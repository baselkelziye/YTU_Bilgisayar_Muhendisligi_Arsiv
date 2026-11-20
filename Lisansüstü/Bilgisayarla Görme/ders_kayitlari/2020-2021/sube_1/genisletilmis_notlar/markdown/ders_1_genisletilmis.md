# Ders 1 Genişletilmiş Notu: Derse Giriş, Kaynaklar ve Python Çalışma Ortamının Kurulumu

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Bilgisayarla Görme Nedir?
- 2. Kaynak Kitaplar ve Öğrenme Çıktıları
- 3. Dersin Konu Akışı
- 4. Programlama Dili ve Geliştirme Ortamı
- 5. Miniconda ve Conda Ortamları
- 6. Canlı Demo: Ortam Oluşturma ve Paket Kurma
- 7. pip, conda ve requirements.txt
- 8. Kurulan Paketler Ne İşe Yarar?
- 9. Çalışma Ortamları ve Donanım
- Örnek Sorular
- Dersin Toparlaması

## 1. Bilgisayarla Görme Nedir?

Dersin ilk haftası, ekle-sil dönemi sürdüğü için konu anlatımına geçilmeden dersin çerçevesini ve çalışma ortamının kurulmasını konu aldı. Hoca dersin amacını tek cümleyle özetledi: bilgisayarlara çevreyi nasıl gösteririz, çevreyi onlara nasıl algılatırız?

Dersin Bologna sayfasındaki amaç metni bu fikri şöyle açar (ekrandan, 00:10:00): Görme, fiziksel bir temasa gerek duymadan çevremizle etkileşim kurmamızı sağlayan en güçlü duyumuzdur. Görme yoluyla nesnelerin şeklini, durumunu ve birbirleriyle olan ilişkilerini öğrenebiliriz. Derste bu duyunun yeteneklerinin bilgisayarlara kazandırılması için ihtiyaç duyulan yöntemler incelenir.

Hoca bu amaçla ilişkili alanları da saydı:

- Bilgisayarda görüntülerin işlenmesi (görüntü işleme).
- Bilgisayar yoluyla yeni görüntülerin oluşturulması.
- İki boyutlu görüntülerden üç boyutlu algılama, yani derinlik bilgisinin çıkarılması.
- Nesnelerin takibi.

Bologna sayfasındaki ders içeriği ise kısaca şöyledir (ekrandan, 00:10:00): görüntü oluşturma ve algılama, görüntü işleme, kenar belirleme, yansıma haritası ve fotometrik stereo.

## 2. Kaynak Kitaplar ve Öğrenme Çıktıları

### 2.1 Kaynak kitaplar

Bologna sayfasında üç kitap yer alır (ekrandan, 00:10:00):

- Rafael C. Gonzalez, Richard E. Woods, *Digital Image Processing*, Pearson International Edition, 2008.
- Emanuele Trucco, Alessandro Verri, *Introductory Techniques for 3-D Computer Vision*, Prentice Hall, 1998.
- Richard Szeliski, *Computer Vision: Algorithms and Applications*, Springer, 2011.

Haftalık okumalar Szeliski'nin kitabından verilir. Hoca bu kitabın yazarın kendi web sitesinde ücretsiz PDF olarak bulunduğunu söyledi ve hemen edinilmesini istedi. Diğer iki kitap da iyi kitaplardır; "şu yöntem nasıl çalışıyor" diye bir şeyi merak edince başvurulacak yardımcı kaynaklar olarak elde bulunmaları tavsiye edildi.

> **Hocanın vurgusu:** Szeliski'nin kitabını hemen edinin; okumalar bu kitaptan.

### 2.2 Öğrenme çıktıları

Ders sonunda öğrencilerden beklenenler (ekrandan, 00:10:00):

- Görme duyusunun yeteneklerinin bilgisayarlara kazandırılması için ihtiyaç duyulan yöntemleri öğrenmek.
- Görüntü işlemenin temellerini öğrenmek.
- İki boyutlu görüntü üzerinden derinlik bilgisinin çıkarılmasını öğrenmek.
- Görüntü üzerinde ilgi noktalarının tespiti konusunda bilgi sahibi olmak.
- İlgi noktalarından tanımlayıcıların (descriptor) kullanılması ve eşleştirilmesi konusunda bilgi sahibi olmak.

## 3. Dersin Konu Akışı

Bologna sayfasındaki haftalık konular, dersin yaklaşık akışını verir. İlk haftalar şöyle başlar (ekrandan, 00:10:00): bilgisayarla görmeye giriş ve diğer alanlarla ilişkiler; görüntü oluşturma ve algılama (perspektif projeksiyon, mercekler, parlaklık, renklerin algılanması, görüntü nicemleme); ikili (binary) görüntüler ve geometrik özellikler (alan, konum, yönelim, projeksiyonlar); ikili görüntülerde topolojik özellikler ve bileşen etiketleme; bölütleme (segmentation) ve eşik tabanlı yöntemler.

Hoca bu dersi daha önce de verdiğini, kendi işlediği sıranın biraz farklı olduğunu söyleyerek önceki yılın haftalık klasör yapısını gösterdi. Bu yapı, Szeliski'deki okuma bölümleriyle birlikte şöyledir (ekrandan, 00:20:00):

| Konu | Szeliski okuması |
|---|---|
| Görüntü filtreleme (image filtering) | 3.2 |
| Frekans uzayında düşünme | 3.4 |
| Frekans uzayında düşünme, 2. kısım | 3.5.2 ve 8.1.1 |
| Kenar bulma (edge detection) | 4.2 |
| İlgi noktaları ve köşeler | 4.1.1 |
| Yerel görüntü özellikleri | 4.1.2 |
| Özellik eşleştirme ve gürbüz uydurma | 4.1 |
| Model uydurma ve RANSAC | 6.1 ve 2.1 |
| Kamera kalibrasyonu | 6.2.1 |
| Epipolar geometri ve hareketten yapı (structure from motion) | 7 |

Bu listeden önce, ikinci haftadan itibaren görüntülerin nasıl açıldığı, piksellere nasıl erişildiği ve görüntü yapıları anlatılır.

Hoca listenin kesin olmadığını vurguladı. Bilgisayarla görme hızla değişen bir alan olduğu için bu yıl daha hızlı ilerleyip son haftalara sinir ağlarını eklemek istiyor. Bunun için frekans konuları ile kamera kalibrasyonu ve epipolar geometri kısaltılabilir ya da atlanabilir. Hoca son yıllarda özellikle üretici modellere (generative models) ilgi duyduğunu söyledi: Generative Adversarial Network (GAN) gibi ağlarla gerçekçi nesneler ve görüntüler oluşturulabilir.

Derslerin yapısı da şöyle planlandı: önce bir iki saat konu anlatımı, ardından laboratuvar tarzında birlikte uygulama. Önceki yıllarda bu uygulamalarda Python ile görüntülerin açılması ve filtrelenmesi gibi işler yapılmıştı.

## 4. Programlama Dili ve Geliştirme Ortamı

### 4.1 Neden Python?

Hoca derste Python'u tercih ettiğini, örnek çözerken Python kullanacağını söyledi. İleride PyTorch anlatılırsa o da Python ile olacaktır. Bazı öğrenciler ödevlerini Julia veya MATLAB ile yapmak isteyebilir; bu mümkündür, ama dersteki demoları anlamak Python ile daha kolay olur.

Hocanın tahtaya çizdiği şema bu ilişkiyi gösterir (ekrandan, 00:50:00): solda Python, PyTorch ve IDE; sağda IDE seçenekleri olarak VS Code, Spyder (yuvarlak içine alınmış), Jupyter Notebook ve PyCharm.

### 4.2 IDE seçimi

Kullanılacak IDE (Integrated Development Environment) fark etmez. Hocanın değerlendirmeleri:

- **Spyder:** Anaconda dağıtımıyla gelir. Hocanın Python için tercihidir. MATLAB'dan gelen etkileşimli bir komut satırı vardır: komut önce orada hızlıca denenir, çalışınca asıl koda eklenir.
- **Jupyter Notebook:** Güzeldir, ama küçük ekranda kod göstermek ve ders anlatmak rahat değildir.
- **VS Code:** Hoca başka dillerde kullanıp çok beğeniyor.
- **PyCharm:** JetBrains'in IDE'si; çok beğenilen, iyi bir editördür. Benzer bir komut satırı vardır ama hocanın hatırladığı kadarıyla Spyder'ınki kadar rahat değildir.

**Soru:** PyCharm kullanmanın bir kısıtı var mı? Bu işler için pek kullanılmıyor ama çok güzel bir IDE. **Cevap:** Kısıt yok; seçim size kalmış. Programlama dili programlama dilidir, her IDE ile yazılabilir. Spyder'ı tercih etme nedeni yukarıdaki etkileşimli komut satırı alışkanlığıdır.

## 5. Miniconda ve Conda Ortamları

### 5.1 Anaconda yerine Miniconda

Hoca tam Anaconda dağıtımının indirilmemesini tavsiye etti. Tam dağıtım, gerekli gereksiz her şeyi indirir; hocanın tahtaya yazdığı değer yaklaşık 600 MB'tır (ekrandan, 01:20:00). Bunun yerine Miniconda kurulur. Miniconda'nın belge sayfasındaki tanıma göre Miniconda, conda için ücretsiz ve küçük bir kurulum programıdır; yalnız conda, Python, bunların bağımlı olduğu paketler ve pip, zlib gibi az sayıda yararlı paket içerir; ek paketler `conda install` komutuyla Anaconda deposundan kurulur (ekrandan, 01:00:00).

İndirme sayfasında Python 3.8 ve Python 2.7 sürümleri vardır (ekrandan, 01:00:00). Hoca Python 3'ün indirilmesini istedi, çünkü Python 2 tarihe karışmaktadır. Windows 64 bit Python 3.8 kurulum dosyası 55.7 MiB'tır.

Miniconda kurulunca komut satırından kullanılan `conda` aracı gelir. `conda install` ile yalnız listelenen paketler indirilir; aynı komut kurulu paketleri günceller de.

> **Hocanın vurgusu:** Büyük Anaconda dağıtımıyla değil, Miniconda ve conda aracıyla çalışın.

### 5.2 Ortam (environment) kavramı

Conda ile çalışırken ortamların öğrenilmesi gerekir. Diyelim ki bir proje PyTorch ile çalışıyor ve PyTorch belirli bir Python sürümünü istiyor; başka bir proje TensorFlow ile çalışıyor ve o da başka bir Python sürümü istiyor. Bu durumda iki ayrı ortam kurulur: biri PyTorch için, biri TensorFlow için (ekrandan, 00:55:00). Her ortamın paketleri kendi içine kurulur, birbirine karışmaz. Hoca bunu Python'daki pip paket yöneticisiyle karşılaştırdı: conda da benzer şekilde paket yönetir, ama ortamları da yönetir.

## 6. Canlı Demo: Ortam Oluşturma ve Paket Kurma

### 6.1 Kurulum belgesi

Hoca önceki yıllardan kalma "Installing Python" adlı bir belgeyi paylaştı ve derste güncelledi. Belgedeki adımlar şunlardır (ekrandan, 01:25:00):

- Miniconda'yı indirip kurun: `https://conda.io/miniconda.html`.
- Başlat menüsünde `cmd` yazarak komut satırını açın.
- Geliştireceğiniz proje için bir conda ortamı oluşturun: `conda create -n opencv1 python=3.6`.
- Ortamı etkinleştirin: Windows'ta `activate pytorchenv`; Linux satırı belgede boş bırakıldı.
- `conda install numpy matplotlib opencv pillow scikit-learn scikit-image jupyter scipy` yazıp Enter'a basın.
- Conda paketleri indirip kurar; artık hazırsınız.
- Komut satırında `jupyter notebook` yazın.
- Tarayıcı penceresinde New / Python 3'e tıklayıp belgedeki görüntüdeki kodu yazın, `Alt+Enter` ya da Run düğmesiyle çalıştırın.

Belgedeki bu son test kodu, Örnek Sorular bölümünde ele alınmıştır.

### 6.2 Ortam oluşturma

Hoca demoyu kendi bilgisayarında yaptı: `cd` ile belgeler klasörüne gidip `mkdir temp` ile geçici bir klasör açtı. İlk denemede ortam adını `-n` bayrağı olmadan yazınca conda "target prefix is the base prefix" benzeri bir hata verdi. Bir öğrenci ortam adının `-n` (name) ile verilmesi gerektiğini hatırlattı.

Conda'nın ortam yönetimi belgesi ekranda şu biçimleri gösterir (ekrandan, 01:05:00):

```text
conda create --name myenv              # ortam oluşturma
conda create -n myenv python=3.6       # belirli Python sürümüyle
conda create -n myenv scipy            # belirli bir paketle
conda create -n myenv python           # ya da: önce ortam,
conda install -n myenv scipy           #        sonra pakete kurulum
```

Ortam `/envs/` klasörü altında oluşur; paket belirtilmezse içine paket kurulmaz. Conda kurulumdan önce indirilecek ve kurulacak paketleri listeler ve `Proceed ([y]/n)?` diye onay ister.

Hoca `conda create -n project1 python=3.5` komutunu çalıştırdı (ekrandan, 01:05:00). Conda Python 3.5.6'yı ve onunla uyumlu `pip`, `setuptools`, `wheel`, `certifi` gibi temel paketleri indirdi. Hocanın vurguladığı nokta şudur: conda paketleri rastgele indirmez; seçilen Python sürümüyle uyumlu sürümleri seçer. Örneğin PyTorch yalnız Python 3.5 ile çalışıyorsa, ortam 3.5 ile kurulur ve diğer paketler buna göre gelir. Diğer paketlerin sürümü de benzer şekilde yazılabilir.

İndirme yavaş kaldığı için hoca kurulumu durdurup ortamı başka bir adla yeniden kurdu. İkinci kurulum daha hızlıydı, çünkü conda daha önce indirdiği paketleri önbellekte (cache) tutar.

### 6.3 Ortamı etkinleştirme ve kapatma

Birden fazla ortam olabildiği için, kurulan ortama geçmek gerekir. Windows'ta conda bunun için `activate` komutunu kurar; hoca kendi bilgisayarındaki ortamı `activate pytorchenv` ile etkinleştirdi ve komut satırının başında ortam adı `(pytorchenv)` olarak görünmeye başladı (ekrandan, 01:10:00). Derste yeni sürümde komutların `conda activate` ve `conda deactivate` olduğu da görüldü. Ortamdan çıkmak için `deactivate` (yeni sürümde `conda deactivate`) yazılır; komut satırını kapatmadan normal çalışmaya dönülür.

Ortam etkinken kurulan bütün paketler o ortamın içine kurulur. Hoca etkin ortamda `mkdir project1` ve `cd project1` ile proje klasörü açtı (ekrandan, 01:10:00), sonra paket listesini `conda install` ile kurdu. Bu komut çalışırken conda yine uzun bir paket listesi gösterip onay istedi (ekrandan, 01:20:00).

> **Ek bilgi (derste anlatılmadı):** Hoca Linux'taki komutu bilen var mı diye sordu ama cevap gelmedi. Conda'nın büyük olasılıkla 4.4 ve sonraki sürümlerinde Windows, Linux ve macOS'ta aynı komutlar kullanılır: `conda activate <ortam>` ve `conda deactivate`. Eski conda sürümlerinde Linux ve macOS'ta büyük olasılıkla `source activate <ortam>` kullanılıyordu.

Hoca Linux'ta çalışmayı tavsiye etti: Python araçları Linux'ta daha iyi çalışır. Ama bu dersin konuları için fark olmaması gerekir, çünkü Python, conda ve OpenCV taşınabilir paketlerdir; Windows'ta da sorun yoktur.

### 6.4 Editörün doğru ortamı kullanması

Hangi editör kullanılırsa kullanılsın, kurulan ortamı tanıması gerekir. Spyder ortam etkinken komut satırından başlatılırsa o ortamın Python'unu kullanır; Spyder açılışta hangi ortamın Python'unu kullandığını yazar. Bu yöntemin kötü yanı arkada bir komut satırı penceresinin açık kalmasıdır. Windows'ta Anaconda başlat menüsü klasöründe, Spyder'ın sistemdeki ortamlar için oluşturduğu kısayollar da vardır; bunlar arkada komut satırı bırakmadan açılır.

> **Hocanın vurgusu:** Hangi editörü kullanırsanız kullanın, doğru ortamı açmanız gerekir.

## 7. pip, conda ve requirements.txt

Hoca öğrencilere conda'nın neden pip yerine tavsiye edildiğini sordu. Bir öğrencinin açıklaması ve hocanın onayıyla şu sonuca varıldı: sanal ortam etkinken pip ile kurulan paketler de o ortamın içine gider. Fark kaynaktadır: conda önce Anaconda'nın kendi deposuna bakar, paket orada varsa oradan kurar; pip'in baktığı PyPI deposu daha geneldir.

Web projelerinde genellikle pip ile çalışılır ve projenin gerektirdiği paketler `requirements.txt` adlı bir dosyaya yazılır. Proje başkasıyla paylaşılırken bu dosya da gönderilir; alan kişi tek komutla aynı paketleri kurar ve herkes aynı ortamı kolayca elde eder. Hoca bunun conda ile nasıl yapılacağını derste denedi ama sonuca ulaşamadı; bir öğrenci sohbete conda ile `requirements.txt` kullanmak için tek satırlık bir betik paylaştı. <!-- BELİRSİZ: öğrencinin paylaştığı tek satırlık betiğin içeriği altyazıda ve karelerde yok. --> Derste paketler en sonunda tek komutta tek tek sıralanarak kuruldu.

> **Ders sonrası not:** Hoca "pip install requirements text" dedi; doğru komut `pip install -r requirements.txt` biçimindedir. `-r` bayrağı olmadan pip, `requirements.txt` adlı bir paket arar.

> **Ek bilgi (derste anlatılmadı):** Conda'da benzer iş için büyük olasılıkla `conda list --export > requirements.txt` ile ortamdaki paket listesi dosyaya yazılır, `conda install --file requirements.txt` ya da `conda create -n <ortam> --file requirements.txt` ile bu dosyadan kurulum yapılır. Bütün ortamı taşımak için `conda env export > environment.yml` ve `conda env create -f environment.yml` de kullanılır. Hocanın derste ekranda baktığı "conda list ... requirements" komutu büyük olasılıkla bu dışa aktarma biçimiydi.

## 8. Kurulan Paketler Ne İşe Yarar?

Bir öğrencinin isteği üzerine hoca kurulan paketleri kısaca anlattı:

- **NumPy:** Standart Python'da matrislerle, daha doğrusu çok boyutlu dizilerle çalışmayı sağlar. Matris iki boyutludur; NumPy'ın `ndarray` yapısı ise 3, 4, 5, hatta 10 boyutlu dizilerle çalışabilir.
- **Matplotlib:** Çok popüler bir grafik çizme ve görselleştirme aracıdır; 2 ve 3 boyutlu grafikler çizer.
- **OpenCV:** Çok popüler ve çok hızlı çalışan bir görüntü işleme ve bilgisayarla görme kütüphanesidir. C++, Java, C#, Python gibi birçok dil için bağlantısı (binding) vardır; derste kurulan, Python bağlantısıdır. Görüntüleri açmak, göstermek ve içeriklerini değiştirmek için kullanılabilir.
- **Pillow:** Görüntü açan bir pakettir. Asıl gücü JPEG, Bitmap (BMP), PNG, TIFF gibi çok sayıda görüntü biçimini açabilmesidir.
- **Jupyter:** Web tarayıcısında çalışan bir geliştirme ortamı verir. Kodlama sırasında belge de yazılabilir: açıklama, altında kod, sonra yine açıklama ve kod. Açıklamalar Markdown ile yazılır. Bir eğitim materyali hazırlamak için çok uygundur: okuyan kişi kodu kendisi çalıştırıp küçük parçalarını değiştirerek dener.
- **scikit-learn, scikit-image, SciPy:** Listede kurulan diğer paketlerdir; derste ayrıca anlatılmadı.

> **Ders sonrası not:** Hoca OpenCV'nin Intel tarafından geliştirildiğini hatırladığını söyledi. OpenCV büyük olasılıkla Intel'de başlatılmış, sonradan açık kaynak topluluğu ve OpenCV.org tarafından sürdürülmüştür. Ayrıca hoca Pillow'un NumPy dizisi verdiğini söyledi; Pillow görüntüyü kendi `Image` nesnesi olarak açar, bu nesne `np.array(img)` ile NumPy dizisine çevrilir.

## 9. Çalışma Ortamları ve Donanım

### 9.1 Seçenekler

Hoca belgeye öğrencilerin önerileriyle bir "Working envs" bölümü ekledi (ekrandan, 01:35:00):

- Kendi yerel bilgisayarınız.
- `colab.research.google.com` (Google Colab).
- Kaggle.
- Databricks.
- Google Cloud: belgeye "Free $100 credit" ve "Stop the virtual machine while not working. It eats your credits even if you do nothing." yazıldı.

Google Colab, kendi makinesi zayıf olanlar için tarayıcıda çalışan bir Jupyter Notebook ortamı verir; orada kod geliştirilebilir ve paylaşılabilir, oturum 12 saat kadar açık kalabilir. Google Cloud'da öğrencilere kredi verilir; ancak açılan sanal makine, üzerinde bir şey çalıştırılmasa bile açık kaldığı sürece krediden düşer. Bu yüzden iş bitince sanal makine durdurulmalıdır.

> **Ders sonrası not:** Hoca sözlü olarak "300 dolar" dedi, belgeye 100 dolar yazdı. Google Cloud'un yeni hesaplara verdiği deneme kredisi o dönemde büyük olasılıkla 300 dolardı; öğrenci programlarının kredisi farklı olabilir.

### 9.2 GPU ihtiyacı

Dersin büyük kısmında klasik bilgisayarla görme yapılacağı için GPU gerekmez. Sinir ağlarına girildiğinde ise GPU hız açısından çok fark ettirir. Çok büyük ağları eğitmek ciddi, çok pahalı donanım ister; Colab bile bunun için çok güçlü sayılmaz. Bu yüzden derste küçük ağları eğitmeyi öğrenip ardından hazır (önceden eğitilmiş) ağları kullanmak üzerinde durulması planlanıyor.

**Soru:** Üniversitenin öğrenciler için uzak sunucu hizmeti var mı? **Cevap:** Colab gibi bir hizmet yok. Ancak TÜBİTAK'ın TRUBA (TR-Grid) sistemi var: Türkiye'deki araştırmacılara GPU içeren hesaplama hizmeti verir, öğrenciler de kaydolabilir. Hoca, TRUBA'nın makine öğrenmesi ve derin öğrenme için kullanımının bir proje konusu bile olabileceğini söyledi.

## Örnek Sorular

**1. Jupyter Notebook test kodu** (ekrandan, 01:05:00 ve 01:25:00)

Kurulum belgesinin son adımı, yeni bir Jupyter defterinde aşağıdaki kodun yazılıp çalıştırılmasıdır. Kodun çıktısı ne olur?

```python
import numpy as np

a = np.array([[1,2,3],[4,5,6]])
b = np.array([[0.1,0.2,0.3]]).T
c = a.dot(b)
print(a)
print(b)
print(c)
```

<!-- BELİRSİZ: `b` satırı karelerde küçük ve kısmen kapalı; `[[0.1,0.2,0.3]]).T` biçimi ve belgede görünen çıktının ilk iki dizisiyle tutarlı. -->

> **Çözüm (derste verilmedi):** `a` 2×3 bir matristir. `b`, 1×3 satır vektörünün devriğidir, yani 3×1 sütun vektörüdür. `a.dot(b)` matris çarpımıdır ve sonuç 2×1 olur: ilk satır $1\cdot0.1 + 2\cdot0.2 + 3\cdot0.3 = 1.4$, ikinci satır $4\cdot0.1 + 5\cdot0.2 + 6\cdot0.3 = 3.2$. Python ile çalıştırılan çıktı:
>
> ```text
> [[1 2 3]
>  [4 5 6]]
> [[0.1]
>  [0.2]
>  [0.3]]
> [[1.4]
>  [3.2]]
> ```
>
> Belgedeki çıktı görüntüsünde de `[[1 2 3] [4 5 6]]` ve `[[0.1] [0.2] [0.3]]` görünür (ekrandan, 01:05:00).

**2. Neden pip yerine conda tavsiye ediyoruz?** (derste sözlü, 01:13:43)

> **Cevap (derste bir öğrenci verdi, hoca onayladı):** Ortam etkinken ikisi de aynı ortama kurar; fark paket kaynağıdır. Conda önce Anaconda'nın kendi deposuna bakar, pip daha genel olan PyPI deposuna bakar. Conda ayrıca ortamları ve Python sürümünü de yönetir, seçilen Python sürümüyle uyumlu paket sürümlerini kurar.

**3. `conda create proje1` neden hata verdi?** (derste sözlü, 01:02:49)

> **Cevap (derste verildi):** Ortam adı `-n` (`--name`) bayrağıyla verilmelidir: `conda create -n proje1`. Bayrak olmadan ad, ortam adı olarak yorumlanmaz ve conda hedefin temel (base) ortam olduğunu söyleyen bir hata verir.

## Dersin Toparlaması

Bu ilk derste bilgisayarla görmenin amacı, yani görme duyusunun yeteneklerini bilgisayarlara kazandırmak tanımlandı. Ders görüntü işlemenin temellerinden başlayıp filtreleme, frekans uzayı, kenar bulma, ilgi noktaları ve tanımlayıcılar, eşleştirme ve RANSAC üzerinden kamera kalibrasyonu ve epipolar geometriye ilerleyecek; bu yıl sonlara sinir ağları ve üretici modeller eklenecek. Ana okuma kaynağı Szeliski'nin *Computer Vision: Algorithms and Applications* kitabıdır.

Dersin ikinci yarısında uygulamaların yapılacağı Python ortamı kuruldu: Miniconda kurulumu, `conda create -n` ile projeye özel ortam açma, ortamı etkinleştirme, `conda install` ile NumPy, Matplotlib, OpenCV, Pillow, scikit-learn, scikit-image, Jupyter ve SciPy paketlerinin kurulması, editörün doğru ortamı kullanması ve pip ile conda arasındaki fark. Sonraki haftalarda bu ortamda görüntülerin açılması ve piksellerine erişimle konu anlatımına geçilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
