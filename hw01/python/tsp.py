from parser import Parser
import copy

class TSP:
    def __init__(self, filepath, ):
        self.filepath = filepath
        self.g  = {}
        self.pl = []
        self.Parser = Parser(filepath)
    
    def generate_matrix(self, Parser):
        self.matrix = Parser.generate_matrix()
        self.table = Parser.generate_convert_table()
        self.n = len(self.matrix)
        #print(self.matrix)
        #print(self.table)
        #print(self.n)

    def solve(self):
        self.generate_matrix(self.Parser)
        
        for x in range(1, self.n):
            self.g[x + 1, ()] = self.matrix[x][0]

        self.get_minimum(1, (2,3,4,5,6))

        print('\n\nSolution to TSP: {' ,self.table[0], ',' , end='')
        solution = self.pl.pop()
        print(self.table[solution[1][0]-1], end=', ')
        for x in range(self.n - 2):
            for new_solution in self.pl:
                if tuple(solution[1]) == new_solution[0]:
                    solution = new_solution
                    print(self.table[solution[1][0]-1], end=', ')
                    break
        print(self.table[0],'}')
        return

    def get_minimum(self, k, a):
        #if already caculated
        if (k, a) in self.g:
            return self.g[k, a]

        values  = []
        all_min = []

        for j in a:
            set_a = copy.deepcopy(list(a))
            set_a.remove(j)
            all_min.append([j, tuple(set_a)])
            result = self.get_minimum(j, tuple(set_a))
            values.append(self.matrix[k-1][j-1] + result)

        #save minimum value
        self.g[k, a] = min(values)
        self.pl.append(((k, a), all_min[values.index(self.g[k, a])]))

        return self.g[k, a]


if __name__ == '__main__':
    Input_file = 'g1.dat'
    tour = TSP(Input_file)
    tour.solve()

'''
reference:
https://github.com/phvargas/TSP-python
'''
