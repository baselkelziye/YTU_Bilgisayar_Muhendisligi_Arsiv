# Ders 2 Genişletilmiş Notu: Hesaplama Kuramına Giriş, Kümeler, Boole Mantığı, İspat Teknikleri; Alfabe, Dizgi ve Dil

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Hesaplama Kuramı Nedir?
- 2. Problemler ve Dizgi Kümeleri
- 3. Makineyle Konuşmak ve Hesaplayıcı Kavramı
- 4. Domino Bilgisayarı
- 5. Hesaplama Kuramının Soruları ve Bilgisayarların Sınırları
- 6. Karmaşıklık, Hesaplanabilirlik ve Otomata Kuramları
- 7. Kümeler Kuramı
- 8. Boole Mantığı
- 9. Teorem, Aksiyom, Lemma ve İspat İpuçları
- 10. İspat Teknikleri
- 11. Alfabe, Sembol ve Dizgi
- 12. Dil ve Düzenli Diller
- 13. Dizgi İşlemleri: Birleştirme, Ters Çevirme, Önek ve Sonek
- 14. Kuvvet, Yıldız ve Artı İşlemleri
- 15. Dil Örnekleri ve İşlemlerin Dil Olarak Yazılması
- 16. Diller Üzerinde Küme İşlemleri; Boş Küme ve Boş Dizgi
- 17. Sonlu Otomata İlk Bakış

## 1. Hesaplama Kuramı Nedir?

Ders İngilizce anlatıldı, araya Türkçe açıklamalar girdi. Hoca, hesaplama kuramını (theory of computation) "neyi hesaplayabileceğimize dair soyutlamalar dersi" diye tanımladı. Bu, bilgisayar biliminin en "saf" konusudur: gerçek bilgisayarın bütün ayrıntılarını atar, yerine soyut modeller koyar. Soyutlama, yaptığımız şeyi belirsizlik içinde bocalamak yerine kesin ve biçimsel bir dille söylememizi sağlar. Hesaplama kuramı bilgisayar bilimi ile matematiğin birleştiği bir daldır. Hesaplamanın genel özelliklerini inceler. Bu da bilgisayarın verdiği çözümlerin geçerliliğini değerlendirmemize ve algoritmaları daha verimli hâle getirmemize yardım eder.

Kuram üç ana alan üzerinden incelenir:

- Otomata kuramı (automata theory)
- Hesaplanabilirlik kuramı (computability theory)
- Hesaplama karmaşıklığı kuramı (computational complexity theory)

Otomata kuramı, hesaplamanın mantığını "otomat" denen basit makineler üzerinden inceleyen kuramsal daldır. 20. yüzyılda matematikçiler tarafından kurulmuştur. Bilim insanlarının makinelerin fonksiyonları nasıl hesapladığını anlamasını sağlar. Gelişmesinin ana nedeni, ayrık (discrete) sistemlerin dinamik davranışını tanımlamak ve çözümlemek için yöntemler geliştirmekti. "Otomat" sözcüğü "automaton" sözcüğünden gelir ve "otomasyon" ile yakından ilişkilidir. Sonlu durum makineleri (finite state machines) özellikle arama algoritmalarında, derleyici tasarımında, bilgisayar mimarisindeki kontrol birimi tasarımında ve birçok modelleme uygulamasında kullanılır. Kuram ayrıca bağlamdan bağımsız gramerleri ve onların kısıtlı biçimlerini de inceler. Bunlar derleyicilerin ve ayrıştırmanın (parsing) temelidir. NP-tamlık kuramı da çözülebilir (tractable) problemleri çözülmesi pratikte olanaksız (intractable) problemlerden ayırmamıza yardım eder.

Hesaplanabilirlik konusunda hoca şunu söyledi: bir problem Turing makinesiyle formüle edilebiliyorsa o problem hesaplanabilirdir.

## 2. Problemler ve Dizgi Kümeleri

Hocaya göre dersin amacı, bir problemin çok basit modellerini ele almaktır. Bir problem, ayırt etmek (tanımak) istediğimiz bir dizgi kümesiyle, çoğu zaman ikili (binary) dizgilerle gösterilir. Örneğin bir problem "3'e bölünebilen bütün ikili sayıların kümesi" olabilir. Bu problemi çözmek için her aday dizgiye "kümede mi, değil mi?" sorusuna evet ya da hayır diyebilmemiz gerekir. Yani aslında bir dizginin kümenin elemanı olup olmadığı denetlenir. Bunu yapan bir algoritmamız varsa problemi çözmüş oluruz. Hoca bu tür problemlere karar verilebilir problemler (decidable problems) dedi.

Daha büyük alfabeler üzerinde daha karmaşık girdiler de düşünülebilir. Örneğin girdi, her biri ikili yazılmış ve birbirinden `#` sembolüyle ayrılmış sayılardan oluşan bir liste olsun. Problem de "sayıların artan sırada olduğu bütün bu tür listelerin kümesi" olabilir.

Hoca bir makineyi ya da otomatı, bir sistemin kapısında duran ve yalnız belirli türdeki ikili dizgileri içeri alan bir bekçiye benzetti. Makineye bir program verilir. Makine her aday girdiyi alır, programı çalıştırır ve o girdi için evet ya da hayır kararı verir.

## 3. Makineyle Konuşmak ve Hesaplayıcı Kavramı

Hoca, hesaplama kuramının aslında bir dil tanımladığını vurguladı. Arkadaşlarımızla ve ailemizle Türkçe konuşuruz. Türkçenin cümle ve paragraf yapısı, sözcükleri vardır; her sözcük harflerden oluşur. Bir şey duyduğumuzda harfleri, sözcükleri, sözcük dizilerinden de cümleyi tanırız ve anlarız. Makineyle konuşmak istersek de makinenin anladığı bir dile ihtiyacımız vardır. Makineyle konuşmamızın nedeni, ona bir şeyler hesaplatmaktır. Makinenin dilini kullanarak hesap emirlerimizi veririz, makine de bizim için hesaplar.

Ardından hoca ekranda farklı düzeneklerin resimlerini gösterip "Hangisi bilgisayardır?" diye sordu. Bilgisayar, hesap yapan bir makinedir. Bu yüzden resimlerdekilerin hepsi bilgisayardır: abaküs, mekanik hesap makinesi, otomat, süper bilgisayar ve diğerleri.

Hoca burada Türkçedeki "bilgisayar" sözcüğünü eleştirdi. Ona göre bilgisayar bilgi saymaz, hesap yapar. Ayrıca bilimsel olarak bilgi sayılamaz (uncountable). Bu yüzden "computer" sözcüğünün doğru Türkçe karşılığı "hesaplayıcı"dır. Batıda bir çocuk "computer" sözcüğünü duyunca aklına abaküsten süper bilgisayara kadar hesap yapan her düzenek gelebilir. "Bilgisayar" denince ise çoğu kişinin aklına oyunlar ve programlar gelir. Hoca, öğrencilerin aslında "hesaplayıcı mühendisi" olacağını, iyi hesap yapabilmeleri ve problemleri hesaplayıcılar kullanarak çözebilmeleri gerektiğini söyledi. Hesaplayıcıların ihtiyaca göre seçildiğini de ekledi: büyük bir problem için süper bilgisayar gerekebilir, küçük bir hesap için abaküs bile yeter.

> **Hocanın vurgusu:** Hesaplayıcıları programlama dilleriyle kontrol ederiz. Yani hesaplayıcılarla programlama dilleri aracılığıyla konuşuruz.

## 4. Domino Bilgisayarı

Hesaplama için dizüstü ya da masaüstü bilgisayara gerek olmadığını göstermek için yaklaşık 10.000 dominoyla kurulmuş bir hesap makinesinin videosu izlendi. Videodaki düzenek iki tane 4 bitlik ikili sayıyı topluyordu.

- Girişler: iki sayının birler, ikiler, dörtler ve sekizler basamakları ayrı ayrı girilir. Bir basamağa "1" girmek için o basamağın domino yolu doldurulur.
- Birler basamağı bir yarım toplayıcıdır (half adder): iki biti toplar, sonucun birler basamağını verir, ikiler basamağını elde (carry) olarak bir sonraki aşamaya aktarır.
- Diğer basamaklar tam toplayıcıdır (full adder): iki sayının bitlerine ek olarak önceki aşamadan gelen eldeyi de alır.
- Çıkış birler, ikiler, dörtler, sekizler ve on altılar basamağı olarak okunur.

Tek bitlik toplama birimi şöyle çalışır: iki girişten yalnız biri düşerse çıkışta "1" sinyali çıkar. İkisi birden düşerse bir domino kolu ötekini durdurur ve "2" anlamına gelen çıkış (yani elde) düşer. Bütün hesap bu birimin tekrar tekrar kullanılmasıyla yapılır.

Örnek işlemde $9 + 3$ hesaplandı. $9 = 8 + 1$ ve $3 = 2 + 1$ olarak girildi. Beklenen sonuç $12 = 8 + 4$ idi: çıkışta yalnız dörtler ve sekizler basamağı düşmeliydi. Doğru basamaklar düştü, ancak zamanlama hatası yüzünden ikiler ve on altılar basamağı da düştü. Videodaki açıklamaya göre en büyük sorun zamanlamaydı: bir domino kolunun ötekini zamanında durdurabilmesi için zikzak yollarla gecikme ekleniyordu ve bir noktada bu gecikme yetmedi.

## 5. Hesaplama Kuramının Soruları ve Bilgisayarların Sınırları

Slayttaki sorular şunlardı (ekrandan, 00:55:00):

- Bilgisayar donanımının ve yazılımının matematiksel özellikleri nelerdir?
- Hesaplama nedir, algoritma nedir? Bu kavramlara kesin matematiksel tanımlar verebilir miyiz?
- Bilgisayarların sınırları nelerdir? "Her şey" hesaplanabilir mi? (Göreceğimiz gibi cevap "hayır"dır.)
- Hesaplama kuramının amacı: gerçek bilgisayarları yansıtan biçimsel matematiksel hesaplama modelleri geliştirmek.

Hoca, donanımı bilgisayarın "malzeme" kısmı, yazılımı ise "dil" kısmı diye açıkladı. Bilgisayara bir şey hesaplatmak için ona bir yazılım, yani bir dil vermek gerekir. Algoritmalarımızın temel gereksinimi de hesaplamadır. Hesaplanamayan bir algoritma işe yaramaz; algoritma hesaplanabilir olmalıdır.

Her şey hesaplanabilir mi? Hayır. Hocanın gerekçesi kaynakların sınırlı olmasıdır. Sınırlı bir uzaydaki her şey sınırlıdır. Kaynaklar sınırlıysa hesaplama gücü de sonsuz olamaz, dolayısıyla her şey hesaplanamaz.

- Birinci sınırlı kaynak RAM'dir. RAM çok azsa birçok şey hesaplanamaz. Örneğin bir dosyayı açmaya ya da bir yazılımı çalıştırmaya çalışırken bilgisayar çok yavaş yanıt veriyorsa, istediğimizi hesaplayamıyor demektir. Bu durumda uygulama, o bilgisayar için hesaplanamaz sayılabilir.
- Teknoloji geliştikçe donanımın hesaplama kaynakları arttı. 20 yıl önce cep telefonları yoktu. Bugün her cep telefonu bir hesaplayıcıdır, içinde ofis uygulamaları bile çalışır. Yani hesaplanabilirlik bilgisayarın kaynaklarıyla ilişkilidir.
- İkinci sınırlı kaynak işlemci gücüdür. Bu sınırları aşmak için dağıtık işlemciler ve dağıtık bellekler kullanılır.

Hoca, bu dersin sonunda gerçek bilgisayarları yansıtan biçimsel modeller geliştirebileceğimizi, bu bilgi olmadan algoritmalar ve problemler hakkında yararlı çıkarımlar yapamayacağımızı söyledi.

## 6. Karmaşıklık, Hesaplanabilirlik ve Otomata Kuramları

### 6.1 Karmaşıklık Kuramı

Karmaşıklık kuramının ana sorusu şudur: bazı problemleri hesaplama açısından zor, bazılarını kolay yapan nedir? Hoca, problemi bilgisayarın kolayca anlayacağı bir dille ifade edip yazılımı çalıştırarak sonucu alabiliyorsak problemin kolay olduğunu, bazı problemlerin ise çözülmesinin çok güç olduğunu anlattı.

Zor problem örneği olarak şu problemi verdi: 100 sayı veriliyor. Bu sayıları, her iki gruptaki sayıların karelerinin toplamı aynı olacak biçimde iki gruba ayırabilir misiniz? Sayılar 1 milyon olunca problem daha da zorlaşır. Hoca, kuantum hesaplama yaygınlaşınca bu tür problemlerin kolaylaşabileceğini, ikili mantığa dayanan bugünkü bilgisayarlarla ise kolay olmadığını söyledi.

> **Ders sonrası not:** Hoca bu problem için "çözülemez" (unsolvable) ve "hesaplanamaz" (uncomputable) sözcüklerini de kullandı. Bu problem hesaplanabilirdir: sonlu sayıda olası bölme olduğu için hepsi tek tek denenerek çözülebilir. Zor olan, onu verimli biçimde çözmektir. Yani bu bir karmaşıklık sorusudur, hesaplanabilirlik sorusu değildir.

Kolay problem örnekleri: 1 milyon sayıyı sıralamak, telefon rehberinde bir isim aramak, iki semt arasındaki en hızlı yolu hesaplamak. Zor problem örnekleri slaytta şöyleydi (ekrandan, 01:05:00):

- Bütün dersler için ders programı çizelgeleme
- 300 basamaklı bir tamsayıyı asal çarpanlarına ayırma
- VLSI'da yonga yerleşimi hesaplama

Karmaşıklık kuramının ana sorusu: problemleri "zorluk" derecelerine göre sınıflandırmak ve zor görünen problemlerin gerçekten zor olduğunu kesin olarak ispatlamak.

### 6.2 Hesaplanabilirlik Kuramı

Hesaplanabilirlik kuramı 1930'larda başladı. Bilim insanları, bazı temel problemlerin bilgisayarla çözülemeyeceğini keşfetti. Bu tür problemlere yaklaşmak için önce kavramların biçimsel tanımı gerekir: bilgisayar nedir, algoritma nedir, hesaplama nedir? Bilgisayar hesaplama gücü üretir, bu güç algoritma içinde kullanılır ve algoritma bilgisayarın içinde çalışır. Hesaplanabilirlik kuramının ana sorusu problemleri çözülebilir ve çözülemez diye sınıflandırmaktır.

> **Ders sonrası not:** Hoca, 1940'larda icat edilen bilgisayarların transistör teknolojisi kullandığını söyledi. İlk elektronik bilgisayarlar büyük olasılıkla vakum tüplüydü; transistör 1947'de icat edildi, transistörlü bilgisayarlar 1950'lerde yaygınlaştı.

### 6.3 Otomata Kuramı

Otomata kuramı farklı hesaplama modellerinin tanımlarını ve özelliklerini inceler (ekrandan, 01:10:00):

- **Sonlu otomatlar (finite automata):** Metin işlemede, derleyicilerde ve donanım tasarımında kullanılır. İki türü vardır: deterministik sonlu otomat (DFA) ve deterministik olmayan sonlu otomat (NFA). Durumları vardır ve girdiyi bu durumları kullanarak işler. Sonlu otomatın da bir dili vardır; ona ne hesaplatmak istediğimizi bu dille söyleriz. Sonlu otomat çok basit bir modeldir, her şeyi hesaplayamaz. Örneğin bir metinde belirli bir sözcüğü ya da ifadeyi aramakta kullanılabilir. Derleyiciler de yazdığımız her sözcüğü (örneğin Java'daki `import`, `if`, `for`, `while`, `class`) tanıyabilmelidir. Hoca, işlemcilerin de bir sonlu otomatlar kümesi olarak düşünülebileceğini söyledi.
- **Bağlamdan bağımsız gramerler (context-free grammars):** Programlama dillerini tanımlamada ve yapay zekâda kullanılır. Sonlu otomatlardan biraz daha güçlüdür. Hocanın anlatımıyla bu makinelerin durumlarına ek olarak belleği de vardır; sonlu otomatın belleği yoktur.
- **Turing makineleri:** Gerçek bir bilgisayarın (örneğin evdeki kişisel bilgisayarın) basit soyut modelidir.

Otomata kuramının ana sorusu: bu modellerin gücü aynı mı, yoksa biri ötekinden daha çok problem çözebilir mi?

> **Ek bilgi (derste anlatılmadı):** Bağlamdan bağımsız gramerlere karşılık gelen makine modeli yığıtlı otomattır (pushdown automaton). Hocanın "bellek" dediği şey bu yığıttır. Sonlu otomatın belleği yalnız içinde bulunduğu durumdan ibarettir.

Hoca, hesaplama kuramına başlamak için kümeler kuramının gerektiğini söyleyerek ilk araya geçti.

## 7. Kümeler Kuramı

Kümeler kuramının (set theory) temel tanımı: küme, iyi tanımlanmış nesnelerin topluluğudur. Slayttaki kümeler şunlardı (ekrandan, 01:25:00):

- Doğal sayılar: $\mathbb{N} = \{1, 2, 3, \dots\}$, yani pozitif tamsayılar.
- Tamsayılar: $\mathbb{Z} = \{\dots, -3, -2, -1, 0, 1, 2, 3, \dots\}$. Negatif ve pozitif tamsayılarla sıfırı içerir.
- Rasyonel sayılar: $\mathbb{Q} = \{m/n : m \in \mathbb{Z},\ n \in \mathbb{Z},\ n \neq 0\}$. İki tamsayının oranı olarak yazılabilen sayılardır. Tanımdaki iki nokta (:) "öyle ki" diye okunur.
- Gerçel sayılar $\mathbb{R}$ ile gösterilir. Örneğin $1{,}2$, $0{,}00001$, $\pi$ ve $e$ gerçel sayılardır. Karmaşık sayılar da $\mathbb{C}$ ile gösterilir.
- $A$'nın her elemanı $B$'nin de elemanıysa $A$, $B$'nin alt kümesidir: $A \subseteq B$.
- $B$ bir küme ise $B$'nin kuvvet kümesi (power set) $B$'nin bütün alt kümelerinin kümesidir: $P(B) = \{A : A \subseteq B\}$. $\emptyset \in P(B)$ ve $B \in P(B)$'dir.

> **Ders sonrası not:** Kuvvet kümesinin eleman sayısı $|P(B)| = 2^{|B|}$'dir. Altyazıda hocanın sözü "iki üssü $|B|$ artı bir" gibi duyuluyor. Boş küme $2^{|B|}$ alt kümenin içinde zaten sayılır; ayrıca 1 eklenmez.

Küme işlemleri:

- **Birleşim:** $A \cup B$, $A$ ile $B$'nin elemanlarını bir araya getiren yeni kümedir.
- **Kesişim:** $A \cap B$, hem $A$'nın hem $B$'nin elemanı olan elemanlardan oluşur.
- **Fark:** $A - B$.
- **Kartezyen çarpım:** $A \times B$, birinci bileşeni $A$'dan, ikinci bileşeni $B$'den gelen ikililerden oluşur. Eleman sayısı $|A \times B| = |A| \cdot |B|$'dir.
- **Tümleyen:** $\overline{A}$, $A$'nın elemanı olmayan elemanlardan oluşur.

İki küme arasındaki ikili bağıntı (binary relation), Kartezyen çarpımlarının bir alt kümesidir. Fonksiyon bir eşlemedir (mapping): bir kümenin elemanlarından başka bir kümenin elemanlarına gidilir. $R \subseteq A \times A$ bağıntısı şu üç koşulu sağlıyorsa bir denklik bağıntısıdır (equivalence relation): yansımalı (reflexive), simetrik (symmetric) ve geçişli (transitive). Bu koşullardan biri sağlanmazsa bağıntı denklik bağıntısı değildir.

## 8. Boole Mantığı

Boole mantığı iki değerle çalışır: 1 ve 0 (ekrandan, 01:30:00). Hoca 0'ı "yokluk", 1'i "varlık" diye de açıkladı. 1 doğruyu, 0 yanlışı gösterir. Temel Boole işlemleri:

| İşlem | Diğer adı | Simge |
|---|---|---|
| değilleme (negation) | NOT | $\neg$ |
| birleşme (conjunction) | AND | $\wedge$ |
| ayrılma (disjunction) | OR | $\vee$ |
| dışlayan veya (exclusive-or) | XOR | $\oplus$ |
| denklik (equivalence) | | $\leftrightarrow$ ya da $\Leftrightarrow$ |
| gerektirme (implication) | | $\rightarrow$ ya da $\Rightarrow$ |

Hocanın anlattığı kurallar: 0'ın değili 1, 1'in değili 0'dır. VE işleminde girişlerden biri 0 ise sonuç 0'dır. VEYA işleminde girişlerden biri 1 ise sonuç 1'dir. XOR'da girişler farklıysa çıkış 1, aynıysa 0'dır. Denklikte $0 \leftrightarrow 0$ doğru, $0 \leftrightarrow 1$ yanlıştır.

## 9. Teorem, Aksiyom, Lemma ve İspat İpuçları

Hoca, "teori" (theory) ile "teorem" (theorem) arasındaki farkı sordu, ancak cevap gelmedi (bkz. Örnek Sorular). Ardından şu kavramları tanımladı:

- **Aksiyomlar:** Matematiksel yapının altında yatan varsayımlardır. Hocanın ifadesiyle gözleme dayanarak doğru kabul edilirler.
- **Hipotez:** Önce hipotez vardır; hipotez ispatlanınca teorem olur.
- **Lemma:** Daha önce (başka bilim insanlarınca) ispatlanmış ya da görece basit teoremlerdir; ispatları zaten bilinir.
- **Sonuç (corollary):** Teoremlerden elde edilen sonuçlardır.

İspat yazmanın belirli bir yolu yoktur, ama yardımcı olan geleneksel stratejiler vardır. Slayttaki ipuçları (ekrandan, 01:35:00):

- İspatlanacak teoremin ifadesini okuyun ve tamamen anlayın. Çoğu zaman en zor kısım budur. İfadeyi kendi sözlerinizle yeniden yazın.
- Bazen teoremler içlerinde başka teoremler barındırır. Örneğin "A özelliği ancak ve ancak B özelliği" iki ifadenin gösterilmesini gerektirir: (a) A doğruysa B doğrudur ($A \rightarrow B$), (b) B doğruysa A doğrudur ($B \rightarrow A$).
- Başka bir örnek "A kümesi B kümesine eşittir" teoremidir. Bunu ispatlamak için $A \subseteq B$ ve $B \subseteq A$ gösterilir: $A$'nın her elemanı $B$'dedir ve $B$'nin her elemanı $A$'dadır.
- Teoremi anlamak için birkaç basit durum üzerinde çalışın: basit değerler seçip teoremin bu durumlarda doğru olup olmadığına bakın.

> **Hocanın vurgusu:** Derste, quizlerde ve sınavlarda bir teoremin ispatı sorulabilir. Önce teoremi çok iyi anlamak gerekir. Hoca, iki yönlü gösterme yönteminin çok kullanıldığını ve pompalama önsavında da karşımıza çıkacağını söyledi.

## 10. İspat Teknikleri

Hoca beş ispat tekniği saydı: doğrudan (yapıcı) ispat, yapıcı olmayan ispat, olmayana ergi, tümevarım ve güvercin yuvası ilkesi. Güvercin yuvası ilkesinin bilgisayar biliminde çok kullanıldığını söyledi.

### 10.1 Doğrudan İspat

Adından da anlaşılacağı gibi doğrudan ispatta teoreme doğrudan yaklaşılır (ekrandan, 01:40:00).

**Teorem:** $n$ tek pozitif bir tamsayı ise $n^2$ de tektir.

**İspat:** Tek pozitif bir tamsayı, bir $k \ge 0$ tamsayısı için $n = 2k + 1$ biçiminde yazılabilir. $2k$ her zaman çift olduğu için, çift artı bir her zaman tektir; böylece $n$'nin tek olduğu garanti edilir. Kare alınıp binom açılımı yapılır:
$$n^2 = (2k+1)^2 = 4k^2 + 4k + 1 = 2(2k^2 + 2k) + 1.$$
$2(2k^2 + 2k)$ çifttir. "Çift artı bir tektir" olduğu için $n^2$ tektir.

### 10.2 Yapıcı İspat

Birçok teorem belirli türde bir nesnenin var olduğunu söyler. Bunu ispatlamanın bir yolu, böyle bir nesneyi kurmaktır. Bu tekniğe kurarak ispat (proof by construction) denir. "Vardır" diyen genel bir ifadede tek bir örnek bulmak ispat için yeterlidir.

**Teorem:** $q$ ve $r$ irrasyonel olmak üzere $p = q^r$ biçiminde yazılabilen rasyonel bir $p$ sayısı vardır.

**İspat:** $q = \sqrt{2}^{\sqrt{2}}$ ve $r = \sqrt{2}$ seçilir. Bu durumda
$$q^r = \left(\sqrt{2}^{\sqrt{2}}\right)^{\sqrt{2}} = \sqrt{2}^{\sqrt{2}\cdot\sqrt{2}} = \sqrt{2}^{2} = 2 \quad \text{(ara adım eklendi)}.$$
$2 = 2/1$ rasyoneldir, teorem ispatlanmıştır. Hoca, bu sayıların çok iyi seçildiğini, sayılar konusunda (rasyonel, irrasyonel, tamsayı, gerçel) iyi bir altyapı olmadan böyle zarif seçimler yapılamayacağını vurguladı.

> **Ders sonrası not:** Hoca "irrasyonel üssü irrasyonel elbette irrasyoneldir" dedi. Bu genel olarak doğru değildir; bir sonraki teorem tam olarak bunun tersine bir örneğin varlığını gösterir. Bu ispatın geçerli olması için $\sqrt{2}^{\sqrt{2}}$'nin irrasyonel olduğunu ayrıca bilmek gerekir.

> **Ek bilgi (derste anlatılmadı):** $\sqrt{2}^{\sqrt{2}}$'nin irrasyonel (hatta aşkın) olduğu Gelfond-Schneider teoreminden çıkar. Bu, basit bir hesapla gösterilebilecek bir sonuç değildir.

### 10.3 Yapıcı Olmayan İspat

Yapıcı olmayan ispatta belirli bir nesnenin var olduğu, o nesne kurulmadan gösterilir (ekrandan, 01:45:00).

**Teorem:** $x^y$ rasyonel olacak biçimde irrasyonel $x$ ve $y$ sayıları vardır.

**İspat:** İki durum vardır.

- Durum 1: $\sqrt{2}^{\sqrt{2}}$ rasyoneldir. Bu durumda $x = y = \sqrt{2}$ alınır; $\sqrt{2}$'nin irrasyonel olduğu bir sonraki teoremde ispatlanacaktır.
- Durum 2: $\sqrt{2}^{\sqrt{2}}$ rasyonel değildir. Bu durumda $x = \sqrt{2}^{\sqrt{2}}$ ve $y = \sqrt{2}$ alınır. $x^y = \sqrt{2}^{2} = 2$ rasyoneldir.

Her iki durumda da teoremin iddiası sağlanır. İspat teoremi kanıtlar, ama $x^y$'nin rasyonel olduğu somut bir irrasyonel $(x, y)$ çifti vermez; hangi durumun geçerli olduğunu söylemez.

> **Ders sonrası not:** Slaytta üs işareti kaybolmuş, teoremde "xy" ve Durum 1'de "$\sqrt{2} \in Q$" yazıyor. Hoca anlatırken slaytta bir yanlış olduğunu fark etti. Doğrusu yukarıdaki gibi $x^y$ ve "$\sqrt{2}^{\sqrt{2}} \in \mathbb{Q}$" olmalıdır.

### 10.4 Olmayana Ergi

Olmayana ergi (proof by contradiction), bir önermenin ya doğru ya yanlış olduğu, aynı anda hem doğru hem yanlış olamayacağı gerçeğine dayanır. Teoremin yanlış olduğu varsayılır. Sonra bu varsayımın açıkça yanlış bir sonuca, yani bir çelişkiye götürdüğü gösterilir.

**Teorem:** $\sqrt{2}$ irrasyonel bir sayıdır.

**İspat** (ekrandan, 01:50:00):

- Çelişki elde etmek için $\sqrt{2}$'nin rasyonel olduğunu varsayalım. O zaman ortak çarpanı olmayan iki pozitif tamsayı $p$ ve $q$ için $\sqrt{2} = p/q$ yazılabilir. Ortak çarpan olsaydı sadeleştirilip aynı orana eşit yeni $p'/q'$ elde edilirdi; bu yüzden $p$ ve $q$'nun ortak çarpanı olmadığı kabul edilebilir.
- İki tarafın karesi alınır: $p^2/q^2 = 2$, yani $2q^2 = p^2$.
- $2q^2$ çift olduğu için $p^2$ de çifttir.
- Bu, $p$'nin çift olduğunu gösterir. Neden? Tek sayının karesi tektir; $p$ tek olsaydı $p^2$ de tek olurdu.
- O hâlde bir $r$ tamsayısı için $p = 2r$'dir ve $2q^2 = p^2 = (2r)^2 = 4r^2$ olur.
- Buradan $2r^2 = q^2$ çıkar, yani $q^2$ ve dolayısıyla $q$ da çifttir.
- Bir yanlışlık oldu: rasyonellik varsayımı gereği "$p$ ve $q$'nun ortak çarpanı yoktur", ama ikisi de çift olduğu için "$p$ ve $q$'nun ortak çarpanı 2'dir".
- Bu bir çelişkidir. Demek ki varsayım yanlıştır ve $\sqrt{2}$ irrasyoneldir.

### 10.5 Tümevarım

$P(n)$, $n$'ye bağlı bir matematiksel önerme olsun. İspat için önce önermenin $n = 1$ için doğru olduğu gösterilir (taban adımı). Hoca, $n = 2$ ve $n = 3$ için de denenebileceğini söyledi. Sonra $P(n+1)$, $P(n)$ cinsinden yazılır ve $P(n)$ doğruysa $P(n+1)$'in de doğru olduğu gösterilir. Böylece önerme bütün $n$ değerleri için doğrudur. Hoca bu tekniğin hesaplama kuramında da çok kullanılacağını söyledi.

**Teorem** (ekrandan, 01:55:00): Bütün pozitif $n$ tamsayıları için
$$1 + 2 + 3 + \dots + n = \frac{n(n+1)}{2}.$$

**İspat:**

- Taban: $n = 1$ için sol taraf 1'dir; sağ taraf $\frac{1 \cdot 2}{2} = 1$'dir. Hoca ayrıca $n = 2$ için $1 + 2 = 3$ ve $\frac{2 \cdot 3}{2} = 3$ olduğunu gösterdi.
- Tümevarım adımı: $n \ge 1$ için teoremin doğru olduğu, yani $1 + 2 + \dots + n = \frac{n(n+1)}{2}$ olduğu varsayılır. $n+1$ için
$$1 + 2 + \dots + n + (n+1) = \frac{n(n+1)}{2} + (n+1) = \frac{(n+1)(n+2)}{2} \quad \text{(ara adım eklendi)}$$
elde edilir. Bu, formülün $n+1$ için de doğru olduğunu gösterir.

Formül ilk 200 değer için python ile de kontrol edildi.

### 10.6 Güvercin Yuvası İlkesi

$n+1$ nesneyi $n$ kutuya, her nesne bir kutuya girecek biçimde yerleştirmek istiyoruz. Bütün nesneler kutulara konulursa en az bir kutuda iki ya da daha fazla nesne bulunur. Kümelerle söylersek: $A$ ve $B$ kümeleri için $|A| > |B|$ ise $A$'dan $B$'ye bire bir (one-to-one) fonksiyon yoktur. Hocanın örneği: 3 güvercin yuvası ve 4 güvercin varsa yuvalardan en az birinde en az 2 güvercin olur.

**Teorem** (ekrandan, 02:00:00): $n$ pozitif bir tamsayı olsun. $n^2 + 1$ farklı gerçel sayıdan oluşan her dizi, $n + 1$ uzunluğunda artan ya da azalan bir alt dizi içerir.

**Örnek:** Slayttaki dizi $(19, 10, 9, 7, 11, 2, 21, 1, 20, 31)$'dir. $10 = 3^2 + 1$ sayı olduğu için $n = 3$ ve aranan alt dizi uzunluğu $n + 1 = 4$'tür.

- Artan alt diziler: slayttaki $(10, 11, 21, 31)$; hocanın derste bulduğu $(9, 11, 20, 31)$ ve $(9, 11, 21, 31)$.
- Azalan alt dizi: hocanın bulduğu $(19, 9, 7, 1)$.

Alt dizide elemanların sırası korunur ama ardışık olmaları gerekmez. Hoca bunu, sayıları sıralı kutulara yerleştirmeye benzetti. Bu alt diziler python ile kontrol edildi. Python'a göre bu dizideki en uzun artan alt dizi 4, en uzun azalan alt dizi 6 uzunluğundadır (örneğin $19, 10, 9, 7, 2, 1$).

Teoremin genel ispatı derste anlatılmadı; hoca slaytlardan okunmasını istedi.

> **Ek bilgi (derste anlatılmadı):** Bu teorem Erdős-Szekeres teoremi olarak bilinir. Klasik ispatta her elemana "o elemanla başlayan en uzun artan alt dizinin uzunluğu" etiketi verilir. Hiçbir artan alt dizi $n+1$ uzunluğunda değilse etiketler $1, \dots, n$ arasındadır. $n^2+1$ eleman $n$ etikete dağıtıldığı için güvercin yuvası ilkesine göre en az $n+1$ eleman aynı etiketi taşır. Aynı etiketli elemanlar soldan sağa azalan bir alt dizi oluşturur.

## 11. Alfabe, Sembol ve Dizgi

İkinci aradan sonra düzenli ifadeler (regular expressions) bölümüne geçildi. Hoca önce dil kavramıyla başladı: Türkçe, İngilizce, Arapça, Rusça gibi birçok dil vardır ve her birinin bir alfabesi vardır. Farklı bilgisayarların da farklı dilleri olduğu düşünülebilir.

Slayttaki tanımlar (ekrandan, 02:20:00):

- **Alfabe (alphabet):** Sonlu, boş olmayan bir sembol kümesidir. Alfabenin elemanlarına o alfabenin sembolleri (symbols) denir. Alfabeleri göstermek için genelde büyük Yunan harfleri $\Sigma$ (sigma) ve $\Gamma$ (gama) kullanılır. Örnekler:
  - $\Sigma_1 = \{0, 1\}$ (ikili alfabe)
  - $\Sigma_2 = \{a, b, c, \dots, z\}$ (İngilizcedeki harfler)
  - $\Gamma = \{0, 1, x, y, z\}$
- **Dizgi (string):** Bir alfabe üzerindeki dizgi, o alfabeden alınan sembollerin sonlu bir dizisidir. Semboller genelde yan yana, virgülsüz yazılır. $\Sigma_1 = \{0,1\}$ ise $01101$, $\Sigma_1$ üzerinde bir dizgidir. $\Sigma_2 = \{a, \dots, z\}$ ise abracadabra, $\Sigma_2$ üzerinde bir dizgidir.

Hoca, $\Sigma_2$'den c, a, r sembolleri kullanılarak "car" dizgisinin, $\Gamma$'dan da "x01yz" gibi dizgilerin üretilebileceğini gösterdi. Alfabe, dizgileri kurmak için kullanılan sembollerdir.

- **Uzunluk:** $w$, $\Sigma$ üzerinde bir dizgiyse $w$'nin uzunluğu $|w|$ ile gösterilir ve $w$'deki sembol sayısıdır.
- **Boş dizgi:** Uzunluğu 0 olan dizgidir ve $\varepsilon$ ile gösterilir.
- $|w| = n$ ise $w = w_1 w_2 \cdots w_n$ yazılabilir; her $w_i$ bir semboldür. Alfabedeki tek bir sembol de kendi başına bir dizgidir. Örneğin $0$ hem $\Sigma_1$'in bir sembolü hem de uzunluğu 1 olan bir dizgidir.
- **Ters çevirme:** $w = w_1 w_2 \cdots w_n$ ise $w^R = w_n w_{n-1} \cdots w_2 w_1$. Sembollerin sırası tersine döner.
- **Alt dizgi:** $z$, $w$'nin içinde ardışık olarak görünüyorsa $z$, $w$'nin alt dizgisidir. Örneğin "cad", "abracadabra"nın alt dizgisidir.

> **Hocanın vurgusu:** $R$ üst simgesini yalnız ters çevirme işlemi için kullanın. Bu gösterimi ezberlemeniz ve hesaplama kuramındaki işlemlerde ve ispatlarda bu anlamda kullanmanız gerekir.

Hoca, alfabe olarak $\Sigma = \{0, 1, \dots, 9\}$ ve $\Sigma = \{0, 1\}$ örneklerini de gösterdi (ekrandan, 02:35:00). Ondalık alfabeden $102345$ ve $567463386$, ikili alfabeden $100010001$ ve $101101111$ gibi dizgiler üretilebilir. Tek sembollü $\Sigma = \{1\}$ alfabesinden de $1$, $11$, $111111$ gibi dizgiler üretilir. Bunlar sırasıyla 1, 2 ve 6 sayılarını gösterir; ilkokulda abaküste boncuk saymaya benzer. Hocanın ifadesiyle hesaplama kuramı bir anlamda birleri saymaktır. İşlemcilerde de hızlı hesap için birlerin sayısı üzerinde çalışan otomatlar tasarlanır.

## 12. Dil ve Düzenli Diller

**Dil (language):** Bir alfabe üzerinde tanımlanmış dizgilerin kümesidir (ekrandan, 02:25:00). Dildeki dizgi sayısı sonlu ya da sonsuz olabilir. Diller hesaplama problemlerini tanımlamak için kullanılır. Örneğin Java dilinde `if`, `else`, `while`, `for`, `class`, `int`, `double`, `byte`, `float`, `long` gibi belirli dizgiler vardır. Bu dizgilerin hepsi birlikte Java için bir dil oluşturur.

> **Hocanın vurgusu:** Dil, aynı alfabe üzerinde tanımlanmış bir dizgi kümesidir. Dil bir kümedir.

**Düzenli diller (regular languages)** (ekrandan, 02:30:00):

- Bütün dillerin bir alt kümesidir. Slayta göre düzenli kümeyi doğrudan tanımlamanın bir yolu yoktur, ama bir kümenin düzenli olup olmadığını söylemek mümkündür.
- En iyi yol sonlu otomat kullanmaktır: bir sonlu otomat dili tanıyorsa dil düzenlidir. Hocanın örneğiyle, bir bilgisayar için yazılan yazılımdaki her ifadeyi makine tanıyabilmelidir. Bir sonlu otomat dildeki bütün dizgileri tanıyorsa bu dil düzenli bir dildir.
- Düzenli kümeleri kurmak için düzenli (küme) işlemler kullanılır: birleşim, birleştirme ve Kleene yıldızı.
  - Birleşim: $A \cup B = \{x \mid x \in A \text{ veya } x \in B\}$.
  - Birleştirme: $A \circ B = \{xy \mid x \in A \text{ ve } y \in B\}$.
  - Yıldız: $A^* = \{x_1 x_2 \dots x_k \mid k \ge 0 \text{ ve her } x_i \in A\}$.

> **Ders sonrası not:** Slayttaki yıldız tanımında "$k > 0$" yazıyor. Sipser'deki tanımda $k \ge 0$'dır; $k = 0$ durumu boş dizgiyi verir ve $\varepsilon$ her zaman $A^*$'ın elemanıdır. Hocanın daha sonra verdiği $\{a,b\}^* = \{\varepsilon, a, b, \dots\}$ örneği de bununla uyumludur.

Hoca, $A$ ve $B$ dizgi kümeleri (dil) ise birleşimlerinin de bir dizgi kümesi, yani bir dil olduğunu anlattı. İki dil birleştirildiğinde $A$'daki ve $B$'deki dizgiler uç uca eklenir. Örneğin $A$'da "bi", $B$'de "cycle" varsa birleştirmede "bicycle" çıkar. Yıldız işlemi ise dildeki dizgilerin bütün olası birleştirmelerini verir.

**Kapalılık özellikleri:**

- Düzenli diller kesişim altında kapalıdır: iki düzenli dilin kesişimi yine bir otomatın kabul ettiği düzenli bir dildir.
- Tümleyen altında kapalıdır: bir düzenli dilin tümleyeni de bir otomatla tanınabilir.
- Birleştirme (Türkçede "kaskat bağlama") altında kapalıdır.
- Kleene yıldızı altında kapalıdır. Hocanın gerekçesine göre yıldız, birleştirmenin bir genellemesidir; birleştirme kapalıysa yıldız da kapalı olur.

## 13. Dizgi İşlemleri: Birleştirme, Ters Çevirme, Önek ve Sonek

Hoca, $\Sigma = \{a, b\}$ alfabesinden $ab$, $abba$ gibi dizgiler üretilebileceğini ve dizgilerin genelde küçük harflerle ($u$, $v$, $w$) gösterildiğini anlattı.

**Birleştirme (concatenation)** (ekrandan, 02:25:00): $x$, uzunluğu $m$ olan, $y$ uzunluğu $n$ olan bir dizgi ise $x$ ile $y$'nin birleştirmesi $xy$ diye yazılır ve $y$'nin $x$'in sonuna eklenmesiyle elde edilir: $x_1 \dots x_m y_1 \dots y_n$.

Hocanın örneğinde $w = a_1 a_2 \dots a_n$ ve $v = b_1 b_2 \dots b_m$, $a, b \in \{x, y\}$ idi. $w = xyyxy$ alındı.

- $|w| = 5$, $|v| = 6$ ve birleştirmenin uzunluğu bireysel uzunlukların toplamıdır: $|wv| = |w| + |v| = 5 + 6 = 11$. <!-- BELİRSİZ: v dizgisinin harfleri karelerde görünmüyor, altyazıda bozuk. -->
- Ters çevirmede sıra soldan sağa yerine sağdan sola okunur: $w^R = yxyyx$ (ara adım eklendi; altyazıdaki okuma bozuk).

**Önek ve sonek** (ekrandan, 02:40:00):

- Dizginin her sembolü ($a_1, a_2, \dots, a_n$) onun alt dizgisidir.
- $a_1,\ a_1a_2,\ a_1a_2a_3, \dots$ önek (prefix) alt dizgileridir.
- $a_2,\ a_2a_3,\ a_2a_3a_4, \dots$ de alt dizgilerdir.
- $a_n,\ a_{n-1}a_n,\ a_{n-2}a_{n-1}a_n, \dots$ sonek (suffix) alt dizgileridir.
- $w = xyyxy$ için $x, xy, xyy, xyyx, xyyxy$ öneklerdir; $y, xy, yxy, yyxy, xyyxy$ soneklerdir.
- Özel durumlar: $\varepsilon$ her dizginin hem öneki hem sonekidir. Her dizgi kendisinin hem öneki hem sonekidir.

Boş dizgi bir dizgiyi değiştirmez: $\varepsilon w = w \varepsilon = w$. Hoca, boş dizginin kuram ve ispatlarda sıkça tercih edildiğini söyledi.

## 14. Kuvvet, Yıldız ve Artı İşlemleri

**Kuvvet:** Bir dizgiyi kendisiyle birçok kez birleştirmek için üst simge gösterimi kullanılır: $x^3 = xxx$, $x^n = xx \dots x$ ($n$ kez). Örneğin $x = 0$ ise $x^3 = 000$; $x = 01$ ise $x^3 = 010101$. Aynı biçimde $w^2 = ww$, $w^3 = www$'dir.

> **Hocanın vurgusu:** Dizgilerde kuvvet çarpma değil, birleştirme sayısıdır. Bu gösterimden emin olmanız gerekir; teoremlerde ve ispatlarda bu anlamda kullanılacak.

> **Ek bilgi (derste anlatılmadı):** Hoca $w^0$'ı sordu ama cevap altyazıda anlaşılmıyor. Tanım gereği $w^0 = \varepsilon$'dur: sıfır kez birleştirme boş dizgiyi verir.

**Kleene yıldızı:** Bütün olası tekrarları göstermek için özel bir işlem kullanılır: $*$ (Kleene star). Bir dizgiye yıldız uygulanınca bir küme elde edilir: $w^* = \{\varepsilon, w, w^2, w^3, \dots\}$, yani $w$'nin bütün olası birleştirmeleri. $w^*$ bir dizgi kümesidir, dolayısıyla bir dildir.

Yıldız işlemi alfabeye de uygulanabilir. Bu durumda alfabedeki sembollerin bütün olası birleştirmeleri elde edilir:
$$\{a, b\}^* = \{\varepsilon, a, b, aa, ab, ba, bb, aaa, aab, \dots\}.$$
Hiç birleştirme yoksa boş dizgi, sonra tek semboller, ikili birleştirmeler, üçlü birleştirmeler vb. gelir.

**Artı işlemi:** $\Sigma^+ = \Sigma^* - \{\varepsilon\}$. Yani $\Sigma^+$, yıldız işleminin boş dizgi çıkarılmış hâlidir. $\Sigma^+$'da $\varepsilon$ yoktur, $\Sigma^*$'da vardır.

## 15. Dil Örnekleri ve İşlemlerin Dil Olarak Yazılması

### 15.1 Her Dil $\Sigma^*$'ın Alt Kümesidir

$\Sigma = \{a, b\}$ alfabesi üzerindeki bir dil, $\Sigma^* = \{\varepsilon, a, b, aa, ab, ba, bb, aaa, aab, \dots\}$ kümesinin bir alt kümesidir (ekrandan, 02:45:00). Hoca, alfabeye yıldız uygulanınca o alfabenin "evrensel dili"nin elde edildiğini, o alfabeyle kurulan bütün dillerin bunun alt kümesi olduğunu söyledi. Örnekler:

- $L_1 = \{\varepsilon\}$: yalnız boş dizgiyi içerir. Bir dizgi kümesi olduğu için bir dildir.
- $L_2 = \{a, b, aa, ab, ba, bb\}$: 6 dizgi içerir.
- $L_3 = \{\varepsilon, a, aa, aaa, aaaa, \dots\}$: sonsuz sayıda dizgi içerir, boş dizgiyi de içerir.
- $L_4 = \{a^n b^n : n \ge 0\} = \{\varepsilon, ab, aabb, aaabbb, \dots\}$: $a$'ların sayısı $b$'lerin sayısına eşittir.

> **Ders sonrası not:** Slaytta $L_4$'ün açılımında "aaabbbb" yazıyor. $n = 3$ için doğrusu $aaabbb$'dir.

$\Sigma = \{0, 1, 2, \dots, 9\}$ alfabesi üzerinde:

- $\text{PRIME\_NUMBERS} = \{x \mid x \in \Sigma^* \text{ ve } x \text{ asaldır}\} = \{2, 3, 5, 7, 11, \dots\}$
- $\text{EVEN\_NUMBERS} = \{x \mid x \in \Sigma^* \text{ ve } x \text{ çifttir}\} = \{0, 2, 4, \dots\}$
- $\text{ODD\_NUMBERS} = \{x \mid x \in \Sigma^* \text{ ve } x \text{ tektir}\} = \{1, 3, 5, \dots\}$

> **Hocanın vurgusu:** Bunlar sayı değil semboldür. Alfabe her zaman sembollerden oluşur. "11" iki tane "1" sembolünün birleştirilmesidir; "on bir" diye değil "bir bir" diye okunmalıdır. "7" ile "11" birleştirilirse "711" ("yedi bir bir") elde edilir.

### 15.2 Birli Toplama ve Kare Alma

(ekrandan, 02:50:00)

**Birli toplama (unary addition):** Alfabe $\Sigma = \{1, +, =\}$. Burada $1$, $+$ ve $=$ birer semboldür.
$$\text{ADDITION} = \{x + y = z : x = 1^m,\ y = 1^n,\ z = 1^k,\ k = m + n\}.$$

- $111 + 11 = 11111 \in \text{ADDITION}$ ($3 + 2 = 5$)
- $111 + 111 = 1111 \notin \text{ADDITION}$ ($3 + 3 \neq 4$)

**Kare alma (squaring):** Alfabe $\Sigma = \{1, \#\}$.
$$\text{SQUARES} = \{x \# y : x = 1^m,\ y = 1^n,\ n = m^2\}.$$

- $111\#111111111 \in \text{SQUARES}$ ($m = 3$, $n = 9 = 3^2$)
- $1111\#11111111 \notin \text{SQUARES}$ ($m = 4$, $n = 8 \neq 16$)

Sembol sayıları python ile kontrol edildi.

> **Hocanın vurgusu:** Burada matematiksel bir işlem yapılmıyor. "111+11=11111" baştan sona tek bir dizgidir; kâğıda yazdığımız semboller gibidir. ADDITION kümesi yalnız bu dizgilerin kümeye ait olup olmadığını belirler. Böylece bir toplamanın doğru mu yanlış mı yapıldığı yalnız semboller kullanılarak anlaşılabilir. Hocaya göre bir hesaplayıcıyla konuşmak tam olarak budur.

## 16. Diller Üzerinde Küme İşlemleri; Boş Küme ve Boş Dizgi

Diller dizgi kümeleri olduğu için bütün küme işlemleri dillere uygulanabilir: birleşim, kesişim, fark ve tümleyen. Her işlemin sonucu yine bir dizgi kümesi, yani bir dildir. Slayt (ekrandan, 02:55:00), düzenli kümelerin birleşim, kesişim ve tümleyen altında kapalı olduğunu söylüyordu. Örnek:

- $A = \{a, ab, aaaa\}$, $B = \{ab, bb\}$
- $A \cup B = \{a, ab, bb, aaaa\}$
- $A \cap B = \{ab\}$
- $A - B = \{a, aaaa\}$
- $\overline{A} = \Sigma^* - A = \{\varepsilon, b, aa, ba, bb, aba, \dots\}$

Tümleyen, harfin üzerine çizilen tek bir çizgiyle ($\overline{A}$) gösterilir. Hoca slayttaki çizginin yanlış yerde durduğunu fark edip düzeltti.

> **Ders sonrası not:** Slaytta $A - B = \{a, bb, aaaa\}$ yazıyor. $bb \notin A$ olduğu için doğrusu $A - B = \{a, aaaa\}$'dır (python ile kontrol edildi). Slayttaki tümleyen listesinde $b$ görünmüyor; $b \notin A$ olduğu için $b \in \overline{A}$'dır.

**Boş küme ve boş dizgi:**

- $\emptyset = \{\} \neq \{\varepsilon\}$. Boş küme, boş dizgiyi içeren kümeye eşit değildir.
- $|\emptyset| = |\{\}| = 0 \neq |\{\varepsilon\}|$.
- $|\{\varepsilon\}| = 1$: bu bir küme büyüklüğüdür (kümede bir eleman var, o da boş dizgi).
- $|\varepsilon| = 0$: bu bir dizgi uzunluğudur.

> **Hocanın vurgusu:** Bu gösterimleri karıştırmayın. Hoca, sınavlarda büyük olasılıkla çoğu öğrencinin bunları karıştıracağını söyledi ve bu ifadelerin arkasındaki kavramı iyice anlamayı önerdi.

## 17. Sonlu Otomata İlk Bakış

Dersin sonunda hoca sonlu otomatı kısaca tanıttı (ekrandan, 03:00:00). Giriş şeridinde (input tape) bir dizgi vardır. Sonlu otomat bu dizgiyi okur ve çıktı olarak "kabul" (accept) ya da "ret" (reject) verir. Dizgi dilin elemanıysa otomat bunu algılar ve dizgiyi kabul eder; çünkü dil bir dizgi kümesidir.

Ardından bir örnek otomat gösterildi. Otomatın durumları ($q_0$, $q_1$, ...) vardır ve her girdi sembolüyle durum değişir. Örneğin $q_0$'dayken girdi sembolü $a$ ise $q_1$'e geçilir. Başka bir durumdan $b$ ile $q_5$'e, $a$ ile $q_4$'e gidilir; $q_4$ kabul (final) durumudur. Girdi dizgisi tamamen okunduğunda son durum kabul durumuysa (çizimde iki halkayla gösterilen durum) girdi dizgisi tanınmış olur. Ayrıntılar bir sonraki derse bırakıldı. <!-- BELİRSİZ: örnek otomatın diyagramı karelerde görünmüyor; geçişlerin tamamı ve hangi durumdan q4/q5'e gidildiği altyazıdan kesin çıkmıyor. -->

Hoca son olarak terimlere dikkat çekti: "automaton" tekil, "automata" çoğuldur; tıpkı "datum" tekil, "data" çoğul olduğu gibi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:21:14): Ekrandaki düzeneklerden (abaküs, mekanik hesap makinesi, otomat, süper bilgisayar vb.) hangisi bilgisayardır?

> **Cevap (derste verildi):** Hepsi. Bilgisayar, hesap yapan bir makinedir; hesap yapan her düzenek bir hesaplayıcıdır.

**Soru 2** (derste sözlü, 01:32:49): Teori (theory) ile teorem (theorem) arasındaki fark nedir?

> **Çözüm (derste verilmedi):** Teorem, aksiyomlardan ve daha önce ispatlanmış önermelerden mantıksal adımlarla ispatlanmış tek bir matematiksel önermedir; örneğin "$\sqrt{2}$ irrasyoneldir". Teori ise bir konu alanını oluşturan tanımlar, aksiyomlar ve teoremlerin bütünüdür; örneğin "kümeler kuramı" ya da "hesaplama kuramı". Derste ayrıca hipotezin ispatlanınca teorem olduğu söylendi.

**Soru 3** (ekrandan, 01:40:00): $n$ tek pozitif bir tamsayı ise $n^2$'nin de tek olduğunu ispatlayın.

> **Çözüm (derste verildi):** $n = 2k+1$ ($k \ge 0$) yazılır. $n^2 = 4k^2 + 4k + 1 = 2(2k^2+2k) + 1$. $2(2k^2+2k)$ çift olduğu için $n^2$ tektir.

**Soru 4** (ekrandan, 01:45:00): $x^y$ rasyonel olacak biçimde irrasyonel $x$ ve $y$ sayılarının var olduğunu gösterin.

> **Çözüm (derste verildi):** $\sqrt{2}^{\sqrt{2}}$ rasyonelse $x = y = \sqrt{2}$ alınır. Değilse $x = \sqrt{2}^{\sqrt{2}}$, $y = \sqrt{2}$ alınır ve $x^y = \sqrt{2}^2 = 2$ olur. İki durumda da iddia sağlanır.

**Soru 5** (ekrandan, 01:50:00): $\sqrt{2}$'nin irrasyonel olduğunu olmayana ergi ile ispatlayın.

> **Çözüm (derste verildi):** Ortak çarpanı olmayan $p, q$ için $\sqrt{2} = p/q$ varsayılır. $2q^2 = p^2$ olduğundan $p$ çifttir, $p = 2r$. Buradan $q^2 = 2r^2$ ve $q$ da çifttir. $p$ ve $q$'nun ortak çarpanı 2 çıkar; bu varsayımla çelişir.

**Soru 6** (ekrandan, 01:55:00): Bütün pozitif $n$ tamsayıları için $1 + 2 + \dots + n = \frac{n(n+1)}{2}$ olduğunu tümevarımla ispatlayın.

> **Çözüm (derste verildi):** Taban: $n = 1$ için iki taraf da 1'dir. Adım: formül $n$ için doğruysa $\frac{n(n+1)}{2} + (n+1) = \frac{(n+1)(n+2)}{2}$ olur; formül $n+1$ için de doğrudur.

**Soru 7** (ekrandan, 02:00:00): $(19, 10, 9, 7, 11, 2, 21, 1, 20, 31)$ dizisinde, $n^2+1$ teoremine göre bulunması gereken uzunlukta artan ya da azalan bir alt dizi bulun.

> **Çözüm (derste verildi):** Dizide $10 = 3^2 + 1$ eleman vardır, dolayısıyla $n = 3$ ve uzunluğu $n+1 = 4$ olan bir alt dizi aranır. Artan: $(10, 11, 21, 31)$ ya da $(9, 11, 20, 31)$. Azalan: $(19, 9, 7, 1)$. Python ile kontrol edildi.

**Soru 8** (ekrandan, 02:50:00): Aşağıdaki dizgilerden hangileri ilgili kümenin elemanıdır? $111+11=11111$ ve $111+111=1111$ (ADDITION); $111\#111111111$ ve $1111\#11111111$ (SQUARES).

> **Çözüm (derste verildi):** $111+11=11111 \in \text{ADDITION}$ ($3+2=5$), $111+111=1111 \notin \text{ADDITION}$ ($3+3 \neq 4$). $111\#111111111 \in \text{SQUARES}$ ($3^2 = 9$), $1111\#11111111 \notin \text{SQUARES}$ ($4^2 = 16 \neq 8$).

**Soru 9** (ekrandan, 02:55:00): $A = \{a, ab, aaaa\}$ ve $B = \{ab, bb\}$ için $A \cup B$, $A \cap B$, $A - B$ ve $\overline{A}$ kümelerini bulun.

> **Çözüm (derste verildi, fark düzeltildi):** $A \cup B = \{a, ab, bb, aaaa\}$, $A \cap B = \{ab\}$, $A - B = \{a, aaaa\}$ (slayttaki $\{a, bb, aaaa\}$ yanlış), $\overline{A} = \Sigma^* - A = \{\varepsilon, b, aa, ba, bb, aba, \dots\}$.

## Dersin Toparlaması

Bu ders hesaplama kuramına bir giriş oldu. Kuramın üç ana alanı (otomata, hesaplanabilirlik ve karmaşıklık) tanıtıldı. Bir problemin bir dizgi kümesi olarak gösterilebileceği ve problemi çözmenin "bu dizgi kümede mi?" sorusuna evet ya da hayır diyebilmek olduğu anlatıldı. Hesap yapan her düzeneğin, domino devresi bile olsa, bir hesaplayıcı olduğu vurgulandı. Ardından kuramın ihtiyaç duyduğu matematiksel altyapı tekrar edildi: kümeler, bağıntılar, fonksiyonlar, Boole mantığı ve beş ispat tekniği (doğrudan, yapıcı, yapıcı olmayan, olmayana ergi, tümevarım) ile güvercin yuvası ilkesi.

Son bölümde dersin asıl dili kuruldu: alfabe, dizgi, uzunluk, boş dizgi, ters çevirme, alt dizgi, önek ve sonek; birleştirme, kuvvet, yıldız ve artı işlemleri; dilin $\Sigma^*$'ın bir alt kümesi olması; düzenli dillerin sonlu otomatlarla tanınması ve kapalılık özellikleri. Toplama ve kare alma gibi işlemlerin bile birer dil olarak yazılabileceği gösterildi. Ders, giriş dizgisini kabul ya da ret eden sonlu otomata kısa bir bakışla bitti. Hoca, sonlu otomatların ayrıntılarının bir sonraki derste işleneceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
