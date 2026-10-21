# main.py
import tkinter as tk
from tkinter import ttk, messagebox
import psycopg2
from psycopg2 import Error
from pets_tab import PetsTab
from appointments_tab import AppointmentsTab
from shop_tab import ShopTab
from login import LoginWindow

class VetCareApp:
    def __init__(self, root):
        self.root = root
        self.root.title("VetCare Yönetim Sistemi")
        self.root.withdraw()  # Başlangıçta ana pencereyi gizle
        self.connect_db()
        self.show_login()

    def connect_db(self):
        try:
            self.conn = psycopg2.connect(
                database="PYvetcareDB",
                user="postgres",
                password="123456",
                host="localhost",
                port="5432"
            )
            self.cur = self.conn.cursor()
        except Error as e:
            messagebox.showerror("Database Hatası", str(e))
            self.root.destroy()

    def show_login(self):
        """Giriş penceresini göster ve kimlik doğrulamasını bekle"""
        login_window = LoginWindow(self.root, self.conn, self.cur)
        self.root.wait_window(login_window.window)
        
        if login_window.logged_in:
            self.current_user_id = login_window.current_user_id
            self.root.deiconify()  # Ana pencereyi göster
            self.setup_ui()
        else:
            self.root.destroy()

    def setup_ui(self):
        # Notebook örnek değişkeni olarak oluştur
        self.notebook = ttk.Notebook(self.root)
        self.notebook.pack(pady=0, expand=True)

        # Sekmeleri geçerli user ID ile başlat
        self.pets_tab = PetsTab(self.notebook, self.conn, self.cur, self.current_user_id)
        self.appointments_tab = AppointmentsTab(self.notebook, self.conn, self.cur, self.current_user_id)
        self.shop_tab = ShopTab(self.notebook, self.conn, self.cur, self.current_user_id)

        # Notebook sekmeler ekle
        self.notebook.add(self.pets_tab, text="Evcil Hayvanlar")
        self.notebook.add(self.appointments_tab, text="Randevular")
        self.notebook.add(self.shop_tab, text="Mağaza")

        # Sekme degisimde guncelleme
        self.notebook.bind('<<NotebookTabChanged>>', self.on_tab_change)

    def on_tab_change(self, event):
        # Mevcut sekmeyi al
        current_tab = self.notebook.select()
        tab_text = self.notebook.tab(current_tab, "text")
        
        # Randevular sekmesine geçiliyorsa, evcil hayvan listesini günceller
        if tab_text == "Randevular":
            self.appointments_tab.on_tab_selected()

if __name__ == "__main__":
    root = tk.Tk()
    app = VetCareApp(root)
    root.mainloop()