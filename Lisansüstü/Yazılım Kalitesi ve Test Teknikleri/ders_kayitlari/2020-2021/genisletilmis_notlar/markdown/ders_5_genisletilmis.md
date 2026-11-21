# Ders 5 Genişletilmiş Notu: Test Sürecinin Tekrarı ve Yazılım Ölçümü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Test Sürecinin Tekrarı: V Model
- 2. Birim Testi ve Yardımcı Kavramlar
- 3. Bütünleme Testi
- 4. Regresyon, Sistem ve Kabul Testi
- 5. Test Tipleri: Saydam Kutu ve Kara Kutu
- 6. Hata Düzeyleri
- 7. Yazılım Ölçümü: Neden Ölçeriz?
- 8. Halstead Ölçütü
- 9. McCabe Döngüsel Karmaşıklığı
- 10. Yazılım Güvenirliği ve Güvenirlik Modelleri
- 11. Büyüklük Ölçütleri: Fonksiyon Noktası ve Kod Satırı
- 12. Nesneye Yönelik Metrikler: CK Metrik Kümesi
- Örnek Sorular
- Dersin Toparlaması

## 1. Test Sürecinin Tekrarı: V Model

Dersin asıl konusu yazılım ölçümü ve yazılım metrikleriydi. Hoca bu konuya geçmeden önce, ortak bir zemin oluşturmak için önceki haftalarda görülen test sürecini ve test tiplerini bir kez daha gözden geçirdi.

Tekrar, artık iyi bilinen V model şekli üzerinden yapıldı (ekrandan, 00:10:00). Slayttaki şekil "Test sürecindeki Alt Test Adımları (V Model yaklaşımına göre)" başlığını taşır. Şeklin sol kolu yazılım geliştirme aktivitelerini, sağ kolu yazılım test aktivitelerini gösterir. Her geliştirme adımı, karşısındaki test adımına ya doğrulama ya da geçerleme ilişkisiyle bağlanır:

| Geliştirme adımı (sol kol) | İlişki | Test adımı (sağ kol) | Yanındaki ek test |
|---|---|---|---|
| Müşteri gereksinimleri | Geçerleme | İşlemsel kullanım | Beta test, teşhis testi |
| Ürün spesifikasyonu | Geçerleme/Doğrulama | Sistem testi | Kabul testi |
| Yüksek düzey tasarım | Doğrulama | Bütünlük testi | Regresyon testi |
| Alçak düzey tasarım | Doğrulama | Bileşen testi | |
| Kodlama ve birim test (V'nin dibi) | | | |

Hoca, test sürecinin geliştirme sürecindeki adımları temel aldığını ve o adımlarda hazırlanan belgeleri kullanarak yürütüldüğünü vurguladı. Test sürecini geliştirmeden bağımsız bir faaliyet olarak düşünmemek gerekir; her test adımı, karşısındaki geliştirme adımının ürettiği belgeden beslenir.

## 2. Birim Testi ve Yardımcı Kavramlar

Test aşamalarının ilki birim testidir. Burada amaç modüllerin içindeki hataları bulmaktır ve genellikle saydam kutu testi yapılır. Birim testinde modülün ara birimi, yerel veri yapıları, kontrol yapıları ve bunlar arasındaki ana yollar üzerinde çalışılır.

Birim testinde üç kavram öne çıkar:

- **Test sürücü (test driver):** Test edilecek birim bağımsızsa ona doğrudan veri gönderip sonuçlarına bakılabilir. Ama birim genellikle başka bir modül tarafından çağrıldığı için, onu çağıracak yapay bir program gerekir; bu test sürücüdür.
- **Koçan (stub):** Test edilen modül başka modülleri çağırıyorsa, bu çağrılan modüllerin yerine konan yapay alt programlara koçan (stub) denir.
- **Test senaryosu (test case):** Programın hangi veriyle çalıştırılacağını tanımlayan test verisidir. Birim testte kullanıldığı gibi diğer test adımlarında da oluşturulan test verisine test senaryosu denir. Kullanıcı testinde test senaryosu daha çok kara kutu bakış açısıyla hazırlanır; saydam kutu testi ise daha çok birim testte kullanılır.

Test sürücü ve koçanın ikisi de yapay modül biçiminde hazırlanan ara programlardır.

## 3. Bütünleme Testi

### 3.1 Neden gerekir?

Bütünleme testi (bütünlük testi, integration test) aşamasında modüller artık bağımsız değildir; bir bütün hâlinde çalışırlar. Slayta göre bu bağlantı "yazılım arabirimi" (software interface) ile sağlanır (ekrandan, 00:15:00). Her modül tek başına doğru çalışsa bile birleştirildiklerinde şu sorunlar ortaya çıkabilir:

- veri kaybı,
- dikkatsizlik nedeniyle modüllerin birbirini ters etkilemesi,
- alt fonksiyonlar birleştirildiğinde beklenen ana fonksiyonun gerçekleşmemesi,
- her birinde göze alınabilen hata toleranslarının eklenerek büyümesi,
- genel veri yapılarının sorun yaratması.

Bu hata nedenlerini bulup modüllerin bir arada da doğru çalışmasını sağlama işine bütünleme testi denir.

### 3.2 Bütün olarak ve artırmalı sınama

Slayta göre bütünleme testi iki biçimde birleştirmeden sonra yapılır (ekrandan, 00:20:00): bütün olarak sınama ve artırmalı sınama. Artırmalı sınamada modüller teker teker, bir sıra ya da plan dahilinde birbirine bağlanır. Uygulamada genellikle artırmalı sınama tercih edilir. Artırmalı sınama yukarıdan aşağı ya da aşağıdan yukarı olarak iki ayrı şekilde uygulanır.

Aşağıdan yukarı yaklaşımda önce alttaki modüllerin test edilmiş olması gerekir; test edilen modüller birleştirilerek kümeler (cluster) oluşturulur ve bu kümelerin birbirine nasıl bağlanacağına göre yukarı doğru ilerlenir.

### 3.3 Birleştirme planı nereden gelir?

Hoca burada bir soru sordu: Artırmalı sınamada hangi modüllerin hangi sırayla, hangi hiyerarşiyle birleştirileceğine karar verirken geliştirme sürecinin hangi adımından ve hangi belgesinden yararlanılır? Gereksinim analizi cevabı verildiğinde hoca bunun bir adım önde kaldığını, gereksinim belgesinin sistem testi ve kullanıcı testinde kullanıldığını söyledi. Doğru cevap tasarım belgesidir.

Gereksinim analizinde yazılımın ne yapacağına karar verilir, sistemin çalışma şekli anlaşılır ve buna göre bir belge hazırlanır; bu belge kullanıcı testine ve sistem testine yarar. Tasarım aşamasında ise bu işlerin bilgisayara nasıl aktarılacağına karar verilir: hangi modüller kullanılacak, bu modüller nasıl sınıflanacak ve yapılandırılacak, nasıl bir hiyerarşi kurulacak, hangi modül hangisine bağlı olacak. Yazılımın mimari yapısı genel tasarımda çıkarılır ve bütünlük testinde bu yapı kullanılır. Kaynak belge, yazılım tasarım spesifikasyonudur (Software Design Specification, SDS); içindeki yapı diyagramı ya da nesneye yönelik yaklaşımda sınıf diyagramı birleştirme planını verir.

Derste bir öğrenci "alçak düzey tasarım (low level design) dokümanı" cevabını verdi ve hoca önce bunu kabul etti; ardından V model şekline dönerek kendini düzeltti: alçak düzey tasarım, modüllerin algoritma yapısıyla bileşen testinde kullanılır; bütünlük testiyle eşleşen adım yüksek düzey tasarımdır (ekrandan, 00:25:00).

> **Hocanın vurgusu:** Bütünlük testi, yüksek düzey (genel) tasarımda oluşturulan mimari yapıyı kullanır; gereksinim belgesi ise sistem ve kullanıcı testlerini besler.

## 4. Regresyon, Sistem ve Kabul Testi

### 4.1 Regresyon testi

Regresyon testi, test edilmiş bir program ya da program parçasında değişiklik veya ekleme yapıldığında tümünün bir kez daha test edilmesidir. Uygulama ortamında değişiklik olduğunda da regresyon testine başvurulur. Önceden test edilmiş yazılımın çeşitli değişikliklerden sonra hâlâ hatasız olup olmadığına bakan bu teste tekrarlama testi de denebilir.

### 4.2 Sistem testi

Bütünlük testinden sonra yazılımın parçaları birbiriyle uyumlu çalışır hâle gelmiştir. Sistem testinde yazılımın işletim sistemi, alt yazılım ve destek yazılımları ile donanım açısından bir sorunu olup olmadığına bakılır. Güvenlik testi, dayanıklılık testi ve performans testi sistem testine girer:

- **Güvenlik testi:** Sistem zararlı dış müdahalelerden ve bilgi hırsızlığından korunabiliyor mu?
- **Dayanıklılık testi:** Sistem anormal biçimde yüklendiğinde dayanabiliyor mu?
- **Performans testi:** Özellikle gerçek zamanlı ve gömülü sistemlerde, yazılımın işlem süresi bilgisayara dayalı sistemle uyumlu mu?

Performans testi aslında her basamakta, birim ve bütünlük testi sırasında da tekrarlanabilir; ama bütünlük testi tamamlandıktan sonra bütün üzerinde mutlaka denenmelidir.

Ayrı bir slaytta performans testi ayrıntılandırıldı (ekrandan, 00:30:00). Performans testinde gerçekleştirilen işlemler şunlardır:

- performans seviyelerinin belirlenmesi,
- belirli bir yük altındaki sistem çalışma zamanı performansının ölçülmesi,
- sistem ayarlamaları (tuning).

Performans testi şu sorulara cevap verir:

- Sistem gereksinimleri karşılanıyor mu?
- Normal şartlar altında sistem nasıl davranıyor?
- Sistem trafiğindeki artışlar işlem süresini ve fonksiyonaliteyi nasıl etkiler?
- Hangi kullanıcı seviyesinde performans problemleri yaşanır?
- Performans seviyelerindeki düşüş sistemin hangi bileşeninden kaynaklanır?

Hoca, sistem testinde gereksinim belgesine (SRS) bakıldığını, özellikle işlevsel olmayan gereksinimlere (non-functional requirements) cevap verilip verilmediğinin sınandığını belirtti.

### 4.3 Kabul testi

Sistem testinden sonra kabul (onaylama) testi gelir. Hoca, slaytta onaylama testini sistem testiyle aynı sıradaymış gibi yazdığını, ama aslında bunun bir üst basamak olduğunu söyledi. Kabul testi (acceptance test), müşterinin kabul aşamasıdır ve iki parçası vardır:

- **Düzenin (konfigürasyonun) incelenmesi:** Kullanıcı belgeleri, tasarım belgeleri, kayıtlar ve test belgeleri tam mı, birbiriyle ilişkileri belirtilmiş mi? Konfigürasyonda verilecek denilen her şey teslim edilmiş mi?
- **Onaylama testi:** Bütünleştirilmiş ve sistem testinden geçmiş yazılım, kullanıcılar ya da kullanıcı benzerleri tarafından kullanıcı belgeleri izlenerek kullanılır ve gereksinimlere cevap verip vermediği sınanır. Yazılım, kullanıcı seviyesinde çalışır durumda olmalıdır.

Bu iki adım tamamlanınca yazılımın teslimi gerçekleşir.

## 5. Test Tipleri: Saydam Kutu ve Kara Kutu

Test tipleri kara kutu, saydam kutu ve gri kutu testidir. Fonksiyonel, performans ve dayanıklılık testleri sistemin dış spesifikasyonlarına ve gereksinimlerine dayandığı için bunlara kara kutu testi (black box testing) denir. Buna karşılık yapısal denetimde, modül düzeyinde programın deyimleri ya da dalları sınanarak iç yapı incelenir; bu şekilde uygulanan teste saydam kutu testi denir. Saydam kutu testinde yazılımın algoritmasına, her modülün algoritmasına, bütünlük testinde ise modüller arasındaki iç yapılara bakılır.

### 5.1 Saydam kutu testi

Saydam kutu testinde işlemsel (prosedürel) tasarımın kontrol yapısı kullanılır. Bu testle:

- bir modüldeki bütün bağımsız yollar en az bir kez çalıştırılır,
- mantıksal kararların doğru ve yanlış durumları denenir,
- bütün döngüler kendi içinde ve sınırlarında işletilir,
- iç veri yapıları denenir.

Bu aşamada en çok kullanılan iki teknik temel yol testi ve döngü testidir.

**Temel yol testi**, işlemsel tasarımın mantıksal karmaşıklığını ölçüp bu ölçüye göre uygulama yolları için bir temel grup oluşturma esasına dayanır; test sırasında programdaki her deyim en az bir kez uygulanır. Algoritma izlendiği için kaynak koda hakim olmak gerekir. Ayrıntılı tasarım ya da kaynak programdan bir akış grafı çizilir, düğümler ve kenarlar bulunur ve bunlardan döngüsel karmaşıklık değeri hesaplanır (bu değer dersin ilerleyen kısmında, ölçüm konusunda ayrıntılandırıldı; bkz. Bölüm 9). Döngüsel karmaşıklık kaç tane temel yol olduğunu verir. Kaç temel yol varsa o kadar test verisi, yani test case hazırlamak gerekir.

**Döngü testi** de bir saydam kutu testidir ve temel yol analizine ek olarak yürütülür. Hangi döngü yapısı olursa olsun döngülerin başlangıcı, bitişi, indisleri ve artımları kontrol edilir. Bu değerlerde yanlışlık varsa döngüye hiç girilmeden geçilebilir, iç içe döngülerde sorun çıkabilir ya da ardışık döngüler arasında karmaşıklık ve değer atlaması olabilir. Slayttaki "Program döngüleri" şeklinde dört döngü türü gösterilir (ekrandan, 00:35:00): basit döngü, yuvalanmış (iç içe) döngü, birbirine bağlı (ardışık) döngü ve yapısal olmayan döngü.

### 5.2 Kara kutu testi

Kara kutu testi, yazılımın bütünlenmesi ve kullanımı sırasında uygulanır; mantıksal iç yapıdan çok temel sistem modelini denemeyi hedefler. Hoca, saydam kutu ve kara kutu testinden birinin seçilmediğini, ikisinin birlikte kullanıldığını vurguladı.

Kara kutu testinde girdi test verileri oluşturulur ve bunlara mutlaka anormal (anomali) veriler de eklenir; ardından bu girdilerin çıktıya nasıl yansıdığına bakılır. Kara kutu testleri işlevsel gereksinimlere uygunluğu göstermek için bir dizi girdi durumu oluşturur. Veri yapılarına ve veri tabanına erişimdeki hatalar ile performans hataları da kara kutu testinde ortaya çıkar. Derste iki kara kutu yöntemi üzerinde durulmuştu:

- **Eşdeğer bölümleme:** Girdi uzayı sınıflara bölünür ve her sınıftan veri girilecek şekilde test hazırlanır. Geçerli girdi aralıkları sınıflar hâlinde verilir, ayrıca geçersiz girdiler de verilir. Çıktılar da sınıflar hâlinde izlenir: hangi sınıfta hangi tür hatalar oluşuyor, hangi tür çıktılar alınıyor.
- **Sınır değer analizi:** Bir yerde hata varsa çoğunlukla sınırda, kenardadır; ortada pek hata olmaz. Bu yüzden aralıkların kenar değerleri test edilir.

## 6. Hata Düzeyleri

Bir yazılım ekibi hataları sınıflayıp hangi düzeyde hangi hataların çıktığını ve hangilerinin düzeltildiğini izlemelidir. Hoca bunun bir örnek sınıflama olduğunu, daha az sınıfa da ayrılabileceğini söyledi. Slayttaki hata düzeyleri ve anlamları şöyledir (ekrandan, 00:40:00):

- **Ölümcül hata:** Testin devamını engeller. Hoca, ölümcül hata varsa test durdurulduğunu ve düzeltilmeden devam edilmediğini söyledi.
- **Kritik hata:** Test devam eder, ama hata düzeltilmeden yazılım teslim edilmez.
- **Büyük hata:** Giderilmeden yazılım teslimi zararlıdır.
- **Orta hata:** Testler devam edebilir; ürün bu hatayla teslim edilirse telafisi mümkün sorunlar çıkabilir.
- **Küçük hata:** Testler devam edebilir ve ürün bu hatayla teslim de edilebilir, yazılımda önemli bir sonuç doğurmaz; daha sonra düzeltilmek koşuluyla teslim mümkündür.
- **Görünüm hatası:** Yazılımın renk, font, büyüklük gibi görünümüyle ilgili hatalardır.

Hataları bir de nedenlerine, yani hangi süreçte ortaya çıktıklarına göre sınıflamak mümkündür. Hoca, daha eski tarihli bir çalışmada hataların en çok gereksinim aşamasından kaynaklandığının görüldüğünü belirtti.

## 7. Yazılım Ölçümü: Neden Ölçeriz?

Molanın ardından yeni bölüme, "Kalite Ölçüm ve Değerlendirmeleri"ne geçildi. Bölümün hedefleri slaytta şöyle verilir (ekrandan, 00:50:00): yazılım kalite ölçütlerinin incelenmesi, yazılım ölçütlerinin test adımlarında kullanımının anlaşılması, kalite güvenirliğinin kestirimini ve modellerini tanıma.

Konu Tom DeMarco'nun klasikleşmiş sözüyle açılır: "Yazılım üretimi ölçülemez ise kontrol edilememektedir." (ekrandan, 01:00:00). Hoca bu sözün genelleştirilebileceğini söyledi: Ölçemediğimiz hiçbir şeyi kontrol edemeyiz.

Yöneticiler ve yazılım mühendisleri farklı gereksinimlerle ölçüm yapar. Slayta göre yöneticiler şunlar için ölçüme gereksinim duyar (ekrandan, 01:00:00):

- yazılım üretimi için maliyetin ne olacağı,
- farklı bölüm çalışanlarının ücretlerini belirlemek için personel üretkenliği,
- farklı projelerde geliştirilen yazılım ürünlerini kıyaslamak için yazılım kalitesi,
- projeler için ölçülebilir hedefler, örneğin yazılımın ne kadar güvenilir olacağı,
- şirkette kullanılmaya başlanacak yöntem ve yazılım geliştirme araçlarının etkinliği.

Hoca, yöneticilerin özellikle bitmiş projelere bakarak yeni başlayacak bir projenin maliyetini tahmin etmek ve bitmiş bir projede ne kadar harcandığını bilmek istediğini vurguladı.

Yazılım mühendisleri ise süreç ölçümleriyle sistemin kalitesini izler: test sırasında bulunan hatalarla güvenirliği belirlemek, kalite ve performans gereksinimlerini kesin ölçülebilir terimlerle tanımlamak, sertifika için ürün ve süreç özelliklerini ölçmek. Ölçüm yazılımın yapısına karar vermede de kullanılır; örneğin modüllerin belirli bir kod satırından uzun olmaması gibi. Var olan ürünlerden ve uygulanan süreçlerden yararlanarak gelecekteki ürünler için tahmin yapmak da ölçümle mümkündür: bitmiş projelerin büyüklüğü ve maliyetinden yola çıkılarak yeni projelerin maliyeti tahmin edilir. Bu tahmin yöneticilerin istediği bir şeydir, ama temelini yazılım mühendisleri oluşturur.

## 8. Halstead Ölçütü

Halstead ölçütü, programlardaki aritmetiksel karmaşıklığı bulmaya yöneliktir. Programda kaç tane işleç (operatör) ve kaç tane işlenen (operand) olduğundan yola çıkarak yazılımın aritmetik işlem yoğunluğunu değerlendirir; program uzunluğu, program hacmi ve programın gücü hakkında bilgi verir. İşlenen değerlerin yinelenme sayıları, örneğin döngü içinde bulunmaları da hesaba girer.

Slayttaki tanımlar şunlardır (ekrandan, 01:05:00). Halstead, kaynak programın kalite güvencesini kestirmek üzere

- $m$: programda bulunan farklı işleç (operatör) sayısı,
- $k$: programda bulunan farklı işlenen (operand) sayısı,
- $M$: işleç yinelenmelerinin toplamı,
- $K$: işlenen yinelenmelerinin toplamı

değerlerinin saptanmasını ve bunlardan aşağıdaki ölçütlerin hesaplanmasını önerir:

$$\text{Program uzunluğu: } U = m\log_2 m + \log_2 k$$

$$\text{Program hacmi: } H = (M+K)\log_2(m+k)$$

$$\text{Program gücü (program effort): } G = H/O$$

Slayta göre oransal hacim daima birden küçük bir sayı olarak bulunmalıdır. <!-- BELİRSİZ: G = H/O formülündeki O simgesi slaytın görünen kısmında tanımlanmıyor; büyük olasılıkla "oransal hacim"dir. -->

> **Ders sonrası not:** Slayttaki uzunluk formülünün ikinci terimi $\log_2 k$ olarak yazılmış. Halstead'in tahmini program uzunluğu formülü büyük olasılıkla $U = m\log_2 m + k\log_2 k$ biçimindedir; slaytta $k$ çarpanı eksik görünüyor.

> **Hocanın vurgusu:** Halstead formüllerini ezbere bilmek gerekmez. Bilinmesi gereken, Halstead ölçütünün aritmetiksel karmaşıklığı ölçtüğü ve işleç ile işlenen sayılarına dayandığıdır.

> **Ek bilgi (derste anlatılmadı):** Halstead'in özgün çalışmasında "program düzeyi" (program level) adı verilen ve büyük olasılıkla slayttaki oransal hacme karşılık gelen bir oran tanımlanır; bu oran, olası en kısa programın hacminin gerçek program hacmine bölümüdür ve bu yüzden 1'den küçüktür. Program gücü (effort) de hacmin bu orana bölünmesiyle bulunur.

## 9. McCabe Döngüsel Karmaşıklığı

### 9.1 Ne ölçer, nerede kullanılır?

McCabe ölçütü, algoritma kapsamında programın kontrol akışını değerlendirerek karmaşıklık derecesini belirler. Hoca bu ölçütün iki yerde kullanıldığını söyledi:

- **Tasarımda:** ayrıntılı (alt düzey) tasarım, yani algoritma tasarımı sırasında,
- **Testte:** bunun karşılığı olan birim testte, saydam kutu testi sırasında.

Saydam kutu testinde McCabe'in döngüsel karmaşıklık (cyclomatic complexity) değeri, bir yazılımda ya da modülde kaç tane algoritma yolu, yani temel yol bulunduğunu ortaya çıkarır. Tekrar kısmında görüldüğü gibi, temel yol testinde her temel yol için bir test case hazırlanır; bunun için önce bir akış grafı oluşturulur ve döngüsel karmaşıklık hesaplanır. Bu hesap McCabe ölçütüyle yapılır.

### 9.2 Akış grafı nasıl çizilir?

Akış grafı hazırlanırken programın bütün akış kontrol deyimleri ve döngüleri ayrı birer düğüm olarak gösterilir. Bunların dışında ardışık giden komutlar tek bir düğümde toplanır. Kontrol düğümlerinden çıkan farklı akış yönleri farklı düğümlere gider.

### 9.3 Ortalama alma yöntemi örneği

Hoca, Roger Pressman'ın Software Engineering kitabından alınmış bir örneği gösterdi: ortalama alma yöntemine ait bir akış grafı (ekrandan, 01:10:00). Slayttaki şeklin altyazısı şöyledir: "Ortalama alma yöntemine ait akış grafı (R2 .. R5 graf içindeki kapalı bölgeler, R1 graf dışında kalan bölge)".

Grafta 1'den 13'e kadar numaralı düğümler vardır. Karede okunabildiği kadarıyla kenarlar şöyledir:

```text
1 -> 2
2 -> 3,  2 -> 10
3 -> 4,  3 -> 10
4 -> 5
5 -> 6,  5 -> 8
6 -> 7,  6 -> 8
7 -> 8
8 -> 9
9 -> 2          (döngünün geri dönüş kenarı)
10 -> 11, 10 -> 12
11 -> 13, 12 -> 13
```

Hoca, "Burada kaç farklı yol var?" diye sordu ve cevabı bölgeleri sayarak verdi: en dışta kalan bölge de sayılır, ayrıca kapalı bölgeler sayılır. Şekilde R1, R2, R3, R4, R5 ve R6 olmak üzere altı bölge vardır. Dolayısıyla döngüsel karmaşıklık 6'dır; altı temel yol vardır ve saydam kutu testinde altı test case hazırlanmalıdır.

Döngüsel karmaşıklık düğüm ve kenar sayılarından da hesaplanabilir. Hoca bunu "kenar sayısı eksi düğüm sayısı artı bir" diye söyledi.

> **Ders sonrası not:** Hoca formülü "kenar sayısı eksi düğüm sayısı artı bir" diye ifade etti; doğrusu $V(G) = E - N + 2$'dir ($E$: kenar, $N$: düğüm sayısı). Ekrandaki grafta okunan $E = 17$ kenar ve $N = 13$ düğümle $V(G) = 17 - 13 + 2 = 6$ bulunur; bu, bölge sayısıyla (R1-R6) tutar. "Artı bir" ile 5 çıkardı (python ile kontrol edildi).

> **Ek bilgi (derste anlatılmadı):** Döngüsel karmaşıklık üç eşdeğer yolla bulunur: akış grafındaki bölge sayısı, $V(G) = E - N + 2$ ve $V(G) = P + 1$ ($P$: karar düğümü sayısı). Bu örnekte karar düğümleri 2, 3, 5, 6 ve 10'dur ($P = 5$), dolayısıyla $V(G) = 5 + 1 = 6$ olur.

Hoca bu döngüsel karmaşıklığın, algoritmalar dersinde görülen algoritma karmaşıklığından farklı bir metrik olduğunu da belirtti.

### 9.4 Tasarımda kullanım: modül büyüklüğü sınırı

McCabe ölçüsü en yüksek modül büyüklüğünü saptamakta da kullanılır. Slayta göre çok sayıdaki programlama projesinden derlenen deneyimlere göre bir modülün büyüklüğü en çok $V(G) = 10$ olmalıdır (ekrandan, 01:10:00, slayt küçük görünümü; hoca da sözlü olarak aynısını söyledi). Döngüsel karmaşıklık bu değeri aşarsa modülün test edilmesi ve takip edilmesi büyük ölçüde zorlaşır; bu durumda modülün yeni alt modüllere bölünmesi tavsiye edilir.

> **Hocanın vurgusu:** Bir modülün döngüsel karmaşıklığı 10'dan fazlaysa test ve takip zorlaşır; modül alt modüllere bölünmelidir.

## 10. Yazılım Güvenirliği ve Güvenirlik Modelleri

### 10.1 Güvenirlik nedir?

Güvenirlik (reliability) önemli bir kalite ölçütüdür. Yazılım kalite faktörlerine bakıldığında bir yanda doğruluk, diğer yanda bu doğruluğun ne derece güvenilir olduğu vardır. Bütün yazılımların aynı kalitede olması ve aynı bileşenlerle aynı sonucu vermesi beklenemez. Yazılımı tümüyle test etmek de mümkün değildir. Hoca, bin kod satırlık bir programda bir satırın hatalı olabileceğinin tahmin edildiğini söyledi; slaytın küçük görünümünde de 1000 satırlık bir programda en az bir satırın hatalı çıktığının tahmin edildiği yazar. Genel olarak güvenirlik hata sayısıyla ilişkilidir: bulunan doğru sonuçlar ne kadar güvenilirdir?

<!-- BELİRSİZ: Güvenirlik slaytının küçük görünümünde "Başarı oranı = Başarılı süre / Toplam işlem süresi" biçiminde bir formül seçiliyor; slayt büyük gösterilmediği ve sözlü anlatılmadığı için kesin okunamadı. -->

### 10.2 Güvenirlik modelleri

Slayta göre güvenirlik modelleri istatistiki verilere dayanarak yazılımın güvenirliğini saptar. Bu modellerin çalıştırılması sonucunda şu gibi değerler elde edilir (ekrandan, 01:15:00):

- toplam hata sayısı,
- güvenirlik düzeyi,
- sistemde yapılan revizyon sonucunda kalan hata sayısı.

Yüze yakın güvenirlik modeli geliştirilmiştir; hoca bunun yazılım kalitesinin önemli bir alt çalışma alanı olduğunu ve bu konuda çok sayıda kitap bulunduğunu söyledi. Slaytta en yaygın modeller şöyle listelenir (ekrandan, 01:15:00 ve 01:20:00, slayt küçük görünümü):

- Schneidewind modeli,
- Jelinski/Moranda modeli,
- Musa Basic ve Musa/Okumoto logaritmik Poisson yürütme zamanı (execution-time) modeli,
- Littlewood-Verrall modeli.

Bu modeller, yazılımın ne kadar süre kullanıldığında ne kadar hata çıktığından yola çıkarak güvenirliği modeller.

### 10.3 Model seçimi

Hangi modelin uygun olduğuna şu sorulara bakılarak karar verilir:

- Modele göre yazılım ne kadar geçerlidir?
- Modeli kullanarak yazılım güvenirliğini ölçmek ne kadar kolaydır?
- Modeli kullanmak için yazılımın ne kadarına ihtiyaç vardır; bütün yazılıma mı uygulamak gerekir?
- Model yazılım ölçümünde kullanmak için kolay ve anlaşılır mıdır?
- Model dış etkenlerden etkilenir mi?

### 10.4 Güvenirliği sağlama adımları

Yazılımın daha güvenilir olması için geliştirme boyunca şunlar yapılır:

- **Fizibilite ve gereksinim analizi:** işlevsel profili iyi belirlemek; hataları tanımlamak ve sınıflamak (hata sınıflarını oluşturup "şu grupta şu kadar hata var" diye sayılabilir hâle getirmek, böylece istatistik yapmayı kolaylaştırmak); müşterinin güvenirlik ihtiyaçlarını tanımlamak.
- **Tasarım ve uygulama:** bileşenler arasındaki güvenirliği belirlemek, işlevsel kaynaklara odaklanmak, hatalı kodları görmek ve hatalı kodlamayı önlemek, yazılım güvenirliğini her aşamada ölçmek.
- **Sistem testi:** testleri yönetmek, testleri gözlemlemek, ihtiyaç duyulan ek testleri belirlemek, test edilen nesnelerin güvenirliğini geçerlemek (ekrandan, 01:20:00).
- **Teslim ve bakım:** yazılımı kullanıma sunmak, yazılımın güvenirliğini kontrol altında gözlemlemek, müşteri memnuniyetini izlemek, ürüne rehberlik etmek ve ilerleme kaydetmek (ekrandan, 01:20:00).

<!-- BELİRSİZ: Bir önceki slaytın küçük görünümünde bu adımların Bell laboratuvarlarında yapılan bir çalışmada belirlenmiş 25 aktiviteden oluştuğu yazıyor gibi görünüyor; slayt büyük gösterilmediği için kesin okunamadı. -->

> **Hocanın vurgusu:** Her yazılım için güvenirlik ihtiyacı aynı değildir; her uygulama için %99,9 gerekmez. Güvenirlik yükseldikçe maliyeti de artar.

## 11. Büyüklük Ölçütleri: Fonksiyon Noktası ve Kod Satırı

Hoca büyüklük ölçümünün yazılım mühendisliği derslerinde ve birçok üniversitede işlendiğini belirterek sınıfa yazılımın büyüklüğünün nasıl ölçüleceğini sordu.

### 11.1 Fonksiyon noktası (function point)

Bir öğrenci fonksiyon sayısından yola çıkılabileceğini önerdi; hoca bunu fonksiyon noktası (function point) yöntemine bağladı. Fonksiyon noktası, yazılımın büyüklüğünü ölçmeyi sağlayan bir yöntemdir; temel fikir, sayılan büyüklükleri ağırlık faktörleriyle çarpıp toplayarak bir sonuç elde etmektir. Hoca burada tek bir değerin ölçülmediğini, her biri ayrı sayılan bir tablo (matris) oluşturulduğunu vurguladı. Sayılanlar beş farklı şeydir:

- girdi sayısı,
- çıktı sayısı,
- ara birim sayısı,
- sorgu sayısı,
- dosya sayısı.

Bunlar arasında büyüklüğü en çok etkileyen, yani ağırlık faktörü en büyük olan dosya sayısıdır; onu sorgu, ara birim, girdi ve çıktı sayıları izler. Beş farklı şey sayılıp birleştirildiği için fonksiyon noktası dolaylı bir ölçümdür.

> **Ek bilgi (derste anlatılmadı):** Fonksiyon noktası hesabında önce bu beş sayım karmaşıklığa göre ağırlıklandırılıp toplanır (ayarlanmamış fonksiyon noktası), sonra sistemin genel özelliklerine ilişkin sorulara verilen puanlarla elde edilen bir düzeltme çarpanıyla çarpılır. Yöntem büyük olasılıkla 1970'lerin sonunda Albrecht tarafından önerilmiştir.

### 11.2 Kod satır sayısı (LOC, KLOC)

Hoca ardından doğrudan sayarak fikir edinilebilecek bir büyüklük ölçüsü sordu; cevap kod satır sayısıydı. LOC (line of code) doğrudan satır sayısıdır; büyük programlarda binlerle ifade edildiği için KLOC (bin kod satırı) kullanılır. LOC gerçekçi ve objektif bir değer değildir; programlama diline ve ortama bağlı olduğu eleştirisi getirilebilir. Bunun için programlama dilleri arasında dönüşüm tabloları hazırlanmıştır. Kullanımı çok basit olduğu için yine de çok yaygındır.

## 12. Nesneye Yönelik Metrikler: CK Metrik Kümesi

Hoca bugüne kadar sayılanları toparladı: büyüklük ölçütleri, güvenirlik modelleri, aritmetiksel karmaşıklık için Halstead ölçütü ve tasarımda ve testte kullanılan McCabe döngüsel karmaşıklığı. Bunların yanında kalite hakkında fikir veren özel ölçüm setleri de vardır. Nesneye yönelik yazılımların kalitesi hakkında bir şey söylemek için farklı çalışma gruplarının oluşturduğu CK metrik seti ve MOOD seti gibi kümeler kullanılır. Bu metrikler, nesneye yönelik programları diğerlerinden ayıran karakteristikleri ölçer. CK adı, kümeyi oluşturan Chidamber ve Kemerer'in adlarından gelir. Hoca MOOD yerine CK kümesini seçme nedenini en yaygın kullanılan küme olmasıyla açıkladı.

Slaytlardaki altı metrik şunlardır (ekrandan, 01:30:00, 01:35:00, 01:40:00):

### 12.1 WMC: Sınıfın ağırlıklı metot sayısı

Weighted Methods per Class (WMC), bir sınıfın tüm metotlarının karmaşıklıklarının toplamıdır. Tüm metotların karmaşıklığı 1 kabul edilirse WMC sınıfın metot sayısına eşit olur. Sınıfın metot sayısı ve metotlarının karmaşıklığı, sınıfın geliştirilmesine ve bakımına ne kadar zaman harcanacağı hakkında fikir verir. Metot sayısı çok olan taban sınıflar çocuk düğümlerde daha çok etki bırakır, çünkü tanımlanan tüm metotlar türetilen sınıflarda da yer alır. Metot sayısı çok olan sınıfların uygulamaya özgü olma ihtimali yüksektir; bu yüzden tekrar kullanılabilirliği (reusability) düşürürler.

### 12.2 DIT: Kalıtım ağacının derinliği

Depth of Inheritance Tree (DIT), sınıfın kalıtım ağacının köküne uzaklığıdır. Hiçbir sınıftan türetilmemiş sınıflar için 0'dır; çoklu kalıtım varsa en uzak köke olan uzaklık alınır. Kalıtım hiyerarşisinde daha derinde olan sınıflar daha çok metot türettikleri için davranışlarını tahmin etmek zordur. Derin kalıtım ağaçları daha çok tasarım karmaşıklığı oluşturur.

### 12.3 NOC: Alt sınıf sayısı

Number of Children (NOC), sınıftan doğrudan türetilmiş alt sınıfların sayısıdır. Bir sınıfın çok fazla alt sınıfı varsa bu, kalıtımın yanlış kullanıldığının bir göstergesi olabilir. Alt sınıf sayısı, sınıfın tasarımdaki potansiyel etkisi hakkında fikir verir. Çok alt sınıfı olan sınıfların metotları daha çok test gerektirdiği için bu metrik, sınıfı test etmek için harcanacak bütçe hakkında da bilgi verir.

### 12.4 CBO: Nesne sınıfları arasındaki bağımlılık

Coupling Between Object Classes (CBO), sınıfın bağımlı olduğu sınıf sayısıdır. Bir sınıfın nitelikleri (attribute) ya da metotları diğer sınıfta kullanılıyorsa ve iki sınıf arasında kalıtım yoksa, bu iki sınıf arasında bağımlılık olduğu kabul edilir. Hoca, tasarımda bağımlılık (coupling) ve uyumun (cohesion) önemli olduğunu, modüller arası aşırı bağımlılığın tasarıma zarar verdiğini hatırlattı. Sınıflar arasındaki aşırı bağımlılık modüler tasarıma zarar verir ve tekrar kullanılabilirliği azaltır; bir sınıf ne kadar bağımsızsa başka uygulamalarda o kadar kolay yeniden kullanılabilir. Bağımlılıktaki artış değişime duyarlılığı da artırdığından bakım zorlaşır. Bağımlılık, tasarımın farklı parçalarının ne kadar karmaşık test edileceği hakkında da fikir verir: bağımlılık fazlaysa testlerin daha özenli yapılması gerekir ve test maliyeti artar. Hoca, bir miktar bağımlılığın kaçınılmaz olduğunu ama fazlasının kaliteye zarar verdiğini söyledi.

### 12.5 RFC: Sınıfın tetiklediği metot sayısı

Response For a Class (RFC), verilen sınıftan bir nesnenin metotları çağrıldığında bu nesnenin tetikleyebileceği tüm metotların sayısıdır. Bu metrik sınıfın test maliyeti hakkında da fikir verir. Bir mesajın çok sayıda metodun çağrılmasını tetiklemesi, sınıfın testinin ve hata ayıklamasının zorlaşması demektir. Bir sınıftan fazla sayıda metodun çağrılması sınıfın karmaşıklığının yüksek olduğunun işaretidir.

### 12.6 LCOM: Metotların uyumluluğu

Lack of Cohesion in Methods (LCOM), sınıf içindeki uyumun (cohesion) eksikliğini ölçer. Bu metriğin birden çok tanımı vardır. Chidamber ve Kemerer ilk olarak şu tanımı yapmıştır: $C_1$ sınıfının $M_1, M_2, \dots, M_n$ metotları olsun ve $\{I_i\}$, $M_i$ metodunda kullanılan nitelik değişkenleri kümesi olsun. LCOM, bu $n$ kümenin kesişiminden oluşan ayrık kümelerin sayısıdır.

Daha sonra tanım şöyle yenilenmiştir: $P$ hiçbir ortak nitelik değişkeni paylaşmayan metot çiftlerinin kümesi, $Q$ en az bir ortak nitelik değişkeni paylaşan metot çiftlerinin kümesi olsun. Bu durumda

$$\mathrm{LCOM} = \begin{cases} |P| - |Q| & |P| > |Q| \text{ ise} \\ 0 & \text{aksi durumda} \end{cases}$$

olur (ekrandan, 01:40:00). Hoca, tanım üzerinde sonradan değişiklikler yapıldığını ama temel tanımı bilmenin yeterli olduğunu söyledi.

### 12.7 Metrik kümesi olarak ölçüm

Hoca, nesneye yönelik bir yazılımda ölçüm yapılacaksa bunun tek bir değerle değil bir set olarak yapılması gerektiğini vurguladı. Sınıfın ağırlıklı metot sayısı, kalıtım ağacının derinliği, alt sınıf sayısı, sınıflar arası bağımlılık, sınıfın tetiklediği metot sayısı ve metotların uyumluluğu ölçülebilir büyüklüklerdir ve yazılımın niteliği ile karmaşıklığı hakkında fikir verir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:15:56): Bütünlük testinde artırmalı sınama yapılırken modüllerin hangi sırayla ve hangi hiyerarşiyle birleştirileceği planlanır. Bu plan için yazılım geliştirme sürecinin hangi adımından ve hangi belgeden yararlanılır?

> **Cevap (derste verildi):** Yüksek düzey (genel) tasarım adımından ve yazılım tasarım spesifikasyonundan (SDS) yararlanılır: yapı diyagramı ya da sınıf diyagramı mimari yapıyı verir. Gereksinim belgesi sistem ve kullanıcı testinde, alçak düzey tasarım bileşen testinde kullanılır.

**Soru 2** (derste sözlü, 00:30:58): Kara kutu testi nedir, saydam kutu testi nedir?

> **Cevap (derste verildi):** Kara kutu testi sistemin dış spesifikasyonlarına ve gereksinimlerine dayanır, iç yapıya bakmaz. Saydam kutu testi modül düzeyinde programın deyimlerini ve dallarını sınayarak iç yapıyı (algoritmayı) inceler. İkisi birlikte kullanılır.

**Soru 3** (ekrandan, 01:10:00; derste sözlü, 01:08:22): Ortalama alma yöntemine ait akış grafında (13 düğüm; kenarlar Bölüm 9.3'teki listede) kaç farklı temel yol vardır? Saydam kutu testinde kaç test case hazırlanmalıdır?

> **Cevap (derste verildi):** Bölgeler sayılır: en dıştaki R1 ve graf içindeki bölgelerle birlikte R1-R6, yani 6 bölge. Döngüsel karmaşıklık 6'dır; 6 temel yol ve 6 test case gerekir. Formülle $V(G) = E - N + 2 = 17 - 13 + 2 = 6$ (python ile kontrol edildi; hocanın sözlü formülündeki "artı bir" için Bölüm 9.3'teki ders sonrası nota bakın).

**Soru 4** (derste sözlü, 01:19:07): Geliştirdiğiniz bir yazılımın büyüklüğünü nasıl ölçersiniz?

> **Cevap (derste verildi):** İki yaygın yol vardır: fonksiyon noktası (dolaylı ölçüm) ve kod satır sayısı, LOC ya da KLOC (doğrudan ölçüm).

**Soru 5** (derste sözlü, 01:21:49): Fonksiyon noktası hesaplanırken tek bir değer mi ölçülür? Neler sayılır?

> **Cevap (derste verildi):** Tek bir değer ölçülmez; beş farklı şey sayılır: girdi, çıktı, ara birim, sorgu ve dosya sayısı. Bunlar ağırlık faktörleriyle birleştirilir; en büyük ağırlık dosya sayısındadır. Bu yüzden dolaylı bir ölçümdür.

**Soru 6** (derste sözlü, 01:23:44): Doğrudan sayarak yazılımın büyüklüğü hakkında yaklaşık bir fikir veren ölçüt hangisidir?

> **Cevap (derste verildi):** Kod satır sayısı (LOC); büyük programlarda bin satır birimiyle KLOC. Dile ve ortama bağlı olduğu için objektif değildir, ama basitliği nedeniyle yaygındır.

**Soru 7** (derste sözlü, 01:49:15): Bir yazılım için döngüsel karmaşıklık (cyclomatic complexity) nasıl hesaplanır, nerede kullanılır ve ne işe yarar?

> **Çözüm (derste verilmedi):** Ayrıntılı tasarımdan ya da kaynak koddan akış grafı çizilir (kontrol deyimleri ve döngüler ayrı düğüm, ardışık komutlar tek düğüm). Döngüsel karmaşıklık, graftaki bölge sayısı (dış bölge dahil) ya da $V(G) = E - N + 2$ ile bulunur. Tasarımda modül büyüklüğünü sınırlamak için ($V(G) \le 10$; aşarsa modül bölünür), birim testte ise saydam kutu temel yol testinde kullanılır: değer, bağımsız temel yol sayısını ve dolayısıyla hazırlanması gereken test case sayısını verir. Cevap dersin 9. bölümündeki anlatımdan derlenmiştir.

## Dersin Toparlaması

Dersin ilk yarısında test süreci V model üzerinden yeniden kuruldu: birim testte test sürücü, koçan ve test senaryosu; bütünlük testinde yüksek düzey tasarımdan gelen birleştirme planı ve artırmalı sınama; ardından regresyon, sistem (güvenlik, dayanıklılık, performans) ve kabul testleri. Test tiplerinde saydam kutu tarafında temel yol ve döngü testi, kara kutu tarafında eşdeğer bölümleme ve sınır değer analizi hatırlatıldı; hata düzeyleri ölümcülden görünüm hatasına kadar sıralandı.

İkinci yarıda yazılım ölçümüne geçildi. Ölçemediğimiz şeyi kontrol edemeyeceğimiz fikrinden yola çıkılarak yöneticilerin ve mühendislerin ölçüm gereksinimleri ayrıldı. Ardından başlıca ölçütler görüldü: aritmetiksel karmaşıklık için Halstead, kontrol akışı karmaşıklığı için McCabe (temel yol testinde test case sayısını ve tasarımda modül büyüklüğü sınırını veren döngüsel karmaşıklık), istatistiki güvenirlik modelleri, büyüklük için fonksiyon noktası ve LOC, nesneye yönelik yazılımlar için de CK metrik kümesi. Ortak fikir, tanımsal bir ürün olan yazılımı sayısal hâle getirerek kalite hakkında karar verebilmektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
