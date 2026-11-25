# Ders 11 Genişletilmiş Notu: Fazör Gösterimi, Karmaşık Sayılar ve Sinüzoidal İşaretlerin Özellikleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Zaman Boyutundan Fazör Uzayına: Sürekli Sinüzoidal Hal
- 2. Empedans ve Fazör Uzayında Devre Yapısı
- 3. Osiloskop Örneği: RLC Devresinde Giriş ve Çıkış Gerilimi
- 4. Karmaşık Sayılar: Kısa Tekrar
- 5. Fazör Uzayında Ohm Yasası Örneği
- 6. Fazör Uzayında Güç
- 7. Sinüzoidal İşaretin Özellikleri
- 8. Faz Açısı, Önde ve Geride Olma
- 9. Fazör Gösterimi ve Zaman-Fazör Dönüşümleri
- 10. Özel (Tekil) Fonksiyonlar
- Örnek Sorular
- Dersin Toparlaması

## 1. Zaman Boyutundan Fazör Uzayına: Sürekli Sinüzoidal Hal

Ders, önceki haftadan kalan fazör gösterimi konusuyla başladı. Hoca önce bu konunun nereden geldiğini hatırlattı. Önceki haftalarda RL, RC ve RLC devreleri **zaman boyutunda** çözülmüştü. RL ve RC devreleri birinci dereceden, RLC devreleri ikinci dereceden diferansiyel denklemlere götürüyordu. Kaynaklı ve kaynaksız durumlarda seri ve paralel RLC devreleri incelenmişti.

Zaman boyutundaki çözüm, eksi sonsuzdan artı sonsuza bütün zaman aralığını kapsar. Bu aralıkta üç özel bölge vardır:

- Devrenin uzun süre kararlı (DC) şartlarda kaldığı, anahtarla durum değişimine kadar geçen bölge.
- Durum değişiminden sonra elemanlarda depolanmış enerjiden ve doğal çözümden kaynaklanan, pratikte yaklaşık $5\tau$ süren geçici hal.
- $5\tau$'dan sonra devrenin yeniden uzun süre kararlı kaldığı bölge.

**Fazör çözümü** ise özel bir çözümdür. Fazör yaklaşımı geçici hal analiziyle ilgilenmez. Geçici etki kuramsal olarak sonsuza kadar sürse de pratikte $5\tau$ sonunda bittiği kabul edilir; fazör analizi bu andan sonraki davranışa bakar. Devrede birim basamak gibi bir zorlayıcı kaynak yerine belirli frekanslı **sinüzoidal bir kaynak** vardır. Geçici haller bittiği için devrede yalnız zorlanmış cevabın etkisi kalır ve bu etki doğrudan fazör yaklaşımıyla görülebilir. Bu analize **sürekli sinüzoidal hal analizi** denir.

Fazör yaklaşımının önemli özelliği şudur: kapasite ve endüktansın tanım bağıntıları zaman boyutunda diferansiyel denklemdir (örneğin $v_L(t) = L\,\dfrac{di_L(t)}{dt}$, ekrandan, 00:15:00). Bu bağıntılar fazör uzayına geçirildiğinde **doğrusal denklemlere** dönüşür; tıpkı direncin $v = Ri$ bağıntısı gibi. Bu yüzden fazör uzayında her şey dirençmiş gibi davranır.

Hoca uygulama adımlarını şöyle özetledi:

1. Eleman tanım bağıntılarını ve kaynakları fazör uzayına geçir; devre şeması artık fazör uzayındadır.
2. Devreyi fazör uzayındaki değerlerle, yani her elemanı bir empedans gibi düşünerek çöz.
3. İlgilenilen değişkeni (bir elemanın gerilimi ya da akımı) fazör uzayında bul.
4. Bu değeri zaman boyutuna geri çevir; böylece değişkenin zamana göre değişimi elde edilir.

Zamandan fazöre ve fazörden zamana geçmek kolaydır. Asıl kazanç, zaman boyutunda diferansiyel denklem çözmek yerine fazör uzayında doğrusal denklemler çözülmesidir.

Hoca seri ve paralel RLC devrelerinde $\alpha$ ve $\omega_0$ değerlerinin nasıl hesaplandığı ve hangi durumda hangi çözümün önerildiği bilgilerinin büyük olasılıkla verileceğini söyledi.

> **Hocanın vurgusu:** Bu formülleri çok ezberlemeye gerek yok; onları nasıl kullanacağımız üzerine kafa yormak daha anlamlı.

## 2. Empedans ve Fazör Uzayında Devre Yapısı

Hoca fazör uzayında karşılaşılacak devrenin örneğini slayttan gösterdi (ekrandan, 00:15:00). Slaytın başlığı "Why do we need to use Complex Numbers?" idi. Devre şöyledir:

| Eleman | Fazör uzayındaki değer | Konum |
|---|---|---|
| Kaynak | $\mathbf{V}_s = 120\angle0^\circ$ V (sinüzoidal) | En solda, akımı $\mathbf{I}_s$ |
| Kutu ile gösterilen bilinmeyen eleman | $40\angle30^\circ\ \Omega$ | Kaynağa paralel ilk kol, akımı $\mathbf{I}_1$ |
| Direnç + kapasite (seri) | $50\ \Omega$ ve $-j30\ \Omega$ | İkinci paralel kol, akımı $\mathbf{I}_2$ |
| Direnç + endüktans (seri) | $30\ \Omega$ ve $j40\ \Omega$ | Üçüncü paralel kol, akımı $\mathbf{I}_3$ |

Bu devrede dikkat çeken noktalar:

- Direncin fazör uzayındaki empedansı kendi değeridir ($50\ \Omega$, $30\ \Omega$).
- Kapasite ve endüktansın $C$ ve $L$ değerleri yerine bunlara karşılık hesaplanmış karmaşık empedanslar ($-j30\ \Omega$, $j40\ \Omega$) yazılmıştır.
- Bir ya da birden fazla elemandan oluşan bir alt devre de giriş-çıkış karakteristiği olarak tek bir karmaşık sayıyla ($40\angle30^\circ\ \Omega$ gibi) ifade edilebilir.

Sinüzoidal kaynağın zaman boyutundaki karşılığı $A\sin(\omega t + \phi)$ biçimindedir; $A$, $\omega$ ve $\phi$ birer değer alır (ekrandan, 00:15:00). Fazör uzayına geçildiğinde direnç, kapasite, endüktans ayrımı kalmaz. Her elemanın sinüzoidal (AC) akıma gösterdiği "direnç" vardır ve bunun adı **empedanstır**.

Empedans, fazör uzayında eleman üzerindeki gerilimin, elemandan geçen akıma oranıdır. Hoca tahtaya $\mathbf{V}_L/\mathbf{I}_L$ yazdı; yani endüktansın zaman boyutunda $L\,di/dt$ olan diferansiyel bağıntısı fazör uzayında doğrusal bir bağıntıya dönüşmüştür. Empedanslar dirençler gibi davrandığı için:

- Seri empedanslar toplanarak eşdeğer empedans bulunur.
- Paralel empedanslar paralel dirençler gibi birleştirilir.
- Empedanslar üzerinden düğüm denklemleri ya da çevre akımları yöntemiyle devre çözülebilir.

Sonuçta her büyüklük karmaşık sayı olarak bulunur. Örneğin $\mathbf{I}_1$ bir genlik ve bir açıyla elde edilir. Bunu zaman boyutundaki $i_1(t)$'ye çevirmek için fazörde görünmeyen **saklı bir parametre** gerekir: kaynağın açısal frekansı $\omega$.

Devrede bir sinüzoidal kaynak (ya da aynı frekanslı birden fazla kaynak) varsa, kararlı halde devredeki bütün elemanların zaman boyutundaki salınımı kaynak frekansındadır. Kaynak $B\sin(\omega t + \theta)$ ise buradaki $\omega$ bütün elemanların salınımını belirler. Fazörden zamana dönerken genlik ve açı fazörden, $\omega$ ise kaynaktan alınır.

## 3. Osiloskop Örneği: RLC Devresinde Giriş ve Çıkış Gerilimi

Hoca önceki hafta atlanan bir örneğe ayrıntılı baktı (ekrandan, 00:20:00, slayt başlığı "Input Voltage vs Output Voltage").

### 3.1 Devre

| Eleman | Değer | Bağlantı |
|---|---|---|
| Kaynak $v_s$ | $v_s = \sin(2\pi f t)$ V | Sol kol, artı ucu üstte |
| Direnç | $235\ \Omega$ | Kaynağın artı ucundan üst düğüme seri |
| Kapasite | $4.7$ nF | Üst düğüm ile alt (toprak) düğüm arasında |
| Endüktans | $1$ mH | Kapasiteye paralel, aynı iki düğüm arasında |
| Çıkış $v_o$ | Paralel LC üzerindeki gerilim | Artı ucu üst düğüm |

Devre önce $f = 5$ kHz ile, sonra daha yüksek bir frekansla çalıştırılarak çıkış gerilimi incelenir. Açısal frekans ile frekans arasındaki ilişki de hatırlatıldı: açısal hız $\omega$ ile dönen bir nokta bir periyotta $2\pi$ radyan ($360^\circ$) tarar, dolayısıyla $\omega = 2\pi/T$; $1/T$ saniyedeki tekrar sayısı yani frekans olduğundan $\omega = 2\pi f$.

### 3.2 Ölçüm düzeni

Osiloskobun iki kanalı vardır, her kanalın artı ve eksi uçları timsah kıskaçlarla bağlanır (ekrandan, 00:20:00, kalemle "CH1 ±" ve "CH2 ±" notları):

- Kanal 1 (sarı/turuncu): artı ucu kaynağın artı ucunda, eksi ucu toprakta; giriş gerilimi $v_s$'yi ölçer.
- Kanal 2 (mavi): artı ucu endüktansın üst ucunda, eksi ucu toprakta; çıkış gerilimi $v_o$'yu ölçer.

Osiloskop ayarları ekranda görünüyor: yatay ölçek $20\ \mu s$/kare, iki kanalın dikey ölçeği $250$ mV/kare.

### 3.3 Periyot ve frekansın ekrandan okunması (5 kHz)

Hoca giriş işaretinin bir tepesinin kaç kare tuttuğunu saydı. İlk anda dört kare dedi, sonra her tepenin **beş** kare olduğunu düzeltti.

- Bir tam periyot iki tepeden (bir çıkan, bir inen) oluşur.
- Her tepe 5 kare, her kare $20\ \mu s$: $T = 2 \times 5 \times 20\ \mu s = 200\ \mu s = 200\times10^{-6}$ s.
- $f = \dfrac{1}{T} = \dfrac{1}{200\times10^{-6}} = \dfrac{10^6}{200} = 5000$ Hz $= 5$ kHz.

Çıkış işaretinde de bir periyot iki tepeden, her tepe 5 kareden oluşur; çıkışın periyodu da $200\ \mu s$, frekansı $5$ kHz'tir.

Buradan iki sonuç çıkar:

1. Kaynak frekansı neyse çıkış işaretinin frekansı da odur. Bu yüzden devre çizilirken kaynağın frekans bilgisi ayrı tutulabilir; fazör hesabında $\omega$ ayrı saklanır.
2. Bu devrede 5 kHz'te çıkış, girişin çok bastırılmış (sönümlenmiş) bir halidir.

### 3.4 Düşük ve yüksek frekansta devre

Hoca devreyi uç durumlar üzerinden yorumladı (ekrandan, 00:25:00, kalemle "$f \to 0$: $v_s = $ DC").

- **$f \to 0$ (DC):** Kapasite açık devre, endüktans kısa devre olur. Çıkış uçları bir tel ile kısa devre edilmiş olur; tel üzerinde gerilim düşümü olmadığından $v_o = 0$. Girişe 10 V DC uygulansa bile çıkış sıfırdır. Devre düşük frekanslı işaretleri süzer, geçirmez.
- **$f \to \infty$:** Kapasite kısa devreye, endüktans açık devreye dönüşür. Çıkış uçları yine kapasitenin kısa devresiyle birleşir; $v_o$ yine sıfıra gider.

Çıkış/giriş oranı frekansa göre çizilirse düşük ve yüksek frekanslarda sıfır, arada bir frekans bölgesinde geçişe izin veren bir eğri çıkar. Yani bu devre **bant geçiren bir süzgeç** gibi çalışır. Hoca bunun iki özel (kesim) noktası olduğunu söyledi: birinde geçirmeye, diğerinde kesmeye başlar.

> **Ek bilgi (derste anlatılmadı):** Paralel LC kolunun empedansı $\omega_0 = 1/\sqrt{LC}$ frekansında sonsuza gider, bu yüzden çıkış bu frekansta girişe eşit olur. Bu devrede $f_0 = \dfrac{1}{2\pi\sqrt{10^{-3}\cdot4.7\times10^{-9}}} \approx 73.4$ kHz'tir (python ile hesaplandı).

### 3.5 Orta frekansta giriş ve çıkış

Giriş frekansı orta bir değere (hoca 50 kHz dedi) çekildiğinde giriş ve çıkışın frekansları yine aynıdır, ama çıkışın genliği girişe çok yaklaşmıştır; sönümleme çok azalmıştır. Ayrıca iki işaretin tepe noktaları aynı anda değildir: aralarında bir **faz farkı** vardır. Orta frekansta faz farkı azalmış, düşük frekansta ise daha büyüktür. <!-- BELİRSİZ: 50 kHz ölçümünün slaytı karelerde görünmüyor; değer altyazıdan alındı. -->

Hoca bu tür RLC devrelerinde (fazör uzayında da görülecek) üç noktaya dikkat edilmesini istedi:

> **Hocanın vurgusu:** (1) Kaynak frekansı değiştikçe giriş ile çıkış arasındaki genlik oranı değişir. (2) Giriş ile çıkış arasındaki faz farkı değişir. (3) Uzun süre aynı sinüzoidal kaynakla sürülen devrede bütün elemanlar kaynak frekansında salınır.

### 3.6 Aynı devrenin fazörle çözümü (slayttaki örnek)

Fazör henüz tam tanımlanmadan, neyle karşılaşılacağını göstermek için slayttaki çözüm anlatıldı (ekrandan, 00:30:00). Kaynak $v_s = \sin(2\pi\cdot10^4\,t)$ V'tur.

- Sinüzoidler fazöre dönüşür: $\mathbf{V}_s = 1.00e^{j0^\circ}$ V. Bu, karmaşık düzlemde açısı $0^\circ$ olan, reel eksen üzerindeki bir noktadır.
- KCL/KVL/Ohm yasası fazörlerle çözülür. Üst düğüme $\mathbf{V}_o$ denir ve düğüm denklemi yazılır:

$$\frac{\mathbf{V}_o - \mathbf{V}_s}{R} + \frac{\mathbf{V}_o}{Z_C} + \frac{\mathbf{V}_o}{Z_L} = 0$$

- Slayttaki sonuç: $\mathbf{V}_o = 0.25e^{j40^\circ}$ V.
- Fazör sinüzoide geri döner: $v_o = 250\sin(2\pi\cdot10^4\,t + 40^\circ)$ mV.

Hoca bu dönüşte üç şeye dikkat çekti: frekans kaynağın frekansıyla aynıdır; faz açısı $+40^\circ$ olarak gelmiştir (kaynağın fazöründe açı sıfırdı); genlik $0.25$ V yani $250$ mV olarak doğrudan kullanılır. Kısacası fazörün genliği ve açısı doğrudan alınır, frekans kaynaktan eklenir.

Üstel gösterimdeki bir sayıyı kartezyene çevirmek için $x = 0.25\cos40^\circ$, $y = 0.25\sin40^\circ$ alınıp $x + jy$ yazılır.

> **Ders sonrası not:** Slaytta verilen eleman değerleriyle ($R = 235\ \Omega$, $C = 4.7$ nF, $L = 1$ mH) ve 10 kHz'te düğüm denklemi çözüldüğünde $\mathbf{V}_o \approx 0.263\angle74.8^\circ$ V çıkıyor (python ile hesaplandı). Slayttaki $0.25e^{j40^\circ}$ büyük olasılıkla yuvarlanmış ya da ölçümden alınmış temsili bir değerdir; yöntem aynıdır. Aynı hesap 5 kHz'te $\approx 0.133\angle82.4^\circ$, 50 kHz'te $\approx 0.928\angle21.9^\circ$ verir; bu, derste söylenen "5 kHz'te çok bastırılmış, orta frekansta girişe yakın ve daha az faz farklı" gözlemiyle uyumludur.

## 4. Karmaşık Sayılar: Kısa Tekrar

Hoca önceki haftada işlenen karmaşık sayı konularını hızlıca tekrar etti.

### 4.1 Tanımlar ve gösterimler

- $\sqrt{-1}$, $j$ ile gösterilir.
- Karmaşık sayı $Z$ ile gösterilir; reel kısmı $\mathrm{Re}(Z)$, sanal (imajiner) kısmı $\mathrm{Im}(Z)$'dir.
- Üç gösterim vardır: **kartezyen** $a + jb$, **üstel** $re^{j\theta}$, **polar** $r\angle\theta$.
- Karmaşık sayı iki boyutlu bir vektör gibi düşünülebilir; vektör toplaması burada da geçerlidir.
- **Eşlenik**, sayının reel eksene göre ayna görüntüsüdür: $Z = a + jb$ ise $Z^* = a - jb$.

### 4.2 İşlemler

- Toplama ve çıkarma kartezyen formda yapılır (ekrandan, 00:35:00): $X = a + jb$, $Y = c + jd$ ise $Z = X + Y = (a+c) + j(b+d)$; $\mathrm{Re}(Z) = a+c$, $\mathrm{Im}(Z) = b+d$.
- Çarpma ve bölme kartezyen formda da yapılabilir, ama polar ya da üstel formda daha kolaydır.
- Çarpma: genlikler çarpılır, açılar toplanır. Örneğin $V\angle\phi$ ile $I\angle\theta$ çarpılırsa genlik $VI$, açı $\phi + \theta$ olur.
- Bölme: $\dfrac{|Z_1|\angle\theta_1}{|Z_2|\angle\theta_2} = \dfrac{|Z_1|}{|Z_2|}\angle(\theta_1 - \theta_2)$. Üstel formda paydadaki $e^{j\theta_2}$ paya $e^{-j\theta_2}$ olarak çıkar; tabanlar aynı olduğu için üsler toplanır ve açı $\theta_1 - \theta_2$ olur. Hoca slayttaki bu formülde iki yazım hatası olduğunu ve doğru indislerin bunlar olduğunu belirtti.

> **Hocanın vurgusu:** Çarpma ve bölme işlemlerini polar ya da üstel formda, toplama ve çıkarma işlemlerini kartezyen formda yapmak daha pratiktir.

### 4.3 Euler formülü

Euler formülü üstel form ile kartezyen form arasındaki geçişi sağlar:

$$e^{j\theta} = \cos\theta + j\sin\theta$$

Hoca ayrıntıya girmeden elde edilişini anlattı. $e^x$'in Taylor açılımı yazılır ve $x$ yerine $j\theta$ konur. Bunun için $j\theta$'nın kuvvetleri gerekir: $(j\theta)^0 = 1$, $(j\theta)^1 = j\theta$, $(j\theta)^2 = -\theta^2$, $(j\theta)^3 = -j\theta^3$, $(j\theta)^4 = \theta^4$. Yani $j$'nin kuvvetleri $1, j, -1, -j$ diye dörtlük periyotla tekrar eder. Aynı işlem $\cos x$ ve $\sin x$ açılımlarıyla karşılaştırılınca çift dereceli (0, 2, 4, ...) terimlerin toplamının $\cos\theta$'nın, tek dereceli terimlerin toplamının ise $j\sin\theta$'nın açılımına karşılık geldiği görülür.

### 4.4 Genlik ve açı dönüşümleri

Slayttaki bağıntılar (ekrandan, 00:40:00; $|z|$ pozitif reel varsayılır):

$$|z|e^{j\theta} = |z|\cos\theta + j|z|\sin\theta = a + jb$$

$$a = |z|\cos\theta,\quad b = |z|\sin\theta,\quad \frac{\sin\theta}{\cos\theta} = \tan\theta = \frac{b}{a}$$

$$a^2 + b^2 = |z|^2(\cos^2\theta + \sin^2\theta) = |z|^2 \;\Rightarrow\; |z| = \sqrt{a^2+b^2}$$

Faz açısı $\theta = \arctan(b/a)$ ile bulunur. Hoca slayttaki grafikteki $4 + 3j$ sayısını örnek verdi: karşı kenar 3, komşu kenar 4 olduğundan açı $\arctan(3/4)$'tür.

## 5. Fazör Uzayında Ohm Yasası Örneği

Hoca, kaynağın zaman boyutundan fazör uzayına nasıl geçirildiği henüz anlatılmadan, fazörler elde varken devrenin çözülebileceğini gösterdi (ekrandan, 00:45:00, slayt başlığı "Example: Ohm's Law").

Devre: bir gerilim kaynağı ve ona bağlı bir endüktans.

- Endüktans üzerindeki gerilim fazörü: $\mathbf{V}_L = -3\sqrt3 + 3j$ mV.
- Endüktanstan geçen akım fazörü: $\mathbf{I}_L = 1 + j\sqrt3$ mA.
- İstenen: $\mathbf{V}_L/\mathbf{I}_L$ oranı, yani endüktansın empedansı.

Empedans, dirençteki $v/i$ gibi fazör uzayında da gerilimin akıma oranıdır ve büyük $Z$ ile gösterilir. mV ile mA birbirini götürür, sonuç ohm cinsindedir.

### 5.1 Birinci yol: paydanın eşleniğiyle çarpma

$$Z_L = \frac{-3\sqrt3 + 3j}{1 + j\sqrt3}\cdot\frac{1 - j\sqrt3}{1 - j\sqrt3}$$

Pay:

$$(-3\sqrt3 + 3j)(1 - j\sqrt3) = -3\sqrt3 + 9j + 3j - 3\sqrt3\,j^2 = -3\sqrt3 + 12j + 3\sqrt3 = 12j$$

Payda: eşlenikle çarpımda sanal terimler birbirini götürür, kareler toplanır:

$$(1 + j\sqrt3)(1 - j\sqrt3) = 1 + 3 = 4$$

$$Z_L = \frac{12j}{4} = 3j\ \Omega$$

Bir endüktans için saf sanal bir empedans beklenir; sonuç bununla uyumludur.

### 5.2 İkinci yol: polar gösterim

Slayttaki formül: $\dfrac{v_L}{i_L} = \dfrac{|v_L|}{|i_L|}\angle(\theta_{VL} - \theta_{IL})$ (ekrandan, 00:45:00).

- Pay: genlik $\sqrt{(3\sqrt3)^2 + 3^2} = \sqrt{27 + 9} = 6$. Açı $\tan^{-1}\{1/(-\sqrt3)\}$. Hoca birim çember çizerek açıyı yorumladı: $1/\sqrt3$'e karşılık referans açı $30^\circ$'dir, ama reel kısım negatif, sanal kısım pozitif olduğundan sayı ikinci çeyrektedir; açı $180^\circ - 30^\circ = 150^\circ$. Pay $6\angle150^\circ$.
- Payda: genlik $\sqrt{1 + (\sqrt3)^2} = \sqrt4 = 2$, açı $\tan^{-1}\sqrt3 = 60^\circ$. Payda $2\angle60^\circ$.
- Bölüm: $\dfrac{6\angle150^\circ}{2\angle60^\circ} = 3\angle90^\circ$.

### 5.3 İki sonucun aynı olduğunu gösterme

$3\angle90^\circ$, merkezden 3 birim uzakta ve $90^\circ$ doğrultusunda, yani sanal eksen üzerindeki bir noktadır. Üstel formdan kartezyene çevrilirse:

$$3e^{j90^\circ} = 3(\cos90^\circ + j\sin90^\circ) = 3(0 + j) = 3j$$

İki yol aynı sonucu verir (python ile doğrulandı). Hoca bu noktada sanal empedansın zaman boyutundaki anlamının henüz bulunamayacağını, ama empedansın elde edildiğini söyledi.

## 6. Fazör Uzayında Güç

Hoca slayttaki bir güç denklemine geçti. Zaman boyutunda güç $p = vi$ idi. Fazör gösteriminde ise güç, eleman üzerindeki gerilim fazörü ile akım fazörünün **eşleniğinin** çarpımıyla bulunur:

$$\mathbf{S} = \mathbf{V}\,\mathbf{I}^*$$

Eşlenik almak, sanal kısmın işaretini değiştirmektir: $a + jb$'nin eşleniği $a - jb$'dir. Hoca bu çarpımın üç yolla yapılabileceğini gösterdi:

1. Gerilim ve akımın eşleniği kartezyen formda doğrudan çarpılır.
2. Kartezyen sonuç polar forma çevrilir: genlik orijine uzaklıktan, açı sanal kısmın reel kısma oranının arktanjantından bulunur.
3. Gerilim ve akım eşleniği önce ayrı ayrı polar forma çevrilir, sonra genlikler çarpılıp açılar toplanır.

Küsuratlar dışında üç yol aynı sonucu verir. <!-- BELİRSİZ: bu örneğin gerilim ve akım değerleri karelerde görünmüyor; altyazıdaki sayılar ("3 artı 4j", "6 eksi 7j", "17 ile 51") birbiriyle tutarlı değil, bu yüzden sayısal çözüm verilmedi. -->

> **Ders sonrası not:** Hoca dersin başında (00:36:17 civarı) güç için $\mathbf{V}\mathbf{I}$ çarpımını ve açının $\phi + \theta$ olacağını söyledi; slayttaki tanım ise $\mathbf{S} = \mathbf{V}\mathbf{I}^*$'dir. $\mathbf{V} = V\angle\phi$, $\mathbf{I} = I\angle\theta$ ise karmaşık gücün açısı $\phi - \theta$ olur.

Hoca bu noktada hâlâ karmaşık sayılarla işlemlere baktıklarını, zaman boyutundaki değişkenlerin fazöre nasıl geçtiğine ise henüz gelmediklerini belirtti.

## 7. Sinüzoidal İşaretin Özellikleri

Sürekli sinüzoidal hal analizinde kaynağın parametrelerini tanımak ve aynı frekanslı iki işaret arasındaki farkları ifade edebilmek gerekir. Slayttaki hedefler (ekrandan, 00:55:00): sinüzoidal dalganın özelliklerini tartışmak; periyot, frekans ve açısal frekans arasındaki ilişkiyi tanımlamak; genliğin nasıl tanımlandığını açıklamak; faz açısını ve geride (lagging) / önde (leading) işaret farkını anlatmak.

Slayttaki özellik listesi (ekrandan, 01:00:00):

- Bir çevrimin süresi ya da saniyedeki çevrim sayısı: periyot, frekans, açısal frekans.
- Gerilim ya da akımın en büyük ve en küçük salınımı: genlik, tepeden tepeye genlik, RMS değeri.
- Ortalama değer: DC ofset.
- İki sinüs dalgasının karşılaştırılması: faz açısı, geride ve önde işaretler.

### 7.1 Periyot, frekans ve açısal frekans

$A\sin(2\pi f t)$ biçiminde yazılan işarette $f$ doğrudan frekanstır. Aynı işaret $A\sin(\omega t)$ diye de yazılabilir; burada $\omega$ açısal frekanstır.

- **Periyot** $T$ (saniye): periyodik bir işaretin kendini tekrarlamaya başlaması için geçmesi gereken süre.
- **Frekans** $f = 1/T$ (hertz): işaretin bir saniyede kendini kaç kez tekrarladığı.

Hoca tahtaya bir sinüs çizip periyodun nerede bittiğini sordu. İşaret sıfırdan başlayıp artıyorsa, periyot işaretin yeniden sıfırdan geçip **artmaya** başladığı yerde biter; sıfırdan geçip azaldığı yer periyodun yarısıdır. Yani bir periyot bir çıkan ve bir inen tepeyi tam içerir. Periyot bir tepeden bir sonraki tepeye kadar olan süre olarak da okunabilir. Yatay ekseni kestiği noktalar ve tepe noktaları gibi anahtar noktalar periyodu okumayı kolaylaştırır.

### 7.2 Genlik

Hoca aynı eksende iki işaret çizdi (ekrandan, 01:00:00): $a = A\sin(2\pi f t)$ ve $b = B\sin(2\pi f t)$, $B < A$. Sorusu şuydu: a ve b arasında frekans ya da periyot farkı var mı? Cevap: yok. İkisi de tepeden bir sonraki tepeye aynı anlarda ulaşır; frekansları ve periyotları aynıdır. Fark yalnız tepe değerlerindedir. Sinüzoidal işaretin başındaki çarpan **genliktir**.

### 7.3 Tepeden tepeye genlik ve DC ofset

Saf sinüzoidal işaretin ortalaması sıfırdır: çeyrek periyot artıda, çeyrek periyot ekside, çeyrek ekside, çeyrek artıda kalır ve net toplam sıfırdır. İşarete sabit bir $C$ eklenirse, $v = A\sin(2\pi f t) + C$, işaretin ortalaması $C$ kadar yukarı ötelenir. Ötelenmiş işaret yatay ekseni kesmeyebileceği için sıfır eksenine göre genlik okumak zorlaşır. Bu durumda **tepeden tepeye genlik** kullanılır; sinüs için bu değer $2A$'dır.

### 7.4 Anlık değer

Anlık genlik, işaretin belirli bir $t_0$ anındaki değeridir; $t$ yerine bilinen sayısal $t_0$ konur ve sonuç sayısal olarak bulunur. Slayttaki örnek (ekrandan, 01:10:00):

$$v(t) = 5\,\text{V}\,\sin[(377\ \text{rad/s})\,t]$$

- $t = 0$ s: $v = 5\sin(0) = 0$ V.
- $t = 10$ ms: $v = 5\sin(377 \times 0.01) = 5\sin(3.77\ \text{rad}) = -2.94$ V (python ile doğrulandı).

### 7.5 Radyan ve derece

Açısal frekans radyan ya da derece cinsinden olabilir. Bir tam tur $360^\circ = 2\pi$ radyandır; dönüşüm doğru orantıyla yapılır. Örneğin $60^\circ$ için $x = \dfrac{60 \cdot 2\pi}{360} = \dfrac{\pi}{3}$ rad. Açısal frekansın $\omega = 2\pi/T = 2\pi f$ olduğu da aynı mantıkla görülür: bir periyotta $2\pi$ radyan taranır.

### 7.6 Ortalama değer

Bir işaretin ortalaması, bir periyot boyunca altında kalan alanın periyoda bölünmesidir:

$$V_{ort} = \frac{1}{T}\int_0^T v(t)\,dt$$

Hoca $v(t) = A\sin\omega t$ için integrali hesapladı. Sinüsün integrali eksi kosinüstür; $0$ ve $T$ sınırlarında $\omega T = 2\pi$ olduğundan $\cos(2\pi) = \cos 0 = 1$ ve fark sıfırdır. Yani saf sinüsün bir periyottaki ortalaması sıfırdır. Hoca önce $1/T$ çarpanını unuttuğunu söyleyip formülü düzeltti.

> **Ders sonrası not:** Hoca integralin katsayısını "$A$ çarpı $\omega$" dedi; doğrusu $\displaystyle\int A\sin\omega t\,dt = -\frac{A}{\omega}\cos\omega t$'dir. Sınırlar yerine konunca sonuç yine sıfırdır.

İşarete $B$ gibi bir DC ofset eklenmişse ortalama $B$ çıkar. Hoca slayttaki bir grafikte ortalamanın 5'e çıktığını, dolayısıyla DC bileşenin 5 olduğunu grafikten okudu.

### 7.7 RMS (etkin) değer

RMS (root mean square) değeri, işaretin karesinin bir periyottaki ortalamasının kareköküdür (ekrandan, 01:15:00):

$$V_{RMS} = \sqrt{\frac{1}{T}\int_0^T [v(t)]^2\,dt}$$

Anlamı şudur: sinüzoidal işaret bir dirence uygulanınca harcanan gücü hesaplayıp not edelim; aynı dirençte aynı gücü bir DC kaynakla harcatmak istersek bu DC değer işaretin RMS değeridir. Slayta göre sinüzoidal genliği ölçen cihazların çoğu sonucu RMS olarak gösterir (birim Vac ya da $V_{RMS}$); RMS gerilim ve akım bir çevrimdeki ortalama gücü hesaplamakta kullanılır.

$$V_{RMS} = \frac{\sqrt2}{2}V_p = 0.707\,V_p,\qquad P_{ort} = \frac{V_{RMS}^2}{R}$$

Hoca $v = A\sin\omega t$ için ispatın anahtarını gösterdi. Karesi $A^2\sin^2\omega t$'dir ve $\sin^2$'nin integralini almak zordur. Bunun için iki özdeşlik birleştirilir:

$$\cos^2 x + \sin^2 x = 1,\qquad \cos(x + x) = \cos^2 x - \sin^2 x$$

Birinciden ikincisi çıkarılınca $1 - \cos2x = 2\sin^2 x$, yani

$$\sin^2 x = \frac{1 - \cos2x}{2}$$

Böylece ikinci dereceden sinüs birinci dereceden kosinüse indirgenir. $\cos2x$'in bir periyottaki integrali sıfır olduğundan $\frac1T\int_0^T A^2\sin^2\omega t\,dt = \dfrac{A^2}{2}$ kalır ve $V_{RMS} = A/\sqrt2$ bulunur (python ile sayısal olarak doğrulandı: $\approx 0.7071A$).

### 7.8 Fazör analizinin önemi

Hoca fazör analizinin neden önemli olduğunu örneklerle anlattı (slaytta da: 60 Hz güç şebekesi, 900 MHz cep telefonu, 2.4 GHz kablosuz internet; ekrandan, 00:15:00):

- Şehir şebeke gerilimleri AC (sinüzoidal) olarak dağıtılır.
- Pek çok haberleşme modülasyonu sinüzoidal işaretler üzerinden çalışır.
- Karmaşık işaretler, Fourier analiziyle sinüzoidal işaretlerin doğrusal toplamı olarak yazılabilir. Devre tek bir sinüzoidal kaynak için çözüldüğünde elde bir araç olur: farklı frekanslı bileşenler için analiz tekrarlanarak genel çözüm aynı yolla elde edilir.

Şebeke frekansı pek çok ülkede 60 Hz, Türkiye'de ve Avrupa'da 50 Hz'tir. Hoca bunun etkisini bir EKG cihazıyla örnekledi: Türkiye'de kullanılan bir cihazın düzgün görüntü verebilmesi için 50 Hz civarındaki şebeke gürültüsünü dar bantta süzen bir **çentik (notch) süzgeci** olması gerekir; Amerika'da kullanılan bir cihazda bu süzgeç 60 Hz'te olur.

## 8. Faz Açısı, Önde ve Geride Olma

### 8.1 Faz açısının anlamı

Aynı periyotlu ($T$) iki işaret çizildiğinde tepe noktaları aynı anlara denk gelmeyebilir. Bu durumda

$$a = A\sin(2\pi f t + \phi_1),\qquad b = B\sin(2\pi f t + \phi_2)$$

yazılır ve $\phi_1 \neq \phi_2$'dir. Faz açısı, fonksiyonu zaman ekseninde bütünüyle kaydıran parametredir. Örneğin $A\sin(2\pi f t)$ işaretini tepe noktası $90^\circ$ sonra gelecek biçimde sağa kaydırırsak $A\sin(2\pi f t - 90^\circ)$ elde ederiz. Genlikleri ve frekansları aynı olan bu iki işareti ayıran tek şey faz açısı farkıdır. Frekansları aynı olan işaretler için "hangisi önde, hangisi geride" yorumu bu sayede yapılabilir. İngilizcede önde olmaya *lead*, geride olmaya *lag* denir.

### 8.2 Faz karşılaştırma kuralları

İki sinüzoidal işaretin faz açısını karşılaştırmak için:

1. İki işaretin **frekansı aynı** olmalıdır.
2. İkisi de **aynı trigonometrik fonksiyonla** (ikisi de kosinüs ya da ikisi de sinüs) yazılmalıdır.
3. **Genlikler pozitif** olmalıdır. Örneğin $-2\sin\omega t$ gibi negatif genlik uygun trigonometrik dönüşümle açının içine alınmalıdır.
4. Aradaki fark $180^\circ$'den büyük çıkarsa dönüşümlerle $0$-$180^\circ$ aralığına getirilmelidir.
5. Faz farkı, birinci işaretin açısından ikinci işaretin açısı çıkarılarak bulunur.

### 8.3 Sinüs-kosinüs dönüşümünün türetilmesi

Hoca dik üçgen ve birim çember üzerinden özdeşlikleri türetti (ekrandan, 01:30:00).

Dik üçgende $x$ açısının karşısındaki kenar $a$, hipotenüs $b$ olsun: $\sin x = a/b$. Diğer dar açı $90^\circ - x$'tir ve $a$ bu açının komşu kenarıdır. Hoca önce bunu $\sin(90^\circ - x)$ diye yazıp birim çemberde $\sin\alpha = \sin(180^\circ - \alpha)$ özdeşliğini kullandı; sonra bunun kosinüs olması gerektiğini fark edip düzeltti. Doğrusu:

$$\sin x = \frac{a}{b} = \cos(90^\circ - x)$$

Birim çemberde $\alpha$ açısının yatay eksene izdüşümü $\cos\alpha$'dır; $-\alpha$ açısının izdüşümü de aynı yere düşer, yani $\cos\alpha = \cos(-\alpha)$. Bu yüzden

$$\sin x = \cos(90^\circ - x) = \cos(x - 90^\circ)$$

Sinüsü kosinüse çevirmek için açıdan $90^\circ$ çıkarılır.

Negatif genlikten kurtulmak için yine birim çember kullanıldı. $\alpha$ açısının kosinüsü $a$ ise, $180^\circ - \alpha$ açısının yatay izdüşümü $-a$'dır: $\cos\alpha = -\cos(180^\circ - \alpha)$. Kosinüs çift fonksiyon olduğundan bu, $\cos\alpha = -\cos(\alpha - 180^\circ)$ diye de yazılabilir. Hoca ikinci biçimi seçti, çünkü $\omega t$ teriminin işareti pozitif kalmalıdır; aksi halde bir işaret $20$, diğeri $-20$ açısal frekanslı gibi görünürdü. Sonuç: kosinüsün önünde eksi varsa açıdan $180^\circ$ çıkarılarak eksi kaldırılır.

### 8.4 Örnek: $v_1$ ile $v_2$ arasındaki faz farkı

Slayttaki örnek (ekrandan, 01:30:00 ve 01:35:00):

$$v_1(t) = 6\,\text{V}\sin(20t + 40^\circ),\qquad v_2(t) = -4\,\text{V}\cos(20t + 20^\circ)$$

**Kosinüs formunda:**

- $v_1$ sinüs olduğu için kosinüse çevrilir: $v_1 = 6\cos(20t + 40^\circ - 90^\circ) = 6\cos(20t - 50^\circ)$.
- $v_2$'nin önünde eksi var: $v_2 = 4\cos(20t + 20^\circ - 180^\circ) = 4\cos(20t - 160^\circ)$.
- Faz farkı: $-50^\circ - (-160^\circ) = 110^\circ$. Sonuç pozitif olduğundan $v_1$, $v_2$'den $110^\circ$ öndedir.

**Sinüs formunda:**

- $v_1 = 6\sin(20t + 40^\circ)$ aynen kalır.
- $v_2 = 4\sin(20t + 20^\circ - 90^\circ) = 4\sin(20t - 70^\circ)$.
- Faz farkı: $40^\circ - (-70^\circ) = 110^\circ$.

İki yol aynı sonucu verir (dönüşümler python ile sayısal olarak doğrulandı). Hoca slaytın üst kısmındaki diğer örneklerin de aynı kurallarla çözüleceğini, slaytta bir dönüşüm tablosu da bulunduğunu söyledi.

## 9. Fazör Gösterimi ve Zaman-Fazör Dönüşümleri

### 9.1 Fazörün karmaşık düzlemdeki yeri

Fazör gösteriminde bir genlik ve bir faz açısı vardır; kartezyen düzlemde bunlar $x$ ve $y$ bileşenlerine karşılık gelir. Genlik her zaman pozitif seçilirse:

| Açı | Sayının türü | Örnek |
|---|---|---|
| $0^\circ$ | Pozitif saf reel | $A$ |
| $180^\circ$ (ya da $-180^\circ$) | Negatif saf reel | $-A$ |
| $90^\circ$ | Pozitif saf sanal | $jA$ |
| $-90^\circ$ | Negatif saf sanal | $-jA$ |

### 9.2 Zamandan fazöre ve fazörden zamana

Slayttaki gösterimler (ekrandan, 01:40:00, başlık "Phasor Representation"):

- Polar: $\mathbf{V} = V_m\angle\phi$
- Kartezyen (sinüs ve kosinüslerin toplamı): $\mathbf{V} = V_m[\cos\phi + j\sin\phi]$, $x = V_m\cos\phi$, $y = V_m\sin\phi$
- Üstel: $\mathbf{V} = V_m e^{j\phi}$
- Karşılık gelen sinüzoidal fonksiyon: $v(t) = V_m\cos(\omega t + \phi)$

Zamandan fazöre geçerken işaretin açısal frekansı $\omega$ ayrı bir yere not edilir; geri kalan genlik $V_m$ ve açı $\phi$ polar fazörü verir: $V_m\angle\phi$.

Fazörden zamana geçerken (kosinüs esaslı dönüşümde) üstel fazörün reel kısmı alınır ve dışarıda tutulan $e^{j\omega t}$ çarpanı geri eklenir:

$$v(t) = \mathrm{Re}\{V_m e^{j\phi}\,e^{j\omega t}\} = \mathrm{Re}\{V_m e^{j(\omega t + \phi)}\} = V_m\cos(\omega t + \phi)$$

Fazör uzayında denklemler çözülürken her şey sanki $e^{j\omega t}$ parantezine alınmış gibidir; devre çözülürken bu terimle ilgilenmeye gerek yoktur. Zaman boyutuna dönerken yeniden bu çarpanla çarpılır.

### 9.3 Dönüşüm tablosu

Slayttaki tablo (ekrandan, 01:45:00, başlık "Sinusoid-Phasor Transformations"):

| Zaman boyutu | Fazör boyutu |
|---|---|
| $V_m\cos(\omega t + \phi)$ | $V_m\angle\phi$ |
| $V_m\sin(\omega t + \phi)$ | $V_m\angle(\phi - 90^\circ)$ |
| $I_m\cos(\omega t + \theta)$ | $I_m\angle\theta$ |
| $I_m\sin(\omega t + \theta)$ | $I_m\angle(\theta - 90^\circ)$ |

Varsayım: $V_m$ pozitiftir ve $-180^\circ \le \phi \le 180^\circ$.

Kaynak kosinüs biçimindeyse genlik ve açı doğrudan fazörde kullanılır. Sinüs biçimindeyse önce kosinüse çevrilir: $V_m\sin(\omega t + \phi) = V_m\cos(\omega t + \phi - 90^\circ)$; açısal frekans not edilir, faz açısı $\phi - 90^\circ$ olur. Aynı dönüşüm gerilim kaynakları ve akım kaynakları için geçerlidir; devredeki sinüzoidal kaynakların fazör karşılıkları bu şekilde bulunur.

Gösterim olarak fazör uzayındaki büyüklükler büyük harfle, kitaplarda ise koyu harfle yazılır; böylece zaman boyutundaki büyüklüklerden ayrılır.

### 9.4 Örnek: $3\sin(100t + 20^\circ)$

Slayttaki örnek (ekrandan, 01:50:00):

$$3\,\text{V}\sin(100t + 20^\circ) = 3\,\text{V}\cos(100t + 20^\circ - 90^\circ) = 3\,\text{V}\cos(100t - 70^\circ)$$

Fazör: $3\,\text{V}\angle{-70^\circ}$. Bu fazör üstel olarak $3e^{-j70^\circ}$, kartezyen olarak $3\cos(-70^\circ) + j\,3\sin(-70^\circ) \approx 1.026 - j2.819$ diye de yazılabilir (python ile hesaplandı).

### 9.5 Örnek: $7\sin(350t - 100^\circ)$

Slayttaki örnek (ekrandan, 01:50:00):

$$7\,\text{A}\sin(350t - 100^\circ) = 7\,\text{A}\cos(350t - 190^\circ)$$

Sinüs kosinüse çevrilirken $90^\circ$ çıkarılınca açı $-190^\circ$ olur; bu, $[-180^\circ, 180^\circ]$ aralığında değildir. Hoca bunu birim çemberle çözdü: $\cos(180^\circ + \alpha) = \cos(180^\circ - \alpha) = -\cos\alpha$. Buna göre

$$7\cos(350t - 190^\circ) = -7\cos(350t - 10^\circ) = 7\cos(350t + 170^\circ)$$

Açısal frekans pozitif, genlik pozitif, açı aralıkta olduğuna göre fazör yazılabilir: $7\,\text{A}\angle170^\circ$ (dönüşümler python ile sayısal olarak doğrulandı).

### 9.6 Polar ve kartezyen arasında geçiş örnekleri

- $5 + 3j$ gerilimi polar forma: genlik $\sqrt{5^2 + 3^2} = \sqrt{34} \approx 5.83$, açı $\arctan(3/5) \approx 31^\circ$. Yani $5.83\angle31^\circ$.
- $0.472\angle32^\circ$ empedansı kartezyen forma: $x = 0.472\cos32^\circ \approx 0.400$, $y = 0.472\sin32^\circ \approx 0.250$; yani $\approx 0.400 + j0.250$ (python ile hesaplandı). <!-- BELİRSİZ: bu iki örneğin slaytı karelerde görünmüyor; değerler altyazıdan alındı, kartezyen sonucun sayısal değeri derste söylenmedi. -->

## 10. Özel (Tekil) Fonksiyonlar

Hoca son olarak özel fonksiyonlara kısaca değindi; bu konunun daha önce ortak derste başka bir hoca tarafından da anlatıldığını hatırlattı. Sinüzoidal fonksiyon süreklidir ve sonsuz kez türevlenebilir. Genel çözüm için ise süreksiz olan ya da türevi süreksiz olan, bu yüzden bir noktada integrali ya da türevi alınamayan fonksiyonların da tanımlanması gerekir.

Slayttaki liste (ekrandan, 01:55:00, başlık "Singularity Functions"): süreksiz ya da türevi süreksiz fonksiyonlardır; **anahtarlama fonksiyonları** diye de bilinirler. Bunlar impuls fonksiyonu, birim (basamak) fonksiyonu, darbe fonksiyonu, kare dalga ve rampa fonksiyonlarıdır (üçgen ve testere dişi). Bu fonksiyonların birleşimleriyle karmaşık bileşik dalga biçimleri tanımlanabilir.

**Birim basamak fonksiyonu** $u(t - t_0)$, $t_0$ anına kadar 0'da kalır, sonra 1'e çıkar ve 1'de kalır:

$$u(t - t_0) = \begin{cases} 0, & t < t_0 \\ 1, & t > t_0 \end{cases}$$

Bu, bir anahtarın kapanmasına karşılık gelir. Ters yönlü basamak (önce 1, sonra 0) $1 - u(t - t_0)$ ile elde edilir: $t < t_0$ için $1 - 0 = 1$, $t > t_0$ için $1 - 1 = 0$.

**İmpuls fonksiyonu** $\delta(t - t_0)$: birim basamağın türevi alındığında, basamağın düz kısımlarında türev sıfırdır, ama $t_0$ anında sonsuz büyük bir türev vardır. İmpuls fonksiyonu budur; $t \neq t_0$ için sıfırdır. Hoca önce $t = t_0$'da değerini 1 diye söyledi, sonra tek bir değer olarak değil, integrali 1 olacak şekilde tanımlandığını belirterek düzeltti.

> **Ek bilgi (derste anlatılmadı):** İmpuls fonksiyonunun standart tanımı $\delta(t - t_0) = 0$ ($t \neq t_0$) ve $\displaystyle\int_{-\infty}^{\infty}\delta(t - t_0)\,dt = 1$'dir; birim basamakla ilişkisi $\delta(t - t_0) = \dfrac{d}{dt}u(t - t_0)$ şeklindedir.

Hoca dersi bu noktada bitirdi; dersin kalan bölümü RLC devrelerinin zaman boyutunda çözümüne ilişkin ayrı bir problem çözümü oturumuna ayrıldı.

## Örnek Sorular

**Soru 1** (ekrandan, 00:20:00 ve 00:25:00): $v_s = \sin(2\pi f t)$ V kaynağı, seri $235\ \Omega$ direnç ve çıkışta paralel bağlı $4.7$ nF kapasite ile $1$ mH endüktanstan oluşan devrede çıkış $v_o$ paralel LC üzerindedir. Osiloskopta yatay ölçek $20\ \mu s$/kare ve işaretin her tepesi 5 kare tutuyorsa (a) giriş frekansı nedir, (b) $f \to 0$ ve $f \to \infty$ için $v_o$ ne olur, (c) devre nasıl bir süzgeçtir?

> **Çözüm (derste verildi):** (a) Bir periyot iki tepedir: $T = 2\times5\times20\ \mu s = 200\ \mu s$, $f = 1/T = 5$ kHz. Çıkışın frekansı da 5 kHz'tir. (b) $f \to 0$'da kapasite açık, endüktans kısa devre: $v_o = 0$. $f \to \infty$'da kapasite kısa, endüktans açık devre: $v_o = 0$. (c) Düşük ve yüksek frekansları bastırıp ara frekansları geçirdiği için bant geçiren süzgeçtir.

**Soru 2** (ekrandan, 00:45:00): Bir endüktans üzerindeki gerilim fazörü $-3\sqrt3 + 3j$ mV, akım fazörü $1 + j\sqrt3$ mA ise $v_L/i_L$ oranı (empedans) nedir?

> **Çözüm (derste verildi):** Eşlenikle çarpma: $\dfrac{(-3\sqrt3+3j)(1-j\sqrt3)}{4} = \dfrac{12j}{4} = 3j\ \Omega$. Polar yol: $\dfrac{6\angle150^\circ}{2\angle60^\circ} = 3\angle90^\circ = 3j\ \Omega$.

**Soru 3** (derste sözlü, 00:59:09; ekrandan, 01:00:00): $a = A\sin(2\pi f t)$ ve $b = B\sin(2\pi f t)$ ($B < A$) işaretleri arasında frekans ya da periyot farkı var mıdır?

> **Çözüm (derste verildi):** Yoktur. İkisi de tepeden bir sonraki tepeye aynı anlarda ulaşır; frekansları ve periyotları aynıdır. Fark yalnız genliktedir.

**Soru 4** (ekrandan, 01:10:00): $v(t) = 5\sin(377t)$ V işaretinin $t = 0$ ve $t = 10$ ms anlarındaki anlık değerleri nedir?

> **Çözüm (derste verildi):** $v(0) = 0$ V; $v(0.01) = 5\sin(3.77) = -2.94$ V.

**Soru 5** (derste sözlü, 01:08:50): $60^\circ$ kaç radyandır?

> **Çözüm (derste verildi):** $x = \dfrac{60\cdot2\pi}{360} = \dfrac{\pi}{3}$ rad.

**Soru 6** (ekrandan, 01:30:00): $v_1(t) = 6\sin(20t + 40^\circ)$ V ve $v_2(t) = -4\cos(20t + 20^\circ)$ V arasındaki faz farkı nedir, hangisi öndedir?

> **Çözüm (derste verildi):** $v_1 = 6\cos(20t - 50^\circ)$, $v_2 = 4\cos(20t - 160^\circ)$; fark $-50^\circ - (-160^\circ) = 110^\circ$, $v_1$ $110^\circ$ öndedir. Sinüs formunda $v_2 = 4\sin(20t - 70^\circ)$ ve fark yine $110^\circ$'dir.

**Soru 7** (ekrandan, 01:50:00): $3\sin(100t + 20^\circ)$ V ve $7\sin(350t - 100^\circ)$ A işaretlerinin fazör gösterimleri nedir?

> **Çözüm (derste verildi):** $3\sin(100t + 20^\circ) = 3\cos(100t - 70^\circ) \Rightarrow 3\,\text{V}\angle{-70^\circ}$. $7\sin(350t - 100^\circ) = 7\cos(350t - 190^\circ) = -7\cos(350t - 10^\circ) = 7\cos(350t + 170^\circ) \Rightarrow 7\,\text{A}\angle170^\circ$.

## Dersin Toparlaması

Bu derste zaman boyutundaki RLC çözümlerinden sürekli sinüzoidal hal analizine geçişin mantığı kuruldu. Sinüzoidal bir kaynakla uzun süre sürülen doğrusal bir devrede geçici haller söndükten sonra bütün gerilim ve akımlar kaynak frekansında salınır; bu yüzden her büyüklük yalnız genlik ve fazla, yani bir fazörle tanımlanabilir. Fazör uzayında kapasite ve endüktansın diferansiyel bağıntıları empedanslı doğrusal bağıntılara dönüşür ve devre, dirençli devreler gibi seri-paralel birleştirme, düğüm ve çevre yöntemleriyle çözülür. Osiloskop örneği, frekansla genlik oranının ve faz farkının değiştiğini, salınım frekansının ise değişmediğini gösterdi. Karmaşık sayı işlemleri, empedans hesabı ve güç ($\mathbf{S} = \mathbf{V}\mathbf{I}^*$) bu çerçevede tekrar edildi.

Dersin ikinci yarısında sinüzoidal işaretin parametreleri (periyot, frekans, açısal frekans, genlik, tepeden tepeye genlik, anlık değer, ortalama, RMS) ve aynı frekanslı iki işaretin faz karşılaştırma kuralları işlendi. Zaman-fazör dönüşüm tablosu kuruldu: kosinüs doğrudan, sinüs ise $-90^\circ$ eklenerek fazöre çevrilir; negatif genlik ve aralık dışı açılar trigonometrik özdeşliklerle düzeltilir. Son olarak birim basamak ve impuls gibi tekil fonksiyonlara giriş yapıldı. Dersin ardından RLC devrelerinin zaman boyutunda çözümüne ilişkin bir problem çözümü oturumu yapılacağı belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
