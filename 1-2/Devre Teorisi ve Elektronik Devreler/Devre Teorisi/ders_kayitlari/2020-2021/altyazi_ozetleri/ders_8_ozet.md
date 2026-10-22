# Ders 8 Çalışma Özeti

## Genel Konular

- Kayıt tarihi: 6 Mayıs 2021 Perşembe. Kayıt iki dosyadan oluşuyor ve yaklaşık 5 saat 42 dakika sürüyor.
- Kaydın ilk yaklaşık 2 saat 56 dakikası laboratuvar oturumudur (Lab 3). Dr. Erkan Uslu'nun dersi 02:57'de başlar.
- Lab 3: Thevenin ve Norton eşdeğerleri (laboratuvar asistanı anlattı, soruyu Kübra Hoca hazırladı)
  - Soru Google Classroom'dan paylaşıldı. Simülasyon Proteus ile yapıldı.
  - Isınma örneği: 12 V kaynak ve seri 3 Ω. Ardından 6 Ω paralel kol, 1 A akım kaynağı paralel kol, seri 8 Ω ve a-b uçları.
    - $R_{TH}$: gerilim kaynağı kısa devre, akım kaynağı açık devre yapılır. $R_{TH} = 8 + (3 \parallel 6) = 8 + 2 = 10$ Ω.
    - $V_{TH}$: a-b açıkken 8 Ω'dan akım geçmez. Düğüm denklemi $\dfrac{V_{TH} - 12}{3} + \dfrac{V_{TH}}{6} - 1 = 0$, $V_{TH} = 10$ V.
    - Norton: $I_N = V_{TH}/R_{TH} = 1$ A, paralel 10 Ω.
  - Laboratuvar görevi: Proteus'ta içi kapalı bir kutu (2 direnç, 2 kapasite, 2 bobin) veriliyor.
    - DC'de kapasite açık devre, bobin kısa devre kabul edilir.
    - Kutunun Thevenin/Norton eşdeğeri bulunur ve istenen dirençler (ör. $R_3$, $R_4$) eşdeğeri sağlayacak şekilde seçilir.
    - Ölçümlerin ekran görüntüleri alınır. $R_{TH}$ ölçümünde bağımsız kaynaklar sıfırlanır, uçlara 1 V'luk bir test kaynağı bağlanır.
  - Süre 19:30 olarak başladı, soru geç paylaşıldığı için 20:00'ye uzatıldı. Gönderimler Kübra Hoca'nın e-postasına gidiyor.
  - Proteus sürüm uyumsuzluğu yaşayanlara ücretsiz/çevrimiçi sürüm önerildi. Elle yazılan çözümlerin okunaklı olması istendi.
- Vize cevaplarının değerlendirilmesi (10 çoktan seçmeli soru)
  - Q1, çevre analizi: 50 V kaynak, 10 Ω ($i_x$), paralel 3 A ve $v_x/4$ akım kaynakları, 2 Ω ($v_x$), 5 Ω ve $4i_x$ bağımlı gerilim kaynağı.
    - İki paralel akım kaynağı tek kaynakta birleştirilir. Cevap: $v_x = -4$ V, $i_x = 2.105$ A (C).
  - Q2, düğüm analizi: 20 V kaynakla süpernode (1-2), $3v_x$ bağımlı kaynakla süpernode (3-4). $v_x$, 1 ile 4 arasındaki 3 Ω'un gerilimi.
    - Düğüm gerilimleri: $V_1 = 26.67$, $V_2 = 6.67$, $V_3 = 173.33$, $V_4 = -46.67$ V.
  - Q3, Thevenin: devrede yalnızca bağımlı kaynaklar var.
    - Bağımsız kaynak olmadığı için $V_{TH} = 0$. $R_{TH}$ test kaynağıyla bulunur: $R_{TH} = 31.73$ Ω (D).
    - En sık hata: bağımlı kaynakları da sıfırlamak.
  - Q4, merdiven devresi: 28 V, 8 Ω seri, 12 Ω ($v_1$), 6 Ω, 15 Ω, 4 Ω, 10 Ω, 2 Ω ve 13 Ω ($v_2$).
    - Sağdan sola sadeleştirme, sonra gerilim bölücüler. $v_1 = 12$ V, $v_2 = 3.12$ V (B).
  - Q5, doğrusallık: $i = a\,i_{s1} + b\,i_{s2}$.
    - $5a + 5b = 0$ ve $8a + 6b = 4$. Buradan $a = 2$, $b = -2$.
    - $i_{s1} = 3$, $i_{s2} = 4$ A için $i = 6 - 8 = -2$ A (A).
  - Q6: kutudaki beş direncin yapısı. Uçlar arası direnç değerleri $R_{AB} = 1.5$, $R_{BC} = 3$, $R_{AC} = 2.5$ Ω. Cevap E.
  - Q7, süperpozisyon: 5 Ω ($v$), aşağı yönlü 3 A kaynak, 10 Ω ve 15 V kaynak.
    - Yalnız 3 A: $v = -3\cdot(5 \parallel 10) = -10$ V. Yalnız 15 V: $v = 15\cdot\frac{5}{15} = 5$ V. Toplam $-5$ V (D).
  - Q8, eşdeğer kapasite: cevap 2 F (D).
  - Q9: 3 H bobinin akımı yamuk biçiminde ($-1$ ile 0 s arası 0'dan 1 A'e çıkar, 0-2 s sabit, 2-3 s arası 0'a iner).
    - $v = L\,di/dt$: $+3$ V, 0, $-3$ V (C).
  - Q10: 48 V kaynak, 6 Ω, 4 Ω, 2 Ω'lu devre. Üstteki 6 Ω kısa devre, açık uca bağlı 4 Ω'dan akım akmaz.
    - Cevap: $I = 6$ A, $V = 6$ V (E).
- DC kararlı hal
  - DC'de uzun süre kalan kapasite açık devre, bobin kısa devre gibi davranır.
  - Teoride "sonsuz süre", pratikte $5\tau$ yeterlidir.
- Kaynaksız (source-free) RC devresi
  - Başlangıç gerilimi $V_0$ olan $C$, $R$ üzerinden boşalır. KCL: $C\dfrac{dv}{dt} + \dfrac{v}{R} = 0$.
  - Çözüm önerisi $A e^{\alpha t}$. $\alpha = -\dfrac{1}{RC}$, $A = V_0$.
  - $v_C(t) = V_0 e^{-t/RC}$. Anahtar $t_0$ anında açılırsa $v_C(t) = V_0 e^{-(t-t_0)/RC}$.
  - Akım $i_R = \dfrac{V_0}{R}e^{-t/\tau}$. Dirençteki güç $p = \dfrac{V_0^2}{R}e^{-2t/\tau}$.
  - Dirençte harcanan enerji: $w_R(t) = \tfrac12 C V_0^2\left(1 - e^{-2t/\tau}\right)$.
- Kaynaksız RL devresi
  - Başlangıç akımı $I_0$ olan bobin. KVL: $L\dfrac{di}{dt} + Ri = 0$.
  - $i_L(t) = I_0 e^{-Rt/L}$.
- Zaman sabiti $\tau$
  - RC için $\tau = R_{TH}C$, RL için $\tau = L/R_{TH}$.
  - $R_{TH}$, kapasite veya bobinin uçlarından bakılarak bulunan Thevenin direncidir.
  - $t = \tau$ anında değer başlangıcın $e^{-1} \approx 0.368$ katına, yani %36.8'ine düşer.
  - $t = 5\tau$ anında $e^{-5} \approx 0.0067$ katına düşer. Geçici hal bitmiş kabul edilir.
- Tekillik (singularity) fonksiyonları
  - Birim basamak $u(t)$: $t < 0$ için 0, $t > 0$ için 1. $u(t - t_0)$ basamağı $t_0$ kadar sağa kaydırır.
  - $1 - u(t - t_0)$: $t_0$'a kadar 1, sonra 0. Bir kaynağın $t_0$ anında devreden çıkmasını modeller.
  - Birim dürtü $\delta(t)$: $u(t)$'nin türevi. $t = 0$'da sonsuz genlikli, altındaki alan 1.
    - Örnek: $x(t) = 5\delta(t+2) + 10\delta(t) - 4\delta(t-3)$.
    - Eleme (sifting) özelliği: $a < t_0 < b$ ise $\displaystyle\int_a^b f(t)\,\delta(t - t_0)\,dt = f(t_0)$. Örneklemenin temelidir.
  - Birim rampa $r(t) = t\,u(t)$: eğimi 1. $r(t - t_0)$ kırılma noktasını $t_0$'a taşır.
  - İlişkiler: $\dfrac{dr}{dt} = u(t)$, $\dfrac{du}{dt} = \delta(t)$. İntegral yönünde tersi.
- Basamak cevabı: RC devresi ve akım kaynağı
  - Devre: $I_1 u(t - t_0)$ akım kaynağı, paralel $R$ ve $C$.
  - $t < t_0$: kaynak sıfır, $v_C = 0$. $t \to \infty$: kapasite açık devre, $v_C = I_1 R$.
  - Diferansiyel denklem: $C\dfrac{dv_C}{dt} + \dfrac{v_C}{R} = I_1$.
  - Çözüm iki parçalı: doğal çözüm $A e^{-t/RC}$ ve zorlanmış çözüm. Sabit kaynak için zorlanmış çözüm sabittir: $I_1 R$.
  - $v_C(t_0) = 0$ koşulundan $A = -I_1R$.
  - Sonuç: $v_C(t) = I_1R\left(1 - e^{-(t - t_0)/RC}\right)$, $t > t_0$.
- Zorlanmış çözüm tahmini
  - Kaynak sabit ise: sabit $A$. Kaynak $t^2$ ise: $At^2 + Bt + C$.
  - Kaynak sinüzoidal ise: $A\cos(\omega t + \phi)$. Kaynağın $\omega$'sı kullanılır, $A$ ve $\phi$ bilinmeyendir.
- Basamak cevabı: RL devresi ve gerilim kaynağı
  - Devre: $V_1 u(t - t_0)$ gerilim kaynağı, seri $R$ ve $L$.
  - $t \to \infty$: bobin kısa devre, $i_L = V_1/R$.
  - $\dfrac{di_L}{dt} + \dfrac{R}{L}i_L = \dfrac{V_1}{L}$. Sonuç: $i_L(t) = \dfrac{V_1}{R}\left(1 - e^{-R(t - t_0)/L}\right)$.
- Example 01: iki basamak kaynaklı RC devresi (süperpozisyon)
  - Devre: paralel bağlı $I_1 u(t - t_1)$ (yukarı), $I_2[1 - u(t - t_2)]$ (aşağı), $R$ ve $C$. $t_1 < t_2$.
  - $I_1$ kaynağı $t_1$'de devreye girer. $I_2$ kaynağı $t_2$'ye kadar ters yönde akım verir, sonra kalkar.
  - $t < t_1$: $v_C = -RI_2$.
  - $t_1 < t < t_2$: $v_C = RI_1\left(1 - e^{-(t - t_1)/RC}\right) - RI_2$.
  - $t > t_2$: $v_C = RI_1\left(1 - e^{-(t - t_1)/RC}\right) - RI_2\,e^{-(t - t_2)/RC}$.
  - Süreklilik kontrolü: $v_C(t_2^-) = v_C(t_2^+)$ sağlanıyor.
- Example 02: kaynaksız RL
  - Devre: 5 V kaynak, $t = 0$'da açılan anahtar, seri 10 µH bobin ve 1 kΩ. Kaynak $5[1 - u(t)]$ V olarak modellenir.
  - $t < 0$: bobin kısa devre. $I_L = 5\text{ V}/1\text{ kΩ} = 5$ mA, $V_L = 0$, $V_R = 5$ V.
  - $t > 0$: $\tau = L/R = 10\text{ µH}/1\text{ kΩ} = 10$ ns.
  - $i_L = 5e^{-t/10\text{ ns}}$ mA, $v_R = 5e^{-t/10\text{ ns}}$ V, $v_L = L\,di_L/dt = -5e^{-t/10\text{ ns}}$ V. $v_R + v_L = 0$ sağlanır.
- Example 03: kaynaksız RC
  - Devre: 5 V kaynak, $t = 2$ ms'de açılan anahtar. Anahtardan sonra $R_1 = 1$ kΩ toprağa. Seri $R_2 = 3$ kΩ, ardından $R_3 = 12$ kΩ ve $C_1 = 2$ µF paralel olarak toprağa.
  - $t < 2$ ms: $C$ açık devre. 5 V doğrudan $R_2 + R_3$ serisine uygulanır.
    - $v_C = 5\cdot\dfrac{12}{3 + 12} = 4$ V.
  - $t > 2$ ms: kaynak çıkar. $C$'nin uçlarından bakılan direnç $R_{eq} = 12\text{k} \parallel (3\text{k} + 1\text{k}) = 3$ kΩ.
    - $\tau = 3\text{ kΩ}\cdot 2\text{ µF} = 6$ ms.
    - $v_C = 4e^{-(t - 2\text{ ms})/6\text{ ms}}$ V.
    - $i_C = C\,dv_C/dt = -1.33\,e^{-(t - 2\text{ ms})/6\text{ ms}}$ mA.
  - Example 04 öğrencilere bırakıldı.
- Ders sonu duyuruları
  - Gelecek hafta bayram nedeniyle ders yok. İki hafta sonra RLC (ikinci dereceden) devrelere geçilecek.
  - Kısa sınav büyük olasılıkla ilan edilen zamanda yapılacak.
  - Vize biçimi soruldu: vize çoktan seçmeliydi, sorulara geri dönülemiyordu. Hoca bunun kopyayı önlemek için olduğunu söyledi.
  - Kısa sınavlar klasik olmaya devam edecek. Final büyük olasılıkla çoktan seçmeli olacak, çözümler yine yüklenecek.

## Hocanın Özellikle Vurguladığı Kısımlar

- Thevenin sorusunda bağımlı kaynaklar sıfırlanmaz. Yalnızca bağımsız kaynaklar sıfırlanır, sonra test kaynağı bağlanır.
- Zaman sabitindeki direnç, kapasite veya bobinin uçlarından görülen Thevenin direncidir.
- Kapasite gerilimi ve bobin akımı süreklidir, ani atlama yapamaz. Aralıklı çözümlerde sınırlarda sürekliliği kontrol edin.
- $1 - u(t - t_0)$ fonksiyonunu tanıyın: kaynağın devreden çıkmasını modeller.
- Ayrıntılı diferansiyel denklem çözümü sınavda beklenmiyor. Basamak cevabının biçimini bilmek yeterli: sıfırdan başlar, son değere üstel olarak yaklaşır.
- Birden fazla kaynakta süperpozisyon kullanın. Her kaynağın devreye girdiği ve çıktığı zamana dikkat edin.
- Çoktan seçmeli sınavın avantajı: sonuç şıklarda yoksa hata yaptığınızı anlayıp düzeltebilirsiniz.

## Kısa Tekrar Notları

- DC: $C$ açık devre, $L$ kısa devre. Pratikte $5\tau$ sonra kararlı hal.
- Doğal cevap: $v_C = V_0e^{-t/\tau}$, $i_L = I_0e^{-t/\tau}$.
- Basamak cevabı: $x(t) = x(\infty) + [x(t_0) - x(\infty)]e^{-(t - t_0)/\tau}$.
- $\tau_{RC} = R_{TH}C$, $\tau_{RL} = L/R_{TH}$.
- $e^{-1} \approx 0.368$, $e^{-5} \approx 0.0067$.
- $\delta = du/dt$, $u = dr/dt$. $\int f(t)\delta(t - t_0)dt = f(t_0)$.

## Detaylı Açıklamalar

### Ders sonrası notlar

- **RL zaman sabiti:** Hoca dersin başında (03:12) RL devreleri için zaman sabitini "R bölü L" olarak söyledi. Doğrusu $\tau = L/R$'dir. Hoca 03:50'de türetmeyi yaparken bunu kendisi doğru verdi: $e^{-Rt/L}$ ifadesinde paydada kalan $L/R$'dir.
- **Example 01'de işaret ve gösterim:** Hoca birkaç kez "eksi R bölü I2" dedi. Doğrusu çarpımdır: $-R\cdot I_2$. Ayrıca $t \to -\infty$ için "$I_2R$'lik gerilim bekliyoruz" dedi. $I_2$ ters yönde aktığı için bu değer $-RI_2$'dir. Slayttaki formüller doğru.
- **Example 02 birim hataları:** Slayttaki devrede bobin 10 µH, hesap satırında ise "10 mH / 1 kΩ = 10 ns" yazıyor. 10 mH ile sonuç 10 µs olurdu. Doğru değer 10 µH'dir ve $\tau = 10$ ns. Hoca da "m değil u olacak, mikrohenri" diyerek düzeltti.
- **Example 02'de anahtarın açılması:** Seri devrede anahtar gerçekten açılsaydı bobin akımının akacağı bir yol kalmazdı. Akım anında sıfıra inemeyeceği için bobinde çok büyük bir gerilim (kıvılcım) oluşurdu. Hoca da "enerjinin harcanacağı bir yol olması lazım" diyerek bunu fark etti. Slayttaki çözüm, kaynağın $5[1 - u(t)]$ ile modellendiğini, yani kaynağın kısa devreye dönüştüğünü ve L-R çevresinin kapalı kaldığını kabul eder.
- **Example 03'te zaman sabiti:** Hoca önce µF'yi $10^{-9}$ alarak $\tau = 6$ µs buldu. Sonra düzeltti: $2\text{ µF} = 2\times10^{-6}$ F, $\tau = 3\times10^{3}\cdot 2\times10^{-6} = 6$ ms. Ayrıca çözüme $t$ yerine $t - 2$ ms yazılması gerektiğini sonradan ekledi.
- **Vize Q8 ara adımı:** Hoca bir yerde "2 ile 2 paralel, 1" dedi. Paralel kapasiteler toplanır, sonuç 4 F'tır. Sohbetten gelen uyarıyla düzeltti. Doğru akış:
  - Sol taraf: $2\parallel 1 = 3$ F, 6 F ile seri $= 2$ F. a ucundaki 2 F ile paralel: $2 + 2 = 4$ F.
  - Sağ taraf: 6 F ile 3 F seri $= 2$ F. b ucundaki 2 F ile paralel: 4 F. Ucu boşta olan 2 F katkı yapmaz.
  - a-b arası: $4$ F ile $4$ F seri $= 2$ F.
- **Vize Q2 tutarsızlığı:** Soru metni "$v_x$'i bulun" diyor. Şıklar (26.67, 173.33, $-46.66$, 6.66 V) ise düğüm gerilimleri $V_1$, $V_3$, $V_4$, $V_2$'dir. numpy ile yapılan çözümde $v_x = V_1 - V_4 = 73.33$ V çıktı ve bu değer şıklarda yok. Sınavda her öğrenciye farklı bir düğüm sorulmuş olabilir. Kayıtta bu sorunun cevap satırı görünmüyor.
- **Vize Q3 cevap anahtarı:** Belgede "$R_{TH} = 31.73$ Ω ve $i_x = 31.52$ mA" yazıyor. Devrede $i_x$ yok, bu satır başka bir sorudan kalmış görünüyor. Test kaynağıyla yapılan hesap $R_{TH} = 31.72$ Ω verdi. Cevap D ($V_{TH} = 0$, $R_{TH} = 31.73$ Ω).
- **Vize Q9 çizimi:** Belgede sorunun altında akım grafiğine benzeyen yamuk biçimli bir gerilim grafiği görünüyor. Bu grafik yanlış şıklardan biri olmalı, hoca cevabı C olarak verdi. Doğru gerilim parçalı sabittir: $(-1, 0)$ aralığında $+3$ V, $(0, 2)$ aralığında 0, $(2, 3)$ aralığında $-3$ V.
- **Lab örneğinde Norton kaynağı:** Slaytta Norton kaynağı "$V_{TH}/R_{TH} - 1$ A" gibi okunuyor. Kastedilen $I_N = V_{TH}/R_{TH} = 10/10 = 1$ A'dir.
- **Doğrulama:** Vize Q1, Q2, Q3, Q4, Q5, Q7, Q8 ve Q10, laboratuvar örneği ve Example 03 Python (numpy) ile yeniden hesaplandı. Sonuçlar hocanın cevaplarıyla uyumlu. Q6'nın şekilleri kayıtta tam görünmediği için yalnızca hocanın verdiği değerler yazıldı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
