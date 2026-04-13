#include "Vector.h"
#include "CosineDistance.h"
#include <cassert>
#include <cmath>
#include <iostream>
#include <stdexcept>

static bool approxEqual(double a, double b, double tol = 1e-5) {
    return std::abs(a - b) < tol;
}

#define RUN_TEST(name, body) \
    void name() { body; std::cout << "[PASS] " #name "\n"; }

// Vector 

RUN_TEST(test_magnitude_3d,
    assert(approxEqual(Vector({1,1,1}).magnitude(), std::sqrt(3.0))))

RUN_TEST(test_magnitude_2d,
    assert(approxEqual(Vector({3,4}).magnitude(), 5.0)))

RUN_TEST(test_dot_product,
    assert(approxEqual(Vector({1,2,3}).dot(Vector({4,5,6})), 32.0)))

void test_dot_dimension_mismatch() {
    try { Vector({1,2}).dot(Vector({1,2,3})); assert(false); }
    catch (const std::invalid_argument&) { std::cout << "[PASS] test_dot_dimension_mismatch\n"; }
}

// cosineDistance

RUN_TEST(test_cos_3d_known,    // (1,1,1) vs (1,1,0) → 0.61548
    assert(approxEqual(cosineDistance(Vector({1,1,1}), Vector({1,1,0})), 0.61548, 1e-4)))

RUN_TEST(test_cos_5d_known,    // (1,1,1,1,1) vs (1,1,1,1,0) → 0.463648
    assert(approxEqual(cosineDistance(Vector({1,1,1,1,1}), Vector({1,1,1,1,0})), 0.463648, 1e-4)))

RUN_TEST(test_cos_identical,
    assert(approxEqual(cosineDistance(Vector({1,2,3}), Vector({1,2,3})), 0.0)))

RUN_TEST(test_cos_parallel,
    assert(approxEqual(cosineDistance(Vector({1,0}), Vector({5,0})), 0.0)))

RUN_TEST(test_cos_orthogonal,
    assert(approxEqual(cosineDistance(Vector({1,0}), Vector({0,1})), M_PI / 2.0)))

RUN_TEST(test_cos_opposite,
    assert(approxEqual(cosineDistance(Vector({1,0}), Vector({-1,0})), M_PI)))

void test_cos_zero_vector() {
    try { cosineDistance(Vector({0,0,0}), Vector({1,2,3})); assert(false); }
    catch (const std::domain_error&) { std::cout << "[PASS] test_cos_zero_vector\n"; }
}

// allPairwiseDistances

void test_pairwise_count() {
    auto pairs = allPairwiseDistances({{{1,0},{0,1},{1,1},{-1,0}}});
    assert(pairs.size() == 12);  // C(4,2)=6 pairs × 2 directions
    std::cout << "[PASS] test_pairwise_count\n";
}

void test_pairwise_sorted() {
    auto pairs = allPairwiseDistances({{{1,0},{0,1},{1,1}}});
    for (std::size_t k = 1; k < pairs.size(); ++k)
        assert(pairs[k-1].distance <= pairs[k].distance + 1e-12);
    std::cout << "[PASS] test_pairwise_sorted\n";
}

// main 

int main() {
    std::cout << "=== Unit Tests: Vector & Cosine Distance ===\n\n";

    test_magnitude_3d(); test_magnitude_2d();
    test_dot_product();  test_dot_dimension_mismatch();

    std::cout << "\n";

    test_cos_3d_known();  test_cos_5d_known();
    test_cos_identical(); test_cos_parallel();
    test_cos_orthogonal(); test_cos_opposite();
    test_cos_zero_vector();

    std::cout << "\n";

    test_pairwise_count(); test_pairwise_sorted();

    std::cout << "\nAll tests passed!\n";
}