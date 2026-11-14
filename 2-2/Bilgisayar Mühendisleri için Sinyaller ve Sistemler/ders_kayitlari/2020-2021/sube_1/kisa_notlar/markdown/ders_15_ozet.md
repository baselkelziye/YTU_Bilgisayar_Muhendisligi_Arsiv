# Ders 15 Çalışma Özeti

## Genel Konular

- Asıl ders yaklaşık 00:03'te başlar.
- z-dönüşümü tekrarı
  - Yakınsaklık bölgesi (ROC) şartı ve neden önemli olduğu.
  - Temel çiftler: $\delta[n-k]$, $u[n]$, $-u[-n-1]$, $a^n u[n]$, $-a^n u[-n-1]$, $n a^n u[n]$.
  - $n$ ile çarpma özelliği (z düzleminde türev).
- Ters z-dönüşümü
  - Kontür integrali tanımı.
  - Kısmi kesirlere ayırma: $X(z)/z$ yöntemi.
  - Sol taraflı ve sağ taraflı çözümler, katlı kutup.
  - Gecikme ($z^{-k}$) içeren ifadelerin ters dönüşümü.
- z-dönüşümüyle konvolüsyon (polinom çarpımı).
- Kapsamlı IIR örneği: sistem fonksiyonu, kutup-sıfır, impuls cevabı, birim basamak cevabı.
- Tek taraflı (unilateral) z-dönüşümü ve başlangıç koşulları
  - Fark denklemlerinin başlangıç koşullarıyla çözümü.
- Blok diyagramdan sistem fonksiyonu.

## Hocanın Özellikle Vurguladığı Kısımlar

- Yakınsaklık bölgesine dikkat edin.
  - Aynı $X(z)$ ifadesi, ROC'a göre farklı işaretlere karşılık gelir. Normal ve ters dönüşüm sorularında ROC sizi yanıltabilir.
- Payda $z$ varken doğrudan kısmi kesir yapmayın. Önce $X(z)/z$ yazın.
  - Tabloda $\dfrac{c}{z-a}$ biçiminde bir çift yoktur. $\dfrac{z}{z-a}$ biçimi vardır.
  - Açılımı yaptıktan sonra $z$'yi geri çarpın.
- $\dfrac{z}{z+a}$ ifadesinde işaret değişir: bu $(-a)^n$'e karşılık gelir.
- $z^{-k}$ çarpanı $k$ birim gecikme demektir.
  - Bilinen bir forma getirmek için pay ve paydayla oynayın, sonra gecikmeyi uygulayın.
- Paydada kare varsa ($(z-a)^2$), işaret $n$ ile çarpılmıştır. Küp varsa $n^2$ terimi gelir: $n^2a^n u[n] \leftrightarrow \dfrac{az(z+a)}{(z-a)^3}$, $|z|>|a|$ (Python ile doğrulandı).
- Nedensel sistem, sağ taraflı demektir. ROC en büyük kutbun dışında olur.
- Fark, türevin ayrık karşılığıdır: $x[n]-x[n-1]$.
  - $y[n]$'den $y[n-1]$'e geçiş ise türev değil, bir birim gecikmedir.
- Başlangıç koşulu verilmişse tek taraflı dönüşüm kuralları uygulanmalıdır.

## Kısa Tekrar Notları

- $\delta[n-k] \leftrightarrow z^{-k}$, $\delta[n+k] \leftrightarrow z^{k}$.
- $u[n] \leftrightarrow \dfrac{z}{z-1}$, $|z|>1$.
- $-u[-n-1] \leftrightarrow \dfrac{z}{z-1}$, $|z|<1$.
- $a^n u[n] \leftrightarrow \dfrac{z}{z-a}$, $|z|>|a|$.
- $-a^n u[-n-1] \leftrightarrow \dfrac{z}{z-a}$, $|z|<|a|$.
- $n a^n u[n] \leftrightarrow \dfrac{az}{(z-a)^2}$, $|z|>|a|$.
  - Buna göre $\dfrac{z}{(z-a)^2} \leftrightarrow n a^{n-1}u[n]$.
- $n$ ile çarpma: $n\,x[n] \leftrightarrow -z\dfrac{dX(z)}{dz}$.
- Ters z-dönüşümü (tanım): $x[n]=\dfrac{1}{2\pi j}\oint_C X(z)z^{n-1}\,dz$.
  - Pratikte tablo, özellikler ve kısmi kesirler kullanılır.
- Tek taraflı z-dönüşümünde gecikme:
  - $y[n-1] \leftrightarrow z^{-1}Y(z)+y[-1]$.
  - $y[n-2] \leftrightarrow z^{-2}Y(z)+z^{-1}y[-1]+y[-2]$.
- Tek taraflı Laplace'ta türev: $y'(t) \leftrightarrow sY(s)-y(0^-)$. İki taraflıda yalnızca $sY(s)$.
- FIR filtre yalnızca girişin farklı anlarına bağlıdır. IIR filtre çıkışın önceki değerlerine de bağlıdır.

## Detaylı Açıklamalar

### ROC şartının mantığı

- $a^n u[n]$ için $X(z)=\sum_{n=0}^{\infty}(az^{-1})^n$.
- $|az^{-1}|$ 1'den büyükse terimler üstel büyür, toplam ıraksar.
- Yakınsama için $|az^{-1}|<1$ gerekir. ROC bu şarttan bulunur.

### $n$ ile çarpma: $n a^n u[n]$

- $a^n u[n] \leftrightarrow \dfrac{z}{z-a}$.
- Türev: $\dfrac{d}{dz}\left(\dfrac{z}{z-a}\right)=\dfrac{(z-a)-z}{(z-a)^2}=\dfrac{-a}{(z-a)^2}$.
- $-z$ ile çarpılır: $n a^n u[n] \leftrightarrow \dfrac{az}{(z-a)^2}$, $|z|>|a|$.

### Örnek 1: $X(z)=\dfrac{z}{2z^2-3z+1}$, $|z|<\frac12$

- Payda çarpanlarına ayrılır: $2z^2-3z+1=2(z-1)\left(z-\frac12\right)$.
- $\dfrac{X(z)}{z}=\dfrac{1}{2(z-1)\left(z-\frac12\right)}=\dfrac{c_1}{z-1}+\dfrac{c_2}{z-\frac12}$.
- Katsayılar:
  - $c_1=\dfrac{1}{2\left(1-\frac12\right)}=1$.
  - $c_2=\dfrac{1}{2\left(\frac12-1\right)}=-1$.
- $X(z)=\dfrac{z}{z-1}-\dfrac{z}{z-\frac12}$.
- ROC $|z|<\frac12$: iki kutbun da içinde. İşaret sol taraflıdır.
- $x[n]=-u[-n-1]+\left(\frac12\right)^n u[-n-1]$.
- Hoca: Benzer soruyu "$|z|>\frac12$" şartıyla da çözün.
  - Kutuplar 1 ve $\frac12$ olduğu için bu şart aslında $\frac12<|z|<1$ halkasıdır.
  - $\frac{z}{z-\frac12}$ terimi sağ taraflı, $\frac{z}{z-1}$ terimi sol taraflı olur: $x[n]=-u[-n-1]-\left(\frac12\right)^n u[n]$.
  - $|z|>1$ olsaydı iki terim de sağ taraflı olurdu: $x[n]=\left(1-\left(\frac12\right)^n\right)u[n]$.

### Örnek 2: $X(z)=\dfrac{z}{(z-1)(z-2)^2}$, $|z|>2$

- $\dfrac{X(z)}{z}=\dfrac{1}{(z-1)(z-2)^2}=\dfrac{c_1}{z-1}+\dfrac{c_2}{z-2}+\dfrac{c_3}{(z-2)^2}$.
- Katsayılar:
  - $c_1=\dfrac{1}{(1-2)^2}=1$.
  - $c_3=\dfrac{1}{2-1}=1$.
  - $c_2=-1$. Hoca önce $1$ dedi, sonra $-1$ olarak düzeltti.
- $X(z)=\dfrac{z}{z-1}-\dfrac{z}{z-2}+\dfrac{z}{(z-2)^2}$.
- ROC $|z|>2$: en büyük kutbun dışı, işaret sağ taraflı.
- $\dfrac{z}{(z-2)^2}$ terimi için: $n2^n u[n] \leftrightarrow \dfrac{2z}{(z-2)^2}$. Payda 2 olmadığı için sonuç $\frac12$ ile çarpılır: $n2^{n-1}u[n]$.
- Sonuç: $x[n]=\left(1-2^n+n2^{n-1}\right)u[n]$.
- Python ile ilk değerler kontrol edildi: $0,0,1,5,17,49,129,\dots$

### Çalışma sorusu

- $X(z)=\dfrac{2+z^{-2}+3z^{-4}}{z^2+4z+3}$ (tahtadaki yazım). Ters dönüşümünü bulun.
- Hoca: önce biraz cebirsel düzenleme yapıp bilinen forma getirin. Kitapta buna benzer çok örnek var.
- Çözüm önerisi (sağ taraflı varsayımıyla):
  - Pay ve payda $z^{-2}$ ile çarpılır: $X(z)=\left(2z^{-2}+z^{-4}+3z^{-6}\right)G(z)$, $G(z)=\dfrac{1}{1+4z^{-1}+3z^{-2}}$.
  - $G(z)=\dfrac{1}{(1+z^{-1})(1+3z^{-1})}=\dfrac{-\frac12}{1+z^{-1}}+\dfrac{\frac32}{1+3z^{-1}}$.
  - $g[n]=\left(-\frac12(-1)^n+\frac32(-3)^n\right)u[n]$.
  - $x[n]=2g[n-2]+g[n-4]+3g[n-6]$.
  - Python ile ilk değerler kontrol edildi: $0,0,2,-8,27,-84,\dots$

### z-dönüşümüyle konvolüsyon

- $x[n]=\{1,1,1\}$, $h[n]=\{1,1\}$ ($n=0$'dan başlar).
- $X(z)=1+z^{-1}+z^{-2}$, $H(z)=1+z^{-1}$.
- $Y(z)=X(z)H(z)=1+2z^{-1}+2z^{-2}+z^{-3}$.
- $y[n]=\delta[n]+2\delta[n-1]+2\delta[n-2]+\delta[n-3]$.
- Bu yöntemle sonucun nerede başlayıp bittiği de kolay görülür ($n=0$'dan $n=3$'e).

### Kapsamlı örnek: $y[n]-\frac34 y[n-1]+\frac18 y[n-2]=x[n]$ (nedensel)

- Çıkışın önceki değerleri olduğu için bu bir IIR sistemdir.
- **a) Sistem fonksiyonu:**
  - $Y(z)\left(1-\frac34 z^{-1}+\frac18 z^{-2}\right)=X(z)$.
  - $H(z)=\dfrac{1}{1-\frac34 z^{-1}+\frac18 z^{-2}}=\dfrac{z^2}{z^2-\frac34 z+\frac18}=\dfrac{z^2}{\left(z-\frac12\right)\left(z-\frac14\right)}$.
- **Kutuplar ve sıfırlar:**
  - Kutuplar: $\frac12$ ve $\frac14$.
  - Sıfır: $z=0$'da (çift katlı).
  - $z^{-1}$'li biçimde sıfır görünmez. Pozitif kuvvetlere geçince görünür.
- **b) İmpuls cevabı $h[n]$:**
  - $\dfrac{H(z)}{z}=\dfrac{z}{\left(z-\frac12\right)\left(z-\frac14\right)}=\dfrac{A}{z-\frac12}+\dfrac{B}{z-\frac14}$.
  - $A=2$, $B=-1$. Öğrenci, ikinci kesrin paydasının $z-\frac14$ olması gerektiğini düzeltti.
  - Sistem nedensel olduğu için ROC $|z|>\frac12$ ve işaret sağ taraflıdır.
  - $h[n]=\left(2\left(\frac12\right)^n-\left(\frac14\right)^n\right)u[n]$.
- **c) Birim basamak cevabı:**
  - $x[n]=u[n]$, $X(z)=\dfrac{z}{z-1}$.
  - $Y(z)=X(z)H(z)=\dfrac{z^3}{(z-1)\left(z-\frac12\right)\left(z-\frac14\right)}$.
  - $\dfrac{Y(z)}{z}$ açılımı: katsayılar $\frac83$, $-2$, $\frac13$.
  - $y[n]=\left(\frac83-2\left(\frac12\right)^n+\frac13\left(\frac14\right)^n\right)u[n]$.
  - Öğrenci, ikinci terimin $\left(\frac14\right)^n$ değil $\left(\frac12\right)^n$ olması gerektiğini düzeltti.
  - Hoca: Örneğin $n=8$'deki çıkış, bu ifadede $n=8$ yazılarak bulunur.
- Python ile özyineleme yapılarak $h[n]$ ve $y[n]$'nin ilk değerleri kontrol edildi. Sonuçlar tuttu.

### Gecikmeli ifadelerin ters dönüşümü

- **Örnek:** $H(z)=\dfrac{1+z^{-1}}{1-0.3z^{-1}}=\dfrac{1}{1-0.3z^{-1}}+z^{-1}\cdot\dfrac{1}{1-0.3z^{-1}}$.
  - İlk terim: $0.3^n u[n]$.
  - İkinci terim, ilk terimin bir birim gecikmiş hâlidir: $0.3^{n-1}u[n-1]$.
  - $h[n]=0.3^n u[n]+0.3^{n-1}u[n-1]$.
- **Örnek:** $X(z)=\dfrac{z^{-4}}{z-1}+z^{-6}+\dfrac{z^{-3}}{z+0.5}$ (sağ taraflı).
  - $\dfrac{z^{-4}}{z-1}=z^{-5}\cdot\dfrac{z}{z-1} \rightarrow u[n-5]$.
  - $z^{-6} \rightarrow \delta[n-6]$.
  - $\dfrac{z^{-3}}{z+0.5}=z^{-4}\cdot\dfrac{z}{z-(-0.5)} \rightarrow (-0.5)^{n-4}u[n-4]$.
  - $x[n]=u[n-5]+\delta[n-6]+(-0.5)^{n-4}u[n-4]$.
  - Paydadaki "$+0.5$", tabloda "$-a$" ile karşılaştırılınca $a=-0.5$ olur. İşarete dikkat.
- **Örnek:** $F(z)=\dfrac{10z(z+5)}{(z-1)(z-2)(z+3)}$ (sağ taraflı).
  - $\dfrac{F(z)}{z}=\dfrac{10(z+5)}{(z-1)(z-2)(z+3)}=\dfrac{A}{z-1}+\dfrac{B}{z-2}+\dfrac{C}{z+3}$.
  - $z=1$: $A=\dfrac{60}{(-1)(4)}=-15$.
  - $z=2$: $B=\dfrac{70}{(1)(5)}=14$.
  - $z=-3$: $C=\dfrac{20}{(-4)(-5)}=1$.
  - $f[n]=\left(-15+14\cdot 2^n+(-3)^n\right)u[n]$.
  - Python ile kontrol edildi.

### Tek taraflı dönüşüm ve başlangıç koşulları

- Laplace'ta:
  - İki taraflı: $y'(t) \leftrightarrow sY(s)$.
  - Tek taraflı: $y'(t) \leftrightarrow sY(s)-y(0^-)$.
  - Örnek: Bir elektrik devresi $t=0$'da açılır. Sistem kapalıyken içindeki değer başlangıç koşuludur. Bu değerin hesaba katılması gerekir.
- Ayrık zamanda başlangıç koşulu $n=0$'ın bir öncesi, yani $y[-1]$'dir.
  - $y[n-1] \leftrightarrow z^{-1}Y(z)+y[-1]$.
  - $y[n-2] \leftrightarrow z^{-2}Y(z)+z^{-1}y[-1]+y[-2]$.
- **Örnek:** $y[n]-\frac12 y[n-1]=x[n]$, $x[n]=\left(\frac13\right)^n u[n]$, $y[-1]=1$.
  - $X(z)=\dfrac{z}{z-\frac13}$, $|z|>\frac13$.
  - $Y(z)-\frac12\left(z^{-1}Y(z)+1\right)=X(z)$.
  - $Y(z)=\dfrac{\frac12 z}{z-\frac12}+\dfrac{z^2}{\left(z-\frac12\right)\left(z-\frac13\right)}$.
  - Sonuç: $y[n]=\left(\frac72\left(\frac12\right)^n-2\left(\frac13\right)^n\right)u[n]$.
  - Hoca bunu "$7\left(\frac12\right)^{n+1}-2\left(\frac13\right)^n$" diye yazdı. İkisi aynıdır.
  - Python ile özyineleme yapılarak kontrol edildi.
- **Çalışma sorusu:** $3y[n]-4y[n-1]+y[n-2]=x[n]$, $x[n]=\left(\frac12\right)^n u[n]$, $y[-1]=1$, $y[-2]=2$.
  - Hem tek taraflı hem iki taraflı çözün. İki taraflı çözümde başlangıç koşulları dikkate alınmaz.
  - Hocanın verdiği tek taraflı sonuç: $y[n]=\frac32-\left(\frac12\right)^n+\frac12\left(\frac13\right)^n$, $n\ge -2$.
  - Python ile özyineleme yapılarak kontrol edildi. Sonuç doğru.

### Blok diyagramdan sistem fonksiyonu

- Diyagram: $y[n]$ bir birim geciktirilir ($z^{-1}$ kutusu), $\frac12$ ile çarpılır ve $x[n]$ ile toplanır.
- Fark denklemi: $y[n]=\frac12 y[n-1]+x[n]$.
- $H(z)=\dfrac{1}{1-\frac12 z^{-1}}$, $h[n]=\left(\frac12\right)^n u[n]$.
- $z^{-1}$ bir birim gecikme, $z^{+1}$ bir birim öne almadır.

### Kutup-sıfır diyagramı araçları

- MATLAB fonksiyonları: `tf2zp`, `pzmap`, `zplane`. Python'da da benzer fonksiyonlar vardır.
- Pay ve paydanın katsayıları girdi olarak verilir.

### Ders sonrası notlar

- Örnek 2'de hoca $c_2$'yi önce $+1$ buldu, sonra $-1$ olarak düzeltti. $\dfrac{z}{(z-2)^2}$ teriminin ters dönüşümünü önce $n2^n$ dedi, sonra $n2^{n-1}$ olarak düzeltti. Özetteki sonuçlar düzeltilmiş hâlleridir.
- Kapsamlı örnekte impuls cevabını hoca "eksi $\frac14$ çarpı $\left(\frac14\right)^n$" gibi okudu. Kısmi kesir katsayısı $B=-1$ olduğu için doğrusu $-\left(\frac14\right)^n$'dir.
- $H(z)=\frac{1+z^{-1}}{1-0.3z^{-1}}$ örneğinde altyazıda "0.33" geçiyor. Doğru değer $0.3$'tür ($\frac{3}{10}$).
- Derste "$y[n]$'den $y[n-1]$'e geçiş bir anlamda türev" dendi (01:28:32). Gecikme türev değildir. Türevin ayrık karşılığı farktır: $x[n]-x[n-1]$.
- Laplace türev özelliğinde tek taraflı/iki taraflı konusunda kısa bir karışıklık oldu. Doğrusu: $sY(s)-y(0^-)$ tek taraflı (unilateral), $sY(s)$ iki taraflı (bilateral) dönüşümdür.
- FIR filtre örneğinde hoca $\{1,2,1\}$ ağırlıklarıyla $1\cdot1+2\cdot2+1\cdot3=8$ bulup 3'e böldü ($\frac83$). Ağırlıklı ortalamada katsayıların toplamına, yani 4'e bölünür. Böylece sonuç $2$ olur.
- Kontrol edilen sonuçlar (Python ile): Örnek 1 ve 2'nin katsayıları, çalışma sorusunun çözümü, konvolüsyon, kapsamlı örneğin $h[n]$ ve basamak cevabı, $0.3$'lü ve $F(z)$'li ters dönüşümler, iki başlangıç koşullu fark denklemi.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.
