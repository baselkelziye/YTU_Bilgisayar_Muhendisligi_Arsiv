# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin kapsamı ve Devre Teorisi ile ilişkisi
  - Devre Teorisi daha basit elektriksel devrelere bakar: Kirchhoff akım ve gerilim kanunları, Ohm kanunu, Norton ve Thevenin eşdeğerleri gibi teorik araçlar. Pasif elemanlarla (direnç, bobin, kondansatör) çalışılır.
  - Elektronik Devreler'de devrenin analizine ve devrenin bir amaca yönelik kurgulanmasına bakılır. Bunun için yarı iletken devre elemanlarına (diyot, transistör, MOSFET, op-amp) giriş yapılır.
  - İki ders arasında bağlantı vardır ama Devre Teorisi ön koşul değildir. $V = I \cdot R$ yeniden anlatılmaz, kullanılır.
  - Dersin konu başlıkları (ekrandan, 00:15:00): elektrik devreleri ve bileşenleri (DC devreler, kapasitans, endüktans, AC devreler, frekans karakteristikleri, geçici davranış); elektronik sistemler (sensörler, eyleyiciler, yükseltme, kontrol ve geri besleme, işlemsel yükselteçler); yarı iletken elemanlar ve devreler (yarı iletkenler ve diyotlar, diyot uygulamaları, BJT, FET, güç elektroniği, işlemsel yükselteçler, sayısal sistemler).
- Elektronik sistem nedir?
  - Çevremiz sürekli değişir; bu değişime tepki vermek için değişen bir büyüklüğü algılar (giriş) ve başka bir büyüklüğü değiştiririz (çıkış). Makineler bunu bizim yerimize yapar (ekrandan, 00:35:00).
  - Elektronik sistem üç birimden oluşur: algılama (sense), işleme (process) ve kontrol (control). Çıkış bir şeyi kontrol etmek, ekrana bilgi yazmak ya da bir sinyali tetiklemek olabilir.
  - Dış dünyadaki büyüklükler fizikseldir (sıcaklık, basınç, nem). Bunları elektronik ortama sensörler aktarır.
- Sürekli (analog) ve ayrık (sayısal) büyüklükler
  - Fiziksel büyüklükler elektriksel işaretlerle gösterilir ve sürekli ya da ayrık olabilir. Sürekli işaretlere analog denir (ekrandan, 00:40:00).
  - Hava sıcaklığı hiçbir anda tam "9 derece" değildir; sürekli değişir. Biz değeri yuvarlarız, yani ayrıklaştırırız.
  - Ayrık işaretlere sayısal (dijital) işaret denir. Yalnız iki değer alan sayısal işaretler ikili (binary) işaretlerdir (ekrandan, 00:45:00).
  - Bit sayısı arttıkça çözünürlük artar ve sayısal işaret analog işarete daha çok yaklaşır (3 bit ile 4 bit karşılaştırması).
- Örnek elektronik sistemler
  - Plak çalar: iğne plaktaki girinti ve çıkıntıları izleyerek analog bir dalga biçimi üretir; bu işaret yükselteçle (amplifier) yükseltilip hoparlöre verilir. Giriş sensör verisi, işleme yükseltme, çıkış sestir.
  - CD çalar: yüzeydeki çukurlar "var ya da yok" bilgisi taşır, yani sayısaldır. Okunan sayısal bilgi analoğa çevrilir, yükseltilir ve hoparlöre verilir.
- Sensörler ve eyleyiciler
  - Sensör: dış dünyadan bilgi alıp elektronik ortamda anlamlandırılmasını sağlayan yapı.
  - Eyleyici (aktüatör): elektronik sistemin dış dünyaya tepki üretmesini sağlayan yapı (motor, hoparlör, LED, lamba vb.).
- Bozunum (distortion) ve gürültü (noise)
  - Bütün sistemler elektriksel işareti bir ölçüde bozar. Örnekler: kırpılma (clipping), sıfır geçiş (crossover) bozunumu, harmonik bozunum (ekrandan, 00:50:00).
  - Bozunum sistematiktir ve tekrarlanır; şablonu öğrenilince ön işlem ya da son işlemle giderilebilir.
  - Gürültü tamamen rastgeledir. Analog işaretten gürültüyü ayırmak zordur; ayrık işarette ise seviyeler bilindiği için çok daha kolaydır.
- Sistem tasarımı
  - Tasarım yukarıdan aşağıya (top-down) ilerler: gereksinimlerin belirlenmesi, spesifikasyon, teknoloji (sensör vb.) seçimi, ayrıntılı tasarım (simülasyon, PCB), yapım ve test.
  - Elektronik tasarım araçları: şematik çizim (schematic capture), devre simülasyonu, PCB ya da VLSI yerleşim paketleri. Yaygın simülatörler: PSpice, Multisim; hoca LTspice'ı da ekledi (ekrandan, 00:55:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Elektronik sistemin üç modülü
  - Bir tasarımın elektronik sistem sayılması için algılama, işleme ve çıkış (kontrol) üretme birimlerinin üçünün de bulunması gerekir.
- Neden ayrıklaştırıyoruz?
  - Sürekli işaretleri elektronik sistemde doğrudan işlemek çok zordur. Hocaya göre transistör ve diyotların iletim ve kesim geçişleri sürekli bir dalga biçimiyle beslendiğinde kararsızlaşabilir; ayrık işaret daha kararlı bir cevap verir.
  - Ayrık işaret üzerinde gürültü giderme gibi ön ve son işlemler çok daha kolay uygulanır.
- Bozunum ile gürültü farkı
  - Bozunum bir şablona sahiptir ve düzeltilebilir; gürültü rastgeledir. Bu ayrım işaret işleme derslerinde de temel olacaktır.
- Teknoloji seçimi
  - Her sensörün kendi eşik değeri, ölçüm aralığı ve hassasiyeti vardır. Hassas ölçüm gereken yerde kullanılan sensör, çok farklı referansa sahip başka bir sistemde aynen kullanılamaz.
- Simülasyon
  - Bu derste devre simülasyonu yoğun kullanılacaktır; simülasyon devrenin işleyişini anlamayı büyük ölçüde kolaylaştırır.

## Kısa Tekrar Notları

- Elektronik Devreler = Devre Teorisi'ndeki pasif elemanlara ek olarak yarı iletkenler (diyot, transistör, MOSFET, op-amp).
- Elektronik sistem: algıla, işle, kontrol et.
- Fiziksel büyüklük sürekli; elektronik sistem genelde ayrık değerlerle çalışır.
- Analog = sürekli; dijital = ayrık; binary = yalnız iki değerli dijital işaret.
- $n$ bitle $2^n$ seviye gösterilir: 3 bit 8, 4 bit 16 seviye. Bit arttıkça çözünürlük artar.
- Plak çalar analog, CD çalar sayısal; ikisi de giriş, işleme, çıkış yapısına sahip elektronik sistemlerdir.
- Sensör girişi, eyleyici çıkışı sağlar.
- Bozunum: sistematik, tekrarlanır, düzeltilebilir (clipping, crossover, harmonik). Gürültü: rastgele.
- Tasarım: gereksinim, spesifikasyon, teknoloji seçimi, ayrıntılı tasarım, yapım ve test.
- Simülatörler: PSpice, LTspice, Multisim, Proteus.

## Detaylı Açıklamalar

- **Elektronik sistem kavramı.** İnsan çevresindeki değişimi algılar, bu bilgiyi işler ve bir tepki üretir. Elektronik sistemler de aynı şekilde çalışır: dış dünyadaki ölçülebilir bir büyüklüğü (sıcaklık, basınç, nem) sensörle elektriksel bir değere çevirir, bu değeri işler ve sonuca göre bir çıkış üretir. Çıkış bir motoru döndürmek, ekrana bilgi yazmak ya da başka bir devreyi tetiklemek olabilir. Otomotiv sistemleri ve iletişim sistemleri girişleri ve çıkışları belli olan bu tür sistemlere örnektir.

- **Analogdan sayısala.** Gerçek dünyadaki ölçümler süreklidir: sıcaklık bir an 9,135 iken bir sonraki an biraz farklıdır. Elektronik sistemin bu sürekliliği birebir izlemesi çok zordur. Bu yüzden işaret ayrıklaştırılır: belli aralıklarla değerler yuvarlanarak basamaklı bir işaret elde edilir. Yalnız 0 ve 1 değerlerini alan işaret ikili işarettir. Seviyeler bitlerle kodlanır (3 bitte 000, 001, 010, ...). Bit sayısı arttıkça basamaklar incelir ve sayısal işaret analog işarete daha çok benzer; buna çözünürlüğün artması denir. Bu konu ileride Lojik Devreler ve İşaret İşleme derslerinde ayrıntılı görülür.

- **Plak çalar ve CD çalar.** Plak çalarda iğne, plağın yüzeyindeki girinti ve çıkıntıları izler ve doğrudan sürekli bir dalga biçimi üretir. Bu işaret yükseltilip hoparlöre verilir. İyi bir yükselteç ve gürültü azaltma ile çok kaliteli ses elde edilir. CD'de ise çukurlar yalnız var ya da yok bilgisi taşır; okunan sayısal bilgi önce analoğa çevrilir, sonra yükseltilip hoparlöre verilir.

> Ders sonrası not: Hoca örneğe önce "CD çalar" diyerek başladı, sonra iğneyle okunan analog sistemin plak çalar olduğunu söyleyerek düzeltti. Doğrusu: iğneyle analog okuma plak çalarda yapılır; CD'deki çukurlar büyük olasılıkla lazerle optik olarak okunur.

- **Bozunum ve gürültü.** Saf bir sinüs işareti sistemden geçerken bozulabilir. Tepelerinin bastırılması kırpılmadır (clipping); sıfır geçişlerinde daralma sıfır geçiş (crossover) bozunumudur; dalga biçimine üst harmoniklerin eklenmesi harmonik bozunumdur. Bozunum her periyotta aynı şekilde tekrar ettiği için öğrenilip giderilebilir. Gürültü ise rastgeledir; analog işaretten ayırmak zordur, ayrık işarette ise seviyeler bilindiği için seviye dışı küçük sapmalar kolayca sıfırlanabilir. Bu, ayrıklaştırmanın bir başka gerekçesidir.

- **Sistem tasarımı.** Örnek: alkışla yanıp sönen ışık isteyen bir akıllı ev müşterisi. Önce gereksinimler çıkarılır (hangi LED, hangi alkış sensörü). Sonra ayrıntılar belirlenir: ne kadar güçlü bir alkışta tepki verilecek, yere düşen bir çatal ışığı yakmalı mı? Bu kararlar teknoloji seçimini belirler, çünkü her sensörün eşiği, aralığı ve hassasiyeti farklıdır. Ardından ayrıntılı tasarıma geçilir; simülasyon ve PCB tasarımı burada yer alır. En son ürün yapılır ve test edilir. Elektronik tasarımda en büyük yardımcı simülasyon programlarıdır (PSpice, LTspice, Multisim): devre önce bilgisayar ortamında kurulup denenir, sonra gerçek ortama taşınır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
