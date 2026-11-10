# Ders 27 Genişletilmiş Notu: Final Hazırlığı: Vektör Fonksiyonları, Yay Uzunluğu, Tanım Bölgesi, Limit ve Süreklilik Soruları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Amacı: Final Öncesi Çalışma Soruları
- 2. Vektör Değerli Fonksiyonlar
- 3. Parametrik Uzay Eğrilerinde Yay Uzunluğu
- 4. İki Değişkenli Fonksiyonlarda Tanım Bölgesi
- 5. İki Değişkenli Limitlerin Hesabı
- 6. Limitin Yokluğu ve Süreklilik
- 7. Derste Yapılan Genel Tekrar
- Örnek Sorular
- Dersin Toparlaması

<!-- BELİRSİZ: Sorular hocanın ekranda paylaştığı bir PDF'ten okundu. Altyazıda soruların formülleri çoğu yerde tam okunmuyor. Fonksiyon ifadeleri, altyazıdaki sözlü okumalarla tutarlı olacak şekilde kısa nottan alındı; sözlü okumada hiç geçmeyen kısımlar (ör. Soru 1'in konum vektörü, Soru 2 ve 4'ün tam ifadesi, Soru 10-12'nin tam ifadesi) altyazıdan ayrıca doğrulanamadı. -->

## 1. Dersin Amacı: Final Öncesi Çalışma Soruları

Hoca derse yeni bir haftanın başladığını söyleyerek girdi ve bugünkü "bilimsel ziyafetin" çalışma soruları olduğunu belirtti. Önce öğrencilere özellikle çözülmesini istedikleri bir konu olup olmadığını sordu. Böyle bir istek gelmeyince ekranını paylaştı ve bir PDF'teki soruları sırayla çözmeye başladı.

Hoca bugünkü soruların neden seçildiğini de açıkladı: vektör fonksiyonları ve tanım kümeleri, çok değişkenli fonksiyonlarda tanım bölgesi, limit, süreklilik ve eğri uzunluğu.

> **Hocanın vurgusu:** Finalde süreklilik, limit, eğri uzunluğu ve tanım bölgesinden mutlaka soru gelecek. Bu yüzden bu konulara iyi hazırlanmak gerekiyor (00:06:01, 01:10:01).

Hoca soruların "orijinal" ve çeldiricisi iyi kurulmuş sorular olduğunu sık sık vurguladı. Yöntemi bilmenin yetmediğini, türevleri ve cebirsel düzenlemeleri hatasız yapmanın da şıkka ulaşmak için şart olduğunu söyledi.

## 2. Vektör Değerli Fonksiyonlar

### 2.1 Hız ve İvme Vektörleri Arasındaki Açı

İlk soruda uzayda hareket eden bir parçacığın $t$ anındaki konum vektörü verilmişti. Sorulan, $t=0$ anında hız vektörü ile ivme vektörü arasındaki açıydı.

Hoca önce kavramları hatırlattı:

- **Hız vektörü:** Konum vektörünün birinci türevidir: $\vec v(t)=\vec r\,'(t)$. Her bileşenin türevi ayrı ayrı alınır.
- **İvme vektörü:** Hızın bir kez daha türevidir: $\vec a(t)=\vec v\,'(t)=\vec r\,''(t)$.
- **İki vektör arasındaki açı:** İki vektörün iç çarpımı, boylarının çarpımı ile aradaki açının kosinüsünün çarpımıdır:

$$\vec v\cdot\vec a=|\vec v|\,|\vec a|\cos\theta\quad\Longrightarrow\quad \cos\theta=\frac{\vec v\cdot\vec a}{|\vec v|\,|\vec a|}.$$

Hoca bu soruda yalnız yöntemi anlattı: türev al, ikinci türevi al, $t=0$ koy, iki vektörün boylarını bul ve kosinüsü hesapla. Sayısal sonuç derste sesli okunmadı. Aşağıdaki hesap hocanın yöntemiyle yapıldı (ara adımlar eklendi).

**Örnek 1.** $\vec r(t)=\dfrac{\sqrt2}{2}t\,\vec i+\left(\dfrac{\sqrt2}{2}t-16t^2\right)\vec j$ olsun. $t=0$ anında $\vec v$ ile $\vec a$ arasındaki açıyı bulalım.

- Hız: $\vec v(t)=\left\langle \dfrac{\sqrt2}{2},\ \dfrac{\sqrt2}{2}-32t\right\rangle$, dolayısıyla $\vec v(0)=\left\langle \dfrac{\sqrt2}{2},\ \dfrac{\sqrt2}{2}\right\rangle$ ve $|\vec v(0)|=1$.
- İvme: $\vec a(t)=\langle 0,\,-32\rangle$, $|\vec a|=32$.
- İç çarpım: $\vec v(0)\cdot\vec a(0)=0\cdot\dfrac{\sqrt2}{2}+\dfrac{\sqrt2}{2}\cdot(-32)=-16\sqrt2$.
- Kosinüs: $\cos\theta=\dfrac{-16\sqrt2}{1\cdot 32}=-\dfrac{\sqrt2}{2}$.
- Sonuç: $\theta=\dfrac{3\pi}{4}$.

### 2.2 Vektör Fonksiyonun Tanım Kümesi

İkinci soruda $t$ parametresine bağlı bir vektör fonksiyonu verilmiş ve tanım kümesi sorulmuştu. Hocanın yöntemi şuydu: Her bileşenin tanım kümesi ayrı ayrı bulunur, sonra bunların kesişimi alınır.

**Örnek 2.** $\vec F(t)=e^t\,\vec i+\sin t\,\vec j+3\ln(1-t)\,\vec k$.

- $e^t$ bütün reel sayılarda tanımlıdır.
- $\sin t$ de bütün reel sayılarda tanımlıdır.
- $\ln(1-t)$ için logaritmanın içi pozitif olmalıdır: $1-t>0$, yani $t<1$.
- Üç kümenin kesişimi: $(-\infty,\,1)$.

### 2.3 Uzay Eğrisinin Teğet Doğrusu

Üçüncü soruda bir uzay eğrisi ve üzerindeki bir nokta verilmiş, o noktadaki teğet doğrusunun (tangent line) denklemi sorulmuştu.

Hoca bileşenleri adlandırarak başladı: $\vec i$ bileşenine $x$, $\vec j$ bileşenine $y$, $\vec k$ bileşenine $z$ dedi. Teğet doğrusunun yön vektörü, eğrinin o noktadaki türev vektörüdür. Doğru, $(x_0,y_0,z_0)$ noktasından geçen ve $\vec v=\langle v_1,v_2,v_3\rangle$ yönündeki doğrudur:

$$x=x_0+v_1t,\qquad y=y_0+v_2t,\qquad z=z_0+v_3t.$$

Noktaya karşılık gelen parametre değerini bulmak için her bileşen, noktanın ilgili koordinatına eşitlenir. Üç denklemi birden sağlayan $t$ aranır.

**Örnek 3.** $\vec r(t)=(3t^2+1)\,\vec i+(4t^3-3)\,\vec j+(6t+2)\,\vec k$ eğrisinin $(4,1,8)$ noktasındaki teğet doğrusu.

- Türev: $\vec r\,'(t)=6t\,\vec i+12t^2\,\vec j+6\,\vec k$.
- Parametre değeri: $4=3t^2+1$, $1=4t^3-3$, $8=6t+2$. Üç denklemin ortak çözümü $t=1$'dir.
- Yön vektörü: $\vec r\,'(1)=\langle 6,\,12,\,6\rangle$.
- Teğet doğrusu: $x=4+6t$, $y=1+12t$, $z=8+6t$.

Hoca şıkları kontrol ederken $4+6t$, $1+12t$ ve $8+6t$ bileşenlerini tek tek doğruladı.

## 3. Parametrik Uzay Eğrilerinde Yay Uzunluğu

Hoca dördüncü ve beşinci soruda yay uzunluğu (arc length) formülünü hatırlattı. Eğri $\vec r(t)=x(t)\,\vec i+y(t)\,\vec j+z(t)\,\vec k$ ise, $a\le t\le b$ aralığındaki uzunluk, hız vektörünün normunun integralidir:

$$L=\int_a^b|\vec r\,'(t)|\,dt=\int_a^b\sqrt{\left(\frac{dx}{dt}\right)^2+\left(\frac{dy}{dt}\right)^2+\left(\frac{dz}{dt}\right)^2}\,dt.$$

Hoca bunun parametrik fonksiyonlardaki eğri uzunluğu formülüyle aynı mantıkta olduğunu söyledi. Önemli olanın mantığı anlamak olduğunu, gerisinin değerleri yerine koymak olduğunu ekledi.

### 3.1 Uzunluğu Veren İntegral

**Örnek 4.** $\vec r(t)=\langle e^t\cos t,\ e^t\sin t,\ e^t\rangle$ eğrisinin $0\le t\le 1$ aralığındaki uzunluğunu veren integral.

Hoca $x'$ için çarpımın türevini kullanmak gerektiğini söyledi: birincinin türevi çarpı ikinci, artı birinci çarpı ikincinin türevi. Hesap şöyle tamamlanır (ara adımlar eklendi):

- $x'=e^t(\cos t-\sin t)$, $y'=e^t(\sin t+\cos t)$, $z'=e^t$.
- $x'^2+y'^2=e^{2t}\big[(\cos t-\sin t)^2+(\sin t+\cos t)^2\big]=2e^{2t}$.
- $x'^2+y'^2+z'^2=3e^{2t}$, dolayısıyla $|\vec r\,'(t)|=\sqrt3\,e^t$.
- İntegral: $L=\displaystyle\int_0^1\sqrt3\,e^t\,dt$. Değeri $\sqrt3\,(e-1)$'dir.

### 3.2 Yay Uzunluğunun Hesabı

**Örnek 5.** $\vec r(t)=(1+t^2)^{3/2}\,\vec i+(3-t^2)^{3/2}\,\vec j+4t^2\,\vec k$, $-1\le t\le 1$.

Hoca burada da aynı yöntemi kurdu ve sınırları $-1$ ile $+1$ olarak yazdı. Sayısal sonuç derste sesli okunmadı. Hesap şöyledir (ara adımlar eklendi):

- $x'=\dfrac32(1+t^2)^{1/2}\cdot 2t=3t\sqrt{1+t^2}$.
- $y'=\dfrac32(3-t^2)^{1/2}\cdot(-2t)=-3t\sqrt{3-t^2}$.
- $z'=8t$.
- $x'^2+y'^2+z'^2=9t^2(1+t^2)+9t^2(3-t^2)+64t^2=36t^2+64t^2=100t^2$.
- $|\vec r\,'(t)|=10|t|$ ve $L=\displaystyle\int_{-1}^{1}10|t|\,dt=2\int_0^1 10t\,dt=10$.

> **Hocanın vurgusu:** Bu sorularda yöntemi herkes biliyor. Doğru şıkka ulaşmak için türevi doğru almak ve işlem hatası yapmamak gerekiyor (01:15:45, 01:16:14).

## 4. İki Değişkenli Fonksiyonlarda Tanım Bölgesi

Tanım bölgesi sorularında hoca her parçanın koşulunu ayrı ayrı yazıp sonra kesişim aldı. Kullanılan koşullar şunlardı:

- $\arccos u$ için $-1\le u\le 1$.
- $\ln u$ için $u>0$ (eşitlik yok).
- $\sqrt u$ için $u\ge 0$.
- Payda sıfır olamaz.

### 4.1 arccos, ln ve Payda Koşulu

**Örnek 6.** $f(x,y)=\arccos\dfrac{y}{x^2}+\ln(1-x^2)$ fonksiyonunun tanım bölgesi.

- `arccos` koşulu: $-1\le \dfrac{y}{x^2}\le 1$. $x^2>0$ olduğundan $x^2$ ile çarpınca eşitsizlik yön değiştirmez: $-x^2\le y\le x^2$.
- `ln` koşulu: $1-x^2>0$, yani $x^2<1$, dolayısıyla $-1<x<1$. Eşitlik olmadığı için $\pm1$ hariçtir.
- Payda koşulu: $x^2$ paydada olduğu için $x\ne 0$ olmalıdır. Aksi halde $y/0$ tanımsız olur.
- Sonuç: $-x^2\le y\le x^2$, $x\in(-1,0)\cup(0,1)$.

Hoca şıkları incelerken ilk şıkkın $x\ne0$ koşulu olmadan verildiğini gösterdi. Bu şık hızlı okuyan birini yanıltır.

> **Hocanın vurgusu:** Paydadaki sıfıra dikkat edin. Çeldirici tam bu ayrıntıyla kurulmuş, çok kişiyi eleme şansı olan bir soru. Gözlerimizi açıp dikkatli okuyoruz (00:18:29-00:19:22).

### 4.2 Kök ve Paydada ln

**Örnek 7.** $f(x,y)=\dfrac{\sqrt{x-y^2}}{\ln(x-2)}$ fonksiyonunun tanım bölgesini çiziniz.

Hoca koşulları şöyle sıraladı:

- Payda sıfır olamaz.
- `ln` tanımlı olmalı: $x-2>0$, yani $x>2$.
- Kök içi negatif olamaz: $x-y^2\ge 0$, yani $x\ge y^2$. Sınır eğrisi $x=y^2$ sağa açılan paraboldür ve eşitlik olduğu için bölgeye dahildir.

Bölge, $x>2$ dikey şeridi ile parabolün içinin ($x\ge y^2$) kesişimidir.

> **Ders sonrası not:** Hoca payda koşulunu "$x-2\ne0$, yani $x\ne2$" olarak yazdı. Bu koşul $x>2$ içinde zaten vardır. Paydadaki ifade $\ln(x-2)$ olduğu için doğru koşul $\ln(x-2)\ne0$, yani $x-2\ne1$, $x\ne3$'tür. Doğru bölge: $x>2$, $x\ge y^2$, $x\ne3$.

### 4.3 Çarpanlara Ayırma ile Tanım Bölgesi

**Örnek 8.** $f(x,y)=\ln(y^2x-1+y^2-x)$ fonksiyonunun tanım bölgesini çiziniz.

Hoca bunun daha önce sorulmuş bir sınav sorusu olduğunu söyledi ve öğrencilere bir dakika süre verip yerinde çözmelerini istedi. Ekran paylaşımı bir süre karıştı. Hoca boş bir tahta açtı ve bir öğrenci soruyu sesli okudu.

- Gruplama: $y^2x+y^2-x-1=y^2(x+1)-(x+1)=(y^2-1)(x+1)$.
- `ln` koşulu: $(y^2-1)(x+1)>0$. Çarpımın pozitif olması için iki çarpan aynı işaretli olmalıdır.
- **Durum 1:** $y^2-1>0$ ve $x+1>0$. Yani ($y>1$ ya da $y<-1$) ve $x>-1$.
- **Durum 2:** $y^2-1<0$ ve $x+1<0$. Yani $-1<y<1$ ve $x<-1$.

Hoca tahtada $y=1$, $y=-1$ ve $x=-1$ doğrularını çizdi. Birinci durum $x=-1$'in sağında, $y=1$'in üstü ile $y=-1$'in altındaki iki bölgedir. İkinci durum $x=-1$'in solunda, $-1<y<1$ şerididir. Tanım bölgesi bu parçaların birleşimidir. Sınır doğruları bölgeye dahil değildir.

<!-- BELİRSİZ: Hoca birinci durumu yazarken bir an "x eksi birden küçük" dedi, hemen "tam tersi" diyerek düzeltti; çizimin kendisi altyazıda yalnız sözlü anlatılıyor. -->

### 4.4 arccos ve Kök İçinde ln

**Örnek 9.** $f(x,y)=\arccos\dfrac{x}{y^2}+\sqrt{\ln(1-xy)}$ fonksiyonunun tanım kümesi.

- `arccos` koşulu: $-1\le\dfrac{x}{y^2}\le1$, yani $-y^2\le x\le y^2$.
- Payda koşulu: $y\ne0$.
- Kök koşulu: $\ln(1-xy)\ge0$.

Hoca burada önemli bir noktayı vurguladı: $0$ ile $1$ arasındaki sayıların logaritması negatiftir. Bu yüzden $\ln(1-xy)\ge0$ için logaritmanın içi en az $1$ olmalıdır: $1-xy\ge1$. Buradan $xy\le0$ çıkar. Bu koşul $1-xy>0$ koşulunu da kendiliğinden sağlar.

- Sonuç: $\{(x,y)\mid -y^2\le x\le y^2,\ xy\le0,\ y\ne0\}$.

Hoca şıklarda $y\ne0$ koşulunun yalnız bir şıkta bulunduğunu, bir önceki soruda dikkat çektiği paydanın bu soruda doğru şıkkı ayırdığını söyledi.

> **Ders sonrası not:** Hoca $1-xy\ge1$ koşulundan "$x$ sıfırdan küçük olacak" dedi ve bir an "$x$ bir olabilir" gibi bir ifade kullandı. Doğru sonuç $xy\le0$'dır; bu, $x$ ve $y$'nin zıt işaretli olması ya da $x=0$ olması demektir.

## 5. İki Değişkenli Limitlerin Hesabı

Molanın ardından hoca limit sorularına geçti. Bu bölümdeki üç soruda limit hesaplanabiliyordu. Yöntemler tek değişkenli limitlerdekilerle aynıydı.

### 5.1 Eşlenikle Çarpma

**Örnek 10.** $\displaystyle\lim_{(x,y)\to(0^+,\,2^-)}\frac{x+y-2}{\sqrt x+\sqrt{2-y}}$.

Hoca önce değerleri yerine koydu: $x\to0$ sağdan, $y\to2$ soldan. $\frac00$ belirsizliği çıktı. Birinci dönemdeki köklü ifadelere benzer şekilde eşlenikle çarpmak gerektiğini söyledi. İki kare farkı ile düzenleme şöyledir (ara adım eklendi):

$$x+y-2=x-(2-y)=(\sqrt x-\sqrt{2-y})(\sqrt x+\sqrt{2-y}).$$

Sadeleşince ifade $\sqrt x-\sqrt{2-y}$ olur ve limit $0-0=0$'dır.

### 5.2 sin u / u Kalıbı

**Örnek 11.** $\displaystyle\lim_{(x,y)\to(0,0)}\frac{e^{xy}\sin(xy)}{xy}$.

Hoca bunun "10 saniyelik" ama bilgi isteyen bir soru olduğunu söyledi. $u=xy\to0$ olduğundan $\dfrac{\sin(xy)}{xy}\to1$ ve $e^{xy}\to e^0=1$'dir. Limit $1$'dir.

Ders sonundaki tekrarda hoca bu kalıbı genelleştirdi: $(x,y)\to(0,0)$ iken $f(x,y)\to0$ ise

$$\lim\frac{\sin f(x,y)}{f(x,y)}=1,\qquad \lim\frac{\tan f(x,y)}{f(x,y)}=1.$$

> **Hocanın vurgusu:** Bu bilgi çok kıymetli. Ne kadar çok soru çözersek bu tür kalıpları kullanma becerimiz o kadar artar (00:55:32, 01:17:22).

### 5.3 Yine Eşlenik

**Örnek 12.** $\displaystyle\lim_{(x,y)\to(0,0)}\frac{x^2+y^2}{1-\sqrt{1+x^2+y^2}}$.

Hoca burada da $\frac00$ belirsizliği olduğunu, paydayı eşleniğiyle (artı işaretli köklü ifadeyle) çarpmak gerektiğini söyledi. Sonuç derste sesli okunmadı. Hesap şöyledir (ara adımlar eklendi). $u=x^2+y^2$ diyelim:

$$\frac{u}{1-\sqrt{1+u}}\cdot\frac{1+\sqrt{1+u}}{1+\sqrt{1+u}}=\frac{u(1+\sqrt{1+u})}{1-(1+u)}=-(1+\sqrt{1+u})\ \longrightarrow\ -2.$$

Hoca bu soruda "soru ilmin yarısıdır" diyerek öğrencilerden anlamadıkları yeri sormalarını istedi. Sorgulanmayan bilginin hafızaya yerleşmediğini söyledi.

## 6. Limitin Yokluğu ve Süreklilik

Bu bölümdeki sorularda temel fikir şudur: $(0,0)$'a farklı yollardan yaklaşınca farklı limit değerleri çıkıyorsa limit yoktur. Yol bir $m$ (ya da $k$) parametresine bağlı seçilir. Sonuç $m$'ye bağlı çıkarsa, $m$ değiştikçe değer değişir. Limit varsa tek olmalıdır, bu yüzden limit yoktur. Limit yoksa fonksiyon o noktada sürekli de değildir.

Süreklilik için hoca şu koşulu hatırlattı: Fonksiyon noktada tanımlı olmalı, limit var olmalı ve limit fonksiyonun o noktadaki değerine eşit olmalıdır.

> **Ek bilgi (derste anlatılmadı):** Yol testi yalnız limitin yokluğunu kanıtlayabilir. Bütün doğrular boyunca aynı değer çıksa bile limit var olmayabilir; Örnek 13 ve 15'teki fonksiyonlar bunun tipik örnekleridir. Limitin varlığını göstermek için sıkıştırma teoremi ya da kutupsal koordinatlar gibi bütün yaklaşımları kapsayan bir yöntem gerekir.

### 6.1 Parçalı Fonksiyon: Hangi İfadeler Doğru?

**Örnek 13.**

$$f(x,y)=\begin{cases}\dfrac{3xy}{x^2+y^2}, & (x,y)\ne(0,0)\\[2mm] 0, & (x,y)=(0,0)\end{cases}$$

Aşağıdakilerden hangileri doğrudur?

- I. $f$, $(0,0)$ noktasında tanımlıdır.
- II. $(0,0)$'a $y=x^2$ eğrisi boyunca yaklaşırken limit $0$'dır.
- III. $(0,0)$'daki limit $0$'dır.
- IV. $f$, $(0,0)$'da süreklidir.

Çözüm:

- I doğrudur, çünkü $f(0,0)=0$ verilmiştir.
- II: $y=x^2$ yazınca $\dfrac{3x\cdot x^2}{x^2+x^4}=\dfrac{3x}{1+x^2}\to0$. Doğrudur.
- III: $y=mx$ doğrusu boyunca $\dfrac{3x\cdot mx}{x^2+m^2x^2}=\dfrac{3m}{1+m^2}$ çıkar. Bu değer $m$'ye bağlıdır, limit yoktur. Yanlıştır.
- IV: Limit olmadığı için fonksiyon sürekli değildir. Yanlıştır.
- Cevap: Yalnız I ve II.

Hoca ders sonundaki tekrarda bu sonucu açıkça verdi: "$y=x^2$ ile gidersen limit var gözüküyor, $0$ gözüküyor; ama $y=kx$ ya da $y=mx$ ile gidersen $k$'ya bağlı çıkıyor, limit yok" (01:21:31).

> **Ders sonrası not:** Hoca soruyu ilk çözerken $y=x^2$ yolunda paydayı bir an $x^4$'lü yazdı ve II için önce "yanlış", hemen sonra "doğru" dedi. Ardından $y=mx$ yolunun işe yaramadığını söyleyip fonksiyonu bir an $\dfrac{3xy}{x^2+y^4}$ gibi yazarak $x=my^2$ yolunu denedi ve "limit sıfırdır, süreklidir" dedi (00:59:11-01:01:11). Bu yanlıştır: verilen fonksiyonda $y=mx$ boyunca sonuç $\dfrac{3m}{1+m^2}$'dir, limit yoktur ve fonksiyon süreksizdir. Hoca da ders sonundaki tekrarda doğru sonucu (yalnız I ve II) verdi.

### 6.2 Limitin Mevcudiyeti ve L'Hôpital

**Örnek 14.** $\displaystyle\lim_{(x,y)\to(0,0)}\frac{x\ln(1+y)}{x^2+y^2}$ limitinin mevcudiyetini araştırınız.

<!-- BELİRSİZ: Fonksiyon ekrandan okunuyor; altyazıda yalnız y=mx yerleştirmesinden sonraki hali ("x çarpı ln(1+mx) bölü x kare artı m kare x kare") geçiyor. Yukarıdaki ifade bu okumadan geri kurulmuştur. -->

Hoca önce $(0,0)$ koydu ve $\frac00$ belirsizliği çıktığını gösterdi. Sonra $y=mx$ doğrusu boyunca yaklaştı. Hangi değişkenin diğerine bağlandığının fark etmediğini ($y=mx$ ya da $x=my$) söyledi:

$$\lim_{x\to0}\frac{x\ln(1+mx)}{x^2+m^2x^2}.$$

$x=0$ koyunca yine $\frac00$ çıkar. Hoca L'Hôpital kuralını (L'Hôpital's rule) kullandı: payın türevi paya, paydanın türevi paydaya yazılır. Sonuç $m$'ye bağlı bir değer çıkar, dolayısıyla limit yoktur. Hesap şöyle tamamlanır (ara adım eklendi): $\dfrac{x\ln(1+mx)}{x^2(1+m^2)}=\dfrac{\ln(1+mx)}{x(1+m^2)}\to\dfrac{m}{1+m^2}$.

### 6.3 İki Fonksiyonun Sürekliliği

**Örnek 15.** $g(x,y)=\dfrac{xy^2}{x^2+y^4}$, $g(0,0)=0$ ve $f(x,y)=x\sin\dfrac1y$, $f(0,0)=0$ fonksiyonlarının $(0,0)$'daki sürekliliği için hangisi doğrudur? Şıklar: $g$ sürekli $f$ süreksiz; $g$ sürekli $f$ sürekli; $g$ süreksiz $f$ sürekli; $g$ süreksiz $f$ süreksiz.

<!-- BELİRSİZ: g ve f'nin tam ifadeleri ekrandan okunuyor; altyazıda g için "y üzeri 4, y kare, x kare" ve x=my^2 yerleştirmesi, f için "x çarpı sinüs bir bölü y" geçiyor. İfadeler bu okumalarla tutarlıdır. -->

**$g$ için:** Hoca paydada $x^2$ ve $y^4$, payda $y^2$ olduğuna dikkat çekti. $x^2$'yi $y^4$ ile aynı kuvvete getirmek için $x=my^2$ dönüşümü yapılır:

$$\lim_{y\to0}\frac{my^2\cdot y^2}{m^2y^4+y^4}=\lim_{y\to0}\frac{m\,y^4}{(m^2+1)y^4}=\frac{m}{1+m^2}.$$

Sonuç $m$'ye bağlıdır. Limit yoktur, dolayısıyla $g$ süreksizdir. Hoca "$g$ süreklidir" diyen şıkları hemen eledi.

**$f$ için:** $-1\le\sin\dfrac1y\le1$ olduğundan her taraf $x$ ile çarpılır ve sıkıştırma teoremi (squeeze theorem) uygulanır. $x\to0$ iken iki uç da $0$'a gittiği için ortadaki limit de $0$'dır. Bu değer $f(0,0)=0$'a eşittir, dolayısıyla $f$ süreklidir.

- Cevap: $g$ süreksiz, $f$ sürekli.

> **Ek bilgi (derste anlatılmadı):** Sıkıştırma adımı mutlak değerle yazılınca işaret sorunu ortadan kalkar: $\left|x\sin\frac1y\right|\le|x|$ ve $|x|\to0$. Hocanın "her tarafı $x$ ile çarparız" adımı $x<0$ için eşitsizliklerin yön değiştirmesini gerektirir; mutlak değerli yazım her iki durumu birden kapsar.

> **Hocanın vurgusu:** Bu, tekrar tekrar sorulabilecek bir soru (01:06:38).

### 6.4 Küp Köklü Fonksiyon

**Örnek 16.**

$$f(x,y)=\begin{cases}\dfrac{\sqrt[3]{x}\,y^2}{x+y^3}, & (x,y)\ne(0,0)\\[2mm] 0, & (x,y)=(0,0)\end{cases}$$

Aşağıdakilerden hangileri doğrudur? I. $(0,0)$'da tanımlıdır. II. $(0,0)$'da limiti mevcuttur. III. $(0,0)$'da süreksizdir çünkü limiti $1$'dir. IV. $(0,0)$'da süreksizdir çünkü limiti yoktur.

Hoca yol seçiminin mantığını vurguladı: $y=mx$ ya da $x=my$ denebilir, ama burada küp kök var. Bu yüzden $x=my^3$, hatta daha iyisi $x=m^3y^3$ seçilir. Böylece $\sqrt[3]{x}=my$ olur ve kökün dışına çıkar:

$$\lim_{y\to0}\frac{my\cdot y^2}{m^3y^3+y^3}=\lim_{y\to0}\frac{m\,y^3}{(m^3+1)y^3}=\frac{m}{m^3+1}.$$

Pay ve paydadaki $y^3$'ler sadeleşir. Sonuç $m$'ye bağlıdır, limit yoktur.

- I doğrudur ($f(0,0)=0$ verilmiştir).
- II yanlıştır, limit yoktur.
- III yanlıştır, limit $1$ diye bir şey yoktur.
- IV doğrudur, limit olmadığı için süreksizdir.
- Cevap: I ve IV.

> **Hocanın vurgusu:** "Soru çözdüm" demek yetmez. Aynı tipte soru çözüp üzerinde düşünmek gerekir: Bu işin mantığı ne, nasıl bir dönüşüm yapmak lazım? Yolu, kuvvetler eşitlenecek şekilde seçin (01:07:40-01:08:27).

> **Ek bilgi (derste anlatılmadı):** Kuvvet eşitleme fikri genel bir kuraldır: Paydada $x^a$ ile $y^b$ toplanıyorsa $x=my^{b/a}$ yolu iki terimi aynı mertebeye getirir. Örnek 15'te $x^2$ ve $y^4$ için $x=my^2$, Örnek 16'da $x$ ve $y^3$ için $x=m^3y^3$ bu kuralın uygulamasıdır.

## 7. Derste Yapılan Genel Tekrar

Son sorudan sonra hoca PDF'i baştan açıp bütün soruları kısaca tekrar etti:

- Soru 1: Hız birinci türev, ivme ikinci türevdir. $t=0$'da iki vektör bulunur, aradaki açı kosinüs formülüyle hesaplanır.
- Soru 2: Bileşenlerin tanım kümelerinin kesişimi alınır.
- Soru 3: Bileşenlere $x$, $y$, $z$ denir. Noktayı veren $t$ bulunur, türev vektörü yön vektörü olur. Doğru $x=x_0+v_1t$, $y=y_0+v_2t$, $z=z_0+v_3t$ biçimindedir.
- Soru 4 ve 5: Türevler alınır, kareleri toplanır, kök içinde integre edilir. Burada doğru türev almak belirleyicidir.
- Soru 6-9: Tanım bölgesi; paydanın sıfır olmaması ve $y\ne0$ gibi koşullar doğru şıkkı ayırır.
- Soru 10-12: Köklü ifadelerde eşlenikle çarpma ve $\frac{\sin f}{f}\to1$ kalıbı.
- Soru 13-16: Yol testi, L'Hôpital, sıkıştırma teoremi ve süreklilik.

<!-- BELİRSİZ: 01:18:25-01:20:47 arasında hocanın sesi gelmiyor; bu aralıkta Soru 13'ün tekrarının bir kısmı altyazıda yok. -->

## Örnek Sorular

Bu dersteki bütün sorular hocanın ekranda paylaştığı final hazırlık çalışma sorularıdır. Çözümler yukarıdaki bölümlerde adım adım verildi; burada soru metinleri ve sonuçlar toplanmıştır.

**Soru 1** (derste sözlü, 00:03:48). Uzaydaki bir parçacığın $t$ anındaki konum vektörü $\vec r(t)=\frac{\sqrt2}{2}t\,\vec i+\left(\frac{\sqrt2}{2}t-16t^2\right)\vec j$ olmak üzere, $t=0$ anında hız vektörü ile ivme vektörü arasındaki açı nedir?

> **Çözüm (derste verilmedi):** $\vec v(0)=\langle\frac{\sqrt2}{2},\frac{\sqrt2}{2}\rangle$, $\vec a=\langle0,-32\rangle$, $\cos\theta=-\frac{\sqrt2}{2}$, $\theta=\frac{3\pi}{4}$ (Bölüm 2.1). Derste yalnız yöntem anlatıldı.

**Soru 2** (derste sözlü, 00:05:31). $\vec F(t)=e^t\,\vec i+\sin t\,\vec j+3\ln(1-t)\,\vec k$ vektör fonksiyonunun tanım kümesi nedir?

- Çözüm (derste): $t<1$, yani $(-\infty,1)$.

**Soru 3** (derste sözlü, 00:07:27). $\vec r(t)=(3t^2+1)\vec i+(4t^3-3)\vec j+(6t+2)\vec k$ eğrisinin $(4,1,8)$ noktasındaki teğet doğrusunun denklemi nedir?

- Çözüm (derste): $t=1$, $\vec r\,'(1)=\langle6,12,6\rangle$; $x=4+6t$, $y=1+12t$, $z=8+6t$.

**Soru 4** (derste sözlü, 00:12:29). $\vec r(t)=\langle e^t\cos t,\,e^t\sin t,\,e^t\rangle$ eğrisinin $0\le t\le1$ arasındaki uzunluğunu veren integral nedir?

- Çözüm (derste yöntem, integralin son hali hesaplandı): $L=\int_0^1\sqrt3\,e^t\,dt$.

**Soru 5** (derste sözlü, 00:15:16). $\vec r(t)=(1+t^2)^{3/2}\vec i+(3-t^2)^{3/2}\vec j+4t^2\vec k$ eğrisinin $-1\le t\le1$ aralığındaki yay uzunluğu nedir?

> **Çözüm (derste verilmedi):** $|\vec r\,'(t)|=10|t|$, $L=10$ (Bölüm 3.2).

**Soru 6** (derste sözlü, 00:16:45). $f(x,y)=\arccos\frac{y}{x^2}+\ln(1-x^2)$ fonksiyonunun tanım bölgesi nedir?

- Çözüm (derste): $-x^2\le y\le x^2$, $-1<x<1$, $x\ne0$.

**Soru 7** (derste sözlü, 00:19:53). $f(x,y)=\frac{\sqrt{x-y^2}}{\ln(x-2)}$ fonksiyonunun tanım bölgesini çiziniz.

- Çözüm: $x>2$, $x\ge y^2$, $x\ne3$ (hocanın $x\ne2$ koşulu için Bölüm 4.2'deki ders sonrası nota bakın).

**Soru 8** (derste sözlü, 00:23:01; geçmiş sınav sorusu). $f(x,y)=\ln(y^2x-1+y^2-x)$ fonksiyonunun tanım bölgesini çiziniz.

- Çözüm (derste): $(y^2-1)(x+1)>0$; ($|y|>1$, $x>-1$) ya da ($|y|<1$, $x<-1$).

**Soru 9** (derste sözlü, 00:30:39). $f(x,y)=\arccos\frac{x}{y^2}+\sqrt{\ln(1-xy)}$ fonksiyonunun tanım kümesi nedir?

- Çözüm: $-y^2\le x\le y^2$, $xy\le0$, $y\ne0$.

**Soru 10** (derste sözlü, 00:54:16). $\lim_{(x,y)\to(0^+,2^-)}\frac{x+y-2}{\sqrt x+\sqrt{2-y}}$ kaçtır?

- Çözüm (derste yöntem): Eşlenikle sadeleştirme; limit $0$.

**Soru 11** (derste sözlü, 00:55:04). $\lim_{(x,y)\to(0,0)}\frac{e^{xy}\sin(xy)}{xy}$ kaçtır?

- Çözüm (derste): $1$.

**Soru 12** (derste sözlü, 00:56:08). $\lim_{(x,y)\to(0,0)}\frac{x^2+y^2}{1-\sqrt{1+x^2+y^2}}$ kaçtır?

> **Çözüm (derste verilmedi):** Eşlenikle çarpınca $-(1+\sqrt{1+x^2+y^2})\to-2$ (Bölüm 5.3). Derste yalnız yöntem söylendi.

**Soru 13** (derste sözlü, 00:57:24). $f(x,y)=\frac{3xy}{x^2+y^2}$, $f(0,0)=0$ için I. $(0,0)$'da tanımlı, II. $y=x^2$ boyunca limit $0$, III. $(0,0)$'daki limit $0$, IV. $(0,0)$'da sürekli ifadelerinden hangileri doğrudur?

- Çözüm (derste, tekrar sırasında): Yalnız I ve II.

**Soru 14** (derste sözlü, 01:01:26). $\lim_{(x,y)\to(0,0)}\frac{x\ln(1+y)}{x^2+y^2}$ limitinin mevcudiyetini araştırınız. <!-- BELİRSİZ: Fonksiyon ifadesi altyazıdaki y=mx yerleştirmesinden geri kurulmuştur. -->

- Çözüm (derste): $y=mx$ ve L'Hôpital ile $\frac{m}{1+m^2}$; limit yok.

**Soru 15** (derste sözlü, 01:03:13). $g(x,y)=\frac{xy^2}{x^2+y^4}$ ve $f(x,y)=x\sin\frac1y$ (ikisi de $(0,0)$'da $0$) fonksiyonlarının $(0,0)$'daki sürekliliği için hangisi doğrudur?

- Çözüm (derste): $g$ süreksiz ($x=my^2$ ile $\frac{m}{1+m^2}$), $f$ sürekli (sıkıştırma teoremi).

**Soru 16** (derste sözlü, 01:07:14). $f(x,y)=\frac{\sqrt[3]{x}\,y^2}{x+y^3}$, $f(0,0)=0$ için I. tanımlı, II. limiti mevcut, III. limiti $1$ olduğu için süreksiz, IV. limiti olmadığı için süreksiz ifadelerinden hangileri doğrudur?

- Çözüm (derste): $x=m^3y^3$ ile $\frac{m}{m^3+1}$; I ve IV doğru.

## Dersin Toparlaması

Bu ders, final öncesi bir soru çözüm dersiydi. Vektör fonksiyonlarında hız ve ivmenin türevle bulunduğu, iki vektör arasındaki açının iç çarpımla hesaplandığı, vektör fonksiyonun tanım kümesinin bileşenlerin tanım kümelerinin kesişimi olduğu ve teğet doğrusunun türev vektörüyle kurulduğu görüldü. Yay uzunluğu için $L=\int|\vec r\,'(t)|\,dt$ formülü iki soruda uygulandı; burada asıl zorluğun türevleri doğru alıp kök içini sadeleştirmek olduğu vurgulandı.

Çok değişkenli fonksiyonlarda tanım bölgesi bulunurken `arccos`, `ln`, kök ve payda koşulları ayrı ayrı yazılıp kesiştirildi; paydanın sıfır olmaması gibi küçük koşulların çeldirici şıkları ayırdığı gösterildi. Limit sorularında eşlenikle çarpma ve $\frac{\sin u}{u}\to1$ kalıbı kullanıldı. Limitin yokluğu, kuvvetleri eşitleyecek şekilde seçilen $y=mx$, $x=my^2$, $x=m^3y^3$ yollarıyla gösterildi; limit yoksa fonksiyonun sürekli olamayacağı, sürekliliğin ise sıkıştırma teoremiyle kanıtlanabileceği görüldü. Hoca ertesi gün yeni sorularla final hazırlığına devam edileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
