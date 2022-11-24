#include "Graph.h"
#include <fstream>
#include <vector>
#include <string>

void Graph::buildEdgeSet(map<pair<int, int>, int>& E, const char *filepath) {
    std::ifstream in;
    int index = 0;

	in.open(filepath);

	if (in.fail()) return;

	while (!in.eof()) {
		Edge edge;
			
		if (!(in >> edge.v1 >> edge.v2 >> edge.weight)) break;

        if (index_table.find(edge.v1) == index_table.end()) {
            index_table[edge.v1] = index;
            convert_table[index++] = edge.v1;
        }
        if (index_table.find(edge.v2) == index_table.end()) {
            index_table[edge.v2] = index;
            convert_table[index++] = edge.v2;
        }

        E[make_pair(index_table[edge.v1], index_table[edge.v2])] = edge.weight;
	}
}

int Graph::nodes() {
    return index_table.size();
}
