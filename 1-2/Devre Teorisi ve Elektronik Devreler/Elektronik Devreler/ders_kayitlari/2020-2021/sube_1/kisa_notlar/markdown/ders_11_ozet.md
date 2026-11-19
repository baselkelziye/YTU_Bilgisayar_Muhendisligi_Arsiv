# Ders 11 Çalışma Özeti

## Genel Konular

- Kutuplama (biasing) kavramı
  - Kutuplama, transistörü iletime sokup AC işareti yükseltebilir hale getirmek için uygulanan DC gerilimlerdir (ekrandan, 00:05:00). Önce DC ile bir çalışma noktası kurulur, sonra bunun üzerine küçük AC işaretler binerek kuvvetlendirilir.
  - Bir $x(t)$ işareti iki kısımdan oluşur: DC kısım işaretin ortalamasıdır ($f = 0$ bileşeni), AC kısım sıfır ortalamalı, sinüzoidal bileşenlerin toplamı olan değişken kısımdır. İşaret sıfırın üzerinde duruyorsa bir DC ofseti vardır.
- npn ve pnp hatırlatması
  - Emitör ucundaki ok her zaman N tarafını gösterir. Ok dışarı bakıyorsa emitör ve kolektör N, baz P'dir (npn). Ok içeri bakıyorsa baz N, emitör ve kolektör P'dir (pnp).
  - npn'de $I_E = I_C + I_B$; $I_B$ çok küçük olduğu için $I_C \approx I_E$. Baz-emitör gerilimi yaklaşık 0,7 V'u geçince transistör akım akıtmaya başlar.
- Çalışma noktası (Q noktası, quiescent point)
  - DC girişin belirlediği çalışma noktasıdır (ekrandan, 00:10:00). $I_C$–$V_{CE}$ çıkış karakteristiği üzerinde gösterilir; mavi eğriler her biri bir $I_B$ değerine aittir (slaytta $I_B = 0$ ile $80\,\mu\text{A}$ arası).
  - Kullanılamayan bölgeler: $I_C \approx 0$ olan kesim (cutoff) bölgesi, $V_{CE} \approx 0$ olan doyum (saturation) bölgesi ve $P = V_{CE} \cdot I_C$ çarpımının transistörün güç sınırını ($P_{C\max}$) aştığı bölge. Slayttaki eğride ayrıca $I_{C\max} = 25$ mA ve $V_{CE\max} = 20$ V sınırları görülür (ekrandan, 00:10:00). Q noktası bu sınırların içinde kalan beyaz bölgede seçilir.
- Üç çalışma durumu (ekrandan, 00:15:00)
  - Aktif (doğrusal) bölge: baz-emitör eklemi ileri, baz-kolektör eklemi ters kutuplu.
  - Kesim bölgesi: baz-emitör eklemi ters kutuplu ($V_{BE} < 0{,}7$ V).
  - Doyum bölgesi: baz-emitör ve baz-kolektör eklemlerinin ikisi de ileri kutuplu; en büyük akım akar.
- Sabit kutuplama (fixed bias)
  - Devre: $V_{CC}$, $R_B$ üzerinden bazı, $R_C$ üzerinden kolektörü besler; emitör doğrudan toprakta. AC giriş $C_1$ ile baza verilir, AC çıkış $C_2$ ile kolektörden alınır (ekrandan, 00:20:00). Kondansatörler DC bileşeni süzer; içeri ve dışarı yalnız AC işaret geçer.
  - Baz-emitör çevresi: $V_{CC} = I_B R_B + V_{BE}$, dolayısıyla $I_B = \dfrac{V_{CC} - V_{BE}}{R_B}$.
  - Kolektör-emitör çevresi: $V_{CC} = I_C R_C + V_{CE}$, yani $V_{CE} = V_{CC} - I_C R_C$, ayrıca $I_C = \beta I_B$ (ekrandan, 00:25:00).
- Yük hattı analizi (ekrandan, 00:30:00)
  - Doyum ucu: $V_{CE} = 0$ V, $I_{C\,sat} = V_{CC}/R_C$. Kesim ucu: $I_C = 0$ mA, $V_{CE\,cutoff} = V_{CC}$.
  - $V_{CE} = V_{CC} - I_C R_C$ denklemi $I_C$–$V_{CE}$ düzleminde bir doğrudur (yük hattı). Bu doğrunun $R_B$'nin belirlediği $I_{BQ}$ eğrisini kestiği nokta Q noktasıdır.
- Q noktasını etkileyen devre değerleri
  - $V_{CC}$ büyüdükçe iki uç da dışarı kayar, Q noktası sağa gider; küçüldükçe sola kayar.
  - $R_C$ küçüldükçe $V_{CC}/R_C$ ucu yukarı çıkar, yük hattı dikleşir. $R_3 > R_2 > R_1$ için en dik hat $R_1$'e aittir (ekrandan, 00:35:00). $R_C$ büyüdükçe Q noktası sola kayar.
  - $I_B$ arttıkça Q noktası aynı yük hattı üzerinde yukarı kayar.
- Emitörle kararlı kılınmış (emitter-stabilized) kutuplama
  - Sabit kutuplamadan farkı emitör ile toprak arasına $R_E$ eklenmesidir.
  - Baz-emitör çevresi: $V_{CC} = I_B R_B + V_{BE} + I_E R_E$ ve $I_E = (\beta + 1) I_B$ kullanılarak $I_B = \dfrac{V_{CC} - V_{BE}}{R_B + (\beta + 1) R_E}$ (ekrandan, 00:40:00).
  - Kolektör-emitör çevresi: $V_{CC} = I_C R_C + V_{CE} + I_E R_E$; $I_E \approx I_C$ ile $V_{CE} = V_{CC} - I_C (R_C + R_E)$.
  - Düğüm gerilimleri toprağa göredir: $V_E = I_E R_E$, $V_C = V_{CC} - I_C R_C$, $V_B = V_{BE} + V_E$.
  - Yük hattı uçları: $V_{CE\,cutoff} = V_{CC}$ ($I_C = 0$), $I_{C\,sat} = \dfrac{V_{CC}}{R_C + R_E}$ ($V_{CE} = 0$) (ekrandan, 00:45:00).
- Gerilim bölücü
  - İki seri dirençte (yük yokken) $I_{R1} = I_{R2}$ olduğundan $\dfrac{V_{in} - V_{out}}{R_1} = \dfrac{V_{out}}{R_2}$ ve buradan $\dfrac{V_{out}}{V_{in}} = \dfrac{R_2}{R_1 + R_2}$ (ekrandan, 00:55:00).
  - Hocanın örneği: $V_{in} = 10$ V, $R_1 = 3\,\Omega$, $R_2 = 7\,\Omega$ ise $V_{out} = 7$ V; iki direnç 5'er ohm ise 5 V; $R_2 = 1$, $R_1 = 9$ ise 1 V.
- Gerilim bölücülü kutuplama (yaklaşık analiz) (ekrandan, 01:05:00)
  - $I_B \ll I_1$ ve $I_1 \cong I_2$ ise baz gerilimi $V_B = \dfrac{R_2 V_{CC}}{R_1 + R_2}$.
  - $\beta R_E > 10 R_2$ koşulu sağlanıyorsa $V_E = V_B - V_{BE}$ ve $I_E = V_E / R_E$.
  - $V_{CE} = V_{CC} - I_C R_C - I_E R_E$, $I_E \cong I_C$ ile $V_{CE} = V_{CC} - I_C (R_C + R_E)$. Yük hattı uçları emitör kararlı devredekiyle aynıdır: $V_{CC}$ ve $V_{CC}/(R_C + R_E)$.
- Gerilim geri beslemeli (kolektör geri beslemeli) kutuplama
  - $R_B$, $V_{CC}$'ye değil kolektöre bağlanır. $R_C$'den geçen akım $I'_C = I_C + I_B \approx I_C$.
  - Baz çevresi: $V_{CC} = I'_C R_C + I_B R_B + V_{BE} + I_E R_E$; $I'_C \approx I_C \approx I_E = \beta I_B$ ile $I_B = \dfrac{V_{CC} - V_{BE}}{R_B + \beta (R_C + R_E)}$. <!-- BELİRSİZ: bu slaytın karesi yok; IB ifadesi hocanın kurduğu çevre denkleminden türetildi. -->
  - Kolektör çevresi: $V_{CE} = V_{CC} - I_C (R_C + R_E)$.
- Transistörün anahtar olarak kullanılması (ekrandan, 01:10:00)
  - Slayt devresi: $V_{CC} = 5$ V, $R_C = 0{,}82$ k$\Omega$, $R_B = 68$ k$\Omega$, $h_{FE} = 125$; giriş 0 V ile 5 V arasında kare dalga.
  - Giriş 5 V iken baz akımı akar, transistör doyuma gider, $V_{CE} \approx 0$ ve çıkış $V_C \approx 0$ V olur. Giriş 0 V iken $I_B = 0$, $I_C = 0$, $R_C$ üzerinde gerilim düşmez ve çıkış $V_C = V_{CC} = 5$ V olur. Devre bir evirici (NOT kapısı) gibi çalışır.
  - Transistörlerle kurulan mantık kapılarından RAM, ROM ve mikroişlemciler yapılır.
  - Gerçek anahtarlama anlık değildir: açılma süresi $t_{on} = t_r + t_d$ (gecikme + yükselme, %90 seviyesine kadar), kapanma süresi $t_{off} = t_s + t_f$ (gecikme + düşme, %10 seviyesine kadar).
  - pnp devreler npn'in tersi kutuplarla çalışır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kutuplamanın amacı
  - DC kutuplama transistörü "çalışır" konuma getirir; AC işaret ancak bu çalışma noktasının çevresinde salınabilir ve kuvvetlendirilebilir.
- Çevre denklemini yazma yöntemi
  - Hoca Kirchhoff çevre denklemini sıfıra eşitlemek yerine, $V_{CC}$ düğümünden toprağa giden her kolun gerilimini $V_{CC}$'ye eşitlemeyi tercih ediyor: akım yönünde geçilen direnç için $+IR$, artı ucundan girilen gerilim için $+V$. İki yöntem aynı sonucu verir.
- Yük hattının iki ucu
  - Doyumda $V_{CE} = 0$ alınıp $I_C$ çekilir, kesimde $I_C = 0$ alınıp $V_{CE} = V_{CC}$ bulunur. Bu iki nokta yük hattını, $I_B$ de Q noktasını belirler.
- Emitör direncinin etkisi
  - Emitör bacağına eklenen direnç, akım ve gerilimlerin geniş bir sıcaklık ve $\beta$ aralığında yaklaşık sabit kalmasını sağlar; yani transistörün kararlılığını (stability) artırır.
- Gerilim bölücünün mantığı
  - Elinizde 10 V'luk pil varken 7 V gerekiyorsa iki dirençle bu gerilim elde edilir; direnç oranı $V_{in}$'in ne kadarının çıkışa aktarılacağını belirler.
- Osiloskop modu
  - Simülasyon ödevlerinde osiloskop kanalları AC değil DC modunda kullanılmalıdır; DC kaymalarının da görülmesi gerekir.

## Kısa Tekrar Notları

- Kutuplama = AC yükseltme için transistörü DC ile çalışma noktasına getirmek.
- Aktif bölge: BE ileri, BC ters. Kesim: BE ters. Doyum: BE ve BC ileri.
- Sabit kutuplama: $I_B = (V_{CC} - V_{BE})/R_B$, $I_C = \beta I_B$, $V_{CE} = V_{CC} - I_C R_C$.
- Yük hattı (sabit): $I_{C\,sat} = V_{CC}/R_C$, $V_{CE\,cutoff} = V_{CC}$.
- Emitör kararlı: $I_B = (V_{CC} - V_{BE})/(R_B + (\beta+1)R_E)$, $V_{CE} = V_{CC} - I_C(R_C + R_E)$, $I_{C\,sat} = V_{CC}/(R_C + R_E)$.
- $I_E = (\beta + 1) I_B$; $I_E \approx I_C$.
- Gerilim bölücü: $V_{out} = V_{in} \cdot R_2/(R_1 + R_2)$.
- Gerilim bölücülü kutuplama: $V_B = R_2 V_{CC}/(R_1+R_2)$, $V_E = V_B - V_{BE}$, $I_E = V_E/R_E$ (koşul $\beta R_E > 10 R_2$).
- Gerilim geri beslemeli: $I_B = (V_{CC} - V_{BE})/(R_B + \beta(R_C + R_E))$.
- $V_{CC}$ artarsa Q sağa, $R_C$ azalırsa yük hattı dikleşir, $I_B$ artarsa Q yukarı kayar.
- Transistör anahtar: giriş yüksek → doyum → çıkış 0; giriş düşük → kesim → çıkış $V_{CC}$ (evirici).
- $t_{on} = t_d + t_r$, $t_{off} = t_s + t_f$.

## Detaylı Açıklamalar

- **Neden kutuplama?** Transistör, baz-emitör eklemi yaklaşık 0,7 V'u geçmeden akım akıtmaz. Küçük bir AC işaret doğrudan baza verilirse bu eşiğin altında kalan kısımlar kaybolur. Bu yüzden önce DC kaynaklarla transistör aktif bölgede bir noktaya, Q noktasına oturtulur; AC işaret bu noktanın çevresinde salınır. Giriş ve çıkıştaki kuplaj kondansatörleri DC'yi geçirmez: kaynaktan gelen işaretin DC kısmı süzülür, yalnız AC kısmı baza ulaşır; kolektördeki DC seviye de çıkışa aktarılmaz.

- **Q noktasının yeri.** Çıkış karakteristiğinde yatay eksen $V_{CE}$, dikey eksen $I_C$'dir. Sıfır çevresindeki bölgeler kullanılmaz: $I_C$'nin neredeyse sıfır olduğu alt şerit kesim, $V_{CE}$'nin sıfıra yakın olduğu sol şerit doyum bölgesidir. Transistörün harcadığı güç, bir dirençteki $P = V \cdot I$ gibi $P = V_{CE} I_C$'dir ve katalog değerinin (örneğin 30 W) altında kalmalıdır; bu sınır grafikte bir hiperbol çizer. Q noktası bunların içinde kalan bölgede seçilir.

- **Sabit kutuplamanın çözümü.** Baz kolunda $V_{CC}$, $R_B$ ve $V_{BE}$ seri gibidir; kolektör tarafından baza akım gelmiyormuş gibi düşünülür. $V_{CC} = I_B R_B + V_{BE}$ ile $I_B$ bulunur. Sonra $I_C = \beta I_B$ ve kolektör kolundan $V_{CE} = V_{CC} - I_C R_C$ hesaplanır. Bu son denklem $y = I_C$, $x = V_{CE}$ alınırsa birinci dereceden bir doğrudur; $V_{CE} = 0$ ile $I_C = V_{CC}/R_C$ (doyum), $I_C = 0$ ile $V_{CE} = V_{CC}$ (kesim) uçları bulunur. Bu yük hattının, $I_B$ ile seçilen karakteristik eğriyle kesiştiği nokta Q noktasıdır.

- **Emitör direnci ve kararlılık.** $R_E$ eklenince baz çevresine $I_E R_E$ gerilimi girer. $I_E = I_C + I_B = \beta I_B + I_B = (\beta + 1) I_B$ yazılarak tek bilinmeyen $I_B$ kalır ve $I_B = (V_{CC} - V_{BE})/(R_B + (\beta+1) R_E)$ bulunur. $R_E$, payda üzerinden $\beta + 1$ katıyla etkili olur. Hocanın anlatımıyla bu direnç, sıcaklık ya da $\beta$ değişse de akımların yaklaşık sabit kalmasını sağlar. Kolektör tarafında $V_{CE} = V_{CC} - I_C(R_C + R_E)$ olduğundan doyum akımı $V_{CC}/(R_C + R_E)$'ye düşer.

- **Gerilim bölücü ve kutuplama.** Seri $R_1$ ve $R_2$'de çıkış ucundan akım çekilmezse iki dirençten aynı akım geçer: $(V_{in} - V_{out})/R_1 = V_{out}/R_2$. Düzenlenince $V_{in}/R_1 = V_{out}(R_1 + R_2)/(R_1 R_2)$ ve $V_{out}/V_{in} = R_2/(R_1 + R_2)$ olur. Kutuplama devresinde baz, bu bölücünün orta noktasına bağlanır. Baz akımı $I_1$ ve $I_2$'ye göre çok küçükse yok sayılır ve $V_B = R_2 V_{CC}/(R_1 + R_2)$ alınır; bu yaklaşım $\beta R_E > 10 R_2$ iken geçerlidir. Sonra $V_E = V_B - V_{BE}$, $I_E = V_E/R_E \approx I_C$ ve $V_{CE} = V_{CC} - I_C(R_C + R_E)$ hesaplanır.

- **Anahtarlama.** Slayttaki devrede giriş 5 V iken baz akımı transistörü doyuma sokar ve kolektör toprağa kısa devre gibi davranır, çıkış 0 V olur. Giriş 0 V iken transistör kesimdedir, $R_C$'den akım geçmez, çıkış $V_{CC}$'dir. Girişi tersine çeviren bu yapı bir NOT kapısıdır. Gerçekte çıkış anında değişmez; belli bir gecikme ve eğimle yükselip düşer, hızlı devrelerde bu süreler kısalır.

<!-- BELİRSİZ: Hoca derste "beş yapı" göstereceğini söyledi; altyazıda sabit kutuplama, emitör kararlı, kolektör-emitör çevresi, gerilim bölücü ve gerilim geri beslemeli adları geçiyor, listenin tamamı net değil. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
