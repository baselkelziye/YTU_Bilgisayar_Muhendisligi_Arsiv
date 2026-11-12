# Ders 2 Genişletilmiş Notu: Hayat Bilgisi Veritabanları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Planı
- 2. Hayat Bilgisi Nedir?
- 3. Hayat Bilgisi Veri Tabanlarına Neden İhtiyaç Var?
- 4. Hayat Bilgisi Veri Tabanları Nasıl Oluşturulur?
- 5. Sinirsel Dil Modelleri ve Hayat Bilgisi
- 6. ConceptNet
- 7. Grup Çalışması: Hayat Bilgisini Toplama ve Kullanma Fikirleri
- 8. NELL
- 9. Türkçe Hayat Bilgisi Veri Tabanı
- 10. CSoyun
- 11. Monotonik ve Monotonik Olmayan Çıkarım
- 12. Hayat Bilgisi Veri Tabanlarının Kalitesi
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Planı

Bu ders, "Hayat Bilgisi Veri Tabanları" bölümünün ilk haftasıdır. Bölüm iki hafta sürer. Bu hafta hayat bilgisinin ne olduğu, neden gerektiği, benzer çalışmalar, Türkçe için yapılmış bir veri tabanı ve bu veri tabanının kalitesini artırmak için tasarlanmış CSoyun oyunu anlatıldı. Slayttaki bölüm planı şöyledir (ekrandan, 00:10:00):

- Hayat Bilgisi (Commonsense) Nedir?
- Neden ihtiyaç var?
- Benzer çalışmalar
- Türkçe Hayat Bilgisi Veritabanı: kaynaklar, veri tabanının oluşturulması, kavramlar arası ilişki türleri
- CSoyun
- Otomatik Bilgi Çıkarımı

Son madde olan otomatik bilgi çıkarımı bir sonraki derste işlenecek: hayat bilgisi türündeki veriler metinlerden otomatik olarak nasıl çıkarılabilir?

## 2. Hayat Bilgisi Nedir?

Hayat bilgisi, İngilizcede commonsense knowledge ya da world knowledge diye geçer. Dünyaya dair, herkesin bildiğini varsaydığımız bilgilerdir. O kadar bariz şeylerdir ki kimseye söylemeye gerek duymayız. Slayttaki örnekler (ekrandan, 00:11:20):

- İnsanlar her gün yemek yer.
- İnsanlar geceleri uyur.
- Balıklar denizde yaşar.
- Elma yuvarlaktır.
- Kediler miyavlar.

Bu bilgilerin istisnaları olabilir. Karada ara sıra yaşayabilen balıklar vardır; geceleri uyumayan insanlar da vardır. Ama genel olarak böyle olduğunu kabul ederiz. Hayat bilgisi veri tabanı da bu tür bilgilerin tutulduğu veri tabanıdır.

## 3. Hayat Bilgisi Veri Tabanlarına Neden İhtiyaç Var?

### 3.1 Bilgisayarlar söylenmeyeni anlamaz

Bilgisayarlara her şeyi söylemek gerekir. Söylediklerimizden söylemediklerimizi anlamazlar, tahmin edemezler. Hoca, yapay zekânın tanımlarından birinin "bilgisayarlar neden bu kadar aptal?" sorusuna cevap aramak olduğunu söyledi. Buradaki "aptallık", söylenmeyeni çıkaramamaktır. Bilgisayarın söylenenden söylenmeyeni tahmin edebilmesi isteniyorsa ona hayat bilgisi vermek gerekir.

Slayttaki örnek: bu sayede bilgisayarlar da insanlar gibi "Ali lokantada yemek yedi" cümlesinden "Ali para ödemiştir" bilgisini çıkarabilecektir. Cümlede para ödemekle ilgili hiçbir şey yoktur: yemek yemek, lokanta ve Ali vardır. Ama biraz düşünen biri buradan "para ödemiştir", "karnı doymuştur", "tatlı da yemiştir" gibi birçok şey çıkarabilir. Bunlar kesin değil, olasılıklıdır: Ali para ödememiş de olabilir. Sistemin bu çıkarımı yapabilmesi için "lokantada yemek yemek için cebinde para ya da kredi kartı olması gerekir", "yemeğini yediysen ödemiş olman gerekir" gibi bilgilerin ona verilmesi gerekir.

### 3.2 Kurt ve kız hikâyesi

Slayttaki hikâye (ekrandan, 00:20:00): "Küçük bir kız babaannesini ziyaret etmek için ormanda yürümeye başlıyor. Çalılıkların arkasındaki aç bir kurt kızı görüyor. Onu yemeğe karar veriyor. Küçük kıza tam saldıracakken, oduncuların şarkılarını duyuyor. Çalılıkların ardında saklanıp kararından vazgeçiyor." Problem: "Kurt kararından neden vazgeçti?" ve "Küçük kız korktu mu?" sorularını açıklayınız. Slayt, örneğin Pat Hayes ve Lokendra Shastri'ye ait olduğunu belirtiyor.

İlk soruya bir öğrenci, kurdun sesleri duyunca tehlikeyi sezdiğini, bu seslerin ona zarar verebilecek varlıklardan geldiğini önceki deneyimlerinden bildiğini söyledi. Hoca akıl yürütmeyi sınıfla birlikte adım adım kurdu: kurt saldırırsa kız bağırır; oduncular ormanda çığlık duyunca oraya gider; bir kurdun bir kıza saldırdığını görünce kızı kurtarmak için kurda zarar verir, belki öldürür; öldürülmek kurt için istenmeyen bir şeydir. Kurt bu planı kafasında yapıp vazgeçmiştir. Bunların hiçbiri metinde yazmaz. Cevap veren kişi metnin yanında hayatı boyunca deneyimlerinden, okuduklarından ve gördüklerinden öğrendiği hayat bilgisini kullanır.

İkinci soruda bir öğrenci, cevabın kızın kurdu fark edip etmediğine bağlı olduğunu söyledi. Metinde kızın kurdu fark ettiğine dair bir şey yoktur; kızın olan bitenden haberi bile yoktur. Kız kurdu görseydi kaçar, koşar ya da bağırırdı. Dolayısıyla kızın korktuğuna dair bilgi yoktur.

Hikâyenin dersi şudur: insanlar metinde doğrudan yer almayan şeyleri kolayca çıkarabilir, makineler için bu henüz pek mümkün değildir. Çünkü makinelerde dünyanın nasıl işlediğine, insanların niyetlerine, bir şey olunca ardından neler olabileceğine dair bilgi yoktur. İnsanlar bu bilgileri doğduklarından (belki anne karnından) itibaren öğrenir. Makinelerin dünyayı deneyimleyerek öğrendiği böyle bir süreç yoktur.

### 3.3 Bilgiyi depolamak mı, erişmek mi?

**Soru:** Bir öğrenci, bu bilgileri metinlerden okuyarak da öğrenebildiğimizi, bilgisayarın da bunu yapıp kaydedebileceğini; sorunun öğrenmekte değil, gereken bilgiyi çok hızlı bulup olayla bağdaştırmakta olduğunu söyledi. **Cevap:** Hoca öğrenmenin bilgiyi organize biçimde kaydetmek, yani gerektiğinde erişebilmek olduğunu belirtti. Bilgisayarların bunu bugün yapamadığını, örneğin bu metni verip "Kurt kararından neden vazgeçti?" diye sorulduğunda cevap veremediklerini söyledi. Bilgiye sahip olmak, ona ne zaman erişileceğini bilmeyi de gerektirir; bilginin bir yerde metin olarak kopyalanmış hâlde durması çok işe yaramaz. İnsanların bunu nasıl bu kadar hızlı yaptığını ise kimse bilmiyor.

Hoca, metnin içinde açıkça bulunan bilgiyi sormanın ("Kurt nereye saklanıp kararından vazgeçiyor?") makineler için kolay olduğunu, klasik yöntemlerle cümleyi öğelerine ayırarak bile çözülebileceğini belirtti. Zor olan, metinde olmayan ama gereken bilgiye erişmektir. Ders boyunca iki soru üzerinde durulacak: bilgisayarlara çok sayıda derlem verip bu bilgileri kendilerinin çıkarmasını mı sağlayacağız, yoksa bilgileri belirli formatlarda oluşturup gerektiğinde onlara erişimi mi sağlayacağız?

### 3.4 Duygu durum analizinde hayat bilgisi

Duygu durum analizinde bir tweet ya da yorumun olumlu mu olumsuz mu olduğu bulunur. Slayttaki örnekler (ekrandan, 00:24:20):

- "Yemeğim 5 dakikada geldi. Çok teşekkürler XXX."
- "Yemeğim 55 dakikada geldi. Çok teşekkürler XXX."
- "XXX sayesinde 1 saatlik filmi 3 saatte izledim."
- "XXX sayesinde 1 saatte 5 film indirdim."

Burada XXX bir firmadır. İlk cümle olumludur. İkincisinde "çok teşekkürler" kinayelidir; cümle aslında olumsuzdur. İkisini ayıran şey 5 ve 55 dakikadır. Bir yemeğin ne kadar sürede gelmesinin kısa ya da uzun olduğuna dair bilgi olmadan birine olumlu, ötekine olumsuz demenin ipucu yoktur. Film örneklerinde de bir filmin ne kadar sürdüğü, indirmenin ne kadar sürdüğü bilinmelidir.

Makine öğrenmesi yöntemleri eğitim örneğine benzeyen bir test örneği gelince ona eğitim örneğindeki etiketi vermeye çalışır. İlk iki cümle eğitim ve test kümesinde olsa, aralarındaki fark yalnızca minicik bir karakterdir; örüntü eşleme (pattern matching) ile birine olumlu, ötekine olumsuz demek mümkün değildir. Ayrıca "55 dakika uzundur" da tek başına anlamlı değildir: yemek teslimatı için uzun, bir film için kısadır. Değerlendirme bağlama göre değişir.

**Soru:** Bir öğrenci, film cümlesinde 1 saatlik filmin 3 saatte izlendiği açıkça yazdığına göre ek bilgiye gerek olup olmadığını sordu. **Cevap:** Hoca, bugünkü internet hızlarıyla bunun kötü olduğunu, ama birkaç yıl önce o kadar kötü sayılmayabileceğini söyledi. Yani bunu değerlendirmek için de arka planda bir bilgiye ihtiyaç vardır.

### 3.5 Metinsel olmayan bilgi

Hoca, hayat bilgisi veri tabanlarının metinle ifade edilebilen bilgiyle sınırlı olduğunu belirtti. Bilgilerimizin bir kısmı görseldir ve metinle ancak bir dereceye kadar aktarılabilir. Bisiklete binmek gibi beceriler de metinle ifade edilemez. Dünyanın fiziğini öğrenmeye yönelik çalışmalar vardır ama henüz emekleme aşamasındadır.

## 4. Hayat Bilgisi Veri Tabanları Nasıl Oluşturulur?

### 4.1 İki temel yaklaşım

Slayttaki iki yaklaşım (ekrandan, 00:27:50):

- Bilgileri az sayıda bilgi mühendisi özenle girsin yaklaşımı: Cyc, 20 yılda 1,5 milyon kaliteli bilgi (www.cycfoundation.org/concepts).
- Bilgileri çok sayıda web kullanıcısı girsin yaklaşımı: OpenMind, 8000 kişi, 3 yılda 1 milyon bilgi (www.openmind.org).

Cyc, Lenat adlı bilim insanının projesidir. Bilgiler Cyc'in Lisp'e benzeyen kendi dilinde girilmiştir. <!-- BELİRSİZ: Hoca bilgi mühendisi sayısı için "3-5 kişinin girmesi pek mümkün değil, 100 civarında" gibi bir şey söyledi; altyazı net değil. -->

İkinci yaklaşımın fikri şudur: bu bilgiler herkesin sahip olduğu bilgilerdir, uzmanlık gerektirmez; bu yüzden uzmanların girmesine gerek yoktur, çok sayıda gönüllü web kullanıcısı girebilir. İki yaklaşımın ürettiği bilgi sayıları benzerdir, ama Cyc tarafındaki bilgi kalitelidir. Bilginin kaliteli ya da kalitesiz olmasının ne demek olduğunu öğrenciler kendi veri toplama çalışmalarında görecek.

### 4.2 Popüler çalışmalar

Slayttaki liste (ekrandan, 00:30:00):

- Cyc (1984, anlamsal ağ, uzman kişiler, elle)
- WordNet (1985, anlamsal ağ, uzman kişiler, elle)
- OpenMind / ConceptNet (2002, gönüllü kullanıcılar, otomatik)
- NELL (2010, hayat bilgisi, yarı otomatik)

Hocaya göre NELL'in ve ConceptNet'in güncellemesi sürüyor.

> **Ders sonrası not:** Hoca listeyi okurken OpenMind için "2012'de" dedi; slaytta OpenMind/ConceptNet için 2002 yazıyor.

## 5. Sinirsel Dil Modelleri ve Hayat Bilgisi

Doğal dil işlemede doğruluk açısından en başarılı sonuçlar genelde dersin ilerisinde işlenecek sinirsel dil modelleriyle elde edilir. Sinirsel dil modeli kabaca bir yapay sinir ağıdır ve kendi kendine denetimli (self-supervised) görevlerle eğitilir. Bu görevlerde kullanıcının etiketlemesine gerek yoktur ama çıktı otomatik olarak belirlenebilir. Örnekler:

- Bir cümledeki üç kelimeden sonraki kelimeyi tahmin etmek.
- Cümleden bir kelimeyi silip o kelimeyi tahmin etmek.

İnternetten indirilebilen çok büyük derlemlerden bu görevlerin girdi-çıktı çiftleri kolayca üretilir. Denetimli duygu durum analizinde ise birinin metni okuyup olumlu ya da olumsuz etiketi vermesi gerekir.

Bu tür modeller birçok NLP alanında başarılıdır. Ama hayat bilgisi gerektiren örneklerde hâlâ yakalayamadıkları şeyler vardır ve bu bilgileri bir şekilde harici olarak vermek gerekir. Son çalışmalar bağlama göre değerlendirme için hayat bilgisine açıkça ihtiyaç olduğunu gösteriyor. Bu amaçla genelde ConceptNet derin öğrenme mimarileriyle birleştiriliyor; ConceptNet'in sinirsel dil modelleriyle iş birliği şu anda oldukça popüler bir çalışma alanıdır.

## 6. ConceptNet

### 6.1 Oluşturulması

ConceptNet, OpenMind'dan türemiştir. Slayttaki aşamalar (ekrandan, 00:35:40):

- Çıkarım aşaması: gönüllü kullanıcıların serbest formda girdikleri cümlelerden (OMCS corpus) yola çıkılır. Cümle bilgi üçlüsüne çevrilir. Bu, tüm bilgilerin %90'ıdır.
- Zenginleştirme aşaması: mevcut bilgilerden yeni bilgiler üretilir. Bu, tüm bilgilerin %10'udur.

Bilgi üçlüsü "kavram 1, kavram 2 ve aralarındaki ilişkinin türü"dür: "şu kavramla şu kavram arasında şu tür bir ilişki vardır". Zenginleştirmede kullanılan çıkarımlara CSoyun anlatılırken dönülecek: çıkarım nasıl yapılır, nasıl yapılması anlamlıdır, nasıl yapılması anlamsızdır.

### 6.2 Yapısı

Slayta göre ConceptNet'te 1,6 milyon (kavram-ilişki-kavram) üçlüsü ve 20 ilişki türü vardır (ekrandan, 00:36:45). Slayttaki şekil ilişki türlerini gruplar:

- Nesneler (THINGS): IsA, PartOf, PropertyOf, DefinedAs, MadeOf
- Mekân (SPATIAL): LocationOf
- Olaylar (EVENTS): SubeventOf, LastSubeventOf, PrerequisiteEventOf, FirstSubeventOf
- Nedensellik (CAUSAL): EffectOf, DesirousEffectOf
- Duygusal (AFFECTIVE): DesireOf, MotivationOf
- İşlevsel (FUNCTIONAL): UsedFor, CapableOfReceivingAction
- Etmenler (AGENTS): CapableOf

Hoca, bugün bakılırsa sayının çok daha büyük olduğunu, ama içine çok faydası olmayan şeylerin de girildiğini belirtti: dünyadaki bütün köyler, bütün ünlülerin doğum tarihleri ya da çıkardıkları albümler, bütün canlıların Latince adları gibi. Bunlar herkesin bildiğini varsayabileceğimiz türden bilgiler değildir. Bazı alanlarda işe yarayabilirler, ama ConceptNet'teki her şey hayat bilgisi olarak doğrudan kullanılabilir değildir.

### 6.3 İlişkilerin özellikleri

ConceptNet örnek ağında kavramlar arasında oklar vardır ve oklar ilişkilerin yönünü gösterir. Bazı ilişkiler yönsüzdür: "A ile B zıt anlamlıdır". Bazıları yönlüdür: A, B için kullanılır ama B, A için kullanılmaz. İlişkiler geçişli ya da geçişsiz de olabilir. "A, B'ye yakındır; B, C'ye yakındır; C, D'ye yakındır" ise A, D'ye yakın mıdır? Aradaki adım sayısı arttıkça artık yakın olmayabilir.

### 6.4 Örnek ağ

Slayttaki ağ (ekrandan, 00:40:00), metne dökülmüş hâliyle:

```text
wake up in morning --PrerequisiteOf--> eat breakfast
wake up in morning --SubeventOf------> yawn
wake up in morning --SubeventOf------> check e-mail
wake up in morning --SubeventOf------> drink coffee
wake up in morning --MotivationOf----> get to bed early
wake up in morning --Generalisation--> wake up
wake up            --UsedFor---------> alarm clock
eat breakfast      --EffectOf--------> full stomach
eat breakfast      --SubeventOf------> chew food
eat breakfast      --SubeventOf------> read newspaper
kitchen table      --UsedFor---------> eat breakfast
in house           --LocationOf------> kitchen table
kitchen table      --PartOf----------> chair
```

Hoca bunu şöyle okudu: Sabahları erken kalkarsınız, sonra kahvaltı edersiniz. Mutfak masası kahvaltı için kullanılır ve evin içindedir; sandalye mutfak masasının bir parçasıdır. Kahvaltının sonucu olarak karnınız doyar. Kahvaltının alt olayları gazete okumak ve yiyecekleri çiğnemektir.

### 6.5 Uygulamalar

ConceptNet'in birçok uygulaması yapılmıştır; derste gösterilenler oldukça eskidir:

- Commonsense ARIA (ekrandan, 00:40:10): kullanıcının yazdığı e-postayı inceleyerek içeriğine uygun fotoğraflar önerir ya da ekler. Ekrandaki örnekte "Ken and Mary's wedding" konulu bir e-posta yazılırken düğünle ilgili fotoğraflar öneriliyor.
- Hikâye üretici: bu tür verilerle hikâye ürettirmek de mümkündür. Hikâye üretiminin uzun bir tarihçesi vardır; derste ayrıntısına girilmedi.

## 7. Grup Çalışması: Hayat Bilgisini Toplama ve Kullanma Fikirleri

Hoca öğrencileri ikişerli gruplara ayırdı ve internete bakmadan, kendi fikirleriyle beyin fırtınası yapmalarını istedi. Üç konu vardı: hayat bilgisini toplamak, toplanmış bilgiyi iyileştirmek ve olası uygulamalar. Grupların fikirleri ve hocanın yorumları şöyledir.

### 7.1 Birinci grup

- Toplama: atasözleri ve deyimler genel yargıya varmak için veri olabilir. Hoca atasözlerinin kullanılabileceğini, deyimlerin ise genel yargı için kullanılmasının zor olacağını belirtti.
- İyileştirme: "Masanın üstünde kedi oturuyordu" gibi hayat bilgisi içermeyen, genel bir yargıya katkı vermeyen cümleleri ayıklamak.
- İyileştirme: örneklerdeki özel adları tür adlarıyla değiştirmek. "Ali şunu yaptı" cümlesinde adın Ali olması önemli değildir; bunun yerine bir etiket kullanılırsa model insana dair şeyleri daha kolay öğrenebilir. Hoca bunun bir kısmını elle işlemek anlamına geldiğini ve modelin amacına göre yapılması gerektiğini belirtti.
- Uygulama: resimleri ilgili atasözü ya da deyimle eşleştiren eğitici materyal; örneğin mutlu bir insan resmini "etekleri zil çalmak" deyimiyle eşleştirmek. Hoca bunun duygu durum analizi değil, image captioning'e yakın bir şey olduğunu belirtti.

### 7.2 İkinci grup

- Toplama: Twitter'dan web kazıma (web scraping). 5 dakika / 55 dakika örneğinde cümlenin yanındaki emoji olumlu ya da olumsuz olduğunu gösterebilir; böylece ayrıca etiketleme yapmadan duygu öğrenilebilir.
- Toplama: insan fizyolojisi kitabı gibi öğretici, kinaye ya da kelime oyunu içermeyen metinlerden öğrenmek.
- İyileştirme: uzman sistemlerden ya da uzman kişilerden destek almak.
- Uygulama: seçim sonucu tahmini, hisse senedi tahmini (bir firmanın işçi çıkarması olumsuz bir etki yapar), soru-cevap sitelerinden öğrenen sağlık sohbet robotu. Hoca seçim tahmininde hayat bilgisinin nasıl kullanılacağını sordu; bunun daha çok duygu durum analizine yakın olduğunu belirtti. Grubun öğrencisi, insanların ideolojilerinin mesajlardan çıkarılabileceğini ve hayat bilgisinin oradan geleceğini söyledi.

### 7.3 Üçüncü grup

- Erişim sorunu: bilgiyi kategori ağacı biçiminde düzenleyerek mevcut 1,5 milyon bilgiye az adımda erişmek.
- Toplama: Wikipedia derlemini verip makine öğrenmesiyle bilgileri ilgili kategorilere yerleştirerek bilgi sayısını büyütmek.
- Uygulama: kişinin okuduğu kitap ve makalelerden psikolojik çıkarım yapmak.

### 7.4 Dördüncü grup

- Uygulama: verilen bir kelimeyle (örneğin "güneş") ilgili el çizimi resimleri getiren bir sistem. Öğrenci bunun hayat bilgisiyle bağlantısının zayıf olduğunu kendisi belirtti.
- Toplama: çocuk kitaplarında "yemek yemişti, artık karnı doymuştu" gibi açık ifadeler bulunur; bunlardan bir eylemden sonra neler olabileceği öğrenilebilir. Hoca çocuk kitaplarının uygun olabileceğini onayladı.
- Uygulama: belirli bir yaş aralığı için yazılmış kitaplardan dil ve olay örüntülerini öğrenerek daha iyi hikâye üretmek.
- Uygulama: İsim-Şehir oyununda verilen harfle başlayan kelimeleri kategorilere göre üretmek. Hoca, kelimeler önceden verilmişse burada mantıksal bir çıkarım olmadığını belirtti.

### 7.5 Beşinci grup

- Toplama: bebeğin gözlemleyerek öğrenmesinden yola çıkarak, Google Street View gibi bir araçla çevreyi tarayıp görüntülere image captioning uygulamak ve en sık görülen cümleleri genel doğru kabul etmek.
- Toplama: gerçek hikâyelerdeki sıralı olaylardan "X bir yere gittiğinde şunu yapar" türü genel bilgiler çıkarmak.
- İyileştirme: çelişen bilgiler için oylama; oylama yapılamazsa frekansı yüksek olanı doğru kabul etmek; bilgi kaynaklarını güvenilirliğe göre puanlamak.
- Uygulama: toplanan bilgilerden görme engelli bir kişi için uyarı mekanizması üretmek (örneğin trafik ışığı ne zamandır kırmızıysa birazdan yeşile döneceği).

### 7.6 Altıncı grup

- Toplama: okuldaki öğrencilere günlük tutar gibi bir uygulama vermek; uygulama yaşadıkları olayları belirli sorularla (hocanın veri toplama tablosundaki gibi) yazdırır. Türkiye genelinde uygulanırsa çok sayıda öğrenciden yaşanmışlık bilgisi toplanabilir.

### 7.7 Yedinci grup

- Toplama: tıp dergilerindeki makalelerden yiyeceklerin duygu durumuna ve hastalıklara etkisini toplamak (örneğin çikolatanın mutlu etmesi), görsellerle zenginleştirmek.
- Uygulama: kişinin o anki duygu durumunu çıkarıp ona iyi gelecek besinleri önermek. Hoca bunu "sistem sizi sürekli gözleyecek ve durumunuza en uygun öneride bulunacak" diye özetledi.

## 8. NELL

### 8.1 Çalışma biçimi

NELL 2010'da çalışmaya başlamış bir sistemdir. Web sayfalarında gezinir ve hayat bilgisi türünden bilgileri ConceptNet'teki gibi bilgi üçlüleri biçiminde toplar: şu kavramla şu kavram arasında şu tür bir ilişki vardır. Yarı otomatiktir ve iteratif çalışır: bir web sayfasını bir kez işleyip bırakmaz, aynı sayfalara defalarca döner; yeni eklenen sayfaları da keşfeder.

Bilgi toplarken morfolojik çözümleme (bir kelimenin kökünün ve eklerinin ya da kelime türlerinin bulunması), HTML kodu şablonları ve metin şablonları kullanır.

Başlangıçta sisteme her ilişki türü için doğruluğu bilinen kavram ikilileri verilir; bunlara seed (tohum) denir. Hoca her ilişki için örneğin yüzer tane verildiğini söyledi. Sistem web sayfalarında gezerken bu ikililerden her ilişki türü için şablonlar öğrenir. Şablonlarla kendisine verilmemiş yeni kavram ikililerini bulur. Yeni ikililerden yeni şablonlar öğrenir. Yeni bilgiler yeni şablonları, yeni şablonlar yeni bilgileri getirir; süreç iteratif ilerler.

### 8.2 Şablon örneği: "Tüm X'ler Y'dir"

Hoca şablonu bir sonraki dersin notundan bir örnekle açıkladı. "Tüm X'ler Y'dir" bir IsA ilişkisidir. Önce aralarında IsA ilişkisi olduğu bilinen X, Y ikilileri (seed) web'de aranır. Dönen sayfalarda X ile Y'nin arasındaki ya da etrafındaki metinlere bakılır. Bu metinler ortaksa şablon olarak alınır; örneğin "X ve diğer Y". Sonra yeni bilgi elde etmek için yalnız şablon aranır ve şablonun sağındaki ve solundaki kavramlar arasında IsA ilişkisi olduğu varsayılır.

Türkçe için bulunan şablonlardan örnekler (ekrandan, 01:47:30):

- ve diğer
- ler ve diğer
- ve benzeri
- veya diğer
- türü olan
- ları ve diğer
- lar ve diğer
- ve her türlü
- lerden biri olan
- leri ve diğer
- larından biri olan
- lerinden biri olan
- lardan biri olan
- adı olan
- ve her tür

**Soru:** Bir öğrenci bu sistemin çok fazla yanılabilecek gibi göründüğünü söyledi. **Cevap:** Hoca, evet, yanılabileceğini ve bu yüzden aşağıdaki önlemlerin alındığını söyledi.

### 8.3 Kısıtlar

Slayttaki açıklama (ekrandan, 01:50:00): çevrim arttıkça üretilen şablonların ve bunlardan üretilen ilişkilerin doğruluğunun keskin biçimde düştüğünü gören tasarımcılar her şablonun bir kısıtı olması gerektiğine karar vermiştir. Örneğin "bu nerede yapılır" ilişkisi için bulunan kavram ikililerinden ilkinin bir eylem, ikincisinin bir mekân olması kısıtı konmuş, ikili bu kısıtlara uyuyorsa veri tabanına alınmıştır. Bu kısıtları koyabilmek için hangi kavramların eylem, hangilerinin mekân olduğuna dair bilginin de sisteme harici olarak verilmesi gerekir.

Tasarımcılar ayrıca kısıtlara uyan ve uymayan kavram ikililerinin sayılarını kullanarak şablonların güvenilirlik katsayılarını hesaplamıştır. Böylece veri kümesi büyüdükçe güvenilirliğin keskin biçimde azalmasının önüne geçilmiştir.

### 8.4 Güvenilirlik nasıl ölçülür?

Slayttaki yapı (ekrandan, 01:51:10):

- Şablon güvenilirliği: şablonun ürettiği ikililerin doğruluk oranı.
- İlişki güvenilirliği:
  - Üretildiği şablonun güvenilirliği.
  - Kaç farklı şablondan üretildiği.
  - Kullanıcı geri beslemeleri.

Şablon güvenilirliğini ölçmek için biraz elle iş gerekir: şablonun ürettiği ikililerden bir kısmına bakılıp gerçekten o ilişkiye sahip olup olmadıkları işaretlenir. Örneğin bir şablonun %60 olasılıkla doğru, %40 olasılıkla yanlış ürettiği bulunur. İlişki güvenilirliğinde tek bir şablondan üretilen ilişkiye daha az, çok sayıda şablondan ya da çok sayıda cümleden üretilen ilişkiye daha çok güvenilir. NELL'in web sayfasında kullanıcılar öğrenilen bilgilere yukarı/aşağı oy verebilir; bu oylar da ilişki güvenilirliğinde kullanılır.

Slayta göre NELL 2010'dan bu yana 50 milyon aday ilişki öğrenmiş, bunların 1,8 milyonunun güvenilirliği yüksektir. Bu, adayların yaklaşık %3,6'sıdır (ara adım eklendi: $1{,}8 / 50 = 0{,}036$).

## 9. Türkçe Hayat Bilgisi Veri Tabanı

### 9.1 Yaklaşım seçimi

Hoca, literatürdeki çalışmaların genelde İngilizce olduğunu ve Türkçe için ilk çalışmanın kendi grubunun bu çalışması olduğunu anlattı. Seçenekler şunlardı:

- Cyc gibi: uzman kişiler elle girer; az ama güvenilir bilgi.
- OpenMind gibi: gönüllüler girer.
- Mevcutları tercüme etmek ya da kullanmak: doğrudan kullanılamaz, tercüme etmek gerekir; bunun da sıkıntıları vardır.
- Frekans tabanlı bilgi çıkarımı.

Tercüme ve frekans tabanlı çıkarım kullanıldı. Veriler (kavram - ilişki türü - kavram) üçlüleri olarak tutuldu.

### 9.2 Veri kaynakları

Slayttaki akış (ekrandan, 01:53:30):

```text
ConceptNet        --> Google Translate --> SİSTEM
Original WordNet  --> Google Translate --> SİSTEM
Turkish WordNet   --------------------> SİSTEM
HTML Pages        --------------------> SİSTEM
```

O dönemde Google Translate bugünkü kadar başarılı değildi ama sonuçlar fena değildi. Türkçe WordNet küçüktü. Web sayfalarından bilgiler, bir sonraki derste anlatılacak şablonlar kullanılarak çıkarıldı. ConceptNet ve WordNet'in formatları farklıydı; veri tabanı oluşturulurken bu sorun çözüldü. Frekans tabanlı bilgi çıkarımında 400 bin web sayfasının HTML kodu üzerinde morfolojik çözümleyici olarak Zemberek kullanıldı. Otomatik çeviri sorunludur ama en az maliyetli yoldur.

### 9.3 Veri tabanından örnekler

Slayttaki tablo (ekrandan, 01:54:15). Her hücre bir kavram ikilisidir; sütun başlığı ilişki türüdür.

| Bunun için ne gerekir? | Neye sebep olur? | Bundan neler yapılır? |
|---|---|---|
| yazmak-araştırmak | öldürmek-ceza | taş-köprü |
| denemek-para | doğurmak-hayat | çelik-makine |
| uyumak-yatmak | sevmek-umut | su-bulut |
| seyahat etmek-enerji | sevmek-acı | kağıt-gazete |
| öğrenmek-okumak | ateş-acı | yün-kumaş |
| yaşam-yiyecek | öldürmek-üzüntü | kumaş-gömlek |

| Ne için kullanılır? | Bu ne yapabilir? | Nerede bulunur? |
|---|---|---|
| asker-savaş | kuş-uçmak | oda-bina |
| çatal-yemek | kişi-yürümek | kişi-oda |
| top-oynamak | bilgisayar-düşünmek | elbise-mağaza |
| ördek-yemek | çocuk-düşmek | kemik-kişi |
| hastalık-öldürmek | bıçak-kesmek | asker-savaş |
| baş-düşünmek | gemi-batmak | öğrenci-okul |

Hoca bunları "Yazmak için araştırmak lazım, denemek için para lazım, seyahat etmek için enerji lazım; sevmek umuda, sevmek acıya, ateş acıya, öldürmek üzüntüye sebep olur" diye okudu. Sonraki slaytta her ilişki türünden kaç bilgi olduğu ve bunların ConceptNet, özgün WordNet ve Türkçe WordNet'ten ne kadar geldiği gösterildi; derste sayılar okunmadı.

Otomatik çeviri hataları vardı; çevirinin hiç yapılamadığı durumlar bile oldu. Elle çeviri ölçeklenebilir bir yaklaşım değildir. Bunun yerine var olan bilginin kalitesini yükseltmek için çok sayıda kişiden geri besleme alınmasına karar verildi ve CSoyun geliştirildi.

## 10. CSoyun

### 10.1 Oyunlaştırma

CSoyun bir web sitesidir. Hoca, sitenin kendisinin değil içinde kullanılan tekniklerin önemli olduğunu vurguladı. Oyunlaştırma (gamification), insanlara bir iş yaparken zevkli bir oyun ortamı sunmaktır: puan alırlar, rütbe kazanırlar, yükselir ya da alçalırlar. İş yerleri ve soru-cevap siteleri bunu çok kullanır; cevaplarınız beğenildikçe puan almak bir motivasyon kaynağıdır.

CSoyun'un amacı veri tabanındaki (CSdb) bilgi sayısını ve kalitesini artırmaktır. Arkadaki veri tabanının bir kısmı gürültülüdür; amaç bu gürültüyü bir miktar gidermek ve yeni bilgiler eklemektir. Kullanıcıları teşvik etmek için puan kazandıkları beş oyun vardır. Kullanıcılar verdikleri her geri besleme için puan alır. Yeni kavram ve kavramlar arası yeni ilişki girebilirler; böylece bilgi sayısı artar. Yeni ilişki türü ise giremezler, bu kısıtlanmıştır.

Derste site açılmaya çalışıldı ama erişilemedi. Hoca, sitenin o dönemde Adobe Flash ile yazıldığını ya da sunucularda bir sorun olabileceğini söyledi.

### 10.2 Oyunlar

- **Bildiklerim:** Kullanıcı önce bir ilişki türü seçer, örneğin eş anlamlılık. Sistem o ilişkiye sahip kavram ikililerini rastgele gösterir. Kullanıcı her ikiliye 0'dan 5'e kadar altı basamaklı bir ölçekte oy verir.
- **Araştır:** Bir kavram ve bir ilişki seçilir; sistem o ilişkiye sahip kavramları gösterir, kullanıcı oy verir. Hocanın örneğinde "kedi nerede bulunur" için gelenlerden bazıları makul, bazıları saçmaydı: kanarya kafesi, restoran, Connecticut, ahır, temiz çamaşır gibi. Bunların bir kısmı İngilizceden çeviriden kaynaklanıyordu.
- **Tahminlerim:** Sistem var olan bilgilerden çıkarım yaparak adaylar üretir ve bunları kullanıcılara sorar; kullanıcılar doğru ya da yanlış diye derecelendirir. Örneğin sistem "yaşamanın ilk adımı hayal kurmaktır" gibi bir tahmin üretmiş, kullanıcı bunun doğru olup olmadığını söylüyor. Slayta göre bu oyun CSoyun'u benzer sistemlerden ayıran en önemli özelliktir (ekrandan, 02:00:00).
- **Bilgi girme oyunu:** Kullanıcıya bir kavram ve bir ilişki türü verilir; bu kavramla bu ilişkiye sahip kavramları listeler. Kullanıcının verdiği bilgi veri tabanında zaten varsa, yani başkaları da daha önce girmişse, bilgiye daha çok güvenilir ve kullanıcı ekstra puan alır. <!-- BELİRSİZ: Oyunun adı altyazıda "JSON'e bana öğret" diye bozuk; büyük olasılıkla "Sen Bana Öğret" benzeri bir ad. Ekstra puan koşulu da altyazıda bozuk ("GSD ile bulmuyorsa"); "veri tabanında bulunuyorsa" olarak yorumlandı. -->
- **İki kişilik oyun:** Rastgele eşleşen iki kişiye aynı soru sorulur. İki kişi aynı sorulara aynı cevapları verirse, yani cevapları tutarlıysa, o bilgilere daha çok güvenilebilir. <!-- BELİRSİZ: Oyunun adı altyazıda "Birlikte eğitim bana" diye bozuk. -->

### 10.3 Oylamanın mantığı

Kullanıcının söylediğinin doğru olup olmadığını bilmek mümkün değildir; bilseydik bu oyuna ihtiyacımız olmazdı, çünkü amaç zaten bilgilerin doğru olup olmadığını anlamaktır. Bunun yerine bir ilişkiye verilen oyların ortalamasına bakılır. Bazıları yanlış söyleyebilir, ama genel olarak doğru söyleyenlerin daha çok olacağı varsayılır. Hoca bunu "burada bir şekilde demokrasiye güveniyoruz" diye anlattı. Bir ilişkiye ne kadar çok insan oy verirse ilişkinin güvenilirliği o kadar artar.

Hoca, iki yılda epey bilgi toplandığını, ama bütün verilerin oylanmasının bu hızla on yıl kadar süreceğini söyledi.

## 11. Monotonik ve Monotonik Olmayan Çıkarım

### 11.1 Monotonik çıkarım

"Bütün X'ler Y'dir" ve "Bütün Y'ler Z'dir" verildiğinde kolayca "Bütün X'ler Z'dir" çıkarılır. Bu monotonik bir çıkarımdır ve sonucu kesindir.

Peki böyle bir bilgiyi çıkarıp veri tabanına kaydetmeye gerek var mı? İnsanlar çıkarabildikleri her şeyi çıkarıp beyinlerinde depolamaz. Sık karşılaşmadıkları şeyleri gerektiğinde çıkarırlar. Hoca bunu şu soruyla gösterdi: "Bir kaplumbağanın sol ön ayağındaki bir hücrenin endoplazmik retikulumu var mıdır?" Muhtemelen daha önce hiç duymadığımız bu soruya "vardır" deriz. Çünkü kaplumbağanın bir hayvan olduğunu, sol ön ayağındaki hücrenin bir hayvan hücresi olduğunu ve hayvan hücrelerinde endoplazmik retikulum bulunduğunu biliriz. Ama "kaplumbağanın sol ön ayağındaki hücrede endoplazmik retikulum vardır" bilgisini, sağ ayaktaki, sol arka ayaktaki hücreler için de ayrı ayrı aklımızda tutmayız. Bunun yerine bilgiyi gerektiğinde çıkarılabilecek hiyerarşik bir yapıda tutarız. Hoca buna bilgi ekonomisi dedi; insanların bilgiyi bu şekilde tuttukları varsayılır.

Dolayısıyla monotonik çıkarım yapıp elde edilen bilgileri veri tabanına eklemenin bir anlamı yoktur; bunlar zaten gerektiğinde elde edilebilir. Kesin doğru ya da kesin yanlış olduğu bilinen bir şeyi çıkarıp kaydetmek anlamsızdır.

> **Ek bilgi (derste anlatılmadı):** Hiyerarşik bellekte özelliklerin en genel düzeyde bir kez saklanıp alt kavramlara kalıtımla aktarıldığı fikri büyük olasılıkla Collins ve Quillian'ın (1969) anlamsal ağ modelindeki "bilişsel ekonomi" (cognitive economy) ilkesine dayanır.

### 11.2 Monotonik olmayan çıkarım

Önemli olan, çıkarıldığında doğru olmama ihtimali olan şeyleri üretmektir. Böyle bir çıkarımın sonucu doğru mu yanlış mı belli değildir; bu yüzden insanlara sorulur.

> **Ders sonrası not:** Hoca bu noktada "Monotonik çıkarım da bu." dedi. Bağlama göre kastedilen "monotonik olmayan çıkarım"dır; büyük olasılıkla dil sürçmesi ya da altyazı hatasıdır.

Slayttaki çıkarım kuralları ve örnekleri (ekrandan, 02:00:00). X, Y, Z, T kavramlar; R1, R2, R3 ilişki türleridir.

| Çıkarım türü | Örnek çıkarım |
|---|---|
| (X-R1-Y) ve (Y-R2-Z) → (X-R3-Z) | (martı - altkavramıdır - kuş) ve (martı - bu ne yapabilir - uçmak) → (kuş - bu ne yapabilir - uçmak) |
| (X-R1-Y) → (X-R2-Y) | (sinemaya gitmek - içerdiği olaylar nelerdir - mısır yemek) → (sinemaya gitmek - bunun için ilk önce ne yaparsın - mısır yemek) |
| (X-R1-T) ve (Z-R1-T) ve (X-R2-Y) → (Z-R2-Y) | (kedi - altkavramıdır - memeli) ve (köpek - altkavramıdır - memeli) ve (kedi - sahiptir - kürk) → (köpek - sahiptir - kürk) |
| (X-R1-Y) ve (X-R2-Z) → (Z-R3-Y) | (bıçak - nerede bulunur - mutfak), (bıçak - ne için kullanılır - kesmek) → (kesmek - nerede yapılır - mutfak) |

Martı örneğinde elimizde iki bilgi vardır: martı bir tür kuştur ve martı uçabilir. Kurala göre bunlardan "kuş uçabilir" çıkarılır. Burada üst kavramın yapabildiği bir şey alt kavrama aktarılmıyor (bu monotonik olurdu); alt kavramın yapabildiği bir şey üst kavrama aktarılıyor. Bu doğru da olabilir yanlış da. Aynı kural penguene uygulansa (penguen bir kuştur, penguen uçamaz) sistem "kuş uçamaz" sonucunu çıkarır. Sonuç bu yüzden kesin bilgi olarak değil aday olarak veri tabanına eklenir.

Kedi-köpek örneğinde aynı üst kavrama (memeli) bağlı iki kardeş kavram vardır. Kardeşlerden birinin sahip olduğu bir şeye diğerinin de sahip olup olmadığı anlaşılmaya çalışılır. "Köpek kürke sahiptir" üretildikten sonra doğru olup olmadığı kullanıcılara sorulur. Bıçak örneğinde de bıçağın bulunduğu yer ile kullanıldığı iş birleştirilerek "kesmek mutfakta yapılır" hipotezi üretilir.

Hoca, kuralların monotonik olup olmamasının R1 ve R2'nin ne olduğuna göre değiştiğini, ama temel fikrin zaten doğru ya da zaten yanlış olanı değil, belirsiz olanı üretmek olduğunu belirtti. Slayta göre bu hipotezler hipotezler tablosuna kaydedilir, onaylandıklarında ilişkiler tablosuna aktarılır.

## 12. Hayat Bilgisi Veri Tabanlarının Kalitesi

Slayttaki ölçütler (ekrandan, 02:06:55):

- Doğruluk: sistemden rastgele seçilecek 100 ilişkiden yüzde kaçının bir insan tarafından doğru olarak nitelendirildiği.
- Kapsayıcılık: gereken tahmini bilgi sayısı milyonlardır.
  - Kavram sayısının yeterliliği.
  - İlişki sayısının yeterliliği.
- Bu ölçümlerle, sürekli gelişen bir sistemin kapsayıcılık ve doğruluk performanslarının zaman içindeki değişimi izlenebilir.

Doğruluk elle kabaca ölçülebilir. Hocaya göre asıl kritik konulardan biri kapsayıcılıktır. İnsanların bilgisi büyük olasılıkla doğrudan bu üçlü formatında değildir, ama elimizdeki yapının kapsayıcı olup olmadığını bilmek gerekir: az miktarda ama çok kaliteli bilgi yetmez.

Kavram sayısının yeterliliği için örneğin büyük metin derlemlerindeki kavramların yüzde kaçının veri tabanında bulunduğuna bakılabilir. Kavram tek bir kelime olmak zorunda değildir; birden fazla kelimeden oluşan bir öbek (phrase) de olabilir. <!-- BELİRSİZ: Bu ölçütte geçen kaynak adı altyazıda bozuk ("Büyük Metin Kikipanelerindeki"); "büyük metin derlemleri" olarak yorumlandı. -->

İlişki sayısının yeterliliği için örneğin bir insana rastgele bir kavram verilip belirli bir sürede aklına gelecek ilişkilerin yüzde kaçının veri tabanında bulunduğuna, ya da bir ilişki türü verilip insanın aklına gelecek ilişkilerin ne kadarının bulunduğuna bakılabilir. İnsanlar birbirinden farklı olduğu için bu ölçümlerde tek kişi yetmez, çok sayıda kişiyle yapılmalıdır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:20:00): Küçük bir kız babaannesini ziyaret etmek için ormanda yürümeye başlıyor. Çalılıkların arkasındaki aç bir kurt kızı görüyor ve onu yemeye karar veriyor. Küçük kıza tam saldıracakken oduncuların şarkılarını duyuyor. Çalılıkların ardında saklanıp kararından vazgeçiyor. (a) Kurt kararından neden vazgeçti? (b) Küçük kız korktu mu?

> **Çözüm (derste verildi):** (a) Kurt saldırırsa kız bağırır; yakındaki oduncular çığlığı duyup oraya gelir; bir kurdun kıza saldırdığını görünce kızı kurtarmak için kurda zarar verir, belki öldürür. Öldürülmek kurt için istenmeyen bir sonuç olduğundan kurt vazgeçer. Bu zincirin hiçbir halkası metinde yazmaz; hayat bilgisiyle çıkarılır. (b) Metinde kızın kurdu fark ettiğine dair bir bilgi yoktur. Kız kurdu görseydi kaçar ya da bağırırdı; dolayısıyla kızın korktuğu söylenemez.

**Soru 2** (ekrandan, 00:24:20): "Yemeğim 5 dakikada geldi. Çok teşekkürler XXX." ve "Yemeğim 55 dakikada geldi. Çok teşekkürler XXX." cümlelerinin duygu durumu nedir? Bunu belirlemek için ne gerekir?

> **Çözüm (derste verildi):** Birincisi olumlu, ikincisi kinayeli ve olumsuzdur. Aradaki fark tek karakterdir (5 / 55); bunu ayırt etmek için bir yemeğin normalde ne kadar sürede geldiğine dair hayat bilgisi gerekir. "55 dakika uzundur" tek başına anlamlı değildir; yemek için uzun, film için kısadır.

**Soru 3** (derste sözlü, 02:00:32): Bir kaplumbağanın sol ön ayağındaki bir hücrenin endoplazmik retikulumu var mıdır? Bu bilgiyi aklımızda saklar mıyız?

> **Çözüm (derste verildi):** Vardır: kaplumbağa bir hayvandır, ayağındaki hücre bir hayvan hücresidir, hayvan hücrelerinde endoplazmik retikulum bulunur. Bu bilgi saklanmaz; monotonik bir çıkarımla gerektiğinde üretilir. Bu yüzden monotonik çıkarımla elde edilen bilgileri veri tabanına eklemenin anlamı yoktur.

**Soru 4** (ekrandan, 02:00:00): Monotonik çıkarım nedir? Monotonik olmayan çıkarım nedir?

> **Çözüm (derste verildi):** Monotonik çıkarımda sonuç kesindir: "Bütün X'ler Y'dir" ve "Bütün Y'ler Z'dir"den "Bütün X'ler Z'dir" çıkar. Monotonik olmayan çıkarımda sonuç doğru da yanlış da olabilir; örneğin (martı - altkavramıdır - kuş) ve (martı - bu ne yapabilir - uçmak) bilgilerinden (kuş - bu ne yapabilir - uçmak) çıkarılır, ama aynı kural penguene uygulanınca "kuş uçamaz" gibi yanlış bir sonuç verir. CSoyun yalnız monotonik olmayan çıkarımların sonuçlarını hipotez olarak üretip kullanıcılara sorar.

**Soru 5** (ekrandan, 02:00:00): (kedi - altkavramıdır - memeli), (köpek - altkavramıdır - memeli) ve (kedi - sahiptir - kürk) bilgilerinden hangi kuralla hangi hipotez üretilir?

> **Çözüm (derste verildi):** Kural (X-R1-T) ve (Z-R1-T) ve (X-R2-Y) → (Z-R2-Y). X = kedi, Z = köpek, T = memeli, R1 = altkavramıdır, R2 = sahiptir, Y = kürk. Üretilen hipotez: (köpek - sahiptir - kürk). Aynı üst kavrama bağlı kardeş kavramlardan birinin özelliği diğerine aktarılır; sonuç kesin olmadığı için kullanıcılara sorulur.

## Dersin Toparlaması

Bu derste hayat bilgisinin, herkesin bildiğini varsaydığımız ve bu yüzden metinlerde açıkça yazılmayan bilgiler olduğu görüldü. Makinelerin "Ali lokantada yemek yedi"den "para ödemiştir" sonucunu çıkarabilmesi, kurt ve kız hikâyesindeki soruları cevaplayabilmesi ya da "55 dakikada geldi, çok teşekkürler" cümlesindeki kinayeyi anlayabilmesi için bu bilgiye ihtiyaç vardır. Hayat bilgisi veri tabanları ya az sayıda uzmanla (Cyc) ya çok sayıda gönüllüyle (OpenMind/ConceptNet) ya da yarı otomatik olarak web'den (NELL) oluşturulur. NELL'in şablon öğrenme döngüsü, kısıtları ve güvenilirlik hesabı; Türkçe veri tabanının çeviri ve frekans tabanlı çıkarımla kurulması; CSoyun'da oyunlaştırma, oylama ve monotonik olmayan çıkarımla hipotez üretimi incelendi. Son olarak bir hayat bilgisi veri tabanının doğruluk ve kapsayıcılık açısından nasıl değerlendirileceği anlatıldı.

Bir sonraki derste bölümün ikinci kısmı olan otomatik bilgi çıkarımına geçilecek: hayat bilgisi türündeki bilgilerin metinlerden şablonlar gibi tekniklerle otomatik olarak nasıl çıkarılabileceği.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
