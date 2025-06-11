INSERT INTO customer (email, password_customer, first_name, last_name, phone_number, gender, age, profession, income_level, city)
VALUES 
('ayse@example.com', 'hashed_pass1', 'Ayşe', 'Demir', '05551112233', 'female', 30, 'Mühendis', 'medium', 'İstanbul'),
('mehmet@example.com', 'hashed_pass2', 'Mehmet', 'Yılmaz', '05553334455', 'male', 40, 'Doktor', 'high', 'Ankara'),
('zeynep@example.com', 'hashed_pass3', 'Zeynep', 'Kaya', '05552223344', 'female', 25, 'Öğrenci', 'low', 'İzmir'),
('ahmet@example.com', 'hashed_pass4', 'Ahmet', 'Çetin', '05443334455', 'male', 35, 'Avukat', 'medium', 'Bursa'),
('elif@example.com', 'hashed_pass5', 'Elif', 'Koç', '05441112233', 'female', 28, 'Grafiker', 'medium', 'Antalya');

INSERT INTO dealer (email, password)
VALUES 
('dealer@example.com', 'hashed_dealer');

INSERT INTO warehouse(email, password)
VALUES 
('warehouse@example.com', 'hashed_warehouse');

INSERT INTO vehicle (brand, model, year, package, price)
VALUES 
('Renault', 'Clio', 2023, 'Touch', 450000.00),
('Toyota', 'Corolla', 2024, 'Flame', 650000.00),
('Hyundai', 'i20', 2023, 'Elite', 520000.00),
('Volkswagen', 'Golf', 2022, 'Style', 780000.00),
('Peugeot', '208', 2024, 'Active', 490000.00);

INSERT INTO stock (vehicle_id, location_type, quantity)
VALUES 
(1, 'warehouse', 10),
(3, 'warehouse', 8),
(5, 'warehouse', 1),
(1, 'dealer', 2),
(2, 'dealer', 3),
(3, 'dealer', 4),
(4, 'dealer', 5),
(5, 'dealer', 6);

INSERT INTO sales (vehicle_id, user_id, sale_date, sale_price)
VALUES 
-- 2025 2. dönem (Nis-May-Haz)
(1, 1, '2025-04-10', 460000.00),
(3, 3, '2025-05-15', 530000.00),
-- 2025 1. dönem (Oca-Şub-Mar)
(4, 4, '2025-01-20', 780000.00),
(5, 5, '2025-02-14', 495000.00),
-- 2024 4. dönem (Eki-Kas-Ara)
(2, 1, '2024-10-30', 610000.00),
(3, 5, '2024-11-11', 520000.00),
(1, 4, '2024-12-05', 790000.00),
-- 2024 3. dönem (Tem-Ağu-Eyl)
(5, 2, '2024-07-22', 490000.00),
(3, 1, '2024-08-18', 460000.00),
-- 2024 2. dönem (Nis-May-Haz)
(3, 4, '2024-05-05', 525000.00),
(4, 5, '2024-06-10', 785000.00),
-- 2024 1. dönem (Oca-Şub-Mar)
(2, 4, '2024-01-20', 780000.00),
(5, 3, '2024-03-22', 455000.00);


INSERT INTO requests (user_id, request_type, vehicle_id, request_date, status)
VALUES 
-- 2025 2. dönem
(1, 'price_offer', 1, '2025-04-05', 'accepted'),   -- request_id = 1
(2, 'price_offer', 2, '2025-04-28', 'accepted'),   -- request_id = 2
(3, 'price_offer', 3, '2025-05-10', 'accepted'),   -- request_id = 3

-- 2025 1. dönem
(4, 'price_offer', 4, '2025-01-15', 'accepted'),   -- request_id = 4
(5, 'price_offer', 5, '2025-02-10', 'accepted'),   -- request_id = 5
(3, 'price_offer', 1, '2025-03-18', 'pending'),    -- request_id = 6

-- 2024 4. dönem
(1, 'price_offer', 2, '2024-10-25', 'accepted'),   -- request_id = 7
(5, 'price_offer', 3, '2024-11-07', 'accepted'),   -- request_id = 8
(4, 'price_offer', 1, '2024-11-30', 'accepted'),   -- request_id = 9

-- 2024 3. dönem
(2, 'price_offer', 5, '2024-07-18', 'accepted'),   -- request_id = 10
(1, 'price_offer', 3, '2024-08-10', 'accepted'),   -- request_id = 11
(3, 'price_offer', 2, '2024-09-01', 'pending'),    -- request_id = 12

-- 2024 2. dönem
(4, 'price_offer', 3, '2024-05-01', 'accepted'),   -- request_id = 13
(5, 'price_offer', 4, '2024-06-05', 'accepted'),   -- request_id = 14
(2, 'price_offer', 4, '2024-06-20', 'pending'),    -- request_id = 15

-- 2024 1. dönem
(4, 'price_offer', 2, '2024-01-15', 'accepted'),   -- request_id = 16
(5, 'price_offer', 1, '2024-02-10', 'pending'),    -- request_id = 17
(3, 'price_offer', 5, '2024-03-15', 'accepted'),   -- request_id = 18

-- 2025 2. dönem
(1, 'order', 1, '2025-04-10', 'accepted'),   -- request_id = 19
(3, 'order', 3, '2025-05-15', 'accepted'),   -- request_id = 21

-- 2025 1. dönem
(4, 'order', 4, '2025-01-20', 'accepted'),   -- request_id = 22
(5, 'order', 5, '2025-02-14', 'accepted'),   -- request_id = 23

-- 2024 4. dönem (Eki-Kas-Ara)
(1, 'order', 2, '2024-10-30', 'accepted'),   -- request_id = 24
(5, 'order', 3, '2024-11-11', 'accepted'),   -- request_id = 25
(4, 'order', 4, '2024-12-05', 'accepted'),   -- request_id = 26

-- 2024 3. dönem (Tem-Ağu-Eyl)
(2, 'order', 5, '2024-07-22', 'accepted'),   -- request_id = 27
(1, 'order', 1, '2024-08-18', 'accepted'),   -- request_id = 28

-- 2024 2. dönem
(4, 'order', 3, '2024-05-05', 'accepted'),   -- request_id = 29
(5, 'order', 4, '2024-06-10', 'accepted'),   -- request_id = 30

-- 2024 1. dönem
(4, 'order', 4, '2024-01-20', 'accepted'),   -- request_id = 31
(3, 'order', 1, '2024-03-22', 'accepted'),   -- request_id = 32

(4, 'test_drive', 4, '2023-01-20', 'accepted'),   -- request_id = 33
(3, 'test_drive', 1, '2024-03-22', 'accepted'),   -- request_id = 34
(2, 'test_drive', 5, '2024-07-22', 'accepted'),   -- request_id = 35
(1, 'test_drive', 1, '2022-08-18', 'accepted');   -- request_id = 36


INSERT INTO price_offers (request_id, user_id, vehicle_id, offer_date, offered_price)
VALUES 
-- 2025 2. dönem
(1, 1, 1, '2025-04-28', 460000.00),
(2, 2, 2, '2025-04-28', 480000.00),
(3, 3, 3, '2025-05-10', 530000.00),

-- 2025 1. dönem
(4, 4, 4, '2025-01-15', 780000.00),
(5, 5, 5, '2025-02-10', 495000.00),

-- 2024 4. dönem
(7, 1, 2, '2024-10-25', 610000.00),
(8, 5, 3, '2024-11-07', 520000.00),
(9, 1, 4, '2024-11-30', 790000.00),

-- 2024 3. dönem
(10, 2, 5, '2024-07-18', 490000.00),
(11, 1, 3, '2024-08-10', 460000.00),

-- 2024 2. dönem
(13, 4, 3, '2024-05-01', 525000.00),
(14, 5, 4, '2024-06-05', 785000.00),

-- 2024 1. dönem
(16, 4, 2, '2024-01-15', 780000.00),
(18, 3, 5, '2024-03-15', 455000.00);