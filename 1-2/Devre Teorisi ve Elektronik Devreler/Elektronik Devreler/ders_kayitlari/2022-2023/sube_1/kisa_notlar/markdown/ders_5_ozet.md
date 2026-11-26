# Ders 5 Çalışma Özeti

## Genel Konular

- Diyot: iki uçlu, tek yönde ileten eleman
  - Diyot, direnç gibi iki uçlu bir devre elemanıdır. Sembolü bir üçgen ve bir çizgidir: üçgen tarafı artı uç (anot), çizgi tarafı eksi uçtur (katot) (ekrandan, 00:05:00).
  - İdeal diyot akımı yalnız bir yönde iletir. Artı ucundaki gerilim eksi ucundakinden yüksekse ($V_D > 0$) kısa devre gibi davranır; akımı devrenin geri kalanı sınırlar. $V_D < 0$ ise açık devre gibi davranır, $I_D = 0$ olur (ekrandan, 00:05:00).
- Gerilim tanımı ve referans yönü
  - Bir elemanın üzerindeki gerilim, artı ucu a, eksi ucu b olarak tanımlanırsa $V_X = V_A - V_B$ olur. $V_A$ ve $V_B$, o noktaların toprağa göre gerilimleridir (ekrandan, 00:15:00).
  - Uçların tanımı ters seçilirse $V_X = V_B - V_A$ olur. Değerlendirme hep artıdan eksiye tanımlanan referans yönüne göre yapılır.
  - İletim için önemli olan uçların mutlak gerilimi değil farkıdır: anot 5,1 V, katot 5 V ise $V_D = 0{,}1$ V'tur ve ideal diyot iletir. İki uç da 5 V ise $V_D = 0$ olur, akım akmaz.
- İdeal diyot karakteristiği
  - $V_D < 0$ bölgesinde $I_D = 0$; $V_D$ sıfırı geçtiği anda akım akmaya başlar. $I_D$–$V_D$ grafiği negatif eksen boyunca sıfırda kalan, sıfırda dikey yükselen bir eğridir (ekrandan, 00:15:00).
- Yarı iletken malzemeler ve p-n eklemi
  - Diyot ve transistörler yarı iletkenden üretilir. Temel malzemeler silisyum (Si), germanyum (Ge) ve galyum arsenit (GaAs) bileşiğidir.
  - Saf malzemeye başka atomlar eklenmesine katkılama (doping) denir. Böylece iki tip malzeme elde edilir: n tipi (iletim bandında fazla elektron) ve p tipi (valans bandında delikler).
  - p tipi ve n tipi malzemenin birleştirilmesine p-n eklemi (jonksiyonu) denir. Bu en basit diyot yapısıdır; transistörler daha çok katmanlı yapılardır.
  - Eklemde n tarafındaki fazla elektronlar p tarafındaki deliklere çekilir; eklem çevresinde hareketli taşıyıcıların azaldığı bir geçiş bölgesi oluşur: tükenme bölgesi (depletion region), uzay yükü katmanı da denir (ekrandan, 00:20:00).
  - Bu bölgede bir potansiyel farkı, yani potansiyel bariyeri oluşur. Gerçek diyotun iletmesi için bu bariyerin aşılması gerekir.
- Doğru ve ters kutuplama
  - Doğru kutuplama (forward bias): anot katottan yeterince yüksektir; bariyer düşer, tükenme bölgesi daralır, çoğunluk taşıyıcı akımı hızla artar (ekrandan, 00:25:00).
  - Ters kutuplama (reverse bias): ters gerilim bariyeri yükseltir, tükenme bölgesi genişler; yalnız küçük bir sızıntı akımı ($I_s$) akar. Bu durum açık devreye karşılık gelir.
  - Kutuplamasız durum: $V_D = 0$, $I_D = 0$.
- Gerçek diyot karakteristiği
  - Akım bağıntısı: $I \approx I_s\left(\exp\frac{eV}{kT} - 1\right)$; oda sıcaklığında $e/kT \approx 40\ \text{V}^{-1}$ (ekrandan, 00:30:00).
  - $V > +0{,}1$ V için $I \approx I_s \exp(40V)$; $V < -0{,}1$ V için $I \approx -I_s$. $I_s$, ters doyma akımıdır (ekrandan, 00:30:00).
  - Gerçek eğride akım belirgin olarak Si için yaklaşık 0,7 V, Ge için yaklaşık 0,3 V, GaAs için yaklaşık 1,2 V civarında yükselir.
  - Kitaptaki karakteristikte ileri bölge mA, ters bölge µA ölçeğindedir; ölçeklere dikkat edilmelidir (ekrandan, 00:35:00).
- Zener bölgesi ve zener diyot
  - Ters gerilim çok artırılınca belli bir $V_Z$ geriliminden sonra ters yönde akım hızla artar. Bu bölgeye zener bölgesi denir.
  - Zener diyot bu bölgede, ters kutuplamada çalıştırılmak için üretilir. Sembolde katot çizgisinin uçları kıvrıktır. Yaygın zener gerilimleri 1,8 V ile 200 V arasındadır (ekrandan, 00:45:00).
- Sıcaklık etkisi
  - Sıcaklık arttıkça diyota enerji eklenir: iletim için gereken ileri gerilim azalır, ters akım artar, en büyük ters çığ gerilimi artar. Germanyum diyotlar sıcaklığa silisyum ve GaAs diyotlardan daha duyarlıdır (ekrandan, 00:40:00).
- Gerçek diyot modeli, kılıflar ve test
  - Gerçek (ideal olmayan) diyot üç parçayla modellenir: ideal diyot, bariyeri temsil eden bir DC gerilim kaynağı (Si için 0,7 V) ve iç direnç.
  - Kılıf üzerinde katot tarafı genellikle bir çizgiyle işaretlenir. Güç uygulamaları için farklı kılıflar, kartlara yüzeyden monte edilen SMD (Surface Mount Device) tipleri vardır.
  - Ohmmetre ile test: kırmızı uç anotta, siyah uç katottayken düşük direnç, ters bağlanınca yüksek direnç okunur. Düşük direnç okunan bağlantıda kırmızı ucun değdiği taraf anottur.
- LED ve diyot dizileri
  - LED (ışık yayan diyot), üzerinden akım geçince ışık yayar. Kırmızı, yeşil ve mavi LED'lerden oluşan bir hücre bir piksel gibi düşünülebilir: kırmızı ve yeşil birlikte yanınca sarı, kırmızı ve mavi birlikte yanınca mor elde edilir.
  - Birden çok diyot tek bir entegre devre (DIP kılıf) içinde paketlenebilir. Ortak anotlu dizide ortak uca +5 V verilir, yakılmak istenen diyotun ucu 0 V'a çekilir; ortak katotlu dizide ortak uç toprağa bağlanır, ilgili uca 5 V verilir (ekrandan, 00:50:00).
- Seri diyot devresi
  - En basit devre: kaynak $E$, direnç $R$ (yük) ve bir Si diyot seri bağlıdır. Yük direnci, devrede enerjiyi kullanan elemanı (ekran, motor vb.) temsil eder.
  - Doğru kutuplamada ($E > 0{,}7$ V): $V_D = 0{,}7$ V, $V_R = E - V_D$, $I_D = I_R = V_R / R$.
  - Ters kutuplamada: $I_D = I_R = 0$, $V_R = 0$, $V_D = E$; kaynak geriliminin tamamı diyot üzerine düşer (ekrandan, 00:55:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Gerilim hep referans yönüne göre okunur
  - $V_X = V_A - V_B$ tanımında artı ucun hangi tarafa konduğu sonucu belirler. Diyotun iletip iletmediğine karar verirken uçların toprağa göre değerleri değil, aradaki fark ($V_D$) bakılır.
- İdeal ile gerçek diyot farkı
  - İdeal diyot sıfırı geçince iletir; gerçek diyotun potansiyel bariyerini aşması gerekir (Si 0,7 V, Ge 0,3 V). Ters bölgede de sıfır değil, küçük bir sızıntı akımı vardır.
- İletimdeki Si diyotun gerilimi 0,7 V'ta kalır
  - Bir öğrenci sorusu üzerine: Si diyot iletime geçtikten sonra da üzerinde yaklaşık 0,7 V kalır, çünkü modeldeki bariyer gerilimi iletimde de vardır. Germanyumda bu değer 0,3 V'tur.
- Zener diyot normal diyotun tersine bağlanır
  - Zener diyot ters kutuplamada, belirli bir gerilimde akım akıtmak için kullanılır. Normal diyottan ayırt etmek için sembolü farklı çizilir.

## Kısa Tekrar Notları

- Diyot: iki uçlu, ideal halde tek yönde ileten eleman; anot (+, p), katot (−, n).
- $V_X = V_A - V_B$; referans yönü artıdan eksiye.
- İdeal: $V_D > 0$ kısa devre, $V_D < 0$ açık devre.
- n tipi: fazla elektron; p tipi: delik. p-n ekleminde tükenme bölgesi ve potansiyel bariyeri oluşur.
- Doğru kutuplama bariyeri düşürür, ters kutuplama yükseltir; ters bölgede yalnız $I_s$ akar.
- $I \approx I_s(e^{eV/kT} - 1)$, $e/kT \approx 40\ \text{V}^{-1}$.
- Eşik gerilimleri: Si 0,7 V, Ge 0,3 V, GaAs 1,2 V.
- Zener: ters kutuplamada $V_Z$'de çalışır; $V_Z$ yaygın olarak 1,8–200 V.
- Sıcaklık artınca: eşik gerilimi azalır, ters akım artar; Ge daha duyarlıdır.
- Gerçek diyot modeli: ideal diyot + 0,7 V kaynak + iç direnç.
- Seri devre, doğru kutuplama: $V_R = E - 0{,}7$, $I = V_R/R$. Ters kutuplama: $I = 0$, $V_R = 0$, $V_D = E$.
- Örnek: $E = 10$ V, $R = 330\ \Omega$, paralel iki Si diyot: $V_R = 9{,}3$ V, $I \approx 28$ mA, her diyottan yaklaşık 14 mA.

## Detaylı Açıklamalar

- **İdeal diyot ve gerilim tanımı.** Diyotun davranışını anlamak için önce üzerindeki gerilimin nasıl tanımlandığını bilmek gerekir. Bir elemanın a ucu artı, b ucu eksi olarak işaretlenirse eleman üzerindeki gerilim $V_X = V_A - V_B$ olur; $V_A$ ve $V_B$ o noktaların toprağa göre gerilimleridir. Diyotta artı uç anottur, dolayısıyla $V_D = V_A - V_B$. İdeal diyot için $V_D$ sıfırdan biraz bile büyükse (örneğin anot 5,1 V, katot 5 V iken $V_D = 0{,}1$ V) diyot kısa devre gibi davranır ve akımı dış devre belirler. $V_D$ negatifse (örneğin −1 V, −2 V) diyot açık devre gibi davranır ve $I_D = 0$ olur. İki ucun gerilimi eşitse (ikisi de 5 V gibi) fark sıfırdır ve akım akmaz.

- **p-n eklemi ve potansiyel bariyeri.** Silisyum, germanyum ya da galyum arsenit gibi saf yarı iletkenlere katkılama yapılarak n tipi ve p tipi malzemeler üretilir. Bu iki malzeme birleştirilince n tarafındaki fazla elektronlar p tarafındaki deliklere doğru göç eder. Eklem çevresinde hareketli taşıyıcıların azaldığı tükenme bölgesi oluşur ve bu bölgede bir potansiyel farkı (bariyer) meydana gelir. İdeal modelde bu bariyer yok sayılır; gerçek diyotta ise iletim için bu bariyerin aşılması gerekir. Bu yüzden silisyum diyot yaklaşık 0,7 V'tan sonra belirgin akım akıtır.

- **Kutuplama durumları.** Doğru kutuplamada dış gerilim bariyeri düşürür, tükenme bölgesi daralır ve çoğunluk taşıyıcılarının akımı gerilimle üstel olarak artar. Ters kutuplamada bariyer yükselir, tükenme bölgesi genişler; yalnızca sabite yakın küçük bir sızıntı akımı ($I_s$) akar. Bu davranış $I \approx I_s(\exp(eV/kT) - 1)$ bağıntısıyla özetlenir: oda sıcaklığında $e/kT \approx 40\ \text{V}^{-1}$ olduğundan $V > 0{,}1$ V iken akım $I_s \exp(40V)$ gibi hızla büyür, $V < -0{,}1$ V iken $-I_s$ değerinde kalır (ekrandan, 00:30:00). Diyot karakteristiği osiloskop ya da karakteristik çıkarıcı (analizör) ile doğrudan gözlenebilir.

- **Zener bölgesi.** Ters gerilim belli bir değeri ($V_Z$) aşınca ters yöndeki akım hızla artar. Normal diyotta istenmeyen bu davranış, zener diyotta bilerek kullanılır: zener diyot ters bağlanır ve örneğin 5 V'luk bir zener, gerilim bu değeri biraz aştığında akım akıtır. Üretim sırasında $V_Z$ ayarlanabildiği için 1,8 V ile 200 V arasında farklı zener diyotlar bulunur (ekrandan, 00:45:00).

- **Sıcaklık ve gerçek diyot modeli.** Sıcaklık yarı iletkene enerji ekler; ileri kutuplamada eşik gerilimi düşer, ters kutuplamada sızıntı akımı artar (ekrandan, 00:40:00). Gerçek diyot, ideal diyot ile seri bir DC gerilim kaynağı (bariyer gerilimi) ve bir iç dirençten oluşan eşdeğer devreyle modellenir. Diyotun DC ve AC'de gösterdiği dirençler derste ayrıntılandırılmadı.

- **Seri ve paralel diyotlu devre örnekleri.** Kaynak, direnç ve Si diyottan oluşan seri devrede diyot iletimdeyse $V_R = E - 0{,}7$ V ve $I_D = I_R = V_R/R$ olur. Diyot ters bağlıysa akım akmaz; direnç üzerinde gerilim düşmez ($V_R = 0$), dolayısıyla direncin alt ucu ile üst ucu aynı potansiyeldedir ve kaynağın tüm gerilimi diyotun üzerine düşer ($V_D = E$) (ekrandan, 00:55:00). Derste çözülen sayısal örnekte 10 V kaynak, 330 Ω direnç ve birbirine paralel iki Si diyot vardır: diyotlar iletimde olduğundan ortak düğüm 0,7 V'tadır, direnç gerilimi $10 - 0{,}7 = 9{,}3$ V, ana kol akımı $9{,}3/330 \approx 28$ mA'dir ve özdeş diyotlar bu akımı eşit paylaşarak her biri yaklaşık 14 mA taşır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
