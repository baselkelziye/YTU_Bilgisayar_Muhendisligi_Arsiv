# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin kapsamı ve kaynağı
  - Dersin amacı temel elektronik devre elemanlarını ve yapılarını anlatmaktır: diyotlar, transistörler, FET'ler (alan etkili transistörler) ve op-amp'lı (işlemsel kuvvetlendiricili) devreler.
  - Konu sırası: önce yarı iletkenler, ardından diyotlar, sonra transistörler ve uygulamaları, en son FET'ler ve bunlarla ilgili soru çözümleri.
  - Ana kaynak Robert Boylestad ve Louis Nashelsky'nin *Electronic Devices and Circuit Theory* kitabıdır (kitabın Türkçe çevirisi de vardır <!-- BELİRSİZ: altyazıda Türkçe adı "Elektronik Devreler ve Devre Teorisi" diye geçiyor; çevirinin tam adı doğrulanamadı -->). Kitabın birçok baskısı vardır; ders slaytları bu kitaptan hazırlanır.
  - Temel elektronik birçok kaynakta anlatıldığı için YouTube'daki "Electronic Devices and Circuits" kursları ve yabancı üniversitelerin ders anlatımları da kullanılabilir.
  - Devre analizleri için Multisim ve Proteus gibi simülasyon programları ya da daha basit çevrim içi devre simülatörleri kullanılır.
- Dersin bilgisayar mühendisliğindeki yeri
  - Elektronik devreler, gömülü sistemler için önemli bir temeldir.
  - Bilgisayarın içindeki hafıza (RAM, ROM) ve tampon (buffer) yapıları <!-- BELİRSİZ: bu kısımda altyazı bozuk (00:14:05), yalnız "Transistörler, Bafurlar, RAM Yapıları, ROM Yapıları" okunuyor --> da transistör, diyot gibi elektronik devre elemanlarıyla kurulur. Mikroişlemci tasarımından FPGA ve GPU'lara kadar donanım tasarımı ayrı mühendislik dallarıdır.
  - Ders sonunda temel devreler kurulabilecek, örneğin motorlar sürülebilecek düzeye gelinmesi hedeflenir.
- Analog (sürekli) dünya ve sayısal (ayrık) dünya
  - Dış dünya analogdur, yani süreklidir: ses, görüntü ve insan görme sistemi sürekli verilerle çalışır (ekrandan, 00:20:00).
  - Bir boyutlu işaret $x(t)$ zamanın her anında tanımlıdır. Göz ve beyin görüntüyü piksel piksel algılamaz; analog fotoğraf filmi de sürekli parlaklık değerleri taşır.
  - Bilgisayar (computer), dış dünyadan alınan veriyi ayrıklaştırarak mikroişlemci (MP), mikrodenetleyici (MC) ve hafıza birimlerinde işleyen her yapıdır: cep telefonu, dizüstü bilgisayar, akıllı TV vb. (ekrandan, 00:20:00).
  - Ayrık tarafta kaynaklar sınırlıdır: işlem gücü ve hafıza kısıtlıdır, her işlemin bir maliyeti vardır.
- Örnekleme (sampling) ve sayısallaştırma
  - Sürekli işaretin kendisi değil, belli periyotla alınan örnekleri işlenir. Bu işleme örnekleme (sampling) denir; iki örnek arasındaki süre örnekleme periyodu $T_s$'dir (ekrandan, 00:25:00).
  - Sürekli işarette 0 ile 1 saniye arasında sonsuz sayıda örnek alınabilir; hafıza sınırlı olduğu için örnek sayısı sınırlandırılır.
  - Örneklenen işaretin ekseni artık zaman $t$ değil indis $n$'dir: $n = 0, 1, 2, 3, \dots$ (ekrandan, 00:25:00).
  - Ayrık örneklerin genlikleri hâlâ sonsuz sayıda değer alabilir (0,5; 0,55; 0,555 ...). Her örnek için ayrılan hafıza gözünün genişliği (8, 16, 32, 64, 128 bit) sınırlı olduğundan genliklerin de sınırlandırılması gerekir.
  - Zincir: sensör (ör. sesi elektriksel işarete çeviren mikrofon) → örnekleme → sayısallaştırma → ikili (binary) diziler (1010111 gibi) → hafıza → işleme.
- İki ve daha çok boyutlu işaretler
  - Görüntü iki boyutlu bir işarettir. Zaman değişkeni $t$'nin yerini uzamsal (spatial) değişkenler $x$ ve $y$ alır (ekrandan, 00:25:00).
  - Uzama yayılmış sürekli bilgiden yine örnekler alınır; iki boyutta alınan örneklere piksel denir.
  - Veri sensörün tipine göre daha çok boyutlu olabilir: MR cihazı vücudun kesitlerini alarak üç boyutlu veri üretir; sensöre göre $N$ boyutlu veriye kadar gidilebilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Elektronik sistemler dış dünyadan bilgi almanın aracıdır
  - Sıcaklık, kandaki glikoz miktarı, hava sıcaklığı ya da uydu görüntüsü gibi bilgisayar dışındaki her veri için bir elektronik sistem (sensör sistemi, gömülü sistem) kurulur.
  - Hoca, donanım tarafındaki temel işlemleri anlamak için bu dersin bilgisayar mühendisleri açısından yararlı olduğunu vurguladı.
- Sınırlı kaynak, sınırlı örnek
  - Sürekli dünyadan ayrık dünyaya geçişte hem örnek sayısının (zaman ekseninde) hem de genlik değerlerinin (bit genişliğinde) sınırlandırılması gerekir; bunun nedeni hafızanın ve işlem gücünün sınırlı olmasıdır.

## Kısa Tekrar Notları

- Ders kapsamı: yarı iletkenler, diyotlar, transistörler, FET'ler, op-amp'lar.
- Ana kaynak: Boylestad ve Nashelsky, *Electronic Devices and Circuit Theory*.
- Dış dünya analog (sürekli), bilgisayar dijital (ayrık).
- Örnekleme: $T_s$ periyoduyla örnek alma; eksen $t$'den indis $n$'ye geçer.
- Genlikler de sınırlanmalıdır: her örnek sınırlı bit genişliğinde saklanır.
- Zincir: sensör → örnekleme → sayısallaştırma → binary → hafıza → işleme.
- Görüntüde $t$ yerine uzamsal değişkenler $x$, $y$ gelir; iki boyutlu örneklere piksel denir.
- MR gibi sensörler üç ve daha çok boyutlu veri üretir.

## Detaylı Açıklamalar

- Bu ilk derste asıl konulara girilmeden önce elektronik devrelerin neden gerekli olduğu anlatıldı. Hoca tahtanın bir yanına dış dünyayı, diğer yanına bilgisayarı (içinde mikroişlemci ve mikrodenetleyici, yanında hafıza) çizdi ve aradaki yolun ne olduğunu sordu (ekrandan, 00:20:00). Dış dünyadaki işaretler süreklidir; örneğin konuşurken ses zamanın her anında tanımlıdır ve $x(t)$ ile gösterilir. Bilgisayar ise sınırlı kaynaklarla çalışır, bu yüzden sürekli işareti olduğu gibi saklayamaz.
- Bu geçişin ilk adımı örneklemedir. Sürekli işaretten $T_s$ aralıklarla örnekler alınır (ekrandan, 00:25:00). Alınan örnekler artık zamanla değil indisle anılır: sıfırıncı, birinci, ikinci örnek gibi. Ancak her örneğin genliği yine sürekli bir değerdir (0,5 ile 0,555... arasındaki her değer olabilir). Hafızadaki her göz belli bir bit genişliğine sahip olduğundan genlikler de sınırlandırılır ve örnekler sonunda ikili diziler olarak hafızaya yazılır.
- Örneklemeyi yapan yapı bir sensörle başlar: mikrofon sesi elektriksel işarete çevirir, bu işaret örneklenir, sayısallaştırılır ve binary dizilere dönüşür. Aynı fikir görüntüye de uygulanır: zaman yerine uzamsal $x$ ve $y$ değişkenleri gelir, uzaya yayılmış sürekli bilgiden alınan örneklere piksel denir. MR cihazının kesit görüntüleri gibi örneklerde veri üç ya da daha çok boyutlu olabilir.
- Bu zincirin her halkası (sensör sistemleri, gömülü sistemler, hatta bilgisayarın içindeki hafıza devreleri) diyot ve transistör gibi elektronik elemanlarla kurulur. Ders, bu elemanların temel çalışma mantığını vermeyi amaçlar.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
