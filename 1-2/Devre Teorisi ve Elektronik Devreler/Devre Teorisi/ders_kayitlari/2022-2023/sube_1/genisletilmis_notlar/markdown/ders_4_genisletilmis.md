# Ders 4 Genişletilmiş Notu: Y-Δ Tekrarı, Düğüm ve Çevre Analizi, Süper Düğüm ve Süper Çevre

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersten Kalanlar: Y-Δ Dönüşümü ve Köprü Devresi
- 2. Düğüm ve Çevre Kavramları, Yöntem Seçimi
- 3. Matematiksel Ön Bilgiler: Doğrusal Denklem Sistemleri
- 4. Düğüm (Nodal) Analizi
- 5. Düğüm Analizi Örneği: Akım Kaynaklı Devre
- 6. Süper Düğüme Kısa Giriş
- 7. Çevre (Mesh) Analizi
- 8. Çevre Analizi Örnekleri
- 9. İdeal Kaynaklar Üzerine Bir Soru
- 10. Süper Düğüm (Supernode)
- 11. Süper Çevre (Supermesh)
- 12. Düğüm ve Çevre Analizinin Karşılaştırılması
- 13. Ders Sonunda Sorulan Soru: Süper Düğüm Denklemi

## 1. Önceki Dersten Kalanlar: Y-Δ Dönüşümü ve Köprü Devresi

Ders, önceki haftadan kalan Y (yıldız) ve Δ (üçgen) ağlarının kısa bir tekrarıyla başladı. Bu üç uçlu düzenler güç sistemlerinde sık kullanılır (ekrandan, 00:05:00). Slayttaki çizimde Y ağında $R_1$ sol üst, $R_2$ sağ üst, $R_3$ alt koldadır. Δ ağında $R_c$ üstte (sol üst ve sağ üst uçlar arasında), $R_a$ solda (sol üst ve alt uç arasında), $R_b$ sağdadır (sağ üst ve alt uç arasında).

### 1.1 Eşdeğerlik koşulu

İki direnç ağının eşdeğer olması için şu sağlanmalıdır: herhangi iki uçtan, üçüncü uç boştayken, bakıldığında görülen direnç iki ağda da aynı olmalıdır. Üçüncü uç boşta olduğunda Y ağında o uca bağlı dirençten akım geçmez; bu direnç kopukmuş gibi düşünülür.

- Sol üst ve alt uçlardan bakılırsa: Y'de $R_2$ boştadır, $R_1 + R_3$ görülür. Δ'da $R_c$ ile $R_b$ seri olur ve bu toplam $R_a$'ya paraleldir: $R_1 + R_3 = R_a \parallel (R_b + R_c)$.
- Sağ üst ve alt uçlardan bakılırsa: $R_2 + R_3 = R_b \parallel (R_c + R_a)$.
- Üst iki uçtan bakılırsa: $R_1 + R_2 = R_c \parallel (R_a + R_b)$.

Üç denklem ve üç bilinmeyen vardır. Y dirençleri biliniyorsa Δ dirençleri, Δ dirençleri biliniyorsa Y dirençleri bulunur. Bu denklemlerin çözümü slaytta verilmiştir (ekrandan, 00:10:00):

| Δ'dan Y'ye | Y'den Δ'ya |
|---|---|
| $R_1 = \dfrac{R_bR_c}{R_a+R_b+R_c}$ | $R_a = \dfrac{R_1R_2+R_2R_3+R_3R_1}{R_1}$ |
| $R_2 = \dfrac{R_aR_c}{R_a+R_b+R_c}$ | $R_b = \dfrac{R_1R_2+R_2R_3+R_3R_1}{R_2}$ |
| $R_3 = \dfrac{R_aR_b}{R_a+R_b+R_c}$ | $R_c = \dfrac{R_1R_2+R_2R_3+R_3R_1}{R_3}$ |

Bütün dirençler eşitse: $R_1 = R_2 = R_3 = R$ için $R_a = R_b = R_c = 3R$; $R_a = R_b = R_c = R'$ için $R_1 = R_2 = R_3 = R'/3$.

> **Ders sonrası not:** Yukarıdaki üç eşdeğerlik denklemi, eşdeğerlik çizimindeki etiketlemeyle çözülünce (python ile sayısal olarak kontrol edildi) $R_1 = R_aR_c/\Sigma$ ve $R_2 = R_bR_c/\Sigma$ çıkar. Formül slaytında $R_1$ ile $R_2$'nin payları yer değiştirmiş görünür. Formül slaytı büyük olasılıkla $R_a$'nın $R_1$ ucunun karşısında olduğu başka bir etiketlemeye göre hazırlanmıştır. Etiketlemeden bağımsız kural şudur: bir Y direnci, kendi ucuna bitişik iki Δ direncinin çarpımı bölü üç Δ direncinin toplamıdır.

### 1.2 Köprü devresi

Köprü devresi hassas ölçüm için kullanılır. Devrenin iki ucuna bir besleme bağlanır. Köprüdeki dirençler, ölçülmek istenen büyüklük dışındaki ortam koşullarından (sıcaklık, ışık, nem) aynı ölçüde etkilenir. Ortam sıcaklığı değişince hepsinin direnci aynı miktarda değişir. Bu ortak etkiler birbirini götürür.

Ölçülmek istenen büyüklük (örneğin bir ağırlık ya da ışık şiddeti) bir koldaki dirence $\Delta R$ kadar bir değişim ekler: o kol $R + \Delta R$ olur. Besleme gerilimi sabitken köprünün orta uçları arasındaki gerilim ($V_{CD}$) bu etki yokken ve varken ölçülür. Aradaki fark doğrudan ölçülen büyüklükle ilişkilidir. Bu yüzden hassas bir tartı yapılacaksa köprü mantığını kullanmak anlamlıdır. Köprü devresi ayrıca iki Y, ortak direnci sonsuz (kopuk) olan iki Δ ya da bir Δ ile bir Y olarak düşünülerek çözülebilir.

## 2. Düğüm ve Çevre Kavramları, Yöntem Seçimi

Şimdiye kadar görülen konular basit devreleri çözmek için ipuçları veriyordu. Bu dersten itibaren daha karmaşık devreleri çözmeye yarayan iki yöntem görülür: düğüm analizi ve çevre analizi.

### 2.1 Düğüm ve çevre

Hoca yazı tahtasında bir kaynak, üstte seri bir direnç, ortada dikey bir direnç, sağda bir direnç ve alt kolda dirençler bulunan iki gözlü bir devre çizdi (ekrandan, 00:15:00 ve 00:20:00).

- **Düğüm (node):** birden fazla elemanın ortak birleştiği nokta. Hoca bu devrede düğümleri işaretleyip altı düğüm saydı. Düğümlerden biri referans seçilir ve ona 0 V verilir. Referans genellikle kaynaklardan birinin eksi ucudur.
- **Çevre (mesh, çevrim):** bir noktadan başlayıp elemanlar üzerinden geçerek aynı noktaya dönen kapalı yol. Bu devrede sol göz, sağ göz ve devrenin dış çevresi olmak üzere üç çevrim yazılabilir.

**Soru:** (Hoca sordu) Üçüncü çevrim için ne dersiniz? **Cevap:** (Bir öğrenci) Devreyi tamamen dolaşabiliriz. Hoca bunu doğruladı.

Üç çevrimden yazılan denklemlerin yalnız ikisi doğrusal bağımsızdır; üçüncüsü diğer ikisinin bir birleşimi olarak yazılabilir. Bu devrede çevre analiziyle iki bilinmeyen çevre akımı aranır. Düğüm analiziyle ise referans dışındaki düğüm gerilimleri bilinmeyendir; bu durumda daha fazla denklem gerekir ve bu denklemler Kirchhoff'un akımlar kanunuyla yazılır.

### 2.2 Hangi yöntem?

Hoca sağ tarafa dört elemanın paralel bağlandığı bir devre çizdi (ekrandan, 00:20:00). Bu devrede dört bağımsız çevre vardır; çevre analiziyle en az dört denklem gerekir. Oysa üstteki bütün noktalar tek bir düğüm, alttaki noktalar ikinci bir düğümdür. Biri referans seçilince tek bilinmeyen ve tek denklem kalır. Bu devrede düğüm analizi seçilmelidir.

Karşılaşılan devrenin topolojisine bakarak hangi yöntemin daha az denklem gerektirdiğine karar verilir. Ayrıca iki yöntemin de özel durumları vardır: bir çevrenin içinde akım kaynağı varsa ya da düğüm analizinde bir gerilim kaynağı referansa bağlı değilse "her çevre için bir denklem" ya da "her düğüm için bir denklem" kuralı doğrudan işlemez. Bu durumlar dersin sonunda süper düğüm ve süper çevre olarak ele alındı.

## 3. Matematiksel Ön Bilgiler: Doğrusal Denklem Sistemleri

Bu yöntemler tek denklem yerine bir denklem sistemi verir. Bir denklem sisteminin ya tek çözümü vardır, ya hiç çözümü yoktur ya da sonsuz çözümü vardır.

- **Sonsuz çözüm:** kısıtlayıcı yeterli sayıda bağımsız denklem yoktur. Devre analizinde bu durumla karşılaşılmaz.
- **Çözüm yok:** kısıtlar birbiriyle çelişir ya da bilinmeyen sayısından fazla bağımsız denklem vardır.
- **Tek çözüm:** bağımsız denklem sayısı bilinmeyen sayısına eşittir ve sistemin determinantı sıfırdan farklıdır.

### 3.1 İki bilinmeyenli sistem

Örnek sistem: $a_1x + b_1y = c_1$, $a_2x + b_2y = c_2$. Burada $a$ ve $b$ katsayıları bilinir, $c$ değerleri bilinir; $x$ ve $y$ aranır. İki gözlü bir devrede çevre analizi yapıldığında $c_1$ ve $c_2$ kaynak değerlerine, $a$ ve $b$ katsayıları direnç değerlerine, $x$ ve $y$ ise çevre akımlarına (ya da düğüm analizinde düğüm gerilimlerine) karşılık gelir.

İki denklemde yerine koyma pratiktir: birinci denklemden $x$ çekilir, ikinci denkleme konur, $y$ bulunur, sonra $x$ hesaplanır. Daha büyük sistemlerde bu yol anlamlı değildir; sistem matris biçimine getirilir (ekrandan, 00:30:00):

$$\begin{bmatrix} a_1 & b_1 \\ a_2 & b_2 \end{bmatrix} \begin{bmatrix} x \\ y \end{bmatrix} = \begin{bmatrix} c_1 \\ c_2 \end{bmatrix}$$

Matris-vektör çarpımında birinci satır sütunla çarpılır ve eşitliğin sağındaki birinci satırı verir: $a_1x + b_1y = c_1$. İkinci satır da $a_2x + b_2y = c_2$'yi verir. Asıl önemli iş, bilinmeyenlerin katsayı matrisini doğru yazabilmektir.

### 3.2 Determinant ile çözüm (Cramer kuralı)

Toplu gösterimle $A\mathbf{x} = \mathbf{c}$ yazılır. Determinantlar (ekrandan, 00:30:00):

- $D = \begin{vmatrix} a_1 & b_1 \\ a_2 & b_2 \end{vmatrix} = a_1b_2 - a_2b_1$
- $D_x = \begin{vmatrix} c_1 & b_1 \\ c_2 & b_2 \end{vmatrix} = c_1b_2 - c_2b_1$ ($x$'in katsayıları yerine sağ taraf konur)
- $D_y = \begin{vmatrix} a_1 & c_1 \\ a_2 & c_2 \end{vmatrix} = a_1c_2 - a_2c_1$ ($y$'nin katsayıları yerine sağ taraf konur)

Çözüm $x = D_x/D$, $y = D_y/D$'dir. Hoca bu formüllerin vektörel çarpım formülünü andırdığını söyledi.

Üç bilinmeyende ($x$, $y$, $z$) aynı mantık genişletilir. $A$ matrisinin birinci sütunu yerine sağ taraf vektörü konunca $D_x$, ikinci sütunu yerine konunca $D_y$, üçüncüsü yerine konunca $D_z$ elde edilir; $x = D_x/D$, $y = D_y/D$, $z = D_z/D$.

3×3 determinant pratik olarak Sarrus kuralıyla bulunur: birinci ve ikinci sütun matrisin sağına tekrar yazılır, soldan sağa inen üç köşegenin çarpımları toplanır, ters yöndeki üç köşegenin çarpımları çıkarılır.

### 3.3 Hazır araçlar

Bu işlemler matematiksel programlama araçlarıyla yapılabilir. Okulun MATLAB lisansı vardır; açık kaynaklı Octave aynı işi yapar. Derste denklemler Octave'da çözüldü.

> **Ek bilgi (derste anlatılmadı):** Octave ve MATLAB'da `A\c` yazımı da $A\mathbf{x}=\mathbf{c}$ sistemini çözer ve sayısal olarak `inv(A)*c`'den daha kararlıdır. Küçük devre sistemlerinde iki yazım aynı sonucu verir.

## 4. Düğüm (Nodal) Analizi

Düğüm analizi, Ohm yasasını ve düğümler arasındaki potansiyel farklarını kullanarak akımları bulma tekniğidir (ekrandan, 00:35:00). İlk sonuç düğüm gerilimleridir; bunlar düğümlerin referansa (toprağa) göre gerilimleridir ve dirençlerin uçlarındaki gerilimlerle aynı şey değildir. İkinci sonuç akımların hesabıdır.

Her dalın akımı, dalın iki ucundaki düğüm gerilimlerinin farkı bölü daldaki dirençtir. Bu Ohm yasası, Kirchhoff'un akımlar kanunuyla (bir düğüme giren ve çıkan akımların toplamı sıfır) birleşince devrenin bütün doğrusal bağımsız denklemleri yazılabilir.

### 4.1 Adımlar

Hoca yöntemi slayttaki devre üzerinden adım adım anlattı (ekrandan, 00:40:00). Devre:

| Dal | Eleman | Düğümler | Akım (yön) |
|---|---|---|---|
| Kaynak kolu | $V_{in}$ (artı ucu $V_1$'de, eksi ucu toprakta) | toprak → $V_1$ | $I_7$ (yukarı) |
| Sol kol | $R_1$ | $V_1$ → $V_2$ | $I_1$ (yukarı) |
| Üst sol | $R_2$ | $V_2$ → $V_3$ | $I_2$ (sağa) |
| Orta dikey | $R_3$ | $V_3$ → $V_5$ | $I_3$ (aşağı) |
| Üst sağ | $R_4$ | $V_3$ → $V_4$ | $I_4$ (sağa) |
| Sağ dikey | $R_5$ | $V_4$ → $V_5$ | $I_5$ (aşağı) |
| Alt kol | $R_6$ | $V_5$ → toprak | $I_6$ (aşağı) |

1. **Referans düğümü seç.** Kaynağın eksi ucu referans seçilirse kaynak gerilimi doğrudan bir düğüm gerilimine eşit olur ve toplama-çıkarma işlemlerinden kurtulunur. Burada $V_1 = V_{in}$ olur.
2. **Düğümleri etiketle.** İki ya da daha fazla elemanın ortak noktalarına $V_1 \ldots V_5$ etiketleri verilir.
3. **Akımların referans yönlerini ve etiketlerini ver.** Yönler keyfî seçilir. Ama bir kez sabitlenince sonuç ne çıkarsa (artı ya da eksi) o akıma atanır. Negatif çıktı diye akım ters çevrilip denklemler yeniden yazılmaz; bütün denklemler zaten seçilen yöne göre kurulmuştur.
4. **KCL denklemlerini yaz** (ekrandan, 00:40:00): $I_7 = I_1 = I_2 = I_6$ (ana kol), $I_2 = I_3 + I_4$, $I_4 = I_5$ ve $I_3 + I_5 = I_6$.
5. **Akımları düğüm gerilimleriyle yaz.** Örneğin $I_1 = (V_1 - V_2)/R_1$.
6. **Sistemi düğüm gerilimleri için çöz.**
7. **Dal akımlarını Ohm yasasıyla bul.**

> **Hocanın vurgusu:** Akım hangi potansiyelden hangisine akıyorsa "başlangıç potansiyeli eksi varış potansiyeli, bölü direnç" yazılır. Varış eksi başlangıç değil; buna dikkat edin.

### 4.2 Sayısal devre (Örnek 1)

Aynı devrede değerler: $V_{in} = 10$ V, $R_1 = 9$ kΩ, $R_2 = 2$ kΩ, $R_3 = 5$ kΩ, $R_4 = 3$ kΩ, $R_5 = 1$ kΩ, $R_6 = 7$ kΩ (ekrandan, 00:45:00). Hoca yazı tahtasında şu denklemleri kurdu (ekrandan, 00:50:00):

- $V_1 = 10$ V (kaynak).
- Ana kol akımı tek harfle $I$ gösterilir: $I = \dfrac{V_1 - V_2}{9000} = \dfrac{V_2 - V_3}{2000} = \dfrac{V_5}{7000}$.
- $I_4$ ve $I_5$ aynı kolda olduğu için ikisine de $I_4$ denir. $V_5$ düğümü için yazılan denklem $V_3$ düğümü için yazılanla doğrusal bağımlıdır; aynı etiketi kullanmak bir denklemden kurtarır.
- $V_3$ düğümü: $I = I_3 + I_4$.
- $I_3 = \dfrac{V_3 - V_5}{5000}$.
- $I_4 = \dfrac{V_3 - V_4}{3000}$. İstenirse $V_4$ hiç kullanılmaz: $V_3$'ten $V_5$'e seri 3 kΩ ve 1 kΩ üzerinden akan akım olarak $I_4 = \dfrac{V_3 - V_5}{4000}$ yazılır.

Bu indirgemelerle bilinmeyenler $V_2$, $V_3$, $V_5$ (ve $V_1$) kalır ve denklem sayısı bilinmeyen sayısına eşit olur. Hoca aynı devreyi hiç indirgeme yapmadan da yazdı: $V_1 = 10$, $\frac{V_1-V_2}{9000} = I_1$, $\frac{V_2-V_3}{2000} = I_2$, $I_2 = I_3 + I_4$, $\frac{V_3-V_5}{5000} = I_3$, $\frac{V_3-V_4}{3000} = I_4$, $\frac{V_4-V_5}{1000} = I_5$, $I_3 + I_5 = I_6$ ve $I_1 = I_7 = I_2 = I_6$, $I_4 = I_5$. Beş gerilim ve yedi akım için on iki bilinmeyen vardır, ama yazılan denklem sayısı bunu aşabilir. Bu durumda yalnız doğrusal bağımsız denklemler kullanılır. Pratik olan, seri elemanlara ve aynı kola tek bir akım etiketi vermektir; iki yol da aynı sonuca götürür.

Düğüm gerilimleri bulunduktan sonra akımlar hesaplanır; örneğin $V_1 - V_2 = 4.45$ V olduğundan $I_1 = 4.45/9\text{k} \approx 0.495$ mA. Direnç gerilimleri (ekrandan, 00:55:00):

| Direnç | Gerilim ifadesi | Değer (V) |
|---|---|---|
| $R_1$ | $V_1 - V_2$ | 4.45 |
| $R_2$ | $V_2 - V_3$ | 0.990 |
| $R_3$ | $V_3 - V_5$ | 1.10 |
| $R_4$ | $V_3 - V_4$ | 0.824 |
| $R_5$ | $V_4 - V_5$ | 0.274 |
| $R_6$ | $V_5 - 0$ | 3.46 |

Python ile çözülen sistem $V_2 = 5.549$ V, $V_3 = 4.560$ V, $V_4 = 3.736$ V, $V_5 = 3.462$ V verir; tablodaki farklar bununla uyumludur. Slayttaki sağlama: bir direnç üzerindeki gerilimin büyüklüğü devredeki bütün gerilim kaynaklarının toplamından küçük olmalıdır; burada hiçbir direnç gerilimi 10 V'u aşamaz.

### 4.3 Yöntemin özeti

Düğüm analizinde bilinmeyenler yalnız düğüm gerilimleri bırakılır. Bir düğüm gerilimi, o düğümün referansa göre potansiyel farkıdır. İki düğüm arasındaki elemandan geçen akım bu iki düğümün potansiyel farkıyla doğru orantılıdır (Ohm yasası). Bütün düğüm denklemleri düğüm gerilimleri cinsinden yazılır, sistem çözülür, sonra her koldaki akım potansiyel farkı bölü direnç olarak bulunur.

## 5. Düğüm Analizi Örneği: Akım Kaynaklı Devre

Aradan sonra hoca yazı tahtasında şu devreyi çözdü (ekrandan, 01:10:00):

| Kol (soldan sağa) | Eleman | Bağlantı |
|---|---|---|
| 1 | 2 A akım kaynağı (yukarı) | toprak → $v_1$ |
| 2 | 7 Ω ve 3 Ω seri (aradaki düğüm $v_3$) | $v_1$ → toprak, akım $I_1$ (aşağı) |
| Üst | 15 Ω | $v_1$ → $v_2$, akım $I_2$ (sağa) |
| 3 | 5 Ω | $v_2$ → toprak, akım $I_3$ (aşağı) |
| 4 | 4 A akım kaynağı (yukarı) | toprak → $v_2$ |

Referans alt düğümdür. Akım kaynaklarının kollarına ayrı akım etiketi verilmez; o kolların akımını kaynaklar belirler.

KCL denklemleri:

- $v_1$ düğümü: 2 A girer, $I_1$ ve $I_2$ çıkar: $2 = I_1 + I_2$.
- $v_2$ düğümü: 4 A ve $I_2$ girer, $I_3$ çıkar: $4 + I_2 = I_3$.

Akımlar düğüm gerilimleriyle: $I_3 = \dfrac{v_2 - 0}{5}$, $I_2 = \dfrac{v_1 - v_2}{15}$. $I_1$ için klasik yazım $I_1 = \dfrac{v_1 - v_3}{7}$ olurdu; ama bu $v_3$'ü denkleme sokar ve $I_4 = v_3/3$, $I_1 = I_4$ gibi ek denklemler gerekir (dört bilinmeyen, dört denklem). Bunun yerine $I_1$, $v_1$'in referansa göre farkı bölü koldaki toplam direnç olarak yazılır: $I_1 = \dfrac{v_1 - 0}{10}$. Böylece $v_3$ yok edilir ve iki denklem yeter.

Yerine koyma:

$$2 = \frac{v_1}{10} + \frac{v_1 - v_2}{15}, \qquad 4 + \frac{v_1 - v_2}{15} = \frac{v_2}{5}$$

Birinci denklem 30 ile çarpılır: $60 = 3v_1 + 2v_1 - 2v_2$, yani $5v_1 - 2v_2 = 60$. İkinci denklem 15 ile çarpılır: $60 + v_1 - v_2 = 3v_2$, yani $v_1 - 4v_2 = -60$.

**Soru:** (Bir öğrenci, düzenleme sırasında) İkinci denklemde $v_1 - v_2$ karşıya geçince $3v_2$ olmuyor mu? **Cevap:** Hoca 15 ile genişlettiğini doğruladı ve denklemi düzeltti.

Matris biçimi:

$$\begin{bmatrix} 5 & -2 \\ 1 & -4 \end{bmatrix} \begin{bmatrix} v_1 \\ v_2 \end{bmatrix} = \begin{bmatrix} 60 \\ -60 \end{bmatrix}$$

Hoca Octave'da `A=[5 -2 ; 1 -4]`, `c=[60;60]` yazıp `inv(A)*c` ile önce $6.6667$ ve $-13.3333$ buldu (ekrandan, 01:20:00). Değerler küsuratlı çıkınca bir denklemde hata olduğundan şüphelenildi. Bir öğrenci, alttaki denklemde 60'ın karşıya geçerken eksi olması gerektiğini söyledi. `c=[60;-60]` ile çözüm $v_1 = 20$ V, $v_2 = 20$ V oldu.

$$A\mathbf{x} = \mathbf{c} \;\Rightarrow\; \mathbf{x} = A^{-1}\mathbf{c}$$

Sonuç 2×1'lik bir vektördür: ilk değer $v_1$, ikinci değer $v_2$. Akımlar: $I_1 = 20/10 = 2$ A, $I_3 = 20/5 = 4$ A ve $I_2 = (20 - 20)/15 = 0$. 15 Ω'luk dirençten akım geçmez; ilginç bir özel durumdur. Sağlama: $v_1$'de $2 = 2 + 0$, $v_2$'de $4 + 0 = 4$.

**Soru:** 15 Ω'luk dirençte kısa devre mi olmuş oluyor? **Cevap:** Hoca önce "kısa devre olmuyor, sanki açık devre gibi" dedi, sonra iki ucun gerilimleri eşit olduğu için "kısa devre diyebiliriz" diye düzeltti: bir elemanın uçlarındaki gerilimler eşitse yerine tel konmuş gibi etki eder; $v_1$ ve $v_2$ aynı gerilimde olduğu için bir telle değiştirilmiş gibi düşünülebilir.

> **Ders sonrası not:** Gerilimi de akımı da sıfır olan bir eleman, devrenin geri kalanını değiştirmeden hem açık devreyle hem kısa devreyle değiştirilebilir. Bu örnekte iki benzetme de doğrudur.

Çözüm, değerleri yerine koyarak, determinantla elle ya da matematik araçlarıyla yapılabilir.

> **Hocanın vurgusu:** Ödev ve laboratuvar sorularında işlemlerin doğruluğunu test etmek için bu tür araçları kullanmanız faydanıza olacaktır.

## 6. Süper Düğüme Kısa Giriş

Hoca çevre analizine geçmeden önce süper düğümden kısaca söz etti. Düğüm analizinde referans bir kaynağın eksi ucunda seçilir. Bir gerilim kaynağının hiçbir ucu referansa bağlı değilse özel bir durum oluşur. Gerilim kaynağı uçları arasındaki gerilim farkını belirler, ama üzerinden geçen akımı belirleyemez; bu akımı aynı koldaki başka bir eleman belirler. Standart yöntem uygulanırsa doğrusal bağımlı, gereksiz bir denklem yazılır. Bu yüzden kaynağın bir ucundaki düğüm gerilimi elimine edilir. Ayrıntısı Bölüm 10'dadır.

## 7. Çevre (Mesh) Analizi

Çevre, başlanan noktadan gerekli elemanlar dolaşılıp yine başlangıç noktasına dönülen kapalı yoldur. Bir çevrim boyunca bütün elemanlardaki gerilimlerin toplamı Kirchhoff'un gerilimler kanununa göre sıfırdır. Bu özellik ve Ohm yasası kullanılarak devrenin denklem sistemi kurulur. Temel yaklaşım, devrede doğrudan görülen basit gözleri (çevreleri) kullanmaktır. Bir akım kaynağı birden fazla çevre tarafından paylaşılıyorsa doğrusal bağımlı iki denklem çıkar; bu durum Bölüm 11'de ele alındı.

### 7.1 Çevre akımları

Düğüm analizinde bir kolun akımı düğüm gerilimleriyle yazılıyordu. Çevre analizinde ise her çevrede dolaşan sanal bir çevre akımı varsayılır. Bir elemanın gerçek akımı, o elemandan geçen çevre akımlarının cebirsel (net) toplamıdır.

Slayttaki iki gözlü devrede (ekrandan, 01:35:00): 12 V kaynak (artı ucu üstte), sol kolda 4 kΩ ($V_1$), üst solda 8 kΩ ($V_2$), iki gözün ortak dikey kolunda 5 kΩ ($V_3$), sağ gözde üstte 6 kΩ ($V_4$) ve sağ dikey kolda 3 kΩ ($V_5$), sağ gözün altından toprağa dönen kolda 1 kΩ ($V_6$) bulunur. Birinci göz akımı $i_1$, ikinci göz akımı $i_2$'dir; ikisi de saat yönündedir.

| Eleman | Gerilim | Bulunduğu göz(ler) |
|---|---|---|
| 4 kΩ | $V_1$ | yalnız $i_1$ |
| 8 kΩ | $V_2$ | yalnız $i_1$ |
| 5 kΩ | $V_3$ | $i_1$ ve $i_2$ (ortak) |
| 6 kΩ | $V_4$ | yalnız $i_2$ |
| 3 kΩ | $V_5$ | yalnız $i_2$ |
| 1 kΩ | $V_6$ | yalnız $i_1$ |

Birinci göz için KVL (kaynağın eksisinden girilerek): $-12 + V_1 + V_2 + V_3 + V_6 = 0$ (ekrandan, 01:35:00). Gerilimler çevre akımlarıyla yazılır: $V_1 = 4000i_1$, $V_2 = 8000i_1$, $V_6 = 1000i_1$. $V_3$ için özel durum vardır: $V_3$'ün referans yönünde $i_1$ artı, $i_2$ eksi katkı yapar (çünkü $i_2$ referansın eksi ucundan girer), yani $V_3 = (i_1 - i_2) \cdot 5000$.

Bir kolda tek bir çevre akımı dolaşıyorsa o kolun akımı çevre akımına eşittir. Ortak kolda ise birden fazla çevre akımı toplanır ve gerçek akım farklıdır; yöntem tam bu farkı kullanır.

### 7.2 Ortak elemanda gerilim referansı

İkinci göz için iki yol vardır.

- **Sabit (mavi) referans kullanmak:** Slayttaki $V_3$ yönü korunursa ikinci göz denklemi $-V_3 + V_4 + V_5 = 0$ olur. $V_3 = (i_1 - i_2)5000$ yerine konunca başta bir eksi gelir: $-(i_1 - i_2)5000 = (i_2 - i_1)5000$.
- **Her göz için kendi yönünde referans (kırmızı) seçmek:** İkinci gözde $V_3$ referansı $i_2$ ile aynı yönde seçilir: $V_3' = (i_2 - i_1)5000$ ve denklem $V_3' + V_4 + V_5 = 0$ olur.

İkisi de aynı denklemi verir.

**Soru:** Hocam, 3'ü (yani $V_3$'ü) niye ters yönde aldınız? **Cevap:** Her çevre için çevre akımı yönüyle uyumlu bir gerilim referansı tanımlanıyor. Mavi referansla yazılsaydı $-V_3 + V_4 + V_5 = 0$ yazmak gerekirdi ve $V_3 = (i_1 - i_2)R_3$ olduğundan başa gelen eksiyle $(i_2 - i_1)R_3$ çıkardı. Kırmızı referans seçilince bu ekstra eksi işlemiyle uğraşılmaz. Pratik olduğu için bu yol önerildi.

> **Hocanın vurgusu:** Hangi çevrenin denklemini yazıyorsanız o çevrenin akım yönündeki gerilim düşümünü pozitif kabul ederseniz işlemler pratikleşir. Sabit bir referans kullanırsanız ikinci çevrede "negatifin negatifi" durumu çıkar; onu gözden kaçırmamak lazım.

### 7.3 Pratik yazım

Gerilim referansları hiç çizilmeden doğrudan yazılabilir (ekrandan, 01:40:00):

$$-12 + 4000i_1 + 8000i_1 + 5000(i_1 - i_2) + 1000i_1 = 0$$

$$6000i_2 + 3000i_2 + 5000(i_2 - i_1) = 0$$

Düzenlenince $18000i_1 - 5000i_2 = 12$ ve $-5000i_1 + 14000i_2 = 0$. Octave'da `A=[18000 -5000; -5000 14000]`, `c=[12;0]` ile çözüm $i_1 \approx 740$ µA, $i_2 \approx 264$ µA (python ile doğrulandı: 740.1 µA ve 264.3 µA).

Yöntemin adımları:

1. Her basit göz için bir çevre akımı yönü tanımlanır.
2. Kaynaklar dışındaki bütün elemanlar için gerilim referans yönleri tanımlanır (ya da her çevre için kendi yönünde alınır).
3. Gerilim düşümleri çevre akımları ve dirençler cinsinden yazılır; her göz için KVL kurulur.
4. Sistem çözülür, sonra eleman gerilimleri ve akımları bulunur.

### 7.4 Eleman gerilimlerinin bulunması

Çevre akımları bulununca her elemandaki gerilim düşümü hesaplanır. Yalnız bir çevrede bulunan elemanın akımı o çevre akımıdır: örneğin $V_1 = 4\text{k} \cdot i_1$, $V_2 = 8\text{k} \cdot i_1$. Ortak elemanda bir yön seçilir: $i_1$ yönünde net gerilim düşümü $(i_1 - i_2) \cdot 5\text{k}$, ters yönde $(i_2 - i_1) \cdot 5\text{k}$'dır.

Slaytta sonuçlar (ekrandan, 01:45:00):

| Akım | Değer (µA) |
|---|---|
| $I_{R1} = i_1$ | 740 |
| $I_{R2} = i_1$ | 740 |
| $I_{R3} = i_1 - i_2$ | 476 |
| $I_{R4} = i_2$ | 264 |
| $I_{R5} = i_2$ | 264 |
| $I_{R6} = i_1$ | 740 |
| $I_{V_{in}} = i_1$ | 740 |

Slayttaki doğrulama: hiçbir çevre akımı, 12 V kaynağa seri eşdeğer dirençten geçen akımdan büyük olmamalıdır. Tek kaynak ve tek eşdeğer dirençli devre gibi çözülür:

$$R_{eq} = 1 + [5 \parallel (3+6)] + 8 + 4 = 16.2 \text{ k}\Omega, \qquad I_{eq} = \frac{12}{16.2\text{ k}\Omega} = 740 \text{ µA}$$

Hoca aynı sağlamanın düğüm analizi bölümünde de bulunduğunu söyleyip geçti.

### 7.5 Düğüm analiziyle karşılaştırma

Aynı tür devre düğüm analiziyle çözülürken dört bağımsız düğümle uğraşılmıştı ($V_1$-$V_4$). Çevre analiziyle ise yalnız iki bağımsız çevre denklemi yetti. Devreyi çözerken hangi yöntemin daha pratik olduğu incelenebilir; belirli bir yöntem istenmişse o kullanılır.

## 8. Çevre Analizi Örnekleri

### 8.1 42 V ve 10 V kaynaklı iki gözlü devre

Slayttaki örnekte iki göz vardır: sol gözde 42 V kaynak ve 6 Ω, ortak kolda 3 Ω, sağ gözde 4 Ω ve 10 V kaynak. Slayttaki çözümde birinci göz denkleminde 3 Ω gerilimi $(I_1 - I_2) \cdot 3$, ikinci gözde $(I_2 - I_1) \cdot 3$ yazılmıştır; yani her göz kendi yönünde pozitif alınmıştır.

> **Hocanın vurgusu:** Ortak elemanda birinci çevrede $(I_1 - I_2)$, ikinci çevrede $(I_2 - I_1)$ yazılmasını karıştırmamanız çok önemli.

<!-- BELİRSİZ: Bu örneğin devre şeması karelerde yok; eleman yerleri ve 10 V kaynağın yönü altyazıdan kurulmuştur. -->

Denklemler:

- Birinci göz: $-42 + 6I_1 + 3(I_1 - I_2) = 0 \Rightarrow 9I_1 - 3I_2 = 42$
- İkinci göz: $-10 + 3(I_2 - I_1) + 4I_2 = 0 \Rightarrow -3I_1 + 7I_2 = 10$

Octave'da `A=[9 -3 ; -3 7]`, `c=[42;10]` ile $I_1 = 6$ A, $I_2 = 4$ A (Octave ekranından, 02:25:00). Gerilimler, çevre akımı yönünde tanımlanarak:

- 6 Ω: yalnız $I_1$ etkili, $6 \cdot 6 = 36$ V.
- 4 Ω: yalnız $I_2$ etkili, $4 \cdot 4 = 16$ V.
- 3 Ω ($I_1$ yönünde): $(6 - 4) \cdot 3 = 6$ V.

### 8.2 Örnek 6: 2 V kaynağın gücü

Slayttaki devre (ekrandan, 01:50:00): sol kolda 5 V kaynak (artı ucu üstte), üst solda 4 Ω, üst sağda 5 Ω, ortak orta kolda 2 Ω ve ona seri 2 V kaynak (artı ucu altta), sağ kolda 1 V kaynak (artı ucu üstte). $i_1$ ve $i_2$ saat yönündedir. İstenen, 2 V kaynağın verdiği güçtür.

- Göz 1: $-5 + 4i_1 + 2(i_1 - i_2) - 2 = 0 \Rightarrow 6i_1 - 2i_2 = 7$
- Göz 2: $+2 + 2(i_2 - i_1) + 5i_2 + 1 = 0 \Rightarrow -2i_1 + 7i_2 = -3$

Çözüm: $i_1 = 43/38 = 1.132$ A, $i_2 = -2/19 = -0.1053$ A (python ile doğrulandı). 2 V kaynaktan yukarıdan aşağıya akan net akım $i_1 - i_2 = 1.132 + 0.105 = 1.237$ A'dir. Akım kaynağa eksi ucundan girdiği için kaynağın emdiği güç

$$p = -(2)(1.237) = -2.474 \text{ W}$$

olur. Negatif emilen güç, kaynağın sisteme 2.474 W enerji verdiği anlamına gelir.

## 9. İdeal Kaynaklar Üzerine Bir Soru

Aradan önce bir öğrenci düğüm analizi örneğindeki (Bölüm 5) akım kaynaklarını sordu.

**Soru:** 2 A'lik kaynağın olduğu kolda 2 A akım var diyoruz. Gerilim kaynaklarında aynı yönlü iki kaynağı topluyor, zıt yönlüleri çıkarıyorduk. Akım kaynağında devrenin diğer yerlerinden gelen akımlar bu kolu etkilemiyor mu? **Cevap:** Akım kaynağı bulunduğu kolda üzerinde yazılı akımı sağlamakla yükümlüdür ve her hâlükârda sağlar. Bunu diğer elemanlardan geçen akımları ve onlardaki gerilim düşümlerini etkileyerek yapar. Gerilim kaynağı için de aynısı geçerlidir: bağlı olduğu iki düğüm arasındaki gerilimi kesin olarak kendisi belirler, bunu diğer elemanlardan geçen akımları etkileyerek sağlar. Tersinden bakınca, akım kaynağı uçlarındaki gerilimi kendisi belirleyemez, bunu devredeki diğer elemanlar belirler; gerilim kaynağı da üzerinden geçen akımı kendisi belirleyemez.

**Soru:** Yani denklemi yazarken 2 A'lik kaynağın kolundaki akımı 2 A, 4 A'lik kaynağın kolundakini 4 A kabul edeceğiz, değil mi? **Cevap:** Evet; o kollardaki akımı ideal kaynaklar belirler. 4 A'lik kaynak 2 A'lik kolu bozmaz; 4 A'nın etkisi diğer elemanlara öyle dağılır ki 2 A'lik kaynağın kolundaki akım 2 A olarak kalır. Aranan da zaten budur: kaynak kollarında 2 A ve 4 A geçmesi için diğer elemanların akımları ne olmalıdır?

## 10. Süper Düğüm (Supernode)

### 10.1 Sorunun ortaya çıkışı

Slayttaki devrede (ekrandan, 02:10:00) referans alt düğümdür. Sağ altta $V_1$ kaynağı (eksi ucu referansta, artı ucu $a$ düğümünde) vardır. $a$ ile $c$ arasında $R_1$, $a$ ile $b$ arasında $R_2$, $b$ ile referans arasında $R_3$, $b$ ile $c$ arasında ise $V_2$ kaynağı (artı ucu $c$ tarafında) bulunur. $V_1$'in eksi ucu referansa bağlı olduğu için sorun yaratmaz. $V_2$ ise referanstan uzaktadır: iki ucu da toprağa bağlı değildir.

Adımlar uygulanınca düğümler $v_a$, $v_b$, $v_c$ olarak etiketlenir. $R_1$'den geçen akım yazılabilir: $(v_a - v_c)/R_1$. Ama $c$ ile $b$ arasındaki kolda direnç yoktur, yalnız bir gerilim kaynağı vardır. Gerilim kaynağı kendi akımını belirleyemez; bu akımı devredeki diğer elemanlar belirler. Bu yüzden bu akım doğrudan yazılamaz. Slaytta düz düğüm analiziyle yazılan $\dfrac{v_a - v_b}{R_2} - \dfrac{v_b}{R_3} + i_{V_2} = 0$ denklemindeki $i_{V_2}$ bu yüzden soru işaretiyle gösterilmiştir.

Çözüm, $a$, $c$ ve $b$ arasındaki tek kol akımını şöyle ifade etmektir: $v_c$, $v_b$'den $V_2$ kadar büyüktür ve bu koldaki akımı $(v_a - v_c)/R_1$ belirler. Böylece akım, $v_c$ ve $v_b$ birbirine bağlanır.

### 10.2 Kural

Bir gerilim kaynağının hiçbir ucu referans düğüme bağlı değilse süper düğüm oluşur. Bu yalnız bağımsız gerilim kaynakları için değil, bağımlı gerilim kaynakları için de geçerlidir. İkisinin ortak özelliği, üzerlerinden geçen akımı kendilerinin belirleyememesidir.

İlk denklem, $v_b$ ile $v_c$ arasındaki ilişkidir: $v_c = v_b + V_2$. Hangisinin büyük olduğu karıştırılırsa şu yol izlenebilir: $v_b$ ve $v_c$ referansa göre tanımlı gerilimler olarak çizilir ve referanstan başlayıp $v_b$'den, kaynağın eksi ucundan girip artı ucundan çıkarak $v_c$ üzerinden referansa dönen bir KVL yolu yazılır:

$$-v_b - V_2 + v_c = 0 \;\Rightarrow\; v_c = V_2 + v_b$$

İkinci denklem $v_a = V_1$'dir. $b$ düğümünde KCL (ekrandan, 02:10:00):

$$\frac{V_1 - v_b}{R_2} - \frac{v_b}{R_3} + \frac{V_1 - (v_b + V_2)}{R_1} = 0$$

Son terim, $R_1$ kolunun (yani kaynağın) akımıdır ve $v_c$ yerine $v_b + V_2$ konarak yazılmıştır. Bu denklemde tek bilinmeyen $v_b$'dir. $v_b$ bulunca $v_c$, sonra $R_1$ akımı Ohm yasasıyla hesaplanır. Normalde iki bilinmeyen ve iki denklem gerekirdi; süper düğüm sayesinde çözüm tek bilinmeyenle yapıldı.

> **Ders sonrası not:** Hoca burada bir an "süperpozisyon özelliğini kullanarak" dedi; kastedilen süper düğümdür. Süperpozisyon ayrı bir konudur.

### 10.3 Referans seçiminin etkisi

Hoca bir kavram örneğinde 4 V ve 8 V iki kaynaklı bir devre gösterdi. Referans alt düğüm seçilince 4 V kaynak referansa bağlı olduğu için süper düğüm oluşturmaz; 8 V kaynak ise referanstan uzaktadır ve süper düğüm oluşturur. Referans başka bir düğüm seçilseydi bu kez 4 V kaynağın çevresi süper düğüm olurdu; o kaynağın akımını belirleyemediği için ona seri bağlı düğüm ve dirençleri dikkate almak gerekirdi. <!-- BELİRSİZ: Bu kavram örneğinin şeması karelerde yok. -->

Önemli olan, süper düğüm oluşturan kaynağın iki ucundaki düğüm gerilimlerinin kaynak gerilimi cinsinden yazılmasıdır. $N$ düğüm için $N$ denklem gerekirken denklemlerden biri bu gerilim eşitliğinden gelir ve geriye $N-1$ düğüm denklemi kalır.

### 10.4 Örnek 3: Bağımlı kaynaklı süper düğüm

Slayttaki devre bir elmas biçimindedir (ekrandan, 02:20:00). Orta düğüm referanstır. Düğümler: solda $v_1$, üstte $v_2$, sağda $v_3$, altta $v_4$.

| Eleman | Bağlantı | Not |
|---|---|---|
| 0.5 Ω | $v_1$ – $v_2$ | gerilimi $v_x$ (artı ucu $v_2$ tarafında) |
| 2 Ω | $v_2$ – $v_3$ | |
| 14 A akım kaynağı | referans → $v_2$ | $v_2$'ye giren |
| 12 V gerilim kaynağı | $v_1$ – referans | eksi ucu $v_1$'de, artı ucu referansta |
| $0.5v_x$ bağımlı akım kaynağı | referans → $v_3$ | $v_3$'e giren |
| 2.5 Ω | $v_1$ – $v_4$ | gerilimi $v_y$ (artı ucu $v_4$ tarafında) |
| 1 Ω | referans – $v_4$ | |
| $0.2v_y$ bağımlı gerilim kaynağı | $v_3$ – $v_4$ | |

Slayttaki yönerge: düğümleri ve süper düğümleri belirle, referans dışındaki her düğümde KCL yaz.

**Süper düğümleri belirleme:** Bağımlı gerilim kaynağının ($0.2v_y$) hiçbir ucu referansa bağlı değildir; bu bir süper düğümdür ($v_3$ ve $v_4$). 12 V kaynağın artı ucu referansa bağlı olduğu için ayrıca süper düğüm gibi ele almak gerekmez; doğrudan $v_1 = -12$ V denilebilir. Bu da süper düğüm kavramının bir tür kullanımıdır.

**Denklemler:**

- $v_1 = -12$ V.
- $v_2$ düğümü: 14 A girer; çıkan akımlar $\dfrac{v_2 - v_1}{0.5}$ ve $\dfrac{v_2 - v_3}{2}$:

$$\frac{v_2 - v_1}{0.5} + \frac{v_2 - v_3}{2} = 14$$

- $v_3$ düğümü: $0.5v_x$ girer. Çıkanlardan biri $\dfrac{v_3 - v_2}{2}$'dir. $v_3$'ten $v_4$'e akan akımı bağımlı gerilim kaynağı belirleyemez; bu akım $v_4$'te ikiye ayrılır: $v_4$'ten referansa ve $v_4$'ten $v_1$'e. Bu yüzden kaynak akımı yerine bu iki kolun toplamı yazılır:

$$0.5v_x = \frac{v_3 - v_2}{2} + \frac{v_4}{1} + \frac{v_4 - v_1}{2.5}$$

**Bilinmeyenlerin indirgenmesi:** Bilinmeyenler $v_1$, $v_2$, $v_3$, $v_4$ ve $v_x$, $v_y$'dir. $v_1$'e $v_x$ eklenince $v_2$ elde edilir: $v_x = v_2 - v_1$. Bağımlı gerilim kaynağı $v_3$ ile $v_4$ arasındaki farkı verir: $v_3 - v_4 = 0.2v_y$. $v_y$ de $v_4 - v_1$ olarak yazılır (ekrandan, 02:25:00):

$$v_3 - v_4 = 0.2v_y = 0.2(v_4 - v_1), \qquad 0.5v_x = 0.5(v_2 - v_1)$$

Yerine koyma ve düzenlemeyle (ekrandan, 02:25:00):

$$\begin{aligned}
-2v_1 + 2.5v_2 - 0.5v_3 &= 14 \\
0.1v_1 - v_2 + 0.5v_3 + 1.4v_4 &= 0 \\
v_1 &= -12 \\
0.2v_1 + v_3 - 1.2v_4 &= 0
\end{aligned}$$

Octave'da katsayı matrisi `[-2 2.5 -0.5 0; 0.1 -1 0.5 1.4; 1 0 0 0; 0.2 0 1 -1.2]` ve sağ taraf `[14; 0; -12; 0]` girildi. Sonuç:

$$v_1 = -12 \text{ V}, \quad v_2 = -4 \text{ V}, \quad v_3 = 0 \text{ V}, \quad v_4 = -2 \text{ V}$$

(python ile çözüldü ve her üç KCL/kaynak ilişkisinde sağlandı). İlginç bir sonuç olarak $v_3 = 0$ çıkmıştır; bu düğüm referansla aynı potansiyeldedir.

## 11. Süper Çevre (Supermesh)

### 11.1 Sorunun ortaya çıkışı

Klasik bir iki gözlü devrede iki gözün ortak kolunda bir akım kaynağı $I_s$ olsun. Basit gözler üzerinden denklem yazılırsa birinci göz için $i_1 - i_2 = I_s$ çıkar, çünkü bu koldaki akımı diğer elemanlara bakmaksızın $I_s$ belirler. İkinci göz için $i_2 - i_1 = -I_s$ çıkar. Bu iki denklem aynıdır; doğrusal bağımsız iki denklem yazılamaz.

Çözümün kolay yolu önceki derslerden bilinir: yalnız iki çevre yazmak zorunda değiliz, daha fazla kapalı yol tanımlanabilir. Devreyi çözmek için iki bilinmeyene karşı iki bağımsız denklem gerekir. Gözlerden biri olduğu gibi bırakılır, ikinci denklem ise ortak akım kaynağını içermeyen başka bir yol üzerinden yazılır. Böylece doğrusal bağımsız iki denklem elde edilir.

### 11.2 Yol

1. Temel gözler için çevre akımları ($i_1$, $i_2$, $i_3$) tanımlanır.
2. İki çevre arasında ortak bir akım kaynağı varsa KVL'nin uygulandığı yollardan biri daha dolambaçlı seçilir: akım kaynağını içermeyen daha geniş bir kapalı yol.
3. Bu geniş yolda gerilim düşümleri yine basit çevre akımları ($i_1$, $i_2$, $i_3$) cinsinden yazılabilir; ya da bu yol boyunca ayrı bir sanal çevre akımı varsayılabilir. İkisi de aynı sonucu verir.
4. Akım kaynağı kısıtı ayrı bir denklem olarak yazılır.
5. Üç gözlü devrede üç doğrusal bağımsız denklem kurulup çözülür.

### 11.3 Örnek 7

Slayttaki devre (ekrandan, 02:30:00 ve 02:35:00): solda 7 V kaynak (artı ucu üstte). Orta dikey kolda yukarıdan aşağı 1 Ω, bir orta düğüm, 7 A akım kaynağı (aşağı yönlü) ve 2 Ω vardır. Sağ dikey kolda yukarıdan aşağı 2 Ω, bir orta düğüm ve 1 Ω vardır. Orta kolun orta düğümü ile sağ kolun orta düğümü arasında 3 Ω bulunur; 3 Ω'daki akım $i$ sağa doğrudur. Göz akımları saat yönündedir: $i_1$ sol göz (7 V kaynak, orta kol), $i_2$ sağ üst göz (1 Ω, 2 Ω, 3 Ω), $i_3$ sağ alt göz (3 Ω, 1 Ω, 7 A ve 2 Ω).

7 A kaynak $i_1$ ve $i_3$ gözlerinin ortak kolundadır. Süper çevre yolu (mavi), 7 V kaynaktan başlayıp üstteki 1 Ω, 3 Ω ve sağ alttaki 1 Ω üzerinden dolaşır ve akım kaynağını içermez.

- Süper çevre: kaynağın eksisinden girilir, $-7$. 1 Ω'dan geçilir: referans yönünde $i_1$ artı, $i_2$ eksi katkı yapar, $(i_1 - i_2) \cdot 1$. 3 Ω'dan geçilir: $i_3$ artı, $i_2$ eksi katkı yapar, $(i_3 - i_2) \cdot 3$. Sağ alt 1 Ω'da yalnız $i_3$ etkilidir, $i_3 \cdot 1$:

$$-7 + 1(i_1 - i_2) + 3(i_3 - i_2) + 1i_3 = 0$$

- 2. göz: $2i_2$, ortak 3 Ω'da $(i_2 - i_3) \cdot 3$, ortak 1 Ω'da $(i_2 - i_1) \cdot 1$:

$$1(i_2 - i_1) + 2i_2 + 3(i_2 - i_3) = 0 \;\Rightarrow\; -i_1 + 6i_2 - 3i_3 = 0$$

- Bağımsız kaynak kısıtı (kaynak aşağı yönlü, $i_1$ bu kolda aşağı, $i_3$ yukarı akar):

$$i_1 - i_3 = 7$$

Sonuç (ekrandan, 02:30:00; python ile doğrulandı):

$$i_1 = 9 \text{ A}, \quad i_2 = 2.5 \text{ A}, \quad i_3 = 2 \text{ A}$$

Eleman gerilimleri:

- 7 A kaynağa seri 2 Ω: bu kolun akımını kaynak belirler, $7 \cdot 2 = 14$ V.
- Üstteki 1 Ω: $(i_1 - i_2) \cdot 1 = 6.5$ V.
- 3 Ω (verilen yönde): $(i_3 - i_2) \cdot 3 = (2 - 2.5) \cdot 3 = -1.5$ V.

> **Ek bilgi (derste anlatılmadı):** Slaytta istenen $i$ akımı 3 Ω'dan sağa doğru akan akımdır. Bu kolda $i_3$ soldan sağa, $i_2$ sağdan sola aktığı için $i = i_3 - i_2 = -0.5$ A olur; yani 3 Ω'dan gerçekte 0.5 A sola doğru akım geçer. Bu sonuç derste hesaplanan $-1.5$ V'luk gerilimle ($-1.5/3$) tutarlıdır.

## 12. Düğüm ve Çevre Analizinin Karşılaştırılması

### 12.1 Düzlemsel devreler

Düzlemsel (planar) devre, elemanları ve bağlantıları birbirinin üzerinden geçmek zorunda kalmadan bir düzleme çizilebilen devredir. Birbirini kesmeyecek biçimde çizilmeye çalışıldığı hâlde bir düzlemde ifade edilemeyen devreler düzlemsel olmayan devrelerdir.

> **Ek bilgi (derste anlatılmadı):** Çevre (göz) analizi yalnız düzlemsel devrelere doğrudan uygulanır, çünkü "göz" kavramı devrenin düzleme çizimine dayanır. Düğüm analizi ise düzlemsel olmayan devrelerde de kullanılabilir.

### 12.2 Karşılaştırma örneği

Slayttaki devre (ekrandan, 02:40:00): solda 100 V kaynak (artı ucu üstte). Üst hatta soldan sağa 8 Ω, $v_1$ düğümü, 2 Ω (akım $i_x$ sağa), $v_2$ düğümü, 10 Ω, $v_3$ düğümü vardır. $v_1$'den toprağa 4 Ω, $v_2$'den toprağa 3 Ω, $v_3$'ten toprağa 5 Ω bağlıdır. $v_2$ ile $v_3$ arasında 10 Ω'a paralel, $v_3$'ten $v_2$'ye doğru 8 A akım kaynağı bulunur. Devrede 5 düğüm ve 4 göz vardır.

Çevre analiziyle 4 denklem yeter; düğüm analiziyle biri referans seçilince yine 4 düğüm kalır. Bu durumda iki yöntem arasında bir fark yoktur. Farklı topolojilerde kaç düğüm, kaç çevre denklemi gerektiğine bakılarak pratik olan seçilir.

**Düğüm analizi:** Referans belirlenir. 100 V kaynakla 8 Ω arasındaki düğüm için ek bir tanım gerekmez; gerilimi açıkça 100 V'tur. Kalan düğümler $v_1$, $v_2$, $v_3$'tür. Pratik bir yaklaşım: her düğüm için, referans akım ve gerilim yönü tanımlamadan, o düğümden dışarı çıkan bütün akımların toplamı sıfıra eşitlenir. Bir dalın akım yönü her düğümün denkleminde o düğümden dışarı doğru alınır; yalnız o denklem için geçerlidir.

$$\frac{v_1 - 100}{8} + \frac{v_1}{4} + \frac{v_1 - v_2}{2} = 0 \quad\text{ya da}\quad 0.875v_1 - 0.5v_2 = 12.5$$

$$\frac{v_2 - v_1}{2} + \frac{v_2}{3} + \frac{v_2 - v_3}{10} - 8 = 0$$

$$\frac{v_3 - v_2}{10} + \frac{v_3}{5} + 8 = 0 \quad\text{ya da}\quad -0.1v_2 + 0.3v_3 = -8$$

İkinci denklemde 8 A giren akımdır. Çözüm (ekrandan, 02:40:00): $v_1 = 25.89$ V, $v_2 = 20.31$ V ve

$$i_x = \frac{v_1 - v_2}{2} = 2.79 \text{ A}$$

> **Ders sonrası not:** Slaytta ikinci denklemin düzenlenmiş biçimi $-0.5v_1 - 0.9333v_2 - 0.1v_3 = 8$ yazılmıştır; doğrusu $-0.5v_1 + 0.9333v_2 - 0.1v_3 = 8$'dir. Python ile çözüm bu düzeltilmiş biçimle $v_1 = 25.89$ V, $v_2 = 20.31$ V, $v_3 = -19.90$ V ve $i_x = 2.79$ A verir. Altyazıda $v_2$ "20.53" diye geçer; slayttaki ve hesaplanan değer 20.31 V'tur.

**Çevre analizi:** Çevre akımları tanımlanır (ekrandan, 02:45:00): $i_1$ (100 V, 8 Ω, 4 Ω), $i_2$ (4 Ω, 2 Ω, 3 Ω), $i_3$ (3 Ω, 10 Ω, 5 Ω), $i_4$ (8 A kaynak ve 10 Ω'un oluşturduğu üst göz). Önce iki çevre arasında ortak bir akım kaynağı olup olmadığına, yani süper çevre olup olmadığına bakılır; yoktur. 8 A kaynak yalnız $i_4$ gözündedir.

- $i_1$: $-100 + 8i_1 + 4(i_1 - i_2) = 0$ ya da $12i_1 - 4i_2 = 100$
- $i_2$: $4(i_2 - i_1) + 2i_2 + 3(i_2 - i_3) = 0$ ya da $-4i_1 + 9i_2 - 3i_3 = 0$
- $i_3$: $3(i_3 - i_2) + 10(i_3 - i_4) + 5i_3 = 0$
- $i_4$ gözünün akımını o gözdeki 8 A kaynak belirler; yönleri ters olduğu için $i_4 = -8$ A. Yerine konunca üçüncü denklem $3(i_3 - i_2) + 10(i_3 + 8) + 5i_3 = 0$, yani $-3i_2 + 18i_3 = -80$ olur.

Dört bilinmeyen, dört denklem. Çözüm $i_2 = i_x = 2.79$ A'dir (python ile: $i_1 = 9.26$ A, $i_2 = 2.79$ A, $i_3 = -3.98$ A). Aynı devre hem çevre hem düğüm analiziyle çözülmüş oldu.

### 12.3 Seçim ölçütü

Denklem sayılarında fark yoksa seçim arasında anlam farkı yoktur. Bir devrede göz sayısı 20, düğüm sayısı 2 ise (örneğin her elemanın paralel bağlandığı bir devre) düğüm analizi mantıklıdır. Bütün elemanları seri bağlı, her iki eleman arasında bir düğüm bulunan bir devrede düğüm denklemi sayısı çok yüksektir; orada çevre analizi anlamlıdır. Devrenin düğüm ve göz sayısına bakarak uygun yönteme karar verilir.

## 13. Ders Sonunda Sorulan Soru: Süper Düğüm Denklemi

Ders sonunda sohbet kutusundan Örnek 3'ün (Bölüm 10.4) son denklemine dair bir soru geldi. Hoca denklemi düğümden çıkan akımlar toplamı sıfır mantığıyla yeniden açıkladı.

- Birinci düğüm referansa doğrudan bir kaynakla bağlıdır; gerilimi doğrudan belirlenir.
- İkinci düğüm: $\dfrac{v_2 - v_1}{0.5} - 14 + \dfrac{v_2 - v_3}{2} = 0$. 14 A giren akım olduğu için eksi işaretiyle sol tarafa alındı.
- Üçüncü düğüm: ilk terim $\dfrac{v_3 - v_2}{2}$'dir. Bağımlı akım kaynağı içeri yönlü olduğu için $-0.5v_x$ yazılır. Son olarak $v_3$'ten $v_4$'e giden akım gerekir. Bu akım, kolda bağımlı (ya da bağımsız) bir gerilim kaynağı olduğu için kaynağa bakılarak yazılamaz; süper düğümün sorunu tam da budur. Ama bu akımın $v_4$'e vardıktan sonra iki kola ayrıldığı bilinir: $v_4$'ten referansa ve $v_4$'ten $v_1$'e. Bu yüzden $\dfrac{v_4 - 0}{1} + \dfrac{v_4 - v_1}{2.5}$ yazılır.
- Ardından $v_y = v_4 - v_1$ yazılır; çünkü $v_y$, $v_3$ ile $v_4$ arasındaki farkı belirleyen bağımlı gerilim kaynağının değerini verir. Böylece denklemde $v_3$, $v_4$ ve $v_y$ birbirine bağlanır ve bir bilinmeyen giderilir.

Kısacası son satırdaki denklemde ilk terim $v_3$'ten $v_2$'ye çıkan akım, ikinci terim giren bağımlı kaynak akımı, son iki terim ise süper düğüm kolundan çıkan ve $v_4$'te ikiye ayrılan akımdır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:45:00 ve 00:55:00): 10 V kaynak, 9 kΩ, 2 kΩ, 5 kΩ, 3 kΩ, 1 kΩ ve 7 kΩ'luk devrede (Bölüm 4.2) düğüm gerilimleri bilindikten sonra dirençlerin gerilimlerini ve akımlarını bulun.

> **Çözüm:** $V_1 = 10$ V; düğüm denklemleri çözülünce $V_2 = 5.549$ V, $V_3 = 4.560$ V, $V_4 = 3.736$ V, $V_5 = 3.462$ V. Direnç gerilimleri: 4.45, 0.990, 1.10, 0.824, 0.274, 3.46 V. Ana kol akımı $I = 4.45/9\text{k} \approx 0.495$ mA, $I_3 = 1.10/5\text{k} = 0.220$ mA, $I_4 = I_5 = 0.824/3\text{k} = 0.275$ mA. Hiçbir direnç gerilimi 10 V'u aşmaz.

**Soru 2** (ekrandan, 01:10:00 ve 01:20:00): 2 A ve 4 A akım kaynakları, 15 Ω, 7 Ω + 3 Ω seri kolu ve 5 Ω'luk devrede (Bölüm 5) düğüm gerilimlerini ve dal akımlarını düğüm analiziyle bulun.

> **Çözüm:** $5v_1 - 2v_2 = 60$, $v_1 - 4v_2 = -60$; $v_1 = v_2 = 20$ V. $I_1 = 2$ A, $I_3 = 4$ A, 15 Ω'dan akım geçmez.

**Soru 3** (derste sözlü, 01:21:06): Bu devrede $v_1$ ile $v_2$ arasındaki 15 Ω'dan akan akım ne olur?

> **Çözüm:** İki düğüm de 20 V'ta olduğu için $(20-20)/15 = 0$ A.

**Soru 4** (ekrandan, 01:35:00-01:45:00): 12 V kaynak, 4 kΩ, 8 kΩ, 5 kΩ, 6 kΩ, 3 kΩ ve 1 kΩ'luk iki gözlü devrede (Bölüm 7.1) çevre akımlarını bulun ve sonucu eşdeğer dirençle doğrulayın.

> **Çözüm:** $18000i_1 - 5000i_2 = 12$, $-5000i_1 + 14000i_2 = 0$; $i_1 = 740$ µA, $i_2 = 264$ µA, 5 kΩ'da 476 µA. $R_{eq} = 16.2$ kΩ, $12/16.2\text{k} = 740$ µA.

**Soru 5** (derste sözlü, 01:45:34): 42 V, 6 Ω, 3 Ω, 4 Ω ve 10 V'luk iki gözlü devrede çevre akımlarını ve direnç gerilimlerini bulun. <!-- BELİRSİZ: Devre şeması karelerde yok. -->

> **Çözüm:** $9I_1 - 3I_2 = 42$, $-3I_1 + 7I_2 = 10$; $I_1 = 6$ A, $I_2 = 4$ A. Gerilimler: 6 Ω'da 36 V, 4 Ω'da 16 V, 3 Ω'da 6 V.

**Soru 6** (ekrandan, 01:50:00): 5 V, 4 Ω, 5 Ω, 2 Ω, 2 V ve 1 V'luk devrede (Bölüm 8.2) 2 V kaynağın verdiği gücü bulun.

> **Çözüm:** $6i_1 - 2i_2 = 7$, $-2i_1 + 7i_2 = -3$; $i_1 = 1.132$ A, $i_2 = -0.1053$ A. Kaynaktan geçen akım 1.237 A; emilen güç $-2.474$ W, yani kaynak 2.474 W verir.

**Soru 7** (ekrandan, 02:20:00 ve 02:25:00): Bağımlı kaynaklı elmas devrede (Bölüm 10.4) düğümleri ve süper düğümleri belirleyin, düğüm-referans gerilimlerini bulun.

> **Çözüm:** Süper düğüm $0.2v_y$ kaynağının uçlarıdır ($v_3$, $v_4$). $v_1 = -12$ V, $v_2 = -4$ V, $v_3 = 0$ V, $v_4 = -2$ V.

**Soru 8** (ekrandan, 02:30:00): 7 V, 7 A ve 1 Ω, 2 Ω, 3 Ω, 2 Ω, 1 Ω'luk devrede (Bölüm 11.3) süper çevre kullanarak çevre akımlarını bulun; slaytta istenen $i$ akımını hesaplayın.

> **Çözüm:** $-7 + (i_1-i_2) + 3(i_3-i_2) + i_3 = 0$, $-i_1 + 6i_2 - 3i_3 = 0$, $i_1 - i_3 = 7$; $i_1 = 9$ A, $i_2 = 2.5$ A, $i_3 = 2$ A. Derste 3 Ω gerilimi $-1.5$ V bulundu.

> **Çözüm (derste verilmedi):** 3 Ω'dan sağa doğru akım $i = i_3 - i_2 = -0.5$ A (python ile doğrulandı).

**Soru 9** (ekrandan, 02:40:00 ve 02:45:00): 100 V kaynak, 8 A akım kaynağı ve 8, 4, 2, 3, 10, 5 Ω'luk devrede (Bölüm 12.2) $i_x$'i önce düğüm, sonra çevre analiziyle bulun.

> **Çözüm:** Düğüm: $v_1 = 25.89$ V, $v_2 = 20.31$ V, $i_x = 2.79$ A. Çevre: $i_4 = -8$ A, $12i_1 - 4i_2 = 100$, $-4i_1 + 9i_2 - 3i_3 = 0$, $-3i_2 + 18i_3 = -80$; $i_2 = i_x = 2.79$ A.

**Soru 10** (derste sözlü, 00:17:29): İki gözlü bir devrede iki basit gözden başka üçüncü bir çevrim var mıdır? Kaç tanesi bağımsızdır?

> **Çözüm:** Devrenin dış çevresi üçüncü bir çevrimdir. Ama üç çevrimden yalnız ikisi doğrusal bağımsızdır; üçüncüsü diğer ikisinin birleşimidir.

## Dersin Toparlaması

Ders, Y-Δ dönüşümünün eşdeğerlik denklemleri ve köprü devresinin hassas ölçümdeki rolü hatırlatılarak başladı. Ardından karmaşık devreler için iki sistematik yöntem tanıtıldı. Düğüm analizinde referans seçilir, düğümler etiketlenir, KCL denklemleri akımlar düğüm gerilimleriyle ("başlangıç eksi varış, bölü direnç") yazılarak kurulur ve çözülür. Çevre analizinde her göze sanal bir çevre akımı verilir, KVL denklemleri ortak elemanlarda akım farkı kullanılarak yazılır ve her çevrenin kendi akım yönü pozitif alınır. Elde edilen denklem sistemleri matris biçimine getirilip Cramer kuralıyla ya da Octave/MATLAB ile çözüldü. Sonuçlar, direnç gerilimlerinin kaynak gerilimlerini aşmaması ve ana kol akımının $V/R_{eq}$ ile karşılaştırılması gibi sağlamalarla kontrol edildi.

Dersin son bölümünde iki özel durum işlendi. Uçlarından hiçbiri referansa bağlı olmayan bir gerilim kaynağı süper düğüm oluşturur; kaynağın uç gerilimleri kaynak gerilimiyle bağlanır ve kaynak akımı komşu kolların akımlarıyla yazılır. İki gözün ortak kolundaki akım kaynağı süper çevre oluşturur; bir denklem kaynak kısıtından, diğeri kaynağı içermeyen daha geniş bir yoldan gelir. Son olarak aynı devre iki yöntemle çözülerek yöntem seçiminin düğüm ve göz sayısına göre yapılacağı gösterildi. Bir sonraki derste doğrusallık, süperpozisyon, kaynak dönüşümü ve Thevenin-Norton eşdeğerleri işlenecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
