# Ders 25 Çalışma Özeti

## Genel Konular

- İşlemsel yükselteç (op-amp) kavramı
  - Op-amp (operational amplifier, işlemsel yükselteç), girişteki gerilimi çıkışta yükselten bir devre elemanıdır. "Yükseltme" pozitif yönde olmak zorunda değildir; çıkış negatif yönde de büyüyebilir, yani işaret de değişebilir.
  - Kullanım alanları: eviren ve evirmeyen yükselteçler, toplayıcı (summing), fark alıcı (difference / subtractor), kaskat (ardışık) yükselteçler, gerilim kıyaslayıcı ve gerilim izleyici.
  - Dersin başındaki hedef slaytında birinci dereceden op-amp devreleri (türev ve integral alıcı) da vardı, ama bu devreler işlenmeden geçildi.
- Op-amp sembolü ve bacakları
  - Sembol bir üçgendir. "+" giriş evirmeyen (non-inverting), "−" giriş eviren (inverting) giriştir. Bunlara ek olarak $V^+$ ve $V^-$ besleme bacakları ve çıkış bacağı vardır.
  - Ekranda uA741, LM111 ve LM324 sembolleri ile LM741 entegresinin 8 bacaklı kılıf şeması gösterildi: 2 eviren giriş, 3 evirmeyen giriş, 4 $V^-$, 7 $V^+$, 6 çıkış, 1 ve 5 offset null, 8 NC (ekrandan, 00:25:00 ve 00:30:00).
- Besleme gerilimiyle sınırlama (doyum)
  - Teoride ideal op-amp'ın kazancı sonsuz kabul edilir. Pratikte çıkış besleme gerilimlerini aşamaz.
  - Ekrandaki örnek: kazancı 10 olan bir devreye 10 V verilirse 100 V beklenir, ama besleme ±15 V ise çıkış 15 V'ta kalır (ekrandan, 00:25:00).
- İdeal op-amp'ın iki kabulü
  - Op-amp'ın giriş bacaklarından içeri akım girmez: $i_1 = i_2 = 0$. Gerekçe: iç direnç $R_i \to \infty$, yani girişler arası açık devredir.
  - İki girişin gerilimi eşittir: $v_1 = v_2$ ($v_d = 0$). Bir giriş topraklıysa diğer giriş "sanal toprak" (virtual ground) olur.
- Gerilim kıyaslayıcı (comparator)
  - Geri besleme yoktur. Hangi girişin gerilimi daha büyükse çıkış o girişin işaretine karşılık gelen beslemeye gider: $v_2 > v_1$ ise $+V$, $v_1 > v_2$ ise $-V$.
- Kazanç türleri
  - Gerilim kazancı $A_v = v_o / v_s$. Akım kazancı $i_o / i_s$. Geçiş direnci (transresistance) $v_o / i_s$ ve geçiş iletkenliği (transconductance) $i_o / v_s$ da sorulabilir.
- Temel devreler ve kazançları
  - Eviren yükselteç: $A_v = -R_f / R_1$.
  - Evirmeyen yükselteç: $A_v = 1 + R_f / R_1$.
  - Gerilim izleyici (voltage follower): $A_v = 1$.
  - Eviren toplayıcı: $v_o = -\left(\frac{R_f}{R_A}V_A + \frac{R_f}{R_B}V_B + \frac{R_f}{R_C}V_C\right)$. Süperpozisyonla çıkarıldı.
  - Fark alıcı: evirmeyen girişteki gerilim gerilim bölücüden bulunur, sonra düğüm denklemi yazılır. $R_A/R_f = R_B/R_C$ ise $v_o = \frac{R_f}{R_A}(V_B - V_A)$; bütün dirençler eşitse $v_o = V_B - V_A$.
  - Kaskat yükselteç: toplam kazanç, katların kazançlarının çarpımıdır: $A_{v,toplam} = A_{v1} A_{v2}$.

## Hocanın Özellikle Vurguladığı Kısımlar

- Formül ezberlemek yerine formülü çıkarmayı bilmek
  - Hoca formülleri ezberlemenin karışıklığa yol açtığını birkaç kez söyledi. Devreye fazladan bir direnç eklenince ya da giriş diğer uca bağlanınca ezberlenmiş formül tutmaz. İki kabul ve akım eşitliğiyle denklem her durumda yeniden kurulabilir.
  - Örnek: evirmeyen girişe toprakla arasına bir direnç konursa o girişten akım akmadığı için gerilim yine sıfırdır, formül değişmez. Ama gerilim bölücü oluşturacak biçimde bir direnç eklenirse önce o düğümün gerilimi bulunmalıdır.
- İki kabul soru çözmenin temelidir
  - Soruda op-amp'ın ideal olmadığı ve iç direnci verilmedikçe $i_1 = i_2 = 0$ ve $v_1 = v_2$ kabul edilir. İdeal olmayan durumda $v_d / R_i$ akımı da hesaba katılmalıdır ve denklemler zorlaşır.
- Doyum sınırlarını unutmamak
  - Hesaplanan çıkış besleme gerilimini aşıyorsa çıkış beslemede kalır. Giriş-çıkış grafiğinde eğim kazancı verir, uçlar düz (sınırlanmış) kalır.
- "Toplayıcı" doğrudan toplamaz
  - Eviren toplayıcı girişlerin direnç oranlarıyla ağırlıklı toplamının negatifini verir. Örnekte girişler 1 V, 3 V, −2 V iken çıkış −12 V çıktı. Doğrudan toplam için direnç değerlerinin buna göre seçilmesi gerekir.
- Kavramı mantıkla kurmak FET konusunda da geçerli
  - Hoca dersin sonunda aynı yaklaşımın önceki FET konusu için de geçerli olduğunu söyledi: $V_{GS}$'nin negatif olmasının drain akımını düşürdüğü gibi ilişkiler ezberle değil, mantıkla kurulmalıdır; N-kanal yerine P-kanal sorulduğunda işaretlerin nasıl değişeceği anlaşılmalıdır.

## Kısa Tekrar Notları

- İdeal op-amp: $R_i \to \infty$, $i_1 = i_2 = 0$, $v_1 = v_2$, kazanç sonsuz kabul edilir.
- Çıkış her zaman $V^-$ ile $V^+$ arasında kalır.
- Kıyaslayıcı: $v_2 > v_1 \Rightarrow +V$; $v_1 > v_2 \Rightarrow -V$.
- Eviren: $A_v = -R_f/R_1$; 1 kΩ ve 10 kΩ ile $A_v = -10$.
- Evirmeyen: $A_v = 1 + R_f/R_1$; 1 kΩ ve 10 kΩ ile $A_v = 11$.
- İzleyici: $A_v = 1$, girişi çıkışa aynen aktarır.
- Toplayıcı: süperpozisyon; her kaynak tek başına bırakılır, diğer gerilim kaynakları kısa devre edilir, sonuçlar toplanır.
- Fark alıcı: önce gerilim bölücüyle $V^+$, sonra $\frac{V_A - V^+}{R_A} = \frac{V^+ - v_o}{R_f}$.
- Kaskat: $A_{v,toplam} = A_{v1} A_{v2}$; ya da kademeli çözüm: ilk katın çıkışı ikinci katın girişi olur.

## Detaylı Açıklamalar

- Eviren yükselteçte kazancın çıkarılışı
  - Evirmeyen giriş topraklıdır ($v_2 = 0$), ikinci kabulden $v_1 = 0$ olur. Girişten gelen akım $i_s = \frac{v_s - v_1}{R_1}$, geri besleme direncinden geçen akım $i_f = \frac{v_1 - v_o}{R_f}$'dir. Birinci kabulden op-amp'a akım girmediği için $i_s = i_f$. $v_1 = 0$ yazılınca $\frac{v_s}{R_1} = -\frac{v_o}{R_f}$, buradan $\frac{v_o}{v_s} = -\frac{R_f}{R_1}$ bulunur (ekrandan, 00:40:00). Eksi işaret, giriş eviren uca bağlandığı için çıkışın ters işaretli olmasından gelir.
- Eviren yükselteç sayısal örneği (ekrandan, 00:45:00)
  - $R_1 = 1\,k\Omega$, $R_f = 10\,k\Omega$, $V^+ = 15$ V, $V^- = -10$ V. Kazanç $-10$'dur.
  - $v_s = 0{,}5$ V için $v_o = -5$ V; $v_s = 1$ V için $-10$ V. $v_s = 1{,}1$ V için $-11$ V beklenir ama çıkış $-10$ V'ta sınırlanır. $v_s = 2$ V için de $-20$ V değil $-10$ V olur. $v_s = -5$ V için $+50$ V değil $+15$ V çıkar. $v_s = -1{,}2$ V için $+12$ V sınır içindedir (python ile doğrulandı).
- Evirmeyen yükselteçte kazancın çıkarılışı (ekrandan, 00:50:00)
  - Giriş evirmeyen uçtadır: $v_2 = v_s$, dolayısıyla $v_1 = v_s$. $R_1$'in diğer ucu topraktır: $i_s = \frac{0 - v_s}{R_1}$, $i_f = \frac{v_s - v_o}{R_f}$. $i_s = i_f$ eşitliğinden $-\frac{R_f}{R_1} = 1 - \frac{v_o}{v_s}$, yani $\frac{v_o}{v_s} = 1 + \frac{R_f}{R_1}$.
  - Aynı dirençlerle kazanç $1 + 10 = 11$'dir; $v_s = 0{,}5$ V için $v_o = 5{,}5$ V. Kazanç pozitiftir, çünkü giriş evirmeyen uçtadır.
- Gerilim kıyaslayıcı örneği (ekrandan, 00:35:00)
  - $v_s$ eviren girişte, $v_2 = 5$ V evirmeyen girişte, geri besleme yok. $v_s = 0$ V iken $v_2 > v_1$ olduğundan çıkış $+V$; $v_s = 5$ V iken girişler eşit olduğundan hocanın anlatımıyla çıkış 0; $v_s = 6$ V iken $v_1 > v_2$ olduğundan çıkış $-V$ olur.
  - Hoca kıyaslayıcının sıcaklık sensörü gibi bir girişle eşik aşıldığında bir anahtarlama işareti üretmek için kullanılabileceğini söyledi.
- Eviren toplayıcı ve süperpozisyon (ekrandan, 00:55:00)
  - $R_A = 5\,k\Omega$, $R_B = 2\,k\Omega$, $R_C = 4\,k\Omega$, $R_f = 10\,k\Omega$; $V_A = 1$ V, $V_B = 3$ V, $V_C = -2$ V.
  - $v_o = -[2V_A + 5V_B + 2{,}5V_C] = -[2 + 15 - 5] = -12$ V.
  - Bütün dirençler 10 kΩ yapılırsa $v_o = -(1 + 3 - 2) = -2$ V olur: toplam alınır ama işaret ters döner (ekrandan, 01:00:00).
- Fark alıcı örneği (ekrandan, 01:05:00)
  - $V_A = 2$ V, $R_A = 6\,k\Omega$, $R_f = 30\,k\Omega$; $V_B = 3$ V, $R_B = 8\,k\Omega$, $R_C = 4\,k\Omega$.
  - $V^+ = 3 \cdot \frac{4}{12} = 1$ V. $\frac{2 - 1}{6} = \frac{1 - v_o}{30}$, buradan $v_o = -4$ V. Slayttaki genel formül de aynı sonucu verir (python ile doğrulandı).
- Kaskat yükselteç (ekrandan, 01:10:00)
  - Birinci kat evirmeyen ($R_1 = 5\,k\Omega$, $R_{f1} = 15\,k\Omega$, $v_s = 2$ V), ikinci kat eviren ($R_2 = 2\,k\Omega$, $R_{f2} = 8\,k\Omega$) yükselteçtir. Toplam kazanç iki kazancın çarpımıdır.
  - Hoca iki yol gösterdi: kazançları çarpmak ya da birinci katın çıkışını bulup onu ikinci katın girişi olarak kullanmak. İkincisini, devre standart biçimden saptığında daha güvenilir bulduğunu söyledi.
- Ders sonrası notlar
  - Kaskat örneği slaytındaki formülde birinci katın kazancı $\left(1 + \frac{R_{f2}}{R_1}\right)$ diye yazılmış; doğrusu $\left(1 + \frac{R_{f1}}{R_1}\right)$'dir. Değerlerle $v_{o1} = 4 \cdot 2 = 8$ V ve ideal hesapla $v_o = -4 \cdot 8 = -32$ V çıkar; bu sonuç derste hesaplanmadı, python ile kontrol edildi. Slaytta besleme verilmediği için doyum durumu belirtilmemiştir.
  - Hoca dersin başında türev ve integral alıcı devreleri bir yerde "ikinci dereceden" diye andı. Tek kapasitörlü türev ve integral alıcılar birinci dereceden devrelerdir (dersin hedef slaytında da "1st order" diye geçer); ikinci dereceden devreler iki enerji depolayıcı (ör. RLC) içerir.
  - Hoca geri besleme direnci için "ileri besleme" ifadesini de kullandı; $R_f$ geri besleme (feedback) direncidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
