import numpy as np
from numpy.linalg import inv
matris = []
c = []
"""
denklem = int(input("Denklem sayisi :"))
derece = int(input("Değişken sayisi :"))

for i in range(denklem):
    m_satir =[]
    print("{}. denklemin katsayilarini gir.".format(i + 1))
    for j in range(derece):
        deger = float(input("{}. değer :".format(j+1)))
        m_satir.append(deger)

    matris.append(m_satir)
    sonuc = float(input("{}. esitlik Sonuç :".format(i+1)))
    c.append(sonuc)

matris = [[5, 2, -4], [1, 4, 2], [2, 3, 6]]
c = [7, 14, 1]
derece =3

kokler = []
for i in range(derece):
    kokler.append(0.0)

def yazdir(matris,c):
    for i in range(len(matris)):
        print(matris[i], " |", c[i])
    print()

print("\nGirdiginiz denklemlerin katsayilar matrisi :")
yazdir(matris,c)

a = np.array(matris)
ai= inv(a)
print(ai)

birim = np.eye(3)
print(birim)

"""
# Python3 program to decompose
# a matrix using Cholesky
# Decomposition
import math
MAX = 100
def Cholesky_Decomposition(matrix, n):
    lower = [[0 for x in range(n + 1)]
             for y in range(n + 1)]

    # Decomposing a matrix
    # into Lower Triangular
    for i in range(n):
        for j in range(i + 1):
            sum1 = 0
            # sum1mation for diagnols
            if j == i:
                for k in range(j):
                    sum1 += pow(lower[j][k], 2)
                lower[j][j] = (math.sqrt(math.fabs(matrix[j][j] - sum1)))
            else:
                # Evaluating L(i, j)
                # using L(j, j)
                for k in range(j):
                    sum1 += (lower[i][k] * lower[j][k])
                if (lower[j][j] > 0):
                    lower[i][j] = int((matrix[i][j] - sum1) /
                                      lower[j][j])

                    # Displaying Lower Triangular
    # and its Transpose
    print("Lower Triangular\t\tTranspose")
    for i in range(n):

        # Lower Triangular
        for j in range(n):
            print(lower[i][j], end="\t")
        print("", end="\t")

        # Transpose of
        # Lower Triangular
        for j in range(n):
            print(lower[j][i], end="\t");
        print("");

    # Driver Code
n = 3;
matrix = [[3.6, 2.4, -1.8],
          [4.2, -5.8, 2.1],
          [0.8, 3.5, 6.5]];
Cholesky_Decomposition(matrix, n);

# This code is contributed by mits