#include "CosineDistance.h"
#include <cmath>
#include <algorithm>
#include <stdexcept>

double cosineDistance(const Vector& x, const Vector& y) {
    double denom = x.magnitude() * y.magnitude();
    if (denom == 0.0)
        throw std::domain_error("cosineDistance: zero-magnitude vector has no direction.");
    return std::acos(std::clamp(x.dot(y) / denom, -1.0, 1.0));
}

std::vector<PairDistance> allPairwiseDistances(const std::vector<Vector>& vectors) {
    std::size_t n = vectors.size();
    std::vector<PairDistance> results;
    results.reserve(n * (n - 1));

    for (std::size_t i = 0; i < n; ++i)
        for (std::size_t j = i + 1; j < n; ++j) {
            double dist = cosineDistance(vectors[i], vectors[j]);
            results.push_back({i, j, dist});
            results.push_back({j, i, dist});
        }

    std::sort(results.begin(), results.end(),
              [](const PairDistance& a, const PairDistance& b) {
                  if (a.distance != b.distance) return a.distance < b.distance;
                  if (a.i != b.i) return a.i < b.i;
                  return a.j < b.j;
              });

    return results;
}