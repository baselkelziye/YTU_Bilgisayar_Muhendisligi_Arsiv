# Ders 12 Çalışma Özeti

*Bu çalışma özeti, `ders_12.srt` altyazısı ve ders videosu kareleri üzerinden hazırlanmıştır. Bu derste proje grupları dönem projesi olan **Özel Aydınlık Üniversitesi Kütüphane Bilgi Sistemi (Kiosk Otomasyonu)** tasarımlarını, risk analizlerini, UML diyagramlarını ve birim sınaması (*unit test*) senaryolarını sunmuş; ders sorumlusu Dr. Yunus Emre Selçuk her tasarım kararını yazılım mühendisliği ilkeleri açısından değerlendirmiştir. Notlarda yalnızca akademik içerik ve tasarım eleştirileri yer almakta olup sunum yapanlar "bir grup" veya "bir öğrenci" olarak anılmıştır.*

---

## Genel Konular

- **Proje Problem Alanı (Kütüphane Kiosk Otomasyonu):** Özel Aydınlık Üniversitesi Kütüphane Bilgi Sistemi'nde kullanılan kiosk cihazları üzerinden ödünç alma (*borrow*), iade etme (*return*), süre uzatma (*renew*), kitap ayırtma/rezervasyon (*reserve*), kitap arama ve kütüphane görevlisi aracılığıyla yeni kitap/üye kaydı ile gecikme cezası (*fine*) işlemlerinin modellenmesi.
- **Risk Analizi, RMMM ve Teknik Borç (*Technical Debt*):** Proje geliştirme sürecinde karşılaşılabilecek teknik, yönetimsel ve dışsal risklerin olasılık–etki matrisiyle önceliklendirilmesi; zaman baskısı altında yapılan kestirme çözümlerin oluşturduğu **teknik borç (*technical debt*)** kavramı; veri sızıntısı ve güvenlik kontrolü (*Have I Been Pwned*).
- **Kullanım Senaryosu (*Use Case*) Şeması Tasarım İlkeleri:** Aktörlerin (*Kullanıcı*, *Kütüphane Görevlisi / Yönetici*, *Zaman / Sistem*) doğru konumlandırılması; `<<include>>` ve `<<extend>>` ilişkilerinin yönü ve anlamsal farkı; kimlik doğrulama (*giriş yapma*) adımının kullanım senaryolarıyla ilişkisi.
- **Faaliyet (*Activity*) ve Durum (*State*) Şemaları:** İş akışlarında karar düğümlerinin (*decision node*) tüm dallarının (`[evet]` / `[hayır]`) eksiksiz gösterilmesi; durum şemalarında **sistemin genel iş akışı yerine tek bir nesnenin (`Kitap` veya `Üye`) yaşam döngüsünün** (`Rafta`, `Ödünç Alındı`, `Rezerve Edildi`, `Kayıp/Hasarlı`) modellenmesi.
- **Sıralama (*Sequence*) Şeması ve Eşzamanlılık (*Concurrency*):** Nesneler arası mesajlaşma sırası, alternatif/koşullu bloklar (`alt`, `opt`, `loop`), aktivasyon çubukları ve iki farklı kiosktan aynı kitabın aynı anda ödünç alınmaya çalışılması durumunda **veritabanı kilitleme (*locking*) / işlem (*transaction*)** yönetimi.
- **Sınıf (*Class*) Şeması ve Nesne Yönelimli Tasarım Kararları:**
  - *Üye* türlerinin (`Öğrenci`, `Akademisyen`, `Personel`) **kalıtım (*inheritance*)** ile mi yoksa **nitelik/enum (`ÜyeTürü`)** ile mi modelleneceği (*Open-Closed Principle* ve davranış farkı analizi).
  - `Kütüphane` veya `VeritabanıYöneticisi` sınıflarında **Singleton (Tek Nesne)** tasarım örüntüsünün uygulanması (`private` kurucu, `static instance`, `getInstance()`).
  - İlişki okları, çokluk (*multiplicity*: `1`, `0..*`, `1..3`) ve kapsama (*composition* / *aggregation*) gösterimleri.
- **Birim Sınaması (*Unit Testing*) ve Duman Testi (*Smoke Test*):** JUnit / NUnit / Python `unittest` ile birim testi yazımı; `assertEquals`, `assertTrue`, `assertFalse` doğrulamaları; pozitif testlerin yanında **negatif testlerin ve sınır değerlerinin (*boundary values*)** sınanması; sistemin temel işlevlerinin hızla kontrol edildiği **duman testi (*smoke test*)** kavramı.

---

## Hocanın Özellikle Vurguladığı Kısımlar

> *"Durum diyagramı (*State Diagram*) sistemin genel akış şeması değildir; durumu anlamlı biçimde değişen **belirli bir nesnenin** (örneğin `Kitap` nesnesinin) yaşam döngüsünü gösterir. Faaliyet diyagramı (*Activity*) ile durum diyagramını birbirine karıştırmayın."*

- **Faaliyet (*Activity*) vs. Durum (*State*) Şeması Ayrımı:**
  - Pek çok grubun yaptığı en yaygın hata, durum şemasında *"Kullanıcı giriş yaptı $\rightarrow$ Kitap aradı $\rightarrow$ Ödünç aldı"* şeklinde iş akışı çizmektir. Bu bir **faaliyet şemasıdır**.
  - **Durum şeması**, örneğin bir `Kitap` nesnesinin `Mevcut (Rafta)` durumundan `Ödünç Verildi` durumuna, oradan `Süresi Geçti` veya `Rezerve Edildi` durumuna geçişlerini ve bu geçişleri tetikleyen olayları (`ödünçAl()`, `iadeEt()`, `süreDoldu()`) göstermelidir.
- **Karar Baklavalarında (*Decision Nodes*) Eksik Dal Bırakılmaması:**
  - Faaliyet şemalarında bir koşul baklavasından (`[Kitap mevcut mu?]`, `[Üyenin cezası var mı?]`, `[Kitap sayısı < Limit mi?]`) yalnızca `[Evet]` oku çıkarıp `[Hayır]` dalını boş bırakmak ciddi bir modelleme hatasıdır. Her karar noktasının alternatif akışı bir sonlanma veya hata/uyarı adımıyla kapatılmalıdır.
- **Kalıtım (*Inheritance*) Ne Zaman Kullanılmalı?**
  - `Öğrenci` ve `Akademisyen` sınıfları arasında yalnızca "ödünç alabileceği maksimum kitap sayısı" (`3` vs. `5`) veya "ödünç süresi" (`15 gün` vs. `30 gün`) gibi **veri/parametre farkı** varsa, bunları ayrı alt sınıflar yapmak yerine `Üye` sınıfı içinde bir tür alanı (`uyeTuru`) veya konfigürasyon tutmak daha sadedir.
  - Ancak alt sınıfların **davranışları (metot gövdeleri / ceza hesaplama algoritmaları)** birbirinden farklılaşıyorsa kalıtım (`Üye <|-- Öğrenci`, `Üye <|-- Akademisyen`) veya *Strategy* örüntüsü kullanmak nesne yönelimli tasarıma uygundur.
- **Birim Sınamasında (*Unit Testing*) Yalnızca "Mutlu Yol" (*Happy Path*) Yetmez:**
  - Birim testlerinde sadece geçerli girdilerle başarılı ödünç alma işlemini test etmek yetersizdir.
  - Kitap limiti dolmuş bir üyenin yeni kitap alamaması, başkasına ödünç verilmiş kitabın tekrar ödünç verilememesi, yanlış şifreyle girişin reddedilmesi ve gecikme gününe göre ceza tutarının sınır değerlerde doğru hesaplanması mutlaka ayrı `test...` metotlarıyla doğrulanmalıdır.

---

## Kısa Tekrar Notları

- **Teknik Borç (*Technical Debt*):** Teslim tarihine yetişmek için tasarım kalitesinden ödün verilerek (ör. test yazmadan, mimariyi bozarak) yapılan hızlı çözümlerin, ileride faiziyle birlikte ödenmesi gereken bakım ve yeniden yazım (*refactoring*) maliyetidir.
- **Duman Testi (*Smoke Test*):** Donanım/elektronik dünyasından (*"cihaza elektriği ver, duman çıkmıyorsa ayrıntılı teste geç"*) yazılım mühendisliğine geçmiş terimdir; yeni bir derleme (*build*) alındığında sistemin en temel, kritik işlevlerinin çökmeden çalışıp çalışmadığını hızlıca kontrol eden yüzeysel doğrulama testidir.
- **Have I Been Pwned (`haveibeenpwned.com`):** Risk analizi tartışmasında hocanın değindiği, e-posta veya пароla özetlerinin (*hash*) bilinen veri ihlallerinde (*data breach*) sızdırılıp sızdırılmadığını kontrol eden güvenlik servisidir.
- **UML `<<include>>` vs. `<<extend>>` Özeti:**
  - `Ana Senaryo - - -> <<include>> - - -> Alt Senaryo`: Ana senaryo her çalıştığında alt senaryo **zorunlu** olarak çalışır (ör. `Kitap Ödünç Al` $\xrightarrow{\text{<<include>>}}$ `Kimlik Doğrula` / `Üye Girişi Yap`). Ok, ana senaryodan dahil edilen senaryoya doğrudur.
  - `Uzantı Senaryosu - - -> <<extend>> - - -> Ana Senaryo`: Uzantı senaryosu yalnızca **belirli bir koşul gerçekleşirse (opsiyonel)** devreye girer (ör. `Ceza Öde` $\xrightarrow{\text{<<extend>>}}$ `Kitap İade Et` — yalnızca gecikme varsa). Ok, opsiyonel uzantıdan ana senaryoya doğrudur!
- **Singleton Tasarım Örüntüsü (*Design Pattern*):**
  1. Kurucu metot (`constructor`) dışarıdan `new` ile çağrılamaması için `private` yapılır.
  2. Sınıf kendi türünden `private static` bir `instance` referansı tutar.
  3. Dış dünyaya `public static getInstance()` metodu sunulur; `instance == null` ise nesneyi oluşturur, değilse mevcut nesneyi döndürür.
- **Eşzamanlılık (*Concurrency*) ve Kiosk Senaryosu:** Kütüphanede birden fazla kiosk bulunduğundan, iki kullanıcının aynı anda son kopyayı ödünç almaya çalışması bir yarış durumu (*race condition*) doğurur. Sıralama ve sınıf tasarımlarında stok/durum kontrolü ile ödünç kaydının **atomik bir işlem (*transaction*)** olarak düşünülmesi gerekir.

---

## Detaylı Açıklamalar

### 1. Proje Problem Alanı: Kütüphane Bilgi Sistemi (Kiosk Otomasyonu)

Dönem projesi senaryosu, bir üniversite kütüphanesinde ("Özel Aydınlık Üniversitesi") hem kütüphane görevlilerinin hem de üyelerin (öğrenci ve akademisyenlerin) self-servis **kiosk terminalleri** üzerinden işlem yapabildiği bir otomasyon sistemidir:

| İşlev / Kural | Tasarımda Dikkat Edilmesi Gereken Nokta |
|---|---|
| **Üye Türleri ve Kotalar** | Öğrenci ve akademisyenlerin ödünç alabileceği azami kitap sayısı (ör. 3 vs. 5 kitap) ve ödünç tutma süresi (ör. 15 vs. 30 gün) farklıdır. |
| **Ödünç Alma (*Borrow*)** | Üyenin cezası/engeli olmamalı, kitap kotası dolmamış olmalı ve kitabın durumu `Rafta (Mevcut)` (veya o üye adına `Rezerve`) olmalıdır. |
| **İade Etme (*Return*) ve Ceza (*Fine*)** | Teslim tarihi geçmişse gecikme gün sayısı üzerinden ceza hesaplanır; kitap için bekleyen rezervasyon varsa durumu `Rezerve Edildi`, yoksa `Rafta` yapılır. |
| **Süre Uzatma (*Renew*)** | Kitap başka bir üye tarafından rezerve edilmemişse ve azami uzatma hakkı dolmamışsa teslim tarihi ileriye çekilir. |
| **Kitap Ayırtma (*Reserve*)** | Ödünçte olan bir kitap için sıraya girilir; kitap iade edildiğinde sıradaki üyeye bildirim/öncelik tanınır. |

---

### 2. Risk Yönetimi, RMMM ve Teknik Borç (*Technical Debt*)

Proje sunumlarının ilk bölümünde grupların hazırladığı **Risk Analizi ve RMMM (*Risk Mitigation, Monitoring, and Management*)** tabloları incelenmiştir:

1. **Proje Özgül Riskler vs. Genel Riskler:**
   - *"Bilgisayarın bozulması"*, *"elektrik kesintisi"* veya *"ekip üyesinin hastalanması"* her projede var olan genel risklerdir.
   - İyi bir risk analizinde **projeye özgü teknik ve mimari riskler** de yer almalıdır:
     - Kiosk donanımı (barkod/RFID okuyucu, dokunmatik ekran) ile yazılım arayüzünün entegrasyon uyumsuzluğu,
     - Birden fazla kiosktan eşzamanlı (*concurrent*) erişimde veritabanı tutarsızlığı (*race condition*),
     - Üye kimlik/şifre verilerinin güvenliği ve KVKK/veri sızıntısı riski.
2. **Risk Olasılık ve Etki Değerlendirmesi:**
   - Riskler **Olasılık ($P$)** ve **Etki ($I$)** çarpımıyla ($R = P \times I$) sıralanmalı; en yüksek puanlı riskler için somut **Önleme (*Mitigation*)**, **İzleme (*Monitoring*)** ve **Yönetim/Acil Eylem (*Management/Contingency*)** adımları yazılmalıdır.
3. **Teknik Borç (*Technical Debt*):**
   - Bir grubun *"zaman yetişmezse bazı modülleri hızlıca birleştirip geçici yazarız"* yaklaşımı üzerine hoca **Teknik Borç (*Technical Debt*)** kavramını vurgulamıştır.
   - Tıpkı finansal borç gibi, yazılımda kısa vadede zaman kazanmak için yapılan özensiz tasarım veya eksik testler, sonraki sürümlerde yüksek "faiz" (kodun anlaşılamaması, bir yeri düzeltirken başka yerin bozulması) olarak geri döner.
4. **Siber Güvenlik ve Veri İhlali Farkındalığı:**
   - Kullanıcı hesaplarının güvenliği konuşulurken hoca, bilinen veri sızıntılarında e-posta ve parolaların yer alıp almadığını denetleyen **Have I Been Pwned** servisini örnek göstererek kimlik doğrulama tasarımında açık metin (*plaintext*) parola tutulmaması gerektiğini hatırlatmıştır.

---

### 3. UML Diyagramları Üzerinden Tasarım Değerlendirmeleri

#### A. Kullanım Senaryosu (*Use Case*) Şeması
- **Aktörlerin İsimlendirilmesi ve Ayrımı:**
  - *Üye* (*Kullanıcı*) ile *Kütüphane Görevlisi* (*Personel / Yönetici*) aktörlerinin yetkileri net ayrılmalıdır. Kitap ekleme, kitap silme, üye kaydı/silme işlemleri *Kütüphane Görevlisi*ne; kitap ödünç alma, iade etme, süre uzatma ve rezervasyon işlemleri *Üye* aktörüne bağlanmalıdır.
  - Eğer *Kütüphane Görevlisi* aynı zamanda üye gibi kitap ödünç alabiliyorsa, görevli aktöründen üye aktörüne **genelleştirme (*generalization*) oku** çizilerek tüm üye senaryolarını miras alması sağlanabilir; böylece şemada ok karmaşası önlenir.
- **`<<include>>` ve `<<extend>>` Oklarının Yönü:**
  - Grupların en sık hata yaptığı noktalardan biri ok yönleridir.
  - `Giriş Yap (Login)` senaryosu, kimlik gerektiren işlemler için zorunlu bir ön/alt adım olarak modellendiyse `Kitap Ödünç Al - - -> <<include>> - - -> Giriş Yap` şeklinde gösterilir.
  - `Gecikme Cezası Hesapla / Öde` ise her iade işleminde değil, yalnızca teslim tarihi aşıldığında çalıştığı için `Ceza Öde - - -> <<extend>> - - -> Kitap İade Et` yönünde bağlanır.

#### B. Faaliyet (*Activity*) Şeması
- **Karar Düğümleri ve Koruma Koşulları (*Guards*):**
  - Her elmas (baklava) düğümünden çıkan oklarda köşeli parantez içinde koşul (`[ceza > 0]`, `[ceza == 0]`, `[kitap mevcut]`, `[kitap ödünçte]`) yazılmalıdır.
  - Başarısız koşulların nereye bağlandığı (kullanıcıya hata mesajı gösterilip akışın sonlandırılması veya önceki adıma dönülmesi) şemada açıkça izlenebilmelidir.
- **Kulvarlar (*Swimlanes / Partitions*):**
  - İşlemin hangi adımının **Kullanıcı**, hangi adımının **Kiosk Arayüzü**, hangi adımının **Kütüphane Sistemi / Veritabanı** tarafından yapıldığını göstermek için kulvarlı (*swimlane*) faaliyet şeması kullanmak okunabilirliği büyük ölçüde artırır.

#### C. Durum (*State*) Şeması
- **Sistem Akışı Değil, Nesne Durumu:**
  - Durum şeması çizilirken önce *"Hangi sınıfın durum şemasını çiziyorum?"* sorusu sorulmalıdır.
  - Bu projede durum şeması için en uygun aday **`Kitap` (veya `KitapKopyası`)** sınıfıdır:

```text
                  ödünçAl()
   [Başlangıç] ──► [ Rafta / Mevcut ] ──────────────────────► [ Ödünç Alındı ]
                          ▲                                      │        │
                          │ iadeEt() [rezervasyonYok]            │        │ süreDoldu()
                          ├──────────────────────────────────────┘        ▼
                          │                                      [ Süresi Geçti / Cezalı ]
                          │ rezervasyonİptal()                            │
                          │                                               │
                   [ Rezerve Edildi ] ◄───────────────────────────────────┘
                                        iadeEt() [rezervasyonVar]
```

#### D. Sıralama (*Sequence*) Şeması
- **Yaşam Çizgileri (*Lifelines*) ve Mesaj Tutarlılığı:**
  - Sıralama şemasındaki nesneler (`:KioskArayüzü`, `:ÖdünçKontrolcüsü`, `:Üye`, `:Kitap`, `:Veritabanı`) sınıf şemasında tanımlanan sınıflarla birebir örtüşmelidir.
  - Sıralama şemasında çağrılan her mesaj (ör. `oduncAl(uyeId, kitapId)`, `durumGuncelle(ODUNC)`), hedef sınıfın **Sınıf Şeması (*Class Diagram*)** içindeki metot listesinde gerçekten bulunmalıdır.
- **Alternatif Çerçeveler (`alt` / `opt`):**
  - Koşullu durumlar (örneğin kitabın uygun olup olmaması veya üyenin cezasının bulunması) sıralama şemasında `alt [Kitap uygun ve üye engelsiz] ... [else] ...` çerçevesiyle gösterilmelidir.

#### E. Sınıf (*Class*) Şeması ve Tasarım Örüntüleri
- **Sorumlulukların Dağıtılması:**
  - Tüm metotları tek bir `Kütüphane` veya `Sistem` sınıfına yığmak (*God Object / Tanrı Nesne* anti-örüntüsü) yerine, sorumluluklar `Üye`, `Kitap`, `Ödünçİşlemi (Loan)`, `Rezervasyon` ve `KütüphaneYöneticisi` sınıfları arasında dengeli dağıtılmalıdır.
- **Singleton Örüntüsü:**
  - Sistemde tek bir merkezi kütüphane/veritabanı yöneticisi olması istendiğinde **Singleton** tasarım örüntüsü kullanılır; ancak diyagramda `Singleton` yazmak yetmez, `- instance : Kutuphane` (`static`) niteliği, `- Kutuphane()` (`private` kurucu) ve `+ getInstance() : Kutuphane` (`static`) metodu sınıf kutusunda açıkça gösterilmelidir.
- **Çokluk (*Multiplicity*) Gösterimleri:**
  - Bir `Üye` aynı anda en çok 3 (veya 5) kitap ödünç alabiliyorsa `Üye "1" --- "0..3" Kitap` (veya `ÖdünçKaydı` üzerinden `0..*`) şeklinde çokluk sınırları belirtilmelidir.

---

### 4. Birim Sınaması (*Unit Testing*) ve Test Senaryoları

Dersin ikinci bileşeninde gruplar C#, Java (JUnit) veya Python (`unittest`) kullanarak yazdıkları birim testlerini canlı olarak çalıştırmışlardır. Hocanın birim sınaması üzerindeki değerlendirme ölçütleri şunlardır:

1. **Gerçek Birim Testi vs. Konsol Çıktısı (`print`):**
   - Test metodunun içinde yalnızca `System.out.println` veya `Console.WriteLine` ile ekrana yazı yazdırmak gerçek bir birim testi değildir.
   - Birim testinde mutlaka **`assertEquals(beklenen, gerçek)`**, **`assertTrue(koşul)`** veya **`assertFalse(koşul)`** gibi otomatik doğrulama (*assertion*) ifadeleri kullanılmalı; test çerçevesi (*test runner*) yeşil/kırmızı sonucu otomatik üretmelidir.
2. **Testlerin Bağımsızlığı (*Isolation*):**
   - Bir test metodunun başarılı olması, kendisinden önce başka bir test metodunun çalışmış olmasına bağlı olmamalıdır. Her test kendi başlangıç durumunu (`setUp` / `@Before`) hazırlamalıdır.
3. **Kapsanması Gereken Temel Test Senaryoları:**
   - **Pozitif (Başarılı) Senaryolar:** Engelsiz bir üyenin raftaki bir kitabı ödünç alması ve kitabın durumunun `Ödünçte`, üyenin kitap sayısının `+1` olması; iade edildiğinde durumun tekrar `Rafta` olması.
   - **Negatif ve Sınır Değer Senaryoları:**
     - Halihazırda ödünçte olan bir kitabın başka bir üyeye ödünç verilmesinin reddedilmesi (`false` dönmesi veya istisna fırlatması),
     - Kitap kotası (ör. 3 kitap) dolmuş bir öğrencinin 4. kitabı ödünç alamaması,
     - Cezası olan veya üyeliği pasif olan bir kullanıcının ödünç alma işleminin engellenmesi,
     - Gecikme gün sayısına göre ceza hesaplama fonksiyonunun `0 gün` (cezasız), `1 gün` ve `N gün` gecikme için doğru tutarı döndürmesi.
4. **Duman Testi (*Smoke Testing*) İlişkisi:**
   - Bir öğrenci sunumunda geçen *Smoke Test* kavramı üzerine hoca, duman testinin sistemin tüm sınır durumlarını tarayan derinlemesine bir birim/entegrasyon testi olmadığını; yeni bir sürüm derlendiğinde *"sistem ayağa kalkıyor mu, temel fonksiyonlar çökmeden yanıt veriyor mu?"* sorusunu yanıtlayan ilk ön kontrol testi olduğunu açıklamıştır.

---

*Not: Bu özet dosyasını Google Gemini NotebookLM veya benzeri bir araca yükleyerek ders içeriği hakkında soru-cevap yapabilir, kavram kartları ve çalışma soruları üretebilirsiniz.*
