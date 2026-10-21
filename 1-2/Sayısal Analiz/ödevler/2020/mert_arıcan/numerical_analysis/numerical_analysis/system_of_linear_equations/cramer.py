from system_of_linear_equations import *

def cramer(A, C, unknown_set):
    """
    Solves the system of linear equations using Cramer's method. Assumes number
    of equations is equal to the number of unknowns.

    A: coefficients matrix
    C: result matrix
    unknown_set: set of unknowns
    """
    #if number of unknowns is not equal to the number of equations then fail.
    assert len(unknown_set) == len(equations), "Inappropriate for Cramer's method."

    #calculate the determinant of coefficient matrix A
    det_A = A.det()

    #getting the column count of coefficient matrix A
    col_count = len(A.row(0))

    for i in range(col_count):
        # copy matrix A into C_A
        C_A = A.copy()

        #delete the i'th column from C_A
        C_A.col_del(i)

        #insert result matrix into i'th column
        C_A = C_A.col_insert(i, C.col(0))

        #determinant of the C_A divided by the determinant of A
        root = C_A.det() / det_A

        roots.append(root)

roots = list()

cramer(A, R, unknowns_set)

all_p = get_all_permutations(roots)
root_dict = match_unknowns_with_values(calculations, all_p, unknowns_set)

for unknown in sorted(list((unknowns_set))):
    print(unknown, "=", round_if_close(root_dict[unknown]))