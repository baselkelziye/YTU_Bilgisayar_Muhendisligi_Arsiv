import sys
import numpy as np
import matplotlib.pyplot as plt
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from matplotlib.backends.backend_qt5agg import *

def q1_graphs():
    t = np.linspace(-3, 3, 1000)
    total_signal = np.zeros_like(t)
    for i, (amplitude, frequency, phase) in enumerate(q1_inputs):
        A=float(amplitude.text())
        f=float(frequency.text())
        theta =float(phase.text())
        signal = A * np.cos(2 * np.pi * f * t + np.deg2rad(theta))
        total_signal+=signal
        q1_canvases[i][1].cla()
        q1_canvases[i][1].plot(t, signal)
        q1_canvases[i][1].set_title(f"Sinyal {i+1}: A={A}, f={f}, θ={theta}")
        q1_canvases[i][0].draw()
    q1_canvases[3][1].cla()
    q1_canvases[3][1].plot(t, total_signal)
    q1_canvases[3][1].set_title("Toplam Sinyal")
    q1_canvases[3][0].draw()

def q2_graphs():
    a0 = float(a0_input.text())
    w0 = float(w0_input.text())
    t = np.linspace(-20, 20, 1000)
    total_signal = a0 * np.ones_like(t) 
    for i, (ak_input, bk_input) in enumerate(q2_inputs):
        ak = float(ak_input.text())
        bk = float(bk_input.text())
        total_signal += ak * np.cos((i + 1) * w0 * t) + bk * np.sin((i + 1) * w0 * t)
    q2_canvas.figure.clf()
    ax = q2_canvas.figure.add_subplot(111)
    ax.plot(t, total_signal)
    ax.set_title("Fourier Serisi Toplam Sinyali")
    ax.set_xlabel("Zaman")
    ax.set_ylabel("Genlik")
    ax.grid(True)
    q2_canvas.draw()

def show_q1():
    stack.setCurrentWidget(q1_widget)

def show_q2():
    stack.setCurrentWidget(q2_widget)

def plot_graphs():
    if stack.currentWidget() == q1_widget:
        q1_graphs()
    else:
        q2_graphs()

app = QApplication(sys.argv)
main_window = QWidget()
palette = QPalette()
palette.setColor(QPalette.Window, QColor("#6a90cc"))
main_window.setPalette(palette)
main_window.setAutoFillBackground(True)
layout = QVBoxLayout(main_window)
button_layout = QHBoxLayout()
q1_button = QPushButton("1. Soru")
q2_button = QPushButton("2. Soru")
draw_button = QPushButton("Çiz")
button_layout.addWidget(q1_button)
button_layout.addWidget(q2_button)
button_layout.addWidget(draw_button)
layout.addLayout(button_layout)
stack = QStackedWidget(main_window)

q1_widget = QWidget()
q1_layout = QVBoxLayout(q1_widget)
q1_inputs = []
for i in range(3):
    hlayout = QHBoxLayout()
    hlayout.addWidget(QLabel(f"Sinyal {i+1}:"))
    amplitude = QLineEdit()
    amplitude.setPlaceholderText("Genlik")
    frequency = QLineEdit()
    frequency.setPlaceholderText("Frekans")
    phase = QLineEdit()
    phase.setPlaceholderText("Faz")
    q1_inputs.append((amplitude, frequency, phase))
    hlayout.addWidget(amplitude)
    hlayout.addWidget(frequency)
    hlayout.addWidget(phase)
    q1_layout.addLayout(hlayout)
q1_canvas_layout = QVBoxLayout()
q1_canvases = []
for i in range(4):
    fig, ax = plt.subplots()
    canvas = FigureCanvas(fig)
    q1_canvases.append((canvas, ax))
    q1_canvas_layout.addWidget(canvas)
q1_layout.addLayout(q1_canvas_layout)
q1_widget.setLayout(q1_layout)
stack.addWidget(q1_widget)
q2_widget = QWidget()
q2_layout = QVBoxLayout(q2_widget)
a0_input = QLineEdit()
a0_input.setPlaceholderText("a0")
q2_layout.addWidget(a0_input)
q2_inputs = []
for i in range(3):
    hlayout = QHBoxLayout()
    ak = QLineEdit()
    ak.setPlaceholderText(f"a{i+1}")
    bk = QLineEdit()
    bk.setPlaceholderText(f"b{i+1}")
    q2_inputs.append((ak, bk))
    hlayout.addWidget(ak)
    hlayout.addWidget(bk)
    q2_layout.addLayout(hlayout)
w0_input = QLineEdit()
w0_input.setPlaceholderText("w0")
q2_layout.addWidget(w0_input)
q2_canvas_layout = QVBoxLayout()
q2_canvas = FigureCanvas(plt.figure())
q2_canvas_layout.addWidget(q2_canvas)
q2_layout.addLayout(q2_canvas_layout)
q2_widget.setLayout(q2_layout)
stack.addWidget(q2_widget)
layout.addWidget(stack)
q1_button.clicked.connect(show_q1)
q2_button.clicked.connect(show_q2)
draw_button.clicked.connect(plot_graphs)

main_window.setLayout(layout)
main_window.setMinimumSize(1000, 1000) 
main_window.show()
sys.exit(app.exec_())
