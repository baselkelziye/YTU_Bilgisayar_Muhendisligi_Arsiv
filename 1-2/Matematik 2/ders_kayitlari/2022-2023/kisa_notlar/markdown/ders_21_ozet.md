# Ders 21 Çalışma Özeti

## Genel Konular

- Bu ders 8 Mayıs 2023 Pazartesi günü yapıldı.
- İki katlı integrallerin tekrarı yapıldı: alan ve hacim yorumu.
- İntegrasyon sırasını değiştirme (change of order of integration) örneklerle pekiştirildi.
- Yeni konu: Jacobian ile değişken dönüşümü (change of variables).
- Kutupsal koordinatlara geçiş (polar coordinates) ve Jacobian'ın $r$ olduğu gösterildi.
- Hiperbol ve parabollerle sınırlı bölgelerde $u,v$ dönüşümü yapıldı.
- Kaynak olarak büyük olasılıkla Prof. Dr. Mustafa Balcı'nın "Genel Matematik 2 Problemleri" kitabının çok katlı integraller bölümü kullanıldı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Finalde çok katlı integrallerden şu tip sorular beklenir:
  - Bir soru kutupsal koordinatlardan.
  - Bir soru bölge dönüşümünden (Jacobian).
  - Bir soru integrasyon sırasını değiştirmeden.
  - Bir soru uzunluk ve kütle gibi uygulamalardan.
- Dönüşümde en önemli şey Jacobian'dır. Unutulursa sonuç yanlış çıkar. Hoca bunu "tılsım" diye niteledi.
- Kutupsal koordinatlarda Jacobian her zaman $r$'dir. Test sınavında yeniden hesaplamaya gerek yoktur.
- $x,y$'yi $u,v$ cinsinden yazmak zorsa, ters Jacobian kullanılır: $\dfrac{\partial(x,y)}{\partial(u,v)}=\dfrac{1}{\partial(u,v)/\partial(x,y)}$.
- İntegrasyon sırası değiştirilirken bölge mutlaka çizilmelidir. Bazen bölge iki parçaya bölünmek zorundadır.
- İntegral alınamıyorsa yöntem değiştirilir. Hoca bunu "uçaktan atlayınca paraşüte ihtiyaç duymak" diye anlattı.
- Test sınavında işlem hatası toleransı yoktur. "Doğru yaptım, yanlış sonuç buldum" işe yaramaz.
- Tek katlı integral bilgisi eksik olan tekrar etmelidir. Çok katlı integral sonunda tek katlıya indirgenir.

## Kısa Tekrar Notları

- $\iint_D 1\,dA$ alanı, $\iint_D f\,dA$ ($f\ne1$, $f\ge0$) hacmi verir.
- **Değişken dönüşümü:** $x=x(u,v)$, $y=y(u,v)$ ise

$$\iint_D f(x,y)\,dx\,dy=\iint_{D'} f\big(x(u,v),y(u,v)\big)\,\left|J\right|\,du\,dv,\qquad J=\frac{\partial(x,y)}{\partial(u,v)}=\begin{vmatrix}x_u & x_v\\ y_u & y_v\end{vmatrix}$$

- **Ters Jacobian:** $\dfrac{\partial(x,y)}{\partial(u,v)}=\dfrac{1}{\begin{vmatrix}u_x & u_y\\ v_x & v_y\end{vmatrix}}$.
- **Kutupsal:** $x=r\cos\theta$, $y=r\sin\theta$, $J=r$, $dx\,dy=r\,dr\,d\theta$, $x^2+y^2=r^2$.
- **Sıra değiştirme:** bölgeyi çiz, kesim noktalarını bul, dış değişkene sabit sınır ver, gerekirse bölgeyi parçala.

## Detaylı Açıklamalar

### Tekrar: Tek Katlı ve Çift Katlı İntegralle Alan

$y=f(x)$ eğrisinin altında, $a\le x\le b$ aralığındaki alan:
$$A=\int_a^b f(x)\,dx=\int_a^b\!\int_0^{f(x)} dy\,dx$$
İki yazım aynı alanı verir.

**Örnek 1:** $1\le x\le2$, $0\le y\le e^x$ bölgesinin alanı.
- İçte: $\int_0^{e^x}dy=e^x$.
- Dışta: $\int_1^2 e^x\,dx=e^2-e$.
- Hocanın tahtadaki hesabı farklı çıktı. "Ders sonrası notlar" kısmına bakın.

### İntegrasyon Sırasını Değiştirme

Yöntem üç adımdır:
1. İntegrasyon bölgesini çiz.
2. İntegrasyon sırasını değiştir.
3. İntegrali hesapla.

**Örnek 2 (büyük olasılıkla (ekrandan)):** $\displaystyle\int_1^2\!\int_0^x e^{y^2}\,dy\,dx$.
- $e^{y^2}$'nin $y$'ye göre ilkeli elementer değildir. Doğrudan alınamaz.
- Hoca bölgeyi $y=0$, $y=x$, $x=2$ ile çizdi. Sırayı değiştirip $\int_0^2 y\,e^{y^2}\,dy$'ye ulaştı ve $u=y^2$ dönüşümünü önerdi.
- Bu hesap tam olarak yazılan sınırlarla tutarlı değil. Ayrıntı "Ders sonrası notlar"dadır.

**Örnek 3 (Balcı, Problem 6a):** $\displaystyle\int_0^\pi\!\int_x^\pi \frac{\sin y}{y}\,dy\,dx$.
- $\dfrac{\sin y}{y}$'nin ilkeli elementer değildir.
- Bölge: $0\le x\le\pi$, $x\le y\le\pi$. Yani $y=x$ doğrusunun üstü, $y=\pi$'nin altı.
- Sıra değişince: $0\le y\le\pi$, $0\le x\le y$.
$$\int_0^\pi\!\int_0^y \frac{\sin y}{y}\,dx\,dy=\int_0^\pi \sin y\,dy=-\cos y\Big|_0^\pi=2$$

**Balcı Problem 6'daki diğer şıklar:** Hoca bunları sıra değiştirme gerektiren örnekler olarak gösterdi. Örneğin büyük olasılıkla (ekrandan) $\int_0^1\int_y^1 x^2e^{xy}\,dx\,dy$ ve $\int_0^2\int_{y/2}^1 e^{x^2}\,dx\,dy$.
- $\int_0^2\!\int_{y/2}^1 e^{x^2}\,dx\,dy=\int_0^1\!\int_0^{2x} e^{x^2}\,dy\,dx=\int_0^1 2x\,e^{x^2}\,dx=e-1$.

**Örnek 4 (bölgeyi parçalama):** $\displaystyle\int_0^1\!\int_x^{2x} f\,dy\,dx$.
- Bölge: $0\le x\le1$, $y=x$ ile $y=2x$ arası.
- Sıra değişince bölge iki parçaya ayrılır:
  - $0\le y\le1$: $x$, $y/2$'den $y$'ye.
  - $1\le y\le2$: $x$, $y/2$'den $1$'e.
$$\int_0^1\!\int_{y/2}^{y} f\,dx\,dy+\int_1^2\!\int_{y/2}^{1} f\,dx\,dy$$
- Hoca bu bölünmenin zorunlu olduğunu vurguladı: tek integralle yazılamaz.

**Örnek 5:** $\displaystyle\int_0^1\!\int_{\sqrt y}^1 f\,dx\,dy$.
- $x=\sqrt y$ eğrisi $y=x^2$ parabolüdür. $x,y\ge0$.
- Bölge: $y=x^2$ parabolünün altı, $0\le x\le1$.
- Sıra değişince: $\displaystyle\int_0^1\!\int_0^{x^2} f\,dy\,dx$.

**Örnek 6:** $\displaystyle\int_2^3\!\int_x^{2x} dy\,dx$.
- İçte: $2x-x=x$. Dışta: $\int_2^3 x\,dx=\dfrac{9-4}{2}=\dfrac52$.
- Bölge $y=x$ ile $y=2x$ arası, $2\le x\le3$. Sıra değişince bu bölge de parçalanır.

### Jacobian ile Değişken Dönüşümü

- Bazı integraller ne doğrudan ne de sıra değiştirerek alınabilir. Bu durumda bölge dönüşümü yapılır.
- $x,y$ değişkenleri $u,v$'ye çevrilir. $D$ bölgesi $D'$ bölgesine dönüşür.
- Dönüşümden gelen çarpan Jacobian'dır: $J=\dfrac{\partial(x,y)}{\partial(u,v)}$ determinantı.

**Kutupsal koordinatlarda Jacobian:**
$$J=\begin{vmatrix}\cos\theta & -r\sin\theta\\ \sin\theta & r\cos\theta\end{vmatrix}=r\cos^2\theta+r\sin^2\theta=r$$

**Örnek 7 (Balcı, Problem 8):** $\displaystyle\iint_B (x^2+y^2)^{1/4}\,dx\,dy$, $B$: $x^2+y^2=1$ ile $x^2+y^2=16$ çemberleri arasındaki halka.
- $1\le r\le4$, $0\le\theta\le2\pi$.
$$\int_0^{2\pi}\!\int_1^4 (r^2)^{1/4}\,r\,dr\,d\theta=\int_0^{2\pi}\!\int_1^4 r^{3/2}\,dr\,d\theta=\frac25\left(32-1\right)2\pi=\frac{124\pi}{5}$$
- Kitapta $x=r\cos\varphi$ yanlış yazılmış gibi duruyordu. Hoca $x=r\cos\theta$, $y=r\sin\theta$ diye düzeltti.

**Örnek 8 (büyük olasılıkla (ekrandan)):** $\displaystyle\iint_D\sqrt{x^2+y^2}\,dA$, $D$: birim disk.
- $\sqrt{x^2+y^2}=r$. Jacobian $r$ eklenince integrand $r^2$ olur.
$$\int_0^{2\pi}\!\int_0^1 r^2\,dr\,d\theta=\frac13\cdot2\pi=\frac{2\pi}{3}$$
- İntegrand 1'den farklı olduğu için sonuç bir hacimdir.

**Örnek 9 (Balcı, Problem 10):** $B$ birinci bölgede, $x^2-y^2=1$, $x^2-y^2=9$, $xy=2$, $xy=4$ hiperbolleriyle sınırlı. $\displaystyle I=\iint_B(x^2+y^2)\,dA$.
- Dönüşüm: $u=x^2-y^2$ ($1\le u\le9$), $v=xy$ ($2\le v\le4$).
- $\dfrac{\partial(u,v)}{\partial(x,y)}=\begin{vmatrix}2x & -2y\\ y & x\end{vmatrix}=2(x^2+y^2)$.
- $dA=\dfrac{du\,dv}{2(x^2+y^2)}$. İntegranddaki $x^2+y^2$ sadeleşir.
$$I=\int_2^4\!\int_1^9 \frac12\,du\,dv=\frac12\cdot8\cdot2=8$$
- Hoca bu sorunun "çok enteresan" olduğunu söyledi: fonksiyon Jacobian'la kendiliğinden sadeleşiyor.

**Örnek 10 (Balcı, Problem 11):** $B$; $y=x^2$, $4y=x^2$, $2x=y^2$, $3x=y^2$ parabolleriyle sınırlı. $\displaystyle\iint_B dx\,dy$.
- Dönüşüm: $u=\dfrac{x^2}{y}$ ($1\le u\le4$), $v=\dfrac{y^2}{x}$ ($2\le v\le3$).
- $\dfrac{\partial(u,v)}{\partial(x,y)}=\begin{vmatrix}\dfrac{2x}{y} & -\dfrac{x^2}{y^2}\\[4pt] -\dfrac{y^2}{x^2} & \dfrac{2y}{x}\end{vmatrix}=4-1=3$.
- $dx\,dy=\dfrac13\,du\,dv$.
$$\iint_B dx\,dy=\int_2^3\!\int_1^4\frac13\,du\,dv=\frac13\cdot3\cdot1=1$$
- Hoca derste $u,v$ sınırlarını ve Jacobian'ı kurdu, sayısal sonucu söylemedi.

**Örnek 11 (Balcı, Problem 13):** $B=\{1\le x\le2,\;0\le y\le x\}$. $\displaystyle\iint_B\frac{y\sqrt{x^2+y^2}}{x}\,dx\,dy$ integralini kutupsal koordinatlarla hesaplayın.
- $x=r\cos\theta$, $y=r\sin\theta$ yazılınca kök kalkar: $\sqrt{x^2+y^2}=r$.
- $\dfrac{y}{x}=\tan\theta$. Jacobian $r$ ile integrand $r^2\tan\theta$ olur.
- Hoca bölgeyi çizdi ama sınırları bitirmedi. Doğru sınırlar ve sonuç "Ders sonrası notlar" kısmındadır.

### Ders sonrası notlar

- **Örnek 1:** Hoca içteki integralin sınırını koyarken $e^x-e^0=e^x-1$ yazdı. Alt sınır $y=0$ olduğu için doğrusu $e^x-0=e^x$. Alan $e^2-e$ olur. Hocanın hesabı $(e^2-2)-(e-1)=e^2-e-1$ verir; bu yanlıştır.
- **Örnek 2:** Yazılan $\int_1^2\int_0^x e^{y^2}\,dy\,dx$ bölgesinde sıra değişince iki parça çıkar: $\int_0^1\int_1^2 e^{y^2}\,dx\,dy+\int_1^2\int_y^2 e^{y^2}\,dx\,dy$. İkisi de elementer değildir. Hocanın ulaştığı $\int_0^2 y\,e^{y^2}\,dy$ ifadesi, $\int_0^2\int_x^2 e^{y^2}\,dy\,dx$ integralinin sıra değiştirilmiş hâlidir:
  - $\displaystyle\int_0^2\!\int_x^2 e^{y^2}\,dy\,dx=\int_0^2\!\int_0^y e^{y^2}\,dx\,dy=\int_0^2 y\,e^{y^2}\,dy=\frac{e^4-1}{2}$.
- **Örnek 6:** Hoca $\left[\dfrac{x^2}{2}\right]_2^3$ hesabını "9 bölü 3 eksi 4 bölü 3" diye söyledi. Doğrusu $\dfrac92-\dfrac42=\dfrac52$.
- **Örnek 11'in çözümü:** Hoca "$\theta$ sıfırdan $2\pi$'ye" dedi. Bölge bir disk değil, $y=0$, $y=x$, $x=1$, $x=2$ ile sınırlı bir yamuktur.
  - $0\le\theta\le\pi/4$. $x=1$ doğrusu $r=\sec\theta$, $x=2$ doğrusu $r=2\sec\theta$ olur.
  - $\displaystyle\int_0^{\pi/4}\!\int_{\sec\theta}^{2\sec\theta} r^2\tan\theta\,dr\,d\theta=\frac73\int_0^{\pi/4}\sec^3\theta\tan\theta\,d\theta=\frac73\left[\frac{\sec^3\theta}{3}\right]_0^{\pi/4}=\frac79\left(2\sqrt2-1\right)$.
- **$u=xy$, $v=x^2-y^2$ tahta örneği:** Hoca alanı bu dönüşümle hesaplarken ($2\le u\le4$, $1\le v\le3$) Jacobian'ı önce $-2(x^2+y^2)$ buldu, sonra "$-v^2$" diye yazdı. Bu yanlış. Doğrusu $|J|=\dfrac{1}{2(x^2+y^2)}$. Yalnız alan istenirse $x^2+y^2=\sqrt{v^2+4u^2}$ olur ve integral elementer değildir. Bu dönüşüm, Örnek 9'daki gibi integrandda $x^2+y^2$ olduğunda işe yarar.
- Altyazıda "Trabzon" diye geçen kelime değişken adıdır ($u$ dönüşümü). Bazı yerlerde $\theta$ "teta", $\varphi$ "fi" diye geçiyor.
- Ders "yarın görüşmek üzere" diye bitti. Sonraki ders 9 Mayıs Salı.

İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
