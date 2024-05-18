from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QPushButton, QTextEdit, QMainWindow, QMessageBox, QListWidget, QListWidgetItem,QLabel
from transformers import AutoModelForCausalLM, AutoTokenizer
from PyQt5.QtWidgets import QProgressBar
from PyQt5.QtCore import Qt, QCoreApplication
from threadler import WorkerThread
import torch
import re
def preprocess_text(text):
    # Noktalama işaretlerini kaldır
    text = re.sub(r'[^\w\s]', '', text)
    
    # Tüm metni küçük harfe çevir
    text = text.lower()
    
    # Fazladan boşlukları kaldır
    text = re.sub(r'\s+', ' ', text).strip()
    
    return text
class ChatbotGUI(QMainWindow):
    def __init__(self):
        super().__init__()
        self.initUI()
        self.model, self.tokenizer, self.device = self.load_model()

    def initUI(self):
        self.setWindowTitle('Chatbot GUI')
        self.setGeometry(100, 100, 400, 600)

        central_widget = QWidget(self)
        self.setCentralWidget(central_widget)
        layout = QVBoxLayout(central_widget)

        self.chat_list_widget = QListWidget()
        layout.addWidget(self.chat_list_widget)
        self.add_message("Bot: Merhaba, nasıl yardımcı olabilirim?", False)

        # İlerleme çubuğu ekleme
        self.progress_bar = QProgressBar(self)
        layout.addWidget(self.progress_bar)
        self.progress_bar.setMaximum(0)  # Sonsuz ilerleme modu
        self.progress_bar.hide()  # Başlangıçta gizle

        self.question_text_edit = QTextEdit()
        self.question_text_edit.setPlaceholderText("Sorunuzu buraya yazın...")
        layout.addWidget(self.question_text_edit)

        self.send_button = QPushButton('Gönder')
        self.send_button.clicked.connect(self.on_send)
        self.send_button.setStyleSheet("background-color: green;")
        layout.addWidget(self.send_button)

        self.exit_button = QPushButton('Çıkış')
        self.exit_button.setStyleSheet("background-color: red;")
        self.exit_button.clicked.connect(self.close)
        layout.addWidget(self.exit_button)
        self.centerWindow()
    def centerWindow(self):
        # Pencereyi ekranın merkezine taşıma
        qr = self.frameGeometry()
        cp = QCoreApplication.instance().primaryScreen().availableGeometry().center()
        qr.moveCenter(cp)
        self.move(qr.topLeft())
    def keyPressEvent(self, event):
        if event.key() == Qt.Key_Return:
            self.on_send()
        else:
            super().keyPressEvent(event)  # Diğer tüm tuş basımları için varsayılan davranışı uygula
    # QMainWindow sınıfınız içinde
    def closeEvent(self, event):
        reply = QMessageBox.question(self, 'Çıkış', 'Çıkmak istediğinize emin misiniz?',
                                    QMessageBox.Yes | QMessageBox.No, QMessageBox.No)

        if reply == QMessageBox.Yes:
            event.accept()  # Pencereyi kapat
        else:
            event.ignore()  # Pencereyi kapatma olayını iptal et
    def load_model(self):
        model_yolu = "BestModelParameters"
        
        device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
        try:
            tokenizer = AutoTokenizer.from_pretrained(model_yolu)
            model = AutoModelForCausalLM.from_pretrained(model_yolu)
            model.to(device)
        except:
            print("Model bulunamadı")
        
        return model, tokenizer, device

    def generate_text(self, prompt_text, max_length=100):
        encoded_input = self.tokenizer.encode(prompt_text, return_tensors='pt', padding=True, truncation=True, max_length=max_length).to(self.device)
        
        output_sequences = self.model.generate(
            input_ids=encoded_input,
            max_length=max_length + 20,
            temperature=1.3,
            top_k=55,
            top_p=0.95,
            repetition_penalty=1.5,
            do_sample=True,
            num_return_sequences=1
        )
        
        generated_text = self.tokenizer.decode(output_sequences[0], skip_special_tokens=True)
        return generated_text.replace(prompt_text, "")

    def add_message(self, text, is_user):
        # QWidget oluştur
        widget = QWidget()
        # QLabel ile mesajı göster
        label = QLabel(text)
        label.setWordWrap(True)  # Kelime sarımını etkinleştir
        label.setStyleSheet("QLabel { background-color : %s; }" % ('#f0f0f0' if is_user else 'white'))

        # QVBoxLayout kullanarak QLabel'ı widget'a yerleştir
        layout = QVBoxLayout()
        layout.addWidget(label)
        widget.setLayout(layout)

        # QListWidgetItem oluştur ve boyutunu ayarla
        item = QListWidgetItem(self.chat_list_widget)
        item.setSizeHint(widget.sizeHint())

        # QListWidget'e widget'ı ekle
        self.chat_list_widget.addItem(item)
        self.chat_list_widget.setItemWidget(item, widget)
        self.chat_list_widget.scrollToBottom()
    def on_send(self):
        pre_user_question = self.question_text_edit.toPlainText()
        if len(pre_user_question) < 1:
            QMessageBox.information(self, "Hata", "Mesaj girilmedi.", QMessageBox.Ok)
            return  # Erken dönüş yaparak işlemi durdur
        pre_user_question = preprocess_text(pre_user_question)
        self.changeButtonEnabled()
        self.add_message(f"Siz: {pre_user_question}", True)
        user_question = self.tokenizer.additional_special_tokens[0] + " " + pre_user_question + " " + self.tokenizer.additional_special_tokens[1]
        self.question_text_edit.clear()
        self.progress_bar.show()  # İlerleme çubuğunu göster

        # Arka plan thread'i oluştur ve başlat
        self.worker = WorkerThread(self.generate_text, user_question, pre_user_question)
        self.worker.finished.connect(self.on_worker_finished)  # İşlem tamamlandığında çağrılacak slot
        self.worker.start()
    def changeButtonEnabled(self):
        is_enabled = self.send_button.isEnabled()
        self.send_button.setEnabled(not is_enabled)
        self.exit_button.setEnabled(not is_enabled)
    def on_worker_finished(self, bot_response):
        self.add_message(f"Bot: {bot_response.strip()}", False)
        self.progress_bar.hide()  # İlerleme çubuğunu gizle
        self.changeButtonEnabled()

def main():
    qssdosyasi = "stylesheet.qss"
    app = QApplication([])
    with open(qssdosyasi, "r") as file:
        app.setStyleSheet(file.read())
    chatbot_gui = ChatbotGUI()
    chatbot_gui.show()
    app.exec_()

if __name__ == '__main__':
    main()
