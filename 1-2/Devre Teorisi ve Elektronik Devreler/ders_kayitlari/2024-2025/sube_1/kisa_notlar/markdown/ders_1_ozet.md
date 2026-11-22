# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin akademik kapsamı
  - Ders, eskiden ayrı olan Devre Teorisi ve Elektronik derslerinin birleştirilmiş hâlidir; konular azaltılmış ve daha temel düzeyde verilmektedir.
  - Dönemin ilk yarısı devre teorisidir: temel kavramlar ve Ohm yasası, KCL ve KVL, seri-paralel bağlama, akım ve gerilim bölücüler, çevre akımları (mesh) ve düğüm gerilimleri (node) analizi, süperpozisyon, kaynak dönüşümü, Thevenin ve Norton teoremleri, enerji depolayan elemanlar (bobin, kondansatör), kaynaksız RL ve RC devreleri, RLC devreleri (aşırı sönümlü, kritik sönümlü, az sönümlü çözüm) (ekrandan, 00:15:00).
  - Alternatif akım (AC) analizi bu birleştirilmiş müfredatta yoktur; yalnız DC analiz yapılır.
  - Dönemin ikinci yarısı elektroniktir: yarı iletkenler, diyot, BJT ve FET (MOSFET) transistörler, işlemsel yükselteç (op-amp).
  - Devre teorisi iletken elemanlarla (direnç, bobin, kondansatör), elektronik ise yarı iletken malzemelerle ilgilenir.
- Ölçü birimleri ve SI sistemi
  - SI (International System of Units) 1960'ta kabul edilmiş, temel birimleri tanımlayan standarttır: uzunluk (metre), kütle (kilogram), zaman (saniye), elektrik akımı (amper), termodinamik sıcaklık (kelvin), ışık şiddeti (kandela).
  - Birimler 10'un kuvvetleriyle ifade edilen öneklerle büyütülüp küçültülür.
  - Derste en çok kullanılacak önekler: giga ($10^{9}$), mega ($10^{6}$), kilo ($10^{3}$), mili ($10^{-3}$), mikro ($10^{-6}$), nano ($10^{-9}$), piko ($10^{-12}$).
- Birim tutarlılığı ve yuvarlama
  - Bir denkleme konan sayı, denklemin beklediği birimde olmalıdır. Hız örneği: $d = 4000$ m, $t = 1$ dk, $v$ km/sa isteniyorsa $v = 4000 \times 10^{-3} / (1/60) = 240$ km/sa olur; $4000/1 = 4000$ yanlıştır (ekrandan, 00:30:00).
  - Yuvarlama, istenen basamak sayısına göre doğru kuralla yapılmalıdır (atılan basamak 5 veya üstüyse bir üst değere yuvarlanır).
  - Üslü sayılarda çarpmada üsler toplanır, bölmede çıkarılır, üssün üssünde çarpılır; toplama ve çıkarmada önce 10'un kuvveti ortak yapılır.
- Bilimsel ve mühendislik gösterimi (ekrandan, 00:35:00)
  - Bilimsel gösterim: ondalık noktanın solunda tek bir sıfırdan farklı basamak olur. $1/3 = 3.33\text{E}{-1}$, $1/16 = 6.25\text{E}{-2}$, $2300/2 = 1.15\text{E}3$.
  - Mühendislik gösterimi: üs 3'ün katıdır, noktanın solunda 1-3 basamak bulunur. $1/3 = 333.33\text{E}{-3}$, $1/16 = 62.50\text{E}{-3}$, $2300/2 = 1.15\text{E}3$.
- Elektrik akımı ve su benzetmesi
  - Elektronlar negatif yüklüdür; pozitif uca doğru hareket ederler. Geleneksel elektrik akımının yönü elektron hareketinin tersidir (artıdan eksiye).
  - Su yüksek seviyeden alçağa aktığı gibi elektrik de yüksek gerilimden düşük gerilime akar (ekrandan, 00:40:00).
  - İki nokta arasındaki gerilim farkına potansiyel fark denir; akım oluşması için potansiyel fark gerekir.
  - Gerilimler bir referans noktasına (toprak, ground) göre ölçülür; "12 V" demek bir ucu toprağa bağlıyken ölçülen değerdir.
  - Akımın birimi amperdir (A) (ekrandan, 00:45:00).
- Devre elemanları (ekrandan, 00:50:00)
  - Aktif elemanlar: bağımsız ve bağımlı kaynaklar (gerilim kaynağı, akım kaynağı).
  - Pasif elemanlar: direnç, kondansatör, bobin.
  - Ölçü aletleri: ampermetre (akım), voltmetre (gerilim), avometre (ikisi bir arada).
  - Toprak (referans noktası), elektrik kablosu, anahtarlar, koruma elemanı olarak sigorta.
- Ölçü aletlerinin bağlanması
  - Ampermetre devreye seri bağlanır; akımın aletin içinden geçmesi gerekir.
  - Voltmetre ölçülecek elemana paralel bağlanır.
  - Avometrede ölçüm türüne uygun ayar seçilmezse koruma sigortası yanar.
- Kaynakların gösterimi ve güç işareti
  - Bağımsız kaynaklar daire, bağımlı kaynaklar baklava (karo) biçiminde çizilir. Pil sembolünde uzun çizgi artı, kısa çizgi eksi uçtur.
  - Pasif işaret kuralı: akımın girdiği uç artı, çıktığı uç eksi kabul edilir. Akım bir elemanın artı ucundan giriyorsa eleman güç tüketir ($p > 0$); artı ucundan çıkıyorsa güç üretir ($p < 0$).
  - Bir devrede bütün elemanların güçleri toplamı sıfırdır (enerjinin korunumu).
  - Bağımlı kaynak türleri: VCVS, CCVS, VCCS, CCCS (ekrandan, 01:00:00). Örneğin değeri $5V_{R1}$ olan bir kaynak, $R_1$ direncindeki gerilimin 5 katını üretir.
- Pasif elemanların birimleri
  - Direnç: ohm ($\Omega$), sembolü zikzak.
  - Bobin (indüktör): henri (H), sık sarılmış bakır tel; sembolü sarım biçimindedir.
  - Kondansatör: farad (F), sembolü iki plakadır; kutuplu ve kutupsuz türleri vardır.
- Kablolar ve AWG (ekrandan, 01:05:00)
  - Teoride kablonun direnci sıfır kabul edilir (ideal iletken); kablo boyunca her noktada gerilim aynıdır. Gerçekte kablonun uzunluğa bağlı bir direnci vardır.
  - AWG (American Wire Gauge) numarası büyüdükçe kablo çapı küçülür, direnç artar ve taşınabilecek akım azalır.
  - Ev tesisatı tipik olarak AWG 12 veya 14, telefon kablosu 22, 24 veya 26'dır.
  - Teoride kaynakların üzerinde yazan değeri tam ürettiği varsayılır; gerçekte 9 V'luk pil örneğin 8.87 V verebilir.
- Yük, akım, gerilim ve güç
  - Elektronun yükünün mutlak değeri $1.6 \times 10^{-19}$ C'dir; yük $Q$ veya $q$ ile gösterilir (ekrandan, 01:10:00).
  - Büyük harf sabit (kararlı durum) değeri, küçük harf zamanla değişen (anlık) değeri gösterir.
  - Akım, yükün zamana göre değişimidir: $i = \dfrac{dq}{dt}$. Tersinden $Q = \int_{t_1}^{t_2} i\,dt$.
  - DC (doğru akım) zamanla değişmez; AC (alternatif akım) zamanla yön ve büyüklük değiştirir (ekrandan, 01:15:00).
  - Gerilim, birim yük başına enerjidir: $v = \dfrac{dw}{dq}$ (J/C = V).
  - Güç, enerjinin zamana göre değişimidir: $p = \dfrac{dw}{dt} = \dfrac{dw}{dq}\cdot\dfrac{dq}{dt} = v\,i$, birimi watt (W) (ekrandan, 01:20:00).
- Ohm yasası
  - Su benzetmesinde gerilimi artırmak suyu artırmaya ya da kabı yükseltmeye, direnci artırmak suyun aktığı deliği daraltmaya karşılık gelir (ekrandan, 01:25:00).
  - $V = I \cdot R$: $R$ sabitken $V$ artarsa akım artar; $V$ sabitken $R$ artarsa akım azalır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Birim ve önek hataları
  - Öğrencilerin en sık yaptığı hata, kilo, mega, mili, mikro gibi önekli değerleri temel birime çevirmeden çarpıp bölmektir. Örneğin kiloohm ile kiloamper doğrudan çarpılırsa sonuç volt değil, $10^{6}$ katı olan bir değer olur.
  - Mili ($10^{-3}$) ile mikro ($10^{-6}$) sık karıştırılır.
- KCL ve KVL
  - Bir sonraki konu olan Kirchhoff akım ve gerilim yasaları bütün dönemi, elektronik kısmını da etkiler; mutlaka öğrenilmelidir.
- Güç işareti
  - Üreten elemanın gücü negatif, tüketen elemanın gücü pozitiftir; "ters mantık" gibi görünse de hesaplar akımın yönüne göre yapılır.
- $i = dq/dt$ ve $p = vi$
  - $i = dq/dt$ formülü bilinmelidir. $p = vi$ formülünün enerji ve yük tanımlarından nasıl çıktığı da önemlidir.
- Avometre kullanımı
  - Akım ölçerken ampermetre, gerilim ölçerken voltmetre konumu seçilmelidir; yanlış konumda bağlantı sigortayı yakar.

## Kısa Tekrar Notları

- Önekler: G $10^{9}$, M $10^{6}$, k $10^{3}$, m $10^{-3}$, $\mu$ $10^{-6}$, n $10^{-9}$, p $10^{-12}$.
- Hesaptan önce bütün değerleri temel birime çevir.
- Bilimsel gösterim: noktanın solunda tek basamak. Mühendislik gösterimi: üs 3'ün katı.
- Geleneksel akım yönü elektron hareketinin tersidir.
- Akım için potansiyel fark gerekir; gerilim toprağa göre ölçülür.
- Ampermetre seri, voltmetre paralel bağlanır.
- Akım artı uçtan giriyorsa $p > 0$ (tüketir), artı uçtan çıkıyorsa $p < 0$ (üretir); $\sum p = 0$.
- Bağımsız kaynak daire, bağımlı kaynak baklava biçimindedir.
- Teoride kablo direnci sıfırdır; AWG numarası büyüdükçe kablo incelir.
- $i = dq/dt$, $v = dw/dq$, $p = dw/dt = vi$.
- $V = IR$; örnek: $10$ V ve $4$ k$\Omega$ için $I = 2.5$ mA, $P = 25$ mW.

## Detaylı Açıklamalar

- **Birim dönüşümü neden önemli?** Formüller temel birimlerle tanımlıdır. Hız örneğinde mesafe metre, zaman dakika verilmiş ama sonuç km/sa istenmiştir. Doğru yol mesafeyi kilometreye ($4000 \times 10^{-3} = 4$ km), zamanı saate ($1/60$ sa) çevirip bölmektir: $4 / (1/60) = 240$ km/sa (ekrandan, 00:30:00). Aynı durum Ohm yasasında da geçerlidir: direnç kiloohm, akım kiloamper verilmişse ikisini doğrudan çarpmak $10^{6}$ çarpanını kaybettirir. Değerler önce temel birime (ohm, amper) çevrilir.
- **Gösterimler.** Bilimsel gösterimde $1/3$, $3.33\text{E}{-1}$ diye yazılır; noktanın solunda 1-9 arası tek basamak bulunur. Mühendislik gösteriminde üs 3'ün katı seçilir ($\text{E}{-3}$, $\text{E}3$ gibi), böylece değer doğrudan bir önekle (mili, kilo) okunabilir: $1/3 = 333.33\text{E}{-3}$, $1/16 = 62.50\text{E}{-3}$ (ekrandan, 00:35:00). Hoca sorularda daha çok bilimsel gösterimi kullandıklarını söyledi.
- **Akımın oluşumu.** Bir malzemeye gerilim uygulandığında negatif yüklü elektronlar artı uca doğru çekilir. Elektronların hareket yönü elektron akımıdır; devre teorisinde kullanılan elektrik akımının yönü bunun tersidir, yani artıdan eksiye doğrudur. Su benzetmesinde iki kap arasındaki yükseklik farkı potansiyel farka, kaptaki su miktarı da akan akımın büyüklüğüne karşılık gelir. Yükseklik farkı ne kadar büyükse su o kadar şiddetli akar; benzer şekilde potansiyel fark büyüdükçe akım artar. Örneğin bir uçta 10 V, diğerinde 2 V varsa potansiyel fark 8 V'tur; +20 V ile −20 V arasında ise 40 V'tur.
- **Ölçü aletleri.** Akım bir kablonun içinden geçen büyüklük olduğu için ampermetre devre açılıp araya seri bağlanır; akım aletin içinden geçerek devreyi tamamlar. Gerilim bir elemanın üzerindeki büyüklük olduğu için voltmetrenin uçları elemanın iki ucuna paralel dokundurulur. Avometre ikisini bir arada yaptığından konum seçimi kritiktir; yanlış konumda bağlantı, cihazı koruyan sigortanın yanmasına yol açar.
- **Güç ve işaret kuralı.** Örnek 1'de (ekrandan, 00:55:00) 3 A'lik bağımsız akım kaynağı, üzerinde 1 V düşen bir elemana doğrudan bağlıdır. Akım elemanın artı ucundan girdiği için eleman $p = 3 \times 1 = 3$ W tüketir. Akım kaynağında akım artı uçtan çıktığı için kaynak $p = -3 \times 1 = -3$ W üretir. Toplam $3 + (-3) = 0$ olur; bu enerjinin korunumunun sonucudur.
- **Bağımlı kaynaklar.** Değeri sabit bir sayı yerine devredeki başka bir gerilim ya da akıma bağlı olan kaynaklardır. Baklava sembolüyle çizilir. Değerini bulmak için önce kontrol eden büyüklük (örneğin $R_1$ üzerindeki gerilim) hesaplanır, sonra katsayıyla çarpılır.
- **Yükten güce.** Akım yükün zamana göre değişim hızıdır ($i = dq/dt$); zamanla değiştiği için küçük harfle yazılır, DC'de büyük $I$ kullanılır. Gerilim birim yük başına enerjidir ($v = dw/dq$). Güç, enerjinin zamana göre değişimi olduğundan zincir kuralıyla $p = \frac{dw}{dt} = \frac{dw}{dq}\cdot\frac{dq}{dt} = v\,i$ elde edilir (ekrandan, 01:20:00). Yani $P = VI$ formülü ezber değil, bu tanımların sonucudur.
- **DC ve AC.** DC kaynakta (örneğin pil) gerilim zamanla değişmez ve akım sabittir. AC kaynakta gerilim periyodik olarak artı ve eksi değerler alır (ekrandan, 01:15:00). Hocaya göre DC daha kararlı ve kolay devre tasarımı sağlar ve düşük gerilimli cihazlarda kullanılır; uzak mesafeli yüksek gerilim iletiminde ise AC tercih edilir.
- **Ohm yasası örneği.** 10 V kaynak ve 4 k$\Omega$ dirençli devrede $I = V/R = 10 / (4 \times 10^{3}) = 2.5 \times 10^{-3}$ A $= 2.5$ mA bulunur. Direnç $10 \times 2.5$ mA $= 25$ mW tüketir, kaynak $-25$ mW üretir. <!-- BELİRSİZ: bu örneğin devre şekli karelerde görünmüyor; değerler altyazıdan alındı. -->
- **Ders sonrası not:** Hoca bu örnekte gücü bir an "25 watt" diye söyledi; doğrusu 25 mW'tır. Kaynağın gücü de $-25$ mW olmalıdır.
- **Ders sonrası not:** Hoca SI temel birimleri arasında elektrik yükünü de saydı. SI'nin yedinci temel birimi büyük olasılıkla madde miktarı (mol) olmalıdır; yükün birimi coulomb türetilmiş bir birimdir ($1\ \text{C} = 1\ \text{A}\cdot\text{s}$).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
