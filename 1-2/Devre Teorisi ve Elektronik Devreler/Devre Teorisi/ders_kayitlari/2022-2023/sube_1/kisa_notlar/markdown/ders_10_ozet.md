# Ders 10 Çalışma Özeti

## Genel Konular

- Kondansatörün frekansa göre davranışı (filtre sezgisi)
  - DC şart, frekansın sıfır olduğu durumdur. Bu durumda kondansatör açık devre gibi davranır.
  - Frekans sonsuza giderken kondansatör kısa devre gibi davranır. Çıkış kondansatör üzerinden alınıyorsa yüksek frekanslarda çıkış sıfıra düşer, yani devre yüksek frekansları geçirmez.
  - Frekans sıfır ve sonsuz iken devrenin iki eşdeğerini çözmek, bir filtrenin çalışma mantığını kabaca ortaya çıkarır.
- İkinci dereceden devrelerde başlangıç ve sınır koşulları
  - İkinci dereceden diferansiyel denklemin iki bilinmeyen katsayısı vardır. Bu yüzden en az iki başlangıç koşulu gerekir.
  - Kondansatör gerilimi süreklidir: $v_C(t_0^-) = v_C(t_0^+)$. İkinci koşul $i_C = C\,dv_C/dt$ bağıntısından gelir.
  - Bobin akımı süreklidir: $i_L(t_0^-) = i_L(t_0^+)$. İkinci koşul $v_L = L\,di_L/dt$ bağıntısından gelir.
  - Üç durum incelenir: değişimden önce ($t < t_0$, uzun süre DC), geçici hal (yaklaşık $5\tau$ boyunca) ve sürekli hal ($t \to \infty$).
  - $t < t_0$ için kondansatör açık devre ($\infty\,\Omega$), bobin kısa devre ($0\,\Omega$) yapılır. Bu yüzden $I_C(t<t_0) = 0$ A ve $V_L(t<t_0) = 0$ V olur (ekrandan, 00:10:00).
- Kaynaksız seri RLC devresi
  - Kaynak $t_0$ anına kadar devrededir, $t_0$ anında çıkarılır (yerine kısa devre gelir). Fiziksel karşılığı, $t_0$ anında açılan bir anahtardır.
  - Başlangıç koşulları: $i(t_0^-) = i_L(t_0^-) = 0$, $v_C(t_0^-) = V_s$, $v_L(t_0^-) = 0$, $i_C(t_0^-) = 0$. Sonsuzda bütün akım ve gerilimler sıfırdır (ekrandan, 00:15:00).
  - Çevre denklemi $v_R + v_L + v_C = 0$ ve $i = C\,dv_C/dt$ ile $LC\,v_C'' + RC\,v_C' + v_C = 0$ elde edilir. $LC$'ye bölünce $v_C'' + \frac{R}{L}v_C' + \frac{1}{LC}v_C = 0$ olur.
  - Önerilen çözüm $v_C(t) = A e^{s\Delta t}$ ($\Delta t = t - t_0$). Yerine konunca karakteristik denklem $s^2 + \frac{R}{L}s + \frac{1}{LC} = 0$ çıkar (ekrandan, 00:20:00).
- Karakteristik kökler ve parametreler
  - $\alpha = \frac{R}{2L}$ (seri devre), $\omega_0 = \frac{1}{\sqrt{LC}}$ tanımlarıyla denklem $s^2 + 2\alpha s + \omega_0^2 = 0$ olur. Kökler $s_{1,2} = -\alpha \pm \sqrt{\alpha^2 - \omega_0^2}$ (ekrandan, 00:25:00).
  - $s_1, s_2$: doğal frekanslar (Np/s). $\omega_0$: rezonans frekansı ya da sönümsüz doğal frekans (rad/s). $\alpha$: neper frekansı ya da sönüm faktörü (Np/s).
  - Genel çözüm $v_C(t) = A_1 e^{s_1\Delta t} + A_2 e^{s_2\Delta t}$ (ekrandan, 00:30:00).
  - $A_1, A_2$ için iki denklem: $A_1 + A_2 = V_s$ (kondansatör gerilimi sürekli) ve $s_1A_1 + s_2A_2 = 0$ ($i_C(t_0) = i_L(t_0) = 0$) (ekrandan, 00:35:00).
- Doğal ve zorlanmış çözüm
  - Yalnız başlangıç enerjisinden gelen çözüm doğal çözümdür (natural, transient, geçici hal çözümü).
  - $t \to \infty$ iken devrede bulunan kaynaktan gelen çözüm zorlanmış çözümdür (forced, steady-state, sürekli hal çözümü).
  - Tam (homojen diye anılan) çözüm ikisinin toplamıdır: $x(t) = x_n(t) + x_f(t)$.
- Üç sönüm durumu
  - $\alpha > \omega_0$: aşırı sönümlü (overdamped). İki ayrı, negatif gerçek kök. $v_C = A_1e^{s_1\Delta t} + A_2e^{s_2\Delta t}$.
  - $\alpha = \omega_0$: kritik sönümlü (critically damped). Çakışık kök $s_1 = s_2 = -\alpha$. $v_C = (A_1 + A_2\Delta t)e^{-\alpha\Delta t}$.
  - $\alpha < \omega_0$: az sönümlü (underdamped). Seri devre için $C < 4L/R^2$ demektir. Kökler $-\alpha \pm j\omega_d$, $\omega_d = \sqrt{\omega_0^2 - \alpha^2}$ (ekrandan, 00:40:00).
  - Az sönümlü çözüm Euler formülüyle $v_C = e^{-\alpha\Delta t}[B_1\cos\omega_d\Delta t + B_2\sin\omega_d\Delta t]$ olur; $B_1 = A_1 + A_2$, $B_2 = j(A_1 - A_2)$ (ekrandan, 00:45:00).
- Kaynaksız paralel RLC devresi
  - $t_0$ anında devreden çıkarılan bir akım kaynağı kullanılır. Örnek devre: $R = 2\,\mathrm{k}\Omega$, $L = 10\,\mu\mathrm{H}$, $C = 3\,\mu\mathrm{F}$ (ekrandan, 00:55:00).
  - $t_0^-$ anında: $i_L = I_s$, diğer bütün akım ve gerilimler sıfır. Sonsuzda hepsi sıfır.
  - Düğüm denklemi $i_R + i_L + i_C = 0$ ve $v = L\,di_L/dt$ ile $i_L'' + \frac{1}{RC}i_L' + \frac{1}{LC}i_L = 0$ elde edilir (ekrandan, 01:00:00).
  - Paralel devrede $\alpha = \frac{1}{2RC}$, $\omega_0$ yine $\frac{1}{\sqrt{LC}}$.
  - $i_L$ bulununca diğer büyüklükler: $v_L = L\,di_L/dt$, $v_L = v_C = v_R$, $i_C = C\,dv_C/dt$, $i_R = v_R/R$ (ekrandan, 01:05:00).
- Kaynaklı (basamak cevaplı) seri RLC devresi
  - Kaynak $V_s\,u(t - t_0)$: $t_0$'a kadar sıfır, sonra $V_s$. Başlangıçta bütün değerler sıfır; sonsuzda $v_C(\infty) = V_s$, diğerleri sıfır.
  - Denklem: $v_C'' + \frac{R}{L}v_C' + \frac{1}{LC}v_C = \frac{V_s}{LC}$ ve $v_C = v_t + v_{ss}$ (ekrandan, 01:25:00).
  - Zorlanmış çözüm için $v_{C,ss} = at + b$ denenince $a = 0$, $b = V_s$ bulunur (ekrandan, 01:35:00).
  - Tam çözümler: doğal çözüm (üç durumdan biri) $+ V_s$ (ekrandan, 01:40:00).
- Kaynaklı paralel RLC devresi
  - Akım kaynağına paralel anahtar $t_0$ anına kadar kapalıdır (kaynak kendi içinde döner), $t_0$'da açılır.
  - Denklem: $i_L'' + \frac{1}{RC}i_L' + \frac{1}{LC}i_L = \frac{I_s}{LC}$ ve $i_L = i_t + i_{ss}$ (ekrandan, 01:45:00). Zorlanmış çözüm $I_s$'dir.
  - Tam çözümler: doğal çözüm (üç durumdan biri) $+ I_s$ (ekrandan, 01:50:00).
- Frekans uzayına geçişin gerekçesi
  - Kaynaklar sinüzoidal ve geçici haller bitmişse devre, diferansiyel denklem çözmeden cebirsel olarak (düğüm, çevre) çözülebilir (ekrandan, 01:55:00).
  - Frekans uzayında eleman bağıntıları doğrusal (cebirsel) denklemlere döner; her eleman bir "direnç" gibi davranır. Sonuç tekrar zaman uzayına geri çevrilir.
- Karmaşık sayılar
  - $z = x + jy$, $j = \sqrt{-1}$: kartezyen (dikdörtgen) gösterim. $z = r\angle\phi = re^{j\phi}$: polar ve üstel gösterim (ekrandan, 02:05:00).
  - Dönüşümler: $r = \sqrt{x^2 + y^2}$, $\phi = \arctan(y/x)$, $x = r\cos\phi$, $y = r\sin\phi$. Euler: $e^{j\phi} = \cos\phi + j\sin\phi$.
  - Eşlenik: $z = a + jb$ ise $z^* = a - jb$; gerçek eksene göre aynadaki görüntü.
  - Toplama ve çıkarma kartezyen biçimde bileşen bileşen yapılır; grafikte vektör toplamıdır (uç uca ekleme). Örnek: $M = 3 + j$, $N = 2 - 2j$, $M + N = 5 - j$ (ekrandan, 02:10:00).
  - Çarpma ve bölme polar biçimde kolaydır: genlikler çarpılır (bölünür), açılar toplanır (çıkarılır).

## Hocanın Özellikle Vurguladığı Kısımlar

- İkinci dereceden devrede en az iki başlangıç koşulu şarttır
  - Biri kondansatör geriliminin ya da bobin akımının sürekliliğinden, diğeri o büyüklüğün türeviyle ilişkili eleman bağıntısından ($i_C = Cv_C'$, $v_L = Li_L'$) gelir.
- Diferansiyel formda yazmak tercih edilmelidir
  - İntegral formda yazınca integralden gelen bir sabit ortaya çıkar; bunu belirlemekle uğraşmamak için mümkünse türevli form kullanılır. Derste ayrıntılı diferansiyel denklem çözümü yerine sınır koşullarına göre hazır çözüm kalıpları seçilir.
- Seri ve paralel devrede $\alpha$ farklıdır
  - Seri: $\alpha = R/(2L)$; paralel: $\alpha = 1/(2RC)$. Her ikisinde $\omega_0 = 1/\sqrt{LC}$. Hoca bunu "alfalar farklı, dikkat edin" diye vurguladı.
- Kök türüne göre doğru çözüm kalıbını seçmek
  - Formüller (alfa, kökler) gerekirse verilebilir; asıl beklenen, kökler gerçek, çakışık ya da karmaşık eşlenik çıktığında hangi çözümün önerileceğini doğru seçmektir.
- Zorlanmış çözüm kaynağın tipindedir
  - Sabit kaynak için sabit, $A\sin\omega t$ için $B\sin(\omega t + \phi)$, $At + B$ için $at + b$ önerilir. Gereğinden fazla terim önerilirse fazlası hesapta sıfır çıkar.
- Sonucu doğrulamak
  - Bulunan çözüm $t \to \infty$ ya da bilinen başka anlar için mutlaka kontrol edilmelidir.
- $\omega_0$ ile $\omega_d$ karıştırılmamalı
  - $\omega_0$ diferansiyel denklemin katsayısından, $\omega_d = \sqrt{\omega_0^2 - \alpha^2}$ karmaşık kökün sanal kısmından gelir.

## Kısa Tekrar Notları

- $t<t_0$ (uzun süre DC): kondansatör açık devre, bobin kısa devre.
- Süreklilik: $v_C(t_0^-) = v_C(t_0^+)$, $i_L(t_0^-) = i_L(t_0^+)$.
- Seri kaynaksız: $v_C'' + \frac{R}{L}v_C' + \frac{1}{LC}v_C = 0$; paralel kaynaksız: $i_L'' + \frac{1}{RC}i_L' + \frac{1}{LC}i_L = 0$.
- $s^2 + 2\alpha s + \omega_0^2 = 0$, $s_{1,2} = -\alpha \pm \sqrt{\alpha^2 - \omega_0^2}$.
- $\alpha > \omega_0$ aşırı sönümlü, $\alpha = \omega_0$ kritik sönümlü, $\alpha < \omega_0$ az sönümlü.
- Kritik sönümlü devre son duruma en kısa sürede ulaşır; ama aşırı ya da az sönümlü devrenin ilk değişimi daha büyük olabilir (ekrandan, 00:50:00).
- Az sönümlü cevap sönümlü salınımdır (ringing); salınım, enerjinin bobin ile kondansatör arasında aktarılmasından gelir. $R = 0$ ise sönüm olmaz, salınım sürer.
- Kaynaklı devrede tam çözüm = doğal çözüm + zorlanmış çözüm ($V_s$ ya da $I_s$).
- $\Delta t = t - t_0$; değişim $t_0$'da oluyorsa üstellerde $t$ yerine $t - t_0$ yazılır.
- Karmaşık sayı: toplama kartezyende, çarpma ve bölme polarda kolaydır. $j^2 = -1$, $j^4 = 1$.

## Detaylı Açıklamalar

- **Kaynaksız seri RLC çözüm adımları.** Önce $t_0^-$ için devre DC şartlarda çözülür: akım yoktur, kondansatör kaynak gerilimine şarj olmuştur ($v_C = V_s$). Kaynak çıkınca kondansatördeki enerji direnç üzerinden harcanır ve $t \to \infty$'da her şey sıfıra gider. Çevre denkleminde $v_L = L\,di/dt$ ve tek kol olduğu için $i = i_L = i_R = i_C = C\,dv_C/dt$ yazılır; böylece denklem yalnız $v_C$ cinsinden ikinci dereceden olur. Türevleri kendisiyle aynı biçimde olan fonksiyon aranır; bu $e^{st}$'dir. Yerine konunca $Ae^{s\Delta t}$ çarpanı sıfır olamayacağı (o durumda çözüm sıfırdır) için karakteristik denklemin sıfır olması gerekir. İki kök çıkar; her biri ayrı ayrı çözümdür, sabitle çarpımları ve toplamları da çözümdür, çünkü türev işlemi doğrusaldır.
- **Katsayıların bulunması.** $\Delta t = 0$'da üsteller 1 olur. Kondansatör gerilimi sürekli olduğundan $A_1 + A_2 = V_s$. Bobin akımı $t_0$'da sıfırdır ve $i_L = i_C = C\,dv_C/dt$ olduğundan türevin $t_0$'daki değeri sıfırdır: $s_1A_1 + s_2A_2 = 0$. İki bilinmeyenli iki denklemden $A_1 = \frac{-s_2V_s}{s_1 - s_2}$, $A_2 = \frac{s_1V_s}{s_1 - s_2}$ bulunur (ara adım eklendi, python ile kontrol edildi).
- **Az sönümlü durumda kosinüs-sinüs biçimi.** $e^{-\alpha\Delta t}(A_1e^{j\omega_d\Delta t} + A_2e^{-j\omega_d\Delta t})$ ifadesine Euler formülü uygulanır, kosinüs ve sinüs terimleri ayrı paranteze alınır. $B_1 = A_1 + A_2$, $B_2 = j(A_1 - A_2)$ tanımlanınca gerçek bir sinüzoidal ifade elde edilir. Hoca aynı frekanslı sinüs ve kosinüs toplamının tek bir kosinüs olarak ($C_1\cos(\omega_d\Delta t + C_2)$ biçiminde, genlik ve faz farkı ile) de yazılabileceğini, hangisi kolaysa onun kullanılabileceğini söyledi. Ortaya çıkan eğri, üstel azalan bir zarfın içinde kalan sinüzoidaldir; periyodu $2\pi/\omega_d$'dir (ekrandan, 00:40:00).
- **Kaynaklı seri RLC'de zorlanmış çözüm.** $v_{C,ss} = at + b$ denendiğinde ikinci türev sıfır, birinci türev $a$ olur. Denklem $\frac{R}{L}a + \frac{at + b}{LC} = \frac{V_s}{LC}$ biçimini alır. Sağ tarafta $t$'li terim yoktur; polinomlarda aynı dereceli terimlerin katsayıları eşit olacağından $a/(LC) = 0$, yani $a = 0$ ve $b = V_s$ bulunur. Hoca bundan, gereğinden fazla terim önerildiğinde fazlanın sıfır çıktığını ve sabit kaynak için sabit önermenin yeterli olduğunu çıkardı.
- **Kaynaklı paralel RLC.** Düğümde $i_R + i_L + i_C = I_s$ yazılır. $v = L\,di_L/dt$ kullanılarak $i_R = \frac{L}{R}i_L'$, $i_C = LC\,i_L''$ olur. Zorlanmış çözüm için sabit $A$ denenir: $A/(LC) = I_s/(LC)$, yani $A = I_s$. Başlangıçta bütün değerler sıfır olduğundan katsayılar, başlangıç değerleri ve sonsuzdaki değer birlikte kullanılarak bulunur.
- **Frekans uzayı fikri.** Zaman uzayında bobin ve kondansatörün akım-gerilim ilişkisi türevlidir. Uygun bir uzaya (frekans uzayı) geçildiğinde bu ilişki doğrusal bir cebirsel ilişkiye dönüşür; eleman bağıntıları, kaynaklar ve devre topolojisi bu uzaya taşınınca devre, ne kadar karmaşık olursa olsun bir direnç devresi gibi çözülür. Bulunan büyüklük (örneğin $v_C$) tekrar zaman uzayına çevrilir. Bu yöntem sinüzoidal kaynaklı ve geçici hali bitmiş devreler içindir. Bu geçiş karmaşık sayılarla yapılacağından ders, karmaşık sayı işlemlerinin tekrarıyla bitti.
- **Karmaşık sayı işlemleri.** Kartezyen çarpımda dağılma özelliği ve $j^2 = -1$ kullanılır: $(a + jb)(c + jd) = (ac - bd) + j(ad + bc)$. Bölmede pay ve payda paydanın eşleniğiyle çarpılır, böylece payda gerçek olur: $\frac{a + jb}{c + jd} = \frac{ac + bd}{c^2 + d^2} + j\,\frac{bc - ad}{c^2 + d^2}$. Polar biçimde $r_1\angle\phi_1 \cdot r_2\angle\phi_2 = r_1r_2\angle(\phi_1 + \phi_2)$ ve $\frac{r_1\angle\phi_1}{r_2\angle\phi_2} = \frac{r_1}{r_2}\angle(\phi_1 - \phi_2)$. Euler formülü, $e^x$, $\sin x$ ve $\cos x$'in sonsuz terimli polinom (Taylor) açılımlarından gelir: $x = j\phi$ konunca çift dereceli terimler kosinüse, tek dereceli terimler $j$ çarpı sinüse karşılık gelir; $j$'nin kuvvetleri dörtte bir tekrar eder ($1, j, -1, -j$).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
