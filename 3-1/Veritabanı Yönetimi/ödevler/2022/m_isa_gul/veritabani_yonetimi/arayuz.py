import customtkinter as ctk 
from tkinter import *
import psycopg2

conn = psycopg2.connect("dbname=zeytinIslemeTesisi user=postgres password=muhammed")
cur = conn.cursor()

ctk.set_appearance_mode("Dark")
ctk.set_default_color_theme("dark-blue")

root = ctk.CTk()
root.geometry(f"{root.winfo_screenwidth()}x{root.winfo_screenheight()}+0+0")
root.title("Zeytin Isleme Tesisi Bilgi Sistemi")


frame = ctk.CTkFrame(master=root)
frame.pack(pady=50, padx=50, fill="both", expand=True)

label_durum = ctk.CTkLabel(frame, text=f"Durum: ")
label_durum.place(x=650, y=110)

def execute():
    islem = clicked_islem.get()
    tablo = clicked_tablo.get()
    extra = textbox_extra.get("1.0", END)
    
    if islem == "Insert":
        query = f"INSERT INTO {tablo} {extra}"
    elif islem == "Update":
        query = f"UPDATE {tablo} {extra}"
    else:
        query = f"DELETE FROM {tablo} {extra}"
    try:
        cur.execute(query)
        conn.commit()
        label_durum.configure(text="Durum: Başarılı")
    except Exception as e:
        conn.rollback()
        label_durum.configure(text=f"Durum: {e}")

def execute_select():
    textbox_select.delete("1.0", END)
    cols = textbox_col.get("1.0", END)
    tablo = clicked_tablo2.get()
    extra = textbox_select_where.get("1.0", END)
    try:
        if len(extra)==1:
            cur.execute(f"SELECT {cols} FROM {tablo}")
        else:
            cur.execute(f"SELECT {cols} FROM {tablo} WHERE {extra}")
        rows =  cur.fetchall()
        txt=""
        for row in rows:
            for alt in row:
                txt+=str(alt).ljust(30)
            txt+="\n"
        textbox_select.delete("1.0", END)
        textbox_select.insert(INSERT, txt)
    except Exception as e:
        conn.rollback()
        textbox_select.delete("1.0", END)
        textbox_select.insert(INSERT, e)

def execute_fonk():
    fonk =clicked_fonk.get()
    param = int(textbox_param.get("1.0", END))
    if "Üreticinin getirdiği" in fonk:
        cur.execute(f"SELECT * FROM uretici_toplam({param})")
        res = cur.fetchone()
    elif "Bir bölümdeki" in fonk:
        cur.execute(f"SELECT * FROM bolum_calisan_sayisi({param})")
        res = cur.fetchone()
    else:
        cur.execute(f"SELECT * FROM fazla_olan({param})")
        res = cur.fetchone()
    textbox_fonk_sonuc.delete("1.0", END)
    textbox_fonk_sonuc.insert(INSERT, res)


def execute_kayit():
    uretici = int(textbox_kayit_uretici.get("1.0", END))
    islem = clicked_kayit_islem.get()
    miktar = int(textbox_kayit_miktar.get("1.0", END))
    zaman = textbox_kayit_tarih.get("1.0", END)

    query = f"INSERT INTO kayitlar VALUES(nextval('kayit_id_seq'),{uretici},'{islem}',{miktar}, '{zaman}')"
    try:
        cur.execute(query)
        conn.commit()
        label_kayit_durum.configure(text="Durum: Başarılı")
    except Exception as e:
        conn.rollback()
        label_kayit_durum.configure(text=f"Durum: {e}")

def execute_siparis():
    musteri = int(textbox_siparis_musteri.get("1.0", END))
    miktar = int(textbox_siparis_miktar.get("1.0", END))
    zaman = textbox_siparis_tarih.get("1.0", END)

    query = f"INSERT INTO siparisler VALUES(nextval('siparis_id_seq'), {musteri}, {miktar}, '{zaman}')"
    try:
        cur.execute(query)
        conn.commit()
        label_siparis_durum.configure(text="Durum: Başarılı")
    except Exception as e:
        conn.rollback()
        label_siparis_durum.configure(text=f"Durum: {e}")

def execute_sorgu():
    sorgu = clicked_sorgu.get()
    if "toplam zeytin" in sorgu:
        query = f"SELECT SUM(miktar) FROM siparisler"
        cur.execute(query)
        res = cur.fetchone()
        textbox_select.delete("1.0", END)
        textbox_select.insert(INSERT, f"Toplam satılan miktar: {res} litre")
    elif "fazla olan bölümlerin" in sorgu:
        try:
            param = textbox_sorgu_param.get("1.0", END)
            create_view = f"""
                            CREATE OR REPLACE VIEW view1 AS
                            SELECT * FROM bolumler
                            WHERE calisan_sayisi > {int(param)}
                            """
            cur.execute(create_view)
            conn.commit()
            query = f"SELECT bolum_id, bolum_adi, calisan_sayisi FROM view1"
            cur.execute(query)
            rows = cur.fetchall()
            txt=f'{"bolum_id".ljust(30)} {"bolum_adi".ljust(30)} {"calisan_sayisi".ljust(30)}\n'
            for row in rows:
                for alt in row:
                    txt+=str(alt).ljust(30)
                txt+="\n"
            textbox_select.delete("1.0", END)
            textbox_select.insert(INSERT, txt)
        except Exception as e:
            conn.rollback()
            textbox_select.delete("1.0", END)
            textbox_select.insert(INSERT, e)
    elif "Sipariş ve müşteri" in sorgu:
        query = """
                SELECT siparis_id, musteri_isim, musteri_adres, musteri_tel, miktar, tarih FROM siparisler
                INNER JOIN musteriler
                ON
                siparisler.musteri_no=musteriler.musteri_id
                """
        try:
            cur.execute(query)
            rows = cur.fetchall()
            txt=f'{"siparis_id".ljust(30)} {"musteri_isim".ljust(30)} {"musteri_adres".ljust(30)} {"musteri_tel".ljust(30)} {"miktar".ljust(30)} {"tarih".ljust(30)}\n'
            for row in rows:
                    for alt in row:
                        txt+=str(alt).ljust(30)
                    txt+="\n"
            textbox_select.delete("1.0", END)
            textbox_select.insert(INSERT, txt)
        except Exception as e:
            conn.rollback()
            textbox_select.delete("1.0", END)
            textbox_select.insert(INSERT, e)
    elif "fazla sipariş" in sorgu:
        param = textbox_sorgu_param.get("1.0", END)
        query = f"""
                SELECT musteri_no, COUNT(siparis_id)
                FROM siparisler
                GROUP BY musteri_no
                HAVING COUNT(siparis_id) > {int(param)}
                """
        cur.execute(query)
        rows= cur.fetchall()
        txt=f'{"musteri_id".ljust(30)} {"siparis_sayisi".ljust(30)}\n'
        for row in rows:
                for alt in row:
                    txt+=str(alt).ljust(30)
                txt+="\n"
        textbox_select.delete("1.0", END)
        textbox_select.insert(INSERT, txt)
    else:
        param = textbox_sorgu_param.get("1.0", END)
        query = f"""
                SELECT uretici_isim, toplam_zeytin, toplam_zeytinyagi FROM ureticiler
                WHERE toplam_zeytin > {int(param)}
                UNION
                SELECT uretici_isim, toplam_zeytin, toplam_zeytinyagi FROM ureticiler
                WHERE toplam_zeytinyagi > {int(param)}
                """
        cur.execute(query)
        rows = cur.fetchall()
        txt=f'{"uretici_isim".ljust(30)} {"toplam_zeytin".ljust(30)} {"toplam_zeytinyagi".ljust(30)}\n'
        for row in rows:
            for alt in row:
                txt+=str(alt).ljust(30)
            txt+="\n"
        textbox_select.delete("1.0", END)
        textbox_select.insert(INSERT, txt)


label = ctk.CTkLabel(frame,text = "İşlem")
label.place(x=20, y=20)
clicked_islem = ctk.StringVar(value="Insert")
drop = ctk.CTkOptionMenu(master=frame, width=100, height=20, variable=clicked_islem, values=["Insert", "Update", "Delete"])
drop.place(x=20, y=50)

label = ctk.CTkLabel(frame,text = "Tablo")
label.place(x=150, y=20)
clicked_tablo = ctk.StringVar(value="calisanlar")
drop = ctk.CTkOptionMenu(master=frame, width=100, height=20, variable=clicked_tablo, values=["calisanlar", "ureticiler", "bolumler", "musteriler", "kayitlar", "siparisler"])
drop.place(x=150, y=50)

label = ctk.CTkLabel(frame,text = "Ek")
label.place(x=300, y=20)
textbox_extra = ctk.CTkTextbox(frame, 300, 100)
textbox_extra.place(x=300, y=50)

button = ctk.CTkButton(frame, 100, 50, text="Çalıştır", command=execute)
button.place(x=650, y=50)

label = ctk.CTkLabel(frame, text = "SELECT")
label.place(x=20,y=220)
textbox_col = ctk.CTkTextbox(frame, 300, 100)
textbox_col.place(width=200, height=30, x=80, y=220)
label = ctk.CTkLabel(frame, text = "FROM")
label.place(x=300,y=220)
clicked_tablo2 = ctk.StringVar(value="calisanlar")
drop = ctk.CTkOptionMenu(master=frame, width=100, height=20, variable=clicked_tablo2, values=["calisanlar", "ureticiler", "bolumler", "musteriler", "kayitlar", "siparisler"])
drop.place(x=350, y=225)
label = ctk.CTkLabel(frame, text = "WHERE")
label.place(x=470,y=220)
textbox_select_where = ctk.CTkTextbox(frame, 300, 100)
textbox_select_where.place(width=300, height=30, x=530, y=220)

button = ctk.CTkButton(frame, 810, 40, text="Çalıştır", command=execute_select)
button.place(x=20, y=270)

label = ctk.CTkLabel(frame,text = "Ozel Sorgu")
label.place(x=20, y=340)
clicked_sorgu = ctk.StringVar(value="Seçim yapınız")
drop = ctk.CTkOptionMenu(master=frame, width=300, height=20, variable=clicked_sorgu, values=[
    "Tesisin sattığı toplam zeytinyağı miktarı", # SUM
    "Çalışan sayısı verilen değerden fazla olan bölümlerin bilgileri", # VIEW
    "Sipariş ve müşteri bilgileri", # INNER JOIN
    "Girilen değerden fazla sipariş veren müşterileri listele", # HAVING
    "Getirdiği zeytin veya aldığı zeytinyağı miktarı girilen değerden fazla olan üreticiler" # UNION
    ])
drop.place(x=100, y=345)

label = ctk.CTkLabel(frame,text = "Parametre: ")
label.place(x=580, y=340)
textbox_sorgu_param = ctk.CTkTextbox(frame,100, 30)
textbox_sorgu_param.place(x=650,y=340)
button = ctk.CTkButton(frame, 810, 40, text="Çalıştır", command=execute_sorgu)
button.place(x=20, y=380)

textbox_select = ctk.CTkTextbox(frame,810, 450)
textbox_select.place(x=20,y=450)

label = ctk.CTkLabel(frame,text = "Fonksiyon")
label.place(x=1000, y=20)
clicked_fonk = ctk.StringVar(value="Seçim yapınız")
drop = ctk.CTkOptionMenu(master=frame, width=300, height=20, variable=clicked_fonk, values=[
    "Üreticinin getirdiği toplam zeytin ağırlığı ve aldığı toplam zeytinyağı hacmi",
    "Bir bölümdeki toplam çalışan sayısı",
    "Getirilen toplam zeytin miktarı belirli bir değerden fazla olan üretici sayısı"])
drop.place(x=1000, y=50)
label = ctk.CTkLabel(frame,text = "Parametre: ")
label.place(x=1000, y=90)
textbox_param = ctk.CTkTextbox(frame,200, 30)
textbox_param.place(x=1080,y=90)
button = ctk.CTkButton(frame, 100, 50, text="Çalıştır", command=execute_fonk)
button.place(x=1320, y=90)
label = ctk.CTkLabel(frame,text = "Sonuç: ")
label.place(x=1000, y=150)
textbox_fonk_sonuc = ctk.CTkTextbox(frame,200, 30)
textbox_fonk_sonuc.place(x=1080,y=150)

label = ctk.CTkLabel(frame,text = "Kayıt Ekle")
label.place(x=1000, y=220)

label = ctk.CTkLabel(frame,text = "Üretici ID: ")
label.place(x=1000, y=250)
textbox_kayit_uretici = ctk.CTkTextbox(frame,200, 30)
textbox_kayit_uretici.place(x=1080,y=250)

label = ctk.CTkLabel(frame,text = "İşlem: ")
label.place(x=1000, y=300)
clicked_kayit_islem = ctk.StringVar(value="Seçim yapınız")
drop = ctk.CTkOptionMenu(master=frame, width=200, height=20, variable=clicked_kayit_islem, values=["Zeytin getirdi", "Zeytinyağı aldı"])
drop.place(x=1080, y=300)

label = ctk.CTkLabel(frame,text = "Miktar: ")
label.place(x=1000, y=350)
textbox_kayit_miktar = ctk.CTkTextbox(frame,200, 30)
textbox_kayit_miktar.place(x=1080,y=350)

label = ctk.CTkLabel(frame,text = "Tarih ve Saat: ")
label.place(x=1000, y=400)
textbox_kayit_tarih = ctk.CTkTextbox(frame,200, 30)
textbox_kayit_tarih.place(x=1080,y=400)

button = ctk.CTkButton(frame, 100, 50, text="Çalıştır", command=execute_kayit)
button.place(x=1320, y=270)
label_kayit_durum = ctk.CTkLabel(frame, text=f"Durum: ")
label_kayit_durum.place(x=1320, y=320)

label = ctk.CTkLabel(frame,text = "Sipariş Ekle")
label.place(x=1000, y=480)

label = ctk.CTkLabel(frame,text = "Müşteri ID: ")
label.place(x=1000, y=500)
textbox_siparis_musteri = ctk.CTkTextbox(frame,200, 30)
textbox_siparis_musteri.place(x=1080,y=500)

label = ctk.CTkLabel(frame,text = "Miktar: ")
label.place(x=1000, y=550)
textbox_siparis_miktar = ctk.CTkTextbox(frame,200, 30)
textbox_siparis_miktar.place(x=1080,y=550)

label = ctk.CTkLabel(frame,text = "Tarih ve Saat: ")
label.place(x=1000, y=600)
textbox_siparis_tarih = ctk.CTkTextbox(frame,200, 30)
textbox_siparis_tarih.place(x=1080,y=600)

button = ctk.CTkButton(frame, 100, 50, text="Çalıştır", command=execute_siparis)
button.place(x=1320, y=500)
label_siparis_durum = ctk.CTkLabel(frame, text=f"Durum: ")
label_siparis_durum.place(x=1320, y=550)


root.mainloop()


