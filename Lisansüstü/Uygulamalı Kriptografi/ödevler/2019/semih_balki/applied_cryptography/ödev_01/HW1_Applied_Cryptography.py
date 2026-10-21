#-----------------------------------------------------------------------

#Semih Balki
#Python IDE: PyCharm
#Operating system: MacOS

#-----------------------------------------------------------------------

y = int(input("Please enter y: "))
g = int(input("Please enter g: "))
k = int(input("Please enter k: "))

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

import math
import random
from timeit import default_timer as timer
#SHANKS ALGORITHM#
start = timer()
m = math.ceil(math.sqrt(k))
giant_step = []
baby_step = []

for i in range(m):
    giant_step.append((g**(m*i)) % k)
for j in range(m):
    baby_step.append((y*(g**j)) % k)

result = 0
print("RESULT OF SHANKS ALGORITHM")
for z in range(len(giant_step)):
    for n in range(len(baby_step)):
        if giant_step[z] == baby_step[n]:
            print("i: ", z)
            print("j: ", n)
            result = z * m - n
end = timer()
if result != 0:
    if y == (g**result) % k:
        print("Giant step: ", giant_step)
        print("Baby step: ", baby_step)
        print("Answer is: ", result)
        print("Time take to complete shanks algorithm: ", end - start)
else:
    print("No result")

print(" ")
#POLLARD RHO ALGHORITHM#
start = timer()

S_zero = []
S_one = []
S_two = []

alpha = random.randint(1, k-1)
a_zero = g**alpha % k

result = a_zero
count = 1
powers_of_y = 0
powers_of_g = alpha
y_power_list = []
g_power_list = []

#-----------------------------------------------------------------------

answer = []#GLOBAL VARIABLE TO HOLD THE SOLUTIONS OF THE MODULUS EQUATION
index_i = []
index_j =[]

def modulus_operation(a, b, n, i, j):
    if math.gcd(a, n) == 1:
        x = modinv(a, n) * b
        x = x % n
        if y == int((g**x) % k):
            if x in answer:
                pass
            else:
                answer.append(x)
                index_i.append(i)
                index_j.append(j)
    else:
        d = math.gcd(a, n)
        if b % d == 0:
            x_bar = (modinv(a/d, n/d) * b/d) % (n/d)
            for i in range(d - 1):
                hold = x_bar + (i * (n/d))
                try:
                    if y == int((g**hold) % k):
                        if hold in answer:
                            pass
                        else:
                            answer.append(hold)
                            index_i.append(i)
                            index_j.append(j)
                except OverflowError:
                    pass


#-----------------------------------------------------------------------

if a_zero <= math.ceil(k / 3) and a_zero >= 1:
    S_zero.append(a_zero)
    S_one.append(-1)
    S_two.append(-1)
elif a_zero <= math.ceil(2*k / 3) and (math.ceil(k/3) + 1) <= a_zero:
    S_zero.append(-1)
    S_one.append(a_zero)
    S_two.append(-1)
else:
    S_zero.append(-1)
    S_one.append(-1)
    S_two.append(a_zero)

g_power_list.append(alpha)
y_power_list.append(0)


while count < (math.ceil(k/3)):
    if result in S_zero:
        result = (y * result) % k
        powers_of_y += 1
    elif result in S_one:
        result = pow(result, 2, k)
        powers_of_g = powers_of_g * 2
        powers_of_y = powers_of_y * 2
    elif result in S_two:
        result = (g * result) % k
        powers_of_g += 1
    g_power_list.append(powers_of_g)
    y_power_list.append(powers_of_y)
    if result <= math.ceil(k / 3) and result >= 1:
        S_zero.append(result)
        S_one.append(-1)
        S_two.append(-1)
    elif result <= math.ceil(2 * k / 3) and (math.ceil(k / 3) + 1) <= result:
        S_zero.append(-1)
        S_one.append(result)
        S_two.append(-1)
    else:
        S_zero.append(-1)
        S_one.append(-1)
        S_two.append(result)
    count += 1

for i in range(len(S_zero)):
    if S_zero[i] != -1:
        for j in range(len(S_zero)):
            if y_power_list[i] > y_power_list[j]:
                big = y_power_list[i] - y_power_list[j]
                small = g_power_list[j] - g_power_list[i]
            else:
                big = y_power_list[j] - y_power_list[i]
                small = g_power_list[i] - g_power_list[j]

            if (S_zero[i] == S_zero[j]) and (i != j):
                if (i % 2 == 1 and j % 2 == 1) or (i % 2 == 0 and j % 2 == 0):
                    d = math.gcd(big % (k - 1), (k - 1))
                    b = (small) % (k - 1)
                    a = big % (k - 1)
                    modulus_operation(a,b, (k - 1), i, j)
                elif (i % 2 == 1 or i % 2 != 0) and (j % 2 == 0 or j % 2 == 1):
                    d = math.gcd(big, (k - 1))
                    b = (small + 1) % (k - 1)
                    a = big % (k - 1)
                    modulus_operation(a,b, (k - 1), i, j)

if len(answer) == 0:
    for i in range(len(S_one)):
        if S_one[i] != -1:
            for j in range(len(S_one)):
                if y_power_list[i] > y_power_list[j]:
                    big = y_power_list[i] - y_power_list[j]
                    small = g_power_list[j] - g_power_list[i]
                else:
                    big = y_power_list[j] - y_power_list[i]
                    small = g_power_list[i] - g_power_list[j]

                if (S_one[i] == S_one[j]) and (i != j):
                    if (i % 2 == 1 and j % 2 == 1) or (i % 2 == 0 and j % 2 == 0):
                        d = math.gcd(big % (k - 1), (k - 1))
                        b = (small) % (k - 1)
                        a = big % (k - 1)
                        modulus_operation(a, b, (k - 1), i, j)
                    elif (i % 2 == 1 or i % 2 != 0) and (j % 2 == 0 or j % 2 == 1):
                        d = math.gcd(big, (k - 1))
                        b = (small + 1) % (k - 1)
                        a = big % (k - 1)
                        modulus_operation(a, b, (k - 1), i, j)

if len(answer) == 0:
    for i in range(len(S_two)):
        if S_two[i] != -1:
            for j in range(len(S_two)):
                if y_power_list[i] > y_power_list[j]:
                    big = y_power_list[i] - y_power_list[j]
                    small = g_power_list[j] - g_power_list[i]
                else:
                    big = y_power_list[j] - y_power_list[i]
                    small = g_power_list[i] - g_power_list[j]

                if (S_two[i] == S_two[j]) and (i != j):
                    if (i % 2 == 1 and j % 2 == 1) or (i % 2 == 0 and j % 2 == 0):
                        d = math.gcd(big % (k - 1), (k - 1))
                        b = (small) % (k - 1)
                        a = big % (k - 1)
                        modulus_operation(a, b, (k - 1), i, j)
                    elif (i % 2 == 1 or i % 2 != 0) and (j % 2 == 0 or j % 2 == 1):
                        d = math.gcd(big, (k - 1))
                        b = (small + 1) % (k - 1)
                        a = big % (k - 1)
                        modulus_operation(a, b, (k - 1), i, j)

end = timer()

print("RESULT OF POLLARD RHO ALGORITHM")
print(answer)
for i in range(len(index_j)):
    print("Alpha: ", alpha)
    print("Solution(s) is founded at the following indexes: ", index_i[i], index_j[i])
    print("Power of y at ", index_i[i], "is: ", y_power_list[index_i[i]])
    print("Power of g at ", index_i[i], "is: ", g_power_list[index_i[i]])
    print(" ")
    print("Power of y at ", index_j[i], "is: ", y_power_list[index_j[i]])
    print("Power of g at ", index_j[i], "is: ", g_power_list[index_j[i]])
    print("Time take to complete Pollard rho algorithm: ", end - start)