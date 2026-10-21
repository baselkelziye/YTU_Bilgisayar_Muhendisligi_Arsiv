from PyQt5.QtWidgets import *
import sys

class showWindow(QDialog):
    def __init__(self, music_list):
        super().__init__()
        self.setWindowTitle("Results")
        self.setGeometry(350, 150, 400, 400)

        table = QTableWidget()
        tableItem = QTableWidgetItem()
        table.setWindowTitle("recomended musics")
        table.setRowCount(10)
        table.setColumnCount(1)

        table.setItem(0, 0, QTableWidgetItem(music_list[0]))
        table.setItem(1, 0, QTableWidgetItem(music_list[1]))
        table.setItem(2, 0, QTableWidgetItem(music_list[2]))
        table.setItem(3, 0, QTableWidgetItem(music_list[3]))
        table.setItem(4, 0, QTableWidgetItem(music_list[4]))
        table.setItem(5, 0, QTableWidgetItem(music_list[5]))
        table.setItem(6, 0, QTableWidgetItem(music_list[6]))
        table.setItem(7, 0, QTableWidgetItem(music_list[7]))
        table.setItem(8, 0, QTableWidgetItem(music_list[8]))
        table.setItem(9, 0, QTableWidgetItem(music_list[9]))

        table.horizontalHeader().setStretchLastSection(True)
        table.show()
        self.setLayout(QVBoxLayout())
        self.layout().addWidget(table)
        #dialog.exec()



if __name__=='__main__':
    App = QApplication(sys.argv)
    obje = showWindow(["1","2",3,4,5,6,7,8,9,10])
    obje.exec()
    sys.exit(App.exec_())