# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin kapsamı
  - Temel fikir: farklı modeller üretip bunların kararlarını birleştirmek. Önceki dönemlerde temel modeller karar ağaçlarıydı; bu dönem yapay sinir ağları (YSA) da eklendi (ekrandan, 01:05:00).
  - Kollektif öğrenmeyi anlamak için optimizasyon konusu da işlenecek. Derin öğrenmede kollektif öğrenme yaklaşımları ayrıca ele alınacak.
  - Uygulamalarda sınıflandırmaya ve bu dönem özellikle metin verilerine ağırlık verilecek; görüntü, ses ya da tablo verisi de kullanılabilir.
- Kollektif öğrenme (ensemble learning) nedir?
  - Sayı (regresyon) ya da kategori (sınıflandırma) tahmin eden bir sistemde tek bir model yerine birden fazla modelin tahmin sürecine katılması.
  - Katılım yalnız kararların birleştirilmesi (ortalama, oylama) değildir; modellerin birlikte ya da birbirinden öğrenmesi de bu kapsamdadır.
  - Basit şema: orijinal veriden farklı veri kümeleri üretilir, her biriyle bir model eğitilir, test örneği için tüm modellerin tahminleri birleştirilir.
- Kollektif öğrenme neden kullanılır?
  - Günlük hayatta da kullanırız (ekrandan, 01:10:00): önemli kararları farklı zamanlarda tekrar düşünürüz, birçok bilene danışırız, kritik ameliyatta birden çok doktor görüşü alırız, doktorlar konsültasyon yapar, şirketleri yönetim kurulları, devletleri meclisler yönetir.
  - Veri çok büyükse: tek bir öğrenici veriyi modelleyemiyor ya da eğitim süresi örnek sayısıyla çok hızlı artıyor. Veri alt kümelere bölünür, her alt küme ayrı bir öğreniciyle modellenir, sonuçlar birleştirilir.
  - Veri çok küçükse: resampling ile veriden yeni alt kümeler elde edilir.
  - Verinin karmaşıklığı yüksekse (ekrandan, 01:15:00): öğrenicinin karmaşıklığı yetmiyorsa (ör. yalnız doğrusal ayrım yapabilen bir sınıflandırıcı) resampling ile alt kümeler üretilir, her biri ayrı öğreniciyle modellenir; doğrusal modellerin kararları birleşince doğrusal olmayan karar sınırları elde edilebilir.
  - Veri farklı türde bilgiler içeriyorsa: bir örneğin sayısal, kategorik ve zaman serisi öznitelikleri varsa veri sütun bazlı parçalanır, her parça onunla iyi çalışan modele verilir, kararlar birleştirilir.
  - Daha doğru kararlar ve tahminler üretmek için.
- Neden daha doğru sonuçlar? Sayısal örnek (ekrandan, 01:20:00)
  - Temel öğrenici sayısı $T = 25$, her birinin hata oranı $\varepsilon = 0.35$, kararlar birbirinden bağımsız, ensemble kararı oy çoğunluğuyla veriliyor.
  - Ensemble'ın yanılması için en az 13 temel öğrenicinin yanılması gerekir: $\sum_{i=13}^{25}\binom{25}{i}\varepsilon^i(1-\varepsilon)^{25-i} = 0.06$.
  - Yani %65 başarılı 25 model birleşince yaklaşık %94 başarı elde edilir (python ile kontrol: 0.0604).
  - Ampirik grafik: temel öğrenici başarısı 0.60, 0.70 ve 0.80 iken ensemble boyutu arttıkça ensemble başarısı artıyor; bireysel başarı ne kadar yüksekse ensemble başarısı da o kadar yüksek.
- Bias ve varyans (ekrandan, 01:30:00)
  - Bias (yanlılık): aynı dağılımdan gelen farklı eğitim kümeleriyle üretilen modellerin kararlarının ortalamasının gerçeğe uzaklığı.
  - Varyans: aynı modellerin kararlarının kendi ortalamalarına uzaklığı.
  - Tek bir test örneği için $Y$ gerçek değer, $y$ modellerin her birinin tahmini. Rastgele bir modelin tahmini seçilirse beklenen kare hata $\mathrm{MSE}(y) = E[(Y-y)^2]$.
- Bias-varyans ayrıştırması (ekrandan, 01:35:00)
  - $E[(Y-y)^2] = E[(Y-E[y])^2] + E[(E[y]-y)^2] + 2E[(Y-E[y])(E[y]-y)]$.
  - Çapraz terim sıfırdır, çünkü $E[E[y]-y] = 0$. Sonuç: $E[(Y-y)^2] = \mathrm{varyans}(y) + \mathrm{bias}^2(y)$.
  - Tahmin olarak $y$ yerine $E[y]$ kullanılırsa: $E[(Y-y)^2] \geq E[(Y-E[y])^2]$; aradaki fark varyanstır ve negatif olamaz.
  - Tahminler yansızsa ($\mathrm{bias}(y) = 0$, $Y = E[y]$): $E[(Y-y)^2] = \mathrm{varyans}(y)$.
- Dart benzetmesi (ekrandan, 01:45:00)
  - Düşük bias: atışların ortalaması hedefe yakın. Düşük varyans: atışlar birbirine yakın.
  - Varyans sıfırsa (bütün oklar aynı yere gidiyorsa) tahminleri birleştirmek hiçbir işe yaramaz.
- Ortalama almanın karar sınırına etkisi (ekrandan, 01:50:00)
  - Doğrusal ayrılabilir iki sınıfta sonsuz sayıda perceptron karar sınırı eğitim kümesinde %100 başarı verir.
  - Bunların ortalaması kabaca maksimum marjinli bir sınır verir (SVM gibi); yeni örneklerde daha güvenlidir.
  - Regresyonda da tek tek modeller yerine ortalama model daha makul bir eğri verir.
- Kollektif öğrenmenin iki bileşeni ve "2'li optimizasyon" (ekrandan, 01:55:00)
  - Temel öğrenicilerin performansı (düşük bias) ve kararlarının farklılığı, ayrıklığı (diversity, varyans).
  - Önerilen ensemble algoritmalarının tamamına yakını bu iki bileşenle ilgilidir.
  - İki bileşen birbiriyle ters orantılıdır: temel öğreniciler çok başarılı olursa kararları birbirine benzer.
- Dezavantajlar
  - Daha yavaş eğitim ve test; daha fazla bellek ve işlemci zamanı.
  - Daha zor anlaşılan, yorumlanması güç modeller (tek ağaç yerine yüz ağaç).
  - Ensemble başarısının diversity ve temel öğrenici başarısı cinsinden, veri kümesinden bağımsız bir açıklaması henüz bulunmuş değil.
- Derin öğrenmede kollektif öğrenme (ekrandan, 02:00:00)
  - Temel öğrenici olarak YSA (yüksek varyans), veri artırımı, karar birleştirme, hata parametre uzayını incelemek ve snapshot ensemble'lar, birbirinden öğrenme (model saflaştırma, distillation, öğretmen-öğrenci modelleri), birbiriyle yarışan modeller.

## Hocanın Özellikle Vurguladığı Kısımlar

- Çeşitlilik (farklılık) şarttır
  - Bütün modeller aynı kararı veriyorsa onları birleştirmenin anlamı yoktur; yönetim kurulunda herkes aynı şeyi söylüyorsa o kadar kişinin bir önemi kalmaz. Farklılık, kararları iyileştirmenin tek yoludur.
- İki bileşen birbiriyle çelişir
  - Kollektif öğrenmede aynı anda iki çelişen şey optimize edilir: temel öğrenici başarısı ve kararların farklılığı. Başarı %100'e çıkarsa varyans sıfır olur.
- YSA'lar deterministik değildir
  - Karar ağacına aynı veri verilirse hep aynı model çıkar. YSA'da başlangıç ağırlıkları rastgele olduğu için aynı veriyle bile farklı modeller ve farklı karar sınırları elde edilir. Bu yüzden YSA ile aynı veri kümesi üzerinde de ensemble kurulabilir.
  - Farklı veri kümeleri kullanmak diversity'yi artırır; veri kümeleri birbirine benzedikçe kararlar da benzer.
- Ortalamayı kullanmak daha iyidir
  - $E[(Y-y)^2] \geq E[(Y-E[y])^2]$ eşitsizliği her zaman doğrudur, çünkü aradaki fark bir kare ifadenin beklenen değeridir.
  - Burada beklenen değer tek bir $y$ için değil, rastgele seçilen herhangi bir $y$ için hesaplanır. Tek bir $y$ ortalamadan gerçeğe daha yakın olabilir ama hangisinin olduğunu bilemeyiz.
- "Neden?" diye sorgulamak
  - Slaytlardaki "Neden?" sorularının cevapları bilerek verilmemiştir. Makale okurken de her iddiaya "neden" sorusunu eklemek okumayı en faydalı hale getirir.
- Kendi kendinize yapacağınız çalışma
  - 12. slayttaki genel ensemble hata formülünün nereden geldiğini bulmaya ve 20. slayttaki şekli anlamaya çalışın.

## Kısa Tekrar Notları

- Kollektif öğrenme = ensemble learning: birden çok modelin tahmin sürecine katılması (karar birleştirme ya da birlikte öğrenme).
- Kullanım nedenleri: çok büyük veri, çok küçük veri, karmaşık veri, farklı türde öznitelikler, daha doğru tahmin.
- $T = 25$, $\varepsilon = 0.35$, bağımsız, oy çokluğu: ensemble hatası $\approx 0.06$.
- Bias: ortalama tahminin gerçeğe uzaklığı. Varyans: tahminlerin kendi ortalamasına uzaklığı.
- $E[(Y-y)^2] = \mathrm{varyans}(y) + \mathrm{bias}^2(y)$.
- Ortalama tahmin, rastgele seçilen tek bir modelden daha düşük beklenen hata verir.
- Varyans sıfırsa birleştirme işe yaramaz; bias sıfırsa hata yalnız varyanstır.
- Perceptronların ortalaması kabaca maksimum marjinli (SVM benzeri) sınır verir.
- İki bileşen: yüksek temel öğrenici başarısı ve yüksek diversity; ikisi ters orantılı.
- Dezavantaj: yavaşlık, bellek, yorumlanabilirlik kaybı, teorik açıklama eksikliği.
- YSA stokastik, karar ağacı deterministik.
- Terimler: base learner = temel öğrenici, ensemble = öğrenici topluluğu, diversity = kararların farklılığı ve ayrıklığı.

## Detaylı Açıklamalar

- Kollektif öğrenmenin temel şeması
  - Elimizde bir veri kümesi var. Klasik yaklaşımda bu veriyle tek bir model eğitilir ve test örneklerinin etiketleri bu modelle tahmin edilir. Kollektif öğrenmede tek model yerine çok sayıda model kullanılır. Çok model eğitebilmek için farklı verilere ihtiyaç vardır; bu veriler orijinal veriden üretilir (resampling, alt kümeler). En sonda her modelin tahmini birleştirilerek test örneği için nihai tahmin verilir.
  - Çeşitlilik iki yoldan sağlanabilir: aynı veriyi birbirinden farklı modellere vermek ya da aynı modele farklı veriler vermek. Önemli olan, tahminlerin birbirinden farklı olmasıdır.
- Oy çokluğu
  - Örneğin üç sınıflı bir problemde 10 model var. Her model test örneği için bir sınıf söyler (A, A, C, B, ...). En çok oy alan, yani frekansı en yüksek sınıf seçilir. Buna kararları oy çokluğuyla birleştirmek denir.
- $T = 25$, $\varepsilon = 0.35$ örneği
  - Oy çokluğunda 25 öğrenicinin en az 13'ü yanılırsa ensemble yanılır. Bağımsızlık varsayımıyla yanılan öğrenici sayısı binom dağılır; 13'ten 25'e kadar olasılıkların toplamı $0.0604 \approx 0.06$ çıkar. Bireysel başarı %65 iken topluluk başarısı yaklaşık %94 olur.
  - Burada "bağımsız" demek, öğrenicilerin birbirine benzeyen hatalar yapmaması demektir. Hepsi aynı örneklerde yanılıyorsa birleştirmenin anlamı kalmaz.
  - Hoca formülün genel halini öğrencilere bıraktı.
  - Ampirik grafikte (1000 örnekten kaç tanesinin doğru bilindiği) bireysel başarısı %70 olan yaklaşık 4 öğreniciyle ulaşılan başarıya, bireysel başarısı %60 olan öğrenicilerle ancak 14-16 öğreniciyle ulaşılıyor. Grafikteki kırıklıklar deneyin ampirik olmasından gelir; analitik formülle çizilirse eğri düzgün olur. Grafiği üreten MATLAB kodu (`ens_acc.m`) slaytta gösterildi. <!-- BELİRSİZ: ens_acc.m kodu ve grafik değerleri karelerde okunur değil (slayt 13-14, yaklaşık 01:21-01:24 arası). -->
- Bias-varyans ayrıştırmasının adımları
  - $E[(Y-y)^2]$ ifadesinin içine $E[y]$ eklenip çıkarılır: $E[(Y-E[y]+E[y]-y)^2]$. $(a+b)^2 = a^2+b^2+2ab$ açılımı ve beklenen değerin toplama dağılması ile üç terim elde edilir.
  - $Y$ ve $E[y]$ sabittir; $E[E[y]-y] = E[y]-E[y] = 0$ olduğundan çapraz terim sıfırlanır. Derste bir öğrenci de bu terimin beklenen değerinin sıfır olduğunu söyledi, hoca onayladı.
  - Kalan iki terimden $E[(Y-E[y])^2]$ bias'ın karesi, $E[(E[y]-y)^2]$ varyanstır. İkisi de hatayla doğru orantılıdır: tahminler çok dağınıksa (yüksek varyans) ya da ortalamaları gerçekten uzaksa (yüksek bias) rastgele seçilen bir tahminin hatası büyük olur.
  - $y$ yerine $E[y]$ kullanıldığında hata yalnız bias kareye iner. Varyans negatif olamayacağı için ortalamayı kullanmak her zaman en az o kadar iyidir; eşitlik yalnız varyans sıfırken olur.
- Dart sorusu
  - Hoca, atılan okların geldiği yerleri değil ortalamalarını saymayı önerdi ve bunun akıllıca olup olmadığını sordu. Öğrenciler, karşıt yönlere giden iki büyük hatanın birbirini dengeleyebileceğini söyledi; ikisi aynı köşeye giderse bir kazanç olmaz. Bu, tahminlerin ortalamasını almanın tam karşılığıdır.
  - Dört hedefli şekilde düşük bias/düşük varyans, düşük bias/yüksek varyans, yüksek bias/düşük varyans ve yüksek bias/yüksek varyans durumları gösterildi.
- Perceptron ve SVM bağlantısı
  - Doğrusal ayrılabilir iki sınıflı veride iteratif bir model (perceptron) bütün örnekleri doğru ayırınca eğitimi durdurur. Bu koşulu sağlayan sonsuz sayıda doğru vardır ve hepsinin eğitim başarısı %100'dür. Örneklere çok yakın geçen bir sınır, yeni gelen benzer bir örneği yanlış tarafta bırakabilir. Bütün olası sınırların ortalaması örneklerden uzak, marjini büyük bir sınır verir. SVM'in temel mantığı budur; çok sayıda perceptron eğitip ortalamasını almak benzer bir davranış sağlar.
- Dezavantajlar ve teori eksikliği
  - Bir model yerine çok model eğitmek ve sorgulamak zaman ve bellek ister. Tek bir karar ağacını uzman olmayan biri de okuyabilir, ama yüz ağaçlık bir topluluk yorumlanması zor bir modeldir; hocaya göre günümüzde yorumlanabilirlik daha az öncelikli olduğu için bu büyük bir handikap sayılmayabilir.
  - Diversity ve temel öğrenici başarısı birbiriyle çeliştiği için ensemble başarısını bu iki büyüklük cinsinden veriden bağımsız açıklayan bir teori henüz yoktur.
- Derin öğrenmede kollektif öğrenme
  - YSA'lar stokastiktir (başlangıç ağırlıkları rastgele), bu yüzden yüksek varyanslı temel öğrenicilerdir. Yarışma liderlik tablolarında en başarılı sonuçların çoğu ensemble içerir; iyi tasarlanmış bir ensemble büyük olasılıkla tekil modelden daha başarılıdır.
  - Distillation (öğretmen-öğrenci) ile büyük, önceden eğitilmiş bir model çok daha küçük bir modele sıkıştırılabilir; örneğin 1 milyon parametreli modelin performansına yakın 10 bin parametreli bir model elde edilip sunucuda çalışan bir sistem cep telefonunda çalışır hale getirilebilir. Birbiriyle yarışan modeller başlığında GAN benzeri yapılardan kısaca söz edilecek.
  - Hoca MATLAB kodları paylaşacağını, bunların Python karşılıklarının kolayca yazılabileceğini söyledi; ensemble kütüphaneleri R, scikit-learn ve MATLAB'de hazırdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
