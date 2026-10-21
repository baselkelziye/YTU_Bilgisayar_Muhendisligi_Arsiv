from prettytable import PrettyTable  # Create pretty Table :)

p = float(input("Enter the coefficient of x^0 = "))
r = float(input("Enter the coefficient of x^1 = "))
s = float(input("Enter the coefficient of x^2 = "))
t = float(input("Enter the coefficient of x^3 = "))
u = float(input("Enter the coefficient of x^4 = "))

a = float(input("Enter the Lower limit of range = "))
b = float(input("Enter the Upper limit of range = "))
eps = float(input("Enter the Epsilon value = "))
c = (a + b) / 2


def fnk(x):
    return (u * x ** 4) + (t * x ** 3) + (s * x ** 2) + (r * x) + p


table = PrettyTable()
table.field_names = ['a', 'f(a)', 'b', 'f(b)', 'c=(a+b)/2', 'f(c)', '|a-b|']

while (abs(a - b) > eps) and (abs(fnk(c)) > eps):       # Do above while (|a-b| > epsilon) and |f(c)| > eps mutlakD. önemli
    c = (a + b) / 2                                     # if one of them is < eps stop
    table.add_row([a, fnk(a), b, fnk(b), c, fnk(c), abs(a - b)])  # abs(-a) = |-a| = a   //Absolute value
    if fnk(a) * fnk(c) > 0:                             # if fnk(a) and fnk(c)'s sings is equal, do a = c
        a = c
    else:                                               # else fnk(b) and fnk(c)'s sings is equal. So b = c
        b = c

print(table)
print("Denklemin Kökü = ", c)
