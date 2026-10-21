DROP TABLE IF EXISTS siparisler;
DROP TABLE IF EXISTS kayitlar;
DROP TABLE IF EXISTS ureticiler;
DROP TABLE IF EXISTS musteriler;
DROP TABLE IF EXISTS calisanlar;
DROP VIEW IF EXISTS view1;
DROP TABLE IF EXISTS bolumler;
DROP SEQUENCE IF EXISTS kayit_id_seq;
DROP SEQUENCE IF EXISTS siparis_id_seq;
DROP FUNCTION IF EXISTS uretici_toplam;
DROP TYPE uretici_zeytin_zeytinyagi;

CREATE TABLE ureticiler(
	uretici_id int NOT NULL PRIMARY KEY,
	uretici_isim varchar(255) NOT NULL,
	uretici_tel int,
	uretici_adres varchar(255),
	toplam_zeytin int DEFAULT 0,
	toplam_zeytinyagi int DEFAULT 0
);

CREATE TABLE bolumler(
	bolum_id int NOT NULL PRIMARY KEY,
	bolum_adi varchar(255),
	calisan_sayisi int DEFAULT 0
);

CREATE TABLE calisanlar(
	calisan_id int NOT NULL PRIMARY KEY,
	calisan_isim varchar(255) NOT NULL,
	calisan_tel int,
	calisan_adres varchar(255),
	calisan_bolum_no int,
	CONSTRAINT fk_bolum FOREIGN KEY(calisan_bolum_no) REFERENCES bolumler(bolum_id)
);

CREATE TABLE musteriler(
	musteri_id int NOT NULL PRIMARY KEY,
	musteri_isim varchar(255) NOT NULL,
	musteri_tel int,
	musteri_adres varchar(255),
	toplam_siparis int
);

CREATE TABLE kayitlar(
	kayit_id int NOT NULL PRIMARY KEY,
	uretici_no int NOT NULL,
	islem varchar(255),
	miktar int,
	tarih TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
	CONSTRAINT fk_uretici FOREIGN KEY(uretici_no) REFERENCES ureticiler(uretici_id),
	CONSTRAINT max_miktar CHECK(miktar<500)
);

CREATE TABLE siparisler(
	siparis_id int NOT NULL PRIMARY KEY,
	musteri_no int NOT NULL,
	miktar int,
	tarih TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
	CONSTRAINT fk_musteri FOREIGN KEY(musteri_no) REFERENCES musteriler(musteri_id),
	CONSTRAINT max_miktar CHECK(miktar<100)
);

-- Kayitlarin tutuldugu tabloda kayit numarasini otomatik olarak 1 arttiran sequence
CREATE SEQUENCE kayit_id_seq START 1 INCREMENT 1;

-- Siparislerin tutuldugu tabloda siparis numarasini otomatik olarak 1 arttiran sequence
CREATE SEQUENCE siparis_id_seq START 1 INCREMENT 1;


-- Yeni bir calisan eklendiginde, calisanin eklendigi bolumdeki toplam calisan sayisini
-- arttiran trigger
CREATE OR REPLACE FUNCTION yeni_calisan_fonk()
RETURNS TRIGGER AS'
BEGIN
	UPDATE bolumler SET calisan_sayisi=calisan_sayisi+1
	WHERE bolum_id = new.calisan_bolum_no;
	
	RETURN NEW;
END;
' LANGUAGE 'plpgsql';

CREATE TRIGGER yeni_calisan 
AFTER INSERT
ON calisanlar
FOR EACH ROW EXECUTE PROCEDURE yeni_calisan_fonk();


-- Yeni kayit eklendiginde kayit turune gore ureticinin toplam degerleri guncelleyen trigger
CREATE OR REPLACE FUNCTION yeni_kayit_fonk()
RETURNS TRIGGER AS $$
BEGIN
	IF new.islem LIKE '%getirdi%' THEN
		UPDATE ureticiler SET toplam_zeytin=toplam_zeytin+new.miktar  
		WHERE uretici_id=new.uretici_no	;
	ELSE
		UPDATE ureticiler SET toplam_zeytinyagi=toplam_zeytinyagi+new.miktar  
		WHERE uretici_id=new.uretici_no	;
	END IF;
RETURN NEW;
END;
$$ LANGUAGE 'plpgsql';

CREATE TRIGGER yeni_kayit
AFTER INSERT
ON kayitlar
FOR EACH ROW EXECUTE PROCEDURE yeni_kayit_fonk();


-- Yeni siparis eklendiginde musterinin toplam siparis miktarini guncelleyen trigger
CREATE OR REPLACE FUNCTION yeni_siparis_fonk()
RETURNS TRIGGER AS $$
BEGIN
	UPDATE musteriler SET toplam_siparis=toplam_siparis+new.miktar  
	WHERE musteri_id=new.musteri_no	;
RETURN NEW;
END;
$$ LANGUAGE 'plpgsql';

CREATE TRIGGER yeni_siparis
AFTER INSERT
ON siparisler
FOR EACH ROW EXECUTE PROCEDURE yeni_siparis_fonk();


--  ID si verilen bolumun calisan sayisini donduren fonksiyon
CREATE OR REPLACE FUNCTION bolum_calisan_sayisi(bolum_no int)
RETURNS int AS'
DECLARE
	toplam_calisan int;
BEGIN
	SELECT calisan_sayisi into toplam_calisan
	FROM bolumler
	WHERE bolum_id=bolum_no;
	
RETURN toplam_calisan;
END;
' LANGUAGE 'plpgsql';


-- IDsi verilen ureticinin Zeytin getirdigi toplam zeytin ve aldigi toplam zeytinyagi miktarini
-- yeni olusturulmus tur donduren fonksiyon
CREATE TYPE uretici_zeytin_zeytinyagi AS (top_zeytin int, top_zeytinyagi int);

CREATE OR REPLACE FUNCTION uretici_toplam(uretici_no int)
RETURNS uretici_zeytin_zeytinyagi AS'
DECLARE
	toplam uretici_zeytin_zeytinyagi;
BEGIN
	SELECT toplam_zeytin, toplam_zeytinyagi INTO toplam
	FROM ureticiler
	WHERE uretici_id=uretici_no;
RETURN toplam;
END;
' LANGUAGE 'plpgsql';


-- Verilen kilogram miktarindan fazla zeytin getiren uretciler
-- sayisini cursor ile bulan fonksiyon
CREATE OR REPLACE FUNCTION fazla_olan(x_miktar int)
RETURNS int AS'
DECLARE
	uretici_sayisi int;
	curs CURSOR FOR SELECT toplam_zeytin FROM ureticiler;
BEGIN
	uretici_sayisi = 0;
	FOR row in curs LOOP
		IF row.toplam_zeytin > x_miktar THEN
			uretici_sayisi = uretici_sayisi+1;
		END IF;
	END LOOP;
RETURN uretici_sayisi;
END;
' LANGUAGE 'plpgsql';


INSERT INTO bolumler VALUES (6,'Nakliyat', 0);
INSERT INTO bolumler VALUES (8,'Sınıflandırma', 0);
INSERT INTO bolumler VALUES (9,'Yıkama', 0);
INSERT INTO bolumler VALUES (4,'Salamura', 0);
INSERT INTO bolumler VALUES (10,'Fermantasyon', 0);
INSERT INTO bolumler VALUES (2,'Depolama', 0);
INSERT INTO bolumler VALUES (3,'Paketleme', 0);
INSERT INTO bolumler VALUES (1,'Sıkma', 0);
INSERT INTO bolumler VALUES (5,'Satış', 0);
INSERT INTO bolumler VALUES (7,'Tedarik', 0);
--
INSERT INTO calisanlar VALUES (9711,'Enes Köseoğlu',3435787,'Bayrampaşa',3);
INSERT INTO calisanlar VALUES (2684,'İsa Gül',2533300,'Güngören',2);
INSERT INTO calisanlar VALUES (9829,'Hakan Adiyaman',1852460,'Bahçelievler',8);
INSERT INTO calisanlar VALUES (7799,'Rahim Albayrak',6686642,'Pendik',1);
INSERT INTO calisanlar VALUES (6059,'Selin Yılmaz',9172843,'Esenler',5);
INSERT INTO calisanlar VALUES (4803,'Aleyna Türk',4450838,'Kadıköy',6);
INSERT INTO calisanlar VALUES (3150,'Muhammet Koç',4679283,'Şişli',9);
INSERT INTO calisanlar VALUES (7937,'Mert Deniz',5909140,'Bakırköy',7);
INSERT INTO calisanlar VALUES (3175,'Asya Yener',6062311,'Mecidiyeköy',4);
INSERT INTO calisanlar VALUES (7151,'Sena Ekiz',1369268,'Ümraniye',10);

INSERT INTO calisanlar VALUES (1001,'Abdullah Aslan',1329228,'Gebze',3);
INSERT INTO calisanlar VALUES (1002,'Merdi Korutürk',1341648,'Darıca',3);
INSERT INTO calisanlar VALUES (1032,'Ülfet Arsoy',1345678,'Beşiktaş',3);
INSERT INTO calisanlar VALUES (1052,'Özlem Dumanlı',1361138,'İçmeler',4);
INSERT INTO calisanlar VALUES (1042,'Bilgin Gülen',1361518,'Esenler',4);
INSERT INTO calisanlar VALUES (1190,'Nirgül Şama',1369878,'Üsküdar',4);
--
INSERT INTO ureticiler VALUES (2257,'Aycan Karabay',8160180,'Aydın',0,0);
INSERT INTO ureticiler VALUES (9092,'Mesut Yağcı',9225789,'İzmir',0,0);
INSERT INTO ureticiler VALUES (8470,'Evren Sezikli',1007500,'Balıkesir',0,0);
INSERT INTO ureticiler VALUES (6229,'Ayşe Kırbız',2154059,'Uşak',0,0);
INSERT INTO ureticiler VALUES (4538,'Sena Karatürk',8042053,'Muğla',0,0);
INSERT INTO ureticiler VALUES (2196,'Güral Dağaşan',3953201,'Çanakkale',0,0);
INSERT INTO ureticiler VALUES (5232,'Damla Şenel',9445967,'Bursa',0,0);
INSERT INTO ureticiler VALUES (4057,'Kemal Tosun',1250270,'Kütahya',0,0);
INSERT INTO ureticiler VALUES (6321,'Celal Tan',9462585,'Mersin',0,0);
INSERT INTO ureticiler VALUES (4444,'Müge Kısa',3468598,'Manisa',0,0);
--
INSERT INTO musteriler VALUES (5710,'Renan Salik',8244538,'Burdur',0);
INSERT INTO musteriler VALUES (9403,'Hatice Karataş',9554501,'Adıyaman',0);
INSERT INTO musteriler VALUES (4588,'Benan Üzen',8816331,'Çorum',0);
INSERT INTO musteriler VALUES (4657,'Feza Karaer',7303221,'Denizli',0);
INSERT INTO musteriler VALUES (5264,'Hayati Doğru',7580482,'Gümüşhane',0);
INSERT INTO musteriler VALUES (7516,'Mustafa Ürel',3165596,'Afyonkarahisar',0);
INSERT INTO musteriler VALUES (4937,'Hasibe Duysak',2206544,'Konya',0);
INSERT INTO musteriler VALUES (1573,'Ali Bağcı',5300194,'Malatya',0);
INSERT INTO musteriler VALUES (9201,'Veli Özdoğan',6736745,'Yalova',0);
INSERT INTO musteriler VALUES (4110,'Didem Çipe',5410904,'Mardin',0);
--
INSERT INTO kayitlar VALUES (nextval('kayit_id_seq'),2257,'Zeytin getirdi',100,'2023-01-16 12:50:25');
INSERT INTO kayitlar VALUES (nextval('kayit_id_seq'),9092,'Zeytin getirdi',250,'2023-01-12 13:22:35');
INSERT INTO kayitlar VALUES (nextval('kayit_id_seq'),8470,'Zeytin getirdi',300,'2023-01-06 14:20:15');
INSERT INTO kayitlar VALUES (nextval('kayit_id_seq'),6229,'Zeytin getirdi',125,'2023-01-01 17:32:12');
INSERT INTO kayitlar VALUES (nextval('kayit_id_seq'),4538,'Zeytin getirdi',400,'2023-01-05 21:18:44');
INSERT INTO kayitlar VALUES (nextval('kayit_id_seq'),2196,'Zeytin getirdi',200,'2023-01-14 22:37:43');
INSERT INTO kayitlar VALUES (nextval('kayit_id_seq'),5232,'Zeytin getirdi',450,'2023-01-07 20:41:30');
INSERT INTO kayitlar VALUES (nextval('kayit_id_seq'),4057,'Zeytin getirdi',225,'2023-01-09 19:07:55');
INSERT INTO kayitlar VALUES (nextval('kayit_id_seq'),6321,'Zeytin getirdi',150,'2023-01-10 09:17:26');
INSERT INTO kayitlar VALUES (nextval('kayit_id_seq'),4444,'Zeytin getirdi',325,'2023-01-02 10:04:22');
INSERT INTO kayitlar VALUES (nextval('kayit_id_seq'),5232,'Zeytin getirdi',150,'2023-01-10 09:17:26');
INSERT INTO kayitlar VALUES (nextval('kayit_id_seq'),6229,'Zeytin getirdi',325,'2023-01-02 10:04:22');
INSERT INTO kayitlar VALUES (nextval('kayit_id_seq'),4538,'Zeytinyağı götürdü',240,'2022-12-22 13:55:32');
INSERT INTO kayitlar VALUES (nextval('kayit_id_seq'),4538,'Zeytinyağı götürdü',325,'2022-03-02 15:12:21');
INSERT INTO kayitlar VALUES (nextval('kayit_id_seq'),4444,'Zeytin getirdi',180,'2022-01-16 11:42:33');
INSERT INTO kayitlar VALUES (nextval('kayit_id_seq'),4444,'Zeytinyağı götürdü',240,'2022-12-22 13:55:32');
INSERT INTO kayitlar VALUES (nextval('kayit_id_seq'),4444,'Zeytinyağı götürdü',325,'2022-04-09 13:19:42');
INSERT INTO kayitlar VALUES (nextval('kayit_id_seq'),4444,'Zeytinyağı götürdü',325,'2022-02-24 22:21:52');
INSERT INTO kayitlar VALUES (nextval('kayit_id_seq'),4444,'Zeytin getirdi',40,'2022-04-02 21:04:12');
--
INSERT INTO siparisler VALUES (nextval('siparis_id_seq'),5710,20,'2023-01-22 10:45:12');
INSERT INTO siparisler VALUES (nextval('siparis_id_seq'),9403,15,'2023-01-21 07:12:32');
INSERT INTO siparisler VALUES (nextval('siparis_id_seq'),4588,45,'2023-01-30 11:55:52');
INSERT INTO siparisler VALUES (nextval('siparis_id_seq'),4657,50,'2023-01-26 17:33:02');
INSERT INTO siparisler VALUES (nextval('siparis_id_seq'),5264,33,'2023-01-20 10:45:12');
INSERT INTO siparisler VALUES (nextval('siparis_id_seq'),7516,27,'2023-01-22 12:28:27');
INSERT INTO siparisler VALUES (nextval('siparis_id_seq'),4937,55,'2023-01-25 21:45:45');
INSERT INTO siparisler VALUES (nextval('siparis_id_seq'),1573,60,'2023-01-21 20:19:37');
INSERT INTO siparisler VALUES (nextval('siparis_id_seq'),9201,32,'2023-01-27 18:16:07');
INSERT INTO siparisler VALUES (nextval('siparis_id_seq'),4110,44,'2023-01-28 13:26:47');

INSERT INTO siparisler VALUES (nextval('siparis_id_seq'),4110,1,'2023-01-28 23:26:47');
INSERT INTO siparisler VALUES (nextval('siparis_id_seq'),4110,44,'2023-01-28 12:26:47');
INSERT INTO siparisler VALUES (nextval('siparis_id_seq'),4110,5,'2023-01-28 10:26:47');
INSERT INTO siparisler VALUES (nextval('siparis_id_seq'),4110,3,'2023-01-28 11:26:47');



