# Sayısal Analiz Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.

### 📋 Genel Bilgiler
* **Ders:** Sayısal Analiz (BLM1022)
* **Hoca:** Prof. Dr. Banu Diri
* **Dönem:** Bahar
* **Akademik Yıl:** 2022-2023
* **Şube:** BLM1022 - 1

Bu dizin, ilgili ders kayıtlarının altyazı özetlerini, çalışma notlarını ve PDF kaynaklarını içermektedir.

## 📚 Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu, kaynak markdown dosyası ve doğrudan indirilebilir PDF formatındaki derlenmiş halleri listelenmiştir. Ders numaraları, kayıt arşivindeki ders kaydı sıra numaralarıdır (hafta numarası değildir).

| Ders No | Ders İçeriği / Konu Başlıkları | Kaynak Notlar (Markdown) | Çalışma Dosyası (PDF) |
| :---: | :--- | :---: | :---: |
| **Ders 1** | Sayısal Analize Giriş: Anlamlı Basamak, Kesme-Yuvarlama, Doğruluk-Hassaslık, Hata ve Taylor-Maclaurin Serileri | [Özet](altyazi_ozetleri/ders_1_ozet.md) | [PDF (İndir)](ders_1_ozet.pdf) |
| **Ders 2** | Taylor Serisinin Genelleştirilmesi, Kesme-Bağıl-Mutlak Hata, Ortalama ve Ara Değer Teoremleri, Kök Bulmaya Giriş | [Özet](altyazi_ozetleri/ders_2_ozet.md) | [PDF (İndir)](ders_2_ozet.pdf) |
| **Ders 3** | Kök Bulma Yöntemleri: Grafik, İkiye Bölme, Regula Falsi, Newton-Raphson ve Sekant | [Özet](altyazi_ozetleri/ders_3_ozet.md) | [PDF (İndir)](ders_3_ozet.pdf) |
| **Ders 4** | Tekrarlama (Sabit Nokta) Yöntemi, Matris İşlemleri, Gauss-Jordan ile Ters Alma, Cramer ve Gauss Eliminasyon | [Özet](altyazi_ozetleri/ders_4_ozet.md) | [PDF (İndir)](ders_4_ozet.pdf) |
| **Ders 5** | Cholesky (LU) Yöntemi, Jacobi ve Gauss-Seidel İterasyonu, Doğrusal Olmayan Denklem Takımları ve Sayısal Türev | [Özet](altyazi_ozetleri/ders_5_ozet.md) | [PDF (İndir)](ders_5_ozet.pdf) |
| **Ders 6** | Sayısal İntegral: Trapez (Yamuk) Yöntemi, Simpson 1/3 ve 3/8 Kuralları | [Özet](altyazi_ozetleri/ders_6_ozet.md) | [PDF (İndir)](ders_6_ozet.pdf) |
| **Ders 7** | İntegral Tekrarı ve Alan Problemleri, İki Katlı İntegral, Sonlu Farklar ve Fark Tabloları | [Özet](altyazi_ozetleri/ders_7_ozet.md) | [PDF (İndir)](ders_7_ozet.pdf) |
| **Ders 8** | Sonlu Farklar Tekrarı, Enterpolasyona Giriş: Doğrusal ve Eğrisel Enterpolasyon, Gregory-Newton Enterpolasyonu | [Özet](altyazi_ozetleri/ders_8_ozet.md) | [PDF (İndir)](ders_8_ozet.pdf) |
| **Ders 10** | Gregory-Newton Enterpolasyonu (Genel Hâl ve Değişken Dönüşümü) ve Lagrange Enterpolasyonu | [Özet](altyazi_ozetleri/ders_10_ozet.md) | [PDF (İndir)](ders_10_ozet.pdf) |
| **Ders 11** | Regresyon: En Küçük Kareler, Doğru ve Polinom Uydurma, Doğrusal Olmayan ve Trigonometrik Fonksiyonlar, Çoklu Regresyon | [Özet](altyazi_ozetleri/ders_11_ozet.md) | [PDF (İndir)](ders_11_ozet.pdf) |
| **Ders 12** | Proje Gösterimleri (1. Hafta) ve İkinci Vize Bilgilendirmesi | [Özet](altyazi_ozetleri/ders_12_ozet.md) | [PDF (İndir)](ders_12_ozet.pdf) |
| **Ders 13** | Proje Gösterimleri (2. Hafta) | [Özet](altyazi_ozetleri/ders_13_ozet.md) | [PDF (İndir)](ders_13_ozet.pdf) |
| **Ders 14** | Proje Gösterimleri (Son Hafta) ve Final Sınavı Bilgilendirmesi | [Özet](altyazi_ozetleri/ders_14_ozet.md) | [PDF (İndir)](ders_14_ozet.pdf) |

> [!NOTE]
> 9 numaralı ders kaydı (26 Nisan 2023, birinci vize haftası) kayıt arşivinde bulunmamaktadır.

## 🎯 Derslerin Detaylı Özetleri ve Kazanımları

### 🔹 Ders 1: Sayısal Analize Giriş: Anlamlı Basamak, Kesme-Yuvarlama, Doğruluk-Hassaslık, Hata ve Taylor-Maclaurin Serileri
* **Genel Konular:**
  - Dönemin ilk dersi. 2023 depremi sonrasında dersler Zoom üzerinden uzaktan yapılır.
    - Hoca her hafta bir öğrenciyi sınıf adına cevap veren temsilci olarak seçer, çünkü boşluğa konuşmak zordur ve tam ekrandayken sohbeti okuyamaz.
  - Dersin işleyişi ve değerlendirme
    - Ders zamanında takip edilirse sonradan çok emek gerektirmeyen bir derstir. Dersleri biriktirmek konuları birbirine karıştırır.
  - Dersin konuları
    - Sayısal analizin tanımı, hata türleri, sayıların gösterimi (anlamlı basamak, ondalık basamak, yuvarlama, kesme).
  - İnterpolasyon ile regresyonun farkı
    - İnterpolasyon: hatasız veri noktalarının arasındaki değerleri bulmak için kullanılır. Veriler tablo hâlindedir. Eğri noktaların tam üzerinden geçer. Örnek: analog bir sesten belirli aralıklarla alınan örneklerden sesi yeniden oluşturmak.
  - Sayısal analiz nedir?
    - Bilgisayarların gelişmesi ve mühendislikte kullanılabilir hâle gelmesiyle önem kazanmıştır. Amaç, mühendislik problemlerini kağıt kalem yerine bilgisayarla, daha hızlı ve daha az hatayla çözmektir.
  - Analitik ve sayısal çözüm
    - Analitik çözüm: matematiksel fonksiyonlarla çözüm üretilir, sonuç süreklidir, tek ve kesin bir sonuç bulunur. Karmaşık olmayan problemlerde kullanılır. Karmaşık problemlerde elle çözmek zaman alır ve yanlış yapma olasılığı yüksektir.
  - Sayıların gösterimi
    - Taban 10 (decimal), taban 2 (binary), taban 8 (octal), taban 16 (hexadecimal). Onaltılık sayılar alt seviye programlamada (assembly) kod adım adım izlenirken görülür.
* **Hocanın Vurgusu:**
  - Dersi zamanında takip edin, biriktirmeyin.
    - Formüller tekrar tekrar üzerinden geçildikçe akılda kalır.
  - Algoritma kurmayı öğrenmek için bol kod yazın.
    - Proje kodlarını başkalarından almayın.
  - Sınava kullanmayı bildiğiniz bir hesap makinesiyle girin.
    - İşlem hatası yapmayın.
  - Anlamlı basamak (S) ile ondalık basamak (D) farkını, kesme ile yuvarlamayı iyi öğrenin.
    - Bütün dönem bu terimlerle çalışılacak.
  - Formülleri ezberlemeyin, neden ve nasıl olduğunu öğrenin.
    - Puan için değil, kendiniz için öğrenin.
* **Detaylı Açıklamalar:** Derste tahtada doldurulan tablonun doğru sonuçları ders sonrasında hesaplandı:

### 🔹 Ders 2: Taylor Serisinin Genelleştirilmesi, Kesme-Bağıl-Mutlak Hata, Ortalama ve Ara Değer Teoremleri, Kök Bulmaya Giriş
* **Genel Konular:**
  - Ders önceki haftanın Taylor ve Maclaurin serisi konusuyla devam eder. Ardından kesme hatası, bağıl hata, mutlak hata ve yuvarlama hatası işlenir. İkinci bölüme (doğrusal olmayan denklemler) giriş yapılır: kapalı ve açık yöntemler, ortalama değer teoremi, ara değer teoremi, süreklilik ve iteratif yöntemlerde durma ölçütü.
  - Hoca, dersi derste öğrenmenin ve ezberlemek yerine mantığı anlamanın önemini tekrar vurgular. Sınav soruları derste çözülen örneklerin "şekil değiştirmiş" hâlleridir, çoğu zaman daha basittir. Gelecek derslerde yanınızda kağıt, kalem ve hesap makinesi olsun. Bazı adımları öğrencilerin kendisinin yapması istenecek.
  - Taylor serisinin kapalı (kompakt) gösterimi
    - $f(x) = \sum_{n=0}^{\infty} \frac{f^{(n)}(x_0)}{n!}(x - x_0)^n$. Maclaurin için $x_0 = 0$: $f(x) = \sum_{n=0}^{\infty} \frac{f^{(n)}(0)}{n!} x^n$.
  - Kesme hatası (truncation error)
    - Bir değerin hesaplanması için sonsuz sayıda terim gerekirken sonlu sayıda terim alındığında oluşan hatadır. Belirli bir terimden sonra her yeni terim sonucu çok az değiştirdiği için (2, 2.5, 2.75, 2.77…) seri bir yerde kesilir ve bu hata kabul edilir.
  - Bağıl hata (relative error)
    - $\varepsilon_r = \frac{\text{gerçek} - \text{hesaplanan}}{\text{gerçek}}$. Yüzde olarak da verilir. Problemde istenen hata sınırı (ör. 0.001) çoğunlukla bağıl hata cinsindendir.
  - Mutlak hata (absolute error)
    - Hatanın pozitif veya negatif olmasının önemi yoksa mutlak değer alınır. Hoca bunu bağıl hatanın mutlak değeri olarak anlatır.
  - Yuvarlama hatası (rounding error)
    - Örnek: 27.35254316, 2D yuvarlama: üçüncü basamak 2 (5'ten küçük) olduğu için 27.35. Yuvarlanmış ve gerçek değer arasındaki fark yuvarlama hatasıdır. Öğrencilerle birkaç örnek daha yapıldı.
* **Hocanın Vurgusu:**
  - Bir fonksiyonu seriye açmadan önce sonsuz kez türevlenebilir olduğunu kontrol edin.
  - Türevlerdeki deseni genelleştirin.
    - Böylece $n$. dereceye kadar açılımı terimleri tek tek hesaplamadan yazabilirsiniz.
  - Birimlerle çalışırken yalnızca farka değil, bağıl hataya bakın.
  - Kök aramadan önce fonksiyonun aralıkta sürekli olduğunu ve $f(a) \cdot f(b) < 0$ olduğunu gösterin.
  - Kapalı yöntemler ıraksamaz ama yavaştır.
    - Açık yöntemler hızlıdır ama ıraksayabilir.

### 🔹 Ders 3: Kök Bulma Yöntemleri: Grafik, İkiye Bölme, Regula Falsi, Newton-Raphson ve Sekant
* **Genel Konular:**
  - Ders, doğrusal olmayan denklemlerin kökünü bulma yöntemleriyle devam eder. Önce geçen haftanın kısa bir tekrarı yapılır. Ardından kapalı yöntemler (grafik, ikiye bölme, regula falsi) ve açık yöntemler (Newton-Raphson, sekant) örneklerle anlatılır. Basit iterasyon (sabit nokta) yöntemi gelecek haftaya bırakılır.
  - Tekrar: doğrusal olmayan denklemler ve kök şartı
    - Bilinmeyenin derecesi 1'den büyükse veya denklemde $\sin x$, $e^{3x}$ gibi trigonometrik ya da üstel terimler varsa denklem doğrusal değildir. Örnek: $x^2 + \sin x + e^{3x}$.
  - Durma ölçütleri
    - Gerçek kök genellikle bilinmez. Bu yüzden ardışık iki kök tahmininin mutlak farkına bakılır: $|x_k - x_{k-1}| \le \varepsilon$. Mutlak değer alınır, çünkü fark negatif çıkabilir.
  - Grafik yöntemi (artımlı arama)
    - Bir başlangıç değeri $x_0$ ve bir artım miktarı $\Delta x$ seçilir. $x$, $\Delta x$ kadar artırılarak fonksiyonda yerine konur. Hesaplanan son iki fonksiyon değeri ters işaretli olana kadar devam edilir.
  - İkiye bölme yöntemi (bisection, aralık yarılama)
    - Kapalı aralık yöntemidir. Önce $f(a) \cdot f(b) < 0$ olduğu kontrol edilir.
  - Regula falsi (yanlış nokta) yöntemi
    - İkiye bölmeden farkı: $c$ hesaplanırken yalnızca $a$ ve $b$ değil, $f(a)$ ve $f(b)$ değerleri de kullanılır.
  - Açık yöntemler
    - Bir veya iki başlangıç değeri ile başlanır. Fonksiyon üzerinde çizimler yapılarak (teğet, kiriş) köke yaklaşılır. Kapalı yöntemlerden genellikle daha hızlıdır ama ıraksayabilir.
* **Hocanın Vurgusu:**
  - Dersi derste öğrenin.
    - Bir gece önceden slaytlara bakarsanız yöntemler karışır. Vizeye iki üç yöntemle değil, çok daha fazlasıyla gireceksiniz.
  - Formülleri ezberlemeyin.
    - Hepsi birbirine çok yakındır ve çizimden (benzer üçgen, teğet, kiriş, tanjant alfa) kolayca çıkarılabilir.
  - Kökü aramadan önce mutlaka fonksiyonun aralıkta sürekli olduğunu ve $f(a) \cdot f(b) < 0$ olduğunu kontrol edin.
    - Soruda "kök olduğunu biliyoruz" denmesine güvenmeyin.
  - $\Delta x$ (artım miktarı) ile $\varepsilon$ (hata payı) aynı şey değildir.
  - Vize sorusu: maksimum/minimum sorularında Newton-Raphson'a fonksiyonun kendisi değil türevi girer.
    - Öğrencilerin çoğu bunu yanlış yaptı.
* **Detaylı Açıklamalar:** 7. iterasyonda durulur, kök yaklaşık 0.586'dır. Bu fonksiyon $(x - 3)(x^2 - 4x + 2)$ olarak çarpanlarına ayrılır. $[0, 1]$ aralığındaki gerçek kök $2 - \sqrt{2} \approx 0.585786$'dır. - **Regula falsi'de durma ölçütü:** Slaytta regula falsi için de $\frac{b - a}{2^n} \le \varepsilon$ kullanıldı. Bu ölçüt ikiye bölmeye özgüdür. Regula falsi'de aralık her adımda yarıya inmez. Bu örnekte $b = 3$ hep sabit kaldı. Bu yöntemde ardışık iki $c$ değerinin farkına bakmak daha doğrudur: $|c_k - c_{k-1}| \le \varepsilon$. Bu ölçütle $c_3 = 2.6873$ ve $c_4 = 2.6901$ arasındaki fark 0.0028'dir, 4. adımda durulur. Ayrıca slaytın 4. adımında "0.019542 < 0.01" yazıyor. Bu eşitsizlik yanlıştır, hoca da derste "hatamdan küçük çıkmadı" dedi. Gerçek kök 2.690647'dir, sonuç 2.69 doğrudur. - **Regula falsi'nin hızı:** Regula falsi genellikle ikiye bölmeden hızlıdır ama her zaman değil. Fonksiyon aralıkta çok eğriyse bir uç (bu örnekte $b = 3$) hiç değişmez ve yakınsama yavaşlar. - **Newton-Raphson örneğinin sonu:** Derste $x_2$'den sonrası hesaplanmadı. Devamı: $x_3 = 0.585592$, $x_4 = 0.5857864$, $x_5 = 0.5857864$. $|x_5 - x_4| \approx 2.9 \times 10^{-8} \le 10^{-6}$ olduğu için 5. iterasyonda durulur. Kök 0.585786'dır. İkiye bölmeyle aynı fonksiyon için yalnızca 5 adım gerekir. - **Newton-Raphson'un ıraksadığı durumlar:** $f'(x_k) = 0$ olursa formülde sıfıra bölme olur. Teğet yataydır ve x eksenini kesmez. Türev sıfıra yakınsa yeni değer çok uzağa fırlar. Başlangıç değeri kökten uzaksa veya fonksiyon salınımlıysa yöntem ıraksayabilir. Bu durumda başlangıç değeri değiştirilir. - **Vize sorusunda diğer kök:** Derste "$x_0 = 1.5$ verirsem diğer kökü (3) bulurum" denildi. Hesaplandığında $f(1.5) = -2.25$, $f'(1.5) = -3$, $x_1 = 0.75$ çıkar ve yöntem yine 1'e yakınsar. $f'(x) = 6x - 12$, $x = 2$'de sıfırdır. Bu yüzden 3 kökünü bulmak için başlangıç değeri 2'den büyük seçilmelidir (ör. $x_0 = 2.5$ ile 3'e yakınsar). - **Vize sorusunda maksimum kontrolü:** Bulunan noktanın maksimum mu minimum mu olduğu ikinci türevle de anlaşılır. $V$'nin 4'e bölünmüş hâlinin ikinci türevi $6x - 12$'dir. $x = 1$'de $-6 < 0$ (maksimum), $x = 3$'te $6 > 0$ (minimum). - **Radyan-derece:** Slayttaki "$\sin 5 \to \frac{900}{\pi}$" notu, hesap makinesi derece modundaysa 5 radyanın dereceye çevrilmesidir: $5 \cdot \frac{180}{\pi} = \frac{900}{\pi} \approx 286.48°$. Hesap makinesi radyan modundaysa doğrudan $\sin 5 = -0.9589$ hesaplanır.

### 🔹 Ders 4: Tekrarlama (Sabit Nokta) Yöntemi, Matris İşlemleri, Gauss-Jordan ile Ters Alma, Cramer ve Gauss Eliminasyon
* **Genel Konular:**
  - Duyurular
    - Diğer grubun hocası Ahmet Hoca bir Google Classroom sınıfı açtı ve bu grup da eklendi. İki grubun proje konuları aynıdır. Proje ilanlarını Classroom'dan takip edin.
  - Kısa tekrar: doğrusal olmayan denklemler
    - Kapalı yöntemlerde kök $[a, b]$ aralığındadır ve $f(a) \cdot f(b) < 0$ olmalıdır. Bu yöntemler ıraksamaz ama iterasyon sayısı uzun sürebilir.
  - Tekrarlama (basit iterasyon, sabit nokta) yöntemi (fixed point iteration)
    - Açık yöntemlerin üçüncüsüdür. Kullanışlıdır, iyi sonuç verir. Yalnızca bir uygunluk kontrolü vardır. Kontrol sağlanmazsa işlem uzayabilir.
  - Doğrusal denklem takımlarının çözümü: matris bilgileri
    - Denklem takımları matris biçimine getirilir ve matrisler üzerinde işlemler yapılır: alt/üst üçgen, birim, köşegen veya bant matrise çevirme, ters alma.
  - Elementer (temel) satır işlemleri
    - Genişletilmiş (augmented) katsayılar matrisi: $[A \mid C]$. $AX = C$'de $A$ katsayılar, $X$ bilinmeyenler, $C$ sağ taraf matrisidir. Örnek: $x + 3y - z = 10$, $3x - y + 2z = 5$, $x + 5y - 2z = -3$.
  - Matrisin tersi (Gauss-Jordan ile)
    - $[A \mid I]$ yan yana yazılır. $A$'yı birim matrise çeviren elementer işlemler aynı anda $I$'ya da uygulanır. $A$, $I$'ya dönüştüğünde $I$'nın yerinde $A^{-1}$ oluşur.
  - Doğrusal denklem takımları
    - $n$ bilinmeyen için $n$ denklem gerekir. Katsayılar matrisi kare olmalıdır.
* **Hocanın Vurgusu:**
  - Tekrarlama yönteminde $g(x)$ seçimi en önemli adımdır. $|g'(a)| < 1$ ve $|g'(b)| < 1$ kontrolünü yapmadan başlamayın.
    - Yanlış $g$ ile değerler kökten uzaklaşır.
  - Ardışık farklar giderek büyüyorsa yöntem ıraksıyordur.
    - Başka bir $g$ deneyin.
  - Uç noktalarda şartın sağlanmaması aralığın tamamında sağlanmadığı anlamına gelmez.
    - Aralık içinde başka bir başlangıç noktası arayın.
  - Trigonometrik fonksiyonlarda radyan/derece dönüşümüne dikkat edin.
  - Elementer işlemler sayıları değiştirir ama matrisin bilgisini ve sistemin çözümünü değiştirmez.

### 🔹 Ders 5: Cholesky (LU) Yöntemi, Jacobi ve Gauss-Seidel İterasyonu, Doğrusal Olmayan Denklem Takımları ve Sayısal Türev
* **Genel Konular:**
  - Proje duyuruları
    - Projede istenenleri anlatan belge (kodlanacak algoritmalar, teslim tarihi, projenin not yüzdesi, kontrol zamanı) ve Ahmet Hoca'nın hazırladığı rapor şablonu e-postayla gönderildi.
  - Cholesky (yoğunlaştırılmış yok etme) yöntemi
    - Dolaysız yöntemlerin sonuncusudur. Mantık lineer cebirdekiyle aynıdır.
  - Dolaylı (iteratif) yöntemler
    - Her adımda bir önceki adımda bulunan bilinmeyen değerleri kullanılır. Kabul edilebilir değerlere ulaşılınca durulur.
  - Jacobi iterasyonu
    - $n$ bilinmeyen, $n$ denklem (kare matris).
  - Gauss-Seidel iterasyonu
    - Jacobi ile aynıdır: köşegen en büyük yapılır, her denklemden bir değişken çekilir. Tek fark: her yeni değer hesaplanırken değişkenlerin **en son bulunan** değerleri kullanılır.
  - Doğrusal olmayan denklem takımları (Newton-Raphson ile)
    - İki değişkenli iki denklem: $f(x, y) = 0$, $g(x, y) = 0$.
  - Sayısal türev
    - Türev, bağımlı değişkenin bağımsız değişkene göre değişim miktarıdır. Mühendislikte birçok yasa değişime dayanır: hız konumun zamana göre türevi, ısı geçişi sıcaklık farkındaki değişim, bobin gerilimi akımın zamana göre değişimi, kondansatör akımı gerilimin zamana göre değişimi.
* **Hocanın Vurgusu:**
  - Jacobi ve Gauss-Seidel'de en önemli adım köşegeni maksimum yapmaktır.
    - Bunu unutursanız çözüm yanlış çıkar.
  - Denklemlerin yerini değiştirirken satırın tamamını taşıyın, tek bir terimi değil.
  - Jacobi bir önceki iterasyonun değerlerini, Gauss-Seidel en son bulunan değerleri kullanır.
    - Bütün fark budur.
  - Durma için bütün değişkenlerin farkı $\varepsilon$'dan küçük olmalıdır.
  - Sayısal türevde merkezi farkı tercih edin.
    - Analitik türeve en yakın sonucu verir.

### 🔹 Ders 6: Sayısal İntegral: Trapez (Yamuk) Yöntemi, Simpson 1/3 ve 3/8 Kuralları
* **Genel Konular:**
  - Duyurular
    - Derslikte ses ve kamera düzeni olmadığı için hibrit derste hoca laptopu masaya koyup yine PowerPoint üzerinden anlatacak. Tahtaya yazarsa online bağlananlar göremez.
  - Sayısal integral
    - İntegral, $f(x)$ eğrisi ile $x$ ekseni arasında, $[a, b]$ aralığında kalan alandır. Fonksiyon bu aralıkta sürekli olmalıdır.
  - Trapez (yamuk) yöntemi
    - $[a, b]$ aralığı $n$ eşit parçaya bölünür. Parça genişliği $h = \Delta x = \frac{b - a}{n} = x_{i+1} - x_i$.
  - Simpson 1/3 kuralı
    - Her iki parçadan bir parabol $f(x) = ax^2 + bx + c$ geçirilir.
  - Simpson 3/8 kuralı
    - Fonksiyondan dört noktada kesen kübik bir polinom geçirilir. $[a, b]$ üç eşit parçaya bölünür:
  - Ders planı: gelecek hafta iki katlı integral, ardından farklar.
* **Hocanın Vurgusu:**
  - Simpson'da $n$ mutlaka çift olmalıdır.
  - Alan negatif olamaz.
    - Eksenin altında kalan parçaları ayrı hesaplayıp mutlak değerle toplayın.
  - Alan sorularında önce şekli kabaca çizin: kökleri ve birkaç değeri bulmak yeter.
    - Öğrencilerin en çok takıldığı yer şekli çizememek ve sınırları belirleyememektir.
  - Anlatırken her şey anlaşılmış gibi gelir, ama soruyu kendiniz çözünce takıldığınız yerleri görürsünüz.
    - Derste çözdürmenin amacı budur.
  - Formüller bir iki örnekle akılda kalır: trapezde $h \times$ (uçların yarısı + iç noktalar), Simpson 1/3'te $\frac{h}{3} \times$ (uçlar + 4·tekler + 2·çiftler).

### 🔹 Ders 7: İntegral Tekrarı ve Alan Problemleri, İki Katlı İntegral, Sonlu Farklar ve Fark Tabloları
* **Genel Konular:**
  - Sınav duyuruları (Ahmet Hoca ile birlikte alınan kararlar)
    - İki vize yapılacak. Birinci vize üniversitenin vize haftasında, bayramdan sonra. İki vize de online olacak.
  - Proje soruları hakkında
    - "Her şey sorulmaz." Trigonometrik fonksiyon, üs, karekök gibi hazır fonksiyonlar elbette kullanılabilir. Yalnızca kodlamanız istenen yöntemin kendisini yapan hazır bir kütüphane kullanılamaz.
  - İntegral tekrarı
    - Trapez: alan yamuklara bölünür. $I \approx h\left[\frac{f(a) + f(b)}{2} + \sum f_i\right]$, $h = \frac{b - a}{n}$.
  - Sınıf alıştırması: $y = x^2 - 5x + 4$ parabolü, $y = 4$, $x = 0$, $x = 4$ doğruları ve $Ox$ ekseni ile sınırlı bölgenin alanı (trapez ve Simpson 1/3, $n = 4$).
    - Önce şekil: parabolün kökleri 1 ve 4 (çarpımı 4, toplamı 5). $x = 0$'da $y = 4$.
  - İki katlı integral
    - Örnek: $I = \int_2^3 \int_x^{2x^3} (x^2 + y)\,dy\,dx$, $n = 4$.
  - Sonlu farklar
    - Bir fonksiyon bazen yalnızca ayrık noktalarda bilinir. Örnek: odanın sıcaklığı yalnızca saat 9, 12, 14, 16, 18'de ölçülmüş. Saat 10 veya 17'deki sıcaklığı tahmin etmek için bu noktalardan geçen bir fonksiyon uydurulur. Bu enterpolasyondur.
  - İleri fark tablosu
    - Her sütun bir önceki sütunun ardışık farklarıdır: alttaki değerden üstteki çıkarılır. Sütun sabit bir sayıya ulaşınca (sonraki sütun sıfır olunca) durulur.
* **Hocanın Vurgusu:**
  - Vizeler online ve test.
    - Bir soruda birden fazla doğru cevap olabilir. Testte de kağıt kalem oynatmanız gerekecek.
  - Alan sorularında önce şekli çizin.
    - Bilinen alanları (kare, dikdörtgen) kullanıp integralle hesaplanacak parçaları ekleyip çıkarın.
  - "$Ox$ ekseni ile sınırlı" ifadesine dikkat edin.
  - Simpson 1/3 ve trapezde $n$ gerekir, Simpson 1/3'te $n$ çift olmalıdır.
    - Simpson 3/8'in temel formülünde $n$ kullanılmaz.
  - İki katlı integralde iç integrali bir $g(x)$ "kapalı kutusu" olarak düşünün.

### 🔹 Ders 8: Sonlu Farklar Tekrarı, Enterpolasyona Giriş: Doğrusal ve Eğrisel Enterpolasyon, Gregory-Newton Enterpolasyonu
* **Genel Konular:**
  - Sınav ve takvim duyuruları
    - Birinci vize gelecek hafta, pazartesi saat 17:00'de (hoca "26 Nisan" dedi, ama pazartesi gününe alındığını da söyledi). Çakışan dersleri alan öğrenciler nedeniyle bu güne konulmuş.
  - Sonlu farklar tekrarı
    - İleri fark $\Delta f_i = f_{i+1} - f_i$. $\Delta^2 f_i = f_{i+2} - 2f_{i+1} + f_i$, $\Delta^3 f_i = f_{i+3} - 3f_{i+2} + 3f_{i+1} - f_i$. Katsayılar binom, işaretler artı-eksi. İleri farkta büyük indis başta, $f_i$ sonda.
  - Enterpolasyon
    - Tanım: tablo hâlinde değerleri verilen bir değişkenin tabloda olmayan bir değerini bulmak. Ölçümü yapılmamış bir girdi için çıktıyı tahmin etmek.
  - Doğrusal enterpolasyon (eğim ile)
    - İki noktadan geçen doğru üzerindeki bütün nokta çiftlerinin eğimi eşittir. Bilinen iki noktanın eğimi, bilinmeyen nokta ile bilinen noktalardan birinin eğimine eşitlenir:
  - Doğrusal enterpolasyon (doğru denklemi ile)
    - $F(x) = Ax + B$. Aralığın uçlarında gerçek değerlere eşitlenir: $Aa + B = f(a)$, $Ab + B = f(b)$.
  - Eğrisel (kuadratik) enterpolasyon
    - İkinci dereceden polinom $y = ax^2 + bx + c$ için üç nokta gerekir.
  - Gregory-Newton (ileri fark) enterpolasyonu
    - Eşit aralıklı noktalar için: $F(x) = f_0 + \sum_{i=1}^{n} \binom{k}{i} \Delta^i f_0$, $k = \frac{x - x_0}{h}$.
* **Hocanın Vurgusu:**
  - Vize: test, 15-20 soru, 1 saat ile 1 saat 15 dakika arası.
    - Konular sonlu farklara kadar, enterpolasyon dahil değil.
  - Final klasik.
    - Vizelerde soruları kendi gayretinizle çözün, yoksa finalde bocalarsınız.
  - Eğimle yapılan doğrusal enterpolasyon fonksiyon vermez, yalnızca bir noktadaki değeri tahmin eder.
    - Fonksiyon isteniyorsa doğru denklemi kurulur.
  - Gregory-Newton formülünün nasıl çıkarıldığını bilin, ama asıl gereken son hâlidir. $x_0 = 0$ ve $h = 1$ ise en basit formül kullanılır.
  - Fark tablosunda hangi sütun sabitlenirse polinomun derecesi odur.

### 🔹 Ders 10: Gregory-Newton Enterpolasyonu (Genel Hâl ve Değişken Dönüşümü) ve Lagrange Enterpolasyonu
* **Genel Konular:**
  - Duyurular
    - Birinci vizenin sınıf ortalaması hocanın beklediğinden düşük, diğer grubun ortalaması biraz daha yüksek. İkinci vize de aynı biçimde (online test) olacak. Finalde kağıt kalemi daha hızlı kullanmanız gerekecek.
  - Enterpolasyon tekrarı
    - Bir ölçümde bazı girdilere karşılık çıktılar alınmıştır. Ara girdiler için çıktıyı ölçüm yapmadan tahmin etmek için, verilen noktaları sağlayan bir fonksiyon bulunur. Bu enterpolasyondur. "Ortalama" ile ilgisi yoktur.
  - Doğrusal enterpolasyon (tekrar)
    - Eğim yöntemi: $\frac{f(x_2) - f(x_1)}{x_2 - x_1} = \frac{f(x_3) - f(x_1)}{x_3 - x_1}$. Her yeni nokta için eğimi yeniden yazmak gerekir.
  - Gregory-Newton enterpolasyonu (tekrar ve devam)
    - $F(x) = f_0 + \sum_{i=1}^{n}\binom{k}{i}\Delta^i f_0$, $k = \frac{x - x_0}{h}$.
  - Değişken dönüşümü
    - $x_0 \ne 0$ ve/veya artımlar 1 değilse (hatta eşit değilse) kullanılır. Hoca "en azından finalde mutlaka sorarız" diye vurguladı.
  - Lagrange enterpolasyonu
    - Noktaların aralıklarının eşit olup olmamasının, $x_0$'ın sıfır olup olmamasının hiçbir önemi yoktur.
  - Enterpolasyon özeti
    - Doğru: eğimden veya doğru denkleminden.
* **Hocanın Vurgusu:**
  - Değişken dönüşümü çok önemli, finalde mutlaka sorulur.
  - Fark tablosunun sabitlendiği sütun polinomun derecesini verir.
    - Bulduğunuz derece bununla uyuşmuyorsa hata yapmışsınızdır.
  - Gregory-Newton'un basit formülü yalnızca $x_0 = 0$ ve $h = 1$ ise kullanılır.
  - Lagrange'ta formülü yazarken sırayı karıştırmayın: payda $x - x_j$, paydada $x_i - x_j$, $j \ne i$.
  - Lagrange elle hataya açıktır, çok dikkatli olun.

### 🔹 Ders 11: Regresyon: En Küçük Kareler, Doğru ve Polinom Uydurma, Doğrusal Olmayan ve Trigonometrik Fonksiyonlar, Çoklu Regresyon
* **Genel Konular:**
  - Duyurular
    - Bu, dönemin son konu dersi. Gelecek hafta ikinci vize var, yine online test. Saat, alttan alınan derslerle çakışmaması için değişebilir. OBS ve Classroom üzerinden duyurulacak.
  - Regresyon ve enterpolasyon farkı
    - İkisinde de ölçülen $x$ ve $y$ değerlerinden bir fonksiyon bulunur. Enterpolasyon daha gerçekçi, noktalardan geçen bir fonksiyon bulur. Regresyon daha yaklaşık bir fonksiyon bulur.
  - En küçük kareler yöntemi
    - Her noktada gerçek değer ile uydurulan fonksiyonun değeri arasında bir fark (distance) vardır: $d_i = y_i - F(x_i)$.
  - Doğru uydurma: $F(x) = A + Bx$
    - $S = \sum (y_i - A - Bx_i)^2$. $\frac{\partial S}{\partial A} = 0$ ve $\frac{\partial S}{\partial B} = 0$:
  - Vize sorusu: $y = ax$ doğrusu
    - Sınıfın büyük çoğunluğu bu soruyu çözemedi, çünkü $A + Bx$ matrisini ezberlemişlerdi.
  - Parabol uydurma: $F(x) = A + Bx + Cx^2$
    - Üç bilinmeyen, üç türev:
  - Fonksiyon seçimi
    - Enterpolasyondaki gibi fark tablosu çıkarılır. Hangi dereceden fark sabitlenirse o dereceden polinom uydurulabilir.
* **Hocanın Vurgusu:**
  - En küçük kareler: farkları değil, farkların karelerini toplayın.
    - Artı ve eksi farklar birbirini götürür.
  - Ezberlemeyin.
    - Her soruda $S = \sum(y_i - F(x_i))^2$ yazın ve bilinmeyenlere göre türev alın. $y = ax$ vize sorusunu çoğunuz ezber yüzünden çözemediniz.
  - Doğrusal olmayan fonksiyonu önce logaritma ile doğrusal hâle getirin.
    - Matriste hangi yerine neyi koyduğunuza (ör. $x$ yerine $\ln x$) dikkat edin. Sonunda $a = e^A$ gibi geri dönüşümü unutmayın.
  - Final klasik ve daha uzun işlemli olacak.
  - Projeyi kendiniz kodlayın, sunumda kamera açık olsun.

### 🔹 Ders 12: Proje Gösterimleri (1. Hafta) ve İkinci Vize Bilgilendirmesi
* **Genel Konular:**
  - Bu derste yeni konu işlenmedi. İkinci vizenin olduğu gün ders saati proje gösterimlerine ayrıldı. Kayıt yaklaşık 45 dakikadır.
  - Sınav bilgisi: ikinci vize aynı gün saat 16:00'da, 75 dakika. Yanınızda hesap makinesi, kalem ve silgi olsun. Önceki sorulara geri dönülebilir.
  - Proje gösterimi nasıl yapılıyor?
    - Öğrenci kaç yöntemi kodladığını söyler. Hoca bunlardan bir ya da ikisini seçer, koda kısaca bakar, kendi verdiği girdiyle çalıştırır ve sonucu kendi elindeki çözümle karşılaştırır.
  - Rapor
    - Online Yıldız'daki yükleme alanına aynı gün yüklenecek.
  - Gösterimlerde çalıştırılan örnekler (hocanın kontrol ettiği girdiler)
    - Newton-Raphson: $x^2 - 4x - 5$. $x_0 = 0$ ile kök $-1$, $x_0 = 6$ ile kök $5$ bulundu. Başka bir gösterimde $x^3 + x^2 - 9x - 9$ için kök $-1$ bulundu.
  - Hocanın kod hakkındaki yorumları
    - Newton-Raphson bir başlangıç değeriyle çalışır. Alt ve üst sınır istemek gereksiz.
* **Hocanın Vurgusu:**
  - Sunumda kamera ve mikrofon açık olsun.
    - Hazır değilseniz o hafta sunmayın.
  - Raporu aynı gün yükleyin.
    - Derste çalıştırılan yöntemin ekran çıktısını ekleyin.
  - Newton-Raphson'da başlangıç değeri, durma koşulunda ardışık köklerin farkı kullanılır.
  - Kodunuzdaki gelişimi görmeniz projenin asıl amacıdır.
  - Vize saat 16:00'da, 75 dakika, hesap makinesi yanınızda olsun.

### 🔹 Ders 13: Proje Gösterimleri (2. Hafta)
* **Genel Konular:**
  - Bu derste yeni konu işlenmedi. Kaydın tamamı (yaklaşık 2 saat 45 dakika) proje gösterimlerinden oluşuyor. Gösterimlerin ikinci haftası.
  - Gösterim düzeni
    - Hoca isim okur. Öğrenci numarasını söyler, kamerasını açar, ekranını paylaşır ve kaç yöntemi kodladığını söyler.
  - Rapor
    - Bütün öğrencilere raporu Online Yıldız'a yükleyip yüklemedikleri soruldu. Raporlara akşam bakılacak.
  - Hocanın genel mesajları
    - "Benim için önemli olan kendinizi geliştirmeniz." Hoca öğrencilere güvendiğini, hiçbirini ayırmayacağını söyledi.
  - Gösterimlerde görülen sorunlar
    - Kapalı yöntemlerde uç noktalardan biri tam kökse ($f(a) = 0$ veya $f(b) = 0$) program "ikisi de pozitif" gibi hatalı bir mesaj verdi. $f(a)\cdot f(b) = 0$ durumu da kontrol edilmeli.
  - Gösterimlerde kullanılan bazı girdiler (kendi kodunuzu sınamak için)
    - Regula falsi: $x^2 - 4x - 5$.
* **Hocanın Vurgusu:**
  - Kendiniz yapın, kendinizi kandırmayın.
    - Amaç gelişiminiz.
  - Raporu yükleyin, ekstra fonksiyonları raporda belirtin.
  - Kamera ve ses açık olmalı.

### 🔹 Ders 14: Proje Gösterimleri (Son Hafta) ve Final Sınavı Bilgilendirmesi
* **Genel Konular:**
  - Dönemin son haftası. Yeni konu işlenmedi, kayıt proje gösterimlerinin son haftasıdır.
  - Final duyurusu
    - Final sınavı klasik olacak, **üç** klasik soru sorulacak. Hoca bunu bütün sınıfa duyurmanızı istedi.
  - Gösterim düzeni
    - Hoca raporu yükleyip henüz gösterim yapmamış olanların listesini çıkarmıştı.
  - Gösterimlerde görülen tipik hatalar
    - Katsayıları veya ara değişkenleri `int` tanımlamak: 0.1 gibi ondalıklı katsayılar girilince sonuç yanlış çıktı. Simpson ve trapezde hata veren bir öğrencinin sorunu da `double` yerine `int` kullanmasıymış. Hoca sonraki öğrencilere "inşallah katsayılar değişkenini integer tanımlamadınız" diye sordu.
  - Gösterimlerde kullanılan bazı girdiler
    - Kök bulma: $x^2 - 4x - 5$ (kökler −1 ve 5).
* **Hocanın Vurgusu:**
  - Final klasik, 3 soru.
    - Çözümler tek PDF olarak yüklenecek, görüntüde yalnızca kağıt olsun.
  - Çalışan kodun yedeğini almadan değişiklik yapmayın.
  - Ondalıklı sayılarla çalışan değişkenleri `double` tanımlayın.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
