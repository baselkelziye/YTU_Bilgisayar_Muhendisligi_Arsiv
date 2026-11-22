# Ders 4 Genişletilmiş Notu: İşaret İşlemleri Tekrarı, Enerji-Güç ve Temel İşaretler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Tekrarı: Sürekli ve Ayrık İşaretler, Sistemler
- 2. İşaretler Üzerinde İşlemler
- 3. İşlemlerin Sırası
- 4. Periyodik İşaretler
- 5. Karmaşık Sayılar ve Euler Eşitliği
- 6. İşaretin Enerjisi ve Gücü
- 7. Sinüzoidal İşaretler
- 8. Karmaşık Sinüzoitler
- 9. Üstel İşaretler ve Sönümlü Sinüzoitler
- 10. Ara Konu: Sayı Kümeleri
- 11. Karmaşık Üstel İşaretler
- 12. Temel İşaretler: Basamak, Dikdörtgen, Rampa, Üçgen
- 13. Temel İşaretlerden Karmaşık İşaret Kurmak: Doppler Darbe Dizisi
- 14. Birim Dürtü (Delta) Fonksiyonu ve Özellikleri
- 15. Dürtülerin İntegrali ve Süreksiz Fonksiyonların Türevi
- Örnek Sorular

## 1. Önceki Dersin Tekrarı: Sürekli ve Ayrık İşaretler, Sistemler

Ders, önceki haftanın kısa bir tekrarıyla başladı. Kullanılan slayt dizisi "Signals and Systems Properties" başlığını taşıyor ve önce sürekli ve ayrık zamanlı işaretleri karşılaştırıyor (ekrandan, 00:05:00). Sürekli işaretler zamanın fonksiyonudur ve belli bir (belki sonsuz) aralıktaki her an için değer alır. Ayrık işaretler ise yalnız ayrık zaman noktalarında, yani $1, 2, 3, \dots$ gibi tam sayı indislerde değer alır. Slaytta ayrıca işaretlerin uzayın (görüntü) ya da uzay ve zamanın (video) fonksiyonu olabileceği, her boyutta sürekli ya da ayrık olabileceği yazıyor.

> **Hocanın vurgusu:** Ders boyunca sürekli fonksiyonlar normal parantezle ($x(t)$), ayrık işaretler köşeli parantezle ($x[n]$) yazılacak; bu ayrıma dikkat edilmeli.

Sürekli bir işaretten ayrık (sayısal) işarete geçerken iki tür ayrıklaştırma yapılır. Birincisi zamanda ayrıklaştırmadır; buna örnekleme (sampling) denir. İkincisi seviyelerin ayrıklaştırılmasıdır: sürekli işaret sonsuz sayıda genlik değeri alabildiği için bu değerler belli seviyelere indirilir; buna nicemleme (quantization) denir.

Sistem ise giriş işaretini ($x(t)$ ya da $x[n]$) alıp bir çıkış işaretine, çıkış fonksiyonuna ya da çıkış dizisine dönüştüren yapıdır. Hoca sistemi daha çok $T$ (transform, dönüşüm) ile gösterdiklerini, ayrık sistemlerde arka planda çeşitli matematiksel işlemlerin ve algoritmaların çalışabileceğini hatırlattı.

## 2. İşaretler Üzerinde İşlemler

### 2.1 Genlik Ölçekleme

İlk işlem genlik ölçeklemedir (amplitude scaling). Bir işaret bir skalerle çarpıldığında her noktadaki değeri o oranda değişir. Bu hem sürekli hem ayrık işaretler için geçerlidir.

### 2.2 Zamanda Ölçekleme

Zamanda ölçeklemede işaretin argümanı bir sabitle çarpılır: $x(at)$. İki durum vardır:

- $a>1$ ise işaret daralır, sıkışır (compress). Örneğin $x(2t)$'de $t=1$ konunca $x(2)$ değeri elde edilir; yani normalde $t=2$'de olan değer artık $t=1$'de görünür.
- $0<a<1$ ise işaret yayılır. $x(t/2)$'de normalde $t=2$'de olan değer artık $t=4$'te görünür.

Hoca bu işlemlerin yalnız argümana değer koyarak anlaşılabileceğini vurguladı.

Ayrık zamanda $a>1$ durumu (slayttaki genel hali $x[nk]$, $k$ tam sayı) her $k$'ıncı örneği alır; ara örnekler kaybolur ve dizi kısalır. Buna alt örnekleme ya da azaltım (downsampling, decimation) denir (ekrandan, 00:10:00). Örneğin $y[n]=x[2n]$'de $n=0$ için $x[0]$, $n=1$ için $x[2]$ alınır; $x[1]$ atlanır.

Ayrık zamanda $0<a<1$ durumunda, örneğin $x[n/2]$'de, $n=0$ için $x[0]$ alınır; $n=1$ için $x[1/2]$ gerekir ama ayrık işaret yarım indiste tanımlı değildir. Bu örneklerin yerine 0 konur ya da önceki ve sonraki örneğin ara değeri yerleştirilir. Bu işleme üst örnekleme ya da interpolasyon (ara değerleme) denir.

### 2.3 Zamanda Ters Çevirme

Üçüncü işlem zamanda ters çevirmedir (time reversal): $x(-t)$ ya da $x[-n]$. İşaret düşey eksene göre yansır. Ayrık durumda örnekler yer değiştirir: örneğin $n=1$ konunca $x[-1]$ elde edilir, yani $-1$'deki değer $1$'e taşınır.

### 2.4 Zamanda Öteleme

Dördüncü işlem zamanda ötelemedir (time shifting). Sürekli durumda $x(t-t_1)$ yazılır; $t_1$ ötelemenin miktarını veren bir skalerdir. $t_1>0$ ise bu geciktirilmiş (delayed) işarettir; $x(t+t_1)$ ise ilerlemiş (advanced) işarettir.

Hoca bunu bir akış gibi düşünmeyi önerdi: ortada şu anki işaret $x(t)$ var; $x(t-1)$ daha sonra gerçekleşecek, gecikmiş durumdur; $x(t+1)$ ise ileriki durumdur. Zaman bir yöne doğru akıyormuş gibi düşünülebilir.

Ayrık zamanda aynı adlandırma geçerlidir: $n_1>0$ tam sayısı için $x[n-n_1]$ gecikmiş, $x[n+n_1]$ ilerlemiş işarettir. Gecikme ya da ilerleme tam sayı sayıda örnek kadardır (ekrandan, 00:15:00). Örneğin $x[n-1]$'de $n=1$ konunca $x[0]$ elde edilir; yani $x[n]$'in $0$'daki değeri artık $1$'de görülür ve işaret bir birim sağa kayar. Slayttaki soru "$n-n_1$ nerede sıfır olur?" sorusudur; işaretin başlangıç noktası bu soruyla bulunur.

## 3. İşlemlerin Sırası

Zamanda ölçekleme, öteleme ve ters çevirme tek bir işlemde birleştirilebilir. Slayta göre işlemler herhangi bir sırayla yapılabilir ama dikkat gerekir ve bu karışıklığa yol açar (ekrandan, 00:30:00).

> **Hocanın vurgusu:** Ölçekleme, öteleme ve ters çevirme işlemlerinin sırası önemlidir; işaret üzerinde yapılan işlemler sıra bağımlıdır ve hangisinin önce uygulandığı sonucu değiştirir.

### 3.1 Örnek: $x(2(t-1))$

Slayttaki $x(t)$, $t=0$'da tepe değeri 2 olan ve yaklaşık $[-1,1]$ aralığında tanımlı bir tümsektir (ekrandan, 00:30:00). İstenen işaret $x(2(t-1))$'dir.

- **Önce ölçekle, sonra ötele (doğru):** Önce 2 ile sıkıştırılır: $x(2t)$ tümseği $[-1/2,1/2]$ aralığına daralır. Sonra 1 birim ötelenir: tümsek $t=1$ civarına gelir (ekrandan, 00:30:00).
- **Önce 1 ötele, sonra 2 ile sıkıştır (yanlış):** Önce $x(t-1)$ alınır, tümsek $t=1$'e gelir. Sonra 2 ile sıkıştırılınca tümsek orijine doğru çekilir ve $t=1/2$ civarına gelir. Slaytta bu "Incorrect" diye işaretli (ekrandan, 00:25:00).
- **Önce ötele, sonra ölçekle (doğru yol):** İfade açılır: $x(2(t-1))=x(2t-2)$. Önce 2 birim ötelenir ($x(t-2)$, tümsek $t=2$'de), sonra 2 ile sıkıştırılır ve tümsek $t=1$'e gelir. Slaytta bu "Correct" diye işaretli ve "$2(t-1)$ nerede sıfır olur?" sorusu soruluyor (ekrandan, 00:25:00).

Hoca, açılmış ifadede ana değişkenin önündeki katsayının sıkıştırma katsayısını, sabit terimin ($-2$) öteleme miktarını gösterdiğini söyledi.

### 3.2 Değer Koyarak Sağlama

Bir öğrenci, öteleme ve ölçekleme birlikte yapıldığında sıkışmanın tepe noktasına göre değil de başka bir noktaya göre mi olduğunu sordu. Hoca bunun üzerine $x(2t-2)$'yi değer koyarak çizdi:

- $t=0$: argüman $2\cdot0-2=-2$; $x(-2)=0$.
- $t=1/2$: argüman $-1$; değer yaklaşık 0.
- $t=3/4$: argüman $2\cdot\frac34-2=\frac32-2=-\frac12$; yani $x(-1/2)$ değeri gelir.
- $t=1$: argüman 0; $x(0)=2$, tepe değeri.
- $t=3/2$: argüman 1; değer yaklaşık 0.
- $t=2$: argüman 2; $x(2)=0$.

Bu değerler tümseğin $t=1$ civarında, $[1/2, 3/2]$ aralığına sıkışmış olarak durduğunu gösterir. Önce 1 öteleyip sonra 2 ile sıkıştırarak bulunan işaret bundan farklıdır; yani o yol işaretin niteliğini değiştirir.

**Soru:** Öteleme ve ölçekleme birlikteyse sıkışma tepe noktasına göre değil de sıfır olan değerlere göre mi oluşuyor? **Cevap:** Hayır, öyle düşünülmemeli. İfadedeki katsayılara bakılır; sıkıştırma katsayısı ve öteleme miktarı doğru sırayla uygulanır. Emin olmak için argümana değerler verilerek işaret noktalarla çizilir.

Önceki hafta $x(t)$ verilip $x(t/2)$ ve $x(2t+2)$ gibi işaretlerin çizildiği alıştırmalar da yapılmıştı; hoca bunlara tekrar bakılmasını önerdi.

## 4. Periyodik İşaretler

Periyodik işaret, sinüs gibi kendini tekrar eden işarettir. $T_0$ kadar zaman sonra işaret kendini tekrar ediyorsa

$$x(t+T_0)=x(t)$$

yazılır. Yani hangi noktadan başlanırsa başlansın $T_0$ kadar ilerlenince aynı genlik değeri elde edilir. Aynı durum ayrık işaretler için de geçerlidir.

Slayttaki örnekte periyodu 1 olan bir işaret 1 birim ötelenince aynı işaret elde ediliyor (ekrandan, 00:20:00). Hoca burada yalnız $x(t+1)=x(t)$ demenin yetmeyeceğini, her $k$ tam sayısı için $x(t+k\cdot1)=x(t)$ yazılması gerektiğini belirtti; çünkü işaret $-\infty$'dan $+\infty$'a kadar kendini tekrar eder. En bilinen periyodik işaretler sinüs ve kosinüstür.

## 5. Karmaşık Sayılar ve Euler Eşitliği

Şimdiye kadar işaretler hep gerçel değerli (sürekli durumda) ya da tam sayı değerli (ayrık durumda) alınmıştı. Karmaşık bir işaret iki bileşenden oluşur. Karmaşık sayı $a+jb$ biçiminde yazılır; $a$ gerçel kısım, $b$ sanal (imajiner) kısım, $j=\sqrt{-1}$'dir. Mühendislik gösteriminde $j$, fizikte $i$ kullanılır. Karmaşık gösterim özellikle haberleşmede, radar, sonar ve ultrason gibi işaretin karmaşık ifade edilmesi gereken yerlerde kullanılır.

### 5.1 Kartezyen ve Kutupsal Gösterim

Gerçel sayılar tek bir eksen üzerinde gösterilir. Buna dik ikinci bir eksen (sanal eksen) eklenince sayılar düzlemde noktalara karşılık gelir. Bu düzlemdeki bir $z$ sayısı iki yolla tarif edilebilir (ekrandan, 00:35:00):

- **Kartezyen gösterim:** $z=a+jb$ (slaytta $z=x+jy$).
- **Kutupsal (polar) gösterim:** $z=re^{j\theta}$ (slaytta açı $\phi$ ile gösterilmiş). Burada $r$ merkezden uzaklık, $\theta$ gerçel eksenle yapılan açıdır.

Dönüşüm Pisagor bağıntısından gelir:

$$r=\sqrt{a^2+b^2},\qquad \theta=\arctan\frac{b}{a}.$$

$r$'ye $z$'nin modülü ya da genliği (modulus, magnitude), $\theta$'ya açısı ya da fazı (angle, phase) denir. İki gösterim düzlemde aynı noktayı verir.

> **Ek bilgi (derste anlatılmadı):** $\theta=\arctan(b/a)$ yalnız $a>0$ olduğunda doğrudan doğru açıyı verir. $a<0$ ise (ikinci ve üçüncü bölge) bulunan değere $\pi$ eklenmesi gerekir; programlama dillerindeki `atan2(b, a)` fonksiyonu bunu kendisi yapar.

### 5.2 Euler Eşitliği

> **Hocanın vurgusu:** Euler eşitliği bol bol kullanılacak; iyice öğrenilmeli.

$$e^{jx}=\cos x + j\sin x$$

Bu karmaşık bir sayıdır: $\cos x$ gerçel kısım ($a$), $\sin x$ sanal kısım ($b$) olur. Sinüs ve kosinüs $[-1,1]$ aralığında değer aldığı için bu sayı birim çember üzerinde, dört bölgeden birinde yer alır.

Slayttaki genelleme şöyledir (ekrandan, 00:35:00):

$$e^{z}=e^{x+jy}=e^{x}e^{jy}=e^{x}(\cos y + j\sin y).$$

Burada $e^{jy}$ Euler eşitliğiyle açılır, $e^{x}$ çarpan olarak başta kalır. Slayt ayrıca karmaşık sayılarda toplama, çarpma, bölme yapabilmenin ve iki gösterim arasında kolayca geçebilmenin gerektiğini yazıyor.

## 6. İşaretin Enerjisi ve Gücü

### 6.1 Dirençte Harcanan Enerjiden İşaret Enerjisine

Hoca tanımı bir direnç devresinden kurdu. Direnç $R$'den zamanla değişen bir $i(t)$ akımı geçsin. Ohm yasasına göre $V=i\cdot R$'dir. Dirençte harcanan enerji slaytta şöyle verilir (ekrandan, 00:40:00):

$$E_R=\lim_{T\to\infty}\int_{-T}^{T} i^2(t)\,R\,dt \quad \text{(Joule)}.$$

Tahtada $V\cdot i=(i\cdot R)\cdot i=i^2R$ adımı gösterildi.

**Soru:** Burada $P=iV$ deyip güç ile zamanı çarparak enerji bulunmuyor mu? **Cevap:** Hoca gücün biraz sonra ele alınacağını söyledi ve slayttaki formülün akımın karesinin zaman boyunca toplanmasıyla (integraliyle) enerjiyi verdiğini açıkladı.

> **Ders sonrası not:** Hoca tahtaya $E=V\cdot i=i^2R$ yazdı. $V\cdot i=i^2R$ anlık güçtür; enerji bu gücün zamana göre integralidir: $E=\int i^2(t)R\,dt$. Öğrencinin sorusu bu noktayı işaret ediyordu; slayttaki formül de integral biçimindedir.

İşaret enerjisi, $i(t)$'nin $1\,\Omega$'luk dirençte harcadığı enerji olarak tanımlanır:

$$E_i=\lim_{T\to\infty}\int_{-T}^{T} i^2(t)\,dt.$$

Akım yerine genel bir işaret $x(t)$ konur. İşaret karmaşık olabileceği için önemli olan genliğidir; bu yüzden karesi yerine mutlak değerinin karesi alınır:

$$E_x=\lim_{T\to\infty}\int_{-T}^{T} |x(t)|^2\,dt.$$

Slayt bunun çoğu uygulamada gerçek bir enerji olmadığını (çoğu işaret gerçekten $1\,\Omega$'luk bir dirence uygulanmaz), tanımsal olduğunu belirtiyor. Hoca, $R=1$ kabul edildiğini bir öğrencinin sorusu üzerine doğruladı.

### 6.2 Güç

Slayta göre işaret enerjisinin zaman içindeki ortalaması işaretin gücüdür (signal power). İşaret $[-T,T]$ aralığında düşünülürse toplam süre $2T$'dir; ortalama bu süreye bölünerek alınır:

$$P_x=\lim_{T\to\infty}\frac{1}{2T}\int_{-T}^{T}|x(t)|^2\,dt.$$

### 6.3 Enerji İşareti ve Güç İşareti

Slayttaki iki sonuç şunlardır (ekrandan, 00:45:00):

- **Enerji işaretinin gücü sıfırdır.** $E_x<\infty$ ise integral sonlu bir değerde kalır, $\frac{1}{2T}$ çarpanı ise $T\to\infty$ iken sıfıra gider; dolayısıyla $P_x=0$.
- **Güç işaretinin enerjisi sonsuzdur.** Enerji ifadesi $2T\cdot\frac{1}{2T}$ ile çarpılarak yazılırsa

$$E_x=\lim_{T\to\infty}2T\cdot\underbrace{\frac{1}{2T}\int_{-T}^{T}|x(t)|^2dt}_{\to P_x>0}=\infty.$$

Ortalama güç sıfırdan büyükse $2T\to\infty$ çarpanı enerjiyi sonsuz yapar.

Hoca bunların tanımsal şeyler olduğunu, bu şekilde bilinmesinin yeterli olacağını söyledi.

## 7. Sinüzoidal İşaretler

Bu kısımda artık işaret türleri tek tek tanınmaya başlandı. Sinüzoidal işaretin belli bir periyodu vardır ve periyot frekansın tersidir. Slayttaki tanım (ekrandan, 00:50:00):

$$x(t)=\cos(\omega t+\theta),\qquad x(t)=A\cos(2\pi f t+\theta).$$

Burada $A$ genlik, $\theta$ işaretin fazı, $f$ Hertz cinsinden frekans, $\omega=2\pi f$ ise radyan frekanstır (rad/s). Slayt, $\omega$'ya genellikle "frekans" dense de bunun aslında radyan frekans olduğunu, gerçek frekansın $f$ olduğunu hatırlatıyor. $2\pi$ sabit bir çarpandır; $f$ ile çarpılınca radyan frekans elde edilir.

Periyot şöyle bulunur: $\omega=2\pi f$'den $f=\omega/2\pi$ çekilir ve $T=1/f$'te yerine konur:

$$T=\frac{1}{f}=\frac{2\pi}{\omega}\quad\text{(saniye)}.$$

Faz, yani $\omega t$ dışında kalan $\theta$ terimi, işareti sağa ya da sola öteler; buna faz açısı denir.

### 7.1 Ayrık Zamanlı Sinüzoit

Ayrık duruma geçmek için sürekli işarette $t$ yerine $nT_s$ konur; işaret $T_s$ aralıklarla örneklenir (ekrandan, 00:55:00):

$$x(t)=A\cos(\omega t+\theta)\;\xrightarrow{t\to nT_s}\;x[n]=A\cos(\omega nT_s+\theta)=A\cos\left(\frac{\omega}{f_s}n+\theta\right).$$

$n$, $-N$'den $N$'ye tam sayı değerler alır. $nT_s$'deki $T_s$ silinir ve yalnız indis yazılır; çünkü indis kaç ise o kadar $T_s$ aralıkla örnek alındığı bilinir (örneğin $n=2$ noktası $2T_s$ anıdır). $T_s=1/f_s$ olduğu için

$$\Omega=\omega T_s=\frac{\omega}{f_s}$$

sayısal frekanstır. Ayrık domene geçince frekans kavramı değişir.

> **Hocanın vurgusu:** Analog frekans küçük omega ($\omega$), sayısal frekans büyük omega ($\Omega$) ile gösterilmeli ki ikisi birbirinden ayrılsın. Slayttaki $A\cos(\omega n+\varphi)$ yazımında aslında $A\cos(\Omega n+\varphi)$ yazılmalıydı.

Slayt metni ayrıca $n$ yalnız tam sayı değerler aldığı için ayrık sinüzoidin ancak $2\pi/\omega$ rasyonel bir sayı olduğunda periyodik olduğunu belirtiyor (ekrandan, 00:55:00).

## 8. Karmaşık Sinüzoitler

Aradan sonra ders karmaşık sinüzoitlerle devam etti. Hoca Euler eşitliğini tekrar yazdı: $e^{jx}=\cos x+j\sin x$; gerçel kısım $\cos x$, sanal kısım $\sin x$.

Karmaşık sinüzoit iki parçadan oluşur: gerçel kısımda kosinüslü normal ifade, sanal kısımda aynı ifadenin sinüslü hali (ekrandan, 01:10:00):

$$Ae^{j(\omega t+\theta)}=A\cos(\omega t+\theta)+jA\sin(\omega t+\theta).$$

Slayttaki $e^{j\omega t}$ grafiğinde düz çizgi gerçel kısmı (çift bir fonksiyon olan kosinüs), kesikli çizgi faz farkıyla giden sanal kısmı gösteriyor. Gerçel sinüzoit, karmaşık sinüzoidin gerçel kısmı olarak yazılabilir:

$$\Re\{Ae^{j(\omega t+\theta)}\}=A\cos(\omega t+\theta).$$

## 9. Üstel İşaretler ve Sönümlü Sinüzoitler

Hoca dersin akışını şöyle özetledi: hem sürekli hem ayrık domende işaretler vardır; önce normal sinüzoitler, sonra karmaşık sinüzoitler görüldü; şimdi üstel işaretler, ardından karmaşık üstel işaretler görülecek.

### 9.1 Üstel İşaretler

Sürekli zamanda üstel işaret (ekrandan, 01:15:00):

$$x(t)=e^{\sigma t}.$$

Hoca bunun $a^t$ biçiminde de yazılabileceğini söyledi.

- $\sigma<0$ ise üstel azalma (exponential decay) vardır. Örnek $e^{-t}$ ($\sigma=-1$): $t=0$'da 1, $t=1$'de $1/e\approx0{,}37$ değerini alır; zamanla azalır, büyük değerlerden gelip $+\infty$'da sıfıra varır.
- $\sigma>0$ ise üstel büyüme (exponential growth) vardır. Örnek $e^{t}$ ($e\approx2{,}7$): $t=0$'da 1, $t=-1$'de $1/e$ değerini alır; $-\infty$'da sıfıra yaklaşır, $+\infty$'da sonsuza gider.

"Decay" teriminin Türkçesi derste tartışıldı; zayıflama, azalma, sönümlenme gibi karşılıklar önerildi. "Growth" büyüme olarak çevrildi.

**Soru:** $\sigma$ bir sabit mi? **Cevap:** $\sigma$ fonksiyona atanan, işaretin verilişine göre değişen bir faktördür. Sıfırdan küçükse üstel azalma, sıfırdan büyükse üstel büyüme faktörü olarak adlandırılır.

### 9.2 Sönümlü ya da Büyüyen Sinüzoitler

Bir sinüzoit üstel bir işaretle çarpılırsa (ekrandan, 01:20:00):

$$x(t)=e^{\sigma t}\cos(\omega t+\theta).$$

Slayta göre bu, üstel büyümenin ($\sigma>0$) ya da azalmanın ($\sigma<0$) bir sinüzoitle modüle edilmesidir. Salınımı kosinüs verir; baştaki üstel çarpan salınımın büyümesine ya da sönümlenmesine neden olur. Grafikteki noktalı çizgiler bu üstel zarfı gösterir: $\sigma<0$ için genlik zamanla küçülür (sönümlü, damped), $\sigma>0$ için büyür (growing).

## 10. Ara Konu: Sayı Kümeleri

Hoca karmaşık üstel işaretlere geçmeden önce işaret ve sistemler dersinin mühendislikteki yerini anlattı. Bu ders temel matematiksel işaret gösterimlerini, işaret türlerini, bunların nasıl yorumlanıp adlandırılacağını öğretir. Bilgisayar mühendisliği öğrencileri bu konulara biraz uzak olsa da makine öğrenmesi, derin öğrenme, doğrusal cebirle yapılan işlemler ve değişkenlerin zamanla değiştiği her yerde işe yarar. Örneğin yapay zekâda nöronlar birbirine işaretler gönderir ve bu işaretler zamanla azalıp artar.

Ardından sayı kümeleri tekrar edildi. En temelde sayma sayıları vardır; sıfır eklenince doğal sayılar, negatif değerler eklenince tam sayılar elde edilir. Bunların üzerinde rasyonel ve irrasyonel sayılar, hepsini kapsayan küme olarak da gerçel (gerçek) sayılar vardır. Tahtadaki şemada gerçel sayılar rasyonel ve irrasyonel olarak ikiye ayrıldı (ekrandan, 01:25:00).

**Soru (hocanın sınıfa sorusu):** Rasyonel ve irrasyonel sayılar arasındaki fark nedir? $\pi$ rasyonel midir? **Cevap:** Bir öğrenci virgülden sonraki kısmı bilinmeyen sayılara irrasyonel dendiğini söyledi. Hoca $\pi$'nin $22/7$ diye yazılabileceğini öne sürerek sınıfı sınadı; doğru cevap, $22/7$'nin $\pi$'nin tam karşılığı değil yalnız yaklaşığı olduğudur. Rasyonel sayılar "rasyo" yani oran olarak, iki tam sayının bölümü biçiminde yazılabilen sayılardır ($1/2$, $10/3$, $-3/5$); böldüğünüzde virgülden sonra ne geleceği bilinir. İrrasyonel sayılar bu biçimde yazılamaz; virgülden sonraki kısım sonlanmaz ve nasıl gideceği bilinmez ($\pi$, $\sqrt{2}$, $\sqrt{5}$).

## 11. Karmaşık Üstel İşaretler

### 11.1 Tanım

Hoca önce sigma harfini tanıttı: küçük sigma $\sigma$, büyük sigma $\Sigma$, Yunan alfabesinde S harfine karşılık gelir. Karmaşık üstel işaret slaytta şöyle verilir (ekrandan, 01:25:00):

$$e^{(\sigma+j\omega)t+j\theta}=e^{\sigma t}\left(\cos(\omega t+\theta)+j\sin(\omega t+\theta)\right).$$

Slaytta sinüs teriminin önünde $i$ yazıyor; derste kullanılan gösterimle bu $j$'dir.

Hoca formülün nasıl kurulduğunu tahtada açtı (ekrandan, 01:35:00):

$$e^{\sigma t}\cdot e^{j(\omega t+\theta)}=e^{\sigma t}\cdot e^{j\omega t}\cdot e^{j\theta}=e^{(\sigma+j\omega)t}\cdot e^{j\theta}.$$

Yani bir karmaşık sinüzoit ($e^{j(\omega t+\theta)}$) üstel bir fonksiyonla ($e^{\sigma t}$) çarpılmıştır. Slayta göre bu, üstel büyüme ya da azalmanın bir karmaşık sinüzoitle modüle edilmesidir ve önceki bütün işaretleri özel durum olarak içerir.

**Soru:** Tahtada sağ tarafa mavi ile yazılan ifadede bir hata yok mu? **Cevap:** Hoca, açılımda yanlışlıkla iki üstel terimin arasına "artı" yazdığını, orada çarpım olması gerektiğini söyleyip düzeltti: $e^{\sigma t}\cdot e^{j(\omega t+\theta)}$.

$\theta$ belirli bir sabitse $e^{j\theta}=\cos\theta+j\sin\theta$ sabit bir karmaşık sayıdır. Bu yüzden zamanla değişen kısım $e^{(\sigma+j\omega)t}$'dir. Bu kısım hem gerçel hem sanal bileşene sahip bir işaret verir: $\cos\omega t$ ve $\sin\omega t$ salınımı oluşturur, $e^{\sigma t}$ ise bu salınımı azaltan ya da artıran çarpandır. Slayttaki grafiklerde düz çizgi gerçel kısmı, kesikli çizgi sanal kısmı, noktalı çizgi $e^{\sigma t}$ zarfını gösterir.

### 11.2 Karmaşık Frekans

$\sigma+j\omega$ ifadesine karmaşık frekans denir ve $s$ ile gösterilir:

$$s=\sigma+j\omega.$$

Hem gerçel ($\sigma$) hem sanal ($j\omega$) kısmı vardır. Yatay eksen $\sigma$, düşey eksen $j\omega$ olan düzlemde $\sigma>0$ bölgesi sağ tarafta, $\sigma<0$ bölgesi sol taraftadır. Sol tarafta azalan, sağ tarafta artan işaretler bulunur; yani $\sigma$, $\omega$ ile salınım yapan işareti artırır ya da azaltır.

Hoca bu kısımların öğrencilerin kendileri tarafından da tekrar gözden geçirilmesini istedi ve yararlanılabilecek bir ders kitabı olarak "DSP First" (Global Edition) kitabını gösterdi. Slaytların bu kitaptan alındığını, kitabın sinüzoitler ve daha sonra gelecek spektrum konusunu açıklamalı anlattığını, eklerinde karmaşık sayılar ve MATLAB ile ilgili güzel örnekler bulunduğunu söyledi.

## 12. Temel İşaretler: Basamak, Dikdörtgen, Rampa, Üçgen

Bu bölümde işaretleri tanımlarken kullanılan temel işaretler ele alındı.

### 12.1 Birim Basamak Fonksiyonu

Sürekli birim basamak fonksiyonu:

$$u(t)=\begin{cases}1, & t\ge0\\ 0, & t<0\end{cases}$$

Basamak biçiminde olduğu için bu adı alır; Heaviside basamak fonksiyonu da denir. Ayrık hali indise göre tanımlanır: $u[n]$, $n=0$'dan itibaren sağa doğru sonsuza kadar 1 değerini alır. Hoca slayttaki ayrık tanımda $t$ yerine $n$ yazılması gerektiğini belirtti.

Slayta göre basamak fonksiyonu başka işaretleri test etmek ve tanımlamak için yararlı bir araçtır. Örneğin $e^{-t}$ işareti $u(t)$ ile çarpılırsa işaretin yalnız $t\ge0$ kısmı kalır, negatif zaman kısmı silinir.

### 12.2 Basamakların Birleşimi: Ötelenmiş Dikdörtgen

Slayttaki örnek (ekrandan, 01:45:00):

$$x(t)=\begin{cases}0, & t>1\\ 1, & 0\le t<1\\ 0, & t<0\end{cases}\qquad\Longrightarrow\qquad x(t)=u(t)-u(t-1).$$

Hoca bunu iki basamağın grafikleri üzerinden açıkladı. $u(t-1)$'de $t-1=0$, yani $t=1$'den itibaren değer 1 olur. Çıkarma, $u(t-1)$'i ters çevirip ($-u(t-1)$) $u(t)$ ile toplamak demektir. $t\ge1$ için $1-1=0$ olur, iki işaret birbirini götürür. $0\le t<1$ için $1-0=1$ kalır. Sonuç, $[0,1)$ aralığında 1 olan kare (dikdörtgen) fonksiyondur. Hoca bu yolun parçalı (virgüllü) tanıma göre daha biçimsel bir gösterim olduğunu belirtti.

### 12.3 Birim Dikdörtgen

Birim dikdörtgen işaret $|t|<1/2$ için, yani $-1/2$ ile $1/2$ arasında 1, diğer yerlerde 0'dır. Genliği 1, genişliği 1 olduğu için alanı 1'dir.

> **Hocanın vurgusu:** Birim dikdörtgenin alanı 1 olacak; sınırların $\pm1/2$ seçilmesi bu yüzdendir.

### 12.4 Birim Rampa

$$r(t)=\begin{cases}t, & t\ge0\\ 0, & t<0\end{cases}$$

$t=0$'dan itibaren 45 derecelik eğimle artar. Slayta göre birim rampa birim basamağın integralidir:

$$r(t)=\int_{-\infty}^{t}u(\tau)\,d\tau.$$

Hoca bunu "integral altta kalan alanların toplamıdır" diye açıkladı: $-\infty$'dan $0$'a kadar altta kalan alan sıfırdır; sonra $t$ ilerledikçe her birim için 1 eklenir ($t=1$'de alan 1, $t=2$'de alan 2), böylece $t$ ile doğrusal artan rampa oluşur.

### 12.5 Birim Üçgen

Slayttaki tanım (ekrandan, 01:50:00):

$$\Delta(t)=\begin{cases}1-|t|, & |t|<1\\ 0, & \text{aksi halde}\end{cases}$$

Tepe noktası $t=0$'dadır ($1-0=1$). $|t|$ arttıkça değer 1'den çıkarıldığı için azalır ve $t=\pm1$'de sıfır olur. Alanı taban çarpı yükseklik bölü ikidir: $\frac{2\cdot1}{2}=1$. Birim üçgenin de alanı 1'dir.

## 13. Temel İşaretlerden Karmaşık İşaret Kurmak: Doppler Darbe Dizisi

Daha karmaşık işaretler bu temel işaretlerin birleşimiyle kurulur. Slayttaki örnek bir Doppler RF darbe işaretidir. İşaret beş sinüzoidal darbeden (atımdan) oluşur; her darbe $\tau$ süresince (hoca mikrosaniye mertebesinde dedi) süren bir kosinüs parçasıdır ve darbeler $T$ aralıkla tekrarlanır.

İşaret şu adımlarla kurulur (ekrandan, 01:55:00):

1. Birim dikdörtgen $\mathrm{rect}(t)$ alınır ve bir $A$ genliğiyle çarpılır.
2. Genişliği ayarlamak için $t$ yerine $t/\tau$ konur: $A\,\mathrm{rect}(t/\tau)$. Zamanda ölçeklemedeki gibi $\tau$ küçükse darbe sıkışır, büyükse genişler. Hoca bunu bölüm olarak yazmanın büyütme-küçültme karışmasın diye tercih edildiğini söyledi: örneğin $\tau=1/2$ ise argüman $2t$ olur ve darbe sıkışır, $\tau=2$ ise darbe genişler.
3. Ötelenmiş kopyalar oluşturulur ve toplanır:

$$\sum_{n=-2}^{2}A\,\mathrm{rect}\left(\frac{t-nT}{\tau}\right).$$

$n$ sırasıyla $-2,-1,0,1,2$ değerlerini alır ve $-2T,-T,0,T,2T$ merkezli beş dikdörtgen elde edilir. Slayta göre bu işaretin zarfıdır (envelope): işaret yalnız dikdörtgenlerin olduğu yerlerde var olacak, diğer yerlerde sıfır olacaktır.

4. Zarf, $\cos(\omega t)$ RF taşıyıcısıyla çarpılır. Sonuçta işaret yalnız darbe aralıklarında kosinüs salınımı olarak görünür:

$$x(t)=\left[\sum_{n=-2}^{2}A\,\mathrm{rect}\left(\frac{t-nT}{\tau}\right)\right]\cos(\omega t).$$

> **Ders sonrası not:** Hoca açıklama sırasında $1/\tau$ çarpanını da "$A$" diye adlandırdı (sıkıştırma katsayısı anlamında). Bu, slayttaki genlik $A$ ile karıştırılmamalıdır; slayttaki $A$ darbenin yüksekliği, $1/\tau$ ise argümandaki zaman ölçekleme katsayısıdır.

## 14. Birim Dürtü (Delta) Fonksiyonu ve Özellikleri

### 14.1 Tanım

Çok kullanılacak bir işaret delta fonksiyonu ya da Dirac fonksiyonudur; darbe fonksiyonu, dürtü işareti ya da impuls işareti de denir. Ayrık halde tanımlamak kolaydır ($n=0$'da 1, diğer yerlerde 0); sürekli halde ise o kadar kolay değildir, çünkü tam sıfırda değer alan, anlık oluşan bir işaret gerekir.

Tanım için çok küçük bir $\epsilon$ alınır: genişliği $\epsilon$, yüksekliği $1/\epsilon$ olan bir darbe düşünülür. Böylece

- $t=0$ anında çok büyük bir değer üretilir,
- diğer yerlerde değer sıfırdır,
- altta kalan alan $\epsilon\cdot\frac{1}{\epsilon}=1$'dir.

$\epsilon\to0$ limitinde bu darbe $\delta(t)$ olur; integrali 1'dir.

### 14.2 Fonksiyonla Çarpımın İntegrali

$\delta(t)$ yalnız $t=0$'da sıfırdan farklıdır. Bu yüzden herhangi bir $f(t)$ ile çarpılıp $-\infty$'dan $\infty$'a integrali alınınca yalnız $f$'in $t=0$'daki değeri kalır:

$$\int_{-\infty}^{\infty}f(t)\,\delta(t)\,dt=f(0).$$

**Ölçeklenmiş dürtüler (scaled impulses):** Dürtü bir $\alpha$ ile çarpılırsa yine yalnız $t=0$'da değer alır ve sonuç $\alpha$ ile çarpılır:

$$\int_{-\infty}^{\infty}f(t)\,\alpha\,\delta(t)\,dt=\alpha f(0).$$

Örneğin $2\delta(t)$, sıfırda 2 genlikli bir dürtüdür.

**Fonksiyonla çarpım:** Bir fonksiyon dürtüyle çarpılınca yalnız sıfırdaki değeri kalır:

$$f(t)\,\delta(t)=f(0)\,\delta(t).$$

Hoca, iki fonksiyon birbiriyle ve bir dürtüyle çarpılıyorsa yalnız sıfırdaki değerlerinin çarpılacağını ekledi.

### 14.3 Kaydırma (Sifting) Özelliği

$\delta(t-T)$, dürtünün $T$ kadar ötelenmiş halidir; $t-T=0$, yani $t=T$'de değer alır, diğer her yerde sıfırdır. Slayttaki özellik (ekrandan, 02:10:00):

$$\int_{-\infty}^{\infty}f(t)\,\delta(t-T)\,dt=f(T)\qquad(f,\ t=T\text{'de sürekli}).$$

Bir fonksiyonu $T$ anındaki bir dürtüyle çarpıp integral almak, $f(T)$ değerini çıkarır. Slayta göre bu özellik dersin ilerleyen bölümlerinde örneklemenin modellenmesinde önemli olacaktır.

### 14.4 İntegral Sınırları

İntegral aralığı dürtünün olduğu noktayı içermelidir:

- $a<0<b$ ise $\displaystyle\int_a^b\delta(t)\,dt=1$.
- $a>0$ ya da $b<0$ ise aralık sıfırı kapsamaz ve integral 0'dır.

Slayttaki örnekler (ekrandan, 02:15:00):

$$\int_{0^+}^{1}\delta(t)\,dt=0,\quad\int_{0^-}^{1}\delta(t)\,dt=1,\quad\int_{-1}^{0^-}\delta(t)\,dt=0,\quad\int_{-1}^{0^+}\delta(t)\,dt=1.$$

$0^-$, sıfırın hemen solu; $0^+$, sıfırın hemen sağıdır. Aralık sıfırı içinde barındırmıyorsa dürtü yakalanamaz.

**Soru:** Bir önceki slayttaki ikinci durum (sıfır çıkan durum) neyi anlatmak istiyor? **Cevap:** Koşul "$a>0$ veya $b<0$" biçimindedir. $a>0$ ise $0$, $a$ ve $b$'nin solunda kalır; aralık sıfırdan hiç geçmediği için dürtü yakalanamaz ve integral 0 olur. Örneğin $-1$ ile $0^-$ arasında da sıfır noktası içerilmez.

### 14.5 Örnek: Dürtü İçeren İntegral

Slayttaki örnek (ekrandan, 02:15:00):

$$\int_{-2}^{3}f(t)\left(2+\delta(t+1)-3\delta(t-1)+2\delta(t+3)\right)dt.$$

Hoca önce parantez içindeki işareti çizdi: 2 sabit değeri, $t=-1$'de genliği 1 olan dürtü, $t=1$'de genliği $-3$ olan dürtü ve $t=-3$'te genliği 2 olan dürtü. Sonra integral dört terime ayrıldı:

$$=2\int_{-2}^{3}f(t)\,dt+\int_{-2}^{3}f(t)\delta(t+1)\,dt-3\int_{-2}^{3}f(t)\delta(t-1)\,dt+2\int_{-2}^{3}f(t)\delta(t+3)\,dt.$$

- Birinci terim: $f$ bilinmediği için olduğu gibi kalır.
- İkinci terim: $\delta(t+1)$ $t=-1$'de değer alır; $-1$ sınırlar içinde olduğu için $f(-1)$ gelir.
- Üçüncü terim: $\delta(t-1)$ $t=1$'de değer alır; 1 sınırlar içinde olduğu için $-3f(1)$ gelir.
- Dördüncü terim: $\delta(t+3)$ yalnız $t=-3$'te değer alır; alt sınır $-2$ olduğu için bu nokta hiç kapsanmaz ve terim 0 olur.

$$=2\int_{-2}^{3}f(t)\,dt+f(-1)-3f(1).$$

(Ajan kontrolü: örneğin $f(t)=t^2+1$ için sol taraf ve sağ taraf ikisi de $88/3\approx29{,}33$ veriyor; numpy ile dürtüler dar Gauss darbeleriyle yaklaşık alınarak doğrulandı.)

## 15. Dürtülerin İntegrali ve Süreksiz Fonksiyonların Türevi

### 15.1 Dürtü İçeren İşaretin İntegrali

Slayttaki işaret:

$$x(t)=1+\delta(t-1)-2\delta(t-2).$$

Hoca önce çizdi: 1 sabit değeri (ofset), $t=1$'de genliği 1 olan yukarı dürtü, $t=2$'de genliği $-2$ olan aşağı dürtü. Ofset 1 olduğu için aşağı dürtünün çizimde $-1$ seviyesine kadar indiğini belirtti.

Sonra $y(t)=\int_0^t x(\tau)\,d\tau$ integrali, "altta kalan alanı tarayarak" adım adım bulundu (ara değerler numpy ile kontrol edildi):

- $0\le t<1$: yalnız sabit 1 integre edilir; $y(t)=t$. $t=1$'e gelindiğinde alan $1\times1=1$ olur.
- $t=1$: alanı 1 olan dürtü eklenir; $y$ 1'den 2'ye sıçrar.
- $1<t<2$: eğim yine 1'dir (45 derece); $y$ 2'den 3'e çıkar.
- $t=2$: alanı $-2$ olan dürtü eklenir; $y$ 3'ten 1'e düşer.
- $t>2$: eğim 1 ile devam eder.

Hoca, $t=2$'deki dürtü $-3$ olsaydı $y$'nin 3'ten 0'a ineceğini de ekledi. Kapalı biçimde $y(t)=t+u(t-1)-2u(t-2)$ ($t\ge0$) yazılabilir (ara adım eklendi).

### 15.2 Süreksiz Fonksiyonların Türevi

Slayta göre tersine, süreksiz bir fonksiyonun türevi her sıçrama noktasında bir dürtü içerir (ekrandan, 02:20:00). Örneğin birim basamak $u(t)$'nin türevi $\delta(t)$'dir.

Yukarıdaki $y(t)$'nin türevi alınırsa: doğrusal kısımlarda eğim 1 olduğu için türev 1'dir; $t=1$'deki 1 birimlik yukarı sıçrama 1 genlikli bir dürtü, $t=2$'deki 2 birimlik aşağı sıçrama $-2$ genlikli bir dürtü verir:

$$y'(t)=1+\delta(t-1)-2\delta(t-2).$$

Bu tam olarak başlangıçtaki $x(t)$'dir. Sabit 1 terimi ofseti verir; ofset 0 olsaydı yalnız dürtüler kalırdı.

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00): Ayrık zamanlı bir $x[n]$ ve $n_1>0$ tam sayısı için $x[n-n_1]$ işaretinde $n-n_1$ nerede sıfır olur?

> **Çözüm:** $n=n_1$'de. Yani $x[n]$'in $n=0$'daki değeri $x[n-n_1]$'de $n=n_1$'e taşınır; işaret $n_1$ örnek sağa kayar (gecikir). Derste $x[n-1]$ için $n=1$ konunca $x[0]$ elde edildiği gösterildi.

**Soru 2** (ekrandan, 00:25:00): $x(2(t-1))$ işaretinde $2(t-1)$ nerede sıfır olur? Önce ötele sonra ölçekle yoluyla doğru çizim nasıl yapılır?

> **Çözüm:** $2(t-1)=0 \Rightarrow t=1$; $x(t)$'nin $t=0$'daki tepe değeri yeni işarette $t=1$'e gelir. İfade $x(2t-2)$ diye açılır; önce 2 birim ötelenir ($x(t-2)$), sonra 2 ile sıkıştırılır. Önce 1 öteleyip sonra 2 ile sıkıştırmak tepeyi $t=1/2$'ye götürür ve yanlıştır.

**Soru 3** (derste sözlü, 00:25:10): $x(2t-2)$ işaretini $t$'ye değer vererek çizin.

> **Çözüm:** $t=0 \to x(-2)=0$; $t=1/2 \to x(-1)\approx0$; $t=3/4 \to x(-1/2)$; $t=1 \to x(0)=2$; $t=3/2 \to x(1)\approx0$; $t=2 \to x(2)=0$. Tümsek $t=1$ merkezli olarak $[1/2,3/2]$ aralığına sıkışır.

**Soru 4** (derste sözlü, 01:23:46): Rasyonel ve irrasyonel sayılar arasındaki fark nedir? $\pi=22/7$ yazılabildiğine göre $\pi$ rasyonel midir?

> **Çözüm:** Rasyonel sayı iki tam sayının oranı olarak yazılabilen sayıdır; irrasyonel sayı bu biçimde yazılamaz, ondalık açılımı sonlanmaz ve nasıl gideceği bilinmez. $22/7\approx3{,}1429$, $\pi\approx3{,}1416$'nın yalnız yaklaşığıdır; $\pi$ irrasyoneldir.

**Soru 5** (ekrandan, 01:45:00): $0\le t<1$ aralığında 1, diğer yerlerde 0 olan ötelenmiş dikdörtgen işareti birim basamaklar cinsinden yazın.

> **Çözüm:** $x(t)=u(t)-u(t-1)$. $t<0$'da iki terim de 0; $0\le t<1$'de $1-0=1$; $t\ge1$'de $1-1=0$.

**Soru 6** (ekrandan, 02:15:00): $\displaystyle\int_{0^+}^{1}\delta(t)dt$, $\int_{0^-}^{1}\delta(t)dt$, $\int_{-1}^{0^-}\delta(t)dt$ ve $\int_{-1}^{0^+}\delta(t)dt$ integrallerini bulun.

> **Çözüm:** Sırasıyla $0, 1, 0, 1$. Aralık $t=0$ noktasını içeriyorsa sonuç 1, içermiyorsa 0'dır.

**Soru 7** (ekrandan, 02:15:00): $\displaystyle\int_{-2}^{3}f(t)\left(2+\delta(t+1)-3\delta(t-1)+2\delta(t+3)\right)dt$ integralini hesaplayın.

> **Çözüm:** $2\int_{-2}^{3}f(t)\,dt+f(-1)-3f(1)$. $\delta(t+3)$ terimi $t=-3$'te olduğu ve bu nokta $[-2,3]$ dışında kaldığı için sıfır verir.

**Soru 8** (derste sözlü, 02:17:24; ekrandan, 02:20:00): $x(t)=1+\delta(t-1)-2\delta(t-2)$ için $y(t)=\int_0^t x(\tau)d\tau$ işaretini çizin; $y'(t)$ nedir?

> **Çözüm:** $y(t)=t+u(t-1)-2u(t-2)$ ($t\ge0$): $t=1^-$'de 1, $t=1^+$'da 2, $t=2^-$'de 3, $t=2^+$'da 1, sonra eğim 1 ile artar. $y'(t)=1+\delta(t-1)-2\delta(t-2)=x(t)$.

## Dersin Toparlaması

Bu derste önce önceki haftanın işaret işlemleri (genlik ölçekleme, zamanda ölçekleme, ters çevirme, öteleme) tekrar edildi ve bu işlemlerin sırasının sonucu değiştirdiği $x(2(t-1))$ örneğiyle, değer koyarak sağlama yapılarak gösterildi. Ardından periyodik işaretler, karmaşık sayıların kartezyen ve kutupsal gösterimi, Euler eşitliği, işaret enerjisi ve gücü tanımları ile enerji işareti-güç işareti ayrımı ele alındı. Sinüzoitlerde radyan frekans ve Hertz cinsinden frekans ayrıldı, ayrık sinüzoitte $\Omega=\omega/f_s$ sayısal frekansı tanıtıldı.

Dersin ikinci yarısında işaret türleri sırasıyla kuruldu: karmaşık sinüzoit, üstel işaret, sönümlü ya da büyüyen sinüzoit ve hepsini özel durum olarak içeren karmaşık üstel işaret; $s=\sigma+j\omega$ karmaşık frekansı tanıtıldı. Son olarak birim basamak, dikdörtgen, rampa ve üçgen işaretleri, bunlardan Doppler darbe dizisinin kurulması ve birim dürtünün özellikleri (kaydırma özelliği, integral sınırları, süreksiz fonksiyonların türevi) görüldü. Hoca kaydırma özelliğinin ileride örneklemenin modellenmesinde kullanılacağını ve DSP First kitabının takip edilmesini önerdi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
