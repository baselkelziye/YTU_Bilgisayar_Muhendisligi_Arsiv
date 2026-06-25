import scipy.io.wavfile as wav
import sounddevice as sd
import numpy as np

fs = 16000  

# 5 saniyelik kayıt
print("5 saniyelik kayıt başlıyor...")
x1 = sd.rec(int(5 * fs), samplerate=fs, channels=1, dtype='float32')
sd.wait()
print("5 saniyelik kayıt tamamlandı.")

print(x1)
# 10 saniyelik kayıt
print("10 saniyelik kayıt başlıyor...")
x2 = sd.rec(int(10 * fs), samplerate=fs, channels=1, dtype='float32')
sd.wait()
print("10 saniyelik kayıt tamamlandı.")

sd.play(x1, samplerate=fs)  # 5 saniyelik kayıt
sd.wait()  # Çalma işlemi bitene kadar bekle

sd.play(x2, samplerate=fs)  # 5 saniyelik kayıt
sd.wait()  # Çalma işlemi bitene kadar bekle


wav.write("kayit_5sec.wav", fs, x1)
wav.write("kayit_10sec.wav", fs, x2)


