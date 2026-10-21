import numpy as np
import matplotlib.pyplot as plt


x=list()
h=list()
x=[1,2,3]
h=[1,2,3]
axisx=1 #birinci grafigin x=0 noktası
axisy=0 #ikinci grafigin x=0 noktası

def my_conv(x,h,axisx,axisy):
    n= len(x)
    k= len(h)
    l=n+k-1
    y=list()
    y2=list()


    for i in range(l):
        y.append(0)
        y[i]=0
        for j in range(n):
            if (((i-j) >= 0) and ((i-j) < k )):
                y[i]=y[i] + x[j]*h[i-j]

    axisx=axisy-axisx

    return (y,axisx)

if __name__ == "__main__":
    y,axis=my_conv(x,h,axisx,axisy)
    print(x)
    print(h)
    print(y)
    print("grafik x="+str(axis)+" noktasından itibaren baslar")