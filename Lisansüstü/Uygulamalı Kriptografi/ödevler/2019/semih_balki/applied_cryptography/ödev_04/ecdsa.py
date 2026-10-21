#-----------------------------------------------------------------------

#Semih Balki
#Python IDE: Visual Studio Code
#Operating system: MacOS

#-----------------------------------------------------------------------
#GLOBAL VARIABLES
#                       PROPERTIES OF THE ELLIPTIC CURVE
m = 29#Number set
a = -1
b = 1
order = 0
#-----------------------------------------------------------------------

import math

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

def modinv(a, M):
    g, x, y = egcd(a, M)
    if g != 1:
        raise Exception('No modular inverse')
    return x%M

#-----------------------------------------------------------------------

def Weierstrass_addition(p1, p2):
    m = 29
    if p1 == [0, 0]:
        return p2
    elif p2 == [0, 0]:
        return p1
    elif (p1[0] == p2[0]) and ((p1[1] + p2[1]) % m == 0):#(x, y) + (x, -y)
        return [0, 0]#point at infinity
    else:
        if p1[0] != p2[0]:
            if p2[0] - p1[0] == 0:#Divide by zero
                return [0, 0]#return point at infinity
            else:
                M = (p2[1] - p1[1]) * modinv((p2[0] - p1[0]) % m, m)
                M = M % m
        elif p1[0] == p2[0] and p1[1] == p2[1]:
            if p1[1] == 0:#Divide by zero
                return [0, 0]#return point at infinity
            else:
                M = (3 * pow(p1[0], 2) + a) * modinv((2 * p1[1]) % m, m)
                M = M % m 
        x3 = (pow(M, 2) - p1[0] - p2[0]) % m
        y3 = (M * (p1[0] - x3) - p1[1]) % m
    return [x3, y3]

#-----------------------------------------------------------------------

def primitive_point_find(points):
    primitive_points = []
    for i in range(order):
        p3 = [0, 0]
        if points[i] == [0, 0]:
            pass
        else:
            count = 0
            for j in range(order):
                p3 = Weierstrass_addition(points[i], p3)
                if p3 not in points:
                    break
                else:
                    count += 1
                if p3 == [0, 0] and count == order:
                    primitive_points.append(points[i])
    return primitive_points

#-----------------------------------------------------------------------

def check_point(p):#Check a point is the on the curve or not
    if pow(p[1], 2) % m == (pow(p[0], 3) + a * p[0] + b) % m:
        print("The point ", "(", p[0], ", ", p[1], ")", "is on the curve.")
    else:
        print("The point ", "(", p[0], ", ", p[1], ")", "is not on the curve.")

#-----------------------------------------------------------------------

def order_of_a_point(p, points):#Find the order of a point
    p3 = [0, 0]
    count = 0
    for j in range(order):
        p3 = Weierstrass_addition(p, p3)
        print(j+1, ": ", p3)
        if p3 not in points:
            break
        else:
            count += 1
    print("Order of the ", "(", p[0], ", ", p[1], ")", " is: ", order)

#-----------------------------------------------------------------------

#For discrete square root problem(Enumeration)
square_root = []
for i in range(m):
    square_root.append(-1)#-1: sembolik gosterim
for i in range(m):#bu asamanin sonunda array'de -1 olan yerler'de square root yok manasina geliyor
    number = pow(i, 2, m)
    if square_root[number] == -1:
        if m - i != m:
            square_root[number] = [i, m - i]
        else:
            square_root[number] = [i]

print("\n \n \n")
print("SQUARE ROOT PROBLEM")
#sum = ""
#for i in range(len(square_root)):
#    sum += str(i) + " "
#print(sum)
#sum = ""
for i in range(len(square_root)):
    if square_root[i] == -1:
        #sum += " "
        print(i, ": ")
    else:
        #sum += str(square_root[i]) + " "
        print(i, ":", square_root[i])
#print(sum)
print("\n \n \n")
#-----------------------------------------------------------------------

points = []
for i in range(m):
    number = (pow(i, 3) + a * i + b) % m 
    if square_root[number] != -1:
        for k in range(len(square_root[number])):
            points.append([i, square_root[number][k]]) 
points.append([0, 0])#Adding point at infinity. (0, 0) represents point at infinity

#-----------------------------------------------------------------------

order = len(points)
print("Order of the curve: ", order)
print("\n \n \n")

#-----------------------------------------------------------------------

print("Points of the curve")
for i in range(len(points)):
    print(i+1, ": ", points[i])

#-----------------------------------------------------------------------

base = []
power = []
primeFactors(order, base, power)
divisors = [1, order]
for i in range(len(base)):
    for j in range(len(base)):
        if base[i] != 1 and base[i] != order:
            divisors.append(base[i] * power[j]) 
#divisors.sort()
#print("Divisors of ", order, " are:", divisors)

#-----------------------------------------------------------------------

print("\n \n \n")
primitive_points = primitive_point_find(points)
print("Primitive points on the curve: ")
length = len(primitive_points)
for i in range(length):
    print(i+1, ": ", primitive_points[i])
print(" ")

#-----------------------------------------------------------------------
#                       ECDSA Key Generation
d = 25# Private key
P = [0, 1]
#Given the private key, going to compute the public key
Q = [0, 0]# Public key
for i in range(d):
    Q = Weierstrass_addition(P, Q)
    print(i+1, ":", Q)
print("Public key: ", Q)
#-----------------------------------------------------------------------
#                      ECDSA Signature Generation
print(" ")


h_m = 10 # h(m) = 10
import random

def random_number_computation():
    return random.randint(1, order - 1)

def compute_point_multiple_times(P, k):
    Z = [0, 0]
    for i in range(k):
        Z = Weierstrass_addition(P, Z)
    return Z

k = random_number_computation()
Z = compute_point_multiple_times(P, k)
r = Z[0] % order 
if r == 0:
    while r == 0:
        k = random_number_computation()
        Z = compute_point_multiple_times(P, k)
        r = Z[0] % order 
        k_inverse = modinv(k, order)
        s = (k_inverse * (h_m + d * r)) % order
        if s == 0:
            while s == 0:
                k = random_number_computation()
                Z = compute_point_multiple_times(P, k)
                r = Z[0] % order 
                k_inverse = modinv(k, order)
                s = (k_inverse * (h_m + d * r)) % order
elif r != 0:
    k_inverse = modinv(k, order)
    s = (k_inverse * (h_m + d * r)) % order
    if s == 0:
        while s == 0:
            k = random_number_computation()
            Z = compute_point_multiple_times(P, k)
            r = Z[0] % order 
            k_inverse = modinv(k, order)
            s = (k_inverse * (h_m + d * r)) % order

print("k: ", k)# Step 1
print("x1, y1: ", Z[0], "", Z[1])# Step 2
print("r: ", r)# Step 2
print("k_inverse: ", k_inverse)# Step 3
print("s: ", s)#Step 4

m = [r, s]
print(" ")
#-----------------------------------------------------------------------
#                      ECDSA Signature Verification
if 1 <= m[0] and m[1] <= (order - 1):
    w = modinv(m[1], order)
    u1 = (h_m*w) % order
    u2 = r*w % order
    mult_of_P = compute_point_multiple_times(P, u1)
    mult_of_Q = compute_point_multiple_times(Q, u2)
    N = Weierstrass_addition(mult_of_P, mult_of_Q)
    v = N[0] % order
    if v == r:
        print("Sinature is accepted")
    else: 
        print("Signature is not accepted")

print(" ")

print("w: ", w)# Step 2
print("u1: ", u1)# Step 3
print("u2: ", u2)# Step 3
print("x1: ", N[0])# Step 4
print("y1: ", N[1])# Step 4
print("v: ", v)# Step 4