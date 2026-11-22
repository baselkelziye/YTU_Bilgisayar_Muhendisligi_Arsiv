# Ders 10 Genişletilmiş Notu: Fourier Serileri ve Sürekli Zamanlı Fourier Dönüşümü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kaynaklar ve dersin yol haritası
- 2. İmpulslardan sinüzoidlere: Fourier fikrinin tekrarı
- 3. Periyodik işaret, temel periyot ve temel frekans
- 4. Karmaşık üstel Fourier serisi
- 5. Trigonometrik Fourier serisi ve harmonik form
- 6. Dirichlet koşulları, genlik ve faz spektrumu, Parseval teoremi
- 7. Fourier serisinden Fourier dönüşümüne
- 8. Fourier dönüşümünün özellikleri ve yaygın dönüşüm çiftleri
- 9. Frekans cevabı ve LTI sistemler
- 10. Soru çözümü öncesi tekrar: trigonometrik seri, simetri ve üstel seri
- Örnek Sorular
- Dersin Toparlaması

## 1. Kaynaklar ve dersin yol haritası

Önceki derste M. J. Roberts'ın slaytlarından Lecture 6'ya, yani sürekli zamanlı Fourier yöntemlerine giriş yapılmıştı. Ayrık zamanlı Fourier serisi ve analizi Lecture 7'dedir. Hoca bu slaytların giriş kısımlarını iyi bulduğunu, ama bazı yerlerde temel kavramları ispatlarıyla çok derinden anlattığını söyledi. Bu yüzden konuyu, kafada daha rahat oturması için Schaum serisinin Signals and Systems kitabından anlattı. Kitabın 5. bölümü (211. sayfadan itibaren) sürekli zamanda Fourier analizini, 6. bölümü ayrık zamanda Fourier analizini içerir (ekrandan, 00:35:00). Kitabın Türkçe çevirisi de vardır.

Dersin planı şuydu: önce sürekli zamandaki Fourier analizinin temel kavramları, sonra "Sorular 2, Fourier Serileri" dosyasından soru çözümü, ardından ayrık zamana geçiş. Süre yetmediği için ayrık zaman kısmı sonraki derse kaldı. Hoca ayrıca Fourier konusunu adım adım, uzun uzun anlatan bir video kaynağını da paylaştığını, takılınan ispat adımları için ona bakılabileceğini söyledi.

Hoca, sayısal işaret işleme dersinden farklı olarak bu derste işaret işlemenin temellerinin hem sürekli hem ayrık hâliyle, arka arkaya görüldüğünü hatırlattı: önce sürekli hâl, sonra ayrık hâl. Fourier analizinde de aynı sırayla ilerlenir.

## 2. İmpulslardan sinüzoidlere: Fourier fikrinin tekrarı

Sürekli zamanda $x(t)$ girişi $h(t)$ cevaplı sisteme girer ve $y(t)$ çıkışı elde edilir. Ayrık zamanda da $x[n]$, $h[n]$ ve $y[n]$ vardır. İmpulslarla anlatılan bölümde $h(t)$ ve $h[n]$'in sistemin birim impulsa verdiği cevaplar olduğu görülmüştü. Birim impulsa verilen cevap biliniyorsa, ölçeklenmiş ve kaydırılmış impulslardan oluşan her $x(t)$ ya da $x[n]$ için çıkış sürekli ve ayrık zamanda bulunabilir. Ödevde de ayrık bir örnek üzerinden impuls cevabı bulunmuştu.

Fourier yaklaşımında işaret artık impulsların toplamı olarak değil, onu oluşturan farklı frekanslardaki sinüzoidlerin toplamı olarak verilir. Her işaret, farklı genlik ve frekanslardaki sinüzoidlerden oluşur. Sinüzoid denince $\cos(\omega t+\phi)$ biçimi akla gelir. Karmaşık üstel denince $e^{j\omega t}$ anlaşılır; burada $\omega=2\pi f$'dir ve
$$e^{j\omega t}=\cos\omega t+j\sin\omega t$$
yazılır. Faz için $+\theta$ da eklenebilir, ama hoca kolaylık için yazmadı. Karmaşık üstelin gerçel kısmı kosinüs, sanal kısmı sinüs gibi ilerler. Örneğin $e^{j2\pi t}$ için $t=0$'da gerçel kısım 1'den başlar ve $t$ arttıkça bir tam çevrim tamamlanır. $e^{-j2\pi t}$ de 1'den başlar, ama ters yönde döner.

### 2.1 Üçgen dalga örneği

Slayttaki örnekte kesik çizgiyle gösterilen, 0 ile 1 arasında gidip gelen periyodik bir üçgen dalga, sinüzoidlerin toplamı olarak yaklaşıklanır. Frekans sıfırdan başlayarak artan değerlerde sonsuz sayıda sinüzoid toplanır:

- Sıfır frekanslı ilk bileşen işaretin ortalamasıdır, yani 0,5 değerinde düz bir çizgi. Buna DC bileşen denir. Tek bir bileşenle gösterilecekse üçgeni en iyi yaklaşıklayan budur.
- Sonra işaretin temel (fundamental) frekansına sahip sinüzoid eklenir. Toplam üçgene yaklaşır, ama yetmez.
- Temel frekansın 2 katı eklenince yaklaşım daha da iyileşir.
- Bu örneğe özel olarak 3 katı frekanstaki bileşenin genliği sıfırdır, yani üçgen dalgada bu harmonik yoktur. 4 katı ise eklenir.

Eklenen her frekans belli bir genlikle çarpılıp toplama katılır. Slayttaki gösterim
$$x(t)=\sum_{k=-\infty}^{\infty}c_x[k]\,e^{j2\pi kt/T}$$
biçimindedir; $c_x[k]$ harmonik fonksiyon, $k$ harmonik sayısıdır. Harmonik fonksiyon işaretten diklik (orthogonality) ilkesiyle bulunur (ekrandan, 00:25:00). Üstel açılınca $\cos2\pi kft+j\sin2\pi kft$ olur; $k$ değiştikçe frekans temel frekansın katları olan $f,2f,3f,\dots$ değerlerini alır. Sanal kısım akıl karıştırmamalıdır: bu, gösterimi genelleştirmek için kullanılan karmaşık üstelin açılmış hâlidir. Önemli olan, her sinüzoidal bileşenin bir katsayıyla çarpılıp toplama eklenmesidir.

Gerçekte bir işaret sonsuz frekans içermez. Belli sayıda frekans bileşeni vardır ve belli bir noktadan sonra katsayılar sıfıra iner. Önemli olan, işarete katkıda bulunan frekansların toplamıyla işaretin ifade edilebilmesidir.

## 3. Periyodik işaret, temel periyot ve temel frekans

Periyodik işaret kendini tekrar eden işarettir. Herhangi bir şekildeki bir temel parça $T$ periyoduyla $T,2T,3T,\dots$ ve $-T,-2T,\dots$ noktalarında her iki yönde tekrar eder:
$$x(t+T)=x(t).$$

Bu tekrarı sağlayan $T$ değerlerinin en küçük pozitif olanı temel periyot $T_0$'dır. Örneğin işaret 3 saniyede bir tekrar ediyorsa 6 saniyede bir de tekrar eder, ama temel periyot 3 saniyedir. Temel frekans ve temel açısal frekans şöyledir (ekrandan, 00:35:00):
$$f_0=\frac{1}{T_0},\qquad \omega_0=\frac{2\pi}{T_0}=2\pi f_0.$$
Karmaşık üstel işaret $x(t)=e^{j\omega_0 t}$ biçimindedir ve $\omega_0$'a temel açısal frekans denir.

Hoca, üçgen dalga örneğinde işareti yaklaşıklamak için kullanılan temel sinüzoidin periyodunun işaretin periyoduyla aynı olduğunu gösterdi. Üçgenler birbirinin ardından geldiği için işaretin periyodu $T$ ile temel bileşenin periyodu $T_0$ çakışır. Üçgenler ayrık örnekler gibi aralıklarla gelseydi, işaretin tekrar aralığı ile temel bileşenin periyodu farklı olabilirdi.

## 4. Karmaşık üstel Fourier serisi

Fourier serisi, periyodik bir işaretin içinde bulunan sinüzoidal, daha doğrusu karmaşık üstel bileşenlerin miktarını bulmayı sağlayan matematiksel yaklaşımdır. Fourier serisini bulmanın birkaç yolu vardır; ilki karmaşık üstel Fourier serisidir (ekrandan, 00:35:00):
$$x(t)=\sum_{k=-\infty}^{\infty}c_k\,e^{jk\omega_0 t},\qquad \omega_0=\frac{2\pi}{T_0}.$$

Hoca, bütün anlatılanların temelinin bu ifade olduğunu söyledi. $k$ tam sayı değerleri aldıkça ($\dots,-1,0,1,2,\dots$) frekans $k\omega_0$ olarak değişir. Her frekanstaki bileşenin işarete hangi genlikle katıldığını $c_k$ belirler. Örneğin $c_k=0$ ise o frekans işarette yoktur; üçgen dalga örneğinde $k=3$ için durum buydu. $c_k$'lara karmaşık Fourier katsayıları denir.

> **Hocanın vurgusu:** Bütün anlatımın temeli $x(t)=\sum c_ke^{jk\omega_0t}$ ifadesidir. $c_k$, o frekanstaki sinüzoidal bileşenin toplama ne kadar katıldığını gösterir.

### 4.1 Katsayıların bulunması

Katsayılar şu integralle bulunur (ekrandan, 00:40:00):
$$c_k=\frac{1}{T_0}\int_{T_0}x(t)\,e^{-jk\omega_0 t}\,dt.$$
İki farka dikkat edilmelidir. Sentez ifadesinde $e^{+jk\omega_0t}$ varken burada $e^{-jk\omega_0t}$ vardır. Ayrıca $c_k$ değerleri ayrık olduğu için sentezde toplam (sigma) kullanılırken, $x(t)$ sürekli olduğu için analizde integral kullanılır. $\int_{T_0}$ herhangi bir periyot boyunca integral demektir; genelde $0$–$T_0$ ya da $-T_0/2$–$T_0/2$ alınır.

$k=0$ konunca $e^{j0}=\cos0+j\sin0=1$ olur ve
$$c_0=\frac{1}{T_0}\int_{T_0}x(t)\,dt$$
kalır. Bu, işaretin bir periyot boyunca altındaki alanın $T_0$'a bölünmesi, yani bir periyottaki ortalamasıdır.

### 4.2 Gerçel işarette eşlenik simetrisi

$c_k$ içinde karmaşık üstel bulunduğu için katsayılar karmaşık sayıdır. $x(t)$ gerçel ise pozitif ve negatif indisler arasında şu ilişki vardır:
$$c_{-k}=c_k^*.$$
Karmaşık eşlenik yalnız sanal kısmın işaretini değiştirir: $z=a+jb$ ise $z^*=a-jb$'dir. Örneğin $c_1$ ile $c_{-1}$ birbirinin eşleniğidir. İkisinin mutlak değeri $\sqrt{a^2+b^2}$ olduğundan genlikleri eşittir; yalnız açıları farklıdır.

### 4.3 Karmaşık sayı hatırlatması

Hoca karmaşık düzlemi beyaz tahtada çizdi (ekrandan, 00:45:00). $z=a+jb$ sayısının gerçel eksendeki izdüşümü $a$, sanal eksendeki izdüşümü $b$'dir. Aynı nokta uzunluk ve açıyla da gösterilebilir:
$$|z|=r=\sqrt{a^2+b^2},\qquad \theta=\arctan\frac{b}{a},\qquad z=re^{j\theta}.$$
Eşleniğin açısı $\arctan(-b/a)$ olur; yani $c_k$ ile $c_{-k}$ birbirinin tersi olan açılar verir.

## 5. Trigonometrik Fourier serisi ve harmonik form

İkinci yaklaşımda yine $x(t)$ yazılır, ama karmaşık üsteller yerine bilinen kosinüs ve sinüs fonksiyonları kullanılır:
$$x(t)=\frac{a_0}{2}+\sum_{k=1}^{\infty}\left(a_k\cos k\omega_0t+b_k\sin k\omega_0t\right),$$
$$a_k=\frac{2}{T_0}\int_{T_0}x(t)\cos k\omega_0t\,dt,\qquad b_k=\frac{2}{T_0}\int_{T_0}x(t)\sin k\omega_0t\,dt.$$
$a_0/2$ ilk bileşendir. $k$ 1, 2, 3 değerlerini aldıkça frekans artar ve $x(t)$ farklı frekanslardaki kosinüs ve sinüslerle çarpılarak katsayılar bulunur.

### 5.1 İki seri arasındaki bağ

Karmaşık ve trigonometrik katsayılar birbirine dönüştürülebilir (ekrandan, 00:50:00):
$$\frac{a_0}{2}=c_0,\qquad a_k=c_k+c_{-k},\qquad b_k=j(c_k-c_{-k}),$$
$$c_k=\tfrac12(a_k-jb_k),\qquad c_{-k}=\tfrac12(a_k+jb_k).$$
$x(t)$ gerçel ise $a_k$ ve $b_k$ de gerçeldir, sanal kısımları yoktur ve
$$a_k=2\,\mathrm{Re}[c_k],\qquad b_k=-2\,\mathrm{Im}[c_k]$$
olur. Yani $c_k$ katsayıları bilinince trigonometrik gösterimdeki $a_k$ ve $b_k$'ya da ulaşılır.

> **Hocanın vurgusu:** Bu iki çözüm (karmaşık üstel ve trigonometrik seri) Fourier analizinde bilinmesi gereken temel kısımdır.

### 5.2 Çift ve tek işaretler

Çift fonksiyon kosinüs gibidir: $x$ kadar sağa ve $-x$ kadar sola gidildiğinde aynı değer alınır, $f(-x)=f(x)$. Tek fonksiyon sinüs gibidir: değerler genlikçe aynı, işaretçe terstir, $f(-x)=-f(x)$. Periyodik işaret çift ise sinüs bileşeni yoktur ($b_k=0$) ve seri yalnız kosinüs terimleri içerir:
$$x(t)=\frac{a_0}{2}+\sum_{k=1}^{\infty}a_k\cos k\omega_0t.$$
İşaret tek ise çiftliği oluşturan $a$ katsayıları yoktur, yalnız $b$ katsayıları kalır.

### 5.3 Harmonik form

Üçüncü bir açılım daha vardır; adı harmonik formdur:
$$x(t)=C_0+\sum_{k=1}^{\infty}C_k\cos(k\omega_0t-\theta_k).$$
Buradaki $C_0$ ve $C_k$, karmaşık serideki küçük $c_k$'lardan farklıdır. Faz bilgisi kosinüsün içine alınarak sinüs ve kosinüs tek bir terimde birleştirilir. $C_0$, $C_k$ ve $\theta_k$ trigonometrik katsayılardan ($a_0,a_k,b_k$) bulunur. Hoca bu forma ayrıntılı girmedi.

## 6. Dirichlet koşulları, genlik ve faz spektrumu, Parseval teoremi

### 6.1 Dirichlet koşulları

Periyodik bir $x(t)$'nin Fourier serisi açılımının olabilmesi için üç koşul aranır (ekrandan, 00:55:00):

- $x(t)$ herhangi bir periyotta mutlak integrallenebilir olmalıdır: $\int_{T_0}|x(t)|\,dt<\infty$.
- Her sonlu aralıkta sonlu sayıda maksimum ve minimum noktası olmalıdır.
- Her sonlu aralıkta sonlu sayıda süreksizlik olmalı ve her süreksizlik sonlu olmalıdır.

Slaytta bu koşulların Fourier serisi gösterimi için yeterli, ama gerekli olmadığı da yazılıdır. Hoca bu kısmın daha çok matematiksel içerikle ilgili olduğunu söyledi.

### 6.2 Genlik ve faz spektrumu

Karmaşık katsayılar genlik ve açıyla yazılabilir (ekrandan, 00:55:00):
$$c_k=|c_k|\,e^{j\phi_k}.$$
$|c_k|$'nın açısal frekans $\omega$'ya göre çizimine genlik spektrumu (amplitude spectrum), $\phi_k$'nın $\omega$'ya göre çizimine faz spektrumu denir. $k$ yalnız tam sayı değerleri aldığından çizimler $0,\omega_0,2\omega_0,3\omega_0,\dots$ noktalarında ayrık değerlerdir.

Gerçel işarette $c_{-k}=c_k^*$ olduğundan, $a-jb$ ile $a+jb$'nin mutlak değeri aynıdır ($\sqrt{a^2+b^2}$). Bu yüzden genlik spektrumu çift, faz spektrumu ($\phi_{-k}=-\phi_k$) tek fonksiyondur (ekrandan, 01:00:00). Hoca anlatırken önce faz için de "çift" dedi, sonra slayttaki ifadeyi okuyarak fazın tek olduğunu belirtti.

### 6.3 Periyodik işaretin gücü ve Parseval teoremi

Periyodik bir işaretin bir periyot boyunca ortalama gücü şöyle tanımlanır (ekrandan, 01:00:00):
$$P=\frac{1}{T_0}\int_{T_0}|x(t)|^2\,dt.$$
Mutlak değer, negatif kısımların da genlik olarak hesaba katılmasını sağlar; ayrıca $x(t)$ karmaşık da olabilir. $x(t)$ karmaşık üstel Fourier serisiyle gösterilirse
$$P=\frac{1}{T_0}\int_{T_0}|x(t)|^2\,dt=\sum_{k=-\infty}^{\infty}|c_k|^2$$
olur. Bu eşitliğe Parseval özdeşliği (Parseval teoremi) denir. Sol taraf zaman domeninde, sağ taraf frekans domeninde hesaplanır. Karmaşık üstellerin katsayılarının kareleri, işarette o sinüzoidlerden ne kadar bulunduğunu gösterir; iki domendeki toplamlar birbirine eşittir.

## 7. Fourier serisinden Fourier dönüşümüne

Asıl varılmak istenen yer Fourier dönüşümüdür: sürekli zamanda sürekli zamanlı Fourier dönüşümü (CTFT), ayrık zamanda ayrık zamanlı Fourier dönüşümü (DTFT). Fourier serileri periyodik fonksiyonlar için yazılır. Oysa incelenecek işaretler çoğu zaman periyodik değildir, belli aralıklarda değer alır. Bu yüzden matematiksel temel önce periyodik işaretlerin Fourier serisiyle kurulur, sonra bu temel periyodik olmayan işaretlere genişletilir. Amaç, işaretin frekans içeriğini bulmak ve sonsuz sayıdaki sinüzoide sistemin verdiği cevaplardan yararlanarak $y(t)$ (ayrık zamanda $y[n]$) çıkışını bulmaktır.

### 7.1 Periyodik genişletme

Periyodik olmayan, sonlu süreli bir işaret ele alınır (ekrandan, 01:15:00):
$$x(t)=0,\qquad |t|>T_1.$$
Slaytta bu işaret $-T_1$ ile $T_1$ arasında tanımlı bir üçgenle gösterilir. Bu temel işaret $T_0$ periyoduyla tekrarlanarak periyodik $x_{T_0}(t)$ elde edilir: $\dots,-T_0,0,T_0,2T_0,\dots$ Hoca, $T_1$ aralığının ve $T_0$ periyodunun farklı büyüklükler olduğuna dikkat çekti. $T_0$ sonsuza giderse tekrarlar uzaklaşır ve geriye yalnız $x(t)$ kalır. Böylece hem periyodiklikten gelen Fourier serisi kullanılır hem de sonuç tek bir $x(t)$ için üretilir.

### 7.2 Türetme adımları

$x_{T_0}(t)$, $-T_0/2<t<T_0/2$ aralığında $x(t)$'ye eşittir; Fourier serisi
$$x_{T_0}(t)=\sum_{k=-\infty}^{\infty}c_ke^{jk\omega_0t},\qquad \omega_0=\frac{2\pi}{T_0}$$
olur. Bir periyodun dışında $x(t)=0$ olduğundan katsayının integral sınırları sonsuza genişletilebilir (ekrandan, 01:15:00):
$$c_k=\frac{1}{T_0}\int_{-T_0/2}^{T_0/2}x(t)e^{-jk\omega_0t}dt=\frac{1}{T_0}\int_{-\infty}^{\infty}x(t)e^{-jk\omega_0t}dt.$$
Gösterimi sadeleştirmek için
$$X(\omega)=\int_{-\infty}^{\infty}x(t)e^{-j\omega t}dt$$
tanımlanır. $\omega$ yerine $k\omega_0$ konunca (ekrandan, 01:20:00)
$$c_k=\frac{1}{T_0}X(k\omega_0)$$
bulunur. Bu, seri ifadesinde yerine yazılır ve $1/T_0=\omega_0/2\pi$ kullanılırsa
$$x_{T_0}(t)=\frac{1}{2\pi}\sum_{k=-\infty}^{\infty}X(k\omega_0)e^{jk\omega_0t}\omega_0$$
elde edilir. $T_0\to\infty$ iken $\omega_0=2\pi/T_0$ sonsuz küçük (infinitesimal) olur, $\omega_0\to0$. Bu küçük adım $\Delta\omega$ diye yazılır:
$$x_{T_0}(t)\big|_{T_0\to\infty}\to\frac{1}{2\pi}\sum_{k=-\infty}^{\infty}X(k\Delta\omega)e^{jk\Delta\omega t}\Delta\omega.$$
$\Delta\omega$ sıfıra giderken $k\Delta\omega$, ekseni çok küçük adımlarla tarayan sürekli $\omega$ değişkenine dönüşür. Sağ taraf $X(\omega)e^{j\omega t}$ eğrisinin altındaki küçük şeritlerin toplamıdır ve limitte integral olur. Böylece $x(t)$'nin periyodik olmasına gerek kalmaz: $x(t)$, her frekanstaki bileşenin karmaşık üstelle çarpılıp $-\infty$'dan $\infty$'a bütün frekanslar üzerinden toplanması ve $2\pi$'ye bölünmesiyle elde edilir.

> **Ek bilgi (derste anlatılmadı):** Bu limit süreci, periyodik işaretin ayrık çizgi spektrumunun periyot büyüdükçe sıklaşarak sürekli bir spektruma dönüşmesi olarak da düşünülebilir. $T_0\,c_k$ çarpımı, çizgilerin zarfı olan $X(\omega)$'yı $k\omega_0$ noktalarında örnekler.

### 7.3 Fourier dönüşüm çifti ve spektrum

Varılan sonuç Fourier dönüşüm çiftidir (ekrandan, 01:25:00):
$$X(\omega)=\mathcal{F}\{x(t)\}=\int_{-\infty}^{\infty}x(t)e^{-j\omega t}dt,$$
$$x(t)=\mathcal{F}^{-1}\{X(\omega)\}=\frac{1}{2\pi}\int_{-\infty}^{\infty}X(\omega)e^{j\omega t}d\omega,$$
$$x(t)\leftrightarrow X(\omega).$$
Birinci ifade zaman domenindeki $x(t)$'yi alıp frekans katsayılarını üretir. İkinci ifade frekans domenindeki katsayılardan ters Fourier dönüşümüyle işareti geri elde eder; bu yüzden ikisine "çift" denir. Hoca tahtada zamanda bir işaret ve frekans ekseninde onun bileşenlerini gösteren bir çizim yaptı: küçük $x$'ten büyük $X$'e geçmek, zaman uzayından frekans uzayına geçmektir; $\omega$ frekanstır.

$X(\omega)$ içindeki $e^{-j\omega t}$ nedeniyle değerler genelde karmaşıktır ve şöyle yazılır:
$$X(\omega)=|X(\omega)|\,e^{j\phi(\omega)}.$$
$X(\omega)$, periyodik olmayan $x(t)$'nin frekans domenindeki tanımıdır ve $x(t)$'nin spektrumu (Fourier spektrumu) diye anılır. $|X(\omega)|$ genlik (magnitude) spektrumu, $\phi(\omega)$ faz spektrumudur. Genlik spektrumunda işaretin hangi frekanslarda ne kadar içerik taşıdığı görülür.

Fourier serisindeki gibi negatif frekanslardaki değerler pozitif frekanslardakilerin karmaşık eşleniğidir. Eşlenik olmak genlikleri bozmaz, yalnız fazların işareti terstir. Bu yüzden $|X(\omega)|$ çift, $\phi(\omega)$ tek fonksiyondur.

Hoca, bazı kitapların (Schaum gibi) Laplace ve Z dönüşümünü önce verip sonra konuların içine yerleştirdiğini, takip edilen M. J. Roberts kitabının ise Laplace ve Z dönüşümünü daha sonra verdiğini ve derste bu sıranın izlendiğini söyledi. Laplace dönüşümü sürekli zamanda, Z dönüşümü ayrık zamanda kullanılır.

## 8. Fourier dönüşümünün özellikleri ve yaygın dönüşüm çiftleri

Hoca, dersin başından beri serileri ve diğer konuları anlatırken hep sürekli zamanlı Fourier dönüşümüne doğru gelmeye çalıştığını söyledi. $X(\omega)$, işaretin frekans domenindeki bileşenlerini gösterir. Hangi frekansların işarette bulunduğu $|X(\omega)|$ çiziminden, faz içeriği $\phi(\omega)$'dan görülür.

### 8.1 Temel özellikler

- **Doğrusallık:** $a_1x_1(t)+a_2x_2(t)\leftrightarrow a_1X_1(\omega)+a_2X_2(\omega)$.
- **Zamanda kaydırma:** İşaret $t_0$ kadar kaydırılırsa dönüşüm karmaşık bir üstelle çarpılır: $x(t-t_0)\leftrightarrow e^{-j\omega t_0}X(\omega)$.
- **Frekansta kaydırma (karmaşık modülasyon):** Zaman domeninde karmaşık üstelle çarpmak, frekans domeninde $\omega_0$ kadar kaydırmaktır: $e^{j\omega_0t}x(t)\leftrightarrow X(\omega-\omega_0)$. Hoca bunu analog radyoyla örnekledi: radyo kanalları farklı frekans bantlarındadır. Konuşma gibi bir $x(t)$ işareti farklı bantlara kaydırılır; buna modülasyon denir ve temeli bu özelliktir.
- **Zamanda ölçekleme:** $x(at)\leftrightarrow\frac{1}{|a|}X\!\left(\frac{\omega}{a}\right)$; $1/|a|$ bir normalizasyon katsayısıdır.
- **Zamanda ters çevirme:** $x(-t)\leftrightarrow X(-\omega)$. Genlikler değişmez, fazın işareti değişir.
- **Dualite (simetri):** $X(t)\leftrightarrow2\pi x(-\omega)$ (ekrandan, 01:35:00). Hoca bunun üzerinde durmadı.
- **Zamanda türev:** $\frac{dx(t)}{dt}\leftrightarrow j\omega X(\omega)$, yani zamanda türev frekansta $j\omega$ ile çarpmadır (ekrandan, 01:35:00).
- **Frekansta türev:** $(-jt)x(t)\leftrightarrow\frac{dX(\omega)}{d\omega}$.
- **Zamanda integral:** $\int_{-\infty}^{t}x(\tau)d\tau\leftrightarrow\pi X(0)\delta(\omega)+\frac{1}{j\omega}X(\omega)$. $X(0)$ sıfır frekanslı (DC) bileşendir; merkezde $\pi X(0)$ ağırlıklı bir impuls ve diğer frekanslarda $X(\omega)/j\omega$ terimi oluşur.

### 8.2 Konvolüsyon özelliği

Hoca bunun önemli bir özellik olduğunu belirtti. Daha önce sürekli ve ayrık zamanda konvolüsyon ayrı ayrı gösterilmişti. Zaman domenindeki konvolüsyon frekans domeninde çok daha basit bir işlem olan çarpmaya dönüşür:
$$x_1(t)*x_2(t)\leftrightarrow X_1(\omega)X_2(\omega).$$
Konvolüsyon zorlu bir işlemdir; işaretin genişliği arttıkça teker teker kaydırıp altta kalan alanları bulmak zahmetlidir. Frekans domenine geçip iki dönüşümü çarpmak, sonra ters Fourier dönüşümü almak çoğu zaman avantaj sağlar. Dualite gereği zamandaki çarpma da frekansta konvolüsyona karşılık gelir.

> **Hocanın vurgusu:** Frekans domeninin asıl kazancı, zorlu konvolüsyon işleminin basit bir çarpmaya dönüşmesidir.

### 8.3 Parseval teoremi (dönüşüm için)

$$\int_{-\infty}^{\infty}|x(t)|^2dt=\frac{1}{2\pi}\int_{-\infty}^{\infty}|X(\omega)|^2d\omega.$$
Başka bir domene geçilse de, $2\pi$ katsayısıyla normalize edildiğinde işaretin zaman ve frekans domenlerindeki "altında kalan alanları" (karelerinin integralleri) eşittir. Hoca bunu bir tür enerjinin korunumu yasasına benzetti.

> **Ek bilgi (derste anlatılmadı):** Periyodik işaretlerde Parseval teoremi ortalama güç için yazılır ($P=\sum|c_k|^2$). Periyodik olmayan, sonlu enerjili işaretlerde ise yukarıdaki eşitlik toplam enerjiyi verir. Derste iki durumda da "güç" sözcüğü kullanıldı.

### 8.4 Yaygın Fourier dönüşüm çiftleri

Schaum kitabındaki Tablo 5-2 ekranda gösterildi (ekrandan, 01:40:00):

| $x(t)$ | $X(\omega)$ |
|---|---|
| $\delta(t)$ | $1$ |
| $\delta(t-t_0)$ | $e^{-j\omega t_0}$ |
| $1$ | $2\pi\delta(\omega)$ |
| $e^{j\omega_0t}$ | $2\pi\delta(\omega-\omega_0)$ |
| $\cos\omega_0t$ | $\pi[\delta(\omega-\omega_0)+\delta(\omega+\omega_0)]$ |
| $\sin\omega_0t$ | $-j\pi[\delta(\omega-\omega_0)-\delta(\omega+\omega_0)]$ |
| $u(t)$ | $\pi\delta(\omega)+\frac{1}{j\omega}$ |
| $u(-t)$ | $\pi\delta(\omega)-\frac{1}{j\omega}$ |
| $e^{-at}u(t),\ a>0$ | $\frac{1}{j\omega+a}$ |
| $te^{-at}u(t),\ a>0$ | $\frac{1}{(j\omega+a)^2}$ |
| $e^{-a\lvert t\rvert},\ a>0$ | $\frac{2a}{a^2+\omega^2}$ |
| $\frac{1}{a^2+t^2}$ | $e^{-a\lvert\omega\rvert}$ |
| $e^{-at^2},\ a>0$ | $\sqrt{\pi/a}\;e^{-\omega^2/4a}$ |

Hoca bu çiftlerden bazılarını yorumladı:

- Zaman domeninde impuls $\delta(t)$'nin dönüşümü her frekansta 1'dir. İmpulsun bütün frekanslarda bileşeni vardır; bütün frekanslar birleştirilirse impuls elde edilir.
- $x(t)=1$ sabit, DC bir işarettir. Dönüşümü merkezde $2\pi$ ağırlıklı bir impulstur, yani yalnız sıfır frekansında bileşeni vardır. Gerçekten DC işaretin frekansı yoktur (sıfırdır).
- $\cos\omega_0t$'nin dönüşümü $-\omega_0$ ve $+\omega_0$'da ağırlığı $\pi$ olan iki impulstur. Tek bir sinüzoidden oluşan işaretin bileşeni yalnız $\omega_0=2\pi f_0$ frekansındadır; negatif ve pozitif frekansta eşit uzaklıkta iki impuls görünür.

Genel yorum: $|X(\omega)|$ çiziminde tek bir noktada değer varsa işaret tek frekanslıdır. Alçak frekanslarda büyük olup yükseğe doğru azalan bir çizim varsa işaretin ağırlığı alçak frekanslardadır.

## 9. Frekans cevabı ve LTI sistemler

Sistemde $x(t)$ giriş, $h(t)$ impuls cevabı, $y(t)$ çıkıştır. $x(t)$ artık farklı frekanslardaki karmaşık üstellerin ($e^{j\omega t}$) toplamı olarak ifade edildiğinden, çıkış sistemin bu farklı sinüzoidlere verdiği cevapların toplanmasıyla bulunur. Konvolüsyon özelliği sayesinde girişin dönüşümü $X(\omega)$ ve impuls cevabının frekans davranışı $H(\omega)$ biliniyorsa konvolüsyon yapmaya gerek yoktur (ekrandan, 01:45:00):
$$y(t)=x(t)*h(t)\quad\Longleftrightarrow\quad Y(\omega)=X(\omega)H(\omega).$$
Çarpımla $Y(\omega)$ bulunur, ters Fourier dönüşümüyle $y(t)$ elde edilir. Önceden impulslara verilen cevaplar bulunup çıkış konvolüsyonla hesaplanıyordu; şimdi $X(\omega)$ ve $H(\omega)$'nın çarpımı yeterlidir.

### 9.1 Karmaşık üstel girişin cevabı

Giriş $x(t)=e^{j\omega_0t}$ olsun. Tablodan
$$X(\omega)=2\pi\delta(\omega-\omega_0)$$
olur; dönüşüm yalnız $\omega_0$'da $2\pi$ ağırlıklı bir impulstur. Buna göre
$$Y(\omega)=H(\omega)X(\omega)=2\pi H(\omega)\delta(\omega-\omega_0)=2\pi H(\omega_0)\delta(\omega-\omega_0).$$
İmpuls yalnız $\omega_0$'da değer aldığı için $H(\omega)$ yerine $H(\omega_0)$ yazılabilir. Ters dönüşüm alınırsa
$$y(t)=H(\omega_0)e^{j\omega_0t}$$
bulunur. Karmaşık üstel, LTI sistemin öz fonksiyonudur ve öz değeri $H(\omega_0)$'dır. İşareti oluşturan $\omega_0,2\omega_0,3\omega_0,\dots$ frekanslarının her biri için $H$'ın o frekanstaki değeri biliniyorsa sonuçlar toplanarak çıkış bulunur. Giriş Fourier serisiyle $x(t)=\sum_k c_ke^{jk\omega_0t}$ ise çıkış da periyodiktir: $y(t)=\sum_k c_kH(k\omega_0)e^{jk\omega_0t}$.

Hoca girişlerde neden hep karmaşık üstel kullanıldığını da buradan açıkladı. $\cos\omega_0t$ hem $-\omega_0$ hem $+\omega_0$'da iki impuls üretir. $e^{j\omega_0t}$ ise yalnız pozitif frekansta tek bir impuls üretir. Negatif ve pozitif frekanslar için ayrı işlem gerekmediğinden hesaplar basitleşir. Frekans domeninde $X(\omega)$, $H(\omega)$ ve $Y(\omega)$'nın hepsinin karmaşık değerler aldığı unutulmamalıdır.

### 9.2 Soru-cevap: CTFS ile CTFT farkı

**Soru:** Sürekli zamanlı Fourier serisi (CTFS) ile sürekli zamanlı Fourier dönüşümü (CTFT) arasındaki temel fark nedir; CTFT neyi anlatır?

**Cevap:** CTFS, işaretin periyodik olduğu temel varsayımıyla işaretin frekanslarını (katsayılarını) bulur. CTFT ise bu derste matematiksel adımlarla geliştirildiği gibi, herhangi bir işaretin frekanslarının nasıl bulunacağını verir. Önce periyodik fonksiyonların Fourier serisi katsayıları bulunmuş, sonra bu sonuç periyodik olmayan herhangi bir işaretin frekans içeriğini bulmak için CTFT'ye dönüştürülmüştür. Kısaca CTFS periyodik işaretlerde çalışır; CTFT periyodik olmayan herhangi bir işaretle çalışabilir.

## 10. Soru çözümü öncesi tekrar: trigonometrik seri, simetri ve üstel seri

Ders arasından sonra "Sorular 2, Fourier Serileri" dosyasına geçildi. Dosya önce trigonometrik seriyi, sonra karmaşık seriyi anlatır; derste bu sıranın tersi izlenmiş ve aradaki bağ gösterilmişti.

### 10.1 Trigonometrik seri

Fourier serisi, periyodik bir $f(t)$ (ya da $x(t)$) fonksiyonunun kosinüs ve sinüslerin sonsuz toplamı biçimindeki açılımıdır:
$$f(t)=\frac{a_0}{2}+\sum_{n=1}^{\infty}(a_n\cos n\omega t+b_n\sin n\omega t),\qquad \omega=\frac{2\pi}{T}.$$
$n=0$ terimi $a_0/2$'yi, yani DC bileşeni verir; geri kalanlar işaretin AC kısmını oluşturur. $n=1$ için $a_1\cos\omega t+b_1\sin\omega t$, $n=2$ için $a_2\cos2\omega t+b_2\sin2\omega t$ gelir ve frekans $2\omega,3\omega,\dots$ diye artar (ekrandan, 01:55:00). Terimlerin hepsi temel frekansın katları, yani harmonikler olduğu için Fourier serisi hesabına harmonik analiz denir. Keyfi (arbitrary) bir fonksiyonu basit terimlere ayırıp çözmeyi ve yeniden birleştirmeyi sağlar.

Hoca, slaytta $\omega$ için "temel frekans" dendiğini, doğrusunun "temel açısal frekans" olduğunu belirtti; $2\pi$ ile çarpılmamış hâli $f$ temel frekanstır. Katsayılar:
$$a_0=\frac{2}{T}\int_0^Tf(t)\,dt,\qquad a_n=\frac{2}{T}\int_0^Tf(t)\cos n\omega t\,dt,\qquad b_n=\frac{2}{T}\int_0^Tf(t)\sin n\omega t\,dt.$$
İntegral $0$–$T$ yerine $-T/2$–$T/2$ aralığında da alınabilir.

Çözümlerde sürekli kullanılan eşitlikler, $n$ tam sayı olmak üzere:
$$\sin n\pi=0,\qquad \cos n\pi=(-1)^n,\qquad \cos2n\pi=1,\qquad \sin2n\pi=0.$$
Kosinüs çift ($\cos(-x)=\cos x$), sinüs tek ($\sin(-x)=-\sin x$) fonksiyondur.

> **Hocanın vurgusu:** İntegral alma kuralları tekrar edilmelidir; çözümler bu integrallere dayanır ve sınavda gerekebilir. Örnekler evde tek tek çözülmelidir.

### 10.2 Simetri fonksiyonları

Hoca bu bölümün daha önce verilse daha iyi olacağını söyledi.

- **Çift simetri:** $f(-t)=f(t)$. Örnekler: $\cos t$, $t^2$, $|t|$. Çift fonksiyonun $-A$'dan $A$'ya integrali, $0$'dan $A$'ya integralin iki katıdır: $\int_{-A}^{A}f_e\,dt=2\int_0^Af_e\,dt$.
- **Tek simetri:** $f(-t)=-f(t)$. Örnekler: $t$, $\sin t$. Tek fonksiyonun $-A$'dan $A$'ya integrali sıfırdır; iki taraftaki alanlar birbirini götürür (ekrandan, 02:25:00).
- **Çarpım kuralları:** çift × çift = çift, tek × tek = çift, çift × tek = tek, tek × çift = tek. İki fonksiyon aynı özellikteyse sonuç çifttir.

Fourier serisine uygulanınca: çift periyodik fonksiyonda $b_n=0$ ve $a_n=\frac{4}{T}\int_0^{T/2}f(t)\cos n\omega t\,dt$ olur. Tek periyodik fonksiyonda $a_0=0$, $a_n=0$ ve $b_n=\frac{4}{T}\int_0^{T/2}f(t)\sin n\omega t\,dt$ olur. Çünkü çift fonksiyon × kosinüs çift kalır ve integral yarı aralığın iki katıdır; tek fonksiyon × kosinüs tektir ve integrali sıfırdır.

### 10.3 Parseval teoremi (trigonometrik seriyle)

Parseval teoremi, periyodik bir sinyaldeki ortalama gücün DC bileşenin gücü ile harmoniklerin ortalama güçlerinin toplamına eşit olduğunu söyler. Bir sinüzoidin gücü $V_{rms}^2/R$'dir ve $V_{rms}=V_p/\sqrt2$'dir. $R=1$ alınınca genliği $A$ olan sinüzoidin gücü $A^2/2$ olur. Buna göre
$$P=\frac14a_0^2+\frac12\sum_{n=1}^{\infty}(a_n^2+b_n^2).$$

### 10.4 Trigonometrik seriden karmaşık üstel seriye

Euler bağıntılarından $\cos x=\frac{e^{jx}+e^{-jx}}{2}$ ve $\sin x=\frac{e^{jx}-e^{-jx}}{2j}$ elde edilir ($e^{jx}=\cos x+j\sin x$ ve $e^{-jx}=\cos x-j\sin x$ taraf tarafa toplanıp çıkarılarak). Bunlar trigonometrik seride yerine konunca (ekrandan, 02:35:00)
$$f(t)=\frac{a_0}{2}+\sum_{n=1}^{\infty}\frac{a_n-jb_n}{2}e^{jn\omega t}+\sum_{n=1}^{\infty}\frac{a_n+jb_n}{2}e^{-jn\omega t}$$
olur. $c_0=\frac{a_0}{2}$, $c_n=\frac{a_n-jb_n}{2}$, $c_{-n}=\frac{a_n+jb_n}{2}$ denirse
$$f(t)=c_0+\sum_{n=1}^{\infty}c_ne^{jn\omega t}+\sum_{n=1}^{\infty}c_{-n}e^{-jn\omega t}.$$
İkinci toplamda indis ters çevrilirse $\sum_{n=-1}^{-\infty}c_ne^{jn\omega t}$ olur. $c_0$ terimi $n=0$'daki $c_0e^{j0}$ terimi olarak araya konunca üç parça birleşir:
$$f(t)=\sum_{n=-\infty}^{\infty}c_ne^{jn\omega t},\qquad c_n=\frac1T\int_0^Tf(t)e^{-jn\omega t}dt.$$
Trigonometrik mi karmaşık mı kullanılacağı $f(t)$'ye bağlıdır; hangisiyle integral daha çabuk alınıyorsa o seçilir. Karmaşık katsayılar çoğu zaman trigonometrik olanlardan daha kolay elde edildiği için daha çok kullanılır. İstenirse trigonometrik katsayılardan da geçiş yapılabilir.

> **Ek bilgi (derste anlatılmadı):** Hoca slayttaki geçişte indis değişiminde üsteki işaretin değiştirilmesinin unutulduğunu düşündü. İndis $n\to-n$ değiştirildiğinde $c_{-n}e^{-jn\omega t}$ terimi $c_ne^{jn\omega t}$ olur ve toplam sınırları $-1$'den $-\infty$'a gider; slayttaki son satır bu dönüşümle tutarlıdır.

## Örnek Sorular

### Soru 1: Kare dalganın trigonometrik Fourier serisi

(ekrandan, 02:00:00) Periyodu $T=2$ olan $f(t)$, $0<t<1$ için $1$, $1<t<2$ için $0$ değerini alır ($f(t+2)=f(t)$). Fourier serisini bulunuz.

**Çözüm (derste verildi):** Önce periyot belirlenir: $T=2$, dolayısıyla $\omega=2\pi/2=\pi$.

- $a_0=\frac22\int_0^2f(t)\,dt=\int_0^11\,dt+\int_1^20\,dt=1$.
- $a_n=\int_0^1\cos n\pi t\,dt+\int_1^20\,dt=\left[\frac{\sin n\pi t}{n\pi}\right]_0^1=\frac{\sin n\pi}{n\pi}$. $n$ tam sayı olduğundan $\sin\pi=\sin2\pi=\dots=0$, yani $a_n=0$.
- $b_n=\int_0^1\sin n\pi t\,dt=\left[-\frac{\cos n\pi t}{n\pi}\right]_0^1=\frac{1-\cos n\pi}{n\pi}$. $\cos\pi=\cos3\pi=\dots=-1$ ve $\cos2\pi=\cos4\pi=\dots=1$ olduğundan $\cos n\pi=(-1)^n$, yani $b_n=\frac{1-(-1)^n}{n\pi}$: tek $n$ için $\frac{2}{n\pi}$, çift $n$ için $0$.

Sonuç:
$$f(t)=\frac12+\sum_{n=1}^{\infty}\frac{1-(-1)^n}{n\pi}\sin n\pi t=\frac12+\frac{2}{\pi}\sin\pi t+\frac{2}{3\pi}\sin3\pi t+\frac{2}{5\pi}\sin5\pi t+\dots$$
Slaytta ilk terimden başlayarak 2, 3, 4 ve 23 terime kadar toplamların grafiği verilir; terim eklendikçe toplam kare dalgaya yaklaşır, sonsuzda orijinal işarete ulaşılır. Katsayılar python ile doğrulandı.

### Soru 2: $f(t)=t$ testere dişi dalgası

(ekrandan, 02:15:00) $f(t)=t$, $-1\le t\le1$, $f(t+2)=f(t)$. $f(t)$'nin grafiğini $-3\le t\le3$ aralığında çiziniz ve Fourier serisini hesaplayınız.

**Çözüm (derste verildi):** Grafik, $-1$ ile $1$ arasında eğimi 1 olan doğrunun 2 periyotla tekrarıdır. $T=2$, $\omega=\pi$.

- $a_0=\frac22\int_{-1}^{1}t\,dt=\left[\frac{t^2}{2}\right]_{-1}^{1}=0$. Ortalama sıfırdır; grafikten de görülür.
- $a_n=\int_{-1}^{1}t\cos n\pi t\,dt$. Kısmi integrasyonla $\left[\frac{t\sin n\pi t}{n\pi}\right]_{-1}^{1}-\int_{-1}^{1}\frac{\sin n\pi t}{n\pi}dt$ olur. İlk terim $\sin n\pi=0$ nedeniyle sıfırdır. İkincisi $\left[\frac{\cos n\pi t}{n^2\pi^2}\right]_{-1}^{1}=\frac{\cos n\pi-\cos(-n\pi)}{n^2\pi^2}=0$ verir. Yani $a_n=0$; zaten $t\cos n\pi t$ tek fonksiyondur.
- $b_n=\int_{-1}^{1}t\sin n\pi t\,dt$. Kısmi integrasyonla $b_n=-\frac{2\cos n\pi}{n\pi}=\frac{2(-1)^{n+1}}{n\pi}$ (ara adım eklendi).

Sonuç (ekrandan, 02:20:00):
$$f(t)=\sum_{n=1}^{\infty}\frac{2(-1)^{n+1}}{n\pi}\sin n\pi t=\frac{2}{\pi}\sin\pi t-\frac{2}{2\pi}\sin2\pi t+\frac{2}{3\pi}\sin3\pi t-\dots$$
Değerler python ile doğrulandı.

### Soru 3: Parçalı doğrusal işaret

(derste sözlü ve ekrandan, 02:20:00) $0<t<2$ için $f(t)=2-t$, $2<t<4$ için $f(t)=0$, periyot $T=4$. Grafiğini çiziniz ve Fourier serisini bulunuz.

**Çözüm (derste kısmen verildi):** $T=4$, $\omega=\pi/2$. $2<t<4$ aralığında işaret sıfır olduğundan integraller yalnız $0$–$2$ aralığında alınır.

- $a_0=\frac24\int_0^2(2-t)\,dt=\frac12\left[2t-\frac{t^2}{2}\right]_0^2=\frac12\cdot2=1$.
- $a_n=\frac12\int_0^2(2-t)\cos\frac{n\pi t}{2}dt$. Derste "iki ayrı terimin integrali alınır" denerek sonuç slayttan gösterildi. <!-- BELİRSİZ: Slayttaki a_n sonucu kareden okunamadı. --> Python ile $a_n=\frac{2[1-(-1)^n]}{n^2\pi^2}$ bulundu (tek $n$ için $\frac{4}{n^2\pi^2}$, çift $n$ için $0$).
- $b_n=\frac{2}{n\pi}$ (derste okundu, python ile doğrulandı). Hoca slayttaki bir ifadede $\sin2n\pi$ yazılmak istendiğini, bunun her $n$ için sıfır olduğunu söyledi.

Sonuç: $f(t)=\frac12+\sum_{n=1}^{\infty}\left(\frac{2[1-(-1)^n]}{n^2\pi^2}\cos\frac{n\pi t}{2}+\frac{2}{n\pi}\sin\frac{n\pi t}{2}\right)$.

> **Ders sonrası not:** Hoca "$a_0$ bu işaretin ortalamasıdır, ortalaması 1" dedi. İşaretin ortalaması $c_0=a_0/2=1/2$'dir; $a_0=1$ ise ortalamanın iki katıdır.

### Soru 4: Tek simetrili işaret

(ekrandan, 02:30:00) Periyodu 4 olan $f(t)$; $-2<t<-1$ için $-1$, $-1<t<1$ için $t$, $1<t<2$ için $1$ değerini alır. $-6\le t\le6$ aralığında çiziniz ve Fourier serisini bulunuz.

**Çözüm (derste verildi):** Grafikte işaret orijine göre simetriktir, yani tektir. Bu yüzden hesap yapmadan $a_0=0$ ve $a_n=0$ denir. Yalnız $b_n$ bulunur. Tek fonksiyon × sinüs çift olduğundan, $-2$'den $2$'ye integral yerine $0$'dan $2$'ye integralin iki katı alınır; katsayı $\frac{2}{T}\cdot2=\frac{4}{T}$ olur:
$$b_n=\frac{4}{4}\int_0^2f(t)\sin\frac{n\pi t}{2}dt.$$
Slaytta sonuç $b_n=-\frac{2\cos n\pi}{n\pi}$ olarak verildi ve
$$f(t)=\sum_{n=1}^{\infty}\left(-\frac{2\cos n\pi}{n\pi}\right)\sin\frac{n\pi t}{2}=2\sum_{n=1}^{\infty}\frac{(-1)^{n+1}}{n\pi}\sin\frac{n\pi t}{2}$$
yazıldı. Burada $\cos n\pi=(-1)^n$ ile baştaki eksi işareti birleştirilerek $(-1)^{n+1}$ elde edilmiştir.

> **Ders sonrası not:** Hoca $T=4$ için "temel fundamental frekansı 4" dedi; doğrusu $\omega=2\pi/T=\pi/2$'dir. Ayrıca python ile yapılan hesapta $b_n=\int_0^1t\sin\frac{n\pi t}{2}dt+\int_1^2\sin\frac{n\pi t}{2}dt=\frac{4\sin(n\pi/2)}{n^2\pi^2}-\frac{2\cos n\pi}{n\pi}$ çıktı. Slayttaki sonuçta $\frac{4\sin(n\pi/2)}{n^2\pi^2}$ terimi eksiktir. Örneğin $b_1\approx1{,}042$ iken slayttaki formül $0{,}637$ verir; çift $n$'lerde iki sonuç aynıdır.

Hoca dosyadaki bir sonraki örneği (Örnek 5) çözmeden alıştırma olarak bıraktı.

### Soru 5: $e^t$ işaretinin karmaşık Fourier serisi

(ekrandan, 02:40:00) $0<t<2\pi$ için $f(t)=e^t$ olan ve $T=2\pi$ periyoduyla tekrar eden fonksiyonun karmaşık Fourier serisini bulunuz.

**Çözüm (derste verildi):** $T=2\pi$, dolayısıyla $\omega=2\pi/T=1$.

- $c_0=\frac{1}{2\pi}\int_0^{2\pi}e^t\,dt=\frac{1}{2\pi}\left[e^t\right]_0^{2\pi}=\frac{e^{2\pi}-1}{2\pi}$. Üste $j$ olmadığından bu yalnız gerçel bir sayıdır.
- $c_n=\frac{1}{2\pi}\int_0^{2\pi}e^te^{-jnt}dt=\frac{1}{2\pi}\int_0^{2\pi}e^{(1-jn)t}dt=\frac{1}{2\pi}\left[\frac{e^{(1-jn)t}}{1-jn}\right]_0^{2\pi}=\frac{e^{2\pi(1-jn)}-1}{2\pi(1-jn)}=\frac{e^{2\pi}e^{-j2n\pi}-1}{2\pi(1-jn)}$.
- $e^{-j2n\pi}=\cos2n\pi-j\sin2n\pi=1-0=1$ olduğundan $c_n=\frac{e^{2\pi}-1}{2\pi(1-jn)}$.
- $n=0$ konunca $c_n|_{n=0}=\frac{e^{2\pi}-1}{2\pi}=c_0$ çıkar; bu örnekte genel ifade $c_0$'ı da verir (ekrandan, 02:45:00).

Sonuç:
$$f(t)=\sum_{n=-\infty}^{\infty}\frac{e^{2\pi}-1}{2\pi(1-jn)}e^{jnt}.$$
Hoca, slaytta üsteki $\omega$'nın yazılmadığını, genel ifadede $e^{jn\omega t}$ olması gerektiğini, burada $\omega=1$ olduğu için $e^{jnt}$ kaldığını belirtti.

Slayttaki not: $c_0$, $c_n$'de $n=0$ konularak hesaplanabilse de bazen bu mümkün olmayabilir; bu yüzden $c_0$'ı tek başına hesaplamak daha iyidir.

$c_n$ karmaşık bir terimdir ve $n\omega$'ya bağlıdır; bu yüzden $|c_n|$, $n\omega$'ya karşı çizilebilir. $n=0,\pm1,\pm2,\dots$ için ayrık $|c_n|$ değerleri bulunur. $c_n$ karmaşık olmasına rağmen $|c_n|$ çizimi çifttir: negatif ve pozitif indisler aynı değeri verir. Frekans yükseldikçe değerler düşer; bu işarette düşük frekanslı bileşenler ağırlıktadır.

> **Ders sonrası not:** Hoca slayttaki $c_0$ değerini "0,85" diye okudu. $\frac{e^{2\pi}-1}{2\pi}\approx85{,}07$'dir; ayrıca $|c_1|\approx60{,}15$ ve $|c_2|\approx38{,}04$ (python ile hesaplandı).

### Soru 6: Soru 1'deki kare dalganın karmaşık Fourier serisi

(derste sözlü, 02:45:46) Örnek 1'deki fonksiyonun karmaşık Fourier serisini hesaplayınız.

**Çözüm (derste verildi):** $T=2$, $\omega=\pi$.

- $c_0$ işaretin ortalamasıdır: bir periyotta alan 1, periyot 2, yani $c_0=\frac12$.
- $c_n=\frac12\int_0^11\cdot e^{-jn\pi t}dt$ ($1<t<2$ aralığı sıfır olduğu için hesaplanmaz) $=\frac12\left[\frac{e^{-jn\pi t}}{-jn\pi}\right]_0^1=\frac{1-e^{-jn\pi}}{2jn\pi}$.
- $e^{-jn\pi}=\cos n\pi-j\sin n\pi$. Sinüslü kısım $\pi$'nin katlarında hep sıfırdır; $\cos n\pi$ tek $n$'de $-1$, çift $n$'de $1$'dir. Buna göre tek $n$ için $c_n=\frac{2}{2jn\pi}=\frac{1}{jn\pi}=-\frac{j}{n\pi}$, çift $n$ için $c_n=0$.
- Genel ifadede $n=0$ konunca sıfır çıkar, oysa $c_0=\frac12$'dir. Slayttaki uyarı burada gerçekleşir: $c_0$ ayrıca hesaplanmalıdır.

Sonuç:
$$f(t)=\frac12+\sum_{\substack{n=-\infty\\ n\ \text{tek}}}^{\infty}\frac{1}{jn\pi}e^{jn\pi t}.$$
$c_0$ DC bileşene karşılık gelir. Tek harmoniklerde değer vardır, çiftlerde yoktur. $|c_n|$'ın çizimi işaretin genlik spektrumudur ve işarette hangi frekansların bulunduğunu gösterir. Değerler python ile doğrulandı.

> **Ek bilgi (derste anlatılmadı):** Bu sonuç Soru 1'le tutarlıdır. $c_n=\frac12(a_n-jb_n)$ bağıntısında $a_n=0$ ve tek $n$ için $b_n=\frac{2}{n\pi}$ konunca $c_n=-\frac{j}{n\pi}$ elde edilir; $c_0=a_0/2=\frac12$'dir.

## Dersin Toparlaması

Bu derste periyodik bir işaretin karmaşık üstellerin (ya da kosinüs ve sinüslerin) ağırlıklı toplamı olarak yazılabileceği görüldü. Karmaşık üstel Fourier serisi, trigonometrik seri ve harmonik form tanıtıldı. Katsayıların integral formülleri, iki seri arasındaki dönüşümler, çift ve tek işaretlerin sadeleştirici etkisi, Dirichlet koşulları, genlik ve faz spektrumları ile Parseval teoremi işlendi. Ardından periyodik genişletme ve $T_0\to\infty$ limitiyle Fourier serisinden sürekli zamanlı Fourier dönüşümüne geçildi. Dönüşüm çifti, temel özellikler (özellikle konvolüsyonun çarpmaya dönüşmesi), yaygın dönüşüm çiftleri ve LTI sistemlerde $Y(\omega)=H(\omega)X(\omega)$ ilişkisi gösterildi. Son bölümde trigonometrik ve karmaşık Fourier serisi örnekleri adım adım çözüldü.

Bir sonraki derste aynı yol ayrık zamanda izlenecek: ayrık zamanlı Fourier serisinden ayrık zamanlı Fourier dönüşümüne (M. J. Roberts, Lecture 7; Schaum kitabının 6. bölümü) geçilecek. Hoca, ayrık kısmın bu derste kurulan sürekli zaman temeli üzerine oturduğunu, bu yüzden bu konuların iyi çalışılmasını önerdi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
