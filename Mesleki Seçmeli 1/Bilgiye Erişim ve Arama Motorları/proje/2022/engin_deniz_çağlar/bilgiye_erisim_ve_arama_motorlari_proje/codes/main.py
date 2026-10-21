from dropdown import *
from ml import *
import sys

class infoRet(Ui_MainWindow):
    def __init__(self,window):
        self.setupUi(window)
        self.trainButton.clicked.connect(self.apply)

    def apply(self):
        train = self.trainInput.text()
        index = self.comboBox.currentIndex()
        metrics= classify(train, index)
        self.funcOutput.setText(metrics)
        self.confMat.setPixmap(QtGui.QPixmap("conf.png"))



if __name__ == '__main__':
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = infoRet(MainWindow)
    MainWindow.show()
    app.exec_()
