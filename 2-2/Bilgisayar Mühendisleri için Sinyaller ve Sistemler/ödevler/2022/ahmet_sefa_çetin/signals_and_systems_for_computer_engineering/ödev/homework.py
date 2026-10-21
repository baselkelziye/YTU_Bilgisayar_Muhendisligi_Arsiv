import numpy as np
import matplotlib.pyplot as plt
import sounddevice as sd
import wavio

def myConv(x, y, xStartingIndex, yStartingIndex):
    n = len(x)
    m = len(y)
    result = np.zeros(n + m - 1)

    for i in range(n + m - 1):
        if i >= m - 1:
            start = i - m + 1
        else:
            start = 0
            
        if i < n:
            end = i + 1
        else:
            end = n

        temp = 0
        for j in range(start, end):
            temp += x[j] * y[i - j]
        
        result[i] = temp

    return result, xStartingIndex + yStartingIndex

def convolveAndPlotGraphs(x, y, xStartingIndex, yStartingIndex):
    xIndices = []
    yIndices = []
    resultIndices = []

    for i in range(len(x)):
        xIndices.append(xStartingIndex + i)

    for i in range(len(y)):
        yIndices.append(yStartingIndex + i)
    
    resultMyConv, resultStartingIndex = myConv(x, y, xStartingIndex, yStartingIndex)
    resultConvolve = np.convolve(x, y)

    for i in range(len(resultMyConv)):
        resultIndices.append(resultStartingIndex + i)
    
    plt.figure(figsize=(15, 5))

    plt.subplot(1, 4, 1)
    plt.stem(xIndices, x, '-o')
    plt.title('x[n]')
    plt.xlabel('n')
    plt.ylabel('x[n]')
    plt.grid(True)

    plt.subplot(1, 4, 2)
    plt.stem(yIndices, y, '-o')
    plt.title('y[n]')
    plt.xlabel('n')
    plt.ylabel('y[n]')
    plt.grid(True)

    plt.subplot(1, 4, 3)
    plt.stem(resultIndices, resultMyConv, '-o')
    plt.title('x[n]*y[n] myConv Function')
    plt.xlabel('n')
    plt.ylabel('x[n]*y[n]')
    plt.grid(True)

    plt.subplot(1, 4, 4)
    plt.stem(resultIndices, resultConvolve, '-o')
    plt.title('x[n]*y[n] Built-in Convolve Function')
    plt.xlabel('n')
    plt.ylabel('x[n]*y[n]')
    plt.grid(True)

    plt.tight_layout()

    plt.show()

def convolveAndShowVectors(x, y, xStartingIndex, yStartingIndex):
    resultMyConv, resultStartingIndex = myConv(x, y, xStartingIndex, yStartingIndex)
    resultConvolve = np.convolve(x, y)

    print("x:", x)
    print("y:", y)
    print("x*y My Convolve Function:", resultMyConv)
    print("x*y Built-in Convolve Function:", resultConvolve)

def recordAudio(duration):
    sampleRate = 8000

    recording = sd.rec(int(duration * sampleRate), samplerate=sampleRate, channels=1)
    sd.wait()

    return recording, sampleRate

def playAudio(recording, sampleRate):
    sd.play(recording, samplerate=sampleRate)
    sd.wait()

def impulseResponse(A, M):
    h = np.zeros(3000 * M + 1)
    
    h[0] = 1
    
    for k in range(1, M + 1):
        h[3000 * k] = (A ** (-k)) * k
    
    return h

print("1 - iki farkli senaryo icin konvolusyon islemi yap ve sonrasinda grafiksel ve vektorel goster (degerleri kod uzerinden degistirebilirsiniz)")
print("2 - 5 saniyelik ses kaydet ve dosyaya yaz")
print("3 - 10 saniyelik ses kaydet ve dosyaya yaz")
print("4 - ses dosyasindan ses oku ve sesi seslendir")
print("5 - dosyadan ses oku ve M = 3, 4, 5 degerleri icin h impulse responsunu ile numpy konvolusyon fonksiyonu sonuclarini kaydet")
print("6 - dosyadan ses oku ve M = 3, 4, 5 degerleri icin h impulse responsunu ile myConv  fonksiyonu sonuclarini kaydet")
print("7 - dosyadan ses oku ve M = 3, 4, 5 degerleri icin h impulse responsunu ile numpy konvolusyon fonksiyonu sonuclarinin grafiklerini ciz")

choice = int(input("choice: "))

# iki farkli senaryo icin konvolusyon islemi ve sonrasinda grafiksel ve vektorel gosterim
if choice == 1:
    # senaryo 1
    n1 = 3
    m1 = 3

    xStartingIndex1 = -1
    yStartingIndex1 = 0

    x1 = [1, 2, 3]
    y1 = [1, 2, 3]

    convolveAndPlotGraphs(x1, y1, xStartingIndex1, yStartingIndex1)
    convolveAndShowVectors(x1, y1, xStartingIndex1, yStartingIndex1)

    # senaryo 2
    n2 = 3
    m2 = 3

    xStartingIndex2 = 0
    yStartingIndex2 = -2

    x2 = [3, 1, 5]
    y2 = [2, 3, 4]

    convolveAndPlotGraphs(x2, y2, xStartingIndex2, yStartingIndex2)
    convolveAndShowVectors(x2, y2, xStartingIndex2, yStartingIndex2)
# **************************************************************************************************

# 5 saniyelik ses kaydet
if choice == 2:
    recording5secons, sampleRate = recordAudio(5)
    wavio.write("5secondsAudio.wav", recording5secons, sampleRate, sampwidth=2)
# **************************************************************************************************

# 10 saniyelik ses kaydet
if choice == 3:
    recording10secons, sampleRate = recordAudio(10)
    wavio.write("10secondsAudio.wav", recording10secons, sampleRate, sampwidth=2)
# **************************************************************************************************

# dosyadan ses seslendir
if choice == 4:
    fileName = input("enter file name: ")
    audio = wavio.read(fileName).data
    audio = audio.astype(np.float32) / np.max(np.abs(audio))
    playAudio(audio, 8000)
# **************************************************************************************************

# dosyadan ses oku ve M = 3, 4, 5 degerleri icin h impulse responsunu ile numpy konvolusyon fonksiyonu sonuclarini kaydet
if choice == 5:
    fileName = input("enter file name: ")
    audio = wavio.read(fileName).data
    audio = audio.astype(np.float32) / np.max(np.abs(audio))

    h1 = impulseResponse(2, 3)
    h2 = impulseResponse(2, 4)
    h3 = impulseResponse(2, 5)
    
    convolvedSignal1 = np.convolve(audio.flatten(), h1)
    convolvedSignal2 = np.convolve(audio.flatten(), h2)
    convolvedSignal3 = np.convolve(audio.flatten(), h3)
    
    wavio.write("npConvolvedSignal1.wav", convolvedSignal1, 8000, sampwidth=2)
    wavio.write("npConvolvedSignal2.wav", convolvedSignal2, 8000, sampwidth=2)
    wavio.write("npConvolvedSignal3.wav", convolvedSignal3, 8000, sampwidth=2)

# **************************************************************************************************

# dosyadan ses oku ve M = 3, 4, 5 degerleri icin h impulse responsunu ile myConv  fonksiyonu sonuclarini kaydet
if choice == 6:
    fileName = input("enter file name: ")
    audio = wavio.read(fileName).data
    audio = audio.astype(np.float32) / np.max(np.abs(audio))

    h1 = impulseResponse(2, 3)
    h2 = impulseResponse(2, 4)
    h3 = impulseResponse(2, 5)
    
    convolvedSignal1 = myConv(audio.flatten(), h1, 0, 0)
    convolvedSignal2 = myConv(audio.flatten(), h2, 0, 0)
    convolvedSignal3 = myConv(audio.flatten(), h3, 0, 0)
    
    wavio.write("myConvolvedSignal1.wav", np.array(convolvedSignal1), 8000, sampwidth=2)
    wavio.write("myConvolvedSignal2.wav", np.array(convolvedSignal2), 8000, sampwidth=2)
    wavio.write("myConvolvedSignal3.wav", np.array(convolvedSignal3), 8000, sampwidth=2)

# **************************************************************************************************

# dosyadan ses oku ve M = 3, 4, 5 degerleri icin h impulse responsunu ile numpy ve myConv konvolusyon fonksiyonu sonuclarinin grafiklerini ciz
if choice == 7:
    fileName = input("enter file name: ")
    audio = wavio.read(fileName).data
    audio = audio.astype(np.float32) / np.max(np.abs(audio))

    h1 = impulseResponse(2, 3)
    h2 = impulseResponse(2, 4)
    h3 = impulseResponse(2, 5)
    
    convolveAndPlotGraphs(audio.flatten(), h1, 0, 0)
    convolveAndPlotGraphs(audio.flatten(), h2, 0, 0)
    convolveAndPlotGraphs(audio.flatten(), h3, 0, 0)

# **************************************************************************************************

