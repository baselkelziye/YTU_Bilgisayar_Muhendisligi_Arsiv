# Diferansiyel Denklemler için Optimizasyon Ödevi

Bu proje, Yıldız Teknik Üniversitesi Bilgisayar Mühendisliği Bölümü **BLM2642 Diferansiyel Denklemler** dersi kapsamında hazırlanmıştır.  
Projede, soru–cevap çiftlerini **“iyi” veya “kötü”** olarak sınıflandıran, regresyon temelli bir model geliştirilmiştir.

## 👤 Öğrenci Bilgileri
- **İsim:** İsmail Orhan  
- **Numara:** 23011081  
- **Mail:** ismail.orhan@std.yildiz.edu.tr  
- **Danışman:** Prof. Dr. Mehmet Fatih Amasyalı  

---

## 🧠 Kullanılan Modeller

| Görev | Model |
|-------|-------|
| Metin vektör temsili (embedding) | Turkish E5 Large |
| Soru-cevap üretimi | Turkish Gemma 9B T1 |
| Karşılaştırma (alternatif model) | `intfloat/multilingual-e5-large` |

---

## ⚙️ Optimizasyon Algoritmaları

Projede üç farklı optimizasyon algoritması karşılaştırılmıştır:

- **GD (Gradient Descent)** – Tüm veri kümesi üzerinden gradyan hesaplar.
- **SGD (Stochastic Gradient Descent)** – Her iterasyonda rastgele bir örnek seçer.
- **Adam** – Momentum ve uyarlanabilir öğrenme oranı kullanır.

Ayrıca ek olarak **AdaGrad** algoritması da incelenmiştir.

---

## 📊 Yapılan Deneyler

1. **Eğitim kümesi büyüklüğünün etkisi**  
   - 50 örnek → düşük genel başarı  
   - 250 örnek → performansta belirgin iyileşme

2. **Optimizasyon algoritmalarının karşılaştırılması**  
   - Zaman, iterasyon ve başarı kriterlerine göre değerlendirme  
   - Ağırlık güncellemeleri **T-SNE** ile görselleştirildi

3. **Farklı embedding modellerinin karşılaştırılması**  
   - Turkish E5 Large, çok dilli E5 modeline göre Türkçe anlam ayrımında daha başarılı bulunmuştur.

---

## 📈 Çıktılar

- Eğitim ve test başarı grafikleri  
- Ağırlık vektörlerinin T-SNE görselleştirmesi  
- Algoritmaların zaman ve iterasyon bazlı karşılaştırma tabloları  

---

## 🎥 Video Sunum

Projenin çalışma prensibi, yöntemler ve sonuçların anlatıldığı video sunumu YouTube’a yüklenmiştir:

[Diferansiyel Denklemler Optimizasyon Ödev - Video](https://www.youtube.com/watch?v=s9lxLIq8H8g)

---

## 📁 Proje Raporu

Detaylı rapor el yazısı notlarla desteklenmiştir.
[Proje Raporu](docs/regression_model_report.pdf)

---

## 📬 İletişim
Her türlü soru ve geri bildirim için:
📧 ismail.orhan@std.yildiz.edu.tr

---

## 🚀 Çalıştırma

Projeyi çalıştırmak için:

```bash
unzip Optimization_odev.zip
cd Optimization_odev
pip install -r requirements.txt   # gerekli kütüphaneler
python main.py                    # ana script
