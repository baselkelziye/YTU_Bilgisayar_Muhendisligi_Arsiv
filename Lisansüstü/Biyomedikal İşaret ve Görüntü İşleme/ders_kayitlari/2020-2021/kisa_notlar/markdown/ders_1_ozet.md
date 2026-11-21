# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin kapsamı ve yaklaşımı
  - Ders disiplinlerarasıdır: sinyal işleme, görüntü işleme, makine öğrenmesi ve örüntü tanıma yöntemleri biyomedikal veriler üzerinde birlikte kullanılır.
  - Dönemin ilk yarısında üç temel alan hızlandırılmış biçimde ele alınır: sayısal işaret işleme (DSP, yaklaşık 4-5 hafta), görüntü işleme (1-2 hafta, slaytlar üzerinden temel fonksiyonlar) ve makine öğrenmesi (yaklaşık 1 hafta; temel kavramlar, öznitelik çıkarımı, standart yöntemler ve derin öğrenmeye geçiş).
  - DSP kısmında özellikle ayrık işaretler üzerinde konvolüsyon ve frekans domeni analizi netleştirilecektir.
  - Dönemin ikinci yarısı biyomedikal veri kümeleri (histopatoloji, MR, göz verileri, Kaggle gibi yarışma siteleri) üzerinde, bilimsel bir yayına dönüştürülebilecek bir projeye ayrılır.
  - Uygulama ortamı MATLAB ya da Python'dur (Google Colab gibi bulut ortamları önerilir).
- Araştırma yöntemi
  - Önce güncel bir yayında önerilen ve kodu paylaşılan yöntem anlaşılır ve kendi veri kümesine uygulanır, sonra bu yöntemin üzerine yenilik önerilir.
  - Yeni bir öznitelik çıkarım yöntemi önerilse bile başarısını göstermek için bir sınıflandırma deneyi gerekir; bu yüzden çalışma ister istemez makine öğrenmesine kayar.
- Biyomedikal mühendisliği ve alt alanları (slayttan)
  - Biyoenstrümantasyon, biyomalzemeler (örneğin dize konan uzun ömürlü titanyum eklemler), biyomekanik, biyoişaretler, biyogörüntüler, biyosistemler, biyotransport, hücre mühendisliği, klinik mühendisliği, doku mühendisliği, rehabilitasyon mühendisliği, biyoistatistik, tıbbi bilişim.
  - Bilgisayar mühendisliği açısından odak: elde edilmiş verinin analizi ve anlamlandırılması, hekimlere yardımcı karar destek sistemleri kurulması.
- Genel enstrümantasyon sistemi (ekrandan, 00:45:00)
  - Ölçülen fiziksel büyüklük (measurand) insan vücudundan alınır.
  - Sensör: birincil algılama elemanı (primary sensing element) ve değişken dönüştürme elemanı (variable conversion element); bu ikisi birlikte dönüştürücüdür (transducer).
  - Ardından işaret işleme, çıktı gösterimi (output display), veri depolama, veri iletimi gelir. Kalibrasyon işareti, kontrol ve geri besleme, güç kaynağı ve dışarıdan uygulanan enerji (radyasyon, elektrik akımı) kesikli çizgiyle gösterilen, bazı uygulamalarda isteğe bağlı bileşenlerdir.
  - Slayttaki tanım: sensör, ölçülen büyüklükten gelen enerji ya da bilgiyi başka bir biçime (genellikle elektriksel) dönüştürür; bu işaret işlenir ve insanın algılayabileceği biçimde gösterilir.
- Kaydedilmiş veriden sonuca giden akış
  - Ön işleme, modelleme, son işleme ve amaca göre sınıflandırma ya da bölütleme.
  - Çalışılabilecek konular: gürültü giderimi ile daha iyi sınıflandırma, MR gibi büyük verilerin sıkıştırılması, histopatoloji verilerinde yeni öznitelik çıkarım yöntemleri.
- Sensörlerle ölçülen biyomedikal büyüklükler
  - Kan akışı, kan basıncı, kalp debisi (cardiac output), vücut ve deri sıcaklığı.
  - Elektriksel işaretler: EEG (elektroensefalografi, beyin işaretleri), EMG (elektromiyografi, kas hareketlerinin elektriksel seviyesi), EKG (elektrokardiyografi, kalp), ERG (elektroretinografi, göz).
  - Kimyasal büyüklükler: pH, karbondioksit ve oksijen seviyesi (parmağa takılan sensörler, kan testleri).
  - Amaç, normal ve hastalıklı bireyler arasındaki farkı ortaya koyan belirteçleri çıkarmaktır.
- EKG işareti (ekrandan, 00:50:00)
  - Dalga biçiminde P tepesi, QRS kompleksi, S-T segmenti ve T tepesi; P-Q aralığı ve Q-T aralığı işaretlenmiştir.
  - Eksenler: genlik milivolt (yaklaşık -0,5 ile 1,0 mV arası), zaman saniye (0-0,8 s). R tepesi yaklaşık 1,0 mV'tur.
  - Kulakçık (atrial) kasılması P dalgası bölgesinde, karıncık (ventricular) kasılması QRS'ten T dalgasına kadar olan bölgede gösterilmiştir.
  - Ham EKG işaretinde gürültü ana işaretin üzerine biner; işaretin karakteristiğine göre filtreleme ile temiz işaret elde edilir, sonra işaret segmentlere bölünüp sağlıklı kalp verisiyle karşılaştırılır.
- İşaret işlemenin uygulama alanları (slayttan)
  - Haberleşme, işaret güvenliği, çoğullama, veri sıkıştırma, gürültü giderimi, konuşmacı tanıma, ses işleme, işaret zenginleştirme, eşitleme (equalization), görüntü işleme, bilgi gömme ve geri elde etme, veri analizi ve öznitelik çıkarımı, frekans ve spektral analiz.
- Zaman domeni ve frekans domeni
  - Zaman domeninde bağımsız değişken $t$'dir; değerler her anda ölçülen genliklerdir.
  - Frekans domeninde değişken frekanstır; işaretin içerdiği frekanslardaki anomaliler aranabilir.
- Bir, iki ve üç boyutlu işaretler (ekrandan, 01:00:00)
  - 1B işaret tek bir değişkene (örneğin zamana) göre ölçülür: $x(t)$.
  - 2B işaret uzamsal (spatial) değişkenlere $x$ ve $y$'ye bağlıdır; piksel kavramı olmayan kimyasal film fotoğrafı sürekli 2B işarete örnektir.
  - 3B işaret: yatan bir hastadan art arda alınan kesit görüntüleri üst üste konunca en, boy ve yükseklikli veri elde edilir.
  - Kavramlar önce 1B işaretlerle anlatılır, diğer boyutlara genelleştirilir.
- Sürekli işaretten ayrık işarete: örnekleme (ekrandan, 01:05:00 ve 01:10:00)
  - İşlemeyi yapan "bilgisayar" yalnız masaüstü değil; mikrodenetleyicili ya da mikroişlemcili herhangi bir sistemdir.
  - Sürekli işaret, en küçük aralıkta bile (örneğin 3. ve 4. saniye arası) sonsuz sayıda değer içerir; bu yüzden doğrudan belleğe konamaz. İlk adım örneklemedir.
  - $x(t)$ sürekli (analog) işaret, $x[n]$ ayrık işarettir: parantez köşeli paranteze, sürekli zaman değişkeni $t$ örnek indisi $n$'ye dönüşür.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sürekli işaret sonsuz bilgi içerir
  - 3. ve 4. saniye arasındaki kısa bir aralıkta bile alınabilecek farklı genlik değerlerinin sınırı yoktur; bu nedenle bilgisayara geçişte örnekleme zorunludur.
- Örnekleme sıklığının ödünleşimi
  - Sık örnekleme en küçük değişimi bile yakalar, ama hesaplama ve depolama maliyetini artırır.
  - Seyrek örnekleme daha az bellek kaplar, ama aradaki değişimler kaçırılır ve işaretin doğruluğu düşer.
- Disiplinlerarası bakış
  - İşaret işleme, görüntü işleme ve makine öğrenmesini birlikte kullanıp bir biyomedikal veri kümesi üzerinde bilimsel bir çalışma ortaya koymak dersin asıl amacıdır.
- DSP'de matematikten çok kavram
  - Konvolüsyon ve frekans analizi gibi konularda formüller olsa da hoca kavramların özünü ve anlamını öne çıkaracağını söyledi.

## Kısa Tekrar Notları

- Biyomedikal işaret işleme: sensörle alınan dış dünya (insan vücudu) verisini bilgisayar ortamında analiz edip anlamlandırmak.
- Sensör = birincil algılama elemanı + değişken dönüştürme elemanı (transducer).
- Akış: veri → ön işleme → modelleme → son işleme → sınıflandırma / bölütleme.
- EEG beyin, EMG kas, EKG kalp, ERG göz ile ilgili elektriksel işaretlerdir.
- EKG dalgası: P, QRS, S-T segmenti, T; P-Q ve Q-T aralıkları.
- Atrium = kulakçık, ventrikül = karıncık.
- 1B: $x(t)$; 2B: uzamsal $(x, y)$; 3B: kesitlerden oluşan hacim.
- Sürekli işaret → örnekleme → ayrık işaret: $x(t) \rightarrow x[n]$.
- Sık örnekleme: doğru ama maliyetli. Seyrek örnekleme: ucuz ama bilgi kaybı.

## Detaylı Açıklamalar

- Dersin temel fikri, sürekli (analog) dış dünya verisini sensörlerle alıp bilgisayar ortamında işlemektir. Aynı yöntemler insan vücudu yerine yeryüzüne uygulandığında uzaktan algılama ve jeofizik uygulamaları ortaya çıkar. Biyomedikal mühendisliği robotik ve biyomalzeme gibi pek çok alt alan içerir; bilgisayar mühendisliğinin katkısı, elde edilmiş veriyi işaret işleme, görüntü işleme ve makine öğrenmesiyle anlamlandırmak ve hekimlere yardımcı karar destek sistemleri kurmaktır.
- Genel enstrümantasyon sistemi şemasında (ekrandan, 00:45:00) ölçülen büyüklük insan vücudundan sensöre girer. Sensör iki parçalıdır: birincil algılama elemanı fiziksel etkiyi algılar, değişken dönüştürme elemanı onu genellikle elektriksel bir işarete çevirir; ikisi birlikte dönüştürücüyü (transducer) oluşturur. İşaret daha sonra işlenir, gösterilir, depolanır ya da iletilir. Hoca derste özellikle ölçülen büyüklüğü, dönüştürücüyü ve veri depolamayı işaretledi; bu derste veriler çoğunlukla zaten kaydedilmiş hâlde gelir ve çalışma depolanmış verinin işlenmesiyle başlar.
- EKG örneğinde (ekrandan, 00:50:00) kalbin kan pompalaması sırasında vücut yüzeyinde oluşan elektriksel değişimler, yüzeye yapıştırılan elektrotlarla ölçülür. Dalga P tepesiyle başlar, QRS kompleksiyle devam eder, S-T segmentinden sonra T tepesiyle biter. Slayttaki renk anahtarına göre P dalgası bölgesi kulakçık kasılmasına, QRS'ten T'ye kadarki bölge karıncık kasılmasına karşılık gelir. Hoca bir EKG giriş işaretinin milivolt seviyesinde olduğunu ve bir DC ofset geriliminin bulunduğunu söyledi. <!-- BELİRSİZ: Hocanın okuduğu "giriş işareti 5 milivolt" değeri ve DC ofset değeri ekranda görülen karelerde yok; değer doğrulanamadı. -->
- Ham EKG kaydında, elektronik ortamdan ya da elektrotun deriyle temasından kaynaklanan gürültü ana işaretin üzerine biner. İşaretin karakteristiğine göre filtre tasarlanarak temiz işaret elde edilir. Sonraki adımda işaret segmentlere ayrılır, sağlıklı kalp verisiyle karşılaştırılır ve hastalık belirtisinin nerede ve ne sıklıkta görüldüğü analiz edilir.
- Boyut kavramı: 1B işaret tek bir değişkene göre değişir (zamana göre vücut sıcaklığı, EKG). 2B işaret uzamsal iki değişkene bağlıdır; dijital kameralardaki piksel kavramı olmayan eski film fotoğrafları sürekli 2B işarete örnektir. 3B işaret, yatan bir hastadan alınan kesit görüntülerinin üst üste konmasıyla oluşan hacimsel veridir (ekrandan, 01:00:00).
- Örnekleme (ekrandan, 01:05:00 ve 01:10:00): Tahtada çizilen sürekli $x(t)$ işaretinin 3. ve 4. saniyeleri arasındaki parça bilgisayarın belleğine (RAM) konmak istenir. Bu aralıkta alınabilecek farklı genlik değerlerinin sınırı yoktur, çünkü sürekli işaret her anda tanımlıdır. Bu yüzden belirli aralıklarla örnek alınır. Hoca tahtada aynı aralığı bir bölümde sık, bir bölümde seyrek örnekledi: sık örneklenen kısımda işaretin dalgalanmaları yakalanırken seyrek kısımda aradaki değişimler kaçmaktadır. Örneklenen işaret artık $x[n]$ ile gösterilir; $n = 1, 2, 3, \dots$ birinci, ikinci, üçüncü örneğin indisidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
