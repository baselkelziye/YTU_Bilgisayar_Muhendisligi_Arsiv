import subprocess
from PyQt5.QtCore import QThread, pyqtSignal
class CommandRunnerThread(QThread):
    progress = pyqtSignal(int)
    finished = pyqtSignal()

    def run(self):
        commands = [
            ('cd ../google_forum_islemleri', False),
            ('python3 hoca_icerikleri_guncelle.py', True),
            ('python3 ders_icerikleri_guncelle.py', True),
            ('cd ..', False),
            ('python3 readme_olustur.py', True),
            ('cd readme_guncelleme_arayuzu_python', False)
        ]

        total_commands = len([cmd for cmd, is_script in commands if is_script])
        completed_commands = 0

        for command, is_script in commands:
            if is_script:
                self.progress.emit(int((completed_commands / total_commands) * 100))
                subprocess.run(command, shell=True)
                completed_commands += 1
            else:
                subprocess.run(command, shell=True)

        self.progress.emit(100)
        self.finished.emit()
