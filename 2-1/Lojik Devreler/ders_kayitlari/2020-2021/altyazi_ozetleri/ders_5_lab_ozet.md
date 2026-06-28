# Ders 5 Lab Çalışma Özeti

## Genel Konular

- Kişiye özel lojik fonksiyon çıkarma
  - Sayısal değerlerden minterm kümesi oluşturulur.
  - Aynı minterm tekrar ederse farklı satır elde etmek için uygun düzeltme yapılır.
- Minterm ifadesi ve doğruluk tablosu
  - Fonksiyon `Σm(...)` biçiminde yazılır.
  - Doğruluk tablosu, minterm kümesinin doğru yorumlanıp yorumlanmadığını gösterir.
- Kapı türüne göre sade devre tasarımı
  - Seçilen kapı türü öğrenciye göre değişebilir.
  - Fonksiyonun sadeleştirilmiş hali, istenen kapı yapısına dönüştürülür.
- Simülasyon doğrulaması
  - Devre girişleri denenerek teorik doğruluk tablosuyla karşılaştırılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Tek sorunun birden fazla aşaması vardır.
  - Fonksiyon çıkarma, doğruluk tablosu, sadeleştirme ve devre gerçekleme birlikte değerlendirilir.
- Kapı seçimi ve minterm çıkarımı karıştırılmamalıdır.
  - Minterm belirleme farklı mod işlemine, kapı seçimi farklı mod işlemine dayanabilir.
- Programda devre çalışır halde gösterilmelidir.
  - Statik ekran görüntüsü yerine giriş-çıkış davranışı kontrol edilmelidir.

## Kısa Tekrar Notları

- Minterm kümesi fonksiyonun `1` olduğu satırları verir.
- Tekrarlı minterm varsa fonksiyon satırları farklılaştırılır.
- Doğruluk tablosu tasarımın referansıdır.
- Sadeleştirilmiş fonksiyon seçilen kapı türüyle kurulmalıdır.

## Detaylı Açıklamalar

- Laboratuvar çalışması, öğrencinin kendi fonksiyonunu üretip uçtan uca devreye dönüştürmesini hedefler. Sayısal işlemlerle bulunan minterm değerleri önce fonksiyon biçiminde yazılır. Sonra bu fonksiyona karşılık gelen doğruluk tablosu oluşturulur.
- Fonksiyon sadeleştirildikten sonra kullanılacak kapı türüne uygun dönüşüm yapılır. Örneğin yalnızca NOR veya NAND türü kapılarla gerçekleme isteniyorsa De Morgan kuralları kullanılır ve gerekli tümleyenler kapı girişleri birleştirilerek elde edilir.
- Simülasyon doğrulaması, teorik çözüm ile devre davranışı arasındaki bağı kurar. Giriş kombinasyonları sırayla denenir ve çıkış değerlerinin doğruluk tablosundaki değerlerle uyumlu olması beklenir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
