import matplotlib.pyplot as plt
import numpy as np
import sys
from PyQt5 import QtWidgets
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.figure import Figure
from gui import Ui_MainWindow

PI = np.pi

class MyApp(QtWidgets.QMainWindow):
    def __init__(self):
        super().__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.figure1 = Figure()
        self.canvas1 = FigureCanvas(self.figure1)

        self.figure2 = Figure()
        self.canvas2 = FigureCanvas(self.figure2)

        self.figure3 = Figure()
        self.canvas3 = FigureCanvas(self.figure3)

        self.figure4 = Figure()
        self.canvas4 = FigureCanvas(self.figure4)

        self.figure5 = Figure()
        self.canvas5 = FigureCanvas(self.figure5)

        self.figure6 = Figure()
        self.canvas6 = FigureCanvas(self.figure6)

        self.figure7 = Figure()
        self.canvas7 = FigureCanvas(self.figure7)
        
        layout1 = QtWidgets.QVBoxLayout(self.ui.widget_5)
        layout1.addWidget(self.canvas1)

        layout2 = QtWidgets.QVBoxLayout(self.ui.widget_6)
        layout2.addWidget(self.canvas2)

        layout3 = QtWidgets.QVBoxLayout(self.ui.widget_4)
        layout3.addWidget(self.canvas3)

        layout4 = QtWidgets.QVBoxLayout(self.ui.widget_7)
        layout4.addWidget(self.canvas4)

        layout5 = QtWidgets.QVBoxLayout(self.ui.widget_3)
        layout5.addWidget(self.canvas5)

        layout6 = QtWidgets.QVBoxLayout(self.ui.widget_8)
        layout6.addWidget(self.canvas6)

        layout7 = QtWidgets.QVBoxLayout(self.ui.widget_9)
        layout7.addWidget(self.canvas7)
        
        
        self.ui.pushButton_3.clicked.connect(self.draw_sin_button_push)
        self.ui.pushButton_2.clicked.connect(self.draw_fourier_button_push)
        
        
        
    def draw_sin_button_push(self):
        amplitude = int(self.ui.lineEdit_16.text())
        freq = int(self.ui.lineEdit_15.text())
        phase = int(self.ui.lineEdit_14.text())
        
        sinx = draw_signal_sin(a=amplitude,f=freq,p=phase)
        cosx = draw_signal_cos(a=amplitude,f=freq,p=phase)
        
        self.plot_signal_sin(sinx=sinx,a=amplitude,f=freq,p=phase,fig=self.figure1,canvas=self.canvas1)
        self.plot_signal_cos(cosx=cosx,a=amplitude,f=freq,p=phase,fig=self.figure2,canvas=self.canvas2)

    def draw_fourier_button_push(self):
        a_k = [0, 0, 0]
        b_k = [0, 0, 0]
        w = float(self.ui.lineEdit_17.text().replace(',', '.'))
        T = float(self.ui.lineEdit_5.text().replace(',', '.'))
        a0 = float(self.ui.lineEdit_4.text().replace(',', '.'))
        a_k[0] = float(self.ui.lineEdit_8.text().replace(',', '.'))
        a_k[1] = float(self.ui.lineEdit_12.text().replace(',', '.'))
        a_k[2] = float(self.ui.lineEdit_13.text().replace(',', '.'))
        b_k[0] = float(self.ui.lineEdit_18.text().replace(',', '.'))
        b_k[1] = float(self.ui.lineEdit_19.text().replace(',', '.'))
        b_k[2] = float(self.ui.lineEdit_20.text().replace(',', '.'))
        
        self.t = np.arange(0, 10, 0.1)
        
        self.signal = draw_fourier_signals(w,T,a0,a_k,b_k)
        self.plot_fourier_signal(self.t,self.signal,self.figure7,self.canvas7)
        
        t, sin_terms, cos_terms = draw_fourier_individual_terms(w, T, a_k, b_k)
            
         # Sinüs terimlerini çizer
        self.plot_individual_signal(t, sin_terms[0], "Sin 1", self.figure1, self.canvas1)
        self.plot_individual_signal(t, sin_terms[1], "Sin 2", self.figure3, self.canvas3)
        self.plot_individual_signal(t, sin_terms[2], "Sin 3", self.figure5, self.canvas5)

        # Kosinüs terimlerini çizer
        self.plot_individual_signal(t, cos_terms[0], "Cos 1", self.figure2, self.canvas2)
        self.plot_individual_signal(t, cos_terms[1], "Cos 2", self.figure4, self.canvas4)
        self.plot_individual_signal(t, cos_terms[2], "Cos 3", self.figure6, self.canvas6)
    
    def plot_signal_sin(self,sinx, a, f, p,fig,canvas):
        
        fig.clear()        
        t = np.arange(0, 1, 0.1)
        
        ax = fig.add_subplot(111)
        ax.plot(t, sinx)
        ax.set_title(f"Sinüs Dalgası: A={a}, f={f} Hz, φ={p} rad")
        ax.set_ylabel("Genlik")
        ax.grid(True)
        canvas.draw()
        
    def plot_signal_cos(self,cosx, a, f, p,fig,canvas):
        
        fig.clear()
        
        t = np.arange(0, 1, 0.1)
        
        ax = fig.add_subplot(111)
        ax.plot(t, cosx)
        ax.set_title(f"Kosinüs Dalgası: A={a}, f={f} Hz, φ={p} rad")
        ax.set_xlabel("Zaman (saniye)")
        ax.set_ylabel("Genlik")
        ax.grid(True)
        
        canvas.draw()

    def plot_fourier_signal(self,t,signal,fig,canvas):
        
        fig.clear()
        t = np.arange(0, 10, 0.1)
        
        ax = fig.add_subplot(111)
        ax.plot(t, signal)
        ax.set_xlabel("Zaman (saniye)")
        ax.set_ylabel("Genlik")
        ax.grid(True)
        
        canvas.draw()
    
    def plot_individual_signal(self,t, signal, title, fig, canvas):
        fig.clear()
        ax = fig.add_subplot(111)
        ax.plot(t, signal)
        ax.set_title(title)
        ax.set_xlabel("Zaman (saniye)")
        ax.set_ylabel("Genlik")
        ax.grid(True)
        canvas.draw()

    
def draw_fourier_individual_terms(w, T, a_k, b_k):
    t = np.arange(0, 10, 0.1)
    sin_terms = []
    cos_terms = []
    for k in range(1, 4):
        cos_terms.append(a_k[k-1] * np.cos(2 * PI * k * t / T))
        sin_terms.append(b_k[k-1] * np.sin(2 * PI * k * t / T))
    return t, sin_terms, cos_terms

def draw_signal_sin(a,f,p):
    t = np.arange(0, 1, 0.1)

    sin_x = a * np.sin(2*PI*f*t + p)
    
    return (sin_x)
    
def draw_signal_cos(a,f,p):
    t = np.arange(0, 1, 0.1)

    cos_x = a * np.cos(2*PI*f*t + p)
    
    return (cos_x)
    
def draw_fourier_signals(w,T,a0,a_k,b_k):
    t = np.arange(0, 10, 0.1)
    sum = a0
    for k in range(0,3):
        sum += a_k[k] * np.cos(2 * PI * k * t / T) + b_k[k] * np.sin(2 * PI * k * t / T)
        
    return sum

def main():

    a = int(input("A:"))
    f = int(input("f:"))
    p = PI / int(input("phase:"))
    
    sinx = draw_signal_sin(a,f,p)
    cosx = draw_signal_cos(a,f,p)
    
    # plot_signal(sinx,cosx,a,f,p)

if "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = MyApp()
    window.show()
    sys.exit(app.exec_())