# Ders 4 Çalışma Özeti

## Genel Konular

- Dersin tarihi 21 Mart 2023 Salı. Ders Zoom üzerinden yapıldı.
  - Kaydın ilk 5 dakikası bekleme kısmıdır. Ders yaklaşık 00:05:25'te başlar.
- Proje durumu
  - Proje grupları, konular ve temel modüller Cuma günü paylaşıldı. İtiraz gelmediği için liste kesinleşti.
  - Proje beklentileri dokümanı ders duvarında paylaşıldı.
- Bilgi sistemi geliştirme sürecinin üçüncü aşaması: gereksinim analizi
  - İki adımı var: iş analizi (business requirements) ve işlevsel çözümleme.
  - Bu ders iş analizini anlatır. İşlevsel çözümleme ve SRS haftaya kalır.
- Gereksinim analizinin çıktıları
  - Kullanıcının ihtiyaçları, mevcut durumun tespiti, fizibilite önerisinin kesinleşmesi.
  - Gerekirse yeni sistem yerine mevcut sistemin iyileştirilmesi önerilir.
- Gereksinimleri belirlemenin iki yolu
  - Müşteri ne istediğini biliyorsa: iş akış diyagramları.
  - Müşteri tam bilmiyorsa: prototip oluşturup birlikte adım adım geliştirmek.
- SRS (Software/System Requirements Specification) dokümanına giriş.
- İdari incelemede yönetimin baktığı noktalar.
- Kullanım senaryosu modellemesi (use case modeling)
  - Kullanım senaryosu diyagramı: aktör, senaryo (elips), ilişki, sistem sınırı.
  - Kullanım senaryosu dokümanı şablonu.
  - Senaryolar arası ilişkiler: include, extend, genelleştirme.
- Bilgi toplama yöntemleri
  - Gözlem, kişisel görüşme (yapılandırılmış / yapılandırılmamış), anket.
- İş analizinin çıktı raporu: BRD (Business Requirements Document).

## Hocanın Özellikle Vurguladığı Kısımlar

- Kullanım senaryolarında mutlaka **etken cümle** kurun.
  - Edilgen cümlede işi kimin yaptığı belli olmaz.
- Senaryolarda işin **ne** yapıldığı yazılır, **nasıl** yapılacağı yazılmaz.
  - Nasıl yapılacağı tasarımın konusudur. Teknik ayrıntı senaryoya girmez.
- Sistemin bittiğini düşünün ve **bütün sorumluluklar** için senaryo yazın.
  - "Bu sorumluluğun senaryosunu yazmaya gerek duymadım" olmaz.
  - Ama sadece sistem sınırı içindeki sorumluluklar yazılır. Dış sistemlerin işi yazılmaz.
- 5 modül var diye 5 use case yazıp bitti demeyin.
  - Bir modülün işlevselliği genellikle birden fazla senaryodan oluşur.
- Use case diyagramındaki **her senaryo için ayrı bir doküman** yazılmalı.
  - Bankacılık örneğinde: 1 diyagram + 6 kullanım senaryosu dokümanı.
- Yönetim raporlara çok önem verir.
  - Projelerinizde farklı kırılımlarda istatistik raporlar oluşturun. Hoca, eksik modülleri olan gruplara raporlama modülleri ekledi.
  - Örnek: Spor salonunda abone sayısının aylara göre değişimi, saatlere göre kullanım yoğunluğu, yaş gruplarına göre ısı haritası.
- İnternette "SRS document" ve "BRD" örneklerine mutlaka bakın.
- Anket hazırlamak zordur. Katılımcıyı tanımlayan bilgi istemeyin.
  - Hoca, "anonimdir" deyip ilk üç soruda e-posta, üniversite-bölüm ve unvan isteyen bir anket örneği anlattı. Bu kötü bir anket tasarımıdır.

## Kısa Tekrar Notları

- Gereksinim analizi = iş analizi + işlevsel çözümleme.
- İş analizi: Mevcut işin nasıl yapıldığı, kimlerin hangi rolü üstlendiği, hangi formların doldurulduğu formal olarak raporlanır.
- SRS: Gereksinimlerin ve özelliklerinin yazıldığı doküman. Baştaki S "software" ya da "system" olabilir.
- Kullanım senaryosu diyagramının 4 sembolü:
  - Aktör (çöp adam), senaryo (elips), ilişki (çizgi/ok), sistem sınırı (dikdörtgen).
- Aktör: Sistemle etkileşen her şey. İnsan, dış sistem (ör. GPS) veya fiziksel birim olabilir.
- Bir aktör en az bir senaryoyla ilişkili olmalı. Bir senaryo birden fazla aktörle ilişkili olabilir.
- Birincil aktör (primary): Senaryodan asıl faydayı sağlayan ve senaryoyu başlatan aktör.
- Destek aktörü: Akışa bilgi veya hizmet sağlayan aktör.
- Kullanım senaryosu dokümanı:
  - Kod numarası ve ad.
  - Ön söz: birincil aktör, destek aktörleri, ilgililer ve beklentileri, ön koşul, son koşul.
  - Ana başarılı senaryo: numaralı, etken cümleler, koşul yok.
  - Alternatif akışlar: 3a, 3b, 3a1 gibi dallanmalar.
  - İsteğe bağlı: sıra dışı durumlar (exception), özel istekler (kalite kısıtları), teknolojik beklentiler.
- Senaryolar arası ilişkiler:
  - **Include (içerme):** Bir senaryo çalışırken başka bir senaryo mutlaka çalışır. Örnek: ders kaydında kimlik doğrulama.
  - **Extend (genişletme):** Belli bir koşulda ana senaryoyu genişleten senaryo. Ana senaryo tek başına da çalışır.
  - **Genelleştirme:** Genel senaryodan özel senaryolar türetilir. Örnek: ödeme → nakit, kart, çek. Aktörler arasında da olabilir.
- Bilgi toplama yöntemleri: gözlem, kişisel görüşme, anket.
- Soru sıralaması:
  - Tümevarım (piramit): kapalı uçludan açık uçluya. Görüşülen kişiyi konuya ısındırır.
  - Tümdengelim (huni): açık uçludan kapalı uçluya. Görüşülen kişi istekliyse tercih edilir.
- BRD içeriği: özet, amaç ve hedef, sisteme ihtiyaç, kapsam, ekonomik analiz, işlevsel gereksinimler (use case'ler), kaynak ihtiyacı, iş-zaman planı, maliyet-fayda analizi.

## Detaylı Açıklamalar

Ders, fizibiliteden sonra gelen gereksinim analizi aşamasının ilk adımı olan iş analizini anlatır. Bu aşama teknik değildir. Ama teknik çözümlemeye sağlam bir temel hazırlar.

### Gereksinim analizinin yeri

- Süreç: ön inceleme → fizibilite → gereksinim analizi → tasarım.
- Gereksinim analizinde problemin ne olduğu, çözüm için hangi parçalara ihtiyaç olduğu ve sistemin nasıl çalışması gerektiği sorgulanır.
- Fizibilitedeki öneriler kullanılarak müşterinin beklentisini en iyi karşılayan çözüm aranır. Hedef en hızlı, en ucuz ya da en az kaynak tüketen çözüm olabilir.
- Bu aşamada fizibilite raporları gözden geçirilir. Zaman fizibilitesindeki görev dağılımı güncellenir. Yönetimin denetim mekanizması kurulur.
- Fizibilite bir tahmindi. Gereksinim analiziyle birlikte faaliyetler kesinleşir.

### Mevcut durumun tespiti

- Sistem analistinin ilk işi mevcut sistemi tanımaktır. Analist mevcut sistemi kullanmalı ve ona hâkim olmalıdır.
- İncelenenler:
  - Bilgi kaynakları, donanım ve yazılım, bilgi hacmi.
  - Dış sistemlerle etkileşim, rutin (döngüsel) işler, arşivleme.
  - Üretilen raporlar ve formatları.
  - Paydaşlar: kim ne yapıyor, nerede zorlanıyor.
  - Mevcut sistemin çalışma maliyeti.
- Hoca bunu Nutuk'un başlangıcına benzetir: Önce mevcut durum ortaya konur, sonra yeni sisteme geçilir.

### Gereksinimlerin belirlenmesi

- Müşteri ne istediğini net biliyorsa: İşlevler, arayüzler ve kabul kriterleri iş akış diyagramlarıyla anlatılır.
- Müşteri ne istediğini bilmiyorsa ("Bunun bilgisayarla yapılabileceğini bilmiyordum" diyen müşteri):
  - Basit bir prototip yapılır ve müşteriye gösterilir.
  - Müşterinin geri bildirimiyle prototip adım adım genişletilir.
- Sonuç bir rapordur: SRS (System/Software Requirements Specification).
- SRS hazırlanırken geliştirme planı (Gantt) ve yönetimin onay mekanizması da eş zamanlı gözden geçirilir.
- Genel akış:
  - Fizibilite → yazılım planı (Project Charter) → idari inceleme.
  - Kabul edilirse gereksinim analizi başlar. Gereksinimler biliniyorsa tanımlanır, bilinmiyorsa model ve prototip oluşturulur.
  - Teknik inceleme (analistler) → gerekirse revizyon.
  - Yönetimin son incelemesi → kabul edilirse tasarım aşaması.

### İdari incelemede yönetimin baktığı noktalar

- İşletmenin genel stratejileriyle uyum.
- Kararlarda bilgi, deneyim ve öngörünün birlikte kullanılması.
- Çatışan ihtiyaçlardan hangisinin işletmeye daha çok fayda sağladığı.
- Somut mali fayda: verimlilik ve karlılık artışı.
- Organizasyondaki sayısal değişiklik. Örnek: Sistem nedeniyle işten çıkarma ya da yeni istihdam ihtiyacı.
- Raporlama kalitesi: hızlı ve ayrıntılı raporlar.
- Bilgi akışlarının ve güncellemelerin planlı olması.
- Yeni çözümün mevcut duruma göre fark edilir derecede iyi olması.
- Teknolojilerin mevcut sistemlerle uyumu, kullanıcı etkileşimi, verinin organizasyonu.

### Kullanım senaryosu modellemesi

- İş analizinde gereksinimleri ve iş akışlarını yarı formal biçimde anlatan modeldir.
- Her senaryo sistemdeki bir sorumluluktur. Sonunda kullanıcıya faydalı bir çıktı üretir.
- Hoca örnek olarak kargo dağıtım planlamasını anlatır:
  - Bazı firmalar aracın kapasitesi kadar paketi yükleyip rotayı sürücüye bırakır.
  - Bazıları paket boyutları ve adreslerle en kısa rotayı hesaplayıp sürücünün navigasyonuna verir. Dağıtım sonuçları geri besleme olarak rota optimizasyonuna döner.
  - Bu işin adres alma, paket bilgisi alma, optimizasyon gibi alt adımları ayrı senaryolarla modellenir.

#### Kullanım senaryosu diyagramı

- Sistemin kullanıcı bakış açısıyla işlevsel bir çözümlemesidir.
- Araç takip sistemi örneği:
  - Aktörler: Operatör (insan) ve GPS Sistemi (dış sistem).
  - Senaryolar: Report Location (GPS sistemiyle), Find Arrival Times (operatör), Report Errors (operatör).
  - Varış zamanı hesaplanırken harita servisi kullanılacaksa, o servis de bir aktör olarak eklenmelidir. Bu tamamen problemin nasıl modellendiğine bağlıdır.

#### Kullanım senaryosu dokümanı şablonu

- **Kod ve ad:** Örnek: UC1 Report Location.
- **Ön söz (preface):**
  - Birincil aktör.
  - Destek aktörleri, ilgililer ve beklentileri. Örnek: GPS sistemi koordinat bilgisini verir.
  - Ön koşul (precondition). Örnek: Hafta içi mesai saatlerinde olmak.
  - Son koşul (postcondition): Senaryo bitince garanti edilen durum. Örnek: Servislerin varış saatleri veritabanına kaydedilir.
- **Ana başarılı senaryo:** Numaralı adımlar, etken cümleler, koşul yok. Adımlar genelde üç tiptir: kullanıcı-sistem etkileşimi/tetikleme, onay ve durum değişikliği/bilgi kaydı.
- **Ders kaydı örneği:**
  - Ön koşul: Öğrencinin o dersi alabilecek sınıfta olması.
  - Son koşul: Ders kaydının oluşturulması.
  - Ana akış:
    1. Öğrenci almak istediği dersin kodunu girer.
    2. Sistem dersin gününü, saatini ve kredisini gösterir.
    3. Öğrenci onay butonuna basar.
    4. Sistem ikinci onaydan sonra kaydı gerçekleştirir.
  - Alternatif akışlar:
    - 3a. Sistem kontenjanı kontrol eder. Kontenjan doluysa hata verir, kaydı yapmaz.
    - 3b. Kontenjan doluysa sistem özel öğrenci (ör. Erasmus) durumunu kontrol eder. Özel öğrenciyse kaydı yapar.
- **İsteğe bağlı bölümler:**
  - Sıra dışı durumlar (exception handling): Hata olunca kayıt geri alınacak mı?
  - Özel istekler: Örnek: saniyede 10.000 ders kaydı, 256 bit SSL, en az 3 seviyeli resimli CAPTCHA.
  - Teknolojik beklentiler: dil, platform, kütüphane kısıtları.
- Çok karmaşık senaryolarda alt parçalar "contract" (sözleşme) ile yazılabilir. Hoca bu konuyu geçti.

#### Senaryolar arası ilişkiler

- **İlişki (association):** Aktör ile senaryo arasındaki bağlantı. Hastane örneğinde "Tahlil Ver" senaryosu hem hasta hem laboratuvarla ilişkilidir.
- **Include:** Ortak işlevler. Örnek: Tahlil vermek için sıra numarası almak ve kan vermek gerekir. Login/kimlik doğrulama da tipik include örneğidir.
- **Extend:** Örnek: Tahlil sonucu ekranda görülür. İstenirse sonuç basılıp adrese postalanır ya da e-postayla gönderilir. Bu ek senaryo ana senaryoyu genişletir.
- **Genelleştirme:** Hastane örneğinde (slayt 21) Doktor ve Hasta, Laborant aktöründen türetilmiştir. Bu yüzden Doktor da "Tahlil Sonucu Al" senaryosunu kullanabilir. Laborant burada soyut aktör gibi davranır.

#### Bankacılık örneği (slayt 22, kareden)

- Aktörler: Customer, Bank Employee, NRFC Customer (non-resident foreign customer, Customer'dan türetilmiş).
- Senaryolar ve ilişkiler:
  - Open Account: Customer ve Bank Employee.
  - Deposit Funds: Customer. Calculate Bonus bu senaryoyu extend eder (koşul: tutar 10.000'in üstünde veya yaş 55'in üstünde).
  - Withdraw Funds: Customer.
  - Deposit Funds ve Withdraw Funds, Update Balance senaryosunu include eder.
  - Convert Currency: Sadece NRFC Customer.
- NRFC Customer genelleştirme sayesinde Customer'ın bütün senaryolarını da kullanabilir. Ama yerli müşteri döviz dönüşümü yapamaz.
- İş analizini tamamlamak için 1 diyagram ve 6 kullanım senaryosu dokümanı gerekir.

### Bilgi toplama yöntemleri

- Mevcut sistemin eksik veya yanlış anlaşılmaması için doğru bilgi toplamak önemlidir.

#### Gözlem

- Analist müşterinin iş ortamına gider ve çalışanları belli bir süre izler (bir gün, bir hafta, bir ay; işin karmaşıklığına göre).
- Kullanılan belge, form ve dosyalardan örnek (kopya) alınır. Her formun ne işe yaradığı öğrenilir.
- Mevcut sistem varsa nasıl kullanıldığı gözlenir: hangi ekran, hangi girdi, hangi çıktı.

#### Kişisel görüşme

- Toplantı, mülakat ya da büyük ölçekte ortak gereksinim planlama semineri olabilir.
- Kurallar:
  - Randevu alınır ve görüşmeye hazırlıklı gidilir.
  - Görüşmenin amacını açıklayan bir başlangıç konuşması hazırlanır. Konular bellidir.
  - Not alınır. Hitap şekline ve duruşa dikkat edilir.
  - Sonunda bir çıkış notu (toplantı tutanağı) hazırlanır.
- Yapılandırılmış görüşme: Amaç, katılımcılar, süre, belgeler ve sorular önceden bellidir. Sonuçlar raporlanıp dağıtılır.
- Yapılandırılmamış görüşme: Daha serbest ve ucu açık. Kullanıcının zorlandığı noktalar ve beklentileri konuşulur.
- Karşılaştırma (slayt 29, kareden):

| Ölçüt | Yapılandırılmamış | Yapılandırılmış |
| :--- | :---: | :---: |
| Değerlendirme | Zor | Kolay |
| Harcanan zaman | Çok | Az |
| Eğitim | Sınırsız | Sınırlı |
| Kendiliğinden oluşma | Fazla | Az |
| Cevaplayanın kendi görüşünü ortaya koyması | Çok fazla | Çok az |
| Esneklik | Çok | Az |
| Görüşmecinin kontrol etmesi | Az | Fazla |
| Doğruluk | Az | Fazla |
| Güvenilirlik | Az | Fazla |
| Genişlik ve derinlik | Fazla | Az |

#### Anket

- Müşteri belli değilse ve son kullanıcıya hitap eden bir ürün geliştiriliyorsa (ör. mobil oyun) kullanılır.
- Müşteri belliyse gözlem ve görüşme daha doğru yöntemlerdir.
- İyi anket kuralları:
  - Sorular tam, eksiksiz ve açık olmalı.
  - Gerekirse hatırlatma yapılmalı.
  - Cevap arzusu oluşturulmalı: özel hayatla ilgisiz, kolay ve ilgi çekici sorular.
  - Hatalı cevaplar kontrol sorularıyla yakalanmalı.
  - Görsellerle desteklenebilir.
  - Cevaplayan şartlandırılmamalı ("Sizce de çok iyi değil mi?" gibi sorular sorulmaz).
- Avantajlar: çok kişiden hızlı ve ucuz veri, kimlik gizliliği, dijital ortamda hızlı analiz.
- Dezavantajlar: katılımı sağlamak zor, eksik cevaplar, esneklik az, vücut dili analiz edilemez, muğlak sorular muğlak cevap getirir.
- Açık uçlu sorular: Ayrıntılı ve gerçek görüş alınır. Ama doldurması yorucu, analiz etmesi zordur. Cevabın kalitesi eğitim seviyesine bağlıdır.
- Kapalı uçlu sorular: Çoktan seçmeli, sıralama vb. Hızlı işlenir. Ama seçenekler eksikse gerçek cevap kaybolur, katılımcı engellenmiş hissedebilir.
- İkisi dengeli kullanılmalı. Sorular genelden özele, basitten zora ve mantıklı bir sırayla dizilmeli. Farklı konular ayrı bölümlerde olmalı.

### İş analizinin çıktısı: BRD

- BRD (Business Requirements Document) içeriği: özet, amaç ve hedef, sisteme neden ihtiyaç olduğu, kapsam (sistem sınırları), fizibiliteden ekonomik analiz, işlevsel gereksinimler (use case diyagramı ve senaryolar), kaynak ihtiyacı, iş-zaman planı, maliyet-fayda analizi.
- Alternatif olarak araştırma raporu formatı kullanılabilir: başlık, içindekiler, amaç, metodoloji (yöntem, işlem, analiz, yorum), sonuç ve öneriler, ekler.
  - Üst yönetim için ayrıca kısa bir yönetici özeti (executive summary) yazılır.
- Gelecek hafta: işlevsel çözümleme, SRS dokümanı ve senaryolardan kavramsal model (analiz modeli) oluşturma.

### Ders sonrası notlar

- **Görüşme karşılaştırması:** Hoca tabloyu okurken iki yerde dil sürçmesi yaptı.
  - "Eğitim ihtiyacı yapılandırılmışta sınırlıdır, yapılandırılmışta sınırsızdır" dedi. Slayta göre yapılandırılmamış görüşmede eğitim ihtiyacı sınırsızdır.
  - "Genişlik ve derinlik yapılandırılmış görüşmede fazla" dedi. Slayta göre yapılandırılmamış görüşmede fazla, yapılandırılmışta azdır.
  - Slaytta "Anketörün kontrol etmesi" yazıyor. Hoca da belirttiği gibi doğrusu "görüşmecinin (mülakatçının) kontrol etmesi".
- **Primary aktör oku:** Hoca, ilişki çizgisinde ok varsa ok çıkan aktörün birincil aktör olduğunu söyledi. UML standardında ilişki çizgisindeki ok zorunlu değildir. Bazı kaynaklar birincil aktörü göstermek için kullanır. Birincil aktörü kesin belirtmenin yolu senaryo dokümanının ön söz bölümüdür.
- **Hastane genelleştirme örneği (slayt 21):** Slaytta Hasta, Laborant'tan türetilmiş görünüyor. Genelleştirme "bir türüdür" (is-a) ilişkisi demektir. Hastanın bir laborant olması anlam olarak tutarsızdır; hoca da derste tereddüt etti. Doğrusu, "Tahlil Sonucu Al" senaryosunu kullanan ortak bir soyut aktör (ör. "Tahlil Sonucu Görüntüleyen") tanımlayıp Doktor ve Hastayı ondan türetmek ya da Hastayı senaryoya doğrudan bağlamaktır.
- **Extend oku yönü:** Bankacılık örneğinde (slayt 22) ok Calculate Bonus'tan Deposit Funds'a doğrudur. Bu UML'de doğrudur: extend okunu genişleten senaryo genişletilene doğru çizer. Include okunu ise içeren senaryo içerilene doğru çizer (Deposit Funds → Update Balance).
- **Soru sıralaması:** Kaynaklarda tümevarım yaklaşımına "piramit", tümdengelim yaklaşımına "huni" yapısı denir. Hocanın anlatımı bununla uyumlu.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
