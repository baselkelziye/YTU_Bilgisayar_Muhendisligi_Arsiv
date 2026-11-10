# Ders 1 Genişletilmiş Notu: Diziler, Sınırlılık, Monotonluk, Dizi Limiti ve Serilere Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Açılışı ve Dönemin Konu Planı
- 2. Dizi Kavramı ve Genel Terim
- 3. Sınırlı Diziler, En Büyük Alt Sınır ve En Küçük Üst Sınır
- 4. Monoton Diziler
- 5. Dizinin Limiti: Yakınsaklık ve Iraksaklık
- 6. Limit Kuralları ve Sandviç Teoremi
- 7. Yakınsaklık ile Sınırlılık İlişkisi ve Limit Hesaplama Teknikleri
- 8. Monoton Dizi Teoremi
- 9. Sıkça Rastlanan Limitler ve $1^\infty$ Belirsizliği
- 10. Sonlu Sayıda Terim Dizinin Karakterini Değiştirmez
- 11. Serilere Giriş: Zıplayan Top Problemi
- 12. Seri, Kısmi Toplamlar Dizisi ve Yakınsaklık
- 13. Geometrik Seri
- 14. Teleskopik ve Harmonik Seriler
- 15. Serilerle İşlemler ve Sonraki Ders

## 1. Dersin Açılışı ve Dönemin Konu Planı

Hoca kendini Matematik bölümünde fonksiyonel analiz alanında çalışan bir öğretim üyesi olarak tanıttı. Bir öğrencinin "neyin analizini yapıyorsunuz?" sorusu üzerine matematiğin ana bilim dallarını saydı: topoloji, fonksiyonel analiz, uygulamalı matematik, geometri. Her dalın içinde yüzlerce alan vardır. Kendisi analiz içinde operatörlerle yaklaşım teorisi (approximation theory) ve Fourier analizi üzerine çalışmıştır.

Bu alanların uygulamasına örnek olarak Fourier ve Laplace dönüşümlerini verdi. Hocaya göre MR cihazlarının yazılımında bu dönüşümler kullanılır. Dönüşümlerle diferansiyel denklemleri doğrudan türev işlemleriyle uğraşmadan çözmek mümkün olur. Tam çözüm bulunamadığında da yaklaşık çözüm yöntemleri devreye girer.

Hoca, bu dersin hem mekatronik hem de genel olarak mühendislik biliminin temeli olduğunu vurguladı. Dersi "geçmek için" değil "öğrenmek için" dinlemenin farkını anlattı: öğrenmek için dinlenen bilgi kalıcı olur. Bunu bir deney anlatımıyla destekledi: Üç öğrenciye aynı şey anlatılmış, birine "bir saat", birine "bir hafta", birine "altı ay" unutmayacaksın denmiş. Her biri söylenen süre kadar hatırlamış. Hocanın çıkardığı sonuç: İnsan bilgiyi hafızaya nasıl yerleştirirse o şekilde kalır. Okunan şey soruya dönüştürülmedikçe kullanılabilir biçimde hafızaya yerleşmez.

> **Hocanın vurgusu:** Bu dersin formüllerinden çok algoritması, yani düşünme yolu gerekli olacak. Derse gelmeden önce internetteki notlardan konuyu tarayın, derste soru sorun.

### 1.1 Dönemin konuları

Dönemin konu sırası şöyle verildi:

- Diziler (sequences)
- Seriler (series)
- Taylor ve Maclaurin serileri
- Serilerin uygulamaları
- Çok değişkenli fonksiyonlar: limit, türev, integral

Çok değişkenli fonksiyon için hoca birinci dönemle karşılaştırma yaptı. Birinci dönemde $y=f(x)$ gibi tek bağımsız değişkenli fonksiyonlar görüldü. Bu dönem en az iki değişkenli fonksiyonlar gelecek: $z=f(x,y)$, $u=f(x,y,z)$ ve genel olarak $n$ değişkenli fonksiyonlar. Hocaya göre yaşadığımız dünyadaki olaylar tek parametreye bağlı değildir. Bir doktorun baktığı binlerce hastanın kan değerleri, ilaçları ve iyileşme süreçleri ancak fonksiyona dönüştürülüp analiz edildiğinde kayda değer bilgiye dönüşür.

Konu başlıkları Matematik bölümünün sitesindeki servis dersleri sayfasında yer alıyor.

**Soru:** Matematik 1'i almadan Matematik 2'ye geçtim, sorun olur mu? **Cevap:** Hoca Matematik 1'i birinci kat, Matematik 2'yi ikinci kat olarak benzetti. Diziler ve seriler (ilk 3-4 hafta) Matematik 1'den büyük ölçüde bağımsızdır. Ama çok değişkenli fonksiyonların limiti, tek değişkenli limiti bilmeden yapılamaz. İki katlı integral de sonunda tek katlı integrallere indirgenerek çözülür. Bu yüzden öğrencinin ilk 3-4 hafta içinde tek değişkenli limit, türev ve integral konularını kayıtlar ve notlarla telafi etmesi gerekir.

## 2. Dizi Kavramı ve Genel Terim

Hoca konuya öğrencilere "dizi nedir?" diye sorarak başladı. Öğrencilerden "belli bir kurala göre tekrar eden örüntüler" ve "ardı ardına gelen sayılar" cevapları geldi. Hoca ikisini de onayladı.

**Tanım (Dizi)**

- Belli bir kurala göre sıralanmış $a_1, a_2, a_3, \dots, a_n, \dots$ sayılarına dizi denir.
- $a_n$ dizinin genel terimidir. Dizi $(a_n)$ ya da $(a_n)_{n=1}^{\infty}$ ile gösterilir.
- $n$ sayısına indis denir. İndis doğal sayıdır: $1, 2, 3, \dots$ diye sonsuza kadar gider.
- Dizi, doğal sayılardan reel sayılara tanımlı bir fonksiyondur: $a:\mathbb{N}\to\mathbb{R}$, $n\mapsto a_n$. Yani fonksiyonun özel bir hâlidir.

Tanım kümesi doğal sayılar olduğu için $a_{1/2}$ gibi bir terim yoktur. "Bir buçukuncu terim" diye bir şey olmaz. Dizi olması için indisin kesinlikle doğal sayı olması gerekir.

<!-- BELİRSİZ: Hoca 00:32:07'de önce "tam sayılar kümesi üzerinde tanımlı" dedi, hemen ardından "doğal sayılardan reel sayılara" diye düzeltti. Notta doğru olan ikinci ifade kullanıldı. -->

### 2.1 Örnek 1: Çift sayılar dizisi

Dizi: $2, 4, 6, 8, \dots$

- İlk terim $a_1=2$, ikinci terim $a_2=4$.
- Genel terim $a_n = 2n$. $n=1$ için $2$, $n=2$ için $4$ çıkar.
- 50. terim: $a_{50}=2\cdot 50=100$.
- 77. terim: $a_{77}=2\cdot 77 = 154$.

Derste 50. terim için bir öğrenci önce $98$ dedi, sonra $100$ olarak düzeltti. Hoca, yanlış cevabın da öğrenmenin parçası olduğunu söyleyip öğrencileri çekinmeden cevap vermeye teşvik etti.

### 2.2 Örnek 2: Karekök dizisi

Dizi: $1, \sqrt2, \sqrt3, \sqrt4, \dots$

Birinci terim $1=\sqrt1$, ikinci terim $\sqrt2$, üçüncü terim $\sqrt3$ olduğuna göre genel terim $a_n=\sqrt{n}$'dir.

### 2.3 Örnek 3: İşaret değiştiren dizi

Dizi: $1, -\dfrac12, \dfrac13, -\dfrac14, \dots$

Hoca genel terimi iki adımda kurdu:

- **Mutlak değer:** Paydalar $1, 2, 3, 4, \dots$ diye gidiyor. Yani terimlerin mutlak değeri $\dfrac1n$.
- **İşaret:** Terimler bir artı, bir eksi gidiyor. $(-1)^n$ yazılırsa $n=1$ için ilk terim eksi olur, bu yanlış. Bu yüzden üs $n+1$ alınır: $n=1$ için $(-1)^2=+1$, $n=2$ için $(-1)^3=-1$.

Sonuç:

$$a_n=\frac{(-1)^{n+1}}{n}$$

> **Hocanın vurgusu:** Verilen terimlere bakarak genel terimi yazabilmek çok önemli. İşaret değiştiren dizilerde $(-1)^{n}$ ya da $(-1)^{n+1}$ çarpanı ilk terimin işaretine göre seçilir.

Hoca ardından notlarda, ilk terimi ve bir önceki terimden sonrakini veren bir kuralla (indirgemeli) tanımlanan bir dizinin ilk 6 teriminin bulunduğu bir örneği gösterdi. Bu örneğin birinci dönem sınavına hazırlanırken de görüldüğünü söyledi.

<!-- BELİRSİZ: 00:35:28'deki indirgemeli dizi örneğinin kuralı altyazıda okunmuyor ("A11, A21 ile tanımlı"); örnek bu yüzden aktarılmadı. -->

### 2.4 Dizilerle işlemler

- Bir diziyi bir $c$ sabitiyle çarpmak, her terimini $c$ ile çarpmak demektir: $(c\,a_n)$.
- İki dizinin toplamı ve farkı terim terim yapılır: $(a_n\pm b_n)$.
- Bölüm de terim terim yazılır: $b_n\neq0$ olmak üzere $\left(\dfrac{a_n}{b_n}\right)$.

## 3. Sınırlı Diziler, En Büyük Alt Sınır ve En Küçük Üst Sınır

**Tanım (Sınırlı dizi)**

- Her $n\in\mathbb{N}$ için $|a_n|\le K$ olacak şekilde bir $K$ sayısı varsa $(a_n)$ dizisi sınırlıdır (bounded).
- Bu, dizinin hem alttan hem üstten sınırlı olması demektir. Birinci terim, ikinci terim, ..., $n$. terim ve sonsuza kadar bütün terimler bu sınırlar arasında kalır.
- Böyle bir $K$ yoksa dizi sınırsızdır.

Hoca öğrencilerden sınırlı bir dizi örneği istedi. Bir öğrenci soğuyan bir cismin sıcaklığını önerdi. Hoca $\dfrac1n$ dizisine geçti.

### 3.1 Örnek 4: $a_n=\dfrac1n$ sınırlı mıdır?

Derste bir öğrenci "reel sayılarda sınırlı değil" dedi. Hoca burada $n$'nin reel sayı değil doğal sayı olduğunu hatırlattı: $n=1, 2, 3, 4, \dots$

- $n=1$ için $a_1=1$, $n=2$ için $\tfrac12$, $n=3$ için $\tfrac13$, $n=100$ için $\tfrac1{100}$.
- Her $n$ için terimler $1$'den küçük ya da eşittir, $0$'dan büyüktür: $0 < a_n \le 1$.
- Dizi alttan $0$, üstten $1$ ile sınırlıdır. Yani sınırlıdır.

### 3.2 Örnek 5: $a_n=2n$ sınırlı mıdır?

Terimler $2, 4, 6, \dots$ diye sonsuza gider. Hiçbir $K$ sayısı bütün terimlerin üstünde kalamaz. Dizi sınırsızdır.

### 3.3 Örnek 6: $a_n=(-1)^n$ sınırlı mıdır?

Bir öğrenci "$-1$ ile $+1$ arasında değer alıyor" dedi. Hoca onayladı: Dizi $-1, 1, -1, 1, \dots$ diye gider. Her $n$ için $-1\le a_n\le 1$, yani $|a_n|\le 1$. Dizi sınırlıdır.

### 3.4 Ebas ve eküs

Bir dizinin birden fazla alt sınırı ve üst sınırı olabilir. Bunların içinde özel iki sayı vardır:

**Tanım (Ebas ve eküs)**

- **En büyük alt sınır (ebas, infimum):** Alt sınırların en büyüğü.
- **En küçük üst sınır (eküs, supremum):** Üst sınırların en küçüğü.

Hoca tanımları okurken bir ara ifadeleri karıştırdı ("en büyük üst sınır") ve hemen "burada yanlış yazdık" diyerek düzeltti.

$(-1)^n$ dizisi üzerinde açıkladı:

- $-1$ bir alt sınırdır, $-2$ de bir alt sınırdır, $-3$ de. Bunların en büyüğü $-1$'dir. Yani ebas $=-1$.
- $1$ bir üst sınırdır, $2$ de, $3$ de. Bunların en küçüğü $1$'dir. Yani eküs $=1$.

### 3.5 Örnek 7: Üstten sınırsız bir dizinin ebas ve eküsü

Hoca ekranda bir dizi gösterip ebas ve eküsünü sordu. Bir öğrenci "eküs artı sonsuz, ebas $1$" dedi. Hoca düzeltti: Dizi üstten sınırlı olmadığı için eküsü yoktur. Ebası $1$'dir. Dizi alttan sınırlı, üstten sınırsızdır.

<!-- BELİRSİZ: 00:42:45'teki dizinin ifadesi altyazıda geçmiyor; yalnız alttan 1 ile sınırlı ve üstten sınırsız olduğu anlaşılıyor. -->

### 3.6 Örnek 8: $a_n=\dfrac{n}{n+1}$

Terimler: $\dfrac12, \dfrac23, \dfrac34, \dots, \dfrac{99}{100}, \dfrac{999}{1000}, \dots$

- **Sınırlı mı?** Evet. Her terimde pay paydadan küçük olduğu için terimler $1$'den küçüktür. En küçük terim ilk terim $\tfrac12$'dir.
- **Eküs:** Terimler $1$'e yaklaşıyor ama $1$'e ulaşmıyor. Üst sınırların en küçüğü $1$'dir.
- **Ebas:** En küçük terim $\tfrac12$ olduğundan ebas $\tfrac12$'dir.

Derste bir öğrenci üst sınırın $1$ olduğunu, diğeri en küçük değerin $\tfrac12$ olduğunu söyledi. Hoca ikisini de onayladı.

## 4. Monoton Diziler

Hoca "monoton dizi nedir?" diye sordu. Bir öğrenci "artış miktarı sabit dizi" dedi. Hoca "aferin" deyip doğrudan tanımı yazmaya geçti.

**Tanım (Monoton dizi)**

- Her $n$ için $a_n<a_{n+1}$ ise dizi monoton artandır. Her terim bir sonrakinden küçüktür.
- Her $n$ için $a_n>a_{n+1}$ ise dizi monoton azalandır.
- Geniş anlamda: $a_n\le a_{n+1}$ ise dizi **azalmayan**, $a_n\ge a_{n+1}$ ise dizi **artmayan** dizidir.
- Grafikte artan dizinin noktaları $n$ arttıkça yukarı, azalan dizininkiler aşağı doğru gider.

> **Ders sonrası not:** Öğrencinin "artış miktarı sabit dizi" tanımı aritmetik dizinin tanımıdır. Hoca bu cevabı onaylayıp geçti; doğrusu, monoton artan dizide artış miktarının sabit olması gerekmez, her terimin bir öncekinden büyük olması yeter. Örneğin $\tfrac{n}{n+1}$ dizisinde artış miktarı her adımda küçülür ama dizi artandır.

### 4.1 Oran testi ile monotonluk

Terimler pozitifse $a_n<a_{n+1}$ eşitsizliğinin iki tarafı $a_n$'e bölünebilir:

$$a_n<a_{n+1}\iff \frac{a_{n+1}}{a_n}>1$$

Yani ardışık terimlerin oranı $1$'den büyükse dizi artan, $1$'den küçükse azalandır.

### 4.2 Örnek 9: $a_n=\dfrac{n}{n+1}$ monoton mudur?

- $a_{n+1}$ için $n$ yerine $n+1$ yazılır: $a_{n+1}=\dfrac{n+1}{n+2}$.
- Oran:

$$\frac{a_{n+1}}{a_n}=\frac{n+1}{n+2}\cdot\frac{n+1}{n}=\frac{(n+1)^2}{n(n+2)}=\frac{n^2+2n+1}{n^2+2n}$$

- Pay, paydadan $1$ fazladır (ara adım eklendi: çarpımların açılımı). Bu yüzden oran $1$'den büyüktür.
- Sonuç: Dizi monoton artandır. Diğer bir deyimle azalmayan dizidir.

### 4.3 Örnek 10: $1, \tfrac12, \tfrac14, \tfrac18, \dots$

Bu bir geometrik dizidir. Ortak çarpan $\tfrac12$'dir. Genel terim $a_n=\left(\tfrac12\right)^{n-1}$.

- Oran: $\dfrac{a_{n+1}}{a_n}=\dfrac12<1$.
- Sonuç: Dizi monoton azalandır (artmayan dizidir).

**Soru:** Sabit dizi monoton dizilere girer mi? Ne artıyor ne azalıyor. **Cevap:** Hoca "sabit dizi monoton değil" dedi ve soruyu soran öğrenciyi tebrik etti.

> **Ders sonrası not:** Hoca sabit dizinin monoton olmadığını onayladı. Bu, kesin (strict) anlamda doğrudur: Sabit dizi ne kesin artan ne kesin azalandır. Ama geniş anlamdaki tanıma göre sabit dizi hem azalmayan hem artmayandır. Bu yüzden büyük olasılıkla çoğu kitapta monoton sayılır. Ayrıca sabit dizi sınırlı ve yakınsaktır.

Hoca bu soru üzerine öğrencileri soru sormaya teşvik etti: Ne kadar soru sorulursa o kadar öğrenilir.

## 5. Dizinin Limiti: Yakınsaklık ve Iraksaklık

Aradan sonra hoca dizinin limitini boş bir sayfa üzerinde çizerek anlattı. Dizinin terimleri $a_1, a_2, \dots, a_{n_0}$ diye gidiyor. $a_{n_0}$'dan sonraki terimler ise bir $a$ sayısının etrafında, onun $\varepsilon$-komşuluğunda yığılıyor.

**Tanım (Dizinin limiti)**

- Dizinin sonlu sayıdaki terimleri (yani $a_{n_0}$'a kadar olanlar) hariç diğer bütün terimleri bir $L$ sayısının her $\varepsilon$-komşuluğunda yığılıyorsa, dizi $L$'ye yakınsar (converges).
- Gösterim: $\lim\limits_{n\to\infty}a_n=L$ ya da $a_n\to L$. İkisi aynı şeydir.
- Limit varsa tektir. Bir dizinin iki ayrı limiti olamaz.
- Limit $+\infty$ ya da $-\infty$ ise ya da limit mevcut değilse dizi ıraksaktır (divergent).

> **Ek bilgi (derste anlatılmadı):** Bu tanımın biçimsel hâli şöyledir: Her $\varepsilon>0$ için öyle bir $n_0$ vardır ki $n>n_0$ olan her $n$ için $|a_n-L|<\varepsilon$ olur. Buradaki $n_0$, hocanın çiziminde "sonlu sayıdaki terimlerin" bittiği yerdir. $\varepsilon$ küçüldükçe $n_0$ genelde büyür.

Hoca tanımın ardından hızlı sorular sordu:

- $\dfrac1n$ nereye yakınsar? Öğrenciler: $0$'a. Doğru.
- $\dfrac{n}{n+1}$ nereye yakınsar? Öğrenciler: $1$'e. Doğru.
- $(-1)^n$ nereye yakınsar? Terimler $-1$ ile $1$ arasında gidip geliyor. $n$ çift iken $1$'e, $n$ tek iken $-1$'e gidiyor. İki ayrı "limit adayı" olduğu için limit yoktur. Dizi yakınsak değildir.
- $1, 2, 3, 4, \dots$ dizisi $+\infty$'a ıraksar.

## 6. Limit Kuralları ve Sandviç Teoremi

Hoca limitin "çok esnek bir kavram" olduğunu söyledi. Fonksiyonlardaki limit kuralları dizilerde de geçerlidir.

**Teorem (Limit kuralları)** $\lim a_n=A$ ve $\lim b_n=B$ ise:

- $\lim(a_n\pm b_n)=A\pm B$
- $\lim(k\,a_n)=kA$ ($k$ sabit)
- $\lim(a_nb_n)=AB$
- $B\neq0$ ise $\lim\dfrac{a_n}{b_n}=\dfrac AB$

**Teorem (Sandviç ya da sıkıştırma teoremi)**

- $(a_n)$, $(b_n)$, $(c_n)$ birer dizi olsun ve belli bir $n$'den sonra $a_n\le b_n\le c_n$ olsun.
- $\lim a_n=\lim c_n=L$ ise $\lim b_n=L$'dir.
- Alttaki ve üstteki dizi aynı yere gidiyorsa ortadaki de oraya gider.

Hoca bu teoremin birinci dönemde fonksiyonlar için görüldüğünü hatırlattı. Bir öğrenci örnek olarak "$3$ ve $4$ arasına $2$'yi sıkıştırmak" gibi bir fikir önerdi. Hoca öğrenciye ekran paylaşımı verdi, sonra kendisi bir örnekle devam etti.

### 6.1 Örnek 11: $\lim\limits_{n\to\infty}\dfrac{\sin n}{n}$

Hoca bunun bir sınav sorusu olduğunu söyledi. Derste öğrencilerden üç farklı cevap geldi: $1$, "limit yok" ve $0$.

Önce yaygın karışıklığı açıkladı: Birinci dönemde görülen

$$\lim_{x\to0}\frac{\sin x}{x}=1$$

limiti farklı bir şeydir. Orada $x\to0$'dır. Burada ise $n\to\infty$'dur.

Çözüm sandviç teoremiyle yapılır:

- Her $n$ için $-1\le\sin n\le1$. Sinüs ve kosinüs her zaman $-1$ ile $1$ arasındadır.
- Her taraf $n>0$ sayısına bölünür:

$$-\frac1n\le\frac{\sin n}{n}\le\frac1n$$

- $\lim\limits_{n\to\infty}\left(-\dfrac1n\right)=0$ ve $\lim\limits_{n\to\infty}\dfrac1n=0$.
- Alt ve üst taraf $0$'a gittiği için ortadaki de $0$'a gider.

Sonuç: $\lim\limits_{n\to\infty}\dfrac{\sin n}{n}=0$. Hocanın ifadesiyle cevap "kocaman bir sıfır".

> **Hocanın vurgusu:** $\lim_{x\to0}\frac{\sin x}{x}=1$ ile $\lim_{n\to\infty}\frac{\sin n}{n}=0$'ı karıştırmayın.

## 7. Yakınsaklık ile Sınırlılık İlişkisi ve Limit Hesaplama Teknikleri

**Teorem:** Yakınsak dizi sınırlıdır. Ancak tersi doğru değildir.

Tersinin doğru olmadığına örnek $(-1)^n$'dir:

- Dizi sınırlıdır: alttan $-1$, üstten $+1$ ile.
- Ama yakınsak değildir: $n$ çiftken $1$'e, $n$ tekken $-1$'e gider, limit yoktur.

Hoca "hem sınırlı hem yakınsak bir dizi" örneği istedi. Bir öğrenci $\dfrac1n$ dedi. Hoca onayladı: Dizi alttan $0$, üstten $1$ ile sınırlıdır ve $0$'a yakınsar.

### 7.1 Örnek 12: $\dfrac{\cos n}{n}$

Notlarda "$\dfrac{\cos n}{n}$ dizisinin limitini sıkıştırma teoremiyle bulunuz" sorusu vardı. Çözüm sinüs örneğiyle aynıdır:

- $-1\le\cos n\le1$.
- $n$'ye bölünür: $-\dfrac1n\le\dfrac{\cos n}{n}\le\dfrac1n$.
- İki ucun limiti $0$ olduğundan $\lim\dfrac{\cos n}{n}=0$.

Hocanın yorumu: "Bu teoremler gerçekten hayat kurtarıyor."

### 7.2 Örnek 13: Eşlenikle çarpma, $a_n=\sqrt{n^2+2n}-n$

Soru: Dizinin yakınsaklığını inceleyiniz (ya da limitini bulunuz).

- $n$ yerine sonsuz konunca $\infty-\infty$ belirsizliği çıkar.
- Kök içeren ifade olduğu için eşlenikle çarpılır (ara adımlar eklendi):

$$a_n=\left(\sqrt{n^2+2n}-n\right)\cdot\frac{\sqrt{n^2+2n}+n}{\sqrt{n^2+2n}+n}=\frac{n^2+2n-n^2}{\sqrt{n^2+2n}+n}=\frac{2n}{\sqrt{n^2+2n}+n}$$

- Pay ve payda $n$'ye bölünür:

$$a_n=\frac{2}{\sqrt{1+\frac2n}+1}\longrightarrow\frac{2}{1+1}=1$$

Sonuç: Dizi yakınsaktır, limiti $+1$'dir.

<!-- BELİRSİZ: Dizinin ifadesi altyazıda "kariköçünde n kare artı 2'e, eksi'e" olarak geçiyor; hocanın verdiği sonuç (+1) ile tutarlı olan $\sqrt{n^2+2n}-n$ kabul edildi. -->

### 7.3 Örnek 14: L'Hôpital kuralı, $a_n=\dfrac{\ln n}{n}$

- $n\to\infty$ için $\dfrac{\infty}{\infty}$ belirsizliği vardır.
- Hoca, fonksiyonlarda yaptığımız gibi $n$ yerine $x$ düşünülebileceğini söyledi: $f(x)=\dfrac{\ln x}{x}$.
- Payın türevi $\dfrac1x$, paydanın türevi $1$'dir:

$$\lim_{x\to\infty}\frac{\ln x}{x}=\lim_{x\to\infty}\frac{1/x}{1}=0$$

- Fonksiyonun limiti $0$ olduğu için dizi de $0$'a yakınsar.

> **Hocanın vurgusu:** Bu güzel bir test sorusu. Konuyu anlamak yetmez, kavramak ve bol soru çözmek gerekir. Test sınavında süre sınırlıdır.

### 7.4 Örnek 15: $\sin(n\pi)$ dizisi yakınsak mıdır?

Hoca bunu bir test sorusu olarak sordu. Bir öğrenci "yakınsak değil, çünkü $1$ ile $-1$ arasında değişiyor" dedi. Hoca önce öğrenciyi tebrik etti, sonra ekrandaki çözüme bakınca cevabın doğru olmadığını açıkladı.

- $n$ doğal sayıdır: $1, 2, 3, 4, \dots$
- $\sin\pi=0$, $\sin2\pi=0$, $\sin3\pi=0$, $\sin4\pi=0$, ...
- Dizinin bütün terimleri $0$'dır. Dizi sabit $0$ dizisidir ve $0$'a yakınsar.

Hoca öğrencinin cevabının nereden geldiğini de açıkladı. $\sin(\pi x)$ **fonksiyonunda** $x$ reel sayıdır. $x=\tfrac12$ için $1$, $x=\tfrac32$ için $-1$, $x=0$ için $0$ olur. Bu yüzden $\lim_{x\to\infty}\sin(\pi x)$ yoktur. Bu fonksiyon için "limit yok" doğru çözümdür. Ama $\sin(n\pi)$ bir **dizidir**, indis doğal sayıdır ve "bir buçuk" değeri alamaz.

> **Hocanın vurgusu:** $x$ yazıldığında iş farklı, $n$ yazıldığında farklıdır. $\sin(n\pi)$ dizisi yakınsaktır ve limiti $0$'dır; $\sin(\pi x)$ fonksiyonunun sonsuzda limiti yoktur.

<!-- BELİRSİZ: 01:22:20'de hoca öğrencinin "yakınsak değil" cevabını önce "aferin" diye karşıladı, sonra ekrandaki çözümü okuyup cevabın $\sin(\pi x)$ için doğru olduğunu açıkladı. Ekrandaki şıkların tam metni altyazıda yok. -->

## 8. Monoton Dizi Teoremi

**Teorem (Monoton dizi teoremi)**

- Monoton ve sınırlı her dizi yakınsaktır.
- Artan ve üstten sınırlı dizi, üst sınırına (eküsüne) yaklaşır. Azalan ve alttan sınırlı dizi, alt sınırına (ebasına) yaklaşır.

Hoca teoremin "orijinalini" yazarken monotonluk ve sınırlılığı yakınsaklık için "gerekli ve yeterli koşul" olarak okudu.

> **Ders sonrası not:** Hoca "monoton ve sınırlı olmak yakınsaklık için gerekli ve yeterli koşul" dedi; doğrusu, bu koşul yalnız yeterlidir, gerekli değildir. Örneğin $\dfrac{(-1)^n}{n}$ dizisi $0$'a yakınsar ama monoton değildir. Monoton bir dizi için ise "yakınsak $\iff$ sınırlı" doğrudur.

### 8.1 Örnek 16: $a_n=\dfrac{n}{n+1}$ teoremle

- **Sınırlı mı?** $n=1$ için $\tfrac12$. Terimler $\tfrac12$ ile $1$ arasındadır. Sınırlıdır.
- **Monoton mu?** $\tfrac12=0{,}5$, $\tfrac23\approx0{,}67$, $\tfrac34=0{,}75$. Terimler artıyor. Bölüm 4'te oranla da gösterildi. Monoton artandır.
- **Sonuç:** Monoton ve sınırlı olduğu için yakınsaktır. Artan olduğu için üst sınırına, yani $1$'e yaklaşır. Bu, Bölüm 5'te bulunan limitle aynıdır.

Hoca ekledi: Dizi monoton azalan olsaydı alt sınırına (bu örnekte $\tfrac12$'ye) yaklaşacaktı.

## 9. Sıkça Rastlanan Limitler ve $1^\infty$ Belirsizliği

> **Hocanın vurgusu:** Sıkça rastlanan limitleri bilmek, hazmetmek lazım. Çünkü sınav test şeklinde ve bu limitler sorularda ara işlem ya da ana işlem olarak mutlaka gelir.

**Sıkça rastlanan limitler** ($n\to\infty$):

- $\sqrt[n]{n}=n^{1/n}\to1$
- $x>0$ ise $\sqrt[n]{x}=x^{1/n}\to1$
- $|x|<1$ ise $x^n\to0$
- Her $x$ için $\dfrac{x^n}{n!}\to0$. Bir sayının kuvveti bölü faktöriyel her zaman $0$'a gider.
- Her $x$ için $\left(1+\dfrac xn\right)^n\to e^x$. Hoca bunu $\left(1+\dfrac bn\right)^n\to e^b$ biçiminde yazdı ve birinci dönemde fonksiyonlarda kullanıldığını hatırlattı.

> **Ders sonrası not:** Hoca $x^n$ için "$x$ bir ya da birden büyükse ıraksaktır" dedi; doğrusu, $x=1$ için $1^n=1$ olur ve dizi $1$'e yakınsar. Tam sınıflandırma: $|x|<1$ ise $0$'a yakınsar; $x=1$ ise $1$'e yakınsar; $x>1$ ise $+\infty$'a ıraksar; $x\le-1$ ise ıraksar (limit yok).

Hoca bu listeden sonra "$1$ yerine $2$, $n$ yerine $3n$ olsaydı" gibi bir varyasyon sordu.

<!-- BELİRSİZ: 01:30:49'daki "Şurada 2 olsaydı, şurada 3 olsa" varyasyonunun tam ifadesi ve cevabı altyazıda anlaşılmıyor. -->

### 9.1 Ekrandaki üç limit

Hoca ekranda üç limit gösterdi ve öğrencilerin kendi yerlerinde çözmelerini istedi. Altyazıdan çıkan kısım:

- **Limit 1:** $\lim\limits_{n\to\infty}\dfrac{100^n}{n!}=0$. Bu, $\dfrac{x^n}{n!}\to0$ kuralının $x=100$ için hâlidir. Hoca "nasıl sıfır eşittir, şöyle bir düşünün" diye öğrencileri sorgulamaya davet etti.
- **Limit 2:** Sınavda sorulmuş, $\dfrac{n-2}{n}$ ya da benzeri bir ifadenin $n$. kuvveti biçiminde bir dizi. Hoca bunun $\left(1+\dfrac xn\right)^n$ kuralıyla ilgili olduğunu ima etti.
- **Limit 3:** $\sqrt[n]{n}$ kuralına "ufak bir manipülasyonla" $3$ eklenmiş bir ifade.

<!-- BELİRSİZ: 01:32:43-01:33:49 arasında Limit 2 ve Limit 3'ün tam ifadeleri altyazıda okunmuyor ("N-2 bölü N üzere", "En kök, en ... Bu da 3 gelmiş"); sonuçları aktarılmadı. -->

### 9.2 $1^\infty$ belirsizliği için pratik kural

Bir öğrencinin isteği üzerine hoca, ekrandaki bir örneği boş tahtada yeniden ve açık açık çözdü. Önce kuralı yazdı. Hoca bu tür limitlerin birinci dönemdeki gibi $\ln$ alınarak da çözülebileceğini, ama aşağıdaki kuralın pratik olduğunu söyledi.

**Teorem ($1^\infty$ kuralı)**

- $\lim\limits_{n\to\infty}a_n=0$,
- $\lim\limits_{n\to\infty}b_n=\infty$,
- $\lim\limits_{n\to\infty}a_nb_n=\lambda$ ise

$$\lim_{n\to\infty}\left(1+a_n\right)^{b_n}=e^{\lambda}$$

> **Ek bilgi (derste anlatılmadı):** Kuralın nedeni $(1+a_n)^{b_n}=e^{\,b_n\ln(1+a_n)}$ yazılışıdır. $a_n\to0$ iken $\ln(1+a_n)$ yaklaşık $a_n$'e eşittir; daha kesin olarak $\dfrac{\ln(1+a_n)}{a_n}\to1$. Bu yüzden üs $a_nb_n$ ile aynı limite gider ve sonuç $e^\lambda$ olur. Hocanın "$\ln$ alarak da yapılabilir" dediği yol budur.

### 9.3 Örnek 17: $\lim\limits_{n\to\infty}\left(1+\dfrac{2}{5n}\right)^{3n}$

- $a_n=\dfrac{2}{5n}$: sayı bölü sonsuz, $0$'a gider. Birinci koşul sağlanır.
- $b_n=3n\to\infty$. İkinci koşul sağlanır.
- Çarpım: $a_nb_n=\dfrac{2}{5n}\cdot3n=\dfrac{6n}{5n}=\dfrac65$. $n$'ler sadeleşir.
- $\lambda=\dfrac65$ olduğundan:

$$\lim_{n\to\infty}\left(1+\frac{2}{5n}\right)^{3n}=e^{6/5}$$

**Soru:** Cevap $e^{-6/5}$ mi? **Cevap:** Hayır. Hoca önce yanlışlıkla "eksi" dedi, sonra düzeltti: Doğru cevap $e^{6/5}$'tir. Pozitif $\lambda$ için üs pozitiftir.

### 9.4 Örnek 18: $\left(-\dfrac12\right)^n$

- İçerideki sayı $x=-\dfrac12$'dir ve $\left|-\dfrac12\right|<1$. Kurala göre dizi $0$'a gider.
- Hocanın mantık açıklaması: Mutlak değer $\dfrac{1^n}{2^n}$'dir. $1^n=1$ kalır, $2^n$ sonsuza gider. Sayı bölü sonsuz $0$'a gider. Önündeki $\pm$ işaret sonucu değiştirmez.

### 9.5 Örnek 19: İki dizinin çarpımı

Hoca iki dizinin çarpımı biçiminde bir dizi gösterdi ve limiti limit kurallarıyla parça parça aldı: çarpımın limiti limitlerin çarpımı, toplamın limiti limitlerin toplamı. Hocanın sözlü anlatımına göre bir çarpanda $2$ ile $\dfrac{1}{2^n}$ gibi bir terim vardı. $\dfrac{1}{2^n}$ (sayı bölü sonsuz) $0$'a gittiği için o çarpanın limiti $2$ çıktı. Diğer çarpanın limiti $3$ çıktı. Sonuç $2\cdot3=6$. Dizi yakınsaktır.

<!-- BELİRSİZ: 01:41:39-01:42:31'deki çarpım dizisinin tam ifadesi altyazıda yok; yalnız parça limitlerin 2 ve 3 olduğu ve sonucun 6 çıktığı anlaşılıyor. -->

## 10. Sonlu Sayıda Terim Dizinin Karakterini Değiştirmez

İkinci aradan sonra hoca bir soruyla başladı. Gerekçesi: Sorularla hafızaya yerleşen bilgi kullanılmaya müsait bilgidir.

### 10.1 Örnek 20: Düzensiz başlayan bir dizi

Dizi: $\dfrac12,\ -\dfrac13,\ \dfrac1{20},\ 200,\ \dfrac19,\ \dfrac1{99},\ \dfrac1{999},\ \dfrac1{9999},\ \dots$

Bu dizi yakınsak mıdır?

Bir öğrenci "sıfıra yakınsak" dedi. Başka bir öğrenci terimlerin bu sırayla mı yazıldığını sordu. Hoca sıralamanın doğru olduğunu ve dizinin $\dfrac1{999},\ \dfrac1{9999},\dots$ diye devam ettiğini söyledi.

Çözüm:

- İlk birkaç terim düzensiz: biri negatif, biri $200$ gibi büyük bir sayı.
- Ama bir yerden sonra bütün terimler $\dfrac1{9\dots9}$ biçiminde ve $0$'a yaklaşıyor.
- Limit tanımına göre, sonlu sayıdaki terimler hariç diğer bütün terimler $0$'ın etrafında yığılıyor.
- Sonuç: Dizi $0$'a yakınsar.

> **Hocanın vurgusu:** Dizinin karakterini belirleyen sonlu sayıdaki terimler değil, sonsuz sayıdaki terimlerdir. Başlangıçtaki terimler farklı farklı olsa da bu diziyi ıraksak yapmaz.

## 11. Serilere Giriş: Zıplayan Top Problemi

Hoca "seri nedir?" diye sordu. Öğrencilerden "örüntülü diziler" ve "diziler arasındaki işlemler" cevapları geldi. Hoca ikinci cevabı beğendi ve seriyi bir problemle tanıttı.

**Problem:** $10$ m yükseklikten bırakılan bir top, her yere çarpışında düştüğü yüksekliğin yarısı kadar yükseliyor. Önce $10$ m düşüyor, $5$ m yükseliyor, $5$ m düşüyor, $2{,}5$ m yükseliyor ve bu böyle sürüyor.

- (a) Top durur mu?
- (b) Topun aldığı toplam yol hesaplanabilir mi?

Öğrencilerin bir kısmı "durur", çoğu "durmaz" dedi. Hoca doğru cevabın "durmaz" olduğunu söyledi: Her sıçrama yüksekliği bir öncekinin yarısıdır. Yükseklik çok azalır, sıfıra çok yaklaşır, ama teorik olarak hiçbir zaman sıfır olmaz. Top sonsuz kez sıçrar.

Toplam yol için bir öğrenci "integral ile, sonsuza giderken" dedi. Hoca "limit alacağız, doğru" diye karşılık verdi. Bir öğrenci toplam yolun $20$ m olup olmadığını sordu. Hoca "henüz hesaplamadık" dedi; amacın şimdilik serilerin nereden çıktığını ve ne işe yaradığını göstermek olduğunu söyledi. Hesap bu notun Örnek Sorular bölümündedir.

Hoca buradan seri fikrine geçti. Topun aldığı yol, sonsuz sayıda terimin toplamıdır: $\sum_{n=1}^{\infty}a_n$. Sonsuza kadar toplama yapılamaz. Bunun yerine $n$. terime kadar toplanır:

$$S_n=\sum_{k=1}^{n}a_k$$

Sonra $n\to\infty$ için limit alınır. Bu limit sonlu bir $L$ sayısıysa serinin değeri $L$'dir. Hocanın yorumu: $n$'den sonra kalan kısım limitte sıfıra çok yakın değerlere gittiği için ihmal edilebilir. Yani top durmaz, ama aldığı yol serilerle hesaplanabilir.

Hoca ayrıca matematiğin ihtiyaçtan doğduğunu, doğadaki her şeyin bir ölçüsü ve hesabı olduğunu söyledi. Seriler de böyle bir ihtiyaçtan çıkmıştır.

## 12. Seri, Kısmi Toplamlar Dizisi ve Yakınsaklık

**Tanım (Seri)**

- Bir kurala göre birbirine bağlı sayılar dizisinin bütün terimlerinin toplamından elde edilen ifadeye seri denir:

$$\sum_{n=1}^{\infty}a_n=a_1+a_2+a_3+\dots$$

### 12.1 Örnek 21: $\sum\dfrac1n$ toplanabilir mi?

Hoca $1+\dfrac12+\dfrac13+\dots+\dfrac1n+\dots$ serisini gösterip toplamının bulunup bulunamayacağını sordu. Bir öğrenci "vardır" dedi. Hoca: Hayır, bu seri ıraksaktır. Toplam sonsuza kadar büyür, bir sayıda durmaz. Bu seriye harmonik seri denir (Bölüm 14).

### 12.2 $p$-serisi

Hoca genel bir kural verdi ve ispatlarının sonraki derslerde gösterileceğini söyledi:

**Teorem ($p$-serisi)**

$$\sum_{n=1}^{\infty}\frac{1}{n^p}\ \text{ serisi }\ \begin{cases}p>1\ \text{ise yakınsak,}\\ p\le1\ \text{ise ıraksaktır.}\end{cases}$$

Harmonik seri $p=1$ hâlidir, bu yüzden ıraksaktır.

### 12.3 Kısmi toplamlar dizisi

**Tanım (Kısmi toplamlar dizisi)**

- $S_1=a_1$
- $S_2=a_1+a_2$
- $S_3=a_1+a_2+a_3=\sum_{k=1}^{3}a_k$
- $S_n=a_1+a_2+\dots+a_n=\sum_{k=1}^{n}a_k$

$(S_n)$ dizisine serinin kısmi toplamlar dizisi (sequence of partial sums) denir. Hoca $S_n$'in "$n$. terim" değil, ilk $n$ terimin toplamı olduğuna dikkat çekti.

**Tanım (Serinin yakınsaklığı)**

- $\lim\limits_{n\to\infty}S_n=S$ sonlu bir sayıysa seri yakınsaktır ve toplamı $S$'dir: $\sum_{n=1}^\infty a_n=S$.
- $\lim S_n=+\infty$ ya da $-\infty$ ise ya da limit mevcut değilse seri ıraksaktır.

> **Hocanın vurgusu:** Serinin karakterini belirleyen, kısmi toplamlar dizisinin limitidir.

Hoca ekrandaki tanımda serinin $a_1+a_2+\dots$ biçiminde değil, $\sum_{n=1}^{\infty}a_n=S$ biçiminde yazılması gerektiğini de belirtti.

## 13. Geometrik Seri

Hoca geometrik diziyi hatırlattı: İlk terim $a$ (ya da $a_1$), ikinci terim $ar$, üçüncü terim $ar^2$, ... Bir sonraki terimin bir öncekine oranı sabittir. Bu sabit $r$'ye ortak çarpan denir. Terimler sonsuza kadar toplanırsa geometrik seri elde edilir.

**Tanım (Geometrik seri)**

$$a+ar+ar^2+\dots=\sum_{n=1}^{\infty}ar^{n-1}$$

> **Ders sonrası not:** Hoca seriyi önce "$a_1$ çarpı $r$ üzeri $n$, $n=1$'den sonsuza" diye yazdı. Bu yazılış ilk terimi $ar$ yapar; ilk terimin $a$ olması için üs $n-1$ olmalıdır: $\sum_{n=1}^\infty ar^{n-1}$. Hoca sonraki örneklerde $n-1$ üssünü kullandı.

### 13.1 Kısmi toplamın türetilmesi

Hoca ezber yerine kâğıt kalemle türetmeyi önerdi:

- Birinci satır: $S_n=a+ar+ar^2+\dots+ar^{n-1}$
- İkinci satır: Her terim $r$ ile çarpılır: $rS_n=ar+ar^2+\dots+ar^{n-1}+ar^n$
- Taraf tarafa çıkarılır. Ortadaki terimler birbirini götürür: $S_n-rS_n=a-ar^n$
- $S_n$ parantezine alınır: $S_n(1-r)=a(1-r^n)$
- $r\neq1$ için:

$$S_n=\frac{a(1-r^n)}{1-r}$$

### 13.2 Yakınsaklık

Sorun $r^n$ teriminin davranışındadır:

- $|r|<1$ ise $r^n\to0$ olur ve

$$\lim_{n\to\infty}S_n=\frac{a}{1-r}$$

- $|r|\ge1$ ise seri ıraksaktır; toplam bulunamaz.

Hoca türetmeyi $a=1$ için yaptı ve sonucu "$\dfrac{1}{1-r}$" diye söyledi.

> **Ders sonrası not:** Hoca bir örnekte toplam formülünü "$r$ bölü $1-r$ idi" diye andı, ama hesabı ilk terim bölü $(1-r)$ ile yaptı. Doğru formül $\dfrac{a}{1-r}$'dir; burada $a$ serinin ilk terimidir.

### 13.3 Örnek 22: $1+\dfrac12+\dfrac14+\dots$

- Seri $1$ ile başladığı için genel terim $\left(\tfrac12\right)^{n-1}$ olarak yazılır. $n=1$ için $\left(\tfrac12\right)^0=1$, $n=2$ için $\tfrac12$:

$$\sum_{n=1}^{\infty}\left(\frac12\right)^{n-1}$$

- İlk terim $a=1$, ortak çarpan $r=\tfrac12$. $|r|<1$.
- Toplam:

$$\frac{1}{1-\frac12}=2$$

Seri $2$'ye yakınsar.

### 13.4 Örnek 23 (çıkmış sınav sorusu): $\pi-e+\dfrac{e^2}{\pi}-\dfrac{e^3}{\pi^2}+\dots$

Hoca bunun yaklaşık sekiz yıl önce ve dört yıl önce sınavda çıkmış bir soru olduğunu söyledi. "Pi var, e var, nasıl yapacağız?" diye sordu.

- **Tür:** Bir öğrenci "geometrik" dedi. Ortak çarpan ilk bakışta görünmüyor.
- **$\pi$ parantezine alma:**

$$\pi\left(1-\frac e\pi+\frac{e^2}{\pi^2}-\frac{e^3}{\pi^3}+\dots\right)$$

- **Genel terim:** İşaretler eksi-artı gidiyor. İlk terim $\pi$ olsun diye üs $n-1$ alınır ($n=1$ için $\left(\tfrac e\pi\right)^0=1$). İşaret için $(-1)^{n-1}$ eklenir:

$$\sum_{n=1}^{\infty}(-1)^{n-1}\,\pi\left(\frac{e}{\pi}\right)^{n-1}=\sum_{n=1}^{\infty}\pi\left(-\frac{e}{\pi}\right)^{n-1}$$

- **Ortak çarpan:** $r=-\dfrac e\pi$. Bir öğrenci $e\approx2{,}71$ ve $\pi\approx3{,}14$ olduğunu söyledi. Bu yüzden $|r|=\dfrac e\pi\approx0{,}865<1$. Seri yakınsaktır.
- **Toplam:** İlk terim $a=\pi$:

$$\frac{\pi}{1-\left(-\frac e\pi\right)}=\frac{\pi}{1+\frac e\pi}=\frac{\pi^2}{\pi+e}$$

**Soru:** Paydada artı olmayacak mıydı? **Cevap:** Hoca önce paydayı $1-\dfrac e\pi$ yazmıştı. Öğrencinin uyarısıyla düzeltti: $r$ negatif olduğu için $1-r=1+\dfrac e\pi$ olur. Şıklarda $\dfrac{\pi^2}{e+\pi}$ seçeneği bulunuyordu.

### 13.5 Örnek 24: $1+\sqrt2+2+2\sqrt2+\dots$

- Ortak çarpan $r=\sqrt2$.
- Öğrenciler $\sqrt2$'nin $1$'den büyük olduğunu söyledi.
- $r>1$ olduğu için seri ıraksaktır; terimler büyüyerek $+\infty$'a gider. Hoca test sorusunda "$+\infty$'a ıraksar" şıkkının doğrudan işaretleneceğini söyledi.

Hoca ardından notlardaki "$0{,}32$ sayısını serileri kullanarak iki tam sayının oranı olarak yazınız" sorusunu okudu ama çözmeden geçti (Örnek Sorular bölümüne bakın).

## 14. Teleskopik ve Harmonik Seriler

**Tanım (Teleskopik seri)**

- Bir serinin terimleri basit kesirlere ayrılarak iki ifadenin farkı şeklinde yazılabiliyor ve kısmi toplamı bu yolla basit bir formüle getirilebiliyorsa, bu seriye teleskopik seri denir.
- Kısmi toplam açılınca ara terimler birbirini götürür. Geriye baştan ve sondan birkaç terim kalır.

**Tanım (Harmonik seri)**

$$\sum_{n=1}^{\infty}\frac1n=1+\frac12+\frac13+\dots$$

serisine harmonik seri denir. Bölüm 12'de görüldüğü gibi ıraksaktır.

> **Ek bilgi (derste anlatılmadı):** Harmonik serinin ıraksaklığı terimler gruplanarak görülebilir: $\tfrac13+\tfrac14>\tfrac12$, $\tfrac15+\dots+\tfrac18>\tfrac12$, ... Her grup $\tfrac12$'den büyük olduğu ve sonsuz grup olduğu için kısmi toplamlar sınırsız büyür. Terimlerin $0$'a gitmesi serinin yakınsak olması için yeterli değildir.

### 14.1 Örnek 25: $\sum\limits_{k=1}^{\infty}\dfrac{1}{k(k+1)}$

- Toplam doğrudan bulunamıyor. Terim basit kesirlere ayrılır, integralde yapıldığı gibi:

$$\frac{1}{k(k+1)}=\frac{A}{k}+\frac{B}{k+1}=\frac1k-\frac1{k+1}$$

- Kısmi toplam açılır (ara adım eklendi):

$$S_n=\left(1-\frac12\right)+\left(\frac12-\frac13\right)+\dots+\left(\frac1n-\frac1{n+1}\right)=1-\frac{1}{n+1}$$

- $n\to\infty$ için $\dfrac1{n+1}\to0$. Toplam:

$$\sum_{k=1}^{\infty}\frac{1}{k(k+1)}=1$$

### 14.2 Örnek 26: $\sum\dfrac{1}{k^2+3k+2}$

- Normal yolla toplanamaz. Teleskopik hâle getirilir. Payda çarpanlara ayrılır: çarpımları $2$, toplamları $3$ olan sayılar $1$ ve $2$'dir:

$$k^2+3k+2=(k+1)(k+2)$$

- Basit kesirlere ayırma:

$$\frac{1}{(k+1)(k+2)}=\frac{A}{k+1}+\frac{B}{k+2}=\frac{1}{k+1}-\frac{1}{k+2}$$

Hoca katsayıların "tesadüfen" ikisinin de $1$ (mutlak değerce) çıktığını söyledi.

- $k=1, 2, 3, \dots$ yazılınca terimler birbirini götürür. Baştan bir terim, sondan bir terim kalır.
- Son terim $n\to\infty$ için $0$'a gider. Hoca "geriye $1$ kaldı" dedi.

<!-- BELİRSİZ: Serinin hangi $k$ değerinden başladığı ve hocanın söylediği sonuç ("1 kaldı ... iliştir") altyazıda net değil. -->

> **Ders sonrası not:** Seri $k=1$'den başlarsa $S_n=\dfrac12-\dfrac1{n+2}$ olur ve toplam $\dfrac12$'dir. Seri $k=0$'dan başlarsa $S_n=1-\dfrac1{n+2}$ olur ve toplam $1$'dir. Hocanın "1 kaldı" demesi büyük olasılıkla serinin $k=0$'dan başladığını gösterir; $k=1$'den başlayan yazılışta doğru cevap $\dfrac12$'dir.

### 14.3 Örnek 27 (sınav sorusu): Logaritmalı teleskopik seri

Hoca bu soruyu "zevkli, çok orijinal" bir sınav sorusu olarak gösterdi.

- Seri doğrudan toplanamaz. Logaritma özellikleri kullanılarak bilinen bir biçime dönüştürülür.
- Önce $\ln$ içindeki ifadenin paydaları eşitlenir ve çarpanlarına ayrılır.
- Toplamın logaritması yerine logaritmaların toplamı, o da çarpımın logaritması olarak yazılır: $\sum\ln(\dots)=\ln\prod(\dots)$.
- Çarpımdaki çarpanlar birbirini götürür. Kısmi toplam:

$$S_n=\ln\frac{n+1}{2n}$$

- Limit alınırken, limit $\ln$'in içine alınabilir (hocanın ifadesiyle "limit çok esnek"):

$$\lim_{n\to\infty}S_n=\ln\left(\lim_{n\to\infty}\frac{n+1}{2n}\right)=\ln\frac12$$

Bir öğrenci içerideki limitin $\tfrac12$ olduğunu söyledi; hoca onayladı.

<!-- BELİRSİZ: Serinin ifadesi altyazıda okunmuyor ("n-1 bölü n-2, ... n-1 çarpı n-1"). -->

> **Ders sonrası not:** Kısmi toplamı $\ln\dfrac{n+1}{2n}$ olan bilinen seri büyük olasılıkla $\sum_{n=2}^{\infty}\ln\left(1-\dfrac1{n^2}\right)$'dir. Bu durumda $1-\dfrac1{n^2}=\dfrac{(n-1)(n+1)}{n\cdot n}$ olur ve $n=2$'den $N$'ye kadar çarpım $\dfrac{N+1}{2N}$'ye sadeleşir. Toplam $\ln\dfrac12=-\ln2$'dir.

## 15. Serilerle İşlemler ve Sonraki Ders

**Teorem (Serilerle işlemler)** $\sum a_n=A$ ve $\sum b_n=B$ ise:

- $\sum(a_n\pm b_n)=A\pm B$
- $\sum k\,a_n=kA$. Bir seriyi bir sayıyla çarpmak her terimini o sayıyla çarpmak demektir.

Hoca notlardaki diğer seri örneklerini ve testleri bir sonraki derste uygulama olarak çözeceğini söyledi. Öğrencilerden bu örnekleri önceden çözmelerini istedi. Ders notlarının internette "YTÜ Matematik notları" adıyla bulunabileceğini, kendi yazdığı kitabın henüz yayımlanmadığını belirtti.

## Örnek Sorular

Bu bölüm, derste hocanın sözlü sorduğu ya da ekranda okuduğu sorulardan kuruldu. Bu iş için kare yoktur; ifadeler altyazıdan alındı.

**Soru 1** (derste sözlü, 00:30:09 ve 00:31:37): $2, 4, 6, 8, \dots$ dizisinin 50. ve 77. terimi nedir?

- Çözüm (derste verildi): Genel terim $a_n=2n$. $a_{50}=100$, $a_{77}=154$.

**Soru 2** (derste sözlü, 00:37:18): $\dfrac1n$ dizisi sınırlı mıdır?

- Çözüm (derste verildi): $n$ doğal sayı olduğundan her $n$ için $0<\dfrac1n\le1$. Dizi sınırlıdır.

**Soru 3** (derste sözlü, 00:43:12): $\dfrac{n}{n+1}$ dizisi sınırlı mıdır? Ebas ve eküsü nedir?

- Çözüm (derste verildi): Sınırlıdır. Ebas $\tfrac12$ (ilk terim), eküs $1$ (terimler $1$'e yaklaşır ama ulaşmaz).

**Soru 4** (derste sözlü, 01:11:54): $\lim\limits_{n\to\infty}\dfrac{\sin n}{n}$ nedir? Seçenekler derste öğrencilerden geldi: $1$, $0$, limit yok.

- Çözüm (derste verildi): $-\dfrac1n\le\dfrac{\sin n}{n}\le\dfrac1n$ ve iki uç $0$'a gider. Sandviç teoreminden limit $0$.

**Soru 5** (derste sözlü, 01:22:15): $\sin(n\pi)$ dizisi yakınsak mıdır? Nereye yakınsar?

- Çözüm (derste verildi): Her doğal sayı $n$ için $\sin(n\pi)=0$. Dizi yakınsaktır, limiti $0$'dır. "Limit yok" cevabı $\sin(\pi x)$ fonksiyonu için doğrudur.

**Soru 6** (derste sözlü, 01:36:03): $\lim\limits_{n\to\infty}\left(1+\dfrac{2}{5n}\right)^{3n}$ nedir?

- Çözüm (derste verildi): $a_n=\dfrac2{5n}\to0$, $b_n=3n\to\infty$, $a_nb_n=\dfrac65$. Sonuç $e^{6/5}$.

**Soru 7** (derste sözlü, 02:05:05): $\dfrac12,\ -\dfrac13,\ \dfrac1{20},\ 200,\ \dfrac19,\ \dfrac1{99},\ \dfrac1{999},\ \dots$ dizisi yakınsak mıdır?

- Çözüm (derste verildi): Sonlu sayıdaki düzensiz terim dizinin karakterini değiştirmez. Sonraki bütün terimler $0$'a yaklaştığı için dizi $0$'a yakınsar.

**Soru 8** (derste sözlü, 02:09:58): $10$ m yükseklikten bırakılan top her seferinde düştüğü yüksekliğin yarısı kadar yükseliyor. (a) Top durur mu? (b) Topun aldığı toplam yol nedir?

- (a) Derste verildi: Teorik olarak durmaz, sonsuz kez sıçrar.

> **Çözüm (derste verilmedi):** (b) İlk düşüş $10$ m'dir. Sonra her sıçramada top aynı yüksekliği bir kez çıkar, bir kez iner: $5$, $2{,}5$, $1{,}25$, ... m. Bu yükseklikler ilk terimi $5$, ortak çarpanı $\tfrac12$ olan geometrik seridir: $5+2{,}5+1{,}25+\dots=\dfrac{5}{1-\frac12}=10$. Çıkış ve iniş için iki katı alınır: $2\cdot10=20$ m. Toplam yol $10+20=30$ m. Derste bir öğrencinin önerdiği $20$ m yalnız sıçramaların yoludur, ilk düşüşü içermez. (sympy ile doğrulandı.)

**Soru 9** (derste sözlü, 02:31:12; çıkmış sınav sorusu): $\pi-e+\dfrac{e^2}{\pi}-\dfrac{e^3}{\pi^2}+\dots$ serisinin toplamı nedir?

- Çözüm (derste verildi): $a=\pi$, $r=-\dfrac e\pi$, $|r|<1$. Toplam $\dfrac{\pi}{1+\frac e\pi}=\dfrac{\pi^2}{\pi+e}$.

**Soru 10** (derste sözlü, 02:37:45): $0{,}32$ sayısını serileri kullanarak iki tam sayının oranı olarak yazınız.

<!-- BELİRSİZ: Altyazıda sayının devirli ($0{,}\overline{32}=0{,}323232\dots$) olduğu söylenmiyor; "serileri kullanarak" ifadesinden devirli olduğu varsayıldı. -->

> **Çözüm (derste verilmedi):** $0{,}\overline{32}=\dfrac{32}{100}+\dfrac{32}{100^2}+\dfrac{32}{100^3}+\dots$ bir geometrik seridir. İlk terim $a=\dfrac{32}{100}$, ortak çarpan $r=\dfrac1{100}$. Toplam $\dfrac{32/100}{1-1/100}=\dfrac{32/100}{99/100}=\dfrac{32}{99}$. (sympy ile doğrulandı.)

## Dersin Toparlaması

Bu derste dizinin, doğal sayılardan reel sayılara tanımlı bir fonksiyon olduğu görüldü. Verilen terimlerden genel terim yazma, sınırlılık (ebas ve eküs), monotonluk (fark ya da oran ile) incelendi. Ardından dizinin limiti tanımlandı: Sonlu sayıdaki terimler hariç bütün terimler bir sayının etrafında yığılıyorsa dizi o sayıya yakınsar. Limit kuralları, sandviç teoremi, eşlenikle çarpma ve L'Hôpital kuralıyla limit hesaplandı. Yakınsak dizinin sınırlı olduğu, ama sınırlı dizinin yakınsak olmayabileceği $(-1)^n$ ile gösterildi. Monoton dizi teoremi, sıkça rastlanan limitler ve $1^\infty$ belirsizliği için $e^\lambda$ kuralı verildi. $\sin(n\pi)$ ile $\sin(\pi x)$ farkı gibi, dizinin indisinin doğal sayı olmasından gelen inceliklere dikkat çekildi.

Dersin son kısmında seriler, zıplayan top problemiyle tanıtıldı. Bir serinin karakterini kısmi toplamlar dizisinin limitinin belirlediği gösterildi. Geometrik serinin kısmi toplamı türetildi ve $|r|<1$ iken toplamın $\dfrac{a}{1-r}$ olduğu bulundu. $p$-serisi kuralı ve harmonik serinin ıraksaklığı söylendi. Teleskopik serilerde basit kesirlere ayırma ve logaritma özellikleriyle ara terimlerin götürülmesi örneklendi. Sonraki derste serilere devam edilecek: yakınsaklık testleri ve uygulama soruları çözülecek, ardından Taylor ve Maclaurin serilerine geçilecek. Hocaya göre diziler ve seriler uygulamalarıyla birlikte 2-3 haftada bitecek, sonra çok değişkenli fonksiyonlara geçilecek.

> **Ders sonrası not:** Hoca dönem konularını sayarken "Laurent ve Taylor serileri" dedi. Laurent serisi büyük olasılıkla bu derste değil, karmaşık analiz derslerinde işlenir; Matematik 2'de Taylor ve Maclaurin serileri işlenir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
