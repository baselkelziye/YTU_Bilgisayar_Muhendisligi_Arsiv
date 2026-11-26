# Ders 9 Çalışma Özeti

## Genel Konular

- Zaman düzleminden dönüşüm düzlemlerine geçiş
  - Şimdiye kadar sinyaller ve sistemler zaman düzleminde incelendi: sürekli zamanda $t$, ayrık zamanda $n$ düzleminde. Sistemin çıkışı giriş ile birim dürtü cevabının konvolüsyonuyla bulundu.
  - Dersin bundan sonraki kısmı, zaman düzleminde yapılması zor işlemlerin frekans, $s$ ve $z$ düzlemlerinde yapılıp yapılamayacağını inceler (Fourier, Laplace ve z dönüşümleri).
  - Sürekli zamanda konvolüsyonun zorluğu: integralin içinde iki fonksiyonun çarpımı vardır ve integral sınırları sinyallerin kritik noktalarına (süreksizlik noktaları, başlangıç ve bitiş noktaları) göre parçalanmak zorundadır. Bu kritik noktalar iki sinyalin örtüşme miktarını belirler.
- Sistem modelleme ve diferansiyel denklemler
  - Mühendislik tasarımı için bir devrenin ya da sistemin davranışını sayısal olarak öngörebilmek gerekir; bunun için matematik modeller kullanılır (ekrandan, 00:10:00).
  - Devrelerde eleman kuralları ($R$: $v(t)=Ri(t)$, $L$: $v(t)=L\,\frac{di(t)}{dt}$, $C$: $\frac{dv(t)}{dt}=\frac{1}{C}i(t)$) ve devre kuralları (KVL, KCL, gerilim bölücü) bir araya gelince diferansiyel denklem çıkar.
  - Mekanik sistemlerde kütle ($M\frac{d^2p(t)}{dt^2}$), yay ($k_s p(t)$) ve sönümleme ($k_d\frac{dp(t)}{dt}$) kuralları ile kuvvetlerin toplamı yine diferansiyel denkleme götürür. Hidrolik ve kimyasal sistemlerde de durum benzerdir: "differential equations rule the world".
  - Sürekli zamanda (zaman türevli) denkleme diferansiyel denklem, ayrık zamanda ($y[n]$, $y[n-1]$ gibi terimlerle) kurulan denkleme fark denklemi denir.
- Basit devre örneği: iki bilgisayar arasındaki kablo
  - İki iletken bir yalıtkanla ayrıldığında kapasitans oluşur. Burgulu çift kablo için tipik değerler $100\ \Omega/\text{km}$ ve $50\ \text{nF/km}$'dir; koaksiyel kabloda da iletkenler yalıtkanla ayrılır (ekrandan, 00:15:00). Direnç kablo boyuyla artar.
  - Kablo bir RC devresi olarak modellenir. Girişteki 0-1 bit dizisi (0 ve 5 V seviyeleri) çıkışta "yumuşatılmış" bir dalga olarak görünür; çıkış, her geçişte oluşan basamak cevaplarının toplamıdır. Bu yüzden 0 ile 1'i ayırt etmek zorlaşır, gürültü eklenirse daha da zorlaşır (ekrandan, 00:20:00).
- Diferansiyel denklemlerin sınıflandırılması ve çözümü
  - Derece (mertebe): denklemdeki en yüksek türev mertebesidir. Katsayılar sabitse sistem zamanla değişmezdir. Doğrusal/doğrusal olmayan, homojen/homojen olmayan, adi (ordinary)/kısmi (partial) diye sınıflandırma yapılır.
  - İkinci mertebeden sabit katsayılı denklemde karakteristik denklem kurulur, köklere göre çözüm yazılır, başlangıç koşullarıyla $C_1$, $C_2$ bulunur (ekrandan, 00:25:00).
  - Hoca bu kısmın yalnız tanıtım amaçlı anlatıldığını, ayrıntılı çözüm sorulmayacağını söyledi.
- Konvolüsyondan Fourier'e
  - Konvolüsyonun kodlanması iki iç içe döngü ister. Frekans karşılıkları biliniyorsa zaman düzlemindeki konvolüsyon frekans düzleminde doğrudan çarpıma dönüşür: $z(t)=f(t)*x(t)\ \Rightarrow\ Z(\omega)=F(\omega)\,X(\omega)$ (ekrandan, 01:05:00). Ters dönüşümle tekrar zaman düzlemine dönülür.
  - Bu kolaylık sistemlerin kararlılık analizinde, örüntü eşleme (bir görüntüde ya da seste belli bir bölgeyi arama) ve gürültü giderme gibi uygulamalarda işe yarar.
- Fourier işlemlerinin ayrımı
  - Periyodik sinyal: Fourier serisi kullanılır, bir periyodu incelemek yeterlidir.
  - Periyodik olmayan (aperiyodik) sinyal: Fourier dönüşümü kullanılır, $-\infty$'dan $+\infty$'a incelenir.
  - Her ikisi sürekli zaman (CTFS, CTFT) ve ayrık zaman (DTFS, DTFT) için ayrı ayrı tanımlanır.
  - Fourier dönüşümü: $X(\omega)=\int_{-\infty}^{\infty}x(t)\,e^{-j\omega t}\,dt$ (ekrandan, 01:25:00); $\omega=2\pi f$ yazılarak $X(f)$ biçiminde de görülür.
- Euler bağıntısı ve karmaşık sinüzoidler
  - $e^{j\omega_0 t}=\cos\omega_0 t + j\sin\omega_0 t$, $e^{-j\omega_0 t}=\cos\omega_0 t - j\sin\omega_0 t$. Bu ikisi toplanıp çıkarılarak $\cos x=\frac{e^{jx}+e^{-jx}}{2}$ ve $\sin x=\frac{e^{jx}-e^{-jx}}{j2}$ elde edilir (ekrandan, 00:40:00).
  - Doğal sinyaller (sinüs, kosinüs) cinsinden yazılan bir sinyalin frekansı, genliği ve fazı doğrudan okunur.
- Sürekli zaman Fourier serisi (CTFS)
  - Süperpozisyon: doğrusal bir sisteme giriş, bilinen küçük parçalara (sinüzoidlere) ayrılıp her parça ayrı verilirse, çıkışların toplamı aynı sonucu verir. Fourier serisinin çıkış noktası budur.
  - Tanım: $x(t)=\sum_{k=-\infty}^{\infty}c_x[k]\,e^{j2\pi kt/T}$, $c_x[k]=\frac{1}{T}\int_{t_0}^{t_0+T}x(t)\,e^{-j2\pi kt/T}\,dt$ (ekrandan, 00:45:00 ve 01:10:00). $c_x[k]$ harmonik fonksiyon, $k$ harmonik numarasıdır; katsayılar ortogonallik ilkesiyle bulunur.
  - Gerçel değerli $x(t)$ için $c_x[k]=c_x^*[-k]$; harmonik fonksiyonun genliği çift, fazı tek fonksiyondur (ekrandan, 00:50:00).
  - Trigonometrik biçim: $x(t)=a_x[0]+\sum_{k=1}^{\infty}\{a_x[k]\cos(2\pi kt/T)+b_x[k]\sin(2\pi kt/T)\}$, $a_x[k]=\frac{2}{T}\int_{t_0}^{t_0+T}x(t)\cos(2\pi kt/T)\,dt$, $b_x[k]=\frac{2}{T}\int_{t_0}^{t_0+T}x(t)\sin(2\pi kt/T)\,dt$ (ekrandan, 00:55:00).
  - Doğrusallık: $x(t)=x_1(t)+x_2(t)+\dots$ ise $c_x[k]=c_{x1}[k]+c_{x2}[k]+\dots$; bu yalnız bütün bileşenler aynı temsil süresi $T$'ye göre açıldığında geçerlidir (ekrandan, 01:15:00).
- Temel frekans ve genlik-faz biçimi
  - $x(t)=\sum_k A_k\cos(k\omega_0 t+\phi_k)$: tamsayı katlı frekanslara sahip sinüzoidlerin toplamı periyodu $T=2\pi/\omega_0$ olan periyodik bir sinyal verir (ekrandan, 01:30:00).
  - Temel frekans, bileşen frekanslarının en büyük ortak böleni (EBOB) ile bulunur. Örnek: 10, 15, 20 Hz için $f_0=5$ Hz.
  - $k=0$ terimi DC bileşen (DC ofset), yani sinyalin bir periyotluk zaman ortalamasıdır: $a_0=\frac{1}{T}\int_{T}x(t)\,dt$.
  - Biçimler arası geçiş: $c_0=A_0$, $c_{\pm k}=\frac{1}{2}A_k e^{\pm j\theta_k}$, $a_k=A_k\cos\theta_k$, $b_k=-A_k\sin\theta_k$, $A_k=\sqrt{a_k^2+b_k^2}$ (ekrandan, 01:40:00).
- Uygulama: periyodik gürültü
  - Görüntüye ya da sese eklenmiş periyodik bir gürültü frekans düzleminde belirli noktalarda tepe olarak görünür. Bu frekansların katsayıları sıfırlanıp ters dönüşüm yapılırsa gürültü kaybolur (ekrandan, 01:35:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Dönüşümlerin asıl faydası
  - Zor integralleri (özellikle iki fonksiyonun çarpımının integralini ve parçalı sınırları) daha basit, bilinen integrallere çevirmek. Konvolüsyon frekans düzleminde çarpım olur.
- Euler bağıntısını bilmek yeterli
  - $e^{j\omega_0 t}=\cos\omega_0 t+j\sin\omega_0 t$ bilinirse kosinüs ve sinüsün üstel ifadeleri taraf tarafa toplama ve çıkarmayla türetilir.
- Fourier serisi toplamı unutulmamalı
  - $x(t)=\sum_i A_i\cos(2\pi f_i t+\phi_i)$: her sinüzoidin genliği, frekansı ve fazı vardır. Amaç bu üç bilgiyi bulmaktır.
- Temel frekans EBOB ile bulunur
  - Bileşen frekanslarının EBOB'u temel frekansı verir; temel periyot $T_0=2\pi/\omega_0=1/f_0$'dır.
- Konvolüsyon tepe noktası benzerliği gösterir
  - Fourier katsayısı hesabı, sinyalin bir sinüzoidle çarpılıp integralinin alınmasıdır. Sinyal o sinüzoide ne kadar benziyorsa sonuç o kadar büyük olur.
- Diferansiyel denklem çözümü ayrıntısı sorumluluk dışı
  - Diferansiyel denklemlerin sınıflandırma ve çözüm ayrıntıları yalnız tanıtım içindir.

## Kısa Tekrar Notları

- Fourier serisi periyodik sinyaller içindir; Fourier dönüşümü periyodik olmayan sinyaller içindir.
- $c_x[k]=\frac{1}{T}\int_{T}x(t)e^{-j2\pi kt/T}dt$; $x(t)=\sum_k c_x[k]e^{j2\pi kt/T}$.
- Trigonometrik biçimde $a_0$ DC bileşen, $a_k$ kosinüs, $b_k$ sinüs katsayısıdır; $a_k$, $b_k$ formüllerinin önünde $\frac{2}{T}$ vardır.
- Gerçel sinyal için $c_x[k]=c_x^*[-k]$: genlik spektrumu çift, faz spektrumu tektir.
- $\cos x=\frac{e^{jx}+e^{-jx}}{2}$, $\sin x=\frac{e^{jx}-e^{-jx}}{j2}$.
- Temel frekans = bileşen frekanslarının EBOB'u; $T_0=1/f_0$.
- Konvolüsyon zamanda zor, frekansta çarpımdır.
- Devre ve mekanik sistemlerin modelleri diferansiyel denklemdir; ayrık zamanda karşılığı fark denklemidir.

## Detaylı Açıklamalar

- Konvolüsyonun zorluğu ve dönüşümlere geçiş
  - Sürekli zamanda konvolüsyon $\int f(\tau)x(t-\tau)d\tau$ biçimindedir. Fonksiyonlar karmaşıksa integral zorlaşır; ayrıca sinyallerin kritik noktaları yüzünden integral bölgelere ayrılır. Kodlarken de biri $f$'in, öteki $x$'in zaman indisini dolaşan iki döngü gerekir. Hoca, sinyallerin Fourier karşılıkları biliniyorsa konvolüsyonun frekans düzleminde eleman eleman çarpıma dönüştüğünü, sonra ters Fourier dönüşümüyle sonucun zaman düzlemine geri getirildiğini anlattı (ekrandan, 00:30:00 ve 01:05:00). Böylece iki fonksiyonun çarpımının integrali yerine tek fonksiyonun bilinen integrali hesaplanır.
- Sistem modelleme
  - Bir sistemi kullanabilmek için önce giriş-çıkış ilişkisini veren denklem kurulur, sonra bu denklem $y(t)$'yi türevsiz ve integralsiz olarak $x(t)$ cinsinden verecek biçimde çözülür. Çözüm elde edildikten sonra istenen giriş yerine konarak çıkış bulunur ve sistemin doğruluğu test edilir. Kablo örneğinde fiziksel sistem iki bilgisayar arasındaki iletişim kablosudur; bu kablonun davranışını veren devre bir RC devresidir ve denklemi birinci mertebeden bir diferansiyel denklemdir. Otomobil fren sistemi gibi mekanik sistemler daha yüksek mertebeden denklemlerle modellenir.
  - Hoca, Thevenin eşdeğeri ve maksimum güç aktarımı teoremini de hatırlattı: bir devreye bağlanan yükün direnci kaynağın iç direncine eşit olduğunda en yüksek güç aktarılır.
  - Bir öğrencinin "diferansiyel denklemin türevle integral arasındaki yeri nedir" sorusuna hoca, sıradan cebirsel denklemlerin (örneğin $x+y=5$, $2x-3y=-10$; çözüm $x=1$, $y=4$) taraf tarafa toplama gibi bilinen tekniklerle çözüldüğünü, türev içeren denklemlerin ise kendine özgü çözüm teknikleri olduğunu söyledi (ekrandan, 00:15:00). MATLAB gibi araçlar bu denklemleri sembolik olarak da çözebilir.
- Diferansiyel denklem örneği (slayttan)
  - $\frac{d^2y}{dt^2}+3\frac{dy}{dt}+2y=\frac{df}{dt}$ denkleminin sıfır giriş biçimi $\frac{d^2y}{dt^2}+3\frac{dy}{dt}+2y=0$'dır. Karakteristik denklem $\lambda^2+3\lambda+2=0\Rightarrow(\lambda+1)(\lambda+2)=0$; başlangıç koşulları $y(0)=0$, $y'(0)=-5$ (ekrandan, 00:25:00). Çözüm $y(t)=C_1e^{-t}+C_2e^{-2t}$ biçimindedir; koşullardan $C_1=-5$, $C_2=5$ çıkar (derste verilmedi, python ile kontrol edildi).
- Fourier serisinin mantığı
  - Bir sinyale bir sinüzoid eklenerek yaklaşılır; her yeni harmonik eklendikçe hata azalır (kare dalga ve üçgen örnekleri). Katsayı hesabı, sinyalin bir periyot boyunca $e^{-j2\pi kt/T}$ (ya da $\cos$, $\sin$) ile çarpılıp integralinin alınmasıdır. Sinyalin içinde o frekansta bir bileşen varsa çarpımın integrali büyük, yoksa sıfır olur (ortogonallik). Hoca bunu bir müzik tanıma uygulamasını anlatan web sayfasındaki 1 Hz kare dalga animasyonuyla gösterdi (ekrandan, 00:35:00).
  - Konuşma sesinin ("but" kelimesi) de sinüzoid bileşenlerine ayrılıp bu bileşenlerin toplamıyla yeniden üretilebildiği örneği verildi.
- Kare dalga ve DC bileşen
  - Hocanın çizdiği kare dalga $0\le t<2$ aralığında 1, $2\le t<3$ aralığında 0'dır ve periyodu $T=3$'tür (ekrandan, 01:20:00). DC bileşen bir periyottaki alanın periyoda bölümüdür: $a_0=\frac{1}{3}\int_0^2 1\,dt=\frac{2}{3}$ (ara adım eklendi).
- Genlik-faz örneği (slayttan)
  - $x(t)=\cos(t)+0.5\cos(4t+\pi/3)+0.25\cos(8t+\pi/2)$, $\omega_0=1$: $A_1=1,\theta_1=0$; $A_4=0.5,\theta_4=\pi/3$; $A_8=0.25,\theta_8=\pi/2$; diğer $A_k=0$ (ekrandan, 01:40:00).
  - Karmaşık üstel biçim: $c_{\pm1}=0.5$, $c_{\pm4}=0.25e^{\pm j\pi/3}$, $c_{\pm8}=0.125e^{\pm j\pi/2}$.
  - Sinüs-kosinüs biçimi: $x(t)=\cos t+0.25\cos 4t-0.433\sin 4t-0.25\sin 8t$ (python ile kontrol edildi).
- Ders sonrası düzeltmeler
  - Genlik-faz örneğinin slaytında $b_4=0.43$, $b_8=0.25$ ve son satırda $+0.25\sin(8t)$ yazıyor (ekrandan, 01:40:00). $b_k=-A_k\sin\theta_k$ formülüne göre doğrusu $b_4\approx-0.433$, $b_8=-0.25$'tir; çünkü $0.25\cos(8t+\pi/2)=-0.25\sin(8t)$.
  - Hoca $\cos(500t+90^\circ)$ için $2\pi f=500$ yazıp $f=250$ Hz dedi. Doğrusu $f=500/(2\pi)\approx 79.6$ Hz'dir; 250 Hz, $\pi$ unutulunca çıkar.
  - Hoca Fourier serisi için yeniden kurulumun "her zaman %100 olmadığını", dönüşümün ise kayıpsız olduğunu söyledi. Sonlu sayıda terim alındığında ve süreksizlik noktalarında (Gibbs olayı) hata kalır; ancak sonsuz terimli Fourier serisi, sürekli olduğu noktalarda periyodik sinyali tam verir.
  - Hoca Fourier katsayısı hesabını "bir konvolüsyon" diye anlattı. Matematiksel olarak bu, sinyalin karmaşık üstelle iç çarpımıdır (ilinti); konvolüsyondaki gibi katlama yoktur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
