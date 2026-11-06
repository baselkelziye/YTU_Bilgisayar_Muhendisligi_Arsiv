# Ders 9 Çalışma Özeti

**Tarih:** 27 Mart 2023 (Pazartesi)

## Genel Konular

- Vektörler tekrarı: skaler çarpım, iz düşüm (projection), vektörel çarpım, birim vektör.
- Üç noktadan oluşan vektörler arasındaki açı ve iz düşüm örneği.
- Uzayda doğru: vektör, parametrik ve simetrik denklem, doğru parçası.
- Noktanın uzaydaki bir doğruya uzaklığı.
- Uzayda düzlem: bir nokta ve normalle, üç noktayla düzlem denklemi.
- Düzlemlerin ve doğruların paralelliği, dikliği, kesişimi, ara kesit doğrusu.
- Vektör değerli fonksiyonlar: türev, hız, sürat, ivme, birim teğet vektör, limit, süreklilik, yay uzunluğu.
- Çıkmış sınav soruları (doğru ve düzlem).
- Çok değişkenli fonksiyonlara giriş: tanım ve değer kümesi.
- Temel yüzeyler: küre, elipsoid, paraboloid, silindir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Doğrular ve düzlemlerden sınavda mutlaka bir soru gelir.
- Düzlemlerle ilgili her soruda düzlemin kendisine değil **normaline** bakılır. Paralellik, diklik, açı ve ara kesit doğrusu normallerden bulunur.
- Bir doğru denklemi yazmak için iki şey gerekir: doğru üzerinde bir nokta ve doğruya paralel bir vektör.
- Taraf değiştirirken işaretlere dikkat edin. İşaret hatası sizi yanlış şıkka götürür. Ne kadar çok soru çözerseniz hata o kadar azalır.
- Birim teğet vektör sınavlarda çıkan bir soru tipidir.
- Çok değişkenli fonksiyonun tanım bölgesinden vizede de, finalde de mutlaka soru gelir.
- Yanlış bile olsa cevap vermek, hiç cevap vermemekten iyidir. Soru sorun.
- Kalan konular: seviye eğrileri, limit ve süreklilik (bir sonraki ders), kısmi türev ve çok katlı integraller.

## Kısa Tekrar Notları

- **İz düşüm:** $\vec u$'nun $\vec v$ üzerine dik iz düşümü $\operatorname{proj}_{\vec v}\vec u=\dfrac{\vec u\cdot\vec v}{|\vec v|^2}\,\vec v$.
- **Birim vektör:** $\dfrac{\vec v}{|\vec v|}$. Boyu 1'dir.
- **Paralelkenar alanı:** $|\vec u\times\vec v|$. Üçgen alanı bunun yarısı.
- **Doğru:** $\vec r=\vec r_0+t\vec v$, yani $x=x_0+at$, $y=y_0+bt$, $z=z_0+ct$, $t\in\mathbb R$.
  - İki noktadan ($P$, $Q$) geçen doğru için $\vec v=\overrightarrow{PQ}$.
  - $PQ$ doğru parçası için $0\le t\le1$.
- **Noktanın doğruya uzaklığı:** $d=\dfrac{|\overrightarrow{PS}\times\vec v|}{|\vec v|}$. $P$ doğru üzerinde, $\vec v$ yön vektörü.
- **Düzlem:** $a(x-x_0)+b(y-y_0)+c(z-z_0)=0$, normal $\vec n=\langle a,b,c\rangle$.
- **Üç noktadan geçen düzlem:** normal $\overrightarrow{AB}\times\overrightarrow{AC}$.
- **Düzlem ve düzlem:**
  - $\vec n_1\parallel\vec n_2$ ise düzlemler paralel.
  - $\vec n_1\cdot\vec n_2=0$ ise düzlemler dik.
  - Aradaki açı: $\cos\theta=\dfrac{|\vec n_1\cdot\vec n_2|}{|\vec n_1||\vec n_2|}$.
  - Ara kesit doğrusunun yön vektörü $\vec n_1\times\vec n_2$.
- **Doğru ve düzlem:**
  - $\vec v\cdot\vec n=0$ ise doğru düzleme paralel.
  - $\vec v\parallel\vec n$ ise doğru düzleme dik.
- **Kesişimler:** doğru ∩ doğru = nokta, doğru ∩ düzlem = nokta, düzlem ∩ düzlem = doğru.
- **Vektör değerli fonksiyon:** $\vec r(t)=f(t)\vec i+g(t)\vec j+h(t)\vec k$.
  - Hız $\vec v=\vec r'(t)$, sürat $|\vec v|$, ivme $\vec a=\vec v'(t)$.
  - Birim teğet vektör: $\vec T=\dfrac{\vec r'(t)}{|\vec r'(t)|}$.
  - Yay uzunluğu: $L=\displaystyle\int_a^b\sqrt{f'^2+g'^2+h'^2}\,dt$.
- **Temel yüzeyler:**
  - Küre: $x^2+y^2+z^2=R^2$.
  - Elipsoid: $\dfrac{x^2}{a^2}+\dfrac{y^2}{b^2}+\dfrac{z^2}{c^2}=1$.
  - Paraboloid: $z=x^2+y^2$ (yukarı açık), $z=a-x^2-y^2$ (aşağı açık).
  - Silindir: $x^2+y^2=R^2$ ($z$ boyunca uzanır).

## Detaylı Açıklamalar

### Vektörler tekrarı

- $\vec u\cdot\vec v=|\vec u||\vec v|\cos\theta$. Sonuç sıfırsa vektörler diktir.
- $\vec u$'nun $\vec v$ üzerine iz düşümünün boyu $|\vec u|\cos\theta$'dır. Yönü $\dfrac{\vec v}{|\vec v|}$'dir.
- $\vec u\times\vec v$, iki vektörün bulunduğu düzleme dik bir vektördür. Boyu $|\vec u||\vec v|\sin\theta$'dır ve paralelkenarın alanını verir.

**Örnek 1 (üç nokta, açı, iz düşüm):** $P$, $Q$, $R$ noktalarından $\overrightarrow{PQ}=\langle-2,-2,1\rangle$ ve $\overrightarrow{QR}=\langle6,-1,-1\rangle$ elde edildi.

- $|\overrightarrow{PQ}|=\sqrt{4+4+1}=3$. Birim değildir. Birim vektör: $\left\langle-\dfrac23,-\dfrac23,\dfrac13\right\rangle$.
- $|\overrightarrow{QR}|=\sqrt{36+1+1}=\sqrt{38}$.
- $\overrightarrow{PQ}\cdot\overrightarrow{QR}=-12+2-1=-11$.
- Açı: $\cos\theta=\dfrac{-11}{3\sqrt{38}}$, yani $\theta=\arccos\left(\dfrac{-11}{3\sqrt{38}}\right)$.
- İz düşüm: $\operatorname{proj}_{\overrightarrow{QR}}\overrightarrow{PQ}=\dfrac{-11}{38}\langle6,-1,-1\rangle=\left\langle-\dfrac{66}{38},\dfrac{11}{38},\dfrac{11}{38}\right\rangle$.
- İki vektöre dik vektör: $\overrightarrow{PQ}\times\overrightarrow{QR}$ determinantla bulunur.
- Sınavda "hangisi yanlıştır" diye sorulursa şıklar tek tek kontrol edilir.

### Uzayda doğru

- $P_0(x_0,y_0,z_0)$ doğru üzerinde, $\vec v=\langle a,b,c\rangle$ yön vektörü olsun. Doğru üzerindeki her $P(x,y,z)$ için $\vec r-\vec r_0=t\vec v$.
- Bileşen bileşen: $x=x_0+at$, $y=y_0+bt$, $z=z_0+ct$ (standart parametrik denklem).
- $t$ çekilirse simetrik denklem: $\dfrac{x-x_0}{a}=\dfrac{y-y_0}{b}=\dfrac{z-z_0}{c}$.
- İki doğru paralelse yön vektörleri de paraleldir.

**Örnek 2:** $(-2,0,4)$ noktasından geçen ve $\vec v=\langle2,4,-2\rangle$'ye paralel doğru.

- $x=-2+2t$, $y=4t$, $z=4-2t$.

**Örnek 3:** $P(-3,2,-3)$ ve $Q(1,-1,4)$ noktalarından geçen doğru.

- $\overrightarrow{PQ}=\langle4,-3,7\rangle$.
- $x=-3+4t$, $y=2-3t$, $z=-3+7t$.
- $PQ$ doğru parçası için aynı denklem $0\le t\le1$ ile yazılır.

### Noktanın doğruya uzaklığı

- $S$ noktasının, $P$'den geçen ve $\vec v$'ye paralel doğruya uzaklığı, $\overrightarrow{PS}$ ve $\vec v$'nin oluşturduğu paralelkenarın yüksekliğidir:

$$d=\frac{|\overrightarrow{PS}\times\vec v|}{|\vec v|}.$$

**Örnek 4:** Doğru $P(1,3,0)$'dan geçiyor, $\vec v=\langle1,-1,2\rangle$. Derste $\overrightarrow{PS}=\langle0,-2,5\rangle$ olarak geçiyor.

- $\overrightarrow{PS}\times\vec v=\langle1,5,2\rangle$, boyu $\sqrt{30}$. $|\vec v|=\sqrt6$.
- $d=\sqrt{30}/\sqrt6=\sqrt5$. Hoca sonucu sesli söylemedi, biz hesapladık.

### Uzayda düzlem

- $ax+by+cz+d=0$ bir düzlem denklemidir. $ax+by+c=0$ ise düzlemde bir doğrudur.
- Düzlem, bir nokta $P_0$ ve normal $\vec n$ ile yazılır. $\overrightarrow{P_0P}\cdot\vec n=0$ koşulu $a(x-x_0)+b(y-y_0)+c(z-z_0)=0$ verir.
- Bir doğruya dik düzlem istenirse doğrunun yön vektörü düzlemin normali olur.
- Üç nokta verilirse $\overrightarrow{AB}\times\overrightarrow{AC}$ normali verir. Bir nokta ve bu normalle düzlem yazılır.

### Düzlemler ve doğruların konumu

- Normalleri paralel iki düzlem paraleldir. Normalleri dik iki düzlem diktir.
- İki düzlem arasındaki açı, normalleri arasındaki açıdır.

**Örnek 5 (doğru ile düzlem):** Düzlemin normali $\vec n=\langle1,-2,5\rangle$. Doğru $x=2-t$, $y=-1+2t$, $z=\ldots+t$, yani $\vec v=\langle-1,2,1\rangle$.

- $\vec n\cdot\vec v=-1-4+5=0$. Normal yön vektörüne dik, yani doğru düzleme **paraleldir**.

**Örnek 6 (ara kesit doğrusu):** Normali $\langle3,-2,1\rangle$ olan düzlemle ikinci bir düzlem verilmiş.

- Yön vektörü $\vec n_1\times\vec n_2$ derste $\langle-5,-8,-1\rangle$ bulundu.
- Ara kesit doğrusu üzerinde bir nokta için değişkenlerden birine kolay bir değer verilip iki denklem çözülür. Derste $(1,2,3)$ bulundu.
- $x=1-5t$, $y=2-8t$, $z=3-t$.
- Benzer bir soruda $z=0$ alınarak nokta bulundu.

### Vektör değerli fonksiyonlar

- $\vec r:D\subseteq\mathbb R\to\mathbb R^3$, $\vec r(t)=f(t)\vec i+g(t)\vec j+h(t)\vec k$. $t$ arttıkça uç nokta uzayda bir eğri çizer.
- Türev bileşen bileşen alınır: $\vec r'(t)=f'(t)\vec i+g'(t)\vec j+h'(t)\vec k$. Üç bileşenin de türevli olması gerekir.
- $\vec r'$ sürekli ve hiçbir yerde $\vec 0$ değilse eğri **düzgündür** (smooth).
- $\vec r$ bir parçacığın konum vektörüyse:
  - $\vec v=\vec r'$ hız vektörüdür.
  - $|\vec v|$ sürattir. $\vec r'=\langle a,b,c\rangle$ ise $|\vec v|=\sqrt{a^2+b^2+c^2}$.
  - $\vec a=\vec v'$ ivmedir.
  - $\vec T=\dfrac{\vec v}{|\vec v|}$ birim teğet vektördür, hareketin yönünü gösterir.

**Örnek 7 (çıkmış soru):** $\vec r(t)=3\cos t\,\vec i+3\sin t\,\vec j+t^2\vec k$ için birim teğet vektör.

- $\vec r'(t)=-3\sin t\,\vec i+3\cos t\,\vec j+2t\,\vec k$.
- $|\vec r'(t)|=\sqrt{9\sin^2t+9\cos^2t+4t^2}=\sqrt{9+4t^2}$.
- $\vec T=\dfrac{-3\sin t\,\vec i+3\cos t\,\vec j+2t\,\vec k}{\sqrt{9+4t^2}}$.

**Limit ve süreklilik:**

- $\displaystyle\lim_{t\to t_0}\vec r(t)$, her bileşenin limiti alınarak bulunur. Bir bileşenin limiti yoksa vektörün limiti de yoktur.
- $\vec r$, bileşenlerinin hepsi sürekliyse süreklidir.
- Derste $t\to\pi/4$ için bir örnek yapıldı. Bileşenler tek tek hesaplandı.

**Örnek 8:** Bir cismin $t=1$ anındaki sürat ve ivmesi istendi. Konum vektörünün türevi alınıp $t=1$ konuldu, ivme için tekrar türev alındı. Süratin hesabında $\sin^2+\cos^2=1$ kullanıldı. Derste sonuç 5 bulundu.

**Türev kuralları:**

- $(\vec u+\vec v)'=\vec u'+\vec v'$, $(\lambda\vec u)'=\lambda\vec u'$.
- $(\vec u\cdot\vec v)'=\vec u'\cdot\vec v+\vec u\cdot\vec v'$.
- $(\vec u\times\vec v)'=\vec u'\times\vec v+\vec u\times\vec v'$.

**Yay uzunluğu:** $L=\displaystyle\int_a^b\sqrt{\left(\frac{dx}{dt}\right)^2+\left(\frac{dy}{dt}\right)^2+\left(\frac{dz}{dt}\right)^2}\,dt$. Derste $0\le t\le\pi$ aralığında bir örnek çözüldü. Fonksiyon ve sonuç altyazıda tam anlaşılmıyor.

### Çıkmış sınav soruları

**Soru 1:** $A$ noktasından geçen ve $x=1+2t$, $y=2-3t$, $z=3-t$ doğrusunu içeren düzlem.

- Doğrudan iki nokta alınır: $t=0$ için $B(1,2,3)$, $t=1$ için $C(3,-1,2)$.
- Normal $\overrightarrow{AB}\times\overrightarrow{AC}$ ile bulunur, düzlem yazılır.
- Daha kısa yol: normal $\overrightarrow{AB}\times\vec v$, burada $\vec v=\langle2,-3,-1\rangle$.

**Soru 2:** $A(1,0,-1)$ ve $B(2,1,0)$ noktalarından geçen ve $3x-y=4$, $x+y+z=5$ düzlemlerinin ara kesit doğrusuna paralel düzlem.

- $\vec n_1=\langle3,-1,0\rangle$, $\vec n_2=\langle1,1,1\rangle$.
- Ara kesit doğrusunun yönü: $\vec v=\vec n_1\times\vec n_2=\langle-1,-3,4\rangle$.
- $\overrightarrow{AB}=\langle1,1,1\rangle$.
- Düzlemin normali: $\vec v\times\overrightarrow{AB}=\langle-7,5,2\rangle$.
- Düzlem: $-7(x-1)+5y+2(z+1)=0$, yani $7x-5y-2z-9=0$. $B$ noktası denklemi sağlar.
- Derste normal $\vec v\times\overrightarrow{AB}$ olarak kuruldu, son denklem sesli okunmadı. Sonucu biz hesapladık.

**Soru 3:** $P(-1,0,1)$ noktasından geçen ve normali $\langle2,-1,7\rangle$ olan düzleme dik doğrunun parametrik denklemi.

- Doğrunun yön vektörü düzlemin normalidir.
- $x=-1+2t$, $y=-t$, $z=1+7t$.
- Hoca önce $x-1$ yazdı. Bir öğrenci $x+1$ olması gerektiğini söyledi, hoca onayladı.

### Çok değişkenli fonksiyonlara giriş

- $y=f(x)$ tek değişkenlidir: $x$ bağımsız, $y$ bağımlı değişkendir.
- $z=f(x,y)$ iki değişkenlidir. Tanım kümesi $D\subseteq\mathbb R^2$, değerleri $\mathbb R$'dedir.
- Genel olarak $w=f(x_1,x_2,\ldots,x_n)$, $n$ değişkenli fonksiyondur.
- Doğadaki olaylar çok değişkenlidir. Örnek: hazır betonda çimento, kireç ve su miktarı birer değişkendir.

**Örnek 9:** $z=\dfrac{1}{\sqrt{1-x^2-y^2}}$.

- Kök paydada olduğu için içi sıfırdan büyük olmalı: $1-x^2-y^2>0$.
- Tanım kümesi: $x^2+y^2<1$, yani merkezi orijin, yarıçapı 1 olan açık daire.
- Değer kümesi: $0<1-x^2-y^2\le1$ olduğundan $z\ge1$. Yani $[1,\infty)$.

**Örnek 10:** $z=\sqrt{x^2+y^2-1}+\ln(4-x^2-y^2)$.

- Kök için $x^2+y^2\ge1$, logaritma için $x^2+y^2<4$.
- Tanım kümesi: $1\le x^2+y^2<4$. İç çember dahil, dış çember dahil değil (kesikli çizilir).

**Örnek 11:** Kök içinde iki çarpanın çarpımı.

- Çarpımın sıfırdan büyük olması için iki çarpan da pozitif ya da ikisi de negatif olmalı.
- Derste bir durumda $y<3x$ (doğrunun altı), diğerinde $y>-3x$ (doğrunun üstü) koşulları çıktı. Tanım bölgesi bu bölgelerin uygun kesişimidir.

**Örnek 12:** Logaritma ve $y-x$ içeren bir fonksiyonun tanım bölgesi.

- Logaritmanın negatif olduğu sayılar $0$ ile $1$ arasındaki sayılardır. Bu bilgiyle $x>0$ ve $x<0$ durumları ayrı incelendi.
- $x>0$ iken $y>x+1$, $x<0$ iken $x<y<x+1$ bölgeleri çıktı. Sınırlar dahil değildir.
- Hoca slayttaki grafikte bir hata olduğunu söyleyip grafiği yeniden çizdi.
- Fonksiyonun tam ifadesi altyazıda anlaşılmıyor.

### Temel yüzeyler

- **Küre:** $x^2+y^2+z^2=R^2$, merkezi orijin. Genel hali $(x-a)^2+(y-b)^2+(z-c)^2=R^2$. $z$ terimi olmasaydı düzlemde çember olurdu.
- **Elipsoid:** eksenleri $a$, $b$, $c$'de keser. Basık bir küre gibidir.
- **Paraboloid:** $z=x^2+y^2$. $y=0$ alınınca $z=x^2$, $x=0$ alınınca $z=y^2$ parabolleri çıkar. Birleşince yukarı açık bir tas olur.
- **Aşağı açık paraboloid:** $z=a-x^2-y^2$. Tepe noktası $z=a$'dadır, kollar aşağı iner.
- **Silindir:** $x^2+y^2=R^2$, $z$ ekseni boyunca uzanır.

### Ders sonrası notlar

- **Örnek 1'deki boy:** Hoca $|\overrightarrow{PQ}|$'yu önce "$\sqrt5$" diye yazdı ve iç çarpımı $-9$ aldı. Doğrusu $|\overrightarrow{PQ}|=\sqrt{4+4+1}=3$ ve $\overrightarrow{PQ}\cdot\overrightarrow{QR}=-11$. Hoca slaytta da bu doğru değerleri gösterdi: $\cos\theta=\dfrac{-11}{3\sqrt{38}}$.
- **Soru 1'deki $C$ noktası:** Altyazıda $t=1$ için nokta "$(3,2,1)$" diye geçiyor. Doğrusu $x=1+2=3$, $y=2-3=-1$, $z=3-1=2$, yani $C(3,-1,2)$.
- **Örnek 9'un değer kümesi:** Hoca "pozitif sayılar" dedi. Doğrusu $[1,\infty)$'dur, çünkü paydadaki kök en fazla 1 olabilir.
- **Sesin kesilmesi:** Yaklaşık 02:03 ile 02:05 arasında hocanın mikrofonu kapalı kaldı. Bu aralıkta anlatılanlar altyazıda yok. Hoca sonra temel yüzeyleri kısaca tekrar anlattı.
- Bazı örneklerin (Örnek 5'in $z$ bileşeni, Örnek 6'nın ikinci düzlemi, Örnek 8) tam verileri yalnız slaytta gösterildi, altyazıda net değil.

---

İsterseniz bu özeti Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
