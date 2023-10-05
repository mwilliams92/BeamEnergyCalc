ReadMe for BeamEnergyCalc
M. Williams 2023

Quick calculator for getting the beam energy 
based on the DRAGON MD1 field

Dependencies:

ROOT

Instalation:

cmake .
make

Usage:

./CalcEnergy

	or

./CalcEnergy -input inputFile.txt

Where inputFile.txt is a two column text file containing 
target pressures (column 1) and NMR1 field values (column 2).

In either case the program will ask for the beam species 
and then charge state after target.

If the -input option is not used then the program will ask 
for an field value for NMR1

If the -input option is used, the magnetic field will be 
calculated based on an extrapolation to zere pressure.