import matplotlib.pyplot as plt
import sqlite3

conn = sqlite3.connect('ZEGESA.db')
cursor = conn.cursor()

aylik_list = list()
count_list = list()
x = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31]


def ay_hesapla(ay,yil):
    for i in range(1,32):
        gun = i
        if gun<10:
            table_tarih = f"tarih_0{gun}_{ay}_{yil}"
        else:
            table_tarih = f"tarih_{gun}_{ay}_{yil}"
        try:
            cursor.execute(f"SELECT SUM(Tutar)FROM {table_tarih}")
            gunluk_tutar = cursor.fetchone()[0]
            print(table_tarih,":",gunluk_tutar)
            aylik_list.append(gunluk_tutar)
        except:
            aylik_list.append(0)
            print(table_tarih," tutar degeri bulunamadi.")
        try:
            cursor.execute(f"SELECT COUNT(*)FROM {table_tarih}")
            count = cursor.fetchone()[0]
            count_list.append(count)
        except:
            count_list.append(0)

    print(count_list)
    print(aylik_list)


def aylik_tutar_graph(ay,yil):
    plt.xlabel('günler')
    plt.ylabel('toplam tutar')
    plt.title('aylik tutar grafiği')
    plt.plot(x,aylik_list)
    plt.savefig(f'static\graph_tutar_{ay}_{yil}.jpg')
    plt.close()

def aylik_musteri_graph(ay,yil):
    plt.xlabel('günler')
    plt.ylabel('müşteri sayisi')
    plt.title('aylik müşteri grafiği')
    plt.plot(x,count_list)
    plt.savefig(f'static\graph_musteri_{ay}_{yil}.jpg')
    plt.close()

def aylik_graph(ay,yil):
    ay_hesapla(ay,yil)
    aylik_tutar_graph(ay,yil)
    aylik_musteri_graph(ay,yil)



aylik_graph("05","2023")

conn.close()