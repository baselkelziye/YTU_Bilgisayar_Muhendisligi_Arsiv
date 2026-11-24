# Ders 2 Çalışma Özeti

## Genel Konular

- Dersin kapsamı ve müfredatı (ekrandan, 00:20:00)
  - Ders, lisans düzeyindeki bilgisayar ve ağ güvenliği dersinin devamı olarak kurgulanmıştır. Temel kitap: William Stallings ve Lawrie Brown, *Computer Security: Principles and Practice*, 4. baskı (2018).
  - Müfredat dört ana bölümden oluşur:
    - Genel bakış.
    - Yönetim sorunları: BT güvenlik yönetimi ve risk değerlendirmesi; BT güvenlik kontrolleri, planları ve prosedürleri; fiziksel ve altyapı güvenliği; insan kaynakları güvenliği; güvenlik denetimi; bilişim güvenliğinde yasal ve etik hususlar.
    - Şifreleme algoritmaları: şifreleme araçları; simetrik şifreleme ve mesaj gizliliği; açık anahtarlı şifreleme ve ileti kimlik doğrulaması.
    - Ağ güvenliği: internet güvenlik protokolleri ve standartları; internet kimlik doğrulama uygulamaları (Kerberos vb.); kablosuz ağ güvenliği.
  - Önceden bilinmesi beklenen konular: simetrik ve asimetrik şifreleme, kimlik doğrulama, erişim kontrolü, veri tabanı ve veri merkezi güvenliği, kötü amaçlı yazılımlar (virüs, solucan, truva atı ve aralarındaki farklar), hizmet reddi (DoS) ve tampon taşması saldırıları, güvenlik duvarı, IDS ve IPS'in çalışma mantığı.
- Temel güvenlik kavramları: CIA üçlüsü ve güvenlik beşgeni (ekrandan, 00:25:00)
  - Korunan varlık "veri ve servisler"dir (Data and services). Etrafında beş hedef vardır: Confidentiality, Integrity, Availability, Authenticity, Accountability.
  - Gizlilik (veri gizliliği, mahremiyet), bütünlük (veri bütünlüğü, sistem bütünlüğü) ve kullanılabilirlik birlikte CIA üçlüsü olarak adlandırılır ve temel güvenlik bileşenleridir.
  - Özgünlük: hakiki olma, doğrulanabilme ve güvenilir olma özelliği.
  - Hesap verebilirlik: bir varlığın eylemlerinin o varlığa benzersiz olarak izlenebilmesi gereksinimi.
- Kavramların tanımları (FIPS 199 temelli)
  - Gizlilik: kişisel gizliliğin ve özel bilgilerin korunması dahil, bilgiye erişim ve bilginin ifşasına ilişkin yetki kısıtlamalarının korunması.
  - Bütünlük: reddedilmezlik ve özgünlük dahil, uygunsuz bilgi değişikliğine ya da yok edilmesine karşı korunma.
  - Kullanılabilirlik: bilgiye zamanında ve güvenilir erişim, bilginin zamanında ve güvenilir kullanımı.
  - Özgünlük: kullanıcıların söyledikleri kişi olduklarını ve sisteme gelen her girdinin güvenilir bir kaynaktan geldiğini doğrulamak (ekrandan, 00:30:00).
  - Hesap verebilirlik: inkar etmeme, caydırıcılık, hata izolasyonu, izinsiz giriş tespiti ve önleme, eylem sonrası kurtarma ve yasal işlemi destekleme (ekrandan, 00:30:00).
- Etki (zarar) düzeyleri: düşük, orta, yüksek
  - Düşük: kaybın organizasyonel operasyonlar, varlıklar ya da bireyler üzerinde sınırlı olumsuz etkisi olur.
  - Orta: ciddi olumsuz etki.
  - Yüksek: ölümcül, geri dönülemez (felaket boyutunda) etki.
  - Web sitesi örneği: anket verileri ya da hayati olmayan kullanıcı verileri düşük; ad, adres, sepet içeriği orta; hesap ve ödeme bilgileri ya da çok gizli bilgiler yüksek etki düzeyidir.
- Bilgisayar güvenliğinin zorlukları (ekrandan, 00:35:00)
  - Slaytta on madde vardır: güvenlik ilk bakışta göründüğü kadar basit değildir; olası saldırılar baştan düşünülmelidir; prosedürler çoğu zaman mantık dışı görünür; fiziksel ve mantıksal yerleşim belirlenmelidir; mekanizmalar algoritmadan fazlasını ve gizli bilgilerin yönetimini içerir; saldırgana tek zayıf nokta yeter, tasarımcı hepsini kapatmalıdır; güvenlik çoğu zaman tasarımdan sonra düşünülür; düzenli ve sürekli izleme gerekir; yatırımın fayda sağlamadığı algısı vardır; güçlü güvenlik verimliliğe engel olarak görülür.
- Bilgisayar güvenliği terminolojisi, RFC 2828 İnternet Güvenliği Sözlüğü, Mayıs 2000 (ekrandan, 00:40:00)
  - Adversary (tehdit ajanı), attack (saldırı), countermeasure (karşı önlem), risk, security policy (güvenlik politikası), system resource / asset (varlık), threat (tehdit), vulnerability (güvenlik açığı).
- Güvenlik kavramları arasındaki ilişki
  - Varlık sahibi varlığa değer verir, riski azaltmak için karşı önlem alır. Saldırgan varlığı ele geçirmek, bozmak ya da kötüye kullanmak ister ve tehdit oluşturur. Tehdit riski artırır; sahibi yeni önlemler alır. Döngü sürer, bir zayıflık bulunursa saldırgan amacına ulaşır.
- Varlık türleri: donanım, yazılım, veri, iletişim hatları ve ağlar
- Güvenlik açıkları, tehditler ve saldırılar (ekrandan, 00:45:00)
  - Açık kategorileri: bozuk (bütünlük kaybı), sızdıran (gizlilik kaybı), kullanılamaz ya da çok yavaş (kullanılabilirlik kaybı).
  - Tehdit: güvenlik açıklarından yararlanma yeteneği; varlığa yönelik olası güvenlik zararı.
  - Saldırı (gerçekleştirilen tehdit): pasif ya da aktif; kökenine göre insider ya da outsider.
  - Karşı önlemin amacı önleme, tespit ve kurtarmadır. Önlemin kendisi de yeni açık getirebilir; amaç artık riski en aza indirmektir.
- Tehdit sonuçları ve tehdit eylemleri, RFC 4949 (ekrandan, 00:50:00)
  - Yetkisiz açıklama: maruziyet, müdahale, çıkarım, izinsiz giriş.
  - Aldatma: maskeli, tahrif, reddetme.
  - Bozulma: aciz bırakma, yolsuzluk, engel.
  - Gasp: zimmete para geçirme, yanlış kullanım.
- Varlıklara göre CIA tehditleri (donanım, yazılım, veri, iletişim hatları)
- Pasif ve aktif saldırılar (ekrandan, 00:55:00)
  - Pasif: dinleme ve izleme; iki tip: mesaj içeriğinin serbest bırakılması ve trafik analizi.
  - Aktif: dört kategori: tekrar oynatma, maskeli saldırı, mesajların değiştirilmesi, hizmet reddi.
- Güvenlik gereksinimleri (FIPS 200) (ekrandan, 01:00:00)
- Temel güvenlik tasarım ilkeleri
- Saldırı yüzeyleri ve derinlemesine savunma (ekrandan, 01:05:00)
- Güvenlik stratejisi (politika, uygulama, güvence, değerlendirme) ve standart kuruluşları (NIST, ISOC, ITU-T, ISO)

## Hocanın Özellikle Vurguladığı Kısımlar

- Güvenlik bir varlık üzerine kuruludur
  - Binanın, bankanın, insanın güvenliği gibi, bilişimde de korunan şey değerli bir varlıktır. Güvenlik, bu varlığa yönelik tehditlerin ve saldırıların karşısında tanımlanır.
- Etkinin bir referansa göre ölçülmesi
  - Mühendis "çok etkiledi" demekle yetinmez; "çok"un referansı tanımlanmalıdır. Bu yüzden etki düşük, orta ve yüksek diye seviyelendirilir.
- Güvenlik tasarımın ayrılmaz parçasıdır
  - Bugün çoğu zaman önce ağ kurulur, program yazılır, sonra güvenliğe dönülür. Hocanın benzetmesi: binayı yapıp sonra depreme dayanıklı mı diye kontrol etmek yerine zeminden itibaren kaliteli malzemeyle yapmak gerekir.
  - Güvenlik anahtar teslim bir iş değildir; kurulmalı, uygulanmalı ve sürekli izlenmelidir.
- İnsan faktörü
  - Sistem ne kadar güvenli kurulursa kurulsun insan zafiyeti sorun çıkarır; güvenlik herkesin katılımını gerektirir.
- Saldırganın tek açığı yeter
  - Saldırgana tek bir zayıf nokta yeter, tasarımcı bütün muhtemel zayıflıkları bulup kapatmak zorundadır.
- Karşı önlem de risk getirir
  - Sisteme eklenen her yazılım ya da donanım kendi zayıflıklarını getirir; amaç artık riski en aza indirmektir.

## Kısa Tekrar Notları

- CIA üçlüsü: gizlilik, bütünlük, kullanılabilirlik. Beşgen için özgünlük ve hesap verebilirlik eklenir.
- Bütünlüğün iki türü: veri bütünlüğü ve sistem bütünlüğü.
- Etki düzeyleri: düşük (sınırlı), orta (ciddi), yüksek (ölümcül/geri dönülemez).
- RFC 2828: İnternet Güvenliği Sözlüğü (Mayıs 2000). RFC 4949: tehdit sonuçları ve eylemleri tablosunun kaynağı.
- Açık kategorileri: bozuk, sızdıran, kullanılamaz.
- Saldırı pasif ya da aktif; insider ya da outsider.
- Karşı önlem: önle, tespit et, kurtar.
- Tehdit sonuçları: yetkisiz açıklama, aldatma, bozulma, gasp.
- Pasif saldırı tipleri: mesaj içeriğinin ifşası, trafik analizi.
- Aktif saldırı kategorileri: tekrar oynatma (replay), maskeli saldırı, mesaj değiştirme, hizmet reddi.
- Saldırı yüzeyi türleri: ağ, yazılım, insan.
- Derin katmanlama ve küçük saldırı yüzeyi düşük risk; sığ katmanlama ve büyük saldırı yüzeyi yüksek risk.
- Güvenlik stratejisinin bileşenleri: politika, uygulama, güvence, değerlendirme.

## Detaylı Açıklamalar

- **Güvenlik beşgeni.** Ekrandaki şekilde ortada "Data and services" yazan beşgen, kenarlarında Confidentiality, Integrity, Authenticity, Availability ve Accountability vardır (ekrandan, 00:25:00). Gizlilik verinin ve kişisel mahremiyetin korunmasıdır. Bütünlük hem verinin hem sistemin beklenmedik biçimde değiştirilmemesidir. Kullanılabilirlik bilgiye ve hizmete zamanında, güvenilir erişimdir. Özgünlük, kullanıcının iddia ettiği kişi olduğunu ve girdilerin güvenilir kaynaktan geldiğini doğrular. Hesap verebilirlik, her eylemin onu yapan varlığa izlenebilmesidir; inkar etmeme, caydırıcılık, hata izolasyonu, izinsiz giriş tespiti ve önleme, olay sonrası kurtarma ve yasal süreci destekleme bu başlık altında değerlendirilir.
- **Etki düzeyleri ve örnek.** Bir güvenlik zafiyetinin etkisi düşük, orta ya da yüksek olarak sınıflandırılır. Hocanın web sitesi örneğinde, hayati olmayan anket verilerinin sızması düşük; kullanıcı adları, adresleri ve sepet içeriklerinin sızması orta; hesap ya da ödeme bilgileri gibi işin kaybedilmesine yol açabilecek verilerin sızması yüksek etki düzeyidir.
- **Zorluklar.** Güvenliğe yapılan yatırım başarılı olduğunda hiçbir olay yaşanmaz ve kaç saldırının önlendiği kaydedilmez; bu yüzden yatırım boşa gitmiş gibi algılanır. Güçlü güvenlik çoğu zaman kullanıcı dostu olmayan, hantal bir yapı olarak görülür. Güvenlik yalnız dijital taraf değildir; fiziksel ve mantıksal yerleşim de güvenliğin parçasıdır.
- **Terminoloji (RFC 2828).** Tehdit ajanı, zararlı faaliyet yürüten ya da yürütme niyetinde olan kişi, grup, kuruluş ya da hükümettir. Saldırı, bilgi sistemi kaynaklarını ya da bilginin kendisini toplamaya, bozmaya, reddetmeye ya da yok etmeye çalışan kötü niyetli faaliyettir. Karşı önlem, casusluk, sabotaj, hırsızlık ya da yetkisiz erişimi önlemeye yönelik cihaz ya da tekniktir. Risk, bir işletmenin olası bir durum ya da olay tarafından ne ölçüde tehdit edildiğinin ölçüsüdür; tipik olarak olay gerçekleşirse doğacak olumsuz etkiye ve gerçekleşme olasılığına bağlıdır. Güvenlik açığı, bir tehdit kaynağının istismar edebileceği bilgi sistemi, prosedür, iç kontrol ya da uygulama zayıflığıdır (ekrandan, 00:40:00).
- **Kavramlar arası döngü.** Varlık sahibi, değer verdiği varlığa yönelik riski azaltmak için önlem alır (ağ için güvenlik duvarı, bina için kamera ve güvenlik görevlisi). Saldırgan varlığı ele geçirmek, bozmak ya da kötüye kullanmak için tehdit oluşturur. Tehdit riski artırır, sahip yeni önlem alır; bir zayıflık kalırsa saldırgan amacına ulaşır.
- **Varlıklar ve CIA tehditleri.**
  - Donanım: kullanılabilirliğe tehdit ekipmanın çalınması ya da devre dışı bırakılması, gizliliğe tehdit içindeki şifrelenmemiş bilginin çalınmasıdır; hocaya göre donanımda bütünlük tehdidinden söz edilmez.
  - Yazılım: programın silinmesi ya da erişimin engellenmesi (kullanılabilirlik), yetkisiz kopyalama (gizlilik), çalışma sırasında başarısız olacak ya da istenmeyen işlev yapacak biçimde değiştirilmesi (bütünlük).
  - Veri: dosyanın silinmesi ya da erişimin engellenmesi (kullanılabilirlik), yetkisiz okunması ya da istatistiksel analizle çıkarım yapılması (gizlilik), mevcut dosyaların değiştirilmesi ya da sahte dosya üretilmesi (bütünlük).
  - İletişim hatları: mesajların silinmesi ya da hattın kullanılamaz hale gelmesi (kullanılabilirlik), mesajların okunması (gizlilik), mesajın değiştirilmesi, geciktirilmesi, yeniden sıralanması, çoğaltılması ya da sahte mesaj üretilmesi (bütünlük).
  - Ders sonrası not: Hoca iletişim hattında gizlilik tehditleri arasında mesajın "düzeninin, sırasının değişmesi"ni de saydı. Kaynak kitapta gizlilik tehdidi büyük olasılıkla "mesaj trafiğinin örüntüsünün gözlenmesi"dir (trafik analizi); sıranın değiştirilmesi bütünlük tehdididir.
- **Güvenlik gereksinimleri (FIPS 200).** Erişim kontrolü, farkındalık ve eğitim, denetim ve hesap verebilirlik, sertifikasyon, akreditasyon ve güvenlik değerlendirmesi, konfigürasyon yönetimi, acil durum planlaması, tanımlama ve doğrulama, olay müdahalesi, bakım, medya koruması, fiziksel ve çevresel koruma, planlama, personel güvenliği, risk değerlendirmesi, sistem ve hizmet alımı, sistem ve iletişim koruması, sistem ve bilgi bütünlüğü (ekrandan, 01:00:00).
- **Tasarım ilkeleri.** Hoca mekanizma ekonomisi, güvenli varsayılanlar (fail-safe defaults), açık tasarım, ayrıcalıkların ayrılması, en az ayrıcalık, en az ortak mekanizma, psikolojik kabul edilebilirlik, izolasyon, modülerlik, katmanlama ve en az şaşırtma ilkelerini saydı. <!-- BELİRSİZ: "ayrıcalıkların ayrılması" altyazıda bozuk ("yetkili kullanıcıların aylıklaştırılması"); ilke adları slaytta görülmedi, altyazıdan çıkarıldı. -->
  - Ders sonrası not: Hoca mekanizma ekonomisini "minimum maliyetle maksimum güvenlik" diye açıkladı. Kaynak kitapta bu ilke büyük olasılıkla güvenlik mekanizmasının tasarımının olabildiğince basit ve küçük tutulması anlamındadır.
- **Saldırı yüzeyi.** Bir sistemdeki erişilebilir ve istismar edilebilir açıkların toplamıdır. Örnekler: dışa açık sunucuların açık portları ve bu portları dinleyen yazılımlar, güvenlik duvarı içinde gereksiz çalışan servisler, gelen veri ve e-postayı işleyen kod, web formları (SQL enjeksiyonu, XSS), sosyal mühendislik ile hassas bilgi isteyen sahte e-postalar. Üç tür vardır: ağ, yazılım ve insan saldırı yüzeyi. Derinlemesine savunma şeklinde (ekrandan, 01:05:00) dikey eksen katmanlama (sığ/derin), yatay eksen saldırı yüzeyidir (küçük/büyük): derin ve küçük düşük risk, sığ ve büyük yüksek risk, diğer iki durum orta risktir.
- **Güvenlik stratejisi ve standartlar.** Güvenlik politikası, kuruluşun kritik kaynaklarını korumak için güvenlik hizmetlerini nasıl sağladığını belirleyen resmi kurallardır. Uygulamanın amacı önleme, tespit, tepki ve kurtarmadır. Güvence, sistemin politikalara uygun çalıştığına duyulan güvenin zeminidir; değerlendirme, ürünü ya da sistemi belirli kriterlere göre inceleme sürecidir. Standart kuruluşları: NIST (ABD, National Institute of Standards and Technology), ISOC (Internet Society), ITU-T (Birleşmiş Milletler'e bağlı telekomünikasyon birliği) ve ISO.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
