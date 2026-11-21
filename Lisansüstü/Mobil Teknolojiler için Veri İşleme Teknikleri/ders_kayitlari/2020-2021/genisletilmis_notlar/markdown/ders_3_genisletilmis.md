# Ders 3 Genişletilmiş Notu: Bağlam Farkındalığı: Bağlam Kategorileri, Yaşam Döngüsü, Edinim, Modelleme ve Çıkarım

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Bağlamın Kategorileri: Birincil ve İkincil Bağlam
- 2. Veriden Bilgiye: Öğrenen Sistemler ve Öznitelikler
- 3. Aktivite Tanımada Sensör Seçimi
- 4. Toplumsal Bağlam Algılama
- 5. Verinin Değişme Sıklığı ve Enerji Tüketimi
- 6. Mobil Cihazlarda Derin Öğrenme
- 7. Bağlam Farkındalığının Seviyeleri
- 8. Sürekli Öğrenme ve Modelin Güncellenmesi
- 9. Bağlam Farkındalıklı Sistemlerin Özellikleri ve Yaşam Döngüsü
- 10. Dijital Unutma
- 11. Bağlam Edinimi
- 12. Bağlam Modelleme ve Ontoloji
- 13. Bağlam Çıkarımı ve Karar Modelleri
- 14. Bağlam Farkındalığı Taksonomisi

## 1. Bağlamın Kategorileri: Birincil ve İkincil Bağlam

Ders, bir önceki derste bağlamın kalitesi (quality of context) konusunda kalınan yerden devam etti. İlk slayt bağlam kategorilerini iki eksende gösteren bir tabloydu (ekrandan, 00:10:00). Dikey eksende kavramsal bakış açısı (conceptual perspective) vardır: konum (location), kimlik (identity), zaman (time) ve aktivite (activity). Yatay eksende operasyonel bakış açısı (operational perspective) vardır: birincil (primary) ve ikincil (secondary) bağlam.

Tablonun içeriği şöyledir:

| Boyut | Birincil (primary) | İkincil (secondary) |
|---|---|---|
| Konum | GPS sensöründen konum verisi (örneğin enlem ve boylam) | GPS değerleriyle hesaplanan iki sensör arasındaki mesafe; harita servisinden alınan harita görüntüsü |
| Kimlik | Kullanıcının RFID etiketiyle tanınması | Kullanıcının Facebook profilinden arkadaş listesinin alınması; yüz tanıma sistemiyle kişinin belirlenmesi |
| Zaman | Saatten zamanın okunması | Hava durumu bilgisinden mevsimin hesaplanması; mevcut aktivite ve takvimden zamanın tahmini |
| Aktivite | Kapı sensöründen kapı açılma aktivitesinin belirlenmesi | Kullanıcı takviminden aktivite tahmini; GPS, jiroskop, ivmeölçer gibi telefon sensörlerinden aktivitenin bulunması |

Birincil bağlam, sensörden doğrudan gelen bilgidir. Hoca, bir cihazdan ya da makineden bilgi gelirken olmazsa olmaz olan bilgileri hatırlattı: konum, kimlik, verinin aktarıldığı zaman ve nesnedeki değişikliğin hangi aktiviteyle sonuçlandığı. İkincil bağlamda ise yalnız veriyi almak yetmez; birden fazla veriyi kullanarak çıkarım yapmak amaçlanır. Örneğin iki sensörün GPS değerlerinden aralarındaki mesafe hesaplanır.

### 1.1 RFID ve QR kod

Kimlik satırındaki RFID üzerine hoca, RFID'nin günümüzdeki alternatifini sordu. Bir öğrencinin NFC önerisinin ardından aranan cevabın QR kod olduğu söylendi. İkisi birbirinin rakibidir ve farklı artı ve eksileri vardır:

- QR kod çok yaygın ve ucuzdur, ama okuyucu ile kod arasında görüş hattı (line of sight) gerektirir ve okumalar teker teker yapılır.
- RFID'nin bir maliyeti vardır; bu maliyet pasif ya da aktif etiket kullanımına göre değişir. Görüş hattı gerektirmez, bu yüzden bir bölgeden aynı anda toplu eşya giriş-çıkışı kolayca yönetilebilir.

Hoca bu farkı haberleşmedeki seri ve paralel iletime benzetti: QR kod seri, RFID paralel gibi düşünülebilir.

### 1.2 Zamandan bilgi türetmek

Saatten okunan zaman sayısal bir bilgidir, ama tek bir zaman değerinden günün hangi saati, gece mi gündüz mü olduğu, haftanın hangi günü, hangi ay ve hangi mevsim olduğu çıkarılabilir. Hoca bunu veriden bilgiye (information) giden yol olarak tanımladı: ham veri işlenerek ona daha fazla anlam katılır. Her bağlam algılama uygulaması bu ayrıntıya ihtiyaç duymaz, ama örnekler çoktur:

- Bir bankacılık uygulamasının "günaydın" ya da "iyi akşamlar" demesi zamana dayanır.
- Trafik hızı tahmininde günün saati (sabah, öğle, akşam) ve mevsim önemlidir; İstanbul trafiğinin yazın ve kışın farklı karakteristikleri vardır.

Tablodaki "mevcut aktivite ve takvimden zamanı tahmin etme" maddesi için hoca bir güvenlik örneği verdi. Kişilerin gece uyuması, gündüz iş yerinde olması beklenir. Evde kimsenin olmaması gereken bir saatte evde aktivite algılanırsa doğrudan alarm üretilebilir. Ancak ev halkının evde olduğu bilinen bir saatte aynı aktivite için alarm üretmek yanlış pozitif (false positive) olur ve gereksiz yere insanları harekete geçirir.

## 2. Veriden Bilgiye: Öğrenen Sistemler ve Öznitelikler

Hoca, önceki derste bahsedilen sanal ve mantıksal sensörlere döndü. Yalnız fiziksel sensörlerden gelen veriler değil, insanların ve dünyanın akış düzeni de tecrübeyle yorumlanarak bağlam hakkında daha derin tahminler yapılabilir. Bugün bu yorumları biz yapıyoruz, çünkü bunları öğrendik; derin öğrenme uygulamaları da benzer biçimde veriden öğrenen sistemlerin tasarlanabildiğini gösteriyor.

### 2.1 Kedi örneği

Hoca bilinen bir hikâyeyi anlattı: bir kişinin bahçesine sürekli bir kedi geliyor ve bitkileri yiyor. Kediyi kaçırmak için kamera kurup kedi geldiğinde alarm üretecek bir tanıma sistemi yapılıyor. Kedinin belli bir tipi olsa da farklı kediler gelebilir, kedi farklı açılardan görünebilir. İlk denemede veri çok az olduğu için sistem öğrenememiş; her şeye kedi diyor ya da kediyi tanıyamıyor. Zaman geçtikçe toplanan verilerle sistem kediyi çok yüksek oranla tanımaya başlıyor.

Buradan çıkan dersler şunlardır:

- Bilgisayarlar insana benzer şekilde veriyle öğrenebilir; ne kadar çok veri verilirse o kadar hızlı öğrenir.
- Verinin çeşitliliği çok önemlidir. Yalnız kedinin önden fotoğrafları verilirse yandan ya da başka açılardan görünen kedi öğrenilemez.

### 2.2 Ham veri yetmediğinde: zaman ve frekans alanı öznitelikleri

Sistemler kendi kendine öğrenme yeteneğine sahip olsa da çalışmalar, insanın tecrübesine dayanarak katkı sağlayacağını düşündüğü özellikleri ek öznitelik olarak eklemesinin başarıyı artırdığını gösteriyor. Hoca bunu insan aktivitesi örneğiyle açtı: yürüyüş sırasında bacağın hareketi incelenerek kişinin yürüyor mu, koşuyor mu, oturuyor mu, duruyor mu olduğunu anlamak için jiroskop ve ivmeölçer kullanılır. Bu sensörlerin ham verisi sisteme öğretildiğinde belli bir başarıya ulaşılır.

Hocanın ekibinin yaptığı bir test çalışmasında bu başarının bir sınırı olduğu görülmüş. Sınırı aşmak için sinyalden elde edilen ek bilgiler sisteme verilmiş: medyan, standart sapma ve sıfır geçiş oranı (zero crossing rate) gibi öznitelikler ham veriden çıkarılıp derin öğrenmeye verildiğinde başarı daha da artmış. Bu özniteliklerin çoğu zaman alanı (time domain) öznitelikleridir.

Sonuç olarak, derin öğrenme hayatımıza daha çok görüntülerle girdi ve piksellerden birçok şey öğretilebiliyor, ama bu her problem için aynı değildir. Bazı problemler zaman alanı ve frekans alanı özniteliklerine ihtiyaç duyar. Bir de bu ikisinin birleşimi olan zaman-frekans alanı (time-frequency domain) öznitelikleri vardır; hoca bunu üçüncü bir uzay olarak düşünmeyi önerdi. Bu üç uzaydaki özniteliklerin neler olduğu ve hangi problemlerde iyileştirme sağladığı dersin ilerleyen haftalarında işlenecek.

> **Ek bilgi (derste anlatılmadı):** Sıfır geçiş oranı, sinyalin bir pencere içinde işaret değiştirme (sıfır çizgisini geçme) sayısının pencere uzunluğuna oranıdır. Hareket sinyallerinde salınımın sıklığı hakkında kabaca bilgi verir; yürüme ve koşma gibi periyodik aktivitelerde değeri belirgin biçimde farklılaşabilir.

## 3. Aktivite Tanımada Sensör Seçimi

Tablodaki son madde, telefon sensörlerinden (GPS, jiroskop, ivmeölçer) kullanıcı aktivitesinin bulunmasıydı. Bağlamı anlamak için kişinin aktivitesini tanımak önemlidir: araçla mı seyahat ediyor, yürüyor mu, evde mi, oturuyor mu, iş yerinde mi çalışıyor? Hoca, fabrikalarda çalışanların gün içinde ne kadar aktif olduğunun artık takip edildiğini de ekledi.

**Soru:** Aktivite tanıma için GPS, jiroskop, ivmeölçer ve manyetometreden hangisi tercih edilmeli?

**Cevap:** Bir öğrenci, takip edilecek ortama bağlı olduğunu söyledi: bakım evlerinde yaşlıların takibi gibi kapalı mekân senaryolarında GPS doğru veri vermez, dış mekânda ise GPS daha uygun olabilir. Hoca bu cevabı doğru buldu ve genişletti. Önce kişinin hangi ortamda olduğu anlaşılmalıdır. GPS bilgisi dinamik olarak kullanılır: belli bir süre (örneğin 2, 5 ya da 10 dakika; bu süre dinamik olarak değişebilir) konumda değişim yoksa kişi kapalı bir ortamdadır ya da en azından hızlı bir hareket içinde değildir. O zaman daha az enerji tüketen sensörlere geçilir. İç mekânda olduğu anlaşıldıktan sonra GPS'in pek faydası yoktur; kabaca konumu verir ama içerideki ayrıntıyı yakalayamaz. Çalışmalar jiroskop, ivmeölçer ve manyetometrenin üçünün birlikte kullanıldığında en iyi sonucu verdiğini göstermektedir; üçü de düşük enerji tüketen sensörlerdir.

Hoca aktivite tanımada kullanılan bir sensör daha olduğunu sordu. Bir öğrencinin cevabı RGB kameralar ve derinlik (depth) bilgisi de veren RGB kameralar oldu. Kapalı ve yerel bir ortamda, örneğin yaşlıların yaşadığı evlerde, daha ayrıntılı bilgi gerektiğinde kamera sistemleri kullanılır. Kişinin koluna akıllı saat ya da bileklik takılabilir, ama yapılan aksiyonun ayrıntısını görmek için kamera kayıtları incelenir. Dış mekânda da kamera kullanılabilir, ancak kameranın sorunları çoktur:

- Maliyetlidir.
- Enerji tüketimi yüksektir.
- Kurulumu (deployment) zordur.
- Mahremiyet (privacy) sorunu vardır.

## 4. Toplumsal Bağlam Algılama

Kameralar bireysel aktivite izlemenin ötesinde toplum hareketlerini incelemek için de kullanılır. Hoca toplumsal bağlam algılamanın nerede gerekebileceğini sordu. Bir öğrenci toplu taşımayı önerdi: istasyon bazında yoğunluk incelenerek sefer sıklığı ayarlanabilir; salgın döneminde aynı araçta çok kişi olmaması için uygun sayıda araç sefere çıkarılabilir. Hoca araçtaki kişi sayısına sonra döneceğini söyleyip havalimanı örneğine geçti.

### 4.1 Kalabalıkta anomali tespiti

Havalimanında normal güvenlik kameralarıyla aranan şey, insan hareketlerindeki anomalilerdir. Terör eylemlerinin önlenmesi için şüpheli kişilerin şüpheli davranışlarının önceden öngörülebilmesi gerekir. Kalabalık açık alanlarda şüpheli hareketleri görüntülerden analiz etmek çok değerli ama hiç basit olmayan bir iştir. (Hoca termal kameraların özellikle askeri uygulamalarda dış alanda ciddi tespitler sağladığını, ama sorunun normal kamerayla ilgili olduğunu belirtti.)

**Soru:** Bu tür anomali tespit çalışmalarındaki en büyük sıkıntı nedir?

**Cevap:** Bir öğrenci kimlik eşleştirmesini önerdi. Hocanın cevabı veri sorunuydu. Bir kişinin anomali gösterip göstermediğini anlamak için veri setine ihtiyaç vardır ve bu veri seti genelde normal hareketleri içerir. Anormal hareket örneği bulmak çok zordur, çünkü terör, patlama ya da kötü niyetli organizasyon sayısı toplamda çok düşüktür. Kötüyü sisteme öğretemediğiniz için hep sorun çıkar. Dolandırıcılık tespitinde (fraud detection) de durum böyleydi; son yıllarda çok sayıda dolandırıcılık etiketlendiği için bu sorun bir ölçüde aşıldı.

Veri yetersiz kaldığında aykırı değerleri (outlier) bulmaya yönelik çalışmalar yapılır. Anomali tespiti (anomaly detection), aykırı değer tespitini (outlier detection) alt başlık olarak içeren bir alandır: sisteme normal öğretilir ve normalden sapan durum tespit edilir. Ağ güvenliğindeki saldırılarda ve zararlı yazılım (malware) tespitinde de aynı mantık işler: sisteme bir virüs ya da saldırı tekniği öğretilir, ama iki gün sonra bambaşka karakteristikte bir saldırı geldiğinde sistem onu tanıyamaz. Bu yüzden sisteme "bunlar normal akışlar" denir ve anormal bir akış olduğunda uyarması istenir. Anomali tespiti son yıllarda çok gündemde olan ve birçok alanda kullanılan bir yöntem ailesidir; veri işleme tekniklerine gelindiğinde tekrar ele alınacak.

### 4.2 Toplu taşımada araçtaki kişi sayısı

Toplu taşımanın kullanım şekli önemlidir. Bir aracın mekaniğinin zamanla yıpranması dengesiz yüklenmeden kaynaklanabilir: araçta bir tarafa yığılma olur, trenlerde bazı vagonlar boşken bazıları dolu olur. Bunu tespit etmek farklı açılardan katkı sağlar. Hoca piyasadaki bir çözümü örnek verdi: aracın kapı bölgesine yerleştirilen kamera kafa sayarak inen ve binenleri tespit ediyor.

**Soru:** Bir araçta kaç kişi olduğunu başka nasıl bulabiliriz?

**Cevap:** Tartışmada çeşitli öneriler ele alındı:

- Kart okutma (Akbil) binenleri gösterir, ama inerken kimse kart okutmadığı için inenler anlaşılamaz.
- Kapılara lazer, kızılötesi (infrared) ya da ultrasonik sensör konabilir. Hoca bunun kalabalık toplu taşımada çalışmayacağını söyledi: insanlar hep birlikte hareket ettiği için biri inse bile yerini başkası kapatır, nesnenin varlığı ve yokluğu net ayrılmaz.
- Mobil cihazlar Bluetooth ile tespit edilebilir. Öğrenci bunun Bluetooth'un sürekli açık olmasını gerektirdiğini belirtti.

Hoca Bluetooth yönteminin ilginç olduğunu ve İBB'nin trafik hızı tahmininde kullandığını anlattı. Trafik durumunu gösteren yol tabelalarının olduğu noktalardaki sensörler, açık olan Bluetooth cihazını okur. İleride geçilen bir noktada aynı cihaz tekrar okunur ve iki okuma arasındaki zaman farkından o noktaya geliş hızı hesaplanır. Bu bilgi genelde üçüncü bir veri kaynağı olarak kullanılır.

**Soru:** Bluetooth sürekli açık kaldığında (yoğun kullanılmadan) günlük pil kapasitesinin yüzde kaçını tüketir?

**Cevap:** Bir öğrenci yüzde biri geçmeyeceğini, pil kullanım listesinde bile görünmediğini söyledi. Hoca aşağı yukarı yüzde üçün altında olduğunu, cihaza ve donanıma göre değişebileceğini belirtti. Bluetooth Low Energy de geldiği için insanların eskisi gibi her şeyi kapatma alışkanlığı kalmadı ve Bluetooth genelde açık duruyor.

Bluetooth sensörleri müşteri analizinde de kullanılır. En iyi örnek mağaza ve alışveriş merkezleridir: hangi rafın önünde ne kadar vakit geçirildiği, alışveriş merkezinde hangi rotanın izlendiği analiz edilir. Merdiven akışları ya da yeni yollar değiştiğinde bazı mağazaların önünden daha az insan geçebilir; bu analizler alışveriş merkezinin tamamında dengeli bir akış oluşturmak için kullanılır.

### 4.3 İnsan odaklı yapay zekâ

Hoca konudan biraz ayrılarak yapay zekânın artık insan odaklı ihtiyaç karşılama noktasına geldiğini söyledi. Eskiden standart işler bilgisayara yaptırılıyordu; artık insan davranışları analiz edilerek değer üretilmeye çalışılıyor. Örnek olarak akıllı kıyafet kombini önerisini verdi: önümüzdeki yıllarda popüler olacak, ama henüz oturmuş çözümler yok. Borsada sanal brokerlerin (robo-danışmanların) hisse, altın ve döviz için yönlendirme yapması ve bazı durumlarda insanlara yaklaşan, hatta onları geçen başarı göstermesi gibi, kıyafet kombininde de görüntü işlemeyle renk, doku ve kumaş gibi özelliklerin analizi önem kazanacak.

## 5. Verinin Değişme Sıklığı ve Enerji Tüketimi

Sonraki slayt bağlam verisine farklı bir yaklaşım getiren dört tanım içeriyordu (ekrandan, 00:35:00):

- **Sensed (algılanan):** Sensörden doğrudan algılanan veri; örneğin sıcaklık sensörünün ölçtüğü sıcaklık. Değerler zamanla yüksek sıklıkta değişir.
- **Static (statik):** Zamanla değişmeyen bilgi; örneğin sensörün üreticisi, sensörün yetenekleri, ölçüm aralığı.
- **Profiled (profil):** Zamanla düşük sıklıkta, örneğin ayda bir değişen bilgi; örneğin sensörün konumu, sensör kimliği.
- **Derived (türetilmiş):** Birincil bağlam kullanılarak hesaplanan bilgi; örneğin iki GPS sensörüyle hesaplanan iki sensör arasındaki mesafe.

**Soru (ekrandan):** Bu dört tanımda vurgulanan ortak nokta nedir?

**Cevap:** Bir öğrenci verilerin değişme sıklığı dedi ve hoca onayladı. Uzaktaki bir IoT cihazından verinin nasıl toplanacağı, verinin değişme sıklığına göre belirlenir. Bu sıklık şartlardan kaynaklanabileceği gibi sensörün programlanmasına da bağlı olabilir: bir sensörden saniyede 100 veri alınırken başka bir sensörden 10 saniyede ya da dakikada bir veri alınabilir. Veri toplama sıklığı sensörün enerji tüketimini doğrudan etkiler: ne kadar sık veri toplanırsa sensör o kadar çok enerji tüketir.

### 5.1 Sensör az tüketse de pil neden çabuk biter?

**Soru:** Sensörün kendi enerji tüketimi düşük ama çok sık veri toplanıyor ve telefonda pil çabuk azalıyor. Bunun sebebi ne olabilir?

**Cevap:** Bir öğrenci verinin daha sık iletilmesini söyledi; hoca iletim varsa bunun doğru olduğunu, ama verinin iletilmeyip cihazda işlendiğini varsaymasını istedi. Sonraki cevaplar iki noktayı ortaya çıkardı:

1. Daha fazla veri işlendiği için işlem yükü artar.
2. Sensörden yüksek frekansta veri toplandığında yalnız sensör değil, işlemci birimi de o sıklıkta aktif olur (tek işlemci varsa).

Bu yüzden mobil teknolojilerde, özellikle telefonlarda Apple'ın öncülüğüyle, ana CPU'ya ek olarak tamamen sensörlerden sorumlu bir hareket işlemcisi (motion processor) eklendi. Sensör verisi toplanırken ana işlemci boşta (idle) bekletilmek yerine uyku moduna alınabilir. Arka planda sensörlerin sürekli izlendiği durumlarda bu ciddi enerji tasarrufu sağlar.

> **Hocanın vurgusu:** Hangi sensörü kullandığınız, hangi sıklıkta veri topladığınız ve bu verinin arka planda hangi işlemci birimi tarafından organize edildiği, telefonun ya da akıllı saatin enerji süresini doğrudan etkiler.

Hoca, ilk akıllı saatlerin bir günü zor tamamladığını, bugünkü saatlerin ise ekran sürekli açıkken bile 2-3 gün dayanabildiğini hatırlattı.

### 5.2 Telefondaki başlıca enerji tüketicileri

**Soru:** Telefon ve akıllı saatte enerji tüketimini doğrudan etkileyen işler nelerdir?

**Cevap:** Derste sırayla şunlar sayıldı:

- **Ekran:** Kullanıcının cihazı her kullanması ciddi enerji kaybıdır; ekran kullanımı en çok enerji tüketen işlerden biridir.
- **Sensör verisinin sürekli toplanması.**
- **Haberleşme (communication):** Haberleşme her zaman algılanan veriden daha fazla enerji harcar. Bu sensör ağları için de geçerlidir. Hoca kabaca, algılama için bir birim enerji harcanıyorsa haberleşmenin iki birime kadar çıkabildiğini söyledi; istisnalar dışında iletim, veri toplamaktan pahalıdır.
- **CPU'da yapılan işlem:** Skaler veriyle büyük iş yapılmaz, ama multimedya veri (video, resim) işleniyorsa hem telefonda hem sensör düğümünde çok ciddi enerji harcanır.

### 5.3 Haberleşmede enerjiyi ne belirler?

**Soru:** Haberleşmede enerji ne zaman artar, ne zaman azalır?

**Cevap:** Bir öğrenci bağlantı kurulan noktanın uzaklığını ve aradaki girişimi (interference) söyledi. Hoca, iletim enerjisinin kabaca uzaklığın karesiyle doğru orantılı düşünülebileceğini belirtti: uzaklık arttıkça tüketilen enerji artar.

> **Ek bilgi (derste anlatılmadı):** Serbest uzayda alınan güç verici-alıcı uzaklığının karesiyle ters orantılı azalır (Friis denklemi). Bu yüzden aynı alınan güç için gereken verici gücü yaklaşık $d^2$ ile artar; engelli ortamlarda yol kaybı üssü 2'den büyük olabilir.

**Soru:** Bataryanız çok azken birini aramanız gerekiyorsa aramayı nasıl ve nereden yapmalısınız?

**Cevap:** Önce protokol konuşuldu. Bir öğrenci LTE yerine yalnız ses için 2G'ye geçmeyi önerdi; hoca LTE veri aktarımına ihtiyaç yoksa bunun mantıklı olduğunu söyledi. Büyük veri gerektiğinde ise 2G ya da 3G çok daha fazla enerji tüketir, 4G'ye geçmek gerekir.

> **Hocanın vurgusu:** 2G ve 3G birim başına daha az güç tüketir, ama verinin aktarılma süresi uzadığı için toplamda daha çok enerji harcanır.

Konum konusunda iki cevap çıktı. Birincisi, kapalı alan iletişimi engelleyen bir faktördür; arama mümkün olduğunca açık bir alanda yapılmalıdır ki "beni duyuyor musun" tekrarlarıyla pil kaybedilmesin. İkincisi, en yakın baz istasyonuna yakın olunmalıdır. Telefonun az çektiği yerler pilin en çok düştüğü yerlerdir: paketlerin hedefe ulaşması için telefonun çıkış sinyalini güçlendirmesi gerekir ve bu güç telefonun kendi bataryasından harcanır.

## 6. Mobil Cihazlarda Derin Öğrenme

**Soru:** Derin öğrenme algoritmaları telefonda çalışır mı? Eskiden telefonda çalışamayacağı algısı neden vardı?

**Cevap:** Bir öğrenci YOLO nesne tespit algoritmasının mobil sürümünü gördüğünü, telefonda çalıştığını söyledi; ağların basitleştirildiğini tahmin etti. Başka bir öğrenci telefonlarda eskiden paralel hesaplama yapamayan işlemciler olduğunu, artık mobil GPU benzeri entegre devrelerin çıktığını belirtti. Hoca mobile özelleşmiş donanımların katkısını kabul etti, ama asıl noktanın başka olduğunu söyledi: derin öğrenmenin çok kaynak isteyen kısmı eğitim (training) kısmıdır.

Eğitim telefonda yapılmadığı sürece, oluşan model telefona ya da saate yüklendiğinde (deploy) iş, ağın katsayılarıyla girdilerin çarpılıp toplanması ve nöronlar üzerinden bir sonuç üretilmesinden ibarettir; bu basit aritmetiktir. Bu yüzden derin öğrenme çözümleri giyilebilir teknolojilere uyarlanırken öğrenme sunucuda yapılır, eğitilmiş model cihazda kullanılır. Bazı modellerin sık güncellenmesi gerekir; bu durumda yeniden eğitim bulutta ya da sunucuda, örneğin gece yapılır ve yeni parametreler telefona aktarılarak cihazdaki model güncellenir. Diğer öğrenme algoritmalarının karmaşıklıkları veri işleme kısmında konuşulacak.

### 6.1 Ham veri yerine türetilmiş veri

Hoca slayta dönerek özetledi: sık toplanan veriler, değişmeyen veriler, çok az değişen veriler ve elde edilen veriden yeni veri türetilerek kullanılan veriler olabilir. Örneğin arka arkaya gelen iki GPS verisini göndermek yerine aradaki farka bakılarak elde edilen veri kullanılabilir. Bunları doğru analiz etmek, bağlam algılamada ve cihazın enerji kaynaklarını verimli kullanmada dikkat edilmesi gereken en önemli noktaların başında gelir.

## 7. Bağlam Farkındalığının Seviyeleri

Aradan sonra hoca, sensörler, verinin toplanma sıklığı ve organizasyonu konuşulduktan sonra üç başlığın öne çıktığını söyledi (ekrandan, 01:00:00): kişiselleştirme (personalisation), pasif bağlam farkındalığı (passive context-awareness) ve aktif bağlam farkındalığı (active context-awareness). Slaytın notlarında her biri için bir örnek vardı:

- Kişiselleştirme: Kullanıcı akıllı evde tercih ettiği sıcaklığı ayarlar ve ısıtma sistemi bu sıcaklığı bütün odalarda korur. Slayttaki ev planında her odanın sıcaklığı farklıdır (örneğin yemek odası 19 °C, salon 21 °C, yatak odası 20 °C, kiler 16 °C, antre 17 °C).
- Pasif bağlam farkındalığı: Kullanıcı süpermarkete girdiğinde telefon ona dikkate alabileceği indirimli ürünlerin listesini gösterir.
- Aktif bağlam farkındalığı: Akıllı evde duman ve sıcaklık sensörleri bir odada yangın algılarsa sistem itfaiyeyi ve ev sahibini telefon araması gibi uygun yollarla otomatik olarak bilgilendirir.

### 7.1 Kişiselleştirme

**Soru:** Bağlam farkındalığında kişiselleştirmenin önemi nedir?

**Cevap:** Bir öğrenci herkesin bulunduğu ortamın kendine özgü olduğunu söyledi. Hoca ev ortamı örneğini verdi: kimi eve geç gelir, kimi saat beşte gelir, kimi sürekli evdedir; kimi soğuk, kimi sıcak bir ev tercih eder. Bunlar kişiye ait yaşam tercihleri ve konfor seviyeleridir. Akıllı evlerde bu yavaş yavaş başladı. Ancak bir kiracının evindeki ayarlar, yeni kiracı geldiğinde yeniden öğrenilmelidir. Bu, sürekli öğrenme konusuna bağlandı (Bölüm 8).

### 7.2 Pasif ve aktif bağlam farkındalığı

Hoca slayttaki iki resmi gösterdi: solda yanan bir oda, sağda bir süpermarket reyonu. Öğrencilerden farkı tahmin etmelerini istedi. Bir öğrenci farkı durumun değişme hızına bağladı (yangının aniden çıkması). Başka bir öğrenci pasifin ortamın aynı şartlarda kaldığını varsaydığını, aktifin ise yeni bağlamı fark edip yeni kurallara göre davrandığını tahmin etti. Hoca sorunun kolay olmadığını, farklı bakış açılarını görmek için sorduğunu söyleyip cevabı verdi:

- **Pasif bağlam farkındalığında** bağlamı algılarsınız ama olaya müdahil olmazsınız. Siz izleyicisiniz; bağlamın farkındasınız ama bir aksiyon mekanizması tasarlamazsınız. Örneğin ormanda yangın tespit edilirse oraya bir ekip yönlendirilebilir.
- **Aktif bağlam farkındalığında** bağlamı algılar ve olaya müdahil olursunuz. Yangını algılamak bir iştir; su püskürtme mekanizmasını çalıştırmak, yani bağlama karşı bir çözüm üretmek aktif bağlam farkındalığıdır. Ormandaki örnekte sulama depoları otomatik olarak devreye alınabilir. Çevresel zekâ (ambient intelligence) kavramı da hem ortamı algılamayı hem ona müdahale etmeyi içerir.

Günümüzde, maliyetli olsa da, aktif bağlam farkındalığı yapıları kurulmaya çalışılıyor. Bunun için yalnız algılama değil, algılanan bilgiyi aksiyona dönüştürecek eyleyicilerin (actuator) ve mekanik sistemlerin harekete geçirilmesi gerekir.

## 8. Sürekli Öğrenme ve Modelin Güncellenmesi

Kişiselleştirme konusunda hoca bir soru sordu: makine öğrenmesi modelleri gerçekten sürekli öğreniyor mu? Bir model eğitildikten sonra sistem öğrenmeye devam ediyor mu?

**Soru:** Eğitilmiş bir sistem öğrenmeye devam ediyor mu, yoksa modeller başka bir yolla mı güncelleniyor?

**Cevap:** Bir öğrenci, yazılım geliştirmedeki gibi mevcut modelin uymayan kısımlarının değiştirilip yeni bir model olarak çıkarıldığını düşündüğünü söyledi. Başka bir öğrenci literatürde öğrenmeye devam eden sistemler olduğunu, ama karşılaşılacak verinin öngörülemediği için ürünün uçları açık kalacağından mühendislerin bunu pek tercih etmediğini söyledi. Hoca şöyle açıkladı: insanlar hayatları boyunca sürekli veriye maruz kalır, yeni deneyimlerle kararları ve iç modelleri değişir. Oysa makinelerdeki modeller genelde pek güncellenmez. Bir model kurulur, yüzde 90 ya da 98 başarı elde edilir ve yeterli denir. Hocaya göre en büyük eksikliklerden biri, yeni veriyle sürekli beslenen, eski veriyle yeniyi birleştirip modelin ana çatısını koruyarak kendini geliştiren sistemlerin kurulmamasıdır. Genelde karar veren bir sistem kurulur, aylarca ya da yıllarca kullanılır, sonra biri yeni bir veri seti bulur ve model yeniden eğitilir.

IoT cihazlarıyla birlikte veri artık akmaya başladı; eskiden zahmetle toplanan veri setleri bundan sonra sürekli akacak. Örnekler: bankacılıkta her ay yeni dolandırıcılık türleri, ağda yeni saldırılar, yeni zararlı yazılımlar. Hocanın dolandırıcılık tespitindeki gözlemi şudur: model güncellenmezse başarısı ay ay ilerledikçe düşer. Yöntem değişiyorsa, yeni dolandırıcılık türleri ya da yeni sınıflar ortaya çıkıyorsa bu teorik olarak beklenen bir durumdur. Kişiselleştirmede de aynı durum vardır: şartlar değişince yeni verilerle model yeniden kurulmalıdır. Buradaki zorluk, önceki veri setinden hangi verilerin kalacağına ve hangilerinin ekleneceğine karar vermektir.

> **Hocanın vurgusu:** Makine öğrenmesi, öğrenmenin sürekli olduğu bir iştir. Lisans derslerinde de "öğrenmeyi öğrenen mezunlar" istendiği söylenir; makineler için de aynı ilke geçerli olmalıdır.

### 8.1 Derin öğrenme ile sığ öğrenmenin yeniden öğrenmedeki farkı

**Soru:** Derin öğrenme ile sığ (shallow) öğrenme, yani karar ağacı ve destek vektör makinesi gibi standart makine öğrenmesi algoritmaları arasında yeniden öğrenme sürecindeki temel fark nedir?

**Cevap:** Bir öğrenci, klasik makine öğrenmesinde bütün verinin yeniden verilmesi gerektiğini, derin öğrenmede ise nöronlardaki ağırlıkların zaten bir noktaya oturduğunu ve yeni veriyle yalnız güncellendiğini söyledi. Hoca bunu onayladı. Bir ağaç yeni veri geldiğinde bütün verilerle yeniden inşa edilmek zorundadır. Derin öğrenmede ise oturmuş ağırlıklar, yeni veri sisteme beslenerek hepsini baştan hesaplamaya gerek kalmadan güncellenir. Bu ciddi bir avantajdır.

Hoca, ekibinin aktivite tanıma çalışmasında rastgele orman (random forest) ile ham veri üzerinde çalışan derin öğrenmenin performansının birbirine çok yakın çıktığını hatırlattı. Yani derin öğrenme her yerde daha başarılı olmasa da güncellenebilirlik avantajı vardır. Sonuç: değişmeyen sistemler için ağaç yapıları akıllıca görünür, evrilen sistemler için yapay sinir ağları şu anda daha mantıklıdır.

> **Ek bilgi (derste anlatılmadı):** Yeni veriyle mevcut ağırlıkları güncelleyerek öğrenmeye artımlı (incremental) ya da sürekli öğrenme (continual learning) denir. Sinir ağlarında bu yaklaşımın bilinen bir riski, yeni veriye uyum sağlarken eski bilginin unutulmasıdır (catastrophic forgetting); bu yüzden eski verilerden örnekler saklanıp yeni veriyle birlikte kullanılabilir.

## 9. Bağlam Farkındalıklı Sistemlerin Özellikleri ve Yaşam Döngüsü

### 9.1 Sekiz özellik

Slayttaki listeye göre bağlam farkındalığında bağlam (ekrandan, 01:00:00):

1. Sensörler ya da sensör ağlarıyla algılanır.
2. Küçük ve kısıtlı cihazlarla algılanır.
3. Dağıtık kaynaklardan gelir.
4. Sürekli değişir.
5. Mobil nesnelerden gelir.
6. Zamansal bir karaktere sahiptir.
7. Mekânsal bir karaktere sahiptir.
8. Kusurlu ve belirsizdir.

Hoca, toplanan bilginin hatalı ve kesin olmayabileceğini, zaman zaman sistemi hataya yöneltebileceğini vurguladı. Bu özellikler bağlam ve veri sistemlerinin karakteristiğini yansıtır.

### 9.2 Yaşam döngüsü

Temel bağlam yaşam döngüsü dört aşamadan oluşur:

1. **Bağlam edinimi (context acquisition):** Veri toplanır.
2. **Bağlam modelleme (context modeling):** Toplanan veri bir modele oturtulur.
3. **Bağlam çıkarımı (context reasoning):** Modelden anlam çıkarılır.
4. **Bağlam yayma (context dissemination):** Anlamlandırılan bağlam diğer birimlerle paylaşılır.

Literatürde çalışılan alana göre tanımlanmış birçok yaşam döngüsü vardır. Hocanın sözlü olarak andıkları:

- Information Lifecycle Management: oluşturma (creation), alma (receipt), dağıtım (distribution), kullanım (use), bakım (maintenance), elden çıkarma (disposition).
- Intelligence Cycle: toplama (collection), işleme (processing), analiz (analysis), yayın (publication), geri bildirim (feedback).

<!-- BELİRSİZ: İlk beş yaşam döngüsünün listelendiği slayt karelerde yok; bu iki döngü yalnız altyazıdan alındı. -->

İkinci yaşam döngüsü slaytında şunlar yer alır (ekrandan, 01:15:00):

```text
6)  Chantzara ve Anagnostou: sense (context provider) -> process (context broker)
    -> disseminate (context broker) -> use (service provider) -> ...
7)  Ferscha ve ark.: sensing -> transformation -> representation -> rule base
    -> actuation -> ...
8)  MOSQUITO: context information discovery -> context information acquisition
    -> context information reasoning -> ...
9)  WCXMS: (context sensing -> context transmission -> context acquisition -> ...)
    -> context classification -> context handling
    -> (context dissemination -> context usage -> context deletion
        -> context request -> ...) -> context maintenance -> context disposition -> ...
10) Baldauf ve ark.: sensors -> raw data retrieval -> preprocessing
    -> storage -> application
```

Hoca 7. döngünün verinin dönüştürülmesi (transformation) aşamasını içeren farklı bir bakış açısı sunduğunu, 9. döngünün ise bağlamın silinmesi, bağlam isteği, bakım ve elden çıkarma gibi daha ayrıntılı aşamalar içerdiğini belirtti. Bu döngülerdeki terimler birbirine benzer ve zaman zaman birbirinin yerine kullanılır.

## 10. Dijital Unutma

Yaşam döngülerindeki silme ve elden çıkarma aşamaları hocayı dijital unutma (digital forgetting) kavramına getirdi. İnsan beyninde bazı anılar ve bilgiler zamanla silinip yerine yenileri yazılır. Bilgisayarda ise sabit diskteki veriyi silme kararını bugün biz kendimiz veririz. Bu kararı bilgisayara bırakmak, yani "verilerime bak, fazlalıkları ve gereksiz (redundant) olanları temizle" demek henüz yaygın değildir.

Derste, resimler üzerinde benzer bir temizleme denemesinde sistemin yalnız "bunları silebilirsin" önerisi verebildiği, silme aksiyonunu alamadığı belirtildi. Hoca bu tür mekanizmaların genelde karar destek ya da öneri sistemi olarak kaldığını, karar verici noktasına getirilemediğini söyledi. Bir başka öğrenci telefonların büyük dosyaları silme önerisini örnek verdi: 2 GB'dan büyük bir video kullanıcı için çok değerli olabilir, sistemin bunu doğrudan silmesi istenmez; geçici klasörlerin silinmesi ise yapılabilir.

Hocaya göre IoT cihazları o kadar çok veri üretecek ki bu veriyi birinin temizlemesi gerekecek; bulaşık makinesi, çamaşır makinesi gibi evdeki bütün cihazların verisini tek tek sorgu yazarak temizlemek mümkün olmayacak. Eski veri olması bir silme ölçütü olabilir. Büyük bulut depolama ve e-posta sağlayıcıları da çöp kutusundaki öğelerin 30 gün sonra silineceği gibi kurallar getirmeye başladı; dünyada dijital bilgi fazlalığı ve dijital çöp oluşuyor. Analog dönemde öğrenci işlerinin öğrenci bilgilerini belli bir süre saklayıp sonra silme hakkı olması gibi, benzer kural ve düzenlemeler gelecektir.

> **Hocanın vurgusu:** Akıllı bir dijital unutma mekanizması tasarlamak, ciddi bir doktora araştırma konusu olabilecek kadar derin bir konudur.

## 11. Bağlam Edinimi

Bağlam edinimi, bağlamla ilgili verinin nasıl alınacağıyla ilgilidir. Slayttaki sınıflandırma şöyledir (ekrandan, 01:25:00):

- **Sorumluluğa göre (based on responsibility):** Pull ve push. Veri istenerek mi çekilecek, yoksa kaynak mı gönderecek?
- **Sıklığa göre (based on frequency):** Anlık (instant) ve aralıklı (interval) olaylar.
- **Kaynağa göre (based on source):** Sensör donanımı, ara katman (middleware), bağlam sunucuları (context servers).
- **Sensör türüne göre (based on sensor types):** Fiziksel; sanal (takvim, rehber, Twitter durumları, e-posta ve sohbet uygulamaları); mantıksal (hava durumu bilgisi).
- **Edinim sürecine göre (based on acquisition process):** Algılama (sense), türetme (derive), el ile (manually).

### 11.1 Sanal sensörler ve Twitter

Sanal sensörler, takvim ya da rehber gibi bilgi barındıran ama fiziksel olarak veri toplamayan uygulamalardır. Hoca Twitter'ın çok ciddi bir sanal sensör olduğunu söyledi.

**Soru:** Büyük miktarda tweet analiz edenler ne çıkarır?

**Cevap:** Bir öğrenci duygu analizini söyledi; hoca bunun çok yaygın olduğunu onayladı. Duygu analiziyle yalnız bireylerin değil toplulukların da o anda ne kadar saldırganlaştığı ya da kızgın olup olmadığı anlaşılabilir.

Hoca deprem, yangın ya da başka bir doğal afet anında tweetlerden nasıl faydalanılabileceğini sordu. Bir öğrenci, felaket anında haber sitelerinden önce Twitter'a bakıldığını, belirli etiketler ya da anahtar kelimelerde yoğunlaşma olduğunda bir olayın gerçekleştiğinin anlaşılabildiğini söyledi.

Hoca burada önemli bir noktaya dikkat çekti: tweetleri okurken haberlerin gerçeklik payını da değerlendiririz. Bazı haberler ajanslara düşmeden sosyal medyaya düşer ve spekülatif ya da sahte olabilir. Hoca, yakın zamandaki bir savaş sırasında sosyal medyada yayılan ve ajanslarda doğrulanmayan bir uçak düşürme haberini örnek verdi; haberin bir süre ajanslara düşmemesi doğru olmadığını gösteriyordu ve sonradan yapılan açıklamalar da bunu teyit etti.

İnsanların farklı doğrulama mekanizmaları vardır: bilgiyi birden fazla kaynaktan almak ya da güven seviyeleri (trust level) kullanmak. Şifreleme mekanizmalarındaki sertifika otoriteleri de noter gibi çalışan bir güven mekanizmasıdır.

> **Hocanın vurgusu:** Bağlam farkındalığında yaşanacak en büyük sorunlardan biri bilgiye olan güvendir, yani bilginin geçerli (valid) olması. Otomatik sistemlerle yapılan çıkarımlar teyit gerektirir ve her zaman risk barındırır.

Twitter'ın başka kullanımlarına örnek olarak hoca, bir kişinin tweetleri incelenerek intihara meyilli olup olmadığının tespit edilmeye çalışıldığı çalışmaları andı; sosyoloji ve psikoloji gibi sosyal bilimlerle temel bilimler bu konularda birlikte çalışıyor. Duygu analizi, ifadeler insanların duygularını gösterdiği için bu tür işlere olanak verir. E-postalar ve sohbet uygulamalarındaki veriler de işlenerek ilginç çıkarımlar yapılabilir.

### 11.2 Mantıksal sensörler

Mantıksal sensörler, fiziksel ya da sanal sensörlerden aldığı bilgiyi kullanıp bir çıktı üretir. Hava durumu örneğinde sıcaklık, basınç, görüş (visibility) ve yağış bilgileri birleştirilip o günkü hava tahmini paylaşılır. Kullanıcı arka plandaki hiçbir bilgiyi bilmez; havanın sıcak mı soğuk mu, yağışlı mı olacağını bilmesi yeterlidir. Bu tür mantıksal sensörler geliştirici tarafından da yaratılabilir. Edinim yalnız otomatik algılamayla değil, talep edilerek ya da el ile de yapılabilir.

## 12. Bağlam Modelleme ve Ontoloji

Bağlam modelleme, alınan verilerin hangi yapıya oturtulacağı ve nasıl saklanacağıyla ilgilidir. Slayttaki yöntemler (ekrandan, 01:30:00):

- Anahtar-değer modelleme (key-value modelling)
- İşaretleme şeması modelleme (markup scheme modelling, tagged encoding): XML, JSON, ContextML, ...
- Grafiksel modelleme (graphical modelling): UML, ORM
- Nesne tabanlı modelleme (object based modelling)
- Mantık tabanlı modelleme (logic based modelling)
- Ontoloji tabanlı modelleme (ontology based modelling)

Anahtar-değer yapısı mobil telefonlarda, örneğin Android'de çok sık kullanılır ve önemli bir esneklik sağlar. Bunun ötesinde veriler nesne formatında dosyalarda ya da SQLite gibi veritabanlarında saklanabilir. Hoca son dönemde popüler olan, Google'ın sunduğu ve F ile başlayan hizmeti sordu; öğrencilerin cevabıyla bunun Firebase olduğu söylendi. Firebase nesne yönelimli bir yapıya dayalı web tabanlı saklama modeli sunar. İşaretleme şeması tarafında XML ve JSON'un yanında ContextML gibi yeni diller vardır ve yenileri eklenecektir.

### 12.1 Ontoloji nedir?

Öğrencilerin çoğu ontoloji kavramını ilk kez duyuyordu. Hoca bir alanın ontolojisini çıkarmayı, bütün kurallarını ortaya koyarak o alanın röntgenini çekmeye benzetti. Hayvanlar aleminin ontolojisi çıkarılırken hayvanlar gruplanır: en üstte "hayvan" kavramı, altında memeliler, sürüngenler gibi gruplar yer alır ve gruplar farklılıkları öne çıkaracak şekilde kurulur. Ontoloji oluştururken modellenmek istenen yapıdaki seçeneklerin neler olduğu, nasıl gruplandığı ve birbirleriyle ilişkilerinin nasıl aktığı adlandırılır. Gerçek hayatta ontolojiye göre karar verme mekanizması oluşturmak ayrı bir kavramdır.

### 12.2 Aktivite ontolojisi

Hoca, insan aktivitelerini ontoloji tabanlı bir yapıyla tanımak için nasıl bir ontoloji kurulacağını sordu ve bir başlangıç verdi: dış ortam aktiviteleri ve iç ortam aktiviteleri. Kişinin dışarıda mı içeride mi olduğu anlaşıldığı anda aktivitelerin bir kısmı elenmiş olur. Bazı aktiviteler ortaktır, ama içeride basketbol ya da halı saha maçı oynama olasılığı çok düşüktür. İç ortam aktivitelerine bir öğrenci uykuyu örnek verdi. Dış ortam aktiviteleri hareketli ve hareketsiz olarak, ya da şöyle ayrılabilir:

```text
Aktivite
  İç ortam aktiviteleri
    (örneğin uyku)
  Dış ortam aktiviteleri
    Motorlu taşıtla yapılanlar: metrobüs, araba, minibüs, tren, uçak
    Kişinin kendi hareketleri: koşma, yürüme, durma, oturma
```

Her problem için ayrı bir ontoloji oluşturulabilir. Hoca bu kez iç/dış ortam ayrımını "cepte duran" ayrı bir ontoloji olarak bırakıp yeni bir ontoloji kurdu: basit aktiviteler ve karmaşık aktiviteler.

**Soru:** Karmaşık aktiviteleri basit aktivitelerden ayıran nedir?

**Cevap:** Bir öğrenci, adımlara ayrıldığında daha fazla adım gerektirenin karmaşık olduğunu önerdi. Hoca tanımı verdi: kendi içinde basit aktiviteler barındıran aktivitelere karmaşık aktivite denir. Basit aktiviteler (yürüme, koşma, oturma, uzanma, yatma) kendi içinde alt aktivite barındırmaz. Karmaşık aktivitelerin alt aktiviteleri vardır.

Öğrencilerden gelen örneklerle sporlar karmaşık aktiviteler altında bir alt başlık (sport activities) oldu. Ev içindeki karmaşık aktiviteler olarak yemek yeme, yemek yapma, temizlik yapma ve diş fırçalama sayıldı; bir öğrenci yemek yemenin bile uzun sürdüğü ve rutin içerdiği için karmaşık sayılabileceğini belirtti.

```text
Aktivite
  Basit aktiviteler: yürüme, koşma, oturma, uzanma, yatma
  Karmaşık aktiviteler
    Spor aktiviteleri
    Ev içi aktiviteler: yemek yeme, yemek yapma, temizlik, diş fırçalama
```

Basit aktivitelerin tanınması son on yılda çok çalışıldı ve artık büyük bir sorun değil; akıllı saatle bile rahatça tanınabiliyor. Karmaşık aktivitelerde ise hâlâ ciddi bir problem var, özellikle tek bir cihazla. Örneğin diş fırçalama telefonla anlaşılamaz; saatle anlaşılabilir, ama saat diş fırçalanan kolda değilse yine anlaşılamaz. Karmaşık aktivitelerin altında nasıl gruplama yapılacağını belirleyen bir ontoloji, analizi basitleştirip tanıma başarısını artırabilir; bu hâlâ bir araştırma konusudur. Bütün karmaşık aktiviteleri kapsayan çözümler yoktur; çalışmalar spor ya da ev içi aktiviteler gibi belirli alanlara yönelmiştir. Bağlam farkındalığı açısından hedef, bir akıllı saatin ya da telefonun gün içindeki bütün aktiviteleri anlayabilmesidir.

Hoca, ileride sistemlerin "bugün 5 dakika diş fırçaladın", "bugün şu araçta şu kadar vakit geçirdin" gibi özetler sunacağını, tıpkı kredi kartı ekstrelerinin harcamaları kategorilere ayırıp farkındalık yaratması gibi bu bilgilerin geriye dönük analiz için kullanılacağını söyledi.

## 13. Bağlam Çıkarımı ve Karar Modelleri

Bağlam çıkarımı slaytında üç iş ayrı ayrı sayılır (ekrandan, 01:40:00):

- Bağlam ön işleme (context pre-processing): ham verinin ön işlenmesi.
- Sensör verisi füzyonu (sensor data fusion): birden fazla kaynaktan gelen verinin birleştirilmesi.
- Bağlam çıkarımı (context inference): gözetimli öğrenme, gözetimsiz öğrenme, kurallar, bulanık mantık (fuzzy logic), ontolojik çıkarım ve olasılıksal çıkarım.

Hoca ön işleme ile füzyonun birbirinden ayrı işler olduğunu vurguladı. Ontolojiye göre karar veren sistemler bir anlamda kural tabanlı sistemlere benzer.

### 13.1 Yöntemlerin dağılımı

Slayttaki iki grafik bağlam çıkarımında kullanılan yöntemlerin dağılımını gösterir (ekrandan, 01:40:00). (a) Tüm uygulamalar pasta grafiği:

| Yöntem | Pay |
|---|---|
| Kurallar (rules) | %54 |
| Karar ağacı (decision tree) | %15 |
| Naive Bayes | %13 |
| Gizli Markov modelleri (HMM) | %13 |
| Destek vektör makineleri (SVM) | %4 |
| k-en yakın komşu (k-NN) | %2 |

Yüzdelerin toplamı yuvarlama nedeniyle 101'dir. (b) Tanıma uygulamaları çubuk grafiğinde en yüksek değer karar ağacındadır (yaklaşık 13); onu gizli Markov modelleri (yaklaşık 12), kurallar (yaklaşık 11), Naive Bayes (yaklaşık 9), destek vektör makineleri (yaklaşık 4) ve k-en yakın komşu (yaklaşık 1) izler. <!-- BELİRSİZ: Çubuk grafikteki değerler eksen ölçeğinden göz kararı okundu. -->

Hoca karar ağaçlarının çok yaygın olduğunu, bugün hangi konu olursa olsun rastgele orman ya da J48 gibi bir karar ağacı yapısının mutlaka kullanıldığını söyledi; kural tabanlı sistemlerin de çok sık kullanıldığını ekledi.

> **Ders sonrası not:** Hoca "en çok Decision Tree'ler var" dedi. Slayttaki pasta grafiğe göre tüm uygulamalarda en büyük pay kurallarındır (%54); karar ağacı yalnız tanıma uygulamaları grafiğinde en sık kullanılan yöntemdir.

### 13.2 Kural tabanlı sistemler ve karar ağaçları

**Soru:** Kural tabanlı sistemlerin sıkıntısı nedir?

**Cevap:** Bir öğrenci statik bir yapıya sahip olduklarını söyledi; hoca bunu onaylayıp öğrenme gibi bir faaliyetin olmadığını ekledi.

**Soru:** Kural tabanlı if-then yapısı ile listede makine öğrenmesi algoritması olarak görünen karar ağacı arasındaki fark nedir? Teknik olarak ikisi de benzer bir yapı kullanıyor.

**Cevap:** Bir öğrenci karar ağaçlarında daha hiyerarşik bir yapı olduğunu, kural tabanlı sistemlerde bütün kombinasyonların değerlendirilmesi gerekirken karar ağacının ayrıştırarak hiyerarşik ilerlediğini söyledi; hoca bunu iyi bir cevap buldu. Başka bir öğrencinin isteği üzerine hoca kural tabanlı sisteme bir örnek verdi.

Bir hava yolu şirketinin en büyük sorunlarından biri çalıntı kredi kartlarıyla bilet alınmasıdır. Hocanın anlattığı düzende bir kişi acente kurar, müşteriden bilet ücretini nakit alır (örneğin 60 lira), sonra bileti çalıntı karttan satın alıp müşteriye teslim eder; parayı cebine koymuş olur ve bilet orijinal olarak alınmıştır. Kart sahibi itiraz ettiğinde şirket parayı geri ödemek zorunda kalır (chargeback). Şirket yıllar içinde edindiği tecrübeyle belirli lokasyonlardan yapılan alımların, belirli ücret aralığındaki biletlerin, belirli destinasyonların ve belirli uçuş geçmişlerinin daha riskli olduğunu görmüş, bu kuralları tanımlamış ve zamanla güncelleyerek bugüne gelmiştir.

Bir öğrenci farkı şöyle özetledi: kural tabanlı sistemlerde insan etkisi daha fazladır, karar ağacı ise veriye göre şekillenir. Hoca bunu birinci fark olarak onayladı ve açtı:

- **Kural tabanlı sistemler** bilgi tabanlıdır (knowledge based): kurallar insanın tecrübesinden gelir ve herhangi bir veri dağılımı gözetilmeden oluşturulur.
- **Karar ağaçlarında** veri insan gözüyle değil, veri analiz araçları ya da istatistiksel modellerle incelenir. Bilgi kazancı (information gain) gibi ölçütlerden yararlanılarak en çok ayrımı sağlayan öznitelik ağacın en üstüne yerleştirilir ve aşağı doğru dallanarak hiyerarşik bir ağaç kurulur.
- Kural tabanlı sistemler de güncellenir, ama karar ağacında veri geldikçe dallanma sayısı, düğüm sayısı ve düğümlerdeki ifadeler değişebilir; bu güncellemelerle sistem öğrenmeye devam eder.

> **Ek bilgi (derste anlatılmadı):** Bilgi kazancı, bir özniteliğe göre bölme yapıldığında sınıf etiketlerinin entropisindeki azalmadır: $IG(S, A) = H(S) - \sum_{v} \frac{|S_v|}{|S|} H(S_v)$. Karar ağacı algoritmaları (ID3, C4.5 ve onun Weka sürümü J48 gibi) her düğümde bu değeri en büyük yapan özniteliği seçer.

## 14. Bağlam Farkındalığı Taksonomisi

Dersin son slaytı bağlam farkındalığı için bir taksonomi şemasıdır (ekrandan, 01:45:00). Hoca bu slaytı ayrıntısına girmeden gösterdi ve incelenmesini istedi; şema dağıtım, çıkarım, modelleme ve edinim tekniklerini tek bir resimde toplar. Şemada aşağıdan yukarıya dört katman ve sağda ortak işlevler yer alır:

- **Bağlam edinimi:** Keşif ve etiketleme (bağlam keşfi, bağlam etiketleme); veri kaynağı desteği (fiziksel sensörler, sanal ve mantıksal yazılım sensörleri, mobil cihazlar); veri işleme (filtreleme, birleştirme); edinim teknikleri (push/pull, anlık/aralıklı, doğrudan sensör, ara katman, bağlam sunucusu); veri kaynağı yönetimi; cihaz yönetimi.
- **Bağlam modelleme:** Modelleme teknikleri (anahtar-değer, işaretleme şeması, grafiksel, nesne, mantık, ontoloji tabanlı); bilgi yönetimi; veri saklama (geçmiş); çalışma zamanı yapılandırması; ön işleme (kusurlu, eski, eksik, çelişkili veriyi ele alma, eksik değer tahmini, aykırı değer tespiti); bağlam paylaşımı.
- **Bağlam çıkarımı:** Çıkarım teknikleri (gözetimli, gözetimsiz, kurallar, bulanık mantık, ontoloji tabanlı, olasılıksal mantık); olay yönetimi; bağlam kalitesi (çelişki çözümü, doğrulama); kesinlik ve belirsizlik; veri füzyonu.
- **Bağlam dağıtımı:** Dağıtım teknikleri (sorgu tabanlı, yayınla-abone ol); veri formatları; erişilebilirlik; kullanıcı istek yönetimi; tüketici yönetimi.
- **Ortak işlevler (sağ sütun):** Mimari, bağlam farkındalığı seviyesi (yüksek/yazılım, düşük/donanım), güvenlik ve mahremiyet, dinamik bileşim, gerçek zamanlı işleme, kayıt bakımı, standartlaştırma, kaynak yönetimi.

## Örnek Sorular

1. (derste sözlü, 00:08:16) RFID'nin günümüzdeki rakibi nedir ve ikisinin temel farkı nedir?

   > **Cevap (derste verildi):** QR kod. QR kod ucuz ve yaygındır ama görüş hattı gerektirir ve teker teker okunur; RFID görüş hattı gerektirmez, toplu giriş-çıkışı aynı anda yönetebilir, maliyeti pasif/aktif etiket türüne bağlıdır.

2. (ekrandan, 00:10:00) Bağlam kategorileri tablosuna göre "iki sensör arasındaki mesafenin GPS değerleriyle hesaplanması" ve "mevcut aktivite ve takvimden zamanın tahmini" hangi boyut ve hangi operasyonel kategoriye girer?

   > **Cevap (tablodan):** Birincisi konum boyutunda ikincil bağlamdır, ikincisi zaman boyutunda ikincil bağlamdır. İkisi de doğrudan okunan değil, birden fazla veriden çıkarılan bilgidir.

3. (derste sözlü, 00:19:25) Aktivite tanıma için GPS, jiroskop, ivmeölçer ve manyetometreden hangisi tercih edilmelidir?

   > **Cevap (derste verildi):** Önce ortam anlaşılır; GPS'te belli süre değişim yoksa kişi kapalı alanda ya da hareketsizdir ve daha az enerji tüketen sensörlere geçilir. Jiroskop, ivmeölçer ve manyetometrenin birlikte kullanımı en iyi sonucu verir; kapalı alanda RGB ve derinlik kameraları da kullanılır.

4. (derste sözlü, 00:25:34) Kalabalık alanlarda kamera görüntülerinden şüpheli davranış tespitinde en büyük sıkıntı nedir ve nasıl aşılır?

   > **Cevap (derste verildi):** Anormal davranış örnekleri çok azdır, sisteme kötü örnek öğretilemez. Normal davranış öğretilir ve normalden sapan durumlar anomali (aykırı değer) olarak tespit edilir.

5. (derste sözlü, 00:29:10) Bir toplu taşıma aracında kaç kişi olduğunu hangi yöntemlerle bulabiliriz?

   > **Cevap (derste verildi):** Kapıda kafa sayan kamera; kart okutma (yalnız binişi gösterir); kızılötesi/ultrasonik kapı sensörleri (kalabalıkta güvenilir değil); Bluetooth ile mobil cihaz tespiti.

6. (ekrandan, 00:35:00) Sensed, static, profiled ve derived bağlam tanımlarında vurgulanan ortak nokta nedir?

   > **Cevap (derste verildi):** Verilerin değişme sıklığı. Veri toplama sıklığı sensörün ve cihazın enerji tüketimini doğrudan belirler.

7. (derste sözlü, 00:37:18) Sensörün kendi enerji tüketimi düşük olduğu halde çok sık veri toplandığında telefonun pili neden çabuk biter?

   > **Cevap (derste verildi):** Daha fazla veri işlenir ve sensör her okunduğunda işlemci de uyanır. Bu yüzden ana CPU'yu uykuda tutan, sensörlerden sorumlu bir hareket işlemcisi eklenmiştir.

8. (derste sözlü, 00:42:03) Pil çok azken arama yapmanız gerekiyorsa protokol ve konum açısından ne yapmalısınız?

   > **Cevap (derste verildi):** Yalnız ses için 2G'ye geçilebilir (büyük veride ise 2G/3G aktarım uzun sürdüğü için toplamda daha çok enerji harcar). Arama kapalı alan yerine açık alanda ve baz istasyonuna yakın, sinyalin iyi olduğu bir yerde yapılmalıdır; zayıf sinyalde telefon çıkış gücünü artırır.

9. (derste sözlü, 00:45:18) Derin öğrenme telefonda çalışır mı? Çalışamayacağı algısı neden vardı?

   > **Cevap (derste verildi):** Çalışır. Kaynak isteyen kısım eğitimdir; eğitim sunucuda yapılır, cihazda yalnız çıkarım (basit aritmetik) çalışır. Mobil GPU benzeri donanımlar da katkı sağlar.

10. (derste sözlü, 01:06:52) Yeni veri geldiğinde derin öğrenme ile karar ağacı gibi sığ öğrenme yöntemleri arasında yeniden öğrenme açısından fark nedir?

    > **Cevap (derste verildi):** Karar ağacı bütün veriyle baştan kurulmalıdır. Sinir ağının oturmuş ağırlıkları yeni veriyle güncellenebilir; bu yüzden evrilen sistemlerde sinir ağları daha uygundur.

11. (ekrandan, 01:10:00) Pasif ve aktif bağlam farkındalığı arasındaki fark nedir? Yangın örneğiyle açıklayınız.

    > **Cevap (derste verildi):** Pasifte sistem bağlamı algılar ve bildirir ama müdahale etmez (yangını tespit edip ekip yönlendirmek). Aktifte sistem eyleyicilerle müdahale eder (sulama ya da su püskürtme sistemini otomatik çalıştırmak).

12. (derste sözlü, 01:34:04) Karmaşık aktiviteyi basit aktiviteden ayıran nedir? Ev içinden karmaşık aktivite örnekleri veriniz.

    > **Cevap (derste verildi):** Karmaşık aktivite, kendi içinde basit aktiviteler (alt aktiviteler) barındıran aktivitedir. Örnekler: yemek yeme, yemek yapma, temizlik, diş fırçalama.

13. (derste sözlü, 01:39:58) Kural tabanlı if-then sistemleri ile karar ağaçları arasındaki fark nedir?

    > **Cevap (derste verildi):** Kural tabanlı sistemlerde kurallar uzman tecrübesinden, veri dağılımı gözetilmeden yazılır ve yapı statiktir. Karar ağacı veriden, bilgi kazancı gibi ölçütlerle en ayırt edici özniteliği köke koyarak kurulur ve yeni veriyle değişebilir.

## Dersin Toparlaması

Bu derste bağlam farkındalığının kavramsal çerçevesi tamamlandı. Bağlam konum, kimlik, zaman ve aktivite boyutlarında, sensörden doğrudan okunan birincil ve çıkarımla elde edilen ikincil bilgi olarak ele alındı. Verinin değişme sıklığına göre algılanan, statik, profil ve türetilmiş türleri tanımlandı; veri toplama sıklığının, haberleşmenin, ekranın ve işlem yükünün mobil cihazlardaki enerji tüketimine etkisi örneklerle tartışıldı. Derin öğrenmenin mobilde eğitim sunucuda, çıkarım cihazda olacak şekilde kullanıldığı, sinir ağlarının yeni veriyle güncellenebilmesinin evrilen sistemlerde avantaj sağladığı vurgulandı. Kişiselleştirme, pasif ve aktif bağlam farkındalığı seviyeleri, bağlam farkındalıklı sistemlerin sekiz özelliği ve edinim, modelleme, çıkarım, yayma aşamalarından oluşan yaşam döngüsü işlendi.

Edinim tarafında fiziksel, sanal ve mantıksal sensörler; modelleme tarafında anahtar-değerden ontolojiye uzanan yöntemler; çıkarım tarafında ön işleme, füzyon ve kural tabanlı sistemlerle makine öğrenmesi yöntemleri karşılaştırıldı. Aktivite tanımada ham veriye zaman alanı özniteliklerinin eklenmesinin başarıyı artırdığı söylendi; zaman, frekans ve zaman-frekans alanı özniteliklerinin ayrıntısı ve öğrenme algoritmalarının karmaşıklıkları dersin ilerleyen veri işleme haftalarında ele alınacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
