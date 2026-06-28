# Ders 3 Çalışma Özeti

## Genel Konular

- Veri indirgeme
  - Veri indirgeme, veri kümesinin temsil gücünü koruyarak daha küçük veya daha yönetilebilir bir biçime dönüştürülmesidir.
  - Amaç işlem maliyetini azaltmak, gereksiz bilgiyi temizlemek ve modelin genelleme başarısını artırmaktır.
- Öz nitelik seçimi ve öz nitelik çıkarımı
  - Öz nitelik seçimi, mevcut değişkenler arasından en anlamlı olanları tutar.
  - Öz nitelik çıkarımı, mevcut değişkenlerden yeni ve daha temsil edici değişkenler üretir.
- Aykırı değer ve veri kalitesi ilişkisi
  - Aykırı değerlerin veri indirgeme ve modelleme üzerindeki etkisi tartışılır.
  - Aykırı değer analizi, veri setinin yapısını anlamanın parçası olarak değerlendirilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Boyut azaltmanın sadece hız kazandırmaması
  - Gereksiz veya zayıf değişkenlerin çıkarılması modelin daha anlaşılır ve daha sağlam hale gelmesini sağlar.
- Öz niteliklerin etkisinin ayrı ayrı değerlendirilmesi
  - Her değişkenin modele katkısı aynı değildir; ilgisiz değişkenler gürültü oluşturabilir.

## Kısa Tekrar Notları

- Veri indirgeme, bilgiyi koruyarak veri boyutunu azaltır.
- Öz nitelik seçimi mevcut değişkenler arasından seçim yapar.
- Öz nitelik çıkarımı yeni değişkenler üretir.
- Aykırı değer analizi veri kalitesinin parçasıdır.

## Detaylı Açıklamalar

- Derste veri indirgeme, veri madenciliği süreçlerinde hem performans hem de yorumlanabilirlik açısından önemli bir adım olarak ele alınır. Çok sayıda öz nitelik olduğunda algoritmalar daha yavaş çalışabilir, gereksiz değişkenler karar sınırlarını bozabilir ve modelin öğrenmesi zorlaşabilir.
- Öz nitelik seçimi ile öz nitelik çıkarımı arasındaki fark önemlidir. Seçim yöntemlerinde mevcut kolonlardan bazıları korunur; çıkarım yöntemlerinde ise veriyi daha iyi temsil eden yeni eksenler veya bileşenler elde edilir. Bu ayrım, PCA gibi yöntemlere geçiş için temel oluşturur.
- Aykırı değerler veri indirgeme sırasında dikkatli ele alınmalıdır. Nadir ama anlamlı davranışları temsil eden gözlemler yanlışlıkla çıkarılırsa model problem için kritik bilgiyi kaybedebilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
