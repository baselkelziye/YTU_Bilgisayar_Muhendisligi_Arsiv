# Ders 3 Genişletilmiş Notu: Bilgi Çıkarımı ve İstatistiksel Dil Modelleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Hayat Bilgisi Veri Tabanlarının Uygulama Alanları
- 2. Otomatik Çıkarım: Textual Entailment
- 3. Bilgi Çıkarımı Nedir?
- 4. Düzenli İfadeler (Regex)
- 5. Yazım Dilindeki Şablonlar
- 6. Öğelerine Ayrılmış Metinler
- 7. Şablonların İki Kriteri: Üretkenlik ve Güvenilirlik
- 8. Dinamik Web Sayfalarındaki HTML Şablonları
- 9. Morfolojik Çözümlemelerdeki Şablonlar: "Tüm X'ler Y'dir" Çalışması
- 10. Hayat Bilgisinde Güncel Yönler
- 11. İstatistiksel Dil Modelleri
- 12. Markov Varsayımı
- 13. Bir Öğrenci Önerisi: Aralıklı Kelime Seçimi
- 14. Bigram Modeli: 1000 Ekonomi Haberi
- 15. Sıfırlarla Başa Çıkmak: Smoothing
- 16. En Olası Dizilişi Bulmak
- 17. Dil Modellerini Değerlendirmek
- 18. Dil Modeliyle Metin Üretimi
- 19. Eğitim ve Test Kümesi Üzerine Bir Soru
- Örnek Sorular
- Dersin Toparlaması

## 1. Hayat Bilgisi Veri Tabanlarının Uygulama Alanları

Ders, geçen hafta başlanan hayat bilgisi veri tabanları bölümünün tamamlanmasıyla açıldı. Geçen hafta hayat bilgisinin ne olduğu, neden gerektiği, benzer çalışmalar, Türkçe için yapılmış veri tabanı ve CSoyun konuşulmuştu. Bu hafta önce bu veri tabanlarının nerelerde kullanıldığına, sonra bilgi çıkarımına geçildi. Slayttaki uygulama alanları şunlardır (ekrandan, 00:05:40):

- Sorgu zenginleştirme
- Metin sınıflandırma
- Soru cevaplama
- Metin anlama
- Otomatik çıkarım (Textual Entailment)
- Uzman sistemler

### 1.1 Sorgu zenginleştirme

Bir arama motoruna yapılan sorguyu düşünelim. Sorgu olduğu gibi aratılabilir; standart yol budur. Ama sorgu, hayat bilgisi veri tabanındaki bilgilerle değiştirilerek zenginleştirilebilir. Böylece kullanıcıdan alınan tek bir sorgudan birçok sorgu üretilir, hepsi ayrı ayrı gönderilir ve sonuçlar bir şekilde birleştirilir. Hoca bunun örneğini ileride soru cevaplama sistemlerinde göreceğimizi söyledi.

### 1.2 Metin sınıflandırmada veri zenginleştirme

Sınıflandırmada aynı fikir veri zenginleştirme (data augmentation) olarak karşımıza çıkar. Elimizde bir eğitim kümesi $X$ olsun. Bu kümedeki her örnekten yeni örnekler üretilir; bunlara $Y$ diyelim. Yeni eğitim kümesi $X+Y$ olur. Yeni örnek üretmek için metnin içindeki bilgiler ve hayat bilgisi veri tabanındaki bilgiler birlikte kullanılarak metin başka bir hâle getirilir.

### 1.3 Soru cevaplama

Sorgu zenginleştirmenin kaynak tarafında yapılanıdır. Bir soru $S$ olsun, cevabın arandığı kaynak da $K$ olsun (web sayfaları gibi). Bu durumda soru yerine kaynak $K$ zenginleştirilebilir.

### 1.4 Metin anlama ve ERASER veri kümesi

Metin anlama başlığı altında reasoning ya da rationalize denen çalışmalar vardır. Bu sistemler sorunun cevabını vermekle kalmaz, neden o cevabı verdiklerini de göstermeye çalışır. Hoca örnek olarak ERASER veri kümesini anlattı. Bir metin sınıflandırma problemi düşünelim. Bu veri kümesinde metnin sınıfı etiketlenmiştir, ama ek olarak metnin içinde o sınıfa girmesine sebep olan parça da işaretlenmiştir.

Slayttaki örnek bir duygu analizi cümlesidir (ekrandan, 00:20:00): "X in kalitesi iyi ama ücretleri çok fazla (-)". Cümle olumsuz etiketlenmiştir; bu etiketin sebebi "ücretleri çok fazla" parçasıdır. Hoca, cümlenin olumlu bir yanı da olduğu için bunu doğrudan olumsuz işaretlemenin pek doğru olmadığını, ama örnek olarak verdiğini söyledi. Aynı cümlede "kalitesi iyi" parçası olumlu bir şey söyler; veri kümesinde bu tür parça düzeyinde etiketler bulunur.

Hayat bilgisi burada şöyle işe yarar: eğitim kümesinde bir ifade geçiyor, test kümesinde ise onunla eş anlamlı başka bir ifade geçiyor olabilir. İşaretli parçalar veri tabanındaki bilgilerle değiştirilerek ya da genişletilerek eğitim kümesi büyütülebilir. Hoca bütün bu çalışmaları özetle, veri kümesini, kaynağı ya da soruyu hayat bilgisi veri tabanındaki bilgilerle büyütme, değiştirme ve zenginleştirme çalışmaları diye topladı.

## 2. Otomatik Çıkarım: Textual Entailment

Otomatik çıkarım, İngilizcede textual entailment diye geçer. Entailment "gerektirmek" demektir; burada metinsel gerektirme kastedilir. Bu tür veri kümelerinden biri SNLI'dır. Her örnekte iki metin vardır ve amaç bu iki metin arasındaki ilişkiyi üç sınıftan birine atamaktır. Slayttaki tanımlar şöyledir (ekrandan, 00:20:00):

- Giriş: 2 metin
- Çıkış: 3 sınıf (gerektirmek, mümkün değil, ilgisiz)
- Gerektirmek: X doğru ise Y kesinlikle doğrudur.
- Mümkün değil: X doğru ise Y kesinlikle yanlıştır.
- İlgisiz: X ile Y bağımsızdır; birinin doğru olması diğerinin doğru ya da yanlış olmasını etkilemez.

Tanımlar soyut göründüğü için hoca bir örnek üzerinden ilerledi. Slayttaki metinler:

- A: Bahçede top oynayan çocuklar var.
- B: Bahçede top oynayan insanlar var.
- C: Bahçede kimse yok.
- D: Hava çok güzel.

A ve B verildiğinde, A doğruysa B kesinlikle doğrudur; bu bir gerektirmedir. Peki B doğruysa A kesinlikle doğru mudur? Hayır, top oynayanlar çocuk olmayabilir.

**Soru:** Hangi iki metni verirsek "mümkün değil" ikilisi oluşur? **Cevap:** A-C ya da B-C. Bahçede çocuklar oynuyorsa bahçede kimse yok denemez.

Bir öğrenci "C ile D'nin aynı anda doğru olması olası, ama ona mümkün değil denmez değil mi?" diye sordu. Hoca, birinin doğru olmasının diğerini gerektirmediğini, bu yüzden bunun mümkün değil sınıfına girmediğini söyledi.

**Soru:** Gerektirme ilişkisi simetrik midir? Yani A ile B arasında gerektirme varsa, B ile A arasında da var mıdır? **Cevap:** Hayır, yoktur.

**Soru:** Mümkün değil ilişkisi simetrik midir? **Cevap:** Evet. İlgisiz ilişkisi de simetriktir.

**Soru:** X ile Y'nin bağımsız olduğu ikililer hangileridir? **Cevap:** B-D, A-D ve C-D. D'nin ("Hava çok güzel") diğerlerinin hiçbiriyle doğruluk ilişkisi yoktur. Bir öğrencinin belirttiği gibi A, B ve C kendi aralarında daha ilişkilidir.

Sistemler bu üç sınıftan hangisinin geçerli olduğunu tahmin etmeye çalışır. Hayat bilgisi veri tabanı burada nasıl kullanılır? A-B gerektirmesini görmek için "çocuklar insandır" bilgisi gerekir. Hoca bunu "çocukların üstünde ne var? İnsanlar var" diye sordu; yani çocuk kavramının üst kavramı insandır.

> **Ders sonrası not:** Slaytta "Mümkün değil" satırının yanında örnek olarak "(A-B, B-C)" yazıyor (ekrandan, 00:20:00). A-B gerektirme örneğidir; derste mümkün değil için A-C ve B-C verildi. Slayttaki "A-B" büyük olasılıkla yazım hatasıdır.

## 3. Bilgi Çıkarımı Nedir?

Hayat bilgisinin metinlerden çıkarılması, genel bilgi çıkarımının bir türüdür. Bilgi çıkarımı (information extraction) kabaca, önceden tanımlanmış ya da sistemin kendi bulduğu şablonlara uyan bilgileri metinden bulmaktır. Hoca, bu işi illa şablonla yapmak gerekmediğini, başka yollarla da yapılabileceğini, ama derste görülecek yöntemlerin şablon tabanlı olduğunu söyledi.

Slayttaki örnek metin bir haber cümlesidir: 21 yaşındaki inşaat işçisi Kazım Yaprak, evine dönerken para meselesi yüzünden tartıştığı arkadaşı Hilmi Bakır tarafından bıçaklanarak öldürülür. Bu metinden şu bilgiler çıkarılabilir (ekrandan, 00:05:40, slayt önizlemesi):

- Katil: Hilmi Bakır
- Kurban: Kazım Yaprak
- Sebep: Para
- Suç aleti: Bıçak

Bu tür metinler polis raporları, haber metinleri ya da uzman raporları olabilir.

**Soru:** Böyle bir bilgiyi çıkarabilirsek bize ne kazandırır? **Cevap:** Bir öğrenci farklı metinlerin ilişkilendirilebileceğini, örneğin aynı kişinin işlediği olayların bulunabileceğini söyledi. Hoca bunu genelleştirdi: metni yapılandırılmış (structured) bir hâle getiriyoruz. Artık bilgi veri tabanında tutulabilir, sorgulanabilir ve filtrelenebilir. Katili şu olan olaylar, kurbanın şu olduğu olaylar, X şehrinde olayların genelde hangi sebeplerle olduğu gibi raporlar üretilebilir. Bu yüzden bilgi çıkarımının pek çok uygulaması vardır.

Slayttaki temel metotlar şunlardır (ekrandan, 00:25:30, slayt önizlemesi):

- Düzenli ifadeleri (regex) kullanmak
- Yazım dilindeki şablonları kullanmak
- Öğelerine ayrılmış metinleri kullanmak
- Dinamik web sayfalarındaki tekrarlanan HTML etiketlerini kullanmak
- Morfolojik çözümlemelerdeki şablonları kullanmak

## 4. Düzenli İfadeler (Regex)

Regex, "şu biçime uyan şeyleri getir" demenin standart yoludur ve içinde epey hile yapılabilir. Bir anlamda kullanıcının uzman bilgisidir: örneğin ilanlardan bilgi çıkarmak istiyorsak, insanların ilanlarda bir şeyi nasıl yazdığına dair bir kural kümesi oluştururuz. Telefon numarası ya da e-posta adresi gibi standart biçimlerin regex'i bellidir; bunlar kolaydır.

Ev ilanları ilginç bir örnektir. İnsanlar ilanlarda uzun ifadeler yazmaz, çünkü ilan ne kadar uzunsa ücreti o kadar yüksektir. Bu yüzden kısaltma kullanırlar. Kısaltmaları da standart tutmaya çalışırlar, yoksa ilanı okuyan anlamaz. Bu kalıplar regex içinde ifade edilerek bilgi çıkarılabilir. Slayttaki örnek (ekrandan, 00:25:30):

```text
DOCUMENT:
  Capitol Hill- 1 br twnhme.
  D/W W/D. Pkg incl $675.
  3BR upper flr no gar. $995.
  (206) 999-9999 <br>

EXTRACTED DATA:
  <Bedrooms: 1  Price: 675>
  <Bedrooms: 3  Price: 995>

Extraction rule:  * (<Digit>) 'BR' * '$' (<Nmb>)
Output:           Rental {Bedrooms @1} {Price @2}

Bedroom ::= ( br || brs || bdrm || bedrooms || bedroom )
```

Kural, bir rakamdan sonra "BR" gelen ve ardından dolar işaretiyle bir sayı içeren kalıbı arar; rakamı yatak odası sayısı, sayıyı fiyat olarak çıkarır. "Bedroom" kelimesinin ilanlarda yazılabileceği farklı kısaltmalar da ayrıca tanımlanmıştır.

## 5. Yazım Dilindeki Şablonlar

Bu yöntemde bir ilişki türü için şablonlar vardır ve amaç o ilişkiye uyan ikilileri bulmaktır. Slayttaki tanım (ekrandan, 00:30:00): istenen ilişki türü için şablonlar bulup büyük metinlerde bu şablonlara uyan çiftleri çıkarmak. Örnek şablon "X ve diğer Y'ler"dir; bu "Tüm X'ler Y'dir" ilişkisine karşılık gelir.

Hoca Google'da "ve diğer" ifadesini aratmış ve sonuçları slayta koymuştu. Bir öğrenci kalıbı şöyle yorumladı: önce belirli bir şey söyleniyor, "ve diğer"den sonra daha genel bir kavram geliyor. Hoca bunu "X ve diğer Y'ler dediğimizde X ile Y arasında IsA ilişkisi vardır" diye bağladı. Sonuçlar tek tek incelendi:

- "Ses kayıtları ve diğer multimedya içeriği": ses kayıtları bir multimedya içeriğidir. Doğru.
- "Spor ve diğer aktiviteler": spor bir aktivitedir. Doğru.
- "Dergiler ve diğer periyodikler": dergiler periyodiktir. Doğru.
- "Sözleşmeler ve diğer hukuki belgeler": doğru.
- "Güzel sanatlar ve diğer konular": "güzel sanatlar bir konudur" demek pek iyi bir bilgi değildir.
- "İnşaat, Çevre, Gıda ve Diğer Mühendislikler": burada kısaltma yüzünden "gıda bir mühendisliktir" sonucu çıkar. Gıda mühendisliği vardır, ama gıda bir mühendislik değildir.
- "Canon ve Diğer Lazer Kartuşlar": "Canon bir lazer kartuşudur" çıkar. Canon'un lazer kartuşları vardır, ama Canon bir lazer kartuşu değildir.

Yani şablon her zaman doğru sonuç vermez. Asıl iş, "ve diğer" gibi iyi şablonları bulmaktır. Hoca öğrencilerin kendi denemelerini yapabileceğini söyledi.

## 6. Öğelerine Ayrılmış Metinler

Cümleleri özne, yüklem, nesne, dolaylı tümleç, zarf tümleci gibi öğelere ayırabiliyorsak neler yapabiliriz? Yüklemi "yemek" olan cümlelerin nesneleri yenilebilir diye sınıflanabilir. "İçmek" fiilinin nesneleri de içilebilir olarak görülebilir. "Şu nerede yapılır?" sorusu için ilgili fiilin dolaylı tümleçleri kullanılabilir. Böylece bir işin nerede, neden, nasıl yapıldığı gibi bilgiler bulunabilir.

Slayttaki örnek "ye" fiilinin nesnelerini yiyecek olarak sınıflandırmadır (ekrandan, 00:31:00). Hoca Google'da "yerken" aratmıştı. Sonuçlarda "yarım döner yerken", "kraker yerken", "zeytin yerken", "mantar yerken" gibi ifadeler çıkmıştır. Bir sonuç başlığında "Yerken" bir soyadı olarak geçer; hoca bunun sorun olmadığını, çünkü cümle öğelerine ayrıldığında bu kullanımın fiil olarak çıkmayacağını söyledi. "Yerken"den önceki ifadeler öğelere ayırma sonrası nesne olarak çıkıyorsa yenilebilir nesneler olarak alınabilir. Benzer şekilde "içerken" araması su, zemzem, çay, kahve ve sigara içerken gibi sonuçlar getirmiştir; buradan sigaranın içilebilen bir şey olduğu bilgisi çıkar.

## 7. Şablonların İki Kriteri: Üretkenlik ve Güvenilirlik

"Ve diğer" gibi yazım dilindeki şablonların iki kriteri vardır:

- **Üretkenlik:** Şablonun ürettiği bilgi miktarıdır. O şablonla ne kadar çok bilgi çıkarabildiğimizi gösterir.
- **Güvenilirlik:** Üretilen bilgilerin doğruluk oranıdır. Çıkarılanların yüzde kaçının doğru olduğunu gösterir.

Bu ikisi birbiriyle çelişir: bir şablon ne kadar çok şey üretirse, ürettiklerinin doğruluk oranı genelde o kadar düşer. Hoca bunun örneğini birkaç slayt sonra gösterdi (bkz. Bölüm 9).

## 8. Dinamik Web Sayfalarındaki HTML Şablonları

Dinamik web sayfaları arka tarafta bir veri tabanı kullanılarak üretilir. Bu sayfaların HTML koduna erişebiliriz ve bu kod modülerdir. Örneğin bir kitap listesi sayfasının HTML kodunda belli yapılar sürekli tekrar eder ve bu yapıların belli yerlerinde belli bilgiler bulunur. Şu etiketten başlayıp şu etikete kadar olan kısım kitabın adıdır, şundan sonraki kısım yazarın adıdır, şundan sonraki liste fiyatıdır, şundan sonraki gerçek fiyattır. Bunlar yazım dilindeki şablonlar değil, HTML kodundaki şablonlardır.

Bu yöntem web crawling'de ve RPA tarzı işlerde çok kullanılır: bir sayfaya git, bir yere tıkla, gelen sonuç sayfasındaki bir kısmı kopyala, başka bir sayfaya yaz gibi. Birçok haber sitesinden haberleri toplayıp tek bir arayüzde gösteren ya da birçok siteyi gezip en ucuz ürünü bulan bir program yazmak istiyorsanız, sayfadaki tekrarlayan kısımları inceleyip nerede başlayıp nerede bittiklerini belirlemeniz gerekir.

Alışveriş ve haber toplama robotları kabaca şöyle çalışır:

1. Her kaynak için bir bilgi çıkarım mekanizması kurulur.
2. Kullanıcının sorgusu alınır.
3. Her site için kullanıcı sorgusu siteye gönderilir, sonuç sayfası alınır ve o sayfaya o sitenin bilgi çıkarım mekanizması uygulanır. Sonuçlar kendi veri tabanına kaydedilebilir ya da doğrudan gösterilebilir.
4. Sonuçlar HTML biçimine çevrilip kullanıcıya döndürülür.

Hoca bu işi bir tür tersine mühendislik olarak niteledi: veri tabanının içindekileri, veri tabanının ürettiği sonuçlara bakarak çıkarıyoruz. İki firma iş birliği yaparsa bu mekanizmalara gerek kalmaz; B firması A firmasına bir API sunar, A firması sorgusunu doğrudan çalıştırır. Çıkar çatışması varsa, yani başkalarının bilgilerinizi kullanmasını istemiyorsanız, crawling'i zorlaştıracak filtreler koyabilirsiniz: belli sürede eşik değerinden fazla sorgu gelen adresi engellemek ya da sayfanın yapısını değiştirmek gibi. Karşı taraf da bu yüzden sürekli IP adresi değiştirmek zorunda kalır.

> **Ek bilgi (derste anlatılmadı):** RPA, Robotic Process Automation (robotik süreç otomasyonu) demektir. Bir insanın arayüz üzerinden yaptığı tekrarlı işleri (tıklama, kopyalama, form doldurma) yazılım robotlarının yapmasıdır. Hoca derste kısaltmayı hatırlamaya çalışırken "RPC, RPA mı?" diye sordu; kastedilen büyük olasılıkla budur.

## 9. Morfolojik Çözümlemelerdeki Şablonlar: "Tüm X'ler Y'dir" Çalışması

Hoca burada, vakti zamanında kendi yaptıkları bir çalışmayı anlattı (slayt başlığı: "Morfolojik çözümlemelerdeki şablonları kullanmak, Amasyalı, 2005"). Amaç, hayat bilgisi veri tabanını güçlendirmek için "Tüm X'ler Y'dir" ilişkisine sahip ikilileri otomatik bulmaktır.

### 9.1 Şablonların bulunması

Yazım dilindeki şablonlarda sorun şablonu bulmaktır. "Ve diğer" akla geldi, ama başka hangi şablonlar işe yarar? Her ilişki türü için farklı şablonlar olabilir. Ya insanlar oturup düşünecek ya da şu yapılacak:

1. Keşfetmek istediğimiz ikililerin aralarındaki ilişki türü belirlenir. Örneğin "Tüm X'ler Y'dir".
2. Bilinen X, Y ikilileri Google'da aratılır. Bu bilinen ikililere seed denir. Çalışmada 50-60 tane seed oluşturulmuştu.
3. Sonuç sayfaları ayrıştırılır ve X ile Y arasındaki şablonlar ve frekansları belirlenir.
4. En yüksek frekanslı şablonlar, yani birçok ikili arasında ortak geçenler, bu ilişki türünün şablonları olur.

"Tüm X'ler Y'dir" için bulunan şablonlar (ekrandan, 00:39:30):

- ve diğer, ler ve diğer, ve benzeri, veya diğer, türü olan, ları ve diğer, lar ve diğer
- ve her türlü, lerden biri olan, leri ve diğer, larından biri olan, lerinden biri olan, lardan biri olan, adı olan, ve her tür

Sonraki adım bu şablonları aratıp seed'de olmayan yeni ikilileri bulmaktır. Mantık oldukça basittir.

"X'in yeri Y'dir" ilişkisi için bulunan şablonlar da gösterildi (ekrandan, 00:40:00): y deki x, y de bulunan x, y de x, x y de, x y ili sınırları içerisindedir, y ili sınırlarında kalan x, y ili sınırları içinde bulunan x, y ilçesi sınırları içinde bulunan x, x y nin sınırları içerisindedir, x/y, x / y, x-y, x y ye zz km, x, y ye zz km, x (y ye zz km, x, y, x - y, x bulunduğu yer:y, y-x, x(y, x(y). Örneğin "Beşiktaş/İstanbul" ifadesi, x/y şablonunun Beşiktaş'ın İstanbul'da olduğunu doğruladığını gösterir.

### 9.2 Üretkenlik ve güvenilirlik örneği

Bu listede sorunlu kısım da görülür. Gönderdiğimiz seed'ler için bu şablonlar çıktı, ama şablonu aratınca gelen cevaplar gerçekten bu ilişkiyi sağlayacak mı?

**Soru:** "y'de bulunan x" ile "x-y" şablonlarından hangisi aratıldığında daha çok sonuç gelir? **Cevap:** Bir öğrenci "x-y daha fazla sonuç getirir, ama daha güvensiz olur" dedi; hoca onayladı. "x-y" çok daha fazla sonuç getirir, ama gelenlerin bu ilişkiye uyması konusunda sorunlar olur. Bölüm 7'deki üretkenlik-güvenilirlik çelişkisi budur: bir şablon çok şey üretebilir, ama ürettikleri çok güvenilir olmayabilir.

### 9.3 Şablonlara uygun ikililerin bulunması ve etiketlenmesi

Şablonlar aratılır, sonuç sayfalarında şablonun sağındaki ve solundaki kelimeler alınıp kaydedilir. Bulunan ikililerden örnekler (ekrandan, 00:42:10):

- kontrolör - personel, teçhizat - malzeme, kemer - teçhizat, protein - gıda, Azerbaycan - bölge, Ceyda - yardımcı, komünizm - ideoloji, delta - Gediz, kurum - Kocaelispor, fotoğrafçı - Robert
- tür - flamingo, ünite - aksesuar, bedel - masraf, din - azınlık, çelik - yapı, yem - araç, kız - sıfat, yapı - sorun, ölçü - şart

Kontrolör bir personeldir, protein bir gıdadır, komünizm bir ideolojidir; bunlar doğrudur. "Kurum - Kocaelispor" ya da "fotoğrafçı - Robert" gibi karışık sonuçlar da vardır. Daha sonra bulunan ikililerin "Tüm X'ler Y'dir" ilişkisine sahip olup olmadığı elle işaretlenmiştir.

### 9.4 Morfolojik analizle sınıflandırma

Daha rafine sonuç elde etmek için, gelen ikililerin doğru olup olmadığını anlamak üzere morfolojik analize dayanan bir mekanizma geliştirilmiştir. Slayttaki örnekler (ekrandan, 00:43:40):

```text
adamlarından biri olan OZAN
  adam : Noun+A3pl+P3sg+Abl
  OZAN : Noun+A3sg+Pnon+Nom

dualar ve her türlü ibadet
  dua    : Noun+A3pl+Pnon+Nom
  ibadet : Noun+A3sg+Pnon+Nom
```

"Adamlarından" kelimesinin çözümlemesi: isim, çoğul, üçüncü tekil iyelik, ayrılma hâli. Ek türleri ve şablon türü özellik olarak alınmış, bütün örnekler 107 boyutlu bir uzaya çevrilmiş ve bir sınıflandırıcı eğitilmiştir.

> **Ek bilgi (derste anlatılmadı):** `A3pl` üçüncü çoğul kişi (çoğul), `A3sg` üçüncü tekil kişi (tekil), `P3sg` üçüncü tekil iyelik eki, `Pnon` iyelik eki yok, `Abl` ayrılma hâli (-dan/-den), `Nom` yalın hâl demektir. Bu etiketler Türkçe için yaygın kullanılan iki düzeyli (two-level) morfolojik çözümleyicilerin etiket kümesine aittir.

### 9.5 Frekansların kullanımı ve yöntemin zayıf yönleri

Sınıflandırıcı yerine ya da onunla birlikte frekanslar kullanılabilir. Hoca bunun oldukça etkili olduğunu söyledi. Çok sayıda internet sayfası işlenince binlerce ikili elde edilir. Bu ikililerin tekrar sayıları bulunur: bu ikiliyi kaç kez buldum, kaç farklı şablondan buldum? Çok kez ve çok farklı şablondan bulunan ikililer iyi ikililer sayılabilir. Sınıflandırma başarısı %100 olmadığından frekans kullanımı zorunludur ve bu yüzden çok sayıda sayfa işlemek gerekir.

Yöntemin zayıf yönleri:

- Birden fazla kelimeden oluşan kelime grupları arasındaki ilişkiler bulunamıyor. Şablonun sağından ve solundan birer kelime almak yeterli değildir; kelimeleri segmente etmek gerekir. "Kayıtlar multimedyadır" değil, "ses kayıtları bir multimedya içeriğidir" alınmalıdır. "Güzel sanatlar", "hukuki belgeler", "lazer kartuşlar" da birlikte alınmalıdır.
- Her ilişki türüne uygulanamaz. Bazı ilişki türleri için şablon bulmak kolay, bazıları için zordur. Zıt anlamlılık, eş anlamlılık ya da sebep-sonuç ilişkilerinin şablonlarını bulmak kolay değildir. Bulunabilir, ama birbirlerine karışırlar. İlişki türüne bağlı olarak şablonun kalitesi ve kullanılabilirliği değişir.

Yine de frekans tabanlı yapılarla epey bilgi elde edilebilir.

## 10. Hayat Bilgisinde Güncel Yönler

Hoca son yaklaşımlardan biri olarak Allen Institute for Artificial Intelligence'ın (AI2) Alexandria girişimini andı. 2018'de başlamış bu girişim hayat bilgisini NELL gibi toplar, ama yalnız metinden değil görüntülerden de bilgi toplamaya çalışır.

Günümüzde derin öğrenmeyle yapılan soru cevaplama ve reasoning çalışmalarına bakılırsa ConceptNet gibi hayat bilgisi veri tabanlarının sürece katılmaya çalışıldığı görülür ve bunlar oldukça katkı sağlar. Sistemin bu bilgiyi kendi kendine öğrenmesini sağlamak oldukça güçtür. Bunun yerine, hazırda var olan veri tabanlarından gerekli bilgileri çekip (retrieve) o anki sorunun cevabını bulmakta kullanma çalışmaları vardır. Hoca, gerekli bilgiyi çekme adımının oldukça kritik olduğunu ve bunun güncel bir çalışma konusu olduğunu söyledi. Slaytta commonsense ve reasoning kaynaklarından oluşan geniş bir liste ve bölümün referansları da vardı (ekrandan, 00:50:00).

## 11. İstatistiksel Dil Modelleri

Aradan sonra yeni bölüme (Anlamsal Uzaylar) geçildi ve ilk konu istatistiksel dil modelleri oldu. Slaytın kaynağı Stanford'un dil modeli ders notlarıdır (ekrandan, 01:10:00).

### 11.1 Kullanım alanları

İstatistiksel dil modelleri bir cümlenin, bir kelime dizisinin ya da tek bir kelimenin olasılığını bulmak için kullanılır. Slayttaki örnekler (ekrandan, 01:10:00):

- **Makine çevirisi:** İki olası çeviri varsa hangisi daha olasıdır? P(taze balık aldım) > P(yeni balık aldım).
- **Yazım düzeltimi:** "Ali soan yedi" yazılmış olsun. Bunu "soğan" mı yoksa "sokan" mı yapacağız? İki adayın da düzeltme uzaklığı aynıdır ve ikisi de geçerli kelimedir. Ama P(ali soğan yedi) > P(ali sokan yedi).
- **Konuşmadan metne:** Ses sinyali iki olası metne çevrilebilir: "soğan yedim" ve "sol an yedim". İkisi de geçerli kelimelerden oluşur. Hangisinin daha olası olduğunu bulmak için dil modeli gerekir: P(soğan yedim) > P(sol an yedim).

### 11.2 İki amaç

Dil modelleri iki amaçla kullanılır:

- **Amaç 1:** Bir cümlenin olasılığını bulmak: $P(W)=P(w_1,w_2,\dots,w_n)$. Büyük $W$ cümleyi, $w_i$'ler cümleyi oluşturan token'ları (kelimeler, noktalama işaretleri vb.) gösterir.
- **Amaç 2:** Bir kelime dizisinden sonra gelecek kelimenin olasılığını bulmak: örneğin $P(w_5\mid w_1,w_2,w_3,w_4)$.

### 11.3 Bayes kuralı ve zincir kuralı

Bunları hesaplamak için Bayes kuralı hatırlatıldı: $P(A\mid B)=P(A,B)/P(B)$, buradan $P(A,B)=P(A\mid B)P(B)$. Elimizde ikiliden daha uzun diziler olduğu için bu kural zincir hâlinde açılır:

$$P(A,B,C,D)=P(A)\,P(B\mid A)\,P(C\mid A,B)\,P(D\mid A,B,C)$$

Yani $A$'nın başta gelme olasılığı, çarpı $A$'dan sonra $B$'nin gelme olasılığı, çarpı $A,B$'den sonra $C$'nin, çarpı $A,B,C$'den sonra $D$'nin gelme olasılığı. Hoca, başa bir cümle başı, sona bir cümle sonu olasılığı da eklenebileceğini, ama burada eklenmediğini belirtti.

Zincir kuralının genel hâli (ekrandan, 01:20:00):

$$P(w_1,w_2,\dots,w_n)=P(w_1)\,P(w_2\mid w_1)\,P(w_3\mid w_1,w_2)\cdots P(w_n\mid w_1,\dots,w_{n-1})$$

Örnek: P(ali, okuldan, buraya, geldi) = P(ali) · P(okuldan | ali) · P(buraya | ali, okuldan) · P(geldi | ali, okuldan, buraya).

### 11.4 Olasılığı frekansla bulmak

P(geldi | ali, okuldan, buraya) nasıl bulunur? Bir yol frekans oranıdır (ekrandan, 01:20:00):

$$P(\text{geldi}\mid\text{ali, okuldan, buraya})=\frac{\text{frekans(ali okuldan buraya geldi)}}{\text{frekans(ali okuldan buraya)}}$$

Dil modellerini hesaplamak için büyük metin derlemlerine ihtiyaç vardır. Derlemde "ali okuldan buraya geldi" kaç kez geçmiş, "ali okuldan buraya" kaç kez geçmiş, bunlara bakılır.

**Soru:** Paydaki frekans paydadakinden her zaman küçük müdür, büyük müdür? **Cevap:** Küçüktür (en fazla eşittir). Dolayısıyla sonuç 0 ile 1 arasında bir olasılıktır.

Ama bir sorun vardır. Slayttaki ifadeyle: bu yolla güvenilir değerler elde etmek için yeterli büyüklükte bir derlemimiz olmaz; çoğu frekans 0 olacaktır, çünkü dil ayrık uzayda çok seyrektir. Dört kelimelik bir dizi için bile durum zordur. Yirmi kelimelik bir dizide on dokuz kelimeden sonra yirmincinin gelme olasılığını hesaplamak için o on dokuz kelimenin derlemde aynen geçmesi gerekir. Pay da payda da 0 olursa hiçbir şey elde edilemez. Bu sorun özellikle uzun ifadelerin birebir aynısı için geçerlidir.

## 12. Markov Varsayımı

Slaytın ifadesiyle "Markov imdada yetişir" (ekrandan, 01:16:50). Markov varsayımı şunu söyler: her olasılık kendinden önceki $k$ bileşene bağlıdır. Burada $k$ 0, 1, 2, 3, 5, 10 gibi bir sayıdır.

### 12.1 k = 0

$k=0$ kabul edilirse her olasılık kendinden önceki hiçbir şeye bağlı değildir, yani her olasılık bağımsızdır:

- $P(w_1,w_2,w_3,w_4)=P(w_1)P(w_2)P(w_3)P(w_4)$
- $P(w_4\mid w_1,w_2,w_3)=P(w_4)$
- P(geldi | ali, okuldan, buraya) = P(geldi)

Burada sıfır frekans elde etme ihtimali artık düşüktür, çünkü tek kelimelerin frekanslarına bakılır ve tek kelime için frekans illa bir şey çıkar.

### 12.2 k = 1 ve k = 2

$k=1$ kabul edilirse her olasılık yalnız bir öncekine bağlıdır (ekrandan, 01:16:50):

- $P(w_1,w_2,w_3,w_4)=P(w_2\mid w_1)\,P(w_3\mid w_2)\,P(w_4\mid w_3)$
- $P(w_4\mid w_1,w_2,w_3)=P(w_4\mid w_3)$
- P(geldi | ali, okuldan, buraya) = P(geldi | buraya)

$k=2$ kabul edilirse her olasılık yalnız bir ve iki öncekine bağlıdır (yalnız ikinci öncekine değil, ikisine birden):

- $P(w_1,w_2,w_3,w_4)=P(w_3\mid w_1,w_2)\,P(w_4\mid w_2,w_3)$
- P(geldi | ali, okuldan, buraya) = P(geldi | okuldan, buraya)

$k$ değeri istendiği kadar artırılabilir.

> **Ders sonrası not:** Slayttaki $k=1$ ve $k=2$ cümle formüllerinde ilk kelimelerin kendi olasılıkları yazılmamıştır. Tam ifade $k=1$ için $P(w_1)\,P(w_2\mid w_1)\,P(w_3\mid w_2)\,P(w_4\mid w_3)$, $k=2$ için $P(w_1)\,P(w_2\mid w_1)\,P(w_3\mid w_1,w_2)\,P(w_4\mid w_2,w_3)$ olur. Hoca zincir kuralında başa cümle başı olasılığının eklenebileceğini, ama burada eklenmediğini söylemişti; slayttaki biçim büyük olasılıkla bu sadeleştirmedir.

### 12.3 k'yı artırmanın ve azaltmanın sonuçları

**Soru:** $k$ değerini artırmanın ve azaltmanın avantaj ve dezavantajları nelerdir? **Cevap:** Bir öğrenci, $k$ küçüldükçe alakasız durumlar ortaya çıkacağını, ama dizilerin sıfır çıkması sorununa düşülmeyeceğini söyledi. Hoca bunu açtı: $k$ küçükken çok daha kısa diziler aratılır. $k=2$ için en fazla 3 uzunluklu diziler aranır; Markov varsayımı olmayan standart yapıda ise $n$ uzunluklu bir dizi aranır. Kötü tarafı, alakasız şeylerin bir arada olmasına da bir miktar olasılık verilmesidir. Örneğin birlikte pek geçmeyen iki yüksek frekanslı kelime düşünelim; $k=0$'da bu iki kelimenin arka arkaya gelmesi yüksek olasılık alır.

$k=0$ için şu rahatlıkla söylenebilir: $P(A,B,C,D)=P(B,A,C,D)$. Yani bu varsayım, kelimelerin sırasının hiçbir önemi olmadığını kabul eder. Bu yüzden $k=0$ iyi bir yaklaşım değildir.

Slayttaki genel ifade şöyledir (ekrandan, 01:30:00, slayt önizlemesi): varsayım yokken

$$P(w_1,\dots,w_n)=\prod_i P(w_i\mid w_1,\dots,w_{i-1})$$

varsayım varken

$$P(w_i\mid w_1,\dots,w_{i-1})\approx P(w_i\mid w_{i-k},\dots,w_{i-1})$$

Yani kendisinden önceki yalnız $k$ tane bileşen işin içine katılır, daha öncekiler (slaytta kırmızı gösterilenler) yok sayılır.

### 12.4 Avantajlar ve dezavantajlar

Avantajları: daha az işlem ve daha az seyrek veri. $k$ küçüldükçe bunlar iyileşir.

Dezavantajı: dil, uzun bağımlılıklar içerir. Hocanın örneği: bir cümleye "Çin'e yaptığım ziyarette" diye başlıyorsunuz, sonra uzun uzun bir şeyler anlatıyorsunuz, sonunda "çok uğraştım ama bir türlü Çinceyi öğrenemedim" diyorsunuz. "Çinceyi" kelimesi kendisinden epey önceki "Çin'e" kelimesine bağlıdır. $k=2$, $k=3$ gibi bir Markov varsayımında bu yakalanamaz, çünkü hesaplamada "Çin" kelimesi hiç yer almaz.

Bu, sonraki kelimeyi tahmin etmeyle de ilgilidir. "Ali okuldan buraya"dan sonra en muhtemel kelimeyi bulmak için sözlükteki bütün kelimeler "geldi"nin yerine konur; olasılığı yüksek olanlar en muhtemel kelimelerdir. "Uğraştım ama bir türlü"den sonra "Çinceyi"nin gelme olasılığı, $k=4$ alınsa bile büyük ihtimalle yüksek çıkmaz. Onu asıl yükseltecek olan çok daha önceki "Çin'e" kelimesidir. Dolayısıyla $k$ seçimi bir ikilemdir: seçilen $k$'dan uzak bağımlılıklar hesaba katılamaz, ama $k$'ya bağlı olarak daha az işlem, daha hızlı sonuç ve daha az seyrek veri elde edilir.

## 13. Bir Öğrenci Önerisi: Aralıklı Kelime Seçimi

Bir öğrenci şunu önerdi: Markov gibi yalnız sondaki kelimeleri almak yerine, cümlenin uzunluğuna göre belli aralıklarla kelime almak. Bir parametre $a$ seçilir; $a=3$ ise her cümlenin başından, ortasından ve sonundan birer kelime alınır, $a=4$ ise cümle dörde bölünüp her çeyrekten kelime alınır. Parametre bir kez seçilir ve değişmez.

Hoca önce, dil modelinin olasılıklarının anlık hesaplanmadığını, çok fazla hesap gerektiği için önceden hesaplanıp tablolarda tutulduğunu, bu yüzden $k$'nın değişken olamayacağını hatırlattı. Sonra öneriyi tahtada 1'den 12'ye numaralı kelimelerden oluşan bir cümle üzerinde tartıştı (ekrandan, 01:30:00). Öğrenci 1., 6. ve 11. kelimeleri aldığını söyledi. Hoca, bu durumda arada kalan 2., 3., 4. kelimeler değişse bile hiçbir şeyin değişmeyeceğini, yani bunların olasılığa etkisinin kaybolacağını gösterdi. Öğrenci Markov'da da önceki kelimelerin yok sayıldığını hatırlattı. Hoca farkı açıkladı: Markov'da 5. kelimenin olasılığı 3. ve 4. kelimelere bakılarak bulunur, 2.'nin önemi yoktur; ama en yakın kelimeler her zaman hesaba katılır. 2.'yi almamak büyük sorun olmayabilir, ama hemen önceki 4.'yü almamak sorun olur.

Bu tartışmada bir de karışıklık giderildi: cümlenin olasılığını bulmak ile bir diziden sonraki kelimenin olasılığını bulmak farklı şeylerdir. "Ali okuldan buraya"dan sonra "geldi"nin olasılığı için $k=2$'de yalnız "okuldan" ve "buraya" kelimelerine bakılır; "Ali"nin hiçbir önemi yoktur.

Hoca öneriyi şöyle geliştirdi: başta bir kelime al, sonra uzunca bir ara bırak, sonra bir kelime daha al, sonra daha kısa bir ara bırak, hedefe yaklaştıkça daha sık kelime al. Yani uzaklığa bağlı örnekleme (sampling). Öğrenci uzun cümlelerde cümlenin başının da önemli olduğunu söyledi. Hoca, bağımlılığın cümle başıyla da sınırlı olmadığını, Çin örneğindeki gibi üç cümle, belki yüz kelime önceki bir kelimenin bile etkili olabileceğini ekledi. Hoca uzaklığa bağlı örnekleme gibi bir yönteme kendisinin rastlamadığını, öğrencinin bunu deneyebileceğini söyledi.

## 14. Bigram Modeli: 1000 Ekonomi Haberi

Hoca derste gösterdiği sonuçların kodlarının (MATLAB) dersin sayfasında olduğunu, MATLAB bilinmese de anlaşılacak kadar basit olduklarını söyledi.

### 14.1 Seyreklik

Slayttaki deney (ekrandan, 01:35:00): kod `dil_modeli.m`; 1000 ekonomi haberi derlem olarak alınmış; 5'ten az geçen kelimeler silinmiş; geriye yaklaşık 8000 farklı kelime kalmış. Böylece 8K × 8K'lık bir matris oluşturulmuş. Matrisin her hücresi "A'dan sonra B kaç kez geçti" sayısıdır; üçlüler yoktur, yalnız ikililer vardır.

Bu matriste $8000\times8000=64$ milyon hücre vardır ve bunların yalnız yaklaşık 140 bini sıfır değildir. Matrisin genel resmi yoğun görünür, ama bir bölgesi büyütülünce noktaların seyrek olduğu görülür (görselde nz = 135956). Yani yalnız A'dan sonra B'nin gelme olasılıklarında bile veri korkunç derecede seyrektir (sparse). A, B'den sonra C'nin gelme olasılıklarına geçilirse sıfır olmayanların oranı çok çok daha düşer. Dilin ayrık uzayda çok seyrek olması burada doğrudan görülür; her kelimeden sonra her kelime gelmez.

### 14.2 En sık takipçiler

Slayttaki örnekler (ekrandan, 01:37:40, slayt önizlemesi):

- "ekonomi"den sonra en sık geçen 5 kelime: bakanı, ve, ligi, bakanlığı, bankası.
- "para"dan sonra: politikası, cezası, ve, birimlerinin.
- "çok"tan sonra: önemli, daha, büyük, sayıda, iyi.

### 14.3 Bir cümlenin bigram olasılığı

Bigram, $k=1$, yani yalnız bir öncekinin hesaba katıldığı modeldir. Slayttaki örnek (ekrandan, 01:37:40):

$$P(\text{fuar otomotiv sektörüne önemli bir hareket getirdi}) = P(\text{otomotiv}\mid\text{fuar})\cdot P(\text{sektörüne}\mid\text{otomotiv})\cdot P(\text{önemli}\mid\text{sektörüne})\cdot P(\text{bir}\mid\text{önemli})\cdot P(\text{hareket}\mid\text{bir})\cdot P(\text{getirdi}\mid\text{hareket})$$

Her terim $P(w_i\mid w_{i-1})=fr(w_{i-1},w_i)/fr(w_{i-1})$ ile hesaplanır. Örneğin P(otomotiv | fuar) = fr(fuar otomotiv) / fr(fuar). Slayttaki tablo:

| $w_{i-1}$ | $fr(w_{i-1})$ | $fr(w_{i-1},w_i)$ | $P(w_i\mid w_{i-1})$ |
|---|---|---|---|
| fuar | 18 | 1 | 1/18 |
| otomotiv | 78 | 4 | 4/78 |
| sektörüne | 35 | 1 | 1/35 |
| önemli | 560 | 162 | 162/560 |
| bir | 3940 | 4 | 4/3940 |
| hareket | 42 | 1 | 1/42 |

(Tablonun ilk sütunu slaytta $w_i$ diye başlıklandırılmış, ama satırlar koşuldaki önceki kelimeyi gösteriyor.)

Slayttaki sonuç: Log(P(fuar otomotiv sektörüne önemli bir hareket getirdi)) = −21.2067.

Log almanın iki faydası vardır. Birincisi, çarpma toplamaya dönüşür ve işlem hızlanır. İkincisi, olasılıklar virgülden sonra çok sayıda sıfır içeren küçük sayılardır; log alınınca daha rahat sayılarla uğraşılır.

> **Ders sonrası not:** Tablodaki değerlerle doğal logaritma toplamı $\ln(1/18)+\ln(4/78)+\ln(1/35)+\ln(162/560)+\ln(4/3940)+\ln(1/42)\approx-21.29$ çıkar (python ile hesaplandı); slaytta −21.2067 yazıyor. Aradaki küçük fark büyük olasılıkla tablodaki bir frekansın yuvarlanmasından ya da aktarılmasından gelir. 10 tabanında toplam yaklaşık −9.24 olurdu; bu yüzden kullanılan logaritma büyük olasılıkla doğal logaritmadır. Hoca log almadan değerin "E−21 gibi, 0,000... bir sürü sıfır" olduğunu söyledi; doğal logaritma için gerçek değer $e^{-21.2}\approx6\times10^{-10}$ civarındadır.

## 15. Sıfırlarla Başa Çıkmak: Smoothing

Slayttaki ikinci cümle (ekrandan, 01:40:00): Log(P(fuar otomotiv sektörüne önemli **iki** hareket getirdi)) = −INF. Neden eksi sonsuz çıkıyor? Çünkü çarpımdaki olasılıklardan biri sıfırdır ("önemli iki" ya da "iki hareket" ikilisi derlemde hiç geçmemiştir). Tek bir sıfır olasılık bütün çarpımı sıfırlar; logu da eksi sonsuz olur.

Çözüm bir smoothing işlemidir. En basiti add-one estimation, diğer adıyla Laplace smoothing'dir:

$$P_{LS}(w_i\mid w_{i-1})=\frac{fr(w_{i-1},w_i)+1}{fr(w_{i-1})+V}$$

$P_{LS}$'deki L, Laplace smoothing'in L'sidir. Paya 1, paydaya $V$ eklenir; $V$ elimizdeki bütün farklı kelimelerin sayısıdır (sözlük boyutu). Paya her zaman 1 eklendiği için değer hiçbir zaman 0 olmaz ve eksi sonsuz skorlar alınmaz.

Smoothing ile sonuçlar (ekrandan, 01:40:00):

- Log(P_LS(fuar otomotiv sektörüne önemli bir hareket getirdi)) = −44
- Log(P_LS(fuar otomotiv sektörüne önemli iki hareket getirdi)) = −49

Dolayısıyla "önemli bir hareket getirdi" ifadesi, "önemli iki hareket getirdi" ifadesinden daha olasıdır. Smoothing olmadan bu iki cümle karşılaştırılamazdı.

## 16. En Olası Dizilişi Bulmak

Elimize rastgele sırada üç kelime verilmiş olsun: önemli, hareket, bir. En olası dizilişleri hangisidir? Slayttaki sonuçlar (ekrandan, 01:41:20):

| Diziliş | $\log P_{LS}$ |
|---|---|
| önemli bir hareket | −11.8570 |
| önemli hareket bir | −18.1881 |
| bir önemli hareket | −17.4616 |
| bir hareket önemli | −16.8926 |
| hareket önemli bir | −13.0944 |
| hareket bir önemli | −17.4034 |

En olası diziliş "önemli bir hareket"tir. Smoothing kullanılmasaydı dizilişlerin büyük kısmı eksi sonsuz çıkacak ve hangisinin daha olası olduğu söylenemeyecekti.

Slayttaki "bir başka uygulama" şudur: şu kelimelerle bir cümle kurun.

**Soru:** Bu kolay mıdır? **Cevap:** Bir öğrenci "model elimizdeyse kolay, en olasıyı seçeriz" dedi. Hoca bir sıkıntı olduğunu söyledi. Bir başka öğrenci Türkçede birden fazla dizilişin doğru olabileceğini belirtti; hoca bunun doğru ve kritik bir nokta olduğunu, ama asıl sorunun başka olduğunu söyledi. Üç kelime için 6 diziliş vardır. 10 kelime için $10! = 3\,628\,800$ diziliş vardır. 20 kelime için $20!$ diziliş vardır ve hepsini tek tek denemeye kalkarsanız siz ölene kadar işlem bitmez.

**Soru:** Yirmi kelimelik bir cümlenin kelimeleri karıştırılıp verilmişse, bunları sıraya dizmek için ne yapılabilir? Derste öğrencilerden gelen öneriler ve hocanın yorumları:

- Kelimeleri dörderli gruplara bölüp her grubun en olası dizilişini bulmak. Hoca, grupların sonra nasıl birleştirileceğinin ve sonucun nasıl hesaplanacağının belli olmadığını sordu.
- Kelimeleri yüklem, özne, nesne gibi gruplara ayırıp her gruptan seçmek; örneğin fiili sona sabitlemek. Hoca, bazı şeyleri sabitleyerek $20!$'den daha düşük bir sayıya inmenin olabileceğini söyledi.
- Markov varsayımından yararlanmak. Hoca bunu şöyle açtı: her kelime için önce tek başına değerlendirme yapılır, yani o kelimenin öncesine ve sonrasına hangi kelimelerin hangi olasılıkla gelebileceği bulunur; bazı olasılıklar elenir. Sonra kalanlar arasından ikililer değerlendirilir, yine bazıları elenir. Sonra üçlüler, ve böyle gide gide azalarak sonunda bütün cümleye ulaşılır. Bir öğrenci bunu "ters karar ağacı" diye niteledi.

Hoca bunun optimum bir çözüm olmadığını, küçük adımlarda bir şey kaçmasa bile daha büyük sayılarda muhtemelen bir şeylerin kaçacağını söyledi.

> **Hocanın vurgusu:** Optimal bir çözüm olmayacaktır, ama mühendislik, optimal olmayan, yeterince iyi çözümler geliştirme sanatıdır.

> **Ek bilgi (derste anlatılmadı):** Hocanın tarif ettiği, her adımda yalnız en olası kısmi çözümleri tutup diğerlerini eleyerek ilerleme yöntemi, literatürde ışın araması (beam search) olarak bilinen yaklaşıma benzer. Beam search her adımda en iyi $b$ kısmi diziyi tutar; optimumu garanti etmez, ama arama uzayını üstel büyümeden kurtarır.

Hoca öğrencileri bu tür fikirleri kendileri gerçekleyip sonuçlarını paylaşmaya teşvik etti. Fikir üretmenin çok önemli olduğunu, ama fikirleri gerçekleyip sonuçların iyi olduğunu göstermek gerektiğini söyledi.

## 17. Dil Modellerini Değerlendirmek

Elimizde iki dil modeli olsun, A ve B. Dil modeli, verilen bir cümlenin olasılığını ya da verilen kelimelerden sonra en olası kelimeyi verebilen bir sistemdir. Hangisinin daha iyi olduğunu nasıl söyleriz? Slayttaki iki yaklaşım (ekrandan, 01:50:00):

- **Harici yöntem:** Her iki model de farklı görevler için (makine çevirisi, yazım düzeltimi, konuşmadan metne) kullanılır ve bu görevlerdeki performanslarına göre karşılaştırılır. A modeli makine çevirisini B'den daha iyi yapıyorsa A daha iyidir.
- **Dahili yöntem:** Derlem eğitim ve test kümesi olarak ayrılır. A ve B eğitim kümesi üzerinden oluşturulur.
  - Test kümesindeki cümlelere hangisi daha yüksek olasılık veriyorsa o daha iyidir.
  - Bir cümlenin başı verildiğinde sonunu hangisi doğru tahmin ediyorsa o daha iyidir.
  - Bu görevlerde Markov varsayımında $k=0$ seçimi nasıldır?

Test cümleleri gerçekte olan, ama eğitim kümesinde bulunmayan cümlelerdir. İyi bir dil modelinin gerçek cümlelere yüksek, saçma sapan cümlelere düşük olasılık vermesi beklenir.

Hoca burada önemli bir uyarı yaptı: test kümesinde eğitimdeki cümleler olmamalıdır. Bu özellikle sosyal medyadan toplanan derlemlerde sorun olur. Twitter'dan veri toplarken birinin söylediği bir şeyi 50 kişi aynen tekrarlayabilir. Veri rastgele eğitim ve test diye ayrılırsa eğitimdeki cümleler test kümesinde de bulunur ve bu bir yanılsama yaratır. Eğitim ve test kümelerinin ayrık olması, yani benzer ama farklı olması bütün değerlendirmenin temel mantığıdır.

**Soru:** Bu görevlerde $k=0$ seçimi nasıldır? **Cevap:** $k=0$'da $P(A,B,C)=P(B,A,C)$ olur, yani model sıra bilgisini hiç kullanmaz; bu iyi bir dil modeli olmaz. Cümle sonunu tahmin etme görevinde de $k=0$ model öncesine hiç bakmadan her zaman en yüksek frekanslı kelimeyi söyler. Bu da hiç iyi bir sonuç değildir.

> **Ek bilgi (derste anlatılmadı):** Dahili değerlendirmede en yaygın ölçü perplexity'dir (şaşkınlık). Test kümesinin kelime başına ortalama negatif log olasılığının üstelidir; $PP=P(w_1,\dots,w_N)^{-1/N}$. Test cümlelerine daha yüksek olasılık veren modelin perplexity'si daha düşüktür, yani derste anlatılan "daha yüksek olasılık veren daha iyidir" ölçütünün kelime sayısına göre normalize edilmiş hâlidir.

## 18. Dil Modeliyle Metin Üretimi

Dil modeli bir diziden sonraki kelimeyi tahmin edebildiğine göre, metin de üretebilir. Bir ilk kelime seçilir; model sonraki kelimeyi tahmin eder; tahmin metne eklenir; model yeni metne göre bir sonrakini tahmin eder. Üretip ekleyerek, üretip ekleyerek bir metin üretilir. Örneğin $k=2$ için: $w_1$ verilir, model $w_2$'yi üretir; $w_1,w_2$'ye göre $w_3$ üretilir; sonra $w_2,w_3$'e göre $w_4$; sonra $w_3,w_4$'e göre $w_5$, ve böyle devam eder. Bir ifadeden sonra geleni tahmin edebilen her sistemde bu yapılabilir.

$k=0$'da model önceki kelimelere hiç bakmaz, yalnız her kelimenin kendi olasılığına bakar. Bu durumda hep frekansı en yüksek olan kelimeyi üretir (örneğin "bir" gibi).

Bir başka sorun daha vardır: her zaman en yüksek olasılıklı kelime seçilirse, bir kelimeden sonra hep aynı kelime gelir. $k=1$'de $w_1$'den sonra $w_4$ üretildiyse, metin ilerleyip yeniden $w_1$ üretildiğinde arkasından kesinlikle yine $w_4$ gelir. $k=2$'de de ardışık iki kelimeden sonra hep aynı üçüncü kelime gelir. Bunu aşmanın iki yolu vardır:

- En yüksek olasılıklı $t$ kelimeden birini rastgele seçmek.
- Bütün kelimeler arasından olasılıklarına göre rastgele seçim yapmak. Shannon Game diye bilinen prosedür bunu yapar: seçim olasılığı yüksek olan kelimenin seçilme şansı yüksektir.

Üretim, istenen sayıda kelime ya da cümle üretilince ya da bir cümle sonu (end of sentence) belirteci üretilince durdurulabilir.

### 18.1 Bigram ile üretilen metinler

Slayttaki deney (ekrandan, 02:00:00): kod `dil_modeli.m`, bigram (K=1) modeli. Model en yüksek olasılıklı $t$ taneden birini rastgele seçer; $t$ değeri azaldıkça metinlerden kopya çekme olasılığı artar. $t=5$ alınmış. 1000 ekonomi haberiyle üretilen metinlerden biri:

```text
fonların yüzde 5 de bu konuda son 10 ın da çok sayıda türk telekom gibi çok
önemli olduğunu belirten bakan şimşek 2012 nin.
```

Slayta göre burada first order (K=1) yapının problemi bariz görünüyor: "yer aldığı bilgiye", "yüzde 10 yılda". "Yer aldığı" anlamlıdır, "aldığı bilgiye" anlamlıdır, ama "yer aldığı bilgiye" anlamlı değildir. "Yüzde 10" anlamlıdır, "10 yılda" anlamlıdır, ama "yüzde 10 yılda" anlamlı değildir. Yani ardışık ikililer anlamlı, ardışık üçlüler anlamsızdır.

### 18.2 Trigram ile üretilen metinler

Slayttaki ikinci deney (ekrandan, 02:00:30): kod `dil_modeli_second.m`, trigram (K=2) modeli, $t=5$. 1000 ekonomi haberiyle üretilen cümlelerden biri:

```text
yaşanan sıkıntıları için devamlı ucuz bilet satıyoruz 100 90 ı aslında bu biz
bu bitireceğiz inşallah yıl sonuna kadar türkiyede üretilen fazlasını
belirterek geçen yıl kasım ayı ihracatını
```

1000 magazin haberiyle de cümleler üretilmiştir. Slaytın sonucu: ardışık üçlüler artık daha anlamlıdır. Ama ardışık dörtlüler ve beşliler hâlâ anlamlı değildir.

$k$ artırıldıkça daha anlamlı metin üretme şansı artar. <!-- BELİRSİZ: Hoca 02:00:57 civarında k artırıldığında ne olacağını anlatırken "en yüksek olasılıklı şeyler çok aşırı derecede nadirleşecekler, dolayısıyla tekrarlı yapıları çok fazla görmeye başlayacaksınız" diyor; cümle altyazıda kısmen bozuk, tam iddia net değil. Büyük olasılıkla, k büyüdükçe bir bağlamdan sonra gelebilecek aday sayısı azaldığı için model derlemdeki dizileri aynen tekrar etmeye başlar demek istedi. --> Hoca, derin öğrenme modelleriyle metin üretimi yapanların modelin bazen bir kalıba takılıp onu arka arkaya ürettiğini görmüş olabileceğini, bunun da aynı olgunun bir yansıması olduğunu ve ileride görüleceğini söyledi.

Hoca, kodlarla oynamanın, başka derlemler kullanmanın ve $k$'yı değiştirerek sonuçlara bakmanın serbest olduğunu, enteresan ve komik sonuçlar çıkabildiğini söyledi.

## 19. Eğitim ve Test Kümesi Üzerine Bir Soru

Dersin sonunda bir öğrenci şunu sordu: 100 cümlenin tamamıyla modeli eğitip sonra içinden 10 tanesiyle test etmek ile 90 cümleyle eğitip 10 cümleyle test etmek arasında fark var mı?

Hoca bir benzetmeyle cevap verdi. Bir öğretmen sınavda soracağı soruları öğrencilere önceden verse, sonra sınavı yapsa ve bütün öğrenciler 100 alsa, öğretmen öğrencilerin konuyu anladığından emin olabilir mi? Hayır, öğrenciler ezberlemiş olabilir.

Ardından 1-en yakın komşu (1-nearest neighbor) algoritmasını örnek verdi. Bu algoritmada bir test örneğinin sınıfı, ona en yakın eğitim örneğinin sınıfıdır. Bütün veri eğitime konup içinden rastgele 10 örnekle test edilirse, her test örneğinin en yakın komşusu kendisi olacağından başarı %100 çıkar. Karar ağacıyla da aynısı elde edilir. Ama bu sonuçlar, model gerçek veriyle test edildiğinde elde edilecek sonuçlar olmaz. Gerçek dünyadaki performansı anlamak için veri kesişimi olmayan iki parçaya ayrılır: eğitim kümesinde eğitilir, test kümesinde test edilir. Bunun cevap verdiği soru şudur: model, eğitimde görmediği örnekler üzerinde de başarılı tahmin yapabiliyor mu?

Öğrenci modelin bir cümleyi işledikten sonra onu "unuttuğunu" düşündüğünü söyledi. Hoca, burada iki farklı şeyin karıştırılmaması gerektiğini belirtti: makine öğrenmesi algoritmaları ile derste anlatılan dil modeli farklıdır. Dil modelinde bir tablo oluşturulur ve olasılıklar buradan çekilir; bir öğrenme süreci değil, yalnız bir hesaplama süreci vardır. Hoca öğrenciye fikrini olgunlaştırıp deneyerek sonuçlarla gelmesini önerdi.

## Örnek Sorular

**Soru 1** (ekrandan, 00:20:00): A: "Bahçede top oynayan çocuklar var.", B: "Bahçede top oynayan insanlar var.", C: "Bahçede kimse yok.", D: "Hava çok güzel." Bu metinlerden oluşan ikilileri gerektirmek, mümkün değil ve ilgisiz sınıflarına ayırın.

> **Çözüm (derste verildi):** A→B gerektirmedir (A doğruysa B kesinlikle doğrudur; tersi geçerli değildir). A-C ve B-C mümkün değildir. A-D, B-D ve C-D ilgisizdir.

**Soru 2** (derste sözlü, 00:18:48): Gerektirme, mümkün değil ve ilgisiz ilişkilerinden hangileri simetriktir?

> **Çözüm (derste verildi):** Gerektirme simetrik değildir: "çocuklar var" → "insanlar var" geçerlidir, ama "insanlar var" → "çocuklar var" geçerli değildir. Mümkün değil ve ilgisiz ilişkileri simetriktir.

**Soru 3** (derste sözlü, 00:22:57): Bir metinden katil, kurban, sebep ve suç aleti gibi bilgileri çıkarabilmek bize ne kazandırır?

> **Çözüm (derste verildi):** Metin yapılandırılmış hâle gelir; bilgiler veri tabanında tutulabilir, sorgulanabilir ve filtrelenebilir. Örneğin aynı kişinin işlediği olaylar bulunabilir ya da bir şehirdeki olayların sebeplerine dair raporlar üretilebilir.

**Soru 4** (derste sözlü, 00:41:04): "X'in yeri Y'dir" ilişkisi için "y'de bulunan x" ve "x-y" şablonlarından hangisi aratıldığında daha çok sonuç gelir? Bu sonuçların güvenilirliği nasıldır?

> **Çözüm (derste verildi):** "x-y" çok daha fazla sonuç getirir, ama gelenlerin ilişkiye uyma oranı düşüktür. "y'de bulunan x" daha az ama daha güvenilir sonuç verir. Bu, şablonlarda üretkenlik ile güvenilirliğin ters ilişkili olduğunu gösterir.

**Soru 5** (derste sözlü, 01:14:26): $P(\text{geldi}\mid\text{ali okuldan buraya})=\dfrac{fr(\text{ali okuldan buraya geldi})}{fr(\text{ali okuldan buraya})}$ ifadesinde pay paydadan küçük müdür, büyük müdür?

> **Çözüm (derste verildi):** Pay paydan büyük olamaz; "ali okuldan buraya geldi"nin her geçişi aynı zamanda bir "ali okuldan buraya" geçişidir. Bu yüzden sonuç 0 ile 1 arasında bir olasılıktır.

**Soru 6** (derste sözlü, 01:18:36): Markov varsayımında $k$ değerini artırmanın ve azaltmanın avantaj ve dezavantajları nelerdir?

> **Çözüm (derste verildi):** Küçük $k$: daha kısa diziler aranır, işlem az olur, sıfır frekans sorunu azalır; ama uzak bağımlılıklar (Çin'e ... Çinceyi) yakalanamaz ve alakasız kelimelerin yan yana gelmesine de olasılık verilir. Büyük $k$: daha uzun bağlam hesaba katılır; ama veri seyrekleşir ve işlem artar. $k=0$'da $P(A,B,C,D)=P(B,A,C,D)$ olur, sıra hiç önemsenmez.

**Soru 7** (ekrandan, 01:37:40): Tablodaki bigram olasılıklarıyla (1/18, 4/78, 1/35, 162/560, 4/3940, 1/42) "fuar otomotiv sektörüne önemli bir hareket getirdi" cümlesinin log olasılığını hesaplayın.

> **Çözüm (derste verildi, ara adım eklendi):** $\log P=\ln(1/18)+\ln(4/78)+\ln(1/35)+\ln(162/560)+\ln(4/3940)+\ln(1/42)$. Terimler yaklaşık −2.890, −2.970, −3.555, −1.240, −6.893, −3.738 olur; toplam yaklaşık −21.29'dur (python ile doğrulandı). Slaytta sonuç −21.2067 olarak verilmiştir; küçük fark büyük olasılıkla tablodaki bir değerin yuvarlanmasından gelir.

**Soru 8** (ekrandan, 01:40:00): "fuar otomotiv sektörüne önemli iki hareket getirdi" cümlesinin bigram log olasılığı neden −INF çıkar? Nasıl düzeltilir?

> **Çözüm (derste verildi):** Cümledeki ikililerden biri derlemde hiç geçmediği için o terimin olasılığı 0'dır; çarpım 0, logu −INF olur. Add-one (Laplace) smoothing ile $P_{LS}(w_i\mid w_{i-1})=(fr(w_{i-1},w_i)+1)/(fr(w_{i-1})+V)$ kullanılır. Sonuçta "bir hareket" cümlesi −44, "iki hareket" cümlesi −49 olur; ilki daha olasıdır.

**Soru 9** (ekrandan, 01:41:20): Kelimeler önemli, hareket, bir. Kaç olası diziliş vardır, en olası hangisidir? 10 ve 20 kelime için diziliş sayısı kaçtır?

> **Çözüm (derste verildi):** $3!=6$ diziliş vardır; en olası "önemli bir hareket"tir ($\log P_{LS}=-11.8570$), ikinci "hareket önemli bir"dir (−13.0944). 10 kelime için $10!=3\,628\,800$, 20 kelime için $20!\approx2.43\times10^{18}$ diziliş vardır (python ile doğrulandı); bu yüzden hepsini denemek yerine eleme yapan yaklaşık yöntemler gerekir.

**Soru 10** (ekrandan, 01:50:00): Dil modellerini dahili yöntemle değerlendirirken Markov varsayımında $k=0$ seçimi nasıldır?

> **Çözüm (derste verildi):** İyi değildir. Test cümlesinin olasılığı, kelimelerin sırası değişse bile aynı çıkar ($P(A,B,C)=P(B,A,C)$). Cümle sonunu tahmin etme görevinde de model öncesine hiç bakmadan her zaman en sık kelimeyi önerir.

**Soru 11** (ekrandan, 02:00:00): Bigram ($t=5$) ile üretilen metinde "yer aldığı bilgiye" ve "yüzde 10 yılda" ifadeleri neden anlamsızdır?

> **Çözüm (derste verildi):** Bigram modeli yalnız ardışık ikilileri hesaba katar. "Yer aldığı" ve "aldığı bilgiye" ikilileri ayrı ayrı anlamlıdır, ama model üçlünün bütününü hiç görmediği için "yer aldığı bilgiye" anlamsız olur. Trigram modelinde ardışık üçlüler anlamlı hâle gelir.

## Dersin Toparlaması

Bu derste önce hayat bilgisi veri tabanlarının nerelerde kullanıldığı görüldü: sorgu ve veri zenginleştirme, soru cevaplama, ERASER gibi gerekçe işaretli veri kümeleriyle metin anlama ve SNLI gibi veri kümeleriyle textual entailment. Sonra bilgi çıkarımına geçildi. Metinleri yapılandırılmış hâle getirmenin yolları olarak regex, yazım dilindeki şablonlar ("X ve diğer Y'ler"), öğelerine ayrılmış metinler, dinamik web sayfalarının HTML şablonları ve hocanın morfolojik çözümlemeye dayanan "Tüm X'ler Y'dir" çalışması incelendi. Şablonlarda üretkenlik ile güvenilirliğin ters ilişkili olduğu, frekansın güvenilirlik için önemli olduğu ve çok kelimeli kavramlarla bazı ilişki türlerinin bu yöntemin zayıf yönleri olduğu vurgulandı.

İkinci yarıda Anlamsal Uzaylar bölümünün ilk konusu olan istatistiksel dil modelleri başladı. Zincir kuralıyla cümle olasılığı, uzun dizilerde ortaya çıkan seyreklik, Markov varsayımı ve $k$ seçiminin ikilemi, 1000 ekonomi haberiyle kurulan bigram modeli, sıfır olasılıklar için Laplace smoothing, en olası dizilişi bulma, dil modellerinin harici ve dahili değerlendirilmesi ve dil modeliyle metin üretimi işlendi. Hoca, bu konuya bir sonraki derste çeşitli eklentilerle devam edileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
