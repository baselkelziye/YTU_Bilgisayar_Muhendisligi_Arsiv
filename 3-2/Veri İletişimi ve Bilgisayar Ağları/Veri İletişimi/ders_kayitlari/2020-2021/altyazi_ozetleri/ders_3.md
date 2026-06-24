# Ders 3 Çalışma Özeti

## Genel Konular

- Multiplexing
  - Birden fazla veri akışının aynı iletim ortamını paylaşmasını sağlar.
  - Amaç, pahalı ya da sınırlı fiziksel hattı daha verimli kullanmaktır.
- Frekans, zaman ve dalga boyu bölmeli çoğullama
  - FDM'de her iletişim farklı frekans bandına yerleştirilir.
  - TDM'de kullanıcılar aynı ortamı farklı zaman dilimlerinde kullanır.
  - WDM, fiber optik sistemlerde farklı dalga boylarını ayırarak birden çok akışı taşır.
- Hata tespiti ve hata düzeltme
  - Veri bağı katmanı, gönderilen veride bozulma olup olmadığını anlamak için ek kontrol bilgileri kullanır.
  - Hata tespiti, hatanın varlığını fark etmeye; hata düzeltme ise mümkünse bozulan kısmı belirleyip düzeltmeye yöneliktir.
- Parity ve checksum
  - Parity biti, bir veri grubundaki 1 sayısının tek veya çift olmasına göre basit kontrol sağlar.
  - Checksum, veri parçalarından hesaplanan özet değerin alıcıda tekrar hesaplanması mantığına dayanır.
- CRC ve Hamming yaklaşımı
  - CRC polinom bölme mantığıyla güçlü hata tespiti sağlar.
  - Hamming kodu, belirli koşullarda hatanın yerini bulup düzeltmeye yarayan ek bitler kullanır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Multiplexing, aynı ortamın paylaştırılması problemine verilen temel cevaptır.
  - Farklı akışları ayırmak için frekans, zaman veya dalga boyu ekseni kullanılabilir.
- Hata kontrolü veri iletişiminin vazgeçilmez parçasıdır.
  - Fiziksel ortamda gürültü olduğu için alıcı tarafın veriyi körlemesine doğru kabul etmesi beklenmez.
- Basit hata kontrol yöntemleri sınırlıdır.
  - Parity kolaydır ama her hata örüntüsünü yakalayamaz; CRC daha güçlü bir tespit yaklaşımıdır.

## Kısa Tekrar Notları

- Multiplexing, aynı hattı birden fazla akışa kullandırır.
- FDM frekansı, TDM zamanı, WDM dalga boyunu böler.
- Hata tespiti hatayı fark eder; hata düzeltme hatayı gidermeye çalışır.
- Parity basit ama zayıf bir kontroldür.
- CRC güçlü hata tespiti için kullanılır.

## Detaylı Açıklamalar

Bu derste paralel ve seri iletimden sonra aynı fiziksel ortamın birden fazla iletişim için nasıl kullanılacağı incelenmiştir. Multiplexing, ağlarda kapasite kullanımını artırır. FDM yaklaşımında her iletişim farklı frekans aralığında taşınır; bu yüzden frekans bantlarının birbirine karışmaması gerekir. TDM'de kullanıcılar sırayla zaman dilimleri alır. WDM ise fiber optikte farklı ışık dalga boylarını kullanarak yüksek kapasite elde eder.

Hata kontrolü konusu veri bağı katmanının temel görevlerinden biridir. Gönderici, verinin yanında kontrol bilgileri de yollar. Alıcı aynı kontrolü yeniden hesaplayarak bozulma olup olmadığını anlar. Parity biti tek bitlik basit kontrol sağlar, ancak bazı çoklu hataları kaçırabilir. Checksum daha geniş bloklar için özet üretir. CRC ise polinom tabanlı yapısıyla yaygın ve güçlü bir hata tespit yöntemidir.

Hamming kodu gibi yöntemler sadece hatayı tespit etmeyi değil, hatanın konumunu belirleyip düzeltmeyi de hedefler. Bunun için veri bitleri arasına kontrol bitleri yerleştirilir. Ek bit maliyeti vardır, fakat yeniden iletim maliyetinin yüksek olduğu yerlerde bu yaklaşım anlamlı hale gelir.
