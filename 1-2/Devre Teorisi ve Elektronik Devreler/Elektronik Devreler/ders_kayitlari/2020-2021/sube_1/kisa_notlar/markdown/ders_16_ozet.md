# Ders 16 Çalışma Özeti

## Genel Konular

- Dersin amacı: soru çözümü
  - Bu derste yeni konu anlatılmadı. Diyot, zener diyot ve BJT DC öngerilim (bias) devreleri üzerine Boylestad & Nashelsky kitabındaki örnekler çözüldü (ekrandaki dosya: ElkDev_Sorular1.pdf).
- Diyot modellerinin tekrarı
  - İdeal diyot: sıfırın biraz üzerinde iletime geçer, akımı devre ne kadar izin veriyorsa o kadar akıtır.
  - Eşik gerilimli model: silisyumda $V_T \approx 0{,}7$ V, germanyumda $V_T \approx 0{,}3$ V. Gerçek karakteristikte bunlara bir de iç direnç eklenir.
  - Diyot iletimdeyken üzerindeki gerilim sabit kalır; akımı diyot değil, devredeki dirençler belirler. Örnek: 10 V kaynak ve 1 kΩ dirençte $I = 9{,}3\text{ V}/1\text{ k}\Omega = 9{,}3$ mA (ekrandan, 00:10:00).
- Seri diyot devreleri
  - $E = 8$ V, $R = 2{,}2$ kΩ, Si diyot: $V_D = 0{,}7$ V, $V_R = 7{,}3$ V, $I_D = I_R = 7{,}3/2{,}2\text{ k}\Omega \approx 3{,}32$ mA (ekrandan, 00:15:00).
  - Örnek 2.9: +12 V noktasından Si ve Ge diyot üzerinden 5,6 kΩ'a: $V_o = 12 - 0{,}7 - 0{,}3 = 11$ V, $I_D = 11/5{,}6\text{ k}\Omega \cong 1{,}96$ mA (ekrandan, 00:15:00).
  - Noktasal gerilim gösterimi: "+12 V" yazan nokta, toprağa göre 12 V olan bir kaynağın kısa çizimidir.
  - Örnek 2.11: $E_1 = 10$ V, $E_2 = -5$ V; uçlar arası gerilim $10 - (-5) = 15$ V; $I = 14{,}3/6{,}9\text{ k}\Omega \approx 2{,}07$ mA (ekrandan, 00:20:00).
- Paralel-seri diyot devresi (Örnek 2.15)
  - 20 V kaynak, iki Si diyot iletimde: $I_1 = 0{,}7/3{,}3\text{ k}\Omega = 0{,}212$ mA, $V_2 = 20 - 0{,}7 - 0{,}7 = 18{,}6$ V, $I_2 = 18{,}6/5{,}6\text{ k}\Omega = 3{,}32$ mA, $I_{D_2} = I_2 - I_1 \approx 3{,}11$ mA (ekrandan, 00:25:00).
- Doğrultucu ve kırpıcı soruları
  - Örnek 2.18: ters bağlı diyotlu yarım dalga doğrultucu, $V_m = 20$ V. İdeal: $V_{dc} = -0{,}318 V_m = -6{,}36$ V; Si diyot: $-0{,}318(20 - 0{,}7) \approx -6{,}14$ V; $V_m = 200$ V için fark önemsizleşir (ekrandan, 00:30:00).
  - Örnek 2.19: dört dirençli köprü (iki diyot, üç 2 kΩ direnç). Her yarım periyotta çıkış direnci girişin yarısını alır: $V_{o,max} = 5$ V, tam dalga, $V_{dc} = 0{,}636 \cdot 5 = 3{,}18$ V (ekrandan, 00:35:00 ve 00:40:00).
  - Seri 5 V kaynaklı kırpıcı: $v_i > -5$ V iken diyot iletir ve $v_o = v_i + 5$; $v_i < -5$ V iken diyot kesimde, $v_o = 0$ (ekrandan, 00:45:00).
- Zener diyot soruları
  - Zener ters bağlanır. Uçlarındaki gerilim $V_Z$'nin altındaysa açık devredir (off); $V_Z$'yi aşmaya zorlanınca iletir (on), uçlarında $V_Z$'yi tutar ve fazla akımı çeker.
  - Örnek 2.26 (16 V, $R = 1$ kΩ, $V_Z = 10$ V, $P_{ZM} = 30$ mW): $R_L = 1{,}2$ kΩ'da zener kapalı ($V = 8{,}73$ V); $R_L = 3$ kΩ'da zener açık, $V_L = 10$ V, $I_Z = 2{,}67$ mA, $P_Z = 26{,}7$ mW (ekrandan, 01:00:00 ve 01:15:00).
  - Örnek 2.27 (50 V, $R = 1$ kΩ, $V_Z = 10$ V, $I_{ZM} = 32$ mA): $R_{L,min} = 250\ \Omega$, $I_R = 40$ mA, $I_{L,min} = 8$ mA, $R_{L,max} = 1{,}25$ kΩ, $P_{Z,max} = 320$ mW (ekrandan, 01:05:00 ve 01:10:00).
- BJT DC öngerilim soruları
  - Kuplaj kondansatörleri DC'yi geçirmez; DC analizde açık devre sayılır, yalnız AC bileşen geçer.
  - Sabit öngerilim (Örnek 4.1): $I_B = 47{,}08\ \mu$A, $I_C = 2{,}35$ mA, $V_{CE} = 6{,}83$ V, $V_{BC} = -6{,}13$ V (ekrandan, 01:20:00).
  - Emitter dirençli öngerilim (Örnek 4.4): $I_B = 40{,}1\ \mu$A, $I_C = 2{,}01$ mA, $V_{CE} = 13{,}97$ V, $V_B = 2{,}71$ V (ekrandan, 01:25:00 ve 01:30:00).
  - Gerilim bölücülü öngerilim: Thevenin eşdeğeri ile $R_{Th} = 3{,}55$ kΩ, $E_{Th} = 2$ V, $I_B = 6{,}05\ \mu$A, $I_C = 0{,}85$ mA, $V_{CE} \approx 12{,}2$ V (ekrandan, 01:35:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Diyot akımı devreden hesaplanır
  - Diyot yalnız akıma izin verir; ne kadar akım geçeceğini bilemez. Akım, iletimdeki diyot geriliminden sonra kalan gerilim ve dirençten bulunur.
- Uçlar arası gerilimi doğru bulmak
  - Devrede toprak görünmese de kaynaklar toprağa bağlıdır. A ve B noktalarının toprağa göre gerilimleri farkı alınır ($10 - (-5) = 15$ V).
- Pozitif ve negatif yarım periyodu ayrı düşünmek
  - Doğrultucu ve kırpıcı sorularında her zaman önce pozitif, sonra negatif yarım periyotta hangi diyotun iletimde olduğu bulunur ve devre yeniden çizilir.
- Büyük girişte diyot gerilimi önemsizleşir
  - 20 V tepe değerde ideal ve Si sonuçları arasında 0,22 V fark vardır; 200 V'ta bu fark ihmal edilebilir.
- Zener paralelindeki gerilimi sabit tutar
  - Zener iletimdeyken paralelindeki yüke hep $V_Z$'yi verir; fazla gerilim seri direnç üzerinde düşer. Bu bir çelişki değildir: zener olmasaydı A noktası 12 V olurdu, zener bunu 10 V'a sınırlar.
- Gerilim bölücülü yapıyı tanımak
  - Taban tarafındaki iki direnç görülünce gerilim bölücülü öngerilim hemen tanınmalı; sol taraf $E_{Th}$ ve seri $R_{Th}$ ile basitleştirilir. Bu yapıyla çok karşılaşılacak.

## Kısa Tekrar Notları

- Si: $V_T = 0{,}7$ V, Ge: $V_T = 0{,}3$ V.
- Seri devrede: $V_R = E - \sum V_T$, $I = V_R / R$.
- Yarım dalga: $V_{dc} = 0{,}318 V_m$; tam dalga: $V_{dc} = 0{,}636 V_m$. Si diyotta $V_m$ yerine $V_m - 0{,}7$.
- Eşit iki seri direnç gerilimi yarı yarıya, 1 kΩ ve 2 kΩ ise 1/3 ve 2/3 oranında paylaşır.
- Zener durumu: önce zeneri çıkarıp yük üzerindeki $V$ bulunur. $V < V_Z$ ise off, $V \ge V_Z$ ise on.
- Zener açıkken: $V_L = V_Z$, $I_R = (V_i - V_Z)/R$, $I_Z = I_R - I_L$, $P_Z = V_Z I_Z \le P_{ZM}$.
- $R_{L,min} = R V_Z / (V_i - V_Z)$; $I_{L,min} = I_R - I_{ZM}$; $R_{L,max} = V_Z / I_{L,min}$.
- Sabit öngerilim: $I_B = (V_{CC} - V_{BE})/R_B$, $I_C = \beta I_B$, $V_{CE} = V_{CC} - I_C R_C$.
- Emitter dirençli: $I_E = I_C + I_B = (\beta + 1) I_B$, $I_B = (V_{CC} - V_{BE})/(R_B + (\beta+1)R_E)$, $V_{CE} \approx V_{CC} - I_C(R_C + R_E)$.
- Gerilim bölücülü: $R_{Th} = R_1 \parallel R_2$, $E_{Th} = R_2 V_{CC}/(R_1 + R_2)$, $I_B = (E_{Th} - V_{BE})/(R_{Th} + (\beta+1)R_E)$.
- $V_{BC} < 0$ (npn) taban-kolektör ekleminin ters kutuplandığını, yani doğrusal yükseltme için istenen durumu gösterir.

## Detaylı Açıklamalar

- **Seri diyot devrelerinde yöntem.** Önce diyotun iletimde olup olmadığına bakılır: anot tarafı katottan yüksek potansiyeldeyse ve fark eşik gerilimini aşıyorsa diyot iletir. İletimdeki diyot yerine $V_T$ değerinde küçük bir kaynak konur. Kalan gerilim dirence düşer ve akım Ohm yasasından bulunur. 10 V ve Si diyotlu devrede direnç 1 kΩ ise akım 9,3 mA'dir; direnç değişirse diyot gerilimi değişmez ama akım değişir. Bu yüzden diyot için "kaç amper akar" sorusunun cevabı her zaman devrenin geri kalanındadır (ekrandan, 00:10:00).
- **Örnek 2.11 ve yuvarlama hatası.** $E_1 = 10$ V, $R_1 = 4{,}7$ kΩ, Si diyot, $R_2 = 2{,}2$ kΩ, $E_2 = -5$ V. KVL: $15 = 4{,}7\text{k} \cdot I + 0{,}7 + 2{,}2\text{k} \cdot I$, buradan $I = 14{,}3/6{,}9\text{ k}\Omega = 2{,}07$ mA. Hoca akımı 2 mA'e yuvarlayıp $V_1 = 9{,}4$ V, $V_2 = 4{,}4$ V buldu; kontrol için toplayınca $9{,}4 + 4{,}4 + 0{,}7 = 14{,}5$ V çıktı. Eksik 0,5 V yuvarlamadan gelir. Tam değerle $V_1 \approx 9{,}74$ V, $V_2 \approx 4{,}56$ V'tur ve toplam 15 V'u tamamlar (ekrandan, 00:20:00).
- **Örnek 2.15.** 20 V kaynak, seri Si diyot $D_1$, ardından birbirine paralel Si diyot $D_2$ ve 3,3 kΩ'luk $R_1$, dönüşte 5,6 kΩ'luk $R_2$. $D_2$ iletimde olduğu için $R_1$ uçlarında 0,7 V vardır: $I_1 = 0{,}212$ mA. Dış çevrede KVL: $V_2 = 20 - 0{,}7 - 0{,}7 = 18{,}6$ V, $I_2 = 3{,}32$ mA. Düğümde akım ikiye ayrılır: $I_{D_2} = 3{,}32 - 0{,}212 \approx 3{,}11$ mA (ekrandan, 00:25:00).
- **Örnek 2.18 (negatif yarım dalga doğrultucu).** Diyot ters yönde bağlı olduğu için pozitif yarım periyotta kesimde ($v_o = 0$), negatif yarım periyotta iletimde ($v_o = v_i$). Çıkış negatif yönde doğrultulmuş bir yarım dalgadır: $V_{dc} = -0{,}318(20) = -6{,}36$ V. Si diyotta diyot ancak giriş $-0{,}7$ V'un altına inince iletir, çıkış tepe değeri 19,3 V olur, çıkış $T/2$ noktasından biraz sonra başlar ve $V_{dc} \approx -6{,}14$ V olur. $V_m = 200$ V için iki sonuç ($-63{,}6$ V ve yaklaşık $-63{,}4$ V) birbirine çok yakındır (ekrandan, 00:30:00).
- **Örnek 2.19 (iki diyotlu köprü).** Pozitif yarım periyotta bir diyot kısa devre, diğeri açık devre olur. Devre yeniden çizilince çıkış direnci (2 kΩ) bir başka 2 kΩ ile seri bağlı ve ikisi girişe paralel kalır; giriş iki eşit dirençte paylaşılır, $v_o = v_i/2$. Negatif yarım periyotta diyotların rolü değişir, çıkış direnci girişe ters yönde bağlanır ve $v_o$ yine pozitif olur. Sonuç tam dalga doğrultmadır: tepe değer 5 V, $V_{dc} = 3{,}18$ V. Bir öğrencinin sorusuna cevap: genlik 10 V'tan 5 V'a düşse de doğrultma tam dalgadır; düşüşün nedeni gerilimin iki eşit dirençte paylaşılmasıdır (ekrandan, 00:40:00).
- **Seri kaynaklı kırpıcı.** Diyotla seri, artı ucu diyota bakan 5 V kaynak var; giriş tepe değeri 20 V. $v_i = 0$ iken bile diyot iletir, $v_o = 5$ V. Pozitif tepe değerde $v_o = 25$ V. Giriş negatife inerken diyot $v_i = -5$ V'a kadar iletimde kalır ($-1 + 5 = 4$ V, $-4{,}9 + 5$ hâlâ pozitif). $v_i$ $-5$ V'un altına inince diyot kesilir, $v_o = 0$. Bu yüzden çıkış $T/2$ noktasını biraz aşarak sıfıra iner ve giriş tekrar $-5$ V'u geçince yükselmeye başlar (ekrandan, 00:45:00).
- **Örnek 2.26 (zener, sabit yük).** 16 V, seri 1 kΩ, zener 10 V, $P_{ZM} = 30$ mW. (a) $R_L = 1{,}2$ kΩ: zener çıkarılınca A noktası $1{,}2/(1+1{,}2) \cdot 16 = 8{,}73$ V; 10 V'un altında olduğu için zener kapalıdır. $V_L = 8{,}73$ V, $V_R = 7{,}27$ V, $I_Z = 0$, $P_Z = 0$. (b) $R_L = 3$ kΩ: A noktası $3/4 \cdot 16 = 12$ V olmak isteyeceği için zener iletir ve 10 V'a sabitler. $V_R = 6$ V, $I_R = 6$ mA, $I_L = 10/3\text{ k}\Omega = 3{,}33$ mA, $I_Z = 2{,}67$ mA, $P_Z = 26{,}7$ mW. Bu değer 30 mW sınırının altında olduğu için zener güvenli çalışır (ekrandan, 01:00:00 ve 01:15:00).
- **Örnek 2.27 (zener, değişken yük).** 50 V, seri 1 kΩ, zener 10 V, $I_{ZM} = 32$ mA. Zenerin tam iletime geçtiği sınırda $I_Z = 0$ ve yük gerilimi 10 V'tur: $I_R = 40\text{ V}/1\text{ k}\Omega = 40$ mA'in hepsi yükten akar, $R_{L,min} = 10\text{ V}/40\text{ mA} = 250\ \Omega$. Zener en çok 32 mA çektiğinde yüke $40 - 32 = 8$ mA kalır: $R_{L,max} = 10\text{ V}/8\text{ mA} = 1{,}25$ kΩ. Yük akımı 8 mA ile 40 mA arasında, yük direnci 250 Ω ile 1,25 kΩ arasında olmalıdır. Zenerin en büyük gücü $10 \cdot 32\text{ mA} = 320$ mW'tır (ekrandan, 01:10:00).
- **BJT sabit öngerilim (Örnek 4.1).** $V_{CC} = 12$ V, $R_B = 240$ kΩ, $R_C = 2{,}2$ kΩ, $\beta = 50$. Taban çevresi: $I_B = (12 - 0{,}7)/240\text{ k}\Omega = 47{,}08\ \mu$A. $I_C = 50 \cdot 47{,}08\ \mu\text{A} = 2{,}35$ mA. Kolektör çevresi: $V_{CE} = 12 - 2{,}35 \cdot 2{,}2 = 6{,}83$ V. Emitter toprakta olduğu için $V_B = V_{BE} = 0{,}7$ V, $V_C = V_{CE} = 6{,}83$ V, $V_{BC} = 0{,}7 - 6{,}83 = -6{,}13$ V. Eksi işaret taban-kolektör ekleminin ters kutuplandığını gösterir (ekrandan, 01:20:00).
- **Emitter dirençli öngerilim (Örnek 4.4).** $V_{CC} = 20$ V, $R_B = 430$ kΩ, $R_C = 2$ kΩ, $R_E = 1$ kΩ, $\beta = 50$. $I_E = I_C + I_B = (\beta + 1)I_B$ yazılırsa taban çevresinden $I_B = 19{,}3/(430 + 51)\text{ k}\Omega = 40{,}1\ \mu$A. $I_C = 2{,}01$ mA. $I_E \approx I_C$ alınarak $V_{CE} = 20 - 2{,}01(2 + 1) = 13{,}97$ V. $V_C = 20 - 2{,}01 \cdot 2 = 15{,}98$ V, $V_E = 2{,}01$ V, $V_B = V_E + 0{,}7 = 2{,}71$ V. Burada $V_E$ artık sıfır değildir; $V_B$ hesabında bu unutulmamalıdır. $V_{BC} = 2{,}71 - 15{,}98 \approx -13{,}27$ V ile eklem yine ters kutupludur (ekrandan, 01:30:00).
- **Gerilim bölücülü öngerilim.** $V_{CC} = 22$ V, $R_1 = 39$ kΩ, $R_2 = 3{,}9$ kΩ, $R_C = 10$ kΩ, $R_E = 1{,}5$ kΩ, $\beta = 140$. Tabanın solundaki bölücü Thevenin eşdeğerine çevrilir: $E_{Th} = 3{,}9 \cdot 22/(39 + 3{,}9) = 2$ V, $R_{Th} = 39 \parallel 3{,}9 = 3{,}55$ kΩ. Sonra devre emitter dirençli devre gibi çözülür: $I_B = (2 - 0{,}7)/(3{,}55 + 141 \cdot 1{,}5)\text{ k}\Omega = 6{,}05\ \mu$A, $I_C = 0{,}85$ mA, $V_{CE} = 22 - 0{,}85(10 + 1{,}5) \approx 12{,}2$ V (ekrandan, 01:35:00). Ders sonunda bir öğrencinin sorusu üzerine önceki dersin slaytı açıldı: yaklaşık analizde $I_B \ll I_1$ ve $\beta R_E > 10 R_2$ koşullarında $V_B = R_2 V_{CC}/(R_1 + R_2)$ alınır (ekrandan, 01:40:00).
  - Ders sonrası not: Hoca son sonucu "$V_C$ 12 volt" diye söyledi. Kullanılan denklem $V_{CE} = V_{CC} - I_C(R_C + R_E)$ olduğu için bulunan değer $V_{CE} = 22 - 9{,}78 = 12{,}22$ V'tur; $V_C$ ise yaklaşık $22 - 0{,}85 \cdot 10 \approx 13{,}5$ V olur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
