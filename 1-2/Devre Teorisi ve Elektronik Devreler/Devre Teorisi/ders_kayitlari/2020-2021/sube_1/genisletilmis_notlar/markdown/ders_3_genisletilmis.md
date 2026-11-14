# Ders 3 Genişletilmiş Notu: Lab 0 Tanıtımı (Proteus); Gerilim ve Akım Bölücüler, Y-Δ Dönüşümü, Köprü Devreleri, Düğüm Analizi ve Süper Düğüm

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Lab 0: Laboratuvar Donanımı
- 2. Lab 0: Proteus ile Basit Bir Devre Kurmak
- 3. Önceki Dersten: Eşdeğer Direnç
- 4. Gerilim Bölücü Devreler
- 5. Akım Bölücü Devreler
- 6. Bölücülerin Özeti ve Dualite Tablosu
- 7. Y-Δ ve T-π Dönüşümleri
- 8. Köprü Devreleri
- 9. Düğüm ve Çevre Analizine Giriş
- 10. Doğrusal Denklem Sistemlerinin Çözümü
- 11. Düğüm (Node) Analizi
- 12. Düğüm Analizi Örneği: 15 Ω Üzerindeki Akım
- 13. Süper Düğüm (Supernode)

## 1. Lab 0: Laboratuvar Donanımı

Kaydın ilk bölümü, dersin laboratuvar kısmını yürüten araştırma görevlisinin anlattığı Lab 0 oturumudur. Deneylerin kapsamı üç parçadan oluşur: matematiksel formülasyon, bu formülasyondan gereken hesapları yapmak ve formülasyonun tutup tutmadığını simülasyon ortamında deney yaparak ölçmek.

Laboratuvar pandemi nedeniyle çevrim içi yapılıyor, bu yüzden deneylerde fiziksel alet kullanılmayacak. Yine de öğrencilerin bu aletlere yabancı kalmaması için tanıtıldılar. Elektronik laboratuvarlarında kullanılma ihtimalleri var.

### 1.1 Devre Bordu (Breadboard)

Devre bordunun beyaz kısmına dirençler ve kablolar takılır. Üzerindeki minik delikler rastgele değildir: Yan yana ya da alt alta dizilmiş deliklerin her birini tek bir hat, yani tek bir kablo gibi düşünebilirsiniz.

Bu bilginin pratik sonucu paralel bağlantıdır. Elinize iki direnç aldınız. İki direncin de ikişer ayağını aynı iki hatta takarsanız dirençleri paralel bağlamış olursunuz, çünkü iki direncin uçları aynı noktalara gelmiştir.

Bordun üst tarafındaki düğmeler frekans ayarlamaya, sol taraftaki düğmeler voltaj vermeye yarar. Kablo başları bu düğmelerin yanındaki küçük yuvalara yerleştirilir. Sol alt köşedeki iki küçük düğme ise toprak (ground) bağlantısıdır: Devreyi topraklamak için kablonun ucu buraya bağlanır.

> **Ders sonrası not:** Anlatıcı bir yerde birer ayağın aynı hatta takılmasının paralel bağlantı olduğunu söyledi. Paralellik için iki direncin iki ucu da ortak olmalıdır. Aynı anlatıcının ilk anlatımındaki "ikişer ayak" ifadesi doğrudur. Ayrıca bir delik sırasının yatay mı dikey mi bağlı olduğu, büyük olasılıkla bordun bölgesine göre değişir.

### 1.2 Multimetre

Multimetre el büyüklüğünde bir ölçüm aletidir. Voltmetre, ampermetre ve direnç ölçerin (ohmmetre) birleşimi olarak düşünülebilir. Çok karmaşık bir alet değildir, ama devre teorisi laboratuvarı için gereklidir.

> **Ders sonrası not:** Anlatıcı bordun beyaz kısmından söz ederken bir kez "multimetrenin yerleri" dedi ve aletlerin sağ-sol konumunu bir yerde ters söyledi. Sonraki tekrarında netleştirdiği gibi board solda, multimetre sağdadır. Beyaz kısım bordun parçasıdır.

### 1.3 Devre Elemanları ve Osiloskop

Slaytta üç şey daha gösterildi:

- **Dirençler:** Üzerlerinde renk kodları vardır. Hangi rengin hangi değere karşılık geldiği bir broşürle paylaşılır.
- **Kondansatörler:** Deneylerde kullanılacak, ama simülatörde sürükle bırak ile eklenecek.
- **Osiloskop:** Yalnızca tanıtıldı. Elektronik içerikli diğer laboratuvarlarda da kullanılacağı için ayrıntısına girilmedi.

## 2. Lab 0: Proteus ile Basit Bir Devre Kurmak

Çevrim içi laboratuvar için simülasyon programı olarak Proteus önerilir, çünkü kullanımı kolaydır. Zorunlu değildir: Multisim ya da başka bir simülasyon programı da kullanılabilir. Proteus'un deneme (demo) sürümü kendi sitesinden indirilebilir. Bu sürümde proje kaydedilemez, ama laboratuvar sırasında devre kurulup çıktı alınabilir.

Proteus aslında kapsamlı bir programdır. Mikroişlemci tasarımında ve elektronik kartlarda da kullanılır. Bu laboratuvar için yalnızca basit devre kurmakla ilgili kısmı bilmek yeterlidir.

### 2.1 Yeni Proje Oluşturma

Proje oluşturma, diğer geliştirme programlarındakine benzer. Adımlar şöyledir:

1. File menüsünden New Project seçilir.
2. Proje adı (Project Name) ve kayıt konumu girilir, Next'e basılır.
3. Şematik sorusunda "Create a schematic from the selected template" işaretlenir, çünkü devrenin şemasını görmemiz gerekir. Şablon olarak Default seçilir. Bu şablon genelde boştur. Next'e basılır.
4. PCB yerleşimi (layout) sorusunda PCB istemediğimiz belirtilir, çünkü bu laboratuvarın kapsamında gerekmiyor. Next'e basılır.
5. Firmware sorusunda "No Firmware Project" seçilir.
6. Program seçimlerin özetini gösterir. Seçimlerden eminseniz Finish'e basılır.

Sonuçta karşımıza boş bir şablon, yani boş bir çalışma alanı ve solda çeşitli menüler çıkar.

### 2.2 Eleman Ekleme ve Değerini Değiştirme

Bir direnç eklemek için sol taraftaki Devices bölümüne gidilir. Burada P ve L harfli iki düğme vardır. P düğmesine basınca program elindeki bütün bileşenleri listeler. Bu kadar bileşenin içinden aradığınızı bulmak için Keyword kutusuna "resistance" yazıp Enter'a basarsınız. Sağ tarafta benzer sonuçlar çıkar. Oradan standart direnç (generic resistor) seçilip OK'ye basılır ve direnç çalışma alanına gelir.

Bir bileşenin değerini değiştirmek için üzerine çift tıklanır. Açılan pencerede örneğin direnç 10k yerine 20k yapılıp OK'ye basılır. Proteus'ta her bileşenin özellikleri bu yolla değiştirilir.

Kaynak da aynı yolla eklenir: Keyword kutusuna "source" yazılır, listeden gerilim kaynağı seçilir. Üzerine çift tıklanıp ikinci satırdan voltajı değiştirilir, örneğin 20 V yerine 30 V yapılır.

> **Ders sonrası not:** Altyazıda kaynak seçilirken "AC yani doğru akım" geçiyor ve kaynaktan birkaç kez "voltmetre" diye söz ediliyor. Doğru akım DC'dir. Burada eklenen eleman voltmetre değil gerilim kaynağıdır. Anlatıcının büyük olasılıkla DC gerilim kaynağını kastettiği, devam eden anlatımdan anlaşılıyor.

### 2.3 Elemanları Bağlama ve Toprak

Değerler ayarlandıktan sonra elemanlar sürükle bırakla birleştirilir: İmleç bir noktaya tıklanıp sürüklenir, öbür noktaya tıklanınca kablo çekilmiş olur. Kaynağın bir ucu toprağa bağlanır. Toprak da menüden seçilip devreye eklenir.

<!-- BELİRSİZ: Altyazı toprağın "aynı menüden" eklendiğini söylüyor. Kısa nota göre Terminals bölümündedir. Slayt görülmedi. -->

Bu noktada devre daha bitmemiştir. Çünkü devre açıktır, kapalı bir devre haline getirilmesi gerekir. Ayrıca yapılacak ölçümler için ampermetre ve voltmetre eksiktir.

### 2.4 Ölçüm Aletleri

Ölçüm aletleri Devices listesinden değil, araç çubuğundaki ölçüm aleti simgesinden alınır. Bu simgeye basınca Instruments menüsü açılır. Burada DC ve AC ampermetre ve voltmetre ile osiloskop dahil çeşitli ölçüm aletleri vardır. Uygun olan seçilip çalışma alanına eklenir ve devrede doğru yere bağlanır.

<!-- BELİRSİZ: Ölçüm aleti simgesinin araç çubuğundaki yeri slaytta gösterildi. Altyazıda "en sağ taraftaki menü" deniyor, kesin konum doğrulanamadı. -->

> **Hocanın vurgusu:** Ampermetre devreye seri, voltmetre paralel bağlanır. Ölçümler önemlidir, çünkü deneylerde sorulacak soruların cevabı bu ölçümlerin içindedir.

**Soru:** Proteus'u distro'dan mı indirelim, internetten mi? **Cevap:** Distro'daki sürüm bazı Windows sürümlerinde hata veriyor, bazılarında çalışıyor ve proje kaydetmeye izin veriyor. İnternetten indirilen demo sürüm hata vermiyor ama proje kaydetmeye izin vermiyor. İkisinden biri tercih edilebilir.

**Soru:** Proje kaydedilemiyorsa yaptığımızı nasıl göstereceğiz? **Cevap:** Proje dosyasını kaydetmeniz gerekmiyor. Kurduğunuz devrede ölçümü yapıp ekran görüntüsünü almanız yeterli.

## 3. Önceki Dersten: Eşdeğer Direnç

Asıl ders, geçen haftadan taşınan konuyla başladı. Geçen hafta seri ve paralel direnç devrelerinin eşdeğer dirençleri Kirchhoff kanunlarından hesaplanmıştı. İki terminal ucundan baktığımız, pasif elemanlardan oluşan karmaşık bir bloğun yerine tek bir direnç koyabiliyorduk.

Eşdeğerliğin anlamı şudur: Karmaşık yapıyı bir kaynağa bağladığımızda terminalde gördüğümüz gerilim ve terminalin bir kolundan akan akım neyse, yapıyı kaldırıp yerine eşdeğer direnci koyduğumuzda da aynı gerilim ve aynı akımı görürüz.

## 4. Gerilim Bölücü Devreler

Gerilim bölücü, gerilimin elemanlar arasında orantılı olarak paylaştırılmasıdır. Bu mantık seri direnç devreleri için geçerlidir.

### 4.1 İki Seri Direnç

Tek gözlü bir devrede tek çevre olduğu için tek bir akım $I$ vardır ve bütün elemanlardan bu akım geçer. Bir çevrim içindeki eleman gerilimlerinin toplamı sıfırdır. Akım kaynağın eksisinden girip artısından çıktığı için kaynak gerilimi denkleme eksi işaretle yazılır:

$$-V + V_1 + V_2 = 0 \quad\Rightarrow\quad -V + IR_1 + IR_2 = 0$$

Buradan akım ve eleman gerilimleri bulunur:

$$I = \frac{V}{R_1 + R_2}, \qquad V_1 = \frac{V}{R_1 + R_2} R_1, \qquad V_2 = \frac{V}{R_1 + R_2} R_2$$

Gerilimler direnç değerleriyle doğru orantılı paylaşılır. Direnç ne kadar büyükse ortak kaynaktan üzerine düşen gerilim o kadar fazladır. Bu tip yapılara gerilim bölücü denir.

### 4.2 Pratik Örnek: LED Sürmek

Elimizde 9 V'luk bir kaynak ve bir direnç üzerinden sürülecek bir LED var. LED'in veri sayfasına (data sheet) göre en parlak ışığını 20 mA'de verir ve bu akımda üzerindeki gerilim düşümü 1.4 V'tur. Soru: R direnci ne olmalı?

LED bir diyot olsa da onu, üzerinden geçmesi gereken akımı ve gerilim düşümü sabit olan iki terminalli bir eleman gibi düşünebiliriz. O zaman bu da bir gerilim bölücü problemidir: Direnci öyle seçmeliyiz ki kaynaktan geriye LED üzerinde 1.4 V kalsın ve devreden 20 mA aksın. Akımı sınırlayan eleman dirençtir.

Bir öğrencinin önerdiği gibi çevre denklemi yazılır:

$$-9 + V_R + V_L = 0 \quad\Rightarrow\quad V_R = 9 - 1.4 = 7.6\ \text{V}$$

Direnç üzerindeki gerilim $V_R = I R$ olduğundan:

$$R = \frac{7.6}{20 \times 10^{-3}} = \frac{760}{2} = 380\ \Omega$$

380 Ω'luk bir direnç kullanırsak LED en parlak şekilde yanar.

### 4.3 Genel Kural

$n$ direncin seri bağlı olduğu ve $V$ kaynağıyla beslenen bir devrede akım şöyledir:

$$I = \frac{V}{R_1 + R_2 + \dots + R_n} = \frac{V}{R_{\text{eş}}}$$

Bu akım istenen direnç değeriyle çarpılınca o direncin gerilimi bulunur:

$$V_k = \frac{V}{R_{\text{eş}}} R_k$$

### 4.4 Pratikte Gerilim Ölçümü

Şimdi 8.4 V'luk bir kaynağa seri bağlı 10 Ω, 30 Ω ve 100 Ω dirençleri düşünelim. Önce teorik hesap yapılır. Toplam direnç 140 Ω'dur:

$$V_1 = \frac{10}{140} \cdot 8.4 = 0.6\ \text{V}, \qquad V_2 = 3 V_1 = 1.8\ \text{V}, \qquad V_3 = \frac{100}{140} \cdot 8.4 = 6\ \text{V}$$

Sonuçların toplamı 8.4 V eder. Her elemanın gerilimi, voltmetrenin artı ve eksi uçlarını elemanın iki terminaline bağlayarak ölçülür.

**Ölçümün işareti.** Verilen referans yönlerinde $V_3 = +6$ V'tur. Multimetrenin kırmızı (artı) ucunu direncin referans yönünün eksi ucuna, eksi ucunu referans yönünün artı ucuna bağlarsak ölçüm ters yönde yapılmış olur ve −6 V okunur. Ölçülen değerin negatif olması, devrede bir terslik olduğunu göstermez. İşaret, seçtiğimiz ölçüm referansına bağlıdır.

**Ölçüm kademesi.** Slaytta multimetre üzerinde 20 V ve 2 V kademeleri görülüyordu. 20 V kademesi, 20 V mertebesine kadar olan gerilimleri ölçebildiği anlamına gelir. Burada öne çıkan hassasiyettir: 20 V kademesinde 2 V mertebesinde bir gerilim ölçerseniz ondalık basamaklarda hassasiyet kalmaz. Ortadaki direncin kademesinin 20 V değil 2 V olmasının nedeni, ölçülen değerin 1.8 V olmasıdır.

Pratikte izlenecek yol şudur: Ölçeceğiniz gerilimi kabaca tahmin ediyorsanız ona uygun kademeyi seçersiniz. Tahmin edemiyorsanız besleme gerilimine uygun kademeden başlarsınız. Örneğin 20 V kademesinde 1 V civarı bir değer görürseniz bir alt kademeye, yani 2 V'a geçip ölçümü daha hassas yaparsınız. Simülasyonda böyle bir kademe ayarı kullanılmayacak, ama fiziksel ölçümde bunu yapmakta fayda var.

<!-- BELİRSİZ: Slayttaki multimetrelerin hangi kademede olduğu yalnız ortadaki 1.8 V ölçümü için açıkça söyleniyor. -->

### 4.5 Pratikte Akım Ölçümü

Ampermetre kısa devre gibi çalışan bir elemandır, bu yüzden devreye seri bağlanır. Tek gözlü devrede bütün elemanlardan aynı akımın geçtiğini biliyoruz. Yine de her elemanın peşine bir ampermetre koyarsak farklı bir durum olur mu diye bakalım. Devre her ölçüm noktasında koparılır ve kopan yer ampermetreyle tamamlanır.

Teorik akım, birinci direncin geriliminden bulunur:

$$I = \frac{0.6\ \text{V}}{10\ \Omega} = 60\ \text{mA}$$

Bu sonuç, saat yönünde seçtiğimiz referans yönü için pozitiftir. Ana koldaki, birinci direncten sonraki ve 30 Ω'dan sonraki ampermetrelerin artı-eksi uçları referans akım yönüyle uyumlu bağlandığı için 60 mA okunur. Son ampermetrenin uçları ise ters bağlanmıştır, bu yüzden −60 mA okunur. Bu okuma, ana koldaki akımın negatif olduğu anlamına gelmez. Ölçüm referansımız da işin içine girdiği için değer eksi görünür.

> **Hocanın vurgusu:** Ölçüm aletinin referans yönleri nasıl bağlanırsa okunan değer ona göre değişir. Bu durum hem fiziksel ölçümde hem simülasyonda geçerlidir. Değerleri istenen referans yönlerinde ölçmeye dikkat edin.

### 4.6 AC Kaynakla Gerilim Bölücü

Gerilim bölücü mantığı yalnız DC için değil AC için de geçerlidir. Kaynağın AC ya da DC olması Kirchhoff denkleminin işleyişini değiştirmez.

**Verilen:** $v_s = 20 \sin 377t$ V, seri 3 kΩ ve 4 kΩ. Kaynağın sinüzoidal olduğu tilda işaretiyle de gösterilebilir.

**Çözüm:** Saat yönünde bir çevre için $-v_s + V_1 + V_2 = 0$ yazılır:

$$20 \sin 377t = 3\text{k} \cdot i + 4\text{k} \cdot i \quad\Rightarrow\quad i = \frac{20}{7\text{k}} \sin 377t$$

$$V_1 = 3\text{k} \cdot \frac{20}{7\text{k}} \sin 377t = \frac{60}{7} \sin 377t \approx 8.57 \sin 377t\ \text{V}$$

$$V_2 = 4\text{k} \cdot \frac{20}{7\text{k}} \sin 377t = \frac{80}{7} \sin 377t \approx 11.43 \sin 377t\ \text{V}$$

Slaytta $V_1 + V_2 = v_s$ olup olmadığının kontrol edilmesi isteniyor. Hocaya göre işleme zaten bu denklemden başladığımız için bu eşitlik sağlanır.

### 4.7 Üç Seri Direnç

**Verilen:** 1 V kaynak, seri 200 Ω, 400 Ω ve 100 Ω. Eşdeğer direnç 700 Ω'dur.

**Çözüm:** $V_i = \frac{V}{R_{\text{eş}}} R_i$ kullanılır:

$$V_1 = \frac{200}{700} = \frac{2}{7}\ \text{V}, \qquad V_2 = \frac{400}{700} = \frac{4}{7}\ \text{V}, \qquad V_3 = \frac{100}{700} = \frac{1}{7}\ \text{V}$$

Toplam $\frac{7}{7} = 1$ V eder, yani kaynak gerilimini verir.

> **Ders sonrası not:** Altyazıda üçüncü direnç "110" diye geçiyor. Hocanın kullandığı 700 Ω toplamı ve $\frac{1}{7}$ V sonucu 100 Ω ile tutarlıdır (python ile hesaplandı). "110" büyük olasılıkla tanıma hatasıdır.

### 4.8 Paralel Kısmı Olan Bir Gerilim Bölücü

**Verilen:** $12 \sin t$ V kaynak, seri 4 Ω, ardından birbirine paralel 6 Ω ve 3 Ω. **İstenen:** Paralel kısmın gerilimi $v_x$.

**Çözüm:** 6 Ω ve 3 Ω paralel olduğu için eşdeğerleri alınır:

$$R_{\text{eş}} = \frac{1}{\frac{1}{6} + \frac{1}{3}} = \frac{6}{2 + 1} = 2\ \Omega$$

Devre 4 Ω ve 2 Ω'luk seri bir devreye dönüşür. Bunu oranla da görebiliriz: 4 Ω üzerinde $2x$ birim gerilim düşerken 2 Ω üzerinde $x$ birim düşer. 2 Ω'luk eşdeğer direncin gerilimi aranan $v_x$'in kendisidir:

$$v_x = \frac{12 \sin t}{6} \cdot 2 = 4 \sin t\ \text{V}$$

## 5. Akım Bölücü Devreler

### 5.1 Paralellik Gösterimi

Az önce kullandığımız çift dik çizgi, dirençlerin paralel olduğunu yazıda belirtmek için kullanılır. İki direncin iki ucu da ortak terminallere bağlıysa paraleldir ve $R_1 \parallel R_2$ yazılır. Devre şemasında bunu görürüz, bu sembol yalnızca yazımı kolaylaştırır.

### 5.2 İki Paralel Direnç

Akım bölücü, bir düğümden paralel bağlı $n$ direnç için oluşan durumdur. Bütün elemanların uçlarında aynı gerilim vardır. Bu yüzden direnç değeri arttıkça o koldan geçen akım azalır: Kol akımı, kol direnciyle ters orantılıdır.

Üst düğüme giren $I$ ve çıkan $I_1$, $I_2$ için Kirchhoff'un akımlar kanunu yazılır:

$$I = I_1 + I_2 = \frac{V}{R_1} + \frac{V}{R_2} = V\left(\frac{1}{R_1} + \frac{1}{R_2}\right) = \frac{V}{R_{\text{eş}}}$$

Kol akımını bulmak için $V$ gerilimi kaynak akımıyla yazılır, yani $V = I R_{\text{eş}}$. Bu değer kol direncine bölünür:

$$I_1 = \frac{V}{R_1} = \frac{I R_{\text{eş}}}{R_1}$$

Paralel eşdeğer direnç hesaba katılırsa iki kollu devre için şu sonuç çıkar:

$$I_1 = \frac{I}{R_1 + R_2} R_2, \qquad I_2 = \frac{I}{R_1 + R_2} R_1$$

Bir kolun akımı kendi direnciyle ters, karşı koldaki dirençle doğru orantılıdır.

### 5.3 Genel Kural ve İletkenlik

Bir akım kaynağıyla beslenen paralel dizide önce eşdeğer direnç bulunur:

$$\frac{1}{R_{\text{eş}}} = \frac{1}{R_1} + \frac{1}{R_2} + \dots + \frac{1}{R_n}$$

$R_{\text{eş}} I$, bütün kollarda eşit olan gerilim düşümüdür. Bu gerilim o kolun direncine bölününce kol akımı bulunur:

$$I_k = \frac{R_{\text{eş}} I}{R_k}$$

Aynı şey iletkenlikle de yazılabilir. Biçim, dirençlerle gerilim bölücüde yaptığımız hesabın aynısıdır. $\frac{I}{G_{\text{eş}}}$ gerilimi verir. Bu gerilim her kolun iletkenliğiyle çarpılınca kol akımı bulunur:

$$V = \frac{I}{G_{\text{eş}}}, \qquad I_k = \frac{I}{G_{\text{eş}}} G_k$$

### 5.4 Üç Kolda Pratik Yazım

Üç paralel direnç için işi pratikleştiren bir bakış var: İlgilendiğimiz kol tek bırakılır, öbür kollar tek bir "karşı kol" eşdeğeri olarak düşünülür. Böylece iki kollu formül kullanılabilir:

$$I_1 = \frac{I}{R_1 + (R_2 \parallel R_3)} (R_2 \parallel R_3)$$

$$I_2 = \frac{I}{R_2 + (R_1 \parallel R_3)} (R_1 \parallel R_3)$$

$I_3$ için de aynısı geçerlidir. Bu yeni bir kural değil, yalnızca işlemi kolaylaştıran bir yazımdır.

### 5.5 Pratikte Paralel Devrede Ölçüm

12 V'luk bir kaynağa paralel bağlı 1 kΩ ve 3 kΩ dirençleri alalım. İki direnç paralel olduğu için $V_1 = V_2 = 12$ V'tur. Voltmetreyi her direncin uçlarına referans yönünde bağlarsak 12 V okuruz.

Kol akımları:

$$I_1 = \frac{12\ \text{V}}{1\ \text{k}\Omega} = 12\ \text{mA}, \qquad I_2 = \frac{12\ \text{V}}{3\ \text{k}\Omega} = 4\ \text{mA}, \qquad I = 12 + 4 = 16\ \text{mA}$$

Akım ölçerken dikkat edilecek nokta, ampermetrenin nereye konduğudur. Ana kol koparılıp aradaki boşluk ampermetreyle tamamlanırsa, kısa devre elemanı gibi davranan ampermetre bağlantıyı sağlar ve 16 mA'lik ana kol akımını ölçer. Bu ölçüm herhangi bir elemanın akımı değildir.

Yalnız $R_1$'in akımını ölçmek için $R_1$'in bir terminali devreden ayrılır. Yalnızca $R_1$'in terminali ayrılır, ana kol bozulmaz. Kopan bağlantı ampermetreyle tamamlanır. O koldaki bütün akım ampermetreden geçtiği için kol akımı ölçülmüş olur.

> **Hocanın vurgusu:** Yeni başlayanların sık yaptığı hata, ana kol akımı ile paralel elemanın akımını karıştırmaktır. Deneyleri yaparken elemanı ayırıp bağlantıyı ampermetreyle tamamlamaya özellikle dikkat edin.

### 5.6 Üç Dirençli Akım Bölücü

**Verilen:** 4 A akım kaynağı, paralel 200 Ω, 400 Ω ve 600 Ω. **İstenen:** Eleman akımları.

**Çözüm:** Önce eşdeğer direnç hesaplanır, sonra kaynak akımıyla çarpılarak her koldaki ortak gerilim bulunur:

$$R_{\text{eş}} = \frac{1}{\frac{1}{200} + \frac{1}{400} + \frac{1}{600}} \approx 109\ \Omega, \qquad V = 109 \cdot 4 \approx 436\ \text{V}$$

Bu gerilim kol dirençlerine bölünür:

$$I_1 = \frac{436}{200} \approx 2.18\ \text{A}, \qquad I_2 = \frac{I_1}{2} \approx 1.09\ \text{A}, \qquad I_3 = \frac{I_1}{3} \approx 0.727\ \text{A}$$

Direnç ne kadar küçükse üzerinden geçen akım o kadar büyüktür. Tam değerler $R_{\text{eş}} = \frac{1200}{11}$ Ω, $I_1 = \frac{24}{11}$ A, $I_2 = \frac{12}{11}$ A, $I_3 = \frac{8}{11}$ A'dir ve toplamları 4 A eder (python ile hesaplandı).

> **Ders sonrası not:** Kısa nota göre slayttaki $R_{\text{eş}}$ formülünde $\frac{1}{R_2}$ iki kez yazılmış, $\frac{1}{R_3}$ unutulmuş. Altyazıdan bu görülemiyor. Slaytta öyle yazıyorsa büyük olasılıkla yazım hatasıdır, çünkü sayısal sonuç üç direncin paralelliğiyle tutuyor (python ile hesaplandı).

### 5.7 Karma Devre: DC ve AC Kaynak Birlikte

Gerilim bölücü ve akım bölücü bir arada olan bir seri-paralel devre çözelim.

**Verilen:** Seri bağlı 1 V DC ve $0.5 \sin 20t$ V kaynakları. $R_1 = 200\ \Omega$ seri, ardından paralel $R_2 = 400\ \Omega$ ve $R_3 = 100\ \Omega$. Ana kol akımı saat yönünde seçilmiştir.

**Çevre denklemi:** Paralel kısmın gerilimine $V_p$ diyelim. Paralel oldukları için hem $R_2$ hem $R_3$ üzerindeki gerilim $V_p$'dir:

$$-0.5 \sin 20t - 1 + V_1 + V_p = 0$$

**Eşdeğer direnç:** $R_{\text{eş}} = R_1 + (R_2 \parallel R_3)$ olur. $400 \parallel 100 = 80\ \Omega$ olduğundan $R_{\text{eş}} = 280\ \Omega$ çıkar.

**Ana kol akımı:**

$$I_1 = \frac{1 + 0.5 \sin 20t}{280} = 3.571 + 1.786 \sin 20t\ \text{mA}$$

Akımın sabit bir DC ofseti ve onun üstüne binen sinüzoidal bir salınımı vardır.

**Gerilimler:**

$$V_1 = 200 \cdot I_1 = 0.714 + 0.357 \sin 20t\ \text{V}$$

$$V_p = 80 \cdot I_1 = 0.286 + 0.143 \sin 20t\ \text{V}$$

$V_p$ iki yoldan daha bulunabilir: Toplam kaynak geriliminden $V_1$ çıkarılarak ya da paralel eşdeğeri ana kol akımıyla çarpılarak.

**Kol akımları:**

$$I_2 = \frac{V_p}{400} = 0.714 + 0.357 \sin 20t\ \text{mA}$$

$$I_3 = \frac{V_p}{100} = 2.857 + 1.429 \sin 20t\ \text{mA}$$

Sayısal sonuçlar derste okunmadı (ara adım eklendi). Python ile hesaplandı: $V_1 + V_p$ kaynak toplamını, $I_2 + I_3$ ise $I_1$'i veriyor.

> **Ders sonrası not:** Altyazıda bölenler "410" ve "110" diye geçiyor. Devredeki dirençler 400 Ω ve 100 Ω olduğu için bunlar büyük olasılıkla tanıma hatasıdır. Doğrusu $\frac{V_p}{400}$ ve $\frac{V_p}{100}$'dür.

## 6. Bölücülerin Özeti ve Dualite Tablosu

İki bölücünün hesap yolu birbirine benzer ve hangi kaynakla sürüldüğüne göre kısalır.

**Gerilim kaynağıyla sürülen seri devre.** Eşdeğer direnç, dirençlerin toplamıdır. $\frac{V}{R_{\text{eş}}}$ ana kol akımını verir. Bu akım her elemanın direnciyle çarpılınca eleman gerilimi bulunur. Devre akım kaynağıyla sürülüyorsa $\frac{V}{R_{\text{eş}}}$ hesabına gerek kalmaz, çünkü akım zaten kaynaktan bellidir.

**Akım kaynağıyla sürülen paralel devre.** $R_{\text{eş}} I$ her koldaki ortak gerilimi verir. Bu gerilim her direncin değerine bölünerek kol akımları bulunur. Devre gerilim kaynağıyla sürülüyorsa $R_{\text{eş}} I$ hesabına gerek kalmaz, çünkü ortak gerilim kaynağın gerilimidir.

Aynı işlemler iletkenlikle de yapılabilir:

- **Seri devre:** Gerilim eşdeğer iletkenlikle çarpılınca akım bulunur, akım eleman iletkenliğine bölününce eleman gerilimi bulunur.
- **Paralel devre:** $\frac{I}{G_{\text{eş}}}$ ortak gerilimi verir, bu gerilim eleman iletkenliğiyle çarpılınca kol akımı bulunur.

Bu, iki derstir kurduğumuz dualite tablosunun devamıdır. Eşdeğer dirençleri seride toplarken eşdeğer iletkenliği paralelde toplarız. Paralel dirençlerin eşdeğer formülü, seri iletkenliklerin eşdeğer formülüyle aynı biçimdedir. Güç ve enerji formülleri de direnç ya da iletkenlik cinsinden yazılarak aynı sonuca varılır.

<!-- BELİRSİZ: Dualite tablosundaki güç ve enerji formülleri slaytta kaldı, altyazıda okunmuyor. -->

## 7. Y-Δ ve T-π Dönüşümleri

Bu dönüşümlerin nasıl çıktığı, teoremleri gördükten sonra daha net gösterilecek. Şimdilik bağlantılar ve formüller tanıtıldı.

### 7.1 Bağlantı Tipleri

**Y bağlantısı.** Üç direnç ortak bir düğümde birleşir. $R_3$'ün boştaki terminalini referans düğümü gibi seçersek boşta kalan iki uç ayrı birer terminal olur. Böylece AC ve BD olmak üzere iki terminal çifti, yani dört uçlu bir yapı tanımlanır. A'dan ortak düğüme $R_1$, B'den ortak düğüme $R_2$, ortak düğümden referansa $R_3$ gider.

**Δ (üçgen) bağlantısı.** $R_A$ direncinin iki ucu AC terminal çiftini, $R_C$ direncinin iki ucu BD terminal çiftini tanımlar. A ile B terminalleri arasında üçüncü bir direnç $R_B$ vardır. İçteki yapıya bakınca bir üçgen görülür.

**T ve π bağlantıları.** Bunlar aynı yapıların farklı çizimleridir. T bağlantısında 2 ve 4 numaralı terminalleri ortak düşünürsek 1, 3 ve ortak terminalden oluşan bir Y elde ederiz. π bağlantısında C ve D terminalleri arasında başka bir eleman olmadığı için aslında ortak bir düğümdür. Bu ikisi birleştirilince Δ bağlantısı çıkar. Yani T, Y'nin; π, Δ'nın eşdeğeridir.

### 7.2 Dönüşüm Formülleri

Eğer Y bağlantısındaki dirençler birbirine eşit ve her biri $R$ ise, eşdeğer Δ bağlantısındaki dirençlerin her biri $3R$ olur. Tersinden düşünürsek, Δ'daki dirençlerin her biri $R_\Delta$ ise Y'deki dirençlerin her biri şöyledir:

$$R_Y = \frac{R_\Delta}{3}$$

Yani eşit dirençli durumda aralarında 3 katlık bir fark vardır.

> **Ek bilgi (derste anlatılmadı):** Genel formüller slaytta gösterildi ama altyazıda okunmuyor. Aşağıdaki hâl kısa nottan alındı ve 7.1'deki harflendirmeye uyuyor: $R_1 = \frac{R_A R_B}{R_A + R_B + R_C}$, $R_2 = \frac{R_B R_C}{R_A + R_B + R_C}$, $R_3 = \frac{R_A R_C}{R_A + R_B + R_C}$. Tersi için $P = R_1 R_2 + R_2 R_3 + R_3 R_1$ olmak üzere $R_A = \frac{P}{R_2}$, $R_B = \frac{P}{R_3}$, $R_C = \frac{P}{R_1}$ yazılır. Üç uç çifti arasındaki direncin iki yapıda eşit çıktığı ve iki yönün birbirinin tersi olduğu, 200 rastgele değer üzerinde python ile hesaplandı. Kendi slaytınızdaki harf düzeniyle karşılaştırın.

<!-- BELİRSİZ: Slayttaki formüllerin harf düzeni altyazıdan doğrulanamadı. -->

### 7.3 Nerede Kullanılır?

Y ve Δ bağlantıları güç elektroniğinde ve trifaze motorlarda kullanılır. Hocaya göre Y bağlantısı düşük dönüş hızlarında, Δ bağlantısı ise yüksek devirde (RPM) daha iyi tork verir.

### 7.4 Dengeli Y Yükü ve Ortak Düğüm

Y bağlantısının bütün dirençleri eşit olsun ve A, B, C terminallerine aynı genlikte, 120° faz farklı AC kaynaklar verilsin. Bu durumda ortak düğümün gerilimi her zaman sıfırdır.

Bunun pratik anlamı şudur: Normalde üç faz kaynak için bir de geri dönüş referansı tanımlamamız, yani motora dört kablo bağlamamız gerekirdi. Üç kablo fazlar, biri referans için. Ama dengeli yük durumunda ortak düğüm zaten hep 0 V olduğu için referansı sisteme bağlamaya gerek yoktur. Bu yüzden trifaze sistemlerde referans için toprak bağlantısı yapmak gerekmez.

> **Ek bilgi (derste anlatılmadı):** Hoca bu sonucun hesaplanabildiğini söyledi ama hesabı yapmadı. Eşit dirençlerde ortak düğüm gerilimi, üç faz geriliminin ortalamasıdır: $V_N = \frac{V_A + V_B + V_C}{3}$. Aynı genlikli ve 120° farklı üç sinüsün toplamı her an sıfırdır, dolayısıyla $V_N = 0$ olur. Toplamın sıfır olduğu python ile hesaplandı.

## 8. Köprü Devreleri

Köprü devrelerinin asıl çözümü teoremlerden sonra daha anlamlı olacak. Bu derste yalnızca bilgi olarak üzerinden geçildi.

### 8.1 Yapı ve Sık Yapılan Hata

Köprü, aynı kaynağa bağlı iki gerilim bölücüden oluşur. $R_A$ ile $R_C$ bir kolu, $R_B$ ile $R_D$ öbür kolu oluşturur. Ölçüm, iki kolun orta noktaları arasında, yani $C$ ve $D$ düğümleri arasında yapılır.

Bu devrede en çok karıştırılan şey kurulumdur. $R_A$-$R_C$ arasındaki düğüm ile $R_B$-$R_D$ arasındaki düğüm aynıymış gibi kabul edilip ikisi aynı noktaya bağlanırsa, aynı düğümde oldukları için $V_{CD}$ her zaman sıfır çıkar.

> **Hocanın vurgusu:** Fiziksel devreyi kurarken iki orta noktanın farklı noktalarda olmasına dikkat edin. Simülasyonda delikli bir breadboard kullanılmayacağı için bu sorun yaşanmaz.

> **Ders sonrası not:** Altyazıda bu uyarının ikinci söylenişinde "B ile D arasındaki düğüm ile A ile B arasındaki düğüm" geçiyor. Hocanın ilk söylediği ve devrenin gerektirdiği, $R_A$-$R_C$ ile $R_B$-$R_D$ arasındaki düğümlerdir.

### 8.2 Neden Köprü Kullanılır?

Temel amaç çevresel etkileri gidermektir. Isı gibi dış etkiler bütün dirençleri aynı şekilde etkiler. Bu özellikten sensör devrelerinde yararlanılır.

Örneğin $R_D$ yerine, nominal değeri diğer dirençlere eşit olan ama ortam sıcaklığıyla değişen bir direnç koyalım. Böylece gerilme gibi diğer etkileri giderip yalnızca sıcaklığı ölçebiliriz. Aynı şekilde D koluna nemle ya da ışıkla değişen bir eleman bağlanırsa, $V_{CD}$ uçlarında yalnızca nem miktarını gösteren bir diferansiyel fark okunur.

Bunu tek bir bölücüyle de yapabilirdik: Bir sabit direnç ve onun yanında nemden etkilenen bir direnç. Ama burada bir şeyi kaçırırız: Ortam sıcaklığı değiştiğinde ölçümümüz de değişir. Köprüde ise ortamın dört dirence birden yaptığı etki birbirini götürür.

**Sabit direnç neden gerekli?** Hoca önce "referans direnci" dediği bu direnci sonra açıkladı. Bir sabit direnç $R_F$ ve onunla seri, ortam nemine ya da sıcaklığına göre örneğin 0 ile 10 kΩ arasında değişen bir $R$ olsun. $R_F$, değişken direncin gerilim karşılığını belirli bir aralıkta tutmak için kullanılır. $R_F = 10$ kΩ ise $R$'nin gerilimi 0 ile $\frac{V}{2}$ arasında değişir.

> **Ders sonrası not:** Hoca, $R_F$ kullanılmazsa değişimin 0 ile $V$ arasında görüleceğini söyledi. Yalnız $R$ doğrudan ideal bir $V$ kaynağına bağlanırsa uçlarındaki gerilim, $R$ ne olursa olsun büyük olasılıkla hep $V$'dir ve okunabilir bir değişim oluşmaz. Değişimi gerilim olarak okumayı sağlayan şey seri dirençle kurulan bölücüdür. $\frac{V}{2}$ üst sınırı python ile hesaplandı.

<!-- BELİRSİZ: Altyazıda "R direncinde 0 ile 5 volt arasındaki değişim" geçiyor. Bu ifade büyük olasılıkla 0-10 kΩ aralığı için söylendi, devam eden cümle 0 ile V/2 diyor. -->

Köprünün mantıklı çalışması için dört direnç eşitken $V_{CD} = 0$ olmalıdır.

> **Ek bilgi (derste anlatılmadı):** $V_{CD} = 0$ için dört direncin eşit olması şart değildir. Her iki bölücünün oranının aynı olması yeter, yani $R_A R_D = R_B R_C$ koşulu yeterlidir. Bu eşitliğin $V_{CD}$'yi sıfırladığı python ile hesaplandı.

### 8.3 Diğer Köprü Yapıları

Köprü farklı biçimlerde de kurulabilir. Ardışık bağlanmış Y yapılarıyla ya da iç içe iki Δ yapısıyla aynı diferansiyel fark elde edilebilir. İç içe iki Δ durumunda ortadaki gerilim farkını ölçerken arası açık devre gibi düşünülür, yani iki Δ'nın ortak dirençleri sonsuz direnç gibi ele alınır. Y ve Δ birbirine dönüştürülebildiği için Δ ile Y'nin peş peşe bağlanmasıyla da aynı sonuç elde edilir.

### 8.4 Küçük Bir Direnç Değişiminin Etkisi

Slaytta D direncindeki küçük bir değişimin $V_{CD}$'ye etkisi inceleniyor. Uçtan uca gerilim $V_T$ olsun ve dirençlerin hepsi $R$ olsun. Hoca bunu iki gerilim bölücü olarak çözdü: C düğümü ilk bölücünün, D düğümü ikinci bölücünün orta noktasıdır. $V_{CD} = V_C - V_D$'dir. Değişim sıfırsa $V_{CD} = 0$ olur, anlamlı bir değişim varsa $V_{CD}$'de de anlamlı bir gerilim farkı oluşur.

D kolundaki direnç $R - \delta R$ alınırsa ara adımlar şöyledir (ara adım eklendi):

$$V_C = \frac{R}{R + R} V_T = \frac{V_T}{2}, \qquad V_D = \frac{R - \delta R}{2R - \delta R} V_T$$

$$V_{CD} = V_C - V_D = \frac{\delta R}{2(2R - \delta R)} V_T$$

> **Ders sonrası not:** Kısa nota göre slayttaki ara adımlar ve sonuç hatalıdır ve $\delta R = 0$ için $V_T$ verir. Altyazıda hoca sonucu $\delta R = 0$ için 0 V olarak okuduğu için slaytın tam hâli doğrulanamadı. Yukarıdaki ifade $\delta R = 0$ için 0 V verir ve küçük $\delta R$ için $V_{CD} \approx \frac{\delta R}{4R} V_T$ olur (python ile hesaplandı). $R - \delta R$ yazımı kısa nottan alındı.

<!-- BELİRSİZ: Slayttaki değişimin işareti ve formülün tam hâli altyazıda okunmuyor. -->

## 9. Düğüm ve Çevre Analizine Giriş

Buraya kadar Kirchhoff kanunlarını tek çevrimli, seri ve paralel devrelerde kullandık. Bunlar basitleştirmeyle ya da birtakım kabullerle çözülebilen yapılardı. Şimdi daha karmaşık devreler için temel iki yöntem görülecek. Asıl soru şudur: Verilen bir devreyi çözmek için kaç denkleme ihtiyacımız var ve bu denklemleri neye dayanarak yazarız?

Bir düğümün gerilim özelliğinden söz edebiliriz. Bir çevrede ise bir akımın dolaştığını kabul edebiliriz. İki yöntem bu iki bakıştan çıkar:

- **Düğüm (node) analizi:** Düğüm gerilimlerine dayanır. Komşu düğümler arasındaki gerilim farkı direnç değeriyle oranlanarak kol akımları bulunur. Çıkış noktası Kirchhoff'un akımlar kanunudur.
- **Çevre (mesh) analizi:** Her çevrenin kendine ait sanal bir çevre akımı olduğu kabul edilir. Bir elemandaki net akım, komşu çevre akımlarının yönlü toplamıdır. Çıkış noktası Kirchhoff'un gerilimler kanunudur.

Bu yöntemler, Kirchhoff kanunlarının düzenlenip daha pratik hale getirilmiş biçimidir ve birbirinin dualidir: Aynı şeyi farklı açılardan çözerler. İkisi de sonuçta bir denklem sistemi verdiği için önce denklem sistemi çözümünü konuşmak gerekir.

## 10. Doğrusal Denklem Sistemlerinin Çözümü

### 10.1 İki Bilinmeyenli Sistem

$a_1, b_1, c_1, a_2, b_2, c_2$ sabit değerler olmak üzere:

$$a_1 x + b_1 y = c_1$$

$$a_2 x + b_2 y = c_2$$

Çözümün olması için katsayı matrisinin determinantı sıfırdan farklı olmalıdır. Bunun başka bir ifadesi, iki denklemin birbirinden doğrusal bağımsız olmasıdır. Yani birinci denklemde çarpma ve bölme yaparak ikinci denklemi elde edememeliyiz. İki denklem aynı şeyse çözümü bulamayız. Determinant sıfırdan farklıysa tek (unique) çözüm vardır.

**Yerine koyma.** Birinci denklemden $x$ çekilir, ikinci denklemde yerine konur. İkinci denklem yalnız $y$'ye bağlı hale gelir. Katsayılar sabit olduğu için $y$ bir değer olarak bulunur. Bu değer $x$'in ifadesinde yerine konunca $x$ de bulunur:

$$x = \frac{c_1 b_2 - c_2 b_1}{a_1 b_2 - a_2 b_1}, \qquad y = \frac{a_1 c_2 - a_2 c_1}{a_1 b_2 - a_2 b_1}$$

Dikkat ederseniz paydalar aynıdır ve determinanta karşılık gelir.

**Matris biçimi.** Bir katsayı matrisi, bir değişken vektörü ve bir sabit vektörü vardır:

$$\begin{bmatrix} a_1 & b_1 \\ a_2 & b_2 \end{bmatrix} \begin{bmatrix} x \\ y \end{bmatrix} = \begin{bmatrix} c_1 \\ c_2 \end{bmatrix}$$

Matrisin birinci satırı sütun vektörüyle çarpılınca $a_1 x + b_1 y = c_1$, ikinci satırı çarpılınca $a_2 x + b_2 y = c_2$ çıkar. Çözümdeki payların determinant karşılıkları $D_x$ ve $D_y$ ile gösterilir:

$$x = \frac{D_x}{D}, \qquad y = \frac{D_y}{D}$$

Burada $D$, katsayı matrisinin determinantıdır ve 2×2 için çapraz çarpımların farkıdır.

**Ters matris.** Sistemi $A X = C$ diye yazalım. İki tarafı soldan $A^{-1}$ ile çarparsak birim matris oluşur ve şu sonuç çıkar:

$$X = A^{-1} C$$

Tersi hesaplarken determinanta ihtiyaç vardır. Sembolik tanımı destekleyen bir matematik aracıyla $A$ tanımlanıp tersi aldırılabilir, ya da yukarıdaki adımlar elle izlenebilir.

> **Ders sonrası not:** Hoca bu adımda "çarpmanın değişim özelliği" dedi. Matris çarpımı genelde değişmeli değildir. Burada kullanılan, büyük olasılıkla birleşme özelliğidir: $A^{-1}(AX) = (A^{-1}A)X$.

### 10.2 Üç Bilinmeyenli Sistem

Üç denklem de aynı biçimde matrise yazılır:

$$\begin{bmatrix} a_1 & b_1 & c_1 \\ a_2 & b_2 & c_2 \\ a_3 & b_3 & c_3 \end{bmatrix} \begin{bmatrix} x \\ y \\ z \end{bmatrix} = \begin{bmatrix} d_1 \\ d_2 \\ d_3 \end{bmatrix}$$

$A$ 3×3, $A^{-1}$ de 3×3 olduğu için, 3×1 boyutlu sabit vektörle çarpımı 3×1 çıkar. Bu, $X$ vektörünün boyutuyla uyumludur.

Elle çözümde $D$ katsayı matrisinin determinantıdır. $D_x$, katsayıların $a$ sütunu yerine $d_1, d_2, d_3$ konarak oluşturulur. $D_y$ için $b$ sütunu, $D_z$ için $c$ sütunu değiştirilir:

$$x = \frac{D_x}{D}, \qquad y = \frac{D_y}{D}, \qquad z = \frac{D_z}{D}$$

**3×3 determinant.** Hoca iki yolu gösterdi. İlkinde birinci satırın her elemanı ayrılır, geri kalan iki eleman için sanki 2×2 determinant hesaplanır. Hoca $a_1(b_2 c_3 - c_2 b_3)$ terimini okudu. Öbür terimler aynı mantıkla yazılır (ara adım eklendi):

$$D = a_1(b_2 c_3 - c_2 b_3) - b_1(a_2 c_3 - c_2 a_3) + c_1(a_2 b_3 - b_2 a_3)$$

İkincisinde determinantın ilk iki sütunu sağa tekrar yazılır. Sol üstten sağ alta inen köşegenlerin çarpımları artı, sağ üstten sol alta inen köşegenlerin çarpımları eksi işaretle toplanır:

$$D = a_1 b_2 c_3 + b_1 c_2 a_3 + c_1 a_2 b_3 - (c_1 b_2 a_3 + a_1 c_2 b_3 + b_1 a_2 c_3)$$

> **Ek bilgi (derste anlatılmadı):** Hoca bu yöntemlere ad vermedi. $x = \frac{D_x}{D}$ biçimindeki çözüm büyük olasılıkla Cramer kuralı, sütun tekrarlayan determinant hesabı ise Sarrus kuralı adıyla geçer. Kısa notta da bu adlar kullanıldı. İki determinant yazımının da doğru olduğu ve 2×2 çözüm formüllerinin sistemi sağladığı python ile hesaplandı.

## 11. Düğüm (Node) Analizi

### 11.1 Temel Fikir

Düğüm analizi Kirchhoff'un akımlar kanunundan çıkar. İki komşu düğüm arasında bir direnç bağlıysa, düğümler arasındaki gerilim farkının direnç değerine bölümü o koldan geçen akımı verir. İncelediğimiz düğüme birden fazla kol bağlıysa bunu hepsi için yapar ve akımlar kanununu yazarız. Bunu yeterli sayıda düğüm için tekrarlayınca devrenin bütün bilinmeyenleri, yani her düğümün gerilimi ve her kolun akımı bulunabilir hale gelir.

Düğümlerden biri **referans** olarak seçilir ve diğer bütün gerilimler buna göre tanımlanır. Referans değerini 0 seçersek $V_{\text{düğüm}} - V_{\text{ref}}$ yerine doğrudan $V_{\text{düğüm}}$ kullanırız. Bu da işlemde kolaylık sağlar.

Hatırlatma: Düğüm, iki elemanın ortak terminalidir ve arada başka eleman olmamalıdır. Tel üzerinde başka bir elemana varıncaya kadar her nokta aynı düğümdür.

### 11.2 Örnek Devre

**Verilen:** $V_{in} = 10$ V, $R_1 = 9$ kΩ, $R_2 = 2$ kΩ, $R_3 = 5$ kΩ, $R_4 = 3$ kΩ, $R_5 = 1$ kΩ, $R_6 = 7$ kΩ. Kaynağın artı ucu $V_1$ düğümündedir. $V_1$ ile $V_2$ arasında $R_1$, $V_2$ ile $V_3$ arasında $R_2$, $V_3$ ile $V_5$ arasında $R_3$, $V_3$ ile $V_4$ arasında $R_4$, $V_4$ ile $V_5$ arasında $R_5$, $V_5$ ile referans arasında $R_6$ bağlıdır.

<!-- BELİRSİZ: Altyazıda yalnız 10 V ve R2 = 2 kΩ duyuluyor. Diğer direnç değerleri ve bağlantı kısa nottan alındı. Slayt görülmedi. -->

**Düğüm sayısı.** Devrede biri referans olmak üzere 6 düğüm vardır. Referansın değeri sıfırdır.

**Akım yönleri.** Kaynağın içinde akım eksiden artıya doğru tanımlıdır. Eleman referans yönleri bununla uyumlu seçilir. Farklı yönde de seçebilirsiniz, hiç önemli değildir: Bir yönde 2 A çıkan akım ters yönde −2 A çıkar. Bir kere seçtikten sonra aynı yönü kullanmak şartıyla aynı çözüm elde edilir. Uyumlu seçmek yalnızca pratiklik sağlar.

**Akımları sadeleştirme.** Her düğüm için akımlar kanunu uygulanır:

- $V_1$ düğümü: Giren $I_7$, çıkan $I_1$. Yani $I_7 = I_1$.
- $V_2$ düğümü: Giren $I_1$, çıkan $I_2$. Yani $I_1 = I_2$.
- Referans düğümü: Giren $I_6$, çıkan $I_7$. Yani $I_6 = I_7$.
- $V_3$ düğümü: $I_2 = I_3 + I_4$.
- $V_4$ düğümü: $I_4 = I_5$.
- $V_5$ düğümü: $I_3 + I_5 = I_6$.

Demek ki $I_7, I_1, I_2, I_6$ aynı akımdır. Bu kadar ayrı işaretlemeye gerek yoktur, hepsine $I$ diyebiliriz.

**Eleman akımlarını düğüm gerilimleriyle yazma.** $R_2$'de verilen yönde akım akması için $V_2$, $V_3$'ten büyük olmalıdır. O yüzden:

$$I_2 = \frac{V_2 - V_3}{R_2}$$

Bütün elemanlar için aynısı yazılır:

$$I_1 = \frac{V_1 - V_2}{R_1}, \quad I_3 = \frac{V_3 - V_5}{R_3}, \quad I_4 = \frac{V_3 - V_4}{R_4} = \frac{V_4 - V_5}{R_5} = \frac{V_3 - V_5}{R_4 + R_5}, \quad I_6 = \frac{V_5}{R_6}$$

$I_4 = I_5$ olduğu için son eşitlik yazılabilir. $R_4$ ve $R_5$, $V_3$'ten $V_5$'e bir gerilim bölücü gibi çalışır. Ayrıca $V_1 = V_{in}$'dir, çünkü $V_1$ ile referans arasındaki fark kaynak gerilimidir.

> **Hocanın vurgusu:** $V_2$ gerilimi $V_1$'e ya da $V_3$'e göre tanımlı değildir. Bütün düğüm gerilimleri referansa göre tanımlıdır. $R_2$'nin uçları arasındaki farkın $V_2 - V_3$ olmasının nedeni budur. Bunu karıştırmayın, bu önemli bir nokta.

> **Ders sonrası not:** Hoca eleman akımını böyle yazmayı bir yerde Kirchhoff'un akımlar kanununa dayandırdı. $I = \frac{\Delta V}{R}$ ilişkisi Ohm kanunudur, hoca da derste sonradan bunu Ohm kanunu olarak andı. Akımlar kanunu, bu akımlar arasındaki denklemleri kurmak için kullanılır.

### 11.3 Denklem Sistemini Kurma

Bilinmeyenleri azaltmak için düğüm düğüm ilerleyelim.

**$V_3$ düğümü.** Giren akımla çıkan akımların yönlü toplamı sıfırdır:

$$\frac{V_2 - V_3}{R_2} - \frac{V_3 - V_5}{R_4 + R_5} - \frac{V_3 - V_5}{R_3} = 0$$

Burada $I_4$'ü $\frac{V_3 - V_4}{R_4}$ yerine $\frac{V_3 - V_5}{R_4 + R_5}$ yazarak $V_4$ bilinmeyeninden kurtulduk.

**$V_5$ düğümü.** $I_4$ ve $I_3$ girer, $I$ çıkar:

$$\frac{V_3 - V_5}{R_4 + R_5} + \frac{V_3 - V_5}{R_3} = \frac{V_5}{R_6}$$

**$V_2$ düğümü.** Giren ve çıkan akım eşittir:

$$\frac{V_{in} - V_2}{R_1} = \frac{V_2 - V_3}{R_2}$$

Bilinmeyenler $V_2, V_3, V_5$'tir. $V_{in}$ ve dirençler bilinmektedir. Yani 3 denklem, 3 bilinmeyen vardır ve katsayı matrisi 3×3 olur.

**Sabit terimler.** Bilinmeyenleri içeren terimler bir tarafa, içermeyenler öbür tarafa alınır. İlk iki denklemin sabit terimi sıfırdır. Son denklem düzenlenirse:

$$\frac{V_{in}}{R_1} - \frac{V_2}{R_1} - \frac{V_2}{R_2} + \frac{V_3}{R_2} = 0$$

Sabit terim karşıya atılınca $-\frac{V_{in}}{R_1}$ olur. Bu denklemde $V_5$'in katsayısı sıfırdır. Bu terim tek sıfırdan farklı sabit terimdir ve kaynaktan gelir.

Sayılar yerine konursa kΩ ve mA biriminde sistem şöyledir (ara adım eklendi):

$$\begin{bmatrix} \frac{1}{2} & -\frac{19}{20} & \frac{9}{20} \\ 0 & \frac{9}{20} & -\frac{83}{140} \\ -\frac{11}{18} & \frac{1}{2} & 0 \end{bmatrix} \begin{bmatrix} V_2 \\ V_3 \\ V_5 \end{bmatrix} = \begin{bmatrix} 0 \\ 0 \\ -\frac{10}{9} \end{bmatrix}$$

Çözüm için katsayı matrisinin tersi alınıp sabit vektörle soldan çarpılır. $V_4$ ise $R_4$ ve $R_5$'in oluşturduğu gerilim bölücüden bulunur:

$$V_4 = V_5 + (V_3 - V_5) \frac{R_5}{R_4 + R_5}$$

**Sonuç.** Python ile hesaplandı, slayttaki yaklaşık değerlerle ve kısa notla aynıdır:

| Düğüm | Tam değer (V) | Yaklaşık (V) |
|---|---|---|
| $V_2$ | $505/91$ | 5.55 |
| $V_3$ | $415/91$ | 4.56 |
| $V_4$ | $340/91$ | 3.74 |
| $V_5$ | $45/13$ | 3.46 |

Son adım eleman akımlarıdır: Her elemanın uçları arasındaki fark direncine bölünür, örneğin $I_2 = \frac{V_2 - V_3}{2\text{k}}$. Python ile hesaplanan akımlar şunlardır: $R_1$, $R_2$ ve $R_6$ akımı 0.495 mA, $R_3$ akımı 0.220 mA, $R_4$ ve $R_5$ akımı 0.275 mA. $0.220 + 0.275 = 0.495$ olduğu için $V_3$ düğümünde akımlar kanunu sağlanır.

**Dört denklemle de olurdu.** $\frac{V_3 - V_4}{R_4} = \frac{V_4 - V_5}{R_5}$ denklemi eklenip $V_4$ bilinmeyen olarak tutulsaydı 4 denklem, 4 bilinmeyenli bir sistem çözülürdü. Aynı kol olduğu için uzatmamak adına ikisi birlikte kullanıldı. İki yolun aynı sonucu verdiği python ile hesaplandı.

### 11.4 Yöntemin Adımları

1. Bir referans düğümü seçin. Kaynağın eksi ucu genelde uygun bir seçimdir ve oldukça pratiklik sağlar.
2. Her düğüme bir etiket verin.
3. Eleman akımlarını belirli bir referans yönünde tanımlayın.
4. Her düğüm için giren ve çıkan akımların yönlü toplamı sıfır olacak şekilde denklem yazın ve bir denklem sistemi kurun.
5. Sistemi çözerek düğüm gerilimlerini bulun.
6. Düğüm gerilimlerinden Ohm kanunuyla eleman akımlarını hesaplayın.

Devrede birden fazla kaynak varsa hangisinin referans seçileceği sorusu özel durumlar doğurur. Bunu süper düğümde göreceğiz.

## 12. Düğüm Analizi Örneği: 15 Ω Üzerindeki Akım

**Verilen:** 2 A ve 4 A akım kaynakları, seri 7 Ω ve 3 Ω, $V_1$ ile $V_2$ arasında 15 Ω, $V_2$ ile referans arasında 5 Ω. **İstenen:** 15 Ω'dan geçen akım.

**Sadeleştirme.** İstenen yalnızca 15 Ω'un akımı olduğu için 7 Ω ve 3 Ω'u tek bir 10 Ω'luk seri eşdeğer olarak yazmak sonucu etkilemez. Sadeleşmiş devrede $V_1$, $V_2$ ve referans olmak üzere 3 düğüm vardır. Referans 0 olduğu için 2 bilinmeyen kalır. İki düğüm için akımlar kanunu 2 denklem verir.

**$V_1$ düğümü.** 2 A girer, 10 Ω ve 15 Ω üzerinden akım çıkar:

$$2 - \frac{V_1 - 0}{10} - \frac{V_1 - V_2}{15} = 0$$

**$V_2$ düğümü.** 15 Ω üzerinden gelen akım ve 4 A girer, 5 Ω üzerinden akım çıkar:

$$\frac{V_1 - V_2}{15} + 4 - \frac{V_2 - 0}{5} = 0$$

**Düzenleme.** Birinci denklem şöyle yazılır:

$$\frac{V_1}{10} + \frac{V_1}{15} - \frac{V_2}{15} = 2$$

30 ile çarpılırsa $3V_1 + 2V_1 - 2V_2 = 60$ olur:

$$5V_1 - 2V_2 = 60$$

İkinci denklem şöyle yazılır:

$$\frac{V_2}{5} + \frac{V_2}{15} - \frac{V_1}{15} = 4$$

15 ile çarpılırsa $3V_2 + V_2 - V_1 = 60$ olur:

$$-V_1 + 4V_2 = 60$$

**Matris biçimi:**

$$\begin{bmatrix} 5 & -2 \\ -1 & 4 \end{bmatrix} \begin{bmatrix} V_1 \\ V_2 \end{bmatrix} = \begin{bmatrix} 60 \\ 60 \end{bmatrix}$$

**MATLAB ile çözüm.** Hoca çözümü MATLAB'da gösterdi. Aynı satırdaki elemanlar boşlukla, satırlar noktalı virgülle ayrılır. Sütun vektörü de aynı şekilde yazılır. Sonra $A^{-1} d$ hesaplanır:

```matlab
A = [5 -2; -1 4]
d = [60; 60]
inv(A) * d
```

Sonuç vektörünün birinci elemanı $V_1$, ikinci elemanı $V_2$'dir: $V_1 = 20$ V, $V_2 = 20$ V. Aynı sistem python (numpy) ile hesaplandı ve aynı sonucu verdi. MATLAB kodu çalıştırılmadı.

Elle de aynı sonuç çıkar. Python ile hesaplandı: $D = 18$, $D_x = 360$, $D_y = 360$, dolayısıyla $V_1 = V_2 = \frac{360}{18} = 20$ V.

**Bir işaret hatası.** Derste matris ilk önce $-1$ yerine $1$ ile girildi ve sonuçlar elle yapılan hesaptan farklı çıktı. Bir öğrenci hatayı fark etti, işaret düzeltilince sonuç 20 V oldu. Yanlış matrisle $V_1 \approx 16.36$ V, $V_2 \approx 10.91$ V çıkar (python ile hesaplandı).

**15 Ω'un akımı:**

$$i = \frac{V_1 - V_2}{15} = \frac{20 - 20}{15} = 0\ \text{A}$$

Bu sonucu doğrulayalım: 10 Ω'dan $\frac{20}{10} = 2$ A, 5 Ω'dan $\frac{20}{5} = 4$ A geçer. Her kaynağın akımı kendi direncinden geçtiği için 15 Ω'a akım kalmaz (ara adım eklendi).

> **Ders sonrası not:** Hoca sonucu önce "aynen kısa devre gibi" diye yorumladı, sonra kendisi düzeltti: Buradaki eleman kısa devre değildir. Kısa devre olması için 15 Ω'un direncinin 0 Ω olması gerekir. Doğrusu, iki düğüm arasında gerilim farkı olmadığıdır.

> **Ders sonrası not:** Hoca, denklem çözümündeki $\frac{D_x}{D}$ ve $\frac{D_y}{D}$ değerlerinin $A^{-1}$'in birer elemanı olduğunu söyledi. Bu değerler $A^{-1}$'in değil, $A^{-1} C$ çözüm vektörünün elemanlarıdır. Bu örnekte $A^{-1} = \frac{1}{18}\begin{bmatrix} 4 & 2 \\ 1 & 5 \end{bmatrix}$ iken $\frac{D_x}{D} = 20$'dir (python ile hesaplandı).

**Soru:** Az önceki devrede akım kaynaklarını birleştirme şansımız var mıydı? **Cevap:** Akım kaynaklarını yalnızca paralel bağlıyken birleştirebiliyorduk. Burada aradaki 15 Ω paralelliği bozuyor. Bu yüzden birleştiremeyiz, birleştirirsek farklı ve yanlış bir sonuç elde ederiz.

## 13. Süper Düğüm (Supernode)

### 13.1 Yüzen Kaynak

Düğüm analizinde kaynaklardan birinin eksi ucunu referans seçiyorduk. Peki birden fazla kaynak varsa ve birinin eksi ucu bu referansa bağlı değilse ne olur? Karşımıza öyle bir eleman çıkar ki, iki düğümü arasındaki gerilim farkı kaynağın değeri kadardır ve iki ucundaki kol akımları eşittir. Devre bu iki özellik kullanılarak çözülebilir hale gelir. Aksi halde iki ucu ayrı düğüm olarak ele alıp fazladan denklem yazmış oluruz.

Eksi ucu referans seçilen uca bağlı olmayan böyle gerilim kaynaklarına **yüzen kaynak (floating voltage source)** denir. Bu durum süper düğüm çözümüyle ele alınır.

> **Ders sonrası not:** Hocanın tanımı eksi uç üzerinden yapılıyor. Kısa nottaki tanım, uçlarından hiçbiri referansa bağlı olmayan kaynaktır. Artı ucu referansa bağlı bir kaynağın gerilimi de düğüm gerilimini doğrudan belirlediği için büyük olasılıkla kısa nottaki tanım daha geneldir.

### 13.2 Örnek Devre

**Devre:** $V_1$ kaynağı A düğümünü besler, yani $V_A = V_1$'dir. A ile C arasında $R_1$, C ile B arasında $V_2$ kaynağı vardır (artı ucu C'de, eksi ucu B'de). A ile B arasında $R_2$, B ile referans arasında $R_3$ bağlıdır. Burada $V_2$ yüzen bir kaynaktır. Dirençlerin ve kaynakların sayısal değeri verilmemiştir.

Referansın dışında A, C ve B olmak üzere 3 düğüm vardır. B düğümü için akımlar kanununu yazalım. Toplamı kolay yazmak için üç akımı da düğüme doğru seçeriz:

$$I_2 = \frac{V_A - V_B}{R_2}, \qquad I_3 = \frac{0 - V_B}{R_3} = -\frac{V_B}{R_3}$$

Üçüncü akım, kaynaktan B'ye doğru gelen $I_{V2}$'dir. Asıl sorun buradadır: **$I_{V2}$ akımını ne belirler?**

### 13.3 Kaynak Akımını Komşu Elemanlar Belirler

$I_{V2}$'yi doğrudan kaynak üzerinden tanımlayamayız, çünkü bir gerilim kaynağı üzerinden geçen akımı diğer elemanlar belirler. Burada $V_2$ ile aynı kolda olan $R_1$ belirler:

$$I_{V2} = \frac{V_A - V_C}{R_1}$$

Derste burada uzunca bir tartışma oldu. Hoca önce, daha önce $R_4$-$R_5$ kolunda yaptığımız gibi ortadaki düğümü görmezden gelip $\frac{V_A - V_B}{R_1}$ yazılabilir mi diye sordu. Sonra bunun öğrencileri şaşırtmak için söylediği bir yol olduğunu belirtti.

**Soru:** $V_A - V_B$ farkının uçları arasında zaten $R_2$ var. Neden $R_1$'e bölüyoruz? **Cevap:** $\frac{V_A - V_B}{R_2}$ zaten $I_2$ akımıdır. $I_{V2}$ ise A'dan C'ye geçen kolun akımıdır. Bu yüzden $R_1$ üzerindeki fark olan $V_A - V_C$ kullanılır. Aynı öğrenciler slaytta $V_C$ yerine $V_B + V_2$ konduğunu da gösterdi.

> **Hocanın vurgusu:** Gerilim kaynağının üzerinden geçen akımı kaynağın kendisi değil, komşu devre elemanları belirler. Süper düğümde denklemi bu özellikten hareketle yazıyoruz.

### 13.4 Kısıt Denklemi

$V_C$, $V_B$'den $V_2$ kadar yüksektir. Bunu bir çevre denklemi olarak da yazabiliriz:

$$-V_C + V_2 + V_B = 0$$

Bu denklem şöyle kurulur: Bütün düğüm gerilimleri referansa göre tanımlı olduğu için $V_C$ ve $V_B$'nin eksi ucu toprağa gider. Topraktan başlayıp C düğümünün eksisinden girer, artısından çıkarız ($-V_C$). Kaynağın artısından girer, eksisinden çıkarız ($+V_2$). B düğümünün artısından girer, eksisinden toprağa çıkarız ($+V_B$). Topraktan girip toprağa çıktığımız için bu bir çevredir.

Basitçe $V_C = V_B + V_2$ de diyebilirdik. Hoca bu notasyonun şimdilik kafa karıştırıcı görünebileceğini, ama ilerideki karmaşık düğüm denklemlerinde işe yarayacağını söyledi.

### 13.5 Tek Bilinmeyenli Denklem

$V_A = V_1$ ve $V_C = V_B + V_2$ yerine konunca:

$$I_{V2} = \frac{V_1 - (V_B + V_2)}{R_1}$$

B düğümü için akımlar kanunu şöyle olur:

$$\frac{V_1 - V_B}{R_2} - \frac{V_B}{R_3} + \frac{V_1 - V_B - V_2}{R_1} = 0$$

$V_1, V_2, R_1, R_2, R_3$ bilindiği için bu yalnız $V_B$'ye bağlı bir denklemdir. Buradan $V_B$ çekilir (ara adım eklendi):

$$V_B = \frac{\frac{V_1}{R_2} + \frac{V_1 - V_2}{R_1}}{\frac{1}{R_1} + \frac{1}{R_2} + \frac{1}{R_3}}$$

Bu ifadenin B düğümü denklemini ve $-V_C + V_2 + V_B = 0$ kısıtını sağladığı, rastgele değerler üzerinde python ile hesaplandı.

**Soru (ders sonunda, altyazıda soru duyulmuyor):** Bu örnekte hangi akımı bulmuş olduk? **Cevap:** Düğüm analiziyle düğüm gerilimlerini buluyoruz. Bilinmeyenler $V_A$ ve $V_B$ idi. Örnekte direnç değerleri verilmediği için sonucu denklem olarak bıraktık. $R_1$'den geçen akım $\frac{V_A - V_C}{R_1}$ idi. $V_C$'yi $V_B + V_2$ olarak yazabildiğimiz için bu akım $\frac{V_1 - V_B - V_2}{R_1}$ oldu ve $I_{V2}$ böyle tanımlandı.

## Dersin Toparlaması

Lab 0'da fiziksel laboratuvar aletleri tanıtıldı ve Proteus'ta basit bir devrenin nasıl kurulup ölçüldüğü gösterildi. Ampermetrenin seri, voltmetrenin paralel bağlandığı ve okunan işaretin ölçüm referansına bağlı olduğu, hem fiziksel ölçümde hem simülasyonda akılda tutulacak noktalardır.

Derste seri devrede gerilimin dirençle doğru orantılı, paralel devrede akımın dirençle ters orantılı paylaşıldığı görüldü. Y-Δ dönüşümü ve köprü devreleri bilgi olarak tanıtıldı, çözümlemeleri teoremlerden sonra yeniden ele alınacak. Ardından düğüm analiziyle herhangi bir devreyi denklem sistemine dönüştürmeyi ve yüzen gerilim kaynağı olduğunda kaynak akımını komşu elemanlardan yazmayı öğrendik.

Gelecek hafta düğüm analizi örneklerine devam edilecek ve çevre (mesh) analizine geçilecek. Aynı devre çevre denklemleriyle de çözülecek. İki yöntem aynı denklem sisteminin farklı ifadeleridir: Düğüm analizinde düğüm gerilimleri, çevre analizinde sanal çevre akımları bulunur ve oradan eleman akım ve gerilimlerine geçilir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
