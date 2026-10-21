# login.py
import tkinter as tk
from tkinter import ttk, messagebox
import hashlib
import re
from psycopg2 import Error

class LoginWindow:
    def __init__(self, parent, db_connection, db_cursor):
        self.parent = parent
        self.conn = db_connection
        self.cur = db_cursor
        self.logged_in = False
        self.current_user_id = None
        
        self.window = tk.Toplevel(parent)
        self.window.title("VetCare Login")
        self.window.geometry("300x450")
        self.window.protocol("WM_DELETE_WINDOW", self.on_closing)
        
        self.setup_ui()
        
    def setup_ui(self):
        # Main frame
        main_frame = ttk.Frame(self.window, padding="20")
        main_frame.pack(fill="both", expand=True)
        
        # Title
        title_label = ttk.Label(main_frame, text="VetCare Login", font=("Helvetica", 16, "bold"))
        title_label.pack(pady=20)
        
        # Login frame
        self.login_frame = ttk.Frame(main_frame)
        self.login_frame.pack(fill="both", expand=True)
        
        # Username
        ttk.Label(self.login_frame, text="Kullanıcı Adı:").pack(fill="x", pady=5)
        self.username_var = tk.StringVar()
        self.username_entry = ttk.Entry(self.login_frame, textvariable=self.username_var)
        self.username_entry.pack(fill="x", pady=5)
        
        # Password
        ttk.Label(self.login_frame, text="Şifre:").pack(fill="x", pady=5)
        self.password_var = tk.StringVar()
        self.password_entry = ttk.Entry(self.login_frame, textvariable=self.password_var, show="*")
        self.password_entry.pack(fill="x", pady=5)
        
        # Login button
        ttk.Button(self.login_frame, text="Giriş", command=self.login).pack(fill="x", pady=20)
        
        # Register link
        ttk.Label(self.login_frame, text="Hesabınız yok mu?").pack(pady=5)
        register_link = ttk.Button(self.login_frame, text="Kayıt ol", command=self.show_register)
        register_link.pack(pady=5)
        
        # Register frame (başlangıçta gizli)
        self.register_frame = ttk.Frame(main_frame)
        
        # Username
        ttk.Label(self.register_frame, text="Kullanıcı Adı:").pack(fill="x", pady=5)
        self.reg_username_var = tk.StringVar()
        self.reg_username_entry = ttk.Entry(self.register_frame, textvariable=self.reg_username_var)
        self.reg_username_entry.pack(fill="x", pady=5)
        
        # Email
        ttk.Label(self.register_frame, text="E-posta:").pack(fill="x", pady=5)
        self.reg_email_var = tk.StringVar()
        self.reg_email_entry = ttk.Entry(self.register_frame, textvariable=self.reg_email_var)
        self.reg_email_entry.pack(fill="x", pady=5)
        
        # Phone
        ttk.Label(self.register_frame, text="Tel:").pack(fill="x", pady=5)
        self.reg_phone_var = tk.StringVar()
        self.reg_phone_entry = ttk.Entry(self.register_frame, textvariable=self.reg_phone_var)
        self.reg_phone_entry.pack(fill="x", pady=5)
        
        # Password
        ttk.Label(self.register_frame, text="Şifre:").pack(fill="x", pady=5)
        self.reg_password_var = tk.StringVar()
        self.reg_password_entry = ttk.Entry(self.register_frame, textvariable=self.reg_password_var, show="*")
        self.reg_password_entry.pack(fill="x", pady=5)
        
        # Register button
        ttk.Button(self.register_frame, text="Kayıt olmak", command=self.register).pack(fill="x", pady=20)
        
        # Back to login link
        ttk.Button(self.register_frame, text="Girişe Geri Dön", command=self.show_login).pack(pady=5)
        
    def show_register(self):
        self.login_frame.pack_forget()
        self.register_frame.pack(fill="both", expand=True)
        
    def show_login(self):
        self.register_frame.pack_forget()
        self.login_frame.pack(fill="both", expand=True)
        
    def hash_password(self, password):
        """Parolanın SHA-256 karmasını oluşturun"""
        return hashlib.sha256(password.encode()).hexdigest()
    
    def validate_email(self, email):
        """E-posta formatını doğrula"""
        pattern = r'^[\w\.-]+@[\w\.-]+\.\w+$'
        return re.match(pattern, email) is not None
    
    def validate_phone(self, phone):
        """Telefon numarası formatını doğrula"""
        pattern = r'^\+?1?\d{9,15}$'
        return re.match(pattern, phone) is not None
    
    def register(self):
        """Kullanıcı kaydını yönetir"""
        username = self.reg_username_var.get().strip()
        email = self.reg_email_var.get().strip()
        phone = self.reg_phone_var.get().strip()
        password = self.reg_password_var.get()
        
        # Doğrulama
        if not all([username, email, password]):
            messagebox.showerror("Hata", "Lütfen tüm gerekli alanları doldurun")
            return
            
        if not self.validate_email(email):
            messagebox.showerror("Hata", "Geçersiz e-posta formatı")
            return
            
        if phone and not self.validate_phone(phone):
            messagebox.showerror("Hata", "Geçersiz telefon numarası formatı")
            return
            
        try:
            # Hash password
            password_hash = self.hash_password(password)
            
            # Yeni kullanıcı ekle
            self.cur.execute("""
                INSERT INTO users (username, email, password_hash, phone)
                VALUES (%s, %s, %s, %s)
                RETURNING user_id
            """, (username, email, password_hash, phone))
            
            self.conn.commit()
            messagebox.showinfo("Başarılı", "Kayıt başarılı! Giriş yapabilirsiniz.")
            self.show_login()
            
        except Error as e:
            self.conn.rollback()
            if "username" in str(e):
                messagebox.showerror("Hata", "Kullanıcı adı zaten mevcut")
            elif "email" in str(e):
                messagebox.showerror("Hata", "E-posta zaten kayıtlı")
            else:
                messagebox.showerror("Hata", str(e))
    
    def login(self):
        """Kullanıcı girişini yönetimi"""
        username = self.username_var.get().strip()
        password = self.password_var.get()
        
        if not username or not password:
            messagebox.showerror("Hata", "Lütfen hem kullanıcı adınızı hem de şifrenizi girin")
            return
            
        try:
            # Kullanıcı adına göre kullanıcıyı al ve şifreyi kontrol etme
            self.cur.execute("""
                SELECT user_id, password_hash 
                FROM users 
                WHERE username = %s
            """, (username,))
            
            result = self.cur.fetchone()
            if result and result[1] == self.hash_password(password):
                self.logged_in = True
                self.current_user_id = result[0]
                self.window.destroy()
            else:
                messagebox.showerror("Hata", "Geçersiz kullanıcı adı veya şifre")
                
        except Error as e:
            messagebox.showerror("Hata", str(e))
    
    def on_closing(self):
        """Pencere kapatma kolu"""
        if not self.logged_in:
            self.parent.destroy()
        else:
            self.window.destroy()