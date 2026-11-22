# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin yeri ve amacı
  - Bilgisayar Mühendisleri için Sinyaller (İşaret) ve Sistemler, sayısal işaret işlemeden (DSP) önce gelen, işin matematiksel temellerini veren bir derstir. İçerik büyük ölçüde sayısal işaret işlemeyle örtüşür ama daha az yoğundur.
  - Görüntü işleme, makine öğrenmesi ve derin öğrenme gibi alanlara gidecekler için altyapı sağlar: dış dünyadaki işaretlerin matematiksel gösterimi, ayrık işaretler ve ayrıklaştırma.
- Dersin konu akışı (ekrandan, 00:15:00 ve altyazıdan)
  - İşaretlerin matematiksel gösterimi, sinüzoitler (her işaretin sinüslerin toplamı olarak yazılabilmesi), spektrum gösterimi ve Fourier analizi (zaman domeni yanında frekans domeni).
  - Örnekleme ve örtüşme (sampling and aliasing): spektrum görünümü, yeniden oluşturma, ayrıktan sürekliye dönüşüm, örnekleme teoremi.
  - Sürekli zamanlı LTI sistemler ve konvolüsyon integrali; ayrık zamanlı LTI sistemler ve konvolüsyon toplamı.
  - LTI sistemlerin zaman domeninde diferansiyel ve fark denklemleri.
  - Sürekli zamanlı işaretler için Fourier dönüşümü; ayrık zamanlı işaretler için ayrık zamanlı Fourier dönüşümü (DTFT).
  - Sürekli zaman için Laplace dönüşümü (s-düzleminde kutuplar ve sıfırlar); ayrık zaman için Z dönüşümü (z-düzleminde kutuplar ve sıfırlar).
- Kullanılacak araçlar
  - Derste ve ödevlerde MATLAB ya da Python kullanılır. Octave, Scilab ve R de vardır ama öncelik MATLAB ve Python'dadır.
  - MATLAB'in tarayıcıdan çalışan çevrim içi sürümü (MATLAB Online) vardır; Python için Anaconda dağıtımı ve Spyder geliştirme ortamı önerildi.
  - Derslerde daha çok MATLAB arayüzü kullanılacak; ödevlerde dil seçimi öğrenciye bırakıldı.
- Kaynak kitaplar
  - Ana kitap: Signal Processing First. Slaytların temeli bu kitaptır.
  - Yardımcı kitaplar: Signals and Systems for Dummies, çeşitli Signals and Systems kitapları ve Richard Baraniuk'un çevrim içi Signals and Systems kitabı. <!-- BELİRSİZ: altyazıda "Richard Briney" geçiyor; büyük olasılıkla Richard Baraniuk kastedildi. -->
- İşaret kavramına giriş (beyaz tahta)
  - Dış dünyadaki veriyi bilgisayarda işlemek temel problemdir.
  - Bir boyutlu işaret $x(t)$, iki boyutlu işaret $x(u,v)$, üç boyutlu ve $n$ boyutlu işaretler.
  - Sürekli (continuous) ve ayrık (discrete) işaret ayrımı; sürekli işaretin bilgisayara olduğu gibi aktarılamaması ve örnekleme (sampling) fikri.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ders eklemeli (birikimli) ilerler
  - Konular birbirinin üzerine kurulduğu için arada bir iki hafta kaçırmak sonrasını takip etmeyi zorlaştırır.
- MATLAB ve Python bilmek önemlidir
  - Python özellikle derin öğrenme, makine öğrenmesi ve görüntü işleme alanlarında öne çıkmaktadır; hoca script dili olarak Python'u tavsiye etti.
  - İkisi de script dili olduğu için kısa bir tanıtım videosuyla (30-50 dakika) temel kullanım öğrenilebilir.
- Sürekli işaret bilgisayara olduğu gibi atılamaz
  - Sürekli işarette iki nokta arasında sonsuz sayıda değer vardır; hepsini kaydetmek için sonsuz bellek gerekir. Bu yüzden belli noktalarda örnek alınır, bu işleme örnekleme denir.
- Bir boyutlu işaretler üzerinden genelleme
  - Ders daha çok bir boyutlu işaretler üzerinden anlatılacak; buradan iki ve daha çok boyuta genelleme yapılabilir.

## Kısa Tekrar Notları

- Sinyaller ve Sistemler: DSP'nin matematiksel temeli.
- Script dil (MATLAB, Python): başlık, değişken bildirimi gerekmez; `a = 5` yazınca değer hemen atanır, satır satır çalışır. Derlenen dil (C): önce başlık dosyaları, değişken tanımları, fonksiyonlar.
- MATLAB arayüzü: Command Window, Workspace (değişken listesi), Command History, Current Directory (ekrandan, 00:20:00).
- 1B işaret: $x(t)$ (ör. bir yerin sıcaklığı, bir çözeltideki asitlik). 2B işaret: $x(u,v)$ (ör. fotoğraf). 3B işaret: MR, bilgisayarlı tomografi, LIDAR, RGB-D.
- Renkli fotoğraf: R, G, B katmanları; her piksel her katmanda örneğin 0-255 arası bir değer alır.
- Sürekli işaret: aralarda boşluk yok (eski film tabanlı fotoğraf, analog ses: kaset, gramofon).
- Ayrık işaret: belli aralıklarla alınmış örnekler (CD, MP3 gibi sayısal ses).
- Analog fonksiyon $x(t)$ süreklidir; sayısal fonksiyon $x[n]$ ayrıktır ve indislerle (1., 2., 3. örnek) gösterilir (ekrandan, 00:50:00).
- Örnekleme (sampling) arada kalan bilgiyi kaybettirir.

## Detaylı Açıklamalar

- **Dersin konumu.** Ders, sayısal işaret işlemenin temellerini daha matematiksel bir bakışla verir. Sayısal işaret işleme dersi kadar yoğun değildir. Hoca dersi çok uzun matematiğe boğmadan, temel kavramları vererek ilerleteceğini söyledi. Konuların sırası slaytlardaki ders planında görülür: işaretlerin gösterimi ve sinüzoitlerden başlanır, spektrum ve Fourier analizine geçilir, ardından örnekleme ve örtüşme, LTI sistemler ve konvolüsyon, diferansiyel/fark denklemleri, sürekli ve ayrık zamanlı Fourier dönüşümleri, en sonda da Laplace ve Z dönüşümleri gelir (ekrandan, 00:15:00). Hoca 8. ve 9. konulardan itibaren sayısal işaret işlemeye girileceğini belirtti.

- **Script dil ile derlenen dil.** C gibi derlenen bir dilde önce başlık dosyaları yazılır, değişkenler tanımlanır, fonksiyonlar yazılır ve program bütün olarak derlenir. MATLAB ve Python gibi script dillerde ise Command Window'a `a = 5` yazıldığında değer hemen atanır, `a*2` yazıldığında sonuç hemen görülür. Özel bir tanımlama gerekmez, komutlar adım adım işletilir. Ekranda MATLAB arayüzünün bölümleri gösterildi: menü çubuğu, araç çubuğu, geçerli çalışma dizini, Command Window, Workspace (değişken listesi), Command History, fonksiyon kataloğu ve "Getting Started" bağlantısı (ekrandan, 00:20:00). Scilab'ın MATLAB'in daha basit bir benzeri olduğu, R'nin daha çok istatistik için kullanıldığı, Python için Spyder ortamının kütüphaneleriyle rahat bir çalışma sağladığı söylendi.

- **Dış dünyadan bilgisayara.** Beyaz tahtada bir dünya ve bir bilgisayar çizildi; temel problem dış dünyadaki verilerin bilgisayar ortamında işlenmesidir (ekrandan, 00:40:00). Bir yerin sıcaklığının zamanla değişimi, bir çözeltideki bir maddenin asitlik oranı ya da delikli bir kaba akan suyun miktarı zamana bağlı bir fonksiyon oluşturur: $x(t)$. Bu tür işaretler bir boyutludur. Bir boyutlu işaret bilgisayarda bir dizinin gözlerine yazılarak saklanır.

- **Boyutlar.** İşaret yalnız $t$'ye değil, iki değişkene de bağlı olabilir: $x(u,v)$. Fotoğraf bunun örneğidir. Üç boyutlu işarete örnek sorulduğunda MR ve bilgisayarlı tomografi görüntüleri verildi: hasta katman katman taranır, en, boy ve yükseklik üç boyutu oluşturur. Öğrencilerden LIDAR ve RGB-D örnekleri de geldi. Renkli fotoğraf R, G ve B katmanlarından oluşur; bir pikselin her katmandaki değeri örneğin 0 ile 255 arasındadır. Kırmızı ile yeşilin karıştığı yerde sarı oluşur. Matematikte boyut sınırı olmadığı için 4, 5 ya da $n$ boyutlu (hiper boyutlu) işaretlerden de söz edilebilir; hoca bunun makine öğrenmesine de ipucu verdiğini söyledi (ekrandan, 00:45:00).

- **Sürekli ve ayrık işaret.** Sıcaklık ölçümünde aralarda hiç boşluk yoktur, yani $t$ süreklidir. Eski film tabanlı fotoğraf makinesinde de piksel kavramı yoktur; görüntü kimyasal filmin her yerine düşer. Sürekli bir işaretin örneğin 3. ve 4. saniyeler arasındaki kısmını bilgisayara atmak istersek 3'teki değeri ($a$) bir dizi elemanına, 3,0001'deki değeri ($b$) bir sonrakine yazabiliriz. Ancak arada daha küçük adımlarla sonsuza kadar gidilebilir; sürekli işarette tanımsız nokta yoktur. Bütün genlik değerlerini kaydetmek için sonsuz belleğe sahip bir bilgisayar gerekir, bu da mümkün değildir (ekrandan, 00:50:00).

- **Örnekleme.** Çözüm, belli noktaları seçip yalnız o noktalardaki değerleri sırayla kaydetmektir. Bu işleme örnekleme (sampling) denir. Örnekler arasında kalan bilgi kaybedilir. Analog fonksiyon $x(t)$ süreklidir; örneklemeden sonra elde edilen sayısal fonksiyon $x[n]$ ise ayrıktır ve indislerle gösterilir: birinci örnek, ikinci örnek, üçüncü örnek (ekrandan, 00:50:00). Analog sese kaset ve gramofon, sayısal sese CD ve MP3 örnek verildi: sayısal ses sesin tamamı değil, belli aralıklarla alınmış örneklerden oluşan bir yaklaşıklığıdır. Örneklemenin ayrıntısı sonraki derslere bırakıldı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
