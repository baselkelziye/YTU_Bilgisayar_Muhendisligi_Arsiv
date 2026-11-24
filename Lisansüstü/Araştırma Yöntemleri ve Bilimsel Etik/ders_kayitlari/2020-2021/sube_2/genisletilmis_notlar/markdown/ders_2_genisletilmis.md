# Ders 2 Genişletilmiş Notu: Bilgiye Erişim, İndeksler ve Dergi Kalitesi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin amacı: bilgiye erişim
- 2. Kütüphane ve elektronik kaynaklar
- 3. Proxy ve ters proxy ile uzaktan erişim
- 4. İndeks kavramı
- 5. Alanlara özgü indeksler ve mühendislik için önemli indeksler
- 6. İndeksin yazar ve dergi açısından faydası
- 7. SCI ile SCIE farkı
- 8. Doğru dergiyi bulmak
- 9. Ticarileşme, sahte dergiler ve sahte konferanslar
- 10. Açık erişim
- 11. Dergi kalitesini değerlendirmek: etki faktörü
- 12. Etki faktörünün manipülasyonu ve Journal Citation Reports
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin amacı: bilgiye erişim

Bilimsel bir araştırma yapılacağı zaman en azından bir literatür taramasına ihtiyaç vardır. Bu derste üç soru ele alınır: Literatüre nasıl ulaşılır? Taramada bulunan bilgi ve belgelerin doğruluğu ve kalitesi nasıl tartılır? Bu erişim kanallarında önemli rol oynayan indeksler nedir, ne işe yarar ve birbirinden nasıl ayrılır?

## 2. Kütüphane ve elektronik kaynaklar

Bilgiye erişimde temel kaynak kütüphanedir. Kütüphane denince ilk akla gelen kitaplardır. Slayttaki bilgiye göre üniversite kütüphanesinde 2015 faaliyet raporunda 130.301 kitap vardır ve her yıl öğretim üyelerinin ve öğrencilerin istekleri doğrultusunda yeni kitaplar alınır (ekrandan, 00:05:00).

Kütüphane aynı zamanda üniversitedeki araştırmacıların önceki çalışmalarının kaynağıdır. Slaytta toplam 9754 tez (1.508 doktora, 8.082 yüksek lisans) yazar (ekrandan, 00:05:00). Hoca, yakın zamanda yapılan bir toplantıda sözlü olarak paylaşılan bilgiye göre bu sayının 15 bine yaklaştığını söyler. Tezlerin çoğuna başka kanallardan çevrim içi erişilebilir; ama bir kısmı eski tarihli olduğu için çevrim içi bulunmayabilir. Çevrim içi olmayan bir tez kütüphaneden istenebilir.

> **Ders sonrası not:** Slayttaki parçaların toplamı $1508 + 8082 = 9590$ eder, slayttaki toplam ise 9754'tür. Aradaki fark büyük olasılıkla raporda ayrı sayılan başka tez türlerinden ya da slayttaki bir yazım farkından kaynaklanır.

Hoca, normal şartlarda taramada 1950'lere ya da 1980'lere pek bakılmadığını söyler. Bulunan yayınların kalitesine ve kabul edilebilirliğine bağlı olarak genelde son 5-10 yılın dışına çok çıkılmaz. Ama daha eski dönemde de çok önemli çalışmalar çıkabilir; araştırma yaparken bu da akılda tutulmalıdır.

Fiziksel imkânların yanında kütüphanenin elektronik olarak abone olduğu (subscription) indeksler ve dijital kütüphaneler vardır. Slayta göre bu abonelikler genelde konuma bağlıdır (ekrandan, 00:05:00). Üniversitenin bir öğrencisi bu kaynaklara erişmek istediğinde üniversite içinde olup olmadığı sorgulanır. Bunun için üniversitenin kullandığı IP adres aralığına bakılır: bağlantı bu aralıktaki bir adresten geliyorsa erişim verilir.

Abonelikler üniversitedeki bütün bölümleri ilgilendiren birçok kaynak içerir: mimarlıkla ve sağlıkla ilgili bol miktarda kaynak vardır. Bilgisayar mühendisliği açısından bakıldığında Springer'in bilgisayarla ilgili kısımları ile başka yayıncıların indeksleri ve dergileri de aboneliklere dahildir. <!-- BELİRSİZ: altyazıda "ESG'nin indeksleri" ve "IT-LOKLIN'in jörnalları" diye bozuk geçen iki yayıncı adı karede görünmüyor -->

## 3. Proxy ve ters proxy ile uzaktan erişim

Evden, iş yerinden ya da kampüs dışındaki başka bir yerden bu kaynaklara bağlanmak için kütüphane bir mekanizma kullanır: ters proxy (reverse proxy). Slaytta "kampüs dışındayken abone olunan yayınlara erişmek için (ters) proxy servisini kullanın" denir ve kurulum belgesinin kütüphanenin sitesinde olduğu gösterilir (ekrandan, 00:05:00).

### 3.1 Proxy nedir?

Proxy, kurum içinden kurumun dışına, internete doğru yapılan erişimin denetlenmesi ve hızlandırılması için kurulan bir mekanizmadır. Örneğin içerideki bir kullanıcı X sitesine eriştiğinde sayfanın bir kopyası proxy'de saklanır. Başka bir kullanıcı aynı siteye eriştiğinde sayfa yerelden sunulur ve böylece hız kazanılır. Proxy ayrıca içerideki kişilerin internet erişimini güne, saate ya da ulaştığı yere göre kısıtlamayı ya da kapatmayı da sağlar.

### 3.2 Ters proxy

Ters proxy ise dışarıdaki birini kampüsün içine almak için kullanılır. Kullanıcı kampüs dışında olsa da trafiği proxy'ye yönlenir, proxy üzerinden yeniden internete çıkar. Böylece yayıncı açısından kullanıcı sanki kampüsün içindeymiş gibi görünür. Ayarlar kütüphanenin kendi sayfasında anlatılır.

Kütüphane son dönemde kaynaklara erişim için farklı bir sistem de kullanmaya başlamıştır; bunun nasıl kullanılacağı da kütüphanenin sayfasındaki belgelerde adım adım anlatılır. <!-- BELİRSİZ: sistemin adı altyazıda "VETIS" diye geçiyor, karede görünmüyor --> Bu adımlar izlenerek kütüphanenin elektronik ortamda abone olduğu bütün bilimsel kaynaklara erişilebilir. Hoca bu adımları derste tek tek göstermez, kütüphanenin belgelerine yönlendirir.

## 4. İndeks kavramı

Elektronik kaynaklara erişim genellikle indeksler üzerinden olur. Bilimsel indeks, bir kitabın içindekiler ya da dizin kısmına benzer. Hoca masasındaki bir bilgisayar ağları kitabını örnek verir: içindekiler kısmında birinci bölüm giriş, ikinci bölüm fiziksel katman (89. sayfa), üçüncü bölüm veri bağı katmanı (193. sayfa), dördüncü bölüm ortam erişim denetimi alt katmanı (257. sayfa) diye hangi konunun nerede olduğu yazar. Bu sayede aranan bilgiye çok hızlı ulaşılır. Bilimsel indeksler de aynı işi dergiler (journal) için yapar.

İndeksler bir buluşma noktasıdır: dergiler indekse üye olur ve içeriğini indekse verir; kullanıcılar da indekse üye olur ve orada tarama yapar. Kullanıcı açısından bu, tek hamlede çok daha fazla yayında arama yapmak demektir. Dergi ya da yayıncı açısından da daha çok insana ulaşmak demektir.

Slayttaki maddeler (ekrandan, 00:10:00):

- Bir dergi bir veritabanında indekslendiğinde o veritabanının bütün kullanıcılarına hemen açılır.
  - Bazı veritabanları yalnız başlıkları, bazıları tam makaleleri, bazıları ise yalnız özeti ve/veya kaynakçayı indeksler.
- Bugün birçok özetleme ve indeksleme servisi vardır.
  - Bazıları kurumlara bağlıdır, bazılarını yayıncılar sağlar.
- Veritabanı hangi kuruma bağlı olursa olsun, dergi seçtiği veritabanına girmek için resmî olarak başvurmalıdır.

İndeksleme servisleri yalnız "şu yayınları içeriyorum, aralarında arama yapabilirsiniz" demekle sınırlı değildir; atıf sayımı gibi başka hizmetler de verir (bkz. Bölüm 6).

## 5. Alanlara özgü indeksler ve mühendislik için önemli indeksler

Bütün konuları kapsayan tek bir indeks yoktur. Belirli başlıklar için özel indeksler vardır: mühendislik, tıp ve sağlık ya da yalnız mimarlık gibi. Bazen bir indeks ana başlıklara ya da alt başlıklara ayrılır.

En bilinen indekslerden PubMed, BIOSIS ve Embase sağlıkla ilgilidir. Hocaya göre bunun temel nedeni, özellikle İkinci Dünya Savaşı sonrasında bilimsel çalışmaların sağlık alanında patlama yapmasıdır. Savaş doğrudan insan hayatıyla ilgili olduğu için ilaç ve malzemeyle ilgili çok sayıda yayın ortaya çıkmış; bu yayınların düzenlenmesi ve sınıflandırılması için indeks yapısında da önemli adımlar atılmıştır. Bu yüzden bilinen eski ve önemli indekslerin birçoğu sağlık alanındadır. Hoca bu tarihin ayrıntısının bilimsel yazım konusunda ele alınacağını söyler.

Mühendislik çalışmaları için önemli görülen üç indeks vardır:

- Science Citation Index (SCI)
- Science Citation Index Expanded (SCIE)
- Scopus

Bunların önemli sayılmasının birkaç nedeni vardır. Biri, akademik atama ve yükseltme ölçütlerinde önemli rol oynamalarıdır. Bir diğeri, özellikle SCI'nin eski ve köklü bir indeks olmasıdır.

### 5.1 Bu üç indeks arasında sıralama var mı?

Hoca, bu soru sorulmadan önce diğer grupta da hemen sorulduğunu söyler: "Bunların arasında bir önem farkı var mı, hangisi daha iyi?" Teknik olarak bu üçü arasında "bu ondan daha iyidir" denemez. İçinde düzgün ve kaliteli dergi bulunmayan bir indeks için "kötü indeks" denebilir; ama bu üç indeksin her birinde farklı açılardan önemli, popüler ve iyi dergiler vardır. Teknik olarak indeksler arasındaki farkı söyleyebilmek için içlerindeki dergileri karşılaştırmak gerekir.

## 6. İndeksin yazar ve dergi açısından faydası

Slaytta indeksin neden gerektiği iki bakış açısından verilir (ekrandan, 00:15:00).

Yazar açısından:

- Makalelerinin kaç kez atıf aldığını öğrenmek.
- h-indeksini belirlemek (slaytta kırmızıyla "h-indeksi nedir?" sorusu vardır).
- Önceki makalelere atıf yapan makaleleri bulmak. Atıf indekslemesi (citation indexing), belirli bir makaleden ya da makale grubundan başlayıp literatürde ileriye doğru bakmanın bir yoludur.

Dergi açısından (slayttaki kaynak: Journal indexing 101 başlıklı bir yazı):

- İndekslenmek derginin asıl amacına, yani geniş bir kitleye erişilebilir olmaya yardım eder.
- Erişilebilirlik, derginin kendi alanında yüksek kaliteli bilginin güvenilir kaynağı olarak itibarını artırır.
- Veritabanı taraması araştırmacıların çalışmalarında ilk yaptığı iştir ve doğal olarak bilinen veritabanlarına bakarlar. Bu yüzden alanda bilinen bir veritabanında indekslenmek derginin okur sayısını artırır.

### 6.1 Atıf ilişkisi

Bir iş yapılacağı zaman literatür taraması yapılır ve sonunda "bu çalışma bunu yapmış, şu çalışma şurayı çalışmış; biz de şu problemi şu noktaya taşıyacağız" denir. Bunu söylerken diğer çalışmaların her birine atıf yapılır. Atıfın kimden ve nereden geldiğini, kaç kişinin atıf yaptığını hesaplamak indekslerin sunduğu hizmetlerden biridir. Bunun iki faydası vardır:

- Yazar, yayınının ne kadar kabul gördüğünü, kimlerin okuyup değerlendirdiğini ve kullandığını görür.
- Bir çalışmaya atıf yapan biri normal şartlarda o konu üzerinde çalışıyordur. Böylece kendi çalışmanızı kaynak gösteren daha güncel çalışmaları arayıp tarama zahmetinden kurtulursunuz; bunlar bir anda önünüze gelir.

Dergi açısından da indeks, son kullanıcıya tek tek ulaşmaya çalışmak yerine indeksin bütün kullanıcılarına ulaşma şansı verir. Bir yayın kuruluşu, yayınlarını mümkün olduğunca çok kişiye ulaştırmak için vardır; indeks bu açıdan önemli bir rol oynar. Yazar açısından da makalenin gönderildiği derginin üye olduğu indeks çok kullanıcıya erişiyorsa yayın da çok kişiye ulaşır.

### 6.2 h-indeksi

Yazarı değerlendirirken farklı bilgiler kullanılır; h-indeksi bunlardan biridir. Yazarın yayınlarının bulunduğu indeksler h-indeksini de hesaplar. Ama h-indeksi, hangi indeksteki yayınlar kullanılarak hesaplandığına göre çok değişebilir. Bazı mekanizmalar birden fazla indeksi bir araya toplar. Bu yüzden aynı kişinin Google Scholar'daki h-indeksi ile Web of Science'taki h-indeksi farklı çıkar.

> **Ek bilgi (derste anlatılmadı):** h-indeksi, bir yazarın en az $h$ atıf almış $h$ yayını olduğu en büyük $h$ değeridir. Yayınlar atıf sayısına göre azalan sırada dizilir; sıra numarası $i$ olan yayının atıf sayısı $i$'den küçük olmayan en büyük $i$ değeri h-indeksidir. Bu tanım J. E. Hirsch'e (2005) aittir.

## 7. SCI ile SCIE farkı

SCI ve SCIE birçok ülkede farklı değerlendirilir: SCI daha kaliteli ve önemli, SCIE biraz daha zayıf sayılır. Hocaya göre gerçek tam olarak böyle değildir.

SCI daha köklü bir indekstir, çünkü ilk çıkan indekstir. Teknoloji değiştikçe ve SCI'deki dergi sayısı çok arttıkça SCIE kurulmuştur. SCI'nin tersine SCIE bu işi basılı kaynaklar, CD ve DVD yerine internet ortamında yapmak için kurulmuştur. Bugün iki indeks de internet üzerinden erişime açıktır.

Hoca bunun kendi görüşü olmadığını, indekslerin sahibi olan firmanın bir bölge müdürünün sözü olduğunu belirtir: 2010 yılında biri iki indeks arasındaki farkı sormuş, bölge müdürü de "fark kullanılan medya türündedir" diye cevap vermiştir. Bugün o fark da kalmamıştır.

> **Hocanın vurgusu:** SCI ile SCIE arasında kalite sıralaması yapmak doğru değildir; ikisinin farkı tarihsel olarak yalnız kullanılan medyaydı.

## 8. Doğru dergiyi bulmak

### 8.1 Dergi bulma araçları

Bilimsel bir çalışma yapıldıktan sonra yayın yapılacağı zaman hangi dergiye gönderileceği aranır. Bunun için birkaç araç vardır (ekrandan, 00:20:00):

- **Master Journal List:** dergilerin adları, konuları, etki faktörleri gibi bilgileri verir. Arama seçenekleri sınırlıdır: başlıktaki kelime, ISSN ve tam başlık.
- **IEEE Xplore:** IEEE'nin hem konferansları hem dergileri içeren indeksi.
- **Elsevier Journal Finder:** yalnız Elsevier dergilerini içerir.
- **Springer Journal Suggester:** Springer'in aracı. Diğerlerinden farklı olarak makalenin başlığını ve özetini alıp ona göre dergi önerir, yalnız kategoriye bakmaz. Hoca bu özelliği beğendiğini, ama aracın her zaman başarılı olmadığını, yine de iyi bir başlangıç noktası olduğunu söyler.

### 8.2 Önerilen yol

Hocaya göre izlenmesi gereken asıl yol araçlar değildir. Bir çalışma yapılıp sonuçları yayınlanacaksa bu çalışma için zaten bir literatür taraması yapılmıştır. Taramada bulunan ilgili çalışmaların hangi dergilerde yayınlandığına bakılır; o dergiler potansiyel yayın yerleridir. Araçlar üzerinden de gidilebilir; özellikle yeni ya da daha farklı dergileri görmek isteyen biri araçları kullanabilir.

Hangi yol izlenirse izlensin, sonrasında yapılması gereken adımlar vardır. Bir aracın önerdiği dergiye makale doğrudan gönderilmez:

1. Derginin kendi sayfasında amacını ve kapsamını anlatan "Aims and Scope" kısmı okunur. Burada derginin hangi tip çalışmaları kabul ettiği ve hangi konuları ilerletmek istediği uzun uzun yazılır. Çalışmanın bu kapsama girip girmediğine bakılır.
2. Kapsama girdiğinden emin olunamıyorsa ya da daha da emin olunmak isteniyorsa, dergide daha önce yayınlanmış yayınlar arasında yapılan çalışmaya benzer kaç yayın olduğuna bakılır.
3. Bundan sonra makalenin o dergiye gönderilip gönderilmeyeceğine karar verilir.

### 8.3 Bu kadar incelemeye gerek var mı?

Hoca bu soruyu kendisi sorar ve "var" diye cevaplar. Bir dergiye makale gönderildiğinde ilk adımda makale editörün önüne düşer. Editör çalışmanın dergiyle ilgisi olmadığına karar verirse makaleyi doğrudan reddeder. Hoca bunu şöyle canlandırır: makaleyi gönderirsiniz, içeceğinizden bir yudum alırsınız, bitince doldurmaya gidersiniz, geri geldiğinizde ret e-postası gelmiştir. Bunu yaşamamak için yukarıdaki adımlar mutlaka yapılmalıdır. Dergi süreçleri ileride ayrıca ele alınacaktır.

## 9. Ticarileşme, sahte dergiler ve sahte konferanslar

### 9.1 Yayıncılığın ticarileşmesi

Hocaya göre bilimsel araştırma ve bu araştırmaların sonucu olan yayınlar son on yılda ciddi biçimde ticarileşmiştir. Eskiden bazı yayıncılarda süreç şöyle işlerdi: özellikle üniversitede çalışan bir araştırmacı makale gönderdiğinde herhangi bir ücret ödemesi gerekmezdi. Yayıncı "Bu çalışma için bir proje desteği aldıysanız, bu yayının maliyeti örneğin bin dolardır; bunu destek kapsamında öderseniz seviniriz, ödeyemezseniz de sorun değil" derdi. <!-- BELİRSİZ: bu örnekte adı geçen yayıncılar altyazıda "I-Tropi, E-SVR ve Dünya" diye bozuk geçiyor; karede görünmüyor -->

Yayın sayısı akademik atama ve yükseltme ölçütü olarak kabul görüp her şey bunun etrafında dönmeye başlayınca çok sayıda dergi, indeks ve yapı ortaya çıktı ve bu sistemi kötüye kullanmaya (abuse) başladı. Normal bir yayın süreci uzundur: araştırma yapılır, sonuçlar elde edilir, yayın hazırlanıp gönderilir, gönderimden sonraki değerlendirme de 3 ile 6 ay arasında başlayan bir süre alır. Bu uzun ve sancılı süreci kısaltmak isteyenlere bazı yerler e-posta atar: "Çalışmanızı bugün gönderin, hızlı (rapid) bir değerlendirme süreciyle hemen yayınlayalım." Makale gönderilir, kabul edilir, sonra duruma göre 500 dolar, 1000 dolar ya da 1000 avro istenir. Ücret ödenir ve bilimsel değeri düşük, sorunlu ya da tartışmalı yayınlar bir anda yayımlanır.

### 9.2 Slayttaki uyarılar

Slaytta "dolandırıcılıklara dikkat" başlığı altında iki madde vardır: sahte dergiler (slayttaki kaynakta sahte bilgisayar bilimi dergileri listesi gösterilir) ve oltalama (phishing) e-postaları (ekrandan, 00:25:00).

### 9.3 WASET vakası

Hiçbir bilimsel değeri olmayan yayınları kabul edip yayımlayan mekanizmalar da oluşmuştur; WASET bunlardan biridir. Slaytta bir yazarın bu yapıda 46 yayını olduğu, bir gazete haberine dayanılarak verilir (ekrandan, 00:25:00). WASET'in konferans sayfalarına bakıldığında, bu ay örneğin İstanbul'da yapılacağı söylenen bir konferansın bir sonraki ay birebir aynısının Paris'te, sonraki ay Sidney'de, sonraki ay Atina'da yapılacağı görülür. Metin, yazı tipi, her şey aynıdır; yalnız sayfanın arka planındaki şehir resimleri değişir. Slaytta aynı konferansın 2017'de Roma ve Paris için açılmış birebir aynı iki sayfasının bağlantısı verilir (ekrandan, 00:25:00). Bu konferanslar yapılmaz bile; katılımcılardan 500 ya da 1000 dolar toplanır ve akademik değeri olmayan çalışmalar yayımlanmış olur.

### 9.4 Bu durum neden herkesi ilgilendirir?

"Ben zaten akademisyen olmayacağım, buna ihtiyacım yok" denebilir. Ama bu sistem yalnız akademik yapılanmayı kirletmez, aynı zamanda bilgi kirliliği oluşturur. Asıl ihtiyaç duyulan değerli bilgi ya da makale aranırken bu kirliliğin içinden geçmek gerekir. Bu yüzden bulunan makalenin nerede ve nasıl yayımlandığı da önemlidir. Hoca, resimleri, başlığı ve özeti çok güzel olan ama içine girildiğinde hiçbir ayrıntı vermeyen, hiçbir şeyin çalışmadığı, bazı bilgilerin yanlış olduğu makalelerle karşılaştığını; bunun belli bir milletle sınırlı olmayıp her yerden çıkabildiğini anlatır.

> **Hocanın vurgusu:** Bulduğunuz makalenin hangi dergide ve nasıl yayımlandığına bakın; sahte yayın düzeni bilgi kirliliği üretir.

## 10. Açık erişim

Makalelerin yayımlandığı dergilerle ilgili dikkat edilmesi gereken bir başka nokta açık erişimdir (open access). Normalde indeksler dergileri indeksleyip makaleleri bir araya toplar ve bunları ücretli üyelikle kendilerine üye olan kişilere sunar. Sistemi yönetmek ve sürdürmek için parayı üyelikten kazanırlar.

Bazı dergiler şu modele geçmiştir: "Yayını yönetmek için gereken parayı yazardan isterim." Örneğin bir makaleyi yayımlamanın maliyeti 500 dolardır; yazar öderse makale açık erişimli olur, herkes okuyabilir. Ödemezse makale yalnız abonelerin bakabildiği bir yayın olur. Açık erişim faydalıdır ve birçok yazar parasını verip makalesinin açık erişimli olmasını tercih eder.

Ama açık erişim dergilerde de insanların hırsını kullanarak para kazanmayı hedefleyenler vardır. Hoca bir deneyi anlatır: İngilizcesi, ortaya koyduğu bilgiler ve yöntemi bakımından ciddi sorunlar içeren bir test makalesi 304 açık erişim dergiye gönderilmiş ve yarısından fazlası makaleyi kabul etmiştir. Hoca kabul sayısını 180 ya da 184 civarında hatırladığını, ama hafızasından emin olmadığını söyler.

> **Ders sonrası not:** Anlatılan deney büyük olasılıkla Science dergisinde 2013'te yayımlanan "Who's Afraid of Peer Review?" çalışmasıdır. Bu raporda 304 dergiden büyük olasılıkla 157'sinin makaleyi kabul ettiği yazar; bu da yine yarıdan fazladır.

Bu yüzden açık erişim iyi bir şeydir; ama daha önceden tanınmayan bir açık erişim dergi söz konusu olduğunda durup düşünmek gerekir.

## 11. Dergi kalitesini değerlendirmek: etki faktörü

Dergilerin kalitesini ya da geçerliliğini ölçmenin farklı yolları vardır. Bunlardan biri, Thomson'da çalışan ve SCI ile SCIE'nin içinde yer alan Eugene Garfield'ın ortaya attığı etki faktörüdür (impact factor). Garfield'ın amacı indeksteki dergileri sınıflandırmak ve bir kalite değerlendirmesine tabi tutmaktı.

### 11.1 Tanım

Hoca tanımı sözlü olarak şöyle verir: bir yılda yayımlanan makalelerin, son iki yılda yayımlanmış makalelere yaptığı atıf sayısı bulunur. Bu sayı, son iki yılda yayımlanmış makale sayısına bölünür. Yani etki faktörü, makale başına düşen ortalama atıf sayısıdır. Formül olarak (karede görünmüyor, sözlü tanımdan yazıldı):

$$IF_y = \frac{y \text{ yılında, } (y-1) \text{ ve } (y-2) \text{ yıllarında yayımlanan makalelere yapılan atıf sayısı}}{(y-1) \text{ ve } (y-2) \text{ yıllarında yayımlanan makale sayısı}}$$

### 11.2 Beş yıllık etki faktörü

Etki faktörü normalde iki yıl için hesaplanır. Sonra aynı hesabın beş yıllık sürümü de ortaya çıkmıştır: son iki yıl yerine son beş yıldaki ortalama atıf sayısına bakılır. Daha uzun vadeye bakınca derginin kararlılığı da görülür. Bazı dergilerin etki faktörü bir yıl 5, ertesi yıl 1, sonra 3, sonra 0,5, sonra 7 diye dalgalanır. Hocaya göre bunun nedeni, etki faktörünün doğası gereği üzerinde çok manipülasyon yapılabilen bir yapı olmasıdır.

> **Hocanın vurgusu:** Etki faktörü bir derginin etkisini ölçmek için kullanılan ölçütlerden biridir, ama hocaya göre başarılı ya da sağlıklı bir ölçüt değildir. Manipülasyon yöntemleri, uygulamak için değil, yapılabildiğini bilmek için anlatılır.

## 12. Etki faktörünün manipülasyonu ve Journal Citation Reports

### 12.1 Slayttaki uyarılar

Slaytta "dergilerin kalitesi nasıl değerlendirilir" başlığı altında "sahtelerine dikkat" denir ve sahte ISI indekslemesine bir örnek kaynak gösterilir. Aynı slaytta Journal Citation Reports'un eskiden Thomson Reuters tarafından yayımlandığı, Intellectual Property & Science biriminin 2017'den beri Clarivate Analytics olarak bilindiği yazar (ekrandan, 00:35:00).

### 12.2 Journal Citation Reports

Bir derginin kalitesini anlamak için başka raporlardan da faydalanılabilir. Journal Citation Reports, Thomson Reuters'ın yayımladığı bir rapordu; firma bu işin bir kısmını sonra Clarivate'e devretti. Rapor, indeksteki bütün dergilerin ne kadar yayın yaptığını, nerelere ne kadar atıf yaptığını, ne kadar atıf aldığını çok ayrıntılı verir. Hoca, raporun hazırlanmasının uzun sürdüğünü ve yıllık değil birkaç yılda bir çıktığını hatırladığını, ama bundan emin olmadığını söyler. Eskiden üniversitenin aboneliğine dahil değildi; bakabilmek için ayrı ücret gerekiyordu.

> **Ders sonrası not:** Journal Citation Reports büyük olasılıkla her yıl yayımlanır; hoca da bu konuda emin olmadığını belirtmiştir.

### 12.3 Etki faktörü nasıl manipüle edilir?

Etki faktörü bu yılın atıflarının son iki yılın makalelerine ne kadar yansıdığına bakar. Örneğin bugün yayımlanan bir makalenin 2019 ve 2020 yayınlarından kaçına atıf yaptığı sayılır. Hoca üç yol anlatır:

1. **Editörün atıf istemesi.** Derginin başındaki editör, makale gönderen herkese "Çok güzel yazmışsın, tebrikler; ama bu konuda dergimizde bazı makaleler var, bunlara atıf yapmamışsın, yaparsan iyi olur" der. Makalenin yayımlanıp yayımlanmayacağına karar veren kişi bunu söyleyince çoğu yazar doğal olarak itiraz etmeden atıfları ekler. Bu her yazara yapılırsa derginin son iki yıldaki yayınlarına yapılan atıflar hızla artar.
2. **Davetli yayın.** Bir konuda bütün dünyada otorite sayılan, popüler (magazin anlamında değil, uzmanlık anlamında) bir araştırmacı davet edilir: "Yeni çıkacak bir cildimiz, sayımız var; sizin çalışmanızı görmek isteriz." Araştırmacının gönderdiği makale değerlendirmeye bile tabi tutulmadan yayımlanır. Sonra o alanda çalışan bütün topluluğun bu makaleye atıf yapması beklenir; böylece derginin aldığı atıf sayısı artar.
3. **Popüler konulara öncelik.** Dergiler genelde belli alanlara odaklanır. Bilgisayar mühendisliğinin bütün konuları tek bir dergide toplanmaz; daha alt konulara (ör. bilgisayar ağları), onun da altına (ör. araçlar arası iletişim, tasarsız ağlar) inilebilir. Ama özellikle kapsamı geniş dergiler bir yıl derin öğrenme popülerse derin öğrenme makalelerini, ertesi yıl görüntü işleme popülerse görüntü işleme makalelerini seçebilir. Makalenin kalitesi yerine popülerliğine göre seçim yapan yerler de etki faktörünü manipüle eder.

Hoca bütün ayrıntıyı görmek isteyenler için on farklı manipülasyon yöntemi sayan, 2008'de yapılmış bir çalışmayı kaynak gösterir. Hocaya göre bu çalışmada sayılan yöntemler dergilerin gerçekte yaptıklarından derlenmiştir; yani gerçek hayat durumlarıdır. <!-- BELİRSİZ: bu çalışmanın künyesi incelenen karelerde görünmüyor -->

## Örnek Sorular

**Soru 1** (derste sözlü, 00:13:57): SCI, SCI Expanded ve Scopus arasında bir önem sırası var mı; hangisi daha iyi, hangisi daha kötü?

> **Cevap (derste verildi):** Teknik olarak bu üçü arasında net bir sıralama yapılamaz. Her birinde farklı açılardan önemli ve iyi dergiler vardır. İndeksleri karşılaştırmak için içlerindeki dergileri karşılaştırmak gerekir. SCI'nin üstün sayılması tarihsel köklülüğünden gelir; SCI ile SCIE arasındaki asıl fark başta kullanılan medyaydı ve bugün o fark da kalmamıştır.

**Soru 2** (ekrandan, 00:15:00): Slayttaki soru: "h-indeksi nedir?"

> **Çözüm (derste verilmedi):** h-indeksi, bir yazarın en az $h$ atıf almış $h$ yayını olduğu en büyük $h$ sayısıdır. Yayınlar atıf sayısına göre azalan sırada dizilir; $i$. sıradaki yayının atıf sayısı en az $i$ olduğu sürece $i$ artırılır; bu koşulu sağlayan en büyük $i$ h-indeksidir. Derste yalnız h-indeksinin indekslerce hesaplandığı ve hangi indeksin yayınlarıyla hesaplandığına göre (ör. Google Scholar ile Web of Science) farklı çıktığı söylendi.

**Soru 3** (derste sözlü, 00:23:40): Bir dergiye makale göndermeden önce kapsamı ve dergideki benzer yayınları bu kadar ayrıntılı incelemeye gerek var mı?

> **Cevap (derste verildi):** Var. Makale önce editörün önüne düşer; çalışma derginin kapsamı dışındaysa editör onu değerlendirmeye göndermeden kısa sürede reddeder. Bunu yaşamamak için önce "Aims and Scope" okunur, sonra dergide daha önce yayımlanmış benzer çalışmaların sayısına bakılır.

**Soru 4** (derste sözlü, 00:35:41): Etki faktörü nasıl manipüle edilebilir?

> **Cevap (derste verildi):** Etki faktörü son iki yılın makalelerine yapılan atıflara bakar. Bu yüzden editör yazarlardan dergideki son makalelere atıf yapmalarını isteyebilir; alanında otorite olan kişilerden değerlendirmesiz davetli makale alınıp topluluğun bunlara atıf yapması beklenebilir; ya da kapsamı geniş dergiler o yıl popüler olan konulardaki makaleleri kaliteye değil popülerliğe göre seçebilir.

## Dersin Toparlaması

Bu derste bilimsel araştırmanın ilk adımı olan literatür taramasında kaynağa nasıl erişileceği ve bulunan kaynağın nasıl değerlendirileceği ele alındı. Üniversite kütüphanesinin fiziksel ve elektronik kaynakları, aboneliklerin IP aralığına bağlı çalışması ve kampüs dışından erişim için ters proxy mekanizması anlatıldı. Ardından indeks kavramı, okur ile dergi arasındaki buluşma noktası olarak tanıtıldı; mühendislik için önemli sayılan SCI, SCIE ve Scopus arasında kesin bir kalite sıralaması olmadığı, SCI ile SCIE farkının tarihsel olarak yalnız kullanılan medya olduğu vurgulandı.

Dersin ikinci yarısında doğru dergiyi bulma yolu (ilgili çalışmaların dergileri, Aims and Scope, benzer yayınlar), yayıncılığın ticarileşmesi, sahte dergi ve konferanslar (WASET), açık erişimin iki yüzü ve etki faktörünün tanımı ile manipülasyon yolları işlendi. Ana mesaj, bir kaynağın değerinin yalnız başlığına ya da indeksine değil, nerede ve nasıl yayımlandığına bakılarak tartılması gerektiğidir. Hoca bir sonraki derste destek (araştırma fonu) programlarının ele alınacağını söyler.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
