#include <iostream>
#include <TFile.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TF1.h>
#include <string>

#include "IsotopeData.h"
#include "EnergyCalculation.h"
#include "CreateGraph.h"

using namespace std;

int main(int argc, char* argv[]) {
    double fA, fQ, fB, fEnergy;

	std::string filePath = "./include/NIST_Data.txt"; // Replace with your file path
    std::vector<Isotope> isotopeData = readIsotopeData(filePath);

    if (argc == 3 && string(argv[1]) == "-input") {
        
		string fileName = argv[2];
        std::string userInput;
        std::cout << "Enter beam species (e.g., Na21): ";
        std::cin >> userInput;

		try {
        	std::string symbol = userInput.substr(0, userInput.size() - 2);
        	int massNumber = std::stoi(userInput.substr(userInput.size() - 2));

        	fA = getRelativeAtomicMass(isotopeData, symbol, massNumber);

        	if (fA == -1) {
            	std::cout << "No information found for " << symbol << massNumber << "." << std::endl;
        	}
    	} catch (const std::exception& e) {
        	std::cerr << "Invalid input format. Please use the format 'ElementSymbolMassNumber', e.g., 'Na21'." << std::endl;
    	}

		cout << "Enter Charge State: ";
        cin >> fQ;

		TFile *outfile = new TFile("output.root","RECREATE");
		TCanvas *c1 = new TCanvas();
		TGraph* graph = CreateGraph(fileName);

    	if (graph != nullptr) {
        	graph->Draw("AP");
			graph->SetMarkerStyle(20);
			graph->Write();

			fB = GetIntercept(graph);
			fEnergy = GetEnergy(fA,fQ,fB);

        	cout << "Energy = " << fEnergy << " keV/u" << endl;

    	} else {

			cout << "TGraph not generated" << endl;
		}
		c1->Write();
		outfile->Close();

		delete c1;
		delete graph;
		delete outfile;

    } else if (argc == 1) {

		std::string userInput;
        std::cout << "Enter beam species (e.g., Na21): ";
        std::cin >> userInput;

		try {
        	std::string symbol = userInput.substr(0, userInput.size() - 2);
        	int massNumber = std::stoi(userInput.substr(userInput.size() - 2));

        	fA = getRelativeAtomicMass(isotopeData, symbol, massNumber);

        	if (fA == -1) {
            	std::cout << "No information found for " << symbol << massNumber << "." << std::endl;
        	} 
    	} catch (const std::exception& e) {
        	std::cerr << "Invalid input format. Please use the format 'ElementSymbolMassNumber', e.g., 'Na21'." << std::endl;
    	}

		cout << "Enter Charge State: ";
        cin >> fQ;
		cout << "Enter NMR1 Field: ";
        cin >> fB;

        // Perform calculations using num1, num2, and num3
        fEnergy = GetEnergy(fA,fQ,fB);
        cout << "Energy = " << fEnergy << " keV/u" << endl;

    } else {
        cout << "Invalid arguments. Usage:" << endl;
        cout << "1. To get energy from file: " << argv[0] << " -input" << endl;
        cout << "2. To get energy from NMR1: " << argv[0] << endl;
        return 1;
    }

    return 0;
}