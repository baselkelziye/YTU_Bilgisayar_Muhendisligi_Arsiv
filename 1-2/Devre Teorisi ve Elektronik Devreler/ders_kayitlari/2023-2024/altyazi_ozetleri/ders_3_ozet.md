# Ders 3 Çalışma Özeti

## Genel Konular

- Duyurular
  - Hoca o hafta Ankara'da olduğu için ders online yapıldı. Hoca dersi ilk kez tablet üzerinden anlattı. Bulunduğu ortam nedeniyle kısık sesle konuştu; bazı öğrenciler sesi düşük duyduğunu yazdı.
  - Gelecek hafta Yunus Hoca soru çözümü yapacak: RL, RC, RLC ve Thevenin/Norton konularından. Katılım çok önemli. Ders büyük olasılıkla yüz yüze olacak; online olursa Classroom'dan duyurulacak.
  - Vizeler bayramdan hemen sonra. Bayramda çalışın. Bölüm, pazartesi gününü vize için boş bırakmaya çalıştı, salı günü sınav var. Servis derslerinin sınavlarına bölüm müdahale edemiyor.
  - Dualite konusu işlenmeyecek, sorumlu değilsiniz.
- Birinci ve ikinci dereceden devreler
  - RC ve RL devrelerinde tek bir enerji depolayan eleman (bir kondansatör veya bir bobin) vardı. Kondansatörde $i_C = C\frac{dv_C}{dt}$, bobinde $v_L = L\frac{di_L}{dt}$ ilişkisinden birinci dereceden diferansiyel denklem çıkıyordu.
  - Devrede iki enerji depolayan eleman (bir L ve bir C, iki C veya iki L) olunca türevin türevi alınmak zorunda kalınır ve **ikinci dereceden** (second order) denklem oluşur.
- Sınır koşulları (boundary conditions)
  - Önce geçiş anından ($t_0$) çok önceki (initial) ve çok sonraki (final) durumlar bulunur. Bu, grafiğin nereden başlayıp nereye gittiğini gösterir. Aradaki geçişin (transient) şekli ayrıca incelenir.
  - Kurallar (DC kaynaklı, sürekli rejimde):
    - Kondansatör **açık devre** kabul edilir.
    - Bobin **kısa devre** kabul edilir.
  - Kaynakların sabit olduğu ve geçiş anında kondansatör gerilimi ile bobin akımının sıçramadığı varsayılır.
  - Kaynak çıkarıldı diye her zaman sıfıra gidilmez. Devrede başka bir kaynak varsa son değer o kaynağa göre belirlenir.
  - Örnek 1 (slayt 8): $V_1$ – $R_1$ – düğüm; düğümden toprağa $R_2$; düğümden $L_1$ ve $R_3$ üzerinden $C_1$'e. Anahtar uzun süre kapalı, $t_0$'da açılıyor.
    - Önce: bobin kısa, kondansatör açık. $L_1$ kolundan akım geçmez, $i_L = 0$. $C_1$, $R_2$ üzerindeki gerilime şarj olur: $v_C = V_1\frac{R_2}{R_1 + R_2}$ (gerilim bölücü).
    - Sonra: kaynak kalmadığı için kondansatör $R_3$, $L_1$, $R_2$ üzerinden boşalır. $v_C(\infty) = 0$, $i_L(\infty) = 0$.
  - Örnek 2 (slayt 12-13): $V_1 = 2$ V (anahtarla), $R_1 = 5$ kΩ, $C_1 = 1$ µF, $L_1 = 10$ µH, $R_2 = 5$ kΩ, $V_2 = 5$ V. Anahtar $t_0$'da açılıyor.
    - Önce: iki kaynak zıt yönlü, net 3 V, toplam direnç 10 kΩ. Akım 0.3 mA. $v_C = 2 + 5\text{k} \cdot 0.3\text{m} = 3.5$ V. $v_L = 0$, $i_C = 0$.
    - Sonra: yalnızca $V_2$ kalır, kondansatör açık devre olduğu için akım yok. $v_C(\infty) = 5$ V, $i_L(\infty) = 0$.
    - Grafik 3.5 V'tan başlayıp 5 V'ta oturur.
  - Örnek 3 (slayt 14): $V_1 = 2$ V (anahtarla), $R_1 = 5$ kΩ, düğümden toprağa $L_2 = 40$ µH, düğümden $L_1 = 10$ µH ve $R_2 = 5$ kΩ üzerinden $V_2 = 5$ V. Anahtar $t_0$'da kapanıyor.
    - Önce: yalnız $V_2$ var. $L_2$ kısa devre olduğu için $V_2$, $R_2$ üzerinden 1 mA akıtır. $i_{L1} = -1$ mA (ok yönüne göre), $i_{L2} = 1$ mA, $v_{L1} = v_{L2} = 0$.
    - Sonra: $V_1$ de $R_1$ üzerinden kısa devre düğümüne 0.4 mA ekler. $i_{L1}$ yine $-1$ mA, $i_{L2} = 1.4$ mA.
  - Örnek 4 (slayt 17): $V_1 = 1$ V, $L_1 = 10$ µH, paralel $C_1 = C_2 = 1$ µF, $R_1 = 1$ kΩ, $V_2 = 5$ V (anahtarla), $R_2 = 3$ kΩ. Hoca $V_2$'nin $t = 0$'da devreden çıkarıldığı senaryoyu çözdü.
    - Önce: net $5 - 1 = 4$ V, toplam direnç 4 kΩ, akım 1 mA. $i_L = -1$ mA, $v_C = 4$ V.
    - Sonra: yalnız 1 V kalır, akım yok. $v_C(\infty) = 1$ V, $i_L(\infty) = 0$.
- Geçişin üç biçimi
  - İki enerji depolayan eleman enerjiyi birbirine aktarır: kondansatör boşalırken bobini, bobin boşalırken kondansatörü besler. Bu yüzden sistem salınım yapabilir.
  - Aşırı sönümlü (overdamped): başta hızlı değişir ama son değere geç oturur. Salınım yok.
  - Kritik sönümlü (critically damped): salınım yapmadan son değere en hızlı oturan durum.
  - Az sönümlü (underdamped): son değer etrafında salınım yaparak, zamanla sönümlenerek oturur.
- Kaynaksız seri RLC (source-free series RLC)
  - Kondansatör $V_s$'ye şarjlı, kaynak $t_0$'da çıkarılıyor. Başlangıç: $v_C = V_s$, akım 0. Son: her şey 0.
  - KVL: $v_C + Ri + L\frac{di}{dt} = 0$, seri devrede $i = C\frac{dv_C}{dt}$. Yerine konunca:
    - $LC\frac{d^2v_C}{dt^2} + RC\frac{dv_C}{dt} + v_C = 0$, yani $\frac{d^2v_C}{dt^2} + \frac{R}{L}\frac{dv_C}{dt} + \frac{1}{LC}v_C = 0$.
  - Çözüm $v_C(t) = Ae^{st}$ kabul edilir. Yerine konunca karakteristik denklem çıkar: $s^2 + \frac{R}{L}s + \frac{1}{LC} = 0$. Bu, $ax^2 + bx + c$ biçimindedir ve diskriminantla çözülür.
  - Parametreler:
    - $\alpha = \frac{R}{2L}$: sönüm katsayısı (damping factor). Direnç büyüdükçe artar.
    - $\omega_0 = \frac{1}{\sqrt{LC}}$: sönümsüz doğal frekans (rezonans frekansı). Yalnız L ve C'ye bağlıdır.
    - Karakteristik denklem: $s^2 + 2\alpha s + \omega_0^2 = 0$.
    - Kökler: $s_{1,2} = -\alpha \pm \sqrt{\alpha^2 - \omega_0^2}$.
  - Genel çözüm: $v_C(t) = A_1e^{s_1t} + A_2e^{s_2t}$.
  - $A_1$ ve $A_2$ başlangıç koşullarından bulunur:
    - $t = 0$'da $v_C(0) = V_s$: $A_1 + A_2 = V_s$.
    - $i_C(0) = C\frac{dv_C}{dt}(0) = 0$: $s_1A_1 + s_2A_2 = 0$.
    - İki bilinmeyen, iki denklem.
  - Durumlar:
    - $\alpha > \omega_0$ (seri devrede $C > \frac{4L}{R^2}$): aşırı sönümlü. İki gerçek, negatif kök.
    - $\alpha = \omega_0$ ($C = \frac{4L}{R^2}$): kritik sönümlü. Tek (çift) kök $s = -\alpha$.
    - $\alpha < \omega_0$ ($C < \frac{4L}{R^2}$): az sönümlü. Kökün içi negatif, karmaşık kökler: $s_{1,2} = -\alpha \pm j\omega_d$, $\omega_d = \sqrt{\omega_0^2 - \alpha^2}$ (sönümlü doğal frekans). $e^{j\omega_dt} = \cos\omega_dt + j\sin\omega_dt$ olduğu için cevapta sinüs ve kosinüs, yani salınım çıkar.
  - Direnç büyükse $\alpha$ büyür, enerji dirençte çabuk harcanır, L ve C birbirini besleyemez: aşırı sönüm. Direnç küçükse L ve C birbirini besler: salınım.
- Kaynaksız paralel RLC
  - Akım kaynağı $I_s$ çıkarılıyor. Başlangıçta bobin kısa devre olduğu için $i_L = I_s$, sonra 0'a iner.
  - KCL: $\frac{v}{R} + i_L + C\frac{dv}{dt} = 0$, $v = L\frac{di_L}{dt}$. Sonuç: $\frac{d^2i_L}{dt^2} + \frac{1}{RC}\frac{di_L}{dt} + \frac{1}{LC}i_L = 0$.
  - Değişen tek şey sönüm katsayısıdır: $\alpha = \frac{1}{2RC}$. $\omega_0 = \frac{1}{\sqrt{LC}}$ aynıdır.
  - Üç durum ve kök formülleri seri devreyle aynıdır.
- Basamak cevabı (step response)
  - Devrede kaynak yokken $t = 0$'da kaynak bağlanıyor.
  - Seri RLC: $v_C$ 0'dan başlayıp $V_s$'ye gider. Diferansiyel denklemin sağ tarafına $\frac{V_s}{LC}$ gelir. $\alpha$ ve $\omega_0$ aynıdır. Çözüme son değer eklenir: $v_C(t) = V_s + (\text{geçici kısım})$.
  - Paralel RLC: $i_L$ 0'dan başlayıp $I_s$'ye gider. Çözüme $I_s$ eklenir.
- RLC devreleri devre teorisinin en zor konusudur ama anlaşılması çok önemlidir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sınır koşullarında kondansatör açık devre, bobin kısa devre.
- Kaynak çıkınca her şey sıfıra gitmeyebilir. Başka kaynak varsa son değeri o belirler.
- Hangi durumun oluşacağına $\alpha$ ile $\omega_0$ karşılaştırılarak karar verilir.
- Seri ve paralel devrede yalnızca $\alpha$ değişir.
- Formüllerin nasıl çıktığını evde kendiniz türetin. Gelecek haftaki soru çözümüne mutlaka katılın.

## Kısa Tekrar Notları

- DC sürekli rejim: C açık, L kısa.
- Seri RLC: $\alpha = \frac{R}{2L}$. Paralel RLC: $\alpha = \frac{1}{2RC}$. İkisinde de $\omega_0 = \frac{1}{\sqrt{LC}}$.
- $s_{1,2} = -\alpha \pm \sqrt{\alpha^2 - \omega_0^2}$.
- Aşırı sönüm ($\alpha > \omega_0$): $v(t) = A_1e^{s_1t} + A_2e^{s_2t}$.
- Kritik sönüm ($\alpha = \omega_0$): $v(t) = (A_1 + A_2t)e^{-\alpha t}$.
- Az sönüm ($\alpha < \omega_0$): $v(t) = e^{-\alpha t}(B_1\cos\omega_dt + B_2\sin\omega_dt)$, $\omega_d = \sqrt{\omega_0^2 - \alpha^2}$.
- Basamak cevabında son değer ($V_s$ veya $I_s$) çözüme eklenir.

## Detaylı Açıklamalar

### Kritik sönümde neden $t$ çarpanı var?

- Kökler eşit olunca ($s_1 = s_2 = -\alpha$) $A_1e^{s_1t} + A_2e^{s_2t}$ aslında tek bir terime ($(A_1 + A_2)e^{-\alpha t}$) iner. Bu durumda iki başlangıç koşulunu birlikte sağlayamaz.
- İkinci bağımsız çözüm $te^{-\alpha t}$'dir. Bu yüzden genel çözüm $(A_1 + A_2t)e^{-\alpha t}$ biçimindedir. Hocanın "A1 ile A2'lerde T'yi çarpacağız" sözü bu çarpanı anlatıyor.

### Ders sonrası notlar

- **Örneklerin kontrolü:** Örneklerin sınır değerleri ders sonrasında devreler yeniden çözülerek kontrol edildi. Örnek 2 (3.5 V → 5 V), Örnek 3 ($i_{L2}$: 1 mA → 1.4 mA) ve Örnek 4 (4 V → 1 V) doğrudur.
- **Örnek 2'de akım işareti:** Slaytta $i_L(-\infty) = 0.3$ mA yazıyor. Akım $V_2$'den $V_1$'e doğru, yani slayttaki ok yönünün tersine akar. Ok yönüne göre doğrusu $-0.3$ mA'dır. Hoca da derste bunu belirtti.
- **Slayt metinleri:** Örnek 3'te "uzun süre açık, $t_0$'da açılıyor", Örnek 4'te "uzun süre kapalı, $t = 0$'da kapanıyor" yazıyor. Bu ifadeler kendi içinde çelişkili. Şekildeki anahtar işaretine ve hocanın anlatımına göre Örnek 3'te anahtar $t_0$'da kapanıyor, Örnek 4'te $V_2$ $t = 0$'da devreden çıkıyor.
- **Sönüm durumunun karıştırılması:** Hoca bir yerde "alfa çok büyükse underdamped" dedi. Doğrusu: $\alpha > \omega_0$ ise **aşırı** sönümlüdür (overdamped). Az sönüm (underdamped) $\alpha < \omega_0$ durumudur. Hoca ilerleyen kısımda doğrusunu anlattı.
- **Grafik yorumu:** Slayttaki grafikte (1'den 0'a inen üç eğri) kritik sönümlü eğri başta en yavaş düşer ama salınım yapmadan son değere en çabuk oturur. Aşırı sönümlü eğri başta çok hızlı düşer, sonra yavaşlar ve geç oturur. Az sönümlü eğri sıfırın altına inip salınır.
- **$\omega_0$ ve salınım:** Hoca "$\omega_0$ ne kadar yüksekse o kadar salınım yapar" dedi. Salınımın olup olmayacağını tek başına $\omega_0$ değil, $\alpha$ ile $\omega_0$'ın karşılaştırması belirler. Salınım varsa frekansı $\omega_d$'dir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
