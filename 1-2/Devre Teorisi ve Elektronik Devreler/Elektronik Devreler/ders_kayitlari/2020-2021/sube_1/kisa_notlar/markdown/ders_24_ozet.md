# Ders 24 Çalışma Özeti

## Genel Konular

- Ara sınav sorularının kısa çözüm yolları
  - Soru 1: gerilim bölücülü BJT devresi. Thevenin gerilimi ve direnci bulunur, sonra sırasıyla $I_B$, $I_C$ ve $V_C$ hesaplanır.
  - Soru 2: diyot ve ters bağlı kaynak içeren bir dalga şekillendirme devresi. Çıkış, giriş dalgasının belli seviyelerde düzlenmiş halidir; ekranda üst seviye 15 V, alt seviye −5,7 V olarak yazıldı (ekrandan, 00:15:00). <!-- BELİRSİZ: devrenin tam şekli ve giriş dalgasının genliği karede tam okunmuyor. -->
  - Soru 3: $R_1$ ve $R_C$'nin bilinmediği gerilim bölücülü BJT tasarımı. $V_E = I_C R_E$ ($R_E = 1{,}2$ kΩ), $V_B = V_E + V_{BE}$; bölücüden $V_B = \dfrac{4\,\text{k}\Omega}{4\,\text{k}\Omega + R_1} \cdot 22$ V ile $R_1$ bulunur. $22 = I_C R_C + V_{CE} + V_E$ ($V_{CE} = 10$ V) eşitliğinden $R_C$ çekilir. <!-- BELİRSİZ: verilen $I_C$ değeri altyazıda ve karede okunmuyor; $V_E$ teriminin denklemde yer alıp almadığı hocanın kısa anlatımında net değil. -->
  - Soru 4: dirençli köprü tipi tam dalga doğrultucu. Çıkışın tepe değeri 33 V; DC (ortalama) değer $0{,}636 \cdot 33 \approx 21$ V (ekrandan, 00:20:00).
- Köprü yapısında negatif yarım dalganın neden pozitife döndüğü (öğrenci sorusu)
  - Negatif yarım periyotta bir diyot kesime gider, devre iki paralel dirence indirgenir. Çıkışın artı ucu her iki yarım periyotta da yüksek potansiyelli tarafta kaldığı için çıkış tam dalga doğrultulmuş olur.
- BJT ve n kanallı JFET'in birlikte bulunduğu devre (ekrandan, 00:25:00 ve 00:30:00)
  - Değerler: üstte npn BJT ($\beta = 80$, $R_B = 470$ kΩ, $R_C = 3{,}6$ kΩ), altta n kanallı JFET ($I_{DSS} = 8$ mA, $V_P = -4$ V, $R_S = 2{,}4$ kΩ), besleme 16 V. İstenen: $V_D$.
  - $V_G = 0$ olduğundan $V_{GS} = -I_D \cdot 2{,}4$ kΩ (kendinden kutuplama doğrusu). Doğru orijinden ve $(-4\text{ V};\ 1{,}67\text{ mA})$ noktasından geçer.
  - Transfer eğrisi için kısayollar: $V_{GS} = 0{,}3V_P = -1{,}2$ V'ta $I_D \approx I_{DSS}/2 = 4$ mA; $V_{GS} = V_P/2 = -2$ V'ta $I_D = I_{DSS}/4 = 2$ mA.
  - Kesişim: $V_{GSQ} \approx -2{,}6$ V, $I_{DQ} \approx 1$ mA. $I_E \approx I_C = I_D = 1$ mA, $I_B = 1\,\text{mA}/80 = 12{,}5$ µA.
  - $V_B = 16 - 12{,}5\,\mu\text{A} \cdot 470\,\text{k}\Omega = 10{,}125$ V, $V_E = V_D = V_B - 0{,}7 = 9{,}425$ V.
- Gerilim bölücülü JFET'te $R_S$ bulma (Örnek 6.16, ekrandan, 00:35:00)
  - $V_G = \dfrac{47}{47 + 91} \cdot 16 = 5{,}44$ V; $I_D = \dfrac{16 - 12}{1{,}8\,\text{k}\Omega} = 2{,}22$ mA.
  - $V_{GS} = V_G - I_D R_S \Rightarrow -2 = 5{,}44 - 2{,}22\,\text{mA} \cdot R_S \Rightarrow R_S = 3{,}35$ kΩ.
- Geri beslemeli E-MOSFET'te $V_{DD}$ ve $R_D$ bulma (Örnek 6.17, ekrandan, 00:40:00)
  - Verilen: $I_{D(on)} = 4$ mA, $V_{GS(on)} = 6$ V, $V_{GS(Th)} = 3$ V, $V_{DS} = V_{DD}/2$, $R_G = 10$ MΩ.
  - Kapıdan akım akmadığı için $V_G = V_D$, yani $V_{GS} = V_{DS} = 6$ V. Buradan $V_{DD} = 12$ V; $R_D = 6\,\text{V}/4\,\text{mA} = 1{,}5$ kΩ.
- p kanallı JFET, gerilim bölücülü kutuplama (ekrandan, 00:45:00)
  - $I_{DSS} = 8$ mA, $V_P = +4$ V; besleme $-20$ V, bölücü 68 kΩ / 20 kΩ, $R_S = 1{,}8$ kΩ, $R_D = 2{,}7$ kΩ.
  - $V_G = \dfrac{20}{20 + 68} \cdot (-20) = -4{,}55$ V. Akım yönü ters olduğu için $V_{GS} = V_G + I_D R_S$.
  - Doğrunun eksen kesimleri: $I_D = 0$ için $V_{GS} = -4{,}55$ V; $V_{GS} = 0$ için $I_D = 2{,}53$ mA.
  - Grafikten $I_{DQ} = 3{,}4$ mA, $V_{GSQ} = 1{,}4$ V (p kanalda pozitif). $V_{DS} = -20 + 3{,}4\,\text{mA}\,(2{,}7 + 1{,}8)\,\text{k}\Omega = -4{,}7$ V.
- İşlemsel yükselteç (op-amp) giriş
  - Sembol üçgendir: eviren giriş (−, inverting), evirmeyen giriş (+, non-inverting), çıkış $V_{out}$; ayrıca besleme uçları $V_{pos}$ ve $V_{neg}$ (ör. ±12 V, ±5 V). Bir pakette tekli, ikili ya da dörtlü op-amp bulunabilir (ekrandan, 00:50:00).
  - İdeal op-amp: gerilim kazancı sonsuz, giriş direnci sonsuz, çıkış direnci sıfır. Sonuç: $V_+ = V_-$ ve girişlerden akım akmaz.
- Gerilim kazancı ve faz
  - $A_v = V_o/V_i$. $A_v = 2$ işaretin genliğini iki katına çıkarır, periyodu ve fazı değiştirmez; $A_v = -2$ ayrıca 180° faz kaydırır (ekrandan, 01:05:00).
- Temel op-amp devreleri
  - Eviren yükselteç: $V_o/V_i = -R_1/R_2$ ($R_1$ geri besleme, $R_2$ giriş direnci) (ekrandan, 01:10:00 ve 01:25:00).
  - Evirmeyen yükselteç: $V_o/V_i = (R_1 + R_2)/R_2 = 1 + R_1/R_2$ (ekrandan, 01:20:00).
  - Birim kazançlı tampon (buffer): $V_o = V_i$; evirmeyen formülde $R_1 = 0$, $R_2 = \infty$.
  - Akım-gerilim dönüştürücü: $V_o = -I_i R$.
  - Fark yükselteci (çıkarıcı): $V_o = (V_1 - V_2)\dfrac{R_1}{R_2}$ (ekrandan, 01:30:00).
  - Eviren toplayıcı, integral alıcı ve türev alıcı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Akım yönüne göre işaret
  - Bir dirençteki gerilim akımın tanımlandığı yöne göre yazılır; akım ters tanımlanmışsa terim eksi işaretle girer. p kanallı JFET'te $V_{GS} = V_G + I_D R_S$ olması ve eviren yükselteçte $I_2 = -I_1$ yazılması bu yüzdendir.
- p kanallı elemanlarda işaretler
  - p kanallı JFET'in transfer eğrisi sola değil sağa doğrudur ($V_P > 0$); çalışma noktasında $V_{GSQ}$ pozitif çıkar.
- Op-amp sorusunun anahtarı
  - $V_+ = V_-$ ve $I_+ = I_- = 0$. Bütün kazanç hesapları bu iki kuraldan yola çıkılarak düğüm akımlarıyla yapılır.
- Çözümün yazılışı
  - Birimler mutlaka yazılmalı (mili ve mikro karıştırılmamalı); dalga şekilleri eksenleri belirtilerek, ölçekli ve anlaşılır çizilmeli. Grafik çözümde eğri, hesaplanan noktalarla ve cetvelle çizilmeli.
- Dalga şekillendirme soruları ezberle değil muhakemeyle çözülmeli
  - Çıkışı otomatik olarak sinüs gibi çizmek yerine diyotların hangi aralıkta iletimde olduğu düşünülerek seviyeler hesaplanmalı.

## Kısa Tekrar Notları

- n kanallı JFET, kendinden kutuplama: $V_{GS} = -I_D R_S$; eğri için $0{,}3V_P \to I_{DSS}/2$, $V_P/2 \to I_{DSS}/4$.
- Gerilim bölücülü JFET: $V_G = \dfrac{R_2}{R_1 + R_2}V_{DD}$, $V_{GS} = V_G - I_D R_S$.
- Geri beslemeli E-MOSFET: $V_{GS} = V_{DS}$ (kapı akımı sıfır).
- p kanallı JFET: işaretler ters, $V_{GS} = V_G + I_D R_S$, $V_{GSQ} > 0$.
- BJT + JFET seri kolda: $I_E \approx I_C = I_D$.
- İdeal op-amp: $A \to \infty$, $R_{in} \to \infty$, $R_{out} = 0$; $V_+ = V_-$, giriş akımları sıfır.
- Eviren: $-R_1/R_2$. Evirmeyen: $1 + R_1/R_2$. Tampon: 1. Akım-gerilim: $V_o = -I_i R$. Fark: $(V_1 - V_2)R_1/R_2$.
- Kazançtaki eksi işareti 180° faz farkıdır, genliğin negatif olması değildir.

## Detaylı Açıklamalar

- BJT + JFET devresinin mantığı
  - JFET'in kapısı doğrudan toprağa bağlı olduğu için $V_{GS}$ yalnız $R_S$ üzerindeki gerilimle belirlenir. Bu yüzden önce JFET'in çalışma noktası grafikle bulunur. JFET, BJT ile aynı seri kolda olduğundan bulunan $I_D$ aynı zamanda BJT'nin emitör ve yaklaşık olarak kollektör akımıdır. $I_C/\beta$ ile baz akımı, $R_B$ üzerindeki düşümle $V_B$, ondan $V_{BE}$ çıkarılarak orta düğümün gerilimi $V_D$ bulunur. Bir öğrenci kollektör akımı bilindiği için doğrudan kollektör tarafından gidilip gidilemeyeceğini sordu; hoca o yoldan gitmek için $V_{CE}$ ve $V_{DS}$'nin bilinmesi gerektiğini, bunların ise henüz bulunmadığını (bulunan yalnız $V_{GS}$) söyledi.
  - Ders sonrası not: Shockley denklemi $I_D = 8(1 + V_{GS}/4)^2$ mA ile doğru $V_{GS} = -2{,}4 I_D$ birlikte çözülünce $V_{GSQ} \approx -2{,}54$ V, $I_{DQ} \approx 1{,}06$ mA çıkar (python ile kontrol edildi). Grafikten okunan $-2{,}6$ V ve 1 mA bu değere yakındır.
- p kanallı JFET'te işaretler
  - Besleme negatif olduğu için akım ters yönde akar. Kapı-kaynak çevresinde KVL $V_G - V_{GS} + I_D R_S = 0$ olur, yani $V_{GS} = V_G + I_D R_S$. Doğrunun iki kesim noktası bulunup cetvelle çizilir, transfer eğrisi sağa doğru (pozitif $V_{GS}$ tarafında) çizilir ve kesişim okunur. $V_{DS}$ için $-I_D R_S + V_{DS} - I_D R_D + V_{DD} = 0$ (ekrandan, 00:45:00) yazılır.
  - Ders sonrası not: denklemler birlikte çözülünce $I_{DQ} \approx 3{,}32$ mA, $V_{GSQ} \approx 1{,}42$ V çıkar (python ile kontrol edildi); grafikten okunan 3,4 mA ve 1,4 V bunun yuvarlanmış halidir.
- Eviren yükselteçte akım yönleri
  - Slaytta $I_1$, $V_o$'dan $V_-$ düğümüne doğru (geri besleme direnci $R_1$ üzerinden), $I_2$ ise $V_i$'den $V_-$ düğümüne doğru (giriş direnci $R_2$ üzerinden) tanımlanmıştır. İkisi de düğüme girdiği ve op-amp'e akım akmadığı için $I_1 = -I_2$. $V_- = V_+ = 0$ konunca $V_i/R_2 = -V_o/R_1$ ve $V_o/V_i = -R_1/R_2$ bulunur. Örneğin $R_1 = R_2 = 1$ kΩ için kazanç $-1$ (yalnız evirme), $R_1 = 2$ kΩ için $-2$, $R_1 = 25$ kΩ ve $R_2 = 1$ kΩ için $-25$ olur.
  - Ders sonrası not: hoca bir yerde (01:16:10) oranı önce $-R_2/R_1$ diye söyledi, hemen ardından düzeltti; doğrusu slayttaki gösterimle $-R_1/R_2$'dir.
- Evirmeyen yükselteç ve tampon
  - $V_+ = V_i$ olduğu için $V_- = V_i$; $R_1$-$R_2$ bölücüsünden $V_i = \dfrac{R_2}{R_1 + R_2}V_o$, yani $A_v = (R_1 + R_2)/R_2$. Aynı sonuç $I_1 = I_2$, $(V_o - V_i)/R_1 = V_i/R_2$ yazılarak da bulunur. $R_1 = R_2 = 1$ kΩ için kazanç 2'dir ve eksi işaret olmadığı için çıkış evrilmez. Tamponda çıkış doğrudan eviren girişe bağlıdır ($R_1 = 0$, $R_2 = \infty$), kazanç 1'dir. Giriş direnci çok yüksek, çıkış direnci çok düşük olduğu için kaynağı yükten yalıtan, çıkıştaki bir kısa devrenin girişe zarar vermesini önleyen bir koruma katı olarak kullanılır.
- Akım-gerilim dönüştürücü
  - Giriş akımı geri besleme direncinden geçer, $V_- = 0$ olduğundan $V_o = -I_i R$ olur. Yalnız gerilim ölçebilen bir multimetreyle bu çıkış okunarak giriş akımı $R$ oranında bulunabilir.
- Fark yükselteci, toplayıcı, integral alıcı
  - Fark yükseltecinde $V_+ = \dfrac{R_1}{R_1 + R_2}V_1$ bölücüden bulunur, eviren tarafta $I_1 = I_2$ yazılıp sadeleştirilince çıkış iki girişin farkıyla orantılı çıkar. Eviren toplayıcıda $V_- = 0$ alınıp her girişin akımı ($V_1/R_2$, $V_2/R_2$) geri besleme akımına eşitlenir; çıkış girişlerin toplamının eksi işaretlisidir. İntegral alıcıda çıkış, girişin 0'dan $t$'ye kadar altında kalan alanın $RC$'ye bölünmüş ve eksi işaretli halidir; R ve C yer değiştirince devre türev alıcı olur. <!-- BELİRSİZ: toplayıcı, tampon, akım-gerilim dönüştürücü ve integral alıcı slaytlarının karesi yok; formüller hocanın sözlü anlatımından alındı. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
