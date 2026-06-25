import matplotlib.pyplot as plt
import numpy as np


def myConv(x, n, y, m):
    L = n + m - 1

    z = [0.0] * L

    # z[k] = Σ x[i] * y[k - i]
    for k in range(L):
        toplam = 0.0
        i_min = max(0, k - m + 1)
        i_max = min(k + 1, n)

        for i in range(i_min, i_max):
            toplam += x[i] * y[k - i]
        # print(".")
        z[k] = toplam

    k_indis = list(range(L))
    return z, k_indis, L


def format_vector(vector, start_index):
    result = ""
    for i, val in enumerate(vector):
        index = start_index + i
        val_str = f"{val}"
        if index == 0:
            val_str = f"\033[1;4m{val_str}\033[0m"  # bold + underline
        result += f"{val_str:>6} "
    return result


def plot_conv(x, y, x_start, y_start):

    n = len(x)
    m = len(y)

    x_indis = list(range(x_start, x_start + n))
    y_indis = list(range(y_start, y_start + m))

    # Konvolüsyon hesabı
    z_my, z_indis, k = myConv(x, n, y, m)
    z_np = np.convolve(x, y, mode="full")
    # Ekrana yazdır

    print("x[n]:", format_vector(x, x_start))
    print("y[n]:", format_vector(y, y_start))

    print("\nBenim fonksiyonum:")
    print("Konvolüsyon Sonucu (z):", z_my)
    print("Konvolüsyon İndisleri (k):", z_indis)

    print("\nNumpy fonksiyonu:")
    print("Konvolüsyon Sonucu (z):", z_np)
    print("Konvolüsyon İndisleri (k):", z_indis)

    # Grafik çizimi
    fig, axs = plt.subplots(2, 2, figsize=(8, 6), sharex=False)

    y_min = min(min(x), min(y), min(z_my), min(z_np))
    y_max = max(max(x), max(y), max(z_my), max(z_np))
    padding = (y_max - y_min) * 0.1
    y_min -= padding
    y_max += padding

    x_min = min(min(x_indis), min(y_indis), min(z_indis))
    x_max = max(max(x_indis), max(y_indis), max(z_indis))
    x_padding = (x_max - x_min) * 0.8
    x_min -= x_padding
    x_max += x_padding

    for ax in axs.flat:
        ax.set_ylim(y_min, y_max)
        ax.set_xlim(x_min, x_max)

    axs[0, 0].stem(x_indis, x, basefmt=" ", linefmt="r-", markerfmt="ro")
    axs[0, 0].set_title("x[n]")
    axs[0, 0].set_ylabel("Genlik")
    axs[0, 0].grid(True)

    axs[0, 1].stem(y_indis, y, basefmt=" ", linefmt="b-", markerfmt="bo")
    axs[0, 1].set_title("y[n]")
    axs[0, 1].set_ylabel("Genlik")
    axs[0, 1].grid(True)

    axs[1, 0].stem(z_indis, z_my, basefmt=" ", linefmt="orange", markerfmt="o")
    axs[1, 0].set_title("z[n] = x[n] * y[n] (Batuhan)")
    axs[1, 0].set_xlabel("Zaman (n)")
    axs[1, 0].set_ylabel("Genlik")
    axs[1, 0].grid(True)

    axs[1, 1].stem(z_indis, z_np, basefmt=" ", linefmt="purple", markerfmt="o")
    axs[1, 1].set_title("z[n] = x[n] * y[n] (Numpy)")
    axs[1, 1].set_xlabel("Zaman (n)")
    axs[1, 1].set_ylabel("Genlik")
    axs[1, 1].grid(True)

    plt.tight_layout()
    plt.show()


x1 = [1, -2, 3, 3, -1]
y1 = [5, -3, 1, 0, 6]
x1_start = 0
y1_start = 0

x2 = [1, -2, 3, 3, -1]
y2 = [5, -3, 1, 0, 6]
x2_start = 0
y2_start = 0

plot_conv(x1, y1, x1_start, y1_start)
print("\n\n")
plot_conv(x2, y2, x2_start, y2_start)
