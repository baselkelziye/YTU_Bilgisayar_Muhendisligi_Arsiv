# Ders 2 Çalışma Özeti

## Genel Konular

- Algoritma analizi
  - Bir algoritmanın başarımını ölçmek için donanım, programlama dili ve çalışma ortamından bağımsız matematiksel değerlendirme yapılması gerektiği anlatılır.
  - Temel işlem sayısı üzerinden büyüme fonksiyonu çıkarma yaklaşımı tanıtılır.
- Karmaşıklık ve büyüme oranı
  - Algoritmanın girdi boyutu arttıkça çalışma zamanının nasıl büyüdüğü incelenir.
  - Sabitler ve düşük dereceli terimlerden çok baskın büyüme davranışına odaklanılır.
- En iyi, ortalama ve en kötü durum
  - Analizde özellikle en kötü durumun güvenli bir üst sınır verdiği belirtilir.
  - Farklı girişlerin aynı algoritma için farklı işlem sayıları üretebileceği gösterilir.
- Öz yinelemeli algoritmalar
  - Rekürsif algoritmaların karmaşıklığını bulmak için yineleme denklemleri kurulabileceği açıklanır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Algoritma analizi deneysel süre ölçümünden farklıdır.
  - Amaç belirli bir bilgisayarda kaç saniye sürdüğünü değil, girdi büyüdükçe maliyetin nasıl davrandığını anlamaktır.
- Önemli işlem doğru seçilmelidir.
  - Karmaşıklık hesabı, algoritmanın maliyetini temsil eden işlemin kaç kez yapıldığını saymaya dayanır.
- Rekürsiyon analizinde fonksiyon kendi cinsinden ifade edilir.
  - Bu nedenle yineleme denklemi kurmadan rekürsif algoritmanın büyüme oranını sağlıklı görmek zordur.

## Kısa Tekrar Notları

- Karmaşıklık analizi girdi boyutuna göre yapılır.
- Big-O gösterimi büyümenin üst sınırını ifade eder.
- İç içe döngüler çoğunlukla çarpımsal maliyet üretir.
- Rekürsif fonksiyonlarda maliyet yineleme denklemiyle modellenir.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Bu derste algoritma analizinin temel amacı, farklı çözüm yollarını adil şekilde karşılaştırabilmektir. Bir programın gerçek çalışma süresi işlemci, derleyici, işletim sistemi ve kodlama ayrıntılarından etkilenir. Teorik analiz bu etkileri dışarıda bırakıp, algoritmanın girdi boyutuna bağlı olarak kaç temel işlem yaptığına odaklanır. Böylece doğrusal, logaritmik, karesel veya üstel büyüyen çözümler birbirinden ayrılır. Rekürsif algoritmalarda ise fonksiyonun daha küçük boyutlu aynı probleme yaptığı çağrılar maliyet hesabına dahil edilir; bu yapı yineleme denklemleriyle ifade edilir.
