from numerical_integration import *

def contains_str(l):
    """
    Takes iterable type as input and returns whether it has an element of type str.

    l: iterable type

    Returns: True if it contains a str element False otherwise
    """
    if len(list(filter(lambda x: type(x) == str, l))) > 0: return True
    return False

def multiple_integral(f, bounds, order, n):
    """"
    Recursive implementation of the multiple integral. This function can be used
    to take double or triple integrals.

    f: function to integrate over
    bounds: bounds of integrals respectively to their order
    order: the order which this algorithm is going to take integrals of the
    function (ex: ['x', 'y'] means take integral according to 'x' first, then 'y')
    n: n of the Simpson's rule. n must be an even number.

    Returns: the integral value with given bounds and integration order
    """
    #This function needs order to be reversed when it's passed for an triple
    #integration to get calculated correctly.
    if len(order) == 3: order = list(reversed(order))

    #Base case
    if len(order) == 1:
        #if length of the integration order is one, (exp:['x']), then return the
        #value using Simpson's rule.
        bounds = bounds[0]
        return simpsons_rule(f, bounds[0], bounds[1], n, order[0], toDisplay=False)

    #Recursive step
    else:
        #determine the inner and outer bounds tuple of the double integration
        inner_bounds = bounds[-1]; outer_bounds = bounds[-2]

        if len(order) == 3 and len(list(filter(lambda x: contains_str(x), bounds))) > 0:
            raise("Triple integration only works with numerical boundary values!")

        if contains_str(outer_bounds): raise("Outer bounds must be numeric values!")

        #if both of the bounds are numeric then switch them. This is needed by
        #a function evaluation process in loop below
        if not contains_str(inner_bounds) and  not contains_str(outer_bounds):
            inner_bounds, outer_bounds = outer_bounds, inner_bounds

        #determine the values of inner and outer bounds
        in_low, in_high = sympify(inner_bounds[1]), sympify(inner_bounds[0])
        out_low, out_high = sympify(outer_bounds[1]), sympify(outer_bounds[0])

        #calculate the h value
        h = ((out_high - out_low) / sympify(n)).evalf()

        #determine which unknown we are integrate according to
        sub = order.pop()

        #initialize the integral variable with value 0
        integral = 0

        #Summing process of the Simpson's rule with recursive calls
        for pair in [(1, n, 4), (0, n+1, 2)]:
            for i in range(pair[0], pair[1], 2):

                #calculate evaluation point
                p = out_low + sympify(i)*h

                #calculate lower and higher bounds
                ll = evaluate(in_low, sub, p)
                hh = evaluate(in_high, sub, p)

                #replace the integration unknown with the p value
                ff = f.subs({sub:p})

                #update the bounds
                bbb = bounds[:-2] + [(hh, ll)]

                #calculate the integral value of the segments
                value = pair[2] * multiple_integral(ff, bbb, order.copy(), n)

                #if p was the first or the nth point then take back the multiplication
                #process (according to Simpson's rule)
                if (pair[-1] == 2 and i == 0) or (pair[-1] == 2 and i == n):
                    value = value / pair[2]

                #add new value of the segment to integral
                integral += value

    return integral*h/3


f = sympify("x**2+y")
bounds = [(3,2), ('2*x**3', "x")]
order = ['y', 'x']
n = 4
aa = multiple_integral(f, bounds, order, n)

#f = sympify("(x**2) * y * (cos(pi*z)+2)")
#bounds = [(5,0), (2,0), (3,0)]
#order = ['x', 'y', 'z']
#n = 4
#aa = multiple_integral(f, bounds, order, n)

#f = sympify("1/((1+x**2+y**2)**0.5)")
#bounds = [(2**0.5, 0), ("(4-y**2)**0.5", "y")]
#order = ['x', 'y']
#n = 4
#aa = multiple_integral(f, bounds, order, n)

#f = sympify("9*(x**3)*(y**2)")
#bounds = [(3,1), (4,2)]
#order = ['x', 'y']
#n = 4
#aa = multiple_integral(f, bounds, order, n)

#f = sympify("2*x+4*y")
#bounds = [(2,0), (1,0)]
#order = ['y', 'x']
#n = 4
#aa = multiple_integral(f, bounds, order, n)

#f = sympify("x/(y**5+1)")
#bounds = [(2,0), ("y**2",0)]
#order = ['x', 'y']
#n = 4
#aa = multiple_integral(f, bounds, order, n)

#f = sympify("x**2 + y**3 + cos(z)")
#bounds = [(8,1),(7,5),(4,0)]
#order = ['x', 'y', 'z']
#n = 4
#aa = multiple_integral(f, bounds, order, n)

#f = sympify("sin(x) + cos(y) + tan(z)")
#bounds = [(4,2), (2,1), (1,0)]
#order = ['x', 'y', 'z']
#n = 4
##n = 8
##n = 16
##n = 32
#aa = multiple_integral(f, bounds, order, n)

#########Symbolab cannot solve error#################3
#f = sympify("sin(x) / (1 - (2*tan(y))**(z*pi*sin(2)))")
#bounds = [(9,3), (1,0), (1,-2)]
#order = ['x', 'y', 'z']
##n = 4
#n = 8
##n = 16
##n = 32
#aa = multiple_integral(f, bounds, order, n)

print(aa)
