# Ders 16 Genişletilmiş Notu: İşlemsel Yükselteçler ve Temel Op-Amp Devreleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Konu sırası ve işlemsel yükselteçlerin kullanım amacı
- 2. Paketler ve bacak numaralandırma
- 3. Op-amp sembolü ve ideal op-amp
- 4. Gerilim kazancı ve evirme kavramı
- 5. Çözümlerin iki temel varsayımı
- 6. Evirmeyen yükselteç
- 7. Eviren yükselteç
- 8. Birim kazançlı tampon
- 9. Akımdan gerilime dönüştürücü
- 10. Fark yükselteci (çıkarıcı)
- 11. Eviren toplayıcı
- 12. İntegral alıcı ve türev alıcı
- Örnek Sorular
- Dersin Toparlaması

## 1. Konu sırası ve işlemsel yükselteçlerin kullanım amacı

Normal (bipolar) transistörlerden sonra sıradaki konu, transistörün değişik bir türü olan FET'ler, yani MOSFET tabanlı transistörlerdir. Bu derste araya işlemsel yükselteçler (operational amplifiers, kısaca op-amp) alınır ve hızlıca işlenir; FET'lere sonraki haftalarda dönülecektir. Hocanın ekrana çizdiği akışta da BJT'den FET'e giden yolun arasına OPAMP yerleştirilmiştir (ekrandan, 00:10:00). Ders, "Elektronik Devreler 4" slaytı üzerinden, slayta kalemle yazılarak anlatılır.

İşlemsel yükselteç, adından da anlaşılacağı gibi gerilim yükseltmede, yani giriş işaretini daha büyük bir işarete çevirmede kullanılır. Küçük genlikli bir dalga girişe verilir, çıkıştan büyütülmüş hâli alınır. Hocanın verdiği örnek, haberleşme devreleridir: alıcıya gelen çok küçük sinyaller işlenebilmek için önce devre içinde yükseltilir. Uydu yayıncılığında da uydudan gelen çok zayıf sinyaller yükseltilir, üzerinde temizleme işlemleri yapılarak kullanılır.

## 2. Paketler ve bacak numaralandırma

### 2.1 Paket türleri

Devrelerde iki tip paket yapısı vardır. Birincisi SMD (Surface Mounted Device), yani yüzeye montajlı elemanlardır. Bunlarda kartın yüzeyindeki boş adacıklara önce lehim (kurşun) dökülür, eleman ısıyla buraya yapıştırılır. İkincisi delikli kartlara bacakları geçirilip lehimlenerek kullanılan paketlerdir. Delikli paketler daha eski bir teknolojidir; yeni ürünlerde çoğunlukla yüzeye montajlı yapılar kullanılır. Yine de günlük kullanımda, hızlı devre ve prototip kurmada delikli paketler yaygındır.

### 2.2 Bacak numaralandırma

Paketin üzerinde bir nokta bulunur. Nokta referans alınarak bacaklar 1'den başlayıp saat yönünün tersine numaralandırılır: 8 bacaklı bir pakette bir sırada 1-2-3-4, karşı sırada 5-6-7-8 gelir. Nokta yerine paketin kenarında bir tık ya da çentik bulunabilir; numaralandırma bu işaret referans alınarak aynı biçimde yapılır.

### 2.3 Tekli, ikili ve dörtlü op-amp paketleri

Slaytta bir paketin çoğu zaman birden fazla op-amp içerdiği gösterilir (ekrandan, 00:15:00). Bacak bağlantıları şöyledir:

| Paket | Bacak 1 | Bacak 2 | Bacak 3 | Bacak 4 | Bacak 5-8 |
|---|---|---|---|---|---|
| (a) Tekli op-amp, 8 bacak | (boş) | Eviren giriş | Evirmeyen giriş | $V_{neg}$ | 5 boş, 6 çıkış, 7 $V_{pos}$, 8 boş |
| (b) İkili op-amp, 8 bacak | Çıkış | Eviren giriş | Evirmeyen giriş | $V_{neg}$ | 5-7 ikinci op-amp'in uçları, 8 $V_{pos}$ |

İkili pakette pozitif besleme tek bir bacaktan iki op-amp'e birlikte verilir; negatif besleme de ortaktır. 14 bacaklı bir paketin içine dört op-amp sığdırılabilir; slaytta 14 bacaklı paketin 1 çıkış, 2 eviren giriş, 3 evirmeyen giriş ve karşı tarafta 14 çıkış, 13 eviren giriş, 12 evirmeyen giriş biçiminde düzenlendiği görülür (ekrandan, 00:15:00). Paketin içinde hangi yapının bulunduğu üreticinin belgelerinden (spec) okunarak değerlendirilir.

> **Ek bilgi (derste anlatılmadı):** Tekli 741 tipi op-amp'lerde 1 ve 5 numaralı bacaklar büyük olasılıkla "offset null" (dengeleme) uçlarıdır, 8 numaralı bacak ise bağlantısızdır. Derste bu bacaklar yalnız "boş" diye anılmıştır.

## 3. Op-amp sembolü ve ideal op-amp

### 3.1 Sembol

Op-amp bir üçgenle gösterilir. İki girişi ve bir çıkışı vardır. Eksi ($-$) ile işaretli bacak eviren (inverting) giriş, artı ($+$) ile işaretli bacak evirmeyen (non-inverting) giriştir. "Evirmek" kavramı İngilizce *invert* kelimesinden gelir ve tersine çevirmek anlamındadır. Op-amp'in beslendiği bir pozitif ($V_{pos}$) ve bir negatif ($V_{neg}$) besleme ucu da vardır; bu uçlar bazı şekillerde ayrıca çizilir, bazılarında gösterilmez. Şekilde artı girişin yukarıda ya da aşağıda çizilmesi önemli değildir.

### 3.2 İdeal op-amp

Hesaplar ideal op-amp tanımından yola çıkılarak yapılır. İdeal op-amp şu üç özelliğe sahiptir:

- Gerilim kazancı sonsuzdur.
- Giriş direnci, yani iki giriş ucu arasında ölçülecek direnç, sonsuzdur.
- Çıkış direnci sıfırdır.

## 4. Gerilim kazancı ve evirme kavramı

Gerilim kazancı $A_v$, çıkış geriliminin giriş gerilimine oranıdır:

$$A_v = G = \frac{V_o}{V_i}$$

Kazanç, girişin ne kadar kuvvetlendirildiğinin ölçüsüdür; İngilizcede *gain* dendiği için $G$ ile de gösterilir. $A_v = 2$ ise 1 V'luk giriş 2 V'a çıkar. Girişe sinüs biçimli bir işaret verilirse tepe değeri 1 V olan sinüs çıkışta tepe değeri 2 V, tepe değeri 2 V olan sinüs 4 V olur. Bu, evirmeyen kazançtır.

Kazanç negatifse işaret evrilir. $A_v = -2$ iken 1 V'luk giriş $-2$ V, $-1$ V'luk giriş $(-1)(-2) = 2$ V olur. Pozitif değerler negatife, negatif değerler pozitife döner. $A_v = -1$ alınırsa 2 V'luk tepe $-2$ V'a, 1 V'luk değer $-1$ V'a gider. Sinüs işareti açısından bu, işaretin 180 derece (yani $\pi$ kadar) kaymasıdır. Kazançtaki eksi işareti, giriş ile çıkış arasındaki 180 derecelik faz farkını gösterir.

## 5. Çözümlerin iki temel varsayımı

Op-amp'li devrelerin hepsi aynı yöntemle çözülür. Giriş direnci sonsuz (ya da çok yüksek) olduğu için girişlerden op-amp'in içine akım girmiyormuş gibi kabul edilir. Bu yüzden iki giriş ucunun gerilimi birbirine eşit alınır. Örneğin $+$ uca $V_i$ uygulanmışsa $-$ uçta da $V_i$ bulunur.

$$V_- = V_+ \qquad\qquad I_- = I_+ = 0$$

> **Hocanın vurgusu:** Bütün çözümlerde bu iki eşitliğe dikkat edilir. $V_+$ birçok devrede toprağa bağlı olduğu için sıfırdır, ama her zaman toprağa bağlanmayabilir; o zaman $V_+$ ayrıca bulunur.

## 6. Evirmeyen yükselteç

### 6.1 Devre

Slayttaki devrede giriş $V_i$ op-amp'in $+$ ucuna verilir. Çıkış ile toprak arasında seri iki direnç vardır: üstte çıkışa bağlı $R_1$, altta toprağa bağlı $R_2$. $-$ uç bu iki direncin orta noktasına bağlıdır (ekrandan, 00:25:00 ve 00:30:00).

### 6.2 Gerilim bölücüden çözüm

$V_+ = V_i$ olduğu için $V_- = V_i$'dir. Hoca öğrencilere $-$ ucun bağlı olduğu yapının neyi hatırlattığını sorar; bir öğrenci "gerilim bölücü" diye cevap verir. $-$ uç, $V_o$'nun $R_1$-$R_2$ bölücüsünün orta noktası olduğundan:

$$V_i = \frac{R_2}{R_1 + R_2}\,V_o \quad\Rightarrow\quad G = \frac{V_o}{V_i} = \frac{R_1 + R_2}{R_2}$$

### 6.3 Akım eşitliğinden çözüm

Aynı sonuç uzun yoldan, akımların eşitliğinden de bulunur. $-$ uca akım girmediği için $R_1$'den geçen $i_1$ akımı ile $R_2$'den geçen $i_2$ akımı eşittir. Bir direncin üzerindeki akım, uçları arasındaki gerilim farkının dirence bölümüdür ($V = iR$, $i = V_R/R$). $R_1$'in uçlarında $V_o$ ve $V_i$, $R_2$'nin uçlarında $V_i$ ve toprak (0 V) vardır (ekrandan, 00:25:00):

$$i_1 = \frac{V_o - V_i}{R_1}, \qquad i_2 = \frac{V_i - 0}{R_2}$$

$i_1 = i_2$ yazılıp içler dışlar çarpımı yapılınca $V_o R_2 - V_i R_2 = V_i R_1$, yani $V_o R_2 = V_i (R_1 + R_2)$ olur. Buradan yine $V_o/V_i = (R_1 + R_2)/R_2$ elde edilir.

### 6.4 Kazancın yorumu

Dirençler daima pozitif olduğu için $G$ de daima pozitiftir ($+2$, $+3$, $+4$ gibi). Bu yüzden devre evirmeyen bir yükselteçtir; girişteki sinüs aynı fazda, büyütülmüş olarak çıkışa gelir. Kullanılan dirençlerin oranıyla gerilim kazancı ayarlanır. Örneğin iki direnç de 1 k$\Omega$ ise kazanç 2'dir.

> **Hocanın vurgusu:** Evirmeyen yükselteçte giriş işareti $+$ uçtan verilir, $-$ uç dirençlerin tam ortasına bağlanır. Çözümde yine $V_+ = V_-$ ve $I_- = I_+ = 0$ kullanılır.

## 7. Eviren yükselteç

### 7.1 Devre

Çok kullanılan ikinci yapı eviren yükselteçtir. Slaytta giriş $V_i$, $R_2$ direnci üzerinden $-$ uca verilir; $R_1$ çıkış ile $-$ uç arasındaki geri besleme direncidir; $+$ uç doğrudan topraktadır (ekrandan, 00:35:00). $+$ uç toprağa bağlı olduğundan $V_+ = 0$, dolayısıyla $V_- = 0$'dır. Amaç $V_o$ ile $V_i$ arasındaki ilişkiyi bulmaktır.

### 7.2 Çözüm

Hoca akımları kendi kabulüne göre, $R_2$'den $-$ uca doğru $i_2$ ve oradan $R_1$ üzerinden çıkışa doğru $i_1$ olarak alır. $-$ uca akım girmediği için $i_2 = i_1$'dir. Akım büyük gerilimli uçtan küçük gerilimli uca doğru kabul edilip gerilim farkları buna göre yazılır:

$$\frac{V_i - 0}{R_2} = \frac{0 - V_o}{R_1} \quad\Rightarrow\quad \frac{V_i}{R_2} = -\frac{V_o}{R_1} \quad\Rightarrow\quad A_v = \frac{V_o}{V_i} = -\frac{R_1}{R_2}$$

(ekrandan, 00:35:00)

> **Ders sonrası not:** Hoca çözüm sırasında kazancı önce $-R_2/R_1$ diye yazdı, hemen ardından düzeltti. Slayttaki adlandırmayla ($R_2$ giriş, $R_1$ geri besleme direnci) doğrusu $A_v = -R_1/R_2$'dir.

Slayttaki şekilde $I_1$ ters yönde (çıkıştan $-$ uca doğru) çizilmiştir. Bu yön kabul edilirse $I_2 = -I_1$ yazılır ve sonuç değişmez; yalnız gerilim farkları yöne göre ters sırayla yazılır.

### 7.3 Yorum

Dirençler pozitif olduğu için kazancın başındaki eksi hesaptan gelir ve giriş ile çıkış arasındaki 180 derecelik faz farkını gösterir: pozitif değerler negatife, negatif değerler pozitife gider. Örneğin geri besleme direnci 10 k$\Omega$, giriş direnci 1 k$\Omega$ ise kazanç $-10$ olur; çıkış girişin on katı büyüklüğünde ve ters işaretlidir.

## 8. Birim kazançlı tampon

Elektronik devrelerde çok sık görülen yapı, birim kazançlı tampon (buffer amplifier) devresidir. Giriş $+$ uca verilir, çıkış doğrudan $-$ uca bağlanır:

$$V_o = V_- = V_+ = V_i$$

Gerilim kazancı yoktur; giriş gerilimi aynen çıkışa aktarılır. Ancak op-amp'in girişinden akım akmadığı için giriş ve çıkış birbirinden yalıtılmış olur; yalnız gerilim aktarılır. Giriş direnci yüksek, çıkış direnci düşük olduğundan bu devre koruma amaçlı kullanılır. Örneğin işlemcilerin bacak çıkışlarında sık görülür ve bu bacak çıkışlarına da "buffer" denir.

## 9. Akımdan gerilime dönüştürücü

### 9.1 Devre ve çözüm

Bu devrede girişe gerilim değil, bir $I_i$ akımı verilir. Akım doğrudan $-$ uca gelir; çıkış ile $-$ uç arasında $R$ direnci vardır; $+$ uç topraktadır (ekrandan, 00:40:00). $V_+ = 0$ olduğu için $V_- = 0$'dır. $-$ uca akım girmediği için giriş akımı tamamen $R$ üzerinden geçer; şekildeki $I_R$ ters yönde çizildiği için $I_i = -I_R$ yazılır:

$$I_i = -\frac{V_o - 0}{R} \quad\Rightarrow\quad V_o = -I_i R$$

### 9.2 Kullanım

Elimizde yalnız bir voltmetre varsa ve bir uçtan geçen akım ölçülmek isteniyorsa bu devre kurulur. $R = 1\ \Omega$ alınırsa çıkış gerilimi sayıca giriş akımının eksi işaretlisi olur; ölçülen gerilim dalgası, akımın 180 derece faz farklı hâlidir. Ekranda $V_o$ belli bir biçimde görülüyorsa akımın bunun tam tersi olduğu anlaşılır. $R$ yerine 1 k$\Omega$ konursa, akımı bulmak için ölçülen gerilim bine bölünür. Çıkış gerilim, giriş değişkeni akım olduğu için devreye akımdan gerilime çevirici denir.

## 10. Fark yükselteci (çıkarıcı)

### 10.1 Devre

Slayttaki fark yükseltecinde (differential amplifier, subtractor) iki giriş vardır (ekrandan, 00:45:00):

- $V_2$, bir $R_2$ direnci üzerinden $-$ uca bağlıdır; çıkış ile $-$ uç arasında $R_1$ geri besleme direnci vardır.
- $V_1$, ikinci bir $R_2$ direnci üzerinden $+$ uca bağlıdır; $+$ uç ile toprak arasında ikinci bir $R_1$ direnci vardır.

### 10.2 $V_+$'nın bulunması

$+$ uca akım girmediği için $V_1$, $R_2$ ve $R_1$'den oluşan bir gerilim bölücüye uygulanmıştır:

$$V_+ = \frac{R_1}{R_1 + R_2}\,V_1$$

### 10.3 $V_-$'nin bulunması

$-$ uç için akım eşitliği yazılır. $V_2$'den $R_2$ üzerinden gelen akım, op-amp'e girmeden $R_1$ üzerinden çıkışa gider:

$$\frac{V_2 - V_-}{R_2} = \frac{V_- - V_o}{R_1}$$

İçler dışlar çarpımıyla $R_1 V_2 - R_1 V_- = R_2 V_- - R_2 V_o$, yani $V_-(R_1 + R_2) = R_1 V_2 + R_2 V_o$ olur (ekrandan, 00:45:00):

$$V_- = \frac{R_1 V_2 + R_2 V_o}{R_1 + R_2}$$

### 10.4 Sonuç

$V_+ = V_-$ yazılır, ortak payda $R_1 + R_2$ sadeleşir: $R_1 V_1 = R_1 V_2 + R_2 V_o$. Buradan:

$$V_o = (V_1 - V_2)\,\frac{R_1}{R_2}$$

(ekrandan, 00:45:00). Hoca çözüm sırasında bir an girişi $V_i$ diye yazar, sonra bunun $V_1$ olduğunu belirterek düzeltir.

Devrenin yaptığı iş, iki giriş gerilimi arasındaki farkı almaktır; bu yüzden fark yükselteci denir. Dirençlerin değeri burada bir sabit çarpan gibi düşünülebilir. $R_1$ iki kat seçilirse ($R_1 = 2R_2$) farkın iki katı alınır; iki direnç aynı seçilirse devre basit bir çıkarma yapar.

> **Hocanın vurgusu:** Hep aynı çözüm uygulanır: $V_- = V_+$ ve $I_- = I_+ = 0$. Burada bir koldan akım denklemi, orta koldan ($+$ uç) da gerilim bölücü ile ikinci denklem bulunmuştur.

## 11. Eviren toplayıcı

Eviren toplayıcı (inverting summing amplifier) giriş gerilimlerini toplar, ama toplam 180 derece faz farkıyla, yani eksi işaretli oluşur. O anki toplam negatifse çıkışta pozitif, pozitifse negatif görülür.

Çözümde yine $V_- = V_+ = 0$ alınır. $-$ uçtaki düğüme giren akımlar çıkan akıma eşittir; giriş akımları $I_1$ ve $I_2$, geri besleme akımı $I_3$ olmak üzere:

$$I_1 + I_2 = -I_3$$

Her giriş akımı, giriş geriliminin ilgili giriş direncine bölümü ($V_1 - 0$ bölü direnç), geri besleme akımı da $V_o - 0$ bölü geri besleme direnci olarak yazılır ve denklem çözülür. <!-- BELİRSİZ: Toplayıcı devresindeki direnç adları altyazıda karışık okunuyor ve ilgili an için kare yok; genel sonuç büyük olasılıkla V_o = -R_f (V_1/R_a + V_2/R_b) biçimindedir. -->

> **Hocanın vurgusu:** Devrenin hangi tip olduğu, adı önemli değildir; devre tiplerinin ezberlenmesi istenmez. Verilen devre $V_- = V_+$, $I_- = I_+ = 0$ ve düğüm akımları ile çözülebilmelidir.

## 12. İntegral alıcı ve türev alıcı

### 12.1 İntegral alıcı

İntegral alıcıda dirençlerin yerine artık kapasite de girer. Slayttaki devrede giriş $V_i$, $R$ direnci üzerinden $-$ uca gelir; çıkış ile $-$ uç arasında $C$ kondansatörü vardır; $+$ uç topraktadır (ekrandan, 00:50:00). Çıkış:

$$V_o = -\frac{1}{RC}\int_0^t V_i\,dt$$

Devre giriş gerilimini evirerek toplar, yani integralini alır. $R$ ve $C$ 1 kabul edilirse doğrudan eviren bir integral alıcı gibi düşünülebilir. Evirmenin 180 derecelik faz farkı demek olduğu bilindiğinde, burada asıl önemli olan temel işlevin integral olmasıdır. Hoca ekranda bir sinüs işareti ve ona göre kaymış ikinci bir dalgayı üst üste çizerek giriş ile çıkışın biçimini gösterir (ekrandan, 00:50:00).

> **Ek bilgi (derste anlatılmadı):** Girişe $V_i = V_m \sin\omega t$ verilirse integral alıcının çıkışı $\dfrac{V_m}{\omega RC}\cos\omega t$ (başlangıç koşulu ihmal edilerek) olur; yani çıkış girişe göre 90 derece kaymış bir dalgadır.

### 12.2 Türev alıcı

Kondansatör ile direncin yerleri değiştirilirse (girişte kondansatör, geri beslemede direnç) devre girişteki değişimi, yani girişin türevini çıkışa verir; çıkıştan girişin diferansiyeli okunur. <!-- BELİRSİZ: Türev alıcı slaytı için kare yok; formül derste sözlü verilmedi. -->

> **Ek bilgi (derste anlatılmadı):** İdeal türev alıcının çıkışı büyük olasılıkla $V_o = -RC\,\dfrac{dV_i}{dt}$ biçimindedir; eksi işareti yine eviren yapıdan gelir.

## Örnek Sorular

### Soru 1: 25 kazançlı evirmeyen yükselteç tasarımı (ekrandan, 00:30:00)

Kazancı 25 olan bir evirmeyen yükselteç tasarlayınız.

> **Çözüm (derste verildi):** Evirmeyen yükselteç için $G = \dfrac{V_o}{V_i} = \dfrac{R_1 + R_2}{R_2}$. $G = 25$ ise $\dfrac{R_1 + R_2}{R_2} = 25$, $R_1 + R_2 = 25R_2$, $R_1 = 24R_2$. Bu yüzden $R_2 = 1$ k$\Omega$ ve $R_1 = 24$ k$\Omega$ seçilir. Kontrol: $(24 + 1)/1 = 25$. Hoca ayrıca 10 mV'lik bir giriş için çıkışın $25 \times 10 = 250$ mV olacağını ve evrilmeyeceğini söyler (derste sözlü, 00:29:51).

### Soru 2: Direnç değerlerine göre evirmeyen kazanç (derste sözlü, 00:27:22)

Evirmeyen yükselteçte (a) $R_1 = R_2 = 1$ k$\Omega$, (b) $R_1 = 1$ k$\Omega$, $R_2 = 2$ k$\Omega$ ise gerilim kazancı nedir?

> **Çözüm (derste verildi):** (a) $G = (1 + 1)/1 = 2$. (b) $G = (1 + 2)/2 = 3/2$. Kazanç, direnç oranıyla ayarlanır ve her zaman pozitiftir.

## Dersin Toparlaması

Bu derste işlemsel yükselteçlere hızlı bir giriş yapıldı. Op-amp'in kullanım amacı, paket türleri ve bacak numaralandırması, sembolü ve ideal op-amp tanımı (sonsuz kazanç, sonsuz giriş direnci, sıfır çıkış direnci) verildi. Gerilim kazancı ve eksi kazancın 180 derecelik faz farkı anlamına geldiği açıklandı. Ardından bütün çözümlerin iki anahtarı olan $V_- = V_+$ ve $I_- = I_+ = 0$ varsayımlarıyla evirmeyen yükselteç ($G = (R_1 + R_2)/R_2$), eviren yükselteç ($A_v = -R_1/R_2$), tampon ($V_o = V_i$), akımdan gerilime dönüştürücü ($V_o = -I_i R$), fark yükselteci ($V_o = (V_1 - V_2)R_1/R_2$), eviren toplayıcı ve integral/türev alıcı devreleri çözüldü.

Hocanın asıl mesajı, devre tiplerini ezberlemek yerine her yeni devreyi aynı iki varsayım, Ohm yasası ve düğüm akımlarıyla çözebilmektir. Hesaplarda birimlere (miliamper, mikroamper) dikkat edilmesi de ayrıca vurgulandı. Sonraki haftalarda FET'lere geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
