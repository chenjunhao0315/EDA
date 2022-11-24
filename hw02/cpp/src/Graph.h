#ifndef GRAPH_H
#define GRAPH_H

#include <map>

using namespace std;

class Graph {
public:
    int Nodes();
    void buildEdgeSet(map<pair<int, int>, int>& E);
};

#endif
