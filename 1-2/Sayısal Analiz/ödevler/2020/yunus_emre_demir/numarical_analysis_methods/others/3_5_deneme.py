from pprint import pprint
from numpy import array, zeros, diag, diagflat, dot, argmax

def jacobi(A,b,N,x,eps):
    # Create a vector of the diagonal elements of A and subtract them from A
    D = diag(A)
    print("\nDiagonel A : ", D)

    R = A - diagflat(D)
    print("\nR = Diagonellerin çıkmış hali \n",R)
    print()

    i=0
    k = 50                          # öylesine eps den yüksel bir sayı işte.
    while i == N or k > eps:
        print("{}. adım {} --> k : {}".format(i,x,k))
        oldx = x.copy()            # burası arıza vermeli normalde ama vermedi:)
        x = (b - dot(R,x)) / D                     # Herşeyi 3 ü için yapıyor. dot(R,x) mesela birinci satırı # x değerleriyle çarp topla, ikinci satırı çarp topla vs.
        k = max(abs((x-oldx)/x))

        i += 1
    print("{}. adım {} --> k : {}".format(i, x, k))
    return x

A = [[3, 1, -2],
     [-1, 4, -3],
     [1, -1, 4]]

b = [9, -8, 1]
startvalue = [1.0, 1.0, 1.0]

def f(A,b):
    D = diag(A)
    R = A - diagflat(D)
    sonuc = 0
    for i in range(len(A)):
        top = 0
        for j in range(len(b)):
            #print("top : ", top , "abs(R[i][j] :", abs(R[i][j] ))
            top = top + abs(R[i][j])
        if abs(D[i]) < top:
            print("|a{}{}|={} < |top|={}".format(i,i,D[i],top))
            print("Yakınsama koşulu sağlanmıyor. Denklemler yer değiştirilip tekrar bakılacak.")

            exit()


f(A,b)
print ("A:", A)
print ("b:", b)

sol = jacobi(A, b, N=100, x=startvalue, eps=0.02)
print ("x:", sol)
