# Ders 21 Genişletilmiş Notu: İndirgeme Formülleri ve İkinci Vizeye Hazırlık Soruları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Başlangıcı ve Anlatım Biçimi
- 2. İndirgeme Formüllerinin Mantığı
- 3. $\int x^n e^x\,dx$ İçin İndirgeme Formülü
- 4. $\int \sin^n x\,dx$ İçin İndirgeme Formülü
- 5. $\int \cos^n x\,dx$ ve Wallis Formülleri
- 6. $\int \tan^n x\,dx$ İçin İndirgeme Formülü
- 7. $\int \sec^n x\,dx$ İçin İndirgeme Formülü
- 8. Diğer İndirgeme Formülleri
- 9. Geçmiş Yıl Soruları: Ortalama Değer Teoremi
- 10. Geçmiş Yıl Soruları: Yerel Ekstremum, Büküm, Rolle ve Zincir Kuralı
- 11. Geçmiş Yıl Soruları: Asimptotlar
- 12. Geçmiş Yıl Soruları: Mutlak Ekstremum
- 13. Grafik Yorumlama (Eğri Çizimi)
- 14. Geçmiş Yıl Soruları: Temel Teorem ve İntegraller İçin Ortalama Değer
- 15. Riemann Toplamı Formülü Soruları

## 1. Dersin Başlangıcı ve Anlatım Biçimi

Ders internet ve kalem sorunlarıyla başladı. Hocanın tablet kalemi bozulmuştu, internet bağlantısı da kesik kesikti. Hoca önce sürücüyü yenilemeyi denedi. Kayıtta yaklaşık 00:17:41 ile 00:55:21 arasında ders yapılmadı. Hoca ikinci vize hakkında kısa bir bilgilendirme de yaptı; sınav düzeni bu notta yer almıyor.

Kalem çalışmadığı için hoca dersi başka öğretim üyelerinin hazır ders notları üzerinden anlattı. Notları ekranda paylaştı ve fareyle işaretledi. Bunu tercih ettiği bir yöntem olmadığını, ama mecbur kaldığını söyledi. Ders İngilizce anlatıldı; öğrenciler istediğinde hoca aynı kısmı Türkçe tekrar etti.

Bu yüzden altyazıda formüllerin çoğu "bu", "şunu elde ederiz" gibi ifadelerle geçiyor. Formüller sözlü anlatımdan, kısa nottaki ekran bilgisinden ve sympy doğrulamasından kuruldu. Okunmayan yerler işaretlendi.

## 2. İndirgeme Formüllerinin Mantığı

Dersin konu kısmı indirgeme formülleri (reduction formulas) oldu. Bir integralin içinde hem sürekli değişken $x$ hem de bir tam sayı $n$ bulunabilir. Bu integrale $I_n$ adı verilir. İndirgeme formülü, $I_n$'yi kendisinden önceki bir integrale ($I_{n-1}$ ya da $I_{n-2}$) bağlayan bir eşitliktir. Bu tür bir eşitliğe ardışıklık bağıntısı (recursive relation) da denir.

**Tanım: İndirgeme formülü**

- $I_n$, $n$ tam sayısına bağlı bir integraldir.
- İndirgeme formülü $I_n$'yi $I_{n-1}$ ya da $I_{n-2}$ cinsinden yazar.
- Formül arka arkaya uygulanarak $I_0$ ya da $I_1$ gibi doğrudan hesaplanabilen bir integrale inilir.

Hocaya göre indirgeme formüllerinin neredeyse hepsi kısmi integrasyonla (integration by parts) elde edilir. Hoca, internette "integraller için indirgeme formülleri listesi" diye aratınca hepsinin listesinin çıkacağını söyledi. Bir soruda bu listeden işe yarayan formül seçilip uygulanır.

> **Hocanın vurgusu:** "İndirgeme formülü nedir?" tarzında soru gelmez. Önemli olan formülün nasıl elde edildiğini ve nasıl uygulandığını öğrenmektir. Elde ediliş mantığını ve yaklaşımları öğrenen, yoruma dayalı soruyu rahat çözer. "Çok soru çözmek marifet değil."

## 3. $\int x^n e^x\,dx$ İçin İndirgeme Formülü

### 3.1 Formülün elde edilişi

$n$ pozitif bir tam sayı olsun ve

$$I_n = \int x^n e^x\,dx$$

diyelim. Kısmi integrasyon için seçim şöyledir:

- $u = x^n$, $dv = e^x\,dx$.
- $du = n x^{n-1}\,dx$, $v = e^x$.

Kısmi integrasyon formülü $\int u\,dv = uv - \int v\,du$ uygulanır:

$$I_n = x^n e^x - \int e^x\cdot n x^{n-1}\,dx = x^n e^x - n\int x^{n-1}e^x\,dx .$$

Sağdaki integral, tanım gereği $I_{n-1}$'dir. Böylece

$$\boxed{I_n = x^n e^x - n\,I_{n-1}}$$

elde edilir. Hoca ekrandaki notta bir yerde $I_n$ yerine yanlış harf yazıldığını gösterip düzeltti ("this must be $I_n$"). Dikkat edilecek nokta, sağ tarafta $n-1$ indisinin olmasıdır: her integral kendisinden bir önceki indise bağlıdır.

### 3.2 Örnek 1: $\int x^4 e^x\,dx$

Burada $n = 4$'tür. Formül arka arkaya uygulanır:

- $I_4 = x^4 e^x - 4I_3$.
- $I_3 = x^3 e^x - 3I_2$.
- $I_2 = x^2 e^x - 2I_1$ (ara adım eklendi).
- $I_1 = x e^x - I_0$ (ara adım eklendi).
- $I_0 = \int e^x\,dx = e^x$.

Hoca Türkçe açıklamada $I_0$'ın $n = 0$ durumu olduğunu, yani yalnız $e^x$'in integrali olduğunu vurguladı. Geri yerine koyunca integral tamamen $x$'e ve üstel fonksiyona bağlı bir ifade olarak çıkar:

$$\int x^4 e^x\,dx = \left(x^4 - 4x^3 + 12x^2 - 24x + 24\right)e^x + C .$$

Son sonuç derste sözlü okunmadı ("we can obtain this integral result"); yukarıdaki ifade adımlardan hesaplandı ve sympy ile doğrulandı.

**Soru:** Bir öğrenci konunun Türkçe açıklanmasını istedi. **Cevap:** Hoca, $I_n$ integralinin bir önceki $I_{n-1}$'e bağlı olduğunu, aralarında "arka arkaya bir ardışıklık ilişkisi" bulunduğunu söyledi. $x^n$'e $u$, $e^x\,dx$'e $dv$ denip kısmi integrasyon uygulandığında $I_{n-1}$ integralinin kendiliğinden ortaya çıktığını gösterdi.

## 4. $\int \sin^n x\,dx$ İçin İndirgeme Formülü

### 4.1 Formülün elde edilişi

$$I_n = \int \sin^n x\,dx$$

olsun. Hoca bu tanımın çok önemli olduğunu, formülün her adımında tanıma bakılacağını söyledi. İntegrand şöyle ayrılır: $\sin^n x = \sin^{n-1}x\cdot\sin x$.

- $u = \sin^{n-1}x$, $dv = \sin x\,dx$.
- $du = (n-1)\sin^{n-2}x\cos x\,dx$, $v = -\cos x$.

Kısmi integrasyonla:

$$I_n = -\sin^{n-1}x\cos x + (n-1)\int \sin^{n-2}x\cos^2 x\,dx .$$

Buradaki $n-1$ katsayısı $du$'dan gelir. Şimdi $\cos^2 x = 1 - \sin^2 x$ yazılır:

$$I_n = -\sin^{n-1}x\cos x + (n-1)\int \sin^{n-2}x\,dx - (n-1)\int \sin^n x\,dx .$$

Tanıma bakılırsa $\int \sin^{n-2}x\,dx = I_{n-2}$ ve $\int \sin^n x\,dx = I_n$'dir:

$$I_n = -\sin^{n-1}x\cos x + (n-1)I_{n-2} - (n-1)I_n .$$

$I_n$'ler sol tarafta toplanır: $I_n + (n-1)I_n = nI_n$. Her iki taraf $n$'ye bölünür:

$$\boxed{I_n = -\frac{\sin^{n-1}x\cos x}{n} + \frac{n-1}{n}I_{n-2}}$$

Bu bağıntının anlamlı olması için $n \ge 2$ olmalıdır. Hoca Türkçe açıklamada "$I$'nın altında indis eksi 1 olamaz; $I_0$ olabilir, $I_{-1}$ diye bir şey yok" dedi.

### 4.2 Örnek 2: $\displaystyle\int_0^{\pi/2}\sin^5 x\,dx$

Hoca bu belirli integrali indirgeme formülüyle hesapladı ve buna $I_5$ dedi.

- $n = 5$ için formülün ilk terimi $-\dfrac{\sin^4 x\cos x}{5}$'tir. Temel teoremin 2. kısmına göre $0$ ve $\pi/2$ sınırları yerine yazılınca bu terim sıfır olur: $\cos(\pi/2) = 0$ ve $\sin 0 = 0$.
- Geriye yalnız sıfırdan farklı terim kalır:

$$\int_0^{\pi/2}\sin^5 x\,dx = \frac{4}{5}\int_0^{\pi/2}\sin^3 x\,dx .$$

- $n = 3$ için formül tekrar uygulanır. Yine ilk terim sınırlarda sıfır gelir; katsayı $\dfrac{2}{3}$'tür:

$$\int_0^{\pi/2}\sin^3 x\,dx = \frac{2}{3}\int_0^{\pi/2}\sin x\,dx .$$

- $\displaystyle\int_0^{\pi/2}\sin x\,dx = \left[-\cos x\right]_0^{\pi/2} = 0 - (-1) = 1$ (ara adım eklendi).

Sonuç:

$$\int_0^{\pi/2}\sin^5 x\,dx = \frac{4}{5}\cdot\frac{2}{3}\cdot 1 = \frac{8}{15} .$$

Sonuç sympy ile doğrulandı.

## 5. $\int \cos^n x\,dx$ ve Wallis Formülleri

### 5.1 Formülün elde edilişi

$$I_n = \int \cos^n x\,dx$$

olsun. Yöntem sinüstekiyle aynıdır. $\cos^n x = \cos^{n-1}x\cdot\cos x$ diye ayrılır.

- $u = \cos^{n-1}x$, $dv = \cos x\,dx$.
- $du = -(n-1)\cos^{n-2}x\sin x\,dx$, $v = \sin x$.

Kısmi integrasyon $uv - \int v\,du$ verir. Ortaya $\sin^2 x$ çıkar ve $\sin^2 x = 1 - \cos^2 x$ yazılır. Katsayı parantezin içine dağıtılır, tanım kullanılır ve $I_n$'ler bir tarafta toplanır:

$$\boxed{I_n = \frac{\cos^{n-1}x\sin x}{n} + \frac{n-1}{n}I_{n-2}}$$

Hoca burada da $I_n$'nin bir terime ve bir integrale bağlı olduğunu, katsayının $\dfrac{n-1}{n}$ olduğunu vurguladı.

### 5.2 $[0, \pi/2]$ üzerindeki belirli integraller

Ekrandaki notta $n = 5$ için $\displaystyle\int_0^{\pi/2}\cos^5 x\,dx$ hesaplandı. Sinüsteki gibi ilk terim sınırlarda sıfır olur ve aynı çarpanlar gelir. Sonuç yine $\dfrac{8}{15}$'tir (sympy ile doğrulandı). Buradan genel bir kural çıkar.

**Kural: Wallis formülleri** ($\sin$ ve $\cos$ için aynı)

- $n$ tek ve $n \ge 3$ ise:
$$\int_0^{\pi/2}\cos^n x\,dx = \frac{2}{3}\cdot\frac{4}{5}\cdots\frac{n-1}{n} .$$
- $n$ çift ve $n \ge 2$ ise:
$$\int_0^{\pi/2}\cos^n x\,dx = \frac{1}{2}\cdot\frac{3}{4}\cdots\frac{n-1}{n}\cdot\frac{\pi}{2} .$$

Hoca her çarpanın, her $n$ için indirgeme formülünden geldiğini söyledi. Türkçe açıklamasında çarpanların belli bir kurala göre geldiğini, pay ve paydanın birer artırılarak yazıldığını anlattı. $n$ çiftse en sonda $\dfrac{\pi}{2}$ ile çarpılır. Bunun nedeni, $n$ çiftken zincirin $\displaystyle\int_0^{\pi/2}dx = \frac{\pi}{2}$ integraliyle bitmesidir. Hoca aynı yaklaşımla $\sin^n$ için de genel formülün elde edilebileceğini söyledi.

> **Ders sonrası not:** Altyazıda hoca $n$ çift durumu için "2 bölü 3, 4 bölü 3" gibi bir ifade kullanıyor; burası büyük olasılıkla bir sürç. Formülde tek $n$ için çarpanlar $\tfrac{2}{3}, \tfrac{4}{5}, \dots$, çift $n$ için $\tfrac{1}{2}, \tfrac{3}{4}, \dots$ şeklindedir. Örneğin sympy ile $\displaystyle\int_0^{\pi/2}\sin^6 x\,dx = \frac{1}{2}\cdot\frac{3}{4}\cdot\frac{5}{6}\cdot\frac{\pi}{2} = \frac{5\pi}{32}$ doğrulandı.

<!-- BELİRSİZ: 01:16:04 civarında "En büyük eşitir 2 olursa tersten aldı" cümlesi tam anlaşılmıyor; çift n kuralı ekrandaki formüle göre yazıldı. -->

## 6. $\int \tan^n x\,dx$ İçin İndirgeme Formülü

### 6.1 Formülün elde edilişi

Hoca bütün indirgeme formüllerini anlatmayacağını, belli başlı olanları göstereceğini söyledi. Diğerleri alıştırma olarak bırakıldı.

$$I_n = \int \tan^n x\,dx$$

olsun. İntegrand uygun biçimde ayrılır: $\tan^n x = \tan^{n-2}x\cdot\tan^2 x$. Hoca bu ayrıştırmanın nedenini şöyle açıkladı: $\tan x$'in türevi $\sec^2 x$ içerir. Bu yüzden $\tan^2 x$ dışarıda bırakılır.

- $\tan^2 x = \sec^2 x - 1$ yazılır.
- Parantez dağıtılır:
$$I_n = \int \tan^{n-2}x\sec^2 x\,dx - \int \tan^{n-2}x\,dx .$$
- İlk integralde yerine koyma (substitution) yapılır: $u = \tan x$, $du = \sec^2 x\,dx$. Böylece
$$\int \tan^{n-2}x\sec^2 x\,dx = \int u^{n-2}\,du = \frac{\tan^{n-1}x}{n-1} .$$
- İkinci integral, tanım gereği $I_{n-2}$'dir.

Sonuç:

$$\boxed{I_n = \frac{\tan^{n-1}x}{n-1} - I_{n-2}}$$

Bu formülde ana araç kısmi integrasyon değil, yerine koymadır.

### 6.2 Örnek 3: $\displaystyle\int_0^{\pi/4}\tan^5 x\,dx$

Hoca bu integrale $I_5$ dedi.

- $n = 5$:
$$\int_0^{\pi/4}\tan^5 x\,dx = \left[\frac{\tan^4 x}{4}\right]_0^{\pi/4} - \int_0^{\pi/4}\tan^3 x\,dx = \frac{1}{4} - \int_0^{\pi/4}\tan^3 x\,dx .$$
Burada $\tan(\pi/4) = 1$ ve $\tan 0 = 0$ kullanıldı.
- $n = 3$ için formül tekrar uygulanır:
$$\int_0^{\pi/4}\tan^3 x\,dx = \left[\frac{\tan^2 x}{2}\right]_0^{\pi/4} - \int_0^{\pi/4}\tan x\,dx = \frac{1}{2} - \int_0^{\pi/4}\tan x\,dx .$$
Hoca "yine eksi 1 bölü 2 gelir" diyerek bu adımdan gelen $-\tfrac{1}{2}$'yi gösterdi.
- Yerine koyunca:
$$\int_0^{\pi/4}\tan^5 x\,dx = \frac{1}{4} - \frac{1}{2} + \int_0^{\pi/4}\tan x\,dx .$$
- $\tan x$'in integrali bilinir: $\displaystyle\int \tan x\,dx = \int\frac{\sin x}{\cos x}\,dx = -\ln(\cos x)$.
$$\int_0^{\pi/4}\tan x\,dx = -\ln\frac{1}{\sqrt{2}} + \ln 1 = \ln\sqrt{2} = \frac{1}{2}\ln 2 .$$

Sonuç:

$$\int_0^{\pi/4}\tan^5 x\,dx = -\frac{1}{4} + \frac{1}{2}\ln 2 \approx 0{,}0966 .$$

Sonuç sympy ile doğrulandı.

> **Ders sonrası not:** Kısa nottaki ekran bilgisine göre ekrandaki hazır notta ikinci satırda $\tfrac{\tan^2 x}{x}$, son satırda da $-\tfrac{1}{4}\ln\sqrt{2}$ gibi okunan yazım hataları vardı. Doğrusu yukarıdaki gibidir: $\tfrac{\tan^2 x}{2}$ ve sonuç $-\tfrac{1}{4} + \ln\sqrt{2}$.

## 7. $\int \sec^n x\,dx$ İçin İndirgeme Formülü

### 7.1 Formül

$$I_n = \int \sec^n x\,dx$$

olsun. Hoca $\sec^n x$'i uygun biçimde ayırıp kısmi integrasyonla ve uygun sadeleştirmelerle formülün elde edildiğini söyledi:

$$\boxed{I_n = \frac{\sec^{n-2}x\tan x}{n-1} + \frac{n-2}{n-1}I_{n-2}}$$

Hoca bu formülün ispatını kalemi olmadığı için gösteremediğini, kısmi integrasyonla elde edilmesini ödev olarak bıraktığını söyledi. Formül $n = 3, 4, 5, 6$ için türev alınarak sympy ile doğrulandı.

> **Ek bilgi (derste anlatılmadı):** İspatta genellikle $\sec^n x = \sec^{n-2}x\cdot\sec^2 x$ diye ayrılır. $u = \sec^{n-2}x$, $dv = \sec^2 x\,dx$ seçilir; böylece $v = \tan x$ olur. Ortaya çıkan $\tan^2 x$ yerine $\sec^2 x - 1$ yazılır ve $I_n$'ler bir tarafta toplanır. Yöntem, $\sin^n$ formülündekiyle aynı mantıktadır.

### 7.2 Örnek 4: $\displaystyle\int_0^{\pi/4}\sec^6 x\,dx$

Hoca bu integrale $I_6$ dedi. $\sec(\pi/4) = \sqrt{2}$, $\tan(\pi/4) = 1$, $\sec 0 = 1$, $\tan 0 = 0$ kullanılır.

- $n = 6$:
$$I_6 = \left[\frac{\sec^4 x\tan x}{5}\right]_0^{\pi/4} + \frac{4}{5}\int_0^{\pi/4}\sec^4 x\,dx = \frac{(\sqrt{2})^4\cdot 1}{5} + \frac{4}{5}I_4 = \frac{4}{5} + \frac{4}{5}I_4 .$$
- $n = 4$:
$$I_4 = \left[\frac{\sec^2 x\tan x}{3}\right]_0^{\pi/4} + \frac{2}{3}\int_0^{\pi/4}\sec^2 x\,dx = \frac{2}{3} + \frac{2}{3}\left[\tan x\right]_0^{\pi/4} = \frac{2}{3} + \frac{2}{3} = \frac{4}{3} .$$
- Yerine koyunca:
$$I_6 = \frac{4}{5} + \frac{4}{5}\cdot\frac{4}{3} = \frac{4}{5} + \frac{16}{15} = \frac{28}{15} .$$

Ekrandaki çözümde son satır $\dfrac{4}{5} + \dfrac{8}{15} + \dfrac{8}{15} = \dfrac{28}{15}$ biçiminde yazılmıştı; bu, $\dfrac{4}{5}\cdot\dfrac{4}{3}$'ün iki parçaya ayrılmış hâlidir. Sonuç sympy ile doğrulandı.

<!-- BELİRSİZ: 01:22:55 - 01:23:25 arasında altyazıda yalnız "I sub 4" geçiyor; ara adımlar ekrandaki nottan ve hesaptan kuruldu. -->

## 8. Diğer İndirgeme Formülleri

### 8.1 $\int \sin^m x\cos^n x\,dx$

Bu integralde iki tam sayı değişkeni vardır; integrale $I_{m,n}$ denir. Hoca önce özel bir durumu gösterdi: $n = 1$ için integral yerine koyma yöntemiyle kolayca bulunur. $m \ne -1$ ise yerine koymayla bir sonuç, $m = -1$ ise başka bir sonuç elde edilir.

> **Ek bilgi (derste anlatılmadı):** Bu özel durum büyük olasılıkla $\int \sin^m x\cos x\,dx$ integralidir. $u = \sin x$ yerine koymasıyla $m \ne -1$ için $\dfrac{\sin^{m+1}x}{m+1}$, $m = -1$ için $\ln|\sin x|$ elde edilir.

Genel durumda integrand çarpanlara ayrılır ve kısmi integrasyon uygulanır. Hoca bir çarpana $u$, diğerine $dv$ denerek formülün bulunacağını söyledi, ama ayrıntıya girmedi: "Önemli olan burada indirgeme formüllerini kullanabiliyor olmak." Ardından ekrandaki örneğe geçti: $m = 4$, $n = 6$ için

$$\int_0^{\pi/2}\sin^4 x\cos^6 x\,dx .$$

$m$ ve $n$ değerleri formüle yazılıp sınırlar yerine konunca sınır terimleri düşer ve başka bir indirgeme formülüne gelinir. O formül de uygulanarak integral hesaplanır.

> **Ders sonrası not:** Bu örneğin sonucu altyazıda okunmuyor. sympy ile hesaplanan değer $\displaystyle\int_0^{\pi/2}\sin^4 x\cos^6 x\,dx = \frac{3\pi}{512}$'dir.

### 8.2 $\int e^{ax}\sin^n x\,dx$

Benzer şekilde $e^{ax}\sin^n x$ biçimindeki integraller için de indirgeme formülü vardır. Burada $n$ bir tam sayı, $a$ ise keyfi bir reel sabittir; hoca $a$'nın tam sayı olmak zorunda olmadığını düzeltti. Bu formül anlatılmadı. Hoca bu notları ders sonrası paylaşacağını söyledi.

## 9. Geçmiş Yıl Soruları: Ortalama Değer Teoremi

Hoca ikinci vizenin konularına giren geçmiş yıl sorularını paylaştı. Öğrencilerin önce kendilerinin çözmesini istedi, sonra çözümü gösterdi.

> **Hocanın vurgusu:** Videoyu tekrar izlerken önünüze kâğıt kalem alın ve çözüme bakmadan soruları çözmeye çalışın. Çözebiliyorsanız konuyu öğrenmişsiniz demektir. "Konunun mantığını anladığınız an iş bitti demektir."

### 9.1 Örnek 5: $f(5)$'in alabileceği değerler

**Soru:** $f$, $[0,5]$'te sürekli ve $(0,5)$'te türevlenebilir olsun. $f(0) = 2$ ve $(0,5)$'te $1 \le f'(x) \le 3$ olsun. $f(5)$'in alabileceği en küçük ve en büyük değerleri bulun.

Hoca önce ortalama değer teoreminin (mean value theorem) ruhunu fareyle çizerek hatırlattı. $[a,b]$'de sürekli ve $(a,b)$'de türevlenebilir bir fonksiyon alalım. Grafiğin uç noktalarını birleştiren kirişi (secant line) düşünelim. Teorem, bu kirişe paralel bir teğet doğrusu bulunabileceğini söyler.

**Teorem: Ortalama değer teoremi**

- $f$, $[a,b]$'de sürekli ve $(a,b)$'de türevlenebilir olsun.
- O zaman öyle bir $c \in (a,b)$ vardır ki
$$f'(c) = \frac{f(b) - f(a)}{b - a} .$$
- Sağ taraf, $f$'nin $[a,b]$ üzerindeki ortalama değişim oranıdır (average rate of change). Teğetin eğimi kirişin eğimine eşittir.

Çözüm:

- Teorem $[0,5]$'e uygulanır: $f'(c) = \dfrac{f(5) - f(0)}{5 - 0} = \dfrac{f(5) - 2}{5}$.
- $1 \le f'(c) \le 3$ olduğu için:
$$1 \le \frac{f(5) - 2}{5} \le 3 .$$
- $5$ ile çarpılır: $5 \le f(5) - 2 \le 15$.
- $2$ eklenir: $7 \le f(5) \le 17$.

En küçük değer $7$, en büyük değer $17$'dir. Son sayılar altyazıda okunmadı; verilen bilgilerden hesaplandı.

### 9.2 Örnek 6: Ortalama değer teoremiyle eşitsizlik ispatı

**Soru:** $\sin 2x$ ile ilgili bir eşitsizliğin her $a, b$ için doğru olduğunu gösterin.

Çözüm:

- $f(x) = \sin 2x$ her kapalı $[a,b]$ aralığında sürekli, her açık $(a,b)$ aralığında türevlenebilirdir.
- Ortalama değer teoremine göre bir $c$ iç noktası vardır ve $f'(c)$ ortalama değişim oranına eşittir.
- $f'(x) = 2\cos 2x$ olduğu için:
$$2\cos 2c = \frac{\sin 2b - \sin 2a}{b - a} .$$
- İki tarafa mutlak değer uygulanır. $|\cos 2c| \le 1$ olduğundan:
$$|\sin 2b - \sin 2a| \le 2|b - a| .$$

<!-- BELİRSİZ: Sorudaki eşitsizliğin tam yazılışı altyazıda okunmuyor. Burada türetilen biçimi $|\sin 2b - \sin 2a| \le 2|b - a|$ olarak verildi; ispat yolu aynıdır. -->

Hoca, matematikteki birçok eşitsizliğin ortalama değer teoremiyle ispat edilebileceğini söyledi. Bu tipten tek örnek çözdü; mantığı anlaşılırsa bir örneğin yeterli olduğunu belirtti.

**Soru:** Bir öğrenci sınavda böyle bir sorunun nasıl sorulacağını sordu. **Cevap:** Hoca, sorunun test sınavının ruhuna uygun hazırlanacağını söyledi. Bir eşitsizliğin doğru olup olmadığı sorulursa, ortalama değer teoremiyle hemen gösterilebilir. Önemli olan çözümün mantığını anlamaktır; o zaman soru hangi tarzda gelirse gelsin çözülür.

## 10. Geçmiş Yıl Soruları: Yerel Ekstremum, Büküm, Rolle ve Zincir Kuralı

### 10.1 Örnek 7: Yerel ekstremum ve büküm noktaları

**Soru:** Verilen fonksiyonun bütün yerel ekstremum değerlerini ve büküm noktalarını (inflection points) bulun.

Hoca bunun basit bir soru olduğunu, ama çözerek tanımları hatırlamış olacağımızı söyledi. Yöntem:

- Yerel ekstremumlar için birinci türev hesaplanır ve işaret tablosu incelenir. Bunun için türev çarpanlarına ayrılır. Bu soruda katlı kök yoktu.
- Büküm noktaları için birinci türevden ikinci türev hesaplanır ve ikinci türevin işaret tablosu incelenir.
- Kritik noktalar ve ikinci türevin kökleri aynı tabloya yazılır. İşaretler, aralıklardan özel değerler türevde yerine konarak doğrulanabilir.

Tablodan okunan davranış:

| Aralık | Monotonluk | Konkavlık |
|---|---|---|
| $(-\infty, -\sqrt{3})$ | artan | aşağı konkav |
| $(-\sqrt{3}, -1)$ | azalan | aşağı konkav |
| $(-1, 0)$ | azalan | yukarı konkav |
| $(0, 1)$ | artan | yukarı konkav |
| $(1, \sqrt{3})$ | artan | aşağı konkav |

- $x = -1$ ve $x = 1$ büküm noktalarıdır, çünkü ikinci türev bu noktalarda işaret değiştirir.
- $x = 0$'da yerel minimum vardır.
- Altyazıda bir noktada da yerel maksimum olduğu söyleniyor ("local maximum point at the point this").

Hoca, bu tablo yardımıyla grafiğin kolayca çizilebileceğini gösterdi. Ardından benzer bir yerel ekstremum sorusunu aynı yaklaşımla öğrencilere bıraktı.

<!-- BELİRSİZ: Fonksiyonun kendisi altyazıda geçmiyor. 01:38:54 - 01:39:04 arasında altyazı "bu, bu, bu" döngüsüne giriyor; türevin çarpanları okunmuyor. Tablo yalnız sözlü anlatımdan kuruldu; $x = \sqrt{3}$ sonrasındaki davranış ve yerel maksimum noktası anlaşılmıyor. -->

### 10.2 Örnek 8: Rolle teoremi

**Soru:** Rolle teoremini verilen fonksiyona $[0,1]$ aralığında uygulayın.

**Teorem: Rolle teoremi**

- $f$, $[a,b]$'de sürekli olsun.
- $f$, $(a,b)$'de türevlenebilir olsun.
- $f(a) = f(b)$ olsun.
- O zaman en az bir $c \in (a,b)$ için $f'(c) = 0$'dır. Yani o noktadaki teğet doğrusu $x$ eksenine paraleldir.

Hoca önce "Bu probleme Rolle teoremini uygulayabilir miyiz?" diye sordu ve üç koşulun sağlanıp sağlanmadığına bakılması gerektiğini söyledi. Öğrencilere süre verdi ve ipucu olarak şunu söyledi: önce sürekliliği ve türevlenebilirliği kontrol et, sonra türevi alıp sıfıra eşitle; $0$ ile $1$ arasındaki $c$ anını bul.

Çözüm:

- $f$, $[0,1]$'de süreklidir.
- $f$, $x = -2$ dışında her yerde türevlenebilirdir. $-2$ aralığın dışında olduğu için $f$, $(0,1)$'de türevlenebilir.
- Uç noktalarda fonksiyon aynı değeri alır.
- Kısa nottaki ekran bilgisine göre:
$$f'(c) = \frac{c^2 + 4c - 2}{(c+2)^2} = 0 \;\Longrightarrow\; c^2 + 4c - 2 = 0 .$$
- İkinci derece denklemin kökleri: $c = -2 \pm \sqrt{6}$, yani yaklaşık $0{,}449$ ve $-4{,}449$.
- Yalnız $c = -2 + \sqrt{6}$ değeri $(0,1)$ aralığındadır. Bu seçilir.

Kökler sympy ile doğrulandı.

<!-- BELİRSİZ: Sorunun fonksiyonu altyazıda okunmuyor; 01:53:29 - 01:53:57 arası boş. -->

### 10.3 Örnek 9: Zincir kuralı

**Soru (kısa nottaki ekran bilgisi):** $f$ ve $g$ türevlenebilir, $f'(2) = 3$, $g(1) = 2$, $g'(1) = 1$ olsun. $h(x) = f(g(x^2))$ ise $h'(1)$ nedir?

Zincir kuralı iki kez uygulanır. Önce $f$'nin $g(x^2)$'ye göre türevi, sonra $g$'nin $x^2$'ye göre türevi, en son $x^2$'nin $x$'e göre türevi alınır:

$$h'(x) = f'(g(x^2))\cdot g'(x^2)\cdot 2x .$$

$x = 1$ yazılır:

$$h'(1) = f'(g(1))\cdot g'(1)\cdot 2 = f'(2)\cdot 1\cdot 2 = 3\cdot 2 = 6 .$$

Ardından ekrandaki bir sonraki soru, bir eşitsizliğin doğru olup olmadığını sormaktaydı. Hoca böyle durumlarda büyük olasılıkla ortalama değer teoreminin kullanılacağını söyleyip soruyu ödev bıraktı. Benzer soruların AVESİS sayfasında olduğunu hatırladığını, indirilip çözülebileceğini söyledi.

### 10.4 Örnek 10: $f(x) = x\sqrt{1-x}$, $[0,1]$, ortalama değer teoremi

Bu soru 10 dakikalık aradan sonra çözüldü (kayıtta yaklaşık 01:58:11 ile 02:10:45 arası ara).

**Soru:** Ortalama değer teoremini $f(x) = x\sqrt{1-x}$ fonksiyonuna $[0,1]$ kapalı aralığında uygulayın.

Çözüm:

- $f$, $[0,1]$'de süreklidir. Türev fonksiyonundan $f$'nin $(0,1)$'de türevlenebilir olduğu görülür.
- Teoreme göre öyle bir $c \in (0,1)$ vardır ki $f'(c)$, kirişin eğimine, yani $f$'nin $[0,1]$ üzerindeki ortalama değişim oranına eşittir.
- $f(0) = 0$ ve $f(1) = 0$ olduğundan ortalama değişim oranı $\dfrac{0 - 0}{1 - 0} = 0$'dır (ara adım eklendi).
- Türev (ara adım eklendi):
$$f'(x) = \sqrt{1-x} - \frac{x}{2\sqrt{1-x}} = \frac{2 - 3x}{2\sqrt{1-x}} .$$
- $f'(c) = 0$ eşitliği çözülür: $2 - 3c = 0$, yani $c = \dfrac{2}{3}$.

$c = \dfrac{2}{3}$ değeri $(0,1)$ aralığındadır. Sonuç sympy ile doğrulandı.

## 11. Geçmiş Yıl Soruları: Asimptotlar

> **Hocanın vurgusu:** Asimptotlar bir sonraki sınav için çok önemli. Birinci vizede asimptot sorusu yoktu; hoca bu konudan soru beklediğini söyledi. "Asimptotlar konusuna iyi çalışın."

### 11.1 Örnek 11: Düşey ve yatay asimptot

**Soru:** Verilen fonksiyonun yatay ve düşey asimptotlarını bulun.

**Düşey asimptot.** Fonksiyonun kuralı $x = 0$'da anlamsızdır. Bu yüzden düşey asimptot $x = 0$'da araştırılır. $x \to 0$ iken limit eşlenik yöntemiyle (conjugate method) hesaplanır ve sonlu bir değer çıkar.

**Tanım: Düşey asimptot**

- Fonksiyonun kuralını tanımsız yapan bir $x = a$ noktası alınır.
- $x \to a$ iken, sağdan ya da soldan, en az birinde $f(x) \to +\infty$ ya da $f(x) \to -\infty$ olmalıdır.
- Bu durumda $x = a$ doğrusu düşey asimptottur.

Limit sonlu olduğu için $x = 0$ doğrusu düşey asimptot değildir.

**Yatay asimptot.** Yatay asimptot durumunda fonksiyon sonsuzda bir yatay doğru gibi davranır. Bu yüzden $x \to +\infty$ ve $x \to -\infty$ limitleri ayrı ayrı hesaplanır.

- $x \to +\infty$ iken eşlenik yöntemiyle $f(x) \to \infty$ çıkar. Bu tarafta yatay asimptot yoktur.
- $x \to -\infty$ iken $\sqrt{x^2}$ dışarı $|x|$ olarak çıkarılır. $x$ negatif olduğundan $|x| = -x$ alınır. Bu düşünceyle limit $\dfrac{1}{2}$ bulunur.
- Sonuç: $y = \dfrac{1}{2}$ doğrusu ($x \to -\infty$ tarafında) yatay asimptottur.

<!-- BELİRSİZ: Fonksiyonun kendisi altyazıda geçmiyor; 02:14:39 - 02:15:09 arası altyazı "bu, bu" döngüsünde. -->

**Soru:** Bir öğrenci, limit sonsuz çıktığında nasıl yorum yapıldığını sordu. **Cevap:** Hoca yatay asimptotu şöyle açıkladı: $x$ ekseni üzerinde yeterince sağa ya da yeterince sola yürüdüğümüzde fonksiyon bir yatay doğru gibi, yani sonlu bir değere yaklaşarak davranır. Pozitif eksende sağa yürürken $f(x)$ değeri gittikçe artıyorsa grafik yatay doğru gibi davranmaz. Bu yüzden $+\infty$ tarafında yatay asimptot yoktur.

**Soru:** Aynı öğrenci, alttaki yatay asimptot hesabının farklı bir soru olup olmadığını sordu. **Cevap:** Hoca aynı soru olduğunu söyledi. Yatay asimptot iki ayrı durumda incelenir: biri $0$'dan $+\infty$'a, diğeri $0$'dan $-\infty$'a yürümektir. Birinde asimptot varken diğerinde olmayabilir. Bu soruda $+\infty$'da yatay asimptot yok, $-\infty$'da var.

**Soru:** Bir öğrenci $x = 0$'ın neden düşey asimptot olmadığını tekrar sordu. **Cevap:** Hoca $y = \dfrac{1}{x}$ örneğini verdi. Bu fonksiyonda $x \to 0$ iken sağdan yaklaşınca değer $+\infty$'a, soldan yaklaşınca $-\infty$'a gider. Bu yüzden $x = 0$ doğrusu düşey asimptottur. Ama bu soruda $x \to 0$ iken $f(x)$ sonlu bir değere yaklaşır; grafikte yalnız bir "delik" vardır. $f(x)$ sonsuza gitmediği için $x = 0$'da düşey asimptot yoktur.

> **Ders sonrası not:** Altyazıda hoca bu açıklamada $f(x)$'in "sıfıra yaklaştığını" söylüyor; aynı soruda daha önce limitin sonlu bir değer olduğu belirtiliyor. Kural değişmez: limit sonluysa (hangi sayı olursa olsun) o noktada düşey asimptot yoktur.

### 11.2 Örnek 12: Sıkıştırma teoremiyle yatay asimptot

**Soru:** Verilen fonksiyonun bütün yatay ve düşey asimptotlarını bulun.

- Fonksiyon $x = 0$'da anlamsızdır; düşey asimptot $x = 0$'da araştırılır. Sağdan ve soldan aynı fonksiyon geldiği için tek limit hesaplanır.
- $x \to 0$ iken limit $1$ çıkar. Limit sonlu olduğundan $x = 0$ düşey asimptot değildir. Fonksiyonun başka düşey asimptotu yoktur.
- $x \to +\infty$ iken bir terim sıfıra giden bir çarpanla sınırlı bir ifadenin çarpımıdır. Sıkıştırma teoremine (sandwich theorem) göre bu terim sıfıra gider. Geriye kalan terim $1$'e yaklaşır.
- Sonuç: $y = 1$ yatay asimptottur. $x \to -\infty$ için de aynı inceleme $y = 1$'i verir.

<!-- BELİRSİZ: Fonksiyonun kendisi altyazıda geçmiyor; yalnız limit değerleri söyleniyor. -->

**Soru:** Bir öğrenci, $x \to 0$ limitinde $1$ bulunduğuna göre $x = 1$'in düşey asimptot olup olmadığını sordu. **Cevap:** Hoca, $x = 1$'de bir tanımsızlık olmadığını söyledi. Düşey asimptot yalnız fonksiyonun kuralını tanımsız yapan noktalarda araştırılır. Her nokta düşey asimptot olmak zorunda değildir. Düşey asimptot için, $f(x)$'i tanımsız yapan noktaya sağdan ya da soldan yaklaşınca fonksiyonun $+\infty$'a ya da $-\infty$'a gitmesi gerekir.

## 12. Geçmiş Yıl Soruları: Mutlak Ekstremum

### 12.1 Örnek 13: Yerel ve mutlak ekstremum

**Soru:** Verilen fonksiyonun bütün yerel ve mutlak ekstremum değerlerini bulun.

Çözüm adımları:

- Önce tanım kümesi bulunur, yani kuralı anlamlı kılan bütün noktaların kümesi. Karekökün anlamlı olması için kökün içi sıfırdan büyük ya da sıfıra eşit olmalıdır: $4 - x^2 \ge 0$. Buradan $-2 \le x \le 2$ çıkar. Tanım kümesi $[-2, 2]$ kapalı aralığıdır.
- $-2$ ve $2$ uç noktalardır.
- Birinci türev hesaplanır ve kökleri bulunur. İki kök çıkar: $\pm\sqrt{2}$. Bunlar tanım kümesinde olduğu için kritik noktalardır.
- $x = \pm 2$'de türev tanımsızdır, ama bu noktalar tanım kümesindedir. Bu yüzden onlar da kritik noktadır.
- Değerler: $f(-2) = f(2) = 0$, $f(\sqrt{2}) = 2$, $f(-\sqrt{2}) = -2$.
- $f(\sqrt{2}) = 2$ mutlak maksimum, $f(-\sqrt{2}) = -2$ mutlak minimum değerdir.

**Tanım: Kritik nokta**

- Türev fonksiyonunu sıfır ya da tanımsız yapan noktadır.
- Bu nokta fonksiyonun tanım kümesinde bulunmalıdır. Tanım kümesinde olmayan bir kök kritik nokta sayılmaz.

> **Ders sonrası not:** Fonksiyon altyazıda geçmiyor. Verilen değerler büyük olasılıkla $f(x) = x\sqrt{4 - x^2}$ fonksiyonuna aittir: sympy ile bu fonksiyonun türevinin kökleri $\pm\sqrt{2}$ ve değerleri $f(\pm 2) = 0$, $f(\sqrt{2}) = 2$, $f(-\sqrt{2}) = -2$ bulundu.

### 12.2 Benzer soru (ödev olarak bırakıldı)

Hoca bir sonraki soruyu benzer şekilde çözülecek bir ödev olarak bıraktı, ama çözümü ekranda üzerinden geçti:

- Türevin kökleri $x = 0$ ve $x = 4$'tür; ikisi de tanım kümesindedir.
- $x = 5$ uç noktadır ve kritik nokta olarak da adlandırılabilir.
- Türevin işaret tablosuna göre $x = 0$'da yerel minimum, $x = 4$'te yerel maksimum vardır.
- $4$'ten sonra fonksiyon sürekli azaldığı için $x = 5$'te bir minimum değer vardır.

<!-- BELİRSİZ: 02:23:00'da altyazı kökleri "x0 and x5" diye veriyor, hemen ardından "x four" ve "x5 endpoint" diyor. Köklerin $0$ ve $4$, uç noktanın $5$ olduğu kabul edildi. Fonksiyon altyazıda geçmiyor. -->

## 13. Grafik Yorumlama (Eğri Çizimi)

Hoca, eğri çizimi (curve sketching) sorularının klasik sınavın ruhuna uygun olduğunu, test sınavında grafik çizdirilmeyeceğini söyledi. Ama grafiği yorumlamanız istenebilir. Bu bölümde ekrandaki grafikler üzerinden yorum soruları soruldu.

### 13.1 Düşey asimptotun iki yanında konkavlık

Grafikte $x = 2$ doğrusu düşey asimptottur. Hoca sordu: "$2$'nin solunda grafik yukarı mı aşağı mı konkav?" Bir öğrenci "aşağı konkav" diye cevap verdi.

- $x = 2$ düşey asimptot olduğu için solunda $f$ aşağı konkav (aşağı bükümlü) olmalıdır.
- Hocanın gerekçesi: Yukarı konkav olsaydı grafik $x = 2$ doğrusunu keserdi. Bu da $x = 2$'nin düşey asimptot olmasıyla çelişirdi.
- Aynı mantıkla $x = 2$'nin sağında grafik yukarı konkav olmalıdır.

### 13.2 Başka bir grafik: düşey ve eğik asimptot

- $x = -1$ düşey asimptottur. $-1$'in solunda $f$'nin grafiği yukarı konkav olmalıdır.
- Grafikte bir eğik asimptot (oblique asymptote) vardır: $y = x - 1$. Bu yüzden $x$'lerin yeterince büyük seçildiği bölgede grafik aşağı konkav olur.
- Hoca eğik asimptotun bölme yapılarak bulunduğunu hatırlattı. Genel yöntemi önceki derslerde anlatmıştı.

<!-- BELİRSİZ: 02:27:41 - 02:28:20 arasında hoca "eğik asimptot var mı?" diye soruyor; grafiğin geri kalan yorumu altyazıda anlaşılmıyor. -->

### 13.3 Yatay asimptot ve konkavlık

Bir başka grafikte $y = 1$ doğrusu yatay asimptottur. Hoca, $x$'ler yeterince sola, $-\infty$'a doğru seçildiğinde grafiğin yukarı konkav olmak zorunda olduğunu söyledi. Aksi durumda $y = 1$ doğrusu yatay asimptot olamazdı.

<!-- BELİRSİZ: 02:29:36 - 02:31:02 arasında altyazı kesik ("bu, bu", "X3'e"); bu grafiğin diğer özellikleri okunmuyor. Bu yorum ekrandaki soruya özeldir. -->

Hoca, bu yorumları yaptıktan sonra eğri çizimi sorularının geri kalanını öğrencilere bıraktı. Ardından bir fonksiyonun tanım kümesini, artan/azalan olduğu aralıkları, yerel ekstremumlarını, konkavlığını ve büküm noktalarını soran klasik bir soruyu da geçti.

## 14. Geçmiş Yıl Soruları: Temel Teorem ve İntegraller İçin Ortalama Değer

Hoca ekranda yeni bir soru dosyası paylaştı.

> **Hocanın vurgusu:** Temel teoremin 1. kısmı (fundamental theorem, part 1) çok önemli bir soru tipidir. Hoca bir sonraki sınavda bu konuyla ilgili birden fazla soru beklediğini söyledi.

### 14.1 Örnek 14: $f(x) = \displaystyle\int_0^{x}\frac{t - t^2}{1 + t^4}\,dt$, yerel maksimum ve minimum

Fonksiyonun integrandı kısa nottaki ekran bilgisinden alındı; altyazıda yalnız "$x$ çarpı $1 - x$" çarpanları geçiyor.

- Temel teorem 1. kısma göre integranda $t$ yerine üst sınır $x$ yazılır:
$$f'(x) = \frac{x - x^2}{1 + x^4} = \frac{x(1 - x)}{1 + x^4} .$$
- Kritik noktalar için türevin kökleri bulunur: $x = 0$ ve $x = 1$. İkisi de tanım kümesinde olduğundan kritik noktadır.
- Payda her zaman pozitiftir. İşaret, $x$ ve $1 - x$ çarpanlarına bakılarak bulunur:

| Aralık | $x$ | $1 - x$ | $f'(x)$ |
|---|---|---|---|
| $x < 0$ | $-$ | $+$ | $-$ |
| $0 < x < 1$ | $+$ | $+$ | $+$ |
| $x > 1$ | $+$ | $-$ | $-$ |

- $x = 0$ yerel minimum noktası, $x = 1$ yerel maksimum noktasıdır.
- Yerel minimum değer doğrudan bulunur: $f(0) = \displaystyle\int_0^0 \dots\,dt = 0$, çünkü alt ve üst sınırı aynı olan belirli integral sıfırdır.

Kritik noktalar ve işaretler sympy ile doğrulandı.

### 14.2 Örnek 15: $f(x) = \cos x$, $[0, \pi]$, ortalama değer

**Soru:** $f(x) = \cos x$ fonksiyonunun $[0, \pi]$ üzerindeki ortalama değerini (average value) hesaplayın. Sonra integraller için ortalama değer teoreminde bahsedilen $c$ değerini bulun.

Hoca burada bir uyarı yaptı: ortalama değer kavramı, ortalama değişim oranı kavramıyla karıştırılmamalıdır. Bunlar farklı kavramlardır.

**Tanım: Ortalama değer ve integraller için ortalama değer teoremi**

- $f$'nin $[a,b]$ üzerindeki ortalama değeri:
$$f_{ort} = \frac{1}{b-a}\int_a^b f(x)\,dx .$$
- Teorem: $f$, $[a,b]$'de sürekliyse $f(c) = f_{ort}$ olacak şekilde bir $c \in [a,b]$ vardır.

Çözüm:

- $f_{ort} = \dfrac{1}{\pi}\displaystyle\int_0^{\pi}\cos x\,dx = \frac{1}{\pi}\left[\sin x\right]_0^{\pi} = 0$.
- $f(c) = \cos c = 0$ aranır.
- $\cos c = 0$ eşitliğini sağlayan çok sayıda $c$ vardır. Ama aralığın içindeki uygun değer aranır: $c = \dfrac{\pi}{2}$.

Hoca bu sorunun basit olduğunu, ama anlamak için ortalama değerin ve integraller için ortalama değer teoreminin tanımlarını bilmek gerektiğini söyledi.

### 14.3 Örnek 16: Sınırları değişkene bağlı integralin türevi, $F'(1)$

**Soru:** Bir belirli integralle verilen $F$ fonksiyonunun $x = 1$'deki türevini hesaplayın.

Hoca öğrencilere süre verdi ve genelleştirilmiş temel teoremi hatırlattı:

**Kural: Sınırları değişkene bağlı integralin türevi**

- $u(x)$'ten $v(x)$'e $\displaystyle\int f(t)\,dt$ integralinin $x$'e göre türevi şöyle bulunur:
$$\frac{d}{dx}\int_{u(x)}^{v(x)} f(t)\,dt = f(v(x))\,v'(x) - f(u(x))\,u'(x) .$$
- Üst sınır integranda $t$ yerine yazılır ve üst sınırın türeviyle çarpılır. Alt sınır için aynısı yapılıp çıkarılır.
- Alt sınır sabitse türevi sıfırdır; o terim yazılmaz.

Çözümde üst sınır integranda yerine yazıldı ve üst sınırın türeviyle çarpıldı. Alt sınır $1$ sabit olduğu için türevi sıfırdır ve ikinci terim yazılmadı. $x = 1$ yazılınca $F'(1) = 2$ bulundu. İki öğrenci cevabı $2$ olarak buldu.

<!-- BELİRSİZ: 02:43:23 - 02:44:56 arasında $F$'nin tanımı okunmuyor; altyazıda "sinüs, 2x minus 1 minus 1" gibi bozuk bir parça var. Integrand ve üst sınır bilinmediği için sonuç ($F'(1) = 2$) ayrıca doğrulanamadı. -->

### 14.4 Örnek 17: $f(x) = \displaystyle\int_0^{x^2 - 2x}\frac{dt}{1+t^2}$, yerel ekstremum

**Soru:** Fonksiyonun yerel ekstremum değerlerini bulun. Fonksiyon kısa nottaki ekran bilgisinden alındı.

Hoca bu soruyu herkesin en fazla 2 dakikada çözebilmesi gerektiğini söyleyip süre verdi.

- Genelleştirilmiş temel teoremle:
$$f'(x) = \frac{1}{1 + (x^2 - 2x)^2}\cdot(2x - 2) .$$
- Kesrin paydası her zaman pozitiftir. $f'(x) = 0$ için $2x - 2 = 0$, yani $x = 1$.
- $x = 1$'in solunda $f' < 0$, sağında $f' > 0$'dır. Bu yüzden $x = 1$ yerel minimum noktasıdır. Hoca "minimum değer değil, minimum nokta" diye düzeltti. Yerel maksimum yoktur.
- Minimum değer: $x = 1$ için üst sınır $1^2 - 2\cdot 1 = -1$ olur.
$$f(1) = \int_0^{-1}\frac{dt}{1+t^2} = \left[\arctan t\right]_0^{-1} = \arctan(-1) - 0 = -\frac{\pi}{4} .$$

**Soru:** Bir öğrenci üst sınırın işaretini sordu ("Artı bir değil mi hocam?"). **Cevap:** Hoca $x$ yerine $1$ yazılınca $x^2 - 2x$'in $-1$ olduğunu gösterdi. Kalemi olmadığı için $\dfrac{dt}{1+t^2}$'nin integralinin arctanjant olduğunu sözlü anlattı; integral $0$'dan $-1$'e hesaplanır.

<!-- BELİRSİZ: 02:48:17 - 02:48:35 arasında öğrenci ile hoca arasındaki konuşmada kimin hangi işareti önerdiği tam anlaşılmıyor. Doğru üst sınır $-1$'dir. -->

Sonuç sympy ile doğrulandı.

> **Ders sonrası not:** Kısa nottaki ekran bilgisine göre ekrandaki hazır notta türevin paydası $1 + (x^2 - 2x)$ yazılmıştı. Doğrusu $1 + (x^2 - 2x)^2$'dir. Kök ve işaretler değişmediği için sonuç aynıdır.

> **Hocanın vurgusu:** Hoca bu soruya "5 yıldız" verdi ve bu tarz soruları görme ihtimalinin yüksek olduğunu söyledi. 5 yıldızlı sorulara ayrıca önem verin; bu sorular birinci vizeden önceki konularla harmanlanmıştır.

### 14.5 Örnek 18: Logaritmik türev ve temel teorem

**Soru:** $f(x) = (1 + \ln x)^x$ olsun. $g(x)$, alt sınırı $x$, üst sınırı $f(x)$ olan bir belirli integralle veriliyor. $f'(1)$ ve $g'(1)$'i bulun. Hoca bunu günün son sorusu olarak verdi.

**$f'(1)$'in hesabı (logaritmik türev).** Bir öğrenci $f'$'nin hesabını tekrar istedi; hoca şöyle açıkladı. $f$ standart bir fonksiyon değildir, aşkın (transcendental) bir fonksiyondur. Çünkü hem taban ($1 + \ln x$) hem üs ($x$) $x$'e bağlıdır. Bunu bilinen fonksiyonlara dönüştürmek için eşitliğin iki tarafına logaritma uygulanır:

$$\ln f(x) = x\ln(1 + \ln x) .$$

Eşitliğin iki tarafının $x$'e göre türevi alınır. Solda zincir kuralı, sağda çarpımın türevi kuralı kullanılır:

$$\frac{f'(x)}{f(x)} = 1\cdot\ln(1 + \ln x) + x\cdot\frac{1/x}{1 + \ln x} .$$

$x = 1$ yazılır:

- $f(1) = (1 + \ln 1)^1 = 1^1 = 1$.
- $\dfrac{f'(1)}{1} = \ln(1 + 0) + 1\cdot\dfrac{1}{1 + 0} = 0 + 1 = 1$, yani $f'(1) = 1$.

**$g'(1)$'in hesabı.** Genelleştirilmiş temel teorem 1. kısım uygulanır. Integranda $h(t)$ diyelim:

$$g'(x) = h(f(x))\,f'(x) - h(x)\cdot 1 .$$

$x = 1$ yazılır. $f(1) = 1$ ve $f'(1) = 1$ olduğundan:

$$g'(1) = h(1)\cdot 1 - h(1)\cdot 1 = 0 .$$

Hoca cevabın $0$ geldiğini söyledi. $f(1)$ ve $f'(1)$ değerleri sympy ile doğrulandı.

<!-- BELİRSİZ: Integrand altyazıda "cosine squared" diye geçiyor (02:51:46); büyük olasılıkla $h(t) = \cos^2 t$. Sonuç ($g'(1) = 0$), $f(1) = 1$ ve $f'(1) = 1$ olduğu sürece integranddan bağımsızdır. -->

Hoca, bu tarz soruların hesap araçlarıyla çözülebildiği için büyük olasılıkla sınavda gelmeyeceğini, bunun yerine yorum soruları geleceğini söyledi. Yine de bu soruya "3 yıldız" verdi.

> **Hocanın vurgusu:** Bütün kuralları çok iyi bilin. Ders notlarındaki kurallar ve yorumlar çok önemlidir. Bu kuralları ve yorumları bilmeyen, yoruma dayalı soruları çözemez.

## 15. Riemann Toplamı Formülü Soruları

Dersin sonunda hoca Riemann toplamlarıyla ilgili bir soru tipini gösterdi. Bir fonksiyon için $x_0$'dan $x_1$'e Riemann toplamı formülünün bulunması istenebilir. Böyle sorularda şıklar uzun uzun sadeleştirilmez; toplam formülü olarak bırakılır.

<!-- BELİRSİZ: Ekrandaki fonksiyon ve şıklar altyazıda okunmuyor. -->

Hoca, Riemann toplamlarıyla ilgili başka soru tiplerinin bir sonraki derste çözüleceğini söyledi.

## Örnek Sorular

Bu derste video karesi yoktur. Aşağıdaki sorular derste sözlü olarak sorulan ya da sözlü okunan sorulardır.

**1. (derste sözlü, 01:10:46)** $\displaystyle\int_0^{\pi/2}\sin^5 x\,dx$ integralini indirgeme formülünü kullanarak hesaplayın.

> **Çözüm:** $\sin^n$ formülünde sınır terimi $0$ ile $\pi/2$ arasında sıfır olur. $I_5 = \dfrac{4}{5}I_3 = \dfrac{4}{5}\cdot\dfrac{2}{3}I_1 = \dfrac{4}{5}\cdot\dfrac{2}{3}\cdot 1 = \dfrac{8}{15}$.

**2. (derste sözlü, 01:29:08)** $f$, $[0,5]$'te sürekli, $(0,5)$'te türevlenebilir; $f(0) = 2$ ve $1 \le f'(x) \le 3$. $f(5)$'in alabileceği en küçük ve en büyük değerleri bulun.

> **Çözüm:** Ortalama değer teoremiyle $f'(c) = \dfrac{f(5) - 2}{5}$. $1 \le \dfrac{f(5) - 2}{5} \le 3$ eşitsizliğinden $7 \le f(5) \le 17$. En küçük değer $7$, en büyük değer $17$.

**3. (derste sözlü, 02:11:18)** Ortalama değer teoremini $f(x) = x\sqrt{1-x}$ fonksiyonuna $[0,1]$ aralığında uygulayın.

> **Çözüm:** $f(0) = f(1) = 0$ olduğundan $f'(c) = 0$ aranır. $f'(x) = \dfrac{2 - 3x}{2\sqrt{1-x}}$; $c = \dfrac{2}{3} \in (0,1)$.

**4. (derste sözlü, 02:24:47)** $x = 2$ doğrusu düşey asimptot olduğuna göre $x = 2$'nin solunda grafik yukarı mı aşağı mı konkavdır? Sağında ne olmalıdır?

> **Çözüm:** Solunda aşağı konkav olmalıdır; yukarı konkav olsaydı grafik $x = 2$ doğrusunu keserdi ve bu, düşey asimptot olmasıyla çelişirdi. Sağında yukarı konkav olmalıdır.

**5. (derste sözlü, 02:35:13)** $x \to 0$ iken limit $1$ (sonlu) çıktı ve $x = 0$ düşey asimptot değil. Peki $x = 1$ düşey asimptot olur mu?

> **Çözüm:** Hayır. $x = 1$'de fonksiyonda bir tanımsızlık yoktur. Düşey asimptot yalnız fonksiyonun kuralını tanımsız yapan noktalarda aranır ve o noktaya yaklaşırken fonksiyonun $\pm\infty$'a gitmesi gerekir.

**6. (derste sözlü, 02:40:13)** $f(x) = \cos x$ fonksiyonunun $[0, \pi]$ üzerindeki ortalama değerini hesaplayın ve integraller için ortalama değer teoremindeki $c$ değerini bulun.

> **Çözüm:** $f_{ort} = \dfrac{1}{\pi}\displaystyle\int_0^{\pi}\cos x\,dx = 0$. $\cos c = 0$ ve $c \in [0, \pi]$ için $c = \dfrac{\pi}{2}$.

**7. (derste sözlü, 02:49:34)** $f(x) = (1 + \ln x)^x$ ve $g(x)$, alt sınırı $x$, üst sınırı $f(x)$ olan bir belirli integral olsun. $f'(1)$ ve $g'(1)$'i bulun. <!-- BELİRSİZ: g'nin integrandı altyazıda tam okunmuyor. -->

> **Çözüm:** Logaritmik türevle $\dfrac{f'(x)}{f(x)} = \ln(1 + \ln x) + \dfrac{1}{1 + \ln x}$; $f(1) = 1$, $f'(1) = 1$. Genelleştirilmiş temel teoremle $g'(1) = h(f(1))f'(1) - h(1) = h(1) - h(1) = 0$.

## Dersin Toparlaması

Bu derste indirgeme formüllerinin nasıl elde edildiği ve nasıl uygulandığı görüldü. $\int x^n e^x\,dx$, $\int \sin^n x\,dx$ ve $\int \cos^n x\,dx$ formülleri kısmi integrasyonla, $\int \tan^n x\,dx$ formülü ise $\tan^2 x = \sec^2 x - 1$ özdeşliği ve yerine koymayla bulundu. $\sec^n$ formülü ödev olarak bırakıldı. $[0, \pi/2]$ üzerindeki $\sin^n$ ve $\cos^n$ integralleri için sınır terimlerinin sıfır olması sayesinde Wallis formüllerine ulaşıldı. Her formül bir belirli integral örneğiyle uygulandı.

Dersin ikinci yarısında ikinci vizeye hazırlık için geçmiş yıl soruları çözüldü: ortalama değer teoremi ve Rolle teoremi, ekstremum ve büküm noktaları, zincir kuralı, düşey ve yatay asimptotlar, mutlak ekstremum, grafik yorumlama, temel teorem 1. kısım, integraller için ortalama değer ve logaritmik türev. Hoca bütün bu konularda kuralları ve yorumları iyi bilmenin önemini vurguladı. Bir sonraki derste Riemann toplamlarıyla ilgili soru tiplerine ve soru çözümüne devam edilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
