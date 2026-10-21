#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Apr 13 23:38:47 2020

@author: mertarican
"""
from non_linear_equations import *

def bisection_method(f, low, high, epsilon):
    """
    Finds and returns the root of the given function f,
    using bisection method. Assumes f(low) * f(high) < 0
    and epsilon > 0.

    f: function in terms of 'x'
    low: smaller value in the given search interval
    high: bigger value of the given search interval
    epsilon: biggest possible difference between consecutive guesses

    Returns: the root of the given function f
    """
    #check whether the given interval is valid for bisection method
    assert is_valid_interval(f, low, high), "Inappropriate interval."

    #initialize iteration count variable
    iter_count = 0

    #create variable for holding the previous guess value in every iteration
    old_guess = float('inf')

    #initialize difference variable with value of infinity
    diff = float('inf')

    while diff > epsilon and is_valid_interval(f, low, high) and iter_count < MAX_ITER:

        #make new guess by using interval values
        guess = (low + high) / 2.0

        #print iteration information
        print("iteration {0}: guess = {1}".format(iter_count, guess))

        #get the value of the function f at point guess
        fx = get_value(f, guess)

        #determine new interval according to bisection method
        if sign(get_value(f, low)) == sign(fx): low = guess
        else: high = guess

        #calculate difference between guesses
        diff = abs(guess - old_guess)

        #assign new guess value to old_guess variable
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
    root = bisection_method(f, low, high, epsilon)
    print("\nThe root of the function is:", root)
