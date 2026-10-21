from non_linear_equations import *

def basic_iteration(h, x0, epsilon):
    """
    Finds and returns the root of the given function
    using basic iteration method. Assumes h is a predetermined
    special function to find the root of the original function.

    h: a function in terms of 'x'
    x0: initial guess for the root value
    epsilon: biggest possible difference between consecutive guesses

    Returns: the root of the given function f
    """
    #create f(x) = x function
    g = sympify('x')

    #get values of the function g and h at the initial guess point
    gx = get_value(g, x0)
    hx = get_value(h, x0)

    #control whether the function converges or not
    hdx = h.diff('x')
    hxdx = get_value(hdx, x0)
    assert abs(hxdx) < 1, "Failed to find the root, function diverges."

    #calculate difference between guesses
    diff = abs(hx - gx)

    #initialize variable to store the iteration count
    iter_count = 0

    while diff > epsilon and iter_count < MAX_ITER:

        #print iteration information
        print("iteration {0}: gx =".format(iter_count), gx, "hx =", hx)

        #switch gx guess with hx guess
        gx = hx

        #get new value for hx by calculating h function at gx point
        hx = get_value(h, gx)

        #get difference between guesses
        diff = abs(hx - gx)

        #update iteration count
        iter_count += 1
    else:
        #checking for the success of the method
        if diff > epsilon: raise("Failed to find the root.")

    return hx

if __name__ == "__main__":
    x0 = eval(input("Enter your initial guess: "))
    root = basic_iteration(f, x0, epsilon)
    print("\nThe root of the function is:", root)
