# Ders 14 Genişletilmiş Notu: Laplace'ta Başlangıç ve Son Değer Teoremleri, z-Dönüşümü, Yakınsaklık Bölgesi, Sistem Fonksiyonu ve Özellikler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Laplace Dönüşümünde Başlangıç ve Son Değer Teoremleri
- 2. z-Dönüşümüne Neden İhtiyaç Var?
- 3. z-Dönüşümünün Tanımı ve z Düzlemi
- 4. Var Olma Şartı
- 5. İlk Örnek: $a^n u[n]$ ve Yakınsaklık Bölgesi
- 6. Ayrık Zamanlı Sistem Örneği: Ses Üretimi
- 7. Sonlu Uzunluklu İşaretler ve Birim Dürtü
- 8. Üstel İşaret ve Ters Dönüşüm Örnekleri
- 9. Sistem Fonksiyonu ve FIR Filtre
- 10. Birim Gecikme
- 11. Konvolüsyonun Polinom Çarpımıyla Hesaplanması
- 12. Seri Bağlı Sistemler
- 13. Frekans Cevabı, Sıfırlar ve Kutuplar
- 14. IIR Filtreye Kısa Bakış
- 15. Sol Taraflı İşaret: $a^n u[-n-1]$
- 16. İki Terimli İşaret ve ROC Kuralı
- 17. z-Dönüşümünün Özellikleri
- 18. Birim Basamak Cevabı ve Fark Denklemleri
- 19. Kalan Slaytlar: Sıfır-Kutup ve Sinüzoidal Cevap

## 1. Laplace Dönüşümünde Başlangıç ve Son Değer Teoremleri

Hoca, z-dönüşümüne geçmeden önce Laplace konusundan kalan bir özelliği örnekle gösterdi. Elimizde şu Laplace dönüşümü olsun:

$$F(s)=\frac{2}{s(s+2)(s+4)}$$

Hocanın ilk sorusu, ters dönüşüm almak için kısmi kesirlere ayırırsak kaç katsayı bulmamız gerektiğiydi. Cevap üçtür, çünkü paydanın üç kökü vardır. Bu üç kök, sistemin üç kutbu olduğu anlamına gelir: $0$, $-2$ ve $-4$.

Bu defa dert başkadır. Normalde ters dönüşümü alsaydık elimizde $t$'ye bağlı bir $f(t)$ ya da $y(t)$ ifadesi olurdu. Hoca şunu sordu: Sistemin $t=0$ anındaki değeri nedir, $t$ sonsuza giderken hangi değere gider? Bu ifade sinyal için de kullanılabilir, ama sistem için kullanmak daha doğrudur. Sisteme ilk giriş verildiği $t=0$ anında sistem nereden başlayacak, zaman ilerleyince nereye gidecek?

### 1.1 Zaman Düzleminden Bakış

$t$'ye bağlı ifade elimizde olsaydı cevap kolaydı: $t$ yerine sıfır ya da sonsuz yazardık. Hoca bunu $y(t)=Ae^{-t}$ ile hatırlattı. $t=0$'da $e^0=1$ olduğu için işaret $A$ noktasından başlar. $t\to\infty$ iken $e^{-t}\to 0$ olduğu için işaret azalarak sönümlenir.

Oysa şimdi elimizde yalnız $F(s)$ var, $t$'ye dair bir şey yok. Ters dönüşüm almadan cevabı veren özellikler, son değer (final value) ve başlangıç değer (initial value) teoremleridir.

### 1.2 Son Değer Teoremi

$$\lim_{t\to\infty} f(t)=\lim_{s\to 0} sF(s)$$

Örneğe uygulayalım:

$$\lim_{s\to 0} s\cdot\frac{2}{s(s+2)(s+4)}=\lim_{s\to 0}\frac{2}{(s+2)(s+4)}=\frac{2}{2\cdot 4}=\frac{1}{4}$$

İlk bakışta $0/0$ belirsizliği çıkacak gibi görünür, ama buna gerek yoktur: Pay ve paydadaki $s$'ler doğrudan sadeleşir. Demek ki sistem sonsuzda $1/4$ noktasına oturur.

Hoca bunun anlamını şöyle yorumladı: İşaret bir yerlerden başlayıp $1/4$'e gelir, doğrudan sıfıra oturmaz. Bu, DC bileşeni olan bir sistem olabilir. Örneğin ifade $\frac14+e^{-t}$ gibi olsaydı sonsuzda yine $1/4$'e giderdi. Yanına başka terimler de gelebilir, ters dönüşüm almadığımız için şimdilik bunu bilmiyoruz.

> **Ders sonrası not:** Hoca son değer teoremini şartsız kullandı. Teorem, $sF(s)$'nin bütün kutupları sol yarı düzlemdeyse geçerlidir. Bu örnekte $sF(s)=\frac{2}{(s+2)(s+4)}$'ün kutupları $-2$ ve $-4$ olduğu için şart sağlanır.

### 1.3 Başlangıç Değer Teoremi

$$\lim_{t\to 0} f(t)=\lim_{s\to\infty} sF(s)$$

Bu kez $s$ sonsuza gider. Yine $s$'ler sadeleşir, $(s+2)$ ve $(s+4)$ sonsuza gider, çarpımları da sonsuz olur. Bir sayının sonsuza bölümü sıfırdır:

$$\lim_{s\to\infty}\frac{2}{(s+2)(s+4)}=0$$

Hoca sonucu bir devre üzerinden okudu: Bu bir devre ise, enerjiyi açtığımızda göreceğimiz değer sıfırdır, en sonunda ulaşılan değer ise $1/4$'tür.

### 1.4 Çalışma Sorusu: Sonucu Ters Dönüşümle Kontrol Etmek

Hoca, isteyenlerin aynı sonucu ters dönüşümle kontrol etmesini istedi. Paydadaki çarpanların hepsi birinci dereceden ve katlı kök yok, bu yüzden açılım üç katsayılıdır:

$$F(s)=\frac{A}{s}+\frac{B}{s+2}+\frac{C}{s+4}$$

Hoca çözümü derste yapmadı. Katsayılar şöyle bulunur (ara adım eklendi):

- $A=\left.\dfrac{2}{(s+2)(s+4)}\right|_{s=0}=\dfrac{2}{8}=\dfrac14$
- $B=\left.\dfrac{2}{s(s+4)}\right|_{s=-2}=\dfrac{2}{(-2)(2)}=-\dfrac12$
- $C=\left.\dfrac{2}{s(s+2)}\right|_{s=-4}=\dfrac{2}{(-4)(-2)}=\dfrac14$

Ters dönüşüm:

$$f(t)=\left(\frac14-\frac12 e^{-2t}+\frac14 e^{-4t}\right)u(t)$$

Buradan $f(0)=\frac14-\frac12+\frac14=0$ ve $\lim_{t\to\infty}f(t)=\frac14$ çıkar. Hocanın dediği gibi, $t$ yerine sıfır ve sonsuz koyunca teoremlerle aynı değerler bulunur.

## 2. z-Dönüşümüne Neden İhtiyaç Var?

Hoca konuya bir soruyla girdi.

**Soru:** Fourier dönüşümü varken Laplace dönüşümüne niye ihtiyaç duyduk? **Cevap:** Mesele periyodik olmak değildir. Periyodik işaretler için Fourier serileri, periyodik olmayanlar için Fourier dönüşümü vardır. Laplace dönüşümü bunların daha genel hâlidir: $\sigma$ sayesinde sonsuza giden durumları ortadan kaldırır. Hesaplayacağımız integral sonsuza gidiyorsa, yani integrallenemiyorsa Fourier dönüşümü yapılamaz. Bu durumda dönüşümü belli şartlar altında yapabilmek için Laplace dönüşümü tanımlanmıştır.

Bunlar sürekli zaman içindi. Ayrık zamanda da bir Fourier dönüşümümüz vardı:

$$X(\omega)=\sum_{n} x[n]\,e^{-j\omega n}$$

Sürekli zamanda olduğu gibi, işareti karmaşık sinüzoidal $e^{-j\omega n}$ ile çarpıp topluyor ve ayrık zamanlı işaretin frekans düzlemindeki karşılığını elde ediyorduk.

**Soru:** Bu dönüşümün adı neydi? (Bir öğrenci "discrete Fourier transform" dedi.) **Cevap:** Ayrık zamanlı Fourier dönüşümü.

> **Ders sonrası not:** Öğrencinin söylediği ad DFT'nin (ayrık Fourier dönüşümü) adıdır. Burada kastedilen DTFT'dir (discrete-time Fourier transform, ayrık zamanlı Fourier dönüşümü). DTFT'nin çıktısı $\omega$'nın sürekli bir fonksiyonudur, DFT ise sonlu sayıda frekans örneği verir. Ayrıca hoca toplamı tahtada $n=0$'dan başlatarak yazdı; genel tanımda toplam $-\infty$'dan $+\infty$'a gider.

Aynı sorun burada da vardır: Toplam sonsuza gidebilir. Bunun için daha genelleştirilmiş bir dönüşüm tanımlanmıştır. Hocanın İngilizce tanımıyla z-dönüşümü, ayrık zamanlı Fourier dönüşümünün genel hâlidir (general case of the discrete-time Fourier transform). Laplace, Fourier dönüşümü için neyse, z-dönüşümü de DTFT için odur.

## 3. z-Dönüşümünün Tanımı ve z Düzlemi

Bu da bir dönüşüm olduğu için elimizde iki değişken vardır: $n$ düzleminden aldığımız işareti $z$ düzlemine götürürüz ve sonucu büyük harfle, $X(z)$ ile yazarız. Sürekli zamandaki integralin yerini burada toplam alır:

$$X(z)=\sum_{n=-\infty}^{\infty} x[n]\,z^{-n}$$

Toplam sayesinde $n$'e bağlı ifadeler kaybolur, $z$'ye bağlı ifadeler kalır. $z$ karmaşık bir şey değildir, yalnızca bir karmaşık değişkendir:

$$z=re^{j\omega}$$

Burada $r$ büyüklük, $\omega$ açıdır. Laplace'ta $s$ düzlemi (S plane) vardı, burada z düzlemi (Z plane) vardır. Karmaşık düzlemde $z$'yi çizersek, kendisine ait bir $r$ büyüklüğü ve bir $\omega$ açısı olan bir nokta görürüz. Hoca ayrıca, buradaki tanımın toplamı $-\infty$'dan başlattığı için iki taraflı olduğunu, bunun bir de tek taraflısı olduğunu söyledi.

<!-- BELİRSİZ: 00:17:50-00:18:00 arasında altyazı "unidirectal direction bu pardon... iki tarafı, tek taraflısı var" diyor. Tahtadaki toplamın iki taraflı tanım olduğu 00:16:54 ve 01:43:21'den çıkarıldı. -->

## 4. Var Olma Şartı

Her işaret için z-dönüşümü mümkün değildir. Toplamın sonsuza gitmemesi için şart koşarız: $|X(z)|<\infty$ olmalıdır. Tanımı yerine yazıp $z=re^{j\omega}$ koyalım:

$$X(z)=\sum_{n=-\infty}^{\infty} x[n]\left(re^{j\omega}\right)^{-n}=\sum_{n=-\infty}^{\infty} x[n]\,r^{-n}\,e^{-j\omega n}$$

Mutlak değer toplamın içine alınırsa şart şu hâli alır (toplamın mutlak değerinin, mutlak değerlerin toplamını geçemeyeceği ara adım olarak eklendi):

$$\sum_{n=-\infty}^{\infty} \left|x[n]\,r^{-n}\right|\,\left|e^{-j\omega n}\right|<\infty$$

Euler açılımıyla $e^{-j\omega n}=\cos\omega n-j\sin\omega n$ yazılır ve bu terimin büyüklüğü birdir. Geriye kalan şart şudur:

$$\sum_{n=-\infty}^{\infty} \left|x[n]\,r^{-n}\right|<\infty$$

> **Ders sonrası not:** Hoca, "$\omega$ tam alınırsa kosinüs 1, sinüs 0 olur, ifade 1'e yaklaşır" dedi. Doğrusu: $|e^{-j\omega n}|=\sqrt{\cos^2\omega n+\sin^2\omega n}=1$'dir, her $\omega$ ve her $n$ için. Yaklaşma söz konusu değildir, $\omega$'nın da tam sayı olması gerekmez. Bu yüzden yakınsaklık yalnız $r$'ye bağlıdır.

Bu sonucu Laplace dönüşümüyle karşılaştıralım. Orada $x(t)e^{-st}$ içinde $s=\sigma+j\omega$ yazıp ifadeyi iki çarpana ayırmıştık. Burada da aynı şey olur: İfadeyi bastıran, sonsuza gitmeyi engelleyen şey $r$ parametresidir. Laplace'taki $e^{-\sigma t}$'nin rolünü burada $r^{-n}$ üstlenir.

$r=1$ alınırsa şart $\sum_n|x[n]|<\infty$ olur. Yani işaretin artık mutlak integrallenebilir (absolutely integrable) değil, mutlak toplanabilir (absolutely summable) olması beklenir.

<!-- BELİRSİZ: 00:23:51-00:24:01 arasında hocanın r'nin bastırma etkisi için söylediği "çok küçük negatif bir sayı" ifadesi altyazıda anlaşılmıyor, nota alınmadı. -->

## 5. İlk Örnek: $a^n u[n]$ ve Yakınsaklık Bölgesi

Hoca, sürekli zamanda sık kullandığımız üstel işaretin benzerini aldı:

$$x[n]=a^n u[n]$$

Bunun z-dönüşümünü ve yakınsaklık bölgesini (region of convergence, ROC) soruyoruz. ROC, Laplace'taki kavramla aynıdır.

Tanımda yerine yazalım:

$$X(z)=\sum_{n=-\infty}^{\infty} a^n u[n] z^{-n}$$

$u[n]$ nedeniyle toplam $n=0$'dan başlar. Terimleri aynı $n$ üssü altında toplarsak:

$$X(z)=\sum_{n=0}^{\infty}\left(az^{-1}\right)^n=1+az^{-1}+\left(az^{-1}\right)^2+\dots$$

Bu, kalkülüsten bilinen geometrik seridir. Hoca buna $\sum_{n=0}^{\infty}\left(\frac12\right)^n=\frac{1}{1-\frac12}$ örneğiyle işaret etti. Bu toplamın değeri $2$'dir. Dolayısıyla:

$$X(z)=\frac{1}{1-az^{-1}}=\frac{z}{z-a}$$

Serinin toplanabilmesi için bir şart vardır: $|az^{-1}|<1$, yani $|a|/|z|<1$ olmalıdır. Karşıya atarsak:

$$|z|>|a|$$

Burası ROC'tur. z düzleminde çizildiğinde bir çember görürüz ve ROC bu çemberin dışıdır.

> **Ders sonrası not:** Hoca bu bölgeyi "A kadar çapta birim çember" diye anlattı. Birim çemberin yarıçapı $1$'dir. Burada kastedilen, yarıçapı $|a|$ olan çemberdir. ROC bu çemberin dışıdır.

## 6. Ayrık Zamanlı Sistem Örneği: Ses Üretimi

Hoca slaytlara geçerken bir genelleme yaptı: Ayrık zamanlı konvolüsyon ve ayrık zamanlı sistem işlemleri sürekli zamana göre nasıl daha kolaysa, z-dönüşümü de Laplace'tan daha kolaydır. Çoğunlukla polinom işlemleriyle uğraşılır.

Sonra ayrık zamanlı sistem örneği olarak ses üretim mekanizmasını gösterdi. Konuşma işleme (speech processing) dersi alınsaydı orada z-dönüşümü anlatılırdı. Sesin üretilmesinde akciğerlerden ve diyaframdan dudaklara kadar uzanan fizyolojik bir yol vardır. Bu yol, sesin üretildiği noktadan çıkış noktasına kadar kapalı bir sistem olarak modellenir. Ses bilgisayara kaydedileceği için model ayrık zamanlıdır.

Sistemin her parçası z düzleminde tanımlı bir alt sistemdir. Ses yolundan (vocal tract) dudağa kadar olan sistemin çıktısı, $z$'ye bağlı birkaç fonksiyonun çarpımıyla yazılır:

$$S(z)=E(z)\,G(z)\,A\,V(z)\,R(z)$$

Hoca bunların ayrıntısına girmedi. Sesli ve sessiz durumlarda frekans düzleminde farklı görüntüler elde edildiğini söyledi ve z-dönüşümünün bu alanda çok kullanıldığını vurguladı.

<!-- BELİRSİZ: Bu formül 00:31:22'de altyazıda "SZ, EZ çarpı, GZ çarpı, A çarpı, VZ çarpı, Z, RZ" diye geçiyor. Çarpanların tam yazımı slaytta kalmış. -->

Dönüşümün neden önemli olduğunu da şöyle özetledi: Sinyal işleme ve dijital sinyal işlemci tasarımında çok kullanılır. Sıfır ve kutup tanımları, sistemin kararlılığını ve frekans karakteristiğini incelemede yardımcı olur. Üstelik işlemler genellikle polinomlarladır, yani kolaydır.

## 7. Sonlu Uzunluklu İşaretler ve Birim Dürtü

Hoca önce Fourier tarafını hatırlattı: Bir dürtü ve onun bir birim ötelenmiş hâlinden oluşan işaretin frekans düzlemindeki karşılığında, ötelenen terim $e^{-j\omega}$ ile çarpılır. Sistemin nasıl çalıştığını z düzleminde de benzer şekilde buluruz:

$$H(z)=\sum_n h[n]\,z^{-n}$$

### 7.1 Sonlu İşaretin Dönüşümü Polinomdur

z-dönüşümü yalnız $a^n$ gibi formüllü işaretlere değil, herhangi bir işarete uygulanabilir. Örneğin $n=0$'dan başlayan beş elemanlı bir işaret olsun. Sıfırdan önce ve $n=5$ ile sonrasında değerler sıfırdır:

$$x[n]=\{2,4,6,4,2\}$$

Her elemanı kendi $z^{-n}$ çarpanıyla yazarsak bir polinom elde ederiz:

$$X(z)=2z^{0}+4z^{-1}+6z^{-2}+4z^{-3}+2z^{-4}=2+4z^{-1}+6z^{-2}+4z^{-3}+2z^{-4}$$

<!-- BELİRSİZ: Altyazıda (00:35:16) yalnız 2, 4 ve 6 katsayıları okunuyor. Son iki değer (4, 2) kısa nottan alındı. Hocanın 00:34:28'deki ilk slayt işareti de "2 ve 0 ile başlayan" başka bir beş elemanlı işarettir, kalan değerleri altyazıda yok. -->

### 7.2 Üsler Konumu, Katsayılar Genliği Verir

Hoca, üslerin zaman düzlemindeki konum bilgisini taşıdığını söyledi. Bunun sebebi birim dürtünün dönüşümünde görülür:

$$\sum_{n=-\infty}^{\infty}\delta[n]z^{-n}$$

Toplam eksi sonsuzdan artı sonsuza gider, ama $\delta[n]$ yalnız $n=0$'da birdir, diğer her yerde sıfırdır. O noktada $z^{0}=1$ olduğu için sonuç $1$'dir: $\delta[n]\leftrightarrow 1$.

Aynı işlemi $\delta[n-5]$ için yapalım. $n=5$'ten önce ve sonra her şey sıfırdır. $n=5$'te dürtü $1$, $z^{-n}$ ise $z^{-5}$ olur. Sonuç: $\delta[n-5]\leftrightarrow z^{-5}$. Yani $z^{-5}$ gördüğümüzde bu, zamanda $n=5$ anının değeridir. Genel olarak $n_0$ birim gecikme için $\delta[n-n_0]\leftrightarrow z^{-n_0}$ yazılır. Bu kuralı toplamı her seferinde açmadan kullanabiliriz.

> **Hocanın vurgusu:** İndis ile genliği karıştırmayın. Üsler ve $n$ değerleri indekstir, yani zamandaki konumdur. Katsayılar ve $x[n]$ değerleri ise genliktir.

Bu okuma ters yönde de doğrudan yapılır. Şu dönüşüm verilsin:

$$X(z)=1-2z^{-1}+3z^{-3}-z^{-5}$$

Sabit terimin derecesi sıfırdır, yani $n=0$'da $1$ vardır. $z^{-1}$'de $-2$, $z^{-2}$'de $0$, $z^{-3}$'te $3$, $z^{-4}$'te $0$, $z^{-5}$'te $-1$ vardır. Ters dönüşüm dürtüler cinsinden doğrudan yazılır:

$$x[n]=\delta[n]-2\delta[n-1]+3\delta[n-3]-\delta[n-5]$$

## 8. Üstel İşaret ve Ters Dönüşüm Örnekleri

### 8.1 Sönümlenen Üstel: $0.8^n u[n]$

Slayttaki işaretin değerleri $0.8$'in kuvvetleridir. Açarsak:

$$X(z)=1+0.8z^{-1}+0.64z^{-2}+0.512z^{-3}+\dots$$

Genel terim $0.8$'den türediği için, $a=0.8$ ile biraz önceki sonucu kullanırız:

$$X(z)=\frac{1}{1-0.8z^{-1}}$$

Bu yazım çok kullanılır, ama bazı durumlarda şu biçim daha sık karşımıza çıkar: Pay ve paydayı $z$ ile çarparsak

$$X(z)=\frac{z}{z-0.8}$$

elde edilir.

### 8.2 $X(z)=\dfrac{1}{z+1.2}$: Dönüşümden İşarete

Bu kez dönüşüm verilip işaretin davranışı isteniyor. İfadeyi $z^{-1}$'li hâle getirmek gerekir, çünkü dönüşümün kendisinde $z^{-1}$'li terimler vardır. $z$'li biçim yalnızca bir kolaylıktı, bir adım geri gelmek için pay ve paydayı $z^{-1}$ ile çarparız:

$$X(z)=\frac{z^{-1}}{1+1.2z^{-1}}$$

$\dfrac{1}{1+1.2z^{-1}}$ terimi, $a=-1.2$ için $(-1.2)^n u[n]$'in dönüşümüdür. Payda kalan $z^{-1}$ ise bir birim gecikmedir. Sonuç:

$$x[n]=(-1.2)^{n-1}u[n-1]$$

Değerleri sırayla yazalım:

- $x[0]=0$
- $x[1]=1$
- $x[2]=-1.2$
- $x[3]=1.44$
- $x[4]=-1.728$

İşaret bir pozitif bir negatif değer alır. Hocanın dediği gibi ters dönüşüm bile çok zor değildir.

<!-- BELİRSİZ: 00:39:25'te ifadenin ilk yazımı altyazıda "bir bölü z çarpı bir bölü iki ters" diye bozuk. 1/(z+1.2) biçimi kısa nottan ve aynı satırlardaki "1.2 z üzeri eksi 1", 1.44, 1.728 değerlerinden alındı. -->

> **Ek bilgi (derste anlatılmadı):** Bu işaretin genliği büyür, çünkü kutup $z=-1.2$'dedir ve birim çemberin dışındadır. Nedensel bir sistemde bütün kutupların birim çemberin içinde olması, kararlılığın şartıdır. Dersin başında sıfır ve kutupların kararlılığı incelemeye yaradığı söylenmişti, bağlantı buradadır.

## 9. Sistem Fonksiyonu ve FIR Filtre

### 9.1 Terimler

Hoca yeni bir terim tanıttı. Şimdiye kadar aynı şey için farklı adlar kullandık:

- Konvolüsyon kısmında: impuls cevabı (impulse response)
- Fourier dönüşümünde: frekans cevabı (frequency response)
- Laplace'ta: transfer fonksiyonu (transfer function)
- z-dönüşümünde: sistem fonksiyonu (system function)

**Soru:** $x$ değişkenini genelde ne için kullanırız? **Cevap:** Bir sisteme giren işaret için. Genelde $x$ girişi, $y$ çıkışı, $h$ ise sistemin ne olduğunu gösterir. Bu yüzden derste hep $h(t)$, $h[n]$, $H(\omega)$, $H(s)$ ve $H(z)$ yazdık. $H(z)$'ye sistem fonksiyonu deriz.

### 9.2 Fark Denklemi

Burada, Fourier dönüşümündekine benzer şekilde katsayılarla çalışırız. Girişin belli miktarda ötelenmiş hâlleri katsayılarla çarpılıp toplanır:

$$y[n]=\sum_k b_k\,x[n-k]$$

Buna fark denklemi (difference equation) denir.

> **Hocanın vurgusu:** Diferansiyel denklemleri Laplace dönüşümüyle nasıl çözüyorsak, fark denklemlerini de z-dönüşümüyle öyle çözeceğiz.

Bu denklem bize konvolüsyonun tanımını hatırlatır. Konvolüsyonda değişkeni $n$'den $k$'ya çeviriyor, $k$ düzleminde işareti ters çeviriyor (flip) ve $n$ kadar öteliyorduk. Sistem fonksiyonu da aynı ilişkiyi z düzleminde verir.

### 9.3 FIR Filtre Örneği

Katsayıları $b_k=\{6,-5,1\}$ olan filtreyi ele alalım:

$$y[n]=6x[n]-5x[n-1]+x[n-2]$$

Sistem girişi ve girişin ötelenmiş hâllerini bu katsayılarla çarpar. $6$, $n=0$ noktasının katsayısıdır. $-5$ bir birim, $1$ iki birim ötelenmiş terime aittir. Üsleri buna göre yazarsak:

$$H(z)=6-5z^{-1}+z^{-2}$$

## 10. Birim Gecikme

Bir sisteme giriş olarak $x[n]$ verilsin ve sistem bir birim geciktirme uygulasın:

$$y[n]=x[n-1]$$

Bu sistemin impuls cevabı $n=1$ noktasında $1$ veren bir dürtüdür. Bu dürtünün z-dönüşümü $z^{-1}$'dir. Yani birim gecikmenin sistem fonksiyonu $H(z)=z^{-1}$'dir ve $Y(z)=z^{-1}X(z)$ olur. İki birim gecikme için $z^{-2}$, üç birim için $z^{-3}$ yazılır.

### 10.1 Polinomla Hesap

Giriş $x[n]=\{3,1,4,1,5,9\}$ olsun, $n=0$'dan başlasın:

$$X(z)=3+z^{-1}+4z^{-2}+z^{-3}+5z^{-4}+9z^{-5}$$

$z^{-1}$ ile polinom çarpması yaparsak:

$$Y(z)=z^{-1}X(z)=3z^{-1}+z^{-2}+4z^{-3}+z^{-4}+5z^{-5}+9z^{-6}$$

Slaytta sonucun başına bir de $0\cdot z^{0}$ terimi yazılmıştır. Çünkü ilk terim artık $z^{-1}$'dir, yani $n=1$'dedir. Bize $n=0$ noktası da lazımdır ve o noktadaki katsayı sıfırdır.

### 10.2 $z^{0}$ Terimi Neden Yazılıyor?

Hoca bunu önce bir hatırlatmayla açıkladı. $\delta[n+1]$'in dönüşümünü alalım. Dürtü yalnız $n=-1$'de birdir, orada $z^{-n}=z^{+1}$ olur:

$$\delta[n+1]\leftrightarrow z^{+1}$$

Şimdi işaretin $n=-1$ noktasında katsayısı $1$ olan bir değeri, yani $1\cdot z^{+1}$ terimi olduğunu varsayalım. Bir birim gecikme uygularsak $z^{-1}\cdot z^{+1}=z^{0}$ olur. Terim $n=0$ noktasına kayar ve orada $1$ değeri elde edilir. Bizim örneğimizde işaret doğrudan sıfırdan başladığı için $n=0$ noktasına gelen bir şey yoktur, orada sıfır vardır.

> **Hocanın vurgusu:** Birim gecikme uygularken $n=0$ noktasını hatırlamak gerekir, bu bazen unutulabiliyor. Sonucu çizerken $n=0$'da sıfır, $n=1$'de $3$ gösterip devam edeceğiz.

## 11. Konvolüsyonun Polinom Çarpımıyla Hesaplanması

Bir giriş işareti ve bir sistem verilsin, çıkış isteniyor.

**Soru:** $y[n]$ nasıl hesaplanır? **Cevap:** Konvolüsyonla. Fakat bu uzun bir iştir. Laplace ve Fourier dönüşümlerinde olduğu gibi z-dönüşümünde de bu işlem çarpmayla yapılır: İki işaretin z-dönüşümü alınır, polinom olarak çarpılır, sonra ters dönüşüm uygulanır.

> **Ders sonrası not:** Hocanın 00:49:38'deki cümlesi altyazıda "x konvolüsyon y" diye geçiyor. Çıkışı veren işlem $y[n]=x[n]*h[n]$'dir.

Slayttaki örnek şöyledir:

$$x[n]=\{1,2,3,4\},\qquad h[n]=\{0,1,-1,1,-1\}$$

Burada $h[n]$ bir FIR filtredir. Filtrenin $z^{0}$ katsayısı sıfırdır, yalnız belirtmek için yazılmıştır. Konvolüsyon ile filtre uygulamak arasında fark yoktur. Dönüşümler, katsayılar olduğu gibi yazılarak bulunur:

$$X(z)=1+2z^{-1}+3z^{-2}+4z^{-3}$$

$$H(z)=z^{-1}-z^{-2}+z^{-3}-z^{-4}$$

Konvolüsyon özelliğinin ispatı uzundur, hoca ona girmedi: Tanım yerine konursa doğrudan $H(z)X(z)$ çarpımına gelinir. Bu çarpım, bir polinom çarpmasından farksızdır. Terimleri sırayla dağıtalım (ara adım eklendi):

- $1\cdot H(z)=z^{-1}-z^{-2}+z^{-3}-z^{-4}$
- $2z^{-1}\cdot H(z)=2z^{-2}-2z^{-3}+2z^{-4}-2z^{-5}$
- $3z^{-2}\cdot H(z)=3z^{-3}-3z^{-4}+3z^{-5}-3z^{-6}$
- $4z^{-3}\cdot H(z)=4z^{-4}-4z^{-5}+4z^{-6}-4z^{-7}$

Aynı üslü terimleri toplarsak:

$$Y(z)=z^{-1}+z^{-2}+2z^{-3}+2z^{-4}-3z^{-5}+z^{-6}-4z^{-7}$$

$z^{0}$ terimi yoktur, yani $y[0]=0$'dır. Üsleri ve katsayıları okuyarak sonucu doğrudan buluruz:

$$y[n]=\{0,1,1,2,2,-3,1,-4\}\qquad (n=0\text{'dan başlar})$$

Adım adım kaydırarak yapılan konvolüsyon da aynı sonucu verir.

## 12. Seri Bağlı Sistemler

Aradan sonra hoca seri bağlı (cascade) sistemleri hatırlattı. Doğrusal ve zamanla değişmez olma şartıyla, seri bağlı sistemlerin sıralaması önemli değildir. Önce $H_1$'e sonra $H_2$'ye girmek ile tersi aynı sonucu verir, çünkü $h_1$ ile $h_2$'nin konvolüsyonunu alınca $x[n]$'den $y[n]$'ye doğrudan geçebiliriz.

z-dönüşümündeki karşılığı daha basittir: Her sistemin dönüşümü alınır ve çarpılır. Çarpım, $x[n]$ ile $y[n]$ arasındaki eşdeğer sistem fonksiyonudur:

$$H(z)=H_1(z)H_2(z)$$

Örnek olarak şu iki sistemi seri bağlayalım:

$$v[n]=x[n]-x[n-1]\quad\Rightarrow\quad H_1(z)=1-z^{-1}$$

$$y[n]=v[n]+v[n-1]\quad\Rightarrow\quad H_2(z)=1+z^{-1}$$

Biri çıkarıyor, biri topluyor. Çarparsak:

$$H(z)=(1-z^{-1})(1+z^{-1})=1-z^{-2}$$

Bunu fark denklemine geri yazarsak $y[n]=x[n]-x[n-2]$ olur: Sistem girişi doğrudan alır ve girişin iki birim ötelenmiş hâlini çıkarır.

## 13. Frekans Cevabı, Sıfırlar ve Kutuplar

### 13.1 z Düzleminden Frekans Düzlemine

z-dönüşümü Fourier dönüşümünün genel hâli olduğu için, $z=re^{j\omega}$ içinde $r=1$ kabul edip $z=e^{j\omega}$ yazarsak frekans cevabına geçeriz:

$$H(e^{j\omega})=H(z)\Big|_{z=e^{j\omega}}$$

Elimizde $z$'ye bağlı bir ifade varsa ve frekans cevabı isteniyorsa, $z$ yerine $e^{j\omega}$ yazmak yeterlidir. Katsayılar aynı kalır. Üç düzlem ($n$, $z$, $\omega$) arasında geçiş bu sayede kolaydır. Hoca slayttaki alçak geçiren (low-pass) filtre tanımını örnek gösterdi: Belli frekansların bastırılması ve filtre uzunluğunun tutulması gibi şartlar verilir. Polinom yazımıyla işaret işleme uygulamaları yapan araçlar olduğunu da belirtti.

<!-- BELİRSİZ: 01:06:57-01:07:16 arasında alçak geçiren filtre örneğinin ayrıntıları ve "z-polynom" araçları slaytta kalmış, altyazıda açık değil. -->

### 13.2 Sıfırlar ve Kutuplar

z-dönüşümünde bir pay ve bir payda varsa, $H(z)=\dfrac{B(z)}{A(z)}$ gibi, payı sıfır yapan noktalar sistemin sıfırları (zeros), paydayı sıfır yapan noktalar ise kutupları (poles) verir. Kutuplar $H(z)$'nin sonsuza gittiği noktalardır. Laplace'ta bunları $s$ düzleminde görmüştük. z düzlemi de karmaşıktır. Sıfırlar ve kutuplar bu düzlemde farklı işaretlerle gösterilir: sıfır "o", kutup "x" ile.

<!-- BELİRSİZ: Altyazıda (01:09:16) gösterim yalnız "şu şekilde, bu şekilde" diye geçiyor. "o" ve "x" sembolleri kısa nottan alındı. Pay ve payda adları da altyazıda okunmuyor (01:08:08); B(z)/A(z) gösterimi kısa nottandır. -->

Örnek: $H(z)=1-\frac12 z^{-1}$. Doğrudan sıfıra eşitlemek biraz zor gelebilir. Hoca, ifadeyi $z$ ile çarpıp $z$ ile bölmeyi gösterdi. Değer değişmez, ama üsler pozitif olur:

$$H(z)=\frac{z-\frac12}{z}$$

Pay sıfır olunca $z=\frac12$ bulunur, yani sistemin $\frac12$ noktasında bir sıfırı vardır. Payda da $z=0$'da bir kutup verir (ara adım eklendi).

### 13.3 Üç Sıfırlı FIR Filtre

Hoca aynı konuyu üç sıfırlı bir örnekle sürdürdü. Filtre katsayıları $\{1,-2,2,-1\}$'dir. FIR filtrelerde işareti bu katsayılarla çarpıp topladığımızı hatırlattı.

> **Ders sonrası not:** Hoca bu işlemi "ortalamasını almak" diye andı. Bu filtrede katsayıların toplamı $1-2+2-1=0$'dır. Bu yüzden işlem bir ortalama değil, ağırlıklı toplamdır.

$$H(z)=1-2z^{-1}+2z^{-2}-z^{-3}=\frac{z^3-2z^2+2z-1}{z^3}$$

Pay çarpanlarına ayrılırsa (ara adım eklendi):

$$z^3-2z^2+2z-1=(z-1)(z^2-z+1)$$

Köklerden biri $z=1$, diğer ikisi karmaşık eşleniktir: $z=e^{\pm j\pi/3}=\frac12\pm j\frac{\sqrt3}{2}$. Toplam üç sıfır vardır. Hepsinin büyüklüğü birdir, yani üçü de birim çember üzerindedir. Kutuplara bakınca, payda $z^3$ olduğu için $z=0$ noktasında üç katlı kutup vardır.

<!-- BELİRSİZ: 01:09:22-01:10:17 arasında incelenen H(z) altyazıda yazılmıyor. "Bir kökü 1, ikisi karmaşık, z=0'da üç katlı kutup" anlatımı {1,-2,2,-1} filtresine uyduğu için aynı örnek kabul edildi. -->

$z=e^{j\omega}$ yazıldığında yalnız $\omega$ değişir, $j$ ve $e$ sabittir. $\omega$ değiştikçe $e^{j\omega}$ yarıçapı bir olan birim çemberi dolaşır. Çemberde bir sıfırın üzerinden geçilen frekansta genlik sıfıra iner. Bu filtrede $\omega=0$ ve $\omega=\pm\pi/3\approx\pm1.05$ rad'da $|H(e^{j\omega})|=0$ olur.

> **Ders sonrası not:** Hoca, "sıfırları eksi 1'de, 0'da ve 1 noktasında" dedi. Bunlar, genlik grafiğinin yatay eksenindeki yaklaşık $\omega$ değerleridir ($\omega\approx-1.05,\ 0,\ 1.05$ rad). $H(z)$'nin sıfırları ise $z=1$ ve $z=e^{\pm j\pi/3}$'tür. Ayrıca hoca, $r$ farklı olursa "birim çember genişler" dedi. Yarıçapı birden farklı olan çember artık birim çember değildir, yalnızca yarıçapı $r$ olan bir çemberdir.

### 13.4 Sinüzoidal Girişe Cevap

Slayttaki bir başka örnekte sistem fonksiyonunda $z$ yerine $e^{j\omega}$ yazılarak frekans cevabı bulunuyor, sonra sisteme karmaşık üstel bir giriş veriliyor. Çıkış, çarpma işlemiyle elde edilir, çünkü Fourier dönüşümünde de konvolüsyon yerine çarpma özelliği vardır. Çarpım sıfıra eşitlenirse sistemin sıfırları görülür. Faz grafiği de vardı, ama hoca fazla şimdilik çok ilgilenmeye gerek olmadığını söyledi.

<!-- BELİRSİZ: 01:12:20-01:13:41 arasında slayttaki H(z), giriş işareti ve sonuç altyazıda okunmuyor ("e üzeri j p p p p bölücü"). Bu yüzden sayısal adımlar verilemedi. -->

## 14. IIR Filtreye Kısa Bakış

> **Hocanın vurgusu:** Bu kısım daha çok sinyal işleme konusudur, ayrıntısına girilmeyecek ve sınavda buradan soru sorulmayacak.

Şimdiye kadar gördüğümüz filtrelerde yalnız giriş terimleri vardı. IIR filtrede ise sistemin kendi önceki çıkış değeri de hesaba katılır. Bu katsayılara geri besleme (feedback) katsayıları denir. Slayttaki örnek şöyledir:

$$y[n]=0.8\,y[n-1]+3x[n]-2x[n-1]$$

MATLAB'de `filter` komutuna giriş ve çıkış katsayıları verilir. Giriş katsayıları $3$ ve $-2$, çıkış katsayıları $1$ ve $-0.8$'dir. $xx$ ise giriş vektörüdür:

```matlab
b = [3 -2];      % giriş katsayıları
a = [1 -0.8];    % çıkış (geri besleme) katsayıları
y = filter(b, a, xx);
```

Filtre, değerleri sırayla hesaplar: önce $y[0]$, sonra $y[1]$, $y[2]$, $y[3]$, $y[4]$. Hoca bunun konvolüsyona çok benzediğini, ama sonucun frekans düzleminden ya da z-dönüşümünden rahatça elde edilebileceğini söyledi. Denklemin iki tarafının dönüşümü alınırsa sistem fonksiyonu bulunur (ara adım eklendi):

$$H(z)=\frac{Y(z)}{X(z)}=\frac{3-2z^{-1}}{1-0.8z^{-1}}$$

<!-- BELİRSİZ: Slayttaki xx giriş değerleri ve y[0]-y[4] sonuçları altyazıda geçmiyor. Fark denkleminin kendisi de kısa nottan alındı; altyazıda yalnız katsayılar var (01:14:43). -->

$H(z)$ elde edilirken çok kullanılan özellik yine geometrik seridir: $\sum_{n=0}^{\infty}r^n=\frac{1}{1-r}$. En genel hâliyle ifade şöyle görülür:

$$\frac{b_0}{1-a_1 z^{-1}}$$

Burada $a_1$ yerine herhangi bir sayı gelebilir. Örneğin $a_1=2$ ve $b_0=1$ için $\dfrac{1}{1-2z^{-1}}$ biçimi karşımıza çıkar.

## 15. Sol Taraflı İşaret: $a^n u[-n-1]$

Hoca, $a^n u[n]$'i bulmuştuk diyerek ikinci temel işarete geçti:

$$x[n]=a^n u[-n-1]$$

Dönüşümü ve yakınsaklık bölgesini arıyoruz.

**Soru:** Bu toplam hangi aralıkta sonuç verir? **Cevap:** $u[-n-1]$'in içi sıfır ya da pozitif olmalıdır. Yani $n$, eksi sonsuzdan gelir ve en son $-1$'e kadar gider.

$$X(z)=\sum_{n=-\infty}^{-1} a^n z^{-n}=\sum_{n=-\infty}^{-1}\left(az^{-1}\right)^n$$

Hoca önce $(a^{-1}z)^{-n}$ düzenlemesine girdi, sonra "bir adım geri alıyorum" diyerek daha kolay olan yolu seçti. Eksi sonsuzdan $-1$'e toplamı hesaplamak zordur. Bunun yerine sınırları değiştirip artı birden artı sonsuza gideriz. Sınırlar yer değişince işaretler de değişir, yani üs $-n$ olur. $m=-n$ yazarsak (ara adım eklendi):

$$X(z)=\sum_{m=1}^{\infty}\left(az^{-1}\right)^{-m}=\sum_{m=1}^{\infty}\left(a^{-1}z\right)^{m}$$

Bu toplam sıfırdan başlasaydı formüle çok benzerdi. O hâlde sıfırdan sonsuza toplamı yazar, $m=0$ terimini çıkarırız. O terimin değeri $\left(a^{-1}z\right)^{0}=1$'dir, tek bir değer olduğu için toplam sembolüne gerek yoktur:

$$X(z)=\sum_{m=0}^{\infty}\left(a^{-1}z\right)^{m}-1=\frac{1}{1-a^{-1}z}-1$$

Serinin toplanabilmesi için $|a^{-1}z|<1$ gerekir. Buradan ROC çıkar:

$$|z|<|a|$$

Şimdi ifadeyi sadeleştirelim. $1-a^{-1}z=1-\dfrac{z}{a}=\dfrac{a-z}{a}$ olduğu için:

$$X(z)=\frac{a}{a-z}-1=\frac{a-(a-z)}{a-z}=\frac{z}{a-z}$$

ROC, yarıçapı $|a|$ olan çemberin içidir.

Hoca, "dönüşüm aslında aynı, ayırt ediciliği region of convergence sağlıyor" dedi.

> **Ders sonrası not:** İki dönüşüm tam olarak aynı değildir, aralarında işaret farkı vardır: $a^n u[n]\leftrightarrow\dfrac{z}{z-a}$ ($|z|>|a|$) iken $a^n u[-n-1]\leftrightarrow\dfrac{z}{a-z}=-\dfrac{z}{z-a}$ ($|z|<|a|$). Aynı ifadeyi veren çift $-a^n u[-n-1]$'dir. Hocanın asıl vurgusu ise doğrudur: Aynı cebirsel ifade iki farklı işarete karşılık gelebilir, ayırt eden ROC'tur.

**Soru:** En son bulduğumuz sonuç sıfırdan sonsuza olan toplam mı, birden sonsuza olan toplam mı? **Cevap:** Formülü sıfırdan sonsuza toplam için yazdık, ama işaretin kendi değerlerinin olduğu noktalara göre bulduk. Sıfır noktasındaki terimi çıkarmak, zaten birden sonsuza kadar olan kısmı bulmak demektir.

## 16. İki Terimli İşaret ve ROC Kuralı

Bu kez iki farklı bileşen içeren bir işaret alalım:

$$x[n]=7\left(\frac13\right)^n u[n]-6\left(\frac12\right)^n u[n]$$

Her terim için $a^n u[n]$ sonucu kullanılır. Katsayılar başa yazılır:

$$X(z)=\frac{7}{1-\frac13 z^{-1}}-\frac{6}{1-\frac12 z^{-1}}$$

Payda eşitlenir. Pay $7\left(1-\frac12 z^{-1}\right)-6\left(1-\frac13 z^{-1}\right)=1-\frac32 z^{-1}$ olur (ara adım eklendi). Pay ve payda $z^2$ ile çarpılırsa:

$$X(z)=\frac{z\left(z-\frac32\right)}{\left(z-\frac12\right)\left(z-\frac13\right)}$$

> **Ders sonrası not:** Hoca bu sonucu "6 ve 7 dışarıda kalırsa" diye okudu. Payda eşitlenince $6$ ve $7$ payın içine girer, dışarıda çarpan kalmaz. Yukarıdaki ifade katsayısız hâliyle tam sonuçtur.

İfadenin iki noktada kutbu vardır: $\frac12$ ve $\frac13$. ROC hangisine göre belirlenir?

**Soru:** Laplace dönüşümünde sağ taraflı işaretlerde ROC neredeydi? **Cevap:** (Bir öğrenci: "En büyük değil, sağında.") En büyük kutbun sağındaydı.

Burada da işaret sağ taraflıdır, ama bir dizi olduğu için z düzleminde "sağ" ve "sol" yoktur, çember vardır. "Sağında" ifadesi "büyüğü" anlamına gelir. Çemberden büyük olmak da çemberin dışında olmaktır. Kural şöyledir:

- **Sağ taraflı işaret:** ROC, en büyük kutbun tanımladığı çemberin dışındadır.
- **Sol taraflı işaret:** ROC, en küçük kutbun tanımladığı çemberin içindedir.

Örneğimizde iki terim de sağ taraflıdır ve en büyük kutup $\frac12$'dir:

$$\text{ROC}:\ |z|>\frac12$$

Bu bölge birim çemberi içerir. Hoca birim çemberi kutupların tanımladığı iki iç çemberle birlikte çizdi. Çemberlerin gerçek eksenle kesiştiği noktalar $\frac12$ ve $\frac13$'tür. İşaret sol taraflı olsaydı iç kısım dahil edilecekti.

> **Ek bilgi (derste anlatılmadı):** ROC'un birim çemberi içermesi, $r=1$ için toplamın yakınsadığı anlamına gelir. Bu durumda işaretin DTFT'si vardır ve $z=e^{j\omega}$ yazılması geçerlidir.

> **Ek bilgi (derste anlatılmadı):** Hoca ROC'un birim çemberin içi ya da dışı olabileceği gibi "iki nokta arasında" da olabileceğini söyledi. Bu durum, işaretin hem sağ hem sol taraflı bileşen içermesiyle ortaya çıkar. Sağ taraflı kısmın ROC'u bir çemberin dışı, sol taraflı kısmın ROC'u daha büyük bir çemberin içi olduğunda ikisinin kesişimi bir halkadır. Bu iki şart çakışmazsa dönüşüm yoktur.

## 17. z-Dönüşümünün Özellikleri

### 17.1 Yarım Kalan Örnek: $2^n u[n]$

Hoca özelliklere geçmeden önce $2^n u[n]$ işaretini ve ROC'unu sormaya başladı. Tanımı yazdı, toplamı $\sum_{n=0}^{\infty}\left(2z^{-1}\right)^n$ biçimine getirdi. Ardından "soruyu yanlış yazmışım, burada farklı bir özellik çıkıyordu" deyip örneği bıraktı.

> **Ders sonrası not:** Yazılan işaret için sonuç, genel formülde $a=2$ alınarak bulunur: $2^n u[n]\leftrightarrow\dfrac{z}{z-2}$, ROC: $|z|>2$. Hocanın aslında hangi işareti kastettiği altyazıdan anlaşılmıyor.

### 17.2 Doğrusallık (Linearity)

$$a\,x_1[n]+b\,x_2[n]\ \leftrightarrow\ a\,X_1(z)+b\,X_2(z)$$

Dönüşüm doğrusal olduğu için bu özellik sağlanır. ROC önemlidir: İlk işaretin ROC'una $R_1$, ikincisine $R_2$ diyelim. Toplamın ROC'u en az $R_1\cap R_2$ kesişimini içerir.

### 17.3 Zamanda Öteleme (Time Shifting)

Bunu daha önce görmüştük: $k$ kadar kayma, $z^{-k}$ ile çarpma demektir.

$$x[n-k]\ \leftrightarrow\ z^{-k}X(z)$$

### 17.4 Zamanda Tersleme (Time Reversal)

$$x[-n]\ \leftrightarrow\ X(z^{-1})$$

$X(z)$'nin ROC'u $R$ ile tanımlı bir alandaysa, $X(z^{-1})$'in ROC'u $1/R$ ile tanımlı bir alandadır.

### 17.5 Konvolüsyon

$$x[n]*y[n]\ \leftrightarrow\ X(z)\,Y(z)$$

Konvolüsyon, dönüşümlerin polinom çarpımıyla yapılır.

### 17.6 Zamanda Fark (Difference in Time)

Sürekli zamandaki türevin ayrık karşılığı burada farktır. $x[n]$'nin türevi, bir değerden bir öncekini çıkarıp $n$ ile $n-1$ arasındaki farka bölmek demektir. Bu fark $n-(n-1)=1$ olduğu için payda birdir:

$$x[n]-x[n-1]$$

Yani dizinin bir önceki elemanını çıkararak türev almış oluruz. z-dönüşümünde birinci terim $X(z)$, ikinci terim $z^{-1}X(z)$ olur:

$$x[n]-x[n-1]\ \leftrightarrow\ \left(1-z^{-1}\right)X(z)$$

### 17.7 z Düzleminde Türev

Bu kez işlem z düzlemindedir: $n$ ile çarpmak, z düzleminde türev almanın karşılığıdır. Ancak işaret farkı vardır, türev $-z$ ile çarpılır:

$$n\,x[n]\ \leftrightarrow\ -z\frac{dX(z)}{dz}$$

ROC aynı kalır.

<!-- BELİRSİZ: Altyazıda (01:34:48) zaman tarafındaki çarpan "bir şeyle çarpmak" diye geçiyor; n ile çarpma hocanın yazdığı -z dX/dz karşılığından ve kısa nottan alındı. Hoca başlığı "difference in z-domain" diye okudu; işlem türevdir. -->

### 17.8 Başlangıç ve Son Değer Teoremleri

Laplace'taki teoremlerin z düzlemindeki karşılıkları da vardır. Burada $x[n]$ nedensel olmalıdır, yani $n<0$ için $x[n]=0$ şartı vardır.

$$x[0]=\lim_{z\to\infty}X(z)$$

$$\lim_{n\to\infty}x[n]=\lim_{z\to 1}\left(1-z^{-1}\right)X(z)$$

Son değer teoremi biraz farklıdır: $X(z)$ doğrudan alınmaz, önce $1-z^{-1}$ ile çarpılır, sonra $z$ yerine $1$ konur.

> **Ders sonrası not:** Hoca son değer teoremi için kutup şartını söylemedi. Teorem, $\left(1-z^{-1}\right)X(z)$'nin bütün kutupları birim çemberin içindeyse geçerlidir. Örneğin $2^n u[n]$ için $\left(1-z^{-1}\right)\frac{z}{z-2}=\frac{z-1}{z-2}$ ifadesi $z=1$'de $0$ verir, oysa işaret sonsuza gider. Burada $z=2$ kutbu çemberin dışındadır, teorem uygulanamaz.

Hoca, bu konunun sinyal işleme dersinde daha ayrıntılı anlatıldığını söyledi.

## 18. Birim Basamak Cevabı ve Fark Denklemleri

### 18.1 Slaytlardaki Diğer Örnekler

Slaytlarda farklı FIR filtreler ve z-dönüşümüyle modellenebilen başka örnekler vardır. Bunlar doğrudan toplam sembolüne konarak yazılabilir, hızlıca incelenebilir.

Bir sistemin birim basamak cevabı (step response) da böyledir. Basamak işareti $u[n]$'dir. Sisteme giriş olarak bunu verince çıkışı normalde konvolüsyonla buluruz. z-dönüşümüyle daha kolaydır: İki dönüşüm çarpılır ve sonuç elde edilir.

Bir fark denklemi, sistemi tanımlayan bir eşitliktir. $Y(z)$'nin $X(z)$'ye oranı sistem fonksiyonunu verir. $y[n]$'nin dönüşümü $Y(z)$'dir. Birim gecikmeli terim $z^{-1}Y(z)$ olur, önünde $0.8$ varsa $0.8z^{-1}Y(z)$ yazılır. $x[n]$'nin dönüşümü $X(z)$'dir. Bunlar programla, örneğin MATLAB ile de yapılabilir.

<!-- BELİRSİZ: 01:38:49-01:39:31 arasındaki slayt denklemi tam okunmuyor. Terimlerin işareti altyazıda yok. -->

### 18.2 Ters z-Dönüşümü Hakkında

Ters z-dönüşümü, Laplace'taki gibi kontür integraliyle tanımlanır. Bu integrali doğrudan hesaplamak biraz zordur. Onun yerine, Laplace'ta olduğu gibi z-dönüşümü tablolarından ve özelliklerden faydalanarak sonucu bulacağız. Kısmi kesirlere açılım da aynı şekilde yapılır. Hoca ters dönüşüm ayrıntısını sonraya bıraktı.

### 18.3 Fark Denklemi Örneği

Kitaptan alınan örnekte sistem şöyle tanımlıdır:

$$y[n]-\frac12 y[n-1]=x[n]$$

Soruda giriş olarak $\left(\frac13\right)^n$ verilirse sistemin nasıl çalışacağı soruluyor. Bu denklemin z-dönüşümünü alarak problem daha hızlı çözülür. Zaman düzleminde $y[n-1]$'i bilmiyoruz ve konvolüsyon yapmak zordur.

Terim terim dönüşüm alalım. $y[n]$, $Y(z)$ olur. $y[n-1]$ ise birim gecikme olduğu için $z^{-1}Y(z)$ olur. $x[n]$, $X(z)$ olur:

$$Y(z)-\frac12 z^{-1}Y(z)=X(z)$$

Hoca burada, kullandığımız dönüşümün çift taraflı (bilateral) olduğunu söyledi. Tek taraflı dönüşümde Laplace'taki gibi bazı terimleri ayrıca çıkarmak gerekirdi, ama burada gerek yoktur.

> **Ek bilgi (derste anlatılmadı):** Tek taraflı z-dönüşümü $\sum_{n=0}^{\infty}x[n]z^{-n}$ ile tanımlanır. Bu tanımda gecikme özelliği $x[n-1]\leftrightarrow z^{-1}X(z)+x[-1]$ olur. Hocanın söz ettiği "çıkarılan terimler" bu başlangıç koşulu terimleridir.

$Y(z)$ ortak parantezine alınır:

$$Y(z)\left(1-\frac12 z^{-1}\right)=X(z)$$

İki taraf $1-\frac12 z^{-1}$'e bölünürse sistem fonksiyonu bulunur:

$$H(z)=\frac{Y(z)}{X(z)}=\frac{1}{1-\frac12 z^{-1}}$$

Bunun ters dönüşümü $h[n]$'dir. $a^n u[n]$ çiftinden $h[n]=\left(\frac12\right)^n u[n]$ çıkar (ara adım eklendi).

Girişe gelince, $x[n]$'nin z-dönüşümü alınıp bu ifadeyle çarpılır. Hoca bunu çalışma sorusu olarak bıraktı.

> **Ders sonrası not:** Çalışma sorusunun çözümü, girişi $x[n]=\left(\frac13\right)^n u[n]$ alarak şöyledir. $Y(z)=\dfrac{1}{\left(1-\frac12 z^{-1}\right)\left(1-\frac13 z^{-1}\right)}$. Kısmi kesirlerle $Y(z)=\dfrac{3}{1-\frac12 z^{-1}}-\dfrac{2}{1-\frac13 z^{-1}}$ bulunur. Sonuç: $y[n]=\left[3\left(\frac12\right)^n-2\left(\frac13\right)^n\right]u[n]$.

<!-- BELİRSİZ: Altyazıda (01:42:31) giriş yalnız "1 bölü 3 üzeri n" diye geçiyor, u[n] söylenmiyor. u[n] kısa nottan alındı. -->

Hoca ayrıca, sistemlerin blok diyagramlarından da bu tür denklemlerin elde edildiğini, oradan $H(z)$ bulunup çözüm yapılabildiğini söyledi. Bu konunun sinyal işleme dersinde anlatıldığını, burada o kadarına gerek olmadığını ekledi.

## 19. Kalan Slaytlar: Sıfır-Kutup ve Sinüzoidal Cevap

Hoca kalan slaytları hızlıca dolaştı. Sıfır ve kutuplarla ilgili çok örnek vardır: $H(z)$ verilir, sıfırları ve kutupları sorulur. Frekans cevabı için $z^{-1}$ yerine $e^{-j\omega}$ yazılır.

Frekans cevabının karesi alınarak işaretin hangi frekansları içerdiği incelenebilir. Hocaya göre kare almak negatif değerlerden kurtulmak içindir, ayrıca ifade karmaşık olduğu için de gereklidir. Bu şekilde frekans düzleminde pik veren noktalar görülür.

Slaytlarda birim çemberin neye karşılık geldiğine dair hatırlatmalar ve üç boyutlu gösterimler de vardır. Bir örnekte $H(z)$, $0.8$ noktası civarında pik verir: Kutup $0.8$ noktasındadır. Hoca, payı $1$ olduğu için bu sistemin sıfırı olmadığını söyledi.

> **Ders sonrası not:** Bu yorum, $H(z)$'nin yazılış biçimine bağlıdır. Slayttaki ifade $\dfrac{1}{1-0.8z^{-1}}$ ise, pozitif üslerle $\dfrac{z}{z-0.8}$ olur ve $z=0$'da bir sıfırı vardır. Slaytta hangi biçimin yazıldığı altyazıda okunmuyor.

Sinüzoidal cevap örneklerinde $H(z)$ ve giriş verilip çıkış isteniyor. Yöntem şudur: Girişin z-dönüşümü bulunur, $H(z)$ ile çarpılır, sonucun ters z-dönüşümü alınır. Elde edilen $y[n]$, $x[n]$ girişi uygulandığında sistemin gösterdiği davranıştır.

> **Ders sonrası not:** Hoca bir yerde sırayı "önce ters dönüşüm, sonra çarpım" gibi anlattı. Doğrusu, önceki cümlesinde söylediği gibi önce çarpım, sonra ters dönüşümdür. Zaman düzleminde doğrudan çarpım değil, konvolüsyon geçerlidir.

Hocaya göre bu ders için buradaki temel şeyleri bilmek yeterlidir.

## Dersin Toparlaması

Ders, Laplace dönüşümünde ters dönüşüm almadan başlangıç ve son değeri bulmayı sağlayan teoremlerle başladı. Sonra aynı mantık ayrık zamana taşındı: Laplace, Fourier dönüşümünü nasıl genelleştiriyorsa z-dönüşümü de DTFT'yi öyle genelleştirir. $z=re^{j\omega}$ içindeki $r$, toplamı bastırır ve yakınsaklık bölgesini belirler. $r=1$ alındığında frekans cevabına geçilir. Sağ taraflı işaretlerde ROC en büyük kutbun çemberinin dışında, sol taraflı işaretlerde en küçük kutbun çemberinin içindedir. Aynı cebirsel ifadeyi veren işaretleri birbirinden ROC ayırır.

Dersin pratik mesajı, z-dönüşümünün işlemleri polinom işlemlerine indirmesidir. $z^{-k}$'nın üssü konumu, katsayısı genliği verir. Konvolüsyon polinom çarpımına, seri bağlı sistemler sistem fonksiyonlarının çarpımına, fark denklemleri de cebirsel denklemlere dönüşür. Hoca, ters z-dönüşümünü tablolar, özellikler ve kısmi kesirlerle ele alacaklarını ve bu kısma sonraki oturumda devam edeceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
