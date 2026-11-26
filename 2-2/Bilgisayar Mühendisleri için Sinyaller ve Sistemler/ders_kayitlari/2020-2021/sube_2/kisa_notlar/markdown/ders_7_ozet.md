# Ders 7 Çalışma Özeti

## Genel Konular

- Sürekli zamanda konvolüsyon integralinin tekrarı
  - İki işaretin konvolüsyonu $f(t)=x(t)*y(t)=\int_{-\infty}^{\infty}x(\tau)\,y(t-\tau)\,d\tau$ biçiminde tanımlanır (ekrandan, 00:20:00). Sürekli zamanda konvolüsyon bir integral, ayrık zamanda bir toplamdır.
  - Konvolüsyonun yapılabilmesi için sistemin doğrusal ve zamanla değişmez (LTI, Türkçe kaynaklarda DZD) olması gerekir.
  - İşlem $t$ düzleminden $\tau$ düzlemine geçilerek yapılır: birinci işarette $t$ yerine $\tau$, ikincisinde $t-\tau$ yazılır. İntegralin sonucu yine $t$'ye bağlıdır; $t$ bağımlılığı integralin sınırlarından ve $y(t-\tau)$ teriminden gelir.
  - $\tau$ sembolü, periyot $T$ ile karışmasın diye kullanılır. Benzer biçimde elektrikte akım $i$ ile karışmasın diye karmaşık birim için $j$ kullanılır.
- Analitik örnek: $x(t)=t$, $y(t)=t^2$
  - $f(t)=\int_0^t \tau\,(t-\tau)^2\,d\tau=\frac{t^4}{12}$ bulunur (ekrandan, 00:20:00 ve 00:35:00).
  - Değişme özelliğiyle $f(t)=\int_0^t \tau^2\,(t-\tau)\,d\tau=\frac{t^4}{3}-\frac{t^4}{4}=\frac{t^4}{12}$ aynı sonucu daha kısa yoldan verir (ekrandan, 00:35:00).
  - Aynı örnek MATLAB Online'da `conv` ile örneklenmiş dizilere uygulanıp çizdirildi (ekrandan, 00:30:00).
- Konvolüsyonun yorumu: benzerlik
  - Konvolüsyon, kaydırılan işaretle sabit işaretin çarpımının altındaki alanı hesaplar. Konvolüsyonun en büyük olduğu nokta iki işaretin birbirine en çok benzediği (en çok örtüştüğü) noktadır.
  - Hoca bunu bir konvolüsyon animasyonu sitesindeki üçgen-üstel ve dikdörtgen-dikdörtgen örnekleriyle gösterdi (ekrandan, 00:25:00 ve 01:00:00).
- Konvolüsyon integralinde güçlükler
  - İntegralin içini çözmek her zaman kolay değildir (değişken dönüşümü, kısmi integrasyon, trigonometrik dönüşümler gerekebilir).
  - Süreksizlik noktaları (kare dalga gibi işaretlerdeki ani iniş ve çıkışlar) integralin bölgelere ayrılmasını gerektirir.
- Grafik yöntem: iki birim dikdörtgen darbenin konvolüsyonu
  - $x(t)$ ve $y(t)$, $0\le t\le 1$ aralığında 1, başka yerde 0 olan dikdörtgen darbelerdir (ekrandan, 00:40:00).
  - Adımlar: $y(\tau)$ katlanır ($y(-\tau)$), $t$ kadar ötelenir ($y(t-\tau)=y(-\tau+t)$), $t$'nin değerine göre örtüşme bölgeleri incelenir.
  - Sonuç üçgendir: $t\le 0$ ya da $t\ge 2$ için $0$; $0<t\le 1$ için $t$; $1<t<2$ için $2-t$ (ekrandan, 01:15:00). Tepe $t=1$'de, yani iki darbenin tam örtüştüğü anda oluşur.
- Slayttaki örnek: farklı genlik ve uzunlukta iki darbe
  - $x(\tau)$: $0$–$2$ aralığında genliği 2; $h(\tau)$: $0$–$1$ aralığında genliği 3 (ekrandan, 01:05:00).
  - Katlanıp ötelenmiş $h(t-\tau)$'nun kenarları $\tau_{L}=t-1$ ve $\tau_{R}=t$'dir.
  - Bölgeler: $t<0$ için $0$; $0\le t\le 1$ için $6t$; $1\le t\le 2$ için $6$ (plato); $2\le t\le 3$ için $-6t+18$; $t>3$ için $0$. Hoca bunu bir trenin tünele girip çıkmasına benzetti.
- Konvolüsyonun özellikleri ve sistem bağlantıları
  - Değişme ($x*h=h*x$), birleşme (seri/kaskat sistemlerde sıra değişebilir) ve dağılma (paralel sistemlerde $x*h_1+x*h_2=x*(h_1+h_2)$) özellikleri vardır (ekrandan, 01:40:00).
  - Diferansiyel denklemle tanımlanan bir sistemin modeli birim dürtü cevabıyla elde edilir; çıkış, giriş ile dürtü cevabının konvolüsyonudur.
- Dönüşümlerin faydası
  - Fourier, Laplace ya da z dönüşümü alındığında konvolüsyon çarpmaya dönüşür: $Y(z)=X(z)H(z)$, $Y(\Omega)=X(\Omega)H(\Omega)$ (ekrandan, 01:35:00). Çarpma, konvolüsyondan algoritmik olarak çok daha ucuzdur.
- Ayrık zamanda konvolüsyon toplamı
  - Birim dürtü: $\delta[n]=1$ ($n=0$), $\delta[n]=0$ ($n\ne 0$) (ekrandan, 01:30:00).
  - Her ayrık işaret ölçeklenmiş ve ötelenmiş dürtülerin toplamı olarak yazılabilir: $x[n]=\sum_{k}x[k]\,\delta[n-k]$.
  - Konvolüsyon toplamı: $y[n]=x[n]*h[n]=\sum_{m=-\infty}^{\infty}x[m]\,h[n-m]$ (ekrandan, 01:35:00). Sürekli zamandaki $\tau$ yerine $k$ (ya da $m$), $t$ yerine $n$, integral yerine toplam gelir.
  - Ayrık zamanda integral ve süreksizlik sorunları olmadığı için analitik çözüm daha kolaydır.
- Ayrık grafik konvolüsyon örneği
  - $x[0]=2,\ x[1]=2,\ x[2]=1$; $h[n]=3$ ($n=0,\dots,4$) (ekrandan, 01:40:00).
  - Sonuç: $y[0..6]=6,\,12,\,15,\,15,\,15,\,9,\,3$; $n<0$ ve $n>6$ için $0$ (ekrandan, 01:45:00).
  - Slaytta kısa olan işaret ($x$) katlanır; daha az terimli işareti katlamak işlemi kolaylaştırır.
  - Çıkış önce rampa gibi artar, platoya ulaşır, sonra azalır.
- İkinci ayrık örnek
  - $x[-1]=x[0]=x[1]=2$; $h[0]=1,\ h[1]=2$ (ekrandan, 01:55:00). Sonuç: $y[-1..2]=2,\,6,\,6,\,4$.
- Fark denklemleri ve dürtü cevabı
  - Sürekli zamanda sistemler diferansiyel denklemle, ayrık zamanda fark (difference) denklemiyle tanımlanır.
  - Slayt örneği: $3h[n]+2h[n-1]+h[n-2]=\delta[n]$; $h[0]=1/3$, $h[1]=-2/9$ (ekrandan, 01:50:00). Fark denklemleri z dönüşümüyle cebirsel işlemlere indirgenir.
  - Dürtü cevabı sistemin "röntgenini çeker"; radar sinyalleri de bir anlamda konvolüsyondur.
- Konvolüsyon ve polinom çarpması
  - Ayrık konvolüsyon, katsayı dizilerinin polinom çarpmasıdır. Örnek: $(x^2+3x)(x^7+x^3)=x^9+3x^8+x^5+3x^4$ (ekrandan, 02:00:00 ve 02:05:00).
- MATLAB'de ayrık işaret çizimi
  - `stem(T,x)` ayrık, `plot(T,x)` sürekli gibi görünen çizim verir; `conv` hazır konvolüsyon fonksiyonudur. `help`/`doc` ile örnekli belgelere ulaşılır (ekrandan, 02:10:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Konvolüsyonun ön koşulu
  - Konvolüsyon yalnız doğrusal ve zamanla değişmez sistemlerde kullanılır; bu iki koşul önceki derste ayrıntılı işlendi.
- En yüksek değer = en çok benzerlik
  - Konvolüsyonun tepe noktası iki işaretin en çok örtüştüğü yeri gösterir. İki boyutlu konvolüsyonda bir yüz görüntüsünde göz aramak ya da raf görüntüsünde ürün logosu bulmak bu fikre dayanır.
- Sınırların doğru seçilmesi
  - Örtüşmeyen bölgelerde sonuç doğrudan sıfırdır. Örtüşen bölgede integralin sınırları kaydırılan işaretin kenarlarına ($t-1$, $t$) ve sabit işaretin sınırlarına göre seçilir; gereksiz geniş sınır alınırsa integral yeniden bölünmek zorunda kalır.
- Hangi işaret katlanmalı
  - Değişme özelliği sayesinde iki işaretten herhangi biri katlanabilir; daha kısa ya da daha basit olanı katlamak işlemi azaltır. $x(t)=t$, $y(t)=t^2$ örneğinde $t^2$ yerine $t$'yi kaydırmak integrali kısaltır.
- Dönüşümler ne işe yarar
  - Dönüşüm düzleminde konvolüsyon yerine doğrudan çarpma yapılır. Konvolüsyon iç içe iki döngü gerektirir; bu yüzden daha maliyetlidir.
- Eski ders notlarındaki hata
  - Bazı eski notlarda "causal" (nedensel) sözcüğü yanlış yazılmış; "because" sözcüğünden hatırlanabilir.

## Kısa Tekrar Notları

- $x(t)*y(t)=\int_{-\infty}^{\infty}x(\tau)y(t-\tau)d\tau$; $x[n]*h[n]=\sum_m x[m]h[n-m]$.
- Adımlar: $\tau$ düzlemine geç, bir işareti katla, $t$ kadar ötele, örtüşme bölgelerine ayır, her bölgede çarpıp integralle/topla, sonuçları parçalı fonksiyon olarak birleştir.
- $t * t^2=t^4/12$ ($0$'dan $t$'ye).
- İki birim dikdörtgenin konvolüsyonu: $0$–$2$ arasında, tepesi $t=1$'de olan üçgen.
- Genliği 2 ve uzunluğu 2 olan darbe ile genliği 3 ve uzunluğu 1 olan darbe: $0,\ 6t,\ 6,\ 18-6t,\ 0$.
- Ayrık örnek: $[2,2,1]*[3,3,3,3,3]=[6,12,15,15,15,9,3]$.
- $[2,2,2]$ ($n=-1$'den başlayarak) $*\ [1,2]=[2,6,6,4]$ ($n=-1$'den başlayarak).
- Sonuç uzunluğu: $N+M-1$.
- Konvolüsyonun tepe noktası en büyük benzerliği gösterir.
- Dönüşüm düzleminde konvolüsyon çarpmaya dönüşür.
- Ayrık konvolüsyon = polinom katsayılarının çarpımı.

## Detaylı Açıklamalar

- **Konvolüsyon integralinin kuruluşu.** Ders, önceki haftada başlanan sürekli zamanlı konvolüsyonun kısa bir tekrarıyla açıldı. İki zaman fonksiyonunun konvolüsyonu için önce yeni bir $\tau$ eksenine geçilir. Birinci fonksiyon $x(\tau)$ olarak aynen taşınır, ikincisi $y(t-\tau)$ olarak yazılır. $\tau$'ya göre alınan belirli integralin sınırları $t$'ye bağlı olduğu için sonuç yine $t$'nin fonksiyonudur. Hoca $\tau$ sembolünün periyot $T$ ile karışmasın diye seçildiğini, aynı nedenle elektrikte karmaşık birimin $i$ yerine $j$ ile gösterildiğini anlattı.

- **$x(t)=t$, $y(t)=t^2$ örneği.** İntegral $\int_0^t \tau(t-\tau)^2 d\tau$ olarak kuruldu. Kare açılınca $\tau^3-2t\tau^2+t^2\tau$ elde edilir; terim terim integralle $\frac{t^4}{4}-\frac{2t^4}{3}+\frac{t^4}{2}$ bulunur. Payda 12'de toplanınca $\frac{3-8+6}{12}t^4=\frac{t^4}{12}$ olur (ekrandan, 00:25:00). Hoca ara adımda bir an $-2t^4/12$ dedi, sonra sonucu $t^4/12$ olarak düzeltti. Değişme özelliğiyle $t$ yerine kaydırılmış olanı birinci fonksiyon yapmak işlemi kısaltır: $\int_0^t\tau^2(t-\tau)d\tau=t\cdot\frac{t^3}{3}-\frac{t^4}{4}=\frac{t^4}{12}$ (ekrandan, 00:35:00). Sonuç, $y(t)=t^2$ davranışındaki bir sisteme $x(t)=t$ girişi verildiğinde alınacak çıkış olarak yorumlandı.

- **MATLAB ile deneme.** MATLAB Online'da örneklenmiş bir zaman vektörü, $X=t$ ve $Y=t^2$ dizileri oluşturuldu; `C=conv(X,Y)` ile konvolüsyon alındı ve `plot(X)`, `hold on`, `plot(Y,'r')`, `plot(C,'g')` ile çizdirildi (ekrandan, 00:30:00). Çalışma alanında $X$ ve $Y$ 901, $C$ 1801 elemanlıdır. Ardından $t^4/12$ eğrisi de çizildi; hoca iki eğrinin farklı göründüğünü, bunun MATLAB'in ayrık konvolüsyonuyla ilgili olduğunu ve konuya ayrık zamanda döneceğini söyledi.
  - **Ders sonrası not:** `conv` örnekleri doğrudan çarpıp toplar; integrale yaklaşmak için sonucun örnekleme adımıyla ($dt$) çarpılması gerekir. Ayrıca örneklenmiş vektör sıfırdan başlamıyorsa analitik $t^4/12$ ile birebir örtüşmez. Farkın nedeni büyük olasılıkla budur.

- **Süreksiz işaretler ve bölgeler.** Sürekli işaretlerde (ör. $t$, $t^2$) integral tek parçada alınabilir. Kare dalga gibi süreksizlik noktası olan işaretlerde integral, örtüşme bölgelerine göre parçalanmalıdır. Örtüşme olmayan bölgelerde bir çarpanın sıfır olması nedeniyle sonuç sıfırdır.

- **İki birim dikdörtgenin konvolüsyonu.** $y(\tau)$ önce $\tau=0$ eksenine göre katlanır, sonra $t$ kadar ötelenir: $y(t-\tau)=y(-\tau+t)$. $t\le 0$ iken katlanmış darbe tamamen negatif tarafta kalır, $x(\tau)$ ile ortak noktası yoktur, sonuç 0'dır. $0<t\le 1$ iken örtüşme $[0,t]$ aralığındadır: $f(t)=\int_0^t 1\cdot 1\,d\tau=t$. Hoca önce sınırı $0$–$1$ yazdı, sonra doğru sınırın $0$–$t$ olduğunu belirterek düzeltti. $1<t<2$ iken örtüşme $[t-1,1]$ aralığındadır: $f(t)=1-(t-1)=2-t$. $t\ge 2$ için yine sıfırdır (ekrandan, 01:15:00). Sınır noktalarının ($t=0,1,2$) hangi bölgeye dahil edildiği sonucu değiştirmez. Grafik $t=1$'de tepe yapan bir üçgendir; tepe, iki darbenin yüzde yüz örtüştüğü andır.

- **Slayttaki genelleştirilmiş örnek.** $x(\tau)=2$ ($0\le\tau\le 2$), $h(\tau)=3$ ($0\le\tau\le 1$) için katlanmış ve ötelenmiş $h(t-\tau)$'nun sol kenarı $t-1$, sağ kenarı $t$'dir (ekrandan, 01:05:00). Bölge I ($t<0$): örtüşme yok, 0. Bölge II ($0\le t\le 1$): kısmi örtüşme, $\int_0^t 2\cdot 3\,d\tau=6t$. Bölge III ($1\le t\le 2$): tam örtüşme, $6$ sabit (plato). Bölge IV ($2\le t\le 3$): darbe çıkmaya başlar, $-6t+18$. Bölge V ($t>3$): 0. Hoca bunu tünele giren, içinde ilerleyen ve tünelden çıkan bir trene benzetti. Slayt dizisinde ayrıca $y(t)$'nin $t=-1$ ile $t=2$ arasında yükselen, platoya ulaşan ve inen bir eğri olduğu başka bir grafik örnek de gösterildi (ekrandan, 01:10:00).

- **Sistem modeli ve dürtü cevabı.** Bir sistem, örneğin $y'(t)+3y(t)=x(t)$ gibi bir diferansiyel denklemle tanımlanabilir. Sisteme birim dürtü uygulanınca elde edilen dürtü cevabı sistemin modelidir; herhangi bir girişin çıkışı bu modelle konvolüsyondan bulunur. Hoca RC devresine birim basamak (DC) giriş uygulanması örneğine slayttan kısaca değindi ve diferansiyel denklem çözümünü bu derste anlatmayacağını söyledi.

- **Ayrık zamanlı işaretin dürtülerle yazılması.** Bir ayrık işaret, her örneğin değeri kadar ölçeklenmiş ve o örneğin konumuna ötelenmiş dürtülerin toplamıdır: $x[n]=\sum_k x[k]\delta[n-k]$. Örneğin $x[-1]=2$ ise bu terim $2\delta[n+1]$'dir (ekrandan, 01:30:00). Bir öğrencinin uyarısıyla toplamın içindeki katsayının $x[k]$ olduğu netleşti. <!-- BELİRSİZ: Tahtadaki örnek dizinin n=0 değerinin 3 olup olmadığı karede ve altyazıda net değil. -->

- **Ayrık konvolüsyon adımları.** İki diziden biri katlanır ($h[-i]$ ya da $x[-i]$), her $n$ için $n$ kadar ötelenir, örtüşen örnekler karşılıklı çarpılıp toplanır ve sonuç $y[n]$ olarak yazılır. Negatif $n$ sola, pozitif $n$ sağa öteleme demektir (ekrandan, 01:45:00). Slayt örneğinde $x[n]=\{2,2,1\}$ ($n=0,1,2$), $h[n]=3$ ($n=0..4$) için $n=0$'da yalnız bir örtüşme vardır: $y[0]=2\cdot 3=6$ (ekrandan, 00:05:00). $n=1$'de iki örtüşme: $12$; $n=2,3,4$'te üç örtüşme: $15$; $n=5$'te $3\cdot 1+3\cdot 2=9$; $n=6$'da $3$. Sonuç $\{6,12,15,15,15,9,3\}$'tür.

- **Dönüşümlerle bağlantı.** Slayttaki konvolüsyon özelliğine göre $y[n]=\mathcal{Z}^{-1}\{X(z)H(z)\}=\mathrm{DTFT}^{-1}\{X(\Omega)H(\Omega)\}=x[n]*h[n]$ (ekrandan, 01:35:00). Hoca, dürtü cevabının da z dönüşümleri çarpılıp ters dönüşüm alınarak bulunabileceğini, bu konulara ileride frekans düzleminde geçileceğini söyledi.

- **Fark denklemi örneği.** $3h[n]+2h[n-1]+h[n-2]=\delta[n]$ denkleminde başlangıçta $h[-1]=h[-2]=0$ alınır: $h[0]=1/3$, $3h[1]+2\cdot\frac13=0\Rightarrow h[1]=-2/9$ (ekrandan, 01:50:00). Slaytta homojen çözümün karmaşık kökleri $-0{,}333\pm j0{,}4714$ ve katsayıları $K_{1,2}=0{,}1665\pm j0{,}1181$ olarak verilmiştir. Hoca bu kısmın ayrıntısına girmedi; fark denklemlerinin z dönüşümüyle kolaylaştığını söyledi.

- **Polinom çarpması olarak konvolüsyon.** $(x^2+3x)$ katsayıları $[1,3]$, $(x^7+x^3)$ katsayıları $[1,0,0,0,1]$ olarak yazılır. Bu dizilerin konvolüsyonu $[1,3,0,0,1,3]$'tür; yani $x^9+3x^8+x^5+3x^4$ (ekrandan, 02:05:00). Hoca örneği önce $(x^7-x^3)$ ile yazdı, bir öğrencinin sorusu üzerine işareti artı yaptı.
  - **Ders sonrası not:** Hoca katlama ile yaptığı adımları tam oturtamadığını söyledi. Doğrusu: eksi işaretli haliyle $(x^2+3x)(x^7-x^3)=x^9+3x^8-x^5-3x^4$, artı işaretli haliyle $x^9+3x^8+x^5+3x^4$'tür (python ile doğrulandı).

- **MATLAB'de ayrık çizim.** `T=1:10`, `x=2*T` gibi bir dizi `stem(T,x)` ile ayrık, `plot(T,x)` ile sürekli gibi çizilir (ekrandan, 02:10:00). Hoca hazır `conv` fonksiyonunun belgelerine `help`/`doc` ile ulaşmayı gösterdi ve MATLAB ile Python'un her ikisinin de akademide kullanıldığını söyledi.

- **Önerilen kaynaklar.** MIT'nin Signals and Systems ders notları ve video dersleri ile M. J. Roberts'ın slaytlarının 5. bölümü bu haftanın konusunu içerir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
