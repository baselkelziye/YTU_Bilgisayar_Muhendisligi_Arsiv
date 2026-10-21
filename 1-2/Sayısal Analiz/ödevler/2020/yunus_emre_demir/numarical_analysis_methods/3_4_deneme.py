"""import pprint
import numpy


A = numpy.array([[3.6, 2.4, -1.8],
                 [4.2, -5.8, 2.1],
                 [0.8, 3.5, 6.5]])
L = numpy.linalg.cholesky(A)
U = numpy.linalg.cholesky(A)

print ("A:")
print(A)

print ("L:")
print(L)

print ("U:")
print(U)
"""

from math import sqrt
from pprint import pprint
import numpy

def cholesky(A,L,U):
    n = len(A)

    for i in range(n):
        for k in range(i + 1):
            tmp_sum = sum(L[i][j] * L[k][j] for j in range(k))
            if (i == k):  # Diagonal elements
                L[i][k] = A[i][i]
            else:
                L[i][k] = (1.0 / L[k][k] * (A[i][k] - tmp_sum))
    return L


def yazdir(matris):
    for i in range(len(matris)):
        print(matris[i], " |")
    print()

A = numpy.array( [[3.6, 2.4, -1.8],
                  [4.2, -5.8, 2.1],
                  [0.8, 3.5, 6.5]])

L = numpy.tril(A)
U = numpy.triu(A)
numpy.fill_diagonal(U, 1, wrap=False)

print("A:")
yazdir(A)
print("L:")
yazdir(L)
print("U:")
yazdir(U)

S = numpy.matmul(L, U)

print("S:")
yazdir(S)


K = cholesky(A,L,U)
print("K:")
yazdir(K)
