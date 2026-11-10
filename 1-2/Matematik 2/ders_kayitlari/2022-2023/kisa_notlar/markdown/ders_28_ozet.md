# Ders 28 Çalışma Özeti

Tarih: 30 Mayıs 2023 (Salı). Dönemin son dersi. Final için çok katlı integral (multiple integral) soruları çözüldü. Sorular ve cevap anahtarı hocanın "mat2 avesis" klasöründeki PDF'ten ekrana yansıtıldı. Bazı sorular tahtada (Paint) yeniden çizildi.

## Genel Konular

- İntegrasyon sırasını değiştirme (changing the order of integration).
- Kartezyen integrali kutupsal koordinatlara (polar coordinates) çevirme.
- Kutupsal integralle alan ve hacim.
- Değişken dönüşümü ve Jacobian (Jacobian determinant).
- Bir fonksiyonun bölge üzerindeki ortalama değeri (average value).

## Hocanın Özellikle Vurguladığı Kısımlar

- Finalde integrasyon sırasını değiştirme sorusu kesin gelecek. Bundan 1-2, bölge dönüşümünden (Jacobian) 1-2 soru bekleniyor.
- Kutupsal koordinat sorusu da gelecek.
- Önce bölge çizilir. Bölge doğru çizilirse soru büyük ölçüde çözülür.
- Kutupsal dönüşümde $dx\,dy$ yerine mutlaka $r\,dr\,d\theta$ yazılır. Jacobian'dan gelen $r$ en sık unutulan şey.
- Şıklar genelde yalnız sınırlarla ayrışır. $r$ ve $\theta$ sınırlarını doğru bulmak yeterli.
- Finalde konular taranacak: kısmi türev, kapalı fonksiyonun türevi, limit-süreklilik, seriler (1 soru), kutupsal koordinatlar, vektörler ve düzlemler, bol integral.

## Kısa Tekrar Notları

- İntegrasyon sırası değişirken: sınırlardan bölgeyi çiz, sonra diğer değişkene göre yeniden oku.
- Kutupsal: $x=r\cos\theta$, $y=r\sin\theta$, $x^2+y^2=r^2$, $dA=r\,dr\,d\theta$.
- Hacim: $V=\displaystyle\iint_D(\text{yükseklik})\,dA$.
- Dönüşüm: $dx\,dy=|J|\,du\,dv$, $J=\dfrac{\partial(x,y)}{\partial(u,v)}=\dfrac{1}{\dfrac{\partial(u,v)}{\partial(x,y)}}$.
- Ortalama değer: $f_{ort}=\dfrac{1}{\text{Alan}(D)}\displaystyle\iint_D f\,dA$.

## Detaylı Açıklamalar

### Soru 1: İntegrasyon sırasını değiştirme

- $\displaystyle\int_0^1\int_{\sqrt y}^1\frac{dx\,dy}{\sqrt{1+3x^3}}$ (altyazıda "3x kare" gibi geçiyor; büyük olasılıkla $3x^3$, sonuç $\frac29$ bununla uyumlu).
- Bölge: $0\le y\le1$, $\sqrt y\le x\le1$. $x=\sqrt y\Leftrightarrow y=x^2$.
- Yeni sıra: $0\le x\le1$, $0\le y\le x^2$.
- $I=\displaystyle\int_0^1\int_0^{x^2}\frac{dy\,dx}{\sqrt{1+3x^3}}$ (cevap B).
- Hesap: $\displaystyle\int_0^1\frac{x^2}{\sqrt{1+3x^3}}dx=\frac29\sqrt{1+3x^3}\Big|_0^1=\frac29$.

### Soru 2: Sıra değişince çözülebilen integral

- $\displaystyle\int_0^1\int_{\arcsin y}^{\pi/2}e^{\cos x}\,dx\,dy$.
- $x=\arcsin y\Leftrightarrow y=\sin x$. Bölge: $0\le x\le\frac\pi2$, $0\le y\le\sin x$.
- Yeni integral: $\displaystyle\int_0^{\pi/2}\int_0^{\sin x}e^{\cos x}\,dy\,dx=\int_0^{\pi/2}\sin x\,e^{\cos x}\,dx$.
- $u=\cos x$ ile sonuç $e-1$.
- Hoca: ilk sırada $e^{\cos x}$'in $x$'e göre integrali alınamaz. Sıra değişince iş kolaylaşıyor.

### Soru 3: Kutupsal dönüşüm

- Büyük olasılıkla (ekrandan) $\displaystyle\int_{-1}^0\int_{-\sqrt{1-x^2}}^0\frac{2}{1+\sqrt{x^2+y^2}}\,dy\,dx$.
- Bölge: birim çemberin üçüncü çeyreği ($x\le0$, $y\le0$).
- $I=\displaystyle\int_\pi^{3\pi/2}\int_0^1\frac{2}{1+r}\,r\,dr\,d\theta$ (cevap büyük olasılıkla (ekrandan) B).
- Hesap: $\displaystyle\int_0^1\frac{2r}{1+r}dr=2(1-\ln2)$. Sonuç $\pi(1-\ln2)$.

### Soru 4: İntegrasyon sırası ($e^{x^2}$)

- $\displaystyle\int_0^1\int_{3y}^3e^{x^2}\,dx\,dy$.
- Bölge: $0\le y\le1$, $3y\le x\le3$. Yeni sıra: $0\le x\le3$, $0\le y\le\frac x3$.
- $I=\displaystyle\int_0^3\int_0^{x/3}e^{x^2}\,dy\,dx$ (cevap B).
- Hesap: $\displaystyle\int_0^3\frac x3e^{x^2}dx=\frac{e^9-1}{6}$.

### Soru 5: Kaydırılmış çember, kutupsal

- $D$: $x^2+y^2=2x$ bölgesi, $f=x^2+y^2$.
- $(x-1)^2+y^2=1$: merkez $(1,0)$, yarıçap 1.
- Kutupsalda: $r^2=2r\cos\theta\Rightarrow r=2\cos\theta$. $\theta\in[-\frac\pi2,\frac\pi2]$.
- $I=\displaystyle\int_{-\pi/2}^{\pi/2}\int_0^{2\cos\theta}r^2\cdot r\,dr\,d\theta$ (c şıkkı).
- Hesap: $\displaystyle\int_{-\pi/2}^{\pi/2}4\cos^4\theta\,d\theta=\frac{3\pi}{2}$.

### Soru 6: Halka dilimi

- Bölge: $1\le x^2+y^2\le4$, $0\le y\le x$.
- $1\le r\le2$, $0\le\theta\le\frac\pi4$ ($y=x$ doğrusu $\theta=\frac\pi4$).
- İntegrandda $\arctan\frac yx$ benzeri bir ifade var. Kutupsalda $\arctan\frac yx=\theta$ olur.
- Hoca önce üst sınırı $\frac\pi2$ okudu, sonra $\frac\pi4$ diye düzeltti.

### Soru 7: İntegrasyon sırası ($e^y/(y+1)$)

- $\displaystyle\int_1^4\int_{\sqrt x}^2\frac{e^y}{y+1}\,dy\,dx$.
- Bölge: $1\le x\le4$, $\sqrt x\le y\le2$. Yeni sıra: $1\le y\le2$, $1\le x\le y^2$.
- $I=\displaystyle\int_1^2\int_1^{y^2}\frac{e^y}{y+1}\,dx\,dy$ (cevap B).
- Hesap: $\dfrac{(y^2-1)e^y}{y+1}=(y-1)e^y$. $\displaystyle\int_1^2(y-1)e^y\,dy=e$.

### Soru 8: Alanı veren integral

- Bölge: $y=\ln(1+x)$, $x=0$, $y=2$ ile sınırlı.
- $x=e^y-1$. Bölge: $0\le y\le2$, $0\le x\le e^y-1$.
- Alan: $\displaystyle\int_0^2\int_0^{e^y-1}dx\,dy=e^2-3$.
- Hoca önce sınırı "$e^y-1$'den 0'a" diye okudu, sonra $0$'dan $e^y-1$'e diye düzeltti.

### Soru 9: Halkanın alt yarısının alanı

- $1\le x^2+y^2\le e^2$, $y\le0$.
- $\pi\le\theta\le2\pi$, $1\le r\le e$.
- Alan: $\displaystyle\int_\pi^{2\pi}\int_1^e r\,dr\,d\theta=\frac{\pi(e^2-1)}{2}$.

### Soru 12: Paraboloidin altındaki hacim

- Altyazıda 01:06:10'da bu soru "10. soru" diye geçiyor; numara kesin değil.

- $z=4-x^2-y^2$ ve $z=0$.
- $z=0$ için $x^2+y^2=4$: $0\le r\le2$, $0\le\theta\le2\pi$.
- $V=\displaystyle\int_0^{2\pi}\int_0^2(4-r^2)\,r\,dr\,d\theta$ (b şıkkı).
- Hesap: $2\pi\left(8-4\right)=8\pi$.
- Hoca: şıklar yalnız $r$'nin üst sınırında (1 ya da 2) ayrışıyor. Çemberi doğru bulmak yetiyor.

### Soru 13: Silindir içinde hacim

- Birim silindir $x^2+y^2=1$ ve $z=4$ ile sınırlı bir cisim.
- $0\le\theta\le2\pi$, $0\le r\le1$, yükseklik fonksiyonu kutupsala çevrilir.
- Yüzeylerin tam ifadesi altyazıda net anlaşılmıyor.

### Soru 14: İki silindir arasındaki hacim

- $z=5-y$ düzleminin altında, $z=0$'ın üstünde, $x^2+y^2=1$ ile $x^2+y^2=2$ silindirleri arasında.
- $V=\displaystyle\int_0^{2\pi}\int_1^{\sqrt2}(5-r\sin\theta)\,r\,dr\,d\theta$.
- Hesap: $\sin\theta$ terimi $2\pi$ üzerinde sıfır verir. $V=5\cdot2\pi\cdot\frac{2-1}{2}=5\pi$.

### Soru 15: Kaydırılmış silindir

- $x^2+y^2-4y=0$: $r^2=4r\sin\theta\Rightarrow r=4\sin\theta$.
- $0\le r\le4\sin\theta$, $0\le\theta\le\pi$.
- Hoca: yalnız $r$ sınırını bulmak bile yanlış şıkları eliyor.

### Soru 16: Jacobian ile dönüşüm

- $R$: $x+y=1$, $x+y=3$, $x-y=0$, $x-y=1$. $I=\displaystyle\iint_R\frac{x^2-y^2}{\sqrt{1+(x-y)^2}}\,dA$ (payda altyazıda net değil; büyük olasılıkla bu).
- $u=x-y\in[0,1]$, $v=x+y\in[1,3]$. Yeni bölge dikdörtgen.
- $\dfrac{\partial(u,v)}{\partial(x,y)}=\begin{vmatrix}1&-1\\1&1\end{vmatrix}=2$, $dA=\frac12\,du\,dv$.
- $x^2-y^2=uv$.
- $I=\displaystyle\int_1^3\int_0^1\frac{uv}{\sqrt{1+u^2}}\cdot\frac12\,du\,dv$ (cevap A).
- Hesap: $\frac12\cdot4\cdot(\sqrt2-1)=2(\sqrt2-1)$.
- Hoca: bu tip sorudan en az bir tane kesin geliyor.

### Soru 17: Parabollerle sınırlı bölge

- $y=x^2$, $y=2x^2$, $x=y^2$, $x=3y^2$.
- $u=\dfrac{x^2}{y}\in[\frac12,1]$, $v=\dfrac{y^2}{x}\in[\frac13,1]$.
- $\dfrac{\partial(u,v)}{\partial(x,y)}=\begin{vmatrix}\frac{2x}{y}&-\frac{x^2}{y^2}\\-\frac{y^2}{x^2}&\frac{2y}{x}\end{vmatrix}=4-1=3$, $dA=\frac13\,du\,dv$.
- Alan: $\frac13\cdot\frac12\cdot\frac23=\frac19$.

### Ortalama değer sorusu

- Köşeleri $(0,0)$, $(2,0)$, $(2,2)$ olan üçgende $f(x,y)=x$.
- Alan $=2$. $\displaystyle\iint_D x\,dA=\int_0^2\int_0^x x\,dy\,dx=\int_0^2x^2dx=\frac83$.
- $f_{ort}=\dfrac{8/3}{2}=\dfrac43$.

### Ders sonrası notlar

- Ortalama değer sorusunda hoca önce integrali alanla çarpıp $\frac{16}{3}$ dedi. Sonra düzeltti: alana bölünür, doğru sonuç $\frac43$.
- Soru 14'te hoca $r$'nin sınırını "0'dan $\sqrt2$'ye" dedi. Cisim iki silindir arasında, ortası boş. Doğrusu $1\le r\le\sqrt2$.
- Soru 17'de hoca $u$ ve $v$'nin sınırlarını bir an "2'ye kadar" dedi. Doğrusu $u\in[\frac12,1]$, $v\in[\frac13,1]$. Jacobian 3, $dA=\frac13\,du\,dv$.
- Soru 4'te hoca $y$'nin üst sınırını sözlü olarak "$3y$" gibi okudu. Tahtadaki doğru sınır $\frac x3$.
- Soru 3'te açı aralığı derste "alt yarım çemberin sol kısmı" diye anlatıldı. Doğru aralık $[\pi,\frac{3\pi}{2}]$.
- Sayısal sonuçların çoğu derste söylenmedi. Değerler hesaplanarak eklendi.
- 00:37-01:03 arası mola. Hoca bu arada paralel yürüyen workshop'a katıldı.

## Duyurular

- Bu dersle dönemin konuları bitti. Final test şeklinde. Tarih bu derste verilmedi.
- Final konuları: integral ağırlıklı. Ayrıca kısmi türev, kapalı fonksiyonun türevi, limit-süreklilik, seriler, kutupsal koordinatlar, vektörler ve düzlemler.
- Çözülen sorular dersten sonra asistan tarafından AVES'e yüklenecek.
- Hoca gelecek dönemin yüz yüze olacağını söyledi.

İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
