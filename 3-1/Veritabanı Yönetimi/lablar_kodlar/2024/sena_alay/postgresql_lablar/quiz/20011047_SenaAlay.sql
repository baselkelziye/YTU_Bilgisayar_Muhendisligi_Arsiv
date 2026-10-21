--BLM3041 Veritabanı Yönetimi 3.Quizi -- 04.01.2024 -- B GRUBU --- SÜRE: 70 dk + 5dk forma cevap yükleme
--Öğrenci No: 20011047
--Ad: Sena         Soyad: Alay

--SORULAR
--1)Proje isimlerini ve lokasyonlarını tutan bir record tanımlayınız. (10 puan)

CREATE TYPE proje_bilgisi AS (project_name VARCHAR(25), project_location VARCHAR(15));

--CREATE TYPE proje_bilgisi_type AS (project_name VARCHAR(25), project_location VARCHAR(15));



--2)2 ve 2'den fazla akrabası olan çalışanların adını, soyadını ve akraba sayısını listeleyen sorguyu yazınız. (15 puan)

--cevap1
SELECT E.FName AS ismi, E.LName AS Soyadi, COUNT(D.Dependent_Name) AS AkrabaSayısı
FROM Employee E
JOIN Dependent D ON E.SSN = D.ESSN
GROUP BY E.SSN, E.FName, E.LName
HAVING COUNT(D.Dependent_Name) >= 2;

--cevap2
SELECT E.FName, E.LName, COUNT(D.Dependent_Name) AS AkrabaSayısı
FROM employee E, dependent D
WHERE E.SSN = D.ESSN
GROUP BY E.SSN, E.FName, E.LName
HAVING COUNT(D.Dependent_Name) >= 2;

--cevap3
SELECT 
    E.FName, 
    E.LName, 
    (SELECT COUNT(*) FROM Dependent WHERE ESSN = E.SSN) AS AkrabaSayısı
FROM 
    Employee E
WHERE 
    (SELECT COUNT(*) FROM Dependent WHERE ESSN = E.SSN) >= 2;




--3)En küçük yaştaki kız çocuğuna sahip çalışanın adını ve soyadını listeleyen sorguyu yazınız. (20 puan)

SELECT E.FName AS adi, E.LName AS soyadi
FROM Employee E
JOIN Dependent D ON E.SSN = D.ESSN
WHERE D.Sex = 'F' AND D.BDate IN (
    SELECT MAX(BDate) 
    FROM Dependent 
    WHERE Sex = 'F'
)
LIMIT 1;


SELECT E.FName AS adi, E.LName AS soyadi
FROM Employee E, Dependent D
WHERE E.SSN = D.ESSN AND D.Sex = 'F' AND D.BDate IN (
    SELECT MAX(BDate) 
    FROM Dependent 
    WHERE Sex = 'F'
)
LIMIT 1;



--4)Proje numarası verilen bir projede çalışanların ortalama çalışma saati, verilen eşik değerinden büyükse bu çalışanların maaşlarına 3000 zam yapan PL/pgSQL fonksiyonunu yazınız. Yazdığınız fonksiyonu çağırınız. (20 puan)

CREATE OR REPLACE FUNCTION istenen_zami_yap(p_project_number project.pnumber%type, p_esik_deger NUMERIC)
RETURNS void AS $$
DECLARE
    v_ortalama_saat NUMERIC;
BEGIN
    -- Projede çalışanların ortalama çalışma saatini hesapla
    SELECT AVG(hours) INTO v_ortalama_saat
    FROM works_on
    WHERE pno = p_project_number;

    -- Ortalama saat, eşik değerinden büyükse maaşlara zam yap
    IF v_ortalama_saat > p_esik_deger THEN
        UPDATE employee
        SET salary = salary + 3000
        WHERE ssn IN (
            SELECT essn
            FROM works_on
            WHERE pno = p_project_number
        );
    END IF;
END;
$$ LANGUAGE plpgsql;

SELECT istenen_zami_yap('10', 40);
SELECT istenen_zami_yap('61', 42);
SELECT istenen_zami_yap('92', 30);
--silmek için
DROP FUNCTION istenen_zami_yap(project.pnumber%type, NUMERIC);





--5)Staj işlemlerini tamamlamak için stajyer alımı gerçekleştirilecektir. Staj yapacak kişinin doğum tarihinin 01.01.2000 ve 01.01.2003 tarihleri arasında olması gerekmektedir. 
--'employee' tablosuna ekleme yaparken tarih aralıklarını kontrol eden, tarih aralığı uymuyorsa uyarı mesajı yazdıran triggerı ve fonksiyonunu yazınız. Triggerın tetiklenmesini sağlayınız. (20 puan)

CREATE OR REPLACE FUNCTION trig_kontrol_stajyer_dogum_tarihi()
RETURNS TRIGGER AS $$
BEGIN
    -- Doğum tarihi kontrolü
    IF NEW.bdate < '2000-01-01'::DATE OR NEW.bdate > '2003-01-01'::DATE THEN
        RAISE EXCEPTION 'Stajyerin doğum tarihi 01.01.2000 ile 01.01.2003 tarihleri arasında olmalıdır. Verilen tarih: %', NEW.bdate;
		RETURN NULL;
    END IF;
    RETURN NEW;
END;
$$ LANGUAGE 'plpgsql';

CREATE TRIGGER trigger_stajyer_dogum_tarihi_kontrol
BEFORE INSERT ON employee
FOR EACH ROW EXECUTE FUNCTION trig_kontrol_stajyer_dogum_tarihi();

INSERT INTO employee VALUES 
  ('Neva','T','Alay','888635555','01-JUN-2018','450 Stone, Trabzon, TX','M',55000,null,null);
  
INSERT INTO employee VALUES 
  ('YEKTA','U','ALAY','888635555','01-JUN-2022','450 Stone, Trabzon, TX','M',55000,null,null);
  
INSERT INTO employee VALUES 
  ('Sena','E','Alay','888665555','30-JUN-2005','450 Stone, Houston, TX','M',55000,null,null);
  




--6)Bir projenin lokasyonunun değiştirilmesi sonrası eğer bu lokasyon departman lokasyonları arasında bulunmuyorsa 
--projenin bağlı olduğu departman numarası ile 'dept_locations' tablosuna ekleme yapılmasını sağlayan trigger ve fonksiyonunu yazınız. Tablodaki birden fazla değeri cursor kullanarak alınız.  (20 puan)

CREATE OR REPLACE FUNCTION update_dept_locations() 
RETURNS TRIGGER AS $$
DECLARE
    v_dnum integer;
    v_location_exists boolean;
    
	v_location_cursor CURSOR FOR SELECT dlocation FROM dept_locations WHERE dnumber = NEW.dnum;
	
BEGIN
    v_dnum := NEW.dnum;
    v_location_exists := FALSE;

    -- Cursor ile dept_locations'daki lokasyonları kontrol et
    FOR v_record IN v_location_cursor LOOP
        IF v_record.dlocation = NEW.plocation THEN
            v_location_exists := TRUE;
            EXIT;
        END IF;
    END LOOP;

    -- Yeni lokasyon dept_locations'da yoksa, ekle
    IF NOT v_location_exists THEN
        INSERT INTO dept_locations (dnumber, dlocation) VALUES (v_dnum, NEW.plocation);
    END IF;

    RETURN NEW;
END;
$$ LANGUAGE 'plpgsql';

CREATE TRIGGER trg_update_dept_locations
AFTER UPDATE OF plocation ON project
FOR EACH ROW EXECUTE FUNCTION update_dept_locations();

--TETİKLEMEK
UPDATE project SET plocation = 'NewLocation' WHERE pnumber = 1;
UPDATE project SET plocation = 'ProjEKontrol' WHERE pnumber = 61;

--SİLMEK
--DROP TRIGGER trg_update_dept_locations ON project 
--DROP FUNCTION update_dept_locations();