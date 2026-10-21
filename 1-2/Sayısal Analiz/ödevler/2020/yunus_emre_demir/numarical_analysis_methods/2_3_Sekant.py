""" SEKANT YÖNTEMİ : Bütün olay yeni bir Xn+1 bulunup |Xn - Xn+1| farkına bakmakatan ibaret!"""

from prettytable import PrettyTable  # Create pretty Table :)
from scipy import poly1d  # To take a polinoms, derivation, and equations good!

n = int(input("Polinomun en yuksek derecesini giriniz : "))

dizi = []
for i in range(n, -1, -1):
    add = int(input("Derecesi {} olan terimin katsayisini giriniz :".format(i)))
    dizi += [add]  # !!! EKLEME İŞLEMİ İÇİN [İÇİNDE] YAZMALIYIZ.

x = float(input("Enter the starting value : "))
x1 = float(input("Enter the ending value : "))
eps = float(input("Enter the Epsilon value : "))

table = PrettyTable()
table.field_names = ['x', 'x0', 'y0=f(x0)', 'x1', 'y1=f(x1)', '|Xk - X(k+1)|']

def f(a):
    f_h = poly1d(dizi)
    f_h = float(f_h([a]))
    return f_h

i = 0
while abs(x - x1) > eps and i < 100:  # Do above while  (|g(x) - h(x)| > epsilon)
    table.add_row([i, x, f(x), x1, f(x1), abs(x - x1)])  # abs(-a) = |-a| = a   //Absolute value
    degisken = x1
    x1 = x1 - ((x1 - x) / (f(x1) - f(x))) * f(x1)
    x = degisken
    i += 1

table.add_row([i, x, f(x), x1, f(x1), abs(x - x1)])
print(table)
if i == 100:
    print("Denklemin kökü bulunamadı.")
else:
    print("Denklemin Kökü = ", x1)
