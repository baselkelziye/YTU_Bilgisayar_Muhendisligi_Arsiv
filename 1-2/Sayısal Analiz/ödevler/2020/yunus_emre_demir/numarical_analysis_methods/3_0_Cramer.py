"""
1. Kare mi diye baksın bilinmeyen sayısı ile denklem sayısı aynı olmalı.
2. x = |delta(x)| / |A| , y = |delta(y)| / |A|
"""
import numpy as np
from numpy import linalg

def yazdir(matris, c):
    for i in range(len(matris)):
        print(matris[i], " |", c[i])

A = []
B = []
C = []

denklem = int(input("Denklem sayisi :"))
derece = int(input("Değişken sayisi :"))

if denklem != derece:                                                  # Kare mi kontrolü ?
    print("Bu denklemi Cremer ile çözemezsiniz. Bilinmeyen sayısı ile denklem sayısı aynı olmalı.")
    exit()

for i in range(denklem):                                                # girdiler alınıyor
    m_satir =[]
    print("{}. denklemin katsayilarini gir.".format(i + 1))
    for j in range(derece):
        deger = float(input("{}. değer :".format(j+1)))
        m_satir.append(deger)

    A.append(m_satir)                                                  # A = ana matris
    sonuc = float(input("{}. esitlik Sonuç :".format(i+1)))
    B.append(sonuc)                                                     # B sonuç matrisi

"""A = [[3.6, 2.4, -1.8],
     [4.2, -5.8, 2.1],
     [0.8, 3.5, 6.5]]

B = [6.3, 7.5, 3.7]"""

C =np.zeros( (denklem, derece))                                      # A nın bir kopyası olan C matrisi oluşturuluyor.
for i in range(denklem):
    for j in range(derece):
        C[i][j]=A[i][j]

yazdir(A,B)
print()

X = []
for i in range(0, len(B)):
    for j in range(0, len(B)):
        C[j][i] = B[j]                              # B yi araya sok
        if i > 0:
            C[j][i - 1] = A[j][i - 1]               # Bozulan Bir önceki sütunu düzelt
    print(i, ". sütun B matrisi ile değiştirildi.")
    yazdir(C, B)
    X.append(round(linalg.det(C)/linalg.det(A), 2))                             #Formülü uygula determinantları böl sonucu bul
    print("det(C) / det(A) = ", linalg.det(C),"/", linalg.det(A),"=", X[i])
    print()

for i in X:
    print("{}.kök = {} ".format(X.index(i), i))
