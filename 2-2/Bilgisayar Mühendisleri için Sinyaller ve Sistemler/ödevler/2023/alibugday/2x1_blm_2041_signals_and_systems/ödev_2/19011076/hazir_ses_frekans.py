import sounddevice as sd
import soundfile as sf
import numpy as np
import matplotlib.pyplot as plt

tel, fs = sf.read("tel.wav",dtype='float32')


t=int(len(tel)/7)



n=t
for i in range(7):
    #input("sonraki plota gecmek icin bir sey giriniz")
    freq=np.fft.fftfreq(n,d=1/fs)
    idx = np.argsort(freq)
    ps = np.abs(np.fft.fft(tel[i*t:i*t+t]))**2
    plt.plot(freq[idx], ps[idx])
    plt.xlabel('frekans düzlemi')
    plt.title("{}'inci tus frekansi".format(i + 1))
    plt.show()


