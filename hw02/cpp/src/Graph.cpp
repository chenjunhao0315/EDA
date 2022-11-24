#include "Graph.h"
#include <fstream>
#include <vector>
#include <string>

void Graph::buildEdgeSet(map<pair<int, int>, int>& E, const char *filepath) {
    std::ifstream in;
    std::vector<Edge> edges;
    int index = 0;

	in.open(filepath);

	if (in.fail()) return;

	while (!in.eof()) {
		Edge edge;
			
		if (!(in >> edge.v1 >> edge.v2 >> edge.weight)) break;

        if (index_table.find(edge.v1) != index_table.end())
            index_table[edge.v1] = index++;
        if (index_table.find(edge.v2) != index_table.end())
            index_table[edge.v2] = index++;

		edges.push_back(edge);
	}

    for (size_t i = 0; i < edges.size(); ++i) {
        E[make_pair(index_table[edges[i].v1], index_table[edges[i].v2])] = edges[i].weight;
    }
}

int Graph::nodes() {
    return index_table.size();
}
