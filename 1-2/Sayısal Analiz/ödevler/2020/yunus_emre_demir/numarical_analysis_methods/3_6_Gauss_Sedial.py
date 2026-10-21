import numpy as np

def yazdir(matris,c):
    for i in range(len(matris)):
        print(matris[i], " |", c[i])
    print()


# mesela x3 ü hesaplar ken x1 ve x2 nin güncel değerlerini kullanıyor.
def seidel(A, x, b):
    for j in range(len(A)):
        d = b[j]
        for i in range(len(A)):         # to calculate respective xi, yi, zi
            if (j != i):                # diagonaldeki eleman değilse
                d -= A[j][i] * x[i]     # ana formül :  x1 = (sonuç -..x2 -..x3) / ..(x1)
        x[j] = d / A[j][j]              # x(n) in yeni değerini update ediyor ve x(n+1) hesabına dönüyor
    return x


matris = []
b = []

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
    b.append(sonuc)

startvalue = []
for i in range(derece):
    startvalue.append(float(input("Enter the starting value of x^{}: ".format(i))))
x = np.array(startvalue)
eps = float(input("Enter the Epsilon value : "))

"""
matris = [[3, 1, -2],
     [-1, 4, -3],
     [1, -1, 4]]

b = [9, -8, 1]
x =  np.array([1.0, 1.0, 1.0])
eps = 0.02

matris = [[2, 4, -3, 1],
         [1, -2, 5, 3],
         [-4, -1, 6, 2],
          [3, 4, -8, 4]]

b = [15, 11, -5, 12]
x = np.array([0, 0, 0, 0])
eps = 0.00001
"""

print("Girilin matris : ")
yazdir(matris,b)
#print(matris)
#print(b)

i=0
N = k = 50                              # k öylesine eps den yüksel bir sayı işte.
while i < N and k > eps:                # sadece durma noktası kontrolü yapıyor.
    print("{}. adım {} --> k : {}".format(i,x,k))
    oldx = x.copy()                     # x matrisini i sakla oldx diyerek
    x = seidel(matris, x, b)            # yenisini oluştur.
    k = max(abs((x-oldx)/x))            # k değeri oluştur kontrol et
    i += 1

if i == 50:
    print("Denklemin kökleri bulunalamdı.")
else:
    print("{}. adım {} --> k : {} < eps = {}".format(i, x, k, eps))
