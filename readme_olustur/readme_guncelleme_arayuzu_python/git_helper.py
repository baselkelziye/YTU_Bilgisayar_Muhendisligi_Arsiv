import subprocess
from degiskenler import (
    SIL_BUTONU_STILI,
    EKLE_BUTONU_STILI,
    SAVE_ICO_PATH,
    DELETE_ICO_PATH,
    RESTORE_ICO_PATH,
    INFO_ICO_PATH,
)
from metin_islemleri import elideText
from PyQt6.QtWidgets import (
    QDialog,
    QVBoxLayout,
    QPushButton,
    QListWidget,
    QCheckBox,
    QMessageBox,
    QTextEdit,
    QLabel,
    QWidget,
    QSizePolicy,
    QHBoxLayout,
    QListWidgetItem,
    QSplitter,
)
from PyQt6.QtGui import QIcon
from PyQt6.QtCore import Qt, QTimer, QSize
import textwrap
from helpers.progress_dialog_helper import (
    CustomProgressDialogWithCancel,
    CustomProgressDialog,
)
from threadler import CMDScriptRunnerThread
import difflib
import os
from screen_utils import apply_minimum_size


class GitHelper:
    @staticmethod
    def get_file_content_at_commit(repo_path, file_path, commit_hash):
        if commit_hash == "WORKING":  # "WORKING" özel bir anahtar olarak kullanılıyor
            # Dosyanın çalışma kopyasındaki şu anki içeriğini oku
            full_path = os.path.join(repo_path, file_path)
            try:
                with open(full_path, "r", encoding="utf-8") as file:
                    return file.read()
            except FileNotFoundError:
                return "Dosya Silindi"
            except IOError as e:
                print("Dosya okuma hatası:", e)
                return ""
        else:
            # Belirli bir commit'teki dosya içeriğini git show ile al
            if file_path[0] == '"':
                file_path = file_path[1 : len(file_path) - 1]
            cmd = [
                "git",
                "-C",
                repo_path,
                "show",
                "{}:{}".format(commit_hash, file_path),
            ]
            try:
                output = subprocess.check_output(
                    cmd, stderr=subprocess.STDOUT, universal_newlines=True
                )
                return output
            except subprocess.CalledProcessError as e:
                print("Git show hatası:", e.output)
                return ""

    @staticmethod
    def set_git_quotepath_off(repo_path):
        # Git yapılandırmasını değiştirmek için git config komutunu çağır
        subprocess.run(
            ["git", "-C", repo_path, "config", "core.quotepath", "off"], check=True
        )

    @staticmethod
    def git_status(repo_path):
        GitHelper.set_git_quotepath_off(repo_path)
        result = subprocess.run(
            ["git", "-C", repo_path, "status", "--porcelain"],
            capture_output=True,
            text=False,  # Bu satırı kaldırdık
        )
        # stdout'u 'utf-8' kullanarak decode ediyoruz
        decoded_output = result.stdout.decode("utf-8")
        return decoded_output.split("\n")

    @staticmethod
    def git_add(repo_path, file_path):
        if file_path[0] != '"':
            file_path = '"' + file_path + '"'
        subprocess.run(f"git -C {repo_path} add -- {file_path}", shell=True)

    @staticmethod
    def git_add_all(repo_path):
        subprocess.run(f"git -C {repo_path} add --all", shell=True)

    @staticmethod
    def git_reset_all(repo_path):
        subprocess.run(f"git -C {repo_path} reset HEAD", shell=True)

    @staticmethod
    def git_reset(repo_path, file_path):
        if file_path[0] != '"':
            file_path = '"' + file_path + '"'
        subprocess.run(f"git -C {repo_path} reset -- {file_path}", shell=True)

    @staticmethod
    def git_commit(repo_path, message):
        subprocess.run(["git", "-C", repo_path, "commit", "-m", message])

    @staticmethod
    def git_push(repo_path):
        subprocess.run(["git", "-C", repo_path, "push"])

    @staticmethod
    def git_restore(repo_path, file_path):
        subprocess.run(
            f"git -C {repo_path} restore -- {file_path}",
            shell=True,
        )

    @staticmethod
    def git_diff(repo_path, file_name):
        # Git diff komutunu çalıştır
        result = subprocess.run(
            ["git", "-C", repo_path, "diff", file_name], capture_output=True, text=True
        )
        diff_output = result.stdout
        return diff_output


def getMaxSizeYatay():
    return QSizePolicy(QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Preferred)


def getMaxSizeDikey():
    return QSizePolicy(QSizePolicy.Policy.Preferred, QSizePolicy.Policy.Expanding)


class GitDialog(QDialog):
    def __init__(self, repo_path, parent=None):
        super().__init__(parent=parent)
        self.setModal(True)
        self.repo_path = repo_path
        apply_minimum_size(self, 550, 650)  # Ekrana göre dinamik boyut
        self.timer = QTimer()
        self.timer.timeout.connect(self.processNextItem)
        self.status_lines = []
        self.current_index = 0  # Şu an işlenmekte olan satırın indeksi
        self.initUI()

    def initUI(self):
        self.setWindowTitle("Git Değişiklikleri")
        self.setGeometry(100, 100, 600, 400)
        # Kaydedilmeyen ve Kaydedilen Değişiklikler için QSplitter oluştur
        changesSplitter = QSplitter(Qt.Orientation.Vertical)
        layout = QVBoxLayout()
        staged_layout = QHBoxLayout()
        unstaged_layout = QHBoxLayout()
        self.unstagedList = QListWidget()
        self.stagedList = QListWidget()
        self.commitMessage = QTextEdit()
        self.amendCheckBox = QCheckBox("Amend")
        pushButton = QPushButton("Değişiklikleri Pushla")
        add_all_btn = QPushButton("Tüm değişiklikleri ekle")
        add_all_btn.setStyleSheet(EKLE_BUTONU_STILI)
        unstaged_label = QLabel("Kaydedilmeyen Değişiklikler")
        unstaged_label.setSizePolicy(getMaxSizeYatay())
        unstaged_layout.addWidget(unstaged_label)
        unstaged_layout.addWidget(add_all_btn)
        unstaged_widget = QWidget()
        unstaged_widget.setLayout(unstaged_layout)
        changesSplitter.addWidget(unstaged_widget)
        changesSplitter.addWidget(self.unstagedList)
        staged_label = QLabel("Kaydedilen Değişiklikler")
        staged_label.setSizePolicy(getMaxSizeYatay())
        delete_all_btn = QPushButton("Tüm değişiklikleri sil")
        delete_all_btn.setStyleSheet(SIL_BUTONU_STILI)
        staged_layout.addWidget(staged_label)
        staged_layout.addWidget(delete_all_btn)
        staged_widget = QWidget()
        staged_widget.setLayout(staged_layout)
        changesSplitter.addWidget(staged_widget)
        changesSplitter.addWidget(self.stagedList)
        layout.addWidget(changesSplitter)
        layout.addWidget(QLabel("Commit Mesajı"))
        layout.addWidget(self.commitMessage)
        layout.addWidget(self.amendCheckBox)
        layout.addWidget(pushButton)
        self.setLayout(layout)
        self.stagedList.setSizePolicy(getMaxSizeDikey())
        self.unstagedList.setSizePolicy(getMaxSizeDikey())
        add_all_btn.clicked.connect(self.tumDegisiklikleriEkle)
        pushButton.clicked.connect(self.pushChanges)
        delete_all_btn.clicked.connect(self.tumDegisiklikleriSil)

    def getStatusToInterface(self):
        self.populateChanges()
        self.setupInitTimer()

    def setupInitTimer(self):
        # QTimer nesnesi oluşturulur
        self.init_timer = QTimer(self)
        # QTimer sinyali ile `processNextLine` metodunu bağla
        self.init_timer.timeout.connect(self.processNextLine)
        # QTimer'ı başlat (her 10 ms de bir)
        self.init_timer.start(10)

    def populateChanges(self):
        self.init_progress_dialog = CustomProgressDialog("Arayüz yükleniyor...", self)
        # GitHelper'dan gelen durum satırlarını al
        self.status_lines = GitHelper.git_status(self.repo_path)
        self.current_index = 0  # İndeksi sıfırla
        self.init_progress_dialog.show()
        # Timer'ı manuel olarak burada başlatabilirsiniz ya da başka bir yerde başlatmış olabilirsiniz
        # Eğer burada başlatmak istiyorsanız, yorumu kaldırın:
        # self.init_timer.start(10)

    def processNextLine(self):
        if self.current_index < len(self.status_lines):
            line = self.status_lines[self.current_index]
            if len(line) > 0:
                if line.startswith(" ") or line.startswith("??"):
                    self.addFileItem(self.unstagedList, line[3:], is_staged=False)
                else:
                    self.addFileItem(self.stagedList, line[3:], is_staged=True)
            self.current_index += 1
        else:
            self.init_timer.stop()  # Listenin sonuna ulaştığımızda timer'ı durdur
            self.init_progress_dialog.close()
            del self.init_progress_dialog

    def tumDegisiklikleriEkle(self):
        if len(self.unstagedList) == 0:
            QMessageBox.warning(self, "Hata", "Eklenecek eleman bulunamadı")
            return

        self.itemsToProcess = iter(self.getItemsFromListWidget(self.unstagedList))
        self.timer.start(
            30
        )  # 10 ms (0.01 saniye) aralıklarla `processNextItem`'ı çağır
        komut = f"git -C {self.repo_path} add --all"
        self.git_progress_dialog = CustomProgressDialog(
            "Arayüz değişiklikleri uyguluyor", self
        )
        self.git_progress_dialog.show()
        self.komut_calistir(
            "Tüm Elemanları Ekleme", "Ekleniyor", komut, kapansin_mi=False
        )

    def tumDegisiklikleriSil(self):
        if len(self.stagedList) == 0:
            QMessageBox.warning(self, "Hata", "Silinecek eleman bulunamadı")
            return
        self.itemsToProcess = iter(self.getItemsFromListWidget(self.stagedList))
        self.timer.start(
            30
        )  # 10 ms (0.01 saniye) aralıklarla `processNextItem`'ı çağır
        komut = f"git -C {self.repo_path} reset HEAD"
        self.git_progress_dialog = CustomProgressDialog(
            "Arayüz değişiklikleri uyguluyor", self
        )
        self.git_progress_dialog.show()
        self.komut_calistir(
            "Tüm Elemanları Çıkarma", "Çıkarılıyor", komut, kapansin_mi=False
        )

    def processNextItem(self):
        try:
            # Sonraki öğeyi al ve işle
            unstagedItem = next(self.itemsToProcess)
            unstagedItem.onButtonClick(git_komutunu_uygula=False)
        except StopIteration:
            # İşlenecek öğe kalmadıysa, timer'ı durdur
            self.timer.stop()
            self.git_progress_dialog.close()
            del self.git_progress_dialog
            QMessageBox.information(self, "Başarılı", "Arayüz Değişiklikleri Uygulandı")

    def addFileItem(self, list_widget, file_name, is_staged):
        item = QListWidgetItem(list_widget)
        widget = FileItemWidget(file_name, is_staged, self)
        item.setSizeHint(widget.sizeHint())
        list_widget.addItem(item)
        list_widget.setItemWidget(item, widget)

    def getItemsFromListWidget(self, list_widget):
        items = []
        for index in range(list_widget.count()):
            item = list_widget.item(index)
            widget = list_widget.itemWidget(item)
            items.append(widget)
        return items

    def removeFileItem(self, list_widget, file_name):
        # Öğeler arasında döngü yap
        for i in range(list_widget.count()):
            item = list_widget.item(i)
            widget = list_widget.itemWidget(item)
            # Dosya adını kontrol et
            if widget.file_name == file_name:
                # Öğeyi bulduğumuzda, onu ve widget'ını sil
                list_widget.takeItem(i)
                # Widget'ı bellekten tamamen kaldırmak için deleteLater kullanılır
                widget.deleteLater()
                break  # Eşleşme bulunduğunda döngüden çık

    def pushChanges(self):
        if self.stagedList.count() == 0 and not self.amendCheckBox.isChecked():
            QMessageBox.warning(self, "Hata", "Kaydedilen dosya yok.")
            return

        commit_msg = self.commitMessage.toPlainText()
        if not commit_msg:
            QMessageBox.warning(self, "Hata", "Commit mesajı gir.")
            return
        reply = QMessageBox.question(
            self,
            "Emin Misiniz?",
            "Değişiklikleri pushlamak istediğinize emin misiniz?",
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
            QMessageBox.StandardButton.No,
        )

        if reply == QMessageBox.StandardButton.No:
            return
        if self.amendCheckBox.isChecked():
            komut = f'git -C "{self.repo_path}" commit --amend -m "{commit_msg}" && git -C "{self.repo_path}" push --force-with-lease'
        else:
            komut = f'git -C "{self.repo_path}" commit -m "{commit_msg}" && git -C "{self.repo_path}" push'
        self.komut_calistir(
            thread_basligi="Git Push", baslik="Pushlanıyor", komut=komut
        )

    def komut_calistir(self, thread_basligi, baslik, komut, kapansin_mi=True):
        self.progress_dialog = CustomProgressDialogWithCancel(
            baslik, self, self.thread_durduruluyor
        )
        # Thread'i başlat
        self.thread = CMDScriptRunnerThread(komut, thread_basligi)
        if kapansin_mi:
            self.thread.finished.connect(self.on_finished)
        else:
            self.thread.finished.connect(self.kapanmadan_on_finished)
        self.thread.error.connect(self.on_error)
        self.thread.info.connect(self.info)
        self.thread.start()
        self.progress_dialog.show()

    def on_error(self, errors):
        self.progress_dialog.close()
        self.thread.quit()
        del self.thread
        del self.progress_dialog
        QMessageBox.critical(self, "Hata", errors)

    def info(self, message, maxlen=35):
        # Mesajı belirli bir uzunlukta parçalara ayır, kelimeleri tam böl
        wrapped_message = textwrap.fill(message, maxlen)

        # Güncellenmiş mesajı etiket metni olarak ayarla
        self.progress_dialog.setLabelText(wrapped_message)

    def kapanmadan_on_finished(self, output):
        self.on_finished(output=output, kapansin_mi=False)

    def on_finished(self, output, kapansin_mi=True):
        self.progress_dialog.close()
        self.thread.wait()
        del self.thread
        del self.progress_dialog
        if kapansin_mi:
            self.close()
        QMessageBox.information(self, "Başarılı", output)

    def thread_durduruluyor(self):
        cevap = QMessageBox.question(
            self,
            "Onay",
            f"İşlemi durdurmak istediğinize emin misiniz?",
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
        )
        if cevap == QMessageBox.StandardButton.No:
            return
        self.progress_dialog.setLabelText("İşlem durduruluyor...")
        self.progress_dialog.setCancelButton(None)
        self.thread.durdur()


class FileItemWidget(QWidget):
    def __init__(self, file_name, is_staged, parent):
        super().__init__(parent)
        self.file_name = file_name
        self.is_staged = is_staged
        self.parent = parent
        self.initUI()

    def initUI(self):
        layout = QHBoxLayout()
        btn_layout = QVBoxLayout()
        self.label = QLabel()
        self.label.setSizePolicy(getMaxSizeYatay())
        self.label.setText(elideText(self.file_name))
        self.label.setToolTip(self.file_name)  # Tam dosya adını tooltip olarak ekleme
        btns = []
        # Kaydet/Sil butonu
        save_delete_button = QPushButton()
        save_delete_button.setIcon(
            QIcon(SAVE_ICO_PATH if not self.is_staged else DELETE_ICO_PATH)
        )  # İkon yolu
        save_delete_button.clicked.connect(lambda: self.onButtonClick(True))
        btns.append(save_delete_button)
        # Farkı Gör butonu
        diff_btn = QPushButton()
        diff_btn.setIcon(QIcon(INFO_ICO_PATH))  # İkon yolu
        diff_btn.clicked.connect(self.showGitDiff)
        btns.append(diff_btn)
        if not self.is_staged:
            # Restore butonu
            restore_btn = QPushButton()
            restore_btn.setIcon(QIcon(RESTORE_ICO_PATH))  # İkon yolu
            restore_btn.clicked.connect(self.onRestoreClick)
            btns.append(restore_btn)
        # Buton boyutlarını ayarla
        for btn in btns:
            btn.setStyleSheet("min-width: 12px; min-height: 12px;")
            btn.setFixedSize(QSize(12, 60))  # Küçük buton boyutu
            btn_layout.addWidget(btn)

        layout.addWidget(self.label)
        layout.addLayout(btn_layout)
        self.setLayout(layout)

    def onRestoreClick(self):
        reply = QMessageBox.question(
            self,
            "Emin Misiniz?",
            f"{self.file_name} Dosyasının tüm değişikliklerini eski haline getirmek istediğinize emin misiniz? (İşlem geri alınamaz!!!)",
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
            QMessageBox.StandardButton.No,
        )
        if reply == QMessageBox.StandardButton.No:
            QMessageBox.information(
                self,
                "İptal Edildi",
                "Dosyanın tüm değişikliklerini eski haline getirme işlemi iptal edildi.",
            )
            return
        GitHelper.git_restore(self.parent.repo_path, self.file_name)
        if self.is_staged:
            self.parent.removeFileItem(self.parent.stagedList, self.file_name)
        else:
            self.parent.removeFileItem(self.parent.unstagedList, self.file_name)
        QMessageBox.information(
            self,
            "Başarılı!!!",
            f"{self.file_name} dosyasının tüm değişiklikleri orjinal haline getirildi...",
        )

    def onButtonClick(self, git_komutunu_uygula=True):
        if self.is_staged:
            self.parent.removeFileItem(self.parent.stagedList, self.file_name)
            self.parent.addFileItem(
                self.parent.unstagedList, self.file_name, is_staged=not self.is_staged
            )
            if git_komutunu_uygula:
                GitHelper.git_reset(self.parent.repo_path, self.file_name)
        else:
            self.parent.removeFileItem(self.parent.unstagedList, self.file_name)
            self.parent.addFileItem(
                self.parent.stagedList, self.file_name, is_staged=not self.is_staged
            )
            if git_komutunu_uygula:
                GitHelper.git_add(self.parent.repo_path, self.file_name)

    def showGitDiff(self):
        original_content = GitHelper.get_file_content_at_commit(
            self.parent.repo_path, self.file_name, "main"
        )
        modified_content = GitHelper.get_file_content_at_commit(
            self.parent.repo_path, self.file_name, "WORKING"
        )

        diffWindow = DiffWindow(
            original_content,
            modified_content,
            self,
        )
        diffWindow.show()


class DiffWindow(QDialog):
    def __init__(self, original_text, modified_text, parent=None):
        super().__init__(parent)
        self.setModal(True)
        self.setWindowTitle("FARK Penceresi")
        original_layout = QVBoxLayout()
        modified_layout = QVBoxLayout()
        original_label = QLabel("Orjinal Hali")
        modified_label = QLabel("Değişmiş Hali")
        modified_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        original_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        original_layout.addWidget(original_label)
        modified_layout.addWidget(modified_label)
        self.original_text_edit = QTextEdit()
        self.modified_text_edit = QTextEdit()

        self.original_text_edit.setReadOnly(True)
        self.modified_text_edit.setReadOnly(True)

        layout = QHBoxLayout()
        original_layout.addWidget(self.original_text_edit)
        modified_layout.addWidget(self.modified_text_edit)
        layout.addLayout(original_layout)
        layout.addLayout(modified_layout)
        self.setLayout(layout)

        self.show_diff(original_text, modified_text)

    def show_diff(self, original_text, modified_text):
        diff = difflib.ndiff(
            original_text.splitlines(keepends=True),
            modified_text.splitlines(keepends=True),
        )

        original_display = ""
        modified_display = ""

        for line in diff:
            if line.startswith("-"):
                original_display += f'<span style="background-color: #FFCCCC;">{line[2:].rstrip()}</span><br>'
            elif line.startswith("+"):
                modified_display += f'<span style="background-color: #CCFFCC;">{line[2:].rstrip()}</span><br>'

        self.original_text_edit.setHtml(original_display)
        self.modified_text_edit.setHtml(modified_display)
