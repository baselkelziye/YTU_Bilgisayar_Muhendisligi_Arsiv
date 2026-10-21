#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Apr 14 00:44:31 2020

@author: mertarican
"""
from non_linear_equations import *

def regula_falsi(f, low, high, epsilon):
    """
    Finds anf returns the root of the given function f using regula falsi method.
    Assumes that f(low) * f(high) < 0.

    f: function in terms of 'x'
    low: smaller value of the given search interval
    high: bigger value of the given search interval
    epsilon: biggest possible difference between consecutive guesses

    Returns: the root of the given function f
    """
    #check whether the given interval is valid for regula falsi method
    assert is_valid_interval(f, low, high), "Inappropriate interval."

    #create variable to hold the value of the previous guess at every iteration
    old_guess = float('inf')

    #create variable to hold the difference between consecutive guesses
    diff = float('inf')

    #create variable for iteration count
    iter_count = 0

    while diff > epsilon and is_valid_interval(f, low, high) and iter_count < MAX_ITER:

        #calculate the value of function f at lower and higher interval points
        f_low = get_value(f, low)
        f_high = get_value(f, high)

        #calculate new guess with using regula falsi method
        guess = ((f_low * high) - (low * f_high)) / (f_low - f_high)

        #print iteration information
        print("iteration {0}: guess = {1}".format(iter_count, guess))

        #calculate the valur of the function f at point guess
        fx = get_value(f, guess)

        #if fx value is 0 then return guess
        if fx == 0: return guess

        #update interval values according to regula falsi method
        if f_low * fx < 0: high = guess
        elif f_high * fx < 0: low = guess
        else: raise("Failed to find the root.")

        #calculate difference between guesses
        diff = abs(guess - old_guess)

        #update the value of the old_guess with new guess
        old_guess = guess

        #update the iteration count
        iter_count += 1
    else:
        #checking for the success of the method
        if abs(get_value(f, guess) - 0.0) > error: 
            raise("Failed to find the root.")
    return guess

if __name__ == "__main__":
    low = eval(input("Enter lower interval value: "))
    high = eval(input("Enter higher interval value: "))
    root = regula_falsi(f, low, high, epsilon)
    print("\nThe root of the function is:", root)
