# Ders 9 Çalışma Özeti

> Kayıt iki parçadır; arşivde parçalar yanlış sırada birleştirildiği için altyazıdaki sıra düzeltildi ve saat damgaları düzeltilmiş altyazıya göredir.

## Genel Konular

- Birinci dereceden devreler: RC ve RL devreleri
  - Kondansatör enerjiyi gerilim, bobin ise üzerinden geçen akımın oluşturduğu manyetik alan üzerinden depolar.
  - Yalnız C ya da yalnız L ile enerji ne birikir ne de harcanır; şarj sırasında gerilimin oluşması ve deşarj sırasında enerjinin "sömürülmesi" için devrede bir R gerekir. Bu yüzden RC ve RL devreleri incelenir.
  - Bu devrelerin diferansiyel denklemleri birinci derecedendir; bu nedenle "birinci dereceden devreler" diye anılırlar.
- Doğal cevap (natural response, deşarj)
  - Devrede dış kaynak yoktur; $t=0$ anında kondansatörde ya da bobinde depolanmış enerji vardır ve $t>0$ için bu enerji direnç üzerinden boşalır (ekrandan, 00:12:53).
  - Kaynak $t_0$ anında anahtarla devreden çıkarılır; kondansatör o ana kadar $V_0$ gerilimine, bobin $I_0$ akımına tam şarj olmuş kabul edilir.
- RC devresinin deşarj denklemi (ekrandan, 00:17:53 ve 00:22:53)
  - KVL: $v_C = v_R$; akımlar ters yönlü: $i_C = -i_R$, $i_C = C\,\dfrac{dv_C}{dt}$, $i_R = \dfrac{v_R}{R}$.
  - $C\dfrac{dV_C}{dt} + \dfrac{V_C}{R} = 0 \Rightarrow \dfrac{dV_C}{V_C} = -\dfrac{1}{RC}dt \Rightarrow \ln V_C = -\dfrac{t}{RC} + \ln V_C\big|_{t=t_0}$
  - Sonuç: $V_C(t) = V_0\,e^{-t/\tau}$, $\tau = RC$, $t \ge 0$.
  - $I_R(t) = -I_C(t) = \dfrac{V_0}{R}e^{-t/\tau}$, $p_R(t) = \dfrac{V_0^2}{R}e^{-2t/\tau}$.
- RL devresinin deşarj denklemi (ekrandan, 00:27:53)
  - $V_L + V_R = 0$, $I_L = I_R$, $V_L = L\dfrac{dI_L}{dt}$.
  - $\dfrac{dI_L}{I_L} = -\dfrac{R}{L}dt \Rightarrow I_L(t) = I_0\,e^{-t/\tau}$, $\tau = \dfrac{L}{R}$.
- Zaman sabiti $\tau$ ve 5τ kuralı
  - Kondansatörde $\tau = RC$, bobinde $\tau = L/R$.
  - Tam şarj ya da tam deşarj için en az $5\tau$ süre geçmesi gerekir.
  - $\tau$ hesabındaki $R$, enerji depolayan elemanın uçlarından devreye bakıldığında görülen eşdeğer dirençtir (Thevenin direncini bulur gibi), kaynak tarafından bakılarak bulunmaz.
- Tekillik fonksiyonları (singularity functions)
  - Anahtarın açılıp kapanması ya da kaynağın devreye girip çıkması sözle değil, fonksiyonla ifade edilir.
  - Birim basamak: $u(t)=0$ ($t<0$), $u(t)=1$ ($t>0$). $u(t-t_0)$ sağa, $u(t+t_0)$ sola kaydırılmış basamaktır. $V_0\,u(t-t_0)$: $t_0$ anında $V_0$ uygulanır (ekrandan, 00:32:53).
  - $1-u(t-t_0)$: kaynak $t_0$ anına kadar devrededir, $t_0$ anında çıkarılır.
  - Birim darbe: $\delta(t) = \dfrac{d}{dt}u(t)$; $t\neq 0$ için 0, $\int_{0^-}^{0^+}\delta(t)\,dt = 1$. Örnek: $x(t) = 5\delta(t+2) + 10\delta(t) - 4\delta(t-3)$ (ekrandan, 00:42:53).
  - Rampa fonksiyonu: $t_0$ öncesinde 0, sonrasında zamanla doğrusal artan sinyal.
- Basamak cevabı (şarj)
  - RC: $I_1u(t-t_0)$ akım kaynağına paralel R ve C. Son değer için C açık devre yapılır: $V_C(\infty) = I_1R$. Düğüm denkleminden $V_C(t) = RI_1\left[1-e^{-(t-t_0)/RC}\right]$, $t>t_0$ (ekrandan, 00:57:53).
  - RL: $V_1u(t-t_0)$ kaynağına seri R ve L. $-V_1 + V_L + V_R = 0$ denkleminden $I_L(t) = \dfrac{V_1}{R}\left[1-e^{-(t-t_0)/\tau}\right]$, $\tau = L/R$ (ekrandan, 01:02:53).
  - Bobinin hangi akıma şarj olacağını bulmak için bobin kısa devre yapılır.
- Birden çok kaynaklı devrede süperpozisyon (ekrandan, 01:07:53 ve 01:12:53)
  - $I_1u(t-t_1)$ ve ters yönlü $I_2[1-u(t-t_2)]$ kaynakları ayrı ayrı çözülüp toplanır.
- Sayısal örnekler (RL deşarjı, üç dirençli RC deşarjı, 6 V'luk RL deşarjı)
- Birinci dereceden op-amp devreleri
  - Türev alıcı: giriş direncinin yerine kondansatör konur. $v_o(t) = -RC\,\dfrac{dv_S(t)}{dt}$.
  - İntegral alıcı: geri besleme direncinin yerine kondansatör konur. $v_o(t) = -\dfrac{1}{RC}\displaystyle\int_{t_1}^{t} v_S\,dt + v_o(t_1)$.
  - Sinüs girişte türev alıcının çıkışı girişin 90° gerisinde, integral alıcının çıkışı 90° önündedir.

## Hocanın Özellikle Vurguladığı Kısımlar

- 5τ kuralı
  - Kondansatörün ya da bobinin tam şarj veya tam deşarj olması için en az $5\tau$ süre geçmelidir; hoca "bu kaydı unutmuyoruz" dedi.
- $\tau$ içindeki R'nin seçimi
  - R, kondansatör ya da bobin tarafından bakılan eşdeğer dirençtir; karmaşık devrelerde önce bu eşdeğer bulunur.
- Güç formülünde üs
  - $p_R = V_0^2/R \cdot e^{-2t/\tau}$; gerilimin karesi alınınca üsteki $t$'nin de 2 ile çarpıldığı sınavlarda sık unutuluyor.
- Birim basamakla sinyal yazma
  - Hoca parça parça tanımlı bir sinyali birim basamaklarla yazmayı tahtada çözdürdü ve bunun finalde "garanti" soru olacağını söyledi.
- Birim dönüşümleri
  - Nano, mikro ve mili saniyeler en çok hata yapılan yerdir; $\tau$ hesaplanırken kilo ($10^3$), mili ($10^{-3}$), mikro ($10^{-6}$) dikkatle çarpılmalıdır.
- Konunun önemi
  - RC ve RL devrelerinin şarj ve deşarjı, ileride işlenecek empedans, faz farkı ve ileri-geri faz (leading, lagging) konularının temelidir; sunumlar evde tekrar edilmelidir.

## Kısa Tekrar Notları

- RC deşarjı: $V_C(t) = V_0e^{-t/RC}$; RL deşarjı: $I_L(t) = I_0e^{-tR/L}$.
- RC şarjı: $V_C(t) = V_\infty\left[1-e^{-(t-t_0)/\tau}\right]$; RL şarjı: $I_L(t) = I_\infty\left[1-e^{-(t-t_0)/\tau}\right]$.
- Kondansatörün son gerilimi: C açık devre yapılır. Bobinin son akımı: L kısa devre yapılır.
- $\tau = RC$ ya da $\tau = L/R$; R, elemanın uçlarından görülen eşdeğer dirençtir.
- Bir $\tau$ sonunda deşarj olan elemanda başlangıç değerinin yaklaşık %37'si kalır; $5\tau$ sonunda eleman tamamen boşalmış ya da dolmuş kabul edilir.
- $u(t-t_0)$: $t_0$ anında devreye girer; $1-u(t-t_0)$: $t_0$ anında devreden çıkar.
- Parça parça sinyal: her kırılma noktasında, sinyalin sıçrama miktarı kadar katsayılı bir basamak eklenir.
- Türev alıcı: $v_o = -RC\,dv_S/dt$; integral alıcı: $v_o = -\frac{1}{RC}\int v_S\,dt + v_o(t_1)$.
- $\sin$ türevi $\cos$, $\cos$ türevi $-\sin$; $-\cos x = \sin(x-90^\circ)$, $\cos x = \sin(x+90^\circ)$.

## Detaylı Açıklamalar

- **Deşarj formülünün çıkarılışı.** Kaynağı $t_0$ anında çıkarılmış, $V_0$'a şarjlı bir kondansatör tek bir R üzerinden boşalır. KVL'den $v_C = v_R$ yazılır. Kondansatörün iç akımı dış devredeki akımın tersi yönündedir: $i_C = -i_R$. $i_C = C\,dv_C/dt$ ve $i_R = v_C/R$ yerine konunca $\frac{dV_C}{dt} + \frac{V_C}{RC} = 0$ olur. Değişkenler ayrılıp iki tarafın integrali alınınca $\ln V_C = -t/RC + \ln V_C(t_0)$ bulunur. $V_C(t_0) = V_0$ yazılıp iki tarafın üssü alınınca $V_C(t) = V_0e^{-t/RC}$ elde edilir. $e^{-t/\tau} = 1/e^{t/\tau}$ olduğu için bu çarpan $V_0$'ı zamanla küçülten bir katsayıdır. Herhangi bir anda gerilimi bulmak için o anın $t$ değeri formüle konur. Akım $V_C/R$'den, güç $V^2/R$'den bulunur. Eğri başta hızlı, sonra yavaş düşer.
- **Bobin deşarjı.** Kaynak çekildikten sonra bobin, içindeki akımı aynı yönde sürdürür ve üreteç gibi davranır. Seri devrede $I_L = I_R$, KVL'den $L\,dI_L/dt + RI_L = 0$ yazılır. Aynı adımlar $I_L(t) = I_0e^{-t/\tau}$ ve $\tau = L/R$ sonucunu verir. Kondansatörde çözüm gerilim üzerinden, bobinde ise akım üzerinden yürür. Direnç gerilimi $V_R = I_LR$, bobin gerilimi ise $V_L = -V_R$ olur.
- **Tekillik fonksiyonları ve sinyal yazma.** Derste tahtada çözülen sinyal şöyledir: $t<5$ s için 0, $5<t<8$ s için 3 V, $8<t<12$ s için $-5$ V, $t>12$ s için 0 (ekrandan, 00:37:53). Önce $3u(t-5)$ yazılır. 8. saniyede sinyal 3 V'tan $-5$ V'a, yani 8 V düşer; bu yüzden $-8u(t-8)$ eklenir. 12. saniyede $-5$ V'tan 0'a, yani 5 V çıkar; $+5u(t-12)$ eklenir. Sonuç $v(t) = 3u(t-5) - 8u(t-8) + 5u(t-12)$ V olur. Bir öğrencinin önerdiği gibi $-8u(t-8)$ yerine $-3u(t-8) - 5u(t-8)$ yazmak da aynı sonucu verir.
- **Şarj formülü.** $I_1u(t-t_0)$ akım kaynağına paralel bağlı R ve C'de düğüm denklemi $\frac{V_C}{R} + C\frac{dV_C}{dt} - I_1 = 0$ olur. Çözüm $V_C(t) = RI_1\left[1-e^{-(t-t_0)/RC}\right]$'dir. $t = t_0$ anında parantez sıfırdır, yani kondansatör boştur. Zaman ilerledikçe $V_C$, $V_0 = RI_1$ değerine yaklaşır. RL devresinde aynı adımlar $I_L(t) = \frac{V_1}{R}\left[1-e^{-(t-t_0)/\tau}\right]$ sonucunu verir. Formüldeki $t-t_0$ farkı, kaynağın devreye girdiği andan itibaren geçen süredir. Örneğin kaynak 1 ms'de giriyorsa, 2 ms'deki değer için $t-t_0 = 1$ ms konur.
- **Süperpozisyon örneği (Example 01).** Devrede paralel R ve C'yi besleyen iki akım kaynağı vardır. Biri $I_1u(t-t_1)$, öbürü ters yönlü $I_2[1-u(t-t_2)]$ kaynağıdır. $t_1<t_2$ için çözüm şöyledir (ekrandan, 01:12:53):
  - $t<t_1$: $V_C = -RI_2$. Yalnız $I_2$ devrededir ve kondansatör uzun süredir buna şarjlıdır.
  - $t_1<t<t_2$: $V_C = RI_1\left[1-e^{-(t-t_1)/RC}\right] - RI_2$
  - $t>t_2$: $V_C = RI_1\left[1-e^{-(t-t_1)/RC}\right] - RI_2e^{-(t-t_2)/RC}$
- **Üç dirençli RC örneği (Example 03).** 5 V'luk kaynak, R1 = 1 kΩ, R2 = 3 kΩ, R3 = 12 kΩ ve C1 = 2 µF'tan oluşan devrede anahtar $t = 2$ ms'de açılır; $V(t) = 5\,\text{V}[1-u(t-2\,\text{ms})]$ (ekrandan, 01:17:53). Açılmadan önce C açık devredir ve gerilimi R3'ünkine eşittir: $V_C = 5\cdot\frac{12}{3+12} = 4$ V. Anahtar açıldıktan sonra C'den bakılan direnç $12\,\|\,(3+1) = 3$ kΩ, $\tau = 3\,\text{k}\Omega\cdot 2\,\mu\text{F} = 6$ ms olur. Buradan $V_C(t) = 4e^{-(t-2\,\text{ms})/6\,\text{ms}}$ V bulunur. 3 ms'de $V_C = 4e^{-1/6} \approx 3{,}39$ V'tur (python ile doğrulandı).
- **Türev alıcı.** Eviren yükselteçte giriş direnci yerine kondansatör konur. Eviren uç sanal topraktadır, bu yüzden $v_C = v_S$ ve $i_C = i_R$ olur. Buradan $C\frac{dv_S}{dt} = -\frac{v_o}{R}$, yani $v_o = -RC\frac{dv_S}{dt}$ çıkar. $R = 2$ kΩ, $C = 0{,}1$ µF ve $v_S = 2\sin(500t)$ V için $v_o = -0{,}2\cos(500t)$ V $= 0{,}2\sin(500t-90^\circ)$ V olur. Çıkış girişin 90° gerisindedir.
- **İntegral alıcı.** Bu kez geri besleme direncinin yerine kondansatör konur. $i_R = v_S/R$, $i_C = -C\,dv_o/dt$ eşitliğinden $v_o = -\frac{1}{RC}\int v_S\,dt + v_o(t_1)$ bulunur. Sinüs girişin integrali $-\cos$ olur ve eksi işaretle birleşince çıkış kosinüs biçimini alır. Bu yüzden çıkış girişin 90° önündedir. PSpice grafiğinde çıkış sıfırın altında, bir doğru gerilim kaymasıyla salınır (ekrandan, 01:42:53).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
