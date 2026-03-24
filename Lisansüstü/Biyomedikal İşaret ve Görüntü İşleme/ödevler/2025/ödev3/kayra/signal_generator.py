import numpy as np

class SignalGenerator:
    """Çeşitli test sinyalleri üreten sınıf"""
    
    @staticmethod
    def exponential_decay(a, length=50):
        """Üstel azalan sinyal: a^n u[n]"""
        n = np.arange(0, length)
        return (a ** n) * (n >= 0), n
    
    @staticmethod
    def complex_exponential(a, omega, length=40):
        """Karmaşık üstel: a^n e^(jωn) u[n]"""
        n = np.arange(0, length)
        return (a ** n) * np.exp(1j * omega * n) * (n >= 0), n
    
    @staticmethod
    def rectangular_window(width=5):
        """Dikdörtgen pencere"""
        n = np.arange(-width*2, width*2+1)
        return (np.abs(n) <= width).astype(float), n
    
    @staticmethod
    def sinusoidal(freq, length=50, fs=1.0):
        """Sinüzoidal sinyal"""
        n = np.arange(0, length)
        return np.sin(2 * np.pi * freq * n / fs), n
