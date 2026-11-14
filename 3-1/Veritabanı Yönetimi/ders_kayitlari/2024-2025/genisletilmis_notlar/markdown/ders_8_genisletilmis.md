# Ders 8 Genişletilmiş Notu: BCNF, Genel Normal Formlar ve NoSQL Veritabanlarına Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Normalizasyonun Tekrarı
- 2. Fonksiyonel Bağımlılıkları Veritabanına Sağlatmak
- 3. Anahtar Bulma ve Kısıtlı Normalizasyon Alıştırması
- 4. 1NF, 2NF ve 3NF'nin Tekrarı
- 5. LOTS Örneğinin Tekrarı
- 6. Genel Normal Form Tanımları
- 7. Boyce-Codd Normal Formu (BCNF)
- 8. BCNF ve Bağımlılık Koruma: TEACH Örneği
- 9. Normalizasyonun Özeti ve Denormalizasyon
- 10. NoSQL Veritabanlarına Giriş
- 11. Dağıtık Sistem Kavramları: Ölçekleme, Sharding, Çoğaltma
- Örnek Sorular

## 1. Normalizasyonun Tekrarı

Hoca derse, normalizasyon bittikten sonra NoSQL veritabanlarına, onların veri modellerine, ortaya çıkış sebeplerine, örnek sistemlere ve terminolojiye geçileceğini söyleyerek başladı.

Önceki derste ilişkisel model tablolarının bazı kurallar çerçevesinde parçalanması (decomposition) gerektiği görülmüştü. Dört gayriresmî kural şöyle özetlenmişti:

- Tablolar anlamlı ve kolay açıklanabilir olmalı; açıklamanın kolaylığı tasarımın doğruluğuna da bir işarettir.
- Tablolar anomalilere yol açmamalı.
- Null değerler mümkün olduğunca az olmalı; bu her zaman mümkün olmayabilir ama gerekli parçalama yapılmalıdır.
- Parçalama doğru yapılmazsa birleştirmede fazladan kayıtlar çıkar ve bu, doğru veriye ulaşmayı engeller.

Hoca biçimsel tarafta fonksiyonel bağımlılığın tek bağımlılık türü olmadığını, iki tür daha (çok değerli bağımlılık ve join bağımlılığı) bulunduğunu hatırlattı. Kitap bunları "garip" diye niteler; yakalanması zor olduğu için ancak sezgisel yaklaşımlarla ele alınabilir. Kitaplar bunlara genelde ayrı bir bölüm ayırır; derste bunlara girilmeyecek, gerçek hayatta yaygın olarak kullanılan fonksiyonel bağımlılıklarla yetinilecek.

Gayriresmî kurallar "iki kere iki dört" gibi değildir; bir küçük dünyanın tasarımında tek doğru yoktur, birçok doğru olabilir, ama yanlış olmamalıdır. İlişkisel modelde tasarımın baştan iyi yapılması çok önemlidir. Hocaya göre NoSQL'in motivasyonu da buradan çıkar: Bazı uygulamalarda baştan mükemmel bir şema kurmak mümkün olmaz.

### 1.1 Anomaliler

`EMP_PROJ` örneğindeki üç anomaliden en tehlikelisi silme anomalisidir, çünkü bilgi kaybolabilir. Hoca bunun üzerine düşünmeyi istedi. Örneğin `EMP_PROJ` tablosundan işçi numarası 100 olan satır silinirken, bu işçi projedeki son kişiyse proje bilgisi de silinir. Oysa amaç projeyi silmek değildi; proje belki devam edecek, yeni kişiler alınacaktı.

Güncelleme anomalisi daha çok performans problemidir: Projenin adı 100 satırda tekrar ettiği için ad değişince 100 satır güncellenir. Yer kaybı ise ilk ve en hafif problemdir. Diğer anomaliler tehlikelidir, çünkü veritabanının bu noktada yapabileceği bir şey yoktur: Bir şey güncellenir, arkada 100 satır güncellenir; bir şey silinir, arka planda düşünülmeyen başka bir şey silinir.

Bütün normal formları eksiksiz uygulamak da bir bedel getirir. 40 tablolu bir tasarım normalizasyonla 60-70 tabloya çıkabilir ve bu ileride performans problemi yaratabilir. Bunun tersi denormalizasyondur: Veritabanı yöneticisi bazı anomalilerin tespitini ve çözümünü uygulamaya havale eder. "Performansı yüksek tutmak için tabloları parçalamadık; anomaliler olabilir, bilginiz olsun" denmiş olur. Normal şartlarda ise tablolar BCNF'ye kadar normalize edilir.

> **Hocanın vurgusu:** İki tabloyu birleştirmek için kullanılan ortak nitelik, tablolardan biri için anahtar olmalıdır. Parçalama böyle yapılırsa emniyetli olur, sahte kayıt çıkmaz ve veri kaybolmaz. Kuralların ispatlarına merak edilirse bakılabilir, ama kendine özgü bir terminolojisi vardır ve bu ders için gerekli değildir.

### 1.2 Null örneği: Parola tablosu

Hoca null'lar için yeni bir örnek verdi. `COMPANY` veritabanını kullanan bir web uygulamasında işçilerin sisteme bağlanmak için parolaları olsun. Kullanıcı kitlesi genişse parolaların veritabanında saklanması gerekir. Ama her işçinin parolası olmayabilir; örneğin işçilerin yalnız %20-30'u sisteme bağlanıyorsa, parolayı `EMPLOYEE` tablosunda tutmak çok sayıda null üretir. Bu yüzden ayrı bir tablo açılır. Ayrı tablonun bir faydası daha vardır: `EMPLOYEE` tablosundaki ofis numarası, telefon gibi bilgiler daha az hassastır; parola tablosunun gizliliği ve kimlik doğrulama açısından ayrıca korunması gerekir ve ayrı tabloya güvenlik önlemi uygulamak daha kolaydır.

## 2. Fonksiyonel Bağımlılıkları Veritabanına Sağlatmak

Anahtar bir tabloyu belirler, kayıtları benzersiz kılar. `EMPLOYEE` tablosunda `SSN` bütün tabloyu belirler: `SSN` tekrar etseydi aynı satır karşımıza çıkardı. Ama küçük dünyada (birbiriyle alakalı veriler ve bağıntılar) yalnız anahtarlar belirleyici değildir; tabloların kendi içinde ya da tablolar arasında nitelikler arasında başka bağımlılıklar da vardır. Küçük dünya tanındıkça bu bağımlılıklar ortaya çıkar ve bir fonksiyonel bağımlılık kümesi oluşturur. Bunlar dünyayı daha iyi tanımayı sağlar, ama fazlalık, yer kaybı ve anomalilere de zemin hazırlar.

Bu bağımlılıklar veriye bakılarak belirlenemez. Hoca kitaptaki cümleye bir ek yaptığını söyledi: Dört satırlık bir örneğe bakarak bir makinenin, örneğin GPT'nin, bu bağımlılıkları belirlemesi mümkün değildir. Semantiği bilen bir kişi belirlemelidir.

Belirlenen bağımlılıklar veritabanına bir yükümlülük getirir. Birincil anahtar ve yabancı anahtar kısıtları tanımlanınca veritabanı bu kuralları kendi dünyasına alır; birincil anahtar hiçbir zaman tekrar etmez. `UNIQUE` ile bazı niteliklerin aday anahtar olması da sağlanabilir. Ama iki nitelik arasındaki, semantiğe ve hatta dünyanın farklı yerlerine göre değişen bir bağımlılık için şema tanımında hazır bir araç yoktur.

**Soru:** Bu fonksiyonel bağımlılıkları veritabanında nasıl tanımlayabiliriz? **Cevap:** Bunlara iş kuralları (business rules) da denir. Tabloya dikte etmenin yolu trigger'lar ya da assertion'lardır. Bu çok sevilen bir yol değildir. `CREATE ASSERTION` standartta vardır ama derste kullanılan sistemde ve birçok sistemde desteklenmez; tersine, bazı sistemler standart dışı kendi uzantılarını sunar.

Bu araçlar çok yüklüdür. Tek kullanıcılı bir ortamda bir assertion ya da trigger güzel çalışır, ama ayakta olan (up and running), operasyonel bir sistemde veritabanının normal akışını ve performansını olumsuz etkiler. Yine de bağımlılıkların minimal hâli bulunarak dikte edilmesi mümkündür. Hoca, kendisinin gerçek bir sistemde yöneticilik yapmadığını ama bildiği kadarıyla minimal kümenin bulunup iş kurallarının uygulandığını söyledi. Bağımlılıklar varken anomalileri önlemek için de normalizasyon gerekir.

Fonksiyonel bağımlılığın tanımı tekrar edildi: Herhangi iki satırda $X$ aynıysa $Y$ de aynıdır. Bu tek yönlüdür; $Y$'ler aynı olunca $X$'lerin aynı olması gerekmez, ama $Y$'nin $X$'i belirlemesi de yasak değildir. Armstrong'un üç temel kuralı ve onlardan çıkan üç tamamlayıcı kural benimsenmelidir. Kapanış (closure) kavramı, minimal küme bulma ve 3NF, BCNF, 4NF ayrıştırma algoritmalarının ispatlarında kullanılır; derste o algoritmalara girilmeyecek. Önceki dersteki $E$ kümesinin çok daha basit, denk bir minimal kümeye dönüştüğü hatırlatıldı.

## 3. Anahtar Bulma ve Kısıtlı Normalizasyon Alıştırması

Hoca önceki derste bıraktığı iki anahtar örneğine, 2NF ve 3NF kısmına eklediği yeni bir çözüm sayfasıyla döndü (ekrandan, 00:56:40):

```text
R = {A, B, C, D, E, F, G, H, I, J}
F = { AB -> C, A -> DE, B -> F, F -> GH, D -> IJ }
G = { AB -> C, BD -> EF, AD -> GH, A -> I, H -> J }
```

Bu bağımlılıklar temsilîdir ama semantikten çıkmış gibi düşünülmelidir. İki şey aranır: Anahtar (ve aday anahtarlar) ile denk ve daha küçük bir minimal küme. Minimal küme, kuralların veritabanına sağlatılmasında sistemin yükünü azaltır.

> **Hocanın vurgusu:** Bu tür problemleri GPT başarıyla çözer, ama sınavda kullanılamayacağı için nasıl yapıldığını bilmek gerekir. Sınavda da buna benzer, ya semantikle ilgili ya da bu tarzda bir soru sorulabilir.

Anahtar ararken önce tek nitelikler denenir: $A$ bütün tabloyu belirliyor mu, $B$ belirliyor mu? Sonra ikili gruplar: $AB$, $AC$, $AD$, $AE$, ardından $BC$, $BD$ ... Sıra önemli değildir; $AB$'ye bakıldıktan sonra $BA$'ya bakmaya gerek yoktur. Bir anahtar bulununca o birincil anahtar olabilir; en küçüğünün seçilmesi daha iyidir. Ama genel normal formlar için aday anahtarlar da gerekir, bu yüzden arama sürdürülür. $F$ için tek anahtar $AB$, $G$ için tek anahtar $ABD$'dir; ikisinde de başka aday anahtar yoktur.

Ardından hoca $F$ üzerinde normalizasyonu uzun uzun çözdü ve öğrencilerin de pekiştirmek için kendileri yapmasını istedi:

**1. Anahtar:** $AB^+ = R$ ve $AB$ tek anahtardır. Tek aday anahtar olduğu için kısıtlı normal formlar yeterlidir; kısıtlı ve genel 2NF aynı sonucu verir.

**2. 1NF:** Örnek veri olmadığı ve iç içe yapı görünmediği için 1NF'nin sağlandığı kabul edilir; 2NF'den başlanır.

**3. 2NF:** Birincil anahtar iki nitelikli olduğu için, anahtarın bir parçası tek başına bir niteliği belirliyor mu diye bakılır. $A \rightarrow DE$ ve $B \rightarrow F$ böyledir ve 2NF'yi bozar. Her ihlal için o niteliği içeren bir tablo kurulur ve niteliğin belirlediği bütün nitelikler ona çekilir; bunun için kapanış bulunur:

- $A^+ = \{A, D, E, I, J\}$: $A \rightarrow DE$ ile $D, E$; $D \rightarrow IJ$ ile $I, J$ gelir.
- $B^+ = \{B, F, G, H\}$: $B \rightarrow F$ ile $F$; $F \rightarrow GH$ ile $G, H$ gelir.

```text
R1(A, D, E, I, J)   R2(B, F, G, H)   R3(A, B, C)
```

`R3`'te `C` iki niteliğe birden bağlıdır, sorun yoktur. Hoca farklı stratejiler olabileceğini, ama hepsinin sonunda aynı tablolara varılacağını, en kısa yolun bu olduğunu söyledi.

**4. 3NF:** Her tabloda, anahtar dışındaki niteliklerden biri başka bir anahtar dışı niteliğe bağlı mı diye bakılır. `R1`'de $D \rightarrow IJ$, `R2`'de $F \rightarrow GH$ vardır; ikisi de 3NF'yi bozar. `D` ana tabloda kalmak üzere `D, I, J` ayrılır; `F` için de aynısı yapılır:

```text
R11(A, D, E)   R12(D, I, J)   R21(B, F)   R22(F, G, H)   R3(A, B, C)
```

Slayta göre her tablo 3NF ve BCNF'dir. Bütün geçişlilikler ortadan kalkmıştır.

> **Ders sonrası not:** Hoca derste slayttaki `R22(F, G, H)` için "F'yi yanlış yazmışım, B olacak, çünkü B anahtar" dedi ve tabloyu `R22(B, G, H)` olarak düzeltti (00:59:55; ekrandan, 01:00:15). Doğrusu slayttaki ilk hâli `R22(F, G, H)`'dir. `R21(B, F)` ile `R22(B, G, H)` de kayıpsız bir ayrıştırmadır, ama `F → GH` bağımlılığı artık hiçbir tablonun içinde kalmaz; bağımlılık korunmaz ve bu kural ancak join ile denetlenebilir. Belirleyen `F` olduğu için tablo `F` üzerine kurulmalıdır (ayrıştırmalar python ile denetlendi).

Hoca, $G$ örneğinin biraz daha karışık olduğunu ama yapmaya değer olduğunu söyledi.

## 4. 1NF, 2NF ve 3NF'nin Tekrarı

### 4.1 1NF

Asal (prime) nitelik tanımı hatırlatıldı: Herhangi bir aday anahtarın (yalnızca "key" diye de geçer) içindeki nitelik asaldır. Kurallarda bu kavram kullanılacak; ispatlanmayacağı için hoca bunlara "kural" diyor.

1NF'de bütün nitelikler anahtara bağlı olmalıdır; bu zaten anahtarın tanımıdır. Ama bir nitelik çok değerliyse bu bozulur. Hoca slayttaki "çok değerli bileşik" ifadesinin üzerini çizdiğini, çünkü onun iç içe (nested) yapı olduğunu söyledi. Tek başına bileşik nitelik problem değildir; zaten her alt niteliği ayrı bir nitelik yapılır.

`DEPARTMENT` örneğinde `Dlocations` çok değerlidir. Çözümlerden biri `Dlocation`'ı birincil anahtara dahil etmektir, ama bu departmanın diğer bilgilerinin tekrar etmesine, yani fazlalığa yol açar. Departmanın başka bilgisi yoksa ve tabloda yalnız departman ve konum varsa, ikisi birden anahtar olan iki nitelikli bir tablo sorunsuzdur. Aksi hâlde ayrı tablo kurulur. Problemin özü şudur: Çok değerli hâlde "5" değeri tek bir konumu belirlemez (Bellaire, Sugarland, Houston), oysa 1NF'de anahtar her niteliğin tek bir değerini belirlemelidir. Satırlara açınca anahtar `(5, Bellaire)`, `(5, Sugarland)` gibi ikililer olur.

İşçinin projeleri ve saatleri bir iç içe tablodur (nested relation); hoca bu adın isabetli olduğunu, yeni bir kelime kullanmak istenmezse "çok değerli bileşik" denebileceğini söyledi. Bu yapı iki tabloya ayrılır. İki seviyeli iç içe yapı (aday kişinin iş geçmişi ve onun içinde maaş geçmişi) üç tabloya ayrılır.

Hoca burada NoSQL'e bir köprü kurdu: MongoDB gibi doküman depolarında iç içe yapı parçalanmadan bırakılır, bu yüzden daha hızlıdır; ama bu daha doğru olduğu anlamına gelmez. Verinin doğruluğunun çok kritik olmadığı ortamlarda (sosyal medya, büyük veri platformları) bazı anomalilere tahammül edilebiliyorsa parçalama yapılmaz. Hocaya göre NoSQL'in çıkış noktası tam da burasıdır. İlişkisel modelde ise bu yapılar geleneksel kurallarla parçalanmalıdır.

### 4.2 2NF

2NF'nin özeti: "All attributes should depend on the whole key." Bütün nitelikler anahtarın tamamına bağlı olmalı, bir kısmına bağlı olmamalıdır. Kısıtlı tanımda anahtar birincil anahtardır; genel tanımda bütün aday anahtarlardır: Nitelikler hiçbir aday anahtarın bir kısmına bağlı olmamalıdır.

`EMP_PROJ` örneğinde `Hours`, `{Ssn, Pnumber}`'a tam bağlıdır; ama `Ename` yalnız `Ssn`'e, `Pname` ve `Plocation` yalnız `Pnumber`'a bağlıdır. Ayrıştırma sezgiseldir: Hangi nitelikler hangilerini belirliyorsa birer tablo olur. Anahtarı tek nitelikli tablolarda kısıtlı 2NF problemi kalmaz, çünkü anahtarın "bir kısmı" yoktur.

### 4.3 3NF

3NF'nin anahtarı geçişli fonksiyonel bağımlılıktır: $X$, $Z$'yi başka bir $Y$ niteliği üzerinden değil, doğrudan belirlemelidir. `SSN → Dmgr_ssn`, `Dnumber` üzerinden geçişlidir: Bir kişinin bağlı bulunduğu departmanın yöneticisi, departman numarası üzerinden belirlenir. `SSN → Ename` ise kesinlikle geçişli değildir. Özet: "All attributes should depend on nothing but the key."

Bir istisna vardır ve kısıtlı tanım için de geçerlidir: Ara nitelik $Y$ bir aday anahtarsa, $X$'in $Y$ üzerinden $Z$'yi belirlemesi problem değildir. Hoca kuralın biraz "soğuk" kaçtığını, ama geçişli bağımlılığın fazlalığa, fazlalığın da anomalilere zemin hazırladığını, bunun dersin başındaki örneklere benzer örneklerle gösterilebileceğini söyledi.

`EMP_DEPT`'te `Dname` ve `Dmgr_ssn`, `Dnumber`'a bağlıdır ve aynı tabloda olduklarında anahtara geçişli bağlı olurlar; `Dnumber` bu tablo için aday anahtar değildir. Ayrıştırınca `Dnumber` yeni tablonun anahtarı olur. Hoca bu parçalamanın zor olmadığını, sahte kayıtlara yol açacak türden olmadığını söyledi; sahte kayıt problemi daha çok join bağımlılıklarında (5NF) öne çıkar, kuralı da ortak niteliğin bir tablonun anahtarı olmasıdır.

Özet: "All attributes depend on the key, on the whole key, and nothing but the key."

## 5. LOTS Örneğinin Tekrarı

Hoca kitabın bölüm sonundaki alıştırmaların (10-15 kadar) çok güzel olduğunu, ders özen gösteriliyorsa çözülmesini, en azından derste gösterilen iki örneğin mutlaka anlaşılmasını istedi. `LOTS` örneği arazi takibiyle ilgilidir ve semantiğe daha çok dayanır. Tabloya ne kadar nitelik eklenirse o kadar potansiyel fonksiyonel bağımlılık ortaya çıkar; bunlar veritabanına sağlatılsa da sağlatılmasa da küçük dünyanın bir gerçeğidir ve problemleri beraberinde getirir.

`{County_name, Lot#}` iki nitelikle benzersizliği sağlar, yani aday anahtardır. `County_name → Tax_rate`: Hoca `County`'yi bir şehir içindeki bölge olarak yorumladı; vergi oranı bölgeye göre değişir, nota benzer bir şeyle ilgisi yoktur, coğrafi bir bilgidir. `Area → Price`: Alan fiyatı belirler.

Kısıtlı 2NF açısından sorun yoktur, ama genel 2NF sağlanmaz, çünkü `Tax_rate` aday anahtarın bir kısmına (`County_name`) bağlıdır. Başka aday anahtar yoktur; anlamsız bütün kombinasyonlara bakmaya da gerek yoktur. Genel 2NF için `(County_name, Tax_rate)` ayrılır; `County_name` ana tabloda da kalır ki ileride join yapılabilsin.

Bundan sonra `Area → Price` bağımlılığı hâlâ durur: `Price`, anahtara `Area` üzerinden bağlıdır ve `Area` anahtar değildir. `Area` anahtar olsaydı istisna kuralıyla geçişli bağımlılıktan kurtulunurdu. 3NF sağlanmadığı için o da ayrılır:

```text
LOTS1A(Property_id#, County_name, Lot#, Area)
LOTS1B(Area, Price)
LOTS2(County_name, Tax_rate)
```

Hoca tabloları parçalarken bu adlandırmanın (`LOTS1`, `LOTS1A`, `LOTS1B`; daha da parçalanırsa `LOTS1AA`, `LOTS1AB`) kullanılmasını önerdi. Üç tablonun hepsi genel 2NF ve 3NF'dir; ama BCNF açısından hâlâ sorun olabilir.

Kısıtlı tanımlarla, yani aday anahtarlara bakmadan çözülürse sonuç daha basittir: Kısıtlı 2NF zaten sağlanır; kısıtlı 3NF için yalnız `Area → Price` ayrılır ve iki tablo yeterli olur:

```text
(Area, Price)
(Property_id#, County_name, Lot#, Area, Tax_rate)
```

Hoca bunun sınavda sorulabilecek türden bir soru olduğunu söyledi.

## 6. Genel Normal Form Tanımları

Aradan sonra hoca genel tanımlara geçti. Kısıtlı tanımlarda yalnız birincil anahtar göz önüne alınıyordu; genel tanımlarda kurallar bütün aday anahtarlara göre belirlenir (ekrandan, 01:15:00).

**Genel 2NF:** Tablodaki asal olmayan her nitelik, tablonun bütün anahtarlarına (bütün aday anahtarlara) tam fonksiyonel bağımlı olmalıdır. `LOTS` örneğinde `Tax_rate`, aday anahtar `{County_name, Lot#}`'ın tamamına bağlı olmalıydı, ama `County_name`'e bağlıdır.

**Süper anahtar:** $R$'nin bir anahtarını içeren nitelik kümesi.

**Genel 3NF:** $R$'de geçerli her $X \rightarrow A$ fonksiyonel bağımlılığı için şu ikisinden biri doğruysa $R$ 3NF'dir:

- (a) $X$, $R$'nin bir süper anahtarıdır, ya da
- (b) $A$, $R$'nin asal bir niteliğidir.

Hoca bu tanımın geçişliliği dolaylı olarak kapsadığını ama daha genel olduğunu söyledi. $X$ süper anahtar olabilir, aday anahtar olması gerekmez.

**BCNF:** Slayttaki not: Boyce-Codd normal formu (b) koşuluna izin vermez. Yani her $X \rightarrow A$'da $X$ süper anahtar olmalıdır. Bu, 3NF'yi de kapsayan daha katı bir formdur.

Normal formlar iç içedir: 2NF 1NF'yi, 3NF 2NF'yi, BCNF 3NF'yi kapsar. BCNF olan bir tablo 3NF olmak zorundadır, 3NF olan 2NF olmak zorundadır; 3NF olup 2NF olmamak söz konusu değildir. Ama bir tablo 3NF olup BCNF olmayabilir. Günümüzde gerçek hayatta kullanılan büyük ilişkisel tasarımlarda BCNF'ye kadar normalizasyon yapılır.

## 7. Boyce-Codd Normal Formu (BCNF)

### 7.1 LOTS1A örneği

Slayttaki BCNF örneği (ekrandan, 01:22:45):

```text
LOTS1A(Property_id#, County_name, Lot#, Area)
FD1: Property_id# -> {County_name, Lot#, Area}
FD2: {County_name, Lot#} -> {Property_id#, Area}
FD5: Area -> County_name
```

`Property_id#` birincil anahtar seçilmiştir; `{County_name, Lot#}` de aday anahtardır. Asal nitelikler `Property_id#`, `County_name` ve `Lot#`'tır. FD1 ve FD2'de sol taraf aday anahtar olduğu için sorun yoktur. FD5'te ise $X$ = `Area` süper anahtar değildir: Anahtar değil, aday anahtar da değil. Ama $A$ = `County_name`, aday anahtarın içinde bir nitelik, yani asaldır. Bu yüzden (b) koşulu sağlanır ve tablo 3NF'dir. BCNF ise $X$'in süper anahtar olmasını ister, $A$'nın asal olmasına izin vermez; tablo BCNF değildir. Bu durum fazlalığa ve anomalilere yol açar.

Hoca FD5'in semantiğinin yapmacık olmadığını açıkladı: Bir bölgedeki arsalar örneğin 100-200 m² arasında, başka bir bölgedekiler 150-200 m² gibi daha büyük parçalardan oluşuyor olabilir. Alan 50-100 arasındaysa bu bir bölgeyi, 150-200 arasındaysa başka bir bölgeyi belirliyor diye düşünülebilir. Tersi geçerli değildir: Bir bölgede 50, 60, 100 m²'lik arsalar bir arada bulunur.

BCNF ayrıştırması, `Area` ana tabloda kalmak üzere şöyledir:

```text
LOTS1AX(Property_id#, Area, Lot#)
LOTS1AY(Area, County_name)
```

Slayttaki şekil açıklamasına göre bu ayrıştırmada FD2 kaybolur.

### 7.2 Şematik örnek

Slayttaki şematik tablo (ekrandan, 01:22:45):

```text
R(A, B, C)
FD1: {A, B} -> C
FD2: C -> B
```

Bu tablo 3NF'dir ama BCNF değildir. `C → B`'de `C` anahtar olma özelliğinde değildir ve belirlenen `B` asal bir niteliktir. Bu yüzden `C` anahtar olacak şekilde parçalanmalıdır.

> **Ders sonrası not:** Hoca ayrıştırmayı "`C` anahtarı olmak üzere `CB` tablosu ve `AB`" diye söyledi (01:23:20). `(A, B)` ve `(C, B)`'nin ortak niteliği `B`, hiçbir tablonun anahtarı değildir; bu ayrıştırma kayıplıdır ve birleştirmede sahte kayıtlar üretir. Doğrusu `(C, B)` ve `(A, C)`'dir: Ortak nitelik `C`, `(C, B)` tablosunun anahtarıdır (python ile denetlendi). Bu ayrıştırmada FD1 kaybolur.

### 7.3 İki nitelikli tablolar

Hoca, iki nitelikli her tablonun BCNF'yi sağladığını, bunun ispat edilebileceğini söyledi ve denemeyi öğrencilere bıraktı (Örnek Sorular bölümüne bakın). Buna göre BCNF problemi ancak ikiden fazla nitelik içeren tablolarda söz konusu olabilir.

## 8. BCNF ve Bağımlılık Koruma: TEACH Örneği

Slayttaki `TEACH` tablosu 3NF'dir ama BCNF değildir (ekrandan, 01:25:10):

| Student | Course | Instructor |
|---|---|---|
| Narayan | Database | Mark |
| Smith | Database | Navathe |
| Smith | Operating Systems | Ammar |
| Smith | Theory | Schulman |
| Wallace | Database | Mark |
| Wallace | Operating Systems | Ahamad |
| Wong | Database | Omiecinski |
| Zelaya | Database | Navathe |

İki fonksiyonel bağımlılık vardır (ekrandan, 01:29:50):

```text
fd1: {Student, Course} -> Instructor
fd2: Instructor -> Course
```

Hoca, bu bağımlılıkları örnek veriye bakarak değil, örnek verinin bu bağımlılıklara göre oluşturulduğunu düşünerek okumak gerektiğini vurguladı. fd1 gerçekçidir: Bir öğrenci bir dersi bir hocadan alır. Başka dönemlerde başka hocadan alabilir, ama örnek veri tek bir döneme aittir. fd2'ye göre her hoca tek bir ders verir: Ammar "Operating Systems"i bir öğrenciye, Navathe "Database"i iki öğrenciye vermiştir.

`{Student, Course}` aday anahtardır ve bağımlılıklar şematik örnekteki kalıba uyar. `Instructor → Course`'ta `Instructor` anahtar değildir, `Course` asaldır: 3NF'dir ama BCNF değildir.

Kitaba göre BCNF olmayan bir tablo, bütün fonksiyonel bağımlılıkların korunmasından ödün vermek pahasına BCNF'ye ayrıştırılmalıdır; bunun algoritması kitabın sonraki bölümündedir (Algorithm 11.3). Olası ayrıştırmalar:

- `{Student, Instructor}` ve `{Student, Course}`: Ortak nitelik `Student`.
- `{Course, Instructor}` ve `{Course, Student}`: Ortak nitelik `Course`.
- `{Instructor, Course}` ve `{Instructor, Student}`: Ortak nitelik `Instructor`.

Hiçbiri fd1'i koruyamaz, çünkü fd1 üç niteliği birden içerir; tablo parçalanınca bağımlılık iki tabloya dağılır ve ancak join ile denetlenebilir. Normalde bundan kaçılır, ama burada mümkün değildir. Kitabın ifadesi: "We have to settle for sacrificing the functional dependency preservation. But we cannot sacrifice the non-additivity property." Bağımlılık korumadan ödün verilebilir, ama sahte kayıtlara kesinlikle izin verilemez, çünkü o zaman veri kaybolur. Derste hangi ayrıştırmanın seçileceği söylenmedi (Örnek Sorular bölümüne bakın).

## 9. Normalizasyonun Özeti ve Denormalizasyon

Hoca konuyu şöyle bağladı:

- Önce ilişkisel model tasarımındaki sezgisel, gayriresmî tasarım kalıpları uygulanır.
- Fonksiyonel bağımlılıklar semantiğe, küçük dünyadaki kurallara göre tespit edilip listelenir.
- Liste minimize edilir, minimal bir küme oluşturulur.
- İstenirse bu küme veritabanına trigger'larla dikte edilir; istenmezse de bağımlılıklar gerçek hayatta yine vardır.
- Bağımlılıklar varken anomalileri önlemek, performans ve yer açısından daha elverişli bir tasarım yapmak için normalizasyon yapılır; normal formlar iç içe olduğu için 1NF'den BCNF'ye kadar kurallar uygulanır.

Tablolar illa BCNF'ye kadar normalize edilmek zorunda değildir. Bazı anomalilere tahammül ediliyor ya da uygulama seviyesinde çözülecekse 2NF'de bırakılabilir, hiç normalize edilmeyebilir ya da bazı tablolar denormalize edilebilir. Örneğin işçi ve proje çok sık birlikte sorgulanıyor ve join ediliyorsa bir araya getirilebilir; sistemin ve ona bağlı uygulamaların genel performansı artar. Ama anomaliler uygulamada yakalanmalıdır: Projede son bir kişi kaldıysa o kişi silinemez, aksi hâlde proje de silinir.

İki uç vardır: Bütün nitelikleri tek tabloda tutmak ya da her niteliği ayrı bir tabloda tutmak. Yüzlerce nitelik için yüzlerce tablo hiçbir anomaliye yol açmaz ama birleştirmek için çok kötü bir performans demektir; tek tablo ise çok sayıda tekrar ve anomali demektir. İkisi arasında en isabetli yolu bulmak kesin değildir, ama yardımcı biçimsel ve gayriresmî tanımlar vardır.

## 10. NoSQL Veritabanlarına Giriş

Hoca NoSQL'i yine aynı kitabın ilgili bölümünden (Chapter 24) anlattı; o bölümün sunusu yerine PDF'ini kullandı. Kendi ders kitabının da güzel olduğunu, ama her konunun her kitapta en iyi anlatılmadığını söyledi.

### 10.1 Tanım ve modeller

NoSQL, ilişkisel modele alternatif olarak ilişkisel olmayan bir modeldir. Tek bir model yoktur, çünkü esnek bir modeldir: Katı (strict), tablosal yapıların dışına çıkılır; iç içe yapılar, çizgeler, basit anahtar-değer depoları, doküman depoları ya da şemaya ve tabloya yakın sütun tabanlı yapılar olabilir. Dört ilişkisel olmayan model:

- Doküman deposu (document store)
- Anahtar-değer deposu (key-value store)
- Sütun tabanlı (column-based, wide column) depo
- Çizge (graph) tabanlı depo

NoSQL "not SQL" değil "Not only SQL" demektir (ekrandan, 01:38:40); hocanın ifadesiyle SQL'den kendimizi tam uzaklaştıramıyoruz. Daha esnek bir model ve daha esnek bir sorgulama dili vardır. Slayta göre çoğu NoSQL sistemi dağıtık veritabanı ya da dağıtık depolama sistemidir; yarı yapısal veri depolama, yüksek performans, erişilebilirlik, veri çoğaltma ve ölçeklenebilirliğe odaklanır.

Konu dağıtık veritabanlarının bir kolu sayılır; kitapta bir önceki bölüm dağıtık veritabanlarına ayrılmıştır. Dağıtık veritabanı bilgisayar ağlarıyla da ilgilidir: Bir küme (cluster) içinde çok sayıda makine, aralarında haberleşme ve protokoller vardır; donanım ve yazılım kısmı olan geniş, ayrı bir konudur. Veritabanı açısından veri yığınının düğümlere dağıtılması, sorgunun birden çok düğümdeki veri üzerinde işlenmesi gibi yeni konular ortaya çıkar. Geleneksel veritabanı tek makinede çalışan, disk tabanlı bir sistemdir. Hocaya göre NoSQL sistemlerinin önemli başarısı, arkadaki kümeyi ya da bulutu soyutlayıp sorguları büyük veri setlerinde tek makinede çalışıyormuş gibi hızlı çalıştırmalarıdır.

### 10.2 Motivasyon: Büyük veri

Bilgisayar dünyasını NoSQL'e yönelten şeyin kısa cevabı büyük veridir. Büyük verinin saklanması ve sorgulanması için esneklik ve gevşeklik gerekir. Hoca ilişkisel sistemleri "biraz fazla mükemmel" diye niteledi: Çok sayıda modülü vardır, doğru ve hızlı çalışır, kurtarma (recovery) ve sorgu iyileştirme yapar, sistem kaynaklarını en iyi biçimde kullanır. Büyük veri uygulamalarında ise verinin bu kadar doğru işlenmesi gerekmez. Kritik olan:

- **Erişilebilirlik (availability):** Milyonlarca kullanıcı vardır; çok yanlış olmamak şartıyla sistemden mutlaka bir cevap alınmalıdır. Bunun en önemli yöntemi çoğaltmadır (replication): Veriyi içeren makine çökerse kopyasından alınır. Slaytta "consistency" kelimesinin geçmediğine dikkat çekildi.
- **Ölçeklenebilirlik (scalability):** Büyük verinin üç V'si hacim (volume), hız (velocity) ve çeşitliliktir (variety): Farklı kaynaklardan, farklı türlerde, çok hızlı ve çok miktarda veri gelir. Terabayt, petabayt düzeyindeki veriye her gün 100 GB ya da 1 TB yeni veri eklenebilir ve sistem bunu kaldırmalıdır; bu yatay ölçeklemeyle yapılır.
- **Yüksek performans:** Her veritabanından beklenen performans burada da beklenir; NoSQL sistemlerinde de hash ya da ağaç tabanlı indeks yapıları vardır.

Ama sorgular çok karmaşık değildir. Bu sistemler operasyonel veritabanlarıdır: Bir kişinin bilgilerini aramak, güncellemek ya da bir çizge veritabanında bağlantılı olduğu kişilere erişmek gibi basit işler yapılır. Karmaşık analitik sorgular (OLAP, veri ambarları) ayrı bir konudur. NoSQL sistemleri daha çok OLTP tarzındadır; ama OLTP'de transaction meselesi de olduğu için bu ifade tam doğru değildir, "basit sorguları içeren sistem" demek daha doğrudur. Dolayısıyla ilişkisel sistemler bu iş için fazla şey yapar; bazı modüllerin, başta tutarlılığın, budanması gerekir: Tutarlılık her an sağlanmaz, biraz sonra sağlanır.

### 10.3 Katı şema ve yarı yapısal veri

İlişkisel sistemlerin hızlı çalışmasının en önemli sebeplerinden biri verinin tablosal olması, şemanın katı olması ve pek değişmemesidir. Üniversite veritabanında olaylar nettir: Öğrenciler, hocalar, bölümler vardır; dersler alınır, geçilir ya da kalınır. `COMPANY` veritabanı da öyledir. Küçük dünyada sürekli yeni şeyler ortaya çıkmıyorsa ve veri düzenliyse, ayrıca doğruluk bekleniyorsa ilişkisel model çok isabetlidir.

Büyük veri platformlarındaki veri ise tablosal değil, yarı yapısaldır (semi-structured). Tablosal yapıda bütün kayıtlar aynı niteliklere sahiptir ve nitelikler de kısıtlanır (örneğin `CHAR(20)`). Herkesin aynı niteliklere sahip olduğu konusunda anlaşılsa bile nitelikleri kısıtlamak ayrı bir problemdir. Hoca öğrenci örneğinin burada isabetli olmadığını, çünkü üniversite veritabanının ilişkisel modele çok uygun olduğunu söyleyip bir alışveriş sitesi örneği verdi: Ürünlerin satıldığı ve stoklarının izlendiği bir sistemde aynı kategorideki cep telefonlarının bile özellikleri farklıdır; bir kategorinin nitelikleri diğerleri için geçerli değildir. Bunu katı bir şemaya sokmak yanlış olur, çok sayıda null çıkar. Esnek bir yapıda bir nitelik bir dizi ya da map olabilir.

Bu kadar veri nereden geliyor? Web ortamındaki her hareket, her tıklama kaydedilir. Hangi sitelere bakıldığı, hangi ürünlerin alındığı kaydedilip herkesin bir profili çıkarılır; buna göre reklamlar ve tahminler yapılır. Gönderiler, tweet'ler, harita ve ulaşım verileri, haberleşme hareketleri de kaydedilir. Herkesin profili farklı olduğu için bu veri yarı yapısal ya da yapısal olmayan (unstructured) veridir. Hoca bu tarihçenin, özellikle 2010 sonrasındaki hızlı gelişimin incelenmesini önerdi.

### 10.4 Örnek sistemler

- Google'ın Bigtable'ı: Sütun tabanlı, "wide column store" (ikisi aynı anlamdadır).
- Amazon'un bulut platformlarında kullanılan anahtar-değer depoları (key-value data store).
- MongoDB: Doküman deposu; veritabanı sıralamalarında ilk 10'da yer alır.
- Neo4j: Çizge tabanlı NoSQL.
- Cassandra: Hem anahtar-değer hem wide column özelliklerini kullanan karma bir sistem.

Hoca "store" kelimesinin isabetli olduğunu düşünüyor: Bu sistemler geleneksel veritabanının bazı önemli modüllerini kapattığı için veritabanı olma özelliğini kısmen kaybetmiştir. İhtiyaca göre doğru sistemi seçmek bir eğitim gerektirir: Ne zaman ilişkisel, ne zaman ilişkisel olmayan model, ilişkisel olmayanlardan da hangisi kullanılacak?

## 11. Dağıtık Sistem Kavramları: Ölçekleme, Sharding, Çoğaltma

Slaytta NoSQL'in dağıtık sistemlerle ilgili özellikleri şöyle sıralanır (ekrandan, 01:59:20): Ölçeklenebilirlik; erişilebilirlik, çoğaltma ve nihai tutarlılık; çoğaltma modelleri (master-slave, master-master); dosyaların sharding'i; yüksek performanslı veri erişimi.

### 11.1 Dikey ve yatay ölçekleme

Veri arttıkça sorgular yavaşlar. Dikey ölçeklemede (vertical scalability) makine güçlendirilir: İşlemci, ana bellek, disk artırılır, bir süper bilgisayar yapılır. İlişkisel sistemler geleneksel olarak bu yolu izler. NoSQL'in ana fikri yatay ölçeklemedir (horizontal scalability): Hocanın günlük ifadesiyle "bir makine daha, bir küme daha, 10 makine daha ekleyelim". Yük birçok makineye dağıtılır; eklenen makineler süper bilgisayar değil, sıradan ticari (commodity) makinelerdir ve sisteme kolayca eklenip çıkarılabilir.

### 11.2 Sharding

Yatay kelimesiyle ilişkili olarak sharding, yani yatay bölümleme (horizontal partitioning) gelir. `COMPANY` veritabanındaki `EMPLOYEE` tablosu tek bir yerde olmasın: Tek yerde olursa bir hata olduğunda tabloya bir daha ulaşılamaz (tek hata noktası). Ayrıca dosyaya aynı anda birçok noktadan paralel erişmek için dosya yatay olarak parçalanıp farklı düğümlere dağıtılır; kümede 10 düğüm varsa dosya 10 parçaya ayrılır. Kümeler yüzlerce, binlerce makineden oluşabilir; hoca Google'ın veri merkezlerini bir fabrikaya benzetti, ürettikleri ısının bile ciddi bir mesele olduğunu söyledi.

### 11.3 Çoğaltma ve nihai tutarlılık

Büyük veri iki esasa dayanır: Yatay parçalama ve çoğaltma. Çoğaltmada farklı protokoller ve yaklaşımlar vardır: MongoDB'nin usta-köle (master-slave), Cassandra'nın usta-usta (master-master) modeli gibi. Çoğaltmanın amacı erişilebilirliği artırmaktır.

Çoğaltmanın ortaya çıkardığı problem bütünlük, yani doğruluktur. Hoca hatırladığı kadarıyla en az üç kopya tutulduğunu ve bunların farklı makinelere dağıtıldığını söyledi. Kopyaların aynı anda güncellenmesi yazmayı zorlaştırır, okumalarda da doğruluğu azaltır. Bu yüzden buradaki tutarlılık ilişkisel modeldeki tutarlılıktan farklıdır ve nihai tutarlılık (eventual consistency) diye adlandırılır: Veri hemen değil, biraz sonra tutarlı olur. Her an tutarlı olması şart değildir, çünkü saklanan veri parasal değerler gibi hassasiyet isteyen bir veri değildir; sosyal medya verisinde küçük hatalar olabilir, yeter ki genel manzara çok yanlış olmasın.

### 11.4 Veri modeli ve sorgu dili

NoSQL sistemlerinin veri modeli ilişkisel değildir ve sorgu dilleri daha az güçlüdür (less powerful). SQL ile çok karmaşık sorgular yazılabilir ama çoğuna ihtiyaç yoktur; basit işler bir API üzerinden (`find`, `get` gibi) yapılır, arkada yine indeksler kullanılır. Şema şart değildir, olabilir de olmayabilir de; veri karakteristiği esnek olmalıdır. Bir verinin farklı sürümlerinin farklı kümelerde saklanması da diğer sistemlerden ayıran bir özelliktir.

Slayttaki sınıflandırmada XML veritabanları (2010 öncesi) ve nesne veritabanları da esnek yapıları yüzünden NoSQL sayılabilir, ama dağıtık sistemlerde yer bulmamış, merkezî veritabanları olarak kalmışlardır. Diğerlerinin hepsi büyük veriyi işleyebilen, saklayabilen dağıtık depolardır. Hoca, SQL ile NoSQL'in farklı odaklarını iyice anlamanın önemli olduğunu, günümüzde büyük veri sistemleri deyince NoSQL'in akla geldiğini ve konuya sonraki derste devam edileceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Nihai tutarlılık genelde CAP teoremiyle birlikte anılır: Ağ bölünmesi (partition) yaşanabilen dağıtık bir sistemde tutarlılık (consistency) ile erişilebilirlik (availability) aynı anda tam olarak sağlanamaz. Birçok NoSQL sistemi erişilebilirliği seçip tutarlılığı gevşetir.

## Örnek Sorular

**1.** (derste sözlü, 00:23:50) Semantiğe dayalı fonksiyonel bağımlılıklar (iş kuralları) veritabanında nasıl tanımlanıp sağlatılabilir?

Cevap (derste verildi): Birincil anahtar, yabancı anahtar ve `UNIQUE` dışındaki bağımlılıklar için hazır bir araç yoktur; ancak trigger'lar ya da assertion'larla dikte edilebilirler. `CREATE ASSERTION` standartta vardır ama birçok sistemde desteklenmez. Bu araçlar çalışan sistemde performansı olumsuz etkilediği için önce minimal FD kümesi bulunur.

**2.** (ekrandan, 00:56:40) $R = \{A, B, C, D, E, F, G, H, I, J\}$ ve $F = \{AB \rightarrow C,\ A \rightarrow DE,\ B \rightarrow F,\ F \rightarrow GH,\ D \rightarrow IJ\}$ için anahtarı bulun ve tabloyu 2NF ile 3NF'ye ayrıştırın.

Cevap (derste verildi): $AB^+ = R$, tek anahtar $AB$; kısıtlı normal formlar yeterli. $A \rightarrow DE$ ve $B \rightarrow F$ 2NF'yi bozar; $A^+ = \{A, D, E, I, J\}$, $B^+ = \{B, F, G, H\}$. 2NF: `R1(A, D, E, I, J)`, `R2(B, F, G, H)`, `R3(A, B, C)`. $D \rightarrow IJ$ ve $F \rightarrow GH$ 3NF'yi bozar. 3NF: `R11(A, D, E)`, `R12(D, I, J)`, `R21(B, F)`, `R22(F, G, H)`, `R3(A, B, C)`. Her biri 3NF ve BCNF'dir. (Hocanın derste yaptığı `R22(B, G, H)` düzeltmesi bağımlılık korumayı bozar; Bölüm 3'teki nota bakın.)

**3.** (derste sözlü, 00:53:33) `LOTS(Property_id#, County_name, Lot#, Area, Price, Tax_rate)` tablosu yalnız kısıtlı tanımlarla (aday anahtarlar dikkate alınmadan) 2NF ve 3NF'ye getirilirse hangi tablolar çıkar?

Cevap (derste verildi): Birincil anahtar tek nitelikli olduğu için kısıtlı 2NF zaten sağlanır. Kısıtlı 3NF'yi `Area → Price` geçişli bağımlılığı bozar; `(Area, Price)` ayrılır. Sonuç iki tablodur: `(Area, Price)` ve `(Property_id#, County_name, Lot#, Area, Tax_rate)`. (`County_name → Tax_rate`, `County_name` birincil anahtar olmadığı hâlde kısıtlı tanımda incelenmedi; hoca bu çözümü böyle verdi.)

> **Ders sonrası not:** Kısıtlı tanımda asallık yalnız birincil anahtara göre belirlenir; o zaman `County_name` asal değildir ve `Property_id# → County_name → Tax_rate` da geçişli bir bağımlılıktır. Büyük olasılıkla kısıtlı 3NF için `(County_name, Tax_rate)` da ayrılmalı ve sonuç üç tablo olmalıdır: `(Area, Price)`, `(County_name, Tax_rate)`, `(Property_id#, County_name, Lot#, Area)`. Önceki dersteki slaytta da `LOTS2(County_name, Tax_rate)` ayrılmıştı.

**4.** (ekrandan, 01:22:45) `LOTS1A(Property_id#, County_name, Lot#, Area)` tablosunda `Area → County_name` bağımlılığı varsa tablo 3NF midir, BCNF midir? BCNF'ye nasıl getirilir?

Cevap (derste verildi): `Area` süper anahtar değildir ama `County_name` asaldır; (b) koşulu sağlandığı için 3NF'dir, BCNF değildir. Ayrıştırma: `LOTS1AX(Property_id#, Area, Lot#)` ve `LOTS1AY(Area, County_name)`. Bu ayrıştırmada `{County_name, Lot#} → ...` bağımlılığı (FD2) kaybolur.

**5.** (ekrandan, 01:22:45) `R(A, B, C)`, `AB → C`, `C → B`. Tablo hangi normal formdadır, BCNF için nasıl ayrıştırılır?

Cevap (derste verildi): 3NF'dir ama BCNF değildir, çünkü `C → B`'de `C` süper anahtar değildir (`B` asal olduğu için 3NF sağlanır). `C` anahtar olacak şekilde `(C, B)` ayrılır.

> **Çözüm (derste verilmedi):** Kayıpsız BCNF ayrıştırması `(A, C)` ve `(C, B)`'dir; ortak nitelik `C`, `(C, B)`'nin anahtarıdır. Derste söylenen `(A, B)` ve `(C, B)` kayıplıdır, çünkü ortak nitelik `B` iki tablonun da anahtarı değildir. Kayıpsızlık, ikili ayrıştırmada ortak niteliklerin kapanışının tablolardan birini kapsaması koşuluyla python ile denetlendi.

**6.** (derste sözlü, 01:23:45) İki nitelikli her tablonun BCNF olduğunu gösterin.

> **Çözüm (derste verilmedi):** Tablo $R(A, B)$ olsun. Önemsiz olmayan olası bağımlılıklar yalnız $A \rightarrow B$ ve $B \rightarrow A$'dır. Hiçbiri geçerli değilse tek anahtar $AB$'dir ve önemsiz olmayan bağımlılık olmadığı için BCNF ihlali yoktur. Yalnız $A \rightarrow B$ geçerliyse $A$ anahtardır; bağımlılığın sol tarafı süper anahtardır. Yalnız $B \rightarrow A$ geçerliyse simetrik olarak $B$ anahtardır. İkisi de geçerliyse $A$ ve $B$ ikisi de anahtardır. Her durumda her önemsiz olmayan $X \rightarrow Y$'de $X$ süper anahtar olduğu için tablo BCNF'dir.

**7.** (ekrandan, 01:29:50) `TEACH(Student, Course, Instructor)` tablosunda `{Student, Course} → Instructor` ve `Instructor → Course` geçerlidir. Tablo neden BCNF değildir? Olası üç ikili ayrıştırmadan hangisi seçilmelidir?

Cevap (kısmen derste verildi): `Instructor → Course`'ta `Instructor` süper anahtar değildir; `Course` asal olduğu için tablo 3NF'dir ama BCNF değildir. Üç ayrıştırmanın hiçbiri `{Student, Course} → Instructor`'ı korumaz; bağımlılık korumadan ödün verilebilir, kayıpsızlıktan verilemez.

> **Çözüm (derste verilmedi):** Kayıpsız olan tek ayrıştırma `{Instructor, Course}` ve `{Instructor, Student}`'tır: Ortak nitelik `Instructor`, `Instructor → Course` sayesinde `{Instructor, Course}` tablosunun anahtarıdır. Diğer ikisinde ortak nitelik (`Student` ya da `Course`) hiçbir tablonun anahtarı olmadığı için birleştirme sahte kayıt üretir. Sonuç, ortak nitelik kapanışı yöntemiyle python ile denetlendi.

## Dersin Toparlaması

Bu derste normalizasyon tamamlandı. Önceki dersin kuralları ve anomaliler tekrar edildi, fonksiyonel bağımlılıkların iş kuralları olarak ancak trigger ve assertion'larla sağlatılabileceği ve bu yüzden minimal kümenin önemli olduğu vurgulandı. Tek anahtarlı bir alıştırma kısıtlı tanımlarla 2NF ve 3NF'ye adım adım ayrıştırıldı. Ardından bütün aday anahtarları dikkate alan genel 2NF ve 3NF tanımları verildi: 3NF'de her $X \rightarrow A$ için $X$ süper anahtar ya da $A$ asal olmalıdır; BCNF ikinci koşula izin vermez. `LOTS1A`, şematik `R(A, B, C)` ve `TEACH` örnekleri 3NF olup BCNF olmayan tabloları gösterdi ve BCNF ayrıştırmasının bağımlılık kaybettirebileceği, ama kayıpsızlıktan asla ödün verilemeyeceği vurgulandı.

Dersin son kısmında NoSQL veritabanlarına giriş yapıldı: Büyük verinin hacim, hız ve çeşitliliği; erişilebilirlik, çoğaltma ve ölçeklenebilirlik odağı; yarı yapısal veri; dört ilişkisel olmayan model; yatay ölçekleme, sharding, çoğaltma modelleri ve nihai tutarlılık. Konuya sonraki derste aynı kitabın NoSQL bölümünden devam edilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
