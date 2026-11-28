# Ders 3 Genişletilmiş Notu: Veri Bağı Protokolleri, HDLC ve Yerel Alan Ağlarına Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Planı
- 2. Veri Bağı Protokolünün Görevleri
- 3. Eşzamansız ve Eşzamanlı Protokoller
- 4. Byte Yönelimli Protokoller
- 5. Veri Şeffaflığı ve Byte Doldurma
- 6. Blok Yapısı, Çok Çerçeveli İletim ve Kontrol Çerçeveleri
- 7. BSC
- 8. Bit Yönelimli Protokollere Geçiş
- 9. HDLC
- 10. LAP Ailesi ve SDLC
- 11. Yerel Alan Ağlarına Giriş
- 12. IEEE 802 Referans Modeli
- Örnek Sorular

## 1. Dersin Planı

Dersin konusu veri bağı protokolleriydi (Data Link Protocols). Slayttaki içerik listesi şöyleydi (ekrandan, 00:25:00):

- Veri Bağı Protokolleri (Data Link Protocols)
  - Eş-zamanlı / Eş-zamansız
  - Bit yönelimli / Byte yönelimli
  - HDLC
  - SDLC
- Yerel Alan Ağları (LAN – Local Area Networks)

Hoca, protokollerin özelliklerine göre sınıflandırılacağını, önce eşzamanlı ve eşzamansız ayrımına, sonra byte ve bit yönelimli ayrımına bakılacağını söyledi. HDLC, ISO tarafından standartlaştırılmış ve zamanında çok kullanılmış bir protokoldür. Bugün doğrudan HDLC adıyla karşımıza çıkmasa da onun farklı biçimleri hayatımızdadır. Hoca, HDLC'deki mantığın bir kısmının bugün Wi-Fi'de de kullanıldığını belirtti. Bu yüzden HDLC'nin çalışma mantığı ayrıntılı incelendi, ardından yerel alan ağlarına ve 802 projesine geçildi.

<!-- BELİRSİZ: Hoca HDLC'nin IBM tarafından kullanılan bir versiyonundan söz etti (00:26:06), altyazı bozuk; büyük olasılıkla SDLC kastedildi. -->

Hoca o sabah sunum dosyasındaki slaytların yaklaşık yarısının kaybolduğunu, bu yüzden bazı yerleri sözlü anlatacağını söyledi. HDLC'nin çerçeve ayrıntıları ve sonrası bu nedenle slaytsız anlatıldı.

## 2. Veri Bağı Protokolünün Görevleri

Veri bağı kontrolünü (Data Link Control) yapacak yapının, şimdiye kadar konuşulan konular içinde şunları yapması gerekir:

- Akış kontrolü (flow control)
- Hata kontrolü (error control)
- İletişim kuralları

Bir iletişim hattı üzerinden bilgi gönderirken bilgiye çeşitli kontrol bilgileri de eklenir. Hoca bunu seri haberleşmeden hatırlattı: orada başlangıç (start) ve bitiş (stop) bitleri vardı. Üst seviyede de benzer kontroller gerekir: akışı durdurma, çerçevenin boyutunu ya da başka özelliklerini belirtme, adres bilgisi, checksum gibi alanlar.

Burada bir sorun vardır. Byte üzerinden konuşulursa bu alanların her biri 0-255 arasında herhangi bir değeri alabilir. Aktarılan veri de, özellikle ikili (binary) veriyse, bütün kombinasyonları içerebilir. Dolayısıyla kontrol bilgisi ile verinin bir şekilde birbirinden ayrılması gerekir. Bunun için bit yönelimli mi, byte yönelimli mi bir yöntem izleneceği dersin ana sorusudur.

Hata kontrolünde iki yaklaşım konuşulmuştu: hata sezme (error detection) ve hata düzeltme (error correction). İkisinde de bilginin içine ek alanlar yerleştirilir. Hata sezmede hata bulunursa bilgi yeniden gönderilir. Bunu bildirmek için farklı çerçevelere ihtiyaç vardır:

- Veri gönderilen bir çerçeve yapısı,
- Kontrol bilgisinin gönderildiği bir çerçeve yapısı,
- Bu ikisinin bir arada bulunduğu yapılar.

Üçüncüsüne örnek, akış kontrolünden hatırlanan piggyback yöntemidir: karşı tarafa gönderilecek bir veri varsa alındı (ACK) bilgisi o verinin arkasına eklenir.

## 3. Eşzamansız ve Eşzamanlı Protokoller

### 3.1 İki seviyede eşzamanlılık

Eşzamanlılık hem fiziksel hem mantıksal seviyede sağlanabilir. Fiziksel katmanda en temiz yol ortak bir saat işareti (clock) kullanmaktır. Mantıksal seviyede ise öncül (preamble), ardıl (postamble) ya da başlangıç ve bitiş bitleri kullanılır.

### 3.2 Eşzamansız protokoller

Slayttaki metin (ekrandan, 00:30:00):

- Veri bağı katmanında kullanılan eşzamansız protokoller, modem ile yapılan bağlantılarda kullanılmaktadır.
- Eşzamansız protokolde alıcı ve gönderici arasındaki mantıksal eşzamanlamayı sağlamak üzere verinin başladığını gösteren başlangıç biti ve bittiğini gösteren bitiş biti kullanılmaktadır.
- Eşzamansız protokoller veriyi iletmek için kullandığı ek bilgiler ve doğası gereği daha yavaş çalışmakta ve bu nedenle tercih edilmemektedir.
  - En bilinen örnekleri X-Modem, Y-Modem, Z-Modem ve Kermit'tir.

Hoca bu protokollerin bugün de belli açılardan kullanıldığını anlattı: mikrodenetleyici programlarken, özellikle ARM tabanlı işlemcilere ROM yüklerken bu ya da benzeri bir protokol üzerinden veri aktarılır. Gönderilenin alıcı tarafından anlaşılması için araya ek bilgi konması gerektiğinden bu yapılar biraz daha yavaştır ve ek yük taşır.

### 3.3 Eşzamanlı protokoller

Slayttaki metin (ekrandan, 00:35:00):

- Eşzamanlı protokollerde 2 türlü eşzamanlılıktan söz edilebilir.
  - **Fiziksel seviyede eşzamanlılık:** Gönderici ve alıcı arasında eşzamanlılığı sağlamak üzere kullanılan ortak saat işareti ile sağlanır.
  - **Veri bağı katmanında (mantıksal seviyede) eşzamanlılık:** İki uç arasında aktarılan verinin algılanabilmesi için FLAG'ler yardımıyla sağlanan eşzamanlılık.
- Protokol, yollanan veriyi, kullanılan kodlama sistemine (ASCII veya EBCDIC) göre kodlanmış, birbirini takip eden byte dizisi olarak algılamaktadır.
  - byte (karakter) yönelimli ve bit yönelimli olarak iki farklı tipte incelenebilir.

Mantıksal eşzamanlılık için başa bir eşzamanlama öncülü (preamble), sona bir eşzamanlama ardılı (postamble) konur. Başa ve sona eklenen bu bilgiye genel bir ad olarak flag denir. Byte yönelimli protokollerde baştaki karakter eşzamanlama sağladığı için SYN (synchronous idle), sondaki EOT (End of Transmission, metin sonu) diye anılır. HDLC'de ise doğrudan flag adı kullanılır. Hoca, her protokolde farklı ad görülebileceğini, ama genel yapının flag olduğunu vurguladı.

Hoca eşzamanlı protokoldeki bakışı C programlamadaki dosya kavramına benzetti: dosya bir byte akışıdır (byte stream), açıldığında byte byte okunabilen sürekli bir yapıdır. Eşzamanlı protokol de bilgiye bir byte dizisi olarak bakar. Byte'ın nasıl kodlandığı (UTF-8, ASCII vb.) değişebilir. Önemli olan bilginin bir dizi olduğunu unutmamaktır. Çerçeveleme (framing) yapabilmek için bu dizi üzerinde kodlama tekniğine bağlı müdahaleler yapılır.

## 4. Byte Yönelimli Protokoller

### 4.1 Karakter dizisi olarak çerçeve

Slayttaki metin (ekrandan, 00:40:00):

- Aktarılacak veri çerçevesi her biri bir byte ile ifade edilen karakterlerden oluşmuş bir dizi olarak değerlendirilir.
  - Eşzamanlılığı sağlamak üzere kullanılacak olan kontrol karakterleri de kullanılan kodlama tekniğine bağlı olarak aynı karakter kümesinin elemanlarıdır.
  - Genel olarak byte yönelimli protokollerde kullanılan kontrol karakterleri veri ifade etmek için kullanılan harf, sayı ve noktalama işaretleri dışında kalan kodlar içinden seçilmektedir.
- İki uç arasında iletilen veri her zaman metin olmak zorunda değildir.
  - Örneğin bir resim verisi yollanırken veri içinde bu özel kontrol karakterlerinin de bulunması doğaldır.
  - Bu durum byte yönelimli protokoller için veri şeffaflığını (data transparency) tehdit eden bir durumdur ve düzeltilmesi için bir takım yöntemler geliştirilmiştir.

Her kodlama tekniğinde her karakterin sayısal bir değeri vardır. Hoca ASCII'den örnek verdi: 65 değeri `A` harfine karşılık gelir. Aynı sayı EBCDIC'te çok farklı bir karaktere denk düşebilir. Bu yüzden protokolün kullanacağı kontrol karakterleri sayısal değerleriyle değil, sembollerle ifade edilir.

> **Ders sonrası not:** Hoca ASCII'de 64'ün bir işarete karşılık geldiğini söyledi, altyazıda işaretin adı bozuk. ASCII'de 64 `@` karakteridir, 65 `A` harfidir.

### 4.2 Kontrol karakterleri

Kontrol karakterlerinin listesi kaybolan slaytlardan biriydi, hoca bunları sözlü anlattı:

- **SYN (Synchronous Idle):** Kanalın aktif hâle geldiğini, verinin geleceğini bildirir.
- **PAD:** Farklı çerçeve boyutları tanımlandığında, çerçevenin en küçük boyutunu dolduracak kadar bilgi yoksa boşluklar PAD karakteriyle doldurulur.
- **DLE (Data Link Escape):** Bir karakterin verinin parçası olduğunu belirtmek için kullanılır (Bölüm 5).
- **ENQ (Enquiry):** Bir istekte bulunulacağı zaman kullanılır.
- **SOH (Start of Header):** Başlık alanının başladığını gösterir. Noktadan noktaya bağlantıda adres gerekmeyebilir, ama bus yapısında gönderen ve alıcı adresi gibi bilgiler gerekir. Bunlar çerçevenin başlık kısmında taşınır.
- **STX (Start of Text):** Başlığın bittiğini, verinin başladığını gösterir.
- **ETX (End of Text):** Veri alanının bittiğini gösterir.
- **ETB (End of Transmission Block):** Bir iletim bloğunun bittiğini gösterir (Bölüm 6).
- **EOT (End of Transmission):** İletimin bittiğini gösterir.
- **ACK:** Alındı bilgisi için kontrol karakterleri.
- Bunların dışında NUL, ters kesme (reverse interrupt), geçici metin gecikmesi gibi karakterler ve protokole özgü başka kontrol karakterleri görülebilir.

<!-- BELİRSİZ: Hoca bu listede bir "BCC alanı"ndan da söz etti; BCC bir kontrol karakteri değil, çerçevenin sonundaki hata sezme alanıdır. Altyazıdaki "Temporary Text Play" büyük olasılıkla TTD (Temporary Text Delay). -->

### 4.3 Temel çerçeve yapısı

Byte yönelimli protokollerde iki tip çerçeveden söz edilir: kontrol çerçevesi ve veri çerçevesi. Hoca, kontrol bilgisinin yalnız kontrol çerçevesinde olduğunu düşünmemek gerektiğini vurguladı. Kontrol çerçevesi bağlantının kurulması, akış kontrolü (stop-and-wait, Go-Back-N, Selective Repeat, kayan pencere) ve hata kontrolü için gerekir. Veri çerçevesinde de SOH, STX, ETX gibi kontrol karakterleri ve başlıktaki alanları belirten kontrol karakterleri bulunur.

Slayttaki yapı ve metin (ekrandan, 00:45:00):

| SYN | SYN | STX | Veri | ETX | BCC |
|-----|-----|-----|------|-----|-----|

- Her çerçeve iki adet SYN karakteri ile başlatılır.
  - alıcıya yeni bir çerçevenin gelmekte olduğunu belirtmek
  - alıcıyla eşzamanlama sağlamak
- STX karakteri alıcıya kontrol bilgisinin bittiğini ve bunun devamında aktarılan verinin olduğunu bildirir.
- Aktarılacak bilginin büyüklüğü hakkında bir bilgi aktarılmadığı için verinin nerede bittiği ETX karakteri ile belirlenmektedir.
- Çerçeve üzerinde hata kontrolünü sağlamak üzere en sona BCC eklenerek çerçeve sonlanmaktadır.

Bu şekilde başlık (header) görünmüyor. Hoca bunun doğrudan kullanılan bir yapı değil, fikir vermek için gösterilen bir çerçeve olduğunu söyledi. Başlığın hiç olmaması en fazla, verinin tek yönde gittiği ve hiçbir şeyin geri gelmediği simpleks bir haberleşmede düşünülebilir.

BCC (Block Check Character) sabit bir kod değildir. Daha önce konuşulan LRC ya da CRC gibi bir yöntem çalıştırılır ve elde edilen sonuç konur. Bu sonuç her zaman en sona yerleştirilir.

Adresleme veri bağı katmanının işlerinden biridir, bu yüzden adres bilgisi başlıkta olur. Çerçevelere bir de sıra numarası (sequence number) verilmesi gerekir. Bu bilgiler de başlık alanında taşınır.

## 5. Veri Şeffaflığı ve Byte Doldurma

### 5.1 Sorun

Bu protokoller ilk tasarlandığında daha çok metin göndermek için kullanılıyordu. Harf, sayı ve noktalama işaretleri dışındaki kodlardan biri SYN, biri SOH, biri STX, biri ETX için seçildi. Sıradan bir metin aktarılırken sorun yoktur. Ama ses, görüntü ya da çalıştırılabilir dosya gibi ikili bir veri gönderilince bu kontrol karakterleri verinin içinde geçebilir. Örneğin ETX için seçilen değer çerçevenin ortasında geçerse alıcı veri çerçevesinin erken bittiğine karar verir.

### 5.2 DLE ile çözüm

Bunu önlemek için DLE (Data Link Escape) karakterinin kullanılmasına karar verildi. SOH'tan, STX'ten ve ETX'ten önce DLE konur. Böylece `DLE STX` ile `DLE ETX` arasında geçen bir şey kontrol karakteri olarak algılanmaz.

Bu kez de DLE'nin kendisinin verinin içinde geçmesi sorunu vardır. Çözüm şudur: veri içinde DLE geçiyorsa önüne bir DLE daha konur. Kontrol amaçlı DLE her zaman tektir ve SOH, STX, ETX'ten önce görülür. Gönderici veride bir DLE gördüğü an araya bir DLE daha ekler. Buna byte doldurma (byte stuffing) denir.

Alıcı tarafı şöyle çalışır: DLE'yi görür, SOH'u görür, başlığı alır. DLE'yi görür, STX'i görür, veriyi almaya başlar. Veride art arda iki DLE görürse bunlardan ilkini atar (drop) ve ikincisini veri olarak kabul eder.

Slayttaki şekil (ekrandan, 00:50:00): üstteki çerçevede verinin içinde `DLE ETX` geçmektedir. Alttaki şeffaf veri çerçevesinde bu dizinin önüne bir DLE eklenmiştir. Şekildeki ok, eklenen DLE'yi "Alıcı tarafından değerlendirilmeyecek olan DLE karakteri" diye gösterir.

```text
Özgün    : SYN SYN DLE SOH Header DLE STX [ ...  DLE ETX ... ] DLE ETX BCC
Şeffaf   : SYN SYN DLE SOH Header DLE STX [ ... DLE DLE ETX ... ] DLE ETX BCC
                                                ^
                                 alıcının değerlendirmeyeceği DLE
```

### 5.3 Ek yük

Hoca bu yöntemin temel sıkıntısını sordu ve cevapladı: şeffaflığı sağlamak için veride geçen her kontrol karakterine karşılık bir byte daha eklenir. Çerçevede 50 tane özel karakter geçiyorsa en az 50 byte ek yük oluşur. Bu, çerçevenin başı ve sonu için zaten eklenen byte'ların üstüne gelir. Byte doldurmanın ek yükü (overhead) yüksektir.

## 6. Blok Yapısı, Çok Çerçeveli İletim ve Kontrol Çerçeveleri

### 6.1 Blok yapısı

Büyük çerçeve gönderildiğinde hata olasılığı artar. Küçük çerçeve gönderildiğinde ise her çerçevenin başına, sonuna, ortasına eklenen alanlar ek yük olur. Bu ikilem için blok yapısı kurgulanmıştır.

Slayttaki metin ve yapı (ekrandan, 00:55:00):

- Gönderici ile alıcı arasında aktarılacak ileti çerçevesi büyüdükçe hata olma olasılığı ve buna bağlı olarak hatanın tespit edilmesi ve iletinin tekrarlanması daha çok zaman alacaktır.
  - iletinin daha ufak parçalardan oluşan daha çok sayıda bloğa ayrılması

| SYN | SYN | SOH | Header | STX | Veri | ITB | BCC | STX | Veri | ETX | BCC |
|-----|-----|-----|--------|-----|------|-----|-----|-----|------|-----|-----|

Şekilde `STX Veri ITB BCC` Blok1, `STX Veri ETX BCC` Blok2 olarak işaretlidir.

Hoca iki birim veriyi örnek aldı. İkisini tek blok olarak tek BCC ile gönderip hata çıkarsa tamamı tekrar gönderilir. Blok yapısında bir çerçevenin içine birden çok blok konur ve her blok ayrı kontrol edilir. Bloklardan birinde hata olursa yine bütün çerçeve yeniden gönderilir. Hoca "o zaman bu işin esprisi ne?" diye sordu ve şöyle cevapladı:

- İki veriyi ayrı çerçeveler olarak gönderseydik her biri için ayrı SYN, SOH ve başlık gerekirdi. Blok yapısında bu tekrar yoktur.
- İki veriyi tek blokta tek BCC ile gönderseydik hata olasılığı artar, hatayı tespit etme şansı düşerdi. Blok yapısında verinin daha küçük parçaları ayrı BCC ile kontrol edildiği için hatayı yakalama şansı daha yüksektir.

### 6.2 Çok çerçeveli iletim

Veri her zaman tek çerçeveye sığmayabilir. O zaman birden çok çerçeve kullanılır. Her çerçeve SYN ile başlar, SOH, başlık ve STX ile devam eder, sonra veri ve blok bilgileri gelir. Ara çerçevelerin hepsi ETB (End of Transmission Block) ile biter, sonuncusu ETX ile biter. Böylece alıcı bütün çerçevelerin bittiğini anlar.

Stop-and-wait kullanılıyorsa her çerçeveye karşılık bir alındı gelir: ACK0 ve ACK1 içeren kontrol çerçeveleri. İlk çerçeveyi alan taraf ACK1 gönderir, çünkü artık bir sonrakini beklemektedir. Onu da alınca ACK0 gönderir. Alındı yapısında her zaman beklenen bir sonraki çerçeve bildirilir.

### 6.3 Kontrol çerçevesi

Slayttaki metin ve yapı (ekrandan, 01:00:00):

- Kontrol çerçeveleri bağlantının tesisi, sürdürülmesi, akış kontrolü, alındı bilgilerinin iletimi ve bağlantının sonlandırılmasını işlevlerini de yerine getirmek için kullanılırlar.

| SYN | SYN | Diğer kontrol bilgileri | BCC |
|-----|-----|-------------------------|-----|

Kontrol çerçevesi iki SYN ile başlar ve BCC ile biter. Aradaki kısımda örneğin ACK kontrol karakteri bulunur. Burada tek bir kontrol bilgisi olmak zorunda değildir, protokolün çalışmasına göre değişir. Hoca, bazı protokollerde 8-10 alanlık ve her alanın yalnız set ya da reset edildiği kontrol yapılarının da görülebileceğini söyledi.

## 7. BSC

Byte yönelimli protokollere örnek olarak IBM'in BSC'si (Binary Synchronous Communication) verildi:

- 1960'larda kullanıldı.
- Hem noktadan noktaya hem çok noktalı bağlantılar için uygundur.
- Yarı çift yönlü (half-duplex) çalışır. Hoca bunun dezavantaj olduğunu, ama biraz da alttaki yapıyla ilgili olduğunu söyledi.
- Akış kontrolü için stop-and-wait kullanır.
- Kod bağımlıdır: tek byte üzerinden çalıştığı için kontrol karakterleri kullanılan kodlamaya göre değişir. ASCII'de ve EBCDIC'te farklı değerler kullanmak gerekir.

> **Ders sonrası not:** Hoca UTF-8'in iki byte'lık bir yapı olduğunu söyledi. UTF-8 değişken uzunluklu bir kodlamadır: bir karakter 1 ile 4 byte arasında yer kaplar, ASCII karakterleri tek byte'tır.

## 8. Bit Yönelimli Protokollere Geçiş

Byte yönelimli protokollerde çerçeve bir byte dizisi olarak yorumlanıyordu. Bit yönelimli protokollerde ise çerçeve bir bit dizisi (bit stream) olarak düşünülür ve her şey bit bit anlamlandırılır.

Hoca bunun nedenini verimlilikle açıkladı. Byte yönelimli yapıda verimsizliğin kaynağı byte doldurmaydı: tek bir kontrol karakteri yerine iki byte göndermek gerekiyordu. Bit yönelimli yapıda farklı bit dizilimlerine farklı anlamlar yüklenir ve kontrol dizileri böyle oluşturulur. Bu dizilerin veride oluşmasını önlemek için bu kez araya byte değil bit eklenir: bit doldurma (bit stuffing). Böylece protokolün ek yükü kendiliğinden azalır.

Slayttaki metin ve şema (ekrandan, 01:05:00):

- Bit Yönelimli Protokoller
  - SDLC (Synchronous Data Link Control)
  - HDLC (High-Level Data Link Control)
  - LAPB (Link Access Procedure Balanced), LAPD (Link Access Procedure on D Channel), LAPM (Link Access Procedure for Modem)
- Bit yönelimli protokoller aktarılacak çerçeveyi birbirini takip eden bitlerden oluşmuş bir dizi olarak görmektedir.
  - çerçeve içindeki dizilişleri
  - diğer bitlere göre durumları
- Temelde ISO tarafından standart haline getirilmiş olan HDLC (High Level Data Link Control) protokolü

HDLC başka firmalar ve kurumlar tarafından uyarlanıp kullanılmış bir protokol yapısıdır. Bit yönelimli çalışan protokol sayısı çoktur, ama çoğu HDLC'nin bir alt kümesi ya da benzeridir.

## 9. HDLC

### 9.1 Genel özellikler

Slayttaki metin (ekrandan, 01:20:00):

- Bit yönelimli protokollerin genel özellikleri şöyle sıralanabilir:
  - Noktadan noktaya veya çok noktaya bağlantı için uygundur.
  - Hem yarı hem tam çift yönlü çalışmayı destekler.
  - Akış kontrolü ve otomatik istek yenileme (ARQ) için kayan pencere tekniğinden yararlanır.
  - Kullanılan kodlama sisteminden bağımsızdır.

Kodlama sisteminden bağımsızlığın nedeni işin byte değil bit üzerinden yapılmasıdır. Kontrol dizisi olarak bir bit dizilimi seçilir ve bit doldurma ile bu kombinasyonun istenmeden oluşması her zaman engellenebilir.

### 9.2 İstasyon tipleri

Noktadan noktaya ve çok noktalı bağlantıyı desteklediği için HDLC farklı topolojilerde karşımıza çıkar. Bunlarla birlikte farklı istasyon tipleri oluşur:

- **Birincil (primary):** Çoklu bağlantıda birinin iletim hattı üzerinde söz sahibi olması gerekir. İletişimin kontrolünü ve yönetimini yapan istasyon birincildir.
- **İkincil (secondary):** İletişime katılır, ama bunu birincilin izni ve komutları doğrultusunda yapar.
- **Birleşik (combined):** Bazı cihazlar hem birincil hem ikincil gibi davranabilir. Bu aynı anda olmak zorunda değildir, farklı anlarda farklı rol üstlenebilir.

### 9.3 Dengeli ve dengesiz yapılanış

Yapılanış (configuration) dengeli (balanced) ya da dengesiz (unbalanced) olabilir. Hoca, buradaki "dengeli" sözcüğünün bir ruh hâlini anlatmadığını, çevirinin biraz kötü olduğunu esprili bir dille belirtti. Sınıflandırma, ağdaki birincil ve ikincil istasyonların sayısal dağılımına göre yapılır:

- **Dengesiz:** Bir birincile karşı çok sayıda ikincil vardır. Düğüm dağılımı açısından bir dengesizlik vardır.
- **Dengeli:** Daha çok noktadan noktaya bir yapıdır. Haberleşme iki istasyon arasında dengeli biçimde kurulur.

### 9.4 İletişim kipleri

Hattın kontrolünün kimde olduğunu belirleyen üç çalışma şekli (modes of communication) vardır. Slayttaki metin (ekrandan, 01:25:00):

- NRM (Normal Response Mode)
  - Dengesiz yapılanış için tanımlıdır.
- ARM (Asynch. Response Mode)
  - Dengesiz yapılanış için tanımlıdır.
  - İkincil istasyon, iletim hattının kullanılmadığı durumlarda, birincil istasyonun izni olmaksızın da veri iletiminde bulunabilir.
- ABM (Asynch. Balanced Mode)
  - Dengeli yapılanış için tanımlıdır.
  - Bilgisayarlar eşit haklara sahip (birleştirilmiş) olup noktadan noktaya yapıda taraflardan herhangi biri diğerinin izni olmaksızın iletime geçebilir.

NRM alışılmış birincil-ikincil ilişkisidir: ikincil, birincilin izni olmadan hiçbir şekilde iletişime geçemez. ARM'de ikincil hat boşken izinsiz iletebilse de hattı başlatma, hata kontrolü ve hattı sonlandırma görevleri birincildedir, yani hattın sorumluluğu hâlâ onun elindedir. Hoca ARM'nin pek doğrudan kullanılan bir kip olmadığını, oldukça nadir kullanıldığını söyledi. ABM'de herhangi bir taraf herhangi bir anda iletişimi başlatabilir ve hattı kullanabilir.

### 9.5 Çerçeve tipleri

Bundan sonraki slaytlar kaybolduğu için anlatım sözlü yapıldı (ekranda yalnız başlık vardı, ekrandan, 01:30:00).

Byte yönelimlilerde çerçeveler veri ve kontrol diye ikiye ayrılıyordu. HDLC'de üçe ayrılır:

- **I çerçevesi (information, bilgi):** Kullanıcı verisini ve buna ilişkin kontrol bilgisini taşır.
- **S çerçevesi (supervisory, gözetim):** Veri bağı katmanındaki hata ve akış kontrolü gibi işlevleri yerine getirir.
- **U çerçevesi (unnumbered, numarasız):** Sistem yönetimiyle ilgili özel amaçlı çerçevedir.

Çerçeve yapıları:

| Çerçeve | Alanlar |
|---------|---------|
| I | Flag, Adres, Kontrol, Kullanıcı verisi, FCS, Flag |
| S | Flag, Adres, Kontrol, FCS, Flag |
| U | Flag, Adres, Kontrol, Yönetim bilgisi, FCS, Flag |

Her çerçeve iki flag arasına sıkıştırılmış gibi düşünülebilir.

### 9.6 Flag ve bit doldurma

Flag alanı 8 bitlik bir dizilimdir. Başı ve sonu 0, ortası altı tane 1'dir:

```text
0 1 1 1 1 1 1 0
```

Flag hem çerçevenin başını ve bitişini belirlemek hem de eşzamanlılığı sağlamak için kullanılır. Bu dizilim flag olarak seçildiğine göre çerçevenin içinde herhangi bir yerde yeniden oluşabilir. Bunu engellemek için byte yönelimlilerdeki byte doldurmanın karşılığı olarak bit doldurma yapılır.

Gönderici, beş tane 1'i art arda yollayacağı zaman, dizinin flag'e benzemesini önlemek için beşinci 1'den sonra araya bir 0 yerleştirir. Alıcı da beş tane 1 gördüğünde sonraki bite bakarak gelenin ne olduğuna karar verir ve eklenen 0'ı çıkararak işlemi tersine çevirir. Bu işlem her seferinde yapılır.

> **Ders sonrası not:** Hoca kuralı "0'dan sonra beş tane 1" diye anlattı. Standart HDLC'de doldurma, öncesinde ne olduğuna bakılmaksızın veride art arda gelen her beş 1'den sonra yapılır. Alıcı beş 1'den sonra 0 görürse onu atar, 1 görürse (yani altı 1) flag ya da hata söz konusudur.

### 9.7 Adres alanı

Adres alanında her zaman ikincil istasyonun adresi bulunur:

- Çerçeve birincil tarafından üretildiyse hangi ikincile gideceğini gösterir, "to" (kime) gibi yorumlanır.
- Çerçeve ikincil tarafından üretildiyse yine o ikincilin adresi bulunur, bu kez "from" (kimden) gibi yorumlanır.

Adres alanı yapıya bağlı olarak bir byte ya da daha fazla olabilir. Bir byte olduğunda adres için yalnız 7 bit kullanılır, çünkü kalan bit adres alanının devam edip etmediğini gösterir. İki byte'lık adreste her byte'ta 7 bitlik adres parçası ve bir devam biti bulunur.

> **Ek bilgi (derste anlatılmadı):** Genişletilmiş adreslemede büyük olasılıkla her adres byte'ının en düşük anlamlı biti kullanılır: bu bit 0 ise adres bir sonraki byte'ta devam eder, 1 ise o byte adresin son byte'ıdır.

### 9.8 Kontrol alanı

Kontrol alanı 1 ya da 2 byte olabilir. Boyutu, akış kontrolünde kullanılan kayan pencere tekniğindeki pencere büyüklüğüne göre belirlenir. Pencere büyüklüğü de hat gecikmesine göre seçilir: gecikme yüksekse hat uzun süre boşta (idle) kalacağı için büyük pencere kullanılır, böylece o zaman aralığında hatta daha çok çerçeve çıkarılır.

> **Hocanın vurgusu:** Pencere büyüklüğünün hat gecikmesine göre seçilmesi sınavda sorulmuş bir konudur.

**Çerçeve tipinin belirlenmesi.** Üç çerçeve tipi de flag, adres, kontrol diye başlar. Alıcı flag'i ve adresi gördüğünde çerçevenin tipini henüz bilmez. Tipi kontrol alanının ilk bitleri belirler:

| Kontrol alanının başı | Çerçeve tipi |
|-----------------------|--------------|
| `0` | I çerçevesi |
| `10` | S çerçevesi |
| `11` | U çerçevesi |

**I çerçevesinin kontrol alanı.** İlk bit 0'dır, geriye 7 bit kalır. Bunlar iki tane 3 bitlik alana ve bir P/F bitine bölünür:

```text
| 0 | N(S) (3 bit) | P/F | N(R) (3 bit) |
```

N(S)'deki S gönderen (sender), N(R)'deki R alan (receiver) tarafını anlatır. Bu iki alanda gönderilen ve alınan çerçevelerin sıra numaraları tutulur. N(R) aynı zamanda alındı bilgisini de taşır. 3 bitlik numaralarla pencere büyüklüğü en çok $2^3 - 1 = 7$ olur.

Daha büyük pencere gerekirse kontrol alanı 2 byte'a çıkarılır. Başlangıç biti yine 0'dır, geriye 15 bit kalır. Bunlar 7'şer bitlik iki alana (ve P/F bitine) bölünür. $2^7 = 128$ olduğundan pencere boyutu en çok 127 olabilir. İlk alan yine gönderilenleri, ikinci alan alınanları tutar.

**S çerçevesinin kontrol alanı.** S çerçevesinde kullanıcı verisi yoktur, yalnız kontrol alanı vardır. Hoca S çerçevesinin ne zaman gerektiğini şöyle açıkladı: işleri optimize etmek için çoğu zaman piggybacking yapılır, yani gönderilecek bir verinin kontrol alanına alındı bilgisi eklenir. Ama bazen bir bilgi gelmiştir, ona geri dönüş yapmak gerekir ve gönderilecek bir veri yoktur. Zaman da işlemektedir. O zaman bir S çerçevesi oluşturulup gönderilir.

```text
| 1 0 | kod (2 bit) | P/F | N(R) (3 bit) |
```

S çerçevesi bir şey göndermediği, yalnız geri dönüş yaptığı için N(R) alanı yeterlidir. Kod alanı 2 bit olduğundan dört durum vardır:

| Kod | Ad | Anlamı |
|-----|----|--------|
| `00` | RR (Receive Ready) | Almaya hazırım. |
| `01` | REJ (Reject) | Ret; Go-Back-N uygulanır. |
| `10` | RNR (Receive Not Ready) | Şu an bilgi alamıyorum. |
| `11` | SREJ (Selective Reject) | Arada eksik çerçeve var, yalnız o yeniden gönderilsin. |

Hoca bu durumların her birinin ne zaman gönderileceğini ve ne sonuç doğuracağını ayrıntılı anlatmanın gerekmediğini, genel yapıya hâkim olmanın yeterli olduğunu, bunların ezberlenmesi gereken şeyler olmadığını söyledi.

**U çerçevesinin kontrol alanı.** U çerçevesi, veri iletişimindeki cihazlar arasında oturum kontrolü sağlamak ve sistem yönetim fonksiyonları için gereken bilgiyi taşımak amacıyla kullanılır. Gönderilen ya da alınan çerçeve numarasına ihtiyaç yoktur. Bunun yerine iki kod alanı tutulur. İlk iki bit 11'dir, geriye 6 bit kalır. Diğer çerçevelerle tek biçimli olsun diye P/F biti yine ortadadır:

```text
| 1 1 | kod (2 bit) | P/F | kod (3 bit) |
```

Toplam 5 bitlik kod $2^5 = 32$ farklı durumu ifade edebilir. Bu durumlar beş kategoride toplanır: kip ayarlama (mode setting), numarasız değişim (unnumbered exchange), bağlantıyı sonlandırma, bağlantıyı başlatma ve diğerleri. Hoca örnekler verdi:

- **Kip ayarlama:** Birincil, ikincille nasıl bir iletişim kurulacağını belirlemek için bir çerçeve gönderir. NRM için ilk iki bitlik kısma `00`, sonraki üç bitlik kısma `001` yazılır (SNRM, Set Normal Response Mode). ARM'de çalışılacaksa `11 000` gönderilir (SARM).
- **Numarasız değişim:** I çerçevesi kullanıcı verisi taşır. Numarasız değişimde ise kullanıcı verisi değil, hattın bağlantısıyla ilgili bilgi alınıp verilir: bir istasyonu yoklamak (poll), tarih ve saat alışverişi yapmak gibi.
- **Bağlantıyı sonlandırma:** Üç farklı tipi vardır.
  - DISC (Disconnect): bağlantıyı kuran taraf karşı tarafa bağlantıyı sonlandırmak için gönderir, kodu `00 010`.
  - RD (Request Disconnect): ikincil istasyon birincilden bağlantıyı sonlandırmasını ister, kodu yine `00 010`.
  - DM: kendisine bağlantı isteği gelen istasyonun bu isteği reddetmesi için kullanılır.

<!-- BELİRSİZ: Hoca DM kodunu "1100" diye söyledi; altyazı eksik olabilir ve slayt kaybolduğu için kareden doğrulanamadı. Standart HDLC'de DM (Disconnected Mode) büyük olasılıkla 11 000'dır. -->

> **Ek bilgi (derste anlatılmadı):** DISC ile RD'nin, SARM ile DM'nin kodlarının aynı olması büyük olasılıkla şundandır: HDLC'de aynı bit kalıbı komut (birincilden giden) olarak bir anlama, cevap (ikincilden gelen) olarak başka bir anlama gelir. Hangisi olduğu çerçevenin yönünden anlaşılır.

Hoca, bu kodların sayısal değerlerinin ezberlenmesi için değil, her kodun farklı bir işe karşılık geldiğini görmek için anlatıldığını vurguladı.

### 9.9 P/F biti

Üç çerçevede de bulunan bir bitlik P/F alanı poll/final bitidir:

- Birincil istasyondan ikinciye yollandığında poll (yoklama) yapıldığını gösterir.
- İkincil istasyondan birinciye cevap olarak gönderildiğinde final anlamına gelir.

İki durumda da adres alanında ikincilin adresi yer alır. Adres alanının "to" mu "from" mu anlamına geldiği, yani çerçevenin kimden kime gittiği P/F üzerinden anlaşılır.

Hoca HDLC'nin daha fazla ayrıntısına, alanların tek tek nasıl kullanıldığını gösteren işleyiş örneklerine girmenin anlamlı olmadığını düşündüğünü söyleyerek bu kısmı atladı.

## 10. LAP Ailesi ve SDLC

Bu iki protokol, HDLC'nin tanımlanmış bir standart olarak birçok protokolün temelini oluşturduğunu gösteren örnekler olduğu için anlatıldı.

### 10.1 Link Access Procedure ailesi

- **LAPB (Link Access Procedure Balanced):** Hoca, ISDN B kanalında kullanıldığında dengeli kipi (ABM) uyguladığını söyledi. ISDN yapısı ve B ile D kanalları ilerleyen haftalarda konuşulacaktır.
- **LAPD (Link Access Procedure on D Channel):** ISDN'in D kanalında kullanılır. D kanalı bant dışı sinyalleşme (out-of-band signalling) için kullanılan kanaldır.
- **LAPM (Link Access Procedure for Modem):** Modem iletişimi için, örneğin V.42 standardında kullanılır.

Link access procedure'ların her biri HDLC'nin basitleştirilmiş bir alt kümesidir. Kullanıldıkları yere, yapıya ve kanala göre HDLC'nin farklı özelliklerini uygularlar. Hoca bunların genel kültür olarak bilinmesinin yeterli olduğunu söyledi.

> **Ders sonrası not:** LAPB en çok X.25 ağlarının veri bağı katmanı protokolü olarak bilinir. ISDN B kanalı üzerinden X.25 taşındığında da büyük olasılıkla LAPB kullanılır.

### 10.2 SDLC

SDLC (Synchronous Data Link Control), IBM'in SNA (System Network Architecture) mimarisinde ikinci katmanda kullanılan protokoldür. Noktadan noktaya ve çok noktalı bağlantılarda kullanılır, hata algılama özelliği vardır, hem yarı hem tam çift yönlü bağlantıyı destekler. Hoca SDLC'yi HDLC'nin farklı bir versiyonu olarak tanıttı ve ikisinin yakından ilgili olduğunu söyledi.

> **Ders sonrası not:** Tarihsel sıra büyük olasılıkla tersidir: IBM SDLC'yi 1970'lerde geliştirmiş, ISO HDLC'yi SDLC'yi temel alarak standartlaştırmıştır.

## 11. Yerel Alan Ağlarına Giriş

### 11.1 Tanım

Yerel alan ağı (LAN), sınırlı bir coğrafi alanda bulunan bilgisayar sistemlerinin ortak bir iletim ortamını kullanarak haberleşmesidir. Bu haberleşme noktadan noktaya değil, çok noktalıdır (multi-point). Günümüzde en yaygın olanları kablosuz LAN (wireless LAN) ve Ethernet'tir. Bunların dışında token bus, token ring, FDDI ve CDDI de vardır. FDDI ve CDDI dışındakilerin neredeyse tamamı IEEE tarafından geliştirilen 802 standart ailesini kullanır: 802.1, 802.2, 802.3, 802.4, 802.5. Bu yüzden yerel alan ağları 802 projesi üzerinden anlatılacaktır.

### 11.2 Paylaşılan ortam ve patlamalı trafik

LAN'lar paylaşılan bir iletim ortamı kullanır. Bu ortam bütün bilgisayarlar arasında düzgün paylaştırılmalıdır. Kimisi buna adil (fair) paylaşım, kimisi yüksek başarımlı paylaşım der.

Hoca bunu bilgisayar ağlarının trafik yapısıyla açıkladı. Bilgisayar ağları patlamalı (bursty) trafiğe sahiptir. Beş bilgisayar açılıp hiçbir şey yapılmasa bile bazılarının kullanıcıdan bağımsız veri alıp gönderdiği görülür: biri güncelleme indirir, birinin arkasında başka bir servis çalışır, bir kullanıcı bir şey indirir. Bu trafik günün her saatinde sabit gitmez, farklı zamanlarda farklı ihtiyaçlara göre değişir ve tepeler yapar.

Ortamın etkin kullanımı, elinde verisi olanın veriyi gönderebilmesi demektir. Herkesin elinde çok veri varsa bu, en az tıkanıklığa neden olarak ve hat kullanımı optimize edilerek yapılmalıdır. Bir veriyi göndermek için aynı veriyi hatta beş kere çıkarmamak, çarpışmaları azaltmak gerekir. Bu yüzden bir yönetime ihtiyaç vardır.

### 11.3 Ortam paylaşımının yolları

**Sabit atama.** En kötü yol sabit paylaşımdır. Paylaşılan kanalı sabit biçimde bölmek mümkündür ve çalışır: herkese bir zaman aralığı atanır, bilgisi olan o aralıkta gönderir, olmayan göndermez. Aralık geçtikten sonra bilgisi olan, diğer herkesin sırasının bitmesini beklemek zorundadır. Bu ciddi bir gecikme demektir.

Hoca bunun kullanıldığı bir örnek verdi: radyo yayını. Kanal zaman bazında değil frekans bazında bölünür, her yayıncıya sınırlı bir bant genişliği verilir ve bu onlara yeter. Kullanılmayan ve boşa harcanan kanal vardır, ama orada düzenli ve akışkan bir trafik olduğu için düzen yürür.

Bilgisayar sistemlerinde bu anlamlı değildir:

- Ortamdaki cihaz sayısı sürekli değişir. Hoca bir odadaki birkaç bilgisayara dizüstü, cep telefonu ve tablet katıldıkça sayının arttığını, çıktıkça azaldığını örnek verdi. Sayı sürekli değişirken atama yapmak zordur.
- Ortamda beş bilgisayar var diye kanal beşe bölünürse, dördü hiç göndermezken gönderecek çok verisi olan beşinci hattın tam kapasitesini kullanamaz.

**Çekişme temelli (contention based).** Hattı kimin kullanacağına düğümler çekişir, kazanan hattı alır. Sorunları: çekişmeye zaman harcanır, çekişme belli bir sürede çözülemeyebilir, çekişen düğüm sayısı çoksa bazı düğümler ciddi gecikme yaşar. En basit hâlinde veri olan doğrudan gönderir, başkası da aynı anda gönderirse çarpışma (collision) olur ve verinin bozulduğu fark edilir. Mümkünse taşıyıcı algılama (carrier sense) devreye sokulur, yani hatta birinin olup olmadığı önceden dinlenir. Taşıyıcı algılama yoksa çarpışmadan kaçınma (collision avoidance) denenir. ALOHA, slotted ALOHA ve persistent / p-persistent yöntemler ilerleyen derslerde konuşulacaktır.

**Rezervasyon temelli.** Rezervasyon için genellikle token adı verilen bir yapı kullanılır. Token ring ve token bus bunun örnekleridir. Bunlar zamanında uygulanmış ve kullanılmıştır, ama günümüzde pek kullanım alanı kalmamıştır. Hoca IBM'in bazı ana bilgisayarlarında (mainframe) hâlâ kullanıldığını, ama yenilerinde kullanılmadığını söyledi. Rezervasyon illa token ile yapılmak zorunda değildir.

**Karma yapılar.** Bir teknoloji yalnız çekişme, yalnız rezervasyon ya da yalnız sabit temelli olmak zorunda değildir. Hat farklı kanallara bölünüp bir kısmı çekişme, bir kısmı rezervasyon için kullanılabilir. Güncel yapıların birçoğunda bu görülür.

## 12. IEEE 802 Referans Modeli

802 projesi, fiziksel katmanın ve veri bağı katmanının fonksiyonlarını tanımlayarak yerel alan ağlarında kullanılacak protokoller arasındaki uyumluluğu sağlamayı hedefler.

OSI referans modelinin katmanları yukarıdan aşağı uygulama, sunum, oturum, taşıma, ağ, veri bağı ve fiziksel katmandır. 802 referans modeli yalnız alt kısmı tanımlar:

| OSI | IEEE 802 |
|-----|----------|
| Üst katmanlar | Tanımlanmaz (üst katmanlar) |
| Ağ | Service Access Point (ağlar arası geçiş) |
| Veri bağı | LLC (Logical Link Control) |
| Veri bağı | MAC (Medium Access Control) |
| Fiziksel | Fiziksel |

OSI'deki veri bağı katmanı 802'de MAC ve LLC diye ikiye bölünmüştür. MAC hatta nasıl erişileceğini belirler. LLC'nin üstüne, ağ katmanına karşılık gelen ve ağlar arası geçişi (internetworking) sağlayan Service Access Point konmuştur. 802 projesinin üst katmanlarla bir derdi yoktur, yalnız üste geçiş için gerekenleri tanımlar.

Alt tarafta hangi fiziksel teknoloji çalışırsa çalışsın LLC standarttır. Amaç ikinci katmanın en azından bir parçasını standart hâle getirmektir. Altta 802.3, 802.4 (token bus) ya da 802.5 (token ring) kullanılabilir, her birinin kendi fiziksel katmanı vardır. MAC, fiziksel katman ile LLC arasındaki geçişi sağlar ve bunun tek biçimli olmasını sağlar.

Hoca, slaytlar olmadan devam etmenin zor olduğunu ve bazı grafikleri göstermek istediğini söyleyerek dersi burada bitirdi.

## Örnek Sorular

Bu derste ekranda soru gösterilmedi. Aşağıdakiler hocanın derste sözlü sorup cevapladığı sorulardır.

**Soru 1** (derste sözlü, 00:23:15): Şu ana kadar konuşulan konular içinde, veri bağı kontrolünü yapacak yapının neler yapması gerekir?

> **Çözüm (derste verildi):** Akış kontrolü, hata kontrolü ve iletişim kurallarını yerine getirmesi gerekir. Bunun için veriye kontrol bilgileri (çerçeve sınırları, adres, sıra numarası, hata sezme kodu) eklenir ve veri, kontrol ve ikisini birlikte taşıyan çerçeve yapıları tanımlanır.

**Soru 2** (derste sözlü, 00:27:13): Fiziksel katmanda eşzamanlılık nasıl sağlanır? Mantıksal seviyede nasıl sağlanır?

> **Çözüm (derste verildi):** Fiziksel katmanda ortak bir saat (zamanlama) işaretiyle, mantıksal seviyede ise öncül/ardıl (preamble/postamble), başlangıç/bitiş bitleri ya da flag'lerle sağlanır.

**Soru 3** (derste sözlü, 00:51:34): Byte yönelimli protokollerde DLE ile byte doldurma yapmanın temel sıkıntısı nedir?

> **Çözüm (derste verildi):** Veride geçen her kontrol karakteri için bir byte daha eklenir. 50 özel karakter içeren bir çerçevede en az 50 byte ek yük oluşur. Ek yük yüksek olduğu için verimli değildir. Bit yönelimli protokollerde araya byte yerine bit eklendiği için ek yük azalır.

**Soru 4** (derste sözlü, 00:55:10): Bir çerçevedeki bloklardan birinde hata olduğunda yine bütün çerçeve yeniden gönderiliyorsa, blok yapısının yararı nedir?

> **Çözüm (derste verildi):** Ayrı çerçeveler gönderilseydi her biri için SYN, SOH ve başlık tekrarlanırdı; blok yapısında bu ek yük yoktur. Tek blok ve tek BCC kullanılsaydı hatayı tespit etme şansı düşerdi; blok yapısında daha küçük parçalar ayrı BCC ile kontrol edildiği için hata sezme şansı daha yüksektir.

**Soru 5** (derste sözlü, 01:35:12): Kayan pencerede pencere büyüklüğü neye göre belirlenir? Hat gecikmesi yüksekse ne yapılır?

> **Çözüm (derste verildi):** Hat gecikmesine göre belirlenir. Gecikme yüksekse büyük pencere kullanılır, çünkü hat uzun süre boşta kalacaktır ve bu sürede daha çok çerçeve gönderilebilmesi istenir. HDLC'de 3 bitlik sıra numarasıyla pencere en çok $2^3 - 1 = 7$, 2 byte'lık kontrol alanında 7 bitlik sıra numarasıyla en çok $2^7 - 1 = 127$ olur.

## Dersin Toparlaması

Bu derste veri bağı protokolleri iki eksende sınıflandırıldı. Eşzamansız protokoller başlangıç ve bitiş bitleriyle çalışır ve modem bağlantılarında kullanılır. Eşzamanlı protokollerde eşzamanlılık fiziksel seviyede saat işaretiyle, mantıksal seviyede flag'lerle sağlanır. Byte yönelimli protokoller çerçeveyi karakter dizisi olarak görür. SYN, SOH, STX, ETX, ETB, DLE gibi kontrol karakterleriyle çerçeve kurar, ikili veride şeffaflığı DLE ile byte doldurarak sağlar ve kod bağımlıdır. Blok yapısı ve çok çerçeveli iletim, büyük ve küçük çerçeve arasındaki ödünleşimi dengeler. BSC bu ailenin örneğidir. Bit yönelimli protokoller ise çerçeveyi bit dizisi olarak görür, şeffaflığı bit doldurmayla sağlar ve kod bağımsızdır.

HDLC'de istasyon tipleri, dengeli ve dengesiz yapılanış, NRM/ARM/ABM kipleri, I/S/U çerçeveleri, `01111110` flag'i, adres alanı, kontrol alanının yapısı (N(S), N(R), S ve U kodları) ve P/F biti incelendi. LAP ailesi ve SDLC, HDLC'nin türevleri olarak tanıtıldı. Son olarak yerel alan ağlarına giriş yapıldı: paylaşılan ortamda patlamalı trafik, sabit, çekişme temelli, rezervasyon temelli ve karma ortam paylaşımı ile veri bağı katmanını MAC ve LLC diye ikiye bölen IEEE 802 referans modeli anlatıldı. Sonraki derslerde ALOHA, slotted ALOHA ve persistent yöntemler gibi çekişme temelli erişim yöntemleri ile 802 standartlarının ayrıntılarına geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
