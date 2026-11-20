# Ders 2 Çalışma Özeti

## Genel Konular

- Zekayı ölçme tartışmasının tekrarı
  - Birinci görüş fonksiyonelliktir: Sistem dışarıdan gözlenebilen davranışlarına, yani çıktılarına göre değerlendirilir. Turing testi bu yaklaşımın örneğidir.
  - İkinci görüşe göre bakılması gereken şey sonuç değil, davranışın nasıl üretildiğidir (süreç). Searle'ün Çin odası deneyi gibi örnekler, dışarıdan zeki görünen bir sistemin arkasında çok basit bir mekanizma olabileceğini anlatır.
  - Hocaya göre insanlar da birbirinin beynindeki süreçlere erişemez. Birinin zeki olup olmadığına onun çıktılarına bakarak karar veririz, yani pratikte Turing testine benzer bir şey yaparız.
  - Satranç örneği: Kasparov'a dünya şampiyonu olduğu için (gözlenebilir bir çıktı) zeki deriz. Kasparov'u yenen Deep Blue gibi bir programın da zeki sayılıp sayılmayacağı bu iki görüş arasında tartışmalıdır.
- Rasyonel ajan (etmen)
  - Derste "insan gibi düşünmek / rasyonel düşünmek / insan gibi hareket etmek / rasyonel hareket etmek" tablosunda rasyonel hareket etmek merkeze alınır.
  - Ajan, kendi başına bir şeyler yapabilen bir sistemdir. Donanım ya da yazılım olması önemli değildir.
  - Sensörler çevreyi algılamak için kullanılır: klavye, mikrofon, kamera, dokunmatik ekran, lidar, mesafe ölçer, üç boyutlu kamera, GPS.
  - Aktüatörler (eyleyiciler) çevreye cevap vermek için kullanılır: kol, bacak, tekerlek, ekran, hoparlör, korna.
  - Asıl soru, sensörlerden gelen girdilerin aktüatörlere giden çıktılara nasıl eşleneceğidir (slayttaki "?" kutusu). Dersin konusu bu eşlemenin yöntemleridir.
- Ajan türleri (bir ajan birden fazla türe girebilir)
  - Refleksif, tam eşleme: O ana kadarki tüm girdi sekansına ya da mevcut girdiye karşılık gelen hareket uygulanır. Durum → hareket ikililerinden oluşan bir tablo vardır (ekrandan, 00:20:00).
  - Refleksif, yaklaşık eşleme: Girdiye en çok benzeyen durum belirlenir ve o duruma karşılık gelen hareket uygulanır.
  - Hafızalı / hafızasız: Zamanla değişebilen bir iç durum vardır ya da yoktur. Hafızalı ajan aynı girdi için her zaman aynı çıkışı üretmeyebilir.
  - Kendi öğrenen / öğretilen: Karar mekanizması çevreyle etkileşerek ya da örneklerden optimize edilir ya da insanlar tarafından oluşturulup sisteme verilir.
  - Öğrenimi hep süren / sürmeyen: Karar mekanizmasının çalışırken (test zamanında) değişmeye devam edip etmediğidir. "Lifelong learning" bu ayrıma karşılık gelir.
- PEAS: Ajan tasarlamadan önce karar verilecek parametreler
  - P (Performance measure): Ajanın başarısı nasıl ölçülecek?
  - E (Environment): Ajan nasıl bir ortamda çalışacak?
  - A (Actuators): Ortam nasıl değiştirilecek?
  - S (Sensors): Ortam nasıl algılanacak?
- Ortam özellikleri
  - Fully observable / partially observable, deterministic / stochastic, episodic / sequential, static / dynamic, discrete / continuous, single agent / multi agent.
- Problemlerin arama problemi olarak formüle edilmesi
  - Bloklar dünyası (planlama), robot yol planlama, çiftçi-kurt-keçi-kabak problemi, su bidonları problemi ve 8-puzzle örnekleri.
  - Bir problemi formüle etmek için durumlar, başlangıç durumu, hedef durumu ve durumları birbirine dönüştüren operatörler tanımlanır. Çözüm, başlangıçtan hedefe götüren bir operatör dizisidir.
- Arama ile ilgili tanımlar ve aramanın zorluğu
- Arama stratejilerinin değerlendirme ölçütleri ve kör arama algoritmaları
- Enlemesine arama (Breadth-first search, BFS): algoritma ve analiz

## Hocanın Özellikle Vurguladığı Kısımlar

- Tam eşlemeli refleksif ajanın problemi
  - Gelen girdiye tam uyan bir satır tabloda olmayabilir. Bunu çözmek için tablo bütün olası durumları kapsamalıdır. Durum sayısı çok büyükse bu mümkün değildir. O zaman en sık karşılaşılan durumlar için ayrı satır yazılıp geri kalanların hepsine tek bir hareket verilebilir.
  - Gerçek dünyada sensörle çalışan bir sistemin hep aynı girdiyle karşılaşması çok düşük bir ihtimaldir. Bu yüzden böyle sistemler genelde yaklaşık eşleme yapar. Parmak izi tanımada bile okunan iz kayıtlı izle birebir aynı olmaz.
- Öğrenimi hep süren olmanın ölçütü
  - Ölçüt, sistemin çalışırken (test zamanında) kendi parametrelerini güncelleyip güncellemediğidir.
  - Çalışırken toplanan verilerle modelin daha sonra yeniden eğitilmesi "öğrenimi hep süren" anlamına gelmez.
- Kendi öğrenen / öğretilen ayrımı
  - Kurallar insanlar tarafından yazılıp sisteme verildiyse (kural tabanlı uzman sistem, Prolog'da yazılan kurallar, hesap makinesi) sistem öğretilendir.
  - Etiketli ya da etiketsiz veriyle model eğitiliyorsa ya da pekiştirmeli öğrenme kullanılıyorsa sistem kendi öğrenendir.
  - Bir sistemin otonom çalışması onun kendi öğrenen olduğunu göstermez. Belirleyici olan, karar mekanizmasının nasıl oluşturulduğudur.
  - Kendi öğrenen / öğretilen ayrımı ile öğrenimi hep süren / sürmeyen ayrımı ayrı boyutlardır.
- Gerçek dünya en zor ortamdır
  - Gerçek dünya kısmen gözlenebilir, stokastik, sequential, dinamik, sürekli (continuous) ve çok ajanlıdır. Yani her ölçütte zor olan taraftadır. Simülasyon ve oyun dünyaları bu açıdan çok daha kolaydır.
- Çözüm bulmak ile en iyi çözümü bulmak aynı şey değildir. Çözüm yolu ile optimum yol arasında fark vardır.
- Optimumluğun tanımı
  - Bir algoritmanın optimum olması, bulduğu ilk çözümün en düşük maliyetli çözüm olması demektir.
- Aramanın zorluğu
  - Derinlik ve dallanma sayısı arttıkça gereken zaman ve bellek üstel olarak artar. Daha hızlı bilgisayarlar kullanılsa bile derinlik biraz artınca süre yıllara çıkar.
  - Hafıza, zamandan daha büyük bir problemdir.

## Kısa Tekrar Notları

- Fonksiyonellik: zekayı çıktılardan değerlendirmek (Turing testi). Karşı görüş: süreç önemlidir (Çin odası).
- Ajan = sensörler + aktüatörler + aradaki eşleme mekanizması.
- Tam eşleme: durum → hareket tablosu. Yaklaşık eşleme: en benzer durumun hareketi.
- Satranç tahtasının son hali en iyi hamle için yeterlidir (hafızasız olabilir). Borsa tahmini için trend gerekir (hafızalı).
- Öğrenimi hep süren: test zamanında kendini güncelleyen sistem.
- PEAS = Performance measure, Environment, Actuators, Sensors.
- Statik ortamda ajan dışında ortamı değiştiren bir nesne yoktur. İçinde insanların gezdiği ya da başka robotların çalıştığı ortam dinamiktir.
- Satranç tamamen gözlenebilir, okey kısmen gözlenebilir bir ortamdır (rakiplerin eli görülmez).
- Formülasyon: durum gösterimi, $S_0$, $G$, operatörler (ön koşul + dönüşüm), maliyet.
- Çiftçi problemi: 4 nesne × 2 konum ($N$/$S$) → $2^4 = 16$ durum.
- Su bidonları: durum $(x, y)$, $x$: 4 galonluk, $y$: 3 galonluk bidondaki su. Başlangıç $(0,0)$, hedef $(2, n)$.
- 8-puzzle: taş başına 4 hareket → 32 operatör. Boş kareyi hareket ettirirsek 4 operatör ($L, R, U, D$, maliyet 1).
- 8-puzzle: ortalama çözüm adımı 22, ortalama dallanma 2,67. Slayta göre bu, tekil olmayan yaklaşık 2,7 milyar durum demektir (ekrandan, 02:05:00).
  - Ders sonrası not: $2{,}67^{22} \approx 2{,}4 \times 10^9$ çıkıyor (python ile hesaplandı). Slayttaki 2,7 milyar büyük olasılıkla yuvarlanmış bir değerdir. Mertebe aynıdır.
- $b$: dallanma sayısı, $d$: en az maliyetli çözümün derinliği, $m$: arama uzayının en büyük derinliği.
- Değerlendirme ölçütleri: tamlık, zaman karmaşıklığı, hafıza karmaşıklığı, optimumluk.
- Kör arama algoritmaları: enlemesine, düşük maliyetli, derinlemesine, sınırlı derinlikli, artan derinlikli, çift yönlü.
- BFS: FIFO kuyruk. $b$ sonluysa tamdır. Zaman ve hafıza $O(b^d)$. Bütün adımların maliyeti eşitse optimumdur.

## Detaylı Açıklamalar

- Ajan türlerine öğrenci örnekleri ve hocanın düzeltmeleri
  - Hesap makinesi tam eşlemeli ve öğretilen bir sisteme örnektir. Telefon alarmı, telefon araması ve komut konsolu da tam eşleme için kabul edildi.
  - Çeviri sistemleri tam eşleme olamaz. Çevrilebilecek bütün cümlelerin tek tek kodlanması gerekirdi ve girdi uzayı çok büyüktür.
  - Mars keşif aracı ya da maden arayan robot gibi gerçek dünyada sensörle çalışan sistemler yaklaşık eşleme yapmak zorundadır.
  - ELIZA yalnız son girdiye bakarak cevap verir. Bu yüzden hafızasızdır ve yaklaşık eşlemeyle çalışır. Diyalogdaki önceki cümleleri kullanan bir sohbet botu ise hafızalıdır.
  - Haritası verilen bir robot süpürgenin hafızaya ihtiyacı olmayabilir. Bilinmeyen bir evde kendi haritasını çıkaran, nereyi süpürdüğünü hatırlaması gereken bir robot ise hafızalıdır.
  - Hava durumu tahmini geçmişi kullanmalıdır. Kışın ölçülen 19 derece ile yazın ölçülen 19 derece farklı anlamlara gelir.
  - Yüz tanıma ve maske tespiti hafızasızdır. Yalnız o anki girdiye bakılır.
  - Siri gibi asistanlarda "kaç yaşındasın" gibi sık sorulan sorulara insanların yazdığı cevaplar vardır. Bu kısım tam eşleme ve öğretilendir. Geri kalanı eğitim kümeleriyle eğitilmiş modellerdir. Yani bu tür sistemler tek parça değildir.
  - Face ID ve parmak izi sistemleri öğretilen sistemler değildir. Kullanıcının birkaç kez parmağını okutması, karar mekanizmasının insanlarca kurallarla yazılması anlamına gelmez.
  - Labirent çözen bir sistem, kurallarını insanlar yazdıysa öğretilen, pekiştirmeli öğrenmeyle öğrendiyse kendi öğrenendir.
  - Bir tahminde bulunup sonra tahminin tutmadığını görerek tahmin mekanizmasını güncelleyen borsa sistemi, öğrenimi hep süren bir sistemdir.
- PEAS örnekleri
  - Harita çıkaran robot (ekrandan, 01:35:00): P: haritanın doğruluğu, işlem hızı, statik / dinamik ortamlarda çalışabilmesi. E: duvarlar, bina içi, dış ortam, statik / dinamik, engeller. A: tekerleklerin yönü ve hızı, kamera kontrolü. S: lazer / sonar / kızılötesi uzaklık algılayıcılar, kamera.
  - Otonom taksi sürücüsü: P: güvenli, hızlı, yasal ve konforlu (ani ivmelenme ve dönüş yok) sürüş. S: kameralar, uzaklık ve hız ölçerler, motor sensörleri ve müşterinin gideceği yeri söylemesi için mikrofon, klavye ya da dokunmatik ekran. Bütün araçlar otonom olursa korna gerekmez, araçlar kendi aralarında haberleşebilir.
  - Slaytlarda tıbbi teşhis uzmanı, banttan geçen balıkları türlerine göre ayıran ajan ve İngilizce öğretmeni örnekleri de var. Bunlar derste ayrıntılı anlatılmadı.
- Ortam özellikleri (ekrandan, 01:40:00)
  - Fully observable: Ajanın sensörleri ortamın tamamını algılayabiliyorsa.
  - Deterministic: Ortamın bir sonraki durumu yalnız şu anki durum ve ajanın yaptığı hareketle belirleniyorsa. Stokastik ortamda şans vardır. Slaytta, sonraki duruma başka ajanların hareketleri de etki ediyorsa ortamın "strategic" olduğu yazıyor.
  - Episodic: Yapılan bir hareket ileriye doğru etki etmiyorsa (klasik arama motoru, parmak izi tanıma). Sequential ortamda arka arkaya yapılan hareketler süreci etkiler.
  - Discrete: Algılar ve hareketler sınırlı sayıda ve açıkça belirtilmişse. Sonsuz sayıdaysa continuous.
  - Single agent / multi agent: Ortamda bir ya da birden çok ajan olması.
- Problem formülasyonu örnekleri
  - Bloklar: A, B, C küpleri bir başlangıç dizilişinden istenen dizilişe getirilecek. Hareketler: küpü tut, yere koy, başka bir küpün üstüne koy. Çözüm bir hareket sırasıdır, örneğin "B'yi al A'nın üstüne koy, sonra C'yi al B'nin üstüne koy".
  - Robot yol planlama (ekrandan, 01:45:00): Başlangıç noktasından (B) hedef noktasına (H) gitmek. Olası hareketler sola, sağa, aşağıya, yukarıya. Hareketlerin maliyetleri farklı olabilir (dikey bir ortamda yukarı çıkmak daha fazla enerji harcatır). Amaç en az maliyetli hareket dizisini bulmaktır.
  - Çiftçi problemi: Çiftçi (Ali), kurt, keçi ve kabak nehrin güneyinden kuzeyine geçirilecek. Sandal çiftçiyle birlikte en fazla bir nesne taşır ve çiftçisiz gidemez. Çiftçi yanlarında yokken kurt keçiyi, keçi kabağı yer. Sandal her zaman çiftçiyle birlikte olduğu için ayrıca gösterilmez. Durum, her nesnenin konumunu gösteren dörtlüdür (çiftçi, kurt, keçi, kabak). Başlangıç $(S,S,S,S)$, hedef $(N,N,N,N)$.
  - Operatör gösterimi (ekrandan, 01:50:00): `Move(Goat, North)`: `(S, ?wolf, S, ?cabbage) => (N, ?wolf, N, ?cabbage)`. `?wolf` kurdun yerini gösteren bir değişkendir. Değişken kullanmak çok sayıda kural yazmaktan kurtarır: burada 4 kural yerine 1 kural yeter.
  - Su bidonları: 4 ve 3 galonluk iki boş bidon ve sınırsız bir pompa var. 4 galonluk bidona tam 2 galon su konulacak. Durum $(x, y)$ ile gösterilir. 3 galonluk bidonda 4 galon su olamayacağı için $(2, 4)$ geçerli bir durum değildir.
  - 8-puzzle (ekrandan, 02:00:00): Karıştırılmış taşlar hedef dizilişe getirilir. Taşları hareket ettirmek yerine boş kare hareket ettirilerek operatör sayısı 32'den 4'e iner.
- Su bidonu operatörleri (ekrandan, 01:55:00)

```text
1  (x,y) -> (4,y)             if x < 4                 4 galonluk bidonu pompa ile doldur
2  (x,y) -> (x,3)             if y < 3                 3 galonluk bidonu pompa ile doldur
3  (x,y) -> (0,y)             if x > 0                 4 galonluk bidonu yere boşalt
4  (x,y) -> (x,0)             if y > 0                 3 galonluk bidonu yere boşalt
5  (x,y) -> (4, y-(4-x))      if x+y >= 4 and y > 0    4 galonluk dolana kadar 3'lükten doldur
6  (x,y) -> (x-(3-y), 3)      if x+y >= 3 and x > 0    3 galonluk dolana kadar 4'lükten doldur
7  (x,y) -> (x+y, 0)          if x+y <= 4 and y > 0    3'lüğün tamamını 4'lüğe boşalt
8  (x,y) -> (0, x+y)          if x+y <= 3 and x > 0    4'lüğün tamamını 3'lüğe boşalt
```

<!-- BELİRSİZ: 7 ve 8 numaralı operatörlerin slaytı karelerde yok; tanımları altyazıdaki anlatımdan, koşulları ise operatörün anlamından yazıldı. -->

- Su bidonu probleminin çözümü
  - Derste gösterilen çözüm: $(0,0) \xrightarrow{2} (0,3) \xrightarrow{7} (3,0) \xrightarrow{2} (3,3) \xrightarrow{5} (4,2) \xrightarrow{3} (0,2) \xrightarrow{7} (2,0)$. Bu dizi python ile adım adım kontrol edildi. 8 operatörün hepsinin kullanılması gerekmez.
- Arama tanımları
  - Durum uzayı / arama uzayı / arama ağacı: durumları, aralarındaki geçişleri, geçiş parametrelerini ve kısıtları gösteren graf ya da ağaç.
  - Operatörler durumlar arası geçişi sağlar. Başlangıç durumu $S_0$, hedef durumu $G$.
  - Maliyet (cost): operatörü uygulamanın maliyeti.
  - Çözüm yolu: başlangıç durumundan hedef duruma giden yol. Optimum yol: en düşük maliyetli çözüm yolu. Birden fazla optimum yol olabilir.
- Arama neden zor?
  - Varsayımlar: dallanma sayısı 10, saniyede işlenen durum sayısı 1000, bir düğüm için 100 bayt bellek.
  - Derinlik 0: 1 durum, 1 milisaniye, 100 bayt. Derinlik 2: $1 + 10 + 100 = 111$ durum, yaklaşık 0,1 saniye, 11 kilobayt. Derinlik 12: yaklaşık $10^{12}$ durum, 35 yıl.
  - Ders sonrası not: Hoca derinlik 12 için gereken belleği "111 kilobayt" olarak söyledi. Aynı varsayımlarla doğrusu $1{,}11 \times 10^{12}$ düğüm × 100 bayt ≈ 111 terabayttır (python ile hesaplandı).
- BFS'nin işleyişi ve analizi
  - Ağaç baştan hazır değildir, arama sırasında oluşturulur. Çözüm bir durum sırasıdır, durum açma sırası da bir sıradır ama ikisi farklı şeylerdir (ekrandan, 02:15:00).
  - Algoritma: Kök kuyruğa konur, `bulundu = false`. Kuyruk boş değilken ve çözüm bulunmamışken kuyruğun başındaki durum $n$ çekilir. $n$ hedef durumsa `bulundu = true` olur. Değilse $n$'den gidilebilecek bütün durumlar kuyruğun sonuna eklenir.
  - Her zaman köke en yakın açılmamış düğüm açılır. Bu yüzden daha derindeki bir düğüm, daha sığdaki bir düğümden önce açılmaz.
  - Tamlık: $b$ sonluysa evet. Zaman: $1 + b + b^2 + \dots + b^d = O(b^d)$. Hafıza: $O(b^d)$ (her düğüm hafızada). Optimumluk: her adımın maliyeti eşitse evet.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
