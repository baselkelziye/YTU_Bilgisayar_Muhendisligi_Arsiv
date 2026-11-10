# Ders 3 Genişletilmiş Notu: Yapay Zeka, Etik ve Hukuk

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Etik ve Hukuk: Temel Kavramlar
- 2. Verilerdeki Önyargı: Bir Bilmece ve Yazıya Geçmeyen Sıradanlıklar
- 3. Yapay Zekanın Karar Veren Sistem Olarak Özel Durumu
- 4. Gerçek Hayattan Önyargı Örnekleri ve Önyargı Türleri
- 5. Önyargıyı Azaltma Yöntemleri
- 6. Korelasyon ve Nedensellik
- 7. Alt Grup Başarısı, COMPAS ve Önyargı Ölçme Araçları
- 8. Sorumluluk: Suçlu Kim?
- 9. Açıklanabilirlik ve Kara Kutu Sorunu
- 10. Yapay Zeka ve İşsizlik
- 11. Manipülasyon ve Deepfake
- 12. Kişisel Veriler, Gizlilik ve Sürekli İzlenme
- 13. Etik İlkeler ve Geliştiricilerin Yapabilecekleri
- 14. AB Yapay Zeka Yasası ve Ülkelerin Yaklaşımları
- 15. Genel Yapay Zeka ve Geleceğe Dair Sorular
- 16. Dersin Genel Çerçevesi: Yapay Zeka Dersine Bakış

## 1. Etik ve Hukuk: Temel Kavramlar

Bu ders, dönemin son konu anlatımıdır. Konu yapay zekanın etik ve hukuk açısından değerlendirilmesidir. Hoca, önce etik ve hukuk gibi temel kavramlara bakacaklarını, sonra yapay zekanın bu işin neresinde olduğunu, hangi potansiyel problemleri doğurduğunu ve gelecekte bizi nelerin beklediğini konuşacaklarını söyledi. Anlatım, Prof. Dr. M. Fatih Amasyalı'nın slaytları ve hocanın ayrıca hazırladığı birkaç slayt üzerinden yürüdü.

### 1.1 Tanımlar

**Etik**, ahlak diye de ifade edilebilir. İyinin ve kötünün ne olduğu, hangi durumda ne yapılması gerektiği etik ilkelerle ilgilidir. Etik genellikle sözlü ve gelenekselleşmiştir, belki kültürün de bir parçasıdır. Yazılı olmak zorunda değildir.

**Hukuk** ise daha çok devletlerin ya da ülkeler arası anlaşmaların koyduğu yazılı kurallardır. Hukukta kuralın yazıya dökülmüş olması gerekir. Bu yasaların bütününe hukuk denir.

Hoca burada bir ayrımı vurguladı: Konu "hukuka uyarlanmış bir yapay zeka", yani yalnız hukuki verilerle çalışan bir sistem değildir. Konu, karar veren bir sistem olarak yapay zekanın verdiği kararların hukuki ve ahlaki açıdan hangi sorunları doğurabileceğidir. Günümüzün yapay zeka sistemleri kimin kredi alacağına, kimin işe alınacağına, bir mahkeme kararında olduğu gibi kimin serbest kalacağına karar verebiliyor. Bu çıktılar hukuki midir? Hukuki olmasının dışında etik midir?

### 1.2 Her Hukuki Şey Etik midir?

Hoca öğrencilere "Bir şey hukuki ise etik midir diyebilir miyiz?" diye sordu ve bunu uydurma bir örnekle açtı: Bir devlet, "adı Ahmet olanlar üniversitenin tıp bölümünde okuyamaz" diye bir kural koyabilir. Devlet kendi gücüyle böyle bir kuralı hukuka uygun biçimde koyabilir. Ama bu etik ilkelere uygun olmaz.

Hoca, bu örneğin absürt görünebileceğini ama absürtlüğün daha ileri seviyelerinin tarihte görüldüğünü söyledi. İlk Çağ'da, Orta Çağ'da, İkinci Dünya Savaşı döneminde de yazılı hukuk kuralları ve mahkemeler vardı, ama bunlar etik kurallara uygun değildi.

Spesifik bir tarihsel örnek olarak Endülüs'ü anlattı. Endülüs devleti yıkıldıktan sonra İspanya'da yönetim, oradaki Müslüman ve Yahudilerin Hristiyanlaşmasını istedi. Sonra "bunlar iyi Hristiyan olamamışlar" denerek hem Müslümanlara hem Yahudilere takibat başladı ve Engizisyon mahkemeleri kuruldu. Bu mahkemelerde iyi Hristiyan olmadığına karar verilenlere türlü işkenceler uygulandı. Hatta Katolik olmayan, Ortodoks ya da başka mezheplerden Hristiyanlar da kabul edilmedi. Bir süre sonra İbranice ve Arapça kitaplar bile yakıldı. Hocaya göre bütün bunlar yazılı kurallara, mahkemelere ve kararlara dayandığı için "hukuka uygundu", ama etik açıdan uygun değildi.

> **Ders sonrası not:** Hoca, oranın eski adının "galiba Aragon Krallığı" olduğunu söyledi. Gırnata (Granada) 1492'de Kastilya Kraliçesi Isabella ile Aragon Kralı Ferdinand'ın ortak yönetimine düştü; yani tek başına Aragon değil, Kastilya ve Aragon birlikteydi. İspanyol Engizisyonu da büyük olasılıkla 1478'de, Gırnata'nın düşüşünden önce kurulmuştu ve ilk hedefi Hristiyanlığa geçmiş Yahudilerdi.

Bu ayrımdan çıkan sonuç şudur: Yapay zekanın verdiği kararlar hukukilik ve etik açısından **ayrı ayrı** değerlendirilmelidir.

> **Hocanın vurgusu:** Hukuki olan her şey etik değildir. Yapay zekanın kararı hem hukuka uygunluk hem etik uygunluk açısından ayrı ayrı incelenmelidir.

### 1.3 Etik ve Hukuk Zamandan ve Kültürden Bağımsız Değildir

Hoca, bu kavramların zamandan ve kültürden bağımsız olmadığını ekledi. Kölelik aynı örneğin başka bir versiyonudur: Bir zamanlar hukukiydi, şimdi yasaklandı ve hukuki değil. Etik açıdan da bugün kabul görmez. Gelecekte neyin nasıl değişeceğini bilmiyoruz.

O zaman soru şudur: Yapay zekaya karar verdireceksek ve bu kararın hukuki ve etik uygunluğunu ayrı ayrı inceleyeceksek, hukuka aykırılık ya da ahlaki ilkelere aykırılık açısından hangi potansiyel sorunlar ortaya çıkabilir? Hoca bunların ilki olarak verilerdeki önyargıyı ele aldı.

## 2. Verilerdeki Önyargı: Bir Bilmece ve Yazıya Geçmeyen Sıradanlıklar

### 2.1 Cerrah Bilmecesi

Hoca slaytta yaşanmış bir olaya dayanan bir hikaye gösterdi ve öğrencilerden yorum istedi: "Burada bir önyargı mı var, başka bir şey mi var?"

<!-- BELİRSİZ: Bilmecenin slayttaki tam metni altyazıda okunmuyor; aşağıdaki kurgu hocanın açıklamasından ve kısa nottan kurulmuştur. -->

Bilmecenin özü şudur: Bir baba ve oğlu kaza geçirir. Ameliyatı yapacak cerrah "bu benim oğlum" diyerek ameliyatı yapamayacağını söyler. Hoca cevabı şöyle açtı: Ameliyatı yapan kişinin illa çocuğun babası olması mı gerekiyor? Cerrah çocuğun annesi olamaz mı? Çoğumuzun aklına ilk gelen, cerrahın erkek olduğudur. Bu, toplumda yaygın biçimde kabul görmüş bir önyargıdır: "Cerrahsa erkektir, kadın değildir."

Hoca bunu yapay zekaya bağladı. Bir kişinin mesleğini tahmin eden bir veri seti oluşturduğunuzu düşünün. Cinsiyet de bu tahminde kullanılan özelliklerden biri olsun. Modeli öyle eğitirsiniz ki önyargıyı da eğitime dahil edersiniz ve önyargılı bir yapay zeka elde edersiniz. Bu mümkündür. Çünkü elimizde bir $x$ girdisi ve bir $y$ çıktısı vardır. Girdi ile çıktı arasındaki ilişkiyi doğal bir ilişki gibi değil de önyargılı bir ilişki gibi verilere doldurursak, yapay zeka bu önyargıyı da öğrenir.

Hoca, bu slaytı neden sonradan açtığını da açıkladı: Bilmecenin cevabı sonraki slayttaydı; öğrencilerin cevabı görmeden fikir yürütmesini istemişti.

### 2.2 Sıradan Şeyler Yazıya Geçmez

Önyargı her zaman bu örnekteki gibi açık değildir. Bazen sıradan şeyler veri olarak pek görünmez. Gerçek hayatta "sarı muz" diye bir şey pek söylemeyiz, çünkü muz zaten sarıdır. Hoca slayttaki internet arama sayılarını okudu: "sarı muz" ifadesi yaklaşık 13.400 kez, "yeşil muz" yaklaşık 30.000 kez geçiyordu; "kırmızı muz" da aranmıştı.

<!-- BELİRSİZ: Altyazıda "Kırmızı muz diye aratılmış internette o zamanlar 13.400 tane sarı muz demiş 30.000 tane yeşil muz demiş" deniyor; kırmızı muz için verilen sayı ve sayıların hangi ifadeye ait olduğu slayt görülmeden kesinleşmiyor. -->

Aynı durum fiillerde de vardır. Bir veri seti oluşturduğunuzu düşünün: "yemek yedi" ifadesini içeren yaklaşık 714 bin, "öldürdü" ifadesini içeren yaklaşık 26 milyon kayıt var. Yani "öldürdü", "yemek yedi"den yaklaşık 36 kat daha sık geçiyor. Bu veriyle eğitilen bir yapay zeka dünyayı ölümün bol olduğu bir yer olarak görür. Bu önyargıyı öğrendiği için mantıksız, önyargılı, hatta etik ve hukuki olmayan tahminler yapabilir.

Nedeni, normalde sıradan yaptığımız şeyleri söylemememizdir; sıradan olan haber olmaz. Hoca bilinen sözü hatırlattı: Köpek insanı ısırırsa haber olmaz, insan köpeği ısırırsa haber olur. Gerçek dünyadaki olayların frekanslarını dikkate alarak bir model eğiteceksek buna çok dikkat etmek gerekir.

## 3. Yapay Zekanın Karar Veren Sistem Olarak Özel Durumu

Hoca, yapay zekayı bir insanın karar vermesinden ayıran özellikleri sıraladı:

- **Ölçek:** Bir insan da karar verir, yapay zeka da. Ama yapay zeka insana göre kat kat fazla, belki milyarlarca karar veriyor.
- **Kara kutu sorunu:** Bazı sistemlerin davranışı belli değildir. Arkada matematiksel bir model vardır, ama verilen kararı gerçek hayata uygun, mantıklı bir gerekçeyle açıklayamazsınız.
- **Önyargı:** Model önyargı içerebilir.
- **Hız ve maliyet avantajı:** Kararlar çok hızlı ve ucuz verilir.

Bu kadar çok kararın yaygın etkisi düşünüldüğünde hem hukuki hem etik sorunlar ortaya çıkabilir. Hoca bunu bir işe alım örneğiyle açtı. Bir insan kaynakları veri setini bir insan hazırlamış olsun. Bu kişi bir şirkette çalışıyor ve örneğin kadınlara ya da siyahi adaylara ayrımcılık yapıp onları işe almadı. Bu tek bir insanın yaptığı bir şeydir ve belli bir şirketle sınırlı kalır. Ama bu davranışı alıp yapay zekaya modellerseniz ve milyonlarca karara ölçeklerseniz, başta sınırlı olan etki her yere yayılır.

> **Hocanın vurgusu:** Bir insanın önyargısı tek bir şirkette kalır. Aynı önyargı yapay zekaya öğretilirse algoritmanın hızıyla milyonlarca kişiye uygulanır.

Bir de **kültürel bağımlılık** vardır. Bir yerde doğru kabul edilen şey başka bir yerde yanlış kabul edilebilir; hoca inançla ilgili konuları buna örnek gösterdi. Peki yapay zeka hangi kültürün etiğine göre karar vermeli? Hoca bu ikilemi "aşağı tükürsen sakal, yukarı tükürsen bıyık" deyimiyle anlattı.

## 4. Gerçek Hayattan Önyargı Örnekleri ve Önyargı Türleri

### 4.1 İşe Alım Verisi ve Amazon Örneği

Hoca işe alım örneğine döndü. Bir model son 10 yılın işe alım verisiyle eğitilsin. Bu veri nasıl oluştu? İK uzmanları formlar tasarlar, sorular sorar. Bu aslında arka planda bir öznitelik mühendisliğidir (feature engineering). Sorulara cevaplar gelir ve "bu kişiyi işe alalım mı, almayalım mı" diye bir karar verilir. Elimizde güzel, yapılandırılmış, tablo biçiminde (tabular) bir veri vardır. Ama İK, farz edelim ki kadın adaylara ya da farklı durumdaki insanlara daha düşük puan verdi. Model bu önyargıyı da öğrenir. İnsanın önyargısı algoritmanın hızıyla milyonlarca kişiye uygulanıp yayılır.

Hoca bunun varsayımsal değil, yaşanmış bir olgu olduğunu vurguladı: Amazon'un 2018'de CV değerlendirme algoritmasının kadın adaylara düşük puan verdiği tespit edildi ve şirket bu sistemi kaldırmak zorunda kaldı.

### 4.2 Yüz Tanıma

İkinci örnek bir MIT araştırmacısının tespitidir. Ticari yüz tanıma sistemlerinde açık tenli erkeklerde hata oranı yaklaşık %1, koyu tenli kadınlarda yaklaşık %35 çıkmıştır. Nedeni, veri setinin çoğunlukla açık tenli erkeklerden oluşmasıdır. Bu, dengesiz veri seti (imbalanced dataset) durumudur ve doğrudan önyargı oluşturur.

> **Ders sonrası not:** Bu çalışma büyük olasılıkla Joy Buolamwini ve Timnit Gebru'nun 2018 tarihli "Gender Shades" çalışmasıdır. Orada en yüksek hata koyu tenli kadınlarda yaklaşık %34,7, en düşük hata açık tenli erkeklerde yaklaşık %0,8 olarak raporlanmıştır; hocanın %1 ve %35 değerleri bunların yuvarlanmış hâlidir.

### 4.3 Kredi Döngüsü

Gerçek dünyadan bir başka örnek kredilerle ilgilidir. Bazı mahallelerin sakinleri hiç kredi alamadıkları için kredi geçmişleri yoktur. Model bu yüzden onlara düşük puan verir. Kredi alamadıkları için geçmişleri oluşmaz; geçmişleri olmadığı için yine kredi alamazlar. Döngü kendi kendini pekiştirir.

### 4.4 Önyargı Türleri

Hoca slayttaki önyargı türlerini saydı:

- **Tarihsel önyargı (historical bias):** Geçmişteki ayrımcılık veriye yansır.
- **Temsil önyargısı (representation bias):** Bazı gruplar veride az sayıda temsil edilir.
- **Ölçüm önyargısı (measurement bias):** Bazı gruplar için veriler daha hatalı ölçülür.
- **Toplama önyargısı (aggregation bias):** Farklı gruplar tek bir modelle temsil edilir.

Toplama önyargısına hoca bir örnek verdi. Kanserin bir türünü tanımak istiyorsunuz ve "var" ya da "yok" diye sınıflandırma yapıyorsunuz. Ama "var" sınıfının içinde alt türler vardır. Bunları tek bir "var" sınıfına indirgediğinizde aslında bir önyargı oluşturursunuz ve model sınıflardan birini iyi bulamaz.

> **Ders sonrası not:** Hoca burada önce "varları iyi buluyor ama yokları iyi bulmuyor", hemen ardından "yokları iyi buluyor, varları iyi bulamıyor" dedi. Gerekçeye ("varlar içerisinde alt türler var") uyan ikinci ifadedir: Farklı alt türleri tek bir "var" sınıfında toplayan model, "var" sınıfını iyi tanıyamaz.

Hoca, yazılı metinlerdeki önyargının (muz ve "öldürdü" örnekleri) da bu slaytta yer aldığını, bunları tekrar anlatmayacağını söyledi.

## 5. Önyargıyı Azaltma Yöntemleri

Bu önyargı türlerinden sonra "ne yapabiliriz?" sorusuna geçildi:

- **Temsili veri toplama:** Eğitim seti tüm grupları dengeli biçimde yansıtacak şekilde toplanır. Böylece dengesiz veri problemi ortadan kaldırılabilir.
- **Alt grup testleri:** Her demografik grup için ayrı ayrı test yapılır. Yüz tanıma örneğinde koyu tenli kadın yüzleri ile açık tenli erkek yüzleri ayrı ayrı test edilir; eğitim ve test verileri her grup için dengelenir.
- **Adillik metrikleri (fairness metrics):** Eşit hata oranı, demografik parite (demographic parity) gibi ölçümler kullanılır.

> **Ek bilgi (derste anlatılmadı):** Demografik parite, modelin olumlu karar ("kredi verilsin" gibi) oranının her grupta eşit olmasını ister. Eşit fırsat (equal opportunity), gerçekten olumlu olan örnekler arasında doğru pozitif oranının, yani duyarlılığın (recall), gruplar arasında eşit olmasını ister. Eşit hata oranı ise hata oranlarının gruplar arasında yakın olmasını hedefler. Bu ölçütler çoğu zaman aynı anda tam olarak sağlanamaz.

## 6. Korelasyon ve Nedensellik

### 6.1 $y=f(x)$ Varsayımı

Hoca bir diğer probleme makine öğrenmesinin temel kurgusundan girdi. Makine öğrenmesinde bir $x$ girdisi (aslında $x_1, x_2, \dots, x_n$ gibi $n$ öznitelikten oluşan bir vektör) ve bir $y$ çıktısı vardır. $y=f(x)$ gibi bir fonksiyon bulmaya çalışırız. Bu fonksiyon, $x$'in değişiminin $y$'yi etkilediği, yani $x$ ile $y$ arasında bir nedensellik (causality), neden-sonuç ilişkisi olduğu varsayımını taşır. Sınıflandırma ve regresyonda bu ilişkiyi çok kullanırız. Peki nedensellik yakalıyoruz derken farkında olmadan yalnızca bir korelasyonla mı uğraşıyoruz?

> **Hocanın vurgusu:** Birlikte değişen şeyler her zaman neden-sonuç ilişkisi içinde değildir. Aralarında yalnızca korelasyon olabilir.

### 6.2 Dondurma ve Terlik

Hocanın aklına gelen örnek şuydu: Yaz geldiğinde dondurma satışları artar. Yazın başka ne artar? Örneğin terlik satışları. Hem dondurma hem terlik satışı artmıştır. O zaman dondurma satışlarıyla terlik satışları arasında nedensellik var diyebilir miyiz? Diyemeyiz. Her ikisi de sıcaklıkla ilişkilidir: Sıcaklığın artması ikisini de artırır. Ama iki olguya bakıp aralarındaki nedenselliği görmeden böyle bir sonuç çıkarılamaz. Derste bir öğrenci aynı örnek için klima satışlarını önerdi; hoca bunun da aynı korelasyon durumu olduğunu söyledi (bkz. Örnek Sorular).

> **Ek bilgi (derste anlatılmadı):** İki değişkeni birlikte etkileyen bu tür ortak nedene istatistikte karıştırıcı değişken (confounder) denir. Dondurma ve terlik örneğinde karıştırıcı değişken sıcaklıktır. Karıştırıcı değişken modelde hesaba katılmazsa, aslında nedensel bağı olmayan iki değişken arasında güçlü bir ilişki görülür.

### 6.3 Sahte Korelasyon Örnekleri

Hoca, kayda geçmiş bazı sahte korelasyon (spurious correlation) örneklerini gösterdi:

- 1990'dan 2010'a kadar internetin yaygınlaşması ile ağaçların azalması arasında bir korelasyon analizi yapılmış. Bu dönemde biri artmış, diğeri azalmış; ama birinin diğerine neden olmadığı çok açık.
- 2000'lerin başında sosyal medyada kedi fotoğraflarının patlaması ile trafik kazalarının artması. "İnsanlar arabada kedi fotoğrafı çektiği için mi kaza yapıyor?" gibi zorlama bir bağ kurulabilir, ama arada yalnızca korelasyon vardır.
- Hocanın "trajikomik" dediği örnek: Kadınlara oy hakkının verilmesi ile 1900'lerde dünya savaşlarının çıkması. İkisi arasında mantıklı bir ilişki kurulamaz.

Yapay zeka korelasyon ile nedenselliği karıştırarak bu tuzağa düşmemelidir. Girdi ile çıktı arasında bir korelasyon varsa bu ilişkiye dikkat etmek gerekir. Bu ilişkilerin bazıları değerlidir ve kullanılabilir; bazıları alakasızdır ve özellik olarak kullanılırsa yapay zekaya yanlış şeyler yaptırır.

### 6.4 Yoğun Bakım ve Meslek Örnekleri

- **Yoğun bakım:** Yoğun bakımda ölüm oranı yüksektir. Hastanın bulunduğu birim (dahiliye, genel cerrahi, beyin cerrahisi, yoğun bakım) ve hayatta kalma durumu bir veri setinde yer alıyorsa, yapay zeka "yoğun bakım ölüme yol açar" sonucunu öğrenebilir. Oysa ağır hastalar yoğun bakıma alındığı için ölüm oranı yüksektir. Hoca bunu neden-sonuç ilişkisinin tersine çevrilmesine örnek gösterdi.
- **Meslek ve kredi:** Geçmişte belirli bir meslekteki insanlar kredilerini geri ödeyememiş olsun. Bu veriyle "bu meslek risklidir" diye öğretirseniz yanlış bir şey yapabilirsiniz. Ödeyememenin nedeni meslek değil, örneğin bir ekonomik kriz olabilir. Ayrıca kredisini ödeyemeyenler yalnız bu meslekten değildir. "Kredisini ödeyemeyenlerin %90'ı şu meslektendir" diyerek yalnız buna göre yorum yapmak yapay zekayı yanıltabilir.

### 6.5 İsim Önyargısı

Hoca bir başka örnekte, gönderilen CV'lerde "Emily" gibi isimlere sahip adayların "Lakisha" gibi isimlere sahip adaylara göre yaklaşık %50 daha fazla geri dönüş aldığını söyledi. Bu bir isim önyargısıdır.

> **Ders sonrası not:** Bu, büyük olasılıkla Bertrand ve Mullainathan'ın 2004 tarihli deneyidir. Aynı nitelikteki CV'ler, beyaz Amerikalılarla özdeşleşen isimlerle (Emily, Greg gibi) ve siyahi Amerikalılarla özdeşleşen isimlerle (Lakisha, Jamal gibi) gönderilmiş; ilk gruba yaklaşık %50 daha fazla geri dönüş yapılmıştır. Altyazıda yalnız "Emily" ve bozuk biçimde "Lakisha" adı geçiyor.

İstatistiksel korelasyon karar almada tek başına yeterli değildir; bu şekilde alınan kararlar etik olmayan, hukuka da uygun olmayabilen durumlar doğurur. Doğru bir karar için nedenselliğe uygun bir çıkarım, yani **nedensel çıkarım (causal inference)** gerekir. Gerekirse bir alan uzmanının görüşü alınmalı ya da bir uzman sistem kurulmalıdır.

## 7. Alt Grup Başarısı, COMPAS ve Önyargı Ölçme Araçları

### 7.1 Ortalama Başarı Yanıltabilir

Hoca önyargıyı ortaya çıkarmak ve azaltmak için alt gruplara ayırma fikrine döndü. Yüz tanımada açık tenli erkek, açık tenli kadın, koyu tenli erkek ve koyu tenli kadın grupları ayrı ayrı değerlendirilir. İlk gruplarda hata oranları çok iyi, koyu tenli erkeklerde orta düzeydedir. Ama koyu tenli kadınlarda %35 hata buluyorsanız bu kabul edilebilir değildir. Ortalama doğruluğunuz %94 olsa bile bir gruptaki bu başarısızlık yapay zekanız için iyi bir şey değildir.

Hoca adil bir yapay zekanın demografik pariteye, eşit fırsata ve eşit hata oranına uygun bir çözüm üretmesi gerektiğini söyledi. Bütün grupların hatası %3, %4, %5 gibi birbirine yakın değerler ya da hepsi %10 olsa bunu anlarız. Ama bir grupta hata %1, başka bir grupta çok daha yüksekken genel ortalamaya bakıp "%94" demek doğru olmaz.

> **Hocanın vurgusu:** Yalnız genel ortalama başarıya bakmak yeterli değildir. Her alt grupta hata oranı ayrı ayrı ölçülmelidir.

### 7.2 COMPAS

Hoca bir başka örnek olarak COMPAS'ı anlattı. Bu, mahkemedeki ve hapishanedeki hükümlülerin profillerini çıkarmak, yani tekrar suç işleme eğilimi olup olmadığını tahmin etmek için kullanılan bir yapay zeka sistemidir. Yapılan bir araştırmada siyahi sanıkların beyazlara göre iki kat daha fazla "yüksek riskli" olarak etiketlendiği bulunmuştur. Özellikle tekrar suç işlemeyenler arasında siyahi sanıkların yanlış etiketlenme oranı daha yüksektir. Hakimler bu skoru cezalarda kullanıyordu. Böylece algoritmanın önyargısı insanların özgürlüğünü etkileyen kararlara yansıdı.

> **Ders sonrası not:** Hoca COMPAS'ın açılımını söylemeye başladı ama tamamlamadı. Açılımı büyük olasılıkla "Correctional Offender Management Profiling for Alternative Sanctions"dır. Siyahi sanıkların yanlışlıkla yaklaşık iki kat daha sık "yüksek riskli" etiketlendiği bulgusu büyük olasılıkla ProPublica'nın 2016 analizine aittir.

### 7.3 Önyargı Ölçme Araçları

Önyargıyı ölçmek ve azaltmak için araçlar da vardır: IBM'in aracı, Google What-If Tool ve Microsoft Fairlearn. Hoca bu araçların ek çözümlerle sistemleri biraz daha dengeli hâle getirdiğini söyledi. Bunların uydurma değil, gerçekten yaşanmış sorunlara cevap olarak ortaya çıktığını da ekledi.

> **Ders sonrası not:** Altyazıda "IBM Payness" diye geçen araç büyük olasılıkla IBM AI Fairness 360'tır.

## 8. Sorumluluk: Suçlu Kim?

Önyargıdan sonraki soru şudur: Yapay zeka bir karar verdi ve buna göre bir aksiyon alındı. Sonuç kötü olursa suçlu kimdir?

### 8.1 Otonom Araç

En basit örnek otonom araçtır ve bunun da gerçeği vardır: 2018'de Uber'in otonom aracı bir yayaya çarptı ve yaya hayatını kaybetti. Bu bir yapay zeka kararının sonucudur. Hoca olası sorumluları sıraladı:

- Yapay zeka modelini eğiten yazılımcı mı?
- O yapay zekayı ürettiren üretici mi?
- Aracı kullanmayan ama araçta oturan, müdahale etmeyen ya da edemeyen sürücü mü?
- Bu konuda gerekli düzenlemeleri yapmadığı için devlet mi?
- Yaya mı?

Bazı durumlarda "yaya kabahatliydi" denip işin içinden çıkılabilir, ama hocaya göre ilk dördünün burada çok payı vardır.

### 8.2 Radyoloji Modeli

Otonom araç kazaları daha seyrek olabilir; hoca daha yaygın bir örnek verdi. Bir radyoloji modeli tümörlü bir dokuyu inceleyip kanser olup olmadığına karar veriyor. Dünyada bir tedavinin, ilacın ya da tıbbi prosedürün kabulü FDA gibi kurumların onayına bağlıdır; Dünya Sağlık Örgütü'nün de düzenlemeleri vardır. Böyle bir yapay zekanın FDA tarafından onaylandığını kabul edelim. Model bir hastaya "bir şeyin yok" der, oysa hasta kanserlidir. Teşhis gecikir ve hasta hayatını kaybeder. Sorumlu FDA mıdır, yazılım mıdır, son kararı veren doktor mudur?

Duruma göre sorumluluk türleri farklı olabilir: ürün sorumluluğu, ihmal ya da ortak sorumluluk. Hoca, bunlarla ilgili hukuki düzenleme yapan, kendi bildiği ilk örneğin risk seviyesine göre kademeli bir yapı kuran Avrupa Birliği Yapay Zeka Yasası olduğunu söyledi. Başka ülkelerin de, Türkiye'nin de bu konuda çalışmaları olabileceğini ama bunları yakından takip etmediğini ekledi.

## 9. Açıklanabilirlik ve Kara Kutu Sorunu

### 9.1 Kara Kutu

Bir sonraki konu açıklanabilirlik (explainability), yani kara kutu problemidir. Derin öğrenme ya da genel olarak yapay zeka modelleri çok sayıda parametreyle bir karar verir. "Neden bu kararı verdin?" sorusu çoğunlukla yanıtsız kalır.

Hoca bir evrişimli sinir ağını (convolutional neural network, CNN) düşünmemizi istedi. Görüntü üzerinde filtreler gezdirilir, filtrelerden öznitelikler çıkarılır, sonra yapay sinir ağının ağırlıkları optimize edilir ve bir karar verilir. Bu kararı neden verdin? Şu ağırlık neden büyük, bu ağırlık neden küçük? Bunlara bir cevabımız yoktur; açıklanabilirlik yoktur.

### 9.2 Açıklanabilirlik Neden Gerekli?

- **Hukuki hak:** Hocaya göre Avrupa Birliği'nin GDPR (General Data Protection Regulation) düzenlemesi kapsamında insanların açıklama talep etme hakkı vardır. "Krediyi neden reddettin?" sorusuna cevap verilebilmelidir. Hoca, olması gereken bir açıklamayı şöyle örnekledi: "Son altı ayda şöyle bir durum var; kararın %40'ı bu nedenle, %35'i bu nedenle, %25'i bu nedenle verildi."
- **Güven:** Doktor yapay zekayla bir teşhis koyduğunda son kullanıcı olarak buna ne kadar güvenebilirim? Yapay zekanın kararı açıklanabiliyorsa, gerekçeli bir hakim kararı gibi, o zaman güvenebilirim.
- **Hata ayıklama:** Önyargı ancak modelin nasıl "düşündüğü" görülünce tespit edilebilir.
- **İtiraz hakkı:** Kişi değerlendirmenin yeterli olmadığını düşünüp itiraz edebilmeli ve itirazı değerlendirilmelidir.

> **Ders sonrası not:** GDPR'da "açıklama hakkı" büyük olasılıkla açıkça yazılmış tek bir madde olarak yer almaz. 22. madde, yalnız otomatik işlemeye dayalı kararlara karşı insan müdahalesi isteme ve itiraz etme hakkı tanır; 13-15. maddeler ise otomatik karar verme durumunda "işlemenin mantığı hakkında anlamlı bilgi" verilmesini ister. "Açıklama hakkı" bu maddelerden çıkarılan bir yorumdur.

Hoca kara kutu uygulamasına günlük bir örnek verdi. Bankaların mobil uygulamalarından kredi kartı limit artırımı istendiğinde, talep "değerlendirmemiz sonucunda reddedilmiştir" diye gerekçesiz reddedilebiliyor; algoritma kelimesi bile geçmiyor. Hatta altında "BDDK kararı gereği itiraz edilemez" gibi ifadeler bulunabiliyor. Hocaya göre bu durumda yapay zekanın verdiği kararla hukuki bir hakkımız ihlal edilmiş olur. Hoca kendi başından geçen bir olayı da anlattı: Bir bankanın sistemi otomatik olarak yanlış bir değerlendirmeyle red vermiş, bota itiraz etmek sonuç vermemiş; bankayla normal bir yazışma yapıldıktan sonra banka sistemindeki hatayı düzeltmiş.

### 9.3 Açıklanabilir Yapay Zeka Araçları

Açıklanabilir yapay zeka (explainable AI, XAI) araçları vardır:

- **LIME:** Her tahmin için yerel bir doğrusal açıklama üretir.
- **SHAP:** Her özelliğin tahmine katkısını oyun teorisiyle hesaplar.
- **Grad-CAM:** Görüntü modellerinde modelin görüntünün neresine baktığını, nereye odaklandığını gösterir.

<!-- BELİRSİZ: Altyazıda oyun teorisine dayalı aracın adı okunmuyor ("Lime, her özelliğin katkısını oyun teorisiyle hesaplayan, ... Gradcam"); SHAP adı kısa nottan ve aracın tarifinden alınmıştır. -->

Hoca Grad-CAM görsellerini internette arayıp incelemeyi önerdi: Görüntünün hangi bölgelerine odaklanıldığı ısı haritası gibi gösteriliyor.

> **Ek bilgi (derste anlatılmadı):** SHAP'in dayandığı Shapley değeri, işbirlikçi oyun teorisinden gelir: Her oyuncunun (burada her özelliğin), olası tüm özellik kombinasyonlarına eklendiğinde sonuca getirdiği ortalama marjinal katkıdır. LIME ise açıklanacak örneğin çevresinde küçük değişikliklerle yeni örnekler üretip bu bölgede basit bir doğrusal model uydurur ve bu modelin katsayılarını açıklama olarak kullanır.

2024'te çıkan Avrupa Birliği Yapay Zeka Yasası, yüksek riskli yapay zeka sistemleri için açıklanabilirliği, insan denetimini ve kayıt tutmayı zorunlu kıldı. İhlal edilirse ciddi para cezaları ve yaptırımlar vardır.

## 10. Yapay Zeka ve İşsizlik

Hoca, öğrencilerin çok konuştuğu bir soruya geçti: Yapay zeka, ölçeklenebilirlik ve otomasyon sayesinde meslekleri elimizden alacak mı?

### 10.1 Karamsar Senaryo

Her şeyi yapay zeka yapacaksa herkes işsiz kalacaktır. Rutin olan birçok iş devralınır, çok az iş devralınamaz. Bir yapay zeka robotu evinizdeki elektrik arızasını bile tamir edebilir; robotun arızasını da başka bir robot giderir. Robotu tamir eden robot olunca insana neredeyse hiç gerek kalmaz. Hocaya göre bu senaryonun belli ölçüde gerçekleşmesi öngörülüyor. Bazı ülkelerin buna yönelik ekonomik planlamaları vardır: İnsanların temel gereksinimlerini karşılayacak vatandaşlık maaşı gibi bir düzenleme. Çünkü işsiz kalan insan farklı sorunlara yol açabilir. Bu tür düzenlemelerin ileride yaygınlaşacağı da söyleniyor.

### 10.2 İyimser Senaryo: Tarihsel Örüntü

İyimser senaryo tarihsel örüntüden gelir. Dokuma (tekstil) makinesi, yazıyı çoğaltan matbaa için hep böyle söylenmiştir; hoca, Osmanlı'da matbaanın hattatlar işsiz kalmasın diye geç kabul edildiğinin anlatıldığını hatırlattı. Önceden orakla yapılan tarıma biçerdöver geldiğinde insanlar işsiz mi kaldı? Sanayi devrimi birçok eski mesleği yerinden etti, ama yeni ihtiyaçlar ve yeni meslekler ortaya çıktı.

### 10.3 Hocanın Görüşü

Hoca bu tarihsel örüntünün önümüzdeki dönemde tekrar etmeyebileceğini düşündüğünü söyledi. Önceden bir insanın bir görevi vardı; bu görev makineye geçince insana yeni bir görev üretildi. Ama şimdi insana üretilecek yeni görevlerin çoğunu da yapay zeka ya da robotik sistemler devralabilir. İnsanın yapabileceği çok az iş kalabilir; yeni meslekler yaratılsa da sayıları az olabilir. Hocaya göre bu kocaman bir soru işaretidir ve yaşayıp göreceğiz.

### 10.4 Risk Haritası

- **Yüksek risk:** Veri girişi, belge sınıflandırma, rutin muhasebe, çağrı merkezi operatörlüğü. Veri girişi artık çok rahat otomatikleştirilebiliyor.
- **Orta risk:** Radyoloji okuma. Yapay zeka okuyor, iyi karar veriyor, örneğin %99 kesinlik (precision) ve duyarlılık (recall) veriyor; ama "içimizde soru işareti kalmasın" diye bir uzman da bakıyor.
- **Düşük risk:** Empatik bakım, liderlik, yaratıcılık gerektiren tasarım, karmaşık müzakere, sahne sanatları gibi insanın duygusal yönünün öne çıktığı işler.
- **Yeni meslekler:** Prompt mühendisi, yapay zeka eğiticisi. Hocaya göre bunlar da ileride yapay zeka tarafından devralınabilir.

Hocaya göre asıl odaklanılması gereken, işlerin yok olup olmayacağından çok dönüşümün yükünü kimin taşıyacağıdır: Geçiş süreci nasıl olacak, kim neyi kaybedip kim neyi kazanacak?

## 11. Manipülasyon ve Deepfake

### 11.1 Sosyal Medya Algoritmaları

Yapay zekayı meslek dışında en çok internette ve sosyal medyada görürüz. Sosyal medya algoritmaları artık klasik algoritmalar değildir, "zeki" hâle gelmiştir ve yapay zekayla manipülasyon yapılabilecek bir durum söz konusudur.

Hoca slaytta Stuart Russell'ın bir tespitini gösterdi: Optimizasyon saptı. Yapay zekanın hedefi insanların ne istediğini öğrenmek olmalıydı. Ama öneri algoritmaları, daha iyi tahmin edebilmek için insanları daha tahmin edilebilir hâle getirdi. İnsanlar bireysellikten uzaklaştı; yönetilebilir ve uzaktan manipüle edilebilir hâle geldi.

> **Ders sonrası not:** Hoca bu tespiti 2020 yılına tarihledi. Stuart Russell'ın bu görüşü büyük olasılıkla 2019'da yayımlanan *Human Compatible* kitabında yer alır.

Hoca bunun alışveriş alışkanlıklarımızda ve güncel olaylara verdiğimiz tepkilerde rahatça görüldüğünü söyledi. İnternetten bir şey alırken "onu alırken bunu da al" önerileri çıkar. İnternette bir sağlık şikayetini araştırdığınızda karşınıza birden bir sağlık sigortası ya da tedavi önerisi çıkar. Bu öneri sizin hareketlerinizden çıkarılmıştır ve sizi yönlendirmeye çalışır. Soru şudur: Bir kişinin bir konudaki fikrini video izleterek, haber okutarak ya da başka içeriklerle değiştirmek mümkün müdür?

### 11.2 Manipülasyon Türleri

- **Ticari manipülasyon:** "X'i alma, Y'yi al." Toplumsal zarar görece azdır, amaç kâr etmek ve bir ürünü öne çıkarmaktır.
- **Siyasi manipülasyon:** "A partisine oy verme, B'ye ver." Hoca, ABD'deki bir iki önceki seçimlerle ilgili böyle bir haberin çıktığını, ne kadar doğru olduğunu bilmediğini ama olabileceğini söyledi.
- **Nefret politikaları.**

Bunların hepsi hukuk ve etik açısından sıkıntılı konulardır.

### 11.3 Tıklama Oranı Optimizasyonu

Ayrıntıya girildiğinde karşımıza tıklama oranı optimizasyonu çıkar: Hedef, insanların platformda olabildiğince uzun süre kalmasıdır. Hoca kendi doktora çalışmasından bir örnek verdi: 2020'de bir telekom şirketiyle (Turkcell) birlikte çalışırken şirketin hedefi, müzik uygulamasında insanların daha fazla zaman geçirmesiydi. Bunun için dinlenen müziğe benzeyen müzikler öneren bir öneri sistemi geliştiriliyordu. Bunun farklı teknikleri vardır:

- yalnız müziğin akustik özelliklerine göre öneri (hocanın çalıştığı yöntem),
- meta verilere göre öneri,
- birliktelik ilişkilerine göre öneri: "A müziğini dinleyenlerin %90'ı B müziğini de dinliyor" gibi.

Hedef, uygulamada daha fazla insanın kalmasıdır; her dinleme ya da indirme uygulamaya gelir getirir.

### 11.4 Cambridge Analytica

Cambridge Analytica olayında 87 milyon Facebook kullanıcısının verileri izinsiz alınarak psikografik profiller oluşturuldu. Bu profillerin ABD seçiminde kullanıldığı ileri sürüldü; hoca bunun hâlâ tartışmalı bir konu olduğunu söyledi.

### 11.5 Yalanla Manipülasyon: Deepfake

Deepfake teknolojisiyle ses, görüntü, video ve metin üretilebilir. Üretilen içerik gerçeğinden ayırt edilemeyecek kadar iyidir ve tespiti giderek zorlaşır.

Hoca daha basit bir örneği kendi yaşadığı biçimde anlattı: 2014 civarında Twitter'da Boğaziçi Köprüsü'nün yıkılmak üzere olduğunu, beşik gibi sallandığını gösteren bir görüntü yayıldı. Oysa görüntüde köprüye asılı, rengi köprünün yol rengine yakın bir bayrak vardı; bayrak dalgalanınca köprü kırılıyormuş gibi görünüyordu. Bu bir deepfake değildi; gerçek bir fotoğrafın üzerine yanıltıcı bir metin eklenmişti. Hocaya göre bugün çok daha fazlası yapılabilir: Bir kişinin, özellikle siyasi figür ya da sanatçı gibi etkili bir kişinin sesinden, söylemediği bir şeyi yapay zekayla üretip insanları manipüle etmek mümkündür.

Dersin ilerleyen kısmında hoca bir örnek daha verdi: Hong Kong'da bir finans çalışanı bir deepfake video konferansına katıldı ve sahte bir "CFO"nun talebiyle 25 milyon dolar transfer etti. Konferanstakilerin hepsinin deepfake olduğu günler sonra anlaşıldı. Hoca özellikle sesteki deepfake'i tespit etmenin çok zor olduğunu, üretim yöntemleri geliştikçe tespit yöntemlerinin de geliştiğini, ama gerçeği sahteden ayırt etmenin hâlâ zor olduğunu söyledi. Burada bir taktik ve anti-taktik yarışı vardır.

> **Ders sonrası not:** Hoca Hong Kong olayını 2023'e tarihledi. Olay büyük olasılıkla Ocak 2024'te yaşandı ve Şubat 2024'te kamuoyuna duyuruldu; transfer edilen tutar yaklaşık 200 milyon Hong Kong doları, yani yaklaşık 25 milyon ABD dolarıdır.

## 12. Kişisel Veriler, Gizlilik ve Sürekli İzlenme

### 12.1 Ham Veri ve Çıkarımlar

Kişisel verilerimizin sahibi kimdir ve bu verilere ne oluyor? Ham veri, işlenmemiş veridir: tıkladığınız haberler, konum (koordinat) bilginiz, alışveriş geçmişiniz, uyku saatleriniz, girdiğiniz sayfalar. Bunlardan çıkarımlar yapılır. Örneğin uyku saatlerinizden "dengesiz uyuyorsunuz, depresyonda olabilirsiniz" diye bir çıkarım yapılıp karşınıza buna göre haberler ve öneriler çıkarılabilir.

Yaşanmış bir örnek **Target**'tır: Şirket, alışveriş alışkanlıklarından hamile müşterileri tespit eden bir model kurdu. Bir baba, kızına hamilelik ürünleri reklamları geldiğini görünce şikayet etti ve durum böyle ortaya çıktı. Hocanın aktardığına göre uygulama daha sonra kaldırıldı. Kişisel veriler duruma göre işverenlere, şirketlere ya da devlete gidebilir.

### 12.2 Sigorta ve Instagram

Hoca İngilizce bir yazıdan bir örnek aktardı: "Hayat sigortanız için ne ödeyeceğinizi bir sonraki Instagram paylaşımınız belirleyebilir." Bazı sigorta şirketleri çevrim içi davranışları izlemek istiyor. Sigara içerken poz verirseniz akciğer kanseri gibi risklerin yüksek olduğu düşünülüp primi buna göre ayarlanabilir. Koşarken fotoğraf paylaşırsanız daha ucuz bir poliçe çıkabilir. Hocanın dikkat çektiği bir nokta da şuydu: Bu durumda kullanıcılar yapay zekayı yanıltmaya çalışabilir; böyle poz vermez, koşarken fotoğraf paylaşırlar.

### 12.3 Olması Gerekenler

Veri paylaşımını kabul ediyoruz, ama verinin hangi amaçla ve nasıl kullanılacağına dair yeterli bilgi verilmiyor. Yapay zekaların ya da diğer algoritmaların bu verileri nasıl işleyeceği açık ve şeffaf değildir. Hocaya göre olması gerekenler şunlardır:

- **Amaç açıkça söylenmeli:** "Instagram paylaşımlarından harcama ya da alışveriş alışkanlıklarını, öğrenme örüntünü çıkarmaya çalışıyorum" gibi açık bir ifade gerekir. "İstendiğinde falanca firmaya veririm" gibi muğlak ifadeler yetmez. Telefon bankacılığında duyulan "kişisel verileriniz hizmet kalitesini artırmak amacıyla işlenmektedir" cümlesi de neyin nasıl işlendiğini söylemez.
- **Kişi verisini görebilmeli ve silebilmeli:** Hoca öğrencilere Google hesaplarındaki verilerini hiç inceleyip incelemediklerini sordu. Google'da bunun yapılabildiğini, ama her hizmette olup olmadığının ayrı bir soru olduğunu söyledi.
- **Üçüncü taraflarla paylaşım için ayrıca onay alınmalı:** Örneğin Medium'a Gmail hesabıyla üye olurken Google bir onay metni gösterir: "Buradan oraya bağlantı kurulacak, veriler paylaşılacak, onayın lazım." Ama hangi verilerin nasıl paylaşılacağı açıkça söylenmez. "Reklam amaçlı" demek de yeterli değildir.

### 12.4 Sağlık Verileri

Sağlık verileri daha hassastır. Faydası açıktır: Hastalıkları erkenden tespit edip büyük sıkıntıların önüne geçebilir. Bu verilerin işlenmesi sorun değildir. Sorun, sağlık verilerinin sigorta şirketleriyle, işverenlerle ya da gereksiz yere devletle sınırsızca paylaşılmasıdır. Sağlık verileri paylaşılabilir, ama belli bir ölçüde; gerektiğinde maskelenmiş ya da anonimleştirilmiş biçimde. Hocanın örneği: Bir kişinin kan değerlerinden hastalık bilgisi tutulabilir, ama kişinin adını vermeye gerek yoktur.

### 12.5 Sürekli İzlenme ve Sosyal Kredi Sistemi

Hoca sürekli izlenmeye örnek olarak Çin'de uygulanan sistemi anlattı. Vatandaşların davranışlarına göre puan verilir: trafikte ihlal, kredi ödemesi, yerli ya da yabancı ürün alma gibi. Hocanın aktardığına göre Çin üretimi olmayan bir telefon almak bile vatandaşlık puanını düşürebiliyor. Puanı düşen kişi bazı haklardan mahrum kalabiliyor, kara listeye girip uçuş ve tren yasağıyla karşılaşabiliyor. Hoca bunların doğruluğuna ve hukuki yönüne girmediklerini, bunun kendi alanları olmadığını söyledi; ama bir yapay zeka sisteminin böyle bir şey yapmasının hukuk ve ahlak açısından iyi ya da kötü diye değerlendirilmesi gerektiğini vurguladı. Bunu Orwell'ın *1984* romanındaki "Büyük Birader her şeyi izliyor" (Big Brother) sözüne bağladı. Hocaya göre bugün tepeden izlemeye gerek kalmadan telefonlarımızdan çok rahat izlenebiliyoruz.

> **Ders sonrası not:** Çin'deki sosyal kredi sistemi büyük olasılıkla tek ve merkezi bir puan sistemi değildir; kurumlara ve şehirlere göre değişen farklı uygulamalardan oluşur. "Yabancı marka telefon alınca puan düşer" iddiası büyük olasılıkla belgelenmiş bir kural değildir. Borcunu ödemeyenlere uçuş ve hızlı tren bileti kısıtlaması getirilmesi ise belgelenmiş uygulamalar arasındadır.

## 13. Etik İlkeler ve Geliştiricilerin Yapabilecekleri

### 13.1 Avrupa Birliği'nin 7 Etik İlkesi

Avrupa Birliği güvenilir yapay zeka için 7 ilke belirlemiştir:

- insan gözetimi,
- teknik sağlamlık,
- gizlilik ve veri yönetişimi,
- şeffaflık,
- çeşitlilik ve adalet,
- toplumsal refah,
- hesap verebilirlik.

> **Ders sonrası not:** Bu 7 ilke büyük olasılıkla AB'nin 2019'da yayımladığı "Güvenilir Yapay Zeka için Etik Yönergeler" (Ethics Guidelines for Trustworthy AI) belgesinden gelir. O belgedeki adlar "insan gözetimi ve insan faaliyeti", "teknik sağlamlık ve güvenlik", "toplumsal ve çevresel refah" biçimindedir.

### 13.2 Geliştiriciler Ne Yapabilir?

Hoca bilgisayar mühendisleri olarak yapabileceklerimizi sıraladı:

- **Alt grup testleri:** Yalnız genel ortalamaya bakmak yetmez. K-katlı çapraz doğrulama (k-fold cross validation) yapıp beş katın ortalama başarısına bakmak son aşamada yeterli olmayabilir; daha ileri analizler gerekir. Hoca, özellikle tıbbi alandaki çalışmalarında bunu daha ileri seviyede yaptıklarını söyledi.
- **Verinin kaynağını belgelemek:** Eğitim verisinin nereden geldiği belgelenmelidir.
- **Model kartı (model card) yazmak:** Modelin amaçları, kısıtları ve başarısızlık senaryoları açıkça belirtilmelidir.

> **Ek bilgi (derste anlatılmadı):** Model kartı fikri, büyük olasılıkla Mitchell ve arkadaşlarının 2019 tarihli "Model Cards for Model Reporting" çalışmasından gelir. Bir model kartında tipik olarak modelin amaçlanan kullanımı, eğitim ve değerlendirme verisi, farklı alt gruplardaki başarı ölçüleri, etik değerlendirmeler ve bilinen kısıtlar yer alır.

### 13.3 Bireyler Ne Yapabilir?

Birey olarak da haklarımızı ve sorumluluklarımızı bilmeliyiz. Önümüze bir metin çıktığında doğrudan "kabul et" deyip geçmemeliyiz. ChatGPT, Claude, Gemini gibi yapay zeka araçlarını kullanıyoruz; bunların sözleşme şartlarını okuyor muyuz? Hoca, kendisi dahil çoğumuzun muhtemelen okumadığını söyledi.

> **Hocanın vurgusu:** Kullanıcı olarak sözleşme ve veri paylaşım metinlerini okuyun; haklarınızı ve sorumluluklarınızı bilin.

## 14. AB Yapay Zeka Yasası ve Ülkelerin Yaklaşımları

### 14.1 Yasaklanan Sistemler

Avrupa Birliği Yapay Zeka Yasası'nda (EU AI Act) bazı sistemler yasaklanmıştır:

- **Gerçek zamanlı uzaktan yüz tanıma:** Sınırlı istisnalar dışında halka açık alanlarda yasaktır. Hocanın örneğiyle, bir polisin yüz tanıma sistemiyle sizi tanıması AB'de yasaktır.
- **Sosyal skor sistemleri:** Çin tarzı sistemler AB'de kabul edilmez.
- **Bilinçaltı manipülasyon teknikleri.**

### 14.2 Sıkı Denetime Tabi Alanlar

Sağlık, eğitim, istihdam, yargı ve kritik altyapı sistemleri sıkı denetime tabidir. Hocaya göre bu alanlarda yapay zekanın çıktısı bir uzman olmadan doğrudan kullanılamaz. Risk değerlendirmesi, şeffaflık ve insan denetimi zorunludur. İhlallerin yaptırımı 35 milyon avroya ya da cironun %7'sine kadar çıkabilen para cezalarıdır.

> **Ders sonrası not:** 35 milyon avro ya da %7 üst sınırı büyük olasılıkla yasaklanmış uygulamaların ihlali içindir ve yüzde, şirketin dünya çapındaki yıllık cirosu üzerinden hesaplanır (hangisi yüksekse). Diğer yükümlülüklerin ihlali için üst sınırlar büyük olasılıkla daha düşüktür. Yasa büyük olasılıkla 1 Ağustos 2024'te yürürlüğe girdi ve hükümleri kademeli olarak uygulanıyor.

### 14.3 Türkiye ve Diğer Ülkeler

Hocaya göre Türkiye'de kişisel verileri koruma kanunu GDPR'a benzer korumalar sağlıyor; yapay zekaya özel düzenleme çalışmaları ise sürüyor. Hoca son birkaç aydaki gelişmelere bakmadığını belirtti.

<!-- BELİRSİZ: Altyazıda kanunun adı "işsiz veriler korunma kanunu" diye bozuk geçiyor; kastedilen büyük olasılıkla Kişisel Verilerin Korunması Kanunu'dur (KVKK). -->

Ülkelerin yaklaşımları farklıdır:

- **Avrupa Birliği:** Risk bazlı düzenleme. Amaç önce temel insan haklarını güvence altına almaktır.
- **ABD:** Sektör bazlı, yeniliği öne alan bir yaklaşım.
- **Çin:** Devlet yönlendirmeli bir yaklaşım.

## 15. Genel Yapay Zeka ve Geleceğe Dair Sorular

Hoca otonom araç kazalarıyla ilgili tartışma sorularının slaytta bulunduğunu, bunları öğrencilerin okuyabileceğini söyledi ve son olarak geleceğe dair bazı zorlukları sıraladı:

- **Genel yapay zeka (Artificial General Intelligence, AGI):** Genel amaçlı bir yapay zeka henüz büyük ölçüde teori düzeyindedir, ama ilerlemeler vardır. Böyle bir sistemin değerlerini kim belirleyecek? Herkes için genel amaçlı bir sistem nasıl olacak?
- **Yapay zeka hakları:** Yapay zekanın hakları olacak mı?
- **Otonom silahlar ("ölüm robotları"):** "İnsanlar savaşmasın, robotlar savaşsın" fikri; bunlar uçak, insansı robot (humanoid) ya da başka biçimlerde olabilir. Hocanın aktardığına göre yaklaşık 30 ülke bunların yasaklanmasını istiyor, ama henüz bir anlaşma sağlanamadı.

Hocaya göre yapay zekanın hedefleri insanın ahlaki ve etik değerleriyle uyumlu olmalıdır. Etik ve ahlak sağlanırsa hukuk da onun peşinden gitmeye çalışır, ama her şeyi düzeltemez. Hoca kaba bir tahminle hukukun belki %70-80'inin etik ve ahlaka uygun, belki %30-40'ının ise uygun olmadığını söyledi.

<!-- BELİRSİZ: Altyazıda "%70'i, %80'i etik ve ahlaka uygundur, %30'u, %40'u belki uygun değildir" deniyor; yüzdeler toplamda tutarsız. Hoca kesin bir oran değil, kaba bir tahmin veriyor. -->

Umut veren gelişmeler de vardır: AB yasası öncü oldu; açıklanabilirlik için teknik araçlar geliştirildi; insanların farkındalığı ve yapay zeka okuryazarlığı arttı. Hoca bunu Facebook'un ilk yıllarına benzetti: Herkes bir anda platforma yüklendi, sonra faydalı içeriğin az olduğunu düşünen birçok kişi uzaklaştı. Yapay zekada da zamanla bu tür değişimler olacaktır.

## 16. Dersin Genel Çerçevesi: Yapay Zeka Dersine Bakış

Hoca bu haftayla konuların bittiğini söyledi; bir önceki derste üretken yapay zeka anlatılmıştı. Yapay zekanın kendi içinden birçok branş doğuran bir bilim dalı olduğunu hatırlattı: makine öğrenmesi, veri madenciliği, örüntü tanıma; makine öğrenmesinin alt teknikleri (örneğin pekiştirmeli öğrenme (reinforcement learning) tek başına bir, hatta birkaç ders olabilir); doğal dil işleme, görüntü işleme, ses işleme. Bu derste amaç yapay zekanın ne olduğunu, hangi alanlara temas ettiğini ve genel olarak hangi problemler üzerinde çalıştığını tanıtmaktı.

Derse optimizasyonla, yani aramayı nasıl daha iyi yapacağımız sorusuyla başlanmıştı. Bu önce ayrık bir uzayda aramaydı, sonra sürekli uzaylara geçildi. Hocaya göre yapay zekada en çok yapılan şey aslında tahmindir: Bu bazen bir fonksiyonun minimum ya da maksimum noktası, bazen birinin kredi skoru, bazen birinin işe alınıp alınmayacağıdır. Bu tahminlerde isabet oranının yanında etik ve ahlaka uygunluk gibi farklı ölçütler de vardır.

## Örnek Sorular

Bu derste ekrandan alınmış soru yoktur. Aşağıdaki sorular derste sözlü olarak sorulmuştur.

**Soru 1** (derste sözlü, 00:12:25): Bir şey hukuki ise etik midir diyebilir miyiz? Her hukuki şey etik olur mu?

> **Çözüm (derste verildi):** Hayır. Bir devlet "adı Ahmet olanlar tıp okuyamaz" gibi bir kuralı hukuka uygun biçimde koyabilir, ama bu etik olmaz. Engizisyon mahkemeleri ve kölelik de bir dönem yazılı kurallara dayandığı için hukukiydi, ama etik değildi. Bu yüzden yapay zekanın kararları hukuk ve etik açısından ayrı ayrı değerlendirilmelidir.

**Soru 2** (derste sözlü, 00:16:45): Bir baba ile oğlu kaza geçirir. Cerrah çocuk için "bu benim oğlum" der ve ameliyatı yapamayacağını söyler. Bu nasıl mümkündür? Burada bir önyargı mı var?

<!-- BELİRSİZ: Bilmecenin slayttaki tam metni altyazıda okunmuyor; soru metni hocanın açıklamasından kurulmuştur. -->

> **Çözüm (derste verildi):** Cerrah çocuğun annesidir. Çoğumuz cerrahın erkek olduğunu varsayarız; bu toplumda yaygın bir önyargıdır. Cinsiyeti özellik olarak kullanan bir meslek tahmin modeli, veride bu önyargı varsa onu da öğrenir.

**Soru 3** (derste sözlü, 00:29:28): Yazın dondurma satışları ve terlik satışları birlikte artıyor. Bu iki satış arasında nedensellik var diyebilir miyiz?

> **Çözüm (derste verildi):** Diyemeyiz. İkisi arasında yalnızca korelasyon vardır. Her ikisini de artıran ortak etken sıcaklıktır. İki olgunun birlikte değişmesine bakarak aralarında neden-sonuç ilişkisi kurulamaz.

**Soru 4** (derste sözlü, bir öğrencinin sorusu, 00:48:38): Aynı örnekte klima satışları da artıyor; bu da aynı durum mudur?

> **Çözüm (derste verildi):** Evet. Dondurma satışları ile klima satışları da birlikte artar; burada da aralarında bir korelasyon vardır, ortak etken sıcaklıktır, ama biri diğerinin nedeni değildir.

**Soru 5** (derste sözlü, 00:30:14 - 00:31:11): Aşağıdaki ilişkilerde nedensellik var mıdır? (a) 1990-2010 arasında internetin yaygınlaşması ve ağaçların azalması, (b) 2000'lerin başında sosyal medyada kedi fotoğraflarının artması ve trafik kazalarının artması, (c) kadınlara oy hakkı verilmesi ve 1900'lerde dünya savaşlarının çıkması.

> **Çözüm (derste verildi):** Üçünde de yalnızca sahte korelasyon vardır. Değişkenler aynı dönemde birlikte değişmiştir, ama aralarında mantıklı bir neden-sonuç bağı kurulamaz.

**Soru 6** (derste sözlü, 00:58:27): Kendi verilerinizi internette araştırdınız mı; örneğin Google hesabınızdaki verileri incelediniz mi?

> **Çözüm (derste verildi):** Hocaya göre kişi kendisine ait verileri görebilmeli ve gerektiğinde silebilmelidir. Bir hizmet bunu sağlayan bir servis sunmalıdır. Google hesabında bu yapılabiliyor; her hizmette bu imkanın olup olmadığı ayrı bir sorudur.

## Dersin Toparlaması

Bu derste etiğin hukukla aynı şey olmadığı, hukuki olan her şeyin etik olmadığı ve yapay zekanın kararlarının iki açıdan ayrı ayrı değerlendirilmesi gerektiği görüldü. Yapay zekayı insan karar vericiden ayıran ölçek, kara kutu yapısı ve önyargı, tek bir kişinin hatasını milyonlarca karara yayabilir. Verilerdeki önyargı tarihsel, temsil, ölçüm ve toplama önyargısı olarak sınıflandırıldı; Amazon'un CV algoritması, yüz tanıma, kredi döngüsü, isim önyargısı ve COMPAS örnekleriyle somutlaştırıldı. Çözüm olarak temsili veri, alt grup testleri ve adillik metrikleri öne çıktı. Korelasyonun nedensellik olmadığı, $y=f(x)$ ile kurulan ilişkinin her zaman neden-sonuç ilişkisi olmadığı ve gerekirse nedensel çıkarıma ve alan uzmanına başvurulması gerektiği vurgulandı.

Dersin ikinci yarısında sorumluluk (otonom araç ve radyoloji örnekleri), açıklanabilirlik (GDPR, LIME, SHAP, Grad-CAM), yapay zekanın işsizliğe etkisi, sosyal medya manipülasyonu ve deepfake, kişisel verilerin gizliliği ve sürekli izlenme ele alındı. Son olarak AB'nin 7 etik ilkesi, AB Yapay Zeka Yasası'nın yasakladığı ve sıkı denetime aldığı sistemler, ülkelerin farklı düzenleme yaklaşımları ve AGI ile otonom silahlar gibi açık sorular konuşuldu. Hoca dersi, yapay zekanın özünde bir tahmin aracı olduğunu ve bu tahminlerin yalnız isabetle değil, etik ve hukuka uygunlukla da değerlendirilmesi gerektiğini hatırlatarak, dönemin konularını bağlayarak kapattı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
