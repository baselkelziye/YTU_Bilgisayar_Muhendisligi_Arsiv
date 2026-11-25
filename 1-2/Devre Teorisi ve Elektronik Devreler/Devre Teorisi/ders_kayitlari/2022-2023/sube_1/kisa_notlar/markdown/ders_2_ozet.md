# Ders 2 Çalışma Özeti

## Genel Konular

- Akım, gerilim, güç ve enerji tanımlarının tekrarı
  - Akım birim zamandaki net yük değişimidir: $i = \dfrac{dq}{dt}$ (ayrık gösterimde $\Delta q / \Delta t$).
  - Gerilim (potansiyel fark), birim yüke kazandırılan enerjidir: $v = \dfrac{dw}{dq}$, $1\ \text{V} = 1\ \text{J}/1\ \text{C}$ (ekrandan, 00:05:00).
  - Güç birim zamanda harcanan enerjidir: $p = \dfrac{dw}{dt} = \dfrac{dw}{dq}\cdot\dfrac{dq}{dt} = v\,i$. Birimi watt'tır; $1\ \text{W} = 1\ \text{V}\cdot\text{A}$.
  - Enerji, gücün bir zaman aralığı üzerindeki integralidir.
- Güç işareti ve referans yönleri
  - Akım, elemanın gerilim referansının artı ucundan giriyorsa $p = v\,i$ olarak hesaplanır. Sonuç pozitifse eleman güç tüketir (absorbe eder), negatifse devreye güç sağlar.
  - Ampermetre elemana seri bağlanır, iç direnci sıfır kabul edilir (kısa devre gibi). Voltmetre elemana paralel bağlanır, iç direnci sonsuz kabul edilir (açık devre gibi).
  - Aynı elemanı ters yönlü ölçmek sonucu değiştirmez: bir yönde $+2$ V okunan gerilim, prob yönleri ters çevrilince $-2$ V okunur; bir yönde $1$ A akım ters yönde $-1$ A demektir.
  - Bir güç ya da gerilim kaynağının gücü pozitif de çıkabilir (örnek: şarj edilen pil).
- Enerjinin korunumu
  - Dışarıyla bağlantısı olmayan kapalı bir devrede bütün elemanların güçlerinin toplamı sıfırdır: $\sum p_{\text{absorbe}} = 0$, yani tüketilen güç toplamı sağlanan güç toplamına eşittir.
- Akım referans yönü seçimi
  - Karmaşık devrelerde her kola kendimiz bir akım referans yönü veririz. Sonuç negatif çıkarsa gerçek akım ters yöndedir. "Bu yönde 1 A" ile "ters yönde $-1$ A" aynı şeydir.
- Ohm yasası
  - Sabit bir dirence uygulanan gerilim değiştirilip akım ölçülürse doğrusal bir $I$-$V$ eğrisi elde edilir; eğim $\Delta I/\Delta V = 1/R$'dir (ekrandan, 00:25:00).
  - $V = IR$ yalnız direnç elemanı için geçerlidir. İdeal kablonun direnci sıfırdır.
  - Ekran örneği: $2\ \Omega$ dirençten 2 A geçiyorsa uçlardan biri $x+4$ V, diğeri $x$ V'tur (ekrandan, 00:25:00).
  - Tek gözlü bir devrede akım her noktada aynıdır; gerilim ise iki nokta arasındaki farktır ve bir referansa göre tanımlanır.
  - Devre kopuksa o kolda akım akmaz ve dirençte gerilim düşümü olmaz; direncin iki ucu aynı potansiyelde kalır.
- Direnç, öz direnç ve iletkenlik
  - $R = \rho \dfrac{L}{A}$: uzunluk arttıkça direnç artar, kesit alanı arttıkça azalır.
  - Metallerin öz direnci çok küçük, yarı iletkenlerinki görece yüksek, yalıtkanlarınki çok yüksektir. Hangi malzemenin seçileceği kullanım amacına bağlıdır.
  - $R = 0$: kısa devre; akım ne olursa olsun $v = iR = 0$ (ekrandan, 00:40:00). $R = \infty$: açık devre; gerilim ne olursa olsun $i = 0$. İkisinde de harcanan güç sıfırdır.
  - İletkenlik $G = 1/R = \sigma \dfrac{A}{L}$, birimi siemens (S, ℧); $\sigma = 1/\rho$. $R$ ve $G$ her zaman pozitiftir.
- Dirençte harcanan güç (ekrandan, 00:45:00)
  - $p = iv = i^2R = \dfrac{v^2}{R} = \dfrac{i^2}{G} = v^2G$.
- Düğüm, yol, çevrim ve dal kavramları
  - Düğüm: iki ya da daha fazla elemanın birleştiği nokta. Bir düğüm tel boyunca kaydırılabilir, ama bir elemanın üzerinden atlayamaz.
  - Yol: düğümler arasındaki, aynı düğümden iki kez geçmeyen geçiş. Çevrim (loop): başladığı düğümde biten yol. Dal: tek bir eleman içeren yol.
- Kirchhoff akım yasası (KCL)
  - Bir düğüme giren akımların cebirsel toplamı sıfırdır; giren akımlar toplamı çıkan akımlar toplamına eşittir.
- Kirchhoff gerilim yasası (KVL)
  - Enerjinin korunumuna dayanır: bir çevrim boyunca gerilim düşümlerinin cebirsel toplamı sıfırdır (ekrandan, 00:55:00).
  - Dolaşım yönü ters seçilirse denklem $-1$ ile çarpılmış olur; sonuç değişmez.
- KCL ve KVL örnekleri (Ohm yasasıyla birlikte)
  - Referans yönleri bir kez seçilir, denklem bu yönlere göre kurulur, ölçülen değerler işaretleriyle yerine konur.
  - KVL çevrimi birden fazla gözü kapsayabilir ve iki düğüm arasındaki bilinmeyen bir gerilimin üzerinden kapatılabilir.
- Tek çevreli (single-loop) devreler
  - Bütün elemanlardan aynı akım geçer: $i = \dfrac{v_{s1} - v_{s2}}{R_1 + R_2}$.
  - Bağımlı kaynaklı örneklerde bağımlı kaynak, bağımsız kaynaktan daha fazla güç verebilir; bağımsız kaynak bile güç tüketebilir.
- Tek düğüm çiftli (single-node-pair) devreler
  - Bütün paralel kollarda gerilim aynıdır. Bu yüzden tek bilinmeyen $v$'dir ve KCL ile çözülür.

## Hocanın Özellikle Vurguladığı Kısımlar

- Referans yönlerine sadık kalmak
  - Hoca bunu en önemli ilke olarak verdi: yönler bir kez seçilir, denklem kurulur, sonra işlem tamamen cebirseldir. Negatif çıkan bir değer görüp yönü sonradan değiştirmek, denklemi baştan kurmayı gerektirir.
- Güç işareti yorumu
  - $p > 0$ ise eleman güç tüketir, $p < 0$ ise güç sağlar. Bir kaynağın gücünün pozitif çıkması hata değildir.
- Direncin gücü her zaman pozitiftir
  - Bir direnç için hesaplanan güç negatif çıkıyorsa referans yönlerinde ya da cebirde hata vardır. Bu, hocanın önerdiği bir kontrol yöntemidir. $i^2R$ ya da $v^2/R$ ile hesap işaret karışıklığını ortadan kaldırır.
- Bağımlı kaynaklı tek çevre örneğindeki tuzak
  - 15 Ω'luk direncin $v_A$ referansı akım yönüne ters verilmiştir. $v_A = 15i$ yazmak hatadır; doğrusu $v_A = -15i$'dir. Hoca bunu devrenin en önemli kısmı olarak gösterdi.
- Uygun çevrim seçmek
  - Uygun bir çevrim seçmek hesabı kısaltır; çevrimin tek ve küçük bir göz olması gerekmez.
- Devreyi topolojik olarak görmek
  - Karmaşık görünen bir devre aslında tek düğüm çiftli olabilir. Bunu fark etmek çözüm yöntemini (KCL ile tek bilinmeyen) belirler.

## Kısa Tekrar Notları

- $i = dq/dt$, $v = dw/dq$, $p = vi$, $w = \int p\,dt$.
- Akım gerilim referansının artısından giriyorsa $p = vi$; $p>0$ tüketir, $p<0$ sağlar.
- Kapalı devrede $\sum p = 0$.
- Ampermetre seri ve iç direnci 0; voltmetre paralel ve iç direnci $\infty$.
- $V = IR$ (yalnız direnç), $R = \rho L/A$, $G = 1/R = \sigma A/L$ (S).
- $p = i^2R = v^2/R = i^2/G = v^2G$.
- Kısa devre: $v = 0$; açık devre: $i = 0$; ikisinde de $p = 0$.
- KCL: $\sum i_{\text{giren}} = \sum i_{\text{çıkan}}$. KVL: çevrim boyunca $\sum v = 0$.
- Tek çevre: ortak akım. Tek düğüm çifti: ortak gerilim.
- Direnç gücü negatif çıkarsa hesapta hata vardır.

## Detaylı Açıklamalar

- **Güç işaretinin ölçümle gösterilmesi (ekrandan, 00:10:00 ve 00:15:00).** Bir elemandan 1 A geçsin ve uçlarında 1 V ölçülsün. Akım, gerilim referansının artı ucundan giriyorsa $p = (1\ \text{V})(1\ \text{A}) = +1$ W'tır ve eleman güç tüketir. Voltmetre ters bağlanıp $-1$ V okunsa da akım bu kez referansın eksi ucundan girdiği için iki eksi birbirini götürür ve yine $+1$ W bulunur. Akım elemanın eksi ucundan giriyor, gerilim de o yönde 1 V ise $p = (-1\ \text{V})(1\ \text{A}) = -1$ W'tır; eleman güç sağlar.
- **Ohm yasasının deneyle kurulması.** Sabit bir $R_1$ seçilir, gerilim belirli bir aralıkta değiştirilip akım ölçülür; ölçüm noktalarına bir doğru oturtulur. Eğim $\tan\alpha = \Delta I/\Delta V = 1/R_1$ sabit çıkar (ekrandan, 00:25:00). Aynı deney $R_2$ ile tekrarlanınca eğim küçülürse, aynı gerilim değişimine daha az akım değişimi karşılık geldiği için $R_2 > R_1$'dir.
- **Kopuk devrede potansiyel (ekrandan, 00:30:00).** 1 V'luk kaynağın eksi ucu toprağa (0 V) bağlıdır. 1 Ω'luk direncin üst bağlantısı koparılırsa kolda akım akmaz; direnç üzerinde düşüm olmadığından direncin üst ucu da 0 V'ta kalır. Alt bağlantı koparılırsa yine akım yoktur ve direncin iki ucu da 1 V'tur.
- **Düğüm sayma alıştırması (ekrandan, 00:50:00).** Devrede A-E arasında bir gerilim kaynağı; A-B, B-E, B-C, C-D ve F-D arasında birer direnç vardır. C, F ve G aynı tel üzerindedir; D ve E alttaki ortak teldedir. Eleman sayısı 6, tekil düğüm sayısı 4'tür ({A}, {B}, {C, F, G}, {D, E}). B→C→D bir yoldur ama çevrim değildir. E→D→C→B→E hem yol hem çevrimdir.
- **KCL örneği (ekrandan, 01:00:00).** Gerilim kaynağı 3 A sağlar, akım kaynağı 5 A'dır ve $R_2$'den 2 A geçer. Ortak düğüm için $3 - 2 - i + 5 = 0$, buradan $i = 6$ A bulunur.
- **KCL ve kaynak gücü (ekrandan, 01:05:00).** Düğüme $R_2$ üzerinden 3 mA, $R_1$ üzerinden 0.5 mA ve kaynaktan $I$ girer; $R_3$ üzerinden 1.9 mA çıkar. Buradan $I = 1.9 - 3.5 = -1.6$ mA bulunur. Akım 3 V'luk kaynağın eksi ucundan girdiği için $p = (-3)(-1.6) = +4.8$ mW çıkar; kaynak güç tüketir (şarj olur).
- **Ohm ve KCL birlikte (ekrandan, 01:10:00).** $I_1 = 2/7 = 0.286$ mA, $I_2 = 4/2 = 2$ mA, $I_3 = 1.75/5 = 0.35$ mA. $I_2 + I_3 + I = I_1$ olduğundan $I = -2.06$ mA bulunur.
- **KVL örnekleri (ekrandan, 01:35:00 ve 01:40:00).** Birinci devrede $-5 - 7 + v_x = 0$, yani $v_x = 12$ V ve $i_x = 120$ mA'dır. İkinci devrede $3 + 1 + v_x = 0$, yani $v_x = -4$ V ve $i_x = -400$ mA'dır. Çok gözlü örnekte $4 - 36 + v_{R2} = 0$ ile $v_{R2} = 32$ V bulunur. Ardından a-b arasındaki gerilim üzerinden kapatılan çevrimde $-32 + 12 + 14 + v_x = 0$ yazılır ve $v_x = 6$ V çıkar.
- **Akım kaynaklı KVL örneği (ekrandan, 01:45:00).** $v_8 = 5 \cdot 8 = 40$ V, $v_{10} = 60 - 40 = 20$ V, $i_{10} = 2$ A, $i_4 = 5 - 2 = 3$ A, $v_4 = 12$ V, $v_x = 20 - 12 = 8$ V. Sonra $i_2 = 4$ A ve KCL'den $i_x = 1$ A bulunur.
- **Enerjinin korunumu (ekrandan, 01:55:00).** Beş elemanlı bir devrede güçler $-56$, $16$, $-60$, $160$ ve $-60$ W'tır; toplamları $-176 + 176 = 0$'dır.
- **Bağımlı gerilim kaynaklı tek çevre (ekrandan, 02:00:00).** KVL: $-120 + v_{30} + 2v_A - v_A = 0$. Burada $v_{30} = 30i$ ve $v_A = -15i$ olduğundan $i = 8$ A bulunur. Güçler: 120 V kaynak $-960$ W, 30 Ω $1920$ W, bağımlı kaynak $-1920$ W, 15 Ω $960$ W.
- **İkinci bağımlı kaynak örneği (ekrandan, 02:10:00).** KVL: $-v_x - 12 + 15i + 4v_x = 0$ ve $v_x = -30i$. Buradan $i = -4/25 = -0.16$ A ve $v_x = 4.8$ V bulunur. Güçler: 12 V kaynak $+1.92$ W (tüketir), 8 Ω $204.8$ mW, 7 Ω $179.2$ mW, 30 Ω $768$ mW, bağımlı kaynak $-3.072$ W (sağlar).
- **Tek düğüm çiftli örnekler (ekrandan, 02:25:00, 02:35:00 ve 02:40:00).**
  - 120 A ve 30 A kaynaklı, $1/30$ Ω ve $1/15$ Ω dirençli devre: $v = 2$ V, $i_1 = 60$ A, $i_2 = 30$ A. Güçler: 120 A kaynak $-240$ W, $R_1$ $120$ W, $R_2$ $60$ W, 30 A kaynak $60$ W.
  - 24 mA ve $2i_x$ kaynaklı devre: $v = 14.4$ V. Bağımsız kaynağın gücü $-345.6$ mW'tır, yani kaynak güç sağlar.
  - 5.6 A, 2 A ve $0.1v_x$ kaynaklı devre: $v_x = 54$ V, $i_A = 3$ A, $i_B = -5.4$ A, $i_C = 6$ A.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
