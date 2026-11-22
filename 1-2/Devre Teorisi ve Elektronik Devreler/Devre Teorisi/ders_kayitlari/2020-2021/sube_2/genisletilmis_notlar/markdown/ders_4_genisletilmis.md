# Ders 4 Genişletilmiş Notu: Düğüm Gerilimleri ve Çevre Akımları Analizi

> Kayıt iki parçadır; arşivde parçalar yanlış sırada birleştirildiği için altyazıdaki sıra düzeltildi ve saat damgaları düzeltilmiş altyazıya göredir.

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Tekrarı ve Bu Dersin Amacı
- 2. Matematik Ön Bilgisi: Denklem Sistemlerinin Çözümü
- 3. Düğüm Gerilimleri Analizi (Nodal Analysis)
- 4. Example 02: İki Akım Kaynaklı Devre
- 5. Süper Düğüm (Supernode)
- 6. Sınıf Alıştırması: İki Süper Düğümlü Devre
- 7. Example 03: Bağımlı Kaynaklı Düğüm Analizi
- 8. Çevre Akımları Analizi (Mesh Analysis)
- 9. Example 05 ve Example 06: Çevre Analizi Örnekleri
- 10. Süper Çevre (Supermesh)
- 11. Düzlemsel ve Düzlemsel Olmayan Devreler
- Örnek Sorular

## 1. Önceki Dersin Tekrarı ve Bu Dersin Amacı

Hoca derse bir önceki haftanın kısa bir tekrarıyla başlar. Geçen hafta gerilim bölücü ve akım bölücü devrelere bakılmıştı. Gerilim bölücüde dirençler seri bağlanır ve merdiven basamakları gibi her direncin üzerinde ana hattaki gerilimin bir parçası birikir; böylece gerilim bölünmüş olur. Akım bölücüde ise paralel dirençler akımı paylaşır. Bunun yanında seri ve paralel dirençlerin eşdeğer direnci, direncin tersi olan iletkenlik (conductance) ile analiz, seri gerilim kaynaklarının toplanması, ideal gerilim kaynaklarının ancak teoride ve aynı gerilimdeyse paralel bağlanabileceği, akım kaynaklarının da yönlerine bakılarak paralelde nasıl tek bir eşdeğer kaynağa indirildiği görülmüştü.

Bu haftanın konusu, KCL, KVL ve Ohm yasasını ($V = IR$) kullanarak iki sistematik analiz yöntemidir: **düğüm gerilimleri analizi** (node voltage) ve **çevre akımları analizi** (mesh current).

Hoca önce iki yasayı hatırlatır. KCL'ye göre bir düğümde, örneğin $I_1$, $I_2$, $I_3$ akımlarının birleştiği bir noktada, düğüme giren akımların toplamı çıkan akımların toplamına eşittir. Düğüm analizinde amaç, bu bilgiyi kullanarak düğümün geriliminin ne olduğunu bulmaktır. KVL ise tek bir kaynak ($V_1$) ve bir dirençten ($V_R$) oluşan basit bir devrede $V_1$'in $V_R$'ye eşit olduğunu, işaretli yazıldığında da gerilimlerin toplamının sıfır olduğunu söyler. KVL'nin temel şartı kapalı bir çevre (loop) olmasıdır. Hoca devreyi bir yerden açık devre bırakarak gösterir: açık kalan kısımda ne olduğu bilinmediği için KVL yazılamaz, dolayısıyla o koldan geçen akım da bulunamaz. KVL, enerjinin korunumunu, yani üretilen gücün tüketilen güce eşit olmasını ifade eder.

Çevre analizinde "mesh" denen şey aslında bir loop'tur; çevre akımı (mesh current) bu loop'u oluşturan elemanlardan geçen akımdır ve KVL üzerinden bulunur. Özetle:

- Düğüm analizi: KCL kullanılır, bilinmeyenler düğüm gerilimleridir.
- Çevre analizi: KVL kullanılır, bilinmeyenler çevre akımlarıdır.

## 2. Matematik Ön Bilgisi: Denklem Sistemlerinin Çözümü

Düğüm ve çevre analizinde $V_1, V_2, V_3$ ya da $I_1, I_2$ gibi birden çok bilinmeyen içeren denklemler çıkar. Hoca bu yüzden önce bu denklemlerin nasıl çözüleceğini hatırlatır. İki yol vardır.

### 2.1 Yerine koyma (substitution)

Denklemler $a_1 x + b_1 y = c_1$ ve $a_2 x + b_2 y = c_2$ biçiminde olsun ($a$, $b$, $c$ sabit sayılar; örneğin $5x + 3y = 4$). Birinci denklemden $x = (c_1 - b_1 y)/a_1$ çekilir, ikinci denklemde $x$ yerine yazılır. Geriye yalnız $y$ kalır, $y$ bulunur, sonra $x$ hesaplanır. İki bilinmeyende bu yöntem basittir. Ama örneklerde dört-beş denklem çıkabilir, bazı denklemlerde bazı değişkenler hiç bulunmayabilir; o zaman iş karmaşıklaşır.

### 2.2 Determinant ile çözüm

Bu durumda denklemler matris biçimine getirilir (ekrandan, 00:14:09):

$$\begin{bmatrix} a_1 & b_1 \\ a_2 & b_2 \end{bmatrix} \times \begin{bmatrix} x \\ y \end{bmatrix} = \begin{bmatrix} c_1 \\ c_2 \end{bmatrix}$$

Bu yazım, $a_1 x + b_1 y = c_1$ ve $a_2 x + b_2 y = c_2$ demekle aynıdır. Hoca matris çarpımının şartını da hatırlatır: $2\times2$ bir matris ancak $2\times1$ bir vektörle çarpılabilir; birinci matrisin sütun sayısı ikincinin satır sayısına eşit olmalıdır.

Determinantlar:

$$D = \begin{vmatrix} a_1 & b_1 \\ a_2 & b_2 \end{vmatrix} = a_1 b_2 - a_2 b_1, \qquad D_x = c_1 b_2 - c_2 b_1, \qquad D_y = a_1 c_2 - a_2 c_1$$

$$x = \frac{D_x}{D}, \qquad y = \frac{D_y}{D}$$

$D_x$ hesaplanırken sağ taraftaki $c_1, c_2$ değerleri $x$'in katsayılarının bulunduğu sütuna, $D_y$ için de $y$'nin katsayılarının sütununa yazılır. Fark yalnız budur. Hoca slaytta $D_x$ ve $D_y$ ifadelerinde yazım hataları olduğunu fark edip yukarıdaki doğru biçimlerini söyler.

> **Ek bilgi (derste anlatılmadı):** Determinantlar oranıyla bilinmeyenleri bulma yöntemine Cramer kuralı denir. Yöntem yalnız $D \neq 0$ olduğunda, yani denklem sisteminin tek çözümü olduğunda kullanılabilir.

### 2.3 Üç bilinmeyenli sistem

Üç bilinmeyende denklemler $a_i x + b_i y + c_i z = d_i$ ($i = 1, 2, 3$) biçimindedir ve $3\times3$ katsayı matrisi ile $3\times1$ bilinmeyen vektörü çarpılıp $d_1, d_2, d_3$ vektörüne eşitlenir (ekrandan, 00:19:09).

$$x = \frac{\begin{vmatrix} d_1 & b_1 & c_1 \\ d_2 & b_2 & c_2 \\ d_3 & b_3 & c_3 \end{vmatrix}}{D}, \quad y = \frac{\begin{vmatrix} a_1 & d_1 & c_1 \\ a_2 & d_2 & c_2 \\ a_3 & d_3 & c_3 \end{vmatrix}}{D}, \quad z = \frac{\begin{vmatrix} a_1 & b_1 & d_1 \\ a_2 & b_2 & d_2 \\ a_3 & b_3 & d_3 \end{vmatrix}}{D}$$

$3\times3$ determinantı için hocanın kullandığı yol şudur: ilk iki sütun matrisin sağına tekrar yazılır, böylece bütün katsayılar işleme girer. Sağa doğru inen üç köşegenin çarpımları artı, sola doğru inen üç köşegenin çarpımları eksi işaretle toplanır:

$$D = a_1 b_2 c_3 + b_1 c_2 a_3 + c_1 a_2 b_3 - a_3 b_2 c_1 - b_3 c_2 a_1 - c_3 a_2 b_1$$

**Soru:** Determinantı daha önce öğrendiğimiz başka yöntemlerle (alta yazma, bir satırı sıfırlama) alsak sorun olur mu? **Cevap:** Olmaz. Hoca kendisine en kolay gelen yöntemi sunduğunu, sıfırlama yönteminde kendisinin de karıştırabildiğini söyler. Doğru sonuca ulaşıldıktan sonra istenen yöntem kullanılabilir.

**Soru:** Geçen hafta Y-Delta (yıldız-üçgen) dönüşümü atlanmadı mı? **Cevap:** Atlandı, bilerek sona bırakıldı. Önce düğüm ve çevre analizi bitirilecek, çünkü Y-Delta dönüşümünün düğüm analizini nasıl kolaylaştırdığı bu konulardan sonra anlatılacak.

Bu ön bilginin amacı şudur: düğüm ve çevre analizinde KCL ve KVL ile olabildiğince çok denklem çıkarılacak; dört denklem ve dört bilinmeyen olduğunda matris biçiminde çözmek çok daha kolaydır.

## 3. Düğüm Gerilimleri Analizi (Nodal Analysis)

### 3.1 Düğüm nedir?

Düğüm (node), iki devre elemanının arasında oluşan birleşme noktasıdır. Hoca örnek devrede (ekrandan, 00:24:09) noktaları $n_1$, $n_2$, $n_3$ diye işaretler. Arada hiçbir devre elemanı olmayan iletkenle birbirine bağlı noktalar (örnekte $R_3$, $R_5$ ve $R_6$'nın alt uçlarının birleştiği hat) tek ve ortak bir düğüm gibi davranır, denklemler buna göre yazılır. Direnç, gerilim kaynağı ya da akım kaynağı fark etmeksizin iki eleman arasında bir eleman varsa, orada ayrı düğümler vardır.

### 3.2 Adım adım düğüm analizi

**Adım 1: Referans düğümü seç.** Düğüm gerilimleri bu referansa göre yazılır. Genellikle alt kısımdaki ortak düğüm seçilir ve 0 V (toprak, GND) kabul edilir. Neden gerekli? Örnek devrede $V_{in}$ kaynağı $n_1$ düğümü ile alttaki düğüm arasındadır. Alt düğüm 0 alınırsa $n_1$ düğümünün gerilimi doğrudan $V_{in}$ olur. Alt düğüme 0 değil de $X$ denseydi, $n_1$ için $X + V_{in}$ yazmak gerekirdi. Referans seçmek değişken sayısını azaltır.

**Adım 2: Düğümlere gerilim etiketi ver.** Referans dışındaki düğümler $V_1, V_2, V_3, V_4, V_5$ diye adlandırılır. Amaç bu düğüm gerilimlerini bulmaktır.

**Adım 3: Akımlara ad ve yön ver.** Her elemandan geçen akım adlandırılır ve bir yön tayin edilir (ekrandan, 00:29:09). Örnekte $I_1$ kaynaktan yukarı, $I_2$ sağa akar; $V_3$ düğümünde akım $I_3$ ve $I_4$ diye ayrılır, $I_5$ ile devam edip $I_6$ olarak birleşir, $I_7$ kaynağa döner. Bu yönler ilk başta bir varsayımdır. Örneğin $I_1$'i yukarı aldıktan sonra $I_2$'yi ona ters yönde tanımlamak anlamsızdır. Hesap sonunda $I_2$ eksi çıkarsa, seri bağlı oldukları için $I_1$, $I_6$ ve $I_7$ de eksi çıkar ve bu yalnızca gerçek yönün kabul edilenin tersi olduğunu gösterir. Kabul edilen yönler akımın tek bir yönde aktığı düşünülerek tutarlı seçilmelidir.

**Adım 4: KCL denklemlerini yaz.** Örnek devre için (ekrandan, 00:29:09):

$$I_7 = I_1 = I_2 = I_6, \qquad I_2 = I_3 + I_4, \qquad I_4 = I_5$$

İlk eşitlik seri elemanlarda akımın her yerde aynı olmasından gelir. Hoca burada sınavlarda sık görülen bir hatayı sorar: $I_3$, $I_4$ ve $I_5$'e eşit midir? Bir öğrenci "dirence göre değişir" der. Hoca $I_3 = I_4 = I_5$ yazılamayacağını vurgular. Bazı öğrenciler $V_3$-$V_5$ arasındaki bölgeyi bir loop gibi görüp bu hatayı yapar. Doğrusu, $V_3$ düğümünde akım ayrıldığı için $I_2 = I_3 + I_4$, $R_4$ ile $R_5$ seri olduğu için de $I_4 = I_5$ yazmaktır. Olabildiğince çok KCL denklemi yazmak esastır, çünkü bu eşitlikler sonraki adımda kullanılacaktır.

**Adım 5: Ohm yasasıyla akımları düğüm gerilimleri cinsinden yaz.** Ohm yasasına göre $I = V/R$'dir; bir dirençten geçen akımı bulmak için üzerindeki gerilim $V_R$ bilinmelidir. Akım her zaman potansiyelin yüksek olduğu yerden düşük olduğu yere, yani artıdan eksiye akar (akım, elektron hareketinin tersidir). Bu yüzden akım $a$ noktasından $b$ noktasına doğru kabul edildiyse:

$$V_R = V_a - V_b, \qquad I = \frac{V_a - V_b}{R}$$

Hoca sınıfa sorar: $V_R$ için $V_a - V_b$ yazabilir miyiz? $V_b - V_a$ yazabilir miyiz? İkisi aynı mıdır? Aynı değildir. Akım yönü soldan sağa kabul edildiyse $V_a > V_b$ kabul edilmiş demektir ve denklem $V_a - V_b$ ile yazılmalıdır. Akım ters kabul edilseydi $I = (V_b - V_a)/R$ olurdu.

> **Hocanın vurgusu:** Kabul ettiğiniz akım yönü neyse bütün devre analizinde denklemi ona göre yazın. Bir dirence $V_b - V_a$, ötekine yönü farklı alıp başka türlü yazarsanız bütün hesap yanlış yere gider. İşaretler bu yüzden önemlidir.

Örnek devre için:

$$I_1 = \frac{V_1 - V_2}{R_1}, \quad I_2 = \frac{V_2 - V_3}{R_2}, \quad I_3 = \frac{V_3 - V_5}{R_3}, \quad I_4 = \frac{V_3 - V_4}{R_4}, \quad I_5 = \frac{V_4 - V_5}{R_5}$$

**Adım 6: Düğüm gerilimlerini çöz.** Bu devrede $V_1$ zaten bilinir: kaynak $V_1$ ile referans arasında doğrudan bağlı olduğundan $V_1 - 0 = V_{in}$, yani $V_1 = V_{in}$ (ekrandan, 00:39:09). Sonra KCL eşitlikleri gerilim cinsinden yazılır; örneğin $I_1 = I_2$ olduğu için $(V_1 - V_2)/R_1 = (V_2 - V_3)/R_2$. Bütün eşitlikler bu şekilde yazılıp (matris biçiminde) çözüldüğünde $V_2, V_3, V_4, V_5$ tek tek bulunur. Dirençlerin gerilimleri de düğüm gerilimlerinin farkından ($V_2 - V_3$ gibi) hesaplanır.

### 3.3 Example 01: sayısal örnek ve kontrol kuralları

Aynı devrenin değerleri (ekrandan, 00:44:09): $V_{in} = 10$ V, $R_1 = 9$ kΩ, $R_2 = 2$ kΩ, $R_3 = 5$ kΩ, $R_4 = 3$ kΩ, $R_5 = 1$ kΩ, $R_6 = 7$ kΩ. Buna göre $V_1 = 10$ V, $I_1 = (10 - V_2)/9$, $I_2 = (V_2 - V_3)/2$ (kΩ ve mA biriminde) yazılır ve eşitliklere göre birbirine bağlanır.

Hoca sonucu kontrol etmek için iki kural verir:

- Devreyi besleyen gerilimden daha büyük bir gerilim hiçbir düğümde birikmez. Burada $V_1 = 10$ V en büyük gerilimdir; dirençlerden geçtikçe her düğümde gerilim düşer.
- Hiçbir koldan ana kol akımından büyük bir akım geçemez.

> **Ek bilgi (derste anlatılmadı):** Bu iki kural, tek bağımsız kaynağı olan ve yalnız dirençlerden oluşan devreler için geçerlidir. Birden çok kaynak ya da bağımlı kaynak bulunan devrelerde bir düğümün gerilimi tek bir kaynağın geriliminden büyük çıkabilir.

Ana kol akımı eşdeğer dirençle kontrol edilir. $R_4$ ile $R_5$ seridir: $3 + 1 = 4$ kΩ. Bu 4 kΩ, 5 kΩ ile paraleldir: $5 \parallel 4 = 20/9 \approx 2{,}22$ kΩ. Geri kalan dirençler seridir:

$$R_{\text{eş}} = 7 + [5 \parallel (1+3)] + 2 + 9 = 20{,}2 \text{ kΩ}$$

$$I_1 = \frac{10 \text{ V}}{20{,}2 \text{ kΩ}} \approx 495 \text{ µA}$$

Akım $V_3$ düğümünde 5 kΩ ve 4 kΩ'luk kollara dirençlerle ters orantılı olarak bölünür: 5 kΩ'luk kola $4/9$'u, 4 kΩ'luk kola $5/9$'u gider. Slayttaki tablo (ekrandan, 00:44:09) $I_1 = I_2 = I_6 = I_7 = 495$ µA, $I_3 = 220$ µA, $I_4 = I_5 = 275$ µA verir. Python ile kontrol: $494{,}5 \cdot 4/9 \approx 219{,}8$, $494{,}5 \cdot 5/9 \approx 274{,}7$; değerler uyuşur.

> **Hocanın vurgusu:** Düğüm analizi zor bir konu değildir. Ama denklemlerin işaretinde yapılan bir hata soruyu tamamen götürür. Bu yüzden düğümleri ve akım yönlerini iyi belirlemek gerekir.

Hoca adımları bir kez daha sıralar: referans (GND) düğümü seç; her düğüme gerilim etiketi ver; her elemandan geçen akıma etiket ver; KCL'ye göre birkaç denklem yaz; Ohm yasasıyla akımları gerilim cinsinden göster; bu denklemleri çöz.

## 4. Example 02: İki Akım Kaynaklı Devre

Soru (ekrandan, 00:49:09): 15 Ω'luk dirençten soldan sağa geçen akımı bulun. Devrede solda yukarı yönlü 2 A akım kaynağı, onun yanında seri 7 Ω ve 3 Ω'luk bir kol, üstte iki düğümü bağlayan 15 Ω, sağda 5 Ω ve yukarı yönlü 4 A akım kaynağı vardır; alt düğüm referanstır.

Sol üst düğüm $V_1$, sağ üst düğüm $V_2$ olsun. Sol düğümde 2 A girer; $I_1$ 7+3 Ω'luk koldan aşağı, $I_2$ 15 Ω'dan sağa çıkar:

$$2 = I_1 + I_2$$

Sağ düğümde 4 A ve $I_2$ girer, $I_3$ 5 Ω'dan aşağı çıkar:

$$4 + I_2 = I_3$$

Ohm yasasıyla (7 Ω + 3 Ω seri = 10 Ω):

$$I_1 = \frac{V_1 - 0}{10}, \qquad I_2 = \frac{V_1 - V_2}{15}, \qquad I_3 = \frac{V_2 - 0}{5}$$

Yerine yazınca:

$$2 = \frac{V_1}{10} + \frac{V_1 - V_2}{15}, \qquad 4 = \frac{V_2}{5} - \frac{V_1 - V_2}{15}$$

Birinci denklem 30 ile çarpılır: $60 = 3V_1 + 2V_1 - 2V_2$, yani $5V_1 - 2V_2 = 60$. İkinci denklem 15 ile çarpılır: $60 = 3V_2 - V_1 + V_2$, yani $-V_1 + 4V_2 = 60$. Matris biçimi:

$$\begin{bmatrix} 5 & -2 \\ -1 & 4 \end{bmatrix} \begin{bmatrix} V_1 \\ V_2 \end{bmatrix} = \begin{bmatrix} 60 \\ 60 \end{bmatrix}$$

Yerine koyma ile: birinci denklem 2 ile çarpılıp ikinciyle toplanırsa $10V_1 - 4V_2 - V_1 + 4V_2 = 120 + 60$, yani $9V_1 = 180$, $V_1 = 20$ V. İkinci denklemden $4V_2 = 80$, $V_2 = 20$ V.

Determinant ile: $D = 5 \cdot 4 - (-2)(-1) = 20 - 2 = 18$. $D_{V_1} = 60 \cdot 4 - (-2) \cdot 60 = 240 + 120 = 360$. $V_1 = 360/18 = 20$ V. Aynı sonuç çıkar.

15 Ω'dan geçen akım $I_2 = (20 - 20)/15 = 0$'dır. İki uç aynı gerilimde olduğu için bu dirençten akım geçmez.

## 5. Süper Düğüm (Supernode)

### 5.1 Sorun: toprağa bağlı olmayan gerilim kaynağı

Hoca bir devre gösterir (ekrandan, 00:59:09): alt düğüm referans, sağda $V_1$ kaynağı referans ile $a$ düğümü arasında, solda $R_3$ referans ile $b$ düğümü arasında, $a$ ile $b$ arasında $R_2$, $b$ ile $c$ arasında $V_2$ kaynağı, $c$ ile $a$ arasında $R_1$ vardır. Uçlarından hiçbiri toprak düğümüne bağlı olmayan gerilim kaynağına **floating voltage source** (yüzen gerilim kaynağı) denir; burada $V_2$ floating'dir ve düğüm analizi için bir sorundur.

$v_a = V_1$ doğrudan yazılır. $b$ düğümünde KCL yazılmak istendiğinde $i_{R_2} + i_{R_3} + i_{V_2} = 0$ olur. $i_{R_2} = (v_a - v_b)/R_2$ yazılabilir. $R_3$'ten geçen akım düğüme giriyormuş gibi kabul edildiği için $(0 - v_b)/R_3 = -v_b/R_3$ yazılır; $(v_b - 0)/R_3$ yazmak akımın düğümden çıktığını kabul etmek olurdu. Hoca ikisinin aslında aynı şey olduğunu, ama işarete dikkat etmek gerektiğini söyler. Böylece:

$$\frac{v_a - v_b}{R_2} - \frac{v_b}{R_3} + i_{V_2} = 0$$

Sorun $i_{V_2}$'dedir: $b$ ile $c$ arasında direnç yoktur, bir akım kaynağı da yoktur. Kaynağın akımını yazacak bir bağıntı bulunmaz. Oysa bu kaynak $c$ ve $b$ düğümlerinin gerilimine katkı yapar.

### 5.2 Çözüm: düğümleri birleştirme

Kural şudur: iki düğüm arasında yalnızca bir gerilim kaynağı varsa, bu iki düğüme ayrı değişken adları verilmez. Biri, diğerinin gerilimi artı kaynak gerilimi olarak yazılır:

$$v_c = v_b + V_2 \quad \text{(ya da } v_b = v_c - V_2\text{)}$$

$c$ için ayrı bir değişken tanımlamak, o düğüm için akım denklemi kurulamayacağından çözümü imkânsız kılar. Bunun yerine $R_1$'den geçen akım (seri hat olduğu için kaynağın akımına eşittir) yazılır:

$$i_{R_1} = \frac{V_1 - (v_b + V_2)}{R_1}$$

Böylece $V_2$ denkleme girmiş olur ve son denklemde yalnız $v_b$ bilinmeyeni kalır. $V_1$ ve $V_2$ soruda verilmiş olacağından (örneğin 5 V ve 3 V) $v_b$ doğrudan bulunur. Düğümleri bu şekilde birleştirmeye **süper düğüm** denir.

> **Hocanın vurgusu:** Süper düğüm önemli bir konudur.

Slayttaki analiz adımları (ekrandan, 01:04:09):

- (1) Bir referans düğümü seç (genelde toprak ya da alttaki düğüm), gerilimini sıfır al.
- (2) Referans dışındaki her düğüme bir gerilim değişkeni ver ($v_1, v_2, \dots, v_{N-1}$).
- (3) Bağımsız ve bağımlı gerilim kaynakları için süper düğümü belirle, süper düğümün gerilimini düğüm gerilimleri cinsinden yaz. Süper düğüm dahil $N-1$ düğümün hepsinde KCL yaz (referansta ve referansı içeren süper düğümde yazma).
- (4) $N-1$ düğüm denklemini ve kaynak denklemlerini birlikte çöz.

Slayttaki tanım: süper düğüm, gerilim kaynaklarıyla ayrılmış birden çok düğümün oluşturduğu topluluktur.

## 6. Sınıf Alıştırması: İki Süper Düğümlü Devre

Hoca slayttaki devreyi (ekrandan, 01:04:09) öğrencilere 10-15 dakikalık bir alıştırma olarak verir. Devre: sol kolda alt ucu referansa bağlı 4 V kaynak (eksi ucu yukarıda, artı ucu aşağıda); sol üst düğümden sağa 6 Ω; ardından bir düğüm, bu düğümden referansa 12 Ω; bu düğümle sağdaki düğüm arasında 8 V kaynak (artı ucu solda, eksi ucu sağda); sağ düğümden referansa 12 Ω; en sağda referanstan bu düğüme doğru yukarı yönlü 2 A akım kaynağı. Slaytta 4 V'luk kaynağın çevresi ve 8 V'luk kaynağın iki yanındaki düğümler "supernode" diye işaretlidir.

**Soru:** Devrede hiçbir yer toprağa bağlı görünmüyor; seçtiğimiz referans noktası mı sıfır oluyor? **Cevap:** Evet. Burada en mantıklı referans alttaki ortak hattır; bu seçim dört düğümde birden denklem yazarken sıfırı kolayca kullanmayı sağlar. Soruda belirli bir akım istenmediği için düğüm gerilimlerini bulmak yeterlidir.

### 6.1 Bir hata örneği

İlk deneyen öğrencinin denkleminde 6 Ω'luk dirençten geçen akım $V_A/6$ diye yazılmıştı. Hoca 6 Ω'un iki ucundaki gerilimlerin yazılması gerektiğini gösterir: bir uç $V_A + 8$, diğer uç $-4$ V olduğuna göre akım, kabul edilen yöne göre $\big((V_A + 8) - (-4)\big)/6$ ya da ters yönde $\big(-4 - (V_A + 8)\big)/6$ olmalıdır. Kabul edilen yön ile yazılan ifade birbirini tutmalıdır.

### 6.2 Doğru çözüm

İkinci öğrencinin çözümü (ekrandan, 01:24:09):

- Alt hat referans (0 V). Sol üst düğüm, 4 V kaynak ters bağlı olduğu için $-4$ V'tur.
- Sağdaki düğüm $V_1$, 8 V kaynağın solundaki düğüm $V_1 + 8$ olarak yazılır (süper düğüm).
- Akımlar: $I_4$, $V_1+8$ düğümünden 6 Ω üzerinden $-4$ V düğümüne; $I_3$, sol 12 Ω'dan yukarı; $I_2$, sağ 12 Ω'dan yukarı; $I_1$, 8 V kaynaktan sola doğru.

KCL: sağ düğümde $I_1 = I_2 + 2$; sol düğümde $I_4 = I_1 + I_3$. Öğrenci önce $I_3$'ü aşağı yönlü düşünüp karıştırmış, hoca $I_3$ yukarı kabul edilirse ifadenin $(0 - (V_1 + 8))/12$ olması gerektiğini belirtmiştir. İkisi birleştirilince:

$$I_4 = I_2 + I_3 + 2$$

Ohm yasasıyla:

$$I_4 = \frac{(V_1 + 8) - (-4)}{6} = \frac{V_1 + 12}{6}, \qquad I_3 = \frac{-V_1 - 8}{12}, \qquad I_2 = \frac{-V_1}{12}$$

Yerine yazıp 12 ile çarpınca:

$$2V_1 + 24 = -V_1 - V_1 - 8 + 24 \;\Rightarrow\; 4V_1 = -8 \;\Rightarrow\; V_1 = -2 \text{ V}$$

Buna göre sağ düğüm $-2$ V, 8 V kaynağın solundaki düğüm $-2 + 8 = 6$ V'tur. Python ile kontrol (ara adım eklendi): 6 Ω'dan çıkan akım $10/6 \approx 1{,}667$ A, sol 12 Ω'dan aşağı $6/12 = 0{,}5$ A, sağ 12 Ω'dan aşağı $-2/12 \approx -0{,}167$ A; toplam $2$ A, akım kaynağının verdiği 2 A'e eşittir.

**Soru:** Sol üstteki düğüm neden $+4$ değil de $-4$? **Cevap:** Devrelerde akımın kaynağın artı ucundan çıktığı düşünülür. Burada kaynak ters bağlıdır: artı ucu referansa (0 V), eksi ucu üst düğüme bağlıdır. Ölçülen uç artı ile sıfır arasında kaldığı için üst düğüm $-4$ V olur.

**Soru:** Sol taraftaki 4 V'luk kısım neden süper düğüm sayılıyor? **Cevap:** Süper düğümden kastedilen, bir düğümün gerilimini ayrı bir değişkenle değil, başka bir düğümün bilgisiyle yazmaktır. Bu düğüme ayrı bir değişken verilmez, doğrudan $-4$ V yazılır. Önceki örnekte $v_a$ yerine $V_1$, $v_c$ yerine $v_b + V_2$ yazmak da aynı işlemdir; burada değişken yerine sayısal bir değer vardır.

## 7. Example 03: Bağımlı Kaynaklı Düğüm Analizi

Soru (ekrandan, 01:29:09): Devredeki düğüm-referans gerilimlerini bulun; düğümleri ve süper düğümleri belirleyin, referans dışındaki her düğümde KCL yazın.

Devre, ortasında referans düğümü bulunan bir eşkenar dörtgene benzer. Köşeler $v_1$ (sol), $v_2$ (üst), $v_3$ (sağ), $v_4$ (alt) düğümleridir. Elemanlar:

- $v_1$-$v_2$ arasında 0,5 Ω (üzerindeki gerilim $v_x$; artı ucu $v_2$ tarafında).
- Referanstan $v_2$'ye doğru 14 A akım kaynağı.
- $v_2$-$v_3$ arasında 2 Ω.
- $v_1$ ile referans arasında 12 V kaynak (eksi ucu $v_1$ tarafında).
- Referanstan $v_3$'e doğru $0{,}5 v_x$ bağımlı akım kaynağı.
- $v_1$-$v_4$ arasında 2,5 Ω (üzerindeki gerilim $v_y$; artı ucu $v_4$ tarafında).
- Referans ile $v_4$ arasında 1 Ω.
- $v_3$-$v_4$ arasında $0{,}2 v_y$ bağımlı gerilim kaynağı.

**$v_1$ düğümü:** Referansla arasında yalnız bir gerilim kaynağı vardır; akımla uğraşmadan gerilim doğrudan yazılır. Kaynak ters bağlı olduğu için $v_1 = -12$ V. Bu da bir süper düğüm yazımıdır.

**$v_2$ düğümü:** 14 A girer; 0,5 Ω ve 2 Ω'dan akımlar çıkar (ekrandan, 01:39:09):

$$14 = \frac{v_2 - v_1}{0{,}5} + \frac{v_2 - v_3}{2}$$

4 ile çarpılırsa $56 = 8v_2 - 8v_1 + 2v_2 - 2v_3$, 2'ye bölünürse $28 = 5v_2 - 4v_1 - v_3$, bir kez daha 2'ye bölünürse:

$$-2v_1 + 2{,}5v_2 - 0{,}5v_3 = 14$$

**$v_3$-$v_4$ süper düğümü:** $v_3$ ile $v_4$ arasında yalnız bağımlı gerilim kaynağı olduğu için bu iki düğüm süper düğüm olarak birlikte ele alınır. Bağımlı akım kaynağı süper düğüme girer; 2 Ω, 1 Ω ve 2,5 Ω'dan akımlar çıkar:

$$0{,}5 v_x = \frac{v_3 - v_2}{2} + \frac{v_4}{1} + \frac{v_4 - v_1}{2{,}5}$$

Hoca 2 Ω'daki akımı bu düğümde $v_3$'ten $v_2$'ye, $v_2$ düğümünde ise $v_2$'den $v_3$'e yazdığına dikkat çeker. Bu sorun değildir: her düğümün denklemi kendi içinde "giren = çıkan" kuralına uygun yazıldıysa, farklı bir düğümde ters yön almak yalnızca o akımın ters işaretle bulunmasına yol açar (birinde 5, ötekinde $-5$ gibi).

**Bağımlı kaynakları düğüm gerilimleriyle ifade etme** (ekrandan, 01:39:09):

$$0{,}5 v_x = 0{,}5(v_2 - v_1), \qquad v_3 - v_4 = 0{,}2 v_y, \qquad 0{,}2 v_y = 0{,}2(v_4 - v_1)$$

Süper düğüm bağıntısı düzenlenince:

$$v_3 = 0{,}2(v_4 - v_1) + v_4 = 1{,}2v_4 - 0{,}2v_1$$

Bu ifade, $v_3$ görülen yere yazılarak ya da $v_4$ yalnız bırakılıp $v_4$ görülen yere yazılarak değişken sayısını azaltmak için kullanılır. İkisi de aynı sonuca götürür.

**Soru:** $0{,}5 v_x$'i bulurken $v_3 - v_4$ kısmı karıştı; $v_4$'ü taşıyıp kollara bölmeyi tekrar anlatır mısınız? **Cevap:** Amaç $v_4$ düğümünü $v_3$ değişkeniyle yazmaktır (ya da tersi). $v_4$ yalnız başına düşünülürse çıkan akımlar $(v_4 - v_1)/2{,}5$ ve $v_4/1$'dir. Soru, iki düğüm arasındaki kaynağın bu iki gerilimin farkına eşit olduğunu söyler: $v_3 - v_4 = 0{,}2v_y$, $v_y = v_4 - v_1$. Bu bağıntıdan biri çekilip diğerinin yerine yazılır; geriye denklem çözmek kalır.

Slayttaki son denklem sistemi (ekrandan, 01:39:09):

$$\begin{aligned} -2v_1 + 2{,}5v_2 - 0{,}5v_3 &= 14 \\ 0{,}1v_1 - v_2 + 0{,}5v_3 + 1{,}4v_4 &= 0 \\ v_1 &= -12 \\ 0{,}2v_1 + v_3 - 1{,}2v_4 &= 0 \end{aligned}$$

$v_1$ bilindiği için sistem üç bilinmeyene iner ve matris biçiminde çözülebilir. Sonuç derste söylenmedi; python ile çözüm: $v_1 = -12$ V, $v_2 = -4$ V, $v_3 = 0$ V, $v_4 = -2$ V. Bu değerler $v_2$ düğümü denklemini ($(-4+12)/0{,}5 + (-4-0)/2 = 16 - 2 = 14$) ve süper düğüm bağıntısını ($0 - (-2) = 0{,}2 \cdot (-2+12) = 2$) sağlar.

> **Hocanın vurgusu:** Bu soruyu evde baştan çözün. İstenen her şey içinde var: bağımlı akım kaynağı, bağımlı gerilim kaynağı, süper düğüm ve direnç gerilimine bağlı kaynaklar. Buna benzer sorular sorulabilir.

## 8. Çevre Akımları Analizi (Mesh Analysis)

### 8.1 Adımlar

Çevre analizinde KVL, yani elemanların üzerindeki gerilim düşümleri ve Ohm yasası üzerinden akım hesabı yapılır. Slayttaki adımlar (ekrandan, 01:59:09):

- Devredeki bütün çevreleri (mesh) belirle.
- Her çevrede akan akımı adlandır.
- Her elemanın üzerindeki gerilimi etiketle.
- KVL kullan.

Çevre akımlarının yönü bütün çevrelerde aynı seçilmelidir. Örneğin bir çevrede saat yönü alındıysa öteki çevrelerde de saat yönü alınır. Bu kural kesinlikle bozulmaz.

Örnek devre düğüm analizindeki devrenin aynısıdır: büyük çevrede $i_1$ ($V_{in}$, $R_1$, $R_2$, $R_3$, $R_6$), küçük çevrede $i_2$ ($R_3$, $R_4$, $R_5$). Büyük çevre için KVL: kaynak bu akıma göre üreteç olduğu için eksi, dirençler artı-eksi kutuplandığı için artı yazılır:

$$-V_{in} + V_1 + V_2 + V_3 + V_6 = 0$$

Küçük çevre de aynı yönde (saat yönü) alınır. Bu çevreye göre $R_3$'te akım, büyük çevrede verilen kutbun artı ucundan çıkar; yani $R_3$ bu çevre için bir üreteç gibi görünür ve eksi işaretle girer:

$$-V_3 + V_4 + V_5 = 0$$

Ohm yasasıyla gerilimler akım cinsinden yazılır: $V_1 = i_1 R_1$, $V_2 = i_1 R_2$; iki çevrenin ortak elemanı $R_3$ için akım farkı kullanılır:

$$V_3 = (i_1 - i_2)R_3$$

İkinci çevrede $-V_3$ yerine $R_3(i_2 - i_1)$ de yazılabilir.

### 8.2 Sayısal örnek

Aynı devrenin değerleri (ekrandan, 02:04:09): kaynak 12 V; $V_1 = i_1(4\text{ kΩ})$, $V_2 = i_1(8\text{ kΩ})$, $V_3 = (i_1 - i_2)(5\text{ kΩ})$, $V_4 = i_2(6\text{ kΩ})$, $V_5 = i_2(3\text{ kΩ})$, $V_6 = i_1(1\text{ kΩ})$. Birinci çevre (kΩ ve mA biriminde):

$$-12 + 4i_1 + 8i_1 + 5(i_1 - i_2) + 1\,i_1 = 0$$

İkinci çevre için $-V_3$'ü yazmanın iki doğru yolu vardır: $-5(i_1 - i_2)$ ya da $5(i_2 - i_1)$. Hoca sınavda sık karıştırılan yanlış biçimi de gösterir: $-5(i_2 - i_1)$ yazmak yanlıştır, çünkü bu hem işareti hem farkın sırasını değiştirip ifadeyi ilk hâline döndürür.

**Soru:** Son yazdığınız $5(i_2 - i_1)$ doğru değil miydi, az önce yanlış dediniz? **Cevap:** Hoca düzeltir: $5(i_2 - i_1)$ doğrudur; başında eksi olan $-5(i_2 - i_1)$ yanlıştır. Eksi yazılacaksa ilk kabul edilen akım farkıyla $-5(i_1 - i_2)$ yazılır. Eksiden kurtulmak istenirse fark ters çevrilip $5(i_2 - i_1)$ yazılır. İkinci çevreye göre bu elemanın kutbu ters olduğu için ikisi aynı şeydir.

İki denklem çözüldüğünde $i_1$ ve $i_2$ bulunur. Bu örnekte sonuç derste hesaplanmadı (ara adım eklendi): ikinci çevre $-5(i_1 - i_2) + 6i_2 + 3i_2 = 0$ olduğundan sistem $18i_1 - 5i_2 = 12$, $-5i_1 + 14i_2 = 0$ olur; python ile $i_1 = 168/227 \approx 0{,}740$ mA, $i_2 = 60/227 \approx 0{,}264$ mA.

Sonra her direncin gerilimi Ohm yasasıyla bulunur; yalnız $R_3$ için $i_1 - i_2$ kullanılır. Bir değer negatif çıkarsa akımın kabul edilen saat yönünün tersine aktığı söylenir. Kontrol için: paralel kollardaki gerilimler aynı olmalı, gerilimler toplandığında ana koldaki gerilim elde edilmeli (çok küçük yuvarlama farkları olabilir) ve hiçbir koldan ana kol akımından büyük akım geçmemelidir.

Hocanın özeti: çevre analizinin adımları düğüm analizine çok benzer; KCL yerine KVL'den gidilir ve gerilimler akım cinsinden yazılır. Önce çevreler belirlenir, sonra akım yönleri tanımlanır, denklemler bu yöne göre çıkarılır.

## 9. Example 05 ve Example 06: Çevre Analizi Örnekleri

### 9.1 Example 05

Soru (ekrandan, 02:09:09): Çevre akımları $i_1$ ve $i_2$'yi bulun. Devre: solda 42 V kaynak (artı ucu yukarıda), üstte 6 Ω, ortada 3 Ω, üstte sağda 4 Ω, sağda 10 V kaynak (eksi ucu yukarıda). İki çevre de saat yönünde.

Birinci çevre: $-42 + 6i_1 + 3(i_1 - i_2) = 0$. İkinci çevrede 3 Ω artık bu çevreye göre üreteç konumundadır; $-3(i_1 - i_2)$ ya da $3(i_2 - i_1)$ yazılır: $3(i_2 - i_1) + 4i_2 - 10 = 0$. Düzenlenince (ekrandan, 02:09:09):

$$9i_1 - 3i_2 = 42, \qquad -3i_1 + 7i_2 = 10$$

$$D = 9 \cdot 7 - (-3)(-3) = 63 - 9 = 54$$

$$i_1 = \frac{42 \cdot 7 - (-3) \cdot 10}{54} = \frac{324}{54} = 6 \text{ A}, \qquad i_2 = \frac{9 \cdot 10 - (-3) \cdot 42}{54} = \frac{216}{54} = 4 \text{ A}$$

3 Ω'luk direncin gerilimi sorulursa: $3 \cdot (6 - 4) = 6$ V. Bu gerilim, birinci çevrenin kutuplamasına göre yukarıdan aşağı akan akımla oluşan bir 6 V'tur (python ile doğrulandı).

### 9.2 Example 06 (sınıf alıştırması)

Soru (ekrandan, 02:19:09): 2 V'luk kaynağın verdiği gücü bulun. Devre: solda 5 V kaynak (artı ucu yukarıda), üstte 4 Ω ve 5 Ω, orta kolda 2 Ω ve altında 2 V kaynak (eksi ucu yukarıda, artı ucu aşağıda), sağda 1 V kaynak (artı ucu yukarıda). İki çevre de saat yönünde.

Hoca bu soruyu öğrencilere yaptırır; bir öğrenci çözümü tahtada yazar. Hoca ortak koldaki işaret karışıklığını tartıştıktan sonra denklemleri birlikte kurar (ekrandan, 02:19:09):

$$\text{Çevre 1:} \quad -5 + 4i_1 + 2(i_1 - i_2) - 2 = 0$$

$$\text{Çevre 2:} \quad +2 + 2(i_2 - i_1) + 5i_2 + 1 = 0$$

Birinci çevrede 5 V ve 2 V kaynaklar akım yönüne ters kutuplandığı için eksi gelir. İkinci çevrede aynı yön korunur; bu kez 2 V kaynağa akım artı ucundan girdiği için $+2$, 1 V kaynağa da artı ucundan girdiği için $+1$ yazılır. Ortak 2 Ω için ikinci çevrede $2(i_2 - i_1)$ ya da $-2(i_1 - i_2)$ yazılabilir.

**Soru:** İkinci çevrede ben $+2(i_2 - i_1)$ değil, $-2(i_2 - i_1)$ buldum; neden? **Cevap:** Birinci çevre ilk yazıldığı ve kutuplama ona göre yapıldığı için 2 Ω, birinci çevrede $2(i_1 - i_2)$ olur. İkinci çevrede kutuplama bozulmaz, aynı akım kabulüyle devam edilir; 2 Ω bu çevreye göre üreteç konumundadır. Bu yüzden $-2(i_1 - i_2)$ ya da $2(i_2 - i_1)$ yazılır; eksiyi dağıtınca ikisi aynıdır.

Düzenlenince:

$$6i_1 - 2i_2 = 7, \qquad -2i_1 + 7i_2 = -3$$

$$D = 42 - 4 = 38, \qquad i_1 = \frac{49 - 6}{38} = \frac{43}{38} \approx 1{,}132 \text{ A}, \qquad i_2 = \frac{-18 + 14}{38} = -\frac{2}{19} \approx -0{,}1053 \text{ A}$$

$i_2$'nin eksi çıkması, ikinci çevre akımının gerçekte saat yönünün tersine aktığını söyler. 2 V kaynağın bulunduğu orta koldan geçen akım, iki çevre akımının farkıdır: $i_1 - i_2 = 43/38 + 4/38 = 47/38 \approx 1{,}237$ A (aşağı doğru). Hoca bunu "1,13 ile 0,10'u toplayıp" diye anlatır.

Bu akım kaynağa eksi ucundan girip artı ucundan çıktığı için kaynak bir üreteçtir. Gücü:

$$P = 2 \text{ V} \times 1{,}237 \text{ A} \approx 2{,}47 \text{ W}$$

Kaynağın verdiği güç yaklaşık 2,47 W, soğurduğu güç ise $-2{,}47$ W'tır (python ile doğrulandı).

> **Ders sonrası not:** Hoca sonucu "eksi 2,47 volt gibi bir supply" diye söyledi; gücün birimi watt'tır. Ayrıca orta koldaki akım anlatımda "1,200 gibi" diye yuvarlandı; tam değeri $47/38 \approx 1{,}237$ A'dir.

**Soru:** 2 Ω'luk direncin artı ve eksi kutbunu yazabilir misiniz? İkinci çevrede de aynı mı? **Cevap:** Kutuplar ilk atamaya, yani birinci çevreye göre konur. İkinci çevre yazılırken bu kabul bozulmaz. Sonuçta ikinci çevre akımı eksi çıktıysa bu, akımın gerçek yönünün ters olduğunu gösterir; kutup aynı kalır.

> **Hocanın vurgusu:** Ortak elemanlardaki çevre analizi biraz kafa karıştırır. Ama sakin ve yavaş yavaş yapılırsa çok da zor değildir.

## 10. Süper Çevre (Supermesh)

### 10.1 Fikir

Süper düğümdeki sorun, iki düğüm arasında yalnız bir gerilim kaynağı olduğunda kaynağın akımının yazılamamasıydı; çözüm, bir düğümü diğerinin gerilimi artı kaynak gerilimi olarak yazmaktı. Süper çevrede aynı durum akım kaynağı için ortaya çıkar. Çevre analizinde gerilimler akım cinsinden yazılır (direnç için $iR$ gibi). Ama bir akım kaynağının üzerindeki gerilim bu şekilde yazılamaz, dolayısıyla KVL denklemine konamaz.

Özetle: gerilim kaynağı düğüm analizi için sorundur (çözüm süper düğüm), akım kaynağı çevre analizi için sorundur (çözüm süper çevre).

Slayttaki açıklama (ekrandan, 02:24:09): I. ve II. çevrenin ikisi de akım kaynağından geçiyorsa, çevrelerden biri bırakılıp yerine iki çevrenin çevresinden dolaşan loop (III) alınabilir. Sonra denklem sistemi normal çevre analizindeki gibi çözülür.

### 10.2 Example 07

Soru (ekrandan, 02:29:09): Devrede gösterilen $i$ akımını bulun. Devre: solda 7 V kaynak; orta dikey kolda yukarıdan aşağı 1 Ω, 7 A akım kaynağı (aşağı yönlü) ve 2 Ω; sağ dikey kolda yukarıdan aşağı 2 Ω ve 1 Ω; ortadaki düğüm ile sağ kolun ortası arasında 3 Ω. Üç çevre vardır: $i_1$ (sol, 7 V kaynaklı), $i_2$ (sağ üst: 1 Ω, 2 Ω, 3 Ω), $i_3$ (sağ alt: 3 Ω, 1 Ω, 2 Ω ve akım kaynağı).

<!-- BELİRSİZ: Slayttaki $i$ okunun hangi kola ait olduğu karede tam seçilemiyor ve derste söylenmedi; ok 7 A kaynağın sağında, 3 Ω'un altında sağa doğru çizilmiş. -->

7 A kaynak $i_1$ ve $i_3$ çevrelerinin ortak kolundadır. Bu yüzden 1. ve 3. çevre tek bir süper çevre olarak yazılır, akım kaynağı (ve onunla seri 2 Ω) dışarıda kalır. Süper çevrenin KVL denklemi (ekrandan, 02:29:09):

$$-7 + 1(i_1 - i_2) + 3(i_3 - i_2) + 1\,i_3 = 0$$

Hoca işaretleri şöyle açıklar: 1 Ω'daki kutuplama $i_1 > i_2$ olduğu senaryoya göre yapıldığı için $i_1 - i_2$, 3 Ω'daki kutuplama $i_3 > i_2$ senaryosuna göre yapıldığı için $i_3 - i_2$ yazılır. Bu denkleme 7 A'lik kaynak henüz hiç katılmamıştır.

İkinci çevrede 1 Ω artık üreteç konumundadır. $i_2$ öne alınarak $1(i_2 - i_1)$ yazılır ve eksi işarete gerek kalmaz; 3 Ω için de aynı şekilde $3(i_2 - i_3)$:

$$1(i_2 - i_1) + 2i_2 + 3(i_2 - i_3) = 0 \;\Rightarrow\; -i_1 + 6i_2 - 3i_3 = 0$$

Bu iki denklemde üç bilinmeyen vardır. Eksik denklemi akım kaynağı verir: kaynak $i_1$ ile $i_3$'ün ortak kolunda olduğu için

$$i_1 - i_3 = 7 \text{ A}$$

$i_1$ büyük alındığı için $+7$ yazılır; $i_3 - i_1$ yazılsaydı $-7$ A olurdu. Bu bağıntıyla $i_1$ yerine $7 + i_3$ yazılarak iki bilinmeyenli bir sisteme inilir. Slayttaki sonuç: $i_1 = 9$ A, $i_2 = 2{,}5$ A. Buradan $i_3 = i_1 - 7 = 2$ A (ara adım eklendi). Python ile kontrol: süper çevre $-7 + 6{,}5 - 1{,}5 + 2 = 0$, çevre 2 $-9 + 15 - 6 = 0$.

> **Hocanın vurgusu:** Kritik nokta, verilen akım kaynağının tanımlanan çevre akımları ($i_1$, $i_3$) için ek bir bağıntı olarak kullanılmasıdır. Bu kaynağın üzerinden geçen 7 A doğrudan KVL'ye yazılamaz, çünkü KCL'de olduğu gibi burada da bir dirençle kurulabilecek bir ifade yoktur.

## 11. Düzlemsel ve Düzlemsel Olmayan Devreler

Hoca son olarak düzlemsel (planar) devrelerden kısaca söz eder. Basamaklı, dirençli yapılarda yolları üst üste gelmeyecek biçimde (kesişmeden) çizilebilen devrelere düzlemsel devre denir. İlk bakışta karışık görünse de bir dönüşümle bu hâle getirilebilen devreler de düzlemseldir; bu dönüşüm, sonraki derslere bırakılan yıldız-üçgen (Y-Delta) direnç dönüşümüyle ilgilidir. Hiçbir şekilde kesişmesiz gösterilemeyen devrelere ise düzlemsel olmayan (non-planar) devre denir.

> **Ek bilgi (derste anlatılmadı):** Çevre (mesh) analizi yalnız düzlemsel devrelere uygulanabilir, çünkü "mesh" içinde başka çevre bulunmayan pencere demektir ve bu tanım devrenin düzlemde kesişmesiz çizilmesine dayanır. Düğüm analizi ise her devreye uygulanabilir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:28:43): Düğüm analizi örnek devresinde $V_3$ düğümünde ayrılan akımlar için $I_3 = I_4 = I_5$ yazılabilir mi?

> **Çözüm:** Yazılamaz. $V_3$ düğümünde akım ayrıldığı için KCL $I_2 = I_3 + I_4$ verir. $R_4$ ile $R_5$ seri olduğu için $I_4 = I_5$'tir. $I_3$ ile $I_4$ ise dirençlere göre değişir; Example 01'de $I_3 = 220$ µA, $I_4 = 275$ µA'dir.

**Soru 2** (derste sözlü, 00:31:13): Bir dirençte akım $a$'dan $b$'ye kabul edildiyse direnç gerilimi $V_a - V_b$ mi, $V_b - V_a$ mı yazılır? İkisi aynı mıdır?

> **Çözüm:** Akım yüksek potansiyelden düşüğe aktığı için $V_R = V_a - V_b$ ve $I = (V_a - V_b)/R$ yazılır. İkisi aynı değildir; birbirinin eksisidir. Hangi yön kabul edildiyse bütün denklemler o yöne göre yazılmalıdır.

**Soru 3** (ekrandan, 00:49:09): Example 02 devresinde (2 A ve 4 A akım kaynakları, 7 Ω + 3 Ω, 15 Ω, 5 Ω) 15 Ω'luk dirençten soldan sağa geçen akımı bulun.

> **Çözüm:** $5V_1 - 2V_2 = 60$, $-V_1 + 4V_2 = 60$; $D = 18$, $V_1 = 360/18 = 20$ V, $V_2 = 20$ V. 15 Ω'dan geçen akım $(20 - 20)/15 = 0$ A (python ile doğrulandı).

**Soru 4** (ekrandan, 01:04:09): 4 V kaynak (eksi ucu üstte), 6 Ω, iki adet 12 Ω, 8 V kaynak (artı ucu solda) ve 2 A akım kaynağından oluşan süper düğümlü devrede düğüm gerilimlerini bulun.

> **Çözüm:** Sol üst düğüm $-4$ V. Sağ düğüm $V_1$, 8 V kaynağın solundaki düğüm $V_1 + 8$. KCL: $\dfrac{V_1 + 12}{6} = \dfrac{-V_1}{12} + \dfrac{-V_1 - 8}{12} + 2$ ⇒ $4V_1 = -8$ ⇒ $V_1 = -2$ V; diğer düğüm $6$ V (derste bir öğrenci çözdü, hoca onayladı; python ile doğrulandı).

**Soru 5** (ekrandan, 01:29:09): Example 03 devresinde (0,5 Ω, 2 Ω, 2,5 Ω, 1 Ω, 14 A, 12 V, $0{,}5v_x$ bağımlı akım kaynağı, $0{,}2v_y$ bağımlı gerilim kaynağı) düğüm-referans gerilimlerini bulun.

> **Çözüm:** Denklemler derste kuruldu ve slaytta verildi: $-2v_1 + 2{,}5v_2 - 0{,}5v_3 = 14$; $0{,}1v_1 - v_2 + 0{,}5v_3 + 1{,}4v_4 = 0$; $v_1 = -12$; $0{,}2v_1 + v_3 - 1{,}2v_4 = 0$.

> **Çözüm (derste verilmedi):** Python ile: $v_1 = -12$ V, $v_2 = -4$ V, $v_3 = 0$ V, $v_4 = -2$ V.

**Soru 6** (ekrandan, 02:09:09): Example 05 devresinde (42 V, 6 Ω, 3 Ω, 4 Ω, 10 V) çevre akımları $i_1$ ve $i_2$'yi bulun.

> **Çözüm:** $9i_1 - 3i_2 = 42$, $-3i_1 + 7i_2 = 10$; $D = 54$, $i_1 = 6$ A, $i_2 = 4$ A. 3 Ω üzerindeki gerilim $3(6-4) = 6$ V.

**Soru 7** (ekrandan, 02:19:09): Example 06 devresinde (5 V, 4 Ω, 2 Ω, 2 V, 5 Ω, 1 V) 2 V'luk kaynağın verdiği gücü bulun.

> **Çözüm:** $6i_1 - 2i_2 = 7$, $-2i_1 + 7i_2 = -3$; $i_1 = 43/38 \approx 1{,}132$ A, $i_2 = -2/19 \approx -0{,}105$ A. Kaynaktan geçen akım $i_1 - i_2 \approx 1{,}237$ A; verilen güç $\approx 2{,}47$ W, soğurulan güç $\approx -2{,}47$ W.

**Soru 8** (ekrandan, 02:29:09): Example 07 devresinde (7 V, 7 A, 1 Ω, 2 Ω, 3 Ω, 2 Ω, 1 Ω) süper çevre yöntemiyle çevre akımlarını bulun.

> **Çözüm:** Süper çevre: $-7 + 1(i_1 - i_2) + 3(i_3 - i_2) + 1i_3 = 0$; çevre 2: $-i_1 + 6i_2 - 3i_3 = 0$; kaynak: $i_1 - i_3 = 7$. Slayttaki sonuç $i_1 = 9$ A, $i_2 = 2{,}5$ A; buradan $i_3 = 2$ A (python ile doğrulandı).

## Dersin Toparlaması

Bu derste, KCL, KVL ve Ohm yasasını sistematik biçimde kullanan iki analiz yöntemi görüldü. Düğüm analizinde bir referans düğümü seçilir, düğüm gerilimleri bilinmeyen olarak alınır, her düğümde KCL yazılır ve akımlar $(V_a - V_b)/R$ biçiminde gerilimlerle ifade edilir. Toprağa bağlı olmayan bir gerilim kaynağı varsa iki ucundaki düğümler süper düğüm olarak birleştirilir. Çevre analizinde ise bütün çevrelerde aynı yönde çevre akımları tanımlanır, her çevrede KVL yazılır ve ortak elemanlarda akım farkı kullanılır. İki çevrenin ortak kolunda akım kaynağı varsa süper çevre kurulur ve akım kaynağı ek bağıntı verir. Bu yöntemlerin ürettiği çok bilinmeyenli denklemler, yerine koyma ya da determinant (Cramer kuralı ve Sarrus yöntemi) ile çözülür. Her iki yöntemde de en sık hata, kabul edilen yöne uymayan işaretlerdir.

Hoca, yıldız-üçgen (Y-Delta) direnç dönüşümünün ve düzlemsel devreleri bu dönüşümle normal biçime getirmenin sonraki derste anlatılacağını, bu dersteki örneklerin de orada hızlıca tekrar edileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
