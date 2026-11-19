# Ders 18 Çalışma Özeti

## Genel Konular

- BJT DC kutuplama soru çözümlerinin devamı
  - Gerilim bölücülü devrenin hatırlatması: $E_{Th} = \dfrac{3{,}9}{39 + 3{,}9} \cdot 22 = 2$ V, $R_{Th} = 39\,\text{k}\Omega \parallel 3{,}9\,\text{k}\Omega \approx 3{,}55$ kΩ (ekrandan, 00:15:00).
  - Giriş ve çıkıştaki kondansatörler işaretin DC bileşenini süzer, yalnız AC bileşeni geçirir. DC kutuplama transistörü kesim ve doyumdan uzak, güvenli bir çalışma noktasına oturtur; AC işaret bu noktanın üzerinde işlenir.
  - $V_C$ gibi tek indisli gerilimler toprağa göredir; $V_{AB} = V_A - V_B$ iki noktanın toprağa göre gerilimlerinin farkıdır.
- Gerilim geri beslemeli devre (Boylestad Örnek 4.13)
  - Değerler: $V_{CC} = 18$ V, $R_1 = 91$ kΩ, $R_2 = 110$ kΩ (ortası 10 µF ile toprağa), $R_C = 3{,}3$ kΩ, $R_E = 510$ Ω, $\beta = 75$ (ekrandan, 00:20:00).
  - $I'_C = I_C + I_B \approx I_C$ kabulüyle KVL: $V_{CC} = I_C R_C + I_B (R_1 + R_2) + V_{BE} + I_E R_E$.
  - $I_C = \beta I_B$ yazılıp $I_B$ yalnız bırakılır: $I_B = \dfrac{V_{CC} - V_{BE}}{R_B + \beta (R_C + R_E)} = 35{,}5$ µA; $I_C = 2{,}66$ mA; $V_C = V_{CC} - I_C R_C = 9{,}22$ V.
- Kollektör geri beslemeli devre ($R_E$ yok)
  - Değerler: $V_{CC} = 20$ V, $R_B = 680$ kΩ, $R_C = 4{,}7$ kΩ, $\beta = 120$ (ekrandan, 00:30:00).
  - $V_{CC} = I_C R_C + I_B R_B + V_{BE}$; $I_B = 19{,}3\,\text{V} / 1{,}244\,\text{M}\Omega = 15{,}51$ µA; $I_C = 1{,}86$ mA.
  - $V_E = 0$ olduğundan $V_{CE} = V_C = V_{CC} - I_C R_C = 11{,}26$ V ve $V_B = V_{BE} = 0{,}7$ V.
- Tasarım sorusu: çalışma noktasından direnç bulma (Boylestad Örnek 4.20)
  - Verilen: $I_{CQ} = 2$ mA, $V_{CEQ} = 10$ V, $V_{CC} = 18$ V, $R_2 = 18$ kΩ, $R_E = 1{,}2$ kΩ (ekrandan, 00:35:00).
  - $V_E = I_C R_E = 2{,}4$ V, $V_B = V_{BE} + V_E = 3{,}1$ V; bölücüden $R_1 = 86{,}52$ kΩ.
  - $V_C = V_{CE} + V_E = 12{,}4$ V, $R_C = (18 - 12{,}4)/2\,\text{mA} = 2{,}8$ kΩ. Aynı sonuç $V_{CC} - V_{CE} = I_C (R_C + R_E)$ yolundan da çıkar.
  - pnp devrelerde akım yönleri npn'nin tersidir; denklemler buna göre kurulur.
- FET'lere giriş: BJT ile karşılaştırma (ekrandan, 00:40:00)
  - Benzerlikler: yükselteç, anahtarlama elemanı (lojik kapılar) ve empedans uydurma devrelerinde kullanılırlar.
  - Farklar: FET gerilim kontrollü, BJT akım kontrollüdür. FET'in giriş empedansı yüksek, BJT'nin gerilim kazancı yüksektir. FET sıcaklığa daha az duyarlıdır ve entegre devreye daha kolay uyarlanır; buna karşılık statik elektriğe BJT'den daha duyarlıdır.
- FET türleri (ekrandan, 00:45:00)
  - JFET (Junction FET, eklemli FET): n kanallı ve p kanallı.
  - MOSFET (Metal-Oxide-Semiconductor FET): D-MOSFET (depletion, kanal ayarlamalı) ve E-MOSFET (enhancement, kanal oluşturmalı); her birinin n ve p kanallı tipi vardır.
- JFET yapısı ve çalışması
  - n kanallı JFET: n tipi silindir şeklinde ana malzeme, çevresinde kuşak gibi p tipi bölge; aradaki geçiş bölgesi (depletion region) kanalın genişliğini belirler.
  - Uç eşleştirmesi: Source ≈ emitör (kaynak), Gate ≈ baz (vana), Drain ≈ kollektör (boşaltım). Slayttaki su musluğu benzetmesi (ekrandan, 00:50:00).
  - Kontrol $I_B$ ile değil, $V_{GS}$ ile yapılır. $I_G \approx 0$, $I_D = I_S$ (ekrandan, 01:05:00).
  - $V_{GS} = 0$ iken kanal en açıktır ve en büyük akım ($I_{DSS}$) akar. $V_{GS}$ negatif yönde büyüdükçe geçiş bölgesi genişler, kanal daralır. $V_{GS} = V_P$ (pinch-off gerilimi) olunca $I_D = 0$ olur.
  - Shockley denklemi: $I_D = I_{DSS}\left(1 - \dfrac{V_{GS}}{V_P}\right)^2$. $I_{DSS}$ ve $V_P$ transistöre özgü sabitlerdir, tek değişken $V_{GS}$'dir (ekrandan, 01:20:00).
  - p kanallı JFET'te malzemeler ve akım yönleri terstir; karakteristik pozitif $V_{GS}$ tarafındadır.
  - Sembolde ok iç malzemenin (kanalın) tipini gösterir: içeri bakan ok n kanal, dışarı bakan ok p kanal.
- D-MOSFET (kanal ayarlamalı)
  - p tipi altlık (substrate) üzerinde drain ve source'a bağlı n bölgeleri ve aralarında hazır bir n kanalı vardır. Gate, SiO₂ yalıtkan tabakayla kanaldan ayrılır, kanala değmez (ekrandan, 01:25:00).
  - Negatif $V_{GS}$ kanalı daraltır (depletion mode, JFET gibi), pozitif $V_{GS}$ kanalı genişletir (enhancement mode). Formül JFET ile aynıdır.
  - Slayttaki örnek eğri: $I_{DSS} = 8$ mA, $V_P = -6$ V, $V_{GS} = +1$ V'ta $I_D = 10{,}9$ mA (ekrandan, 01:30:00).
- E-MOSFET (kanal oluşturmalı)
  - Yapı D-MOSFET'e benzer ama drain ve source arasında hazır kanal yoktur; $V_{GS} = 0$ iken $I_D = 0$.
  - n kanallı tipte pozitif $V_{GS}$ gate altına elektron toplar; $V_{GS}$ eşik gerilimini ($V_T$) geçince kanal oluşur ve akım artar.
  - Formül: $I_D = k (V_{GS} - V_T)^2$, $k = \dfrac{I_{D(on)}}{(V_{GS(on)} - V_T)^2}$; doyma gerilimi $V_{DS(sat)} = V_{GS} - V_T$ (ekrandan, 01:40:00).
  - p kanallı E-MOSFET'te kanal negatif $V_{GS}$ ile oluşur.
  - Sembolde gate ile kanal arasındaki çizgi kesiklidir; kesik çizgi kanalın henüz oluşmadığını gösterir.
- CMOS ve özet tablo
  - CMOS hücreleri lojik devre tasarımında, RAM'lerde ve görüntü sensörlerinde yaygındır: yüksek giriş empedansı, hızlı anahtarlama, düşük güç.
  - Özet tablo: n kanallı JFET ve D-MOSFET aynı formülü kullanır; E-MOSFET'in formülü farklıdır (ekrandan, 01:45:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- $I_B$'yi yalnız bırakmak
  - BJT sorularında çözüm hep $I_B$'yi bulmakla başlar; $I_C$ yerine $\beta I_B$ yazılarak denklem tek bilinmeyene indirilir. $I_B$ µA, $I_C$ mA mertebesinde çıkar.
- Bir noktanın gerilimini iki yoldan bulmak
  - $V_C$ hem $V_{CC} - I_C R_C$ ile hem de $V_{CE} + V_E$ ile bulunabilir; biri kontrol için kullanılabilir.
- BJT akım kontrollü, FET gerilim kontrollü
  - En temel fark budur; FET'te $I_B$'nin yerini $V_{GS}$ alır.
- Üç formülü bilmek
  - JFET ve D-MOSFET için Shockley denklemi, E-MOSFET için $k(V_{GS} - V_T)^2$ ve bunların $I_D$-$V_{GS}$ eğrileri akılda oturmalıdır.
- Soru çözerek çalışmak
  - Konular kolay olsa da soru çözülmezse işlem hataları çok yapılır; çözümün yolu anlaşılmalıdır.

## Kısa Tekrar Notları

- Kondansatörler DC'yi keser; DC kutuplama çalışma noktasını sabitler, AC işaret onun üzerine biner.
- Gerilim geri beslemeli: $I_B = (V_{CC} - V_{BE}) / [R_B + \beta(R_C + R_E)]$.
- Kollektör geri beslemeli ($R_E = 0$): $V_{CE} = V_C$, $V_B = 0{,}7$ V.
- Tasarımda $V_E \to V_B \to R_1$ ve $V_C \to R_C$ sırası izlenir.
- FET: G-S-D ↔ B-E-C; $I_G \approx 0$, $I_D = I_S$.
- JFET: $V_{GS} = 0 \Rightarrow I_D = I_{DSS}$; $V_{GS} = V_P \Rightarrow I_D = 0$.
- D-MOSFET: hazır kanal; negatif $V_{GS}$ ile depletion, pozitif ile enhancement.
- E-MOSFET: kanal yok; $V_{GS} > V_T$ olunca kanal oluşur, $I_D = k(V_{GS} - V_T)^2$.
- Sembolde ok kanal tipini gösterir; kesik çizgi E-MOSFET'tir.

## Detaylı Açıklamalar

Dersin ilk yarısında BJT DC kutuplama sorularına devam edildi. Gerilim geri beslemeli devrede (Örnek 4.13) taban direnci iki parçadan oluşur ($R_1 = 91$ kΩ, $R_2 = 110$ kΩ) ve ortalarından 10 µF'lık bir kondansatörle toprağa bağlanır (ekrandan, 00:20:00). Kollektör direncinden geçen akım $I'_C = I_C + I_B$'dir, ama $I_B$ çok küçük olduğundan $I'_C \approx I_C$ alınır. Besleme, $R_C$, iki taban direnci, baz-emitör eklemi ve $R_E$ üzerinden yazılan KVL'de $I_C$ yerine $\beta I_B$ konunca $I_B = 17{,}3 / (201\,\text{k} + 75 \cdot 3{,}81\,\text{k}) = 35{,}5$ µA bulunur. $I_C = 75 \cdot 35{,}5\,\mu\text{A} = 2{,}66$ mA'dir ve kollektör gerilimi $V_C = 18 - 2{,}66 \cdot 3{,}3 = 9{,}22$ V olur.

Kollektör geri beslemeli devrede emitör doğrudan topraktadır. $V_{CC} = I_C R_C + I_B R_B + V_{BE}$ denkleminden $I_B = 19{,}3 / (680\,\text{k} + 120 \cdot 4{,}7\,\text{k}) = 15{,}51$ µA, $I_C = 1{,}86$ mA bulunur. $V_E = 0$ olduğundan $V_{CE} = V_C = 20 - 1{,}86 \cdot 4{,}7 = 11{,}26$ V, $V_B = 0{,}7$ V'tur (ekrandan, 00:30:00).

Tasarım sorusunda (Örnek 4.20) çalışma noktası verilip dirençler istenir. $I_E \approx I_C$ kabulüyle $V_E = 2\,\text{mA} \cdot 1{,}2\,\text{k} = 2{,}4$ V, $V_B = 3{,}1$ V bulunur. Bölücü denklemi $3{,}1 = \dfrac{18\,\text{k} \cdot 18}{R_1 + 18\,\text{k}}$'den $R_1 = 86{,}52$ kΩ çıkar. $V_C = 10 + 2{,}4 = 12{,}4$ V olduğundan $R_C = 5{,}6\,\text{V} / 2\,\text{mA} = 2{,}8$ kΩ'dur (ekrandan, 00:35:00).

- **Ders sonrası not:** Hoca tahtaya bölücü formülünü $V_B = V_{CC} \cdot \dfrac{R_1}{R_1 + 18\,\text{k}\Omega}$ diye yazdı (00:32:34). Doğrusu, $V_B$ alttaki dirençte (18 kΩ) düştüğü için $V_B = V_{CC} \cdot \dfrac{18\,\text{k}\Omega}{R_1 + 18\,\text{k}\Omega}$'dur. Slayttaki çözüm de böyledir ve $R_1 = 86{,}52$ kΩ sonucu bu doğru formülden çıkar.

İkinci yarıda FET'lere geçildi. BJT'de $I_B$'nin varlığına ya da yokluğuna göre kollektör-emitör yolundan akım akıyordu (akım kontrolü). FET'te ise gate-source gerilimi $V_{GS}$ kanalın genişliğini değiştirir (gerilim kontrolü). n kanallı JFET'te n tipi kanalın çevresi p tipi bir kuşakla sarılıdır. $V_{GS} = 0$ iken kanal en açıktır ve $I_{DSS}$ akar; $V_{GS}$ negatifleştikçe geçiş bölgeleri büyür ve "iki parmağın arasında bir tutam tuzu sıkıştırmak" gibi kanalı kapatır. Kanalın tamamen kapandığı gerilim $V_P$'dir. Bu davranış Shockley denklemiyle $I_D = I_{DSS}(1 - V_{GS}/V_P)^2$ olarak verilir; kare terim yüzünden $I_D$-$V_{GS}$ eğrisi paraboliktir.

- **Ders sonrası not:** Hoca pinch-off anlatırken kanal kapanınca $I_D = I_S = 0$ olduğunu söyledi (01:09:44). Ekrandaki slayt (ekrandan, 01:10:00) iki durumu ayırır: $V_{GS} = 0$ iken $V_{DS}$ artırılıp $V_P$'ye ulaşınca kanal "pinch off" olur ama akım sıfıra düşmez, $I_{DSS}$ düzeyinde doyuma gider. Akımın gerçekten sıfır olduğu durum $V_{GS} = V_P$ ($V_{GS(off)}$) durumudur.

D-MOSFET'te p altlık üzerinde hazır bir n kanalı vardır ve gate, SiO₂ ile kanaldan yalıtılmıştır. JFET'ten farkı pozitif $V_{GS}$ de alabilmesidir: pozitif gerilim kanalı genişletir ve akım $I_{DSS}$'nin üstüne çıkar (enhancement mode). Slayttaki eğride $I_{DSS} = 8$ mA, $V_P = -6$ V için $V_{GS} = +1$ V'ta $I_D = 8(1 + 1/6)^2 \approx 10{,}9$ mA'dir (ekrandan, 01:30:00). E-MOSFET'te kanal yoktur; pozitif $V_{GS}$ eşik gerilimini aşınca kanal oluşur ve $I_D = k(V_{GS} - V_T)^2$ ile artar.

- **Ders sonrası not:** Hoca eşikten sonra akımın "eksponansiyel" arttığını söyledi (01:38:25). Slayttaki formüle göre artış üstel değil, kareseldir: $I_D = k(V_{GS} - V_T)^2$.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
