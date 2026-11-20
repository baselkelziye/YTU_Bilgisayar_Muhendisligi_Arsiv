# Ders 1 Çalışma Özeti

## Genel Konular

- Bilgisayarla görmenin amacı ve kapsamı
  - Temel amaç, bilgisayarların çevreyi görme yoluyla algılamasını sağlamaktır. Görme, fiziksel temas gerektirmeden çevreyle etkileşim kurmamızı sağlayan en güçlü duyudur; nesnelerin şekli, durumu ve birbirleriyle ilişkileri görme yoluyla öğrenilir (ekrandan, 00:10:00).
  - İlgili alanlar: bilgisayarda görüntülerin işlenmesi, bilgisayarla yeni görüntülerin oluşturulması, iki boyutlu görüntülerden üç boyutlu algılama (derinlik çıkarma) ve nesne takibi.
  - Ders içeriği (Bologna sayfası): görüntü oluşturma ve algılama, görüntü işleme, kenar belirleme, yansıma haritası ve fotometrik stereo (ekrandan, 00:10:00).
- Kaynak kitaplar (ekrandan, 00:10:00)
  - Rafael C. Gonzalez, Richard E. Woods, *Digital Image Processing*, Pearson, 2008.
  - Emanuele Trucco, Alessandro Verri, *Introductory Techniques for 3-D Computer Vision*, Prentice Hall, 1998.
  - Richard Szeliski, *Computer Vision: Algorithms and Applications*, Springer, 2011. Okumalar bu kitaptan verilir; yazarın kendi sitesinde ücretsiz PDF olarak bulunur.
- Öğrenme çıktıları (ekrandan, 00:10:00)
  - Görme duyusunun yeteneklerini bilgisayarlara kazandırmak için gereken yöntemler.
  - Görüntü işlemenin temelleri.
  - İki boyutlu görüntüden derinlik bilgisinin çıkarılması.
  - Görüntüde ilgi noktalarının tespiti.
  - İlgi noktalarından tanımlayıcıların (descriptor) çıkarılması ve eşleştirilmesi.
- Dersin konu akışı (önceki yılın klasör yapısından, ekrandan, 00:20:00)
  - Giriş; görüntülerin açılması, piksellere erişim ve görüntü yapıları.
  - Görüntü filtreleme (Szeliski 3.2); frekans uzayında düşünme (Szeliski 3.4, 3.5.2 ve 8.1.1).
  - Kenar bulma (Szeliski 4.2); ilgi noktaları ve köşeler (4.1.1); yerel görüntü özellikleri (4.1.2).
  - Özellik eşleştirme ve gürbüz uydurma (4.1); model uydurma ve RANSAC (6.1 ve 2.1).
  - Kamera kalibrasyonu (6.2.1); epipolar geometri ve hareketten yapı (structure from motion, Szeliski 7).
  - Liste kesin değildir: frekans konuları ile kamera kalibrasyonu/epipolar geometri kısaltılıp sinir ağlarına (özellikle üretici modeller, GAN) yer açılması planlanmaktadır.
- Programlama dili ve geliştirme ortamı
  - Derste Python kullanılır; ileride PyTorch da Python ile anlatılacaktır. Julia veya MATLAB da kullanılabilir ama ders demolarını izlemek Python ile daha kolaydır.
  - IDE seçenekleri: Spyder (hocanın tercihi), Jupyter Notebook, VS Code, PyCharm (ekrandan, 00:50:00).
- Miniconda, conda ve ortamlar (environment)
  - Tam Anaconda dağıtımı yaklaşık 600 MB indirir (ekrandan, 01:20:00); Miniconda yalnız conda, Python ve az sayıda temel paketle gelir, gerekli paketler sonradan kurulur.
  - Her proje için ayrı conda ortamı kurulur; böylece örneğin PyTorch ve TensorFlow'un farklı Python sürümü istekleri birbirine karışmaz.
  - Kurulum adımları ekrandaki "Installing Python" belgesinde verildi (ekrandan, 01:25:00).
- Kurulan paketler ve görevleri
  - NumPy: çok boyutlu dizilerle (ndarray) çalışma.
  - Matplotlib: 2B ve 3B grafik çizimi, görselleştirme.
  - OpenCV: hızlı, yaygın bir görüntü işleme ve bilgisayarla görme kütüphanesi; C++, Java, C#, Python gibi dillerden kullanılabilir.
  - Pillow: JPEG, BMP, PNG, TIFF gibi birçok görüntü biçimini açar.
  - scikit-learn, scikit-image, SciPy ve Jupyter.
- Çalışma ortamları (ekrandan, 01:35:00)
  - Yerel bilgisayar, Google Colab, Kaggle, Databricks, Google Cloud.
  - Dersin büyük kısmı klasik bilgisayarla görme olduğundan GPU gerekmez; sinir ağlarına geçildiğinde GPU hız açısından büyük fark yaratır.
  - TÜBİTAK'ın TRUBA (TR-Grid) sistemi, Türkiye'deki araştırmacılara GPU içeren hesaplama hizmeti sunar.

## Hocanın Özellikle Vurguladığı Kısımlar

- Szeliski'nin kitabı hemen edinilmeli
  - Haftalık okumalar bu kitabın bölümlerinden verilir; diğer iki kitap bir yöntemi merak edince bakılacak yardımcı kaynaklardır.
- Tam Anaconda yerine Miniconda ve conda
  - Tam dağıtım gerekli gereksiz her şeyi indirir; Miniconda ile yalnız ihtiyaç duyulan paketler kurulur. `conda install` aynı zamanda paketleri günceller.
- Conda ortamlarını öğrenmek
  - Farklı projeler farklı Python ve paket sürümleri isteyebilir; her biri için ayrı ortam açılır. Bilmeyenlerin web'den öğrenmesi tavsiye edildi.
- Editör doğru ortamı kullanmalı
  - Hangi editör kullanılırsa kullanılsın, kurulan ortamın Python'u ile açılması gerekir. Spyder ortam aktifken komut satırından başlatılırsa o ortamı kullanır.
- Linux tavsiyesi
  - Python araçları Linux'ta daha iyi çalışır; ancak Python, conda ve OpenCV taşınabilir olduğundan Windows'ta da sorun yoktur.
- Bulut sanal makinesi
  - Google Cloud'da açılan sanal makine, üzerinde iş çalışmasa bile açık kaldıkça krediden düşer; işi bitince kapatılmalıdır.

## Kısa Tekrar Notları

- Bilgisayarla görme: bilgisayara çevreyi görme yoluyla algılatma; görüntü işleme, görüntü üretme, 2B'den 3B algılama, nesne takibi.
- Ana okuma kaynağı: Szeliski, *Computer Vision: Algorithms and Applications* (ücretsiz PDF).
- Konular: filtreleme, frekans uzayı, kenar bulma, ilgi noktaları, yerel özellikler, eşleştirme, RANSAC, kamera kalibrasyonu, epipolar geometri; sonra sinir ağları ve üretici modeller.
- Miniconda kur, her proje için ortam aç:
  - `conda create -n opencv1 python=3.6`
  - Windows'ta eski komut `activate <ortam>`, yeni sürümlerde `conda activate <ortam>` ve `conda deactivate`.
  - `conda install numpy matplotlib opencv pillow scikit-learn scikit-image jupyter scipy`
- `conda create`'te ortam adı `-n` (`--name`) ile verilir; `-n` unutulursa conda hata verir.
- pip ve conda paketleri farklı depolardan alır: conda Anaconda deposuna, pip PyPI'ye bakar.
- `requirements.txt`: projenin paket listesi; pip ile `pip install -r requirements.txt` şeklinde kurulur.
- GPU yalnız sinir ağı aşamasında gerekir; Colab, Kaggle, Google Cloud, TRUBA seçeneklerdir.

## Detaylı Açıklamalar

- **Dersin çerçevesi.** Bilgisayarla görme, insanın görme duyusunun yeteneklerini bilgisayarlara kazandırmayı amaçlar. Bu, görüntü işlemenin temellerinden başlar (görüntüleri açmak, piksellerine erişmek, filtrelemek), kenar ve ilgi noktası bulmaya, bu noktalardan tanımlayıcı çıkarıp farklı görüntüler arasında eşleştirmeye, model uydurma ve RANSAC ile gürbüz kestirime, oradan kamera kalibrasyonu ve epipolar geometri ile iki boyutlu görüntülerden üç boyutlu bilgi çıkarmaya uzanır. Hoca bu yıl derin öğrenmeye, özellikle üretici modellere (Generative Adversarial Network gibi, gerçekçi görüntüler oluşturabilen ağlar) yer açmak istediğini, bu yüzden frekans uzayı ve kamera geometrisi konularının kısalabileceğini söyledi. Ders anlatımının ardından Python ile görüntü açma, filtreleme gibi uygulamaların birlikte yapılması planlandı.
- **Python ve araç seçimi.** Hoca derste Python kullanacağını, demoların Python ile olacağını söyledi. Spyder'ı tercih etme nedeni MATLAB'dan gelen etkileşimli komut satırıdır: komut önce orada hızlıca denenir, çalışınca koda eklenir. Jupyter Notebook belge ve kodu iç içe yazmaya (Markdown açıklama, altında kod hücresi) uygundur; eğitim materyali hazırlamak için iyidir ama küçük ekranda ders anlatmak için rahat değildir. PyCharm da güçlü bir editördür; seçim kişiye kalmıştır.
- **Miniconda ve conda ortamları.** Miniconda kurulunca `conda` aracı gelir. Önerilen akış: önce proje için ortam oluşturulur (`conda create -n opencv1 python=3.6`), sonra ortam etkinleştirilir, ardından paketler kurulur. Conda istenen Python sürümüyle uyumlu paket sürümlerini seçer, ne indireceğini ve kuracağını listeleyip onay ister (`Proceed ([y]/n)?`). Derste `conda create -n project1 python=3.5` komutuyla Python 3.5'li bir ortam kurulduğu görüldü (ekrandan, 01:05:00). Bir ortam etkinken kurulan paketler yalnız o ortama gider, diğer ortamlardaki paketlerle karışmaz.
- **pip ile conda farkı.** Bir öğrencinin açıklamasıyla: ortam etkinken pip de paketleri aynı ortama kurar; fark kaynaktadır. Conda önce Anaconda'nın kendi deposuna bakar, pip ise daha genel olan PyPI deposuna. Web projelerinde genelde pip ve `requirements.txt` kullanılır: proje paylaşılırken bu dosya da gönderilir ve herkes aynı ortamı tek komutla kurar.
- **Çalışma ortamları ve donanım.** Kendi bilgisayarı zayıf olanlar Google Colab'ı (tarayıcıda Jupyter Notebook, oturum yaklaşık 12 saat açık kalabilir) kullanabilir. Büyük ağları eğitmek çok güçlü donanım ister; derste küçük ağları eğitmek ve hazır ağları kullanmak üzerinde durulacaktır.

> **Ders sonrası not:** Hoca Google Cloud için sözlü olarak "300 dolar" dedi, ekrandaki belgeye "Free $100 credit" yazdı (ekrandan, 01:35:00). Google Cloud'un yeni hesaplara verdiği deneme kredisi o dönemde büyük olasılıkla 300 dolardı; öğrenci programlarının kredisi farklı olabilir.

> **Ders sonrası not:** Hoca dosyadaki paketleri kurmak için "pip install requirements text" dedi; doğru komut `pip install -r requirements.txt` biçimindedir (`-r` bayrağı olmadan pip, `requirements.txt` adlı bir paket arar).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
