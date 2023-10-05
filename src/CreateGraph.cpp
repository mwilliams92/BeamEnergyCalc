#include <string>
#include <vector>
#include <fstream>

#include <TGraph.h>
#include <TF1.h>

#include "CreateGraph.h"

TGraph* CreateGraph(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file " << fileName << std::endl;
        return nullptr;
    }

    std::vector<double> xData, yData;
    double x, y;

    while (inputFile >> x >> y) {
        xData.push_back(x);
        yData.push_back(y);
    }

    TGraph* graph = new TGraph(xData.size(), &xData[0], &yData[0]);

    inputFile.close();

    return graph;
}

double GetIntercept(TGraph* graph) {
    TF1* fitFunc = new TF1("fitFunc", "pol1",0,10); // Fit to a first-order polynomial
    graph->Fit(fitFunc,"QR"); // "Q" means quiet mode (no printing)
    double yIntercept = fitFunc->GetParameter(0); // Get y-intercept
	fitFunc->Write();
    delete fitFunc;
    return yIntercept;
}