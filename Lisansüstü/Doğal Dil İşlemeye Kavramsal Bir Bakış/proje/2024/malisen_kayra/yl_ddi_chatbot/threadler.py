from PyQt5.QtCore import QThread, pyqtSignal

class WorkerThread(QThread):
    finished = pyqtSignal(str)  # İşlem bittiğinde sinyal gönder

    def __init__(self, generate_text_function, text, pre_text):
        super().__init__()
        self.generate_text_function = generate_text_function
        self.text = text
        self.pre_text = pre_text

    def run(self):
        # Arka planda çalışacak işlem (örneğin, metin üretimi)
        generated_text = self.generate_text_function(self.text)
        generated_text = generated_text.replace(self.pre_text,"")
        self.finished.emit(generated_text)  # İşlem bittiğinde sinyali tetikle
