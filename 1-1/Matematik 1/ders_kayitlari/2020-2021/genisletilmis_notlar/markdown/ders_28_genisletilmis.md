# Ders 28 Genişletilmiş Notu: Final Öncesi Soru Çözümü ve tan(x/2) Dönüşümü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Amacı: Final Mazeret Sınavı Soruları
- 2. Dönme Ekseni Bilinmeyen Hacim Sorusu (Soru 3)
- 3. Sınırsız Bölgenin Döndürülmesi: $y=\ln x$, $x=0$, $y=b$
- 4. Daha Önce Çözülen Soru Tipleri: Tek Fonksiyon, L'Hôpital, Temel Teorem
- 5. Kabuk Yöntemiyle Hacim İntegrali (Soru 10)
- 6. Riemann Toplamından Belirli İntegrale (Soru 11)
- 7. Zincir Kuralı Sorusu
- 8. Has Olmayan İntegral İçin Yorum Sorusu (Soru 15)
- 9. Yay Uzunluğu (Soru 17)
- 10. Trigonometrik Dönüşüm (Soru 18)
- 11. Parabol Altındaki Bölgenin Farklı Eksenler Etrafında Döndürülmesi
- 12. Ekstremum: Parçacığın En Büyük Hızı
- 13. Yeni Bir Dönüşüm: $\tan\frac{x}{2}=t$
- 14. Finalde Hangi Konular Ağırlıklı?
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Amacı: Final Mazeret Sınavı Soruları

Bu ders dönemin son dersidir. Hoca dersin tamamını final hazırlığına ayırdı. Ekranda bir önceki dönemin final mazeret sınavına ait çoktan seçmeli sorular vardı. Bu soruların bir kısmı daha önce birinci ve ikinci vize konuları işlenirken çözülmüştü. Hoca bu derste çözülmemiş olanlara odaklandı. Daha önce çözülenleri kısaca gösterip hangi konuya ait olduklarını söyleyerek geçti.

Hoca soruların zorluk düzeyi hakkında da bir yorum yaptı. Mazeret sınavlarında soruların biraz daha zor geldiğini, final sorularının ise genelde daha kolay olduğunu söyledi. Konuyu öğrenmiş biri için bu soruları "orta şeker" buluyordu.

Derste izlenen yöntem şuydu: Hoca soruyu ekranda gösterip okuyor, öğrencilere birkaç dakika çözmeleri için süre veriyor, sonra tablette birlikte çözüyordu. Bazı sorularda şıkları baştan göstermedi; şıklara bakmadan da sonucun bulunabileceğini düşünüyordu. Derste anlatılacak yeni konu olarak yalnız $\tan\frac{x}{2}=t$ dönüşümü kalmıştı. Hoca bunu dersin sonunda bir soru üzerinden anlattı.

<!-- BELİRSİZ: Soru metinleri ekrandaki sınav dosyasındaydı ve altyazıda yalnız sözlü kısmı var. Altyazıda tam okunmayan soru metinleri ve formüller aynı dersin kısa notundan (ekrandaki dosyadan alınmış) aktarıldı. -->

## 2. Dönme Ekseni Bilinmeyen Hacim Sorusu (Soru 3)

### 2.1 Soru

$R$ bölgesi $y=2-x^2$ parabolü, $y=x$ doğrusu ve $x=0$ doğrusu ($y$ ekseni) ile sınırlıdır. $R$ bölgesi $x=-b$ doğrusu etrafında döndürülüyor ve oluşan cismin hacmi $\dfrac{11\pi}{2}$ veriliyor. Amaç $b$'yi bulmaktır.

Hoca bunun alışılmış hacim sorularından farklı bir tip olduğuna dikkat çekti: Burada hacim verilmiş, bilinmeyen dönme ekseninin konumudur. Hacim integrali $b$'ye bağlı bir ifade verir. Bu ifade $\frac{11\pi}{2}$'ye eşitlenip $b$ çözülür.

### 2.2 Bölgenin Çizimi

Hoca önce bölgeyi çizmeyi önerdi. $y=2-x^2$ aşağı bakan bir paraboldür. $y=x$ orijinden geçen doğrudur. $x=0$ ise $y$ eksenidir. Bölge bu üç sınırın arasında, birinci bölgede kalan parçadır. Dönme ekseni $x=-b$ için $b$ pozitif olmalıdır. Yani eksen $y$ ekseninin solundadır.

Kesişim noktası iki denklemin ortak çözümünden bulunur:

$$2-x^2=x\;\Rightarrow\;x^2+x-2=0\;\Rightarrow\;(x+2)(x-1)=0$$

Bölgede $x\ge0$ olduğundan kesişim $x=1$'dir (çarpanlara ayırma ara adım eklendi). Bölge $0\le x\le1$ aralığındadır.

### 2.3 Hangi Yöntem?

Hoca "Hangi yöntem en iyisi?" diye sordu. Cevap kabuk yöntemi (shell method) oldu. Kabuk yönteminde bölgeyi tarayan çubuk dönme eksenine paralel olmalıdır. Dönme ekseni dikey ($x=-b$) olduğundan çubuk da dikeydir. Dikey çubuğun kalınlığı $dx$'tir, bu yüzden her şey $x$ cinsinden yazılır.

### 2.4 Kabuğun Boyutları

- **Kabuk yarıçapı (radius of shell):** Çubuğun dönme eksenine uzaklığıdır. Eksenden $y$ eksenine uzaklık $b$, $y$ ekseninden çubuğa uzaklık $x$'tir. Bölgede $x$ pozitif, $b$ de pozitif olduğundan yarıçap $b+x$ olur.
- **Kabuk yüksekliği (height of shell):** Çubuğun üst ucu her zaman $y=2-x^2$ üzerinde, alt ucu her zaman $y=x$ üzerindedir. Yükseklik üst uç eksi alt uçtur: $(2-x^2)-x$.
- **Kabuk kalınlığı:** $dx$.

Kabuk yöntemiyle hacim:

$$\frac{11\pi}{2}=2\pi\int_0^1(b+x)\,(2-x-x^2)\,dx$$

### 2.5 Hesabın Tamamlanması

Hoca tablette yer kalmadığını söyleyerek hesabın kalanını ödev bıraktı. Cevabın $2$ olacağını söyledi ve "bazen burada değişiklikler olabiliyor, hata olabilir, dikkat edin" diye ekledi. Hesap şöyle tamamlanır (ara adımlar eklendi):

$$\int_0^1(2-x-x^2)\,dx=2-\frac12-\frac13=\frac76,\qquad \int_0^1x(2-x-x^2)\,dx=1-\frac13-\frac14=\frac{5}{12}$$

$$2\pi\left(\frac{7b}{6}+\frac{5}{12}\right)=\frac{11\pi}{2}\;\Rightarrow\;\frac{7b}{6}+\frac{5}{12}=\frac{11}{4}\;\Rightarrow\;\frac{7b}{6}=\frac{28}{12}\;\Rightarrow\;b=2$$

Sonuç gerçekten $b=2$'dir.

## 3. Sınırsız Bölgenin Döndürülmesi: $y=\ln x$, $x=0$, $y=b$

### 3.1 Soru

Bölge $y=b$ yatay doğrusunun altında, $y=\ln x$ eğrisi ile $x=0$ doğrusu arasında kalan bölgedir. Bu bölge $y=b$ doğrusu etrafında döndürülüyor. Oluşan cismin hacmini veren integral hangisidir?

Hoca bu soruda şıkları önce göstermedi ve öğrencilerin verilen bilgileri şekil üzerinde göstermelerini istedi. Sonra şıkları açtı. Doğru cevabın B şıkkı olduğunu ve B şıkkına bakınca kabuk yönteminin daha avantajlı olduğunun anlaşıldığını söyledi.

> **Hocanın vurgusu:** Temel eğrilerin çizimi önemli. Logaritmik, üstel, parabolik ve trigonometrik eğrileri çizebilmeyi çalışın.

### 3.2 Bölge Sınırsız: Has Olmayan İntegral

$y=\ln x$ eğrisi $x\to0^+$ iken $-\infty$'a iner. Bu yüzden $y$ ekseni ile $\ln x$ eğrisi arasındaki bölge aşağı doğru sınırsızdır. Hoca bunu hemen fark etti: Bölge sınırsız olduğuna göre büyük olasılıkla has olmayan bir integral (improper integral) elde edilecektir.

### 3.3 Yatay Çubuk ve Tek İntegral

Dönme ekseni yatay ($y=b$) olduğundan kabuk yöntemi için çubuk yataydır. Hoca yatay çubuğa odaklanıp çok güzel bir duruma dikkat çekti: Çubuğun sağ ucu her zaman $y=\ln x$, yani $x=e^y$ eğrisi üzerinde, sol ucu her zaman $x=0$ doğrusu üzerindedir. Uçlar hiç değişmediği için tek bir integral yeterlidir. Ek bir integral sembolüne gerek yoktur.

Kalınlık $dy$ olduğundan her şey $y$ cinsinden yazılır:

- **Yükseklik (çubuğun uzunluğu):** Sağ uç eksi sol uç: $e^y-0=e^y$.
- **Kalınlık:** $dy$.
- **Sınırlar:** Çubuk bölgeyi $-\infty$'dan $y=b$ seviyesine kadar tarar.

### 3.4 Kabuk Yarıçapı: Her İki Durumda da $b-y$

Hoca bu sorunun en ince noktasının yarıçap olduğunu söyledi ve bir öğrenci için bu kısmı Türkçe olarak bir kez daha anlattı.

- **Birinci durum, $y>0$:** Çubuk birinci bölgededir. Çubuğun $x$ eksenine uzaklığı $y$'dir, çünkü çubuk üzerindeki noktanın koordinatı $(x,y)$'dir. Eksene toplam uzaklık $b$ olduğundan kabuk yarıçapı $b-y$ olur.
- **İkinci durum, $y<0$:** Çubuk dördüncü bölgededir. Burada $y$ negatiftir. Çubuğun $x$ eksenine uzaklığı pozitif olmalı, bu yüzden uzaklık $-y$ olur. Eksenin $x$ eksenine uzaklığı $b$'dir. Toplam uzaklık iki pozitif değerin toplamıdır: $b+(-y)=b-y$.

Böylece iki durumda da yarıçap $b-y$ çıkar. Hoca bunun sonucunu şöyle özetledi: İntegrali ikiye bölmeye gerek yoktur, yarıçap doğrudan $b-y$'dir.

$$V=2\pi\int_{-\infty}^{b}(b-y)\,e^{y}\,dy$$

Hoca bu integral ifadesini görünce doğrudan B şıkkını işaretlediğini söyledi. Hocaya göre soru "çok zor gibi görünüyor ama gayet basit bir soru".

İntegralin değeri derste hesaplanmadı. Kısmi integrasyon ve limitle hesaplanırsa (ara adım eklendi):

$$\int(b-y)e^y\,dy=(b-y)e^y+e^y+C$$

$$V=2\pi\lim_{s\to-\infty}\Big[(b-y+1)e^y\Big]_{s}^{b}=2\pi\left(e^b-\lim_{s\to-\infty}(b-s+1)e^{s}\right)=2\pi e^{b}$$

Buradaki limit sıfırdır, çünkü $s\to-\infty$ iken $e^s$, $(b-s+1)$'in büyümesinden çok daha hızlı sıfıra gider.

> **Ders sonrası not:** Hoca "$b$ pozitif olmalı" dedi ve soruda bunun yazıp yazmadığını sordu. Yarıçap ifadesi $b-y$ için $b$'nin işaretine aslında gerek yoktur: Bölgede her zaman $y\le b$ olduğundan $b-y\ge0$'dır. $b>0$ varsayımı yalnız hocanın anlattığı iki durumlu ($y>0$ ve $y<0$) resmi mümkün kılar.

## 4. Daha Önce Çözülen Soru Tipleri: Tek Fonksiyon, L'Hôpital, Temel Teorem

Hoca birkaç soruyu "bunu daha önce çözmüştük" diyerek yalnız konusunu söyleyip geçti.

- **Tek ve çift fonksiyonların uygulaması:** Hoca bir soruyu tek fonksiyon ve çift fonksiyon uygulaması olarak tanıttı. Kısa nota göre bu, $h(x)=1+x+(x-2)\int_{-2}^{x}\left[(\sin t)^{2019}(\cos t)^{2020}-1\right]dt$ fonksiyonunun $x=2$'deki lineerleştirmesini soran Soru 9'dur. Çözümü "Örnek Sorular" bölümünde verildi.
- **L'Hôpital kuralı ve temel teorem:** $x\to0$ iken $\frac00$ belirsizliği veren bir limit sorusu. Hoca "L'Hôpital kuralını çalışın, temel teorem 1 ve 2'yi çalışın" dedi.
- **Temel teorem 1. kısım:** Temel teoremin birinci kısmıyla ilgili bir soru. Hoca finalde böyle soruların olacağını söyledi.

> **Hocanın vurgusu:** Baştan sona sorumlusunuz. Finalde en baştaki konulardan da soru gelebilir.

<!-- BELİRSİZ: L'Hôpital ve temel teorem 1. kısım sorularının metni altyazıda geçmiyor. Hoca bunları çözmeden geçti. -->

## 5. Kabuk Yöntemiyle Hacim İntegrali (Soru 10)

### 5.1 Soru

$R$ bölgesi $y=x^2$ eğrisi ile $y=3x$ doğrusu arasında kalan bölgedir. $R$ bölgesi $x=-5$ doğrusu etrafında döndürülüyor. Kabuk yöntemiyle hacmi veren integral hangisidir?

Hoca önce cevabın E olduğunu doğrulamalarını istedi. Arada bir öğrenciye derse devam etmenin önemini anlattı (aşağıya bakın), sonra soruya döndü.

### 5.2 Çözüm

Hoca önce bölgeyi çizdi. $y=x^2$ ile $y=3x$ kesişimi:

$$x^2=3x\;\Rightarrow\;x(x-3)=0\;\Rightarrow\;x=0,\;x=3$$

Bölgede $x$ ve $y$ pozitiftir. Dönme ekseni $x=-5$, $y$ ekseninin 5 birim solundadır. Kabuk yöntemi için dönme eksenine paralel, yani dikey bir çubuk konur. Kalınlık $dx$ olduğundan her şey $x$ cinsinden yazılır.

- **Yarıçap:** Eksenden $y$ eksenine uzaklık 5, $y$ ekseninden çubuğa uzaklık $x$'tir. Bölgenin başından sonuna yarıçap her zaman $x+5$'tir.
- **Yükseklik:** Hoca burada genel kuralı tekrar etti: Çubuğun üst ucundan alt ucunu çıkarırsanız kabuğun yüksekliğini bulursunuz. Üst uç her zaman $y=3x$ üzerinde, alt uç her zaman $y=x^2$ üzerindedir. Yükseklik $3x-x^2$'dir.
- **Kalınlık:** $dx$.

$$V=2\pi\int_0^3(x+5)(3x-x^2)\,dx$$

Cevap E şıkkıdır. Hoca soruyu, anlaşılırsa "gayet basit, güzel bir soru" olarak niteledi. İntegralin değeri derste hesaplanmadı; hesaplanırsa $\dfrac{117\pi}{2}$ çıkar.

### 5.3 Derse Katılım Üzerine

Hoca, soruları sonradan paylaşacağını bilen öğrencilerin dersi terk ettiğini söyledi. Derste önemli bir bilgi verilebileceğini ve bunun kaçırılacağını belirtti.

> **Hocanın vurgusu:** "Başarı, birim zamanda yapılan sorumlulukların, fedakârlıkların miktarıdır. Kolay yolu tercih etmeyin. Kolay yolu tercih edenlerin sonu genellikle hüsran olur."

## 6. Riemann Toplamından Belirli İntegrale (Soru 11)

### 6.1 Soru

$$\lim_{n\to\infty}\sum_{k=1}^{n}\frac{n}{n^2+k^2}$$

limitinin değeri nedir?

Hoca bu soruyu önce "daha önce çözmüştük" diyerek geçmek istedi ve bu tip bir sorunun finalde gelme ihtimalini yüksek gördüğünü söyledi. Bir öğrenci böyle bir sorunun ikinci vizede geldiğini söyleyince hoca tahminini düşürdü. Sonra bir öğrencinin isteğiyle soruyu yeniden çözdü: "Bakalım bilgilerimiz ne kadar taze aklımızda."

### 6.2 Hatırlatma: Riemann Toplamı

Hoca öğrencilere süre vermeden önce şu hatırlatmayı yaptı:

**Tanım (Riemann toplamı ve belirli integral):**

- $[a,b]$ aralığı $n$ eşit alt aralığa bölünür. Bütün alt aralıkların uzunluğu aynıdır: $\Delta x_k=\Delta x=\dfrac{b-a}{n}$.
- Alt aralıkların uç noktaları en baştan başlayarak koordinatlandırılır: $x_k=a+k\,\Delta x=a+k\,\dfrac{b-a}{n}$.
- $\displaystyle\sum_{k=1}^{n}f(x_k)\,\Delta x$ bir Riemann toplamıdır.
- $n\to\infty$ limitinde bu sonlu toplam belirli integrale dönüşür:

$$\lim_{n\to\infty}\sum_{k=1}^{n}f(x_k)\,\Delta x=\int_a^b f(x)\,dx$$

Hocaya göre soruda yapılacak iş, verilen ifadeyi $f(x_k)\,\Delta x$ biçiminde sigma notasyonu altında düzenlemek, uygun $a$, $b$ ve $f$'yi belirlemektir.

### 6.3 Çözüm

Önce toplam sigma notasyonuyla yazılır. Sigma notasyonunda değişen $k$'dır. $n$ sabittir.

$n^2$ paydada ortak paranteze alınır:

$$\frac{n}{n^2+k^2}=\frac{n}{n^2\left(1+\left(\frac kn\right)^2\right)}=\frac{1}{1+\left(\frac kn\right)^2}\cdot\frac1n$$

Şimdi parçalar yorumlanır:

- $\dfrac1n=\Delta x$ alınır. $\dfrac1n=\dfrac{1-0}{n}$ olduğundan $a=0$, $b=1$ seçilir.
- Bu durumda $x_k=0+k\cdot\dfrac1n=\dfrac kn$ olur.
- $\dfrac{1}{1+\left(\frac kn\right)^2}=f(x_k)$ ise $f(x)=\dfrac{1}{1+x^2}$'dir.

Limit, verilen aralığın bölüntü sayısını artırmak demektir. Bölüntü sayısı artınca sonlu toplam belirli integrale, $\Delta x$ de $dx$'e dönüşür:

$$\lim_{n\to\infty}\sum_{k=1}^{n}\frac{1}{1+\left(\frac kn\right)^2}\cdot\frac1n=\int_0^1\frac{dx}{1+x^2}$$

Bu integral temel teoremin 2. kısmıyla hesaplanır:

$$\int_0^1\frac{dx}{1+x^2}=\arctan1-\arctan0=\frac{\pi}{4}$$

### 6.4 Öğrenci Sorusu

**Soru:** Neden $0$'dan $1$'e gidiyoruz?

**Cevap:** Sigma notasyonunda değişken $k$'dır; $n$'ye bağlı her şey sabittir. $\Delta x$'in genel formülü $\dfrac{b-a}{n}$ olduğundan $\dfrac1n$'i $\dfrac{b-a}{n}$ olarak okuyabilirim. $b=2$, $a=1$ de seçebilirdin. O da $\dfrac1n$'i verir. Ama o zaman fonksiyonu kurmak zorlaşır; bu "işi yokuşa sürmek" olur. $b=1$, $a=0$ seçersem $x_k$ koordinatlandırmasını en rahat yaparım. Böylece $\Delta x$'i, $x_k$'yı ve $f(x)$'i rahatça yakalarım. Hangi tercihi yapacağınız sizin becerinize kalmış.

> **Ek bilgi (derste anlatılmadı):** $a=1$, $b=2$ seçimi de doğru sonucu verir; bu durumda $x_k=1+\frac kn$ olur ve $f(x)=\dfrac{1}{1+(x-1)^2}$ alınmalıdır. $\int_1^2\frac{dx}{1+(x-1)^2}$ integrali de $\frac{\pi}{4}$'tür. Yani seçim sonucu değiştirmez, yalnız fonksiyonu karmaşıklaştırır.

## 7. Zincir Kuralı Sorusu

Hoca rasyonel fonksiyonların integraline (basit kesirlere ayırma) ait bir soruyu daha önce çözdükleri için geçti. Ardından gelen zincir kuralı sorusunu da önce geçmek istedi, sonra "hadi çözelim" dedi.

### 7.1 Soru

$f$ türevlenebilir bir fonksiyon, $f(1)=-3$ ve $f'(1)=4$'tür.

$$y=f\!\left(xy^2+f(x^2)\right)+5$$

ise $(1,2)$ noktasında $\dfrac{dy}{dx}$ kaçtır?

### 7.2 Çözüm

Hoca türevi doğrudan aldı. İki noktaya dikkat çekti: zincir kuralı ve $y$'nin $x$'e bağlı olması.

$$y'=f'\!\left(xy^2+f(x^2)\right)\cdot\Big(1\cdot y^2+x\cdot2y\,y'+f'(x^2)\cdot2x\Big)$$

- İç fonksiyonun türevinde $xy^2$ çarpım kuralıyla türetilir: $y^2+x\cdot2y\,y'$.
- $f(x^2)$'nin türevi yine zincir kuralıyla $f'(x^2)\cdot2x$'tir.
- Sabit $5$'in türevi $0$'dır.

Hoca kalanını öğrencilere bıraktı: $x$ yerine $1$, $y$ yerine $2$ yazılıp verilen değerler kullanılır, cevap B şıkkı çıkar. Hesap şöyle tamamlanır (ara adımlar eklendi):

- $(1,2)$'de iç ifade: $xy^2+f(x^2)=1\cdot4+f(1)=4-3=1$. Dolayısıyla dış türev $f'(1)=4$'tür.
- $f'(x^2)\cdot2x=f'(1)\cdot2=8$.

$$y'=4\left(4+4y'+8\right)=48+16y'\;\Rightarrow\;-15y'=48\;\Rightarrow\;y'=-\frac{16}{5}$$

Nokta denklemi de sağlar: $f(1)+5=-3+5=2$.

> **Hocanın vurgusu:** Bu tip bir zincir kuralı sorusunu önemli buluyor. "Finaldeyiz, baştan sona sorumlusunuz."

## 8. Has Olmayan İntegral İçin Yorum Sorusu (Soru 15)

### 8.1 Soru

$t>0$ için

$$I=\int_0^t\frac{dx}{(2-x)^2}$$

integrali hakkında aşağıdaki ifadelerden hangileri doğrudur?

- I. $t<2$ için yakınsar.
- II. $t>2$ için $+\infty$'a ıraksar.
- III. $t>2$ için $-\infty$'a ıraksar.
- IV. $t=2$ için yakınsar.

Hoca soruyu aradan önce gösterdi, cevabın C olduğunu zihinlerinde doğrulamalarını istedi ve çözümü aradan sonra yaptı.

> **Hocanın vurgusu:** Has olmayan integrallerle ilgili böyle yoruma dayalı bir soru gelir. Has olmayan integrallerle ilgili en az iki soru bekleniyor.

### 8.2 Çözüm

Hoca önce integrandı tanımsız yapan noktayı belirledi: $x=2$'de payda sıfır olur. Sonra $t$'nin bu noktaya göre konumuna bakarak durumları ayırdı.

**I. durum, $t<2$:** $0$ ile $t$ arasında $\frac{1}{(2-x)^2}$ ifadesini tanımsız yapan bir nokta yoktur. Bu durumda olağan (has) bir integral söz konusudur. Hocaya göre olağan integraller her zaman yakınsaktır. I doğrudur.

**II ve III. durum, $t>2$:** Bu kez $x=2$ noktası $0$ ile $t$ arasındadır. İntegral has olmayan tiptedir ve bir limit problemine dönüştürülmelidir. Süreksizlik noktasının solunda $t_1$, sağında $t_2$ alınır:

$$I=\lim_{t_1\to2^-}\int_0^{t_1}\frac{dx}{(2-x)^2}+\lim_{t_2\to2^+}\int_{t_2}^{t}\frac{dx}{(2-x)^2}$$

Hoca belirsiz integrali hatırlattı:

$$\int\frac{dx}{(2-x)^2}=\frac{1}{2-x}+C$$

Türev alınarak doğrulanabilir: $\left(\frac{1}{2-x}\right)'=\frac{1}{(2-x)^2}$.

Hoca limitlerin hesabını öğrencilere bıraktı ve integralin $+\infty$'a ıraksadığını söyledi. Hesap şöyle tamamlanır (ara adımlar eklendi):

$$\lim_{t_1\to2^-}\left(\frac{1}{2-t_1}-\frac12\right)=+\infty,\qquad \lim_{t_2\to2^+}\left(\frac{1}{2-t}-\frac{1}{2-t_2}\right)=+\infty$$

İkinci limitte $2-t_2\to0^-$ olduğundan $-\dfrac{1}{2-t_2}\to+\infty$ olur. İntegrand her yerde pozitif olduğundan $-\infty$'a ıraksama mümkün değildir. II doğru, III yanlıştır.

**IV. durum, $t=2$:** $t$ yerine $2$ yazılınca integral $\int_0^2\frac{dx}{(2-x)^2}$ olur. Bu da has olmayan bir integraldir ve yukarıdaki ilk limit $+\infty$ olduğundan yakınsamaz. IV yanlıştır.

Hoca bir genel kurala da dikkat çekti: İntegral parçalara ayrıldığında parçalardan biri ıraksaksa, toplam integral yakınsak olmaz.

Doğru ifadeler I ve II'dir; cevap C şıkkıdır.

> **Ders sonrası not:** Hoca ikinci limiti yazarken altyazıda "$0$'dan $t_2$'ye" diyor; doğrusu integralin $t_2$'den $t$'ye alınmasıdır. Hoca ayrıca "parçalardan biri sonlu, öbürü sonsuz çıkabilir" gibi bir ihtimalden söz etti; bu integralde iki parça da $+\infty$'a ıraksar.

> **Ek bilgi (derste anlatılmadı):** İntegrasyon aralığının içindeki bir noktada integrand sınırsız oluyorsa, integral o noktada iki has olmayan integrale ayrılır. Toplam integralin yakınsak sayılması için iki parçanın da ayrı ayrı yakınsaması gerekir. Bu yüzden tek bir parçanın ıraksaması sonucu belirlemeye yeter.

## 9. Yay Uzunluğu (Soru 17)

Hoca bu sorudan önce bükülme noktası (inflection point) ve kritik noktalarla ilgili bir soruyu "daha önce çözdük" diyerek geçti ve finalde böyle bir soru görülebileceğini söyledi.

### 9.1 Soru

$$y=\frac12x^2-\frac14\ln x,\qquad 1\le x\le2$$

eğrisinin uzunluğu nedir?

### 9.2 Yay Uzunluğu Formülünün Hatırlatılması

Hoca yay uzunluğu formülünün Pisagor teoremiyle türetilebileceğini hatırlattı. Yay diferansiyeli:

$$dL=\sqrt{dx^2+dy^2}$$

Kare kökün içinde $dx^2$ ortak paranteze alınırsa:

$$dL=\sqrt{1+\left(f'(x)\right)^2}\,dx,\qquad L=\int_a^b\sqrt{1+\left(f'(x)\right)^2}\,dx$$

### 9.3 Çözüm

Önce türev alınır:

$$f'(x)=x-\frac{1}{4x}$$

Hoca kare alırken işlem hatası yapmamaya dikkat çekti:

$$\left(x-\frac{1}{4x}\right)^2=x^2-2\cdot x\cdot\frac{1}{4x}+\frac{1}{16x^2}=x^2-\frac12+\frac{1}{16x^2}$$

$$1+\left(f'(x)\right)^2=x^2+\frac12+\frac{1}{16x^2}$$

Hoca "bu bir şeyin karesi olur mu?" diye sordu. Bu ifade $\left(x+\frac{1}{4x}\right)^2$'dir: Açılımdaki orta terim $2\cdot x\cdot\frac{1}{4x}=\frac12$'yi verir. Sorunun anahtarı bu tam kareyi görmektir.

$$L=\int_1^2\left|x+\frac{1}{4x}\right|dx$$

$[1,2]$ aralığında $x+\frac{1}{4x}$ pozitif olduğundan mutlak değer kalkar:

$$L=\left[\frac{x^2}{2}+\frac14\ln x\right]_1^2=\left(2+\frac14\ln2\right)-\frac12=\frac32+\frac14\ln2$$

Cevap A şıkkıdır.

## 10. Trigonometrik Dönüşüm (Soru 18)

### 10.1 Soru

$$\int\frac{x^2}{\sqrt{4+x^2}}\,dx$$

integraline uygun bir trigonometrik dönüşüm (trigonometric substitution) uygulanınca aşağıdaki integrallerden hangisi elde edilir?

### 10.2 Hangi Dönüşüm?

Hoca hangi dönüşümün uygun olduğunu sordu. Cevap tanjant dönüşümüdür: $x=2\tan\theta$.

**Soru:** Bir öğrenci sekant dönüşümünü önerdi.

**Cevap:** Hayır. $\operatorname{arcsec}$'in türevi $x^2-a^2$ biçimiyle ilişkilidir. Burada ise ifade $\arctan$'ın türevine benziyor: $4$ yerine $1$ koyarsanız $1+x^2$ elde edersiniz. $a^2+x^2$ biçimi $\arctan$'ın türeviyle ilişkilidir. Bu yüzden uygun trigonometrik dönüşüm $x=2\tan\theta$'dır.

### 10.3 Çözüm

$$x=2\tan\theta,\qquad dx=2\sec^2\theta\,d\theta$$

$$\sqrt{4+x^2}=\sqrt{4+4\tan^2\theta}=\sqrt{4\sec^2\theta}=2\sec\theta$$

Burada $1+\tan^2\theta=\sec^2\theta$ özdeşliği kullanılır. Yerine yazılınca:

$$\int\frac{4\tan^2\theta\cdot2\sec^2\theta}{2\sec\theta}\,d\theta=\int4\tan^2\theta\,\sec\theta\,d\theta$$

Sadeleştirmede paydaki $2$ ile paydadaki $2$, ayrıca bir $\sec\theta$ sadeleşir. Cevap A şıkkıdır.

## 11. Parabol Altındaki Bölgenin Farklı Eksenler Etrafında Döndürülmesi

### 11.1 Soru

$y=2x-x^2$ parabolü ile $x$ ekseni arasında kalan bölge $y$ ekseni etrafında döndürülüyor. Oluşan cismin hacmi nedir?

### 11.2 Çözüm

$y=2x-x^2$ aşağı bakan bir paraboldür. Kökleri $x=0$ ve $x=2$'dir. Bölge parabolün altında, $x$ ekseninin üstündedir.

Dönme ekseni $y$ ekseni olduğundan kabuk yöntemi uygundur. Dikey çubuk için:

- **Yarıçap:** $x$.
- **Yükseklik:** $2x-x^2$ (hoca önce "$x^2$ eksi" dedi, hemen düzeltti).
- **Kalınlık:** $dx$.

$$V=2\pi\int_0^2x\,(2x-x^2)\,dx=2\pi\left[\frac{2x^3}{3}-\frac{x^4}{4}\right]_0^2=2\pi\left(\frac{16}{3}-4\right)=\frac{8\pi}{3}$$

Hesap derste yapılmadı; hoca cevabın C şıkkı olduğunu söyledi (ara adım eklendi).

### 11.3 Hocanın Ek Varyasyonları

Hoca aynı bölgeyi farklı eksenler etrafında döndürerek kendi "şıklarını" kurdu:

- **$x=-2$ etrafında:** Eksenden $y$ eksenine uzaklık 2 birimdir. Bölgede $x$ pozitif olduğundan yarıçap $x+2$'dir.

$$V=2\pi\int_0^2(x+2)(2x-x^2)\,dx$$

- **$x=3$ etrafında:** Eksene toplam uzaklık 3, çubuğun $y$ eksenine uzaklığı $x$'tir. Yarıçap $3-x$'tir.

$$V=2\pi\int_0^2(3-x)(2x-x^2)\,dx$$

- **$y=-2$ etrafında:** Hoca bu durumda hangi yöntemin avantajlı olduğunu sordu. Cevap pul (washer) yöntemidir, çünkü dikey çubuk bu kez dönme eksenine diktir. Hoca disk yöntemiyle pul yönteminin aslında aynı yöntem olduğunu söyledi.

<!-- BELİRSİZ: 01:18:29-01:18:42 arasında altyazı bozuk. Dönme ekseninin $y=-2$ olduğu "y'ye, minus 2'ye" ifadesinden çıkarıldı. -->

## 12. Ekstremum: Parçacığın En Büyük Hızı

### 12.1 Soru

Bir parçacığın zamana bağlı hız fonksiyonu $v(t)$ veriliyor. Parçacığın $t=0$ ile $t=2$ anları arasında sahip olduğu en büyük hız nedir?

<!-- BELİRSİZ: Hız fonksiyonunun kendisi altyazıda geçmiyor. Hocanın bulduğu türev ve sonuçtan büyük olasılıkla $v(t)=t-\ln(t^2+1)$ olduğu anlaşılıyor. -->

### 12.2 Çözüm

Hoca bunun ekstremum değerleriyle ilgili bir soru olduğunu söyledi. En büyük hızı bulmak için önce kritik noktalar aranır, yani türev hesaplanır. Hoca türevi şu biçimde buldu:

$$v'(t)=\frac{(t-1)^2}{t^2+1}$$

$v(t)=t-\ln(t^2+1)$ için bu türev şöyle çıkar (ara adım eklendi):

$$v'(t)=1-\frac{2t}{t^2+1}=\frac{t^2-2t+1}{t^2+1}=\frac{(t-1)^2}{t^2+1}$$

Pay bir tam kare, payda pozitiftir. Türev hiçbir yerde negatif değildir. Bu yüzden $v$ her yerde artan bir fonksiyondur ve aralıktaki en büyük değerini sağ uçta alır:

$$v_{\max}=v(2)=2-\ln5$$

> **Ders sonrası not:** Hoca türev için "her zaman pozitif" dedi. Doğrusu "negatif değil" olmalıdır: $t=1$'de $v'(1)=0$'dır. Türevin tek bir noktada sıfır olması fonksiyonun artan olmasını değiştirmez, sonuç aynıdır.

## 13. Yeni Bir Dönüşüm: $\tan\frac{x}{2}=t$

Hoca, şimdiye kadar çözmediği farklı bir değişken dönüşümü gerektiren bir soru tipi kaldığını söyledi. Bunu da anlatınca bütün konuları bitirmiş olacaktı. Ekran paylaşımını beyaz tahtaya geçirip yeni konuyu bir soru üzerinden anlattı.

### 13.1 Dönüşümün Fikri

$\tan\frac{x}{2}=t$ özel bir dönüşümdür. $\sin x$ ve $\cos x$ içeren, olağan yöntemlerle kolay bir integrale dönüşmeyen bazı integrallerde kullanılır. Böyle bir integral görüldüğünde bu dönüşümü uygulamak daha iyidir.

**Tanım ($\tan\frac x2=t$ dönüşümü):**

- $t=\tan\dfrac x2$ alınır.
- $\sin x=\dfrac{2t}{1+t^2}$
- $\cos x=\dfrac{1-t^2}{1+t^2}$
- $dx=\dfrac{2\,dt}{1+t^2}$

### 13.2 Formüllerin Çıkarılışı

Hoca formülleri bir dik üçgenle çıkardı. Açısı $\frac x2$ olan bir dik üçgende karşı kenar $t$, komşu kenar $1$ alınırsa $\tan\frac x2=t$ olur. Pisagor teoremiyle hipotenüs $\sqrt{t^2+1}$'dir. Buradan:

$$\sin\frac x2=\frac{t}{\sqrt{t^2+1}},\qquad \cos\frac x2=\frac{1}{\sqrt{t^2+1}}$$

**$\sin x$:** $x=\frac x2+\frac x2$ yazılır ve $\sin(a+b)$ açılımı kullanılır, yani $\sin x=2\sin\frac x2\cos\frac x2$:

$$\sin x=2\cdot\frac{t}{\sqrt{t^2+1}}\cdot\frac{1}{\sqrt{t^2+1}}=\frac{2t}{1+t^2}$$

**$\cos x$:** $\cos x=\cos^2\frac x2-\sin^2\frac x2$ kullanılır:

$$\cos x=\frac{1}{t^2+1}-\frac{t^2}{t^2+1}=\frac{1-t^2}{1+t^2}$$

**$dx$:** $\tan\frac x2=t$ eşitliğinin iki tarafının diferansiyeli alınır:

$$\left(1+\tan^2\frac x2\right)\cdot\frac12\,dx=dt\;\Rightarrow\;\frac{1+t^2}{2}\,dx=dt\;\Rightarrow\;dx=\frac{2\,dt}{1+t^2}$$

> **Ek bilgi (derste anlatılmadı):** Bu dönüşüm literatürde Weierstrass dönüşümü ya da yarım açı tanjant dönüşümü olarak bilinir. $\sin x$ ve $\cos x$'in rasyonel her ifadesini $t$'nin rasyonel bir fonksiyonuna çevirir. Bu yüzden prensipte bu tür her integral, basit kesirlere ayırma ile çözülebilir hale gelir.

### 13.3 Örnek 1: $\displaystyle\int\frac{dx}{2+\sin x+\cos x}$

Dönüşüm uygulanır:

$$\int\frac{\dfrac{2\,dt}{1+t^2}}{2+\dfrac{2t}{1+t^2}+\dfrac{1-t^2}{1+t^2}}$$

Hoca sadeleştirmeyi ödev bıraktı ve sonucu notundan okudu. Sadeleştirme şöyledir (ara adım eklendi): Payda ortak paydada toplanır,

$$2+\frac{2t}{1+t^2}+\frac{1-t^2}{1+t^2}=\frac{2+2t^2+2t+1-t^2}{1+t^2}=\frac{t^2+2t+3}{1+t^2}$$

$1+t^2$'ler sadeleşir:

$$\int\frac{2\,dt}{t^2+2t+3}=\int\frac{2\,dt}{(t+1)^2+2}$$

Bu artık basit bir integraldir; $u=t+1$ değişken dönüşümüyle $\arctan$ formülüne gelinir:

$$\int\frac{2\,dt}{(t+1)^2+2}=\frac{2}{\sqrt2}\arctan\frac{t+1}{\sqrt2}+C=\sqrt2\arctan\frac{t+1}{\sqrt2}+C$$

Son olarak eski değişkene dönülür, $t$ yerine $\tan\frac x2$ yazılır:

$$\int\frac{dx}{2+\sin x+\cos x}=\sqrt2\arctan\left(\frac{1+\tan\frac x2}{\sqrt2}\right)+C$$

> **Ders sonrası not:** Hoca sonucu altyazıda "$\frac{2}{\sqrt2}\arctan\left(\frac{1}{\sqrt2}\tan\frac x2\right)+C$" gibi okudu. Bu ifadede $+1$ eksik. Doğrusu $\sqrt2\arctan\left(\frac{1+\tan\frac x2}{\sqrt2}\right)+C$'dir. Türev alınarak doğrulandı; hocanın okuduğu ifadenin türevi integrande eşit değildir.

> **Hocanın vurgusu:** Böyle bir dönüşümle çözülen soru şu ana kadar sınavlarda nadir geldi, gelme ihtimali düşük. Ama zorlayıcı, seçici bir soru olarak sorulabilir.

### 13.4 Örnek 2: $\displaystyle\int\frac{dx}{5+3\cos x}$

Hoca "sınavda nasıl gelirse" diyerek bu örneği verdi, öğrencilerin çözmesini bekledi. Bunun öncekinden daha basit olduğunu söyledi.

Dönüşüm uygulanır:

$$\int\frac{\dfrac{2\,dt}{1+t^2}}{5+3\cdot\dfrac{1-t^2}{1+t^2}}$$

Payda: $\dfrac{5(1+t^2)+3(1-t^2)}{1+t^2}=\dfrac{2t^2+8}{1+t^2}$. Sadeleşince:

$$\int\frac{2\,dt}{2t^2+8}=\int\frac{dt}{t^2+4}=\frac12\arctan\frac t2+C$$

Hoca bu formülü daha önce gösterdiğini hatırlattı. $t$ gördüğümüz yere $\tan\frac x2$ yazılır:

$$\int\frac{dx}{5+3\cos x}=\frac12\arctan\left(\frac{\tan\frac x2}{2}\right)+C$$

Hoca sonucu ilk yazdığında $\arctan$'ın içindeki $2$'ye bölmeyi unuttu. "Burada bir gariplik var mı?" diye sordu ve düzeltti: "Bir de bölü iki olacaktı. Yoksa $x$ bölü $2$ gelir, yanlış olur."

### 13.5 Neden Başka Yöntemler Değil?

**Soru:** Bu integrallerde neden diğer yöntemleri denemiyoruz?

**Cevap:** Başka yöntemleri uygulamaya çalışırsanız basit bir integral elde edemezsiniz. Ama $\tan\frac x2=t$ dönüşümünü yaparsanız, o üçgen sayesinde ifadeyi rasyonel bir fonksiyona çevirebilirsiniz. Böylece alışık olmadığımız bir problemi, çok iyi bildiğimiz bir probleme, rasyonel fonksiyonların integraline dönüştürürüz.

> **Hocanın vurgusu:** "Yaptığımız her şey zaten bu. Önce çok iyi bilinen yöntemleri anlattık. Sonra karmaşık problemler gelirse, uygun değişken dönüşümleriyle onları çok iyi bilinen formlara dönüştürebiliriz dedik."

## 14. Finalde Hangi Konular Ağırlıklı?

Hoca derste anlatılacak başka konu kalmadığını söyleyip finalde hangi konuların ağırlıklı olacağına dair kendi tahminini verdi. Bu tahmin, dönemin konularını gözden geçirmek için de bir liste niteliğindedir.

- **İntegralin uygulamaları:** alan, hacim (en çok soru bu konudan beklendi), yay uzunluğu, dönel yüzey alanı. Hoca yüzey alanı formüllerini çalışmalarını özellikle istedi.
- **İntegrasyon teknikleri:** rasyonel fonksiyonların integrali, trigonometrik dönüşümler, trigonometrik integraller.
- **Has olmayan integraller:** en az bir, büyük olasılıkla iki soru.
- **Temel teorem (fundamental theorem):** hocaya göre kesine yakın.
- **Ortalama değer teoremleri:** türev ve integral için.
- **L'Hôpital kuralı ile temel teoremin birlikte kullanıldığı sorular.**

Hocaya göre soruların büyük kısmı ikinci vizeden sonraki konulardan, özellikle integrallerden gelecekti. Önerdiği çalışma sırası şuydu: Önce bu listedeki konular, sonra geçmiş yılların diğer soru tipleri.

**Soru:** İndirgeme formülleri (reduction formulas) gelir mi? Vizede gelmedi.

**Cevap:** Vizede gelmediyse gelme ihtimali var.

**Soru:** Odaklanmamız gereken konular yalnız bunlar mı?

**Cevap:** Bunlar finalde görebileceğiniz temel soru tipleridir ve gelme ihtimalleri yüksektir. Diğer soru tiplerinin hangisinin geleceğini bilmiyoruz; onlar birinci ve ikinci vize konularından gelebilir. Önce bu konulara, sonra geriye kalan soru tiplerine çalışın.

## Örnek Sorular

Bu bölümdeki sorular derste ekranda gösterilip hocanın okuduğu ya da tahtada verdiği sorulardır. Soru metinleri altyazıda tam geçmeyenlerde aynı dersin kısa notundaki metin kullanıldı. Derste çözülenlerin çözümü yukarıdaki bölümlerdedir; burada kısa sonuç verildi.

**Soru 1** (derste sözlü, 00:01:22): $R$ bölgesi $y=2-x^2$, $y=x$ ve $x=0$ ile sınırlıdır. $R$, $x=-b$ ($b>0$) doğrusu etrafında döndürülünce oluşan cismin hacmi $\frac{11\pi}{2}$'dir. $b$ kaçtır?

> **Çözüm:** Kabuk yöntemiyle $\frac{11\pi}{2}=2\pi\int_0^1(b+x)(2-x-x^2)\,dx$ kuruldu (Bölüm 2). Hesabın kalanı derste verilmedi: $2\pi\left(\frac{7b}{6}+\frac{5}{12}\right)=\frac{11\pi}{2}$ eşitliğinden $b=2$ çıkar (sympy ile doğrulandı).

**Soru 2** (derste sözlü, 00:09:48): $y=b$ doğrusunun altında, $y=\ln x$ ile $x=0$ arasında kalan bölge $y=b$ doğrusu etrafında döndürülüyor. Hacmi veren integral hangisidir?

> **Çözüm:** $V=2\pi\int_{-\infty}^{b}(b-y)\,e^{y}\,dy$ (Bölüm 3, B şıkkı). İntegralin değeri derste hesaplanmadı: $V=2\pi e^b$ (sympy ile doğrulandı).

**Soru 3** (derste sözlü, 00:20:21): $h(x)=1+x+(x-2)\displaystyle\int_{-2}^{x}\left[(\sin t)^{2019}(\cos t)^{2020}-1\right]dt$ fonksiyonunun $x=2$'deki lineerleştirmesi hangisidir?

<!-- BELİRSİZ: Bu sorunun metni altyazıda geçmiyor; hoca yalnız "tek ve çift fonksiyon uygulaması, daha önce çözdük" dedi. Metin kısa nottan alındı. -->

> **Çözüm (derste verilmedi):** $h(2)=1+2+0=3$. Temel teoremin 1. kısmı ve çarpım kuralıyla $h'(x)=1+\int_{-2}^{x}g(t)\,dt+(x-2)\,g(x)$, burada $g(t)=(\sin t)^{2019}(\cos t)^{2020}-1$. $x=2$'de son terim sıfırdır. $(\sin t)^{2019}(\cos t)^{2020}$ tek fonksiyon olduğundan $[-2,2]$'deki integrali $0$'dır; $\int_{-2}^{2}(-1)\,dt=-4$. Böylece $h'(2)=1-4=-3$ ve $L(x)=3-3(x-2)=9-3x$ (sympy ile tekliği doğrulandı).

**Soru 4** (derste sözlü, 00:21:40): $y=x^2$ ile $y=3x$ arasındaki bölge $x=-5$ etrafında döndürülüyor. Kabuk yöntemiyle hacmi veren integral hangisidir?

> **Çözüm:** $V=2\pi\int_0^3(x+5)(3x-x^2)\,dx$ (Bölüm 5, E şıkkı). Değeri $\frac{117\pi}{2}$'dir (derste hesaplanmadı, sympy ile bulundu).

**Soru 5** (derste sözlü, 00:33:16): $\displaystyle\lim_{n\to\infty}\sum_{k=1}^{n}\frac{n}{n^2+k^2}$ kaçtır?

> **Çözüm:** $\int_0^1\frac{dx}{1+x^2}=\frac{\pi}{4}$ (Bölüm 6). Sayısal kontrol: $n=100000$ için toplam $0{,}78540$'tır.

**Soru 6** (derste sözlü, 00:42:24): $f$ türevlenebilir, $f(1)=-3$, $f'(1)=4$. $y=f\!\left(xy^2+f(x^2)\right)+5$ ise $(1,2)$ noktasında $\frac{dy}{dx}$ kaçtır?

> **Çözüm:** Türev derste kuruldu, sayısal kısım öğrencilere bırakıldı (Bölüm 7). $y'=4(4+4y'+8)$ eşitliğinden $y'=-\frac{16}{5}$ çıkar (B şıkkı; sympy ile doğrulandı).

**Soru 7** (derste sözlü, 00:44:11): $t>0$ için $\int_0^t\frac{dx}{(2-x)^2}$ hakkında: I. $t<2$ için yakınsar. II. $t>2$ için $+\infty$'a ıraksar. III. $t>2$ için $-\infty$'a ıraksar. IV. $t=2$ için yakınsar. Hangileri doğrudur?

> **Çözüm:** Yalnız I ve II doğrudur, cevap C (Bölüm 8). $x\to2$ iken iki taraftaki limit de $+\infty$'dır (sympy ile doğrulandı).

**Soru 8** (derste sözlü, 01:05:39): $y=\frac12x^2-\frac14\ln x$, $1\le x\le2$ eğrisinin uzunluğu nedir?

> **Çözüm:** $1+(f')^2=\left(x+\frac{1}{4x}\right)^2$ olduğundan $L=\int_1^2\left(x+\frac{1}{4x}\right)dx=\frac32+\frac14\ln2$ (Bölüm 9, A şıkkı; sympy ile doğrulandı).

**Soru 9** (derste sözlü, 01:11:50): $\displaystyle\int\frac{x^2}{\sqrt{4+x^2}}\,dx$ integraline uygun trigonometrik dönüşüm uygulanınca hangi integral elde edilir?

> **Çözüm:** $x=2\tan\theta$ ile $\int4\tan^2\theta\sec\theta\,d\theta$ elde edilir (Bölüm 10, A şıkkı; sympy ile doğrulandı).

**Soru 10** (derste sözlü, 01:14:50): $y=2x-x^2$ ile $x$ ekseni arasındaki bölge $y$ ekseni etrafında döndürülüyor. Hacim nedir?

> **Çözüm:** $V=2\pi\int_0^2x(2x-x^2)\,dx=\frac{8\pi}{3}$ (Bölüm 11, C şıkkı). Hocanın varyasyonları için değerler derste hesaplanmadı: $x=-2$ etrafında $8\pi$, $x=3$ etrafında $\frac{16\pi}{3}$ çıkar (sympy ile).

**Soru 11** (derste sözlü, 01:19:09): Hız fonksiyonu $v(t)$ verilen bir parçacığın $[0,2]$ aralığındaki en büyük hızı nedir?

<!-- BELİRSİZ: $v(t)$ altyazıda geçmiyor; büyük olasılıkla $v(t)=t-\ln(t^2+1)$. -->

> **Çözüm:** $v'(t)=\frac{(t-1)^2}{t^2+1}\ge0$ olduğundan $v$ artandır; en büyük hız $v(2)=2-\ln5\approx0{,}391$'dir (Bölüm 12; sympy ile doğrulandı).

**Soru 12** (derste sözlü, 01:23:24): $\displaystyle\int\frac{dx}{2+\sin x+\cos x}$ integralini hesaplayın.

> **Çözüm:** $\tan\frac x2=t$ ile $\int\frac{2\,dt}{(t+1)^2+2}=\sqrt2\arctan\left(\frac{1+\tan\frac x2}{\sqrt2}\right)+C$ (Bölüm 13.3; türev alınarak sympy ile doğrulandı).

**Soru 13** (derste sözlü, 01:30:22): $\displaystyle\int\frac{dx}{5+3\cos x}$ integralini hesaplayın.

> **Çözüm:** $\int\frac{dt}{t^2+4}=\frac12\arctan\left(\frac{\tan\frac x2}{2}\right)+C$ (Bölüm 13.4; türev alınarak sympy ile doğrulandı).

## Dersin Toparlaması

Bu son derste dönemin konuları bir final mazeret sınavının soruları üzerinden gözden geçirildi. Hacim sorularında ortak yöntem şuydu: Önce bölge çizilir, dönme eksenine göre kabuk ya da pul yöntemi seçilir, sonra yarıçap, yükseklik ve kalınlık çubuğun konumundan okunur. Yarıçap her zaman pozitif bir uzaklık olmalıdır; $y=\ln x$ sorusunda bu ilke, $y$'nin işareti değişse de yarıçapın tek bir ifadeyle ($b-y$) yazılmasını sağladı. Sınırsız bölge has olmayan integrale, iç süreksizlik noktası da iki limitli bir hesaba götürdü. Riemann toplamı sorusunda bir toplamın $f(x_k)\,\Delta x$ biçiminde okunması, yay uzunluğu sorusunda ise kök içindeki ifadenin tam kare olduğunu görmek anahtar adımdı.

Dersin tek yeni konusu $\tan\frac x2=t$ dönüşümüydü. Bu dönüşüm $\sin x$ ve $\cos x$ içeren kesirleri rasyonel fonksiyon integraline çevirir. Hoca bunu dönemin bütün integral tekniklerinin ortak fikriyle bağladı: Alışık olmadığımız bir problemi uygun bir dönüşümle çok iyi bildiğimiz bir forma getirmek. Böylece dönemin konuları tamamlanmış oldu.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
