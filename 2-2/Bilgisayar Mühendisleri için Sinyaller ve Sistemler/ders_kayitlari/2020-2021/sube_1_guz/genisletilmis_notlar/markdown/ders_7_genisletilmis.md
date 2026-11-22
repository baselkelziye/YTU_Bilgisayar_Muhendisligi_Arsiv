# Ders 7 Genişletilmiş Notu: Ayrık Zamanda Dürtü Yanıtı ve Konvolüsyon Toplamı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Sürekli Konvolüsyonun Tekrarı ve Ayrık Zamana Geçiş
- 2. Fark Denklemleri ve Hafızalı Sistemler
- 3. Ayrık Zamanda Dürtü Yanıtı
- 4. Keyfi Bir İşaretin Dürtülerle Yazılması
- 5. Konvolüsyon Toplamının Türetilmesi
- 6. Konvolüsyonun Uygulama Alanları
- 7. Slayttaki Konvolüsyon Toplamı Örneği
- 8. Konvolüsyonun Özellikleri, Kararlılık ve Sistem Bağlantıları
- 9. Sonlu Dizilerde Uzunluk ve Sınır Kuralları
- 10. Çözümlü Örnek: Formülle Çözüm (1. Yol)
- 11. Çözümlü Örnek: Kaydırma Yöntemi (2. Yol)
- 12. MATLAB ile Konvolüsyon ve Programlama Alıştırması
- 13. Sürekli ve Ayrık Konvolüsyonun Karşılaştırılması
- Örnek Sorular

## 1. Sürekli Konvolüsyonun Tekrarı ve Ayrık Zamana Geçiş

Önceki derste sürekli sistemlerde konvolüsyon işlenmişti. Bu derste aynı kavram ayrık zamanlı sistemler için kuruldu. Kullanılan slayt dizisi M. J. Roberts'ın "Signals and Systems" kitabının slaytlarıdır ve bu bölüm "B) Discrete Time Convolution" başlığıyla açılıyor (ekrandan, 00:05:00).

Sürekli zamanda bir sistem $x(t)$ girişini $y(t)$ çıkışına dönüştürür. Sistemi karakterize eden şey birim dürtü (impuls) yanıtı $h(t)$'dir ve çıkış, iki sürekli fonksiyonun, $x(t)$ ile $h(t)$'nin konvolüsyonudur. Sürekli birim dürtü ok şeklinde gösterilir: yalnız bir anda var olup hemen yok olan, altındaki alanı 1 kabul edilen teorik bir işarettir. Hoca bunun nasıl kurulduğunu hatırlattı: $-T_0/2$ ile $T_0/2$ arasında tanımlı bir dikdörtgen darbe (biraz daha gerçeklenebilir bir kare dalga) alınır ve $T_0$ sıfıra götürülür; limitte dürtü teorik olarak elde edilir.

Ayrık zamanda aynı fikirler geçerlidir. Hoca, sayısal işaret işleme dersinden farklı olarak bu derste konuların hem sürekli hem ayrık zamanlı hâllerinin arka arkaya işlendiğini belirtti. Ayrık işaret $x[n]$, sürekli bir işaretten alınan örneklerden oluşur. Artık zaman değişkeni yoktur; sıfırıncı örnek, birinci örnek gibi tam sayı indisler vardır.

Ayrık birim dürtü ok şeklinde değil, belli bir indiste genliği 1 olan tek bir örnek olarak tanımlanır. Sisteme $\delta[n]$ uygulandığında alınan yanıta $h[n]$ denir ve herhangi bir giriş için çıkış $y[n]=x[n]*h[n]$ olur. Hoca, ayrık zamandaki konvolüsyonu kavradıktan sonra sürekli konvolüsyona geri dönüldüğünde onun da daha kolay anlaşılacağını söyledi.

## 2. Fark Denklemleri ve Hafızalı Sistemler

LTI (Linear Time Invariant, doğrusal ve zamanla değişmez) ayrık zamanlı sistemler matematiksel olarak fark denklemleriyle tanımlanır (ekrandan, 00:15:00):

$$a_0y[n]+a_1y[n-1]+\dots+a_Ny[n-N]=b_0x[n]+b_1x[n-1]+\dots+b_Mx[n-M]$$

Çıkış, kendi önceki değerlerine ($N$ adım öncesine kadar) ve girişin şimdiki ve önceki değerlerine ($M$ adım öncesine kadar) bağlıdır. Hoca burada şuna dikkat çekti: her gecikmiş çıkış ya da giriş değerinin bir yerde saklanması gerekir. Bu yüzden bu tür sistemler hafızalı sistemlerdir.

Tahtadaki örnek $y[n]=y[n-1]+x[n]+\dfrac{x[n-1]}{2}$ denklemidir (ekrandan, 00:15:00). Bunu genel biçimle karşılaştırırsak $y[n-1]$ terimi sol tarafa geçince işareti değişir. Böylece $a_0=1$, $a_1=-1$, $b_0=1$ ve $b_1=1/2$ olur. Bu sistemde $y[n-1]$ ve $x[n-1]$'in hafızada tutulması gerekir.

Slaytta şu genel ilke de yazıyor: herhangi bir uyarı (excitation) $x[n]$ için yanıt $y[n]$, önce $x[n]$'nin sağ taraftaki tek zorlayıcı fonksiyon olduğu durumdaki yanıt bulunarak, sonra bu yanıtın ölçeklenmiş ve zamanda ötelenmiş kopyaları toplanarak elde edilebilir. Slayt girişi "input" yerine "excitation" (uyarı) diye adlandırıyor.

## 3. Ayrık Zamanda Dürtü Yanıtı

Giriş bir birim dürtü (genliği 1 olan dürtü) ise sistemin buna verdiği yanıta $h[n]$ denir. Dürtünün kaydırılmış ve genliği değiştirilmiş kopyaları bir araya gelerek her girişi oluşturabildiği için, $h[n]$ bilindiğinde sistemin herhangi bir $x[n]$'ye vereceği yanıt da bulunabilir.

Dürtü sisteme yalnız $n=0$ anında uygulanır ve sistemin tek uyarısı odur. Sistem nedensel ise dürtüden önce bir çıkış üretmez (ekrandan, 00:20:00):

$$h[n]=0,\qquad n<0$$

$n=0$'da dürtü gelir ve gider; ondan sonra uyarı yine sıfırdır. Ama sistemin yanıtı devam edebilir, çünkü o andaki giriş sonraki çıkışları etkileyebilir. $n>0$ için fark denkleminin çözümü homojen çözümdür. Bu yüzden dürtü yanıtı şu biçimdedir:

$$h[n]=y_h[n]\,u[n]$$

Hoca, fark denklemlerinin çözümünün (homojen çözüm, özel çözüm) bu dersin kapsamında olmadığını, bunların matematikteki diferansiyel denklemlere benzediğini ve ayrıntısının sayısal işaret işleme dersinde anlatılacağını söyledi. Burada tanımı bilmek yeterlidir.

> **Ders sonrası not:** Hoca anlatırken bir yerde "$n=0$'dan önce sistemin çıkışı homojen çıkış" dedi. Slayta göre homojen çözüm $n>0$ için geçerlidir; $n<0$'da nedensel sistemin dürtü yanıtı sıfırdır.

> **Hocanın vurgusu:** Akılda tutulması gereken şu: elimizde bir $x[n]$ girişi var ve $y[n]$'yi bulmak istiyoruz. Sistemi karakterize eden şey dürtü yanıtıdır. $x[n]$ dürtülerden oluştuğu için, sistem LTI ise ve dürtü yanıtı biliniyorsa çıkış bulunabilir. Bu dersin amacı bunu öğrenmektir.

## 4. Keyfi Bir İşaretin Dürtülerle Yazılması

Keyfi bir giriş, temelde dürtünün genliği ölçeklenmiş ve zamanda ötelenmiş kopyalarından oluşur. Örneğin $2\delta[n]$, genliği 2 olan bir dürtüdür; $\delta[n-1]$ ise bir sağa kaydırılmış dürtüdür. Bunların uygun genliklerle toplamı bir $x[n]$ işaretini verir. Bu nedenle sistemin yanıtı da genliği ölçeklenmiş ve ötelenmiş dürtü yanıtlarının toplamıdır.

Hoca bunu iki dürtülük bir girişle anlattı. Tek bir dürtü verilseydi yanıt, $h[n]$ gibi azalarak giden bir dizi olurdu. Ama bir adım sonra ikinci bir dürtü daha gelirse, ilk yanıt sürerken ikincisinin yanıtı ona eklenir; çıkış toplamsal olarak artar, sonra azalmaya başlar. Slayttaki karmaşık örnekte de periyodik görünen bir uyarı ile üstel azalan bir dürtü yanıtından elde edilen çıkış gösteriliyor (ekrandan, 00:25:00). Uyarı periyodik ve sürekli devam eden bir dizi de olabilir, sonlu bir dizi de; dürtü yanıtı biliniyorsa her iki durumda çıkış hesaplanabilir.

### 4.1 Tahtadaki ayrıştırma örneği

Hoca tahtaya şu değerleri alan bir işaret çizdi (ekrandan, 00:35:00): $x[-3]=-1$, $x[-2]=1$, $x[-1]=-0{,}5$, $x[0]=2$, $x[1]=1$, $x[2]=0{,}5$. Sonra her örneği ayrı bir dürtü olarak yazdı:

- $x_0[n]=x[0]\,\delta[n]=2\delta[n]$
- $x_1[n]=x[1]\,\delta[n-1]=\delta[n-1]$
- $x_2[n]=x[2]\,\delta[n-2]=0{,}5\,\delta[n-2]$
- $x[-1]\,\delta[n+1]=-0{,}5\,\delta[n+1]$ (sola kaydırılmış dürtü $-0{,}5$ ile çarpılır; dürtünün genliği 1 olduğu için neyle çarpılırsa o değeri alır)
- $x[-2]\,\delta[n+2]=\delta[n+2]$
- $x[-3]\,\delta[n+3]=-\delta[n+3]$

Bunların toplamı işaretin kendisidir:

$$x[n]=-\delta[n+3]+\delta[n+2]-0{,}5\,\delta[n+1]+2\delta[n]+\delta[n-1]+0{,}5\,\delta[n-2]$$

Toplam biçiminde, $k$ ana değişken olmak üzere, $x[k]$'nın sıfırdan farklı olduğu her indis için bir terim yazılır (ekrandan, 00:40:00):

$$x[n]=\sum_{k=-\infty}^{\infty}x[k]\,\delta[n-k]=x[-3]\delta[n+3]+x[-2]\delta[n+2]+x[-1]\delta[n+1]+x[0]\delta[n]+\dots$$

## 5. Konvolüsyon Toplamının Türetilmesi

Hoca türetmeyi başka bir kitaptan daha anlaşılır bulduğu bir anlatımla, tahtada blok diyagramlarla yaptı (ekrandan, 00:30:00 ve 00:35:00).

1. Bir LTI sistemin girişine $\delta[n]$ uygulanırsa çıkışta $h[n]$ elde edilir.
2. Zamanla değişmezlik (ötelemeyle değişmezlik): giriş zamanda ötelenirse çıkış da aynı miktarda ötelenir. Dolayısıyla $\delta[n-k]\to h[n-k]$.
3. Doğrusallığın ölçeklenebilirlik (homogeneity) özelliği: giriş bir sabitle çarpılırsa çıkış da aynı sabitle çarpılır. $k$ kadar kaydırılmış yerdeki genlik değerine $x[k]$ denirse $x[k]\,\delta[n-k]\to x[k]\,h[n-k]$. Burada $x[k]$ skaler bir sayıdır, $x$ fonksiyonunun $k$'da aldığı değerdir (örneğin $x[1]=0{,}5$ ya da $x[2]=-1$ gibi).
4. Doğrusallığın toplamsallık özelliği: girişteki işaretler toplanırsa çıkıştaki yanıtlar da toplanır. Her iki taraf $k$ üzerinden toplanır:

$$\sum_{k=-\infty}^{\infty}x[k]\,\delta[n-k]\ \longrightarrow\ \sum_{k=-\infty}^{\infty}x[k]\,h[n-k]$$

Sol taraf, 4. bölümde gösterildiği gibi $x[n]$'nin kendisidir. Sağ taraf ise çıkıştır. Böylece ayrık konvolüsyon (discrete convolution) elde edilir (ekrandan, 00:40:00):

$$y[n]=\sum_{k=-\infty}^{\infty}x[k]\,h[n-k]=x[n]*h[n]$$

Yani çıkış, girişin her bir elemanı için dürtü yanıtının o elemanın genliğiyle çarpılıp o elemanın indisine kaydırılmış kopyalarının toplamıdır.

Sürekli zamanda aynı denklemde toplam yerine integral gelir; buna sürekli konvolüsyon (continuous convolution) denir. Orada da giriş, dürtülere verilen yanıtların toplanmasıyla çıkışa dönüşür.

> **Ders sonrası not:** Hoca sürekli konvolüsyonu tahtaya $y(t)=\int_{-\infty}^{\infty}x(t)\,h(t-k)\,dk$ diye yazdı (ekrandan, 00:40:00). Doğrusu $y(t)=\int_{-\infty}^{\infty}x(\tau)\,h(t-\tau)\,d\tau$'dur; integral değişkeni hem girişin hem dürtü yanıtının argümanında yer almalıdır.

Hoca ilerleyen bölümde slaytla uyumlu olmak için kaydırma değişkenine $k$ yerine $m$ dedi: $y[n]=\sum_{m=-\infty}^{\infty}x[m]\,h[n-m]$. Önemli olan, bu değişkenin kaydırma miktarı olmasıdır. Konvolüsyon toplamı açılırsa, örneğin $x$ ilk sıfırdan farklı değerini $-1$'de alıyorsa, $\dots+x[-1]h[n+1]+x[0]h[n]+x[1]h[n-1]+\dots$ biçiminde, yalnız $x$'in sıfırdan farklı olduğu girişlere ait kaydırılmış dürtü yanıtları toplama katılır.

Hoca bu noktada matematiğin soyut bir bilim olduğunu, soyut gelen kavramların ödevler ve soru çözerek zamanla oturacağını söyledi ve kaynak olarak M. J. Roberts'ın "Signals and Systems: Analysis Using Transform Methods and MATLAB" kitabını önerdi; derste kullanılan slaytlar bu kitabındır. Oppenheim'ın "Signals and Systems" kitabı ve "Fundamentals of Signals and Systems" gibi kitapların da aynı konuları anlattığını belirtti.

## 6. Konvolüsyonun Uygulama Alanları

Bir öğrencinin bu kavramların soyutluğuyla ilgili sorusu üzerine hoca, bunların nerede karşımıza çıkacağını anlattı. Şu anda tek boyutta çalışılıyor, ama görüntülerde piksel değerleri bir matris oluşturur ve işaret iki değişkenli olur ($x[u,v]$ gibi) (ekrandan, 00:50:00). Bu durumda ders görüntü işlemeye dönüşür. Görüntü işlemede kullanılan bulanıklaştırma (blur) filtreleri ve yüksek geçiren kenar bulma filtreleri hep konvolüsyonla yapılır.

Makine öğrenmesinde ve derin öğrenmede de evrişimli sinir ağları (convolutional neural network) vardır. Orada kullanılan filtreler, bu dersteki $h[n]$'lerin karşılığıdır. "Neden $3\times3$ ya da $5\times5$ filtre kullanılıyor, etkisi nedir?" gibi sorulara mühendis gözüyle bakabilmek için bu altyapıyı bilmek gerekir. Hoca, bilgisayar mühendisliğinde en çok kullanılacak kavramların altyapısında sinyal ve sistemlerden örnekler olduğunu vurguladı.

## 7. Slayttaki Konvolüsyon Toplamı Örneği

Slayttaki örnekte (ekrandan, 00:50:00) giriş $x[n]$, $n=-1,0,1$'de genliği 2 olan üç dürtüden oluşur; hoca bunun sisteme bir kare darbe uygulamak gibi düşünülebileceğini söyledi. Dürtü yanıtı $h[0]=1$, $h[1]=2$'dir. İstenen $y[n]$'dir.

Formüle göre $y[n]=\sum_m x[m]h[n-m]$. Slayttaki çözümde önce dürtü yanıtı $m$ ekseninde ters çevrilir: $h[-m]$, $m=-1$'de 2, $m=0$'da 1 değerini alır. Sonra $h[n-m]$, $n$'nin değerine göre $m$ ekseninde sağa sola kayar. $x[m]$ yerinde sabit durur. Her $n$ için çakışan örnekler çarpılır ve toplanır (ekrandan, 00:55:00):

- $n=-1$: $h[-1-m]$, $m=-2$'de 2, $m=-1$'de 1 değerini alır. $x$ ile yalnız $m=-1$'de çakışır: $y[-1]=2\cdot1=2$.
- $n=0$: $h[-m]$ ile $m=-1$ ve $m=0$'da çakışma vardır: $y[0]=2\cdot2+2\cdot1=4+2=6$.
- $n=1$: fonksiyon bir sağa kayar, yine iki çakışma: $y[1]=2\cdot2+2\cdot1=6$.
- $n=2$: yalnız $m=1$'de çakışma: $y[2]=2\cdot2=4$.

Sonuç: $y[-1]=2$, $y[0]=6$, $y[1]=6$, $y[2]=4$; diğer indislerde 0.

## 8. Konvolüsyonun Özellikleri, Kararlılık ve Sistem Bağlantıları

### 8.1 Konvolüsyon toplamının özellikleri

Aradan sonra konvolüsyonun özelliklerine geçildi (ekrandan, 01:15:00):

- Dürtü yanıtı tek bir ölçeklenmiş ve ötelenmiş dürtüyse çıkış, girişin aynı miktarda ötelenip aynı katsayıyla çarpılmış hâlidir: $x[n]*A\delta[n-n_0]=Ax[n-n_0]$.
- $y[n]=x[n]*h[n]$ ise $y[n-n_0]=x[n]*h[n-n_0]=x[n-n_0]*h[n]$. Dürtü yanıtı ya da giriş $n_0$ kaydırılırsa çıkış da $n_0$ kayar.
- $y[n]-y[n-1]=x[n]*(h[n]-h[n-1])=(x[n]-x[n-1])*h[n]$. Çıkışın birinci farkı, dürtü yanıtının farkıyla ya da girişin farkıyla konvolüsyondur.
- Değişme özelliği: iki dizinin yer değiştirmesi, yani hangisinin sabit tutulup hangisinin ters çevrilip üzerinden geçirildiği, sonucu değiştirmez.
- Birleşme: birden çok dizide ikili konvolüsyonlar hangi sırayla alınırsa alınsın sonuç aynıdır.
- Dağılma: iki dizinin toplamının bir $z[n]$ ile konvolüsyonu, ayrı ayrı konvolüsyonların toplamına eşittir.
- Slaytta ayrıca $y$'deki dürtü genliklerinin toplamının, $x$'teki ve $h$'deki genlik toplamlarının çarpımı olduğu yazıyor. Slayt örneğinde $\sum x=6$, $\sum h=3$, $\sum y=2+6+6+4=18$'dir.

### 8.2 Kararlılık ve dürtü yanıtı

Çıkışın kararlı (stabil, durağan) olması isteniyorsa, dürtü yanıtının mutlak değerlerinin toplamı sonlu bir değere varmalıdır:

$$\sum_{n=-\infty}^{\infty}|h[n]|<\infty$$

Bu toplam sonsuza gidiyorsa sistem duran bir çıkış üretmez.

> **Ek bilgi (derste anlatılmadı):** Bu koşul sınırlı giriş-sınırlı çıkış (BIBO) kararlılığının LTI sistemler için gerek ve yeter koşuludur. Yani her sınırlı girişe sınırlı bir çıkış verilmesi, dürtü yanıtının mutlak toplanabilir olmasına denktir.

### 8.3 Kaskat ve paralel bağlantı

Bir $x[n]$ girişi önce $h_1[n]$ sisteminden, ardından $h_2[n]$ sisteminden geçiyorsa çıkış $y[n]=\{x[n]*h_1[n]\}*h_2[n]$ olur (ekrandan, 01:20:00). Aradaki konvolüsyonu ayrıca hesaplamadan çıkışı bulmanın kolay yolu, önce $h_3[n]=h_1[n]*h_2[n]$'yi bulmak ve girişi bu tek eşdeğer sistemle konvolüsyona sokmaktır. Buna kaskat (cascade, seri) bağlantı denir ve konvolüsyonun birleşme özelliğinin doğrudan sonucudur. Aynı şey sürekli zamanda da gösterilmişti.

Sistemler paralel bağlıysa ve çıkışları toplanıyorsa, eşdeğer dürtü yanıtı $h_1[n]+h_2[n]$'dir; girişin bu toplamla konvolüsyonunu almak yeterlidir.

Hoca, MATLAB ve Python'da hazır bir konvolüsyon fonksiyonu bulunduğunu ve bunu dersin sonunda göstereceğini söyleyerek sayısal konvolüsyon (numerical convolution) slaytlarını atladı.

## 9. Sonlu Dizilerde Uzunluk ve Sınır Kuralları

Hoca yeni bir örnek verdi (ekrandan, 01:25:00): $x[n]$, $n=-1$'de 1, $n=0$'da 2, $n=1$'de 0, $n=2$'de $-1$ değerini alır; dizi olarak $[1,\ 2,\ 0,\ -1]$. Dürtü yanıtı $h[n]$, $n=0,1,2$'de $3,2,1$ değerlerini alır. İstenen $y[n]$'dir.

Çözüme geçmeden önce sonucun nerede başlayıp nerede biteceği bulunur.

- Bir dizinin uzunluğu, ilk sıfırdan farklı değer aldığı indis ile son sıfırdan farklı değer aldığı indis arasındaki örnek sayısıdır. $L_x=4$, $L_h=3$.
- Her bir konvolüsyonun sonucu $L_y=L_x+L_h-1$ uzunluğundadır. Burada $L_y=4+3-1=6$.
- $x$'in ilk ve son sıfırdan farklı indisleri $[M_x,\ N_x]=[-1,\ 2]$, $h$'ninkiler $[M_h,\ N_h]=[0,\ 2]$ olsun. Sonucun sınırları:

$$[M_y,\ N_y]=[M_x+M_h,\ N_x+N_h]=[-1+0,\ 2+2]=[-1,\ 4]$$

$-1$ ile $4$ arasında $6$ indis vardır; iki kural birbiriyle tutarlıdır (ekrandan, 01:40:00).

> **Hocanın vurgusu:** Bu iki özellik (uzunluk $L_x+L_h-1$ ve sınırlar $[M_x+M_h,\ N_x+N_h]$) bilinmeli.

## 10. Çözümlü Örnek: Formülle Çözüm (1. Yol)

İlk yöntem formülün doğrudan uygulanmasıdır: $y[n]=\sum_k x[k]h[n-k]$. Her sıfırdan farklı $x[k]$ için $y_k[n]=x[k]\,h[n-k]$ dizisi ayrı ayrı çizilir ve sonunda hepsi toplanır (ekrandan, 01:30:00, 01:35:00 ve 01:40:00).

- $k=-1$: $x_{-1}[n]=x[-1]\delta[n+1]$, $x[-1]=1$. $y_{-1}[n]=x[-1]\,h[n+1]=h[n+1]$. $h[n+1]$, $h[n]$'nin bir sola ötelenmiş hâlidir: $n=-1,0,1$'de $3,2,1$.
- $k=0$: $x_0[n]=x[0]\delta[n]$, $x[0]=2$. $y_0[n]=x[0]\,h[n]=2h[n]$: $n=0,1,2$'de $6,4,2$.
- $k=1$: $x[1]=0$ olduğu için $0\cdot h[n-1]$ bütün değerleri sıfırlar; bu terim çizilmeden atlanır.
- $k=2$: $x_2[n]=x[2]\delta[n-2]$, $x[2]=-1$. $y_2[n]=x[2]\,h[n-2]=-h[n-2]$: $n=2,3,4$'te $-3,-2,-1$.

Girişin parçalarının toplamı $x_{-1}[n]+x_0[n]+x_2[n]$, $x[n]$'nin kendisidir. Çıkışların toplamı indis indis yapılır:

| $n$ | $-1$ | $0$ | $1$ | $2$ | $3$ | $4$ |
|---|---|---|---|---|---|---|
| $y_{-1}[n]$ | 3 | 2 | 1 | 0 | 0 | 0 |
| $y_0[n]$ | 0 | 6 | 4 | 2 | 0 | 0 |
| $y_2[n]$ | 0 | 0 | 0 | $-3$ | $-2$ | $-1$ |
| $y[n]$ | 3 | 8 | 5 | $-1$ | $-2$ | $-1$ |

Hoca toplamayı ilk yaptığında $y_0[n]$'yi 2 ile çarpmayı unutup $n=0$ için 5 buldu. Bir öğrenci $y_0[n]$'nin $x[0]=2$ ile çarpılması gerektiğini hatırlattı; hoca değerleri $6,4,2$ olarak düzeltti ve $y[0]=8$ oldu. Sonuç beklendiği gibi $-1$ ile $4$ arasındadır.

**Soru:** $y_{-1}[n]$ çizilirken, $x$'in o indislerde değeri olmadığı için 2 ve 1 değerlerinin sıfır olması gerekmez mi? **Cevap:** Hayır. Bu yöntemde örnekler o anda birbiriyle çarpılmıyor; $x[-1]$ skaleri bütün kaydırılmış $h[n+1]$ dizisiyle çarpılıyor. Noktasal çarpma, birazdan anlatılacak kaydırma yöntemine aittir.

## 11. Çözümlü Örnek: Kaydırma Yöntemi (2. Yol)

İkinci yöntem kaydırma yöntemidir ve daha kolaydır (ekrandan, 01:50:00). Aynı $x=[1,\ 2,\ 0,\ -1]$ ($n=-1..2$) ve $h=[3,\ 2,\ 1]$ ($n=0..2$) kullanılır. Sınırlar yine $[-1,\ 4]$, uzunluk 6'dır.

Önce dürtü yanıtı ters çevrilir: $h[-k]$, $k=-2,-1,0$'da $1,2,3$ değerlerini alır. $h[n-k]$ ise $h[-k]$'nın $n$ kadar kaydırılmış hâlidir. Bu dizi soldan sağa doğru, her adımda bir indis kaydırılır. Her adımda aynı indise düşen (birbirine "değen") değerler çarpılıp toplanır:

- $n=-1$: $h[-1-k]$, $k=-3,-2,-1$'de $1,2,3$. Yalnız $k=-1$ çakışır: $y[-1]=x[-1]\cdot3=1\cdot3=3$ (ekrandan, 01:50:00).
- $n=0$: $h[-k]$, 3 değeri $k=0$'a gelir. $k=-1$ ve $k=0$ çakışır: $y[0]=1\cdot2+2\cdot3=2+6=8$.
- $n=1$: 3 değeri $k=1$'e gelir. $y[1]=1\cdot1+2\cdot2+0\cdot3=1+4=5$.
- $n=2$: 3 değeri $k=2$'ye gelir. $y[2]=2\cdot1+0\cdot2+(-1)\cdot3=2-3=-1$.
- $n=3$: yalnız $k=1$ ve $k=2$ çakışır. $y[3]=0\cdot1+(-1)\cdot2=-2$.
- $n=4$: yalnız $k=2$ çakışır. $y[4]=(-1)\cdot1=-1$.

Sonuç $y=[3,\ 8,\ 5,\ -1,\ -2,\ -1]$ ($n=-1..4$), birinci yolla bulunanla aynıdır (ekrandan, 02:00:00). Birinci yolda $k$ değiştirilerek dürtü yanıtının kaydırılmış kopyaları toplanıyordu; burada $n$ değiştirilerek ters çevrilmiş dürtü yanıtı $x$'in üzerinden geçiriliyor ve her adımda $y$'nin bir elemanı bulunuyor.

**Soru:** Denklemi yazarken $h[n-k]$ çizildi dendi; o aslında $h[k-n]$ değil miydi? $h[n]$ ters çevrilip sola ötelendi. **Cevap:** $h[n]$'nin değerleri $3,2,1$'dir. $h[-n]$ ters çevrilmiş hâlidir. Değişken adı $k$ olunca $h[-k]$ de aynı ters çevrilmiş diziyi verir. $h[n-k]$ yazıldığında ise $k$ ekseninde, $n$'ye verilen değere göre sağa sola kaydırılmış ters çevrilmiş dizi elde edilir. Birinci yolda $k$'ya değer verilip kaydırılmış kopyalar toplanıyordu; burada $n$'ye değer verilerek aynı işlem yapılıyor. Öğrenci, önceki hafta sürekli zamanda aynı işlemin $t$ ve $\tau$ değişkenleriyle yapıldığını hatırlattı; hoca yalnız değişken adlarının farklı olduğunu onayladı.

## 12. MATLAB ile Konvolüsyon ve Programlama Alıştırması

### 12.1 Programda indis sorunu

Hoca öğrencilerden kaydırma yöntemini kendi fonksiyonları olarak (örneğin `myconv`) yazmalarını istedi: fonksiyon $x$ dizisini ve $h$ dizisini alacak, $y$ dizisini döndürecek. Bunu programla yapmanın zorluğu şudur: $x$ için yalnız $[1,\ 2,\ 0,\ -1]$, $h$ için $[3,\ 2,\ 1]$ girilirse eksik bir bilgi kalır.

**Soru (hocanın sorusu):** $y$'yi düzgün çizmek istiyorsak burada eksik olan nedir? **Cevap (bir öğrenci):** İndisler tutulmuyor. Hoca bunu onayladı: başlangıç ve bitiş indisleri de ($M_x, N_x$ ve $M_h, N_h$; burada $[-1,\ 2]$ ve $[0,\ 2]$) fonksiyona verilmelidir.

### 12.2 MATLAB'de doğru indislerle çizim

Hoca MATLAB Online'da şunu gösterdi (ekrandan, 02:05:00):

```matlab
x = [1 2 0 -1];
stem(x)          % indisleri 1'den başlatır, istenen bu değil
n = -1:2;        % başlangıç -1, birer artarak 2'ye kadar
stem(n, x)       % indisler doğru: -1, 0, 1, 2
```

Yalnız `stem(x)` yazıldığında dizi 1, 2, 3, 4 indislerinde çizilir. `n=-1:2` ile indis vektörü kurulup `stem(n,x)` yazıldığında çizim $-1$'den başlar. Grafikleri tek pencerede dört parçaya bölmek için MATLAB'de de Python'da da `subplot` komutu kullanılabilir.

Sonra hazır fonksiyonla konvolüsyon alındı:

```matlab
h = [3 2 1];
y = conv(x, h)   % 3 8 5 -1 -2 -1
```

`conv` derste çözülen örneğin aynısını verdi. Ama yalnız genlik değerlerini kullanır; çıkışın hangi indisler arasında olduğunu bilmez. Çıkışın $n=-1$ ile $4$ arasında olduğu bilindiği için çizim bu indislerle yapıldı ve grafik $-1$'den başlayıp 3, 8, 5, ... değerlerini gösterdi.
<!-- BELİRSİZ: Çıkış için kurulan indis vektörünün komutu karede görünmüyor; büyük olasılıkla ny = -1:4 ve stem(ny, y) yazıldı. -->

Bir öğrenci MATLAB'in hazır konvolüsyon fonksiyonunun başlangıç ve bitiş indisi alıp almadığını sordu. Hoca `help conv` ile yardım metnine baktı: fonksiyon `shape` seçeneği alıyor ve sonuç vektörünün uzunluğu `length(a)+length(b)-1` oluyor, ama başlangıç indisi seçeneği yok. Yani indisleri kullanıcı kendisi hesaplamalıdır.

> **Ders sonrası not:** Altyazıda `conv` sonucu "3, 8, 5, eksi 1, eksi 2, eksi 4" diye geçiyor. Bu büyük olasılıkla yazıya dökme hatasıdır; doğru son değer $-1$'dir (python ile doğrulandı).

### 12.3 Alıştırmanın akademik içeriği

İstenen program şu adımları içerir:

- Giriş $x[n]$ ve dürtü yanıtı $h[n]$, başlangıç ve bitiş indisleriyle birlikte verilir.
- Bir grafik penceresi `subplot` ile dörde bölünür: $x[n]$, $h[n]$, kendi yazılan fonksiyonla bulunan $y[n]$ ve hazır `conv` fonksiyonuyla bulunan $y[n]$ doğru indislerle çizilir.
- İki $y[n]$'nin aynı olduğu gösterilir.
- Farklı başlangıç ve bitiş indislerine sahip, negatif ve pozitif indislerde elemanları bulunan (iki taraflı) üç farklı $x$ ve $h$ çifti denenir.

**Soru:** Sadece ikinci fonksiyonu ters çevirip $x$'in üzerinden mi geçiriyoruz? **Cevap:** Tam tersi de yapılabilir; biri sabit tutulur, diğeri ters çevrilip kaydırılır (değişme özelliği).

## 13. Sürekli ve Ayrık Konvolüsyonun Karşılaştırılması

Dersin sonunda hoca iki konvolüsyonu karşılaştırdı. Sürekli konvolüsyonda da aynı şey yapılıyordu: fonksiyonlardan biri ters çevrilir ve yavaş yavaş diğerinin üzerinden geçirilir. Örneğin $-1$'de başlayan bir dikdörtgenin üzerinden ters çevrilmiş bir dikdörtgen geçerken, ilk değdiği andan itibaren altta kalan alan artar; tamamen altına girdiğinde sabit kalır; çıkmaya başladığında giderek azalır (ekrandan, 02:15:00). Sonuç bir yamuk biçimidir.

Ayrık hâlde aynı işaretlerin örnekleri alınsaydı aynı yaklaşım görülecekti. Sürekli konvolüsyonda altta kalan alanlar integralle toplanır; ayrık konvolüsyonda ise ayrık değerlerin genlikleri çarpılıp toplanır, yani "ayrık altta kalan alanlar" bulunur.

## Örnek Sorular

### Soru 1: Fark denkleminin katsayıları

(ekrandan, 00:15:00)

$y[n]=y[n-1]+x[n]+\dfrac{x[n-1]}{2}$ sistemini $a_0y[n]+a_1y[n-1]=b_0x[n]+b_1x[n-1]$ biçiminde yazıp katsayıları bulun. Sistem hafızalı mıdır?

**Çözüm (derste verildi):** $y[n]-y[n-1]=x[n]+\frac{1}{2}x[n-1]$. Buradan $a_0=1$, $a_1=-1$, $b_0=1$, $b_1=1/2$. $y[n-1]$ ve $x[n-1]$ saklanması gerektiği için sistem hafızalıdır.

### Soru 2: İşareti dürtülerle yazma

(ekrandan, 00:35:00)

$x[-3]=-1$, $x[-2]=1$, $x[-1]=-0{,}5$, $x[0]=2$, $x[1]=1$, $x[2]=0{,}5$ değerlerini alan işareti ölçeklenmiş ve ötelenmiş dürtülerin toplamı olarak yazın.

**Çözüm (derste verildi):**

$$x[n]=-\delta[n+3]+\delta[n+2]-0{,}5\,\delta[n+1]+2\delta[n]+\delta[n-1]+0{,}5\,\delta[n-2]=\sum_k x[k]\,\delta[n-k]$$

### Soru 3: Slayttaki konvolüsyon toplamı

(ekrandan, 00:50:00)

$x[n]=2$ ($n=-1,0,1$), diğer yerlerde 0; $h[0]=1$, $h[1]=2$, diğer yerlerde 0. $y[n]=x[n]*h[n]$'yi bulun.

**Çözüm (derste verildi):** $h[-m]$ ters çevrilip kaydırılır. $y[-1]=2\cdot1=2$, $y[0]=2\cdot2+2\cdot1=6$, $y[1]=2\cdot2+2\cdot1=6$, $y[2]=2\cdot2=4$. Kontrol: uzunluk $3+2-1=4$, sınırlar $[-1+0,\ 1+1]=[-1,\ 2]$ (python `numpy.convolve` ile doğrulandı).

### Soru 4: İki yöntemle konvolüsyon

(ekrandan, 01:25:00)

$x[n]=[1,\ 2,\ 0,\ -1]$ ($n=-1,\dots,2$) ve $h[n]=[3,\ 2,\ 1]$ ($n=0,1,2$) için $y[n]$'nin uzunluğunu ve sınırlarını bulun; sonra $y[n]$'yi hem formülle hem kaydırma yöntemiyle hesaplayın.

**Çözüm (derste verildi):** $L_y=4+3-1=6$, $[M_y,N_y]=[-1,\ 4]$. Her iki yöntemle (10. ve 11. bölümler) $y[n]=[3,\ 8,\ 5,\ -1,\ -2,\ -1]$, $n=-1,\dots,4$ (ekrandan, 02:00:00). MATLAB'de `conv([1 2 0 -1],[3 2 1])` aynı genlikleri verir (python ile doğrulandı).

### Soru 5: Kendi konvolüsyon fonksiyonunu yazma

(derste sözlü, 02:00:46)

Kaydırma yöntemini, başlangıç indislerini de alan bir fonksiyon olarak yazın; sonucu hazır konvolüsyon fonksiyonuyla karşılaştırın ve negatif ile pozitif indisli farklı örneklerle deneyin.

> **Çözüm (derste verilmedi):** Aşağıdaki Python fonksiyonu ajan tarafından yazıldı ve test edildi; derste yazılmadı. `nx0` ve `nh0` dizilerin ilk elemanlarının indisleridir. Her çıkış indisi $n$ için $\sum_k x[k]h[n-k]$ yalnız iki dizinin çakıştığı indislerde hesaplanır.

```python
import numpy as np

def myconv(x, nx0, h, nh0):
    Lx, Lh = len(x), len(h)
    Ly = Lx + Lh - 1                 # uzunluk kuralı
    ny0 = nx0 + nh0                  # başlangıç indisi kuralı
    y = [0.0] * Ly
    for i in range(Ly):
        n = ny0 + i
        s = 0.0
        for j in range(Lx):
            k = nx0 + j              # x[k]
            m = n - k                # h[n-k]
            if nh0 <= m <= nh0 + Lh - 1:
                s += x[j] * h[m - nh0]
        y[i] = s
    ny = list(range(ny0, ny0 + Ly))
    return y, ny

y, ny = myconv([1, 2, 0, -1], -1, [3, 2, 1], 0)
print(ny, y)                                  # [-1..4] [3, 8, 5, -1, -2, -1]
print(np.convolve([1, 2, 0, -1], [3, 2, 1]))  # [ 3  8  5 -1 -2 -1]
```

> Test çıktısı: Soru 4 için $[3,8,5,-1,-2,-1]$ ($n=-1..4$), Soru 3 için $[2,6,6,4]$ ($n=-1..2$); ikisi de `numpy.convolve` ile aynıdır. Çizim için `matplotlib.pyplot.subplot` ile dört parça açılıp `stem(nx, x)`, `stem(nh, h)`, `stem(ny, y)` ve hazır fonksiyonun sonucu aynı `ny` ile çizilebilir.

## Dersin Toparlaması

Bu derste ayrık zamanlı LTI sistemlerde konvolüsyon kuruldu. Ayrık birim dürtü ve dürtü yanıtı $h[n]$ tanımlandı; nedensel bir sistemde $h[n]$'nin $n<0$ için sıfır olduğu ve $n>0$'da fark denkleminin homojen çözümü olduğu görüldü. Her işaretin ölçeklenmiş ve ötelenmiş dürtülerin toplamı olduğu gösterildi. Zamanla değişmezlik, ölçeklenebilirlik ve toplamsallık birlikte kullanılarak $y[n]=\sum_k x[k]h[n-k]$ konvolüsyon toplamı türetildi. Konvolüsyonun özellikleri, kararlılık koşulu $\sum|h[n]|<\infty$, kaskat ($h_1*h_2$) ve paralel ($h_1+h_2$) bağlantılar ele alındı.

Sonlu dizilerde sonucun uzunluğu $L_x+L_h-1$, sınırları $[M_x+M_h,\ N_x+N_h]$ olarak bulundu. Aynı örnek hem formülle (kaydırılmış dürtü yanıtlarını toplayarak) hem kaydırma yöntemiyle (ters çevrilmiş dürtü yanıtını kaydırıp çakışan değerleri çarparak) çözüldü ve MATLAB'deki `conv` fonksiyonuyla doğrulandı; hazır fonksiyonun indis bilgisi vermediği, indislerin ayrıca hesaplanması gerektiği vurgulandı. Hoca, bu dersle sürekli ve ayrık konvolüsyonun tamamlandığını ve sonraki adımda işaretlerin frekans domeninde işlenmesine geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
