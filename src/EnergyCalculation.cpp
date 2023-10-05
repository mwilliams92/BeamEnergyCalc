#include "EnergyCalculation.h"
#include <cmath>

double GetEnergy(double A, int Q, double B) {
   
	double Cmag = 0.0004815;
	double Energy = Cmag * pow((B*Q)/A,2); // Example calculation (you can replace with your own)
    return Energy;

}