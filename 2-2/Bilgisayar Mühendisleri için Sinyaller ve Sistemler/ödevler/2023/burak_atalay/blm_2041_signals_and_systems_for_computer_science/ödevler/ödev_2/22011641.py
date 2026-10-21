import sys
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from PyQt5.QtWidgets import (
    QApplication, QWidget, QLabel, QLineEdit, QPushButton, QVBoxLayout, QGridLayout, QGroupBox, QFormLayout, QTabWidget, QMainWindow, QMessageBox
)

class SignalPlotter(QWidget):
    def __init__(self):
        super().__init__()
        self.init_ui()

    def init_ui(self):
        layout = QVBoxLayout()

        group_box1 = QGroupBox("Input for Signal 1")
        form_layout1 = QFormLayout()
        self.input_A1 = QLineEdit()
        self.input_f1 = QLineEdit()
        self.input_theta1 = QLineEdit()
        form_layout1.addRow(QLabel('Amplitude (A1):'), self.input_A1)
        form_layout1.addRow(QLabel('Frequency (f1):'), self.input_f1)
        form_layout1.addRow(QLabel('Phase (θ1):'), self.input_theta1)
        group_box1.setLayout(form_layout1)
        layout.addWidget(group_box1)

        group_box2 = QGroupBox("Input for Signal 2")
        form_layout2 = QFormLayout()
        self.input_A2 = QLineEdit()
        self.input_f2 = QLineEdit()
        self.input_theta2 = QLineEdit()
        form_layout2.addRow(QLabel('Amplitude (A2):'), self.input_A2)
        form_layout2.addRow(QLabel('Frequency (f2):'), self.input_f2)
        form_layout2.addRow(QLabel('Phase (θ2):'), self.input_theta2)
        group_box2.setLayout(form_layout2)
        layout.addWidget(group_box2)

        group_box3 = QGroupBox("Input for Signal 3")
        form_layout3 = QFormLayout()
        self.input_A3 = QLineEdit()
        self.input_f3 = QLineEdit()
        self.input_theta3 = QLineEdit()
        form_layout3.addRow(QLabel('Amplitude (A3):'), self.input_A3)
        form_layout3.addRow(QLabel('Frequency (f3):'), self.input_f3)
        form_layout3.addRow(QLabel('Phase (θ3):'), self.input_theta3)
        group_box3.setLayout(form_layout3)
        layout.addWidget(group_box3)

        form_layout_time = QFormLayout()
        self.input_T_start = QLineEdit()
        self.input_T_end = QLineEdit()
        form_layout_time.addRow(QLabel('Start Time (T_start):'), self.input_T_start)
        form_layout_time.addRow(QLabel('End Time (T_end):'), self.input_T_end)
        layout.addLayout(form_layout_time)

        plot_button = QPushButton('Plot Signals')
        plot_button.clicked.connect(self.open_plot_window)
        layout.addWidget(plot_button)

        self.setLayout(layout)

    def plot_signals(self, A1, f1, theta1, A2, f2, theta2, A3, f3, theta3, T_start, T_end):
        t = np.linspace(T_start, T_end, 1000)
        sin1 = A1 * np.sin(2 * np.pi * f1 * t + np.radians(theta1))
        cos1 = A1 * np.cos(2 * np.pi * f1 * t + np.radians(theta1))
        sin2 = A2 * np.sin(2 * np.pi * f2 * t + np.radians(theta2))
        cos2 = A2 * np.cos(2 * np.pi * f2 * t + np.radians(theta2))
        sin3 = A3 * np.sin(2 * np.pi * f3 * t + np.radians(theta3))
        cos3 = A3 * np.cos(2 * np.pi * f3 * t + np.radians(theta3))
        total_signal = sin1 + cos1 + sin2 + cos2 + sin3 + cos3

        fig, ax = plt.subplots(4, 1, figsize=(10, 8))
        ax[0].plot(t, sin1, label=f'{A1}*sin(2π*{f1}*t + θ={theta1})')
        ax[0].plot(t, cos1, label=f'{A1}*cos(2π*{f1}*t + θ={theta1})')
        ax[0].legend()

        ax[1].plot(t, sin2, label=f'{A2}*sin(2π*{f2}*t + θ={theta2})')
        ax[1].plot(t, cos2, label=f'{A2}*cos(2π*{f2}*t + θ={theta2})')
        ax[1].legend()

        ax[2].plot(t, sin3, label=f'{A3}*sin(2π*{f3}*t + θ={theta3})')
        ax[2].plot(t, cos3, label=f'{A3}*cos(2π*{f3}*t + θ={theta3})')
        ax[2].legend()

        ax[3].plot(t, total_signal, label='Total Signal')
        ax[3].legend()

        fig.tight_layout()
        fig.subplots_adjust(hspace=0.5)
        plt.show()

    def show_error_message(self):
        msg = QMessageBox()
        msg.setIcon(QMessageBox.Warning)
        msg.setWindowTitle("Input Error")
        msg.setText("All input fields must be filled.")
        msg.setStandardButtons(QMessageBox.Ok)
        msg.exec_()

    def open_plot_window(self):
        if not self.input_A1.text() or not self.input_f1.text() or not self.input_theta1.text() or \
           not self.input_A2.text() or not self.input_f2.text() or not self.input_theta2.text() or \
           not self.input_A3.text() or not self.input_f3.text() or not self.input_theta3.text() or \
           not self.input_T_start.text() or not self.input_T_end.text():
            self.show_error_message()
            return

        A1 = float(self.input_A1.text())
        f1 = float(self.input_f1.text())
        theta1 = float(self.input_theta1.text())
        A2 = float(self.input_A2.text())
        f2 = float(self.input_f2.text())
        theta2 = float(self.input_theta2.text())
        A3 = float(self.input_A3.text())
        f3 = float(self.input_f3.text())
        theta3 = float(self.input_theta3.text())
        T_start = float(self.input_T_start.text())
        T_end = float(self.input_T_end.text())
        self.plot_signals(A1, f1, theta1, A2, f2, theta2, A3, f3, theta3, T_start, T_end)

class FourierPlotter(QWidget):
    def __init__(self):
        super().__init__()
        self.init_ui()

    def init_ui(self):
        layout = QVBoxLayout()

        form_layout = QFormLayout()
        self.input_a0 = QLineEdit()
        self.input_a1 = QLineEdit()
        self.input_b1 = QLineEdit()
        self.input_a2 = QLineEdit()
        self.input_b2 = QLineEdit()
        self.input_a3 = QLineEdit()
        self.input_b3 = QLineEdit()
        self.input_f0 = QLineEdit()
        self.input_T_start = QLineEdit()
        self.input_T_end = QLineEdit()

        form_layout.addRow(QLabel('a0:'), self.input_a0)
        form_layout.addRow(QLabel('a1:'), self.input_a1)
        form_layout.addRow(QLabel('b1:'), self.input_b1)
        form_layout.addRow(QLabel('a2:'), self.input_a2)
        form_layout.addRow(QLabel('b2:'), self.input_b2)
        form_layout.addRow(QLabel('a3:'), self.input_a3)
        form_layout.addRow(QLabel('b3:'), self.input_b3)
        form_layout.addRow(QLabel('f0:'), self.input_f0)
        form_layout.addRow(QLabel('Start Time (T_start):'), self.input_T_start)
        form_layout.addRow(QLabel('End Time (T_end):'), self.input_T_end)

        layout.addLayout(form_layout)

        plot_button = QPushButton('Plot Fourier Series')
        plot_button.clicked.connect(self.open_fourier_plot_window)
        layout.addWidget(plot_button)

        self.setLayout(layout)

    def plot_fourier_series(self, a0, a1, b1, a2, b2, a3, b3, f0, T_start, T_end):
        t = np.linspace(T_start, T_end, 1000)
        omega0 = 2 * np.pi * f0

        term1 = a0 + a1 * np.cos(omega0 * t) + b1 * np.sin(omega0 * t)
        term2 = term1 + a2 * np.cos(2 * omega0 * t) + b2 * np.sin(2 * omega0 * t)
        term3 = term2 + a3 * np.cos(3 * omega0 * t) + b3 * np.sin(3 * omega0 * t)

        fig, ax = plt.subplots(3, 1, figsize=(10, 8))

        ax[0].plot(t, term1, label=f'{a0} + {a1}*cos({omega0:.2f}t) + {b1}*sin({omega0:.2f}t)')
        ax[0].legend()
        ax[0].set_title('Fourier Series for k = 1')

        ax[1].plot(t, term2, label=f'{a0} + {a1}*cos({omega0:.2f}t) + {b1}*sin({omega0:.2f}t) + {a2}*cos(2*{omega0:.2f}t) + {b2}*sin(2*{omega0:.2f}t)')
        ax[1].legend()
        ax[1].set_title('Fourier Series for k = 2')

        ax[2].plot(t, term3, label=f'{a0} + {a1}*cos({omega0:.2f}t) + {b1}*sin({omega0:.2f}t) + {a2}*cos(2*{omega0:.2f}t) + {b2}*sin(2*{omega0:.2f}t) + {a3}*cos(3*{omega0:.2f}t) + {b3}*sin(3*{omega0:.2f}t)')
        ax[2].legend()
        ax[2].set_title('Fourier Series for k = 3')

        fig.tight_layout()
        fig.subplots_adjust(hspace=0.5)
        plt.show()

    def show_error_message(self):
        msg = QMessageBox()
        msg.setIcon(QMessageBox.Warning)
        msg.setWindowTitle("Input Error")
        msg.setText("All input fields must be filled.")
        msg.setStandardButtons(QMessageBox.Ok)
        msg.exec_()

    def open_fourier_plot_window(self):
        if not self.input_a0.text() or not self.input_a1.text() or not self.input_b1.text() or \
           not self.input_a2.text() or not self.input_b2.text() or not self.input_a3.text() or \
           not self.input_b3.text() or not self.input_f0.text() or not self.input_T_start.text() or \
           not self.input_T_end.text():
            self.show_error_message()
            return

        a0 = float(self.input_a0.text())
        a1 = float(self.input_a1.text())
        b1 = float(self.input_b1.text())
        a2 = float(self.input_a2.text())
        b2 = float(self.input_b2.text())
        a3 = float(self.input_a3.text())
        b3 = float(self.input_b3.text())
        f0 = float(self.input_f0.text())
        T_start = float(self.input_T_start.text())
        T_end = float(self.input_T_end.text())
        self.plot_fourier_series(a0, a1, b1, a2, b2, a3, b3, f0, T_start, T_end)
        
class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.init_ui()

    def init_ui(self):
        self.setWindowTitle('Signal and Fourier Series Input')
        self.setGeometry(100, 100, 500, 600)

        tabs = QTabWidget()
        tabs.addTab(SignalPlotter(), 'Signal Input')
        tabs.addTab(FourierPlotter(), 'Fourier Series Input')

        self.setCentralWidget(tabs)

app = QApplication(sys.argv)
main_window = MainWindow()
main_window.show()
sys.exit(app.exec_())


