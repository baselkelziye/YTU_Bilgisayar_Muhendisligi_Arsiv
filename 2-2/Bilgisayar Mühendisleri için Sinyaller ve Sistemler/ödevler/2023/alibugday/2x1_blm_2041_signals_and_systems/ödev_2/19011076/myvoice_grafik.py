import sounddevice as sd
import soundfile as sf
import numpy as np
import matplotlib.pyplot as plt


tel, fs = sf.read("myvoice.wav",dtype='float32')
sd.play(tel, fs)


plt.subplot(2, 1, 1)
x_values = np.linspace(0,len(tel), len(tel))
plt.plot(x_values, tel)
plt.xlabel('zaman ekseni')
plt.title("plot grafigi")
plt.subplot(2, 1, 2)
plt.stem(x_values, tel)
plt.xlabel('zaman ekseni')
plt.title("stem grafigi")
plt.subplots_adjust(top=0.95,
                    bottom=0.09,
                    left=0.1,
                    right=0.895,
                    hspace=0.42,
                    wspace=0.4)
plt.show()

