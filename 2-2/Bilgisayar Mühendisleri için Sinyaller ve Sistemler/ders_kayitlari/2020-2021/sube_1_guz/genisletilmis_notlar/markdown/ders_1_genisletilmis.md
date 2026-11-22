# Ders 1 Genişletilmiş Notu: Derse Giriş, Araçlar ve İşaret Kavramı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yeri ve Amacı
- 2. Dersin Konu Akışı
- 3. Kullanılacak Araçlar: MATLAB ve Python
- 4. Kaynak Kitaplar
- 5. Dış Dünyadan Bilgisayara: İşaret Nedir?
- 6. İşaretlerin Boyutları
- 7. Sürekli ve Ayrık İşaretler
- 8. Örnekleme: Sürekli İşaretten Sayısal İşarete
- Örnek Sorular

## 1. Dersin Yeri ve Amacı

Bu ilk ders bir tanışma ve giriş dersiydi. Hoca dersi, sayısal işaret işlemeden (DSP, Digital Signal Processing) önceki işin temellerini anlatan, biraz daha matematiğiyle ilgilenen temel bir ders olarak tanıttı. Dersin adı müfredatta "Bilgisayar Mühendisleri için Sinyaller ve Sistemler" olarak geçse de hoca "İşaret ve Sistemler" ifadesini de kullandı; "işaret" ile "sinyal" aynı anlamdadır.

Ders büyük ölçüde sayısal işaret işlemeyle örtüşür, ama DSP dersi kadar yoğun değildir. Hoca dersi öğrencileri uzun uzun matematiğe boğmadan, temel kavramları vererek ilerleteceğini söyledi. Bu dersin matematiksel temelleri ayrık işaretler ve ayrıklaştırma kavramları üzerinden kurulur. Özellikle görüntü işleme, makine öğrenmesi ve derin öğrenme gibi alanlara yönelecekler için bu temel önemlidir. Dersin sonunda dış dünya işaretlerinin matematiksel gösterimi hakkında bilgi sahibi olunması ve gerçek hayat problemlerinde kullanılacak sinyal işleme, görüntü işleme, makine öğrenmesi ve derin öğrenme için bir altyapı kurulması hedeflenir.

> **Hocanın vurgusu:** Ders eklemeli (birikimli) ilerler. Dersler takip edilirse rahat ilerlenir; arada bir iki hafta kaçırılırsa tekrar toparlamak zor olur.

## 2. Dersin Konu Akışı

Hoca ekranda dersin tanıtım slaytlarını (syllabus) açarak konu başlıklarını tek tek anlattı. İlk konular altyazıdan, 4. konudan sonrası slayttan alınmıştır (ekrandan, 00:15:00):

- 1-3. İşaretlerin matematiksel gösterimi, sinüzoitler ve spektrum gösterimi. Burada sinüs kavramı ve bütün işaretlerin sinüslerin toplamı biçiminde nasıl ifade edildiği görülür. Spektrum analizinde Fourier analizine girilir; işaretler zaman domeninin yanında frekans domeninde de incelenir.
- 4. Örnekleme ve örtüşme (Sampling and Aliasing): örnekleme, spektrum görünümü, yeniden oluşturma (reconstruction), ayrıktan sürekliye dönüşüm, örnekleme teoremi.
- 5. Sürekli zamanlı LTI sistemler ve konvolüsyon integrali: genel giriş-çıkış ilişkisinin kurulması, konvolüsyon integraliyle çalışma.
- 6. Ayrık zamanlı LTI sistemler ve konvolüsyon toplamı: giriş-çıkış ilişkisinin ayrık duruma özelleştirilmesi, konvolüsyon toplamıyla çalışma.
- 7. LTI sistemlerin zaman domeninde diferansiyel ve fark denklemleri: sistemlerin giriş-çıkış ilişkileri için diferansiyel ve fark denklemlerinin elde edilmesi ve zaman domeninde çözülmesi.
- 8. Sürekli zamanlı işaret ve sistemler için Fourier dönüşümü: sürekli zamanlı periyodik olmayan işaretler, sürekli zamanlı Fourier dönüşümü ve özellikleri.
- 9. Ayrık zamanlı işaretler için ayrık zamanlı Fourier dönüşümü (DTFT): ayrık zamanlı periyodik olmayan işaretler, DTFT ve özellikleri.
- 10. Sürekli zaman için Laplace dönüşümü: yaygın Laplace dönüşümleri, özellikleri, ters Laplace dönüşümü, s-düzleminde kutuplar ve sıfırlar.
- 11. Ayrık zaman için Z dönüşümü: yaygın Z dönüşümleri, özellikleri, ters Z dönüşümü, z-düzleminde kutuplar ve sıfırlar.

Hoca konuşurken LTI kısaltmasını "lineer zamanla değişmeyen sistemler" diye açtı. Fourier dönüşümünün ve ayrık Fourier dönüşümünün bulunduğu 8-9. konulardan itibaren sayısal işaret işlemeye girildiğini, 10. ve 11. konularda ise dönüşüm yöntemleri olan Laplace ve Z dönüşümlerinin işlendiğini söyledi.

> **Ek bilgi (derste anlatılmadı):** LTI, "Linear Time-Invariant" (doğrusal ve zamanla değişmeyen) sistem demektir. Böyle bir sistemin çıkışı, girişin sistemin dürtü yanıtıyla konvolüsyonu olarak yazılabilir; sürekli zamanda bu konvolüsyon integrali, ayrık zamanda konvolüsyon toplamıdır. Bu yüzden ders planında LTI sistemler ile konvolüsyon aynı başlık altında yer alır.

## 3. Kullanılacak Araçlar: MATLAB ve Python

### 3.1 Neden MATLAB ve Python?

Ders kapsamında temel olarak MATLAB ve Python kullanılacak. Octave, Scilab ve R gibi başka ortamlar da vardır, ama hoca geleceğe hazırlık açısından özellikle MATLAB ve Python'u bilmenin yararlı olacağını söyledi. Üniversitenin MATLAB lisansı vardır; MATLAB'in tarayıcıdan, program kurmadan çalışan çevrim içi sürümü (MATLAB Online) de bulunur. Python, R, Scilab ve Octave ise ücretsizdir.

Hoca bunlar arasında en iyi script dilinin Python olduğunu düşündüğünü ve onu tavsiye ettiğini söyledi; Python derin öğrenme, makine öğrenmesi ve görüntü işleme alanlarında öne çıkmıştır. Derslerde daha çok MATLAB arayüzü kullanılacak, çünkü MATLAB şimdilik daha bilindiktir; ödevlerde ise MATLAB ya da Python seçimi tamamen öğrenciye bırakıldı.

### 3.2 Script dil ile derlenen dil

Hoca iki dil türünü karşılaştırdı. C gibi derlenen (compiled) bir dilde önce başlık (header) dosyaları yazılır, gerekli değişkenler tanımlanır, fonksiyonlar yazılır; program bir bütün olarak adım adım kurulur. MATLAB ve Python gibi script dillerde ise örneğin `a = 5` yazıldığında `a`'ya doğrudan 5 atanır; ardından `a*2` gibi bir ifade yazıldığında sonuç hemen bir sonraki satırda görülür. Özel bir tanımlama gerekmez, komutlar tek tek işletilerek ilerlenir. Döngülerin nasıl yazıldığı gibi konulara sonraki derslerde değinileceği söylendi.

### 3.3 MATLAB arayüzü

Slaytta eski bir MATLAB sürümünün (R2009a) ekran görüntüsü üzerinde arayüzün bölümleri işaretlenmişti (ekrandan, 00:20:00):

- Menü çubuğu (Menubar) ve araç çubuğu (Toolbar).
- Geçerli çalışma dizini (Current Working Directory) ve bu dizinin içeriği (Current Directory Contents), altında dosya ayrıntıları (File Details).
- Komut penceresi (Command Window): komutların yazıldığı ve sonuçların görüldüğü yer. Başındaki `fx` simgesi fonksiyon kataloğunu (Function Catalog) açar.
- Çalışma alanı (Workspace): tanımlanmış değişkenlerin listesi (ad, değer, en küçük, en büyük).
- Komut geçmişi (Command History).
- Yardım (Help) menüsü ve başlangıç için "Getting Started" bağlantısı.

Hoca slaytlarda Scilab ortamının da gösterildiğini, Scilab'ın MATLAB'in daha basit bir benzeri olduğunu, R'nin daha çok istatistik için kullanıldığını söyledi. Python için Anaconda dağıtımını ve onunla gelen Spyder geliştirme ortamını tavsiye etti; Anaconda birçok aracı bir arada toplar ve kütüphanelerle istenen her şey rahatça yapılabilir.

### 3.4 Öğrenme önerisi

Hoca ekranda YouTube'da "how to use MATLAB" araması yaparak (ekrandan, 00:30:00) başlangıç seviyesinde birçok MATLAB eğitim videosu bulunduğunu gösterdi. 30-50 dakikalık bir tanıtım videosu izlenirse MATLAB'de rahatça çalışmaya başlanabileceğini söyledi.

## 4. Kaynak Kitaplar

Dersin temel kitabı **Signal Processing First**'tür; ders slaytlarının temel kısmı bu kitaptan alınmıştır. Yardımcı kaynak olarak **Signals and Systems for Dummies** ve çeşitli **Signals and Systems** kitapları anıldı. Ders çok temel bir ders olduğu için bu konuda yazılmış çok sayıda kitap vardır ve hepsinden yararlanılabilir. Çevrim içi kitap olarak da Richard Baraniuk'un Signals and Systems kitabı önerildi. <!-- BELİRSİZ: altyazıda yazar adı "Richard Briney" diye geçiyor; büyük olasılıkla Richard Baraniuk kastedildi. -->

Hoca, slaytlar üzerine not alarak dersi takip edenlerin dersi rahatlıkla götürebileceğini söyledi. Soru çözümlerinde zaman zaman Microsoft Whiteboard uygulamasına geçileceği, orada $x(t)$, $e^{j\omega}$ gibi ifadelerle çözümlerin yapılacağı belirtildi.

## 5. Dış Dünyadan Bilgisayara: İşaret Nedir?

Hoca dersin geri kalanında, bu derste ne öğrenileceğini beyaz tahtada bir resimle anlattı. Bir yanda dış dünya (bir dünya çizimi), öbür yanda bir bilgisayar vardır. Temel problem, dış dünyadaki verileri bilgisayar ortamında işlemektir (ekrandan, 00:40:00).

Dış dünya verilerine örnek olarak bir yerin sıcaklığı ya da bir kimyasaldaki asitlik oranı verildi. Bu büyüklükler zamanla değişir. Zamana $t$, büyüklüğe $x(t)$ denir. Bir başka örnek: bir vanadan bir kaba su akıyor, ama kap delik; arada kabın delikleri kapatılıyor, su miktarı artıyor ya da azalıyor. Bütün bu durumlarda sonuçta bir matematiksel fonksiyon oluşur: $x$ fonksiyonu $t$'ye göre değişir. Bunlara **bir boyutlu (1B) işaretler** denir.

Böyle bir işaret bilgisayara aktarılmak istendiğinde, değerler bir dizinin gözlerine yazılır. Tahtada 1B işaretin altına gözlere ayrılmış bir dizi çizildi (ekrandan, 00:40:00).

## 6. İşaretlerin Boyutları

### 6.1 İki boyutlu işaretler

İşaret yalnız $t$'ye değil, iki değişkene bağlı olabilir. Bu durumda $u$ ve $v$ eksenlerinin ikisinden de değer alan bir işaret $x(u,v)$ biçiminde yazılır. Tahtada bunun için $u$-$v$ düzleminde bir ızgara çizildi ve "2D işaret" diye etiketlendi (ekrandan, 00:40:00 ve 00:45:00). En tanıdık örnek fotoğraflardır.

### 6.2 Üç boyutlu işaretler

Hoca üç boyutlu işarete örnek istedi ve ipucu olarak sağlık alanında çok kullanıldığını söyledi. Cevap MR ve tomografi görüntüleriydi. Yatan bir hasta sırayla taranır: önce ayak tabanından bir kesit alınır, üzerine bir katman daha, bir katman daha eklenir. Böylece en, boy ve yükseklik olmak üzere birinci, ikinci ve üçüncü boyut oluşur. Öğrencilerden LIDAR ve RGB-D örnekleri de geldi; hoca bunların da üç boyutlu işaret olduğunu, bilgisayarlı tomografinin de doğru bir örnek olduğunu söyledi. Bu tür işaretler uzaktan algılamada ve biyomedikalde de kullanılır.

### 6.3 Renkli fotoğraf ve RGB

Bir renkli fotoğraf R (kırmızı), G (yeşil) ve B (mavi) olmak üzere üç katmandan oluşur. Bir pikselin her katmandaki değeri örneğin 0 ile 255 arasında verilmiş olsun. Piksel tamamen kırmızıdan oluşuyor, yeşil ve mavi bileşeni yoksa yalnız R değeri yüksektir (örneğin 200). Tahtada R, G, B eksenleriyle bir renk uzayı çizildi: kırmızılar bir eksende, yeşiller bir başka eksende toplanır; yeşil ile kırmızının arasında sarı renkler oluşur (ekrandan, 00:45:00).

### 6.4 n boyutlu işaretler

Kartezyen koordinatlar üç boyutta çizilebilir, ama matematikte sınır yoktur: 4 boyutlu, 5 boyutlu, hiper boyutlu, genel olarak **n boyutlu (n-dimensional)** işaretler düşünülebilir. Hoca bu kısmın makine öğrenmesine de biraz ipucu verdiğini söyledi. Bu derste bu kadar derine gidilmeyecek; anlatım daha çok bir boyutlu işaretler üzerinden yapılacak ve oradan hepsine genelleştirilebilecek bir anlatım tarzı izlenecek.

> **Ek bilgi (derste anlatılmadı):** Makine öğrenmesinde her örnek çoğunlukla bir öznitelik vektörüyle temsil edilir; $n$ öznitelik varsa her örnek $n$ boyutlu uzayda bir noktadır. Hocanın $n$ boyutlu işaretlerin makine öğrenmesine ipucu verdiğini söylemesi büyük olasılıkla bu bağlantıyı kastediyordu.

## 7. Sürekli ve Ayrık İşaretler

Tahtada iki kavram ayrıldı: **sürekli (continuous)** ve **ayrık (discrete)** işaretler (ekrandan, 00:40:00).

Bir yerin sıcaklığı ölçülüyorsa ölçümlerin arasında hiç boşluk yoktur; $t$ süreklidir ve işaret sürekli bir fonksiyondur. Fotoğraf için de bugünkü telefonlar ve sayısal fotoğraf makineleri değil, eski sistem düşünülmelidir. Eski makinede içeride bir fotoğraf filmi vardır, ışık gelir ve görüntü filme düşer. Burada piksel kavramı, yani tek tek noktalar yoktur; kimyasal filmin her yerinde renkler ve şekiller oluşur. Bu da sürekli bir iki boyutlu işarettir.

Asıl sorun, sürekli işaretten bilgisayara geçmektir; bu bir, iki ya da üç boyutlu işaretlerin hepsi için geçerlidir.

## 8. Örnekleme: Sürekli İşaretten Sayısal İşarete

### 8.1 Sürekli işaret neden olduğu gibi saklanamaz?

Hoca tahtada bir boyutlu sürekli bir işaret çizdi ve 3. saniye ile 4. saniye arasındaki kısmın bilgisayara nasıl atılacağını sordu (ekrandan, 00:45:00 ve 00:50:00). Öğrencilerden "dijitalize ederiz" cevabı geldi; demek ki bir sayısallaştırma kavramından söz etmek gerekir.

Sürekli bir işaretin neden doğrudan bilgisayara atılamayacağı şöyle gösterildi. 3. saniyedeki değer okunur ve bir dizi elemanına yazılır; bu değer $a$ olsun. Ardından 3,0001. saniyedeki değer okunur, o da bir sonraki dizi elemanına yazılır; bu değer $b$ olsun. Ama 3 ile 3,0001 arasında da değerler vardır: 3,00001, 3,000001 ve böyle sonsuza kadar gidilebilir. Tahtada bu, gittikçe uzayan sıfırlarla yazılmış zaman değerleriyle gösterildi (ekrandan, 00:50:00). Sürekli işarette tanımsız bir nokta yoktur. Dolayısıyla bütün genlik değerlerini kaydetmek için sonsuz belleğe sahip bir bilgisayar gerekir. Bu mümkün değildir.

### 8.2 Örnekleme (sampling)

Yapılması gereken, işaret üzerinde belli noktaları seçip yalnız bu noktalardaki değerleri sırayla kaydetmektir. Tahtada eğrinin altında belli aralıklarla dikey çizgiler çekilerek bu noktalar işaretlendi (ekrandan, 00:50:00). Bu şekilde atlayarak değer almak, aradaki bilgiyi kaybetmek demektir. Bu işleme **örnekleme (sampling)** denir. Örneklemede nelere dikkat edileceği ve sayısal sistemler sonraki derslerin konusudur.

### 8.3 Analog ve sayısal fonksiyon

Başlangıçtaki işaret $x(t)$ biçiminde bir **analog fonksiyondur**; analog fonksiyon süreklidir. Analog ses buna iyi bir örnektir: kaset (teyp) ve gramofon, sesin sürekli olarak kaydedildiği ortamlardır. Sayısal (dijital) ses denince ise CD ve MP3 düşünülmelidir: sesin belli aralıklarla örnekleri alınmıştır. Bu, sesin tamamı değil, bir yaklaşıklığıdır.

Örneklemeden sonra işaret ayrıklaştırılmış olur. Artık $x(t)$ yerine $x[n]$ yazılır; köşeli parantez içindeki $n$ bir indistir: birinci örnek, ikinci örnek, üçüncü örnek. Tahtada bu durum şöyle özetlendi (ekrandan, 00:50:00):

- $x(t)$: analog fonksiyon (sürekli)
- $x[n]$: sayısal fonksiyon (ayrık)

> **Ek bilgi (derste anlatılmadı):** Örnekler eşit aralıklarla alınıyorsa ve örnekleme aralığı $T_s$ ise ayrık işaret $x[n] = x(nT_s)$ biçiminde yazılır; örnekleme frekansı $f_s = 1/T_s$'dir. Örneklemede bilginin kaybolmaması için gereken koşul, ders planındaki örnekleme teoreminin konusudur.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:40:11): Üç boyutlu bir işarete örnek veriniz.

> **Çözüm:** Derste verilen cevaplar: MR ve bilgisayarlı tomografi görüntüleri (hasta katman katman taranır; en, boy ve yükseklik üç boyutu oluşturur), LIDAR ve RGB-D verileri.

**Soru 2** (derste sözlü ve tahtada, 00:43:22; ekrandan, 00:45:00): Bir boyutlu sürekli bir işaretin 3. ve 4. saniyeler arasındaki kısmını bilgisayara olduğu gibi atabilir miyiz?

> **Çözüm:** Hayır. Sürekli işarette iki nokta arasında (örneğin 3 ile 3,0001 arasında) sonsuz sayıda değer vardır; bunların hepsini saklamak sonsuz bellek gerektirir. Bu yüzden işaret belli noktalarda örneklenir (sampling) ve yalnız bu örnekler bir diziye yazılır. Sonuç, ayrık (sayısal) işaret $x[n]$'dir; örnekler arasındaki bilgi kaybolur.

**Soru 3** (derste sözlü, 00:26:16): Konvolüsyon tek boyutlu mu, iki boyutlu mu yapılır?

> **Çözüm:** Hocanın cevabı: Bir boyutlu konvolüsyonu yapabilen iki boyutluyu da rahatlıkla yapabilir; hemen hemen aynı işlemdir, biri dizi boyutunda, öbürü matris boyutunda yapılır. <!-- BELİRSİZ: sorunun tam metni altyazıda yok, yalnız hocanın cevabından çıkarıldı. -->

**Soru 4** (derste sözlü, 00:29:19): Derste Python ve MATLAB'in ikisi de mi kullanılacak, yoksa biri yeterli mi?

> **Çözüm:** Biri yeterlidir. Ödevler istenen dilde yapılabilir; derslerde ise daha çok MATLAB arayüzü kullanılacaktır.

## Dersin Toparlaması

Bu giriş dersinde Sinyaller ve Sistemler dersinin sayısal işaret işlemenin matematiksel temeli olduğu, konuların işaretlerin gösterimi ve sinüzoitlerden başlayıp Fourier analizi, örnekleme, LTI sistemler ve konvolüsyon üzerinden Laplace ve Z dönüşümlerine uzandığı görüldü. Uygulamalar için MATLAB ve Python önerildi; script dillerin derlenen dillerden farkı ve MATLAB arayüzünün bölümleri tanıtıldı.

Beyaz tahtadaki anlatımda dış dünyadaki verinin bilgisayarda işlenmesi problemi ortaya kondu. İşaretlerin bir, iki, üç ve $n$ boyutlu olabileceği; sürekli işaretin sonsuz sayıda değer içerdiği için bilgisayara olduğu gibi aktarılamayacağı ve bu yüzden örnekleme yapılarak analog $x(t)$'den sayısal $x[n]$'e geçildiği anlatıldı. Örneklemenin ayrıntıları ve ayrık işaretler sonraki derslerin konusudur.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
