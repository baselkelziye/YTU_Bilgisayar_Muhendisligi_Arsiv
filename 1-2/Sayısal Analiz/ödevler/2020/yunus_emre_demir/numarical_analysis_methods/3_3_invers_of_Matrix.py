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
"""
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

"""birim = np.eye(3)
print(birim)"""
