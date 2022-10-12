from parser import Parser

def main():
    p = Parser('g1.dat')
    matrix = p.generate_matrix()

    print(matrix)

if __name__ == '__main__':
    main()
