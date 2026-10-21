from system_of_linear_equations import *

def create_L(n):
    """
    Creates and returns the L matrix of size n for LU decomposition.

    n: size of the square matrix

    Returns: L matrix of size n
    """
    L = Matrix()

    for row in range(n):
        col_list = []
        for col in range(n):
            if col < row+1:
                symbol = "L{0}".format(str(row)+str(col))
                col_list.append(Symbol(symbol))
            else:
                col_list.append(0)
        L = L.row_insert(row, Matrix([col_list]))

    return L

def create_U(n):
    """
    Creates and retruns the U matrix of size n for LU decomposition.

    n: size of the square matrix

    Returns: U matrix of size n
    """
    U = Matrix()

    for row in range(n):
        col_list = []
        for col in range(n):
            if row < col+1:
                if row != col:
                    symbol = "U{0}".format(str(row)+str(col))
                    col_list.append(Symbol(symbol))
                else:
                    col_list.append(1)
            else:
                col_list.append(0)
        U = U.row_insert(row, Matrix([col_list]))
    return U

def create_vector(n=None, label=None, unknowns=None):
    """
    Creates and returns 1D column matrix with placeholder symbols or given
    with given unknowns if any.

    label: label for unknown symbols
    unknowns: list of string values

    Returns: 1D column matrix symbols as its elements
    """
    V = Matrix()
    if unknowns != None:
        V = V.col_insert(0, Matrix(unknowns))
    else:
        col_list = list()
        for i in range(n):
            symbol = "{0}{1}".format(label, str(i+1))
            col_list.append(symbol)
        V = V.col_insert(0, Matrix(col_list))
    return V

def prepare_for_substitution(M):
    """
    Takes matrix M as its input and prepares it for the substitution process.

    M: Matrix

    Returns: list of lists of lists of every element in the matrix
    (exp: if M = Matrix([L00]) then returns [[['L00']]])
    """
    l = []

    for i in range(len(M)):
        ss = str(M[i])
        ss = clear_white_space(ss)
        ss = add_new_char_next_to_every_occurence(ss, '+', '-')
        e = ss.split("+")
        l.append(e)

    lll = []
    for element in l:
        ll = []
        for expression in element:
            e = expression.split("*")
            ll.append(e)
        lll.append(ll)

    return lll

def substitution(C, A, m, n, unknowns, is_forward=True):
    """
    Performs forward or backward substitution on matrix A according to matrix C.
    Updates the dictionary of unknowns.

    A: Matrix of unknowns
    C: Matrix that function substitues accordingly
    m: row count of A
    n: column count of A
    unknowns: dictionary of unknowns
    is_forward: determines the direction of substitution
    """
    #variables for -1 and 0
    m_o, z = -1, 0

    if not is_forward:
        #if backward substitution then swap -1 with 0 to change direction
        m_o, z = z, m_o

    for row in range(max(m, 1)):
        #if A is a column matrix then m will be 0 but we still need the loop
        #so that why 'max(m, 1)' used in here.
        for col in range(n):
            if not is_forward:
                #if it backwards then change direction
                col = n - col - 1

            #calculate index to use for reaching Matrix elements
            index = n*row + col

            #get element from matrix A
            element = A[index]

            #getting the terminal expression (left or right based on direction)
            terminal_exp = element[m_o]

            #initializing has_multiplier bool
            has_multiplier = False

            if len(terminal_exp) == 1:
                symbol = terminal_exp[z]
                element[m_o] = ['0']
            else:
                symbol = terminal_exp[m_o]
                multiplier = terminal_exp[z]
                element[m_o] = ['0', '0']
                has_multiplier = True

            #getting corresponding C value
            C_value = str(C[index])

            #creating list of product lists for every expression in element
            product_list = ['*'.join(exp) for exp in element]

            #creating equation with adding '+' in between every elements of the product_list
            sum_str = '+'.join(product_list)

            if has_multiplier:
                equation_str = "({0} - ({1})) / {2}".format(C_value, sum_str, multiplier)
            else:
                equation_str = "{0} - ({1})".format(C_value, sum_str)

            equation = sympify(equation_str)

            unknowns[symbol] = equation.evalf(subs=unknowns)

def create_UL(n):
    return create_L(n), create_U(n)

def print_cholesky(M, label):
    print_matrix(M)
    print("                         Matrix {0}".format(label))
    print("\n\n\n")

if __name__ == "__main__":
    variables = dict()
    n = len(unknowns_set)
    is_appropriate = True

    while is_appropriate:
#        print_cholesky(A, 'A')
        roots = []
        #create L and U matrices of size n
        L, U = create_UL(n)
#        print_cholesky(L, 'L')
#        print_cholesky(U, 'U')

        #spend 2 hours just because I didn't notice L*U != U*L
        LU = L * U
#        print_cholesky(LU, "LU")
        LU = prepare_for_substitution(LU)

        #perform forward substitution on matrix L*U according to matrix A
        #this will add the values of the unknowns of both L and U matrices
        #to variables dictionary
        substitution(A, LU, n, n, variables)

        #substitute unknown symbols with their value in dictionary
        L, U = L.subs(variables), U.subs(variables)

#        print_cholesky(L, 'L')
#        print_cholesky(U, 'U')

        X, Y = create_vector(n=n, label="Ğ"), create_vector(n=n, label='Y')

#        print_cholesky(R, 'C')
#        print_cholesky(Y, 'Y')

        LY = L * Y
        if LY[0] == 0:
            #VUHUW! Sometimes first value of the L matrix becomes 0 and that causes
            #Y1 key to never get calculated, this makes chaining impracticle and
            #thats why code change the order of the rows randomly until getting
            #the appropriate order

            random.shuffle(equations)
            extraction_list, unknowns_set = extract_equations(equations)
            A, R = create_coefficient_matrix(extraction_list, unknowns_set)
            continue

        LY = prepare_for_substitution(LY)
#        print_cholesky(L*Y, "L*Y")
        substitution(R, LY, 0, n, variables)

#        print_cholesky(Y.subs(variables), 'Y')

        UX = U * X
#        print_cholesky(UX, "U*X")
        UX = prepare_for_substitution(UX)
        substitution(Y, UX, 0, n, variables, False)

#        print_cholesky(X.subs(variables), 'of Unknowns')

        for key in X:
            roots.append(variables[str(key)])

        all_p = get_all_permutations(roots)
        root_dict = match_unknowns_with_values(calculations, all_p, unknowns_set)

        for unknown in sorted(list((unknowns_set))):
            print(unknown, "=", round_if_close(root_dict[unknown]))
        break
