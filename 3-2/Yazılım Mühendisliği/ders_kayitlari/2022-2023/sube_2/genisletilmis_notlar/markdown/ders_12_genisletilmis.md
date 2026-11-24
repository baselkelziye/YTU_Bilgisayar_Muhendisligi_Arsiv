# Ders 12 Genişletilmiş Notu: Uygulama: Otobüs Bileti Rezervasyon Sistemi için Sınıf, Sıralama, Etkinlik ve Durum Şemaları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Uygulama Sorusu ve Kullanım Senaryosu
- 2. Tasarım Sınıf Şeması
- 3. Sıralama Şeması: Rezervasyon Yapma
- 4. Etkinlik Şeması: Rezervasyon Yapma
- 5. Durum Şeması: Koltuk Nesnesi
- Örnek Sorular
- Dersin Toparlaması

## 1. Uygulama Sorusu ve Kullanım Senaryosu

Bu ders bir uygulama oturumudur. Tek bir senaryo üzerinden dört UML şeması çizildi: sınıf şeması (class diagram), sıralama şeması (sequence diagram), etkinlik şeması (activity diagram) ve durum şeması (state diagram). Çizimler Violet UML Editor ile yapıldı.

### 1.1 Problem tanımı

Ekrandaki soru metni şöyledir (ekrandan, 00:15:00):

> Bir yolcunun yolculuk etmek istediği seferi, istediği seferle ilgili otobüsü ve ilgili otobüsteki koltuğu seçmesini sağlayan ve ilgili bilgilerin rezervasyon bilgisi olarak kaydedildiği bir sistem tasarlanmak istenmektedir.

Kısaca yolcu nereye ve ne zaman gitmek istediğini girer, sistem hangi otobüslerin hangi saatlerde gittiğini listeler, yolcu bunlardan birini ve o otobüsteki boş koltuklardan birini seçerek rezervasyon yapar.

### 1.2 Kullanım senaryosu: Otobüs Bileti Alımı

Senaryo metni ekranda şu alanlarla verildi (ekrandan, 00:15:00):

- Birincil Aktör: Yolcu.
- Diğer İlgililer: Bilet Satış Sistemi.
- İlgi Alanları: Yolcu koltuğunu kolayca seçebilip biletini kolaylıkla alabilmek ister.
- Ön Koşullar: Bilet satış sistemine tüm sefer bilgileri girilmiştir.
- Son Koşullar: Yolcu biletini satın almıştır.

Ön koşul, hangi gün hangi otobüsün nereden nereye gittiği bilgisinin sistemde bulunmasıdır; kullanıcı ancak bu sayede seferleri görüp seçebilir. Son koşulda yolcunun rezervasyonunu yapıp biletini satın alabilmiş olması istenir.

Ana senaryo (ekrandan, 00:15:00):

1. Yolcu seyahat yapmak isteyeceği seyahat bilgilerini girer ve bu bilgilere ait otobüs seferleri sistem tarafından gösterilir.
2. Yolcu bir otobüs seçer.
3. Yolcu seçilen otobüste bir koltuk seçer ve sistem koltuğun uygunluğunu kontrol eder.
4. Yolcu seçimlerini yaptıktan sonra rezervasyon bilgilerini girer ve koltuk için sistem kaydı rezerve olarak işlenir.
5. Yolcu rezervasyonu için ödeme yapar ve koltuk için biletin alındığı sisteme işlenir.

Dördüncü adımda girilen rezervasyon bilgileri yolcunun iletişim bilgileridir. Beşinci adımda ödeme alınınca koltuğun kesin olarak bu yolcuya satıldığı bilet oluşturulur.

### 1.3 Alternatif senaryolar

Alternatif senaryo metni ekranda kaydın alındığı karede görünmüyor; aşağıdakiler anlatımdan alındı.

- Üçüncü adımın alternatifi: Sistem seçilen koltuğa izin vermeyebilir. Koltuk doluysa bunu bildirir ve yolcudan yeni bir koltuk seçmesini ister.
- Dördüncü adımın alternatifi: Yolcu rezervasyon yapıp ödeme yapmazsa koltuk 12 saatlik bir süre boyunca onun adına rezerve tutulur. Bu süre içinde ödeme yapılmamışsa sistem rezervasyonu iptal eder ve koltuk yeniden boş olarak işaretlenir.

<!-- BELİRSİZ: Anlatımda hem "12 saat boyunca rezerve ediyoruz" hem de "son 12 saat kalaya kadar", "en az 12 saat kalaya kadar ödeme" geçiyor. Sürenin rezervasyondan sonraki 12 saat mi, yoksa sefere 12 saat kalana kadar mı olduğu net değil. Durum şemasında yalnız "Yolcu 12 saate kadar ödeme yapmaz" yazıyor. -->

## 2. Tasarım Sınıf Şeması

### 2.1 Analizden tasarıma

Önceki uygulamada analiz tarafında bir sınıf şeması çizilmişti. Orada sınıf adını, niteliklerini (attribute) ve sınıflar arası ilişkileri çizmek yeterliydi; metotları ayrıntılandırmaya gerek yoktu. Bu derste tasarım tarafındayız. Tasarım bir sonraki, daha ayrıntılı aşamadır: bu sınıftaki nesnelerin hangi işleri yapabildiği, yani metotlar da parametreleri ve dönüş tipleriyle gösterilir.

> **Hocanın vurgusu:** Analiz sınıf şemasında metotlara gerek yoktu; tasarım sınıf şemasında metotlar da ayrıntılı yazılır.

Üye alanlar her zaman private yapılır ve başlarına `-` konur; metotlar public olarak `+` ile gösterilir.

### 2.2 Yolcu sınıfı

İlk sınıf Yolcu'dur (ekrandan, 00:20:00 ve 00:25:00):

```text
Yolcu
- ad: String
- soyad: String
- tcNo: String
- iletisimBilgileri: String
+ getAd(): String
+ getSoyad(): String
+ getTcNo(): String
+ getIletisimBilgileri(): String
```

T.C. kimlik numarası tamsayı tipinde de düşünülebilir, ama String tutmak daha doğrudur, çünkü bu değerle toplama, çıkarma gibi sayısal işlem yapılmaz. İletişim bilgileri telefon ya da adres olabilir. Getter'lar yazıldı; setter'lar da aynı şekilde eklenebilir. Örneğin `getAd()` String tipinde adı, `getTcNo()` String tipindeki kimlik numarasını döndürür.

<!-- BELİRSİZ: Ekranda tcNo tipi "iString" olarak görünüyor; anlatımla birlikte bu bir yazım hatasıdır ve String kastedilmiştir. -->

### 2.3 Sınıfların belirlenmesi

Önce sınıf adları oluşturuldu, sonra içleri dolduruldu:

- RezervasyonEkranı: Yolcu doğrudan rezervasyon yapmaz; önce olası seferleri listelettiği bir ekran vardır. Bu sınıf kullanıcının yaptığı aramaları (sefer günü, gidiş ve varış yeri) tutar ve sistemde kayıtlı uygun sefer olup olmadığına bakar.
- Sefer: Seferin nereden kalkacağını, nereye varacağını, hangi tarih ve saatte olduğunu ve hangi otobüsün gideceğini tutar.
- Otobüs: Plaka ve şoför bilgisini, kaç koltuk ve hangi koltuklar olduğunu tutar.
- Koltuk: Koltuk numarasını ve tipini (tekli, ikili, daha rahat ya da daha ekonomik gibi) tutar.
- Rezervasyon: Yapılan rezervasyonları tutar.
- Ödeme: Ödeme bilgilerini tutar.

Otobüs ve koltuk ayrı sınıflara bölündü, çünkü her birinde ayrı veriler tutulur.

### 2.4 Sefer, Otobüs ve Koltuk

Bir sefer bir otobüsle yapılır; sefer bir otobüs verisini tutar. Bir otobüste ise birden fazla koltuk vardır. Koltuk tek başına var olabilen bir şey olmadığı için Otobüs ile Koltuk arasında daha kuvvetli bir ilişki kurulur. İlişkiler içinde en kuvvetlisi bileşimdir (composition). Dolu elmas "bir" tarafında, yani Otobüs tarafında durur; "çok" tarafı düz çizgiyle iner (ekrandan, 00:25:00).

> **Hocanın vurgusu:** Koltuk otobüsten bağımsız var olamaz; bu yüzden en kuvvetli ilişki olan bileşim kullanılır, dolu elmas Otobüs tarafındadır.

> **Ek bilgi (derste anlatılmadı):** Toplama (aggregation) ilişkisinde parça bütünden bağımsız yaşayabilir ve içi boş elmasla gösterilir. Bileşimde parçanın yaşam süresi bütüne bağlıdır; bütün yok olunca parçaları da yok olur. Bu yüzden bileşimde bir parça aynı anda yalnız bir bütüne ait olabilir.

Sefer sınıfı (ekrandan, 00:30:00 ve 00:40:00):

```text
Sefer
- çıkışYeri: String
- varışYeri: String
- tarih: Date
- otobüs: Otobüs
+ Sefer(çıkış: String, varış: String, tarih: Date, otobüs: Otobüs)
+ seferBilgileriniAl(): Sefer
```

Çıkış ve varış yeri şehir ya da otogar olarak düşünülebilir. Sisteme seferler girildiği için bir sefer nesnesi doğrudan kurucu (constructor) üzerinden oluşturulur: nereden, nereye, ne zaman ve hangi otobüsle gidildiği kurucuya verilir. Getter ve setter'lar da (`getÇıkışYeri`, `setÇıkışYeri`, `getVarışYeri`, `setVarışYeri` gibi) yazılabilir; üye alanlar belirlendiği için bunlar doğrudan türetilebilir, derste konuyu uzatmamak için hepsi yazılmadı. `seferBilgileriniAl()` metodu sıralama şemasında ihtiyaç duyulunca eklendi; seferin bütün verisini döndürür.

<!-- BELİRSİZ: Karede kurucu parametresi "tairh:Date" olarak yazılmış; "tarih" kastedildiği açık. -->

Otobüs sınıfı:

```text
Otobüs
- plaka: String
- sofor: String
- koltuklar: Koltuk[]
+ getPlaka(): String
+ getSofor(): String
```

Bir otobüs nesnesi birden fazla koltuk nesnesini bir dizi içinde tutar; bu, `koltuklar: Koltuk[]` alanıyla gösterilir.

Koltuk sınıfı (ekrandan, 00:30:00):

```text
Koltuk
- koltukNo: String
- koltukTipi: String
- boslukDurumu: boolean
+ getKoltukNo(): String
+ getKoltukTipi(): String
+ getBoslukDurumu(): boolean
+ setBoslukDurumu(boolean): void
```

Koltuk numarası tamsayı değil String yapıldı, çünkü "1A", "1B" gibi değerler olabilir. Tasarımda koltukların hepsi başlangıçta boştur. Biri rezerve ettikçe ve biletini aldıkça bu durum değişir; bu yüzden boolean tipinde bir boşluk durumu tutulur. `setBoslukDurumu(boolean)` ile ilgili koltuğun durumu true ya da false yapılır; koltuk rezerve edildiğinde ya da parası ödendiğinde false'a çevrilir.

### 2.5 RezervasyonEkranı

Yolcunun yaptığı aramalar bu sınıf üzerinden yürür. Ekran, aranacak seferleri `Sefer` tipinde bir dizide tutar ve aramayı bu dizi üzerinden yapar (ekrandan, 00:40:00):

```text
RezervasyonEkranı
- seferler: Sefer[]
+ seferAra(gidis: String, varış: String, gun: Date): boolean
+ gosterSeferBilgileri(sefer: Sefer): void
+ otobusSec(busX: Otobus): void
+ koltukSec(koltukY: Koltuk): void
```

- `seferAra` gidiş yerini, varış yerini ve günü alır ve böyle bir seferin olup olmadığını true ya da false olarak döndürür.
- Sefer varsa `gosterSeferBilgileri` o sefere ait ayrıntılı bilgileri (hangi otobüs, şoför vb.) listeler. Dönüş tipine gerek yoktur; metot içinde bilgiler konsola ya da arayüze yazdırılır.
- Sefer bilgileri listelendikten sonra yolcu listelenen otobüslerden birini `otobusSec` ile, ardından o otobüste gösterilen koltuklardan birini `koltukSec` ile seçer. Bu iki iş ayrı metotlarla ifade edildi.

Bu adımlardan sonra elde yolcunun seçtiği sefer, otobüs ve koltuk bulunur; artık rezervasyon yapılabilecek noktaya gelinir.

### 2.6 Rezervasyon ve Ödeme

Rezervasyon ayrı bir sınıfla ifade edildi (ekrandan, 00:40:00):

```text
Rezervasyon
- rezervasyonNo: String
- odeme: Odeme
+ rezervasyonYap(yolcu: Yolcu, sefer: Sefer, koltuk: Koltuk)
+ odemeYap(rezervasyonNo: String): void

Ödeme
- odemeTarihi: Date
- odemeTutari: double
+ odemeAl(): void
```

Her rezervasyonun benzersiz (unique) bir numarası olur. Bu numaralarda harf de kullanılabildiği için String vermek daha mantıklıdır.

Rezervasyonun kesinleşmesi için kullanıcının ödeme yapması gerekir. Ödeme bilgileri ayrı bir Ödeme sınıfında tutulur: ödeme tarihi ve ödeme tutarı. Ödemeye de makbuz ya da fiş numarası gibi benzersiz bir kimlik verilmesi mantıklı olabilir; bu da eklenebilir. Rezervasyon, Ödeme tipinde bir nesne tutar. Ödeme yapılmamışsa bu alan null'dır. Belirli bir saate kadar ödeme yapılmazsa koltuğun eski haline döndürülüp yeniden rezervasyona açılması için ayrı bir metot yazılabilir.

`rezervasyonYap` metodu yukarıdan gelen yolcu, sefer ve koltuk bilgisini alır ve bunlarla bir rezervasyon oluşturur. Metodun içinde rezervasyon numarası da atanır; böylece ilgili yolcu, bir rezervasyon numarasıyla ilgili sefere ve seçtiği koltuğa bağlanmış olur.

`odemeYap` metodu rezervasyon numarasını parametre alır, çünkü ödeme belirli bir rezervasyona aittir. Bir şey döndürmesine gerek yoktur. Bu metot içinde ödeme işi Ödeme sınıfındaki `odemeAl()` metoduna gönderilir; ödeme tarihi ve tutarı bir Ödeme nesnesi olarak tutulur.

### 2.7 İlişkiler ve çokluklar

Son adım olarak ilişkilerin çoklukları belirlendi (ekrandan, 00:40:00; Sefer–Otobüs ve Rezervasyon–Ödeme çoklukları anlatımdan):

| İlişki | Çokluk | Gerekçe |
|---|---|---|
| Yolcu → RezervasyonEkranı | 1 : * | Bir yolcu birden fazla arama ve işlem yaptırabilir. |
| RezervasyonEkranı → Sefer | 1 : * | Ekran birden fazla sefer tutar; dizi de bunu gösterir. |
| RezervasyonEkranı → Rezervasyon | 1 : 0..1 | Ekranda listelenen bir sefer ya rezervasyona dönüşür ya dönüşmez. |
| Rezervasyon → Ödeme | 1 : 1 | Bir rezervasyonun birden fazla ödemesi olmaz. |
| Sefer → Otobüs | 1 : 1 | Bir sefer bir otobüsü içerir. |
| Otobüs ◆— Koltuk | 1 : * (bileşim) | Bir otobüsün birden çok koltuğu vardır. |

Genel resim şöyledir: yolcu arama yapar, sonra rezervasyon yapar, sonra ödeme yapar. Arama yaptığı ekran sefer bilgilerini alır; sefer bilgilerinin içinde otobüs bilgileri, onun içinde de koltuk bilgileri bulunur.

## 3. Sıralama Şeması: Rezervasyon Yapma

### 3.1 Amaç ve gösterim

Sıralama şeması dinamik görünümdür (dynamic view). Tek bir işlem, burada rezervasyon yapma işlemi boyunca hangi sınıfın hangi nesnesinin hangi metotlar üzerinden haberleştiğini ve bu akışın hangi sırayla ilerlediğini gösterir: önce şu nesne şuna gider, oradan şu metot şunu döndürür gibi.

Kullanılan öğeler:

- Nesne yaşam çizgisi (object lifeline): her sınıftan oluşturulan nesnenin akış boyunca hayat döngüsünü gösterir. Gösterim `nesneAdı: SınıfAdı` biçimindedir, örneğin `yolcu: Yolcu`.
- İsimsiz nesne: Nesnenin adı akışta kullanılmayacaksa yalnız `:RezervasyonEkranı` yazılır. Bu, o sınıftan adı belirtilmemiş bir nesne olduğu ve o sınıfın metotlarının işini yaptığı anlamına gelir.
- Etkinlik çubuğu (activation bar): nesnenin o anda iş yaptığını gösterir; mesaj gönderen ve alan tarafa konur.
- Çağrı mesajı (call message): düz çizgi ve dolu ok; gidilen sınıftaki metodun çağrıldığını gösterir.
- Dönüş mesajı (return message): kesikli çizgi; dönen değer üzerine yazılır.
- Kendine çağrı: Nesne kendi sınıfının bir metodunu çağırıyorsa ok kendi üzerine döner.

### 3.2 Akış

Şemadaki nesneler: `yolcu: Yolcu`, `:RezervasyonEkranı`, `sefer: Sefer`, `busX: Otobüs`, `koltukY: Koltuk`, `:Rezervasyon` (ekrandan, 00:55:00). Mesajlar sırayla:

| Sıra | Gönderen → Alan | Mesaj | Tür |
|---|---|---|---|
| 1 | yolcu → :RezervasyonEkranı | `seferAra(parametreler)` | çağrı |
| 2 | :RezervasyonEkranı → yolcu | `true` | dönüş |
| 3 | :RezervasyonEkranı → sefer | `seferBilgileriniAl()` | çağrı |
| 4 | sefer → :RezervasyonEkranı | `sefer` | dönüş |
| 5 | :RezervasyonEkranı → kendisi | `gosterSeferBilgileri(sefer)` | kendine çağrı |
| 6 | yolcu → :RezervasyonEkranı | `otobusSec(busX)` | çağrı |
| 7 | :RezervasyonEkranı → busX | `bosKoltuklariListele()` | çağrı |
| 8 | busX → koltukY | `getBoslukDurumu()` | çağrı |
| 9 | koltukY → busX | `boslukBilgisi` | dönüş |
| 10 | busX → :RezervasyonEkranı | `koltukBilgileri` | dönüş |
| 11 | yolcu → :RezervasyonEkranı | `koltukSec(koltukY)` | çağrı |
| 12 | :RezervasyonEkranı → :Rezervasyon | `rezervasyonYap(yolcu, sefer, koltukY)` | çağrı |
| 13 | :Rezervasyon → :RezervasyonEkranı | `rezervasyonOnayı` | dönüş |

Karede yalnız ilk iki mesaj numaralandırılmış (`1:seferAra(parametreler)`, `2:true`); sonraki numaralar aynı mantıkla verilmiştir (ara adım eklendi). Anlatımda da mesajların bu şekilde sırayla numaralanması önerildi.

Adımların anlatımı:

- `seferAra` çağrısıyla parametreler (çıkış yeri, varış yeri, tarih) ekrana gider. Metot boolean döndürüyordu; burada kullanıcının rezervasyon yaptığı durum kurgulandığı için böyle bir sefer var kabul edilir ve `true` döner.
- Sefer var olduğuna göre, daha sonra otobüs ve koltuk bilgilerine ulaşabilmek için ekran `sefer` nesnesinden `seferBilgileriniAl()` ile ilgili seferi alır. Sefer sınıfı ilgili seferin tuttuğu bilgileri döndürür.
- Ekran, dönen `sefer` nesnesine göre bilgileri yolcuya göstermek için kendi `gosterSeferBilgileri(sefer)` metodunu çağırır. Kendi üzerindeki bir metodu çağırdığı için ok kendine döner.
- Yolcuya kalan iş seçim yapmaktır. Yolcu listelenen otobüslerden birini `otobusSec(busX)` ile seçer.
- Ekranın boş koltukları gösterebilmesi için koltukların boşluk durumuna ulaşması gerekir. Bunun için Otobüs sınıfında `bosKoltuklariListele()` adlı bir metot olmalıdır. Sınıf şemasında bu metot yazılmamıştı; sıralama şeması çizilirken eksik olduğu fark edildi ve otobüs sınıfına eklenmesi gerektiği söylendi.
- Otobüs, boş koltukları listeleyebilmek için koltuklara tek tek bakar: koltuk boş mu (is available)? Koltuk sınıfı her koltuğun boşluk durumunu true ya da false olarak tutar. Otobüs `getBoslukDurumu()` ile boşluk bilgisini alır, true olanları seçip listeler ve ekrana koltuk bilgilerini döndürür.
- Koltuklar listelendikten sonra yolcu `koltukSec(koltukY)` ile koltuğu seçer.
- Artık yolcu bilgisi, sefer bilgisi ve koltuk elde olduğu için Rezervasyon sınıfının `rezervasyonYap(yolcu, sefer, koltukY)` metodu çağrılır. Dönüş olarak ekrana rezervasyonun onayına dair bir onay kutusu ya da bilgi çıkar; yani rezervasyon onayı döner.

> **Ders sonrası not:** Sınıf şemasında `seferBilgileriniAl()` Sefer sınıfında yer alıyor, ama `bosKoltuklariListele()` karedeki Otobüs sınıfında görünmüyor. Anlatımda bu metodun Otobüs sınıfına eklenmesi gerektiği söylendi; tutarlı bir tasarımda Otobüs sınıfına `+ bosKoltuklariListele(): Koltuk[]` gibi bir metot eklenmelidir (dönüş tipi büyük olasılıkla bir koltuk listesidir, derste yazılmadı).

### 3.3 Sıranın önemi

> **Hocanın vurgusu:** Sıralama şemasında sıra çok önemlidir. Örneğin otobüs seçimini yukarıya, sefer aramayı aşağıya yazamazsınız.

Okların yukarıdan aşağıya sırası bazen karışabilir. Okunabilirliği artırmak için mesajları 1, 2, 3, ... diye numaralandırmak iyi bir alışkanlıktır.

Sınıf şemasında bütün metotlar bir anda verilir. Sıralama şemasının güzelliği, her metodun hangi sırada kullanıldığını göstermesidir.

Bu şema programın tamamı değil, yalnız rezervasyon yapma aşamasıdır. Sistemde ödeme de vardır; onun için ya bu şemaya devam edilir ya da ödeme için ayrı bir sıralama şeması çizilir.

## 4. Etkinlik Şeması: Rezervasyon Yapma

### 4.1 Amaç

Etkinlik şeması bir işlemde hangi eylemlerin (aktivitelerin) hangi sırayla olduğunu gösterir. Programlamadaki akış diyagramlarına benzer. Burada da rezervasyon yapma işlemi seçildi.

Kullanılan öğeler: başlangıç noktası (scenario start), etkinlik (activity), karar (decision, elmas), eş zamanlama çubuğu (synchronization bar), geçiş (transition) ve bitiş noktası (scenario end).

### 4.2 Akış

Şemadaki akış şöyledir (ekrandan, 01:05:00):

```text
(başlangıç)
   |
Yolcu Sisteme Girer
   |
Yolcu Sefer Bilgilerini Girer  <-----------+
   |                                       |
Sistem Seferleri Kontrol Eder              |
   |  [Sefer var mı?]                      |
 <karar> ---- Yok -------------------------+
   |
   Var
   |
Yolcu Otobüs Seçer
   |
Boş Koltuk Bilgileri Yolcuya Verilir
   |
=========== çatallanma (fork) ===========
   |                         |
Yolcu Koltuk Seçer     Yolcu İletişim Bilgilerini Girer
   |                         |
=========== birleşme (join) =============
   |
Rezervasyon Yapılır
   |
Yolcu Rezervasyonu Onaylar
   |
(bitiş)
```

Anlatım:

- Yolcu sisteme girer, ardından aradığı seferin bilgilerini (nereye gitmek istediğini) girer.
- Sistem girilen bilgilere göre böyle bir sefer olup olmadığını kontrol eder.
- Burada bir karar noktası çıkar, çünkü sefer olup olmamasına göre farklı aksiyon alınacaktır. Karar elması konur ve neye karar verildiğini belirtmek için "Sefer var mı?" açıklaması yazılır. Sefer yoksa yolcuya böyle bir sefer olmadığı söylenir ve tekrar sefer bilgisi girmesi istenir ("Yok" dalı geri döner). Sefer varsa akış devam eder ("Var" dalı).
- Yolcu otobüsü seçer; ardından o otobüsteki boş koltuk bilgileri yolcuya verilir.
- Rezervasyon için yolcunun hem koltuk seçmesi hem de iletişim bilgilerini (adres, telefon gibi) girmesi gerekir. Bunlar ikisi tamamlanmadan bir sonraki aşamaya geçilmeyecek işlerdir. Bu yüzden önce bir eş zamanlama çubuğuyla çatallanma yapılır, iki etkinlik yazılır, sonra ikinci bir eş zamanlama çubuğuyla birleşme (join) yapılır. Birleşme, iki etkinliğin de bitmesini bekler.
- İkisi tamamlanınca rezervasyon yapılır. Ardından kullanıcıya rezervasyonu bu haliyle kabul edip etmediği bir kez daha sorulur; yolcu rezervasyonu onaylar ve senaryo biter.

> **Hocanın vurgusu:** Eş zamanlı yapılması ya da biri tamamlanmadan diğer aşamaya geçilmemesi gereken işler çatallanma ve birleşme çubuklarıyla gösterilir.

> **Ek bilgi (derste anlatılmadı):** UML etkinlik şemasında çatallanma (fork) bir akışı paralel akışlara ayırır, birleşme (join) ise gelen bütün paralel akışlar tamamlanınca tek akışla devam eder. Karar (decision) düğümünde ise yalnız bir çıkış dalı seçilir; dallar köşeli parantez içindeki koşullarla (guard) etiketlenir.

## 5. Durum Şeması: Koltuk Nesnesi

### 5.1 Amaç

Durum şeması bir sınıfın nesnesinin hangi durumlarda bulunabildiğini ve durumlar arasında hangi olay ya da eylemlerle (event/action) geçiş olduğunu gösterir. Örnek olarak Koltuk nesnesi seçildi.

Koltuğun bulunabileceği durumlar:

- Boş.
- Rezerve: rezerve edilmiş.
- Biletlendi: artık kesin olarak bir kişiye atanmış, başka birine atanamayacak durumda.

### 5.2 Geçişler

Şemadaki geçişler (ekrandan, 01:10:00):

| Kaynak | Hedef | Geçiş etiketi |
|---|---|---|
| Başlangıç | Boş | Yolcu otobüs seçer ve boş koltukları görüntüler |
| Boş | Rezerve | Yolcu koltuk seçti ve iletişim bilgisini girdi |
| Rezerve | Biletlendi | Yolcu ödeme yaptı |
| Rezerve | Boş | Yolcu 12 saate kadar ödeme yapmaz |
| Biletlendi | Bitiş | Koltuk başkasına verilemez |

Yolcu otobüsü seçip boş koltukları görüntülediğinde koltuk nesnesinin boş durumu görülür. Yolcu bir koltuk seçip iletişim bilgilerini girerse koltuk rezerve durumuna geçer. Bu kişi ödemesini yaparsa koltuk biletlenir; artık başkasına verilemez ve senaryo biter. Rezerve durumundayken ödeme yapılmazsa koltuk yeniden boş olarak işaretlenir ve boş durumuna döner.

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00): Bir yolcunun yolculuk etmek istediği seferi, istediği seferle ilgili otobüsü ve ilgili otobüsteki koltuğu seçmesini sağlayan ve ilgili bilgilerin rezervasyon bilgisi olarak kaydedildiği bir sistem tasarlanmak istenmektedir. "Otobüs Bileti Alımı" kullanım senaryosu (birincil aktör Yolcu; ön koşul: bilet satış sistemine tüm sefer bilgileri girilmiştir; son koşul: yolcu biletini satın almıştır; ana senaryo: 1. sefer bilgileri girilir ve seferler gösterilir, 2. otobüs seçilir, 3. koltuk seçilir ve uygunluğu kontrol edilir, 4. rezervasyon bilgileri girilir ve koltuk rezerve işlenir, 5. ödeme yapılır ve bilet işlenir) için şunları çiziniz:

- a) Tasarım sınıf şeması,
- b) Sınıf şemasına uygun bir sıralama şeması,
- c) Bir etkinlik şeması,
- d) Koltuk nesnesi için durum şeması.

<!-- BELİRSİZ: Soru metninin alternatif senaryolar ve istenen şemalar kısmı karede görünmüyor; istenen şemalar anlatımdan (00:13:24, 00:40:55, 00:56:10, 01:05:07) alındı. -->

> **Çözüm:** Derste verildi. Sınıf şeması Bölüm 2.2–2.7'de, sıralama şeması Bölüm 3.2'de, etkinlik şeması Bölüm 4.2'de, durum şeması Bölüm 5.2'de anlatıldı.

## Dersin Toparlaması

Bu uygulamada tek bir senaryo, otobüs bileti rezervasyonu, üzerinden dört UML şeması çizildi. Tasarım sınıf şeması analizdekinden farklı olarak metotları parametre ve dönüş tipleriyle gösterdi; anlamlı tip seçimi (kimlik ve koltuk numarasının String olması), bileşim ilişkisi ve çokluklar üzerinde duruldu. Sıralama şeması aynı sınıfların rezervasyon yapma işleminde hangi sırayla haberleştiğini gösterdi ve çizim sırasında sınıf şemasındaki eksik bir metot (`bosKoltuklariListele`) ortaya çıktı. Bu, sıralama şemasının tasarımı sınamak için de kullanılabildiğini gösterir.

Etkinlik şeması aynı işlemi akış diyagramına benzer biçimde, karar düğümü ve eş zamanlama çubuklarıyla anlattı. Durum şeması ise tek bir nesnenin, koltuğun, Boş, Rezerve ve Biletlendi durumları arasındaki geçişlerini gösterdi. Ödeme işlemi bu sıralama şemasının dışında kaldı; aynı şemaya devam ettirilerek ya da ayrı bir şemayla çizilebileceği söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
