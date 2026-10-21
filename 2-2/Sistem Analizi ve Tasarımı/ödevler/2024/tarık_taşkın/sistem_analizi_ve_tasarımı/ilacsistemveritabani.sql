-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Anamakine: 127.0.0.1
-- Üretim Zamanı: 10 May 2024, 19:54:13
-- Sunucu sürümü: 10.4.32-MariaDB
-- PHP Sürümü: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Veritabanı: `ilacsistemveritabani`
--

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `adminler`
--

CREATE TABLE `adminler` (
  `username` text NOT NULL,
  `password` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_turkish_ci;

--
-- Tablo döküm verisi `adminler`
--

INSERT INTO `adminler` (`username`, `password`) VALUES
('admin', 'admin');

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `eczaneler`
--

CREATE TABLE `eczaneler` (
  `username` text NOT NULL,
  `password` text NOT NULL,
  `isim` text NOT NULL,
  `adres` text NOT NULL,
  `telefonno` text NOT NULL,
  `eczaneno` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_turkish_ci;

--
-- Tablo döküm verisi `eczaneler`
--

INSERT INTO `eczaneler` (`username`, `password`, `isim`, `adres`, `telefonno`, `eczaneno`) VALUES
('yesileczane1880', 'eczane1880', 'Yesil Eczane', 'Bağcılar-İstanbul', '02127678989', 1),
('çiçekeczane', '1234', 'Çiçek Eczane', 'Şişli-İstanbul', '02125556765', 2),
('mahmut', '123', 'Mahmut Eczane', 'İkitelli-İstanbul', '02123456230', 3),
('ismailytu', 'ismail123', 'İsmail Eczane', 'Kağıthane-İstanbul', '02124565758', 4),
('yildiz', '123', 'Yıldız Eczanesi', 'Güngören-İstanbul', '02125463275', 5),
('kanarya1907', '12345', 'Kanarya Eczane', 'Kadıköy-İstanbul', '02120986754', 6);

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `ilaclar`
--

CREATE TABLE `ilaclar` (
  `isim` text NOT NULL,
  `barkodno` int(11) NOT NULL,
  `tur` text NOT NULL,
  `fiyat` int(11) NOT NULL,
  `adet` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_turkish_ci;

--
-- Tablo döküm verisi `ilaclar`
--

INSERT INTO `ilaclar` (`isim`, `barkodno`, `tur`, `fiyat`, `adet`) VALUES
('Parol', 1, 'Ağrı Kesici', 40, 294),
('Muscoflex', 2, 'Ağrı Kesici', 50, 224),
('İbuprofen', 3, 'Ateş Düşürücü', 30, 168),
('Betanorm Tablet', 6, 'Hormon Dengeleyici', 32, 149),
('Parasetamol', 7, 'Ateş Düşürücü', 25, 279),
('Pharmaton 50 plus', 8, 'Vitamin & Takviye', 100, 397),
('Novomix Flexpen ', 9, 'Hormon Dengeleyici', 81, 129),
('EasyVit EasyFishoil', 10, 'Balık Yağı & Takviye', 334, 391),
('Flebogamma', 12, 'İmmun Sistem', 50, 190),
('Cordarone Tablet', 14, 'Kalp & Damar', 120, 282),
('Fludex Sr Tablet', 15, 'Kalp & Damar', 89, 243),
('One Up D3+K2', 16, 'Vitamin', 170, 282),
('Domexi', 19, 'Vitamin', 45, 139),
('Nevparin Flk', 24, 'Kan', 120, 198),
('Protamin Hcl Amp', 25, 'Kan', 90, 198),
('Calpol', 26, 'Soğuk Algınlığı', 22, 70),
('Metsil Fort ', 27, 'Mide & Bağırsak', 37, 86),
('Zofran 4 mg', 28, 'Mide & Bağırsak', 48, 22),
('Zofran 8 mg', 29, 'Mide & Bağırsak', 85, 14),
('Molit Ampul', 30, 'Mide & Bağırsak', 21, 121),
('Roxin', 31, 'Antienfeksiyon', 64, 123),
('Danasin', 32, 'Hormon Dengeleyici', 99, 43),
('Rupafin', 33, 'Solunum', 146, 180),
('Suprax', 34, 'Antienfeksiyon', 222, 72),
('Pred Forte Damla', 35, 'Göz', 48, 129),
('Dermovate', 36, 'Merhem', 21, 256),
('Beklazon Losyon', 37, 'Deri', 38, 120),
('Acnelyse Krem', 38, 'Akne', 84, 17),
('Benexol B12', 39, 'Vitamin', 64, 24),
('Nurofen', 40, 'Soğuk Algınlığı', 33, 232);

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `siparisler`
--

CREATE TABLE `siparisler` (
  `eczaneismi` text NOT NULL,
  `eczaneno` int(11) NOT NULL,
  `siparisno` int(11) NOT NULL,
  `siparis` text NOT NULL,
  `tutar` text NOT NULL,
  `tamamlandi` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_turkish_ci;

--
-- Tablo döküm verisi `siparisler`
--

INSERT INTO `siparisler` (`eczaneismi`, `eczaneno`, `siparisno`, `siparis`, `tutar`, `tamamlandi`) VALUES
('Yıldız Eczanesi', 5, 1, 'EasyVit EasyFishoil,1,334,Cordarone Tablet,1,120,Parasetamol,1,25,', '479', '1'),
('Yesil Eczane', 1, 2, 'Novomix Flexpen ,1,81,Betanorm Tablet,2,64,Fludex Sr Tablet,3,267,Domexi,1,45,Parol,10,400,', '857', '1'),
('Yıldız Eczanesi', 5, 3, 'Allerset Dml,101,252500,Domexi,20,900,', '253400', '1'),
('Yıldız Eczanesi', 5, 4, 'Allerset Dml,25,62500,Domexi,9,405,', '62905', '1'),
('Yıldız Eczanesi', 5, 5, 'EasyVit EasyFishoil,1,334,Betanorm Tablet,1,32,Flebogamma,1,50,', '416', '1'),
('Yıldız Eczanesi', 5, 6, 'Pharmaton 50 plus,1,100,', '100', '1'),
('Yıldız Eczanesi', 5, 7, 'Flebogamma,1,50,', '50', '1'),
('Yıldız Eczanesi', 5, 8, 'Parol,1,40,Betanorm Tablet,33,1056,', '1096', '1'),
('Yıldız Eczanesi', 5, 9, 'Parasetamol,3,75,Flebogamma,1,50,', '125', '1'),
('Yesil Eczane', 1, 10, 'İbuprofen,7,210,Flebogamma,5,250,Parasetamol,15,375,', '835', '1'),
('Yıldız Eczanesi', 5, 11, 'Domexi,1,45,Flebogamma,1,50,', '95', '1'),
('Yıldız Eczanesi', 5, 12, 'Betanorm Tablet,3,96,Flebogamma,1,50,Muscoflex,3,150,', '296', '1'),
('Kanarya Eczane', 6, 13, 'İbuprofen,2,60,Parasetamol,3,75,Cordarone Tablet,4,480,Nevparin Flk,2,240,', '855', '1'),
('Yıldız Eczanesi', 5, 14, 'İbuprofen,12,360,EasyVit EasyFishoil,1,334,Domexi,1,45,', '739', '1'),
('Yıldız Eczanesi', 5, 15, 'Protamin Hcl Amp,12,1080,', '1080', '0'),
('Mahmut Eczane', 3, 16, 'Parol,5,200,Muscoflex,2,100,Cordarone Tablet,13,1560,Calpol,17,374,One Up D3+K2,11,1870,EasyVit EasyFishoil,5,1670,Betanorm Tablet,24,768,Novomix Flexpen ,11,891,', '7433', '0'),
('İsmail Eczane', 4, 17, 'Nurofen,3,99,Benexol B12,2,128,Beklazon Losyon,5,190,Acnelyse Krem,4,336,Pred Forte Damla,21,1008,One Up D3+K2,7,1190,Molit Ampul,23,483,Dermovate,11,231,', '3665', '0'),
('Yıldız Eczanesi', 5, 18, 'Pharmaton 50 plus,1,100,', '100', '1'),
('Yıldız Eczanesi', 5, 19, 'EasyVit EasyFishoil,1,334,', '334', '1'),
('Yıldız Eczanesi', 5, 20, 'Cordarone Tablet,1,120,Molit Ampul,1,21,', '141', '1');

--
-- Dökümü yapılmış tablolar için indeksler
--

--
-- Tablo için indeksler `eczaneler`
--
ALTER TABLE `eczaneler`
  ADD PRIMARY KEY (`eczaneno`);

--
-- Tablo için indeksler `ilaclar`
--
ALTER TABLE `ilaclar`
  ADD PRIMARY KEY (`barkodno`);

--
-- Tablo için indeksler `siparisler`
--
ALTER TABLE `siparisler`
  ADD PRIMARY KEY (`siparisno`);

--
-- Dökümü yapılmış tablolar için AUTO_INCREMENT değeri
--

--
-- Tablo için AUTO_INCREMENT değeri `eczaneler`
--
ALTER TABLE `eczaneler`
  MODIFY `eczaneno` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- Tablo için AUTO_INCREMENT değeri `ilaclar`
--
ALTER TABLE `ilaclar`
  MODIFY `barkodno` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=41;

--
-- Tablo için AUTO_INCREMENT değeri `siparisler`
--
ALTER TABLE `siparisler`
  MODIFY `siparisno` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=21;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
