import sounddevice as sd
import soundfile as sf
import numpy as np
import matplotlib.pyplot as plt

tel, fs = sf.read("myvoice.wav",dtype='float32')
sd.play(tel, fs)

t=int(len(tel)/11)

# X = np.fft.fft(tel[2*t:3*t])
# plt.plot(X)
# plt.show()

n=t
for i in range(11):
    #input("sonraki plota gecmek icin bir sey giriniz")
    freq=np.fft.fftfreq(n,d=1/fs)
    idx = np.argsort(freq)
    ps = np.abs(np.fft.fft(tel[i*t:i*t+t]))**2
    plt.plot(freq[idx], ps[idx])
    plt.xlabel('frekans düzlemi')
    plt.title("{}'inci tus frekansi".format(i+1))
    plt.show()




# freq=freq[idx]
# freq1=freq[512:518]
# freq2=freq[0:516]
# xmax1 = freq1[np.argmax(ps[idx])]
# #xmax2 = freq2[np.argmax(ps[idx])]
# print(xmax1)
# #print(xmax2)
