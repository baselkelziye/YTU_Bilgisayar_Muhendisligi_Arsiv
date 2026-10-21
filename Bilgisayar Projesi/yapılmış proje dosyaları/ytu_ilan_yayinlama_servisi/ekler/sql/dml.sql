INSERT INTO announcement_type VALUES
  (1, 'Staj'),
  (2, 'Yarı zamanlı'),
  (3, 'Tam zamanlı'),
  (4, 'freelance'),
  (5, '-Duyuru İlanı-'),
  (-1, 'Tüm Tipler');

INSERT INTO user_type (type_no, type_name, main_page, unauthorized_page) VALUES
  (0, 'admin', 'directadminmainpageservlet', 'admin/erisim-izni-yok.jsp'),
  (1, 'donation_accept_unit', 'daumainpage', 'dau/erisim-izni-yok.jsp'),
  (2, 'company', 'companymainpage', 'company/erisim-izni-yok.jsp'),
  (3, 'student', 'studentmainpage', 'student/erisim-izni-yok.jsp') ;

INSERT INTO announcement_state VALUES
  (1, 'passive'),
  (2, 'active'),
  (3, 'expired'),
  (4, 'suspended') ;

INSERT INTO membership_status (id, status) VALUES
  (0, 'onay bekleniyor'),
  (1, 'aktif'),
  (2, 'süreli cezalı'),
  (3, 'süresiz cezalı'),
  (4, 'admin onayı bekleniyor'),
  (5, 'kullanıcı tarafından pasif hale getirilmiş'),
  (6, 'yeni şifre belirlemek zorunda');

INSERT INTO currency VALUES
  (1, 'Türk Lirası'),
  (2, 'Euro'),
  (3, 'Amerikan Doları');

INSERT INTO announcement_packet_state (id, title) VALUES
  (-1, 'Tümü'),
  (1, 'Onay Bekleniyor'),
  (2, 'Kullanılabilir'),
  (3, 'Kullanım süresi sona erdi'),
  (4, 'İkinci Ödeme Şansı'),
  (5, 'Reddedildi'),
  (6, 'İkinci Ödeme Onayı Bekleniyor');

INSERT INTO department (code, name) VALUES
  ('011', 'Bilgisayar Mühendisliği'),
  ('012', 'Elektrik Mühendisliği'),
  ('014', 'Elektronik ve Haberleşme Mühendisliği'),
  ('015', 'Kontrol ve Otomasyon Mühendisliği'),
  ('021', 'Felsefe'),
  ('022', 'Fizik'),
  ('023', 'İstatistik'),
  ('024', 'Kimya'),
  ('025', 'Matematik'),
  ('026', 'Mütercim-Tercümanlık (Fransızca)'),
  ('027', 'Türk Dili ve Edebiyatı'),
  ('028', 'Moleküler Biyoloji ve Genetik'),
  ('029', 'İnsan ve Toplum Bilimleri'),
  ('02B', 'Sosyoloji'),
  ('02D', 'Kimya (İngilizce)');

INSERT INTO spending_request_state (id, title) VALUES
  (-1, 'Tüm Durumlar'),
  (1, 'Harcama Bekleniyor'),
  (2, 'Harcama Yapıldı'),
  (3, 'Harcama İsteği Reddedildi'),
  (4, 'Yönetici tarafından askıya alındı');

INSERT INTO announcement_category (id, category_name, parent_category_id)  VALUES
  (-1, 'Tüm Kategoriler', 0, 0),
  (0, 'root-category', 0),
  (1, 'Diğer', 0),
  (2, 'Etkinlik', 1);

INSERT INTO donation_accept_unit (unit_name, balance) VALUES
  ('Tüm Birimler', 0);

INSERT INTO global_parameter (name, value, type) VALUES
	('Mail Adresi', 'ytu.ilanservisi@gmail.com', 'mail'),
	('Mail Parola', 'ytu.ilanservisi1717', 'mail'),
	('Kullanıcı Adı', 'ytu.ilanservisi@gmail.com', 'mail'),
	('Host', 'smtp.gmail.com', 'mail'),
	('Port', '587', 'mail');
