from prettytable import PrettyTable  # Create pretty Table :)

p = float(input("Enter the coefficient of x^0 = "))
r = float(input("Enter the coefficient of x^1 = "))
s = float(input("Enter the coefficient of x^2 = "))
t = float(input("Enter the coefficient of x^3 = "))
u = float(input("Enter the coefficient of x^4 = "))

a = float(input("Enter the Lower limit of range = "))
b = float(input("Enter the Upper limit of range = "))
eps = float(input("Enter the Epsilon value = "))

def f(x):
    return (u * x ** 4) + (t * x ** 3) + (s * x ** 2) + (r * x) + p

ceski = 0
c = (a*f(b) - b*f(a)) / (f(b)-f(a))         #c = (a*f(b) - b*f(a)) / (f(b)-f(a))
fark = c - ceski

table = PrettyTable()
table.field_names = ['a', 'f(a)', 'b', 'f(b)', 'c', '|f(c)|', '|Ck - C(k+1)|']

i =0
while (abs(fark) > eps) and (abs(f(c)) > eps) and i < 100:      # Do above while (|Ck - C(k+1)| > epsilon) and |f(c)| > eps   # mutlakD. önemli if one of them is < eps stop
    c = (a*f(b) - b*f(a)) / (f(b)-f(a))
    fark = c - ceski
    ceski = c
    table.add_row([a, f(a), b, f(b), c, f(c), fark])  # abs(-a) = |-a| = a   //Absolute value
    if abs(f(a)) < abs(f(b)):             # if abs(f(a)) < abs(f(b)), f(a) nearer to 0 from f(b), so do a = c
        a = c                             # hangisi sıfıra daha yakınsa c nin değeri ona atanacak.
    else:                                 # else f(b) is nearer to 0 from f(b), so b = c
        b = c
    i += 1

print(table)
if i == 100:
    print("Bu aralikta kök bulunamadi")
else:
    print("Denklemin Kökü = ", c)


