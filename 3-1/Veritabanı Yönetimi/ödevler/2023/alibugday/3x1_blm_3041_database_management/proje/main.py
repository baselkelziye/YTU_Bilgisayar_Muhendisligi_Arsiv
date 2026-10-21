#nursing managment system
#Ali Bugay
#date created:24.12.2022
#date modified:17.01.2023

import sys,sqlite3,time


from PyQt5 import QtGui
from PyQt5.QtWidgets import QTableWidgetItem,QTableWidget,QComboBox,QVBoxLayout,QGridLayout,QDialog,QWidget, QPushButton, QApplication, QMainWindow,QAction,QMessageBox,QLabel,QTextEdit,QProgressBar,QLineEdit
from PyQt5.QtCore import QCoreApplication
import psycopg2
from datetime import datetime
import ast

class DbManage():
    def __init__(self):
        self.conn = psycopg2.connect(
            host="localhost",
            database="nursery_db",
            user="postgres",
            password="1235789ila")
        self.c = self.conn.cursor()
        self.c.execute("CREATE TABLE IF NOT EXISTS teachers(teacher_id INTEGER CHECK (teacher_id >= 2 AND teacher_id <=5) PRIMARY KEY, name char(20), surname char(20), total_student INTEGER CHECK (total_student <= 30))")
        self.c.execute(
            """CREATE TABLE IF NOT EXISTS child (
  std_id integer PRIMARY KEY,
  fname char(20),
  lname char(20),
  age INTEGER CHECK (age >=2 AND age <= 5) REFERENCES teachers(teacher_id),
  full_or_part char(20),
  gender char(1)
)""")

        self.c.execute("CREATE TABLE IF NOT EXISTS payments(payment_id INTEGER PRIMARY KEY REFERENCES child(std_id) ON DELETE CASCADE, fee INTEGER, reciept_date DATE)")
        self.c.execute("CREATE TABLE IF NOT EXISTS dependent(dependent_id INTEGER REFERENCES child(std_id) ON DELETE CASCADE, name char(20), surname char(20), tel char(12), dependency char(20))")

        self.c.execute("""CREATE SEQUENCE IF NOT EXISTS mysequence
                        INCREMENT 1
                        START 1;""")

        self.c.execute("""
        CREATE OR REPLACE FUNCTION calculate_meal(out kahvalti INTEGER, out oglenYemegi INTEGER) AS $$
        
        DECLARE
            sabahci INTEGER;
            oglenci INTEGER;
            tumGun INTEGER;
        BEGIN
            select count(*) into sabahci
			from child
			group by full_or_part
			having full_or_part = 'sabahci';
            
            select count(*) INTO oglenci 
            from child
            where full_or_part='oglenci';
            
            select count(*) INTO tumGun 
            from child
            where full_or_part='tumGun';
            
            kahvalti := sabahci + tumGun;
            oglenYemegi := oglenci + tumGun;
        END;
        
        $$LANGUAGE plpgsql;  
        """)

        self.c.execute("""
                CREATE OR REPLACE FUNCTION odeme_yap(id_num INTEGER,miktar INTEGER) RETURNS VOID AS $$

                DECLARE
                    borc INTEGER;
                BEGIN
                    select fee INTO borc
                    from payments
                    where payment_id = id_num;
    
                    borc = borc - miktar;
                     
                    update payments set fee = borc where payment_id = id_num;
                END; 

                $$LANGUAGE plpgsql;   
                """)


        #self.c.execute("insert into payments values(2,250,'24.12.2022')")
        #self.c.execute("SELECT * from payments")
        #self.data = self.c.fetchall()
        #print(self.data)


        #self.c.close()
        #self.conn.commit()
        #self.conn.close()


    def createTrigger(self):
        self.c.execute("""
                    CREATE OR REPLACE FUNCTION trig_inc() RETURNS TRIGGER AS $$
                        BEGIN
                            update teachers set total_student = total_student + 1 where new.age = teacher_id;
                            return new;
                        END;

                        $$LANGUAGE plpgsql;
                """)

        self.c.execute("""
            CREATE TRIGGER increment_student
            AFTER INSERT ON child
            FOR EACH ROW execute procedure trig_inc()
        """)

        self.c.execute("""
                            CREATE OR REPLACE FUNCTION trig_numeric() RETURNS TRIGGER AS $$
                            BEGIN
                                IF new.tel not like '%[^0-9]%' THEN
                                return new;
                                END IF;
                            return null;
                            END;
                            $$LANGUAGE plpgsql;
                        """)
        self.c.execute("""
                    CREATE TRIGGER check_numeric
                    AFTER INSERT ON dependent
                    FOR EACH ROW execute procedure trig_numeric()
                """)

    def addChild(self, fname, lname, age, full_or_part, gender):
        try:

            self.c.execute("SELECT nextval('mysequence')")
            row = self.c.fetchone()
            sequence_value = row[0]

            self.c.execute("INSERT INTO child (std_id, fname, lname, age, full_or_part, gender) VALUES (%s,%s,%s,%s,%s,%s)",(sequence_value,fname, lname, age, full_or_part, gender))

            # ogenciye ait ödeme kaydının oluşturulması
            if (full_or_part == "sabahci" or full_or_part == "oglenci"):
                self.addPayment(sequence_value, 250)
            elif (full_or_part == "tumGun"):
                self.addPayment(sequence_value, 500)

            self.conn.commit()
            self.c.close()
            self.conn.close()
            QMessageBox.information(QMessageBox(), 'Successful', 'Cocuk basari ile eklendi.')
        except Exception:
            print(Exception.with_traceback())
            QMessageBox.warning(QMessageBox(), 'Error', 'ekleme islemi basarisiz oldu.')

    def addDependent(self, dependent_id, name, surname, tel, dependent):
        try:
            self.c.execute("INSERT INTO dependent (dependent_id, name, surname, tel, dependency) VALUES (%s,%s,%s,%s,%s)",(dependent_id, name, surname, tel, dependent))
            self.conn.commit()
            self.c.close()
            self.conn.close()
            QMessageBox.information(QMessageBox(), 'Successful', 'ebeveyin basari ile eklendi.')
        except Exception:
            print(Exception.with_traceback())
            QMessageBox.warning(QMessageBox(), 'Error', 'ekleme islemi basarisiz oldu.')

    def addPayment(self, payment_id, fee):
        try:
            now = datetime.now()
            date_time_str = now.strftime("%Y-%m-%d")
            print("flag")
            self.c.execute("INSERT INTO payments (payment_id, fee, reciept_date) VALUES (%s,%s,%s)",(payment_id, fee, date_time_str))
            #self.conn.commit()
            #self.c.close()
            #self.conn.close()
            #QMessageBox.information(QMessageBox(), 'Successful', 'ödeme kaydı basari ile oluşturuldu.')
        except Exception:
            print(Exception.with_traceback())
            #QMessageBox.warning(QMessageBox(), 'Error', 'ödeme kaydı oluşturulamadı.')
    def addTeacher(self, teacher_id, name, surname, total_student):
        try:
            self.c.execute("INSERT INTO teachers (teacher_id, name, surname, total_student) VALUES (%s,%s,%s,%s)",(teacher_id, name, surname, total_student))
            self.conn.commit()
            self.c.close()
            self.conn.close()
            QMessageBox.information(QMessageBox(), 'Successful', 'ogretmen basari ile eklendi.')
        except Exception:
            print(Exception.with_traceback())
            QMessageBox.warning(QMessageBox(), 'Error', 'Ekleme islemi basarisiz oldu.')

    def searchChild(self,id):
        self.c.execute("SELECT * from child WHERE std_id="+str(id))
        self.data=self.c.fetchone()

        if not self.data:
            QMessageBox.warning(QMessageBox(), 'Error', 'bu numarali ogrenci idsi bulunamadi'+str(id))
            return None
        self.list=[]
        for i in range(0,6):
            self.list.append(self.data[i])

        self.c.close()
        self.conn.close()

        showStudent(self.list)

    def deleteChild(self,id):
        try:
            self.c.execute("DELETE FROM child WHERE std_id ="+str(id))
            self.conn.commit()
            self.c.close()
            self.conn.close()
            QMessageBox.information(QMessageBox(), 'Successful', 'Cocuk basari ile silinci.')

        except Exception:
            print(Exception.with_traceback())
            QMessageBox.warning(QMessageBox(), 'Error', 'silme islemi basarisiz oldu.')

    def updatePayment(self, student_id, miktar):
        try:
            self.c.execute("select odeme_yap(%s, %s)",(student_id, miktar))
            self.conn.commit()
            self.c.close()
            self.conn.close()
            QMessageBox.information(QMessageBox(), 'Successful', 'odeme basarili.')

        except Exception:
            print(Exception.with_traceback())
            QMessageBox.warning(QMessageBox(), 'Error', 'silme islemi basarisiz oldu.')
    def calculate_meal(self):
        try:
            self.c.execute("SELECT calculate_meal()")
            row = self.c.fetchone()
            sequence_value = row[0]
            tuple_list = ast.literal_eval(sequence_value)
            return tuple_list
        except Exception:
            print(Exception.with_traceback())
            QMessageBox.warning(QMessageBox(), 'Error', 'yemek hesaplama işlemi basarizis oldu.')

    def ilk_defa_calistir(self):
        try:
            self.c.execute("insert into teachers values (2, 'ikinci', 'sinif', 0)")
            self.c.execute("insert into teachers values (3, 'ucuncu', 'sinif', 0)")
            self.c.execute("insert into teachers values (4, 'dorduncu', 'sinif', 0)")
            self.c.execute("insert into teachers values (5, 'besinci', 'sinif', 0)")
            self.c.execute(
                "CREATE TYPE ogrenciler AS (isim varchar(20), soyisim varchar(20), fee integer, enrolled_date DATE);")

            self.c.execute("""
                    CREATE OR REPLACE FUNCTION calculate_record() RETURNS ogrenciler[]  AS $$

                    DECLARE
                        ogrs ogrenciler[];
                        i INTEGER;
                        kayit_gecersiz CURSOR FOR
                        select y.fname, y.lname, y.fee, y.reciept_date
                        from yarim_gun y, tam_gun tam
                        where y.fee = 250 and tam.fee = 500
                        union
                        select fname, lname, fee, reciept_date
                        from ogrenciler_view
                        where (EXTRACT (YEAR FROM reciept_date) + 1) < EXTRACT (YEAR FROM CURRENT_DATE);
                    BEGIN
                        i = 1;
                        create or replace view ogrenciler_view as
                        select fname, lname, fee, reciept_date  
                        from child, payments
                        where std_id = payment_id;

                        create or replace view yarim_gun as
                        select fname, lname, fee, reciept_date 
                        from child, payments
                        where full_or_part <> 'tumGun' and std_id = payment_id;

                        create or replace view tam_gun as
                        select fname, lname, fee, reciept_date 
                        from child, payments
                        where full_or_part = 'tumGun' and std_id = payment_id;


                        FOR kayit IN kayit_gecersiz LOOP
                            ogrs[i] = kayit;
                            i = i + 1;
                            END LOOP;
                        RETURN ogrs;

                    END;

                    $$LANGUAGE plpgsql;  
                    """)

            self.createTrigger()

            self.c.close()
            self.conn.commit()
            self.conn.close()
            QMessageBox.information(QMessageBox(), 'Successful', 'Veritabani hazırlandı.')

        except Exception:
            print(Exception.with_traceback())
            QMessageBox.warning(QMessageBox(), 'Error', 'Veritabanı Hazırlama işlemi basarisiz.')

    def kaydi_onaylanmayanlari_hesapla(self):

        self.c.execute("SELECT calculate_record()")

        kayitlar = self.c.fetchall()

        kayit = kayitlar[0][0]

        print(kayit)

def showStudent(list):
    std_id = 0
    fname = ""
    lname = ""
    pymt_id = -1
    dpn_id = -1
    age = -1
    full_or_part = ""
    gender = ""

    print("flag")
    std_id = list[0]
    fname = list[1]
    lname = list[2]
    age = list[3]
    full_or_part = list[4]
    gender = list[5]
    print("flag")

    table = QTableWidget()
    tableItem = QTableWidgetItem()
    table.setWindowTitle("cocuk detay")
    table.setRowCount(6)
    table.setColumnCount(2)

    table.setItem(0, 0, QTableWidgetItem("id"))
    table.setItem(0, 1, QTableWidgetItem(str(std_id)))
    table.setItem(1, 0, QTableWidgetItem("adi"))
    table.setItem(1, 1, QTableWidgetItem(fname))
    table.setItem(2, 0, QTableWidgetItem("soyadi"))
    table.setItem(2, 1, QTableWidgetItem(lname))
    table.setItem(3, 0, QTableWidgetItem("yasi"))
    table.setItem(3, 1, QTableWidgetItem(str(age)))
    table.setItem(4, 0, QTableWidgetItem("gün"))
    table.setItem(4, 1, QTableWidgetItem(full_or_part))
    table.setItem(5, 0, QTableWidgetItem("cinsiyet:"))
    table.setItem(5, 1, QTableWidgetItem(gender))
    table.horizontalHeader().setStretchLastSection(True)
    table.show()
    dialog = QDialog()
    dialog.setWindowTitle("Child Details")
    dialog.resize(500, 300)
    dialog.setLayout(QVBoxLayout())
    dialog.layout().addWidget(table)
    dialog.exec()

def showMeals(list):
    kahvalti = -1
    oglen_yemegi = -1

    kahvalti = list[0]
    oglen_yemegi = list[1]


    table = QTableWidget()
    tableItem = QTableWidgetItem()
    table.setWindowTitle("meal Details")
    table.setRowCount(2)
    table.setColumnCount(2)

    table.setItem(0, 0, QTableWidgetItem("kahvalti"))
    table.setItem(0, 1, QTableWidgetItem(str(kahvalti)))
    table.setItem(1, 0, QTableWidgetItem("oglen yemegi"))
    table.setItem(1, 1, QTableWidgetItem(str(oglen_yemegi)))

    table.horizontalHeader().setStretchLastSection(True)
    table.show()
    dialog = QDialog()
    dialog.setWindowTitle("meal Details")
    dialog.resize(500, 300)
    dialog.setLayout(QVBoxLayout())
    dialog.layout().addWidget(table)
    dialog.exec()

class AddStudent(QDialog):
    def __init__(self):
        super().__init__()

        #general variables
        self.std_id=-1
        self.fname=''
        self.lname=''
        self.pymt_id=None
        self.dpn_id=None
        self.age=None
        self.full_or_part=''
        self.gender=''


        self.btnCancel=QPushButton("iptal_et",self)
        self.btnReset=QPushButton("sifirla",self)
        self.btnAdd=QPushButton("ekle",self)

        self.btnCancel.setFixedHeight(30)
        self.btnReset.setFixedHeight(30)
        self.btnAdd.setFixedHeight(30)

        self.ageCombo=QComboBox(self)
        self.ageCombo.addItem('2')
        self.ageCombo.addItem('3')
        self.ageCombo.addItem('4')
        self.ageCombo.addItem('5')

        self.full_or_partCombo = QComboBox(self)
        self.full_or_partCombo.addItem('sabahci')
        self.full_or_partCombo.addItem('oglenci')
        self.full_or_partCombo.addItem('tumGun')


        self.genderCombo = QComboBox(self)
        self.genderCombo.addItem('M')
        self.genderCombo.addItem('F')



        self.fnameLabel=QLabel("isim")
        self.lnameLabel = QLabel("soyisim")
        self.pymt_idLabel = QLabel("payment no")
        self.dpn_idLabel = QLabel("dep no")
        self.ageLabel = QLabel("age")
        self.full_or_partLabel = QLabel("full veya part")
        self.genderLabel=QLabel("Gender")


        self.fnameText=QLineEdit(self)
        self.lnameText = QLineEdit(self)
        self.pymt_idText = QLineEdit(self)
        self.dpn_idText = QLineEdit(self)

        self.grid=QGridLayout(self)
        self.grid.addWidget(self.fnameLabel,1,1)
        self.grid.addWidget(self.lnameLabel,2,1)
        self.grid.addWidget(self.pymt_idLabel, 3, 1)
        self.grid.addWidget(self.dpn_idLabel, 4, 1)
        self.grid.addWidget(self.ageLabel, 5, 1)
        self.grid.addWidget(self.full_or_partLabel, 6, 1)
        self.grid.addWidget(self.genderLabel,7,1)






        self.grid.addWidget(self.fnameText,1,2)
        self.grid.addWidget(self.lnameText,2,2)
        self.grid.addWidget(self.pymt_idText, 3, 2)
        self.grid.addWidget(self.dpn_idText, 4, 2)
        self.grid.addWidget(self.ageCombo, 5, 2)
        self.grid.addWidget(self.full_or_partCombo, 6, 2)
        self.grid.addWidget(self.genderCombo,7,2)




        #adding three buttons
        self.grid.addWidget(self.btnReset,8,1)
        self.grid.addWidget(self.btnCancel,8,3)
        self.grid.addWidget(self.btnAdd,8,2)

        #button connectors
        self.btnAdd.clicked.connect(self.addchild)
        self.btnCancel.clicked.connect(QApplication.instance().quit)
        self.btnReset.clicked.connect(self.reset)

        self.setLayout(self.grid)
        self.setWindowTitle("Cocuk ekleme")
        self.resize(500,300)
        self.show()
        sys.exit(self.exec())

    def reset(self):

        self.fnameText.setText("")
        self.lnameText.setText("")
        self.pymt_idText.setText("")
        self.dpn_idText.setText("")

    def addchild(self):

        self.gender=self.genderCombo.currentText()
        self.age=self.ageCombo.currentText()
        self.age=int(self.age)
        self.full_or_part=self.full_or_partCombo.currentText()

        self.fname=self.fnameText.text()
        #self.pymt_id=int(self.pymt_idText.text())
        #self.dpn_id=int(self.dpn_idText.text())
        self.lname=self.lnameText.text()
        print(self.lname)
        print(self.gender)

        y=DbManage()
        y.addChild(self.fname,self.lname,self.age,self.full_or_part,self.gender)
        #y.addChild('ali','bug',None,None,None,'tumGun','M')

class AddDependent(QDialog):
    def __init__(self):
        super().__init__()

        #general variables
        self.std_id=-1
        self.fname=''
        self.lname=''
        self.tel=''
        self.iliski=''

        self.btnCancel=QPushButton("iptal_et",self)
        self.btnReset=QPushButton("sifirla",self)
        self.btnAdd=QPushButton("ekle",self)

        self.btnCancel.setFixedHeight(30)
        self.btnReset.setFixedHeight(30)
        self.btnAdd.setFixedHeight(30)

        self.dep_idLabel=QLabel("cocugun idsi")
        self.fnameLabel=QLabel("isim")
        self.lnameLabel = QLabel("soyisim")
        self.telLabel = QLabel("tel:")
        self.iliskiLabel=QLabel("ilişkisi")

        self.dep_idText = QLineEdit(self)
        self.fnameText=QLineEdit(self)
        self.lnameText = QLineEdit(self)
        self.telText = QLineEdit(self)
        self.iliskiText = QLineEdit(self)

        self.grid=QGridLayout(self)
        self.grid.addWidget(self.dep_idLabel,1,1)
        self.grid.addWidget(self.fnameLabel,2,1)
        self.grid.addWidget(self.lnameLabel, 3, 1)
        self.grid.addWidget(self.telLabel, 4, 1)
        self.grid.addWidget(self.iliskiLabel, 5, 1)

        self.grid.addWidget(self.dep_idText,1,2)
        self.grid.addWidget(self.fnameText,2,2)
        self.grid.addWidget(self.lnameText, 3, 2)
        self.grid.addWidget(self.telText, 4, 2)
        self.grid.addWidget(self.iliskiText, 5, 2)

        self.grid.addWidget(self.btnReset,6,1)
        self.grid.addWidget(self.btnCancel,6,3)
        self.grid.addWidget(self.btnAdd,6,2)


        self.btnAdd.clicked.connect(self.adddep)
        self.btnCancel.clicked.connect(QApplication.instance().quit)
        self.btnReset.clicked.connect(self.resetle)

        self.setLayout(self.grid)
        self.setWindowTitle("dependent ekleme")
        self.resize(500,300)
        self.show()
        sys.exit(self.exec())
        print("flag")
    def resetle(self):

        self.fnameText.setText("")
        self.lnameText.setText("")
        self.dep_idText.setText("")
        self.iliskiText.setText("")
        self.telText.setText("")


    def adddep(self):

        self.std_id=int(self.dep_idText.text())
        self.lname=self.lnameText.text()
        self.fname = self.fnameText.text()
        self.tel = self.telText.text()
        self.iliski = self.iliskiText.text()

        y=DbManage()
        y.addDependent(self.std_id,self.fname,self.lname,self.tel,self.iliski)
        #y.addChild('ali','bug',None,None,None,'tumGun','M')



class Cocuk_islemleri(QDialog):
    def __init__(self):
        super().__init__()

        self.vbox = QVBoxLayout()
        self.text = QLabel("Cocuk id num giriniz:")
        self.editField = QLineEdit()
        self.btnSearch = QPushButton("Ara", self)
        self.btnSearch.clicked.connect(self.CocukDetay)
        self.vbox.addWidget(self.text)
        self.vbox.addWidget(self.editField)
        self.vbox.addWidget(self.btnSearch)
        self.dialog = QDialog()
        self.dialog.setWindowTitle("Cocuk detay")
        self.dialog.setLayout(self.vbox)


        self.vboxPayment = QVBoxLayout()
        self.textPayment = QLabel("Silinecek ogenci num giriniz")
        self.editFieldPayment = QLineEdit()
        self.btnSearchPayment = QPushButton("Sil!", self)
        self.btnSearchPayment.clicked.connect(self.CocukKayitSil)
        self.vboxPayment.addWidget(self.textPayment)
        self.vboxPayment.addWidget(self.editFieldPayment)
        self.vboxPayment.addWidget(self.btnSearchPayment)
        self.dialogPayment = QDialog()
        self.dialogPayment.setWindowTitle("silme islemi")
        self.dialogPayment.setLayout(self.vboxPayment)

        self.btnEnterStudent = QPushButton("Kayit Ekle", self)
        self.btnEnterPayment = QPushButton("Kayit Sil", self)
        self.btnShowStudentDetails = QPushButton("Cocuk Detaylari", self)
        #self.btnShowPaymentDetails = QPushButton("Kayit Sil", self)


        self.picLabel = QLabel(self)
        self.picLabel.resize(150, 150)
        self.picLabel.move(120, 20)
        self.picLabel.setScaledContents(True)
        self.picLabel.setPixmap(QtGui.QPixmap("cocuk.png"))

        self.btnEnterStudent.move(15, 170)
        self.btnEnterStudent.resize(180, 40)
        self.btnEnterStudentFont = self.btnEnterStudent.font()
        self.btnEnterStudentFont.setPointSize(13)
        self.btnEnterStudent.setFont(self.btnEnterStudentFont)
        self.btnEnterStudent.clicked.connect(self.CocukKayitEkle)

        self.btnEnterPayment.move(205, 170)
        self.btnEnterPayment.resize(180, 40)
        self.btnEnterPaymentFont = self.btnEnterStudent.font()
        self.btnEnterPaymentFont.setPointSize(13)
        self.btnEnterPayment.setFont(self.btnEnterPaymentFont)
        self.btnEnterPayment.clicked.connect(self.kayitSilDialog)

        self.btnShowStudentDetails.move(15, 220)
        self.btnShowStudentDetails.resize(180, 40)
        self.btnShowStudentDetailsFont = self.btnEnterStudent.font()
        self.btnShowStudentDetailsFont.setPointSize(13)
        self.btnShowStudentDetails.setFont(self.btnShowStudentDetailsFont)
        self.btnShowStudentDetails.clicked.connect(self.CocukDetayDialog)


        self.resize(400, 280)
        self.setWindowTitle("cocuk islemleri")

    def CocukKayitEkle(self):
        self.close()
        enterStudent = AddStudent()
        pass

    def CocukKayitSil(self):
        if self.editFieldPayment.text() == "":
            QMessageBox.warning(QMessageBox(), 'Error',
                                'Numara girmediniz.')
            return None
        showstudent = DbManage()
        showstudent.deleteChild(int(self.editFieldPayment.text()))

    def CocukDetayDialog(self):
        self.dialog.exec()

    def kayitSilDialog(self):
        self.dialogPayment.exec()

    def CocukDetay(self):
        if self.editField.text() == "":
            QMessageBox.warning(QMessageBox(), 'Error',
                                'Numara girmediniz.')
            return None
        showstudent = DbManage()
        showstudent.searchChild(int(self.editField.text()))

class Diger_islemler(QDialog):
    def __init__(self):
        super().__init__()


        self.vboxPayment = QVBoxLayout()
        self.textPayment = QLabel("ögrencinin id num")
        self.editFieldPayment = QLineEdit()
        self.btnSearchPayment = QPushButton("Ekle", self)
        self.btnSearchPayment.clicked.connect(self.dep_ekle)
        self.vboxPayment.addWidget(self.textPayment)
        self.vboxPayment.addWidget(self.editFieldPayment)
        self.vboxPayment.addWidget(self.btnSearchPayment)
        self.dialogPayment = QDialog()
        self.dialogPayment.setWindowTitle("ekle")
        self.dialogPayment.setLayout(self.vboxPayment)

        self.btnEnterStudent = QPushButton("ilk defa ayarlamalar", self)
        self.btnEnterPayment = QPushButton("gecersiz kayıtlar", self)
        self.btnShowStudentDetails = QPushButton("dependent ekle", self)
        #self.btnShowPaymentDetails = QPushButton("Kayit Sil", self)


        self.picLabel = QLabel(self)
        self.picLabel.resize(150, 150)
        self.picLabel.move(120, 20)
        self.picLabel.setScaledContents(True)
        self.picLabel.setPixmap(QtGui.QPixmap("diger.png"))

        self.btnEnterStudent.move(15, 170)
        self.btnEnterStudent.resize(180, 40)
        self.btnEnterStudentFont = self.btnEnterStudent.font()
        self.btnEnterStudentFont.setPointSize(13)
        self.btnEnterStudent.setFont(self.btnEnterStudentFont)
        self.btnEnterStudent.clicked.connect(self.ilk_defa)

        self.btnEnterPayment.move(205, 170)
        self.btnEnterPayment.resize(180, 40)
        self.btnEnterPaymentFont = self.btnEnterStudent.font()
        self.btnEnterPaymentFont.setPointSize(13)
        self.btnEnterPayment.setFont(self.btnEnterPaymentFont)
        self.btnEnterPayment.clicked.connect(self.depEkleDialog)

        self.btnShowStudentDetails.move(15, 220)
        self.btnShowStudentDetails.resize(180, 40)
        self.btnShowStudentDetailsFont = self.btnEnterStudent.font()
        self.btnShowStudentDetailsFont.setPointSize(13)
        self.btnShowStudentDetails.setFont(self.btnShowStudentDetailsFont)
        self.btnShowStudentDetails.clicked.connect(self.KayitlariGoster)


        self.resize(400, 280)
        self.setWindowTitle("Diger islemler")

    def ilk_defa(self):
        obje = DbManage()
        obje.ilk_defa_calistir()

    def KayitlariGoster(self):
        self.close()
        obje = AddDependent()
        obje.exec()

    def dep_ekle(self):
        if self.editFieldPayment.text() == "":
            QMessageBox.warning(QMessageBox(), 'Error',
                                'Numara girmediniz.')
            return None


    def depEkleDialog(self):
        print("flag")
        showstudent = DbManage()
        print("flag")
        showstudent.kaydi_onaylanmayanlari_hesapla()





class Window(QMainWindow):
    def __init__(self):
        super().__init__()
        self.rollToBeSearched=0
        self.vbox = QVBoxLayout()
        self.text = QLabel("Ogrenci id girniz")
        self.editField = QLineEdit()
        self.editFieldStudent_id = QLineEdit()
        self.btnSearch = QPushButton("Ara", self)
        self.btnSearch.clicked.connect(self.showStudent)
        self.vbox.addWidget(self.text)
        self.vbox.addWidget(self.editField)
        self.vbox.addWidget(self.editFieldStudent_id)
        self.vbox.addWidget(self.btnSearch)
        self.dialog = QDialog()
        self.dialog.setWindowTitle("numara")
        self.dialog.setLayout(self.vbox)

        self.rollForPayment = 0
        self.vboxPayment = QVBoxLayout()
        self.textPayment = QLabel("ogrenci id giriniz")
        self.editFieldPayment = QLineEdit()
        self.btnSearchPayment = QPushButton("ara", self)
        self.btnSearchPayment.clicked.connect(self.showStudentPayment)
        self.vboxPayment.addWidget(self.textPayment)
        self.vboxPayment.addWidget(self.editFieldPayment)
        self.vboxPayment.addWidget(self.btnSearchPayment)
        self.dialogPayment = QDialog()
        self.dialogPayment.setWindowTitle("numara")
        self.dialogPayment.setLayout(self.vboxPayment)

        self.btnEnterStudent=QPushButton("Ögrenci islemleri",self)
        self.btnEnterPayment=QPushButton("ögün detayları",self)
        self.btnShowStudentDetails=QPushButton("odeme yap",self)
        self.btnShowPaymentDetails=QPushButton("Diger islemler",self)

        #picture
        self.picLabel=QLabel(self)
        self.picLabel.resize(150,150)
        self.picLabel.move(120,20)
        self.picLabel.setScaledContents(True)
        self.picLabel.setPixmap(QtGui.QPixmap("kres.png"))

        self.btnEnterStudent.move(15,170)
        self.btnEnterStudent.resize(180,40)
        self.btnEnterStudentFont=self.btnEnterStudent.font()
        self.btnEnterStudentFont.setPointSize(13)
        self.btnEnterStudent.setFont(self.btnEnterStudentFont)
        self.btnEnterStudent.clicked.connect(self.enterstudent)

        self.btnEnterPayment.move(205,170)
        self.btnEnterPayment.resize(180, 40)
        self.btnEnterPaymentFont = self.btnEnterStudent.font()
        self.btnEnterPaymentFont.setPointSize(13)
        self.btnEnterPayment.setFont(self.btnEnterPaymentFont)
        self.btnEnterPayment.clicked.connect(self.enterpayment)

        self.btnShowStudentDetails.move(15, 220)
        self.btnShowStudentDetails.resize(180, 40)
        self.btnShowStudentDetailsFont = self.btnEnterStudent.font()
        self.btnShowStudentDetailsFont.setPointSize(13)
        self.btnShowStudentDetails.setFont(self.btnShowStudentDetailsFont)
        self.btnShowStudentDetails.clicked.connect(self.showStudentDialog)

        self.btnShowPaymentDetails.move(205, 220)
        self.btnShowPaymentDetails.resize(180, 40)
        self.btnShowPaymentDetailsFont = self.btnEnterStudent.font()
        self.btnShowPaymentDetailsFont.setPointSize(13)
        self.btnShowPaymentDetails.setFont(self.btnShowPaymentDetailsFont)
        self.btnShowPaymentDetails.clicked.connect(self.showStudentPaymentDialog)

        self.resize(400,280)
        self.setWindowTitle("Ana pencere")

    def enterstudent(self):
        ogrenci = Cocuk_islemleri()
        ogrenci.exec()
    def enterpayment(self):
        obje = DbManage()
        showMeals(obje.calculate_meal())
    def showStudentDialog(self):
        self.dialog.exec()
    def showStudentPaymentDialog(self):
        obje = Diger_islemler()
        obje.exec()
    def showStudent(self):
        if self.editField.text() == "" or self.editFieldStudent_id.text() == "":
            QMessageBox.warning(QMessageBox(), 'Error',
                                'numarayi veya odeme kismini bos biraktiniz.')
            return None
        showstudent = DbManage()
        showstudent.updatePayment(int(self.editField.text()), int(self.editFieldStudent_id.text()))
    def showStudentPayment(self):
        if self.editFieldPayment.text() == "":
            QMessageBox.warning(QMessageBox(), 'Error',
                                'numarayi veya odeme kismini bos biraktiniz.')
            return None
        showstudent = DbManage()
        #showstudent.searchPayment(int(self.editFieldPayment.text()))

if __name__ == "__main__":
    #y=DbManage()
    #y.ilk_defa_calistir()
    #y.kaydi_onaylanmayanlari_hesapla()
    #y.deleteChild(5)
    #y.calculate_meal()
    #y.addTeacher(2, 'yunus','bugday', 25)
    #y.addDependent(9, 'haci', 'bugday', '54259', 'anne')
    #y.searchChild(2)

    app = QApplication(sys.argv)
    #y.addChild('ali','bug',2,'tumGun','M')
    #y.searchChild(8)
    #enterStudent = AddStudent()
    window = Window()
    window.show()
    sys.exit(app.exec_())