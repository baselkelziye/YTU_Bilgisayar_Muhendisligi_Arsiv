#-----------------------------------------------------------------------

#Semih Balki
#Python IDE: PyCharm
#Operating system: MacOS

#-----------------------------------------------------------------------

#INDEX CALCULUS ALGORITHM
S = [5, 7]#Factor base

y = int(input("Please enter y: "))
g = int(input("Please enter g: "))
m = int(input("Please enter m: "))#Mod size


import random
import numpy as np
import math

primes_found = []#Always update as sorted

#for a^k: a corresponds to base, k corresponds to power

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


#Taken from: https://github.com/ctfs/write-ups-2015/blob/master/ghost-in-the-shellcode-2015/crypto/nikoli/hilly.py
#-----------------------------------------------------------------------
def modMatInv(A,p):       # Finds the inverse of matrix A mod p
    n = len(A)
    A = np.matrix(A)
    adj = np.zeros(shape = (n, n))
    for i in range(0, n):
        for j in range(0, n):
            adj[i][j] = ((-1)**(i+j)*int(round(np.linalg.det(minor(A, j, i))))) % p
    return (modInv(int(round(np.linalg.det(A))), p)*adj) % p

def modInv(a,p):          # Finds the inverse of a mod p, if it exists
    for i in range(1, p):
        if (i*a) % p == 1: return i
    raise ValueError(str(a)+" has no inverse mod "+str(p))

def minor(A,i,j):    # Return matrix A with the ith row and jth column deleted
    A = np.array(A)
    minor = np.zeros(shape=(len(A)-1, len(A)-1))
    p = 0
    for s in range(0,len(minor)):
        if p == i:
            p = p+1
        q = 0
        for t in range(0,len(minor)):
            if q == j:
                q = q+1
            minor[s][t] = A[p][q]
            q = q+1
    p = p+1
    return minor
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


#Taken from: https://github.com/ThomIves/BasicLinearAlgebraToolsPurePy/blob/master/LinearAlgebraPurePython.py
def zeros_matrix(rows, cols):
    """
    Creates a matrix filled with zeros.
        :param rows: the number of rows the matrix should have
        :param cols: the number of columns the matrix should have
        :return: list of lists that form the matrix
    """
    M = []
    while len(M) < rows:
        M.append([])
        while len(M[-1]) < cols:
            M[-1].append(0.0)

    return M

def copy_matrix(M):
    """
    Creates and returns a copy of a matrix.
        :param M: The matrix to be copied
        :return: A copy of the given matrix
    """
    # Section 1: Get matrix dimensions
    rows = len(M)
    cols = len(M[0])

    # Section 2: Create a new matrix of zeros
    MC = zeros_matrix(rows, cols)

    # Section 3: Copy values of M into the copy
    for i in range(rows):
        for j in range(cols):
            MC[i][j] = M[i][j]

    return MC
#-----------------------------------------------------------------------


#Taken from: https://integratedmlai.com/find-the-determinant-of-a-matrix-with-pure-python-without-numpy-or-scipy/
#-----------------------------------------------------------------------
def determinant_recursive(A, total=0):
    # Section 1: store indices in list for row referencing
    indices = list(range(len(A)))

    # Section 2: when at 2x2 submatrices recursive calls end
    if len(A) == 2 and len(A[0]) == 2:
        val = A[0][0] * A[1][1] - A[1][0] * A[0][1]
        return val

    # Section 3: define submatrix for focus column and
    #      call this function
    for fc in indices:  # A) for each focus column, ...
        # find the submatrix ...
        As = copy_matrix(A)  # B) make a copy, and ...
        As = As[1:]  # ... C) remove the first row
        height = len(As)  # D)

        for i in range(height):
            # E) for each remaining row of submatrix ...
            #     remove the focus column elements
            As[i] = As[i][0:fc] + As[i][fc + 1:]

        sign = (-1) ** (fc % 2)  # F)
        # G) pass submatrix recursively
        sub_det = determinant_recursive(As)
        # H) total all returns from recursion
        total += sign * A[0][fc] * sub_det

    return total
#-----------------------------------------------------------------------


A = []
B = []
smooth_values = []
base = []
power = []
while len(S) != len(smooth_values):
    alpha = random.randint(1, 1000)
    number = pow(g, alpha, m)
    base = []
    power = []
    primeFactors(number, base, power)
    if base == S and number not in smooth_values:
        smooth_values.append(number)
        B.append([alpha])
        A.append(power)
        if len(S) == len(smooth_values) and determinant_recursive(A) != 0:
            break
        elif len(S) == len(smooth_values) and determinant_recursive(A) == 0:
            smooth_values = []
            A = []
            B = []

#STEP 2
B = np.matrix(B)
A_inverse = modMatInv(A, (m - 1))
result = (A_inverse * B) % (m - 1)
print("RESULT: ", result)
numOfRows = result.shape[0]
for i in range(numOfRows):
    hold = int(result.item(i))
    if pow(g, hold, m) != base[i]:
        print("THERE IS A PROBLEM")
#STEP 3
flag = True
alpha = 0
while flag:
    alpha = random.randint(1, 1000)
    number = (y * pow(g, alpha)) % m
    base = []
    power = []
    primeFactors(number, base, power)
    if base == S and number not in smooth_values:
        print("Last alpha: ", alpha)
        flag = False
compute = -alpha
numOfRows = result.shape[0]
for i in range(numOfRows):
    compute += power[i] * int(result.item(i))
compute = compute % (m - 1)
if pow(g, compute, m) == y:
    print("Result is : ", compute)
    print("B: ", B)
    print("A: ", A)
else:
    print("Couldn't find the result")

#EXPERIMENT RESULT 1: BUYUK BASE'LER ICIN SURE UZUYOR(SEBEBI: DAHA FAZLA DENKLEM COZMESI GEREKIYOR)
#EXPERIMENT RESULT 2: HER DENEMEDE SONUCA ULASAMIYOR(BASE ILE ALAKALI BIR DURUM VEYA SAYININ TERSINI BULAMAMASINDAN DOLAYI), ULASTIGINDA DOGRU SONUCU BULUYOR