"""
x var x1 i bul farkının mutlak değeri eps den küşün olana kadar devam et
x1 = x - fnk(x) / fnk(x)'

"""
from prettytable import PrettyTable  # Create pretty Table :)
from scipy import poly1d  # To take a polinoms, derivation, and equations good!

n = int(input("Polinomun en yuksek derecesini giriniz : "))
dizi = []
for i in range(n, -1, -1):
    add = int(input("Derecesi {} olan terimin katsayisini giriniz :".format(i)))
    dizi += [add]  # !!! EKLEME İŞLEMİ İÇİN [İÇİNDE] YAZMALIYIZ.

x = float(input("Enter the starting value = "))
eps = float(input("Enter the Epsilon value = "))

# Katsayıları verdim bir eşitlik oluşturdu güzelde bir yazımı var 2 satırda üstleride göstermeye çalışan.
f_h = poly1d(dizi)  # Fonksiyon oluşturulur.
f_h_t = f_h.deriv()  # Türevi alınır.


def fnk(x):
    return f_h(x)


def derivative(x):
    return f_h_t(x)


x1 = x - fnk(x) / derivative(x)  # The main rule of this method. That's all!

table = PrettyTable()
table.field_names = ['X', 'X(k+1)', '|Xk - X(k+1)|']

i = 0
while abs(x1 - x) > eps and i < 100:  # Do above while  (|Xk - Xk+1| > epsilon)
    table.add_row([x, x1, abs(x1 - x)])  # abs(-a) = |-a| = a   //Absolute value
    x = x1
    x1 = x - fnk(x) / derivative(x)                 # Sürekli bu kuralı uyguluyor başka bir espirisi yok :)

table.add_row([x, x1, abs(x1 - x)])  # Son satırı göstermiyor anlamadım? Oyüzden ekledim.
print(table)

if i == 100:
    print("Denklemin kökü bulunamadı.")
else:
    print("Denklemin Kökü = ", x1)
