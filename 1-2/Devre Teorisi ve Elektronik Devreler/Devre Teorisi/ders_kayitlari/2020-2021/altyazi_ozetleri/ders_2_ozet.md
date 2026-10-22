# Ders 2 Çalışma Özeti

## Genel Konular

- İkinci hafta (18 Mart 2021 Perşembe). Konular: direnç ve iletkenlik, devre topolojisi, Kirchhoff yasaları, tek çevreli ve tek düğüm çiftli devreler, seri ve paralel bağlama.
- Direnç ve özdirenç
  - Bir iletkenin direnci malzemeye, uzunluğa ve kesit alanına bağlıdır: $R = \rho \frac{L}{A}$.
  - $\rho$ özdirençtir (resistivity). Slayttaki tabloda Ω·cm biriminde verilir. Uzunluk arttıkça direnç artar, kesit alanı arttıkça azalır.
  - Kısa devre: $R = 0$. Üzerinde gerilim düşmez, akım herhangi bir değer olabilir.
  - Açık devre: $R = \infty$. Üzerinden akım geçmez, uçları arasında herhangi bir gerilim olabilir.
- İletkenlik
  - İletkenlik (conductance) direncin tersidir: $G = \frac{1}{R}$. Birimi siemens (S) veya mho (℧).
  - Ohm kanunu iletkenlikle $i = G v$ olarak yazılır.
  - Özdirencin tersi öziletkenliktir (conductivity): $\sigma = \frac{1}{\rho}$.
- Dirençte güç
  - $p = vi = i^2 R = \frac{v^2}{R} = \frac{i^2}{G} = v^2 G$.
  - $R$ ve $G$ her zaman pozitiftir. Akım ve gerilim formüllerde karesiyle yer alır. Bu yüzden direnç her zaman güç çeker. Bu güç ısıya dönüşür.
  - Kısa devre ($v = 0$) ve açık devre ($i = 0$) güç harcamaz.
- Devre topolojisi
  - Düğüm (node): iki veya daha fazla elemanın birleştiği nokta. Bir kabloyla birbirine bağlı noktalar tek bir düğümdür.
  - Yol (path): bir düğümden başlayıp elemanlar üzerinden ilerleyen, hiçbir düğümden iki kez geçmeyen dizi.
  - Çevre (loop): başladığı düğümde biten kapalı yol.
  - Kol (branch): tek bir eleman ve onun iki ucu.
  - Slayttaki örnekte a'dan g'ye kadar harflenmiş noktalar var. Aralarında yalnızca kablo bulunan noktalar (ör. D ile E; C, F ve G) aynı düğümdür.
- Kirchhoff Akım Yasası (KCL)
  - Bir düğüme giren akımların toplamı, çıkan akımların toplamına eşittir. Eşdeğeri: bir düğümdeki akımların cebirsel toplamı sıfırdır.
  - Dayanağı yükün korunumudur. Düğümde yük birikmez.
- Kirchhoff Gerilim Yasası (KVL)
  - Herhangi bir kapalı çevre boyunca gerilimlerin cebirsel toplamı sıfırdır.
  - Dayanağı enerjinin korunumudur. Bir yükü çevre boyunca dolaştırıp başlangıç noktasına getirmek için net iş gerekmez.
  - Yazım kuralı: çevre yönünde ilerlerken bir elemana artı ucundan girilirse gerilim artı, eksi ucundan girilirse eksi işaretle yazılır.
  - Gerilim bir yoldan bağımsızdır. İki düğüm arasındaki gerilim, hangi yol üzerinden hesaplanırsa hesaplansın aynıdır. Bu yüzden çevre seçiminde esneklik vardır.
- Tek çevreli devreler
  - Bütün elemanlardan aynı akım geçer. Tek bir akım tanımlanır ve KVL ile çözülür.
  - Bağımlı kaynak, herhangi bir eleman gibi KVL denklemine yazılır. Kontrol değişkeni ana kol akımı cinsinden ifade edilir.
- Tek düğüm çiftli devreler
  - Bütün elemanlar aynı iki düğüm arasına bağlıdır. Hepsinin uçları arasında aynı gerilim vardır. Tek bir gerilim tanımlanır ve KCL ile çözülür.
- Seri ve paralel bağlama
  - Seri: iki eleman tek bir ortak düğümü paylaşır ve o düğüme başka eleman bağlı değildir. Seri elemanlardan aynı akım geçer.
  - Paralel: iki eleman aynı iki düğüm arasına bağlıdır. Paralel elemanların uçlarında aynı gerilim vardır.
  - Seri ve paralellik tekil elemanlar arasında olduğu gibi eleman grupları arasında da tanımlanır.
- Kaynakların birleştirilmesi
  - Seri gerilim kaynakları yönleriyle birlikte toplanır ve tek bir kaynakla değiştirilebilir.
  - Paralel akım kaynakları yönleriyle birlikte toplanır ve tek bir kaynakla değiştirilebilir.
  - Farklı değerli gerilim kaynakları paralel bağlanamaz (KVL çiğnenir). Yalnızca aynı değer ve yöndeki kaynaklar paralel bağlanabilir.
  - Farklı değerli akım kaynakları seri bağlanamaz (KCL çiğnenir).
- Eşdeğer direnç
  - Seri: $R_{eş} = R_1 + R_2 + \dots + R_N$. İletkenlikle $\frac{1}{G_{eş}} = \frac{1}{G_1} + \dots + \frac{1}{G_N}$.
  - Paralel: $\frac{1}{R_{eş}} = \frac{1}{R_1} + \dots + \frac{1}{R_N}$. İletkenlikle $G_{eş} = G_1 + \dots + G_N$.
  - İki paralel direnç için $R_{eş} = \frac{R_1 R_2}{R_1 + R_2}$. $N$ tane eşit $R$ paralel bağlanırsa $R_{eş} = \frac{R}{N}$.
  - Eşdeğer direnç, devreye iki terminalden bakıldığında görülen dirençtir. Bu "terminalden bakma" fikri ileride Thevenin eşdeğerinde kullanılacak.
  - Seri dirençlerde güç dirençle doğru orantılıdır ($p = i^2 R$, aynı akım). Paralel dirençlerde güç dirençle ters orantılıdır ($p = \frac{v^2}{R}$, aynı gerilim).
  - Multimetre ohmmetre konumunda direnç ölçerken devrenin enerjisi kesilmelidir.
- Eleman sayısının ve değerinin etkisi
  - Her direncin değeri artırılırsa hem seri hem paralel bağlamada eşdeğer direnç artar.
  - Aynı değerli direnç sayısı artırılırsa seri bağlamada eşdeğer direnç artar, paralel bağlamada azalır.
- Dualite
  - Seri ↔ paralel, direnç ↔ iletkenlik, gerilim ↔ akım, KVL ↔ KCL, kısa devre ↔ açık devre, gerilim kaynağı ↔ akım kaynağı.
  - Bir yapı için bulunan formül, dual yapıda karşılıkları yerine konarak aynen kullanılır.
- Gerilim ve akım bölücüler gelecek haftaya kaldı. Ders sonunda Classroom ve laboratuvar duyuruları yapıldı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Referans yönlerine dikkat edin. KVL'de elemana artı ucundan girildiyse artı, eksi ucundan girildiyse eksi yazın. Bağımlı kaynağın kontrol gerilimi ters yönde tanımlandıysa bu da ayrıca bir eksi işareti getirir.
- Akım kaynağının uçlarındaki gerilim devrenin geri kalanı tarafından belirlenir. Bu yüzden akım kaynağı içeren bir çevrede KVL yazmak yerine, akım kaynağından geçmeyen bir çevre seçmek işi kolaylaştırır.
- Gerilim kaynağının akımı da devrenin geri kalanı tarafından belirlenir. Hesaplanan güç negatif çıkmayabilir. Kaynak güç çekiyor olabilir (şarj edilen akü gibi).
- Bağımlı kaynağı devreye diğer elemanlar gibi katın. Sonra kontrol değişkenini ana akım veya ana gerilim cinsinden yazın.
- Devrede bütün elemanların güçleri toplamı sıfır olmalıdır. Sonucu bu toplamla kontrol edin.
- Farklı değerli gerilim kaynaklarını paralel bağlamayın. Hoca bir kuru aküyü yanlışlıkla ters yönde şarj ettiğini ve akünün kutuplarının ters döndüğünü anlattı.
- Multimetreyle direnç ölçerken devrenin enerjisini kesin.

## Kısa Tekrar Notları

- $R = \rho \frac{L}{A}$, $G = \frac{1}{R}$ (S), $\sigma = \frac{1}{\rho}$.
- $p = i^2 R = \frac{v^2}{R} = v^2 G$. Direnç her zaman güç çeker.
- KCL: düğümdeki akımların cebirsel toplamı 0.
- KVL: çevredeki gerilimlerin cebirsel toplamı 0.
- Seri: aynı akım. Paralel: aynı gerilim.
- Seri $R$ toplanır, paralel $G$ toplanır.
- Seri gerilim kaynakları ve paralel akım kaynakları yönlü olarak toplanır.
- Kısa devre $R = 0$, açık devre $R = \infty$. İkisi de güç harcamaz.

## Detaylı Açıklamalar

### KCL örnekleri

- **Örnek 1:** Bir düğüme 10 V'luk bir gerilim kaynağı, $R_1$, $R_2$, $R_3$ ve 5 A'lik bir akım kaynağı bağlı.
  - Gerilim kaynağının kolundan düğüme 3 A giriyor. $R_2$'den 2 A çıkıyor. Akım kaynağı düğüme 5 A veriyor. $R_3$'ten $i$ çıkıyor.
  - KCL: $3 - 2 - i + 5 = 0$, buradan $i = 6$ A.
- **Örnek 3:** Bir düğüme 1.9 mA, 0.5 mA ve bilinmeyen $I$ giriyor, 3 mA çıkıyor. $I$, 3 V'luk $V_1$ kaynağının akımıdır.
  - KCL: $1.9 + 0.5 + I = 3$, buradan $I = 0.6$ mA.
  - Akım kaynağın artı ucundan çıkar. Kaynağın çektiği güç $p = -(3)(0.6) = -1.8$ mW, yani kaynak 1.8 mW verir.
  - Değerler değişip $I = -1.6$ mA çıkarsa akım kaynağın artı ucundan girer. Kaynak güç çeker, şarj olan bir akü gibi davranır.
- **Örnek 5:** $R_1 = 7$ kΩ (2 V), $R_2 = 2$ kΩ (4 V), $R_3 = 5$ kΩ (1.75 V), $V_1 = 3$ V.
  - $I_1 = \frac{2}{7} = 0.286$ mA, $R_2$ akımı $\frac{4}{2} = 2$ mA, $R_3$ akımı $\frac{1.75}{5} = 0.35$ mA.
  - KCL: $0.286 = I + 2 + 0.35$, buradan $I = -2.064$ mA.
  - $I$ negatif çıktığı için gerçek akım ters yöndedir. $V_1$ kaynağı güç çeker.

### KVL örnekleri

- **Tek çevre, 100 Ω:** 5 V ve 7 V'luk iki kaynak ile 100 Ω'luk bir direnç seri. KVL: $-5 - 7 + V_x = 0$, buradan $V_x = 12$ V ve $i = \frac{12}{100} = 0.12$ A.
- **Tek çevre, 10 Ω:** KVL: $3 + 1 + V_x = 0$, buradan $V_x = -4$ V ve $I_x = \frac{-4}{10} = -0.4$ A. Eksi işaret, gerçek yönün seçilen referansın tersi olduğunu gösterir.
- **Örnek 7 (iki gözlü devre):** Soldaki çevrede 4 V ve 36 V'luk elemanlar ile $R_2$ var.
  - Sol çevre: $4 - 36 + v_{R2} = 0$, buradan $v_{R2} = 32$ V.
  - Büyük çevre ($R_2$, 12 V'luk direnç, 14 V'luk eleman ve $a$-$b$ arasındaki $v_x$): $-32 + 12 + 14 + v_x = 0$, buradan $v_x = 6$ V.
- **Örnek 8:** Devrenin solunda üstte − + yönlü 12 V'luk kaynak, sol kolda −8 V'luk bir eleman, ortada $R_2$ ($v_{R2}$, artısı üstte) var. Üst hatta 7 V'luk direnç, − + yönlü 9 V'luk bir eleman, $a$ düğümü, − + yönlü $v_2$ elemanı ve sağ kolda eksisi üstte 3 V'luk kaynak ile $R_1$ ($v_{R1}$, artısı üstte) var. $v_x$, $a$ ile $b$ arasındadır.
  - a) Sol çevre: $-8 - 12 + v_{R2} = 0$, buradan $v_{R2} = 20$ V.
  - b) Slaytta büyük çevre yazılmış: $-20 + 7 - 9 - v_2 - 3 + v_{R1} = 0$. $v_{R1} = 1$ V için $v_2 = -24$ V.
  - Soruda $v_x$ istendiği hâlde slayt $v_2$'yi bulmuş. Hoca soruda hata olduğunu söyleyip $v_2$ sorulmuş gibi düzeltti. $v_x$'in hesabı aşağıda, ders sonrası notlarda.
- **Örnek 9 (üç gözlü devre):** 60 V'luk kaynak, seri 8 Ω (üzerinden 5 A geçiyor), ortada 10 Ω, üst hatta 4 Ω ($i_4$), sonra 2 Ω ve en sağda $v_x$ gerilimli bir akım kaynağı ($i_x$).
  - 1. çevre: $-60 + v_8 + v_{10} = 0$. $v_8 = 8 \cdot 5 = 40$ V olduğu için $v_{10} = 20$ V.
  - $i_{10} = \frac{20}{10} = 2$ A. KCL: $i_4 = 5 - 2 = 3$ A. $v_4 = 4 \cdot 3 = 12$ V.
  - 2 Ω'luk direncin akımı bilinmediği için ikinci göz yerine 10 Ω, 4 Ω ve akım kaynağından geçen çevre seçilir: $-v_{10} + v_4 + v_x = 0$, buradan $v_x = 20 - 12 = 8$ V.
  - Slaytlardaki bazı kaynaklar AC sembolüyle çizilmiş. Değerleri sabit olduğu için bunlar DC kaynaktır.
- **Enerjinin korunumu slaytı:** Elemanların güçleri toplanınca $-56 + 16 - 60 + 160 - 60 = 0$ çıkar.

### Bağımlı kaynaklı tek çevreli devreler

- **Örnek 1:** 120 V'luk kaynak, 30 Ω, artı ucu solda olan $2v_A$ değerli bağımlı gerilim kaynağı ve 15 Ω seri. $v_A$, 15 Ω'luk direncin üzerinde, artısı altta olacak şekilde tanımlı.
  - Çevre akımı $i$ saat yönünde. KVL: $-120 + 30i + 2v_A - v_A = 0$.
  - $v_A$ referansı akım yönünün tersi olduğu için $v_A = -15i$. Yerine konunca $-120 + 15i = 0$, buradan $i = 8$ A ve $v_A = -120$ V.
  - Güçler (çekilen güç):
    - 120 V'luk kaynak: $-120 \cdot 8 = -960$ W (verir).
    - 30 Ω: $8^2 \cdot 30 = 1920$ W.
    - 15 Ω: $8^2 \cdot 15 = 960$ W.
    - Bağımlı kaynak: $(2v_A) \cdot i = (-240)(8) = -1920$ W (verir).
    - Toplam: $-960 + 1920 + 960 - 1920 = 0$.
- **Örnek 2:** 30 Ω ($v_x$), 12 V'luk kaynak, 8 Ω, 7 Ω ve $4v_x$ değerli bağımlı gerilim kaynağı seri.
  - KVL: $-v_x - 12 + 8i + 7i + 4v_x = 0$. Çevre yönü $v_x$ referansına ters olduğu için $v_x = -30i$.
  - $-90i - 12 + 15i = 0$, buradan $i = -\frac{4}{25} = -0.16$ A ve $v_x = \frac{24}{5} = 4.8$ V.
  - Güçler (çekilen güç):
    - 30 Ω: $\frac{(24/5)^2}{30} = 0.768$ W.
    - 12 V'luk kaynak: $1.92$ W (çeker).
    - 8 Ω: $(-0.16)^2 \cdot 8 = 0.2048$ W.
    - 7 Ω: $(-0.16)^2 \cdot 7 = 0.1792$ W.
    - Bağımlı kaynak: $4v_x \cdot i = (19.2)(-0.16) = -3.072$ W (verir).
    - Toplam: $0.768 + 1.92 + 0.2048 + 0.1792 - 3.072 = 0$.

### Tek düğüm çiftli devreler

- **Örnek 3:** Yukarı yönlü 120 A'lik kaynak, $R_1 = \frac{1}{30}$ Ω, aşağı yönlü 30 A'lik kaynak, $R_2 = \frac{1}{15}$ Ω paralel. Üst düğüm $v$.
  - İletkenlikler 30 S ve 15 S olduğu için $i_1 = 30v$, $i_2 = 15v$.
  - KCL: $-120 + 30v + 30 + 15v = 0$, buradan $v = 2$ V. $i_1 = 60$ A, $i_2 = 30$ A.
  - Güçler: $p_{R1} = 30 \cdot 2^2 = 120$ W, $p_{R2} = 15 \cdot 2^2 = 60$ W, $p_{120A} = -240$ W (verir), $p_{30A} = 60$ W (çeker). Toplam 0.
- **Örnek 4:** 6 kΩ ($i_6$ aşağı), yukarı yönlü $2i_x$ bağımlı akım kaynağı, yukarı yönlü 24 mA'lik kaynak ve 2 kΩ paralel. $i_x$, 2 kΩ'luk dirençten üst düğüme doğru tanımlı.
  - KCL: $i_6 - 2i_x - 0.024 - i_x = 0$. $i_6 = \frac{v}{6000}$, $i_x = -\frac{v}{2000}$.
  - $\frac{v}{6000} + \frac{3v}{2000} = 0.024$, buradan $\frac{v}{600} = 0.024$ ve $v = 14.4$ V.
  - 24 mA'lik kaynağın çektiği güç: $-14.4 \cdot 0.024 = -345.6$ mW. Kaynak 345.6 mW verir.
- **Örnek 5:** Yukarı yönlü 5.6 A, 18 Ω ($i_A$), yukarı yönlü $0.1v_x$ bağımlı akım kaynağı ($i_B$ aşağı), 9 Ω ($i_C$) ve aşağı yönlü 2 A paralel.
  - KCL: $5.6 - \frac{v_x}{18} + 0.1v_x - \frac{v_x}{9} - 2 = 0$, buradan $v_x = 54$ V.
  - $i_A = 3$ A, $i_B = -0.1v_x = -5.4$ A, $i_C = 6$ A.

### Seri-paralel tanıma örnekleri

- **Örnek 6:** 120 mA'lik kaynak, 125 Ω ve 50 Ω paralel kollar. Sağda üst hatta 2 Ω, sonra 240 Ω'luk dikey kol, üst hatta 40 Ω ve en sağda 20 Ω.
  - 40 Ω ile 20 Ω seridir (60 Ω). Bu grup 240 Ω'a paraleldir ($60 \parallel 240 = 48$ Ω).
  - 2 Ω bu gruba seridir ($50$ Ω). Bu grup 50 Ω, 125 Ω ve kaynakla paraleldir.
  - Ek hesap: kaynağın gördüğü eşdeğer direnç $50 \parallel 50 \parallel 125 = 20.83$ Ω'dur. Kaynak gerilimi $0.12 \cdot 20.83 = 2.5$ V olur.
- **Örnek 7:** Solda yukarı yönlü 2 A'lik kaynak ve seri 1.5 Ω. Ortada iki tane dikey 4 Ω. İki 4 Ω'un üst uçları arasında 2 Ω var ve bu direnç bir kabloyla kısa devre edilmiş. Sağda 5 Ω ile yukarı yönlü 5 A'lik kaynak.
  - 2 Ω kısa devre edildiği için akım kablodan geçer. 2 Ω yok hükmündedir.
  - Bu yüzden iki 4 Ω aynı iki düğüm arasındadır, birbirine paraleldir.
  - 5 A ile 5 Ω seridir. 2 A ile 1.5 Ω seridir. Bu iki seri kol da aynı düğüm çiftine bağlı olduğu için 4 Ω'larla paraleldir.
  - Öğrenci sorusu: kısa devre olmasaydı ne olurdu? 2 Ω, sağdaki 4 Ω ve 5 A-5 Ω grubunun oluşturduğu gruba seri olurdu. Bu bütüne de soldaki 4 Ω paralel olurdu.
- **Örnek 8:** 1 A'lik kaynak, 3 Ω ve 5 Ω paralel. En sağ kolda yukarıdan aşağıya $3 \parallel 9$, 3 Ω, 5 Ω ve $3 \parallel 6$ seri bağlı.
  - Sağ kol tek bir grup olarak 3 Ω, 5 Ω ve 1 A'lik kaynakla paraleldir.
  - Ek hesap: sağ kol $2.25 + 3 + 5 + 2 = 12.25$ Ω'dur.

### Kaynak birleştirme örnekleri

- **Örnek 9 (seri gerilim kaynakları):** KVL: $-3 - 9 + 100i - 5 + 1 + 220i = 0$, buradan $320i = 16$ ve $i = 50$ mA. Eşdeğer devre 16 V'luk tek bir kaynak ve 320 Ω'dur.
- **Örnek 10 (paralel akım kaynakları):** Yukarı 2.5 A, 5 Ω, aşağı 2.5 A, 5 Ω, aşağı 3 A paralel.
  - KCL: $2.5 - \frac{v}{5} - 2.5 - \frac{v}{5} - 3 = 0$, buradan $v = -7.5$ V.
  - Kaynaklar birleştirilince yukarı yönlü $-3$ A (veya aşağı yönlü 3 A) olur. Sonuç aynıdır: $v = -7.5$ V, her dirençten $-1.5$ A geçer.
- **Örnek 11 (seri devre):** Soldaki 80 V'luk kaynağın artı ucu üstte. Üst hatta 10 Ω, eksisi solda 30 V'luk pil, 7 Ω, 5 Ω. Sağda artı ucu üstte 20 V'luk kaynak. Alt hatta 8 Ω.
  - Saat yönündeki $i$ için kaynaklar birleştirilir: $80 + 30 - 20 = 90$ V.
  - Dirençler: $10 + 7 + 5 + 8 = 30$ Ω.
  - $i = \frac{90}{30} = 3$ A. 80 V'luk kaynağın çektiği güç $-80 \cdot 3 = -240$ W, yani kaynak 240 W verir.
- **Örnek 12 (paralel devre):** Yukarı 5 A, 10 Ω, aşağı 1 A, 10 Ω, yukarı 6 A paralel.
  - Kaynaklar: $5 - 1 + 6 = 10$ A. Dirençler: $10 \parallel 10 = 5$ Ω.
  - $v = 10 \cdot 5 = 50$ V. Her dirençten 5 A geçer.

### Ders sonrası notlar

- **Düğüm ve çevre denklemleri:** Hoca 00:14:46 civarında "düğüm denklemlerini dirençler üzerinden, çevre akımlarını iletkenlik cinsinden yazmak daha pratik" dedi. Doğrusu tersidir. Düğüm denklemleri akımlarla (KCL) yazılır ve $i = Gv$ olduğu için iletkenlikle yazmak pratiktir. Çevre denklemleri gerilimlerle (KVL) yazılır ve $v = Ri$ olduğu için dirençle yazmak pratiktir.
- **Bağımlı kaynak örneği (Örnek 1):** Derste bağımlı kaynağın akım ve gerilim referanslarının aynı yönde olduğu için güç çektiği söylendi. $v_A = -120$ V olduğu için bağımlı kaynağın gerilimi $2v_A = -240$ V'tur. Çektiği güç $(-240)(8) = -1920$ W'tır, yani bağımlı kaynak 1920 W **verir**. Derste $v_A$'nın ters referansı ilk başta unutuldu ve 15 Ω'luk direncin gücü negatif bulundu. Bir öğrenci işaret hatasını gösterdi ve sonuç düzeltildi. Doğru güç dağılımı yukarıdaki örnekte verildi. Toplamın 0 çıkması bunu doğrular.
- **Örnek 8'de $v_x$:** Hoca soruda hata olduğunu söyleyip $v_2$'yi buldu. Aslında $v_x$ de bulunabilir. $a$ düğümünden sağ yol üzerinden $b$'ye gidilirse $v_x = -v_2 - 3 + v_{R1} = 24 - 3 + 1 = 22$ V. Sol yol üzerinden kontrol: $v_x = v_{R2} - 7 + 9 = 20 - 7 + 9 = 22$ V. İki yol aynı sonucu verir. Cevap $v_x = 22$ V'tur.
- **Örnek 2'deki yazım:** Slaytta güç hesabında $-(4/25)^2$ yazılmış. Akım $i = -\frac{4}{25}$ A olduğu için doğrusu $\left(-\frac{4}{25}\right)^2$'dir. Sonuç pozitiftir. Hoca ayrıca 30 Ω'luk direncin gücünde $(24/5)^2$ alınması gerektiğini, $\frac{24^2}{5}$ olmadığını belirtti.
- **Örnek 12'deki gerilim:** Derste önce 10 A, 5 Ω'a bölündü ve $v = 10$ V bulundu. Bir öğrenci bunu fark etti. Doğrusu $v = 10 \cdot 5 = 50$ V'tur. Her 10 Ω'luk dirençten 5 A geçer.
- **Altyazıdaki hatalar:** Altyazıda "10 kanunu" ifadesi "Ohm kanunu", "Kirşof" ifadesi "Kirchhoff", "nod" ifadesi "node (düğüm)", "10 metre" ifadesi "ohmmetre" olarak okunmalıdır. Hocanın "fasulye elemanı" dediği şey, slaytlarda türü belirtilmeyen genel bir devre elemanını gösteren fasulye biçimli semboldür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
