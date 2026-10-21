-- Users table sample data
INSERT INTO users (username, email, password_hash, phone) VALUES
('john_doe', 'john@example.com', 'hash1', '555-0101'),
('jane_smith', 'jane@example.com', 'hash2', '555-0102'),
('mike_wilson', 'mike@example.com', 'hash3', '555-0103'),
('sarah_brown', 'sarah@example.com', 'hash4', '555-0104'),
('david_lee', 'david@example.com', 'hash5', '555-0105'),
('emma_davis', 'emma@example.com', 'hash6', '555-0106'),
('james_taylor', 'james@example.com', 'hash7', '555-0107'),
('lisa_white', 'lisa@example.com', 'hash8', '555-0108'),
('robert_martin', 'robert@example.com', 'hash9', '555-0109'),
('amy_garcia', 'amy@example.com', 'hash10', '555-0110');

INSERT INTO pets (user_id, name, species, breed, age, weight, birth_date) VALUES
(1, 'Max', 'Köpek', 'Golden Retriever', 3, 30.5, '2021-03-15'),
(1, 'Luna', 'Kedi', 'Persian', 2, 4.2, '2022-01-20'),
(2, 'Bella', 'Köpek', 'Labrador', 5, 28.7, '2019-06-10'),
(3, 'Charlie', 'Köpek', 'Poodle', 1, 8.3, '2023-02-28'),
(4, 'Milo', 'Kedi', 'Siamese', 4, 3.8, '2020-09-12'),
(5, 'Lucy', 'Köpek', 'Beagle', 2, 12.4, '2022-04-05'),
(6, 'Leo', 'Kedi', 'Maine Coon', 3, 6.1, '2021-11-30'),
(7, 'Rocky', 'Köpek', 'Alman Kurdu', 4, 32.6, '2020-07-22'),
(8, 'Lily', 'Kedi', 'Ragdoll', 1, 3.5, '2023-01-15'),
(9, 'Cooper', 'Köpek', 'Bulldog', 6, 25.0, '2018-12-03');

INSERT INTO vet_clinics (name, address, phone, email, rating) VALUES
('PawsCare Kliniği', '123 Ana Cadde', '555-1001', 'pawscare@example.com', 4.5),
('Mutlu Evcil Hayvanlar Veterineri', '456 Meşe Caddesi', '555-1002', 'happypets@example.com', 4.8),
('Şehir Veterinerliği', '789 Çam Yolu', '555-1003', 'cityvets@example.com', 4.2),
('Hayvan Sağlığı Merkezi', '321 Karaağaç Caddesi', '555-1004', 'wellness@example.com', 4.7),
('Evcil Hayvan Sağlık Merkezi', '654 Akçaağaç Yolu', '555-1005', 'pethealth@example.com', 4.4),
('Özenli Veterinerler', '987 Sedir Sokak', '555-1006', 'caringvets@example.com', 4.6),
('VetCare Plus', '147 Huş Caddesi', '555-1007', 'vetcare@example.com', 4.3),
('Evcil Hayvan Doktorları', '258 Ladin Caddesi', '555-1008', 'petdocs@example.com', 4.9),
('Hayvan Hastanesi', '369 Söğüt Yolu', '555-1009', 'hospital@example.com', 4.1),
('Nazik Bakım Veterinerleri', '741 Palmiye Yolu', '555-1010', 'gentle@example.com', 4.5);

INSERT INTO appointments (pet_id, clinic_id, appointment_date, reason, status) VALUES
(1, 1, '2024-01-20 10:00:00', 'Yıllık kontrol', 'Tamamlandı'),
(2, 2, '2024-01-21 14:30:00', 'Aşı', 'Planlandı'),
(3, 3, '2024-01-22 11:15:00', 'Diş temizliği', 'Planlandı'),
(4, 4, '2024-01-23 09:45:00', 'Cilt problemi', 'İptal Edildi'),
(5, 5, '2024-01-24 16:00:00', 'Rutin kontrol', 'Planlandı'),
(6, 6, '2024-01-25 13:30:00', 'Göz enfeksiyonu', 'Planlandı'),
(7, 7, '2024-01-26 10:30:00', 'Aşı', 'Planlandı'),
(8, 8, '2024-01-27 15:45:00', 'Ameliyat sonrası kontrol', 'Planlandı'),
(9, 9, '2024-01-28 12:00:00', 'Yıllık kontrol', 'Planlandı'),
(10, 10, '2024-01-29 11:00:00', 'Aşı', 'Planlandı');

INSERT INTO products (name, category, price, stock_quantity, description) VALUES
('Premium Köpek Maması', 'Yiyecek', 49.99, 100, 'Yüksek kaliteli kuru köpek maması'),
('Kedi Kumu Kabı', 'Malzemeler', 29.99, 50, 'Büyük otomatik kedi kumu kabı'),
('Evcil Hayvan Yatağı - Büyük', 'Mobilya', 79.99, 30, 'Büyük köpekler için rahat yatak'),
('Kedi Oyuncak Seti', 'Oyuncaklar', 19.99, 80, '5 parçalı interaktif kedi oyuncak seti'),
('Köpek Tasması', 'Aksesuarlar', 24.99, 60, 'Dayanıklı naylon tasma'),
('Akvaryum Filtresi', 'Ekipman', 39.99, 40, 'Gelişmiş filtreleme sistemi'),
('Kuş Kafesi', 'Barınma', 89.99, 20, 'Geniş telli kafes'),
('Evcil Hayvan Bakım Seti', 'Bakım', 34.99, 45, 'Tam bakım seti'),
('Kedi Maması - Premium', 'Yiyecek', 44.99, 90, 'Tahılsız kedi maması'),
('Köpek Oyuncak Paketi', 'Oyuncaklar', 29.99, 70, 'Dayanıklı köpek oyuncak seti');

INSERT INTO orders (user_id, total_amount, status) VALUES
(1, 129.97, 'Tamamlandı'),
(2, 79.98, 'Tamamlandı'),
(3, 189.97, 'İşleniyor'),
(4, 54.98, 'Tamamlandı'),
(5, 99.98, 'İşleniyor'),
(6, 149.97, 'Tamamlandı'),
(7, 69.98, 'İşleniyor'),
(8, 159.96, 'Tamamlandı'),
(9, 89.98, 'Tamamlandı'),
(10, 119.97, 'İşleniyor');

-- Order details table sample data
INSERT INTO order_details (order_id, product_id, quantity, unit_price) VALUES
(1, 1, 2, 49.99),
(1, 4, 1, 29.99),
(2, 2, 1, 29.99),
(2, 5, 2, 24.99),
(3, 3, 1, 79.99),
(3, 8, 1, 34.99),
(4, 4, 1, 19.99),
(4, 5, 1, 24.99),
(5, 6, 2, 39.99),
(5, 9, 1, 44.99);

-- Vaccinations table sample data
INSERT INTO vaccinations (pet_id, vaccine_name, date_given, next_due_date, vet_clinic_id) VALUES
(1, 'Kuduz', '2023-06-15', '2024-06-15', 1),
(1, 'DHPP', '2023-07-20', '2024-07-20', 1),
(2, 'FVRCP', '2023-08-10', '2024-08-10', 2),
(3, 'Bordetella', '2023-09-05', '2024-03-05', 3),
(4, 'Kuduz', '2023-10-12', '2024-10-12', 4),
(5, 'FVRCP', '2023-11-20', '2024-11-20', 5),
(6, 'Kuduz', '2023-12-15', '2024-12-15', 6),
(7, 'DHPP', '2024-01-05', '2025-01-05', 7),
(8, 'FVRCP', '2024-01-10', '2025-01-10', 8),
(9, 'Bordetella', '2024-01-15', '2024-07-15', 9);