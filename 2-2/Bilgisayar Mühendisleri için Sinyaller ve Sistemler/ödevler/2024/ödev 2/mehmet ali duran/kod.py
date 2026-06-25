import tkinter as tk
from tkinter import ttk
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.figure import Figure
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg

# Ana formu oluştur
form = tk.Tk()
form.geometry("1300x750")
form.title("Plot Sine and Cosine Functions and Fourier Series")

# Grafikler için çerçeve
graphics_frame = tk.Frame(form, width=1000, height=800)
graphics_frame.grid(row=0, column=0, rowspan=5, padx=10, pady=10, sticky="nsew")

# 1. Sinyal çerçevesi
signal1 = tk.LabelFrame(
    form, width=400, height=150, bg="#d3d3d3", text="1. Sinyalin Değerleri"
)
signal1.grid(row=0, column=1, padx=10, pady=5)

# 2. Sinyal çerçevesi
signal2 = tk.LabelFrame(
    form, width=400, height=150, bg="#d3d3d3", text="2. Sinyalin Değerleri"
)
signal2.grid(row=1, column=1, padx=10, pady=5, sticky="n")

# 3. Sinyal çerçevesi
signal3 = tk.LabelFrame(
    form, width=400, height=150, bg="#d3d3d3", text="3. Sinyalin Değerleri"
)
signal3.grid(row=2, column=1, padx=10, pady=5, sticky="n")

# Toplam sinyal çerçevesi
signal_sum = tk.LabelFrame(
    form, width=400, height=150, bg="#d3d3d3", text="Toplam Sinyal Değerleri"
)
signal_sum.grid(row=3, column=1, padx=10, pady=5, sticky="n")

# 1. Sinyal için değerler
signal1LabelA = tk.Label(signal1, text="Genlik: ")
signal1LabelA.grid(row=0, column=0, padx=5, pady=10, sticky="n")

A1 = tk.Entry(signal1, width=10)
A1.grid(row=0, column=1, padx=5, pady=10)
A1.insert(0, "0")  # Başlangıç değeri olarak sıfır ekle

signal1Labelf = tk.Label(signal1, text="Frekans: ")
signal1Labelf.grid(row=1, column=0, padx=5, pady=10, sticky="n")

f1 = tk.Entry(signal1, width=10)
f1.grid(row=1, column=1, padx=5, pady=10)
f1.insert(0, "0")  # Başlangıç değeri olarak sıfır ekle

signal1Labelt = tk.Label(signal1, text="Faz: ")
signal1Labelt.grid(row=2, column=0, padx=5, pady=10, sticky="n")

theta1 = tk.Entry(signal1, width=10)
theta1.grid(row=2, column=1, padx=5, pady=10)
theta1.insert(0, "0")  # Başlangıç değeri olarak sıfır ekle

# 2. Sinyal için değerler
signal2LabelA = tk.Label(signal2, text="Genlik: ")
signal2LabelA.grid(row=0, column=0, padx=5, pady=10, sticky="n")

A2 = tk.Entry(signal2, width=10)
A2.grid(row=0, column=1, padx=5, pady=10)
A2.insert(0, "0")  # Başlangıç değeri olarak sıfır ekle

signal2Labelf = tk.Label(signal2, text="Frekans: ")
signal2Labelf.grid(row=1, column=0, padx=5, pady=10, sticky="n")

f2 = tk.Entry(signal2, width=10)
f2.grid(row=1, column=1, padx=5, pady=10)
f2.insert(0, "0")  # Başlangıç değeri olarak sıfır ekle

signal2Labelt = tk.Label(signal2, text="Faz: ")
signal2Labelt.grid(row=2, column=0, padx=5, pady=10, sticky="n")

theta2 = tk.Entry(signal2, width=10)
theta2.grid(row=2, column=1, padx=5, pady=10)
theta2.insert(0, "0")  # Başlangıç değeri olarak sıfır ekle

# 3. Sinyal için değerler
signal3LabelA = tk.Label(signal3, text="Genlik: ")
signal3LabelA.grid(row=0, column=0, padx=5, pady=10, sticky="n")

A3 = tk.Entry(signal3, width=10)
A3.grid(row=0, column=1, padx=5, pady=10)
A3.insert(0, "0")  # Başlangıç değeri olarak sıfır ekle

signal3Labelf = tk.Label(signal3, text="Frekans: ")
signal3Labelf.grid(row=1, column=0, padx=5, pady=10, sticky="n")

f3 = tk.Entry(signal3, width=10)
f3.grid(row=1, column=1, padx=5, pady=10)
f3.insert(0, "0")  # Başlangıç değeri olarak sıfır ekle

signal3Labelt = tk.Label(signal3, text="Faz: ")
signal3Labelt.grid(row=2, column=0, padx=5, pady=10, sticky="n")

theta3 = tk.Entry(signal3, width=10)
theta3.grid(row=2, column=1, padx=5, pady=10)
theta3.insert(0, "0")  # Başlangıç değeri olarak sıfır ekle

# a0 değişkenini global olarak tanımlayın
a0label = tk.Label(signal_sum, text="DC Bileşen (a0): ")
a0label.grid(row=3, column=0, padx=5, pady=10, sticky="n")

a0 = tk.Entry(signal_sum, width=10)
a0.grid(row=3, column=1, padx=5, pady=10)
a0.insert(0, "0")  # Başlangıç değeri olarak sıfır ekle

# Toplam sinyal için özellikler
signalSumLabelA = tk.Label(signal_sum, text="Genlik: ")
signalSumLabelA.grid(row=0, column=0, padx=5, pady=10, sticky="n")

sumA = tk.Label(signal_sum, text="0")
sumA.grid(row=0, column=1, padx=5, pady=10, sticky="w")

signalSumLabelf = tk.Label(signal_sum, text="Frekans: ")
signalSumLabelf.grid(row=1, column=0, padx=5, pady=10, sticky="n")

sumf = tk.Label(signal_sum, text="0")
sumf.grid(row=1, column=1, padx=5, pady=10, sticky="w")

signalSumLabelt = tk.Label(signal_sum, text="Faz: ")
signalSumLabelt.grid(row=2, column=0, padx=5, pady=10, sticky="n")

sumtheta = tk.Label(signal_sum, text="0")
sumtheta.grid(row=2, column=1, padx=5, pady=10, sticky="n")


# Değerleri almak ve grafik çizdirmek için fonksiyon
def draw():
    global a0
    # 1. Sinyalin değerlerini oku
    amplitude1 = float(A1.get())
    frequency1 = float(f1.get())
    phase1 = float(theta1.get())

    # 2. Sinyalin değerlerini oku
    amplitude2 = float(A2.get())
    frequency2 = float(f2.get())
    phase2 = float(theta2.get())

    # 3. Sinyalin değerlerini oku
    amplitude3 = float(A3.get())
    frequency3 = float(f3.get())
    phase3 = float(theta3.get())

    # a0 değerini oku
    a_0 = float(a0.get())

    # Zaman aralığı
    t = np.linspace(-2, 2, 1000)
    # derece değerlerini radyana çevirme
    phase1_radians = phase1 * (np.pi / 180)
    phase2_radians = phase2 * (np.pi / 180)
    phase3_radians = phase3 * (np.pi / 180)

    # Sinyaller
    y1_cos = amplitude1 * np.cos(2 * np.pi * frequency1 * t + phase1_radians)
    y2_cos = amplitude2 * np.cos(2 * np.pi * frequency2 * t + phase2_radians)
    y3_cos = amplitude3 * np.cos(2 * np.pi * frequency3 * t + phase3_radians)

    # Toplam sinyal
    y_sum = a_0 + y1_cos + y2_cos + y3_cos

    # Grafik oluştur
    figure = Figure(figsize=(10, 6), dpi=100)

    # Sinyal 1 grafikleri
    ax1 = figure.add_subplot(411)
    ax1.plot(t, y1_cos, label="Sinyal 1 - Cos")
    ax1.legend()

    # Sinyal 2 grafikleri
    ax2 = figure.add_subplot(412)
    ax2.plot(t, y2_cos, label="Sinyal 2 - Cos")
    ax2.legend()

    # Sinyal 3 grafikleri
    ax3 = figure.add_subplot(413)
    ax3.plot(t, y3_cos, label="Sinyal 3 - Cos")
    ax3.legend()

    # Toplam sinyal grafiği
    ax4 = figure.add_subplot(414)
    ax4.plot(t, y_sum, label="Toplam Sinyal", color="red")
    ax4.legend()

    # Toplam sinyal özelliklerini hesapla
    amplitude_sum = np.abs(np.max(y_sum) - np.min(y_sum)) / 2
    print(amplitude_sum)

    # a0 değerini tekrar oku ve float'a dönüştür
    a_0_float = float(a0.get())

    # amplitude_sum ile topla
    amplitude_sum += a_0_float
    frequency_sum = (
        frequency1  # Baskın frekans olarak ilk sinyalin frekansı kabul edilir
    )
    phase_sum = np.arctan2(
        np.sum(
            [
                amplitude1 * np.sin(phase1_radians),
                amplitude2 * np.sin(phase2_radians),
                amplitude3 * np.sin(phase3_radians),
            ]
        ),
        np.sum(
            [
                amplitude1 * np.cos(phase1_radians),
                amplitude2 * np.cos(phase2_radians),
                amplitude3 * np.cos(phase3_radians),
            ]
        ),
    )
    phase_sum_degrees = np.degrees(phase_sum)

    # Toplam sinyal özelliklerini güncelle
    sumA.config(text=f"{amplitude_sum:.2f}")
    sumf.config(text=f"{frequency_sum:.2f}")
    sumtheta.config(text=f"{phase_sum_degrees:.2f}")

    # Eski kanvasları temizle
    for widget in graphics_frame.winfo_children():
        widget.destroy()

    # Canvas oluştur ve grafikleri çerçeveye yerleştir
    canvas = FigureCanvasTkAgg(figure, graphics_frame)
    canvas.draw()
    canvas.get_tk_widget().grid(row=0, column=0, padx=5, pady=5)


# Çizdir butonu
plot_button = tk.Button(form, text="Çizdir", command=draw)
plot_button.grid(row=1, column=2, pady=10)


def open_new_window():
    new_window = tk.Toplevel(form)
    new_window.title("Yeni Pencere")
    new_window.geometry("400x300")

    a1label = tk.Label(new_window, text="a1: ")
    a1label.grid(row=0, column=0, padx=5, pady=10, sticky="n")

    a1 = tk.Entry(new_window, width=10)
    a1.grid(row=0, column=1, padx=5, pady=10)

    a2label = tk.Label(new_window, text="a2: ")
    a2label.grid(row=1, column=0, padx=5, pady=10, sticky="n")

    a2 = tk.Entry(new_window, width=10)
    a2.grid(row=1, column=1, padx=5, pady=10)

    a3label = tk.Label(new_window, text="a3: ")
    a3label.grid(row=2, column=0, padx=5, pady=10, sticky="n")

    a3 = tk.Entry(new_window, width=10)
    a3.grid(row=2, column=1, padx=5, pady=10)

    b1label = tk.Label(new_window, text="b1: ")
    b1label.grid(row=0, column=2, padx=5, pady=10, sticky="n")

    b1 = tk.Entry(new_window, width=10)
    b1.grid(row=0, column=3, padx=5, pady=10)

    b2label = tk.Label(new_window, text="b2: ")
    b2label.grid(row=1, column=2, padx=5, pady=10, sticky="n")

    b2 = tk.Entry(new_window, width=10)
    b2.grid(row=1, column=3, padx=5, pady=10)

    b3label = tk.Label(new_window, text="b3: ")
    b3label.grid(row=2, column=2, padx=5, pady=10, sticky="n")

    b3 = tk.Entry(new_window, width=10)
    b3.grid(row=2, column=3, padx=5, pady=10)

    a0label = tk.Label(new_window, text="a0: ")
    a0label.grid(row=3, column=0, padx=5, pady=10, sticky="n")

    a00 = tk.Entry(new_window, width=10)
    a00.grid(row=3, column=1, padx=5, pady=10)

    w0label = tk.Label(new_window, text="f: ")
    w0label.grid(row=3, column=2, padx=5, pady=10, sticky="n")

    w0 = tk.Entry(new_window, width=10)
    w0.grid(row=3, column=3, padx=5, pady=10)

    def calculate_and_convert():
        global a0
        try:
            a_0 = float(a00.get())
            w_0 = float(w0.get())
            a_1 = float(a1.get())
            a_2 = float(a2.get())
            a_3 = float(a3.get())
            b_1 = float(b1.get())
            b_2 = float(b2.get())
            b_3 = float(b3.get())

            # Genlikleri hesapla
            A1_value = np.sqrt(a_1**2 + b_1**2)
            A2_value = np.sqrt(a_2**2 + b_2**2)
            A3_value = np.sqrt(a_3**2 + b_3**2)

            # Fazları hesapla (radyan cinsinden)
            theta1_value = np.arctan2(-b_1, a_1)
            theta2_value = np.arctan2(-b_2, a_2)
            theta3_value = np.arctan2(-b_3, a_3)

            # Fazları dereceye çevir
            theta1_deg = np.degrees(theta1_value)
            theta2_deg = np.degrees(theta2_value)
            theta3_deg = np.degrees(theta3_value)

            # Değerleri ana penceredeki girişlere geçir
            A1.delete(0, tk.END)
            A1.insert(0, f"{A1_value:.2f}")

            A2.delete(0, tk.END)
            A2.insert(0, f"{A2_value:.2f}")

            A3.delete(0, tk.END)
            A3.insert(0, f"{A3_value:.2f}")

            theta1.delete(0, tk.END)
            theta1.insert(0, f"{theta1_deg:.2f}")

            theta2.delete(0, tk.END)
            theta2.insert(0, f"{theta2_deg:.2f}")

            theta3.delete(0, tk.END)
            theta3.insert(0, f"{theta3_deg:.2f}")

            f1.delete(0, tk.END)
            f1.insert(0, f"{w_0:.2f}")

            f2.delete(0, tk.END)
            f2.insert(0, f"{w_0:.2f}")

            f3.delete(0, tk.END)
            f3.insert(0, f"{w_0:.2f}")

            # a0 değerini de ana pencereye geçir
            a0.delete(0, tk.END)
            a0.insert(0, f"{a_0:.2f}")

            # sumA label'ını güncelle
            sumA.config(text=f"{a_0:.2f}")

            new_window.destroy()
        except ValueError:
            error_label = tk.Label(
                new_window, text="Lütfen tüm değerleri doğru giriniz.", fg="red"
            )
            error_label.grid(row=5, columnspan=4, padx=5, pady=10)

    close_button = tk.Button(
        new_window,
        text="Değerleri çevir ve grafiğe geçir",
        command=calculate_and_convert,
    )
    close_button.grid(row=4, columnspan=4, padx=5, pady=10)


# Sin Cos butonu
sine_cosine_button = tk.Button(form, text="Sin-Cos Formu", command=open_new_window)
sine_cosine_button.grid(row=2, column=2, pady=10)


# Formu çalıştır
form.mainloop()
