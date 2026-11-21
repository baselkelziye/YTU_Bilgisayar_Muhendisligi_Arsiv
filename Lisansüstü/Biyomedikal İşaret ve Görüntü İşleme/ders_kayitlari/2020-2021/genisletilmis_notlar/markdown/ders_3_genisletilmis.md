# Ders 3 Genişletilmiş Notu: Ayrık Zaman Sistemleri, Sistem Özellikleri ve Konvolüsyon

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Tekrar: İşaret Ayrıştırma
- 2. Ayrık Zaman Sistemleri
- 3. Sistem Özellikleri: Hafıza, Toplamsallık, Homojenlik, Doğrusallık
- 4. Doğrusallıktan Birim Örnek Cevabına
- 5. Öteleme ile Değişmezlik ve LSI Sistemler
- 6. Nedensellik
- 7. Kararlılık (Durağanlık)
- 8. Konvolüsyonun Özellikleri
- 9. Analitik Bir Konvolüsyon Örneği
- 10. Sonlu Uzunluklu Dizilerin Konvolüsyonu
- 11. MATLAB'de Konvolüsyon ve İndisli Çizim
- Örnek Sorular

## 1. Tekrar: İşaret Ayrıştırma

Hoca derse bir önceki haftanın son konusu olan işaret ayrıştırmayı (signal decomposition) hatırlatarak başladı. Ayrık işaretleri köşeli parantezle, $x[n]$ biçiminde gösteriyoruz. Ayrık işaret, analog bir işaretten alınmış örneklerden oluşur. Bu örneklerin her biri, birim impulsun kaydırılmış bir kopyası olarak düşünülebilir.

Birim impulsun değeri 1'dir. Bu yüzden bir örneği temsil etmek için impulsu o örneğin genliğiyle çarpmak gerekir. Örneğin $n=3$'teki örneğin genliği 1,5 ise bu örnek $x[3]\,\delta[n-3]$ terimiyle gösterilir; burada $x[3]=1{,}5$'tir (ekrandan, 00:20:00). Bütün örnekler için bu terimler toplanınca işaretin genel ifadesi elde edilir:

$$x[n]=\sum_{k=-\infty}^{\infty} x[k]\,\delta[n-k]$$

Toplamdaki $k$, işaretin tanımlı olduğu ilk indisten son indisine kadar değer alır. Örneğin işaret $-2$'de başlayıp $4$'te bitiyorsa toplam $x[-2]\delta[n+2]+x[-1]\delta[n+1]+\dots+x[4]\delta[n-4]$ olur. "Kompozisyon" bir bütün oluşturmak, "dekompozisyon" ise bütünü parçalarına, yani genlikle çarpılmış tek tek impulslara ayırmak demektir.

## 2. Ayrık Zaman Sistemleri

Ayrık zaman işaretlerinden sonra yeni başlık ayrık zaman sistemleridir. Hocanın tahtaya yazdığı tanım şöyledir (ekrandan, 00:35:00):

> Bir ayrık zamanlı sistem, bir giriş işaretini sabit kurallar kümesi veya işlemlerle başka bir çıkış işaretine dönüştüren matematiksel bir operatör olarak tanımlanabilir.

Gösterimde bir giriş işareti $x[n]$, bir sistem kutusu $T[\cdot]$ ve bir çıkış işareti $y[n]$ vardır. Kutunun içi tasarlayacağımız sistemdir: içinde çeşitli algoritmalar koşturabilir, matematiksel ya da mantıksal işlemler yapabiliriz. Amaç, giriş işaretini işleyerek istenen $y[n]$ işaretini oluşturmaktır. Bu kutu ayrık zaman işaretlerini kabul eder.

## 3. Sistem Özellikleri: Hafıza, Toplamsallık, Homojenlik, Doğrusallık

Hoca sistem özelliklerini numaralandırarak tek tek anlattı.

### 3.1 Hafızasız ve hafızalı sistemler

İngilizcesi "system with memory or not" olan birinci özellik, sistemin bir hafıza birimine ihtiyaç duyup duymadığıdır. Sistem hafızasızsa $n=n_0$ anındaki çıkış yalnız $n=n_0$ anındaki girişe bağlıdır (ekrandan, 00:40:00).

- **Örnek 1:** $y[n]=x^2[n]$, yani girişin karesini alan sistem. Bir diğer örnek $y[n]=e^{x[n]}$: $y[1]$'i bulmak için yalnız $x[1]$ gerekir, $y[1]=e^{x[1]}$. Bu sistemler hafızasızdır.
- **Örnek 2:** $y[n]=x[n]+x[n-1]+x^2[n+1]$. $y[1]$'i bulmak için $x[1]$'in yanında bir önceki örnek $x[0]$ gerekir: $y[1]=x[1]+x[0]+\dots$. Bu önceki örneğin kutunun içinde bir yerde saklanması gerekir. $x^2[n+1]$ terimi ise $n=1$ için $x^2[2]$, yani ileriki bir örnek ister; bunun da bir şekilde saklanması gerekir. Bu sistem hafızalıdır.

Kısacası sistem, geciktirme operatörlerinde olduğu gibi o anki girişten farklı bir anın değerine ihtiyaç duyuyorsa hafızalıdır.

### 3.2 Toplamsallık (additivity)

İki işaret sisteme toplam olarak, $x_1[n]+x_2[n]$ biçiminde birlikte verildiğinde elde edilen çıkış, işaretler ayrı ayrı verildiğinde elde edilen çıkışların toplamına eşitse sistem toplamsaldır:

$$T\{x_1[n]+x_2[n]\}=T\{x_1[n]\}+T\{x_2[n]\}$$

### 3.3 Homojenlik (ölçekleme)

Sistem homojense, giriş bir sabitle ölçeklendiğinde çıkış da aynı sabitle ölçeklenir. Hoca "ölçekleme" teriminin "scaling"in tam karşılığı olmadığını da belirtti. Tahtadaki ifade (ekrandan, 00:45:00):

$$T[c\,x[n]]=c\,T[x[n]]$$

Burada $c$ bir sabit (constant) ya da skalerdir. Ölçeklenmiş girişin çıkışı, ölçeklenmemiş girişin çıkışının $c$ ile çarpılmasıyla bulunabiliyorsa sistem homojendir.

### 3.4 Doğrusallık (lineer sistemler)

Doğrusal sistem, toplamsallık ve homojenlik özelliklerini birlikte sağlayan sistemdir. $a_1$ ile ölçeklenmiş $x_1[n]$ ve $a_2$ ile ölçeklenmiş $x_2[n]$ toplam olarak sisteme verildiğinde (ekrandan, 00:45:00):

$$T[a_1x_1[n]+a_2x_2[n]]=a_1T[x_1[n]]+a_2T[x_2[n]]$$

Yani girişler ayrı ayrı verilip sonuçlar ölçeklenerek toplansa da, toplam halinde verilse de aynı çıkış elde edilir.

> **Hocanın vurgusu:** Doğrusallık, verilen bir giriş için sistem cevabının değerlendirilmesini büyük ölçüde basitleştirir.

## 4. Doğrusallıktan Birim Örnek Cevabına

Hoca bu notun ne demek olduğunu işaret ayrıştırmayla bağlayarak gösterdi. $y[n]$'yi elde etmek için girişi sistemden geçiririz. Girişin yerine ayrıştırılmış halini yazarsak:

$$y[n]=T\left[\sum_{k=-\infty}^{\infty} x[k]\,\delta[n-k]\right]$$

Bu ifadede hem çarpım ($x[k]$ katsayıları) hem toplam vardır. $x[k]$'ler sabitlerimiz, $\delta[n-k]$'ler ise ötelenmiş impuls dizileridir. Sistem doğrusalsa toplamsallık sayesinde toplam operatörü, homojenlik sayesinde $x[k]$ katsayıları $T$'nin dışına çıkar:

$$y[n]=\sum_{k=-\infty}^{\infty} x[k]\,T[\delta[n-k]]$$

Geriye kalan, kaydırılmış impulslara sistemin verdiği cevaptır. Buna $h_k[n]$ adı verilir (ekrandan, 00:50:00):

$$h_k[n]=T[\delta[n-k]]$$

$h_k[n]$, sistemin birim örneğe cevabıdır; İngilizcesi "impulse response"dur. Bu durumda çıkış

$$y[n]=\sum_{k=-\infty}^{\infty} x[k]\,h_k[n]$$

biçiminde yazılır. Hocanın vurguladığı nokta şudur: Sistemin tamamını bilmeye gerek yoktur. Bir sisteme uygulanan bir impulsa verilen cevabı biliyorsak sistemin davranışını karakterize edebiliriz; gelen genlikler bu cevapla çarpılır, ötelenmiş cevaplar toplanır.

## 5. Öteleme ile Değişmezlik ve LSI Sistemler

### 5.1 Öteleme ile değişmezlik (shift invariance)

Beşinci özellik öteleme ile değişmezliktir (ekrandan, 00:50:00). Sistem öteleme ile değişmezse, girişteki $n_0$ örneklik gecikme, yani $x[n-n_0]$, çıkışta da aynı miktarda gecikme üretir: $y[n-n_0]$. Burada $n_0$ sabit bir tam sayı, $n$ ise değişkendir.

### 5.2 Doğrusal ve öteleme ile değişmez sistemler

Doğrusallık ile öteleme ile değişmezlik birleştirilince doğrusal öteleme ile değişmez sistemler (linear shift invariant systems, LSI) elde edilir. Bu sistemlerde $k$ kadar kaydırılmış impulsa verilen cevap, birim impuls cevabının $k$ kadar kaydırılmışıdır: $h_k[n]=h[n-k]$. Böylece çıkış (ekrandan, 00:55:00):

$$y[n]=\sum_{k=-\infty}^{\infty} x[k]\,h[n-k]=x[n]*h[n]$$

Bu özel işlem konvolüsyondur. Sistemin $h[n]$ diye bir karakteristiği, yani impuls cevabı vardır. Bu cevap biliniyorsa, LSI bir sistemde girişi impuls cevabıyla konvolüsyon işlemine sokarak çıkış $y[n]$ bulunur. Hoca bunu şöyle özetledi: Sistemin birim impulsa verdiği cevabı bildiğimizde, bu cevabı kaydırarak, belli katsayılarla çarparak ve toplayarak sistemin çıkışını bulabiliriz.

## 6. Nedensellik

Yedinci özellik nedenselliktir (tahtada "Casuality" yazılı; ekrandan, 01:05:00). Sistem nedenselse $n_0$ anındaki cevap yalnız $n_0$ anına kadar olan girişlere bağlıdır.

- $y[n]=x[n]+x[n-1]$: Çıkış o anki ve bir önceki girişe bağlıdır. Sistem nedenseldir.
- $y[n]=x[n-1]+x^2[n+1]$: $x[n-1]$ geçmişte oluşmuş (gecikmiş) bir örnektir, $x^2[n+1]$ ise gelecekte oluşacak (ilerletilmiş, "advanced") bir örnektir. $n=1$ için $y[1]=x[0]+x^2[2]$ olur. $x[0]$'ı hafızada tutarak kullanabiliriz, ama 1 anındayken 2 anındaki değeri bilemeyiz. Bu yüzden sistem nedensel değildir.

> **Ders sonrası not:** Tahtadaki "Casuality" yazımı hatalıdır; doğrusu "Causality"dir.

### 6.1 Nedensellik üzerine soru-cevap

**Soru:** Nedensellikteki $y[1]$ örneği tekrar açıklanabilir mi?

**Cevap:** Hoca önce $y[n]=x^2[n]$ örneğini verdi: $y[1]$ için yalnız $x[1]$ gerekir, yani 1 anındaki giriş 1 anındaki çıkışı etkiler. $y[n]=x[n]+x[n-1]$ için $y[1]=x[1]+x[0]$ olur; 1 anı oluşmuşsa 0 anı da oluşmuştur. $y[n]=x[n-1]+x^2[n+1]$'de ise $n$ gördüğümüz her yere 1 koyunca $x[0]$ ve $x^2[2]$ çıkar. $y[1]$'i hesaplarken zaman olarak 1 anına kadar gelmişizdir; $x[0]$ geçmişte oluştuğu için hafıza kullanarak kullanılabilir, fakat $x[2]$ gelecekteki bir örnektir. Şu anki an ve geçmişteki anlar şu anı etkileyebilir; gelecekteki bir şeyin şu anı etkilemesi nedensel değildir.

**Soru:** Bu örnekte $x[0]$ ve $x[2]$ var; $x[1]$'in de bulunması gerekir mi?

**Cevap:** Hayır. Önemli olan, şu anki ve geçmiş örneklerle yetinilmesidir.

## 7. Kararlılık (Durağanlık)

Sekizinci özellik hocanın "durağanlık" dediği stability özelliğidir (ekrandan, 01:05:00). Tanımı: Sistemin sınırlı giriş için sınırlı çıkış üretmesi. Girişin mutlak değeri (giriş negatif değerler de alabildiği için mutlak değer alınır) sonlu bir $A$ değerinin altındaysa, çıkış da sonlu bir $B$ değerinin altında kalıyorsa sistem kararlıdır (ekrandan, 01:00:00):

$$|x[n]|\le A<\infty \;\Rightarrow\; |y[n]|\le B<\infty$$

Sınırsız bir işarete örnek olarak hoca $x[n]=e^n$'i verdi: $n$ arttıkça değer sonsuza gider. Çıkışta sonsuza giden bir değer oluşmuyorsa sistem kararlıdır.

> **Ders sonrası not:** Tahtada $y[n]\le B<\infty$ yazılmıştır; tanım mutlak değerle $|y[n]|\le B$ biçimindedir. Ayrıca Türkçe işaret işleme kaynaklarında stability için büyük olasılıkla daha yaygın olan terim "kararlılık"tır; "durağanlık" çoğunlukla stationarity (istatistiksel özelliklerin zamanla değişmemesi) karşılığıdır.

### 7.1 LSI sistemlerde kararlılık koşulu

LSI sistemlerde kararlılık doğrudan sistemin kendisine, yani $h[n]$'ye bağlı bir koşulla yazılır (ekrandan, 01:00:00):

$$\sum_{n=-\infty}^{\infty}|h[n]|<\infty$$

$h[n]$ de, sisteme bir impuls girip çıkışta oluşan bir dizidir. Bu dizinin bütün elemanlarının mutlak değerleri toplandığında sonuç sonsuza gitmemelidir.

**Örnek:** $h[n]=a^n u[n]$ ve $|a|<1$ olsun. $u[n]$, $n=0$'dan sonsuza kadar 1 değerini alan birim basamak dizisidir; burada $h[n]$'nin $0$'dan itibaren pozitif indislerde değer aldığını belirtir. Hoca önce $a\,u[n]$ yazıp sonra bunu $a^n u[n]$ olarak düzeltti. Koşula yerleştirince $u[n]$ bir sınır belirttiği için toplamın alt sınırı $0$ olur ve $u[n]$ ortadan kalkar; mutlak değerin yalnız tabana uygulanması yeterlidir:

$$\sum_{n=-\infty}^{\infty}|a^n u[n]|=\sum_{n=0}^{\infty}|a|^n=\frac{1}{1-|a|},\quad |a|<1$$

$a=1/2$ için terimler $1, \frac12, \frac14, \frac18,\dots$ biçiminde gider ve toplam 2'ye yakınsar. Sonsuz toplam sabit bir sayıya ulaştığı için sistem kararlıdır.

> **Ders sonrası not:** Altyazıda toplamın "$1-a$"ya yakınsadığı geçmektedir (büyük olasılıkla Whisper ya da sözlü kısaltma kaynaklı); doğrusu $\frac{1}{1-a}$'dır (pozitif $a$ için). Hocanın $a=1/2$ için verdiği 2 sonucu da bu ifadeyle tutarlıdır (python ile doğrulandı).

> **Ek bilgi (derste anlatılmadı):** Geometrik seri $\sum_{n=0}^{\infty} r^n$, $|r|<1$ olduğunda $\frac{1}{1-r}$'ye yakınsar; $|r|\ge 1$ ise ıraksar. Bu yüzden $h[n]=a^n u[n]$ biçimindeki bir LSI sistem $|a|<1$ için kararlı, $|a|\ge 1$ için kararsızdır.

## 8. Konvolüsyonun Özellikleri

Aradan sonra hoca konvolüsyon konusuna geçti. Konvolüsyonun bugün derin öğrenmedeki konvolüsyonel sinir ağlarında da çok kullanıldığını hatırlattı: Orada da girişler farklı filtrelere uygulanır ve iki boyutlu konvolüsyon yapılır. Temel kabul aynıdır: Görüntü ya da işaret biçimindeki ayrık bir girişe (piksellere veya vektör dizilerine) sistemin bir cevabı vardır ve sistemin kendi karakteristiği, birim impulslara verdiği cevap olan $h[n]$'dir. Tahtadaki ifade (ekrandan, 01:25:00):

$$y[n]=\sum_{k=-\infty}^{\infty}x[k]\,h[n-k]=x[n]*h[n]$$

Aradaki $*$ işareti konvolüsyon işaretidir.

### 8.1 Değişme özelliği (commutative)

$$x[n]*h[n]=h[n]*x[n]$$

Giriş ile impuls cevabının yeri değiştirilse de aynı sonuç elde edilir (ekrandan, 01:25:00).

### 8.2 Birleşme özelliği (associative)

Birbirine kaskat (cascade) bağlı iki sistem düşünelim: $x[n]$ önce impuls cevabı $h_1[n]$ olan sistemden, sonra $h_2[n]$ olan sistemden geçiyor (ekrandan, 01:25:00). Bu durumda

$$\{x[n]*h_1[n]\}*h_2[n]=x[n]*\{h_1[n]*h_2[n]\}$$

yazılabilir. Yani önce $h_1$ ile $h_2$ konvolüsyon işlemine sokulursa $h_{eq}[n]=h_1[n]*h_2[n]$ elde edilir ve sistem tek bir $h_{eq}$ sistemiymiş gibi düşünülebilir.

### 8.3 Dağılma özelliği (distributive)

Bu kez $x[n]$ paralel olarak $h_1[n]$ ve $h_2[n]$ sistemlerinde ayrı ayrı işlenir, çıkışlar toplanarak $y[n]$ oluşur (ekrandan, 01:30:00):

$$x[n]*\{h_1[n]+h_2[n]\}=\{x[n]*h_1[n]\}+\{x[n]*h_2[n]\}$$

Buna göre paralel bağlı sistemlerin eşdeğeri basit bir toplamdır: $h_{eq}[n]=h_1[n]+h_2[n]$. Kaskat bağlamada eşdeğer konvolüsyonla, paralel bağlamada toplamayla bulunur.

## 9. Analitik Bir Konvolüsyon Örneği

Örnekte giriş ve impuls cevabı şöyledir (ekrandan, 01:30:00):

$$x[n]=a^n u[n]=\begin{cases}a^n, & n\ge 0\\ 0, & n<0\end{cases},\qquad h[n]=u[n]$$

$a$ birden büyük ya da küçük olabilir. Örneğin $a=1/2$ alınırsa $x[n]$ önce 1, sonra $1/2$, sonra $1/4$ değerlerini alarak sonsuza kadar gider. İmpuls cevabı ise basit bir birim basamak fonksiyonudur.

Genel formülde $x[k]$ ve $h[n-k]$ yerine konur. Toplamda değişken artık $k$'dir:

$$y[n]=\sum_{k=-\infty}^{\infty}a^k u[k]\,u[n-k]$$

$u[k]$ nedeniyle $k$ sıfırdan başlar. $u[n-k]$ ise $k>n$ olduğunda sıfırdır: örneğin $k=n+1$ için $u[-1]=0$ olur. Bu yüzden üst sınır $n$'dir:

$$y[n]=\sum_{k=0}^{n}a^k=\frac{1-a^{n+1}}{1-a},\quad n\ge 0$$

ve $n<0$ için $y[n]=0$'dır. Yani $y[n]=\frac{1-a^{n+1}}{1-a}\,u[n]$.

Doğrulama (python, $a=1/2$): Sayısal konvolüsyonun ilk değerleri $1;\ 1{,}5;\ 1{,}75;\ 1{,}875;\ 1{,}9375$ olup formülle aynıdır.

## 10. Sonlu Uzunluklu Dizilerin Konvolüsyonu

### 10.1 Örnek diziler

Hoca konvolüsyonun pratik yolunu iki sonlu diziyle gösterdi (ekrandan, 01:35:00 ve 01:40:00). Bir sistemin impuls cevabı $h[n]$ biliniyor, giriş $x[n]$; $y[n]$ isteniyor:

- $x[n]=[3,\ 2,\ 1]$, tanım aralığı $[0,\ 2]$, uzunluğu $L_x=3$.
- $h[n]=[-1,\ 2,\ 1]$, tanım aralığı $[-1,\ 1]$, uzunluğu $L_h=3$. Yani $h[-1]=-1$, $h[0]=2$, $h[1]=1$.

$y[n]=\sum_k x[k]\,h[n-k]$ formülünde birinci dizi sabit tutulur. Değişken $k$ olduğu ve $h[n-k]$'de eksi işareti bulunduğu için ikinci dizi ters çevrilir: $h[-k]$ dizisinde $k=-1$'de 1, $k=0$'da 2, $k=1$'de $-1$ bulunur. Bu ters dizi sanki eksi sonsuzdan gelip $x$ üzerinden geçiyormuş gibi adım adım sağa kaydırılır.

### 10.2 Uzunluk ve sınır kuralı

Tahtadaki not (ekrandan, 01:40:00): İki sonlu uzunluklu dizide $x[n]$'nin uzunluğu $L_x$, tanım aralığı $[M_x,\ N_x]$; $h[n]$'nin uzunluğu $L_h$, tanım aralığı $[M_h,\ N_h]$ olsun. O zaman

$$L_y=L_x+L_h-1,\qquad [M_y,\ N_y]=[M_x+M_h,\ N_x+N_h]$$

Örnekte $L_y=3+3-1=5$ ve $[M_y,N_y]=[0+(-1),\ 2+1]=[-1,\ 3]$ olur. Sağlama: $-1, 0, 1, 2, 3$ gerçekten 5 indistir.

### 10.3 Adım adım hesap

Ters çevrilmiş dizi kaydırılırken her adımda üst üste gelen örnekler çarpılıp toplanır (ekrandan, 01:45:00 ve 01:55:00):

- $y[-1]$: İlk karşılaşmada yalnız $-1$ ile $3$ üst üste gelir. $y[-1]=-1\times 3=-3$.
- $y[0]$: Dizi bir sağa kayar, merkezindeki 2 artık $x[0]$'ın altındadır. $y[0]=2\times 3+2\times(-1)=6-2=4$.
- $y[1]$: Bir sağa daha kayar. $y[1]=3\times 1+2\times 2+1\times(-1)=3+4-1=6$.
- $y[2]$: $y[2]=2\times 1+1\times 2+0\times(-1)=4$. Son terim tanımsız bölgeye düştüğü için sayılmaz.
- $y[3]$: Yalnız iki değer çakışır. $y[3]=1\times 1=1$.

Sonuç: $n=-1,0,1,2,3$ için $y[n]=[-3,\ 4,\ 6,\ 4,\ 1]$. Hoca aynı işlemi dizileri kutucuklar halinde yazıp ters diziyi altlarında kaydırarak da gösterdi (ekrandan, 01:50:00): ilk adımda $3\times(-1)=-3$ ve bu değer başlangıç indisi olan $-1$'e yazılır; sonraki adımda $3\times2+2\times(-1)=4$ ve bu böyle devam eder. Sonuç python (`numpy.convolve`) ile de doğrulandı.

### 10.4 Aradaki sıfırlar üzerine soru-cevap

**Soru:** Dizi $0$ ile $2$ yerine $0$ ile $3$ arasında verilse ama arada bir değer olmasa, oraya sıfır mı yazılır?

**Cevap:** Evet. Dizi örneğin $3, 0, 2, 1$ biçiminde olur ve o eleman sıfırla çarpılır. Önemli olan başlangıç ve bitiş indislerinin doğru belirlenmesidir. Başlangıç indisi dizinin sıfırdan farklı ilk değer aldığı yer (hocanın çizdiği örnekte $-3$), bitiş indisi de sıfırdan farklı değer aldığı son indistir.

## 11. MATLAB'de Konvolüsyon ve İndisli Çizim

Hoca MATLAB'in çevrimiçi sürümünde (MATLAB Online) aynı örneği çalıştırdı. Ekrandaki komutlar (ekrandan, 02:00:00 ve 02:05:00):

```matlab
x = [3 2 1]
h = [-1 2 1]
xi = 0:2          % x'in indisleri
hi = -1:1         % h'nin indisleri
y = conv(x, h)    % -3 4 6 4 1
yi = xi + hi      % yanlış deneme: -1 1 3 (elemanları tek tek toplar)
yi(1)             % ilk eleman
yi(end)           % son eleman
yi = xi(1)+hi(1) : xi(end)+hi(end)   % doğru çıkış indisleri: -1 0 1 2 3
stem(yi, y)
```

Anlatılan noktalar:

- `a:b` yapısı 1'er artan bir vektör üretir. `0:0.1:3` gibi bir yazımla adım belirlenebilir; bu örnekte değerler 0, 0,1, 0,2 diye 3'e kadar gider. MATLAB'de diziler ve skalerler matris yapısında tutulur. İndisler tam sayı olduğu için hoca 1'er artan vektör kullandı.
- `conv(x,h)` değerleri doğru verir ($-3, 4, 6, 4, 1$), fakat başlangıç ve bitiş indislerini vermez. `stem(y)` yazıldığında örnekler 1'den 5'e kadar indislerle çizilir; değerler doğru, indisler yanlıştır.
- Hoca önce `yi = xi + hi` yazdı; bu iki vektörü eleman eleman toplayıp $[-1, 1, 3]$ verdiği için yanlıştır. Doğrusu, ilk elemanların toplamından son elemanların toplamına kadar 1'er artan vektördür. Örnekte $0+(-1)=-1$ ve $2+1=3$ olduğundan indisler $-1, 0, 1, 2, 3$ olur.
- `stem(yi, y)` ile değerler doğru indislerde çizilir. Eksenler `xlabel`, `ylabel('Genlik')` ve `title` (başlık olarak "Konvolüsyon sonucu y[n]") ile düzenlendi. <!-- BELİRSİZ: xlabel içine yazılan metin altyazıda net değil ("indis veya n") ve karede görünmüyor. -->
- Komutun sonuna `;` konursa sonuç ekrana basılmaz, konmazsa basılır.
- MATLAB'de genellikle `plot` kullanılır, ama `plot` noktaları birleştirir. Ayrık işaret işlemede örnekleri ayrık çizen `stem`, bizim çizimlerimize daha yakındır.

> **Ek bilgi (derste anlatılmadı):** Python'da `numpy.convolve(x, h)` MATLAB'deki `conv` ile aynı sonucu verir; o da indis bilgisi taşımaz. Çizim için `matplotlib.pyplot.stem` ve dört parçalı ekran için `matplotlib.pyplot.subplot(2, 2, i)` kullanılabilir.

## Örnek Sorular

### Soru 1: Hafızalı mı, hafızasız mı?

Kaynak: (ekrandan, 00:40:00)

Aşağıdaki sistemlerin hafızalı mı hafızasız mı olduğunu belirleyin: (a) $y[n]=x^2[n]$, (b) $y[n]=e^{x[n]}$, (c) $y[n]=x[n]+x[n-1]+x^2[n+1]$.

**Çözüm (derste verildi):** (a) ve (b) hafızasızdır; örneğin $y[1]=e^{x[1]}$ yalnız o anki girişe bağlıdır. (c) hafızalıdır; $y[1]=x[1]+x[0]+x^2[2]$ hesabı için $x[0]$ ve $x[2]$'nin saklanması gerekir.

### Soru 2: Nedensellik

Kaynak: (ekrandan, 01:05:00)

$y[n]=x[n]+x[n-1]$ ve $y[n]=x[n-1]+x^2[n+1]$ sistemleri nedensel midir?

**Çözüm (derste verildi):** Birincisi nedenseldir; yalnız şu anki ve geçmiş örnekleri kullanır. İkincisi için $y[1]=x[0]+x^2[2]$ olur; $x[2]$ gelecekteki bir örnek olduğundan sistem nedensel değildir.

### Soru 3: LSI sistemin kararlılığı

Kaynak: (ekrandan, 01:00:00; derste sözlü, 00:59:54)

İmpuls cevabı $h[n]=a^n u[n]$, $|a|<1$ olan LSI sistem kararlı mıdır? $a=1/2$ için koşuldaki toplam kaçtır?

**Çözüm (derste verildi):** $\sum_{n}|h[n]|=\sum_{n=0}^{\infty}|a|^n=\frac{1}{1-|a|}<\infty$ olduğundan sistem kararlıdır. $a=1/2$ için toplam $1+\frac12+\frac14+\dots=2$'dir.

### Soru 4: Analitik konvolüsyon

Kaynak: (ekrandan, 01:30:00)

$x[n]=a^n u[n]$ ve $h[n]=u[n]$ için $y[n]=x[n]*h[n]$'yi bulun.

**Çözüm (derste verildi):** $y[n]=\sum_{k=0}^{n}a^k=\frac{1-a^{n+1}}{1-a}\,u[n]$ (ara adımlar Bölüm 9'da).

### Soru 5: Sonlu dizilerin konvolüsyonu

Kaynak: (ekrandan, 01:35:00 ve 01:45:00)

$x[n]=[3,2,1]$ ($n=0,1,2$) ve $h[n]=[-1,2,1]$ ($n=-1,0,1$) için $y[n]$'nin uzunluğunu, tanım aralığını ve değerlerini bulun.

**Çözüm (derste verildi):** $L_y=3+3-1=5$, aralık $[-1,3]$. $y[-1]=-3$, $y[0]=4$, $y[1]=6$, $y[2]=4$, $y[3]=1$ (adımlar Bölüm 10.3'te).

### Soru 6: Ödev 1, `myconv` programı

Kaynak: (derste sözlü, 01:55:31; ekrandan, 02:10:00)

MATLAB veya Python'da adı `myconv` olan bir program yazın. Program kullanıcıdan (input fonksiyonuyla) $x$ dizisini, $h$ dizisini, $x$'in başlangıç ve bitiş indislerini ($M_x$, $N_x$) ve $h$'nin başlangıç ve bitiş indislerini ($M_h$, $N_h$) istesin; uzunluklar dizilerden hesaplansın. Ekranı `subplot` ile dörde bölün: $x[n]$'yi, $h[n]$'yi, `myconv` sonucunu ve MATLAB ya da Python'ın hazır `conv` fonksiyonunun sonucunu doğru indislerle `stem` ile çizin; iki sonucun aynı olduğu görülsün. Bunu üç farklı örnek için yapın; örneğin biri negatif indislerden başlayan bir $x$, biri yalnız pozitif indisli bir $h$, biri yalnız negatif indisli bir dizi içersin.

> **Çözüm (derste verilmedi):** Aşağıdaki Python çekirdeği derste yazılmamıştır; ajan tarafından yazılıp üç örnekte `numpy.convolve` ile karşılaştırılarak test edilmiştir. Kullanıcı girişi ve çizim kısmı ödevin parçası olarak bırakılmıştır.
>
> ```python
> def myconv(x, mx, h, mh):
>     """x mx indisinden, h mh indisinden başlar. (y, my) döndürür."""
>     ly = len(x) + len(h) - 1          # L_y = L_x + L_h - 1
>     y = [0] * ly
>     for i in range(len(x)):
>         for j in range(len(h)):
>             y[i + j] += x[i] * h[j]   # x[mx+i] * h[mh+j] -> y[mx+mh+i+j]
>     return y, mx + mh                 # M_y = M_x + M_h
> ```
>
> Test sonuçları: $x=[3,2,1]$ ($M_x=0$), $h=[-1,2,1]$ ($M_h=-1$) için $n=-1..3$'te $[-3,4,6,4,1]$; $x=[1,-2,4]$ ($M_x=-2$), $h=[2,1,3,1]$ ($M_h=1$) için $n=-1..4$'te $[2,-3,9,-1,10,4]$; $x=[2,0,-1]$ ($M_x=-1$), $h=[1,1]$ ($M_h=-3$) için $n=-4..-1$'de $[2,2,-1,-1]$.

## Dersin Toparlaması

Bu derste ayrık işaretlerden ayrık zaman sistemlerine geçildi. Bir sistemin hafızalı ya da hafızasız, toplamsal, homojen, doğrusal, öteleme ile değişmez, nedensel ve kararlı olması tanımlandı ve her biri örneklerle gösterildi. İşaret ayrıştırması ile doğrusallık birleştirilince sistem çıkışının kaydırılmış impuls cevapları cinsinden yazılabildiği, sisteme öteleme ile değişmezlik de eklenince (LSI) bu ifadenin konvolüsyon toplamına dönüştüğü görüldü. LSI bir sistem, birim impuls cevabı $h[n]$ ile tamamen karakterize edilir; kararlılığı da $\sum|h[n]|<\infty$ koşuluyla $h[n]$ üzerinden kontrol edilir.

İkinci bölümde konvolüsyonun değişme, birleşme (kaskat sistemler) ve dağılma (paralel sistemler) özellikleri, analitik bir örnek ($a^n u[n]*u[n]$) ve sonlu iki dizinin ters çevir-kaydır-çarp-topla yöntemiyle adım adım konvolüsyonu işlendi. Çıkışın uzunluğu ve indis aralığı için $L_y=L_x+L_h-1$ ve $[M_x+M_h,\ N_x+N_h]$ kuralları verildi ve MATLAB'de `conv` ile `stem` kullanılarak sonucun doğru indislerle nasıl çizileceği gösterildi. Hoca bir sonraki derste frekansla ilgili konulara başlanacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
