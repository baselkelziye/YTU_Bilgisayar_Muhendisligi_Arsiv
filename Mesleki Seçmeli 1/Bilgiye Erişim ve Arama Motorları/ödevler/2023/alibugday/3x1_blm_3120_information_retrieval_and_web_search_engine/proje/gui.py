import sys
from PyQt5.QtWidgets import *
from Kmeans_gui import AnotherWindow
import pandas as pd
from KMeans import *
from visual import *
from showResult import showWindow

class Window(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Music Recomandation System")
        self.setGeometry(350,150,400,400)
        self.UI()

    def UI(self):
        mainLayout=QVBoxLayout()
        topLayout=QVBoxLayout()
        bottomLayout=QHBoxLayout()
        mainLayout.addLayout(topLayout)
        mainLayout.addLayout(bottomLayout)

        self.label = QLabel("Muzik oneri sistemi")
        self.label.setContentsMargins(250,0,0,0)
        self.combo = QComboBox()
        self.combo.setContentsMargins(150, 0, 0, 0)
        self.btn1 = QPushButton("Collobrative")
        self.btn2 = QPushButton("Content based")
        self.btn1.clicked.connect(self.islem_1)
        self.btn2.clicked.connect(self.islem_2)



        self.dataset = pd.read_csv("data.csv")
        self.dataset = self.dataset.head(20000)
        self.dataset = self.dataset.sort_values(by=["popularity"]).tail(1000)
        name_and_year = ["name", "year"]
        self.df = self.dataset[name_and_year]
        names = self.df["name"]
        names = names.values.tolist()
        self.combo.addItems(names)

        #topLayout.setContentsMargins(150,10,150,10) #left,top,right,bottom
        topLayout.addWidget(self.label)
        topLayout.addWidget(self.combo)

        bottomLayout.setContentsMargins(150,10,150,10)
        bottomLayout.addWidget(self.btn1)
        bottomLayout.addWidget(self.btn2)
        #bottomLayout.addWidget(btn1)

        self.setLayout(mainLayout)


        self.show()

    def islem_1(self, checked):
        name = self.combo.currentText()
        self.df_i = self.df[self.df["name"] == name]
        name = self.df_i.values.tolist()

        obje = Kmeans("data.csv")
        results = obje.Music_Recommender([{'name': name[0][0], 'year': name[0][1]}])
        print(type(results))
        results=results.values.tolist()
        print(results[1][1])
        print(results)
        music_names = []


        for music in results:
            music_names.append(music[1])

        print(music_names)
        obje1=showWindow(music_names)

        obje1.exec()

    def islem_2(self, s):
        name = self.combo.currentText()
        self.df_i = self.df[self.df["name"] == name]
        name = self.df_i.values.tolist()
        obje = Cosine_simliarity()
        print(name[0][0])

        obje1 = showWindow(obje.generate_recommendation(name[0][0]).values)

        obje1.exec()

def main():
    App=QApplication(sys.argv)
    window = Window()
    sys.exit(App.exec_())

if __name__=='__main__':
    main()