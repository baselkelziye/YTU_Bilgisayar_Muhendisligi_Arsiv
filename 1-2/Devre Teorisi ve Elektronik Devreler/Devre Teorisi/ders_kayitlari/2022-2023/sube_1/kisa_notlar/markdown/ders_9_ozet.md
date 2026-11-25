# Ders 9 Çalışma Özeti

## Genel Konular

- Birinci dereceden op-amp devreleri: türev ve integral alıcılar
  - İdeal op-amp'ın iki tanım bağıntısı kullanılır: giriş gerilimleri eşittir ($v_N = v_P$) ve girişlerden akım akmaz ($i_N = i_P = 0$). Artı giriş toprağa bağlıysa eksi giriş de 0 V olur (sanal toprak).
  - Bu devreler içinde bir enerji depolayan eleman (kondansatör) bulunan op-amp devreleridir. Tarihte analog bilgisayarlarda türev ve integral hesabı için yaygın kullanılmıştır (örneğin hız kontrolü gibi denetim işlerinde).
  - Kondansatörün tanım bağıntısı: $q = C\,v_C$, $i_C = C\,\dfrac{dv_C}{dt}$, ya da integral biçiminde $v_C = \dfrac{1}{C}\int i_C\,dt$.
- Türev alıcı (differentiator) (ekrandan, 00:15:00 ve 00:20:00)
  - Devre: $v_S$ kaynağı ile eksi giriş arasında seri $C$; eksi girişten çıkışa geri besleme direnci $R$; artı giriş toprakta.
  - Eksi giriş 0 V olduğu için $v_C = v_S$. Girişlere akım girmediği için $i_C = i_R$.
  - $C\,\dfrac{dv_S}{dt} = \dfrac{0 - v_o}{R}$ eşitliğinden $v_o = -RC\,\dfrac{dv_S}{dt}$ çıkar.
  - Üçgen dalga girişi verilirse çıkış kare dalgadır: eğimin pozitif olduğu yerde çıkış negatif sabit, eğimin negatif olduğu yerde pozitif sabittir.
  - $t^2$ biçiminde (parabol parçaları) bir giriş verilirse çıkış üçgen dalgaya benzer.
- Türev alıcı örnekleri
  - Basamak girişi: $v_S(t) = 3\,\text{V}\,u(t-5\,\text{s})$, $R = 20\ \text{k}\Omega$, $C = 40\ \mu\text{F}$, $\tau = RC = 0{,}8$ s (ekrandan, 00:25:00 ve 00:30:00).
    - $t < 5$ s için $v_o = 0$; $t > 5\,\text{s} + 5\tau = 9$ s için de $v_o = 0$ kabul edilir. Arada üstel bir geçici hal vardır: $v_o(t)$, $e^{-(t-5)/0{,}8}$ biçiminde söner.
  - Sinüs girişi: $R = 2\ \text{k}\Omega$, $C = 0{,}1\ \mu\text{F}$, $RC = 0{,}2$ ms, $v_S = 2\sin(500t)$ V. Sonuç $v_o = -0{,}2\cos(500t)$ V $= 0{,}2\sin(500t - 90^\circ)$ V (ekrandan, 00:35:00). Çıkış girişten $90^\circ$ geridedir.
- Sinüs-kosinüs dönüşümleri (birim çember ve toplam formülüyle)
  - $\cos x = \sin(90^\circ - x) = \sin(90^\circ + x)$.
  - $-\sin\alpha = \sin(\alpha + 180^\circ) = \sin(\alpha - 180^\circ)$.
  - Amaç baştaki eksi işaretinden kurtulmak ve faz açısını $-180^\circ$ ile $+180^\circ$ arasında tutmaktır. Bu, sonraki haftalardaki fazör konusu için gereklidir.
- İntegral alıcı (integrator)
  - Devre: girişte seri $R$, geri beslemede $C$, artı giriş toprakta.
  - $i_R = v_S/R = i_C$, $v_C = -v_o$; buradan $v_o = -\dfrac{1}{RC}\int v_S\,dt$.
  - Belirli bir aralıkta: $V_o(t_2) = -\dfrac{1}{RC}\int_{t_1}^{t_2} v_{in}(t)\,dt + V_o(t_1)$ (ekrandan, 00:45:00).
  - Örnek: $R = 25\ \text{k}\Omega$, $C = 5$ nF, $v_S = 3\sin(6{,}24\text{k}\,t)$ V. $1/RC = 8000\ \text{s}^{-1}$, genlik $3 \cdot 8000/6240 \approx 3{,}85$ V. $t_1 = 0$ için $V_o(t_2) = 3{,}85\sin(6{,}24\text{k}\,t_2 + 90^\circ) - 3{,}85$ V. Çıkış ile giriş arasında $90^\circ$ faz farkı vardır.
- Başlangıç gerilimli kondansatör (ekrandan, 00:50:00)
  - Kaynak yoksa kondansatördeki başlangıç gerilimi $R_1$ üzerinden boşalır: $v_C(t) = v_C(t_0)\,e^{-(t-t_0)/R_1C}$, $i_C = -\dfrac{1}{R_1}v_C(t_0)\,e^{-(t-t_0)/R_1C}$. Zaman sabiti $R_1C$'dir.
  - Başlangıç gerilimi devrede ek bir kaynak varmış gibi modellenebilir.
- İkinci dereceden devreler ve sınır koşulları
  - İki enerji depolayan eleman içeren devrelerdir: seri RLC, paralel RLC, iki bobinli ya da iki kondansatörlü devreler. Denklem ikinci dereceden diferansiyel denklemdir.
  - Birinci dereceden devrede $A f + B f' = 0$ biçimindeki denklemin çözümü üsteldir: $A\,e^{-(t-t_0)/\tau}$. $\tau$ devre elemanlarından, $A$ sınır değerlerinden bulunur (ekrandan, 01:15:00).
  - İkinci derecede de üstel çözüm $e^{\alpha t}$ önerilir; $\alpha$ için ikinci dereceden bir karakteristik denklem çıkar, iki kök $\alpha_1, \alpha_2$ bulunur. Genel çözüm $A e^{\alpha_1 t} + B e^{\alpha_2 t}$ olur. $A$ ve $B$ için iki sınır koşulu gerekir.
  - Sınır koşulları (ekrandan, 01:20:00): kararlı halde (DC) kondansatör açık devre, bobin kısa devredir. Geçiş anında kondansatör gerilimi ($v_C(t_0^+) = v_C(t_0^-)$) ve bobin akımı ($i_L(t_0^+) = i_L(t_0^-)$) süreklidir.
  - $t \to \infty$ değerleri hem kontrol için hem de çözümün doğrulanması için hesaplanır.
- Sınır koşulu örnekleri
  - Örnek 1 (ekrandan, 01:25:00 ve 01:30:00): anahtar uzun süre kapalı, $t_0$'da açılıyor. $t < t_0$: $i_L = i_C = 0$, $v_L = 0$, $v_C = V_1 R_2/(R_1 + R_2)$. Anahtar açılınca $V_1$ ve $R_1$ devreden çıkar; $R_2$, $L_1$, $R_3$, $C_1$ tek gözlü devre olur: $v_C + v_L + i(R_2 + R_3) = 0$. $t \to \infty$'da bütün akım ve gerilimler sıfıra gider.
  - Örnek 2 (iki kaynaklı devre, devre şekli karede yok): $t < t_0$ için $i = -0{,}3$ mA, $v_L = 0$, $i_C = 0$, $v_C = 3{,}5$ V; $t \to \infty$ için $v_C = 5$ V, akımlar ve $v_L$ sıfır. <!-- BELİRSİZ: devre şekli karelerde görünmüyor, değerler altyazıdan -->
  - Örnek 3 (ekrandan, 01:35:00 ve 01:40:00): $V_1 = 2$ V, $R_1 = 5$ k$\Omega$, $L_2 = 40\ \mu$H, $L_1 = 10\ \mu$H, $R_2 = 5$ k$\Omega$, $V_2 = 5$ V. $t < t_0$: $i_{L1} = -1$ mA, $i_{L2} = 1$ mA, $v_{L1} = v_{L2} = 0$. $t \to \infty$: $i_{L1} = -1$ mA, $i_{L2} = 1{,}4$ mA, $v_{L1} = v_{L2} = 0$.
- Seri RLC devresinin basamak tepkisi (kaynaksız hale geçiş)
  - Kaynak $v_s = V_s\,[1 - u(t - t_0)]$: uzun süre $V_s$ uygulanır, $t_0$'da sıfıra iner (ekrandan, 01:45:00).
  - $t < t_0$: $i_L = 0$, $v_L = 0$, $i_C = 0$, $v_C = V_s$. $t \to \infty$: hepsi sıfır.
  - KVL: $v_L + v_R + v_C = 0$, $i = i_L = i_C = i_R$. Türev alınarak $L\,i'' + R\,i' + \dfrac{1}{C}i = 0$ (ekrandan, 01:55:00).
  - $i(t) = e^{\alpha t}$ önerisiyle $\alpha^2 + \dfrac{R}{L}\alpha + \dfrac{1}{LC} = 0$; $\alpha_{1,2} = \dfrac{-R/L \pm \sqrt{(R/L)^2 - 4/(LC)}}{2}$.
  - Genel çözüm $i(t) = A\,e^{\alpha_1(t-t_0)} + B\,e^{\alpha_2(t-t_0)}$. $i(t_0) = 0$ koşulundan $A + B = 0$; ikinci koşul kondansatörün $v_C(t_0) = V_s$ değerinden gelir.
  - Köklerin iki ayrı gerçel, eşit ya da karmaşık eşlenik olmasına göre aşırı sönümlü, kritik sönümlü ve az sönümlü durumlar oluşur. Bunlar sonraki derste ayrıntılı incelenecektir.
- Vize soru çözümü (asistan tarafından)
  - KVL ve çevre denklemleri, DC'de kondansatörlü devrede gerilim bölme, eşdeğer kapasitans, evirmeyen op-amp, düğüm analizi, maksimum güç aktarımı, birim basamak fonksiyonları, sonsuz merdiven devre, RC geçici hal ve süperpozisyon soruları çözüldü (ayrıntılar genişletilmiş notta).

## Hocanın Özellikle Vurguladığı Kısımlar

- Türev alıcının çalışma mantığı
  - Hoca bunu "çok önemli bir nokta" diye vurguladı. $v_o = -RC\,dv_S/dt$: devre girişin türevini alır, $RC$ ile ölçekler ve işaretini ters çevirir.
- Devrenin adı değil, çözümü önemlidir
  - Op-amp devrelerinde (eviren, evirmeyen, toplayıcı, tampon) devreye isim vermekten çok, ideal op-amp bağıntılarıyla devreyi çözebilmek önemlidir.
- Faz düzenlemesi
  - Sonuç kosinüs ve eksi işaretli çıktığında sinüse çevrilir, eksi işaret açıya $\pm 180^\circ$ eklenerek içeri alınır, açı $-180^\circ$ ile $+180^\circ$ arasında tutulur.
- İntegral alıcıda başlangıç değeri
  - İntegral bir aralıkta alındığı için $V_o(t_1)$ başlangıç değeri eklenmelidir. Kondansatör gerilimi süreksiz olamayacağından $t = 0$'da çıkış sıfırdan başlar.
- İkinci derece devrelerde iki sınır koşulu
  - Kondansatör gerilimi ve bobin akımı geçiş anında süreklidir; DC kararlı halde kondansatör açık devre, bobin kısa devredir. $t \to \infty$ değerleri çözümün kontrolü için kullanılır.

## Kısa Tekrar Notları

- İdeal op-amp: $v_N = v_P$, $i_N = i_P = 0$.
- Türev alıcı: girişte $C$, geri beslemede $R$; $v_o = -RC\,\dfrac{dv_S}{dt}$.
- İntegral alıcı: girişte $R$, geri beslemede $C$; $v_o = -\dfrac{1}{RC}\int v_S\,dt + v_o(t_1)$.
- Üçgen dalganın türevi kare dalgadır; sinüsün türevi kosinüstür ($90^\circ$ faz farkı).
- $\cos x = \sin(x + 90^\circ)$, $-\sin\alpha = \sin(\alpha \pm 180^\circ)$.
- $5\tau$ sonra geçici hal bitmiş sayılır.
- DC kararlı hal: C açık devre, L kısa devre.
- Süreklilik: $v_C(t_0^+) = v_C(t_0^-)$, $i_L(t_0^+) = i_L(t_0^-)$.
- Seri RLC (kaynaksız): $L\,i'' + R\,i' + i/C = 0$, $\alpha^2 + (R/L)\alpha + 1/(LC) = 0$.
- Genel çözüm iki üstelin doğrusal birleşimidir; katsayılar iki sınır koşulundan bulunur.

## Detaylı Açıklamalar

- Türev alıcıda kondansatör, kaynak ile sanal toprak arasındadır; bu yüzden üzerindeki gerilim doğrudan kaynak gerilimidir. Kondansatör akımı gerilimin türeviyle orantılıdır ve op-amp girişine giremediği için tamamen geri besleme direncinden geçer. Direncin çıkış ucundaki gerilim bu akımın $R$ ile çarpımının eksisidir. Sonuç olarak çıkış, girişin türevinin $-RC$ katıdır. Üçgen dalgada eğim parça parça sabit olduğundan çıkış parça parça sabit, yani kare dalga olur.
- Basamak girişli türev alıcı örneğinde slayt, kondansatör geriliminin $t = 5$ s'den sonra $\tau = 0{,}8$ s ile üstel olarak 3 V'a yaklaştığını kabul eder. Hoca slayttaki son satırda katsayının eksik yazıldığını gösterdi ve $\dfrac{d}{dt}\left(3e^{-(t-5)/0{,}8}\right) = 3\cdot\left(-\dfrac{1}{0{,}8}\right)e^{-(t-5)/0{,}8}$ türevini ayrıca yazdı. $RC = 0{,}8$ s olduğu için katsayılar sadeleşir ve çıkışın genliği 3 V olur.
- Ders sonrası not: kondansatör gerilimi $v_C = 3\left(1 - e^{-(t-5)/0{,}8}\right)$ V biçiminde yükseliyorsa türev pozitif çıkar ve $v_O = -3\,e^{-(t-5)/0{,}8}$ V olur, yani çıkış negatif bir darbedir. Slayttaki işaret büyük olasılıkla bu yüzden karışmıştır. İdeal op-amp ve ideal kaynakla kondansatör gerilimi anında 3 V'a atlar; slayttaki üstel model büyük olasılıkla kaynak tarafındaki küçük bir direnci varsayar.
- İntegral alıcıda giriş direncinden geçen akım ($v_S/R$) kondansatörü doldurur. Kondansatör gerilimi akımın integralidir ve eksi giriş 0 V olduğu için $v_o = -v_C$'dir. Bu yüzden çıkış, girişin integralinin $-1/RC$ katıdır. Sinüs girişinde integral eksi kosinüs verir, iki eksi sadeleşir ve genlik $3/(RC\omega) \approx 3{,}85$ V olur.
- İkinci dereceden devrelerde çözüm yolu: önce $t < t_0$ için DC eşdeğer devre çizilir (C açık, L kısa), başlangıç değerleri bulunur. Sonra $t \to \infty$ için yeni DC eşdeğer devre çözülür. Geçiş anının hemen sonrasında süreklilik koşullarıyla devre kurulur, KVL/KCL ile ikinci dereceden diferansiyel denklem yazılır. Üstel çözümün kökleri devre elemanlarından, katsayıları sınır koşullarından bulunur. Sonuç $t \to \infty$ değerleriyle karşılaştırılarak kontrol edilir.
- Ders sonrası not: seri RLC örneğinde ikinci koşul en kolay KVL'den elde edilir. $t_0^+$ anında $i = 0$ olduğundan $L\,\dfrac{di}{dt}(t_0^+) = -v_C(t_0^+) = -V_s$ olur; buradan $A\alpha_1 + B\alpha_2 = -V_s/L$ yazılır. Hocanın tahtada integral üzerinden kurmaya çalıştığı ikinci denklem büyük olasılıkla bu koşula karşılık gelir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
