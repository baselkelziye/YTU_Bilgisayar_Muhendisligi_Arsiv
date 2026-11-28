# Ders 1 Çalışma Özeti

## Genel Konular

- Turing ve Searle: sonuç mu, süreç mi?
  - Turing'e göre bir sistemi zeki saymak için dışarıdan ölçülebilen davranışına bakmak yeter. Sistem dışarıdan bakıldığında zeki bir varlıktan ayırt edilemiyorsa, nasıl yapıldığına bakılmadan ona zeki denmelidir.
  - Searle'e (Çin Odası) göre girdiyi anlamadan yalnız kurallarla çıktı üreten bir sisteme zeki denemez. Sonuca değil sürece bakılmalıdır.
- Ned Block'un soru-cevap ağacı (ekrandan, 00:10:00)
  - X saatten kısa her mümkün söyleşinin içinde yer aldığı bir ağaç yapısı düşünülür. Belki depolanamayacak kadar büyüktür, ama elimizde olduğu varsayılır.
  - Basit kurallarla bu ağacı kullanan bir sistem Turing testini geçebilir, ama yaptığı tek şey kural işletmektir.
  - Block'un sonucu: "Zeka yalnızca soruları zeki bir insandan ayırt edilemeyen bir yolla yanıtlama yeteneği değildir. Bir davranışı zeki diye adlandırmak bu davranışın nasıl üretildiği hakkında bir önermede bulunmaktır."
- Rudolf Arnheim: yöntem sorunu
  - Zekanın çözebildiği her problemin yalnızca zeka ile çözüleceğini söyleyemeyiz. Aynı problem zeka kullanılarak da, kullanılmadan da çözülebilir.
  - Zihinsel süreçler çıktılar aracılığıyla tanımlanmadıkça (yani Turing'in görüşü kabul edilmedikçe) ya da zekanın işleyişine dair görüşümüz mekanist bir niteliğe kavuşmadıkça (insan düşüncesinin algoritması bulunmadıkça) bilgisayarların yöntemine zekice denemez.
  - Bilgisayarlar başarılı bir tepki bulunana kadar olası birçok tepki arasında körlemesine koşar; bu onları yalnızca daha hızlı yapar, daha zeki yapmaz.
- Hesaplama gücü grafiği (ekrandan, 00:15:00)
  - 1997'de çizilmiş "Evolution of Computer Power/Cost" grafiği: dikey eksende 1000 dolar başına saniyedeki milyon işlem (MIPS per \$1000, 1997 doları), yatay eksende yıl. Noktalar tek tek bilgisayarlardır (Colossus, ENIAC, UNIVAC I, IBM PC, Mac II vb.).
  - Sağ tarafta bakteri, solucan, örümcek, kertenkele, fare, maymun ve insan için "1000 dolarlık bilgisayara eşdeğer beyin gücü" basamakları ve 1965, 1975, 1985, 1995 trend çizgileri vardır.
  - Hocaya göre beyin gücünü işlem sayısıyla karşılaştırmak anlamsızdır: bilgisayarlar ayrık (dijital), beyin süreklidir; çok işlem yapabilmek zeki davranabilmek demek değildir. Grafik yalnız tarihsel bir örnek olarak gösterildi.
- YZ savunucuları: iki ekol
  - Aşağıdan yukarıya (donanımdan yazılıma): beynin fiziksel yapısı önemlidir, taklit edilmelidir. Beyin sinir ağlarından oluştuğu için yararlı makineler yapay sinir ağlarıyla üretilebilir.
  - Yukarıdan aşağıya: simgesel temsil yapılarına ve düşünme kurallarına odaklanılmalı, beynin fiziksel yapısına takılmamalı. Arama algoritmaları, mikrodünyalar, çerçeveler (frame) bu yaklaşıma aittir.
  - Benzetme: uçaklar kuş kanadından esinlenmiştir ama kanat çırparak uçmaz. Doğadaki çözümü birebir kopyalamak zorunlu değildir.
- YZ karşıtları
  - Searle: Sentaks tek başına, ne miktarda olursa olsun, semantiği ortaya çıkarmaz. Bilgisayarın simgelerin anlamına dair anlayışı yoktur; anlam yoksa zeka da yoktur.
  - Gödel teoremi ve John Lucas'ın yorumu: İnsanların doğruluğunu bildiği ama makinelerin ispatlayamadığı doğrular vardır; buna göre insan zihni her zaman makine kapasitesinin üzerinde kalacaktır.
- Turing ve Searle karşılaştırması (ekrandan, 00:20:00)
  - Turing: "Makineler düşünebilir mi?" sorusu felsefi değil deneysel bir yaklaşımla ele alınmalıdır, çünkü ilki sonuç vermez. İnsanın nasıl düşündüğünü bilmediğimiz için içerideki süreci karşılaştıracak bir şeyimiz yoktur; yalnız dışarıdan görülen davranış ölçülebilir.
  - Searle: Deneysel bir yaklaşım olamaz, çünkü bir programı takip eden şey asla düşünemez.
  - Açık soru: İnsanlar da bir programı takip ediyor olabilir mi? Böyle bir program bulunursa zeka ile yapay zeka arasındaki fark ortadan kalkar.
- YZ'nin kısa tarihi (ekrandan, 00:25:00)
  - 1943: McCulloch ve Pitts, ilk yapay nöron tasarımı (aşağıdan yukarıya yaklaşımın başlangıcı).
  - 1949: Hebbian öğrenme kuralı: iki nöron aynı anda aktif olurlarsa aralarındaki bağ güçlenir. Pavlov'un köpeği (klasik koşullanma) bu kuralın fizyolojik açıklamasıdır.
  - 1950: Turing'in makalesi. 1951: ilk yapay sinir ağı bilgisayarı (Minsky ve Edmonds).
  - 1950-1966 büyük beklentiler dönemi (ekrandan, 00:35:00): Turing 50 yıl içinde sıradan sorgulayıcıların en az yüzde 30'unun 5 dakikalık diyalogdan sonra doğru karar veremeyeceğini söyledi; 1957'de Newell ve Simon 10 yıl içinde dünya satranç şampiyonu bir bilgisayar olacağını söyledi; 1950-60 arası otomatik dil çevirisinin çok yakında olduğu düşünüldü.
  - Beklentiler neden gerçekleşmedi: dünya/sağduyu bilgisinin büyük etkisi, problemlerin karmaşıklığının üstel olması, kısıtlı dünyaların (mikrodünyalar) gerçek dünyaya model olamaması.
  - 1966-1973 biraz da gerçekler (ekrandan, 00:40:00): 1969'da Minsky ve Papert yapay sinir ağlarının birçok problem türünde başarısızlığını kanıtladı, fonlar durduruldu; 1969'da Bryson ve Ho çok katmanlı ağları keşfetti ama eğitim algoritması olmadığı için 1980'lere kadar ilgi çekmedi; otomatik çeviri sistemlerinde hüsran.
  - 1979-1990 güzel zamanlar: uzman sistemler (kural tabanlı, kısıtlı alanlarda uzmanlık), Japonya'nın Prolog temelli Fifth Generation projesi (1981-1991), Amerika ve Avrupa'nın büyük YZ yatırımları, YZ firmalarının sayısında artış.
  - Yaklaşık 1991-1995 YZ kışı (ekrandan, 00:45:00): Fifth Generation durduruldu. Yeni odak: insanların yerini tamamen alacak programlar yerine uygun problemlere YZ teknikleri uygulamak, insanları destekleyen programlar üretmek.
- Günümüz (ekrandan, 01:05:00)
  - Deep Blue 1997'de Garry Kasparov'u yendi; 2018'de Go ve StarCraft'ta da bilgisayarlar insanları yendi.
  - Sürücüsüz arabalar (DARPA yarışması, 132 mil), Mars'ta otonom robot, konuşmayı yazıya çeviren programlar, daha ileri tarihler ve daha küçük zaman aralıkları için hava tahmini.
- Kimine kolay kimine zor (ekrandan, 01:10:00 ve 01:20:00)
  - İnsanlar için zor, makineler için kolay: çok fazla veriyle işlem gerektiren görevler (lojistik ve uçuş saati planlaması, satranç gibi bilgisayar oyunları). Formal tanımlarla tüm durumlara makineler erişebilir.
  - İnsanlar için kolay, makineler için zor: sayı dizisi tamamlama, Bongard problemleri, dil anlama, resim anlama, dünya bilgisi. Ortak yön: değişkenliğin yüksek olduğu, olası tüm durumların kapsanamadığı problemler.
- Yapay zeka ve doğal zeka
  - Yapay zeka: daha kalıcı, kopyalanabilir, geniş kitlelere yayılabilir, daha ucuz, her zaman tutarlı, işleyişi belgelenebilir.
  - Doğal zeka: yaratıcı, tecrübelerini aktarabilir, adapte olabilir, bilinçli çaba olmadan modelleri öğrenir.
- Etmenler (ajanlar) (ekrandan, 01:25:00)
  - Dört yaklaşım tablosunda seçilen hedef "rasyonel hareket etmek"tir.
  - Ajan çevresini algılayıcılarıyla (sensors) algılar, eyleyicileriyle (actuators) çevreye etki eder; aradaki karar mekanizması onu rasyonel ya da irrasyonel yapar. Ajan bir robot, bir yazılım ya da bir canlı olabilir.
  - PEAS: ajan tasarlamadan önce Performans ölçütü, Ortam (Environment), Eyleyiciler (Actuators), Algılayıcılar (Sensors) belirlenir.
  - Harita çıkaran robot örneği (ekrandan, 01:30:00) ve otonom taksi sürücüsü örneği.
- Ortam özellikleri (ekrandan, 01:35:00)
  - Tamamen/kısmen gözlemlenebilir, deterministik/stokastik, epizodik/sıralı, statik/dinamik, ayrık/sürekli, tek/çok ajanlı.
  - Gerçek dünya her kriterin zor tarafındadır: kısmen gözlemlenebilir, stokastik, sıralı, dinamik, sürekli, çok ajanlı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sonuç ve süreç ayrımı
  - Bütün kavramsal tartışma (Turing, Searle, Block, Arnheim) bir sistemin zekasına sonuçtan mı süreçten mi karar verileceği sorusuna dayanır.
  - Turing süreç ölçütünü reddeder, çünkü insanın içeride nasıl düşündüğünü bilmiyoruz ve karşılaştıracak bir şey yoktur.
- Beyin gücü ile işlem gücünü karşılaştırmak anlamsızdır
  - Hoca grafiği "tamamen bir saçmalık" diye niteledi: ayrık ve sürekli sistemlerin işlem sayısı karşılaştırılamaz, işlem gücü zekayı göstermez.
- Gecikmeler donanımdan kaynaklandı
  - Satranç şampiyonunun 10 değil yaklaşık 40 yıl sonra (1997) yenilmesi, Go ve StarCraft'ın 2018'i bulması arama uzaylarının büyüklüğü ve gereken işlem gücüyle ilgilidir.
- Eğitim ve test kümesi benzerliği
  - Makineler, test örnekleri eğitim örneklerine benzer bir dağılımdan geldiğinde başarılıdır. Bongard problemleri ve mizah gibi her yeni örneğin eskilerden farklı olduğu problemler bu yüzden zordur.
- Bütün parçaların toplamından fazladır
  - Bugünkü sistemler resimdeki parçaları (insanlar, takım elbise, gülme, tartı, vücut iskeleti) bulabilir, ama sahnedeki esprinin ne olduğunu anlayamaz.
- Her ortam özelliğinde bir taraf daha kolaydır
  - Tamamen gözlemlenebilir, deterministik, epizodik, statik, ayrık ve tek ajanlı ortamlar karşıtlarından kolaydır. Gerçek dünyada çalışan ajan yapmanın zorluğu bütün kriterlerin zor tarafında olmasından gelir.

## Kısa Tekrar Notları

- Turing: davranış (sonuç) yeter. Searle, Block, Arnheim: süreç de önemlidir.
- Ned Block: bütün diyalogları içeren ağaç Turing testini geçer ama zeki değildir.
- Arnheim: zekayla çözülebilen her problem yalnız zekayla çözülmez.
- Aşağıdan yukarıya: yapay sinir ağları. Yukarıdan aşağıya: simgesel temsil, arama.
- Searle: sentaks semantiği doğurmaz. Lucas: Gödel'e dayanarak insan zihni makineden üstündür.
- 1943 McCulloch-Pitts nöronu, 1949 Hebb kuralı, 1950 Turing makalesi, 1951 Minsky-Edmonds.
- 1950-1966 büyük beklentiler, 1966-1973 gerçekler (Minsky-Papert, XOR), 1979-1990 uzman sistemler ve Fifth Generation, yaklaşık 1991-1995 YZ kışı.
- 1997 Deep Blue, 2018 Go ve StarCraft.
- Makineler için kolay: çok veriyle rutin işlem, formal tanımlı oyunlar. Zor: değişkenliği yüksek, tüm durumları kapsanamayan problemler.
- $1, 4, 9, 61, ?$ dizisinde kareler ters yazılır: $52, 63, \dots$
- PEAS: Performans, Ortam, Eyleyiciler, Algılayıcılar.
- Ortam özellikleri ajan tasarımını büyük ölçüde etkiler; gerçek dünya en zor ortam türüdür.

## Detaylı Açıklamalar

- Ned Block ve Arnheim'ın itirazı
  - Block'un düşünce deneyinde iki insan arasında belli bir süre içinde geçebilecek bütün diyaloglar bir veritabanında toplanır. "Şunu dediyse şunu de" türünden basit kurallarla çalışan bu sistem Searle'ün Çin Odası'ndaki gibi girdi-çıktı üretir ve Turing testini geçebilir. Ancak arka planda yalnız kural işlettiği için zeki sayılamaz. Arnheim de aynı yönde, bir problemin zeka kullanılmadan da çözülebileceğini, bu yüzden "problemi çözüyor mu" sorusunun zekayı adlandırmaya yetmediğini söyler. İki istisna sayar: zihinsel süreçlerin çıktılarla tanımlanmasını kabul etmek (Turing'in görüşü) ya da insan düşüncesinin işleyişini mekanist biçimde, yani bir algoritma olarak bulmak.
- Hebbian öğrenme ve Pavlov'un köpeği
  - Köpeğe önce zil çalınır, tepki olmaz. Ardından her zilden sonra yemek verilir. Bir süre sonra yemek verilmese de zilden sonra köpeğin salyası akar. Hebb'e göre zil sesiyle aktifleşen nöronlarla yemeği görünce aktifleşen nöronlar arasında önceden olmayan ya da çok zayıf olan bir bağlantı oluşur ya da güçlenir. Zil çalınınca ilk grup aktifleşir, bağlantı yoluyla ikinci grubu da tetikler, o da salya salgılatan motor nöronlara haber verir. Bu tanıma göre öğrenme nöronlar arasındaki bağlantıların değişmesidir; unutmak bağlantının zayıflaması gibi düşünülebilir. Yapay sinir ağlarında öğrenme de ağırlıkların değişimiyle tanımlanır.
- Minsky-Papert ve XOR
  - Minsky ve Papert tek katmanlı bir ağın (perceptron) XOR gibi doğrusal olmayan problemleri çözemeyeceğini gösterdi. Gizli katmanlı iki katmanlı ağların bu problemleri çözebildiği, ağırlıklar elle hesaplanarak gösterildi. Ancak rastgele ağırlıklardan başlayıp doğru ağırlıklara ulaştıracak bir eğitim algoritması yoktu. 1980'lerin ortasında geri yayılım (backpropagation) algoritmasıyla yapay sinir ağları yeniden kullanılmaya başlandı.
- Kısıtlı dünyalar
  - Ekranda bir robot kolu ve küp, prizma gibi nesneler bulunan bir simülasyonda "kırmızı küpün altındaki yeşil dikdörtgen prizmayı al, mavi üçgen prizmanın altına koy" gibi komutları anlayan bir sistem yapmak zor değildir, çünkü dünya kısıtlıdır. Aynı sistem gerçek dünyaya taşındığında çalışmaz; simülasyonda eğitilen robotların gerçek dünyada başka bir eğitime ihtiyaç duyması bunun örneğidir.
- Otonom sistemler ve değişkenlik
  - Sürücüsüz araçlar değişkenliğin az olduğu otoyollarda ve ayrılmış yollarda güvenle kullanılabilir, ama ara sokaklarda olası durumların sayısı arttıkça doğru karar vermek zorlaşır. Mars robotlarının otonom olmasının temel sebebi iletişim gecikmesidir: görüntü size ulaştığında robot çoktan bir kratere düşmüş olabilir. Hava tahmininde de değişkenliğin yüksek olduğu mevsim geçişlerinde doğru tahmin olasılığı düşer.
- Ajan ve PEAS
  - Eyleyici, ortamı etkileyen her uzantıdır: robotun tekerleri, telefonun hoparlörü, çalar saatin zili, bir yazılım için ekran. Algılayıcı göz, kulak, kamera, mikrofon, klavye, fare gibi girdilerdir. Harita çıkaran robotta performans ölçütleri haritanın doğruluğu, işlem hızı ve statik/dinamik ortamlarda çalışabilmedir; ortam duvarlar, bina içi ya da dış ortam, statik ya da dinamik engellerdir (insanlar bir görünüp kaybolan dinamik engellerdir); eyleyiciler tekerlerin yönü ve hızı ile kamera kontrolüdür; algılayıcılar lazer, sonar, kızılötesi uzaklık algılayıcıları ve kameradır (ekrandan, 01:30:00). Otonom taksi için performans güvenilir, hızlı, yasal ve konforlu sürüştür; ortam yollar, trafikteki diğer araçlar, yayalar ve müşteridir.
- Ortam özellikleri tablosu (ekrandan, 01:35:00)

| Özellik | Süreli satranç | Süresiz satranç | Taksi şoförü |
|---|---|---|---|
| Fully observable | Yes | Yes | No |
| Deterministic | Strategic | Strategic | No |
| Episodic | No | No | No |
| Static | Semi | Yes | No |
| Discrete | Yes | Yes | No |
| Single agent | No | No | No |

  - Satranç tamamen gözlemlenebilir, poker ya da okey kısmen gözlemlenebilirdir. Deterministik-stokastik ayrımı işin içinde şans olup olmadığıdır. Epizodik-sıralı ayrımı bir hareketin ilerideki durumları etkileyip etkilemediğidir: satrançta etkiler; klasik bir arama motorunda sorgular birbirinden bağımsızdır, kişiselleştirilmiş arama motorunda öncekiler sonrakileri etkiler; parmak izi tanıma sisteminde kullanımlar birbirini etkilemez. Sınırlı sayıda açıkça belirlenmiş algı ve hareket varsa ortam ayrık, sonsuzsa süreklidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
