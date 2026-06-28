# Ders 14 Çalışma Özeti

## Genel Konular

- Birliktelik kuralları devamı
  - Market sepeti analizinde sık öğe kümelerinin bulunması ve bu kümelerden kurallar üretilmesi üzerinde durulur.
  - Kural değerlendirmede support ve confidence yanında ek ölçütler kullanılabilir.
- Apriori mantığı
  - Sık olmayan bir öğe kümesinin üst kümeleri de sık olamaz ilkesine dayanır.
  - Bu ilke aday öğe kümesi sayısını azaltarak arama sürecini verimli hale getirir.
- Lift ve kural ilginçliği
  - Lift, X ve Y'nin birlikte görülmesinin bağımsız beklenene göre ne kadar güçlü olduğunu gösterir.
  - Yüksek confidence tek başına yeterli olmayabilir; yaygın sonuç öğeleri yanıltıcı kural üretir.
- Kuralların yorumlanması
  - Kurallar iş bilgisiyle birlikte değerlendirilmelidir.
  - Çok sayıda kural üretilebilir; bu nedenle eşik değerleri ve ilginçlik ölçütleri önemlidir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Confidence'ın tek başına yeterli olmaması
  - Sonuç öğesi zaten çok sık görülüyorsa yüksek confidence gerçek ilişki gücünü abartabilir.
- Apriori ilkesinin arama alanını azaltması
  - Tüm kombinasyonları denemek pahalıdır; sık olmayan kümelerin üst kümelerini elemek işlem maliyetini düşürür.

## Kısa Tekrar Notları

- Apriori sık öğe kümelerini aşamalı bulur.
- Sık olmayan kümenin üst kümesi de sık değildir.
- Lift, ilişkinin bağımsızlığa göre gücünü ölçer.
- Kurallar support, confidence ve ilginçlik ölçütleriyle birlikte değerlendirilmelidir.

## Detaylı Açıklamalar

- Derste birliktelik kuralları daha algoritmik açıdan ele alınır. Büyük işlem veri tabanlarında tüm olası öğe kombinasyonlarını saymak çok maliyetli olduğu için Apriori benzeri yöntemler aday sayısını azaltır.
- Apriori yaklaşımı, önce tek öğeli sık kümeleri bulur; sonra bunlardan iki öğeli, üç öğeli ve daha büyük aday kümeler üretir. Bir adayın alt kümelerinden biri sık değilse o adayın kendisinin de sık olamayacağı kabul edilir ve aramadan çıkarılır.
- Confidence kuralın koşullu güvenilirliğini gösterse de tek başına yanıltıcıdır. Çok yaygın bir ürün sonuç tarafında yer alıyorsa birçok öncül için yüksek confidence verebilir. Lift gibi ölçütler, ilişkinin rastlantısal veya doğal yaygınlıktan kaynaklanıp kaynaklanmadığını ayırt etmeye yardım eder.
- Birliktelik kurallarının çıktısı çoğu zaman çok sayıda kuraldır. Bu nedenle minimum support, minimum confidence ve lift gibi eşikler belirlenerek hem istatistiksel hem de pratik açıdan anlamlı kurallar seçilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
