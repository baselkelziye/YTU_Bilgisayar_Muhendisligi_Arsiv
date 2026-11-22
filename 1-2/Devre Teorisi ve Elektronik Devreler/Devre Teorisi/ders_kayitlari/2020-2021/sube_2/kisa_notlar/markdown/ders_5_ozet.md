# Ders 5 Çalışma Özeti

> Kayıt iki parçadır; arşivde parçalar yanlış sırada birleştirildiği için altyazıdaki sıra düzeltildi ve saat damgaları düzeltilmiş altyazıya göredir.

## Genel Konular

- Düğüm ve çevre analizinin aynı devre üzerinde karşılaştırılması
  - Devre (ekrandan, 00:05:41): 100 V kaynak, 8 Ω seri direnç, $v_1$ düğümünden toprağa 4 Ω, $v_1$–$v_2$ arasında 2 Ω (akımı $i_x$), $v_2$'den toprağa 3 Ω, $v_2$–$v_3$ arasında 10 Ω, $v_3$'ten toprağa 5 Ω; üstte $v_3$'ten $v_2$'ye doğru 8 A akım kaynağı. İstenen: $i_x$.
  - Düğüm analizi: referans (toprak) alt düğüme konur; böylece 100 V kaynağın üst ucu doğrudan 100 V olur. Her düğüm için KCL yazılır, akımlar düğüm gerilimleri cinsinden ifade edilir.
  - $v_1 = 25{,}89$ V, $v_2 = 20{,}31$ V, $i_x = (v_1 - v_2)/2 = 2{,}79$ A.
  - Çevre analizi (ekrandan, 00:15:41): dört çevre vardır, ama $i_4 = -8$ A olduğu hemen görülür; geriye üç denklem kalır:
    - $-100 + 8i_1 + 4(i_1 - i_2) = 0 \Rightarrow 12i_1 - 4i_2 = 100$
    - $4(i_2 - i_1) + 2i_2 + 3(i_2 - i_3) = 0 \Rightarrow -4i_1 + 9i_2 - 3i_3 = 0$
    - $3(i_3 - i_2) + 10(i_3 + 8) + 5i_3 = 0 \Rightarrow -3i_2 + 18i_3 = -80$
  - Çözümde $i_2 = i_x = 2{,}79$ A çıkar. Çevre analizinin bu soruda avantajı, istenen akımın doğrudan bir çevre akımı olmasıdır.
- Doğrusallık (linearity)
  - Ohm yasası doğrusal bir fonksiyondur: akım $k$ katına çıkarsa gerilim de $k$ katına çıkar, $k \times I \times R = k \times V$ (ekrandan, 00:20:41).
  - Doğrusallığın iki yönü: ölçekleme (homojenlik) ve toplanabilirlik; ayrı ayrı girdilerin etkilerinin toplamı, toplam girdinin etkisine eşittir.
  - Çevre analizinde ortak dirence $5k(i_1 - i_2) = 5k\,i_1 - 5k\,i_2$ yazabilmemiz de doğrusallıktan gelir.
  - Güç doğrusal değildir: $P = I^2R$ olduğu için akımın karesiyle değişir.
  - Doğrusal elemanlar: direnç, bobin, kondansatör, bağımsız gerilim ve akım kaynakları, doğrusal bağımlı kaynaklar.
  - Doğrusal olmayan elemanlar: diyot (ışık yayan diyot dahil; ekrandan, 00:25:41), transistör. Diyot eşik gerilimine kadar akım geçirmez, sonra eğrisel bir karakteristikle iletime geçer.
- Doğrusallık ile ters yönden çözüm
  - Çıkıştaki büyüklük için kolay bir değer (ör. $I_0 = 1$ A) varsayılır, devre geriye doğru çözülerek kaynağın değeri bulunur; gerçek kaynak değeriyle oranlanarak gerçek çıkış bulunur.
- Süperpozisyon
  - Birden fazla bağımsız kaynak bulunan doğrusal devrede her kaynağın etkisi ayrı ayrı bulunup toplanır.
  - Adımlar (ekrandan, 00:45:41): biri dışında bütün bağımsız kaynaklar kapatılır (gerilim kaynağı yerine kısa devre, akım kaynağı yerine açık devre); bağımlı kaynaklar devrede kalır; yeni devre çözülür; sıradaki kaynak açılarak işlem tekrarlanır; en sonda katkılar toplanır.
  - Her alt devrede aynı direnç için ilk seçilen akım yönü ve gerilim kutbu değiştirilmez.
- Kaynak dönüşümü (source transformation)
  - Seri $v_s$–$R$ çifti, paralel $i_s$–$R$ çiftine dönüştürülebilir (ya da tersi): $v_s = i_s R$, $i_s = v_s / R$ (ekrandan, 01:25:41).
  - Eşdeğer devre, yük direnci üzerinde aynı akımı ($I_L$) ve aynı gerilimi ($V_L$) vermelidir.
  - Thevenin ve Norton eşdeğer devrelerinin temeli bu dönüşümdür.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bağımlı kaynaklar süperpozisyonda asla kapatılmaz
  - Bağımlı kaynak devrede kalır; çünkü değeri devredeki bir büyüklüğe (ör. $i_0$) bağlıdır ve o büyüklük her alt devrede yeniden hesaplanır.
- Kapatma kuralı
  - Gerilim kaynağı kısa devre, akım kaynağı açık devre yapılır. Bu ikisini karıştırmamak gerekir.
- Yönlerin sabit tutulması
  - İlk alt devrede bir dirence verilen kutup ve akım yönü sonraki alt devrelerde aynen korunur. Yönler karışırsa katkılar birbirini götürmesi gerekirken toplanır ve sonuç yanlış çıkar. Sonuç eksi çıkarsa gerçek yön kabul edilenin tersidir.
- Seri/paralel ayrımını doğru görmek
  - Süperpozisyon alt devrelerinde hangi elemanların seri, hangilerinin paralel olduğu dikkatle incelenmelidir. Ucu boşta kalan bir koldan akım geçmez; bu yüzden ilk bakışta paralel görünen iki direnç aslında başka bir kolla seri olabilir.
- Düğüm gerilimlerinden akım yönü
  - $v_1 > v_2$ ise 2 Ω'luk dirençteki akım soldan sağa akar ve pozitif çıkar; akım yüksek potansiyelden düşük potansiyele akar.
- Eşdeğerlik ölçütü
  - Bir dönüşümden sonra $I_L$ ve $V_L$ aynı değilse devre eşdeğer değildir, hesapta hata vardır.

## Kısa Tekrar Notları

- Düğüm analizi: referans düğüm seç, KCL yaz, akımları düğüm gerilimleriyle ifade et.
- Çevre analizi: çevre akımlarını aynı yönde (saat yönü) tanımla, KVL yaz; dış koldaki akım kaynağı çevre akımını doğrudan belirler.
- Doğrusallık: ölçekleme + toplanabilirlik. Güç doğrusal değildir.
- Ters yönden çözüm: çıkışa 1 birim ver, kaynağı bul, gerçek kaynakla oranla.
- Süperpozisyon: gerilim kaynağı → kısa devre, akım kaynağı → açık devre, bağımlı kaynak → dokunma.
- Kaynak dönüşümü: $v_s = i_s R$; seri direnç paralele geçer, değeri aynı kalır.
- $R_S = R_L$ olduğunda üretilen gücün %50'si yükte harcanır; yük en büyük gücü çeker.

## Detaylı Açıklamalar

- Düğüm analizi örneği (ekrandan, 00:05:41)
  - $v_1$ düğümü: $\dfrac{v_1 - 100}{8} + \dfrac{v_1}{4} + \dfrac{v_1 - v_2}{2} = 0 \Rightarrow 0{,}875\,v_1 - 0{,}5\,v_2 = 12{,}5$.
  - $v_2$ düğümü (8 A giriyor): $\dfrac{v_2 - v_1}{2} + \dfrac{v_2}{3} + \dfrac{v_2 - v_3}{10} - 8 = 0$.
  - $v_3$ düğümü (8 A çıkıyor): $\dfrac{v_3 - v_2}{10} + \dfrac{v_3}{5} + 8 = 0$.
  - Üç denklem matris biçiminde çözülür: $v_1 = 25{,}89$ V, $v_2 = 20{,}31$ V (python ile doğrulandı), $i_x = 2{,}79$ A.
  - <!-- BELİRSİZ: Ekranda yazılan 2. ve 3. denklemin düzenlenmiş katsayıları karede görülmedi; yukarıdaki biçim devreden kurulmuştur. -->
- Bağımlı kaynaklı bir çevre analizi sorusu (yaklaşık 01:22)
  - $v_s = 12$ V ve $v_s = 24$ V iken $i_0$ soruluyor. Çevre denklemleri: $12i_1 - 4i_2 + v_s = 0$ ve $-4i_1 + 16i_2 - 3v_x - v_s = 0$, $v_x = 2i_1$.
  - Çözüm $i_0 = i_2 = v_s/76$: $v_s = 12$ V için $\approx 0{,}158$ A, $v_s = 24$ V için $\approx 0{,}316$ A. Kaynak iki katına çıkınca akım da iki katına çıkar (doğrusallık).
  - <!-- BELİRSİZ: Bu sorunun devre şekli karede görülmedi; denklemler altyazıdan alındı ve python ile tutarlı bulundu. -->
- Doğrusallık ile ters yönden çözüm, Example 4 (ekrandan, 00:40:41)
  - $I_s = 15$ A; $I_0 = 1$ A varsayılır. $V_1 = (3+5)I_0 = 8$ V, $I_1 = V_1/4 = 2$ A, $I_2 = I_1 + I_0 = 3$ A.
  - $V_2 = V_1 + 2I_2 = 14$ V, $I_3 = V_2/7 = 2$ A, $I_4 = I_3 + I_2 = 5$ A, yani $I_s = 5$ A.
  - Gerçek kaynak 15 A olduğu için oran 3'tür: gerçek $I_0 = 3$ A; aynı oranla $I_3$ de 6 A olur.
- Bir başka ters yönden çözüm örneği (01:30–01:34)
  - 40 V kaynağın beslediği 12 Ω + 8 Ω seri kolunda $v_0$ (8 Ω üzerinde) için 1 V varsayılır: akım $1/8 = 0{,}125$ A, kol gerilimi $0{,}125 \times 20 = 2{,}5$ V. Gerçek gerilim 40 V olduğundan oran 16, yani $v_0 = 16$ V. Doğrudan gerilim bölücüyle de $40 \cdot 8/20 = 16$ V çıkar.
  - <!-- BELİRSİZ: Bu örneğin devre şekli karede görülmedi; değerler altyazıdan alındı. -->
- Süperpozisyon giriş örneği, Example 01 (ekrandan, 00:30:41)
  - 10 Ω direnç, 5 V gerilim kaynağı ve 2 A akım kaynağı paralel. Yalnız 5 V varken: $I_1 = 5/10 = 0{,}5$ A. Yalnız 2 A varken gerilim kaynağının yeri kısa devredir, 2 A kısa devreden döner, $I_2 = 0$. Toplam $I = 0{,}5$ A.
- Üç kaynaklı süperpozisyon, Example 6 (ekrandan, 00:50:41, 00:55:41, 01:00:41)
  - $R_1 = 50$ Ω, $R_2 = 30$ Ω, $R_3 = 20$ Ω, bir gerilim kaynağı $V_1$, akım kaynakları $I_1 = 1$ A ve $I_2 = 2$ A.
  - Devre 1 (akım kaynakları açık): $R_2$'den akım geçmez; $R_1$ ve $R_3$ seri (70 Ω). Altyazıya göre kaynak 3 V, akım $3/70$ A; gerilimler akımın 50 ve 20 ile çarpımıdır.
  - Devre 2 ($V_1$ kısa, $I_2$ açık, yalnız 1 A): $R_1 \parallel R_3$ ile $R_2$ seri, $R_{\text{eş}} = 44{,}3$ Ω. $R_2$ akımı kabul edilen yöne göre $-1$ A; sonuçlar $V_2 = -30$ V, $V_3 = -14{,}3$ V, $V_1 = 14{,}3$ V, $I_1 = 14{,}3/50 \approx 0{,}29$ A.
  - Devre 3 ($V_1$ kısa, $I_1$ açık, yalnız 2 A): $R_2$ ve $I_2$, $R_3$ ile paralel değildir; 2 A yalnız $R_2$ üzerinden döner. $I_2 = 2$ A, $V_2 = 60$ V; $R_1$–$R_3$ çevresinde kaynak olmadığından $I_1 = I_3 = 0$, $V_1 = V_3 = 0$.
  - Son adımda üç alt devrenin sonuçları bir tabloda toplanır.
  - <!-- BELİRSİZ: Devre 1'in kaynak değeri ve toplam tablo karede görülmedi; toplam değerler bu nota alınmadı. -->
  - Slaytta direnç birimleri "W" (watt) yazılmış; hoca bunların ohm olduğunu belirtti.
- Example 7 (ekrandan, 01:10:41): 6 V, 8 Ω, 4 Ω ($v$), 3 A
  - Yalnız 6 V: $v_1 = 6 \cdot 4/12 = 2$ V. Yalnız 3 A: akım 4 Ω ve 8 Ω arasında 2:1 bölünür, 4 Ω'dan 2 A geçer, $v_2 = 8$ V. Toplam $v = 10$ V.
- Bağımlı kaynaklı süperpozisyon, Example 9 (ekrandan, 01:20:41)
  - Devre 1 (yalnız 4 A): $i_1 = 4$ A, $-3i_1 + 6i_2 - i_3 - 5i_0' = 0$, $-5i_1 - i_2 + 10i_3 + 5i_0' = 0$, $i_3 = 4 - i_0'$. Düzenlenince $3i_2 - 2i_0' = 8$, $i_2 + 5i_0' = 20$; $i_0' = 52/17$ A.
  - Devre 2 (yalnız 20 V kaynak; akım kaynağı açık): $i_0'' = -i_5$ yazılarak iki bilinmeyenli iki denklem çözülür, $i_0'' = -60/17$ A.
  - Toplam $i_0 = 52/17 - 60/17 = -8/17 \approx -0{,}47$ A; eksi işaret gerçek yönün kabul edilenin tersi olduğunu gösterir.
- Kaynak dönüşümü ve güç, Example 10 (ekrandan, 01:30:41)
  - 18 V, $R_S = 3$ kΩ, $R_L = 6$ kΩ: $V_L = \dfrac{6}{6+3} \cdot 18 = 12$ V, $I_L = 12/6 = 2$ mA.
  - Kaynak gücü $P = 12 \cdot 2 + (18-12) \cdot 2 = 36$ mW.
  - Aynı $I_L$'yi akım kaynağıyla vermek için $I_S = \dfrac{R_L + R_S}{R_S} I_L$. $R_S = 6$ kΩ için $I_S = 4$ mA ve güç 48 mW; $R_S = 3$ kΩ için $I_S = 6$ mA ve güç 72 mW. $R_S$ küçüldükçe gereken akım ve güç artar.
  - <!-- BELİRSİZ: Altyazıda $R_S = 20$ kΩ için $I_S = 2{,}67$ mA ve 32 mW söyleniyor; bu sayılar $R_S = 18$ kΩ ile tutarlıdır (20 kΩ için 2,6 mA ve 31,2 mW çıkar). Slayttaki değer karede görülmedi. -->
- Example 11 (ekrandan, 01:35:41)
  - $I_s = 5$ mA, $R_S = 50$ Ω, $R_L = 300$ Ω: $I_L = \dfrac{50}{350} \cdot 5 = 0{,}714$ mA, $V_L = 0{,}214$ V, kaynak gücü 1,07 mW.
  - Gerilim kaynağıyla $R_S = 0$ alınırsa $V_s = 0{,}214$ V ve güç yalnız 0,153 mW olur; $R_S = 50$ Ω alınırsa $V_s = 0{,}25$ V ve güç 0,179 mW olur.
- Kaynak dönüşümüyle sadeleştirme, Example 12 (ekrandan, 01:40:41)
  - 3 A ∥ 4 Ω → 12 V seri 4 Ω; 4 Ω + 2 Ω = 6 Ω → 2 A ∥ 6 Ω. Sağda 12 V seri 3 Ω → 4 A ∥ 3 Ω.
  - 6 Ω ∥ 3 Ω = 2 Ω, akım kaynakları zıt yönlü: net 2 A. Tekrar dönüşümle 4 V seri 2 Ω; $v_0 = 4 \cdot 8/10 = 3{,}2$ V (ya da akım bölücüyle $0{,}4$ A × 8 Ω). Düğüm analiziyle de 3,2 V çıkar (python ile doğrulandı).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
