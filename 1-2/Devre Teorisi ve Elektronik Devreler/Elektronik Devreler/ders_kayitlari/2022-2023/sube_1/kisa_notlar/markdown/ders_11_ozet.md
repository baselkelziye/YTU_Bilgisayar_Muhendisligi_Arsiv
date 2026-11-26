# Ders 11 Çalışma Özeti

## Genel Konular

- BJT yapısının ve temel bağıntıların tekrarı
  - İki tür transistör vardır: pnp ve npn. Uçlar E (emetör, yayıcı), B (baz, temel) ve C (kolektör, toplayıcı) diye adlandırılır (ekrandan, 00:05:00).
  - Sembolde ok daima n tipi bölgeyi gösterir. Ok bazdan dışarı doğruysa baz p tipidir ve transistör npn'dir; ok baza doğruysa baz n tipidir ve transistör pnp'dir.
  - npn'de akım kolektörden girer, emetörden çıkar, baz akımı transistöre doğrudur. pnp'de bütün akım yönleri terstir.
  - Her iki tipte de transistör bir düğüm gibi düşünülerek $I_E = I_C + I_B$ yazılır.
  - $I_C$ ve $I_E$ miliamper ($10^{-3}$ A), $I_B$ mikroamper ($10^{-6}$ A) mertebesindedir. Bu yüzden $I_B$ ihmal edilerek $I_C \approx I_E$ alınır. Silisyum transistörde $V_{BE} \approx 0{,}7$ V'tur.
  - $\alpha = I_C / I_E$, $\beta = I_C / I_B$. $\beta$, baz akımının kaç kat güçlendirildiğini gösterir.
- Çalışma bölgeleri (ekrandan, 00:10:00)
  - Aktif (doğrusal) bölge: yükselticinin çalışma aralığıdır; transistör asıl burada çalıştırılır.
  - Kesim (cutoff): yükseltici kapalıdır; gerilim vardır ama akım çok küçüktür ($I_C$ minimum).
  - Doyum (saturation): yükseltici tam açıktır; akım vardır ama gerilim çok küçüktür ($V_{CE}$ minimum).
  - Karakteristikte ayrıca $P_{C\max}$ eğrisinin dışındaki bölge (güç sınırı), $I_{C\max}$ ve $V_{CE\max}$ sınırları vardır. Bu sınırların ve kesim/doyumun dışında kalan kısım aktif bölgedir (ekrandan, 00:15:00).
- Kutuplama (biasing) ve çalışma noktası
  - Kutuplama, transistörü çalışır duruma getirmek için uygulanan DC gerilimdir. Amaç transistörü aktif bölgede uygun bir noktaya yerleştirmek, böylece AC işaretlerin doyuma ya da kesime gitmeden bozulmadan işlenmesini sağlamaktır.
  - DC giriş bir çalışma noktası (operating ya da quiescent point, Q-noktası) belirler (ekrandan, 00:15:00).
  - Derste incelenecek DC kutuplama devreleri sıralandı: sabit kutuplama, emetör kararlı kutuplama, gerilim bölücü kutuplama ve gerilim (kolektör) geri beslemeli kutuplama. <!-- BELİRSİZ: listede Whisper'ın "kolektör emetör döngüsü" diye yazdığı bir madde daha var; beşinci devre türü altyazıdan net değil -->
- Sabit kutuplama (fixed bias) (ekrandan, 00:20:00)
  - Devre: $V_{CC}$ hem $R_B$ üzerinden bazı hem $R_C$ üzerinden kolektörü besler; emetör doğrudan toprağa bağlıdır. Giriş $C_1$ üzerinden baza, çıkış $C_2$ üzerinden kolektörden alınır.
  - Emetör toprağa en yakın uç olduğu için bu bir ortak emetörlü (common emitter) devredir.
  - Giriş ve çıkıştaki kondansatörler DC'yi keser (blocks DC), yalnız sıfır ortalamalı AC bileşeni geçirir. DC analizde kondansatörler açık devre sayılır (ekrandan, 00:25:00).
  - Baz-emetör döngüsü: $V_{CC} = I_B R_B + V_{BE}$, buradan $I_B = \dfrac{V_{CC} - V_{BE}}{R_B}$.
  - Kolektör-emetör döngüsü: $I_C = \beta I_B$, $V_{CC} = I_C R_C + V_{CE}$, buradan $V_{CE} = V_{CC} - I_C R_C$ (ekrandan, 00:30:00).
- Yük hattı (load line) analizi
  - Doyumda $V_{CE} \approx 0$ olur, transistör kısa devre gibidir: $I_{C\,sat} = V_{CC}/R_C$.
  - Kesimde $I_C = I_E = 0$ olur, dirençlerde gerilim düşmez: $V_{CE} = V_{CC}$.
  - Bu iki uç nokta birleştirilerek yük hattı çizilir; hattın $I_B$ eğrisini kestiği nokta Q-noktasıdır.
- Devre değerlerinin Q-noktasına etkisi (ekrandan, 00:35:00 ve 00:40:00)
  - $V_{CC}$ büyüdükçe ($V_{CC1} > V_{CC2} > V_{CC3}$) yük hattı yukarı ve sağa paralel kayar; sabit $I_B$ eğrisi üzerindeki Q-noktası sağa doğru ilerler.
  - $R_C$ büyüdükçe ($R_3 > R_2 > R_1$) $V_{CC}/R_C$ kesişimi aşağı iner, hattın eğimi azalır, Q-noktası sabit $I_B$ eğrisi üzerinde sola, doyuma doğru kayar.
  - $I_B$ büyüdükçe Q-noktası daha üstteki karakteristik eğrisine çıkar.
- Emetör kararlı kutuplama (emitter-stabilized bias) (ekrandan, 00:45:00)
  - Sabit kutuplamadan tek farkı emetörle toprak arasına bir $R_E$ direnci eklenmesidir; bu, kutuplamayı daha kararlı yapar.
  - $I_E = I_C + I_B = (\beta + 1) I_B$.
  - Baz-emetör döngüsü: $V_{CC} = I_B R_B + V_{BE} + I_E R_E$, buradan $I_B = \dfrac{V_{CC} - V_{BE}}{R_B + (\beta + 1) R_E}$.
  - Kolektör-emetör döngüsü ($I_E \approx I_C$): $V_{CC} = I_C R_C + V_{CE} + I_E R_E$, $V_{CE} = V_{CC} - I_C (R_C + R_E)$.
  - Yük hattı uçları: kesimde $V_{CE} = V_{CC}$, $I_C = 0$; doyumda $V_{CE} = 0$, $I_{C\,sat} = \dfrac{V_{CC}}{R_C + R_E}$ (ekrandan, 00:50:00).
- Gerilim bölücü (voltage divider)
  - İki seri direnç arasındaki orta noktanın gerilimi: $V_{out} = \dfrac{R_2}{R_1 + R_2} V_{in}$; $R_2$ orta noktadan toprağa giden dirençtir (ekrandan, 00:55:00).
  - Büyük dirençte daha büyük gerilim düşer. Her direncin payı kendi değerinin toplam dirence oranıdır.
- Gerilim bölücü kutuplama (voltage divider bias) (ekrandan, 01:00:00 ve 01:05:00)
  - $I_B$ çok küçük olduğundan $I_1 \approx I_2$ alınır ve baz gerilimi bölücüden bulunur: $V_B = \dfrac{R_2}{R_1 + R_2} V_{CC}$.
  - $V_{BE} = V_B - V_E$, dolayısıyla $V_E = V_B - V_{BE}$ ve $V_E = I_E R_E$.
  - Kolektör tarafı: $V_{CC} = I_C R_C + V_{CE} + I_E R_E$.
  - Akım ve gerilimler $\beta$ değişimlerinden neredeyse bağımsızdır; çok kararlı bir kutuplama devresidir.
- Kolektör geri beslemeli kutuplama (ekrandan, 01:10:00)
  - $R_B$ baz akımını $V_{CC}$'den değil, kolektör (çıkış) ucundan alır.
  - $R_C$'den geçen akım $I'_C = I_C + I_B \approx I_C$ olur.
  - Baz-emetör döngüsü: $V_{CC} = I'_C R_C + I_B R_B + V_{BE} + I_E R_E$. $I_C = \beta I_B$ ve $I_E \approx I_C$ yazılınca $I_B = \dfrac{V_{CC} - V_{BE}}{R_B + \beta (R_C + R_E)}$.
  - Kolektör-emetör döngüsü: $V_{CC} = I'_C R_C + V_{CE} + I_E R_E$.
- Transistörün anahtar olarak kullanılması (ekrandan, 01:15:00)
  - Örnek devre: $V_{CC} = 5$ V, $R_C = 0{,}82\ \text{k}\Omega$, $R_B = 68\ \text{k}\Omega$, $h_{FE} = 125$; girişe 0 V ile 5 V arasında değişen kare dalga uygulanır, çıkış kolektörden ($V_C$) alınır.
  - Giriş 0 V iken baz akımı akmaz, transistör kesimdedir; $R_C$ üzerinde gerilim düşmez ve $V_C = 5$ V olur.
  - Giriş 5 V iken transistör iletime girer; $V_C \approx 0$ V olur. Devre 0'ı 1'e, 1'i 0'a çevirir: tek transistörle yapılan bir DEĞİL (NOT) kapısı.
  - Gerçek geçişler anlık değildir: gecikme ($t_d$), yükselme ($t_r$, %10'dan %90'a), depolama ($t_s$) ve düşme ($t_f$) süreleri vardır. Hızlı mantık devrelerinde bu sürelerin olabildiğince kısa olması istenir.
- pnp transistörler (ekrandan, 01:20:00)
  - Kutuplama analizi npn ile aynıdır; tek fark akımların ters yönde akmasıdır. Eşitlikler ve yaklaşıklıklar aynen kullanılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ok daima n tipini gösterir
  - npn/pnp ayrımı sembolden yapılırken okun yönüne bakılır; ortadaki harf bazın tipidir.
- $I_B$'nin ihmal edilmesi
  - $I_B$ mikroamper, $I_C$ miliamper mertebesinde olduğu için $I_C \approx I_E$ ve gerilim bölücüde $I_1 \approx I_2$ yaklaşımları yapılır. Bütün kutuplama çözümleri bu varsayıma dayanır.
- Baz akımı transistörü açıp kapayan akımdır
  - $I_B$ olmadan $I_C$ ve $I_E$ oluşmaz; baz akımı transistörün anahtarı gibi düşünülmelidir.
- İki döngüyle çözüm
  - Her kutuplama devresi transistörün ortasından ikiye ayrılarak incelenir: önce baz-emetör döngüsünden $I_B$, sonra kolektör-emetör döngüsünden $V_{CE}$ bulunur.
  - KVL yazılırken besleme noktasından toprağa giden paralel kolların gerilimleri eşitlenir: $V_{CC}$ = akım yönündeki direnç gerilimleri + eklem gerilimleri.
- Yük hattının uç noktaları
  - Kesimde $V_{CE} = V_{CC}$ ($I_C = 0$), doyumda $V_{CE} = 0$ ($I_C$ maksimum). Bütün kutuplama devrelerinde aynı mantık kullanılır.
- Gerilim bölücü
  - Orta noktanın gerilimi, o noktadan toprağa giden direncin toplam dirence oranıyla bulunur; payda $R_1$ değil $R_2$ yer alır.

## Kısa Tekrar Notları

- $I_E = I_C + I_B$, $I_C \approx I_E$, $V_{BE} \approx 0{,}7$ V (Si), $\beta = I_C/I_B$, $I_E = (\beta+1) I_B$.
- Aktif bölge: yükseltme. Kesim: $I_C \approx 0$. Doyum: $V_{CE} \approx 0$.
- Kondansatörler DC'yi keser; DC analizde açık devre sayılır.
- Sabit kutuplama: $I_B = (V_{CC} - V_{BE})/R_B$, $V_{CE} = V_{CC} - I_C R_C$, $I_{C\,sat} = V_{CC}/R_C$.
- Emetör kararlı: $I_B = (V_{CC} - V_{BE})/(R_B + (\beta+1)R_E)$, $V_{CE} = V_{CC} - I_C(R_C + R_E)$, $I_{C\,sat} = V_{CC}/(R_C + R_E)$.
- Gerilim bölücü: $V_B = R_2 V_{CC}/(R_1 + R_2)$, $V_E = V_B - V_{BE}$, $I_E = V_E/R_E$; $\beta$'dan neredeyse bağımsız.
- Kolektör geri beslemeli: $I_B = (V_{CC} - V_{BE})/(R_B + \beta(R_C + R_E))$.
- $V_{CC}$ artarsa yük hattı paralel kayar; $R_C$ artarsa hat yatıklaşır, Q doyuma yaklaşır.
- Tek transistörlü anahtar: 0 V girişte $V_C = V_{CC}$, 5 V girişte $V_C \approx 0$; DEĞİL kapısı.
- pnp: aynı denklemler, ters akım yönleri.

## Detaylı Açıklamalar

- **Kutuplama neden gerekir?** Transistör bir AC işareti yükseltebilmek için önce DC ile aktif bölgede bir çalışma noktasına getirilmelidir. Q-noktası kesime ya da doyuma çok yakın seçilirse çıkış işaretinin bir kısmı kırpılır. Bu yüzden önce DC devre çözülüp $I_B$, $I_C$ ve $V_{CE}$ bulunur, ardından AC işaretin bu nokta etrafında salınacağı düşünülür. Giriş ve çıkıştaki kuplaj kondansatörleri, ofsetli bir işaretin DC bileşenini keserek yalnız sıfır ortalamalı AC bileşeni geçirir; böylece kutuplama, önceki ve sonraki katlardan etkilenmez.
- **KVL'yi düğüm gerilimiyle yazmak.** Hoca KVL'yi "toplam sıfır" biçimi yerine şu yolla yazdı: $V_{CC}$ uygulanan A noktasından toprağa giden her kolun toplam gerilimi $V_{CC}$'ye eşittir. Akım yönünde ilerlerken her direnç için $I \cdot R$, eklemler için $V_{BE}$ ya da $V_{CE}$ eklenir. Örneğin sabit kutuplamada sol kol $V_{CC} = I_B R_B + V_{BE}$, sağ kol $V_{CC} = I_C R_C + V_{CE}$ verir. Bu, klasik $V_{CC} - I_B R_B - V_{BE} = 0$ ifadesiyle aynıdır.
- **Yük hattı.** $V_{CE} = V_{CC} - I_C R_C$ doğrusu $I_C$-$V_{CE}$ düzleminde çizilir. $V_{CE} = 0$ için $I_C = V_{CC}/R_C$ (doyum ucu), $I_C = 0$ için $V_{CE} = V_{CC}$ (kesim ucu) bulunur. Baz devresinden hesaplanan $I_B$'ye ait karakteristik eğrisiyle bu doğrunun kesiştiği yer Q-noktasıdır. Emetör direnci olan devrelerde doyum akımı $V_{CC}/(R_C + R_E)$ olur.
- **Gerilim bölücü örnekleri.** $V_{in} = 10$ V, $R_1 = R_2 = 1\ \text{k}\Omega$ ise orta nokta $\frac{1}{2} \cdot 10 = 5$ V olur. $R_2 = 3\ \text{k}\Omega$ yapılırsa $R_2$ üzerine $\frac{3}{4} \cdot 10 = 7{,}5$ V düşer. $R_2 = 2$, $R_1 = 5$ birim olursa $R_2$ üzerindeki gerilim $\frac{2}{7} V_{in}$, $R_1$ üzerindeki $\frac{5}{7} V_{in}$ olur (python ile kontrol edildi).
- **Kutuplama devrelerinin karşılaştırılması.** Sabit kutuplamada $I_B$ yalnız $V_{CC}$ ve $R_B$ ile belirlenir; $I_C = \beta I_B$ olduğundan Q-noktası $\beta$'ya doğrudan bağlıdır. $R_E$ eklenince paydaya $(\beta+1)R_E$ gelir ve devre daha kararlı olur. Gerilim bölücü kutuplamada baz gerilimi $\beta$'dan bağımsız olarak dirençlerle sabitlendiği için akım ve gerilimler $\beta$ değişimlerinden neredeyse etkilenmez. Kolektör geri beslemeli yapıda $R_B$ kolektöre bağlanır; paydada $\beta(R_C + R_E)$ terimi oluşur.
- **Anahtarlama.** Transistör yalnız DC ile kesim ve doyum arasında sürülürse elektronik anahtar olur. Örnek devrede 0 V girişte baz akımı yoktur, $R_C$'de gerilim düşmez, $V_C = V_{CC} = 5$ V olur; 5 V girişte transistör iletir ve $V_C$ yaklaşık 0 V'a iner. Bu bir DEĞİL kapısıdır. Gerçekte geçişlerde gecikme, yükselme, depolama ve düşme süreleri bulunur; yüksek hızlı mantık devrelerinde bu süreler kısaltılmaya çalışılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
