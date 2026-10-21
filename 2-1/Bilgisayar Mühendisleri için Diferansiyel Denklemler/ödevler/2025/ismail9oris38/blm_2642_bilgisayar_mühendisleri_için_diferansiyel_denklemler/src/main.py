import numpy as np
import time
from grafik_çizdirme import grafik
from tsne_grafik import Tsne_grafik


y = np.load("Vektör/reranker_etiketleri.npy")  #(100, ) # Hedef etiketler (1.0: Doğru, -1.0: Yanlış). Toplam 100 örnek.
X = np.load("Vektör/train_vektor_intfloat.npy")  #(100, 2048) # Birleştirilmiş girdi gömülmeleri (Sorgu + Cevap). 100 örnek, 2048 boyut.

Y = y.reshape(-1,1)

W = np.random.uniform(low=-0.1, high=0.1, size=(X.shape[1], 1)) #(2048,1)

def gradient_descent(X, Y, W_baslangic, lr = 0.1, epochs = 100):
    W = W_baslangic.copy()
    baslangic_zamani = time.time()
    hata_time = []
    hata_epochs = []
    basari_epochs = []
    basari_time = []
    # W_values = []

    # Bu döngü, tüm veri seti üzerinde 100 kez eğitim yapar.
    for epoch in range(epochs):
        hata = np.mean((np.tanh(X @ W) - Y) ** 2) #(100,2048) * (2048,1) - (100,1)
        hata_epochs.append([epoch, hata])
        gecen_zaman = time.time() - baslangic_zamani
        hata_time.append([gecen_zaman, hata])
        dogru = 0
        for j in range(100):
             if(np.tanh(X @ W)[j][0] * Y[j][0] > 0):
                 dogru += 1
        basari_epochs.append([epoch, dogru/100])
        basari_time.append([time.time() - baslangic_zamani, dogru/100])
        # W_values.append(W.T.copy())

        # İleri Yayılım: Tahmin = tanh(Girdi @ Ağırlıklar)
        tahmin_y = np.tanh(X @ W)  # (100, 1) = (100, 2048) @ (2048, 1)
        # Geri Yayılım: Gradyan Bileşenleri

        d_loss = tahmin_y - Y  # (100, 1) # Hata (Fark)
        d_tanh = 1 - tahmin_y ** 2  # (100, 1) # tanh Aktivasyonunun Türevi
        delta = d_loss * d_tanh  # (100, 1) # Zincir Kuralının İlk Kısmı (Eleman bazlı çarpım)

        # Ağırlık Gradyanı (∂L/∂w): Gradyan = X.T @ Delta (Matris Çarpımı)
        d_W = X.T @ delta #  (2048, 1) = (2048, 100) @ (100, 1)

        # Ağırlık Güncelleme: W = W - (Öğrenme Hızı * Gradyan / Örnek Sayısı)
        W -= (lr * d_W) / len(Y)  # (2048, 1)
    # W_values = np.array(W_values)
    # W_values_reshaped = W_values.reshape(W_values.shape[0], W_values.shape[2])
    # eski = np.load("W_value/W_GD.npy")
    # yeni = np.vstack([eski, W_values_reshaped])
    # np.save("W_value/W_GD.npy", yeni)
    return np.array(hata_epochs), np.array(hata_time), np.array(basari_epochs), np.array(basari_time)

def SGD(X, Y, W_baslangic, lr = 0.1, epochs = 100, batchSize = 10):
    W = W_baslangic.copy()
    baslangic_zamani = time.time()
    hata_time = []
    hata_epochs = []
    basari_epochs = []
    basari_time = []
    # W_values = []

    for epoch in range(epochs):
        # Hata Hesaplama
        hata = np.mean((np.tanh(X @ W) - Y) ** 2)
        hata_epochs.append([epoch, hata])  # Epoch'a göre çizim
        gecen_zaman = time.time() - baslangic_zamani
        hata_time.append([gecen_zaman, hata])
        dogru = 0
        for j in range(100):
             if(np.tanh(X @ W)[j][0] * Y[j][0] > 0):
                 dogru += 1
        basari_epochs.append([epoch, dogru/100])
        basari_time.append([time.time() - baslangic_zamani, dogru/100])
        # W_values.append(W.T.copy())

        index = np.random.permutation(len(X))
        X_shuffled = X[index]
        Y_shuffled = Y[index]

        for i in range(0, len(X), batchSize):
            xBatch = X_shuffled[i:i + batchSize]
            yBatch = Y_shuffled[i:i + batchSize]

            # --- Backward ---
            tahmin = np.tanh(xBatch @ W)
            d_loss = tahmin - yBatch
            d_tanh = 1 - tahmin ** 2
            delta = d_loss * d_tanh

            # Gradyan Hesaplama
            d_W = xBatch.T @ delta
            d_W /= batchSize

            W -= lr * d_W

    # W_values = np.array(W_values)
    # W_values_reshaped = W_values.reshape(W_values.shape[0], W_values.shape[2])
    # eski = np.load("W_value/W_SGD.npy")
    # yeni = np.vstack([eski, W_values_reshaped])
    # np.save("W_value/W_SGD.npy", yeni)
    return np.array(hata_epochs), np.array(hata_time), np.array(basari_epochs), np.array(basari_time)

def AdaGrad(X, Y, W_baslangic, lr = 0.1, epochs = 100, batchSize = 10):
    W = W_baslangic.copy()
    e = 1e-8
    G = np.zeros_like(W)
    baslangic_zamani = time.time()
    hata_time = []
    hata_epochs = []
    basari_epochs = []
    basari_time = []
    # W_values = []

    for epoch in range(epochs):
        # Hata Hesaplama
        hata = np.mean((np.tanh(X @ W) - Y) ** 2)
        hata_epochs.append([epoch, hata])  # Epoch'a göre çizim
        gecen_zaman = time.time() - baslangic_zamani
        hata_time.append([gecen_zaman, hata])
        dogru = 0
        for j in range(100):
             if(np.tanh(X @ W)[j][0] * Y[j][0] > 0):
                 dogru += 1
        basari_epochs.append([epoch, dogru/100])
        basari_time.append([time.time() - baslangic_zamani, dogru/100])
        # W_values.append(W.T.copy())

        index = np.random.permutation(len(X))
        X_shuffled = X[index]
        Y_shuffled = Y[index]

        for i in range(0, len(X), batchSize):
            xBatch = X_shuffled[i:i + batchSize]  #(batchSize, 2048)
            yBatch = Y_shuffled[i:i + batchSize]  #( batchSize, 1)

            # --- Backward ---
            tahmin = np.tanh(xBatch @ W)
            d_loss = tahmin - yBatch
            d_tanh = 1 - tahmin ** 2
            delta = d_loss * d_tanh

            # Gradyan Hesaplama ve KRİTİK BÖLME İŞLEMİ
            d_W = xBatch.T @ delta
            d_W /= batchSize

            G += d_W ** 2

            W -= lr * d_W / (np.sqrt(G) + e)  #(2048, 1)

    # W_values = np.array(W_values)
    # W_values_reshaped = W_values.reshape(W_values.shape[0], W_values.shape[2])
    # eski = np.load("W_value/W_AG.npy")
    # yeni = np.vstack([eski, W_values_reshaped])
    # np.save("W_value/W_AG.npy", yeni)
    return np.array(hata_epochs), np.array(hata_time), np.array(basari_epochs), np.array(basari_time)

def ADAM(X, Y, W_baslangic, lr = 0.01, epochs = 100, batchSize = 10):
    W = W_baslangic.copy()
    B1 = 0.9
    B2 = 0.999
    e = 1e-8
    m = np.zeros_like(W)
    v = np.zeros_like(W)
    baslangic_zamani = time.time()
    hata_time = []
    hata_epochs = []
    basari_epochs = []
    basari_time = []
    # W_values = []

    t = 0  # Genel güncelleme adımı sayacı

    for epoch in range(epochs):
        # Hata Hesaplama
        hata = np.mean((np.tanh(X @ W) - Y) ** 2)
        hata_epochs.append([epoch, hata])
        gecen_zaman = time.time() - baslangic_zamani
        hata_time.append([gecen_zaman, hata])
        dogru = 0
        for j in range(100):
             if(np.tanh(X @ W)[j][0] * Y[j][0] > 0):
                 dogru += 1
        basari_epochs.append([epoch, dogru/100])
        basari_time.append([time.time() - baslangic_zamani, dogru/100])
        # W_values.append(W.T.copy())

        index = np.random.permutation(len(X))
        X_shuffled = X[index]
        Y_shuffled = Y[index]

        for i in range(0, len(X), batchSize):
            t += 1  # Her batch için adımı artır
            xBatch = X_shuffled[i:i + batchSize]
            yBatch = Y_shuffled[i:i + batchSize]

            # --- Backward ---
            tahmin = np.tanh(xBatch @ W)
            d_loss = tahmin - yBatch
            d_tanh = 1 - tahmin ** 2
            delta = d_loss * d_tanh

            d_W = xBatch.T @ delta
            g = d_W / batchSize  # Mini-Batch Gradyan Ortalaması

            # ADAM Güncelleme
            m = B1 * m + (1 - B1) * g
            v = B2 * v + (1 - B2) * (g * g)

            m_hat = m / (1 - B1 ** t)
            v_hat = v / (1 - B2 ** t)

            W -= lr * m_hat / (np.sqrt(v_hat) + e)
    # W_values = np.array(W_values)
    # W_values_reshaped = W_values.reshape(W_values.shape[0], W_values.shape[2])
    # eski = np.load("W_value/W_ADAM.npy")
    # yeni = np.vstack([eski, W_values_reshaped])
    # np.save("W_value/W_ADAM.npy", yeni)
    return np.array(hata_epochs), np.array(hata_time), np.array(basari_epochs), np.array(basari_time)


gradient_descents = []
SGDs = []
AGs = []
ADAMs = []

for i in range(5):

    gradient_descents.append(gradient_descent(X, Y, W))
    SGDs.append(SGD(X, Y, W))
    AGs.append(AdaGrad(X, Y, W))
    ADAMs.append(ADAM(X, Y, W))

    W = np.random.uniform(low=-0.1, high=0.1, size=(X.shape[1], 1))

grafik(gradient_descents, SGDs, AGs, ADAMs)

Tsne_grafik()


