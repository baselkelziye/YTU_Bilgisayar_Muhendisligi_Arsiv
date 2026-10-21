#-----------------------------------------------------------------------

#Semih Balki
#Python IDE: Visual Studio Code
#Operating system: MacOS

#-----------------------------------------------------------------------
import math

y = int(input("Please enter y: "))
g = int(input("Please enter g: "))
p = int(input("Please enter m: "))#Mod size

#Taken from: https://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/ But I have modified.
#-----------------------------------------------------------------------
def primeFactors(n, base, power):
    # Print the number of two's that divide n
    while n % 2 == 0:
        if 2 not in base:
            power.append(1)
            base.append(2)
        else:
            for k in range(len(base)):
                if base[k] == 2:
                    power[k] = power[k] + 1
        n = n / 2

    # n must be odd at this point
    # so a skip of 2 ( i = i + 2) can be used
    for i in range(3, int(math.sqrt(n)) + 1, 2):

        # while i divides n , print i ad divide n
        while n % i == 0:
            if i not in base:
                power.append(1)
                base.append(int(i))
            else:
                for k in range(len(base)):
                    if base[k] == i:
                        power[k] = power[k] + 1
            n = n / i

            # Condition if n is a prime
    # number greater than 2
    if n > 2:
        if n not in base:
            power.append(1)
            base.append(int(n))
        else:
            for k in range(len(base)):
                if base[k] == n:
                    power[k] = power[k] + 1
#-----------------------------------------------------------------------

#modinv and egcd function are taken from: https://gist.github.com/ofaurax/6103869014c246f962ab30a513fb5b49
#-----------------------------------------------------------------------
def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    g, y, x = egcd(b%a,a)
    return (g, x - (b//a) * y, y)

def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('No modular inverse')
    return x%m

#-----------------------------------------------------------------------
#p - 1 = a.b, a <= b
power = []
base = []
primeFactors((p - 1), base, power)
composite_number = []
for i in range(2):
    composite_number.append(1)

for i in range(len(base)):
    for j in range(power[len(base) - 1 - i]):
        composite_number[composite_number.index(min(composite_number))] *= base[len(base) - 1 - i] 

#STEP 1
maximum = max(composite_number)
minimum = min(composite_number)
number = pow(g, minimum, p)#g^a(mod p)
result = pow(y, minimum, p)#y^a(mod p)
for i in range(maximum):
    if pow(number, i, p) == result:
        r = i
        break
#STEP 2
number = pow(g, maximum, p)#g^b(mod p)
result = (y * pow(modinv(g, p), r)) % p#y*((g^(-1))^r) % p
for i in range(minimum):
    if pow(number, i, p) == result:
        s = i
        break
#STEP 3
x = r + s*maximum
if pow(g, x, p) == y:
    print("Result is: ", x)
else:
    print("Problem")