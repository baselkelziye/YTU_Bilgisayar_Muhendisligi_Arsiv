# Ders 3 Genişletilmiş Notu: Tek Çevrimli ve Tek Düğüm Çiftli Devreler, Seri-Paralel Bağlantı, Gerilim-Akım Bölücü ve Y-Δ Dönüşümü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Kısa Tekrarı
- 2. Tek Çevrimli Devreler
- 3. Tek Düğüm Çiftli Devreler
- 4. Seri ve Paralel Elemanların Tanımı
- 5. Seri-Paralel Yapı Analizi Örnekleri
- 6. Kaynakların Seri ve Paralel Birleştirilmesi
- 7. Seri Dirençler ve Eşdeğer Direnç
- 8. Direnç Renk Kodları ve Ohmmetre ile Ölçüm
- 9. Paralel Dirençler ve Güç Dağılımı
- 10. İletkenlik ve Dualite
- 11. Seri ve Paralel Eşdeğerlik Örnekleri
- 12. Gerilim Bölücü Devreler
- 13. Akım Bölücü Devreler
- 14. Y-Δ (T-π) Dönüşümü ve Köprü Devresi
- Örnek Sorular
- Dersin Toparlaması

## 1. Önceki Dersin Kısa Tekrarı

Ders, iki şubenin ortak oturumu olduğu için önceki haftanın konularının kısa bir tekrarıyla başladı. Önceki derste bir elemanın direncinin ve öz direncin neye bağlı olduğu, ideal elemanlar olarak kısa devre ve açık devre elemanları, direncin çarpmaya göre tersi olan iletkenlik kavramı ele alınmıştı.

Güç, akım ile gerilimin çarpımıdır. Direnç elemanında Ohm yasası ($v = iR$) kullanılarak güç $p = vi = i^2R = v^2/R$ biçimlerinde de yazılabilir. Referans yönlerine dikkat edilerek hesaplanan güç negatif çıkarsa eleman devreye güç verir, pozitif çıkarsa devreden güç çeker. Bir gerilim kaynağının gücü bile pozitif çıkabilir; şarj edilen bir pil buna örnektir.

Ardından düğüm, çevre, çevrim ve yol tanımları ile Kirchhoff yasaları hatırlatıldı:

- **Kirchhoff akımlar kanunu (KCL):** Bir düğüme giren akımların toplamı çıkan akımların toplamına eşittir.
- **Kirchhoff gerilimler kanunu (KVL):** Bir çevrim boyunca bir noktadan başlayıp aynı noktaya dönüldüğünde, referans yönleri dikkate alınarak toplanan gerilim düşümleri sıfırdır.

Bu derste bu iki yasanın en basit uygulamaları olan tek çevrimli ve tek düğüm çiftli devrelerle başlanıp seri-paralel devrelere geçildi.

## 2. Tek Çevrimli Devreler

### 2.1 Tanım ve Çözüm Adımları

Tek çevrimli (single-loop) devrede yalnız bir göz vardır ve bütün elemanlar bu gözün üzerindedir. En önemli özelliği, her elemandan geçen akımın aynı olmasıdır. Tek bir kapalı yol olduğu için çözüm KVL ile yapılır.

Slayttaki adımlar (ekrandan, 00:25:00):

- Birinci adım: bilinmeyen akım için bir referans yönü varsayılır.
- İkinci adım: her direnç için bir gerilim referansı seçilir.
- Üçüncü adım: tek kapalı yola KVL uygulanır.

Gerilim kaynağının referansı zaten üzerinde işaretlidir. Hoca bunu bir voltmetre ile açıkladı: voltmetrenin artı probu kaynağın artı ucuna, eksi probu eksi ucuna bağlanırsa okunan değer $v_{s1}$ olur. Dirençler için ise referans biz seçeriz; pratik bir seçim, akımın girdiği ucu artı, çıktığı ucu eksi almaktır.

### 2.2 Örnek: İki Kaynaklı Tek Çevrim

Devre (ekrandan, 00:25:00): $v_{s1}$ kaynağı (sol kol, artı ucu üstte), üst kolda $R_1$ ve $v_{s2}$ kaynağı (artı ucu solda), sağ kolda $R_2$. Akım saat yönünde seçilmiştir.

Akım yönünde dolaşırken:

- $v_{s1}$'e eksi ucundan girilir: $-v_{s1}$.
- $R_1$'in artısından eksisine geçilir: $+v_{R1}$.
- $v_{s2}$'nin artısından girilir: $+v_{s2}$.
- $R_2$'nin artısından eksisine geçilir: $+v_{R2}$.

$$-v_{s1} + v_{R1} + v_{s2} + v_{R2} = 0$$

Bu denklemde üç bilinmeyen var gibi görünür ($v_{R1}$, $v_{R2}$, $i$). Ohm yasasıyla $v_{R1} = R_1 i$ ve $v_{R2} = R_2 i$ yazılınca tek bilinmeyen kalır:

$$-v_{s1} + R_1 i + v_{s2} + R_2 i = 0 \quad\Rightarrow\quad i = \frac{v_{s1}-v_{s2}}{R_1+R_2}$$

Cebirsel çözümde akım negatif çıkabilir. Bu, akımın seçilen yönün tersine aktığı anlamına gelir. Yön değiştirmeye gerek yoktur; "verilen yönde negatif akım" olarak kullanılır. Aynı şekilde bir direncin gerilimi de seçilen referansta negatif çıkabilir.

> **Hocanın vurgusu:** Referans akım ve gerilim yönleri bir kez sabitlenir. Sonra denklem yazılır, cebirsel çözüm yapılır ve bulunan değerler (negatif olsalar bile) doğrudan kullanılır.

### 2.3 Kapalı Sistemde Güç Dengesi

Devrenin etrafına bir sınır çizildiğinde bu sınırdan içeri ya da dışarı bir kaynak ya da akım girişi yoksa sistem kapalıdır. Kapalı sistemde üretilen ve tüketilen güçler eşittir; yani bütün elemanların güçleri toplandığında sıfır elde edilir. Bu, bir elemanın gücünü bilmediğimizde kullanılabilir: diğerlerinin güçleri biliniyorsa eksik güç bulunur; eleman bir dirençse ve $R$ biliniyorsa buradan akımı ve gerilimi de elde edilir.

### 2.4 Örnek: Bağımlı Kaynaklı Tek Çevrim

Devre (ekrandan, 00:35:00): Sol kolda 120 V kaynak (artı ucu üstte), üst kolda 30 Ω direnç ve gerilim kontrollü gerilim kaynağı $2v_A$ (artı ucu solda), sağ kolda 15 Ω direnç. 15 Ω üzerindeki $v_A$ geriliminin referansı alt uç artı, üst uç eksi olacak şekilde tanımlıdır. Akım saat yönündedir. Soru: her elemanın çektiği gücü bulun.

Bağımlı kaynak, devrenin başka bir yerindeki gerilime ($v_A$) bağlı olarak uçlarında gerilim oluşturur. Akım yönünde KVL:

$$-120 + v_{30} + 2v_A - v_A = 0$$

15 Ω'da akım, gerilim referansının eksi ucundan girdiği için $-v_A$ yazıldı. Yine üç bilinmeyen var gibidir ($v_{30}$, $v_A$, $i$), ama tek çevrimde akım ortaktır:

- $v_{30} = 30i$
- Akım yönünde 15 Ω'a voltmetre bağlansa (artı prob akımın girdiği uca) okunan değer $-v_A$ olur ve bu $15i$'ye eşittir. Yani $v_A = -15i$.

$$-120 + 30i - 30i + 15i = 0 \quad\Rightarrow\quad i = 8 \text{ A}$$

Güçler (ekrandan, 00:35:00):

| Eleman | Hesap | Güç |
|---|---|---|
| 120 V kaynak | $(120)(-8)$ | $-960$ W (güç veriyor) |
| 30 Ω | $(8)^2(30)$; ya da $v_{30}=240$ V, $240 \cdot 8$ | $1920$ W |
| Bağımlı kaynak | $(2v_A)(8) = 2[(-15)(8)](8)$ | $-1920$ W (güç veriyor) |
| 15 Ω | $(8)^2(15)$; ya da $-i\,v_A = -(8)(-120)$ | $960$ W |

Toplam: $-960 + 1920 - 1920 + 960 = 0$. Kapalı sistemde güç dengesi sağlanır.

> **Hocanın vurgusu:** Direnç elemanının gücü her zaman pozitif çıkmalıdır; bunu baştan bilmek kendimizi kontrol etmemizi sağlar. $i^2R$ ile hesaplanırsa akımın yönü ne olursa olsun kare alındığı için sonuç zaten pozitif gelir.

## 3. Tek Düğüm Çiftli Devreler

### 3.1 Düğüm Kavramı ve Referans Düğüm

Düğüm, bir kablo üzerinde bir sonraki elemana kadar uzanan bölgedir. Şemada farklı yerlerde nokta olarak işaretlenmiş olsalar bile aynı kablo üzerinde, araya eleman girmeden ulaşılan bütün noktalar tek bir düğümdür.

Slayttaki devrede (ekrandan, 00:40:00) dört eleman (120 A kaynak, $\tfrac{1}{30}\,\Omega$ direnç $R_1$, 30 A kaynak, $\tfrac{1}{15}\,\Omega$ direnç $R_2$) üstte ve altta birer ortak düğüme bağlıdır. Hoca üst düğümü kırmızıyla, alt düğümü yeşille işaretledi. Düğümlerden biri referans seçilir ve 0 V kabul edilir; diğer düğüm gerilimleri buna göre tanımlanır. Pratikte devredeki en büyük kaynağın eksi ucu referans seçilebilir. Alt düğüm 0 V olunca geriye tek bilinmeyen düğüm, yani tek bilinmeyen gerilim kalır.

Birbirine paralel çok sayıda elemandan oluşan bu tür devrelere tek düğüm çiftli (single-node-pair) devre denir. Slayttaki ifade: KVL, her koldaki gerilimin diğer kollardakiyle aynı olmasını zorunlu kılar; ortak gerilimi taşıyan elemanlar paralel bağlıdır. Çözüm KCL ile yapılır.

### 3.2 Örnek: İki Akım Kaynaklı Tek Düğüm Çifti

Soru (ekrandan, 00:45:00): Aşağıdaki devrede her elemanın gerilimini, akımını ve gücünü bulun.

Devre: soldan sağa 120 A kaynak (yukarı yönlü), $R_1 = \tfrac{1}{30}\,\Omega$ (akımı $i_1$ aşağı), 30 A kaynak (aşağı yönlü), $R_2 = \tfrac{1}{15}\,\Omega$ (akımı $i_2$ aşağı). Ortak gerilim $v$, üst düğüm artı.

Akım kaynaklarının akım yönü kaynağın okuyla verilir. Üst düğümde çıkan akımlar artı, giren akımlar eksi alınarak:

$$-120 + i_1 + 30 + i_2 = 0$$

Tersini de seçmek mümkündü; yalnız denklemin iki tarafı yer değiştirir. Paralel elemanların gerilimi aynıdır:

- $i_1 = \dfrac{v}{R_1} = \dfrac{v}{1/30} = 30v$
- $i_2 = \dfrac{v}{1/15} = 15v$

$$-120 + 30v + 30 + 15v = 0 \quad\Rightarrow\quad 45v = 90 \quad\Rightarrow\quad v = 2 \text{ V}$$

Buradan $i_1 = 60$ A, $i_2 = 30$ A.

Güçler (ekrandan, 00:45:00):

| Eleman | Hesap | Güç |
|---|---|---|
| $R_1$ | $30(2)^2$ | $120$ W |
| $R_2$ | $15(2)^2$ | $60$ W |
| 120 A kaynak | $120(-2)$ | $-240$ W (güç veriyor) |
| 30 A kaynak | $30(2)$ | $60$ W (güç çekiyor) |

120 A kaynağın akımı, akım yönünde $-v$ kadar bir gerilim düşümü üzerinden akar; bu yüzden güç negatiftir. 30 A kaynağın akımı ise pozitif bir gerilim düşümü üzerinden akar; akım kaynağı olmasına rağmen devreden güç çeker. Toplam: $120 + 60 - 240 + 60 = 0$.

### 3.3 Örnek: Bağımlı Akım Kaynaklı Tek Düğüm Çifti

Soru (ekrandan, 00:50:00): Tek düğüm çiftli devrede $i_A$, $i_B$ ve $i_C$'yi bulun.

Devre: soldan sağa 5.6 A kaynak (yukarı), 18 Ω ($i_A$ aşağı), gerilim kontrollü akım kaynağı $0.1v_x$ (yukarı yönlü ok; kol akımı $i_B$ aşağı tanımlı), 9 Ω ($i_C$ aşağı), 2 A kaynak (aşağı). Ortak gerilim $v_x$, üst düğüm artı.

Bağımlı kaynak, her elemandaki ortak gerilimin 0.1 katı kadar akım verir. Üst düğüme giren akımlar artı, çıkanlar eksi alınarak KCL:

- 5.6 A giriyor: $+5.6$
- $i_A = v_x/18$ çıkıyor: $-v_x/18$
- $i_B$ aşağı tanımlı, çıkan yönde olduğu için $-i_B$ yazılmalıdır. Kaynağın oku yukarı olduğundan $i_B = -0.1v_x$, yani $-i_B = +0.1v_x$.
- $i_C = v_x/9$ çıkıyor: $-v_x/9$
- 2 A çıkıyor: $-2$

$$5.6 - \frac{v_x}{18} + 0.1v_x - \frac{v_x}{9} - 2 = 0 \quad\Rightarrow\quad v_x = 54 \text{ V}$$

Kol akımları:

- $i_A = 54/18 = 3$ A
- $i_B = -0.1 \cdot 54 = -5.4$ A
- $i_C = 54/9 = 6$ A

Sağlama: $5.6 = i_A + i_B + i_C + 2 = 3 - 5.4 + 6 + 2 = 5.6$.

**Soru:** Bağımlı akım kaynağından gelen akım hesaba katılmıyor mu? **Cevap:** Katılıyor. O kolda tanımlanan $i_B$ akımı yalnız ve yalnız bağımlı kaynak tarafından oluşturulur. Kolun içinde ne olduğunu görmediğimizi düşünüp aşağı yönlü bir $i_B$ tanımladık; sonra elemanın, ok yönü yukarı olan bir akım kaynağı olduğunu gördük. Genliği $0.1v_x$, yönü $i_B$'ye ters olduğu için $i_B = -0.1v_x$ olur ve KCL'ye bu şekilde girer.

## 4. Seri ve Paralel Elemanların Tanımı

### 4.1 Seri Elemanlar

Üzerinden aynı akım geçen elemanlar seridir. Daha biçimsel tanım: iki eleman, yalnız ikisi tarafından paylaşılan ortak bir düğüme sahipse seridir.

Örneğin 60 V kaynak ile 8 Ω direnç tek ve yalnız kendi aralarında paylaşılan bir düğüme bağlıysa seridir. 8 Ω ile 4 Ω arasındaki düğüme başka bir eleman da bağlıysa bu ikisi seri değildir. Benzer şekilde bir devrede R3 ile 36 V kaynak yalnız ikisinin paylaştığı bir düğüme sahipse seridir; ama ikiden fazla elemanın bağlı olduğu bir düğüm üzerinden komşu olan elemanlar (örneğin 36 V kaynak ile R2, R2 ile R4) seri değildir.

### 4.2 Paralel Elemanlar

Üzerlerindeki gerilim aynı olan elemanlar paraleldir. Biçimsel tanım: iki elemanın her iki ucu da ortak düğümlere bağlıysa, ancak ve ancak o zaman paraleldir. Gösterim: $R_1 \parallel 120\text{ A}$.

Slayttaki tek düğüm çiftli devrede (ekrandan, 00:55:00) herhangi iki eleman seçildiğinde ikisi de aynı iki uç düğümü paylaşır; bu yüzden 120 A kaynak, $\tfrac{1}{30}\,\Omega$ direnç, 30 A kaynak ve $\tfrac{1}{15}\,\Omega$ direncin hepsi birbirine paraleldir ($R_1 \parallel 120 \parallel 30$ ...).

## 5. Seri-Paralel Yapı Analizi Örnekleri

### 5.1 Alt Devre Bloğunu Tek Eleman Gibi Görmek

Daha karmaşık devrelerde her eleman birbirine paralel değildir. Hoca şu mantığı kullandı: seri olan bir grup, tek bir "fasulye elemanı" (iki uçlu sanal bir eleman) gibi düşünülür, sonra bu elemanın diğerleriyle ilişkisine bakılır.

Örnekte bir yolda 2 Ω direnç ile $i_x$ akım kaynağı aynı iki düğümü paylaştığı için paraleldir. 60 V kaynak ile 8 Ω direnç yalnız kendilerinin paylaştığı bir düğüme sahip olduğu için seridir. Bu ikili tek bir eleman yerine konulursa, bu eleman 10 Ω dirençle iki ortak düğüm paylaşır ve 10 Ω'a paralel olur. 10 Ω ile 2 Ω ise bir ortak düğüme sahiptir, ama ikinci ortak düğümü aradaki 4 Ω'luk eleman engellediği için paralel değildir.

İkinci örnekte 40 Ω ile 20 Ω seridir; bu seri grup başka bir dirence paraleldir; oluşan büyük kapalı grup 2 Ω'a seridir; bunların tamamı 50 Ω'a, o da 125 Ω'a paraleldir; en sonunda hepsi 120 mA kaynağa paraleldir.

<!-- BELİRSİZ: 00:55-00:59 arasındaki bu iki devrenin tam şeması karelerde yok; eleman yerleri ve "240 ohm" diye geçen değer altyazıdan kesin çıkarılamadı. -->

### 5.2 Kısa Devre İçeren Örnek

Soru (ekrandan, 01:00:00): Aşağıdaki devrede (a) hangi tekil elemanlar seri/paraleldir, (b) hangi eleman grupları seri/paraleldir?

Devre (ekrandan, 01:00:00):

| Konum | Eleman |
|---|---|
| Sol kol (alt düğüm - sol üst) | 2 A akım kaynağı (yukarı) |
| Üst, sol | 1.5 Ω (sol üst köşe ile X düğümü arası) |
| X düğümünden alt düğüme | 4 Ω |
| Üst, orta | 2 Ω (X ile Y düğümleri arası); üstünden X ile Y'yi doğrudan birleştiren bir kablo geçer |
| Y düğümünden alt düğüme | 4 Ω |
| Üst, sağ | Y'den sonra ucu boşta kalan kısa bir kablo çıkıntısı, ardından 5 Ω |
| Sağ kol (sağ üst - alt düğüm) | 5 A akım kaynağı (yukarı) |

2 Ω'luk direncin iki ucu bir kabloyla bağlanmıştır. Bu durumda direnç üzerinde gerilim düşümü yoktur, iki ucunun gerilimi eşittir; gerilim olmayan elemandan akım da akmaz. Direnç devreden koparılmış gibi düşünülebilir ve X ile Y aynı düğüm olur.

Analiz:

- Sağ taraf: 5 A kaynak ile 5 Ω yalnız ikisinin paylaştığı bir düğüme sahip olduğu için seridir; bu seri kol sağdaki 4 Ω'a paraleldir.
- Sol taraf: 2 A kaynak ile 1.5 Ω seridir (şemaya göre); bu kol soldaki 4 Ω'a paraleldir.
- Sol blok (A) ile sağ blok (B) kısa devre üzerinden üstte, alt kabloyla da altta ortak düğüm paylaşır; bu yüzden A ile B paraleldir.
- 5 Ω'un yanındaki çıkıntı hiçbir yere bağlı değildir; topolojiyi değiştirmez.

Kısa devre olmasaydı A ile B arasında 2 Ω seri kalırdı (A seri 2 Ω seri B gibi).

**Soru:** Yalnız iki eleman kaldığında bunlar seri mi, paralel mi? **Cevap:** İki eleman tek bir kapalı halka oluşturduğunda ikisi hem ortak düğümler paylaşır hem aynı akımı taşır; "A, B'ye seridir" de "A, B'ye paraleldir" de aynı hesaba çıkar. Hangisinin söyleneceği bakılan uçlara bağlıdır: ortak iki düğüm arasından bakılıyorsa paralel, halkanın bir kolunun ortasından açılan uçlardan bakılıyorsa seri görülür. Hoca bu "bakış yönü" konusunun Thevenin ve Norton eşdeğerlerinde daha net oturacağını söyledi.

### 5.3 Grup Gösterimi Örneği

Bir sonraki örnekte (01:05 civarı) 6 Ω ile 3 Ω iki ortak düğüm paylaştığı için paraleldir ve A grubunu oluşturur. A grubu 5 Ω ve 3 Ω ile seridir. Diğer tarafta 3 Ω ile 9 Ω paraleldir ve B grubunu oluşturur. A, 3 Ω, 5 Ω ve B birbirine seridir; bunların tamamı C grubudur. C grubu 5 Ω'a, 3 Ω'a ve 1 A kaynağa paraleldir.

<!-- BELİRSİZ: Bu örneğin şeması karede yok; eleman değerleri ve grupların tam yerleri yalnız altyazıdan alındı. -->

## 6. Kaynakların Seri ve Paralel Birleştirilmesi

### 6.1 Seri Gerilim Kaynakları

A ve B düğümleri arasında seri bağlı birkaç gerilim kaynağı tek bir eşdeğer kaynakla değiştirilebilir. Koşul: A-B arasındaki gerilim farkı her iki durumda aynı olmalıdır. Örneğin bir düğüm bir sonrakine göre $v_1$, o da bir sonrakine göre $v_2$ kadar yüksek potansiyeldeyse, ters bağlı bir $v_3$ kaynağı da $-v_3$ katkı verir. Eşdeğer kaynak:

$$v_{eq} = v_1 + v_2 - v_3$$

Yani seri gerilim kaynakları referans yönlerine göre cebirsel toplanır. Diğer elemanlar değişmediği sürece akım da aynı kalır.

Günlük hayattan örnek (ekrandan, 01:25:00): Bir kumandaya kalem piller bir ileri bir geri yönde yerleştirilir ve metal plakalarla birbirine seri bağlanır. Dört adet 1.5 V AAA pil seri bağlanınca 6 V elde edilir. Slayta göre gerilim artmıştır, ama her pilin ve 6 V kaynağın maksimum akımı aynıdır; kullanılabilir güç uç gerilimindeki artış nedeniyle 4 katına çıkar.

### 6.2 Örnek: Dağınık Seri Kaynakların Birleştirilmesi

Devre (ekrandan, 01:30:00), şekil (a): tek gözlü devrede sol kolda üstte 9 V (artı üstte) ve altta 3 V (artı üstte); üst kolda 100 Ω; sağ kolda 5 V (artı altta); alt kolda 220 Ω ve 1 V (artı sağda). Akım $i$ saat yönünde.

Kaynaklar doğrudan peş peşe bağlı değildir, ama tek gözlü devrede bir kaynakla bir direncin yeri değiştirilirse ana kol akımı değişmez. Bu yüzden kaynaklar bir yere toplanabilir. (Tek tek elemanların düğüm gerilimleri değişebilir; burada yalnız ana kol akımı için eşdeğer kuruluyor.)

Akım yönünde KVL (ekrandan, 01:30:00):

$$-3 - 9 + 100i - 5 + 1 + 220i = 0 \quad\Rightarrow\quad i = \frac{16}{320} = 50 \text{ mA}$$

Kaynakların net katkısı $-3-9-5+1 = -16$ V'tur. Yani akım yönünde eksisinden girilen 16 V'luk tek bir kaynak eşdeğerdir. Şekil (b)'de bu kaynak sol kola (artı üstte), şekil (c)'de sağ kola (artı altta) konmuştur; akım yönüne göre her iki durumda da kaynağa eksisinden girilir:

$$-16 + 100i + 220i = 0 \quad\Rightarrow\quad i = 50 \text{ mA}$$

Slayttaki not: dirençlerin akımı ve harcadığı güç (a), (b) ve (c)'de aynıdır; ancak her gerilim kaynağının verdiği gücü bulmak için kaynakların eşdeğerden ayrılıp orijinal devreye dönülmesi gerekir.

### 6.3 Paralel Gerilim Kaynakları

Farklı değerli gerilim kaynakları paralel bağlanamaz; ideal kaynaklar için bu ancak değerler eşitse geçerlidir. Paralel elemanların gerilimi eşit olmak zorundadır, oysa farklı kaynaklar kendi gerilimlerini zorlar ve topoloji bozulur.

Gerçek kaynaklarda farklı değerli iki kaynak paralel bağlanabilir. Bu durumda gerilimi yüksek olandan diğerine bir akım akar; kaynakların iç dirençleri üzerinden akan bu akım, iki kaynağın uç gerilimleri eşitlenene kadar artar. Devreden ayrıldıklarında gerilimleri farklıdır, devrede ise eşit görünürler. Bu arada devrenin geri kalanında değil, iki kaynağın iç dirençlerinde harcanan bir akım oluşur.

### 6.4 Paralel Akım Kaynakları

Aynı iki düğüm arasındaki paralel akım kaynakları tek bir eşdeğer kaynakla değiştirilebilir. Eşdeğer kaynağın yönü seçilir; o yöndekiler artı, ters yöndekiler eksi toplanır. Örneğin $i_1$ ve $i_3$ düğüme giriyor, $i_2$ çıkıyorsa, $i_2$ yönünde bir eşdeğer kaynak $i_2 - i_1 - i_3$ olur; ters yönde seçilirse $i_1 + i_3 - i_2$ olur. Bu, akımın yönü değiştirildiğinde cebirsel değerinin negatifinin yazılması kuralının aynısıdır.

### 6.5 Örnek: Dağınık Paralel Akım Kaynakları

Devre (ekrandan, 01:35:00), şekil (a): soldan sağa 2.5 A (yukarı), 5 Ω (ortak gerilim $v$, üst düğüm artı), 2.5 A (aşağı), 5 Ω, 3 A (aşağı). Hepsi aynı iki düğüm arasındadır.

Paralel elemanların yeri değiştirildiğinde topoloji değişmez; kaynaklar yan yana getirilebilir.

- Yukarı yönlü eşdeğer: $2.5 - 2.5 - 3 = -3$ A (şekil (b): $-3$ A yukarı, iki 5 Ω).
- Aşağı yönlü eşdeğer: $2.5 + 3 - 2.5 = 3$ A (şekil (c): 3 A aşağı, iki 5 Ω arasında).

Çözüm (ekrandan, 01:35:00):

$$\text{(a)}\quad 2.5 - \frac{v}{5} - 2.5 - \frac{v}{5} - 3 = 0 \quad\Rightarrow\quad v = -7.5 \text{ V}$$

$$\text{(b,c)}\quad -3 - \frac{v}{5} - \frac{v}{5} = 0 \quad\Rightarrow\quad v = -7.5 \text{ V}$$

İki 5 Ω eşit olduğu için kol akımları da eşittir ($i_1 = i_2 = -v/5$ ile tanımlanan yönlerde); $v$ bulunduktan sonra kol akımları hesaplanır.

Özetle: bir çevrede seri gerilim kaynaklarının net toplamı tek eşdeğer gerilim kaynağını, iki düğüm arasındaki paralel akım kaynaklarının net toplamı tek eşdeğer akım kaynağını verir. Topolojiyi bozmadan elemanların yerini değiştirmek çözümü kolaylaştırır.

## 7. Seri Dirençler ve Eşdeğer Direnç

### 7.1 Türetme

Bir gerilim kaynağı $v_s$ ile sürülen ve N adet seri dirençten oluşan tek çevrimde KVL:

$$-v_s + v_1 + v_2 + \dots + v_N = 0$$

Seri devrede her direnden aynı $i$ akımı geçtiği için $v_k = iR_k$:

$$v_s = i(R_1 + R_2 + \dots + R_N) \quad\Rightarrow\quad \frac{v_s}{i} = \sum_{k=1}^{N} R_k$$

Amaç, bu dirençleri kapsayan kutunun yerine tek bir $R_{eq}$ koymaktır. Eşdeğerlik için kutunun uçlarındaki gerilim ve kutuya giren akım iki durumda da aynı olmalıdır. Aynı kaynak kullanıldığı için gerilim zaten aynıdır; tek dirençli devrede $v_s = iR_{eq}$, yani $R_{eq} = v_s/i$. İki ifade eşitlenince:

$$R_{eq} = \sum_{k=1}^{N} R_k$$

### 7.2 Eşdeğerlik Hangi Uçlardan Bakıldığına Bağlıdır

Hoca tahtaya üç dirençli bir halka çizdi: 10 Ω, 10 Ω ve 20 Ω (ekrandan, 01:45:00).

- Kaynak 20 Ω'un iki ucuna uygulanırsa: iki 10 Ω seri olur (20 Ω) ve bu 20 Ω'a paralel görülür: $20 \parallel 20$.
- Kaynak bir 10 Ω'un iki ucuna uygulanırsa: 10 Ω ile 20 Ω seri olur (30 Ω) ve bu diğer 10 Ω'a paralel görülür: $30 \parallel 10$.

> **Hocanın vurgusu:** Devre topolojisi aynı kalsa bile bakılan ya da kaynağın uygulandığı uçlar kimin kime seri, kimin kime paralel olduğunu ve dolayısıyla eşdeğer direnci değiştirir.

Slayttaki ifade (ekrandan, 01:45:00): bir DC kaynak bağlandığında elemanların tek tek bağlantısını değil, yalnız bağlantı uçlarından görülen toplam direnci görür. Örnek: a-b uçlarından bakıldığında 10 Ω, 30 Ω ve 100 Ω seri dizi $R_T = 140$ Ω'dur.

## 8. Direnç Renk Kodları ve Ohmmetre ile Ölçüm

### 8.1 Renk Kodları

Fiziksel bir direnç iki uçlu bir elemandır ve üzerindeki renk bantları değerini gösterir. Dört bantlı dirençte ilk iki bant iki basamaklı sayıyı, üçüncü bant $10^n$ çarpanını, dördüncü bant toleransı verir. Tolerans bandı genelde altın ya da gümüş renklidir ve diğer bantlardan biraz uzaktadır. Örneğin %10 toleranslı 10 Ω'luk bir direncin değeri 9 Ω ile 11 Ω arasında olabilir.

Renk-rakam karşılıkları (ekrandan, 01:50:00):

| Renk | Rakam | Çarpan |
|---|---|---|
| Siyah | 0 | $10^0$ |
| Kahverengi | 1 | $10^1$ |
| Kırmızı | 2 | $10^2$ |
| Turuncu | 3 | $10^3$ |
| Sarı | 4 | $10^4$ |
| Yeşil | 5 | $10^5$ |
| Mavi | 6 | $10^6$ |
| Mor | 7 | |
| Gri | 8 | |
| Beyaz | 9 | |
| Altın | | $0.1$ (tolerans ±%5) |
| Gümüş | | $0.01$ (tolerans ±%10) |

Örnekler:

- Kahverengi (1), kırmızı (2), yeşil ($10^5$): $12 \times 10^5 = 1.2$ MΩ (ekrandan, 01:50:00).
- 1 kΩ $= 10 \times 10^2$: kahverengi, siyah, kırmızı.
- 10 kΩ $= 10 \times 10^3$: kahverengi, siyah, turuncu.

**Soru:** Dirençte 5 ya da 6 bant varsa nasıl okunur? **Cevap:** Okuma farklıdır. Beş bantlı dirençte ilk üç bant üç basamaklı sayıyı oluşturur, ardından çarpan gelir. Bu derste yalnız dört bantlı okuma ele alındı.

### 8.2 Ohmmetre ile Seri Direnç Ölçümü

Direnç yönsüz bir elemandır; tolerans ucu hangi tarafa gelirse gelsin değeri değişmez. Dirençler tek bir düğüm paylaşacak şekilde uç uca bağlanınca seri bağlantı oluşur. Multimetre direnç ölçme moduna alınıp kırmızı prob bir uca, siyah prob diğer uca bağlanırsa 10 Ω + 30 Ω + 100 Ω dizisi için 140 Ω okunur. Problar yer değiştirilse de dirençler yönsüz olduğu için yine 140 Ω okunur.

### 8.3 Seri Devrede Güç Dağılımı

Slayttaki bilgi (ekrandan, 01:55:00): Dirençlerden oluşan bir devrede bataryanın verdiği güç, dirençlerde harcanan güçlerin toplamına eşittir:

$$P_E = P_{R_1} + P_{R_2} + P_{R_3}, \qquad P_1 = V_1I_1 = I_1^2R_1 = \frac{V_1^2}{R_1}$$

Seri devrede bütün dirençlerden aynı akım geçtiği için her direncin gücü $I^2R$ ile bulunur. Slayttaki sonuç: seri direnç ağında direnç ne kadar büyükse çektiği güç o kadar fazladır.

> **Ders sonrası not:** Hoca, seri devrede harcanan gücün direnç değerinin karesiyle orantılı arttığını söyledi ve tahtaya $I\,R^2$ biçiminde yazdı; doğrusu $P = I^2R$'dir. Akım ortak olduğu için güç direnç değeriyle doğru (doğrusal) orantılıdır, karesiyle değil.

## 9. Paralel Dirençler ve Güç Dağılımı

### 9.1 Türetme

N adet paralel direnç bir kutuya alınır ve kutunun uçlarına bir $I_s$ akım kaynağı bağlanır. Kutunun yerine konan $R_{eq}$ ile uçlarda aynı $V$ gerilimi görülüyorsa iki kutu eşdeğerdir. Akım kaynağıyla beslemenin nedeni, kol akımlarının toplamının kaynak akımına eşit olmasının hesapta pratik olmasıdır; gerilim kaynağıyla da aynı sonuca ulaşılır, ama hesap daha dolambaçlı olur.

KCL ile:

$$I_s = I_1 + I_2 + \dots + I_N$$

Bütün elemanların gerilimi $V$ olduğu için $I_k = V/R_k$:

$$I_s = V\left(\frac{1}{R_1} + \frac{1}{R_2} + \dots + \frac{1}{R_N}\right)$$

Tek dirençli durumda $I_s = V/R_{eq}$, yani $I_s/V = 1/R_{eq}$. Eşitlenince:

$$\frac{1}{R_{eq}} = \sum_{k=1}^{N} \frac{1}{R_k}$$

### 9.2 Ohmmetre ile Paralel Direnç Ölçümü

Slayttaki örnek (ekrandan, 02:00:00): 1 kΩ, 2.2 kΩ ve 1.2 kΩ paralel bağlı dirençlere ohmmetre bağlandığında $R_T = 437.1$ Ω okunur. Bu, formülle hesaplanan eşdeğerin aynısıdır.

Dikkat edilecek nokta: bu ölçüm sırasında devrede enerji olmamalı, yani kaynak bağlı olmamalıdır. Gerçek (ideal olmayan) gerilim kaynağının seri bir iç direnci vardır; kaynak bağlıyken ölçülürse aslında dirençlerin paraleline bu iç direncin de eklendiği bir eşdeğer ölçülür. Slayttaki ifadeyle ohmmetre hiçbir zaman canlı devreye uygulanmaz. Direnç yönsüz olduğu için ohmmetrenin uçları ters de bağlanabilir.

### 9.3 Paralel Devrede Güç Dağılımı

Paralel elemanların gerilimi aynı olduğu için güç $P = V^2/R$ ile yazılır:

$$P_1 = \frac{V^2}{R_1},\quad P_2 = \frac{V^2}{R_2},\quad P_3 = \frac{V^2}{R_3}$$

Paralel devrede güç direnç değeriyle ters orantılıdır: büyük dirençte daha az güç harcanır. Bu, akımın direnci düşük olan kolu tercih etmesiyle de uyumludur. Paralel bağlantıyı göstermek için iki dik çizgi ($\parallel$) kullanılır.

## 10. İletkenlik ve Dualite

İletkenlik direncin çarpmaya göre tersidir: $G = 1/R$. Ohm yasası $i = Gv$ biçiminde de yazılabilir.

### 10.1 Seri İletkenlikler

Tek çevrimde her elemandan aynı akım geçer ve KVL ile $v_{in} = v_1 + v_2$. $v_k = i/G_k$ yazılınca:

$$\frac{v_{in}}{i} = \frac{1}{G_1} + \frac{1}{G_2}$$

Tek eşdeğer iletkenlikte $v_{in}/i = 1/G_{eq}$ olduğundan, genel olarak:

$$\frac{1}{G_{eq}} = \sum_{k=1}^{N} \frac{1}{G_k}$$

Seri iletkenliklerin eşdeğeri, paralel dirençlerin eşdeğeriyle aynı biçimde hesaplanır.

### 10.2 Paralel İletkenlikler

Paralel iki iletkenliğe $i_{in}$ akım kaynağı bağlansın. Gerilimler eşit olduğu için $vG_1 + vG_2 = i_{in}$, yani $i_{in}/v = G_1 + G_2$. Tek eşdeğer iletkenlikte $i_{in}/v = G_{eq}$ olduğundan:

$$G_{eq} = \sum_{k=1}^{N} G_k$$

Paralel iletkenliklerin eşdeğeri, seri dirençlerin eşdeğeriyle aynı biçimdedir. Bu karşılıklılığa dualite denir. Güç de iletkenlikle $P = V^2G$ ya da $P = I^2/G$ biçiminde yazılabilir. Hoca, hangi terimin hangisine karşılık geldiğini özetleyen slayt tablosunun başvuru için saklanabileceğini söyledi.

> **Ders sonrası not:** Hoca tekrar sırasında seri bağlı iletkenliklerin eşdeğerinin "geometrik ortalama" ile bulunduğunu söyledi. Doğrusu yukarıda türetilen terslerin toplamı kuralıdır: $1/G_{eq} = \sum 1/G_k$ (iki eleman için $G_1G_2/(G_1+G_2)$). Bu geometrik ortalama değildir.

## 11. Seri ve Paralel Eşdeğerlik Örnekleri

### 11.1 Örnek: Seri Devrede Kaynak Gücü

Seri elemanlardan oluşan bir devrede 80 V kaynağın gücünün olabildiğince pratik bulunması isteniyor. Önce kaynaklar bir araya toplanır (kaynak ve direncin yeri değiştirilince topoloji bozulmaz), kalan dirençler de seri olduğu için toplanır.

- Kaynaklar akım yönünde: $-80 - 30 + 20 = -90$ V; yani akım yönünde eksisinden girilen 90 V'luk tek bir eşdeğer kaynak.
- Dirençlerin toplamı: 30 Ω.
- Ana kol akımı: $i = 90/30 = 3$ A.
- 80 V kaynağın gücü: akım yönünde $-80$ V'luk bir gerilim düşümü üzerinden 3 A geçer; $p = (-80)(3) = -240$ W. Kaynak devreye 240 W verir.

<!-- BELİRSİZ: Bu örneğin şeması karede yok; tek tek direnç değerleri altyazıda bozuk geçiyor ("10, 17, 22"), yalnız toplamın 30 Ω olduğu kesin. -->

### 11.2 Örnek: Paralel Devrede Kol Akımı

Paralel elemanlardan ve paralel akım kaynaklarından oluşan bir devrede 10 Ω'luk dirençlerden akan akım isteniyor.

- Kaynaklar yukarı yönlü tek eşdeğerde toplanır: aynı yönlü 5 A ve 6 A artı, ters yönlü kaynak eksi; sonuç yukarı yönlü 10 A.
- İki 10 Ω paralel: $\dfrac{1}{R_{eq}} = \dfrac{1}{10} + \dfrac{1}{10}$, $R_{eq} = 5$ Ω. Eşit dirençler paralelken eşdeğer, direnç değerinin eleman sayısına bölümüdür.
- Gerilim: $10 \text{ A} \times 5\,\Omega = 50$ V.
- Her 10 Ω'dan geçen akım: $50/10 = 5$ A; 10 A iki kola eşit paylaşılır.

<!-- BELİRSİZ: Bu örneğin şeması karede yok; ters yönlü kaynağın değeri altyazıda geçmiyor (10 A sonucuna göre 1 A olmalı, ara adım eklendi). -->

### 11.3 Aynı Değerli Dirençler

Soru (ekrandan, 02:25:00): Aynı değerli dirençlerde (a) seri direnç sayısı artırıldıkça, (b) paralel direnç sayısı artırıldıkça $R_{eq}$ artar mı, azalır mı?

Seride eleman sayısı arttıkça eşdeğer direnç artar, paralelde azalır.

## 12. Gerilim Bölücü Devreler

### 12.1 Mantık

Seri dirençler toplam gerilimi direnç değerleriyle doğru orantılı paylaşır: direnci büyük olan, toplam gerilimin daha büyük bir kısmını üzerinde düşürür. Bu, gerilim bölücü olarak kullanılır: devrenin bir kısmı için belirli bir gerilim gerekiyorsa uygun değerli iki seri dirençle elde edilebilir. Formül seri devrede gerilim düşümü hesabından gelir ve N direnç için genelleştirilebilir:

$$V_k = \frac{R_k}{R_1 + R_2 + \dots + R_N}\,V$$

### 12.2 Ölçüm Örneği

Kurulum (ekrandan, 02:30:00): Bir güç kaynağı 8.40 V gerilim veriyor (akım göstergesi 60.0 mA). Kaynak 10 Ω ($R_1$), 30 Ω ($R_2$) ve 100 Ω ($R_3$) seri dirençlerini sürüyor. Her direncin referansı akım yönünde artıdan eksiye ($+V_1-$, $+V_2-$, $+V_3-$) tanımlı. Üç voltmetre bağlı:

| Direnç | Voltmetre okuması | Bağlantı |
|---|---|---|
| $R_1 = 10\,\Omega$ | $0.600$ V | kırmızı prob referansın artısında |
| $R_2 = 30\,\Omega$ | $1.800$ V | kırmızı prob referansın artısında |
| $R_3 = 100\,\Omega$ | $-6.000$ V | problar ters bağlı |

Üçüncü voltmetrenin siyah (eksi) probu referansın artı ucuna bağlıdır; okunan değer $-V_3$'tür. $-V_3 = -6$ V olduğundan $V_3 = 6$ V.

KVL ile sağlama: $-8.4 + V_1 + V_2 + V_3 = -8.4 + 0.6 + 1.8 + 6 = 0$.

Her direncin gerilimi bölü direnci aynıdır: $0.6/10 = 1.8/30 = 6/100 = 0.06$ A. Bu ana kol akımıdır (60 mA). Seri dirençler ana kol gerilimini direnç değerleriyle doğru orantılı paylaşır.

Slayttaki kural: voltmetrenin kırmızı (artı) ucu yüksek potansiyelli noktaya, siyah (eksi) ucu düşük potansiyelli noktaya bağlanırsa okuma pozitif olur; uçlar ters bağlanırsa büyüklük aynı kalır, eksi işaret görünür.

### 12.3 Seri Devrede Akım Ölçümü

Akım ölçmek için multimetreler miliamper kademesine ve akım ölçme konumuna alınır. Ampermetre devreye seri bağlanır. Ana kolda akım yönüne uygun bağlanan ampermetre 60 mA, birinci ile ikinci direnç arasına ve ikinci ile üçüncü direnç arasına akım yönüne uygun bağlananlar yine 60 mA gösterir. Akım referans yönünün tersine bağlanan ampermetre ise $-60$ mA gösterir. Ölçülen değerlerin işareti bağlantı yönüne göre değişir.

### 12.4 Örnek: AC Kaynakta Gerilim Bölücü

Soru (ekrandan, 02:35:00): $R_1$ üzerindeki $V_1$ ve $R_2$ üzerindeki $V_2$ gerilimlerini bulun.

Devre: $20\sin(377t)$ V gerilim kaynağı, seri $R_1 = 3$ kΩ ve $R_2 = 4$ kΩ.

Önceki örneklerdeki kaynaklar DC idi, yani zamanla değişmiyordu. Bu kaynak sinüzoidaldir: $t = 0$ anında sıfırdır, en çok 20 V'a çıkar, en az $-20$ V'a iner, ortalaması sıfırdır. $2\pi f = 377$ olduğundan frekans $f = 377/(2\pi) \approx 60$ Hz'dir (ara adım eklendi); frekans, işaretin saniyede kendini kaç kez tekrarladığıdır.

Seri direnç devresi yalnız DC için değil, her kaynak türü için gerilim bölücü olarak çalışır:

$$V_1 = \frac{R_1}{R_1+R_2}V_{total} = \frac{3\text{ k}\Omega}{3\text{ k}\Omega + 4\text{ k}\Omega}\,20\sin(377t) = 8.57\sin(377t)\text{ V}$$

$$V_2 = \frac{4\text{ k}\Omega}{7\text{ k}\Omega}\,20\sin(377t) = 11.4\sin(377t)\text{ V}$$

Sağlama: $8.57\sin(377t) + 11.4\sin(377t) = 20\sin(377t)$ V. Hoca bunu genliği $A$ olan kaynak için $A\cdot\tfrac{3}{7} + A\cdot\tfrac{4}{7} = A$ diye özetledi.

> **Ders sonrası not:** Hoca anlatırken dirençleri bir yerde "4K ve 7K" diye andı; slayttaki dirençler 3 kΩ ve 4 kΩ'dur, 7 kΩ bunların toplamıdır.

### 12.5 Örnek: Paralel Eşdeğerle Gerilim Bölücü

Bir sinüzoidal kaynaklı devrede $v_x$ isteniyor. $v_x$, birbirine paralel 6 Ω ve 3 Ω dirençlerin uçlarındaki gerilimdir. Önce bu iki direncin, $v_x$'in tanımlandığı iki uç arasından görülen eşdeğeri bulunur:

$$\frac{1}{R_{eq}} = \frac{1}{6} + \frac{1}{3} = \frac{1}{6} + \frac{2}{6} = \frac{3}{6} \quad\Rightarrow\quad R_{eq} = 2\,\Omega$$

Paralel elemanların gerilimi eşdeğerlerinin gerilimine eşit olduğu için 2 Ω üzerindeki gerilim yine $v_x$'tir. Kalan devrede 2 Ω ile seri bir direnç vardır ve toplam 6 Ω'dur; yani seri direnç 4 Ω'dur (ara adım eklendi). Kaynak genliği $A$ ise:

$$v_x = A \cdot \frac{2}{6} = \frac{A}{3}$$

Sonuç derste $4\sin t$ V olarak verildi.

<!-- BELİRSİZ: Bu örneğin slaytı karede yok; kaynak ifadesi altyazıda geçmiyor. v_x = 4 sin t sonucuna göre kaynak büyük olasılıkla 12 sin t V'tur. -->

## 13. Akım Bölücü Devreler

### 13.1 Mantık

Paralel devreler akım bölücü olarak çalışır. Paralel kollarda akım direnci düşük olan kolu tercih eder; bir kola düşen akım, o kolun direnciyle ters orantılıdır. Seri devrede eşdeğer direnç toplamla bulunduğu gibi, paralel devrede eşdeğeri iletkenlikle bulmak daha kolaydır. Bu yüzden paralel kolda akımı iletkenlik üzerinden yazmak, seri devredeki gerilim bölücünün karşılığıdır.

Slayttaki formül (ekrandan, 02:40:00): $I_{in}$ akım kaynağı, paralel $R_1$, $R_2$, $R_3$. $R_2$ ile $R_3$'ün eşdeğeri alınarak iki kollu devreye indirilir:

$$R_{eq} = R_2 \parallel R_3 = \frac{R_2R_3}{R_2+R_3}, \qquad I_1 = \frac{R_{eq}}{R_1 + R_{eq}}\,I_{in}$$

### 13.2 Ölçüm Örneği: Paralel İki Direnç

Kurulum (ekrandan, 02:45:00): 12.0 V güç kaynağı (akım göstergesi 16.0 mA), paralel $R_1 = 1$ kΩ ve $R_2 = 3$ kΩ, ana kola seri bağlı mA ölçerde $16.00$ okunuyor.

Paralel dirençlerde her birinin gerilimi 12 V'tur; voltmetre kırmızı prob referansın artısına bağlanırsa her ikisinde 12 V okunur.

Ölçülebilecek üç akım vardır: ana kol akımı (ampermetre 1), $R_1$ kolu (ampermetre 2) ve $R_2$ kolu (ampermetre 3).

Ana kol akımı:

$$\frac{1}{R_{eq}} = \frac{1}{1000} + \frac{1}{3000} \quad\Rightarrow\quad R_{eq} = \frac{3000 \cdot 1000}{4000} = 750\,\Omega$$

$$I_s = \frac{12}{750} = 16 \text{ mA}$$

Kol akımları dirençle ters orantılıdır. 1 kΩ'luk kola $3x$, 3 kΩ'luk kola $x$ birim akım gider; $4x = 16$ mA olduğundan:

- $I_1 = 12$ mA (1 kΩ)
- $I_2 = 4$ mA (3 kΩ)

Ana kol akımını ölçmek için kaynağın paralel elemanlara bağlandığı nokta koparılır ve araya ampermetre seçilen akım yönünde bağlanır. Slayttaki kural: kırmızı (artı) uç, kaynak akımı bu uçtan girip siyah (eksi) uçtan çıkacak şekilde bağlanırsa okuma pozitif olur.

Bir kolun akımını ölçmek için o direncin bir ucu devreden ayrılır ve ayrılan uç, akım referans yönünde ampermetreyle tamamlanır. İdeal ampermetre kısa devre eşdeğeridir: iç direnci sıfırdır, üzerinde gerilim düşmez, koldaki akımın tamamı ondan geçer. İç direnci olsaydı akımın bir kısmını kendi üzerinde harcar ve ölçüm doğru olmazdı. Bu şekilde 1 kΩ kolunda 12 mA, 3 kΩ kolunda 4 mA ölçülür.

### 13.3 Üç Paralel Direnç

Üç paralel direnç varsa yol yine aynıdır: önce üç direncin eşdeğeri bulunur (örnekte yaklaşık 109 Ω), ana kol akımı bulunur, sonra her kolun akımı direnciyle ters orantılı paylaştırılır. Hoca örnekte en düşük dirençli koldan 3 birim, ortadakinden 2 birim, en yüksek dirençli koldan 1 birim akım geçtiğini gösterdi; düşük dirençten daha yüksek akım geçer.

<!-- BELİRSİZ: Üç dirençli akım bölücü örneğinin direnç değerleri ve akımları karede yok; yalnız yaklaşık 109 Ω eşdeğer altyazıda geçiyor. Hocanın bu eşdeğeri "geometrik ortalama gibi" diye anması da doğru değil; eşdeğer terslerin toplamı kuralıyla bulunur. -->

## 14. Y-Δ (T-π) Dönüşümü ve Köprü Devresi

### 14.1 Y ve Δ Yapıları

Üç uçlu bağlantı yapıları güç sistemlerinde yaygındır (ekrandan, 02:50:00). Şekildeki gösterim:

| Yapı | Eleman | Bağlı olduğu uçlar |
|---|---|---|
| Y | $R_1$ | A ile ortak (yıldız) noktası |
| Y | $R_2$ | B ile ortak nokta |
| Y | $R_3$ | C ile ortak nokta |
| Δ | $R_c$ | A ile B |
| Δ | $R_a$ | A ile C |
| Δ | $R_b$ | B ile C |

Bir Y bağlantısının eşdeğer bir Δ bağlantısı vardır (ve tersi). İki yapının eşdeğer olması için herhangi iki uç arasından (üçüncü uç boştayken) bakıldığında görülen dirençler iki yapıda aynı olmalıdır.

### 14.2 Eşdeğerlik Denklemleri

- **A-B uçları (C boşta):** C ucu bir yere bağlı değilken $R_3$'ten akım akmaz. Y'de $R_1 + R_2$ görülür. Δ'da $R_a$ ile $R_b$ seridir ve bu seri grup $R_c$'ye paraleldir:
  $$R_1 + R_2 = R_c \parallel (R_a + R_b)$$
- **C-B uçları (A boşta):** $R_1$'den akım akmaz. Y'de $R_2 + R_3$; Δ'da $R_c$ ile $R_a$ seri, bunlar $R_b$'ye paralel:
  $$R_2 + R_3 = R_b \parallel (R_c + R_a)$$
- **A-C uçları (B boşta):** $R_2$'den akım akmaz. Y'de $R_1 + R_3$; Δ'da $R_c$ ile $R_b$ seri, bunlar $R_a$'ya paralel:
  $$R_1 + R_3 = R_a \parallel (R_c + R_b)$$

Üç denklem, üç bilinmeyen vardır. $R_1$, $R_2$, $R_3$ biliniyorsa $R_a$, $R_b$, $R_c$ çekilir; tersi de mümkündür.

### 14.3 Dönüşüm Formülleri

Slayttaki formüller (ekrandan, 02:55:00):

| Δ'dan Y'ye | Y'den Δ'ya |
|---|---|
| $R_1 = \dfrac{R_bR_c}{R_a+R_b+R_c}$ | $R_a = \dfrac{R_1R_2+R_2R_3+R_3R_1}{R_1}$ |
| $R_2 = \dfrac{R_aR_c}{R_a+R_b+R_c}$ | $R_b = \dfrac{R_1R_2+R_2R_3+R_3R_1}{R_2}$ |
| $R_3 = \dfrac{R_aR_b}{R_a+R_b+R_c}$ | $R_c = \dfrac{R_1R_2+R_2R_3+R_3R_1}{R_3}$ |

Özel durum: $R_1 = R_2 = R_3 = R$ ise $R_a = R_b = R_c = 3R$; $R_a = R_b = R_c = R'$ ise $R_1 = R_2 = R_3 = R'/3$.

> **Ders sonrası not:** Yukarıdaki üç eşdeğerlik denklemi, 14.1'deki çizim etiketleriyle ($R_c$: A-B, $R_a$: A-C, $R_b$: B-C) python ile çözüldüğünde $R_1 = R_aR_c/\Sigma$, $R_2 = R_bR_c/\Sigma$, $R_3 = R_aR_b/\Sigma$ çıkar. Yani formül slaytında $R_1$ ile $R_2$ (ve Y'den Δ'ya tarafında $R_a$ ile $R_b$) çizime göre yer değiştirmiş görünür. Formül slaytı büyük olasılıkla $R_a$'nın A ucunun karşısında durduğu bir etiketlemeye göre hazırlanmıştır. Etiketten bağımsız kural: bir uçtaki Y direnci, o uca bitişik iki Δ direncinin çarpımının üç Δ direncinin toplamına bölümüdür; bir Δ direnci ise Y çarpımlarının toplamının, o Δ direncinin karşısındaki Y direncine bölümüdür.

### 14.4 T-π Gösterimi

Y yapısının ortak düğümü genişletildiğinde yapı, giriş ve çıkış uçları olan bir T modülüne dönüşür. Δ yapısında üçgenin tepesindeki düğüm genişletildiğinde π yapısı elde edilir. Bu yüzden Y-Δ dönüşümüne T-π dönüşümü de denir; ikisi arasındaki fark yalnız gösterimdir.

### 14.5 Y Bağlantısının Kullanımı: Üç Fazlı Motorlar

Y bağlantısı özellikle AC devrelerinde, üç fazlı (trifaze) motorların beslenmesinden gelir. Bir motorun üç ayrı sargısı olduğunu düşünelim. Her sargıya kendi fazı ve onun referans (ground) kablosu ayrı ayrı gönderilseydi 6 kablo gerekirdi. Bütün fazların referansı aynı olduğu için referanslar birleştirilebilir ve 4 kabloya inilir. Trifaze AC motorlar bugün de yüksek güç gerektiren sistemlerde kullanılır.

Sargılar Y biçiminde bağlanıp aralarında 120° faz farkı olan AC besleme verilirse, teorik olarak Y'nin merkez noktası her an sıfır gerilimdedir. Birleşme noktasında sanal bir referans (ground) oluşur. Böylece referans gerilimi taşıyan dördüncü kabloyu çekmeye gerek kalmaz; sistem kendi içinde sanal bir referans oluşturur.

### 14.6 Köprü Devresi

Y ve Δ gösterimlerinin iki kullanım amacı vardır:

- Karmaşık devrelerde Y-Δ dönüşümü yaparak devreyi basitleştirmek.
- Hassas ölçümlerde köprü mantığını kullanmak.

Köprü devresi, sırt sırta bağlı iki Δ yapısı olarak görülebilir (ekrandan, 03:00:00). Şekilde üstte $R_{b1}$ ve $R_{a1}$, altta $R_{a2}$ ve $R_{b2}$, ortada iki Δ'nın ortak kenarı $R_{c1} = R_{c2}$ ve bu kenarın uçları arasındaki gerilim $V_{CD}$ vardır. Slayttaki ifadeye göre bu yapı, $R_{c1} = R_{c2} = \infty$ olan iki Δ ağı olarak da düşünülebilir. Ortadaki kenarda bir yük direnci olabilir.

Köprü mantığında alınan ölçüm ortam koşullarından en az etkilenen ölçümdür. Dirençler ortamın sıcaklığına, nemine ya da başka özelliklerine göre değişiyorsa, karşılıklı (çapraz) dirençler aynı biçimde etkilenir ve net etki sıfıra yaklaşır. Bu yüzden köprü mantığı içinde kurulan bir sensör yapısı ortam koşullarından en az etkilenen hassas bir sensör olur.

Yapının uçlarına iki direnç daha eklenirse iki Y bağlantısının sırt sırta bağlandığı bir yapı elde edilir; bunlar da Δ biçimine dönüştürülerek düzenlenebilir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:35:00): 120 V kaynak, 30 Ω, $2v_A$ gerilim kontrollü gerilim kaynağı ve 15 Ω'dan oluşan tek çevrimde ($v_A$, 15 Ω üzerinde alt uç artı) her elemanın çektiği gücü bulun.

> **Çözüm:** $-120 + 30i + 2(-15i) + 15i = 0 \Rightarrow i = 8$ A. $p_{120V} = -960$ W, $p_{30\Omega} = 1920$ W, $p_{dep} = -1920$ W, $p_{15\Omega} = 960$ W. Toplam sıfır.

**Soru 2** (ekrandan, 00:45:00): 120 A (yukarı), $\tfrac{1}{30}\,\Omega$, 30 A (aşağı) ve $\tfrac{1}{15}\,\Omega$ paralel bağlıdır. Her elemanın gerilimini, akımını ve gücünü bulun.

> **Çözüm:** $-120 + 30v + 30 + 15v = 0 \Rightarrow v = 2$ V; $i_1 = 60$ A, $i_2 = 30$ A; $p_{R1} = 120$ W, $p_{R2} = 60$ W, $p_{120A} = -240$ W, $p_{30A} = 60$ W.

**Soru 3** (ekrandan, 00:50:00): 5.6 A (yukarı), 18 Ω, $0.1v_x$ bağımlı akım kaynağı (yukarı), 9 Ω ve 2 A (aşağı) paralel bağlıdır. $i_A$, $i_B$ (bağımlı kaynak kolunda aşağı yönlü) ve $i_C$'yi bulun.

> **Çözüm:** $5.6 - v_x/18 + 0.1v_x - v_x/9 - 2 = 0 \Rightarrow v_x = 54$ V; $i_A = 3$ A, $i_B = -5.4$ A, $i_C = 6$ A. Sağlama: $3 - 5.4 + 6 + 2 = 5.6$.

**Soru 4** (ekrandan, 01:00:00): Bölüm 5.2'deki devrede (2 A, 1.5 Ω, kısa devreli 2 Ω, iki 4 Ω, 5 Ω, 5 A) (a) hangi tekil elemanlar seri/paraleldir, (b) hangi eleman grupları seri/paraleldir?

> **Çözüm:** Kısa devre yüzünden 2 Ω'dan akım akmaz ve orta iki düğüm birleşir. 2 A kaynak ile 1.5 Ω seri, 5 A kaynak ile 5 Ω seridir. Sol seri kol soldaki 4 Ω'a, sağ seri kol sağdaki 4 Ω'a paraleldir; sol ve sağ gruplar da birbirine paraleldir.

**Soru 5** (ekrandan, 01:30:00): 9 V, 3 V, 5 V ve 1 V kaynaklar ile 100 Ω ve 220 Ω dirençlerden oluşan tek çevrimde akımı bulun; kaynakları tek bir eşdeğer kaynakla değiştirin.

> **Çözüm:** $-3 - 9 + 100i - 5 + 1 + 220i = 0 \Rightarrow i = 16/320 = 50$ mA. Eşdeğer kaynak 16 V'tur; akım yönünde eksisinden girilecek biçimde sol ya da sağ kola konabilir.

**Soru 6** (ekrandan, 01:35:00): 2.5 A (yukarı), 5 Ω, 2.5 A (aşağı), 5 Ω ve 3 A (aşağı) paralel bağlıdır. Akım kaynaklarını tek kaynağa indirip $v$'yi bulun.

> **Çözüm:** Yukarı yönlü eşdeğer $-3$ A (ya da aşağı yönlü 3 A). $-3 - v/5 - v/5 = 0 \Rightarrow v = -7.5$ V.

**Soru 7** (ekrandan, 01:50:00): Kahverengi-kırmızı-yeşil bantlı direncin değeri nedir? 1 kΩ ve 10 kΩ dirençlerin ilk üç bandı hangi renklerdir?

> **Çözüm:** $12 \times 10^5 = 1.2$ MΩ. 1 kΩ: kahverengi-siyah-kırmızı. 10 kΩ: kahverengi-siyah-turuncu.

**Soru 8** (ekrandan, 02:25:00): Aynı değerli dirençlerde seri direnç sayısı artırıldıkça ve paralel direnç sayısı artırıldıkça $R_{eq}$ artar mı, azalır mı?

> **Çözüm:** Seride artar ($NR$), paralelde azalır ($R/N$).

**Soru 9** (ekrandan, 02:35:00): $20\sin(377t)$ V kaynağa seri bağlı 3 kΩ ($R_1$) ve 4 kΩ ($R_2$) dirençlerinin gerilimlerini bulun.

> **Çözüm:** $V_1 = \tfrac{3}{7} \cdot 20\sin(377t) = 8.57\sin(377t)$ V, $V_2 = \tfrac{4}{7} \cdot 20\sin(377t) = 11.4\sin(377t)$ V; toplamları $20\sin(377t)$ V.

**Soru 10** (ekrandan, 02:45:00): 12 V kaynağa paralel bağlı 1 kΩ ve 3 kΩ dirençlerde ana kol akımını ve kol akımlarını bulun.

> **Çözüm:** $R_{eq} = 750$ Ω, $I_s = 12/750 = 16$ mA, $I_{1k} = 12$ mA, $I_{3k} = 4$ mA.

## Dersin Toparlaması

Bu derste Kirchhoff yasalarının en basit iki uygulaması görüldü: tek çevrimli devrede ortak akım ve KVL, tek düğüm çiftli devrede ortak gerilim ve KCL. Bağımlı kaynaklı örneklerde bilinmeyenlerin Ohm yasasıyla tek bir değişkene indirildiği ve güç toplamının sıfır olmasıyla sonucun kontrol edildiği gösterildi. Ardından seri (yalnız iki elemanca paylaşılan düğüm, aynı akım) ve paralel (iki ortak düğüm, aynı gerilim) tanımları yapıldı; seri gerilim kaynaklarının ve paralel akım kaynaklarının tek kaynağa, seri ve paralel dirençlerin tek dirence indirgenmesi türetildi. Eşdeğerliğin bakılan uçlara bağlı olduğu, iletkenlikle dirençler arasındaki dualite, renk kodları ve multimetre ile ölçümde işaretlerin bağlantı yönüne göre değiştiği vurgulandı.

Dersin son bölümünde gerilim bölücü (seri dirençlerde gerilim dirençle doğru orantılı) ve akım bölücü (paralel dirençlerde akım dirençle ters orantılı) devreler, DC ve AC örneklerle işlendi. Son olarak Y-Δ (T-π) dönüşümünün eşdeğerlik denklemleri ve formülleri, Y bağlantısının üç fazlı motorlardaki kullanımı ve köprü devresinin ortam koşullarından az etkilenen hassas ölçümdeki rolü anlatıldı. Hoca son birkaç slaydı bir sonraki derste kısaca tekrar edip düğüm ve çevre analizine geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
