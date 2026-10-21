from system_of_linear_equations import *

#dictionary to hold the guesses of the roots of previous iteration
previous_guesses = dict()

#dictionary to hold the guesses of the roots of current iteration
current_guesses = dict()

#dictionary to hold the equations for unknowns (ex: {X: "(3-2*Y+Z)/4"})
equation_dict = dict()

#dictionary to hold whether the differences of the differences between previous
#and current guesses of the roots are bigger than epsilon or not
diffs = dict()

epsilon = 0.000000000000001
epsilon = 1e-15

MAX_ITER = 1000

def print_iteration(n, unknowns):
    print("Iteration {0}: ".format(n))
    for unknown in unknowns:
        print(unknown, unknowns[unknown])
    print("\n\n\n")

def get_coef_list(M):
    """
    Creates and returns the coefficient matrix as a list of lists.

    M: Matrix of type sympy matrix

    Returns: coefficient matrix as a list of lists.
    """
    coef_list = [list(M.row(i)) for i in range(len(M.col(0)))]
    return coef_list

def get_diagonally_dominant_order_of_rows(all_permutations, coef_list):
    """
    Finds and returns the order of the rows of the matrix to make matrix
    diagonally dominant.

    all_permutations: all permutations of orders of the rows
    coef_list: coefficient list of matrix

    Returns: the tuple that contains indexes of rows in order to make
    matrix diagonally dominant
    (ex: (0, 2, 1). This tuple says that use the first element of row 0, second
    element of row 1 and third element of row 2 to make the matrix diagonally
    dominant.
    """
    maks = 0; dominant_order = None
    for permutation in all_permutations:
        product = 1

        for index, order in enumerate(permutation):
            "First choose row based on order and then choose index."
            product *= coef_list[order][index]

        if abs(product) > maks:
            maks = abs(product)
            dominant_order = permutation

    return dominant_order

def prepare_for_iteration(M, extraction_list, unknowns_set, initial_guesses):
    all_permutations = get_all_permutations(list(range(len(M.col(0)))))
    coef_list = get_coef_list(M)
    dominant_order = get_diagonally_dominant_order_of_rows(all_permutations, coef_list)

    for index, order in enumerate(dominant_order):
        unknowns_of_row = extraction_list[order][0]
        unknown = list(unknowns_set)[index]
        coef_of_unknown = unknowns_of_row[unknown]
        result_at_row = extraction_list[order][1]

        body = [[str(unknowns_of_row[unk]), unk] for unk in unknowns_of_row if unk != unknown]
        body = '+'.join(['*'.join(p) for p in body])

        if body == '':
            equation_str = "({0}) / {1}".format(result_at_row, coef_of_unknown)
        else:
            equation_str = "({0} - ({1})) / {2}".format(result_at_row, body, coef_of_unknown)
        
        equation = sympify(equation_str)

        equation_dict[unknown] = equation
        previous_guesses[unknown] = initial_guesses[unknown]

initial_guesses = dict()

for key in sorted(list(unknowns_set)):
    initial_guesses[key] = float(input("Enter the initial guess for {0}: ".format(key)))

prepare_for_iteration(A, extraction_list, unknowns_set, initial_guesses)
