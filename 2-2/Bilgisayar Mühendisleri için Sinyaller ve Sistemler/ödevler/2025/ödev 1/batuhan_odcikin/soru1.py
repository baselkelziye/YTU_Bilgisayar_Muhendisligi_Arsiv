import matplotlib.pyplot as plt


def myConv(x, n, y, m):
    L = n + m - 1  

    z = [0.0] * L
    a=0
    # z[k] = Σ x[i] * y[k - i]
    for k in range(L):
        toplam = 0.0
        i_min = max(0, k - m + 1)
        i_max = min(k + 1, n)
        
        for i in range(i_min, i_max):
            toplam += x[i] * y[k - i]
        # print(a)
        z[k] = toplam

    k_indis = list(range(L))
    return z, k_indis, L


n = int(input("x[n] dizisi uzunluğu n: "))
x_start = int(input("x[n] dizisi başlangıç indis değeri: "))
x = []
for i in range(n):
    x_val = float(input(f"x[{i}] değerini giriniz: "))
    x.append(x_val)
x_indis = list(range(x_start, x_start + n))

m = int(input("y[m] dizisi uzunluğu m: "))
y_start = int(input("y[m] dizisi başlangıç indis değeri: "))
y = []
for j in range(m):
    y_val = float(input(f"y[{j}] değerini giriniz: "))
    y.append(y_val)
y_indis = list(range(y_start, y_start + m))


z, z_indis, k = myConv(x, n, y, m)


print("\nKonvolüsyon Sonucu (z):", z)
print("Konvolüsyon İndisleri (k):", z_indis)


fig, axs = plt.subplots(3, 1, figsize=(8, 6), sharex=False)

for ax in axs:
    ax.set_xlim(-k * 2, k * 2)

axs[0].stem(x_indis, x, basefmt=" ", linefmt="r-", markerfmt="ro")
axs[0].set_title("x[n]")
axs[0].set_ylabel("Genlik")
axs[0].grid(True)

axs[1].stem(y_indis, y, basefmt=" ", linefmt="b-", markerfmt="bo")
axs[1].set_title("y[n]")
axs[1].set_ylabel("Genlik")
axs[1].grid(True)

axs[2].stem(z_indis, z, basefmt=" ", linefmt="orange", markerfmt="o")
axs[2].set_title("z[n] = x[n] * y[n]")
axs[2].set_xlabel("Zaman (n)")
axs[2].set_ylabel("Genlik")
axs[2].grid(True)

plt.tight_layout()
plt.show()
