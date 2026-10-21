#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Apr 14 00:59:18 2020

@author: mertarican
"""
from non_linear_equations import *

def newton_raphson(f, x0, epsilon):
    """
    Finds and returns the root of the given function f with Newton-Raphson
    method.

    f: function in terms of 'x'
    x0: initial guess for the root value
    epsilon: biggest possible difference between consecutive guesses

    Returns: the root of the given function f
    """
    #create old_guess variable with the value of initial guess x0
    old_guess = x0

    #create guess variable with the same value as the old_guess variable
    guess = old_guess

    #create variable to store the difference between consecutive guesses
    diff = float('inf')

    #determine the derivative of f according to x
    fxdx = f.diff('x')

    #create a variable to store iteration count
    iter_count = 0

    while diff > epsilon and iter_count < MAX_ITER:

        #get value of the function f at point guess
        fx = get_value(f, guess)

        #get value of the derivative of the function f at point guess
        dx = get_value(fxdx, guess)

        if dx == 0: raise("Divide by zero error.")
        
        #calculate new guess by using Newton's method
        guess = old_guess - (fx / dx)

        #print iteration information
        print("iteration {0}: guess = {1}".format(iter_count, guess))

        #calculate difference between guesses
        diff = abs(guess - old_guess)

        #update the value of the old_guess variable
        old_guess = guess

        #update the iteration count
        iter_count += 1
    else:
        #checking for the success of the method
        if abs(get_value(f, guess) - 0.0) > error: 
            raise("Failed to find the root.")
            
    return guess

if __name__ == "__main__":
    x0 = eval(input("Enter yout initial guess: "))
    root = newton_raphson(f, x0, epsilon)
    print("\nThe root of the function is:", root)
