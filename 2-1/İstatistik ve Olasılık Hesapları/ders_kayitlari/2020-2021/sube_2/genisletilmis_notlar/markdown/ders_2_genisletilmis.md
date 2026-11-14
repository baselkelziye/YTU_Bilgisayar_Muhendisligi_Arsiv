# Ders 2 Genişletilmiş Notu: Sayılabilir Kümeler, Kuvvet Kümesi, Olasılık Aksiyomları ve Temel Olasılık Kuralları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kümeler Konusunun Tekrarı ve Fark Kuralı
- 2. Fonksiyonların Tekrarı
- 3. Sayılabilir ve Sayılamaz Kümeler
- 4. Kapsayan Kümeler ve Bölüntü
- 5. Kuvvet Kümesi
- 6. Chat Sorusu: Tam Sayılar Gerçekten Sayılabilir mi?
- 7. Olasılık Teorisine Giriş: Deney, Çıktı, Olay, Örneklem Uzayı
- 8. Olasılık Nedir? Fonksiyon Olarak Olasılık ve İki Yorum
- 9. Olasılık Aksiyomları
- 10. Aradaki Soru: Koşullu Olasılık Sezgisi
- 11. Olasılık Hesaplamak: Eşit Olasılıklı Çıktılar
- 12. Aksiyomlardan Türeyen Kurallar
- 13. Dersin Sonundaki Türkçe Tekrar

## 1. Kümeler Konusunun Tekrarı ve Fark Kuralı

Hoca derse, önceki hafta olasılığın ne olduğuna kısaca değinip kümelere başladıklarını hatırlatarak girdi. Kümeleri büyük ölçüde zaten bildiğimizi söylediği için bu kısmı hızlı geçti. Küme nedir, iyi bilinen kümeler hangileridir (doğal sayılar, tam sayılar, reel sayılar, rasyonel sayılar), alt küme, evrensel küme, boş küme, Venn diyagramları, birleşim, kesişim, tümleyen ve fark işlemleri önceki dersten biliniyor.

### 1.1 Farkın Kesişimle Yazılması

Hoca, geçen hafta söylemeyi unuttuğu ve notlarını gözden geçirirken eklediği bir kuralı "oldukça önemli" diyerek verdi:

$$A \setminus B = A \cap B^c$$

Bunu Venn diyagramı üzerinde görmek kolaydır. $A$ kümesini çizelim. $B^c$, $B$'nin dışında kalan bütün bölgedir. Hem $A$'nın içinde hem de $B^c$'nin içinde olan bölge, $A$'nın $B$'ye girmeyen parçasıdır. Bu parça tam olarak $A \setminus B$'dir. Yani aynı bölgeye ister "$A$ fark $B$", ister "$A$ kesişim $B$'nin tümleyeni" diyebiliriz.

### 1.2 İki Kitap Arasındaki Notasyon Farkları

Derste iki kitap birlikte kullanılacak: Michael Baron'un kitabı ve Pishro-Nik'in kitabı. Hoca ikisinin benzer olduğunu, ikisinden de yararlanabileceğini söyledi. İki kitap aynı kavramlara bazen farklı işaretler verdiği için bu farkları baştan bilmek gerekir:

| Kavram | Pishro-Nik | Baron |
|---|---|---|
| Fark | $A - B$ | $A \setminus B$ |
| Tümleyen | $A^c$ | $\bar{A}$ |
| Evrensel küme / örneklem uzayı | $S$ | $\Omega$ |

<!-- BELİRSİZ: Hoca işaretleri tahtaya yazıp "şöyle yazılır" diyor, altyazıda işaretlerin kendisi okunmuyor. Tablodaki biçimler kısa nottan alındı. Baron'daki tümleyen işareti için hoca "şapka" dedi; çizgi mi şapka mı olduğu altyazıdan anlaşılmıyor. -->

> **Ders sonrası not:** Hoca Baron'daki işarete iki kez "sigma karakteri" dedi; kısa notta bu işaret $\Omega$ olarak yazılı ve bu not da onu izliyor. Doğru adı büyük olasılıkla "omega"dır.

Hoca bunların küçük farklar olduğunu, geri kalan her şeyin hemen hemen aynı olduğunu ekledi. Ayrıca Pishro-Nik'in kitabının ilk bölümlerde biraz daha ayrıntılı olduğunu ve bunun iyi bir şey olduğunu söyledi.

### 1.3 Ayrık Kümeler ve Bölüntü

Kesişimi olmayan kümelere ayrık kümeler (disjoint sets) denir. Bunlara karşılıklı dışlayan kümeler (mutually exclusive sets) de denir. Hoca Türkçede "dışlayan kümeler" demeyi sevdiğini, "ayrık kümeler" adının da kullanıldığını söyledi.

Bölüntü (partition), evrensel kümeyi parçalara ayıran bir küme topluluğudur. Bir topluluğun bölüntü sayılması için iki koşul birlikte sağlanmalıdır:

- Kümeler ayrık olmalıdır, yani aralarında kesişim olmamalıdır.
- Kümelerin birleşimi evrensel küme olmalıdır.

Hoca tahtaya $A_1, A_2, A_3, A_4$ kümelerini, $A_3$ diğerleriyle örtüşecek biçimde çizdi ve bunun bölüntü olmadığını gösterdi. Sebep, kümelerin ayrık olmamasıdır. Bu tekrarda De Morgan yasaları ve dağılma yasası da önceki dersten hatırlatıldı.

## 2. Fonksiyonların Tekrarı

Fonksiyon bir eşlemedir (mapping). Tanım kümesindeki (domain) bir elemanı, görüntü kümesindeki (range) ya da değer kümesindeki (codomain) bir elemana götürür. Değer kümesi görüntü kümesini kapsar. Yani görüntü kümesi, değer kümesinin bir alt kümesidir.

Hocanın örneği $f: \mathbb{R} \to \mathbb{R}$, $f(x) = x^2$ fonksiyonudur. Burada okun iki yanına tanım ve değer kümesi yazılır. Görüntü kümesi ise negatif olmayan sayılardır, dolayısıyla değer kümesinden daha küçüktür. Genelde fonksiyon tanımında değer kümesi yazılır. Görüntü kümesini tam olarak yazmak, fonksiyona bağlı olarak daha zor olabilir.

> **Ders sonrası not:** Hoca $x^2$'nin görüntü kümesine "pozitif sayılar" dedi. Doğrusu $[0, \infty)$'dur, çünkü $0^2 = 0$ olduğundan $0$ da görüntü kümesindedir.

### 2.1 Birebir Fonksiyonlar ve Ters Fonksiyon

Birebir (one-to-one) fonksiyon, tanım kümesinin her elemanını görüntü kümesinin farklı bir elemanına götürür. Tanım kümesindeki iki farklı eleman aynı elemana gidiyorsa fonksiyon birebir değildir.

Bu koşulun sebebi terse çevrilebilirliktir. Birebir fonksiyonlara terslenebilir (invertible) de denir. Fonksiyon normalde tanım kümesinden görüntü kümesine gider. Ters fonksiyon ise ilk fonksiyonun görüntü kümesinden tanım kümesine geri döner. Fonksiyon birebir değilse, görüntü kümesinde iki farklı elemana geri gönderilmesi gereken elemanlar olur. Bir eleman iki farklı elemana giderse bu eşleme fonksiyon olmaz. Ters eşleme fonksiyon olmadığı için bu tür fonksiyonlara birebir değil ya da terslenemez deriz.

> **Ders sonrası not:** Hoca bu kısımda birkaç kez "birebir kümeler" ve "terslenebilir kümeler" dedi. Terslenen ve birebir olan şey fonksiyondur, küme değil.

## 3. Sayılabilir ve Sayılamaz Kümeler

### 3.1 Eleman Sayısı, Sonlu ve Sonsuz Kümeler

Sayılabilirliği tanımlamadan önce kümenin eleman sayısı (cardinality) gerekir. $A$ kümesinin eleman sayısı $|A|$ ile gösterilir. Üç elemanlı bir kümenin eleman sayısı $3$'tür.

<!-- BELİRSİZ: Hocanın tahtaya yazdığı üç elemanlı küme altyazıda "one a two" diye geçiyor, küme tam okunmuyor. Sonuç (3) net. -->

Eleman sayısı sonsuzdan küçük olan kümeye sonlu küme denir. Örneğin 10 ya da 11 elemanlı bir küme sonludur. Sonsuz kümenin ise sonsuz sayıda elemanı vardır. Örneği doğal sayılardır: $1, 2, 3, \dots$ diye sonsuza kadar gider.

### 3.2 Sayılabilir Küme

Bir $A$ kümesi şu iki durumdan birinde sayılabilirdir (countable):

- $A$ sonludur. Örneğin $A = \{2, 3, 4\}$.
- $A$'nın elemanları bir dizi hâlinde numaralandırılabilir (enumerate), yani $a_1, a_2, a_3, \dots$ diye sıralanabilir.

Numaralandırmak demek birinci eleman, ikinci eleman, üçüncü eleman diye listelemektir. Hoca "enumerate" için Türkçede "numaralandırmak" diyebileceğimizi, "countable" için de "sayılabilir" dendiğini söyledi. Doğal sayılar $1, 2, 3, 4, \dots$ diye numaralandırılabildiği için sayılabilirdir.

### 3.3 Sayılamaz Küme ve Reel Sayılar

Sayılabilir olmayan kümeye sayılamaz (uncountable) küme denir. Hocanın örneği reel sayılardır. İlk reel sayı nedir, bunu bilmiyoruz. Diyelim ki $1.0$'dan başladık. Peki sıradaki reel sayı hangisi? $1.1$ dersek olmaz, çünkü $1$ ile $1.1$ arasında $1.05$ vardır. $1$ ile $1.05$ arasında da başka bir sayı vardır, onlarla $1$ arasında da başka bir sayı. Hoca bu yüzden reel sayıları numaralandıramayacağımızı söyledi.

> **Ders sonrası not:** Bu akıl yürütme sezgi verir ama tek başına ispat değildir. "İki sayı arasında her zaman başka bir sayı vardır" özelliği rasyonel sayılarda da geçerlidir ($1$, $1.1$ ve $1.05$ üçü de rasyoneldir), oysa az sonra göreceğimiz gibi $\mathbb{Q}$ sayılabilirdir. Sonraki elemanı bulamamak yalnız doğal büyüklük sırasıyla sayamadığımızı gösterir, başka bir sırayla sayılamayacağını göstermez. $\mathbb{R}$'nin sayılamazlığının asıl ispatı büyük olasılıkla Cantor'un köşegen yöntemiyle yapılır; bu ispat derste verilmedi.

### 3.4 Sayılabilir Kümelere Örnekler

Hoca "başka neler sayılabilir?" diye sorarak örnekleri sıraladı. $\{2, 3, 4\}$ sonlu olduğu için sayılabilirdir. Doğal sayılar sayılabilirdir. Tam sayılar da sayılabilirdir: $0$'dan başlayıp $1, -1, 2, -2, \dots$ diye gidersek bütün elemanları sayabiliriz. Bu örneğe öğrenci sorusuyla Bölüm 6'da yeniden dönülüyor.

### 3.5 Rasyonel Sayılar Sayılabilir

Hoca şaşırtıcı bulduğu sonucu verdi: Rasyonel sayılar da sayılabilirdir. $\frac{3}{2}$ ya da $\frac{4}{5}$ gibi sayıların hepsi numaralandırılabilir. Rasyonel sayı $\frac{a}{b}$ biçimindedir. Pay tam sayılardan, payda doğal sayılardan gelir, ikisi de sayılabilir kümelerdir. Bu yüzden sonucun sayılabilir olmasını bekleriz. Fakat bu yalnızca bir beklentidir, asıl argüman aşağıdaki tablodur.

> **Ders sonrası not:** Hoca pay için "nominator" dedi. Pay'ın İngilizcesi büyük olasılıkla "numerator"dür; kitaplarda bu sözcükle karşılaşırsınız.

Önce yalnız pozitifleri düşünelim. Negatifleri sonra ekleyeceğiz. Tablonun üstüne olası payları ($1, 2, 3, \dots$), yanına olası paydaları ($1, 2, 3, \dots$) yazalım. Kesişim hücrelerine ilgili rasyonel sayıyı yazalım:

| payda / pay | 1 | 2 | 3 | ... |
|---|---|---|---|---|
| 1 | 1/1 | 2/1 | 3/1 | ... |
| 2 | 1/2 | 2/2 | 3/2 | ... |
| 3 | 1/3 | 2/3 | 3/3 | ... |
| ... | ... | ... | ... | ... |

Birinci satırı bitirip ikinciye geçmeye çalışırsak sorun çıkar, çünkü paylar sonsuz olduğundan birinci satır hiç bitmez. Hocanın "güzel numara" dediği çözüm şudur: Önce satırı değil, köşegeni bitirmek. Sıra şöyle ilerler:

$$\frac{1}{1},\ \frac{2}{1},\ \frac{1}{2},\ \frac{1}{3},\ \frac{2}{2},\ \frac{3}{1},\ \dots$$

Her köşegen sonlu olduğu için her köşegen biter ve sıra bir sonrakine geçer. Tablodaki her hücreye sonlu adımda ulaşılır (python ile payı ve paydası 20'ye kadar olan bütün hücreler için bu sıra denendi). Böylece rasyonel sayıları numaralandırmış oluruz. Negatifler için de her pozitif sayının hemen arkasına negatifini yazmak yeterlidir.

> **Ders sonrası not:** Köşegen sayımında $\frac{2}{2} = \frac{1}{1}$ gibi tekrarlar çıkar. Daha önce sayılmış değerler atlanır, sonuç değişmez. Ayrıca tablo $0$'ı içermez, ama $0$ dizinin en başına yazılarak eklenebilir.

### 3.6 Sayılabilir Sonsuz Kümeler

Bazen "sayılabilir sonsuz" (countably infinite) adı kullanılır. Bu yalnızca kümenin hem sayılabilir hem de sonsuz olduğu anlamına gelir. Doğal sayılar böyle bir kümedir.

## 4. Kapsayan Kümeler ve Bölüntü

Hoca kümeleri bitirmeden önce söylemeyi unuttuğu bir kavramı daha ekledi. Birleşimleri evrensel kümeye eşit olan kümelere kapsayan (exhaustive) kümeler denir. Örneğin $A \cup B \cup C \cup D$ evrensel küme ise $A, B, C, D$ kapsayandır.

Bu tanım bölüntüye benzer. İkisinde de kümelerin birleşimi evrensel kümeyi verir. Fark, kesişimlerdedir:

- **Bölüntü:** Kümeler arasında kesişim olamaz.
- **Kapsayan kümeler:** Bazı kümelerin kesişmesine izin verilir.

Hoca iki durumu yan yana çizdi: $A_1, \dots, A_4$ birbirine değmeden bütün alanı dolduruyorsa bölüntü, bazıları üst üste biniyorsa ama yine bütün alanı dolduruyorsa kapsayan kümelerdir.

## 5. Kuvvet Kümesi

Kümeler konusunun son kavramı kuvvet kümesidir (power set). Bir kümenin kuvvet kümesi, o kümenin bütün alt kümelerinin kümesidir. Kuvvet kümesini yazmak için önce tek elemanlı alt kümeler, sonra iki elemanlılar, sonra daha çok elemanlılar listelenir. Listelemenin sonunda bütün alt kümeler elde edilir.

Kuvvet kümesi her zaman boş kümeyi ve kümenin kendisini içerir. Eleman sayısı $2^{|A|}$'dır.

Hocanın örneği $A = \{1, 2\}$ kümesidir:

- Verilen: $|A| = 2$.
- Alt kümeler: $\emptyset$, $\{1\}$, $\{2\}$, $\{1, 2\}$ (liste kısa nottan; altyazıda hoca yalnız birer birer saydı).
- Sonuç: $|\mathcal{P}(A)| = 2^2 = 4$. Bu, listedeki dört kümeyle uyuşur.

## 6. Chat Sorusu: Tam Sayılar Gerçekten Sayılabilir mi?

Hoca arayı vermek üzereyken chat'ten bir soru geldi.

**Soru:** Tam sayılar eksi sonsuzdan artı sonsuza gidiyor. Yine de sayılabilir mi?

**Cevap:** Evet, sayılabilir. Sayılabilir olmak için doğal sayılarla birebir eşleme kurabilmek, yani "birinci eleman budur, ikinci eleman budur" diyebilmek gerekir. Başlangıç noktası önemli değildir, herhangi bir yerden başlayabiliriz. $0$'ı birinci eleman, $1$'i ikinci eleman seçelim. Sağa doğru $2, 3, 4, \dots$ diye devam edersek saymayı hiç bitiremeyiz ve negatiflere hiç sıra gelmez. İlk bakışta küme sayılamaz gibi görünür. Fakat elemanları doğal sıralarında saymak zorunda değiliz, sayma sırasını değiştirebiliriz:

| Sıra | 1. | 2. | 3. | 4. | 5. | ... |
|---|---|---|---|---|---|---|
| Eleman | $0$ | $1$ | $-1$ | $2$ | $-2$ | ... |

Bu sırada hiçbir eleman atlanmaz. Sonsuz zamanımız olsa bütün elemanları sayabilirdik. Bu yüzden tam sayılar sayılabilirdir.

Bu sırada hoca, chat'te bir öğrencinin "partition" yazdığını gördü. Kapsayan kümeler ile bölüntü farkının biraz önce anlatıldığını belirtip soruyu öğrenciye açtı, ek bir akademik içerik gelmedi.

<!-- BELİRSİZ: 00:52 civarında partition sorusunun içeriği altyazıda net değil. -->

## 7. Olasılık Teorisine Giriş: Deney, Çıktı, Olay, Örneklem Uzayı

Aradan sonra olasılık teorisine geçildi. Hoca, kümelerin bu yüzden önemli olduğunu söyledi: Olasılıkları kümeler üzerinde tanımlayacağız.

### 7.1 Rastgele Deney

Rastgele deney (random experiment), sonucu kesin olarak tahmin edilemeyen bir olgudur. Baron kitabında yalnızca "deney" (experiment), Pishro-Nik "rastgele deney" der. Örnekler: zar atmak, zarı üç kez atmak, para atmak.

> **Ders sonrası not:** Hoca önce sözlü olarak "belirsizlikle tahmin edilemeyen" (with uncertainty) dedi. Hemen ardından tahtaya doğrusunu yazdı: "kesin olarak tahmin edilemeyen" (with certainty).

### 7.2 Çıktı

Çıktı (outcome), deneyin sonucudur. Zar atıldığında çıktı örneğin $2$ ya da $3$ olabilir. Zar üç kez atılırsa üç değer birlikte bir çıktıdır, örneğin $2, 1, 6$. Para atıldığında iki çıktı vardır: yazı ya da tura.

### 7.3 Olay

Olay (event), çıktılardan oluşan bir kümedir. Birden fazla çıktıyı toplayıp onlardan birlikte, kolayca söz etmemizi sağlar. Deneyimiz zar atmak olsun ve olayımız "sonucun tek sayı gelmesi" olsun. Bu olaya $E$ diyelim. $E$, olası tek çıktılardan oluşur:

$$E = \{1, 3, 5\}$$

Olaylar her zaman kümedir. "Sonucun $1$ gelmesi olayı" dediğimizde de bir kümeden söz ederiz, yalnızca bu kümenin tek elemanı vardır: $\{1\}$.

### 7.4 Örneklem Uzayı

Örneklem uzayı (sample space), bir deneyin bütün olası çıktılarının kümesidir. Baron'da $\Omega$, Pishro-Nik'te $S$ ile gösterilir. Altı yüzlü zar için:

$$\Omega = \{1, 2, 3, 4, 5, 6\}$$

Deney değişince örneklem uzayı da değişir. Üç zar atarsak ya da bir zarı üç kez atarsak (hoca bunun fark etmediğini söyledi) çıktılar artık üçlülerdir: birinci atışın sonucu, ikinci atışın sonucu ve üçüncü atışın sonucu. $(1, 3, 4)$ bir çıktıdır, $(1, 3, 5)$ başka bir çıktıdır. Örneklem uzayı bütün olası üçlülerin kümesidir. Hoca bunları saymayı daha sonra göreceğimizi, biraz sabırlı olmamız gerektiğini söyledi.

<!-- BELİRSİZ: 01:16-01:17:39 arasında bir öğrenci sözü kesip üç zar atma durumuyla ilgili bir şey söylüyor, altyazı bozuk. Sorunun içeriği çıkarılamadı. Hocanın anlatımı "üçlüler" ile devam ediyor. -->

### 7.5 Her Yerde Kümeler

Rastgele deneyde kümeleri her yerde görürüz:

- Olay bir kümedir.
- Örneklem uzayı evrensel kümedir.
- Çıktı, evrensel kümenin ya da söz ettiğimiz olayın bir elemanıdır.

### 7.6 Bir Olayın Gerçekleşmesi

Deneyin sonucu bir olayın içindeyse o olay gerçekleşti (occurred) deriz. $E = \{1, 3, 5\}$ olsun ve zarı atalım. Çıktı $1$ ise $E$ gerçekleşmiştir. $3$ ya da $5$ gelseydi de $E$ gerçekleşecekti. Yani bir olayın gerçekleşmesinin birden fazla yolu olabilir: Olayın herhangi bir elemanı çıktı olursa olay gerçekleşir.

### 7.7 Küme Dili Olaylara Aynen Taşınır

Kümeler üzerine epey zaman harcamamızın sebebi budur.

> **Hocanın vurgusu:** Olaylar sadece kümedir. Kümelerde öğrendiğimiz her şey olaylar için de geçerlidir. Birleşim, kesişim, kapsayan kümeler gibi kavramların yanına "olay" sözcüğünü koyup olayların birleşiminden, kesişiminden, kapsayan olaylardan söz edebiliriz.

Örneğin $E_1, E_2, E_3, E_4$ olaylarının örneklem uzayının bir bölüntüsü olması için iki koşul gerekir:

$$E_1 \cup E_2 \cup E_3 \cup E_4 = \Omega, \qquad E_i \cap E_j = \emptyset \quad (\text{her } i \neq j \text{ için})$$

Hoca burada özel bir şey olmadığını, kümelerde söylediğimizin aynısını söylediğimizi belirtti.

## 8. Olasılık Nedir? Fonksiyon Olarak Olasılık ve İki Yorum

Olasılık olaylar üzerine kurulur. Olasılık, bir olayı alıp ona bir sayı veren bir fonksiyondur. Bu değere $A$'nın olasılığı denir ve $P(A)$ ile gösterilir.

Peki bu sayının sezgisel anlamı nedir? Hoca iki yorum olduğunu hatırlattı.

### 8.1 Frekans Yorumu

Her olay bir deneyden gelir. Frekansçı (frequentist) yorumda deney çok sayıda tekrarlanır. Olayın gözlendiği denemelerin oranı, o olayın olasılığıdır.

### 8.2 İnanç Yorumu

İkinci yoruma bazen Bayesçi (Bayesian) yorum denir. Burada olasılık bir inançtır (belief). Bu düşünce genellikle deneyi tekrar edemediğimiz durumlarda kullanılır.

Hocanın örneği şudur: Ayşe adlı bir öğrencinin üniversite sınavını kazanma olasılığı nedir? Ayşe bu sınava hayatında büyük olasılıkla bir kez girecek. Bu durumda olasılığı, Ayşe'nin kazanacağına dair bir inanç olarak düşünmeyi tercih edebiliriz.

Bu derste çoğunlukla frekans yorumu kullanılacak.

**Soru:** Buradaki "interpretation" Türkçede "yorum" anlamında mı?

**Cevap:** Evet. "Bayes interpretation", Bayes'in yorumu demektir.

## 9. Olasılık Aksiyomları

### 9.1 Her Fonksiyon Olasılık Olamaz

Olasılığın bir fonksiyon olduğunu gördük, ama her fonksiyon olasılık için uygun değildir. Bir fonksiyon $P(A) = \frac{3}{2}$ veriyorsa bu $P$ bir olasılık fonksiyonu değildir. Bir fonksiyonun olasılık ölçüsü (probability measure) olması için bazı kurallara uyması gerekir. Bu kurallara aksiyom denir.

### 9.2 Üç Aksiyom

Olasılık ölçüsü, örneklem uzayındaki olayları reel sayılara götüren bir fonksiyondur. Genelde $P$ ile gösterilir, ama bazı kitaplarda başka bir harf olabilir; $P$ olmak zorunda değildir. Bu fonksiyon şu üç aksiyomu sağlar:

- **Aksiyom 1:** Her $A$ olayı için $P(A) \ge 0$. Yani olasılık negatif olamaz.
- **Aksiyom 2:** $P(\Omega) = 1$. Hoca bunu, deneydeki bütün elemanların olasılıklarını sayarsak toplamın $1$'e ulaşması gerektiği diye açıkladı.
- **Aksiyom 3:** Ayrık olaylardan oluşan sayılabilir bir $A_1, A_2, \dots$ topluluğu için birleşimin olasılığı tek tek olasılıkların toplamıdır:

$$P(A_1 \cup A_2 \cup \dots) = P(A_1) + P(A_2) + \dots$$

> **Ders sonrası not:** Hoca tahtaya topluluğu $A_1$'den $A_n$'ye kadar yazdı, ama sözlü olarak "sayılabilir topluluk" dedi. Bölüm 3'teki tanıma göre sayılabilir bir topluluk sonsuz da olabilir, bu yüzden aksiyomu sonsuz dizi $A_1, A_2, A_3, \dots$ için de okumak gerekir. Sonlu durum bunun özel hâlidir. Ayrıca Aksiyom 2 için verilen "elemanların olasılıklarını topla" sezgisi, Aksiyom 3'ün gereği olarak çıktıları tek tek sayabildiğimiz uzaylarda doğrudur.

### 9.3 Aksiyomlar Neden Önemli?

> **Hocanın vurgusu:** Aksiyomlar çok önemlidir. Bunun iki nedeni vardır.

Birinci neden: Olasılıkla ilgili bundan sonra göreceğimiz bütün kurallar bu üç aksiyomdan elde edilir. Elimizde önce aksiyomlar, sonra diğer olasılık kuralları vardır. Her kuralı derste ispatlamayabiliriz, ama her kural bu üçünden ispatlanabilir.

İkinci neden: Bu kurallara uyan her fonksiyon bir olasılık ölçüsü tanımlar. Dolayısıyla bu derste öğreneceğimiz bütün kurallar o fonksiyon için de geçerli olur.

Hocanın örneği koşullu olasılıktır (conditional probability). Birazdan şu kuralı öğreneceğiz:

$$P(A^c) = 1 - P(A)$$

Koşullu olasılık da bir olasılık ölçüsü olduğu için, başka hiçbir şey yapmadan şunu yazabiliriz:

$$P(A^c \mid B) = 1 - P(A \mid B)$$

Birinci kuralı öğreneceğiz. İkincisini ise ayrıca öğrenmemize gerek yok, doğrudan biliyor olacağız. Çünkü koşullu olasılığın aksiyomlara uyduğunu biliyoruz.

> **Hocanın vurgusu:** Bir fonksiyon aksiyomlara uyuyorsa, bu derste geliştireceğimiz bütün kurallar ve araçlar o fonksiyona uygulanabilir. Bu çok önemlidir.

## 10. Aradaki Soru: Koşullu Olasılık Sezgisi

Ara başlarken koşullu olasılık örneğiyle ilgili bir soru geldi. Altyazı bu kısımda bozuk. Okunabildiği kadarıyla hoca, asıl anlatmak istediğinin şu olduğunu söyledi: Elinizde olasılık ölçüsü olan bir fonksiyon varsa, öğrendiğiniz kurallar ona da uygulanır.

Hoca gösterimi de Türkçe okudu. $P(A \mid B)$'deki dik çubuk, "$B$ olduysa $A$'nın olma olasılığı" demektir. Örneği şuydu: $B$ "yola vaktinde çıkmak", $A$ "gideceğiniz yere vaktinde varmak" olsun. $P(A \mid B)$, yola vaktinde çıktıysanız gideceğiniz yere vaktinde varma olasılığıdır.

<!-- BELİRSİZ: 01:45:59-01:49:26 arası altyazı büyük ölçüde bozuk. Sorunun tam metni ve hocanın örnekten sonraki açıklaması okunmuyor. Yalnız dik çubuğun okunuşu ve yola çıkma örneği net. -->

## 11. Olasılık Hesaplamak: Eşit Olasılıklı Çıktılar

Hoca son bölüme yeni bir soruyla başladı: Olasılıkları nasıl hesaplayacağız? Elimizde aksiyomlar var, onlara bakalım. $P(A) \ge 0$ bize hesap için bir şey vermez. $P(\Omega) = 1$ işe yarayabilir. Aksiyom 3 ise ayrık kümeler için toplama imkânı verir. Bu son ikisi birlikte bize bir araç sağlar.

> **Ders sonrası not:** Hoca bu tekrarda Aksiyom 1'i "sıfırdan büyük" diye okudu. Doğrusu "sıfırdan büyük veya eşit"tir, $P(A) \ge 0$.

### 11.1 Her Çıktının Olasılığı

Çok yardımcı olan bir durum, çıktıların eşit olasılıklı (equally likely) olmasıdır. Örnek hilesiz zardır. Zar hilesiz olduğu için:

$$P(1) = P(2) = P(3) = P(4) = P(5) = P(6)$$

Örneklem uzayı $\Omega = \{1, 2, 3, 4, 5, 6\}$, altı elemanlıdır. Her birinin olasılığı $\frac{1}{6}$ çıkar. Burada Aksiyom 2 ve Aksiyom 3 birlikte kullanılır. Hoca bunu "bütün olasılık olan $1$'i altı parçaya bölüp her çıktıya bir parça veriyoruz" diye anlattı:

- Verilen: Çıktılar ayrıktır ve birleşimleri $\Omega$'dır, olasılıkları eşittir. Ortak değere $p$ diyelim (ara adım eklendi).
- Aksiyom 3 ve Aksiyom 2: $P(1) + \dots + P(6) = P(\Omega) = 1$, yani $6p = 1$ (ara adım eklendi).
- Sonuç: $p = \frac{1}{6}$.

Genel olarak, bütün çıktılar eşit olasılıklıysa her çıktının olasılığı $\dfrac{1}{|\Omega|}$'dır.

Hoca iki gösterim ayrıntısına dikkat çekti. Çıktılar tanım gereği ayrıktır, aralarında kesişim yoktur. Ayrıca $P(1)$ yazdığımızda aslında tek elemanlı $\{1\}$ kümesinin olasılığından söz ederiz; yazmayı kolaylaştırmak için küme parantezlerini atlıyoruz.

### 11.2 Bir Olayın Olasılığı

Hilesiz zar atılsın ve $E$ "sonuç tek sayı" olayı olsun: $E = \{1, 3, 5\}$. $E$, elemanlarının birleşimi olarak yazılabilir ve bu elemanlar birbirinden ayrıktır. Aksiyom 3 doğrudan uygulanır:

$$P(E) = P(1) + P(3) + P(5) = \frac{1}{6} + \frac{1}{6} + \frac{1}{6} = \frac{3}{6}$$

> **Ders sonrası not:** Altyazıda hoca bu toplamı "$P(1)$ artı $P(2)$ artı $P(3)$" diye okuyor. $E = \{1, 3, 5\}$ olduğu için doğrusu $P(1) + P(3) + P(5)$'tir. Üç terim de $\frac{1}{6}$ olduğundan sonuç değişmez (python ile hesaplandı: $\frac{1}{2}$).

Hoca bu sayıların ne anlama geldiğini sordu. $6$, örneklem uzayındaki eleman sayısıdır. $3$, $E$ olayındaki eleman sayısıdır. Aksiyomlardan ve çıktıların eşit olasılıklı olmasından şu kural çıkar:

$$P(E) = \frac{|E|}{|\Omega|}$$

Çıktılar eşit olasılıklıysa, olaydaki eleman sayısını sayıp örneklem uzayındaki eleman sayısına böleriz. Olasılık budur. Bu kural yalnızca bu koşulda geçerlidir. Türkçe tekrarda hoca bunu "hileli bir zar olsaydı söyleyemeyebilirdik" diye açıkça belirtti.

## 12. Aksiyomlardan Türeyen Kurallar

Olasılık bulmanın başka yolları da vardır. Bunlar olasılık kurallarını oluşturur.

### 12.1 Tümleyen Kuralı

$P(A)$'yı bildiğimizi varsayalım. $P(A^c)$'yi nasıl buluruz? Venn diyagramında $A$ kümesi ve onun dışında kalan $A^c$ bölgesi örneklem uzayını doldurur. Yani:

$$A \cup A^c = \Omega, \qquad A \cap A^c = \emptyset$$

Bu ikisi tümleyenin tanımından gelir. Ayrık oldukları için Aksiyom 3 uygulanır:

$$P(A) + P(A^c) = P(\Omega)$$

Aksiyom 2'den $P(\Omega) = 1$'dir. $P(A^c)$'yi yalnız bırakırsak:

$$P(A^c) = 1 - P(A)$$

### 12.2 Boş Kümenin Olasılığı

$$P(\emptyset) = 0$$

Sezgisel olarak, hiç çıktısı olmayan bir kümenin gerçekleşme imkânı yoktur, olasılığı da sıfırdır. Ama biz bunu aksiyomlardan ispatlıyoruz. Boş kümede hiç eleman olmadığı için, onu bir kümeyle birleştirmek o kümeye hiçbir şey katmaz:

$$\emptyset \cup \Omega = \Omega, \qquad \emptyset \cap \Omega = \emptyset$$

Birleşimleri örneklem uzayıdır ve ayrıktırlar. Aksiyom 3 ve Aksiyom 2'yi uygulayınca:

$$P(\emptyset) + 1 = 1 \quad\Rightarrow\quad P(\emptyset) = 0$$

Hoca Türkçe tekrarda bu kısım için "en zoru bazen çok basit şeyleri ispat etmek oluyor" dedi.

### 12.3 Bir Olasılık 1'i Aşamaz

$$P(A) \le 1$$

Bu kuralı ispatlarken hocanın vurguladığı bir yöntem devreye girer.

> **Hocanın vurgusu:** Her şeyi yeniden aksiyomlardan ispatlamak zorunda değiliz. Bir kuralı bir kez ispatladıysak artık "alet çantamızda"dır. Onu sonraki ispatlarda ve hesaplarda kullanabiliriz. Matematikte ise ispatlayamadığınız bir şeyi normalde kullanamazsınız.

Tümleyen kuralını alet çantasına koymuştuk. $P(A^c)$'yi diğer tarafa geçirelim:

$$P(A) = 1 - P(A^c)$$

Aksiyom 1'e göre $P(A^c) \ge 0$'dır. Yani $1$'den sıfır veya daha büyük bir şey çıkarıyoruz, sonuç $1$ veya daha küçük olur. Hoca bunu iki duruma ayırarak da gösterdi:

- $P(A^c) = 0$ ise $P(A) = 1$.
- $P(A^c) > 0$ ise $P(A) < 1$.

İki durum birlikte $P(A) \le 1$ verir. Aksiyom 1 ile birleştirince hocanın Türkçe tekrarda özetlediği sonuç çıkar: Olasılıklar $0$ ile $1$ arasındadır, $0 \le P(A) \le 1$. Bunu kafadan söylemiyoruz, aksiyomlardan yola çıkarak ispatlıyoruz.

### 12.4 Fark Kuralı

Son kural biraz daha karmaşıktır:

$$P(A \setminus B) = P(A) - P(A \cap B)$$

Hoca bunun ispatını alıştırma olarak bıraktı ve bir ipucu verdi: $P(A \setminus B) = P(A \cap B^c)$. Bu ipucunu kullanmak zorunlu değil, ama yardımcı olabileceğini söyledi. Türkçe tekrarda Venn diyagramını gösterip $A$'nın iki parçadan oluştuğuna ve bu iki parçanın toplamının $A$'yı verdiğine dikkat çekti.

> **Ek bilgi (derste anlatılmadı):** İspat hocanın bu ipucuyla kurulabilir. $A = (A \cap B) \cup (A \cap B^c)$ yazılır ve bu iki parça ayrıktır. Aksiyom 3'ten $P(A) = P(A \cap B) + P(A \cap B^c)$ olur. $A \cap B^c = A \setminus B$ olduğu için $P(A \setminus B) = P(A) - P(A \cap B)$ elde edilir.

## 13. Dersin Sonundaki Türkçe Tekrar

Bir öğrencinin isteği üzerine hoca son bölümü kısaca Türkçe özetledi. Bu kısmın altyazısı büyük ölçüde bozuk. Yukarıdaki bölümlerde yer almayan, okunabilen kısımlar şunlardır.

<!-- BELİRSİZ: 02:26:36-02:33:03, 02:44:17-02:46:11 ve 02:47:08-02:50:29 aralıkları büyük ölçüde okunmuyor. Bu aralıklardaki konuşma Türkçe olduğu hâlde İngilizce çevrilmiş ve anlamsız tekrarlara dönüşmüş. -->

Hoca işe neden araçlara ihtiyaç olduğunu söyleyerek başladı. Bir olayın olasılığını $0.2$ ya da $0.3$ diye belirlemek istiyoruz, bunun için elimizde kurallar olmalı. Okunabildiği kadarıyla burada toplamı $1$ olan olasılıklardan bir sayısal örnek daha verdi.

<!-- BELİRSİZ: 02:29:13-02:29:25 arasında "0.05" ve bozuk biçimde "0.95" ile "bunun toplamı 1" seçiliyor. Örneğin deneyi ve olayları okunmuyor, bu yüzden örnek çözülmedi. -->

Ardından üç aksiyomu tekrarladı ve eşit olasılıklı çıktılar kuralına geçti: Çıktılar eşit olasılıklıysa ve ayrıksa, olasılıklarının toplamı $1$ olduğundan her çıktının olasılığı bir bölü örneklem uzayının eleman sayısıdır. Altı yüzlü hilesiz bir zarı attığınızda her yüzün gelme olasılığı $\frac{1}{6}$'dır, çünkü toplam eleman sayısı $6$'dır.

**Soru:** Bir öğrenci kendi anladığını özetledi: Birinci aksiyom sıfırdan büyük olmak, yani $\frac{1}{6}$. İkinci aksiyom altı tane $\frac{1}{6}$'nın toplamının $1$ olması. Üçüncü aksiyom da toplamın doğrudan $1$ vermesi. Doğru mu?

**Cevap:** Evet. Bu üçünü kullanarak basit dört işlem mantığıyla sonuca ulaştık. Bunu herhangi birine söyleseniz "ne anlatıyorsun, zaten öyle" der. Ama dersimiz matematik olduğu için aksiyomlardan yola çıkıp ispatlı ispatlı gidiyoruz, olayın mantığını yerleştirmeye çalışıyoruz.

> **Ders sonrası not:** Öğrencinin özetindeki üçüncü madde tam değildir. "Toplamın $1$ olması" Aksiyom 2'nin katkısıdır. Aksiyom 3, ayrık olayların birleşiminin olasılığının tek tek olasılıkların toplamı olduğunu söyler.

**Soru:** Bunun hemen altındaki kısım tek sayılar mı?

**Cevap:** Evet. Artık tek çıktılardan değil, birden fazla çıktı içeren olaylardan söz ediyoruz. Zarın tek gelmesi olayı $1$, $3$ ya da $5$ gelirse gerçekleşir. Bu yüzden olayı tek tek çıktıların birleşimi olarak yazabiliriz. Üçüncü aksiyom, kesişim yoksa birleşimin olasılığının tek tek olasılıkların toplamı olduğunu söyler. Hoca bu cümlenin dolu dolu olduğunu, kâğıt kalemle bakmanın yardımcı olacağını ekledi. Sonuç olarak olayın olasılığı çıktılarının olasılıkları toplamıdır.

Eşit olasılık kuralının koşulunu yineledi: Örneklem uzayındaki bütün çıktılar eşit olasılıklı olmalı. Zar atma, para atma gibi durumlarda kural doğrudan kullanılabilir. Böylece elimizde dört araç olmuş oldu: üç aksiyom ve bu kural.

**Soru:** Bu kısım yalnızca $P(A^c) = 1 - P(A)$'yı mı ispatlıyor?

**Cevap:** Evet. Hoca bunu doğrudan yazdırabileceğini, ama hem ispatı görmenin hoş olacağını hem de aksiyomların nasıl uygulandığının görülebileceğini söyledi. $A$ ile tümleyeninin ayrık olması ve birleşimlerinin örneklem uzayı olması, tümleyenin tanımından gelir. Bu ikisini görünce Aksiyom 3 kullanılabilir.

Burada hoca bir de gösterim düzeltmesi yaptı. Tahtada $S$ yazmıştı, ama örneklem uzayı için genelde Baron'un notasyonunu kullandığını söyleyip işareti ona çevirdi.

**Soru:** $P$'nin içindeki boş süslü parantezler ne demek?

**Cevap:** Boş küme demek. Boş küme bu biçimde de yazılabilir.

Hoca evrensel küme ile örneklem uzayı terimlerini de ayırdı. Olasılıktan söz ederken "örneklem uzayı" demek daha doğrudur. "Evrensel küme" daha geniş bir terimdir, olasılığın olmadığı durumlarda da kullanılır. Hoca, derste ikisini de söylese ne kastedildiğinin anlaşılacağını belirtti.

$P(A) \le 1$ ispatını da aynı biçimde tekrarladı: $P(A) = 1 - P(A^c)$ ve $P(A^c)$, Aksiyom 1 gereği ya sıfırdır ya da sıfırdan büyüktür. Sıfırsa $P(A) = 1$, sıfırdan büyükse $P(A) < 1$ çıkar.

## Dersin Toparlaması

Bu ders kümeler konusunu kapattı ve olasılık teorisini aksiyomatik olarak açtı. Küme tarafında fark için $A \setminus B = A \cap B^c$ kuralı, sayılabilir ve sayılamaz kümeler, sayılabilir sonsuz kümeler, kapsayan kümelerin bölüntüden farkı ve kuvvet kümesi görüldü. Tam sayıların ve rasyonel sayıların sayılabilirliği, sayma sırasını akıllıca seçmekle gösterildi. Olasılık tarafında deney, çıktı, olay ve örneklem uzayı tanımlandı. Olaylar küme olduğu için küme dilinin aynen taşındığı görüldü. Olasılığın frekans ve inanç yorumlarından sonra üç aksiyom verildi.

Bu üç aksiyomdan eşit olasılıklı çıktılar için $P(E) = |E| / |\Omega|$, ardından $P(A^c) = 1 - P(A)$, $P(\emptyset) = 0$ ve $P(A) \le 1$ türetildi. $P(A \setminus B) = P(A) - P(A \cap B)$ kuralının ispatı alıştırma olarak kaldı. Dersin ana fikri şudur: Aksiyomlara uyan her fonksiyon bir olasılık ölçüsüdür ve geliştirilen bütün araçlar ona da uygulanır. Hoca bunu ileride görülecek koşullu olasılıkla örnekledi. Örneklem uzayındaki çıktıları saymaya da daha sonra dönülecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
