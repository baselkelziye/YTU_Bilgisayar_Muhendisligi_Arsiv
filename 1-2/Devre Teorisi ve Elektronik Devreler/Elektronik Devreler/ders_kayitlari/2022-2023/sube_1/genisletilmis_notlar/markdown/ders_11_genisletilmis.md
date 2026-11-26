# Ders 11 Genişletilmiş Notu: BJT DC Kutuplama Devreleri ve Transistörün Anahtar Olarak Kullanılması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. BJT yapısı ve temel bağıntıların tekrarı
- 2. Çalışma bölgeleri ve çalışma noktası
- 3. Sabit kutuplama devresi
- 4. Yük hattı analizi ve devre değerlerinin Q-noktasına etkisi
- 5. Emetör kararlı kutuplama
- 6. Gerilim bölücü ve gerilim bölücü kutuplama
- 7. Kolektör geri beslemeli kutuplama
- 8. Transistörün anahtar olarak kullanılması
- 9. pnp transistörler
- Örnek Sorular
- Dersin Toparlaması

## 1. BJT yapısı ve temel bağıntıların tekrarı

Ders, bir önceki hafta başlanan transistör konusunun kısa bir tekrarıyla açılır. Diyotlarda p ve n tipi iki malzeme tek bir eklemle birleştiriliyordu. Transistörde ise iki eklem (çift jonksiyon) vardır. Yapıya göre iki tür transistör oluşturulabilir: pnp ve npn. Slaytta uçlar E (emitter, emetör), B (base, baz) ve C (collector, kolektör) olarak adlandırılır; pnp yapıda ortadaki ince bölge n tipi, npn yapıda p tipidir (ekrandan, 00:05:00).

### 1.1 Sembol ve akım yönleri

Sembolde baz, büyük düz çizginin bulunduğu taraftır. Hoca tipi ayırt etmek için tek bir kural verir: ok daima n tipi bölgeyi gösterir. Ok bazdan dışarı doğruysa baz p tipidir, kenarlar n tipidir; transistör npn'dir. Ok baza doğruysa ortadaki baz n tipidir; transistör pnp'dir. Ortadaki harf her zaman bazın tipidir.

Türkçe adlandırmada emetör "yayıcı", kolektör "toplayıcı", baz da "temel" diye geçer. npn transistörde akım kolektörden girer, emetörden çıkar; baz akımı da transistöre doğrudur. pnp'de bütün yönler terstir, iki tip birbirinin tam tersi mantıkla çalışır.

### 1.2 Temel akım bağıntıları

Transistör bir düğüm gibi düşünülürse her iki tipte de

$$I_E = I_C + I_B$$

yazılır. Emetör ve kolektör akımları miliamper ($10^{-3}$ A), baz akımı ise mikroamper ($10^{-6}$ A) mertebesindedir. Bu yüzden soru çözümlerinde baz akımı ihmal edilir ve

$$I_C \approx I_E$$

alınır. Silisyum transistörde baz-emetör gerilimi diyotta olduğu gibi yaklaşık $V_{BE} \approx 0{,}7$ V'tur.

Transistörün iki temel karakteristiği vardır:

$$\alpha = \frac{I_C}{I_E}, \qquad \beta = \frac{I_C}{I_B}$$

$\beta$ paydası mikroamper, payı miliamper mertebesinde bir oran olduğu için büyüktür; baz akımının kaç kat yükseltildiğini gösterir ve transistörün güçlendirme faktörü diye anılır.

Toprağa en yakın uca göre ortak bazlı (common base), ortak emetörlü ve ortak kolektörlü bağlantılar oluşur. Önceki hafta transistörün küçük giriş işaretlerini büyük işaretlere dönüştürmede (sinyal yükseltme) kullanıldığı bir örnek yapılmıştı.

## 2. Çalışma bölgeleri ve çalışma noktası

### 2.1 Üç çalışma bölgesi

Slaytta transistörün üç çalışma bölgesi şöyle verilir (ekrandan, 00:10:00):

- **Aktif (active):** yükselticinin çalışma aralığı. Transistör asıl bu bölgede çalıştırılmak istenir.
- **Kesim (cutoff):** yükseltici temelde kapalıdır; gerilim vardır ama akım çok azdır. Transistörden akım akmaz.
- **Doyum (saturation):** yükseltici tam açıktır; akım vardır ama gerilim çok azdır. En büyük akım akarken transistör üzerinde en küçük gerilim düşer.

### 2.2 Kutuplama (biasing)

Kutuplama, transistörü çalışır duruma getirmek için uygulanan DC gerilimdir. Transistör DC ile aktif bölgenin uygun bir yerine yerleştirilir ki üzerine binen AC işaretler doyuma gitmeden, düzgün dalga şekilleriyle işlenebilsin. Hoca bunu "DC şartlama" diye de anar: DC gerilim uygulanarak transistör istenen çalışma bölgesine getirilir.

### 2.3 Q-noktası

Slayttaki ifade: "The DC input establishes an operating or quiescent point called the Q-point." DC giriş, çalışma noktası (Q-noktası) denen bir nokta belirler (ekrandan, 00:15:00). Karakteristik grafikte yatay eksen $V_{CE}$ (V), düşey eksen $I_C$ (mA)'dır; eğriler $I_B = 0, 10, 20, \dots, 80\ \mu\text{A}$ değerlerine aittir. Grafikte A, B, C, D diye işaretli örnek çalışma noktaları, $I_{C\max}$ (25 mA civarı), $V_{CE\max}$ (20 V civarı) sınırları ve $P_{C\max}$ güç eğrisi gösterilir.

Grafik bölgelere ayrılır:

- Kesim: $I_B = 0$ eğrisinin altındaki bölge; $I_C$ minimumdur.
- Doyum: düşey eksene yakın, $V_{CE} \le V_{CE\,sat}$ bölgesi; $V_{CE}$ minimumdur.
- Güç sınırı: güç $P = V \cdot I$ olduğundan, $V_{CE} \cdot I_C$ çarpımının $P_{C\max}$'ı aştığı bölgede (grafikte mavi taralı alan) çalışılmaz.

Kesim, doyum ve güç sınırlarının dışında kalan kısım aktif (doğrusal) bölgedir.

## 3. Sabit kutuplama devresi

Derste incelenecek DC kutuplama devreleri sıralanır: sabit kutuplama, emetör kararlı kutuplama, gerilim bölücü kutuplama ve gerilim geri beslemeli kutuplama. <!-- BELİRSİZ: listede Whisper'ın "kolektör emetör döngüsü" diye yazdığı bir madde daha var; beşinci devre türü altyazıdan net değil -->

### 3.1 Devre yapısı

Sabit kutuplama (fixed bias) devresi slaytta şöyledir (ekrandan, 00:20:00):

| Eleman | Bağlantı |
|---|---|
| $V_{CC}$ | Üst besleme düğümü |
| $R_B$ | $V_{CC}$ ile baz (B) arasında; $I_B$ baza doğru akar |
| $R_C$ | $V_{CC}$ ile kolektör (C) arasında; $I_C$ aşağı doğru akar |
| Emetör (E) | Doğrudan toprağa bağlı |
| $C_1$ | AC giriş işareti ile baz arasında |
| $C_2$ | Kolektör ile AC çıkış işareti arasında |
| $V_{BE}$ | Baz (+) ile emetör (−) arasında |
| $V_{CE}$ | Kolektör (+) ile emetör (−) arasında |

Hoca öğrencilere transistörün tipini sorar: ok dışarı doğru olduğu için npn'dir. Derste çözümler hep npn üzerinden yapılır; pnp'de yönler tersine çevrilir. Ardından toprağa en yakın ucun hangisi olduğu sorulur: emetör toprağa en yakın uçtur, bu yüzden devre ortak emetörlü (common emitter) bir devredir (ekrandan, 00:25:00).

Hoca devreyi bir anahtar benzetmesiyle anlatır: $I_B$ olmadan $I_C$ ve $I_E$ oluşmaz. Baz akımı transistörü açıp kapayan bir akım gibi düşünülmelidir.

### 3.2 Kuplaj kondansatörleri

Girişte ve çıkışta birer kondansatör vardır. Ofsetlenmiş (sıfır ortalamalı olmayan) bir sinüs işareti iki bileşenden oluşur: işaretin ortalaması olan bir DC bileşen ve onun üzerine binen bir AC bileşen. Kondansatör DC bileşeni keser (blocks DC) ve yalnız AC bileşeni geçirir. Çıkıştaki $C_2$ de aynı amaçla, DC bileşeni süzüp yalnız sıfır ortalamalı salınım yapan işareti geçirmek için konmuştur. Bu işaret sinüs olabileceği gibi kare ya da üçgen dalga da olabilir (ekrandan, 00:25:00).

DC analizde bu kondansatörler hesaba katılmaz; hoca bir öğrencinin "$C_1$ ters bağlanmış" yorumuna da kapasitelere şimdilik yoğunlaşmamak gerektiğini, bunların yalnız girişteki ve çıkıştaki DC'yi kesen elemanlar olduğunu söyleyerek cevap verir.

### 3.3 Baz-emetör döngüsü

Devre transistörün ortasından ikiye ayrılarak incelenir: sol tarafta $I_B$'yi akıtan kısım (1), sağ tarafta $I_C$'yi akıtan kısım (2).

Hoca $V_{CC}$'nin aslında A noktası ile toprak arasına bağlı bir kaynak olduğunu hatırlatır. KVL'yi "toplam sıfır" biçiminde yazmak yerine şu yolu tercih eder: A noktasından toprağa giden paralel kolların gerilimleri birbirine eşittir. Sol kolda akım yönünde ilerlerken önce $R_B$ üzerindeki $I_B R_B$, sonra baz-emetör gerilimi $V_{BE}$ gelir:

$$V_{CC} = I_B R_B + V_{BE}$$

Buradan

$$I_B = \frac{V_{CC} - V_{BE}}{R_B}$$

bulunur. Bu, klasik $+V_{CC} - I_B R_B - V_{BE} = 0$ yazımıyla aynı denklemdir.

### 3.4 Kolektör-emetör döngüsü

Sağ kolda $V_{CC}$'den başlanıp önce $R_C$ üzerindeki gerilim, sonra kolektör-emetör gerilimi eklenir (ekrandan, 00:30:00):

$$I_C = \beta I_B, \qquad V_{CC} = I_C R_C + V_{CE}$$

$$V_{CE} = V_{CC} - I_C R_C$$

Soru çözümlerinde $\beta$ genellikle verilir; $I_B$ bulunduktan sonra $I_C$ ve $V_{CE}$ hesaplanır.

### 3.5 Doyum

Transistör doyuma geldiğinde kolektör-emetör gerilimi sıfıra yaklaşır, akım en büyük değerine çıkar. Kolektör-emetör arası kısa devre gibi davranır ve $R_C$ üzerinden en büyük akım akar.

## 4. Yük hattı analizi ve devre değerlerinin Q-noktasına etkisi

### 4.1 Yük hattı

Yük hattı (load line) analizinin amacı transistörün çalıştığı noktayı bulmaktır. $I_C$-$V_{CE}$ grafiğinde farklı $I_B$ değerleri için ($I_{B1}, I_{B2}, I_{B3}, \dots$) karakteristik eğriler vardır; yük hattı bu eğrileri keser.

Yük hattının iki ucu şöyle bulunur:

- **Doyum:** $V_{CE} = 0$ yapılır. $V_{CC} = I_C R_C + 0$ olduğundan $I_{C\,sat} = \dfrac{V_{CC}}{R_C}$. Bu, hattın $I_C$ eksenini kestiği noktadır.
- **Kesim:** $I_C = I_E = 0$ olur. Dirençlerde gerilim düşmez, bütün $V_{CC}$ kolektör-emetör arasına düşer: $V_{CE} = V_{CC}$. Bu, hattın $V_{CE}$ eksenini kestiği noktadır.

Bu iki nokta birleştirilince yük hattı elde edilir. Baz devresinden bulunan $I_B$'ye ait eğri ile yük hattının kesiştiği yer Q-noktasıdır; böylece aktif bölgede tam olarak nerede çalışıldığı belirlenir.

### 4.2 $V_{CC}$'nin etkisi

Slaytta üç farklı besleme için yük hatları çizilir: $V_{CC1} > V_{CC2} > V_{CC3}$. Her hattın uçları $V_{CCi}/R_C$ ve $V_{CCi}$'dir; hatlar birbirine paraleldir (ekrandan, 00:35:00). $V_{CC}$ büyüdükçe yük hattı yukarı ve sağa kayar. Sabit bir $I_{BQ}$ eğrisi üzerindeki Q-noktası da adım adım sağa doğru ilerler. Q-noktası kenardan çekilip ortalara getirilmek istenirse $V_{CC}$ artırılabilir.

**Soru:** $V_{CC}$ artınca $V_{CE}$ de artıyor; bu durumda grafikte $I_B$ nasıl sabit kalıyor? $I_B$'yi belirleyen nedir?
**Cevap:** $I_B$ sol taraftaki baz devresinden, $I_B = (V_{CC} - V_{BE})/R_B$ ile belirlenir. Burada yalnız $V_{CC}$'nin aktif bölgedeki etkisini görmek için $I_B$ sabit tutulmuş varsayılıyor. Hoca sorunun haklı olduğunu, gerçekte kaymanın tam doğrusal olmayacağını, biraz eğri bir yol izleyeceğini ve bunun ileride görüleceğini belirtir.

### 4.3 $R_C$'nin etkisi

İkinci grafikte $R_3 > R_2 > R_1$ olacak biçimde üç kolektör direnci için hatlar çizilir. Hepsi aynı $V_{CC}$ noktasından çıkar, $I_C$ eksenini $V_{CC}/R_1$, $V_{CC}/R_2$, $V_{CC}/R_3$ noktalarında keser (ekrandan, 00:40:00). Direnç küçükken $I_C$ ekseni üzerindeki kesişim yüksektir; direnç büyüdükçe kesişim aşağı iner, hat yatıklaşır. Sabit $I_B$ ve sabit $V_{CC}$ için Q-noktası aşağı (doyuma doğru) çekilir.

### 4.4 $I_B$'nin etkisi

$I_B$ değeri büyüdükçe Q-noktası daha üstteki karakteristik eğriye, aktif bölgenin daha üst noktalarına taşınır. Özetle sabit kutuplamalı transistörde Q-noktasını $I_B$, $R_C$ ve $V_{CC}$ belirler.

## 5. Emetör kararlı kutuplama

### 5.1 Devre ve fark

Hoca öğrencilere bu devrenin öncekinden farkını sorar. Fark, emetör ile toprak arasına bir $R_E$ direncinin eklenmesidir. Slayttaki ifadeye göre emetör devresine bir direnç eklemek kutuplamayı daha kararlı hale getirir (emitter-stabilized bias circuit). Hesaplarda artık $R_E$ üzerindeki gerilim de hesaba katılır.

### 5.2 Baz-emetör döngüsü

A noktasından ($V_{CC}$) başlayıp $R_B$, baz-emetör eklemi ve $R_E$ üzerinden toprağa gidilir (ekrandan, 00:45:00):

$$V_{CC} = I_B R_B + V_{BE} + I_E R_E$$

$\beta = I_C / I_B$ olduğundan $I_C = \beta I_B$ ve

$$I_E = I_C + I_B = \beta I_B + I_B = (\beta + 1) I_B$$

yazılır. Bu, döngü denkleminde $I_E$ yerine konunca

$$V_{CC} - I_B R_B - V_{BE} - (\beta + 1) I_B R_E = 0$$

$$I_B = \frac{V_{CC} - V_{BE}}{R_B + (\beta + 1) R_E}$$

elde edilir. Amaç $I_B$'yi bulmaktır; $I_B$ transistörü sürebilmek için belli bir değerin üstünde olmalıdır. $V_{BE}$ silisyum transistörde yine 0,7 V alınır; baz-emetör arası bir diyot varmış gibi hesaba katılır.

### 5.3 Kolektör-emetör döngüsü

Kolektör tarafında $V_{CC}$'den başlanıp $R_C$, kolektör-emetör ve $R_E$ üzerinden toprağa gidilir:

$$V_{CC} = I_C R_C + V_{CE} + I_E R_E$$

$I_E \approx I_C$ varsayımıyla

$$V_{CE} = V_{CC} - I_C (R_C + R_E)$$

olur. Yük hattı analizinde $V_{CE}$ ve $I_C$ grafikleri çizildiği için kolektör-emetör üzerindeki gerilim önemlidir.

### 5.4 Doyum ve kesim

Slayttaki "Saturation Level" çiziminde $V_{CE} = 0$ V iken akan $I_{C\,sat}$ gösterilir ve yük hattının uç noktaları verilir (ekrandan, 00:50:00):

| Durum | $V_{CE}$ | $I_C$ |
|---|---|---|
| Kesim ($V_{CE\,cutoff}$) | $V_{CE} = V_{CC}$ | $I_C = 0$ mA |
| Doyum ($I_{C\,sat}$) | $V_{CE} = 0$ V | $I_C = \dfrac{V_{CC}}{R_C + R_E}$ |

Kesimde transistörden akım akmaz; dirençlerde gerilim oluşmaz ve uygulanan gerilimin tamamı kolektör ile emetör arasına düşer.

## 6. Gerilim bölücü ve gerilim bölücü kutuplama

### 6.1 Gerilim bölücü

Hoca kutuplama devresine geçmeden önce gerilim bölücüyü ayrıca çıkarır (ekrandan, 00:55:00). A noktasına $V_{in}$ uygulanır; A ile B arasında $R_1$, B ile toprak arasında $R_2$ vardır; çıkış $V_{out}$ orta nokta B'den alınır. $R_1$'den geçen akım $i_1$, $R_2$'den geçen $i_2$ olsun. Çıkıştan akım çekilmediği için

$$i_1 = i_2 \;\Rightarrow\; \frac{V_{in} - V_{out}}{R_1} = \frac{V_{out}}{R_2}$$

İçler dışlar çarpımı yapılınca:

$$R_2 V_{in} - R_2 V_{out} = R_1 V_{out} \;\Rightarrow\; R_2 V_{in} = (R_1 + R_2) V_{out}$$

$$\frac{V_{out}}{V_{in}} = \frac{R_2}{R_1 + R_2}$$

Paydada dirençlerin toplamı, payda ise orta noktadan toprağa giden direnç $R_2$ vardır. Herhangi bir direnç üzerindeki gerilim, o direncin toplam dirence oranıyla $V_{in}$'in çarpımıdır; büyük dirençte daha çok gerilim düşer. $V_{R1} + V_{R2} = V_{in}$ olduğu da buradan görülür. Sayısal örnekler Örnek Sorular bölümündedir.

> **Ders sonrası not:** Tahtadaki ilk örnekte sonuç "$V_{out} = 5$k" diye yazıldı ve söylendi (ekrandan, 00:55:00). Birim yanlış; doğrusu $V_{out} = 5$ V'tur.

### 6.2 Gerilim bölücü kutuplama devresi

Slaytta devre şöyledir (ekrandan, 01:00:00 ve 01:05:00):

| Eleman | Bağlantı |
|---|---|
| $R_1$ | $V_{CC}$ ile baz düğümü arasında ($I_1$ aşağı) |
| $R_2$ | Baz düğümü ile toprak arasında ($I_2$ aşağı) |
| $R_C$ | $V_{CC}$ ile kolektör arasında |
| $R_E$ | Emetör ile toprak arasında ($I_E$ aşağı) |
| $C_1$ | Giriş $v_i$ ile baz düğümü arasında |
| $C_2$ | Kolektör ile çıkış $v_o$ arasında |

Slayttaki ifadeler: "This is a very stable bias circuit." ve "The currents and voltages are nearly independent of any variations in β."

$I_B$ çok küçük olduğundan baz ucuna giden akım ihmal edilir (hoca bunu tahtada baz bağlantısını keserek gösterir). Bu durumda $I_1 \approx I_2$ olur ve $R_1$-$R_2$ ikilisi bir gerilim bölücü gibi davranır:

$$V_B = \frac{R_2}{R_1 + R_2} V_{CC}$$

Emetör gerilimi ve baz-emetör gerilimi için:

$$V_E = I_E R_E, \qquad V_{BE} = V_B - V_E \;\Rightarrow\; V_E = V_B - V_{BE}$$

$V_{BE}$ 0,7 V sabit, $V_B$ de bölücüden bilindiği için $V_E$ ve oradan $I_E$ bulunur; benzer şekilde $I_1$ ve $I_2$ de hesaplanabilir. Kolektör tarafında:

$$V_{CC} = I_C R_C + V_{CE} + I_E R_E$$

Yük hattının uçları diğer devrelerdeki gibi bulunur: kesimde $V_{CE} = V_{CC}$, doyumda $V_{CE} = 0$ ve $I_C$ en büyük değerindedir.

> **Ders sonrası not:** Hoca bir yerde "kesimde $V_{CE}$'yi sıfıra eşitleyeceğiz" dedi, hemen ardından kesimde bütün gerilimin transistör üzerine düştüğünü söyleyerek düzeltti. Doğrusu: kesimde $V_{CE} = V_{CC}$, doyumda $V_{CE} = 0$.

## 7. Kolektör geri beslemeli kutuplama

### 7.1 Devre

Bu devre emetör kararlı yapıya çok benzer; fark, $R_B$'nin $V_{CC}$'den değil çıkış ucundan, yani kolektörden beslenmesidir (ekrandan, 01:10:00). $R_C$'den geçen akım $I'_C$ ile gösterilir. Kolektör düğümünde

$$I'_C = I_C + I_B \approx I_C$$

olur, çünkü $I_B \ll I_C$'dir. Temel varsayım budur.

### 7.2 Döngü denklemleri

Kolektör-emetör yolunda A noktasından ($V_{CC}$) başlanırsa (hocanın tahtaya yazdığı):

$$V_{CC} = I'_C R_C + V_{CE} + I_E R_E$$

Baz yolunda ise $R_C$, ardından $R_B$, baz-emetör eklemi ve $R_E$ üzerinden gidilir:

$$V_{CC} = I'_C R_C + I_B R_B + V_{BE} + I_E R_E$$

Slayttaki yazım: $V_{CC} - I'_C R_C - I_B R_B - V_{BE} - I_E R_E = 0$. $I'_C \approx I_C = \beta I_B$ ve $I_E \approx I_C$ konunca:

$$V_{CC} - \beta I_B R_C - I_B R_B - V_{BE} - \beta I_B R_E = 0$$

$$I_B = \frac{V_{CC} - V_{BE}}{R_B + \beta (R_C + R_E)}$$

$\beta$, $R_C$ ve $R_E$'nin ortak çarpanı olarak paydada kalır; $R_B$ ise tek başına paydadadır. Kolektör-emetör gerilimi ilk döngüden bulunur. Kesim ve doyum yine $V_{CE} = V_{CC}$ ve $V_{CE} = 0$ ile belirlenir.

## 8. Transistörün anahtar olarak kullanılması

### 8.1 Örnek devre

Slayttaki ifade: "Transistors with only the DC source applied can be used as electronic switches." Örnek devre (ekrandan, 01:15:00):

| Büyüklük | Değer |
|---|---|
| $V_{CC}$ | 5 V |
| $R_C$ | 0,82 kΩ |
| $R_B$ | 68 kΩ |
| $h_{FE}$ ($\beta$) | 125 |
| Giriş $V_i$ | 0 V ile 5 V arasında değişen kare dalga |
| Çıkış | Kolektör gerilimi $V_C$ |

### 8.2 Çalışma

Giriş 0 V iken baz akımı akmaz, dolayısıyla $I_C$ de akmaz; transistör çalışmıyordur (kesim). $R_C$ üzerindeki gerilim $V_{R_C} = I_C R_C = 0$ olur. $R_C$'nin üst ucuna A, alt ucuna C denirse $V_{R_C} = V_A - V_C$ olduğundan

$$0 = 5\ \text{V} - V_C \;\Rightarrow\; V_C = 5\ \text{V}$$

bulunur. Hoca bunu genel bir kuralla bağlar: bir direncin uçlarından akım akmıyorsa iki ucundaki gerilim birbirine eşittir.

Giriş 5 V olduğunda baz akımı akar, ardından kolektör akımı da akar ve transistör iletime girer. Transistör üzerinde çok düşük gerilim düştüğü için çıkış 0 V civarına iner. Böylece giriş 0 iken çıkış 1, giriş 1 iken çıkış 0 olur. Bu, tek transistörle yapılmış bir DEĞİL (NOT) kapısıdır; bu tür devrelere transistör anahtarlama devreleri denir. VE, VEYA gibi kapılar da transistörlerden kurulur.

**Soru:** Bu devrede iki giriş ($V_{CC}$ ve $V_{in}$) var; bu bir VE-DEĞİL (NAND) kapısı sayılabilir mi?
**Cevap:** Hayır. Daha karmaşık mantık kapıları tek transistörle değil, transistör topluluklarıyla yapılır ve bunlara anahtarlamalı ağlar denir. Burada yalnız tek transistörle basit bir DEĞİL kapısının yapılabildiği gösterilmiştir; transistörlerle mantık kapılarının kurulması bu dersin konusu değildir.

### 8.3 Anahtarlama süreleri

Geçişler çizimde dik gösterilse de gerçekte 0 V'tan 5 V'a geçiş belli bir eğimle olur. Slayttaki zaman tanımları hocanın anlatımına göre şöyledir:

- $t_d$ (delay, gecikme): giriş değiştikten sonra çıkışın yükselmeye başlamasına kadar geçen süre.
- $t_r$ (rise, yükselme): çıkışın son değerinin %10'undan %90'ına çıkma süresi.
- $t_s$ (storage, depolama): kapatma sırasında çıkışın hemen düşmeyip bir süre yüksek seviyede kalma süresi.
- $t_f$ (fall, düşme): çıkışın %90'dan %10'a inme süresi.

<!-- BELİRSİZ: anahtarlama süreleri slaytının karesi okunan kareler arasında yok; tanımlar altyazıdan kuruldu -->

Yüksek hızlı mantık devrelerinde ve mikroişlemcilerde bu sürelerin olabildiğince kısa olması, dalga şeklinin ideal kare dalgaya olabildiğince yaklaşması istenir. Geçişler ne kadar hızlıysa yüksek hızlı devreler o kadar kullanılabilir olur.

## 9. pnp transistörler

Bütün örnekler npn üzerinden verildi. Slayttaki ifade: pnp transistörlü kutuplama devrelerinin analizi npn ile aynıdır; tek fark akımların ters yönde akmasıdır (ekrandan, 01:20:00). npn'de $I_C$ kolektöre girer, $I_B$ baza girer, $I_E$ emetörden çıkar. pnp'de $I_B$ bazdan dışarı, $I_C$ kolektörden yukarı doğru çıkar, $I_E$ emetöre girer. Eşitlikler ve yaklaşıklıklar aynı kalır; çözümler yönlere dikkat edilerek yapılır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:20:00; derste sözlü, 00:18:46): Sabit kutuplama devresindeki transistör npn mi, pnp mi?

> **Cevap (derste verildi):** npn. Ok bazdan dışarı doğrudur; ok n tipini gösterdiği için kenarlar n, baz p tipidir.

**Soru 2** (derste sözlü, 00:20:31): Aynı devre ortak hangi uçlu bir devredir? (Toprağa en yakın uç hangisidir?)

> **Cevap (derste verildi):** Toprağa en yakın uç emetördür (E); devre ortak emetörlüdür (common emitter).

**Soru 3** (derste sözlü, 00:41:16): Emetör kararlı kutuplama devresinin sabit kutuplama devresinden farkı nedir?

> **Cevap (derste verildi):** Emetör ile toprak arasına bir $R_E$ direnci eklenmiştir. Bu direnç kutuplamayı daha kararlı yapar ve baz akımı $I_B = (V_{CC} - V_{BE})/(R_B + (\beta+1)R_E)$ olur.

**Soru 4** (ekrandan, 00:55:00): $V_{in} = 10$ V, $R_1 = 1\ \text{k}\Omega$, $R_2 = 1\ \text{k}\Omega$ olan gerilim bölücüde orta nokta gerilimi nedir? $R_2 = 3\ \text{k}\Omega$ yapılırsa ne olur?

> **Cevap (derste verildi):** $V_{out} = \dfrac{1}{1+1} \cdot 10 = 5$ V. $R_2 = 3$ kΩ için $V_{out} = \dfrac{3}{1+3} \cdot 10 = 7{,}5$ V; büyük direncin üzerine daha çok gerilim düşer, $R_1$ üzerinde 2,5 V kalır (python ile kontrol edildi).

**Soru 5** (derste sözlü, 00:55:16): Gerilim bölücüde $R_1 = 5$, $R_2 = 2$ birim ise dirençler üzerindeki gerilimler girişin ne kadarıdır?

> **Cevap (derste verildi):** Toplam 7 birimdir. $R_2$ üzerindeki gerilim $\frac{2}{7} V_{in}$, $R_1$ üzerindeki $\frac{5}{7} V_{in}$'dir. Hoca önce "2 bölü 5" dedi, ardından payda toplam direncin yazılması gerektiğini söyleyerek $\frac{2}{7}$ olarak düzeltti.

**Soru 6** (ekrandan, 01:00:00; derste sözlü, 00:56:56): Gerilim bölücü kutuplama devresinde $V_B$ noktasındaki gerilim nedir?

> **Cevap (derste verildi):** $I_B$ ihmal edilince $V_B = \dfrac{R_2}{R_1 + R_2} V_{CC}$. Payda $R_1$ değil, $V_B$ noktasından toprağa giden $R_2$ yer alır.

**Soru 7** (derste sözlü, 00:59:14): $V_{CC} = 10$ V iken iki direnç de 1 kΩ ise her birinin üzerinde kaç volt düşer? Üstteki 2 kΩ, alttaki 1 kΩ olursa? Üstteki 2 kΩ, alttaki 5 kΩ olursa $V_B$ nedir?

> **Cevap (derste verildi):** Eşit dirençlerde 5 V - 5 V. 2 kΩ - 1 kΩ durumunda 2 kΩ'luk direnç üzerine $\frac{2}{3} \cdot 10 \approx 6{,}67$ V, 1 kΩ üzerine $\approx 3{,}33$ V düşer. $R_1 = 2$ kΩ, $R_2 = 5$ kΩ için $V_B = \frac{5}{7} V_{CC}$ ($V_{CC} = 10$ V ise $\approx 7{,}14$ V) olur (python ile kontrol edildi).

**Soru 8** (ekrandan, 01:15:00; derste sözlü, 01:13:54): $V_{CC} = 5$ V, $R_C = 0{,}82$ kΩ, $R_B = 68$ kΩ, $h_{FE} = 125$ olan anahtarlama devresinde girişe 0 V / 5 V kare dalga uygulanıyor. Çıkış $V_C$ nasıl olur? Bu devre bir mantık elemanı olsaydı hangisi olurdu?

> **Cevap (derste verildi):** Giriş 0 V iken transistör kesimdedir, $R_C$'de gerilim düşmez ve $V_C = 5$ V olur. Giriş 5 V iken transistör iletir, $V_C \approx 0$ V olur. Çıkış girişin tersidir; devre bir DEĞİL (NOT) kapısıdır. (Öğrencilerden gelen "flip-flop" ve "mux" cevapları yanlıştır.)

## Dersin Toparlaması

Bu derste BJT'nin temel bağıntıları ($I_E = I_C + I_B$, $I_C \approx I_E$, $V_{BE} \approx 0{,}7$ V, $\beta = I_C/I_B$) hatırlatıldıktan sonra transistörün DC ile aktif bölgede bir Q-noktasına yerleştirilmesi, yani kutuplama ele alındı. Sabit kutuplama, emetör kararlı kutuplama, gerilim bölücü kutuplama ve kolektör geri beslemeli kutuplama devreleri aynı yöntemle çözüldü: devre transistörün ortasından ikiye ayrılır, baz-emetör döngüsünden $I_B$, kolektör-emetör döngüsünden $V_{CE}$ bulunur. Yük hattının uçları kesim ($V_{CE} = V_{CC}$) ve doyum ($V_{CE} = 0$) koşullarıyla belirlenir; $V_{CC}$, $R_C$ ve $I_B$'nin Q-noktasını nasıl kaydırdığı grafiklerle gösterildi.

Dersin sonunda transistörün yalnız DC ile kesim ve doyum arasında sürülerek bir anahtar, tek transistörle bir DEĞİL kapısı olarak kullanılabileceği görüldü ve gerçek anahtarlamadaki gecikme, yükselme, depolama ve düşme sürelerine değinildi. pnp transistörlerin analizinin aynı olduğu, yalnız akım yönlerinin ters olduğu belirtildi. Hoca sonraki derslerin diyot, zener diyot ve transistör devreleri üzerine soru çözümüyle geçeceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
