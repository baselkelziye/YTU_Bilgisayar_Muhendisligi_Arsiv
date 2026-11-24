# Ders 1 Genişletilmiş Notu: Ayrık Matematiğe Giriş ve Önermeler Mantığı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin kapsamı ve kaynaklar
- 2. Ayrık matematik nedir?
- 3. Ayrık matematikle çözülen problem türleri
- 4. Örnek problemler: atama, planlama (PERT) ve eşleştirme
- 5. Mantık ve önermeler
- 6. Birleştiriciler ve doğruluk tabloları
- 7. Şartlı önerme ve mantıksal denklik
- 8. Converse, inverse ve contrapositive
- 9. Çift yönlü önerme, totoloji, çelişki ve De Morgan
- 10. Alıştırmalar
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin kapsamı ve kaynaklar

Ayrık matematik bilgisayar bilimlerinin teorik altyapısını veren, çok eski geçmişi olan bir derstir. Önceleri soyut matematik adıyla okutulmuştur. Bilgisayar mühendisliği elektrik-elektronik mühendisliğinden ayrıldıktan sonra, saf matematik bilgisinin bilgisayar bilimine uyarlanması ve matematiksel yöntemlerle algoritmalar arasında ilişki kurulması bu derse kalmıştır. Zamanla bu dersin içinden ayrı dersler doğmuştur: lojik devreler, hesaplama kuramı, olasılık ve istatistik, algoritma analizi ve veri yapıları. Bu ders hepsine bir giriş yapar. Öğrencinin az da olsa programlama bilgisi olduğu kabul edilir; amaç bu bilgiyi matematikle birleştirip algoritma bilgisini ileri taşımaktır.

Dönemin konu akışı şöyle anlatıldı:

- Giriş ve mantık konusu.
- Mantıkla doğrudan ilişkili Boole cebri ve kombinasyonel devreler (lojik devreler dersiyle birbirini tamamladığı için öne alındı).
- Genel matematik tekrarı ve sayı teorisi.
- Algoritmalar, algoritma karmaşıklığı ve asimptotik gösterim.
- Graf ve ağaç veri yapıları, kromatik polinomlar.
- Otomatlar, gramerler ve diller; sonlu durum makineleri (finite state machine).

Ana kaynak Kenneth H. Rosen'ın *Discrete Mathematics and Its Applications* kitabıdır; slaytların çoğu bu kitaba göre hazırlanmıştır. Kitaptaki olasılık-istatistik kısımları bu derste anlatılmaz. İkinci kaynak MIT OpenCourseWare'in *Mathematics for Computer Science* dersidir (ekrandan, 00:15:00). Aynı ders farklı üniversitelerde "Ayrık İşlemsel Yapılar" (Discrete Computational Structures), "Ayrık Yapılar" (Discrete Structures) ya da "Discrete Mathematics for Computer Science" gibi adlarla verilir; içeriklerin %80-90'ı ortaktır. Giriş slaytlarının kaynakları arasında Michaels ve Rosen'ın *Applications of Discrete Mathematics* kitabı ile bir "Ayrık İşlemsel Yapılar" ders notu da vardır (ekrandan, 00:50:00).

## 2. Ayrık matematik nedir?

Ayrık matematik (sonlu matematik), matematiğin ayrık yapılarıyla ilgilenen ve süreklilik içermeyen konularını kapsayan dalıdır. Hoca farkı sinyal örneğiyle anlattı (ekrandan, 00:20:00 ve 00:35:00).

Zamana bağlı değişen bir sinyal düşünelim. Bu sinyal zamanın her anında bir değere sahiptir; buna sürekli (continuous) sinyal denir ve $x(t)$ ile gösterilir. Bu sinyalden belirli aralıklarla örnek alınırsa, yani zaman açısından bir sınırlama getirilirse, yalnız belirli anlardaki değerler kalır. Bu ayrık (discrete) sinyaldir ve $x[n]$ ile gösterilir.

- Sürekli sinyalde değer sayısı sonsuzdur. Ayrık sinyalde örnek sayısı sonludur; neye göre sonlu olduğu bilgisayarın kapasitesine bağlıdır.
- Ayrık sinyalin her bir elemanının değeri de gerçekte sonsuz hassasiyetlidir. Fonksiyon biliniyorsa (ör. $x(t)=2\sin t$) değer hesaplanabilir. Ama bir ölçüm sonucu ya da bir devrenin karakteristiği üzerinde çalışılıyorsa o anın değeri tam bulunamayabilir. Ayrık sistemde bir kabul yapılır ve değer, gösterilebilecek en yakın değere yuvarlanarak saklanır.
- Sürekli olan doğadadır (in nature); ayrık olan bilgisayarda (in computer) saklanır.

Doğadaki bir işareti incelerken sürekli matematikten yararlanılır. Bilgisayarda ise ayrık matematik devreye girer. Örneğin bir fonksiyonun türevi analitik olarak alınabilir; ama elde yalnız veri varsa ya önce bu veriden bir fonksiyon üretilir ya da sayısal analiz ve ayrık matematik teknikleriyle türev hesaplanır.

Kısacası sürekli matematik sürekli nesnelerle, ayrık matematik ayrık nesnelerle ilgilenir. Ayrık nesne örnekleri:

- Tam sayılar.
- Bir bilgisayar programının yürüttüğü işlem adımları, yani algoritma.
- Bir haritada A noktasından B noktasına giden farklı yollar.

## 3. Ayrık matematikle çözülen problem türleri

Slaytta ayrık matematikle çözülen problem türleri listelendi (ekrandan, 00:25:00):

- Belirli kurallara göre bir şifre kaç yolla seçilebilir?
- Kaç tane geçerli İnternet adresi olabilir?
- Belirli bir piyangoyu kazanma olasılığı nedir?
- Bir ağdaki iki bilgisayar arasında bağlantı var mı?
- İstenmeyen e-posta mesajlarını nasıl tanımlayabiliriz?
- Bir mesajı, istenmeyen bir alıcının okuması için nasıl şifreleyebiliriz?
- İki tamsayıyı toplayan bir devreyi nasıl kurabiliriz?
- Bir ulaşım sistemi kullanarak iki şehir arasındaki en kısa yol nasıl bulunur?
- Bir grup şehirden her birini yalnızca bir kez ziyaret eden ve turu başlangıç şehrinde bitiren en kısa tur nasıl bulunur?
- Bir bilgisayarın mantık yürütebilmesi için cümleleri nasıl temsil edebiliriz?
- Sonsuz sayıda asal sayı olduğunu nasıl kanıtlayabiliriz?
- Bir tamsayı listesi, tamsayıların artan sırada olması için nasıl sıralanabilir? Böyle bir sıralama kaç adım gerektirir?
- Bir sıralama algoritmasının bir listeyi her zaman doğru sıraladığı nasıl kanıtlanabilir?

Hoca bunlardan bazılarını açtı:

- **Şifre:** "Büyük harfle başlasın, rakam ve özel sembol içersin" gibi kurallarla kaç farklı şifre oluşturulabileceği bir sayma problemidir. Hoca bunu bir permütasyon problemi olarak ele aldı; değişkenler karakter kümesi ve şifrenin hane sayısıdır (bkz. Örnek Sorular).
- **İnternet adresi:** IP adresleri 192.168.10.0 gibi dört sayıdan oluşur; bunlarla kaç farklı adres yazılabileceği sorulur.
- **Bağlantı:** `ping` atıldığında arka planda paket yönlendirme vardır. İki bilgisayar, iki şehir ya da iki ülke arasında bağlantı olup olmadığı aynı türden bir sorudur.
- **İstenmeyen e-posta (spam):** Sözcük tabanlı ve içerik tabanlı teknikler kullanılır.
- **Şifreleme:** Kriptoloji bu dersten türeyen ayrı bir alandır.

### 3.1 Gezgin satıcı problemi

Bir grup şehrin her birini bir kez ziyaret edip başlangıca dönen en kısa tur aranıyor. Hoca dört şehirle örnek verdi: A, B, C, D (ekrandan, 00:35:00). Önce şehirlerin topolojisi, yani hangi şehirden hangisine yol olduğu bilinmelidir. A'dan başlayıp A'da biten turlar ABCDA, ACBDA, ACDBA gibi sıralanır. B, C, D üç şehrin sıralaması $3!=6$ farklı durum verir. Her turun maliyeti yazılır ve en az maliyetli olan seçilir.

Şehir sayısı küçükse bu kolaydır. Ama 81 il için İstanbul'dan başlayıp İstanbul'a dönülecekse geri kalan 80 il için $80!$ farklı tur vardır. $80!\approx 7{,}2\times10^{118}$ durumu tek tek hesaplamak bugünkü bilgisayarlar için mümkün değildir. Bu yüzden bu tür problemlerde genetik algoritma ve karınca kolonisi algoritması gibi yapay zekâ yöntemleri kullanılır. Bu amaçla TSP (Travelling Salesman Problem) haritası denen hazır veri yapıları vardır: şehirler arası bağlantıları ve uzaklıkları tutar; coğrafi bilgi sistemlerinde kullanılır.

> **Ders sonrası not:** Yollar iki yönde aynı uzunluktaysa bir tur ile ters yönde dolaşılan turun maliyeti aynıdır. Büyük olasılıkla farklı maliyetli tur sayısı $(n-1)!/2$'dir: dört şehirde 3, 81 ilde $80!/2$. Hocanın verdiği 6 ve $80!$ yön ayrımı yapılarak sayılmıştır; sonuç (kaba kuvvetin imkânsızlığı) değişmez.

**Soru:** Böyle bir yöntemle bulunan rotanın gerçekten en kısa rota olduğu nasıl anlaşılır? Algoritma yanlış çalışıyor olabilir.
**Cevap:** Burada kesin çözüm mümkün değildir. Birkaç algoritma karşılaştırılır, en kısa sonucu veren seçilir ve sonuç literatürdeki çalışmalarla kıyaslanır. Bulunan sonuç kesin (mutlak) sonuç değil, optimal sonuçtur.

### 3.2 Kesin çözüm ve optimal çözüm

- **Kesin çözüm (exact solution):** Bütün durumların incelenip en iyisinin bulunmasıdır. TSP'de bütün permütasyonların maliyetini hesaplayıp en küçüğünü bulmaktır.
- **Optimal çözüm:** Kesin çözüme en yakın, makul ve kabul edilebilir çözümdür. Bütün durumları incelemek imkânsızsa, kabul edilebilir kriterlere ulaşılana kadar daha iyi bir çözüm aranır.

Hoca bunu aşı geliştirme süreciyle benzetti: virüsü tamamen yok eden kesin bir çözüm yerine farklı adaylar arasında fayda-zarar ve maliyet analizi yapılır, kabul edilebilir kriterlere ulaşan çözüm seçilir.

### 3.3 Dersin amaçları

- **Matematiksel akıl yürütme:** Gerçek dünya problemini ispatlarla ve matematiksel argümanlarla çözme becerisi. İspat yöntemleri anlatılacaktır.
- **Kombinatoryal analiz:** Farklı türdeki nesnelerin sayılması. Kümeler, permütasyonlar, bağıntılar, graflar, ağaçlar ve sonlu durum makineleri.
- **Algoritmik düşünme:** Bir problemin birden fazla çözüm yolu olabilir; hangisinin daha verimli olduğu incelenir.
- **Uygulamalar ve modelleme:** Bilinen bir problemi eldeki yapılarla modellemek. Haritadaki yollar bir graftır. Kimyada su molekülü ($H_2O$, bağlar arası açı yaklaşık $104{,}5^\circ$) de bir graf gibi gösterilebilir; kimyacılar ve biyologlar molekül yapısından benzerlik analizleri yapar. Problemin türü değişir, yapı aynı kalır.

Hocaya göre ayrık matematik bir geçiş (gateway) dersidir: lise matematiği, mantık ve ilk programlama bilgisi ile bilgisayar biliminin ileri konuları arasında köprü kurar. Bilgisayar mimarisi, veri yapıları ve algoritmalar, programlama dilleri, derleyici ve yorumlayıcılar, bilgisayar güvenliği, veri tabanı ve yapay zekâ ayrık matematikle ilişkilidir. Kriptoloji dersinin büyük kısmı ayrık matematiktir. Matematikte graf teorisi, oyun teorisi, optimizasyon, sayılar ve kombinatorik; diğer disiplinlerde felsefe, ekonomi, dil bilim, görüntü ve ses işleme bu dersle bağ kurar.

Ayrık matematik, olası durumları sonlu olan problemlerin çözümüyle uğraşır. Problemler genel olarak üç gruba ayrılabilir (bu bir yorumdur, daha fazla gruba da ayrılabilir):

- **Varlık problemi:** Çözümün var olup olmadığı açık değildir. Önce çözüm var mı, varsa nasıl üretilir diye bakılır.
- **Sayma problemi (counting):** Çözümün varlığı bilinir, kaç tane olduğu sorulur.
- **Optimizasyon problemi:** Çözümler arasından en uygunu aranır.

## 4. Örnek problemler: atama, planlama (PERT) ve eşleştirme

Hoca giriş slaytlarındaki örnek problemleri gösterdi. Dört evli çiftle ilgili ilk soru bir varlık problemiydi; hoca bunu el sıkışma (handshake) probleminin bir uygulaması olarak tanıttı. <!-- BELİRSİZ: Dört evli çift sorusunun metni okunmadı ve karede görünmüyor. --> Altı kişilik bir yatırım kulübünde başkan ve sayman pozisyonlarının her yıl değiştirilmesi sorusu da sayma problemi olarak geçti (bkz. Örnek Sorular).

### 4.1 Atama problemi

Bir iş yerinde üç çalışan (Ali, Ayşe, Ahmet) sırasıyla 10, 12 ve 15 milyon saat ücreti alıyor. Patronun bu insanlara vereceği üç ayrı iş var. Tabloda her insanın her işi kaç saatte yapacağı gösteriliyor (ekrandan, 00:40:00):

| | Ali | Ayşe | Ahmet |
|---|---|---|---|
| İş 1 | 7,5 | 6 | 6,5 |
| İş 2 | 8 | 8,5 | 7 |
| İş 3 | 5 | 6,5 | 5,5 |

Patron toplamda en az ödeme yapacak şekilde her birine hangi işi vermelidir? Bu açıkça bir optimizasyon problemidir. Hoca bunun için Macar algoritması (Hungarian algorithm) adlı bir algoritma olduğunu söyledi ve ileride anlatacağını belirtti. Çözüm Örnek Sorular bölümündedir.

### 4.2 Planlama problemi ve PERT diyagramı

Bir şirket bayram için sekiz sayfalık bir ilan gönderecektir. İlanın bayramdan en az on gün önce postalanması gerekir; bunun için birçok iş yapılmalı ve bazı kararlar alınmalıdır. Elde yalnız 30 gün vardır. İşlerin süreleri toplanınca 37 gün çıkıyor. Soru: iş daha kısa sürede bitirilebilir mi?

Çözüm, eş zamanlılık ve boru hattı (pipeline) mantığıdır. Birbirine bağımlı olmayan işler aynı anda yapılırsa, örneğin aynı anda başlayan dört iş en uzunu kadar sürede biter. Bunun için hangi işin hangisine bağlı olduğu (ön koşul ilişkisi) uzman görüşüyle belirlenir; tıpkı derslerin ön koşulları gibi. Örneğin A ve B aynı anda yapılabilir, ama C için A ve B'nin bitmiş olması gerekir. Bütün işler harflerle gösterilip böyle bir öncelik grafı kurulur.

Slayttaki şekilde oklar soldan sağa doğru olduğu için çizilmez. Her düğüm bir daireyle gösterilir ve içine o işin süresi yazılır (ekrandan, 00:45:00). Düğümlerin yanındaki sayı, o işin en erken bitiş zamanıdır. Bir işin bitiş zamanı, öncüllerinin en büyük bitiş zamanına kendi süresinin eklenmesiyle bulunur:

| İş | Süre | Öncüller | Bitiş zamanı |
|---|---|---|---|
| A | 3 | - | 3 |
| B | 2 | - | 2 |
| C | 2 | A, B | $\max(3,2)+2=5$ |
| G | 3 | C | $5+3=8$ |
| D | 4 | C | $5+4=9$ |
| E | 3 | C | $5+3=8$ |
| H | 1 | G | $8+1=9$ |
| F | 2 | D, E | $\max(9,8)+2=11$ |
| I | 5 | F | $11+5=16$ |
| J | 2 | H, I | $\max(9,16)+2=18$ |
| K | 10 | J | $18+10=28$ |

Sonuçta K işi için toplam 28 gün bulunur, yani iş zamanında (30 günün içinde) yetişir. Bu tablo python ile yeniden hesaplanmış ve aynı sonuç alınmıştır.

**Kritik yol:** İşin tamamlandığı noktadan geriye doğru gidilir. K'nın bitmesi için J'nin bitmesi gerekir. J, H ve I'yı bekler; H 9'da çoktan bitmiştir, J'yi bekleten I'dır. I, F'yi bekler. F, D ve E'yi bekler; E 8'de bitmiştir, bekleten D'dir. D için C, C için A tamamlanmalıdır. Böylece kritik yol A, C, D, F, I, J, K olur. Bu yoldaki herhangi bir işin gecikmesi bütün projeyi geciktirir.

Bu yöntem PERT (Program Evaluation and Review Technique) diyagramı olarak bilinir. Büyük projelerde "projenin en zor parçası şu tarihte bitiyor" gibi planlamalar bu tür analizlerle yapılır. Benzer bir araç olan Gantt diyagramı sistem analizi dersinde anlatılacaktır; o da hangi işin ne zaman başlayıp biteceğini ve hangi işlerin eş zamanlı yürüyebileceğini gösterir. PERT'te ayrıca kritik yol ve maliyet analizi yapılabilir. Hoca bu grafın derste matris olarak da gösterileceğini belirtti.

### 4.3 Pilot-şehir eşleştirmesi

Bir hava yolunun pazartesi sabahları Ankara'dan yedi ayrı ülkeye uçuşu vardır. Yedi pilotun uçmak istedikleri yerlere göre bir liste hazırlanır. Mümkünse bütün pilotların isteğine uyulacak, değilse olabildiğince çok eşleşme yapılacaktır. Bu yapı iki taraflı graftır (bipartite graph): bir yanda uçuş yerleri, bir yanda pilotlar vardır. Pilotlar arasında ya da şehirler arasında bağlantı olmaz; kenarlar yalnız iki küme arasındadır. Doğrudan yaklaşımda her uçuşa bir pilot eşleyen bütün olası atamalar listelenir ve her biri isteklere uygunluk açısından sayılır.

Hoca giriş bölümünü şöyle bağladı: bu derste algoritma da matematik de vardır, kodlama da vardır; ama ağırlık kodlamadan çok problemin algoritmik, analiz ve tasarım tarafındadır.

## 5. Mantık ve önermeler

Mantık, doğru çıkarım elde etme çalışmasıdır (ekrandan, 01:05:00). Günlük hayatın bir parçasıdır; ama burada matematikte ve bilgisayar biliminde nasıl kullanıldığı incelenir.

- **Matematikte:** Teoremler mantık kurallarıyla ispat edilir. Bir şeyin varlığı da mantık kurallarıyla ispatlanır.
- **Bilgisayar biliminde:** Bir programın beklenen sonucu üretip üretmediğini incelemek ve `if`, `for` gibi yapıların içindeki koşul ifadelerini (conditional statement) yazmak mantığa dayanır.

Hoca varlık ispatına bir örnek olarak, $a^4+b^4+c^4=d^4$ eşitliğini sağlayan pozitif tam sayıların uzun süre bulunamadığını, bilgisayarlar gelişince böyle bir dörtlünün bulunduğunu anlattı; ifadenin tam biçiminden emin olmadığını da belirtti. Hocanın vurgusu şuydu: varlığı gösterilemeyen bir şey "yok kabul edilir", ama bu bir ispat değildir; bir örnek gösterildiğinde varlık ispatlanmış olur.

> **Ek bilgi (derste anlatılmadı):** Bu, Euler'in kuvvetler toplamı sanısıyla ilgili büyük olasılıkla doğru hatırlanan bir örnektir. Büyük olasılıkla 1988'de N. Elkies $2682440^4+15365639^4+18796760^4=20615673^4$ eşitliğini bulmuştur; bu eşitlik python ile doğrulanmıştır.

> **Ders sonrası not:** Hoca "bir şeyin yokluğu ispat edilmez" dedi. Matematikte yokluk da ispatlanabilir; örneğin $\sqrt{2}$'yi iki tam sayının oranı olarak yazan bir çiftin olmadığı çelişki yoluyla ispatlanır. Hocanın kastettiği, bir örneğin bulunamamış olmasının yokluğun ispatı sayılmayacağıdır.

### 5.1 Önerme

Sonucu doğru ya da yanlış olan, bir hüküm içeren ifadelere önerme (proposition) denir.

- "Bugün yağmur yağıyor": o an yağmıyorsa yanlıştır.
- "Dün yağmur yağdı": yağdıysa doğrudur.
- "Cüneyt bir programcıdır": bu kişinin programcı olup olmadığına dair bilgi varsa doğru ya da yanlış olduğu söylenebilir.

Doğruluk ya da yanlışlık içermeyen bir ifade (soru, emir gibi) önerme değildir. Derste doğru için 1, yanlış için 0 kullanılacaktır; slaytlarda T/F yazılsa da lojik devrelerde 0 ve 1 kullanılacağı için öğrencilerin bu gösterime şimdiden alışması istendi.

Önerme değişkenleri için matematikçiler ve mantıkçılar genelde $p, q, r, s, t$ kullanır. Bu bir alışkanlıktır; $A_1, A_2, \dots, A_n$ ya da $x, y, z$ de kullanılabilir. Lojik devreler kısmında $A_1, A_2, \dots$ gösterimi daha kullanışlıdır (ekrandan, 01:10:00).

## 6. Birleştiriciler ve doğruluk tabloları

Problemleri çözmek için kullanılan mantıksal ifadeler genellikle tek bir önermeden değil, önermelerin belirli kurallarla birleşiminden oluşur. En çok kullanılan birleştiriciler (connectives) şunlardır (ekrandan, 01:10:00):

| Birleştirici | Anlam | Sembol |
|---|---|---|
| Conjunction (AND) | ve | $\wedge$ |
| Inclusive disjunction (OR) | veya | $\vee$ |
| Exclusive disjunction (XOR) | ya ... ya da | $\underline{\vee}$ ya da $\oplus$ |
| Negation | değil | $\sim p$, $\neg p$, $p'$ ya da $\bar p$ |
| Implication | ise (if) | $\rightarrow$ |
| Double implication | ancak ve ancak (iff) | $\leftrightarrow$ |

XOR için bilgisayarcılar genelde daire içinde artı ($\oplus$) sembolünü kullanır. "If and only if" kısaca "iff" diye yazılır.

### 6.1 VE (conjunction)

VE bağlacı kümelerdeki kesişime (intersection) karşılık gelir. Hoca bunu bir elektrik devresiyle anlattı: bir üreteç, bir lamba ve seri bağlı iki anahtar $p$ ve $q$. Lambanın yanması için iki anahtarın da kapalı (iletimde) olması gerekir. İki şartın birlikte gerçekleşmesi VE ile ifade edilir (ekrandan, 01:15:00).

İki önermenin her biri iki değer alabildiği için $2\cdot2=4$ farklı durum vardır. Genel olarak $n$ değişkenli bir ifadenin doğruluk tablosunda $2^n$ satır bulunur. Bu derste genelde 2, 3, en fazla 4 değişken kullanılır.

| $p$ | $q$ | $p\wedge q$ |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

Kural: bütün girişler 1 ise sonuç 1, aksi hâlde 0. Beş değişken varsa beşi de doğru olmalıdır. Örnek: "Kaplan vahşi bir hayvandır" doğru, "Balina bir sürüngendir" yanlış; dolayısıyla $p\wedge q$ yanlıştır.

VE için temel özdeşlikler (derste soru-cevapla bulundu):

- $p\wedge 0=0$: bir giriş 0 ise sonuç doğrudan 0'dır.
- $p\wedge p=p$: sonuç $p$'ye göre değişir.
- $p\wedge p'=0$: biri mutlaka 0'dır.
- $p\wedge 1=p$ ve $p'\wedge 1=p'$.

### 6.2 VEYA (disjunction)

VEYA, şartlardan en az birinin doğru olması gerektiğinde kullanılır ve kümelerdeki birleşime karşılık gelir. Devrede paralel bağlı iki anahtardır: biri kapalıysa lamba yanar (ekrandan, 01:20:00).

| $p$ | $q$ | $p\vee q$ |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 1 |

Kural: iki giriş de 0 ise sonuç 0, diğer durumlarda 1. Lojik gösterimde $1+1=1$ yazılır, yani $1\vee1=1$. Özdeşlikler:

- $p\vee 1=1$: en az bir giriş 1'dir.
- $p\vee p=p$.
- $p\vee p'=1$.
- $p\vee 0=p$.

> **Ders sonrası not:** Derste bir an "$p$ ile 0'ın sonucu 0'dır" dendi. Bu VE için doğrudur ($p\wedge0=0$); VEYA için doğrusu $p\vee 0=p$'dir.

### 6.3 XOR (exclusive OR)

XOR'un Türkçe karşılığı "ya da"dır, kümelerdeki karşılığı simetrik farktır. "Ya Ali ya Mehmet" dendiğinde ikisinden yalnız biri kastedilir, ikisi birlikte değil. XOR kriptolojide çok kullanılır (ekrandan, 01:25:00).

| $p$ | $q$ | $p\oplus q$ |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

Kural: girişler aynıysa çıkış 0, farklıysa 1. Slayttaki örnek: $p$ = "Cüneyt programcıdır", $q$ = "Zeynep avukattır"; "Ne Cüneyt programcıdır ne de Zeynep avukattır" durumunda $p\oplus q$ yanlıştır.

Devrede XOR, iki konumlu iki anahtarla kurulur (S1 ve S2'nin 1 ve 0 uçları çapraz bağlanır). Elektrikçilerin vavien anahtar dediği, bir lambanın iki ayrı yerden açılıp kapatılmasını sağlayan bağlantıdır. <!-- BELİRSİZ: Anahtar devresinin çizimi karede kısmen okunuyor; bağlantının tam şekli altyazıdan net değil. -->

**XOR'u VE, VEYA, DEĞİL ile yazmak.** Tabloda sonucun 1 olduğu satırlar alınır: $p=1,q=0$ ve $p=0,q=1$. Böylece (ekrandan, 01:30:00):

$$p\oplus q=(p\wedge q')\vee(p'\wedge q)$$

Bir programlama dilinde XOR operatörü yoksa ya da kullanılması yasaklanmışsa bu açılım kullanılır. Hoca, yapısal programlama dersinde "bu soruyu XOR operatörü kullanmadan yapın" diye soru sorduğunu örnek verdi. Operatörlerin birbiri cinsinden yazılması bu dersin önemli konularındandır.

> **Ders sonrası not:** Hoca C'de XOR operatörü olup olmadığından emin olmadığını söyledi. C'de bit düzeyinde XOR operatörü (`^`) vardır, ama mantıksal XOR operatörü yoktur; mantıksal XOR için `(a && !b) || (!a && b)` ya da `!a != !b` yazılır.

**XOR özdeşlikleri.** VE ve VEYA gibi XOR da değişme özelliğine sahiptir: $(p'\wedge q)\vee(p\wedge q')=(p\wedge q')\vee(p'\wedge q)$, örneğin $0\vee1=1\vee0$.

- $p\oplus p'=1$: girişler her zaman farklıdır.
- $p\oplus p=0$: girişler her zaman aynıdır.
- $p\oplus 1=p'$: 0 ile 1 XOR'lanınca 1, 1 ile 1 XOR'lanınca 0 çıkar. Bu devirme (inversion) işlemidir.
- $p\oplus 0=p$: değer korunur. Hoca buna aynalama (mirror) dedi.

Kriptolojide bir anahtarın değilini hızlıca almak için anahtar bütün bitleri 1 olan bir diziyle XOR'lanır. Hocanın örneğinde anahtar $111000$ idi: $111000\oplus111111=000111$. Sonuç anahtarın bit bit tersidir (python ile doğrulandı).

### 6.4 DEĞİL (negation)

Verilen önerme doğruysa yanlışını, yanlışsa doğrusunu verir. $p$'nin tersi $\sim p$ ya da $p'$ ile gösterilir (ekrandan, 01:35:00). Bilgisayar bilimciler genelde $p'$ gösterimini kullanır.

- $p$: "Bugün cumadır." $p'$: "Bugün cuma değildir."

### 6.5 Birden fazla bağlaçlı ifadeler

Önermeler parantezlerle birleştirilir; örneğin $(p\vee q)\wedge r$ ya da $p'\vee q'$. Bu tür ifadelerin doğruluk tablosu lojik devreler dersinde de yapılacaktır.

**Tabloyu hızlı doldurma.** Üç değişken için $2^3=8$ satır vardır. Sütunlar ikilik sayının basamakları gibi düşünülür: en sağdaki sütun ($2^0$ basamağı) her satırda, ortadaki ($2^1$) ikişer satırda, en soldaki ($2^2$) dörder satırda değişir. Dördüncü bir değişken olsaydı sekizer satırda değişirdi. Satırlar sıfırdan başlayarak 0, 1, 2, ... sayılarının ikilik karşılığı gibi dizilir; ezbere gerek yoktur.

**$(p\vee q)\wedge r$ örneği.** Önce parantez içi hesaplanır. Ama VE bağlacı yüzünden $r=0$ olan bütün satırlar, parantez içine bakmadan doğrudan 0'dır. $r=1$ satırlarında sonuç $p\vee q$'ya eşittir; yalnız $p=q=0$ iken 0, diğerlerinde 1'dir.

| $p$ | $q$ | $r$ | $p\vee q$ | $(p\vee q)\wedge r$ |
|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 0 | 0 |
| 0 | 1 | 0 | 1 | 0 |
| 0 | 1 | 1 | 1 | 1 |
| 1 | 0 | 0 | 1 | 0 |
| 1 | 0 | 1 | 1 | 1 |
| 1 | 1 | 0 | 1 | 0 |
| 1 | 1 | 1 | 1 | 1 |

Doğruluk tablolarında genelde doğru (1) olan satırlar üzerinden işlem yapılır; diğerleri 0 kabul edilir. Lojik devrelerde bir de "don't care" (önemsiz) durumu vardır; bu derste yalnız adı geçti.

## 7. Şartlı önerme ve mantıksal denklik

### 7.1 Şartlı önerme

Şartlı önerme (conditional proposition) "if $p$ then $q$" şeklindedir ve $p\rightarrow q$ ile gösterilir (ekrandan, 01:40:00). $p$ gerçekleşmişse ve $q$ ona bağlı olarak gerçekleşecekse bunu ifade eder. Slayt örneği: $p$ = "Cüneyt programcıdır", $q$ = "Zeynep avukattır", $p\rightarrow q$ = "Cüneyt programcıysa Zeynep avukattır". İki önerme de doğruysa sonuç doğrudur.

| $p$ | $q$ | $p\rightarrow q$ |
|---|---|---|
| 0 | 0 | 1 |
| 0 | 1 | 1 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

Ezber için "1 ise 0 durumu 0, diğerleri 1" denir (ekrandan, 01:45:00). Bu doğrudur ama hoca anlamını bir seçim vaadiyle anlattı: "Seçimi kazanırsam şuraya park yapacağım."

- Kazandım ve park yaptım: vaat yerine geldi, doğru.
- Kazandım ama yapmadım: vaat bozuldu, yanlış.
- Kazanmadım ve yapmadım: şart gerçekleşmedi, vaat bozulmadı, doğru.
- Kazanmadım ama yine de yaptım: vaat bozulmadı, doğru.

Yani sonuç yalnız şart gerçekleşip ikinci şart gerçekleşmediğinde yanlıştır.

$\rightarrow$ bağlacının bir solunda bir sağında birer ifade vardır; bu ifadeler kendi içinde başka bağlaçlar içerebilir (ör. $(p\wedge q)\rightarrow r$).

### 7.2 Hipotez, sonuç, gerekli ve yeterli şart

$p\rightarrow q$ önermesinde $p$'ye hipotez (hypothesis, antecedent), $q$'ya sonuç (conclusion, consequent) denir. "$p$ only if $q$" ifadesi de aynı önermeyi anlatır.

- **Gerekli şart (necessary condition):** sonuç tarafından ifade edilir.
- **Yeterli şart (sufficient condition):** hipotez tarafından ifade edilir (ekrandan, 01:50:00).

"Cüneyt programcıysa Zeynep avukattır" önermesinde yeterli koşul Cüneyt'in programcı olması, gerekli koşul Zeynep'in avukat olmasıdır.

### 7.3 $p\rightarrow q$ ile $q\rightarrow p$ eşit mi?

Değildir. $p\rightarrow q$'nun tablosu simetrik değildir: $(1,0)$ satırında 0'dır. $q\rightarrow p$ ise $(0,1)$ satırında 0'dır. İki sütun aynı olmadığı için bu iki önerme mantıksal olarak denk değildir.

### 7.4 $p\rightarrow q$'yu VE, VEYA, DEĞİL ile yazmak

Temel bağlaçlar VE, VEYA ve DEĞİL'dir. $p\rightarrow q$'nun yalnız $p=1, q=0$ satırında 0 olduğunu biliyoruz. Bu satırı yok etmek için $p$'nin 1 olma durumu tersine çevrilip $q$ ile VEYA'lanır (ekrandan, 01:50:00):

| $p$ | $q$ | $p'$ | $p'\vee q$ | $p\rightarrow q$ |
|---|---|---|---|---|
| 0 | 0 | 1 | 1 | 1 |
| 0 | 1 | 1 | 1 | 1 |
| 1 | 0 | 0 | 0 | 0 |
| 1 | 1 | 0 | 1 | 1 |

$$p\rightarrow q\equiv p'\vee q$$

Kısaca: hipotezin değili alınır ve sonuçla VEYA'lanır.

> **Hocanın vurgusu:** $p\rightarrow q\equiv p'\vee q$ dönüşümünün bilinmesi gerekir; lojikte en çok bu biçim kullanılacaktır.

Bu açılımla birkaç özel durum:

- $p\rightarrow p\equiv p'\vee p=1$. Tek değişken vardır; $0\rightarrow0$ ve $1\rightarrow1$ satırlarının ikisi de 1'dir.
- $p\rightarrow p'\equiv p'\vee p'=p'$.
- $p\rightarrow 1=1$: sonuç her durumda 1 ise önerme doğrudan doğrudur.
- $p\rightarrow 0=p'$: $p=1$ iken $1\rightarrow0=0$, $p=0$ iken $0\rightarrow0=1$; ya da $p'\vee0=p'$.

### 7.5 Mantıksal denklik

Doğruluk tablosunda değerleri aynı olan iki önerme arasında mantıksal denklik (logical equivalence) vardır ve $\equiv$ ile gösterilir. Karşılaştırma aynı değişkenler üzerinden yapılır. Yukarıda $p\rightarrow q$ tanımından gelen sütun ile $p'\vee q$ sütunu birebir aynı olduğu için bu ikisi mantıksal olarak denktir.

## 8. Converse, inverse ve contrapositive

$p\rightarrow q$ ifadesinden üç ifade daha türetilir:

| Ad | Türkçe | İşlem | İfade |
|---|---|---|---|
| Converse | karşıt (yer değiştirme) | yerleri değiştirilir | $q\rightarrow p$ |
| Inverse | ters | değilleri alınır | $p'\rightarrow q'$ |
| Contrapositive | karşıt ters (devrik) | hem yer değiştirilir hem değilleri alınır | $q'\rightarrow p'$ |

**Örnek.** $p$: "Bugün cumartesi", $q$: "Yarın pazar". $p\rightarrow q$: "Bugün cumartesi ise yarın pazardır."

- Converse: "Yarın pazar ise bugün cumartesidir."
- Inverse: "Bugün cumartesi değilse yarın pazar değildir."
- Contrapositive: "Yarın pazar değilse bugün cumartesi değildir."

Bir öğrenci bu dönüşümlerin mantıksal denklik olup olmadığını sordu. Hoca bunların ifadelerin birbirine dönüştürülmesi olduğunu, mantıksal denkliğin ise doğruluk tablosuyla denetlenmesi gerektiğini söyledi. Tahtada $p\rightarrow q$ (1, 1, 0, 1) ile inverse $p'\rightarrow q'$ (1, 0, 1, 1) sütunlarını yazıp aynı çıkmadıklarını gösterdi. Slayttaki converse tablosu da aynı sonucu verir: $p\rightarrow q$ ile $q\rightarrow p$ arasında mantıksal denklik yoktur (ekrandan, 01:55:00).

| $p$ | $q$ | $p\rightarrow q$ | $q\rightarrow p$ | $p'\rightarrow q'$ | $q'\rightarrow p'$ |
|---|---|---|---|---|---|
| 0 | 0 | 1 | 1 | 1 | 1 |
| 0 | 1 | 1 | 0 | 0 | 1 |
| 1 | 0 | 0 | 1 | 1 | 0 |
| 1 | 1 | 1 | 1 | 1 | 1 |

> **Ek bilgi (derste anlatılmadı):** Son iki sütun derste yazılmadı, python ile hesaplandı. Tablodan görüldüğü gibi contrapositive $q'\rightarrow p'$, $p\rightarrow q$'ya mantıksal olarak denktir; converse ile inverse de birbirine denktir. Contrapositive ile ispat bu denkliğe dayanır.

> **Hocanın vurgusu:** Converse, inverse ve contrapositive'in sözel karşılıklarını bilmek önemlidir. Contrapositive ileride ispat yöntemlerinde kullanılacaktır.

## 9. Çift yönlü önerme, totoloji, çelişki ve De Morgan

### 9.1 Çift yönlü önerme

Çift yönlü önerme (biconditional proposition) "$p$ if and only if $q$" olarak tanımlanır ve $p\leftrightarrow q$ ile gösterilir (ekrandan, 02:05:00). Şartlı önermedeki "seçilemedim ama yine de yaptım, sonuç doğru" durumunu giderir: ancak ve ancak seçilirsem yaparım, seçilmezsem yapmam. Yalnız bu iki durum doğrudur.

| $p$ | $q$ | $p\leftrightarrow q$ | $(p\rightarrow q)\wedge(q\rightarrow p)$ |
|---|---|---|---|
| 0 | 0 | 1 | 1 |
| 0 | 1 | 0 | 0 |
| 1 | 0 | 0 | 0 |
| 1 | 1 | 1 | 1 |

XOR'un tersi gibi düşünülebilir: XOR'da girişler aynıysa 0, burada girişler aynıysa 1'dir. $p\leftrightarrow q$, $p\rightarrow q$ ile $q\rightarrow p$'nin VE ile birleştirilmiş hâlidir. VE, VEYA, DEĞİL ile:

$$p\leftrightarrow q\equiv(p'\vee q)\wedge(q'\vee p)$$

Tabloyu doldururken önce DEĞİL, sonra parantez içi, en son VE hesaplanır. Örneğin $p=q=1$ satırında: $p'\vee q=0\vee1=1$, $q'\vee p=0\vee1=1$, $1\wedge1=1$.

**XOR'un değili olduğunu gösterme.** $p\oplus q=(p'\wedge q)\vee(p\wedge q')$. Değili De Morgan ile alınırsa:

$$\big((p'\wedge q)\vee(p\wedge q')\big)'=(p\vee q')\wedge(p'\vee q)$$

Bu, yukarıdaki $p\leftrightarrow q$ açılımının aynısıdır. Hoca bunu tablo üzerinde alıştırma olarak denemeyi önerdi (python ile doğrulandı).

### 9.2 Totoloji ve çelişki

Bir önerme doğruluk tablosunun her satırında doğruysa totolojidir (tautology). Dört değişken için 16 satırın 16'sı da 1 ise totolojidir; 100 değişken için $2^{100}$ satırın hepsi 1 olmalıdır.

**Örnek: $p\rightarrow(p\vee q)$.** Önce $p\vee q$ sütunu: 0, 1, 1, 1. Sonra $p\rightarrow(p\vee q)$: $0\rightarrow0=1$, $0\rightarrow1=1$, $1\rightarrow1=1$, $1\rightarrow1=1$. Bütün sonuçlar 1 olduğu için totolojidir.

| $p$ | $q$ | $p\vee q$ | $p\rightarrow(p\vee q)$ |
|---|---|---|---|
| 0 | 0 | 0 | 1 |
| 0 | 1 | 1 | 1 |
| 1 | 0 | 1 | 1 |
| 1 | 1 | 1 | 1 |

Bütün sonuçlar 0 ise önerme çelişkidir (contradiction). Örnek: $p\wedge p'$. "Cüneyt programcıdır ve Cüneyt programcı değildir" demek bir çelişkidir; bir şey aynı anda hem doğru hem yanlış olamaz.

### 9.3 De Morgan kanunu

Aşağıdaki önerme çiftleri mantıksal olarak denktir (ekrandan, 02:10:00):

$$\sim(p\vee q)\equiv(\sim p)\wedge(\sim q)$$
$$\sim(p\wedge q)\equiv(\sim p)\vee(\sim q)$$

Slaytta iki taraf arasına ok konmuştu; hoca bunun "ise" bağlacı değil denklik ($\equiv$) olarak okunması gerektiğini söyledi. Kural: parantez içindeki her ifadenin değili alınır; VE, VEYA'ya; VEYA, VE'ye dönüşür; $p$ de $p'$'ye dönüşür. İse bağlacı için De Morgan'da doğrudan bir dönüşüm kuralı yoktur: önce $p\rightarrow q$, $p'\vee q$ biçimine çevrilir, sonra değili alınır.

## 10. Alıştırmalar

Dersin sonunda kitaptaki alıştırma slaytları çözüldü (ekrandan, 02:15:00 ve 02:20:00). Soruların metinleri ve çözümleri Örnek Sorular bölümündedir. Bu bölümde yalnız yöntem özetlenir:

- Bir önermenin değilini yazarken önermenin bütün karşı durumları söylenir ("perşembe" değilse haftanın diğer altı günü).
- Sözel bir cümle sembolle yazılırken önce önerme değişkenleri belirlenir; "ama", "bununla birlikte" (nevertheless) VE olarak okunur; "yeterlidir" hipotezi, "gereklidir" sonucu belirtir; "ancak ve ancak" çift yönlü önermedir.
- Değerleri kısmen bilinen önermelerde bağlacın kuralı kullanılır: VEYA'da bir giriş 1 ise sonuç 1; ise bağlacında hipotez 0 ise sonuç 1.

> **Hocanın vurgusu:** Sözel cümleyi sembolle yazma türünden sorular sınavlarda da gelebilir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:22:50): Belirli kurallara göre (büyük harfle başlasın, rakam ve özel sembol içersin vb.) kaç farklı şifre oluşturulabilir? Bu ne tür bir problemdir?

> **Çözüm:** Derste bir öğrenci bunun permütasyon problemi olduğunu söyledi. Hoca değişkenlerin karakter kümesi ve hane sayısı olduğunu belirtti: 100 karakterlik bir kümeden $n\le100$ uzunlukta kaç şifre oluşturulacağı sorulursa bu bir permütasyon problemidir; 100 uzunluklu şifre için $100!$ bulunur.

> **Ders sonrası not:** $100!$ ve 100'ün $n$'li permütasyonu, karakterlerin tekrar edilemediği durum içindir. Şifrelerde aynı karakter birden fazla kullanılabildiği için büyük olasılıkla doğru sayı $100^n$'dir (tekrarlı dizilim). Kurallar (ör. "en az bir rakam") varsa sayım, kuralı sağlamayan şifrelerin çıkarılmasıyla yapılır.

**Soru 2** (ekrandan, 00:35:00): A, B, C, D şehirleri arasında A'dan başlayıp her şehre bir kez uğrayarak A'ya dönen kaç farklı tur vardır?

> **Çözüm:** A sabit olduğuna göre B, C, D'nin sıralaması $3!=6$ farklı tur verir (ABCDA, ACBDA, ACDBA, ...). Her turun maliyeti hesaplanıp en küçüğü seçilir. 81 il için aynı hesap $80!$ tur verir. (Yön ayrımı için 3.1'deki ders sonrası nota bakın.)

**Soru 3** (derste sözlü, 00:39:37): Altı kişilik bir yatırım kulübü her yıl başkan ve sayman pozisyonlarını dönüşümlü olarak değiştirmek istiyor. Aynı kişilerin aynı pozisyonlara yeniden gelmesi için kaç yıl gerekir? <!-- BELİRSİZ: Soru metni altyazıdan kısmen çıkarıldı; slayt karesi okunmadı. -->

> **Çözüm (derste verilmedi):** Başkan 6 kişiden, sayman kalan 5 kişiden seçilir: $P(6,2)=6\cdot5=30$ farklı (başkan, sayman) ataması vardır. 30 yıl boyunca her yıl farklı bir atama yapılabilir; 31. yılda bir atama mutlaka tekrar eder (güvercin yuvası ilkesi). Sayı python ile doğrulandı.

**Soru 4** (ekrandan, 00:40:00): Üç çalışan Ali, Ayşe ve Ahmet sırasıyla 10, 12 ve 15 milyon saat ücreti alıyor. Patronun vereceği üç işin her çalışan için süresi (saat) tablodadır: İş 1: 7,5 / 6 / 6,5; İş 2: 8 / 8,5 / 7; İş 3: 5 / 6,5 / 5,5. Patron toplamda en az ödeme yapacak şekilde her birine hangi işi vermelidir?

> **Çözüm (derste verilmedi):** Her hücrenin maliyeti süre × saat ücretidir (milyon). Ali: İş 1 = 75, İş 2 = 80, İş 3 = 50. Ayşe: İş 1 = 72, İş 2 = 102, İş 3 = 78. Ahmet: İş 1 = 97,5, İş 2 = 105, İş 3 = 82,5. Üç kişiye üç işin $3!=6$ ataması denenir. En ucuzu Ali → İş 3 (50), Ayşe → İş 1 (72), Ahmet → İş 2 (105): toplam 227 milyon. İkinci en iyi atama (Ali → İş 2, Ayşe → İş 1, Ahmet → İş 3) 234,5 milyondur. Bütün atamalar python ile karşılaştırıldı. Derste adı geçen Macar algoritması aynı sonucu büyük tablolarda da verimli bulur.

**Soru 5** (ekrandan, 00:45:00): Şekil 1.3'teki öncelik grafında işlerin süreleri A=3, B=2, C=2, D=4, E=3, F=2, G=3, H=1, I=5, J=2, K=10'dur. Bütün işler kaç günde biter, kritik yol nedir?

> **Çözüm:** 4.2'deki tabloya göre K işi 28. günde biter; iş 30 günlük süreye yetişir. Kritik yol A, C, D, F, I, J, K'dır.

**Soru 6** (derste sözlü, 01:18:43 ve 01:19:57): $p\wedge0$, $p\wedge p$, $p\wedge p'$, $p\wedge1$, $p\vee1$, $p\vee p$, $p\vee p'$ ve $p\vee0$ neye eşittir?

> **Çözüm:** $p\wedge0=0$, $p\wedge p=p$, $p\wedge p'=0$, $p\wedge1=p$; $p\vee1=1$, $p\vee p=p$, $p\vee p'=1$, $p\vee0=p$.

**Soru 7** (derste sözlü, 01:32:06 ve 01:33:00): $p\oplus p'$, $p\oplus p$, $p\oplus1$ ve $p\oplus0$ neye eşittir?

> **Çözüm:** $p\oplus p'=1$, $p\oplus p=0$, $p\oplus1=p'$ (tersleme), $p\oplus0=p$ (aynalama).

**Soru 8** (derste sözlü, 01:48:04 ve 01:51:42): $p\rightarrow p$, $p\rightarrow p'$, $p\rightarrow1$ ve $p\rightarrow0$ neye eşittir?

> **Çözüm:** $p\rightarrow q\equiv p'\vee q$ açılımıyla: $p\rightarrow p=p'\vee p=1$, $p\rightarrow p'=p'\vee p'=p'$, $p\rightarrow1=1$, $p\rightarrow0=p'\vee0=p'$.

**Soru 9** (derste sözlü, 01:56:26): "Bugün cumartesi ise yarın pazardır" önermesinin converse, inverse ve contrapositive'ini sözel olarak yazınız.

> **Çözüm:** Converse: "Yarın pazar ise bugün cumartesidir." Inverse: "Bugün cumartesi değilse yarın pazar değildir." Contrapositive: "Yarın pazar değilse bugün cumartesi değildir."

**Soru 10** (derste sözlü, 02:11:16): Her önermenin değilini yazınız: (a) Bugün perşembedir. (b) $2+1=3$. (c) Illinois'de rüzgâr yoktur. (d) Champaign'de yaz sıcak ve nemlidir (hot and muggy).

> **Çözüm:** (a) Bugün pazartesi, salı, çarşamba, cuma, cumartesi ya da pazardır. (b) $2+1<3$ ya da $2+1>3$. (c) Illinois rüzgârlıdır. (d) Champaign'de yaz soğuk ya da kurudur (cold or dry). (d) şıkkında De Morgan kullanılmıştır: "sıcak ve nemli"nin değili "sıcak değil veya nemli değil"dir.

**Soru 11** (ekrandan, 02:15:00): $p$: "Finalden A alırsın", $q$: "Kitaptaki her alıştırmayı yaparsın", $r$: "Dersten A alırsın" olsun. Aşağıdaki cümleleri sembolle yazınız.

- (a) Dersten A alırsın ama kitaptaki her alıştırmayı yapmazsın.
- (b) Finalden A alırsın, her alıştırmayı yaparsın ve dersten A alırsın.
- (c) Dersten A almak için finalden A almak gereklidir.
- (d) Finalden A alırsın ama her alıştırmayı yapmazsın; bununla birlikte (nevertheless) dersten A alırsın.
- (e) Finalden A almak ve kitaptaki her alıştırmayı yapmak dersten A almak için yeterlidir.
- (f) Ancak ve ancak ya kitaptaki her alıştırmayı yaparsan ya da finalden A alırsan dersten A alırsın.

> **Çözüm:** (a) $r\wedge q'$. (b) $p\wedge q\wedge r$. (c) Slaytta ve derste $p\rightarrow r$ yazıldı. (d) $p\wedge q'\wedge r$. (e) $(p\wedge q)\rightarrow r$. (f) $r\leftrightarrow(p\vee q)$. "Veya" geçtiği için bir tarafta VEYA, "ancak ve ancak" geçtiği için çift yönlü önerme kullanılır.

> **Ders sonrası not:** (c) şıkkında gerekli şart sonuç tarafında yer alır. "Dersten A almak için finalden A almak gereklidir" cümlesinin doğru karşılığı $r\rightarrow p$'dir ("dersten A aldıysan finalden de A almışsındır"). Slayttaki ve hocanın okuduğu $p\rightarrow r$, "finalden A almak yeterlidir" anlamına gelir.

**Soru 12** (derste sözlü, 02:15:26): Her önermeyi "$p$ ise $q$" biçiminde yazınız: (a) Joe çok çalışırsa ayrık matematik dersini geçer. (b) Katrina'nın algoritma dersini alması için yeterli bir koşul, ayrık matematiği geçmesidir. Ayrıca "Joe çok çalışırsa ayrık matematik sınavını geçer" önermesinin converse'ini yazınız. <!-- BELİRSİZ: Slayt metni karede küçük görünüyor; soru altyazıdan kuruldu. -->

> **Çözüm:** (a) Joe çok çalışırsa ayrık matematik dersini geçecektir. (b) Katrina ayrık matematiği geçerse algoritma dersini alacaktır. Converse: Joe ayrık matematik sınavını geçtiyse çok çalışmıştır.

**Soru 13** (derste sözlü, 02:16:47): $p$ doğru, $q$ yanlış ve $r$'nin doğruluk değeri bilinmiyor. Aşağıdakilerin doğruluk değerini bulunuz: $p\vee r$, $q\rightarrow r$, $p\wedge r$ içeren ifade ve $q$ ile $r$ içeren ifade. <!-- BELİRSİZ: Son iki ifadenin tam biçimi karede okunmadı; altyazıdan (p ∧ r) ↔ r ve (q ∨ r) ↔ r olduğu anlaşılıyor. -->

> **Çözüm:** $p\vee r$: $p$ doğru olduğu için doğrudur. $q\rightarrow r$: hipotez yanlış olduğu için $r$ ne olursa olsun doğrudur. $p\wedge r$: $p$ doğru olduğundan $r$'ye eşittir; bu yüzden $(p\wedge r)\leftrightarrow r$ girişleri hep aynı olduğu için doğrudur. $q\vee r$: $q$ yanlış olduğundan $r$'ye eşittir; $(q\vee r)\leftrightarrow r$ de doğrudur. $r$'nin iki değeri için python ile denetlendi.

**Soru 14** (ekrandan, 02:20:00): Verilen ifadeleri sembolle yazınız: "if $4<2$ then $7<10$" ve "$7<10$ if and only if ($4<2$ and 6 is not less than 6)". Ayrıca $p$: "Today is Monday", $q$: "It is raining", $r$: "It is hot" olmak üzere $p\rightarrow q$ ve $\sim(p\vee q)\leftrightarrow r$ ifadelerini sözel yazınız.

> **Çözüm:** $p$: $4<2$, $q$: $7<10$, $r$: $6<6$ alınırsa birincisi $p\rightarrow q$, ikincisi $q\leftrightarrow(p\wedge\sim r)$ olur. $p\rightarrow q$: "If today is Monday then it is raining." $\sim(p\vee q)\leftrightarrow r$: "It is not the case that today is Monday or it is raining if and only if it is hot."

**Soru 15** (derste sözlü, 02:21:20): $[\sim p\wedge(p\rightarrow q)]\rightarrow\sim q$ bir totoloji midir? <!-- BELİRSİZ: İfade karede küçük görünüyor; hocanın sütun sütun anlatımından kuruldu. -->

> **Çözüm:** Sütunlar sırayla $\sim p$, $p\rightarrow q$, $\sim p\wedge(p\rightarrow q)$, $\sim q$ ve son ise bağlacıdır.

| $p$ | $q$ | $\sim p$ | $p\rightarrow q$ | $\sim p\wedge(p\rightarrow q)$ | $\sim q$ | sonuç |
|---|---|---|---|---|---|---|
| 0 | 0 | 1 | 1 | 1 | 1 | 1 |
| 0 | 1 | 1 | 1 | 1 | 0 | 0 |
| 1 | 0 | 0 | 0 | 0 | 1 | 1 |
| 1 | 1 | 0 | 1 | 0 | 0 | 1 |

> $p=0$, $q=1$ satırında sonuç 0 olduğu için totoloji değildir (python ile doğrulandı).

## Dersin Toparlaması

Dersin ilk yarısında ayrık matematiğin ne olduğu ve neden bilgisayar biliminin temelinde yer aldığı anlatıldı. Sürekli sinyalin örneklenerek ayrık hâle gelmesi, bilgisayarın neden ayrık yapılarla çalıştığını gösterdi. Gezgin satıcı, atama, PERT ile planlama ve pilot eşleştirme örnekleri, ayrık problemlerin varlık, sayma ve optimizasyon türlerinde olduğunu ve graf gibi yapılarla modellendiğini gösterdi. Kesin çözümün imkânsız olduğu büyük problemlerde optimal çözüm arandığı vurgulandı.

İkinci yarıda önermeler mantığına girildi. Önerme, birleştiriciler (VE, VEYA, XOR, DEĞİL, ise, ancak ve ancak) ve doğruluk tabloları tanıtıldı. Bağlaçların birbiri cinsinden yazılması ($p\oplus q=(p\wedge q')\vee(p'\wedge q)$, $p\rightarrow q\equiv p'\vee q$, $p\leftrightarrow q\equiv(p'\vee q)\wedge(q'\vee p)$), mantıksal denklik, converse-inverse-contrapositive, totoloji, çelişki ve De Morgan kanunu işlendi. Bir sonraki adımda niceleyicilere (quantifiers) ve ispat yöntemlerine geçilecek; contrapositive ispatlarda yeniden kullanılacaktır. Mantık konusu, ardından gelecek Boole cebri ve kombinasyonel devreler konusunun da temelidir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
