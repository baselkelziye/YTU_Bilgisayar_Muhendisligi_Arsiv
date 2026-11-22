# Ders 6 Çalışma Özeti

## Genel Konular

- Diferansiyel ve fark denklemleriyle tanımlanan sistemlerin tekrarı
  - Sistem, giriş işaretini $T[\cdot]$ dönüşümüyle çıkış işaretine çevirir: $x(t)\to y(t)$ ya da $x[n]\to y[n]$. Konular önce sürekli zamanda, sonra ayrık zamanda işlenir.
  - Ayrık zamanda çıkış; şu anki giriş, geçmiş girişler ve geçmiş çıkışlar cinsinden yazılabilir. Ekrandaki örnek: $y[n]=y[n-2]+y^2[n-1]+\frac{x[n-1]}{2}+x[n]$ (ekrandan, 00:15:00). Böyle sistemler geçmiş örnekleri tutmak için belleğe ihtiyaç duyar.
  - Sürekli zamanda birçok sistem doğrusal sabit katsayılı adi diferansiyel denklemle (LCCODE) tanımlanır: $a_n y^{(n)}(t)+\dots+a_1y'(t)+a_0y(t)=b_m x^{(m)}(t)+\dots+b_1x'(t)+b_0x(t)$. Çözüm için başlangıç koşulları $y^{(n-1)}(0),\dots,y'(0),y(0)$ verilmelidir. $n$ sistemin derecesidir, $a_i,b_i$ sistemin katsayılarıdır (ekrandan, 00:15:00).
  - Özel durumlar: $a_0=1$, $b_0=A$ ve diğer katsayılar sıfırsa $y(t)=Ax(t)$, sistem yalnız genlik ölçekler. $a_0=0$, $a_1=1$, $b_0=1$ ise $y'(t)=x(t)$ olur; çıkış girişin integralidir, sistem integratördür.
  - Ayrık zamanda genel fark denklemi $a_0y[n]+a_1y[n-1]+\dots=b_0x[n]+b_1x[n-1]+\dots$ biçimindedir (ekrandan, 00:20:00). Örnek: $y[n]+3y[n-1]=2x[n]$ denklemi $y[n]=2x[n]-3y[n-1]$ diye yazılır. $y[0]$ için $y[-1]$, $y[-1]$ için $y[-2]$ gerekir; bu yüzden bir başlangıç değeri verilmelidir.
- İmpuls cevabı (dürtü yanıtı)
  - Birim impuls $\delta(t)$ yalnız $t=0$ anında var olan, altındaki alan 1 olan matematiksel bir uyarandır. Gerçekte üretilemez, modelleme için kullanılır.
  - Sistemin birim impulsa verdiği çıkış $h(t)$ impuls cevabıdır. $h(t)$ biliniyorsa sistem karakterize edilmiş olur ve her girişe verilecek cevap bulunabilir (ekrandan, 00:25:00).
  - Nedensel bir sistem uyarandan önce çıkış üretmez; impuls $t=0$'da uygulandığından $t<0$ için çıkış sıfırdır.
- Girişin dikdörtgen darbelerle yaklaşıklanması
  - Sürekli $x(t)$ işareti (tam uyaran, exact excitation), $T_p$ genişliğinde bitişik dikdörtgen darbelerin dizisiyle yaklaşıklanır (yaklaşık uyaran, approximate excitation) (ekrandan, 00:30:00).
  - Temel darbe $\mathrm{rect}(t/T_p)$, $-T_p/2$ ile $T_p/2$ arasında 1 değerini alır. Ortadaki darbe $x(0)\,\mathrm{rect}(t/T_p)$, yanındaki $x(T_p)\,\mathrm{rect}\left(\frac{t-T_p}{T_p}\right)$ olur (ekrandan, 00:40:00).
  - Kapalı form: $x(t)\cong\sum_{n=-\infty}^{\infty}x(nT_p)\,\mathrm{rect}\left(\frac{t-nT_p}{T_p}\right)$. Darbeler birim alanlı yapılırsa: $x(t)\cong\sum_{n}T_p\,x(nT_p)\,\frac{1}{T_p}\mathrm{rect}\left(\frac{t-nT_p}{T_p}\right)$; buradaki $\frac{1}{T_p}\mathrm{rect}(\cdot)$ ötelenmiş birim alanlı darbedir (ekrandan, 00:45:00).
- Birim darbe cevabından impuls cevabına
  - Ötelenmemiş, birim alanlı, $T_p$ genişliğindeki darbeye verilen cevaba birim darbe cevabı (unit pulse response) $h_p(t)$ denir. Doğrusallıktan: $y(t)\cong\sum_{n}T_p\,x(nT_p)\,h_p(t-nT_p)$ (ekrandan, 00:50:00).
  - $T_p\to0$ iken birim darbeler birim impulslara, $h_p(t)$ impuls cevabı $h(t)$'ye dönüşür; uyaran ve cevap kesinleşir.
  - Slayttaki örnekte $T_p=0{,}2$, $0{,}1$ ve $0{,}05$ s için yaklaşık çıkış giderek gerçek çıkışa yaklaşır (ekrandan, 00:55:00 ve 01:20:00). Hoca bunu bir RC devresinin darbeye cevabıyla somutlaştırdı: darbe varken kapasitör dolar, darbe kesilince yavaşça boşalır.
- Konvolüsyon integrali
  - İmpulsun örnekleme özelliğinden $x(t)=\int_{-\infty}^{\infty}x(\tau)\delta(t-\tau)\,d\tau$ yazılır. Sistem LTI ise $x(\tau)\delta(t-\tau)$ girişinin cevabı $x(\tau)h(t-\tau)$ olur; toplamsallıktan $y(t)=\int_{-\infty}^{\infty}x(\tau)h(t-\tau)\,d\tau=x(t)*h(t)$ elde edilir (ekrandan, 01:30:00 ve 01:35:00).
  - Hesap yolu: $\tau$ ana değişkendir. $h(\tau)$ ters çevrilip $h(-\tau)$ yapılır, $t$ kadar kaydırılıp $h(t-\tau)$ elde edilir, $x(\tau)$ ile çarpılır ve çarpımın altındaki alan bulunur. Bu her $t$ için tekrarlanır.
- Grafik konvolüsyon örnekleri
  - $h(t)$: $t=0$'da 2'den $t=1$'de 0'a inen üçgen; $x(t)$: $[-1,1]$ aralığında genliği 2 olan dikdörtgen (ekrandan, 01:40:00). $y(t)$, $t=-1$'de sıfırdan başlar, önce hızlı sonra yavaş artarak $t=0$'da 2'ye ulaşır, $0\le t\le1$ boyunca 2'de kalır, sonra azalarak $t=2$'de sıfıra iner (ekrandan, 01:45:00 ve 01:50:00).
  - $x_1(t)$: $[-0{,}5;0{,}5]$ aralığında genliği 3 olan dikdörtgen; $x_2(t)$: $[0,2]$ aralığında genliği 2 olan dikdörtgen. $x_1*x_2$ bir yamuktur: $-0{,}5$'te 0, $t=0$'da 3, $0{,}5\le t\le1{,}5$ boyunca 6, $2{,}5$'te 0 (ekrandan, 01:55:00 ve 02:00:00).
  - İki üçgen: $x_1(t)$, $[-3,1]$ aralığında, tepesi $t=-1$'de 3; $x_2(t)$, $[-1,1]$ aralığında, tepesi $t=0$'da 1,5 (ekrandan, 02:05:00 ve 02:15:00). Sonuç $[-4,2]$ aralığında, $t=-1$'e göre simetrik, yumuşak bir tepe biçimindedir.
- Konvolüsyonun özellikleri (ekrandan, 02:20:00)
  - $x(t)*A\delta(t-t_0)=A\,x(t-t_0)$; impulsla konvolüsyon işareti impulsun bulunduğu yere öteler ve genliğiyle ölçekler.
  - $g(t)=g_0(t)*\delta(t)$ ise $g(t-t_0)=g_0(t-t_0)*\delta(t)=g_0(t)*\delta(t-t_0)$.
  - $y(t)=x(t)*h(t)$ ise $y'(t)=x'(t)*h(t)=x(t)*h'(t)$ ve $y(at)=|a|\,x(at)*h(at)$.
  - Değişme: $x*y=y*x$. Birleşme: $[x*y]*z=x*[y*z]$. Dağılma: $[x+y]*z=x*z+y*z$.
- Birim üçgen fonksiyonu
  - $\mathrm{tri}(t)=1-|t|$ ($|t|<1$), diğer yerlerde 0. Altındaki alan 1'dir. Birim dikdörtgenin kendisiyle konvolüsyonudur: $\mathrm{tri}(t)=\mathrm{rect}(t)*\mathrm{rect}(t)$ (ekrandan, 02:25:00).
- Sistem bağlantıları ve kararlılık
  - Seri bağlı iki sistemin eşdeğer impuls cevabı $h_1(t)*h_2(t)$, paralel bağlı ve çıkışları toplanan iki sistemin eşdeğer impuls cevabı $h_1(t)+h_2(t)$'dir.
  - Kararlılık şartı: $\int_{-\infty}^{\infty}|h(t)|\,dt<\infty$. Örneğin $e^{-t}u(t)$ bu şartı sağlar; sonsuza kadar sönmeden süren bir $h(t)$ sağlamaz.
- Konvolüsyon ve evrişimli sinir ağları (CNN)
  - Bir öğrenci sorusu üzerine: CNN'deki filtreler ayrık konvolüsyondaki sistem filtresine karşılık gelir. Görüntünün parçaları filtre katsayılarıyla konvolüsyona sokularak kenar, geçiş ya da gradyan gibi öznitelikler çıkarılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- İmpuls cevabı sistemi karakterize eder
  - Sistemin birim impulsa cevabı $h(t)$ biliniyorsa, keyfi bir girişin çıkışı konvolüsyonla bulunur. Bu dersin "sözün özü" konvolüsyon integralidir.
- Konvolüsyonda ikinci fonksiyon ters çevrilip kaydırılır
  - Ana değişken $\tau$'dur. Bir fonksiyon sabit tutulur, diğeri ters çevrilip $-\infty$'dan $+\infty$'a kaydırılır. Her konumda çarpımın altındaki alan o $t$ için çıkış değeridir ("çarp-topla").
  - Değişme özelliği sayesinde hangi fonksiyonun ters çevrileceği sonucu değiştirmez.
- Konvolüsyon her zaman sistem çıkışı değildir
  - Herhangi iki fonksiyonun konvolüsyonu alınabilir. İkinci fonksiyon sistemin impuls cevabıysa sonuç sistemin çıkışı $y(t)$ olur.
- Seri bağlantıda konvolüsyon, paralel bağlantıda toplama
  - Seri bağlı sistemler tek kutuya $h_1*h_2$ ile, paralel bağlı sistemler $h_1+h_2$ ile indirgenir.
- Ayrık konvolüsyon bilgisayar mühendisleri için daha nettir
  - Sürekli konvolüsyondaki fikir ayrık zamanda daha somut hale gelir; CNN'deki filtrelerin temeli budur.

## Kısa Tekrar Notları

- LCCODE: $\sum a_k y^{(k)}(t)=\sum b_k x^{(k)}(t)$; $n$ sistemin derecesi, başlangıç koşulları gerekir.
- Fark denklemi: $\sum a_k y[n-k]=\sum b_k x[n-k]$; $y[n]+3y[n-1]=2x[n]\Rightarrow y[n]=2x[n]-3y[n-1]$.
- $y'(t)=x(t)$ olan sistem integratördür.
- $h(t)$: birim impulsa cevap. Nedensel sistemde $t<0$ için $h(t)=0$.
- $x(t)\cong\sum_n T_p\,x(nT_p)\frac{1}{T_p}\mathrm{rect}\left(\frac{t-nT_p}{T_p}\right)$, $y(t)\cong\sum_n T_p\,x(nT_p)h_p(t-nT_p)$.
- $T_p\to0$: $h_p(t)\to h(t)$, toplam integrale döner.
- $y(t)=x(t)*h(t)=\int_{-\infty}^{\infty}x(\tau)h(t-\tau)\,d\tau$.
- Adımlar: ters çevir, kaydır, çarp, alanı bul, her $t$ için tekrarla.
- $x(t)*A\delta(t-t_0)=Ax(t-t_0)$.
- Değişme, birleşme, dağılma özellikleri geçerlidir.
- $\mathrm{tri}(t)=\mathrm{rect}(t)*\mathrm{rect}(t)$.
- Seri: $h_1*h_2$; paralel: $h_1+h_2$.
- Kararlılık: $\int|h(t)|dt<\infty$.

## Detaylı Açıklamalar

- Ders, önceki derste kalınan sistem özellikleri slaytlarının tekrarıyla başladı. Bir sistemin çıkışı yalnız şu anki girişe bağlı değilse, geçmiş giriş ve çıkış değerlerini tutan bir belleğe ihtiyaç vardır. Sürekli zamanda bu bağıntı türevlerle (diferansiyel denklem), ayrık zamanda gecikmeli örneklerle (fark denklemi) kurulur. Her iki durumda da denklemi çözmek için başlangıç koşulları gerekir. Örneğin $y[n]=2x[n]-3y[n-1]$ denkleminde $y[0]$'ı bulmak için $y[-1]$ bilinmelidir; aksi halde geriye doğru sonsuza kadar gidilir.
- Konvolüsyonun mantığı şudur: sürekli bir işaret, sonsuz dar, ölçeklenmiş ve ötelenmiş impulsların toplamı olarak düşünülebilir. Gerçekte impuls üretilemediği için önce $T_p$ genişliğinde dikdörtgen darbeler kullanılır. Her darbenin genliği, işaretin darbe merkezindeki değeri $x(nT_p)$'dir. Darbeler birim alanlı yapılınca ($1/T_p$ yükseklik) her terimin önüne $T_p$ çarpanı gelir. Sistem doğrusal ve zamanla değişmez olduğundan, her ötelenmiş darbenin cevabı $h_p(t-nT_p)$, aynı katsayıyla ölçeklenip toplanır. $T_p$ sıfıra giderken toplam integrale, $nT_p$ sürekli değişken $\tau$'ya, $T_p$ de $d\tau$'ya dönüşür ve $y(t)=\int x(\tau)h(t-\tau)d\tau$ bulunur.
- Grafik hesapta $\tau$ ekseni üzerinde çalışılır. $h(\tau)$ düşey eksene göre yansıtılır ve $t$ kadar sağa kaydırılır. Örneğin $y(5)$ için $h(5-\tau)$ çizilir ve $x(\tau)$ ile çakışan bölgedeki çarpımın alanı alınır; slayttaki ilk örnekte $t=5$'te çakışma yoktur, $y(5)=0$'dır. Aynı örnekte $t=0$'da çarpımın alanı 2'dir: üçgen tamamen dikdörtgenin içindedir ve alan $2\cdot(2\cdot1/2)=2$ olur. Üçgen dikdörtgene girerken alan önce hızlı sonra yavaş artar, tamamen içerideyken sabit kalır, çıkarken önce hızlı sonra yavaş azalır.
- İkinci örnekte iki dikdörtgenin konvolüsyonu yamuk verir. Dar dikdörtgen (genişlik 1, genlik 3) ters çevrilmiş geniş dikdörtgenin (genişlik 2, genlik 2) içine girerken çakışma alanı doğrusal artar ve tamamen içerideyken $3\cdot2\cdot1=6$ değerinde sabit kalır. Yamuğun yükselen kenarının uzunluğu dar dikdörtgenin genişliği, düz kısmının uzunluğu genişlikler farkı kadardır; toplam süre genişliklerin toplamı olan 3'tür.
- Üçüncü örnekte iki üçgenin konvolüsyonu, parçalı polinomlardan oluşan, $t=-1$'de en büyük değerini alan yumuşak bir tepedir. Sonucun başlangıcı başlangıçların toplamı ($-3+(-1)=-4$), bitişi bitişlerin toplamıdır ($1+1=2$).
- Konvolüsyon özelliklerinden impulsla konvolüsyon özellikle kullanışlıdır: $A\delta(t-t_0)$ ile konvolüsyon, işareti $t_0$ kadar öteler ve $A$ ile ölçekler. Birim üçgenin iki birim dikdörtgenin konvolüsyonu olması da ikinci örneğin özel bir halidir: genişlikler eşit olduğunda yamuğun düz kısmı kaybolur ve üçgen kalır.
- Seri bağlı iki LTI sistemde ilk sistemin çıkışı $x*h_1$, ikincinin çıkışı $(x*h_1)*h_2=x*(h_1*h_2)$ olur; birleşme özelliği sayesinde eşdeğer sistem $h_1*h_2$'dir. Paralel bağlantıda dağılma özelliğinden $x*h_1+x*h_2=x*(h_1+h_2)$ yazılır.
- Kararlılık için $h(t)$'nin mutlak değerinin altındaki toplam alan sonlu olmalıdır. $e^{-t}u(t)$ için bu alan 1'dir; zamanla sönmeyen bir impuls cevabında alan sonsuza gider ve sistem kararsızdır.

- **Ders sonrası not:** İkinci örnekte hoca 6 değerinin "0 ile $-0{,}5$ arasında" alındığını söyledi; ekrandaki sonuç grafiğine ve hesaba göre yamuğun düz kısmı (değer 6) $0{,}5\le t\le1{,}5$ aralığındadır, $t=0$'da değer 3'tür (python ile doğrulandı).
- **Ders sonrası not:** Üçüncü örnekte hoca 4,5 ve 2,25 değerlerini söyledi; bunlar belirli kaydırmalarda çarpım fonksiyonunun tepe değerleridir ($3\cdot1{,}5$ ve $1{,}5\cdot1{,}5$), konvolüsyonun değerleri değildir. Python ile hesaplanan konvolüsyon değerleri: $y(-3)=0{,}375$, $y(-2)=2{,}25$, $y(-1)=3{,}75$ (en büyük değer), $y(0)=2{,}25$, $y(1)=0{,}375$. Hocanın "maksimumuna 6'da ulaştı" sözü bu örnek için geçerli değildir; 6, ikinci örneğin en büyük değeridir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
