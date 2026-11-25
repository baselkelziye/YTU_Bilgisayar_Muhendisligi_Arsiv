# Ders 5 Çalışma Özeti

## Genel Konular

- Doğrusallık (linearity)
  - Girdisi $x$, çıktısı $f(x)$ olan bir kara kutu düşünülür. Girdi bir $a$ sabitiyle çarpıldığında çıktı da aynı sabitle çarpılıyorsa, yani $f(ax) = a\,f(x)$ ise sistem doğrusaldır.
  - Doğrusal sistemde toplam biçimindeki girdiler çıktıda ayrıştırılabilir: $f(x_1 + x_2) = f(x_1) + f(x_2)$. Süperpozisyon bu özellikten gelir.
  - Ohm yasası doğrusal bir sistemdir: gerilim girdi, akım çıktı olarak düşünülürse $i = v/R$ grafiği sıfırdan geçen bir doğrudur. Gerilim iki katına çıkınca akım da iki katına çıkar.
  - Çevre analizinde bir direnç üzerindeki iki çevre akımının etkisini ayrı ayrı bulup toplamak ($I_1 - I_2$) aslında doğrusallığın kullanılmasıdır.
- Doğrusal olmayan sistemler ve elemanlar
  - Güç akım ve gerilime göre doğrusal değildir (ekrandan, 00:15:00): $P = IV = I^2R = V^2/R$. Gerilim ya da akım $a$ katına çıkınca güç $a^2$ katına çıkar.
  - Doğrusal elemanlar: direnç, bobin (endüktans), kondansatör (kapasite), bağımsız akım ve gerilim kaynakları, doğrusal kontrol edilen bağımlı kaynaklar (örneğin $2v_x$).
  - Doğrusal olmayan elemanlar (ekrandan, 00:20:00): diyotlar (LED dahil), transistörler (BJT, MOSFET), SCR'ler, manyetik anahtarlar, doğrusal olmayan biçimde kontrol edilen bağımlı kaynaklar (örneğin $2I_1^2$). Bunlar ağırlıkla elektronik devreler dersinde incelenir.
- Doğrusallık ile çözüm (Örnek 4, ekrandan, 00:30:00)
  - Bilinmeyen kaynak değeri yerine çıktı için varsayımsal bir değer ($I_0 = 1$ A) seçilir, devre geriye doğru çözülür, sonra gerçek kaynak değerine oranla ölçeklenir.
- Süperpozisyon ilkesi
  - Bir elemandaki gerilim (akım), her bağımsız kaynağın tek başına oluşturduğu gerilimlerin (akımların) cebirsel toplamıdır (ekrandan, 00:40:00).
  - Kaç bağımsız kaynak varsa o kadar alt devre çözülür. Her alt devrede yalnız bir bağımsız kaynak bırakılır.
  - Kaynak kapatma: gerilim kaynağı kısa devre ile, akım kaynağı açık devre ile değiştirilir (ekrandan, 00:25:00).
  - Bağımlı kaynaklar kapatılmaz, her alt devrede kalır.
  - Bütün alt devrelerde aranan büyüklüğün referans yönü aynı tutulur.
- İdeal ve gerçek kaynaklar
  - İdeal gerilim kaynağının iç direnci yoktur; gereken kadar akım verir. Gerçek gerilim kaynağı ideal kaynağa seri bir iç dirençle ($R_s$) modellenir (ekrandan, 01:15:00).
  - İdeal akım kaynağı gereken kadar gerilim üretir. Gerçek akım kaynağı ideal kaynağa paralel bir iç dirençle modellenir (ekrandan, 01:20:00).
  - Gerçek gerilim kaynağında $V_L = V_s \dfrac{R_L}{R_L + R_s}$; gerçek akım kaynağında $I_L = I_s \dfrac{R_s}{R_L + R_s}$.
  - $R_L = R_s$ ise $V_L = V_s/2$ ve $I_L = I_s/2$ olur. Bu özel durum en büyük güç aktarımına bağlanır.
- Kaynak dönüşümü
  - Seri dirençli bir gerilim kaynağı ($v_s$, $R$) yerine paralel dirençli bir akım kaynağı ($i_s$, $R$) konabilir, tersi de geçerlidir: $v_s = i_s R$, $i_s = v_s/R$ (ekrandan, 01:30:00).
  - Dönüşüm bağımlı kaynaklar için de geçerlidir.
  - Eşdeğerlik: iki devrenin aynı uçlardan bakıldığında akım-gerilim ($v$-$i$) karakteristikleri aynı olmalıdır (ekrandan, 01:25:00).
  - Kaynak dönüşümü Thevenin ve Norton eşdeğerlerine giden yoldur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Süperpozisyon çözümünde alt devreleri mutlaka ayrı ayrı çizin
  - Her bağımsız kaynak için bir alt devre çizilir, her birinin katkısı bulunup toplanır.
- Kaynağı "sıfırlamak" ne demek
  - Gerilim kaynağını sıfırlamak iki uç arasındaki gerilim farkını sıfır yapmaktır; bunu kısa devre sağlar. Akım kaynağını sıfırlamak koldan geçen akımı sıfır yapmaktır; bunu açık devre sağlar.
- Bağımlı kaynaklar devrede kalır
  - Süperpozisyonda yalnız bağımsız kaynaklar sırayla kapatılır. Bağımlı kaynak, o alt devredeki kontrol büyüklüğüne göre etkisini gösterir.
- Referans yönleri sabit tutulmalı
  - Bir alt devrede yukarı, diğerinde aşağı yönlü akım hesaplanırsa toplama hatalı olur.
- Kaynak dönüşümünde yön ve direncin yeri
  - Dönüşen kaynağın yönü, uçlar açık iken görülen gerilimin (ya da uçlar kısa devre iken akan akımın) yönünü korumalıdır. Direnç, seçilen referans düğümünün gerilimini bozmayacak tarafa konur.
- Süperpozisyonun ileride kullanımı
  - Elektronik devrelerde transistörlü kuvvetlendiriciler hem DC (kutuplama) hem AC (işaret) kaynak içerir. Önce yalnız DC ile çalışma noktası, sonra yalnız AC ile kuvvetlendirme bulunur; bu süperpozisyonun uygulamasıdır.

## Kısa Tekrar Notları

- Doğrusal sistem: $f(ax) = a f(x)$ ve $f(x_1 + x_2) = f(x_1) + f(x_2)$.
- Güç doğrusal değildir: $P = I^2R = V^2/R$.
- Tek kaynaklı doğrusal devrede bütün akım ve gerilimler kaynakla orantılıdır; varsayımsal çıktı değeriyle geriye doğru çözüp ölçeklemek pratiktir.
- Süperpozisyon: kaynak sayısı kadar alt devre; gerilim kaynağı → kısa devre, akım kaynağı → açık devre; bağımlı kaynak kalır; sonuçlar cebirsel toplanır.
- Gerçek gerilim kaynağı = ideal kaynak + seri $R_s$; gerçek akım kaynağı = ideal kaynak + paralel $R_s$.
- İdeal gerilim kaynağında iç direnç sıfır (iletkenlik sonsuz); ideal akım kaynağında paralel iç direnç sonsuzdur.
- $R_L = 0$ (kısa devre) ya da $R_L = \infty$ (açık devre) iken yük gücü sıfırdır.
- $R_L = R_s$ iken $V_L = V_s/2$, $I_L = I_s/2$; yükteki güç ideal kaynağın ürettiği gücün %50'sidir (ekrandan, 01:45:00).
- Kaynak dönüşümü: $v_s = i_s R$, $R$ aynı kalır; iki şart: açık devre gerilimleri eşit, kısa devre akımları eşit.

## Detaylı Açıklamalar

- Doğrusallık ve süperpozisyonun ilk örneği (Örnek 01, ekrandan, 00:25:00)
  - Devre: 10 Ω direnç, 5 V gerilim kaynağı (artı ucu üstte) ve aşağı yönlü 2 A akım kaynağı aynı iki düğüm arasına paralel bağlı. İstenen, 10 Ω üzerinden aşağı yönlü $I$ akımı.
  - Yalnız 5 V: 2 A kaynağı açık devre yapılır. $I_1 = 5/10 = 0.5$ A.
  - Yalnız 2 A: 5 V kaynağı kısa devre yapılır. 10 Ω kısa devreyle paralel kaldığı için akım kısa devre yolundan döner, $I_2 = 0$.
  - Sonuç $I = I_1 + I_2 = 0.5$ A. Bir kaynağın katkısının sıfır çıkması bu devreye özgüdür.
- Örnek 4: doğrusallık ile kaynak-çıktı ilişkisi (ekrandan, 00:30:00)
  - Devre (soldan sağa): yukarı yönlü $I_s = 15$ A akım kaynağı; üst kolda 6 Ω ($I_4$), düğüm 2 ($V_2$); düğüm 2'den toprağa 7 Ω ($I_3$); üst kolda 2 Ω ($I_2$), düğüm 1 ($V_1$); düğüm 1'den toprağa 4 Ω ($I_1$); üst kolda 3 Ω ve ardından toprağa 5 Ω ($I_0$).
  - $I_0 = 1$ A varsayılır: $V_1 = (3+5)I_0 = 8$ V, $I_1 = V_1/4 = 2$ A, $I_2 = I_1 + I_0 = 3$ A, $V_2 = V_1 + 2I_2 = 14$ V, $I_3 = V_2/7 = 2$ A, $I_4 = I_3 + I_2 = 5$ A. Bu durumda $I_s = 5$ A olmalıdır.
  - Gerçek kaynak 15 A, yani 3 kat; doğrusallık gereği $I_0 = 3$ A.
  - > **Ders sonrası not:** Bir öğrencinin sorusu üzerine hoca diğer akımların aynı oranda ölçeklenmeyebileceğini söyledi. Tek bağımsız kaynaklı doğrusal devrede bütün akım ve gerilimler kaynakla orantılıdır; $I_s = 15$ A için $I_1 = 6$ A, $I_2 = 9$ A, $I_3 = 6$ A, $I_4 = 15$ A, $V_1 = 24$ V, $V_2 = 42$ V olur (python ile doğrulandı).
- Örnek 5: doğrusallık (derste sözlü, 00:37:33)
  - $V_0$, 8 Ω üzerindeki gerilimdir; aynı akım toplam 20 Ω'luk yoldan geçer ve $V_s = \dfrac{V_0}{8} \cdot 20 = 2.5\,V_0$ bulunur. $V_s = 40$ V için $V_0 = 40/2.5 = 16$ V.
  - <!-- BELİRSİZ: Örnek 5'in devre şekli karelerde yok; ilişki yalnız altyazıdan alındı. -->
- Örnek 6: üç bağımsız kaynaklı süperpozisyon (ekrandan, 00:45:00)
  - Elemanlar: 3 V kaynak ($V_1$), $R_1 = 50$ Ω, $R_3 = 20$ Ω, $R_2 = 30$ Ω, 2 A ve 1 A akım kaynakları. İstenen, ana koldaki ($R_1$) akım.
  - Yalnız 3 V: akım kaynakları açık devre; $R_2$'nin bir ucu boşta kalır, akım yalnız $R_1$ ve $R_3$ üzerinden akar: $3/70 \approx 42.9$ mA.
  - Yalnız 1 A: 1 A, $R_2$ üzerinden $R_1 \parallel R_3$ düğümüne gelir ve $R_1$ ile $R_3$ arasında bölünür. $R_1$'deki katkı $1 \cdot \dfrac{20}{70} \approx 285.7$ mA; düğüm gerilimi $1 \cdot (50 \parallel 20) \approx 14.29$ V.
  - Yalnız 2 A: kaynağın oluşturduğu kapalı yolda başka kaynak yoktur, $R_1$ ve $R_3$'e katkısı sıfırdır.
  - Toplam yaklaşık 328.6 mA (python ile doğrulandı).
  - <!-- BELİRSİZ: Özgün devrenin tam şekli karelerde görünmüyor; yalnız 3 V'luk alt devre ekranda. Akım kaynaklarının konumu ve yönü altyazıdan ve slayttaki 14.3 değerinden çıkarıldı. -->
  - > **Ders sonrası not:** Hoca 1 A'lık alt devrede düğüm gerilimini 30 V, ana kol katkısını $-30/50$ diye söyledi. Doğrusu, 1 A'nın 50 Ω ile 20 Ω arasında bölünmesidir: düğüm gerilimi büyük olasılıkla $\approx 14.29$ V (slaytta 14.3 olarak verilen değer), $R_1$ akımı $\approx 285.7$ mA. Hocanın söylediği toplam (328 mA civarı) bu düzeltilmiş değerle tutarlıdır.
- Örnek 7: süperpozisyon (ekrandan, 00:50:00)
  - Devre: 6 V kaynak, seri 8 Ω, 4 Ω ($v$) ve yukarı yönlü 3 A kaynak; 4 Ω ile 3 A paralel.
  - Yalnız 6 V: $v_1 = \dfrac{4}{4+8}(6) = 2$ V.
  - Yalnız 3 A: 8 Ω ile 4 Ω paralel; $i_3 = \dfrac{8}{4+8}(3) = 2$ A, $v_2 = 4 i_3 = 8$ V.
  - $v = v_1 + v_2 = 10$ V.
- Örnek 9: bağımlı kaynaklı süperpozisyon (ekrandan, 00:55:00)
  - Devre: 4 A akım kaynağı, 20 V gerilim kaynağı, 2, 3, 1, 5, 4 Ω dirençler ve $5i_o$ akım kontrollü gerilim kaynağı. İstenen 5 Ω'dan geçen $i_o$.
  - Devre 1 (20 V kısa devre): $i_1 = 4$ A; $-3i_1 + 6i_2 - i_3 - 5i_o' = 0$; $-5i_1 - i_2 + 10i_3 + 5i_o' = 0$; $i_3 = i_1 - i_o' = 4 - i_o'$. Sonuç $i_o' = 52/17$ A.
  - Devre 2 (4 A açık devre): $6i_4 - i_5 - 5i_o'' = 0$; $-i_4 + 10i_5 - 20 + 5i_o'' = 0$; $i_5 = -i_o''$. Sonuç $i_o'' = -60/17$ A.
  - $i_o = i_o' + i_o'' = -8/17 \approx -0.4706$ A (python ile doğrulandı).
- Gerçek kaynakların yük davranışı
  - Gerçek gerilim kaynağında $R_s$ yük direnciyle gerilim bölücü oluşturur; $V_s$'nin tamamı yükte düşmez.
  - Gerçek akım kaynağında $I_s = V_L/R_s + V_L/R_L$ ve $V_L = I_L R_L$ yazılırsa $I_L = I_s \dfrac{R_s}{R_L + R_s}$ elde edilir (ekrandan, 01:35:00).
  - Yük gücü $R_L$'ye göre ters parabol biçimindedir; tepe noktası $R_L = R_s$'dir. Matematiksel ispatı en büyük güç aktarımı konusunda yapılacaktır.
- Kaynak dönüşümünün türetilmesi
  - Uçlar açık: gerilim kaynaklı devrede $R$'den akım geçmez, $v_{ab} = v_s$; akım kaynaklı devrede bütün akım $R$'den geçer, $v_{ab} = i_s R$. Eşitlikten $v_s = i_s R$.
  - Uçlar kısa devre: akım kaynaklı devrede bütün akım kısa devre yolundan geçer, $i = i_s$; gerilim kaynaklı devrede $i = v_s/R$. Yine $v_s = i_s R$.
  - Sayısal örnek: 18 V ve 3 kΩ'luk gerçek gerilim kaynağının eşdeğeri $18/3\text{k} = 6$ mA ve paralel 3 kΩ'dur.
- Örnek 12: kaynak dönüşümüyle çözüm (ekrandan, 01:50:00)
  - Devre: 4 Ω ile paralel aşağı yönlü 3 A; üst kolda 2 Ω; $v_o$'nun ölçüldüğü 8 Ω; üst kolda 3 Ω ve 12 V kaynak (artı üstte).
  - 3 A ∥ 4 Ω → 12 V (artı ucu altta) + seri 4 Ω; 4 Ω ile 2 Ω seri → 6 Ω. 12 V + seri 3 Ω → yukarı yönlü 4 A ∥ 3 Ω.
  - 12 V + 6 Ω → aşağı yönlü 2 A ∥ 6 Ω. $6 \parallel 3 = 2$ Ω; akım kaynakları $4 - 2 = 2$ A (yukarı).
  - Akım bölücü: $i = \dfrac{2}{2+8}(2) = 0.4$ A, $v_o = 8i = 3.2$ V; ya da $v_o = (8 \parallel 2)(2) = 3.2$ V.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
