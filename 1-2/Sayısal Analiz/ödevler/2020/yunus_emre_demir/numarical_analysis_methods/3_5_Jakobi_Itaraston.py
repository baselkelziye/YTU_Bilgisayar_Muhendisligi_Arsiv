from numpy import array, zeros, diag, diagflat, dot, argmax


def jacobi(A, b, x, eps):

    D = diag(A)
    print("\nDiagonel A : ", D)

    R = A - diagflat(D)
    print("\nR = Diagonellerin çıkmış hali \n",R)
    print()

    i=0
    k = N = 60                          # k öylesine eps den yüksel bir sayı işte.
    while i < N and k > eps:        # N = MAX İTERASYON SAYISI
        print("{}. adım {} --> k : {}".format(i,x,k))
        oldx = x.copy()
        x = (b - dot(R,x)) / D      # Herşeyi 3 ü için yapıyor. dot(R,x) mesela birinci satırı  x değerleriyle çarp + topla, ikinci satırı çarp topla vs.
                                    # ANA FORMÜL BU!
        k = max(abs((x-oldx)/x))    # k formülü

        i += 1
    if i == N:
        print("Denklemin kökleri bulunalamdı.")
        exit()
    else:
        print("{}. adım {} --> k : {} < eps = {}".format(i, x, k, eps))
        return x


def f(A,b):
    D = diag(A)
    R = A - diagflat(D)
    sonuc = 0
    for i in range(len(A)):
        top = 0
        for j in range(len(b)):
            #print("top : ", top , "abs(R[i][j] :", abs(R[i][j] ))
            top = top + abs(R[i][j])                                                        # 1. Satırı topla , 2. satırı yopla, 3. satırı topla
        if abs(D[i]) < top:                                                                 # diagonal 1 den küçükmü diye bak.
            print("|a{}{}|={} < |top|={}".format(i,i,abs(D[i]),top))                        # küçükse yakınsama koşulu sağlanmıyor.
            print("Yakınsama koşulu sağlanmıyor. Denklemler yer değiştirilip tekrar bakılacak.")
            #exit()


matris = []
c = []


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

startvalue = []
for i in range(derece):
    startvalue.append(float(input("Enter the starting value of x^{}: ".format(i))))
eps = float(input("Enter the Epsilon value : "))

"""
matris = [[3, 1, -2],
     [-1, 4, -3],
     [1, -1, 4]]

c = [9, -8, 1]
startvalue = [1.0, 1.0, 1.0]
eps = 0.02
"""

matris = array(matris)
f(matris,c)                     # yakınsama kontrolü yapar. Sufficient not necessary.

print ("A:", matris)
print ("b:", c)

sol = jacobi(matris, c, startvalue, eps)
print ("x:", sol)

