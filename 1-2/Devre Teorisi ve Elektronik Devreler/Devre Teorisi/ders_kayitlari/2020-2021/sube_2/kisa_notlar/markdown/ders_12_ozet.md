# Ders 12 Çalışma Özeti

## Genel Konular

- AC devrelerde Ohm kanunu ve gösterim
  - DC analizde gerilim ve akım büyük harfle ($V$, $I$) yazılır, zamana bağlı değildir. AC analizde zamana bağlı büyüklükler küçük harfle ($v(t)$, $i(t)$) yazılır.
  - Direnç için $v(t) = R\,i(t) = R I_m\cos(\omega t + \theta)$, fazör olarak $\mathbf{V} = R I_m\angle\theta = R\mathbf{I}$ (ekrandan, 00:10:00). Dirençte gerilim ve akım aynı fazdadır.
  - Fazör gösterime geçmenin amacı $t$ değişkeninden kurtulmak ve çarpma/bölmeyi kolaylaştırmaktır.
- Kondansatörde faz kayması ve empedans
  - $v(t) = V_m\cos\omega t$ için $i(t) = C\,dv/dt = -\omega C V_m\sin\omega t = \omega C V_m\cos(\omega t + 90^\circ)$ (ekrandan, 00:15:00). Akım gerilimden $90^\circ$ öndedir; frekans değişmez.
  - Fazörde $\mathbf{V} = V_m\angle 0^\circ$, $\mathbf{I} = j\omega C\mathbf{V}$, yani $\mathbf{V} = \dfrac{1}{j\omega C}\mathbf{I} = -\dfrac{j}{\omega C}\mathbf{I}$ (ekrandan, 00:20:00).
- Bobinde faz kayması ve empedans
  - $i(t) = I_m\cos\omega t$ için $v = L\,di/dt$ türevinden gerilim akımdan $90^\circ$ önde çıkar. Bobin empedansı $j\omega L$'dir.
- Empedans ($Z$)
  - $\mathbf{V} = \mathbf{I}\mathbf{Z}$; DC'deki $V = IR$'nin AC karşılığıdır. Birimi ohm'dur.
  - $Z_R = R = R\angle 0^\circ$, $Z_L = j\omega L = \omega L\angle 90^\circ$, $Z_C = -j/(\omega C) = (1/\omega C)\angle -90^\circ$.
  - Genel bileşen: $\mathbf{Z} = R + jX = |Z|\angle\phi$, $|Z| = \sqrt{R^2+X^2}$, $\phi = \tan^{-1}(X/R)$, $R = |Z|\cos\phi$, $X = |Z|\sin\phi$ (ekrandan, 00:35:00). Gerçel kısım dirençlerden, sanal kısım bobin ve kondansatörden gelir.
- Admitans ($Y$)
  - $\mathbf{I} = \mathbf{Y}\mathbf{V}$, $\mathbf{Y} = 1/\mathbf{Z}$; birimi $\Omega^{-1}$ (ekrandan, 00:30:00).
  - $Y_R = 1/R = G\angle 0^\circ$, $Y_C = j\omega C = \omega C\angle 90^\circ$, $Y_L = -j/(\omega L) = (1/\omega L)\angle -90^\circ$.
- KVL, KCL ve eşdeğer empedans
  - Seri devrede: $V_1 + V_2 - V_s = 0$, $V_1 = IZ_1$, $V_2 = IZ_2$, $I(Z_1+Z_2) = V_s$ (ekrandan, 00:40:00). Seri empedanslar toplanır.
  - Paralel devrede: $I = I_1 + I_2$, $I_k = V/Z_k$; paralel empedanslar ters toplamla birleşir. Admitansta tersi geçerlidir: paralel admitanslar toplanır, seri admitanslar ters toplamla birleşir.
  - Gerilim bölücü: $V_2 = V_s\dfrac{Z_2}{Z_1+Z_2}$, $V_1 = V_s\dfrac{Z_1}{Z_1+Z_2}$; akım bölücü de dirençteki gibi kurulur.
- Öncelik/gecikme (leading/lagging)
  - Gerilim ve akım fazörlerinin açıları karşılaştırılır; açısı daha pozitif olan öndedir.
- Thevenin, Norton ve kaynak dönüşümü
  - DC'deki yöntemlerin hepsi aynen geçerlidir; tek ön işlem bütün elemanları empedansa çevirip fazör biçiminde çalışmaktır.
- Örnekler (ekrandan): seri RL (Örnek 03), paralel RCL ve admitans (Örnek 04), kaynak dönüşümlü Thevenin (Örnek 05), paralel RLC'de KCL (Örnek 02, önceki haftadan).

## Hocanın Özellikle Vurguladığı Kısımlar

- Empedans konusu önemlidir
  - Empedans, zaman domenindeki analizden kurtarır; bobin, kondansatör ve direnç aynı "dilden" konuşan devre elemanları gibi işlenir.
- Seri devrede empedans, paralel devrede admitans
  - Seri bağlarda empedansları doğrudan toplamak kolaydır. Paralel bağlarda admitansları toplayıp sonunda tersini almak, paydaları eşitlemekten çok daha kolaydır.
- Sık yapılan karışıklıklar
  - Kim kimin önünde: "V leads I" ya da "I lags V" yorumu açıyla yapılır; açısı daha pozitif olan öndedir.
  - Formüller karıştırılmamalı: $Z_C = -j/(\omega C)$, $Z_L = j\omega L$; admitansta roller yer değiştirir.
- Sinüs kaynağı önce kosinüse çevrilir
  - $\sin(\omega t + \theta) = \cos(\omega t + \theta - 90^\circ)$; fazöre kosinüsten geçmek daha kolaydır.
- Çarpma ve bölme fazör (kutupsal) biçimde yapılır
  - Bölmede genlikler bölünür, açılar çıkarılır; toplama için dik (rectangular) biçime geçmek gerekir.

## Kısa Tekrar Notları

- $Z_R = R$, $Z_L = j\omega L$, $Z_C = -j/(\omega C) = 1/(j\omega C)$.
- $Y = 1/Z$; $Y_R = G$, $Y_C = j\omega C$, $Y_L = -j/(\omega L)$.
- Kondansatörde akım gerilimden $90^\circ$ önde; bobinde gerilim akımdan $90^\circ$ önde; dirençte aynı faz.
- $Z = R + jX$, $|Z| = \sqrt{R^2+X^2}$, $\phi = \tan^{-1}(X/R)$.
- Seri: $Z_{eq} = \sum Z_k$; paralel: $Y_{eq} = \sum Y_k$, $Z_{eq} = 1/Y_{eq}$.
- KVL, KCL, gerilim/akım bölücü, Thevenin/Norton ve kaynak dönüşümü empedanslarla DC'deki gibi uygulanır.
- Örnek 03: $Z_{eq} = 10 + j1 = 10{,}05\angle 5{,}7^\circ\ \Omega$, $\mathbf{I} = 1{,}19\angle -65{,}7^\circ$ A; gerilim akımdan önde.
- Örnek 04: $Y_{eq} = 1 + j0{,}297 = 1{,}04\angle 16{,}5^\circ\ \Omega^{-1}$, $Z_{eq} = 0{,}959\angle -16{,}5^\circ\ \Omega$, $\mathbf{V} = 3{,}84\angle -26{,}5^\circ$ V; akım gerilimden önde.
- Örnek 02: $\mathbf{V} \approx 545\angle 43{,}2^\circ$ mV; gerilim akımdan yaklaşık $13^\circ$ önde.

## Detaylı Açıklamalar

- Neden empedans gerekir?
  - Yalnız dirençli bir AC devrede gerilim ve akım aynı fazdadır; akım fazöre çevrilip $R$ ile çarpılarak gerilim fazörü bulunur. Devrede kondansatör ya da bobin varsa bu elemanlar enerji depoladığı için gerilimle akım arasında $90^\circ$ faz kayması oluşur. Kondansatörde $i = C\,dv/dt$ türevi kosinüsü eksi sinüse çevirir; eksi işareti $180^\circ$ eklenerek, sinüs de $90^\circ$ çıkarılarak kosinüse getirilir ve $i(t) = \omega C V_m\cos(\omega t + 90^\circ)$ elde edilir (ekrandan, 00:15:00). Bu kayma fazörde $e^{j90^\circ} = j$ çarpanı olarak görünür: $\mathbf{I} = j\omega C\mathbf{V}$. $V/I$ oranı $1/(j\omega C)$ verir; bu, kondansatörün AC'deki "direnç benzeri" katkısıdır, yani empedansıdır. Bobin için akım üzerinden aynı türetme $Z_L = j\omega L$ verir.
  - İki sinyal ancak frekansları aynıysa karşılaştırılabilir. Kondansatör ve bobin frekansı değiştirmez, yalnız fazı kaydırır.
- Açıların kaynağı
  - Karmaşık düzlemde $+j$ ekseni $90^\circ$, $-j$ ekseni $-90^\circ$ açısındadır. $a + jb$ fazöre çevrilirken genlik $\sqrt{a^2+b^2}$, açı $\tan^{-1}(b/a)$'dır. Saf sanal bir sayıda $a = 0$ olduğundan açı $b$'nin işaretine göre $\pm 90^\circ$ çıkar; bu yüzden $Z_L$ $+90^\circ$, $Z_C$ $-90^\circ$ açılıdır. Direnç saf gerçel olduğundan açısı $0^\circ$'dir.
  - Ders sonrası not: Hoca dirençte açının arktanjanttan "1" geldiğini söyledi (00:28:25); doğrusu $\tan^{-1}(0/R) = 0^\circ$'dir. Hoca ayrıca açı formülünü birkaç kez "eksi arktanjant" diye okudu (00:35:38, 00:53:46); slayttaki doğru ifade $\phi = \tan^{-1}(X/R)$'dir.
- Örnek 03: seri RL devresi (ekrandan, 00:45:00 ve 00:50:00)
  - $v_s = 12\sin(100t + 30^\circ)$ V, $R = 10\ \Omega$, $L = 10$ mH. Direnç ve bobin farklı birimlerde olduğu için doğrudan toplanamaz; empedansa çevrilince ikisi de ohm olur.
  - $Z_R = 10\ \Omega$, $Z_L = j(100)(10\text{ mH}) = j1\ \Omega$, $Z_{eq} = 10 + j1 = \sqrt{101}\angle\tan^{-1}(1/10) = 10{,}05\angle 5{,}7^\circ\ \Omega$.
  - $v_s = 12\cos(100t + 30^\circ - 90^\circ) = 12\cos(100t - 60^\circ)$, yani $\mathbf{V} = 12\angle -60^\circ$ V.
  - $\mathbf{I} = \mathbf{V}/Z_{eq} = 1{,}19\angle -65{,}7^\circ$ A. Gerilim açısı ($-60^\circ$) daha pozitif olduğu için gerilim akımdan $5{,}7^\circ$ öndedir.
  - Ders sonrası not: Hoca $\omega = 100$ rad/s için frekansı "16 Hz gibi" dedi; $f = 100/(2\pi) \approx 15{,}9$ Hz'dir. Hoca sinyali "tepeden tepeye 12 V" diye niteledi; 12 V genliktir, tepeden tepeye değer 24 V'tur.
- Örnek 04: paralel R, C, L ve admitans (ekrandan, 00:55:00)
  - $i_s = 4\cos(300t - 10^\circ)$ A, $R = 1\ \Omega$, $C = 1$ mF, $L = 1$ H, hepsi paralel. $Y_R = 1$, $Y_C = j\omega C = j0{,}3$, $Y_L = -j/(\omega L) = -j3{,}33\text{ m}\Omega^{-1}$.
  - $Y_{eq} = 1 + j0{,}297 = 1{,}04\angle 16{,}5^\circ\ \Omega^{-1}$, $Z_{eq} = 1/Y_{eq} = 0{,}959\angle -16{,}5^\circ\ \Omega$.
  - $\mathbf{V} = \mathbf{I}Z_{eq} = 4\angle -10^\circ \cdot 0{,}959\angle -16{,}5^\circ = 3{,}84\angle -26{,}5^\circ$ V. Akım açısı daha pozitif olduğu için akım gerilimden öndedir.
- Örnek 05: kaynak dönüşümü ve Thevenin (ekrandan, 01:00:00 ve 01:05:00)
  - $i_1 = 5\text{ mA}\sin(400t + 50^\circ) = 5\text{ mA}\cos(400t - 40^\circ)$, $\mathbf{I}_1 = 5\angle -40^\circ$ mA. Elemanlar: $C_1 = 1\ \mu$F ($-j2{,}5$ kΩ), $R_1 = 3$ kΩ, $L_1 = 0{,}3$ H ($j120\ \Omega$), $L_2 = 2$ H ($j800\ \Omega$), $R_2 = 5$ kΩ, $C_2 = 0{,}7\ \mu$F ($-j3{,}57$ kΩ).
  - Akım kaynağı ile paralel $Z_{C1}$ gerilim kaynağı ile seri empedansa dönüştürülür; $R_1$ ile toplanır; yeniden akım kaynağına dönüştürülür; $L_1$ ile paralel birleştirme admitansla yapılır; tekrar gerilim kaynağına çevrilir ve $L_2$ ile seri toplanır. Sonunda $C_2$ üzerindeki gerilim bulunur.
  - Slaytta $\mathbf{V}_{th2} = \mathbf{I}_{n1}/\mathbf{Y}_{th2} = 1{,}92\text{ mA}\angle -90{,}2^\circ / 8{,}17\text{ m}\Omega^{-1}\angle -88{,}6^\circ = 0{,}235\angle -1{,}6^\circ$ V yazıyor (ekrandan, 01:05:00).
  - Ders sonrası not: Python ile yeniden hesapta $\mathbf{I}_{n1} = 12{,}5\angle -130^\circ / 3905\angle -39{,}8^\circ \approx 3{,}20\angle -90{,}2^\circ$ mA çıkar; buna göre $\mathbf{V}_{th2} \approx 0{,}392\angle -1{,}6^\circ$ V olur. Açılar slaytla aynıdır, genlik farkı büyük olasılıkla slayttaki bir ara değer hatasından gelir. Ayrıca hoca $Z_{C2}$'yi "357 kilo" diye okudu; doğrusu $3{,}57$ kΩ'dur.
- Örnek 02: paralel RLC'de KCL (ekrandan, 01:15:00)
  - $i_s = 8\cos(2\pi\cdot 10^6 t + 30^\circ)$ mA, $70\ \Omega$, $10\ \mu$H, $2$ nF paralel. $\mathbf{I}_s = 8\angle 30^\circ$ mA. KCL: $\mathbf{I}_s - \mathbf{V}/R - \mathbf{V}/(j\omega L) - j\omega C\mathbf{V} = 0$.
  - Kondansatör terimi: $\mathbf{V}/Z_C = \mathbf{V}/(-j/\omega C) = j\omega C\mathbf{V}$. Denklemdeki eksi işaretler KCL'den gelir, $j$'den değil.
  - Çözüm: $\mathbf{V} \approx 545\angle 43{,}2^\circ$ mV. Gerilim açısı akımınkinden yaklaşık $13^\circ$ daha pozitif, yani gerilim akımdan öndedir. Eşdeğer empedans istenseydi admitanslar toplanıp tersi alınırdı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
