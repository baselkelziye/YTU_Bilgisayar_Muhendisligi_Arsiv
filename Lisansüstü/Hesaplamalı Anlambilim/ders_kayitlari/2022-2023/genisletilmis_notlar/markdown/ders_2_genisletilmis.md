# Ders 2 Genişletilmiş Notu: Hayat Bilgisi Veritabanları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Geçen Dersten Bağlantı: Prolog Örneği ve "Bilinmesi Gerekenler"
- 2. Hayat Bilgisi Nedir?
- 3. Hayat Bilgisi Veritabanına Neden İhtiyaç Var?
- 4. Hayat Bilgisi Veritabanları Nasıl Oluşturulur?
- 5. ConceptNet
- 6. Grup Etkinliği: Hayat Bilgisi Toplama ve Kullanma Fikirleri
- 7. NELL: Never-Ending Language Learning
- 8. Türkçe Hayat Bilgisi Veritabanı ve CSoyun
- 9. Monotonik ve Monotonik Olmayan Çıkarım
- 10. CSoyun İstatistikleri
- 11. Hayat Bilgisi Veritabanlarının Kalitesi
- Örnek Sorular
- Dersin Toparlaması

## 1. Geçen Dersten Bağlantı: Prolog Örneği ve "Bilinmesi Gerekenler"

Hoca derse, geçen hafta anlatılan iki temel yaklaşımı hatırlatarak başladı. Bunlardan biri **formal anlambilim**, yani kural tabanlı yaklaşımlardı. Bu yaklaşımda sistemin yapmasını istediğimiz şeyleri mümkün olduğunca kodlamaya, kuralların içine gömmeye çalışırız. Sonlu durum makineleri ve uzman sistemler bu ailedendir. Cümle çözümleme ve morfolojik analiz belli bir dereceye kadar bu tür kural yapılarıyla yapılabilir. Kural tabanlı yapılarla yapılabilen bir başka iş de **çıkarım**dır.

### 1.1 Prolog ile çıkarım örneğinin hatırlatılması

Geçen dersteki örnekte bir paragraf ve bir soru veriliyordu (ekrandan, 00:05:40):

- "Ali okula gittiğinde öğlen yemeğini kantinde yer. Ali eve gittiğinde öğlen yemeğini mutfakta yer. Ali sınıfta kitap okudu."
- Soru: "Ali öğlen yemeğini nerede yedi?"

Bu soruya kural tabanlı bir yapıyla cevap verilebiliyordu. Ama sistemin cevap verebilmesi için paragrafta **yazmayan** bazı bilgileri de bilmesi gerekiyordu. Slaytta "Burada bilinmesi gerekenler" başlığıyla şunlar sayıldı:

- Birisi bir yerde bulunmuşsa oraya gitmiştir.
- Birisi bir yere gitmişse o yeri içine alan yere de gitmiştir.
- Sınıf okulun içindedir.
- Oda evin içindedir.

Hoca, bu dersin konusunun tam olarak bu alt kısım, yani "bilinmesi gerekenler" olduğunu söyledi. Sadece soru cevaplarken değil, bütün konuşmalarımızda karşı tarafın bazı şeyleri bildiğini varsayarız. Bu ortak bilgi üzerinden karşı tarafın bilmediği konuları konuşur, haber veririz.

### 1.2 Prolog kodundaki yapı

Hoca örnekte Prolog (Programming in Logic) dilinin kullanıldığını hatırlattı. Kodda cümleler şu yapıda tutulmuştu (ekrandan, 00:07:45):

```text
vardir(yüklem, özne, belirtilinesne, dolaylıtümleç, cümleno)
```

Slayttaki kod şöyledir:

```prolog
kapsar(oda,ev).
kapsar(sinif,okul).
vardir(oku,ali,kitap,sinif,12).
vardir2(git,M,_,Yer,_) :- vardir(_,M,_,Yer,_).
% M Yer'de bulunmussa -> M Yer'e gitmistir
vardir2(F,M,B,Yer1,I) :- kapsar(Yer2,Yer1), vardir2(F,M,B,Yer2,I).
% M Yer2'de birsey yapmissa ve Yer2 Yer1'i kapsiyorsa -> M Yer1'de de ayni seyi yapmistir
vardir2(yer,ali,oglenyemegi,mutfak,_) :- vardir2(git,ali,_,ev,_).
% ali eve gitmisse -> oglenyemegini mutfakta yer
vardir2(yer,ali,oglenyemegi,kantin,_) :- vardir2(git,ali,_,okul,_).
% ali okula gitmisse -> oglenyemegini kantinde yer
```

Slayta göre `vardir` ilişkisi gerçek cümleleri (bilgileri), `vardir2` ilişkisi ise türetilen cümleleri (bilgileri) ifade eder.

Hoca bu yapının yalnız basit cümleleri ifade edebildiğini düşünmenin doğru olmadığını söyledi. Örneğin belirtili nesne ya da özne başka bir alt cümle olabilir; yapı iç içe kurularak daha karmaşık hâle getirilebilir.

Hocaya göre bu örnekte soruyu cevaplamayı sağlayan, ama paragrafta doğrudan yazmayan şey neyse, bugün ona **hayat bilgisi** diyeceğiz.

## 2. Hayat Bilgisi Nedir?

Hayat bilgisi, İngilizcesiyle **commonsense**, herkesin bildiğini varsaydığımız bilgilerdir. Slayttaki örnekler şunlardır (ekrandan, 00:10:00):

- İnsanlar her gün yemek yer.
- İnsanlar geceleri uyur.
- Balıklar denizde yaşar.
- Elma yuvarlaktır.
- Kediler miyavlar.

Hoca bu bilgilerin istisnaları olabileceğini kabul etti, ama genel anlamda böyle bilgilere sahip olduğumuzu söyledi. "İnsanlar ne zaman uyur?" diye sorulduğunda "geceleri" deriz. "İnsanlar ne sıklıkla yemek yer?" diye sorulduğunda birkaç saatte bir gibi bir cevap verilir; "iki günde bir" gibi bir cevap beklenmez.

## 3. Hayat Bilgisi Veritabanına Neden İhtiyaç Var?

Bu tür bilgilerden oluşan bir veritabanına **hayat bilgisi veritabanı** denir. Slayttaki ana fikir şudur: bilgisayarlar, söylediklerimizden söylemediklerimizi tahmin edemez.

Geçen dersteki örnekte paragrafın içinde soruyu cevaplamaya yetecek bilgi yoktu. Bu, bizim cevap vermemize engel değildi, ama makineler bu bilgiye sahip olmadığında cevap veremezler. Bu bilgiler makineye verilebilirse, hoca örneğine göre, bir kişinin lokantada yemek yediğini söyleyen bir cümleden "Ali para ödemiştir" bilgisi çıkarılabilir. <!-- BELİRSİZ: 00:11:09'da öncül cümle bozuk çıkmış ("Şahil Lokantı diye mekili cümlesine"); "Ali lokantada yemek yedi" benzeri bir cümle olduğu tahmin ediliyor. -->

İnsanlar bu bilgileri kabaca yaşayarak edinir. Doğduğumuzda bu bilgilerin çok büyük kısmı bizde yoktur. Soru şudur: yaşayarak öğrendiğimiz bu bilgileri belli bir biçime sokup makineye verebilir miyiz?

### 3.1 Duygudurum analizi örneği

Hoca, hayat bilgisinin gerekliliğini duygudurum analizi (bir ifadenin olumlu mu olumsuz mu olduğu) üzerinden gösterdi (ekrandan, 00:12:30). Slayttaki cümlelerde "XXX" bir firmayı temsil ediyor:

- "Yemeğim 5 dakikada geldi. Çok teşekkürler XXX."
- "Yemeğim 55 dakikada geldi. Çok teşekkürler XXX."

Birinci cümle olumludur. İkinci cümle "çok teşekkürler" dese de imalıdır, genel anlamda olumsuzdur; hocanın deyişiyle "55 dakikada yemek mi getirilir kardeşim, çok teşekkürler". İki cümle arasında şekilsel olarak tek bir karakter farkı vardır: birinde 5, diğerinde 55. Birinin olumlu, diğerinin olumsuz olduğunu söyleyebilmek için yemeğin ortalama kaç dakikada getirildiğini bilmek gerekir. Bu bilgi olmadan doğru karar vermek mümkün değildir.

Hoca burada bağlamın da önemli olduğunu ekledi. Kişi dağın başında yaşıyorsa ve oraya yemek gerçekten geç ulaşıyorsa, 55 dakika da teşekküre değer olabilir. Kimin, nereden söylediği önemlidir. Ama istisnalara gitmeden düz düşünürsek, yemek siparişinde 5 dakika iyi, 55 dakika kötü bir şeydir.

İkinci örnek çifti:

- "XXX sayesinde 1 saatlik filmi 3 saatte izledim."
- "XXX sayesinde 1 saatte 10 film indirdim."

Birincisi olumsuz, ikincisi olumludur. Burada da şekilsel farklar azdır. Birincinin kötü olduğunu anlamak için film izlemenin ve indirmenin normalde ne kadar sürdüğünü bilmek gerekir: bir saatlik filmin üç saatte izlenmesi muhtemelen bağlantının kesildiğini, donduğunu, bant genişliğinin çok düşük olduğunu gösterir. İkincisinde yüksek bir hızdan söz ediliyor. Hoca yine bağlama dikkat çekti: yaklaşık 20 yıl önceki Türkiye altyapısı düşünülürse bir saatlik filmi üç saatte izlemek belki o kadar da kötü sayılmazdı.

## 4. Hayat Bilgisi Veritabanları Nasıl Oluşturulur?

Hoca bunun yeni değil, eski bir soru olduğunu söyledi. Yapay zekânın tarihine bakıldığında hayat bilgisi probleminin birçok problemin önünde bir duvar gibi durduğu görülür: hikâye anlamadan makine çevirisine kadar, uzman sistemlerde de hayat bilgisi büyük bir sorundur. Bu yüzden hayat bilgisi veritabanı oluşturma çalışmaları, büyük girişimler anlamında, 1980'lerin başına kadar uzanır; daha öncesi de vardır.

### 4.1 İki temel yaklaşım

Slayttaki iki yaklaşım şunlardır (ekrandan, 00:20:00):

- **Bilgileri az sayıda bilgi mühendisi özenle girsin yaklaşımı:** Cyc, 20 yılda 1,5 milyon kaliteli bilgi.
- **Bilgileri çok sayıda web kullanıcısı girsin yaklaşımı:** OpenMind, 8000 kişi, 3 yılda 1 milyon bilgi.

Birinci yaklaşımda uzman kişiler kontrollü biçimde, söyledikleri her şeye güvenilerek, bilgileri formal bir yapıda girer. Cyc'in kendine ait bir dili, bilgilerin girilmesi gereken bir formatı vardır. Uzmanlar bilgileri bu formata uygun girer. Bu iş 20 yıl boyunca sürmüş ve yaklaşık 1,5 milyon bilgi oluşturulmuştur.

> **Ek bilgi (derste anlatılmadı):** Cyc'in bilgi temsil dili CycL olarak bilinir. Hoca dersteki anlatımda bu dilin adını tam söylemedi; ad büyük olasılıkla CycL'dir.

İkinci yaklaşımın mantığı, hayat bilgisinin tanımından gelir: madem bu bilgileri herkesin bilmesi gerekiyor, o zaman herkes girsin. Bu durumda sokaktaki insanın önüne formal bir yapı koymak süreci hızlandırmaz. Format basitleştirilebilir, ama temelde insanlar bilgileri serbest biçimde (free form), cümleler hâlinde girer. Bunu OpenMind yapmıştır: 8000 gönüllü, 3 yılda 1 milyon bilgi. Bu çalışma zamanla evrilmiş, yeni sürümleri hâlâ çıkmaktadır.

İki yaklaşımın karşılaştırması:

- **Kişiler:** birincisinde profesyoneller, ücret ödenen kişiler; ikincisinde gönüllüler.
- **Altyapı:** birincisi internet yokken başlamış bir süreçtir. İkincisi interneti kullanır; başka türlü o kadar kişiden bilgi toplamak kolay olmazdı.
- **Bilgi sayısı:** çok büyük fark yoktur.
- **Hız:** ikincisi daha hızlıdır.
- **Güvenilirlik:** birincisi daha güvenilirdir. Gönüllülerden alınan bilgide tutarsızlıklar çok daha fazladır. Hoca bunu çözmenin yollarından sonra bahsedeceğini söyledi.

### 4.2 Popüler çalışmalar

Slayttaki liste (ekrandan, 00:20:30):

- **Cyc** (1984, anlamsal ağ, uzman kişiler, elle).
- **WordNet** (1985, anlamsal ağ, uzman kişiler, elle).
- **OpenMind / ConceptNet** (2002, gönüllü kullanıcılar, otomatik).
- **NELL** (2010, hayat bilgisi, yarı otomatik).

Hoca 2020 civarında başka bir çalışmanın daha çıktığını söyledi. <!-- BELİRSİZ: 00:20:27'de çalışmanın adı "Cassandra" gibi çıkmış; slaytta yok, doğrulanamadı. --> Daha sonra bu tür bilgileri dil modelleriyle birlikte kullanan yaklaşımlar da ortaya çıktı. Burada dil modeli derken hem istatistiksel hem sinirsel dil modelleri kastediliyor. Bir kısım yaklaşım ikisini birlikte kullanır. Bir kısmı ise sinirsel dil modelinin çok büyük miktarda veriyle eğitildiği için bu bilgileri zaten öğrendiğini, ekstradan bir şey yapmaya gerek olmadığını savunur.

## 5. ConceptNet

### 5.1 ConceptNet'in oluşturulması

Hoca OpenMind'dan ConceptNet'e geçişi anlattı. İnsanların cümle hâlinde girdiği bilgiler **bilgi üçlülerine** çevrilir. Üçlü, temelde "şu kavram ile şu kavram arasında şu türden bir ilişki vardır" anlamına gelir. Slayttaki iki aşama şunlardır (ekrandan, 00:22:20):

- **Çıkarım aşaması:** gönüllü kullanıcıların serbest formda girdikleri cümlelerden (OMCS corpus) cümle → bilgi üçlüsü dönüşümü yapılır. Tüm bilgilerin %90'ı buradan gelir.
- **Zenginleştirme aşaması:** mevcut bilgilerden yeni bilgiler üretilir. Tüm bilgilerin %10'u buradan gelir.

Hoca iki "çıkarım" kelimesinin farklı anlamlarına dikkat çekti. Birinci aşamadaki çıkarım, cümlelerden bilgi çıkarmadır (information extraction). Zenginleştirme aşamasındaki ise mantıksal çıkarımdır: üçlülerden yeni üçlüler üretmek. Burada monotonik ya da monotonik olmayan akıl yürütme (reasoning) diye bilinen yaklaşımlar kullanılır; hoca bunlara dersin ilerleyen kısmında döndü (Bölüm 9).

> **Ek bilgi (derste anlatılmadı):** OMCS, Open Mind Common Sense projesinin kısaltmasıdır. MIT Media Lab'de başlatılan bu proje, ConceptNet'in kaynak derlemidir.

### 5.2 ConceptNet'in yapısı

Slayta göre ConceptNet'te 1,6 milyon (kavram-ilişki-kavram) üçlüsü ve 20 ilişki türü vardır (ekrandan, 00:24:10). Slayttaki şekil, ilişki türlerini gruplar hâlinde gösterir:

- **Nesneler (THINGS):** IsA, PartOf, PropertyOf, MadeOf, DefinedAs.
- **Mekânsal (SPATIAL):** LocationOf.
- **Olaylar (EVENTS):** SubeventOf, LastSubeventOf, PrerequisiteEventOf, FirstSubeventOf.
- **Nedensel (CAUSAL):** EffectOf, DesirousEffectOf.
- **Duygusal (AFFECTIVE):** DesireOf, MotivationOf.
- **İşlevsel (FUNCTIONAL):** UsedFor, CapableOfReceivingAction.
- **Ajanlar (AGENTS):** CapableOf.

Hoca bu ilişkilerin şu tür ifadelere karşılık geldiğini söyledi: "bu şunun için kullanılır", "bu şunun bir parçasıdır", "bu bir tür şudur", "bunu yapmak için önce şunu yapmalısın", "şu durumda ajan şunu ister", "böyle yaparsan sonucu şu olur". İlişki türleri binlerce değildir; ilk sürümde yaklaşık 20 tanedir ve bu 20 ilişki türü için 1,6 milyon üçlü oluşturulmuştur.

### 5.3 Grafik gösterim

Slayttaki ConceptNet örneğinde mavi kapalı çizgilerle gösterilen düğümler kavramlar, aralarındaki oklar ilişkiler, okların üstündeki etiketler ise ilişki türleridir (ekrandan, 00:24:55). Şekildeki ilişkiler metin olarak şöyledir:

```text
wake up in morning --PrerequisiteOf--> eat breakfast
wake up in morning --MotivationOf--> get to bed early
wake up in morning --Generalization--> wake up      (slaytta "Generdisation" yazılı)
wake up --UsedFor--> alarm clock
wake up in morning --SubeventOf--> yawn
wake up in morning --SubeventOf--> check e-mail
wake up in morning --SubeventOf--> drink coffee
in house --LocationOf--> kitchen table
kitchen table --PartOf--> chair
kitchen table --UsedFor--> eat breakfast
eat breakfast --EffectOf--> full stomach
eat breakfast --SubeventOf--> chew food
eat breakfast --SubeventOf--> read newspaper
```

### 5.4 Uygulamalar

Bu büyüklükte bir veri ortaya çıkınca bununla birçok çalışma yapılmış. Hoca iki örnek verdi:

- Kullanıcının yazdığı e-postayı inceleyip içine uygun fotoğraf öneren bir sistem. Kullanıcının elinde etiketli resimler olabilir ya da sistem resimleri kendisi etiketleyebilir; yazılanlara uygun olanlar eklenir.
- Hikâye üretme: ConceptNet'i kullanan MakeBelieve adlı bir program küçük hikâyeler yazabiliyordu.

## 6. Grup Etkinliği: Hayat Bilgisi Toplama ve Kullanma Fikirleri

Hoca dersi etkileşimli yapmak için öğrencileri üçer kişilik gruplara ayırdı ve yaklaşık 15 dakika süre verdi. Görev şuydu: hayat bilgisi toplamak, toplanmış olanı iyileştirmek ya da hayat bilgisinin toplandığını varsayıp onu kullanan uygulamalar için yeni fikirler geliştirmek. Her grup bir sözcü seçip fikirleri sınıfa aktardı. Aşağıda grupların akademik içeriği adsız olarak verilmiştir.

### 6.1 Sosyal medya tepkilerinden bilgi toplama

Bir grup, güvenilir olarak belirlenmiş kişilerin sosyal medya gönderilerine verilen tepki ve yorumlardan bilgi toplamayı önerdi. Hoca somut bir örnek istedi. Örnek: biri "yarın kar yağacak" diye bir gönderi atıyor; altına "yarın okullar tatil mi?" ve "kar lastiği takmak lazım" gibi yorumlar geliyor. Buradan kar yağması ile okulların tatil olması ve kar lastiği takılması arasında ilişkisel bilgi çıkarılabilir. Çıkarılan bu bilgiler daha sonra başka kişilerce bir web sitesinde oylanarak doğrulanacaktır.

### 6.2 Hava durumu, duygu durumu ve eylem ilişkisi

Başka bir grup da sosyal medyayı kaynak olarak düşündü, ama duygu analizi yönünden. Örneğin biri "hava kapalı, bugün bir şey yapasım yok" diye bir gönderi atıyor ve gönderi çok paylaşılıyor. Yorumlardan, kapalı havanın bazı insanları olumlu, bazılarını olumsuz etkilediği ve farklı eylemlere yol açtığı görülebilir. Buradan "insanların yüzde x'i şu hava durumunda şu duygu durumundadır ve şu olasılıkla şu eylemleri yapar" türünden bir bilgi çıkarılabilir; örneğin kapalı havada insanların bir kısmının karamsar olup evde kalması. Grup, gönderinin hangi gün atıldığının da önemli olduğunu ekledi: hafta sonu ve hava güzelse "sahilde yürümeye gider" gibi bir çıkarım yapılabilir.

### 6.3 Temel bilgiler, kural ve düzeltme

Bir grup küçük bir deneme yaptı. Hayat bilgisi olarak "insanlar hastalanır", "insanlar hastaneye gider", "hastanede doktorlar çalışır", "insanlar doktora gider", "insanlar hastalanınca ilaç kullanır" gibi cümleler seçtiler. Bunlardan "bir insan hastanedeyse hastadır", "bir insan ilaç kullanıyorsa doktor vermiştir" gibi çıkarımlar yapılabilir. İyileştirme (düzeltme) olarak da "hastanedeki insan doktorsa hasta olmayabilir" gibi bir istisna eklenir. Ayrıca kullanıcıların başkalarının girdiği bilgilerle ilgili yan bilgiler girebileceği, seçenekleri kısıtlı (açılır kutu) ya da serbest bir program tasarlanabilir. Hoca bunu "farklı insanlar hayat bilgisi girer, arkasından aralarında çıkarım yapan ve düzelten bir mekanizma çalışır" diye özetledi.

### 6.4 Oylama ile doğrulama, tutarsızlık ve zarar tespiti

Bir grup, kullanıcıların girdiği hayat bilgisini diğer kullanıcıların onaylamasını (upvote/downvote) önerdi. Hayat bilgisi topluluğun kabul ettiği bilgi olduğu için, böyle bir teyit sistemi hem yeni bir veritabanı kurmak hem de var olanı düzeltmek için kullanılabilir.

Uygulama olarak, güvenilir bir hayat bilgisi veritabanı varsa bir kişinin söylediğinin yalan olup olmadığı tespit edilebilir. Örnek: "Ali okula gitti. Ben ders dinlerken televizyon izledim, dedi." Veritabanında "okulda televizyon yoktur" bilgisi varsa Ali'nin yalan söylediği çıkarılabilir. Hoca bunu **tutarsızlık tespiti** olarak adlandırdı. Grubun ikinci uygulaması, eylemleri yararlı ya da zararlı diye sınıflandırmaktı: "Ali 5. kattan aşağı atlayacak" denildiğinde model bunun zararlı bir eylem olduğunu söylemeli.

### 6.5 Reklam önerisi, romanlardan bilgi ve tedarik zinciri

Bir grup üç fikir sundu:

- **Reklam önerisi:** "telefon satın alan kılıf da satın alır" gibi bir bilgiyle, telefon reklamının yanına kılıf reklamı da gösterilir. Hoca bunu "elimizdeki reklam önerilerini hayat bilgisi veritabanıyla güncellemek" diye yeniden ifade etti.
- **Romanlardan bilgi çıkarma:** hikâye ve romanlardaki yer ve kişi adlarından, kişi adlarının hangi ülkeye özgü olduğu çıkarılabilir. Hoca soru-cevapla netleştirdi: burada veritabanı kullanılarak bir sonuç çıkarılmıyor; romanın kendisinden kişi ve yer bilgisi çıkarılarak yeni bir veritabanı oluşturuluyor (örneğin "Ahmet" adının geçtiği ve olayların Mısır'da geçtiği bir romandan bu adın Mısır'a özgü olduğu bilgisi).
- **Tedarik zinciri:** firmaların kullandığı ham maddeden ürünleri çıkarmak; örneğin pamuk kullanan bir firma büyük olasılıkla kıyafet yapar.

### 6.6 Kalıplarla ilişki çıkarma, dil modeli ve veri artırımı

Bir grup, belli kalıplar belirleyip bunları düzenli ifadelerle (regex) metinden çıkarmayı ve belli bir frekansın üstündeki bilgileri doğru kabul etmeyi önerdi. Kavramlar ve aralarında ilişkiler olacak, ama ilişkiler daha kapsamlı olacaktı: "X Y'de bulunur", "X Y'yi kurdu", "X Y'nin yazarıdır" gibi. Kullanım olarak iki fikir verdiler:

- Dil modelinin hayat bilgisini artırmak için modele kavramları verip aradaki ilişkiyi tahmin ettirmek; örneğin "Bill Gates" ve "Microsoft" verilince "kurdu" ilişkisini tahmin etmesi.
- **Veri artırımı:** cümlede geçen bir kavramın yerine ilişkiyi kullanarak başka bir ifade yazmak; örneğin "Microsoft" yerine "Bill Gates tarafından kurulan Microsoft" ya da "Bill Gates tarafından kurulan şirket".

### 6.7 Fotoğraflarla bilgi toplama

Son grup şunu gözlemledi: insanlara "bildiklerini söyle" denildiğinde akıllarına birçok şey gelmeyebilir. Bunun yerine farklı yerlerden alınmış görsellerden bir veri kümesi oluşturulup insanlara gösterilir ve "bu fotoğrafta ne görüyorsun?" diye sorulur. Örneğin iki çocuğun yan yana durduğu bir fotoğrafa bakıp "çocuğun tokası kırmızıdır" denildiğinde "çocuklar saçlarına toka takar", "tokalar kırmızı olabilir" gibi bilgiler çıkarılabilir. Bu bilgileri bir insanın kendiliğinden söylemesi beklenmez, ama fotoğrafa bakınca aklına gelebilir. Fotoğraflar yalnız bilgiyi tetiklemek için kullanılır, sonra kullanılmaz.

## 7. NELL: Never-Ending Language Learning

### 7.1 NELL'in çalışma biçimi

OpenMind'dan sonraki büyük girişimlerden biri NELL'dir (ekrandan, 01:25:45). Slayttaki tanım:

- 2010 yılında çalışmaya başlayan, web sayfaları üzerinde iteratif olarak çalışan, yarı otomatik, sürekli yeni ilişkiler öğrenen bir sistemdir.
- Sistem morfolojik çözümleme şablonları, HTML kodu şablonları ve metin şablonları kullanarak bilgi toplar.
- Sisteme başlangıçta her ilişki türü için doğruluğu bilinen kavram ikilileri verilir. Sistem buradan çeşitli şablonları öğrenir ve bu şablonlardan yeni kavram ikilileri bulur. Bu yeni ikililerden yeni şablonlar çıkarır ve bu çevrim sürer.

Döngü adım adım şöyledir:

```text
1. Her ilişki türü için doğru bilinen kavram ikilileri (seed) verilir.
2. Bu ikililerden ilişkiyi belirlemeye yarayan şablonlar üretilir.
3. Şablonlar web sayfalarında aranır, yeni kavram ikilileri bulunur.
4. Veritabanı güncellenir.
5. Yeni veritabanıyla yeni şablonlar üretilir; 3. adıma dönülür.
```

"İteratif" sözünün anlamı budur: sistem aynı web sayfasından birinci geçişte, üçüncü ya da beşinci geçişte farklı bilgiler çıkarabilir, çünkü bazı şablonlar ilk geçişte elinde yoktu. Şablon veritabanı genişledikçe aynı sayfadan çok daha farklı şeyler elde edilebilir.

> **Ek bilgi (derste anlatılmadı):** NELL, Carnegie Mellon Üniversitesi'nin "Read the Web" projesidir. Slayttaki adres (http://rtw.ml.cmu.edu/rtw/) bu projeye aittir.

### 7.2 Doğruluğun düşmesi ve kısıtlar

Tasarımcılar mekanizmayı çalıştırınca üretilen ilişkilerin doğruluğunun keskin biçimde düştüğünü görmüşler. Bunu düzeltmek için **kısıtlar** tanımlamışlar. Örneğin elinizde "bu nerede yapılır" ilişkisi varsa, ilk kavramın bir eylem, ikincisinin bir mekân olması gerekir. Bulunan ilişki ancak bu kısıta uyuyorsa veritabanına eklenmiş. Tabii bunun için bir şeyin eylem mi mekân mı olduğunu belirleyen kuralları da tanımlamak gerekmiştir. Ayrıca kısıtlara uyan ve uymayan kavram ikililerinin sayıları kullanılarak şablonlar için güvenilirlik hesaplanmıştır. Böylece veri kümesi büyümeye devam ederken başarının keskin biçimde düşmesi engellenmiştir.

### 7.3 Neden "yarı otomatik"?

Buraya kadar anlatılan süreçte temel olarak insan müdahalesi yoktur. Ama veritabanının başındaki kişinin her gün yaklaşık yarım saat yeni üretilen şablonları gözden geçirmesi gerekiyormuş. Bu yapılmazsa sistem hiç olmadık yerlere sapabiliyormuş, çünkü şablonları sistem kendisi buluyor ve bunlar her zaman doğru değil. Hoca, şablonlar üzerindeki bu insan müdahalesinin sistemi "diri" tuttuğunu söyledi.

### 7.4 NELL arayüzü

Hoca NELL'in web sayfasından ekran görüntüleri gösterdi. "Recently-Learned Facts" tablosunda her bilgi için öğrenildiği iterasyon, tarih ve güven değeri vardır (ekrandan, 01:29:30). Örneğin "zerah_fiske_road is a street" bilgisi 526. iterasyonda, 08-mar-2012 tarihinde, 99,3 güvenle öğrenilmiştir. Kullanıcılar her bilgi için doğru ya da yanlış geri bildirimi verebilir.

> **Ders sonrası not:** Hoca altyazıda bu bilginin "5126. iterasyonda" öğrenildiğini söyledi; ekrandaki tabloda iterasyon 526'dır (ekrandan, 01:29:30). Fark Whisper'dan da kaynaklanmış olabilir.

Bilgi tabanı tarayıcısında kategoriler ağaç yapısındadır (ekrandan, 01:30:00). Örneğin "movie" kategorisinde "aliens" ve "an_american_in_paris" sisteme başta verilmiş (seed) örneklerdir; "beowulf" ise sistemin kendisinin 161. iterasyonda bulduğu bir filmdir. Yani tabloda hem verilenler hem de verilenlerden sistemin kendi bulduğu bilgiler vardır.

Hoca 2010'dan 2012-2013 civarına kadar sistemin yaklaşık 50 milyon aday ilişki topladığını ve bunların 1,8 milyonunun güvenilirliğinin yüksek olduğunu söyledi. <!-- BELİRSİZ: 01:30:48'deki "50 milyon" ve "1.8 milyon" sayıları ekranda görülmedi. 01:29:30'daki 2012 tarihli ekran görüntüsünde "over 15 million candidate beliefs" ve "high confidence in 1,027,444" yazıyor; hoca daha sonraki bir dönemin sayılarını söylemiş olabilir. -->

### 7.5 Güvenilirlik nasıl ölçülür?

Burada 1,8 milyon dediğimiz şeyler ilişkilerdir, yani "şununla şunun arasında şu tür bir ilişki var" biçimindeki üçlülerdir. Güvenilirlik iki düzeyde hesaplanır:

- **Şablon güvenilirliği:** şablonun ürettiği ikililerin doğruluk oranı. Bir şablondan üretilen ikililer ne kadar doğruysa şablon o kadar güvenilirdir.
- **İlişki güvenilirliği:** (1) üretildiği şablonun güvenilirliğine bağlıdır; hoca şablon ve ilişki güvenilirliğinin birbirine bağlı olmasını tavuk-yumurta hikâyesine benzetti. (2) Kaç farklı şablondan üretildiğine bağlıdır: aynı ilişki birden fazla şablonla üretildiyse doğru olma olasılığı daha yüksektir. (3) Kullanıcı geri beslemelerine bağlıdır: kullanıcıların ilişkilere verdiği puanlar da hesaba katılır.

### 7.6 Metin şablonu örneği

Hoca "şablon" sözünün ne anlama geldiğini bir örnekle gösterdi. Bu düzenli ifade değil, metin şablonudur (ekrandan, 01:32:45):

```text
bir tür X olan Y          -> isa(X,Y)
bir diğer X çeşidi olan Y -> isa(X,Y)
```

Metinde böyle bir kalıp geçiyorsa, X ve Y'nin yerine gelen kelimeler alınır ve veritabanına bir `isa(X,Y)` ilişkisi eklenir.

## 8. Türkçe Hayat Bilgisi Veritabanı ve CSoyun

### 8.1 Türkçe veritabanının oluşturulması

Hoca, kendi grubunun Türkçe için yaptığı bir çalışmayı anlattı. Türkçe için böyle bir veritabanı kurmak istediklerinde ilk soru hangi kaynağın kullanılacağıydı. Cyc o zaman erişime açık değildi, OpenMind açıktı. Bu yüzden mevcut kaynakları tercüme edip kullanmaya ve frekans tabanlı bilgi çıkarımı yapmaya karar verdiler. Kullanılan kaynaklar:

- ConceptNet ve orijinal WordNet'in Google Translate ile çevirisi.
- Küçük de olsa bir Türkçe WordNet.
- HTML sayfalarında bilgi çıkarımı (information extraction): NELL'deki türden şablonlarla. Zemberek ile morfolojik analiz yapılarak yaklaşık 400 bin web sayfası taranmış (crawl edilmiş), HTML kodları üzerinde şablonlar tanımlanıp veriler elde edilmiştir.

Hoca, o zamanki otomatik çevirinin bugünkünden de sorunlu olduğunu, ama elde çok fazla veri olduğu için en az maliyetli yolun bu olduğunu söyledi.

### 8.2 Veritabanından örnekler

Slayttaki tablo, farklı ilişki türleri için veritabanındaki kavram ikililerini gösterir (ekrandan, 01:35:00):

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

Hoca bazı satırları sesli okudu: denemek için para lazım, seyahat etmek için enerji lazım, öğrenmek için okumak lazım, yaşamak için yiyecek lazım; asker savaş için, çatal yemek için kullanılır; kuş uçabilir, bıçak kesebilir. Veritabanında her ilişki türü için kaç ilişki olduğu ve bunların hangi kaynaktan geldiği de tutuluyordu.

### 8.3 Sorunlar ve geri besleme ihtiyacı

Bu yaklaşımın sorunları:

- **Otomatik çeviri hataları:** yanlış çeviriler ya da çevirinin yapılamaması. Elle çeviri ise çok maliyetlidir.
- **Bilgi kalitesi:** oluşturulan veritabanının içinde elbette bir "çöp" kısım vardır.

Sistemi iyileştirmek için insanlardan geri besleme almak gerekir. Ama "bu ilişki doğru mu, değil mi?" diye doğrudan sormak çok çekici değildir. Bu yüzden geri besleme bir oyun biçimine getirildi: **CSoyun**.

### 8.4 CSoyun oyunları

CSoyun'da oyun oynadıkça puan kazanılır, puan tablolarında yukarı çıkılır. Oyunun amacı bilgi sayısını ve kalitesini artırmaktır. İnsanlar yeni ilişki ve kavram girebilir ya da var olan ilişkilere geri besleme verebilir. Beş oyun vardır (ekrandan, 01:36:25):

- **Bildiklerim:** kullanıcı bir ilişki türü seçer, sistemin o ilişki türü için bildikleri karşısına çıkar. Kullanıcı her ilişkiye 0 ile 5 arasında puan verir. Puanın yalnız 0 ya da 1 olmamasının nedeni, bazı ilişki türlerinde dünyanın ikili olmamasıdır.
- **Araştır:** kullanıcı bir kelime ve bir ilişki seçer; bu ikisi için sistemdeki üçüncü kavramlar karşısına gelir ve bunlara puan verir.
- **Tahminlerim:** sistem elindeki ilişkileri kullanarak veritabanında olmayan yeni ilişkiler üretir ve kullanıcıya sorar. Ekrandaki örnekte "hayal — Bu neyin ilk adımıdır? — yaşamak" ilişkisi için kullanıcıdan Doğru, Yanlış ya da Ben Bilmem demesi istenir.
- **Bana Öğret:** kullanıcıya bir kavram ve ilişki türü verilir, kullanıcı veritabanına yeni kavram ekler.
- **Birlikte Eğitim:** iki kişi eşleştirilip aynı oyunu oynar; ikisinin aynı şeyi söylediği cevaplar daha yüksek puan alır.

Birlikte Eğitim'in mantığı şudur: bu oyun hileye açıktır, insanların doğru yapıp yapmadığını bilemezsiniz. Çoğu insanın bir ilişki için verdiği ortalama cevaba güvenmek makuldür, ama insanlar rastgele cevap verebilir ("sallayabilir"). Bunu engellemek için birçok mekanizma geliştirilebilir. Buradaki mekanizma, iki kişinin rastgele aynı cevabı verme olasılığının düşük olmasına dayanır: birbirinden bağımsız iki kişinin aynı cevabı, farklı cevaplara göre çok daha değerlidir.

> **Hocanın vurgusu:** Hocaya göre CSoyun'un en dikkat çekici kısmı Tahminlerim oyunudur: sistem veritabanında olmayan yeni ilişkiler üretip bunlar için geri besleme alabilmektedir. Bu üretim monotonik olmayan bir çıkarımdır.

## 9. Monotonik ve Monotonik Olmayan Çıkarım

Slaytta Tahminlerim oyunu şöyle tanımlanıyor (ekrandan, 01:41:35): "Bu oyun CSoyun'u benzer sistemlerden ayıran en önemli özelliğidir. Sistemde, CSdb'de yer alan relation'lar kullanılarak non-monotonic reasoning yapılarak CSdb'de yer almayan hipotezler üretilir ve hipotezler tablosuna kaydedilir. Hipotezlerin 4 farklı üretilme çeşidi tabloda verilmiştir. Hipotezler onaylandıklarında relations tablosuna kaydedilmektedirler." Slayttaki iki soru şunlardır: monotonik çıkarım nedir, monotonik olmayan çıkarım nedir?

### 9.1 Monotonik çıkarım

Elinizde iki ilişki var ve bunlardan yeni bir ilişki üretiyorsunuz. İlk iki ilişki doğruysa üçüncüsü **kesinlikle** doğrudur. Örnek: "Bütün insanlar ölümlüdür. Sokrat insandır." Bu ikisinin doğru olduğunu kabul ederseniz kesinlikle "Sokrat ölümlüdür" diyebilirsiniz. Bu, kesin bir çıkarımdır (tümdengelim).

### 9.2 Monotonik olmayan çıkarım

İlişkiler doğruyken üretilen ilişki doğru da olabilir, yanlış da. Hoca bunu kabaca tümevarım gibi yaklaşımlara benzetti. Monotonik olmayan çıkarımın sonucu kesin bilgi değil, bir **tahmin**dir.

### 9.3 Monotonik çıkarım bu veritabanında neden anlamsızdır?

Hocaya göre bu tür bir veri kümesi üzerinde monotonik çıkarım yapmanın çok anlamı yoktur, çünkü monotonik çıkarım yeni bilgi üretmez. Var olan bilgiler doğruysa sonuç zaten onların doğal sonucudur; bunu üretip veritabanına eklemek veritabanını şişirir.

Hoca bunu uzman sistemlerden bir örnekle anlattı. Bir kaplumbağa görüyorsunuz. Sol ön ayağını, o ayaktaki bir hücreyi düşünün. "Bu hücrede endoplazmik retikulum var mıdır?" diye sorulsa hepiniz "vardır" dersiniz. Çünkü o bir hayvandır, bu bir hayvan hücresidir ve bütün hayvan hücrelerinde endoplazmik retikulum vardır. Bugüne kadar böyle bir soruyla hiç karşılaşmamış olsanız da %100'e yakın bir güvenle cevap verirsiniz. Bunu yapabilmenizin nedeni monotonik (tümdengelimli) bir çıkarım yapmanızdır ve bu bilgiyi gerektiğinde zaten çıkarabilirsiniz. Böyle bir bilgiyi veritabanına eklemek ancak çok sık kullanılıyorsa anlamlıdır. Gerektiğinde çıkarılabilecekse veritabanını şişirmeye gerek yoktur.

> **Hocanın vurgusu:** Monotonik çıkarım yeni bilgi üretmez; istediğiniz zaman erişebileceğiniz bir bilgiyle veritabanını şişirmenin anlamı yoktur. Değerli olan, doğrulanınca gerçekten yeni bilgi sağlayan monotonik olmayan çıkarımdır.

### 9.4 CSoyun'daki dört çıkarım türü

Slayttaki tablo, hipotezlerin dört üretilme biçimini örnekleriyle verir (ekrandan, 01:41:35):

```text
Çıkarım türü                              Örnek çıkarım
(X-R1-Y) and (Y-R2-Z) -> (X-R3-Z)         (martı - altkavramıdır - kuş) ve
                                          (martı - bu ne yapabilir - uçmak)
                                          -> (kuş - bu ne yapabilir - uçmak)

(X-R1-Y) -> (X-R2-Y)                      (sinemaya gitmek - içerdiği olaylar nelerdir - mısır yemek)
                                          -> (sinemaya gitmek - bunun için ilk önce ne yaparsın - mısır yemek)

(X-R1-T) and (Z-R1-T) and (X-R2-Y)        (kedi - altkavramıdır - memeli) ve
  -> (Z-R2-Y)                             (köpek - altkavramıdır - memeli) ve
                                          (kedi - sahiptir - kürk)
                                          -> (köpek - sahiptir - kürk)

(X-R1-Y) and (X-R2-Z) -> (Z-R3-Y)         (bıçak - nerede bulunur - mutfak),
                                          (bıçak - ne için kullanılır - kesmek)
                                          -> (kesmek - nerede yapılır - mutfak)
```

Hoca örnekleri şöyle açıkladı:

- **Martı örneği:** martı bir tür kuştur ve martı uçabilir; o zaman "kuşlar uçabilir" tahmini üretilir. Bu aslında kesin doğru bir çıkarım değildir. Burada alt kavramın (martı) yapabildiği bir şey üst kavrama (kuş) aktarılıyor. Tersi, yani "kuşlar uçabilir, martı bir kuştur, o hâlde martı uçabilir" monotonik olurdu. Ama alttan üste aktarım kesin değildir; bir tahmindir. Bu tahmin onaylanırsa veritabanına gerçekten yeni bir bilgi eklenmiş olur.
- **Kedi-köpek örneği:** kedi ve köpek aynı üst kavramın (memeli) alt kavramlarıdır; hoca bunlara "kardeş" kavramlar dedi. Kardeşlerden birinin bir özelliği diğerinde de vardır diye tahmin edilir: kedinin kürkü var, o hâlde köpeğin de kürkü var.
- **Bıçak örneği:** bıçak mutfakta bulunur ve kesmek için kullanılır; o hâlde kesme eylemi mutfakta yapılır.

Tahminlerim oyunu kullanıcıya bu tahminlerin yalnız son kısmını, yani sonuç ilişkiyi gösterir; örneğin "kuşlar uçabilir mi?". İlişkinin hangi öncüllerden türetildiği gösterilmez, ama veritabanında tutulur. Kullanıcı "evet" derse ilişki veritabanına eklenir.

## 10. CSoyun İstatistikleri

Hoca, CSoyun'un yaklaşık iki yıllık bir deney olduğunu ve bu sürede iki rapor çıkarıldığını söyledi (ekrandan, 01:45:10). Sistem Ocak 2010'da açılmıştır.

| | 1. rapor | 2. rapor |
|---|---|---|
| Rapor zamanı | 18 Nisan 2010 | 23 Şubat 2012 |
| Oy sayısı | 34 bin | 155 bin |
| Kullanıcı sayısı | 65 | 182 |
| İlişki türü sayısı | 40 | 45 |
| İlişki sayısı | 1,09 milyon | 1,2 milyon |
| Kavram sayısı | 475 bin | 700 bin |

Slayttaki açıklamaya göre bir ilişkinin doğruluk oyu en düşük 0, en yüksek 5'tir. Verilen oyların ortalaması 5 üzerinden yaklaşık 3,1'dir. Kullanıcıların oyladığı tekil ilişki sayısı yaklaşık 99 bindir. Buna göre oyunun kullanıma açıldığı 2 yıl boyunca veritabanındaki ilişkilerin %8,3'ü oylanmıştır.

Hesap (ara adım eklendi):

$$\frac{99\,000}{1\,200\,000} \approx 0{,}0825 \approx \%8{,}3$$

> **Ders sonrası not:** Hoca ilişki sayısının "1 milyondan 1,2 milyona" çıktığını ve oranın "%8" olduğunu söyledi; slayttaki değerler 1,09 milyon ve %8,3'tür (ekrandan, 01:45:10).

Hoca buradan şu sonucu çıkardı: tüm sistemin oylanması için gereken süre çok uzundur. Bu tür bir yöntemle ilerlemek kolay değildir; başka mekanizmalar da kurmak gerekir. Çok kişiye oynatılabilirse durum değişir, ama insanların oynaması için motivasyon sağlamak gerekir ve bu oyun onlar için çok çekici değildir. Sunumda her ilişki türünün ortalama puanı, hangi tür ilişkilerin daha çok puan aldığı gibi ayrıntılar da vardı; hoca bunlara ayrıntılı girmedi.

## 11. Hayat Bilgisi Veritabanlarının Kalitesi

### 11.1 Doğruluk ve kapsayıcılık

Hayat bilgisi veritabanının kalitesi için birkaç ölçü vardır:

- **Doğruluk:** içindeki bilgiler doğru mu?
- **Kapsayıcılık:** gereken bilgilerin ne kadarı içinde var?

Hoca bu ikisinin birbiriyle biraz çeliştiğini söyledi. İçeriye çok fazla şey doldurursanız kapsayıcılık artar ama doğruluk düşer. Yalnız çok doğru şeyler koymaya karar verirseniz az şey koyabilirsiniz ve bu kez kapsayıcılık düşer.

### 11.2 Nasıl ölçülür?

- **Doğruluk:** sistemden rastgele, örneğin yüz ilişki seçilir. Siz ya da ekibinizden birileri bunları oylar ve sistemin yüzde kaçının doğru olduğu bulunur. Yani doğruluk bir örneklem üzerinden ölçülür.
- **Kapsayıcılık:** bu ilişki türleri için gereken bilgi sayısının milyonlarca olduğu varsayılır. Hocaya göre ilişki sayısı belki o kadar sorunlu değildir, ama kavram sayısı sorunludur. İki ölçüm önerdi:
  - **Kavram sayısının yeterliliği:** büyük bir metin derlemi alınır; derlemdeki kavramların yüzde kaçının veritabanında bulunduğuna bakılır.
  - **İlişki sayısının yeterliliği:** insanlara rastgele bir kavram ya da rastgele bir resim gösterilir (hoca burada fotoğraf fikrini öneren gruba atıf yaptı). Kişinin bir dakika gibi kısa bir sürede bu kavram hakkında ürettiği ilişkilerin yüzde kaçının veritabanında olduğuna bakılır. Örneğin insanlara rastgele 50 kavram gösterilir, her biri için yazdıkları ilişkilerin veritabanındaki oranı ölçülür. Bunun için tek kişi yetmez, birden çok kişiyle ölçmek gerekir.

Bu ölçümler zaman içinde tekrarlanarak sistemin kapsayıcılık ve doğruluk performansının nasıl değiştiği izlenebilir.

### 11.3 Uygulama alanları

Hoca son olarak hayat bilgisi veritabanlarının birçok uygulama alanı olabileceğini, grup etkinliğinde de bunlardan bazılarının konuşulduğunu hatırlattı. Mevcut problemlerin çözümlerine bu veritabanları çeşitli yollarla entegre edilebilir ve her birinde fayda sağlayabilirler.

## Örnek Sorular

**Soru 1** (ekrandan, 00:05:40): "Ali okula gittiğinde öğlen yemeğini kantinde yer. Ali eve gittiğinde öğlen yemeğini mutfakta yer. Ali sınıfta kitap okudu." bilgileri verildiğinde "Ali öğlen yemeğini nerede yedi?" sorusunu cevaplamak için metinde olmayan hangi bilgiler gerekir?

> **Çözüm (derste verilen):** Slayta göre gereken bilgiler: birisi bir yerde bulunmuşsa oraya gitmiştir; birisi bir yere gitmişse o yeri içine alan yere de gitmiştir; sınıf okulun içindedir; oda evin içindedir. Hoca bu bilgilerin hayat bilgisi olduğunu ve bu dersin konusunu oluşturduğunu söyledi.

**Soru 2** (ekrandan, 00:12:30): "Yemeğim 5 dakikada geldi. Çok teşekkürler XXX." ve "Yemeğim 55 dakikada geldi. Çok teşekkürler XXX." cümlelerinden hangisi olumlu, hangisi olumsuzdur? Bunu söyleyebilmek için ne bilmek gerekir?

> **Çözüm (derste verilen):** Birincisi olumlu, ikincisi imalı ve olumsuzdur. Ayrım için yemek teslimatının ortalama ne kadar sürdüğünü bilmek gerekir; iki cümle arasında şekilsel olarak yalnız bir karakter farkı vardır. Bağlam da önemlidir: çok uzak bir yerde yaşayan biri için 55 dakika teşekküre değer olabilir.

**Soru 3** (ekrandan, 00:12:30): "XXX sayesinde 1 saatlik filmi 3 saatte izledim." ve "XXX sayesinde 1 saatte 10 film indirdim." cümlelerinin duygu yönü nedir?

> **Çözüm (derste verilen):** Birincisi olumsuz (bağlantı kesilmiş, donmuş, bant genişliği düşük), ikincisi olumludur (yüksek hız). Bunu anlamak için film izlemenin ve indirmenin normalde ne kadar sürdüğünü bilmek gerekir.

**Soru 4** (derste sözlü, 00:26:16): Hayat bilgisi toplamak, toplanmış hayat bilgisini iyileştirmek ya da onu kullanan uygulamalar için hangi fikirler geliştirilebilir?

> **Çözüm (derste verilen):** Gruplardan gelen fikirler (Bölüm 6): sosyal medya tepkilerinden ilişki çıkarıp oylatmak; hava durumu-duygu-eylem ilişkisini olasılıklı olarak çıkarmak; kullanıcı onayıyla (upvote/downvote) veritabanı kurmak; tutarsızlık/yalan tespiti ve yararlı/zararlı eylem sınıflandırması; reklam önerisi; romanlardan kişi ve yer bilgisi çıkarmak; kalıplarla ilişki çıkarıp dil modeline ilişki tahmini ve veri artırımı için kullanmak; insanlara fotoğraf gösterip yorumlarından bilgi toplamak.

**Soru 5** (ekrandan, 01:41:35): Monotonik çıkarım nedir? Monotonik olmayan çıkarım nedir?

> **Çözüm (derste verilen):** Monotonik çıkarımda öncüller doğruysa sonuç kesinlikle doğrudur ("Bütün insanlar ölümlüdür, Sokrat insandır → Sokrat ölümlüdür"). Monotonik olmayan çıkarımda öncüller doğruyken sonuç doğru da olabilir, yanlış da; sonuç bir tahmindir ("martı bir tür kuştur, martı uçabilir → kuşlar uçabilir").

**Soru 6** (derste sözlü, 01:39:36): Bir kaplumbağanın sol ön ayağındaki bir hücrede endoplazmik retikulum var mıdır? Bu soruyu hiç düşünmemiş olsak da nasıl cevaplarız ve bu, hayat bilgisi veritabanı için ne anlama gelir?

> **Çözüm (derste verilen):** "Vardır" deriz, çünkü kaplumbağa bir hayvandır, hücresi bir hayvan hücresidir ve bütün hayvan hücrelerinde endoplazmik retikulum vardır. Bu monotonik (tümdengelimli) bir çıkarımdır. Bu bilgi gerektiğinde çıkarılabildiği için veritabanına eklemek gereksizdir; monotonik çıkarım yeni bilgi üretmez, yalnız veritabanını şişirir.

**Soru 7** (ekrandan, 01:41:35): CSoyun tablosundaki (X-R1-Y) → (X-R2-Y) türünde, "(sinemaya gitmek - içerdiği olaylar nelerdir - mısır yemek)" ilişkisinden hangi tahmin üretilir? Bu tahmin neden kesin değildir?

> **Çözüm (derste verilmedi):** Slayttaki örneğe göre "(sinemaya gitmek - bunun için ilk önce ne yaparsın - mısır yemek)" tahmini üretilir. Aynı kavram ikilisi arasındaki bir ilişki türü başka bir ilişki türüne aktarılmaktadır. Bir olayın alt olayı olmak, onun ön koşulu (ilk önce yapılan şey) olmayı gerektirmez; bu yüzden sonuç kesin değil, monotonik olmayan bir tahmindir ve kullanıcı onayı gerekir. Hoca bu satırı derste ayrıca anlatmadı.

**Soru 8** (ekrandan, 01:45:10): CSoyun'da 2 yılda yaklaşık 99 bin tekil ilişki oylanmıştır. Veritabanında 1,2 milyon ilişki varsa ilişkilerin yüzde kaçı oylanmıştır?

> **Çözüm (derste verilen):** $99\,000 / 1\,200\,000 \approx 0{,}0825$, yani yaklaşık %8,3 (slayttaki değer). Hoca buradan, tüm veritabanını insan oylamasıyla doğrulamanın çok uzun süreceği sonucunu çıkardı.

**Soru 9** (derste sözlü, 01:46:42): Bir hayat bilgisi veritabanının kalitesi nasıl ölçülür?

> **Çözüm (derste verilen):** İki ölçü vardır ve birbiriyle çelişir: doğruluk ve kapsayıcılık. Doğruluk, rastgele seçilen bir örneklemin (örneğin 100 ilişki) insanlara oylatılmasıyla ölçülür. Kapsayıcılık için büyük bir derlemdeki kavramların yüzde kaçının veritabanında bulunduğuna ve insanların rastgele bir kavram ya da resim için kısa sürede ürettiği ilişkilerin yüzde kaçının veritabanında bulunduğuna bakılır.

## Dersin Toparlaması

Bu derste, geçen dersteki Prolog örneğinde soruyu cevaplamayı sağlayan ama metinde yazmayan bilgiye, yani hayat bilgisine odaklanıldı. Hayat bilgisi herkesin bildiğini varsaydığımız bilgidir; duygudurum analizi gibi görevlerde bile şekilsel olarak neredeyse aynı iki cümlenin anlamını ayırt etmek için gereklidir. Hayat bilgisi veritabanları iki temel yolla kurulur: az sayıda uzmanın formal dille özenle girdiği bilgiler (Cyc) ve çok sayıda gönüllünün serbest biçimde girdiği bilgiler (OpenMind/ConceptNet). NELL ise web sayfalarından şablonlarla iteratif ve yarı otomatik olarak bilgi öğrenir; doğruluğu korumak için kısıtlar, şablon güvenilirliği ve günlük insan denetimi kullanır. Hocanın grubunun Türkçe çalışmasında çeviri ve şablonlarla oluşturulan veritabanının kalitesini artırmak için CSoyun oyunu geliştirildi. Bu oyunun Tahminlerim kısmı, monotonik olmayan çıkarımla yeni ilişki tahminleri üretip kullanıcı onayıyla veritabanına ekler; monotonik çıkarım ise yeni bilgi üretmediği için veritabanına eklenmeye değmez. Son olarak veritabanı kalitesinin birbiriyle çelişen iki ölçüsü, doğruluk ve kapsayıcılık, ve bunların nasıl ölçülebileceği ele alındı.

Hoca, gelecek hafta da hayat bilgisi veritabanlarıyla devam edileceğini, şablonların nasıl çıkarıldığının konuşulacağını söyledi. Öğrencilerden sinirsel dil modellerinin hayat bilgisini harici bir kaynak olmadan içerip içermediğine dair çalışmaları incelemelerini istedi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
