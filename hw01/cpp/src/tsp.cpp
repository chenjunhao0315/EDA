// Traveling Salesman Problem (TSP)
// Dynamic Programming Method

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

struct Edge {
	Edge() {}
	Edge(std::string name, int weight, std::string v1, std::string v2) : name(name), weight(weight), v1(v1), v2(v2) {}

	std::string name;
	int weight;
	std::string v1;
	std::string v2;
};

class Problem {
public:
	Problem() : ready(-1) {}

	Problem(const char* filepath) {
		ready = readInput(filepath);
	}

	int readInput(const char* filepath);

	int good() { return ready == 0; }

	int fail() { return ready == -1; }
private:
	int ready;

	std::vector<Edge> edges;
};

int main(int argc, const char* argv[]) {
	if (argc < 2) {
		std::cout << "Usage: " << argv[0] << " [input]" << std::endl;
	}

	Problem p(argv[1]);

	if (p.fail()) {
		return -1;
	}

	printf("good: %d\n", p.good());

	return 0;
}

int Problem::readInput(const char* filepath) {
	std::ifstream in;

	in.open(filepath);

	if (in.fail()) {
		return -1;
	}

	while (!in.eof()) {
		std::string buf;

		if (in.peek() == '#') {
			std::getline(in, buf, '\n');
		} else {
			Edge edge;
			
			in >> edge.name >> edge.weight >> edge.v1 >> edge.v2;

			printf("%s: %s <-%d-> %s\n", edge.name.c_str(), edge.v1.c_str(), edge.weight, edge.v2.c_str());

			edges.push_back(edge);
		}
	}

	return 0;
}
