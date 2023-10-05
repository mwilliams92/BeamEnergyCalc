#ifndef ISOTOPE_DATA_H
#define ISOTOPE_DATA_H

#include <vector>
#include <string>
#include "Isotope.h"

std::vector<Isotope> readIsotopeData(const std::string& filePath);
double getRelativeAtomicMass(const std::vector<Isotope>& isotopes, const std::string& symbol, int massNumber);

#endif // ISOTOPE_DATA_H