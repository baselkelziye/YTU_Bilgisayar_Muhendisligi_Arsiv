# Ders 21 Çalışma Özeti

## Genel Konular

- FET türlerinin tekrarı
  - FET'ler JFET (jonksiyon FET) ve MOSFET olarak ikiye ayrılır; her biri N kanal ve P kanal olabilir.
  - MOSFET'ler iki yapıdadır: D-MOSFET (kanal ayarlamalı, depletion) ve E-MOSFET (kanal oluşturmalı, enhancement).
  - Sembolde okun yönü kanal tipini gösterir: ok içeri doğruysa kanal N tipidir. P kanallı elemanların karakteristikleri N kanallıların aynalanmış hâlidir.
- FET'in temel bağıntıları
  - FET gerilim kontrollü bir elemandır: çıkış akımı $I_D$, $V_{GS}$ ile kontrol edilir. BJT ise akım kontrollüdür ($I_C=\beta I_B$).
  - Bütün FET tiplerinde $I_G \approx 0$ ve $I_D = I_S$ (BJT'de yalnız $I_C \cong I_E$).
  - JFET ve D-MOSFET için Shockley denklemi: $I_D = I_{DSS}\left(1-\dfrac{V_{GS}}{V_P}\right)^2$. Parametreler $I_{DSS}$ ve $V_P$ (pinch-off) elemana özgüdür.
  - E-MOSFET için: $I_D = k\,(V_{GS}-V_{GS(Th)})^2$, $k = \dfrac{I_{D(on)}}{(V_{GS(on)}-V_{GS(Th)})^2}$ (ekrandan, 00:05:00).
  - D-MOSFET, JFET'ten farklı olarak pozitif $V_{GS}$ ile de çalışabilir ve $I_D$, $I_{DSS}$'yi aşabilir (ekrandan, 00:30:00).
  - E-MOSFET'te $V_{GS} < V_{GS(Th)}$ iken $I_D=0$'dır; eşik aşılınca kanal oluşur ve akım artar.
- FET kutuplama devreleri (ekrandan, 00:15:00)
  - JFET: sabit kutuplama (fixed bias), kendinden kutuplama (self-bias), gerilim bölücülü kutuplama.
  - D-MOSFET: kendinden kutuplama ve gerilim bölücülü kutuplama.
  - E-MOSFET: geri beslemeli (feedback) yapı ve gerilim bölücülü kutuplama.
- Grafik çözüm yöntemi
  - Devreden $V_{GS}$ ile $I_D$ arasında doğrusal bir denklem (kutuplama doğrusu) çıkarılır.
  - Elemanın transfer eğrisi çizilir; doğrunun eğriyi kestiği nokta çalışma noktasıdır ($I_{DQ}$, $V_{GSQ}$).
  - Q noktası bulunduktan sonra $V_D$, $V_S$, $V_{DS}$ gibi gerilimler devre denklemlerinden hesaplanır.
- Transfer eğrisinin çizimi
  - JFET ve D-MOSFET için kolay noktalar: $V_{GS}=0 \Rightarrow I_D=I_{DSS}$; $V_{GS}=V_P \Rightarrow I_D=0$; $V_{GS}=0{,}3V_P \Rightarrow I_D=I_{DSS}/2$; $V_{GS}=V_P/2 \Rightarrow I_D=I_{DSS}/4$.
  - D-MOSFET'te pozitif bölge için bir pozitif $V_{GS}$ değeri (örneğin $+1$ V) formüle konarak ek nokta bulunur.
  - E-MOSFET'te bu kısa yollar yoktur; $k$ bulunur ve birkaç $V_{GS}$ değeri formüle konarak ara noktalar hesaplanır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kanal tipini sembolden ezberle değil okun yönünden okumak
  - Ok içeri doğruysa kanal N tipidir; bu basit ipucuyla ezbere gerek kalmaz.
- Grafikleri ölçekli ve geniş çizmek
  - Eksenleri eşit aralıklara bölmek gerekir ($I_{DSS}=10$ mA ise yarısı tam 5 mA'nın yerine gelmeli). Ölçek bozulursa doğrunun kesişim noktası kayar ve $I_{DQ}$, $V_{GSQ}$ yanlış çıkar.
  - Elle yapılan grafik çözümde küçük farklar (örneğin 2,4 yerine 2,5 mA) sorun değildir, ama işaret (eksi/artı) önemlidir.
- Birimlere dikkat
  - mA ile µA'yı karıştırmak hesapları bozar; kΩ ile mA çarpılınca $10^{3}\cdot10^{-3}$ birbirini götürür ve sonuç doğrudan volt olur.
- Soruları elle çözmek
  - Konu soru çözerek oturur; yalnız okuyup geçmek küçük hatalara yol açar.

## Kısa Tekrar Notları

- FET: gerilim kontrollü; $I_G\approx0$, $I_D=I_S$.
- JFET/D-MOSFET: $I_D = I_{DSS}(1-V_{GS}/V_P)^2$; E-MOSFET: $I_D = k(V_{GS}-V_{GS(Th)})^2$.
- Sabit kutuplama: $V_{GS} = -V_{GG}$ doğrudan bulunur, sonra $I_D$ formülden, $V_{DS}=V_{DD}-I_DR_D$.
- Kendinden kutuplama: $V_{GS} = -I_DR_S$; $V_{DS} = V_{DD}-I_D(R_D+R_S)$, $V_S = I_DR_S$, $V_D = V_{DS}+V_S = V_{DD}-I_DR_D$.
- Gerilim bölücü: $V_G = \dfrac{R_2}{R_1+R_2}V_{DD}$, $V_{GS} = V_G - I_DR_S$.
- E-MOSFET geri beslemeli yapı: $R_G$'den akım akmaz, $V_G=V_D$, $V_{GS}=V_{DS}=V_{DD}-I_DR_D$.
- Kutuplama doğrusunun iki noktası: $V_{GS}=0$ için $I_D$ ve $I_D=0$ için $V_{GS}$.
- Transfer eğrisi noktaları: $(V_P,0)$, $(V_P/2, I_{DSS}/4)$, $(0{,}3V_P, I_{DSS}/2)$, $(0, I_{DSS})$.

## Detaylı Açıklamalar

- JFET'in çalışması
  - N kanallı JFET'te kanalın etrafını P tipi malzeme sarar. $V_{GS}=0$ iken kanal tam açıktır ve en büyük akım $I_{DSS}$ akar. $V_{GS}$ negatif yapıldıkça kanal daralır; $V_{GS}=V_P$ olduğunda kanal kapanır (pinch-off) ve $I_D=0$ olur. Aradaki gerilimlerde transfer eğrisi üzerinde belirli bir $I_D$ akar.
- E-MOSFET'te kanalın oluşması
  - N kanallı E-MOSFET'te başlangıçta kanal yoktur. Gate ile kanal arasında yalıtkan tabaka vardır. Pozitif $V_{GS}$ uygulanınca N tipi bir tabaka (kanal) oluşmaya başlar; kanalın ilk oluştuğu gerilim $V_{GS(Th)}$'dir. Gerilim arttıkça kanal büyür ve akım hızla artar.
- Kendinden kutuplamalı JFET (ekrandan, 00:20:00)
  - Ana kolda $V_{DD} = I_DR_D + V_{DS} + I_SR_S$ yazılır. Gate'ten akım akmadığı için $R_G$ üzerinde gerilim düşmez. $V_D$ iki yoldan bulunabilir: $V_D = V_{DD}-I_DR_D$ ya da $V_D = V_{DS}+I_SR_S$.
- Gerilim bölücülü kutuplama (ekrandan, 00:25:00)
  - Örnek: $V_{DD}=20$ V, $R_1=1{,}5$ k, $R_2=0{,}5$ k ise $V_G = \dfrac{0{,}5}{2}\cdot 20 = 5$ V; $R_1$ üzerinde 15 V düşer. $V_G$, $V_{GS}$'ye eşit değildir: $V_G = V_{GS}+I_SR_S$.
  - $V_{GS} = V_G - I_DR_S$ bir doğru denklemidir ($y = a - bx$ biçiminde, ters eğimli). $V_{GS}=0$ için $I_D = V_G/R_S$, $I_D=0$ için $V_{GS}=V_G$ bulunur. Bu doğrunun transfer eğrisiyle kesişimi Q noktasıdır.
- Sabit kutuplamalı JFET örneği (ekrandan, 00:55:00)
  - $V_{DD}=16$ V, $R_D=2$ k, $R_G=1$ MΩ, $V_{GG}=2$ V, $I_{DSS}=10$ mA, $V_P=-8$ V.
  - $V_{GSQ}=-2$ V, $I_{DQ}=10(1-0{,}25)^2=5{,}625$ mA, $V_{DS}=V_D=16-5{,}625\cdot2=4{,}75$ V, $V_G=-2$ V, $V_S=0$.
- Gerilim bölücülü JFET örneği (ekrandan, 01:00:00)
  - $V_{DD}=16$ V, $R_2=270$ k, $R_D=2{,}4$ k, $R_S=1{,}5$ k, $I_{DSS}=8$ mA, $V_P=-4$ V; $V_G=1{,}82$ V.
  - Doğru: $V_{GS}=1{,}82-1{,}5I_D$; uç noktalar $I_D=1{,}21$ mA ($V_{GS}=0$) ve $V_{GS}=1{,}82$ V ($I_D=0$).
  - Grafikten $I_{DQ}\approx2{,}4$ mA, $V_{GSQ}\approx-1{,}8$ V; $V_D=10{,}24$ V, $V_S=3{,}6$ V, $V_{DS}=6{,}64$ V.
- Gerilim bölücülü D-MOSFET örneği (ekrandan, 00:30:00 ve 01:05:00)
  - $V_{DD}=18$ V, $R_1=110$ MΩ, $R_2=10$ MΩ, $R_D=1{,}8$ k, $R_S=750\ \Omega$, $I_{DSS}=6$ mA, $V_P=-3$ V.
  - $V_G=\dfrac{10}{120}\cdot18=1{,}5$ V; doğru: $V_{GS}=1{,}5-0{,}75I_D$; uç noktalar $(0;\,2\text{ mA})$ ve $(1{,}5\text{ V};\,0)$.
  - Eğri noktaları: $(-3;0)$, $(-1{,}5;1{,}5)$, $(-0{,}9;3)$, $(0;6)$, $(+1;10{,}67)$. Sonuç: $I_{DQ}\approx3{,}1$ mA, $V_{DS}=18-3{,}1\cdot(1{,}8+0{,}75)\approx10{,}1$ V.
- JFET ile BJT karşılaştırması (ekrandan, 00:45:00)
  - JFET: $I_D=I_{DSS}(1-V_{GS}/V_P)^2$, $I_D=I_S$, $I_G\cong0$. BJT: $I_C=\beta I_B$, $I_C\cong I_E$, $V_{BE}\cong0{,}7$ V. JFET'te giriş-çıkış ilişkisi karesel, BJT'de doğrusaldır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
