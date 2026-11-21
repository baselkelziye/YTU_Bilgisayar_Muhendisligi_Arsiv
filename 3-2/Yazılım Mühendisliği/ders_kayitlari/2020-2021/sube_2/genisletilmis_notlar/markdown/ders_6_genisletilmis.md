# Ders 6 Genişletilmiş Notu: Tasarım Kalıpları, Sözleşme ile Tasarım, Sıralama, Etkinlik ve Durum Şemaları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Yüksek Uyum (High Cohesion) Özeti ve Tasarım Kalıpları (Design Patterns)
- 2. Nesneye Yönelik Tasarım Sürecinin Belgelendirilmesi
- 3. Sözleşme ile Tasarım (Design by Contract)
- 4. UML Sıralama Şemaları (Sequence Diagrams) Ayrıntıları
- 5. UML Etkinlik Şemaları (Activity Diagrams): Kurallar, Kulvarlar (Swimlanes) ve NextGenPOS Uygulaması
- 6. UML Durum Şemaları (State Diagrams): Kurallar ve Yolcu Uçağı Yaşam Döngüsü Örneği
- Örnek Sorular
- Dersin Toparlaması

## 1. Yüksek Uyum (High Cohesion) Özeti ve Tasarım Kalıpları (Design Patterns)

Geçen dersin sonunda incelenen **Yüksek Uyum (*High Cohesion*)** ilkesi, bir parçanın (sınıfın) sorumluluklarının kendi içinde birbiriyle ne kadar uyumlu ve yakın görevlerle ilgili olduğunun ölçüsüdür (ekrandan, 00:35:00). Slayt 87'de yüksek uyumun sağladığı dört temel mühendislik yararı şöyle özetlenmiştir (ekrandan, 00:35:00):
- Sınıfın anlaşılma kolaylığı artar,
- Yeniden kullanılabilirlik (*reusability*) artar,
- Bakım kolaylığı artar,
- Sınıfın değişikliklerden etkilenme olasılığı düşer (ekrandan, 00:35:00).

Genellikle **düşük bağlaşım (*low coupling*)** getiren bir tasarım **yüksek uyumu (*high cohesion*)**, yüksek bağlaşım getiren bir tasarım ise düşük uyumu beraberinde getirir (ekrandan, 00:35:00).

### 1.1 Tasarım Kalıpları (Design Patterns) ve Dörtlü Çete (Gang of Four)

Hem problem alanı (iş mantığı) hem de sistem katmanı üzerinde tasarım yaparken, yılların yazılım mühendisliği deneyimini yazılı şablonlar hâlinde aktaran **Tasarım Kalıplarından (*Design Patterns*)** yararlanmak büyük önem taşır (ekrandan, 00:35:00):
- **Tanım ve Amaç:** Tasarım kalıpları, nesneye yönelik modelleme alanında **sık karşılaşılan problemlere kanıtlanmış çözüm önerileri** sunarlar (ekrandan, 00:35:00). Tasarım kalıplarına uyarak tasarım yapıldığında, gelecekte ortaya çıkabilecek gereksinim değişikliklerini bakım zorluğunu artırmadan karşılayabilen **daha esnek bir tasarım** elde edilir (ekrandan, 00:35:00).
- **Mimari Kökeni:** Bilgisayar ve yazılım mühendisliği nispeten genç bir mühendislik dalı olduğu için pek çok terimi diğer disiplinlerden alıp uyarlamıştır; "tasarım kalıbı" kavramı da **bina mimarisinden** doğmuştur. Örneğin mimaride *"İçerisinde en az yarım saat kesintisiz zaman geçirilecek her odanın en az bir penceresi olmalıdır"* kuralı klasik bir mimari tasarım kalıbıdır.

> **Ek bilgi (derste anlatılmadı):** Mimaride tasarım kalıpları (*pattern language*) kavramı büyük olasılıkla mimar Christopher Alexander tarafından 1977 yılında (*A Pattern Language* kitabıyla) ortaya atılmış; 1990'ların başında yazılım mühendisliğine uyarlanmıştır.

- **Dörtlü Çete (*Gang of Four* — GoF) Kitabı:** Nesneye yönelik yazılımda tasarım kalıplarının temelini atan eser, literatürde **"Dörtlü Çete" (*Gang of Four* — GoF)** olarak anılan dört yazarın (**Erich Gamma, Richard Helm, Ralph Johnson, John Vlissides**) 1994 yılında yayımladığı ***Design Patterns: Elements of Reusable Object-Oriented Software*** (Addison-Wesley, 1994) adlı kitaptır (ekrandan, 00:35:00). Bu kitapta yaklaşık 23–24 temel tasarım kalıbı tanımlanmıştır; daha sonra yazılan yüzlerce tasarım kalıbı kitabı da temelde bu klasik eserdeki kalıpların farklı programlama dillerine ve problem alanlarına pratik uygulamalarını anlatmaktadır.

## 2. Nesneye Yönelik Tasarım Sürecinin Belgelendirilmesi

Bir nesneye yönelik programın tasarım sürecinin belgelendirilmesinde yer alan önemli yapıtlar (*artefacts*) iki gruba ayrılır (ekrandan, 00:39:00):

1. **Vazgeçilmez (Zorunlu) Belge — Ayrıntılı UML Sınıf Şemaları (*Detailed Class Diagrams*):**
   Tasarım belgelendirmesinin olmazsa olmazıdır (ekrandan, 00:39:00). Çözümleme aşamasında oluşturulan alan modeline üye metotların, parametre/dönüş tiplerinin ve kesinleşmiş ilişki yönlerinin eklenmesiyle elde edilir. Ortaya çıkarılacak kaynak kodun doğrudan "ana oyun planı" olduğu için, bu şemaya uymayan her kod parçası derleme veya mantık hatalarına ve fazladan sınama yüküne yol açar.
2. **Tasarımın İhtiyaçlarına Göre Kullanılan Seçimlik Belgeler (ekrandan, 00:39:00):**
   - **Sözleşmeler (*Contracts*)**,
   - **UML Etkileşim Şemaları (*Interaction Diagrams*):** Nesnelerin birbirlerinin metotlarını hangi sırada ve nasıl çağırdığını gösteren koda yakın şemalardır; iki türü vardır (ekrandan, 00:39:00):
     1. *Sıralama Şemaları (Sequence Diagrams)*,
     2. *İşbirliği Şemaları (Collaboration / Communication Diagrams)*.
     > **Hocanın vurgusu (Neden *Sequence Diagram* tercih edilir?):** Hem akademik kaynaklarda hem de sektörde *Sequence Diagram*'lar *Collaboration Diagram*'lara göre çok daha fazla tercih edilir. Çünkü etkileşim şemalarının ana amacı **metot çağrım sırasını** göstermektir. *Collaboration Diagram* daha kompakt (az yer kaplayan) bir şema olsa da, çağrı sırasını yalnızca nesneler arasındaki çizgilerin üzerine yazılan `1.1.1`, `1.1.2` gibi iç içe numaralarla ifade eder ve bütüncül akışı zihinde canlandırmak zordur. *Sequence Diagram* ise nesne sayısı arttıkça sağa doğru genişlese de, düşey eksen doğrudan zamanı gösterdiği için hangi metodun hangisinden sonra veya hangisinin içinde çağrıldığını ilk bakışta net olarak ortaya koyar.
   - **UML Etkinlik Şemaları (*Activity Diagrams*)**,
   - **UML Durum Diyagramları (*State Diagrams*)** (ekrandan, 00:39:00).

## 3. Sözleşme ile Tasarım (Design by Contract)

**Sözleşme (*Contract*)**, bir kullanım senaryosunun (*use case*) ayrıntılandırılmasıyla elde edilir ve büyük ölçekli bir senaryo yerine **tek bir metot düzeyinde kodlanabilecek kritik bir sorumluluğun** nasıl çalışacağını tarif eder (ekrandan, 01:00:00). Kolay anlaşılır basit metotlar için sözleşme yazmaya gerek yoktur; çünkü sözleşme hazırlamak da ciddi bir emek gerektirir. Ancak karmaşık ve kritik metotlar için sözleşme yazmak, kodlama sırasında hiçbir ilişki veya durum güncellemesinin unutulmamasını garanti eder (ayrıca CRC kartlarıyla birlikte Scrum gözden geçirme toplantılarında da yararlı olur).

Slayt 90'da *NextGenPOS* örneğindeki satış kalemi girişi (`ürünGir` metodu) için verilen örnek sözleşme şöyledir (ekrandan, 01:00:00):

```text
Sözleşme No: 2 – Satış Kalemi Girişi
--------------------------------------------------------------------------------
İşlem:              ürünGir( barkod: String, adet: integer )
Çapraz Başvurular:  Satış kullanım senaryosu
Ön Koşullar:        Süregelen bir satış işleminin olması
Son Koşullar:       - Bir SatışKalemi örneği olan satisKalemi oluşturulmuştur.
                    - satisKalemi süregelen satis ile (Satış örneği)
                      ilişkilendirilmiştir.
                    - satisKalemi.miktar üyesine o malın satış adedi atanmıştır.
                    - satisKalemi, satılan mal ile uyuşan barkod sayesinde bir
                      Urun örneği ile ilişkilendirilmiştir.
```

### 3.1 Sözleşme Bölümleri ve Yazım Kuralları

Bir sözleşme dört bölümden oluşur ve şu kurallara uyularak yazılır (ekrandan, 01:00:00; ekrandan, 01:02:00):
1. **İşlem (*Operation*):** Metodun adı ve parametre listesi (tipleriyle birlikte) yazılır: `ürünGir(barkod: String, adet: integer)`. Mutlaka bulunmalıdır (ekrandan, 01:00:00).
2. **Çapraz Başvurular (*Cross References*):** Bu metodun hangi kullanım senaryosunun (veya başka hangi sözleşmenin/yapıtın) gerçeklenmesinde kullanıldığı belirtilir (`Satış kullanım senaryosu`). Eğer hiçbir çapraz başvuru yoksa bile başlık yazılır ve karşısına `—` (yok) çizgisi çekilir (ekrandan, 01:00:00).
3. **Ön Koşullar (*Preconditions*):** Metodun anlamlı biçimde çalıştırılabilmesi için **tüm sistemin** içinde bulunması gereken durumdur (ekrandan, 01:02:00). Örneğin `ürünGir` metodunun çalışması için *"Süregelen bir satış işleminin olması"* gerekir; henüz başlatılmış bir satış yokken `Kasa` nesnesinin `ürünGir` metodu çağrılırsa metot hiçbir işlem yapmadan geri döner.
4. **Son Koşullar (*Postconditions*):** Yalnızca **problem alanı ile ilgili nesnelerin durum değişiklikleri** hakkındadır (ekrandan, 01:02:00). Metodun çalışması tamamlandığında sistemde:
   - Hangi sınıftan yeni bir nesne örneği (*instance of*) oluşturulduğu (*"Bir `SatışKalemi` örneği olan `satisKalemi` oluşturulmuştur"*),
   - Hangi nesnenin hangi üye alanına ne değer atandığı (*"`satisKalemi.miktar` üyesine o malın satış adedi atanmıştır"*),
   - Hangi nesneler arasında yeni sahiplik/ilişki kurulduğu veya mevcut bir ilişkinin kırıldığı (*"`satisKalemi` süregelen `satis` ile ilişkilendirilmiştir"* ve *"barkod sayesinde bir `Urun` örneği ile ilişkilendirilmiştir"*) eksiksiz yazılır (ekrandan, 01:00:00; ekrandan, 01:02:00).

> **Hocanın vurgusu:**
> - Son koşullarda **edilgen geçmiş zaman** (*"... oluşturulmuştur, ... ilişkilendirilmiştir, ... atanmıştır"*) kullanılması, bunların işlemin sonunda tamamlanmış eylemler olduğunu vurgulamak açısından yerinde olacaktır (ekrandan, 01:02:00). (Dikkat: Kullanım öyküsü metinlerinde *etken geniş zaman* kullanılırken, metot sözleşmesinin son koşullarında *edilgen geçmiş zaman* kullanılır.)
> - Sözleşme içerisinde **ilişkilerin kurulmasını belirtmeyi asla unutmayın!** Sözleşme yazarken fark ettiğiniz yeni bir ilişki ihtiyacı, geri dönüp problem alanı çözümlemesinde (alan modelinde) güncelleme yapmanıza da yol açabilir (ekrandan, 01:02:00).

## 4. UML Sıralama Şemaları (Sequence Diagrams) Ayrıntıları

Nesneye Dayalı Programlama dersinde temelleri görülen **UML Sıralama Şemaları (*Sequence Diagrams*)**, tasarım aşamasında nesneler arasındaki metot çağrılarını zaman sırasıyla modellemek için kullanılır. Slayt 92'de şemanın tüm gösterim kuralları özetlenmiştir (ekrandan, 01:05:00):

```text
  +----------------+                      +----------------+
  | nesne1: Sınıf1 |                      | nesne2: Sınıf2 |
  | -------------- |                      | -------------- |
  +-------+--------+                      +-------+--------+
          :                                       :
         +-+ [koşul] değişken := birMetot(        :
         | |         param1: Tip, ... )           :
         | |------------------------------------->+-+
         | |                                      | |  --> Mesaj (metot çağırma)
         | |< - - - - - - - - - - - - - - - - - - +-+  <-- Geri dönüş (ihmal edilebilir)
         | |                                      :
         | |----+                                 :    [koşul]
         | | +-+| Nesnenin kendi                  :   --------> Koşullu mesaj (if)
         | | | || metodunu çağırması              :
         | |<--+|                                 :   * [koşul]
         +-+    |                                 :   --------> Döngülü mesajlar (for, while)
          :                                       :
                                                  :      new
                                                  :   --------> Nesne oluşturma (constructor)
```

### 4.1 Sıralama Şeması Çizim Kuralları ve Kritik Uyarılar

1. **Nesne Kutusu ve Alt Çizgi Zorunluluğu:** En üstteki dikdörtgenlerin içine `nesne1: Sınıf1` yazılır ve **altı mutlaka çizilir** (ekrandan, 01:05:00). Eğer nesnenin adından hangi sınıfa ait olduğu zaten anlaşılıyorsa (ör. `arabam`) sınıf adı yazılmayabilir (`<u>arabam</u>`); tersine nesnenin adı önemli değilse yalnız iki nokta üst üste ve sınıf adı yazılabilir (`<u>: Sınıf2</u>`). Ancak her iki durumda da sınıf şemasındaki sınıf kutusuyla karışmaması için **alt çizgi (*underline*) zorunludur**.
2. **Yaşam Çizgisi (*Lifeline*) ve Etkinlik Çubuğu (*Activation Bar*):** Nesne kutusundan aşağı inen kesikli çizgi nesnenin yaşam çizgisini, üzerindeki ince uzun dikdörtgenler (*activation bar*) ise o anda o nesnenin bir metodunun çağrılmış ve çalışmakta olduğunu gösterir (ekrandan, 01:05:00).
3. **Metot Çağrısı, Atama ve Geri Dönüş:**
   - Metot çağrısı içi dolu okla (`--->`) gösterilir; üzerine `[koşul] değişken := birMetot(param1: Tip, ...)` yazılır (buradaki `:=` Pascal tarzı atama gösterimidir, normal `=` de yazılabilir) (ekrandan, 01:05:00).
   - Yapıcı metot (*constructor*) çağrısı ok üzerine `new` yazılarak gösterilir (ekrandan, 01:05:00).
   - Metodun tamamlanıp geri dönmesi kesikli okla (`<---`) gösterilir (ihmal edilebilir; ancak özel bir değer döndürüyorsa kesikli ok üzerine etiket olarak yazılabilir) (ekrandan, 01:05:00).
   - Bir nesnenin kendi içindeki başka bir yardımcı metodu çağırması (*self-call*), mevcut *activation bar* üzerine ikinci bir katman *activation bar* çizilip okun kendine döndürülmesiyle gösterilir (ekrandan, 01:05:00).
4. **Koşullu (`if`) ve Döngülü (`for`/`while`) Mesajlar ile Çerçeve Gösterimi:**
   - Tek bir metot çağrısı koşula bağlıysa başına `[koşul]`, döngüye bağlıysa başına `* [koşul]` (koşulsuz sabit `for` döngüsüyse yalnız `*`) konulur (ekrandan, 01:05:00).
   - **Pratik Alternatif (Çerçeve / *Frame* Gösterimi):** Eğer aynı `if` koşuluna veya aynı döngüye bağlı ardışık 3–5 metot çağrısı varsa, her okun başına tekrar tekrar `[koşul]` yazmak yerine bu ardışık metot oklarının tamamını içine alan bir dikdörtgen çerçeve çizilir ve sol üst köşesine bir kez `[koşul]` (veya `* [koşul]`) yazılır (*Violet UML* bu çerçeveyi doğrudan desteklemediği için şema PNG olarak dışa aktarıldıktan sonra bir resim düzenleyiciyle çerçeve eklenebilir).

> **Hocanın vurgusu (İki Kritik Hata Noktası):**
> 1. **Metodun Ait Olduğu Sınıf:** `nesne1: Sınıf1`'den `nesne2: Sınıf2`'ye doğru `birMetot()` oku çizilmişse, `birMetot()` çağrıyı gönderen `Sınıf1`'in değil, **çağrıyı alan `Sınıf2`'nin metodudur**! Dolayısıyla ayrıntılı sınıf şemasında `Sınıf2` kutusunun içinde `birMetot()` mutlaka yer almalıdır.
> 2. **Zaman ($y$) Ekseninde İç İçe Çağrı Hizası:** Sıralama şemasında aşağı doğru inildikçe zaman ilerler. Eğer `nesne2` üzerinde çalışan `birMetot()` kendi çalışması sırasında üçüncü bir nesnenin `ikinciMetot()`'unu çağırıyorsa, bu iç çağrının gidiş ve dönüş okları dış çağrının gidiş okundan **daha aşağıda**, dönüş okundan ise **daha yukarıda** (arada belirgin bir düşey mesafe bırakılarak) çizilmelidir. İç çağrıyı dış çağrıyla aynı hizaya veya daha yukarıya çizmek "zamanda geriye gitmek" anlamına gelir ve hatadır.

## 5. UML Etkinlik Şemaları (Activity Diagrams): Kurallar, Kulvarlar (Swimlanes) ve NextGenPOS Uygulaması

**UML Etkinlik Şemaları (*Activity Diagrams*)**, denetim ve program akışını gerçekleşen olaylar ve eylemler üzerinden gösteren diyagramlardır (ekrandan, 01:20:00). Sıralama şemalarından (*sequence diagrams*) farklı olarak:
1. **Çok iş parçacıklı (*multi-threaded* / paralel) işlemleri** doğrudan gösterebilir,
2. Yalnızca yazılımcıların değil, **müşterinin ve konu alanı uzmanının da** kolayca anlayabileceği bir soyutlama düzeyindedir,
3. Kullanım şemalarında (*use case diagrams*) gösterilmesi yasak olan **"hangi işin hangi sırada ve kim tarafından yapıldığı"** bilgisini göstermenin standart yoludur.

### 5.1 Çizim Kuralları ve Havayolu Check-in Örneği

Slayt 94'te etkinlik şemasının temel sembolleri ve bir havayolu firmasının **Check-in** sürecine ait örnek çizim verilmiştir (ekrandan, 01:20:00):

```text
   SEMBOLLER                                      ÖRNEK ÇİZİM (Check-in)
   ---------                                      ----------------------
                  Denetim akışı             +----------------------------------+
   ------------>                            | Yolcu check-in bankosuna gelir.   \
                                            |                                   /
        (*)       Etkinlik başlangıcı       +-----------------+----------------+
                                                              |
   +---------+    Sinyal alma /                               v
   |          \   Olay (event) kabul etme          .--------------------.
   |          /                                    | Yolcu check-in     |
   +---------+                                     | yapar.             |
                                                   '---------+----------'
   .---------.                                               |
   |         |    Eylem                                      v
   '---------'                                             .---.
                                                          /     \          [else]
       / \        Karar verme (if)                       <  if?  >-----------------------> (o)
       \ /                                                \     /
                                                           '---'
   ===========    Eşgüdüm (Fork / Join)                      | [check-in başarılı]
                                                             v
       (o)        Etkinlik sonu             ==================================== (Fork)
                                                   |                    |
   +---------+                                     v                    v
   |          \   Sinyal gönderme       .--------------------. .--------------------.
   |          /                         | Yolcu uçağa biner  | | Bagajlar uçağa     |
   +---------+                          '---------+----------' | yüklenir           |
                                                  |            '---------+----------'
                                                  v                      v
                                            ==================================== (Join)
                                                             |
                                                             v
                                                   .--------------------.
                                                   | Uçak piste yönelir |
                                                   '---------+----------'
                                                             |
                                                             v
                                                            (o)
```

Sembollerin özellikleri şunlardır (ekrandan, 01:20:00):
- **Etkinlik Başlangıcı ve Sinyal Alma / Gönderme:** Bir etkinlik şeması içi dolu siyah daire (`(*)`) ile başlayabileceği gibi, sağ kenarı içeri girintili bayrak şeklindeki **Sinyal alma / Olay (*event*) kabul etme** bileşeniyle de başlayabilir (ör. `Yolcu check-in bankosuna gelir.`). Sinyal alma sembolü aynı zamanda bir zamanlayıcının (*timer*) dolması olayını göstermek için de kullanılır. Eğer süreç başka bir aktöre veya sürece sinyal/olay fırlatıyorsa sağ kenarı dışa sivri beşgen olan **Sinyal gönderme** sembolü kullanılır (bu iki beşgen yan yana getirildiğinde bir yapboz gibi tam bir dikdörtgen oluşturur).
- **Eylem (*Action*) ve Karar Verme (`if`):** Yürütülen işlemler kenarları yuvarlatılmış dikdörtgenler içine yazılır. Koşullu dallanmalar **elmas (`<>`)** ile gösterilir ve elmastan çıkan her okun üzerine köşeli parantez içinde koşul (`[check-in başarılı]`, `[else]`) yazılır.
  - Eğer `if - else if - else` şeklinde üçlü (örneğin pandemi sokağa çıkma kısıtlamalarında `[yaş 0-17]`, `[yaş 18-59]`, `[yaş >= 60]`) bir karar varsa, elmasın bir köşesi giriş için kullanıldığından kalan **3 köşesinden 3 ayrı koşul oku** çıkarılabilir; ya da 3'ten fazla dal varsa ardışık elmaslar (`if` $\rightarrow$ `[else]` $\rightarrow$ ikinci `if` elması) birbirine bağlanır.
- **Eşgüdüm Çubuğu (*Synchronization Bar* — `fork` ve `join`):** Kalın yatay çubuk paralel (*multi-threaded*) çalışmayı modeller (ekrandan, 01:20:00):
  - Çubuğa **1 ok girip birden fazla ok çıkıyorsa** bu C/işletim sistemleri terminolojisindeki **`fork`** komutuna karşılık gelir ve paralel süreçleri başlatır (`Yolcu uçağa biner` ve `Bagajlar uçağa yüklenir` işlemleri eşzamanlı yürür).
  - Çubuğa **birden fazla ok girip 1 ok çıkıyorsa** bu **`join`** komutuna karşılık gelir. Buradaki eşgüdüm **bloklayıcıdır (*blocking*)**: paralel kollardaki işlemlerin tamamı (hem tüm yolcuların uçağa binmesi hem de tüm bagajların yüklenmesi) bitmeden tek akıştan (`Uçak piste yönelir`) devam edilemez.

### 5.2 Kulvarlar (Swimlanes) ve Aktörler Arası Bilgi Akışı

Her eylem kutusunun içine işi yapan aktörün adını tekrar tekrar yazmak yerine, olimpik yüzme havuzu kulvarları (**swimlanes**) kullanılarak her aktöre dikey bir sütun ayrılır (ekrandan, 01:26:00):

```text
+-----------------------------------+-----------------------------------+
|          Yer Hizmetleri           |         Müşteri Hizmetleri        |
+-----------------------------------+-----------------------------------+
|                                   |                 (*)               |
|                                   |                  |                |
|                                   |                  v                |
|     .------------------------.    |     .------------------------.    |
|     | Yolcu listesini oluştur|<---|-----|  Yolcu listesini iste  |    |
|     '-----------+------------'    |     '------------------------'    |
|                 |                 |                                   |
|                 v                 |                                   |
|     .------------------------.    |     .------------------------.    |
|     | Yolcu listesini gönder |----+---->| Yolcu listesini kabul  |    |
|     '------------------------' [yolcu   | et                     |    |
|                                listesi] '-----------+------------'    |
|                                   |                 |                 |
|                                   |                 v                 |
|                                   |     .------------------------.    |
|                                   |     | Kesinleşmiş yolcu      |    |
|                                   |     | listesini veritabanına |    |
|                                   |     | kaydet                 |    |
|                                   |     '-----------+------------'    |
|                                   |                 |                 |
|                                   |                 v                 |
|                                   |                (o)                |
+-----------------------------------+-----------------------------------+
```

> **Hocanın vurgusu (Elmastan Çıkmayan Ok Üzerindeki Köşeli Parantez):** Yukarıdaki şemada `Yolcu listesini gönder` eyleminden `Yolcu listesini kabul et` eylemine giden okun üzerinde **`[yolcu listesi]`** yazmaktadır (ekrandan, 01:26:00). Dikkat edilirse bu ok bir karar elmasından (`<>`) çıkmamaktadır! Etkinlik şemasında iki eylem arasındaki düz ok üzerinde köşeli parantez içinde yazılan ifade bir `if` koşulu değil, **bir eylemden diğerine denetim akışıyla birlikte aktarılan bilgi, belge veya nesnedir** (örneğin öğrencinin hazırladığı staj formlarını bölüm sekreterliğine teslim ederken ok üzerinde `[staj evrakları]` yazması gibi).

### 5.3 NextGenPOS Satış İşlemi Etkinlik Şeması Uygulaması

Hoca dersin son saatinde *NextGenPOS* satış işlemi kullanım öyküsünü (ana öykü ve alternatif öyküler dahil) etkinlik şemasına dönüştürmüştür (ekrandan, 02:38:30):

```text
                                                 (*)
                                                  |
                                                  v
                                        .-------------------.
                                        | Satış işlemi      |
                                        | başlat            |
                                        '---------+---------'
                                                  |
  +-----------------------------------------------+----------------------------------+
  | Bkz. Ürün iptali senaryosu                    |                                  |
  +-------------------------------+               v                                  |
  |                                     .-------------------.                        |
  |                                     |    Barkod gir     |<-------------------+   |
  |                                     '---------+---------'                    |   |
  |                                               |                              |   |
  |                                               | barkod geçerli mi?           |   |
  |                                               v                              |   |
  |                                             .---.        [hayır /            |   |
  |                                            /     \        geçersiz barkod]   |   |
  |                                           <  if?  >-----> [Uyarı mesajı ver]-+   |
  |                                            \     /                           |   |
  |                                             '---'                            |   |
  |                                               | [evet / geçerli barkod]      |   |
  |                                               v                              |   |
  |                                     .-------------------.                    |   |
  |                                     | Satış kalemi      |                    |   |
  |                                     | oluştur           |                    |   |
  |                                     '---------+---------'                    |   |
  |                                               |                              |   |
  |                                               | alınacak mal kaldı mı?       |   |
  |                                               v                              |   |
  |                                             .---.                            |   |
  |                                            /     \       [evet / else]       |   |
  |                                           <  if?  >--------------------------+   |
  |                                            \     /                               |
  |                                             '---'                                |
  |                                               | [hayır / başka ürün yok]         |
  |                                               v                                  |
  |                                     .-------------------.                        |
  |                                     | Sistem toplam     |                        |
  |                                     | bedeli KDV ile    |                        |
  |                                     | birlikte hesaplar |                        |
  |                                     '---------+---------'                        |
  |                                               |                                  |
  |                                               v                                  |
  |                                     .-------------------.                        |
  |                                     | Toplamı bildir ve |                        |
  |                                     | ödeme iste        |                        |
  |                                     '---------+---------'                        |
  +-----------------------------------------------+----------------------------------+
                                                  |
                                                  v
                                        .-------------------.
                                        | Ödeme al (tahsil) |
                                        '---------+---------'
                                                  |
                                                  v
                                        .-------------------.
                                        | Harici sistemlere |
                                        | bilgi aktarımı    |
                                        '---------+---------'
                                                  |
                                                  v
                                        .-------------------.
                                        | Makbuz (fiş) ver  |
                                        '---------+---------'
                                                  |
                                                  v
                                                 (o)
```

Şema çizilirken dikkat edilen iki önemli tasarım tekniği şunlardır (ekrandan, 02:38:30):
1. **Ana ve Alternatif Öykülerin Birlikte Düşünülmesi:** Etkinlik şeması çizerken önce yalnız ana öyküyü çizip sonra alternatif öyküleri eklemeye çalışmak okların silinip yeniden çizilmesine yol açar. Bu yüzden 3. adımdan (`Barkod gir`) itibaren alternatif öyküler (`3a. Geçersiz barkod` ve `3-7a. Ürün silme`) eşzamanlı olarak şemaya yerleştirilmiştir.
2. **Adım Aralığı (`3-7a`) Kapsayan Alternatif Senaryolar İçin Çerçeve Kullanımı:** Müşterinin bir ürünü alışverişten çıkartmak istemesi (`3-7a`), 3. adım (`Barkod gir`) ile 7. adım (`Toplamı bildir ve ödeme iste`) arasındaki herhangi bir anda gerçekleşebilir. Her eylemin altına ayrı bir *"Ürün çıkartılacak mı?"* elması koymak şemayı okunmaz hâle getireceğinden, 3. adımdan 7. adıma kadar olan tüm eylemler büyük bir çerçeve içine alınmış ve sol üst köşesine **`Bkz. Ürün iptali / silme senaryosu`** yazılmıştır (ekrandan, 02:38:30).

## 6. UML Durum Şemaları (State Diagrams): Kurallar ve Yolcu Uçağı Yaşam Döngüsü Örneği

**UML Durum Şemaları (*State Diagrams*)**, problem alanındaki önemli bir varlığın yaşam döngüsü boyunca içinde bulunabileceği **durumları (*states*)** ve hangi **olay (*event*)** gerçekleştiğinde hangi durumdan hangi duruma geçeceğini (veya aynı durumda kalacağını) gösteren diyagramlardır (ekrandan, 01:40:00).

### 6.1 Çizim Kuralları ve Durum vs. Olay Ayrımı

Durum şemasının dört temel bileşeni vardır (ekrandan, 01:40:00):
- **Başlangıç:** İçi dolu siyah daire (`(*)`). (Eğer varlık doğar doğmaz herhangi bir olaya gerek kalmadan varsayılan bir duruma giriyorsa başlangıçtan ilk duruma etiketsiz düz bir ok çizilebilir.)
- **Bitiş:** Hedef tahtası (`(o)` — çember içinde siyah daire).
- **Durum (*State*):** Kenarları yuvarlatılmış dikdörtgen.
- **Durum Geçişi / Olay (*Transition / Event*):** Düz çizgi ve ucu açık ok (`--->`). Üzerindeki etiket **`«M»`** (*Mutate* — değişim/mutasyon stereotipi) ile başlar ve **`/`** (eğik çizgi) ile biter:
  ```text
  «M» OlayAdı [koşul] / EYLEM_KOMUTLARI;
  ```

> **Hocanın vurgusu (En Sık Yapılan Hata — Durum ile Olayı Karıştırmak):**
> Durum şeması çizerken yapılan en büyük hata, bir **olayı (eylemi)** durum kutusunun içine yazmak veya bir **durumu** geçiş okunun üzerine yazmaktır.
> - Например *"Uçuş atamak"* veya *"Uçağın teslim edilmesi"* bir durum değil, anlık gerçekleşen birer **olaydır** (`«M»` ile ok üzerine yazılır). Buna karşılık uçağın *"Sipariş aşamasında"*, *"Bakımda"*, *"Kullanıma hazır"* veya *"Bakım sırası beklemede"* olması ise uçağın belirli bir süre boyunca içinde bulunduğu **durumlardır** (kutuların içine yazılır).
> - Hoca bunu kendi günlük hayatından bir örnekle açıklamıştır: Bir öğretim üyesinin şu an içinde bulunduğu durum **`Ders verme durumu`**dur. *"3 saatlik ders süresinin dolması"* bir **olaydır**; bu olay gerçekleştiğinde **`Dinlenme durumu`**na geçilir. *"Mola süresinin bitmesi (timeout)"* olayıyla **`Çalışma durumu`**na, *"Mesai saatinin bitmesi"* olayıyla **`Eve gidiş (trafikte olma) durumu`**na, *"Eve varma"* olayıyla da **`Babalık görevini yapma durumu`**na geçilir.

### 6.2 Yolcu Uçağı Yaşam Döngüsü Örneği (3 Aşamalı Geliştirme)

Slayt 98, 99 ve 101'de bir havayolu firmasının filosundaki **Yolcu Uçağı** varlığının durum şeması adım adım zenginleştirilmiştir (ekrandan, 01:40:00; ekrandan, 01:44:00; ekrandan, 01:52:00):

```text
   (*) (Başlangıç)
    |
    | «M» Uçağın alım emri verildi /
    | CREATE;
    | SET kayıtNo = (INPUT);
    v
.---------------------.
| Sipariş aşamasında  |
|  (Sipariş Edildi)   |
'----------+----------'
           |
           | «M» Uçak teslim edildi /
           | SET teslimTarihi = (INPUT);
           v
      .---------.        «M» Uçak emekli edildi / DELETE;
      | Bakımda |---------------------------------------------------> (o) (Bitiş)
      '---------'
       ^   ^   \
      /     \   \ «M» Bakım tamamlandı /
     /       \   v
    |         \ .-----------------.
    |          \| Kullanıma hazır |---+ «M» Uçuş ata /
    |           |                 |<--+ «M» Uçuş yap /
    |           '--------+--------'
    |     «M» Arıza      |
    |     bulundu /      | «M» Bakım isteği geldi /
    |                    v
    |    .-------------------------------------------.
    |    | Bakım sırası beklemede                    |
    +----| «M» Uçuş yap [atanmış uçuş varsa] /       |
«M» Uçuş '-------------------------------------------'
yap [atanmış uçuş kalmamışsa] /
```

1. **Temel Yaşam Döngüsü (Slayt 98) (ekrandan, 01:40:00):**
   - `«M» Uçağın alım emri verildi /` olayıyla uçak **`Sipariş aşamasında`** durumuna girer.
   - `«M» Uçak teslim edildi /` olayı gerçekleştiğinde uçak doğrudan uçuşa verilmez, önce **`Bakımda`** durumuna alınır.
   - `«M» Bakım tamamlandı /` olayıyla **`Kullanıma hazır`** durumuna geçer; bu durumdayken `«M» Arıza bulundu /` olayı gerçekleşirse derhal tekrar **`Bakımda`** durumuna döner.
   - Uçak kullanım ömrünü tamamladığında `«M» Uçak emekli edildi /` olayıyla yaşam döngüsü sonlanır (`(o)`).
2. **Koşullu Geçişler ve Durum Değiştirmeyen İç Olaylar (Slayt 99) (ekrandan, 01:44:00):**
   - Uçak **`Kullanıma hazır`** durumundayken kendisine uçuş atanması (`«M» Uçuş ata /`) veya uçuş gerçekleştirmesi (`«M» Uçuş yap /`) uçağın durumunu değiştirmez; bu durum kendinden kendine dönen okla (veya doğrudan durum kutusunun içine yazılarak) gösterilir.
   - Uçak kullanıma hazırken acil bir arıza değil de rutin bir **`«M» Bakım isteği geldi /`** olayı gerçekleşirse, uçak hemen bakıma alınmaz; **`Bakım sırası beklemede`** durumuna geçer. Bu sırada önceden planlanmış uçuşları varsa onları yapmaya devam eder (`«M» Uçuş yap [atanmış uçuş varsa] /` — kutu içinde iç olay olarak gösterilmiştir). Planlanan uçuşlar bittiğinde (`«M» Uçuş yap [atanmış uçuş kalmamışsa] /`) uçak **`Bakımda`** durumuna geçer (ekrandan, 01:44:00).
   - *(Not: Hoca bu şemada `«M» Uçuş yap` olayının üç farklı yerde farklı koşullarla geçtiğine dikkat çekerek, durum şemalarını ilk bakışta okumanın etkinlik şemalarına göre daha fazla dikkat gerektirdiğini vurgulamıştır.)*
3. **Durum Geçişi Sırasında İşlenen Komutların Gösterimi (Slayt 101) (ekrandan, 01:52:00):**
   - Eğik çizginin (`/`) sağ tarafına, ilgili olay gerçekleştiğinde yürütülecek sözde kod (*pseudocode*), SQL sorguları veya veritabanı saklı yordamları (*stored procedures*) noktalı virgülle (`;`) ayrılarak yazılır:
     - Alım emri verildiğinde: `CREATE; SET kayıtNo = (INPUT);` (veritabanında uçak nesnesi için yeni kayıt açılır ve kullanıcıdan kayıt numarası alınır).
     - Uçak teslim edildiğinde: `SET teslimTarihi = (INPUT);` (teslim tarihi kullanıcıdan alınıp kaydedilir).
     - Uçak emekli edildiğinde: `DELETE;` (kayıt silinir; eğer resmi/mali denetim için kaydın silinmeyip saklanması gerekiyorsa `SET durum = pasif;` şeklinde de yazılabilir).
   - Aynı ok üzerinde birden fazla olay ve komut yazıldığında (ör. `«M» Uçuş yap / sp_uc; «M» Uçuş ata / sp_ata;`), **`«M»`** stereotipi bir önceki olayın komutunun bittiğini ve yeni olayın başladığını, **`/`** işareti ise olay adıyla çalıştırılacak komutun sınırını görsel olarak ayırır.

## Örnek Sorular

### Soru 1: Metot Sözleşmesi (Design by Contract) Hazırlama (Ekrandan, 01:00:00)

**Soru:** *NextGenPOS* perakende satış sisteminde, süregelen bir satış işlemine yeni bir ürün kalemi ekleyen `ürünGir(barkod: String, adet: integer)` metodu için standartlara uygun bir **Tasarım Sözleşmesi (*Contract*)** yazınız.

**Cevap (derste verildi):**
Bölüm 3'te verilen `Sözleşme No: 2 – Satış Kalemi Girişi` tablosudur (ekrandan, 01:00:00):
- **İşlem:** `ürünGir( barkod: String, adet: integer )`
- **Çapraz Başvurular:** Satış kullanım senaryosu
- **Ön Koşullar:** Süregelen bir satış işleminin olması.
- **Son Koşullar (edilgen geçmiş zamanla ve tüm nesne/ilişki değişimlerini kapsayarak):**
  1. Bir `SatışKalemi` örneği olan `satisKalemi` oluşturulmuştur.
  2. `satisKalemi` süregelen `satis` ile (`Satış` örneği) ilişkilendirilmiştir.
  3. `satisKalemi.miktar` (veya `adet`) üyesine o malın satış adedi atanmıştır.
  4. `satisKalemi`, satılan mal ile uyuşan barkod sayesinde bir `Urun` örneği ile ilişkilendirilmiştir.

---

### Soru 2: Durum Şemasının (State Diagram) Yorumlanması ve Komutların Eklenmesi (Ekrandan, 01:44:00 – 01:52:00)

**Soru:** Bölüm 6.2'de verilen Yolcu Uçağı Durum Şemasına (*State Diagram*) göre:
1. `Kullanıma hazır` durumundaki bir uçak için `«M» Arıza bulundu /` olayı ile `«M» Bakım isteği geldi /` olayı gerçekleştiğinde uçağın davranışındaki fark nedir? `«M» Uçuş yap` olayının farklı durumlardaki davranışını açıklayınız.
2. Uçağın sipariş edilmesi, teslim alınması ve emekli edilmesi olaylarında veritabanı/nesne düzeyinde çalıştırılacak komutlar şemada nasıl gösterilir?

**Cevap (derste verildi):**
1. `Kullanıma hazır` durumundaki bir uçakta **arıza bulunursa** (`«M» Arıza bulundu /`) uçak beklemeden doğrudan `Bakımda` durumuna geçer. Buna karşılık **bakım isteği gelirse** (`«M» Bakım isteği geldi /`), uçak önce `Bakım sırası beklemede` durumuna alınır. Bu durumdayken önceden planlanmış uçuşları varsa (`[atanmış uçuş varsa]`) `«M» Uçuş yap` olaylarını kabul ederek uçuşlarını tamamlar ve aynı durumda kalır; planlanan uçuşlar bittiğinde (`«M» Uçuş yap [atanmış uçuş kalmamışsa] /`) `Bakımda` durumuna geçer (`Kullanıma hazır` durumundayken ise `«M» Uçuş yap /` olayı koşulsuz olarak çalışır ve uçağı yine `Kullanıma hazır` durumunda tutar) (ekrandan, 01:44:00).
2. Komutlar olay adındaki `/` işaretinden sonra noktalı virgülle yazılarak gösterilir (ekrandan, 01:52:00):
   - Sipariş emrinde: `«M» Uçağın alım emri verildi / CREATE; SET kayıtNo = (INPUT);`
   - Teslim alındığında: `«M» Uçak teslim edildi / SET teslimTarihi = (INPUT);`
   - Emekli edildiğinde: `«M» Uçak emekli edildi / DELETE;` (veya kayıt saklanacaksa `SET durum = pasif;`).

## Dersin Toparlaması

Bu derste ilk olarak **Yüksek Uyum (*High Cohesion*)** ilkesinin yararları özetlenmiş ve nesneye yönelik tasarımda sık karşılaşılan problemlere esnek çözümler sunan **Tasarım Kalıpları (*Design Patterns* — Dörtlü Çete / GoF)** kavramı tanıtılmıştır. Ardından tasarım sürecinin belgelendirilmesinde kullanılan yapıtlar incelenmiş; kodun ana planı olan **Ayrıntılı UML Sınıf Şemalarının** zorunlu olduğu, diğer şema ve belgelerin ise ihtiyaca göre seçildiği vurgulanmıştır.

Dersin devamında kritik metotların ön ve son koşullarını tanımlayan **Sözleşme ile Tasarım (*Design by Contract*)**, nesneler arası metot çağrı sırasını zaman ekseninde gösteren **UML Sıralama Şemaları (*Sequence Diagrams*)**, çok iş parçacıklı (*fork/join*) süreçleri ve aktör kulvarlarını (*swimlanes*) modelleyen **UML Etkinlik Şemaları (*Activity Diagrams*)** ile varlıkların yaşam döngüsü durumlarını ve olay geçişlerini (`«M» Olay [koşul] / Komut;`) modelleyen **UML Durum Şemaları (*State Diagrams*)** kuralları ve örnekleriyle işlenmiştir. Son ders saatinde *NextGenPOS* satış senaryosunun etkinlik şeması *Violet UML Editor* üzerinde çizilmiştir; bir sonraki derste aynı örnek üzerinden durum şeması ve metotları eklenmiş ayrıntılı tasarım sınıf şeması oluşturulacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
