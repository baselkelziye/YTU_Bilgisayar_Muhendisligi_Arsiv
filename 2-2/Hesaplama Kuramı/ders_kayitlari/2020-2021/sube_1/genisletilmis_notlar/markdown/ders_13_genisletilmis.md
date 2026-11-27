# Ders 13 Genişletilmiş Notu: Turing Makinesi Çeşitleri, Karar Verilebilir Diller ve Zaman Karmaşıklığı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Yerinde Kalma Seçenekli (Stay-Option) Turing Makineleri
- 2. Çok İzli Şerit
- 3. Yarı Sonsuz Şerit
- 4. Çok Şeritli Turing Makineleri
- 5. Çok Boyutlu Şerit
- 6. Belirlenimci Olmayan Turing Makineleri
- 7. Turing'le Kabul Edilebilir ve Karar Verilebilir Diller
- 8. Karar Verilebilir Problem Örnekleri
- 9. Karar Verilebilir Dilin Tümleyeni
- 10. Karar Verilemeyen Bir Dil: Köşegen Yöntemi
- 11. Zaman Karmaşıklığı, P ve NP
- Örnek Sorular

Ders büyük ölçüde İngilizce anlatıldı; hoca yer yer Türkçe açıklamalar yaptı. Anlatım tablette açılan hazır slaytlar üzerinden ilerledi: önce önceki derste başlanan "Turing makinesi çeşitleri" slaytları bitirildi, aradan sonra karar verilebilir dillere, ikinci aradan sonra da kısaca zaman karmaşıklığına geçildi. Altyazının birçok yeri Whisper tarafından bozulduğu için slaytlarda kalan ama sözlü anlatımı anlaşılmayan yerler işaretlendi.

## 1. Yerinde Kalma Seçenekli (Stay-Option) Turing Makineleri

Standart Turing makinesinde kafa her adımda bir hücre sola (L) ya da sağa (R) gider. Stay-option makinesinde bunlara ek olarak kafa yerinde de kalabilir (S, stay). Makinenin adı bu ek seçenekten gelir.

**Teorem:** Stay-option makineleri standart Turing makineleriyle aynı güce sahiptir (ekrandan, 00:05:00).

Hoca, iki makine türünün "aynı güçte" olduğunu göstermek için her zaman iki durum incelenmesi gerektiğini vurguladı:

- Stay-option makineleri standart Turing makinelerini taklit eder (simulate). Bu doğruysa stay-option makinelerinin gücü en az standart makineler kadardır.
- Standart Turing makineleri stay-option makinelerini taklit eder. Bu doğruysa standart makinelerin gücü en az stay-option makineleri kadardır.

İkisi birlikte doğruysa güçler eşittir.

### 1.1 Birinci yön

Bu yön kolaydır: her standart Turing makinesi zaten bir stay-option makinesidir. Stay-option makinesi S hareketini hiç kullanmadan standart makinenin yaptığı her şeyi yapar.

### 1.2 İkinci yön: S hareketinin taklidi

Standart makinede S hareketi yoktur; bu yüzden onu iki hareketle taklit etmek gerekir: önce bir yöne, sonra geri. Hoca bunu "bir left ve bir right" diye özetledi.

Stay-option makinesindeki

$$q_1 \xrightarrow{a \to b,\,S} q_2$$

geçişi standart makinede şu iki geçişle yazılır:

$$q_1 \xrightarrow{a \to b,\,L} q_t \xrightarrow{x \to x,\,R} q_2$$

Burada $q_t$ geçici (temporary) bir durumdur, $x$ ise her olası şerit simgesini gösterir: ikinci adımda kafanın altında ne varsa değiştirilmeden yeniden yazılır ve kafa sağa döner. L ya da R içeren diğer geçişler (örneğin $q_1 \xrightarrow{a \to b,\,L} q_2$) olduğu gibi kalır.

### 1.3 Taklit örneği

Slayttaki örnekte şerit $\Diamond\, a\, a\, b\, a\, \Diamond$ ve makine $q_1$ durumunda ilk $a$'nın üzerindedir (ekrandan, 00:10:00).

- Stay-option makinesi: $a \to b, S$ ile ilk $a$ yerine $b$ yazılır, kafa yerinde kalır. Sonuç: $\Diamond\, b\, a\, b\, a\, \Diamond$, kafa aynı hücrede, durum $q_2$.
- Standart makine:
  - Adım 1: şerit $\Diamond\, a\, a\, b\, a\, \Diamond$, kafa ilk $a$'da, durum $q_1$.
  - Adım 2: $a \to b, L$ uygulanır; şerit $\Diamond\, b\, a\, b\, a\, \Diamond$, kafa soldaki $\Diamond$'da, durum geçici durum.
  - Adım 3: $x \to x, R$ uygulanır ($x = \Diamond$); şerit değişmez, kafa yeniden $b$'nin üzerinde, durum $q_2$.

İki makinenin son durumu aynıdır: aynı şerit, aynı kafa konumu, aynı durum (python ile kontrol edildi).

> **Ders sonrası not:** Slaytta adım 2'nin durumu $q_2$, adım 3'ün durumu $q_3$ yazılıydı. Hoca bunu derste düzeltti: adım 2'deki durum geçici bir durumdur, adım 3'te ulaşılan durum $q_2$ olmalıdır.

## 2. Çok İzli Şerit

Hoca bu bölümü "daha karmaşık taklitlerde işe yarayan bir hile" (a useful trick) olarak sundu (ekrandan, 00:15:00). Tek bir şerit vardır ama her hücre üst üste birkaç iz (track) taşır. Kafa tektir ve bir sütunun tamamını birden okur.

Slayttaki örnekte iz 1 $\Diamond\, \Diamond\, a\, b\, a\, b\, \Diamond$, iz 2 $\Diamond\, \Diamond\, b\, a\, c\, d\, \Diamond$ biçimindedir. Kafanın altındaki sütun tek bir simge gibi düşünülür: $(a,b)$. İki iz varsa sütun bir ikili (double), üç iz varsa bir üçlü (triple) simgedir. Böylece şerit alfabesi genişler ama makine yine standart bir Turing makinesidir.

Örneğin kafanın altında $(b,a)$ varsa ve geçiş bunu $(c,d)$ yapıp sola gidiyorsa geçiş

$$(b,a) \to (c,d),\ L$$

biçiminde yazılır: şeritte $b$ ile $a$'nın yerine $c$ ile $d$ gelir, kafa bir sütun sola gider. Bu yüzden çok izli şerit standart makineyi, standart makine de çok izli şeridi kolayca taklit eder.

## 3. Yarı Sonsuz Şerit

Yarı sonsuz (semi-infinite) şeritli makinede şerit yalnız sağa doğru sonsuzdur; solda şerit yoktur, yani bir başlangıç noktası vardır. Başlangıç konumu en soldaki hücredir. Kafa bu sol sınırdan sola gitmek isterse en soldaki konuma geri döner (yerinde kalır).

**Teorem:** Yarı sonsuz şeritli makineler standart Turing makineleriyle aynı güce sahiptir.

İspat yine iki yönlüdür.

### 3.1 Standart makine yarı sonsuz makineyi taklit eder

Standart makinenin şeridi iki yönde sonsuzdur; yarı sonsuz makinenin "sol duvarını" yapay olarak kurmak gerekir. Slayttaki iki değişiklik şunlardır (ekrandan, 00:20:00):

- a. Giriş dizgisinin soluna özel simge $\#$ konur. Bu simge yarı sonsuz şeridin başlangıcını gösterir. Örnek şerit: $\cdots\, \Diamond\, \Diamond\, \#\, a\, b\, a\, c\, \Diamond\, \Diamond \cdots$
- b. Her duruma $\# \to \#, R$ öz döngüsü eklenir (çıkışı olmayan durumlar hariç).

Böylece kafa ne zaman $\#$'nin üzerine gelirse $\#$'yi okur, aynısını yazar ve sağa döner. Bu, yarı sonsuz makinede kafanın sol sınırdan sola gidememesinin karşılığıdır. Hoca bu geçişlerin makinedeki her duruma konması gerektiğini özellikle belirtti.

### 3.2 Yarı sonsuz makine standart makineyi taklit eder

Bu yönde standart makinenin iki yöndeki sonsuzluğu tek yöne "sıkıştırılır". Yarı sonsuz şerit iki izli düşünülür:

- Üst iz (right part): standart şeridin sağ yarısı.
- Alt iz (left part): standart şeridin sol yarısı, başlangıç noktasından sola doğru sırayla.

Her iki izin en solunda $\#$ bulunur. Standart makinenin her durumu için yarı sonsuz makinede iki kopya vardır: kafa sağ yarıda çalışırken kullanılan $q^R$ ve sol yarıda çalışırken kullanılan $q^L$. Hoca bunu iki durumun sol ve sağ için "yansıması" diye anlattı. Sol yarıdaki kopyalarda hareket yönleri tersine döner, çünkü sol yarı ters sırada saklanmıştır.

Sınırda özel bir kontrol gerekir: kafa $\#$ sütununa geldiğinde $\#$ simgeleri birlikte okunur, birlikte yazılır, kafa sağa gider ve durum bir kopyadan öbürüne geçer. Bu geçişler de her duruma eklenir.

Slayttaki örnek (ekrandan, 00:25:00):

| Zaman | Üst iz (sağ yarı) | Alt iz (sol yarı) | Kafa ve durum |
|---|---|---|---|
| Time 1 | $\#\ d\ e\ \Diamond\ \Diamond\ \Diamond$ | $\#\ c\ b\ g\ \Diamond\ \Diamond$ | $\#$ sütununda, $q_1^L$ |
| Time 2 | $\#\ d\ e\ \Diamond\ \Diamond\ \Diamond$ | $\#\ c\ b\ g\ \Diamond\ \Diamond$ | birinci sütunda, $q_1^R$ |

Time 1'de makine sol kopyadadır ve kafa sınırdadır. Sınır geçişi uygulanınca şerit değişmez, kafa bir sütun sağa gider ve durum aynı durumun sağ kopyası $q_1^R$ olur. Artık kafa birinci sütunun üst izini, yani sağ yarının ilk simgesi $d$'yi okur.

> **Ek bilgi (derste anlatılmadı):** Bu örneğe karşılık gelen standart şerit büyük olasılıkla $\cdots\, g\, b\, c\, d\, e \cdots$ biçimindedir: sol yarı $c, b, g$ başlangıç noktasından sola doğru okunur. Standart makinede $c$'den sağa geçmek, katlanmış şeritte alt izde sola gidip $\#$'ye çarpmak ve sağ kopyaya geçerek $d$'ye ulaşmak demektir.

> **Hocanın vurgusu:** Hoca bu örneği "çok iyi bir örnek" olarak verdi ve yarı sonsuz makinelerin nasıl kullanıldığının anlaşılmasını istedi.

Hoca ayrıca iki izli yarı sonsuz şeritte sütunların yine ikili simgeler olarak düşünülebileceğini, yani bu yapının çok izli şerit hilesinin bir uygulaması olduğunu hatırlattı.

## 4. Çok Şeritli Turing Makineleri

Çok şeritli (multi-tape) makinede kontrol birimine bağlı birden çok şerit vardır ve her şeridin kendi kafası vardır. Giriş dizgisi şerit 1'dedir; şerit 2 başlangıçta boştur. Makine girişi okuyarak şerit 2'yi değiştirebilir, ya da şerit 2'ye göre şerit 1'i değiştirebilir.

Bir geçişte her şeritten bir simge okunur ve her şeride bir simge yazılır; her kafa kendi yönünde hareket eder. İki şeritli bir makinede örneğin $q_1$ durumunda kafa 1 $b$'yi, kafa 2 $f$'yi gösterirken bir geçişten sonra kafa 1 $a$'yı, kafa 2 $g$'yi gösterebilir. Okunan iki simge birlikte tek bir simge gibi düşünülebilir.

Hoca çok izli şerit ile çok şeritli makinenin farkını vurguladı: çok izli şeritte tek kafa vardır, çok şeritli makinede kafa sayısı birden fazladır ve her kafanın konumu önemlidir.

**Teorem:** Çok şeritli Turing makineleri standart Turing makineleriyle aynı güce sahiptir.

Yine iki yön vardır. Çok şeritli makine standart makineyi kolayca taklit eder (yalnız bir şeridi kullanır). Asıl iş, standart makinenin çok şeritli makineyi taklit etmesidir.

### 4.1 Standart makinede taklit

İki şeritli bir makine, dört izli tek şeritle gösterilir (ekrandan, 00:30:00):

| İz | İçerik |
|---|---|
| Şerit 1 | $\#\ a\ b\ c$ |
| Şerit 1 kafa konumu | $\#\ 0\ 1\ 0$ |
| Şerit 2 | $\#\ e\ f\ g\ h$ |
| Şerit 2 kafa konumu | $\#\ 0\ 0\ 1\ 0$ |

Kafa konumu izinde 1, o şeridin kafasının bulunduğu hücreyi gösterir; bu örnekte şerit 1'in kafası $b$'de, şerit 2'nin kafası $g$'dedir. Standart makine dört simgeyi (bir dörtlü simge) okuyup sola ya da sağa gider. En soldaki $\#$ sütunu referans noktasıdır.

Çok şeritli makinenin her geçişi için şu adımlar tekrarlanır:

- 1. Referans noktasına dön.
- 2. İz 1'de güncel simgeyi bul ve güncelle.
- 3. Referans noktasına dön.
- 4. Şerit 2'de güncel simgeyi bul ve güncelle.

<!-- BELİRSİZ: 00:30-00:31 arası altyazı bozuk; adımların sözlü açıklaması ve sonraki slayt anlaşılmıyor -->

### 4.2 Aynı güç, farklı hız

Hoca, makinelerin aynı dilleri tanıması ile aynı hızda tanıması arasındaki farkı bir örnekle gösterdi. $\{a^nb^n\}$ dili standart Turing makinesiyle tanınabilir; ama makine $a$'larla $b$'leri eşleştirmek için şerit üzerinde ileri geri gider ve süre yaklaşık $n^2$ ile artar. İki şeritli makinede ise $b^n$ kısmı şerit 2'ye kopyalanır ve şerit 1'deki $a^n$ ile karşılaştırılır.

<!-- BELİRSİZ: iki şeritli makinede sürenin hocanın söylediği değeri altyazıda kesik (00:32:30) -->

> **Ek bilgi (derste anlatılmadı):** İki şeritli yöntemde her iki kafa da şerit üzerinden yalnız birkaç kez geçtiği için süre büyük olasılıkla $n$ ile doğrusal artar. Bu, çok şeritli makinelerin daha güçlü değil, bazı dillerde yalnızca daha hızlı olduğunu gösterir.

## 5. Çok Boyutlu Şerit

Şerit iki, dört, on boyutlu olabilir; boyut sayısı ne olursa olsun güç değişmez. İki boyutlu makinede kafa sola, sağa, yukarı ve aşağı gidebilir. Kafanın konumu koordinatlarla verilir.

Slayttaki örnekte (ekrandan, 00:35:00) ızgarada üç simge vardır: $a$ ilk çeyrekte $(1, 1)$ konumunda, $b$ $(2, -1)$ konumunda, $c$ $(-1, 1)$ konumunda. Kafa $q_1$ durumunda $b$'yi göstermektedir. Hoca kafa konumunu "artı 2, eksi 1" diye okudu: $x$ ekseninde ikinci hücre, $y$ ekseninde $-1$.

Standart makinede taklit için iki izli bir şerit kullanılır: üst izde simgeler, alt izde her simgenin koordinatları yazılır ve koordinat çiftleri $\#$ ile ayrılır:

| Üst iz | $a$ | | | | $b$ | | | | | $c$ | | |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Alt iz | $1$ | $\#$ | $1$ | $\#$ | $2$ | $\#$ | $-$ | $1$ | $\#$ | $-$ | $1$ | |

<!-- BELİRSİZ: slayttaki koordinat izinin son hücreleri ve hocanın taklit adımlarına dair sözlü anlatımı altyazıda okunmuyor (00:34-00:35) -->

Hoca bu yapının standart makinelerin iki boyutlu makineleri taklit etmesi için kullanıldığını söyledi.

## 6. Belirlenimci Olmayan Turing Makineleri

Standart Turing makineleri belirlenimcidir (deterministic). Ama belirlenimcilik olmayan bir sürüm de tanımlanabilir: örneğin $q_1$ durumunda $a$ okunduğunda hem $a \to b, L$ hem $a \to c, R$ geçişi bulunabilir.

Belirlenimci bir makine bunu taklit etmek için her seçenekte şeridin bir kopyasını çıkarır. $q_1$'deyken bir seçimle $q_2$'ye geçilir ve şeridin bir hâli oluşur; öbür seçim için başka bir şerit kopyası gerekir. Hoca bunu "belirlenimci olmama şerit sayısının artmasına yol açar" diye özetledi.

Slayttaki taklit kuralları şöyle özetlenebilir:

- Belirlenimci olmayan makinenin o anki adımındaki her yapılandırma (configuration) için iki ya da daha fazla seçenek vardır; taklitte yapılandırma kopyalanır (replicate).
- Belirlenimci olmayan makine girişi kabul ederse, belirlenimci taklit de kabul eder ve durur. En kötü durumda taklit, kabul eden en kısa yolun uzunluğuna göre üstel zaman alır.
- Belirlenimci olmayan makine girişi kabul etmezse: tüm yollar durma durumuna ulaşırsa taklit durur; sonu gelmeyen bir yol (sonsuz döngü) varsa taklit hiç bitmez. Her iki durumda da belirlenimci makine girişi reddeder (durarak ya da sonsuz döngüyü taklit ederek).

Sonuç olarak belirlenimci olmayan Turing makineleri standart makinelerden daha güçlü değildir.

## 7. Turing'le Kabul Edilebilir ve Karar Verilebilir Diller

### 7.1 Turing'le kabul edilebilir diller

Önceki derslerden hatırlatma: bir $L$ dili, onu kabul eden (tanıyan) bir Turing makinesi $M$ varsa Turing'le kabul edilebilir (Turing-acceptable), Turing'le tanınabilir (Turing-recognizable) ya da özyinelemeli sayılabilir (recursively enumerable) dildir. Bu makinede:

- $w \in L$ ise $M$ bir kabul durumunda durur.
- $w \notin L$ ise $M$ kabul olmayan bir durumda durur ya da sonsuza dek döner (loops forever).

Hoca kilit noktanın bu "döngü" olasılığı olduğunu vurguladı.

### 7.2 Karar verilebilir diller

Bir $L$ dilini kabul eden ve **her** giriş dizgisinde duran bir Turing makinesi varsa $L$ karar verilebilir (decidable) bir dildir. Bu makineye karar verici (decider) denir. Karar vericide döngü yoktur: her giriş için hesaplama ya kabul ya da ret durumunda biter.

> **Hocanın vurgusu:** Karar verilebilir dilin tanımındaki anahtar "döngü yok" koşuludur. Hoca bunu art arda birkaç kez tekrarladı.

Gözlem: her karar verilebilir dil Turing'le kabul edilebilirdir, ama her Turing'le kabul edilebilir dil karar verilebilir değildir.

### 7.3 Tek kabul ve tek ret durumlu makineler

Bazen tek bir kabul durumu $q_{accept}$ ve tek bir ret durumu $q_{reject}$ olan makinelerle çalışmak kolaydır (ekrandan, 00:55:00). Bu durumda yalnız iki durma durumu ve yalnız iki olası durma yapılandırması vardır: kabul ya da ret.

Her Turing makinesi bu biçime getirilebilir:

- Birden çok son (kabul) durumu varsa, hepsinden yeni ve tek bir $q_{accept}$ durumuna geçiş eklenir.
- Bir $q_i$ durumunda bazı simgeler için geçiş tanımlı değilse makine eskiden orada dururdu. Yeni makinede bu simgeler için $q_i$'den $q_{reject}$'e geçiş eklenir. Bu geçişteki $x$, $q_i$'den çıkan geçişlerde kullanılmayan her simgedir.

<!-- BELİRSİZ: 00:56 civarında kabul durumlarını birleştiren geçişlerin etiketi altyazıda bozuk ("x'in n'ı symbol") -->

Karar verici için çıktı ikidir: kabul ya da ret. Turing'le kabul edilebilir bir dilin makinesinde ise bazı girişlerde durumlar arasında sonsuza dek dönülebilir.

### 7.4 Problemler ve diller

Bir hesaplama problemi, karşılık gelen dili karar verilebilirse karar verilebilirdir. Böyle bir probleme çözülebilir (solvable) de denir (ekrandan, 01:00:00). Hoca bunu "karar verilebilir, çözülebilir demektir" diye özetledi: problem verildiğinde onun dili kurulur; dil karar verilebilirse, yani her girişte kabul ya da ret durumunda duran döngüsüz bir makine varsa, problem çözülebilirdir.

## 8. Karar Verilebilir Problem Örnekleri

### 8.1 "$x$ sayısı asal mı?"

Karşılık gelen dil asal sayılar kümesidir. Hoca slayttaki kümeyi $\{1, 2, 3, 5, 7, 11, 13, \dots\}$ diye okudu.

**Soru:** 1'in bu kümede olmaması gerekmiyor muydu? **Cevap:** Matematik tarihinde 1 bir dönem asal kabul edilmiş, sonradan asallardan çıkarılmıştır; hocaya göre bu karar 1800'lerin sonlarına doğru verilmiştir. Bugün 1'i asal kabul etmiyoruz; slayta eklenmiş olması karar verilebilirlik açısından fark etmez, çıkarılabilir.

> **Ders sonrası not:** Günümüzdeki tanımla 1 asal değildir; asal sayılar kümesi $\{2, 3, 5, 7, 11, 13, \dots\}$'tür. Python ile 1-13 arasındaki asallar $2, 3, 5, 7, 11, 13$ olarak doğrulandı.

Karar verici: giriş sayısı $x$, 2 ile $\sqrt{x}$ arasındaki tüm sayılara bölünmeye çalışılır. Bunlardan biri $x$'i bölerse ret, hiçbiri bölmezse kabul. Bu çözümde döngü yoktur; her giriş için ya kabul ya ret durumuna ulaşılır. Bu yüzden dil karar verilebilirdir. Hoca karar verici bir Turing makinesinin bir algoritmaya dayanarak tasarlanabileceğini de ekledi.

### 8.2 "DFA $M$ boş dili mi kabul ediyor?"

Boş dil hiç elemanı olmayan dildir. Karşılık gelen dil (ekrandan, 01:05:00):

$$EMPTY_{DFA} = \{\langle M \rangle : M \text{ boş dili } \emptyset \text{ kabul eden bir DFA}\}$$

Burada $\langle M \rangle$, DFA $M$'nin bir dizgi olarak betimlenmesidir. Örneğin $M$, Turing makinelerinde yapıldığı gibi ikili bir dizgiyle kodlanabilir. Hoca bunu yazılan bir Java ya da C kodunun sonunda ikili dizgiye çevrilmesine benzetti. Boş dili kabul eden tüm DFA'ların kodları bir dizgi kümesi, yani bir dil oluşturur; bu dil karar verilebilirdir.

Karar verici: DFA'nın başlangıç durumundan bir kabul durumuna giden yol aranır. Böyle bir yol varsa makinenin dili boş değildir (bir dizgi kabul durumuna ulaşır). Boş dili tanımak için başlangıç durumundan kabul durumuna hiçbir yol olmamalıdır.

<!-- BELİRSİZ: 01:06:29-01:06:39 arası karar vericinin adımlarının sözlü açıklaması altyazıda bozuk -->

### 8.3 "DFA $M$ sonlu bir dil mi kabul ediyor?"

Dil, sonlu bir dil kabul eden DFA'ları betimleyen ikili dizgilerin kümesidir. Karar verici makinenin kodunu inceler ve başlangıç durumundan bir kabul durumuna giden, döngü (cycle) içeren bir yol olup olmadığına bakar. Böyle bir yol varsa döngü istenildiği kadar dolaşılabilir; DFA sonsuz büyüklükte bir dil tanır ve giriş reddedilir. Böyle bir yol yoksa dil sonludur ve giriş kabul edilir.

<!-- BELİRSİZ: 01:08:12-01:08:49 arası sözlü açıklama kelime kelime bölünmüş ve bozuk -->

### 8.4 "DFA $M$, $w$ dizgisini kabul ediyor mu?"

Karşılık gelen dil (ekrandan, 01:10:00):

$$A_{DFA} = \{\langle M, w \rangle : M, \ w\text{'yu kabul eden bir DFA}\}$$

Karar vericinin girdisi makine ile dizginin birlikte ikili kodudur. Karar verici DFA'yı $w$ üzerinde çalıştırır. DFA ya kabul eder ya reddeder; DFA'da döngüye girme yoktur. Bu yüzden dil karar verilebilirdir.

### 8.5 "$M_1$ ve $M_2$ aynı dili mi kabul ediyor?"

İki DFA verilsin; dilleri $L_1$ ve $L_2$ olsun. Karar vericinin girdisi iki makinenin ikili kodudur. Karar verici şu dili kabul eden bir DFA $M$ kurar:

$$L(M) = (L_1 \cap \overline{L_2}) \cup (\overline{L_1} \cap L_2)$$

İki DFA aynı dili tanıyorsa bu birleşim boştur: $L_1 \cap \overline{L_2} = \emptyset$ ve $\overline{L_1} \cap L_2 = \emptyset$ olur ve $L_1 = L_2$ sonucuna varılır. Birleşim boş değilse $L_1 \ne L_2$'dir. Böylece problem, $M$'nin boş dili kabul edip etmediği sorusuna dönüşür; bunun karar verilebilir olduğu zaten biliniyor. Sonuç olarak dil karar verilebilirdir.

> **Ders sonrası not:** Hoca bu birleşimin "boş dizgi" (empty string) olması gerektiğini söyledi. Doğrusu boş dil ($\emptyset$) olmasıdır; boş dizgi $\varepsilon$ ise uzunluğu sıfır olan bir dizgidir. Hoca formülü sözlü okurken de birleşimin ilk parçasını $L_1 \cap L_2$ diye okudu; doğrusu $L_1 \cap \overline{L_2}$'dir.

> **Ek bilgi (derste anlatılmadı):** Bu kurulum düzenli dillerin kesişim, birleşim ve tümleme altında kapalı olmasına dayanır; bu yüzden $L(M)$ yine düzenli bir dildir ve onu tanıyan bir DFA kurulabilir.

## 9. Karar Verilebilir Dilin Tümleyeni

**Teorem:** Bir $L$ dili karar verilebilirse tümleyeni $\overline{L}$ de karar verilebilirdir.

> **Hocanın vurgusu:** Hoca bunu "çok önemli bir teorem" olarak niteledi.

**İspat:** $\overline{L}$'yi kabul eden ve her giriş dizgisinde duran (döngüsüz) bir $M'$ makinesi kurulacak; yani $M'$, $\overline{L}$ için bir karar verici olacak.

$M$, $L$ için bir karar verici olsun. $M$'nin kabul durumu ret durumuna, ret durumu kabul durumuna dönüştürülür (ekrandan, 01:15:00):

| $M$ | $M'$ |
|---|---|
| $q_{accept}$: $q_a$ | $q'_{reject}$: $q_a$ |
| $q_{reject}$: $q_r$ | $q'_{accept}$: $q_r$ |

$M'$ makinesi her $w$ girişi için şöyle çalışır:

- $M$'yi $w$ üzerinde çalıştır.
- $M$ kabul ederse $w$'yu reddet.
- $M$ reddederse $w$'yu kabul et.

$M$ her girişte durduğu için $M'$ de her girişte durur; döngü yoktur. $M'$ tam olarak $\overline{L}$'yi kabul eder. İspat biter.

> **Ek bilgi (derste anlatılmadı):** Bu ispat yalnız karar vericiler için çalışır. Döngüye girebilen bir makinede kabul ve ret durumlarını yer değiştirmek, makinenin döndüğü girişleri hâlâ yanıtsız bırakır; bu yüzden Turing'le kabul edilebilir dillerin tümleyeni Turing'le kabul edilebilir olmak zorunda değildir.

## 10. Karar Verilemeyen Bir Dil: Köşegen Yöntemi

Karar verilemeyen (undecidable) bir dilin karar vericisi yoktur: o dili kabul eden her Turing makinesi bazı giriş dizgilerinde durmaz, döngüye girer.

> **Ders sonrası not:** Hoca bir yerde bunu "kesinlikle bir döngüsü olan bir Turing makinesi vardır" diye söyledi. Doğrusu, dili kabul eden **her** Turing makinesinin bazı girişlerde döngüye girmesidir; yani dilin hiçbir karar vericisi yoktur.

Hedef: Turing'le kabul edilebilir ama karar verilemeyen bir $L$ dili olduğunu göstermek. Bunun için $L$'nin Turing'le kabul edilebilir olduğu, ama tümleyeni $\overline{L}$'nin hiçbir Turing makinesince kabul edilmediği gösterilecek. Hoca, bir önceki teoremin (karar verilebilir dilin tümleyeni karar verilebilirdir) burada çok işe yaradığını vurguladı.

### 10.1 Dillerin ikili gösterimi

Alfabe $\Sigma = \{a\}$ olsun. Dizgiler $a, aa, aaa, \dots$, yani $a^1, a^2, a^3, \dots$ biçimindedir. Bu alfabe üzerindeki dilleri kabul eden Turing makineleri sayılabilir: $M_1, M_2, M_3, \dots$ Bir dil birden fazla Turing makinesince kabul edilebileceği için farklı $i$ ve $j$ değerlerinde $L(M_i) = L(M_j)$ olabilir.

Bir dil, her $a^i$'nin dilde olup olmadığını gösteren ikili bir satırla gösterilir. Örnek (ekrandan, 01:20:00):

$$L(M_i) = \{aa, aaaa, aaaaaa\} = \{a^2, a^4, a^6\}$$

| | $a^1$ | $a^2$ | $a^3$ | $a^4$ | $a^5$ | $a^6$ | $a^7$ | $\cdots$ |
|---|---|---|---|---|---|---|---|---|
| $L(M_i)$ | 0 | 1 | 0 | 1 | 0 | 1 | 0 | $\cdots$ |

Dilde bulunan dizginin altına 1, bulunmayanın altına 0 yazılır (python ile kontrol edildi).

### 10.2 Köşegen dili

Tüm makinelerin satırları alt alta yazılınca bir tablo oluşur. Slayttaki tablonun ilk dört sütunu şöyledir (ekrandan, 01:25:00):

| | $a^1$ | $a^2$ | $a^3$ | $a^4$ | $\cdots$ |
|---|---|---|---|---|---|
| $L(M_1)$ | **0** | 1 | 0 | 1 | $\cdots$ |
| $L(M_2)$ | 1 | **0** | 0 | 1 | $\cdots$ |
| $L(M_3)$ | 0 | 1 | **1** | 1 | $\cdots$ |
| $L(M_4)$ | 0 | 0 | 0 | **1** | $\cdots$ |

Köşegen kullanılarak yeni bir dil tanımlanır:

$$L = \{a^i : a^i \in L(M_i)\}$$

Yani $a^i$, $i$. makinenin dilinde ise $L$'dedir. Köşegen $0, 0, 1, 1$ olduğundan bu tabloda $L = \{a^3, a^4, \dots\}$ olur. Tümleyen:

$$\overline{L} = \{a^i : a^i \notin L(M_i)\}$$

$\overline{L}$ köşegendeki 0'lardan oluşur: $\overline{L} = \{a, aa, \dots\}$, satırı $1\,1\,0\,0 \cdots$'dır.

### 10.3 Teorem: $\overline{L}$ Turing'le kabul edilebilir değildir

**İspat (çelişki ile):** $\overline{L}$'nin Turing'le kabul edilebilir olduğunu varsayalım. O hâlde $\overline{L}$'yi kabul eden bir Turing makinesi $M_k$ vardır ve bu makine listede bir yerdedir: $L(M_k) = \overline{L}$, ikili gösterimi $1\,1\,0\,0 \cdots$.

- $M_k = M_1$ mi? $L(M_k)$'nin ilk biti 1, $L(M_1)$'in ilk biti 0'dır. Yani $a^1 \in L(M_k)$ ama $a^1 \notin L(M_1)$. Cevap: $M_k \ne M_1$.
- $M_k = M_2$ mi? İkinci bitler 1 ve 0'dır: $a^2 \in L(M_k)$ ama $a^2 \notin L(M_2)$. Cevap: $M_k \ne M_2$.
- $M_k = M_3$ mü? Üçüncü bitler 0 ve 1'dir: $a^3 \notin L(M_k)$ ama $a^3 \in L(M_3)$. Cevap: $M_k \ne M_3$.
- Benzer şekilde her $i$ için: $a^i \in L(M_k) \iff a^i \notin L(M_i)$, dolayısıyla $M_k \ne M_i$.

$M_k$ listedeki hiçbir makineye eşit olamaz; demek ki $M_k$ var olamaz. Sonuç: $\overline{L}$ Turing'le kabul edilebilir değildir. (Tablodaki dört tanık python ile kontrol edildi.)

### 10.4 $L$ Turing'le kabul edilebilirdir

$L$'yi kabul eden bir makine şöyle çalışır: giriş $a^i$ için $a$'lar sayılarak $i$ bulunur; sayımlayıcı (enumerator) ile $M_i$ makinesi elde edilir; $M_i$, $a^i$ girişi üzerinde taklit edilir. $M_i$ girişi kabul ederse makine de kabul eder. Bu yüzden $L$ Turing'le kabul edilebilirdir.

### 10.5 $L$ karar verilemezdir

$L$ karar verilebilir olsaydı, tümleme teoremine göre $\overline{L}$ de karar verilebilir olurdu (ekrandan, 01:30:00). Karar verilebilir her dil Turing'le kabul edilebilir olduğundan $\overline{L}$ Turing'le kabul edilebilir olurdu. Oysa $\overline{L}$'nin Turing'le kabul edilebilir olmadığı gösterildi. Çelişki! Demek ki $L$ karar verilemezdir.

Sonuçta dil sınıfları iç içe bir küme yapısı oluşturur: karar verilebilir diller, Turing'le kabul edilebilir dillerin içindedir; Turing'le kabul edilebilir diller de tüm dillerin içindedir. $L$, Turing'le kabul edilebilir ama karar verilemeyen bölgededir; $\overline{L}$ ise Turing'le kabul edilebilir olmayan bölgededir.

> **Ders sonrası not:** Hoca sonucu "karar verilemez, yani Turing makinesi yoktur" diye bağladı. Doğrusu, $L$ için bir **karar verici** yoktur; $L$'yi kabul eden (bazı girişlerde döngüye giren) bir Turing makinesi vardır.

> **Hocanın vurgusu:** Hoca bu konulardan (karar verilebilir diller ve köşegen ispatı) final sınavında soru sorulacağını söyledi.

## 11. Zaman Karmaşıklığı, P ve NP

Dersin son bölümünde hoca zaman karmaşıklığından kısaca bahsetti.

### 11.1 Karar süresi ve $T_M(n)$

Bir $L$ diline karar veren belirlenimci (standart) bir Turing makinesi $M$ düşünelim. Her giriş dizgisi $w$ için hesaplama sonlu sayıda geçişte biter: başlangıç durumundan başlanır, sonunda kabul ya da ret durumuna ulaşılır. Karar süresi, başlangıç durumundan kabul ya da ret durumuna kadarki geçiş sayısıyla orantılıdır.

$n$ uzunluğundaki tüm dizgiler düşünülürse, $T_M(n)$ bu dizgilerden herhangi birine karar vermek için gereken en uzun süredir. Slayttaki grafikte yatay eksen dizgi uzunluğu ($1, 2, 3, 4, \dots, n$), dikey eksen süredir ve her $n$ için en uzun karar süresi işaretlenmiştir (ekrandan, 01:40:00).

### 11.2 Zaman karmaşıklığı sınıfları

$TIME(T(n))$, $T(n)$ sürede belirlenimci bir Turing makinesiyle karar verilebilen tüm dillerin sınıfıdır. Örnekler:

- $\{a^nb\}$: süre giriş uzunluğuyla orantılıdır, yani doğrusal ($n$) sürede karar verilir.
- $\{a^nb^n\}$ ve $\{ww\}$: $n^2$ sürede karar verilir. <!-- BELİRSİZ: hocanın "yarı uzunluğun karesi" ifadesi (01:42:02) altyazıda tam anlaşılmıyor -->
- Matris çarpımı: iki matristen üçüncüsünü elde etmek $n^3$ karmaşıklıktadır.
- CYK algoritması: bağlamdan bağımsız bir gramer ve bir dizgi birlikte verildiğinde dizginin gramerce üretilip üretilmediğine karar verir; süresi giriş uzunluğunun küpüyle ($n^3$) orantılıdır.

### 11.3 Polinom zaman ve P sınıfı

Bir $k$ sabiti için $TIME(n^k)$ polinom zamanlı algoritmaları verir. $k$ küçükse sonuca hızla karar verilir; bu tür algoritmalara uygulanabilir (tractable) denir. Bu yüzden polinomdaki üssün olabildiğince küçük olduğu algoritmalar aranır. Hoca küçük üslü bir sınıfın büyük üslü sınıfın alt kümesi olduğunun gösterilebileceğini de söyledi.

$$P = \bigcup_{k} TIME(n^k)$$

$P$ sınıfı polinom zamanlı algoritmaları, yani uygulanabilir problemleri temsil eder. Slayttaki $P$ kümesinde $\{a^nb\}$, $\{a^nb^n\}$, $\{ww\}$, CYK algoritması ve matris çarpımı vardır (ekrandan, 01:45:00).

### 11.4 Üstel zaman ve uygulanamaz problemler

Üstel zamanlı algoritmalarda süre $2^{n^k}$ biçimindedir. Hoca bu algoritmaların uygulanamaz (intractable) olduğunu, girdi büyüdükçe çözümün yüzyıllar alabileceğini söyledi. Örnek olarak şifreleme anahtarını bilmeden şifreli bir metni çözmenin çok uzun süreceğini verdi.

> **Ders sonrası not:** Hoca $k$ değeri 1'den küçükse problemin uygulanabilir sayılabileceğini söyledi. $0 < k < 1$ için bile $2^{n^k}$ her polinomdan daha hızlı büyür; bu yüzden böyle bir algoritma büyük olasılıkla polinom zamanlı (uygulanabilir) sayılmaz.

Üstel zaman örnekleri:

- **Hamilton yolu:** Bir grafta tüm düğümleri birer kez ziyaret eden bir yol var mı? Çözüm tüm yolları sırayla dener; yol sayısı $n!$ mertebesindedir. Bu yüzden üstel zaman gerekir ve problem uygulanamaz sayılır. <!-- BELİRSİZ: 01:46:35-01:48:14 arası Hamilton yolu anlatımı büyük ölçüde bozuk; graf örneği karelerde yok -->
- **Klik problemi:** $k$ boyutlu bir klik var mı? Klik, tüm düğümlerin birbirine bağlı olduğu düğüm kümesidir (örneğin $k = 5$).
- **Sağlanabilirlik (SAT):** Birleşik normal biçimdeki (conjunctive normal form) bir Boole ifadesi, yani $t_1 \lor t_2 \lor \dots \lor t_k$ biçimindeki tümcelerin VE'si sağlanabilir mi? Slayttaki örnekte $x_1 = 0$, $x_2 = 1$, $x_3 = 1$ atamasıyla ifade 1 olur, yani ifade sağlanabilirdir. Bu dili tanımak için bilinen yöntemler üstel zaman ister. <!-- BELİRSİZ: SAT örneğindeki ifadenin kendisi karelerde ve altyazıda yok (01:49:31) -->

### 11.5 Belirlenimci olmama ve NP

$NTIME(T(n))$, belirlenimci olmayan Turing makinelerinin $n$ uzunluğundaki her dizgiye $T(n)$ sürede karar verdiği dillerin sınıfıdır (ekrandan, 01:50:00). Belirlenimci olmayan makinenin bir dizgi üzerindeki tüm hesaplamaları bir ağaç olarak gösterilebilir; kabul durumuna ulaşan bir dalın uzunluğu giriş uzunluğuyla orantılı süreyi verir.

$$NP = \bigcup_{k} NTIME(n^k)$$

$NP$, belirlenimci olmayan polinom zaman sınıfıdır.

Gözlem: $P \subseteq NP$.

**Açık problem:** $P = NP$ mi? Cevabı bilmiyoruz. Örneğin SAT probleminin polinom zamanlı belirlenimci bir algoritması var mı? Bunu da bilmiyoruz. Hoca bu problemin çözülmesinin çok uzun sürebileceğini, ama ileride kuantum bilgisayarlar gibi daha güçlü makinelerle bu tür sorulara cevap verilebileceğini söyledi. Hoca NP-tam (NP-complete) dillere girmeden konuyu burada bitirdi.

## Örnek Sorular

**Soru 1** (ekrandan, 00:10:00): Stay-option makinesinde şerit $\Diamond\, a\, a\, b\, a\, \Diamond$, makine $q_1$ durumunda ilk $a$ üzerindedir ve $q_1 \xrightarrow{a \to b,\,S} q_2$ geçişi uygulanır. Standart makinede bu geçişi taklit edin ve ara şeritleri gösterin.

> **Çözüm:** Standart makinede $q_1 \xrightarrow{a \to b,\,L} q_t$ ile şerit $\Diamond\, b\, a\, b\, a\, \Diamond$ olur ve kafa soldaki $\Diamond$'ya gider; sonra $q_t \xrightarrow{x \to x,\,R} q_2$ ile kafa yeniden $b$'nin üzerine döner. Son durum: şerit $\Diamond\, b\, a\, b\, a\, \Diamond$, kafa ikinci hücrede, durum $q_2$ (python ile kontrol edildi).

**Soru 2** (ekrandan, 01:00:00): "$x$ sayısı asal mı?" problemi karar verilebilir mi?

> **Çözüm:** Evet. Karşılık gelen dil asal sayılar kümesidir. Karar verici $x$'i 2 ile $\sqrt{x}$ arasındaki tüm sayılara böler; biri bölerse reddeder, hiçbiri bölmezse kabul eder. Her girişte durur, döngü yoktur.

**Soru 3** (ekrandan, 01:05:00): "DFA $M$ boş dili mi kabul ediyor?" problemi karar verilebilir mi?

> **Çözüm:** Evet; $EMPTY_{DFA}$ karar verilebilirdir. Karar verici başlangıç durumundan bir kabul durumuna yol arar. Yol yoksa dil boştur (kabul), yol varsa dil boş değildir (ret).

**Soru 4** (derste sözlü, 01:06:54): "DFA $M$ sonlu bir dil mi kabul ediyor?" problemi karar verilebilir mi?

> **Çözüm:** Evet. Başlangıç durumundan bir kabul durumuna giden ve döngü içeren bir yol varsa dil sonsuzdur ve $M$ reddedilir; yoksa dil sonludur ve $M$ kabul edilir.

**Soru 5** (ekrandan, 01:10:00): "DFA $M$, $w$ dizgisini kabul ediyor mu?" problemi karar verilebilir mi?

> **Çözüm:** Evet; $A_{DFA} = \{\langle M, w\rangle : M,\ w\text{'yu kabul eden bir DFA}\}$ karar verilebilirdir. Karar verici $M$'yi $w$ üzerinde çalıştırır; DFA $|w|$ adımda biter ve ya kabul ya ret verir.

**Soru 6** (derste sözlü, 01:10:49): İki DFA $M_1$ ve $M_2$ aynı dili mi kabul ediyor? Bu problem çözülebilir mi?

> **Çözüm:** Evet. $L(M) = (L_1 \cap \overline{L_2}) \cup (\overline{L_1} \cap L_2)$ olan bir DFA kurulur ve $L(M) = \emptyset$ olup olmadığına $EMPTY_{DFA}$ karar vericisiyle bakılır. Boşsa $L_1 = L_2$, değilse $L_1 \ne L_2$.

**Soru 7** (ekrandan, 01:25:00): Köşegen tablosunda $L(M_1) = 0101\cdots$, $L(M_2) = 1001\cdots$, $L(M_3) = 0111\cdots$, $L(M_4) = 0001\cdots$ ve $L(M_k) = \overline{L}$ olsun. $M_k = M_1$ midir? $M_k$, $M_2$, $M_3$, $M_4$'ten birine eşit olabilir mi?

> **Çözüm:** Köşegen $0, 0, 1, 1$ olduğundan $\overline{L}$'nin satırı $1100\cdots$'dır. $a^1 \in L(M_k)$ ama $a^1 \notin L(M_1)$, bu yüzden $M_k \ne M_1$. Aynı şekilde $a^2$ tanığıyla $M_k \ne M_2$, $a^3$ tanığıyla $M_k \ne M_3$, $a^4$ tanığıyla $M_k \ne M_4$ (python ile kontrol edildi). Genel olarak her $i$ için $M_k \ne M_i$ olduğundan $M_k$ var olamaz.

## Dersin Toparlaması

Dersin ilk bölümünde Turing makinesi çeşitleri tamamlandı. Yerinde kalma seçenekli, çok izli, yarı sonsuz şeritli, çok şeritli, çok boyutlu ve belirlenimci olmayan makinelerin hepsinin standart Turing makinesiyle aynı güçte olduğu, her seferinde iki yönlü taklitle gösterildi. Bu çeşitler bazı dilleri daha hızlı tanıyabilir, ama standart makinenin tanıyamadığı bir dili tanıyamaz.

İkinci bölümde Turing'le kabul edilebilir diller ile karar verilebilir diller arasındaki fark, yani karar vericinin her girişte durması koşulu üzerinde duruldu. DFA'larla ilgili temel problemlerin (üyelik, boşluk, sonluluk, eşitlik) ve asallık probleminin karar verilebilir olduğu görüldü. Karar verilebilir dilin tümleyeninin de karar verilebilir olduğu ispatlandı ve köşegen yöntemiyle Turing'le kabul edilebilir ama karar verilemeyen bir dil kuruldu. Son bölümde zaman karmaşıklığı, $P$ ve $NP$ sınıfları tanıtıldı ve $P = NP$ sorusunun açık bir problem olduğu belirtildi. Bu, dönemin son dersiydi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
