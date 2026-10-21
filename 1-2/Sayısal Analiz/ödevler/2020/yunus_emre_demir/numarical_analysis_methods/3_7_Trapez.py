""" formük basit
h = (y-x)/n
trapez = h/2 (f(x)+f(y)) + h * (diğer y ler))]

"""
from scipy import poly1d  # To take a polinoms, derivation, and equations good!

derece = int(input("Polinomun en yuksek derecesini giriniz : "))
dizi = []
for i in range(derece, -1, -1):
    add = float(input("Derecesi {} olan terimin katsayisini giriniz :".format(i)))
    dizi += [add]  # !!! EKLEME İŞLEMİ İÇİN [İÇİNDE] YAZMALIYIZ.

#dizi = [1,0,0,0]
print("araligi giriniz [x,y] (y>x olacak sekilde)")
x = float(input("x : "))
y = float(input("y : "))

n = float(input("n : aralik sayisini giriniz :"))

# Katsayıları verdim bir eşitlik oluşturdu güzelde bir yazzımı var 2 satırda üstleride göstermeye çalışan.
f_h = poly1d(dizi)

def fnk(x):
    return f_h(x)

h = (y - x) / n                         # h hesaplanır..
print("\nh :",h, "\n",)
top = fnk(x) * (h/2)                                # İLK sonuç * h/2
print("f(x) :", fnk(x))


x += h                              # x in ikinci değeri için h eklenir.
while (x < y):
    f = fnk(x)
    print("f(x) :",f)
    f *= h                                          # DİĞER Y ler *h
    top += f

    x += h


f = fnk(x)                                          # SON Sonuç * h/2
top += f * (h/2)
print("f(x) :", f)

if (top < 0):
    top *= (-1)


print("\n----->alan :", top)                         # tüm bunlar top değişkeninde tutuldu ve bitti


