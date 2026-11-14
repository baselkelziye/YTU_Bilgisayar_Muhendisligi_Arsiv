# Ders 7 Çalışma Özeti

## Genel Konular

- Normalizasyona giriş ve kaynak
  - Bu derste ilişkisel model tasarımının son aşaması olan fonksiyonel bağımlılıklar ve normalizasyon işlendi. Hoca, kendi ders kitabındaki bölümü fazla teorik bulduğu için daha önce kullandığı başka bir kitabın (Elmasri ve Navathe'nin veritabanı kitabı) sunularını kullandı.
  - Tasarım akışı: Kavramsal tasarım (ER diyagramı), ilişkisel model tablolarına dönüşüm, ardından normalizasyon. Normalizasyon yapılan tasarımı "mükemmel" değil "iyi" (good) bir kıvama getirir.
  - Bütün nitelikleri tek tabloda toplamak bütünlük (integrity) problemlerine, çok küçük tablolara bölmek ise çok sayıda join'e yol açar. Ortada bir yol tutturmak, tasarımda bir ayar (tuning) yapmak gerekir. Bu iş bilimle sanatın karışımıdır; deterministik araçlar yoktur, sezgisel kurallarla ilerlenir.
  - Normalizasyon görünümler (view) üzerinde değil, temel (base) tablolar üzerinde yapılır.
- Gayriresmî tasarım kuralları (informal guidelines)
  - Anlamın (semantik) net olması: Tablo ve nitelik adları düzgün olmalı, bir tablo tek bir varlığı ya da bağıntıyı anlatmalı. Başka varlıklarla bağ yalnız yabancı anahtarla kurulmalı.
  - Fazla (tekrar) bilgi ve güncelleme anomalileri: Tekrar yer kaybına, daha önemlisi ekleme (insert), silme (delete) ve güncelleme (update) anomalilerine yol açar.
  - Null değerlerin az olması: Çok null boş yer kaplar, `COUNT` gibi toplama fonksiyonlarında ve join'lerde belirsizlik yaratır, üç değerli mantık ortaya çıkarır.
  - Sahte (spurious) kayıt üretmemek: Tablo parçalanırken (decomposition) birleştirmenin kayıpsız (lossless, non-additive) olması gerekir.
- Anomali örnekleri: `EMP_PROJ` (ekrandan, 00:20:50)
  - `EMP_PROJ(Emp#, Proj#, Ename, Pname, No_hours)` tablosunda P1 projesinin adını değiştirmek, projede çalışan bütün işçilerin satırında değişiklik gerektirir (güncelleme anomalisi). Yanlış yazılmış bir proje adı sistemce fark edilmez.
  - Ekleme anomalisi: İşçisi olmayan bir proje, projesi olmayan bir işçi eklenemez.
  - Silme anomalisi: Projeyi silmek işçileri de siler; projedeki son işçiyi silmek projeyi de siler.
  - Aynı problemler `EMP_DEPT` için de geçerlidir: Bir departmandaki her işçi için departman bilgisi tekrar eder.
- Null örneği
  - İşçilerin yalnız %10-15'inin ofis bilgisi varsa, bu bilgi ayrı bir `EMP_OFFICES(SSN, Office_number)` tablosuna alınır. Bir join'e mal olur ama null'lardan kurtulunur.
- Kayıpsız birleştirme ve bağımlılık koruma
  - Kayıpsız birleştirme (lossless join) mutlaka sağlanmalıdır. Ortak nitelik olarak birincil anahtar ile yabancı anahtar seçilmelidir; slayttaki gibi proje konumu (`Plocation`) üzerinden parçalama birleştirmede fazladan, sahte kayıtlar üretir.
  - Bağımlılık koruma (dependency preservation) istenen ama şart olmayan bir özelliktir. Bir fonksiyonel bağımlılık iki tabloya dağılırsa ancak join ile denetlenebilir; bu doğruluğu değil performansı etkiler.
- Fonksiyonel bağımlılık (FD)
  - $X \rightarrow Y$: İki satırda $X$ aynıysa $Y$ de aynı olmalıdır. $X \rightarrow Y$, $Y \rightarrow X$ demek değildir.
  - FD'ler gerçek dünyanın semantiğinden çıkar, örnek veriye bakılarak çıkarılamaz; tablodaki bir örnek ancak bazı FD'leri dışlayabilir. `TEACH` tablosunda `TEACHER → COURSE` dışlanır, `TEXT → COURSE` olabilir (ekrandan, 00:48:20).
  - Örnekler: `SSN → ENAME`, `PNUMBER → {PNAME, PLOCATION}`, `{SSN, PNUMBER} → HOURS`. Hocanın eklediği örnekler: Eyalet ve ehliyet numarası kişiyi belirler; posta kodu alan kodunu belirler.
  - FD'ler bir kısıttır; veritabanı bunları kendiliğinden sağlamaz, ancak assertion ya da trigger ile sağlanabilir. Pratikte çoğu zaman uygulamaya bırakılır.
- Çıkarım kuralları (Armstrong) (ekrandan, 00:51:00)
  - IR1 (yansıma): $Y \subseteq X$ ise $X \rightarrow Y$.
  - IR2 (genişletme): $X \rightarrow Y$ ise $XZ \rightarrow YZ$.
  - IR3 (geçişlilik): $X \rightarrow Y$ ve $Y \rightarrow Z$ ise $X \rightarrow Z$.
  - Ek kurallar: Ayrıştırma ($X \rightarrow YZ$ ise $X \rightarrow Y$, $X \rightarrow Z$), birleşim ($X \rightarrow Y$, $X \rightarrow Z$ ise $X \rightarrow YZ$), sözde geçişlilik ($X \rightarrow Y$, $WY \rightarrow Z$ ise $WX \rightarrow Z$).
  - $F^+$: $F$'den türetilebilen bütün FD'ler. $X^+$: $X$'in belirlediği bütün nitelikler (kapanış). Anahtar ve aday anahtar bulmada $X^+$ kullanılır.
- Minimal FD kümesi (ekrandan, 00:58:35)
  - Adımlar: Sağ tarafları tek niteliğe indir; sol taraftaki gereksiz nitelikleri at; diğerlerinden türetilebilen FD'leri at.
  - Örnek: $E = \{B \rightarrow A,\ D \rightarrow A,\ AB \rightarrow D\}$ için minimal küme $\{B \rightarrow D,\ D \rightarrow A\}$'dır.
- Anahtar bulma (ekrandan, 01:04:20)
  - $R = \{A, \dots, J\}$, $F = \{AB \rightarrow C,\ A \rightarrow DE,\ B \rightarrow F,\ F \rightarrow GH,\ D \rightarrow IJ\}$ için $AB^+ = R$; tek anahtar $AB$'dir.
  - İkinci örnek $G = \{AB \rightarrow C,\ BD \rightarrow EF,\ AD \rightarrow GH,\ A \rightarrow I,\ H \rightarrow J\}$ için slayt $ABD^+ = R$ verir ve "tek anahtar mı?" diye sorar; derste çözülmedi.
- Anahtar tanımları
  - Süper anahtar: İki satırın aynı değeri taşımadığı nitelik kümesi. Anahtar: Minimal süper anahtar. Aday anahtarlardan biri birincil anahtar seçilir.
  - Asal (prime) nitelik: Herhangi bir aday anahtarın içindeki nitelik. Değilse asal olmayan (non-prime). "Prime" ile "primary" farklıdır.
- Normal formlar
  - 1NF: Nitelikler atomik olmalı; çok değerli nitelik ve iç içe (nested) tablo olmamalı. `DEPARTMENT(Dname, Dnumber, Dmgr_ssn, Dlocations)` için konumlar ya anahtara katılarak satırlara açılır ya da ayrı `(Dnumber, Dlocation)` tablosuna alınır (ekrandan, 01:13:15). İç içe `EMP_PROJ(Ssn, Ename, {PROJS(Pnumber, Hours)})` tablosu `EMP_PROJ1(Ssn, Ename)` ve `EMP_PROJ2(Ssn, Pnumber, Hours)` olur (ekrandan, 01:38:20).
  - Tam fonksiyonel bağımlılık: $Y \rightarrow Z$'de $Y$'nin hiçbir alt kümesi $Z$'yi belirlemiyorsa. `{SSN, PNUMBER} → HOURS` tamdır; `{SSN, PNUMBER} → ENAME` tam değildir.
  - 2NF: Asal olmayan her nitelik birincil anahtara tam bağımlıdır. `EMP_PROJ` → `EP1(Ssn, Pnumber, Hours)`, `EP2(Ssn, Ename)`, `EP3(Pnumber, Pname, Plocation)` (ekrandan, 01:22:10).
  - 3NF: Asal olmayan nitelik anahtara geçişli bağımlı olmamalıdır. `EMP_DEPT` → `ED1(Ename, Ssn, Bdate, Address, Dnumber)`, `ED2(Dnumber, Dname, Dmgr_ssn)`.
  - `LOTS` örneği (ekrandan, 01:29:00): Kısıtlı (restrictive) 2NF'dir ama genel 2NF değildir. 3NF için `County_name → Tax_rate` ve `Area → Price` ayrı tablolara alınır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Tasarım "iki kere iki dört" gibi değildir
  - Hem mühendislik hem tecrübe isteyen bir meleke gerekir. Hedef mükemmel değil, tatminkâr (good) bir tasarımdır.
- Pratikte BCNF'ye kadar gidilir
  - 4NF ve 5NF teoride kalır; gerçek hayatta pek uygulanmaz, anlaşılması zor ve "garip" (peculiar) bağımlılıklara (çok değerli bağımlılık, join bağımlılığı) dayanır.
- Kayıpsız birleştirme mutlaka, bağımlılık koruma tercihen
  - Parçalama birincil anahtar ve yabancı anahtar üzerinden yapılmalıdır; aksi hâlde birleştirme sahte kayıt üretir.
- FD'ler örnek veriden çıkarılmaz
  - Semantiği bilen biri tarafından açıkça tanımlanmalıdır; örnek veri yalnız bazı FD'leri çürütebilir.
- Üç kuralın özeti
  - 1NF: "All attributes depend on the key." 2NF: "All attributes depend on the whole key." 3NF: "All attributes depend on nothing but the key."
- ER'den tabloya dönüşüm kuralları ezber değildir
  - Her kuralın arkasında bir anlam vardır; tasarım konusuna önem verilmelidir.
- NoSQL ile karşılaştırma
  - Anomaliler tasarımda çözülmezse uygulamada çözülmelidir. NoSQL sistemleri karmaşık join'leri ve bütünlük kurallarını çoğu zaman uygulamaya bırakır; "key-value store" gibi adlardaki "store" kelimesi bunu yansıtır.

## Kısa Tekrar Notları

- Tek dev tablo: Anomali. Çok küçük tablolar: Çok join. Ortası aranır.
- Üç anomali: Ekleme, silme, güncelleme.
- Null'lar: Boş yer, toplama ve join'de belirsizlik, üç değerli mantık.
- Parçalama: Kayıpsız birleştirme şart (PK–FK üzerinden), bağımlılık koruma tercih.
- $X \rightarrow Y$: Aynı $X$, aynı $Y$. Ters yön gerekmez.
- Armstrong: Yansıma, genişletme, geçişlilik. Ek: Ayrıştırma, birleşim, sözde geçişlilik.
- $X^+ = R$ ise $X$ süper anahtardır; minimalse anahtardır.
- Minimal küme: Sağ tek nitelik, solu küçült, gereksiz FD'yi at.
- Asal nitelik: Bir aday anahtarın parçası.
- 1NF atomik; 2NF tam bağımlılık; 3NF geçişli bağımlılık yok.
- Kısıtlı tanımlar yalnız birincil anahtara, genel tanımlar bütün aday anahtarlara bakar.

## Detaylı Açıklamalar

- Normalizasyon neden gerekir?
  - Bir veritabanındaki bütün nitelikler tek bir tabloda toplanabilirdi. Bunun bedeli tekrar eden veridir. `EMP_PROJ` örneğinde bir projenin adı o projede çalışan her işçinin satırında tekrar eder. Proje adı değişince bütün bu satırlar güncellenmelidir; yalnız birinde değişiklik yapılırsa veri tutarsızlaşır ve sistem bunu kendiliğinden fark etmez (bunun için trigger gerekir). Aynı tabloda yeni bir proje, ona atanmış bir işçi olmadan girilemez; bir projenin son işçisi silinince proje bilgisi de kaybolur. Bu anomaliler, niteliklerin kontrolsüz bir araya getirilmesinden doğar; çoğu zaman da amaç join maliyetinden kaçmaktır.
- Null değerler
  - Null "uygulanamaz", "var ama bilinmiyor" ya da "yok" anlamlarına gelebilir. Null = Null karşılaştırması doğru değildir; doğru, yanlış ve bilinmeyen değerleriyle üç değerli bir mantık ortaya çıkar. Hoca, makinenin 0-1 felsefesine aykırı olduğunu söyledi. Dış birleştirmeler (outer join) eşleşmeyen satırları null ile doldurur. Çok sayıda null üretecek bir nitelik (ofis bilgisi gibi) ayrı tabloya alınarak problem kolayca çözülür.
- Sahte kayıtlar ve kayıpsız birleştirme
  - Slayttaki örnekte `EMP_PROJ` tablosu, ortak nitelik `Plocation` olacak şekilde iki parçaya ayrıldı. Bir konumda birden çok proje ve işçi bulunduğu için, iki parça natural join ile birleştirilince her işçi o konumdaki başka projelerle de eşleşir; özgün tablodan çok daha fazla, yanlış satır çıkar. Doğru parçalama, birleştirmenin birincil anahtar ile yabancı anahtar üzerinden yapılmasını sağlar.
- Fonksiyonel bağımlılık ve kapanış
  - $X \rightarrow Y$, iki satır $t_1, t_2$ için $t_1[X] = t_2[X]$ ise $t_1[Y] = t_2[Y]$ olması demektir. Birincil anahtar bütün nitelikleri belirler: TC kimlik numarası ad, soyad, adres ve telefonu belirler, ama ad kimlik numarasını belirlemez. Armstrong kurallarıyla verilen FD'lerden yeni FD'ler türetilir. Bir $X$ kümesinin kapanışı $X^+$, $X$'ten başlayıp sol tarafı kümede bulunan FD'lerin sağ taraflarını ekleyerek bulunur. $X^+$ bütün tabloyu kapsıyorsa $X$ süper anahtardır.
  - Anahtar örneği (ekrandan, 01:04:20): Önce tek nitelikler denenir ($A^+$, $B^+$, ...); hiçbiri $R$'yi vermez. Sonra sol tarafta görünenlerden ikili gruplar denenir: $AB \rightarrow C$ ile $ABC$, $A \rightarrow DE$ ile $ABCDE$, $B \rightarrow F$ ile $F$, $F \rightarrow GH$ ile $GH$, $D \rightarrow IJ$ ile $IJ$ eklenir; $AB^+ = R$ olur.
- Minimal küme örneği (ekrandan, 00:58:35)
  - $E = \{B \rightarrow A,\ D \rightarrow A,\ AB \rightarrow D\}$. Sağ taraflar zaten tek niteliktir. $AB \rightarrow D$'de $A$ gereksiz mi? $B \rightarrow A$'yı $B$ ile genişletince $B \rightarrow AB$, geçişlilikle $B \rightarrow D$ çıkar; $AB \rightarrow D$ yerine $B \rightarrow D$ yazılır. Yeni küme $\{B \rightarrow A,\ D \rightarrow A,\ B \rightarrow D\}$'dir. $B \rightarrow D$ ve $D \rightarrow A$'dan geçişlilikle $B \rightarrow A$ türediği için o atılır. Sonuç: $\{B \rightarrow D,\ D \rightarrow A\}$.
- Normal formlar
  - 1NF ilişkisel tablonun tanımının bir parçasıdır: Her hücre tek, atomik değer taşır. Çok değerli bir nitelik (departman konumları) ya anahtara katılıp satırlara açılır ya da ayrı tabloya alınır. Hem çok değerli hem bileşik (nested) bir nitelik, yani hücre içinde bir tablo (işçinin çalıştığı projeler ve saatleri), ayrı tabloya alınır; tek tabloda tutulsaydı `Ename` her proje için tekrar ederdi. Hoca, bugün birçok sistemin (PostgreSQL gibi) dizi tipine izin verdiğini, veritabanının bunu yine de 1NF saydığını ve parçalamayı uygulamaya bıraktığını söyledi.
  - 2NF'de `EMP_PROJ(Ssn, Pnumber, Hours, Ename, Pname, Plocation)` için birincil anahtar `{Ssn, Pnumber}`'dır. `Ename` yalnız `Ssn`'e, `Pname` ve `Plocation` yalnız `Pnumber`'a bağlıdır; bu kısmi bağımlılıklar 2NF'yi bozar. Her belirleyen, belirlediği niteliklerle aynı tabloda toplanarak üç tablo elde edilir.
  - 3NF'de `EMP_DEPT`'te `Ssn → Dnumber → {Dname, Dmgr_ssn}` geçişli bağımlılığı vardır. Departman bilgisi ayrı tabloya alınır, `Dnumber` her iki tabloda kalır ki natural join ile birleştirme yapılabilsin.
  - `LOTS(Property_id#, County_name, Lot#, Area, Price, Tax_rate)` tablosunda `Property_id#` birincil anahtar, `{County_name, Lot#}` aday anahtardır. `County_name → Tax_rate` ve `Area → Price` bağımlılıkları da vardır. Birincil anahtar tek nitelikli olduğu için kısıtlı tanıma göre 2NF'dir; ama `Tax_rate` bir aday anahtarın parçasına bağlı olduğu için genel 2NF değildir. Slayttaki çözüm: `LOTS1(Property_id#, County_name, Lot#, Area, Price)`, `LOTS2(County_name, Tax_rate)`; sonra 3NF için `LOTS1A(Property_id#, County_name, Lot#, Area)` ve `LOTS1B(Area, Price)` (ekrandan, 01:29:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
