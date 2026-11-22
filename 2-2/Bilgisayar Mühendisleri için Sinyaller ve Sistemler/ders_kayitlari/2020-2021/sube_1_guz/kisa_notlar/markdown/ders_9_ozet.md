# Ders 9 Çalışma Özeti

## Genel Konular

- Ders kaynakları ve akış
  - Konvolüsyon tekrarında SaS-05 slaytlarının soru kısmı kullanıldı; Fourier konusuna M. J. Roberts'ın "Continuous-Time Fourier Methods" (Lecture 6) slaytlarıyla geçildi (ekrandan, 00:45:00). Sonunda Schaum serisinin "Signals and Systems" kitabının 5. bölümünden (Fourier Analysis of Time Signals and Systems) özet yapıldı (ekrandan, 02:40:00).
  - Hoca, bazı kitapların LTI sistemlerden sonra önce Laplace ve z dönüşümüne geçtiğini, bu derste ise önce frekans kavramının ve Fourier analizinin işlendiğini söyledi.
- Konvolüsyonun tekrarı
  - LTI sistemde giriş, kaydırılmış ve ölçeklenmiş impulsların toplamı olarak yazılır. Sistemin birim impulsa cevabı $h$ biliniyorsa, doğrusallık (ölçekleme ve toplamsallık) ve zamanla değişmezlik (kaydırma) sayesinde her girişin cevabı bulunabilir.
  - Sürekli zaman: $y(t) = \int_{-\infty}^{\infty} x(\tau)\,h(t-\tau)\,d\tau$. Ayrık zaman: $y[n] = \sum_{m=-\infty}^{\infty} h[m]\,x[n-m]$.
  - Nedensel sistem ($h(t)=0$, $t<0$) ve nedensel giriş ($x(t)=0$, $t<0$) durumlarında integral sınırları daralır; ikisi de nedenselse $y(t) = \int_{0}^{t} x(\tau)h(t-\tau)\,d\tau$ olur (ekrandan, 00:05:00).
  - Grafiksel yöntem: fonksiyonlardan biri sabit tutulur, diğeri ters çevrilir (katlanır) ve kaydırılır; her kaydırmada çarpımın altındaki alan (ayrıkta çarpımların toplamı) hesaplanır. Hangisinin ters çevrildiği fark etmez (değişme özelliği).
- Sürekli konvolüsyon örneği (ekrandan, 00:20:00 ve 00:25:00)
  - $x(t)=2$ ($0 \le t \le 2$), $h(t)=3$ ($0 \le t \le 1$), dışarıda sıfır. $h(t-\tau)$ kaydırılarak beş bölge bulunur.
  - Sonuç: $t<0$ için $0$; $0 \le t \le 1$ için $6t$; $1 < t \le 2$ için $6$; $2 < t \le 3$ için $-6t+18$; $t>3$ için $0$. Çıkış yamuk biçimlidir.
- Ayrık konvolüsyon örneği (ekrandan, 00:30:00 ve 00:40:00)
  - $x[n] = \{2, 2, 1\}$ ($n=0,1,2$), $h[n] = \{3,3,3,3,3\}$ ($n=0,\dots,4$). Kısa dizi olan $x$ ters çevrildi.
  - Sonuç: $y[n] = \{6, 12, 15, 15, 15, 9, 3\}$, $n = 0,\dots,6$; diğer $n$ değerlerinde $0$.
  - Çıkışın başlangıç indisi giriş başlangıçlarının toplamı ($0+0$), bitiş indisi bitişlerin toplamıdır ($2+4=6$).
  - Konvolüsyonun Türkçe karşılığı evrişimdir; evrişimsel sinir ağlarında (CNN) filtre, çekirdek (kernel) ya da maske, aslında bir impuls cevabıdır.
- Zaman uzayından frekans uzayına geçiş
  - Şimdiye kadarki işlemler (konvolüsyon, örnekleme) zaman uzayındaydı. Ayrık işaret de $x[n] = x(nT_s)$ ile zamandan alınan örneklerdir; $T_s = 1/f_s$ örnekleme periyodudur.
  - Konvolüsyon yöntemi girişi impulsların, cevabı impuls cevaplarının doğrusal birleşimi olarak yazar. Fourier serisi ise işareti karmaşık sinüzoitlerin doğrusal birleşimi olarak yazar (ekrandan, 00:50:00).
- Sinüzoitler
  - $A\cos(\omega t + \theta)$: $A$ genlik, $\omega = 2\pi f$ açısal frekans, $\theta$ faz (ekrandan, 00:55:00). Kosinüs ve sinüs birbirinin faz kaymış hâlidir.
  - Periyot $T = 1/f$; periyot azaldıkça frekans artar.
  - $f = 0$ bileşeni sabit (DC) bileşendir ve işaretin ortalamasını verir. Bir işaret DC (ofset) ve AC kısımların toplamı olabilir.
- Karmaşık üstel ve LTI sistem
  - Euler eşitliği: $e^{jx} = \cos x + j\sin x$; $e^{j\omega t}$ karmaşık sinüzoittir.
  - Bir uyarım (excitation) karmaşık sinüzoitlerin toplamıysa, LTI sistemin cevabı da her birinin cevaplarının toplamıdır. Sistem her bileşenin genliğini değiştirir, frekansını değiştirmez (ekrandan, 01:25:00).
- Karmaşık sayılar (ekrandan, 01:30:00)
  - Kartezyen gösterim $z = a + jb$; kutupsal gösterim büyüklük $|z| = r = \sqrt{a^2+b^2}$ ve açı $\theta = \tan^{-1}(b/a)$ ile yapılır.
  - Eşlenik: $z^* = a - jb$; $(e^{jx})^* = e^{-jx}$.
- Gerçel ve karmaşık sinüzoitler (ekrandan, 01:35:00 ve 01:40:00)
  - $e^{j2\pi t}$ ve $e^{-j2\pi t}$, gerçel-sanal-zaman ekseninde ters yönlerde dönen sarmallardır.
  - Kosinüs çift ($\cos(-x) = \cos x$), sinüs tek fonksiyondur ($\sin(-x) = -\sin x$).
  - $\cos x = \dfrac{e^{jx} + e^{-jx}}{2}$, $\sin x = \dfrac{e^{jx} - e^{-jx}}{j2}$.
- Fourier serisinin kavramsal anlatımı (ekrandan, 01:45:00 - 01:55:00)
  - Periyodik bir üçgen dalgaya önce yalnız bir sabitle (ortalama, 0,5), sonra temel frekanslı bir sinüzoitle, sonra temel frekansın tam katlarındaki sinüzoitlerle yaklaşılır. Eklenen her harmonikle yaklaşım iyileşir.
  - Slayttaki örnekte üçüncü sinüzoitin genliği sıfırdır; yani her harmonik işarette bulunmak zorunda değildir.
  - Temel frekans $f_0 = 1/T_0$, işaretin kendini tekrar ettiği en küçük periyoda karşılık gelir.
- Fourier serisi tanımı (ekrandan, 02:00:00)
  - $t_0 < t < t_0+T$ aralığında $x(t) = \sum_{k=-\infty}^{\infty} c_x[k]\, e^{j2\pi k t/T}$.
  - $c_x[k]$ (kısaca $c_k$) harmonik fonksiyon, $k$ harmonik numarasıdır.
- Diklik (ortogonallik) ve katsayıların bulunması (ekrandan, 02:15:00 ve 02:25:00)
  - İç çarpım: $(x_1, x_2) = \int_{t_0}^{t_0+T} x_1(t)\, x_2^*(t)\, dt$. İç çarpım sıfırsa iki fonksiyon o aralıkta diktir.
  - $(e^{j2\pi kt/T}, e^{j2\pi qt/T}) = \int_{t_0}^{t_0+T} e^{j2\pi (k-q)t/T}dt$; $k=q$ ise $T$, $k \ne q$ ise $0$.
  - Buradan $c_x[k] = \dfrac{1}{T}\int_{t_0}^{t_0+T} x(t)\, e^{-j2\pi kt/T}\, dt$ bulunur. $x(t)$ ile $c_x[k]$ bir Fourier serisi çiftidir.
  - $T$ temsil süresidir. $T$, işaretin temel periyoduna eşitse gösterim her zaman geçerlidir; değilse yalnız o aralıkta geçerlidir.
- Gerçel fonksiyonun CTFS'i (ekrandan, 02:30:00)
  - Gerçel değerli $x(t)$ için $c_x[k] = c_x^*[-k]$. Harmonik fonksiyonun büyüklüğü çift, fazı tek fonksiyondur.
- Kitaptaki gösterim (ekrandan, 02:40:00)
  - Periyodik işaret: $x(t+T) = x(t)$; temel periyot $T_0$ bu eşitliği sağlayan en küçük pozitif $T$'dir. $\omega_0 = 2\pi/T_0 = 2\pi f_0$ temel açısal frekanstır.
  - $x(t) = \sum_{k=-\infty}^{\infty} c_k e^{jk\omega_0 t}$, $c_k = \dfrac{1}{T_0}\int_{T_0} x(t)e^{-jk\omega_0 t}dt$. İntegral $[0, T_0]$ ya da $[-T_0/2, T_0/2]$ aralığında alınabilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Konvolüsyonda hangi fonksiyonun ters çevrildiği fark etmez
  - Slayttaki çözüm daha az işlem için kısa diziyi ters çevirmiştir; bu kişisel bir tercihtir, kural değildir.
- Sürekli konvolüsyonda bölge sınırlarına dikkat
  - Sonuç her bölgede ayrı bir ifadedir; $t$'nin hangi aralıkta olduğu doğru yazılmalıdır.
- Konvolüsyon sonucunun sınırları
  - Ayrık durumda çıkışın başlangıç ve bitiş indisleri, girişlerin başlangıç ve bitiş indislerinin toplamıdır.
- Fourier'nin temel fikri
  - Herhangi bir işaret, değişik genlik, frekans ve fazda sonsuz sayıda sinüzoidin toplamı olarak yazılabilir. Bu yüzden impulslar yerine sisteme sinüzoitler (karmaşık üsteller) verilir.
- Temel frekansı yakalamak önemlidir
  - Yaklaşımda kullanılan temel periyot işaretin periyoduyla aynıysa en iyi sonuç alınır; diğer bileşenler temel frekansın tam katlarıdır (harmonikler).
- Sistem frekansı değiştirmez
  - LTI sistem bir karmaşık sinüzoidin frekansını değiştirmez, yalnız katsayısını ($A_k$ yerine $B_k$) değiştirir.
- Negatif ve pozitif frekansların simetrisi
  - Gerçel işaretlerde $c_x[k] = c_x^*[-k]$ olduğu için frekans gösteriminde negatif frekanslar pozitif frekanslarla simetrik çıkar.

## Kısa Tekrar Notları

- $y(t) = \int x(\tau)h(t-\tau)d\tau$, $y[n] = \sum_m h[m]x[n-m]$.
- Grafiksel konvolüsyon: ters çevir, kaydır, çarp, topla (ya da alanı bul).
- $x(t)=2$ ($[0,2]$), $h(t)=3$ ($[0,1]$): $y = 0,\ 6t,\ 6,\ -6t+18,\ 0$.
- $\{2,2,1\} * \{3,3,3,3,3\} = \{6,12,15,15,15,9,3\}$, $n = 0,\dots,6$.
- Konvolüsyon = evrişim; CNN filtreleri birer impuls cevabıdır.
- Sinüzoit: genlik, frekans, faz. $\omega = 2\pi f$, $T = 1/f$.
- $f=0$ bileşeni DC'dir, işaretin ortalamasıdır.
- $e^{jx} = \cos x + j\sin x$; $\cos x = (e^{jx}+e^{-jx})/2$; $\sin x = (e^{jx}-e^{-jx})/(j2)$.
- $z = a+jb$; $|z| = \sqrt{a^2+b^2}$; $\theta = \tan^{-1}(b/a)$; $z^* = a-jb$.
- CTFS: $x(t) = \sum_k c_x[k]e^{j2\pi kt/T}$, $c_x[k] = \frac{1}{T}\int_{t_0}^{t_0+T} x(t)e^{-j2\pi kt/T}dt$.
- Farklı harmonikli karmaşık üsteller periyot aralığında diktir (iç çarpım $0$), aynı harmonik için iç çarpım $T$'dir.
- Gerçel $x(t)$: $c_x[k] = c_x^*[-k]$; büyüklük çift, faz tek.

## Detaylı Açıklamalar

- Konvolüsyonun mantığı
  - Sürekli bir işaret, çok dar impulsların toplamı gibi; ayrık bir işaret ise genlikleri $x[k]$ olan kaydırılmış birim impulsların toplamı, $x[n] = \sum_k x[k]\delta[n-k]$ olarak düşünülür. Sistem LTI olduğunda $\delta[n]$ girişine cevap $h[n]$ ise, $\delta[n-k]$ girişine cevap $h[n-k]$, $x[k]\delta[n-k]$ girişine cevap $x[k]h[n-k]$ olur. Toplamsallıktan dolayı girişleri önce toplayıp sisteme vermek ile ayrı ayrı verip çıkışları toplamak aynı sonucu verir. Bu yüzden çıkış $y[n] = \sum_k x[k]h[n-k]$ olur. Sürekli durumda toplamın yerini integral alır.
- Sürekli konvolüsyon örneğinin çözümü
  - $x(\tau)$ sabit tutulur, $h(t-\tau)$ ters çevrilip kaydırılır. $h(t-\tau)$ yüksekliği 3 olan ve $[t-1, t]$ aralığında duran 1 birim genişliğinde bir darbedir.
  - $t<0$: darbe $x$'e hiç değmez, $y=0$.
  - $0 \le t \le 1$: kesişim $[0,t]$; $y(t) = \int_0^t 2\cdot 3\, d\tau = 6t$. Eğimi 6 olan bir doğru.
  - $1 < t \le 2$: darbe tamamen $[0,2]$ içinde; kesişim 1 birim, $y = 6$.
  - $2 < t \le 3$: kesişim $[t-1, 2]$; $y(t) = 6(3-t) = -6t+18$. Eğimi $-6$ olan bir doğru.
  - $t > 3$: kesişim yok, $y = 0$.
  - Ayrıkta değerler doğrudan çarpılıp toplanırken, süreklide kesişim alanı kaydırmayla sürekli değiştiği için sonuç $6t$ gibi bir fonksiyon olarak çıkar.
- Ayrık konvolüsyon örneğinin çözümü
  - $y[n] = \sum_i h[i]x[n-i]$. $x[-i]$, $x$'in $i$ ekseninde katlanmış hâlidir; $n>0$ sağa kaydırma demektir.
  - $n<0$: örtüşme yok, $y[n]=0$.
  - $n=0$: $3\cdot 2 = 6$.
  - $n=1$: $3\cdot 2 + 3\cdot 2 = 12$.
  - $n=2,3,4$: $3\cdot 1 + 3\cdot 2 + 3\cdot 2 = 15$.
  - $n=5$: $3\cdot 1 + 3\cdot 2 = 9$.
  - $n=6$: $3\cdot 1 = 3$.
  - $n \ge 7$: örtüşme yok, $y[n]=0$.
  - Hoca slayttaki bazı indis etiketlerinin yanlış yazıldığını, örneğin $n=4$ ve $n=5$ adımlarında $x[4-i]$ ve $x[5-i]$ olması gerektiğini belirtti.
  - Python `numpy.convolve([2,2,1],[3,3,3,3,3])` ile sonuç doğrulandı (ajan kontrolü).
- Frekans uzayının gerekçesi
  - Konvolüsyonda girişi impulslara ayırıyorduk. Fourier analizinde ise girişi farklı frekanslardaki sinüzoitlere ayırıyoruz. Sinüzoitler yerine karmaşık sinüzoitler ($e^{j\omega t}$) kullanılır, çünkü hem gerçel hem sanal kısmı tek bir ifadede taşır ve matematiği kolaylaştırır. Gerçek hayattaki işaretlerin bazı frekansları hiç bulunmayabilir; bulunanların genlikleri de farklıdır. Gerçek işaretlerde bir en yüksek frekans da vardır.
- Karmaşık üstelin görselleştirilmesi
  - $e^{j2\pi t}$, $t=0$'da gerçel eksende 1'den başlar; $t$ arttıkça hem gerçel hem sanal bileşen alır ve zaman ekseni boyunca bir sarmal çizer. $e^{-j2\pi t}$ ters yönde döner. İkisi toplanıp 2'ye bölününce sanal kısımlar birbirini götürür ve gerçel düzlemde $\cos(2\pi t)$ kalır. Biri diğerinden çıkarılıp $j2$'ye bölününce $\sin(2\pi t)$ elde edilir.
- Fourier serisi katsayılarının türetilmesi
  - Seri ifadesinin iki tarafı $e^{-j2\pi qt/T}$ ile çarpılıp $[t_0, t_0+T]$ üzerinde integrali alınır. Diklikten dolayı toplamdaki terimlerin hepsi sıfır olur, yalnız $k=q$ terimi $c_x[q]\,T$ verir. Böylece $c_x[q] = \frac{1}{T}\int_{t_0}^{t_0+T} x(t)e^{-j2\pi qt/T}dt$ bulunur. $k \ne q$ için integralin sıfır olmasının nedeni, aralıkta $e^{j2\pi(k-q)t/T}$'nin tam sayıda çevrim yapmasıdır.
- Ders sonrası notlar
  - Hoca frekansı bir anda "bir çevrimin tamamlanma süresi" diye tarif etti; doğrusu: bir çevrimin tamamlanma süresi periyottur ($T$), frekans birim zamandaki çevrim sayısıdır ($f = 1/T$).
  - Hoca $|z|$ için "gücü manasında" dedi; $|z|$ büyüklüktür (genlik). Güç büyük olasılıkla büyüklüğün karesiyle ilgilidir.
  - Hoca bir yerde $T_s$'yi "örnekleme frekansı" dedi, sonra düzeltti: $T_s = 1/f_s$ örnekleme periyodudur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
