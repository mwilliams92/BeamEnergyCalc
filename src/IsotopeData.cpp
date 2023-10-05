#include "Isotope.h"
#include <iostream>
#include <fstream>
#include <algorithm>

std::vector<Isotope> readIsotopeData(const std::string& filePath) {

    std::ifstream file(filePath);
    std::vector<Isotope> isotopes;
    std::string line;

    while (std::getline(file, line)) {
        Isotope isotope;
        while (line != "") {
            size_t pos = line.find(" = ");
            std::string key = line.substr(0, pos);
            line.erase(0, pos + 3);
            pos = line.find("\n");
            std::string value = line.substr(0, pos);
            line.erase(0, pos + 1);

            if (key == "Atomic Symbol") {
                isotope.symbol = value;
                std::transform(isotope.symbol.begin(), isotope.symbol.end(), isotope.symbol.begin(), ::tolower);
            }
            else if (key == "Mass Number")
                isotope.massNumber = std::stoi(value);
            else if (key == "Relative Atomic Mass")
                isotope.relativeAtomicMass = std::stod(value);
        }
        isotopes.push_back(isotope);
    }

    return isotopes;
}

double getRelativeAtomicMass(const std::vector<Isotope>& isotopes, const std::string& symbol, int massNumber) {
    
	std::string lowerSymbol = symbol;
    std::transform(lowerSymbol.begin(), lowerSymbol.end(), lowerSymbol.begin(), ::tolower);

    for (const auto& isotope : isotopes) {
        if (isotope.symbol == lowerSymbol && isotope.massNumber == massNumber) {
            return isotope.relativeAtomicMass;
        }
    }
    return -1;

}