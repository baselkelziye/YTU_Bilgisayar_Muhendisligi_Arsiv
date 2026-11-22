# Ders 10 Çalışma Özeti

## Genel Konular

- Birinci dereceden devrelerden ikinci dereceden devrelere geçiş
  - Birinci dereceden (first order) devrelerde tek bir kondansatör ya da tek bir bobin bulunur. Denklem, bobinde $v_L = L\,di_L/dt$, kondansatörde $i_C = C\,dv_C/dt$ bağıntısından gelen birinci türevi içerir. Şarj ve deşarj, $1-e^{-t/\tau}$ ve $e^{-t/\tau}$ biçimli ifadelerle anlatılmıştı.
  - İkinci dereceden (second order) devrelerde enerji depolayan iki eleman vardır: bir bobin ve bir kondansatör (seri ya da paralel), iki bobin ya da iki kondansatör. Bu devrelere genelde RLC devreleri denir.
  - Bu konu birinci dereceden devrelerin üzerine kurulur; o konunun iyi anlaşılmış olması gerekir.
- Sınır koşulları (boundary conditions)
  - Bir anahtarın konum değiştirdiği ya da kaynağın devreye girip çıktığı an $t_0$'dır. Geçişten çok önceki durum (initial, $t<t_0$) ve geçişten çok sonraki durum (final, $t=\infty$) sınır koşullarıdır.
  - Kararlı halde (steady state) kondansatör açık devre ($i_C = 0$), bobin kısa devre ($v_L = 0$) kabul edilir. Bu kural hem başlangıç hem son durum için uygulanır.
  - Geçiş anında kondansatör gerilimi ve bobin akımı süreklidir: $v_C(t_0^+) = v_C(t_0^-)$, $i_L(t_0^+) = i_L(t_0^-)$ (ekrandan, 00:25:00).
  - Geçişte devrenin dışarıdan başka bir etkiyle bozulmadığı, ani kopma gibi durumların olmadığı kabul edilir; bunlar konu dışıdır.
- Sınır koşulu örnekleri (Örnek 1-3 ekrandan, 00:30:00 - 00:40:00; Örnek 4 altyazıdan)
  - Örnek 1: $V_1$, $R_1$, $R_2$, $L_1$, $R_3$, $C_1$ devresi; $t_0$'da $V_1$ devreden çıkıyor. Başlangıçta $i_L = 0$, $v_L = 0$, $i_C = 0$, $v_C = V_1 R_2/(R_1+R_2)$. Sonda her şey sıfıra gider.
  - Örnek 2: $V_1 = 2$ V, $R_1 = 5$ kΩ, $C_1$, $L_1 = 10\,\mu$H, $R_2 = 5$ kΩ, $V_2 = 5$ V. Başlangıçta $i_L = -0{,}3$ mA, $v_C = 3{,}5$ V. Sol kol açılınca $v_C \to 5$ V, $i_L \to 0$.
  - Örnek 3: $L_1 = 10\,\mu$H, $L_2 = 40\,\mu$H, $R_2 = 5$ kΩ, $V_2 = 5$ V; $t_0$'da 2 V'luk kaynak devreye giriyor. Başlangıçta $i_{L1} = -1$ mA, $i_{L2} = 1$ mA. Sonda $i_{L1} = -1$ mA, $i_{L2} = 1{,}4$ mA (süperpozisyonla).
  - Örnek 4: iki kondansatör ve bir bobin; 1 V ve 5 V'luk zıt kaynaklar, 3 kΩ ve 1 kΩ. Başlangıçta $i_L = -1$ mA, $v_C = 4$ V. Anahtar açılınca $v_C \to 1$ V, $i_L \to 0$. <!-- BELİRSİZ: Örnek 4'ün devre şekli karelerde yok, yerleşim altyazıdan kuruldu. -->
- Kaynaksız seri RLC devresi (source-free series RLC)
  - Kaynak $V_s[1-u(t-t_0)]$ biçimindedir, yani $t_0$'da devreden çıkar (ekrandan, 00:50:00). Başlangıçta $v_C = V_s$, $i_L = 0$; sonda her şey sıfırdır.
  - KVL: $v_C + L\,di_L/dt + R\,i_L = 0$. Seri devrede $i_L = i_C = C\,dv_C/dt$ olduğundan $\dfrac{d^2v_C}{dt^2} + \dfrac{R}{L}\dfrac{dv_C}{dt} + \dfrac{1}{LC}v_C = 0$ elde edilir (ekrandan, 00:55:00).
  - $v_C = Ae^{st}$ konunca karakteristik denklem $s^2 + 2\alpha s + \omega_0^2 = 0$ olur. Kökler $s_{1,2} = -\alpha \pm \sqrt{\alpha^2 - \omega_0^2}$; seri devrede $\alpha = R/(2L)$, $\omega_0 = 1/\sqrt{LC}$ (ekrandan, 01:00:00).
  - $\alpha$ sönüm katsayısı (neper frekansı, Np/s), $\omega_0$ rezonans frekansı ya da sönümsüz doğal frekanstır (rad/s).
  - Genel çözüm $v_C(t) = A_1 e^{s_1 t} + A_2 e^{s_2 t}$. Katsayılar başlangıç koşullarından bulunur: $A_1 + A_2 = V_s$ ve $s_1A_1 + s_2A_2 = 0$ (çünkü $i_C(t_0) = 0$).
- Üç cevap türü
  - Aşırı sönümlü (overdamped): $\alpha > \omega_0$, yani $C > 4L/R^2$. İki farklı reel kök vardır.
  - Kritik sönümlü (critically damped): $\alpha = \omega_0$. Tek (çift) kök $s = -\alpha$.
  - Az sönümlü (underdamped): $\alpha < \omega_0$, yani $C < 4L/R^2$. Kökler karmaşıktır: $s_{1,2} = -\alpha \pm j\omega_d$, $\omega_d = \sqrt{\omega_0^2 - \alpha^2}$. Euler bağıntısıyla $v_C(t) = e^{-\alpha t}(B_1\cos\omega_d t + B_2 \sin\omega_d t)$, $B_1 = A_1 + A_2$, $B_2 = j(A_1 - A_2)$ (ekrandan, 01:20:00).
- Diğer akım ve gerilimler
  - $v_C(t)$ bulununca $i_C = C\,dv_C/dt$, seri devrede $i = i_C = i_L = i_R$, $v_L = L\,di_L/dt$, $v_R = R\,i_R$ ile diğer büyüklükler bulunur (ekrandan, 01:30:00).
- Kaynaksız paralel RLC devresi
  - Akım kaynağı $I_s$, $t_0$'da devreden çıkar. Başlangıçta bobin kısa devre olduğu için $i_L = I_s$, $v_C = 0$, $i_C = 0$; sonda $i_L = 0$.
  - KCL: $i_R + i_L + i_C = 0$, paralelde $v = v_R = v_L = v_C = L\,di_L/dt$. Sonuç: $\dfrac{d^2 i_L}{dt^2} + \dfrac{1}{RC}\dfrac{di_L}{dt} + \dfrac{i_L}{LC} = 0$ (ekrandan, 01:50:00).
  - Fark yalnız $\alpha$'dadır: paralelde $\alpha = 1/(2RC)$; $\omega_0 = 1/\sqrt{LC}$ aynı kalır. Üç durumun ölçütleri ve çözüm biçimleri seri devreyle aynıdır.
- Basamak (step) cevabı: kaynağın devreye eklenmesi
  - Seri RLC'de $V_s u(t-t_0)$ bağlanır. KVL'ye $-V_s$ terimi girer: $\dfrac{d^2v_C}{dt^2} + \dfrac{R}{L}\dfrac{dv_C}{dt} + \dfrac{1}{LC}v_C = \dfrac{V_s}{LC}$ (ekrandan, 02:00:00). Başlangıçta $v_C = 0$, sonda $v_C = V_s$.
  - Paralel RLC'de $I_s$ eklenir: $i_R + i_L + i_C = I_s$; başlangıçta $i_L = 0$, sonda $i_L = I_s$.
  - Değişen tek şey başlangıç ve son değerlerdir; $\alpha$, $\omega_0$ ve üç durumun ölçütleri aynıdır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kondansatör açık devre, bobin kısa devre
  - Kararlı halde kondansatör açık devre, bobin kısa devre yapılır. Hoca, sınavlarda bunu ters yapan (bobini açık, kondansatörü kısa devre yapan) çok öğrenci gördüğünü söyleyip iki kuralın karıştırılmamasını istedi.
- Kondansatörün neye şarj olduğu
  - Kondansatör giriş gerilimine değil, uçlarının paralel bağlı olduğu kısmın gerilimine şarj olur. Örnek 1'de $v_C = V_1R_2/(R_1+R_2)$ çıkar (gerilim bölücü). Bu en sık yapılan hatalardan biridir.
- $\alpha$ ve $\omega_0$ en kritik iki parametredir
  - $\alpha$ sönümlendirir, sönümü sağlayan direnç etkisidir. $\omega_0$ salınım yaptırır, bobin-kondansatör etkileşiminden gelir. Cevabın türü bu ikisinin karşılaştırmasıyla belirlenir.
- Konunun önemi
  - Hoca bu konunun öğrenciler açısından en problemli gördüğü konu olduğunu, farklı örneklerle çalışılması gerektiğini vurguladı.

## Kısa Tekrar Notları

- İkinci dereceden devre = enerji depolayan iki eleman (LC, LL ya da CC).
- Kararlı halde: kondansatör açık devre ($i_C = 0$), bobin kısa devre ($v_L = 0$).
- Geçişte $v_C$ ve $i_L$ süreklidir.
- Seri RLC: $\alpha = R/(2L)$. Paralel RLC: $\alpha = 1/(2RC)$. İkisinde de $\omega_0 = 1/\sqrt{LC}$.
- $s_{1,2} = -\alpha \pm \sqrt{\alpha^2 - \omega_0^2}$.
- $\alpha > \omega_0$: aşırı sönümlü, $A_1e^{s_1t} + A_2e^{s_2t}$.
- $\alpha = \omega_0$: kritik sönümlü, $e^{-\alpha t}(A_1 t + A_2)$.
- $\alpha < \omega_0$: az sönümlü, $e^{-\alpha t}(B_1\cos\omega_d t + B_2\sin\omega_d t)$, $\omega_d = \sqrt{\omega_0^2-\alpha^2}$.
- Seri RLC'de $\alpha > \omega_0 \iff C > 4L/R^2$.
- Katsayılar $t_0$ anındaki değerden ve türevinden (kondansatör akımından) bulunur.
- Kaynak eklenince denklem sağ tarafı sıfır olmaz; son değer $V_s$ (seri) ya da $I_s$ (paralel) olur.

## Detaylı Açıklamalar

- Sınır koşullarının bulunması
  - Önce $t<t_0$ devresi çizilir, kondansatör yerine açık devre (ya da çok büyük direnç), bobin yerine kısa devre konur. Böylece $i_L$ ve $v_C$ bulunur. Sonra $t=\infty$ devresi aynı kurallarla çözülür. Geçişin nasıl olacağı ayrı bir hesaptır; sınır koşulları yalnız nereden nereye gidileceğini söyler.
  - Örnek 2'de iki kaynak birbirine zıt olduğundan net 3 V, toplam 10 kΩ üzerinden 0,3 mA akım akar. Akım 5 V'tan 2 V'a doğru akar; şekildeki $I_L$ okuna göre bu $-0{,}3$ mA'dir. Kondansatör gerilimi iki yoldan bulunur: $2 + 0{,}3\text{ mA}\cdot 5\text{ kΩ} = 3{,}5$ V ya da $5 - 0{,}3\text{ mA}\cdot 5\text{ kΩ} = 3{,}5$ V. Sol kol açılınca kondansatör 5 V'a çıkar ve iki uç arasında potansiyel fark kalmadığı için akım sıfıra iner.
  - Örnek 3'te bobinler kısa devre olduğundan başlangıçta $5/5\text{k} = 1$ mA akar. 2 V'luk kaynak eklenince süperpozisyonla $i_{L2} = 2/5\text{k} + 5/5\text{k} = 1{,}4$ mA olur; $i_{L1}$ yalnız 5 V'luk koldan beslendiği için $-1$ mA kalır.
- Seri RLC'de ikinci türevin kaynağı
  - KVL'de bobin terimi $L\,di/dt$'dir. Seri devrede akım kondansatör akımına eşit olduğundan $i = C\,dv_C/dt$ yazılır. Türevin içinde türev oluşur, yani $LC\,d^2v_C/dt^2$. İkinci derecenin anlamı budur. Bobin olmasaydı yalnız RC terimi kalır ve denklem birinci dereceden olurdu.
- Neden salınım olur?
  - RC ya da RL devresinde direnç enerjiyi tüketir ve cevap üstel olarak sönümlenir. RLC'de kondansatör deşarj olurken bobin bu akımla enerji depolar, bobinin akımı da kondansatörü yeniden şarj edebilir. Bu karşılıklı besleme salınıma yol açar. Direnç ne kadar etkiliyse ($\alpha$ büyük) salınım o kadar bastırılır.
- Üç cevabın karşılaştırılması (ekrandan, 01:25:00)
  - Grafikte üç eğri 1'den başlayıp sıfıra iner. Kritik sönümlü cevap kararlı hale en erken ulaşır. Aşırı sönümlü cevap başta daha hızlı düşer ama sıfıra daha geç oturur. Az sönümlü cevap sıfırın altına ve üstüne salınarak oturur.
  - Kuramsal olarak $R = 0$ olsaydı salınım hiç sönümlenmezdi; gerçekte kablonun bile direnci olduğu için bu olmaz.
- Paralel RLC'de değişken seçimi
  - Seri devrede değişen büyüklük kondansatör gerilimi olduğu için denklem $v_C$ üzerinden yazılır. Paralel devrede değişen büyüklük bobin akımıdır, bu yüzden denklem $i_L$ üzerinden KCL ile yazılır. Genel kural: başlangıç ile son durum arasında hangi büyüklük değişiyorsa denklem onun üzerinden kurulur.
- Ders sonrası notlar
  - Hoca kritik sönümlü cevabı $A_1e^{-\alpha t} + A_2e^{-\alpha t}$ diye yazıp "biraz yanlış olmuş" dedi. Slayttaki doğru biçim $e^{-\alpha t}(A_1 t + A_2)$'dir; çift kökte ikinci çözüm $t e^{-\alpha t}$'dir.
  - Hoca $R = 0$ durumunda sonsuz salınım için "bobin değeri kondansatörden fazlaysa" gibi bir koşul söyledi. $R = 0$ ise $\alpha = 0 < \omega_0$ her zaman sağlanır; $L$ ile $C$ arasında ek bir koşul gerekmez.
  - Hoca paralel devreye geçerken seri devrenin $\alpha$'sını bir yerde "L bölü 2R" diye söyledi; doğrusu $\alpha = R/(2L)$'dir (slayttaki tabloda da böyledir).
  - Hoca $\omega_d$ için "salınımı sönümlendiren parametre" dedi. $\omega_d$ sönümlü doğal frekanstır, yani sönüm altındaki salınımın açısal frekansıdır; sönümü $\alpha$ belirler.
  - Örnek 2'deki akım bir yerde "0,3 amper" diye söylendi; değerler kΩ olduğu için doğrusu 0,3 mA'dir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
