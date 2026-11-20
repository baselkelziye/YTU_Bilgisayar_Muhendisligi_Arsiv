# Ders 2 Genişletilmiş Notu: Bilgisayarla Görmeye Giriş ve Python ile İmgelerle Çalışma

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Kaynakları ve Yönelimi
- 2. Bilgisayarla Görme Nedir?
- 3. Uygulama Alanları
- 4. Güncel Durum: Derin Öğrenmenin Etkisi
- 5. Disiplinlerarası Bir Alan ve Önkoşullar
- 6. İmgeler: Gri Seviye ve Renkli İmgeler
- 7. Değer Aralıkları ve Normalizasyon
- 8. Python ile İmge Okuma
- 9. İmge Gösterme ve Renk Haritaları
- 10. İmge Yazma ve Dosya Formatları
- 11. NumPy'a Hızlı Bakış
- 12. Uygulama: Spyder'da İmge Açmak
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Kaynakları ve Yönelimi

Hoca derse bu yıl kullanılacak kaynakları tekrar göstererek başladı. Sunumları PDF'e çevirip tablet üzerinde, üzerine el yazısıyla not alarak anlatıyor; slaytlar ve materyaller dersin paylaşım klasöründe konu konu ("subjects") toplanmış durumda.

### 1.1 Ana kitap: Szeliski

Dersin kitabı Richard Szeliski'nin *Computer Vision: Algorithms and Applications* kitabıdır. Yazar kitabı yıllardır kendi web sitesinde taslak hâlinde yayımlıyor ve geliştiriyor. Derste açılan sayfa ikinci baskının sayfasıydı: "© 2020 Richard Szeliski", taslak PDF'ler ücretsiz indirilebiliyor (ekrandan, 00:10:00). Hocanın slaytındaki kitap kapağı ise 2010 tarihli birinci baskıya aitti (ekrandan, 01:00:00). Hoca, okumalarda bölüm numaraları değişmişse bölümün adına göre aranmasını söyledi.

Ders paylaşım klasöründe konular Szeliski okumalarıyla birlikte sıralanmış durumdaydı (ekrandan, 02:40:00):

- 010 course intro
- 020 working with images
- 030 cameras and optics (Szeliski 2.1)
- 040 image filtering (Szeliski 3.2)
- 050 thinking in frequency (Szeliski 3.4)
- 060 thinking in frequency part 2 (Szeliski 3.5.2 ve 8.1.1)
- 070 edge detection (Szeliski 4.2)
- 080 interest points and corners (Szeliski 4.1.1)
- 090 local image features (Szeliski 4.1.2)
- 100 feature matching and robust fitting (Szeliski 4.1)
- 110 model fitting and RANSAC (Szeliski 6.1 ve 2.1)
- 130 camera calibration (Szeliski 6.2.1)
- 140 epipolar geometry and structure from motion (Szeliski 7)

Hoca bu listenin iki yıl önce verdiği dersin konuları olduğunu, bu yıl yaklaşık yarısını çıkarıp yerine yapay sinir ağları ve derin öğrenme ekleyeceğini, dolayısıyla listenin geçici olduğunu söyledi.

### 1.2 Slaytlar ve çevrimiçi dersler

Slaytların temeli James Hays'in bilgisayarla görme ders slaytlarıdır. Hays de slaytlarını başka hocalardan derlemiştir; örneğin Brown Üniversitesi'ndeki bir hocanın slaytlarından yararlanmıştır.

Sinir ağlarına geçildiğinde Stanford'da Fei-Fei Li'nin grubunun verdiği *CS231n: Convolutional Neural Networks for Visual Recognition* dersi önerildi (ekrandan, 00:20:00). Bu dersin slaytları ve videoları çevrimiçidir. Hocaya göre bilgisayarla görmede derin öğrenmeyle çalışmak isteyenler için "çok çok iyi" bir kaynak. İlk sekiz hafta kadarı giriş, sonrası daha özel konulardır ve konu çok hızlı değiştiği için içerik her yıl yenilenir. Klasik bilgisayarla görme ilk 5-6 haftada biterse dersin bu içeriğe paralel ilerleyebileceği söylendi.

Fei-Fei Li'nin yanında çalışmış olan Justin Johnson'ın University of Michigan'daki *Deep Learning for Computer Vision* dersi de benzer içerikte ikinci bir kaynak olarak gösterildi.

### 1.3 Derin öğrenme kitabı

**Soru:** Derin öğrenme ve yapay sinir ağları için ön hazırlık olarak hangi kaynak okunabilir?
**Cevap:** Hoca Yoshua Bengio'nun *Deep Learning* kitabını önerdi (tahtaya "Joshua Bengio / Deep Learning" yazdı; ekrandan, 00:25:00). Kitap internette ücretsiz okunabiliyor. Temel konular kitapta vardır, ama alan çok hızlı değiştiği için kitaplar güncel gelişmelere yetişemez. Yapay sinir ağı ve derin öğrenmenin temelleri derste de anlatılacak.

### 1.4 Hesaplama altyapısı

Derin öğrenmeyle uğraşmak sağlam bir donanım altyapısı gerektirir. Hoca, Türkiye'de araştırmacıların kullanabildiği dağıtık hesaplama altyapısı TRUBA'dan (TR-Grid) söz etti ve bu altyapıyı derin öğrenme için kullanabilmenin önemli olduğunu vurguladı. Hocanın ilgisi ayrıca yapay sinir ağlarıyla üretme (GAN'lar gibi üretici modeller) üzerine; işin içine öğrenme girince görüntü ile metin üretimi arasında büyük fark kalmadığını düşünüyor.

## 2. Bilgisayarla Görme Nedir?

Hocanın kısa tanımı: bilgisayarla görme, **makine öğrenmesinin görsel veriye uygulanmış hâlidir**. Yani aslında bir makine öğrenmesi dersidir; temel farkı uygulama alanının görseller olmasıdır.

"Görme" denince bilgisayarların imgeleri ve diğer görsel verileri anlaması kastedilir. Bir imgede nasıl bir sahne var, sahnede neler var, arabalarla ilgileniyorsak arabalar nerede, bina kameradan ne kadar uzakta? İnsan bir sahneye baktığında bu bilgilerin çoğunu iyi kötü toparlayabilir. Bu işleri bilgisayara yaptırmak ise kolay değildir.

Slayttaki bilgiye göre görsel korteks makak maymununun beyninin yaklaşık %50'sini kaplar. <!-- BELİRSİZ: Altyazıda insan beyni için "%1" deniyor; slayttaki insanla ilgili cümle karelerde görünmüyor. --> Hoca, gelen görsel verinin büyüklüğünü şöyle anlattı: Bir slayttaki resimlerin içerdiği bilgi büyükçe bir kitap kadar olabilir; video düşünüldüğünde bu daha da artar. İnsanın görsel sistemi bu veriyi değerlendirir, anlar ve çıkarımlar yapar. Bunu taklit etmek kolay değildir.

Tarihçeye fazla girilmedi: alanın 1960'larda başladığı, 2000'lerde büyük veri setlerinin hazır hâle geldiği, 2010'larda ise sinir ağları ve derin öğrenmenin öne çıktığı söylendi.

## 3. Uygulama Alanları

Hoca slaytlardaki uygulamaları tek tek gezdi ve bu slaytların yaklaşık on yıl önce hazırlandığını, bazı örneklerin geride kaldığını belirtti.

- **Karakter tanıma:** Plaka tanıma, posta servislerinde adreslerin okunması.
- **Yüz algılama:** Cihazlar yüzü doğrudan algılıyor; bazı fotoğraf makineleri gülümsemeyi algılayıp o anda çekiyor.
- **Biyometri:** Hocanın örneği, eski ve ünlü bir Afgan kızı fotoğrafıdır. Yıllar sonra kızı tekrar bulduklarında aynı kişi olduğunu doğrulamak için iris tanımadan yararlanılmıştır. Kızın en ayırt edici özelliği zaten gözleri ve bakışıdır. Bilgisayarlarda şifre yerine parmak izi ya da yüz tanıma da bu gruptadır.
- **Mobil görsel arama:** Telefonla bir resim çekip Google ya da Wikipedia'da arama yapmak.
- **Üç boyutlu model çıkarma:** Önceden birçok resim gerekirken artık tek bir resimden üç boyutlu şekil çıkarılabiliyor.
- **Hareket yakalama (motion capture):** Filmlerde oyuncunun hareketleri ve konuşması algılanıp üzerine üç boyutlu bir model "giydiriliyor"; oyuncu hareket ettikçe model de hareket ediyor. Bilgisayar grafiğiyle iç içe bir uygulamadır.
- **Spor:** Tenis maçlarında topun kort içinde mi dışında mı olduğuna gerçek zamanlı karar verme; karar destek sistemi olarak kullanım.
- **Reklam yerleştirme:** Sistem görüntüde boş bir alan bulup oraya otomatik reklam koyuyor; boş alanın bulunması bilgisayarla görme işidir.
- **Medikal görüntüleme:** Tümörlü ya da kanserli hücrelerin, hastalıkların görüntülerden tespiti. Hoca bunun popüler bir araştırma konusu olduğunu, bilgisayar mühendisliği hocalarının sıkça bir tıp hocasıyla iş birliği yaptığını söyledi.
- **Akıllı arabalar:** Slaytta Intel'in yaklaşık 15 milyar dolara satın aldığı bir şirketten (Mobileye; altyazıda bozuk yazılmış) ve Google'ın sürücüsüz arabalarından söz ediliyordu.
- **Oyunlar:** Elinizde gerçek bir golf sopası olmadan yaptığınız hareket algılanıyor ve oyun hareketlerinizle oynanıyor. Örnek olarak Microsoft'un derinlik de algılayabilen Kinect cihazı anıldı.
- **Artırılmış ve sanal gerçeklik:** Gerçek bir sahnenin içinde zıplayan bir balina hologramı örneği gösterildi. Bunun için ortamın algılanması gerekir; bu da bilgisayar grafiği ile bilgisayarla görmenin birlikte kullanıldığı bir uygulamadır. Pokémon Go da bu tür bir örnek olarak anıldı.
- **Endüstriyel robotlar:** Banttan geçen ürünlere bakan bir kamera, çatlak ya da bozuk ürünü bantan düşürebilir veya alarm verebilir. Slayttaki daha gelişmiş örnekte görüntüyle yönlendirilen robotlar araba tekerleklerine somun sıkma aletlerini yerleştiriyordu (ekrandan, 00:40:00).
- **Uzay:** Mars aracı Spirit'te bilgisayarla görmenin kullanıldığı söylendi.

## 4. Güncel Durum: Derin Öğrenmenin Etkisi

En gelişmiş uygulamalara bakıldığında, eğitim verisi verildiğinde bilgisayarla görme neredeyse insan görüsünü yakalamış durumdadır. Hocaya göre derin öğrenme "ortalığı dağıttı"; bilgisayarla görme büyük ölçüde derin öğrenme hâline geldi.

### 4.1 Örnek: İmge büyütme neden zordur?

Hoca, akla gelmeyebilecek bir örnek verdi: imgeyi yeniden boyutlandırma. Bir imgenin daha büyük bir sürümünü elde etmek istiyoruz. İmgeyi her boyutta 2 katına çıkarırsak bir piksel 2×2 = 4 piksel olur. Bu dört piksele eski pikselin aynı rengini koymak kaliteli bir büyütme sağlamaz. Yapılması gereken, çevredeki piksellere bakarak bu dört pikseli farklı ama uygun renklerle doldurmaktır. Ölçek 2,3 gibi tam sayı olmayan bir değer olunca iş daha da karışır. Bu tür işler artık derin öğrenmeye yaptırılıyor. Yani yalnızca "görme" değil, klasik imge işleme uygulamalarının çoğu da derin öğrenmeyle yapılabiliyor.

Hoca bu derste derin öğrenmeyi kaçınılmaz olarak ekleyeceklerini, ama klasik yöntemlerden de tamamen vazgeçmeyeceklerini söyledi.

### 4.2 Derin öğrenmenin görünürlüğü

Slaytta dijital dünyayı değiştiren kişilerin bir listesi gösterildi: 69. sırada "derin öğrenmenin babası" olarak anılan Geoffrey Hinton vardı (ekrandan, 00:45:00). <!-- BELİRSİZ: Listenin adı altyazıda "Wild Yüz" diye geçiyor; büyük olasılıkla bir derginin "100" listesi. --> Yann LeCun da derin öğrenmenin önemli isimlerinden biri olarak anıldı. Ayrıca Google DeepMind'ın Go oyununda şampiyonları yenen AlphaGo ve AlphaZero uygulamalarından söz edildi; bunlar temelde pekiştirmeli öğrenmeye dayanan derin öğrenme uygulamalarıdır.

## 5. Disiplinlerarası Bir Alan ve Önkoşullar

Bilgisayarla görme birçok disiplini içinde barındırır. Temelinde imge işleme, geometrik düşünme ve tanıma vardır; derin öğrenme çok önemli hâle gelmiştir. Robotik, insan-bilgisayar etkileşimi, medikal görüntüleme, sinirbilim, optik, fotoğrafçılık, bilgisayar grafiği ve makine öğrenmesiyle de ilişkilidir.

Ders için gerekenler:

- **Matematik:** Lineer cebir, temel kalkülüs (Matematik 1-2) ve olasılık.
- **İmge işleme:** Gonzalez'in *Digital Image Processing* kitabı (hocanın hatırladığı kadarıyla dördüncü baskısı var).
- **Programlama:** Python ve benzeri bir dille çalışabilmek.

> **Hocanın vurguları:** Bilgisayarla görmede araştırmacı olmayı ciddi olarak düşünenler Gonzalez'in kitabını okumalı. Makalelerde bolca matematik vardır ve böyle bir kitap okunmadan bu matematik anlaşılamaz. İmge işleme bilgisayarla görmenin temelidir. Ancak imge işleme başlı başına ayrı bir derstir (kitap bin sayfa kadardır); bu derste yalnızca temel düzeyde üzerinden geçilecek.

## 6. İmgeler: Gri Seviye ve Renkli İmgeler

### 6.1 Gri seviye imge bir matristir

Hoca "Working with Images" konusuna gri seviye imgelerle başladı. Gri seviye imge iki boyutlu bir dizi, yani bir matristir. Tahtaya şu 3×4'lük matris yazıldı ve "bu 3×4'lük bir imge olarak kabul edilebilir" denildi (ekrandan, 01:05:00). Hoca daha sonra ilk elemanı 0, en büyük elemanı 255 yaparak siyah ve beyazı örnekledi (ekrandan, 01:10:00):

$$A = \begin{bmatrix} 0 & 3 & 8 & 6 \\ 7 & 12 & 200 & 255 \\ 1 & 8 & 12 & 5 \end{bmatrix}$$

Görüntüleme sistemi matristeki her sayıya bir renk atar. Sayıları ışık miktarı gibi düşünebiliriz: 0'da hiç ışık yoktur ve siyah gösterilir; 255'te bol ışık vardır ve beyaz gösterilir. Aradaki değerler siyahtan beyaza grinin farklı tonlarıdır.

Matristeki her değer aslında tek bir sayıdır. Ekran ise bu değeri gösterebilmek için belirli bir alanı, yani bir pikselin kapladığı küçük kare alanı o renge boyar. Bu elemanların her birine **piksel** denir. Pikseller çok küçük olduğu için uzaktan fark edilmezler; bir resmi Paint gibi bir programda yeterince büyütünce kareler görünmeye başlar.

### 6.2 İndeksleme

Matrisin bir elemanına ulaşmak için onu numaralandırmak gerekir. Java ve C gibi Python'da da (NumPy'da) indeksleme **0'dan başlar**. MATLAB'da ise 1'den başlar. Önce satır numarası, sonra sütun numarası yazılır:

- `A[0,0]` → sıfırıncı satır, sıfırıncı sütun → 0
- `A[0,1]` → sıfırıncı satır, birinci sütun → 3

Hoca, satır ve sütun sırasını sık karıştırdığını söyledi; bir öğrenci önce satırın yazıldığını doğruladı. Python'da (NumPy'da) köşeli parantez kullanılır.

### 6.3 Renkli imge ve renk uzayları

Renk üç sayıyla gösterilir. Bu üç sayının ne anlama geldiği kullanılan **renk uzayına** bağlıdır. En yaygını RGB'dir: kırmızı (red), yeşil (green) ve mavi (blue) bileşenler. Ama sonuçta RGB de yalnızca üç sayıdır; örneğin (3, 10, 100) (ekrandan, 01:15:00).

Aynı renk başka bir renk uzayında başka üç sayıyla gösterilir. Hoca HSI uzayını (hue, saturation, intensity) örnek verdi ve aynı rengin HSI'da "218, 60 gibi" başka değerlerle ifade edildiğini söyledi; bu değerler yalnızca örnek amaçlıydı. Diğer renk uzayları arasında YCrCb ve HSV sayıldı. Hoca vakit açısından renk uzaylarına derste ayrıca girmeyeceğini, öğrencilerin bunları kendilerinin okuyup öğrenmesini istedi.

> **Ders sonrası not:** Hocanın HSI değerleri yalnızca "başka sayılarla gösterilir" demek için verilmişti, gerçek bir dönüşüm değildi. Standart RGB→HSI formülüyle (3, 10, 100) için büyük olasılıkla yaklaşık $H \approx 236^\circ$, $S \approx 0{,}92$, $I \approx 37{,}7$ (0-255 ölçeğinde) bulunur (ajan python ile hesapladı).

### 6.4 Kanallar (channels)

Her pikselde üç değer olduğuna göre bunlar nasıl tutulur? Genel yol şudur: R değerleri bir matris, G değerleri bir matris, B değerleri bir matris olur. Bu matrislerin her birine **kanal (channel)** ya da **düzlem (plane)** denir; "page" dendiği de olur ama pek kullanılmaz (ekrandan, 01:15:00). Kırmızı kanal (R channel), yeşil kanal ve mavi kanal birlikte düşünüldüğünde üç boyutlu, küp benzeri bir yapı oluşur. Renkli bir imgede her piksel için üç değer tutulur.

Bazen dördüncü bir kanal olarak **alfa kanalı** eklenir (A ya da α ile gösterilir). Alfa değeri değiştirildiğinde imgenin o kısmının saydamlığı ayarlanır. Bilgisayar grafiğinde bir resim başka bir resmin üzerine geldiğinde alttakinin görünüp görünmeyeceği bununla belirlenir.

**Soru (hoca sordu):** Alfada 0 mı tam saydam, yoksa en büyük değer mi?
**Cevap (bir öğrenci):** 255'te normal renk görünür, 0'da tam saydam olur. Hoca bunu onayladı: 0 saydam, en büyük değer opaktır (saydamlığın tersi); opak bir piksel altını hiç göstermez.

## 7. Değer Aralıkları ve Normalizasyon

### 7.1 Neden 0-255?

Gri seviyede en çok kullanılan aralık 0-255'tir, çünkü bir piksel 8 bitle gösterildiğinde $2^8 = 256$ farklı değer elde edilir; bunlar 0'dan 255'e kadar atanır (ekrandan, 01:20:00). İmgeler MATLAB ya da Python ile ilk okunduğunda pikseller çoğunlukla bu aralıkta gelir; birçok ekrana da değerler bu aralıkta verilir.

### 7.2 Neden 0-1 aralığına geçiyoruz?

İmge işleme ya da bilgisayarla görme yaparken 256 tamsayı değer yetmez. İmgeler toplanır, çıkarılır, çarpılır, konvolüsyon yapılır ve 1,3 gibi ondalıklı değerler oluşur. Değerler tamsayıda tutulursa bu kesirler kaybolur ve sonuç doğruluğu düşer. Ayrıca işlemler sırasında değerler sık sık aralığın dışına taşar.

Bu yüzden izlenen yol şudur:

1. İmge okununca değerler gerçel sayıya çevrilir ve basit bir normalizasyonla 0-1 aralığına getirilir (255 → 1, 0 → 0).
2. İşlemler 0-1 aralığında yapılır. Aralık dışına taşma olursa arada tekrar normalize edilir.
3. Sonuç kaydedilirken ya da ekranda gösterilirken 0-1 aralığı yeniden 0-255'e döndürülür.

Hoca bunu "aralıkları normalize ede ede, değiştire değiştire işlem yapmak" diye özetledi.

## 8. Python ile İmge Okuma

Hoca derste doğrudan Python kullanacağını söyledi. Python'da imge okumak için birden fazla seçenek vardır:

- **OpenCV:** `cv2` modülünde `imread` fonksiyonu dosya yolunu alıp imgeyi okur. Slayttaki örnek (ekrandan, 02:40:00):

  ```python
  import cv2  # OPENCV
  f = cv2.imread('airplane.png')  # numpy array!
  ```

- **SciPy:** Slayta CS231n'in Python/NumPy öğreticisinden şu alternatif eklendi (ekrandan, 02:40:00):

  ```python
  from scipy.misc import imread, imsave, imresize

  # Read an JPEG image into a numpy array
  img = imread('assets/cat.jpg')
  ```

  Bir öğrenci SciPy'daki `imread`'in içe aktarılamadığını yazdı. Belgelere bakınca fonksiyonun kullanımdan kaldırıldığı (deprecated) görüldü. Bu fonksiyon PIL'i kullanıyordu; PIL çok popüler olmasına rağmen artık güncellenmediği için yerine **Pillow** çıkmıştır. Sonuç: imgeler OpenCV ile ya da Pillow ile okunmalı.

Neden bu kadar çok seçenek var? Dünya kadar imge formatı vardır (PNG, JPEG, GIF, TIFF...) ve her kütüphane hepsini açamaz. Ayrıca OpenCV gibi kütüphaneler kendi okuma fonksiyonlarını yazmıştır. İşin güzel tarafı, hepsinin döndürdüğü şeyin bir **NumPy dizisi** olmasıdır. NumPy, Python'da çok boyutlu dizilerle çalışma (bir anlamda lineer cebir) kütüphanesidir ve Python ekosisteminde standarttır. İmge bir kez okunduktan sonra elde bir NumPy dizisi vardır ve bundan sonrası NumPy ile yapılır.

İmgenin boyutları NumPy dizisinin `shape` özelliğiyle öğrenilir: `f.shape` bir tuple döndürür.

## 9. İmge Gösterme ve Renk Haritaları

### 9.1 OpenCV ile gösterme

OpenCV esasen C ile yazılmış bir kütüphanedir; Java'dan C#'a kadar birçok dilde bağlantısı (binding) vardır, Python'da da vardır. `cv2.imshow` OpenCV'nin kendi grafik penceresini açıp imgeyi orada gösterir. Slayttaki kod (ekrandan, 01:30:00):

```python
cv2.imshow('the image', f)
cv2.waitKey(0)
cv2.destroyAllWindows()
```

`waitKey(0)` yazılmazsa pencere hemen açılıp kapanır. `waitKey(0)` bir tuşa basılmasını bekler; ardından `destroyAllWindows()` pencereleri kapatır.

### 9.2 Matplotlib ile gösterme

Matplotlib, Python dünyasında standart sayılabilecek bir grafik çizim paketidir; 2 ve 3 boyutlu grafikler çizer, resim de gösterebilir. Slayttaki kod (ekrandan, 01:30:00):

```python
import matplotlib.pyplot as plt
import cv2

f = cv2.imread('airplane.png')
plt.imshow(f)

# get the first channel to demonstrate colorbar
l = f[:,:,0]
plt.imshow(l, cmap='hot')
plt.colorbar()
plt.show()
```

`f[:,:,0]` ifadesindeki iki nokta üst üste "o boyuttaki hepsi" demektir. Burada bütün satırlar, bütün sütunlar ve 0 numaralı kanal alınır (kanallar 0, 1, 2 diye numaralanır). Sonuç tek kanallı, yani gri seviye bir imgedir; bu `l` değişkenine atanıp gösterilir.

Hoca kütüphanelerin kanalları her zaman RGB sırasıyla döndürmeyebileceğini, OpenCV'nin "sanırım RBG" sırası kullandığını ama emin olmadığını, belgelere bakmak gerektiğini söyledi (tahtada "RGB / RBG?" yazdı; ekrandan, 01:35:00).

> **Ders sonrası not:** Hoca OpenCV'nin kanal sırası için "RBG" dedi; doğrusu **BGR**'dir (mavi, yeşil, kırmızı). Bu yüzden `cv2.imread` ile okunan bir imge doğrudan `plt.imshow` ile gösterilirse kırmızı ve mavi yer değiştirmiş görünür; yukarıdaki örnekte `f[:,:,0]` aslında mavi kanaldır.

### 9.3 Renk haritaları (colormap)

Tek kanallı bir imgedeki sayıları (ör. 200, 218, 255) normalde gri tonlarıyla gösteririz. Ama bazen gri tonlarla farklar iyi seçilemez. O zaman örneğin "218'i yeşil, 200'ü sarı, 255'i kırmızı göstereyim" demek isteriz (hoca tahtada küçük bir ızgara üzerinde bunu örnekledi; ekrandan, 01:35:00). Bu işi **renk haritası** yapar: hangi sayı değerinin ekranda hangi renkle gösterileceğini belirler.

Matplotlib'de önceden tanımlı birçok renk haritası vardır: viridis, plasma, inferno, magma, cividis gibi algısal olarak düzgün haritalar; Greys, Blues gibi sıralı haritalar; binary; HSV gibi döngüsel haritalar. Örnekteki `hot` haritası 0'a yakın değerleri siyah, 255'e yakın değerleri beyaz gösterir ve aradaki değerleri kırmızı-sarı tonlarına dağıtır. Değerleri birbirinden ayırt etmek önemliyse çok renkli bir harita daha çok işe yarar.

`plt.colorbar()` kullanılan renk haritasını kenarda bir çubuk olarak gösterir; hangi haritanın kullanıldığını göstermek iyi olur. `plt.show()` denmezse çizim görünmez. Hoca, Matplotlib'de ilk resmin bazı sistemlerde görünmeyebileceğini, ilk resim bir kez gösterildikten sonra gerisinin sorunsuz çalıştığını da ekledi.

## 10. İmge Yazma ve Dosya Formatları

İşlemlerden sonra elde edilen matris tekrar bir resim dosyasına yazılmak istenebilir. Bunun için OpenCV'nin `imwrite` fonksiyonu kullanılır.

Bazı formatlarda kayıt sırasında kalite belirlemek gerekir. Bunlar genelde sıkıştırmalı formatlardır. JPEG sıkıştırma sırasında bir kısım veriyi atar; daha çok sıkıştırmak dosyayı küçültür ama kaliteyi düşürür. OpenCV'de JPEG yazarken kalite parametresine 0 ile 100 arasında bir değer verilir; değer düştükçe kalite de düşer.

<!-- BELİRSİZ: "Writing images" slaytındaki imwrite ve JPEG kalite parametresinin tam kodu karelerde görünmüyor. -->

Bilgisayarla görmede bilgi kaybetmek istenmez; bu yüzden **kayıpsız formatlar** tercih edilir. PNG sıkıştırma yapan ama kayıpsız bir formattır. Hocanın hatırladığı kadarıyla BMP (bitmap) sıkıştırılmayan bir formattır ve çok yer kaplar, ama yine de kullanılabilir.

### 10.1 Veri türü

İmge ilk okunduğunda veri türü genellikle `uint8`'dir: 8 bitlik işaretsiz tamsayı (unsigned integer). Bunu kontrol etmek gerekir. NumPy'da `astype` çağrısıyla veri türü değiştirilir:

```python
x = x.astype(float)
```

Böylece veri gerçel sayıya çevrilir ve sonraki işlemler float üzerinde yapılır.

> **Ek bilgi (derste anlatılmadı):** Hoca NumPy'da "double" türü olup olmadığından emin olmadığını söyledi. NumPy'da `astype(float)` büyük olasılıkla 64 bitlik `float64` türünü verir; bu, C'deki `double` ile aynı duyarlıktadır. 32 bitlik tür için `np.float32` kullanılır.

## 11. NumPy'a Hızlı Bakış

Slayta göre NumPy imgeyi dikey çevirme, kırpma (cropping), alt örnekleme (subsampling), yatay bir satırı alma gibi işlemler için kullanılabilir; bunlar dilimleme (slicing) ile öğrenilir. NumPy en azından CPU'da Python bilimsel hesaplamasının standardıdır (ekrandan, 01:45:00). Hoca NumPy'ı verimli kullanabilmenin önemini vurguladı ve DataCamp'in *NumPy Cheat Sheet*'i üzerinden ilerledi. Ayrıca Matplotlib galerisini gösterdi: her örneğin arkasında kodu vardır; istenen grafik bir örnekten yola çıkarak çizilebilir. İki boyutlu bir imgeyi üç boyutlu yüzey olarak çizmek de bazen faydalıdır.

### 11.1 Diziler ve eksenler

NumPy genellikle `import numpy as np` diye içe aktarılır. Bir, iki ve üç boyutlu diziler vardır ve her boyut bir **eksen (axis)** ile adlandırılır. Cheat sheet'teki örnek diziler (ekrandan, 02:05:00):

```python
a = np.array([1,2,3])
b = np.array([(1.5,2,3), (4,5,6)], dtype=float)
c = np.array([[(1.5,2,3), (4,5,6)], [(3,2,1), (4,5,6)]], dtype=float)
```

Hoca `b` üzerinde `min` fonksiyonunu örnekledi ve tahtaya `a.min(axis=0)` → `(1.5, 2, 3)` yazdı. Hangi eksenin yatay hangisinin dikey olduğundan emin değildi; cheat sheet'teki açıklamayı okuyunca netleşti: "axis 0, satırlar boyunca dikey olarak aşağı doğru ilerler". Yani:

- `b.min(axis=0)` her sütunun en küçüğünü verir: `[1.5, 2, 3]`.
- `b.min(axis=1)` her satırın en küçüğünü verir: `[1.5, 4]`.

Üç boyuta çıkınca bir de `axis=2` gelir; eksen sayısı boyutla birlikte artar. Elde Python listesi hâlinde veri varsa önce NumPy dizisine çevrilmesi gerekir. Tür `dtype` anahtar kelime argümanıyla belirtilir.

### 11.2 Hızlı dizi oluşturma

Elde veri yoksa şu fonksiyonlar hızlıca dizi üretir (ekrandan, 02:05:00):

| Komut | Ne yapar |
|---|---|
| `np.zeros((3,4))` | Sıfırlarla dolu dizi |
| `np.ones((2,3,4), dtype=np.int16)` | Birlerle dolu dizi |
| `np.arange(10,25,5)` | 10'dan 25'e kadar beşer artan değerler: `[10, 15, 20]` |
| `np.linspace(0,2,9)` | 0 ile 2 arasında eşit aralıklı 9 değer |
| `np.full((2,2),7)` | Sabit değerli dizi |
| `np.eye(2)` | 2×2 birim matris |
| `np.random.random((2,2))` | Rastgele değerlerle dolu dizi |
| `np.empty(...)` | Yer ayırır ama içini doldurmaz; içinde bellekte ne varsa o kalır |

Veri türleri `np.int64`, `np.float32` gibi bit sayısıyla birlikte belirtilebilir; karmaşık sayı, Boole, `np.object`, metin için string ve unicode türleri de vardır. Dizi hakkında bilgi almak için `a.shape` (boyutlar), `len(a)`, `a.dtype` (veri türü), `a.dtype.name` gibi özellikler kullanılır.

### 11.3 Aritmetik işlemler

NumPy'ın asıl faydası, lineer cebirde gördüğümüz matris işlemlerini hiç döngü yazmadan yapabilmektir. Cheat sheet'teki örnekler (ekrandan, 02:10:00):

```python
>>> g = a - b
array([[-0.5,  0. ,  0. ],
       [-3. , -3. , -3. ]])
>>> b + a
array([[ 2.5,  4. ,  6. ],
       [ 5. ,  7. ,  9. ]])
>>> a / b
array([[ 0.66666667,  1.  ,  1.  ],
       [ 0.25      ,  0.4 ,  0.5 ]])
>>> a * b
array([[  1.5,   4. ,   9. ],
       [  4. ,  10. ,  18. ]])
>>> e.dot(f)
array([[ 7.,  7.],
       [ 7.,  7.]])
```

`a - b` elemanları tek tek çıkarır. Burada `a` tek boyutlu, `b` iki boyutlu olduğu için NumPy `a`'yı uygun boyuta genişletip öyle çıkarır; biri skaler (ör. yalnızca 2) olsa da önce uygun bir matris oluşturup sonra çıkarır. Operatörlerin fonksiyon karşılıkları da vardır: `np.subtract`, `np.add`, `np.divide`, `np.multiply`. Bölme ve çarpma da eleman eleman yapılır. `np.exp`, `np.sqrt`, `np.sin`, `np.cos`, `np.log` gibi fonksiyonlar da her elemana uygulanır. Üs almak için `a**2` yazılır (ekrandan, 02:15:00).

Matris çarpımı ise `dot` ile yapılır. Son örnekte `e = np.full((2,2),7)` ve `f = np.eye(2)` olduğundan $e \cdot I = e$ olur ve sonuç her elemanı 7 olan 2×2 matristir.

> **Hocanın vurgusu:** `dot` matris çarpımıdır; `*` ise Hadamard çarpımı dediğimiz bileşen bileşen çarpımdır. Bu fark hatırlanmalı.

**Soru (bir öğrenci):** A çarpı B'nin transpozu dersek de matris çarpımı yapıyor mu? Transpoz `B.T` ile alınıyor.
**Cevap:** Hoca transpozun `B.T` ile alındığını onayladı ve bunun matematiğe daha yakın bir yazım olduğunu söyledi.

> **Ders sonrası not:** Derste `A * B.T` ifadesinin de matris çarpımı yaptığı kabul edildi; doğrusu, NumPy dizilerinde (`ndarray`) `*` her zaman eleman eleman çarpımdır. `A * B.T` yalnızca boyutlar uyuşursa eleman eleman çarpım yapar. Matris çarpımı için `A.dot(B.T)`, `np.dot(A, B.T)` ya da `A @ B.T` yazılmalıdır.

### 11.4 Karşılaştırma ve Boole maskesi

Karşılaştırmalar da eleman eleman yapılır ve Boole türünde bir dizi döner (ekrandan, 02:15:00):

```python
>>> a == b
array([[False,  True,  True],
       [False, False, False]], dtype=bool)
>>> a < 2
array([ True, False, False], dtype=bool)
>>> np.array_equal(a, b)
```

`a < 2` "a'nın hangi elemanları 2'den küçük?" sorusunu tek adımda cevaplar. Bu Boole dizisi **maske** olarak kullanılabilir. Örneğin 2'den küçük elemanlara 0 atamak için:

```python
a[a < 2] = 0
```

`a < 2` bir Boole dizisi üretir, `True` olan konumlara 0 atanır. Aynı işin döngüyle yazılışı tahtada başlatıldı; aşağıdaki iç içe döngü anlatımdan tamamlandı (ara adım eklendi):

```python
for i in range(...):
    for j in range(3000):
        if a[i, j] < 2:
            a[i, j] = 0
```

> **Hocanın vurgusu:** Döngü yerine maskeli yazımı kullanın. İki avantajı var: yazması çok daha kolay ve anlaşılır, ve çok çok daha hızlı. Python'da döngüler C ya da C++'taki gibi değildir, pahalıdır; bu yüzden pratikte döngüyle çalışılamaz. NumPy'ın bu imkânlarını öğrenip kullanabilmek gerekir.

### 11.5 Toplu (aggregate) fonksiyonlar

`a.sum()`, `a.min()`, `b.max(axis=0)`, `b.cumsum(axis=1)`, `a.mean()`, `b.median()`, `a.corrcoef()`, `np.std(b)` gibi fonksiyonlar istatistiksel özetler verir (ekrandan, 02:20:00). NumPy'da olmayan istatistiksel işlevler çoğu zaman SciPy'da bulunur.

### 11.6 Atama, kopya ve görünüm (view)

Python'da (ve NumPy'da) diziler Java'daki gibi nesnedir. Bir nesneyi başka bir değişkene atamak yalnızca referansı kopyalar. `b = a` dendiğinde `b`, `a` nesnesine yeni bir referans olur; `a` değişince `b`, `b` değişince `a` da değişir. Gerçek bir kopya için `np.copy(a)` ya da `a.copy()` kullanılır; bunlar bellekte ayrı yer ayırıp yeni nesneye referans döndürür.

`h = a.view()` ise aynı veriye yeni bir **görünüm** verir, yeni matris oluşturmaz. Hoca tahtada büyük bir matrisin içinde küçük bir bölge çizerek açıkladı: Yalnızca bu bölgeyle çalışmak istiyorsak bölgeye bir görünüm oluşturabiliriz ve NumPy bundan sonra onu ayrı bir matris gibi kullanmamıza izin verir; `h[0,0]` bölgenin köşesini gösterir. Bellekte kopyalama yapılmadığı için hızlıdır.

NumPy mümkün olduğunca veri kopyalamaktan kaçınır, çünkü en yavaş iş veri kopyalamaktır. Örneğin `a.T` ile transpoz almak da bir görünümdür: alttaki veri hiç değişmez, yalnızca erişime yardım eden bilgiler (ör. `a.strides`, kabaca satır uzunluğu gibi düşünülebilir) değişir. NumPy 10 boyutlu verilerle bile çalışabildiği için orada satır-sütun yerine 0. boyut, 1. boyut demek daha doğrudur. Sıralama için `a.sort()` ve `c.sort(axis=0)` kullanılır.

### 11.7 Eleman seçme ve dilimleme

Cheat sheet'teki örnekler (ekrandan, 02:25:00):

| İfade | Sonuç | Açıklama |
|---|---|---|
| `a[2]` | `3` | 2 numaralı eleman (0, 1, 2) |
| `b[1,2]` | `6.0` | 1. satır, 2. sütun |
| `a[0:2]` | `array([1, 2])` | 0 ve 1 numaralı elemanlar |
| `b[0:2,1]` | `array([2., 5.])` | 0-1. satırların 1. sütunu |
| `b[:1]` | `array([[1.5, 2., 3.]])` | 0. satırdaki bütün elemanlar |
| `c[1,...]` | `[[3., 2., 1.], [4., 5., 6.]]` | `c[1,:,:]` ile aynı |
| `a[::-1]` | `array([3, 2, 1])` | Ters çevrilmiş dizi |
| `a[a<2]` | `array([1])` | Boole indeksleme |

Çok boyutlu bir dizide tek indeks kullanılırsa bir alt dizi döner: iki boyutlu `b` için `b[0]` ilk satırı olduğu gibi verir; üç boyutlu bir dizide `c[1]` bir matris verir. Buna dikkat etmek gerekir.

**Dilimleme (slicing)** çok faydalıdır. `0:2` "0'dan 2'ye kadar" demektir, ama Python'da **son yazılan indis dahil edilmez**; yani 0. ve 1. elemanlar gelir, 2. gelmez. MATLAB'da son eleman da dahildir. Baştaki değer yazılmazsa 0, sondaki yazılmazsa "sona kadar" anlamına gelir.

Üç nokta (`...`) operatörünü hoca ilk kez gördüğünü söyledi; anlamı "geri kalan bütün boyutların hepsini al"dır. Hoca NumPy dizilerini iç içe diziler gibi düşünmeyi önerdi: ilk indeks en dıştaki diziyi, ikincisi bir içtekini, üçüncüsü onun içindekini seçer. `c[1,...]` en dıştaki 1 numaralı elemanı ve onun içindeki her şeyi getirir.

Hoca ayrıca Spyder gibi ortamlarda bir komut satırı olmasının bu tür denemeleri çok kolaylaştırdığını söyledi: dilimlemenin nasıl çalıştığından emin olmadığınızda hemen deneyip görebilirsiniz.

### 11.8 Fancy indeksleme

Cheat sheet'teki iki örnek (ekrandan, 02:30:00):

```python
>>> b[[1, 0, 1, 0], [0, 1, 2, 0]]
array([ 4. ,  2. ,  6. ,  1.5])
>>> b[[1, 0, 1, 0]][:, [0, 1, 2, 0]]
array([[ 4. ,  5. ,  6. ,  4. ],
       [ 1.5,  2. ,  3. ,  1.5],
       [ 4. ,  5. ,  6. ,  4. ],
       [ 1.5,  2. ,  3. ,  1.5]])
```

İlki (1,0), (0,1), (1,2), (0,0) konumlarındaki elemanları seçer ve **tek boyutlu bir dizi** döndürür: birden fazla belirli elemanı tek adımda seçmenin yolu budur.

İkincisi ilk bakışta benzer, ama sonuç bir matristir. Önce `b[[1,0,1,0]]` satırları sırasıyla 1, 0, 1, 0 olarak seçer (satırlar tekrar edebilir) ve bir matris döndürür. Dönen matrisin üzerinde indekslemeye devam edilir: `[:, [0,1,2,0]]` bütün satırları ve 0, 1, 2, 0 numaralı sütunları alır (0. sütun tekrar eder). Böylece satır ve sütunların bir alt kümesi 4×4'lük bir matris olarak elde edilir.

### 11.9 Dizi düzenleme (array manipulation)

Cheat sheet'teki komutlar (ekrandan, 02:35:00):

- **Transpoz:** `np.transpose(b)` ya da `i.T`.
- **Şekil değiştirme:** `b.ravel()` kaç boyutlu olursa olsun diziyi satır satır yan yana koyarak tek boyutlu yapar. `g.reshape(3,-2)` veriyi değiştirmeden yeni bir şekil verir. Hoca buradaki `-2`'nin anlamını tam anlayamadığını, `reshape` belgelerine bakılabileceğini söyledi.
- **Eleman ekleme/çıkarma:** `h.resize((2,6))`, `np.append(h,g)`, `np.insert(a, 1, 5)`, `np.delete(a,[1])`.
- **Birleştirme:** `np.concatenate((a,d),axis=0)` → `array([1, 2, 3, 10, 15, 20])`; `np.vstack((a,b))` dizileri alt alta (satır olarak) dizer; `np.hstack((e,f))` yan yana (sütun olarak) dizer.
- **Bölme:** Diziler yatay ve dikey olarak da bölünebilir (`hsplit`, `vsplit`).

> **Ek bilgi (derste anlatılmadı):** `reshape` belgelerine göre boyutlardan biri `-1` verilebilir; NumPy o boyutu eleman sayısından kendisi hesaplar. `g` 6 elemanlı olduğundan `g.reshape(3,-1)` 3×2'lik bir dizi verir. Ajanın denediği NumPy 2.3.5 sürümünde `g.reshape(3,-2)` de aynı 3×2 sonucu verdi; ancak belgelenmiş kullanım `-1`'dir.

### 11.10 Bellek düzeni ve yeniden boyutlandırma

Hoca NumPy dizilerinin C dizilerine benzediğini anlattı: bellekte bölünmemiş tek bir alan kaplarlar ve içlerindeki bütün elemanlar aynı türdendir (ör. hepsi tamsayı). Python listeleri ise bellekte tek bir alan olmayabilir; içinde başka listeler ve başka nesnelere referanslar olabilir, her türden şey konabilir. NumPy'ın bu tasarımı hız ve optimizasyon içindir; örneğin `min` çağrıldığında arka planda C kütüphaneleri çalışır.

Bunun bir sonucu şudur: **yeniden boyutlandırma pahalıdır.** Bir diziye satır eklemek istediğinizde, bellekte o bölgenin hemen arkasında yeterli yer yoksa, eski dizi ile yeni satırın birlikte sığacağı büyük bir alan bulunmalı ve eski içerik tek tek oraya kopyalanmalıdır.

> **Hocanın vurgusu:** `resize` ve `append` gibi işlemlerden kaçının; mecbur kalırsanız ya da hız önemli değilse kullanabilirsiniz. Doğru yol, işin başında kaç satır ve sütun gerektiğini hesaplamak, diziyi bir kerede oluşturmak ve sonra içini satır satır doldurmaktır. `vstack`, `hstack` ve `concatenate` de aynı nedenle hız için önerilmez.

## 12. Uygulama: Spyder'da İmge Açmak

Dersin sonunda hoca kurduğu Python ortamında (conda) Spyder editörünü açtı. Visual Studio Code ile kod yazmayı daha çok sevdiğini, ama yazılanı çalıştırıp denemek için Spyder'ın daha iyi olduğunu söyledi. `demo1.py` adlı bir dosya oluşturuldu.

Adımlar şöyle ilerledi:

1. Önce `import cv2` yazılıp OpenCV'nin kurulu olup olmadığı denendi. Hata çıkmadı; emin olmak için `print('done')` eklendi ve "done" yazdırıldı.
2. TIFF formatı daha karmaşık olabildiği için klasördeki `pcb.tif` yerine daha basit bir BMP dosyası seçildi: `f = cv2.imread('LennaTrue.bmp')`.
3. Spyder'ın konsolunda `f.shape` yazıldı ve `(480, 512, 3)` sonucu alındı: 480 satır, 512 sütun ve 3 kanal (ekrandan, 02:45:00). Hoca bu tür hızlı denemeler için komut satırının bilim insanlarınca çok sevildiğini söyledi.
4. `cv2.imshow('title', f)` ile gösterilmeye çalışıldı. Pencere hemen açılıp kapandı. Ardından `cv2.waitKey(0)` ve `cv2.destroyAllWindows()` eklenince imge göründü; bir tuşa basınca pencere kapandı.
5. Aynı imge Matplotlib ile `plt.imshow` kullanılarak Spyder'ın "Plots" bölmesinde gösterildi. Renk çubuğu (colorbar) ve `hot` renk haritası kullanıldığı için renkler gri seviyeden farklı göründü.

Hocanın özeti: NumPy matrisi elde edildikten sonra gerisi tamamen NumPy işidir.

Derste denenen kodun bir araya getirilmiş hâli (karelerden ve anlatımdan derlendi):

```python
import cv2
import matplotlib.pyplot as plt

f = cv2.imread('LennaTrue.bmp')
print('done')
print(f.shape)          # (480, 512, 3)

cv2.imshow('title', f)
cv2.waitKey(0)
cv2.destroyAllWindows()

l = f[:,:,0]
plt.imshow(l, cmap='hot')
plt.colorbar()
plt.show()
```

<!-- BELİRSİZ: Matplotlib bölümünün Spyder'da yazılan tam satırları karelerde görünmüyor; bölüm slayttaki koda ve anlatıma göre derlendi. -->

## Örnek Sorular

**Soru 1** (ekrandan, 01:10:00): Aşağıdaki 3×4'lük gri seviye imge veriliyor. `A[0,0]` ve `A[0,1]` nedir? Hangi piksel siyah, hangisi beyaz gösterilir?

$$A = \begin{bmatrix} 0 & 3 & 8 & 6 \\ 7 & 12 & 200 & 255 \\ 1 & 8 & 12 & 5 \end{bmatrix}$$

> **Çözüm (derste verildi):** İndeksleme 0'dan başlar ve önce satır yazılır. `A[0,0]` = 0, `A[0,1]` = 3. 0 değerli piksel siyah, 255 değerli piksel (0'dan sayarak 1. satır, 3. sütun) beyaz gösterilir.

**Soru 2** (derste sözlü, 01:33:36): Renkli bir imge `f` için `f[:,:,0]` ne verir?

> **Çözüm (derste verildi):** 0 numaralı kanaldaki bütün satırları ve bütün sütunları alır. Sonuç tek kanallı, gri seviye bir imgedir.

**Soru 3** (derste sözlü, 01:14:57): Alfa kanalında hangi değer tam saydamdır?

> **Çözüm (derste verildi):** 0 tam saydam, en büyük değer (8 bitte 255) opaktır.

**Soru 4** (ekrandan, 02:05:00): `b = np.array([(1.5,2,3), (4,5,6)])` için `b.min(axis=0)` ve `b.min(axis=1)` ne döndürür?

> **Çözüm (derste kısmen verildi, python ile doğrulandı):** axis 0 satırlar boyunca aşağı doğru ilerler, yani sütun başına en küçük değer alınır: `b.min(axis=0)` → `[1.5, 2, 3]`. `b.min(axis=1)` her satırın en küçüğünü verir: `[1.5, 4]`.

**Soru 5** (ekrandan, 02:15:00): `a` dizisinde 2'den küçük bütün elemanlara döngü kullanmadan 0 atayın.

> **Çözüm (derste verildi):** `a[a < 2] = 0`. `a < 2` Boole bir maske üretir; `True` olan konumlara 0 atanır. Döngüyle yazılan sürümden çok daha hızlıdır.

**Soru 6** (ekrandan, 02:30:00): `b = np.array([(1.5,2,3), (4,5,6)])` için `b[[1,0,1,0],[0,1,2,0]]` ile `b[[1,0,1,0]][:,[0,1,2,0]]` arasındaki fark nedir?

> **Çözüm (derste verildi, python ile doğrulandı):** İlki (1,0), (0,1), (1,2), (0,0) elemanlarını tek boyutlu dizi olarak verir: `[4, 2, 6, 1.5]`. İkincisi önce 1, 0, 1, 0 numaralı satırları seçip bir matris oluşturur, sonra bu matrisin 0, 1, 2, 0 numaralı sütunlarını alır ve 4×4'lük bir matris döndürür: `[[4,5,6,4],[1.5,2,3,1.5],[4,5,6,4],[1.5,2,3,1.5]]`.

**Soru 7** (ekrandan, 02:45:00): `cv2.imread` ile okunan imge için `f.shape` → `(480, 512, 3)` çıktı. Bu ne anlama gelir?

> **Çözüm (derste verildi):** İmge 480 satır, 512 sütun ve 3 kanaldan oluşur.

**Soru 8** (ekrandan, 02:35:00): `g = a - b` 2×3'lük bir dizidir. `g.reshape(3,-2)` ne yapar?

> **Çözüm (derste verilmedi):** Veriyi değiştirmeden diziyi 3×2 şekline sokar. Negatif boyut "bu boyutu kendin hesapla" anlamına gelir; belgelenmiş kullanım `-1`'dir. Ajanın NumPy 2.3.5 ile denemesinde sonuç `[[-0.5, 0], [0, -3], [-3, -3]]` çıktı.

## Dersin Toparlaması

Bu derste önce dersin kaynakları gözden geçirildi: Szeliski'nin kitabı, James Hays'in slaytları, derin öğrenme tarafı için CS231n ve Justin Johnson'ın dersi, Bengio'nun *Deep Learning* kitabı ve imge işleme temeli için Gonzalez. Ardından bilgisayarla görme, makine öğrenmesinin görsel veriye uygulanması olarak tanımlandı. Karakter ve yüz tanımadan medikal görüntülemeye, artırılmış gerçeklikten endüstriyel robotlara kadar uygulama alanları gezildi. Derin öğrenmenin alanı nasıl dönüştürdüğü, imge büyütme gibi klasik işleri bile üstlendiği vurgulandı.

İkinci yarıda "imgelerle çalışma" konusuna geçildi. Gri seviye imgenin bir matris, renkli imgenin kanallardan oluşan üç boyutlu bir dizi olduğu, değerlerin 8 bitte 0-255 aralığında geldiği ama işlem için 0-1 aralığında gerçel sayılara normalize edilmesi gerektiği anlatıldı. Python'da OpenCV ve Pillow ile okuma, OpenCV ve Matplotlib ile gösterme, renk haritaları, `imwrite` ile yazma ve kayıpsız format tercihi işlendi. Son olarak NumPy cheat sheet'i üzerinden dizi oluşturma, eleman eleman işlemler, Boole maskeleri, görünüm ve kopya, dilimleme ve fancy indeksleme gözden geçirildi ve Spyder'da bir imge okunup gösterildi. Bundan sonraki konular (kameralar ve optik, imge filtreleme) bu NumPy temeli üzerine kurulacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
