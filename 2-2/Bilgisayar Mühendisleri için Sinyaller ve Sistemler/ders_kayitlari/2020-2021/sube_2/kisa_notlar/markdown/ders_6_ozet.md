# Ders 6 Çalışma Özeti

## Genel Konular

- Dersin yeri ve hedefi
  - Sinyaller ve Sistemler dersi; devre teorisi, kalkülüs, elektronik, fizik, lineer cebir ve diferansiyel denklemler gibi derslerin üzerine kurulur. Ardından DSP ve görüntü işleme, daha sonra ileri DSP, ileri görüntü işleme, bilgisayarlı görü, konuşma/ses ve video işleme, makine öğrenmesi, derin öğrenme ve örüntü tanıma gibi konular gelir.
  - Bu dersin hedefi: sinyal ve sistemin ne olduğu, temel özellikleri, sinyallerin bilgisayarda nasıl saklandığı (ses bir dizi, görüntü iki boyutlu bir matris) ve bunların zaman ve frekans domeninde incelenmesidir. Frekans ve fazdan anlam çıkarmak DSP'nin konusudur.
  - Konuların hemen hepsi hem sürekli zamanda (türev, integral, devre) hem ayrık zamanda (fark, toplam, programlama dili) karşılığa sahiptir. Örneğin girişin negatifini alan sistem ayrık zamanda girişi $-1$ ile çarpan bir koddur, sürekli zamanda ise bunu yapan bir devredir.
  - Konvolüsyon, CNN (Convolutional Neural Network) gibi derin öğrenme modellerinin temelidir. Görüntüde konvolüsyon ile yatay, düşey ya da çapraz kenarlar bulunur; kenar, renk (yoğunluk) değişiminin, yani frekans değişiminin olduğu yerdir ve ayırt edici bir özelliktir.
- Bir sinyali birim basamaklar cinsinden yazma
  - Ekrandaki parçalı sabit sinyal (ekrandan, 00:35:00): $[-1,0)$ aralığında 1, $[0,1)$ aralığında 3, $[1,2)$ aralığında 2, $[2,3)$ aralığında 1, diğer yerlerde 0.
  - Çözüm (ekrandan, 00:40:00): $x(t) = u(t+1) + 2u(t) - u(t-1) - u(t-2) - u(t-3)$.
  - Her $u(t-a)$ terimi $t=a$ noktasında sinyale bir basamak ekler ya da çıkarır; katsayı, o noktadaki sıçramanın büyüklüğüdür.
- Çarpıcı (multiplier) sistemin özellikleri: $y(t) = x(t)\cos\omega_0 t$ (ekrandan, 00:45:00)
  - Belleksiz: $y(t)$ yalnız aynı andaki $x(t)$ değerine bağlıdır.
  - Nedensel (causal): çıkış yalnız şimdiki (ve geçmiş) giriş değerlerine bağlıdır.
  - Doğrusal: $x = a_1x_1 + a_2x_2$ için $y = a_1x_1\cos\omega_0t + a_2x_2\cos\omega_0t = a_1y_1 + a_2y_2$ (ekrandan, 00:55:00).
  - Zamanla değişen (time-invariant değil): girişi geciktirince $x(t-T)\cos\omega_0 t$ elde edilir, ama $y(t-T) = x(t-T)\cos\omega_0(t-T)$'dir; ikisi eşit değildir (ekrandan, 01:00:00).
  - Kararlı (BIBO): $x(t)$ sınırlı ve $|\cos\omega_0 t| \le 1$ olduğu için $|y(t)| \le |x(t)|$ olur.
- Doğrusallık testi
  - Toplamsallık (Law of Additivity): $x_1 \to y_1$, $x_2 \to y_2$ ve $x_1+x_2 \to y_3$ ise $y_3 = y_1+y_2$ olmalı.
  - Homojenlik/çarpımsallık (Law of Homogeneity): $x \to y$ ise $c\,x \to c\,y$ olmalı.
  - İki koşul birlikte sağlanırsa sistem doğrusaldır (ekrandan, 01:25:00).
  - $y(t) = x(t)\sin t$ iki koşulu da sağlar, doğrusaldır.
  - $y(t) = 2x(t)+4$ bir doğru denklemidir ama doğrusal sistem değildir; sabit terim yüzünden iki koşul da bozulur. Bu tür sisteme afin (affine) denir (ekrandan, 01:35:00).
- Sistemlerin sınıflandırılmasının amacı
  - Sistem denklemi (matematiksel model, transfer fonksiyonu) çoğunlukla diferansiyel ya da fark denklemi olarak gelir. Çözüm yöntemi denklemin sınıfına göre seçilir. Derste bundan sonra doğrusal ve zamanla değişmeyen (LTI) sistemler incelenecektir.
- Sinyali kaydırılmış dürtülerin toplamı olarak yazma
  - Ayrık zamanda: $x[n] = \sum_{k} x[k]\,\delta[n-k]$. Örnek: $x[-2]=3$, $x[-1]=2$, $x[1]=2$, $x[4]=6$ ise $x[n] = 3\delta[n+2] + 2\delta[n+1] + 2\delta[n-1] + 6\delta[n-4]$.
  - Sürekli zamanda: $x(t) = \int_{-\infty}^{\infty} x(\tau)\,\delta(t-\tau)\,d\tau$.
- Birim dürtü cevabı (impulse response)
  - Doğrusal bir sistemin $h_\tau(t)$ dürtü cevabı, $\tau$ anında uygulanan dürtüye sistemin $t$ anındaki çıkışıdır: $h_\tau = H(\delta_\tau)$ (ekrandan, 01:50:00).
  - Soldaki $t$ belirli bir örnekleme anıdır; sağdaki $t$ bütün gerçel sayılar üzerinde değişir. Belirli bir andaki çıkış genelde girişin tüm dalga biçimine bağlıdır (ekrandan, 02:00:00).
  - Sistem zamanla değişmiyorsa $h_\tau(t) = h(t-\tau)$ olur; dürtü cevabı yalnız ötelenir (ekrandan, 02:05:00).
  - Dürtü cevabı sistemin "röntgeni" gibidir: LTI bir sistemin davranışını tamamen belirler.
- Konvolüsyon integrali
  - LTI sistemin çıkışı giriş ile dürtü cevabının konvolüsyonudur: $y(t) = x(t)*h(t) = \int_{-\infty}^{\infty} x(\tau)\,h(t-\tau)\,d\tau$ (ekrandan, 02:10:00).
  - Frekans/Laplace domeninde aynı ilişki çarpımdır: $Y(\omega)=H(\omega)X(\omega)$, $Y(s)=H(s)X(s)$.
  - Nedensel giriş ve nedensel sistemde integral sınırları $0$ ile $t$ arasına iner.
  - Özellikler: değişme, birleşme, dağılma; türev ve integral özellikleri.
  - Sürekli zamanda konvolüsyon integral, ayrık zamanda toplam (konvolüsyon toplamı) ile yapılır.
- Grafiksel konvolüsyon adımları (ekrandan, 02:20:00)
  - 1) Sinyalleri $\tau$ cinsinden yaz. 2) Birini (genelde kısa olanı) $\tau=0$ etrafında ters çevir. 3) Ters çevrilmiş sinyalin kenarlarını bul. 4) $t$ kadar kaydır; kenarlar $\tau_{L,t} = t+\tau_{L,0}$, $\tau_{R,t} = t+\tau_{R,0}$ olur. 5) Örtüşme bölgelerini belirle. 6) Her bölgede çarpımın integralini al.
- Grafiksel konvolüsyon örneği (ekrandan, 02:25:00 ve 02:30:00)
  - $x(t)$: $[0,2]$ aralığında 2; $h(t)$: $[0,1]$ aralığında 3.
  - $y(t) = 0$ ($t<0$); $6t$ ($0\le t\le1$); $6$ ($1\le t\le2$); $18-6t$ ($2\le t\le3$); $0$ ($t>3$). Sonuç bir yamuktur.
- Analitik konvolüsyon örneği (ekrandan, 02:50:00 ve 02:55:00)
  - $x(t)=u(t)-u(t-3)$, $h(t)=u(t)-u(t-2)$.
  - $y(t) = t\,u(t) - (t-2)\,u(t-2) - (t-3)\,u(t-3) + (t-5)\,u(t-5)$.
- RC devresi örneği (slayttan, sözlü anlatım)
  - Basamak girişli RC devresinde konvolüsyon sonucu $y(t) = \left(1 - e^{-t/RC}\right)u(t)$ bulunur.

## Hocanın Özellikle Vurguladığı Kısımlar

- "Causal" (nedensel) kelimesi "cause" (neden) kelimesinden gelir; "casual" ile karıştırılmamalıdır.
  - Nedensel sistemde çıkış yalnız şimdiki ve geçmiş girişlere bağlıdır. "Dersim olduğu için bilgisayarı açtım" örneğinde neden önce gelir. $y(t)=x(t+1)$ gibi gelecekteki girişe bağlı bir sistem gerçek zamanda kurulamaz, nedensel değildir.
- Sinyal özellikleri ile sistem özellikleri karıştırılmamalıdır.
  - Belleksizlik, nedensellik, doğrusallık, zamanla değişmezlik ve kararlılık sistem özellikleridir.
- Özellik testinde değişken $t$'dir; $x(t)$ ve $y(t)$ yalnız $t$'ye bağlı olduklarını gösteren gösterimlerdir.
  - Zamanla değişmezlik testinde girişteki $t$ yerine $t-T$ konur; çıkışı ötelerken ise $t$'nin geçtiği her yer (örneğin $\cos\omega_0 t$ içindeki $t$ de) değişir. Kilit nokta budur.
- Bir doğru denklemi doğrusal sistem demek değildir.
  - $y=2x+4$ grafikte doğrudur ama sabit terim yüzünden doğrusal değil, afindir.
- Konvolüsyon ve korelasyon bu dersin en önemli konularıdır.
  - DSP ya da derin öğrenmeye geçmeden önce konvolüsyonun mantığı ve algoritması iyi öğrenilmelidir.
- Konvolüsyonda örtüşmenin başladığı ve bittiği yerler integral sınırlarını belirler.
  - Sınırlar dışında integrand sıfırdır; sonsuza giden bir sinyal kaydırılıyorsa sınırlardan biri sonsuz olur.

## Kısa Tekrar Notları

- Parçalı sabit sinyal = sıçrama noktalarında, sıçrama büyüklüğüyle çarpılmış $u(t-a)$ terimlerinin toplamı.
- $y(t)=x(t)\cos\omega_0 t$: belleksiz, nedensel, doğrusal, zamanla değişen, kararlı.
- Doğrusallık = toplamsallık + homojenlik. Biri bozulursa sistem doğrusal değildir.
- $y = 2x+4$ afin, doğrusal değil.
- $x[n]=\sum_k x[k]\,\delta[n-k]$; $x(t)=\int x(\tau)\,\delta(t-\tau)\,d\tau$.
- LTI sistemde $h_\tau(t)=h(t-\tau)$ ve $y(t) = \int_{-\infty}^{\infty} x(\tau)\,h(t-\tau)\,d\tau$.
- Grafiksel konvolüsyon: yaz, ters çevir, kenarları bul, kaydır, bölgeleri belirle, her bölgede integral al.
- İki dikdörtgenin konvolüsyonu: genişlikler farklıysa yamuk (plato), eşitse üçgen (sivri tepe) çıkar.
- Konvolüsyonun en büyük değeri, iki sinyalin en çok benzediği (tam çakıştığı) kaydırma miktarındadır; görüntüde göz bulma gibi uygulamalar bu fikre dayanır.

## Detaylı Açıklamalar

- Ders, dersin müfredattaki yeriyle başladı. Teorik tarafta Z, Laplace ve Fourier dönüşümleri, diferansiyel denklem çözümü ve bir fiziksel sistemin (havuz, araç hızı, devre) denkleminin kurulması gerekir. Bilgisayar mühendisliği açısından ağırlık algoritmik taraftadır: sinyalin nasıl saklandığı, sistem özellikleri ve konvolüsyon gibi işlemlerin mantığı ve algoritması. Görüntü iki boyutlu bir matris, ses bir dizidir; hazır fonksiyonları kullanmak yerine bunların arkasındaki yapıyı bilmek, ileri derslerde (DSP, görüntü işleme, derin öğrenme) iş görmeyi sağlar.
- Birim basamak örneğinde sinyal soldan sağa taranır. $t=-1$'de 1 birim yükselme $u(t+1)$ ile, $t=0$'da 2 birim yükselme $2u(t)$ ile, $t=1$, $t=2$ ve $t=3$'teki 1'er birimlik düşüşler $-u(t-1)$, $-u(t-2)$, $-u(t-3)$ ile verilir. Python ile her aralıkta kontrol edildi: değerler sırasıyla 1, 3, 2, 1, 0 çıkar. Hoca ayrıca sonsuza giden basamakların sınırlı süreli parçaları ifade etmekte zahmetli olduğunu, ileride aynı sinyalin başka temel sinyaller (dürtüler) cinsinden de yazılacağını söyledi. <!-- BELİRSİZ: bu alternatif yazımın ayrıntısı altyazıda net değil (00:42:43). -->
- Çarpıcı sistemde zamanla değişmezlik testi şöyle yapılır: girişe $x(t-T)$ uygulanınca çıkış $y_1(t) = x(t-T)\cos\omega_0 t$ olur; çıkışı ötelemek ise $y(t-T) = x(t-T)\cos\omega_0(t-T)$ verir. Kosinüsün içindeki $t$ de ötelendiği için ikisi farklıdır; sistem zamanla değişir. Kararlılıkta ise kosinüs çarpanı girişi en fazla 1 ile çarptığı için çıkış girişten büyük olamaz.
- Doğrusallık örneğinde $y(t) = x(t)\sin t$ için $x_3 = x_1 + x_2$ verildiğinde $y_3 = (x_1+x_2)\sin t = y_1 + y_2$ olur (toplamsallık) ve $c\,x_1 \to c\,x_1\sin t = c\,y_1$ olur (homojenlik). $y(t)=2x(t)+4$ için ise $c\,x_1 \to 2c\,x_1+4 \neq c(2x_1+4)$ ve $y_1+y_2 = 2(x_1+x_2)+8 \neq 2(x_1+x_2)+4 = y_3$ olur; iki koşul da bozulur.
- Nedensellik için faiz örneği verildi: bankadaki paranın bir sonraki aydaki miktarı, bir önceki aydaki miktara ve sabit faiz oranına bağlıdır; sonucu belirleyen neden geçmişteki değerdir. <!-- BELİRSİZ: faiz örneğinin tam formülü altyazıda net değil (01:02:46). -->
- Dürtü cevabı slaytlarında (ekrandan, 01:50:00 ve 02:05:00) $\delta(t)$ ve $\delta(t-\tau)$ girişlerine karşılık $h(t,0)$ ve $h(t,\tau)$ çıkışları gösterildi. Zamanla değişmeyen sistemde ikinci çıkış birincinin ötelenmiş halidir. Bir sinyal kaydırılmış dürtülerin ağırlıklı toplamı (integrali) olduğu ve sistem doğrusal olduğu için çıkış, kaydırılmış dürtü cevaplarının aynı ağırlıklarla toplamıdır; bu konvolüsyon integralini verir.
- Grafiksel konvolüsyon örneğinde $h(\tau)$ ters çevrilip $h(t-\tau)$ elde edilir; bu dikdörtgen $[t-1, t]$ aralığındadır. $t<0$ iken örtüşme yoktur, $y=0$. $0\le t\le1$ iken örtüşme $[0,t]$'dir: $y = \int_0^t 6\,d\tau = 6t$. $1\le t\le2$ iken kısa dikdörtgen tamamen içeridedir: $y=6$ (plato). $2\le t\le3$ iken örtüşme $[t-1,2]$'dir: $y = 6(3-t) = 18-6t$. $t>3$ iken yine 0'dır. Python ile sayısal konvolüsyonla doğrulandı.
- Konvolüsyonun hareketli gösterimi ve slayttaki "Convolution Example" (ekrandan, 02:35:00 ve 02:45:00) aynı fikri gösterir: ters çevrilen sinyal kaydırıldıkça çarpımın altındaki alan artar, sabit kalır ve azalır. Eşit genişlikli iki dikdörtgende plato yerine sivri bir tepe oluşur. Bu tepe, iki sinyalin en çok benzediği konumu verir.
- Analitik örnekte integral dört terime ayrılır: $\int u(\tau)u(t-\tau)\,d\tau - \int u(\tau)u(t-2-\tau)\,d\tau - \int u(\tau-3)u(t-\tau)\,d\tau + \int u(\tau-3)u(t-2-\tau)\,d\tau$. Her çarpım belirli bir aralıkta 1, dışında 0'dır: $0<\tau<t$ ($t>0$), $0<\tau<t-2$ ($t>2$), $3<\tau<t$ ($t>3$), $3<\tau<t-2$ ($t>5$). Bu integraller sırasıyla $t\,u(t)$, $(t-2)u(t-2)$, $(t-3)u(t-3)$, $(t-5)u(t-5)$ verir. Sonuç python ile doğrulandı; grafiksel çözümde de aynı sonuç $[0,2]$, $[2,3]$, $[3,5]$ aralıkları ve dışı için parçalı olarak elde edilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
