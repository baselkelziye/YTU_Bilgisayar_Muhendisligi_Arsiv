# Ders 1 Genişletilmiş Notu: Analog İşaretlerin Sayısallaştırılması, Nyquist Teoremi ve Lojik Devrelere Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin kapsamı ve kaynaklar
- 2. Transistör ve 0-1 mantığı
- 3. Analog ve sayısal işaretler
- 4. Analog işaretin bilgisayara aktarılması: örnekleme
- 5. Frekans, sinüzoidal bileşenler ve Fourier analizi
- 6. Nyquist teoremi
- 7. Nicemleme (quantization)
- 8. Temel lojik kapılar: AND ve OR
- 9. Sayı sistemlerine giriş
- 10. Fourier gösterimi, DC ve AC bileşenler
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin kapsamı ve kaynaklar

Lojik devreler dersi, bilgisayar mühendisliği lisans programının zorunlu ve donanım (elektronik) ağırlıklı derslerinden biridir. Sonraki dönemlerdeki elektronik devreler, bilgisayar mimarisi ve mikroişlemciler gibi derslerin temelini oluşturur. Dersin temel amacı, liseden bilinen mantık (lojik) kavramlarının devreler üzerinde nasıl uygulandığını göstermektir. Ders bilgi sayfasındaki tanıma göre amaç, kombinezonsal ve ardışıl devreleri çözümleme ve tasarım yeteneği kazandırmak ve bunu laboratuvar ortamında pekiştirmektir (ekrandan, 00:15:00).

Derste iki büyük devre ailesi incelenir:

- **Kombinezonsal (birleşik) devreler:** Herhangi bir hafıza birimi barındırmayan devrelerdir. Çıkış yalnız o anki girişlere bağlıdır.
- **Ardışıl devreler (sequential circuits):** Hafıza barındıran devrelerdir. Hoca bunu saymayla örnekledi: "1, 2, 3, 4" diye sayarken "4" diyebilmek için daha önce "3" dendiğini bilmek gerekir. Bu tür hafıza gerektiren devreler dersin ikinci yarısında anlatılır.

Konu akışı şöyle özetlendi: sayısal sistemlerin genel özellikleri, sayı sistemleri, Boole cebrinin temelleri, lojik fonksiyonlar ve lojik kapıların oluşturulması, bunların sadeleştirilmesi, ardından kombinezonsal devreler. Kombinezonsal devreler, yazılımda yapılan işlemleri (karşılaştırma, toplama gibi) donanımsal olarak yapan devrelerdir. Elektronik devre tasarımında çok kullanılan seçiciler (multiplexer), dağıtıcılar (demultiplexer), kod çözücüler (decoder) ve kodlayıcılar (encoder) bu kısımda incelenir. Sonra hafızalı devrelere geçilir: flip-floplar, ardışıl devrelerin çözümlenmesi ve tasarımı, saklayıcılar, sayıcılar ve bellekler. Ders bilgi sayfasındaki içerik listesi de aynı sırayı verir: sayı sistemleri, Boole cebri, lojik fonksiyonların indirgenmesi, Karnaugh haritaları, Quine-McCluskey yöntemi, kombinezonal devre analizi ve tasarımı, senkron ve asenkron devre yapıları, ardışıl devre analizi ve tasarımı, saklayıcılar, sayıcılar, bellekler (ekrandan, 00:15:00).

Ders kaynakları (ekrandan, 00:15:00):

- M. Morris Mano, Charles R. Kime, *Logic and Computer Design Fundamentals*, Prentice Hall.
- M. Morris Mano, *Digital Design*, Prentice Hall.
- Taner Arsan, Rıfat Çölkesen, *Lojik Devre Tasarımı*, Papatya Yayıncılık.
- M. Morris Mano, *Sayısal Tasarım*, Literatür Yayıncılık.

Hoca ders sonunda bu kitaplardan herhangi birinin takip edilmesinin yeterli olduğunu, dersin genel (jenerik) bir ders olduğu için hepsinde akışın hemen hemen aynı olduğunu söyledi.

Hoca ayrıca donanım derslerinin önemine değindi: gömülü sistemlerle ilgili iş alanları giderek artmaktadır. Gömülü sistemler, robotik sistemler ve elektronik devre sistemleri için gerekli altyapı bu derslerle kazanılır. Bilgisayar mühendisliğini yalnız yazılım olarak düşünmemek gerekir.

## 2. Transistör ve 0-1 mantığı

Hoca bilgisayar mühendisliğinin başlangıcını bir elektronik elemanın bulunuşuna bağladı ve öğrencilere bu elemanın ne olduğunu sordu. Cevap transistördür; tahtaya "1950s Transistor" yazıp NPN tipi bir transistör sembolü çizdi (ekrandan, 00:20:00).

> **Ders sonrası not:** Hoca transistörün 1950'lerde bulunduğunu söyledi. Transistör büyük olasılıkla 1947'de Bell Laboratuvarları'nda bulunmuş, 1950'lerde yaygınlaşmıştır.

Transistörün tabanına (bazına) verilen akıma göre transistör çalıştırılır ve çıkıştan (OUT) bir gerilim alınır. Çıkışta 5 V elde edildiğinde bu "1", 0 V elde edildiğinde "0" olarak yorumlanır. Böylece çıkışta 1, 0, 1, 0, 1, 1 gibi bir dizi oluşur. Bu bit dizileri (bitstream) belirlenip karakterlerin kodlanmasında kullanılır. Lojik devreler, bu 1 ve 0'ları algılayıp onların mantığına göre sonuç üreten devrelerdir.

Hoca liseden hatırlatma yaptı: matematik dersindeki mantık konusunda $p$, $q$ önermeleri 1 ya da 0, yani doğru ya da yanlış değer alıyordu. Bilgisayar mühendisliğinde bu $p$ ve $q$'lar artık **değişkenler** (variable) olur. Bir değişkenin 1 ya da 0 değerlerinden birini alması lojik devrelerin temel kavramıdır.

## 3. Analog ve sayısal işaretler

Bir sensörden (ör. herhangi bir algılayıcı yapıdan) elde edilen elektriksel çıktıya **analog işaret** denir. Analog işaret $x(t)$ olarak yazılır ve zamanın her anında tanımlıdır. Hoca bunu şöyle açıkladı: zaman ekseninde 0 ile 1 arasında işaret yalnız 0,5 ya da 0,55 gibi seçilmiş anlarda değil, her anda bir değere sahiptir; dolayısıyla sonsuz sayıda noktadan oluşur. Genlik ekseninde de durum aynıdır: işaret bir anda 0,5, başka bir anda 0,6 değerini alırken arada 0,556789... gibi virgülden sonra sonsuza giden değerler alabilir (tahtada "0,556789..." yazıyor, ekrandan, 00:20:00). Yani hem $t$ ekseninde hem $x(t)$ ekseninde sonsuz değer vardır. Bu işaretlere **analog işaretler** ya da **sürekli işaretler** (continuous signals) denir.

**Sayısal işaretler** ise belli seviyelerde değer alan işaretlerdir. Örneğin yalnız 1, 3, 5 gibi tam sayı değerlerini alabilen, basamaklı bir işaret (tahtada mavi renkle çizilen basamaklı işaret, ekrandan, 00:20:00).

Analog işaret örnekleri olarak ses işareti ve EKG işareti verildi. EKG, kalbin vücut derisinde oluşturduğu elektriksel potansiyelleri ölçen sensörlerle elde edilir.

## 4. Analog işaretin bilgisayara aktarılması: örnekleme

### 4.1 Birinci kısıt: hafıza

Hoca tahtaya bir $x(t)$ işareti, bir PC ve hafıza gözlerini temsil eden bir kutu çizdi (ekrandan, 00:25:00). Soru şuydu: bu işaret bir bilgisayar sistemine aktarılacaksa ne gerekir?

Burada "bilgisayar" (computer) kavramı geniş anlamda, hesaplama (computing) yapabilen her birimdir: masaüstü bilgisayar, cep telefonu ya da bir sensörden gelen bilgileri işleyip çıkış üreten bir gömülü sistem olabilir. Bu birimlerin hafızası vardır ve hafıza gözlerine değerler yazılır; burada yazılan, işaretin genlik değerleridir.

İlk kısıt hafızadır. İşaret 0 ile 1. saniye arasında bile sonsuz sayıda değer içerir. Örneğin 8 KB'lık bir hafızaya (tahtada "8KB", ekrandan, 00:30:00) bu sonsuz değerin hepsini yazmak mümkün değildir; hafıza gözleri hemen dolar. Dolayısıyla analog işaret olduğu gibi işlenemez; ondan **örnekler** alınmalıdır. Örneğin bir andaki değer 0,565 ise bu değer bir hafıza gözüne yazılır (tahtada ilk göze "0,565" yazıyor, ekrandan, 00:30:00).

### 4.2 Ayrıklaştırma ve örnekleme periyodu

İşaretin ayrık noktalara indirgenmesine **ayrıklaştırma** (discretization) denir. Hoca öğrencilere "ayrıklaştırma yapacağız; mühendis adayı olarak aklınıza gelen ilk soru ne?" diye sordu. Bir öğrencinin cevabı: "Hangi sıklıkta, hangi aralıkla?"

Zaman ekseninde belli aralıklarla örnek alma işlemine **örnekleme** (sampling) denir. İki örnek arasındaki süre $T_s$, yani **örnekleme periyodu**dur (tahtada "discretization", "sampling (örnekleme)", "Ts: örnekleme periyodu", ekrandan, 00:30:00). Örneğin:

- $T_s = 1$ s: saniyede bir örnek alınır.
- $T_s = 1$ ms: saniyede 1000 örnek alınır.

### 4.3 Sık ve seyrek örneklemenin avantaj ve dezavantajları

Hoca bu konuyu öğrencilerle soru-cevap biçiminde işledi.

**Soru:** $T_s$'yi küçük (sık) almanın avantajı ve dezavantajı nedir?
**Cevap:** Ne kadar sık örnek alınırsa orijinal işarete o kadar benzer, hata o kadar az olur; sık almanın bir alt limiti yoktur. Dezavantajı, daha çok örneğin bellekte daha çok yer tutmasıdır. Bilgisayar sistemlerinin belli bir hafıza kapasitesi vardır; 0 ile 1 saniye arası çok sayıda örnekle doldurulursa hafıza yetmez.

**Soru:** Seyrek almanın zararı ve yararı nedir?
**Cevap:** Seyrek alınırsa hata payı artar, arada önemli değişimler kaçırılabilir. Hoca kalp işaretini örnek verdi: filmlerde görülen kalp işaretinin küçük iniş çıkışları bile önemlidir; seyrek örnekleme bunları kaçırır. Yararı ise daha az bellek gerektirmesidir.

Hoca bir boyut daha ekledi: **işlem gücü ve güç tüketimi.** Aynı sayıda (ör. 1000) örnek bir işaretten kısa sürede, başka bir işaretten uzun sürede alınabilir; yani örnekleme periyodu farklı olabilir. Bilgisayarın birim zamanda hafızadan çekip işleyebileceği bilgi miktarı sınırlıdır. Tepe noktası bulma ya da değişim sezme gibi bir algoritma çalıştırılıyorsa, daha çok örnekle çalışmak hesaplama karmaşıklığını (computation complexity) arttırır. Hesaplama karmaşıklığının artması güç tüketiminin artması demektir. Hoca bunu bilgisayarın görev yöneticisindeki CPU kullanım grafiğiyle gösterdi: işlemci ne kadar zorlanırsa grafik o kadar yükselir, daha çok transistör çalışıp daha çok akım çeker (ekrandan, 00:35:00).

### 4.4 Örnekleme frekansı

İki örnek arasındaki süre $T_s$ (sampling period) ise **örnekleme frekansı** onun tersidir (ekrandan, 00:40:00):

$$F_s = \frac{1}{T_s}$$

Örnekleme periyodu daraldıkça daha sık örnek alınır; bu da daha yüksek örnekleme frekansı demektir.

### 4.5 Frekans kavramı

Hoca insan sesi örneğine geçti: konuşurken mikrofonda bir elektriksel işaret oluşur ve insan konuşması yaklaşık 0-4 kHz, yani 0-4000 Hz aralığındadır (tahtada "0 - 4000 Hz", ekrandan, 00:40:00).

**Soru:** 1 Hz frekansa sahip olmak ne demektir?
**Cevap:** Bir değişimin (bir çevrimin) 1 saniyede başlayıp bitmesi demektir. 2 Hz ise 1 saniyede 2 çevrimin tamamlanması demektir. 0 Hz ise değişim olmaması demektir (tahtada 1 ve 2 çevrimlik sinüs çizimleri, ekrandan, 00:40:00).

Hoca arada şu soruyu düşünmeyi istedi: örnekleme istenildiği kadar sık yapılabilir ama hafıza harcanır; çok seyrek yapılırsa önemli bilgi kaybolur. Olabildiğince seyrek örnekleyip yine de önemli değişimleri kaçırmamanın optimal bir yolu var mıdır?

## 5. Frekans, sinüzoidal bileşenler ve Fourier analizi

### 5.1 Fourier analizi

Bir işaret $x(t)$ biçiminde zamana bağlı bir işaret olarak ya da matematiksel bir fonksiyon (ör. polinom ifadesi) olarak yazılabilir (tahtada "$x(t) = x^7 + \frac{1}{2}x^6 \dots$" ve "Fourier Analizi", ekrandan, 00:55:00). Örnekleme periyodunu belirlemek için 1800'lü yılların başında yaşamış Fourier'nin analizinden yararlanılır.

Konuşma gibi işaretler belli bir matematiksel kurala göre değil, keyfi olarak değişir; bu yüzden bunlara keyfi işaret ya da keyfi fonksiyon denir. Fourier analizi basitçe şunu söyler: herhangi bir keyfi işaret aslında sinüzoidal bileşenlerin toplamından oluşur. Teorik olarak bu bileşenlerin frekansları 0'dan sonsuza kadar gider; yani işaret sonsuz sayıda sinüzoidal bileşenin toplamıyla elde edilebilir.

### 5.2 Sinüzoidal bir bileşenin özellikleri

Hoca bir sinüzoidal bileşenin tek bir çevrimini çizip hangi özelliklerle tanımlandığını sordu.

**Soru:** Sinüzoidal bir işaretin özellikleri nelerdir?
**Cevap:**

- **Periyot (ya da frekans):** $f = 1/T$ olduğundan sinüzoidal işaret tanımlanırken frekansından da söz edilir.
- **Genlik (amplitude):** İşaretin $+A$ ile $-A$ arasında salınması. Örneğin $\sin(t)$, $+1$ ile $-1$ arasında değer alır. (Bu özelliği bir öğrenci söyledi.)
- **Faz:** İşaret sıfır anında illa sıfırdan başlamak zorunda değildir; sıfır anındaki konumu fazdır.

Sinüs ve kosinüs aslında aynı sinüzoidal işarettir; aralarındaki tek fark faz farkıdır.

**Soru:** Sinüs ile kosinüs arasındaki faz farkı ne kadardır?
**Cevap:** 90 derece.

### 5.3 Bant sınırlı işaretler

Hoca keyfi bir işaretin 0 Hz, 10 Hz ve giderek yükselen frekanslardaki sinüzoidal bileşenlerin toplamı olarak yazılışını çizdi (tahtada "$f: 0 \to \infty$", ekrandan, 01:00:00). Teoride frekanslar sonsuza kadar gider; ama gerçek hayatta sonsuza gitmek söz konusu değildir. Örneğin konuşma işaretleri 0-4 kHz arasındadır; en yüksek frekans yaklaşık 4000 Hz'dir. Buna göre gerçek hayattaki işaretler **bant sınırlı**dır (band limited, tahtada "Bant limitli", ekrandan, 01:00:00): ulaşabilecekleri bir maksimum frekans vardır ve bunun üstündeki frekansları içermezler. Bazı insanlarda bu sınır 5 ya da 6 kHz'e çıkabilir (ör. sesi daha tiz olanlarda), ama 10 kHz'lik ses çıkarılmaz; kabaca ortalama 4 kHz alınır.

Dolayısıyla bir konuşma işareti için sensör tasarlanırken içinde en fazla 4 kHz bulunduğu bilinir. Bu maksimum frekansa $f_{max}$ denir.

## 6. Nyquist teoremi

### 6.1 En yüksek frekanslı bileşenin periyodu

En yüksek frekanslı bileşenin bir çevriminin süresi (tahtada "$T_{max} = 1/F_{max}$", ekrandan, 01:05:00):

$$T_{max} = \frac{1}{f_{max}}$$

Ses işareti için:

$$T_{max} = \frac{1}{4000\ \text{Hz}} = 250\ \mu s$$

Yani en yüksek frekanslı bileşen kendini 250 mikrosaniyede bir tekrar eder (tahtada "250 µsn", ekrandan, 01:05:00).

### 6.2 Örnekleme periyoduyla ilişki

Amaç, iki örnek arasındaki ve hiçbir önemli değişimi kaçırmayacak $T_s$'yi bulmaktır. Hoca en yüksek frekanslı bileşenin bir çevrimine yakından baktı. En azından bu bileşenin **tepe noktaları** (bir üst, bir alt tepe) örneklenmelidir. En yüksek frekanslı bileşenin tepe noktaları alındığında, daha düşük frekanslı bileşenlerin bir çevrimi içinde çok daha fazla örnek alınmış olur; onlar için durum daha iyidir. En kötü durum, en yüksek frekanslı bileşenin bir çevriminde yalnız iki örnek alınmasıdır.

**Soru:** Bu durumda $T_s$ ile $T_{max}$ arasındaki ilişki nedir?
**Cevap:** $T_{max} = 2T_s$. Çevrimin yarısı bir örnekleme periyoduna karşılık gelir.

Tepe noktalarının yanında aradaki sıfır geçişleri de alınırsa bir çevrimde 4 örnek alınır ve $T_{max} = 4T_s$ olur (tahtada "$T_{max} = 4T_s$", ekrandan, 01:10:00); bu daha iyi bir örneklemedir. En kötü durum $2T_s$ olduğuna göre genel koşul:

$$T_{max} \ge 2T_s$$

Frekans cinsinden ($F_s = 1/T_s$, $f_{max} = 1/T_{max}$):

$$F_s \ge 2 f_{max}$$

Buna **Nyquist teoremi** denir (tahtada "Nyquist Teoremi, $F_s \ge 2F_{max}$", ekrandan, 01:10:00). Teorem şunu söyler: bir işareti örneklemek için, işaretin içerdiği maksimum frekansın en az iki katı bir örnekleme frekansı kullanılmalıdır. $f_{max}$ biliniyorsa $F_s$ bulunur, $F_s$'den de $T_s = 1/F_s$ hesaplanır. Böylece başta sorulan "örnekleme periyodu nasıl seçilir" sorusu Fourier analizi üzerinden cevaplanmış olur.

> **Ders sonrası not:** Ekranda bir yerde koşul "$T_s \ge 2F_{max}$" diye yazılmış (ekrandan, 01:15:00). Doğrusu $F_s \ge 2f_{max}$'tır; $T_s$ periyot olduğu için koşul $T_s \le T_{max}/2$ biçimindedir.

### 6.3 Sayısal örnek: mikrofon kaydı

Hoca bir öğrenciye şu soruyu sordu: ortam seslerini (en fazla konuşma seslerini) kaydedecek bir mikrofon ve kaydedici tasarlanıyor; konuşma 0-4 kHz arasındadır. Kaydedicinin örnekleme frekansı ne olmalıdır?

- Verilen: $f_{max} = 4$ kHz.
- Nyquist: $F_s \ge 2 f_{max} = 2 \cdot 4 = 8$ kHz.
- Örnekleme periyodu: $T_s = \dfrac{1}{8000\ \text{Hz}} = 125\ \mu s$ (tahtada "$F_s = 8$ kHz, $T_s = 125\ \mu$sn", ekrandan, 01:10:00).
- Yorum: 125 mikrosaniyede bir örnek alınır; yani 0 ile 1. saniye arasında 8000 örnek alınır. Mikrosaniye $10^{-6}$ saniyedir.

Öğrenci 8 kHz cevabını verdi; hoca "en az" iki katı olması gerektiğini vurguladı.

**Soru:** $F_s$ 8 kHz yerine 16 kHz seçilse daha iyi olmaz mı?
**Cevap:** Evet, daha ayrıntılı olur. $F_s$, $f_{max}$'ın en az iki katı olmak zorundadır; bu bir alt sınırdır, üst sınırı yoktur. 16, 32, 64 kHz de seçilebilir. En düşük değer 8 kHz'dir.

> **Hocanın vurgusu:** $F_s \ge 2f_{max}$ koşulunda alt sınır vardır, üst sınır yoktur.

### 6.4 Kalite ve dosya boyutu

Hoca bu bilginin günlük hayattaki karşılığını ses dosyalarıyla anlattı: bazı ses dosyalarının bilgisinde 32, 64 ya da 128 gibi değerler yazar. Örnekleme frekansı yükseldikçe, yani saniyede alınan örnek sayısı arttıkça ses kalitesi artar; ama daha çok örnek daha büyük dosya demektir. Düşük örnekleme frekansıyla kaydedilen dosyada kaliteden ödün verilir, dosya boyutu küçülür.

> **Ders sonrası not:** Hoca MP3 dosyalarında "32, 64, 128 kHz'de örneklenmiştir" bilgisinin yazdığını söyledi. MP3 dosyalarında görülen 64, 128 gibi değerler büyük olasılıkla bit hızıdır (kbps); tipik örnekleme frekansları ise 32, 44,1 ve 48 kHz'dir. Kalite-dosya boyutu ilişkisi her iki büyüklük için de geçerlidir.

### 6.5 Neden önemli değişimler kaçırılmaz?

Örnekler $T_s$, $2T_s$, $3T_s$, $4T_s$ anlarında alınır (ekrandan, 01:15:00). Aradaki bazı anlar alınmaz, ama önemli değişimler kaçırılmaz. Çünkü işaretteki hızlı değişimler en yüksek frekanslı bileşenlerden oluşur ve bu bileşenlerin her çevriminde en az bir üst, bir alt nokta alınmaktadır. Elde edilen örnekler yüzde yüz orijinal işaret değildir, ama $F_s \ge 2f_{max}$ ile değişimler yakalanmış olur.

## 7. Nicemleme (quantization)

### 7.1 Örnekler doğrudan hafızaya yazılabilir mi?

İşaret artık zaman ekseninde ayrıklaştırılmıştır. Hoca sordu: bu örnekler sırasıyla hafıza gözlerine atılabilir mi?

**Soru:** Ayrıklaştırılmış örnekleri sırasıyla hafızanın içine atabilir miyiz?
**Cevap:** İlk cevap "atabiliriz" oldu. Başka bir öğrenci itiraz etti: "Önce genlik sınırı belirlememiz gerekmez mi? Şu an zamanı ayrıklaştırdık ama genliği ayrıklaştırmadık." Hoca bu cevabı doğruladı.

Bir örnek 0,565 değerini alabilir, hemen yanındaki örnek (125 µs sonra) ise 0,5654321098765... gibi virgülden sonra sonsuza giden bir değer alabilir (tahtada "0,56543210987 6 5...", ekrandan, 01:20:00). Genlik de süreklidir; belli değerlerle sınırlandırılmadıkça istenen her değeri alabilir. Oysa hafıza gözleri bitlerden oluşur.

### 7.2 Bit sayısı ve seviye sayısı

- **1 bit:** Yalnız 0 ve 1 saklanabilir. Bu durumda yalnız işaretin bir referans çizgisinin (sıfırın) üstünde mi altında mı olduğu bilinir. Hoca 0'ı pozitif, 1'i negatif bölge olarak düşündü.
- **2 bit:** 00, 01, 10, 11 olmak üzere 4 durum vardır; genlik aralığı 4 bölgeye ayrılır (tahtada bölgeler ve 00, 01, 10, 11 listesi, ekrandan, 01:20:00). Hassasiyet artar.
- **3 bit:** 000, 001, 010, 011, 100, 101, 110, 111 olmak üzere 8 durum vardır. Önceden aynı bölgede kalan iki örnek (hocanın A ve B örnekleri) artık birbirinden ayrılabilir. İlk bit 0 olduğunda pozitif bölgeyi gösterir.
- **8 bit:** $2^8 = 256$ seviye vardır.

Genel olarak $n$ bit ile $2^n$ seviye ifade edilir.

> **Ders sonrası not:** Hoca 8 bit örneğinde önce "258, 256, 128 ... 127 tane 0 bölgesinde, 128 tane negatif bölgede" dedi. Doğrusu: 8 bit ile toplam 256 seviye vardır; ilk bit işaret için kullanılırsa 128 seviye sıfır dahil pozitif bölgeye, 128 seviye negatif bölgeye düşer.

### 7.3 Gerilim aralığının bölünmesi

Seviyeler belli bir fiziksel birimdedir, örneğin volt. İşaret 0 ile 5 V arasında değer alıyorsa ve 8 bitin 128 seviyesi bu aralığa ayrılırsa, her seviye $5/128$ V genişliğindedir. İşaret $-5$ V ile $+5$ V arasındaysa 10 V'luk aralık 256 seviyeye bölünür:

$$\Delta = \frac{10\ \text{V}}{256} \approx 0{,}039\ \text{V} \approx 39\ \text{mV} \quad \text{(ara adım eklendi)}$$

Bit sayısı arttırıldıkça seviyeler daralır ve aralıklar daha hassas belirlenir.

### 7.4 Nicemleme hatası

Hoca yeni bir sayfada büyük bir işaret çizdi (tahtada "Nicemleme / Quantization", seviyeler ve 00000001, 00000000 gibi kodlar, ekrandan, 01:25:00). Aynı nicemleme aralığına (kuanta) düşen iki örnek aynı değeri alır, aralarındaki fark kaybolur. Bit sayısı arttırılınca araya yeni seviyeler girer ve bu örnekler ayrışır. Bir kuanta aralığının içindeki fark, kullanılan bit sayısının belirlediği bir hatadır.

Bu işleme **nicemleme** (quantization) denir. Özetle:

- $t$ ekseninde yapılan ayrıklaştırma: **örnekleme** (sampling).
- $x(t)$ ekseninde yapılan ayrıklaştırma: **nicemleme** (quantization).

Bir analog işaretin sayısallaştırılması için iki eksenin de ayrıklaştırılması gerekir. Her örneğin nicemlenmiş değeri bir bit dizisi olarak (ör. 8 bitlik bir kod) hafıza gözüne yazılır. Bu kodun hangi gerilime karşılık geldiğini bilmek için işaretin ulaşabileceği maksimum genlik (ör. ±5 V) ve seviye sayısı bilinmelidir.

### 7.5 Hafıza gösterimi

Hafızalar "hücre sayısı × hücre genişliği" biçiminde gösterilir. Örneğin $1\text{K} \times 8$ bit: 1K = 1024 hücre vardır ve her hücre (kelime, word) 8 bittir. Yani 1024 tane 8 bitlik değer tutulabilir. Hücre genişliği 16 bit olursa nicemleme seviyeleri daralır ve genlik hassasiyeti artar. (Hoca önce "1 kilohertz" deyip "1 kilobyte" diye düzeltti.)

## 8. Temel lojik kapılar: AND ve OR

Sayısallaştırma ile elde edilen 1 ve 0'lar üzerinde işlem yapabilecek elemanlar lojik devreler dersinde tasarlanacaktır. Hoca iki temel kapıyı tanıttı (ekrandan, 01:30:00).

**AND (VE) kapısı:** $p$ ve $q$ değişkenlerinin ikisi de 1 (olumlu) olduğunda çıkış 1'dir; diğer durumlarda çıkış 0'dır. İki değişken $2^2 = 4$ farklı değer kombinasyonu alabilir:

| $p$ | $q$ | $f = p \cdot q$ |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

**OR (VEYA) kapısı:** İki önermeden birinin doğru olması çıkışın 1 olması için yeterlidir:

| $p$ | $q$ | $f = p + q$ |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 1 |

(AND tablosu ekrandan alınmıştır; OR tablosu ekranda yalnız başlatılmış, satırları sözlü anlatımdan ve sonraki karede görülen değerlerden kurulmuştur, ekrandan, 01:35:00.)

## 9. Sayı sistemlerine giriş

Sonraki derste önce sayı sistemleri, ardından Boole cebri işlenecektir. Hoca buna kısa bir giriş yaptı.

Hafıza gözündeki her 0 ya da 1'e **bit** denir. 8 bitten oluşan yapıya **byte**, 4 bitten oluşan yapıya **nibble** denir; byte'ın üst ve alt nibble'ı vardır (ekrandan, 01:35:00).

Onluk sistemde basamak ağırlıkları $10^0$ (birler), $10^1$ (onlar), ... biçimindedir; örneğin 21 sayısında 1 birler, 2 onlar basamağındadır. İkilik sistemde ağırlıklar $2^0 = 1$, $2^1 = 2$, $2^2 = 4$, $2^3 = 8$, $2^4 = 16$, $2^5 = 32$, $2^6 = 64$, $2^7 = 128$'dir.

**Örnek:** Hafıza gözündeki 01100101 değerinin onluk ve onaltılık karşılığı (ekrandan, 01:35:00):

- 1 olan basamaklar: $2^6$, $2^5$, $2^2$, $2^0$.
- Onluk değer: $64 + 32 + 4 + 1 = 101$.
- Onaltılık değer: byte iki nibble'a ayrılır; üst nibble $0110 = 6$, alt nibble $0101 = 5$, sonuç $65$.

$$(01100101)_2 = (101)_{10} = (65)_{16}$$

Hafıza gözünün içeriği değişmez; değişen yalnız gösterim biçimidir. Hoca seçilen onluk sayının tesadüfen yalnız 0 ve 1 rakamlarından oluştuğunu, onluk sistemde 0-9 arası rakamların kullanılabileceğini hatırlattı.

Rakam sayısı tabana eşittir: onluk sistemde 10 rakam, ikilik sistemde 2 rakam (0 ve 1), onaltılık (hexadecimal) sistemde 16 rakam vardır. Onaltılıkta 0-9 rakamlarına ek olarak A, B, C, D, E ve F de rakam olarak kullanılır.

## 10. Fourier gösterimi, DC ve AC bileşenler

### 10.1 Fourier teoreminin integral biçimi

Ders sonunda bir öğrenci Fourier teoremini kısaca teorik olarak anlatmasını istedi. Hoca şu ifadeyi yazdı (ekrandan, 01:40:00):

$$x(t) = \int_0^{\infty} A_f \sin(\omega t)\, df, \qquad \omega = 2\pi f$$

$$x(t) = \int_0^{\infty} A_f \sin(2\pi f t)\, df$$

Burada $A_f$, $f$ frekansına ait genliktir ve değişken $f$'dir. Yani 0'dan sonsuza giden bütün frekanslardaki sinüzoidal işaretler farklı genliklere sahip olabilir. Daha basit söylenirse: işaret $f = 0$ bileşeni, artı $f = 10$ Hz bileşeni ($A_{10}$ genlikli), artı $f = 100$ Hz bileşeni ($A_{100}$ genlikli), artı $f = 1000$ Hz bileşeni, ... gibi sonsuz sayıda bileşenin toplamıdır; bu bileşenler toplandığında işaret teorik olarak elde edilir (ekrandan, 01:45:00).

Bir işarette her frekans bulunmak zorunda değildir: örneğin 101,372 Hz'lik bir bileşen yoksa ona karşılık gelen $A_f$ sıfırdır.

> **Ders sonrası not:** Tahtadaki ifade sezgi için sadeleştirilmiştir. Tam Fourier gösteriminde her bileşenin fazı da yer alır; büyük olasılıkla $\sin(2\pi f t + \phi_f)$ ya da sinüs ve kosinüs terimleri birlikte yazılır. Fazın bir bileşen özelliği olduğu derste 5.2'de anlatılmıştı.

### 10.2 DC ve AC bileşen

$f = 0$ bileşenine **DC bileşen** denir: değişim içermez. Diğer bütün bileşenler salınım yaptığı için **AC bileşen**dir (ekrandan, 01:45:00).

- **DC = Direct Current** (doğru akım).
- **AC = Alternating Current** (alternatif akım).

Hoca bu kavramları elektrikten örnekledi. 1,5 V'luk bir pilin uçlarına voltmetre ya da osiloskop bağlanırsa daima 1,5 V görülür: sabit, salınım yapmayan bir işaret. Duvardaki prize bağlanırsa salınım yapan bir işaret görülür.

**Soru:** Şehir şebekesinin frekansı nedir?
**Cevap:** 50 Hz; yani bir saniyede bu çevrim 50 kez tamamlanır.

**Soru:** Şehir şebekesinin genliği nedir?
**Cevap:** 220 V.

> **Ders sonrası not:** Derste şebeke geriliminin "±220 V arasında" salındığı söylendi. 220 V etkin (RMS) değerdir; tepe değeri büyük olasılıkla $220\sqrt{2} \approx 311$ V'tur.

Hoca, belgesellerden bilinen tartışmaya değindi: Tesla şebekeye AC göndermeyi, Edison ise sabit (DC) gerilim göndermeyi düşünüyordu. Elektrik teller üzerinden iletilir. Bir pilin artı ve eksi uçları bir telle birleştirilirse tel ısınır; çünkü tel bir direnç gösterir ve tel uzadıkça direnci artar. DC ile iletimde sürekli güç yüklemesi olur; işaretin altında kalan alan sürekli pozitiftir. AC işarette ise pozitif ve negatif alanlar birbirini götürür; ortalama sıfıra yaklaşır. Bir işaretin ortalaması onun DC bileşenini verir: 1,5 V'luk pilin ortalaması 1,5 V'tur.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:28:13): Bir analog işaret ayrıklaştırılacaksa mühendis olarak akla gelen ilk soru nedir?

> **Çözüm:** Örneklerin hangi sıklıkta (hangi aralıkla) alınacağı, yani örnekleme periyodu $T_s$'nin ne olacağı.

**Soru 2** (derste sözlü, 00:30:22): Örnekleme periyodunu dar (sık) ya da geniş (seyrek) almanın avantaj ve dezavantajları nelerdir?

> **Çözüm:** Sık örnekleme orijinal işarete daha çok benzer, hata azdır; ama daha çok bellek, daha çok işlem ve daha çok güç tüketimi gerektirir. Seyrek örnekleme daha az bellek ve işlem gerektirir; ama işaretteki önemli, hızlı değişimler kaçırılabilir.

**Soru 3** (derste sözlü, 00:38:05): 1 Hz frekansa sahip olmak ne demektir?

> **Çözüm:** Bir çevrimin 1 saniyede başlayıp bitmesi demektir. 2 Hz, saniyede 2 çevrim; 0 Hz ise değişim olmaması demektir.

**Soru 4** (derste sözlü, 00:55:24): Sinüzoidal bir bileşen hangi özelliklerle tanımlanır? Sinüs ile kosinüs arasındaki fark nedir?

> **Çözüm:** Periyot (frekans), genlik ve faz. Sinüs ve kosinüs aynı işarettir; aralarında 90°'lik faz farkı vardır.

**Soru 5** (derste sözlü, 01:04:28; ekrandan, 01:10:00): En yüksek frekanslı bileşenin bir çevriminde yalnız tepe noktaları örneklenirse $T_s$ ile $T_{max}$ arasındaki ilişki nedir? Bir çevrimde 4 örnek alınırsa ne olur?

> **Çözüm:** Yalnız tepe noktaları alınırsa $T_{max} = 2T_s$ (en kötü durum). 4 örnek alınırsa $T_{max} = 4T_s$. Genel koşul $T_{max} \ge 2T_s$, yani $F_s \ge 2f_{max}$.

**Soru 6** (derste sözlü, 01:07:40; ekrandan, 01:10:00): Ortam seslerini (en fazla konuşma seslerini, 0-4 kHz) kaydedecek bir mikrofon ve kaydedici tasarlanıyor. Örnekleme frekansı ve örnekleme periyodu en az/en çok ne olmalıdır?

> **Çözüm:** $F_s \ge 2 \cdot 4\ \text{kHz} = 8$ kHz. $T_s = 1/8000 = 125\ \mu s$ (en fazla). Saniyede en az 8000 örnek alınır. 16, 32, 64 kHz de seçilebilir; üst sınır yoktur.

**Soru 7** (derste sözlü, 01:15:44): Zaman ekseninde ayrıklaştırılmış örnekler sırasıyla hafıza gözlerine doğrudan yazılabilir mi?

> **Çözüm:** Hayır. Genlik hâlâ süreklidir ve sonsuz basamaklı değerler alabilir; hafıza gözleri sınırlı sayıda bitten oluşur. Genlik de ayrıklaştırılmalıdır (nicemleme).

**Soru 8** (derste sözlü, 01:19:21; ekrandan, 01:20:00): 2 bitlik ve 3 bitlik bir hafıza gözüyle kaç farklı genlik durumu ifade edilir?

> **Çözüm:** 2 bit: $2^2 = 4$ durum (00, 01, 10, 11). 3 bit: $2^3 = 8$ durum (000 ... 111). Genel olarak $n$ bit ile $2^n$ durum.

**Soru 9** (ekrandan, 01:35:00): $(01100101)_2$ sayısının onluk ve onaltılık karşılığı nedir?

> **Çözüm:** $64 + 32 + 4 + 1 = 101$, yani $(101)_{10}$. Nibble'lar $0110 = 6$ ve $0101 = 5$ olduğundan $(65)_{16}$.

**Soru 10** (derste sözlü, 01:41:53): Şehir şebekesinin frekansı ve genliği nedir?

> **Çözüm:** Frekans 50 Hz. Derste genlik 220 V olarak cevaplandı; 220 V etkin değerdir, tepe değeri büyük olasılıkla yaklaşık 311 V'tur (derste verilmedi).

**Soru 11** (derste sözlü, 01:43:51): Bir pilin artı ve eksi uçları bir telle birleştirilirse tel ne olur?

> **Çözüm:** Tel ısınır; çünkü telin bir direnci vardır ve üzerinden geçen akım güç harcar. Tel uzadıkça direnci artar.

## Dersin Toparlaması

Bu ilk derste lojik devrelerin neden gerekli olduğu, analog dünyadan sayısal dünyaya geçiş üzerinden anlatıldı. Analog işaret hem zaman hem genlik ekseninde sonsuz değer içerdiği için sınırlı hafızası ve işlem gücü olan bir bilgisayarda doğrudan işlenemez. Zaman ekseni örnekleme ile, genlik ekseni nicemleme ile ayrıklaştırılır. Örnekleme periyodu Fourier analizinden yola çıkılarak Nyquist teoremiyle seçilir: gerçek işaretler bant sınırlıdır ve en yüksek frekanslı bileşenin her çevriminde en az iki örnek alınırsa ($F_s \ge 2f_{max}$) önemli değişimler kaçırılmaz. Nicemlemede kullanılan bit sayısı $n$ ise $2^n$ seviye belirler ve genlik hassasiyetini, dolayısıyla nicemleme hatasını belirler.

Böylece elde edilen 1 ve 0'lar üzerinde işlem yapan elemanlar lojik kapılardır; AND ve OR kapıları ilk örnekler olarak tanıtıldı. Aynı hafıza içeriğinin ikilik, onluk ve onaltılık tabanda farklı biçimlerde gösterilebildiği görüldü. Bir sonraki derste sayı sistemleri ayrıntılı işlenecek, ardından Boole cebrine geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
