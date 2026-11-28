# Ders 10 Çalışma Özeti

## Genel Konular

- Yazılım kalitesi ve kalite bakış açısı
  - Yazılım mühendisliğinin katmanlı yapısı alttan üste: **kalite bakış açısı**, **süreçler**, **yöntemler**, **yazılım araçları** (ekrandan, 00:10:00). Kaliteli yazılım için formal bir süreç tanımı, o sürece uygun bir yöntem ve bunları destekleyen bir yazılım aracı gerekir.
  - Mühendislik yaklaşımının iki temel öğesi **ölçme** ve **tasarım**dır. Yazılım ölçümü (*software metrics*) hem proje yönetiminin hem kalite yönetiminin alt başlığıdır.
  - **CASE** (*Computer Aided Software Engineering*): yazılım geliştirme sürecinde çalışanlara destek olan yazılım aracı. Yalnız diyagram çizimini destekleyen küçük araçlar da olabilir, proje planından teste kadar bütün süreci destekleyen **bütünleşik CASE araçları** da (örnek: IBM'in satın aldığı Rational Rose platformu).
- Yazılım kalite faktörleri ve McCall modeli
  - McCall kalite üçgeni üç bakış açısı tanımlar (ekrandan, 00:15:00):
    - **Ürün kullanımı** (kullanıcı için): doğruluk, güvenirlik, kullanışlılık, bütünlük, etkinlik.
    - **Ürün değişikliği** (bakım yapan için): bakım yapılabilirlik, esneklik, test edilebilirlik.
    - **Ürün geçişi** (taşıyan/çalıştıran için): taşınabilirlik, yeniden kullanılabilirlik, birlikte çalışabilirlik.
  - Tanımlar: doğruluk (*correctness*) spesifikasyona uygunluk ve müşteri isteklerini karşılama derecesi; güvenirlik (*reliability*) işlevleri istenen duyarlılıkta, ne kadar hatasız yerine getirdiği; güvenlik/bütünlük (*security, integrity*) yetkisiz erişimi engelleme; kullanışlılık (*usability*) öğrenme, çalıştırma, girdi hazırlama ve çıktı yorumlama kolaylığı; taşınabilirlik (*portability*) farklı donanım ve işletim sistemlerinde çalışma; yeniden kullanılabilirlik (*reusability*); birlikte çalışabilirlik (*interoperability*) diğer sistemlerle veri alışverişi.
  - McCall modelinde kalite faktörleri ($F_i$) doğrudan ölçülemez; ölçütlere ($m_i$) bağlı doğrusal regresyon denklemi ile ya da faktör analizi (diskriminant fonksiyonu) ile kestirilir (ekrandan, 00:20:00):
    - $F_i = c_1 m_1 + c_2 m_2 + c_3 m_3$
  - Örnek eşleşmeler: doğruluk ↔ izlenebilirlik, tamlık, uyumluluk; güvenirlik ↔ uyumluluk, hata toleransı; etkinlik ↔ çalışma etkinliği, bellek etkinliği; bütünlük ↔ erişim kontrolü, erişim denetimi. <!-- BELİRSİZ: Eşleşme diyagramının tamamı karede okunamadı; yalnız anlatılan eşleşmeler yazıldı. -->
- Kaliteyi sağlama aktiviteleri
  - Standartların kullanımı, doğrulama ve geçerleme, gözden geçirme ve denetim (*review, audit, inspection*), test, hata/kusur analizi, değişim (konfigürasyon) yönetimi, risk yönetimi, kullanıcı eğitimi.
  - Süreç ilerledikçe hatayı bulma olasılığı düşer, bulma ve düzeltme gideri artar; bu yüzden hata bulma sürecin başına çekilmeli, her ara ürün (*artifact*) gözden geçirilmelidir.
  - Hata önleme maliyeti: kalite planlama, formal ve teknik gözden geçirme, test oluşturma, eğitim. **İç hata maliyeti** yazılım kullanıma alınmadan önce, **dış hata maliyeti** kullanıma alındıktan sonra ortaya çıkan hatanın düzeltme maliyetidir (ekrandan, 00:25:00).
  - Yazılım mühendisliği standartları (ör. IEEE): gereksinim analizi (SRS) raporu, tasarım, güvenlik, geçerleme, konfigürasyon yönetimi, kalite güvencesi standartları.
- Doğrulama ve geçerleme, V model
  - **Doğrulama (*verification*)**: ürünü doğru yolla mı geliştiriyoruz? **Geçerleme (*validation*)**: doğru ürünü, yani kullanıcının istediği ürünü mü ürettik?
  - V modelde geliştirme adımları sol kolda, test adımları sağ kolda karşılıklıdır (ekrandan, 00:35:00): müşteri gereksinimleri ↔ işlemsel kullanım (kullanıcı testi), ürün spesifikasyonu ↔ sistem testi, yüksek düzey (mimari) tasarım ↔ bütünlük testi, alçak düzey (ayrıntılı) tasarım ↔ bileşen testi, en altta kodlama ve birim test.
- Test adımları (test stratejisi)
  - **Birim test**: tasarımın en küçük birimi olan modül üzerinde, ayrıntılı tasarıma dayanarak, saydam kutu testi olarak, kodu geliştiren kişi tarafından yapılır.
  - **Test sürücü (*driver*)**: test verisini alıp test edilen modüle ileten ve sonucu yazan ara program. **Koçan (*stub*)**: test edilen modülün çağırdığı, henüz hazır olmayan alt programı temsil eden kukla (*dummy*) program.
  - **Bütünleme (bütünlük) testi**: tek tek doğru çalışan modüllerin ara birimler üzerinden birlikte doğru çalışıp çalışmadığını sınar. Bütün olarak ya da artırmalı (yukarıdan aşağı / aşağıdan yukarı) yapılabilir.
  - **Regresyon testi**: alttaki modüllerde değişiklik yapıldıktan sonra testlerin tekrarlanması.
  - **Sistem testi**: yazılımın işletim sistemi, VTYS ve diğer yazılımlarla birlikte denenmesi: güvenlik testi, dayanıklılık (stres) testi, yetenek (performans) testi (ekrandan, 00:45:00).
  - **Onaylama (kabul, kullanıcı) testi**: yazılımın müşteri ve kullanıcı beklentilerini ne kadar karşıladığını ortaya koyar.
- JUnit ile birim test
  - Birim sınama, en küçük yazılım bileşeninin, NYP'de bireysel sınıfların sınanmasıdır; kodlamadan önce (TDD), kodlama sırasında ya da sonra tasarlanabilir. Gereken diğer sınıfların yerine vekil kod (*stub, dummy, surrogate, proxy*) kullanılır (ekrandan, 01:05:00).
  - JUnit, Java için birim test çerçevesidir; C# için csUnit gibi başka dillerde karşılıkları vardır. Eclipse ve NetBeans'te hazır gelir.
  - Her sınıf için ayrı test sınıfı, `setUp()` her testten önce yeniden çalışır, testler `TestAll` içindeki statik `suite()` metodunda toplanır. JUnit 4 ile test sınıfının `TestCase`'ten türetilmesi ve metot adlarının `test` ile başlaması zorunlu olmaktan çıkar, `@Test` ek açıklaması yeterlidir; istisnaların atılıp atılmadığı da sınanabilir.
  - Örnek: video kiralama (`Customer`, `Rental`, `Movie`) uygulaması için `TestCustomer` sınıfı (ekrandan, 01:15:00).
- Yazılım proje yönetimi
  - Proje yöneticisi proje yönetimi bilgi ve deneyimi, genel yönetim bilimi ve yazılım mühendisliği tekniklerinin kesişimine sahip olmalıdır.
  - Etkin proje yönetiminin üç öğesi: **insan kaynakları**, **problemler**, **süreç** (ekrandan, 01:35:00).
  - Yazılım geliştirmenin esas adımları (analiz, tasarım, geliştirme, test, bakım) ve bunları destekleyen aktiviteler (proje planlama, risk yönetimi, konfigürasyon yönetimi, yazılım ölçümü).
- Yazılım ölçümü
  - **Doğrudan ölçüm**: gider, süre, komut satırı, hız, bellek, hata miktarı. **Dolaylı ölçüm**: birden fazla değere bağlı büyüklük ve karmaşıklık ölçüsü.
  - **LOC/KLOC**: kod satırı sayısı; verimlilik, kalite, gider ve belgeleme bununla ilişkilendirilir.
  - **İşlev noktası (*function point*, FP)**: girdi, çıktı, sorgulama, kütük (dosya/tablo) ve dış arabirim sayıları ağırlıklarla çarpılıp toplanır, 14 sorunun cevaplarıyla düzeltilir (ekrandan, 01:45:00):
    - $FP = \text{Sayı toplamı} \times (0.65 + 0.01 \sum_{i=1}^{14} F_i)$, $F_i \in \{0,\dots,5\}$
  - LOC ve FP ölçeklerinin kıyaslaması (ekrandan, 01:50:00).
  - Maliyet tahmin yöntemleri: uzman görüşü/Delphi, analiz yöntemi, istatistik modeller (ayrıntısı sonraki derse bırakıldı).
- Yazılım risk yönetimi
  - Risk gelecek, değişim ve seçimle ilgilidir; yazılım risklerinin iki genel özelliği **belirsizlik** ve **kayıp**tır (ekrandan, 02:00:00).
  - Risk kategorileri: ürün büyüklüğü, işletmecilik, müşteriyle ilişkili, süreç, teknoloji (teknik), geliştirme ortamı, personel riskleri.
  - Risk tablosu: risk, kategori, olasılık, etki ve olasılık × etkiden çıkan önem derecesi (yüksek/orta/düşük). Yalnız önem derecesi yüksek (kritik projelerde yüksek ve orta) olanlar izlenir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Doğrulama ve geçerleme Türkçede karışır, İngilizcesiyle düşünülmelidir
  - Slayttaki V modelde iki terim yer değiştirmiş yazılmıştı; hoca ders sırasında düzeltti. Verification sürecin (gidilen yolun) doğruluğu, validation ürünün kullanıcının istediği ürün olmasıdır.
- Hatayı erken bulmak
  - Hata ne kadar geç bulunursa düzeltme gideri o kadar artar; ürün başka firmalarca kullanıma alındıktan sonra çıkan hata yalnız düzeltme maliyeti değil güven kaybı da getirir. Bu yüzden her adım geçişinde gözden geçirme ve denetim şarttır.
- Birim testi kodu yazan yapar
  - V modelde "Kodlama & Birim Test" aynı kutudadır; kodlamayı yapan kişi birim testini de gerçekleştirir. Sonraki testler giderek test ekibine ve test uzmanlarına geçer; kullanıcı testi uygulama alanını bilen, dikkatli test uzmanlarınca yapılır.
- Birim test aracı dile bağlıdır
  - Java için JUnit, C# için başka bir araç kullanılır; birim test aracı kodlama dili ya da ortamına uygun seçilmelidir. JUnit önce küçük bir program parçası üzerinde denenmelidir.
- Bütün riskler izlenmez
  - Bütün riskleri sürekli izlemek proje maliyetini artırır; önem derecesine göre izlenecekler seçilir.
- Proje planının öğeleri
  - Bir proje planında zaman planı, kaynak planı ve risk tablosu bulunmalıdır.

## Kısa Tekrar Notları

- Katmanlar: kalite bakış açısı → süreçler → yöntemler → yazılım araçları.
- McCall üçgeni: ürün kullanımı (doğruluk, güvenirlik, kullanışlılık, bütünlük, etkinlik), ürün değişikliği (bakım yapılabilirlik, esneklik, test edilebilirlik), ürün geçişi (taşınabilirlik, yeniden kullanılabilirlik, birlikte çalışabilirlik).
- $F_i = c_1 m_1 + c_2 m_2 + c_3 m_3$: kalite faktörü ölçütlerin doğrusal birleşimi olarak kestirilir.
- İç hata maliyeti: kullanıma almadan önce; dış hata maliyeti: kullanıma aldıktan sonra.
- Verification: "ürünü doğru mu yapıyoruz?"; validation: "doğru ürünü mü yapıyoruz?".
- Test sırası: birim → (bileşen) → bütünlük → sistem → kullanıcı (kabul).
- Driver test verisini modüle iletir; stub (koçan) çağrılan alt modülün yerini tutar.
- Regresyon testi: değişiklikten sonra testlerin tekrarı.
- Sistem testi: güvenlik, stres, performans.
- JUnit: `setUp()` her testten önce; `TestAll.suite()` testleri toplar; JUnit 4'te `@Test`.
- FP ağırlıkları (basit/orta/karmaşık): girdi 3/4/6, çıktı 4/5/7, sorgulama 3/4/6, kütük 7/10/15, dış arabirim 5/7/10.
- Örnek: orta karmaşıklıkta 15 kütük → $15 \times 10 = 150$.
- $FP = \text{Sayı toplamı} \times (0.65 + 0.01 \sum F_i)$, 14 soru, her biri 0-5.
- LOC dile bağlı, FP dilden bağımsız ama öznel ve veri toplaması güç.
- Risk = belirsizlik + kayıp; önem derecesi = olasılık × etki.

## Detaylı Açıklamalar

- **Kalite bakış açısı ve CASE.** Yazılım mühendisliği, yazılım geliştirmeyi mühendislik temellerine uygun yürütmeyi amaçlar. Kaliteli yazılımın nasıl tanımlanacağı kalite yönetiminin, en ekonomik nasıl elde edileceği proje yönetiminin konusudur. Mühendislik yaklaşımının iki öğesi olan ölçme ve tasarımdan tasarım, gereksinim analizi ve tasarım konularında; ölçme ise yazılım ölçütleri (metrikler) başlığında ele alınır. Katmanlı yapıda en altta kalite bakış açısı, üstünde süreçler, yöntemler ve en üstte araçlar vardır. Araç katmanı CASE ile karşılanır: CASE araçları diyagram çizimini kolaylaştırıp standartlaştırır, analizden tasarıma geçişte kontrol sağlar; bütünleşik olanları proje planından teste kadar bütün süreci destekler.

- **Kalite faktörlerinin ölçülmesi.** McCall modeli kalite özelliklerini kullanıcı, bakımcı ve taşıyıcı bakış açılarına göre üçe ayırır ve her faktörü daha sayısal ölçütlerle ilişkilendirir. Örneğin güvenirlik, hata toleransıyla ilişkilidir: belirli bir çalışma süresinde kaç hata çıktığı ve bunların ne kadarının düzeltilebildiği gibi istatistiksel modellere dayanır. Faktör, ölçütlerin farklı katsayılarla ağırlıklı toplamı olarak ($F_i = c_1 m_1 + c_2 m_2 + c_3 m_3$) ya da diskriminant fonksiyonuyla kestirilir (ekrandan, 00:20:00).

- **Hata maliyeti.** Süreç ilerledikçe hata bulma olasılığı düşerken düzeltme gideri artar. Slayt küçük resminde yazılım hatalarını düzeltme maliyetinin gereksinim analizinde 0,2, tasarımda 0,5, birim testte 2, kabul testinde 5, bakım sürecinde 20 birim olduğu yazmaktadır (ekrandan, 00:25:00). <!-- BELİRSİZ: Bu değerler slayt küçük resminden okundu, derste sözlü anlatılmadı. --> Bu yüzden hata önleme (kalite planlama, gözden geçirme, test oluşturma, eğitim) yatırımı yapılır ve hatalar iç hata maliyeti aşamasında yakalanmaya çalışılır.

- **V model.** Sol kolda müşteri gereksinimleri, ürün spesifikasyonu, yüksek düzey tasarım (genel/mimari tasarım), alçak düzey tasarım (algoritmalar, veritabanı tasarımı gibi ayrıntılı tasarım) ve en altta kodlama ile birim test vardır. Sağ kolda bileşen testi, bütünlük testi, sistem testi ve işlemsel kullanım (kullanıcı testi) yer alır. Kullanıcı testi müşteri gereksinimlerinin, sistem testi spesifikasyondaki (özellikle işlevsel olmayan) gereksinimlerin, bütünlük testi mimari tasarımın, bileşen testi ayrıntılı tasarımın karşılanıp karşılanmadığını sınar. Düzeltilmiş slaytta üst eşleşme "Geçerleme", spesifikasyon-sistem testi "Geçerleme/Doğrulama", alt iki eşleşme "Doğrulama" olarak etiketlidir (ekrandan, 00:35:00).

- **Birim ve bütünleme testi.** Birim test modül içindeki önemli kontrol yollarını saydam kutu yaklaşımıyla sınar ve birçok modülde paralel yürütülebilir. Test edilen modül başka bir modül tarafından çağrılıyorsa bu çağıranın yerini test sürücü tutar; çağırdığı alt modüller henüz hazır değilse koçanlar kullanılır. Bütünleme testinde modüller birleştirilirken veri kaybı, birbirini ters etkileme, alt fonksiyonların birleşince beklenen ana fonksiyonu vermemesi ve hata toleranslarının birikerek büyümesi gibi sorunlar ortaya çıkabilir (ekrandan, 00:40:00). Artırmalı bütünlemede yukarıdan aşağı ya da aşağıdan yukarı ilerlenir; alt modüllerde değişiklik olduğunda regresyon testi yapılır.
  - **Ders sonrası not:** Hoca yukarıdan aşağı bütünlemede alt modüllerin koçan olarak görüldüğünü söyledikten sonra test sürücüsünden ve önce test edilen alt modüllerin bir blok halinde üst modüle aktarılmasından da söz etti. Büyük olasılıkla standart ayrım şöyledir: yukarıdan aşağı bütünlemede eksik alt modüller için **koçan**, aşağıdan yukarı bütünlemede alt modül kümeleri için **test sürücü** kullanılır; blok oluşturup üste aktarma aşağıdan yukarı yaklaşımın özelliğidir.

- **JUnit örneği.** Video kiralama örneğinde müşteri, kiralama ve film sınıfları vardır; sıralama diyagramında her kiralama için ücret hesaplanır ve döngüde biriktirilir. `TestCustomer` sınıfı `setUp()` içinde bir müşteri ve dört film (farklı fiyat kodlarıyla) oluşturur, `testGetName()` müşteri adını, `testStatementWhenEmpty()` hiç kiralama yokken üretilen hesap dökümünü `assertEquals` ile karşılaştırır (ekrandan, 01:15:00). `Movie` sınıfında fiyat kodları `CHILDRENS = 2`, `REGULAR = 0`, `NEW_RELEASE = 1` sabitleridir (ekrandan, 01:20:00). Testler bir test suite'te toplanır ve `TestAll` çalıştırılarak hepsinin sonucu görülür.

- **İşlev noktası hesabı.** Her parametre (girdi, çıktı, sorgulama, kütük, dış arabirim) için sayı belirlenir, karmaşıklığa göre basit/orta/karmaşık ağırlığı seçilir ve çarpılır; satırların toplamı "sayı toplamı"dır. Ağırlığı en yüksek olan kütük (dosya/tablo) sayısıdır. Hocanın örneğinde orta karmaşıklıkta 15 dosya için FP sütununa $15 \times 10 = 150$ yazılır. Sonra 14 soru (ör. güvenli yedekleme ve geri yükleme gerekli mi, dağıtılmış fonksiyon var mı, uzaktan erişim var mı) 0-5 arası puanlanır; örnekte toplam $\sum F_i = 32$ bulunmuştur. Bu durumda düzeltme çarpanı $0.65 + 0.01 \times 32 = 0.97$ olur (ara adım eklendi). FP programlama dilinden bağımsızdır, ancak öznel, doğrudan fiziksel ölçüt değildir ve verisini toplamak güçtür; LOC ise dile (kısmen) bağlıdır, iyi tasarlanmış kısa yazılımları yeterince değerlendiremez ve işlemsel olmayan dillere kolay uyarlanamaz (ekrandan, 01:50:00).

- **Risk yönetimi.** Risk, şu an sorun olmayan durumların gelecekteki değişimler (teknoloji, bilgisayarlar, projeye bağlı varlıklar) ve yapılan seçimler (yöntem, araç, çalışan sayısı, önem verilen kalite ölçütleri) yüzünden soruna dönüşmesidir. Müşteriyle ilişkili riskler (müşteri daha önce çalışılmış mı, neye ihtiyaç duyduğunu biliyor mu, gözden geçirmelere katılacak mı), süreç riskleri (süreç ekipçe anlaşıldı mı, standartlar biliniyor mu, konfigürasyon yönetimi yapılıyor mu), teknik riskler (kod belgeleniyor mu, tasarım yöntemi var mı, CASE aracı ilk kez mi kullanılıyor) ve personel riski (insanlar yeteneklerine göre kullanılıyor mu, yeterli çalışan var mı, tam ya da yarı zamanlı mı, gerekli eğitimi aldı mı) soru listeleriyle belirlenir (ekrandan, 02:05:00). Risk tablosunda olasılık ve etki çarpılarak önem derecesi bulunur; riskler olasılık ve etkisi azaltılarak ortadan kaldırılır. Örneğin iki ay süre verilen bir donanım siparişinde sürenin bitmesine bir ay kala satış sorumlusu iş programını hatırlatır; proje yöneticisi her şeyden önceden haberdar olacak biçimde çalışmalıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
