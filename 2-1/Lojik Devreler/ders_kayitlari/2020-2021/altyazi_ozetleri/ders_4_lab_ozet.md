# Ders 4 Lab Çalışma Özeti

## Genel Konular

- Minterm tabanlı fonksiyon oluşturma
  - Öğrenciye verilen sayısal değerlere göre minterm numaraları belirlenir.
  - Mintermler doğruluk tablosunda fonksiyonun `1` olduğu satırları gösterir.
- Doğruluk tablosu hazırlama
  - Üç girişli bir fonksiyonda tüm `x, y, z` kombinasyonları yazılır.
  - Seçilen mintermlere karşılık gelen satırlarda çıkış `1`, diğerlerinde `0` olur.
- Kapı türüne göre gerçekleme
  - Fonksiyon sadeleştirildikten sonra istenen kapı türüyle devre kurulmalıdır.
  - OR, AND, NOR gibi kapılar ve gerekli NOT kapıları kullanılarak eşdeğer devre elde edilir.
- Simülasyonla doğrulama
  - Kurulan devre, doğruluk tablosuyla karşılaştırılarak kontrol edilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Devre sadeleştirilmiş ifadeye göre kurulmalıdır.
  - Gereksiz uzun kanonik ifade doğrudan çizilmek yerine önce sadeleştirme yapılmalıdır.
- Çözümde minterm ifadesi, doğruluk tablosu ve seçilen kapı türü açık olmalıdır.
  - Devre çizimi tek başına yeterli değildir; hangi fonksiyonun gerçekleştirildiği gösterilmelidir.
- Simülasyonda yalnızca şekil değil, çalışan devre ve çıkış kontrolü önemlidir.

## Kısa Tekrar Notları

- Minterm numarası ikili giriş kombinasyonunu temsil eder.
- Fonksiyonun `1` olduğu satırlar minterm toplamı ile yazılır.
- Sadeleştirme devre maliyetini düşürür.
- Doğruluk tablosu ile simülasyon sonucu aynı olmalıdır.

## Detaylı Açıklamalar

- Laboratuvar içeriği, teoride öğrenilen minterm, doğruluk tablosu ve kapı gerçekleme ilişkisini uygulamaya taşır. Önce fonksiyonun hangi giriş kombinasyonlarında `1` verdiği belirlenir. Ardından bu fonksiyon açık minterm toplamı olarak yazılır.
- Sonraki adım, fonksiyonu Boolean cebri veya Karnaugh haritası ile sadeleştirmektir. Sadeleşmiş ifade hangi kapılarla kurulacaksa ona uygun dönüşümler yapılır. Örneğin yalnızca belirli bir kapı türü kullanılacaksa De Morgan dönüşümleri ve NOT elde etme yöntemleri devre tasarımında kullanılır.
- Simülasyon programında girişler değiştirilerek çıkışın doğruluk tablosuyla uyuşup uyuşmadığı gözlenir. Bu adım, cebirsel çözümün devre düzeyinde doğru çalıştığını doğrular.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
