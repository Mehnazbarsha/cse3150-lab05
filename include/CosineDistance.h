#pragma once
#include "Vector.h"
#include <vector>

struct PairDistance {
    std::size_t i;
    std::size_t j;
    double distance;
};

double cosineDistance(const Vector& x, const Vector& y);
std::vector<PairDistance> allPairwiseDistances(const std::vector<Vector>& vectors);