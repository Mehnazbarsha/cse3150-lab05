#pragma once
#include <vector>
#include <string>

class Vector {
public:
    explicit Vector(const std::vector<double>& components);
    std::size_t size() const;
    double operator[](std::size_t i) const;
    double dot(const Vector& other) const;
    double magnitude() const;
    std::string toString() const;

private:
    std::vector<double> data_;
    double magnitude_;
};