# Ders 8 Çalışma Özeti

## Genel Konular

- Normalizasyonun tekrarı
  - Dört gayriresmî kural: Anlamı net, kolay açıklanabilen tablolar; anomali üretmeyen yapı; az null; sahte kayıt üretmeyen parçalama.
  - Anomalilerin en tehlikelisi silme anomalisidir, çünkü bilgi kaybolur (projedeki son işçi silinince proje de gider). Güncelleme anomalisi daha çok performans ve tutarlılık problemidir.
  - Bütün normal formları uygulamak tablo sayısını artırır (40 tablo 60-70 olabilir) ve performansı düşürebilir. Tersi denormalizasyondur: Bazı anomalilerin çözümü uygulamaya bırakılır.
  - Parçalamada ortak nitelik, tablolardan biri için anahtar olmalıdır; aksi hâlde sahte kayıtlar çıkar.
- Null örneği: Parola tablosu
  - İşçilerin yalnız bir kısmının sisteme giriş parolası varsa parolalar ayrı bir tabloda tutulur. Hem null'lardan kurtulunur hem de bu hassas tabloya ayrı güvenlik önlemi uygulanabilir.
- Fonksiyonel bağımlılıkların veritabanına sağlatılması
  - FD'ler iş kurallarıdır (business rules); bunları veritabanına dikte etmenin yolu trigger ya da assertion'dır. `CREATE ASSERTION` standartta vardır ama birçok sistemde desteklenmez.
  - Çalışan (up and running) bir sistemde bu kurallar performansı olumsuz etkiler; bu yüzden FD kümesi önce minimal hâle getirilir.
  - FD'ler veriye bakılarak (bir makine ya da GPT tarafından) belirlenemez, semantiği bilen biri belirler.
- Anahtar bulma ve kısıtlı normalizasyon alıştırması (ekrandan, 00:56:40)
  - $R = \{A, \dots, J\}$, $F = \{AB \rightarrow C,\ A \rightarrow DE,\ B \rightarrow F,\ F \rightarrow GH,\ D \rightarrow IJ\}$: $AB^+ = R$, tek anahtar $AB$; tek anahtar olduğu için kısıtlı normal formlar yeterlidir.
  - $A \rightarrow DE$ ve $B \rightarrow F$ 2NF'yi bozar. $A^+ = \{A, D, E, I, J\}$, $B^+ = \{B, F, G, H\}$. 2NF: `R1(A, D, E, I, J)`, `R2(B, F, G, H)`, `R3(A, B, C)`.
  - $D \rightarrow IJ$ ve $F \rightarrow GH$ 3NF'yi bozar. Slayttaki ilk 3NF sonucu: `R11(A, D, E)`, `R12(D, I, J)`, `R21(B, F)`, `R22(F, G, H)`, `R3(A, B, C)`. Hepsi 3NF ve BCNF'dir.
  - Hoca derste `R22`'yi `R22(B, G, H)` diye düzeltti; bu bağımlılık korumayı bozar (Detaylı Açıklamalar'a bakın).
- 1NF, 2NF, 3NF tekrarı
  - 1NF: Çok değerli ve iç içe nitelik olmamalı. Bileşik nitelik zaten alt nitelikleriyle yazılır.
  - 2NF: "All attributes depend on the whole key." Kısıtlı tanımda birincil anahtar, genel tanımda bütün aday anahtarlar.
  - 3NF: "All attributes depend on nothing but the key." Geçişli bağımlılık olmamalı. İstisna: Ara nitelik $Y$ bir aday anahtarsa problem yoktur.
- `LOTS` örneğinin tekrarı
  - Genel 2NF için `County_name → Tax_rate` ayrılır; 3NF için `Area → Price` ayrılır: `LOTS1A`, `LOTS1B`, `LOTS2`.
  - Hocaya göre kısıtlı 2NF ve 3NF ile çözüm daha basittir: `(Area, Price)` ve `(Property_id#, County_name, Lot#, Area, Tax_rate)`.
  - Ders sonrası not: Kısıtlı tanımda `County_name` asal sayılmaz; `Property_id# → County_name → Tax_rate` de geçişli olduğu için büyük olasılıkla `(County_name, Tax_rate)` da ayrılmalıdır.
- Genel normal form tanımları (ekrandan, 01:15:00)
  - Genel 2NF: Asal olmayan her nitelik, tablonun her anahtarına tam fonksiyonel bağımlı olmalıdır.
  - Genel 3NF: Her $X \rightarrow A$ için ya (a) $X$ süper anahtardır ya da (b) $A$ asal bir niteliktir.
  - BCNF: (b) koşuluna izin vermez; her $X \rightarrow A$'da $X$ süper anahtar olmalıdır.
  - Normal formlar iç içedir: BCNF olan 3NF'dir, 3NF olan 2NF'dir; tersi gerekmez.
- BCNF örnekleri
  - `LOTS1A(Property_id#, County_name, Lot#, Area)` ve `FD5: Area → County_name` (ekrandan, 01:22:45): $X$ = `Area` süper anahtar değil ama `County_name` asal olduğu için 3NF'dir, BCNF değildir. BCNF ayrıştırması: `LOTS1AX(Property_id#, Area, Lot#)`, `LOTS1AY(Area, County_name)`; FD2 kaybolur.
  - Şematik örnek: `R(A, B, C)`, `FD1: AB → C`, `FD2: C → B`. 3NF'dir, BCNF değildir.
  - İki nitelikli her tablo BCNF'dir; BCNF problemi ancak ikiden fazla nitelikli tablolarda çıkar.
  - `TEACH(Student, Course, Instructor)` (ekrandan, 01:25:10): `{Student, Course} → Instructor`, `Instructor → Course`. 3NF'dir, BCNF değildir.
- BCNF ve bağımlılık koruma (ekrandan, 01:29:50)
  - BCNF'ye ayrıştırma bütün FD'leri korumayabilir. `TEACH`'in olası ayrıştırmalarının hiçbiri `{Student, Course} → Instructor`'ı tek tabloda tutamaz.
  - Kitabın ifadesiyle bağımlılık korumadan ödün verilebilir, ama sahte kayıt üretmeme (non-additivity) özelliğinden asla ödün verilemez.
- NoSQL veritabanlarına giriş (ekrandan, 01:38:40)
  - NoSQL "Not only SQL" demektir. Çoğu NoSQL sistemi dağıtık veritabanı ya da dağıtık depolama sistemidir; yarı yapısal veri, yüksek performans, erişilebilirlik (availability), çoğaltma (replication) ve ölçeklenebilirliğe odaklanır.
  - Dört ilişkisel olmayan model: Doküman, anahtar-değer (key-value), sütun tabanlı (wide column) ve çizge (graph) depoları.
  - Motivasyon büyük veridir: Hacim (volume), hız (velocity), çeşitlilik (variety). Kullanıcı hareketleri, gönderiler, konum verisi gibi kaynaklar yarı yapısal ya da yapısal olmayan veri üretir.
  - İlişkisel sistemler katı şemalı, tablosal ve düzenli veride (üniversite, şirket veritabanı) çok başarılıdır. Bir alışveriş sitesinde ürünlerin nitelikleri kategoriye göre çok değiştiği için katı şema çok null üretir; esnek yapı gerekir.
  - NoSQL sistemlerinde sorgular çoğunlukla basittir (operasyonel, OLTP benzeri); karmaşık analitik sorgular (OLAP, veri ambarı) ayrı bir konudur. Sorgu dilleri daha az güçlüdür, işlemler çoğu zaman bir API (`find`, `get`) ile yapılır; hash ya da ağaç tabanlı indeksler yine kullanılır.
  - Örnek sistemler: Google Bigtable (wide column), Amazon'un anahtar-değer depoları, MongoDB (doküman), Neo4j (çizge), Cassandra (anahtar-değer ve wide column karması).
- Dağıtık sistem kavramları (ekrandan, 01:59:20)
  - Dikey ölçekleme (vertical scalability): Makineyi güçlendirmek; ilişkisel sistemlerin geleneksel yolu. Yatay ölçekleme (horizontal scalability): Sıradan (commodity) makineler ekleyip yükü dağıtmak; NoSQL'in yolu.
  - Sharding (yatay bölümleme, horizontal partitioning): Bir tablo satırlara göre parçalanıp farklı düğümlere dağıtılır; tek hata noktası ortadan kalkar ve paralel erişim mümkün olur.
  - Çoğaltma: Erişilebilirliği artırır; çoğaltma modelleri usta-köle (master-slave, MongoDB) ve usta-usta (master-master, Cassandra) gibi. Kopyaların güncellenmesi tutarlılığı zorlaştırır; bu yüzden nihai tutarlılık (eventual consistency) kullanılır.
  - Şema şart değildir; bir verinin farklı sürümleri saklanabilir. XML ve nesne veritabanları esnek ama merkezî sistemlerdir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Silme anomalisi en tehlikelisidir
  - Bilgi kaybına yol açar; örneğin bir işçiyi silen komut, işçi projedeki son kişi ise projeyi de siler.
- FD'leri veriden makine çıkaramaz
  - Bu iş semantiği bilen kişiye düşer. Anahtar bulma ve normalizasyon alıştırmalarını GPT çözebilir, ama sınavda kullanılamayacağı için yöntemi bilmek gerekir.
- Kitaptaki alıştırmaları çözün
  - Kitabın bölüm sonundaki 10-15 alıştırma pekiştirme için çok uygundur; en azından iki örnek (anahtar bulma ve `LOTS`) mutlaka anlaşılmalıdır.
- Gerçek hayatta BCNF'ye kadar normalizasyon yapılır
  - Ama şart değildir; anomalilere tahammül ediliyorsa ya da uygulamada çözülecekse 2NF'de bırakılabilir ya da tablolar denormalize edilebilir. Örneğin çok sık birleştirilen işçi ve proje tabloları bir araya getirilebilir; o zaman projedeki son kişinin silinmesini uygulama engellemelidir.
- Bağımlılık korumadan ödün verilebilir, kayıpsızlıktan asla
- Doğru veritabanını seçmek bir eğitim gerektirir
  - İhtiyaca göre ilişkisel ya da ilişkisel olmayan model, ilişkisel olmayanlardan da hangisinin seçileceği bilinmelidir.
- NoSQL'de tutarlılık geri plandadır
  - Sosyal medya gibi veride küçük hatalar kabul edilir; kritik olan erişilebilirliktir ve bunun temel aracı çoğaltmadır.

## Kısa Tekrar Notları

- Silme anomalisi: Bilgi kaybı. Güncelleme anomalisi: Çok satır güncelleme.
- Çok null üreten nitelik (parola, ofis) ayrı tabloya.
- FD'ler trigger ya da assertion ile sağlatılır; önce minimal küme bulunur.
- Kısıtlı tanımlar: Birincil anahtar. Genel tanımlar: Bütün aday anahtarlar.
- Genel 3NF: $X \rightarrow A$ için $X$ süper anahtar ya da $A$ asal.
- BCNF: $X \rightarrow A$ için $X$ süper anahtar (asal istisnası yok).
- BCNF ⊂ 3NF ⊂ 2NF ⊂ 1NF.
- İki nitelikli tablo her zaman BCNF'dir.
- BCNF ayrıştırması bağımlılık kaybettirebilir; sahte kayda asla izin verilmez.
- NoSQL: Not only SQL; dağıtık; erişilebilirlik, çoğaltma, ölçeklenebilirlik, yarı yapısal veri.
- Dört model: Doküman, anahtar-değer, wide column, çizge.
- Yatay ölçekleme + sharding + çoğaltma + nihai tutarlılık.

## Detaylı Açıklamalar

- Kısıtlı normalizasyon alıştırması (ekrandan, 00:56:40)
  - $F = \{AB \rightarrow C,\ A \rightarrow DE,\ B \rightarrow F,\ F \rightarrow GH,\ D \rightarrow IJ\}$ için önce $AB$'nin tek anahtar olduğu gösterilir. Tek aday anahtar olduğu için kısıtlı ve genel tanımlar aynı sonucu verir. 1NF'nin sağlandığı kabul edilir (örnek veri yok). 2NF'yi bozan bağımlılıklar anahtarın bir kısmından çıkanlardır: $A \rightarrow DE$ ve $B \rightarrow F$. Her biri için kapanış alınıp ayrı tablo kurulur: $A^+ = \{A, D, E, I, J\}$ ($D \rightarrow IJ$ yüzünden $I, J$ de gelir), $B^+ = \{B, F, G, H\}$. Geriye iki niteliğe birden bağlı $C$ ile `R3(A, B, C)` kalır.
  - 3NF için her tabloda anahtar dışı nitelikler arasında bağımlılık aranır: `R1`'de $D \rightarrow IJ$, `R2`'de $F \rightarrow GH$ geçişlidir. Ayrıştırma `R11(A, D, E)`, `R12(D, I, J)` ve `R21(B, F)`, `R22(F, G, H)` verir. Bütün tablolarda tek belirleyen anahtardır; hepsi BCNF'dir.
  - Ders sonrası not: Hoca derste `R22(F, G, H)`'yi "F'yi yanlış yazmışım, B anahtar" diyerek `R22(B, G, H)` yaptı (00:59:55, ekrandan 01:00:15). Doğrusu slayttaki ilk hâli `R22(F, G, H)`'dir. `R21(B, F)` ve `R22(B, G, H)` ayrıştırması da kayıpsızdır, ama `F → GH` bağımlılığı hiçbir tabloda kalmaz, yani bağımlılık korunmaz. 3NF ayrıştırmasında $F \rightarrow GH$ kendi tablosuna alınmalıdır.
- Genel 3NF tanımının mantığı
  - Tanım geçişliliği dolaylı olarak kapsar ama daha geneldir. $X \rightarrow A$'da $X$ süper anahtarsa sorun yoktur. $X$ süper anahtar değilse, 3NF yine de $A$ bir aday anahtarın parçasıysa (asal) buna izin verir. BCNF bu ikinci kapıyı kapatır. `LOTS1A`'da `Area → County_name` bağımlılığında `Area` anahtar değildir ama `County_name`, aday anahtar `{County_name, Lot#}`'ın parçasıdır; tablo 3NF'dir, BCNF değildir. Hoca bu bağımlılığın semantiğini şöyle açıkladı: Bir bölgedeki arsalar belli büyüklük aralığındadır (biri 50-100 m², öteki 150-200 m²), dolayısıyla alan bölgeyi belirleyebilir; tersi geçerli değildir, çünkü bir bölgede farklı alanlarda arsalar vardır. BCNF için `Area` ve `County_name` ayrı tabloya alınır, `Area` ana tabloda kalır.
- Şematik BCNF örneği
  - `R(A, B, C)` için `AB → C` ve `C → B` vardır. `C → B`'de `C` süper anahtar değildir, `B` ise asaldır. Bu yüzden tablo 3NF'dir, BCNF değildir; `C` anahtar olacak şekilde `(C, B)` tablosu ayrılır.
  - Ders sonrası not: Hoca ayrıştırmayı "CB ve AB" diye söyledi (01:23:20). `(A, B)` ve `(C, B)`'nin ortak niteliği `B` hiçbir tablonun anahtarı olmadığı için bu ayrıştırma kayıplıdır. Doğrusu `(C, B)` ve `(A, C)`'dir; ortak nitelik `C`, `(C, B)`'nin anahtarıdır (python ile denetlendi).
- `TEACH` örneği
  - Slayttaki örnek veri (ekrandan, 01:25:10) `Instructor → Course` kuralına uyar: Her hoca tek bir ders verir (örneğin Mark ve Navathe "Database", Ammar "Operating Systems"). `{Student, Course}` aday anahtardır, çünkü bu dönemde bir öğrenci bir dersi tek bir hocadan alır. `Instructor → Course`'ta `Instructor` süper anahtar değildir, `Course` ise asaldır; 3NF'dir, BCNF değildir.
  - Olası ayrıştırmalar `{Student, Instructor}`–`{Student, Course}`, `{Course, Instructor}`–`{Course, Student}` ve `{Instructor, Course}`–`{Instructor, Student}`'tır. Hiçbiri üç niteliği içeren `{Student, Course} → Instructor`'ı tek tabloda tutamaz; bu bağımlılık ancak join ile denetlenebilir. Derste hangi ayrıştırmanın seçileceği söylenmedi.
- NoSQL'in ortaya çıkışı
  - İlişkisel sistemler "biraz fazla mükemmeldir": Kurtarma, sorgu iyileştirme gibi çok sayıda modülle doğru ve hızlı çalışır. Büyük veri platformlarında ise bu kadar doğruluk gerekmez; kritik olan verinin her zaman erişilebilir olması ve milyonlarca kullanıcıya hızlı cevap verilmesidir. Bu yüzden sistemin bazı modülleri, başta tutarlılık, hafifletilir. Ürün katalogu gibi niteliği kayıttan kayda değişen veride, katı şema yerine dizi ve map gibi yapılar içerebilen esnek bir model gerekir. MongoDB gibi doküman depoları iç içe yapıyı parçalamadan saklar; bu daha hızlıdır ama daha doğru demek değildir.
  - Dağıtık veritabanı ayrı ve geniş bir konudur (ağ, düğümler arası haberleşme, donanım ve yazılım). NoSQL sistemlerinin başarısı, arkadaki kümeyi soyutlayıp sorguları tek makinede çalışıyormuş gibi hızlı çalıştırmasıdır. Hoca "store" kelimesinin (key-value store, document store) bu sistemlerin geleneksel veritabanı modüllerini kapatıp veritabanı olma özelliğini kısmen kaybetmesini yansıttığını düşünüyor.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
