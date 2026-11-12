# Ders 2 Çalışma Özeti

## Genel Konular

- Geçen dersten bağlantı: Prolog çıkarım örneği ve "bilinmesi gerekenler"
  - Geçen derste "Ali öğlen yemeğini nerede yedi?" sorusu kural tabanlı bir yapıyla (Prolog) cevaplanmıştı (ekrandan, 00:05:40).
  - Bu cevap için paragrafta yazmayan bilgiler gerekiyordu: "Birisi bir yerde bulunmuşsa oraya gitmiştir", "Birisi bir yere gitmişse o yeri içine alan yere de gitmiştir", "Sınıf okulun içindedir", "Oda evin içindedir".
  - Kodda cümleler `vardir(yüklem, özne, belirtilinesne, dolaylıtümleç, cümleno)` yapısında tutulur. `vardir` gerçek cümleleri (bilgileri), `vardir2` türetilen cümleleri ifade eder (ekrandan, 00:07:45).
  - Hoca, bu yapının yalnız basit cümlelerle sınırlı olmadığını söyledi: özne ya da nesne başka bir alt cümle olabilir, yapı iç içe kurulabilir.
  - Bu dersin konusu, işte bu "bilinmesi gerekenler" kısmıdır: hayat bilgisi.
- Hayat bilgisi (commonsense) nedir?
  - Herkesin bildiğini varsaydığımız bilgilerdir. Slayttaki örnekler: insanlar her gün yemek yer, insanlar geceleri uyur, balıklar denizde yaşar, elma yuvarlaktır, kediler miyavlar (ekrandan, 00:10:00).
  - Bu bilgilerin istisnaları olabilir, ama genel olarak doğrudurlar.
  - Konuşurken karşı tarafın bazı şeyleri bildiğini varsayarız ve bilmediği konuları bu ortak bilgi üzerinden anlatırız.
- Hayat bilgisi veritabanına neden ihtiyaç var?
  - Bilgisayarlar, söylediklerimizden söylemediklerimizi tahmin edemez. Paragrafta soruyu cevaplayacak bilgi olmasa da insan cevap verebilir; makine veremez.
  - Bu bilgi verilebilirse, örneğin lokantada yemek yemekle ilgili bir cümleden "Ali para ödemiştir" bilgisi çıkarılabilir. <!-- BELİRSİZ: 00:11:09'da öncül cümle bozuk çıkmış. -->
  - İnsan bu bilgileri yaşayarak edinir. Soru, bu bilgilerin bir biçime sokulup makineye verilip verilemeyeceğidir.
- Duygudurum analizinde hayat bilgisi (ekrandan, 00:12:30)
  - "Yemeğim 5 dakikada geldi. Çok teşekkürler XXX." olumludur; "Yemeğim 55 dakikada geldi. Çok teşekkürler XXX." imalıdır, olumsuzdur.
  - İki cümle arasında yalnız bir karakter farkı vardır. Ayrımı yapmak için yemek teslimatının normalde ne kadar sürdüğünü bilmek gerekir.
  - "XXX sayesinde 1 saatlik filmi 3 saatte izledim." olumsuz, "XXX sayesinde 1 saatte 10 film indirdim." olumludur. Bunun için film izlemenin ve indirmenin normalde ne kadar sürdüğünü bilmek gerekir.
  - Hoca, bağlamın da önemli olduğunu ekledi: dağın başında yaşayan biri için 55 dakika teşekküre değer olabilir; 20 yıl önceki altyapıyla bir saatlik filmi üç saatte izlemek kötü sayılmayabilir.
- Hayat bilgisi veritabanları nasıl oluşturulur? İki temel yaklaşım (ekrandan, 00:20:00)
  - Az sayıda bilgi mühendisi bilgileri özenle, formal bir dille girer: Cyc, 20 yılda 1,5 milyon kaliteli bilgi.
  - Çok sayıda web kullanıcısı bilgileri serbest biçimde (cümle olarak) girer: OpenMind, 8000 kişi, 3 yılda 1 milyon bilgi.
  - Bilgi sayısı açısından büyük fark yoktur. İkinci yaklaşım daha hızlıdır, birincisi daha güvenilirdir; gönüllülerden gelen bilgide tutarsızlık daha fazladır.
  - Birinci yaklaşım internet yokken başlamıştır; ikincisi interneti kullanır.
- Popüler çalışmalar (ekrandan, 00:20:30)
  - Cyc (1984, anlamsal ağ, uzman kişiler, elle).
  - WordNet (1985, anlamsal ağ, uzman kişiler, elle).
  - OpenMind / ConceptNet (2002, gönüllü kullanıcılar, otomatik).
  - NELL (2010, hayat bilgisi, yarı otomatik).
  - Hoca, sinirsel dil modellerinin bu bilgiyi zaten öğrendiğini savunan ve dil modelini bilgi tabanıyla birlikte kullanan yaklaşımların da bulunduğunu söyledi.
- ConceptNet'in oluşturulması (ekrandan, 00:22:20)
  - Çıkarım aşaması: gönüllülerin serbest formda girdiği cümlelerden (OMCS corpus) bilgi üçlüleri çıkarılır. Tüm bilgilerin %90'ı buradan gelir. Buradaki "çıkarım", cümleden bilgi çıkarma (information extraction) anlamındadır.
  - Zenginleştirme aşaması: mevcut üçlülerden mantıksal kurallarla yeni üçlüler üretilir. Tüm bilgilerin %10'u buradan gelir.
- ConceptNet'in yapısı (ekrandan, 00:24:10)
  - 1,6 milyon (kavram-ilişki-kavram) üçlüsü, 20 ilişki türü.
  - İlişki türleri gruplar hâlinde: nesneler (IsA, PartOf, PropertyOf, MadeOf, DefinedAs), mekânsal (LocationOf), olaylar (SubeventOf, PrerequisiteEventOf, FirstSubeventOf, LastSubeventOf), nedensel (EffectOf, DesirousEffectOf), duygusal (DesireOf, MotivationOf), işlevsel (UsedFor, CapableOfReceivingAction), ajanlar (CapableOf).
  - Grafik gösterimde kavramlar düğüm, ilişkiler etiketli oklardır (ekrandan, 00:24:55). Örnek: wake up in morning → PrerequisiteOf → eat breakfast → EffectOf → full stomach.
  - Uygulamalar: kullanıcının yazdığı e-postaya uygun fotoğraf önermek, hikâye üretmek (MakeBelieve programı).
- NELL (Never-Ending Language Learning) (ekrandan, 01:25:45)
  - 2010'da çalışmaya başlamış, web sayfaları üzerinde iteratif çalışan, yarı otomatik, sürekli yeni ilişki öğrenen bir sistemdir.
  - Morfolojik çözümleme şablonları, HTML kodu şablonları ve metin şablonları kullanır.
  - Döngü: her ilişki türü için doğruluğu bilinen kavram ikilileri (seed) verilir → sistem şablon öğrenir → şablonlarla yeni ikililer bulur → yeni ikililerden yeni şablonlar çıkarır. Aynı sayfadan sonraki geçişlerde yeni bilgiler çıkarılabilir.
  - Sorun: üretilen ilişkilerin doğruluğu hızla düşmüş. Çözüm: kısıtlar (örneğin "nerede yapılır" ilişkisinde ilki eylem, ikincisi mekân olmalı) ve kısıta uyan/uymayan ikili sayılarına göre şablon güvenilirliği.
  - Yarı otomatik olmasının nedeni: bir kişinin her gün yaklaşık yarım saat yeni şablonları gözden geçirmesi gerekiyormuş; aksi hâlde sistem saparmış.
  - İlişki güvenilirliği: üretildiği şablonun güvenilirliği, kaç farklı şablondan üretildiği ve kullanıcı geri beslemeleri.
- Metin şablonu örneği (ekrandan, 01:32:45)
  - "bir tür X olan Y" → isa(X,Y); "bir diğer X çeşidi olan Y" → isa(X,Y).
- Türkçe hayat bilgisi veritabanı ve CSoyun
  - Hocanın grubunun Türkçe çalışması: ConceptNet ve WordNet Google Translate ile çevrildi, küçük Türkçe WordNet eklendi, Zemberek ile morfolojik analiz yapılarak 400 bin web sayfasından şablonlarla bilgi çıkarıldı.
  - Veritabanı örnekleri (ekrandan, 01:35:00): "Bunun için ne gerekir?" denemek-para, öğrenmek-okumak; "Ne için kullanılır?" çatal-yemek; "Bu ne yapabilir?" kuş-uçmak, bıçak-kesmek; "Nerede bulunur?" oda-bina.
  - Sorunlar: otomatik çeviri hataları ve bilgi kalitesi. Kaliteyi artırmak için insan geri beslemesi gerekir; bunu çekici kılmak için CSoyun oyunu yapıldı.
  - CSoyun'un beş oyunu: Bildiklerim, Araştır, Tahminlerim, Bana Öğret, Birlikte Eğitim (ekrandan, 01:36:25). Oyun oynadıkça puan kazanılır.
- Monotonik ve monotonik olmayan çıkarım (ekrandan, 01:41:35)
  - Monotonik: öncüller doğruysa sonuç kesinlikle doğrudur (tümdengelim). Örnek: "Bütün insanlar ölümlüdür, Sokrat insandır → Sokrat ölümlüdür."
  - Monotonik olmayan: öncüller doğruyken sonuç doğru da olabilir, yanlış da. Bu bir tahmindir.
  - CSoyun'daki dört çıkarım türü tablo olarak verildi (bkz. Kısa Tekrar Notları).
- Veritabanı kalitesinin ölçülmesi
  - Doğruluk ve kapsayıcılık birbiriyle çelişir: çok şey koyarsanız kapsayıcılık artar, doğruluk düşer.
  - Doğruluk: rastgele örneklem (örneğin 100 ilişki) insanlara oylatılır.
  - Kapsayıcılık: büyük bir derlemdeki kavramların yüzde kaçının veritabanında olduğu; insanların rastgele bir kavram için kısa sürede ürettiği ilişkilerin yüzde kaçının veritabanında olduğu.

## Hocanın Özellikle Vurguladığı Kısımlar

- Hayat bilgisi yapay zekânın önünde bir duvardır
  - Hikâye anlamadan makine çevirisine ve uzman sistemlere kadar birçok problemde hayat bilgisi eksikliği büyük bir engel olarak karşımıza çıkar. Bu yüzden hayat bilgisi veritabanı çalışmaları 1980'lerin başına kadar uzanır.
- Metinden tek başına karar vermek zordur
  - Duygudurum örneklerinde şekilsel fark çok küçüktür (bir karakter), ama anlam tersine döner. Doğru karar için dünya bilgisi gerekir.
- Monotonik çıkarımla veritabanını şişirmenin anlamı yoktur
  - Monotonik çıkarım yeni bilgi üretmez; sonuç zaten öncüllerin doğal sonucudur ve gerektiğinde çıkarılabilir. Hoca bunu "kaplumbağanın sol ön ayağındaki bir hücrenin endoplazmik retikulumu var mıdır?" örneğiyle anlattı: bu soruyu hiç düşünmemiş olsak da tümdengelimle hemen "vardır" deriz.
  - Asıl değerli olan monotonik olmayan çıkarımdır: tahmin üretir, kullanıcı onaylarsa veritabanına gerçekten yeni bir bilgi eklenir.
- Tahminlerim oyunu CSoyun'un ayırt edici özelliğidir
  - Sistem veritabanında olmayan yeni ilişkiler üretip kullanıcıdan geri besleme alır. Kullanıcıya yalnız sonuç ilişki gösterilir (örneğin "kuşlar uçabilir mi?").
- Gönüllü verisinde güven sorunu
  - Kullanıcılar rastgele cevap verebilir. Birlikte Eğitim oyununda iki kişi eşleştirilir; ikisinin aynı cevabı vermesi daha yüksek puan alır, çünkü iki kişinin rastgele aynı şeyi söyleme olasılığı düşüktür.
- İnsan geri beslemesiyle tüm veritabanını oylatmak çok yavaştır
  - CSoyun'da 2 yılda ilişkilerin yalnız yaklaşık %8,3'ü oylanabildi. İnsanların oynaması için motivasyon gerekir.

## Kısa Tekrar Notları

- Hayat bilgisi (commonsense): herkesin bildiğini varsaydığımız bilgiler; metinde yazmayan ama anlamak için gereken bilgi.
- Duygudurum örneği: "5 dakikada geldi" olumlu, "55 dakikada geldi" imalı/olumsuz; ayrım dünya bilgisi ister.
- İki yaklaşım: uzmanlar formal dille girer (Cyc: 20 yılda 1,5 milyon, güvenilir, yavaş) ve gönüllüler serbest girer (OpenMind: 8000 kişi, 3 yılda 1 milyon, hızlı, tutarsız).
- Popüler çalışmalar: Cyc 1984, WordNet 1985, OpenMind/ConceptNet 2002, NELL 2010.
- ConceptNet: OMCS cümlelerinden üçlü çıkarımı (%90) + zenginleştirme (%10); 1,6 milyon üçlü, 20 ilişki türü.
- NELL: seed ikililer → şablon → yeni ikililer → yeni şablonlar; kısıtlar ve günlük insan denetimi.
- Şablon: "bir tür X olan Y" → isa(X,Y).
- Monotonik çıkarım kesindir ama yeni bilgi üretmez; monotonik olmayan çıkarım tahmindir ve doğrulanınca yeni bilgi olur.
- CSoyun çıkarım türleri (ekrandan, 01:41:35):

```text
(X-R1-Y) and (Y-R2-Z) -> (X-R3-Z)
  (martı - altkavramıdır - kuş) ve (martı - bu ne yapabilir - uçmak)
  -> (kuş - bu ne yapabilir - uçmak)
(X-R1-Y) -> (X-R2-Y)
  (sinemaya gitmek - içerdiği olaylar nelerdir - mısır yemek)
  -> (sinemaya gitmek - bunun için ilk önce ne yaparsın - mısır yemek)
(X-R1-T) and (Z-R1-T) and (X-R2-Y) -> (Z-R2-Y)
  (kedi - altkavramıdır - memeli) ve (köpek - altkavramıdır - memeli)
  ve (kedi - sahiptir - kürk) -> (köpek - sahiptir - kürk)
(X-R1-Y) and (X-R2-Z) -> (Z-R3-Y)
  (bıçak - nerede bulunur - mutfak), (bıçak - ne için kullanılır - kesmek)
  -> (kesmek - nerede yapılır - mutfak)
```

- Kalite: doğruluk (örneklem oylatma) ve kapsayıcılık (derlemdeki kavram oranı, insan üretimi ilişkilerin kapsanma oranı) birbiriyle çelişir.

## Detaylı Açıklamalar

- Prolog örneğinden hayat bilgisine geçiş
  - Geçen dersin Prolog örneğinde (ekrandan, 00:07:45) gerçek bilgiler `kapsar(oda,ev).`, `kapsar(sinif,okul).`, `vardir(oku,ali,kitap,sinif,12).` biçimindeydi. Türetme kuralları şunlardı:

```prolog
vardir2(git,M,_,Yer,_) :- vardir(_,M,_,Yer,_).
% M Yer'de bulunmuşsa -> M Yer'e gitmiştir
vardir2(F,M,B,Yer1,I) :- kapsar(Yer2,Yer1), vardir2(F,M,B,Yer2,I).
% M Yer2'de bir şey yapmışsa ve Yer2 Yer1'i kapsıyorsa -> M Yer1'de de aynı şeyi yapmıştır
vardir2(yer,ali,oglenyemegi,mutfak,_) :- vardir2(git,ali,_,ev,_).
% Ali eve gitmişse -> öğlen yemeğini mutfakta yer
vardir2(yer,ali,oglenyemegi,kantin,_) :- vardir2(git,ali,_,okul,_).
% Ali okula gitmişse -> öğlen yemeğini kantinde yer
```

  - Hoca, buradaki `kapsar` gerçeklerinin ve ilk iki kuralın aslında hayat bilgisi olduğunu vurguladı: soruyu cevaplamayı sağlayan, metinde yazmayan bilgi. Bu dersin sorusu, bu tür bilgilerin geniş ölçekte nasıl toplanacağıdır.
- Cyc ve OpenMind karşılaştırması
  - Cyc'te bilgiler, kendine ait formal bir dilde, ücretli uzmanlarca girilir. Her bilgiye güvenilir, ama süreç yavaştır.
  - OpenMind'da sokaktaki insanın önüne formal bir yapı koymak süreci yavaşlatır; bu yüzden insanlar bilgiyi serbest cümle olarak girer. Sonra bu cümleler otomatik olarak üçlülere çevrilir. Bu yaklaşım zamanla evrilerek ConceptNet'e dönüşmüştür ve yeni sürümleri çıkmaya devam etmektedir.
  - Hoca, sonraki dönemde Cyc ve OpenMind dışında başka çalışmaların da çıktığını söyledi. <!-- BELİRSİZ: 00:20:27'de hoca 2020 civarında çıkan bir çalışmanın adını "Cassandra" gibi söyledi; slaytta yok, ad doğrulanamadı. -->
- ConceptNet ilişkileri
  - İlişkiler şu türden ifadeleri temsil eder: "bu şunun için kullanılır", "bu şunun bir parçasıdır", "bu bir tür şudur", "bunu yapmak için önce şunu yapmalısın", "şu durumda ajan şunu ister", "böyle yaparsan sonucu şu olur".
  - İlişki türü sayısı binlerce değildir; ilk sürümde yaklaşık 20 ilişki türü ve bunlara ait 1,6 milyon üçlü vardır.
- NELL'in iteratif döngüsü ve güvenilirlik
  - NELL'in arayüzünde öğrenilen her bilgi, öğrenildiği iterasyon, tarih ve güven değeriyle gösterilir (ekrandan, 01:29:30). Örneğin "movie" kategorisinde "aliens" ve "an_american_in_paris" seed olarak verilmiş, "beowulf" ise sistem tarafından 161. iterasyonda bulunmuştur (ekrandan, 01:30:00).
  - Hoca, 2012-2013 civarı için 50 milyon aday ilişkiden 1,8 milyonunun yüksek güvenle tutulduğunu söyledi. <!-- BELİRSİZ: 01:30:48'deki bu sayılar ekranda görülmedi; 01:29:30'daki 2012 tarihli ekran görüntüsünde "15 milyon aday bilgi, 1.027.444 yüksek güvenli bilgi" yazıyor. -->
  - Şablon ve ilişki güvenilirliği birbirine bağlıdır (hocanın deyişiyle tavuk-yumurta ilişkisi): şablon, ürettiği ikililer ne kadar doğruysa o kadar güvenilirdir; ilişki ise onu üreten şablonların güvenilirliğine, kaç farklı şablondan üretildiğine ve kullanıcı puanlarına göre güvenilirdir.
- CSoyun oyunları
  - Bildiklerim: kullanıcı bir ilişki türü seçer, sistemin bildiği ilişkiler gösterilir, kullanıcı 0-5 arası puan verir. Puan ikili değildir, çünkü bazı ilişkilerde dünya ikili değildir.
  - Araştır: kullanıcı bir kelime ve bir ilişki seçer, karşısına üçüncü kavramlar gelir ve bunları puanlar.
  - Tahminlerim: sistem monotonik olmayan çıkarımla veritabanında olmayan bir ilişki üretir ve kullanıcıya sorar. Ekrandaki örnek: "hayal — Bu neyin ilk adımıdır? — yaşamak" için Doğru, Yanlış ya da Ben Bilmem seçilir (ekrandan, 01:36:25).
  - Bana Öğret: kullanıcıya bir kavram ve ilişki türü verilir, kullanıcı yeni kavram girer.
  - Birlikte Eğitim: iki kullanıcı aynı oyunu oynar, aynı cevaplar daha yüksek puan alır.
- CSoyun istatistikleri (ekrandan, 01:45:10)
  - Sistem Ocak 2010'da açıldı. 1. rapor (18 Nisan 2010) ve 2. rapor (23 Şubat 2012) arasında: oy sayısı 34 binden 155 bine, kullanıcı sayısı 65'ten 182'ye, ilişki türü sayısı 40'tan 45'e, ilişki sayısı 1,09 milyondan 1,2 milyona, kavram sayısı 475 binden 700 bine çıktı.
  - Oylar 0-5 arasıdır, ortalaması yaklaşık 3,1'dir. Oylanan tekil ilişki sayısı yaklaşık 99 bindir; yani 2 yılda ilişkilerin yaklaşık %8,3'ü oylanmıştır ($99\,000 / 1\,200\,000 \approx 0{,}0825$).
- Grup etkinliğinde üretilen fikirler (akademik içerik)
  - Hoca öğrencilerden gruplar hâlinde hayat bilgisi toplamak, toplanmış bilgiyi iyileştirmek ya da onu kullanan uygulamalar için fikir üretmelerini istedi. Öne çıkan fikirler:
  - Sosyal medya gönderilerine verilen tepkilerden ilişki çıkarmak (örneğin "yarın kar yağacak" gönderisine gelen "okullar tatil mi?", "kar lastiği takmak lazım" yorumları) ve bunları başka kullanıcılara oylatmak.
  - Hava durumu ile duygu durumu ve eylemler arasında olasılıklı ilişki kurmak (gönderinin atıldığı günün hafta içi ya da sonu olması da önemli).
  - Kullanıcı girdilerini diğer kullanıcıların onaylamasıyla (upvote/downvote) veritabanı kurmak ve iyileştirmek; güvenilir bir veritabanıyla tutarsızlık/yalan tespiti ve eylemlerin yararlı/zararlı sınıflandırılması.
  - Kalıplarla (regex) ilişki çıkarıp belli bir frekansın üstündekileri doğru kabul etmek; veritabanını dil modeline ilişki tahmini görevi olarak vermek ya da veri artırımı için kullanmak (örneğin "Microsoft" yerine "Bill Gates tarafından kurulan şirket").
  - İnsanlara rastgele fotoğraflar gösterip yorumlarını toplamak; "ne biliyorsun?" sorusunda akla gelmeyen bilgiler fotoğrafa bakınca akla gelebilir.
  - Hoca, son fikri kapsayıcılık ölçümüyle ilişkilendirdi: insanlara rastgele bir kavram ya da resim gösterip ürettikleri ilişkilerin ne kadarının veritabanında bulunduğuna bakılabilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
