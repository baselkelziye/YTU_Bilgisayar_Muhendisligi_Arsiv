# Ders 13 Genişletilmiş Notu: Final Öncesi Örnek Çözümleri: Birinci Dereceden Devreler, Tekillik Fonksiyonları ve Fazörler

> Kayıt iki parçadır; arşivde parçalar yanlış sırada birleştirildiği için altyazıdaki sıra düzeltildi ve saat damgaları düzeltilmiş altyazıya göredir.

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Amacı ve Birinci Dereceden Devrelerde Genel Yol
- 2. Kaynaksız RC Devresi Örnekleri
- 3. Başlangıç Gerilimini Bulma ve Kondansatör Enerjisi
- 4. Bağımlı Kaynaklı RL Devresi: İki Yöntem
- 5. Diğer RL Devresi Örnekleri
- 6. Tekillik Fonksiyonlarıyla Sinyal Yazma
- 7. Fazörlerle AC Devre Çözümü
- 8. Op-Amp ve Norton Eşdeğeri Fazör Örnekleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Amacı ve Birinci Dereceden Devrelerde Genel Yol

Dönemin son dersinde yeni konuya geçilmedi. İlk programda bu haftaya devrelerde frekans analizi konmuştu; bu konu bu dönem anlatılmadı. Bunun yerine sınavlara hazırlık için çok sayıda örnek çözüldü. Sunum "BLM1612 - Circuit Theory / Examples" başlığını taşıyordu (ekrandan, 01:38:57). Bazı örneklerde hoca soruyu öğrencilere bıraktı ve bir öğrenci ekranda çözdü.

İlk konu, zaman düzleminde (t domain) kondansatör ve bobin denklemlerinin çıkarılmasıydı. Devrede bir kaynak varken kondansatör bir gerilime, bobin bir akıma yüklenir. Kaynak devreden çıkarıldığında depolanan enerji zamanla sönümlenir. Kondansatör gerilimi önce hızlı, sonra giderek yavaşlayan bir eğilimle düşer ve yaklaşık $5\tau$ sonra sıfıra iner.

RC ve RL devrelerinde son değer zaten bellidir: kaynak çıkarılınca birbirini besleyecek ikinci bir depolayıcı eleman olmadığından değer sıfıra gider. Bu yüzden yalnız başlangıç değeri ve zaman sabiti bulunur:

- RC devresi: $v_C(t) = v_C(0)\,e^{-t/\tau}$, $\tau = R_{eq}C$.
- RL devresi: $i(t) = i(0)\,e^{-t/\tau}$, $\tau = L/R_{eq}$.

RLC devrelerinde de değer sonunda sıfıra gider, ama bu sırada $5\tau$ hesabı aynı biçimde yapılmaz; $\alpha$ ile $\omega_0$ karşılaştırılarak cevabın türü belirlenir.

> **Hocanın vurgusu:** Buradaki $R$, devredeki ilk direnç değildir. Kondansatörün (ya da bobinin) uçlarından bakıldığında görülen eşdeğer dirençtir.

## 2. Kaynaksız RC Devresi Örnekleri

### 2.1 İlk örnek: $v_C(0) = 15\,\text{V}$

Devrede soldan sağa $5\,\Omega$, $0.1\,\text{F}$ kondansatör, üst kolda $8\,\Omega$ ve sağda $12\,\Omega$ vardır. $v_C(0) = 15\,\text{V}$ verilmiş; $t>0$ için $v_C$, $v_x$ ve $i_x$ isteniyor (ekrandan, 00:08:57).

Çözüm (ekrandan, 00:13:57):

- $8\,\Omega$ ile $12\,\Omega$ seridir: $20\,\Omega$. Bu kol $5\,\Omega$ ile paraleldir:
  $$R_{eq} = \frac{20\times 5}{20+5} = 4\,\Omega$$
- Devre, $R_{eq}$ ile $0.1\,\text{F}$'lık bir kondansatörden oluşan basit bir devreye indirgenir.
- $\tau = R_{eq}C = 4(0.1) = 0.4\,\text{s}$.
- $v_C = v(0)e^{-t/\tau} = 15e^{-t/0.4} = 15e^{-2.5t}\,\text{V}$.

Hoca bunun anlamını şöyle açıkladı: $5\tau = 2\,\text{s}$ sonra bu devrede kondansatör tamamen boşalmış olur. Grafiği çizerken $t=0$'da 15 V, $t \approx 2\,\text{s}$ civarında sıfır olduğu bilinir; aradaki değişim üstel denklemle bulunur. Denkleme istenen $t$ değeri konarak o andaki gerilim hesaplanır.

$v_x$ ve $i_x$ için: $5\,\Omega$ ve $20\,\Omega$'luk kol paralel olduğundan ikisinin üzerinde de $15e^{-2.5t}$ vardır. Bu gerilim $8\,\Omega$ ile $12\,\Omega$ arasında dirençlerle orantılı paylaşılır:

$$v_x = \frac{12}{20}\cdot 15e^{-2.5t} = 9e^{-2.5t}\,\text{V}, \qquad i_x = \frac{v_x}{12} = 0.75e^{-2.5t}\,\text{A}$$

### 2.2 İkinci örnek: $v_C(0) = 60\,\text{V}$ (öğrenciye soruldu)

Devrede $12\,\Omega$, $6\,\Omega$ (üzerinde $v_x$), üst kolda $8\,\Omega$ (akımı $i_o$) ve $\tfrac13\,\text{F}$ vardır. $v_C(0) = 60\,\text{V}$; $t \ge 0$ için $v_C$, $v_x$, $i_o$ isteniyor. Slaytta cevap: $60e^{-0.25t}\,\text{V}$, $20e^{-0.25t}\,\text{V}$, $-5e^{-0.25t}\,\text{A}$ (ekrandan, 00:18:57).

Bir öğrencinin ekranda yaptığı çözüm (ekrandan, 00:23:57):

- $12 \parallel 6 = 4\,\Omega$, $4 + 8 = 12\,\Omega$ eşdeğer direnç.
- $\tau = RC = 12\cdot\tfrac13 = 4\,\text{s}$, yani üs $-t/4 = -0.25t$.
- $v_C = 60e^{-0.25t}\,\text{V}$.
- $v_x$: 60 V'luk gerilim $8\,\Omega$ ile $4\,\Omega$ arasında paylaşılır; $4\,\Omega$ tarafına $\tfrac13$'ü düşer: $v_x = 20e^{-0.25t}\,\text{V}$.
- $i_o$: $60/12 = 5$; kondansatör boşalırken akım $i_o$ okunun tersine aktığı için $i_o = -5e^{-0.25t}\,\text{A}$.

Hoca çözümü doğru buldu.

## 3. Başlangıç Gerilimini Bulma ve Kondansatör Enerjisi

### 3.1 Kaynak $t=0$'da çıkarılıyor

Bu örnek bir öncekinin kaynak eklenmiş biçimidir. Önceki örneklerde $v_C(0)$ veriliyordu; burada önce onun bulunması gerekir. Değerler altyazıdan şöyle anlaşılıyor: 20 V kaynak, $3\,\Omega$, $1\,\Omega$, $9\,\Omega$ ve $20\,\text{mF}$; $t=0$'da kaynak devreden ayrılıyor, $v(t)$ ve başlangıç enerjisi isteniyor.

<!-- BELİRSİZ: Bu örneğin karesi yok; devre değerleri ve topolojisi altyazıdan kuruldu, kareyle doğrulanamadı. -->

> **Hocanın vurgusu:** "20 V var, o zaman kondansatör 20 V'a şarj olur" denemez. Bu sık yapılan bir hatadır. Kondansatörün hangi elemanın gerilimine şarj olduğuna bakmak gerekir; bunun için kondansatör açık devre yapılarak devre incelenir.

- Açık devre durumunda kondansatörle seri $1\,\Omega$'dan akım geçmez. Kondansatör, paralel olduğu $9\,\Omega$'un gerilimine şarj olur.
- $3\,\Omega$ ile $9\,\Omega$ seridir; 20 V, $1:3$ oranında paylaşılır: $v(0) = 20\cdot\frac{9}{12} = 15\,\text{V}$. $3\,\Omega$ üzerinde 5 V kalır.
- Kaynak çıkarıldıktan sonra kondansatör $1\,\Omega$ ve $9\,\Omega$'un seri bağlantısı üzerinden boşalır: $R_{eq} = 10\,\Omega$.
- $\tau = 10\cdot 20\times10^{-3} = 0.2\,\text{s}$, yani yaklaşık 1 saniyede kondansatör boşalır.
- $v(t) = 15e^{-t/0.2} = 15e^{-5t}\,\text{V}$.

Başlangıç enerjisi için hoca kondansatör enerji formülünü hatırlattı ve dirençteki güç formülleriyle ($I^2R$, $V^2/R$) benzerliğine değindi:

$$w_C(0) = \tfrac12 C v(0)^2 = \tfrac12 (20\times10^{-3})(15)^2 = 2.25\,\text{J} \text{ (ara adım eklendi)}$$

Başlangıç enerjisi sorulduğu için doğrudan $v(0) = 15\,\text{V}$ kullanılır; üstel ifadeye gerek yoktur.

### 3.2 Anahtar $t=0$'da açılıyor (öğrenciye soruldu)

Devre: 24 V kaynak, seri $6\,\Omega$ ve anahtar; anahtarın sağında $\tfrac16\,\text{F}$, $12\,\Omega$ ve $4\,\Omega$ paralel. $t \ge 0$ için $v(t)$ ve $w_C(0)$ isteniyor; slaytta cevap $8e^{-2t}\,\text{V}$, $5.333\,\text{J}$ (ekrandan, 00:28:57).

Bir öğrencinin sözlü çözümü:

- Kondansatör açık devre: $\frac{1}{R} = \frac{1}{12} + \frac14 \Rightarrow R = 3\,\Omega$. $6 + 3 = 9\,\Omega$.
- $v(0) = 24\cdot\frac{3}{9} = 8\,\text{V}$.
- Anahtar açılınca kondansatör yalnız $3\,\Omega$'u görür: $\tau = 3\cdot\tfrac16 = 0.5\,\text{s}$.
- $v(t) = 8e^{-2t}\,\text{V}$.

Enerji derste hesaplanmadı; slayttaki değer $\tfrac12\cdot\tfrac16\cdot 8^2 = 5.333\,\text{J}$ ile tutarlıdır (python ile doğrulandı).

## 4. Bağımlı Kaynaklı RL Devresi: İki Yöntem

### 4.1 Soru

Devrede $0.5\,\text{H}$ bobin (akımı $i$), ona paralel $2\,\Omega$ (akımı $i_x$), üst kolda $4\,\Omega$ ve sağda gerilim kontrollü değil, akım kontrollü bağımlı gerilim kaynağı $3i$ vardır. $i(0) = 10\,\text{A}$; $t>0$ için $i(t)$, $v_x$ ve $i_x(t)$ isteniyor (ekrandan, 00:33:57).

Bağımlı kaynak bulunduğundan iki teknik uygulanabilir.

> **Hocanın vurgusu:** Devrede bağımlı kaynak varsa Thevenin eşdeğer direnci normal yolla (kaynakları söndürüp seri/paralel indirgeyerek) bulunamaz.

### 4.2 Yöntem 1: Test kaynağı

Amaç $R_{eq}$'yi bulup $\tau = L/R_{eq}$ hesaplamaktır. Bobin yerine $v_o = 1\,\text{V}$ test kaynağı konur (ekrandan, 00:33:57). Bağımlı kaynak gerilim kaynağı olduğu için çevre (mesh) analizi uygundur. Hoca KVL'nin çevre analiziyle, KCL'nin düğüm analiziyle eşleştiğini hatırlattı.

- Birinci çevre: $2(i_1 - i_2) + 1 = 0$. Akım kaynağın artı ucundan girdiği için $+1$ yazılır.
- İkinci çevre: $4i_2 + 2(i_2 - i_1) - 3i_1 = 0 \Rightarrow 6i_2 - 2i_1 - 3i_1 = 0$. Bağımlı kaynak gerilim olduğundan KVL'ye doğrudan girer.
- İkinci denklemden $i_2 = \tfrac56 i_1$; birinciye konunca $2i_1 - \tfrac53 i_1 = -1 \Rightarrow i_1 = -3\,\text{A}$ (ara adım eklendi).
- Test kaynağından çıkan akım $i_o = -i_1 = 3\,\text{A}$.
- $R_{eq} = \dfrac{v_o}{i_o} = \dfrac{1}{3}\,\Omega$.
- $\tau = \dfrac{L}{R_{eq}} = \dfrac{0.5}{1/3} = \dfrac32\,\text{s}$.
- $i(t) = 10e^{-2t/3}\,\text{A}$.

Hoca anlatırken bir an $\tau = R/L$ yazdığını, doğrusunun $L/R_{eq}$ olduğunu kendisi düzeltti.

### 4.3 Yöntem 2: Bobin denklemini KVL'ye yazmak

Test kaynağına gerek kalmadan bobin gerilimi $v_L = L\,\frac{di}{dt}$ doğrudan çevre denklemine yazılır (ekrandan, 00:38:57):

$$\frac12\frac{di_1}{dt} + 2(i_1 - i_2) = 0 \;\Rightarrow\; \frac{di_1}{dt} + 4i_1 - 4i_2 = 0$$
$$6i_2 - 2i_1 - 3i_1 = 0 \;\Rightarrow\; i_2 = \tfrac56 i_1$$

Yerine konunca:

$$\frac{di_1}{dt} + \frac23 i_1 = 0 \;\Rightarrow\; \frac{di_1}{i_1} = -\frac23\,dt$$

İki taraf $0$'dan $t$'ye integrallenir: $\ln\frac{i(t)}{I_0} = -\frac23 t$. $\ln$'den kurtulmak için iki taraf $e$ üssüne alınır:

$$i(t) = I_0 e^{-2t/3} = 10e^{-2t/3}\,\text{A}$$

İki yöntem aynı sonucu verir.

### 4.4 $i_x$ ve $v_x$

Hoca $i_1$'in $2\,\Omega$ ile $4\,\Omega$ kollarına bölüneceğini söyleyip $i_x = \frac46\cdot 10e^{-2t/3}$ yazdı. $v_x$'in slaytta işaretli olmadığını, büyük olasılıkla $2\,\Omega$ üzerindeki gerilim olduğunu, bu durumda $v_x = 2i_x$ olacağını söyledi.

> **Ders sonrası not:** Bağımlı kaynak bulunduğu için $i_x$ basit akım bölücüyle bulunamaz. $2\,\Omega$ bobine paraleldir, bu yüzden üzerindeki gerilim bobin gerilimine eşittir: $v = L\frac{di}{dt} = 0.5\cdot\left(-\frac{20}{3}\right)e^{-2t/3} = -\frac{10}{3}e^{-2t/3}\,\text{V}$. Buradan $i_x = v/2 = -\frac53 e^{-2t/3}\,\text{A} \approx -1.667e^{-2t/3}\,\text{A}$ olur (python ile doğrulandı). $v_x$ bu gerilimse $v_x = -\frac{10}{3}e^{-2t/3}\,\text{V}$'tur.

## 5. Diğer RL Devresi Örnekleri

### 5.1 $2v_x$ bağımlı kaynaklı devre (öğrenciye soruldu)

Devre: $2\,\text{H}$ bobin (akımı $i$, aşağı yönlü), üst kolda $1\,\Omega$ (üzerinde $v_x$, artı ucu solda), ortada $2\,\Omega$ ve altında bağımlı kaynak $2v_x$, sağda $6\,\Omega$. $i(0) = 12\,\text{A}$; $i$ ve $v_x$ isteniyor. Slaytta cevap: $12e^{-2t}\,\text{A}$, $-12e^{-2t}\,\text{V}$ (ekrandan, 00:43:57).

Hoca, örneğin bir öncekinin aynısı olduğunu, iki yöntemle de çözülebileceğini söyledi. Kaynak gerilim kaynağı olduğu için KVL yazmak mantıklıdır; düğüm analiziyle de olur ama daha çok uğraştırır.

Bir öğrencinin Yöntem 2 ile çözümü:

- Sol çevre: $2\frac{di}{dt} - v_x + 2(i_1 - i_2) - 2v_x = 0 \Rightarrow 2\frac{di}{dt} - 3v_x + 2i_1 - 2i_2 = 0$.
- Sağ çevre: $6i_2 + 2(i_2 - i_1) + 2v_x = 0$.
- $1\,\Omega$'dan akım ters yönde aktığı için $v_x = -i_1$. Sağ çevre: $8i_2 - 2i_1 - 2i_1 = 0 \Rightarrow i_1 = 2i_2$.
- Sol çevrede yerine konunca: $2\frac{di_1}{dt} + 3i_1 + 2i_1 - i_1 = 0 \Rightarrow 2\frac{di_1}{dt} = -4i_1$.
- $\frac{di_1}{i_1} = -2\,dt$; integral ve $\ln$'den kurtulma ile $i(t) = I_0 e^{-2t} = 12e^{-2t}\,\text{A}$.
- $v_x = -i = -12e^{-2t}\,\text{V}$.

Sonuç slayttaki cevapla aynıdır. Düğüm denklemiyle de kontrol edildi: bobin uçlarından görülen direnç $4\,\Omega$, $\tau = 2/4 = 0.5\,\text{s}$ (elle doğrulandı, ara adım eklendi).

### 5.2 Anahtar uzun süre kapalı, $t=0$'da açılıyor

Devre: 40 V, $2\,\Omega$, anahtar, $12\,\Omega$, üst kolda $4\,\Omega$, $16\,\Omega$ ve $2\,\text{H}$ bobin. $t>0$ için $i(t)$ isteniyor (ekrandan, 00:53:57).

$t<0$: anahtar kapalı, DC'de bobin kısa devre.

- Bobin kısa devre olunca $16\,\Omega$'un devrede yeri kalmaz: akım kısa devre yolunu seçer, $16\,\Omega$ etkin olmayan bir kol olur. Hoca, $16\,\Omega$ ile bobin arasında bir direnç daha olsaydı bunun yapılamayacağını belirtti.
- Kalan devre: 40 V, $2\,\Omega$, $12\,\Omega$ ve $4\,\Omega$ (ekrandan, 00:53:57).
- $4\parallel 12 = 3\,\Omega$, $2 + 3 = 5\,\Omega$, ana akım $i_1 = 40/5 = 8\,\text{A}$.
- Bobin kolunun akımı akım bölücüyle: $i(0) = \frac{12}{16}\cdot 8 = 6\,\text{A}$.

$t>0$: $2\,\Omega$ ve kaynak ayrılır. Bobin $(12 + 4) \parallel 16 = 8\,\Omega$ görür.

- $\tau = L/R_{eq} = 2/8 = \tfrac14\,\text{s}$.
- $i(t) = 6e^{-4t}\,\text{A}$.

### 5.3 Akım kaynaklı devre (öğrenciye soruldu)

Devre: $24\,\Omega$, 15 A akım kaynağı, anahtar; anahtarın sağında $12\,\Omega$, $8\,\Omega$, $5\,\Omega$ ve $2\,\text{H}$ bobin (akımı $i(t)$). $t>0$ için $i(t)$ isteniyor; slaytta cevap $5e^{-2t}\,\text{A}$ (ekrandan, 00:58:57).

Bir öğrencinin çözümü (ekrandan, 01:03:57):

- $t<0$: bobin kısa devre. $5\,\Omega$'un iki ucu da aynı potansiyelde kaldığından ondan akım geçmez.
- $24\,\Omega$, $12\,\Omega$ ve $8\,\Omega$ akımı ters orantılı paylaşır: $24\,\Omega$'dan $i$, $12\,\Omega$'dan $2i$, $8\,\Omega$'dan $3i$. $6i = 15 \Rightarrow i = 2.5\,\text{A}$.
- Bobinden geçen akım $12\,\Omega$'un akımıdır: $i(0) = \frac{15}{6}\cdot 2 = 5\,\text{A}$.
- $\tau = 2/R_{eq} = 0.5\,\text{s}$, $i(t) = 5e^{-2t}\,\text{A}$.

Öğrenci $R_{eq}$'yi $24\parallel 12 = 8$, $8 \parallel 8 = 4\,\Omega$ diye hesapladı. Hoca sonucun tesadüfen aynı çıktığını belirtti: anahtar açıldıktan sonra $24\,\Omega$ ve akım kaynağı devrede değildir. Doğru devrede bobin, $12 + 8 = 20\,\Omega$ ile $5\,\Omega$'un paralelini görür: $20 \parallel 5 = 4\,\Omega$, $\tau = 2/4 = 0.5\,\text{s}$.

> **Hocanın vurgusu:** Anahtar konumu değiştikten sonra bobin ya da kondansatör hangi devreyi görüyorsa eşdeğer direnç o devreden, elemanın uçlarından bakılarak bulunur.

### 5.4 Anahtar $t=0$'da kapanıyor

Bu örnekte anahtar $t=0$'da kapanır; mantık öncekinin tersidir. $t<0$'da anahtar açıkken devreyi 10 V'luk kaynak besler. Anahtarın kapanması bir kısmı kısa devre edip kaynağı devreden ayırmak demektir; bobin kalan dirençler üzerinden boşalır. Bu örneğin ilk sayfası karede yok; değerler altyazıdan ve ikinci sayfadan alınmıştır (ekrandan, 01:08:57).

- $t<0$: bobin kısa devre, $6\,\Omega$'dan akım geçmez, $i_o = 0$. Eşdeğer direnç $5\,\Omega$, $i(0) = 10/5 = 2\,\text{A}$. $3\,\Omega$ üzerindeki gerilim $v_o = 3\cdot 2 = 6\,\text{V}$.
- $t>0$: $3\,\Omega$ ile $6\,\Omega$ paralel: $R_{eq} = 2\,\Omega$, $\tau = L/R_{eq} = 2/2 = 1\,\text{s}$.
- $i(t) = 2e^{-t}\,\text{A}$.
- Bobin $6\,\Omega$ ve $3\,\Omega$ ile paralel olduğundan (ekrandan, 01:08:57):
  $$v_o(t) = -v_L = -L\frac{di}{dt} = -2(-2e^{-t}) = 4e^{-t}\,\text{V}, \qquad i_o(t) = \frac{v_L}{6} = -\frac23 e^{-t}\,\text{A}$$
- Bütün zamanlar için: $i(t) = 2\,\text{A}$ ($t<0$), $2e^{-t}\,\text{A}$ ($t \ge 0$); $i_o(t) = 0$ ($t<0$), $-\tfrac23 e^{-t}\,\text{A}$ ($t>0$); $v_o(t) = 6\,\text{V}$ ($t<0$), $4e^{-t}\,\text{V}$ ($t>0$).

<!-- BELİRSİZ: Bu örneğin devre şeklinin bulunduğu ilk sayfa karede yok; 2 H ve 3/6 ohm değerleri ikinci sayfadaki formüllerden ve altyazıdan çıkarıldı. -->

Hoca bu değerler bulunduktan sonra $i(t)$ ile $i_o(t)$'nin aynı grafikte çizilmesinin istenebileceğini söyledi. Bobin akımı 2'den sıfıra azalır, $i_o$ ise $-\tfrac23$'ten sıfıra yükselir; ikisi de sıfıra yaklaşır.

### 5.5 24 A akım kaynaklı örnek (evde çözülmek üzere)

Hoca bu örneği uzun sürdüğü için evde çözülmesini istedi ve yalnız özetini verdi: $t=0$'da 24 A'lik kaynak devreden çıkarılıyor. $t<0$'da bobin kısa devre olduğundan $3\,\Omega$ etkisiz kalır; paralel iki koldan bobine 16 A, diğer kola 8 A düşer: $I_0 = 16\,\text{A}$. $t>0$'da seri iki direnç $6\,\Omega$ eder, bu $3\,\Omega$ ile paraleldir: $R_{eq} = 2\,\Omega$; bobin $1\,\text{H}$ olduğundan üs $-2t$ olur.

<!-- BELİRSİZ: Bu örneğin karesi yok; devre değerleri altyazıdan eksik okunuyor, 16 A ve e^{-2t} sonuçları kareyle doğrulanamadı. -->

## 6. Tekillik Fonksiyonlarıyla Sinyal Yazma

Bu konu ilgili haftada işlenmiş ama az örnek çözülmüştü. Basamak $u(t)$, rampa $r(t)$ ve darbe (impulse) $\delta(t)$ kullanılarak parçalı sinyaller yazılır.

### 6.1 Dikdörtgen darbe

2. saniyede 10 birimlik basamak verilir, 5. saniyede sıfıra iner. Sıfıra indirmek için aynı genlikte ters bir basamak üst üste bindirilir:

$$f(t) = 10u(t-2) - 10u(t-5)$$

Türev, değişimi gösterir. Yatay bölgelerde değişim yoktur; bu yüzden türev $t=2$ ve $t=5$'te darbe olarak görünür: $10\delta(t-2) - 10\delta(t-5)$ (ara adım eklendi).

### 6.2 Akım darbesi ve integrali

Sinyal 0–2 s arasında 10, 2–4 s arasında $-10$, sonra 0'dır (ekrandan, 01:13:57). 2. saniyede 10'dan $-10$'a inmek için $-20$'lik basamak gerekir; 4. saniyede $+10$'luk basamak ile sıfırlanır:

$$i(t) = 10[u(t) - 2u(t-2) + u(t-4)]$$

İntegral alanların toplamıdır; basamaklar rampaya dönüşür:

$$\int i\,dt = 10[r(t) - 2r(t-2) + r(t-4)]$$

Grafik 0'dan $t=2$'de 20'ye çıkan, $t=4$'te sıfıra inen bir üçgendir. Rampanın eğimi $r$'nin katsayısıdır. $10r(t)$'ye $-10r(t-2)$ eklenirse sinyal yatay devam eder; aşağı inmesi için iki kat eğimle $-20r(t-2)$ gerekir. 4. saniyede daha aşağı inmemesi için aynı eğimde $+10r(t-4)$ eklenir.

> **Hocanın vurgusu:** Rampaların eğim katsayılarında sık hata yapılıyor.

### 6.3 Testere dişi (sawtooth) sinyal

0'dan 2. saniyeye kadar yükselen bir rampa vardır; hoca eğimi önce 10 deyip sonra 5 olarak düzeltti. 2. saniyede sinyal birden sıfıra iner.

- $5r(t)$ rampayı başlatır.
- $-5r(t-2)$ rampayı durdurur; sinyal 10 seviyesinde yatay kalır. ($-10r(t-2)$ eklenseydi sinyal eğimle aşağı inerdi; istenen ise ani düşüştür.)
- $-10u(t-2)$ bu 10 seviyesini sıfırlar.

$$f(t) = 5r(t) - 5r(t-2) - 10u(t-2)$$

Başka çözümler de mümkündür; en basiti budur.

<!-- BELİRSİZ: Bu örneğin karesi yok; eğim ve genlik altyazıdan alındı. -->

### 6.4 Rampalardan oluşan sinyal (öğrenciye soruldu)

Sinyal $t=0$'da 2'den başlar, $t=1$'de sıfırı keser, $t=2$'de $-2$'ye iner, $t=3$'te tekrar 0'a çıkar. Slaytta cevap (ekrandan, 01:18:57):

$$i(t) = 2u(t) - 2r(t) + 4r(t-2) - 2r(t-3)\,\text{A}$$

Bir öğrenciden her terimi ayrı çizmesi istendi (ekrandan, 01:23:57): $2u(t)$ 2 seviyesinde bir basamak, $-2r(t)$ eğimi $-2$ olan rampa, $4r(t-2)$ 2'de başlayan eğimi 4 olan rampa, $-2r(t-3)$ 3'te başlayan eğimi $-2$ olan rampa.

**Soru:** Bütün eğimler 2 iken neden $4r(t-2)$ kullanıldı?
**Cevap (öğrenci):** $+2r(t-2)$ eklenseydi sinyal düz giderdi; yukarı çıkması için $+4$ gerekir.

**Soru:** $2u(t)$ ile $-2r(t)$ birleşince yukarıdaki şekil nasıl oluşuyor?
**Cevap (hoca):** Birim basamak, rampa fonksiyonunun başlangıç seviyesini (baseline) kaydırır. Örneğin eğimi 3 olan ama $-3$'ten başlayan bir rampa görülürse, rampanın yanına $-3u(t)$ eklenerek başlangıç seviyesi kaydırılır.

## 7. Fazörlerle AC Devre Çözümü

### 7.1 Neden fazör?

Direnç, bobin ve kondansatör birlikteyken ortak bir eşdeğer dirençten söz edilemez; bunun yerine eşdeğer empedans kullanılır. Fazör gösteriminde kaynaktaki açısal frekans $\omega$ ($\omega = 2\pi f$) bobin ve kondansatörün empedansına katılır, böylece zaman değişkeninden kurtulunur.

- Bobin: $\mathbf{Z}_L = j\omega L$.
- Kondansatör: $\mathbf{Z}_C = -\dfrac{j}{\omega C}$.
- $-3j$ gibi bir saf sanal sayı fazör diyagramında $3\angle -90^\circ$'dir. Genel olarak $a + jb$ için büyüklük $\sqrt{a^2+b^2}$, açı $\arctan(b/a)$'dır.
- Kosinüsle verilen kaynak doğrudan fazöre yazılır: $20\cos 250t \to 20\angle 0^\circ$. Sinüs olsaydı önce kosinüse çevrilirdi ve açı $90^\circ$ kayardı.

> **Hocanın vurgusu:** Fazörle çözüm için bütün kaynaklar aynı frekansta olmalıdır. Fazöre geçince frekans bilgisi kaynaklardan atılır, çünkü artık empedansların içindedir.

### 7.2 $v_a(t)$ örneği

Devre: $20\cos(250t)\,\text{V}$ kaynak, seri $8\,\Omega$ ve $36\,\text{mH}$; düğümde $0.25\,\text{mF}$ kondansatör ($v_a$), $1.2\cos(250t+45^\circ)\,\text{A}$ akım kaynağı, $80\,\text{mH}$ ve bağımlı kaynak $4v_a(t)$ (ekrandan, 01:43:57).

Dönüşümler ($\omega = 250$):

- $j\omega L = j(250)(36\times10^{-3}) = j9$
- $-j/(\omega C) = -j/(250\cdot 0.25\times10^{-3}) = -j16$
- $j(250)(80\times10^{-3}) = j20$
- $1.2\cos(250t+45^\circ) \to 1.2\angle 45^\circ$

Kondansatörün üst düğümünde KCL (ekrandan, 01:48:57):

$$\mathbf{I}_1 + 1.2\angle 45^\circ = \mathbf{I}_2 + \mathbf{I}_3$$
$$\frac{20\angle 0^\circ - \mathbf{V}_a}{8 + j9} + 1.2\angle 45^\circ = \frac{\mathbf{V}_a}{-j16} + \left(-\frac{3\mathbf{V}_a}{j20}\right)$$

Hoca toplama ve çıkarmanın karmaşık (dikdörtgen) biçimde daha kolay olduğunu, sonucu en sonda fazöre çevirmenin mantıklı olduğunu söyledi. Sonuç:

$$\mathbf{V}_a = 12.43\angle -81.2^\circ\,\text{V}, \qquad v_a(t) = 12.43\cos(250t - 81.2^\circ)\,\text{V}$$

Frekans (250) değişmez. Giriş $0^\circ$ fazlı 20 V iken bu gerilim $81.2^\circ$ geridedir.

> **Ders sonrası not:** Slaytta seri kolun empedansı $8 - j9$ yazılmış. Hoca, bobin $90^\circ$ ileride olduğu için buranın artı olması gerektiğini söyledi. $8 + j9$ ile çözüldüğünde slayttaki $12.43\angle -81.2^\circ$ sonucu çıkıyor; $8 - j9$ ile $10.21\angle -31.7^\circ$ çıkıyor (python ile doğrulandı). Yani slayttaki eksi işaret yalnız yazım hatasıdır.

### 7.3 Akım kontrollü bağımlı kaynaklı örnek

Giriş kaynağı $v_s = 10\cos 10t$, $\omega = 10$. $R_1 = 10\,\Omega$ üzerinden geçen $i(t)$ isteniyor. Hoca slaytta "$v_a$" yazmasına karşın giriş kaynağının kastedildiğini söyledi.

Dönüşümler:

- $10\,\text{mF}$ kondansatör: $-j/(10\cdot 10\times10^{-3}) = -j10$.
- $0.5\,\text{H}$ bobin: $j(10)(0.5) = j5$.
- $5\,\Omega$ ile seri bobin: $\mathbf{Z}_2 = 5 + j5$.
- $10\,\Omega$ ile $-j10$ paralel: $\mathbf{Z}_1 = 5 - j5$ (ara adım eklendi).

Devre, $\mathbf{V}_s$, $R_1$, $\mathbf{Z}_1$, $\mathbf{Z}_2$ ve aradaki $10\mathbf{I}$ bağımlı gerilim kaynağından oluşan bir yapıya indirgenir (ekrandan, 01:53:57). Denklemler:

1. $\mathbf{I} = \dfrac{\mathbf{V}_s - \mathbf{V}_1}{R_1}$
2. $10\mathbf{I} = \mathbf{V}_2 - \mathbf{V}_1$
3. Süper düğüm KCL'si: $\mathbf{I} = \dfrac{\mathbf{V}_1}{\mathbf{Z}_a} + \dfrac{\mathbf{V}_1 + 10\mathbf{I}}{\mathbf{Z}_b}$

Hoca ikinci değişken $\mathbf{V}_2$ oluşmasın diye $\mathbf{V}_2$ yerine $\mathbf{V}_1 + 10\mathbf{I}$ yazdı. Denklemler matris biçiminde düzenlenip hesap makinesiyle çözülür:

$$\mathbf{V}_1 = 4.4721\angle 63.4^\circ\,\text{V}, \qquad \mathbf{I} = 0.89443\angle -26.6^\circ\,\text{A}, \qquad i(t) = 0.89443\cos(10t - 26.6^\circ)\,\text{A}$$

Yorum: $R_1$'in sağındaki $\mathbf{V}_1$ gerilimi, $R_1$'den geçen akımdan $63.4^\circ + 26.6^\circ = 90^\circ$ öndedir.

> **Ders sonrası not:** Slayttaki şekilde empedanslar $\mathbf{Z}_1$, $\mathbf{Z}_2$ diye adlandırılmış, denklemlerde ise $\mathbf{Z}_2$, $\mathbf{Z}_3$ kullanılmış. Yukarıda bu yüzden $\mathbf{Z}_a$ (düğüm 1'deki kol, $5 - j5$) ve $\mathbf{Z}_b$ (düğüm 2'deki kol, $5 + j5$) yazıldı. Bu değerlerle python çözümü slayttaki sonucu veriyor.

## 8. Op-Amp ve Norton Eşdeğeri Fazör Örnekleri

### 8.1 Op-amp örneği

Op-amp'ın kuralları bilindikten sonra yapılacak iş, devreyi fazöre çevirip aynı kuralları uygulamaktır. $\omega = 500$; giriş $125\,\text{mV}\angle 15^\circ = 0.125\angle 15^\circ\,\text{V}$. Bobin $j400$, nano faradlık kondansatör $-j8000$'e dönüşür.

Evirmeyen uçta KCL (ekrandan, 01:58:57):

$$\frac{\mathbf{V}_s - \mathbf{V}_a}{j400} = \frac{\mathbf{V}_a}{300} + 0 \;\Rightarrow\; \mathbf{V}_a = \frac{300}{300 + j400}\mathbf{V}_s = (0.6\angle -53.1^\circ)(0.125\angle 15^\circ) = 0.075\angle -38.1^\circ\,\text{V}$$

İdeal op-amp kuralıyla eviren uç da $\mathbf{V}_a$'dadır. Eviren uçta akım üç kola ayrılır:

$$\frac{\mathbf{V}_a}{4000} + \frac{\mathbf{V}_a - \mathbf{V}_o}{10\,000} + \frac{\mathbf{V}_a - \mathbf{V}_o}{-j8000} = 0$$

80 000 ile çarpılınca $0 = 20\mathbf{V}_a + 8(\mathbf{V}_a - \mathbf{V}_o) + j10(\mathbf{V}_a - \mathbf{V}_o)$:

$$\mathbf{V}_o = \frac{28 + j10}{8 + j10}\mathbf{V}_a = \frac{29.73\angle 19.65^\circ}{12.81\angle 51.34^\circ}(0.075\angle -38.1^\circ) = 0.174\angle -69.79^\circ\,\text{V}$$

$$v_o(t) = 174\cos(500t - 69.79^\circ)\,\text{mV}$$

Python ile hesap $0.1741\angle -69.82^\circ$ veriyor; fark slayttaki ara yuvarlamadan gelir.

### 8.2 Norton eşdeğeri

Devrede bir bağımlı kaynak vardır, ama $i_a$ akımına bağlıdır. Çıkış ucu açık devre olduğundan $i_a$ bir kol akımı değil ana akımdır ve devreyi tek başına belirler; bu yüzden kaynak neredeyse bağımsız gibi ele alınabilir. Değerler zaten fazör biçiminde verilmiştir. Kaynak $10\angle 30^\circ\,\text{V}$'tur.

<!-- BELİRSİZ: Devre şeklinin karesi yok; altyazıdaki çevre denklemi ("30 IA - 5 IA ... j25 IA") net okunamıyor. -->

İzlenen yol:

- Thevenin ve Norton'da ortak büyüklük, bakılan uçlardaki açık devre gerilimi $\mathbf{V}_{oc}$'dir.
- Thevenin için $\mathbf{V}_{oc}$ ve eşdeğer direnç, Norton için kısa devre akımı $\mathbf{I}_{sc}$ ve eşdeğer direnç bulunur. Thevenin devresi gerilim kaynağı ile seri empedans, Norton devresi akım kaynağı ile paralel empedanstır.
- Önce tek bilinmeyen $i_a$ çekilir ve $\mathbf{V}_{oc}$ bulunur. Sonra uçlar kısa devre edilip ikinci bir çevre yazılır: $i_a = i_1 - i_{sc}$; buradan $\mathbf{I}_{sc}$ çekilir.
- Kondansatör ve bobin bulunduğundan eşdeğer direnç yerine eşdeğer empedans $\mathbf{Z}_t$ kullanılır (ekrandan, 02:03:57):

$$\mathbf{Z}_t = \frac{\mathbf{V}_{oc}}{\mathbf{I}_{sc}} = \frac{7.071\angle -15^\circ}{0.1060\angle -2^\circ} = 66.71\angle -13^\circ\,\Omega$$

Norton eşdeğeri: $106\angle -2^\circ\,\text{mA}$'lik akım kaynağına paralel $66.71\angle -13^\circ\,\Omega$'luk empedans.

## Örnek Sorular

**Soru 1** (ekrandan, 00:18:57): Devrede $12\,\Omega$, $6\,\Omega$ ($v_x$), $8\,\Omega$ ($i_o$) ve $\tfrac13\,\text{F}$ var. $v_C(0) = 60\,\text{V}$ ise $t \ge 0$ için $v_C$, $v_x$, $i_o$'yu bulun.

> **Çözüm (derste bir öğrenci çözdü):** $R_{eq} = (12\parallel 6) + 8 = 12\,\Omega$, $\tau = 4\,\text{s}$. $v_C = 60e^{-0.25t}\,\text{V}$, $v_x = 20e^{-0.25t}\,\text{V}$, $i_o = -5e^{-0.25t}\,\text{A}$.

**Soru 2** (ekrandan, 00:28:57): 24 V, $6\,\Omega$, $\tfrac16\,\text{F}$, $12\,\Omega$, $4\,\Omega$ içeren devrede anahtar $t=0$'da açılıyor. $t \ge 0$ için $v(t)$ ve $w_C(0)$'ı bulun.

> **Çözüm (derste bir öğrenci çözdü, enerji derste hesaplanmadı):** $v(0) = 24\cdot 3/9 = 8\,\text{V}$, $R_{eq} = 3\,\Omega$, $\tau = 0.5\,\text{s}$, $v(t) = 8e^{-2t}\,\text{V}$. $w_C(0) = \tfrac12\cdot\tfrac16\cdot 64 = 5.333\,\text{J}$.

**Soru 3** (ekrandan, 00:33:57): $0.5\,\text{H}$, $2\,\Omega$, $4\,\Omega$ ve bağımlı kaynak $3i$ içeren devrede $i(0) = 10\,\text{A}$ ise $t>0$ için $i(t)$ ve $i_x(t)$'yi bulun.

> **Çözüm:** Derste: $R_{eq} = 1/3\,\Omega$, $\tau = 1.5\,\text{s}$, $i(t) = 10e^{-2t/3}\,\text{A}$. $i_x$ için derste verilen akım bölücü sonucu hatalıdır; doğrusu $i_x = \frac{L\,di/dt}{2} = -\frac53 e^{-2t/3}\,\text{A}$ (python ile doğrulandı).

**Soru 4** (ekrandan, 00:43:57): $2\,\text{H}$, $1\,\Omega$ ($v_x$), $2\,\Omega$, $6\,\Omega$ ve bağımlı kaynak $2v_x$ içeren devrede $i(0) = 12\,\text{A}$ ise $i$ ve $v_x$'i bulun.

> **Çözüm (derste bir öğrenci çözdü):** $v_x = -i_1$, $i_1 = 2i_2$, $2\frac{di}{dt} = -4i$. $i = 12e^{-2t}\,\text{A}$, $v_x = -12e^{-2t}\,\text{V}$.

**Soru 5** (ekrandan, 00:58:57): 15 A, $24\,\Omega$, $12\,\Omega$, $8\,\Omega$, $5\,\Omega$ ve $2\,\text{H}$ içeren devrede $t>0$ için $i(t)$'yi bulun.

> **Çözüm (derste bir öğrenci çözdü, hoca düzeltti):** $i(0) = 5\,\text{A}$; $t>0$'da $R_{eq} = (12+8)\parallel 5 = 4\,\Omega$, $\tau = 0.5\,\text{s}$, $i(t) = 5e^{-2t}\,\text{A}$.

**Soru 6** (ekrandan, 01:18:57): Şekildeki $i(t)$'yi (0'da 2, 1'de 0, 2'de $-2$, 3'te 0) tekillik fonksiyonlarıyla ifade edin ve terimleri ayrı ayrı çizin.

> **Çözüm (slaytta verildi):** $i(t) = 2u(t) - 2r(t) + 4r(t-2) - 2r(t-3)\,\text{A}$. Kontrol: $0 \le t \le 2$'de $2 - 2t$; $2 \le t \le 3$'te $2t - 6$; $t \ge 3$'te 0.

**Soru 7** (ekrandan, 01:13:57): 0–2 s arasında 10, 2–4 s arasında $-10$ olan akım darbesini birim basamakla ifade edin, integralini bulup çizin.

> **Çözüm (slaytta verildi):** $10[u(t) - 2u(t-2) + u(t-4)]$; integral $10[r(t) - 2r(t-2) + r(t-4)]$, $t=2$'de tepe değeri 20 olan üçgen.

**Soru 8** (ekrandan, 01:43:57): Fazör yöntemiyle $v_a(t)$'yi bulun ($20\cos 250t\,\text{V}$, $8\,\Omega$, $36\,\text{mH}$, $0.25\,\text{mF}$, $1.2\cos(250t+45^\circ)\,\text{A}$, $80\,\text{mH}$, $4v_a$).

> **Çözüm (slaytta verildi, işaret düzeltmesiyle):** $v_a(t) = 12.43\cos(250t - 81.2^\circ)\,\text{V}$; seri kol empedansı $8 + j9$ alınmalıdır.

## Dersin Toparlaması

Son derste birinci dereceden devrelerin çözüm yolu örneklerle pekiştirildi: önce $t<0$ kararlı halde (kondansatör açık, bobin kısa devre) başlangıç değeri bulunur, sonra anahtar konumu değiştikten sonra elemanın uçlarından görülen eşdeğer dirençle zaman sabiti hesaplanır, cevap $x(0)e^{-t/\tau}$ biçiminde yazılır ve diğer akım ve gerilimler bölücü kurallarıyla bulunur. Bağımlı kaynak varsa eşdeğer direnç test kaynağıyla bulunur ya da bobin/kondansatör denklemi doğrudan KVL'ye yazılıp diferansiyel denklem çözülür. Ardından basamak, rampa ve darbe fonksiyonlarıyla parçalı sinyallerin yazılması, son olarak da fazörlerle düğüm, süper düğüm, op-amp ve Norton eşdeğeri örnekleri çözüldü.

Hoca final için sunumlardaki çözümlü soruların, çözüme bakıp "anladım" demek yerine baştan kendi başına çözülmesini önerdi; sınav soruları bu örneklerin seri/paralel düzeni değiştirilmiş benzerleridir. Derste çözülmeyen ama önceki haftalarda anlatılan RLC cevap türleri ($\alpha$ ile $\omega_0$ karşılaştırmasına göre aşırı, kritik ve az sönümlü) de önemli konular arasında sayıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
