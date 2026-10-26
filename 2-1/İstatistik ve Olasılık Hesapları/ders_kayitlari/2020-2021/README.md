# İstatistik ve Olasılık Hesapları Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.

### 📋 Genel Bilgiler
* **Ders:** İstatistik ve Olasılık Hesapları (BLM2011)
* **Hoca:** Dr. Oğuz Altun
* **Dönem:** Güz
* **Akademik Yıl:** 2020-2021
* **Şube:** BLM2011 - 2

Bu dizin, ilgili ders kayıtlarının altyazı özetlerini, çalışma notlarını ve PDF kaynaklarını içermektedir.

## 📚 Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu, kaynak markdown dosyası ve doğrudan indirilebilir PDF formatındaki derlenmiş halleri listelenmiştir. Ders numaraları, kayıt arşivindeki ders kaydı sıra numaralarıdır (hafta numarası değildir).

| Ders No | Ders İçeriği / Konu Başlıkları | Kaynak Notlar (Markdown) | Çalışma Dosyası (PDF) |
| :---: | :--- | :---: | :---: |
| **Ders 1** | Tanışma, Dersin İşleyişi, Olasılığın Yorumları, Küme Teorisi ve Fonksiyonlar | [Özet](altyazi_ozetleri/ders_1_ozet.md) | [PDF (İndir)](ders_1_ozet.pdf) |
| **Ders 2** | Sayılabilir Kümeler, Kuvvet Kümesi, Olasılık Aksiyomları ve Temel Olasılık Kuralları | [Özet](altyazi_ozetleri/ders_2_ozet.md) | [PDF (İndir)](ders_2_ozet.pdf) |
| **Ders 3** | Birleşim Kuralı, Sürekli Uzaylar, Şartlı Olasılık, Bağımsızlık ve Toplam Olasılık Kuralı | [Özet](altyazi_ozetleri/ders_3_ozet.md) | [PDF (İndir)](ders_3_ozet.pdf) |
| **Ders 4** | Bayes Kuralı, Zincir Kuralı, Güvenilirlik ve Sayma Yöntemleri | [Özet](altyazi_ozetleri/ders_4_ozet.md) | [PDF (İndir)](ders_4_ozet.pdf) |
| **Ders 5** | Kesikli Rastgele Değişkenler, PMF ve CDF, Beklenen Değer, Varyans, Kovaryans ve Korelasyon | [Özet](altyazi_ozetleri/ders_5_ozet.md) | [PDF (İndir)](ders_5_ozet.pdf) |
| **Ders 6** | Birleşik Dağılım Örneği, Chebyshev Eşitsizliği, Bernoulli ve Binom Dağılımları | [Özet](altyazi_ozetleri/ders_6_ozet.md) | [PDF (İndir)](ders_6_ozet.pdf) |
| **Ders 7** | Vize Oturumu (Kısa Kayıt) | [Özet](altyazi_ozetleri/ders_7_ozet.md) | [PDF (İndir)](ders_7_ozet.pdf) |
| **Ders 8** | Geometrik, Negatif Binom ve Poisson Dağılımları; Sürekli Dağılımlar: Düzgün, Üstel, Gama ve Normal | [Özet](altyazi_ozetleri/ders_8_ozet.md) | [PDF (İndir)](ders_8_ozet.pdf) |
| **Ders 9** | Merkezi Limit Teoremi, Süreklilik Düzeltmesi ve İstatistiğe Giriş: Örneklem Ortalaması, Medyan ve Kantiller | [Özet](altyazi_ozetleri/ders_9_ozet.md) | [PDF (İndir)](ders_9_ozet.pdf) |
| **Ders 10** | Çeyrekler, Örneklem Varyansı, Standart Hata, IQR ile Aykırı Değerler ve Histogram | [Özet](altyazi_ozetleri/ders_10_ozet.md) | [PDF (İndir)](ders_10_ozet.pdf) |
| **Ders 11** | İkinci Vize Oturumu (Konu Anlatımı Yok) | [Özet](altyazi_ozetleri/ders_11_ozet.md) | [PDF (İndir)](ders_11_ozet.pdf) |
| **Ders 12** | Histogram Şekilleri, Kutu, Saçılım ve Zaman Grafikleri; Momentler ve En Çok Olabilirlik Yöntemleri | [Özet](altyazi_ozetleri/ders_12_ozet.md) | [PDF (İndir)](ders_12_ozet.pdf) |
| **Ders 13** | Standart Hatanın Tahmini, Güven Aralıkları ve Final Bilgilendirmesi | [Özet](altyazi_ozetleri/ders_13_ozet.md) | [PDF (İndir)](ders_13_ozet.pdf) |

> [!NOTE]
> Bu şubede ders İngilizce anlatılmıştır. 7 ve 11 numaralı kayıtlar vize oturumlarıdır. 29 Ekim 2020 haftası Cumhuriyet Bayramı'dır.

## 🎯 Derslerin Detaylı Özetleri ve Kazanımları

### 🔹 Ders 1: Tanışma, Dersin İşleyişi, Olasılığın Yorumları, Küme Teorisi ve Fonksiyonlar
* **Genel Konular:**
  - Dersin tarihi 8 Ekim 2020 Perşembe. Ders Zoom üzerinden, İngilizce yapıldı.
    - Asıl ders yaklaşık 05:00'te başlar. İlk dakikalar selamlaşma ve bekleme kısmıdır.
  - Dersin işleyişi
    - Ofis saati: Çarşamba 15:00-17:00. Bu saatler uymazsa e-posta ile ya da Calendly üzerinden görüşme talebi gönderilebilir.
  - Kaynak kitaplar
    - Michael Baron, *Probability and Statistics for Computer Scientists*, 2. baskı.
  - Dönem planı (taslak)
    - Giriş ve olasılığa giriş.
  - Olasılığa giriş ve olasılığın iki yorumu
  - Küme teorisi tekrarı (sets)
  - Fonksiyonlar (functions), kardinalite (cardinality), sonlu ve sonsuz kümeler
* **Hocanın Vurgusu:**
  - Hoca slayt, PPT veya ders notu paylaşmayacak.
    - Kâğıt kalem alın ve kendi notunuzu tutun. Hoca bunu dersin sonunda Türkçe olarak da tekrarladı.
  - Not dağılımı: 2 quiz toplam 20 puan, vize 40 puan, final 40 puan.
    - Quiz tarihleri önceden belli değil. Quizden önce duyurulacak.
  - İngilizce okuyup anlayabilmelisiniz.
    - Öğrenilecek şeylerin çoğu önce İngilizce çıkıyor. Matematik kitabını okuyamıyorsanız İngilizceye ayrıca zaman ayırın.
  - Olasılık problemlerinde ilk iş örneklem uzayını (sample space) yazmaktır.
  - Olasılıklar kümeler üzerinden hesaplanır.
    - "1'in olasılığı" dediğimizde aslında tek elemanlı $\{1\}$ kümesinin olasılığından bahsediyoruz.

### 🔹 Ders 2: Sayılabilir Kümeler, Kuvvet Kümesi, Olasılık Aksiyomları ve Temel Olasılık Kuralları
* **Genel Konular:**
  - Dersin tarihi 15 Ekim 2020 Perşembe. Ders Zoom üzerinden, İngilizce yapıldı.
    - Asıl ders yaklaşık 05:20'de başlar. İlk dakikalar görüntü ayarı ve bekleme kısmıdır.
  - Dersin işleyişi (tekrar)
    - Ofis saati Çarşamba 15:00-17:00. Uymazsa yarım saatlik Calendly görüşme talebi gönderebilirsiniz.
  - Kümeler konusunun tekrarı
  - Kümelerde yeni kavramlar
    - Fark için $A \setminus B = A \cap B^c$ kuralı.
  - Olasılık teorisine giriş
    - Rastgele deney (random experiment), çıktı (outcome), olay (event), örneklem uzayı (sample space).
  - Olasılık hesaplama kuralları
    - Eşit olasılıklı çıktılar.
* **Hocanın Vurgusu:**
  - USİS e-postasını alamıyorsanız aynı gün YTÜ bilgi işlem birimiyle görüşün.
    - Duyurular bu sistemden yapılacak.
  - Olaylar (events) birer kümedir.
    - Kümelerde öğrendiğimiz her şey (birleşim, kesişim, bölüntü, kapsayan kümeler) olaylar için de geçerlidir.
  - Aksiyomlar çok önemlidir.
    - Bunun iki nedeni var:
  - Şartlı olasılık (conditional probability) da aksiyomlara uyar.
    - Bu yüzden $P(A^c) = 1 - P(A)$ kuralından doğrudan $P(A^c \mid B) = 1 - P(A \mid B)$ yazılabilir. Ayrıca ispat gerekmez.
  - Matematikte ispatlamadığınız bir kuralı kullanamazsınız.
    - Bir kuralı bir kez ispatladıktan sonra o kural "alet çantanıza" girer. Sonraki ispatlarda kullanabilirsiniz.

### 🔹 Ders 3: Birleşim Kuralı, Sürekli Uzaylar, Şartlı Olasılık, Bağımsızlık ve Toplam Olasılık Kuralı
* **Genel Konular:**
  - Dersin tarihi 22 Ekim 2020 Perşembe. Ders Zoom üzerinden yapıldı.
    - Asıl ders yaklaşık 05:00'te başlar.
  - Önceki dersin tekrarı (Türkçe)
    - Üç aksiyom, eşit olasılıklı çıktılar, tümleyen ve boş küme kuralları.
  - Yeni olasılık kuralları
    - Birleşim kuralı (kesişen olaylar için).
  - Sürekli olasılık uzayları (continuous probability spaces) üzerine kısa giriş
  - Şartlı olasılık (conditional probability)
    - Tanım, sezgisel anlamı ve zar örneği.
  - Bağımsızlık (independence)
    - Tanım, uçuş örneğiyle test.
  - Toplam olasılık kuralı (law of total probability)
    - Ev ödevi: üç hileli bozuk para örneği.
* **Hocanın Vurgusu:**
  - Şartlı olasılık formülü önemlidir, mutlaka bilin: $P(A \mid B) = \dfrac{P(A \cap B)}{P(B)}$, $P(B) > 0$.
  - Şartlı olasılık aksiyomlara uyar.
    - Bu yüzden şartlı olasılık bir olasılık ölçüsüdür.
  - Problem çözerken önce modelleyin.
    - Olaylara büyük harfle ad verin. Verilen olasılıkları bu harflerle yazın. Sorulan şeyi bu harflerle yazın.
  - Ayrık (mutually exclusive) ile bağımsız (independent) aynı şey değildir.
    - Ayrık: kesişim boş kümedir. Bu, kümelerle ilgili bir özelliktir.
  - Bağımsızlığı test ederken çoğu zaman çarpım kuralı daha kolaydır.

### 🔹 Ders 4: Bayes Kuralı, Zincir Kuralı, Güvenilirlik ve Sayma Yöntemleri
* **Genel Konular:**
  - Dersin tarihi 5 Kasım 2020 Perşembe. Ders Zoom üzerinden, İngilizce yapıldı.
    - Asıl ders yaklaşık 00:04:50'de başlar.
  - Toplam olasılık kuralı (law of total probability) tekrarı ve torba-madeni para örneği
    - Torbada 3 hileli madeni para var. Yazı (heads) gelme olasılıkları 0.9, 0.6 ve 0.3.
  - Bayes kuralı (Bayes' rule)
    - Şartlı olasılığın tanımından türetildi.
  - Şartlı bağımsızlık (conditional independence)
  - Zincir kuralı (chain rule)
    - İki ve üç olay için yazıldı. Şartlı hâli de gösterildi.
  - Quiz duyurusu ve yeni çevrim içi sınav sistemi denemesi
    - Öğrenciler online.yildiz.edu.tr'de 2 soruluk deneme sınavına girdi. Not verilmedi.
  - Güvenilirlik (reliability) problemleri
    - Yedekli sabit disk örneği.
* **Hocanın Vurgusu:**
  - Bayes kuralı çok önemli.
    - Sınavda neredeyse kesin çıkacak.
  - Olasılık sorusu çözmeden önce olaylara harf verin.
    - Verilenleri ve isteneni bu harflerle denklem olarak yazın.
  - Güvenilirlik sorularında birleşimi doğrudan hesaplamak zordur.
    - Tümleyenden gidin.
  - Formülleri ezberlemek yerine mantığı hatırlayın.
    - Hoca $n^k$ gibi formülleri hatırlamadığını, mantıktan (çarpma ilkesi) yeniden kurduğunu söyledi.
  - Quiz duyurusu:
    - Bir hafta sonra, üçüncü ders saatinde (15:00) yapılacak. En fazla 50 dakika.

### 🔹 Ders 5: Kesikli Rastgele Değişkenler, PMF ve CDF, Beklenen Değer, Varyans, Kovaryans ve Korelasyon
* **Genel Konular:**
  - Dersin tarihi 12 Kasım 2020 Perşembe. Ders Zoom üzerinden, İngilizce yapıldı.
    - Asıl ders yaklaşık 00:05:20'de başlar.
  - Kesikli rastgele değişkenler (discrete random variables)
    - Rastgele değişken, deneyin çıktısını bir sayıya götüren fonksiyondur.
  - Olasılık kütle fonksiyonu (PMF) ve birikimli dağılım fonksiyonu (CDF)
    - PMF ile CDF arasında dönüşüm.
  - Rastgele vektörler (random vectors)
    - Birleşik dağılım (joint distribution) ve marjinal dağılım (marginal distribution).
  - Beklenen değer (expectation)
    - Fonksiyonun beklenen değeri.
  - Varyans (variance) ve standart sapma (standard deviation)
    - Bir öğrencinin isteğiyle bu bölüm Türkçe olarak tekrar anlatıldı.
  - Kovaryans (covariance) ve korelasyon (correlation)
    - Varyans, kovaryans ve korelasyonun özellikleri.
* **Hocanın Vurgusu:**
  - Rastgele değişkenin değeri mutlaka bir sayıdır. "Yağmur" ya da "yazı" olamaz.
  - "Dağılımı bulun" denince PMF ya da CDF istenir.
    - Biri bilinirse diğeri bulunur.
  - PMF yalnızca $R_X$'teki noktalarda sıfırdan farklıdır.
    - CDF ise ilk değerden sonra hiçbir yerde sıfır değildir.
  - $E[XY] = E[X]\,E[Y]$ ve $\mathrm{Var}(X+Y) = \mathrm{Var}(X) + \mathrm{Var}(Y)$ yalnızca bağımsızlık koşuluyla geçerlidir.
    - Formüldeki "eğer"i unutmayın.
  - Beklenen değer, varyans ve kovaryansın alternatif formüllerini evde kendiniz ispatlayın.
    - İnternete bakmadan önce deneyin.

### 🔹 Ders 6: Birleşik Dağılım Örneği, Chebyshev Eşitsizliği, Bernoulli ve Binom Dağılımları
* **Genel Konular:**
  - Dersin tarihi 19 Kasım 2020 Perşembe. Ders Zoom üzerinden, İngilizce yapıldı.
    - Asıl ders yaklaşık 00:02:30'da başlar.
  - Önceki dersin tekrarı
    - PMF, CDF, rastgele vektörler, marjinal dağılım, bağımsızlık, beklenen değer, varyans, kovaryans, korelasyon ve özellikleri.
  - Sayısal örnek: İki modüllü programda hata sayıları
    - Birleşik dağılım tablosu, marjinal dağılımlar, bağımsızlık kontrolü, varyanslar ve korelasyon katsayısı.
  - Vize duyurusu
  - Chebyshev eşitsizliği (Chebyshev's inequality)
    - Yazılımdaki hata sayısı örneği.
  - Yaygın kesikli dağılımlara giriş
    - Bu bölümde görülecek dağılımlar: Bernoulli, binom, geometrik, negatif binom, Poisson.
  - Quiz 1 çözümü (ders sonunda, Türkçe)
* **Hocanın Vurgusu:**
  - Cevap yazma kuralı: Hoca dört aşamalı cevap istiyor.
    - Bu dört aşamayı görmezse puan vermiyor.
  - Bağımsızlık tüm $x, y$ değerleri için sağlanmalı.
    - Bağımsız olmadığını göstermek için tek bir karşı örnek yeter.
  - Chebyshev eşitsizliği her rastgele değişken için geçerlidir.
    - Yalnızca ortalama ve varyans bilindiğinde olasılığa sınır koyar. PMF biliniyorsa daha iyi sonuç alınır.
  - Vize duyurusu:
    - Bir hafta sonra, aynı saatte. Çevrim içi test olarak online.yildiz.edu.tr'de yapılacak.

### 🔹 Ders 7: Vize Oturumu (Kısa Kayıt)
* **Genel Konular:**
  - Dersin tarihi 26 Kasım 2020 Perşembe.
    - Bu kayıt bir ders değildir. Vize sınavı sırasında açılan Zoom oturumunun yaklaşık 4 dakikalık kaydıdır.
  - Vize sırasında yaşanan sorun
    - Hoca ile başka bir kişi (büyük olasılıkla sınava yardım eden bir görevli) sınav sistemiyle ilgili bir sorunu konuşuyor.
* **Hocanın Vurgusu:**
  - Kayıtta derse yönelik bir vurgu yoktur.
  - Hoca, sınavı hazırlamanın zor olduğunu ve yaşanan sorundan dolayı üzüldüğünü söylüyor.

### 🔹 Ders 8: Geometrik, Negatif Binom ve Poisson Dağılımları; Sürekli Dağılımlar: Düzgün, Üstel, Gama ve Normal
* **Genel Konular:**
  - Dersin tarihi 3 Aralık 2020 Perşembe. Ders Zoom üzerinden, İngilizce işlendi.
    - Asıl anlatım yaklaşık 00:03'te başlar. Duyurular Türkçe de tekrarlandı.
  - Kesikli dağılım aileleri (devam)
    - Geometrik dağılım (geometric distribution)
  - Sürekli dağılımlara giriş (continuous distributions)
    - Olasılık yoğunluk fonksiyonu (probability density function, PDF) ve kümülatif dağılım fonksiyonu (CDF)
  - Sürekli dağılım aileleri
    - Düzgün dağılım (uniform distribution) ve standart düzgün dağılım
  - Sınav duyuruları
    - İkinci vize 17 Aralık 2020'de. İkinci quiz sürpriz olacak.
* **Hocanın Vurgusu:**
  - Poisson problemlerinde $\lambda$'yı sorulan zaman aralığına göre ayarlayın.
    - Günde ortalama 10 olay varsa 2 günde $\lambda = 20$ olur. Hoca örneği bu uyarı için seçtiğini söyledi.
  - Kümülatif olasılıkları elle hesaplamak zordur.
    - Baron'un kitabının sonundaki tabloları kullanın: Tablo A3 (Poisson), Tablo A4 (standart normal).
  - Sürekli dağılımda tek bir noktanın olasılığı sıfırdır.
    - Bu yüzden $P(X \le x) = P(X < x)$ olur. Olasılık her zaman bir aralık için sorulur.
  - Kesikli formüllerdeki toplam, sürekli durumda integrale; PMF de yoğunluğa dönüşür.
  - Parçalı tanımlı yoğunlukta integral sınırlarına dikkat edin.
    - Yoğunluğun sıfır olduğu bölgeyi integrale katmayın; alt sınır o bölgenin bittiği yer olur.

### 🔹 Ders 9: Merkezi Limit Teoremi, Süreklilik Düzeltmesi ve İstatistiğe Giriş: Örneklem Ortalaması, Medyan ve Kantiller
* **Genel Konular:**
  - Dersin tarihi 10 Aralık 2020 Perşembe. Ders Zoom üzerinden, İngilizce işlendi.
    - Asıl anlatım yaklaşık 00:06'da başlar. Öğrenci soruları üzerine bazı kısımlar Türkçe tekrar edildi.
  - Merkezi limit teoremi (central limit theorem, CLT)
    - Bağımsız ve özdeş dağılmış (i.i.d.) değişkenlerin toplamı
  - Baron'un kitabında 4. bölüm (sürekli dağılımlar) bitti. Olasılık kısmı tamamlandı.
  - İstatistiğe giriş (Baron, 8. bölüm)
    - Popülasyon (population), parametre, örneklem (sample), örnekleme (sampling)
  - Betimleyici istatistikler (descriptive statistics)
    - Örneklem ortalaması (sample mean): beklenen değeri, varyansı, dağılımı
  - İkinci vize duyurusu (17 Aralık 2020)
* **Hocanın Vurgusu:**
  - CLT pratikte $n \ge 30$ ise kullanılır.
    - Teorem aslında $n \to \infty$ için geçerlidir. Bu yüzden CLT ile yapılan hesap yaklaşık bir hesaptır.
  - Toplanan değişkenler zaten normal ise toplam her $n$ için normaldir. $n < 30$ olsa da normal kabul edilir.
  - Süreklilik düzeltmesi yalnızca kesikli bir dağılımı sürekli bir dağılımla yaklaşık hesaplarken yapılır.
    - Gama (sürekli) normal ile (sürekli) yaklaşık hesaplanırken düzeltme yapılmaz.
  - Tahmin, gerçek parametre değildir.
    - İkisini karıştırmayın.
  - Örnekleme dışı hatayı yok etmek için basit rastgele örnekleme kullanın.
    - Türkiye'deki ağırlıkları ölçmek için yalnızca İstanbul'dan örnek almak yanlıştır.

### 🔹 Ders 10: Çeyrekler, Örneklem Varyansı, Standart Hata, IQR ile Aykırı Değerler ve Histogram
* **Genel Konular:**
  - Dersin tarihi 17 Aralık 2020 Perşembe. Ders Zoom üzerinden, İngilizce işlendi.
    - Kaydın ilk yarım saati quiz oturumudur. Öğrenciler Online YıldızEdu'da 30 dakikalık quiz'e girdi.
  - Önceki dersin tekrarı: örneklem ortalaması, medyan, kantiller
  - Kantillerle ilgili diğer adlar
    - Yüzdelikler (percentiles)
  - Ortalama ve medyana bakarak dağılımın şekli: simetrik, sağa çarpık, sola çarpık
  - Merkezi eğilim ölçüleri (measures of central tendency) ve dayanıklılık (robustness)
  - Yayılım ölçüleri (measures of spread)
    - Örneklem varyansı ve örneklem standart sapması; neden $n-1$'e bölündüğü
  - Grafiksel istatistik
    - Histogram, kutu grafiği (box plot), zaman grafiği (time plot), saçılım grafiği (scatter plot)
* **Hocanın Vurgusu:**
  - Yüzdelik ve çeyrek, kantilin farklı adlarıdır.
    - Şapka ($\hat{\ }$) görürseniz değer örneklemden gelen bir tahmindir.
  - Ortalama aykırı değerlerden medyana göre çok daha fazla etkilenir.
    - Çarpık dağılımda ortalama, kuyruğun uzun olduğu tarafa kayar.
  - Örneklem varyansında $n$ değil, $n-1$'e bölünür.
    - Hoca bunun nedenini merak ettiğini anlattı: $n$ kullanılırsa tahmin edici yanlı olur.
  - İyi bir tahmin edici yansız, tutarlı ve asimptotik normal olmalı.
    - Mümkünse standart hatası da düşük olmalı.
  - Veriyle bir şey yapmadan önce veriyi çizip bakın.
    - Bu öneri Baron'un kitabından geliyor.

### 🔹 Ders 11: İkinci Vize Oturumu (Konu Anlatımı Yok)
* **Genel Konular:**
  - Dersin tarihi 24 Aralık 2020 Perşembe.
  - Bu kayıt bir sınav oturumudur. Konu anlatılmadı.
    - 10. dersin sonunda hoca bu hafta ikinci vizenin yapılacağını duyurmuştu.
  - Kayıttaki duyurular
    - Hoca öğrencilere sınava erişip erişemediklerini sordu. Sınav online.yildiz.edu.tr üzerindeydi.
* **Hocanın Vurgusu:**
  - Bu kayıtta konu anlatımı ve vurgu yok.
  - Sınav çevrim içi sistemde yapıldı.
    - Sorusu olan öğrenciler Zoom'da hocaya ulaşabildi.

### 🔹 Ders 12: Histogram Şekilleri, Kutu, Saçılım ve Zaman Grafikleri; Momentler ve En Çok Olabilirlik Yöntemleri
* **Genel Konular:**
  - Dersin tarihi 31 Aralık 2020 Perşembe. Ders Zoom üzerinden işlendi.
    - Önceki dersin tekrarı Türkçe, geri kalanı İngilizce anlatıldı.
  - Tekrar: histogram ve göreli frekans histogramı
  - Sık görülen histogram şekilleri
    - Düzgün, üstel ve normal görünümlü histogramlar
  - Kutu grafiği (box plot) ve paralel kutu grafikleri
  - Saçılım grafiği (scatter plot): antivirüs örneği
  - Zaman grafiği (time plot): dünya nüfusu örneği
  - Baron'un kitabında 8. bölüm bitti.
* **Hocanın Vurgusu:**
  - Göreli frekans histogramı, gözleme dayalı (empirical) bir olasılık dağılımı verir.
    - Örnek: CPU verisinde bir gözlemin 0–14 aralığında olma olasılığı yaklaşık $1/30$'dur.
  - Histogramın şekli, veriyi üreten dağılım ailesi hakkında fikir verir.
    - Verinin homojen mi yoksa bir karışım mı olduğu da histogramdan görülür.
  - Dağılımın parametresini bulursanız dağılımı bilirsiniz.
    - Sonra ortalama, medyan gibi her şeyi hesaplayabilir, gelecek değerleri tahmin edebilirsiniz.
  - Momentler yöntemi çok kolaydır: kaç bilinmeyen varsa o kadar moment eşitliği yazıp çözün.
  - Momentler yöntemiyle bir kez genel formül çıkarırsanız aynı aileden her veri için tekrar kullanabilirsiniz.

### 🔹 Ders 13: Standart Hatanın Tahmini, Güven Aralıkları ve Final Bilgilendirmesi
* **Genel Konular:**
  - Dersin tarihi 7 Ocak 2021 Perşembe. Dönemin son dersidir. Ders Zoom üzerinden işlendi.
    - Önceki dersin tekrarı Türkçe, yeni konular İngilizce anlatıldı. Final duyuruları Türkçe yapıldı.
  - Tekrar: parametre tahmini, momentler yöntemi, en çok olabilirlik yöntemi
  - Standart hatanın tahmini (estimation of standard errors)
    - Poisson dağılımında $\hat{\lambda} = \bar{X}$ için iki farklı standart hata tahmini
  - Güven aralıkları (confidence intervals)
    - Nokta tahmin edicileri (point estimators) ve aralık tahmini
  - Final sınavı duyuruları ve kitap önerisi
* **Hocanın Vurgusu:**
  - Likelihood'u maksimize etmek için logaritmasını maksimize edin.
    - Çözümler aynı noktada çıkar.
  - İyi bir tahmin edicinin özellikleri: yansız, tutarlı, asimptotik normal ve düşük standart hatalı.
  - Nokta tahminine olasılık atanamaz, çünkü sürekli dağılımda tek bir noktanın olasılığı sıfırdır.
    - Güvenimizi bir olasılıkla ifade etmek için aralık kurulur.
  - Aynı güven düzeyini veren sonsuz sayıda aralık vardır.
    - En iyisi en dar olanıdır.
  - Güven aralığı formülünü kullanmak için iki şart gerekir:
    - Tahmin edici yansız olmalı.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
