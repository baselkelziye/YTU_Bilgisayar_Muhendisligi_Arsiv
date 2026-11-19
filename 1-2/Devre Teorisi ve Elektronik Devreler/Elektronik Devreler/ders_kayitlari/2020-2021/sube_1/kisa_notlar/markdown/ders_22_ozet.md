# Ders 22 Çalışma Özeti

## Genel Konular

- FET çeşitlerinin özeti (n-kanal)
  - Derse önceki haftanın özet tablosuyla başlandı (ekrandaki dosya: ElDev_10.pdf, "Summary Table"). Tablo n-kanal için verilmiştir; p-kanalda her şey tersidir.
  - Üç tip: JFET, kanal ayarlamalı (depletion, D-type) MOSFET ve kanal oluşturmalı (enhancement, E-type) MOSFET. Üçünün de gate (G), drain (D) ve source (S) olmak üzere üç ucu vardır.
  - BJT akım kontrollüdür (belirleyici büyüklük $I_B$), FET gerilim kontrollüdür (belirleyici büyüklük $V_{GS}$). Bu yüzden FET'lerde $I_D$–$V_{GS}$ (transfer) grafiği temel grafiktir (ekrandan, 00:10:00).
  - Bütün FET'lerde $I_G = 0$ A ve $I_D = I_S$ tam eşittir. BJT'de ise $I_C \approx I_E$ yaklaşık eşitliği vardı.
  - Sembolde ok içeri bakıyorsa kanal n tipidir.
- JFET ve D-MOSFET transfer eğrisi (Shockley denklemi)
  - $I_D = I_{DSS}\left(1 - \dfrac{V_{GS}}{V_P}\right)^2$ (ekrandan, 00:10:00). $I_{DSS}$ ve $V_P$ (pinch-off gerilimi) transistöre özgü sabitlerdir.
  - n-kanal JFET'te $V_{GS}$ negatiftir: $V_{GS} = V_P$'de kanal tamamen kapanır ($I_D = 0$), $V_{GS} = 0$'da akım en büyük değeri $I_{DSS}$'ye ulaşır.
  - Yaklaşık çizim için yardımcı noktalar: $V_{GS} = 0{,}3V_P$ iken $I_D \approx I_{DSS}/2$; $V_{GS} = V_P/2$ iken $I_D = I_{DSS}/4$ (ekrandan, 00:15:00).
  - D-MOSFET aynı denkleme uyar; farkı $V_{GS}$'nin pozitif bölgeye de geçebilmesidir. Pozitif $V_{GS}$'de kanal genişlemeye devam eder ve $I_D > I_{DSS}$ olur (ekrandan, 00:20:00).
- E-MOSFET transfer eğrisi
  - Başta kanal yoktur. $V_{GS}$ eşik gerilimi $V_{GS(Th)} = V_T$ değerini geçince kanal oluşur ve akım akmaya başlar.
  - $I_D = k\,(V_{GS} - V_{GS(Th)})^2$. $k$ transistöre özgüdür, birimi A/V²'dir. $k$, verilen bir çalışma noktasından bulunur: $k = \dfrac{I_{D(on)}}{(V_{GS(on)} - V_{GS(Th)})^2}$ (ekrandan, 01:05:00).
  - p-kanal tiplerde grafikler n-kanal grafiklerinin $I_D$ eksenine göre aynalanmış hâlidir; p-kanal E-MOSFET negatif bir eşikten başlar.
- FET DC öngerilim (bias) devreleri
  - JFET: sabit öngerilim (fixed-bias), kendinden öngerilim (self-bias), gerilim bölücü. D-MOSFET: kendinden öngerilim ve gerilim bölücü. E-MOSFET: geri beslemeli (feedback) ve gerilim bölücü.
  - Sabit öngerilim: $V_{GS} = -V_{GG}$, $V_S = 0$, $V_{DS} = V_{DD} - I_D R_D$ (ekrandan, 00:25:00).
  - Kendinden öngerilim: $V_G = 0$ olduğundan $V_{GS} = -I_D R_S$.
  - Gerilim bölücü: $V_G = \dfrac{R_2 V_{DD}}{R_1 + R_2}$, $V_{GS} = V_G - I_D R_S$ (ekrandan, 00:35:00).
  - Geri beslemeli E-MOSFET: $I_G = 0$ olduğundan $V_{R_G} = 0$, $V_G = V_D$; $V_S = 0$ olduğundan $V_{GS} = V_{DS} = V_{DD} - I_D R_D$ (ekrandan, 00:45:00).
- Çalışma noktasının (Q) grafikle bulunması
  - Devreden çıkan denklem $V_{GS}$ ile $I_D$ arasında bir doğru denklemidir ($y = c - ax$ biçiminde).
  - Doğru, $I_D = 0$ ve $V_{GS} = 0$ verilerek iki eksen kesim noktasından çizilir. Transfer eğrisiyle kesiştiği yer Q noktasıdır; buradan $I_{DQ}$ ve $V_{GSQ}$ okunur (ekrandan, 00:40:00).
  - Sonra noktasal gerilimler ($V_D$, $V_S$, $V_G$) ve farksal gerilimler ($V_{DS}$, $V_{DG}$) Kirchhoff gerilim yasasıyla bulunur.
- Çözülen sorular (ekrandaki dosya: ElkDev_Sorular2.pdf)
  - JFET transfer eğrisi, $I_{DSS} = 12$ mA, $V_P = -6$ V: $-1{,}8$ V'ta 6 mA, $-3$ V'ta 3 mA (ekrandan, 00:50:00).
  - D-MOSFET transfer eğrisi, $I_{DSS} = 10$ mA, $V_P = -4$ V: $-1{,}2$ V'ta 5 mA, $-2$ V'ta 2,5 mA, $+1$ V'ta $\approx 15{,}63$ mA (ekrandan, 00:55:00).
  - E-MOSFET: $I_{D(on)} = 3$ mA, $V_{GS(on)} = 10$ V, $V_{GS(Th)} = 3$ V için $k = 0{,}061 \times 10^{-3}$ A/V² (ekrandan, 01:05:00).
  - JFET sabit öngerilim (16 V, 2 kΩ, $V_{GG} = 2$ V, $I_{DSS} = 10$ mA, $V_P = -8$ V): $V_{GSQ} = -2$ V, $I_{DQ} = 5{,}625$ mA, $V_{DS} = V_D = 4{,}75$ V, $V_G = -2$ V, $V_S = 0$ (ekrandan, 01:10:00).
  - JFET gerilim bölücü (16 V; 2,1 MΩ / 270 kΩ; 2,4 kΩ / 1,5 kΩ; $I_{DSS} = 8$ mA, $V_P = -4$ V): $V_G = 1{,}82$ V, $I_{DQ} \approx 2{,}4$ mA, $V_{GSQ} \approx -1{,}8$ V, $V_D = 10{,}24$ V, $V_S = 3{,}6$ V, $V_{DS} = 6{,}64$ V (ekrandan, 01:15:00).
  - D-MOSFET gerilim bölücü (18 V; 110 MΩ / 10 MΩ; 1,8 kΩ / 750 Ω; $I_{DSS} = 6$ mA, $V_P = -3$ V): $V_G = 1{,}5$ V, $I_{DQ} = 3{,}1$ mA, $V_{GSQ} = -0{,}8$ V, $V_{DS} \cong 10{,}1$ V (ekrandan, 01:20:00 ve 01:25:00).
  - D-MOSFET kendinden öngerilim (20 V; 6,2 kΩ; 1 MΩ; 2,4 kΩ; $I_{DSS} = 8$ mA, $V_P = -8$ V): $V_{GS} = -I_D(2{,}4\text{ k}\Omega)$, grafikten $I_{DQ} \approx 1{,}7$ mA, $V_{GSQ} \approx -4{,}3$ V (ekrandan, 01:25:00 ve 01:30:00).
  - Gate'i doğrudan toprağa bağlı D-MOSFET: $V_{GS} = 0$ olduğundan $I_{DQ} = I_{DSS} = 10$ mA.
  - E-MOSFET geri beslemeli (12 V, 2 kΩ, 10 MΩ; $I_{D(on)} = 6$ mA, $V_{GS(on)} = 8$ V, $V_{GS(Th)} = 3$ V): $k = 0{,}24$ mA/V², $I_{DQ} \approx 2{,}75$ mA, $V_{GSQ} = V_{DSQ} \approx 6{,}4$ V (ekrandan, 01:35:00).
  - E-MOSFET gerilim bölücü ($V_G = 18$ V, $R_S = 0{,}82$ kΩ; $V_{GS(Th)} = 5$ V, $I_{D(on)} = 3$ mA, $V_{GS(on)} = 10$ V): $k = 0{,}12 \times 10^{-3}$ A/V², $I_{DQ} \approx 6{,}7$ mA, $V_{GSQ} = 12{,}5$ V (ekrandan, 01:40:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Soru çözümünde ilk iş transfer eğrisini çizmek
  - Q noktası, devreden çıkan doğru ile transistörün $I_D$–$V_{GS}$ eğrisinin kesişimidir. Eğri doğru çizilmezse çalışma noktası yanlış okunur.
- Eşit aralıklı (ölçekli) eksen
  - Elle çizimde eksenlere eşit aralıklar verilmelidir; yoksa doğru ile eğrinin kesişimi çok kayar ve $I_{DQ}$, $V_{GSQ}$ yanlış okunur.
- İşaretlere dikkat
  - n-kanal JFET ve D-MOSFET'te $V_P$ negatiftir; $0{,}3V_P$ ve $V_P/2$ değerleri de negatif çıkar. Eksi ve artılara mutlaka dikkat edilmelidir.
- $I_G = 0$ ve $I_D = I_S$
  - Bütün FET sorularında bu iki eşitlik kullanılır. Gate direnci üzerinden akım geçmediği için o dirençte gerilim düşmez.
- E-MOSFET'te $k$ mutlaka bulunur
  - Eşik gerilimi tek başına yetmez; eğriyi çizmek için verilen $(V_{GS(on)}, I_{D(on)})$ noktasından önce $k$ hesaplanır.
- D-MOSFET'te pozitif bölge
  - Pozitif $V_{GS}$'de akım çok hızlı arttığı için dış nokta olarak küçük bir değer (+1 V, +2 V gibi) seçilir.

## Kısa Tekrar Notları

- FET gerilim kontrollüdür; $V_{GS}$ akımı belirler. BJT akım kontrollüdür.
- Bütün FET'lerde $I_G = 0$, $I_D = I_S$.
- JFET ve D-MOSFET: $I_D = I_{DSS}(1 - V_{GS}/V_P)^2$.
- E-MOSFET: $I_D = k(V_{GS} - V_{GS(Th)})^2$, $k = I_{D(on)}/(V_{GS(on)} - V_{GS(Th)})^2$.
- Yardımcı noktalar: $0{,}3V_P \to I_{DSS}/2$, $V_P/2 \to I_{DSS}/4$.
- n-kanal JFET: $V_P \le V_{GS} \le 0$. D-MOSFET: $V_{GS} > 0$ da olabilir. n-kanal E-MOSFET: $V_{GS} > V_{GS(Th)} > 0$.
- p-kanal grafikleri, n-kanal grafiklerinin $I_D$ eksenine göre aynasıdır.
- Sabit öngerilim: $V_{GS} = -V_{GG}$.
- Kendinden öngerilim: $V_{GS} = -I_D R_S$ (doğru orijinden geçer).
- Gerilim bölücü: $V_{GS} = V_G - I_D R_S$, $V_G = R_2 V_{DD}/(R_1 + R_2)$.
- Geri beslemeli E-MOSFET: $V_{GS} = V_{DS} = V_{DD} - I_D R_D$.
- Q noktası: doğrunun eksen kesimlerini bul, eğriyle kesiştir, $I_{DQ}$ ve $V_{GSQ}$'yu oku.
- $V_{DS} = V_{DD} - I_D(R_D + R_S)$, $V_D = V_{DD} - I_D R_D$, $V_S = I_D R_S$.

## Detaylı Açıklamalar

- FET'lerin BJT ile karşılaştırılması
  - BJT'de kollektör, baz ve emitter uçları vardı; silisyumda $V_{BE} = 0{,}7$ V sabit kabul ediliyordu, $I_B$ çok küçüktü, $I_C \approx \beta I_B$ ve $I_C \approx I_E$ idi. FET'te ise uçlar drain, gate ve source'tur. Sabit kabul edilen şey $I_G \approx 0$'dır ve $I_D = I_S$ yaklaşık değil, tam eşitliktir. BJT'de doğrusal ilişkiler varken FET'te ana değişkenler $V_{GS}$ ile $I_D$ arasındaki ilişki karesel bir ifadedir. Bu yüzden FET sorularında önce karesel transfer eğrisi çizilir.
- Kanal ayarlamalı ile kanal oluşturmalı MOSFET farkı
  - MOSFET'te gate, kanaldan yalıtkan bir tabakayla ayrılmıştır. Hazırda bir kanal varsa ve $V_{GS}$ bu kanalın genişliğini ayarlıyorsa yapı kanal ayarlamalıdır (D-MOSFET). Bu yapıda negatif $V_{GS}$ kanalı daraltır, $V_P$'de kanal yok olur; $V_{GS}$ sıfıra ve pozitife gittikçe kanal genişler ve akım $I_{DSS}$'yi aşar. Kanal yoksa ve belli bir pozitif $V_{GS}$ (eşik gerilimi) uygulanınca oluşuyorsa yapı kanal oluşturmalıdır (E-MOSFET). Bu nedenle formülü JFET ve D-MOSFET'ten farklıdır; JFET ile D-MOSFET birbirine çok benzer.
- Gerilim bölücünün mantığı
  - Seri iki dirençten aynı akım geçtiği için gerilim dirençlerle orantılı paylaşılır: büyük dirençte daha çok gerilim düşer. Hocanın örneğinde 10 V kaynak ve 2 birim ile 3 birimlik dirençler vardır; 3 birimlik dirençte 6 V, 2 birimlik dirençte 4 V düşer, orta nokta $\frac{2}{5} \cdot 10 = 4$ V olur. Dirençler eşit olsaydı orta nokta 5 V olurdu. FET'li gerilim bölücü devrede gate'e akım girmediği için $V_G$ doğrudan bu oranla bulunur.
- Kendinden öngerilimde doğrunun orijinden geçmesi
  - Gate direnci üzerinden akım geçmediği için $V_G = 0$ olur ve $V_{GS} = -I_D R_S$ elde edilir. Bu doğru orijinden geçer. İkinci nokta için dışarıdan bir $V_{GS}$ seçilir; örnekte $R_S = 2{,}4$ kΩ iken $V_{GS} = -6$ V için $I_D = 2{,}5$ mA bulunmuştur (01:27:46).
- Geri beslemeli E-MOSFET devresi
  - Drain ile gate arasına büyük bir direnç ($R_G$) bağlıdır. Gate akımı sıfır olduğundan bu dirençte gerilim düşmez ve gate, drain'in gerilimini görür: $V_G = V_D$. Source toprakta olduğundan $V_{GS} = V_G$ ve $V_{DS} = V_D$, yani $V_{GS} = V_{DS} = V_{DD} - I_D R_D$. Bu doğru, $I_D = 0$'da $V_{GS} = V_{DD}$ noktasından ve $V_{GS} = 0$'da $I_D = V_{DD}/R_D$ noktasından geçer.
- Hesapların sonuçları (ders sonrası python kontrolü)
  - Grafikten okunan değerler yaklaşıktır. Denklemler sayısal çözüldüğünde: JFET gerilim bölücüde $I_{DQ} \approx 2{,}42$ mA, $V_{GSQ} \approx -1{,}80$ V; D-MOSFET gerilim bölücüde $I_{DQ} \approx 3{,}12$ mA, $V_{GSQ} \approx -0{,}84$ V; D-MOSFET kendinden öngerilimde $I_{DQ} \approx 1{,}77$ mA, $V_{GSQ} \approx -4{,}24$ V; geri beslemeli E-MOSFET'te $I_{DQ} \approx 2{,}79$ mA, $V_{GSQ} \approx 6{,}41$ V; E-MOSFET gerilim bölücüde $I_{DQ} \approx 6{,}72$ mA, $V_{GSQ} \approx 12{,}49$ V çıkar. Grafik değerleri bunlarla uyumludur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
