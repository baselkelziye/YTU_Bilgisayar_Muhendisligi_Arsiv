"""Mantık şu ilk önce en yüksek Polinomun derece ve katsayısını alıyoruz.
Bunu ayrı almamızın sebebi bunu g(x) olarak kabul edecek olmamız. h(x)'i ise geri kalan polinom oluşturacaktır.
h(x) oluşturulurken enb. dereceli polinomun katsayısına bölünür ve 1/derecesi ** üst olarak eklenerek
h(x) elde edilmiş olunur.)
* Ek olarak g(x)' > h(x)' olduğu için yakınsak çıkar. Yinede kök olmamasına karşın önlem olarak i<100 ile
    döngüyü sınırladım.
"""

from prettytable import PrettyTable  # Create pretty Table :)
from scipy import poly1d    # To take a polinoms, derivation, and equations good!

n = int(input("Polinomun en yuksek derecesini giriniz : "))
eyk = int(input("En yuksek dereceli polinomun katsayısı : "))

dizi = []
for i in range(n-1,-1,-1):
    add = int(input("Derecesi {} olan terimin katsayisini giriniz :".format(i)))
    dizi += [add]  # !!! EKLEME İŞLEMİ İÇİN [İÇİNDE] YAZMALIYIZ.

x = float(input("Enter the starting value = "))
eps = float(input("Enter the Epsilon value = "))

# Katsayıları verdim bir eşitlik oluşturdu güzelde bir yazzımı var 2 satırda üstleride göstermeye çalışan.
f_h = poly1d(dizi)
# g(x) yani enb. katsayılı X'i yalnız bırakmak adına h(x)'i Eşitliğin karşısına attım(* -1). Ve g(x)=Enbüyük polinomun katsayısına böldüm. Sonuç x yalnız kaldı.
f_h = (-1 * f_h) / eyk

def h_bul(x):
    f_h_d = float(f_h([x]))         #print("pol değer f_h_d", f_h_d)
    f_h_d = (f_h_d) ** (1/n)        # X = (2x+5)^1/n  mesela buradaki n de X in derecesi YANİ KÖK İŞLEMİ
    print(f_h_d)
    return f_h_d

table = PrettyTable()
table.field_names = ['g(x)', 'h(x)', '|Xk - X(k+1)|']

g = x
h = h_bul(g)
i = 0
while abs(g - h) > eps and i < 100:        # Do above while  (|g(x) - h(x)| > epsilon)
    table.add_row([g, h, abs(g - h)])      # abs(-a) = |-a| = a   //Absolute value
    g = h
    h = h_bul(h)                           # Calculate new h()
    i += 1

table.add_row([g, h, abs(g - h)]) #TestArrayComparisons satırı göstermesi için eklendi.
print(table)
if i == 100:
    print("Denklemin kökü bulunamadı.")
else:
    print("Denklemin Kökü = ", h)
