# Ders 7 Genişletilmiş Notu: Fonksiyonel Bağımlılıklar ve Normalizasyon (1NF, 2NF, 3NF)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Normalizasyona Giriş ve Tasarımda Ayar
- 2. Gayriresmî Tasarım Kuralları
- 3. Güncelleme Anomalileri
- 4. Null Değerler
- 5. Sahte Kayıtlar, Kayıpsız Birleştirme ve Bağımlılık Koruma
- 6. Fonksiyonel Bağımlılık
- 7. Çıkarım Kuralları ve Kapanış
- 8. Minimal Fonksiyonel Bağımlılık Kümesi
- 9. Anahtar Bulma
- 10. Anahtar Tanımları ve Asal Nitelik
- 11. Birinci Normal Form (1NF)
- 12. İkinci Normal Form (2NF)
- 13. Üçüncü Normal Form (3NF)
- 14. LOTS Örneği: Kısıtlı ve Genel 2NF
- 15. Özet Tablo
- Örnek Sorular

## 1. Normalizasyona Giriş ve Tasarımda Ayar

Hoca derse normalizasyon konusuyla başladı. Kendi ders kitabındaki ilgili bölümün sunularını anlatması zor ve fazla teorik bulduğu için, daha önce kullandığı başka bir kitabın (Elmasri ve Navathe'nin veritabanı kitabı) sunularını kullandığını söyledi. Bu kitabın bölümü daha pratik bir yol öneriyor. Konunun bir de ağır teorik kısmı var: Normalizasyonun algoritmalarla, ağır bir notasyonla çözümlendiği bölüm. Hoca o kısma girmeyeceğini, iyi bir tasarım için kullanılan teknik ve esaslara odaklanacağını söyledi.
<!-- BELİRSİZ: Kitap adı altyazıda "Elmasin'in kitabı" ve "Elmas Sinemati'nin kitabı" diye bozuk geçiyor; slaytlarda yalnız "Pearson Addison-Wesley" görünüyor. -->

Problemin karmaşıklığı şuradan gelir: Elimizde bir veri yığını ve onunla ilgili birçok nitelik vardır. Üniversite veritabanında ya da laboratuvarda kullanılan `COMPANY` veritabanında 8-10 tablo vardır. Bütün bu nitelikleri tek bir tabloda, tek bir dosyada toplamak mümkündü; neden birçok tabloya dağıtıyoruz? Çünkü her şeyi tek yerde toplamak bütünlük (integrity) problemlerine yol açar. Öte yandan çok küçük tablolara dağıtmak çok sayıda join demektir. Bu yüzden ortada bir yol tutturmak, tasarımda bir ayar (tuning) yapmak gerekir.

Bu ayar "iki kere iki dört" gibi değildir. Hoca kavramsal tasarımda söylediğini tekrarladı: Tasarım hem mühendislik hem de tecrübe gerektiren bir meleke, bir sanattır. Her meslekte tasarımcıların ayrı bir ekolü vardır ve bir işe çoğu zaman doğrudan tasarımcı olarak girilmez. Deterministik araçlar yoktur; ayar sezgisel kurallarla (heuristic) yapılır. Fiziksel tasarımda (dosya tipleri, indeksler, veri yapıları ve algoritmalar) da durum aynıdır, ama o bu dersin kapsamında değildir.

Tasarım akışı şöyledir: Kavramsal tasarım ER diyagramıyla kâğıda dökülür, ER diyagramı dönüşüm kurallarıyla ilişkisel model tablolarına çevrilir, ardından normalizasyon aşaması gelir. Hoca dönüşüm kurallarının "soğuk" kurallar olmadığını, her birinin bir anlamı olduğunu ve bu anlamın kavranması gerektiğini vurguladı.

Normal formlar 1NF, 2NF, 3NF, BCNF (Boyce-Codd normal formu), 4NF ve 5NF'dir. Bunlar doğruluğu artıran, performansı da gözeten, tabloları çok fazla parçalamadan belli bir kıvama getiren, herkesin kabul ettiği kurallar zinciridir. Kitap bunları iki kategoriye ayırır:

- Kısıtlı (restrictive) tanımlar: Yalnız birincil anahtarı esas alır.
- Genel (general) tanımlar: Bütün aday anahtarları esas alır. Birincil anahtar aday anahtarlar arasından seçildiği için diğer aday anahtarlar da potansiyel problem kaynağıdır.

> **Hocanın vurgusu:** Bütün kitaplarda pratikte tasarım BCNF'ye kadar yapılır. 4NF ve 5NF teoride kalır; hoca araştırdığını ve gerçek hayatta bunları uygulamaya çalışan pek olmadığını söyledi. Kitap bunlar için "peculiar" (garip) kelimesini kullanır. Bu dersin amacı 1NF, 2NF, 3NF ve BCNF'yi öğrenmek ve ilişkisel model tablolarını bu formlara getirmektir.

Normalizasyon sonunda tasarım "garip" bir hâle gelmez; birkaç tablo biraz daha parçalanır, ince bir ayar yapılır. Hedef mükemmel (perfect) değil, tatminkâr, iyi (good) bir tasarımdır. Bu ayar görünümler (view) üzerinde değil, temel (base) tablolar üzerinde yapılır: Görünümler dış dünyaya açılan, sayıca çok olabilen mantıksal yapılardır; tasarımın konusu ise kaç tablo olacağı ve hangi nitelikleri içereceğidir.

## 2. Gayriresmî Tasarım Kuralları

Kitap önce sağduyuya dayalı (common sense) dört gayriresmî kural verir, sonra daha biçimsel kavramlara geçer:

- Niteliklerin anlamı (semantiği) net olmalı.
- Tablolarda fazla, tekrar eden bilgi olmamalı.
- Gereksiz yer kaplayan ya da belirsizlik yaratan null değerler olmamalı.
- Sahte (spurious) kayıt üretilmemeli; tablolar kontrolsüz parçalanırsa birleştirilmeleri fazladan kayıtlar üretir. Parçalama (decomposition) belli bir kurala göre yapılmalıdır.

Birinci kural: Tablo ve nitelik adları düzgün olmalı, bir ad başka bir tabloda karışıklığa yol açacak biçimde kullanılmamalıdır. Bir tablo bir bütünlük, bir anlam ifade etmeli; içinde mümkün olduğunca birden çok varlık bulunmamalıdır. Başka varlıklarla tek bağ yabancı anahtarlardır. Örneğin `student` tablosunda öğrencinin bölümü için bir `dept_name` niteliği bulunur; ama bölümün bütün ayrıntıları öğrenci tablosuna konursa problem başlar. Aynı yapı `instructor`, `course` ve `section` tablolarında da vardır: `section` `course`'a bir yabancı anahtarla işaret eder. Bundan kaçmak mümkün değildir, ama yabancı anahtar ihtiyacının ötesine geçilmemelidir. Slayttaki ifade: Nitelikler mümkün olduğunca ayrı tutulmalı ve her tablo tek başına açıklanabilmelidir.

`COMPANY` veritabanında bu açıkça görülür: `EMPLOYEE` tablosunda işçilerin bilgileri ve çalıştıkları departmana yabancı anahtar vardır. `DEPARTMENT` tablosunda departman numarası, adı ve yöneticisi bulunur; yönetici bir işçi olduğu için `EMPLOYEE`'ye yabancı anahtardır. Departman konumları ve projeler de ayrı tablolardır. Böyle bir tasarım gereksinim listesinden kolayca kurulabilir ve kolayca anlatılabilir.

## 3. Güncelleme Anomalileri

Tablolar iyi tasarlanmazsa tekrarlar ortaya çıkar. İlk sonuç gereksiz yer kaybıdır. Daha önemlisi, hem tespiti hem çözümü daha zor olan anomalilerdir: Ekleme (insert), silme (delete) ve güncelleme (update) anomalileri.

Hoca bütün `COMPANY` niteliklerini tek tabloda düşünmek yerine yalnız işçi ve projeyi bir araya getirdi (ekrandan, 00:20:50):

```text
EMP_PROJ(Emp#, Proj#, Ename, Pname, No_hours)
```

**Güncelleme anomalisi:** P1 projesinin adını "Billing"den "Customer-Accounting"e değiştirmek, o projede çalışan 100 işçinin satırında değişiklik gerektirir. Tek bir yerde yapılmak istenen değişiklik pahalıya mal olur. Ayrıca projeye 101. işçi eklenirken proje adı yeniden girilir ve yanlış yazılabilir; böylece P1 bir satırda bir adla, başka satırda başka bir adla görünür. Ayrı bir kısıt (constraint) ya da assertion yazılmadıysa sistem buna itiraz etmez, çünkü hiçbir kısıtı bozulmamıştır.

**Ekleme anomalisi:** Bir proje ancak bir işçiyle birlikte girilebilir; işçisi olmayan bir proje tanımlanamaz. Ayrı bir proje tablosu olsaydı, iki yıl sonra işçi alacak bir proje de rahatça eklenebilirdi. Aynı şekilde bir işçi, bir projede çalışmıyorsa girilemez.

**Silme anomalisi:** Daha da kötüdür. Bir projeyi silmek, projede çalışan işçilerin satırlarını da siler. Tersine, projedeki son işçi silinirse proje bilgisi de kaybolur, oysa amaç projeyi silmek değildi.

Hoca, bu tasarımın arkasında çoğu zaman performans kaygısı olduğunu söyledi: `EMPLOYEE` ile `PROJECT` arasındaki join masraflıdır diye ikisi birleştirilir, ama bunun bedeli arka planda bu anomalilerdir. Aynı problem `EMP_DEPT` için de geçerlidir (ekrandan, 00:27:50): Departman bilgisi işçi tablosunda tutulursa bir departmanda 100 işçi varsa departman bilgisi 100 kez tekrar eder. 5 numaralı departmanın yöneticisi değişince bütün satırları güncellenmelidir; bunu tek satırdaki değişiklikle tamamlamak için arkada bir trigger yazmak gerekir.

Slayttaki ikinci kural: Ekleme, silme ve güncelleme anomalilerinden etkilenmeyen bir şema tasarlayın; anomali varsa not edin ki uygulamalar bunu hesaba katsın. Hoca bunu NoSQL veritabanlarına bağladı: Onlar karmaşık join'leri ve bütünlük kurallarını çoğu zaman uygulama seviyesine atar, klasik veritabanı anlamını bir parça kaybeder. "Key-value store", "graph store" gibi adlardaki "store" kelimesi de veriyi klasik veritabanı kurallarına göre değil, yalnız saklamak üzere tuttuklarını yansıtır. Genel yorum, bu sistemlerin dezavantajının uygulamanın yükünü artırması olduğudur.

## 4. Null Değerler

Üçüncü kural null'larla ilgilidir. Null'lar mümkün olduğunca az olmalıdır. Hoca slayttaki örneği kendi örnekleriyle değiştirdiğini söyledi: `EMPLOYEE` tablosunda bir ofis numarası niteliği olsun, ama ofis bilgisi işçilerin yalnız %10-15'i için mevcut olsun. O zaman 1000 işçinin 800'ünde null görünür. Çözüm tabloyu parçalamaktır:

```text
EMP_OFFICES(SSN, Office_number)
```

Yalnız ofisi olan işçiler bu tabloda tutulur. Bu bir join'e mal olur ama null'lardan kurtulmanın çok kolay bir yoludur. Hocanın ifadesiyle diğer problemler bu kadar kolay değildir.

Null'ların yol açtığı problemler:

- Boş yer kaybı.
- `GROUP BY`, toplama fonksiyonları (sayma, en büyük, en küçük) ve join'lerde ayrıca dikkat gerektirmesi.
- Farklı veritabanı sistemlerinin null'ları farklı ele alması, ortak bir zeminin dışına çıkılması.

Hoca dış birleştirmeleri (left, right, full outer join) hatırlattı: Bunlar eşleşmeyen satırları da görmek için tanımlanmıştır ve eşleşmeyen kısmı null ile doldurur. Null'ın anlamı da tek değildir: Bazı satırlar için nitelik uygulanamaz olabilir, değer var ama bilinmiyor olabilir ya da hiç mevcut olmayabilir. Null = Null karşılaştırması doğru değildir; null doğru, yanlış ve bilinmeyen değerleriyle üç değerli bir mantık ortaya çıkarır. Hoca bunun 0 ve 1'le çalışan makinenin felsefesine aykırı olduğunu söyledi.

## 5. Sahte Kayıtlar, Kayıpsız Birleştirme ve Bağımlılık Koruma

Dördüncü kural sahte (spurious) kayıtlarla ilgilidir. Join sonucunda hatalı, fazladan satırların ortaya çıkması problemidir. Birleştirmelerin kayıpsız (lossless) ve fazladan satır eklemeyen (non-additive) olması istenir: Parçalar birleştirildiğinde özgün tablo tam olarak geri gelmelidir.

Slayttaki örnekte `EMP_PROJ` tablosu iki parçaya ayrıldı: Birinde `Ename` ve `Plocation`, diğerinde `Plocation` ortak nitelik olmak üzere geri kalan sütunlar. Ortak nitelik olarak proje konumunun seçilmesi yanlıştır. Bir konumda birden çok proje ve işçi vardır; natural join yapılınca bir işçinin adı, o konumdaki başka işçilerin SSN'leriyle de eşleşir. Hoca, özgün tabloda 10 satır varsa birleştirmede 20-30 satır çıkabileceğini söyledi.

> **Hocanın vurgusu:** Doğru eşleşmeleri yakalamanın tek şartı, parçalamanın birincil anahtar ile yabancı anahtar ikilisi üzerinden yapılmasıdır. SQL dilbilgisi her türlü join'e izin verir ve bazı durumlarda başka join'ler de kullanılabilir, ama bilerek kullanılmalıdır.

Slayttaki kural: Tablolar kayıpsız birleştirme koşulunu sağlayacak biçimde tasarlanmalı, herhangi bir natural join sahte satır üretmemelidir. Bu özellik (property A) mutlaka sağlanmalıdır.

İkinci özellik bağımlılık korumadır (dependency preservation). Bir tablo içinde fonksiyonel bağımlılıklar tanımlanır (bir sonraki bölümde). Tablo parçalanınca bir fonksiyonel bağımlılığın nitelikleri iki farklı tabloya dağılırsa, ekleme ve silmelerde bu bağımlılığın sağlanıp sağlanmadığı ancak iki tablo birleştirilerek test edilebilir. Bu sisteme ayrı bir yük getirir. Bu yüzden bağımlılık koruma tercih edilir ama doğruluğu bozan bir şey değildir, performansı etkiler. Hoca ileride görülecek bir farkı önceden söyledi: 3NF bağımlılığı korur, BCNF korumaz ama daha katıdır; BCNF'de performanstan ödün verilir.

> **Ders sonrası not:** Büyük olasılıkla daha doğru ifade şudur: Her tablo için bağımlılığı koruyan kayıpsız bir 3NF ayrıştırması her zaman bulunabilir; BCNF ayrıştırması ise bazı durumlarda bağımlılıkları koruyamaz. Her BCNF ayrıştırması bağımlılık kaybettirmez.

## 6. Fonksiyonel Bağımlılık

Fonksiyonel bağımlılık (functional dependency, FD), iyi bir tasarım için elimizdeki temel malzemedir; normalizasyon adımları bu malzemeyle tanımlanır. 4NF ve 5NF bu malzemeyle tanımlanamaz; orada çok değerli bağımlılık (multivalued dependency) ve join bağımlılığı (join dependency) gibi kavranması daha zor bağımlılıklar kullanılır. 1NF, 2NF, 3NF ve BCNF ise aynı kategoridedir.

Tanım: Bir tablodaki $X$ nitelik kümesi, $X$'in değeri $Y$ için tek bir değer belirliyorsa $Y$'yi fonksiyonel olarak belirler. Hocanın sezgisel açıklaması: $X$'te aynı değer ortaya çıkınca $Y$'de de aynı değer ortaya çıkmalıdır. Biçimsel olarak, herhangi iki satır $t_1, t_2$ için:

$$t_1[X] = t_2[X] \implies t_1[Y] = t_2[Y]$$

Bu "$X$, $Y$'yi belirler" ya da "$Y$, $X$'e fonksiyonel bağımlıdır" diye okunur ve $X \rightarrow Y$ ile gösterilir. Diyagramlarda okla çizilir.

**Soru:** $X$'in $Y$'yi belirlemesi, $Y$'nin $X$'i belirlemesi demek midir? **Cevap:** Hayır. $X \rightarrow Y$, $Y \rightarrow X$'i gerektirmez.

Fonksiyonel bağımlılıklar gerçek hayattaki semantikten çıkar. Birincil anahtar diğer bütün nitelikleri belirler: Birincil anahtar tekrar etmez, ama tekrar etseydi aynı değerlerle gelirdi. Hocanın örneği TC kimlik numarasıdır: Kimlik numarası adı, soyadı, adresi ve telefonu belirler; ama ad kimlik numarasını belirlemez, çünkü aynı adı taşıyan başka kişiler vardır.

Slayttaki örnekler (`COMPANY` veritabanından):

- `SSN → ENAME`
- `PNUMBER → {PNAME, PLOCATION}`
- `{SSN, PNUMBER} → HOURS`

Son bağımlılıkta tek başına `SSN` saati belirlemez, çünkü bir işçi başka projelerde de çalışabilir; tek başına `PNUMBER` da belirlemez, çünkü projede başkaları başka miktarlarda çalışır. İkisi birlikte belirler. Bu bağımlılıkların semantiğe göre çıkarılıp belgelenmesi gerekir; normalizasyonda kullanılacaklardır.

Hoca iki örnek ekledi. Birincisi eyalet ve ehliyet numarasıdır: Bir eyalette bir ehliyet numarası tek kişiye verilir, dolayısıyla `{State, Driver_license_number} → SSN`. Ters yön ise bir kişinin birden çok ehliyeti (kamyon, tır gibi) olup olamayacağına bağlıdır. Hocaya göre bunları düşünmek konunun anlaşıldığını gösterir: "Vardır" denirse bir sonuç, "yoktur" denirse başka bir sonuç çıkar. İkincisi posta kodunun telefon alan kodunu belirlemesidir; hoca bunun ABD'de geçerli olduğunu, kaynağın da başka bir yer için geçerli olmadığına dair not düştüğünü söyledi.
<!-- BELİRSİZ: Hocanın posta kodu örneğinde Türkiye için ne söylendiği ve kaynaktaki notun hangi yerden söz ettiği altyazıdan net değil (00:44:46-00:45:12). -->

### 6.1 FD'ler bir kısıttır

Fonksiyonel bağımlılık tanımlamak bir kısıt tanımlamaktır. Veritabanının kendiliğinden sağladığı kısıtlar vardır: Alan (domain) kısıtı, `UNIQUE`, birincil anahtar ve yabancı anahtar kısıtı. Yabancı anahtar tanımlandıktan sonra onun sağlanmasıyla uğraşılmaz, sistem bunu üstlenir. Ama iş kurallarına, semantiğe göre tanımlanan FD'leri veritabanına aktarmak ve sağlatmak için ayrıca assertion ya da trigger yazmak gerekir. Hoca pratiklikten uzaklaşmanın burada başladığını söyledi: Karmaşık FD'lerin sağlanması veritabanından pek beklenmez, uygulamaya havale edilir. Veritabanı küçük dünyanın semantiğini bilemez.

Slayta göre FD'ler bütün tablo durumları (relation state) için sağlanmalıdır. Bir anahtar $K$, tablodaki bütün nitelikleri fonksiyonel olarak belirler. Aday anahtarlar birden çok olabilir ve tek, iki, üç ya da daha çok nitelikten oluşabilir. Bunları bulan bir algoritma vardır, ama ders kapsamında değildir; birkaç sezgisel örnek yapılacaktır.

### 6.2 FD örnek veriden çıkarılamaz

Slaytta `TEACH` tablosunun bir durumu vardır (ekrandan, 00:48:20):

| Teacher | Course | Text |
|---|---|---|
| Smith | Data Structures | Bartram |
| Smith | Data Management | Martin |
| Hall | Compilers | Hoffman |
| Brown | Data Structures | Horowitz |

Hoca tablonun zaten bir potansiyel probleme hazır olduğunu söyledi: Öğretmen, ders ve kitap bir aradadır. Bu örneğe bakarak söylenebilecek FD'ler yalnız bu örneği bağlar.

**Soru:** `TEACHER`, `COURSE`'u belirler mi? **Cevap:** Hayır. Smith iki farklı derste görünüyor.

**Soru:** `TEXT`, `COURSE`'u belirler mi? **Cevap:** Bu örnekte buna aykırı bir durum yok, dolayısıyla belirliyor olabilir. Bir öğrenci gerçek dünyada aynı kitabın farklı derslerde kullanıldığını söyledi; hoca da tam bu noktaya varmak istediğini belirtti.

> **Hocanın vurgusu:** Bir FD, verilen bir tablo örneğinden otomatik olarak çıkarılamaz; tablonun niteliklerinin semantiğini bilen biri tarafından açıkça tanımlanmalıdır. Örnek veri bazı FD'leri yalnız dışlayabilir. Semantiği bilen biri bir FD tanımlarsa, tablo örnekleri artık o kurala uymak zorundadır.

## 7. Çıkarım Kuralları ve Kapanış

Semantiğe göre tanımlanan FD'lerden yola çıkarak yeni FD'ler çıkarılabilir (infer). Hoca "refer" ile "infer"in farklı olduğunu hatırlattı. Armstrong'un üç temel çıkarım kuralı vardır (ekrandan, 00:51:00):

- IR1 (yansıma, reflexive): $Y \subseteq X$ ise $X \rightarrow Y$. Hocanın ifadesiyle çok basit, önemsiz (trivial) bir ifadedir: $XY$, $X$'i de $Y$'yi de belirler.
- IR2 (genişletme, augmentation): $X \rightarrow Y$ ise $XZ \rightarrow YZ$. ($XZ$, $X \cup Z$ demektir.)
- IR3 (geçişlilik, transitive): $X \rightarrow Y$ ve $Y \rightarrow Z$ ise $X \rightarrow Z$.

> **Ders sonrası not:** Altyazıda geçişlilik kuralının sonucu "X, Y'yi belirleyecektir" diye geçiyor (00:51:40). Slayttaki doğru ifade $X \rightarrow Z$'dir; büyük olasılıkla bir sürç ya da Whisper hatasıdır.

Slayta göre bu üç kural sağlam (sound) ve tam (complete) bir kümedir: Bunlarla türetilen her FD geçerlidir ve geçerli bütün FD'ler bunlardan türetilebilir. İşi kolaylaştıran üç ek kural daha vardır, böylece toplam altı kural olur:

- Ayrıştırma (decomposition): $X \rightarrow YZ$ ise $X \rightarrow Y$ ve $X \rightarrow Z$.
- Birleşim (union): $X \rightarrow Y$ ve $X \rightarrow Z$ ise $X \rightarrow YZ$.
- Sözde geçişlilik (pseudotransitivity): $X \rightarrow Y$ ve $WY \rightarrow Z$ ise $WX \rightarrow Z$.

Sözde geçişliliği hoca şöyle türetti: $X \rightarrow Y$, $W$ ile genişletilir ve $WX \rightarrow WY$ olur; $WY \rightarrow Z$ olduğu için geçişlilikle $WX \rightarrow Z$ elde edilir.

Bu kurallar iki şey için kullanılır:

- $F^+$ (F'nin kapanışı): Küçük dünyada tanımlanan $F$ kümesinden türetilebilen bütün FD'ler. Bu, ileride normalizasyon algoritmalarında kullanılır; derste kullanılmayacak.
- $X^+$ (X'in kapanışı): Bir nitelik ya da nitelik grubu $X$'in fonksiyonel olarak belirlediği bütün nitelikler. Birincil anahtar ve aday anahtar bulunurken bu kullanılacaktır.

Slaytta ayrıca iki FD kümesi $F$ ve $G$'nin denkliği (birinin kapanışının diğerini kapsaması) de geçiyor; hoca bunun anlaşılır olduğunu söyleyip geçti.

## 8. Minimal Fonksiyonel Bağımlılık Kümesi

FD'ler veritabanına sağlatılacaksa kümenin minimal olması istenir, çünkü her kural için bir trigger ya da assertion yazılacak ve her ekleme ya da silmede çalışacaktır. Minimal küme şu adımlarla bulunur:

- Her FD'nin sağ tarafı tek nitelik olacak şekilde yazılır.
- Gereksiz FD'ler atılır: Bir FD çıkarıldığında diğerlerinden türetilebiliyorsa fazladır. Hoca bunu esas adım saydı.
- Sol taraf küçültülür: $X \rightarrow A$'da $X$'ten bir nitelik çıkarıldığında kalan küme yine $A$'yı belirliyorsa, o nitelik atılır.

Hoca adımları bu sırayla anlattı. Slayttaki çözümlü örnekte ise sol taraf önce küçültüldü ("step 2"), gereksiz FD sonra atıldı ("step 3"). Kitaptaki algoritma da büyük olasılıkla bu sırayı izler. Hoca bu adımların ispatının zor olduğunu, sezgisel olarak kabul edilebileceğini söyledi.

**Örnek (ekrandan, 00:58:35):** $E = \{B \rightarrow A,\ D \rightarrow A,\ AB \rightarrow D\}$ için minimal küme:

- Sağ taraflar zaten tek nitelik.
- $AB \rightarrow D$'de sol taraf küçültülebilir mi? $B \rightarrow A$, iki tarafı $B$ ile genişletilince (IR2) $BB \rightarrow AB$, yani $B \rightarrow AB$ olur. $AB \rightarrow D$ ile geçişlilikten (IR3) $B \rightarrow D$ çıkar. Demek ki $A$'ya gerek yoktur; $AB \rightarrow D$ yerine $B \rightarrow D$ yazılır.
- Yeni küme $E' = \{B \rightarrow A,\ D \rightarrow A,\ B \rightarrow D\}$. Bütün sol taraflar tek niteliktir.
- $B \rightarrow D$ ve $D \rightarrow A$'dan geçişlilikle $B \rightarrow A$ türer; $B \rightarrow A$ gereksizdir.
- Sonuç: $\{B \rightarrow D,\ D \rightarrow A\}$.

Bu küme daha da küçültülemez: $B \rightarrow D$ çıkarılırsa $D \rightarrow A$'dan türetilemez, $D \rightarrow A$ çıkarılırsa $B \rightarrow D$'den türetilemez. Hoca, kurallar arasında dolaşırken "biraz göz gezdirmek" gerektiğini söyledi. Bu küme veritabanına sağlatılmak istenirse trigger yazılabilir, ama çoğu zaman bu yük veritabanına verilmez, gerekirse uygulama seviyesinde sağlanır.

> **Hocanın vurgusu:** Bu teorik kısım korkutmasın. Çoğu zaman gayriresmî kurallar ve ardından 3NF ve BCNF'ye kadar normalizasyon yeterlidir; orada kullanılacak malzeme birincil anahtar ve aday anahtarlardır.

## 9. Anahtar Bulma

Hoca slayta iki örnek ekledi ve birini çözdü (ekrandan, 01:04:20):

```text
R = {A, B, C, D, E, F, G, H, I, J}
F = { AB -> C, A -> DE, B -> F, F -> GH, D -> IJ }
```

Burada minimal küme yerine tablonun anahtarı ya da anahtarları aranır. Hoca, A niteliğinin bir ders, diğerlerinin şube gibi şeyler olabileceğini, ve tabloya nitelik eklendikçe tehlikenin arttığını söyledi. Seçilen $X$ bütün tabloyu belirliyor mu diye FD'ler ve çıkarım kurallarıyla bakılır. Birincil anahtarın tek nitelik olması istenir; bu yüzden önce $A^+$, $B^+$, $C^+$ denenir. Bunların $R$'yi vermediği görülür. Sonra ikili gruplara, aramayı kısaltmak için sol tarafta görünen niteliklerden başlanarak bakılır:

- $AB^+$: $\{A, B\}$
- $AB \rightarrow C$: $\{A, B, C\}$
- $A \rightarrow DE$: $\{A, B, C, D, E\}$
- $B \rightarrow F$: $\{A, B, C, D, E, F\}$
- $F \rightarrow GH$: $\{A, \dots, H\}$
- $D \rightarrow IJ$: $\{A, \dots, J\} = R$

Demek ki $AB^+ = R$ ve $AB$ bir anahtardır; slayta göre tek anahtardır. Kapanış, niteliğin üzerine (ya da sağına) artı konarak gösterilir. Başka ikili ya da üçlü anahtarlar olsaydı onlar da aday anahtar olurdu ve aralarından en minimalini birincil anahtar seçmek daha isabetli olurdu.

İkinci örneği hoca çözmedi, denemeyi öğrencilere bıraktı (Örnek Sorular bölümüne bakın). Tek niteliklerin ve $AB^+$'nın $R$'yi vermediğini, üçlü gruplardan birinin ($ABD$) verdiğini söyledi.

## 10. Anahtar Tanımları ve Asal Nitelik

Normalizasyon, tatminkâr olmayan (bad) tablolardan kurtulup iyi (good) bir tasarım elde etmektir. Önce 2NF ve 3NF'nin birincil anahtara dayalı kısıtlı tanımları, sonra aday anahtarlara dayalı genel tanımları görülecektir. 1NF anahtara bağımlılıkla ilgili değildir, başka bir meseledir. Normal formlar iç içedir: 3NF'yi sağlayan bir tasarım 2NF'yi de sağlar; BCNF'deki bir tasarım 1NF, 2NF ve 3NF'yi sağlar; ama 2NF'deki bir tasarım 3NF'yi ya da BCNF'yi sağlamayabilir.

Hoca denormalizasyonu da hatırlattı: Sistem bütünlük problemlerine ve anomalilere tahammül edebiliyorsa, tablolar parçalanmadan tek tabloda bırakılabilir; anomaliler uygulamada çözülür.

Tanımlar:

- **Süper anahtar (superkey):** Hiçbir iki satırın aynı değeri taşımadığı nitelik kümesi.
- **Anahtar (key):** Herhangi bir niteliği çıkarılınca artık süper anahtar olmayan süper anahtar, yani minimal süper anahtar. Her süper anahtar anahtar değildir.
- **Aday anahtar (candidate key):** Tablonun birden çok anahtarı varsa her biri. Bunlardan biri keyfî olarak (arbitrarily) birincil anahtar seçilir; hocaya göre en minimalini seçmek daha isabetlidir.
- **Asal nitelik (prime attribute):** Herhangi bir aday anahtarın içinde yer alan nitelik. Hoca "prime" ile "primary"nin farklı olduğunu vurguladı. Hiçbir aday anahtarda yer almayan nitelik asal olmayandır (non-prime). Bu kavramlar 2NF ve 3NF kurallarında geçecektir.

## 11. Birinci Normal Form (1NF)

Hoca 1NF'nin özünü "bütün nitelikler anahtara bağlı olmalı" diye özetledi; bu zaten anahtarın tanımıdır. Asıl şart her niteliğin atomik, tek bir değer olmasıdır. Çok değerli nitelikler, bileşik çok değerli nitelikler ya da iç içe (nested) tablolar 1NF'ye, dolayısıyla ilişkisel model tablo tanımına aykırıdır. Bir nitelik tamsayılar kümesi, adlar kümesi, renkler kümesi gibi bir dizi olmamalıdır.

Hoca bugün birçok sistemin, PostgreSQL dahil, bu esnekliği tanıdığını söyledi. Böyle bir nitelik veritabanınca 1NF kabul edilir; parçalama ve işleme, semantiği bilen uygulamaya bırakılır. Çok değerli bir nitelik en fazla üç değer alıyorsa üç ayrı niteliğe dağıtılabilir; ama herkes için üç değer olmadığından null'lar çıkar ve sorgular zorlaşır. Bu yüzden ilişkisel diye geçen veritabanlarında bile çok değerli niteliklere çoğu zaman izin verilir.

### 11.1 Çok değerli nitelik örneği

Slayttaki örnek (ekrandan, 01:13:15):

```text
DEPARTMENT(Dname, Dnumber, Dmgr_ssn, Dlocations)

Research        5  333445555  {Bellaire, Sugarland, Houston}
Administration  4  987654321  {Stafford}
Headquarters    1  888665555  {Houston}
```

`Dlocations` atomik değildir. İki çözüm vardır:

- Konumu satırlara açmak ve `Dlocation`'ı birincil anahtara dahil etmek: `Research` satırı her konum için tekrar eder (slayttaki 1NF sürümü fazlalık içerir).
- Ayrı bir `(Dnumber, Dlocation)` tablosu kurmak.

İkisi de atomikliği sağlar; hangisinin seçileceği duruma göre değişir.

### 11.2 İç içe tablo örneği

Hem çok değerli hem bileşik bir nitelik, niteliğin içinde bir tablo demektir. Bir işçinin çalıştığı projeler ve her projedeki saatleri böyledir; tek bir satırda küçük bir tablo ortaya çıkar. Çözüm yine parçalamaktır (ekrandan, 01:38:20):

```text
EMP_PROJ(Ssn, Ename, {PROJS(Pnumber, Hours)})
  -> EMP_PROJ1(Ssn, Ename)
  -> EMP_PROJ2(Ssn, Pnumber, Hours)
```

**Soru:** Bunu `(Ssn, Pnumber)` birincil anahtarlı tek tabloda yapsaydık ne tekrar ederdi? **Cevap:** `Ename` tekrar ederdi. Bir kişi 10 projede çalışıyorsa adı 10 kez yazılırdı. Bu yüzden parçalamak daha isabetlidir. Departman konumlarında ise konumun başka ayrıntısı olmadığı için tek tabloda anahtara dahil etmek tekrar yaratmıyordu; bu da semantiğe bağlıdır.

Hoca dersin sonlarında slayta eklediği bir örneği daha gösterdi: Bir aday kişinin iş geçmişi, onun içinde de maaş geçmişi olan iki seviyeli iç içe bir tablo. 1NF için her iç içe tabloya ayrı bir tablo açılır ve dış anahtar içe taşınır (ekrandan, 01:38:20):

```text
CANDIDATE(Ssn, Name,
  {JOB_HIST(Company, Highest_position,
     {SAL_HIST(Year, Max_sal)})})

  -> CANDIDATE_1(Ssn, Name)
  -> CANDIDATE_JOB_HIST(Ssn, Company, Highest_position)
  -> CANDIDATE_SAL_HIST(Ssn, Company, Year, Max_sal)
```

## 12. İkinci Normal Form (2NF)

2NF'den itibaren birincil anahtar kavramı kullanılır. Önce bir tanım gerekir:

**Tam fonksiyonel bağımlılık (full functional dependency):** $Y \rightarrow Z$'de $Y$'den herhangi bir nitelik çıkarıldığında bağımlılık artık geçerli değilse $Z$, $Y$'ye tam bağımlıdır. $Y$'nin bir alt kümesi $Z$'yi belirliyorsa tam bağımlılık yoktur; $Y$ bütün hâliyle $Z$'yi belirlemelidir.

- `{SSN, PNUMBER} → HOURS` tam bağımlılıktır; ikisinden biri çıkarılırsa saat belirlenemez.
- `{SSN, PNUMBER} → ENAME` tam bağımlılık değildir; `SSN → ENAME` zaten geçerlidir, `PNUMBER`'ın adla ilgisi yoktur.

**2NF kuralı:** "All attributes depend on the whole key." Asal olmayan her nitelik birincil anahtara tam fonksiyonel bağımlı olmalıdır.

Hoca bu sunuda en çok bu slaydı beğendiğini, FD'lerin oklarla çok net gösterildiğini söyledi (ekrandan, 01:22:10):

```text
EMP_PROJ(Ssn, Pnumber, Hours, Ename, Pname, Plocation)
FD1: {Ssn, Pnumber} -> Hours
FD2: Ssn -> Ename
FD3: Pnumber -> {Pname, Plocation}
```

Birincil anahtar `{Ssn, Pnumber}`'dır. Hoca bunun ezbere değil, FD'lerden çıkarılması gerektiğini söyledi. `Ename` anahtarın yalnız `Ssn` kısmına, `Pname` ve `Plocation` yalnız `Pnumber` kısmına bağlıdır. Tam bağımlılık olmadığı için tablo 2NF değildir. Parçalama yine kayıpsız olmalıdır; her belirleyen, belirlediği niteliklerle aynı tabloya konur:

```text
EP1(Ssn, Pnumber, Hours)
EP2(Ssn, Ename)
EP3(Pnumber, Pname, Plocation)
```

Üç tablonun her biri 2NF'dir: `EP2` ve `EP3`'te anahtar tek nitelik olduğu için tam bağımlılık kendiliğinden sağlanır; `EP1`'de `Hours` iki niteliğe birden bağlıdır. Hoca bu kuralların dersin başındaki anomali örneklerini ortadan kaldırdığına dikkat çekti.

## 13. Üçüncü Normal Form (3NF)

**Geçişli fonksiyonel bağımlılık:** $X \rightarrow Y$ ve $Y \rightarrow Z$'den türetilebilen $X \rightarrow Z$ bağımlılığıdır. $X$'ten $Z$'ye ulaşırken arada bir $Y$ niteliği varsa problem vardır ve anomaliler çıkabilir (ekrandan, 01:21:00):

- `SSN → DMGRSSN` geçişlidir, çünkü `SSN → DNUMBER` ve `DNUMBER → DMGRSSN` geçerlidir.
- `SSN → ENAME` geçişli değildir, çünkü `SSN → X` ve `X → ENAME` olan bir $X$ yoktur.

**3NF kuralı:** "All attributes depend on nothing but the key." Asal olmayan nitelikler yalnız anahtara bağlı olmalı, aradaki başka bir niteliğe bağlı olmamalı, yani geçişli bağımlılık bulunmamalıdır.

Slayttaki örnek (ekrandan, 01:22:10):

```text
EMP_DEPT(Ename, Ssn, Bdate, Address, Dnumber, Dname, Dmgr_ssn)
```

`Ssn`, `Dname`'i de belirler: İşçinin çalıştığı bir departman, o departmanın da bir adı vardır. Ama `Dname` ve `Dmgr_ssn`, birincil anahtar dışındaki `Dnumber`'a bağlıdır. Fazlalık ve anomaliler buradan çıkar. Tablo ikiye ayrılır:

```text
ED1(Ename, Ssn, Bdate, Address, Dnumber)
ED2(Dnumber, Dname, Dmgr_ssn)
```

`Dnumber` her iki tabloda tekrar etmelidir; aksi hâlde natural join yapılamaz. Ortak nitelik birincil anahtar ve yabancı anahtar olmalıdır. Dersin başındaki konum üzerinden yapılan yanlış parçalama, birleştirmede fazladan kayıtlar üretmişti.

## 14. LOTS Örneği: Kısıtlı ve Genel 2NF

`COMPANY` dışında bir örnek (ekrandan, 01:29:00):

```text
LOTS(Property_id#, County_name, Lot#, Area, Price, Tax_rate)
FD1: Property_id# -> {County_name, Lot#, Area, Price, Tax_rate}
FD2: {County_name, Lot#} -> {Property_id#, Area, Price, Tax_rate}
FD3: County_name -> Tax_rate
FD4: Area -> Price
```

Hoca `LOTS`'u arazi parselleri, `County`'yi de bölge (mahalle) olarak yorumladı. Parsel numarası (`Lot#`) bir bölge içinde tektir, ama farklı bölgelerde aynı numara olabilir. Hocanın örneği: Esenler'de 50, Bayrampaşa'da 30 parsel varsa ve numaralar 1'den başlıyorsa, anahtar bölge adı ile parsel numarasıdır. Bir de tapu kadastronun kullandığı, ülke çapında tek bir `Property_id#` vardır. Demek ki semantiğe göre birincil anahtarın yanında bir ya da birden çok nitelik grubu da anahtar olabilir. `Tax_rate` bölgeye bağlı vergi oranıdır; `Price` alana göre belirlenir.

Kısıtlı tanıma göre tablo 2NF'dir: Birincil anahtar tek nitelikli olduğu için bütün nitelikler anahtarın tamamına bağlıdır. Ama genel tanım bütün aday anahtarları hesaba katar: `Tax_rate`, `{County_name, Lot#}` aday anahtarının bir kısmına bağlıdır. Bu yüzden `LOTS` kısıtlı 2NF'dir ama genel 2NF değildir. Genel tanımlar bir sonraki derse kaldı. Slayttaki 2NF parçalaması:

```text
LOTS1(Property_id#, County_name, Lot#, Area, Price)   FD1, FD2, FD4
LOTS2(County_name, Tax_rate)                           FD3
```

3NF'de geçişlilik aranır. `Property_id# → County_name → Tax_rate` ve `Property_id# → Area → Price` geçişli bağımlılıklardır; `Price` yalnız `Area`'ya bağlıdır. Bunlar 3NF'ye aykırıdır. Parçalama `County_name, Tax_rate` ve `Area, Price` için yapılır; `County_name` ve `Area` ana tabloda kalır ki join yapılabilsin:

```text
LOTS1A(Property_id#, County_name, Lot#, Area)   FD1, FD2
LOTS1B(Area, Price)                              FD4
LOTS2(County_name, Tax_rate)                     FD3

LOTS (1NF) -> LOTS1, LOTS2 (2NF) -> LOTS1A, LOTS1B, LOTS2 (3NF)
```

Hoca bu konunun egzersizle pekiştirilmesi gerektiğini, en kolay yolun alıştırma çözmek olduğunu söyledi.

## 15. Özet Tablo

Hoca üç normal formu kitaptaki özet tabloyla toparladı (ekrandan, 01:29:00, sonraki slayt önizlemesi; 01:38:20):

| Normal form | Test | Çözüm (normalizasyon) |
|---|---|---|
| 1NF | Çok değerli nitelik ya da iç içe tablo olmamalı. | Her çok değerli nitelik ya da iç içe tablo için yeni tablo kur. |
| 2NF | Birincil anahtarı birden çok nitelikli tablolarda, anahtar olmayan nitelik anahtarın bir kısmına fonksiyonel bağımlı olmamalı. | Her kısmi anahtar ve ona bağlı nitelikler için yeni tablo kur; özgün birincil anahtar ve ona tam bağlı nitelikler bir tabloda kalsın. |
| 3NF | Anahtar olmayan bir nitelik başka anahtar olmayan nitelik(ler)ce belirlenmemeli; anahtar olmayan niteliğin birincil anahtara geçişli bağımlılığı olmamalı. | Belirleyen anahtar olmayan nitelik(ler) ve belirlediği nitelikler için yeni tablo kur. |

Hoca özetleri şöyle hatırlattı:

- 1NF: "All attributes depend on the key." Çok değerli nitelik varsa bozulur.
- 2NF: "All attributes depend on the whole key." Tam fonksiyonel bağımlılık.
- 3NF: "All attributes depend on nothing but the key." Geçişlilik yok.

Birincil anahtarı tek nitelikli tablolar kısıtlı 2NF'yi kendiliğinden sağlar; problem birden çok nitelikli anahtarlarda başlar. 3NF için ise anahtar tek nitelikli olsa da bakılmalıdır, çünkü asal olmayan nitelikler başka bir niteliğe bağlı olmamalıdır. Geriye genel tanımlar ve BCNF kaldı.

> **Ek bilgi (derste anlatılmadı):** Genel tanımlarda "birincil anahtar" yerine "her aday anahtar" konur. Genel 2NF'de asal olmayan hiçbir nitelik herhangi bir aday anahtarın bir kısmına bağlı olmamalıdır. BCNF ise her önemsiz olmayan $X \rightarrow A$ bağımlılığında $X$'in süper anahtar olmasını ister; 3NF'den daha katıdır.

## Örnek Sorular

**1.** (derste sözlü, 00:41:04) $X \rightarrow Y$ ise $Y \rightarrow X$ de geçerli midir?

Cevap (derste verildi): Hayır. $X$'in $Y$'yi belirlemesi, $Y$'nin $X$'i belirlemesini gerektirmez. Örneğin kimlik numarası adı belirler, ad kimlik numarasını belirlemez.

**2.** (ekrandan, 00:48:20; derste sözlü) `TEACH` tablosu örneğinde (Smith–Data Structures–Bartram, Smith–Data Management–Martin, Hall–Compilers–Hoffman, Brown–Data Structures–Horowitz) `TEACHER → COURSE` ve `TEXT → COURSE` geçerli olabilir mi?

Cevap (derste verildi): `TEACHER → COURSE` dışlanır, çünkü Smith iki farklı derste görünüyor. `TEXT → COURSE` bu örnekte çürütülmüyor, olası bir FD'dir. Ama gerçek dünyada aynı kitap farklı derslerde kullanılabilir; FD'nin geçerliliğine örnek veriyle değil, semantikle karar verilir.

**3.** (ekrandan, 00:58:35) $E = \{B \rightarrow A,\ D \rightarrow A,\ AB \rightarrow D\}$ kümesinin minimal örtüsünü bulun.

Cevap (derste verildi): $B \rightarrow A$'dan genişletmeyle $B \rightarrow AB$, geçişlilikle $B \rightarrow D$ çıkar; $AB \rightarrow D$ yerine $B \rightarrow D$ yazılır. $B \rightarrow D$ ve $D \rightarrow A$'dan $B \rightarrow A$ türediği için atılır. Minimal örtü $\{B \rightarrow D,\ D \rightarrow A\}$'dır.

**4.** (ekrandan, 01:04:20) $R = \{A, B, C, D, E, F, G, H, I, J\}$, $F = \{AB \rightarrow C,\ A \rightarrow DE,\ B \rightarrow F,\ F \rightarrow GH,\ D \rightarrow IJ\}$ için tablonun anahtarı nedir?

Cevap (derste verildi): $AB^+ = \{A,B\} \rightarrow \{A,B,C\} \rightarrow \{A,B,C,D,E\} \rightarrow \{A,\dots,F\} \rightarrow \{A,\dots,H\} \rightarrow R$. $A^+$ ve $B^+$ tek başına $R$'yi vermez. Tek anahtar $AB$'dir.

**5.** (ekrandan, 01:04:20) Aynı $R$ için $G = \{AB \rightarrow C,\ BD \rightarrow EF,\ AD \rightarrow GH,\ A \rightarrow I,\ H \rightarrow J\}$ verilirse anahtar nedir? $ABD$ tek anahtar mı?

> **Çözüm (derste verilmedi):** $A$, $B$ ve $D$ hiçbir FD'nin sağ tarafında yer almaz, bu yüzden her anahtarda bulunmalıdır. $AB^+ = \{A, B, C, I\}$ olduğundan $AB$ anahtar değildir. $ABD^+$: $AB \rightarrow C$, $BD \rightarrow EF$, $AD \rightarrow GH$, $A \rightarrow I$, $H \rightarrow J$ ile $\{A, B, C, D, E, F, G, H, I, J\} = R$ olur. Her anahtar $ABD$'yi içermek zorunda olduğu ve $ABD$ zaten süper anahtar olduğu için tek anahtar $ABD$'dir. Sonuç, bütün nitelik altkümeleri python ile denenerek doğrulandı.

**6.** (derste sözlü, 01:15:35) İşçi ve projelerini `(SSN, Pnumber)` anahtarlı tek bir tabloda tutsaydık hangi nitelik tekrar ederdi?

Cevap (derste verildi): `Ename`. Bir kişi 10 projede çalışıyorsa adı 10 satırda tekrar eder; bu yüzden `EMP_PROJ1(Ssn, Ename)` ve `EMP_PROJ2(Ssn, Pnumber, Hours)` diye parçalamak daha isabetlidir.

**7.** (ekrandan, 01:29:00) `LOTS` tablosu neden kısıtlı 2NF olduğu hâlde genel 2NF değildir? 3NF'ye nasıl getirilir?

Cevap (derste verildi): Birincil anahtar `Property_id#` tek nitelikli olduğu için kısıtlı tanıma göre 2NF'dir. Ama `Tax_rate`, aday anahtar `{County_name, Lot#}`'ın bir parçası olan `County_name`'e bağlıdır; genel 2NF bozulur. 2NF için `LOTS2(County_name, Tax_rate)` ayrılır. 3NF için `Area → Price` geçişli bağımlılığı `LOTS1B(Area, Price)` olarak ayrılır, kalan tablo `LOTS1A(Property_id#, County_name, Lot#, Area)` olur.

## Dersin Toparlaması

Bu derste ilişkisel model tasarımının son adımı olan normalizasyona girildi. Önce iyi bir tasarımın gayriresmî kuralları görüldü: Anlamı net tablolar, tekrar ve anomali üretmeyen yapı, az null ve sahte kayıt üretmeyen kayıpsız parçalama. Ardından biçimsel malzeme kuruldu: Fonksiyonel bağımlılık, Armstrong çıkarım kuralları, kapanış ($X^+$), minimal FD kümesi ve anahtar bulma. Bu malzemeyle 1NF (atomiklik), 2NF (birincil anahtara tam bağımlılık) ve 3NF (geçişli bağımlılık olmaması) tanımlandı; `EMP_PROJ`, `EMP_DEPT` ve `LOTS` örnekleri adım adım parçalandı.

`LOTS` örneği, yalnız birincil anahtara bakan kısıtlı tanımların yetmeyebileceğini gösterdi. Bir sonraki derste genel (aday anahtarlara dayalı) normal formlar ve BCNF ile konu tamamlanacak, örnekler çözülecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
