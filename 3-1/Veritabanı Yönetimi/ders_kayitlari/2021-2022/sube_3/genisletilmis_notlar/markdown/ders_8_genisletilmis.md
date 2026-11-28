# Ders 8 Genişletilmiş Notu: Normalizasyon: Fonksiyonel Bağımlılıklar, Yitimsiz Parçalama, BCNF ve 3NF

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Normalizasyona Giriş
- 2. İyi Bir İlişkisel Tasarımın Özellikleri
- 3. Parçalama: Yitimli ve Yitimsiz
- 4. Fonksiyonel Bağımlılıklar
- 5. Anahtarlar ve Fonksiyonel Bağımlılıklar
- 6. Yitimsiz Parçalama Testi
- 7. Bağımlılık Koruma
- 8. Boyce-Codd Normal Formu (BCNF)
- 9. Üçüncü Normal Form (3NF)
- 10. Türkçe Sunu: Anomaliler, Armstrong Kuralları, Kanonik Örtü ve Normal Formlar
- Örnek Sorular
- Dersin Toparlaması

Ders Zoom üzerinden yapıldı. Hoca önce ders kitabının (Database System Concepts, 7. baskı, Silberschatz, Korth ve Sudarshan) 7. bölüm PDF'ini açtı. PDF'te bazı slaytların gizli kaldığı fark edilince bir süre PowerPoint sunumuna geçti. PowerPoint'te bazı operatörler görünmeyince PDF'e döndü. Dersin sonunda da kendi Türkçe ders notlarını gösterdi.

## 1. Normalizasyona Giriş

Bu dersin konusu normalizasyondur. Normalizasyon, kavramsal tasarımın ikinci bölümüdür ve bu dersle birlikte kavramsal tasarım tamamlanır. Hoca işin çok teorisine girmeden, literatürdeki terimlerin anlamlarını anlamayı hedeflediğini söyledi.

Temel soru şudur: Bir ilişkisel model tasarımı çok farklı şekillerde yapılabilir. Bu tasarımın "iyi" olması ne demektir? Belki en mükemmeli değil, ama iyi bir tasarım yapmanın anlamı nedir? Ders kitabındaki yaklaşım iyi tasarımı **veri tekrarının en aza indirilmesi** olarak ele alır. Veri tekrarı tasarımda istenmeyen bir durumdur ve tasarımı iyi hale getirmek için normalizasyon adımları uygulanır.

Hoca konunun ana kavramlarını şöyle sıraladı:

- **Normal formlar:** Klasik literatürde 5 normal form vardır, bunlara ek başka formlar da vardır. Endüstride yaygın olarak kullanılan BCNF, ilk üç normal formu kapsar.
- **Fonksiyonel bağımlılık (functional dependency):** Normalizasyon fonksiyonel bağımlılıklar tanımlanarak ve kullanılarak yapılır.
- **Parçalama (decomposition):** Normalizasyon, mevcut tabloların parçalanmasına dayanır. Kompozisyon birleştirmek, dekompozisyon parçalamaktır; tablolar ikiye, üçe bölünür.
- **Yitimli (lossy) ve yitimsiz (lossless) parçalama:** Parçalamanın yitimsiz olması, yani veri kaybına yol açmaması istenir.
- **Bağımlılık koruma (dependency preservation):** Fonksiyonel bağımlılıkların parçalamadan sonra da korunması.

Bu kavramların arkasında bir teori ve algoritmalar vardır; tasarımda tabloların bu algoritmalara göre parçalanması gerekir. Derste bölümün ilk yaklaşık 30 slaytı (iyi tasarım, fonksiyonel bağımlılık, parçalama, normal formlar) işlendi. Algoritmalar ve daha ileri normal formlar kapsam dışı bırakıldı (ekrandan, 00:10:00).

Hoca, dönem başında kullanılan üniversite veritabanını hatırlattı: öğrencilerin aldığı dersler, notları, hocaları, bölümleri gibi gerçek hayatı oldukça iyi yansıtan bir veritabanı. Bu veritabanı için kavramsal tasarım (ER diyagramları) yapılmıştı. Normalizasyon ise bunun üzerine sürülen bir **cila** gibidir: tasarım ortaya çıktıktan sonra iyi hale getirilir, olası arızalar giderilir. Kendi küçük makinemizde yaptığımız mütevazı bir veritabanında normalizasyon yapılmasa çok tehlikeli olmayabilir; ama gerçek bir veritabanında normalizasyon elzem olabilir.

## 2. İyi Bir İlişkisel Tasarımın Özellikleri

### 2.1 instructor ve department'ı birleştirmek: in_dep

Özgün tasarımda instructor ve department ayrı varlık kümeleridir ve ilişkisel modele dönüştürülünce ayrı tablolar olurlar. Bu iki tabloyu tek tabloda toplamak neden istenebilir? Eğer instructor ve department üzerinde birleştirme (join) gerektiren çok sayıda sorgu varsa, iki tabloyu fiziksel olarak tek tabloda tutmak performans açısından cazip görünür.

Slaytta bu birleşik tablo, in_dep, şöyle verilir (ekrandan, 00:25:00):

| ID | name | salary | dept_name | building | budget |
|---|---|---|---|---|---|
| 22222 | Einstein | 95000 | Physics | Watson | 70000 |
| 12121 | Wu | 90000 | Finance | Painter | 120000 |
| 32343 | El Said | 60000 | History | Painter | 50000 |
| 45565 | Katz | 75000 | Comp. Sci. | Taylor | 100000 |
| 98345 | Kim | 80000 | Elec. Eng. | Taylor | 85000 |
| 76766 | Crick | 72000 | Biology | Watson | 90000 |
| 10101 | Srinivasan | 65000 | Comp. Sci. | Taylor | 100000 |
| 58583 | Califieri | 62000 | History | Painter | 50000 |
| 83821 | Brandt | 92000 | Comp. Sci. | Taylor | 100000 |
| 15151 | Mozart | 40000 | Music | Packard | 80000 |
| 33456 | Gold | 87000 | Physics | Watson | 70000 |
| 76543 | Singh | 80000 | Finance | Painter | 120000 |

Slayttaki iki madde: "There is repetition of information" ve "Need to use null values (if we add a new department with no instructors)".

### 2.2 Veri tekrarının zararları

Hoca zararları en masum olandan en kötüsüne doğru adım adım sıraladı:

1. **Yer kaybı.** Comp. Sci. bölümünde Katz, Srinivasan ve Brandt vardır. Bu hocalar tabloda yer aldıkça bölümün bilgileri (Taylor, 100000) her satırda tekrar eder. Bu yer kaybı görece masum bir zarardır ve göz ardı edilebilir.
2. **Güncellemede tutarlılığı korumanın zorlaşması.** Comp. Sci. bölümünün bütçesi 200000 yapılmak istenirse bölümdeki her hocanın satırı değiştirilmelidir. Güncelleme, bölümdeki hoca sayısı kadar satırı etkiler ve bu satırların hepsinin birlikte değişmesi sağlanmalıdır. Tutarlılık korunabilir, ama bu çok daha zordur.
3. **Ekleme sorunu ve null zorunluluğu.** Yeni bir bölüm açıldığında bölümün binası ve bütçesi ancak o bölümde bir hoca varsa eklenebilir. Hoca yoksa instructor alanlarına null girmek gerekir; tablonun anahtarı ID olduğu için ID'ye null girilmesine de izin verilmez. Özgün tasarımda ise yeni bir bölüm, hocası olmasa da department tablosuna kolayca eklenirdi. Hoca null'ın belirsiz bir durum olduğunu ve çoğu zaman görmek istenmediğini vurguladı.
4. **Beklenmedik bilgi kaybı.** Comp. Sci. bölümünde tek bir hoca kalmışsa ve bu hoca ayrılırsa, satırı silinince bölümün bilgileri de silinir. Oysa niyet yalnız hocayı silmekti; bölüme yeni hocalar gelebilir. Aynı şekilde bir bölümü silmek, arka planda hocaların bilgilerini de siler; belki o hoca başka bir bölüme gidecekti.

Sonuç olarak tek kazanç tabloları birleştirmeden aynı fiziksel tabloda tutmaktı; bunun bedeli veri bütünlüğü sorunlarıdır.

### 2.3 Her birleştirme tekrara yol açmaz

Slayt "A Combined Schema Without Repetition" (ekrandan, 00:30:00):

- sec_class(sec_id, building, room_number) ve
- section(course_id, sec_id, semester, year)

tek bir ilişkide birleştirilir:

- section(course_id, sec_id, semester, year, building, room_number)

Bu durumda tekrar yoktur. Her section için ders kodu, section numarası, açıldığı dönem ve yıl, verildiği bina ve oda numarası tutulur. Fark şuradadır: in_dep'te dept_name'e has nitelikler (building, budget) vardı ve bu nitelikler yalnız dept_name'e bağlıydı. İleride bu "building ve budget, dept_name'e fonksiyonel bağımlıdır" diye ifade edilecek. section örneğinde ise niteliklerin kendi aralarında böyle bir bağımlılığı yoktur; hepsi section'a bağlıdır. Bu yüzden veri tekrarı tehlikesi yoktur.

## 3. Parçalama: Yitimli ve Yitimsiz

### 3.1 Neden parçalama ve her parçalama neden iyi değil?

in_dep şemasındaki tekrar sorunundan kurtulmanın tek yolu, onu instructor ve department şemalarına parçalamaktır. Bu örnekte mantıksal olarak hangi niteliğin nereye gideceği açıktır. Ama daha karmaşık şemalarda en iyi parçalamanın ne olduğunu kurallarla, biçimsel olarak tanımlamak gerekir. Çünkü her parçalama iyi değildir.

Parçalama şema üzerinde yapılır: şemayı bıçakla keser gibi iki parçaya ayırırız, her parçanın satır sayısı özgün tablonunkiyle aynıdır. Parçaların yeniden birleştirilebilmesi için ortak bir nitelik iki parçada da bulunmalıdır; böylece parçalar yabancı anahtar üzerinden birleştirilebilir.

### 3.2 Yitimli parçalama örneği

Slayt "A Lossy Decomposition" (ekrandan, 00:35:00). employee(ID, name, street, city, salary) şeması ortak nitelik name olmak üzere (ID, name) ve (name, street, city, salary) olarak bölünür.

Özgün employee tablosunun ilgili satırları:

| ID | name | street | city | salary |
|---|---|---|---|---|
| 57766 | Kim | Main | Perryridge | 75000 |
| 98776 | Kim | North | Hampton | 67000 |

Parçalar:

| ID | name |
|---|---|
| 57766 | Kim |
| 98776 | Kim |

| name | street | city | salary |
|---|---|---|---|
| Kim | Main | Perryridge | 75000 |
| Kim | North | Hampton | 67000 |

Parçaları name üzerinden doğal birleşimle (natural join) birleştirince:

| ID | name | street | city | salary |
|---|---|---|---|---|
| 57766 | Kim | Main | Perryridge | 75000 |
| 57766 | Kim | North | Hampton | 67000 |
| 98776 | Kim | Main | Perryridge | 75000 |
| 98776 | Kim | North | Hampton | 67000 |

(python ile doğrulandı: birleşim 4 satır verir.)

Her iki Kim de iki adresle eşleşti: 57766 numaralı Kim hem Perryridge'de hem Hampton'da görünüyor, oysa yalnız Perryridge'de oturuyor. Sorunun kaynağı aynı adlı iki kişinin olmasıdır. Bütün adlar farklı olsaydı satırlar yalnız kendileriyle birleşirdi; ama bir şirkette aynı adlı birçok kişi olabileceği için bu garanti edilemez.

Hocanın vurguladığı ilginç nokta: Birleşim sonucunda özgün tablodan **daha çok** satır elde edildi, sanki daha çok bilgi var gibi görünüyor. Ama aslında bilgi kaybedildi: özgün tablo artık yok ve Kim adlı çalışanların hangisinin nerede oturduğu bilinemiyor.

### 3.3 Yitimsiz parçalamanın biçimsel tanımı

Slayt "Lossless Decomposition" (ekrandan, 00:40:00). $R$ bir ilişki şeması, $R_1$ ve $R_2$ de onun bir parçalaması olsun, yani $R = R_1 \cup R_2$. Büyük harf ($R$) şemayı, küçük harf ($r$) o şemaya ait tabloyu gösterir.

$R$'yi $R_1$ ve $R_2$ şemalarıyla değiştirmek bilgi kaybına yol açmıyorsa parçalama **yitimsizdir**. Biçimsel olarak:

$$\Pi_{R_1}(r) \bowtie \Pi_{R_2}(r) = r$$

Tersine, parçalama şu durumda **yitimlidir**:

$$r \subset \Pi_{R_1}(r) \bowtie \Pi_{R_2}(r)$$

Yani doğal birleşim özgün tablodan daha çok satır üretiyorsa bir kayıp vardır. (PowerPoint'te izdüşüm operatörleri görünmüyordu, hoca bu nedenle PDF'e geçti; formül kitaptaki gösterimle yazıldı.)

### 3.4 Yitimsiz parçalama örneği

$R = (A, B, C)$ şeması $R_1 = (A, B)$ ve $R_2 = (B, C)$ olarak parçalansın. Tablonun durumu $\{(\alpha, 1, A), (\beta, 2, B)\}$ ise parçalar $\{(\alpha,1),(\beta,2)\}$ ve $\{(1,A),(2,B)\}$ olur. Bunlar B üzerinden doğal birleşimle birleştirilince, B'de tekrar olmadığı için, özgün tablo aynen elde edilir: $(\alpha,1,A)$ ve $(\beta,2,B)$ (python ile doğrulandı). Hoca bunu karpuzu ortadan ikiye bölüp yeniden birleştirmeye benzetti. Kim örneğindeki sorun, ortak niteliğin (name) anahtar olmamasıydı. Bu örnekte bu belirli durum (instance) için yitim olmadı. <!-- BELİRSİZ: Bu slaytın karesi yoktu; tablo değerleri altyazıdan (00:42:19-00:44:14) alındı. -->

### 3.5 Normalizasyonun hedefi

Normalizasyonda istenen, şemadaki her $R$ tablosunun **iyi formda** (good form) olmasıdır; iyi form, veri tekrarının olmamasıdır. Tablo tekrar içeriyorsa $R_1, R_2, \ldots, R_n$ gibi ilişkilere parçalanır. Parçalardan birinde tekrar kalırsa o da parçalanır. Bunun için hem her ilişkinin iyi formda olması hem de parçalamanın yitimsiz olması gerekir.

Bu iş bağımlılık tanımlarıyla yapılır: fonksiyonel bağımlılık ve çok değerli (multivalued) bağımlılık. Bu ders kapsamında yalnız fonksiyonel bağımlılıklar işlenir; bunlar ilk üç normal form ve BCNF için yeterlidir. 4NF ve 5NF için çok değerli bağımlılıklar gerekir ve bunlar işlenmeyecek.

## 4. Fonksiyonel Bağımlılıklar

### 4.1 Anahtardan fonksiyonel bağımlılığa

Anahtar (süper anahtar ya da genel anlamda anahtar), tablodaki bir nitelik grubudur: tek bir nitelik ya da birden çok nitelikten oluşan bileşik bir grup. Bu grup tablodaki bir satırı belirler. Biçimsel ilişkisel modelde aynı satır tekrar etmediği için anahtar değeri de tabloda bir kez görünür.

Fonksiyonel bağımlılık buna ek bir tanımdır: Tablo içinde bazı nitelikler başka nitelikleri belirleyebilir. A niteliği B'yi belirliyorsa "B, A'ya fonksiyonel bağımlıdır" denir. Bu, A'nın aynı değerleri için hep aynı B değerlerinin karşımıza çıkması demektir. Anahtarda aynı değer tekrar etmez, fonksiyonel bağımlılıkta ise sol tarafın değeri tekrar edebilir; tekrar ettiğinde sağ taraf da aynı olmalıdır.

### 4.2 Bağımlılıklar küçük dünyadan gelir

Slayt "Functional Dependencies" (ekrandan, 00:50:00). Gerçek dünyada veri üzerinde birçok kısıt vardır. Üniversite veritabanında beklenen kısıtlardan bazıları:

- Öğrenciler ve hocalar ID'leriyle tek olarak tanımlanır.
- Her öğrencinin ve hocanın tek bir adı vardır.
- Her hoca ve öğrenci (öncelikle) tek bir bölümle ilişkilidir.
- Her bölümün tek bir bütçe değeri ve tek bir binası vardır.

Birinci madde bir fonksiyonel bağımlılıktır ama aslında anahtar üzerinden bir bağımlılıktır; anahtar da bir tür fonksiyonel bağımlılıktır, çünkü anahtar olan ID bütün satırı belirler. Üçüncü madde, hocanın ID'sinin bölümü belirlediğini söyler: aynı hoca tabloda tekrar görünürse bölümü de aynı olmalıdır. Dördüncü madde, aynı bölüm karşımıza çıktığında aynı bütçe ve aynı binanın çıkacağını söyler.

in_dep tablosunda dept_name, building'i ve budget'ı belirler; başka bir deyişle building ve budget, dept_name'e fonksiyonel bağımlıdır. Ama dept_name, building'e bağımlı değildir: Watson binasında hem fizik hem biyoloji bölümü vardır. Fizik bölümünün yeri bellidir; tabloda fizik bir daha görünürse yanında yine Watson görünmelidir. Ama Watson görününce bölümün ne olduğu belli değildir. Hocanın vurguladığı gibi bu bağımlılıklar tablonun içeriğinden değil, küçük dünyada gerçek olan şeylerden, bizim o dünyayı tasavvurumuzdan gelir.

### 4.3 Legal instance

Gerçek dünyadaki bütün bu kısıtları sağlayan bir ilişki durumuna **legal instance** denir. Örneğin in_dep'e fizik bölümü için Watson'dan farklı bir bina yazan bir satır eklenirse bu durum legal olmaz, geçerli bir veritabanı durumu sayılmaz. Bir veritabanındaki bütün ilişki durumları legal ise veritabanı durumu da legal'dir.

Legal ilişkiler kümesi üzerindeki kısıtlar, bir nitelik grubunun değerinin başka bir nitelik grubunun değerini tek olarak belirlemesini gerektirir. Fonksiyonel bağımlılık anahtar kavramının genelleştirilmesidir: anahtar, bütün satırı tek olarak belirlemek zorundadır; bu tanım gevşetilerek tablodaki herhangi iki nitelik grubu arasındaki belirleme ilişkisine genişletilir.

### 4.4 Biçimsel tanım

Slayt "Functional Dependencies Definition" (ekrandan, 01:00:00). $R$ bir ilişki şeması, $\alpha \subseteq R$ ve $\beta \subseteq R$ olsun. $\alpha \to \beta$ fonksiyonel bağımlılığı, ancak ve ancak her legal $r(R)$ için, $r$'nin $\alpha$ niteliklerinde uyuşan herhangi iki satırı $t_1$ ve $t_2$, $\beta$ niteliklerinde de uyuşuyorsa $R$ üzerinde geçerlidir (holds on $R$):

$$t_1[\alpha] = t_2[\alpha] \Rightarrow t_1[\beta] = t_2[\beta]$$

Örnek: $r(A, B)$ şu duruma sahip olsun:

| A | B |
|---|---|
| 1 | 4 |
| 1 | 5 |
| 3 | 7 |

- $A \to B$ sağlanmaz: A = 1 olan iki satırda B değerleri farklıdır (4 ve 5). Bu iki satırdan A'nın B'yi belirlemediği çıkarılır.
- $B \to A$ sağlanır: Onu bozacak bir durum yoktur; 4 için 1, 5 için 1, 7 için 3. Bu durum (snapshot) için $B \to A$ geçerlidir.

Hoca, tabloda 4'ün yanında 2 olan bir satır daha olsaydı $B \to A$'nın da sağlanmayacağını, yani ne A'nın B'yi ne B'nin A'yı belirleyeceğini ekledi.

### 4.5 Kapanış ($F^+$)

Küçük dünyadan alınan fonksiyonel bağımlılıklar kümesi $F$ olsun. $F$'den mantıksal olarak çıkarılabilen başka fonksiyonel bağımlılıklar da vardır. Örneğin $A \to B$ ve $B \to C$ ise $A \to C$ çıkarılabilir: bir tabloda A'nın B'yi, B'nin de C'yi belirlediğini düşünün; o zaman A, C'yi belirler. $F$'den çıkarılabilen bütün fonksiyonel bağımlılıkların kümesine $F$'nin **kapanışı** (closure) denir ve $F^+$ ile gösterilir. Bu çıkarımlar için Armstrong kuralları kullanılır (bkz. Bölüm 10).

## 5. Anahtarlar ve Fonksiyonel Bağımlılıklar

### 5.1 Süper anahtar ve aday anahtar

Slayt "Keys and Functional Dependencies" (ekrandan, 01:05:00):

- $K$, $R$ için **süper anahtardır** ancak ve ancak $K \to R$.
- $K$, $R$ için **aday anahtardır** ancak ve ancak $K \to R$ ve hiçbir $\alpha \subset K$ için $\alpha \to R$ değilse.

Yani aday anahtar minimal süper anahtardır: süper anahtardan herhangi bir nitelik çıkarıldığında geri kalanlar anahtar olma özelliğini kaybediyorsa $K$ minimaldir, daha fazla küçültülemez.

### 5.2 Süper anahtarla ifade edilemeyen kısıtlar

Fonksiyonel bağımlılıklar, süper anahtarlarla ifade edilemeyen kısıtları ifade etmeyi sağlar. in_dep(ID, name, salary, dept_name, building, budget) şemasında şu bağımlılıkların geçerli olması beklenir:

- $dept\_name \to building$
- $ID \to building$

ama şunun geçerli olması beklenmez:

- $dept\_name \to salary$

dept_name anahtar değildir; building'in dept_name tarafından belirlendiği anahtar tanımıyla değil, ancak fonksiyonel bağımlılıkla ifade edilebilir. Aynı şekilde budget da dept_name tarafından belirlenir. building ile budget arasında ise hiçbir bağımlılık yoktur, çünkü bütçe tamamen bölümle ilgilidir. Hocanın ifadesiyle nitelikler arasında bir alaka olabilir ama bağımlılık olmayabilir. ID → building geçerlidir, çünkü hoca bir bölüme, bölüm de bir binaya aittir (odası orada olduğu için ID binayı belirler).

### 5.3 Fonksiyonel bağımlılıkların kullanım amaçları

- Bir ilişkinin verilen fonksiyonel bağımlılıklar kümesi altında legal olup olmadığını test etmek: küçük dünyadan alınan kriterleri $r$ tablosu sağlıyor mu?
- Legal ilişkiler kümesi üzerindeki kısıtları belirtmek.

$R$ üzerindeki bütün legal ilişkiler $F$'yi sağlıyorsa "$F$, $R$ üzerinde geçerlidir" (F holds on R) denir.

Bir ilişki şemasının belirli bir durumu, bütün legal durumlarda geçerli olmayan bir fonksiyonel bağımlılığı sağlayabilir. Örneğin instructor tablosunun belirli bir durumunda hiç ad tekrar etmiyorsa name → ID geçerli gibi görünür. Ama bu gerçekçi değildir, çünkü aynı adlı hocaların olması beklenir; yalnız şu anda ortaya çıkmamıştır. Bu yüzden $F$ kümesini yalnız tablo durumlarına bakarak tanımlamak isabetli olmaz; kavramsal ve mantıksal olarak düşünülmelidir.

### 5.4 Trivial bağımlılıklar

Slayt "Trivial Functional Dependencies" (ekrandan, 01:10:00). Bir ilişkinin bütün durumlarında sağlanan fonksiyonel bağımlılığa **trivial** (önemsiz) denir. Örnekler:

- $ID, name \to ID$
- $name \to name$

ID ve name birlikte ID'yi elbette belirler; ad tekrar etse de etmese de, ID tekrar ettiğinde aynı ID görünür. Genel olarak $\beta \subseteq \alpha$ ise $\alpha \to \beta$ trivialdir. Bütün nitelik kombinasyonları arasındaki bağımlılıklar düşünüldüğünde bunların bir kısmı trivial olur ve bahsetmeye değmez.

## 6. Yitimsiz Parçalama Testi

Fonksiyonel bağımlılıklar kullanılarak bir parçalamanın yitimsiz olup olmadığı test edilebilir. $R_1$ ve $R_2$, $R$'nin bir parçalaması olsun. Aşağıdaki bağımlılıklardan en az biri $F^+$ içindeyse parçalama yitimsizdir:

- $R_1 \cap R_2 \to R_1$
- $R_1 \cap R_2 \to R_2$

Yani iki şemanın kesişimi parçalardan birini fonksiyonel olarak belirliyorsa, başka bir deyişle o parçanın anahtarıysa, parçalar birleştirildiğinde bilgi kaybı olmaz (lossless join decomposition). Hoca bu koşulun yalnız fonksiyonel bağımlılıklar için olduğunu, çok değerli bağımlılıkların 4NF/5NF konusu olduğu için şimdilik göz ardı edilebileceğini belirtti.

Slayt "Example" (ekrandan, 01:15:00):

- $R = (A, B, C)$, $F = \{A \to B, B \to C\}$
- $R_1 = (A, B)$, $R_2 = (B, C)$: yitimsiz parçalama, çünkü $R_1 \cap R_2 = \{B\}$ ve $B \to BC$.
- $R_1 = (A, B)$, $R_2 = (A, C)$: yitimsiz parçalama, çünkü $R_1 \cap R_2 = \{A\}$ ve $A \to AB$.
- Not: $B \to BC$, $B \to \{B, C\}$'nin kısa yazılışıdır.

Birinci parçalamada kesişim B'dir. B, B'yi (trivial olarak) ve C'yi belirlediği için BC'yi, yani $R_2$'yi belirler. Bu yüzden tabloya hangi veri yazılırsa yazılsın yitim olmaz: B, C'yi belirlediği için Kim örneğindeki gibi aynı B değerinin farklı C değerleriyle görünmesi mümkün değildir. İkinci parçalamada kesişim A'dır; A, AB'yi yani $R_1$'i belirler ve A anahtardır, dolayısıyla bu da yitimsizdir. Hoca, öğrencilerin herhangi bir durum seçip iki tabloyu birleştirerek yitim olmadığını denemelerini önerdi.

## 7. Bağımlılık Koruma

### 7.1 Tanım ve gerekçe

Bazen parçalama nedeniyle bağımlılıklar tek bir tabloda korunamaz. Fonksiyonel bağımlılıkların tek bir tabloda kalması denetimlerini çok kolaylaştırır; farklı tablolara dağıldıklarında denetim sistem için daha büyük bir yük olur.

Hoca bütün bu kavramların (anahtar, fonksiyonel bağımlılık) aslında veri bütünlüğü kısıtları olduğunu vurguladı: bir check kısıtı, bir assertion, bir trigger ya da bir yabancı anahtar kısıtı gibi. Kavram olarak farklı bir şey söylenmiyor; ek olarak aday anahtar ve fonksiyonel bağımlılık tanımlandı. Normalizasyon fonksiyonel bağımlılığa dayanarak yapılır, bu da verinin parçalanmasını gerektirir ve parçalamada iki mesele çıkar: yitimsizlik ve bağımlılık koruma.

Slayt "Dependency Preservation" maddeleri (ekrandan, 01:20:00; slaydın ortası Zoom penceresiyle kapalıydı, maddeler hocanın okumasından tamamlandı):

- Veritabanı her güncellendiğinde fonksiyonel bağımlılık kısıtlarını test etmek maliyetli olabilir.
- Veritabanını kısıtların verimli test edilebileceği şekilde tasarlamak yararlıdır.
- Bir fonksiyonel bağımlılık yalnız bir ilişki dikkate alınarak test edilebiliyorsa bu kısıtın test maliyeti düşüktür.
- Bir ilişki parçalandığında, testi kartezyen çarpım yapmadan gerçekleştirmek artık mümkün olmayabilir.
- Fonksiyonel bağımlılığın uygulanmasını hesaplama açısından zorlaştıran bir parçalamaya **dependency preserving değil** denir.

Yani tablo ikiye ayrıldığında bütün fonksiyonel bağımlılık kısıtları kendi tablolarında kalıyorsa, testler arka planda doğal birleşim ya da kartezyen çarpım yapmadan yapılabilir; ideal durum budur.

### 7.2 dept_advisor örneği

Slayt "Dependency Preservation Example" (ekrandan, 01:45:00). Kitapta Şekil 7.6'da anlatılan küçük dünyaya dayanan şema:

- $dept\_advisor(s\_ID, i\_ID, department\_name)$
- Fonksiyonel bağımlılıklar: $i\_ID \to dept\_name$ ve $s\_ID, dept\_name \to i\_ID$

Bu tablo danışmanlık ilişkisini izler. Bir hoca tek bir bölüme aittir. Bir öğrencinin bir bölümde tek bir danışmanı vardır; ama farklı bölümlerden birden çok danışmanı olabilir. Hoca bunu çift anadal (double major) ile açıkladı: aynı anda iki bölümü bitirmeye çalışan öğrencinin her bölümde bir danışmanı olabilir. Dönem başındaki üniversite şemasında bir öğrencinin bir danışmanı vardı ve bir danışman birçok öğrenciyle ilgilenebiliyordu (bire-çok); bu, çift anadal senaryosunu ifade edemiyordu.

Slayttaki diğer maddeler:

- Bu tasarımda bir hoca her dept_advisor ilişkisine katıldığında bölüm adı bir kez daha tekrar etmek zorundadır.
- Bunu düzeltmek için dept_advisor parçalanmalıdır.
- Herhangi bir parçalama, $s\_ID, dept\_name \to i\_ID$ bağımlılığının bütün niteliklerini tek tabloda içermez.
- Dolayısıyla parçalama bağımlılığı korumaz.

Bu bağımlılık şemanın üç niteliğinin hepsini içerir; hangi parçalama yapılırsa yapılsın bu üç nitelik tek bir tabloda kalamaz. Bağımlılık tek tabloda korunamadığı için bu tür parçalamaya "dependency preserving değil" denir. Hoca, BCNF tanımından sonra bu şemanın BCNF olmadığının ve parçalanınca bağımlılığın korunamadığının gösterileceğini söyledi.

## 8. Boyce-Codd Normal Formu (BCNF)

### 8.1 Normal formların sıralaması

Derste tanımlanan normal formlar BCNF ve 3NF'dir; en yaygın kullanılanlar bunlardır. 1NF ve 2NF'den de kısaca bahsedildi. Bu formlar birbirini kapsar: BCNF olan bir form aynı zamanda 3NF'dir, 3NF olan aynı zamanda 2NF'dir. En katı, kısıtı en ağır olan BCNF'dir. Veri bütünlüğü açısından BCNF en ideal ve en kapsamlı formdur; ama bazı parçalamalarda bağımlılık korunamaz ve fonksiyonel bağımlılık birçok tabloya dağıldığı için denetiminde performans sorunu çıkar.

### 8.2 Tanım

$R$ ilişki şeması, $F$ fonksiyonel bağımlılık kümesine göre BCNF'dir, eğer $F^+$'daki $\alpha \to \beta$ biçimindeki ($\alpha \subseteq R$, $\beta \subseteq R$) bütün bağımlılıklar için şunlardan en az biri sağlanıyorsa:

- $\alpha \to \beta$ trivialdir ($\beta \subseteq \alpha$), ya da
- $\alpha$, $R$ için süper anahtardır.

Kısaca: trivial olmayan bütün fonksiyonel bağımlılıklarda sol taraf süper anahtar ise şema BCNF'dir. <!-- BELİRSİZ: BCNF tanım slaydının karesi yoktu; tanım hocanın okumasından (01:52:43-01:53:45) yazıldı. -->

in_dep şeması BCNF midir? Bağımlılık $dept\_name \to building, budget$ geçerlidir, ama dept_name süper anahtar değildir. Bu yüzden in_dep BCNF değildir ve parçalanması gerekir.

### 8.3 BCNF'ye parçalama

Slayt "Decomposing a Schema into BCNF" (ekrandan, 01:55:00). $R$, BCNF olmayan bir şema ve $\alpha \to \beta$ BCNF'yi bozan fonksiyonel bağımlılık olsun. $R$ şu iki şemaya parçalanır:

- $(\alpha \cup \beta)$
- $(R - (\beta - \alpha))$

BCNF'yi bozan bağımlılığın iki tarafı aynı şemada toplanır. Diğer şema, $R$'den $\beta - \alpha$ çıkarılarak elde edilir; ortak kalan $\alpha$ iki tablo arasındaki yabancı anahtar olur.

in_dep örneğinde:

- $\alpha = dept\_name$
- $\beta = building, budget$
- $(\alpha \cup \beta) = (dept\_name, building, budget)$
- $\beta - \alpha = (building, budget)$, dolayısıyla $(R - (\beta - \alpha)) = (ID, name, dept\_name, salary)$

Bu iki parçada BCNF'yi bozan bir şey kalmaz: birinci tabloda dept_name, building ve budget'ı belirler ve anahtardır; ikinci tabloda da bütün bağımlılıkların sol tarafı anahtardır. Hoca, parçalama algoritmasının ayrıntısına ve kuralın "sebebinin sebebine" girmeyeceğini, bu kısmın zor olduğunu söyledi.

### 8.4 Örnek: $R=(A,B,C)$, $F=\{A \to B, B \to C\}$

Hoca BCNF denetimini ve parçalamayı bu örnekle adım adım gösterdi (ekrandan, 02:00:00):

1. **$A \to B$:** A süper anahtar mı? $A \to B$ ve $B \to C$ olduğundan A, ABC'yi yani bütün tabloyu belirler (python ile kapanış doğrulandı). A süper anahtardır, bu bağımlılık BCNF'yi bozmaz.
2. **$B \to C$:** B, C'yi belirler ama A'yı belirlemez; B süper anahtar değildir. Bu bağımlılık BCNF'yi bozar, şema BCNF değildir.
3. **Parçalama:** $\alpha = B$, $\beta = C$. $(\alpha \cup \beta) = (B, C)$. $\beta - \alpha = C$; $R - C = (A, B)$. Parçalama: $R_1 = (A, B)$, $R_2 = (B, C)$.
4. **Yitimsiz mi?** Kesişim B ve $B \to BC$, yani B, $R_2$'yi belirler. Yitimsizdir.
5. **Bağımlılık korunuyor mu?** $A \to B$, $R_1$'de; $B \to C$, $R_2$'de denetlenebilir. Her bağımlılık tek bir tabloda kaldığı için bağımlılık korunur.

Slayttaki özet:

- $R_1 = (A, B)$, $R_2 = (B, C)$: lossless-join ($R_1 \cap R_2 = \{B\}$ ve $B \to BC$), dependency preserving.
- $R_1 = (A, B)$, $R_2 = (A, C)$: lossless-join ($R_1 \cap R_2 = \{A\}$ ve $A \to AB$), ama dependency preserving değil: $B \to C$, $R_1 \bowtie R_2$ hesaplanmadan denetlenemez.

İkinci parçalamada $A \to B$ birinci tabloda yakalanır, ama B bir tabloda, C ötekinde olduğu için $B \to C$ tek tabloda yakalanamaz. Hoca, BCNF kuralının ürettiği parçalamanın bu olmadığını, ama böyle parçalansaydı sorun çıkacağını belirtti.

### 8.5 BCNF ve bağımlılık koruma

BCNF'nin sorunu çok katı olmasıdır: BCNF parçalaması her zaman yitimsizdir, ama bazı BCNF parçalamaları bağımlılığı koruyamaz.

Slayt "BCNF and Dependency Preservation" (ekrandan, 02:05:00): Hem BCNF'yi hem bağımlılık korumayı sağlamak her zaman mümkün değildir. dept_advisor(s_ID, i_ID, department_name), bağımlılıklar $i\_ID \to dept\_name$ ve $s\_ID, dept\_name \to i\_ID$:

- **$i\_ID \to dept\_name$:** i_ID süper anahtar mı? Hayır; bir hoca yalnız bir öğrencinin değil, başka öğrencilerin de danışmanıdır, i_ID tabloda tekrar eder. Bu bağımlılık BCNF'yi bozar. Slayttaki ifade: "dept_advisor is not in BCNF, i_ID is not a superkey".
- **$s\_ID, dept\_name \to i\_ID$:** Bir öğrencinin bir bölümde tek danışmanı olduğu için (s_ID, dept_name) bir kez görünür ve anahtardır. Bu bağımlılık BCNF'yi bozmaz.

Sonuç olarak tablo bu bağımlılıklar altında BCNF değildir; arkada gizli bir veri tekrarı vardır ve dersin başındaki tutarlılık, yer kaybı ve bilgi kaybı sorunları burada da örneklenebilir.

BCNF'ye parçalama: Bozan bağımlılık $i\_ID \to dept\_name$'dir. $(\alpha \cup \beta) = (i\_ID, dept\_name)$; $R$'den dept_name çıkarılınca $(s\_ID, i\_ID)$ kalır. Bu iki şemada belirleyenler anahtar olduğu için BCNF bozulmaz. Ama $s\_ID, dept\_name \to i\_ID$ bütün nitelikleri içerdiğinden parçalamadan sonra i_ID bir tarafta, dept_name diğer tarafta kalır ve bağımlılık tek tabloda toplanamaz; bağımlılık korunmaz.

## 9. Üçüncü Normal Form (3NF)

### 9.1 Tanım

BCNF bu açıdan ağırdır. Alternatif olarak onun gevşek bir hali olan üçüncü normal form kullanılır.

Slayt "Third Normal Form" (ekrandan, 02:10:00). $R$ ilişki şeması, $F^+$'daki bütün $\alpha \to \beta$ için aşağıdakilerden en az biri sağlanıyorsa üçüncü normal formdadır (3NF):

- $\alpha \to \beta$ trivialdir ($\beta \subseteq \alpha$).
- $\alpha$, $R$ için süper anahtardır.
- $\beta - \alpha$ içindeki her $A$ niteliği $R$'nin bir aday anahtarının içindedir. (Not: her nitelik farklı bir aday anahtarda olabilir.)

İlk iki madde BCNF ile aynıdır; bunlar sağlanıyorsa şema zaten BCNF'dir. Üçüncü madde gevşekliktir: ilk ikisi sağlanmasa bile $\beta - \alpha$'daki her nitelik bir aday anahtarın (minimal süper anahtarın) içinde geçiyorsa şema 3NF'dir.

Hoca bu koşulun sebebini anlamanın kolay olmadığını, arkada üstü örtülü bir mantık bulunduğunu söyledi ve şöyle bir yorum verdi: Hiçbir anahtara dahil olmayan niteliklere **asal olmayan** nitelikler denir. 3NF koşulu, asal olmayan nitelikler arasında **geçişli bağımlılık** olmamasına karşılık gelir.

Slayttaki diğer maddeler:

- Bir ilişki BCNF ise 3NF'dir (çünkü BCNF'de ilk iki koşuldan biri zaten sağlanır).
- Üçüncü koşul, bağımlılık korumayı sağlamak için BCNF'nin en küçük gevşetilmesidir.

### 9.2 3NF örneği: dept_advisor

Slayt "3NF Example" (ekrandan, 02:15:00). Aynı şema ve bağımlılıklar: dept_advisor(s_ID, i_ID, dept_name), $i\_ID \to dept\_name$, $s\_ID, dept\_name \to i\_ID$.

**Aday anahtarların bulunması.** Küçük bir tabloda kombinasyonlar az olduğu için önce tekli, sonra ikili, gerekirse üçlü nitelik grupları denenir:

- Tekliler: Ne s_ID (çift anadal yapan öğrencinin başka bölümde danışmanı olabilir) ne i_ID ne dept_name tek başına anahtardır.
- $\{s\_ID, dept\_name\}$: Öğrencinin bir bölümde tek danışmanı olduğu için satırları tek olarak belirler. Minimal mi? s_ID çıkarılınca bölümde birçok öğrenci olduğu için dept_name tekrar eder; dept_name çıkarılınca s_ID tekrar eder. Minimaldir, aday anahtardır.
- $\{s\_ID, i\_ID\}$: Bir öğrencinin bir danışmanı bir kez görünür. Başka bölümde de aynı hoca danışman olamaz, çünkü hoca tek bir bölüme aittir; çift anadal yapan öğrencinin diğer bölümdeki danışmanı farklı bir hocadır. Bu ikili tekrar etmez, aday anahtardır.
- $\{i\_ID, dept\_name\}$: Süper anahtar bile değildir, çünkü bir hoca aynı bölümde birçok öğrenciye danışmanlık yapar ve bu ikili tekrar eder.

Aday anahtarlar: $\{s\_ID, dept\_name\}$ ve $\{s\_ID, i\_ID\}$ (python ile doğrulandı).

**3NF denetimi.** Şema BCNF değildir, çünkü $i\_ID \to dept\_name$'de i_ID süper anahtar değildir. 3NF için her bağımlılığa bakılır:

- $s\_ID, dept\_name \to i\_ID$: sol taraf süper anahtardır, sorun yok.
- $i\_ID \to dept\_name$: i_ID süper anahtar değildir, ama $\beta - \alpha = \{dept\_name\} - \{i\_ID\} = \{dept\_name\}$ ve dept_name bir aday anahtarın ($\{s\_ID, dept\_name\}$) içindedir.

Dolayısıyla dept_advisor 3NF'dir.

### 9.3 3NF ile BCNF'nin karşılaştırılması

3NF'nin gevşekliğinin bedeli **veri tekrarıdır** (redundancy); BCNF katı olduğu için orada bu sorun yoktur. Hoca, yalnız fonksiyonel bağımlılıkların söz konusu olduğunu, çok değerli bağımlılıklar varsa BCNF'nin de yetmeyeceğini ve 4NF, 5NF gibi başka normalizasyonların gerektiğini, bunların konu dışı olduğunu hatırlattı.

3NF'nin BCNF'ye göre avantajı: Yitimsizlikten ve bağımlılık korumadan ödün vermeden her zaman bir 3NF tasarımı elde etmek mümkündür. 3NF'nin dezavantajları:

- Öğeler arasındaki bazı anlamlı ilişkileri göstermek için null değerler kullanmak gerekebilir.
- Kısıtlar gevşediği için bilgi tekrarı sorunu ortaya çıkabilir.

### 9.4 3NF'de tekrar örneği

Slayt "Redundancy in 3NF" (ekrandan, 02:20:00). 3NF olan şu şemayı düşünelim:

- $R = (J, K, L)$
- $F = \{JK \to L, L \to K\}$

Örnek tablo:

| J | L | K |
|---|---|---|
| $j_1$ | $l_1$ | $k_1$ |
| $j_2$ | $l_1$ | $k_1$ |
| $j_3$ | $l_1$ | $k_1$ |
| null | $l_2$ | $k_2$ |

Hoca bu şemanın neden BCNF olmadığını göstermeyi öğrencilere bıraktı (çözüm Örnek Sorular bölümünde). 3NF ile yetinip parçalama yapmazsak bu şema bir derece normalizasyon sağlar, ama tablodaki sorunlar şunlardır:

- Bilgi tekrarı: $(l_1, k_1)$ çifti üç kez tekrar eder.
- Null değer gereği: $J$ için karşılık gelen bir değer olmadan $(l_2, k_2)$ ilişkisini göstermek için null kullanmak gerekir.

Böylece kitap bölümünün ilk 31 slaytı (7.31'e kadar) tamamlandı. Bölümün devamı 4NF ve daha yüksek normal formlara geçer; bunlara girilmedi.

## 10. Türkçe Sunu: Anomaliler, Armstrong Kuralları, Kanonik Örtü ve Normal Formlar

Hoca son bölümde kendi Türkçe ders notlarını açtı ve aynı konuların ana hatlarını hızlıca geçti; öğrencilerin bu sunuyu da çalışmasını önerdi.

### 10.1 Anomaliler

Türkçe sunuda veri tekrarının yol açtığı sorunlara **anomali** denir; kitap bu terimi kullanmıyordu. İyi bir ilişkisel model şeması için kılavuzlar verilir: yer kaybı ya da güncelleme anomalileri varsa şema iyi değildir ve normalize edilmelidir. Ekleme, silme ve güncellemelerde anormallikler oluşur. Örnekler (ekrandan, 02:25:00):

- Silme anomalisi: Bir proje silindiğinde o projede çalışan bütün çalışanlar silinir. Bir çalışan bir projedeki tek çalışansa, çalışanı silmek projeyi de siler.
- EMP_DEPT(Ename, Ssn, Bdate, Address, Dnumber, Dname, Dmgr_ssn) ve EMP_PROJ(Ssn, Pnumber, Hours, Ename, Pname, Plocation) şemaları ve bunların fonksiyonel bağımlılık okları. EMP_PROJ'da FD1: {Ssn, Pnumber} → Hours; FD2: Ssn → Ename; FD3: Pnumber → {Pname, Plocation}.

Çalışan ile bölümü ya da çalışan ile projeyi aynı tabloda birleştirmek normalizasyon ihtiyacını doğurur. Hoca süreci şöyle özetledi: ER diyagramından daha önce görülen dönüşüm kurallarıyla (bire-çok, çoka-çok bağıntıların dönüşümü) ilişkisel model tabloları elde edilir. Bu tabloların her biri için küçük dünyaya has fonksiyonel bağımlılık kümesi tanımlanır, tabloların BCNF olup olmadığı belirlenir ve değilse parçalanır. Normalizasyon, ilişkisel model tablolarını daha emniyetli hale getirmek için yapılan bir cila işlemidir.

### 10.2 İşlevsel bağımlılık ve Armstrong kuralları

Türkçe sunudaki tanım (ekrandan, 02:25:00): $R = \{A_1, A_2, \ldots, A_n\}$, $X \subseteq R$, $Y \subseteq R$ olsun.

$$t_1[X] = t_2[X] \Rightarrow t_1[Y] = t_2[Y]$$

ifadesi $X \to Y$ olması için gerekli koşuldur. $X \to Y$, "X niteliği Y'yi belirler" demektir.

Sunuda trivial, trivial olmayan ve geçişli bağımlılıklar maddeler halinde verilir. Çıkarım kuralları (Armstrong aksiyomları) hocanın sözlü anlatımıyla:

- **Dönüşlülük:** $Y \subseteq X$ ise $X \to Y$.
- **Arttırma:** $X \to Y$ ise $XZ \to Y$. Hoca: X zaten Y'yi belirliyorsa yanına bir nitelik daha koyunca da belirler. <!-- BELİRSİZ: Hoca arttırmayı "XZ, Y'yi belirler" diye okudu; kitaplardaki standart biçim XZ → YZ'dir. Slayt karesi yoktu. -->
- **Geçişlilik:** $X \to Y$ ve $Y \to Z$ ise $X \to Z$.
- **Birleşim:** $X \to Y$ ve $X \to Z$ ise $X \to YZ$.
- **Ayrıştırma:** $X \to YZ$ ise $X \to Y$ ve $X \to Z$.

Hoca bunların sezgisel olarak "tabii ki" denebilecek ifadeler olduğunu, matematiksel olarak zor bir şey bulunmadığını söyledi. Bu kurallarla verilen bir $F$ kümesinin kapanışı $F^+$ bulunabilir; sunudaki kapanış algoritması konunun zor algoritmalarından değil, basit olanlarındandır.

> **Ek bilgi (derste anlatılmadı):** Standart Armstrong aksiyomlarında arttırma kuralı "$X \to Y$ ise $XZ \to YZ$" biçimindedir. Hocanın söylediği "$XZ \to Y$" biçimi de doğrudur; bu, arttırma ile dönüşlülük ve geçişliliğin birlikte uygulanmasından çıkar.

### 10.3 Kanonik örtü

**Kanonik örtü**, kapanışın tersi yöndeki kavramdır: küçük dünyadan tanımlanan bir fonksiyonel bağımlılık kümesinin minimal halidir (minimal $F$ kümesi). Kanonik örtüde işlevsel bağımlılıkların sol tarafları birbirinden farklıdır ve artık (fazla) bağımlılık yoktur; artık olanlar çıkarılır. Bulunan kanonik örtüde önemsiz, kısmi ve geçişli bağımlılık olmamalıdır. $F$'den bir bağımlılık çıkarıldığında $F$ yine üretilebiliyorsa o bağımlılık artıktır.

Kanonik örtü aday anahtarları belirlemede kullanılır. Hoca, derste dept_advisor için aday anahtarların küçük dünya düşünülerek ve kombinasyonlar değerlendirilerek bulunduğunu, karmaşık şemalarda ise kanonik örtüden yola çıkıldığını söyledi. Aday anahtarlar BCNF'de değil, 3NF denetiminde gerekir.

Örnek: Sunudaki bağımlılık kümesinden artık bağımlılıklar atıldı:

- $B \to C$ ve $C \to A$'dan geçişlilikle $B \to A$ türetilir; $B \to A$ artıktır, çıkarılır.
- $BC \to A$ da türetilebilir ($B \to A$ ya da $C \to A$ geçerliyse BC de A'yı belirler); bu da çıkarılır.
- Geriye kalan kanonik örtü: $\{B \to C, C \to A\}$.

<!-- BELİRSİZ: Bu anın karesi yoktu; verilen kümenin {B→C, C→A, B→A, BC→A} olduğu altyazıdan (02:30:45-02:33:07) çıkarıldı. -->

Hoca sunudaki daha kapsamlı bir kanonik örtü örneğini öğrencilere bıraktı.

### 10.4 Normal formların özeti

Türkçe sunudaki özet (ekrandan, 02:30:00 ve 02:35:00):

- Tüm niteliklerin değer alanları yalın (atomic) ise $R$, 1NF'dir. (Bu zaten ilişkisel modeldeki ilişki (tablo) tanımıdır.)
- Asal olmayan tüm nitelikler tüm anahtarlara tam işlevsel bağımlı ise $R$, 2NF'dir.
- Asal olmayan tüm nitelikler tüm anahtarlara geçişli bağımlı değil ise $R$, 3NF'dir. (Asal olmayan nitelikler birbirinden bağımsız olmalı.)
- $R$'de tüm belirleyenler ilişkinin anahtarı ise $R$, BCNF'dir. (Asal nitelikler ile ilgili bir kısıtlama getiriyor.)

BCNF sağlanıyorsa diğerleri de sağlanır. Derste yalnız BCNF ve 3NF ayrıntılı tanımlandı; kitap 2NF'den hiç bahsetmediği için hoca kafa karışmasın diye örnekleri BCNF ve 3NF açısından değerlendirmeyi önerdi. Sununun "Örnekler" kısmında şu şemalar görünür (ekrandan, 02:35:00):

- ÖĞRENCİ(ÖNO, ÖADI, DERS(DADI, NOTU)): 1NF değil. ÖĞRENCİ(ÖNO, ÖADI, DADI, NOTU): 1NF.
- SATICI(ÜKODU, FNO, FADI, FADRESİ, SFİYATI), FNO → FADI, FADRESİ: 2NF değil.

Sunuda büyük olasılıkla Elmasri ve Navathe'nin kitabından alınmış örnekler ve ilişkilerin yitimli/yitimsiz ayrıştırılmasıyla ilgili koşullar da vardır; bunlar derste anlatılan konularla aynıdır.

## Örnek Sorular

**Soru 1** (ekrandan, 01:00:00): $r(A, B)$ şu duruma sahiptir: $(1,4)$, $(1,5)$, $(3,7)$. Bu durumda $A \to B$ ve $B \to A$ sağlanır mı?

> **Çözüm (derste verildi):** A = 1 olan iki satırda B değerleri 4 ve 5'tir; $A \to B$ sağlanmaz. B değerleri tekrar etmediği için $B \to A$'yı bozan bir durum yoktur; $B \to A$ sağlanır.

**Soru 2** (ekrandan, 01:15:00): $R = (A, B, C)$, $F = \{A \to B, B \to C\}$. $R_1 = (A, B)$, $R_2 = (B, C)$ ve $R_1 = (A, B)$, $R_2 = (A, C)$ parçalamaları yitimsiz midir?

> **Çözüm (derste verildi):** Birincisinde $R_1 \cap R_2 = \{B\}$ ve $B \to BC$, yitimsiz. İkincisinde $R_1 \cap R_2 = \{A\}$ ve $A \to AB$, yitimsiz.

**Soru 3** (ekrandan, 02:00:00): Aynı $R$ ve $F$ için şema BCNF midir? Değilse BCNF'ye parçalayın; parçalamanın yitimsiz olup olmadığını ve bağımlılığı koruyup korumadığını belirtin.

> **Çözüm (derste verildi):** $A^+ = ABC$, A süper anahtardır. $B \to C$'de B süper anahtar değildir, şema BCNF değildir. Parçalama: $(B, C)$ ve $(A, B)$. Kesişim B ve $B \to BC$ olduğu için yitimsiz; $A \to B$ ve $B \to C$ ayrı tablolarda denetlenebildiği için bağımlılık korunur. $(A,B),(A,C)$ parçalaması da yitimsizdir ama $B \to C$'yi korumaz.

**Soru 4** (ekrandan, 02:15:00): dept_advisor(s_ID, i_ID, dept_name), $F = \{i\_ID \to dept\_name;\ s\_ID, dept\_name \to i\_ID\}$. Aday anahtarları bulun; şemanın BCNF ve 3NF olup olmadığını belirleyin.

> **Çözüm (derste verildi):** Aday anahtarlar $\{s\_ID, dept\_name\}$ ve $\{s\_ID, i\_ID\}$. $i\_ID \to dept\_name$'de i_ID süper anahtar olmadığı için BCNF değildir. $\beta - \alpha = \{dept\_name\}$ bir aday anahtarın içinde olduğu için 3NF'dir. BCNF parçalaması (i_ID, dept_name) ve (s_ID, i_ID) olur ve $s\_ID, dept\_name \to i\_ID$ korunmaz.

**Soru 5** (ekrandan, 02:20:00; hoca öğrencilere bıraktı): $R = (J, K, L)$, $F = \{JK \to L, L \to K\}$. Şema neden BCNF değildir, neden 3NF'dir?

> **Çözüm (derste verilmedi):** Aday anahtarlar $\{J, K\}$ ve $\{J, L\}$'dir: $JK \to L$ olduğundan JK bütün şemayı belirler; $L \to K$ olduğundan JL de JLK'yı belirler; tek nitelikler anahtar değildir (python ile doğrulandı). $L \to K$'de L süper anahtar olmadığı için şema BCNF değildir. Ama $\beta - \alpha = \{K\}$, $\{J, K\}$ aday anahtarının içinde olduğu için 3NF koşulu sağlanır; $JK \to L$'de sol taraf zaten süper anahtardır. Bu yüzden şema 3NF'dir.

## Dersin Toparlaması

Bu derste iyi bir ilişkisel tasarımın veri tekrarını en aza indiren tasarım olduğu görüldü. instructor ve department'ı birleştiren in_dep örneği, tekrarın yer kaybına, güncelleme tutarsızlığına, null zorunluluğuna ve beklenmedik bilgi kaybına yol açtığını gösterdi. Çözüm şemayı parçalamaktır; ama parçalama yitimsiz olmalıdır. Kim örneğinde ortak nitelik anahtar olmadığı için birleşim daha çok satır üretip bilgiyi kaybettirdi. Fonksiyonel bağımlılık, anahtar kavramının genelleştirilmesi olarak tanımlandı; bağımlılıkların tablo durumundan değil, küçük dünyanın kurallarından geldiği vurgulandı. Süper anahtar, aday anahtar, trivial bağımlılık ve kapanış kavramları üzerine yitimsizlik testi ($R_1 \cap R_2$ parçalardan birini belirlemeli) ve bağımlılık koruma kriteri kuruldu.

Bu araçlarla iki normal form tanımlandı. BCNF, trivial olmayan her bağımlılıkta sol tarafın süper anahtar olmasını ister; parçalaması her zaman yitimsizdir ama dept_advisor örneğinde olduğu gibi bağımlılığı koruyamayabilir. 3NF, aday anahtar içindeki nitelikler için bir gevşeklik tanıyarak bağımlılık korumayı her zaman mümkün kılar; bedeli tekrar ve null değerlerdir. Son bölümde Türkçe sunu üzerinden anomaliler, Armstrong kuralları, kanonik örtü ve 1NF-BCNF özeti tekrar edildi. Sonraki derslerde fiziksel tasarımla ilgili tanım ve kavramlara geçilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
