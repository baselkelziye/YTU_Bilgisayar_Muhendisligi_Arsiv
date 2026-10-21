import tkinter as tk
from tkinter import ttk, messagebox
from psycopg2 import Error

class ShopTab(ttk.Frame):
    def __init__(self, parent, conn, cur, user_id):  
        super().__init__(parent)
        self.conn = conn
        self.cur = cur
        self.user_id = user_id 
        self.cart = {}
        self.setup_ui()

    def setup_ui(self):
        """Kullanıcı arayüzünü kurar"""
        # Create main layout 
        self.main_frame = ttk.Frame(self)
        self.main_frame.pack(fill="both", expand=True, pady=0)  

        # Notebook (alt sekmeler) oluştur
        self.notebook = ttk.Notebook(self.main_frame)  # main_frame'e bağlıyoruz
        self.notebook.pack(fill="both", expand=True, pady=0)  

        # Mevcut Ürünler sekmesini ekle
        self.products_frame = ttk.Frame(self.notebook)
        self.notebook.add(self.products_frame, text="Mevcut Ürünler", padding=0) 
        self.create_products_frame(self.products_frame)

        # Yeni Ürünler sekmesini ekle
        self.create_new_products_tab()

        # Diğer sekmeleri ekle
        self.create_product_details_tab()
        self.create_price_analysis_tab()
        
        # Load initial product values
        self.refresh_products()


    def create_main_layout(self):
        # Çerçeveyi ürünler ve sepet bölümlerine ayırın
        self.main_frame = ttk.Frame(self)
        self.main_frame.pack(fill="both", expand=True)

    def create_products_frame(self, parent):
        # Ürünler ve sepet için yan yana düzenleyici
        main_products_frame = ttk.Frame(parent)
        main_products_frame.pack(fill="both", expand=True, padx=10, pady=10)

        # Products bölümü (sol tarafta)
        products_frame = ttk.LabelFrame(main_products_frame, text="Mevcut Ürünler")
        products_frame.pack(side="left", fill="both", expand=True, padx=10, pady=10)
        
        # Ürün arama, listeleme, sepete ekleme
        self.create_search_frame(products_frame)
        self.create_products_tree(products_frame)
        self.create_add_to_cart_frame(products_frame)
        
        # Alışveriş sepeti bölümü
        cart_frame = ttk.LabelFrame(main_products_frame, text="Alışveriş Sepeti")
        cart_frame.pack(side="right", fill="both", padx=0, pady=0)
        
        # Sepet Listesi
        self.create_cart_tree(cart_frame)
        self.create_cart_total(cart_frame)
        self.create_cart_buttons(cart_frame)


    def create_new_products_tab(self):
        """Yeni Ürünler sekmesini oluştur"""
        new_products_frame = ttk.Frame(self.notebook)
        self.notebook.add(new_products_frame, text="Yeni Ürünler")

        # Kontrol paneli için frame
        control_frame = ttk.Frame(new_products_frame)
        control_frame.pack(fill="x", padx=5, pady=5)

        # Gün sayısı için input
        ttk.Label(control_frame, text="Son kaç günün ürünleri:").pack(side="left", padx=5)
        self.days_var = tk.StringVar(value="7")
        days_entry = ttk.Entry(control_frame, textvariable=self.days_var, width=5)
        days_entry.pack(side="left", padx=5)

        # Sütunlar tanımlanıyor
        columns = ("ID", "İsim", "Kategori", "Fiyat", "Stok", "Açıklama", "Eklenme Tarihi")
        new_products_tree = ttk.Treeview(new_products_frame, columns=columns, show="headings")

        # Sütun başlıklarını oluştur
        for col in columns:
            new_products_tree.heading(col, text=col)
            new_products_tree.column(col, width=150)

        new_products_tree.pack(fill="both", expand=True, padx=0, pady=0)

        def load_new_products():
            """Yeni ürünleri getir ve tabloyu doldur"""
            try:
                # Gün sayısını kontrol et
                try:
                    days = int(self.days_var.get())
                    if days <= 0:
                        raise ValueError("Gün sayısı pozitif olmalıdır")
                except ValueError as e:
                    messagebox.showwarning("Uyarı", str(e))
                    return

                # PostgreSQL fonksiyonunu çağır
                self.cur.execute("SELECT * FROM get_new_products(%s)", (days,))
                products = self.cur.fetchall()

                # Mevcut satırları temizle ve yeni ürünleri ekle
                for row in new_products_tree.get_children():
                    new_products_tree.delete(row)

                for product in products:
                    new_products_tree.insert("", "end", values=product)

            except Error as e:
                messagebox.showerror("Hata", f"Yeni ürünler getirilemedi: {str(e)}")

        # Yenile düğmesi ekle
        ttk.Button(control_frame, text="Yenile", command=load_new_products).pack(side="left", padx=20)

        # Sekme yüklendiğinde ürünleri yükle
        load_new_products()

    def create_product_details_tab(self):
        """Ürün Detay sekmesini oluştur."""
        product_details_frame = ttk.Frame(self.notebook)
        self.notebook.add(product_details_frame, text="Ürün Detay")

        # Sütunları tanımla
        columns = ("ID", "İsim", "Açıklama")
        product_details_tree = ttk.Treeview(product_details_frame, columns=columns, show="headings")

        # Sütun başlıkları ve genişlikleri
        for col in columns:
            product_details_tree.heading(col, text=col)
            product_details_tree.column(col, width=200 if col == "Açıklama" else 100)

        product_details_tree.pack(fill="both", expand=True, padx=0, pady=0)

        def load_product_descriptions():
            """Ürün açıklamalarını getir ve tabloyu doldur."""
            try:
                # PostgreSQL fonksiyonunu çağır
                self.cur.execute("SELECT * FROM get_product_descriptions_with_cursor()")
                descriptions = self.cur.fetchall()
                # Mevcut satırları temizle ve açıklamaları ekle
                for row in product_details_tree.get_children():
                    product_details_tree.delete(row)

                for desc in descriptions:
                    product_details_tree.insert("", "end", values=desc)

            except Error as e:
                messagebox.showerror("Hata", f"Ürün detayları getirilemedi: {str(e)}")

        # Yenile düğmesi ekle
        ttk.Button(product_details_frame, text="Yenile", command=load_product_descriptions).pack(pady=5)

        # Sekme yüklendiğinde açıklamaları yükle
        load_product_descriptions()

    def create_price_analysis_tab(self):
        """Fiyat Analizi sekmesini oluştur"""
        price_analysis_frame = ttk.Frame(self.notebook)
        self.notebook.add(price_analysis_frame, text="Fiyat Analizi")

        # Giriş alanları çerçevesi
        input_frame = ttk.LabelFrame(price_analysis_frame, text="Fiyat Aralığı")
        input_frame.pack(padx=10, pady=5, fill="x")

        # Minimum fiyat girişi
        ttk.Label(input_frame, text="Minimum Fiyat (TL):").grid(row=0, column=0, padx=5, pady=5)
        self.min_price_entry = ttk.Entry(input_frame, width=10)
        self.min_price_entry.grid(row=0, column=1, padx=5, pady=5)

        # Maximum fiyat girişi
        ttk.Label(input_frame, text="Maximum Fiyat (TL):").grid(row=0, column=2, padx=5, pady=5)
        self.max_price_entry = ttk.Entry(input_frame, width=10)
        self.max_price_entry.grid(row=0, column=3, padx=5, pady=5)

        # Analiz butonu
        ttk.Button(input_frame, text="Analiz Et", command=self.analyze_price_range).grid(row=0, column=4, padx=20, pady=5)

        # Sonuç tablosu - "Ürün Sayısı" sütunu kaldırıldı
        columns = ("Kategori", "Ortalama Fiyat", "Toplam Stok", "Örnek Ürünler")
        self.analysis_tree = ttk.Treeview(price_analysis_frame, columns=columns, show="headings", height=10)
        
        # Sütun başlıkları
        for col in columns:
            self.analysis_tree.heading(col, text=col)
            if col == "Örnek Ürünler":
                self.analysis_tree.column(col, width=250)
            else:
                self.analysis_tree.column(col, width=120)
        
        # Scrollbar ekle
        scrollbar = ttk.Scrollbar(price_analysis_frame, orient="vertical", command=self.analysis_tree.yview)
        self.analysis_tree.configure(yscrollcommand=scrollbar.set)
        
        self.analysis_tree.pack(pady=10, padx=10, fill="both", expand=True)
        scrollbar.pack(side="right", fill="y")


    def analyze_price_range(self):
        """Girilen fiyat aralığına göre analiz yap"""
        try:
            # Giriş değerlerini kontrol et
            min_price = self.min_price_entry.get().strip()
            max_price = self.max_price_entry.get().strip()
            
            if not min_price or not max_price:
                messagebox.showwarning("Uyarı", "Lütfen minimum ve maximum fiyat değerlerini girin.")
                return
                
            try:
                min_price = float(min_price)
                max_price = float(max_price)
            except ValueError:
                messagebox.showwarning("Uyarı", "Lütfen geçerli sayısal değerler girin.")
                return
                
            if min_price < 0 or max_price < 0:
                messagebox.showwarning("Uyarı", "Fiyatlar negatif olamaz.")
                return
                
            if min_price > max_price:
                messagebox.showwarning("Uyarı", "Minimum fiyat, maximum fiyattan büyük olamaz.")
                return
            
            # Treeview'ı temizle
            for item in self.analysis_tree.get_children():
                self.analysis_tree.delete(item)
            
            # SQL fonksiyonunu çağır
            self.cur.execute("SELECT * FROM analyze_price_range(%s, %s)", (min_price, max_price))
            results = self.cur.fetchall()
            
            # Sonuçları tabloya ekle - "Ürün Sayısı" sütunu atlanıyor
            for result in results:
                self.analysis_tree.insert("", "end", values=(
                    result[0],  # Kategori
                    f"{float(result[2]):.2f} TL",  # Ortalama Fiyat
                    result[3],  # Toplam Stok
                    result[4]   # Örnek Ürünler
                ))
                
            if not results:
                messagebox.showinfo("Bilgi", "Bu fiyat aralığında ürün bulunamadı.")
                
        except Error as e:
            messagebox.showerror("Hata", f"Analiz yapılırken bir hata oluştu: {str(e)}")

    def create_search_frame(self, parent):
        search_frame = ttk.Frame(parent)
        search_frame.pack(fill="x", padx=5, pady=5)
        
        ttk.Label(search_frame, text="Ara:").pack(side="left", padx=5)
        self.search_var = tk.StringVar()
        self.search_var.trace('w', self.filter_products)
        search_entry = ttk.Entry(search_frame, textvariable=self.search_var)
        search_entry.pack(side="left", fill="x", expand=True, padx=5)
        
        # Kategori filtresi
        ttk.Label(search_frame, text="Kategori:").pack(side="left", padx=5)
        self.category_filter = ttk.Combobox(search_frame, width=15)
        self.category_filter.pack(side="left", padx=5)
        self.update_category_list()
        self.category_filter.bind('<<ComboboxSelected>>', lambda e: self.filter_products())

    def create_products_tree(self, parent):
        # product_id'yi gizli bir sütun olarak eklendi
        columns = ("ID", "İsim", "Kategori", "Fiyat", "Stok")
        self.products_tree = ttk.Treeview(parent, columns=columns, show="headings")
        
        # ID sütununu gizli yapıldı
        self.products_tree.heading("ID", text="ID")
        self.products_tree.column("ID", width=0, stretch=False)
        
        # Diğer sütunları göster
        for col in columns[1:]:  # ID hariç diğer sütunlar
            self.products_tree.heading(col, text=col)
            if col == "Name":
                self.products_tree.column(col, width=200)
            else:
                self.products_tree.column(col, width=100)
        
        scrollbar = ttk.Scrollbar(parent, orient="vertical", command=self.products_tree.yview)
        self.products_tree.configure(yscrollcommand=scrollbar.set)
        
        self.products_tree.pack(side="left", fill="both", expand=True, padx=5, pady=5)
        scrollbar.pack(side="right", fill="y")

    def create_add_to_cart_frame(self, parent):
        add_frame = ttk.Frame(parent)
        add_frame.pack(fill="x", padx=5, pady=5)
        
        ttk.Label(add_frame, text="Miktar:").pack(side="left", padx=5)
        self.quantity_var = tk.StringVar(value="1")
        quantity_entry = ttk.Entry(add_frame, textvariable=self.quantity_var, width=5)
        quantity_entry.pack(side="left", padx=5)
        
        ttk.Button(add_frame, text="Sepete ekle", command=self.add_to_cart).pack(side="left", padx=5)


    def create_cart_tree(self, parent):
        columns = ("İsim", "Fiyat", "Adet", "Toplam")
        self.cart_tree = ttk.Treeview(parent, columns=columns, show="headings", height=10)
        for col in columns:
            self.cart_tree.heading(col, text=col)
            self.cart_tree.column(col, width=100)
        
        cart_scrollbar = ttk.Scrollbar(parent, orient="vertical", command=self.cart_tree.yview)
        self.cart_tree.configure(yscrollcommand=cart_scrollbar.set)
        
        self.cart_tree.pack(side="left", fill="both", expand=True, padx=5, pady=5)
        cart_scrollbar.pack(side="right", fill="y")

    def create_cart_total(self, parent):
        total_frame = ttk.Frame(parent)
        total_frame.pack(fill="x", padx=5, pady=5)
        
        ttk.Label(total_frame, text="Toplam:").pack(side="left", padx=5)
        self.cart_total_var = tk.StringVar(value="0.00TL")
        ttk.Label(total_frame, textvariable=self.cart_total_var).pack(side="left", padx=5)

    def create_cart_buttons(self, parent):
        btn_frame = ttk.Frame(parent)
        btn_frame.pack(fill="x", padx=5, pady=5)
        
        # Butonları alt alta yerleştir
        ttk.Button(btn_frame, text="Seçilenleri Kaldır", command=self.remove_from_cart).pack(side="top", fill="x", padx=5, pady=2)
        ttk.Button(btn_frame, text="Sepeti Temizle", command=self.clear_cart).pack(side="top", fill="x", padx=5, pady=2)
        ttk.Button(btn_frame, text="Ödeme", command=self.checkout).pack(side="top", fill="x", padx=5, pady=2)
    def update_category_list(self):
        """Kategori filtresi açılır menüsü"""
        try:
            self.cur.execute("SELECT DISTINCT category FROM products ORDER BY category")
            categories = [row[0] for row in self.cur.fetchall()]
            self.category_filter['values'] = ['Hepsi'] + categories
            self.category_filter.set('Hepsi')
        except Error as e:
            messagebox.showerror("Hata", str(e))

    def filter_products(self, *args):
        """Ürünleri arama metnine ve kategoriye göre filtreleme"""
        search_text = self.search_var.get().lower()
        category = self.category_filter.get()
        
        for item in self.products_tree.get_children():
            self.products_tree.delete(item)
        
        try:
            if category == 'Hepsi':
                self.cur.execute("""
                    SELECT product_id, name, category, price, stock_quantity 
                    FROM products 
                    WHERE LOWER(name) LIKE %s OR LOWER(category) LIKE %s
                    ORDER BY name
                """, (f'%{search_text}%', f'%{search_text}%'))
            else:
                self.cur.execute("""
                    SELECT product_id, name, category, price, stock_quantity 
                    FROM products 
                    WHERE (LOWER(name) LIKE %s OR LOWER(category) LIKE %s)
                    AND category = %s
                    ORDER BY name
                """, (f'%{search_text}%', f'%{search_text}%', category))
            
            for row in self.cur.fetchall():
                self.products_tree.insert("", "end", values=row)
        except Error as e:
            messagebox.showerror("Hata", str(e))

    def refresh_products(self):
        """Ürün listesini yenile"""
        self.filter_products()

    def add_to_cart(self):
        """Seçili ürünü sepete ekle"""
        selected_item = self.products_tree.selection()
        if not selected_item:
            messagebox.showwarning("Uyarı", "Lütfen bir ürün seçin")
            return
        
        try:
            quantity = int(self.quantity_var.get())
            if quantity <= 0:
                raise ValueError("Miktar pozitif olmalıdır")
        except ValueError as e:
            messagebox.showwarning("Uyarı", str(e))
            return
        
        product_data = self.products_tree.item(selected_item)['values']
        product_id = product_data[0]  # İlk sütun artık product_id
        
        # Check stock
        if quantity > product_data[4]:  # stock_quantity artık 5. sütunda
            messagebox.showwarning("Uyarı", "Yeterli stok yok")
            return
        
        # Add to cart
        if product_id in self.cart:
            self.cart[product_id]['Adet'] += quantity
        else:
            self.cart[product_id] = {
                'İsim': product_data[1],  # name artık 2. sütunda
                'Fiyat': float(product_data[3]),  # price artık 4. sütunda
                'Adet': quantity
            }
        
        self.update_cart_display()

    def remove_from_cart(self):
        """Seçili ürünü sepetten kaldır"""
        selected_item = self.cart_tree.selection()
        if not selected_item:
            messagebox.showwarning("Uyarı", "Lütfen kaldırmak için bir öğe seçin")
            return
        
        item_name = self.cart_tree.item(selected_item)['values'][0]
        product_id = next(pid for pid, data in self.cart.items() if data['İsim'] == item_name)
        del self.cart[product_id]
        self.update_cart_display()

    def clear_cart(self):
        """Sepetteki tüm ürünleri temizle"""
        if messagebox.askyesno("Onay", "Sepeti temizlemek istediğinizden emin misiniz?"):
            self.cart.clear()
            self.update_cart_display()

    def update_cart_display(self):
        """Sepeti günceller"""
        for item in self.cart_tree.get_children():
            self.cart_tree.delete(item)
        
        total = 0.0  # Float olarak başlat
        for product_id, data in self.cart.items():
            # Fiyat ve miktarın sayısal oldugu kontrolü
            price = float(data['Fiyat'])
            quantity = int(data['Adet'])
            item_total = price * quantity
            total += item_total
            
            self.cart_tree.insert("", "end", values=(
                data['İsim'],
                f"{price:.2f}TL",
                quantity,
                f"{item_total:.2f}TL"
            ))
        
        self.cart_total_var.set(f"{total:.2f}TL")

    def checkout(self):
        """İşlem ödemesi"""
        if not self.cart:
            messagebox.showwarning("Uyarı", "Sepet boş")
            return
        
        if messagebox.askyesno("Onay", "Ödeme işlemine devam edecek misiniz?"):
            try:
                # Mevcut kullanıcının ID'siyke sipariş oluştur
                total_amount = sum(data['Fiyat'] * data['Adet'] for data in self.cart.values())
                self.cur.execute("""
                    INSERT INTO orders (user_id, total_amount, status)
                    VALUES (%s, %s, 'Processing')
                    RETURNING order_id
                """, (self.user_id, total_amount))  
                
                order_id = self.cur.fetchone()[0]
                
                # Sipariş ayrıntılarını oluşturun ve stoğu günceller
                for product_id, data in self.cart.items():
                    self.cur.execute("""
                        INSERT INTO order_details (order_id, product_id, quantity, unit_price)
                        VALUES (%s, %s, %s, %s)
                    """, (order_id, product_id, data['Adet'], data['Fiyat']))
                    """
                    -- Trigger 1: Siparişten sonra ürün stokunu güncelle
                    CREATE OR REPLACE FUNCTION update_product_stock()
                    RETURNS TRIGGER AS $$
                    BEGIN
                        UPDATE products
                        SET stock_quantity = stock_quantity - NEW.quantity
                        WHERE product_id = NEW.product_id;
                        
                        -- Check if stock is low
                        IF (SELECT stock_quantity FROM products WHERE product_id = NEW.product_id) < 10 THEN
                            RAISE NOTICE 'Low stock alert for product %', NEW.product_id;
                        END IF;
                        
                        RETURN NEW;
                    END;
                    $$ LANGUAGE plpgsql;

                    CREATE TRIGGER after_order_detail_insert
                    AFTER INSERT ON order_details
                    FOR EACH ROW
                    EXECUTE FUNCTION update_product_stock();
                    """
                self.conn.commit()
                messagebox.showinfo("Başarılı", "Sipariş başarıyla verildi!")
                self.cart.clear()
                self.update_cart_display()
                self.refresh_products()
                
            except Error as e:
                self.conn.rollback()
                messagebox.showerror("Hata", f"Sipariş işleme alınamadı: {str(e)}")