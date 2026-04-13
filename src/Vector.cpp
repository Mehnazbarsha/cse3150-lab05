#include "Vector.h"
#include <cmath>
#include <numeric>
#include <sstream>
#include <stdexcept>

Vector::Vector(const std::vector<double>& components) : data_(components) {
    if (data_.empty())
        throw std::invalid_argument("Vector must have at least one component.");
    magnitude_ = std::sqrt(std::inner_product(data_.begin(), data_.end(), data_.begin(), 0.0));
}

std::size_t Vector::size() const { return data_.size(); }

double Vector::operator[](std::size_t i) const { return data_.at(i); }

double Vector::magnitude() const { return magnitude_; }

double Vector::dot(const Vector& other) const {
    if (size() != other.size())
        throw std::invalid_argument("Vectors must have the same dimension for dot product.");
    return std::inner_product(data_.begin(), data_.end(), other.data_.begin(), 0.0);
}

std::string Vector::toString() const {
    std::ostringstream oss;
    oss << "(";
    for (std::size_t i = 0; i < data_.size(); ++i) {
        if (i > 0) oss << ", ";
        oss << data_[i];
    }
    oss << ")";
    return oss.str();
}