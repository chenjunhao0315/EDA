#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <string>

using namespace std;

class Graph {
public:
    void buildEdgeSet(map<pair<int, int>, int>& E, const char* filepath);
    int nodes(); 
   
public:
    std::map<std::string, int> index_table;
    std::map<int, std::string> convert_table;
};

struct Edge {
	Edge() {}
	Edge(std::string v1, std::string v2, int weight) : weight(weight), v1(v1), v2(v2) {}

	int weight;
	std::string v1;
	std::string v2;
};

#endif
