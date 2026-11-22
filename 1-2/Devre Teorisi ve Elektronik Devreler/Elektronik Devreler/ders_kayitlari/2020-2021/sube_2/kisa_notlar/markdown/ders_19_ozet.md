# Ders 19 Çalışma Özeti

## Genel Konular

- FET ile BJT karşılaştırması
  - BJT akım kontrollü bir elemandır: baz akımı $I_B$ kolektör akımını belirler ($I_C = \beta I_B$, $I_E = I_C + I_B$). FET (Field Effect Transistor, alan etkili transistör) ise gerilim kontrollüdür (ekrandan, 00:15:00).
  - Benzerlikler: ikisi de yükselteç (amplifier), anahtarlama elemanı ve empedans uydurma devrelerinde kullanılır.
  - Farklar: FET'in giriş empedansı yüksektir, BJT'nin kazancı yüksektir. FET sıcaklık değişiminden daha az etkilenir ve tümleşik devrelere (IC) daha kolay yerleştirilir. FET statik elektriğe BJT'den daha duyarlıdır; çözüm iyi yalıtımdır.
  - Giriş empedansı çok yüksek olduğu için FET'in gate ucundan, BJT'deki baz akımı gibi bir akım akmaz.
- FET türleri
  - JFET (Junction FET, eklemli FET) ve MOSFET (Metal Oxide Semiconductor FET). MOSFET'in iki alt türü vardır: D-type (depletion, azaltmalı/boşaltmalı) ve E-type (enhancement, çoğaltmalı) (ekrandan, 00:50:00).
  - FET'lerde npn/pnp yerine kanal tipinden söz edilir: n-kanal ve p-kanal. Kanal, drain ile source arasındaki yarı iletken bölgedir.
- JFET yapısı ve uçları
  - n-kanal JFET'te drain (D) ve source (S) n-kanala, gate (G) iki yandaki p tipi bölgeye bağlıdır; p-n eklemlerinde tükenme bölgesi (depletion region) vardır (ekrandan, 00:20:00).
  - BJT'deki karşılıklar: baz → gate, kolektör → drain, emetör → source.
  - Musluk benzetmesi: source su kaynağı, drain suyun aktığı gider, gate ise akışı ayarlayan musluktur. Gate, tükenme bölgeleri üzerinden kanalın genişliğini değiştirir.
  - n-kanalda elektronların source'tan drain'e akması için drain'e artı, source'a eksi uygulanır ($V_{DS} > 0$). $I_D$ akımı elektron akışının tersine, drain'den source'a doğrudur (ekrandan, 00:25:00).
- $V_{GS} = 0$ iken JFET karakteristiği
  - $V_{DS}$ artırıldıkça $I_D$ önce hızla artar (ohmik bölge), tükenme bölgeleri kanalı daralttıkça eğri yatıklaşır.
  - Kanalın neredeyse kapandığı noktaya pinch-off (kıstırma) denir. Bu noktadaki $V_{DS}$ değeri $V_P$, bu noktada ulaşılan en büyük akım $I_{DSS}$'dir (drain-source doyum akımı) (ekrandan, 00:30:00).
  - Pinch-off'tan sonra $V_{DS}$ artsa da $I_D$ artmaz (doyum bölgesi, saturation region). Kanal hiçbir zaman tamamen kapanmaz; ince bir yol kalır.
  - $V_{DS}$ çok artırılırsa breakdown olur, $I_D$ kontrolden çıkar ve JFET bozulur ($V_{DS} > V_{DS\max}$) (ekrandan, 00:35:00).
- $V_{GS}$'nin etkisi
  - n-kanal JFET'te gate p tipidir. $V_{GS}$ negatif yapıldıkça (gate-source eklemi ters polarmalı) tükenme bölgesi büyür, pinch-off daha düşük $V_{DS}$'de olur ve doyum akımı $I_{DSS}$'nin altına iner (ekrandan, 01:10:00).
  - $V_{GS}$ yeterince negatif olunca $V_{DS}$ ne olursa olsun $I_D = 0$ olur. Bu gerilime $V_P$ ya da $V_{GS(\text{off})}$ denir (slayttaki örnekte $-4$ V) (ekrandan, 00:35:00).
  - Bir problemi çözmek için iki parametre gerekir: $I_{DSS}$ ve $V_P$.
- p-kanal JFET
  - Yapı aynıdır, yalnız polariteler terstir: kanal p, gate n tipidir. $V_{DS}$ negatif uygulanır; $V_{GS}$ pozitif yapıldıkça akım azalır. Hoca slayttaki artı/eksi işaretlerinin yanlış yazıldığını, şeklin doğru olduğunu belirtti.
- JFET sembolü
  - Sembolde ok her zaman n tipi bölgeyi gösterir. Ok içeri bakıyorsa n-kanal, dışarı bakıyorsa p-kanaldır (BJT'de ok emetör ucundadır ve aynı mantıkla pnp/npn ayırt edilir) (ekrandan, 00:40:00).
- Shockley denklemi ve transfer eğrisi
  - $I_D = I_{DSS}\left(1 - \dfrac{V_{GS}}{V_P}\right)^2$. JFET ve D-type MOSFET için geçerlidir, E-type MOSFET için geçerli değildir.
  - Uç noktalar: $V_{GS} = 0$ için $I_D = I_{DSS}$; $V_{GS} = V_P$ için $I_D = 0$.
  - Transfer eğrisi ($I_D$-$V_{GS}$) çıkış karakteristiğinden çizilir. Slayttaki örnek: $I_{DSS} = 8$ mA, $V_P = -4$ V; $V_{GS} = -1, -2, -3$ V için $I_D = 4{,}5;\ 2;\ 0{,}5$ mA (ekrandan, 00:45:00).
  - Çizim adımları: (1) $V_{GS} = 0$ noktasında $I_D = I_{DSS}$, (2) $I_D = 0$ noktasında $V_{GS} = V_P$, (3) aradaki eğri için birkaç $V_{GS}$ değerinde $I_D$ hesaplanır.
  - Kestirmeler: $V_{GS} = V_P/2$ ise $I_D = I_{DSS}/4$; $V_{GS} = 0{,}3V_P$ ise $I_D \approx I_{DSS}/2$. Hoca bunların ezberlenmesine gerek olmadığını, formülden çıktığını söyledi.
- Veri sayfası (datasheet) değerleri
  - JFET'in $I_{DSS}$, $V_{GS(\text{off})}$, gate-source kırılma gerilimi ve en büyük $V_{DS}$ gibi değerleri veri sayfasında yazar. Hocanın okuduğu örnekte $I_{DSS}$ en çok 5 mA, gate-source kırılması $-25$ V, en büyük drain-source gerilimi 25 V'tur. <!-- BELİRSİZ: veri sayfası slaytının karesi yok; "cut-off voltage 15" ve "15 VDC" ifadeleri doğrulanamadı. -->
  - JFET'ler BJT'ler gibi basit test cihazlarıyla test edilemez; özel FET test devreleri gerekir.
- D-type MOSFET
  - n-kanal D-type MOSFET'te drain ve source n tipidir, aralarında n-kanal vardır; ayrıca p tipi alttaş (substrate, SS) ucu bulunur. Gate, silisyum dioksit (SiO$_2$) katmanıyla kanaldan ayrılır; adı bu metal-oksit yapıdan gelir.
  - Depletion modu: $V_{GS} \le 0$ bölgesinde davranış JFET ile aynıdır, aynı Shockley denklemi geçerlidir.
  - Enhancement modu: JFET'ten farkı, n-kanalda $V_{GS} > 0$ uygulandığında da çalışması ve $I_D$'nin $I_{DSS}$'nin üstüne çıkabilmesidir. Slaytta $I_{DSS} = 8$ mA, $V_P = -6$ V; $V_{GS} = +1$ V için $I_D \approx 10{,}9$ mA (ekrandan, 00:55:00).
  - p-kanal D-type'ta polariteler terstir.
  - Sembolde ok alttaş ucundadır; n-kanalda içeri, p-kanalda dışarı bakar.
- E-type MOSFET
  - Fiziksel olarak hazır bir kanal yoktur; yine de drain ve source n tipi ise "n-kanal E-type" denir.
  - $V_{GS}$ eşik gerilimi $V_T$'yi geçene kadar $I_D = 0$'dır; $V_T$ aşılınca akım oluşur ve $V_{GS}$ arttıkça artar. n-kanalda $V_{GS}$ pozitif, p-kanalda negatif uygulanır.
  - Denklem farklıdır: $I_D = k(V_{GS} - V_T)^2$, $k = \dfrac{I_{D(\text{on})}}{(V_{GS(\text{on})} - V_T)^2}$, $V_{DS(\text{sat})} = V_{GS} - V_T$ (ekrandan, 01:00:00).
  - $k$ elemana özgü bir sabittir; ya doğrudan verilir ya da bir çalışma noktasından ($I_{D(\text{on})}$, $V_{GS(\text{on})}$) hesaplanır.
  - Sembolde kanal çizgisi kesik gösterilir (hazır kanal yok); ok yine alttaş ucundadır.
- Diğer MOSFET'ler ve statik elektrik
  - MOSFET'ler de statik elektriğe duyarlıdır; korumak için statik önleyici kılıf ya da ambalaj kullanılır.
  - VMOS (Vertical MOSFET): dikey yapısı sayesinde ısıyı daha iyi yayar, sıcaklıktan daha az etkilenir.
  - CMOS (Complementary MOSFET): bir p-kanal ve bir n-kanal MOSFET'ten oluşur. Hızlı anahtarlar, çok az güç tüketir; sayısal devrelerde, FPGA'larda ve bilgisayar sistemlerinde yaygındır.

## Hocanın Özellikle Vurguladığı Kısımlar

- FET'in temel özelliği gerilim kontrollü olmasıdır
  - Bütün FET türlerinde $I_D$'nin gerilim değişimiyle ($V_{GS}$, $V_{DS}$) değiştiği gözlenir; BJT'deki gibi bir giriş akımı yoktur.
- Polarite kuralları
  - n-kanal JFET'te drain artı, source eksi; akımı azaltmak için gate-source ters polarmalı (gate negatif) bağlanır.
- İki pinch-off
  - Birincisi $V_{GS} = 0$ iken $I_D$'nin $I_{DSS}$'ye ulaştığı $V_{DS}$ değeridir; ikincisi $V_{DS}$'den bağımsız olarak $I_D$'yi sıfırlayan $V_{GS}$ değeridir ($V_{GS(\text{off})}$). Problemlerde $I_{DSS}$ ve $V_P$ bu iki nokta üzerinden bulunur.
- JFET ile D-type MOSFET arasındaki fark
  - İkisi de aynı denklemi kullanır. Ancak n-kanal JFET'e pozitif $V_{GS}$ uygulanmaz; formül eğriyi sağa uzatabilir ama mimari buna uygun değildir. D-type MOSFET ise pozitif $V_{GS}$'de enhancement modunda çalışır. Analiz yapılırken elemanın mimarisine bakılmalıdır.
- E-type MOSFET için formül değişir
  - Shockley denklemi değil, $I_D = k(V_{GS} - V_T)^2$ kullanılır.
- Breakdown sınırı
  - $I_{DSS}$'ye ulaşıldıktan sonra $V_{DS}$'yi artırmaya devam etmek elemanı bozar; veri sayfasındaki en büyük değerler aşılmamalıdır.

## Kısa Tekrar Notları

- BJT akım kontrollü, FET gerilim kontrollüdür; FET'in giriş empedansı yüksek, BJT'nin kazancı yüksektir.
- FET türleri: JFET, D-type MOSFET, E-type MOSFET; her biri n-kanal ya da p-kanal olabilir.
- Uç karşılıkları: G ↔ B, D ↔ C, S ↔ E.
- n-kanal JFET: $V_{DS} > 0$, $V_{GS} \le 0$. p-kanal JFET: $V_{DS} < 0$, $V_{GS} \ge 0$.
- $V_{GS} = 0$ iken pinch-off'taki akım $I_{DSS}$; $I_D = 0$ yapan $V_{GS}$ ise $V_P = V_{GS(\text{off})}$.
- Shockley: $I_D = I_{DSS}(1 - V_{GS}/V_P)^2$ (JFET ve D-type MOSFET).
- $V_{GS} = V_P/2 \Rightarrow I_D = I_{DSS}/4$; $V_{GS} = 0{,}3V_P \Rightarrow I_D \approx I_{DSS}/2$.
- D-type MOSFET: depletion modu JFET gibidir; n-kanalda $V_{GS} > 0$ ile $I_D > I_{DSS}$ olabilir (enhancement modu).
- E-type MOSFET: $V_{GS} > V_T$ olmadan akım yok; $I_D = k(V_{GS} - V_T)^2$.
- Sembol: ok n tipi bölgeyi gösterir; içeri bakıyorsa n-kanal. JFET'te ok gate'te, MOSFET'te alttaş ucundadır.
- CMOS = p-kanal + n-kanal MOSFET; hızlı ve düşük güçlü anahtarlama.

## Detaylı Açıklamalar

- JFET'in çalışma mantığı
  - JFET'te akım drain ile source arasındaki kanaldan geçer. Kanalın iki yanında gate'e bağlı, kanalın tersi tipte bölgeler vardır; bu p-n eklemlerinde oluşan tükenme bölgeleri kanalın iletken genişliğini belirler. Gate-source eklemi ters polarmalandıkça tükenme bölgeleri kanalın içine doğru büyür ve kanal daralır, böylece aynı $V_{DS}$ için daha az akım geçer. Hoca bunu bir musluğa benzetti: source'tan gelen akışı gate musluk gibi kısar, akış drain'e gider.
  - $V_{GS} = 0$ iken bile $V_{DS}$ arttıkça kanalın drain tarafı daralır. Başta kanal bir direnç gibi davrandığı için akım gerilimle hemen hemen doğrusal artar (ohmik bölge). Kanal daraldıkça direnç büyür ve eğri yatıklaşır. Pinch-off noktasında kanal ince bir yola iner ve akım $I_{DSS}$ değerinde sabitlenir; bundan sonraki $V_{DS}$ artışı akımı değiştirmez (doyum bölgesi). Hocanın çizdiği grafikte $I_{DSS} = 8$ mA, $V_P \approx 4$ V'tur (ekrandan, 00:35:00).
  - Gate-source eklemine negatif gerilim uygulandığında her $V_{GS}$ için ayrı bir çıkış eğrisi çıkar: $V_{GS} = 0, -1, -2, -3$ V eğrileri sırasıyla daha düşük akımlarda doyuma ulaşır, $V_{GS} = -4$ V'ta akım sıfırdır (ekrandan, 00:35:00).
  > **Ders sonrası not:** Hoca bir yerde tükenme bölgesi büyüdükçe akımın arttığını ("hortumu sıkınca su daha hızlı akar"), bir yerde de pinch-off'ta $I_D$'nin sıfır olduğunu söyledi; hemen ardından pinch-off'taki akımın en büyük akım $I_{DSS}$ olduğunu belirtti. Doğrusu: ohmik bölgede $I_D$, $V_{DS}$ arttığı için artar; kanalın daralması akımı artırmaz, aksine direnci büyüterek eğriyi yatıklaştırır. Pinch-off'ta akım sıfır değil, $I_{DSS}$'dir. $I_D = 0$ ancak $V_{GS} = V_P$ olduğunda olur.
  > **Ders sonrası not:** Hoca $V_{GS}$ daha az negatif (örneğin $-1$ V ya da 0 V) iken breakdown'a daha erken gidileceğini söyledi. Büyük olasılıkla doğrusu terstir: kırılma, gate-drain eklemi üzerindeki ters gerilim ($V_{DG} = V_{DS} - V_{GS}$) kırılma değerine ulaşınca olur; bu yüzden $V_{GS}$ daha negatif oldukça kırılma daha düşük $V_{DS}$ değerlerinde görülür (Boylestad'daki çıkış karakteristiğinde de böyledir).
- Transfer eğrisinin kurulması
  - Transfer eğrisi, doyum bölgesindeki $I_D$ değerlerinin $V_{GS}$'ye göre çizimidir. Çıkış karakteristiğinin sağ tarafındaki her yatay eğri sola, $I_D$-$V_{GS}$ düzlemine bir nokta olarak taşınır (ekrandan, 00:45:00). Shockley denklemi bu noktaları verir: $I_{DSS} = 8$ mA ve $V_P = -4$ V için $V_{GS} = -1$ V'ta $I_D = 8(1 - 0{,}25)^2 = 4{,}5$ mA, $-2$ V'ta $8(0{,}5)^2 = 2$ mA, $-3$ V'ta $8(0{,}25)^2 = 0{,}5$ mA (python ile doğrulandı).
  - Kestirme noktalar da denklemden gelir: $V_{GS} = V_P/2$ için $(1 - 1/2)^2 = 1/4$, $V_{GS} = 0{,}3V_P$ için $(1 - 0{,}3)^2 = 0{,}49 \approx 1/2$.
- D-type MOSFET'in enhancement modu
  - D-type MOSFET'te kanal üretimde hazır olduğu için $V_{GS} = 0$'da $I_D = I_{DSS}$ akar. Negatif $V_{GS}$'de JFET gibi akım azalır. Gate kanaldan oksit katmanıyla yalıtıldığı için n-kanalda pozitif $V_{GS}$ de uygulanabilir; bu durumda akım $I_{DSS}$'nin üstüne çıkar. Slayttaki örnekte ($I_{DSS} = 8$ mA, $V_P = -6$ V): $V_{GS} = +1$ V için $I_D = 8(1 + 1/6)^2 \approx 10{,}9$ mA, $V_{GS} = -3$ V için $2$ mA, $V_{GS} = 0{,}3V_P = -1{,}8$ V için yaklaşık $3{,}9$ mA (ekrandan, 00:55:00; python ile doğrulandı).
  > **Ders sonrası not:** Hoca D-type ve E-type MOSFET'lerde "gate p tipi" dedi ve n-kanalda pozitif $V_{GS}$'yi "ters polarma" diye adlandırdı. Doğrusu: MOSFET'te gate metaldir ve SiO$_2$ ile yalıtılmıştır; p tipi olan alttaştır (substrate). JFET'te ise n-kanalda pozitif $V_{GS}$, gate-kanal eklemini doğru polarmalar; bu yüzden JFET bu bölgede kullanılmaz.
- E-type MOSFET ve $k$ sabiti
  - E-type'ta hazır kanal yoktur; n-kanalda gate'e uygulanan pozitif gerilim eşik değerini aşınca drain ile source arasında kanal oluşur. Slayttaki eğride $V_T = 2$ V ve $V_{GS} = 8$ V'ta $I_D = 10$ mA'dir; buradan $k = 10/(8-2)^2 \approx 0{,}278$ mA/V$^2$ çıkar ve $V_{GS} = 3, 4, 5, 6, 7$ V için eğrideki $0{,}28;\ 1{,}11;\ 2{,}5;\ 4{,}44;\ 6{,}94$ mA değerleri elde edilir (ekrandan, 01:00:00; python ile doğrulandı, $k$ derste hesaplanmadı).
- Özet tablo
  - Hoca son slaytta üç elemanı karşılaştırdı (ekrandan, 01:05:00): üçünde de $I_G = 0$ A ve $I_D = I_S$'dir. JFET ve D-type MOSFET için gerekli parametreler $I_{DSS}$ ve $V_P$'dir; E-type için $V_T$, $I_{D(\text{on})}$ ve $V_{GS(\text{on})}$ gerekir. JFET eğrisi $V_{GS} = 0$'da biter, D-type eğrisi pozitif $V_{GS}$'ye uzanır, E-type eğrisi $V_T$'den başlar.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
