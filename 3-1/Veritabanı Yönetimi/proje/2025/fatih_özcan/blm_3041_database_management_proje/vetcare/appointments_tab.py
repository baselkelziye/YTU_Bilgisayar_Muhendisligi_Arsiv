import tkinter as tk
from tkinter import ttk, messagebox
from psycopg2 import Error
from datetime import date
from psycopg2 import sql

class AppointmentsTab(ttk.Frame):
    def __init__(self, parent, conn, cur, user_id):
        super().__init__(parent)
        self.conn = conn
        self.cur = cur
        self.user_id = user_id
        self.parent = parent
        self.root = parent
        self.setup_ui()

    def setup_ui(self):
        # Alt sekmeler için notebook oluşturma
        self.notebook = ttk.Notebook(self)
        self.notebook.pack(fill='both', expand=True)
        
        # Appointments sekmesi
        self.appointments_frame = ttk.Frame(self.notebook)
        self.notebook.add(self.appointments_frame, text='Randevular')
        
        # Vaccinations sekmesi
        self.vaccinations_frame = ttk.Frame(self.notebook)
        self.notebook.add(self.vaccinations_frame, text='Aşı Takibi')
        
        # Her form için ayrı pet_dict tanımlama
        self.appointment_pet_dict = {}
        self.vaccination_pet_dict = {}
        
        # Appointments frame orijinal randevu kullanıcı arayüzünü ayarlama
        self.create_booking_form(self.appointments_frame)
        self.create_appointments_list(self.appointments_frame)
        self.create_buttons(self.appointments_frame)
        
        # vaccinations UI ayarla
        self.create_vaccinations_ui()

    def create_vaccinations_ui(self):
        # Aşı ekleme formu
        add_vaccine_frame = ttk.LabelFrame(self.vaccinations_frame, text="Yeni Aşı Kaydı")
        add_vaccine_frame.pack(pady=10, padx=10, fill="x")

        # Evcil Hayvan Seçimi
        ttk.Label(add_vaccine_frame, text="Hayvan:").grid(row=0, column=0, padx=5, pady=5)
        self.vaccination_pet_select = ttk.Combobox(add_vaccine_frame)  
        self.vaccination_pet_select.grid(row=0, column=1, padx=5, pady=5)
        self.update_vaccination_pet_list()

        # Aşı Adı
        ttk.Label(add_vaccine_frame, text="Aşı Adı:").grid(row=0, column=2, padx=5, pady=5)
        self.vaccine_name_var = tk.StringVar()
        ttk.Entry(add_vaccine_frame, textvariable=self.vaccine_name_var).grid(row=0, column=3, padx=5, pady=5)

        # Geçerlilik Süresi (Sayı ve Birim)
        ttk.Label(add_vaccine_frame, text="Geçerlilik Süresi:").grid(row=1, column=0, padx=5, pady=5)
        self.validity_value_var = tk.StringVar()
        ttk.Entry(add_vaccine_frame, textvariable=self.validity_value_var, width=10).grid(row=1, column=1, padx=5, pady=5)

        self.validity_unit_var = tk.StringVar()
        validity_unit_options = ttk.Combobox(
            add_vaccine_frame, textvariable=self.validity_unit_var, width=10, state="readonly"
        )
        validity_unit_options["values"] = ("gün", "ay", "yıl")
        validity_unit_options.set("ay")  # Varsayılan birim "ay"
        validity_unit_options.grid(row=1, column=2, padx=5, pady=5)

        # Aşı Verilme Tarihi
        ttk.Label(add_vaccine_frame, text="Aşı Verildiği Tarih:").grid(row=2, column=0, padx=5, pady=5)
        self.date_given_var = tk.StringVar(value="YYYY-MM-DD")  # Varsayılan format
        date_given_entry = ttk.Entry(add_vaccine_frame, textvariable=self.date_given_var)
        date_given_entry.grid(row=2, column=1, padx=5, pady=5)

        # Kaydet Butonu
        ttk.Button(add_vaccine_frame, text="Kaydet", command=self.add_vaccination_record).grid(
            row=2, column=3, padx=5, pady=5
        )

        # Vaccinations Listesi
        list_frame = ttk.LabelFrame(self.vaccinations_frame, text="Yaklaşan Aşılar")
        list_frame.pack(pady=10, padx=10, fill="both", expand=True)

        # Vaccinations için Treeview oluşturun
        columns = ("Hayvan", "Tür", "Aşı", "Tarih", "Sahip", "Email")
        self.vaccination_tree = ttk.Treeview(list_frame, columns=columns, show="headings")
        
        # Sütunları yapılandırma
        for col in columns:
            self.vaccination_tree.heading(col, text=col)
            self.vaccination_tree.column(col, width=100)
        
        # Scrollbar ekleme
        scrollbar = ttk.Scrollbar(list_frame, orient="vertical", command=self.vaccination_tree.yview)
        self.vaccination_tree.configure(yscrollcommand=scrollbar.set)
        
        self.vaccination_tree.pack(side="left", pady=10, padx=10, fill="both", expand=True)
        scrollbar.pack(side="right", fill="y")

        # Refresh button ekleme
        ttk.Button(self.vaccinations_frame, text="Yenile", 
                command=self.refresh_vaccinations).pack(pady=5)

        # Vaccinations verilerinin ilk yüklemesi
        self.refresh_vaccinations()


    def refresh_vaccinations(self):
        """Vaccinations listesini yenile"""
        for item in self.vaccination_tree.get_children():
            self.vaccination_tree.delete(item)
        
        try:
            # upcoming_vaccinations view Query
            self.cur.execute("""
                SELECT pet_name, species, vaccine_name, next_due_date, 
                       owner_name, owner_email
                FROM upcoming_vaccinations
                WHERE owner_email = (
                    SELECT email FROM users WHERE user_id = %s
                )
                ORDER BY next_due_date
            """, (self.user_id,))
            
            for row in self.cur.fetchall():
                # Görüntüleme için tarihi biçimlendir
                row_list = list(row)
                row_list[3] = row[3].strftime('%Y-%m-%d')  # Tarih biçimi
                self.vaccination_tree.insert("", "end", values=row_list)
        except Error as e:
            messagebox.showerror("Hata", str(e))
    
    def add_vaccination_record(self):
        """Yeni bir aşı kaydı ekler ve tetikleyiciyi çalıştırır."""
        try:
            # Kullanıcıdan alınan bilgiler
            pet_id = self.vaccination_pet_dict.get(self.vaccination_pet_select.get())  # Değişken adı güncellendi
            vaccine_name = self.vaccine_name_var.get()
            validity_value = self.validity_value_var.get()
            validity_unit = self.validity_unit_var.get()
            date_given = self.date_given_var.get()

            if not all([pet_id, vaccine_name, validity_value, validity_unit, date_given]):
                messagebox.showwarning("Uyarı", "Lütfen tüm alanları doldurun")
                return

            # Geçerlilik Süresini PostgreSQL INTERVAL formatına çevir
            if validity_unit == "gün":
                interval = f"{validity_value} days"
            elif validity_unit == "ay":
                interval = f"{validity_value} months"
            elif validity_unit == "yıl":
                interval = f"{validity_value} years"
            else:
                messagebox.showwarning("Uyarı", "Geçerlilik birimi yanlış")
                return

            # Geçerlilik tarihini hesaplama
            self.cur.execute("SELECT %s::DATE + INTERVAL %s", (date_given, interval))
            next_due_date = self.cur.fetchone()[0]

            # Veritabanına kayıt ekle
            self.cur.execute("""
                INSERT INTO vaccinations (pet_id, vaccine_name, date_given, next_due_date)
                VALUES (%s, %s, %s, %s)
            """, (pet_id, vaccine_name, date_given, next_due_date))
            self.conn.commit()

            # Kullanıcıya bilgi mesajı göster
            messagebox.showinfo("Başarılı", "Aşı kaydı başarıyla eklendi!")

            # Aşı listesini yenile
            self.refresh_vaccinations()

        except Error as e:
            self.conn.rollback()
            messagebox.showerror("Hata", f"Aşı kaydı eklenemedi: {str(e)}")

    def create_booking_form(self, parent):
        booking_frame = ttk.LabelFrame(parent, text="Yeni Randevu Al")
        booking_frame.pack(pady=10, padx=10, fill="x")

        # Evcil Hayvan Seçimi
        ttk.Label(booking_frame, text="Hayvan:").grid(row=0, column=0, pady=5, padx=5)
        self.appointment_pet_select = ttk.Combobox(booking_frame)  
        self.appointment_pet_select.grid(row=0, column=1, pady=5, padx=5)
        self.update_appointment_pet_list()

        # Klinik Seçimi
        ttk.Label(booking_frame, text="Klinik:").grid(row=0, column=2, pady=5, padx=5)
        self.selected_clinic = ttk.Combobox(booking_frame)
        self.selected_clinic.grid(row=0, column=3, pady=5, padx=5)
        self.update_clinic_list()

        # Tarih ve Saat Seçimi
        ttk.Label(booking_frame, text="Tarih:").grid(row=1, column=0, pady=5, padx=5)
        self.appointment_date = ttk.Entry(booking_frame)
        self.appointment_date.grid(row=1, column=1, pady=5, padx=5)
        self.appointment_date.insert(0, "YYYY-MM-DD")

        ttk.Label(booking_frame, text="Zaman:").grid(row=1, column=2, pady=5, padx=5)
        self.appointment_time = ttk.Entry(booking_frame)
        self.appointment_time.grid(row=1, column=3, pady=5, padx=5)
        self.appointment_time.insert(0, "HH:MM")

        # Ziyaret Nedeni
        ttk.Label(booking_frame, text="Sebep:").grid(row=2, column=0, pady=5, padx=5)
        self.appointment_reason = ttk.Entry(booking_frame, width=50)
        self.appointment_reason.grid(row=2, column=1, columnspan=3, pady=5, padx=5)

        # Randevu Button
        ttk.Button(booking_frame, text="Randevu Al", command=self.book_appointment).grid(
            row=3, column=0, columnspan=4, pady=10)
    
    def update_vaccination_pet_list(self):
        """Aşı formu için evcil hayvan listesini günceller"""
        try:
            self.cur.execute("""
                SELECT pet_id, name 
                FROM pets 
                WHERE user_id = %s
                ORDER BY name
            """, (self.user_id,))
            pets = self.cur.fetchall()
            self.vaccination_pet_dict = {f"{pet[1]} (ID: {pet[0]})": pet[0] for pet in pets}
            current_value = self.vaccination_pet_select.get()
            self.vaccination_pet_select['values'] = list(self.vaccination_pet_dict.keys())
            if current_value in self.vaccination_pet_dict:
                self.vaccination_pet_select.set(current_value)
            elif self.vaccination_pet_dict:
                self.vaccination_pet_select.set(list(self.vaccination_pet_dict.keys())[0])
        except Error as e:
            messagebox.showerror("Hata", str(e))

    def update_appointment_pet_list(self):
        """Randevu formu için evcil hayvan listesini günceller"""
        try:
            self.cur.execute("""
                SELECT pet_id, name 
                FROM pets 
                WHERE user_id = %s
                ORDER BY name
            """, (self.user_id,))
            pets = self.cur.fetchall()
            self.appointment_pet_dict = {f"{pet[1]} (ID: {pet[0]})": pet[0] for pet in pets}
            current_value = self.appointment_pet_select.get()
            self.appointment_pet_select['values'] = list(self.appointment_pet_dict.keys())
            if current_value in self.appointment_pet_dict:
                self.appointment_pet_select.set(current_value)
            elif self.appointment_pet_dict:
                self.appointment_pet_select.set(list(self.appointment_pet_dict.keys())[0])
        except Error as e:
            messagebox.showerror("Hata", str(e))

    def on_tab_selected(self, event=None):
        """Sekme seçildiğinde çağrılır"""
        self.update_pet_list()
        self.refresh_appointments()

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
            current_value = self.selected_pet.get()
            self.selected_pet['values'] = list(self.pet_dict.keys())
            # Eğer hala mevcutsa önceki seçimi geri yükler
            if current_value in self.pet_dict:
                self.selected_pet.set(current_value)
        except Error as e:
            messagebox.showerror("Hata", str(e))

    def create_appointments_list(self, parent):
        # Appointments Listesi
        list_frame = ttk.LabelFrame(parent, text="Yaklaşan Randevular")
        list_frame.pack(pady=10, padx=10, fill="both", expand=True)

        # appointment_id'yi gizli bir sütun olarak ekler
        columns = ("ID", "Hayvan", "Klinik", "Tarih & Zaman", "Sebep", "Durum")
        self.appointment_tree = ttk.Treeview(list_frame, columns=columns, show="headings")
        
        # ID sütununu gizleme
        self.appointment_tree.heading("ID", text="ID")
        self.appointment_tree.column("ID", width=0, stretch=False)


        # Görünür sütunları yapılandırma
        for col in columns[1:]:  # Görünür sütunları ayarlarken ID sütununu atlayın
            self.appointment_tree.heading(col, text=col)
            if col == "Sebep":
                self.appointment_tree.column(col, width=200)
            else:
                self.appointment_tree.column(col, width=100)
        
        # Scrollbar ekleme
        scrollbar = ttk.Scrollbar(list_frame, orient="vertical", command=self.appointment_tree.yview)
        self.appointment_tree.configure(yscrollcommand=scrollbar.set)
        
        self.appointment_tree.pack(side="left", pady=10, padx=10, fill="both", expand=True)
        scrollbar.pack(side="right", fill="y")

        # initial veri yüklemesi
        self.refresh_appointments()

    def create_buttons(self, parent):
        # Buttons Frame
        btn_frame = ttk.Frame(parent)
        btn_frame.pack(pady=5)
        ttk.Button(btn_frame, text="Yenile", command=self.refresh_appointments).pack(side="left", padx=5)
        ttk.Button(btn_frame, text="Randevuyu İptal Et", command=self.cancel_appointment).pack(side="left", padx=5)
        ttk.Button(btn_frame, text="Durumu Günvelle", command=self.update_appointment_status).pack(side="left", padx=5)

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
            current_value = self.selected_pet.get()
            self.selected_pet['values'] = list(self.pet_dict.keys())
            # Eğer hala mevcutsa önceki seçimi geri yükler
            if current_value in self.pet_dict:
                self.selected_pet.set(current_value)
            elif self.pet_dict:  # Eğer liste boş değilse ilk değeri seç
                self.selected_pet.set(list(self.pet_dict.keys())[0])
        except Error as e:
            messagebox.showerror("Hata", str(e))

    def update_clinic_list(self):
        """Klinik seçimi açılır menüsünü günceller"""
        try:
            self.cur.execute("""
                SELECT clinic_id, name 
                FROM vet_clinics 
                ORDER BY name
            """)
            clinics = self.cur.fetchall()
            self.clinic_dict = {f"{clinic[1]} (ID: {clinic[0]})": clinic[0] for clinic in clinics}
            self.selected_clinic['values'] = list(self.clinic_dict.keys())
        except Error as e:
            messagebox.showerror("Hata", str(e))

    def book_appointment(self):
        """Yeni bir randevu al"""
        try:
            # Seçili evcil hayvan ve ID alır
            pet_selection = self.appointment_pet_select.get().strip()
            clinic_selection = self.selected_clinic.get().strip()
            appointment_date = self.appointment_date.get().strip()
            appointment_time = self.appointment_time.get().strip()
            
            pet_id = self.appointment_pet_dict.get(pet_selection)
            clinic_id = self.clinic_dict.get(clinic_selection)
            
            # Boş string kontrolü ekle
            if not pet_selection or not clinic_selection or \
            not appointment_date or not appointment_time or \
            appointment_date == "YYYY-MM-DD" or appointment_time == "HH:MM":
                messagebox.showwarning("Uyarı", "Lütfen tüm gerekli alanları doldurun")
                return

            if not all([pet_id, clinic_id]):
                messagebox.showwarning("Uyarı", "Lütfen geçerli bir hayvan ve klinik seçin")
                return

            # Tarih ve saati birleştirme
            appointment_datetime = f"{appointment_date} {appointment_time}"

            # Yeni randevu ekleme
            self.cur.execute("""
                INSERT INTO appointments (pet_id, clinic_id, appointment_date, reason, status)
                VALUES (%s, %s, %s, %s, 'Scheduled')
            """, (pet_id, clinic_id, appointment_datetime, self.appointment_reason.get().strip()))
            
            self.conn.commit()
            messagebox.showinfo("Başarılı", "Randevu başarıyla alındı!")
            self.refresh_appointments()
            
            # Formu temizleme
            self.appointment_date.delete(0, tk.END)
            self.appointment_date.insert(0, "YYYY-MM-DD")
            self.appointment_time.delete(0, tk.END)
            self.appointment_time.insert(0, "HH:MM")
            self.appointment_reason.delete(0, tk.END)
            self.selected_pet.set('')
            self.selected_clinic.set('')
            
        except Error as e:
            messagebox.showerror("Hata", str(e))

    def refresh_appointments(self):
        """Randevu listesini yenile"""
        for item in self.appointment_tree.get_children():
            self.appointment_tree.delete(item)
        
        try:
            self.cur.execute("""
                SELECT 
                    a.appointment_id,
                    p.name as pet_name,
                    vc.name as clinic_name,
                    a.appointment_date,
                    a.reason,
                    a.status
                FROM appointments a
                JOIN pets p ON a.pet_id = p.pet_id
                JOIN vet_clinics vc ON a.clinic_id = vc.clinic_id
                WHERE p.user_id = %s
                UNION
                SELECT 
                    a.appointment_id,
                    p.name as pet_name,
                    vc.name as clinic_name,
                    a.appointment_date,
                    'Genel Kontrol' AS reason,
                    'Planlanmış' AS status
                FROM appointments a
                JOIN pets p ON a.pet_id = p.pet_id
                JOIN vet_clinics vc ON a.clinic_id = vc.clinic_id
                WHERE a.reason IS NULL
                ORDER BY appointment_date
            """, (self.user_id,))
            
            for row in self.cur.fetchall():
                self.appointment_tree.insert("", "end", values=row)
        except Error as e:
            messagebox.showerror("Hata", str(e))

    def cancel_appointment(self):
        """Seçilen randevuyu iptal et"""
        selected_item = self.appointment_tree.selection()
        if not selected_item:
            messagebox.showwarning("Uyarı", "Lütfen iptal etmek için bir randevu seçin")
            return

        # Gizli ilk sütundan appointment_id'yi alın
        appointment_id = self.appointment_tree.item(selected_item)['values'][0]
        
        if messagebox.askyesno("Onay", "Bu randevuyu iptal etmek istediğinizden emin misiniz?"):
            try:
                self.cur.execute("""
                    UPDATE appointments 
                    SET status = 'Cancelled'
                    WHERE appointment_id = %s
                """, (appointment_id,))
                self.conn.commit()
                messagebox.showinfo("Başarılı", "Randevu başarıyla iptal edildi!")
                self.refresh_appointments()
            except Error as e:
                messagebox.showerror("Hata", str(e))

    def update_appointment_status(self):
        """Randevu durumunu güncelleme"""
        selected_item = self.appointment_tree.selection()
        if not selected_item:
            messagebox.showwarning("Uyarı", "Lütfen güncellemek için bir randevu seçin")
            return

        appointment_id = self.appointment_tree.item(selected_item)['values'][0]
        
        # Durum seçimi için küçük bir iletişim kutusu oluşturma
        status_dialog = tk.Toplevel(self)
        status_dialog.title("Güncelleme Durumu")
        status_dialog.geometry("300x150")
        
        ttk.Label(status_dialog, text="Yeni Durum Seçin:").pack(pady=10)
        status_var = tk.StringVar()
        status_combo = ttk.Combobox(status_dialog, 
                                textvariable=status_var,
                                values=["Planlanmış", "Tamamlanmış", "İptal edildi", "Gelmeyen"])
        status_combo.pack(pady=10)
    
        def save_status():
            try:
                self.cur.execute("""
                    UPDATE appointments 
                    SET status = %s
                    WHERE appointment_id = %s
                """, (status_var.get(), appointment_id))
                self.conn.commit()
                messagebox.showinfo("Başarılı", "Durum başarıyla güncellendi!")
                self.refresh_appointments()
                status_dialog.destroy()
            except Error as e:
                messagebox.showerror("Hata", str(e))
        
        ttk.Button(status_dialog, text="Kaydet", command=save_status).pack(pady=10)