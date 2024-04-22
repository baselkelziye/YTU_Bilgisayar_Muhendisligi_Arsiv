import sounddevice as sd
from scipy.io.wavfile import write
import numpy as np
import matplotlib.pyplot as plt

def MyCOnv(x: list, lenx, y:list, leny):
    #x(t) fonksiyonu 
    #h(t) fonksiyounu
    #h(t) fonksiyonunun uzunluğu = leny
    result = [0]*(leny+lenx-1)
    j = -1
    for i in x: #x(t) fonksiyonun elemanlarını alıyorum. Formüle baktım
        j = j + 1
        tmp = j
        flag = 0
        while(tmp < (leny + j) ): # result dizisinin içine çarpıp o indexteki değerle topluyorum.
            result[tmp] = result[tmp] + i * y[flag]
            tmp = tmp + 1
            flag = flag + 1
    return result
def start(sx, lenx): # grafikte x düzleminde x noktalarını doğru yazdırmak için dizinin içine atıyorum 
    tmp = sx
    x = []
    for i in range(lenx):
        x.append(tmp)
        tmp = tmp + 1
    return x
def startn(sx, lenx): #fonksiyonun hangi index 0 noktasına gelecek onu tespit ediyorum.
    tmp = sx
    n = sx
    for i in range(lenx):
        if( (tmp + i) == 0 ):
            n = i
    return n
            
def main():
    x = []
    y = []
    lenx = int(input("x dizisinin uzunlugu: "))
    sx = int(input("x dizisinin eksi sonsuzdan (x ekseni düzleminde) gelirken 0'dan farklı değer geleceği x noktasını giriniz. "))
    leny = int(input("y dizisinin uzunluğu: "))
    sy = int(input("y dizisinin (x ekseni düzleminde) eksi sonsuzdan gelirken 0'dan farklı değer geleceği y noktasını giriniz.  "))
    dizinx = []
    diziny = []
    diziresult = []
    for i in range(lenx): # x ve y fonskiyonlarının değerlerini alıyorum
        temp = float(input("X[{0}] degeri: ".format(i)))
        x.append(temp)
    for i in range(leny):
        temp = float(input("Y[{0}] degeri: ".format(i)))
        y.append(temp)
    result = MyCOnv(x, lenx, y, leny)
    
    dizinx = start(sx, lenx) #fonksiyonun grafiği için x noktalarını belirledim. Mesela sx = -1 ise dizinx = -1, 0 1 gibi
    print(dizinx)
    nx = startn(sx, lenx)  #fonksiyonun hangi index 0 noktasına gelecek onu tespit ediyorum. Mesela 
    diziny = start(sy, leny) #fonksiyonun grafiği için x noktalarını belirledim
    print(diziny)
    ny = startn(sy, leny) #fonksiyonun hangi index 0 noktasına gelecek onu tespit ediyorum.
    sr = sy + sx #konvule edecegim fonksiyonun hangi degerden itibaren 0'dan farklı sayı gelecek onu hesaplıyorum
    n = startn(sr, len(result)) #fonksiyonun hangi index 0 noktasına gelecek onu tespit ediyorum.
    diziresult = start(sr, len(result)) #fonksiyonun grafiği için x noktalarını belirledim
    print("x dizisi: ", x)
    print("x: n = 0 noktasindaki index degeri: ", nx)
    print("y dizisi: ", y)
    print("y: n = 0 noktasindaki index degeri: ", ny)
    print("result dizisi: ", result)
    print("result: n = 0 noktasindaki index degeri: ", n)
    result2 = np.convolve(x, y)
    print("hazir fonksiyon result: ", result2)
    #x grafiği
    t = dizinx
    a = x
    plt.subplot(1, 4, 1)
    plt.stem(t, a, 'b')
    plt.xlabel("zaman")
    plt.ylabel("value")
    plt.title("x[n] fonksiyonu")
    #y grafiği
    t = diziny #
    a = y
    plt.subplot(1, 4, 2)
    plt.stem(t, a, 'r')
    plt.xlabel("zaman")
    plt.ylabel("value")
    plt.title("y[n] fonksiyonu")
    #sonucun grafiği
    t = diziresult
    a = result
    plt.subplot(1, 4, 3)
    plt.stem(t, a, 'c')
    plt.xlabel("zaman")
    plt.ylabel("value")
    plt.title("konvülasyon[n] fonksiyonu")
    #hazir fonksiyon kullanıldı
    t = diziresult
    a = result2
    plt.subplot(1, 4, 4)
    plt.stem(t, a, 'k')
    plt.xlabel("zaman")
    plt.ylabel("value")
    plt.title("hazır konvülasyon[n] fonksiyonu")
    plt.show()

    #5 saniyelik ses kaydı 
    fs = 10000  # Saniye başına örnekleme 
    sd.default.samplerate= fs
    seconds = 5
    print("5 saniyelik ses kaydı başladı\n")
    myrecording = sd.rec(int(seconds * fs), samplerate=fs, channels=2) #kaydediyor
    sd.wait()
    print("kayit bitti")
    write('output12.wav', fs, myrecording)  # WAV dosyası şeklinde kaydediyor
    result = np.array(myrecording).flatten() #Sesi matrix şeklinde depoladığı için dizi haline dönüştürmemiz gerek.
    devam  = 1
    while(devam): #hazır konvolüsyon kullandım
        M = int(input("-Hazır konvolüsyon fonksiyonu-Formüldeki M sayisini giriniz: ")) 
        A = 0.8     
        h  = [0]* M * 400 #y[n] fonksiyonunu M değerine bağlı olarak bir dizi oluşturuyorum.
        h.append(0) #0 eklemem gerekiyordu çünkü 400. noktada dürtümün olmasını istiyorsam 401 boyutluk dizi oluşturmam gerek
        h[0] = 1
        for i in range(M):
            h[(i + 1) * 400] = A * (i + 1)        
        convolved = np.convolve(result,h)
        sd.play(convolved, blocking = True)
        devam = int(input("İşleme devam etmek istiyorsanız 1'e basınız."))
        if(devam != 1):
            devam = 0
    fs = 10000  # Saniye başına örnekleme 
    sd.default.samplerate= fs
    seconds = 5
    print("5 saniyelik ses kaydı başladı\n")
    myrecording = sd.rec(int(seconds * fs), samplerate=fs, channels=2) #kaydediyor
    sd.wait()
    print("kayit bitti")
    write('output12.wav', fs, myrecording)  # WAV dosyası şeklinde kaydediyor
    result = np.array(myrecording).flatten() #Sesi matrix şeklinde depoladığı için dizi haline dönüştürmemiz gerek.
    devam = 1
    while(devam): #benim konvolüsyon fonksiyonum kullandım
        M = int(input("-Benim konvolüsyon fonksiyonum-Formüldeki M sayisini giriniz: ")) 
        A = 0.8     
        h  = [0]* M * 400 #y[n] fonksiyonunu M değerine bağlı olarak bir dizi oluşturuyorum.
        h.append(0) #0 eklemem gerekiyordu çünkü 400. noktada dürtümün olmasını istiyorsam 401 boyutluk dizi oluşturmam gerek
        h[0] = 1
        for i in range(M):
            h[(i + 1) * 400] = A * (i + 1)     
        resultlen =  len(result)  
        lenh = len(h)
        convolved = MyCOnv(result,resultlen , h,lenh )
        sd.play(convolved, blocking = True)
        devam = int(input("İşleme devam etmek istiyorsanız 1'e basınız."))
        if(devam != 1):
            devam = 0

    #10 saniyelik ses kaydı
    fs = 10000  # Saniye başına örnekleme 
    sd.default.samplerate= fs
    seconds = 10
    print("10 saniyelik ses kaydı başladı\n")
    myrecording = sd.rec(int(seconds * fs), samplerate=fs, channels=2) #kaydediyor
    sd.wait()
    print("kayit bitti")
    write('output123.wav', fs, myrecording)  # WAV dosyası şeklinde kaydediyor
    result = np.array(myrecording).flatten() #Sesi matrix şeklinde depoladığı için dizi haline dönüştürmemiz gerek.
    devam  = 1
    while(devam): #hazır konvolüsyon kullandım
        M = int(input("-Hazır konvolüsyon fonksiyonu-Formüldeki M sayisini giriniz: ")) 
        A = 0.8     
        h  = [0]* M * 400 #y[n] fonksiyonunu M değerine bağlı olarak bir dizi oluşturuyorum.
        h.append(0) #0 eklemem gerekiyordu çünkü 400. noktada dürtümün olmasını istiyorsam 401 boyutluk dizi oluşturmam gerek
        h[0] = 1
        for i in range(M):
            h[(i + 1) * 400] = A * (i + 1)        
        convolved = np.convolve(result,h)
        sd.play(convolved, blocking = True)
        devam = int(input("İşleme devam etmek istiyorsanız 1'e basınız."))
        if(devam != 1):
            devam = 0
    fs = 10000  # Saniye başına örnekleme 
    sd.default.samplerate= fs
    seconds = 5
    print("10 saniyelik ses kaydı başladı\n")
    myrecording = sd.rec(int(seconds * fs), samplerate=fs, channels=2) #kaydediyor
    sd.wait()
    print("kayit bitti")
    write('output12.wav', fs, myrecording)  # WAV dosyası şeklinde kaydediyor
    result = np.array(myrecording).flatten() #Sesi matrix şeklinde depoladığı için dizi haline dönüştürmemiz gerek.
    devam = 1
    while(devam): #benim konvolüsyon fonksiyonumu kullandım
        M = int(input("-Benim konvolüsyon fonksiyonum-Formüldeki M sayisini giriniz: ")) 
        A = 0.8     
        h  = [0]* M * 400 #y[n] fonksiyonunu M değerine bağlı olarak bir dizi oluşturuyorum.
        h.append(0) #0 eklemem gerekiyordu. Misal 400. noktada dürtümün olmasını istiyorsam 401 boyutluk dizi oluşturmam gerek
        h[0] = 1
        for i in range(M):
            h[(i + 1) * 400] = A * (i + 1)  
        resultlen =  len(result)  
        lenh = len(h)      
        convolved = MyCOnv(result, resultlen, h, lenh)
        sd.play(convolved, blocking = True)
        devam = int(input("İşleme devam etmek istiyorsanız 1'e basınız."))
        if(devam != 1):
            devam = 0

if __name__ == "__main__":
    main()