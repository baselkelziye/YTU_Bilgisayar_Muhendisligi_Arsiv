# Ders 2 Çalışma Özeti

## Genel Konular

- Veri ön işleme
  - Veri madenciliğinde model başarısı, çoğu zaman kullanılan algoritmadan önce verinin kalitesine bağlıdır.
  - Eksik, hatalı, gürültülü veya ölçekleri farklı veriler modelin yanlış öğrenmesine neden olabilir.
- Veri temizleme ve dönüştürme
  - Eksik değerlerin ele alınması, aykırı değerlerin değerlendirilmesi ve tutarsız kayıtların düzeltilmesi temel ön işleme adımlarıdır.
  - Sayısal özelliklerin karşılaştırılabilir hale gelmesi için normalizasyon ve ölçekleme kullanılır.
- Aykırı değer kavramı
  - Aykırı değerler, genel dağılımdan belirgin biçimde sapan gözlemlerdir.
  - Her aykırı değer hata değildir; bazı problemlerde en kritik bilgi aykırı gözlemlerde bulunabilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ön işlemenin modelleme öncesi zorunlu oluşu
  - Kalitesiz veriyle kurulan model, algoritma güçlü olsa bile güvenilir sonuç üretmez.
- Aykırı değerlerin doğrudan silinmemesi
  - Aykırı gözlemin hata mı yoksa problem için anlamlı bir durum mu olduğu bağlama göre değerlendirilmelidir.

## Kısa Tekrar Notları

- Veri ön işleme, veri madenciliğinin temel aşamasıdır.
- Eksik değer, gürültü ve ölçek farklılıkları model başarısını etkiler.
- Normalizasyon, özellikleri ortak ölçeğe taşır.
- Aykırı değerler önce analiz edilmeli, sonra uygun işlem uygulanmalıdır.

## Detaylı Açıklamalar

- Derste veri ön işlemenin, ham veriyi algoritmaların kullanabileceği tutarlı bir forma dönüştürdüğü anlatılır. Gerçek veri kümeleri çoğunlukla eksik, hatalı veya farklı biçimlerde tutulmuş değerler içerir. Bu nedenle doğrudan algoritmaya verilen veri yanıltıcı sonuçlar doğurabilir.
- Normalizasyon, özellikle uzaklık temelli yöntemlerde önemlidir. Bir öz niteliğin değer aralığı diğerlerinden çok büyükse, uzaklık hesabını baskılayabilir. Bu durumda algoritma gerçekte daha önemli olan özellikleri görmezden gelebilir.
- Aykırı değerler hem hata kaynağı hem de bilgi kaynağı olabilir. Örneğin ölçüm hatası olan bir değer temizlenebilir; fakat dolandırıcılık, saldırı tespiti veya arıza analizi gibi problemlerde aykırı değerler asıl ilgilenilen sınıfı temsil edebilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
