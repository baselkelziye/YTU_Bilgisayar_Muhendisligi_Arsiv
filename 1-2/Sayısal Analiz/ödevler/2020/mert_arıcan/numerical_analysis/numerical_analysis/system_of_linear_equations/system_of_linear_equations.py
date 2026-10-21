from sympy import *
from math import *
import numpy as np
import itertools
import random

def print_matrix(M):
    """
    Prints matrix to screen.

    M: Matrix variable
    """
    print(np.matrix(M))

def clear_white_space(s):
    """
    Clears all the white space from the given string and returns the modified version.

    s: string that is going to get cleared

    Returns: given string with no white space
    """
    return "".join(s.split())

def find_all(s, ch):
    """
    Finds and returns the indices of all occurences of a given character in
    given string.

    s: string that is going to get searched
    ch: character that is going to be searched

    Returns: array of indices of all occurences
    """
    return [i for i, letter in enumerate(s) if letter == ch]

def add_new_char_next_to_every_occurence(s, new, ch):
    """
    Adds a new character next to all occurences of given character in the given
    string and returns the modified version.

    s: string value
    new: new character value that is going to get inserted
    ch: character that new character is going to get inserted right next to

    Returns: modified string value
    """
    all_occurences = find_all(s, ch)
    count = len(all_occurences)
    if count > 0:
        for occurrence_index in all_occurences:
            index = s[occurrence_index:].find(ch) + occurrence_index
            s = s[:index] + new + s[index:]
    return s

def replace_char(s, old, new):
    """
    Finds and replaces the first occurence of the character 'old' with 'new' one.
    Returns the modified string value.

    s: string going to get searched
    old: old char that is going to get replaced
    new: new char that is going to get inserted

    Returns: modified string value
    """
    index = s.find(old)
    s = s[:index] + new + s[index+1:]
    return s

def extract_equations(equations):
    """
    Extracts and returns coefficients, unknowns and values from given list of equations.

    equations: list of equations as a list of strings (ex: ["3A + 4B - C = 5"])

    Returns: list of tuple of dictionary of unknowns matched with their coefficients and
    result value (ex: [({A: 3, B: 4, C: -1}, 5)]) and set of unknowns (ex: {A, B, C})
    """
    #initialize empty list for holding extracted values.
    extraction_list = list()

    #initialize empty set to hold the unknowns.
    unknowns_set = set()

    for equation in equations:
        #for every equation in equations...

        #create coefficient dictionary
        coef_dict = dict()

        #clear white space from equation
        equation = clear_white_space(equation)

        #add '+' right next to ever '-'
        equation = add_new_char_next_to_every_occurence(equation, '+', '-')

        #replace '=' with '+'
        equation = replace_char(equation, '=', '+')

        #split equation into its elements
        #use '+' as a split point
        equation = list(equation.split('+'))

        #remove if there are any empty elements after split
        equation = list(filter(lambda e: len(e) != 0, equation))

        #assign result of the equation into result variable
        result = equation.pop()

        for element in equation:
            #for every element in equation...

            #find the index of '-' in the equation
            minus_index = element.find('-')

            if minus_index != -1:
                #if element contains '-'
                if element[minus_index+1].isalpha():
                    #if character next to the '-' is not numeric (ex: '-A')
                    coefficient = -1
                    symbol = element[1:]
                else:
                    #if character next to the '-' is numeric (ex: "-12A")
                    a = 0
                    while not element[a].isalpha():
                        a += 1
                    coefficient = float(element[:a])
                    symbol = element[a:]
            else:
                if element[0].isalpha():
                    #if first character is alphabetical (ex: "A")
                    coefficient = 1
                    symbol = element
                else:
                    #if first character is numeric (ex: "31A")
                    a = 0
                    while not element[a].isalpha():
                        a += 1
                    coefficient = float(element[:a])
                    symbol = element[a:]

            #matching symbol with its coefficient
            coef_dict[symbol] = coefficient

            #adding symbol to unknowns set
            unknowns_set.add(symbol)

        #creating tuple for coefficient dictionary and result value (ex: ({A: 3, B: 5, C:-1}, 5))
        equation_tuple = (coef_dict, result)

        #adding equation tuple to extraction list
        extraction_list.append(equation_tuple)

    return extraction_list, unknowns_set

def create_coefficient_matrix(extracted_list, unknowns_set):
    """
    Creates and returns the coefficient and result matrix from extracted_list of
    equations and unknowns_set of equations.

    extracted_list: first value of the output from calling to extract_equations method
    unknowns_set: second value of the output from call to extract_equations method

    Returns: the tuple of coefficient matrix and result matrix respectively
    """
    #create empty matrix for coefficients
    A = Matrix();

    #create empty matrix for results
    C = Matrix();

    #create empty list for storing the results column
    col_list = list()

    for index, eq_tuple in enumerate(extracted_list):
        #for every element in extracted list (ex: ({A: 3, B: 4, C: -1}, 5)) and index of it...

        #create empty list for storing coefficients in the row
        row_list = list()

        for unknown in unknowns_set:
            #for every unknown in given equations...

            if unknown in eq_tuple[0].keys():
                #if element of the extracted list contains key then append its value to coefficients row
                row_list.append(float(eq_tuple[0][unknown]))
            else:
                #if it doesn't contain then append 0 to coefficients row
                row_list.append(0)

        #append result to result columns list
        col_list.append(float(eq_tuple[1]))

        #append coefficients of row to the matrix A respectively to its index
        A = A.row_insert(index, Matrix([row_list]))

    #append results column to matrix C
    C = C.col_insert(0, Matrix(col_list))

    return A, C

def build_calculations_from_extractions(extractions):
    """
    Takes the extractions list as its only input and builds the list of
    (equation, result) pairs.

    extractions: first value of the output from calling to extract_equations method

    Returns: the list of (calculation, result) pairs (ex: [("3A + 4B - C", 5)])
    """
    calculations = list()
    for extraction in extractions:
        calculation = [[str(extraction[0][unknown]), unknown] for unknown in extraction[0]]
        calculation = ["*".join(element) for element in calculation]
        calculation = "+".join(calculation)
        calculations.append((calculation, float(extraction[1])))

    return calculations

def calculations_are_true(calculations, unknowns):
    """
    Takes calculations tuple and unknowns dictionary, determines whether the
    calculations are right with values given in unknowns dictionary.

    calculations: list of tuple of equations and their result (ex: [("3A + 4B - C", 5)])
    unknowns: set of unknowns from equations

    Returns: bool indicating success for calculations
    """
    for equation, result in calculations:
        #for every equation, result pair in calculations

        #make equation string a sympy equation
        equation = sympify(equation)

        #if result is not right with given substitutions then return False else return True
        if not is_close(equation.evalf(subs=unknowns), result):
            return False
    return True

def is_close(a, b):
    """
    Takes two numeric values and determines whether the difference between them
    is smaller than 1e-10 or not.

    a: numeric value
    b: numeric value

    Returns: bool indicating whether the difference is smaller than 1e-10 or not
    """
    return abs(a - b) < 1e-10

def round_if_close(a):
    """
    Takes the numeric value 'a' as an argument and returns its floor or ceiling
    value if it's really close, if not then returns 'a' itself.

    a: numeric value

    Returns: closest integer if there is one, 'a' itself otherwise
    """
    if is_close(floor(a), a): return floor(a)
    elif is_close(ceil(a), a): return ceil(a)
    else: return a

def get_all_permutations(iterable):
    """
    Takes iterable object as an input and returns all the permutations of that.

    iterable: iterable object

    Returns: list of all the permutations of 'iterable'
    """
    return list(itertools.permutations(iterable))

def match_unknowns_with_values(calculations, permutations, unknowns_set):
    """
    Matches the root values with their unknowns in the equations.

    calculations: result of call to build_calculations_from_extractions function
    permutations: all permutations of root values as a list of list (ex: [[1, 2, 3], [2,1,3], ...])
    unknowns_set: set of unknowns in the equations

    Returns: the dictionary that contains the correct unknown-value pairs
    """
    for root_values in permutations:
        roots = dict()
        for index, unknown in enumerate(unknowns_set):
            roots[unknown] = root_values[index]

        if calculations_are_true(calculations, roots):
            return roots

equations = []

while True:
    equation = input("Please enter an equation or press enter to end the process: \n")
    if equation =='': break
    print("YAYY!")
    equations.append(equation)

extraction_list, unknowns_set = extract_equations(equations)
A, R = create_coefficient_matrix(extraction_list, unknowns_set)
n = len(unknowns_set)
calculations = build_calculations_from_extractions(extraction_list)
