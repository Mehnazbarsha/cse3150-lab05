#include "VectorIO.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

std::vector<Vector> readVectors(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Cannot open file: " + filename);

    std::vector<Vector> vectors;
    std::size_t expectedDim = 0;
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<double> components;
        double val;
        while (iss >> val)
            components.push_back(val);

        if (components.empty()) continue;

        if (expectedDim == 0) {
            if ((expectedDim = components.size()) < 2)
                throw std::runtime_error("Vectors must have dimension >= 2.");
        } else if (components.size() != expectedDim) {
            throw std::runtime_error("Dimension mismatch: expected " +
                std::to_string(expectedDim) + " but got " + std::to_string(components.size()));
        }

        vectors.emplace_back(components);
    }

    if (vectors.empty())
        throw std::runtime_error("No vectors found in file: " + filename);

    return vectors;
}