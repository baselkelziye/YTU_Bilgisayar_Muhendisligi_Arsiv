# Ders 23 Çalışma Özeti

## Genel Konular

- FET türlerinin hatırlatılması
  - FET'ler JFET ve MOSFET olarak ikiye ayrılır. MOSFET'ler de kanal ayarlamalı (D-MOSFET, depletion type) ve kanal oluşturmalı (E-MOSFET, enhancement type) olarak ikiye ayrılır. Her türün N kanal ve P kanal çeşidi vardır.
  - N kanal JFET ile N kanal D-MOSFET'in transfer eğrileri ($I_D$-$V_{GS}$) birbirine çok benzer: eğri negatif bir $V_P$ değerinden başlar, $V_{GS}=0$'da $I_{DSS}$'ye ulaşır. D-MOSFET'te eğri pozitif $V_{GS}$ bölgesine de devam eder.
  - N kanal E-MOSFET'te eğri pozitif bir eşik geriliminden ($V_{GS(Th)}$) başlar; kanal ancak bu gerilimden sonra oluşur ve akım artmaya başlar.
  - P kanal yapılarda bütün eğilimler ve işaretler N kanalın tersidir.
- FET kutuplamada grafik çözüm yöntemi
  - Transistöre ait transfer eğrisi (eleman karakteristiği) ile devreden yazılan $V_{GS}$-$I_D$ doğru denklemi (kutuplama doğrusu) aynı eksen takımına çizilir. Kesişim noktası çalışma noktasını ($I_{D_Q}$, $V_{GS_Q}$) verir.
  - FET'te kapı akımı sıfırdır ($I_G = 0$), bu yüzden $I_S = I_D$ alınır.
- JFET ve D-MOSFET eğrisini çizmek için pratik noktalar
  - $V_{GS}=0$ iken $I_D = I_{DSS}$; $V_{GS}=V_P$ iken $I_D=0$.
  - $V_{GS}=0{,}3V_P$ iken $I_D \approx I_{DSS}/2$; $V_{GS}=V_P/2$ iken $I_D = I_{DSS}/4$.
  - D-MOSFET'te eğrinin pozitif bölgedeki gidişi için Shockley denkleminde pozitif bir $V_{GS}$ (örneğin $+2$ V) yerine konur: $I_D = I_{DSS}\left(1-\frac{V_{GS}}{V_P}\right)^2$.
- E-MOSFET eğrisi
  - $I_D = k\,(V_{GS}-V_{GS(Th)})^2$. $k$ verilmemişse verilen $I_{D(on)}$ ve $V_{GS(on)}$ değerlerinden bulunur: $k = \frac{I_{D(on)}}{(V_{GS(on)}-V_{GS(Th)})^2}$.
  - Eğri, eşikten sonraki birkaç $V_{GS}$ değeri yerine konarak noktalarla çizilir.
- Çözülen kitap örnekleri (ekrandan)
  - Öz kutuplamalı N kanal D-MOSFET ($I_{DSS}=8$ mA, $V_P=-8$ V, $R_S=2{,}4$ kΩ, $R_D=6{,}2$ kΩ, $V_{DD}=20$ V): $I_{D_Q}\approx 1{,}7$ mA, $V_{GS_Q}\approx -4{,}3$ V, $V_D = 9{,}46$ V.
  - Kapısı toprağa bağlı D-MOSFET ($I_{DSS}=10$ mA, $V_P=-1$ V, $R_D=1{,}5$ kΩ, $V_{DD}=20$ V): $V_{GS_Q}=0$, $I_{D_Q}=I_{DSS}=10$ mA, $V_{DS}=5$ V.
  - Geri beslemeli E-MOSFET ($V_{DD}=12$ V, $R_D=2$ kΩ, $V_{GS(Th)}=3$ V, $I_{D(on)}=6$ mA, $V_{GS(on)}=8$ V): $k=0{,}24\times10^{-3}$ A/V², kutuplama doğrusu $V_{GS}=V_{DD}-I_DR_D$, çalışma noktası yaklaşık $6{,}4$ V ve $2{,}8$ mA.
  - Gerilim bölücülü E-MOSFET ($V_{DD}=40$ V, 22 MΩ / 18 MΩ, $R_D=3$ kΩ, $R_S=0{,}82$ kΩ, $V_{GS(Th)}=5$ V, $I_{D(on)}=3$ mA, $V_{GS(on)}=10$ V): $V_G=18$ V, $I_{D_Q}=6{,}7$ mA, $V_{GS_Q}=12{,}5$ V, $V_{DS}=14{,}4$ V.
  - JFET ile BJT'nin birlikte kullanıldığı devre ($\beta=80$): JFET öz kutuplamadan $I_{D_Q}\approx 1$ mA bulunur, $I_C\approx I_E\approx I_D$ alınarak $V_B=10{,}125$ V, $V_D=V_E=9{,}425$ V.
  - Gerilim bölücülü JFET'te $V_D=12$ V ve $V_{GS_Q}=-2$ V verildiğinde $R_S$ tasarımı: $V_G=5{,}44$ V, $I_D=2{,}22$ mA, $R_S=3{,}35$ kΩ.
  - Gerilim bölücülü P kanal JFET ($I_{DSS}=8$ mA, $V_P=4$ V, $-20$ V besleme): $V_G=-4{,}55$ V, $V_{GS}=V_G+I_DR_S$, $I_{D_Q}=3{,}4$ mA, $V_{GS_Q}=1{,}4$ V, $V_{DS}=-4{,}7$ V.

## Hocanın Özellikle Vurguladığı Kısımlar

- Çözümün özü iki eğrinin kesişimidir
  - Önce transistörün kendi eğrisi verilen parametrelerden çizilir, sonra devreden kutuplama doğrusu yazılır. Kesişim noktası çalışma akımını ve gerilimini verir.
- Doğru tek noktadan geçiyorsa ikinci nokta seçilmelidir
  - Öz kutuplamada $V_{GS}=-I_DR_S$ doğrusu orijinden geçer; eksen kesişimleri tek nokta verir. Bu yüzden keyfi bir $V_{GS}$ (örneğin $-6$ V ya da $-8$ V) yerine konup ikinci nokta bulunur.
- İşaret ve birimlere dikkat
  - $V_{GS_Q}$'nun eksi ya da artı oluşu, mA ile µA ayrımı gibi ayrıntılar unutulursa sonuç yanlış olur.
- P kanalda akım yönü terstir
  - P kanal FET'te $I_D$ ters yönde akar; $V_S$ ve $V_{DS}$ denklemleri yazılırken işaretler buna göre değişir. Özet tablolar N kanal için verilmiştir, P kanalda tersine çevrilir.
- Grafik çizimi düzgün yapılmalı
  - Eksen aralıkları eşit ve tutarlı çizilirse kesişim noktası daha doğru okunur. Grafik çözümde küçük farklar (örneğin $-4{,}1$ ile $-4{,}3$ V) kabul edilebilir.
- Soruları kendiniz çözün
  - İzlerken anlaşılır görünen çözümlerde, tek başına çözerken ayrıntılar kaçabilir. Birkaç soru çözüldükten sonra genel mantık oturur.

## Kısa Tekrar Notları

- $I_G=0$ olduğundan $I_S=I_D$; kapı direncinde gerilim düşmez, $R_G$'nin iki ucu aynı gerilimdedir.
- Sabit kutuplama ya da kapısı toprağa bağlı D-MOSFET: $V_{GS_Q}=0$ ise $I_{D_Q}=I_{DSS}$.
- Öz kutuplama: $V_{GS}=-I_DR_S$.
- Gerilim bölücü: $V_G=\frac{R_2V_{DD}}{R_1+R_2}$, $V_{GS}=V_G-I_DR_S$.
- Geri beslemeli E-MOSFET: $V_{GS}=V_{DS}=V_{DD}-I_DR_D$.
- Doğru için $I_D=0$ ve $V_{GS}=0$ konarak eksen kesişimleri bulunur.
- JFET/D-MOSFET eğrisi: $(V_P,0)$, $(0{,}3V_P,\ I_{DSS}/2)$, $(V_P/2,\ I_{DSS}/4)$, $(0,\ I_{DSS})$.
- E-MOSFET: $k=I_{D(on)}/(V_{GS(on)}-V_{GS(Th)})^2$, eğri $V_{GS(Th)}$'den başlar.
- $V_{DS}=V_{DD}-I_D(R_D+R_S)$ (N kanal); P kanalda $V_{DS}=-V_{DD}+I_D(R_D+R_S)$ (besleme negatif).
- FET ile BJT birlikteyse ana koldaki akımlar yaklaşık eşittir: $I_E\approx I_C\approx I_D$, $I_B=I_C/\beta$.

## Detaylı Açıklamalar

- Ders, FET kutuplama konusunun kitap örnekleri üzerinden soru çözümüyle geçer. Ekranda İngilizce bir kaynaktan alınmış örnekler ve çözümleri olan bir PDF açıktır; hoca örneklerin üzerine kalemle işaretleyerek anlatır.
- Öz kutuplamalı D-MOSFET örneğinde kapı 1 MΩ ile toprağa bağlıdır ve kapıdan akım akmadığı için $V_G=0$'dır. Kaynakta $V_S=I_DR_S$ olduğundan $V_{GS}=-I_D(2{,}4\ \text{k}\Omega)$ olur. Transfer eğrisi için $(-8\ \text{V},0)$, $(-2{,}4\ \text{V},4\ \text{mA})$, $(-4\ \text{V},2\ \text{mA})$, $(0,8\ \text{mA})$ ve D-MOSFET'e özgü dış nokta $(+2\ \text{V},12{,}5\ \text{mA})$ kullanılır (ekrandan, 00:20:00). Doğru orijinden geçtiği için $V_{GS}=-6$ V seçilip $I_D=2{,}5$ mA bulunur (ekrandan, 00:25:00). Kesişimden $I_{D_Q}\approx1{,}7$ mA, $V_{GS_Q}\approx-4{,}3$ V okunur; $V_D=20-(1{,}7)(6{,}2)=9{,}46$ V.
- Kapısı doğrudan toprağa bağlı D-MOSFET'te çizim gerekmez: $V_{GS}=0$ olduğundan $I_D=I_{DSS}=10$ mA, $V_{DS}=V_D=20-(10\ \text{mA})(1{,}5\ \text{k}\Omega)=5$ V.
- Geri beslemeli E-MOSFET örneğinde $R_G$ üzerinden akım akmadığı için kapı gerilimi savak gerilimine eşittir. Bu yüzden $V_{GS}=V_D=12-I_D(2\ \text{k}\Omega)$ olur; eksen kesişimleri $(12\ \text{V},0)$ ve $(0,6\ \text{mA})$'dir. Eğri $k=6/(8-3)^2=0{,}24$ mA/V² ile çizilir: $V_{GS}=6$ V'ta $2{,}16$ mA, $10$ V'ta $11{,}76$ mA (ekrandan, 00:30:00).
- Gerilim bölücülü E-MOSFET'te $V_G=\frac{18}{18+22}\cdot40=18$ V, $V_{GS}=18-I_D(0{,}82\ \text{k}\Omega)$; doğru $(18\ \text{V},0)$ ve $(0,21{,}95\ \text{mA})$ noktalarından geçer (ekrandan, 00:35:00). $k=3/(10-5)^2=0{,}12$ mA/V² ile eğri çizilir. Kesişimden $I_{D_Q}=6{,}7$ mA, $V_{GS_Q}=12{,}5$ V; $V_{DS}=40-6{,}7(0{,}82+3)=14{,}4$ V (ekrandan, 00:40:00).
- FET ile BJT'nin birlikte bulunduğu devrede önce JFET'in öz kutuplama doğrusu ($V_{GS}=-I_D\cdot2{,}4$ kΩ) ile $I_{DSS}=8$ mA, $V_P=-4$ V eğrisinin kesişiminden $I_{D_Q}=1$ mA, $V_{GS_Q}=-2{,}6$ V bulunur. Sonra $I_C\approx I_D$ alınarak $I_B=1\ \text{mA}/80=12{,}5$ µA, $V_B=16-(12{,}5\ \mu\text{A})(470\ \text{k}\Omega)=10{,}125$ V ve $V_E=V_D=V_B-0{,}7=9{,}425$ V hesaplanır (ekrandan, 00:45:00).
  - Ders sonrası not: Hoca $I_B$'yi sözlü olarak "12,5 mA" dedi; doğrusu ekrandaki gibi $12{,}5$ µA'dir.
- Tasarım tipindeki örnekte $V_D$ ve $V_{GS_Q}$ verilir, $R_S$ istenir: $V_G=\frac{47}{47+91}\cdot16=5{,}44$ V, $I_D=\frac{16-12}{1{,}8}=2{,}22$ mA, $-2=5{,}44-2{,}22R_S$ ile $R_S=3{,}35$ kΩ (ekrandan, 00:50:00).
- Başka bir tasarım örneğinde geri beslemeli E-MOSFET'te $V_{DS}=V_{DD}/2$ istenir. Kapı ile savak aynı gerilimde olduğundan $V_{DS}=V_{GS(on)}=6$ V, dolayısıyla $V_{DD}=12$ V bulunur; $R_D$ üzerindeki $6$ V'un $I_{D(on)}=4$ mA'ya bölünmesiyle $R_D=1{,}5$ kΩ olur. <!-- BELİRSİZ: bu örneğin kare görüntüsü yok; devre ve verilen değerler altyazıdan kuruldu. -->
- P kanal JFET örneğinde besleme negatiftir ve akım ters yönde akar: $V_G=\frac{20}{20+68}(-20)=-4{,}55$ V, $V_{GS}=V_G+I_DR_S$. Doğru $(-4{,}55\ \text{V},0)$ ve $(0,2{,}53\ \text{mA})$ noktalarından geçer; eğri $V_P=+4$ V ile $I_{DSS}=8$ mA arasında çizilir. Kesişimden $I_{D_Q}=3{,}4$ mA, $V_{GS_Q}=1{,}4$ V; $V_{DS}=-20+3{,}4(2{,}7+1{,}8)=-4{,}7$ V (ekrandan, 00:55:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
