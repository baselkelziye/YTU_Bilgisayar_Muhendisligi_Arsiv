# Ders 23 Çalışma Özeti

## Genel Konular

- FET'lerin temel akım bağıntıları
  - Bütün FET'lerde kapı akımı sıfır kabul edilir: $I_G \cong 0$ A, bu yüzden $I_D = I_S$ (ekrandan, 00:30:00). BJT'de $I_B$ sıfır alınamadığı için $I_C = \beta I_B$ denklemi yazılır; FET'te buna gerek kalmaz.
  - JFET ve D tipi MOSFET için Shockley denklemi: $I_D = I_{DSS}\left(1 - \frac{V_{GS}}{V_P}\right)^2$.
    - $V_{GS} = 0$ iken $I_D = I_{DSS}$; $V_{GS} = V_P$ iken $I_D = 0$.
  - E tipi MOSFET için: $I_D = k(V_{GS} - V_T)^2$ (ekrandan, 00:35:00).
    - $k$ verilmezse eğri üzerindeki bir nokta ($I_{D(on)}$, $V_{GS(on)}$) verilir ve $k$ bu noktadan bulunur.
- Transfer (aktarım) eğrisini hızlı çizme
  - $V_{GS} = V_P/2$ alınırsa $I_D = I_{DSS}/4$ olur.
  - $V_{GS} \cong 0{,}3V_P$ alınırsa $I_D \cong I_{DSS}/2$ olur.
  - Bu iki nokta, $(0, I_{DSS})$ ve $(V_P, 0)$ ile birlikte dört nokta eder. Nokta sayısı arttıkça eğri daha doğru çizilir.
  - D tipi MOSFET'te eğri pozitif $V_{GS}$ tarafına da uzatılır; bunun için denkleme örneğin $V_{GS} = +1$ V konur.
- Sabit kutuplama (fixed bias)
  - Kapıya doğrudan $V_{GG}$ bağlıdır, kaynakta direnç yoktur: $V_{GS} = -V_{GG}$, $V_S = 0$, $V_{DS} = V_{DD} - I_D R_D$ (ekrandan, 00:40:00).
  - $V_{GS}$ sabit olduğundan $I_{D_Q}$ grafik çizmeden doğrudan Shockley denkleminden hesaplanır.
- Kendinden kutuplama (self-bias)
  - Kapıda DC kaynak yoktur, $V_{GS} = -I_D R_S$ olur. Bu doğru orijinden geçer.
- Gerilim bölücü kutuplama
  - $V_G = \frac{R_2}{R_1 + R_2} V_{DD}$, $V_{GS} = V_G - I_D R_S$.
  - Doğrunun iki noktası: $I_D = 0 \Rightarrow V_{GS} = V_G$; $V_{GS} = 0 \Rightarrow I_D = V_G / R_S$ (ekrandan, 00:50:00).
  - Doğrunun transfer eğrisini kestiği nokta Q noktasıdır ($I_{D_Q}$, $V_{GS_Q}$).
  - Sonra $V_D = V_{DD} - I_D R_D$, $V_S = I_D R_S$, $V_{DS} = V_{DD} - I_D(R_D + R_S)$ hesaplanır.
- E tipi MOSFET kutuplama devreleri
  - Geri beslemeli kutuplama: kapı direncinden akım geçmediği için $V_G = V_D$, yani $V_{GS} = V_{DD} - I_D R_D$ (ekrandan, 01:05:00).
  - Doğrunun noktaları: $I_D = 0 \Rightarrow V_{GS} = V_{DD}$; $V_{GS} = 0 \Rightarrow I_D = V_{DD}/R_D$.
  - Gerilim bölücülü E tipi devrede de aynı yol izlenir: $V_{GS} = V_G - I_D R_S$.
- P kanallı elemanlar
  - Yöntem değişmez. JFET ve D tipi MOSFET'te pozitif, E tipinde negatif $V_{GS}$ ile çalışılır; transfer eğrisi düşey eksene göre aynalanır.
- Çözülen örnekler
  - Transfer eğrisi çizimi, sabit kutuplamalı JFET, gerilim bölücülü JFET, gerilim bölücülü D tipi MOSFET, kendinden kutuplamalı D tipi MOSFET, $V_{GS} = 0$ olan devre ve E tipi MOSFET için $k$ hesabı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bütün çözümün anahtarı $V_{GS}$'dir
  - FET gerilim kontrollü bir elemandır; $V_{GS}$ bulunmadan $I_D$ bulunamaz. Her devrede önce $V_{GS}$'yi $I_D$ cinsinden veren denklem (KVL) çıkarılır.
- Q noktası grafik yöntemle bulunur ve özenle çizilmelidir
  - Kağıtta çizimde 3,1 mA yerine 3 ya da 3,2 okumak kabul edilir, ama 4 okumak bariz bir hatadır.
- Gerilim bölücülü D tipi MOSFET sorusu
  - Hoca bu tarz bir sorunun doğrudan final sorusu olabileceğini söyledi.
- D tipi MOSFET'te eğriyi pozitif tarafa uzatmak
  - Bazen kutuplama doğrusu eğriyi pozitif $V_{GS}$ tarafında keser. Eğri uzatılmazsa Q noktası bulunamaz; bu yüzden elemanın D tipi olduğunu fark etmek gerekir.
- Bağlantının adı önemli değil
  - Devre hazır başlıklara uymasa bile $V_{GS}$ denklemini çıkarmayı bilen her bağlantıyı çözebilir.

## Kısa Tekrar Notları

- $I_G = 0$, $I_D = I_S$.
- JFET ve D-MOSFET: $I_D = I_{DSS}(1 - V_{GS}/V_P)^2$.
- E-MOSFET: $I_D = k(V_{GS} - V_T)^2$, $k = I_{D(on)}/(V_{GS(on)} - V_T)^2$, birimi A/V².
- Kısa yol noktaları: $V_P/2 \to I_{DSS}/4$; $0{,}3V_P \to I_{DSS}/2$.
- Sabit kutuplama: $V_{GS} = -V_{GG}$, grafik gerekmez.
- Kendinden kutuplama: $V_{GS} = -I_D R_S$, doğru orijinden geçer.
- Gerilim bölücü: $V_{GS} = V_G - I_D R_S$; noktalar $(V_G, 0)$ ve $(0, V_G/R_S)$.
- Geri beslemeli E-MOSFET: $V_{GS} = V_{DD} - I_D R_D$; noktalar $(V_{DD}, 0)$ ve $(0, V_{DD}/R_D)$.
- $V_{GS} = 0$ ise $I_D = I_{DSS}$ (JFET ve D-MOSFET).
- Q noktasındaki $I_{D_Q}$ ile $V_D$, $V_S$, $V_{DS}$ hesaplanır.

## Detaylı Açıklamalar

FET'lerin kutuplama analizi BJT'ye benzer, ama bir kolaylığı ve bir zorluğu vardır. Kolaylık, kapı akımının sıfır kabul edilmesidir: drenden giren akım aynen kaynaktan çıkar ($I_D = I_S$), bu yüzden dren-kaynak devresinde KVL yazarken iki direnç ortak parantezde toplanabilir. Zorluk, $I_D$ ile $V_{GS}$ arasındaki ilişkinin doğrusal olmamasıdır (karesel). Bu yüzden Q noktası genelde iki eğrinin kesişimi olarak grafikle bulunur: biri elemanın transfer eğrisi, öteki devrenin dirençlerinden gelen kutuplama doğrusu. Hoca bunu şöyle özetledi: sol taraftaki eğri elemanın veri sayfasından gelen karakteristiğidir; doğru ise bu dirençlerle elemanın nasıl çalışacağını söyler, kesişim de bu dirençlerle geçen akımdır.

Transfer eğrisi çizimi için örnek: $I_{DSS} = 12$ mA, $V_P = -6$ V (ekrandan, 01:10:00). Noktalar $(0;\ 12\text{ mA})$, $(-6\text{ V};\ 0)$, $(-3\text{ V};\ 3\text{ mA})$ ve $(-1{,}8\text{ V};\ 6\text{ mA})$'dir. (Python kontrolü: $V_{GS} = -1{,}8$ V'ta tam değer 5,88 mA'dir; $0{,}3V_P$ kuralı yaklaşık bir kuraldır.)

Sabit kutuplamalı JFET örneği (ekrandan, 01:15:00): $V_{DD} = 16$ V, $R_D = 2$ kΩ, $V_{GG} = 2$ V, $I_{DSS} = 10$ mA, $V_P = -8$ V. $V_{GS_Q} = -2$ V; $I_{D_Q} = 10(1 - 0{,}25)^2 = 5{,}625$ mA; $V_{DS} = 16 - 5{,}625 \cdot 2 = 4{,}75$ V; $V_D = V_{DS} = 4{,}75$ V; $V_G = -2$ V; $V_S = 0$.

Gerilim bölücülü JFET örneği (ekrandan, 01:20:00): $V_{DD} = 16$ V, $R_1 = 2{,}1$ MΩ, $R_2 = 270$ kΩ, $R_D = 2{,}4$ kΩ, $R_S = 1{,}5$ kΩ, $I_{DSS} = 8$ mA, $V_P = -4$ V. $V_G = 1{,}82$ V; doğru $(1{,}82\text{ V};\ 0)$ ile $(0;\ 1{,}21\text{ mA})$ noktalarından geçer. Kesişim $I_{D_Q} = 2{,}4$ mA, $V_{GS_Q} = -1{,}8$ V. Buradan $V_D = 10{,}24$ V, $V_S = 3{,}6$ V, $V_{DS} = 6{,}64$ V, $V_{DG} = 8{,}42$ V.

Gerilim bölücülü D tipi MOSFET örneği (ekrandan, 01:25:00): $V_{DD} = 18$ V, $R_1 = 110$ MΩ, $R_2 = 10$ MΩ, $R_D = 1{,}8$ kΩ, $R_S = 750$ Ω, $I_{DSS} = 6$ mA, $V_P = -3$ V. $V_G = 18 \cdot 10/120 = 1{,}5$ V; doğru $(1{,}5\text{ V};\ 0)$ ve $(0;\ 2\text{ mA})$'den geçer. Eğri $V_{GS} = +1$ V'ta $6(4/3)^2 = 10{,}67$ mA'e uzatılır. Kesişim $I_{D_Q} \approx 3{,}1$ mA, $V_{GS_Q} \approx -0{,}8$ V (ekrandan, 01:00:00). $V_{DS} = 18 - 3{,}1(1{,}8 + 0{,}75) \approx 10{,}1$ V (python ile hesaplandı).

Kendinden kutuplamalı D tipi MOSFET örneği (ekrandan, 01:40:00): $V_{DD} = 20$ V, $R_D = 6{,}2$ kΩ, $R_G = 1$ MΩ, $R_S = 2{,}4$ kΩ, $I_{DSS} = 8$ mA, $V_P = -8$ V. $V_{GS} = -I_D R_S$ doğrusu orijinden geçer; ikinci nokta için $V_{GS} = -6$ V alınır, $I_D = 6/2{,}4 = 2{,}5$ mA. Kesişim $I_{D_Q} \approx 1{,}7$ mA, $V_{GS_Q} \approx -4{,}3$ V; $V_D = 20 - 1{,}7 \cdot 6{,}2 = 9{,}46$ V.

$V_{GS} = 0$ olan D tipi MOSFET örneği (ekrandan, 01:45:00): kapı doğrudan kaynağa bağlı olduğu için $V_{GS} = 0$, dolayısıyla $I_D = I_{DSS} = 10$ mA. $V_{DD} = 20$ V, $R_D = 1{,}5$ kΩ için $V_{DS} = V_D = 20 - 15 = 5$ V. Transfer eğrisi çizmeye gerek yoktur.

E tipi MOSFET örneğinde $V_T = 3$ V'tur ve $k$ verilmemiştir; eğri üzerinde verilen bir noktadan $k \approx 0{,}24$ mA/V² bulunur. Ardından geri beslemeli devrede $V_{GS} = V_{DD} - I_D R_D$ doğrusu çizilir; $I_D = 0$ için $V_{GS} = 12$ V bulunur. <!-- BELİRSİZ: Verilen nokta altyazıda "16 mA, 18 V" diye geçiyor, ama bu değerler k = 0,24 mA/V² sonucunu vermiyor (16/15² ≈ 0,071). 0,24 sonucuyla tutarlı nokta büyük olasılıkla I_D = 6 mA, V_GS = 8 V'tur; bu anın karesi yok. -->

> **Ders sonrası not:** D tipi MOSFET'te pozitif $V_{GS}$ bölgesinin adı kitaplarda zenginleşme (enhancement) bölgesidir; negatif $V_{GS}$ tarafı ise fakirleşme (depletion) bölgesidir. Hoca pozitif tarafa "depletion bölgesi" dedi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
