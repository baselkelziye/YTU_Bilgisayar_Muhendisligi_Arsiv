import sounddevice as sd
import numpy as np
import scipy.io.wavfile as wav
import matplotlib.pyplot as plt

def system_response(x, M, A=0.5, delay=400):
    y = [0.0] * len(x)
    for i in range(len(x)):
        sum = 0
        for k in range(1, M + 1):
            if i - delay * k >= 0:
                sum += A * x[i - delay * k]
        y[i] = x[i] + sum
    return y


def myConv(x, n, y, m):
    L = n + m - 1

    z = [0.0] * L
    a = 0
    # z[k] = Σ x[i] * y[k - i]
    for k in range(L):
        toplam = 0.0
        i_min = max(0, k - m + 1)
        i_max = min(k + 1, n)
        # a += 1
        for i in range(i_min, i_max):
            toplam += x[i] * y[k - i]
        # print(a)
        z[k] = toplam

    k_indis = list(range(L))
    return z, k_indis, L


# WAV dosyasını kaydet
def save_wav(filename, fs, data):
    data = np.array(data)
    data = np.clip(data, -1.0, 1.0)
    data = (data * 32767).astype(np.int16)
    wav.write(filename, fs, data)


# WAV dosyasını oku ve normalize et
def read_wav(filename):
    fs, data = wav.read(filename)
    if data.dtype == np.int16:
        data = data.astype(np.float32) / 32768.0
    elif data.dtype == np.int32:
        data = data.astype(np.float32) / 2147483648.0
    return fs, data


# ------------------- ANA İŞLEM -------------------

# Ses dosyalarını yükle
fs, x1 = read_wav("kayit_5sec.wav")
_, x2 = read_wav("kayit_10sec.wav")

# Dürtü yanıtları üret
delta = np.zeros(10000)
delta[0] = 1.0

h3 = system_response(delta, M=3)
h4 = system_response(delta, M=4)
h5 = system_response(delta, M=5)

# Konvolüsyon işlemleri
# y1_3 = np.convolve(x1, h3)
# y1_4 = np.convolve(x1, h4)
# y1_5 = np.convolve(x1, h5)

# y2_3 = np.convolve(x2, h3)
# y2_4 = np.convolve(x2, h4)
# y2_5 = np.convolve(x2, h5)

myy1_3, _, _ = myConv(x1, len(x1), h3, len(h3))
save_wav("myy1_3.wav", fs, myy1_3)
myy1_4, _, _ = myConv(x1, len(x1), h4, len(h4))
save_wav("myy1_4.wav", fs, myy1_4)
myy1_5, _, _ = myConv(x1, len(x1), h5, len(h5))
save_wav("myy1_5.wav", fs, myy1_5)

myy2_3, _, _ = myConv(x2, len(x2), h3, len(h3))
save_wav("myy2_3.wav", fs, myy2_3)
myy2_4, _, _ = myConv(x2, len(x2), h4, len(h4))
save_wav("myy2_4.wav", fs, myy2_4)
myy2_5, _, _ = myConv(x2, len(x2), h5, len(h5))
save_wav("myy2_5.wav", fs, myy2_5)

# WAV olarak kaydet
# save_wav("y1_3.wav", fs, y1_3)
# save_wav("y1_4.wav", fs, y1_4)
# save_wav("y1_5.wav", fs, y1_5)

# save_wav("y2_3.wav", fs, y2_3)
# save_wav("y2_4.wav", fs, y2_4)
# save_wav("y2_5.wav", fs, y2_5)


# print("Tüm çıkışlar başarıyla oluşturuldu ve kaydedildi.")

# sd.play(y1_5, samplerate=fs)  # 5 saniyelik kayıt
# sd.wait()  # Çalma işlemi bitene kadar bekle

# plt.plot(range(len(y1_5)), y1_5, color="orange", alpha=0.8)
# # plt.plot(range(len(y1_4)), y1_4, color="red", alpha=0.5)
# # plt.plot(range(len(y1_5)), y1_5, color="green", alpha=0.5)
# plt.show()
# plt.cla()
# plt.plot(range(len(x1)), x1, color="purple", alpha=0.8)
# plt.show()

print("end")
