# Ders 6 Genişletilmiş Notu: ER Tasarımının İncelikleri, Tablolara Dönüşüm ve Genişletilmiş ER

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kavramsal Tasarıma Yeniden Bakış
- 2. Bağıntılar, Nitelikler ve Roller
- 3. Üçlü Bağıntılar ve İkili Gösterim
- 4. Kardinalite Gösterimleri ve Katılım
- 5. Üçlü Bağıntıda Oklar
- 6. Bağıntı Setlerinin Birincil Anahtarı
- 7. ER Diyagramından Tablolara
- 8. Bire Çok Bağıntı İçin Ayrı Tablo Ne Zaman?
- 9. Özelleştirme ve Genelleştirme
- 10. Birleştirme (Aggregation)
- 11. Yaygın Hatalar ve Tasarım Seçimleri
- Örnek Sorular

## 1. Kavramsal Tasarıma Yeniden Bakış

Hoca derse, tasarımın sayısal ve net bir sonucu olmadığını hatırlatarak başladı. Biz mühendisler net, sayısal sonuçlar isteriz; tasarımda ise bazı kapılar açık kalır. Yine de yöntemler vardır ve bunlar "en iyi" değilse de orta hâlli, iyi bir tasarım yapmayı sağlar. Tasarım yalnız bilim değil sanattır da (not only science, but also art); tecrübe ve meleke ister. Kitap da bazı noktaları "olabilir de olmayabilir de" diyerek açık bırakır. Hoca bu konuda iki ders kitabını takip ettiğini ve açıklama notlarını paylaştığını söyledi.

Kavramsal modellemede küçük dünyadaki kısıtlar ER diyagramlarıyla kâğıda, ilişkisel model dönüşümleriyle makineye aktarılır. Tam bir modelleme fonksiyonel gereksinimleri, işlemleri ve yetkilendirmeyi (kim ne yapabilir) de içerir; bunlar daha çok sistem analizi dersinin konusudur. Bu derste yalnız veri modellemeye, yani hangi verilerin ve aralarında hangi bağıntıların olacağına odaklanılır.

Mantıksal tasarım ile fiziksel tasarım arasındaki fark yeniden vurgulandı. Mantıksal tasarımın bir kez yapılıp çok zorda kalınmadıkça değişmemesi umulur. Hocanın örneği: Şu anda bir hoca bir bölüme aittir, ama ileride bir hoca birden çok bölüme ait (ortak hoca, joint professor) olabilir. Bunu baştan düşünüp mevcut durumu bozmadan genişletilebilecek bir tasarım yapmak daha profesyoneldir. Fiziksel tasarım ise kullanıcı profillerine ve verinin karakteristiğine göre değişebilir; sosyal medyadaki gibi patlamalı, çok değişken veride zaten değişmeye çok açıktır.

Tasarımın iki problemi fazlalığı (redundancy) tespit etmek ve gereksinimlerin sağlanıp sağlanmadığını, yani eksikliği (incompleteness) kontrol etmektir. Hoca slayttaki listeye üçüncü bir madde olarak veri kaybının (data loss) eklenebileceğini söyledi; tasarımda veri kaybı olabilir ve bu, normalizasyonun konusudur. Hocaya göre konunun %80'i kolaydır, %10-15'i zordur, küçük bir kısmı da bulanıktır.

## 2. Bağıntılar, Nitelikler ve Roller

ER diyagramında varlık setleri, bağıntı setleri ve nitelikler vardır; nitelikler hem varlık hem bağıntı setleri için geçerlidir. Hoca `advisor` bağıntısını hatırlattı: Bir hoca birçok öğrenciye danışmanlık yapabilir, bir öğrencinin tipik olarak bir danışmanı vardır. Ama küçük dünya değişebilir: Çift ana dal yapan bir öğrencinin iki farklı bölümde birer danışmanı olabilir. Böyle küçük bir değişiklik tasarımı ve tabloları değiştirir; belki bir tablo iki tablo olur ya da tersi.

Bağıntı setinin niteliği örneği yine `advisor`'daki `date`'tir: `I1` hocası `S1` öğrencisine şu tarihte, `S2` öğrencisine başka bir tarihte danışmanlık etmeye başlamıştır (imza tarihi gibi). Rol gerektiren durum ise özyinelemeli (recursive) bağıntılardır: Derslerin ön koşulları. Hocaya göre "recursive" denmesinin sebebi zincirleme gitmesidir: Bir dersin ön koşulları, onların da ön koşulları vardır.

## 3. Üçlü Bağıntılar ve İkili Gösterim

Bağıntıların çoğu ikilidir ve ikili bağıntı hemen algılanır. Ama bazı durumlarda üçlü bağıntı meseleyi daha doğal (hocanın ifadesiyle "fıtri") biçimde temsil eder. Örnek cümle: "Students work on research projects under the guidance of an instructor." Bu hadise iki değil üç varlık seti arasındadır. Bu durumda "ikili bağıntılarla yapabilir miyim?" sorusu akla gelir. Hocanın tavsiyesi: Zorlamaya gerek yok; böyle bir cümle görünce üçlü bağıntı kullanmak meseleye tam hitap eder. Kavramsal tasarımın amacı da kavramı, bir yıl sonra kendimizin ve başkalarının anlayacağı standart biçimde kâğıda dökmektir.

Slayttaki ifade "more convenient"tır, yani daha uygundur; ikili bağıntılarla yapmak imkânsız değildir. Slaytta (ekrandan, 00:25:40) hoca harfleri şöyle eşleştirdi: A: `project`, B: `instructor`, C: `student`, E: `proj_guide`. Üç gösterim vardır:

```text
(1) Üçlü bağıntı:
      project
         |
 instructor ---< proj_guide >--- student

(2) Yapay varlık seti ile (denk):
            A
            |
          <R_A>
            ||
 B --<R_B>== E ==<R_C>-- C        (E zayıf, bağıntılar çift çizgili)

(3) Yalnız ikili bağıntılar (denk değil):
   B --<R_AB>-- A --<R_AC>
   |                  |
   +------<R_BC>------ C
```

Bu örnekte bağıntı çoka çoka çoktur: Birçok hoca, birçok öğrenci, birçok proje vardır; öğrenciler birçok hocayla birçok projede çalışabilir.

(2)'de `E`, `proj_guide`'ın her elemanını temsil eden yapay bir varlık setidir. Hoca `E`'nin zayıf varlık olduğunu, bu yüzden hem `E`'nin hem de onu A, B ve C'ye bağlayan bağıntıların çift çizgiyle çizilmesi gerektiğini söyledi (slayttaki şekilde unutulmuştu); `E`'nin belirleyicileri A, B ve C'dir. `E`'nin bir elemanı A, B, C'den birer eleman içerir; örneğin `(P1, I1, S1)` verisi aynen üretilebilir. Bu dönüşüm her zaman mümkündür ve bilgi kaybı yoktur.

(3)'te ise her şey ikili yapılır: A-B, A-C ve B-C arasında birer bağıntı. Hocanın özeti: Üçlü bağıntının örnek verisinden bu üç ikili bağıntının verisi çıkarılabilir; ama tersi her zaman mümkün değildir. İkili tablolardan birleştirmelerle (join) üçlü bilgiye bazen erişilir, bazen erişilemez; bilgi kaybı olabilir. Hoca bunu 6. bölüm açıklama dokümanında örnek veriyle açıkladığını söyledi.

> **Ek bilgi (derste anlatılmadı):** (3)'ün neden denk olmadığını görmek için büyük olasılıkla şu tür bir örnek kullanılır: `(P1, I1, S2)`, `(P1, I2, S1)` ve `(P2, I1, S1)` üçlüleri varken ikili tablolarda `(P1, I1)`, `(P1, S1)` ve `(I1, S1)` çiftlerinin hepsi bulunur. Bu çiftlerin birleşimi, aslında hiç olmayan `(P1, I1, S1)` üçlüsünü de üretir. Yani ikili çiftlerden üçlü bilgi doğru olarak geri kurulamaz.

## 4. Kardinalite Gösterimleri ve Katılım

Bire bir, bire çok ve çoka çok gösterimleri basittir; hoca bunlarda sorun olmaması gerektiğini vurguladı. Ok "bir", düz çizgi "çok" anlamına gelir: `advisor`'da öğrenciden hocaya ok varsa bir öğrencinin bir danışmanı vardır, bir hocanın birçok öğrencisi olabilir.

Aynı kitap bunun yanında `l..h` (minimum..maksimum) gösterimini de kullanır. Maksimum değer küçük dünyadan gelir: Bir hoca en fazla 10, bir başkası 20 öğrenci alırım diyebilir; bu üst sınır tasarıma aktarılabilir. `instructor` tarafındaki `0..*`'da 0, hocanın hiç öğrencisi olmayabileceğini; `*` birçok öğrencisi olabileceğini söyler. Önemli bir okuma ayrıntısı: Bir taraftaki `l..h`, o taraftaki varlığın bağıntıya kaç kez katıldığını anlatır.

İlk değer katılımı, ikinci değer kardinaliteyi taşır. `student` tarafındaki `1..1`, her öğrencinin en az ve en fazla bir hocası olduğunu söyler: Öğrenci tarafı tam (total), hoca tarafı kısmi (partial) katılımlıdır. Hoca, bu iki şeklin denkliğini gösterdi: Ok ve çift çizgili gösterimde ok "bir" bilgisini, çift çizgi tam katılımı verir; `l..h` gösteriminde ikisi `1..1` içinde birleşir. Tam ya da kısmi olması ilişkisel model dönüşümünde tablo oluşup oluşmayacağını ve yabancı anahtarın hangi tarafa gideceğini şekillendirir.

> **Hocanın vurgusu:** Paylaşılan ek dokümanda ER örneklerinin yanında UML örnekleri de var. UML'deki kardinalite gösterimi bizim kullandığımız `l..h` gösterimine terstir. Sınavda kitaptaki notasyon kullanılacak; UML örneklerine bakıp kafanızı karıştırmayın.

## 5. Üçlü Bağıntıda Oklar

Çoka çoka çok bir üçlü bağıntıda sorun yoktur. Ama küçük dünyada örneğin "bir öğrenci bir hocayla yalnız bir projede çalışabilir" gibi bir kısıt varsa, bu kardinaliteyi üçlü bağıntıya oklarla aktarmak gerekir. Kitap karışıklığı önlemek için üçlü bağıntıda birden fazla oku yasaklar ("to avoid confusion we outlaw more than one arrow").

Tek ok belirsizlik taşımaz. A, B, C arasındaki bir `R` bağıntısında yalnız B'ye ok olsun. Bu, A ve C'den bir çift aldığımızda, örneğin `(A1, C1)`, bu çiftin yalnız bir B ile (`B1`) eşleştiği anlamına gelir. `(A1, C1)` bir daha görülmez; ama `A1` ya da `C1` tek başına başka kombinasyonlarda görülebilir (örneğin `(A2, C1)`).

İki ok olduğunda (B ve C'ye) iki yorum mümkündür:

- `A1` bir kez ortaya çıkar ve tek bir `(B, C)` çiftiyle eşleşir; `(A1, B1, C1)` varsa başka hiçbir `A1` satırı yoktur.
- Ya da tek oklu durum gibi düşünülür: `(A1, B1)` çifti bir daha görülmez ama `(A1, B2, ...)` görülebilir.

Hocanın öğrenci-proje-hoca örneği: `(S1, P1, I1)` varsa `(S1, P2, I1)` görülmeyecektir; ama `(S1, P2, I2)` görülebilir mi? İki ok gösterimi bu soruyu belirsiz bırakır. Hocanın kanaati: Böyle bir kısıt varsa üçlü bağıntı kullanmayıp her zaman mümkün olan yapay varlık setli gösterimi (bölüm 3'teki (2)) kullanmak ve okları o ikili bağıntılara koymak gerekir. Hoca, kitabın konuyu böyle bıraktığını, bunun kendi kanaati olduğunu, itiraz edenle tekrar değerlendirebileceğini söyledi.

## 6. Bağıntı Setlerinin Birincil Anahtarı

Varlık setleri için birincil anahtar kolaydır. Bağıntı setleri için (hoca slayttaki bir ifadenin kafa karıştırıcı olduğunu söyleyip onu okumamayı önerdi):

- **Çoka çok:** Bağıntı setinin anahtarı iki taraftaki birincil anahtarların ikisi birden olmalıdır; çünkü her taraftaki eleman diğer taraftaki birden çok elemanla eşleşebilir, tek bir taraf tekrar eder.
- **Bire çok / çoka bir:** "Çok" tarafının anahtarı anahtardır. `(A1, B1)`, `(A1, B2)`, `(A1, B3)` çiftlerinde `A1` tekrar ettiği için anahtar olamaz; her `B` ise yalnız bir kez görülür. Slayt: "The primary key of the many side is a minimal superkey and is used as the primary key."
- **Bire bir:** Herhangi bir taraf anahtar olabilir; soldan da sağdan da bir eleman bir daha görülmez.

## 7. ER Diyagramından Tablolara

Hoca zayıf varlıkları tekrar hatırlattı: Zayıf varlık istenmeyen bir şey değildir. Zayıf varlıklar için ayrı bir birincil anahtar tanımlanmaz, güçlü varlığın altında bir ayırt edici (discriminator) bulunur; bu sistem için daha hafiftir. Hoca, bütün üniversite ER diyagramını kendi başınıza çizmeye çalışmanın, laboratuvardaki company veritabanı için de aynısını yapmanın iyi bir alıştırma olacağını söyledi.

Normalizasyon bu aşamadan sonra gelir; bu derste ertelendi. Dönüşüm kuralları:

- **Güçlü varlık setleri** doğrudan tabloya dönüşür: `course(course_id, title, credits)`.
- **Zayıf varlık setleri**, güçlü varlığın birincil anahtarı ve kendi nitelikleriyle: `section(course_id, sec_id, semester, year)`.
- **Bileşik nitelikler:** Üstteki `name` ya da `address` değil, en alttaki bileşenler (`first_name`, `middle_initial`, `last_name`, `street_number`, ...) nitelik olarak kullanılır.
- **Türetilmiş nitelik:** Hoca `age()` gösterimini sordu; cevap türetilmiş (derived) nitelikti. Yaş tabloda saklanmaz, doğum tarihinden hesaplanır; hoca bunun bir stored procedure ile hesaplanabileceğini söyledi.
- **Çok değerli nitelik:** `{phone_number}` ayrı bir tabloda saklanır, çünkü bir satırda bir niteliğin yalnız bir değeri olabilir. Tablo `inst_phone(ID, phone_number)`, anahtarı ikisi birdendir.

### 7.1 Telefon numarası için tasarım tartışması

Hoca tek bir telefon için nitelik tipinin ne olabileceğini sordu: integer ya da double değil, 10 haneli bir `char` ya da `varchar`. Birden çok telefon varsa seçenekler:

- `phone1`, `phone2`, `phone3` sütunları: İyi tasarım değildir. Hocaların çoğunun bir telefonu vardır, diğer sütunlar null kalır. Başka bir küçük dünyada çoğu kişinin 4-5 telefonu olabilir; baştan bir sınır koymuş oluruz. Veri kaybolmasın diye 10 sütun koymak da kötüdür.
- Dizi (array) tipi: PostgreSQL ve diğer veritabanlarının hepsinde vardır. Bu yüzden bu sistemler saf (katıksız) ilişkisel değil, nesne-ilişkisel (object-relational) sistemlerdir. Dizi, formal ilişkisel modele aykırıdır ve 1NF'yi bile sağlamaz, ama çok daha verimlidir.
- Ayrı tablo: Saf ilişkisel model için geçerli yoldur. Bedeli: 100 hocanın her birinin 3 telefonu varsa 100 satırlık hoca tablosunun yanında 300 satırlık bir tablo oluşur.

Anahtarın neden ikisi birden olduğu: Yalnız `ID` olamaz, çünkü bir hocanın birden çok telefonu vardır. Yalnız `phone_number` olabilir gibi görünür; ama iki hoca aynı ev telefonunu kullanıyor olabilir, bu da garip bir varsayım değildir. Bu yüzden numara da tekrar edebilir.

> **Hocanın vurgusu:** Kuralları ezberleyebiliriz, ama asıl amaç birincil anahtarın, tablonun, şemanın ne demek olduğunu öğrendikten sonra bütün melekeyi işletip kuralın neden öyle olduğunu görmektir.

### 7.2 Bağıntı setlerinin dönüşümü

Çoka çok bağıntı için mutlaka yeni bir tablo tanımlanır; başka yollar denendiğinde başka türlü olamayacağı görülür.

Bire çok bağıntıda "bir" taraftaki anahtar "çok" tarafına taşınır ve yabancı anahtar yapılır; ilişkisel modelde ilişkiler tablolarda yabancı anahtar olarak ortaya çıkar. "Bir" tarafa taşımayı deneyince neden olmadığı görülür: `I1`'in bölümü `D1`, `I2`'nin bölümü `D1`, `I3`'ün bölümü `D1` ise her hoca satırında `D1` yazılabilir. Ama `D1` tek bir satırdır; o satıra `I1, I2, I3`'ü nasıl yazacağız? Bu bağıntı ancak "çok" tarafına aktarılabilir.

Tek yol bu değildir: Bağıntı için ayrı bir tablo da tanımlanabilir. Çoka çokta bu zorunludur; bire çok, çoka bir ve bire birde de yapılabilir. Bu tablonun anahtarı bölüm 6'daki kurallarla belirlenir: Çoka birde "çok" tarafı, bire birde herhangi bir taraf.

## 8. Bire Çok Bağıntı İçin Ayrı Tablo Ne Zaman?

Hoca önce bir uyarı yaptı: Kavramsal tasarımda `instructor` varlığına `dept_name` yazmayın; bu fazlalıktır ve hatadır. Tablo dönüşümü sırasında `dept_name` kurala göre `instructor` tablosuna gelir.

`inst_dept` için ayrı bir tablo kurulsaydı adı `inst_dept`, nitelikleri `ID` ve `dept_name` olurdu. Anahtar "çok" tarafı olan `ID`'dir: `(I1, D1)` varken `(I1, D2)` olamaz, çünkü hocanın tek bölümü vardır; `D1` ise birçok kez geçebilir.

Peki neden ayrı tablo tercih edilir? Hoca cevabı diyagramdaki çift çizgide gösterdi: tam katılım. Tam katılımda her hocanın bir bölümü vardır; yabancı anahtar taşınınca hiçbir satırda null görülmez. Kısmi katılımda ise bazı hocaların bölümü yoktur. Kaba bir örnekle 1000 hocadan 500'ünün bölümü yoksa, yabancı anahtar yaklaşımında 500 null görülür; bu iyi tasarım değildir. Ayrı tabloda ise yalnız gerçekten bölümü olan 500 hoca bir satır olarak yer alır.

Üniversite örneğinde `inst_dept` ve `stud_dept` tam katılımlı olduğu için ayrı tabloya gerek yoktur, `dept_name` hoca ve öğrenci tablolarına gider. `advisor` ise kısmi olabileceği için ayrı tablo daha iyi olabilir.

**Soru:** (Bir öğrenci, `inst_dept` için ayrı tablo oluşturulabileceğini doğru anlayıp anlamadığını sordu ve bir yorum yaptı; yorumun ayrıntısı altyazıda yok.) **Cevap:** Hoca yorumu doğru buldu ve bunun bir ödünleşim (trade-off) olduğunu söyledi. Öğrencilerin yalnız birkaçının danışmanı yoksa yine yabancı anahtar yolu seçilebilir; çünkü yeni bir tablo büyük olasılıkla fiziksel olarak yeni bir dosya ve ayrı bir join maliyeti demektir. Tersine, bağıntı küçük dünyada çok seyrekse ayrı tablo çok küçük olur, ana belleğe sığar ve join'i ucuz olur; diğer yolda ise bir ton null oluşurdu. Genel eğilim ayrı tablo kurmamak, yabancı anahtarı "çok" tarafına atmaktır; bire birde de herhangi bir taraf yabancı anahtar olarak alınır.

<!-- BELİRSİZ: 01:07:29 civarındaki öğrenci yorumunun metni altyazıda yok. -->

Zayıf varlığı güçlüsüne bağlayan bağıntı için ayrıca düşünmeye gerek yoktur: Zayıf varlığın tablosu oluşturulurken güçlünün birincil anahtarı zaten taşınmıştır.

## 9. Özelleştirme ve Genelleştirme

Genişletilmiş ER'de (EER) iki ana mesele vardır: özelleştirme/genelleştirme ve birleştirme. Özelleştirme (specialization) bir varlık setinin alt varlık setlerine ayrılıp detaylandırılmasıdır; genelleştirme (generalization) farklı varlık setlerinin genelleştirilip tek bir yerde toplanmasıdır. Hangi yönden baktığımıza göre değişir.

Örnek: Bütün kişiler `person` üst varlık setindedir; alt setleri `employee` ve `student`'tır. `employee`'nin `salary`, `student`'ın `tot_cred` niteliği vardır; `ID`, `name`, `street`, `city` ise hepsinde ortaktır. Hepsi tek bir `person` setinde tutulsaydı bazı kişiler için `salary`, bazıları için `tot_cred` boş kalırdı. Özelleştirmeyle null'lar ortadan kalkar, veritabanı daha belirli hâle gelir; bedeli ayrı tablolardır.

Kısıtlar:

- **Örtüşen (overlapping) / ayrık (disjoint):** Bir `P1` kişisi hem öğrenci hem çalışan olabilir mi? Gerçek hayatta olabilir: Kısmi zamanlı çalışan, asistanlık yapan öğrenciler vardır. Bu örtüşen özelleştirmedir. Diyagramda alt setlere ayrı oklar çizilir; hoca bu notasyonu pek iyi bulmadığını söyledi. Ayrık durumda alt setlere giden oklar tek bir noktada birleşir: Bir sekreter aynı zamanda hoca olamaz.
- **Tam (total) / kısmi (partial):** Üst setteki herkes mutlaka bir alt sette mi olmalı? Hocanın örneği: Fakültede birkaç ay çalışıp giden sözleşmeli kişiler başka bir yerin çalışanıdır, ne bizim çalışanımız ne öğrencimizdir. Böyle kişiler varsa özelleştirme kısmidir. Diyagramda tam özelleştirmenin yanına "total" yazılır. Hocanın yorumu: `person` altı tam olabilir, ama `employee` altındaki `instructor`/`secretary` ayrımı kısmi olabilir, çünkü bunlar dışında da çalışanlar vardır.

### 9.1 Şemaya dönüştürme

Slayttaki iki yöntem (ekrandan, 01:17:30):

| Yöntem | Şemalar | Dezavantaj |
|---|---|---|
| 1: Üst seviye için bir şema; her alt seviye için üst seviyenin birincil anahtarı ve yerel nitelikler | `person(ID, name, street, city)`, `student(ID, tot_cred)`, `employee(ID, salary)` | Bir çalışanın bilgisi için iki ilişkiye (alt ve üst seviye) erişmek gerekir |
| 2: Her varlık seti için yerel ve miras alınan bütün nitelikler | `person(ID, name, street, city)`, `student(ID, name, street, city, tot_cred)`, `employee(ID, name, street, city, salary)` | Hem öğrenci hem çalışan olan kişilerin `name`, `street`, `city` bilgisi tekrar saklanabilir |

Hocanın yorumu: Kısmi özelleştirmede Yöntem 1 daha iyidir. Tam ve ayrık özelleştirmede ise `person` tablosuna hiç gerek yoktur: `student(ID, tot_cred, name, street, city)` ve `employee(ID, salary, name, street, city)` yeterlidir; herkes ya öğrencidir ya çalışandır ve hiçbir veri tekrar etmez. Hoca dört kombinasyonu (örtüşen-tam, örtüşen-kısmi, ayrık-tam, ayrık-kısmi) fazlalık açısından değerlendirmeyi önerdi; burada da kesin kural yoktur.

## 10. Birleştirme (Aggregation)

Arada 01:20-01:34 arası mola verildi. Hoca birleştirmeyi "bağıntılar arasında bağıntı ifade etme ihtiyacı" başlığıyla anlattı. "Aggregate" kelimesinin anlamı toplamak, topaklamaktır: `proj_guide` bağıntısı toplu olarak bir bütün gibi düşünülür.

Problem: `project`, `student` ve `instructor` arasında `proj_guide` üçlü bağıntısı var. Bu bağıntının, yani bir öğrencinin bir hocanın rehberliğinde bir projede yaptığı çalışmanın değerlendirilmesi (`evaluation`) gerekiyor. Hoca seçenekleri sırayla eledi:

- **Durum 1, dörtlü bağıntı:** `evaluation`'ı dördüncü varlık seti yapıp bağıntıyı dört dereceli yapmak. Sorun: Bütün projeler değerlendirilmeyebilir. Proje hadisesi ile değerlendirme hadisesi ayrıdır. Gerçekten bütün projeler değerlendiriliyorsa dörtlü olabilir.
- **Durum 2, çok değerli nitelik:** `proj_guide`'a çok değerli bir değerlendirme niteliği koymak. Yanlış değildir, ama değerlendirmenin bir bölüme ya da burs ofisine bildirilmesi gibi başka bağıntıları olabilir; bu, değerlendirmenin bir varlık seti olmasını gerektirebilir.
- **Durum 3, üçlünün yanında ayrı bir dörtlü bağıntı (`eval_for`):** Fazlalık getirir. Projelerin %80'i değerlendiriliyorsa, `(P1, I1, S1)` bilgisi hem `proj_guide`'da hem `(P1, I1, S1, E1)` olarak `eval_for`'da tekrar eder.

Çözüm birleştirmedir (ekrandan, 01:42:30): `proj_guide` ve ona katılan varlıklar bir kutu içine alınır; `proj_guide` artık birleştirilmiş bir bağıntı ve daha üst seviyede bir "varlık seti" gibidir. Bu birleştirilmiş yapı `eval_for` bağıntısıyla `evaluation`'a bağlanır. Diyagram şunu anlatır: Bir öğrenci belirli bir projede belirli bir hocanın rehberliğindedir; bir öğrenci-hoca-proje kombinasyonunun ilişkili bir değerlendirmesi olabilir (may have).

```text
+-------------------------------------------+
|              project                       |
|                 |                          |   <- birleştirme (aggregation)
| instructor --< proj_guide >-- student      |
+-------------------------------------------+
                  |
              < eval_for >
                  |
             evaluation
```

Tabloya dönüşüm: `eval_for` şeması `proj_guide`'ın birincil anahtarlarını (öğrenci, proje, hoca) ve `evaluation`'ın anahtarını içerir. Slayta göre birleştirme `eval_for`'a tam katılıyorsa, yani bütün kombinasyonlar değerlendiriliyorsa, `proj_guide` şeması fazlalıktır ve tek bir `eval_for` tablosu yeterlidir; sanki dörtlü bağıntı yapılmış gibi olur. Yalnız bazı projeler değerlendiriliyorsa `proj_guide` için ayrıca bir tablo tutulur ve öğrenci-proje-hoca bilgisi iki tabloda tekrar eder.

Hoca, kitapta yazmayan bir seçenek de önerdi: `proj_guide` için yapay (artificial) bir anahtar, örneğin 1, 2, 3, ... diye giden bir sıra numarası tanımlamak. Bu anahtar `proj_guide` tablosunun birincil anahtarı olur, `eval_for`'da yabancı anahtar olarak kullanılır; böylece proje, hoca ve öğrenci bilgisi `eval_for` tarafında tekrar etmez.

## 11. Yaygın Hatalar ve Tasarım Seçimleri

### 11.1 Bağıntıdan çıkarılabilen nitelik

`student` için ilk listede `ID`, `name`, `tot_cred` ve `dept_name` yazılabilir; ama `department` varlığı ve `stud_dept` bire çok bağıntısı kurulduktan sonra bu bilgi bağıntıdadır ve `student`'tan çıkarılmalıdır. Tabloya dönüşümde `dept_name` yabancı anahtar olarak "çok" tarafına zaten gelecektir; bu dönüşümün sonucudur. Slayttaki yanlış örnekte hem bağıntı vardır hem de `dept_name` öğrenciye yazılmıştır; bu fazlalıktır ve çok yanlıştır.

### 11.2 Bağıntı niteliğinin yanlış kullanımı

Slayttaki ikinci hata (ekrandan, 01:50:30): `student` ile `section` arasındaki `stud_section` bağıntısına `assignment` ve `marks` nitelikleri konmuş. Slayt notu: "Burada iki nitelik var; birincil anahtarı `s_id` ve `sec_id` olan belirli bir öğrenci-şube çifti için yalnız tek bir ödev gösterebiliriz." Hocanın ekrandaki örnek verisi:

```text
S1, Sec1, A1, 10
S1, Sec2, A1, 30
S1, Sec2, A2, 30
S2, Sec1, A1, 20
```

`S1, Sec2` çifti için iki ödev vardır, ama bağıntının bir satırına sığmaz. Doğru alternatifler:

- (c) `assignment`, `section`'a `sec_assign` belirleyici bağıntısıyla bağlı zayıf bir varlıktır; `student` ile `assignment` arasında `marks` nitelikli `marks_in` bağıntısı kurulur. Hoca, `section`'ın da aslında `course`'a bağlı zayıf bir varlık olduğunu, slaytta güçlü göründüğünü belirtti. Bu tasarım çok daha nettir: Bu dersin, bu şubesinin, bu ödevinde öğrencinin notu.
- (d) `stud_section` üzerinde çok değerli ve bileşik bir `{assignment_marks}` niteliği (`assignment`, `marks`): Bir öğrencinin bir şubede birden çok ödev notu olur.

### 11.3 Varlık mı, nitelik mi? Varlık mı, bağıntı mı?

Telefonu `instructor`'ın niteliği yapmak yerine `phone` varlık seti ve `inst_phone` bağıntısı kurulabilir; slayta göre bu, telefon numarası hakkında ek bilgi (örneğin konum) ve birden çok numara saklamaya izin verir.

Hoca bir cümle ekledi: Orijinal tasarımda `section` ile `student` arasında `takes` bağıntısı vardır. Onun yerine bir `registration` varlık seti ve iki bağıntı da kullanılabilir; bir kayıt varsa mutlaka bir öğrenci ve bir şube olduğu için iki taraf da tam katılımlıdır. Bu yanlış değildir, ama daha az özdür (concise); fazladan bir varlık seti ve bağıntı olur, tabloya dönüşünce belki aynı kapıya çıkar ama dolambaçlıdır. `registration`'ın başka bir varlıkla bağıntısı varsa bu tercih gerekli olabilir.

### 11.4 Notasyon özeti

Hoca ER notasyonlarının özet slaytını gösterdi ve sınavda bunların mutlaka bilinmesi gerektiğini söyledi: varlık seti, bağıntı seti, belirleyici bağıntı, tam katılım, birincil anahtar, ayırt edici, bileşik, çok değerli ve türetilmiş nitelik, örtüşen ve ayrık özelleştirme, kardinalite sınırları. Ek dokümandaki farklı notasyonlu örneklere (UML) bakılmamasını tekrar hatırlattı. Böylece 6. bölüm bitti; normalizasyon (7. bölüm) bir sonraki derse kaldı.

## Örnek Sorular

**1.** (derste sözlü, 00:51:32) Çok değerli `phone_number` niteliği için ayrı bir tablo kurulursa tablonun nitelikleri ve birincil anahtarı ne olur?

Derste verilen cevap: Tablo `inst_phone(ID, phone_number)` olur. Anahtar ikisi birdendir: `ID` tek başına olamaz, çünkü bir hocanın birden çok telefonu vardır; `phone_number` tek başına da olamaz, çünkü örneğin aynı evde oturan iki hoca aynı telefonu kullanabilir.

**2.** (derste sözlü, 00:52:57) Bir hocanın birden çok telefonu varsa `phone1`, `phone2`, `phone3` sütunları ya da dizi (array) tipi kullanmak iyi bir tasarım mıdır?

Derste verilen cevap: Ayrı sütunlar iyi değildir; çoğu hoca için null kalırlar ve baştan bir üst sınır koyarlar. Dizi tipi PostgreSQL gibi nesne-ilişkisel sistemlerde vardır ve verimlidir, ama formal ilişkisel modele aykırıdır, 1NF'yi bile sağlamaz. Saf ilişkisel modelde doğru yol ayrı tablodur.

**3.** (derste sözlü, 01:03:08) Bire çok bir bağıntıda yabancı anahtarı "çok" tarafına taşımak yerine neden ayrı bir tablo kurmayı tercih edebiliriz?

Derste verilen cevap: Belirleyici olan katılımdır. "Çok" tarafı tam katılımlıysa yabancı anahtar taşınır, null oluşmaz. Kısmi katılımda yabancı anahtar sütunu birçok satırda null kalır; bu durumda ayrı tablo daha iyi olabilir. Ama ayrı tablo yeni bir dosya ve join maliyeti getirdiği için bu bir ödünleşimdir.

**4.** (derste sözlü, 01:56:27) Yaygın hatalar slaytındaki doğru tasarımda (`assignment` zayıf varlığı) `assignment` tablosunda `course_id` olacak mı? Notlar hangi tabloda, hangi anahtarla saklanır?

Derste verilen cevap: Evet. `assignment`, zayıf olan `section`'a; `section` de güçlü olan `course`'a bağlıdır. Zayıf varlık sonunda bir güçlü varlığa ulaşmalıdır. Bu yüzden `assignment` tablosu `course_id`, `sec_id` ve ödev numarasını içerir. `student` ile `assignment` arasındaki bağıntı çoka çok olduğu için notlar ayrı bir tabloda saklanır: anahtarı öğrenci `ID`'si, `course_id`, `sec_id` ve ödev numarasından oluşur. Hocanın örnek verisi (`S1, Sec1, A1, 10` gibi) bu dördünden hiçbir ikili ya da üçlü kombinasyonun anahtar olamayacağını gösterir: Bir öğrenci bir dersin bir şubesinin bir ödevinden bir not alır.

> **Ders sonrası not:** Slayttaki şemalar dönem ve yılı da `section`'ın ayırt edicisi sayar (`sec_id`, `semester`, `year`). O gösterimde `assignment` ve not tablolarının anahtarına büyük olasılıkla `semester` ve `year` da girer; hoca cevabında bunları ayrıca saymadı.

## Dersin Toparlaması

Bu derste ER tasarımının ince noktaları tekrar edildi ve genişletildi: Üçlü bağıntıların yapay varlık setiyle ikili gösterime denk dönüştürülmesi, yalnız ikili bağıntılara bölmenin bilgi kaybına yol açabilmesi, `l..h` gösteriminde katılım ve kardinalite, üçlü bağıntıda tek ok kuralı ve bağıntı setlerinin birincil anahtarları. ER diyagramından tablolara dönüşüm kuralları (güçlü ve zayıf varlıklar, bileşik, türetilmiş ve çok değerli nitelikler, bağıntılar) örneklerle gerekçelendirildi; bire çok bağıntıda ayrı tablonun katılıma bağlı bir ödünleşim olduğu gösterildi. Genişletilmiş ER'de özelleştirme/genelleştirme kısıtları ve şemaya dönüşüm yöntemleri, birleştirme ve yaygın ER hataları ele alındı.

Hoca 6. bölümün burada bittiğini, normalizasyona (7. bölüm) bir sonraki dersten itibaren geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
