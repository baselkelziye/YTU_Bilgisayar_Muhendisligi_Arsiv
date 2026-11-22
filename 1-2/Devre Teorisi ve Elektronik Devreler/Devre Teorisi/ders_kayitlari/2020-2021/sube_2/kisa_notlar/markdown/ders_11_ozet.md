# Ders 11 Çalışma Özeti

> Kayıt üç parçadır; arşivde parçalar yanlış sırada birleştirildiği için altyazıdaki sıra düzeltildi ve saat damgaları düzeltilmiş altyazıya göredir.

## Genel Konular

- Birinci ve ikinci dereceden devrelerden AC devrelerine geçiş
  - RL ve RC devreleri tek enerji depolayan elemanlı (birinci dereceden) devrelerdir; DC kaynakla beslendiklerinde yaklaşık $5\tau$ sonra sabit (kararlı) bir değere oturur.
  - RLC devrelerinde kondansatör ile bobin enerjiyi birbirine aktarır; geçiş cevabı aşırı sönümlü (overdamped), kritik sönümlü (critically damped) ve az sönümlü (underdamped) olarak üç durumda incelenir. Hangi durumun oluşacağını R, L, C değerlerinden hesaplanan $\alpha$ ve $\omega_0$ belirler.
  - AC (alternatif akım) kaynakla beslenen devrede kaynak değeri sürekli değiştiği için devre sabit bir değere oturmaz; geçişten sonra da aynı frekansta salınmaya devam eder.
  - Bu tür devreleri zaman domeninde diferansiyel denklemle çözmek zordur. Bunun yerine karmaşık sayılara dayanan fazör (phasor) gösterimine geçilir; böylece türevli denklemler cebirsel denklemlere dönüşür.
- Giriş frekansının çıkışa etkisi (ekrandan, 00:11:13)
  - Slayttaki devre: $235\,\Omega$ seri direnç, ardından paralel bağlı $4.7\,\text{nF}$ kondansatör ve $1\,\text{mH}$ bobin; giriş $v_s=\sin(2\pi f t)\,\text{V}$, $f=5\,\text{kHz}$.
  - Osiloskop görüntüsünde giriş ile çıkışın genliği ve fazı farklıdır; frekans değişince çıkış da değişir. DC'de frekans bilgisi yoktur, AC'de ise çıkış doğrudan giriş frekansına bağlıdır.
- Karmaşık sayılar
  - Dikdörtgen (rectangular) biçim: $z=x+jy$, $j=\sqrt{-1}$. $x$ reel kısım, $y$ sanal (imaginary) kısımdır.
  - Polar biçim $z=r\angle\phi$; üstel (exponential) biçim $z=re^{j\phi}$. Fazör gösterimi polar biçimle aynıdır.
  - Yalnız aynı türden büyüklükler toplanıp çıkarılabilir: gerilimle gerilim, akımla akım, empedansla empedans, admitansla admitans (ekrandan, 00:16:13).
  - Eşlenik (conjugate): $a+jb$ sayısının eşleniği $a-jb$ olur.
  - Toplama ve çıkarma dikdörtgen biçimde, çarpma ve bölme polar biçimde kolaydır.
- Dikdörtgen ve polar biçim arasında dönüşüm (ekrandan, 00:26:13)
  - $|z|e^{j\theta}=|z|\cos\theta+j|z|\sin\theta$ olduğu için $a=|z|\cos\theta$ ve $b=|z|\sin\theta$.
  - $|z|=\sqrt{a^2+b^2}$, $\theta=\tan^{-1}(b/a)$.
  - Örnek: $4+3j=5\angle 37^\circ$ ($5e^{j37^\circ}$).
- Çarpma ve bölme
  - Dikdörtgen biçimde bölme (ekrandan, 00:21:13): $\dfrac{a+jb}{c+jd}=\dfrac{(ac+bd)+j(bc-ad)}{c^2+d^2}$.
  - Polar biçimde çarpma (ekrandan, 00:31:13): $z_1z_2=|z_1||z_2|\angle(\theta_1+\theta_2)$. Bölmede genlikler bölünür, açılar çıkarılır.
  - Örnek: $M=3+4j=5\angle53^\circ$, $N=\tfrac{3}{\sqrt2}+\tfrac{3}{\sqrt2}j=3\angle45^\circ$, $MN=15\angle98^\circ$.
- Sinüs dalgasının karakteristikleri
  - Periyot $T$: bir tam çevrimin süresi. $v(t)=5\sin(377t)$ için $T=1/60\,\text{s}=16.7\,\text{ms}$ (ekrandan, 00:41:13).
  - Frekans $f=1/T$: saniyedeki çevrim sayısı (Hz). Frekans artınca periyot kısalır; genlik değişmez.
  - Açısal frekans $\omega=2\pi f=2\pi/T$ (rad/s). $f=60\,\text{Hz}$ için $\omega=377\,\text{rad/s}$. $1\,\text{rad}=57.3^\circ$, $2\pi\,\text{rad}=360^\circ$ (ekrandan, 00:46:13).
  - Tepe genliği $V_p$, tepeden tepeye genlik $V_{pp}=2V_p$. Anlık değer, $t$ anındaki $v(t)$ değeridir.
  - Ortalama değer: saf sinüs için sıfırdır. DC ofset eklenirse dalga dikey yönde kayar ve ortalama sıfırdan farklı olur.
  - RMS değeri (ekrandan, 00:51:13): $V_{RMS}=\sqrt{\tfrac1T\int_0^T v^2(t)\,dt}$; sinüs için $V_{RMS}=\tfrac{\sqrt2}{2}V_p=0.707V_p$; ortalama güç $P_{ave}=V_{RMS}^2/R$. Ölçü aletlerinin çoğu RMS değeri gösterir.
- Faz açısı, önde olma (lead) ve geride olma (lag)
  - Faz açısıyla yalnız aynı frekanstaki sinyaller karşılaştırılabilir.
  - Zaman kaymasından faz bulma (ekrandan, 01:11:13): $\phi=-2\pi\,\Delta t/T$ (radyan) ya da $\phi=-360^\circ\,\Delta t/T$.
  - Kural: $\theta_{\text{seçilen}}-\theta_{ref}>0$ ise seçilen sinyal öndedir (lead), $<0$ ise geridedir (lag).
- Sinüs ve kosinüs dönüşümleri (ekrandan, 01:26:13)
  - $A\sin(\omega t+\phi)=A\cos(\omega t+\phi-90^\circ)$; $A\cos(\omega t+\phi)=A\sin(\omega t+\phi+90^\circ)$.
  - $-A\sin(\omega t+\phi)=A\sin(\omega t+\phi\pm180^\circ)$; $-A\cos(\omega t+\phi)=A\cos(\omega t+\phi\pm180^\circ)$.
  - $\pm360^\circ$ eklemek sinyali değiştirmez.
- Karşılaştırma adımları
  - Frekanslar aynı mı diye bakılır; iki sinyal aynı fonksiyona (sinüs ya da kosinüs) çevrilir; genlikler pozitif yapılır (gerekirse $\pm180^\circ$); sonra faz açıları çıkarılır. Fark $\pm180^\circ$ aralığında tutulur.
- Fazör gösterimi
  - $V_m\cos(\omega t+\theta)=\mathrm{Re}\{V_me^{j\omega t}e^{j\theta}\}\Rightarrow V_m\angle\theta$ (ekrandan, 01:56:13). Önce sinyal kosinüs biçimine getirilir; sonra genlik ve faz açısı fazörü oluşturur.
  - Devredeki bütün kaynakların frekansı aynı olmalıdır; frekans bilgisi ($\omega t$) fazörden atılır ve yalnız L ile C'nin empedansında hesaba katılır.
  - Örnekler (ekrandan, 01:31:13): $3\sin(100t+20^\circ)\,\text{V}\to3\angle-70^\circ\,\text{V}$; $7\sin(350t-100^\circ)\,\text{A}\to7\angle170^\circ\,\text{A}$.
- Tekillik (singularity) fonksiyonları ile dalga biçimleri (önceki konunun tekrarı)
  - İmpuls, birim basamak, darbe (pulse), kare dalga, rampa (üçgen ve testere dişi) fonksiyonları ve bunların birleşimleri (ekrandan, 01:36:13).
  - Darbe: $V_0u(t-t_0)-V_0u(t-t_1)$. Üçgen dalga: $r(t-t_0)-2r(t-t_1)+r(t-t_2)$ biçiminde rampaların toplamı.
  - Sinüs olmayan her periyodik fonksiyon temel frekansın tam katlarındaki sinüslerin (harmoniklerin) toplamı olarak yazılabilir (ekrandan, 01:41:13).
- Sinüzoidal kaynaklı devreler
  - RL devresi: $\dfrac{di}{dt}+\dfrac RL i=\dfrac{V_0}{L}\cos\omega t$ denklemi sonsuza kadar salınan bir çözüm verir: $i(t)=\dfrac{V_0}{\sqrt{R^2+\omega^2L^2}}\cos\!\left(\omega t-\tan^{-1}\tfrac{\omega L}{R}\right)$ (ekrandan, 01:51:13). Çözümde genlik ölçeklenir ve faz kayar.
  - Dirençte akım ile gerilim aynı fazdadır. Bobinde gerilim akımdan $90^\circ$ öndedir, kondansatörde akım gerilimden $90^\circ$ öndedir.
  - Paralel RLC örneği (Example 02) fazörle KCL kullanılarak çözüldü.

## Hocanın Özellikle Vurguladığı Kısımlar

- Faz açısı ile önde ya da geride olma yorumu
  - Hoca bu iki kavramı "kesinlikle, çok iyi öğrenmeniz gereken" parametreler olarak gösterdi; kosinüs biçimine çevirme ve $\pm180^\circ$ ile işaret düzeltme adımlarının üzerinde "burası önemli" diyerek durdu.
- Radyan ve derece karışıklığı
  - $\omega t$ radyan cinsindendir. Hesap makinesi derece modundaysa $\sin(3.77)$ yanlış sonuç verir; önce dereceye çevirmek gerekir ($1\,\text{rad}=57.3^\circ$). Hoca bunun sık yapılan bir hata olduğunu söyledi.
- Sinüsten kosinüse $-90^\circ$, kosinüsten sinüse $+90^\circ$
  - Bunun bilinmesi gerektiğini, çünkü fazöre geçerken sinyallerin kosinüs biçimine getirileceğini vurguladı.
- Fazörden zaman domenine dönüş
  - Hoca bunu araştırma sorusu olarak bıraktı ve "bunu öğreneceğiz" dedi. Konunun kritik olduğunu ve sınavda kesinlikle soru geleceğini, sonraki derste örnek çözüleceğini söyledi.

## Kısa Tekrar Notları

- $z=x+jy=r\angle\phi=re^{j\phi}$, $r=\sqrt{x^2+y^2}$, $\phi=\tan^{-1}(y/x)$.
- Toplama ve çıkarma dikdörtgen biçimde yapılır. Çarpmada genlikler çarpılır, açılar toplanır; bölmede genlikler bölünür, açılar çıkarılır.
- $f=1/T$, $\omega=2\pi f$; $60\,\text{Hz}\leftrightarrow377\,\text{rad/s}$, $T=16.7\,\text{ms}$.
- $V_{RMS}=0.707V_p$, $V_{pp}=2V_p$.
- $\phi=-360^\circ\Delta t/T$; $\theta_{sel}-\theta_{ref}>0$ ise lead.
- $\sin x=\cos(x-90^\circ)$, $\cos x=\sin(x+90^\circ)$, $-\cos x=\cos(x\pm180^\circ)$.
- $6\sin(20t+40^\circ)$ ile $-4\cos(20t+20^\circ)$ karşılaştırılırsa $v_1$, $v_2$'den $110^\circ$ öndedir.
- Fazör: önce kosinüse çevir, sonra $V_m\angle\theta$ yaz; bütün kaynakların frekansı aynı olmalı.
- Empedanslar: $R$, $j\omega L$, $1/(j\omega C)$. Bobinde $v$, $i$'den $90^\circ$ önde; kondansatörde $i$, $v$'den $90^\circ$ önde.

## Detaylı Açıklamalar

- AC analizine neden fazör gerekir: DC kaynaklı RL, RC ve RLC devrelerinde başlangıç ve son durum sabit değerlerdir; geçiş analizi bu iki değer arasında yapılır. Sinüzoidal kaynakta son durum da salınan bir sinyaldir. Diferansiyel denklemi zaman domeninde her an için çözmek zahmetlidir. Hoca bu yüzden "hesaplama uzayını değiştireceğiz" dedi: her sinyal, genliği ve faz açısını taşıyan bir karmaşık sayıyla (fazörle) gösterilir. Frekans bütün devrede aynı olduğu için fazörde yer almaz; yalnız bobin ve kondansatörün empedansına $\omega$ olarak girer. Fazörlere geçtikten sonra Ohm kanunu, KCL ve KVL olağan biçimde uygulanır. Geçiş bölgesi ($5\tau$'ya kadar) yine geçiş analiziyle incelenir; ondan sonraki sinüzoidal sürekli hal fazörle bulunur.
- Polar biçimde çarpma örneği (ekrandan, 00:31:13): $M=3+4j$ için $|M|=5$, $\theta=\tan^{-1}(4/3)=53^\circ$. $N=\tfrac3{\sqrt2}(1+j)$ için $|N|=\sqrt{9/2+9/2}=3$, $\theta=45^\circ$. Çarpım $15\angle98^\circ$ olur (python ile $15\angle98.1^\circ$).
- Polar biçimde bölme örneği (derste sözlü, 00:33:27): Gerilim $-3\sqrt3+j3$ polar biçimde $\sqrt{27+9}=6$ genlikli ve $150^\circ$ açılıdır. Akım fazörü $2\angle60^\circ$ alınırsa bölüm $3\angle90^\circ$ çıkar. <!-- BELİRSİZ: Bu örneğin slaytı karelerde yok. Akım değeri altyazıdaki "6 bölü 2, 3; faz açısı 90" ifadesinden geriye doğru çıkarıldı. -->
- Faz farkının zaman kaymasından hesaplanması (ekrandan, 01:06:13 ve 01:11:13): Üç sinyalin tepe değeri 5 V, periyodu $T=500\,\text{s}$'dir. Referans sinyal $5\sin(\omega t)$, $\omega=2\pi/500=12.6\,\text{mrad/s}$. Sinyal 2 sıfırdan $\Delta t=40\,\text{s}$ geç geçer: $\phi_2=-360^\circ\cdot40/500=-28.8^\circ$ (lag). Sinyal 3 için kayma $480\,\text{s}$ ölçülürse $\phi=-345.6^\circ$ çıkar; buna $360^\circ$ eklenince $+14.4^\circ$ (lead) bulunur. Grafikte aynı anda dikey bir çizgi çekip hangi sinyalin sıfırdan önce geçtiğine bakarak da bu sonuç görülür.
- Sinüs-kosinüs karşılaştırması (ekrandan, 01:16:13): $v_1=6\sin(20t+40^\circ)=6\cos(20t-50^\circ)$ ve $v_2=-4\cos(20t+20^\circ)=4\cos(20t-160^\circ)$. Fark $-50-(-160)=110^\circ>0$ olduğundan $v_1$ öndedir. Sinüs biçimiyle de aynı sonuç çıkar: $v_2=4\sin(20t+20^\circ+90^\circ-180^\circ)=4\sin(20t-70^\circ)$ ve $40-(-70)=110^\circ$.
- $\pm180^\circ$ seçimi: Eksi işareti kaldırırken $+180^\circ$ ya da $-180^\circ$ eklemek aynı sinyali verir. Hoca, karşılaştırılan iki açının farkını $180^\circ$ içinde tutacak işaretin seçilmesini önerdi; aksi halde fark yorumlanması zor bir değere çıkar.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
