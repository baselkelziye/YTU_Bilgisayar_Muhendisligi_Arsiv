# Ders 4 Çalışma Özeti

## Genel Konular

- Temel bileşen analizi
  - PCA, çok boyutlu veriyi daha az sayıda yeni eksene yansıtarak boyut azaltma yapan bir yöntemdir.
  - Yeni eksenler, verideki varyansı en iyi temsil edecek şekilde oluşturulan temel bileşenlerdir.
- Öz nitelik çıkarımı
  - PCA mevcut öz nitelikleri doğrudan seçmez; bunların doğrusal bileşimlerinden yeni bileşenler üretir.
  - Bu nedenle feature composition veya feature extraction yaklaşımıdır.
- Varyans ve bileşen seçimi
  - İlk temel bileşen en yüksek varyansı, sonraki bileşenler kalan varyansı açıklayacak şekilde sıralanır.
  - Kaç bileşen kullanılacağı, açıklanan toplam varyans oranına göre belirlenir.

## Hocanın Özellikle Vurguladığı Kısımlar

- PCA'nın öz nitelik seçimi değil öz nitelik üretimi olduğu
  - Yöntem eski değişkenleri atıp bazılarını tutmaz; yeni koordinat sistemi üretir.
- Bileşen sayısına dikkat edilmesi
  - Çok az bileşen bilgi kaybına, çok fazla bileşen ise indirgeme amacının zayıflamasına yol açar.

## Kısa Tekrar Notları

- PCA boyut azaltma ve öz nitelik çıkarımı yöntemidir.
- Temel bileşenler varyansı maksimum açıklayacak şekilde sıralanır.
- Yeni bileşenler eski değişkenlerin doğrusal kombinasyonudur.
- Bileşen sayısı açıklanan varyansa göre seçilir.

## Detaylı Açıklamalar

- Derste PCA'nın amacı, yüksek boyutlu veri kümesini daha az boyutlu ama temsil gücü yüksek bir uzaya taşımak olarak açıklanır. Bu yöntem özellikle birbirleriyle ilişkili öz niteliklerin bulunduğu veri kümelerinde işe yarar.
- PCA'da veri yeni eksenlere projekte edilir. Bu eksenler birbirine diktir ve her biri verideki farklı bir varyans yönünü temsil eder. İlk bileşen en fazla varyansı taşıdığı için en bilgilendirici eksen kabul edilir.
- PCA sonucunda elde edilen bileşenler modelleme öncesinde kullanılabilir. Böylece gürültü azalabilir, işlem maliyeti düşebilir ve görselleştirme kolaylaşabilir. Ancak bileşenler orijinal değişkenler kadar doğrudan yorumlanabilir olmayabilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
