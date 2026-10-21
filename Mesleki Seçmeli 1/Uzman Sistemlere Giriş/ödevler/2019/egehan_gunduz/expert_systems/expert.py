# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'expert.ui'
#
# Created by: PyQt5 UI code generator 5.10.1
#
# WARNING! All changes made in this file will be lost!


import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import pickle

from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import QTableWidgetItem
from PyQt5.QtCore import Qt

from sklearn import preprocessing


class Ui_MainWindow(object):

    #this function was created by qt designer(pyuic5 expert.ui -o expert.py)
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(800, 600)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.tablo = QtWidgets.QTableWidget(self.centralwidget)
        self.tablo.setGeometry(QtCore.QRect(20, 280, 361, 281))
        self.tablo.setObjectName("tableWidget")
        self.tablo.setColumnCount(0)
        self.tablo.setRowCount(0)
        self.result = QtWidgets.QTextEdit(self.centralwidget)
        self.result.setGeometry(QtCore.QRect(590, 490, 201, 71))
        self.result.setObjectName("textEdit")
        self.layoutWidget = QtWidgets.QWidget(self.centralwidget)
        self.layoutWidget.setGeometry(QtCore.QRect(20, 210, 561, 61))
        self.layoutWidget.setObjectName("layoutWidget")
        self.horizontalLayout = QtWidgets.QHBoxLayout(self.layoutWidget)
        self.horizontalLayout.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.logistic = QtWidgets.QRadioButton(self.layoutWidget)
        self.logistic.setObjectName("radioButton_2")
        self.horizontalLayout.addWidget(self.logistic)
        self.svm = QtWidgets.QRadioButton(self.layoutWidget)
        self.svm.setObjectName("radioButton")
        self.horizontalLayout.addWidget(self.svm)
        self.mlp = QtWidgets.QRadioButton(self.layoutWidget)
        self.mlp.setObjectName("radioButton_3")
        self.horizontalLayout.addWidget(self.mlp)
        self.knn = QtWidgets.QRadioButton(self.layoutWidget)
        self.knn.setObjectName("radioButton_4")
        self.horizontalLayout.addWidget(self.knn)
        self.lda = QtWidgets.QRadioButton(self.layoutWidget)
        self.lda.setObjectName("radioButton_5")
        self.horizontalLayout.addWidget(self.lda)
        self.layoutWidget1 = QtWidgets.QWidget(self.centralwidget)
        self.layoutWidget1.setGeometry(QtCore.QRect(590, 280, 201, 191))
        self.layoutWidget1.setObjectName("layoutWidget1")
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout(self.layoutWidget1)
        self.horizontalLayout_2.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout()
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.label = QtWidgets.QLabel(self.layoutWidget1)
        self.label.setObjectName("label")
        self.verticalLayout_2.addWidget(self.label)
        self.label_3 = QtWidgets.QLabel(self.layoutWidget1)
        self.label_3.setObjectName("label_3")
        self.verticalLayout_2.addWidget(self.label_3)
        self.label_5 = QtWidgets.QLabel(self.layoutWidget1)
        self.label_5.setObjectName("label_5")
        self.verticalLayout_2.addWidget(self.label_5)
        self.label_4 = QtWidgets.QLabel(self.layoutWidget1)
        self.label_4.setObjectName("label_4")
        self.verticalLayout_2.addWidget(self.label_4)
        self.horizontalLayout_2.addLayout(self.verticalLayout_2)
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.accuracy_Edit = QtWidgets.QTextEdit(self.layoutWidget1)
        self.accuracy_Edit.setObjectName("textEdit_3")
        self.verticalLayout.addWidget(self.accuracy_Edit)
        self.precision_Edit = QtWidgets.QTextEdit(self.layoutWidget1)
        self.precision_Edit.setObjectName("textEdit_6")
        self.verticalLayout.addWidget(self.precision_Edit)
        self.recall_Edit = QtWidgets.QTextEdit(self.layoutWidget1)
        self.recall_Edit.setObjectName("textEdit_5")
        self.verticalLayout.addWidget(self.recall_Edit)
        self.f1score_Edit = QtWidgets.QTextEdit(self.layoutWidget1)
        self.f1score_Edit.setObjectName("textEdit_4")
        self.verticalLayout.addWidget(self.f1score_Edit)
        self.horizontalLayout_2.addLayout(self.verticalLayout)
        self.karisiklikmatrisi = QtWidgets.QLabel(self.centralwidget)
        self.karisiklikmatrisi.setGeometry(QtCore.QRect(388, 280, 191, 281))
        self.karisiklikmatrisi.setMinimumSize(QtCore.QSize(189, 219))
        self.karisiklikmatrisi.setObjectName("quickWidget_2")
        self.layoutWidget_4 = QtWidgets.QWidget(self.centralwidget)
        self.layoutWidget_4.setGeometry(QtCore.QRect(100, 20, 691, 20))
        self.layoutWidget_4.setObjectName("layoutWidget_4")
        self.horizontalLayout_12 = QtWidgets.QHBoxLayout(self.layoutWidget_4)
        self.horizontalLayout_12.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout_12.setObjectName("horizontalLayout_12")
        self.label_18 = QtWidgets.QLabel(self.layoutWidget_4)
        self.label_18.setObjectName("label_18")
        self.horizontalLayout_12.addWidget(self.label_18)
        self.label_13 = QtWidgets.QLabel(self.layoutWidget_4)
        self.label_13.setObjectName("label_13")
        self.horizontalLayout_12.addWidget(self.label_13)
        self.label_14 = QtWidgets.QLabel(self.layoutWidget_4)
        self.label_14.setObjectName("label_14")
        self.horizontalLayout_12.addWidget(self.label_14)
        self.label_15 = QtWidgets.QLabel(self.layoutWidget_4)
        self.label_15.setObjectName("label_15")
        self.horizontalLayout_12.addWidget(self.label_15)
        self.label_16 = QtWidgets.QLabel(self.layoutWidget_4)
        self.label_16.setObjectName("label_16")
        self.horizontalLayout_12.addWidget(self.label_16)
        self.label_17 = QtWidgets.QLabel(self.layoutWidget_4)
        self.label_17.setObjectName("label_17")
        self.horizontalLayout_12.addWidget(self.label_17)
        self.resetButton = QtWidgets.QPushButton(self.centralwidget)
        self.resetButton.setGeometry(QtCore.QRect(590, 210, 201, 31))
        self.resetButton.setObjectName("pushButton")
        self.runButton = QtWidgets.QPushButton(self.centralwidget)
        self.runButton.setGeometry(QtCore.QRect(590, 240, 201, 31))
        self.runButton.setObjectName("pushButton_2")
        self.widget = QtWidgets.QWidget(self.centralwidget)
        self.widget.setGeometry(QtCore.QRect(30, 180, 711, 23))
        self.widget.setObjectName("widget")
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout(self.widget)
        self.horizontalLayout_3.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.credit_limit = QtWidgets.QLineEdit(self.widget)
        self.credit_limit.setObjectName("lineEdit_5")
        self.horizontalLayout_3.addWidget(self.credit_limit)
        self.sex = QtWidgets.QLineEdit(self.widget)
        self.sex.setObjectName("lineEdit_4")
        self.horizontalLayout_3.addWidget(self.sex)
        self.age = QtWidgets.QLineEdit(self.widget)
        self.age.setObjectName("lineEdit_3")
        self.horizontalLayout_3.addWidget(self.age)
        self.education = QtWidgets.QLineEdit(self.widget)
        self.education.setObjectName("lineEdit_2")
        self.horizontalLayout_3.addWidget(self.education)
        self.marriage = QtWidgets.QLineEdit(self.widget)
        self.marriage.setObjectName("lineEdit")
        self.horizontalLayout_3.addWidget(self.marriage)
        self.widget1 = QtWidgets.QWidget(self.centralwidget)
        self.widget1.setGeometry(QtCore.QRect(30, 46, 761, 97))
        self.widget1.setObjectName("widget1")
        self.verticalLayout_3 = QtWidgets.QVBoxLayout(self.widget1)
        self.verticalLayout_3.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.horizontalLayout_8 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_8.setObjectName("horizontalLayout_8")
        self.label_2 = QtWidgets.QLabel(self.widget1)
        self.label_2.setObjectName("label_2")
        self.horizontalLayout_8.addWidget(self.label_2)
        self.horizontalLayout_4 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_4.setObjectName("horizontalLayout_4")
        self.bill_eylul = QtWidgets.QLineEdit(self.widget1)
        self.bill_eylul.setObjectName("lineEdit_6")
        self.horizontalLayout_4.addWidget(self.bill_eylul)
        self.bill_agustos = QtWidgets.QLineEdit(self.widget1)
        self.bill_agustos.setObjectName("lineEdit_7")
        self.horizontalLayout_4.addWidget(self.bill_agustos)
        self.bill_temmuz = QtWidgets.QLineEdit(self.widget1)
        self.bill_temmuz.setObjectName("lineEdit_8")
        self.horizontalLayout_4.addWidget(self.bill_temmuz)
        self.bill_haziran = QtWidgets.QLineEdit(self.widget1)
        self.bill_haziran.setObjectName("lineEdit_9")
        self.horizontalLayout_4.addWidget(self.bill_haziran)
        self.bill_mayis = QtWidgets.QLineEdit(self.widget1)
        self.bill_mayis.setObjectName("lineEdit_10")
        self.horizontalLayout_4.addWidget(self.bill_mayis)
        self.bill_nisan = QtWidgets.QLineEdit(self.widget1)
        self.bill_nisan.setObjectName("lineEdit_11")
        self.horizontalLayout_4.addWidget(self.bill_nisan)
        self.horizontalLayout_8.addLayout(self.horizontalLayout_4)
        self.verticalLayout_3.addLayout(self.horizontalLayout_8)
        self.horizontalLayout_9 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_9.setObjectName("horizontalLayout_9")
        self.label_6 = QtWidgets.QLabel(self.widget1)
        self.label_6.setObjectName("label_6")
        self.horizontalLayout_9.addWidget(self.label_6)
        self.horizontalLayout_5 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_5.setObjectName("horizontalLayout_5")
        self.payment_eylul = QtWidgets.QLineEdit(self.widget1)
        self.payment_eylul.setObjectName("lineEdit_12")
        self.horizontalLayout_5.addWidget(self.payment_eylul)
        self.payment_agustos = QtWidgets.QLineEdit(self.widget1)
        self.payment_agustos.setObjectName("lineEdit_13")
        self.horizontalLayout_5.addWidget(self.payment_agustos)
        self.payment_temmuz = QtWidgets.QLineEdit(self.widget1)
        self.payment_temmuz.setObjectName("lineEdit_14")
        self.horizontalLayout_5.addWidget(self.payment_temmuz)
        self.payment_haziran = QtWidgets.QLineEdit(self.widget1)
        self.payment_haziran.setObjectName("lineEdit_15")
        self.horizontalLayout_5.addWidget(self.payment_haziran)
        self.payment_mayis = QtWidgets.QLineEdit(self.widget1)
        self.payment_mayis.setObjectName("lineEdit_16")
        self.horizontalLayout_5.addWidget(self.payment_mayis)
        self.payment_nisan = QtWidgets.QLineEdit(self.widget1)
        self.payment_nisan.setObjectName("lineEdit_17")
        self.horizontalLayout_5.addWidget(self.payment_nisan)
        self.horizontalLayout_9.addLayout(self.horizontalLayout_5)
        self.verticalLayout_3.addLayout(self.horizontalLayout_9)
        self.horizontalLayout_10 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_10.setObjectName("horizontalLayout_10")
        self.label_7 = QtWidgets.QLabel(self.widget1)
        self.label_7.setObjectName("label_7")
        self.horizontalLayout_10.addWidget(self.label_7)
        self.horizontalLayout_7 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_7.setObjectName("horizontalLayout_7")
        self.time_eylul = QtWidgets.QLineEdit(self.widget1)
        self.time_eylul.setObjectName("lineEdit_24")
        self.horizontalLayout_7.addWidget(self.time_eylul)
        self.time_agustos = QtWidgets.QLineEdit(self.widget1)
        self.time_agustos.setObjectName("lineEdit_25")
        self.horizontalLayout_7.addWidget(self.time_agustos)
        self.time_temmuz = QtWidgets.QLineEdit(self.widget1)
        self.time_temmuz.setObjectName("lineEdit_26")
        self.horizontalLayout_7.addWidget(self.time_temmuz)
        self.time_haziran = QtWidgets.QLineEdit(self.widget1)
        self.time_haziran.setObjectName("lineEdit_27")
        self.horizontalLayout_7.addWidget(self.time_haziran)
        self.time_mayis = QtWidgets.QLineEdit(self.widget1)
        self.time_mayis.setObjectName("lineEdit_28")
        self.horizontalLayout_7.addWidget(self.time_mayis)
        self.time_nisan = QtWidgets.QLineEdit(self.widget1)
        self.time_nisan.setObjectName("lineEdit_29")
        self.horizontalLayout_7.addWidget(self.time_nisan)
        self.horizontalLayout_10.addLayout(self.horizontalLayout_7)
        self.verticalLayout_3.addLayout(self.horizontalLayout_10)
        self.widget2 = QtWidgets.QWidget(self.centralwidget)
        self.widget2.setGeometry(QtCore.QRect(30, 160, 745, 18))
        self.widget2.setObjectName("widget2")
        self.horizontalLayout_11 = QtWidgets.QHBoxLayout(self.widget2)
        self.horizontalLayout_11.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout_11.setObjectName("horizontalLayout_11")
        self.label_8 = QtWidgets.QLabel(self.widget2)
        self.label_8.setObjectName("label_8")
        self.horizontalLayout_11.addWidget(self.label_8)
        self.label_12 = QtWidgets.QLabel(self.widget2)
        self.label_12.setObjectName("label_12")
        self.horizontalLayout_11.addWidget(self.label_12)
        self.label_9 = QtWidgets.QLabel(self.widget2)
        self.label_9.setObjectName("label_9")
        self.horizontalLayout_11.addWidget(self.label_9)
        self.label_10 = QtWidgets.QLabel(self.widget2)
        self.label_10.setObjectName("label_10")
        self.horizontalLayout_11.addWidget(self.label_10)
        self.label_11 = QtWidgets.QLabel(self.widget2)
        self.label_11.setObjectName("label_11")
        self.horizontalLayout_11.addWidget(self.label_11)
        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        #set functions to buttons
        #readfile to table function shows the dataset in the interface
        self.readfiletotable()
        self.logistic.setChecked(True) #default check for initializing
        self.runButton.clicked.connect(self.hesapla)
        self.resetButton.clicked.connect(self.set_defaults)
        self.set_defaults()


        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    #this function was created by qt designer(pyuic5 expert.ui -o expert.py)
    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.logistic.setText(_translate("MainWindow", "Logistic Regresssion"))
        self.svm.setText(_translate("MainWindow", "SVM"))
        self.mlp.setText(_translate("MainWindow", "MLP"))
        self.knn.setText(_translate("MainWindow", "KNN"))
        self.lda.setText(_translate("MainWindow", "LDA"))
        self.label.setText(_translate("MainWindow", "Accuracy"))
        self.label_3.setText(_translate("MainWindow", "Precision"))
        self.label_5.setText(_translate("MainWindow", "Recall"))
        self.label_4.setText(_translate("MainWindow", "F1 Score"))
        self.label_18.setText(_translate("MainWindow", "Eylül"))
        self.label_13.setText(_translate("MainWindow", "Ağustos"))
        self.label_14.setText(_translate("MainWindow", "Temmuz"))
        self.label_15.setText(_translate("MainWindow", "Haziran"))
        self.label_16.setText(_translate("MainWindow", "Mayıs"))
        self.label_17.setText(_translate("MainWindow", "Nisan"))
        self.resetButton.setText(_translate("MainWindow", "Sıfırla"))
        self.runButton.setText(_translate("MainWindow", "Sınıflandır"))
        self.label_2.setText(_translate("MainWindow", " Borç       "))
        self.label_6.setText(_translate("MainWindow", "Ödenen  "))
        self.label_7.setText(_translate("MainWindow", "Zaman    "))
        self.label_8.setText(_translate("MainWindow", "Kredi Kartı Limiti          "))
        self.label_12.setText(_translate("MainWindow", "Cinsiyet(E-1 K-2)         "))
        self.label_9.setText(_translate("MainWindow", "Yaş                             "))
        self.label_10.setText(_translate("MainWindow", "Eğitim(1-4)                   "))
        self.label_11.setText(_translate("MainWindow", "Evlilik durumu(E-1 H-2 D-3)"))

    #set default values for initializing
    def set_defaults(self):
        self.credit_limit.setText("10000")
        self.sex.setText("1")
        self.education.setText("2")
        self.marriage.setText("2")
        self.age.setText("23")
        self.time_eylul.setText("2")
        self.time_agustos.setText("2")
        self.time_temmuz.setText("-1")
        self.time_haziran.setText("1")
        self.time_mayis.setText("-2")
        self.time_nisan.setText("3")
        self.bill_eylul.setText("4000")
        self.bill_agustos.setText("2000")
        self.bill_temmuz.setText("500")
        self.bill_haziran.setText("0")
        self.bill_mayis.setText("100")
        self.bill_nisan.setText("0")
        self.payment_eylul.setText("2000")
        self.payment_agustos.setText("300")
        self.payment_temmuz.setText("150")
        self.payment_haziran.setText("0")
        self.payment_mayis.setText("100")
        self.payment_nisan.setText("0")

    #read and write file to table to show the user
    def readfiletotable(self):
        self.data = pd.read_csv("UCI_Credit_Card.csv")
        satir_sayisi=self.data.shape[0]
        sutun_sayisi=self.data.shape[1]
        kolonlar = self.data.columns.values.tolist()
        self.tablo.setRowCount(1)
        self.tablo.setColumnCount(sutun_sayisi)
        self.tablo.setHorizontalHeaderLabels(kolonlar)
        for i in range(1,int(satir_sayisi/100)+1):
            for j in range(1,sutun_sayisi+1):
                item = QTableWidgetItem(str(self.data.iloc[i-1][j-1]))
                item.setFlags(Qt.ItemIsEnabled)
                self.tablo.setItem(i-1,j-1, item)
            self.tablo.setRowCount(i+1)
        self.tablo.setRowCount(i)

    #create time statistics for user entered data
    def add_pay_statistics(self,X):
        X["avg_pay"] = X.iloc[:,5:11].mean(axis=1)
        X["std_pay"] = X.iloc[:,5:11].std(axis=1)
        return X

    #create bill statistics for user entered data
    def add_bill_statistics(self,X):
        X["avg_bill"] = X.iloc[:,12:18].mean(axis=1)
        X["std_bill"] = X.iloc[:,12:18].std(axis=1)
        return X

    #create payment statistic for user entered data
    def add_payment_statistics(self,X):
        X["avg_payment"] = X.iloc[:,18:24].mean(axis=1)
        X["std_payment"] = X.iloc[:,18:24].std(axis=1)
        return X

    #get all of the values entered by user
    def get_values(self):
        values=[]
        values.append(int(self.credit_limit.text()))
        values.append(int(self.sex.text()))
        values.append(int(self.education.text()))
        values.append(int(self.marriage.text()))
        values.append(int(self.age.text()))
        values.append(int(self.time_eylul.text()))
        values.append(int(self.time_agustos.text()))
        values.append(int(self.time_temmuz.text()))
        values.append(int(self.time_haziran.text()))
        values.append(int(self.time_mayis.text()))
        values.append(int(self.time_nisan.text()))
        values.append(int(self.bill_eylul.text()))
        values.append(int(self.bill_agustos.text()))
        values.append(int(self.bill_temmuz.text()))
        values.append(int(self.bill_haziran.text()))
        values.append(int(self.bill_mayis.text()))
        values.append(int(self.bill_nisan.text()))
        values.append(int(self.payment_eylul.text()))
        values.append(int(self.payment_agustos.text()))
        values.append(int(self.payment_temmuz.text()))
        values.append(int(self.payment_haziran.text()))
        values.append(int(self.payment_mayis.text()))
        values.append(int(self.payment_nisan.text()))
        values = pd.DataFrame(values).T
        values = self.add_pay_statistics(values)
        values = self.add_bill_statistics(values)
        values = self.add_payment_statistics(values)

        return values

    #check for radio buttons
    def hesapla(self):
        if self.logistic.isChecked():
            name = 'Logistic Regression'
        elif self.svm.isChecked():
            name ='SVM'
        elif self.mlp.isChecked():
            name = 'MLP'
        elif self.knn.isChecked():
            name = 'K-NN'
        else:
            name = 'LDA'

        #assing file name in order to read the necessary files
        model_filename = name + ".sav"
        cm_value_filename = name + "_value_cm.txt"
        cm_filename = name + "_cm.png"

        #read necessary files
        model = pickle.load(open(model_filename, 'rb'))
        with open(cm_value_filename, "rb") as fp:
            cm_values=pickle.load(fp)
        cm_image = plt.imread(cm_filename)

        #get user values
        values = self.get_values()
        values = values.astype('float64')
        scaler = preprocessing.StandardScaler()
        values = pd.DataFrame(scaler.fit_transform(np.array(values).reshape(-1,1))).T

        #predict the user payment
        prediction = model.predict(values)

        #for choosen model, metrics were saved as txt file
        #load them in order: 1-accuracy 2-precision 3-recall 4-f1 score
        self.accuracy_Edit.setPlainText(str(round(cm_values[0],4)))
        self.precision_Edit.setPlainText(str(round(cm_values[1],4)))
        self.recall_Edit.setPlainText(str(round(cm_values[2],4)))
        self.f1score_Edit.setPlainText(str(round(cm_values[3],4)))
        print("Prediction: " + str(prediction))
        if prediction[0] == 1:
            self.result.setPlainText(str("Paid"))
        else:
            self.result.setPlainText(str("Not paid"))

        #show confusion matrix as an image
        self.karisiklikmatrisi.setPixmap(QtGui.QPixmap(cm_filename))
        self.karisiklikmatrisi.setScaledContents(True)



if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())

