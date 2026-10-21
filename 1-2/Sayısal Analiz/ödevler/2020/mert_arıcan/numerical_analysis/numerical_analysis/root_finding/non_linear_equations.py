from sympy import *
import math

MAX_ITER = 1000

epsilon = 1e-15

error = 1e-5

def sign(x):
    """
    Returns sign of the numerical value as a string.

    x: numerical value

    Returns: sign of the given numerical value 'x'
    """
    if x > 0: return "+"
    elif x < 0: return "-"
    return "zero"

def get_value(f, x0):
    """
    Substitues 'x' in the function f, with the given value x0.

    f: function in terms of 'x'
    x: point that function is going to be evaluated at

    Returns: value of the given function at the given point
    """
    return f.evalf(subs={"x": x0})

def is_valid_interval(f, x1, x2):
    """
    Returns whether the x1 and x2 values is appropriate to use within
    bisection, regula falsi and secant methods.

    f: function in terms of 'x'
    x1: first x value
    x2: second x value

    Returns: bool indicating whether the points are valid or not
    """
    fx1 = get_value(f, x1)
    fx2 = get_value(f, x2)
    return sign(fx1) != sign(fx2) and fx1 != 0 and fx2 != 0


class Function_Supplier(object):
    """Class that handles the process of taking function as an input from the user."""
    
    def __init__(self):
        self.func_string = input("Enter a function in terms of 'x': ")
        self.func = sympify(self.func_string)

    def get_func(self):
        return self.func


function_supplier = Function_Supplier()
f = function_supplier.get_func()
