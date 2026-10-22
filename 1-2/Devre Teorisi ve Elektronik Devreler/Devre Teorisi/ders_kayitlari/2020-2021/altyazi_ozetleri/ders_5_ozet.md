# Ders 5 Çalışma Özeti

## Genel Konular

- Duyurular
  - Dersin hemen ardından (saat 16:00) birinci kısa sınav var. Online Yıldız üzerinden, karma: çoktan seçmeli ve klasik sorular.
  - Konular planın ilk üç haftası: Ohm yasası, seri-paralel devreler, Kirchhoff akım ve gerilim yasaları, düğüm ve çevre denklemleri. Teoremler dahil değil.
  - Klasik soruların çözümleri dosya olarak, sınav süresi içinde yüklenecek. Ek yükleme süresi yok, dosya boyutlarını makul tutun.
  - Konular planın bir hafta gerisinde (8 Nisan haftasında hâlâ kaynak dönüşümü, Norton-Thevenin ve maksimum güç işleniyor).
- Geçen haftanın tekrarı: doğrusallık ve süperpozisyon
  - Birden fazla kaynaklı devrede bir elemana toplam etki, her seferinde tek kaynak bırakılıp diğerleri sıfırlanarak bulunan etkilerin yönlü toplamıdır.
  - Gerilim kaynağını sıfırlamak = yerine kısa devre koymak. Akım kaynağını sıfırlamak = yerine açık devre koymak.
  - Süperpozisyon hem DC hem AC devrelerde geçerlidir.
- Kaynak dönüşümü
  - Eşdeğerlik ölçütü: bir terminal çiftinden (ör. AB) bakıldığında, bu uçlara bağlanan her yük direnci için yük gerilimi ve yük akımı iki yapıda aynı olmalıdır.
  - Seri dirençli gerilim kaynağı ($V_s$, $R$) ile paralel dirençli akım kaynağı ($I_s$, $R$) birbirine eşdeğerdir:
    - $V_s = I_s R$, iki yapıda direnç aynıdır.
    - Açık devre: gerilim kaynağında direnç üzerinden akım akmaz, uçlarda $V_s$ görülür. Akım kaynağında $I_s$ tamamen $R$ üzerinden akar, uçlarda $I_s R$ görülür.
    - Yük bağlıyken: gerilim kaynağında $I_L = \frac{V_s}{R + R_L}$. Akım kaynağında akım bölücüden $I_L = I_s\frac{R}{R + R_L} = \frac{V_s}{R + R_L}$. İkisi aynıdır.
  - Faydası: devreyi daha basit topolojilere indirgeyip pratik çözmek. Ör. birkaç seri dirençli gerilim kaynağı akım kaynağına çevrilince hepsi paralel bir yapıya dönüşür.
  - Bağımlı kaynaklar için de geçerlidir. Dikkat: bağımlı kaynağın kontrol değişkeni (ör. $V_s = a\,i_x$'teki $i_x$) dönüşümden sonra kaybolmamalıdır. Kontrol değişkeninin tanımlı olduğu elemanlar dönüşüme sokulmaz.
- İdeal ve ideal olmayan kaynaklar
  - Gerçek gerilim kaynaklarının bir iç direnci ($R_s$) vardır. İdeal gerilim kaynağından teorik olarak sonsuz akım çekilebilir, iç direnç bunu sınırlar. İdeal gerilim kaynağında seri iç direnç $R_s = 0$'dır.
  - Gerçek akım kaynağı paralel bir iç dirençle modellenir. Bu direnç akımın bir kısmını içeride böler. İdeal akım kaynağında paralel iç direnç sonsuzdur.
  - Neden gerilim kaynağında seri, akım kaynağında paralel? Akım kaynağına seri bir direnç akımın tamamının dışarı çıkmasını engellemez. Paralel direnç ise akımı böler ve gerçek kaybı modeller.
  - Yük gücü ($R_s$ sabit, $R_L$ değişken):
    - $V_L = V_s \frac{R_L}{R_s + R_L}$, $I_L = \frac{V_s}{R_s + R_L}$.
    - $R_L = 0$: $V_L = 0$, $P_L = 0$. $R_L \to \infty$: $I_L = 0$, $P_L = 0$.
    - Arada tek tepeli bir eğri vardır, güç bir noktada maksimum olur. Bu maksimum güç teoremine götürür.
    - Örnek: $R_L = R_s$ ise $V_L = \frac{V_s}{2}$, $I_L = \frac{V_s}{2R_s}$, $P_L = \frac{V_s^2}{4R_s}$. $R_L$ bundan biraz küçük ya da büyük olursa güç azalır.
    - Bu durumda gücün yarısı iç dirençte, yarısı yükte harcanır. Yüke aktarılabilecek güç en fazla ideal kaynağın sağladığının yarısıdır.
    - İspat ($\frac{\partial P_L}{\partial R_L} = 0$) bir sonraki derse kaldı.
- Kaynak dönüşümü örnekleri
  - Örnek 10: $V_s = 18$ V, $R_s = 3$ kΩ, $R_L = 6$ kΩ. Eşdeğer akım kaynağı bulunacak.
    - Yük varken: $I_L = \frac{18}{9\text{k}} = 2$ mA, $V_L = 2\,\text{mA} \cdot 6\,\text{k} = 12$ V.
    - Akım kaynaklı yapıda yük varken: $(I_s - 2\,\text{mA})R = 12$. Yük yokken (açık devre): $I_s R = 18$.
    - $18 - 2R = 12$ olduğundan $R = 3$ kΩ, $I_s = 6$ mA. Yani direnç aynı kalır ve $I_s = V_s / R$.
  - Örnek 11: $I_s = 5$ mA, $R_s = 50$ Ω, $R_L = 300$ Ω. Eşdeğer gerilim kaynağı bulunacak.
    - Yük varken: $I_L = 5\,\text{mA}\cdot\frac{50}{350} = \frac{5}{7}$ mA.
    - Yük varken yazılan iki denklem ($I_L$ ve $V_L$) aynı denklemdir, iki bilinmeyeni çözmeye yetmez. Bu yüzden yük kaldırılmış (açık devre) durum da kullanılır.
    - Açık devre: $V_s = 5\,\text{mA} \cdot 50 = 250$ mV. Sonra $\frac{250\,\text{mV}}{R + 300} = \frac{5}{7}$ mA'dan $R = 50$ Ω.
  - Örnek 12: kaynak dönüşümüyle $v_0$'ı bulun. Devre: 4 Ω ve aşağı yönlü 3 A kaynak paralel, 2 Ω seri, $v_0$'ın ölçüldüğü 8 Ω, 3 Ω seri ve 12 V kaynak.
    - 3 A ∥ 4 Ω → 12 V (ters yönlü) + 4 Ω seri. 4 Ω ile 2 Ω seri → 6 Ω.
    - 12 V + 3 Ω → 4 A ∥ 3 Ω. 12 V + 6 Ω → 2 A ∥ 6 Ω.
    - 6 Ω ∥ 3 Ω = 2 Ω. Ters yönlü kaynakların net katkısı 2 A.
    - 8 Ω ve 2 Ω'luk paralel yapıda 8 Ω'dan geçen akım $2 \cdot \frac{2}{10} = 0.4$ A, $v_0 = 0.4 \cdot 8 = 3.2$ V.
    - $v_0$'ın ölçüldüğü eleman dönüşüme sokulmadı, böylece $v_0$ kaybolmadı.
  - Örnek 13: kaynak dönüşümüyle $i_0$'ı bulun (cevap 1.78 A).
    - Devre: solda 6 Ω, yukarı 5 A ve 3 Ω paralel. Üstte 5 V kaynak (sola −, sağa +). Ortada $i_0$'ın aşağı aktığı 7 Ω. Sağda yukarı 3 A, 1 Ω ve 4 Ω.
    - Sol: 6 Ω ∥ 3 Ω = 2 Ω, 5 A ∥ 2 Ω → 10 V + 2 Ω. 5 V ile seri → 15 V + 2 Ω.
    - Sağ: 1 Ω + 4 Ω = 5 Ω, 3 A ∥ 5 Ω → 15 V + 5 Ω.
    - Hoca bir süre farklı dönüşümler denedi. Sonunda iki taraf yine akım kaynağına çevrildi: 7.5 A ∥ 2 Ω ve 3 A ∥ 5 Ω, ortada 7 Ω. Toplam 10.5 A.
    - $i_0 = 10.5 \cdot \frac{2 \parallel 5}{7 + 2 \parallel 5} \approx 1.78$ A.
    - Bu devre iki düğümle (düğüm denklemleriyle) de çözülebilir. Hoca yöntemi ne kadar ileri götürebileceğimizi göstermek için uzattı.
- Norton ve Thevenin teoremleri
  - Doğrusal elemanlardan oluşan karmaşık bir devrenin bir terminal çiftine bağlı yüke etkisi:
    - Thevenin: bağımsız bir gerilim kaynağı $V_{TH}$ ve seri direnç $R_{TH}$ ile,
    - Norton: bağımsız bir akım kaynağı $I_N$ ve paralel direnç $R_N$ ile eşdeğer olarak yazılabilir.
  - Thevenin ile Norton arasındaki geçiş kaynak dönüşümüdür: $R_N = R_{TH}$, $I_N = \frac{V_{TH}}{R_{TH}}$. Bu yüzden yöntemler Thevenin için anlatılır.
  - Yük direnci (ya da bağlanan ikinci devre, "Network B") eşdeğeri bulunan devrenin dışındadır.
  - Yöntem 1: Kaynak dönüşümlerini art arda uygulayıp bir gerilim kaynağı ve seri direnç kalana kadar indirgemek.
  - Yöntem 2: Açık devre gerilimi ve kısa devre akımı.
    - $R_L \to \infty$ (açık devre): uçlarda ölçülen gerilim $V_{OC} = V_{TH}$.
    - $R_L = 0$ (kısa devre): akan akım $I_{SC} = \frac{V_{TH}}{R_{TH}}$.
    - $R_{TH} = \frac{V_{OC}}{I_{SC}}$.
    - Pratikte içi bilinmeyen (black box) bir devrede voltmetre ve ampermetreyle ölçülebilir. Laboratuvarda böyle bir deney var (içeride bağımlı kaynak olmadığı bilgisiyle).
  - Yöntem 3: $V_{OC}$ ölçülür. Sonra devredeki bütün bağımsız kaynaklar sıfırlanır ve terminallerden bakılan eşdeğer direnç bulunur: $R_{eş} = R_{TH}$.
  - Yöntem 4 (içeride bağımlı kaynak varsa):
    - $V_{OC} = V_{TH}$ ölçülür.
    - Bağımsız kaynaklar sıfırlanır, uçlara bir test kaynağı (ör. 1 V veya 1 A) bağlanır.
    - $R_{TH} = \frac{v_{test}}{i_{test}}$.
    - Bağımlı kaynaklar asla sıfırlanmaz. Kontrol değişkenleri devrede kalmalıdır.
  - Örnek 14: 12 V, 3 Ω, 6 Ω, 7 Ω. Network A'nın Thevenin eşdeğeri.
    - Yöntem 1: 12 V + 3 Ω → 4 A ∥ 3 Ω. 3 ∥ 6 = 2 Ω. 4 A ∥ 2 Ω → 8 V + 2 Ω. 2 + 7 = 9 Ω. Sonuç $V_{TH} = 8$ V, $R_{TH} = 9$ Ω.
    - Yöntem 2: açık devrede 7 Ω'dan akım akmaz, 3 Ω ve 6 Ω gerilim bölücü: $V_{OC} = 12\cdot\frac{6}{9} = 8$ V. Kısa devrede ana kol akımı $\frac{12}{3 + 6\parallel 7}$, bunun $\frac{6}{13}$'ü kısa devreden akar. $R_{TH} = \frac{8}{I_{SC}} = 9$ Ω.
    - Yöntem 3: 12 V kısa devre yapılınca 3 ∥ 6 = 2 Ω, 7 Ω ile seri → 9 Ω.
    - Yöntem 4: 1 V test kaynağı bağlanınca $\frac{1}{9}$ A akar, oran yine 9 Ω.
  - Örnek 18: 4 V kaynak, 2 kΩ, yukarı 2 mA kaynak, 3 kΩ, yük 1 kΩ. Thevenin ve Norton eşdeğeri.
    - Açık devrede 3 kΩ'dan akım akmaz, gözde 2 mA akar. 2 kΩ'da 4 V düşer ve 4 V kaynakla toplanır: $V_{TH} = 8$ V.
    - Kaynaklar sıfırlanınca 2 kΩ + 3 kΩ = 5 kΩ = $R_{TH}$.
    - Kontrol (kısa devre, süper çevre): $I_{SC} = \frac{8}{5\text{k}} = 1.6$ mA, $R_{TH} = 5$ kΩ.
    - Norton: $I_N = 1.6$ mA, $R_N = 5$ kΩ.
    - Yük 1 kΩ, 2 kΩ, 5 kΩ ne olursa olsun bu eşdeğer aynı akım ve gerilimi verir.
  - Örnek 20: 4 V, 2 kΩ, yukarı yönlü bağımlı akım kaynağı $\frac{v_x}{4000}$, 3 kΩ, açık uçlarda $v_x$.
    - Açık devrede 3 kΩ'dan akım akmaz. Gözde $\frac{v_x}{4000}$ akar, 2 kΩ'da $\frac{v_x}{2}$ düşer. $v_x = 4 + \frac{v_x}{2}$, yani $V_{TH} = v_x = 8$ V.
    - 4 V sıfırlanıp uçlara 1 V test kaynağı bağlanınca (çevre denklemleri) test akımı 0.1 mA. $R_{TH} = 10$ kΩ.
    - Slayttaki çözüm kısa devre akımını kullanıyor. Hoca, bağımlı kaynak varsa test kaynağı yöntemini tavsiye ediyor.
  - Örnek 21: bağımlı gerilim kaynağı $1.5i$, 3 Ω, 2 Ω; bağımsız kaynak yok.
    - Açık devrede $i = 0$, bağımlı kaynak pasif, $V_{OC} = 0$. Kısa devre akımı da sıfırdır.
    - 1 A test akım kaynağı ($i = -1$): $\frac{v_{test} - 1.5(-1)}{3} + \frac{v_{test}}{2} = 1$, $v_{test} = 0.6$ V.
    - $V_{TH} = 0$, $R_{TH} = 0.6$ Ω. Devre tek bir 0.6 Ω'luk direnç gibi davranır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kaynak dönüşümünde direnç değeri değişmez; yalnız seri ↔ paralel olur. $V_s = I_s R$.
- Kaynak dönüşümünde kaynak yönlerine dikkat edin. Bağımlı kaynakta kontrol değişkenini kaybetmeyin.
- Bulmak istediğiniz akım ya da gerilimin ait olduğu elemanı dönüşüme sokmayın.
- Eşdeğerlik, yükün bütün değerleri için aynı akım ve gerilimi vermek demektir.
- İçeride bağımlı kaynak varsa mutlaka test kaynağı yöntemini (yöntem 4) kullanın. Bağımsız kaynakları sıfırlayın, bağımlıları bırakın.
- Maksimum güç, yük direnci kaynağın iç direncine (genel olarak $R_{TH}$'ye) eşitken çekilir.
- Kısa sınavda klasik çözümleri süre içinde yükleyin.

## Kısa Tekrar Notları

- Kaynak dönüşümü: $V_s$ ile seri $R$ ⇔ $I_s = \frac{V_s}{R}$ ile paralel $R$.
- İdeal gerilim kaynağı: seri $R_s = 0$. İdeal akım kaynağı: paralel $R_s = \infty$.
- $V_{TH} = V_{OC}$, $R_{TH} = \frac{V_{OC}}{I_{SC}}$, $I_N = I_{SC} = \frac{V_{TH}}{R_{TH}}$, $R_N = R_{TH}$.
- Yöntem 3: bağımsız kaynakları sıfırla, terminalden eşdeğer direnç.
- Yöntem 4: bağımsız kaynakları sıfırla, test kaynağı bağla, $R_{TH} = v_{test}/i_{test}$.
- $R_L = R_s$ ise $P_{L,max} = \frac{V_s^2}{4R_s}$.

## Detaylı Açıklamalar

### Thevenin yöntemleri ne zaman işe yarar?

- Yöntem 2 ($V_{OC}/I_{SC}$), devrede en az bir bağımsız kaynak varsa ve $V_{OC}$, $I_{SC}$ sıfırdan farklıysa bağımlı kaynak olsa da doğru sonuç verir. Örnek 20'de kısa devre akımı $\frac{4}{5\text{k}} = 0.8$ mA çıkar ve $\frac{8}{0.8\,\text{mA}} = 10$ kΩ, test kaynağıyla bulunanla aynıdır.
- Devrede hiç bağımsız kaynak yoksa (Örnek 21) $V_{OC} = I_{SC} = 0$ olur ve oran $0/0$ belirsizdir. Bu durumda test kaynağı zorunludur.
- Yöntem 3 yalnızca bağımlı kaynak yoksa geçerlidir. Bağımlı kaynak varken sadece dirençlerden eşdeğer hesaplanırsa bağımlı kaynağın etkisi kaybolur.

### Ders sonrası notlar

- **Örneklerin kontrolü:** Bütün örnekler ders sonrasında Python ile (düğüm denklemleriyle) yeniden çözüldü. Örnek 12: $v_0 = 3.2$ V. Örnek 13: $i_0 = 1.7797$ A. Örnek 14: $V_{TH} = 8$ V, $R_{TH} = 9$ Ω. Örnek 20: $V_{TH} = 8$ V, $R_{TH} = 10$ kΩ. Örnek 21: $R_{TH} = 0.6$ Ω. Hepsi derstekiyle aynıdır.
- **Örnek 11'de $V_L$:** Derste $V_L$ için "500/7" dendi. Doğrusu $V_L = 300\,\Omega \cdot \frac{5}{7}\,\text{mA} = \frac{1500}{7}$ mV $\approx 214.3$ mV'tur. Hoca da "hesapta yanlışlık mı yaptım" diye duraksadı. Bu değer sonraki adımları etkilemez: $V_s = 250$ mV ve $R = 50$ Ω doğrudur. Kontrol: $\frac{250}{350}\,\text{mA} = \frac{5}{7}$ mA.
- **Yöntem 4'ün ilk tanımı:** Derste bir yerde "kompleks devre içinde bağımsız kaynaklar varsa bu yöntemi kullanacağız" dendi. Kastedilen **bağımlı** kaynaklardır; hoca devamında doğrusunu söyledi.
- **"Açık devre akımı" ifadesi:** Yöntem 2 anlatılırken birkaç kez "açık devre akımı" dendi, hoca sonra düzeltti. $R_{TH} = \frac{V_{OC}}{I_{SC}}$; $I_{SC}$ **kısa devre** akımıdır.
- **Güç birimi:** Kısa devre durumunda "güç sıfır volt" dendi; güç vat (W) cinsindendir.
- **Örnek 14'teki güç sorusu:** Slayt yükte harcanan gücü de soruyor ama $R_L$ değeri verilmediği için derste hesaplanmadı. $R_L$ verilirse $P_L = \left(\frac{8}{9 + R_L}\right)^2 R_L$; en büyük değer $R_L = 9$ Ω'da $\frac{8^2}{4\cdot 9} \approx 1.78$ W'tır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
