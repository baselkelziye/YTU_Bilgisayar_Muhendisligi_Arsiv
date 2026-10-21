# pets_tab.py
import tkinter as tk
from tkinter import ttk, messagebox
from psycopg2 import Error

class PetsTab(ttk.Frame):
    def __init__(self, parent, conn, cur, user_id):
        super().__init__(parent)
        self.conn = conn
        self.cur = cur
        self.user_id = user_id
        self.setup_ui()

    def setup_ui(self):
        # Notebook oluşturma
        self.notebook = ttk.Notebook(self)
        self.notebook.pack(fill='both', expand=True)
        
        # Pet Tablosunu güncelleme
        self.update_pet_list()

        # Evcil Hayvanlarım Sekmesi
        self.pets_frame = ttk.Frame(self.notebook)
        self.notebook.add(self.pets_frame, text='Evcil Hayvanlarım')
        
        # İstatistik sekmesi
        self.stats_frame = ttk.Frame(self.notebook)
        self.notebook.add(self.stats_frame, text='Genel İstatistikler')
        
        # Eşleşme sekmesi
        self.match_frame = ttk.Frame(self.notebook)
        self.notebook.add(self.match_frame, text='Hayvan Eşi Bul')

        # Evcil hayvan sekmesini ayarlama
        self.create_add_pet_form(self.pets_frame)
        self.create_pet_list(self.pets_frame)
        
        # İstatistik sekmesini ayarlama
        self.create_stats_ui(self.stats_frame)

        # Eşleşme sekmesini ayarlama
        self.create_find_match_tab()


    def create_find_match_tab(self):
        # Üst kısım için frame
        top_frame = ttk.Frame(self.match_frame)
        top_frame.pack(fill='x', padx=10, pady=5)
        
        ttk.Label(top_frame, text="Evcil Hayvanınız:").pack(side='left', padx=5)
        self.match_pet_combo = ttk.Combobox(top_frame, values=list(self.pet_dict.keys()))
        self.match_pet_combo.pack(side='left', padx=5)

        # Eşleşme sonuçları için frame
        results_frame = ttk.Frame(self.match_frame)
        results_frame.pack(fill='both', expand=True, padx=10, pady=5)

        # Treeview ve scrollbar
        columns = ("Ad", "Tür", "Irk", "Yaş", "Ağırlık", "Sahip")
        self.match_tree = ttk.Treeview(results_frame, columns=columns, show="headings", height=10)
        
        # Scrollbar ekleme
        scrollbar = ttk.Scrollbar(results_frame, orient="vertical", command=self.match_tree.yview)
        self.match_tree.configure(yscrollcommand=scrollbar.set)
        
        # Treeview sütunlarını yapılandırma
        for col in columns:
            self.match_tree.heading(col, text=col)
            self.match_tree.column(col, width=120)
        
        # Treeview ve scrollbar'ı yerleştirme
        self.match_tree.pack(side='left', fill='both', expand=True)
        scrollbar.pack(side='right', fill='y')

        # Alt kısım için frame
        bottom_frame = ttk.Frame(self.match_frame)
        bottom_frame.pack(fill='x', padx=10, pady=10)
        
        # Eşleşme bul butonu
        ttk.Button(bottom_frame, text="Eşleşme Bul", command=self.find_pet_match).pack(pady=5)

    def find_pet_match(self):
        """Seçilen hayvan için eşleşme bul ve sonucu göster."""
        selected_pet = self.match_pet_combo.get()
        if not selected_pet:
            messagebox.showwarning("Uyarı", "Lütfen bir hayvan seçin!")
            return

        pet_id = self.pet_dict.get(selected_pet)
        try:
            self.cur.execute("SELECT * FROM find_pet_matches(%s)", (pet_id,))
            matches = self.cur.fetchall()

            # Treeview temizle
            for item in self.match_tree.get_children():
                self.match_tree.delete(item)

            # Sonuçları ekle
            for match in matches:
                self.match_tree.insert("", "end", values=match)
        except Error as e:
            messagebox.showerror("Hata", f"Eşleşmeler bulunamadı: {str(e)}")

    def update_pet_list(self):
        """Evcil hayvan seçimi açılır menüsünü günceller"""
        try:
            self.cur.execute("""
                SELECT pet_id, name 
                FROM pets 
                WHERE user_id = %s
                ORDER BY name
            """, (self.user_id,))
            pets = self.cur.fetchall()
            self.pet_dict = {f"{pet[1]} (ID: {pet[0]})": pet[0] for pet in pets}
        except Error as e:
            messagebox.showerror("Hata", str(e))

    def create_stats_ui(self, parent):
        # Species statistics tree
        species_frame = ttk.LabelFrame(parent, text="Tür İstatistikleri")
        species_frame.pack(pady=10, padx=10, fill="x")
        
        columns = ("Tür", "Hayvan Sayısı", "Ortalama Yaş", "Ortalama Kilo", "En Popüler Irk")
        self.stats_tree = ttk.Treeview(species_frame, columns=columns, show="headings", height=6)
        
        for col in columns:
            self.stats_tree.heading(col, text=col)
            self.stats_tree.column(col, width=120)
        
        self.stats_tree.pack(pady=5, fill="x")
        
        # Yaş Grubu istatistik
        age_frame = ttk.LabelFrame(parent, text="Yaş Grubu İstatistikleri")
        age_frame.pack(pady=10, padx=10, fill="x")
        
        age_columns = ("Yaş Grubu", "Hayvan Sayısı", "Ortalama Kilo")
        self.age_tree = ttk.Treeview(age_frame, columns=age_columns, show="headings", height=4)
        
        for col in age_columns:
            self.age_tree.heading(col, text=col)
            self.age_tree.column(col, width=120)
        
        self.age_tree.pack(pady=5, fill="x")
        
        # Refresh button
        ttk.Button(parent, text="Yenile", command=self.refresh_stats).pack(pady=10)
        
        # Initial yükleme
        self.refresh_stats()

    def refresh_stats(self):
        """Verileri Temizleme"""
        # Olan verileri temizleme
        for item in self.stats_tree.get_children():
            self.stats_tree.delete(item)
        for item in self.age_tree.get_children():
            self.age_tree.delete(item)
        
        try:
            # Tür istatistikleri - en az 2 hayvanı olan türler
            self.cur.execute("""
                WITH breed_counts AS (
                    SELECT species, breed, COUNT(*) as breed_count
                    FROM pets
                    WHERE breed IS NOT NULL
                    GROUP BY species, breed
                ),
                most_popular_breeds AS (
                    SELECT species, breed, breed_count,
                        ROW_NUMBER() OVER (PARTITION BY species ORDER BY breed_count DESC) as rn
                    FROM breed_counts
                )
                SELECT 
                    p.species,
                    COUNT(*) as total_pets,
                    ROUND(AVG(age)::numeric, 1) as avg_age,
                    ROUND(AVG(weight)::numeric, 1) as avg_weight,
                    mpb.breed as popular_breed
                FROM pets p
                LEFT JOIN most_popular_breeds mpb ON p.species = mpb.species AND mpb.rn = 1
                GROUP BY p.species, mpb.breed
                HAVING COUNT(*) >= 2
                ORDER BY total_pets DESC
            """)
            
            for row in self.cur.fetchall():
                self.stats_tree.insert("", "end", values=row)
            
            # Yaş grubu istatistikleri - en az 3 hayvanı olan gruplar
            self.cur.execute("""
                WITH age_group_data AS (
                    SELECT 
                        CASE 
                            WHEN age < 2 THEN 'Yavru (0-2)'
                            WHEN age < 7 THEN 'Yetişkin (2-7)'
                            ELSE 'Yaşlı (7+)'
                        END AS age_group,
                        COUNT(*) AS pet_count,
                        ROUND(AVG(weight)::numeric, 1) AS avg_weight
                    FROM pets
                    GROUP BY 
                        CASE 
                            WHEN age < 2 THEN 'Yavru (0-2)'
                            WHEN age < 7 THEN 'Yetişkin (2-7)'
                            ELSE 'Yaşlı (7+)'
                        END
                    HAVING COUNT(*) >= 3
                )
                SELECT 
                    age_group, 
                    pet_count, 
                    avg_weight
                FROM age_group_data
                ORDER BY 
                    CASE 
                        WHEN age_group = 'Yavru (0-2)' THEN 1
                        WHEN age_group = 'Yetişkin (2-7)' THEN 2
                        ELSE 3
                    END;
            """)
            
            for row in self.cur.fetchall():
                self.age_tree.insert("", "end", values=row)
                
        except Error as e:
            messagebox.showerror("Hata", str(e))

    def create_add_pet_form(self, parent):
        # Form Frame
        add_frame = ttk.LabelFrame(parent, text="Yeni Hayvan Ekle")
        add_frame.pack(pady=10, padx=10, fill="x")

        # İsim ve tür
        ttk.Label(add_frame, text="Ad:").grid(row=0, column=0, pady=5, padx=5)
        self.pet_name = ttk.Entry(add_frame)
        self.pet_name.grid(row=0, column=1, pady=5, padx=5)

        ttk.Label(add_frame, text="Türler:").grid(row=0, column=2, pady=5, padx=5)
        self.pet_species = ttk.Combobox(add_frame, values=["Köpek", "Kedi", "Kuş", "Diğer"])
        self.pet_species.grid(row=0, column=3, pady=5, padx=5)

        # Irk ve Yaş
        ttk.Label(add_frame, text="Irk:").grid(row=1, column=0, pady=5, padx=5)
        self.pet_breed = ttk.Entry(add_frame)
        self.pet_breed.grid(row=1, column=1, pady=5, padx=5)

        ttk.Label(add_frame, text="Yaş:").grid(row=1, column=2, pady=5, padx=5)
        self.pet_age = ttk.Entry(add_frame, width=10)
        self.pet_age.grid(row=1, column=3, pady=5, padx=5)

        # Ağırlık
        ttk.Label(add_frame, text="Ağırlık (kg):").grid(row=2, column=0, pady=5, padx=5)
        self.pet_weight = ttk.Entry(add_frame, width=10)
        self.pet_weight.grid(row=2, column=1, pady=5, padx=5)

        # Buton ile hayvan ekleme
        ttk.Button(add_frame, text="Evcil Hayvan Ekle", command=self.add_pet).grid(
            row=2, column=2, columnspan=2, pady=10, padx=5, sticky="ew")

    def create_pet_list(self, parent):
        # Liste
        list_frame = ttk.LabelFrame(parent, text="Evcil Hayvan Listesi")
        list_frame.pack(pady=10, padx=10, fill="both", expand=True)

        # Treeview oluşturma
        columns = ("ID", "İsim", "Tür", "Irk", "Yaş", "Ağırlık")  
        self.pet_tree = ttk.Treeview(list_frame, columns=columns, show="headings")
        
        # ID gizli yapma
        self.pet_tree.heading("ID", text="ID")
        self.pet_tree.column("ID", width=0, stretch=False)
        
        # Scrollbar ekleme
        scrollbar = ttk.Scrollbar(list_frame, orient="vertical", command=self.pet_tree.yview)
        self.pet_tree.configure(yscrollcommand=scrollbar.set)

        # Görünür sütunlarla işlem
        for col in columns[1:]:  # ID yi geçerek işleme devam
            self.pet_tree.heading(col, text=col)
            if col == "İsim":
                self.pet_tree.column(col, width=150)
            else:
                self.pet_tree.column(col, width=100)

        # Pack Treeview 
        self.pet_tree.pack(pady=10, padx=10, fill="both", expand=True)
        scrollbar.pack(side="right", fill="y")

        # İnsan hayvan yaş hesabı
        calc_frame = ttk.Frame(list_frame)
        calc_frame.pack(pady=5, padx=10, fill="x")

        # Hesapla button
        calc_button = ttk.Button(calc_frame, text="İnsan Yaşını Hesapla", command=self.calculate_human_age)
        calc_button.pack(side="left", padx=5)

        # Sonuç label
        self.human_age_label = ttk.Label(calc_frame, text="")
        self.human_age_label.pack(side="left", padx=5)

        # Ön yükleme
        self.refresh_pets()

    def calculate_human_age(self):
        """İnsan yaşını hesaplama ve gösterme"""
        selected_item = self.pet_tree.selection()
        if not selected_item:
            messagebox.showwarning("Uyarı", "Lütfen bir evcil hayvan seçin")
            return

        values = self.pet_tree.item(selected_item)['values']
        pet_age = values[4]  # yaş = 4
        pet_species = values[2]  # tür = 2

        try:
            self.cur.execute("SELECT calculate_human_age(%s, %s)", (pet_age, pet_species))
            human_age = self.cur.fetchone()[0]
            self.human_age_label.config(text=f"İnsan yaşı karşılığı: {human_age} yıl")
        except Error as e:
            messagebox.showerror("Hata", str(e))

    def create_control_buttons(self):
        # Buttons Frame
        btn_frame = ttk.Frame(self)
        btn_frame.pack(pady=5)
        
        # Kontrol butonları
        ttk.Button(btn_frame, text="Yenile", command=self.refresh_pets).pack(side="left", padx=5)
        ttk.Button(btn_frame, text="Güncelle", command=self.update_pet).pack(side="left", padx=5)
        ttk.Button(btn_frame, text="Sil", command=self.delete_pet).pack(side="left", padx=5)

    def add_pet(self):
        # Formlardan veri alma
        name = self.pet_name.get().strip()
        species = self.pet_species.get().strip()
        breed = self.pet_breed.get().strip()
        age = self.pet_age.get().strip()
        weight = self.pet_weight.get().strip()

        # Temel doğrulama
        if not name or not species:
            messagebox.showwarning("Uyarı", "İsim ve tür gereklidir")
            return

        try:
            # Çevir ve yaş hesabı
            age_val = None
            if age:
                age_val = int(age)
                if age_val < 0 or age_val > 30:
                    messagebox.showwarning("Uyarı", "Yaş 0 ile 30 arasında olmalıdır")
                    return

            # Çevir ve ağırlık doğrulama
            weight_val = None
            if weight:
                weight_val = float(weight)
                if weight_val <= 0:
                    messagebox.showwarning("Uyarı", "Ağırlık 0'dan büyük olmalıdır")
                    return

            # SQL query 
            query = """
                INSERT INTO pets (user_id, name, species, breed, age, weight)
                VALUES (%s, %s, %s, %s, %s, %s)
            """
            
            # Query'yi ayarlama
            self.cur.execute(query, (
                self.user_id,
                name,
                species,
                breed if breed else None,
                age_val,
                weight_val
            ))
            
            self.conn.commit()
            messagebox.showinfo("Başarılı", "Evcil hayvan başarıyla eklendi!")
            
            # Formu temizleme
            self.pet_name.delete(0, tk.END)
            self.pet_species.set('')
            self.pet_breed.delete(0, tk.END)
            self.pet_age.delete(0, tk.END)
            self.pet_weight.delete(0, tk.END)
            
            # Pet listesini yenile
            self.refresh_pets()
            
        except ValueError:
            messagebox.showerror("Hata", "Lütfen yaş ve kilo için geçerli sayılar giriniz")
        except Error as e:
            self.conn.rollback()
            messagebox.showerror("Hata", str(e))

    def refresh_pets(self):
        """Pet listesini yenile"""
        for item in self.pet_tree.get_children():
            self.pet_tree.delete(item)
        
        try:
            self.cur.execute("""
                SELECT pet_id, name, species, breed, age, weight 
                FROM pets 
                WHERE user_id = %s
                ORDER BY name
            """, (self.user_id,))
            
            pets = self.cur.fetchall()
            self.pet_dict = {f"{pet[1]} (ID: {pet[0]})": pet[0] for pet in pets}
            for pet in pets:
                self.pet_tree.insert("", "end", values=pet)
        except Error as e:
            messagebox.showerror("Hata", str(e))

    def update_pet(self):
        """Seçilen hayvanın bilgileri"""
        selected_item = self.pet_tree.selection()
        if not selected_item:
            messagebox.showwarning("Uyarı", "Lütfen güncellemek için bir evcil hayvan seçin")
            return

        # Current value değeri alma
        values = self.pet_tree.item(selected_item)['values']
        pet_id = values[0]
        
        # Update dialog oluşurma
        update_dialog = tk.Toplevel(self)
        update_dialog.title("Evcil Hayvan Güncelle")
        update_dialog.geometry("400x300")
        
        # Form alanları ekleme
        ttk.Label(update_dialog, text="Ad:").grid(row=0, column=0, pady=5, padx=5)
        name_entry = ttk.Entry(update_dialog)
        name_entry.insert(0, values[1])
        name_entry.grid(row=0, column=1, pady=5, padx=5)

        ttk.Label(update_dialog, text="Tür:").grid(row=1, column=0, pady=5, padx=5)
        species_combo = ttk.Combobox(update_dialog, values=["Köpek", "Kedi", "Kuş", "Diğer"])
        species_combo.set(values[2])
        species_combo.grid(row=1, column=1, pady=5, padx=5)

        ttk.Label(update_dialog, text="Irk:").grid(row=2, column=0, pady=5, padx=5)
        breed_entry = ttk.Entry(update_dialog)
        breed_entry.insert(0, values[3] if values[3] else "")
        breed_entry.grid(row=2, column=1, pady=5, padx=5)

        ttk.Label(update_dialog, text="Yaş:").grid(row=3, column=0, pady=5, padx=5)
        age_entry = ttk.Entry(update_dialog)
        age_entry.insert(0, values[4] if values[4] else "")
        age_entry.grid(row=3, column=1, pady=5, padx=5)

        ttk.Label(update_dialog, text="Ağırlık (kg):").grid(row=4, column=0, pady=5, padx=5)
        weight_entry = ttk.Entry(update_dialog)
        weight_entry.insert(0, values[5] if values[5] else "")
        weight_entry.grid(row=4, column=1, pady=5, padx=5)

        def save_updates():
            try:
                # Temel doğrulama
                name = name_entry.get().strip()
                species = species_combo.get().strip()
                if not name or not species:
                    messagebox.showwarning("Uyarı", "İsim ve tür gereklidir")
                    return

                # Yaş doğrulama 
                age = age_entry.get().strip()
                age_val = None
                if age:
                    age_val = int(age)
                    if age_val < 0 or age_val > 30:
                        messagebox.showwarning("Uyarı", "Yaş 0 ile 30 arasında olmalıdır")
                        return

                # Ağırlık doğrulama
                weight = weight_entry.get().strip()
                weight_val = None
                if weight:
                    weight_val = float(weight)
                    if weight_val <= 0:
                        messagebox.showwarning("Uyarı", "Ağırlık 0'dan büyük olmalıdır")
                        return

                # DB güncelleme
                self.cur.execute("""
                    UPDATE pets 
                    SET name = %s, species = %s, breed = %s, age = %s, weight = %s
                    WHERE pet_id = %s
                """, (
                    name,
                    species,
                    breed_entry.get().strip() or None,
                    age_val,
                    weight_val,
                    pet_id
                ))
                
                self.conn.commit()
                messagebox.showinfo("Başarılı", "Evcil hayvan başarıyla güncellendi!")
                update_dialog.destroy()
                self.refresh_pets()
                
            except ValueError:
                messagebox.showerror("Hata", "Lütfen yaş ve kilo için geçerli sayılar giriniz")
            except Error as e:
                self.conn.rollback()
                messagebox.showerror("Hata", str(e))

        # Kaydet butonu ekleme
        ttk.Button(update_dialog, text="Kaydet", command=save_updates).grid(
            row=5, column=0, columnspan=2, pady=20, padx=5)

    def delete_pet(self):
        selected_item = self.pet_tree.selection()
        if not selected_item:
            messagebox.showwarning("Uyarı", "Lütfen silmek için bir evcil hayvan seçin")
            return

        # Gizli ID verisini al
        pet_id = self.pet_tree.item(selected_item)['values'][0]
        
        if messagebox.askyesno("Onay", "Bu evcil hayvanı silmek istediğinizden emin misiniz?"):
            try:
                self.cur.execute("DELETE FROM pets WHERE pet_id = %s", (pet_id,))
                self.conn.commit()
                messagebox.showinfo("Başarılı", "Evcil hayvan başarıyla silindi!")
                self.refresh_pets()
            except Error as e:
                messagebox.showerror("Hata", str(e))