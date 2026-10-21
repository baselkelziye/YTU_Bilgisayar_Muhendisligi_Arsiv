import sys
import numpy as np
import matplotlib.pyplot as plt
from PyQt5.QtWidgets import QApplication, QVBoxLayout, QHBoxLayout, QGridLayout, QPushButton, QLineEdit, QLabel, QWidget
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas

def plotSignals():
    A1 = float(inputAmplitude1.text())
    f1 = float(inputFrequency1.text())
    phase1 = float(inputPhase1.text())

    A2 = float(inputAmplitude2.text())
    f2 = float(inputFrequency2.text())
    phase2 = float(inputPhase2.text())

    A3 = float(inputAmplitude3.text())
    f3 = float(inputFrequency3.text())
    phase3 = float(inputPhase3.text())

    t = np.linspace(0, 1, 500)
    sineWave1 = A1 * np.sin(2 * np.pi * f1 * t + phase1)
    cosineWave1 = A1 * np.cos(2 * np.pi * f1 * t + phase1)

    sineWave2 = A2 * np.sin(2 * np.pi * f2 * t + phase2)
    cosineWave2 = A2 * np.cos(2 * np.pi * f2 * t + phase2)

    sineWave3 = A3 * np.sin(2 * np.pi * f3 * t + phase3)
    cosineWave3 = A3 * np.cos(2 * np.pi * f3 * t + phase3)

    sumWave = sineWave1 + cosineWave1 + sineWave2 + cosineWave2 + sineWave3 + cosineWave3

    figure.clear()

    ax1 = figure.add_subplot(411)
    ax1.plot(t, sineWave1, label='Sine Wave 1')
    ax1.plot(t, cosineWave1, label='Cosine Wave 1')
    ax1.grid(True)
    ax1.set_title('Sine and Cosine Wave 1')
    ax1.legend()

    ax2 = figure.add_subplot(412)
    ax2.plot(t, sineWave2, label='Sine Wave 2')
    ax2.plot(t, cosineWave2, label='Cosine Wave 2')
    ax2.grid(True)
    ax2.set_title('Sine and Cosine Wave 2')
    ax2.legend()

    ax3 = figure.add_subplot(413)
    ax3.plot(t, sineWave3, label='Sine Wave 3')
    ax3.plot(t, cosineWave3, label='Cosine Wave 3')
    ax3.grid(True)
    ax3.set_title('Sine and Cosine Wave 3')
    ax3.legend()

    ax4 = figure.add_subplot(414)
    ax4.plot(t, sumWave, label='Sum of Waves')
    ax4.grid(True)
    ax4.set_title('Sum of Waves')
    ax4.legend()

    figure.tight_layout()
    canvas.draw()

def plotFourierSeries():
    a0 = float(inputA0.text())
    a1 = float(inputA1.text())
    a2 = float(inputA2.text())
    a3 = float(inputA3.text())
    b1 = float(inputB1.text())
    b2 = float(inputB2.text())
    b3 = float(inputB3.text())
    w0 = float(inputW0.text())

    T0 = 2 * np.pi / w0

    t = np.linspace(0, T0, 500)
    harmonic1 = a1 * np.cos(w0 * t) + b1 * np.sin(w0 * t)
    harmonic2 = a2 * np.cos(2 * w0 * t) + b2 * np.sin(2 * w0 * t)
    harmonic3 = a3 * np.cos(3 * w0 * t) + b3 * np.sin(3 * w0 * t)
    signal = a0 + harmonic1 + harmonic2 + harmonic3

    figure.clear()

    ax1 = figure.add_subplot(411)
    ax1.plot(t, harmonic1, label='a1 + b1')
    ax1.grid(True)
    ax1.set_title('a1 + b1')
    ax1.legend()

    ax2 = figure.add_subplot(412)
    ax2.plot(t, harmonic2, label='a2 + b2')
    ax2.grid(True)
    ax2.set_title('a2 + b2')
    ax2.legend()

    ax3 = figure.add_subplot(413)
    ax3.plot(t, harmonic3, label='a3 + b3')
    ax3.grid(True)
    ax3.set_title('a3 + b3')
    ax3.legend()

    ax4 = figure.add_subplot(414)
    ax4.plot(t, signal, label='Sum of Signals')
    ax4.grid(True)
    ax4.set_title('Sum of Signals')
    ax4.legend()

    figure.tight_layout()
    canvas.draw()

app = QApplication(sys.argv)
window = QWidget()
window.setWindowTitle('GUI')

mainLayout = QVBoxLayout(window)

inputLayout = QHBoxLayout()
mainLayout.addLayout(inputLayout)

inputLayout1 = QGridLayout()
inputLayout.addLayout(inputLayout1)

labels1 = ["Amplitude 1 (A1)", "Frequency 1 (f1)", "Phase 1 (θ1)"]
inputs1 = []

for i, labelText in enumerate(labels1):
    label = QLabel(labelText)
    inputLayout1.addWidget(label, i, 0)
    lineEdit = QLineEdit()
    inputLayout1.addWidget(lineEdit, i, 1)
    inputs1.append(lineEdit)

inputAmplitude1, inputFrequency1, inputPhase1 = inputs1

labels2 = ["Amplitude 2 (A2)", "Frequency 2 (f2)", "Phase 2 (θ2)"]
inputs2 = []

for i, labelText in enumerate(labels2):
    label = QLabel(labelText)
    inputLayout1.addWidget(label, i + 3, 0)
    lineEdit = QLineEdit()
    inputLayout1.addWidget(lineEdit, i + 3, 1)
    inputs2.append(lineEdit)

inputAmplitude2, inputFrequency2, inputPhase2 = inputs2

labels3 = ["Amplitude 3 (A3)", "Frequency 3 (f3)", "Phase 3 (θ3)"]
inputs3 = []

for i, labelText in enumerate(labels3):
    label = QLabel(labelText)
    inputLayout1.addWidget(label, i + 6, 0)
    lineEdit = QLineEdit()
    inputLayout1.addWidget(lineEdit, i + 6, 1)
    inputs3.append(lineEdit)

inputAmplitude3, inputFrequency3, inputPhase3 = inputs3

button1 = QPushButton('Plot Signals')
button1.clicked.connect(plotSignals)
inputLayout1.addWidget(button1, 9, 0, 1, 2)

inputLayout2 = QGridLayout()
inputLayout.addLayout(inputLayout2)

labels4 = ["a0", "a1", "a2", "a3", "b1", "b2", "b3", "w0"]
inputs4 = []

for i, labelText in enumerate(labels4):
    label = QLabel(labelText)
    inputLayout2.addWidget(label, i, 0)
    lineEdit = QLineEdit()
    inputLayout2.addWidget(lineEdit, i, 1)
    inputs4.append(lineEdit)

inputA0, inputA1, inputA2, inputA3, inputB1, inputB2, inputB3, inputW0 = inputs4

button2 = QPushButton('Plot Fourier Series')
button2.clicked.connect(plotFourierSeries)
inputLayout2.addWidget(button2, 9, 0, 1, 2)

figure = plt.figure()
canvas = FigureCanvas(figure)
mainLayout.addWidget(canvas)

window.setLayout(mainLayout)
window.show()

sys.exit(app.exec_())
