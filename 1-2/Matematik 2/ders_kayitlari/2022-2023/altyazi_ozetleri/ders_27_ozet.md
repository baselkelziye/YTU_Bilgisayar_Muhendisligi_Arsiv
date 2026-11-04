# Ders 27 Çalışma Özeti

Tarih: 29 Mayıs 2023 (Pazartesi). Dönemin sondan bir önceki dersi. Final hazırlığı için "Test-7" adlı çalışma soruları çözüldü. Sorular hocanın "mat2 avesis" klasöründeki PDF'ten ekrana yansıtıldı. Konular: vektör değerli fonksiyonlar (vector-valued functions), eğri uzunluğu, çok değişkenli fonksiyonlarda tanım bölgesi (domain), limit ve süreklilik (continuity).

## Genel Konular

- Konum vektöründen hız ve ivme vektörü, iki vektör arasındaki açı.
- Vektör fonksiyonun tanım kümesi.
- Uzay eğrisinin bir noktasındaki teğet doğrusu (tangent line).
- Parametrik uzay eğrisinin yay uzunluğu (arc length).
- İki değişkenli fonksiyonların tanım bölgesi: `arccos`, `ln`, kök ve payda koşulları.
- İki değişkenli limitler: eşlenikle çarpma, $\frac{\sin u}{u}\to1$ kalıbı.
- Limitin yoktuğunu gösterme: $y=mx$, $x=my^2$, $x=m^3y^3$ gibi yollar.
- Sıkıştırma teoremi (squeeze theorem) ile süreklilik.

## Hocanın Özellikle Vurguladığı Kısımlar

- Finalde limit, süreklilik, eğri uzunluğu ve tanım bölgesinden mutlaka soru gelecek.
- Tanım bölgesi sorularında paydanın sıfır olmaması koşulu sık atlanıyor. Şıklar bu ayrıntıyla çeldirici yapılıyor.
- Limitin yokluğunu göstermek için doğru yolu seçmek gerekir. Kuvvetler eşitlenecek şekilde dönüşüm yapılır: $y^4$ ile $x^2$ varsa $x=my^2$, küp kök varsa $x=m^3y^3$.
- Sonuç $m$'ye bağlı çıkarsa limit yoktur. Limit yoksa fonksiyon sürekli değildir.
- "Soru ilmin yarısıdır": öğrencilerden anlamadıkları yeri sormaları istendi.

## Kısa Tekrar Notları

- Hız: $\vec v(t)=\vec r\,'(t)$. İvme: $\vec a(t)=\vec r\,''(t)$.
- İki vektör arasındaki açı: $\cos\theta=\dfrac{\vec v\cdot\vec a}{|\vec v|\,|\vec a|}$.
- Teğet doğrusu: $x=x_0+v_1t$, $y=y_0+v_2t$, $z=z_0+v_3t$; $\vec v=\vec r\,'(t_0)$.
- Yay uzunluğu: $L=\displaystyle\int_a^b|\vec r\,'(t)|\,dt=\int_a^b\sqrt{x'^2+y'^2+z'^2}\,dt$.
- `arccos u` için $-1\le u\le1$. `ln u` için $u>0$. $\sqrt u$ için $u\ge0$. Payda $\ne0$.
- $0<u<1$ ise $\ln u<0$. Bu yüzden $\sqrt{\ln u}$ için $u\ge1$ gerekir.

## Detaylı Açıklamalar

### Soru 1: Hız ve ivme arasındaki açı

- $\vec r(t)=\dfrac{\sqrt2}{2}t\,\vec i+\left(\dfrac{\sqrt2}{2}t-16t^2\right)\vec j$, $t=0$.
- $\vec v(t)=\left\langle\tfrac{\sqrt2}{2},\ \tfrac{\sqrt2}{2}-32t\right\rangle$, $\vec v(0)=\left\langle\tfrac{\sqrt2}{2},\tfrac{\sqrt2}{2}\right\rangle$, $|\vec v(0)|=1$.
- $\vec a(t)=\langle0,-32\rangle$, $|\vec a|=32$.
- $\vec v\cdot\vec a=-16\sqrt2$. $\cos\theta=\dfrac{-16\sqrt2}{32}=-\dfrac{\sqrt2}{2}$.
- Sonuç: $\theta=\dfrac{3\pi}{4}$ (d şıkkı).

### Soru 2: Vektör fonksiyonun tanım kümesi

- $\vec F(t)=e^t\,\vec i+\sin t\,\vec j+3\ln(1-t)\,\vec k$.
- $e^t$ ve $\sin t$ her yerde tanımlı. $\ln(1-t)$ için $1-t>0$, yani $t<1$.
- Kesişim: $(-\infty,1)$ (c şıkkı).

### Soru 3: Teğet doğrusu

- $\vec r(t)=(3t^2+1)\,\vec i+(4t^3-3)\,\vec j+(6t+2)\,\vec k$, nokta $(4,1,8)$.
- $3t^2+1=4$, $4t^3-3=1$, $6t+2=8$ denklemlerinin ortak çözümü $t=1$.
- $\vec r\,'(t)=\langle6t,\ 12t^2,\ 6\rangle$, $\vec r\,'(1)=\langle6,12,6\rangle$.
- Teğet doğrusu: $x=4+6t$, $y=1+12t$, $z=8+6t$.

### Soru 4: Yay uzunluğu integrali

- $\vec r(t)=\langle e^t\cos t,\ e^t\sin t,\ e^t\rangle$, $0\le t\le1$.
- $x'=e^t(\cos t-\sin t)$, $y'=e^t(\sin t+\cos t)$, $z'=e^t$.
- $x'^2+y'^2=2e^{2t}$, toplam $3e^{2t}$.
- $L=\displaystyle\int_0^1\sqrt3\,e^t\,dt$ (b şıkkı).

### Soru 5: Yay uzunluğu

- $\vec r(t)=(1+t^2)^{3/2}\,\vec i+(3-t^2)^{3/2}\,\vec j+4t^2\,\vec k$, $-1\le t\le1$.
- $x'=3t\sqrt{1+t^2}$, $y'=-3t\sqrt{3-t^2}$, $z'=8t$.
- $x'^2+y'^2+z'^2=9t^2(1+t^2)+9t^2(3-t^2)+64t^2=100t^2$.
- $L=\displaystyle\int_{-1}^1 10|t|\,dt=10$ (c şıkkı).

### Soru 6: Tanım bölgesi (çeldiricili)

- $f(x,y)=\arccos\dfrac{y}{x^2}+\ln(1-x^2)$.
- `arccos`: $-1\le\dfrac{y}{x^2}\le1\Rightarrow -x^2\le y\le x^2$.
- `ln`: $1-x^2>0\Rightarrow -1<x<1$.
- Payda: $x\ne0$.
- Sonuç: $-x^2\le y\le x^2$, $-1<x<1$, $x\ne0$.
- Hoca: ilk şık $x\ne0$ koşulu olmadan verilmiş. Hızlı okuyan öğrenci bu şıkka düşer.

### Soru 7: Tanım bölgesi

- $f(x,y)=\dfrac{\sqrt{x-y^2}}{\ln(x-2)}$.
- Kök: $x\ge y^2$. `ln`: $x>2$. Payda: $\ln(x-2)\ne0$.
- Bölge: $x>2$, $x\ge y^2$, $x\ne3$ (bkz. ders sonrası notlar).

### Soru 8: Tanım bölgesi (çarpanlara ayırma)

- $f(x,y)=\ln(y^2x-1+y^2-x)$.
- $y^2x+y^2-x-1=y^2(x+1)-(x+1)=(y^2-1)(x+1)$.
- Koşul: $(y^2-1)(x+1)>0$.
  - Durum 1: $y^2>1$ ve $x>-1$. Yani $|y|>1$, $x>-1$.
  - Durum 2: $y^2<1$ ve $x<-1$. Yani $-1<y<1$, $x<-1$.
- Bölge bu iki parçanın birleşimidir. Hoca iki durumu tahtada ayrı ayrı çizdi.

### Soru 9: Tanım bölgesi

- $f(x,y)=\arccos\dfrac{x}{y^2}+\sqrt{\ln(1-xy)}$.
- `arccos`: $-y^2\le x\le y^2$, ayrıca $y\ne0$.
- Kök içi: $\ln(1-xy)\ge0\Rightarrow1-xy\ge1\Rightarrow xy\le0$.
- Cevap: $\{(x,y)\mid -y^2\le x\le y^2,\ xy\le0,\ y\ne0\}$ (e şıkkı).

### Soru 10: Eşlenikle limit

- $\displaystyle\lim_{(x,y)\to(0^+,2^-)}\frac{x+y-2}{\sqrt x+\sqrt{2-y}}$.
- $x+y-2=x-(2-y)=(\sqrt x-\sqrt{2-y})(\sqrt x+\sqrt{2-y})$.
- Sadeleşince limit $\sqrt x-\sqrt{2-y}\to0$. Cevap 0.

### Soru 11: $\sin u/u$ kalıbı

- $\displaystyle\lim_{(x,y)\to(0,0)}\frac{e^{xy}\sin(xy)}{xy}$.
- $u=xy\to0$ için $\dfrac{\sin u}{u}\to1$, $e^{u}\to1$. Cevap 1.

### Soru 12: Eşlenikle limit

- $\displaystyle\lim_{(x,y)\to(0,0)}\frac{x^2+y^2}{1-\sqrt{1+x^2+y^2}}$.
- $u=x^2+y^2$ deyip eşlenikle çarp: $\dfrac{u(1+\sqrt{1+u})}{1-(1+u)}=-(1+\sqrt{1+u})\to-2$. Cevap $-2$.
- Derste sonuç sesli okunmadı, hesaplanarak eklendi.

### Soru 13: Parçalı fonksiyon, hangi ifadeler doğru

- $f(x,y)=\dfrac{3xy}{x^2+y^2}$, $(x,y)\ne(0,0)$; $f(0,0)=0$.
- I. $(0,0)$'da tanımlı: doğru.
- II. $y=x^2$ boyunca limit 0: $\dfrac{3x^3}{x^2+x^4}=\dfrac{3x}{1+x^2}\to0$. Doğru.
- III. $(0,0)$'daki limit 0: yanlış. $y=mx$ boyunca $\dfrac{3m}{1+m^2}$ çıkar, $m$'ye bağlı. Limit yok.
- IV. Sürekli: yanlış, çünkü limit yok.
- Cevap: yalnız I ve II.

### Soru 14: Limitin mevcudiyeti

- Fonksiyonun tam ifadesi altyazıda net anlaşılmıyor (payında $x\ln(1+y)$ benzeri bir ifade var).
- Yöntem: $y=mx$ yerine konur, $\frac00$ belirsizliği L'Hôpital (L'Hôpital's rule) ile açılır.
- Sonuç $m$'ye bağlı çıkar. Limit yoktur.

### Soru 15: İki fonksiyonun sürekliliği

- $g(x,y)=\dfrac{xy^2}{x^2+y^4}$ benzeri ($g(0,0)=0$): $x=my^2$ yolu ile $\dfrac{m}{m^2+1}$ çıkar. Limit yok, $g$ süreksiz.
- $f(x,y)=x\sin\dfrac1y$ benzeri ($f(0,0)=0$): $-1\le\sin\frac1y\le1$. Her tarafı $|x|$ ile çarp, sıkıştırma teoremi ile limit 0. $f$ sürekli.
- Cevap: g süreksiz, f sürekli (c şıkkı).

### Soru 16: Küp köklü fonksiyon

- $f(x,y)=\dfrac{\sqrt[3]{x}\,y^2}{x+y^3}$, $f(0,0)=0$.
- $x=m^3y^3$ yolu: $\sqrt[3]{x}=my$. İfade $\dfrac{my^3}{(m^3+1)y^3}=\dfrac{m}{m^3+1}$.
- $m$'ye bağlı, limit yok.
- I tanımlı: doğru. II limit var: yanlış. III "limit 1 olduğu için süreksiz": yanlış. IV "limit olmadığı için süreksiz": doğru.
- Cevap: I ve IV (c şıkkı).

### Ders sonrası notlar

- Soru 7'de hoca paydadan yalnız "$x\ne2$" koşulunu çıkardı. $x>2$ zaten bunu kapsıyor. Asıl koşul $\ln(x-2)\ne0$, yani $x-2\ne1$, $x\ne3$.
- Soru 9'da hoca bir an "$x<0$" dedi. Doğru koşul $xy\le0$. Şıktaki "$y\ne0$" ekini hoca tahtada kendisi ekledi.
- Soru 13'te hoca $y=x^2$ yolunu bir an $x^4$'lü bir paydayla karıştırdı. Doğru hesap yukarıda.
- Soru 1, 5 ve 12'nin sonuçları derste sesli okunmadı. Değerler hesaplanarak eklendi.
- 01:18:25-01:20:47 arasında hocanın sesi gelmiyor. Bu aralık altyazıda yok.

## Duyurular

- Final soruları limit, süreklilik, eğri uzunluğu ve tanım bölgesinden gelecek.
- Bir öğrenci soruların paylaşılmasını istedi. Hoca asistanının soruları AVES'e yükleyeceğini söyledi.
- Hoca derse paralel bir workshop'un açılışını yapacağı için ders biraz erken bitti.
- Ertesi gün (30 Mayıs) saat 11.00'de yeni sorularla devam edilecek.

İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
