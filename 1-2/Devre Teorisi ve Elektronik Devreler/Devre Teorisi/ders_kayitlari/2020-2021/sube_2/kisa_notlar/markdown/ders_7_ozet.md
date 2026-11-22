# Ders 7 Çalışma Özeti

## Genel Konular

- Kondansatörün şarj ve deşarj davranışı (animasyonla tekrar)
  - Kondansatör bir kaynağa bağlandığında plakalar arasındaki dielektrik kutuplanır ve yük birikir. Şarj önce çok hızlı başlar, sonra yavaşlayarak bir doyma değerine yaklaşır.
  - Şarj tamamlanınca akım durur. Bu yüzden kararlı durumda (DC) kondansatör açık devre gibi davranır.
  - Deşarjda da akım başta büyüktür ve giderek azalır. Animasyonda şarjlı kondansatör bir motoru çalıştırarak boşalıyordu.
- İşlemsel yükselteç (op-amp) ve kullanım alanları
  - Op-amp (operational amplifier, işlemsel yükselteç ya da işlemsel kuvvetlendirici), iki girişi arasındaki gerilim farkını bir kazanç katsayısıyla çarpıp çıkışa veren devre elemanıdır.
  - "Yükseltme" yalnız sayısal büyütme değildir. Çıkışın işareti ters olabilir (+5 V girişten −7 V çıkış gibi); burada genlik büyür. Kazanç 1'den küçük de seçilebilir.
  - Kullanım alanları: ses yükseltme (mikrofon, hoparlör), biyomedikal sistemler (EKG gibi, gürültüden az etkilenen yükselteç gerekir), güç elektroniği.
- Op-amp sembolü ve uçları
  - Şemada üç uçla çizilir: eviren giriş (−), evirmeyen giriş (+) ve çıkış. Gerçek entegrede ayrıca pozitif ve negatif besleme uçları vardır.
  - Örnek entegre LM324. Bacak numaraları datasheet'teki kılıf (paket) diyagramından okunur; kılıftaki çentik yönü bacak sırasını belirler.
- Op-amp eşdeğer devresi (ekrandan, 00:15:00)
  - Girişler arasında büyük bir giriş direnci $R_i$ vardır. Fark gerilimi $v_d = v_2 - v_1$ ($v_2$: evirmeyen, $v_1$: eviren giriş).
  - İçeride gerilim kontrollü gerilim kaynağı $A v_d$ ve ona seri küçük bir çıkış direnci $R_o$ bulunur. $A$ açık çevrim gerilim kazancıdır.
- Tipik op-amp parametreleri (ekrandan, 00:20:00)
  - Açık çevrim kazancı $A$: $10^5$–$10^8$, ideali $\infty$.
  - Giriş direnci $R_i$: $10^5$–$10^{13}\ \Omega$, ideali $\infty$.
  - Çıkış direnci $R_o$: $10$–$100\ \Omega$, ideali $0$.
  - Besleme: $V^+$ için 5–30 V, $V^-$ için −30–0 V.
- İdeal op-amp kabulleri
  - Giriş akımları sıfırdır: $i_1 = i_2 = 0$ (çünkü $R_i \to \infty$, girişler açık devre gibidir).
  - Giriş gerilimleri eşittir: $v_1 = v_2$ (negatif geri beslemeli devrelerde).
  - $R_o = 0$ kabul edilir.
- Frekansın etkisi
  - Giriş AC ise frekans arttıkça op-amp'ın kazancı azalır. Derste yalnız DC analiz yapılır.
- Doyum (saturation) ve besleme sınırı (ekrandan, 00:25:00)
  - Çıkış besleme gerilimlerini aşamaz. $A v_d > V^+$ ise $v_o \approx V^+$ (pozitif doyum); $V^- < A v_d < V^+$ ise $v_o = A v_d$ (doğrusal bölge); $A v_d < V^-$ ise $v_o \approx V^-$ (negatif doyum).
  - Hocanın örneği: $\pm 18$ V beslemede $A = 10$, $v_d = 5$ V için hesap 50 V verir, ama çıkış +18 V'ta kalır.
- Gerilim karşılaştırıcı (açık çevrim) (ekrandan, 00:30:00)
  - Geri besleme yoktur, $A$ ideal olarak sonsuz kabul edilir. Çok küçük bir fark bile çıkışı beslemeye götürür.
  - $V_s$ eviren girişe, evirmeyen giriş toprağa bağlıysa: $V_s = 0$ için $v_o = 0$; $V_s < 0$ için $v_o = V^+$; $V_s > 0$ için $v_o = V^-$.
- Kapalı çevrim kazancı ve eviren yükselteç (ekrandan, 00:40:00)
  - Çıkıştan eviren girişe $R_f$ ile geri besleme yapılır. $i_s = i_f$ ve $v_1 = v_2 = 0$ kabulleriyle $\dfrac{V_s}{R_1} = -\dfrac{v_o}{R_f}$ ve $A_v = \dfrac{v_o}{V_s} = -\dfrac{R_f}{R_1}$ bulunur.
- Gerçek op-amp ile kapalı çevrim (ekrandan, 00:45:00)
  - $R_i$ ve $R_o$ hesaba katılırsa $i_s = i_1 + i_f$, $i_1 = -i_2$, $v_d = R_i i_2$ ve $v_o$ içinde $R_o$ üzerindeki düşüm yer alır. Denklemler çok karmaşıklaşır; bu yüzden sorularda ideal model kullanılır.
- Kazanç türleri
  - Gerilim kazancı $A_v = v_o/v_s$, akım kazancı $A_i = i_o/i_s$, geçiş direnci (transresistance) kazancı $v_o/i_s$, geçiş iletkenliği (transconductance) kazancı $i_o/v_s$.
- Temel op-amp devreleri
  - Eviren yükselteç: $A_v = -R_f/R_1$.
  - Evirmeyen yükselteç: $A_v = 1 + R_f/R_1$.
  - Gerilim izleyici: $v_o = v_s$, $A_v = 1$.
  - Toplayıcı: süperpozisyonla her giriş ayrı bir eviren yükselteç gibi çözülür; $v_o = -\left(\frac{R_f}{R_A}V_A + \frac{R_f}{R_B}V_B + \frac{R_f}{R_C}V_C\right)$.
  - Fark alıcı: evirmeyen girişteki gerilim bölücüden $v_2$ bulunur, $v_1 = v_2$ yazılır, sonra eviren taraf için düğüm denklemi kurulur.
  - Kaskat (ardışık) yükselteçler: her kat ayrı çözülür, birinci katın çıkışı ikincinin girişi olur; toplam kazanç $A_{v,toplam} = A_{v1} A_{v2}$.
- Ödev soruları: kaynak dönüşümü ve Thevenin eşdeğeri
  - Example 24: kaynak dönüşümüyle $v_x = 7{,}5$ V (öğrenci çözümü, iki farklı yöntemle).
  - Example 25: bağımlı kaynaklı devrenin Thevenin eşdeğeri, $R_{Th} = 6\ \Omega$, $V_{Th} = 20$ V.

## Hocanın Özellikle Vurguladığı Kısımlar

- Formül ezberlemeyin, nasıl çıktığını bilin
  - Hoca bunu ders boyunca defalarca söyledi. Devre biraz değişirse (örneğin bir kaynak eklenirse) ezber formül işe yaramaz. Önemli olan $i_1 = i_2 = 0$ ve $v_1 = v_2$ kabulleriyle düğüm denklemini kurabilmektir. Formül özeti slaytların sonunda olsa da türetme bilinmelidir.
- İdeal op-amp'ın iki kuralı
  - Girişlere akım girmez ve iki giriş gerilimi eşittir. Bütün kapalı çevrim sorular bu iki kuralla çözülür.
- Açık çevrim ile kapalı çevrimin farkı
  - Açık çevrimde (karşılaştırıcı) $A$ hesaplanmaz, sonsuz kabul edilir ve çıkış doğrudan $+V$ ya da $-V$ olur. Kapalı çevrimde kazanç dirençlerden hesaplanır.
- Besleme gerilimleri sınırlayıcıdır
  - Hesaplanan çıkış besleme aralığının dışına çıkarsa çıkış o beslemede kalır. Kazanç ne olursa olsun "yoktan var edilemez".
- Toplayıcı ve fark alıcıda sık yapılan hata
  - Toplayıcıda giriş gerilimleri doğrudan toplanmaz (1 V + 3 V − 2 V = 2 V değil); her giriş kendi direnç oranıyla çarpılır. Fark alıcıda da çıkış basitçe $3 - 2$ değildir; önce gerilim bölücüden $v_2$ bulunmalıdır.
- Thevenin ve Norton çok önemli
  - Bağımlı kaynak varsa $R_{Th}$ için test kaynağı yöntemi kullanılır: bağımsız kaynaklar söndürülür (gerilim kaynağı kısa, akım kaynağı açık devre), a-b uçlarına 1 V'luk test kaynağı bağlanır, akım bulunur, $R_{Th} = 1\ \text{V}/i_o$.
  - Bağımlı kaynak yoksa bağımsız kaynaklar söndürülüp a-b uçlarından eşdeğer direnç doğrudan hesaplanır. Direnç her zaman a-b uçlarından bakılarak bulunur.
  - $V_{oc}$ için bağımlı kaynak yoksa kaynak dönüşümü, varsa çevre (mesh) analizi en çok kullanılan yoldur.

## Kısa Tekrar Notları

- Kondansatör: şarj ve deşarj başta hızlı, sonra yavaş; DC kararlı durumda açık devre.
- Op-amp: iki giriş (− eviren, + evirmeyen), bir çıkış, iki besleme ucu.
- $v_d = v_2 - v_1$, $v_o = A v_d$ (doğrusal bölgede).
- İdeal: $A \to \infty$, $R_i \to \infty$, $R_o = 0$, $i_1 = i_2 = 0$, $v_1 = v_2$.
- Çıkış $V^-$ ile $V^+$ arasında kalır; dışına çıkan hesap doyuma gider.
- Karşılaştırıcı: geri besleme yok, çıkış $+V$, $0$ ya da $-V$.
- Eviren: $-R_f/R_1$. Evirmeyen: $1 + R_f/R_1$. İzleyici: $1$.
- Toplayıcı: $v_o = -R_f\sum V_k/R_k$ (süperpozisyon).
- Fark alıcı: $v_2 = V_B \dfrac{R_C}{R_B + R_C}$, sonra $\dfrac{V_A - v_2}{R_A} = \dfrac{v_2 - v_o}{R_f}$.
- Kaskat: kazançlar çarpılır.
- Kazanç türleri: gerilim, akım, geçiş direnci, geçiş iletkenliği.
- Bağımlı kaynaklı Thevenin: $R_{Th}$ test kaynağıyla, $V_{Th}$ açık devre gerilimiyle bulunur.

## Detaylı Açıklamalar

- Op-amp'ın iç modeli ve ideal kabuller
  - Eşdeğer devrede iki giriş arasında $R_i$, çıkışta $A v_d$ değerli bağımlı gerilim kaynağı ve seri $R_o$ vardır (ekrandan, 00:15:00). $R_i$ çok büyük olduğundan girişlerden akım çekilmez; $R_o$ çok küçük olduğundan üretilen gerilim çıkışta kaybolmaz. İdeal modelde $R_i = \infty$ girişleri açık devre yapar ($i_1 = i_2 = 0$). $A = \infty$ olduğundan, çıkış sonlu kaldıkça $v_d = v_o / A \to 0$, yani $v_1 = v_2$ olur.
  - Gerçek op-amp'ta bu kabuller yapılmazsa eviren devre için $i_s = i_1 + i_f$, $i_1 = -i_2$, $v_d = v_2 - v_1 = R_i i_2$, $V_s = R_1 i_s - v_d$ ve $V_s = R_1 i_s + R_f i_f + v_o$ gibi denklemler yazılır. Sonuç $R_i$ ve $R_o$ içeren karmaşık bir ifadedir. Sorularda ideal model kullanılır.
- Doyum ve karşılaştırıcı
  - Çıkışı üreten bağımlı kaynak, beslemenin verdiği sınırları aşamaz (ekrandan, 00:25:00). Hocanın örneğinde $\pm 18$ V beslemede $A = 10$ ve $v_d = 5$ V için $v_o = 50$ V çıkamaz, $+18$ V olur; $v_d = -5$ V için $-50$ V yerine $-18$ V olur.
  - Karşılaştırıcıda geri besleme olmadığından $A$ ideal olarak sonsuzdur. 0,1 mV'luk fark bile, örneğin $A = 10^6$ ile 100 V gibi bir değer verir; bu mümkün olmadığından çıkış doğrudan besleme gerilimine gider. Ekrandaki ikinci örnekte (ekrandan, 00:35:00) evirmeyen giriş $v_2 = 5$ V'a, $V_s$ eviren girişe bağlıdır: $V_s = 0$ V için $v_o = +V$, $V_s = 5$ V için $v_o = 0$, $V_s = 6$ V için $v_o = -V$.
- Eviren yükselteç (ekrandan, 00:40:00 ve 01:05:00)
  - $i_1 = 0$ olduğundan $i_s = i_f$: $\dfrac{V_s - v_1}{R_1} = \dfrac{v_1 - v_o}{R_f}$. Evirmeyen giriş toprakta olduğundan $v_1 = v_2 = 0$. Buradan $\dfrac{V_s}{R_1} = -\dfrac{v_o}{R_f}$ ve $A_v = -\dfrac{R_f}{R_1}$.
  - Sayısal örnek: $R_1 = 1$ kΩ, $R_f = 10$ kΩ, $V^+ = 15$ V, $V^- = -10$ V. $A_v = -10$. $V_s = 0{,}5$ V için $-5$ V; $V_s = 1$ V için $-10$ V; $V_s = 1{,}1$ V için $-11$ V çıkamaz, $-10$ V'ta doyar. Negatif girişlerde çıkış pozitiftir ve $+15$ V'ta sınırlanır. Doğrusal bölge $-1{,}5\ \text{V} \le V_s \le 1\ \text{V}$ aralığıdır.
- Evirmeyen yükselteç (ekrandan, 01:10:00)
  - $V_s$ evirmeyen girişe bağlıdır, $v_1 = v_2 = V_s$. $\dfrac{0 - V_s}{R_1} = \dfrac{V_s - v_o}{R_f}$ denkleminden $A_v = 1 + \dfrac{R_f}{R_1}$.
  - Aynı dirençlerle $A_v = 11$: $V_s = 0{,}5$ V için $5{,}5$ V; $V_s = 1{,}6$ V için $17{,}6$ V çıkamaz, $+15$ V; $V_s = -0{,}9$ V için $-9{,}9$ V; $V_s = -1{,}01$ V için $-11{,}11$ V çıkamaz, $-10$ V'ta doyar.
- Gerilim izleyici
  - Çıkış doğrudan eviren girişe bağlıdır, $V_s$ evirmeyen girişe verilir. $v_1 = v_2$ kuralından $v_o = V_s$, kazanç 1'dir.
- Toplayıcı yükselteç (ekrandan, 01:15:00)
  - Üç kaynak ($V_A = 1$ V, $V_B = 3$ V, $V_C = -2$ V) $R_A = 5$ kΩ, $R_B = 2$ kΩ, $R_C = 4$ kΩ üzerinden eviren girişe bağlıdır, $R_f = 10$ kΩ. Süperpozisyonla her seferinde bir kaynak bırakılır, diğerleri kısa devre edilir. Eviren giriş sanal toprakta (0 V) olduğundan kısa devre edilen kolların akımı sıfırdır ve her alt devre bir eviren yükseltece dönüşür: $v_{o,k} = -\frac{R_f}{R_k}V_k$.
  - Toplam: $v_o = -\left(\frac{10}{5}\cdot 1 + \frac{10}{2}\cdot 3 + \frac{10}{4}\cdot(-2)\right) = -(2 + 15 - 5) = -12$ V.
- Fark alıcı yükselteç (ekrandan, 01:20:00 ve 01:25:00)
  - $V_A = 2$ V, $R_A = 6$ kΩ üzerinden eviren girişe; $V_B = 3$ V, $R_B = 8$ kΩ ile $R_C = 4$ kΩ'luk bölücü üzerinden evirmeyen girişe bağlıdır; $R_f = 30$ kΩ.
  - $v_2 = 3 \cdot \dfrac{4}{8 + 4} = 1$ V, $v_1 = 1$ V. $\dfrac{2 - 1}{6} = \dfrac{1 - v_o}{30}$ denkleminden $v_o = -4$ V.
  - Genel ifade (ekrandan, 01:20:00): $v_o = \dfrac{R_f}{R_A}\dfrac{1 + R_A/R_f}{1 + R_B/R_C}V_B - \dfrac{R_f}{R_A}V_A$.
  - Hoca, direnç oranları uygun seçilirse ($R_f/R_A = R_C/R_B$) devrenin doğrudan iki girişin farkını o oranla çarptığını, bütün dirençler eşitse tam bir çıkarıcı olduğunu söyledi.
- Kaskat yükselteç (ekrandan, 01:30:00)
  - Birinci kat evirmeyendir: $R_1 = 5$ kΩ, $R_{f1} = 15$ kΩ, $V_s = 2$ V; $A_{v1} = 1 + 15/5 = 4$, $v_{o1} = 8$ V. İkinci kat eviren: $R_2 = 2$ kΩ, $R_{f2} = 8$ kΩ; $A_{v2} = -8/2 = -4$. Toplam kazanç $A_v = 4 \cdot (-4) = -16$.
  - Derste gösterilen bir başka karma devrede iki gerilim izleyicinin çıkışları bir fark alıcıya bağlanıyordu; çözüm yine bölücü ile $v_x$ bulup eviren taraf için düğüm denklemi yazmaktır.
- Thevenin eşdeğeri, bağımlı kaynak (ekrandan, 02:00:00 ve 02:15:00)
  - Bağımlı kaynak olmasaydı akım kaynağı açık devre yapılıp a-b'den bakılınca $R_{Th} = (4 + 2) \parallel 6 + 2 = 5\ \Omega$ bulunurdu. Bağımlı kaynak bu yolu kapattığından test kaynağı kullanılır ve sonuç $6\ \Omega$ çıkar. $V_{oc}$ çevre analiziyle $20$ V bulunur. Eşdeğer devre 20 V'luk kaynak ve seri 6 Ω'dur; aynı yük direnci iki devrede de aynı akımı ve gerilimi görür.
- Derste kaynak kitap olarak, dersin başında önerilen devre analizi kitabı yeniden anıldı. <!-- BELİRSİZ: Altyazıda kitap adı "Xiaomi" diye bozulmuş; büyük olasılıkla Alexander ve Sadiku'nun "Fundamentals of Electric Circuits" kitabı. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
