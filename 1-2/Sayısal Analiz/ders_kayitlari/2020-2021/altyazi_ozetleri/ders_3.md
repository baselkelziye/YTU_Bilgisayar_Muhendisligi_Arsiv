# Ders 3 Çalışma Özeti

## Genel Konular

- Hata kavramları ve türleri
  - Kesme hatası (truncation error): xửzhendislik hesaplamalarında kullanılan yaklaşık değerlerden kaynaklanan hata.
  - Bağl hatası (relative error): mutlak hatanın gerçek değere oranıdır.
  - Mutlak hata: beklenen değer ile elde edilen değer arasındaki farktır.
- Ondalık nokta ve anlamlı rakamlar (significant figures)
  - Normalize edilmiş kayan nokta (floating point) gösterimi: birgülden sonra bir anlamlı basamak gelecek şekilde ifade edilir.
  - Anlamlı basamak sayısı, bir sayının hassasiyetini belirler.
- Hassasiyet kavramı
  - Farklı ölçüm araçlarının aynı hata oranına sahip olabileceği; mutlak hata ile bağ hatası arasındaki farkın anlaşılması gerekir.
  - Örneğin 100 kg ile tartılan bir cisimde 100 kg hata, 0.01 gram ile tartılan bir cisimde 5 gram hata olabilir; her iki durumda da bağ hatası %0.2 olarak aynıdır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Hata analizinin tüm yöntemlerde karşımıza çıkacağı vurgulandı.
- Quiz uygulaması ile dersteki konuların pratiği yapıldı.
- Hesap makinesi kullanımı: bilgisayardaki scientific mod yeterlidir, ekstra bir hesap makinesi almasına gerek yoktur.

## Kısa Tekrar Notları

- Mutlak hata = |gerçek değer - gözlenen değer|
- Bağl hatası = |gerçek değer - gözlenen değer| / |gerçek değer|
- Normalize edilmiş kayan nokta: birgülden sonra bir anlamlı basamak gelecek şekilde ifade.
- Hassasiyet: bağ hatası ile ölçülür; mutlak hata tek başına yeterli değildir.

## Detaylı Açıklamalar

Hata analizi, sayısal analizin temel taşlarından biridir. Bir hesaplamanın ne kadar güvenilir olduğunu anlamak için hata türlerinin bilinmesi gerekir. Kesme hatası,处理me sürecinde oluşturulan yaklaşık modellerden kaynaklanır. Örneğin Taylor serisinin belirli bir terimde kesilmesi kesme hatası üretir.

Bağl hatası, hatanın büyüklüğünü gerçek değere göre orantılamanızı sağlar. Bu sayede farklı ölçeklerdeki ölçümlerin hassasiyeti karşılaştırılabilir. Örneğin 100 kg ile tartımda 100 kg hata ile 0.01 gram ile tartımda 5 gram hata, her ikisi de %0.2 bağ hatası verir.

Kayan nokta gösterimi, bilgisayarda reel sayıların saklanma biçimidir. Normalize edilmiş formatta, birgülden sonra bir anlamlı basamak yer alır ve kalan basamaklar exponent (üs) ile ifade edilir. Bu gösterim sayesinde hem büyük hem de küçük sayılar aynı formatta işlenebilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
