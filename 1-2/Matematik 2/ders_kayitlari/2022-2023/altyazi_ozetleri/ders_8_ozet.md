# Ders 8 Çalışma Özeti

**Tarih:** 21 Mart 2023 (Salı)

## Genel Konular

- Parametrik eğrilerde türev ve alan.
- Kartezyen, parametrik ve kutupsal koordinatlarda yay uzunluğu (tekrar).
- Vektörler: bileşenler, skaler çarpım (dot product), vektörel çarpım (cross product), karma çarpım (triple product).
- İki vektör arasındaki açı.
- Uzayda düzlem denklemi, düzlemin normal vektörü.
- Noktanın doğruya ve düzleme uzaklığı.
- İki düzlemin ara kesitinden geçen düzlem.
- Uzayda doğrunun parametrik ve simetrik denklemleri.
- Çıkmış sınav sorusu: iki düzlem, ara kesit doğrusu, dik düzlem, düzlemler arası açı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Skaler çarpımda açının **kosinüsü**, vektörel çarpımda açının **sinüsü** vardır. Bunlar karıştırılmamalı.
- Basit sorularda işlem hatası yapmayın. Test sınavında işlem hatası soruyu doğrudan yanlış yapar. Bol alıştırma yapın.
- Bu hafta parametrik denklemler, kutupsal koordinatlar ve vektörler bitti. Gelecek hafta çok değişkenli fonksiyonlara geçilecek.
- Soruları biriktirmeyin. Konuları parça parça, haftası haftasına bitirin.
- Anlamadığınız yerde hemen mikrofonu açıp sorun. Soru sormaktan çekinmek büyük bir eksikliktir.
- Ders notları üniversitenin sistemine (AVES) yüklenecek.

## Kısa Tekrar Notları

- **Parametrik türev:** $\dfrac{dy}{dx}=\dfrac{dy/dt}{dx/dt}$.
- **Parametrik alan:** $A=\displaystyle\int_{t_1}^{t_2}y(t)\,x'(t)\,dt$.
- **Yay uzunluğu (kutupsal):** $L=\displaystyle\int_{\theta_1}^{\theta_2}\sqrt{r^2+r'^2}\,d\theta$.
- **Skaler çarpım:** $\vec a\cdot\vec b=a_1b_1+a_2b_2+a_3b_3=|\vec a|\,|\vec b|\cos\theta$. Sonuç bir sayıdır.
  - $\vec a\perp\vec b\iff\vec a\cdot\vec b=0$.
  - Aynı yönde paralel ise $\vec a\cdot\vec b=|\vec a|\,|\vec b|$.
- **Vektörel çarpım:** $|\vec a\times\vec b|=|\vec a|\,|\vec b|\sin\theta$. Sonuç bir vektördür, iki vektörün düzlemine diktir.
  - $\vec a\times\vec b=-(\vec b\times\vec a)$.
  - $\vec a\parallel\vec b\iff\vec a\times\vec b=\vec 0$.
  - $|\vec a\times\vec b|$, iki vektörün oluşturduğu paralelkenarın alanıdır.
- **Karma çarpım:** $\vec a\cdot(\vec b\times\vec c)$ = üç vektörün belirlediği paralelyüzün hacmi. Dört nokta aynı düzlemdeyse bu çarpım 0'dır.
- **Düzlem:** normali $\vec n=\langle a,b,c\rangle$, geçtiği nokta $P_0(x_0,y_0,z_0)$ ise $a(x-x_0)+b(y-y_0)+c(z-z_0)=0$.
- **Uzaklık:**
  - Noktanın doğruya (düzlemde): $d=\dfrac{|ax_0+by_0+c|}{\sqrt{a^2+b^2}}$.
  - Noktanın düzleme: $d=\dfrac{|ax_0+by_0+cz_0+d|}{\sqrt{a^2+b^2+c^2}}$.
- **Doğru:** yön vektörü $\vec v=\langle a,b,c\rangle$, geçtiği nokta $P_0$ ise
  - Parametrik: $x=x_0+at$, $y=y_0+bt$, $z=z_0+ct$.
  - Simetrik: $\dfrac{x-x_0}{a}=\dfrac{y-y_0}{b}=\dfrac{z-z_0}{c}$.

## Detaylı Açıklamalar

### Parametrik eğriler ve kutupsal koordinatlar (tekrar)

- $x=x(t)$, $y=y(t)$ ise türev zincir kuralıyla bulunur: $\dfrac{dy}{dx}=\dfrac{dy/dt}{dx/dt}$.
- Kartezyen bir denklem kutupsala çevrilirken $x$ yerine $r\cos\theta$, $y$ yerine $r\sin\theta$ yazılır. Sınavda "Kartezyen denklemi hangisidir?" biçiminde tersi de sorulabilir.

**Yay uzunluğu formülleri:**

| Gösterim | Formül |
|---|---|
| Kartezyen | $L=\displaystyle\int_{x_1}^{x_2}\sqrt{1+(y')^2}\,dx$ |
| Parametrik | $L=\displaystyle\int_{t_1}^{t_2}\sqrt{(x')^2+(y')^2}\,dt$ |
| Kutupsal | $L=\displaystyle\int_{\theta_1}^{\theta_2}\sqrt{r^2+(r')^2}\,d\theta$ |

**Örnek 1:** $r=1-\cos\theta$ kardiyoidinin çevresi.

- Eğri kutup eksenine göre simetrik. Üst yarı $0$ ile $\pi$ arasında hesaplanıp 2 ile çarpılır.
- $r'=\sin\theta$. $r^2+r'^2=2-2\cos\theta=4\sin^2\dfrac{\theta}{2}$.
- $L=2\displaystyle\int_0^{\pi}2\sin\frac{\theta}{2}\,d\theta=8$.

**Örnek 2 (kısa çizim):** $r=1-\cos 2\theta$ gibi açının katsayısı değişirse çizimde $\pi/4$, $\pi/2$ gibi farklı açılar alınır. $\theta=0$'da $r=0$, $\theta=\pi/4$'te $r=1$, $\theta=\pi/2$'de $r=2$.

### Parametrik eğride alan

- Kartezyende $A=\displaystyle\int_a^b y\,dx$ idi. İki eğri arasında $A=\displaystyle\int(y_2-y_1)\,dx$.
- $x=x(t)$, $y=y(t)$ ise $dx=x'(t)\,dt$ olur. Yerine yazılır:

$$A=\int_{t_1}^{t_2}y(t)\,x'(t)\,dt.$$

- Kutupsal ortak alan örneği (dünkü ders): $r=4\sin\theta$ ve $r=4\cos\theta$ eşitlenir, kesişme açısı $\theta=\pi/4$ bulunur. İki parçanın alanı toplanır.

### Vektörler

- İki boyutta $\vec a=a_1\vec i+a_2\vec j$, üç boyutta $\vec a=a_1\vec i+a_2\vec j+a_3\vec k=\langle a_1,a_2,a_3\rangle$.
- Boy (norm): $|\vec a|=\sqrt{a_1^2+a_2^2+a_3^2}$.

**Skaler çarpımın özellikleri:**

- $\vec a\cdot\vec b=\vec b\cdot\vec a$ (değişme).
- $\vec a\cdot(\vec b+\vec c)=\vec a\cdot\vec b+\vec a\cdot\vec c$ (dağılma).
- $(k\vec a)\cdot\vec b=k(\vec a\cdot\vec b)$.
- $\vec a\perp\vec b$ ise $\cos 90°=0$ olduğu için $\vec a\cdot\vec b=0$.

**Örnek 3:** $\vec a=2\vec i+3\vec j+4\vec k$, $\vec b=-\vec i-4\vec j+\vec k$.

- $\vec a\cdot\vec b=2(-1)+3(-4)+4(1)=-2-12+4=-10$.
- Hoca önce $2\cdot(-1)$'i $+2$ alıp $-6$ buldu, sonra $-10$ diye düzeltti.

**Örnek 4:** $\vec a=3\vec i-4\vec j$, $\vec b=8\vec i-6\vec j$.

- $\vec a\cdot\vec b=24+24=48$.
- $|\vec a|=\sqrt{9+16}=5$, $|\vec b|=\sqrt{64+36}=10$.
- $\cos\theta=\dfrac{48}{50}=\dfrac{24}{25}$, yani $\theta=\arccos\dfrac{24}{25}$.

**Vektörel çarpım:**

$$\vec a\times\vec b=\begin{vmatrix}\vec i&\vec j&\vec k\\a_1&a_2&a_3\\b_1&b_2&b_3\end{vmatrix}.$$

- Sonuç vektör, $\vec a$ ve $\vec b$'nin bulunduğu düzleme diktir. Bu vektöre düzlemin **normali** denir.
- $\vec a\times(\vec b+\vec c)=\vec a\times\vec b+\vec a\times\vec c$.
- Bir üçgende $\overrightarrow{AB}\times\overrightarrow{AC}$, üçgenin düzlemine dik bir vektör verir. Boyunun yarısı üçgenin alanıdır.

**Örnek 5 (üçgende açı):** $A$, $B$, $C$ noktaları verilince $\overrightarrow{AB}$ ve $\overrightarrow{AC}$ bulunur. $A$ açısı için:

$$\cos A=\frac{\overrightarrow{AB}\cdot\overrightarrow{AC}}{|\overrightarrow{AB}|\,|\overrightarrow{AC}|}.$$

- Derste $|\overrightarrow{AB}|=\sqrt{1+4+36}=\sqrt{41}$ ve $|\overrightarrow{AC}|=\sqrt{9+9+9}=\sqrt{27}$ bulundu.
- Vektörlerin bileşenleri ve iç çarpımın sonucu altyazıda tam anlaşılmıyor.

**Karma çarpım ve aynı düzlemdeki noktalar (çıkmış soru tipi):**

- $A$, $B$, $C$, $D$ noktaları aynı düzlemdeyse $\overrightarrow{AB}$, $\overrightarrow{AC}$, $\overrightarrow{AD}$ vektörlerinin belirlediği paralelyüzün hacmi 0'dır.

$$\begin{vmatrix}AB_1&AB_2&AB_3\\AC_1&AC_2&AC_3\\AD_1&AD_2&AD_3\end{vmatrix}=0.$$

- Derste $\overrightarrow{AB}=\langle-1,-2,6\rangle$ ve $\overrightarrow{AD}=\langle m-1,5,7\rangle$ verildi. Determinant sıfıra eşitlenip $m$ bulundu. $\overrightarrow{AC}$'nin bileşenleri ve $m$'nin değeri altyazıda net değil.

### Uzayda düzlem

**Düzlem denkleminin çıkarılışı:**

- Düzlemde sabit bir nokta $P_0(x_0,y_0,z_0)$ ve değişken bir nokta $P(x,y,z)$ alınır.
- $\overrightarrow{P_0P}=(x-x_0)\vec i+(y-y_0)\vec j+(z-z_0)\vec k$ düzlemin içindedir.
- Düzlemin normali $\vec n=\langle a,b,c\rangle$ düzleme diktir. O halde $\vec n\cdot\overrightarrow{P_0P}=0$:

$$a(x-x_0)+b(y-y_0)+c(z-z_0)=0.$$

- Açılırsa $ax+by+cz+d=0$ biçimini alır. Normal, $x$, $y$, $z$'nin katsayılarından okunur.

**Örnek 6:** $P_0$ noktasından geçen ve $\vec v=3\vec i-2\vec j+4\vec k$ vektörüne dik düzlem.

- $\vec v$ düzlemin normalidir. $\vec v\cdot\overrightarrow{P_0P}=0$ yazılır.
- Derste $3(x-1)-2(y+1)+4(z\mp3)=0$ biçiminde kuruldu. $P_0$'ın $z$ bileşeninin işareti altyazıda tutarsız geçiyor ("$z-3$" ve "$z+3$").

**Örnek 7:** Üç noktadan geçen düzlem. $\overrightarrow{AB}\times\overrightarrow{AC}$ normal vektörü verir. Bu normal ve $A$ noktasıyla düzlem denklemi yazılır.

### Uzaklıklar ve düzlem demeti

- Düzlemde $(x_0,y_0)$ noktasının $ax+by+c=0$ doğrusuna uzaklığı: $d=\dfrac{|ax_0+by_0+c|}{\sqrt{a^2+b^2}}$.
- Uzayda $(x_0,y_0,z_0)$ noktasının $ax+by+cz+d=0$ düzlemine uzaklığı: $d=\dfrac{|ax_0+by_0+cz_0+d|}{\sqrt{a^2+b^2+c^2}}$.
- $P_1=0$ ve $P_2=0$ düzlemlerinin ara kesitinden geçen her düzlem $P_1+\lambda P_2=0$ biçimindedir. Verilen noktayı sağlayan $\lambda$ bulunur.

### Uzayda doğru

- $P_0(x_0,y_0,z_0)$'dan geçen ve $\vec v=\langle a,b,c\rangle$'ye paralel doğru üzerinde $P(x,y,z)$ alınır.
- $\overrightarrow{P_0P}\parallel\vec v$ olduğundan bileşenler orantılıdır: $\dfrac{x-x_0}{a}=\dfrac{y-y_0}{b}=\dfrac{z-z_0}{c}=t$ (simetrik denklem).
- Her biri $t$'ye eşitlenip çekilirse parametrik denklem çıkar: $x=x_0+at$, $y=y_0+bt$, $z=z_0+ct$.

### Çıkmış soru: iki düzlem

$D_1:\ 3x-y+z-1=0$ ve normali $\vec n_2=\langle1,2,-4\rangle$ olan $D_2$ düzlemi verilmiş.

**a) İki düzlemi de dik kesen ve $P$ noktasından geçen düzlem:**

- $\vec n_1=\langle3,-1,1\rangle$, $\vec n_2=\langle1,2,-4\rangle$.
- İstenen düzlemin normali iki normale de diktir:

$$\vec n_1\times\vec n_2=\begin{vmatrix}\vec i&\vec j&\vec k\\3&-1&1\\1&2&-4\end{vmatrix}=2\vec i+13\vec j+7\vec k.$$

- Derste $P$ noktası $(1,0,3)$ alınarak düzlem $2(x-1)+13y+7(z-3)=0$ diye yazıldı.

**b) Ara kesit doğrusu:**

- Yön vektörü yine $\vec n_1\times\vec n_2=\langle2,13,7\rangle$'dir.
- İki düzlemi de sağlayan bir nokta bulunur. Simetrik denklem $\dfrac{x-x_0}{2}=\dfrac{y-y_0}{13}=\dfrac{z-z_0}{7}$ olur.

**c) Ara kesitten ve bir noktadan geçen düzlem:** $D_1+\lambda D_2=0$ yazılır, nokta yerine konup $\lambda$ bulunur.

**d) İki düzlem arasındaki açı:** normaller arasındaki açıdır.

- $\vec n_1\cdot\vec n_2=3-2-4=-3$.
- $|\vec n_1|=\sqrt{11}$, $|\vec n_2|=\sqrt{21}$.
- $\cos\theta=\dfrac{|-3|}{\sqrt{11}\sqrt{21}}=\dfrac{3}{\sqrt{231}}$.
- Derste sonuç sayısal olarak söylenmedi. Hoca çözümleri paylaşacağını söyledi.

### Ders sonrası notlar

- **Kosinüs ve sinüs:** Hoca bir yerde vektörel çarpım için "kosinüs", skaler çarpım için "sinüs" dedi, sonra kendisi düzeltti. Doğrusu: $\vec a\cdot\vec b=|\vec a||\vec b|\cos\theta$, $|\vec a\times\vec b|=|\vec a||\vec b|\sin\theta$.
- **Paralel vektörlerde vektörel çarpım:** Hoca "kosinüs sıfır olur" dedi. Doğrusu: $\sin 0=0$ olduğu için $\vec a\times\vec b=\vec 0$ olur.
- **Örnek 4:** $\vec b$ önce "$6\vec i-6\vec j$" diye söylendi, hesapta $8\vec i-6\vec j$ kullanıldı. $|\vec b|=10$ ve $\cos\theta=\dfrac{24}{25}$ ancak $8\vec i-6\vec j$ ile tutar.
- **Çıkmış soru (a):** Hoca düzlem denklemini bir an "$18y$" diye okudu. Doğrusu $13y$'dir.
- **Örnek 5'teki sonuç:** Altyazıda "$5/\sqrt{123}$" geçiyor. Bu sonuç, verilen boylarla ($\sqrt{41}\cdot\sqrt{27}=\sqrt{1107}$) tutarlı değil. Bu kısım altyazıda anlaşılmıyor.
- Yaklaşık 00:19 ile 00:21 arasında hocanın sesi kesildi. O bölümde anlatılanlar (kutupsal alan) altyazıda yok.

---

İsterseniz bu özeti Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
