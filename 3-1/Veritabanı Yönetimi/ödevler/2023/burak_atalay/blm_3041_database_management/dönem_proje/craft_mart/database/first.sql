-- create_tables.sql

-- 1) Veritabanı oluşturma (Eğer oluşturmadıysanız)
-- CREATE DATABASE craftmart;

-- craftmart veritabanına bağlanma (manuel olarak bağlanabilirsiniz)
-- \c craftmart;

------------------------------------------------------------------------------
-- Users Tablosu
------------------------------------------------------------------------------
CREATE SEQUENCE user_id_seq
START 1
INCREMENT 1
NO MINVALUE
NO MAXVALUE
CACHE 1;

CREATE TABLE IF NOT EXISTS Users (
    user_id INT NOT NULL DEFAULT nextval('user_id_seq'),
    name VARCHAR(100) NOT NULL,
    username VARCHAR(255) UNIQUE NOT NULL,
    password VARCHAR(255) NOT NULL,
    PRIMARY KEY (user_id)
);

------------------------------------------------------------------------------
-- Categories Tablosu
------------------------------------------------------------------------------
CREATE TABLE IF NOT EXISTS Categories (
    category_id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL UNIQUE
);

------------------------------------------------------------------------------
-- Products Tablosu
------------------------------------------------------------------------------
CREATE TABLE IF NOT EXISTS Products (
    product_id SERIAL PRIMARY KEY,
    seller_id INT NOT NULL,
    name VARCHAR(255) NOT NULL,
    price NUMERIC(10, 2) NOT NULL CHECK (price > 0),
    category_id INT NOT NULL,
    total_sales INT DEFAULT 0 CHECK (total_sales >= 0),
    rating NUMERIC NOT NULL CHECK (rating BETWEEN 0 AND 5),
    image_url VARCHAR(255),
    deleted BOOLEAN DEFAULT FALSE,
    FOREIGN KEY (seller_id) REFERENCES Users(user_id) ON DELETE CASCADE,
    FOREIGN KEY (category_id) REFERENCES Categories(category_id)
);

------------------------------------------------------------------------------
-- Orders Tablosu
------------------------------------------------------------------------------
CREATE TABLE IF NOT EXISTS Orders (
    order_id SERIAL PRIMARY KEY,
    buyer_id INT NOT NULL,
    total_price NUMERIC(10, 2) NOT NULL CHECK (total_price >= 0),
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (buyer_id) REFERENCES Users(user_id)
);

------------------------------------------------------------------------------
-- Order_Items Tablosu
------------------------------------------------------------------------------
CREATE TABLE IF NOT EXISTS Order_Items (
    order_item_id SERIAL PRIMARY KEY,
    order_id INT NOT NULL,
    product_id INT NOT NULL,
    quantity INT NOT NULL CHECK (quantity > 0),
    price NUMERIC(10, 2) NOT NULL CHECK (price > 0),
    FOREIGN KEY (order_id) REFERENCES Orders(order_id) ON DELETE CASCADE,
    FOREIGN KEY (product_id) REFERENCES Products(product_id) ON DELETE CASCADE
);

------------------------------------------------------------------------------
-- Reviews Tablosu
------------------------------------------------------------------------------
CREATE TABLE IF NOT EXISTS Reviews (
    review_id SERIAL PRIMARY KEY,
    product_id INT NOT NULL,
    user_id INT NOT NULL,
    rating INT NOT NULL CHECK (rating BETWEEN 0 AND 5),
    FOREIGN KEY (product_id) REFERENCES Products(product_id) ON DELETE CASCADE,
    FOREIGN KEY (user_id) REFERENCES Users(user_id) ON DELETE CASCADE
);

------------------------------------------------------------------------------
-- Script Sonu
------------------------------------------------------------------------------


CREATE OR REPLACE VIEW latest_products AS
SELECT p.product_id, p.name, p.price, p.rating, c.name AS category_name, p.image_url
FROM Products p
JOIN Categories c ON p.category_id = c.category_id WHERE p.deleted = FALSE
ORDER BY p.product_id DESC
LIMIT 6;

--------------------------------------------------------




---------------------------------------------
-- TYPE: category_avg_rating_type
---------------------------------------------
CREATE TYPE category_avg_rating_type AS (
  cat_id INT,
  cat_name VARCHAR,
  avg_rating NUMERIC
);

---------------------------------------------
-- FUNCTION: get_category_avg_rating(_cat_id INT)
---------------------------------------------
CREATE OR REPLACE FUNCTION get_category_avg_rating(_cat_id INT)
  RETURNS SETOF category_avg_rating_type
  LANGUAGE plpgsql
AS $$
DECLARE
    rec category_avg_rating_type;
    cur CURSOR FOR
        SELECT c.category_id AS cat_id,
               c.name AS cat_name,
               ROUND(AVG(p.rating), 2) AS avg_rating
        FROM Categories c
        JOIN Products p ON c.category_id = p.category_id
        WHERE c.category_id = _cat_id
          AND p.deleted = FALSE
          AND p.rating > 0  -- Exclude products with a rating of 0
        GROUP BY c.category_id;
BEGIN
    OPEN cur;
    LOOP
        FETCH cur INTO rec;
        EXIT WHEN NOT FOUND;
        RETURN NEXT rec;
    END LOOP;
    CLOSE cur;
END;
$$;


---------------------------------------------
-- TYPE: top_selling_product_type
---------------------------------------------
CREATE TYPE top_selling_product_type AS (
  product_id INT,
  product_name VARCHAR,
  total_sales INT
);

---------------------------------------------
-- FUNCTION: find_top_selling_products_for_user_with_cursor(_user_id INT)
---------------------------------------------
CREATE OR REPLACE FUNCTION find_top_selling_products_for_user_with_cursor(_user_id INT)
  RETURNS SETOF top_selling_product_type
  LANGUAGE plpgsql
AS $$
DECLARE
    rec top_selling_product_type;
    cur CURSOR FOR
        SELECT p.product_id,
               p.name AS product_name,
               p.total_sales,
               p.image_url
        FROM Products p
        WHERE p.seller_id = _user_id
          AND p.deleted = FALSE
        ORDER BY p.total_sales DESC
        LIMIT 5;
BEGIN
    OPEN cur;
    LOOP
        FETCH cur INTO rec;
        EXIT WHEN NOT FOUND;
        RETURN NEXT rec;
    END LOOP;
    CLOSE cur;
END;
$$;


---------------------------------------------
-- TYPE: product_with_min_rating_type
---------------------------------------------
CREATE TYPE product_with_min_rating_type AS (
  product_id INT,
  name VARCHAR,
  price NUMERIC,
  rating NUMERIC,
  seller_id INT
);

---------------------------------------------
-- FUNCTION: get_products_with_min_rating(_min_rating FLOAT, _limit INT)
---------------------------------------------
CREATE OR REPLACE FUNCTION get_products_with_min_rating(_min_rating FLOAT, _limit INT)
  RETURNS SETOF product_with_min_rating_type
  LANGUAGE plpgsql
AS $$
DECLARE
    rec product_with_min_rating_type;
    cur CURSOR FOR
        SELECT p.product_id,
               p.name,
               p.price,
               p.rating,
               p.seller_id
        FROM Products p
        WHERE p.deleted = FALSE
          AND p.rating >= _min_rating
        ORDER BY p.rating DESC
        LIMIT _limit;
BEGIN
    OPEN cur;
    LOOP
        FETCH cur INTO rec;
        EXIT WHEN NOT FOUND;
        RETURN NEXT rec;
    END LOOP;
    CLOSE cur;
END;
$$;

---------------------------------------------
-- reviews_trigger
---------------------------------------------
CREATE OR REPLACE FUNCTION auto_update_product_rating() 
    RETURNS TRIGGER AS $$
    DECLARE 
        new_avg FLOAT;
        product_id_variable INT;
    BEGIN
        -- İşlem türüne göre product_id belirle
        IF TG_OP = 'INSERT' THEN
            product_id_variable = NEW.product_id;
        ELSIF TG_OP = 'DELETE' THEN
            product_id_variable = OLD.product_id;
        END IF;

        -- Ürüne ait ortalama puanı hesapla
        SELECT AVG(rating) 
        INTO new_avg
        FROM Reviews
        WHERE product_id = product_id_variable;
        
        -- Products tablosunda rating güncelle
        UPDATE Products p
        SET rating = COALESCE(new_avg, 0)
        WHERE p.product_id = product_id_variable;

        -- Notify mesajı gönder
        PERFORM pg_notify('product_rating_update', 
            'Product ID ' || product_id_variable || ' rating updated to ' || COALESCE(new_avg::TEXT, '0'));

        RAISE NOTICE 'Trigger Çalıştı: % -> Ürünün ortalama puanı güncellendi -> %', TG_OP, new_avg;
        RETURN NEW;
    END;
    $$ LANGUAGE plpgsql;


CREATE TRIGGER reviews_trigger
AFTER INSERT OR DELETE ON Reviews
FOR EACH ROW
EXECUTE PROCEDURE auto_update_product_rating();


---------------------------------------------
-- create_trigger_orders
---------------------------------------------
CREATE OR REPLACE FUNCTION update_product_total_sales()
RETURNS TRIGGER AS $$
BEGIN
    IF TG_OP = 'INSERT' THEN
        -- Yeni bir sipariş eklendiğinde total_sales'i artır
        UPDATE Products
        SET total_sales = total_sales + NEW.quantity
        WHERE product_id = NEW.product_id;

        -- Notify mesajı gönder
        PERFORM pg_notify('product_total_sales_update', 
            'Product ID ' || NEW.product_id || ' total sales increased by ' || NEW.quantity);

        RAISE NOTICE 'Trigger Çalıştı: % -> Ürünün toplam satışları artırıldı -> %', TG_OP, NEW.quantity;

    ELSIF TG_OP = 'DELETE' THEN
        -- Sipariş iptal edildiğinde total_sales'i azalt
        UPDATE Products
        SET total_sales = total_sales - OLD.quantity
        WHERE product_id = OLD.product_id;

        -- Notify mesajı gönder
        PERFORM pg_notify('product_total_sales_update', 
            'Product ID ' || OLD.product_id || ' total sales decreased by ' || OLD.quantity);

        RAISE NOTICE 'Trigger Çalıştı: % -> Ürünün toplam satışları azaltıldı -> %', TG_OP, OLD.quantity;

    ELSIF TG_OP = 'UPDATE' THEN
        -- Sipariş güncellenirse eski ve yeni miktar arasındaki farkı uygula
        UPDATE Products
        SET total_sales = total_sales - OLD.quantity + NEW.quantity
        WHERE product_id = NEW.product_id;

        -- Notify mesajı gönder
        PERFORM pg_notify('product_total_sales_update', 
            'Product ID ' || NEW.product_id || ' total sales updated by ' || (NEW.quantity - OLD.quantity));

        RAISE NOTICE 'Trigger Çalıştı: % -> Ürünün toplam satışları güncellendi -> %', TG_OP, (NEW.quantity - OLD.quantity);
    END IF;

    RETURN NEW;
END;
$$ LANGUAGE plpgsql;


CREATE TRIGGER order_items_trigger
AFTER INSERT OR DELETE OR UPDATE ON Order_Items
FOR EACH ROW
EXECUTE PROCEDURE update_product_total_sales();
