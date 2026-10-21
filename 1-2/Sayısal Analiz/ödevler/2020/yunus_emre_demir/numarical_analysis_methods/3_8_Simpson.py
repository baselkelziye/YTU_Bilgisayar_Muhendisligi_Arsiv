""" formük basit
h = (y-x)/n
simpson = h/3 [f(x)+f(y) + 4*f(tekler) + 2*f(çiftler)]

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

h = (y - x) / n                                         # h'ımıız oluşturduk.
print("\nh :",h, "\n",)
top = fnk(x)                                            # İLK DEĞERİ topla
print("f(x) :",top)

x += h
tekmi = 1

while (x < y):
    if (tekmi % 2 == 1):                                # tekse 4 ile çarp topla
        f = fnk(x)
        print("f(x) :",f)
        f *= 4
    else:                                               # çift ise 2 ile çarp topla
        f = fnk(x)
        print("f(x) :", f)
        f *= 2

    tekmi += 1
    x += h
    top += f


f = fnk(x)                                              # ServerOnlyCompressionTest DEĞERİ topla
top += f
print("f(x) :", f)

if (top < 0):
    top *= (-1)

top = top * (h / 3)                                      # Sonucu böl h/3 e
print("\n----->alan :", top)


