import matplotlib.pyplot as plt
import numpy as np
import sounddevice as sd


# Kullanicidan alinan x ve y dizileri ve bu dizilerin 0 noktalarinin hangi indiste oldugunu belirten x_zero ve y_zero
# degerleri alinir.
def myConv(x, x_zero, y, y_zero):

    # kisa olan diziyi kaydirmak daha kolay oldugu icin kisa olan y dizisine atanir
    if len(y) > len(x):
        x, y = y, x
        x_zero, y_zero = y_zero, x_zero

    # fonksiyon zaman ekseninde terslenir
    y = y[::-1]

    y_zero = len(y) - y_zero - 1
    # sonucun sıfır noktasi nerede hesaplanir
    result_zero = 0

    result_length = len(x) + len(y) - 1
    result = [0] * result_length
    # konvolusyon islemi yapilir
    for shift in range(-len(y) + 1, len(x)):
        for i in range(len(y)):
            if 0 <= shift + i < len(x):
                result[shift + len(y) - 1] += x[shift + i] * y[i]
            if shift + i == x_zero and i == y_zero:
                result_zero = shift + len(y) - 1
    # sonuc olarak sonuc dizisi ve sifir degerinin oldugu indis geri dondurulur
    return result, result_zero


# istenilen uzunlukta dizi girilerek girdilerin alindigi fonksiyon
def get_input_normal():
    n = int(input("x dizisinin eleman sayısını girin (n): "))
    x = list(
        map(
            int,
            input(f"{n} elemanlı x dizisini girin (örnek: 1 2 3 ... {n}): ").split(),
        )
    )
    if len(x) != n:
        print("Girilen eleman sayısı n ile uyuşmuyor, program yeniden başlatılıyor.")
        return get_input_normal()

    m = int(input("y dizisinin eleman sayısını girin (m): "))
    y = list(
        map(
            int,
            input(f"{m} elemanlı y dizisini girin (örnek: 1 2 3 ... {m}): ").split(),
        )
    )
    if len(y) != m:
        print("Girilen eleman sayısı m ile uyuşmuyor, program yeniden başlatılıyor.")
        return get_input_normal()

    x_zero = int(input("x_zero: "))
    y_zero = int(input("y_zero: "))
    return x, x_zero, y, y_zero


# ikinci soruda en fazla 5 ornek dendigi icin input sayisini kisitlayan fonksiyon
def get_input_maks5():
    while True:
        x = list(map(int, input("İlk diziyi girin (örn: 1 2 3): ").split()))
        max_len_y = 5 - len(x)
        if max_len_y <= 0:
            print(
                "İlk dizi zaten 5 veya daha fazla eleman içeriyor, lütfen daha kısa bir dizi girin."
            )
            continue
        y = list(
            map(
                int,
                input(f"İkinci diziyi girin (maksimum {max_len_y} eleman): ").split(),
            )
        )
        if len(y) > max_len_y:
            print(
                f"İkinci dizi çok uzun, lütfen en fazla {max_len_y} elemanlı bir dizi girin."
            )
            continue
        break
    x_zero = int(input("x_zero: "))
    y_zero = int(input("y_zero: "))
    return x, x_zero, y, y_zero


# ikinci sorunun b sikkinda belirtilen ekrana basma seklinde karsilastirma fonksiyonu
def compareVector(x, y, result, sonuc):
    print("------------------")
    print("X-->", x)
    print("Y-->", y)
    print("MyConv Sonuc: ", result)
    print("Hazır Konvolusyon Sonuc", sonuc)


# grafikler yazdirilirken paramtreleri kolay ayarlamak icin olusturulmus fonksiyon
def setup_graph(ax, indices, values, title, xlabel, ylabel, color, marker):
    mask = values != 0
    ax.stem(
        indices,
        values,
        color,
        markerfmt=marker,
        basefmt=" ",
        label=title,
    )
    ax.set_title(title)
    ax.set_xlabel(xlabel)
    ax.set_ylabel(ylabel)
    ax.legend()
    ax.grid(True)
    unique_values = np.unique(values[values != 0])
    ax.set_yticks(unique_values)


# sonuclari grafikte karsilastiran fonksiyon
def compareGrafik(result, result_zero, sonuc, x, x_zero, y, y_zero):
    # burada sifir noktalarina gore zaman ekseninde ayarlama yapiliyor
    x_indices = np.arange(len(x)) - x_zero
    y_indices = np.arange(len(y)) - y_zero
    my_conv_indices = np.arange(len(result)) - result_zero
    numpy_conv_indices = np.arange(len(sonuc)) - result_zero

    fig, axs = plt.subplots(
        4, 1, figsize=(10, 20)
    )  # 4 rows, 1 column, figsize düzenlendi

    # X[n] grafiği
    setup_graph(
        axs[0],
        x_indices,
        x,
        "Input Signal X[n]",
        "Time Index (n)",
        "Amplitude",
        "r",
        "ro",
    )

    # Y[m] grafiği
    setup_graph(
        axs[1],
        y_indices,
        y,
        "Input Signal Y[m]",
        "Time Index (n)",
        "Amplitude",
        "g",
        "go",
    )

    # Kendi Konvolüsyon Sonucu grafiği
    setup_graph(
        axs[2],
        my_conv_indices,
        result,
        "MyConv Result",
        "Time Index (n)",
        "Amplitude",
        "b",
        "bo",
    )

    # Numpy Konvolüsyon Sonucu grafiği
    setup_graph(
        axs[3],
        numpy_conv_indices,
        sonuc,
        "Numpy Conv Result",
        "Time Index (n)",
        "Amplitude",
        "m",
        "mo",
    )

    plt.subplots_adjust(hspace=0.4)
    plt.show()


# Birinci soru icin sadece konvolusyon hesaplanan kısım
x, x_zero, y, y_zero = get_input_normal()

result = myConv(x, x_zero, y, y_zero)
print(result[0])

# ikinci soruda en fazla 5 ornek ile yapilan hesap ve karsilastirma fonksiyonlari
# x, x_zero, y, y_zero = get_input_maks5()

# result = myConv(x, x_zero, y, y_zero)
# result_arr = result[0]
# result_zero = result[1]

# x = np.array(x)
# y = np.array(y)
# sonuc = np.convolve(x, y, mode="full")


# compareVector(x, y, result_arr, sonuc)
# compareGrafik(result_arr, result_zero, sonuc, x, x_zero, y, y_zero)


# 3. soruda istenen ses kaydetme fonksiyonu
def record_audio(fs, duration):
    print("Kayıt başlıyor...")
    recording = sd.rec(int(duration * fs), samplerate=fs, channels=1, dtype="float64")
    sd.wait()
    print("Kayıt bitti.")
    return recording


# 4. soru
# fs = 8000  # Örnekleme frekansı (Hz)
# # M degerleri icin dongu
# for M in range(3, 6):
#     size = M * 3000 + 1
#     x = np.zeros(size)
#     x[0] = 1
#     # h[n] impulse response u bulmak icin dongu
#     for i in range(1, M + 1):
#         x[i * 3000] = (2**-i) * i

#     # 5 ve 10 saniyelik ses kayitlari
#     recording_5_saniye = record_audio(fs, duration=5)
#     recording_10_saniye = record_audio(fs, duration=10)

#     # Kaydedilen sesi numpy dizisine dönüştür
#     audio_array_5_saniye = np.array(recording_5_saniye)
#     audio_array_10_saniye = np.array(recording_10_saniye)

#     sonuc_ses_5_saniye_kendi = myConv(audio_array_5_saniye, 0, x, 0)[0]
#     sonuc_ses_10_saniye_kendi = myConv(audio_array_10_saniye, 0, x, 0)[0]
#     sonuc_ses_5_saniye_hazir = np.convolve(x, audio_array_5_saniye, mode="full")
#     sonuc_ses_10_saniye_hazir = np.convolve(x, audio_array_10_saniye, mode="full")

#     sesler = []
#     sesler.append(sonuc_ses_5_saniye_kendi)
#     sesler.append(sonuc_ses_10_saniye_kendi)
#     sesler.append(sonuc_ses_5_saniye_hazir)
#     sesler.append(sonuc_ses_10_saniye_hazir)
#     for i in range(4):
#         print("Ses oynatılıyor... ses 5 saniye")
#         sd.play(sesler[i], fs)
#         sd.wait()
#         print("Oynatma bitti.")
