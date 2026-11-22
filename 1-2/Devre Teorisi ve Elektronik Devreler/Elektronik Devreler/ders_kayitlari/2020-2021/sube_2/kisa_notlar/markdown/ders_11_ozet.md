# Ders 11 Çalışma Özeti

## Genel Konular

- BJT'nin yapısı ve çalışma şartı (tekrar)
  - Bipolar transistör, iki p-n ekleminin art arda (sırt sırta iki diyot gibi) kullanılmasıyla oluşur. Orta bacağın (base) n ya da p tipi olmasına göre PNP ve NPN olmak üzere iki tipi vardır. Üç bacağı emiter (E), base (B) ve kolektör (C)'dür.
  - Transistörün aktif bölgede çalışması için base-emiter eklemi doğru polarlanır (buradaki fakirleşmiş bölge daralır), base-kolektör eklemi ters polarlanır (buradaki fakirleşmiş bölge genişler). Bu kural PNP ve NPN için aynıdır.
  - Şematik sembolde ok emiter bacağı üzerindedir; okun yönü transistörün NPN mi PNP mi olduğunu gösterir. <!-- BELİRSİZ: Okun yönüyle tipin eşleştirildiği anlatım altyazıda bozuk (00:22:11-00:22:52). -->
- Transistör akımları
  - Akımların korunumundan (KCL): $I_E = I_C + I_B$ (ekrandan, 00:20:00). Bu bağıntı bütün konfigürasyonlarda geçerlidir.
  - Kolektör akımı çoğunluk ve azınlık taşıyıcı bileşenlerinden oluşur: $I_C = I_{C\,majority} + I_{CO\,minority}$ (ekrandan, 00:20:00). Azınlık bileşeni ($I_{CO}$, sıcaklıkla ilgili sızıntı akımı) derste hesaplanmayacak.
  - Base akımı çok küçüktür (mikroamper düzeyi), kolektör akımı miliamper düzeyindedir.
- Ortak base (common-base, CB) konfigürasyonu
  - Base, hem emiter hem kolektör devresinde ortaktır. Genelde yükselteç olarak kullanılır.
  - Giriş karakteristiği: $I_E$–$V_{BE}$ eğrisi, $V_{CB}$ = 1, 10, 20 V için (ekrandan, 00:25:00). $V_{BE}$ yaklaşık 0,7 V'u geçmeden emiter akımı oluşmaz; eşikten sonra $I_E$ hızla artar. Aynı $V_{BE}$'de $V_{CB}$ arttıkça $I_E$ biraz daha büyüktür.
  - Çıkış karakteristiği: $I_C$–$V_{CB}$ eğrisi, farklı $I_E$ değerleri için (ekrandan, 00:30:00). Aktif bölgede $I_C \approx I_E$; $I_E = 0$ altı kesim (cutoff), $V_{CB} < 0$ tarafı doyum (saturation) bölgesidir.
  - Yaklaşık analizde $I_C \approx I_E$, $V_{BE} \approx 0{,}7$ V alınır.
- Alfa ($\alpha$)
  - $\alpha = I_C / I_E$. İdealde 1'dir (base akımı yok sayılır), pratikte 0,9–0,998 arasıdır. Soruda $\alpha$ ve $I_E$ verilirse $I_C = \alpha I_E$, sonra $I_B = I_E - I_C$ bulunur.
- Ortak emiter (common-emitter, CE) konfigürasyonu
  - Emiter, hem base hem kolektör devresinde ortaktır. Base-emiter doğru, kolektör tarafı ters polarlanır.
  - Kolektör karakteristiği: $I_C$–$V_{CE}$, $I_B$ = 0–90 µA için; base karakteristiği: $I_B$–$V_{BE}$, $V_{CE}$ = 1, 10, 20 V için (ekrandan, 00:35:00). Aynı $V_{BE}$'de küçük $V_{CE}$ daha büyük $I_B$ verir.
- Beta ($\beta$)
  - $\beta = I_C / I_B$; genelde 50–200 arasıdır. Transistörün üretimden gelen bir parametresidir.
  - Grafikten beta: $\beta_{AC} = \Delta I_C / \Delta I_B$, $\beta_{DC} = I_C / I_B$ (ekrandan, 00:40:00).
  - Bağıntılar: $I_C = \beta I_B$, $I_E = (\beta + 1) I_B$, $\alpha = \dfrac{\beta}{\beta + 1}$, $\beta = \dfrac{\alpha}{1 - \alpha}$.
- Ortak kolektör (common-collector, CC) konfigürasyonu
  - Kolektör, giriş ve çıkış devresinde ortaktır. Karakteristikleri CE'ye benzer; belli bir $V_{CE}$ için $I_B$ eğrilerinden karşılık gelen akım okunur.
- Güç harcaması (ekrandan, 00:45:00)
  - CB: $P_{C\max} = V_{CB} I_C$; CE: $P_{C\max} = V_{CE} I_C$; CC: $P_{C\max} = V_{CE} I_E$. Base akımı güce katılmaz.
- Transistör bilgi sayfası (datasheet) ve test
  - 2N4123 (NPN silisyum, TO-92) örneği: $V_{CEO}$ = 30 V, $V_{CBO}$ = 40 V, $V_{EBO}$ = 5 V, $I_C$ = 200 mA, $P_D$ = 625 mW; bacaklar 1 emiter, 2 base, 3 kolektör (ekrandan, 00:50:00).
  - Ohmmetre testi: base-emiter doğru yönde ölçülünce küçük, base-kolektör ters yönde ölçülünce çok büyük direnç görülmelidir; aksi transistörün bozuk olduğunu gösterir.
  - Fototransistör gibi farklı transistör türleri vardır.
  - Transistör, bilgisayar donanımında en çok kullanılan elemandır: mantık kapıları transistörlerden kurulur. Önemli kullanımlarından biri anahtarlamadır.
- Kutuplama (biasing) ve çalışma noktası
  - Kutuplama, transistörü açıp AC işareti yükseltebilmesi için uygulanan DC gerilimlerdir (ekrandan, 00:55:00). Transistör AC işaret üzerinde işlem yapar, ama çalışma noktası tamamen DC ile belirlenir; sorular DC analize dayanır.
  - Çalışma noktası (Q-point): karakteristik üzerinde transistörün çalıştığı nokta. Sınırlar: $I_{C\max}$, $V_{CE\max}$, $P_{C\max}$ eğrisi, kesim ve doyum bölgeleri (ekrandan, 01:00:00).
  - Çalışma bölgeleri: aktif (BE doğru, BC ters), kesim (BE ters), doyum (BE doğru, BC de doğru).
- Sabit kutuplama (fixed bias): base-emiter çevresi
  - KVL: $V_{CC} - I_B R_B - V_{BE} = 0 \Rightarrow I_B = \dfrac{V_{CC} - V_{BE}}{R_B}$ (ekrandan, 01:05:00).
  - Kolektör-emiter çevresi: $V_{CE} = V_{CC} - I_C R_C$, $I_C = \beta I_B$. Doyum akımı $I_{C\,sat} = V_{CC}/R_C$.
- Emiter dirençli kutuplama
  - KVL: $V_{CC} - I_B R_B - V_{BE} - I_E R_E = 0$, $I_E = (\beta+1) I_B$ ile $I_B = \dfrac{V_{CC} - V_{BE}}{R_B + (\beta+1) R_E}$ (ekrandan, 01:10:00).
  - $V_{CE} = V_{CC} - I_C R_C - I_E R_E$; $V_E = I_E R_E$, $V_C = V_{CE} + V_E = V_{CC} - I_C R_C$, $V_B = V_E + V_{BE} = V_{CC} - I_B R_B$.
  - $V_{CE} = 0$ alınırsa doyum akımı $I_{C\,sat} = V_{CC}/(R_C + R_E)$.
  - $V_{BE}$: silisyum 0,7 V, germanyum 0,3 V, galyum arsenit 1,2 V.
- Gerilim bölücülü kutuplama (yaklaşık analiz, ekrandan, 01:15:00)
  - $I_B \ll I_1$, $I_1 \cong I_2$ ve $\beta R_E > 10 R_2$ iken: $V_B = \dfrac{R_2 V_{CC}}{R_1 + R_2}$, $V_E = V_B - V_{BE}$, $I_E = V_E / R_E$, $V_{CE} = V_{CC} - I_C (R_C + R_E)$ ($I_E \cong I_C$).
- Gerilim geri beslemeli DC kutuplama
  - $R_B$ kolektörden base'e bağlıdır; $R_C$'den $I'_C = I_C + I_B$ akar. KVL: $V_{CC} - I'_C R_C - I_B R_B - V_{BE} - I_E R_E = 0$. $I'_C \approx I_C \approx I_E$ ve $I_C = \beta I_B$ yazılarak $I_B$ çekilir. <!-- BELİRSİZ: Bu slaytın karesi yok; denklem altyazıdan kuruldu (01:17:10). -->
- Transistörlü anahtarlama devresi
  - Yalnız DC kaynak uygulanan transistör elektronik anahtar olarak kullanılabilir (ekrandan, 01:20:00). Örnek: $V_{CC}$ = 5 V, $R_C$ = 0,82 kΩ, $R_B$ = 68 kΩ, $h_{FE}$ = 125. Çözümü sonraki derse kaldı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Base akımı mikroamper düzeyinde çıkmalı
  - Bir soruda $I_B$ amper ya da onlarca miliamper çıkarsa çözümde büyük olasılıkla hata vardır.
- $I_E = I_C + I_B$ her zaman geçerli
  - Hoca bunu "en önemli kaide" olarak defalarca tekrarladı. $I_B$ çok küçük olduğundan birçok soruda $I_C \approx I_E$ kabul edilir.
- Transistör sorularının anahtarı KVL
  - Devre ne kadar karışık olursa olsun KVL denklemini doğru yazmak, $I_E = I_C + I_B$ ve $I_B$'nin çok küçük olduğunu bilmek soruları çözmeye yeter.
- Kutuplama DC'dir
  - Transistör AC işaret üzerinde çalışsa da çalışma noktasını DC gerilimler belirler; sorularda DC analiz yapılır.
- Beta üretim parametresidir
  - Grafikte hangi $V_{CE}$'de bakılırsa bakılsın beta yaklaşık aynı çıkar; en doğrusu üreticinin verdiği değerdir.

## Kısa Tekrar Notları

- Aktif bölge: BE doğru, BC ters polar. Kesim: BE ters. Doyum: BC de doğru polar.
- $I_E = I_C + I_B$, $I_C = \beta I_B$, $I_E = (\beta+1) I_B$.
- $\alpha = I_C/I_E \approx 0{,}9$–$0{,}998$; $\beta = I_C/I_B \approx 50$–$200$; $\alpha = \beta/(\beta+1)$, $\beta = \alpha/(1-\alpha)$.
- CB yükselteç örneği: $V_i$ = 200 mV, $R_i$ = 20 Ω, $R_L$ = 5 kΩ → $I_E$ = 10 mA, $V_L$ = 50 V, kazanç 250.
- Grafikten beta ($V_{CE}$ = 7,5 V): $\beta_{AC} = 1\text{ mA}/10\text{ µA} = 100$, $\beta_{DC} = 2{,}7\text{ mA}/25\text{ µA} = 108$.
- Güç: CB $V_{CB} I_C$, CE $V_{CE} I_C$, CC $V_{CE} I_E$.
- Sabit kutuplama: $I_B = (V_{CC} - V_{BE})/R_B$.
- Emiter dirençli: $I_B = (V_{CC} - V_{BE})/[R_B + (\beta+1)R_E]$.
- Gerilim bölücü: $V_B = R_2 V_{CC}/(R_1+R_2)$, $I_E = (V_B - V_{BE})/R_E$.
- Doyum akımı: $V_{CE} = 0$ alınarak bulunur.

## Detaylı Açıklamalar

- Ders, bir önceki derste girişi yapılan bipolar transistörün (BJT) devamıdır. Hoca önce yapıyı hatırlattı: transistör iki p-n ekleminden oluşur; base-emiter eklemi doğru polarlanarak bu eklemdeki fakirleşmiş bölge daraltılır, base-kolektör eklemi ters polarlanarak genişletilir. PNP'de emitere artı, base'e eksi; NPN'de emitere eksi, base'e artı verilir. Kolektör tarafı da buna göre ters polarlanır.
- $V_{BE}$'nin yaklaşık 0,7 V'u geçmeden akım akmaması diyottaki mantıkla aynıdır: base-emiter eklemi bir silisyum diyot gibi davranır ve eşik gerilimi aşılmadan iletime geçmez. Giriş karakteristiğinde hoca $V_{BE}$ = 0,8 V için $V_{CB}$ arttıkça emiter akımının daha yüksek olduğunu gösterdi <!-- BELİRSİZ: Hocanın okuduğu 5 mA ve 8 mA değerleri altyazıdan; grafikte tam okunmadı (00:27:08). -->. Yorum: BE ne kadar doğru, BC ne kadar ters polarlanırsa transistör o kadar iyi çalışır; eşikten sonra $V_{BE}$ artışı $I_E$'yi çok hızlı, $V_{CB}$ artışı daha az ama yine artırır.
- Ortak base yükselteç örneğinde girişte 200 mV'luk işaret ve 20 Ω'luk giriş direnci vardır; $I_E = 200\text{ mV}/20\ \Omega = 10$ mA. $I_C \approx I_E$ kabulüyle 5 kΩ'luk yükte $V_L = 10\text{ mA} \times 5\text{ kΩ} = 50$ V oluşur; gerilim 250 kat yükseltilmiştir (python ile doğrulandı).
- Beta, grafikten iki komşu $I_B$ eğrisi arasındaki $I_C$ farkının $I_B$ farkına oranıyla bulunur. Slayttaki örnekte $V_{CE}$ = 7,5 V'ta $I_B$ = 30 µA için $I_C$ = 3,2 mA, $I_B$ = 20 µA için $I_C$ = 2,2 mA'dir; $\beta_{AC} = 1\text{ mA}/10\text{ µA} = 100$. Aynı noktada Q-noktası ($I_B$ = 25 µA, $I_C$ = 2,7 mA) için $\beta_{DC} = 108$'dir (ekrandan, 00:40:00; python ile doğrulandı).
- Transistör bir anahtar gibi kullanılabilir: kolektöre bir gerilim bağlanır, akımın kolektörden emitere akıp akmaması base-emiter ekleminin doğru polarlanıp polarlanmamasına bağlıdır. Doğru polarma yoksa transistör kesimde kalır. Hoca, mantık kapılarının transistörlerle kurulduğunu ve işlemcilerin bu kapılardan oluştuğunu hatırlattı; vakum tüpünden transistöre geçişin bilgisayarların hızlı gelişmesine yol açtığını anlattı.
- Kutuplama analizinde devre iki çevreye bölünür. Önce base-emiter çevresinde KVL yazılır ve $I_B$ bulunur; sonra $I_C = \beta I_B$ ile kolektör akımı, kolektör-emiter çevresinde KVL ile $V_{CE}$ bulunur. Emiter direnci varsa $I_E$ yerine $(\beta+1)I_B$ yazılarak bilinmeyen tek değişkene ($I_B$) indirilir. Düğüm gerilimleri: $V_E = I_E R_E$, $V_C = V_{CE} + V_E$, $V_B = V_E + 0{,}7$ V.
- Gerilim bölücülü kutuplamada base gerilimi $R_2$ üzerindeki gerilimdir: $V_B = V_{CC} R_2/(R_1 + R_2)$. Bundan $V_{BE}$ çıkarılınca $V_E$, $R_E$'ye bölününce $I_E$ bulunur; $V_{CE} = V_{CC} - I_C(R_C + R_E)$.
- Ders sonrası not: Hoca emiteri "transistörü kontrol etmemizi sağlayan bacak" diye andı; doğrusu kontrol bacağı base'tir (küçük base akımı büyük kolektör akımını kontrol eder).
- Ders sonrası not: Hoca base akımını "gerçek bir akım değil, sızıntı akımı" diye niteledi; doğrusu base akımı büyük olasılıkla base bölgesindeki yeniden birleşmeden kaynaklanan gerçek bir akımdır. Sızıntı (azınlık taşıyıcı) akımı $I_{CO}$'dır.
- Ders sonrası not: Hoca ortak kolektörde "base-kolektör doğru, emiter-kolektör ters polarlanır" dedi; doğrusu konfigürasyon ne olursa olsun aktif bölgede base-emiter doğru, base-kolektör ters polarlanır.
- Ders sonrası not: Hoca doyumu $V_{CE}$'ye eksi değer vermek diye anlattı; doğrusu doyumda base-kolektör eklemi de doğru polarlıdır ve $V_{CE}$ büyük olasılıkla küçük pozitif bir değerdedir ($V_{CE\,sat}$ ≈ 0,1–0,3 V). Doyum yükselteç için istenmez, ama anahtarlamada "açık" durum olarak kullanılır.
- Ders sonrası not: Hoca ENIAC'ı "tüp diyot tabanlı" diye andı; ENIAC büyük olasılıkla çoğunluğu vakum tüpünden (triyot vb.) oluşan bir bilgisayardı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
