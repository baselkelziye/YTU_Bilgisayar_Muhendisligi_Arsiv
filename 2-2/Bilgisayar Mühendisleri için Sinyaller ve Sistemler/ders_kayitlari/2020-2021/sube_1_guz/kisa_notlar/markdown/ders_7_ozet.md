# Ders 7 Çalışma Özeti

## Genel Konular

- Sürekli zamanlı konvolüsyonun kısa tekrarı
  - Sürekli zamanda sistem $x(t)$ girişini $y(t)$ çıkışına dönüştürür; sistemi birim dürtü (impuls) yanıtı $h(t)$ karakterize eder ve çıkış $x(t)$ ile $h(t)$'nin konvolüsyonudur.
  - Sürekli dürtü ok şeklinde gösterilir: yalnız bir anda var olup yok olan, altındaki alanı 1 olan teorik bir işarettir. $-T_0/2$ ile $T_0/2$ arasındaki dikdörtgen darbenin genişliği sıfıra götürülerek elde edilir.
- Ayrık zamanda dürtü ve dürtü yanıtı
  - Ayrık işaret $x[n]$ sürekli işaretin örneklerinden oluşur; zaman yerine tam sayı indis $n$ vardır.
  - Ayrık birim dürtü $\delta[n]$, $n=0$'da genliği 1 olan tek bir örnektir. Sistemin buna verdiği yanıt $h[n]$ (dürtü yanıtı, impulse response) diye adlandırılır.
- Fark denklemleri (ekrandan, 00:15:00)
  - Ayrık zamanlı LTI (doğrusal, zamanla değişmez) sistemler fark denklemleriyle tanımlanır:
    $a_0y[n]+a_1y[n-1]+\dots+a_Ny[n-N]=b_0x[n]+b_1x[n-1]+\dots+b_Mx[n-M]$.
  - Geciken her çıkış ve giriş değeri bir yerde saklanmalıdır; bu yüzden böyle sistemler hafızalıdır.
  - Tahtadaki örnek: $y[n]=y[n-1]+x[n]+\frac{x[n-1]}{2}$ için $a_0=1$, $a_1=-1$ (karşı tarafa geçince), $b_0=1$, $b_1=1/2$ (ekrandan, 00:15:00).
- Dürtü yanıtının biçimi (ekrandan, 00:20:00)
  - Dürtü yalnız $n=0$'da uygulandığı ve sistem nedensel olduğu için $h[n]=0,\ n<0$.
  - $n>0$ için uyarı sıfırdır; fark denkleminin çözümü homojen çözümdür: $h[n]=y_h[n]u[n]$. Homojen ve özel çözüm ayrıntılarına bu derste girilmedi.
- Keyfi bir işaretin dürtülerle yazılması
  - Her ayrık işaret, genliği ölçeklenmiş ve zamanda ötelenmiş dürtülerin toplamıdır: $x[n]=\sum_{k=-\infty}^{\infty}x[k]\,\delta[n-k]$.
  - Tahtadaki örnek: $x[-3]=-1$, $x[-2]=1$, $x[-1]=-0{,}5$, $x[0]=2$, $x[1]=1$, $x[2]=0{,}5$ işareti $x[n]=-\delta[n+3]+\delta[n+2]-0{,}5\,\delta[n+1]+2\delta[n]+\delta[n-1]+0{,}5\,\delta[n-2]$ biçiminde yazılır (ekrandan, 00:35:00).
- Konvolüsyon toplamının türetilmesi (ekrandan, 00:30:00 ve 00:40:00)
  - $\delta[n]\to h[n]$; zamanla değişmezlikten (ötelemeyle değişmezlik) $\delta[n-k]\to h[n-k]$.
  - Doğrusallığın ölçeklenebilirlik (homogeneity) özelliğinden $x[k]\delta[n-k]\to x[k]h[n-k]$; toplamsallık özelliğinden her iki taraf toplanır.
  - Sonuç: $y[n]=\sum_{k=-\infty}^{\infty}x[k]\,h[n-k]=x[n]*h[n]$ (ayrık konvolüsyon). Sürekli karşılığında toplam yerine integral gelir: $y(t)=\int_{-\infty}^{\infty}x(\tau)h(t-\tau)\,d\tau$.
  - Örnek grafik: periyodik görünen bir uyarı ile üstel azalan bir $h[n]$'nin yanıtı (ekrandan, 00:25:00). Uyarı periyodik ya da sonlu olabilir.
- Konvolüsyon toplamı örneği (ekrandan, 00:50:00 ve 00:55:00)
  - $x[n]=2$ ($n=-1,0,1$), $h[0]=1$, $h[1]=2$. $h[m]$ ters çevrilir ($h[-m]$), $h[n-m]$ olarak kaydırılır ve her $n$ için çakışan örnekler çarpılıp toplanır.
  - $y[-1]=2$, $y[0]=6$, $y[1]=6$, $y[2]=4$.
- Konvolüsyonun özellikleri (ekrandan, 01:15:00)
  - $x[n]*A\delta[n-n_0]=Ax[n-n_0]$.
  - $y[n]=x[n]*h[n]$ ise $y[n-n_0]=x[n]*h[n-n_0]=x[n-n_0]*h[n]$.
  - $y[n]-y[n-1]=x[n]*(h[n]-h[n-1])=(x[n]-x[n-1])*h[n]$.
  - Değişme: hangi işaretin sabit tutulup hangisinin ters çevrilip kaydırıldığı sonucu değiştirmez. Dağılma: $(x_1+x_2)*z=x_1*z+x_2*z$.
  - Slaytta ayrıca $y$'deki dürtü genliklerinin toplamının, $x$ ve $h$'deki toplamların çarpımı olduğu yazıyor.
- Kararlılık ve dürtü yanıtı
  - Çıkışın kararlı olması için $\sum_n |h[n]|<\infty$ olmalıdır; bu toplam sonsuza gidiyorsa sistem duran bir çıkış üretmez.
- Sistem bağlantıları (ekrandan, 01:20:00)
  - Kaskat (seri) bağlantı: $y[n]=\{x[n]*h_1[n]\}*h_2[n]=x[n]*(h_1[n]*h_2[n])$; iki dürtü yanıtının konvolüsyonu tek bir eşdeğer sistemdir (birleşme özelliği).
  - Paralel bağlantı: çıkışlar toplanıyorsa eşdeğer dürtü yanıtı $h_1[n]+h_2[n]$'dir.
- Sonlu dizilerde konvolüsyonun uzunluğu ve sınırları (ekrandan, 01:25:00 ve 01:40:00)
  - $L_y=L_x+L_h-1$.
  - $[M_y,\ N_y]=[M_x+M_h,\ N_x+N_h]$ ($M$: ilk sıfırdan farklı indis, $N$: son sıfırdan farklı indis).
- Çözümlü örnek: iki yöntem
  - $x=[1,\ 2,\ 0,\ -1]$ ($n=-1..2$), $h=[3,\ 2,\ 1]$ ($n=0..2$). $L_y=4+3-1=6$, sınırlar $[-1,\ 4]$.
  - 1. yol (formülle): her sıfırdan farklı $x[k]$ için $y_k[n]=x[k]h[n-k]$ çizilir ve hepsi toplanır.
  - 2. yol (kaydırma): $h[-k]$ çizilir, $h[n-k]$ olarak soldan sağa birer adım kaydırılır, her adımda çakışan indislerdeki değerler çarpılıp toplanır.
  - İki yol da $y=[3,\ 8,\ 5,\ -1,\ -2,\ -1]$ ($n=-1..4$) verir (ekrandan, 02:00:00).
- MATLAB ile konvolüsyon (ekrandan, 02:05:00)
  - `n=-1:2; x=[1 2 0 -1]; stem(n,x)` doğru indislerle çizer; yalnız `stem(x)` indisleri 1'den başlatır.
  - `y=conv(x,h)` yalnız genlikleri verir (uzunluk `length(x)+length(h)-1`); başlangıç indisi verilmez, $n_y$ ayrıca hesaplanmalıdır.
- Uygulama alanları
  - Görüntü işlemede iki boyutlu konvolüsyon (bulanıklaştırma, kenar bulma filtreleri) ve evrişimli sinir ağlarındaki (CNN) filtreler aynı mantığa dayanır; o filtreler $h$'nin karşılığıdır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Dürtü yanıtını bilmek yeter
  - LTI bir sistemin dürtü yanıtı biliniyorsa her keyfi giriş için çıkış bulunabilir, çünkü giriş ölçeklenmiş ve ötelenmiş dürtülerden oluşur.
- Uzunluk ve sınır kuralları
  - $L_x+L_h-1$ ve $[M_x+M_h,\ N_x+N_h]$ kuralları "bilinmesi gereken iki özellik" diye vurgulandı; sonucu kontrol etmek için kullanılır.
- Kaydırma yöntemi
  - Tek bir işaret ters çevrilip diğerinin üzerinden kaydırılır; her adımda yalnız aynı indise düşen değerler çarpılıp toplanır. Sürekli konvolüsyondaki "altta kalan alanın" ayrık karşılığıdır.
- İndis bilgisi
  - Programda yalnız diziler verilirse indis kaybolur; başlangıç ve bitiş indisleri ayrıca tutulmalıdır.
- Konvolüsyon soyut ama temel
  - Görüntü işleme ve derin öğrenme gibi bilgisayar mühendisliği alanlarının altyapısında bu konu vardır.

## Kısa Tekrar Notları

- $x[n]=\sum_k x[k]\delta[n-k]$.
- $y[n]=x[n]*h[n]=\sum_k x[k]h[n-k]=\sum_m x[m]h[n-m]$.
- Nedensel sistemde $h[n]=0,\ n<0$.
- $x[n]*A\delta[n-n_0]=Ax[n-n_0]$.
- Kararlılık: $\sum|h[n]|<\infty$.
- Kaskat: $h_1*h_2$; paralel: $h_1+h_2$.
- $L_y=L_x+L_h-1$; $[M_y,N_y]=[M_x+M_h,\ N_x+N_h]$.
- $[1,2,0,-1]_{n=-1}*[3,2,1]_{n=0}=[3,8,5,-1,-2,-1]_{n=-1}$.
- MATLAB `conv` indis vermez; `stem(n,y)` için $n$ elle kurulur.

## Detaylı Açıklamalar

- Konvolüsyon toplamının mantığı
  - Bir LTI sistemi $\delta[n]$ ile uyarıldığında $h[n]$ elde edilir. Sistem zamanla değişmez olduğu için girişteki öteleme çıkışa aynen geçer: $\delta[n-k]\to h[n-k]$. Doğrusal olduğu için girişteki sabit çarpan çıkışa aynen geçer: $x[k]\delta[n-k]\to x[k]h[n-k]$. Buradaki $x[k]$, $x$ işaretinin $k$ indisinde aldığı skaler değerdir. Son olarak toplamsallıkla bütün $k$'lar için toplanır. Sol taraf $x[n]$'nin kendisidir, sağ taraf da çıkıştır: $y[n]=\sum_k x[k]h[n-k]$.
  - Örneğin arka arkaya iki dürtü uygulanırsa, ilk dürtünün azalan yanıtı sürerken ikinci dürtünün yanıtı ona eklenir; çıkış önce yükselir, sonra azalır.
- Slayt örneği
  - $x[n]$ $n=-1,0,1$'de 2, $h[0]=1$, $h[1]=2$. $h[-m]$ $m=-1$'de 2, $m=0$'da 1 değerini alır. $n=-1$ için $h[-1-m]$ yalnız $m=-1$'de $x$ ile çakışır: $2\cdot1=2$. $n=0$ için $m=-1$ ve $m=0$ çakışır: $2\cdot2+2\cdot1=6$. $n=1$ için yine iki çakışma: $6$. $n=2$ için yalnız $m=1$: $2\cdot2=4$ (ekrandan, 00:55:00).
- Tahtadaki örnek, 1. yol
  - $k=-1$: $y_{-1}[n]=x[-1]h[n+1]=1\cdot h[n+1]$, yani $n=-1,0,1$'de $3,2,1$.
  - $k=0$: $y_0[n]=x[0]h[n]=2h[n]$, yani $n=0,1,2$'de $6,4,2$. Hoca önce 2 ile çarpmayı unuttu, bir öğrencinin uyarısıyla düzeltti.
  - $k=1$: $x[1]=0$ olduğu için katkı yoktur, atlanır.
  - $k=2$: $y_2[n]=x[2]h[n-2]=-h[n-2]$, yani $n=2,3,4$'te $-3,-2,-1$.
  - Toplam: $n=-1$: 3; $n=0$: $2+6=8$; $n=1$: $1+4=5$; $n=2$: $2-3=-1$; $n=3$: $-2$; $n=4$: $-1$.
- Tahtadaki örnek, 2. yol (kaydırma)
  - $h[-k]$: $k=-2,-1,0$'da $1,2,3$. $n=-1$: yalnız $k=-1$ çakışır, $1\cdot3=3$. $n=0$: $1\cdot2+2\cdot3=8$. $n=1$: $1\cdot1+2\cdot2+0\cdot3=5$. $n=2$: $2\cdot1+0\cdot2+(-1)\cdot3=-1$. $n=3$: $0\cdot1+(-1)\cdot2=-2$. $n=4$: $(-1)\cdot1=-1$ (ekrandan, 01:50:00 ve 01:55:00).
  - İki yöntemin sonuçları aynıdır. Ödevde istenen, bu ikinci yöntemin bir fonksiyon olarak yazılmasıdır.
- MATLAB'de doğrulama
  - Hoca MATLAB Online'da `n=-1:2`, `x=[1 2 0 -1]`, `stem(n,x)` ile girişi doğru indislerle çizdi; `y=conv(x,h)` ile aynı genlikleri ($3,8,5,-1,-2,-1$) buldu ve $y$'yi $-1$'den $4$'e kadar olan indislerle çizdi (ekrandan, 02:05:00). `help conv` çıktısına göre fonksiyon yalnız uzunluğu `length(a)+length(b)-1` olan vektörü döndürür; başlangıç indisi seçeneği yoktur.
- Ders sonrası notlar
  - Hoca sürekli konvolüsyonu tahtaya $y(t)=\int x(t)h(t-k)\,dk$ diye yazdı (ekrandan, 00:40:00); doğrusu $y(t)=\int_{-\infty}^{\infty}x(\tau)h(t-\tau)\,d\tau$'dur, integral değişkeni girişin içinde de yer almalıdır.
  - Hoca bir yerde "$n=0$'dan önce sistemin çıkışı homojen çıkış" dedi; slayta göre homojen çözüm $n>0$ için geçerlidir, $n<0$'da $h[n]=0$'dır (ekrandan, 00:20:00).
  - Altyazıda MATLAB sonucu "3, 8, 5, -1, -2, -4" diye geçiyor (büyük olasılıkla yazıya dökme hatası); doğrusu son değer $-1$'dir (python ile doğrulandı).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
