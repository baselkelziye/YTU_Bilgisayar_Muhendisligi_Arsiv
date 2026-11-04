# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin tanıtımı: kaynaklar, değerlendirme, ödev kuralları.
- Yapay zeka (artificial intelligence) ve makine öğrenmesi (machine learning) neden gerekli?
- Kural tabanlı sistemlerle öğrenen sistemlerin farkı (kredi kartı sahtekarlığı örneği).
- Makine öğrenmesinin yapay zeka, veri madenciliği (data mining), veri bilimi (data science), büyük veri (big data) ve derin öğrenme (deep learning) ile ilişkisi.
- Üç temel öğrenme türü: eğitmenli (supervised), eğitmensiz (unsupervised), pekiştirmeli / ödül-ceza ile öğrenme (reinforcement learning). Ara tür: yarı eğitmenli (semi-supervised) öğrenme.
- Bir öğrenme sisteminin ana adımları: problem analizi, veri toplama, ön işleme, özellik seçimi, model kurma, model seçimi ve değerlendirme.
- Veri bölme: eğitim (training), doğrulama (validation), test.
- Veri toplama sorunları: eksik veri, dengesiz sınıf dağılımı, veri çeşitliliği, sahte veri üretimi.
- Veri tipleri: kullanılmayan (useless), sıralı (ordinal), kategorik (nominal).
- Normalizasyon: min-max ve Z-skor (standartlaştırma).
- Varsayımlar, özellik vektörü, model seçimi ve hata ölçütünün seçimi.
- Derin öğrenmenin tarihçesi ve klasik yöntemlerle karşılaştırması.

## Hocanın Özellikle Vurguladığı Kısımlar

- **Değerlendirme:** 3 ödev %50, 1 yıl içi yazılı sınav %20, 1 dönem sonu projesi %30.
- **Kopya kuralı:** Fikir alışverişi serbest. İnternetteki kaynaklara ya da başka bir öğrencinin ödevine belli oranın üzerinde benzeyen ödev/proje **0** alır.
- **Geç teslim:** Teslim tarihinden sonraki her gün için 10 puan kesilir.
- Ödevler Python ile (istenirse C ile) yazılacak. Derste uygulama (kod) gösterilmeyecek; uygulama ödevlerde yapılacak.
- Lisansüstü öğrencinin hedefi dersi geçmek değil öğrenmek olmalı.
- Tek bir model kurup "performans %5 arttı" demek yetmez. Olası tüm modeller denenmeli. En uygun model ve onun en uygun parametreleri (ör. k-NN için $k=3$ mü $5$ mi) performans analiziyle seçilmeli.
- Veri toplanabileceğinden emin olmadan bir makine öğrenmesi projesine başlanmamalı.
- Başarı **asla** eğitim verisiyle ölçülmez. Model doğrulama verisiyle seçilir, son başarı test verisiyle ölçülür.
- Eğitim başarısı doğrulama başarısından belirgin yüksekse model ezberlemiş (overfitting) olabilir.
- Sistemler başıboş bırakılmamalı. Önce bir prototip üzerinde etiketi bilinen veriyle başarı ölçülmeli.
- Özellikler sınıf içi benzerliği artırmalı, sınıflar arası benzerliği azaltmalı. Ne az ne gereğinden fazla özellik kullanılmalı.
- Klasik makine öğrenmesi yöntemleri aynı başarıyı veriyorsa derin öğrenmeye gerek yok. Derin öğrenmenin eğitimi günler, haftalar sürebilir.
- Dengesiz veride çok örnekli sınıfı kademe kademe azaltarak farklı modeller kurulmalı. En iyi oran deneyle bulunmalı.
- Hata ölçütü probleme göre seçilir. Hastalık teşhisinde hasta olanları kaçırmamak (yüksek doğru pozitif) daha önemlidir.
- Derse canlı katılım ve soru sorma isteniyor. Bir sonraki derste ilk 10-15 dakika kameralar açık tanışma yapılacak.

## Kısa Tekrar Notları

- **Makine öğrenmesi:** Program yazmadan sistemin verilen girişler için istenen çıkışı elde etmesini sağlamak. Arthur Samuel (1959): "bilgisayarı açıkça programlamadan öğrenme yeteneği kazandırmak".
- **Makine öğrenmesi**, yapay zekanın problemi öğrenme ile çözen alt alanıdır.
- **Derin öğrenme**, makine öğrenmesinin büyük veri ile çok katmanlı yapay sinir ağları kullanan alt alanıdır.
- **Eğitmenli öğrenme:** Giriş $x$ ve çıkış $y$ etiketli verilir. Sistem $x$'ten $y$'ye eşlemeyi öğrenir.
- **Eğitmensiz öğrenme:** Etiket yok. Sistem örnekleri benzerliklerine göre gruplar (kümeleme, clustering).
- **Yarı eğitmenli öğrenme:** Az sayıda etiketli, çok sayıda etiketsiz veri. Etiketli veri kümelemenin başarısını artırır.
- **Pekiştirmeli öğrenme:** Yalnız ödüller (pozitif puan) ve cezalar (negatif puan) ile hedef tanımlanır. Sistem doğru davranışı kendi bulur.
- **Çıkış türü:** Sınıf (ör. sahte / normal) ya da sürekli değer (ör. ev fiyatı tahmini, regresyon).
- **Veri bölme:** eğitim, doğrulama, test.
- **Eksik veri:** Örnek çoksa eksik kayıtlar atılır. Azsa benzer örneklerde en sık görülen değerle doldurulur.
- **Ordinal veri:** Aralarında ölçülebilir ilişki olan sayısal değerler (yaş, kilo).
- **Nominal veri:** Kategorik değerler, aralarında ölçüm yapılamaz (şehir, işlem kanalı, plaka kodu).
- **Min-max normalizasyonu:** Değerleri $[0,1]$ aralığına çeker.
- **Z-skor standartlaştırması:** Ortalama çıkarılıp standart sapmaya bölünür. Gauss dağılımlı veride önerilir.

## Detaylı Açıklamalar

### Zeka ve Yapay Zeka

- İnsan zekası: düşünme, akıl yürütme, nesnel gerçekleri algılama, kavrama, yargılama, sonuç çıkarma yeteneklerinin tümü.
- Günlük örnekler: konuşulanı anlayıp cevap verme, yabancı dilde iletişim, satranç oynama, araba kullanırken engellere çarpmama.
- Yapay zekanın amacı: olaylar karşısında insan gibi düşünen, öğrenen ve davranan sistemlerle problem çözmek.
- 1940'lardan beri yapay zeka çalışması var. Başta öğrenmesi olmayan kural tabanlı sistemler kullanıldı.
  - Örnek: parmak izi tanımada çizgilerin başlangıç, bitiş ve çatallanma noktaları kaydedilip yeni izle karşılaştırılıyordu. Burada öğrenme yok, yalnız sabit işlem adımları var.
- Bu sistemler yetersiz kalınca öğrenme özelliği gerekti. İnsan ezberleyerek değil öğrenerek yeni problemleri çözebiliyor.

### Kural Tabanlı Sistemin Sınırı: Kredi Kartı Sahtekarlığı

- Bir bankanın kural tabanlı yazılımındaki kurallar:
  - Günlük harcama belli bir tutarın (ör. 1500-2000 TL) üzerindeyse alarm.
  - Aynı gün 3 farklı ülkede harcama varsa alarm.
- Sorunlar:
  - Her kural her kişi için geçerli değil. Bir öğrenci günde 40 TL harcar, bir iş insanı 5000 TL harcayabilir.
  - Aktarmalı uçuşla aynı gün 3 ülkede harcama yapmak mümkün.
  - Hocanın anlattığı olay: Kuralı yazan yazılımcının kartı, İtalya'dan başka bir ülkeye geçtiği gün bu kural yüzünden kapanmış.
- Çözüm: Normal ve sahte işlem örnekleri toplanır. Sistem karakteristik özellikleri bu örneklerden kendisi çıkarır. Bilinmeyen bir işlem geldiğinde sahte mi gerçek mi kendisi karar verir.

### Büyük Veri, Veri Madenciliği, Veri Bilimi

- Veri çok büyüyünce kurallarla yönetmek imkânsızlaşır (Amazon, Trendyol gibi milyonlarca müşteri).
- **Tavsiye sistemleri:** Netflix, birbirine benzeyen kullanıcıları bulup birinin izlediği filmi benzerine önererek başarılı bir öneri sistemi kurdu.
- **Veri madenciliği:** Veriden önyargısız, anlamlı bilgi çıkarmak.
  - Klasik örnek: Bebek bezi alanların bira da aldığı bulunmuş. Önyargıyla (kola alan cips alır) bulunamayacak bir ilişki.
- **Veri bilimi:** Veri madenciliğinin daha büyük veriyle evrilmiş hali. Örnek: televizyon izleyicisinin segmentini makine öğrenmesiyle bulup segmente göre farklı reklam göstermek.
- Bilgi çıkarmanın aracı makine öğrenmesi yöntemleridir.

### Derin Öğrenme

- Temel: çok katmanlı yapay sinir ağları (artificial neural networks, 1940'lardan beri var).
- **ImageNet:** İnsanlara internette resim etiketletilerek oluşturulan, milyonlarca etiketli resim içeren veri kümesi.
- Eskiden tanıma sistemleri az örnekle, kısıtlı pozlarla (ör. karşıdan bakan kedi, yüzde en fazla ±15 derece dönüş) eğitilirdi.
- Derin öğrenme milyonlarca farklı örnekle eğitildiği için arkası dönük kediyi, kısmen görünen tilkiyi, arka plana karışmış kurbağayı da tanıyabiliyor.
- Klasik yöntemlerde veri artınca başarı bir noktadan sonra artmıyordu. Derin öğrenmede veri arttıkça başarı artıyor.
- 2012: Bir nesne tanıma çalışmasında YouTube'daki 10 milyon etiketsiz resimden 3 gün çalışan bir programla kedi yüzü öğrenildi. Önceki sistemlerden belirgin daha başarılı oldu (hoca "%70 daha başarılı" diyor). Sonra Go oyunu, gerçek zamanlı İngilizce-Çince çeviri gibi uygulamalar geldi.
- GPU'lu donanımların yaygınlaşması derin öğrenmeyi mümkün kıldı.
- Dezavantaj: Eğitim süresi çok uzun (haftalar, aylar).
- Bazı problemler karar ağacı, k-en yakın komşu (k-NN), destek vektör makineleri (SVM) gibi klasik yöntemlerle daha az veriyle aynı başarıyı verir.
- Hocanın görüşü: 5-10 yıl içinde alan büyük olasılıkla derin öğrenmeye kayacak. Klasik yöntemlerin bir kısmı da derin öğrenmeye uyarlanabilir.

### Uygulama Alanları

- Biyoinformatik: Ailede kansere neden olan geni bulmak.
- Profil çıkarma (bir Avrupa Birliği projesi): Yolcunun yürüyüşüne, izlediği rotaya bakarak potansiyel tehdit tespiti.
- Pazarlama: Web sayfasını gezen kişiye hangi ürünlerin gösterileceği.
- Ses ile kişi tanıma (biyometri), optik/kızılötesi görüntüde insan-araç ayrımı, ağ saldırısı tespiti.

### Öğrenme Türleri

**Eğitmenli öğrenme (supervised learning)**

- Hem giriş hem çıkış bilgisi etiketli olarak verilir.
- Kural yazılmaz ("boyu şu kadarsa..." gibi). Yalnız örnekler verilir.
- Her sınıf için yeterli sayıda örnek gerekir.
- Bütün verinin etiketlenmesi gerekir.
- Model, sınıflar arasında karar sınırları (decision boundaries) oluşturur. Bilinmeyen örnek bu sınırlara göre sınıflandırılır.

**Eğitmensiz öğrenme (unsupervised learning)**

- Her zaman veri etiketlenemez.
- Sistem çok benzeyen örnekleri aynı gruba, az benzeyenleri farklı gruplara koyar.
- Çıkışta sınıf adı değil grup verilir. Gruplara insan bakıp etiket verebilir.
- Örnekler:
  - Telefondaki aynı yerde çekilmiş fotoğrafları gruplamak.
  - Belgeleri içeriğe göre gruplamak (ekonomi, spor). Elle etiketleme çok zahmetli. Hoca, bir yüksek lisans öğrencisinin ekonomi haberlerinin borsaya etkisi tezi için yaklaşık bin belgeyi elle etiketlediğini anlatıyor.
  - Kelimelerin benzerliklerine göre hiyerarşik (ağaç yapısında) kümelenmesi.
- Gruplarda hatalı örnekler olabilir. Ama insan etiketlemesi de hatalı olabilir.
  - Örnek: Afet sonrası tweet'leri "önemli / önemsiz" diye etiketlemede insanlar "binlerce kişi öldü" gibi mesajlarda hemfikir. "Bu köyde hasar çok fazla" gibi mesajlarda farklı etiket veriyor.
  - Bu tür çalışmalarda aynı veri 5-10 kişiye etiketletilir, çoğunluk oyu alınır.
- Az sayıdaki hata sistemin bütününe büyük zarar vermez.

**Yarı eğitmenli öğrenme (semi-supervised learning)**

- Etiketleyebildiğin kadar küçük bir bölüm etiketlenir. Kalanı etiketsiz kalır.
- Etiketli veriler kümelemenin daha doğru yapılmasına yardım eder.
- Son yıllarda çok kullanılan bir yaklaşım.

**Pekiştirmeli öğrenme / ödül-ceza ile öğrenme (reinforcement learning)**

- Hoca "pekiştirmeli" yerine "ödül-ceza ile öğrenme" adını tercih ediyor.
- Örnek: Uzaya gönderilen robot değerli taşları toplayacak ama yolu bilmiyor.
  - Taşa ulaşırsa ödül (pozitif puan).
  - Kayaya çarpıp ilerleyemezse ceza (negatif puan).
- Yalnız ödüller, cezalar ve hedef tanımlanır. Sistem hangi yolun etkili olduğunu kendisi öğrenir.
- Önce oyunlarda, sonra insansız taşıtlarda kullanıldı. Derin öğrenme ile birleşince yaygınlaştı.
- Örnek (reklam): Kullanıcı bir ürünü Facebook'ta görüp sonra Google üzerinden satın almaya gelirse eski sistemler yalnız son kaynağı (Google) hesaba katıyordu. Pekiştirmeli öğrenme, satın almaya giden yoldaki tüm durakların etkisini öğrenebiliyor. Hoca bunun Alibaba'nın bir makalesinde başarıyla çözüldüğünü söylüyor.

**Karşılaştırma**

- Eğitmensiz öğrenme en az bilgiyle çalışır.
- Pekiştirmeli öğrenmede biraz bilgi (ödül/ceza) verilir.
- Eğitmenli öğrenmede tam etiket bilgisi verilir.
- Günümüzde bu türler iç içe geçmiş durumdadır.

### Öğrenme Sisteminin Ana Adımları

```
Gerçek dünya / veri kaynağı (sensör: kamera, mikrofon; veritabanı)
  -> Ön işleme (iyileştirme, temizleme, renk uzayı dönüşümü...)
  -> Özellik çıkarma / seçme (feature selection / projection)
  -> Model (eğitmenli / eğitmensiz / pekiştirmeli)
  -> Model seçimi ve değerlendirme
```

**1. Problemi anlama**

- İyi bir sistem analizi ve fizibilite çalışması yapılmalı.
- Sorular:
  - Nasıl bir veri var? Ne kadar sürede toplanıyor?
  - Hangi öğrenme yöntemi uygun?
  - Veri etiketlenebiliyor mu? Etiketleme kolay mı?
  - Çıkış sınıf mı sürekli mi?
- Kredi kartı sahtekarlığı: Etiketli veri var (sahte / normal), çıkış 2 sınıf. Eğitmenli öğrenme uygun.
- Müşteri segmentasyonu (ör. Netflix izleyicileri): Etiket yok. Eğitmensiz öğrenme uygun.
- Ağ saldırısı tespiti: Saldırgan saldırı türünü sürekli değiştirdiği için normal-anormal ayrımını öğreten anomali tespiti (anomaly detection) uygun olabilir.
- Etiketli veri olsa bile etiketleme çok zahmetliyse eğitmensiz yönteme geçilebilir.

**2. Veri toplama**

- Belli miktarda veri toplamadan projeye başlanmamalı.
- Hocanın örnekleri:
  - Pandeminin başında değerlendirdiği bir turizm firmasının uçuş öneri projesi reddedildi. Firma veriyi IATA'dan alabileceğini düşünüyordu ama elinde toplanmış veri yoktu.
  - Jürisinde bulunduğu bir doktora tezinde, nadir görülen ortopedik bir rahatsızlık için 4 yılda toplanan görüntü sayısı 20'yi geçmemiş.
- **Sınıf sayısı** belirlenir.
- **Örnek çeşitliliği** sağlanmalı. Derin öğrenmenin başarısının ardında örnek çeşitliliği yatar. Farklı gelir, eğitim seviyesi, şehir gibi farklılıklar kapsanmalı.
- **Ana senaryolar** çıkarılmalı ve bu senaryolar için örnek toplanmalı:
  - İnsansız hava aracında sık karşılaşılan kuşlar, sağanak yağışta azalan görüş alanı (hoca bu örnekleri uydurduğunu söylüyor).
  - Yüz tanımada ışığı az ortamlar.
  - Hedef: Ana senaryolara karşı dayanıklı (robust) bir sistem kurmak.
- Diğer sorular:
  - Ne kadar veri yeterli? Sahtekarlık tespitinde bir yıllık işlem ve 10 bin müşteri yetmez, milyonlarca müşteri gerekir.
  - İyi örnekler kadar kötü örnekler de olmalı mı? Sistemi iyi temsil etmeyen örnekler başarıyı düşürebilir.
  - Simülasyonla veri üretilebilir mi? Eskiden sahte veri başarıyı düşürüyordu. Şimdi derin öğrenme ile gerçekçi sahte veri üretilebiliyor.

**Eksik veri**

- Çok örnek varsa eksik kayıtlar kullanılmaz.
- Az örnek varsa:
  - Önce benzer örnekler bulunur.
  - Bu örneklerde o özellik için en sık kullanılan değer boşluğa yazılır.
- Hocanın pek beğenmediği yaklaşım: Aynı sınıftaki diğer örneklerin ortalamasıyla doldurmak.
- Diğer seçenekler: o özelliği hiç kullanmamak (faydalı bir özellik kaybedilebilir), ortalama veya medyan ile doldurmak.

**Dengesiz sınıf dağılımı (imbalanced data)**

- Tıpta hasta verisi az (nadir hastalık) ya da kontrol grubu verisi az olabilir.
- Ağ saldırısında normal trafik çok, saldırı verisi az.
- Çözümler:
  1. Az örnekli sınıf için gerçekçi sahte örnek üretmek. Örnek yöntem: Çekişmeli Üretici Ağlar (Generative Adversarial Network, GAN).
  2. Örnekleri kopyalayarak çoğaltmak. Örnek: görüntüyü biraz döndürmek, bir kısmını kesmek (veri artırma, data augmentation).
  3. Çok örnekli sınıfı azaltmak (undersampling).
- Azaltmada izlenecek yol: Çok örnekli sınıf kademe kademe azaltılarak farklı modeller kurulur (ör. 1 milyon normal / 1000 sahte, 500 bin normal / 1000 sahte...). En başarılı oran seçilir.
- Hocanın BKM için yaptığı TÜBİTAK projesinde en iyi oran **5 normal : 1 sahte** bulunmuş.
- Azaltırken hangi örnekleri seçmeli?
  - Rastgele seçim benzer örneklerin seçilmesine yol açabilir.
  - Daha mantıklısı: Örnekleri önce benzerliklerine göre kümelemek, sonra her kümeden eşit sayıda seçmek. Ör. 10 küme × 500 örnek = 5000 örnek.
  - Bu yöntem yalnız örnek sayısı çok değilse anlamlı. 1 milyon örnekten rastgele 5000 seçmek zaten yeterince dağınık olur.

### Veri Tipleri

**Kullanılmayan (useless) veri**

- Öğrenmede kullanılmaması gereken özellikler: kimlik numarası, ad soyad.
- Bu veriler genelde kodlanmış olarak verilir.

**Sıralı (ordinal) veri**

- Aralarında ölçülebilir ilişki olan sayısal değerler. Tam sayı olması gerekmez.
- Örnek: yaş (43 ile 75 arası mesafe anlamlı), kilo (70 ile 90 arası).

**Kategorik (nominal) veri**

- Birbirinden farklı ama aralarında ölçüm ya da üstünlük karşılaştırması yapılamayan değerler.
- Örnek: yaşanılan şehir (İstanbul, Ankara), harcama kanalı (ATM, internet).
- Plaka numarası sayı olsa da ordinal değildir. 34 (İstanbul) ile 36 (Kars) arasındaki "2" farkının anlamı yoktur.

- Özelliklerin türüne göre yöntem seçilir ya da özellikler dönüştürülür.

### Ön İşleme

- **Gereksiz bilgiyi çıkarmak:**
  - Belge işlemede durak kelimeler (stop words: "and", "or", "if") çıkarılır. Bunlar sınıflar arası benzerliği gereksiz yere artırır.
  - Yüz tanımada renkli değil gri seviyeli görüntü kullanılır, çünkü renk bilgisi önemsizdir.
- **İyileştirme:**
  - Karanlık görüntüye histogram işlemi uygulanarak daha aydınlık ve kontrastlı hale getirilir.
  - Seste ses seviyesi artırılır, gürültü (parazit) temizlenir.
- Hatalı ya da eksik özelliklerin düzeltilmesi de ön işlemdir.

### Normalizasyon

- Uzaklık tabanlı yöntemlerde (Öklid uzaklığı, Manhattan uzaklığı) özelliklerin ölçekleri farklıysa bazı özellikler baskın çıkar.
  - Örnek: İnsan kilosunda 98 ile 100 kg arasındaki 2 kg fark küçüktür. Altında 1 ile 3 kg arasındaki 2 kg fark çok büyüktür.
- Çözüm: Değerleri belli bir aralığa çekmek.

**Min-max normalizasyonu ($[0,1]$ aralığı)**

$$x_i' = \frac{x_i - x_{min}}{x_{max} - x_{min}}$$

- En küçük değer 0, en büyük değer 1 olur.

**$[-1,1]$ aralığı**

- Merkezin sıfır olması isteniyorsa kullanılır. Yaygın kullanılan bağıntı:

$$x_i' = 2\,\frac{x_i - x_{min}}{x_{max} - x_{min}} - 1$$

- Not: Hoca bu bağıntıyı slayttan gösteriyor, sözlü olarak okumuyor. Buradaki formül standart $[-1,1]$ ölçeklemesidir.

**Belirli sınırlar arası normalizasyon**

- Görüntü işlemede gri seviyeler genelde $[0,255]$ aralığına çekilir:

$$x_i' = \frac{x_i - x_{min}}{x_{max} - x_{min}}\,(yeni_{max} - yeni_{min}) + yeni_{min}$$

**Z-skor normalizasyonu (standartlaştırma, standardization)**

$$z_i = \frac{x_i - \mu}{\sigma}$$

- $\mu$: verinin ortalaması, $\sigma$: standart sapması.
- Hoca bunun aslında normalizasyon değil standartlaştırma olduğunu söylüyor.
- Veri Gauss (normal) dağılımlıysa iyi sonuç verir. Gerçek hayattaki verilerin çoğu Gauss dağılımlıdır.
  - Örnek: Kadınların çoğunun boyu 1,55-1,65 m arasında. Çok azı 1,45-1,50 m veya 1,80 m üzeri.

### Varsayımlar

- Tüm problemleri tek projede çözmeye çalışmak doğru değil. Problemi parçalara ayırmak için varsayımlar yapılır.
- Örnekler:
  - Tavsiye sistemi yalnız iki aydan uzun süredir film izleyenler için kurulur. Yeni üyeye öneri (soğuk başlangıç, cold start) ayrı bir problemdir.
  - Kredi kartı sahtekarlığı modeli önce internet alışverişleri için kurulur. ATM harcamaları için gerekirse ayrı model kurulur.
  - Hedef tespitinde yalnız gündüz görüntüleri için çözüm üretilir. Gece kamerası ayrı bir problem.
- Her işe çözüm veren tek model yerine alt problemlere ayrı çözümler bazen daha etkilidir.

### Özellikler ve Model Seçimi

- Özellikler nesnenin ayırt edici karakteristikleri olmalıdır. Bir örneğin tüm özellikleri bir **özellik vektörü** (feature vector) oluşturur.
- Hoca slaytta 2 özellikle 3 sınıfı ayıran bir model gösteriyor. İki sınıf biraz karışıyor; daha iyi özellikler bulunmalı.
- Özellikler kolay ve kısa sürede elde edilebilmeli. Bir yıl sonra elde edilecek bir özellik için sistem bekletilmemeli.
- Farklı modeller arasından hatası en düşük olan seçilir. Ama "hata"nın ne olduğu probleme göre tanımlanmalı.
  - Hastalık teşhisinde asıl önemli olan hastaları yakalamak, yani doğru pozitifin (true positive) yüksek olması. Kanser olmayana "kanser" demek (yanlış pozitif, false positive) kötüdür ama hastayı kaçırmak daha kötüdür.

### Eğitim, Doğrulama ve Test Verisi

| Veri | Kullanım amacı |
| :--- | :--- |
| Eğitim (training) | Modeli eğitmek. Başarısı yalnız ezberleme kontrolü için anlamlı. |
| Doğrulama (validation) | Hangi modelin ve hangi parametrelerin daha başarılı olduğunu seçmek. |
| Test | En iyi model seçildikten sonra hiçbir şeyi değiştirmeden son başarıyı ölçmek. |

- Eğitimde %100, doğrulamada %80 başarı varsa model ezberlemiş olabilir; incelenmeli.
- Verinin bu üç gruba nasıl ayrılacağı ilerleyen derslerde işlenecek.

### Ders Sonu Duyuruları ve Sorular

- Ders slaytları her dersin sonunda paylaşılacak. Bir öğrenci materyallerin gecikmeden paylaşılmasını rica etti; hoca asistan olmadığı için zorlandığını söyledi.
- Kontenjan 30 kişi. Hoca gerekirse 5 kişi artırılabileceğini söylüyor. Ekle-bırak haftası devam ediyor.
- Dersler kayıt altına alınıyor. Kayıtlar derse bağlanılan sistemden ders sonrası izlenebilir.
- Hoca, YTÜ e-posta adresine gelen e-postaları alamadığını, kendi kurumsal adresinin (slayttaki adres) kullanılmasını söylüyor.
- Ders saati 10:00. Bir sonraki derste başta kameralar açık tanışma yapılacak.

### Ders sonrası notlar

- Altyazıda "Ethem Hoca" olarak geçen yazar, ders kaynaklarından "Introduction to Machine Learning" kitabının yazarı Prof. Dr. Ethem Alpaydın'dır. Hoca kitabın MIT Press'ten basıldığını ve Boğaziçi Üniversitesi'nden emekli olduğunu söylüyor.
- Diğer kaynak: Christopher Bishop, "Pattern Recognition and Machine Learning" (2006).
- Altyazıdaki "Ayata" IATA (Uluslararası Hava Taşımacılığı Birliği) olmalıdır.
- Altyazıdaki "TEDE / TEDEP projesi", TÜBİTAK TEYDEB (sanayi Ar-Ge destek) projeleridir.
- Altyazıdaki "Label Mini" büyük olasılıkla Stanford ekibinin ImageNet için kullandığı etiketleme sistemine yapılan bir atıftır; altyazıda net değil. ImageNet etiketlemesi Amazon Mechanical Turk ile yapılmıştır.
- Altyazıdaki "öplit distance" Öklid uzaklığı (Euclidean distance) olmalıdır.
- 2012'deki "YouTube'dan 10 milyon etiketsiz resimle kedi yüzü öğrenen sistem" Google Brain çalışmasıdır (Le ve ark., 2012). Aynı yıl ImageNet yarışmasını AlexNet kazanmıştır. Hoca ikisini tek bir olay gibi anlatıyor.
- "Bebek bezi ve bira" örneği veri madenciliği literatüründe çok anlatılır ama bir şehir efsanesi olarak da bilinir.
- Hoca derin öğrenme ile kurulan Go programını anıyor; bu, DeepMind'ın AlphaGo programıdır (2016).

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
