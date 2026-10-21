#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Apr 13 23:22:12 2020

@author: mertarican
"""
from non_linear_equations import *

def graphical_method(f, guess, epsilon):
    """
    Finds and returns the root of the given function f using graphical method.

    f: function in terms of 'x'
    guess: initial guess
    epsilon: biggest possible difference between consecutive guesses

    Returns: the root of the given function f
    """
    #determine delta x value by dividing the guess to 2.0
    delta_x = guess / 2.0

    #create variable to hold the value of the old guesses at every iteration
    old_guess = float('inf')

    #create variable to hold the difference between consecutive guesses at every iteration
    diff = float('inf')

    #calculate the value of the function f at point guess
    fx = get_value(f, guess)

    #determine the sign of the last value of the function at guess point
    last_sign = sign(fx)

    #create variable to hold iteration count
    iter_count = 0

    while diff > epsilon and iter_count < MAX_ITER:
        #add the value of the delta_x variable to the guess
        guess += delta_x

        #print iteration information
        print("iteration {0}: root = {1}".format(iter_count, guess))

        #calculate the value of the function f at point guess
        fx = get_value(f, guess)

        #calculate the difference between consecutive guesses
        diff = abs(guess - old_guess)

        #update the interval according to graphical method
        if last_sign != sign(fx):
            delta_x = delta_x / 2.0
            guess = old_guess
        else:
            old_guess = guess

        #update the iteration count
        iter_count +=1
    else:
        #checking for the success of the method
        if abs(get_value(f, guess) - 0.0) > error: 
            raise("Failed to find the root.")

    return guess

if __name__ == "__main__":
    x0 = eval(input("Enter your initial guess: "))
    root = graphical_method(f, x0, epsilon)
    print("\nThe root of the function is:", root)
