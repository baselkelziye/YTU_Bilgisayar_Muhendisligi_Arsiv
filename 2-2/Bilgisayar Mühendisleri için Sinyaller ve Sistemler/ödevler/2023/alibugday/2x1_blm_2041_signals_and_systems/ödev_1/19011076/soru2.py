import numpy as np
import matplotlib.pyplot as plt
from soru_1 import my_conv

x=list()
h=list()
x=[1,2,3]
h=[1,2,3]
axisx=1 #birinci grafigin x=0 noktası ikinci eleman
axisy=0 #ikinci grafigin x=0 noktası ilk eleman


def myconv_vs_hazir(x,h,axisx,axisy):
    y1,axis1=my_conv(x,h,axisx,axisy)#myconv sor_1'den import ettim
    y2=np.convolve(x,h)#hazir_fonksiyon

    print("vektorel karsılaştırma:")
    print(y1)
    print(y2)

    plt.subplot(2, 1, 1)
    x_values = np.linspace(axis1, axis1 + len(y1)-1, len(y1))
    plt.stem(x_values, y1)#myconv
    plt.xlabel('t')
    plt.ylabel('Amplitude');
    plt.title("myconv grafigi");
    # plt.xlim([-10, 10])
    plt.subplot(2, 1, 2)
    plt.stem(x_values, y2)#hazir_fonk
    plt.xlabel('t');
    plt.ylabel('Amplitude');
    plt.title("hazir fonk grafigi");
    # plt.xlim([-10, 10])
    plt.subplots_adjust(top=0.95,
                        bottom=0.09,
                        left=0.1,
                        right=0.895,
                        hspace=0.42,
                        wspace=0.4)
    plt.show()
if __name__ == "__main__":
    print(x)
    print(h)
    myconv_vs_hazir(x,h,axisx,axisy)