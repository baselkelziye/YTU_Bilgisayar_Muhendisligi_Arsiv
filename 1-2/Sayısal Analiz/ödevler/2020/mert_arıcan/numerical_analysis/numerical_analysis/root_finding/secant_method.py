#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Apr 14 01:10:50 2020

@author: mertarican
"""
from non_linear_equations import *

def secant_method(f, low, high, epsilon):
    """
    Finds and returns the root of the given function f using secant method.
    Assumes that f(low) * f(high) < 0.

    f: function in terms of 'x'
    low: smaller value of the given search interval
    high: bigger value of the given search interval
    epsilon: biggest possible difference between consecutive guesses

    Returns: the root of the given function f
    """
    #check whether the given interval is valid for secant method
    assert is_valid_interval(f, low, high), "Inappropriate interval."

    #initialize other_guess variable with the lower interval value
    other_guess = low

    #initialize guess variable with the higher interval value
    guess = high

    #create variable to hold the previous guess at every iteration
    old_guess = float('inf')

    #initializing fx values with appropriate (different signed) values
    fx = 1; other_fx = -1

    #creating a variable to hold the value of the difference between consecutive guesses
    diff = float('inf')

    #create variable for iteration count
    iter_count = 0

    while diff > epsilon and is_valid_interval(f, other_guess, guess) and iter_count < MAX_ITER:

        #getting values for fx values at guess points
       other_fx = get_value(f, other_guess)
       fx = get_value(f, guess)

       #if new interval is not valid for the method then raise failure
       if not is_valid_interval(f, other_guess, guess):
           raise("Failed to find the root.")

        #calculate new guess according to secant method
       new_guess = other_guess - (other_fx * ((guess - other_guess) / (fx - other_fx)))
       #get the value of the function at the new guess point
       new_fx = get_value(f, new_guess)

       #update guesses according to secant method
       if sign(new_fx) == sign(other_fx):
           other_guess = new_guess
           other_fx = new_fx
       else:
           guess = new_guess
           fx = new_fx

        #print iteration information
       print("Iteration {0}: guess = {1}".format(iter_count, new_guess))

       #calculate the difference between guesses
       diff = abs(new_guess - old_guess)

       #update the value of the old_guess
       old_guess = new_guess

       #update the iteration count
       iter_count += 1

    else:
        #checking for the success of the method
        if abs(get_value(f, new_guess) - 0.0) > error: 
            raise("Failed to find the root.")
            
    return new_guess

if __name__ == "__main__":
    low = eval(input("Enter lower interval value: "))
    high = eval(input("Enter higher interval value: "))
    root = secant_method(f, low, high, epsilon)
    print("\nThe root of the function is:", root)
