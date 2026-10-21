# app.py

from flask import Flask, render_template, request, redirect, url_for, session, flash
import db
import config
import bcrypt
import os
from werkzeug.utils import secure_filename
import uuid
import psycopg2
import threading
from time import sleep
product_rating_update_flag = False
product_total_sales_update_flag = False
app = Flask(__name__)
app.secret_key = config.SECRET_KEY  # session yönetimi için gerekli

# Dosya yükleme ayarları
UPLOAD_FOLDER = 'static/uploads/'
ALLOWED_EXTENSIONS = {'png', 'jpg', 'jpeg', 'gif'}
app.config['UPLOAD_FOLDER'] = UPLOAD_FOLDER

def allowed_file(filename):
    return '.' in filename and filename.rsplit('.', 1)[1].lower() in ALLOWED_EXTENSIONS

# Dizin oluşturma fonksiyonu
def create_upload_folder():
    if not os.path.exists(app.config['UPLOAD_FOLDER']):
        os.makedirs(app.config['UPLOAD_FOLDER'])


def listen_notifications():
    conn = psycopg2.connect(
        host=config.DB_HOST,
        database=config.DB_NAME,
        user=config.DB_USER,
        password=config.DB_PASS,
        port=config.DB_PORT
    )
    conn.set_isolation_level(psycopg2.extensions.ISOLATION_LEVEL_AUTOCOMMIT)
    cur = conn.cursor()
    cur.execute("LISTEN product_rating_update;")
    cur.execute("LISTEN product_total_sales_update;")
    global product_rating_update_flag
    global product_total_sales_update_flag
    print("Waiting for notifications on channels 'product_rating_update' and 'product_total_sales_update'")
    while True:
        conn.poll()
        while conn.notifies:
            notify = conn.notifies.pop(0)
            print("------------------------")
            print(f"Got NOTIFY: {notify.channel} - {notify.payload}")
            print("------------------------")
            
            
            if notify.channel == "product_rating_update":
                product_rating_update_flag = True
                print(product_rating_update_flag)
            elif notify.channel == "product_total_sales_update":
                product_total_sales_update_flag = True
                print(product_total_sales_update_flag)

            
            
# Bildirim dinleme thread'i başlat
notification_thread = threading.Thread(target=listen_notifications, daemon=True)
notification_thread.start()

##############################################################################
# YARDIMCI FONKSİYONLAR
##############################################################################
def is_logged_in():
    """
    Kullanıcı giriş yapmış mı diye kontrol eder.
    session['user_id'] varlığına bakar.
    """
    return 'user_id' in session

def get_current_user_id():
    """
    Oturumdaki kullanıcı ID’sini döndürür (yoksa None).
    """
    return session.get('user_id')

##############################################################################
# ANASAYFA
##############################################################################
@app.route('/')
def index():
    """
    Anasayfa: Ürünlerin bir kısmı listelenebilir, 
    ya da sadece 'Hoş Geldiniz' gibi bir mesaj verilebilir.
    """
    # View'dan ceker.
    q = "SELECT * FROM latest_products;"
    products = db.fetch_query(q)
    print(products)
    return render_template('index.html', products=products)

##############################################################################
# KAYIT / GİRİŞ / ÇIKIŞ (AUTH)
##############################################################################

@app.route('/register', methods=['GET', 'POST'])
def register():
    if request.method == 'POST':
        name = request.form.get('name')
        username = request.form.get('username')
        password = request.form.get('password')
        if not (name and username and password):
            flash("Lütfen ad, kullanıcı adı ve şifre giriniz.", "danger")
            return redirect(url_for('register'))
        
        # Kullanıcı adı zaten var mı kontrol et
        q = "SELECT user_id FROM Users WHERE username = %s;"
        existing_user = db.fetch_query(q, (username,))
        if existing_user:
            flash("Bu kullanıcı adı zaten alınmış. Lütfen başka bir kullanıcı adı seçiniz.", "danger")
            return redirect(url_for('register'))
        
        # Şifreyi hash'le
        hashed_pw = bcrypt.hashpw(password.encode('utf-8'), bcrypt.gensalt())
        
        # Kullanıcıyı veritabanına kaydet
        q = "INSERT INTO Users (name, username, password) VALUES (%s, %s, %s);"
        print(f"INSERT: {name}, {username}, {hashed_pw.decode('utf-8')}")
        db.execute_query(q, (name, username, hashed_pw.decode('utf-8')))
        
        flash("Kayıt başarıyla oluşturuldu. Giriş yapabilirsiniz.", "success")
        return redirect(url_for('login'))

    # GET isteğinde formu göster
    return render_template('register.html')


@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        username = request.form.get('username')
        password = request.form.get('password')
        if not (username and password):
            flash("Lütfen kullanıcı adı ve şifre giriniz.", "danger")
            return redirect(url_for('login'))
        
        # Kullanıcı var mı kontrol et
        q = "SELECT user_id, password FROM Users WHERE username = %s;"
        user_data = db.fetch_query(q, (username,))
        if not user_data:
            flash("Kullanıcı bulunamadı.", "danger")
            return redirect(url_for('login'))
        
        db_user = user_data[0]
        db_hashed_pw = db_user['password'].encode('utf-8')

        # Şifre doğru mu?
        if bcrypt.checkpw(password.encode('utf-8'), db_hashed_pw):
            session['user_id'] = db_user['user_id']
            flash("Giriş başarılı!", "success")
            return redirect(url_for('index'))
        else:
            flash("Şifre yanlış.", "danger")
            return redirect(url_for('login'))
    
    # GET isteği
    return render_template('login.html')

@app.route('/logout')
def logout():
    session.pop('user_id', None)
    flash("Çıkış yapıldı.", "info")
    return redirect(url_for('index'))

# (update / delete isterseniz benzer route’lar ekleyebilirsiniz)

##############################################################################
# ÜRÜNLER
##############################################################################

@app.route('/products')
def list_products():
    category_id = request.args.get('category_id')
    min_price = request.args.get('min_price')
    max_price = request.args.get('max_price')
    search_query = request.args.get('search_query')
    sort_by = request.args.get('sort_by')  # Sıralama parametresi

    # Subquery ile review_count:
    base_query = """
      SELECT p.*,
             c.name AS category_name,
             u.name AS seller_name,
             COALESCE((SELECT COUNT(*) FROM Reviews r WHERE r.product_id = p.product_id), 0) AS review_count
      FROM Products p
      JOIN Categories c ON p.category_id = c.category_id
      JOIN Users u ON p.seller_id = u.user_id
      WHERE p.deleted = FALSE
    """
    params = []

    if category_id:
        base_query += " AND p.category_id = %s"
        params.append(category_id)

    if min_price:
        base_query += " AND p.price >= %s"
        params.append(min_price)

    if max_price:
        base_query += " AND p.price <= %s"
        params.append(max_price)

    if search_query:
        base_query += " AND p.name ILIKE %s"
        params.append(f"%{search_query}%")

    # Sıralama
    if sort_by == 'price_asc':
        base_query += " ORDER BY p.price ASC"
    elif sort_by == 'price_desc':
        base_query += " ORDER BY p.price DESC"
    elif sort_by == 'rating_asc':
        base_query += " ORDER BY p.rating ASC"
    elif sort_by == 'rating_desc':
        base_query += " ORDER BY p.rating DESC"
    elif sort_by == 'sales_desc':
        base_query += " ORDER BY p.total_sales DESC"
    elif sort_by == 'reviews_desc':
        base_query += " ORDER BY review_count DESC"
    else:
        base_query += " ORDER BY p.product_id DESC"

    products = db.fetch_query(base_query, tuple(params))

    # Kategorileri çek
    cat_q = "SELECT * FROM Categories ORDER BY category_id;"
    categories = db.fetch_query(cat_q)  

    return render_template('products.html', 
                           products=products, 
                           categories=categories,
                           sort_by=sort_by)



@app.route('/products/<int:product_id>')
def product_detail(product_id):
    """
    Ürün detay sayfası; incelemeleri de gösterelim.
    """
    q = """
        SELECT p.*, c.name as category_name, u.name as seller_name 
        FROM Products p
        JOIN Categories c ON p.category_id = c.category_id
        JOIN Users u ON p.seller_id = u.user_id
        WHERE p.product_id = %s;
    """
    product_data = db.fetch_query(q, (product_id,))
    if not product_data:
        flash("Ürün bulunamadı.", "danger")
        return redirect(url_for('list_products'))
    
    product = product_data[0]

    # İncelemeleri (Reviews) çek
    review_q = """
        SELECT r.*, us.name as user_name
        FROM Reviews r
        JOIN Users us ON r.user_id = us.user_id
        WHERE r.product_id = %s
        ORDER BY r.review_id DESC;
    """
    reviews = db.fetch_query(review_q, (product_id,))

    has_reviewed = False
    if 'user_id' in session:
        user_id = session['user_id']
        check_review_q = "SELECT 1 FROM Reviews WHERE product_id = %s AND user_id = %s;"
        existing_review = db.fetch_query(check_review_q, (product_id, user_id))
        has_reviewed = len(existing_review) > 0
        print(len(existing_review))

    return render_template('product_detail.html',
                           product=product,
                           reviews=reviews,
                           has_reviewed=has_reviewed)

@app.route('/products/create', methods=['GET', 'POST'])
def create_product():
    """
    Sadece giriş yapmış kullanıcı (satıcı) ürün ekleyebilir.
    """
    if not is_logged_in():
        flash("Ürün eklemek için giriş yapmanız gerekiyor.", "warning")
        return redirect(url_for('login'))
    
    if request.method == 'POST':
        name = request.form.get('name')
        price = request.form.get('price')
        category_id = request.form.get('category_id')
        rating = request.form.get('rating', 0)  # default 0
        image = request.files.get('image')
        
        if not (name and price and category_id):
            flash("Zorunlu alanları doldurunuz.", "danger")
            return redirect(url_for('create_product'))
        
        if image and allowed_file(image.filename):
            create_upload_folder()  # Dizin oluşturma kontrolü
            filename = secure_filename(image.filename)
            unique_filename = f"{uuid.uuid4().hex}_{filename}"
            image.save(os.path.join(app.config['UPLOAD_FOLDER'], unique_filename))
            image_url = unique_filename  # Sadece dosya adını sakla
        else:
            image_url = None
        
        try:
            price = float(price)
            rating = float(rating)
        except:
            flash("Geçersiz fiyat veya rating.", "danger")
            return redirect(url_for('create_product'))
        
        seller_id = get_current_user_id()
        q = """
          INSERT INTO Products (seller_id, name, price, category_id, rating, image_url)
          VALUES (%s, %s, %s, %s, %s, %s);
        """
        db.execute_query(q, (seller_id, name, price, category_id, rating, image_url))
        flash("Ürün başarıyla eklendi.", "success")
        return redirect(url_for('list_products'))
    
    # GET: formu gösterelim
    cat_q = "SELECT * FROM Categories ORDER BY category_id;"
    categories = db.fetch_query(cat_q)
    return render_template('create_product.html', categories=categories)

@app.route('/products/<int:product_id>/edit', methods=['GET', 'POST'])
def edit_product(product_id):
    """
    Ürünü sadece sahibi düzenleyebilsin.
    """
    if not is_logged_in():
        flash("Ürün düzenlemek için giriş yapmanız gerekiyor.", "warning")
        return redirect(url_for('login'))
    
    # Önce ürün var mı + sahibi kim?
    check_q = "SELECT seller_id, image_url FROM Products WHERE product_id = %s;"
    check_res = db.fetch_query(check_q, (product_id,))
    if not check_res:
        flash("Ürün bulunamadı.", "danger")
        return redirect(url_for('list_products'))
    
    owner_id = check_res[0]['seller_id']
    if owner_id != get_current_user_id():
        flash("Bu ürünü düzenleme yetkiniz yok.", "danger")
        return redirect(url_for('list_products'))
    
    if request.method == 'POST':
        name = request.form.get('name')
        price = request.form.get('price')
        category_id = request.form.get('category_id')
        image = request.files.get('image')
        
        if not (name and price and category_id):
            flash("Eksik bilgi.", "danger")
            return redirect(url_for('edit_product', product_id=product_id))
        
        try:
            price = float(price)
        except:
            flash("Geçersiz fiyat.", "danger")
            return redirect(url_for('edit_product', product_id=product_id))
        
        if image and allowed_file(image.filename):
            try:
                create_upload_folder()  # Dizin oluşturma kontrolü
                filename = secure_filename(image.filename)
                unique_filename = f"{uuid.uuid4().hex}_{filename}"
                image_path = os.path.join(app.config['UPLOAD_FOLDER'], unique_filename)
                image.save(image_path)
                print(f"Image saved: {unique_filename} at {app.config['UPLOAD_FOLDER']}")
                image_url = unique_filename  # Sadece dosya adını sakla
            except Exception as e:
                print(f"Error saving image: {e}")
                flash("Dosya kaydedilirken bir hata oluştu.", "danger")
                return redirect(url_for('edit_product', product_id=product_id))
        else:
            image_url = check_res[0]['image_url']
            print(f"Image not updated: {image_url}")
        
        q = """
          UPDATE Products
          SET name = %s, price = %s, category_id = %s, image_url = %s
          WHERE product_id = %s;
        """
        db.execute_query(q, (name, price, category_id, image_url, product_id))
        flash("Ürün güncellendi.", "success")
        return redirect(url_for('product_detail', product_id=product_id))
    
    # GET -> Form
    p_q = "SELECT * FROM Products WHERE product_id = %s;"
    product = db.fetch_query(p_q, (product_id,))[0]
    cat_q = "SELECT * FROM Categories ORDER BY category_id;"
    categories = db.fetch_query(cat_q)
    return render_template('edit_product.html', product=product, categories=categories)

@app.route('/products/<int:product_id>/delete')
def delete_product(product_id):
    if not is_logged_in():
        flash("Ürün silmek için giriş yapmanız gerekiyor.", "warning")
        return redirect(url_for('login'))
    
    # Ürünün sahibi kim?
    check_q = "SELECT seller_id FROM Products WHERE product_id = %s;"
    check_res = db.fetch_query(check_q, (product_id,))
    if not check_res:
        flash("Ürün bulunamadı.", "danger")
        return redirect(url_for('list_products'))
    
    owner_id = check_res[0]['seller_id']
    if owner_id != get_current_user_id():
        flash("Bu ürünü silme yetkiniz yok.", "danger")
        return redirect(url_for('list_products'))
    
    # Soft delete işlemi
    q = "UPDATE Products SET deleted = TRUE WHERE product_id = %s;"
    db.execute_query(q, (product_id,))
    flash("Ürün silindi.", "info")
    return redirect(url_for('list_products'))


##############################################################################
# SEPET (CART) & SİPARİŞ (ORDER)
##############################################################################
@app.route('/cart')
def view_cart():
    """
    Kullanıcının session’da tuttuğumuz sepetini gösterir.
    (Basit yaklaşım: Sepet item’larını session’da tutmak.)
    Ürün ID ve adet saklıyor olabiliriz. 
    Production projede Order_Items tablosuna "taslak" sipariş de yazılabilir vs.
    """
    cart_items = session.get('cart', [])
    # cart_items = [ {product_id, quantity}, ... ]
    
    # Ürün bilgilerini DB’den çekelim
    display_items = []
    total_price = 0.0
    for item in cart_items:
        p_q = "SELECT product_id, name, price FROM Products WHERE product_id = %s;"
        p_data = db.fetch_query(p_q, (item['product_id'],))
        if p_data:
            product_info = p_data[0]
            quantity = item['quantity']
            line_price = float(product_info['price']) * quantity
            total_price += line_price
            display_items.append({
                'product_id': product_info['product_id'],
                'name': product_info['name'],
                'price': product_info['price'],
                'quantity': quantity,
                'line_price': line_price
            })
    
    return render_template('cart.html', cart_items=display_items, total_price=total_price)

@app.route('/cart/add/<int:product_id>', methods=['POST'])
def add_to_cart(product_id):
    """
    Sepete ekleme: session içinde tutulan 'cart' listesine ekliyoruz.
    Gerçek projelerde bu mantığı veritabanına da yansıtmak gerekebilir.
    """
    if not is_logged_in():
        flash("Sepete eklemek için giriş yapmanız gerekiyor.", "warning")
        return redirect(url_for('login'))
    
    quantity = int(request.form.get('quantity', 1))
    cart_items = session.get('cart', [])
    # Aynı ürün varsa quantity artır
    found = False
    for item in cart_items:
        if item['product_id'] == product_id:
            item['quantity'] += quantity
            found = True
            break
    
    if not found:
        cart_items.append({'product_id': product_id, 'quantity': quantity})
    
    session['cart'] = cart_items
    flash("Ürün sepete eklendi.", "success")
    return redirect(url_for('view_cart'))

@app.route('/cart/remove/<int:product_id>')
def remove_from_cart(product_id):
    cart_items = session.get('cart', [])
    cart_items = [i for i in cart_items if i['product_id'] != product_id]
    session['cart'] = cart_items
    flash("Ürün sepetten çıkarıldı.", "info")
    return redirect(url_for('view_cart'))

@app.route('/cart/checkout')
def checkout():
    """
    Sepeti siparişe dönüştürme.
    Orders + Order_Items tablolarına yazacağız.
    total_price’ı hesaplayıp Orders tablosuna ekle.
    Order_Items tablosuna satırları ekle.
    """
    if not is_logged_in():
        flash("Sipariş oluşturmak için giriş yapmanız gerek.", "warning")
        return redirect(url_for('login'))
    
    cart_items = session.get('cart', [])
    if not cart_items:
        flash("Sepetiniz boş.", "danger")
        return redirect(url_for('view_cart'))
    
    # 1) total_price hesapla
    total_price = 0.0
    for item in cart_items:
        p_q = "SELECT price FROM Products WHERE product_id = %s;"
        p_data = db.fetch_query(p_q, (item['product_id'],))
        if p_data:
            price = float(p_data[0]['price'])
            total_price += price * item['quantity']
    
    buyer_id = get_current_user_id()
    # 2) Orders tablosuna ekle
    order_q = "INSERT INTO Orders (buyer_id, total_price) VALUES (%s, %s) RETURNING order_id;"
    
    # "manual" approach (RETURNING)
    import psycopg2
    conn = db.get_connection()
    try:
        with conn.cursor() as cur:
            cur.execute(order_q, (buyer_id, total_price))
            new_order_id = cur.fetchone()[0]
        conn.commit()
    except psycopg2.Error as e:
        conn.rollback()
        flash(f"Veritabanı hatası: {e}", "danger")
        return redirect(url_for('view_cart'))
    finally:
        conn.close()
    
    # 3) Order_Items’a ekle ve total_sales güncelle
    for item in cart_items:
        product_id = item['product_id']
        quantity = item['quantity']
        # Ürünün o anki fiyatını tekrar DB’den alalım
        p_data = db.fetch_query("SELECT price FROM Products WHERE product_id = %s;", (product_id,))
        if not p_data:
            continue
        price = p_data[0]['price']
        
        oi_q = """
          INSERT INTO Order_Items (order_id, product_id, quantity, price)
          VALUES (%s, %s, %s, %s);
        """
        db.execute_query(oi_q, (new_order_id, product_id, quantity, price))

    # 4) Sepeti temizle
    session['cart'] = []
    global product_total_sales_update_flag
    sleep(0.4)  # Trigger'ın çalışması için biraz bekle
    if product_total_sales_update_flag:
        flash(f"Sipariş oluşturuldu! Sipariş ID: {new_order_id} (TRIGGER AKTIF)", "success")
        product_total_sales_update_flag = False
    else:
        flash(f"Sipariş oluşturuldu! Sipariş ID: {new_order_id} (TRIGGER PASIF)", "warning")
    return redirect(url_for('my_orders'))



@app.route('/my_orders')
def my_orders():
    """
    Giriş yapmış kullanıcının tüm siparişlerini listeler.
    """
    if not is_logged_in():
        flash("Siparişlerinizi görmek için giriş yapmanız gerekiyor.", "warning")
        return redirect(url_for('login'))
    
    user_id = get_current_user_id()
    q = """
        SELECT 
            o.order_id,
            o.total_price,
            o.created_at,
            (
                SELECT json_agg(
                    json_build_object(
                        'name', p.name,
                        'quantity', oi2.quantity,
                        'price', oi2.price,
                        'image_url', p.image_url
                    )
                )
                FROM Order_Items oi2
                JOIN Products p ON p.product_id = oi2.product_id
                WHERE oi2.order_id = o.order_id
            ) as product_list
        FROM Orders o
        WHERE o.buyer_id = %s
        ORDER BY o.order_id DESC;
    """
    orders = db.fetch_query(q, (user_id,))
    
    return render_template('orders.html', orders=orders)

##############################################################################
# YORUMLAR (REVIEWS)
##############################################################################
@app.route('/products/<int:product_id>/review', methods=['POST'])
def add_review(product_id):
    """
    Bir ürüne yorum ekleme.
    """
    if not is_logged_in():
        flash("Yorum yapmak için giriş yapmalısınız.", "warning")
        return redirect(url_for('login'))
    
    rating = request.form.get('rating')
    if not rating:
        flash("Puan boş olamaz.", "danger")
        return redirect(url_for('product_detail', product_id=product_id))
    
    try:
        rating = int(rating)
        if rating < 1 or rating > 5:
            flash("Puan 1-5 arasında olmalı.", "danger")
            return redirect(url_for('product_detail', product_id=product_id))
    except:
        flash("Geçersiz puan.", "danger")
        return redirect(url_for('product_detail', product_id=product_id))
    
    user_id = get_current_user_id()
    # ekle
    q = """
        INSERT INTO Reviews (product_id, user_id, rating)
        VALUES (%s, %s, %s);
    """
    
    db.execute_query(q, (product_id, user_id, rating))
    global product_rating_update_flag
    sleep(0.4)  # Trigger'ın çalışması için biraz bekle
    if product_rating_update_flag:
        flash("Yorum eklendi.(TRIGGER AKTIF)", "success")
        product_rating_update_flag = False
    else:
        flash("Yorum eklendi, ancak ortalama puan güncellenemedi.(TRIGGER PASIF)", "warning")
    return redirect(url_for('product_detail', product_id=product_id))

@app.route('/reviews/<int:review_id>/delete', methods=['POST'])
def delete_review(review_id):
    """
    Kullanıcı kendi yorumunu silebilir.
    """
    if not is_logged_in():
        flash("Yorum silmek için giriş yapmalısınız.", "warning")
        return redirect(url_for('login'))
    
    user_id = get_current_user_id()
    
    # Yorumun sahibi mi kontrol et
    check_q = "SELECT product_id FROM Reviews WHERE review_id = %s AND user_id = %s;"
    review = db.fetch_query(check_q, (review_id, user_id))
    if not review:
        flash("Bu yorumu silme yetkiniz yok.", "danger")
        return redirect(url_for('index'))
    
    product_id = review[0]['product_id']
    
    # Yorumu sil
    delete_q = "DELETE FROM Reviews WHERE review_id = %s;"
    db.execute_query(delete_q, (review_id,))
    
    global product_rating_update_flag
    sleep(0.4)  # Trigger'ın çalışması için biraz bekle
    if product_rating_update_flag:
        flash("Yorum silindi.(TRIGGER AKTIF)", "info")
        product_rating_update_flag = False
    else:
        flash("Yorum silindi, ancak ortalama puan güncellenemedi.(TRIGGER PASIF)", "warning")
    return redirect(url_for('product_detail', product_id=product_id))

##############################################################################
# SATICI PANELİ: ÜRÜNLERİM, SATIŞ İSTATİSTİKLERİ
##############################################################################
@app.route('/my_products')
def my_products():
    """
    Giriş yapmış kullanıcıya ait ürünlerin listesi
    """
    if not is_logged_in():
        flash("Ürünlerinizi görmek için giriş yapmalısınız.", "warning")
        return redirect(url_for('login'))
    
    user_id = get_current_user_id()
    q = """
      SELECT p.product_id, p.name, p.price,  p.image_url, c.name as category_name
      FROM Products p
      JOIN Categories c ON p.category_id = c.category_id
      WHERE p.seller_id = %s AND p.deleted = FALSE
      ORDER BY p.product_id DESC;
    """
    products = db.fetch_query(q, (user_id,))
    print(products)
    return render_template('my_products.html', products=products)

@app.route('/my_sales')
def my_sales():
    """
    Kullanıcıya ait ürünlerin toplam satış miktarı (toplam adedi)
    ve ortalama rating gibi bilgileri gösterebiliriz.
    """
    if not is_logged_in():
        flash("Satış istatistiklerini görmek için giriş yapmalısınız.", "warning")
        return redirect(url_for('login'))
    
    user_id = get_current_user_id()
    q = """
        SELECT p.product_id, p.name, p.price, p.image_url,
               COALESCE(SUM(oi.quantity), 0) as total_quantity_sold,
               COALESCE(AVG(r.rating), 0) as avg_rating
        FROM Products p
        LEFT JOIN Order_Items oi ON p.product_id = oi.product_id
        LEFT JOIN Reviews r ON p.product_id = r.product_id
        WHERE p.seller_id = %s AND p.deleted = FALSE
        GROUP BY p.product_id;
    """
    stats = db.fetch_query(q, (user_id,))
    return render_template('my_sales.html', stats=stats)

# ...existing code...
@app.route('/pending_reviews')
def pending_reviews():
    """
    Kullanıcının satın alıp da henüz yorum yapmadığı ürünleri listeler.
    EXCEPT kullanarak, Orders + Order_Items'tan gelen ürün ID'lerinden
    Reviews tablosuna kaydettiği ürün ID'lerini çıkarıyoruz.
    """
    if not is_logged_in():
        flash("Bu sayfayı görmek için giriş yapmalısınız.", "warning")
        return redirect(url_for('login'))
    
    user_id = get_current_user_id()

    # EXCEPT ile alma:
    query = """
        SELECT p.product_id, p.name, p.price, p.image_url
        FROM Products p
        JOIN (
            SELECT product_id
            FROM Order_Items oi
            JOIN Orders o ON oi.order_id = o.order_id
            WHERE o.buyer_id = %s
            EXCEPT
            SELECT product_id
            FROM Reviews
            WHERE user_id = %s
        ) AS sub ON p.product_id = sub.product_id;
    """
    products_to_review = db.fetch_query(query, (user_id, user_id))
    print(products_to_review)
    return render_template('pending_reviews.html', products=products_to_review)

@app.route('/top_categories')
def top_categories():
    """
    Ortalama puanı belli bir değerin üzerinde olan kategorileri listeler.
    HAVING ifadesiyle aggregate fonksiyonları filtreliyoruz.
    """
    min_rating_str = request.args.get('min_rating', '4.0')
    try:
        min_rating = float(min_rating_str)
    except ValueError:
        min_rating = 4.0  # Geçersiz sayı gelirse varsayılanı kullan
    
    query = """
        SELECT c.category_id,
               c.name AS category_name,
               ROUND(AVG(CASE WHEN r.rating IS NOT NULL THEN r.rating ELSE NULL END), 2) AS avg_rating,
               COUNT(p.product_id) AS product_count,
               COUNT(r.review_id) AS total_reviews
        FROM Categories c
        JOIN Products p ON c.category_id = p.category_id
        LEFT JOIN Reviews r ON p.product_id = r.product_id WHERE p.deleted = FALSE
        GROUP BY c.category_id
        HAVING AVG(CASE WHEN r.rating IS NOT NULL THEN r.rating ELSE NULL END) >= %s
        ORDER BY avg_rating DESC;
    """
    categories = db.fetch_query(query, (min_rating,))
    
    return render_template('top_categories.html',
                           categories=categories,
                           min_rating=min_rating)


@app.route('/analytics')
def analytics_home():
    """
    Analiz (İstatistik) ana sayfası.
    Burada kullanıcı, hangi analizi yapmak istediğini seçer.
    Basit linklerle alt sayfalara yönlendirme yaparız.
    """
    return render_template('analytics_home.html')

@app.route('/analytics/category_rating', methods=['GET', 'POST'])
def analytics_category_rating():
    """
    1) Kategori ortalama puanı:
       get_category_avg_rating(_cat_id INT)
    Kullanıcıya kategori listesini dropdown’da gösteririz. 
    Seçili kategoriye göre fonksiyonu çağırır, sonucu gösteririz.
    """
    # Kategorileri çek (dropdown için)
    cat_query = "SELECT category_id, name FROM Categories ORDER BY name;"
    all_categories = db.fetch_query(cat_query)

    # Sonuç tutulacak
    category_avg_data = []

    if request.method == 'POST':
        cat_id = request.form.get('cat_id')
        if not cat_id:
            flash("Lütfen bir kategori seçiniz.", "warning")
        else:
            cat_id = int(cat_id)
            return redirect(url_for('analytics_category_rating', cat_id=cat_id))

    if request.method == 'GET':
        cat_id = request.args.get('cat_id')
        if cat_id:
            query = "SELECT * FROM get_category_avg_rating(%s)"
            category_avg_data = db.fetch_query(query, (cat_id,))

    return render_template('analytics_category_rating.html',
                           all_categories=all_categories,
                           category_avg_data=category_avg_data)

@app.route('/analytics/my_top_selling', methods=['GET'])
def analytics_my_top_selling():
    """
    2) En Çok Satan 5 Ürünüm:
       find_top_selling_products_for_user_with_cursor(_user_id INT)
    Kullanıcı giriş yapmamışsa uyarı. Giriş yapmışsa, session’daki user_id 
    ile fonksiyonu çağırır ve tabloyu gösterir.
    """
    if not is_logged_in():
        flash("Bu sayfayı kullanmak için giriş yapmalısınız.", "danger")
        return redirect(url_for('login'))

    user_id = get_current_user_id()
    query = "SELECT * FROM find_top_selling_products_for_user_with_cursor(%s)"
    top_selling_data = db.fetch_query(query, (user_id,))

    return render_template('analytics_my_top_selling.html',
                           top_selling_data=top_selling_data)

@app.route('/analytics/min_rating', methods=['GET', 'POST'])
def analytics_min_rating():
    """
    3) Belirli Puanın Üstündeki Ürünler:
       get_products_with_min_rating(_min_rating FLOAT, _limit INT)
    Kullanıcıya min_rating ve limit girdirir. Fonksiyonu çağırıp tablo gösteririz.
    """
    results = []
    
    # Varsayılan değerler
    default_min_rating = 3.0
    default_limit = 5

    min_rating = default_min_rating
    limit_val = default_limit

    if request.method == 'POST':
        min_rating_str = request.form.get('min_rating')
        limit_str = request.form.get('limit_val')
        try:
            min_rating = float(min_rating_str)
            limit_val = int(limit_str)
        except ValueError:
            flash("Lütfen geçerli bir puan ve limit giriniz.", "warning")
            return redirect(url_for('analytics_min_rating'))
        else:
            query = "SELECT * FROM get_products_with_min_rating(%s, %s)"
            results = db.fetch_query(query, (min_rating, limit_val))
            return redirect(url_for('analytics_min_rating', min_rating=min_rating, limit_val=limit_val))

    if request.method == 'GET':
        min_rating = request.args.get('min_rating', default_min_rating)
        limit_val = request.args.get('limit_val', default_limit)
        query = "SELECT * FROM get_products_with_min_rating(%s, %s)"
        results = db.fetch_query(query, (min_rating, limit_val))

    return render_template('analytics_min_rating.html',
                           results=results,
                           min_rating=min_rating,
                           limit_val=limit_val)

##############################################################################
# UYGULAMA ÇALIŞTIRMA
##############################################################################
if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=5000)