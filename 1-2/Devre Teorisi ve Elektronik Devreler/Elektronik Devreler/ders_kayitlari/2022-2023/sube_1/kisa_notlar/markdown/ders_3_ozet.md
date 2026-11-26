# Ders 3 Çalışma Özeti

## Genel Konular

- Dersin kaynak kitabı
  - Dersin ana kaynağı Boylestad'ın *Electronic Devices and Circuit Theory* kitabıdır. Kitabın çeşitli baskıları ve Türkçe çevirisi vardır; derste kitabın slaytları ve ayrı soru slaytları kullanılır.
- Analog (sürekli) dünya ve sayısal (ayrık) dünya
  - Dış dünyadaki büyüklükler süreklidir: ses gibi bir boyutlu işaretler zamanın her anında, görüntü gibi iki boyutlu işaretler düzlemin her noktasında tanımlıdır. İki boyutlu işaretlerin tanımlandığı düzlem mekânsal ya da uzamsal (spatial) olarak adlandırılır (ekrandan, 00:15:00).
  - MR gibi tıbbi cihazlarda $x$, $y$ yanında $z$ de eklenir; bu çok boyutlu (N boyutlu) işaretlere örnektir (ekrandan, 00:20:00).
  - Bu verileri işlemek için mikroişlemci ya da mikrodenetleyici ve hafıza içeren sayısal sistemler gerekir. Bilgisayar yalnız masaüstü ya da dizüstü değildir; telefon, tablet gibi algoritma çalıştırabilen her cihaz "computer", yani hesaplayıcıdır.
  - Sayısal dünyada veriler ayrıktır (discrete).
- Analogdan sayısala geçişin adımları
  - Önce bir sensör (algılayıcı) gerekir: ses için mikrofon, görüntü için fotoğraf makinesi, tıpta MR cihazı. Sensör fiziksel büyüklüğü elektriksel işarete çevirir.
  - Elektriksel işaret hâlâ süreklidir; iki an arasında sonsuz değer vardır. Bu yüzden işaretten belirli aralıklarla örnek alınır (örnekleme, sampling).
  - İki boyutlu işaretlerde $x$ ve $y$ yönünde alınan örneklere piksel denir.
  - Ardından örneklerin genlikleri sınırlı sayıda düzeye yuvarlanır (nicemleme, quantization) ve ikili sayılar olarak hafızaya yazılır.
- Örnekleme periyodu seçimi
  - Örnekleme periyodu $T_s$ ile gösterilir (ekrandan, 00:25:00).
  - Çok sık örnekleme işareti asıla yakın saklar, ama hafıza ihtiyacı ve hesaplama karmaşıklığı artar.
  - Seyrek örnekleme yer kazandırır, ama aradaki önemli değişimler (işaretin karakteristiği) kaybolabilir.
  - Amaç, bilgi kaybını en aza indirerek $T_s$'yi olabildiğince geniş, yani optimal seçmektir. Bunun cevabı Fourier analizinden gelir.
- Sinüzoidal işaret ve parametreleri
  - Genel sinüzoidal işaret $x(t) = A\sin(2\pi f t + \varphi)$ biçimindedir (ekrandan, 00:35:00). Bir sinüsü diğerinden ayıran üç parametre genlik $A$, frekans $f$ (ya da periyot $T$) ve faz $\varphi$'dir.
  - Genlik: $\sin$ değeri $-1$ ile $1$ arasındadır; $A$ ile çarpılınca işaret $-A$ ile $A$ arasında salınır.
  - Periyot bir çevrimin (cycle) süresidir, birimi saniyedir. Frekans bir saniyedeki çevrim sayısıdır, birimi Hz'dir ve $T = 1/f$ olur.
  - Faz, işaretin başlangıç kaymasıdır. Tam bir periyot $360^\circ$ ya da $2\pi$ radyandır. Çeyrek periyotluk kayma $360^\circ/4 = 90^\circ$, yani $2\pi/4 = \pi/2$ radyandır (ekrandan, 00:35:00).
  - Sinüs ve kosinüs ayrı işaretler değildir; frekansı ve genliği aynı, aralarında $90^\circ$ faz farkı olan aynı sinüzoidal biçimdir.
- DC ve AC işaretler
  - $f = 0$ olan işaret salınım yapmaz, zamanla sabittir: DC (Direct Current, doğru akım). Örnek: 1,5 V'luk pil.
  - $f > 0$ olan işaretler salınır: AC (Alternating Current, alternatif akım) (ekrandan, 00:40:00).
  - Evdeki prizden AC işaret alınır; Türkiye'de 220 V, 50 Hz'dir. ABD'de 110 V, 60 Hz kullanılır; Avrupa standardı genellikle 50 Hz'dir.
- Fourier analizi
  - Keyfi (arbitrary) bir fonksiyon, frekansı 0'dan sonsuza kadar sürekli değişen sinüzoidallerin toplamı olarak yazılabilir (ekrandan, 00:45:00).
  - İlk bileşen $f = 0$'daki DC bileşendir ve işaretin ortalamasıdır. AC bileşenlerin ortalaması sıfırdır; bunlar DC bileşenin üstüne binerek işareti oluşturur.
  - Frekans sürekli olduğundan toplam, sürekli halde integrale dönüşür.
  - Gerçek işaretler bant sınırlıdır: insan sesi yaklaşık 0-4 kHz, derste verilen kalp işareti örneği yaklaşık 0-360 Hz aralığındadır. Bu yüzden her işaretin bir en yüksek frekansı $F_{max}$ vardır.
  - İşaretin yavaş değişen kısımları düşük frekanslı, hızlı değişen kısımları yüksek frekanslı bileşenlerden gelir.
- Nyquist ölçütü
  - En yüksek frekanslı bileşenin periyodu $T_{max} = 1/F_{max}$'tır (ekrandan, 00:55:00).
  - Bu bileşenden yalnız tepe noktalarında örnek alınırsa $T_{max} = 2T_s$, yani $F_s = 2F_{max}$ olur. Bu en kötü durumdur; daha düşük frekanslı bileşenler bir periyotta daha çok örnekle temsil edilir.
  - Geçiş noktaları da alınırsa $T_{max} = 4T_s$, $F_s = 4F_{max}$ olur; $8F_{max}$, $16F_{max}$ diye artırılabilir.
  - Kural: $F_s \geq 2F_{max}$. Örnekleme frekansı işaretteki en yüksek frekansın en az iki katı olmalıdır. Derste bu sınıra Nyquist frekansı denildi (ekrandan, 01:00:00).
  - Örnek: 0-4 kHz'lik insan sesi için en düşük örnekleme frekansı $2 \times 4 = 8$ kHz'dir. Cep telefonu görüşmelerinde ses 8 kHz ile örneklenir.
- Nicemleme (quantization)
  - Zaman ekseni ayrıklaştırılınca örnekler zaman indisi $n$ ile anılır (ekrandan, 01:15:00). Ama örneklerin genlikleri hâlâ sürekli değerlerdir ve virgülden sonra sonsuz basamak alabilir.
  - Hafıza gözleri 8, 16 ya da 64 bitlik olabilir; ifade edilebilen sayılar sınırlıdır. Bu yüzden genlikler belirli aralıklara (kuanta aralıklarına) atanır.
  - 1 bit ile 2 bölge (örneğin pozitif/negatif), 2 bit ile 4 bölge (00, 01, 10, 11), 3 bit ile 8 bölge ayrılabilir. Bit sayısı arttıkça aralıklar daralır ve birbirine yakın örnekler ayrıştırılabilir.
  - Geri oluştururken her örnek kendi kuanta aralığının ortalama değeriyle temsil edilir; $T_s$ değeri de bilinmelidir.
  - Türkçe karşılıklar: sampling = örnekleme, quantization = nicemleme.
- Elektronik devrelerin yeri
  - ADC'lerden bilgisayarın içindeki lojik elemanlara ve transistörlü yapılara, gömülü sistemlerden mikrodenetleyicinin çevre birimlerine kadar her yerde elektronik devreler kullanılır. Bu derste bu çevre birimlerinin diyot ve transistör gibi temel elemanlarla nasıl tasarlandığı görülecektir.
- Sensörler ve aktüatörler
  - Sensör fiziksel büyüklüğü elektriksel işarete çevirir; aktüatör tersini yapar, elektriksel işareti fiziksel bir etkiye çevirir. Mikrofon sensör, hoparlör aktüatördür.
  - Sensör performansı: çalışma aralığı, çözünürlük, hata, doğruluk (accuracy), netlik (precision), belirsizlik, doğrusallık, hassasiyet.
  - Sensör türleri: rezistif, indüktif, kapasitif, piezoelektrik, fotorezistif (ışıkla değişen), elastik, termal.
  - Rezistif sıcaklık sensöründe direnç sıcaklıkla değişir; $V = IR$ gereği ölçülen gerilim de değişir. Termistörler ve transistör tabanlı yarı iletken sıcaklık sensörleri de vardır.
  - Işık sensörleri (ekrandan, 01:25:00): ışık bağımlı dirençler (LDR) elektrik üretmez, yalnız dirençleri değişir; yavaştır ama insan gözü gibi tepki verir. Fototransistörler fotodiyotlar gibi çalışır ama daha hassastır. Fotoğraf makinesinde her piksel ışık miktarını elektriksel değere çevirir; R, G, B için ayrı parlaklık değerleri kaydedilirse renkli görüntü elde edilir.
  - Kuvvet sensörü olarak gerinim ölçer (strain gauge), yer değiştirme sensörü olarak potansiyometre, endüktif yakınlık sensörleri, anahtarlar, opto-anahtarlar ve enkoderler vardır.
  - Aktüatörler: LED'ler, LCD'ler, solenoidler ve röleler, ölçü aletleri, DC/AC ve adım (step) motorları, hoparlörler ve ultrasonik dönüştürücüler (ekrandan, 01:30:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Sinüs ve kosinüs aynı işarettir
  - Frekansları ve genlikleri aynıdır, yalnız $90^\circ$ ($\pi/2$) faz farkı vardır. Hoca "bu da aklımızda kalsın" diyerek vurguladı.
- $F_s \geq 2F_{max}$ kuralı
  - Örnekleme frekansı en yüksek frekansın en az iki katı olmalıdır. En kötü durum $F_{max}$ bileşeninde oluşur; daha düşük frekanslar bu örneklemeyle zaten daha iyi temsil edilir.
- Örnekleme sıklığının bedeli
  - Daha sık örnekleme daha iyi ses ya da görüntü kalitesi verir, ama dosya boyutu ve hesaplama yükü artar.
- Örnekleme ve nicemleme iki ayrı adımdır
  - Örnekleme zaman eksenini, nicemleme genlik eksenini ayrıklaştırır. Hafızaya yazmak için ikisi de gerekir.
- Merak
  - Prizden alınan işaretin türü, genliği ve frekansı gibi günlük bilgiler bir mühendislik öğrencisinin bilmesi gereken genel kültürdür.

## Kısa Tekrar Notları

- Analog = sürekli, sayısal = ayrık. Geçiş: sensör → örnekleme → nicemleme → hafıza.
- 2B işaretten alınan örnek = piksel.
- $x(t) = A\sin(2\pi f t + \varphi)$: genlik, frekans, faz.
- $T = 1/f$; Hz = saniyedeki çevrim sayısı.
- $360^\circ = 2\pi$; $90^\circ = \pi/2$.
- $f = 0$ → DC; $f > 0$ → AC. Pil DC, priz AC (Türkiye: 220 V, 50 Hz; ABD: 110 V, 60 Hz).
- Fourier: her işaret = DC (ortalama) + AC sinüzoidallerin toplamı (integrali).
- Gerçek işaretler bant sınırlıdır: insan sesi ≈ 0-4 kHz.
- $T_{max} = 1/F_{max}$; tepe noktalarından örnek: $F_s = 2F_{max}$; geçişler dahil: $F_s = 4F_{max}$.
- Kural: $F_s \geq 2F_{max}$; ses için en az 8 kHz.
- $b$ bit → $2^b$ nicemleme düzeyi.
- Sensör: fiziksel → elektriksel; aktüatör: elektriksel → fiziksel.
- Precision (netlik) = ölçümlerin birbirine yakınlığı; accuracy (doğruluk) = gerçek değere yakınlık.

## Detaylı Açıklamalar

- **Neden elektronik devreler?** Yaşadığımız dünya analogdur. Bir sınıfta konuşan hocanın sesi kulağa zamanın her anında sürekli gelir; göz de pikselsiz, sürekli bir görüntü algılar. Bilgisayar ise bu verileri ancak ayrık ve sınırlı sayıda bitle saklayabilir. İki dünya arasındaki köprü sensörler, örnekleyiciler, ADC'ler ve bunların çevresindeki elektronik devrelerdir. Bu ders, bu devrelerin diyot ve transistör gibi temel elemanlarla nasıl kurulduğunu inceler.

- **Örnekleme problemi.** Bir ses işaretinin 0 ile 1 saniye arasında bile sonsuz değeri vardır. Bu yüzden işaretten $T_s$ aralıklarla örnek alınır. Hoca tahtada bir işaret çizip önce sık, sonra seyrek örnekler aldı (ekrandan, 00:25:00). Seyrek örneklemede işaretin hızlı inip çıktığı bölgeler arada kalıp kayboluyordu. Sık örneklemede işaret iyi temsil ediliyor ama hem hafıza hem işlem yükü artıyordu. Dolayısıyla mühendislik sorusu şudur: Bilgi kaybetmeden $T_s$ en fazla ne kadar büyük seçilebilir? Fotoğrafta piksel sıklığının uygulamaya göre seçilmesi de aynı sorudur.

- **Sinüzoidal işaretler.** Fourier analizi sinüzoidallerle çalıştığı için hoca sinüsün parametrelerini ayrıntılı anlattı. Genlik salınımın sınırlarını, frekans bir saniyedeki çevrim sayısını belirler: 5 Hz'lik bir işaret bir saniyede 5 tam çevrim yapar (periyodu 0,2 s), 100 Hz'lik işaret 100 çevrim. Periyodu büyük olan işaretin frekansı küçüktür; frekansı yüksek işaret aynı sürede daha çok titreşir (ekrandan, 00:40:00). Faz ise işaretin sıfırdan başlamak zorunda olmadığını anlatır. Hoca tahtada biri tepe noktasından, biri sıfırdan başlayan iki işaret çizdi; aralarındaki kayma bir periyodun dörtte biri, yani $90^\circ$ ya da $\pi/2$ radyandı. Tepeden başlayan kosinüs, sıfırdan başlayan sinüstü.

- **DC ve AC.** Fourier toplamındaki $f = 0$ bileşeni salınmaz; zamanla sabit bir değerdir. Bir pilin uçlarına voltmetre bağlanınca 1,5 V'luk sabit bir değer görülür (pil zamanla zayıflar ama bu ayrı bir konudur). $f > 0$ olan bileşenler salınır. Prizden gelen şebeke gerilimi AC'dir; adaptörler bunu cihazların kullandığı DC'ye çevirir. Türkiye'de şebeke 220 V ve 50 Hz'dir.

- **Fourier analizi ve bant sınırı.** Fourier (1800'lerin başı) keyfi bir fonksiyonun nasıl ayrıştırılabileceğini sormuş ve cevabı, frekansı 0'dan sonsuza sürekli değişen sinüzoidallerin toplamı olarak vermiştir. Her bileşenin kendi genliği ve fazı vardır; frekans sürekli olduğu için toplam yerine integral kullanılır. DC bileşen işaretin ortalamasıdır, AC bileşenlerin ortalaması sıfırdır. Pratikte frekans sonsuza gitmez: insan ses telleri yaklaşık 0-4 kHz arası (kişiden kişiye 3,5-5 kHz) bileşen üretir; insan sesinde 10 kHz'lik bir bileşen bulunmaz. Bu yüzden her gerçek işaretin bir $F_{max}$'ı vardır.

- **Nyquist ölçütünün çıkarılması.** İşarette en hızlı değişim $F_{max}$ bileşenindedir; örnekleme bu bileşeni yakalayabiliyorsa daha yavaş bileşenleri de yakalar. Hoca $F_{max}$ bileşeninden yalnız tepe noktalarında (bir tepe, bir çukur) örnek aldı: bir periyotta iki örnek, yani $T_{max} = 2T_s$, $F_s = 2F_{max}$ (ekrandan, 00:55:00). Bu örneklerle işaret en azından üçgen biçiminde yeniden çizilebilir. Sıfır geçişleri de alınırsa bir periyotta dört örnek olur: $T_{max} = 4T_s$, $F_s = 4F_{max}$. Sıklık $8F_{max}$, $16F_{max}$ diye artırılabilir; üst sınır yoktur. Alt sınır ise $F_s \geq 2F_{max}$'tır.
  - Ders sonrası not: Hoca bu sınıra "Nyquist frekansı" dedi. Literatürde $2F_{max}$'a büyük olasılıkla "Nyquist hızı" (Nyquist rate), $F_s/2$'ye "Nyquist frekansı" denir. Ayrıca kuram tam yeniden oluşturma için $F_s > 2F_{max}$ (kesin büyük) ister; tam $2F_{max}$'ta örnekler sıfır geçişlerine denk gelirse bileşen kaybolabilir.

- **Uygulamalar.** İnsan sesi için en az 8 kHz örnekleme gerekir; cep telefonu görüşmelerinde ses 8 kHz ile örneklenir. Yüksek örnekleme frekansı ses kalitesini artırır ama dosya boyutunu büyütür.
  - Ders sonrası not: Hoca MP3 dosyalarında "8 kHz, 16 kHz, 128 kHz örnekleme" görüldüğünü söyledi. MP3'te görülen 128 değeri büyük olasılıkla bit hızıdır (128 kbps); yaygın MP3 örnekleme frekansları 44,1 kHz ve 48 kHz civarındadır.

- **Nicemleme.** Örneklenmiş işaret zamanda ayrıktır ama genlikte değildir. İlk örnek 4 olsaydı ikili olarak saklanabilirdi; ama örnek 4,7821357... gibi sonsuz basamaklı bir değer de olabilir (ekrandan, 01:15:00). Hafıza gözlerinin bit sayısı sınırlı olduğu için genlik ekseni aralıklara bölünür ve her örnek düştüğü aralığın koduyla saklanır. Tek bit yalnız işaretin pozitif mi negatif mi olduğunu ayırır. İki bitle dört bölge vardır, ama genlikleri farklı iki örnek aynı bölgeye düşerse ikisi de aynı kodu alır ve fark kaybolur. Bir bit daha eklemek bu iki örneği ayırır. Bu aralıklara kuanta aralıkları denir; adı, kimyadaki elektronların ayrık enerji seviyelerine (kuanta) benzetmeden gelir. Geri oluşturmada her örnek kendi aralığının ortalama değeriyle ve $T_s$ aralıklarla yerleştirilir.

- **Sensörlerde doğruluk ve netlik.** Bir sıvının sıcaklığını tekrar tekrar ölçen bir sensör düşünülsün. Ölçümler birbirine çok yakın ama gerçek değerden uzaksa sensörün netliği (precision) yüksek, doğruluğu (accuracy) düşüktür. Ölçümler gerçek değerin etrafında toplanıyorsa doğruluk yüksektir.

- **Sensör ve aktüatör örnekleri.** Potansiyometrede kolun konumu bir gerilime dönüşür; gerilimden konum bulunur. Endüktif yakınlık sensörleri sanayide araya bir nesne girdiğini algılar. Opto-anahtarda bir ışık kaynağı ve karşısında bir sensör vardır; aradan ışığın geçip geçmemesi elektriksel sinyale dönüşür. Delikli bir tekerlekle birlikte kullanılırsa dönüş hızı bulunabilir; lazerli farelerden önce fareler bu yapıyla çalışırdı. Enkoderler motorlarda, özellikle adım motorlarında konum ölçer. Aktüatör tarafında LED'ler, akıma bağlı olarak yanar ya da farklı parlaklık verir. Hoparlörde sabit mıknatıs ve diyaframa bağlı hareketli bir bobin vardır; giriş sinyali bobinden akım geçirip onu mıknatısa göre hareket ettirir. Yüksek frekanslarda hoparlörün yerini dar frekans aralığında çalışan piezoelektrik aktüatörler alır (ekrandan, 01:30:00). Sensör yapıları ilerideki derslerde görülecek gerilim bölücü devrelerle de kurulabilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
