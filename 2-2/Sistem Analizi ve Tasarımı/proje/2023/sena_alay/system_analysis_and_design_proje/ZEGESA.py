import tkinter as tk
from tkinter import messagebox, ttk
import datetime
import sqlite3

class Menu:
    def __init__(self, items):
        self.items = items

class Item:
    def __init__(self, name, price, ingredients):
        self.name = name
        self.price = price
        self.ingredients = ingredients

class Pasta(Item):
    def __init__(self, name, price, ingredients):
        super().__init__(name, price, ingredients)

class Drink(Item):
    def __init__(self, name, price, ingredients):
        super().__init__(name, price, ingredients)

class Dessert(Item):
    def __init__(self, name, price, ingredients):
        super().__init__(name, price, ingredients)       

class Masa:
    def __init__(self, masa_no):
        self.masa_no = masa_no
        self.dolu_mu = False




#*****************************DATABASE İNİT***********************************

conn = sqlite3.connect('ZEGESA.db')
cursor = conn.cursor()

now = datetime.datetime.now()
table_tarih = "tarih_" + (now.strftime ("%d_%m_%Y"))
#table_tarih = f"tarih_17_05_2023"
print(table_tarih)
cursor.execute(f"CREATE TABLE IF NOT EXISTS {table_tarih} (Musteri_ID INTEGER, Isim STRING, Masa INTEGER, Giris_Saati INTEGER, Cikis_Saati INTEGER, Tarih INTEGER, Siparis STRING, Tutar INTEGER)")
conn.commit()
def sql_max():
    query = f"SELECT MAX(Musteri_ID) FROM {table_tarih}"
    cursor.execute(query)
    conn.commit()
    result = cursor.fetchone()[0]
    return result

global musteri_id
musteri_id=0
try: 
    musteri_id = sql_max() + 1
except: 
    musteri_id = 1

def sql_add():

    cursor.execute(f"INSERT INTO {table_tarih} (Musteri_ID) VALUES (('{musteri_id}'))")
    conn.commit()

def sql_update(pos,value):
    cursor.execute(f"UPDATE {table_tarih} SET ({pos}) = (('{value}')) WHERE Musteri_ID = ('{musteri_id}')")
    conn.commit()

# ****************************************FONKSİYONLAR********************************


# Siparişi onaylama ve masa durumunu güncelleme fonksiyonunu 
def siparisi_onayla():
    global siparis_onaylandi_mi
    secilen_masa_no = int(masa_secim.get())
    secilen_masa = masalar[secilen_masa_no - 1]
    if not secilen_masa.dolu_mu:
        secilen_masa.dolu_mu = True
        masa_durumunu_goster()  # Masa durumunu güncelle
        messagebox.showinfo("Sipariş Onayı", f"Masa {secilen_masa_no}, sipariş alındı. Toplam tutar: {hesapla_tutar()} TL.")
        siparis_onaylandi_mi = True
    else:
        messagebox.showerror("Sipariş Hatası", f"Masa {secilen_masa_no} dolu. Lütfen başka bir masa seçin.")


def adim_musteri_girisi():
    musteri_frame.pack(fill='both', expand=True)
    menu_frame.pack_forget()
    siparis_frame.pack_forget()
    odeme_frame.pack_forget()

def adim_menu_secimi():
    musteri_frame.pack_forget()
    menu_frame.pack(fill='both', expand=True)
    siparis_frame.pack_forget()
    odeme_frame.pack_forget()

def adim_siparis_onayi():
    musteri_frame.pack_forget()
    menu_frame.pack_forget()
    siparis_frame.pack(fill='both', expand=True)
    odeme_frame.pack_forget()

def adim_odeme():
    musteri_frame.pack_forget()
    menu_frame.pack_forget()
    siparis_frame.pack_forget()
    odeme_frame.pack(fill='both', expand=True)

def ileri_git():
    global current_step
    global siparis_onaylandi_mi

    if current_step == 2:  # Sipariş onayı adımında mıyız?
        if onay.get():  
            messagebox.showinfo("Başarılı", "Ödeme adımına geçiliyor...")
            siparis_onaylandi_mi = True  # Siparişi onaylandı olarak işaretle
        else:
            messagebox.showerror("Hata", "Lütfen siparişi onaylayın!")
            return  # Sipariş onaylanmadığı için ilerleme yapma

    # Sipariş onaylandıysa veya sipariş onayı adımı değilse, ilerle
    if current_step < len(steps) - 1:
        current_step += 1
        steps[current_step]["islev"]()


def geri_git():
    global current_step
    if current_step > 0:
        current_step -= 1
        steps[current_step]["islev"]()

def musteri_al():
    ileri_git()
    masa_isim = isim_girdisi.get()
    masa_no = masa_secim.get()
    print(masa_isim)
    print(masa_no)
    now = datetime.datetime.now()
    tarih = now.strftime("%d-%m-%Y")
    giris_saati = now.strftime("%H.%M.%S")
    sql_add()
    sql_update("Isim",masa_isim)
    sql_update("Masa",masa_no)
    sql_update("Tarih",tarih)
    sql_update("Giris_Saati",giris_saati)

def odeme_al():
    ileri_git()
    now = datetime.datetime.now()
    cikis_saati = now.strftime("%H.%M.%S")
    sql_update("Cikis_Saati",cikis_saati)
    print(toplam_tutar)
    sql_update("Tutar",toplam_tutar)
    print(toplam_siparis)
    sql_update("Siparis",toplam_siparis)
    

def odeme_yap():
    global musteri_id
    lambda: messagebox.showinfo("Tutar", f"Ödeme tutarı: {hesapla_tutar()} TL")
    for i in range(4):
        geri_git()
    musteri_id = musteri_id + 1

# Canvas'da masaların durumunu göstermek için bir fonksiyon
def masa_durumunu_goster():
    masa_canvas.delete("all")  # Önceki masa durumunu temizle
    for masa in masalar:
        masa_rengi = "green" if not masa.dolu_mu else "red"
        masa_canvas.create_rectangle(masa.masa_no*50, 50, masa.masa_no*50+40, 90, fill=masa_rengi)
        masa_canvas.create_text(masa.masa_no*50+20, 70, text=str(masa.masa_no), fill="white")
        isim_etiketi = tk.Label(musteri_frame, text="Müşteri Adı:", font=("Arial", 12), bg="light blue")
    isim_etiketi.pack()
    global isim_girdisi
    isim_girdisi = tk.Entry(musteri_frame)
    isim_girdisi.pack()

    masa_etiketi = tk.Label(musteri_frame, text="Masa Numarası:", font=("Arial", 12), bg="light blue")
    masa_etiketi.pack()

    global masa_secim
    masa_secim = tk.Entry(musteri_frame)
    masa_secim.pack()

    musteri_girisi_btn = tk.Button(musteri_frame, text="İleri Git", command = musteri_al, bg="green", fg="white", font=("Arial", 12, "bold"), padx=10, pady=10)
    musteri_girisi_btn.pack(pady=20)
    

    musteri_frame.pack(fill='both', expand=True)

#***************************************** MAİN CODE**************************************************************
# Menü öğelerini oluşturalım

steps = [
    {"adim": "Müşteri Girişi", "islev": adim_musteri_girisi},
    {"adim": "Menü Seçimi", "islev": adim_menu_secimi},
    {"adim": "Sipariş Onayı", "islev": adim_siparis_onayi},
    {"adim": "Ödeme", "islev": adim_odeme}
]

current_step = 0
pasta_menu = [
    ("Pesto Soslu", 50, ["Pesto Sosu", "Makarna"]),
    ("Bolonez Soslu", 55, ["Domates Sosu", "Makarna", "Sarımsak", "Soğan", "Kıyma"]),
    ("Köri Soslu", 65, ["Köri Sosu", "Krema", "Köri", "Makarna"]),
    ("Arabiata Soslu", 53, ["Domates Sosu", "Acı Biber", "Makarna"]),
    ("Kremalı Mantarlı", 57, ["Krema", "Mantar", "Makarna"]),
    ("Napoliten Soslu", 55, ["Krema", "Mantar", "Makarna"]),
    ("Alfredo", 50, ["Üç Peynirli", "Makarna"])
]

drink_menu = [
    ("Su", 8, ["Su"]),
    ("Soda", 10, ["Soda"]),
    ("Kola", 20, ["Kola"]),
    ("Ayran", 18, ["Ayran"]),
    ("Sprite", 20, ["Sprite"]),
    ("Fanta", 20, ["Fanta"]),
    ("Ice Tea", 20, ["Şeftalili Soğuk Çay"]),
    ("Meyve Suyu", 20, ["Şeftali Suyu"])
]

dessert_menu = [
    ("Tiramisu (Alkollü)", 65, ["Likör", "Kek", "Kahve", "Krema"]),
    ("Tiramisu", 57, ["Kek", "Krema","Kahve"]),
    ("Vişneli Brownie", 55, ["Brownie Keki", "Vişne"]),
    ("Çikolata Brownie", 55, ["Brownie Keki", "Çikolata"]),
    ("Vişneli Cheescake", 60, ["Cheesecake Keki", "Vişne"]),
    ("Limonlu Cheesecake", 60, ["Cheesecake Keki", "Limon"]),
    ("Ekler porsiyon ", 15, ["Kek", "Pastacı Kreması"]),
    ("Ekler kilogram ", 150, ["Kek", "Pastacı Kreması"])
]
pasta_items = [Pasta(name, price, ingredients) for name, price, ingredients in pasta_menu]
drink_items = [Drink(name, price, ingredients) for name, price, ingredients in drink_menu]
dessert_items = [Dessert(name, price, ingredients) for name, price, ingredients in dessert_menu] 

# Siparişlerin adetlerini tutmak için bir sözlük 
siparisler = {}

siparis_onaylandi_mi = False

# Menünün oluşturulması
menu_items = pasta_items + drink_items + dessert_items
menu = Menu(menu_items)

# Menü seçeneklerini ve fiyatlarını bir sözlük olarak oluşturun
menu_fiyatlari = {item.name: item.price for item in menu.items}
secenekler = list(menu_fiyatlari.keys())
secilenler = {item.name: item.name for item in menu.items}
son_secilenler = list(secilenler.keys())


# Masaların oluşturulması
masalar = [Masa(i) for i in range(1, 9)]  # 10 masa oluşturuldu
root = tk.Tk()
root.title("Restoran Hizmeti Sistemi")
root.geometry("800x800")  # Pencere boyutunu belirle

# Müşteri Girişi Adımı
musteri_frame = tk.Frame(root, bg="light blue")
musteri_baslik = tk.Label(musteri_frame, text="ZEGESA RESTORAN \n\nMÜŞTERİ GİRİŞİ YAPINIZ", font=("Arial", 16), bg="light blue")
musteri_baslik.pack(pady=20)

# Masaların durumunu gösteren bir Canvas widget
masa_canvas = tk.Canvas(musteri_frame, width=500, height=100)
masa_canvas.pack(pady=20)
masa_durumunu_goster()  # İlk yüklemede masa durumunu göster


# Menü Seçimi Adımı
menu_frame = tk.Frame(root, bg="light green")
menu_baslik = tk.Label(menu_frame, text="MENÜDEN SİPARİŞİ BELİRLEYİNİZ", font=("Arial", 16), bg="light green")
menu_baslik.pack(pady=20)

tree = ttk.Treeview(menu_frame)
tree["columns"] = ("#1", "#2")

tree.column("#0", width=190, minwidth=150, stretch=tk.NO)
tree.column("#1", width=100, minwidth=80, stretch=tk.NO)
tree.column("#2", width=80, minwidth=80, stretch=tk.NO)

tree.heading("#0", text="Menü Öğesi", anchor=tk.W)
tree.heading("#1", text="Fiyat", anchor=tk.W)
tree.heading("#2", text="Seç", anchor=tk.W)

def select_item(event):
    for selected_item in tree.selection():
        item_text = tree.item(selected_item, "text")
        # Fiyat değerini çekelim, eğer bu bir kategori başlığı ise fiyatı olmayacak
        item_price = tree.item(selected_item, "values")[0]

        # Eğer siparişlerde bu öğe varsa adedini arttır
        if item_text in siparisler and item_price:
            siparisler[item_text] += 1
        elif item_price:  # Eğer bu bir kategori başlığı değilse
            # Yoksa yeni bir öğe oluştur ve adedini 1 yap
            siparisler[item_text] = 1

        # listbox'u güncelle
        listbox.delete(0, tk.END)
        for siparis, adet in siparisler.items():
            listbox.insert(tk.END, f"{siparis} - {adet}")
        update_total()  # total cost'u güncelle

tree.bind("<Double-1>", select_item)  # Menü öğesini çift tıklama ile seçiyoruz

...
# Ana kategori düğümleri oluşturuluyor
pasta_node = tree.insert("", "end", text="Makarnalar", values=("",""))
drink_node = tree.insert("", "end", text="İçecekler", values=("",""))
dessert_node = tree.insert("", "end", text="Tatlılar", values=("",""))

# Her bir kategorinin altına ilgili menü öğeleri ekleniyor
for item in pasta_menu:
    tree.insert(pasta_node, "end", text=item[0], values=(item[1], "Seç"))
for item in drink_menu:
    tree.insert(drink_node, "end", text=item[0], values=(item[1], "Seç"))
for item in dessert_menu:
    tree.insert(dessert_node, "end", text=item[0], values=(item[1], "Seç"))

tree.pack()

listbox = tk.Listbox(menu_frame, selectmode=tk.MULTIPLE, height=10)
listbox.pack()

def remove_item(event):
    selected_item = listbox.get(listbox.curselection())
    item_text = selected_item.split(' - ')[0]  # öğenin adını alıyoruz

    # Eğer siparişlerde bu öğe varsa adedini azalt
    if item_text in siparisler:
        siparisler[item_text] -= 1
        # Eğer adet 0'a düşerse öğeyi tamamen kaldır
        if siparisler[item_text] <= 0:
            del siparisler[item_text]

    # listbox'u güncelle
    listbox.delete(0, tk.END)
    for siparis, adet in siparisler.items():
        listbox.insert(tk.END, f"{siparis} - {adet}")
    update_total()  # total cost'u güncelle

# Öğeyi listbox'tan sol tıklama (Button-1) ile çıkartıyoruz
listbox.bind("<Button-1>", remove_item)

def remove_item_completely(event):
    selected_item = listbox.get(listbox.curselection())
    item_text = selected_item.split(' - ')[0]  # öğenin adını alıyoruz

    # Eğer siparişlerde bu öğe varsa tamamen çıkar
    if item_text in siparisler:
        del siparisler[item_text]

    # listbox'u güncelle
    listbox.delete(0, tk.END)
    for siparis, adet in siparisler.items():
        listbox.insert(tk.END, f"{siparis} - {adet}")
    update_total()  # total cost'u güncelle

# Öğeyi listbox'tan Shift + Sol Tıklama (Shift-1) ile tamamen çıkartıyoruz
listbox.bind("<Shift-1>", remove_item_completely)

def update_total():
    total_cost.config(text=f"Toplam Tutar: {hesapla_tutar()} TL")

listbox.bind('<<ListboxSelect>>', lambda event: update_total())

menu_secimi_btn = tk.Button(menu_frame, text="İleri Git", command=ileri_git, bg="green", fg="white", font=("Arial", 12, "bold"), padx=10, pady=10)
menu_secimi_btn.pack(pady=20)

menu_secimi_geri_btn = tk.Button(menu_frame, text="Geri Git", command=geri_git, bg="red", fg="white", font=("Arial", 12, "bold"), padx=10, pady=10)
menu_secimi_geri_btn.pack(pady=20)



# Sipariş Onayı Adımı
siparis_frame = tk.Frame(root, bg="light yellow")
siparis_baslik = tk.Label(siparis_frame, text="SİPARİŞİ ONAY", font=("Arial", 16), bg="light yellow")
siparis_baslik.pack(pady=20)

onay = tk.BooleanVar(root)
onay_checkbtn = tk.Checkbutton(siparis_frame, text="Siparişi Onayla", variable=onay, bg="light yellow")
onay_checkbtn.pack()

siparis_onayi_btn = tk.Button(siparis_frame, text="İleri Git", command=odeme_al, bg="green", fg="white", font=("Arial", 12, "bold"), padx=10, pady=10)
siparis_onayi_btn.pack(pady=20)

siparis_onayi_geri_btn = tk.Button(siparis_frame, text="Geri Git", command=geri_git, bg="red", fg="white", font=("Arial", 12, "bold"), padx=10, pady=10)
siparis_onayi_geri_btn.pack(pady=20)

# Ödeme Adımı
odeme_frame = tk.Frame(root, bg="light gray")
odeme_baslik = tk.Label(odeme_frame, text="ÖDEME", font=("Arial", 16), bg="light gray")
odeme_baslik.pack(pady=20)

# Siparişin tutarını hesaplamak için bir fonksiyon
def hesapla_tutar():
    global toplam_tutar
    toplam_tutar = 0
    global toplam_siparis
    toplam_siparis = ''
    for siparis, adet in siparisler.items():

        toplam_siparis = toplam_siparis + secilenler[siparis]*adet + "-"
        print(toplam_siparis)
        toplam_tutar += menu_fiyatlari[siparis] * adet  # fiyatı sipariş adedi ile çarpıp toplam tutara ekliyoruz
    sql_update("Tutar", toplam_tutar)
    return toplam_tutar

total_cost = tk.Label(odeme_frame, text=f"Toplam Tutar: {hesapla_tutar()} TL", bg="light gray")
total_cost.pack()

payment_methods = ["Kredi Kartı", "Nakit"]
payment_method = str(tk.StringVar(value=payment_methods[0]))


for method in payment_methods:
    tk.Radiobutton(odeme_frame, text=method, variable=payment_method, value=method, bg="light gray").pack()

odeme_btn = tk.Button(odeme_frame, text="Ödeme Yap", command=odeme_yap, bg="green", fg="white", font=("Arial", 12, "bold"), padx=10, pady=10)
odeme_btn.pack(pady=20)

odeme_geri_btn = tk.Button(odeme_frame, text="Geri Git", command=geri_git, bg="red", fg="white", font=("Arial", 12, "bold"), padx=10, pady=10)
odeme_geri_btn.pack(pady=20)


root.mainloop()
conn.close()