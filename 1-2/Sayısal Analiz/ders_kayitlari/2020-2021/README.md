# Sayısal Analiz Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.

## Genel Bilgiler

- **Ders Adı:** Sayısal Analiz
- **Dersi Veren Akademisyen:** Ahmet Elbir
- **Dönem:** Bahar
- **Akademik Yıl:** 2020-2021

## Müfredat ve Belge Dizini

| Ders | Konu Başlığı | Markdown Kaynak | PDF |
|------|-------------|-----------------|-----|
| Ders 1 | Sayısal Analize Giriş, Algoritmanın Önemi | [ders_1.md](altyazi_ozetleri/ders_1.md) | [ders_1.pdf](ders_1.pdf) |
| Ders 2 | Ders Konu Planı, Uygulama Araçları | [ders_2.md](altyazi_ozetleri/ders_2.md) | [ders_2.pdf](ders_2.pdf) |
| Ders 3 | Hata Kavramları, Kayan Nokta Gösterimi | [ders_3.md](altyazi_ozetleri/ders_3.md) | [ders_3.pdf](ders_3.pdf) |
| Ders 4 | Hata Analizi, Taylor Serisi | [ders_4.md](altyazi_ozetleri/ders_4.md) | [ders_4.pdf](ders_4.pdf) |
| Ders 5 | Fonksiyon Modelleme, Veri Yapıları | [ders_5.md](altyazi_ozetleri/ders_5.md) | [ders_5.pdf](ders_5.pdf) |
| Ders 6 | Trigonometrik ve Üstel Fonksiyon Modelleme | [ders_6.md](altyazi_ozetleri/ders_6.md) | [ders_6.pdf](ders_6.pdf) |
| Ders 7 | Cholesky Yöntemi, LU Ayrıştırma | [ders_7.md](altyazi_ozetleri/ders_7.md) | [ders_7.pdf](ders_7.pdf) |
| Ders 9 | Sayısal Türev ve İntegral | [ders_9.md](altyazi_ozetleri/ders_9.md) | [ders_9.pdf](ders_9.pdf) |
| Ders 12 | Sonlu Farklar ve İnterpolasyona Giriş | [ders_12.md](altyazi_ozetleri/ders_12.md) | [ders_12.pdf](ders_12.pdf) |
| Ders 13 | Newton İnterpolasyonu, Proje Soruları | [ders_13.md](altyazi_ozetleri/ders_13.md) | [ders_13.pdf](ders_13.pdf) |
| Ders 14 | Regresyon, Dersin Genel Özeti | [ders_14.md](altyazi_ozetleri/ders_14.md) | [ders_14.pdf](ders_14.pdf) |

## Detaylı Özetler

### Ders 1 - Sayısal Analize Giriş, Algoritmanın Önemi

- **Genel Konular**
  - Sayısal analiz, matematiksel problemlerin sayısal yöntemlerle çözümüne odaklanan bir bilim dalıdır.
  - Dersin içeriği: eşitlik çözümü, sayısal integral, sayısal türev, interpolasyon, regresyon, matris işlemleri, sonlu farklar ve adi diferansiyel denklemlerin çözümü.
  - Algoritma bilgisi ezberlenerek öğrenilecek bir şey değildir; pratik ve kavramsal derinlik gerektirir.
- **Hocanın Vurguladığı Kısımlar**
  - Uzaktan eğitim avantaj ve dezavantajları; öğrencilerin kendi mesleki gelişimleri için en iyi şekilde kendilerini yetiştirmeleri gerekir.
  - Sinyal işleme, makine öğrenmesi ve veri madenciliği alanlarında çalışmalar yapılmaktadır.

### Ders 2 - Ders Konu Planı, Uygulama Araçları

- **Genel Konular**
  - Eşitliklerin çözümü: bisection, regula falsi, Newton-Raphson.
  - Sayısal integral ve türev, interpolasyon ve regresyon, matris işlemleri, sonlu farklar.
  - Python ve MedLab kullanımı; projeler için C programlama dili tercih edilmektedir.
- **Hocanın Vurguladığı Kısımlar**
  - Analitik çözüm mümkün olmayan durumlarda sayısal yöntemlerin gerekliliği vurgulandı.

### Ders 3 - Hata Kavramları, Kayan Nokta Gösterimi

- **Genel Konular**
  - Kesme hatası, bağ hatası, mutlak hata kavramları.
  - Normalize edilmiş kayan nokta (floating point) gösterimi ve anlamlı rakamlar.
  - Hassasiyet: bağ hatası ile ölçülür; mutlak hata tek başına yeterli değildir.
- **Hocanın Vurguladığı Kısımlar**
  - Hata analizinin tüm yöntemlerde karşımıza çıkacağı vurgulandı.
  - Bilgisayardaki scientific mod yeterlidir; ekstra hesap makinesi gerekmez.

### Ders 4 - Hata Analizi, Taylor Serisi

- **Genel Konular**
  - Sınav sorularının çözümü: mutlak hata formülü, normalize kayan nokta, hassasiyet karşılaştırması.
  - Taylor serisi açılımı: f(x) = Σ f⁽ⁿ⁾(x₀) / n! × (x - x₀)ⁿ.
  - Türevlerin alınmasıyla seri katsayıları belirlenir.
- **Hocanın Vurguladığı Kısımlar**
  - Quizlerin amacı: dersin canlılığını artırmak, pratiği güçlendirmek.

### Ders 5 - Fonksiyon Modelleme, Veri Yapıları

- **Genel Konular**
  - Polinom fonksiyonları: katsayı dizisi ile temsil; indis = derece.
  - x³ + 2x + 5 → [5, 2, 0, 1] biçiminde modelleme.
  - Kök bulma yöntemleri için fonksiyonun bilgisayarda temsili şarttır.
- **Hocanın Vurguladığı Kısımlar**
  - Karmaşık fonksiyonların modellenmesinde birden fazla terimin bir arada ele alınması gerektiği belirtildi.

### Ders 6 - Trigonometrik ve Üstel Fonksiyon Modelleme

- **Genel Konular**
  - Trigonometrik fonksiyonlar: kat sayı ve açı parametreleri dizide saklanır.
  - Üstel fonksiyonlar: a × bˣ biçiminde; kat sayı ve üs dizide tutulur.
  - Fonksiyon türü seçimi sonrası parametreler kullanıcıdan alınır.
- **Hocanın Vurguladığı Kısımlar**
  - Basitten başlayıp aşama aşama ilerlemek gerektiği vurgulandı.

### Ders 7 - Cholesky Yöntemi, LU Ayrıştırma

- **Genel Konular**
  - Cholesky: simetrik pozitif tanımlı matrisler için A = L × Lᵀ ayrıştırması.
  - LU ayrıştırması: A = L × U; Gauss eliminasyonu ile elde edilir.
  - Sınav hazırlığı: klasik usul, 4-5 soru, PDF zorunlu.
- **Hocanın Vurguladığı Kısımlar**
  - Cholesky'nin hangi durumlarda tercih edildiği; sınavda PDF formatı zorunluluğu.

### Ders 9 - Sayısal Türev ve İntegral

- **Genel Konular**
  - Sayısal türev: sonlu farklar ile türev approximations (ileri, geri, merkezi).
  - Sayısal integral: trapez, Simpson 1/3, Simpson 3/8 kuralı.
  - Global değişken kullanımı: dördüncü sınıfa kadar kullanılmamalıdır.
- **Hocanın Vurguladığı Kısımlar**
  - Sayısal türev ve integral konuları bu derste tamamlanacaktır.

### Ders 12 - Sonlu Farklar ve İnterpolasyona Giriş

- **Genel Konular**
  - h (fark aralığı): xₖ₊₁ - xₖ = h.
  - İleri ve geri fark operatörleri.
  - İnterpolasyon: ayrık noktalardan geçen fonksiyon üretme.
- **Hocanın Vurguladığı Kısımlar**
  - Sonlu farkların interpolasyon konusundaki önemi vurgulandı.

### Ders 13 - Newton İnterpolasyonu, Proje Soruları

- **Genel Konular**
  - Newton interpolasyonu: ileri fark tablosu ile polinom oluşturulması.
  - Simpson kuralı: 1/3 veya 3/8, herhangi biri tercih edilebilir.
  - Proje: tek C dosyasında, dinamik parça sayısı ile integral hesabı.
- **Hocanın Vurguladığı Kısımlar**
  - Tek C dosyası zorunluluğu: benzerlik kontrolü ve değerlendirme kolaylığı için.

### Ders 14 - Regresyon, Dersin Genel Özeti

- **Genel Konular**
  - Regresyon: minimum hata ile veri setine en iyi yaklaşımı sağlayan fonksiyon.
  - İnterpolasyondan farkı: noktaların üzerinden geçmek yerine en iyi yaklaşımı sağlaması.
  - Ekstrapolasyon: aralık dışında tahmin.
- **Hocanın Vurguladığı Kısımlar**
  - Büyük veri setlerinde interpolasyon yerine regresyon tercih edilir.

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.
