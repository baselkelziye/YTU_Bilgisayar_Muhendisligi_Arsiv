# 🌡️ Isı Kontrollü Fan Sistemi

Bu proje, ortam sıcaklığı belirli bir seviyenin üzerine çıktığında fanı otomatik olarak çalıştıran temel bir elektronik devredir. Proje tamamen analog/dijital bileşenlerle gerçekleştirilmiş, mikrodenetleyici (Arduino, vb.) kullanılmamıştır.

---

## 🧰 Kullanılan Malzemeler

| Bileşen            | Açıklama                           |
|--------------------|------------------------------------|
| NTC Termistör      | Sıcaklık algılayıcı                |
| NPN Transistör     | Anahtarlama için (BC547)    |
| Dirençler          | Voltaj bölücü ve bias ayarları     |
| 9V Fan             | Devre çalıştığını göstermek için  |
| Güç Kaynağı        | 9V DC (adaptör veya batarya)       |
| Breadboard ve Kablolar | Devre kurulumu için             |

---

## ⚙️ Nasıl Çalışır?
1. Ortam sıcaklığı sensör tarafından ölçülür.
2. Eşik sıcaklık değeri geçildiğinde transistör tetiklenir.
3. Transistör üzerinden fan çalışmaya başlar.
4. Sıcaklık düşerse fan otomatik olarak kapanır.


---

## 🖼️ Görseller

| Açıklama                                 | Dosya Adı                            |
|------------------------------------------|--------------------------------------|
| Falstad ile oluşturulan devre şeması     | `images/falstad.jpg`           |
| Tinkercad ile oluşturulan devre şeması   | `images/tinkercad.jpg`         |
| Fiziksel devre kurulumu (breadboard)     | `images/fiziksel_devre.jpg`          |


---

## 📎 Belgeler

| Belge                          | Açıklama                           |
|--------------------------------|------------------------------------|
| [`docs/circuit_diagram.pdf`](docs/circuit_diagram.pdf) | Devrenin genel şematik çizimi (Falstad ve çizim olarak) |
| [`docs/proje_aciklamasi.pdf`](docs/proje_aciklamasi.pdf) | Proje raporu, çalışma prensibi vb. |

---

## 👥 Katkıda Bulunanlar

- **İsmail Orhan, Yunus Emre Tokmakçı ve Metehan Özyürek** – Yıldız Teknik Üniversitesi, Bilgisayar Mühendisliği 1.sınıf
- Öğrenci Numarası: 23011081
- E-posta: ismail.orhan@std.yildiz.edu.tr 📧

> Bu proje, temel elektronik bilgilerini pekiştirmek amacıyla bir grup çalışması olarak gerçekleştirilmiştir.

---
