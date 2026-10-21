------------------------------------------------------------------------------
-- Users Tablosu İçin INSERT
------------------------------------------------------------------------------
INSERT INTO Users (name, username, password) VALUES
('Ali Demir',    'ali_demir',    '$2b$12$Fd3jaOgAJrRJomWwE8qTdeQned4NqmB500p3GeR7h8YDy5scN5NcW'),
('Veli Çelik',   'veli_celik',   '$2b$12$Fd3jaOgAJrRJomWwE8qTdeQned4NqmB500p3GeR7h8YDy5scN5NcW'),
('Ayşe Yılmaz',  'ayse_yilmaz',  '$2b$12$Fd3jaOgAJrRJomWwE8qTdeQned4NqmB500p3GeR7h8YDy5scN5NcW'),
('Mehmet Öztürk','mehmet_ozturk','$2b$12$Fd3jaOgAJrRJomWwE8qTdeQned4NqmB500p3GeR7h8YDy5scN5NcW'),
('Fatma Aslan',  'fatma_aslan',  '$2b$12$Fd3jaOgAJrRJomWwE8qTdeQned4NqmB500p3GeR7h8YDy5scN5NcW'),
('Derya Güneş',  'derya_gunes',  '$2b$12$Fd3jaOgAJrRJomWwE8qTdeQned4NqmB500p3GeR7h8YDy5scN5NcW'),
('Cem Kara',     'cem_kara',     '$2b$12$Fd3jaOgAJrRJomWwE8qTdeQned4NqmB500p3GeR7h8YDy5scN5NcW'),
('Ceren Koç',    'ceren_koc',    '$2b$12$Fd3jaOgAJrRJomWwE8qTdeQned4NqmB500p3GeR7h8YDy5scN5NcW'),
('Kerem Kurt',   'kerem_kurt',   '$2b$12$Fd3jaOgAJrRJomWwE8qTdeQned4NqmB500p3GeR7h8YDy5scN5NcW'),
('Sena Polat',   'sena_polat',   '$2b$12$Fd3jaOgAJrRJomWwE8qTdeQned4NqmB500p3GeR7h8YDy5scN5NcW');

------------------------------------------------------------------------------
-- Categories Tablosu İçin INSERT
------------------------------------------------------------------------------
INSERT INTO Categories (name) VALUES
('Takı'),
('El Örgüsü'),
('Seramik'),
('Tablo'),
('Oyuncak'),
('Ahşap Ürünler'),
('El Yapımı Sabunlar'),
('El Yapımı Mumlar'),
('Reçine Sanatı'),
('Makrome');

------------------------------------------------------------------------------
-- Products Tablosu İçin INSERT
------------------------------------------------------------------------------
-- Foreign key'ler nedeniyle seller_id (Users tablosu) ve category_id (Categories tablosu)
-- ID değerleri ile eşleşmelidir.
INSERT INTO Products (seller_id, name, price, category_id, total_sales, rating, image_url)
VALUES
(1,  'El Örgüsü Bere',              50.00,  2,  5, 0, NULL),
(2,  'El Örgüsü Atkı',              80.00,  2,  3, 0, NULL),
(3,  'Seramik Kupa',                120.00, 3,  7, 0, NULL),
(4,  'Tablo - Doğa Manzarası',      300.00, 4,  2, 0, NULL),
(5,  'Oyuncak - Amigurumi Bebek',   150.00, 5, 10, 0, NULL),
(6,  'Ahşap Oymalı Kutu',           200.00, 6,  4, 0, NULL),
(7,  'El Yapımı Sabun - Lavanta',   25.00,  7, 10, 0, NULL),
(8,  'El Yapımı Mum - Vanilya',     35.00,  8, 12, 0, NULL),
(9,  'Reçine Kolye',                60.00,  9,  9, 0, NULL),
(10, 'Makrome Duvar Süsü',          75.00,  10, 6, 0, NULL);

------------------------------------------------------------------------------
-- Orders Tablosu İçin INSERT
------------------------------------------------------------------------------
-- Foreign key: buyer_id, Users tablosundaki user_id'lere karşılık gelmelidir.
INSERT INTO Orders (buyer_id, total_price)
VALUES
(2,  130.00),
(3,  180.00),
(1,  120.00),
(5,  300.00),
(6,   95.00),
(8,  210.00),
(9,   50.00),
(7,  300.00),
(4,   45.00),
(10, 275.00);

------------------------------------------------------------------------------
-- Order_Items Tablosu İçin INSERT
------------------------------------------------------------------------------
-- Foreign key: order_id (Orders), product_id (Products)
INSERT INTO Order_Items (order_id, product_id, quantity, price)
VALUES
(1,  1,  2,  50.00),
(2,  2,  1,  80.00),
(3,  3,  1, 120.00),
(4,  4,  1, 300.00),
(5,  5,  1, 150.00),
(5,  7,  1,  25.00),
(6,  8,  2,  35.00),
(7,  9,  1,  60.00),
(8,  6,  1, 200.00),
(9,  1,  1,  50.00);

------------------------------------------------------------------------------
-- Reviews Tablosu İçin INSERT
------------------------------------------------------------------------------
-- Foreign key: product_id (Products), user_id (Users)
-- rating 1-5 aralığında olmalıdır.
INSERT INTO Reviews (product_id, user_id, rating)
VALUES
(1,  2,  1),
(1,  3,  2),
(2,  4,  3),
(3,  5,  4),
(4,  6,  5),
(5,  7,  1),
(6,  8,  2),
(7,  9,  3),
(8,  1,  4),
(9, 10,  5);

------------------------------------------------------------------------------
-- Script Sonu
------------------------------------------------------------------------------