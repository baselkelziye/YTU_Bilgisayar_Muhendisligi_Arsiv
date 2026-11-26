# Ders 1 Genişletilmiş Notu: Derse Giriş: Analog ve Sayısal Dünya, Örnekleme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Kapsamı ve Kaynakları
- 2. Dersin Bilgisayar Mühendisliğindeki Yeri
- 3. Analog (Sürekli) Dünya ve Sayısal (Ayrık) Dünya
- 4. Örnekleme ve Sayısallaştırma
- 5. İki ve Daha Çok Boyutlu İşaretler
- 6. Elektronik Devreler Bu Zincirin Neresinde?
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Kapsamı ve Kaynakları

Bu kayıt dönemin ilk dersidir ve büyük kısmı tanışma ile dersin işleyişine ayrılmıştır. Akademik kısım, dersin kapsamı ile analog ve sayısal dünya arasındaki geçişi anlatan kısa bir girişten oluşur. Hoca asıl konulara bir sonraki hafta başlanacağını söyledi.

Dersin temel amacı temel elektronik devre elemanlarını ve yapılarını anlatmaktır: diyotlar, transistörler, FET'ler ve op-amp'lı (işlemsel kuvvetlendiricili) yapılar. Konu sırası şöyle verildi:

- Yarı iletkenler
- Diyotlar
- Transistörler ve transistörlü uygulamalar
- FET'ler (alan etkili transistörler) ve bunlarla ilgili uygulama ve soru çözümleri

> **Ders sonrası not:** Hoca FET'leri "transistörlerin gelişmiş versiyonu" diye tanıttı. FET, BJT'nin geliştirilmiş hali değil, farklı bir çalışma ilkesine (kanalın elektrik alanla kontrolü) dayanan ayrı bir transistör ailesidir.

Ana ders kitabı Robert Boylestad ve Louis Nashelsky'nin *Electronic Devices and Circuit Theory* kitabıdır. Kitabın çok sayıda baskısı vardır, herhangi biri kullanılabilir; Türkçe çevirisi de bulunur <!-- BELİRSİZ: altyazıda çevirinin adı "Elektronik Devreler ve Devre Teorisi" diye geçiyor; tam adı doğrulanamadı -->. Ders slaytları bu kitaptan hazırlandığı için kitabı almak zorunlu değildir.

Temel elektronik çok yaygın anlatılan bir konu olduğu için farklı kitaplardan ve web sitelerinden de yararlanılabilir. Hoca YouTube'da "Electronic Devices and Circuits" araması ile bulunabilecek kursları ve yabancı üniversitelerin ders anlatımlarını alternatif kaynak olarak önerdi.

Devre analizleri için simülasyon programları kullanılacaktır. Hoca Multisim ve Proteus'u örnek verdi; bunların dışında temel elektronik devre analizlerinin yapılabildiği daha basit simülatörler de kullanılabilir.

## 2. Dersin Bilgisayar Mühendisliğindeki Yeri

Hoca bu dersin özellikle gömülü sistemler için önemli bir girdi olduğunu söyledi. Bilgisayarın içindeki yapılar da elektronik devrelerle kurulur: transistörler, tampon (buffer) devreleri, RAM ve ROM yapıları bunlara örnektir <!-- BELİRSİZ: bu kısımda altyazı bozuk (00:14:05); yalnız "Transistörler, Bafurlar, RAM Yapıları, ROM Yapıları" okunabiliyor -->. Ders sonunda temel devreleri kurabilecek, örneğin motorları sürebilecek düzeye gelinmesi hedeflenir.

## 3. Analog (Sürekli) Dünya ve Sayısal (Ayrık) Dünya

Hoca elektronik devrelerin ve sayısal elektronik devrelerin neden önemli olduğunu bir çizimle anlattı (ekrandan, 00:20:00). Tahtanın solunda dış dünyayı temsil eden bir küre, sağında bir bilgisayar vardı. Tahtadaki çizim şu öğelerden oluşuyordu:

| Sol taraf | Ortada | Sağ taraf |
|---|---|---|
| Dünya: "Analog (Continuous)" | Soru işaretli bir ok: arada ne var? | Bilgisayar (Computer): içinde MP (mikroişlemci) ve MC (mikrodenetleyici), yanında hafıza; "Discrete (Ayrık)" |

Çizimin altında yatay ekseni $t$, düşey ekseni $x(t)$ olan sürekli bir işaret ve bu işaretin üzerine çizilmiş dikey örnek çizgileri vardı (ekrandan, 00:20:00).

### 3.1 Dış dünya süreklidir

Çevremizdeki dünyada hemen her işaret ve görüntü süreklidir. Bu yüzden dış dünyaya analog ya da sürekli dünya denir. Hoca bunu iki örnekle açıkladı:

- **Ses:** Sınıfta konuşurken hocanın sesi ve dinleyenin kulağı zamanın her anında tanımlı bir işaretle çalışır. Bir boyutlu bu işaret zamana göre $x(t)$ olarak çizilir ve zamanın her anında tanımlıdır.
- **Görme:** Göz ve beyin dünyayı piksel piksel algılamaz; insan görme sisteminde algılanan görüntü süreklidir. Analog fotoğraf makinesindeki film de sürekli parlaklık değerleri taşır.

### 3.2 Bilgisayar ayrıktır

Bilgisayar (computer), kelime anlamıyla hesap yapabilen herhangi bir şeydir. Cep telefonu, dizüstü bilgisayar ya da akıllı TV gibi, dış dünyadan aldığı veriyi mikroişlemcilerde, mikrodenetleyicilerde ve hafıza birimlerinde işleyen her yapı bu kapsamdadır. Bu yapıların ortak özelliği dış dünya verisini ayrıklaştırarak incelemeleridir.

Ayrık (discrete) tarafta kaynaklar sınırlıdır: işlem gücü sınırlıdır, hafıza sınırlıdır ve her işlemin bir maliyeti vardır. Dış dünya verisi sürekli olduğu için onu olduğu gibi bilgisayara aktarmak mümkün değildir. Aradaki yolda yapılması gereken ilk iş, sürekli veriden örnek almaktır.

## 4. Örnekleme ve Sayısallaştırma

### 4.1 Zamanda örnekleme

Dış dünya verisinden belirli aralıklarla örnek alınmasına örnekleme (sampling) denir. Bilgisayar artık orijinal işaretin kendisiyle değil, onun örnekleriyle çalışır. Tahtada iki örnek arasındaki süre $T_s$ ile gösterildi; alt indis $s$ "sampling" kelimesinden gelir ve $T_s$ örnekleme periyodudur (ekrandan, 00:25:00).

Sürekli işarette 0 ile 1 saniye arasında sonsuz sayıda nokta vardır; örnekler istenildiği kadar sıklaştırılabilir. Ancak bunun bir sınırı olmalıdır, çünkü alınan her örnek sensörden gelip hafızaya kaydedilir ve hafıza sınırlıdır. Ayrıca bu bilgiler hafızada 1010111 gibi ikili (binary) biçimde tutulur.

Örneklemeden sonra işaretin ekseni artık zaman $t$ değil indis $n$'dir. Tahtadaki ikinci grafikte yatay eksen $n$ ve üzerinde $0, 1, 2, 3, \dots$ indisleri, her indiste bir örnek (dikey çizgi ve uçta nokta) çizildi (ekrandan, 00:25:00). Artık sonsuz sayıda noktayla değil, indislenmiş ayrık örneklerle çalışılır.

### 4.2 Genliklerin de sınırlandırılması

Hoca burada önemli bir noktaya dikkat çekti: örnekler zamanda ayrık hale gelse de genlikleri hâlâ sonsuz sayıda değer alabilir. Tahtada düşey eksende 0,5 ve 0,550... gibi değerler yazılıydı (ekrandan, 00:25:00); bir örnek 0,5 iken diğeri 0,555... diye sonsuza kadar giden bir değer olabilir.

Hafızada her örnek için ayrılan gözün belirli bir genişliği vardır: 8 bit, 16 bit, 32 bit, 64 bit ya da 128 bit olabilir. Bu yüzden örneklerin genliklerinin de sınırlandırılması gerekir. Özetle iki ayrı sınırlama vardır:

- Zaman ekseninde: örnek sayısı sınırlıdır.
- Genlik ekseninde: her örneğe ayrılan bit sayısı sınırlıdır.

> **Ek bilgi (derste anlatılmadı):** Genliklerin sınırlı sayıda seviyeye yuvarlanmasına nicemleme (quantization) denir. $b$ bitlik bir göz $2^b$ farklı seviye gösterebilir; örneğin 8 bit ile 256, 16 bit ile 65536 seviye ifade edilir. Hocanın "bir sonraki hafta" anlatacağını söylediği ayrıklaştırma işlemi büyük olasılıkla bu konuyu kapsar.

### 4.3 Sensörden hafızaya zincir

Örneklemeyi yapan yapının başında bir sensör vardır. Sensör, fiziksel büyüklüğü elektriksel işarete dönüştürür; örneğin mikrofon sesi elektriksel bilgiye çevirir. Bu işaret örneklenir, sayısallaştırılır ve en sonunda 1-0-1 biçiminde ikili dizilere dönüşür. Zincir şöyle özetlenebilir:

```text
Fiziksel büyüklük (ör. ses)
  -> Sensör (ör. mikrofon): elektriksel işaret
  -> Örnekleme: T_s aralıklı ayrık örnekler
  -> Sayısallaştırma: sınırlı bit genişliğinde değerler
  -> Binary diziler hafızaya yazılır
  -> Mikroişlemci / mikrodenetleyici ile işleme
```

## 5. İki ve Daha Çok Boyutlu İşaretler

Ses bir boyutlu bir işarettir. İki boyutlu işaretlerde, örneğin görüntüde, zaman değişkeni $t$'nin yerini uzamsal değişkenler alır. Tahtada bir göz, bu gözün baktığı dikdörtgen bir sahne (içinde bir insan figürü), sahnenin üzerinde noktalarla gösterilmiş örnekler ve yanında $x$ ile $y$ eksenleri çizildi; yanına "uzamsal (spatial) değişken" yazıldı (ekrandan, 00:25:00).

Uzama yayılmış sürekli bilgiden de aynı şekilde örnekler alınır. İki boyutta alınan bu örneklere piksel denir; görüntüdeki pikselleşme (pikselizasyon) kavramı buradan gelir. Hoca bunu öğrencilere soru olarak sordu ve cevap piksel olarak verildi (bkz. Örnek Sorular).

Dış dünya verisi bir ya da iki boyutla sınırlı değildir. Veri, sensörün tipine göre daha çok boyutlu olabilir. Hoca MR cihazını örnek verdi: cihaz yatan hastanın vücudundan kesitler alır ve bunları saklar. Bu durumda veri üç boyutlu olur. Sensöre bağlı olarak $N$ boyutlu verilere kadar gidilebilir.

## 6. Elektronik Devreler Bu Zincirin Neresinde?

Ayrık tarafa geçildiğinde, örnekleme ve sensör sisteminin ardından ayrıklaştırma ve ikili hale getirme (binarizasyon) gelir; veri artık hafızaya yazılıp işlenmeye başlar. Hoca ayrıklaştırma işleminin ayrıntısına sonraki derste girileceğini söyledi.

Bu zincirin her halkasında elektronik devreler vardır. Bilgisayarın dışından bilgi alınan her durumda bir elektronik sistem kurulur: sıcaklık verisi, kandaki glikoz miktarı, hava sıcaklığı ya da uydu görüntüleri için sensör sistemleri ve gömülü (embedded) sistemler bunlara örnektir. Bilgisayarın içindeki hafıza sistemleri de transistörlerle, diyotlarla ve elektronik devrelerle kurulur. Bu yapıların tasarımı, mikroişlemci tasarımından FPGA ve GPU'lara kadar ayrı mühendislik dallarıdır.

> **Hocanın vurgusu:** Elektronik devreler dersi, donanım tarafındaki temel işlemleri anlamak için gereken görüşü vermeyi amaçlar; hoca bunun bilgisayar mühendisleri için yararlı bir temel olduğunu vurguladı.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:24:23): İki boyutta (bir görüntüden) alınan örneklere ne ad verilir?

**Cevap:** Piksel. Görüntüdeki pikselleşme kavramı, iki boyutlu uzamsal işaretin $x$ ve $y$ doğrultularında örneklenmesinden gelir.

**Soru 2** (derste sözlü, 00:16:11): İnsan görme sistemi doğayı piksel şeklinde mi algılar?

**Cevap:** Hayır. İnsan görme sisteminde algılanan görüntü süreklidir; analog fotoğraf filmi de sürekli parlaklık değerleri taşır. Piksel kavramı ancak görüntü sayısal tarafa geçerken örneklenince ortaya çıkar.

## Dersin Toparlaması

Bu ilk derste dersin kapsamı (yarı iletkenler, diyotlar, transistörler, FET'ler ve op-amp'lar) ve ana kaynağı (Boylestad ve Nashelsky) tanıtıldı. Ardından elektronik devrelerin bilgisayar mühendisliğindeki yeri, analog dünyadan sayısal dünyaya geçiş üzerinden anlatıldı: dış dünya süreklidir, bilgisayar ise sınırlı kaynaklarla çalışan ayrık bir sistemdir. Aradaki köprü sensör, örnekleme ve sayısallaştırmadır. Örnekleme hem zaman ekseninde (örnek sayısı, $T_s$) hem genlik ekseninde (bit genişliği) sınırlandırma gerektirir. Görüntüde zamanın yerini uzamsal $x$, $y$ değişkenleri alır ve örneklere piksel denir; MR gibi sensörler daha çok boyutlu veri üretir.

Hoca bir sonraki derste örnekleme ve dış dünyadan veri alma konusuna devam ederek asıl derslere başlanacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
