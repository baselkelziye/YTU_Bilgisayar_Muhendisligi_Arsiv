# Ders 7 Çalışma Özeti

**Tarih:** 20 Mart 2023 (Pazartesi)

## Genel Konular

- Kutupsal koordinatlar (polar coordinates): kutup, kutup ekseni, $(r,\theta)$ gösterimi.
- Bir noktanın sonsuz sayıda kutupsal gösterimi, negatif $r$.
- Kartezyen ve kutupsal koordinatlar arasında dönüşüm.
- Kutupsal denklemlerin grafikleri: çember, doğru, kardiyoid (cardioid), limaçon, gül eğrileri (rose curves).
- Kutupsal eğrilerde simetri ve eğri çizimi.
- Kutupsal koordinatlarda alan hesabı.
- Kutupsal koordinatlarda yay uzunluğu (arc length).
- Çıkmış sınav soruları: iki eğri arasındaki alan, ortak alan.

## Hocanın Özellikle Vurguladığı Kısımlar

- Vizede kutupsal koordinatlardan en az bir soru kesin gelir. İki, üç, hatta dört soru gelme ihtimali de var.
- Vize ağırlıklı olarak serilerden, kutupsal koordinatlardan, vektörlerden ve 7. haftaya kadarki konulardan gelecek.
- Sınavda en çok şunlar soruluyor: "Bu eğrinin grafiği hangisidir?", "Bu eğrinin alanı nedir?", "Şu aralıktaki yay uzunluğu nedir?"
- Alan sorusu çözmeden önce mutlaka eğri çizilmeli.
- Simetri kuralları ezber değildir. Şekli doğru çizebilmek önemlidir.
- Kardiyoidi hızlı çizmek için yalnız birkaç açıda ($0$, $\pi/2$, $\pi$, $3\pi/2$) $r$ değerini bulmak yeter. Test sınavında bu pratiklik çok işe yarar.
- Alan formülünde $r$'nin **karesi** alınır. Kareyi unutmayın.
- Vektörler bir sonraki derste (21 Mart) işlenecek.

## Kısa Tekrar Notları

- **Dönüşüm:** $x=r\cos\theta$, $y=r\sin\theta$, $x^2+y^2=r^2$, $\tan\theta=\dfrac{y}{x}$.
- **Aynı nokta:** $(r,\theta)$, $(r,\theta+2k\pi)$ ve $(-r,\theta+\pi)$ aynı noktayı gösterir. $r=0$ ise $\theta$ ne olursa olsun nokta kutuptur.
- **Temel eğriler:**
  - $r=a$: merkezi kutup, yarıçapı $a$ olan çember.
  - $\theta=\alpha$: kutup ekseniyle $\alpha$ açısı yapan doğru.
  - $r=2a\cos\theta$: merkezi $(a,0)$, yarıçapı $a$ olan çember.
  - $r=2a\sin\theta$: merkezi $(0,a)$, yarıçapı $a$ olan çember.
  - $r=a(1\pm\cos\theta)$, $r=a(1\pm\sin\theta)$: kardiyoid.
  - $r=a\sin n\theta$, $r=a\cos n\theta$: gül eğrisi.
- **Periyot:** $\cos\theta$, $\sin\theta$ için $2\pi$. $\cos 3\theta$ için $\dfrac{2\pi}{3}$. $\tan\theta$ için $\pi$.
- **Alan:** $A=\dfrac12\displaystyle\int_\alpha^\beta r^2\,d\theta$.
- **Yay uzunluğu:**
  - Kutupsal: $L=\displaystyle\int_\alpha^\beta\sqrt{r^2+\left(\dfrac{dr}{d\theta}\right)^2}\,d\theta$.
  - Kartezyen: $L=\displaystyle\int_a^b\sqrt{1+(f'(x))^2}\,dx$.
  - Parametrik: $L=\displaystyle\int_{t_1}^{t_2}\sqrt{\left(\dfrac{dx}{dt}\right)^2+\left(\dfrac{dy}{dt}\right)^2}\,dt$.
- **İki eğri arasında kalan alan:** önce eğriler eşitlenip kesişme açıları bulunur. Sonra dıştaki eğrinin $r^2$'sinden içtekinin $r^2$'si çıkarılır.

## Detaylı Açıklamalar

### Kutupsal koordinat sistemi

- Düzlemde bir nokta $O$ (kutup) ve bu noktadan çıkan bir ışın (kutup ekseni) seçilir.
- Bir $P$ noktası $(r,\theta)$ ile gösterilir.
  - $r$: kutuptan $P$'ye olan yönlü uzaklık.
  - $\theta$: kutup ekseninden $OP$'ye olan yönlü açı.
- Pozitif $\theta$ saatin tersi yönünde, negatif $\theta$ saat yönünde ölçülür.
- $r<0$ ise nokta, $\theta$ ışınının tam ters yönündedir. Yani $(-r,\theta)$ ile $(r,\theta+\pi)$ aynı noktadır.

**Örnekler:**

- $(3,\pi/4)$: $\pi/4$ ışını üzerinde, kutuptan 3 birim uzakta.
- $(2,-\pi/6)$: saat yönünde $30°$ dönülür, 2 birim gidilir.
- $(-3,\pi/3)$: önce $\pi/3$ ışını çizilir, sonra ters yönde 3 birim gidilir. Bu nokta $(3,4\pi/3)$ ile aynıdır.

### Kartezyen ve kutupsal dönüşüm

Dik üçgende $\cos\theta=\dfrac{x}{r}$ ve $\sin\theta=\dfrac{y}{r}$ olduğundan:

$$x=r\cos\theta,\qquad y=r\sin\theta,\qquad x^2+y^2=r^2.$$

**Örnek 1:** $x^2+y^2=a^2$ çemberi. $x$ ve $y$ yerine yazılırsa $r^2=a^2$, yani $r=a$ olur.

**Örnek 2:** $r^2=a^2\cos 2\theta$ eğrisinin Kartezyen denklemi.

- $\cos 2\theta=\cos^2\theta-\sin^2\theta=\dfrac{x^2}{r^2}-\dfrac{y^2}{r^2}$.
- Yerine yazılır: $r^2=a^2\dfrac{x^2-y^2}{r^2}$, yani $r^4=a^2(x^2-y^2)$.
- Sonuç: $(x^2+y^2)^2=a^2(x^2-y^2)$. Bu eğri lemniskattır (lemniscate).

**Örnek 3:** $(x-a)^2+y^2=a^2$ çemberi (merkez $(a,0)$, yarıçap $a$).

- Açılır: $x^2+y^2-2ax=0$.
- Yerine yazılır: $r^2-2ar\cos\theta=0$, yani $r=2a\cos\theta$.
- Hoca: "$r=2a\cos\theta$ grafiği istenirse onu Kartezyene çevirip bu çember olarak çizeriz."

**Örnek 4 (derste soru olarak soruldu):** $r=2\sin\theta$ grafiği hangisidir?

- $r$'yi yalnız bırakmak için iki taraf $r$ ile çarpılır: $r^2=2r\sin\theta$.
- $x^2+y^2=2y$, yani $x^2+(y-1)^2=1$.
- Merkezi $(0,1)$, yarıçapı 1 olan çemberdir. Bir öğrenci doğru şıkkı buldu.

### Eşitsizliklerle verilen bölgeler

- $1\le r\le 2$, $0\le\theta\le\pi/2$: birinci bölgede, yarıçapı 1 ve 2 olan çemberler arasındaki halka parçası.
- $\theta$ yalnız $0$ ile $\pi$ arasında olsaydı üst yarı halka alınırdı.
- $-3\le r\le 2$, $\theta=\pi/4$: $\pi/4$ doğrusu üzerinde bir doğru parçası. Pozitif yönde 2 birime, ters yönde 3 birime uzanır.
- $\dfrac{2\pi}{3}\le\theta\le\dfrac{5\pi}{6}$, $r$ sınırsız: bu iki ışın arasında kalan kama biçimli bölge.
- Bir sınır "dahil değilse" kesik çizgiyle çizilir.

### Simetri

$r=f(\theta)$ eğrisi için:

- $\theta$ yerine $-\theta$ yazınca denklem değişmiyorsa eğri **kutup eksenine** ($x$ ekseni) göre simetriktir.
- $(r,\theta)$ yerine $(-r,-\theta)$ ya da $\theta$ yerine $\pi-\theta$ yazınca denklem değişmiyorsa eğri **$\theta=\pi/2$ doğrusuna** ($y$ ekseni) göre simetriktir.
- Simetri varsa eğrinin yalnız bir yarısı çizilir, diğer yarısı yansıtılır.

### Kutupsal eğri çizimi

**Adımlar:**

- Eğri periyodikse periyot bulunur. Çizim bir periyotta yapılır.
- Simetri incelenip çizim aralığı daraltılır.
- $r'=\dfrac{dr}{d\theta}$ ile $r$'nin artıp azaldığı bakılır.
- Seçilen $\theta$ değerleri için $r$ hesaplanır ve tablo yapılır.
- Eğim gerekirse: $\dfrac{dy}{dx}=\dfrac{r'\sin\theta+r\cos\theta}{r'\cos\theta-r\sin\theta}$.

**Örnek 5:** $r=a(1+\cos\theta)$, $a>0$.

- Periyot $2\pi$. $\theta\to-\theta$ ile denklem değişmez, eğri kutup eksenine göre simetriktir. Yalnız $[0,\pi]$ incelenir.
- $r'=-a\sin\theta\le0$ olduğundan $[0,\pi]$'de $r$ azalır.

| $\theta$ | $0$ | $\pi/2$ | $\pi$ |
|---|---|---|---|
| $r$ | $2a$ | $a$ | $0$ |

- Üst yarı çizilip kutup eksenine göre yansıtılır. Ortaya kalp şekli çıkar: kardiyoid.

**Örnek 6 (pratik çizim):** $r=2(1+\sin\theta)$.

| $\theta$ | $0$ | $\pi/2$ | $\pi$ | $3\pi/2$ |
|---|---|---|---|---|
| $r$ | $2$ | $4$ | $2$ | $0$ |

- Uzun kuyruk yukarıda ($\theta=\pi/2$'de 4), sivri uç kutupta ($\theta=3\pi/2$'de 0).

**Örnek 7 (pratik çizim):** $r=a(1-\cos\theta)$.

| $\theta$ | $0$ | $\pi/2$ | $\pi$ | $3\pi/2$ |
|---|---|---|---|---|
| $r$ | $0$ | $a$ | $2a$ | $a$ |

- Kardiyoidin uzun kısmı negatif $x$ ekseni yönündedir.

**Kardiyoid koşulu:** $r=a(1\pm\sin\theta)$ ya da $r=a(1\pm\cos\theta)$ biçiminde olmalı. Parantez içindeki sabit 1 ile trigonometrik terimin katsayısı eşit olmalıdır.

**Örnek 8:** $r=2-4\sin\theta$ kardiyoid değildir (katsayılar eşit değil). Bu eğri iç döngülü bir limaçondur.

| $\theta$ | $0$ | $\pi/2$ | $\pi$ | $3\pi/2$ |
|---|---|---|---|---|
| $r$ | $2$ | $-2$ | $2$ | $6$ |

- $\theta=\pi/2$'de $r=-2$ olduğundan nokta aşağıda, $(0,-2)$'dedir.
- $\theta=3\pi/2$'de $r=6$, nokta $(0,-6)$'dadır.
- Bu tür eğrilerde normal çizim yöntemi (tablo, simetri, türev) kullanılır.

**Gül eğrileri:** $r=\sin 3\theta$, $r=\cos 3\theta$ gibi eğriler. Hoca bunların pratik çizimlerinin ders notlarında olduğunu söyledi.

**Öğrenci sorusu:** İçinde $\tan\theta$ olan bir eğri gelirse ne yapılır? Hoca: genel eğri çizim maddeleri uygulanır. Simetriye bakılır, ara noktalar alınır. Bu tür sorular az gelir.

### Kutupsal koordinatlarda alan

$r=f(\theta)$ eğrisi ile $\theta=\alpha$ ve $\theta=\beta$ doğrularının sınırladığı bölgenin alanı:

$$A=\frac12\int_\alpha^\beta r^2\,d\theta.$$

- Bölge simetrikse yarısı hesaplanıp 2 ile çarpılır.

**Örnek 9:** $r=2(1+\sin\theta)$ kardiyoidinin alanı.

- Eğri $y$ eksenine göre simetrik. Sağ yarı $-\pi/2$ ile $\pi/2$ arasıdır.
- $A=2\cdot\dfrac12\displaystyle\int_{-\pi/2}^{\pi/2}4(1+\sin\theta)^2\,d\theta=4\int_{-\pi/2}^{\pi/2}\left(1+2\sin\theta+\sin^2\theta\right)d\theta$.
- $\int 1=\pi$, $\int 2\sin\theta=0$, $\int\sin^2\theta=\dfrac{\pi}{2}$.
- $A=4\cdot\dfrac{3\pi}{2}=6\pi$.
- Derste sonuç hesaplanmadı. Genel kural: $r=a(1\pm\sin\theta)$ kardiyoidinin alanı $\dfrac{3\pi a^2}{2}$.

**Örnek 10 (çıkmış soru):** $r=4\cos\theta$ ve $r=4\sin\theta$ eğrilerinin ortak alanı.

- İki eğri de birinci bölgeye dayalı çemberdir.
- Kesişme: $4\cos\theta=4\sin\theta\Rightarrow\tan\theta=1\Rightarrow\theta=\dfrac{\pi}{4}$.
- $0$ ile $\pi/4$ arasında ortak bölgenin sınırı $r=4\sin\theta$, $\pi/4$ ile $\pi/2$ arasında $r=4\cos\theta$'dır.
- $A=\dfrac12\displaystyle\int_0^{\pi/4}16\sin^2\theta\,d\theta+\dfrac12\int_{\pi/4}^{\pi/2}16\cos^2\theta\,d\theta$.
- İki parça eşit: her biri $8\left(\dfrac{\pi}{8}-\dfrac14\right)=\pi-2$.
- $A=2\pi-4$. Derste sayısal sonuç söylenmedi.

**Örnek 11 (çıkmış soru):** $r=1$ çemberinin dışında, $r=1+\cos\theta$ kardiyoidinin içinde kalan bölgenin alanı.

- Kesişme: $1=1+\cos\theta\Rightarrow\cos\theta=0\Rightarrow\theta=\pm\dfrac{\pi}{2}$.
- Üst yarı hesaplanıp 2 ile çarpılır:

$$A=2\cdot\frac12\int_0^{\pi/2}\left[(1+\cos\theta)^2-1^2\right]d\theta=\int_0^{\pi/2}\left(2\cos\theta+\cos^2\theta\right)d\theta=2+\frac{\pi}{4}.$$

**Örnek 12 (hocanın kendi sorusu):** $r=2$ çemberinin dışında, $r=2(1+\cos\theta)$ kardiyoidinin içinde kalan bölgenin alanı ve sınır yay uzunluğu.

- Kardiyoid tablosu: $\theta=0$'da 4, $\pi/2$'de 2, $\pi$'de 0, $3\pi/2$'de 2.
- Kesişme: $2=2+2\cos\theta\Rightarrow\theta=\pm\dfrac{\pi}{2}$.
- Alan: $A=2\cdot\dfrac12\displaystyle\int_0^{\pi/2}\left[4(1+\cos\theta)^2-4\right]d\theta=4\left(2+\dfrac{\pi}{4}\right)=8+\pi$.
- Kardiyoid tarafındaki yay: $r^2+r'^2=8(1+\cos\theta)=16\cos^2\dfrac{\theta}{2}$.
  - $L=\displaystyle\int_{-\pi/2}^{\pi/2}4\cos\frac{\theta}{2}\,d\theta=8\sqrt2$.
- Hoca integralleri kurdu, sonucu hesaplamadan dersi bitirdi. Sonuçları biz hesapladık.

### Kutupsal koordinatlarda yay uzunluğu

$$L=\int_\alpha^\beta\sqrt{r^2+\left(r'\right)^2}\,d\theta.$$

**Örnek 13:** $r=1+\cos\theta$ kardiyoidinin uzunluğu.

- $r'=-\sin\theta$. $r^2+r'^2=2+2\cos\theta=4\cos^2\dfrac{\theta}{2}$.
- Üst yarı $0$ ile $\pi$ arasında hesaplanır, 2 ile çarpılır. Böylece mutlak değerle uğraşılmaz.
- $L=2\displaystyle\int_0^{\pi}2\cos\frac{\theta}{2}\,d\theta=8$.

**Örnek 14:** $r=\cos\theta$ çemberinin uzunluğu ($-\pi/2\le\theta\le\pi/2$).

- $r^2+r'^2=\cos^2\theta+\sin^2\theta=1$.
- $L=\displaystyle\int_{-\pi/2}^{\pi/2}1\,d\theta=\pi$. Bu, çapı 1 olan çemberin çevresidir.

**Örnek 15:** $r=1-\cos\theta$ ve $r=1+\sin\theta$ kardiyoidlerinin uzunluğu.

- Aynı yöntemle bulunur. İkisinde de sonuç 8'dir.
- $0$ ile $2\pi$ arasında integral alınırsa mutlak değer gerekir. Yarısı alınıp 2 ile çarpmak daha kolaydır.

**Parametrik örnek (çıkmış soru):** Parametrik verilen bir eğrinin $-1\le t\le1$ arasındaki uzunluğu, parametrik yay formülüyle bulundu. Eğrinin denklemi altyazıda net anlaşılmıyor ("$x=t^3$, ... $t^2$" gibi geçiyor).

### Ders sonrası notlar

- **$r=2a\cos\theta$ çemberi:** Hoca bir yerde "merkezi $(a,0)$, yarıçapı $a/2$ olan çember" dedi. Doğrusu: $r=2a\cos\theta$ çemberinin merkezi $(a,0)$, yarıçapı $a$'dır. Merkezi $(a/2,0)$ ve yarıçapı $a/2$ olan çember $r=a\cos\theta$'dır.
- **$r=2-4\sin\theta$:** Hoca "eğri kutuptan geçmiyor" dedi. Doğrusu: $\sin\theta=\dfrac12$ iken ($\theta=\pi/6$ ve $5\pi/6$) $r=0$ olur. İç döngülü limaçon kutuptan iki kez geçer.
- **$r=1+\cos\theta$ yay uzunluğu:** Altyazıda kök içinin karekökü "$2\cos\theta$ ... teta belki" gibi geçiyor; hoca büyük olasılıkla $2\cos\frac{\theta}{2}$ demek istedi. Doğru ifade $\sqrt{2+2\cos\theta}=2\cos\dfrac{\theta}{2}$'dir ($0\le\theta\le\pi$). Toplam uzunluk 8'dir.
- **$r=2(1+\sin\theta)$ tablosu:** Hoca $\theta=\pi$ değerini bir an karıştırdı. Doğrusu $r(\pi)=2$, $r(3\pi/2)=0$.
- Bazı integral sonuçlarını hoca slayttan gösterdi, sesli okumadı. Bunlar altyazıda yok. Yukarıdaki sayısal sonuçları biz hesapladık.
- Ders sonundaki gül eğrisi ($r=\sin 3\theta$) alan sorusu yalnız slaytta gösterildi. Çözümü altyazıda anlaşılmıyor.

---

İsterseniz bu özeti Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
