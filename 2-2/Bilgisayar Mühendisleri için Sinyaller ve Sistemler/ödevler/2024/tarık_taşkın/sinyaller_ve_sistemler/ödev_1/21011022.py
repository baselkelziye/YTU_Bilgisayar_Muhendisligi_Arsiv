import numpy as np
import matplotlib.pyplot as plt
import sounddevice as sd

def myConv(x, n, x0, y, m, y0):
    xy0 = x0 + y0
    conv = [0]*(n+m-1)

    for i in range(n):
        for j in range(m):
            conv[i+j] += x[i]*y[j]
            
    return conv, xy0

def plotSignals(x, x0, y, y0, xy_myConv, xy_Conv, xy0):
    nx = np.arange(len(x)) - x0
    ny = np.arange(len(y)) - y0
    nxy = np.arange(len(xy_myConv)) - xy0
    
    plt.stem(nxy, xy_myConv, linefmt="m", markerfmt="D",  label="x*y")
    plt.stem(nx, x, linefmt="b", markerfmt="bo", label="x[n]")
    plt.stem(ny, y, linefmt="r", markerfmt="^", label="y[n]")
    plt.stem(nxy, xy_Conv, linefmt="g", markerfmt="P",  label="x*y (Hazır)")    
    
    plt.xlabel('n')
    plt.ylabel('Değer')
    plt.title('Ayrık Zamanlı Sistemler')
    plt.legend()
    plt.grid()
    plt.show()
    
def convolveSystem():
    frequency = 8100
    duration = 5

    print(f"\n{duration} saniyelik X1 kaydı başladı.")
    x1 = sd.rec(int(frequency * duration), samplerate=frequency, channels=1, dtype='float32')
    sd.wait()
    print(f"{duration} saniyelik X1 kaydedildi.")
    x1 = np.array(x1).flatten().tolist()
    
    print(f"\n{duration*2} saniyelik X2 kaydı başladı.")
    x2 = sd.rec(int(frequency * duration*2), samplerate=frequency, channels=1, dtype='float32')
    sd.wait()
    print(f"{duration*2} saniyelik X2 kaydedildi.")
    x2 = np.array(x2).flatten().tolist()
    
    # X1 için konvolüsyon
    print()
    for M in range(3, 6):
        system = [0]*(M*3000 + 1)
        system[0] = 1
        for k in range(1,M+1):
            system[k*3000] = k*(2 ** -k)
        
        # Kendi yazdığım konvolüsyon fonksiyonu
        conv, _ = myConv(x1, len(x1), 0, system, len(system), 0) # Sesin ve sistemin başlangıç noktası 0'dır.        
        print(f"X1 için sistem konvolüsyonu oynatılıyor. (M={M})")
        sd.play(conv, samplerate=frequency)
        sd.wait()
        print("X1 için sistem konvolüsyonu oynatıldı.")

        # Hazır konvolüsyon fonksiyonu
        conv = np.convolve(x1, system)        
        print(f"X1 için sistem konvolüsyonu oynatılıyor. (M={M}, hazır konvolüsyon fonksiyonu)")
        sd.play(conv, samplerate=frequency)
        sd.wait()
        print("X1 için sistem konvolüsyonu oynatıldı.")
    
    # X2 için konvolüsyon
    print()    
    for M in range(3, 6):
        system = [0]*(M*3000 + 1)
        system[0] = 1
        for k in range(1,M+1):
            system[k*3000] = k*(2 ** -k)
        
        # Kendi yazdığım konvolüsyon fonksiyonu
        conv, _ = myConv(x2, len(x2), 0, system, len(system), 0) # Sesin ve sistemin başlangıç noktası 0'dır.        
        print(f"X2 için sistem konvolüsyonu oynatılıyor. (M={M})")
        sd.play(conv, samplerate=frequency)
        sd.wait()
        print("X2 için sistem konvolüsyonu oynatıldı.")

        # Hazır konvolüsyon fonksiyonu
        conv = np.convolve(x2, system)        
        print(f"X2 için sistem konvolüsyonu oynatılıyor. (M={M}, hazır konvolüsyon fonksiyonu)")
        sd.play(conv, samplerate=frequency)
        sd.wait()
        print("X2 için sistem konvolüsyonu oynatıldı.")
        

if __name__ == "__main__":
    
    while True:
        choice = int(input("\n1- Q1 ve Q2\n2- Q3 ve Q4\n0- Çıkış\nSeçiminiz: "))
        if choice == 1:
            n = int(input("\nx sinyalinin uzunluğu: "))
            x = [0]*(n)
            for i in range(n):
                x[i] = int(input(f"x[{i}]: "))
            x0 = int(input("x sinyalinin sıfır noktası: "))

            m = int(input("\ny sinyalinin uzunluğu: "))
            y = [0]*(m)
            for i in range(m):
                y[i] = int(input(f"y[{i}]: "))
            y0 = int(input("y sinyalinin sıfır noktası: "))

            xy_myConv, xy0 = myConv(x, n, x0, y, m, y0)
            xy_Conv = np.convolve(x, y)
            xy_Conv = xy_Conv.tolist()
            print(f"\nx sinyali  : {x} (n0={x0})\ny sinyali  : {y} (n0={y0})\nx*y        : {xy_myConv} (n0={xy0})\nx*y (Hazır): {xy_Conv} (n0={xy0})")
            plotSignals(x, x0, y, y0, xy_myConv, xy_Conv, xy0)
        elif choice == 2:
            convolveSystem()
        elif choice == 0:
            print("Çıkış yapılıyor...")
            break
        else:
            print("Hatalı seçim yaptınız!") 