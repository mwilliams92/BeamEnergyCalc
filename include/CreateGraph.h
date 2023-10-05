#ifndef CREATE_GRAPH_H
#define CREATE_GRAPH_H

#include <string>
#include <TGraph.h>
#include <TF1.h>

TGraph* CreateGraph(const std::string& fileName);

double GetIntercept(TGraph* graph);

#endif // CREATE_GRAPH_H