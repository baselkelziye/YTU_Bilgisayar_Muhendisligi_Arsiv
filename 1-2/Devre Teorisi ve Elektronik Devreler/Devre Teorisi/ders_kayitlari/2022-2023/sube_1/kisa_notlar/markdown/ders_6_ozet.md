# Ders 6 Çalışma Özeti

## Genel Konular

- Kaynak dönüşümü ile Thevenin/Norton teoremlerinin farkı
  - Kaynak dönüşümü yalnız ideal olmayan bir gerilim kaynağını (ideal kaynak + seri direnç) ideal olmayan bir akım kaynağına (ideal kaynak + paralel direnç) ya da tersine çevirir.
  - Thevenin teoremi: doğrusal elemanlardan oluşan herhangi bir karmaşık devre, seçilen iki terminalden bakıldığında tek bir ideal olmayan gerilim kaynağına ($V_{TH}$ ile seri $R_{TH}$) eşdeğerdir. Eşdeğerlik, bu terminallere bağlanan her yük direncinde ($R_L$) aynı akımın ($i_L$) ve aynı gerilimin ($v_L$) oluşması demektir.
  - Norton teoremi: aynı devre, ideal olmayan bir akım kaynağına ($I_N$ ile paralel $R_N$) eşdeğerdir. Thevenin'den Norton'a kaynak dönüşümüyle geçilir: $R_N = R_{TH}$, $I_N = V_{TH}/R_{TH}$.
- Thevenin eşdeğerini bulmanın dört yöntemi (ekrandan, 00:10:00 - 00:35:00)
  - Yöntem 1: Art arda kaynak dönüşümü yaparak devreyi tek gerilim kaynağı ve tek seri dirence indirgemek.
  - Yöntem 2: Yükü açıp açık devre gerilimini ($V_{OC}$), sonra yükü kısa devre edip kısa devre akımını ($I_{SC}$) bulmak. $V_{TH} = V_{OC}$, $R_{TH} = V_{OC}/I_{SC}$. Uygulamada voltmetre ve ampermetreyle de ölçülebilir.
  - Yöntem 3: $V_{OC}$'yi bulduktan sonra bütün bağımsız kaynakları sıfırlayıp (gerilim kaynağı kısa devre, akım kaynağı açık devre) terminallerden görülen eşdeğer direnci bulmak: $R_{TH} = R_{eq}$.
  - Yöntem 4 (test kaynağı): $V_{OC}$'yi bulduktan sonra bağımsız kaynakları sıfırlayıp terminallere bir test kaynağı (örneğin 1 A ya da 1 V) bağlamak: $R_{TH} = V_{test}/I_{test}$. Devrede bağımlı kaynak varsa çalışması garanti olan tek yöntem budur.
- Thevenin/Norton örnekleri
  - Yöntem 1-4 aynı devreyle gösterildi: 12 V, 3 Ω, 6 Ω, 7 Ω (ekrandan, 00:25:00). Kaynak dönüşümüyle 4 A ∥ 3 Ω → $3\parallel6 = 2$ Ω → 8 V + 2 Ω → $2+7 = 9$ Ω. $V_{OC} = 12\cdot\frac{6}{3+6} = 8$ V, $I_{SC} = 8/9 \approx 0.889$ A, $R_{TH} = 9$ Ω.
  - 4 V, 2 kΩ, 2 mA, 3 kΩ devresinin 1 kΩ yüke göre eşdeğeri (ekrandan, 00:40:00): süperpozisyonla $V_{OC} = 4 + 0.002\cdot2000 = 8$ V; $R_{TH} = 2+3 = 5$ kΩ; Norton akımı $8/5 = 1.6$ mA.
  - 3 V, 2 kΩ, 7 mA (aşağı yönlü), 5 kΩ, 1 kΩ devresi (ekrandan, 00:45:00): $V_{TH} = -7.857$ V, $R_{TH} = 2\parallel5 + 1 = 2.429$ kΩ, $I_N = -3.235$ mA.
  - Bağımlı kaynaklı örnek (ekrandan, 00:50:00): 4 V, 2 kΩ, $v_x/4000$ bağımlı akım kaynağı, 3 kΩ; $V_{OC} = v_x = 8$ V. Derste 1 V test kaynağıyla $R_{TH} = 10$ kΩ bulundu; slayttaki $I_{SC} = 4/5000 = 0.8$ mA yolu da $8/0.8\text{ mA} = 10$ kΩ verir.
  - Akım kontrollü gerilim kaynaklı ($1.5i$) ve bağımsız kaynağı olmayan örnekte $V_{OC} = 0$; 1 A test kaynağıyla $R_{TH} = 0.6$ Ω bulundu. <!-- BELİRSİZ: bu örneğin slaytı karelerde görünmüyor; devre altyazıdan kuruldu. -->
- Maksimum güç aktarımı (ekrandan, 01:00:00 ve 01:25:00)
  - Gerçek kaynaktan yüke aktarılan güç: $p_L = i_L v_L = \dfrac{v_L^2}{R_L} = \dfrac{v_s^2 R_L}{(R_s+R_L)^2}$.
  - $R_L = 0$ ve $R_L \to \infty$ iken güç sıfırdır; aradaki tepe noktası $\dfrac{dp_L}{dR_L} = 0$ koşulundan bulunur: $R_L = R_s$.
  - En büyük güç $p_{max} = \dfrac{v_s^2}{4R_s}$; Thevenin eşdeğeriyle genelleştirilince $R_L = R_{TH}$ ve $p_{max} = \dfrac{V_{TH}^2}{4R_{TH}}$.
  - Örnek (ekrandan, 01:30:00): ortak emetörlü BJT kuvvetlendirici modeli. $R_{TH} = 1$ kΩ, $v_{oc} = -30v_\pi$, $v_\pi = (2.5\times10^{-3}\sin 440t)\frac{3864}{300+3864}$, $p_{max} = 1.211\sin^2 440t$ μW.
- Ek örnekler (çözüm yolu anlatıldı, ayrıntılı çözüm öğrenciye bırakıldı)
  - Süperpozisyonla $i_o$ (ekrandan, 01:35:00): her alt devre bağımlı kaynakla birlikte üç bilinmeyenle çözülür.
  - Kaynak dönüşümüyle $v_x$: dönüşümlerle devre tek çevrime indirgenir. <!-- BELİRSİZ: devre karelerde görünmüyor. -->
  - Bağımlı kaynaklı ($2v_x$) Thevenin örneği (ekrandan, 01:40:00): $R_{TH}$ için 1 V test kaynağı ve üç çevre, $V_{OC}$ için $i_1 = 5$ A ve $V_{OC} = 6i_2$.
  - Maksimum güç örneği: $R_{TH} = 2 + 3 + (6\parallel12) = 9$ Ω, yani $R_L = 9$ Ω. <!-- BELİRSİZ: devre karelerde görünmüyor; değerler altyazıdan. -->
- Kondansatör (kapasite elemanı)
  - İki iletken plaka arasında yalıtkan (dielektrik) malzemeden oluşur: $C = \varepsilon A/d$, $\varepsilon = \varepsilon_r\varepsilon_0$ (ekrandan, 01:50:00). Alan büyüdükçe ve plakalar yaklaştıkça kapasite artar.
  - Seramik (yönsüz) ve elektrolitik (yönlü) kondansatörler. Elektrolitik kondansatörün eksi ucu kaynağın referans ucuna bağlanır; ters bağlanırsa şişip patlayabilir.
  - Değer kodu: ilk iki rakam iki basamaklı sayı, üçüncü rakam 10'un kuvveti, birim pikofarad (örneğin 102 → 1000 pF = 1 nF).
  - Değişken kapasiteler (plaka yüzeyi mekanik olarak değiştirilir) ve mikro-elektromekanik (MEMS) kapasiteler, özellikle RF devrelerinde.
  - DC kararlı durumda açık devre gibi davranır; gerilimi süreklidir, ani sıçrama yapmaz; ideal kondansatör enerji harcamaz, depolar ve geri verir (ekrandan, 01:55:00).
  - Gerçek kondansatör: ideal kondansatöre paralel bir kaçak direnç.
  - Bağıntılar (ekrandan, 02:00:00 ve 02:05:00): $q = Cv_C$; $i_C = \dfrac{dq}{dt} = C\dfrac{dv_C}{dt}$; $v_C = \dfrac{1}{C}\displaystyle\int_{t_0}^{t_1} i_C\,dt$. Birim: farad; coulomb = farad·volt; $\varepsilon_0$'ın birimi F/m.
  - Güç ve enerji: $p = v_C i_C = C v_C \dfrac{dv_C}{dt}$, $w = \tfrac{1}{2}Cv_C^2 = \dfrac{q^2}{2C}$.
  - Şarj ve deşarj (ekrandan, 02:10:00 ve 02:15:00): şarjda $v(t) = V_c(1-e^{-t/\tau})$, deşarjda $v(t) = V_c e^{-t/\tau}$, $\tau = RC$. Pratikte $5\tau$ sonunda tam şarj/deşarj kabul edilir. Denklemlerin türetilmesi sonraki derse bırakıldı.
  - Paralel kondansatörler: $C_{eq} = C_1 + C_2 + \dots + C_N$. Seri kondansatörler: $\dfrac{1}{C_{eq}} = \dfrac{1}{C_1} + \dots + \dfrac{1}{C_N}$.
- Bobin (endüktans elemanı)
  - Bir çekirdek (hava ya da başka malzeme) etrafına sarılmış iletkendir; enerjiyi akımın oluşturduğu manyetik alanda depolar.
  - DC kararlı durumda kısa devre gibi davranır.
  - Birim henry: $1\text{ H} = 1\text{ V·s/A}$. Akı $\phi = Li$; $v_L = L\dfrac{di}{dt}$; $i_L = \dfrac{1}{L}\displaystyle\int_{t_0}^{t_1} v_L\,dt$ (ekrandan, 02:25:00). Enerji $w = \tfrac{1}{2}Li^2$.
  - Selenoid endüktansı kesit alanına, sarım sayısına, uzunluğa ve malzeme katsayısına bağlıdır; $\mu_0$'ın birimi H/m. Düz tellerde bile istenmeyen (parazitik) endüktans vardır.
  - Bobin akımı süreklidir, ani sıçrama yapmaz.
  - Gerçek bobin: seri bir tel direnci ve sarımlar arasından gelen küçük paralel parazitik kapasite.
  - Seri bobinler: $L_{eq} = L_1 + \dots + L_N$; paralel bobinler: $\dfrac{1}{L_{eq}} = \dfrac{1}{L_1} + \dots + \dfrac{1}{L_N}$ (ekrandan, 02:35:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Bağımlı kaynak varsa test kaynağı yöntemi kullanılmalı
  - Kaynaklar sıfırlanıp yalnız direnç birleştirmesi yapılırsa bağımlı kaynağın etkisi görülemez. Bağımlı kaynak devrede kalır; sıfırdan farklı, anlamlı bir test kaynağı bağlanır.
  - Test kaynağının türü (1 A akım ya da 1 V gerilim) devrenin yapısına göre seçilir: kaynaklar sıfırlandıktan sonra tek düğüm çiftine dönüşen devrede gerilim, tek çevreye dönüşen devrede akım kaynağı daha pratiktir.
- Yöntem 2 (açık devre gerilimi + kısa devre akımı) önemlidir
  - Bu yöntemde devre istenen herhangi bir yöntemle (düğüm, çevre) çözülebilir; Yöntem 1 ise yalnız kaynak dönüşümüne dayanır.
- Gerilim kaynağının akımını kaynak değil, devredeki diğer elemanlar belirler
  - Gerilim kaynağı yalnız iki ucu arasındaki gerilim farkını belirler.
- Kondansatörde gerilim, bobinde akım sürekli olmalıdır
  - Sonraki derslerde RC ve RL devrelerinde anahtarlama anının hemen öncesi ve hemen sonrası için bu süreklilik sınır koşulu (ek denklem) olarak kullanılacak.
- Elektrolitik kondansatörün yönü
  - Eksi ucu kaynağın referans ucuna bağlanmalıdır.
- Mutlaka bilinmesi gereken kavramlar
  - Düğüm analizi ve süper düğüm (bir ucu referansta olmayan gerilim kaynağı), çevre analizi ve süper çevre (iki çevrenin paylaştığı akım kaynağı), kaynak dönüşümü, doğrusallık, süperpozisyon, Norton/Thevenin eşdeğerleri ve maksimum güç aktarımı.

## Kısa Tekrar Notları

- Thevenin: $V_{TH}$ + seri $R_{TH}$; Norton: $I_N$ + paralel $R_N$; $R_N = R_{TH}$, $I_N = V_{TH}/R_{TH}$.
- $V_{TH} = V_{OC}$ (yük çıkarılıp açık devre gerilimi).
- $R_{TH} = V_{OC}/I_{SC}$ ya da kaynaklar sıfırlanınca görülen $R_{eq}$ ya da $V_{test}/I_{test}$.
- Kaynak sıfırlama: gerilim kaynağı → kısa devre, akım kaynağı → açık devre; bağımlı kaynak kalır.
- Bağımlı kaynak varsa test kaynağı yöntemi.
- Maksimum güç: $R_L = R_{TH}$, $p_{max} = V_{TH}^2/(4R_{TH})$.
- Kondansatör: $q = Cv$, $i = C\,dv/dt$, $w = \tfrac12 Cv^2$; DC'de açık devre; gerilimi sürekli.
- Bobin: $\phi = Li$, $v = L\,di/dt$, $w = \tfrac12 Li^2$; DC'de kısa devre; akımı sürekli.
- $\tau = RC$; şarj/deşarj yaklaşık $5\tau$'da tamamlanır.
- Kondansatörler: paralel toplanır, seri ters toplanır. Bobinler dirençler gibi birleşir.

## Detaylı Açıklamalar

- Yöntemlerin aynı devrede karşılaştırılması: 12 V kaynak, 3 Ω seri, 6 Ω paralel ve 7 Ω seri dirençten oluşan devrede açık devrede 7 Ω'dan akım geçmez; $V_{OC}$, 6 Ω üzerindeki gerilimdir: $12\cdot 6/9 = 8$ V. Kısa devrede ortadaki düğüm için $\frac{V-12}{3} + \frac{V}{6} + \frac{V}{7} = 0$ yazılır; 42 ortak paydasıyla $27V = 168$, $V \approx 6.22$ V, $I_{SC} = V/7 \approx 0.889$ A $= 8/9$ A, $R_{TH} = 8/(8/9) = 9$ Ω. Yöntem 3'te 12 V kısa devre edilir: $3\parallel6 = 2$ Ω, $2 + 7 = 9$ Ω. Yöntem 4'te terminallere 1 V test kaynağı bağlanır: $\frac{V}{3} + \frac{V}{6} + \frac{V-1}{7} = 0 \Rightarrow V = 2/9$ V; 7 Ω'dan geçen akım $1/9$ A, $R_{TH} = 1/(1/9) = 9$ Ω. Dört yöntem de $V_{TH} = 8$ V, $R_{TH} = 9$ Ω verir.
- Yöntem 1'de yükteki güç parametrik yazılabilir: $i = \frac{8}{9 + R_L}$, $P_L = i^2 R_L$.
- 3 V/7 mA örneği (ekrandan, 00:45:00): 1 kΩ'dan akım geçmediği için $V_{OC}$, 5 kΩ üzerindeki gerilimdir. Düğüm denklemi $\frac{V-3}{2000} + 0.007 + \frac{V}{5000} = 0$; hoca önce yanlışlıkla 3000 yazdı, sonra düzeltti. Sonuç $V = -55/7 \approx -7.857$ V. Kaynaklar sıfırlanınca $R_{TH} = \frac{1}{1/2000 + 1/5000} + 1000 = \frac{10000}{7} + 1000 \approx 2.429$ kΩ.
- Bağımlı kaynaklı örnek (ekrandan, 00:50:00 ve 00:55:00): açık devrede 3 kΩ'dan akım geçmez, bu yüzden $v_x$ aynı zamanda bağımlı akım kaynağının uçlarındaki gerilimdir. Tek çevre denklemi $-4 + 2000\left(-\frac{v_x}{4000}\right) + v_x = 0$ ile $v_x = 8$ V $= V_{OC}$. $R_{TH}$ için 4 V kısa devre edilir, terminallere 1 V bağlanır; bu durumda $v_x = 1$ V ve bağımlı kaynak $1/4000$ A olur. Orta düğüm: $\frac{V}{2000} - \frac{1}{4000} + \frac{V-1}{3000} = 0 \Rightarrow V = 0.7$ V. Test kaynağından çekilen akım $\frac{1-0.7}{3000} = 10^{-4}$ A, $R_{TH} = 1/10^{-4} = 10$ kΩ.
- $1.5i$ örneği: terminalde $V_{OC} = 0$ olduğu için Thevenin eşdeğeri yalnız bir dirençtir. 1 A test akım kaynağı bağlanınca terminal akımı $i = -1$ A, bağımlı kaynağın düğümü $1.5\cdot(-1) = -1.5$ V olur. Ara düğüm için $\frac{x + 1.5}{3} + \frac{x}{2} - 1 = 0 \Rightarrow x = 0.6$ V; $V_{test} = 0.6$ V, $R_{TH} = 0.6/1 = 0.6$ Ω.
- Maksimum güç türetmesi: $p_L = \frac{v_s^2 R_L}{(R_s+R_L)^2}$ bölüm kuralıyla türetilir: $\frac{dp_L}{dR_L} = \frac{(R_s+R_L)^2 v_s^2 - 2v_s^2 R_L (R_s+R_L)}{(R_s+R_L)^4}$. Pay sıfıra eşitlenince $R_s + R_L = 2R_L$, yani $R_L = R_s$. Yerine konunca $p_{max} = \frac{v_s^2 R_s}{4R_s^2} = \frac{v_s^2}{4R_s}$.
- BJT örneği (ekrandan, 01:30:00): bağımsız kaynak sıfırlanınca $v_\pi = 0$, bağımlı kaynak da sıfır olur; 1 V test kaynağından 1 mA akar, $R_{TH} = 1$ kΩ. $5\parallel17 \approx 3864$ Ω, $v_\pi = v_s\frac{3864}{300+3864}$, $v_{oc} = -0.03v_\pi\cdot1000 = -30v_\pi$. $R_L = 1$ kΩ seçilince $p_{max} = V_{TH}^2/(4R_{TH}) = 1.211\sin^2 440t$ μW.
- Kondansatörün çalışma mantığı: boş kondansatör kaynağa bir direnç üzerinden bağlanınca başta yükü hızlı kabul eder; plakalarda yük biriktikçe oluşan gerilim kaynak gerilimine yaklaşır ve yük kabul isteği azalır. Deşarjda da başta hızlı, sonra yavaşlayarak boşalır. Yük bir anda taşınamadığı için gerilim süreklidir.
- Kondansatörün kuvvetlendiricilerdeki kullanımı: DC'de açık devre olduğu için transistörün DC çalışma noktasını bozmadan küçük genlikli AC işaretin kuvvetlendiriciye aktarılmasında seri kondansatör kullanılır.
- Eşdeğer kapasite türetmesi: paralel bağlamada hepsinde aynı $v$ vardır, $i_{in} = (C_1 + \dots + C_N)\frac{dv}{dt}$. Seri bağlamada hepsinden aynı akım geçer, $v_{in} = \left(\frac{1}{C_1} + \dots + \frac{1}{C_N}\right)\int i\,dt$.
- Eşdeğer endüktans türetmesi: seride $v_{in} = (L_1 + \dots + L_N)\frac{di}{dt}$; paralelde $i_{in} = \left(\frac{1}{L_1} + \dots + \frac{1}{L_N}\right)\int v\,dt$.
- Ders sonrası notlar
  - Hoca $1.5i$ örneğinde sonucu "0.6 volt" dedi; $R_{TH}$ için doğrusu 0.6 Ω.
  - Hoca 1 V test kaynaklı ilk örnekte test değerini "1 amper" dedi; doğrusu 1 V.
  - Hoca deşarj süresi için bir yerde "1 bölü RC'nin 5 katı" dedi; doğrusu $5\tau = 5RC$ (hoca daha sonra $\tau = RC$ diye düzeltti).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
