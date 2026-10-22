# Ders 9 Çalışma Özeti

## Genel Konular

- Konu: ikinci dereceden devreler, yani RLC devreleri. Önceki derste RL ve RC devrelerinin zaman domenindeki davranışı (birinci dereceden diferansiyel denklemler) incelenmişti. Bu derste aynı yaklaşım iki enerji depolayan elemanlı devrelere genişletilir.
- Dersin planı:
  - Başlangıç ve son durumların (uç durumlar, boundary conditions) DC analizle bulunması.
  - Kaynaksız (source-free) seri RLC devresi.
  - Kaynaksız paralel RLC devresi.
  - Basamak (step) cevaplı seri RLC devresi.
  - Basamak cevaplı paralel RLC devresi.
- Tekrar: kaynaksız devrelerde çıkan çözüm, diferansiyel denklemin **homojen çözümüdür** (eşittir sıfır hâli). Devrede kaynak varsa ayrıca bir **zorlanmış çözüm** eklenir. Genel çözüm = homojen çözüm + zorlanmış çözüm.
  - Zorlanmış çözüm, denklemin sağ tarafındaki fonksiyon cinsinden önerilir:
    - Sabit (basamak fonksiyonu) için sabit: $A$.
    - Sinüzoidal kaynak için $A\sin(\omega t + \phi)$.
    - Rampa ($at + b$) için polinom önerilir.
- İkinci dereceden devre: devrede en az iki enerji depolayan eleman (L ve C) vardır. Seri RLC, paralel RLC, birbirine kuple iki RLC yapısı, bir direnç üzerinden bağlı iki kapasite gibi devrelerin hepsi ikinci dereceden diferansiyel denklem verir.
- İkinci dereceden denklemde **iki** katsayı bulunacağı için **iki başlangıç koşulu** gerekir: ilgilenilen değişkenin $t_0$ anındaki değeri ve türevinin $t_0$ anındaki değeri.
- Uç durumlar (DC analiz)
  - $-\infty < t < t_0^-$ ve $t \to \infty$ aralıkları DC rejimdir. Pratikte "uzun süre" yaklaşık beş zaman sabiti demektir.
  - DC şartlarda kapasite **açık devre**, endüktans **kısa devre** gibi davranır. Hatırlama yolu: kapasitenin sembolü iki ayrık plaka (açık), endüktansınki bir tel sargısı (kısa).
  - Bu yüzden DC'de $i_C = 0$ ve $v_L = 0$. Geriye kalan direnç-kaynak devresinden $v_C$ ve $i_L$ bulunur.
  - Süreklilik: kaynak devreye girerken veya çıkarken kapasitenin **gerilimi**, endüktansın **akımı** ani değişemez:
    - $v_C(t_0^-) = v_C(t_0^+)$, $i_L(t_0^-) = i_L(t_0^+)$.
    - Hatırlama yolu: $i_C = C\frac{dv_C}{dt}$ ve $v_L = L\frac{di_L}{dt}$. Türevi alınan değişken süreklidir, yoksa sonsuz akım/gerilim gerekirdi.
  - $t_0^+$ ile $\infty$ arasındaki geçici hâl (transient) için eşdeğer devre kullanılmaz. L ve C kendi diferansiyel bağıntılarıyla devrede kalır.
- Uç durum örnekleri
  - Örnek 1: $V_1$, $R_1$ seri; düğümden $R_2$ toprağa; aynı düğümden $L_1$, $R_3$ ve $C_1$ seri bir kol. Anahtar uzun süre kapalı, $t_0$'da açılıyor.
    - $t < t_0$: C açık devre olduğu için $L$-$R_3$-$C$ kolunda akım yok: $i_L = i_C = 0$, $v_L = 0$. $R_3$ üzerinde gerilim düşümü olmadığından $v_C$, $R_2$ geriliminin aynısıdır: $v_C = \frac{V_1 R_2}{R_1 + R_2}$.
    - $t \to \infty$: kaynak devre dışı, bütün değerler sıfır: $i_L = v_L = i_C = v_C = 0$.
    - Arada ($t > t_0$) değerler sıfırdan farklıdır ve üstel fonksiyonlarla değişir.
  - Örnek 2: $V_1 = 2$ V, $R_1 = 5$ kΩ, ortada $C_1$ (toprağa), $L_1 = 10$ µH, $R_2 = 5$ kΩ, $V_2 = 5$ V. Anahtar açılınca sol taraf ($V_1$) devreden çıkıyor.
    - $t < t_0$: L kısa, C açık. Tek çevrede net 3 V ve toplam 10 kΩ: $|i_L| = 0.3$ mA. $v_L = 0$, $i_C = 0$. Orta düğüm $v_C = 2 + 5\text{k} \cdot 0.3\text{m} = 3.5$ V.
    - $t \to \infty$: yalnız $V_2$ kolu kalır, C açık olduğu için akım yok: $i_L = i_C = 0$, $v_L = 0$, $v_C = 5$ V.
  - Örnek 3: aynı devrede C yerine $L_2 = 40$ µH (toprağa), anahtar $t_0$'da kapanıp sol tarafı devreye alıyor.
    - $t < t_0$: yalnız sağ taraf. Orta düğüm L2 kısa devresiyle 0 V: $i_{L1} = -1$ mA, $i_{L2} = 1$ mA, $v_{L1} = v_{L2} = 0$.
    - $t \to \infty$: soldan $2/5\text{k} = 0.4$ mA eklenir: $i_{L1} = -1$ mA, $i_{L2} = 1.4$ mA, gerilimler sıfır.
  - Örnek 4 (ödev): $V_1 = 1$ V, $L_1 = 10$ µH, paralel $C_1 = C_2 = 1$ µF, $R_1 = 1$ kΩ, anahtarlı $V_2 = 5$ V, $R_2 = 3$ kΩ. İki paralel kapasite tek eşdeğer kapasite gibi düşünülebilir. $t = 0$'da sağdaki kaynak devreden çıkıyor.
- Kaynaksız seri RLC devresi
  - Kaynak $V_s[1 - u(t - t_0)]$: $t_0$'a kadar devrede, sonra sıfırlanıyor. Örnek değerler: $R = 2$ kΩ, $L = 10$ µH, $C = 3$ µF.
  - Başlangıç ($t < t_0$, DC): $v_L = 0$, $i_L = i_C = 0$, $v_C = V_s$. Süreklilikten $v_C(t_0^+) = V_s$, $i_L(t_0^+) = 0$.
  - $t > t_0$ için çevre denklemi (KVL): $v_R + v_L + v_C = 0$. Seri devrede tek akım var, bu akım kapasitenin gerilim değişimiyle belirlenir: $i = C\frac{dv_C}{dt}$.
    - $v_R = RC\frac{dv_C}{dt}$, $v_L = LC\frac{d^2 v_C}{dt^2}$.
    - $LC\,v_C'' + RC\,v_C' + v_C = 0$, yani $v_C'' + \frac{R}{L}v_C' + \frac{1}{LC}v_C = 0$.
  - İkinci türev, birinci türev ve kendisi doğrusal bağımlı bir fonksiyon aranır: $v_C = Ae^{st}$. Yerine konunca karakteristik denklem çıkar ($A = 0$ trivial çözüm istenmez):
    - $s^2 + \frac{R}{L}s + \frac{1}{LC} = 0$, $s_{1,2} = -\frac{R}{2L} \pm \sqrt{\left(\frac{R}{2L}\right)^2 - \frac{1}{LC}}$.
  - İki çözüm bulunduğu için genel homojen çözüm bunların doğrusal birleşimidir: $v_C(t) = A_1e^{s_1t} + A_2e^{s_2t}$.
  - $A_1$, $A_2$ başlangıç koşullarından: $v_C(0) = V_s$ ve $i_C(0) = C\,v_C'(0) = 0$. Yani $A_1 + A_2 = V_s$ ve $s_1A_1 + s_2A_2 = 0$.
  - $v_C$ bulununca: $i = i_C = i_L = i_R = C\,v_C'$, $v_L = L\,\frac{di}{dt}$, $v_R = Ri$.
  - Kaynak $t_0$'da kesiliyorsa denklemlerde $t$ yerine $t - t_0$ yazılır.
- Kök durumları (sönüm türleri)
  - Kısaltmalar: $\alpha = \frac{R}{2L}$ (seri), $\omega_0 = \frac{1}{\sqrt{LC}}$ (sönümsüz doğal frekans). $s_{1,2} = -\alpha \pm \sqrt{\alpha^2 - \omega_0^2}$.
  - $\alpha > \omega_0$: iki farklı reel kök, **aşırı sönümlü (overdamped)**. $A_1e^{s_1t} + A_2e^{s_2t}$.
  - $\alpha = \omega_0$: katlı kök, **kritik sönümlü (critically damped)**. İki çözüm için ikinci çözüm $t$ ile çarpılır: $e^{-\alpha t}(A_1 + A_2t)$.
    - Gerekçe: $Ate^{\alpha t}$'nin türevi $Ae^{\alpha t}(1 + \alpha t)$'dir, yine kendisiyle doğrusal bağımlıdır. Genel olarak $n$ katlı kökte $e^{\alpha t}, te^{\alpha t}, t^2e^{\alpha t}, \ldots$ önerilir (ör. 4 katlı kökte 4 çözüm).
  - $\alpha < \omega_0$: karmaşık eşlenik kökler $s_{1,2} = -\alpha \pm j\omega_d$, **az sönümlü (underdamped)**. $\omega_d = \sqrt{\omega_0^2 - \alpha^2}$.
    - Euler formülü $e^{j\theta} = \cos\theta + j\sin\theta$ ile: $e^{-\alpha t}(B_1\cos\omega_dt + B_2\sin\omega_dt)$, $B_1 = A_1 + A_2$, $B_2 = j(A_1 - A_2)$.
    - Aynı frekanslı iki sinüzoidalin toplamı tek bir $B\cos(\omega_dt + \phi)$ olarak da yazılabilir. İki bilinmeyen yine iki tanedir ($B$ ve $\phi$).
    - Sonuç: üstel olarak azalan bir zarf içinde salınan sinüzoidal.
    - $R = 0$ ise $\alpha = 0$, $\omega_d = \omega_0$: hiç sönümlenmeyen salınım (pratikte imkânsız, her telde direnç var).
  - Kritik sönümlü durum, steady state'e (son değere) **en hızlı** oturan durumdur. Az sönümlü salınarak, aşırı sönümlü yavaşça oturur.
- Kaynaksız paralel RLC devresi
  - $t_0$'a kadar bir akım kaynağı $I_s$ devrede, $t_0$'da kaynak devreden çıkarılıyor.
  - Başlangıç (DC): L kısa devre olduğu için bütün akım ondan geçer: $i_L(t_0^-) = I_s$. $v_L = v_C = 0$, $i_C = i_R = 0$. Enerjiyi yalnız endüktans depolamıştır.
  - $t \to \infty$: kaynak yok, bütün değerler sıfır.
  - $t > t_0$ için düğüm denklemi (KCL): $\frac{v}{R} + i_L + C\frac{dv}{dt} = 0$, $v = L\frac{di_L}{dt}$.
    - $i_L'' + \frac{1}{RC}i_L' + \frac{1}{LC}i_L = 0$. Paralel devrede pratik olan, denklemi **endüktans akımı** cinsinden yazmaktır (serideki $v_C$'nin karşılığı).
    - $s_{1,2} = -\frac{1}{2RC} \pm \sqrt{\left(\frac{1}{2RC}\right)^2 - \frac{1}{LC}}$, yani $\alpha = \frac{1}{2RC}$, $\omega_0 = \frac{1}{\sqrt{LC}}$.
  - Aynı üç sönüm durumu ve aynı çözüm biçimleri geçerlidir.
  - Diğer değerler: $v = L\,i_L'$ (bütün elemanların gerilimi), $i_C = C\,v'$, $i_R = v/R$.
  - Salınım frekansı veya üstel terim frekansı, devredeki bütün akım ve gerilimler için aynıdır.
- Özet tablo (kaynaksız RLC)

  | Durum | Koşul | Cevap |
  |---|---|---|
  | Aşırı sönümlü | $\alpha > \omega_0$ | $A_1e^{s_1t} + A_2e^{s_2t}$, $s_{1,2} = -\alpha \pm \sqrt{\alpha^2 - \omega_0^2}$ |
  | Kritik sönümlü | $\alpha = \omega_0$ | $e^{-\alpha t}(A_1t + A_2)$ |
  | Az sönümlü | $\alpha < \omega_0$ | $e^{-\alpha t}(B_1\cos\omega_dt + B_2\sin\omega_dt)$, $\omega_d = \sqrt{\omega_0^2 - \alpha^2}$ |

  - Seri: $\alpha = \frac{R}{2L}$, cevap $v_C(t)$. Paralel: $\alpha = \frac{1}{2RC}$, cevap $i_L(t)$. İkisinde de $\omega_0 = \frac{1}{\sqrt{LC}}$.
- Basamak cevaplı seri RLC devresi
  - $t_0$'a kadar kaynak yok: bütün başlangıç değerleri sıfır ($v_C = i_L = 0$). $t_0$'da $V_s$ devreye girer.
  - $t \to \infty$: C açık, L kısa: $v_C(\infty) = V_s$, $i_L(\infty) = 0$ (hoca önce $i_L = V_s/R$ dedi, sonra düzeltti).
  - KVL: $-V_s + v_R + v_L + v_C = 0$, yani $v_C'' + \frac{R}{L}v_C' + \frac{1}{LC}v_C = \frac{V_s}{LC}$.
  - Homojen çözüm (kaynaksız durumla aynı) + zorlanmış çözüm. Sağ taraf sabit olduğu için zorlanmış çözüm $v_{C,z} = A$: $\frac{A}{LC} = \frac{V_s}{LC}$, yani $A = V_s$ (hoca önce $V_sLC$ yazıp düzeltti).
  - Genel çözüm (aşırı sönümlü için): $v_C(t) = A_1e^{s_1t} + A_2e^{s_2t} + V_s$. Kritik ve az sönümlü durumlarda homojen kısım tablodaki biçimlerle değişir.
  - $A_1$, $A_2$: $v_C(0) = 0 \Rightarrow A_1 + A_2 + V_s = 0$ ve $i_L(0) = C\,v_C'(0) = 0 \Rightarrow s_1A_1 + s_2A_2 = 0$.
- Basamak cevaplı paralel RLC devresi
  - Anahtar $t_0$'a kadar kapalı ve akım kaynağını kısa devre ediyor. Başlangıç değerleri sıfır. Anahtar açılınca $I_s$ devreye girer.
  - $t \to \infty$: L kısa devre, $i_L(\infty) = I_s$, diğerleri sıfır.
  - KCL: $i_L'' + \frac{1}{RC}i_L' + \frac{1}{LC}i_L = \frac{I_s}{LC}$. Zorlanmış çözüm $A = I_s$.
  - Genel çözüm: $i_L(t) = A_1e^{s_1t} + A_2e^{s_2t} + I_s$. $i_L(0) = 0 \Rightarrow A_1 + A_2 + I_s = 0$; $v_C(0) = L\,i_L'(0) = 0 \Rightarrow s_1A_1 + s_2A_2 = 0$.
  - Örnek değerler: $R = 2$ kΩ, $L = 10$ µH, $C = 3$ µF.
- Sinüzoidal kaynaklı durumlar ve geçici hâl bittikten sonraki sürekli sinüzoidal hâl gelecek haftaki **fazör** konusunun içeriğidir. Laplace dönüşümüne zaman kalmayabilir.
- Duyurular: bu konunun deneyi bir hafta ertelendi, gelecek hafta yapılacak. 3 Haziran haftasında kısa sınav var, fazörler de muhtemelen dahil. Kısa sınav ve finalde RL, RC ve RLC devreleri hem zaman hem fazör domeninde sorulacak.

## Hocanın Özellikle Vurguladığı Kısımlar

- DC'de kapasite açık devre, endüktans kısa devre. Kapasitenin gerilimi, endüktansın akımı süreklidir.
- İkinci dereceden devrede iki başlangıç koşulu gerekir: değişkenin değeri ve türevi. Seri devrede $v_C(t_0)$ ve $i_L(t_0)$ (türev akımla ilişkili), paralel devrede $i_L(t_0)$ ve $v_C(t_0)$ (türev gerilimle ilişkili) kullanılır.
- **Çok önemli:** Zorlanmış çözüm varsa başlangıç koşulları **genel çözüme** (homojen + zorlanmış) konarak $A_1$, $A_2$ bulunur. Yalnız homojen çözüme konursa zorlanmış çözüm hesaba katılmamış olur ve sonuç yanlış çıkar.
- Pratikte yapılacak iş: (1) devre seri mi paralel mi, (2) kaynaksız mı basamak cevaplı mı, (3) kökler hangi durumda (aşırı/kritik/az sönümlü) belirlenip uygun genel çözüm seçilir, (4) başlangıç koşullarıyla katsayılar bulunur. Parça parça verilen tabloları birleştirip yanınızda referans olarak bulundurun.
- RL, RC ve RLC devreleriyle ilgili bol pratik yapın.

## Kısa Tekrar Notları

- Seri RLC: $v_C'' + \frac{R}{L}v_C' + \frac{1}{LC}v_C = \frac{V_s}{LC}$ (kaynaksızda sağ taraf 0). $\alpha = \frac{R}{2L}$.
- Paralel RLC: $i_L'' + \frac{1}{RC}i_L' + \frac{1}{LC}i_L = \frac{I_s}{LC}$. $\alpha = \frac{1}{2RC}$.
- $\omega_0 = \frac{1}{\sqrt{LC}}$, $\omega_d = \sqrt{\omega_0^2 - \alpha^2}$.
- $\alpha > \omega_0$ aşırı, $\alpha = \omega_0$ kritik, $\alpha < \omega_0$ az sönümlü.
- Basamak cevabı: genel çözüm = homojen + son değer ($V_s$ veya $I_s$).

## Detaylı Açıklamalar

### Sönüm durumları neden böyle adlandırılır?

- Aşırı sönümlüde iki reel negatif kök vardır. Yavaş olan kök (mutlak değeri küçük olan) cevabı belirler, bu yüzden devre son değere geç oturur.
- Kritik sönümlüde iki kök çakışır. Salınım olmadan oturabilecek en hızlı durum budur.
- Az sönümlüde kökler karmaşıktır. Cevap son değerin etrafında salınır, zarf $e^{-\alpha t}$ ile söner.

### Ders sonrası notlar

- **Ders içi sayısal kontrol (Python):**
  - Seri örnek ($R = 2$ kΩ, $L = 10$ µH, $C = 3$ µF): $\alpha = 10^8$ s⁻¹, $\omega_0 \approx 1.83 \times 10^5$ rad/s. $\alpha > \omega_0$, **aşırı sönümlü**. Kökler $s_1 \approx -2 \times 10^8$, $s_2 \approx -166.7$ s⁻¹. Kaynaksız durumda $A_1 \approx -8.3 \times 10^{-7}V_s$, $A_2 \approx V_s$; yani pratikte $v_C(t) \approx V_se^{-166.7t}$ (zaman sabiti ≈ 6 ms).
  - Paralel örnek (aynı değerler): $\alpha = \frac{1}{2RC} \approx 83.3$ s⁻¹ $< \omega_0$, **az sönümlü**, $\omega_d \approx 1.83 \times 10^5$ rad/s (≈ 29 kHz). Basamak cevabı (derste yazılmadı): $i_L(t) = I_s\left[1 - e^{-83.3t}\left(\cos\omega_dt + 4.6 \times 10^{-4}\sin\omega_dt\right)\right]$. Aynı R, L, C değerleri seri ve paralel bağlamada tamamen farklı sönüm türleri verir.
- **Örnek 2'de akımın işareti:** Derste bir öğrenci $i_L$'nin eksi olması gerektiğini söyledi, hoca "doğru, eksi yönlü olur" diye onayladı. Slaytta ise $i_L(-\infty) = 0.3$ mA yazıyor. İki kaynağın da artı ucu üstte ise net akım 5 V'tan 2 V'a, yani sağdan sola akar. $i_L$ oku sağa doğru tanımlandığı için doğrusu $i_L(-\infty) = -0.3$ mA'dir. $v_C = 3.5$ V sonucu bundan etkilenmez ($2 + 1.5 = 5 - 1.5 = 3.5$ V).
- **Basamak cevabında ikinci denklem:** Derste bir an $A_1s_1 + A_2s_2 + V_s = 0$ yazıldı. Sabit terimin ($V_s$) türevi sıfırdır, doğrusu $s_1A_1 + s_2A_2 = 0$'dır (slayttaki ve paralel durumdaki denklem de böyledir).
- **Kök ifadesindeki yazım:** Derste bir yerde üs $-\frac{R}{L}$ olarak yazıldı. Doğru kök $-\frac{R}{2L} \pm \sqrt{\left(\frac{R}{2L}\right)^2 - \frac{1}{LC}}$'dir. Ayrıca uç durumlar sayılırken "$t = \infty$, $t_0^-$, $t_0^+$, $t = \infty$" dendi; ilki $t = -\infty$ olmalıdır.
- **Örnek 4'ün cevabı (kontrol için, derste çözülmedi):** Kaynakların artı uçlarının üstte olduğu ve sağdaki kaynağın $t = 0$'da devreden çıktığı varsayımıyla: $t < 0$'da üst düğüm 4 V, $i_L = -1$ mA (ok yönüne göre), $v_C = 4$ V, $v_L = 0$, $i_{C1} = i_{C2} = 0$. $t \to \infty$'da yalnız $V_1$ kalır, C açık olduğu için akım yok: $i_L = 0$, $v_C = 1$ V. Slayt hem "uzun süre kapalı" hem "$t = 0$'da kapanıyor" diyor; hoca derste sağdaki kaynağın devreden çıktığını söyledi.
- **"Kritik sönüm en hızlı oturur" ifadesi:** Bu, salınım yapmadan oturan durumlar arasında doğrudur. Az sönümlü bir devre son değere ilk kez daha erken ulaşabilir ama etrafında salınır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
