# Ders 1 Çalışma Özeti

## Genel Konular

- Dönemin ilk dersi. 2023 depremi sonrasında dersler Zoom üzerinden uzaktan yapılır.
  - Hoca her hafta bir öğrenciyi sınıf adına cevap veren temsilci olarak seçer, çünkü boşluğa konuşmak zordur ve tam ekrandayken sohbeti okuyamaz.
  - Bu dönem iki grup 100'er öğrenciyle çok kalabalıktır. Diğer grubun hocası Ahmet Hoca'dır.
- Dersin işleyişi ve değerlendirme
  - Ders zamanında takip edilirse sonradan çok emek gerektirmeyen bir derstir. Dersleri biriktirmek konuları birbirine karıştırır.
  - İki vize toplam %40, final %40. Kalan kısım yıl içi projedir.
  - Proje: dersin içinde belirtilen yöntemlerin (ör. 10 algoritma) istenilen bir programlama diliyle kodlanması. Dönemin son bir-iki haftasında çevrim içi sunulur. Hoca kaç yöntemin kodlandığını sorar ve birini gösterilmesini ister. Söylenen sayıda kod yoksa hiçbiri yapılmamış sayılır. Algoritmalar ve çıktıları bir rapor hâlinde Drive'a yüklenir.
  - Hoca, bilgisayar mühendisliği öğrencisinin en geç ikinci sınıfın birinci döneminde algoritma kurabilmesi gerektiğini vurgular. Bunun yolu bol bol kod yazmaktır. Kendi öğrencilik hikâyesini anlatır: algoritmayı ilk başta anlamamış, akış diyagramları üzerinden "neden böyle yapıldı" diye analiz ederek öğrenmiştir. Proje kodlarını başka yerlerden almayın.
  - Hesap makinesi bu ders için olmazsa olmazdır. Sınavlara kendi hesap makinenizi getirin ve kullanmayı bilin.
  - Slaytlar hocanın AVESİS sayfasında (Sayısal Analiz Bölüm 1, 2…). Şifre korumalıysa şifre "sayana". Ahmet Hoca'nın paylaştığı link de OBS üzerinden gönderilecek.
  - Kaynak olarak McGraw-Hill'in sayısal yöntemler kitabı referans alınır. Bu konuda yüzlerce kaynak vardır. Kitapların %60-70'i aynı konulardır, geri kalanı yazarın alanına göre değişir.
- Dersin konuları
  - Sayısal analizin tanımı, hata türleri, sayıların gösterimi (anlamlı basamak, ondalık basamak, yuvarlama, kesme).
  - Doğrusal olmayan denklemlerin kök bulma yöntemleri: kapalı yöntemler (grafik yöntemi, ikiye bölme, regula falsi) ve açık yöntemler (Newton-Raphson, basit iterasyon, sekant).
  - Sayısal integral: alanı küçük parçalara bölüp parçaların alanlarını toplamak. Yamuk (trapez) ve Simpson yöntemleri, çift katlı integraller.
  - Sayısal türev: optimizasyon problemlerinde (en küçük, en büyük noktalar) kullanılır.
  - Matrisler: transpoz, determinant, ters matris. Alt-üst üçgen, birim, köşegen ve bant matrisler.
  - Doğrusal denklem sistemleri: dolaysız (doğrudan) yöntemler ve dolaylı (iteratif) yöntemler (Gauss-Seidel, Jacobi). Cholesky ve Cramer yöntemleri.
  - Doğrusal olmayan denklem sistemleri: Taylor serisi kullanılarak çözülür.
  - Sonlu farklar (ileri, geri, merkezi farklar ve fark tabloları), interpolasyon için gereklidir.
  - Eğri uydurma: interpolasyon (Gregory-Newton, Lagrange) ve regresyon (en küçük kareler).
  - Zaman kalırsa adi diferansiyel denklemler.
- İnterpolasyon ile regresyonun farkı
  - İnterpolasyon: hatasız veri noktalarının arasındaki değerleri bulmak için kullanılır. Veriler tablo hâlindedir. Eğri noktaların tam üzerinden geçer. Örnek: analog bir sesten belirli aralıklarla alınan örneklerden sesi yeniden oluşturmak.
  - Regresyon: verilerde belirgin bir hata varsa (deneysel veriler) kullanılır. Verilerin genel eğilimini gösteren, noktalardan geçmek zorunda olmayan bir eğri bulunur.
  - Hangi tür eğrinin (doğru, parabol, üstel) uyacağı önceden bilinmez. Farklı türler denenip en küçük hatayı veren seçilir. Aynı tür verilerle çalışıldıkça hangi türün iyi sonuç verdiği öğrenilir.
  - Sayısal analizde gerçek dünyada sıfır hatayla sonuç bulmak çok zordur. Örnek sorular çözüm kolay olsun diye özel hazırlanır.
  - Bilgisayar mühendisleri hazır bir kütüphaneyi kullanırken bile giriş, çıkış veya ara adımlara müdahale etmek zorunda kalabilir. Algoritmanın arka planını bilmek bunu kolaylaştırır.
- Sayısal analiz nedir?
  - Bilgisayarların gelişmesi ve mühendislikte kullanılabilir hâle gelmesiyle önem kazanmıştır. Amaç, mühendislik problemlerini kağıt kalem yerine bilgisayarla, daha hızlı ve daha az hatayla çözmektir.
  - Geniş çaplı matematik problemleri ve mühendislik sistemleri için matematikçilerin geliştirdiği yöntemler topluluğudur.
  - Fiziksel bir sistemin matematiksel gösterimini sağlar. Analitik yoldan çözülmesi imkânsız denklemlerin yaklaşık çözümünde kullanılır. Yüksek matematiği basit aritmetik işlemlere indirger.
- Analitik ve sayısal çözüm
  - Analitik çözüm: matematiksel fonksiyonlarla çözüm üretilir, sonuç süreklidir, tek ve kesin bir sonuç bulunur. Karmaşık olmayan problemlerde kullanılır. Karmaşık problemlerde elle çözmek zaman alır ve yanlış yapma olasılığı yüksektir.
  - Sayısal çözüm: sonuçlar her zaman sayısaldır. Veriler kesiklidir (ör. oda sıcaklığı sürekli değişir ama 5 dakikada bir ölçülür). Yaklaşık sonuç iteratif bir çözümle bulunur: her adım bir önceki adımın sonucunu kullanır. İterasyon sayısı ve alınan basamak sayısı arttıkça hassasiyet artar. Hata büyükse iterasyon sayısı artırılır veya başka bir yöntem seçilir.
  - Örnek: $f(x) = x^2 - 3x + 2$. Analitik yolla $f'(x) = 2x - 3 = 0$, $x = 1.5$, $f(1.5) = -0.25$ (en küçük nokta). Sayısal yolla yalnızca belirli $x$ değerlerindeki sonuçlar bilinir. 1.5 tabloda yoksa sonucun iki komşu değer arasında olduğu söylenip yaklaşık bir değer bulunur.
- Sayıların gösterimi
  - Taban 10 (decimal), taban 2 (binary), taban 8 (octal), taban 16 (hexadecimal). Onaltılık sayılar alt seviye programlamada (assembly) kod adım adım izlenirken görülür.
  - Anlamlı basamak (significant digit, S): noktanın solundaki ve sağındaki basamakların toplamıdır. Noktanın solundaki 0 anlamlı değildir. $\frac{2}{3}$ için 5S: $0.66667$ (noktadan sonra 5 basamak, son basamak yuvarlandı). $\sqrt{2}$ için 5S: $1.4142$ (soldaki 1 de sayılır).
  - "Noktadan sonra kaç basamak?" yerine "kaç anlamlı basamak?" diye sormak daha doğru bir ifadedir.
  - Ondalık basamak (decimal place, D): yalnızca noktanın sağındaki basamak sayısıdır. $6.7542$ için 3S $6.75$, 2D $6.75$, 3D $6.754$.
  - Kayan nokta sayı: mantis × taban^üs. Bilgisayar genellikle $0.xxx \times 10^n$ biçiminde yazar. $156.78 = 0.15678 \times 10^3$, $0.0125 = 0.125 \times 10^{-1}$. Virgül sola kaydırılırsa üs pozitif, sağa kaydırılırsa negatif olur.
  - Aynı sayı farklı biçimlerde yazılabilir: $5.026 \times 10^{-17} = 50.26 \times 10^{-18} = 0.5026 \times 10^{-16}$.
- Kesme (truncate) ve yuvarlama (round)
  - Kesme: istenen basamaktan sonrası atılır. Yuvarlama: sonraki basamak 5 veya büyükse son basamak bir artırılır.
  - $\pi = 3.14159265\ldots$ için 4D kesme $3.1415$, 4D yuvarlama $3.1416$. İkisi de 5 anlamlı basamaktır.
  - Sorularda sonuçların hangi kurala göre (kaç S veya D, kesme veya yuvarlama) alınacağı belirtilir. İteratif işlemlerde her adımın sonucu bu kurala göre bir sonraki adıma verilir.
  - Yuvarlama hatası (round-off error): basamak sınırlamasından doğan hatadır. Roket gibi hassas sistemlerde çok küçük farklar ölümcül sonuçlar doğurabilir.
- Doğruluk (accuracy) ve hassaslık (precision)
  - Doğruluk: hesaplanan veya ölçülen değerin gerçek değere ne kadar yakın olduğu. Gerçek değer 61 ise 59.89, 59'dan daha doğrudur.
  - Hassaslık: ölçülen değerlerin kendi aralarında ne kadar uyumlu olduğu. 59.88 ve 59.891 hassastır. Arada 70 ölçülürse hassaslık bozulmuştur.
  - Hedef tahtası örneği: oklar birbirine yakınsa hassaslık, hedefin merkezine yakınsa doğruluk yüksektir. Dört durum: yanlış ve belirsiz, belirsiz ama daha doğru, yanlış ama hassas, hem doğru hem hassas. İteratif yöntemlerde her adımda sonuç hem daha hassas hem daha doğru hâle gelir.
- Yanlış (mistake) ve hata (error)
  - Hata: sistemden kaynaklanır. Gerçek değer ile hesaplanan değer arasındaki farktır (1.5 yerine 1.6 bulmak). İterasyonla küçültülebilir.
  - Yanlış: insandan kaynaklanır. Bir sayıyı yanlış yazmak, basamakların yerini değiştirmek, matrisin satırını kaydırarak okumak gibi.
  - Bilgisayar "error" verir. Kodda yanlış yazılan bir komut ise "mistake"tir. Hesap makinesi kullanılmadan yapılan işlemlerde hem yanlış hem hata oluşabilir.
- Kayan noktalı sayılarla işlemler
  - Toplama ve çıkarmada üsler önce eşitlenir: $3.12 \times 10^1 + 4.26 \times 10^1 = 7.38 \times 10^1 = 0.738 \times 10^2$.
  - Çarpmada üsler toplanır: $4.27 \times 10^1 \cdot 3.68 \times 10^2 = 15.7136 \times 10^3$.
  - Bölmede üsler çıkarılır: $\frac{4.27 \times 10^1}{3.68 \times 10^2} = 1.1603 \times 10^{-1} = 0.11603$.
- Hata türleri
  - Hata, beklenen (gerçek) değer ile hesaplanan değer arasındaki farktır. Örnek: $x = 5$ için $x^2$ gerçekte 25'tir, hesap makinesi 10 verirse aradaki fark hatadır. Sayısal yöntemlerde birinci amaç hatayı en aza indirmektir.
  - Dört hata türü: kesme hatası (truncation error), bağıl hata (relative error), mutlak hata (absolute error), yuvarlama hatası (rounding error). Ayrıntıları gelecek ders.
- Taylor ve Maclaurin serileri
  - Hataları göstermek için genellikle seriler kullanılır. Bir fonksiyonun seriye açılabilmesi için sonsuz kez türevlenebilir olması gerekir. $\sin x$, $\cos x$, $e^{2x}$ seriye açılabilir.
  - Taylor açılımı, $f(x)$'in $x = x_0$ noktası çevresindeki açılımıdır: $f(x) = f(x_0) + \frac{f'(x_0)}{1!}(x - x_0) + \frac{f''(x_0)}{2!}(x - x_0)^2 + \frac{f'''(x_0)}{3!}(x - x_0)^3 + \dots + \frac{f^{(n)}(x_0)}{n!}(x - x_0)^n + \dots$
  - Maclaurin serisi, Taylor serisinin $x_0 = 0$ olduğu özel durumudur: $f(x) = f(0) + f'(0)x + \frac{f''(0)}{2!}x^2 + \dots$
  - Seri sonsuza kadar açılamaz, belirli bir terimde kesilir. "3. dereceye kadar aç" demek ilk dört terimi almak demektir.
  - Bu seriler ileride kesme hatasında, Gregory-Newton interpolasyonunda ve sayısal türevde kullanılacak.
  - Örnek: $e^x$'in $x = 1$ çevresinde ilk dört terimi. Bütün türevler $e^x$'tir, $x = 1$'de hepsi $e$. $e^x \approx e + e(x - 1) + \frac{e}{2!}(x - 1)^2 + \frac{e}{3!}(x - 1)^3$.
  - Hesap makinesi $e^x$'i veya $\cos x$'i serinin kaç terimiyle hesapladığını söylemez. Daha hassas bir sonuç gerekirse seriyi kendimiz açıp istediğimiz sayıda terimle hesaplayabiliriz. Bazı kütüphanelerde terim sayısı bir parametredir.
  - Örnek: $\cos x$'in Maclaurin açılımının sıfırdan farklı ilk üç terimi. Türevler $-\sin x$, $-\cos x$, $\sin x$, $\cos x$… $x = 0$'da $\sin$ terimleri 0 olur. $\cos x \approx 1 - \frac{x^2}{2!} + \frac{x^4}{4!}$.
  - Serileri ezberlemeye gerek yoktur. Formül bilinirse $\sin x$, $\cos 5x$, $\tan x$ hemen açılabilir.
  - Gelecek ders: seriyi bir noktada hesaplamak için genel bir formül hâline getirmek.

## Hocanın Özellikle Vurguladığı Kısımlar

- Dersi zamanında takip edin, biriktirmeyin. Formüller tekrar tekrar üzerinden geçildikçe akılda kalır.
- Algoritma kurmayı öğrenmek için bol kod yazın. Proje kodlarını başkalarından almayın.
- Sınava kullanmayı bildiğiniz bir hesap makinesiyle girin. İşlem hatası yapmayın.
- Anlamlı basamak (S) ile ondalık basamak (D) farkını, kesme ile yuvarlamayı iyi öğrenin. Bütün dönem bu terimlerle çalışılacak.
- Formülleri ezberlemeyin, neden ve nasıl olduğunu öğrenin. Puan için değil, kendiniz için öğrenin.
- Sınavda yalnızca sonuca bakılmaz. Doğru yoldaki ara adımlara puan verilir, ama birkaç satır yazmak puan getirmez.

## Kısa Tekrar Notları

- Sayısal analiz: analitik çözümü zor veya imkânsız problemlerin iteratif, yaklaşık çözümü.
- 5S: toplam 5 anlamlı basamak, baştaki sıfırlar sayılmaz. 3D: noktadan sonra 3 basamak.
- Kesme: at. Yuvarlama: sonraki basamak ≥ 5 ise artır.
- Doğruluk: gerçeğe yakınlık. Hassaslık: ölçümlerin birbirine yakınlığı.
- Hata sistemden, yanlış insandan kaynaklanır.
- Kayan nokta: toplamada üsleri eşitle, çarpmada topla, bölmede çıkar.
- Taylor: $\sum \frac{f^{(n)}(x_0)}{n!}(x - x_0)^n$. Maclaurin: $x_0 = 0$.
- $\cos x = 1 - \frac{x^2}{2!} + \frac{x^4}{4!} - \dots$

## Detaylı Açıklamalar

### Kesme ve yuvarlama tablosu

Derste tahtada doldurulan tablonun doğru sonuçları ders sonrasında hesaplandı:

| Sayı | Kesme 3S | Kesme 3D | Yuvarlama 3S | Yuvarlama 3D |
| :--- | :---: | :---: | :---: | :---: |
| 34.78219 | 34.7 | 34.782 | 34.8 | 34.782 |
| 3.478219 | 3.47 | 3.478 | 3.48 | 3.478 |
| 0.3478219 | 0.347 | 0.347 | 0.348 | 0.348 |
| 0.03478219 | 0.0347 | 0.034 | 0.0348 | 0.035 |

- 0.3478219'da 3S ve 3D aynı çıkar, çünkü noktanın solundaki 0 anlamlı değildir ve noktadan sonraki ilk basamak 0 değildir.
- 0.03478219'da ise noktadan sonraki ilk 0 da anlamsızdır. 3S için 3, 4, 7 alınır (0.0347), ama 3D için noktadan sonraki ilk üç basamak (0.034) alınır.

### Ders sonrası notlar

- **Polinomlar seriye açılabilir:** Hoca $x^3 + x^2 - x$ gibi bir polinomun dördüncü türevi 0 olduğu için seriye açılamayacağını söyledi. Polinomlar sonsuz kez türevlenebilir. Belirli bir dereceden sonra bütün türevleri sıfırdır, sıfır da bir türevdir. Bu yüzden bir polinomun Taylor serisi sonlu sayıda terimden oluşur ve polinomun kendisine eşittir. Seriye açılamayan fonksiyonlara örnek $|x|$'in $x = 0$ noktasıdır (türevi yoktur).
- **$e^{2x}$'in türevleri:** Derste üçüncü ve dördüncü türevler $12e^{2x}$ ve $24e^{2x}$ olarak söylendi. Her türevde 2 ile çarpılır: $2e^{2x}$, $4e^{2x}$, $8e^{2x}$, $16e^{2x}$. Genel olarak $n$. türev $2^n e^{2x}$'tir.
- **İkinci derece denklemin kökleri:** Derste formül "b kare artı eksi diskriminant bölü 2b" diye söylendi. Doğrusu $x_{1,2} = \frac{-b \pm \sqrt{\Delta}}{2a}$, $\Delta = b^2 - 4ac$'dir.
- **Slayttaki çarpma örneği:** $15.7136 \times 10^3$, $0.157136 \times 10^{-5}$ olarak yazılmış. Virgül sola iki basamak kaydığı için üs 2 artar: $0.157136 \times 10^5$. Hoca derste de bu satırın yanlış olduğunu fark etti.
- **Yuvarlama hatasının tanımı:** Derste yuvarlama hatası, aynı sayının yuvarlanmış ve kesilmiş hâlleri arasındaki fark olarak anlatıldı. Genel tanımı, gerçek değer ile sınırlı sayıda basamakla gösterilen değer arasındaki farktır. Örneğin $\pi$ 3.1416 olarak alınırsa yuvarlama hatası $3.14159265\ldots - 3.1416 \approx -0.0000073$'tür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
