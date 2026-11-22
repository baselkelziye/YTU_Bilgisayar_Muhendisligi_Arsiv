# Ders 2 Çalışma Özeti

## Genel Konular

- Önceki dersin kısa tekrarı
  - Akım, yükün zamana göre değişimidir: $i = \dfrac{dq}{dt}$, birimi amper ($1\ \text{A} = 1\ \text{C/s}$).
  - Elektronlar eksi uçtan artı uca doğru hareket eder. Devre analizinde kullanılan akım yönü elektron hareketinin tersidir.
  - Bir elemanın gücü $p = v\,i$ ile bulunur. Gücü tüketen (soğuran) elemanın gücü artı, üreten elemanın gücü eksi işaretle yazılır. Üretilen toplam güç tüketilen toplam güce eşittir.
- Direnç, özdirenç ve malzemeler
  - Her malzeme yük hareketine karşı bir direnç gösterir. Bu etki malzemenin özdirenci $\rho$ ile ölçülür.
  - Oda sıcaklığında (300 K) özdirenç tablosu (ekrandan, 00:25:00): gümüş $1{,}64\times10^{-8}$, bakır $1{,}72\times10^{-8}$, alüminyum $2{,}8\times10^{-8}$, altın $2{,}45\times10^{-8}$, karbon (grafit) $4\times10^{-5}$ (iletkenler); germanyum $0{,}47$, silisyum $640$ (yarı iletkenler); kağıt $10^{10}$, mika $5\times10^{11}$, cam $10^{12}$, teflon $3\times10^{12}$ (yalıtkanlar). Birim $\Omega\cdot\text{cm}$.
  - Gümüş bakırdan iyi iletkendir, ama bakır daha ucuz ve kolay bulunduğu için teller bakırdan yapılır.
  - Yarı iletkenler ikinci sınıftaki elektronik dersinin konusudur. Devre teorisi iletkenler ve dirençlerle ilgilenir.
  - Bir iletkenin direnci: $R = \rho\dfrac{L}{A}$. Uzunluk ($L$) arttıkça direnç artar, kesit alanı ($A$) arttıkça direnç azalır.
- Ohm yasası
  - $v = iR$ (ekrandan, 00:30:00). Birimler: $\text{V} = \text{A}\,\Omega$, $\text{A} = \text{C/s}$.
  - Akım dirençli bir elemandan geçerken elemanın uçları arasında akımla orantılı bir gerilim oluşur.
- Kısa devre ve açık devre
  - Kısa devre: direnci sıfır olan yol. $R = 0$ olduğu için üzerinde gerilim oluşmaz.
  - Açık devre: direnci sonsuz olan yol. $i = \lim_{R\to\infty} v/R = 0$, akım geçmez.
  - İkisinde de güç ($p = vi$) sıfırdır.
- İletkenlik (conductance)
  - $G = R^{-1} = i/v$. Birimi siemens (S) ya da mho ($\mho$) (ekrandan, 00:35:00).
  - $G = A\sigma/L$; burada $\sigma = 1/\rho$ iletkenlik katsayısıdır.
- Güç formülleri
  - $p = vi = i^2R = \dfrac{v^2}{R} = \dfrac{i^2}{G} = v^2 G$.
- Devre terminolojisi (ekrandan, 00:40:00)
  - Düğüm (node): iki ya da daha çok elemanın ortak bağlandığı nokta. Aralarında eleman olmayan bağlantı noktaları tek düğüm sayılır.
  - Yol (path): düğümlerin tekrar etmediği güzergah (örnek $1\to3\to2$).
  - Çevre/döngü (loop): aynı düğümde başlayıp biten yol (örnek $3\to1\to2\to3$).
  - Kol (branch): tek eleman ve iki uç düğümden oluşan yol (örnek $1\to2$, $1\to3$, $3\to2$).
- Kirchhoff'un akım yasası (KCL)
  - Bir düğüme giren akımların toplamı çıkan akımların toplamına eşittir; düğümdeki akımların cebirsel toplamı sıfırdır: $\sum i = 0$.
  - Yükün korunumuna dayanır. KCL düğümler üzerinde uygulanır.
- Kirchhoff'un gerilim yasası (KVL)
  - Bir döngüdeki elemanların gerilimlerinin cebirsel toplamı sıfırdır: $\sum_{m=1}^{M} v_m = 0$, ya da $\sum v_{\text{düşüm}} = \sum v_{\text{yükselme}}$ (ekrandan, 00:50:00).
  - Enerjinin korunumuna dayanır. KVL döngüler üzerinde uygulanır.
- KCL ve KVL örnekleri (Example-01 ile Example-11 arası slaytlar)
  - KCL ile tek düğümde bilinmeyen akım bulma, eksi çıkan akımın yorumlanması.
  - Gerilim düşümleri verildiğinde Ohm yasasıyla akımları bulup KCL uygulama.
  - KVL ile tek döngü, çok döngülü devre ve "kara kutu" elemanlı devrelerde gerilim bulma.

## Hocanın Özellikle Vurguladığı Kısımlar

- Akım değerinin önündeki işaret yönü gösterir
  - Hesap sonunda akım eksi çıkarsa, akımın gerçek yönü şekilde çizilen okun tersidir. "−2 A" ile ters yönlü "2 A" aynı akımdır.
  - Akımı tanımlayan iki şey vardır: büyüklüğü ve yönü. Büyüklüğü doğru bulup yönü yanlış göstermek yanlış çözümdür.
- Polarizasyon (kutuplaşma) KCL ve KVL'nin kritik noktasıdır
  - Direnç gibi tüketen elemanda akım artı uçtan girer, eksi uçtan çıkar.
  - Akım bir kaynağın artı ucundan çıkıyorsa kaynak güç üretir. Akım artı uçtan giriyorsa kaynak güç tüketir.
  - Her gerilim kaynağı güç üretmek zorunda değildir. Ters bağlı bir pil (örneğin 9 V'luk pile ters bağlı 3 V'luk pil) güç tüketir.
- Döngü yönü bir kabuldür
  - Her döngü için bir yön seçilir ve bütün döngülerde aynı yön (örneğin saat yönü) ve aynı işaret kuralı kullanılır.
  - Hocanın genelde kullandığı kural: akım bir elemana eksi ucundan giriyorsa gerilim eksi, artı ucundan giriyorsa artı yazılır.
  - Soruda verilmiş polariteler değiştirilmez. Verilmemişse, seçilen akım yönüne göre dirence artı-eksi konur.
  - Bir direnç bir döngüde artıdan, komşu döngüde eksiden girilen eleman olabilir; bu yüzden "direnç her zaman artı yazılır" diye düşünülmemelidir.
- İki nokta arasındaki gerilim sorulduğunda o noktaların ötesindeki elemanlar tek tek çözülmek zorunda değildir; bir kara kutu gibi düşünülüp döngü öteki taraftan kapatılabilir.
- Bir elemana doğrudan paralel bağlı elemanın gerilimi aynıdır.
- Çözümde yalnız sonuç değil, akım yönleri ve adımlar gösterilmelidir.

## Kısa Tekrar Notları

- $i = dq/dt$, $v = iR$, $R = \rho L/A$, $G = 1/R = A\sigma/L$.
- $p = vi = i^2R = v^2/R = v^2G = i^2/G$.
- Tüketen elemanın gücü $+$, üreten elemanın gücü $-$; $\sum p_{\text{üretilen}} = \sum p_{\text{tüketilen}}$.
- Kısa devre: $R = 0$, $v = 0$. Açık devre: $R = \infty$, $i = 0$. İkisinde de güç sıfır.
- Düğüm, yol (düğüm tekrarı yok), döngü (başlangıç = bitiş), kol (tek eleman).
- KCL: düğümde $\sum i_{\text{giren}} = \sum i_{\text{çıkan}}$. KVL: döngüde $\sum v = 0$.
- Eksi sonuç = seçilen yön ya da polarite ters.
- Örnek sonuçları: Example-01 $i = 6$ A; Example-02 $i_B = 4$ A, $i_E = 0$; Example-04 $I = -1{,}6$ mA; Example-05 $I \approx -2{,}06$ mA; Example-06 $v_x = 12$ V, $i_x = 120$ mA ve $v_x = -4$ V, $i_x = -0{,}4$ A; Example-07 $v_{R2} = 32$ V, $v_x = 6$ V; Example-08 $v_{R2} = 20$ V; Example-09 $v_x = 8$ V; Example-10 $|v_{R1}| = 2$ V; Example-11 $v_{R2} = 9{,}1$ V, $i \approx 1{,}94$ mA.

## Detaylı Açıklamalar

- **Güç işareti ve polarizasyon.** Tek kaynak ve tek elemandan oluşan bir devrede akım kaynağın artı ucundan çıkar, elemana artı ucundan girer ve elemanı "girdiği taraf artı, çıktığı taraf eksi" olacak biçimde kutuplar. Kaynağın gücü $-P$ (üretilen), elemanın gücü $+P$ (tüketilen) yazılır ve toplam sıfırdır. Pratikte üretilen gücün bir kısmı ısı olarak kaybolur, ama derste teorik olarak üretilen ve tüketilen güç eşit kabul edilir.

- **Direnci azaltmanın yolları.** $R = \rho L/A$ formülüne göre bir elemanın direnci üç yolla düşürülebilir: kesit alanını büyütmek, daha iyi iletken bir malzeme kullanarak $\rho$'yu düşürmek, uzunluğu kısaltmak.

- **Terminoloji alıştırması** (ekrandan, 00:45:00). Şekildeki devrede 5 direnç ve 1 gerilim kaynağı, toplam 6 eleman vardır. $B\to C\to D$ hareketi bir yoldur, döngü değildir; döngü olması için $E$ üzerinden $B$'ye dönmek gerekir. $E\to D\to C\to B\to E$ hareketi başladığı düğüme döndüğü için bir döngüdür.

- **KCL örnekleri.**
  - Example-01 (ekrandan, 00:55:00): 10 V'luk kaynak 3 A veriyor, $R_2$'den aşağı 2 A iniyor. Üst düğümde $3 = 2 + 1$, yani sağa 1 A gider. Sonraki düğümde 1 A ile 5 A'lık akım kaynağının akımı birleşir: $R_3$'ten geçen akım $i = 6$ A.
  - Example-02 (ekrandan, 01:00:00): $i_A + i_B - i_C - i_D - i_E = 0$. (a) $i_A = 1$, $i_D = -2$, $i_C = 3$, $i_E = 4$ A için $i_B = -1 + 3 - 2 + 4 = 4$ A. (b) $i_A = i_B = i_C = i_D = -1$ A için $i_E = -1 - 1 + 1 + 1 = 0$ A.
  - Example-03 (altyazıdan, 01:00:24): düğümden 3 mA çıkıyor, 0,5 mA, 1,9 mA ve kaynağın $I$ akımı giriyor. $I = 3 - 0{,}5 - 1{,}9 = 0{,}6$ mA. Akım 3 V'luk kaynağın artı ucundan çıktığı için kaynak güç üretir. <!-- BELİRSİZ: Example-03 şekli karelerde yok; değerler altyazıdan alındı. -->
  - Example-04 (ekrandan, 01:05:00): $R_2$'nin 3 mA'i düğüme giriyor, $R_3$'ün 1,9 mA'i düğümden çıkıyor, $R_1$'den 0,5 mA giriyor. $3 + 0{,}5 - 1{,}9 + I = 0 \Rightarrow I = -1{,}6$ mA. Akımın gerçek yönü aşağı doğrudur, yani 3 V'luk kaynağa artı ucundan girer; kaynak güç tüketir: $P = 1{,}6\ \text{mA}\times 3\ \text{V} = 4{,}8$ mW.
  - Example-05 (ekrandan, 01:10:00): akımlar yerine gerilim düşümleri verilmiş. $R_1 = 7\ \text{k}\Omega$ üzerinde 2 V, $R_2 = 2\ \text{k}\Omega$ üzerinde 4 V, $R_3 = 5\ \text{k}\Omega$ üzerinde 1,75 V (altyazıdan). Ohm yasasıyla $i_{R1} \approx 0{,}286$ mA (düğümden çıkar), $i_{R2} = 2$ mA (girer), $i_{R3} = 0{,}35$ mA (girer). KCL: $2 + 0{,}35 + I = 0{,}286 \Rightarrow I \approx -2{,}06$ mA.

- **KVL örnekleri.**
  - Example-06 (ekrandan, 01:30:00): sol devrede saat yönünde $-5 - 7 + v_x = 0 \Rightarrow v_x = 12$ V, $i_x = 12/100 = 120$ mA. Sağ devrede $3 + 1 + v_x = 0 \Rightarrow v_x = -4$ V, $i_x = -0{,}4$ A: şekildeki polarite ve akım yönü terstir; direncin üzerinde 4 V vardır, akım 400 mA'dir ve saat yönünün tersine akar.
  - Example-07 (ekrandan, 01:35:00): sol döngüde $4 - 36 + v_{R2} = 0 \Rightarrow v_{R2} = 32$ V. Sağdaki büyük döngüde $a$-$b$ arasının sağı kara kutu sayılır: $-32 + 12 + 14 + v_x = 0 \Rightarrow v_x = 6$ V.
  - Example-08 (ekrandan, 01:40:00): sol direncin gerilimi soruda $-8$ V verilmiş, işareti değiştirilmeden yazılır: $-8 - 12 + v_{R2} = 0 \Rightarrow v_{R2} = 20$ V. Derste sağ döngüde $-20 + 7 - 9 - v_2 - 3 + 1 = 0$ yazılarak $v_2 = -24$ V bulundu.
  - Example-09 (ekrandan, 01:55:00): $8\ \Omega$'dan 5 A geçtiği için $v_8 = 40$ V. $60 - 40 - v_{10} = 0 \Rightarrow v_{10} = 20$ V, $i_{10} = 2$ A, KCL ile $i_4 = 3$ A, $v_4 = 12$ V. $20 - 12 - v_2 = 0 \Rightarrow v_2 = 8$ V. Akım kaynağı $2\ \Omega$'a paralel olduğu için $v_x = 8$ V.
  - Example-10 (ekrandan, 02:00:00): $R_2$ akım kaynağına paralel olduğu için gerilimi 3 V'tur. Yeşil döngüde $-5 - v_{R1} + 3 = 0$.
  - Example-11 (ekrandan, 02:10:00 ve 02:15:00): sol döngüde $v_{R2} = 11{,}5 - 2{,}4 = 9{,}1$ V. Sağ döngüde $v_{R3} = 1\ \text{mA}\times1{,}1\ \text{k}\Omega = 1{,}1$ V ve $v_{R2} = 1{,}1 + 8 = 9{,}1$ V. $i_{R2} = 9{,}1/4{,}7\ \text{k}\Omega \approx 1{,}94$ mA. Üst düğümde KCL ile $R_1$ akımı $1{,}94 + 1 = 2{,}94$ mA.

- **Ders sonrası notlar.**
  - Example-04'te hoca gücü "4,8 watt" diye söyledi. Akım miliamper olduğu için doğrusu $4{,}8$ mW'tır.
  - Example-06'nın sağ devresinde hoca önce "eksi 1 amper" dedi, sonra 400 mA'e düzeltti. Doğrusu $-4\ \text{V}/10\ \Omega = -0{,}4$ A'dir.
  - Example-08'de slayttaki soru $v_{R1} = 1$ V iken $v_x$'i ($a$-$b$ arası) soruyor; derste $v_2 = -24$ V bulundu. Aynı değerlerle $v_x$: $-20 + 7 - 9 + v_x = 0 \Rightarrow v_x = 22$ V (python ile kontrol edildi).
  - Example-10'da slaytta $-5 - v_{R1} + 3 = 0$ denkleminden "$v_{R1} = 2$ V" yazıyor. Bu denklemin çözümü $v_{R1} = -2$ V'tur: slayttaki polariteyle ($-\ v_{R1}\ +$) gerilim $-2$ V, ters polariteyle 2 V'tur. Bir öğrenci bunu sordu, hoca da sonunda bunu kabul etti.
  - Hoca kısa devreyi anlatırken bir yerde "akım geçmeyen kol" dedi; aynı anlatımda ve ders sonunda doğrusunu söyledi: kısa devrede gerilim sıfırdır, akım geçmeyen yol açık devredir. İdeal kaynağı doğrudan kısa devre etmek teorik olarak sonsuz akım demektir.
  - Hoca $10^{-8}$ için "milyarda bir" dedi; $10^{-8}$ yüz milyonda birdir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
