#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Apr 12 20:39:27 2020

@author: mertarican
"""
from sympy import *
import math

def evaluate(f, symbol, value):
    """
    Evaluates the given function f with substituting the symbol with value.

    f: function
    symbol: label of the unknown
    value: substitution value

    Returns: the value of the function f after substitution
    """
    return f.evalf(subs={symbol:value})

def trapezoidal_rule(f, high, low, n):
    """
    Finds and prints the integral value of the given function f with given
    interval values low and high using Trapezoidal rule.

    f: function to integrate over
    low: lower interval value
    high: higher interval value
    n: n of the Trapezoidal rule
    """
    #compute h value
    h = (high - low) / n

    #initialize integral value with half of the sum of the function values at the
    #lowest and the highest interval points (according to Trapezoidal rule)
    integral = (evaluate(f, 'x', low) + evaluate(f, 'x', high)) / 2.0

    #summing part of the Trapezoidal rule
    for i in range(1, n):
        integral += evaluate(f, 'x', low + i*h)

    #final calculation
    integral = h * integral

    print("Integral value using Trapezoidial rule: ", integral)


def simpsons_rule(f, high, low, n, label='x', toDisplay=True):
    """
    Finds and returns the integral of the given function f with given interval
    values low and high using Simpson's rule.

    f: function to integrate over
    low: lower interval value
    high: higher interval value
    n: n of the Simpson's rule
    label: symbol of the unknown, it's default to 'x'
    toDisplay: determines whether return value needed or not

    Returns: the value of the integral if toDisplay is False
    """
    #n must be an even number to use Simpson's rule
    assert n%2 == 0, "n must be an even number."

    #compute h value
    h = (high - low) / n

    #initialize integral value with function values at 'low' and 'high' points
    integral = evaluate(f, label, low) + evaluate(f, label, high)

    #summing part of the Simpson's rule
    for pair in [(1, n, 4), (2, n-1, 2)]:
        for i in range(pair[0], pair[1], 2):
            integral += pair[2] * evaluate(f, label, low + i*h)

    #final calculation
    integral *= h/3

    #print information or return value
    if toDisplay:
        print("Integral value using Simpson's rule: ", integral)
    else: return integral

if __name__ == "__main__":
    #Take input from the user and convert it to sympy function type
    f = sympify(input("Enter a function to integrate in terms of x: "))

    #Take lower and higher interval value from the user
    low = eval(input("Enter lower bound: "))
    high = eval(input("Enter higher bound: "))

    #Take n from the user
    n = int(input("Enter n: "))

    print()
    simpsons_rule(f, high, low, n)
    print()
    trapezoidal_rule(f, high, low, n)
