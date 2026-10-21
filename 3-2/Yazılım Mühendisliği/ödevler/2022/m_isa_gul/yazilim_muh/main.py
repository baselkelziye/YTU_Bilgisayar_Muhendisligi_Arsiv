import customtkinter as ctk
from CTkMessagebox import CTkMessagebox
from tkinter import *
import sqlite3

ctk.set_appearance_mode("Dark")
ctk.set_default_color_theme("dark-blue")
root = ctk.CTk()
root.geometry(f"{root.winfo_screenwidth()}x{root.winfo_screenheight()}+0+0")
root.title("Çelebi Seyahat Acentesi")

frame = ctk.CTkFrame(master=root)
frame.pack(pady=50, padx=50, fill="both", expand=True)

conn = sqlite3.connect("database.db")
print("Database connected.")


def sefer_sorgula():
    try:
        tbox_bos_koltuklar.delete("1.0", "end-1c")
        firma = drop_firma.get()
        tarih = tbox_tarih.get("1.0", "end-1c")
        cikis = tbox_cikis.get("1.0", "end-1c")
        varis = tbox_varis.get("1.0", "end-1c")
        cur = conn.execute(f"SELECT * FROM firma WHERE firmaAd LIKE '{firma}'")
        firma = cur.fetchone()
        cur = conn.execute(
            f"SELECT * FROM sefer WHERE firmaNo = {firma[0]} AND seferTarih LIKE '{tarih}' AND seferCikis LIKE '{cikis}' AND seferVaris LIKE '{varis}'"
        )

        sefer = cur.fetchone()
        bos_koltuklar = sefer[3].split(",")
        fiyat = sefer[6]
        label_sefer_no.configure(text=sefer[0])
        label_price.configure(text=fiyat)
        tbox_bos_koltuklar.insert(INSERT, "\t".join(bos_koltuklar))
    except Exception as e:
        conn.rollback()
        CTkMessagebox(title="Hata", message=e, icon="cancel")


def musteri_sorgula():
    try:
        tbox_musteri_adsoyad.delete("1.0", "end-1c")
        tbox_puan.delete("1.0", "end-1c")
        tbox_telefon.delete("1.0", "end-1c")

        musteri_no = tbox_musteri_no.get("1.0", "end-1c")
        cur = conn.execute(f"SELECT * FROM musteri WHERE musteriNumara = {musteri_no}")
        musteri = cur.fetchone()
        if musteri:
            tbox_musteri_adsoyad.insert(INSERT, f"{musteri[1]},{musteri[2]}")
            tbox_puan.insert(INSERT, musteri[3])
            tbox_telefon.insert(INSERT, musteri[4])
        else:
            CTkMessagebox(title="Hata", message="Müşteri bulunumadı.", icon="cancel")
    except Exception as e:
        conn.rollback()
        CTkMessagebox(title="Hata", message=e, icon="cancel")


def musteri_ekle():
    try:
        musteri_no = tbox_musteri_no.get("1.0", "end-1c")
        musteri_ad, musteri_soyad = tbox_musteri_adsoyad.get("1.0", "end-1c").split(",")
        musteri_tel = tbox_telefon.get("1.0", "end-1c")
        puan = tbox_puan.get("1.0", "end-1c")
        conn.execute(
            f"INSERT INTO musteri VALUES ({musteri_no}, '{musteri_ad}', '{musteri_soyad}', {puan}, '{musteri_tel}')"
        )
        conn.commit()
        CTkMessagebox(title="Başarılı", message="Müşteri Eklendi.", icon="check")
    except Exception as e:
        conn.rollback()
        CTkMessagebox(title="Hata", message=e, icon="cancel")


def puan_kullan():
    fiyat = float(label_price._text) - float(tbox_puan.get("1.0", "end-1c"))
    label_yeni_fiyat.configure(text=fiyat)

def bilet_kes():
    try:
        mus_no = int(tbox_musteri_no.get("1.0", "end-1c"))
        sefer_no = int(label_sefer_no._text)
        fiyat = float(label_yeni_fiyat._text)
        koltuk_no = tbox_koltuk_no.get("1.0", "end-1c")
        firma_name = drop_firma.get()
        cur = conn.execute(f"SELECT * FROM firma WHERE firmaAd LIKE '{firma_name}'")
        firma = cur.fetchone()
        yeni_puan = fiyat * firma[1] / 100
        conn.execute(
            f"UPDATE musteri SET musteriPuan = {yeni_puan} WHERE musteriNumara = {mus_no}"
        )

        cur = conn.execute(f"SELECT * FROM sefer WHERE seferNumara = {sefer_no}")
        sefer = cur.fetchone()
        bos_koltuklar = sefer[3].split(",")
        bos_koltuklar.remove(koltuk_no)
        bos_koltuklar_text = ",".join(bos_koltuklar)

        conn.execute(
            f"UPDATE sefer SET seferBosKoltuk = '{bos_koltuklar_text}' WHERE seferNumara = {sefer_no}"
        )
        conn.commit()
    except Exception as e:
        conn.rollback()
        CTkMessagebox(title="Hata", message=e, icon="cancel")


def otel_sorgula():
    try:
        tbox_otel_sonuc.delete("1.0", "end-1c")
        bolge = tbox_bolge.get("1.0", "end-1c")
        tarih = tbox_otel_tarih.get("1.0", "end-1c")

        cur = conn.execute(
            f"SELECT * FROM otel WHERE otelBolge = '{bolge}' AND otelTarih = '{tarih}'"
        )
        tbox_otel_sonuc.insert(
            INSERT,
            "Otel Adı\t\tOtel Bölgesi\t\tGün Sayısı\t\tGünlük Fiyat\t\tBoş Odalar\n",
        )
        for row in cur:
            tbox_otel_sonuc.insert(
                INSERT, f"{row[0]}\t\t{row[1]}\t\t{row[3]}\t\t{row[4]}\t\t{row[5]}\n"
            )
    except Exception as e:
        conn.rollback()
        CTkMessagebox(title="Hata", message=e, icon="cancel")


def otel_fiyat_hesapla():
    try:
        otelad = tbox_otel_ad.get("1.0", "end-1c")
        gunsayisi = int(tbox_otel_gun.get("1.0", "end-1c"))

        otel = conn.execute(
            f"SELECT * FROM otel WHERE otelAdi LIKE '{otelad}'"
        ).fetchone()
        fiyat = gunsayisi * int(otel[4])
        label_otel_fiyat.configure(text=fiyat)
    except Exception as e:
        conn.rollback()
        CTkMessagebox(title="Hata", message=e, icon="cancel")


def puan_kullan_otel():
    fiyat = float(label_otel_fiyat._text)
    puan = float(tbox_puan.get("1.0", "end-1c"))

    label_yeni_otel_fiyat.configure(text=fiyat - puan)


def rezervasyon_yap():
    try:
        otelad = tbox_otel_ad.get("1.0", "end-1c")
        odano = tbox_otel_oda.get("1.0", "end-1c")
        gunsayisi = int(tbox_otel_gun.get("1.0", "end-1c"))
        otel = conn.execute(
            f"SELECT * FROM otel WHERE otelAdi LIKE '{otelad}'"
        ).fetchone()
        fiyat = float(label_yeni_otel_fiyat._text)
        puan = fiyat * int(otel[6]) / 100
        mus_no = int(tbox_musteri_no.get("1.0", "end-1c"))
        conn.execute(
            f"UPDATE musteri SET musteriPuan = {puan} WHERE musteriNumara = {mus_no}"
        )

        odalar = otel[5].split(",")
        odalar.remove(odano)
        odalar_yeni = ",".join(odalar)

        conn.execute(
            f"UPDATE otel SET bosOda = '{odalar_yeni}' WHERE otelAdi LIKE '{otelad}'"
        )

        conn.commit
        CTkMessagebox(title="Başarılı", message="Rezerasyon yapıldı.", icon="check")
    except Exception as e:
        conn.rollback()
        CTkMessagebox(title="Hata", message=e, icon="cancel")


# ARAYUZ


# Sefer Sorgulama

label = ctk.CTkLabel(frame, text="Firma:")
label.place(x=20, y=20)
drop_firma = ctk.StringVar(value="Uçan Türk Özel Havayolu")
drop = ctk.CTkOptionMenu(
    master=frame,
    width=100,
    height=20,
    variable=drop_firma,
    values=["Uçan Türk Özel Havayolu", "Devlet Demir Yolları (TCDD)", "YTUR Otobüs"],
)
drop.place(x=80, y=25)


label = ctk.CTkLabel(frame, text="Tarih:")
label.place(x=20, y=80)
tbox_tarih = ctk.CTkTextbox(frame, 300, 100)
tbox_tarih.place(width=200, height=30, x=80, y=80)

label = ctk.CTkLabel(frame, text="Çıkış:")
label.place(x=20, y=140)
tbox_cikis = ctk.CTkTextbox(frame, 300, 100)
tbox_cikis.place(width=200, height=30, x=80, y=140)

label = ctk.CTkLabel(frame, text="Varış:")
label.place(x=20, y=200)
tbox_varis = ctk.CTkTextbox(frame, 300, 100)
tbox_varis.place(width=200, height=30, x=80, y=200)

button = ctk.CTkButton(frame, 270, 30, text="Sorgula", command=sefer_sorgula)
button.place(x=20, y=260)

label = ctk.CTkLabel(frame, text="Boş Koltuklar")
label.place(x=350, y=20)

tbox_bos_koltuklar = ctk.CTkTextbox(frame, 300, 100)
tbox_bos_koltuklar.place(width=220, height=120, x=300, y=50)

label = ctk.CTkLabel(frame, text="Fiyat:")
label.place(x=330, y=200)
label_price = ctk.CTkLabel(frame, text="...")
label_price.place(x=400, y=200)

label = ctk.CTkLabel(frame, text="Sefer No:")
label.place(x=330, y=230)
label_sefer_no = ctk.CTkLabel(frame, text="...")
label_sefer_no.place(x=400, y=230)


# Müşteri Sorgulama

label = ctk.CTkLabel(frame, text="Müşteri No:")
label.place(x=20, y=400)
tbox_musteri_no = ctk.CTkTextbox(frame, 300, 100)
tbox_musteri_no.place(width=200, height=30, x=100, y=400)

button = ctk.CTkButton(frame, 100, 30, text="Sorgula", command=musteri_sorgula)
button.place(x=330, y=400)

label = ctk.CTkLabel(frame, text="Ad Soyad:")
label.place(x=20, y=460)
tbox_musteri_adsoyad = ctk.CTkTextbox(frame, 300, 100)
tbox_musteri_adsoyad.place(width=200, height=30, x=100, y=460)

label = ctk.CTkLabel(frame, text="Telefon:")
label.place(x=20, y=500)
tbox_telefon = ctk.CTkTextbox(frame, 300, 100)
tbox_telefon.place(width=200, height=30, x=100, y=500)

label = ctk.CTkLabel(frame, text="Puan:")
label.place(x=20, y=540)
tbox_puan = ctk.CTkTextbox(frame, 300, 100)
tbox_puan.place(width=200, height=30, x=100, y=540)

button = ctk.CTkButton(frame, 100, 30, text="Ekle", command=musteri_ekle)
button.place(x=330, y=460)


# Bilet Kes

button = ctk.CTkButton(frame, 100, 30, text="Puan Kullan", command=puan_kullan)
button.place(x=20, y=600)

label = ctk.CTkLabel(frame, text="Yeni Fiyat:")
label.place(x=170, y=600)
label_yeni_fiyat = ctk.CTkLabel(frame, text="...")
label_yeni_fiyat.place(x=250, y=600)

label = ctk.CTkLabel(frame, text="Ödeme Yöntemi:")
label.place(x=20, y=650)
drop_odeme = ctk.StringVar(value="Nakit")
drop = ctk.CTkOptionMenu(
    master=frame,
    width=100,
    height=20,
    variable=drop_odeme,
    values=["Nakit", "Kredi Kartı", "Çek"],
)
drop.place(x=170, y=650)

label = ctk.CTkLabel(frame, text="Koltuk No:")
label.place(x=20, y=700)
tbox_koltuk_no = ctk.CTkTextbox(frame, 300, 100)
tbox_koltuk_no.place(width=200, height=30, x=100, y=700)

button = ctk.CTkButton(frame, 250, 30, text="Bilet Kes", command=bilet_kes)
button.place(x=20, y=780)

# Otel Sorgulama

label = ctk.CTkLabel(frame, text="TATİL REZERVASYONU")
label.place(x=830, y=20)

label = ctk.CTkLabel(frame, text="Bölge:")
label.place(x=800, y=60)
tbox_bolge = ctk.CTkTextbox(frame, 300, 100)
tbox_bolge.place(width=200, height=30, x=880, y=60)

label = ctk.CTkLabel(frame, text="Tarih:")
label.place(x=800, y=100)
tbox_otel_tarih = ctk.CTkTextbox(frame, 300, 100)
tbox_otel_tarih.place(width=200, height=30, x=880, y=100)

tbox_otel_sonuc = ctk.CTkTextbox(frame, 300, 100)
tbox_otel_sonuc.place(width=600, height=400, x=1130, y=40)

button = ctk.CTkButton(frame, 280, 30, text="Sorgula", command=otel_sorgula)
button.place(x=800, y=150)

label = ctk.CTkLabel(frame, text="Otel Adı:")
label.place(x=800, y=300)
tbox_otel_ad = ctk.CTkTextbox(frame, 300, 100)
tbox_otel_ad.place(width=200, height=30, x=880, y=300)

label = ctk.CTkLabel(frame, text="Gün Sayısı:")
label.place(x=800, y=340)
tbox_otel_gun = ctk.CTkTextbox(frame, 300, 100)
tbox_otel_gun.place(width=200, height=30, x=880, y=340)

label = ctk.CTkLabel(frame, text="Oda No:")
label.place(x=800, y=380)
tbox_otel_oda = ctk.CTkTextbox(frame, 300, 100)
tbox_otel_oda.place(width=200, height=30, x=880, y=380)

button = ctk.CTkButton(frame, 100, 30, text="Fiyat Hesapla", command=otel_fiyat_hesapla)
button.place(x=800, y=480)

label = ctk.CTkLabel(frame, text="Fiyat:")
label.place(x=950, y=480)
label_otel_fiyat = ctk.CTkLabel(frame, text="...")
label_otel_fiyat.place(x=1050, y=480)

button = ctk.CTkButton(frame, 100, 30, text="Puan Kullan", command=puan_kullan_otel)
button.place(x=800, y=520)

label = ctk.CTkLabel(frame, text="Yeni Fiyat:")
label.place(x=950, y=520)
label_yeni_otel_fiyat = ctk.CTkLabel(frame, text="...")
label_yeni_otel_fiyat.place(x=1050, y=520)


button = ctk.CTkButton(frame, 250, 30, text="Rezervasyon Yap", command=rezervasyon_yap)
button.place(x=800, y=580)


root.mainloop()
