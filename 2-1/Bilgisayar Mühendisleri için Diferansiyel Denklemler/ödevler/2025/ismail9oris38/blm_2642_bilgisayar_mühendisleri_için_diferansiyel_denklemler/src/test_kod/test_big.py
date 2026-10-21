import numpy as np
import time
from grafik_çizdirme import grafik

W_GD = np.load("W_GD_big.npy") #(500, 2048)
W_SGD = np.load("W_SGD_big.npy")
W_ADAM = np.load("W_ADAM_big.npy")

y = np.load("reranker_etiketleri.npy")  #(100, 1) # Hedef etiketler (1.0: Doğru, -1.0: Yanlış). Toplam 100 örnek.
X = np.load("test_vektor.npy")  #(100, 2048) # Birleştirilmiş girdi gömülmeleri (Sorgu + Cevap). 100 örnek, 2048 boyut.

Y = y.reshape(100,1)

def gradient_descent(X, Y, W_GD, W_index, epochs = 100) :
    W = W_GD[W_index * 100: W_index * 100 + 100]
    baslangic_zamani = time.time()
    hata_time = []
    hata_epochs = []
    basari_epochs = []
    basari_time = []

    for epoch in range(epochs):
        W_new = W[epoch].reshape(-1, 1)
        hata = np.mean((np.tanh(X @ W_new) - Y) ** 2) #(100,2048) * (2048,1) - (100,1)
        hata_epochs.append([epoch, hata])
        gecen_zaman = time.time() - baslangic_zamani
        hata_time.append([gecen_zaman, hata])
        dogru = 0
        for j in range(100):
             if(np.tanh(X @ W_new)[j][0] * Y[j][0] > 0):
                 dogru += 1
        basari_epochs.append([epoch, dogru/100])
        basari_time.append([time.time() - baslangic_zamani, dogru/100])

    return np.array(hata_epochs), np.array(hata_time), np.array(basari_epochs), np.array(basari_time)

def SGD(X, Y, W_SGD, W_index, epochs = 100):
    W = W_SGD[W_index * 100: W_index * 100 + 100]
    baslangic_zamani = time.time()
    hata_time = []
    hata_epochs = []
    basari_epochs = []
    basari_time = []

    for epoch in range(epochs):
        W_new = W[epoch].reshape(-1, 1)
        hata = np.mean((np.tanh(X @ W_new) - Y) ** 2)  # (100,2048) * (2048,1) - (100,1)
        hata_epochs.append([epoch, hata])
        gecen_zaman = time.time() - baslangic_zamani
        hata_time.append([gecen_zaman, hata])
        dogru = 0
        for j in range(100):
            if (np.tanh(X @ W_new)[j][0] * Y[j][0] > 0):
                dogru += 1
        basari_epochs.append([epoch, dogru / 100])
        basari_time.append([time.time() - baslangic_zamani, dogru / 100])

    return np.array(hata_epochs), np.array(hata_time), np.array(basari_epochs), np.array(basari_time)

def ADAM(X, Y, W_ADAM, W_index, epochs = 100):
    W = W_ADAM[W_index * 100: W_index * 100 + 100]
    baslangic_zamani = time.time()
    hata_time = []
    hata_epochs = []
    basari_epochs = []
    basari_time = []

    for epoch in range(epochs):
        W_new = W[epoch].reshape(-1, 1)
        hata = np.mean((np.tanh(X @ W_new) - Y) ** 2)  # (100,2048) * (2048,1) - (100,1)
        hata_epochs.append([epoch, hata])
        gecen_zaman = time.time() - baslangic_zamani
        hata_time.append([gecen_zaman, hata])
        dogru = 0
        for j in range(100):
            if (np.tanh(X @ W_new)[j][0] * Y[j][0] > 0):
                dogru += 1
        basari_epochs.append([epoch, dogru / 100])
        basari_time.append([time.time() - baslangic_zamani, dogru / 100])

    return np.array(hata_epochs), np.array(hata_time), np.array(basari_epochs), np.array(basari_time)



gradient_descents = []
SGDs = []
ADAMs = []

for i in range(5):
    gradient_descents.append(gradient_descent(X, Y, W_GD, i))
    SGDs.append(SGD(X, Y, W_SGD, i))
    ADAMs.append(ADAM(X, Y, W_ADAM, i))

grafik(gradient_descents, SGDs, ADAMs)
