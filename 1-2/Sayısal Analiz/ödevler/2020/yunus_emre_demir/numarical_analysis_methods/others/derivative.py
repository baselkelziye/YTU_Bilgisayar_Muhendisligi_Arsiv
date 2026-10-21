import math
from scipy import poly1d
polinom = poly1d([1, math.sin, 4])

#polinom = math.sqrt(polinom)
print (polinom)

pt = polinom.deriv()
print(pt)

pts = pt([3])
print(pts)

for i in range(5,-1,-1):
    print(i)



"""

from scipy import poly1d
polinom = poly1d([1, 2, 4])
print (polinom)
print (polinom.deriv())"""