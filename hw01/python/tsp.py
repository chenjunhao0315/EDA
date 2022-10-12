from parser import Parser

def main():
    p = Parser('g1.dat')
    matrix = p.generate_matrix()
    table = p.generate_convert_table()

    print(matrix)
    print(table)

if __name__ == '__main__':
    main()
