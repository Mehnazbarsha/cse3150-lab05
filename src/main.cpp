#include "VectorIO.h"
#include "CosineDistance.h"
#include <iostream>
#include <iomanip>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>\n";
        return 1;
    }

    try {
        auto vectors = readVectors(argv[1]);
        std::cout << "Read " << vectors.size() << " vectors of dimension "
                  << vectors[0].size() << ".\n\n"
                  << std::fixed << std::setprecision(6);

        for (const auto& p : allPairwiseDistances(vectors))
            std::cout << p.i << " " << p.j << " cos dist = " << p.distance << "\n";

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
}