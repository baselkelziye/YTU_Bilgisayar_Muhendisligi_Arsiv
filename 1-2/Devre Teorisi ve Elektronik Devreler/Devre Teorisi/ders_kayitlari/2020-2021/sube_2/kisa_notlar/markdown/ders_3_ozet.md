# Ders 3 Çalışma Özeti

> Kayıt üç parçadır; arşivde parçalar yanlış sırada birleştirildiği için altyazıdaki sıra düzeltildi ve saat damgaları düzeltilmiş altyazıya göredir.

## Genel Konular

- Önceki dersin tekrarı: Ohm yasası, güç ve işaret kuralı
  - $V = IR$, $P = IV = I^2R = V^2/R$.
  - Akım bir elemana artı (+) uçtan giriyorsa eleman güç soğurur, güç $+P$ yazılır; eksi (−) uçtan giriyorsa eleman güç üretir, güç $-P$ yazılır.
  - Bir devredeki bütün elemanların soğurduğu güçlerin toplamı sıfırdır: $\sum p_{\text{soğurulan}} = 0$, yani $\sum p_{\text{soğurulan}} = \sum p_{\text{üretilen}}$ (enerjinin korunumu).
- Tek çevreli devre ve KVL (Kirchhoff Gerilim Yasası)
  - Analiz adımları (ekrandan, 00:11:29): bilinmeyen akım için bir referans yön seç, her direnç için gerilim referansını seç, tek kapalı yola KVL uygula.
  - Örnek denklem: $-v_{s1} + R_1 i + v_{s2} + R_2 i = 0 \Rightarrow i = \dfrac{v_{s1}-v_{s2}}{R_1+R_2}$ (ekrandan, 00:11:29).
- Bağımlı kaynak içeren devrelerde güç hesabı
  - Gerilim kontrollü bağımlı gerilim kaynağı (eşkenar dörtgen içinde + −) ve gerilim kontrollü bağımlı akım kaynağı (içinde ok) ayrımı.
  - Bağımlı kaynağın üreten mi tüketen mi olduğu ancak kontrol değişkeni ($v_A$, $v_x$ gibi) hesaplandıktan sonra anlaşılır.
- Tek düğüm çiftli devre ve KCL (Kirchhoff Akım Yasası)
  - Paralel kollarda gerilim her yerde aynıdır; bütün kol akımları bu ortak $v$ cinsinden yazılarak tek bilinmeyene inilir.
  - Arada eleman olmayan iletkenle birleşen noktalar aynı düğümdür.
- Seri ve paralel bağlantı
  - Seri: aynı akımı taşıyan, aralarında dallanma olmayan elemanlar.
  - Paralel: başlangıç ve bitiş düğümleri aynı olan elemanlar; eleman grupları da birbirine seri ya da paralel olabilir.
  - Kısa devre ile köprülenen direnç devreden düşer.
- Kaynakların seri ve paralel bağlanması
  - Seri gerilim kaynakları kutuplarına göre toplanır ya da çıkarılır.
  - İdeal gerilim kaynakları ancak eşitse paralel bağlanabilir; gerçekte iç direnç ve küçük farklar yüzünden paralel bağlanmaz.
  - Paralel akım kaynakları yönlerine göre (KCL) toplanır ya da çıkarılır.
- Dirençlerin seri ve paralel bağlanması, iletkenlik
  - Seri: $R_{\text{eş}} = R_1 + R_2 + \dots$; paralel: $1/R_{\text{eş}} = 1/R_1 + 1/R_2 + \dots$
  - İletkenlik $G = 1/R$: paralelde $G_{\text{eş}} = G_1 + G_2$, seride tersleri toplanır.
  - Seri devrede büyük direnç daha çok güç soğurur; paralel devrede büyük direnç daha az güç soğurur.
- Gerilim bölücü ve akım bölücü
  - Gerilim bölücü: $V_n = \dfrac{R_n}{R_1 + \dots + R_N}\,V_{toplam}$ (ekrandan, 02:21:29).
  - Akım bölücü (iki kol): $I_1 = I\,\dfrac{R_2}{R_1+R_2}$, $I_2 = I\,\dfrac{R_1}{R_1+R_2}$.
- Ölçüm kuralları
  - Voltmetre ölçülen elemana paralel, ampermetre devre koparılarak seri bağlanır; ters bağlanan ölçü aleti eksi değer gösterir.
  - Direnç değeri devrede güç varken ölçülmez, eleman devreden ayrılarak ölçülür.
- Laboratuvar tanıtım oturumu (kayıtta ayrı oturum)
  - Proteus ve Multisim ile seri devre, Kirchhoff devresi, diyotlu devre ve osiloskop ölçümleri gösterildi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Akım yönü varsayımı ve işaretler
  - Akım için seçilen yön keyfidir. Sonuç eksi çıkarsa gerçek akım ters yöndedir; ya yönü çevirip pozitif değerle ya da yönü koruyup eksi değerle devam edilir, ikisi aynı sonucu verir.
  - KVL'de terimin işareti elemanın kutbuna göre, terimin içindeki değer ise o gerilimi oluşturan akımın yönüne göre yazılır (örneğin $v_x = -30i$).
- Güç toplamı kontrolü
  - Her çözümün sonunda bütün güçlerin toplamının sıfır olup olmadığına bakılmalı; sıfır çıkmıyorsa bir işaret ya da yön hatası vardır.
- Gerilim kaynağının gücü
  - Gerilim kaynağının direnci yoktur. Gücü $I^2R$ ile değil yalnız $P = IV$ ile bulunur ve kaynak devreye göre üreten ya da tüketen olabilir. Direnç ise her zaman güç soğurur.
- Bağımlı kaynakların dış görünüşü yanıltıcıdır
  - Kutuplara bakınca tüketen gibi görünen bağımlı kaynak, kontrol gerilimi eksi çıkınca üretici olabilir (Örnek 1'de $p_{dep} = -1920$ W).
- Paralel eşdeğer direnç
  - Paralel eşdeğer direnç kollardaki en küçük dirençten her zaman küçüktür. Elde olmayan değer paralel bağlamayla elde edilir (iki 10 kΩ → 5 kΩ).
- Ölçme
  - Gerilim paralel, akım seri ölçülür. Akım ölçmek için kol koparılıp ölçü aleti araya girilir.

## Kısa Tekrar Notları

- $P = IV = I^2R = V^2/R$; akım + uçtan giriyorsa $+P$ (soğurma), − uçtan giriyorsa $-P$ (üretim).
- $\sum p = 0$ her devrede sağlanmalı.
- KVL: kapalı yolda gerilimlerin işaretli toplamı sıfır. KCL: düğüme giren akımlar çıkanlara eşit.
- Seri elemanlar aynı akımı, paralel elemanlar aynı gerilimi taşır.
- Örnek 1: $i = 8$ A, $v_A = -120$ V; güçler $-960$, $1920$, $-1920$, $960$ W.
- Örnek 2: $i = -4/25$ A, $v_x = 24/5$ V; bağımlı kaynak $-3{,}072$ W üretir.
- Örnek 3: $v = 2$ V, $i_1 = 60$ A, $i_2 = 30$ A, $P_{R1} = 120$ W.
- Örnek 4: $v = 14{,}4$ V; 24 mA kaynağının soğurduğu güç $\approx -345{,}6$ mW.
- Örnek 5: $v_x = 54$ V; $i_A = 3$ A, $i_B = -5{,}4$ A, $i_C = 6$ A.
- Seri: $R_{\text{eş}} = \sum R$; paralel: $1/R_{\text{eş}} = \sum 1/R$; paralelde $G_{\text{eş}} = \sum G$.
- Gerilim bölücü: $V_n = V\,R_n/R_{\text{eş}}$. Akım bölücü: $I_1 = I\,R_2/(R_1+R_2)$.
- Kısa yol: iki paralel direnç arasında $k$ kat fark varsa $R_{\text{eş}} = R_{\text{büyük}}/(k+1)$.

## Detaylı Açıklamalar

- **Güç ve işaret kuralı.** Pasif işaret kuralına göre akım elemanın + ucundan giriyorsa $p = +vi$ soğurulan güçtür. Akım − ucundan giriyorsa eleman güç üretir ve soğurulan güç eksidir. Ekrandaki örnekte (ekrandan, 00:16:29) 7 A–8 V elemanı $-56$ W, 2 A–8 V elemanı $16$ W, 5 A–12 V elemanı $-60$ W, 8 A–20 V elemanı $160$ W, 3 A–20 V bağımlı kaynak $-60$ W'tır. Toplam sıfırdır: 176 W üretilir, 176 W tüketilir. Hoca bilinmeyen kol akımlarının KCL ile de bulunabileceğini gösterdi: 7 A girip 2 A aşağı gidiyorsa yatay koldan 5 A devam eder; 5 A ve 3 A birleşince aşağı 8 A iner.
- **Örnek 1, bağımlı gerilim kaynaklı tek çevre (ekrandan, 00:26:29).** 120 V kaynak, 30 Ω, $2v_A$ bağımlı kaynak ve 15 Ω seri bağlıdır. $v_A$ 15 Ω üzerinde, + ucu altta olacak şekilde tanımlanmıştır. KVL: $-120 + v_{30} + 2v_A - v_A = 0$, $v_{30} = 30i$, $v_A = -15i$. Buradan $-120 + 30i - 30i + 15i = 0$ ve $i = 8$ A çıkar. Güçler: $p_{120V} = 120(-8) = -960$ W, $p_{30\Omega} = 8^2 \cdot 30 = 1920$ W, $p_{dep} = 2v_A \cdot 8 = 2(-120)(8) = -1920$ W, $p_{15\Omega} = 8^2 \cdot 15 = 960$ W. Toplam sıfırdır (python ile doğrulandı). Bağımlı kaynak kutuplarına göre tüketen gibi görünse de $v_A$ eksi çıktığı için güç üretir.
- **Örnek 2, beş elemanlı çevre (ekrandan, 00:46:29 ve 00:56:29).** Elemanlar 30 Ω (üzerinde $v_x$, + ucu üstte), 12 V kaynak (sol ucu −), 8 Ω, 7 Ω ve $4v_x$ bağımlı kaynaktır. Akım saat yönünde (30 Ω'da yukarı) alınınca $v_x = -30i$ olur. KVL: $-v_x - 12 + 15i + 4v_x = 0 \Rightarrow 15i - 12 + 3v_x = 0 \Rightarrow -75i = 12$, yani $i = -4/25$ A. Buradan $v_x = 24/5 = 4{,}8$ V bulunur. Soğurulan güçler: 30 Ω için $0{,}768$ W, 12 V kaynağı için $(-12)(-4/25) = 1{,}92$ W (tüketir), 8 Ω için $0{,}2048$ W, 7 Ω için $0{,}1792$ W, bağımlı kaynak için $4v_x \cdot i = 19{,}2 \cdot (-0{,}16) = -3{,}072$ W (üretir). Toplam sıfırdır (python ile doğrulandı). Hoca derste yalnız 30 Ω, 12 V ve bağımlı kaynağın işaretini tartıştı. Sayısal güçler derste tek tek hesaplanmadı; burada eklendi.
- **Örnek 3, tek düğüm çifti (ekrandan, 01:06:29).** 120 A kaynak, $R_1 = 1/30$ Ω, 30 A kaynak (aşağı) ve $R_2 = 1/15$ Ω paraleldir. KCL: $-120 + i_1 + 30 + i_2 = 0$, $i_1 = 30v$, $i_2 = 15v$, buradan $45v = 90$ ve $v = 2$ V çıkar. $i_1 = 60$ A, $i_2 = 30$ A, $P_{R1} = 120$ W, $P_{R2} = 60$ W, 120 A kaynağı $-240$ W (üretir), 30 A kaynağı $+60$ W (soğurur). Hoca derste $i_1$ ve $P_{R1} = 120$ W değerini söyledi; diğer güçler python ile hesaplandı.
- **Örnek 4, bağımlı akım kaynaklı paralel devre (ekrandan, 01:31:29).** Üst düğüm için KCL (çıkanlar +, girenler −): $i_6 - 2i_x - 24\,\text{mA} - i_x = 0$. Ortak gerilim $v$ ile $i_6 = v/6000$ ve $i_x = -v/2000$ olur. $i_x$'in eksi işaretli olmasının nedeni, şekildeki $i_x$ yönünün 2 kΩ üzerindeki $v$ polaritesine göre ters olmasıdır. Çözüm $v = 14{,}4$ V'tur. 24 mA kaynağında akım + uçtan çıktığı için soğurulan güç $-14{,}4 \times 0{,}024 \approx -0{,}3456$ W'tır; kaynak güç üretir.
- **Örnek 5 (ekrandan, 01:36:29).** 5,6 A kaynak, 18 Ω, $0{,}1v_x$ bağımlı akım kaynağı (yukarı), 9 Ω ve 2 A kaynak (aşağı) paraleldir. $i_B$ aşağı tanımlandığı için $i_B = -0{,}1v_x$ olur. KCL: $5{,}6 - v_x/18 + 0{,}1v_x - v_x/9 - 2 = 0$, buradan $v_x = 54$ V çıkar. $i_A = 3$ A, $i_B = -5{,}4$ A, $i_C = 6$ A bulunur. Kontrol: $3 - 5{,}4 + 6 + 2 = 5{,}6$ A.
- **Seri ve paralel tanıma.** Seri elemanlar aynı akımı taşır ve aralarında başka kola giden düğüm yoktur. Paralel elemanların iki ucu da aynı düğümlere bağlıdır. Karmaşık devrede elemanlar "kara kutu" bileşenlerle gruplanarak sadeleştirilir. Örnek 7'de (ekrandan, 01:46:29) üstteki iletkenle kısa devre edilen 2 Ω devreden düşer. 2 A kaynakla 1,5 Ω seri, 5 Ω ile 5 A kaynak seridir, kalan kollar paralel olur.
- **Kaynak bağlantıları.** Seri piller kutuplar sıralı ise toplanır. Hoca lise fiziğinden örnek verdi: seri pillerle lamba daha parlak ama daha kısa süre, paralel pillerle aynı parlaklıkta daha uzun süre yanar (teoride). Eşit olmayan gerilim kaynakları paralel bağlanırsa büyükten küçüğe akım akar ve tehlikelidir (ekrandan, 01:51:29).
- **Seri devre sayısal örneği.** Kaynaklar kutuplarına göre birleştirilince eşdeğer 90 V olur. Toplam direnç 30 Ω olduğu için $I = 3$ A bulunur. 80 V kaynağı $-240$ W üretir; ters yönde bağlı 20 V kaynağı ise $60$ W soğurur. <!-- BELİRSİZ: bu örneğin karesi yok; direnç değerleri ve 30 V kaynağın konumu altyazıdan net değil. -->
- **Paralel dirençler ve güç.** İki 10 Ω paralel dirence 10 A verilince $R_{\text{eş}} = 5$ Ω ve $V = 50$ V olur. Akım yönü ters olsaydı $-50$ V yazılırdı. Paralel kollarda gerilim aynı olduğu için büyük direnç daha az akım çeker ve daha az güç soğurur. Seri devrede ise akım aynıdır ve büyük direnç daha çok güç soğurur (ekrandan, 01:56:29).
- **Gerilim bölücü.** Seri iki dirençte $V_1 = V\,R_1/(R_1+R_2)$ olur. Örnek: 9 V, 3 Ω ve 6 Ω için $V_1 = 3$ V, $V_2 = 6$ V. Örnek 03'te (ekrandan, 02:26:29) 6 Ω ile 3 Ω paraleldir ve eşdeğeri 2 Ω'dur; 4 Ω ile seri olunca $v_x = 12\sin t \cdot 2/6 = 4\sin t$ V çıkar.
- **Akım bölücü ve kısa yol.** İki paralel kolda akım ters orantılı bölünür. Hoca bir kısa yol verdi: büyük direnç küçüğün $k$ katıysa $R_{\text{eş}} = R_{\text{büyük}}/(k+1)$ olur. Örnekler: 400 Ω ∥ 100 Ω = 80 Ω, 12 Ω ∥ 4 Ω = 3 Ω, 20 Ω ∥ 5 Ω = 4 Ω.
- **Örnek 05, DC ve AC kaynaklı bölücü (ekrandan, 02:36:29).** 1 V DC ve $0{,}5\sin(20t)$ V kaynak seri bağlıdır. Yük olarak 200 Ω ($R_1$) ve $R_2 = 400$ Ω ∥ $R_3 = 100$ Ω = 80 Ω seridir. $V_1 = (1 + 0{,}5\sin 20t)\cdot 200/280$, $V_p = (1 + 0{,}5\sin 20t)\cdot 80/280$ olur. Kol akımları $I_1$'in $100/500$ ve $400/500$ oranlarıyla bulunur. DC ve AC bileşen tek sayı olarak toplanamaz; ifade toplam biçiminde taşınır.
- **Laboratuvar tanıtımı.** Proteus'ta 80 V kaynağa seri bağlı 5, 10, 20 ve 5 Ω dirençlerin voltmetre ölçümü gösterildi: ekranda yaklaşık 9,98, 20,0, 39,9 ve 9,98 V okunuyor (ekrandan, 03:05:09). Hesapla $I = 80/40 = 2$ A ve gerilimler 10, 20, 40, 10 V'tur; küçük farklar ölçü aletinin iç direncinden gelir. Diyotlu devrede (1N4001, 1 kΩ, sinüs kaynak) osiloskop girişte tam sinüs, dirençte yalnız pozitif yarım dalgaları gösterdi (ekrandan, 03:15:09). Multisim'de 1 kΩ ve 100 nF'lık RC devresinde direnç ve kondansatör gerilimleri arasında faz farkı görüldü.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
