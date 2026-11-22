# Ders 3 Genişletilmiş Notu: İşaretlerin Sınıflandırılması ve İşaretler Üzerinde Temel İşlemler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. İşaret Nedir?
- 2. Sistem Nedir?
- 3. İşaretleri Sinüzoidallerin Toplamı Olarak Görmek
- 4. Neden Frekans Domeni?
- 5. Sinüzoidal İşaretin Parametreleri
- 6. İşaretlerin Sınıflandırılması
- 7. Çift-Tek Ayrıştırması
- 8. Deterministik ve Rastgele İşaretler, Bir Örnek
- 9. MATLAB ile İlk İşaret
- 10. Sürekli ve Ayrık İşaretler, Sistem Türleri
- 11. İşaretler Üzerinde İşlemler
- 12. Periyodik İşaretler
- 13. Ders Sonundaki Sorular
- Örnek Sorular

## 1. İşaret Nedir?

Dersin adı İngilizcede "Signals and Systems"tir; Türkçeye "işaretler ve sistemler" diye de çevrilebilir. Hoca derse işaretin genel bir tanımını vererek başladı ve tanımı ekrana yazdı (ekrandan, 00:10:00):

> İşaretler, fiziksel bir durum hakkında bilgi taşıyan, bir ya da birden fazla değişkene bağlı fonksiyonlar olarak tanımlanabilir.

Önceki derste çoğunlukla bir boyutlu işaretlerden, yani tek değişkeni zaman olan $x(t)$ işaretlerinden söz edilmişti. İki boyutlu işarete örnek gri seviyeli bir görüntüdür. Piksel kavramı olmasa bile, örneğin eski tip fotoğraf filmine çekilmiş bir resim iki değişkene bağlıdır. Bu değişkenler zaman değil, konumla ilgili uzamsal (spatial) değişkenlerdir. Üç boyutlu işarette yapı bir küpe dönüşür. Her katmanında farklı bilgi taşıyan MR gibi biyomedikal görüntüler buna örnektir; burada fonksiyon $x$, $y$ ve $z$ yönlerinin üçünde de değişim gösterir.

Slayttaki örneklere göre işaretleri genellikle haberleşme ve bilgi açısından düşünürüz: radyo işareti, havadan ya da kablodan gelen TV yayını, ses, bir devredeki elektrik gerilimi ya da akımı. Daha genel olarak ölçülebilen ya da ölçülebilen bir şeyi etkileyen her fiziksel ya da soyut büyüklük bir işarettir: bisiklet fren kablosundaki gerginlik, bir uzay aracının dönme hızı, bir hücredeki enzim derişimi, doların avro karşısındaki fiyatı (ekrandan, 00:10:00). Hoca akım örneğinde şuna dikkat çekti: akım soyut bir kavram gibi görünür, ama elektronların yer değiştirmesinden kaynaklanan ölçülebilir bir büyüklüktür.

Bu derste iki tür işaret birlikte işlenecek: sürekli (analog) ve ayrık (discrete) işaretler. İşaretin değişkeni sonsuz sayıda değer alabiliyorsa işaret süreklidir, yalnız belirli değerleri alıyorsa ayrıktır.

> **Hocanın vurgusu:** Sürekli işaretlerde gösterim normal parantezle yapılır: $x(t)$. Ayrık işaretlerde köşeli parantez kullanılır: $x[n]$. Buradaki $n$ sürekli olmayan, indis değerleri alan bir değişkendir.

## 2. Sistem Nedir?

Hoca sistemin en temel tanımını da ekrana yazdı:

> Sistemler, istenilen niteliklerde işaret üreten ya da verilen giriş işaretlerine göre belirli çıkışlar üreten düzeneklerdir.

Bir sistemi bir kutu gibi düşünebiliriz. Kutunun bir girişi ve bir çıkışı vardır. Girişe işaret verilir, çıkışta bu işaretin değiştirilmiş, istediğimiz forma getirilmiş hali oluşur. Kutunun içeriği, yani sistemin tasarımı, sistemin özelliklerini belirler. Radyo alıcısı, ses yükseltici, modem, mikrofon ve cep telefonu birer sistemdir. Biyolojik açıdan hücresel metabolizma, ekonomik açıdan da ekonomik veriler arasındaki ilişkiler birer sistemdir. Bir sistemde sürekli ve ayrık işaretler birlikte bulunabilir. Önemli olan, giriş işaretinin istenen çıkış işaretine dönüştürülmesini sağlayan tanımlı bir düzenin olmasıdır.

Slaytta üç örnek vardı:

- **Kütle-yay sistemi:** Bir yaya bağlı yük, girişte yukarı çekilir ya da itilir. Girişe sinüzoidal bir hareket uygulanırsa yük belli bir noktadan başlayarak sönümlenen sinüzoidal bir hareket yapar.
- **Tank sistemi:** İki sıvı tankı vardır. Birinci tanka giren sıvı bir süre açık kalıp sonra kesilir. Birinci tankta sıvı kesilene kadar belli bir yüksekliğe çıkar. İkinci tanka önce az sıvı akar, sonra seviye hızla yükselir, akış azaldıkça seviye düşer ve sonunda biter.
- **Cep telefonu sistemi:** Telefonun içinde analogdan sayısala çevirici vardır. İşaret baz istasyonlarına gider, belli bir protokolle iletilir, karşı tarafta sayısaldan analoga çevrilir ve yeniden ses olur. Bu ağ çok karmaşık alt birimlerden oluşur; telefonlar kulelerle elektromanyetik işaretlerle haberleşir, kuleler arasında hız için fiber kablo bulunur. Biz bütün bunları bir soyutlamayla tek bir "cep telefonu sistemi" olarak görürüz.

İşaret ve sistem yaklaşımı elektriksel, mekanik, optik, akustik, biyolojik ve finansal her alana uyarlanabilir. Bu yüzden bu ders temel bir derstir. Derste daha çok elektriksel işaretler üzerinde durulacak.

## 3. İşaretleri Sinüzoidallerin Toplamı Olarak Görmek

Hoca önceki derste Fourier dönüşümünden söz ederken anlattığı bir fikri hatırlattı: herhangi bir $x(t)$ işareti, kendisini oluşturan sonsuz sayıda sinüsün toplamı şeklinde ifade edilebilir. Demek ki her sürekli ya da ayrık işaretin temel yapı taşları vardır ve bunlar sinüzoidallerdir, yani belli bir frekansla salınan işaretler.

Slayttaki örnekte en alttaki işaret, farklı genliklerde ve farklı frekanslardaki birkaç sinüzoidalin toplamıydı. Bu bileşenler deterministiktir: matematiksel fonksiyonu biliniyorsa zamanın her anındaki değeri hesaplanabilir.

## 4. Neden Frekans Domeni?

Bileşenlerin her biri farklı bir frekansa sahiptir. Farklı işaretlerin frekans içerikleri farklı olduğu için, frekans içeriğini bilmek işaretten bilgi edinmeyi kolaylaştırır. Hangi frekansın baskın olduğunu, işarete özgü hangi frekansların bulunduğunu görebilir, farklı işaretleri birbirinden ayırabiliriz.

Hoca "domain" sözcüğünü "uzay" diye çevirdi. Bir işaretin zamana göre nasıl değiştiğini çizdiğimizde yatay eksen $t$'dir ve buna zaman domeni (time domain) denir. Yatay eksen $f$ olur ve işaretin içindeki frekanslar gösterilirse buna frekans domeni denir. "Representation" da gösterim ya da sunum anlamındadır (ekrandan, 00:25:00).

Slayta göre frekans domeni gösterimi:

- birçok işaret türü için daha basittir (örneğin AM radyo işareti),
- doğrusal (linear) sistemler gibi birçok sistemin analizini kolaylaştırır,
- bir sistemin temel karakteristiklerini ortaya çıkarır,
- zamanla gerçek dünya hakkında alternatif bir düşünme biçimine dönüşür.

### 4.1 Piyano Örneği

Slaytta piyanoda bir akora basıldığında oluşan ses gösteriliyordu. Hoca sunumdaki ses dosyasını çalmaya çalıştı, ama dosya sunuma gömülü değildi. Zaman domenindeki görüntüde önce yüksek bir ses çıkar, sonra genlik azalarak kaybolur. Tek bir notaya basıldığında temel bir frekans ve zamanla onun harmonikleri oluşur. Akorda ise birkaç tuşa birlikte basılır, yani ses birkaç frekansın birleşimidir. Bileşenler farklı hızlarda sönümlenebildiği için işaretin içeriği zamanla değişir.

Zaman domeninde Do majör akoruna da Re majör akoruna da bassanız hemen hemen aynı görüntüyü elde edersiniz. Frekans domeninde ise, frekansı analiz eden bir algoritma kullanırsanız, hangi tuşlara basıldığını açıkça görebilirsiniz. Slayttaki akorun frekans gösteriminde üç baskın frekans ve bunların harmonikleri vardı.

Ders arasında bir öğrenci frekans domenindeki çizimin tekrar açıklanmasını istedi. Hoca piyano klavyesini çizerek anlattı. Her tuş bir sinüzoidal ses üretir ve klavyede sağa gidildikçe frekans artar. Notalar C, D, E, F, G, A, B harfleriyle adlandırılır; bunlar sırasıyla Do, Re, Mi, Fa, Sol, La, Si'dir. Bu yedili yapı klavye boyunca tekrarlanır ve C1, D1, ..., C2, D2 diye numaralanır. Hoca bir arama sonucundaki frekans tablosunu gösterdi; tabloda C5 = 523,25 Hz, D5 = 587,33 Hz, E5 = 659,25 Hz idi (ekrandan, 00:35:00). Örneğin Do'ya basmak $\sin(2\pi\cdot 523\,t)$ gibi bir işaret, yanındaki Re'ye basmak $\sin(2\pi\cdot 587\,t)$ gibi bir işaret üretir.

> **Ders sonrası not:** Hoca 523 Hz'lik Do'yu "C4, piyanonun neredeyse orta noktasındaki Do" diye andı ve La sesi için "770 Hz miydi, emin değilim" dedi. Standart akortta orta Do (C4) yaklaşık 261,63 Hz'dir; 523,25 Hz C5'e karşılık gelir. La (A4) 440 Hz'dir. Bir yerde söylenen "528 Hz" de tablodaki 523 Hz'dir.

Birkaç tuşa birden basmak, gitarda birkaç tele basıp tek bir ses çıkarmaya benzer; buna akor denir. Duyduğumuz ses dört farklı tuşun frekanslarının toplamıdır. İnsan kulağı bu sesleri bir şekilde ayrıştırabilir. Elimizde 523 Hz'e mi 587 Hz'e mi basıldığını analiz eden bir algoritma olsaydı, hangi tuşların basıldığını ayırt edebilirdik. Doğrudan zaman domenindeki gösterimden bunu pek ayırt edemeyiz.

**Soru:** Alttaki grafik zamanın daha kısa bir parçasına mı bakıyor? Örneğin 0,5 ile 3,5 saniye arasındaki 3 saniyelik bir girişi alıp incelemiş gibi.

**Cevap:** Evet. İşaret parça parça da incelenebilir: bir aralık, sonra bir sonraki aralık. Böylece daha ayrıntılı bir analiz yapılır. Bu yöntemin adı kısa zamanlı Fourier dönüşümüdür (Short Time Fourier Transform). Frekansları daha dar aralıklarda daha iyi okumak için kullanılır, çünkü işaretin frekans içeriği zamanla değişebilir.

### 4.2 Doğrusal Sistemler Sinüzoidaller İçin Kolay Analiz Edilir

Slayttaki ikinci fikir şuydu: doğrusal sistemler sinüzoidaller için kolay analiz edilir. Örnek, arabanın bir kaldırıma (curb) çıkmasıydı. Kaldırım bir "basamak" (step) girişi olarak modellenebilir. Arabanın dinamiği bir dizi diferansiyel denklemle tanımlanır ve bu denklemleri keyfi bir giriş için doğrudan çözmek zordur (ekrandan, 00:30:00). Hoca örneği fren mekanizmasıyla da anlattı: frene basıldığı andan itibaren tekerleğin tutması ya da hızın azalması diferansiyel denklemlerle analiz edilebilir, ama bu denklemler amortisörlerin sıkışması, hızın üstel olarak azalması gibi birçok değişkene bağlıdır. Frekans domenine geçildiğinde basit bir transfer fonksiyonu elde edilir ve diferansiyel denklemler yerine basit doğrusal işlemlerle sonuca varılır. Hoca bunun ayrıntısının ileride gösterileceğini söyledi.

### 4.3 Hız Sabitleme Örneği

Bir arabanın hızını kontrol ettiğimizi düşünelim. Gaza daha çok basınca araba hızlanır. Sabit hızda gitmek için önce hızımızı bilmemiz, sonra ayağımızla gazı artırıp azaltmamız gerekir. Örneğin istenen hız 90 iken hız 85'e düştüyse 5'lik bir hata vardır. Bu hata belli bir kazanç katsayısıyla çarpılır ve gaz pedalına bir uyarı olarak uygulanır. Bu işlem ne kadar sık tekrarlanırsa sürüş o kadar sabit olur. Peki hız 85 ile 90 arasında salınıma (osilasyona) mı girecek, yoksa sabite yakın mı kalacak? Bu salınımı denetlemek istiyorsak frekans analizi yöntemlerinden yararlanırız.

## 5. Sinüzoidal İşaretin Parametreleri

Hoca önceki derste anlattığı sinüzoidal işaretin üç özelliğini hatırlattı: genlik, periyot ($T = 1/f$) ve işaretin başlangıçtan ne kadar kaydığını gösteren faz. Örneğin sinüs işareti, kosinüs işaretinin $90^\circ$ kaydırılmış halidir. Genel yazım şöyledir:

$$x(t) = A\cos(\omega t + \phi), \qquad \omega = 2\pi f$$

Burada $A$ genlik (amplitude), $\phi$ faz, $\omega$ radyan cinsinden açısal frekans, $f$ ise hertz cinsinden bildiğimiz frekanstır. Kosinüs yerine sinüs de yazılabilir.

### 5.1 Slayttaki Örnek

Slayttaki işaret şuydu (ekrandan, 00:45:00):

$$x(t) = 3\cos(2\pi\cdot 2\cdot t - 3\pi/4)$$

Slaytta parametreler $A = 3$, $f_0 = 2$, $\phi = 3\pi/4$, $T_0 = 1/f_0 = 0{,}5$ olarak verilmişti.

- **Periyot:** Hoca öğrencilere frekansı 2 olan bu işaretin periyodunu sordu; öğrenciler $1/2$ diye cevap verdi. $T_0 = 1/f_0 = 1/2$ s. İşaret bir tepe noktasından bir sonraki tepe noktasına yarım saniyede gelir; slaytta bu aralık "one period" diye işaretliydi.
- **Genlik:** Tepe değeri 3'tür; işaret $-3$ ile $3$ arasında salınır.
- **Faz:** $\pi$'yi $180^\circ$ alırsak $3\pi/4 = 3\cdot 180^\circ/4 = 135^\circ$. Tam periyotluk kayma $2\pi$, yani $360^\circ$'dir. Bu yüzden işaret, bir kosinüsün periyodun $3/8$'i kadar kaydırılmış halidir.
- **Tepe noktası:** Kosinüsün argümanı sıfır olduğunda değer en büyüktür. $4\pi t - 3\pi/4 = 0 \Rightarrow t = 3/16$ s. Bu noktada $x(3/16) = 3\cos 0 = 3$. Yarım saniye sonra, $t = 3/16 + 1/2$'de, kosinüs bir periyot tamamladığı için yine 3 değeri alınır. $t = 0$'da işaret $3\cos(-3\pi/4) \approx -2{,}12$ değerindedir (ara adım eklendi; numpy ile kontrol edildi).

> **Ders sonrası not:** Hoca fazı önce "270 derece" diye okudu, sonra $3\cdot 180/4 = 135^\circ$ olarak düzeltti. Ayrıca $3/16$ saniyeyi "yaklaşık 0,3 saniye" dedi; doğrusu $3/16 = 0{,}1875$ s'dir.

Sürekli işaretin en önemli özelliği $t$'nin bütün değerlerini almasıdır. Ayrık işaretlerde ise değişken sonsuz değer almaz, bir zaman indisine, yani tam sayılara karşılık gelir. Önceki derste anlatıldığı gibi, analog ses işaretinden sayısal ses dalgasına geçerken önce kuantalama seviyeleri tanımlanır, sonra kodlayıcılarla (encoder) ikili yapılara geçilir; sayısal işaret yalnız belirli değerleri alabilir.

## 6. İşaretlerin Sınıflandırılması

İşaretler belli karakteristiklerine göre kategorilere ayrılır. Derste beş sınıflandırma görüldü.

### 6.1 Sürekli ve Ayrık Zamanlı İşaretler

Birinci sınıflandırma zaman ekseninin sürekli mi ayrık (sayılabilir) mı olduğuna göredir. Sürekli zamanlı bir işaret zaman eksenindeki bütün gerçek sayılar için bir değer taşır. Ayrık zamanlı işaret ise çoğunlukla sürekli bir işaretin örneklenmesiyle elde edilir ve yalnız zaman ekseni boyunca eşit aralıklı noktalarda değer alır (ekrandan, 00:45:00). Hoca dersin bundan sonraki kısmında sürekli ve ayrık işaretlerin karşılaştırmalı olarak, eş zamanlı kullanılacağını söyledi.

### 6.2 Periyodik ve Aperiyodik İşaretler

Periyodik işaret belli bir süre sonra kendini tekrarlayan işarettir. Sinüs işareti buna örnektir, ama periyodik bir işaretin sinüs biçiminde olması gerekmez. Slayttaki örnekte $T_0$ aralığındaki işaret parçası, zaman boyunca aynı biçimde tekrar ediyordu. Kendini tekrar etmeyen işarete aperiyodik işaret denir (ekrandan, 00:50:00). Matematiksel tanım:

$$f(t) = f(t + T)$$

Yani $T$ kadar zaman geçtikten sonra işaret yine aynı genlik değerlerini alıyorsa periyodiktir.

### 6.3 Nedensel, Antinedensel ve Nedensel Olmayan İşaretler

- **Nedensel (causal) işaret:** Zamanın negatif olduğu yerlerde sıfırdır. Hoca bunu, negatif zaman olmayacağı için böyle tanımlanan işaretler diye açıkladı.
- **Antinedensel (anti-causal) işaret:** Nedenselin tersidir; pozitif zamanda sıfır değerini alır.
- **Nedensel olmayan (non-causal) işaret:** Zamanın negatif olduğu yerlerde de, pozitif olduğu yerlerde de değer alır.

### 6.4 Çift ve Tek İşaretler

Dördüncü sınıflandırma çift (even) ve tek (odd) işaretlerdir (ekrandan, 00:55:00).

- **Çift işaret:** $f(t) = f(-t)$. Pozitif yönde $a$ kadar gidildiğinde alınan değer ile negatif yönde $a$ kadar gidildiğinde alınan değer aynıdır. Kosinüs çift bir işarettir: örneğin $a$'da $0{,}7$ ise $-a$'da da $0{,}7$'dir. Çift işaretler düşey eksene göre simetriktir.
- **Tek işaret:** $f(t) = -f(-t)$. $a$'da ve $-a$'da alınan değerlerin büyüklüğü aynıdır, işareti terstir. Sinüs tek bir işarettir: $a$'da $0{,}7$ ise $-a$'da $-0{,}7$'dir. $-f(-a) = -(-0{,}7) = 0{,}7 = f(a)$ olduğu için tanım sağlanır.

## 7. Çift-Tek Ayrıştırması

"Decomposition" ayrıştırma demektir; "kompozit etmek" birleştirmek, "dekompozit etmek" ayrıştırmaktır. Her fonksiyon kendisini oluşturan bir çift ve bir tek parçaya ayrılabilir (ekrandan, 01:15:00):

$$e(t) = \frac{1}{2}\big[f(t) + f(-t)\big], \qquad o(t) = \frac{1}{2}\big[f(t) - f(-t)\big], \qquad f(t) = e(t) + o(t)$$

Çift parça, işaretin pozitif ve negatif yöndeki değerlerinin ortalamasıdır. Örneğin kosinüste $0{,}7$ ile $0{,}7$ toplanıp ikiye bölününce yine $0{,}7$ elde edilir. Tek parçada ise fark alınır; sinüste $0{,}7 - (-0{,}7)$ ikiye bölününce yine $0{,}7$ bulunur.

**Soru:** Ayrıştırmada iki farklı fonksiyonu birleştirip yeni bir fonksiyon mu elde ediyoruz, yoksa aynı fonksiyon üzerinde bir işlem mi yapıyoruz?

**Cevap:** Fonksiyonu bileşenlerine ayırıyoruz. Aşağıdaki örnek bunu gösteriyor.

### 7.1 Ayrıştırma Örneği

Slayttaki $f(t)$, $t = -1$'den $t = 0$'a doğrusal olarak $0$'dan $1$'e çıkar, $0 \le t \le 1$ aralığında $1$ değerinde sabit kalır, sonra sıfır olur.

1. **$f(-t)$'yi çiz.** $f(-x)$, $f(x)$'in düşey eksene göre aynalanmış halidir. Değişkenin başına gelen eksi, fonksiyonu eksene göre ters çevirir. $f(-t)$'de sabit kısım sola ($-1 \le t \le 0$), eğimli kısım sağa ($0 \le t \le 1$) geçer.
2. **Topla: $2e(t) = f(t) + f(-t)$.** $0 < t < 1$ için $f(t) = 1$, $f(-t) = 1 - t$, toplam $2 - t$ (ara adım eklendi). Sonuç $t = 0$'da $2$, $t = \pm 1$'de $1$ olan çift bir işarettir; slaytta "it's even!" diye işaretliydi.
3. **İkiye böl.** $e(t)$, $t = 0$'da $1$, $t = \pm 1$'de $0{,}5$ değerini alır.
4. **Çıkar: $2o(t) = f(t) - f(-t)$.** $0 < t < 1$ için $1 - (1 - t) = t$ (ara adım eklendi). Hoca birkaç noktayı tek tek hesapladı: $t = 0$'da $1 - 1 = 0$, $t = 1$'de $1 - 0 = 1$, $t = -1$'de $0 - 1 = -1$. Sonuç $-1$ ile $1$ arasında giden tek bir işarettir ("it's odd!").
5. **İkiye böl.** $o(t)$, $-0{,}5$ ile $0{,}5$ arasında gider.
6. **Kontrol: $e(t) + o(t) = f(t)$.** $t = 0$'da $1 + 0 = 1$, $t = 1$'de $0{,}5 + 0{,}5 = 1$, $t = -1$'de $0{,}5 - 0{,}5 = 0$. Bunlar $f(t)$'nin değerleridir (numpy ile kontrol edildi).

Çift ve tek parçaların biçimleri farklıdır: çift parça $\pm a$'da aynı değeri alır, tek parça zıt işaretli değerler alır.

## 8. Deterministik ve Rastgele İşaretler, Bir Örnek

Ders arasından sonra, hocanın yazarken imlecinin görünmemesi üzerine kısa bir teknik ayar yapıldı. Ardından beşinci sınıflandırmaya geçildi.

**Deterministik işaret:** Zamanın her anında alacağı değerler bir matematiksel ifade, kural ya da tabloyla bellidir. Örneğin $\sin(\omega t)$'de $t$'ye değer verince alınacak değerler bellidir.

**Rastgele işaret:** Herhangi bir anda alacağı değer bir matematiksel fonksiyonla belirli değildir.

Hoca sordu: Konuşma işareti deterministik midir, rastgele midir? Bir öğrenci, matematiksel bir ifadesi olmadığı için rastgele sayılabileceğini söyledi. Hoca doğruladı: ders anlatırken söyleyeceği bir sonraki cümleyi ya da kelimeyi dinleyenler bilemez, bu yüzden konuşma işareti rastgeledir.

### 8.1 Örnek: Bir İşaretin Özellikleri

Slayttaki örnek şuydu (ekrandan, 01:25:00):

$$f(t) = \begin{cases} \sin(2\pi t)/t, & t \ge 1 \\ 0, & t < 1 \end{cases}$$

Bu işaretin özellikleri:

- **Sürekli zamanlı:** Değişken $t$ süreklidir.
- **Analog:** $t$'nin bütün değerlerini alır ve genliği bir aralıktaki bütün değerleri alabilir.
- **Aperiyodik:** $t \ge 1$'de bir sinüs değeri alır, ama $t$'ye bölündüğü için genlik giderek azalır; kendini tekrarlamaz.
- **Sonsuz uzunluklu:** Sonsuza kadar sürer.
- **Nedensel:** Sıfırın altında değer almaz.
- **Ne çift ne tek:** Çift olması için kosinüs gibi, tek olması için sinüs gibi simetrik olması gerekirdi.
- **Deterministik:** Matematiksel ifadesi bellidir.

## 9. MATLAB ile İlk İşaret

Hoca aynı işareti MATLAB'in çevrim içi sürümünde (MATLAB Online) çizdi. MATLAB bilgisayara da kurulabilir. MATLAB bir betik (script) dilidir: değişkenler anında, satır satır oluşturulur. Tanımlama, başlık dosyası, derleme gibi adımlar yoktur; bu tür dillere yorumlanan (interpreter) diller denir. Hoca MATLAB'i yeni öğrenecekler için YouTube'daki kısa başlangıç derslerini önerdi.

### 9.1 Temel Kullanım

- `a = 5` yazınca çalışma alanında (workspace) `a` değişkeni 5 olur ve değer ekrana basılır.
- `b = 3;` gibi sonuna noktalı virgül konursa değer ekrana basılmaz, ama çalışma alanında görünür.
- `c = a*b` yazınca ekranda 15 görülür.
- `clc` komut penceresini temizler, `clear all` çalışma alanındaki bütün değişkenleri siler.

### 9.2 Kod

Slayttaki kod (ekrandan, 01:45:00):

```matlab
% Code written for Last Example in Lecture1
clc
clear all
close all

t1 = 1:0.01:10;
t2 = -10:0.01:1-0.01;
timeAxis = [t2 t1];
MySignal = [zeros(1,length(t2)) sin(2*pi*t1)./t1];
plot(timeAxis,MySignal)
ylabel('Amplitude', 'fontsize', 20)
xlabel('time', 'fontsize', 20)
title('My First Signal','fontsize', 20)
```

Hoca kodu satır satır açıkladı:

- **`t1 = 1:0.01:10;`** 1'den 10'a kadar 0,01 artışla değer üretir. `1:10` yazılsaydı 1, 2, ..., 10 değerleri atanırdı. Sonuç $1\times 901$ boyutlu bir dizidir: 1; 1,01; 1,02; ...; 10.
- **`t2 = -10:0.01:1-0.01;`** $-10$'dan $0{,}99$'a kadar 0,01 artışla gider; 1100 elemanlıdır.
- **`timeAxis = [t2 t1];`** iki diziyi uç uca ekleyerek $-10$'dan $10$'a kadar giden zaman eksenini oluşturur. Uzunluğu $1100 + 901 = 2001$'dir.
- **`zeros(1,length(t2))`** MATLAB'in hazır fonksiyonudur; $1\times 1100$ boyutlu sıfır dizisi üretir. Bu, işaretin $t < 1$ olan kısmıdır. MATLAB'de her sayı ve her dizi bir matris olarak tanımlanır.
- **`sin(2*pi*t1)./t1`** işaretin $t \ge 1$ olan kısmıdır.
- **`plot(timeAxis,MySignal)`** yatay eksene `timeAxis`, düşey eksene `MySignal` değerlerini koyar. İki dizi aynı uzunlukta olmak zorundadır.
- **`ylabel`, `xlabel`, `title`** eksen etiketlerini ve başlığı yazar; `'fontsize'` yazı boyutunu belirler.

> **Hocanın vurgusu:** Ekranda sürekli bir fonksiyon gibi görünen çizim aslında sürekli değildir. Bilgisayar ayrık değerlerle çalışır; zaman eksenini 0,01 gibi küçük adımlarla örnekleyerek sürekli bir işaret çizilmiş gibi yaparız. `t1` ve `t2`'nin küçük adımlarla tanımlanmasının nedeni budur.

### 9.3 Eleman Eleman Bölme: `./`

$\sin(2\pi t)/t$'de her $t$ değeri kendi sinüs değerini böler: $t=1$ için 1'e, $t=2$ için 2'ye, $t=3$ için 3'e. MATLAB'de bunun için `./` kullanılır. Hoca noktayı silip `/t1` yazınca işlemin hata vermediğini, ama `MySignal`'ın 2001 yerine 1101 elemanlı çıktığını gösterdi. Yani bölme bütün `t1` değerleri için tek tek yapılmamış, sonuca yalnız tek bir değer eklenmişti.

Hoca bunu iki diziyle de açıkladı. $A = [a, b, c, d]$ ve $N = [1, 2, 3, 4]$ olsun. $[a/1,\ b/2,\ c/3,\ d/4]$ dizisini istiyorsak `A./N` yazmalıyız. Nokta, aynı indisli gözlerin birbirine bölünmesini sağlar.

**Soru:** Bu işaretleri Python'da hazır kütüphanelerle oluşturabilir miyiz?

**Cevap:** Evet, kullanılabilir. MATLAB'in kullanım şekli zaten Python'a çok benzer.

### 9.4 Sonuç

Çizimde $t < 1$ için işaret sıfırdır. $t = 1$'den sonra genliği $1/t$ ile azalan, sonsuzda sıfıra giden bir sinüs görülür (ekrandan, 01:40:00). En büyük değer yaklaşık $0{,}8$'dir ve $t \approx 1{,}23$'te oluşur (numpy ile kontrol edildi).

## 10. Sürekli ve Ayrık İşaretler, Sistem Türleri

Hoca burada ikinci slayt dosyasını bitirip üçüncüsüne geçti. Birçok işaret zamanın fonksiyonudur, ama işaretler uzayın da fonksiyonu olabilir. Bir görüntü $I(x, y)$, $x$ ve $y$ koordinatlarındaki parlaklık değerlerinin fonksiyonudur. Video ise saniyede 25-30 görüntüden oluşur. İşaretler her boyutta sürekli ya da ayrık olabilir (ekrandan, 01:50:00).

### 10.1 Sistem Türleri

Sistemler giriş ve çıkış işaretlerinin türüne göre sınıflandırılır (ekrandan, 01:50:00):

- **Sürekli zamanlı sistem:** Girişleri ve çıkışları sürekli zamanlıdır. AM/FM radyo ve tamamen mekanik bir araba buna örnektir. Gaza basınca araba hızlanır; radyoya gelen işaret işlenir ve ses çıkar. İçerideki her işlem analogdur. Hoca burada kuleden yayın yapan standart radyoları kastettiğini, uydu radyo yayınlarında analog ve sayısal işaretlerin birlikte kullanıldığını belirtti.
- **Ayrık zamanlı sistem:** Girişleri ve çıkışları ayrık zamanlıdır. Bilgisayar oyunu, MATLAB ve kredi (mortgage) hesabı buna örnektir.
- **Hibrit sistem:** İçinde A/D ve D/A çeviriciler vardır. Örneğin ses işareti içeride ikili veri akışı olarak işlenir, sonra yeniden analoga çevrilir. Elektronik kontrol üniteli (ECU) modern arabalarda analog işaretler sayısallaştırılıp işlenir, sonra yeniden analog hale getirilir.

### 10.2 Örnekleme ile Ayrık İşaret

Sürekli zamanlı işaretlerde zaman değişkeni $t$ ile gösterilir; $t_0$, $t_1$ gibi belli anlar da kullanılır. İşaret her anda tanımlıdır. Ayrık işaretler köşeli parantezle yazılır. Önceki derste anlatıldığı gibi sürekli bir $x_a(t)$ işareti $T_s$ aralıklarla örneklenir:

$$x[n] = x_a(nT_s)$$

$n = 0$ için $x[0] = x_a(0)$, $n = 1$ için $x[1] = x_a(T_s)$, $n = 2$ için $x[2] = x_a(2T_s)$ olur. Slaytta $T$'nin altına $s$ konmamıştı, çünkü bağlamdan örnekleme periyodu olduğu anlaşılıyordu.

## 11. İşaretler Üzerinde İşlemler

Bu bölümde her işlem hem sürekli hem ayrık işaretler için gösterildi.

### 11.1 Genlik Ölçekleme

Ölçeklenmiş işaret $a\,x(t)$, $x(t)$'nin bir $a$ sabitiyle çarpılmasıdır (ekrandan, 01:55:00). Örneğin $2x(t)$'de zamanın her anında değer 2 ile çarpılır: $x$'in 0'da 1 olan değeri 2 olur, 0,25 olan bir değer 0,5 olur. Ayrık işarette $a\,x[n]$ de aynı şekilde tanımlanır. $a > 1$ ise genlik artar, $0 < a < 1$ ise (örneğin $1/2$) genlik azalır.

### 11.2 Zamanda Ölçekleme (Sürekli)

Bir $x(t)$ işareti, zaman değişkeni pozitif bir $b$ sabitiyle çarpılarak zamanda ölçeklenir: $x(bt)$. $0 < b < 1$ ise işaret zamanda genişler, $b > 1$ ise sıkışır (ekrandan, 02:00:00).

Hoca $x(2t)$'yi değer vererek buldu:

- $t = 0$ için $x(2\cdot 0) = x(0)$. Yani $x$'in 0'daki tepe değeri (2) yine 0'da kalır.
- $x(0{,}5)$ değerini yeni işarette nerede görürüz? $2t = 0{,}5 \Rightarrow t = 1/4$. Yani $x$'in 0,5'teki değeri yeni işarette $t = 1/4$'e gelir.

Her nokta orijine yarı uzaklığa geldiği için işaret sıkışır (compress). $x(t/2)$'de ise işaret iki kat genişler.

### 11.3 Zamanda Ölçekleme (Ayrık): Downsampling ve Upsampling

**Downsampling.** $y[n] = x[2n]$ olsun.

- $y[0] = x[0]$
- $y[1] = x[2]$
- $y[2] = x[4]$

Örnekler birer atlanarak alınır; işaret bir anlamda sıkışır. Buna downsampling denir. $x[bn]$'de $b$ birden büyük bir tam sayıysa işlem downsampling'dir.

**Upsampling.** $y[n] = x[n/2]$ olsun, yani $b = 1/2$ (ekrandan, 02:30:00).

- $y[0] = x[0/2] = x[0]$
- $y[1] = x[1/2] = x[0{,}5]$: $n$ tam sayı değerleri aldığı için $x[0{,}5]$ diye bir değer yoktur.
- $y[2] = x[2/2] = x[1]$

Değeri olmayan ara indisler için iki seçenek vardır: o noktaya sıfır yazmak ya da bir önceki ve bir sonraki örneğin ortalamasını koymak, yani ara değerleme (interpolasyon) yapmak. Slaytta da ara örneklerin "sıfıra eşitlenerek ya da ara değerlemeyle sentezlenmesi gerektiği" ve dizinin uzadığı yazıyordu (ekrandan, 02:05:00). $x$'in 0. ve 1. örnekleri yeni işarette 0. ve 2. indise gider; 1, 3, 5 gibi ara indisler sıfır ya da ara değer alır. Buna upsampling, yani bir tür genişleme (expansion) denir.

> **Hocanın vurgusu:** $x(bt)$'de $b > 1$ ise işaret darlaşır (ayrıkta downsampling), $0 < b < 1$ ise işaret yayılır (ayrıkta upsampling). Kısaca $a$ tam sayı olmak üzere $x(at)$ downsampling, $x(t/a)$ upsampling yapar.

Hoca, zamanda ölçekleme yapınca yeni işaretin frekans bileşenlerinin de değiştiğini ekledi.

### 11.4 Zamanda Ters Çevirme

Sürekli zamanda $t$ yerine $-t$ konur; ters çevrilmiş işaret $x(-t)$'dir (ekrandan, 02:10:00). İşaret düşey eksene göre katlanır; pozitif taraftakiler negatife, negatif taraftakiler pozitife geçer. Örneğin $x(-t)$'nin $-1$'deki değerini bulmak için $t = -1$ konur: $x(-(-1)) = x(1)$. Yani $x$'in 1'deki değeri yeni işarette $-1$'e taşınır.

Ayrık zamanda $n$ yerine $-n$ konur; ters çevrilmiş işaret $x[-n]$'dir. $x[-n]$'nin $n = 1$'deki değeri $x[-1]$, $n = 3$'teki değeri $x[-3]$'tür. Slayta göre bu işlem $b = -1$ alınmış zamanda ölçeklemedir. Hoca slaytta ayrık grafiğin yatay ekseninin yanlışlıkla $t$ yazıldığını, $n$ olması gerektiğini belirtti.

### 11.5 Zamanda Öteleme

Sürekli zamanda $t_1 > 0$ bir sabit olmak üzere $x(t - t_1)$ gecikmiş (delayed), $x(t + t_1)$ ilerlemiş (advanced) işarettir. Örneğin $x(t-1)$'de $t - 1 = 0 \Rightarrow t = 1$: işaretin merkezi 1'e, yani sağa kayar. $x(t+1)$'de $t + 1 = 0 \Rightarrow t = -1$: işaret sola kayar. Slayttaki ipucu da buydu: ilk bakışta ters gibi görünebilir, $t - t_1$'in nerede sıfır olduğunu düşünün (ekrandan, 02:35:00).

Ayrık zamanda $n_1 > 0$ bir tam sayı olmak üzere $x[n - n_1]$ gecikmiş, $x[n + n_1]$ ilerlemiş işarettir. Gecikme ya da ilerleme tam sayı kadar örnek süresidir. $x[n-1]$'de $n - 1 = 0 \Rightarrow n = 1$, işaret bir örnek sağa kayar; $x[n+1]$'de $n = -1$, işaret bir örnek sola kayar.

### 11.6 Birleşik İşlemler: Sıra Önemlidir

Zamanda ölçekleme, öteleme ve ters çevirme birleştirilebilir. Ama sonuç işlemlerin sırasına bağlıdır, bu yüzden dikkatli olunmalıdır. Slayttaki örnek $x(2(t-1))$ idi; $x(t)$, tepe değeri 2 olan ve 0'da tepe yapan bir işaretti (ekrandan, 02:15:00).

- **Önce ölçekle, sonra kaydır:** $x(t)$ 2 ile sıkıştırılır, $x(2t)$ elde edilir; sonra 1 kaydırılır. Tepe $t = 1$'e gelir. Tepe genliği değişmez, işaret yalnız sıkışır. Bu doğrudur.
- **Önce 1 kaydır, sonra 2 ile sıkıştır:** $x(t-1)$'in tepesi 1'dedir; sonra sıkıştırılınca tepe $0{,}5$'e gelir. Slaytta bu yol "Incorrect" diye işaretliydi.
- **Önce 2 kaydır, sonra 2 ile ölçekle:** İfade $x(2(t-1)) = x(2t - 2)$ diye yeniden yazılır. $x(t-2)$'nin tepesi 2'dedir; sonra 2 ile sıkıştırılınca tepe 1'e gelir. Slaytta bu yol "Correct" diye işaretliydi.

Hoca ilk bakışta slaytta bir yanlışlık olduğunu düşündü, sonra değerleri kontrol ederek slaytın doğru olduğunu gördü. Kontrol için slaytın sorduğu soru sorulur: $2(t-1)$ nerede sıfır olur? $t = 1$'de. Demek ki $x$'in 0'daki tepe değeri yeni işarette $t = 1$'dedir.

### 11.7 Yeni İşareti Değer Vererek Çizmek

Slayttaki "kendiniz deneyin" örneğinde $x(t)$, $t = -1$'de 0'dan başlayıp doğrusal olarak $t = 0$'da 1'e çıkan, sonra doğrusal olarak $t = 2$'de 0'a inen bir üçgendi (ekrandan, 02:20:00). Hoca $y(t) = x(-t/2)$'yi çizdi. Önce $x(-t)$'yi çizip sonra genişletmeye çalışınca karıştırdı ve işi yeniden, değer vererek yaptı:

| $t$ | $-t/2$ | $y(t) = x(-t/2)$ |
|---|---|---|
| $0$ | $0$ | $1$ |
| $1$ | $-1/2$ | $0{,}5$ |
| $2$ | $-1$ | $0$ |
| $-1$ | $1/2$ | $0{,}75$ |
| $-2$ | $1$ | $0{,}5$ |
| $-3$ | $3/2$ | $0{,}25$ |
| $-4$ | $2$ | $0$ |

Sonuç: $y(t)$, $t = -4$ ile $t = 2$ arasında tanımlı, tepesi $t = 0$'da olan bir üçgendir. Bu, $x(t)$'nin önce ters çevrilip ($x(-t)$) sonra iki kat genişletilmesidir: ters çevrilmiş işaretin her noktası orijine iki kat uzaklaşır.

> **Ders sonrası not:** Hoca bazı değerleri grafikten göz kararıyla okudu: $x(1/2)$'yi yaklaşık 0,8, $x(1)$'i yaklaşık 0,6, $x(3/2)$'yi yaklaşık 0,3 dedi. Üçgenin $0 \le t \le 2$ arasındaki kenarı $1 - t/2$ olduğundan doğru değerler 0,75, 0,5 ve 0,25'tir (python ile kontrol edildi).

> **Hocanın vurgusu:** Karışıklığı önlemenin yolu, yeni işaret $y(t)$'de $t$'ye değerler verip $x$'in hangi noktasının okunacağını hesaplamaktır. Slayttaki diğer iki işaret de ($x(2(t+2))$ ve $x(-t+1)$) bu yolla çizilmelidir.

## 12. Periyodik İşaretler

Slayta göre periyodik işaretler bu derste çok önemlidir (ekrandan, 02:25:00).

- Sürekli zamanlı bir işaret, ancak ve ancak bütün $t$ için $x(t + T_0) = x(t)$ olacak şekilde bir $T_0 > 0$ varsa periyodiktir. $T_0$, $x(t)$'nin zamandaki periyodudur.
- Ayrık zamanlı bir işaret, ancak ve ancak bütün $n$ için $x[n + N_0] = x[n]$ olacak şekilde bir $N_0 > 0$ tam sayısı varsa periyodiktir. $N_0$, $x[n]$'nin örnek aralığı cinsinden periyodudur.
- En küçük $T_0$ ya da $N_0$, periyodik işaretin temel periyodudur (fundamental period).

Hoca sinüzoidal bir işareti hatırlattı: $T_0$ kadar gittikten sonra işaret kendini tekrarlar; ayrık işarette bu $N_0$ örnek sonra olur. Slayttaki örnekte tek bir periyotluk $x_1(t)$ parçası alınıyor ve tekrar tekrar kaydırılarak periyodik uzantı (periodic extension) oluşturuluyordu:

$$x(t) = \sum_{k} x_1(t + kT)$$

Bu örnekte $T = 1$'di; $k$'ya değerler verilerek işaret iki yönde uzatılır. Hoca bir sonraki derste karmaşık (kompleks) işaretlere geçileceğini söyledi.

## 13. Ders Sonundaki Sorular

**Soru:** Ayrık işaretlerde parantezin içinde $n/2$ olunca bazı noktalar kayboluyordu. Onlara biz mi değer veriyoruz?

**Cevap:** Hoca $y[n] = x[n/2]$ örneğini yeniden anlattı ve $x$'e değerler verdi: $x[0] = 1$, $x[1] = 3$, $x[2] = 4$. $y[0] = x[0] = 1$; $y[1] = x[0{,}5]$ tanımsızdır, sıfır konur; $y[2] = x[1] = 3$; $y[3] = x[1{,}5]$ yine sıfır; $y[4] = x[2] = 4$. Yani $1, 3, 4$ dizisi $1, 0, 3, 0, 4$ olur. Bu bir genişlemedir, yani upsampling. İkinci yol ara değerlemedir: sıfırlar yerine komşu örneklerin ortalaması konur. 1 ile 3'ün ortalaması 2, 3 ile 4'ün ortalaması 3,5'tir; dizi $1, 2, 3, 3{,}5, 4$ olur. Olmayan değerlere komşulardan değer üretmeye interpolasyon denir. Standart upsampling'de yalnız sıfırlar konur. Öğrenci ve hoca, slayttaki ara değerlerin bu ortalamalara tam uymadığını fark etti; hoca slaytta farklı bir yöntem kullanılmış olabileceğini söyledi.

**Soru:** Analog bir sesi sayısala çevirip tekrar analoga çevirince ilk sesle aynı olmuyor, değil mi?

**Cevap:** Olmaz. Örnekleme sırasında iki yerden bilgi kaybedilir. Birincisi, örnekler arasındaki değerler kaybolur. İkincisi, her örnek en yakın kuantalama seviyesine atandığı için gerçek genlik ile seviye arasındaki fark kadar hata oluşur. Örnekler sonra güzel bir şekilde birleştirilse bile orijinale çok yakın ama birebir aynı olmayan bir işaret elde edilir. Yine de örnekler çok sık alınır: 4 kHz'lik bir işaret 8 kHz ile örneklenirse iki örnek arası $1/8000$ s $= 125\ \mu$s olur. Örnekleme frekansı 16 kHz ya da 64 kHz'e çıkarıldıkça bu aralık daha da küçülür ve fark insan kulağıyla pek algılanmaz.

**Soru:** Klasik upsampling sıfır dolduruyor. Dekonvolüsyon da klasik upsampling sayılır mı? O da sıfır dolduruyor diye biliyorum.

**Cevap:** Konvolüsyon başka bir konudur ve daha sonra görülecek. Burada temel işaret işlemlerini konuşuyoruz. Evrişimli sinir ağlarındaki (CNN) downsampling, upsampling ve max pooling gibi işlemler kavram olarak benzer, örneğin bir örnek alınıp bir örnek atlanır ya da en büyük değer alınır, ama ayrı bir konudur ve şimdilik karıştırılmamalıdır.

## Örnek Sorular

**1. (derste sözlü ve ekrandan, 00:44:10 / 00:45:00)** $x(t) = 3\cos(2\pi\cdot 2\cdot t - 3\pi/4)$ işaretinin periyodu nedir? Genlik, faz ve ilk tepe noktası nedir?

> **Çözüm:** $f_0 = 2$ Hz olduğundan $T_0 = 1/f_0 = 0{,}5$ s. Genlik $A = 3$, faz $3\pi/4 = 135^\circ$. İlk tepe $4\pi t - 3\pi/4 = 0 \Rightarrow t = 3/16 = 0{,}1875$ s; bir sonraki tepe $3/16 + 1/2$ s'de.

**2. (derste sözlü, 01:23:32)** Bir konuşma işareti deterministik midir, rastgele midir?

> **Çözüm:** Rastgeledir. Konuşmacının bir sonraki anda ne söyleyeceği önceden bilinemez; işaretin değerini veren bir matematiksel ifade yoktur.

**3. (ekrandan, 01:25:00)** Bütün gerçek $t$ için tanımlı $f(t) = \sin(2\pi t)/t$ ($t \ge 1$), $f(t) = 0$ ($t < 1$) işaretinin özelliklerini yazınız.

> **Çözüm:** Sürekli zamanlı, analog, aperiyodik, sonsuz uzunluklu, nedensel, ne çift ne tek ve tanımı gereği deterministik.

**4. (ekrandan, 01:15:00)** $t \in [-1, 0]$'da $0$'dan $1$'e doğrusal artan, $t \in [0, 1]$'de $1$ olan, başka yerde sıfır olan $f(t)$'yi çift ve tek parçalarına ayırınız.

> **Çözüm:** $e(t) = \frac{1}{2}[f(t) + f(-t)]$: $t = 0$'da $1$, $0 < |t| < 1$'de $1 - |t|/2$, $|t| = 1$'de $0{,}5$. $o(t) = \frac{1}{2}[f(t) - f(-t)]$: $0 < t < 1$'de $t/2$, $-1 < t < 0$'da $t/2$, $t = \pm 1$'de $\pm 0{,}5$. Kontrol: $e + o$, $t = 1$'de $1$, $t = -1$'de $0$, $t = 0$'da $1$.

**5. (ekrandan, 02:20:00)** $x(t)$, $t = -1$'de 0, $t = 0$'da 1, $t = 2$'de 0 olan (kenarları doğrusal) üçgen işarettir. (a) $x(-t/2)$, (b) $x(2(t+2))$, (c) $x(-t+1)$ işaretlerini çiziniz.

> **Çözüm (a), derste verildi:** $y(t) = x(-t/2)$, $t \in [-4, 2]$'de tanımlı üçgendir: $y(-4) = 0$, $y(-2) = 0{,}5$, $y(0) = 1$, $y(1) = 0{,}5$, $y(2) = 0$.

> **Çözüm (b) ve (c) (derste verilmedi):** (b) $x(2(t+2))$: argüman $2(t+2) \in [-1, 2]$ olmalı, yani $t \in [-2{,}5,\ -1]$. Tepe $2(t+2) = 0 \Rightarrow t = -2$'de 1 değerinde. Değerler: $t = -2{,}5$'te 0, $t = -2$'de 1, $t = -1{,}5$'te 0,5, $t = -1$'de 0. (c) $x(-t+1)$: $1 - t \in [-1, 2]$, yani $t \in [-1, 2]$. Tepe $1 - t = 0 \Rightarrow t = 1$'de 1. Değerler: $t = -1$'de 0, $t = 0$'da 0,5, $t = 1$'de 1, $t = 1{,}5$'te 0,5, $t = 2$'de 0. Yani $t = -1$'den $t = 1$'e doğrusal yükselen, $t = 1$'den $t = 2$'ye doğrusal inen bir üçgen (python ile kontrol edildi).

**6. (ekrandan ve derste sözlü, 02:28:28 / 02:30:00)** $x[0] = 1$, $x[1] = 3$, $x[2] = 4$ ise $y[n] = x[n/2]$ dizisini $n = 0, \dots, 4$ için yazınız.

> **Çözüm:** Sıfır doldurmayla $y = [1, 0, 3, 0, 4]$. Komşu ortalamasıyla ara değerlemeyle $y = [1, 2, 3, 3{,}5, 4]$.

## Dersin Toparlaması

Bu derste işaret ve sistem kavramları tanımlandı, işaretlerin neden sinüzoidallerin toplamı olarak görüldüğü ve frekans domeninin neden önemli olduğu piyano, araba ve hız sabitleme örnekleriyle anlatıldı. Sinüzoidal bir işaretin genlik, frekans, periyot ve faz parametreleri bir örnek üzerinde okundu. İşaretler sürekli/ayrık, periyodik/aperiyodik, nedensel/antinedensel/nedensel olmayan, çift/tek ve deterministik/rastgele diye sınıflandırıldı. Her işaretin bir çift ve bir tek parçaya ayrılabileceği bir örnekle gösterildi. MATLAB'de $\sin(2\pi t)/t$ işareti çizilirken sürekli bir işaretin bilgisayarda küçük adımlarla örneklenerek gösterildiği ve eleman eleman işlem için `./` gerektiği görüldü.

Dersin ikinci yarısında işaretler üzerindeki temel işlemler anlatıldı: genlik ölçekleme, zamanda ölçekleme (ayrıkta downsampling ve upsampling), zamanda ters çevirme ve zamanda öteleme. Birleşik işlemlerde sıranın önemli olduğu, en güvenli yolun argümanın sıfır olduğu noktayı bulmak ya da yeni işarete değer vererek çizmek olduğu vurgulandı. Ders, periyodik işaretlerin tanımı ve temel periyot kavramıyla bitti. Bir sonraki derste karmaşık (kompleks) işaretlere geçilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
