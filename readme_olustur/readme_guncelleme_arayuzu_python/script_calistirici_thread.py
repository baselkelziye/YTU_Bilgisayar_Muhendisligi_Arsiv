import subprocess
from PyQt5.QtCore import QThread, pyqtSignal
class ScriptRunnerThread(QThread):
    finished = pyqtSignal()
    error = pyqtSignal(str)

    def __init__(self, paths):
        QThread.__init__(self)
        self.google_forum_islemleri_path, self.readme_olustur_path = paths

    def run(self):
        try:
            subprocess.run('python3 hoca_icerikleri_guncelle.py\n', shell=True, cwd=self.google_forum_islemleri_path)
            subprocess.run('python3 ders_icerikleri_guncelle.py\n', shell=True, cwd=self.google_forum_islemleri_path)
            subprocess.run('python3 readme_olustur.py\n', shell=True, cwd=self.readme_olustur_path)
            self.finished.emit()
        except subprocess.CalledProcessError as e:
            self.error.emit(str(e))
