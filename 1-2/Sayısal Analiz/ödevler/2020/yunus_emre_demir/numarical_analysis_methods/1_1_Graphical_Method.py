from prettytable import PrettyTable     # Create pretty Table :)

a = float(input("Enter the coefficient of x^0 = "))
b = float(input("Enter the coefficient of x^1 = "))
c = float(input("Enter the coefficient of x^2 = "))
d = float(input("Enter the coefficient of x^3 = "))
e = float(input("Enter the coefficient of x^4 = "))

x = float(input("Enter the starting value = "))
eps = float(input("Enter the Epsilon value = "))
delta = float(input("Enter the Delta x = "))

def fnk(x):
    return (e * x ** 4) + (d * x ** 3) + (c * x ** 2) + (b * x) + a

x1 = x + delta
fonk = fnk(x)           # x ilk değeli halini alır fonk a atar
fonk1 = fnk(x1)         # x+deltaX li değeri fonk1'e atıyoruz. Daha sonra bunların arasındaki farkın mutlak değeri eps'dan küçük olana kadar
                        # aşağıdaki while da görüldüğü üzre işlemleri yapıyoruz. Hangi işlemleri....

table = PrettyTable()
table.field_names = ['delta', 'x', 'f(x)', 'x+1', '|f(x)-f(x+1)|']
table.add_row([delta, x, fonk, x1, abs(fonk - fonk1)])      # abs(-a) = |-a| = a   //Absolute value

while (abs(fonk-fonk1) > eps):           # Do above while |f(x)-f(x+1)| > epsilon      (|Xk - Xk+1|)
    x = x1                      # x i güncelle
    x1 = x + delta              # x1 i güncelle
    fonk = fnk(x)               # değerlerini bul
    fonk1 = fnk(x1)
    table.add_row([delta, x, fonk, x1, abs(fonk - fonk1)])      # tabloya ekle. !!!! EĞER F(x) FARKLI BİR İŞARETE GEÇERSE DELTAYI KÜÇÜLT VE X KALDIĞIN DEĞERİNDEN DEVAM ET
    if (fonk1 * fonk < 0):              # if f(x) * f(x+1) < 0 , so there are opposite sign. + - or - +
        x1 = x1 - delta                 # x1 goes to one step back (Because new series start from them(Xk))
        delta = delta / 2               # And Delta must be lower to find most nearest value

print(table)
print("Denklemin Kökü = ", x1)
