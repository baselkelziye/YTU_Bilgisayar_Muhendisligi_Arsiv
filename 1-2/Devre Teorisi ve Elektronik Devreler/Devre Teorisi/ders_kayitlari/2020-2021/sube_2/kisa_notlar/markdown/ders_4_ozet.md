# Ders 4 Çalışma Özeti

> Kayıt iki parçadır; arşivde parçalar yanlış sırada birleştirildiği için altyazıdaki sıra düzeltildi ve saat damgaları düzeltilmiş altyazıya göredir.

## Genel Konular

- Önceki dersin kısa tekrarı
  - Gerilim bölücü: seri dirençler gerilimi kademe kademe paylaşır. Akım bölücü: paralel dirençler akımı paylaşır.
  - Seri/paralel eşdeğer direnç, iletkenlik ($G = 1/R$), seri ve paralel gerilim ve akım kaynakları.
- KCL ve KVL'den düğüm ve çevre analizine geçiş
  - Düğüm gerilimleri analizi (node voltage) KCL'ye dayanır: bir düğüme giren akımlar çıkan akımlara eşittir.
  - Çevre akımları analizi (mesh current) KVL'ye dayanır: kapalı bir çevrede gerilimlerin toplamı sıfırdır (enerjinin korunumu).
  - KVL ancak kapalı bir çevre (loop) için yazılabilir; açık devre bırakılan bir kolda KVL yazılamaz.
- Matematik ön bilgisi: lineer denklem sistemlerinin çözümü (ekrandan, 00:14:09 ve 00:19:09)
  - Yerine koyma (substitution): bir denklemden bir bilinmeyen çekilip diğerine yazılır. İki bilinmeyende pratiktir.
  - Determinant (Cramer kuralı): denklemler matris biçimine getirilir, $\begin{bmatrix} a_1 & b_1 \\ a_2 & b_2 \end{bmatrix}\begin{bmatrix} x \\ y \end{bmatrix} = \begin{bmatrix} c_1 \\ c_2 \end{bmatrix}$.
  - $D = a_1 b_2 - a_2 b_1$, $x = D_x / D$, $y = D_y / D$. $D_x$ için sağ taraf vektörü $x$'in katsayı sütununa, $D_y$ için $y$'nin katsayı sütununa yazılır.
  - $3 \times 3$ determinant için ilk iki sütun sağa tekrar yazılır (Sarrus kuralı); sağa inen üç köşegen çarpımı artı, sola inen üç köşegen çarpımı eksi işaretle toplanır.
- Düğüm analizi adımları (ekrandan, 00:24:09 – 00:39:09)
  - Düğüm: iki ya da daha çok devre elemanının birleştiği nokta. Arada eleman olmayan iletkenle birleşen noktalar tek düğümdür.
  - 1) Bir referans düğümü (toprak, 0 V) seç. Bu, değişken sayısını azaltır.
  - 2) Diğer düğümlere gerilim etiketi ver ($V_1, V_2, \dots$).
  - 3) Her elemandaki akıma ad ve yön ver. Yön ilk başta bir varsayımdır.
  - 4) KCL denklemlerini yaz (örneğin $I_2 = I_3 + I_4$).
  - 5) Ohm yasasıyla akımları düğüm gerilimleri cinsinden yaz: $a$'dan $b$'ye akan akım $I = (V_a - V_b)/R$.
  - 6) Denklem sistemini çöz; elemanlardaki gerilim ve akımları bul.
- Süper düğüm (supernode) (ekrandan, 00:59:09 ve 01:04:09)
  - Uçlarından hiçbiri toprağa bağlı olmayan gerilim kaynağı (floating voltage source) düğüm analizinde sorun çıkarır: kaynağın akımı Ohm yasasıyla yazılamaz.
  - Çözüm: kaynağın iki ucundaki düğümler tek bir süper düğüm sayılır, biri diğeri cinsinden yazılır (örneğin $v_c = v_b + V_2$). KCL süper düğümün tamamı için yazılır.
  - Bir ucu referansa bağlı gerilim kaynağı varsa o düğümün gerilimi doğrudan bilinir (örneğin $v_a = V_1$).
- Bağımlı kaynaklı düğüm analizi örneği (ekrandan, 01:29:09 – 01:39:09)
  - Bağımlı akım ve bağımlı gerilim kaynağının değerleri düğüm gerilimleri cinsinden yazılır ($0{,}5 v_x = 0{,}5(v_2 - v_1)$, $0{,}2 v_y = 0{,}2(v_4 - v_1)$).
- Çevre (mesh) analizi adımları (ekrandan, 01:59:09)
  - Bütün çevreleri belirle, her çevre akımına ad ver; bütün çevrelerde aynı yön (örneğin saat yönü) seçilir.
  - Her elemandaki gerilimi etiketle, her çevre için KVL yaz, Ohm yasasıyla gerilimleri çevre akımları cinsinden ifade et.
  - İki çevrenin ortak elemanında akım farkı kullanılır: $V_3 = (i_1 - i_2)R_3$ birinci çevre için; ikinci çevre için $R_3(i_2 - i_1)$.
- Süper çevre (supermesh) (ekrandan, 02:24:09 ve 02:29:09)
  - İki çevrenin ortak kolunda akım kaynağı varsa o kolun gerilimi KVL'ye yazılamaz.
  - Bu iki çevre yerine ikisinin dışından dolaşan tek bir çevre (süper çevre) için KVL yazılır; akım kaynağı ek denklem verir (örneğin $i_1 - i_3 = 7$ A).
- Düzlemsel (planar) ve düzlemsel olmayan (non-planar) devreler
  - Kesişen kol olmadan düzleme çizilebilen (gerekirse dönüştürülerek) devreler düzlemseldir; çevre analizi bunlara uygulanır. Hiçbir şekilde kesişmesiz çizilemeyenler düzlemsel değildir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Akım yönü bir kez seçilince denklemler o yöne göre yazılmalı
  - $V_a - V_b$ ile $V_b - V_a$ aynı değildir. Bir dirençte akımı soldan sağa kabul edip başka bir yerde ters işaretle yazmak bütün çözümü bozar.
  - Bulunan akım eksi çıkarsa gerçek yön kabul edilenin tersidir; bu bir hata değildir.
- Düğüm analizinde en sık hata işaret hatasıdır
  - Konu zor değildir ama denklemlerin işaretinde yapılan hata soruyu tamamen götürür.
- Paralel kollarda akım eşitliği yanlışı
  - $I_3 = I_4 = I_5$ gibi bir eşitlik yazılamaz; bir düğümde ayrılan akım için $I_2 = I_3 + I_4$ yazılır, seri elemanlarda ise $I_4 = I_5$.
- Kontrol kuralları
  - Tek kaynaklı dirençli devrede hiçbir düğümde besleme geriliminden yüksek gerilim olmaz; hiçbir koldan ana kol akımından büyük akım geçmez.
  - Eşdeğer direnç ile ana kol akımı bulunarak sonuç kontrol edilebilir.
- Çevre analizinde ortak eleman
  - Ortak elemanın gerilimi ikinci çevre için ya $-R(i_1 - i_2)$ ya da $R(i_2 - i_1)$ diye yazılır. $-R(i_2 - i_1)$ yazmak yanlıştır.
- Çözüm yöntemi serbesttir
  - Determinant için başka yöntemler (alta yazma, satır sıfırlama) da kullanılabilir; doğru sonuca ulaşmak yeterlidir.
- Bağımlı akım kaynağı, bağımlı gerilim kaynağı ve süper düğüm içeren örnek (Example 03) evde baştan çözülmesi önerilen tipte bir sorudur.

## Kısa Tekrar Notları

- Düğüm analizi = KCL + Ohm yasası; bilinmeyenler düğüm gerilimleri.
- Çevre analizi = KVL + Ohm yasası; bilinmeyenler çevre akımları.
- Referans düğümü 0 V; genelde alttaki ortak düğüm seçilir.
- Akım: $I = (V_{\text{yüksek}} - V_{\text{düşük}})/R$, kabul edilen yöne göre.
- Gerilim kaynağı iki düğüm arasında (toprağa bağlı değil) → süper düğüm: $v_c = v_b + V_s$.
- Akım kaynağı iki çevrenin ortak kolunda → süper çevre: akım kaynağı $i_1 - i_3 = I_s$ bağıntısını verir.
- Cramer: $x = D_x/D$; $3\times3$'te Sarrus kuralı.
- Örnek sonuçları: Example 01'de $R_{\text{eş}} = 20{,}2$ kΩ, $I_1 = 495$ µA; Example 02'de $V_1 = V_2 = 20$ V, 15 Ω'dan akım geçmez; Example 03'te $v_1 = -12$, $v_2 = -4$, $v_3 = 0$, $v_4 = -2$ V; Example 05'te $i_1 = 6$ A, $i_2 = 4$ A.

## Detaylı Açıklamalar

- Matematik ön bilgisi
  - Düğüm ve çevre analizi çok bilinmeyenli lineer denklem sistemleri üretir. İki bilinmeyende yerine koyma yeterlidir; üç-dört bilinmeyende denklemleri matris biçimine getirip determinantla çözmek daha düzenlidir.
  - İki bilinmeyende (ekrandan, 00:14:09): $D = a_1 b_2 - a_2 b_1$, $D_x = c_1 b_2 - c_2 b_1$, $D_y = a_1 c_2 - a_2 c_1$. Hoca slaytta $D_x$ ve $D_y$ ifadelerinde yazım hatası olduğunu belirtip düzeltti.
  - Üç bilinmeyende (ekrandan, 00:19:09): $D = a_1 b_2 c_3 + b_1 c_2 a_3 + c_1 a_2 b_3 - a_3 b_2 c_1 - b_3 c_2 a_1 - c_3 a_2 b_1$; $x$, $y$, $z$ için ilgili sütuna $d_1, d_2, d_3$ yazılır.
- Düğüm analizi örnek devresi (Example 01, ekrandan 00:29:09 – 00:44:09)
  - Devre: 10 V kaynak, $R_1 = 9$ kΩ, $R_2 = 2$ kΩ, $R_3 = 5$ kΩ, $R_4 = 3$ kΩ, $R_5 = 1$ kΩ, $R_6 = 7$ kΩ. Kaynak $V_1$ ile toprak arasında olduğu için $V_1 - 0 = V_{in}$, yani $V_1 = 10$ V.
  - KCL: $I_7 = I_1 = I_2 = I_6$, $I_2 = I_3 + I_4$, $I_4 = I_5$.
  - Ohm yasasıyla: $I_1 = (V_1 - V_2)/R_1$, $I_2 = (V_2 - V_3)/R_2$, $I_3 = (V_3 - V_5)/R_3$, $I_4 = (V_3 - V_4)/R_4$, $I_5 = (V_4 - V_5)/R_5$.
  - Kontrol: $R_{\text{eş}} = 7 + [5 \parallel (1+3)] + 2 + 9 = 20{,}2$ kΩ, $I_1 = 10/20{,}2 \approx 495$ µA. Akım 5 kΩ ve 4 kΩ'luk kollara ters orantıyla bölünür: $I_3 = 495 \cdot 4/9 \approx 220$ µA, $I_4 = I_5 = 495 \cdot 5/9 \approx 275$ µA (ekrandan, 00:44:09; python ile doğrulandı).
- İki akım kaynaklı düğüm örneği (Example 02, ekrandan 00:49:09)
  - 2 A ve 4 A kaynaklar, 7 Ω + 3 Ω (10 Ω) kol, 15 Ω ve 5 Ω. Denklemler: $2 = V_1/10 + (V_1 - V_2)/15$, $4 = V_2/5 - (V_1 - V_2)/15$.
  - Düzenlenince $5V_1 - 2V_2 = 60$, $-V_1 + 4V_2 = 60$. Çözüm $V_1 = V_2 = 20$ V; 15 Ω'dan geçen akım $(20-20)/15 = 0$.
- Süper düğüm
  - Floating gerilim kaynağının akımı yazılamadığı için o kaynağın uçlarındaki düğümler tek düğüm gibi ele alınır. Bilinmeyen sayısı bir azalır, kaynak bağıntısı ek denklem olur.
  - Örnek (ekrandan, 00:59:09): $v_a = V_1$, $v_c = v_b + V_2$; $R_1$ akımı $(V_1 - (v_b + V_2))/R_1$ olarak yazılır ve tek bilinmeyen $v_b$ kalır.
- Bağımlı kaynaklı örnek (Example 03, ekrandan 01:39:09)
  - $v_1 = -12$ V (12 V kaynak ters bağlı). $v_2$ düğümü: $14 = (v_2 - v_1)/0{,}5 + (v_2 - v_3)/2$.
  - $v_3$-$v_4$ süper düğümü: $v_3 - v_4 = 0{,}2 v_y$, $v_y = v_4 - v_1$; bağımlı akım kaynağı $0{,}5 v_x = 0{,}5(v_2 - v_1)$.
  - Sonuç denklemleri slayttan: $-2v_1 + 2{,}5v_2 - 0{,}5v_3 = 14$; $0{,}1v_1 - v_2 + 0{,}5v_3 + 1{,}4v_4 = 0$; $v_1 = -12$; $0{,}2v_1 + v_3 - 1{,}2v_4 = 0$. Python çözümü: $v_1 = -12$, $v_2 = -4$, $v_3 = 0$, $v_4 = -2$ V (sonuç derste söylenmedi).
- Çevre analizi
  - Saat yönünde seçilen çevre akımlarıyla her direnç gerilimi $V = iR$ olarak yazılır; ortak elemanda akım farkı kullanılır.
  - Example 05 (ekrandan, 02:09:09): $9i_1 - 3i_2 = 42$, $-3i_1 + 7i_2 = 10$; $D = 54$, $i_1 = 6$ A, $i_2 = 4$ A; 3 Ω üzerindeki gerilim $3(6-4) = 6$ V.
  - Example 06 (ekrandan, 02:19:09): $6i_1 - 2i_2 = 7$, $-2i_1 + 7i_2 = -3$; $i_1 = 43/38 \approx 1{,}132$ A, $i_2 = -2/19 \approx -0{,}105$ A. 2 V kaynaktan geçen akım $i_1 - i_2 \approx 1{,}237$ A; kaynak yaklaşık $2{,}47$ W güç verir (soğurduğu güç $-2{,}47$ W).
  - Ders sonrası not: Hoca sonucu "eksi 2,47 volt" diye söyledi; güç birimi watt'tır.
- Süper çevre
  - Example 07 (ekrandan, 02:29:09): süper çevre $-7 + 1(i_1 - i_2) + 3(i_3 - i_2) + 1 i_3 = 0$, çevre 2: $-i_1 + 6i_2 - 3i_3 = 0$, akım kaynağı $i_1 - i_3 = 7$. Slayttaki sonuç $i_1 = 9$ A, $i_2 = 2{,}5$ A; buradan $i_3 = 2$ A.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
