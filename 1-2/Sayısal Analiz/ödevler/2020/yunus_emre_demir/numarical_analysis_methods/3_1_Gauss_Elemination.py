# [0][0] ı 1 liyor sonra 1,0 ı birliyor sonra çıkartıyor. sonra 2,0 ı birle çıkart 3,0 ı birle çıkart
# [1][1] i 1 liyor sonra 2,1 i birliyor sonra çıkartıyor. sonra 3,1 ı birle çıkart
# [2][2] i 1 liyor sonra 3,2 i birliyor sonra çıkartıyor. sonra
# [3][3] ü birliyor ve çıkıyor.
# Matris ortaya çıktıktan sonra ise kökler matrisi(içi tamamen sıfır)
# sum = [][]
# sum = kök 3 + [][]
# sum = kök 3 + kök 2 + [][]

matris = []
c = []

denklem = int(input("Denklem sayisi :"))
derece = int(input("Değişken sayisi :"))
"""
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
matris = [[2,4,-3,1], [-4,-1,6,2], [1,-2,5,3], [3,4,-8,4]]
c = [15,-5,11,12]
derece =4

kokler = []
for i in range(derece):
    kokler.append(0.0)

def yazdir(matris,c):
    for i in range(len(matris)):
        print(matris[i], " |", c[i])
    print()

print("\nGirdiginiz denklemlerin katsayilar matrisi :")
yazdir(matris,c)

K = derece
for t in range(K):
    for i in range(t, K):
        bol = matris[i][t]                              # bol = a11
        print("{}. satır, matris[{}][{}]={} ile bölünecek(üste bak :))".format(i,i,t,bol))
        for j in range(K):
            matris[i][j] = matris[i][j] / bol           # 1. satiri a11'e böl       # 2. satırıda a21' e böl
        c[i] = c[i] / bol                               # 1. sonucu a11'e böl       # 2. sonucu a21' e böl
        yazdir(matris,c)
        if i > t:                                       # bir sonraki satır işlemi şimdi:
            print("{}. satırdan {}. satır çıkartılır".format(i,t))
            for k in range(K):
                matris[i][k] = matris[i][k] - matris[t][k]      # 2. satırdan 1. satırı  çıkart.
            c[i] = c[i] - c[t]                                  # 2. satırdan 1. satırı  çıkart.
            yazdir(matris,c)

for i in range(K-1, -1, -1):
    sum = c[i]
    for j in range(i, K):
        print("sum = sum - matris[i][j] * kokler[j] // {} = {} - {} * {} ".format(sum,sum,matris[i][j],kokler[j]))
        sum = sum - matris[i][j] * kokler[j]    # sum = matris[i][i]*Z + matris[i][i-1]*W +  0*Y + 0*X
    print("kokler[i] = sum / matris[i][i] // {} = {} / {} ".format(kokler[i],sum,matris[i][i]))
    kokler[i] = sum / matris[i][i]      # sum = matris[i][i]*Z    ise    Z = sum / matris[i][i]

for j in kokler:
    print("{}.kök = {} ".format(kokler.index(j), j))
