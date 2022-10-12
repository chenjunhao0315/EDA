import numpy as np

class Parser():
    def __init__(self, filepath, dtype=float):
        self.filepath = filepath;
        self.edges = []
        self.vertices = {}
        self.dtype = dtype
        self.inf = np.inf if dtype is float else 1e6

    def add_vertice(self, v):
        if v not in self.vertices:
            self.vertices[v] = len(self.vertices)

    def add_edge(self, edge_info):
        _, _, v1, v2 = edge_info
        self.edges.append(edge_info)
        self.add_vertice(v1)
        self.add_vertice(v2)

    def parse(self):
        f = open(self.filepath)
        for line in f.readlines():
            if line[0] == '#' or line[0] == '\n':
                continue
            edge_info = tuple(line.rstrip().split(' '))
            self.add_edge(edge_info) 

        f.close()

    def generate_matrix(self):
        self.parse()
        dim = len(self.vertices)
        matrix = np.full((dim, dim), self.inf, dtype=self.dtype)
        for _, weight, v1, v2 in self.edges:
            v1 = self.vertices[v1]
            v2 = self.vertices[v2]
            matrix[v1, v2] = weight
            matrix[v2, v1] = weight

        return matrix

    def generate_convert_table(self):
        table = [None] * len(self.vertices)
        for key, value in self.vertices.items():
            table[value] = key

        return table

