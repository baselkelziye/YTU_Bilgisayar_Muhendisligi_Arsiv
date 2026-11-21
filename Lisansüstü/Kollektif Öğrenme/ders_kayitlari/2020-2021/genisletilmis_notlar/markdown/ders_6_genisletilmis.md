# Ders 6 Genişletilmiş Notu: Kollektif Öğrenme Metotları: Bagging, AdaBoost, Rastsal Altuzaylar ve Rastsal Ormanlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ara Not: Stokastik ve Stokastik Olmayan Gradyan Süreçleri
- 2. Dersin Planındaki Yeri
- 3. Çeşitlilik ve Tekil Başarı
- 4. Farkı Nasıl Sağlarız?
- 5. Farklı Eğitim Setleri Nasıl Üretilir?
- 6. Bagging
- 7. Bagging Örneği: Basit Öğrenicilerden Karmaşık Karar Sınırı
- 8. Bagging Bulguları
- 9. Boosting ve AdaBoost
- 10. Bagging ve Boosting Karşılaştırmaları
- 11. Rastsal Altuzaylar (Random Subspace)
- 12. Rastsal Ormanlar (Random Forest)
- 13. Aşırı Rastsal Ormanlar (Extremely Randomized Trees)
- 14. Bir Algoritmayı Başarılı Yapan Nedir?
- Örnek Sorular

## 1. Ara Not: Stokastik ve Stokastik Olmayan Gradyan Süreçleri

Hoca derse, önceki haftaki ödev sunumlarıyla ilgili kafalarda yanlış bir izlenim kalmasın diye bir düzeltmeyle başladı. Ödevin asıl kısmı stokastik olmayan süreçlerle ilgiliydi; stokastik süreçler yalnız bonus kısmındaydı.

Stokastik olmayan süreçte bir noktadaki gradyan, elimizdeki bütün örneklerle hesaplanır; buna tam (full) gradyan denir ve standart gradyan inişi (GD) bu biçimde çalışır. Stokastik süreçte ise her adımda örneklerin bir kısmıyla ya da yalnız bir örnekle gradyan hesaplanır (SGD). Bu gradyan, tam gradyanın bir miktar gürültülü hâlidir. Ödevde kayıp fonksiyonu açıkça verildiği ve bir örnek kümesinden hesaplanmadığı için öğrenciler gerçek gradyana erişebiliyordu.

Örnek ve özellik sayısı büyük olduğunda tam gradyanla çalışmak verimli değildir; stokastik süreçler bu noktada devreye girer. SGD ve quasi-Newton slaytlarında görüldüğü gibi SGD sürecin başında GD'den çok farklı değildir. Optimizasyonun sonlarına doğru, R diye tanımlanan bölgeye girildikten sonra, rastgele seçilen örneklerin gradyanı tam gradyana pek benzemez olur ve SGD yalpalamaya başlar.

Ödevde birçok öğrenci Adam'ın gradyan inişinden daha uzun süren, daha kötü bir süreç olduğunu gördü. Hoca bunun nedeninin Adam ve Adagrad'ın asıl olarak büyük ölçekli (large scale), stokastik problemler için geliştirilmiş olması olduğunu söyledi.

> **Hocanın vurgusu:** Adam hakkında yanlış bir önyargı oluşmasın. Ödev stokastik süreçlerle tekrarlanırsa Adam'ın gradyan inişine göre etkinliğinin artacağı tahmin edilir.

## 2. Dersin Planındaki Yeri

Bu hafta kollektif öğrenmenin yöntemlerine başlandı. Ders programına göre altıncı haftanın konuları Bagging, AdaBoost, Rastsal Altuzaylar, Rastsal Ormanlar, Aşırı Rastsal Ormanlar, Rotasyon Ormanları ve Improved Space Forest'tır (ekrandan, 00:15:00). Sonraki haftalarda hata düzelten kod tabanlı metotlar, uzman karışımları, kararların birleştirilmesi, modellerin karşılaştırılması, kümeleme ve regresyonda kollektif öğrenme, boosting teorisi ve yapay sinir ağlarıyla kollektif öğrenme gelecek.

Hoca, yapay sinir ağlarında kollektif öğrenme (teacher-student yöntemleri, birden fazla modelin birbirinden öğrenmesi gibi) konusunda son zamanlarda yayın sayısının giderek arttığını, bu konunun popülerleştiğini belirtti.

Slayt setinde 10 başlık vardır; bu derste ilk kısımlar işlendi. Rotasyon ormanları ve iyileştirilmiş uzay ormanları sonraki derse kaldı.

## 3. Çeşitlilik ve Tekil Başarı

Kollektif öğrenme, birinci haftadan hatırlanacağı gibi, öğrenme sürecinde tek bir model yerine birden fazla model kullanmaktır. Bunu yapmanın en klasik yolu modellerin kararlarını birleştirmektir.

Kararları birleştirirken en büyük engel kararların çeşitli olmamasıdır. Bütün temel öğreniciler aynı şeyi söylüyorsa birden fazla model kullanmanın anlamı kalmaz; kararlar birleştirilse de tek tek modellerden farklı bir şey elde edilmez. Bu yüzden temel öğrenicilerin karar çeşitliliğini sağlamak gerekir: aynı örnek için farklı modeller farklı şeyler söylemelidir.

Bununla pek uzlaşmayan ikinci bir kriter daha vardır: her tekil öğrenicinin doğruluğu yüksek olmalıdır. Daha önce çizilen grafikte, her biri %60, %70 ya da %80 başarılı öğrenicilerin birleşimi karşılaştırılmıştı; birleştirilen modeller ne kadar başarılıysa topluluk da o kadar başarılı olur. Bu derste ağırlık çeşitliliğin nasıl sağlanacağı üzerindedir.

## 4. Farkı Nasıl Sağlarız?

Slaytta çeşitliliği sağlamanın üç yolu sıralanır (ekrandan, 00:20:00).

### 4.1 Farklı temel öğreniciler

Aynı veri kümesi üzerinde bir yapay sinir ağı, bir SVM, bir karar ağacı ve bir 1-NN (en yakın komşu) çalıştırılıp kararları birleştirilebilir. Eğitim kümesinin tamamı her birine verilse bile bu algoritmalar tamamen farklı varsayımlara sahip olduğu için farklı karar sınırları üretir; farklı karar sınırları da farklı kararlar demektir.

### 4.2 Aynı öğrenicinin farklı hiperparametreli hâlleri

Hiperparametreler, algoritmanın kendisinin bulamadığı, kullanıcının verdiği parametrelerdir. KNN'de farklı $k$ değerleri (en yakın bir, iki, üç, dört komşu), yapay sinir ağında farklı başlangıçlar, gizli katmana farklı sayıda nöron ya da farklı sayıda gizli katman, karar ağacında maksimum derinlik, saflık ölçütü ya da bölme ölçütü (information gain, en yüksek doğruluk ya da aynı anlama gelen en düşük yanlışlık) birer hiperparametredir.

Yapay sinir ağları başlangıçları rastgele atandığı için deterministik değildir. Hata-parametre uzayı konveks olmadığından yapılan iş global değil lokal bir aramadır; başlanan yer, varılan yeri büyük ölçüde belirler. Bu yüzden aynı mimari ve aynı veriyle bile farklı başlangıçlardan farklı karar sınırları elde edilir. Çeşitlilik daha da artırılmak istenirse gizli katman sayısı, nöron sayısı, mimari ya da aktivasyon fonksiyonu değiştirilebilir.

### 4.3 Aynı öğreniciyi farklı eğitim setleriyle eğitmek

Öğrenici ve hiperparametreler aynı kalır, yalnız eğitim kümesi değişir: aynı eğitim kümesini herkese vermek yerine farklı eğitim kümeleri oluşturulup öğrenicilere verilir. Dersin en çok kullanacağı yaklaşım, aslında en basiti olan bu sonuncusudur. Sorun şudur: elimizde tek bir eğitim seti vardır; ondan çok sayıda eğitim seti nasıl üretilir?

**Soru:** Bundan kastedilen, örneğin 100 bin resmi 10 bin, 10 bin diye bölüp 10 öğreniciyi eğitmek mi, yoksa aynı veriden farklı bilgiler (örneğin metinden farklı özellikler) çıkarıp öğrenicileri beslemek mi?

**Cevap:** Aynı eğitim kümesinden farklı özellikler çıkararak farklı veri kümeleri oluşturmak yapılabilir, ama buradaki tanıma uymaz; o durumda aynı eğitim kümesinden değil, farklı eğitim kümelerinden söz edilir. Buradaki tanımda kullanılacak özellikler belirlenmiş ve tek bir eğitim kümesi hazırlanmıştır; yapılacak şey bu tek kümeden, örneğin 100 bin örneğin içinden farklı parçalar alarak yeni kümeler üretmektir. Bu da tam olarak basit bir bölme değildir; ayrıntısı yöntemlerle birlikte anlatıldı.

## 5. Farklı Eğitim Setleri Nasıl Üretilir?

Bir veri kümesinde örnekler, özellikler, sınıflar ve belki bölgeler vardır. Farklılaştırma bunların her biri üzerinden yapılabilir (ekrandan, 00:25:00). Üretilen kümeler birbirinden tamamen bağımsız olmaz, birbirine benzer, ama en azından farklılıkları olur.

- Örnekler: Bagging, AdaBoost, Rastsal Ormanlar (Random Forest).
- Özellikler: Rastsal Altuzaylar (Random Subspaces), Rastsal Ormanlar, Rotasyon Ormanları (Rotation Forest).
- Sınıflar: Ensemble of Nested Dichotomies, ECOC. Eğitim kümesinin bazı sınıfları ya da sınıf grupları bir temel öğreniciye, başka sınıfları başka bir öğreniciye verilir.
- Bölgeler: uzman karışımları, Random Linear Oracle. Uzay bölgelere ayrılır ve her bölgeye bir uzman temel öğrenici atanır; bu yöntemler Mixture of Experts (uzman karışımları) diye bilinir.
- Model sonuçlarını modelleme (Stacking): model sonuçlarını birleştirmeyi öğrenmek; orijinal veri kümesinden yeni bir veri kümesi üretmek anlamına gelir. Sonraki derse bırakıldı.

<!-- BELİRSİZ: Hoca bölgeler için "Mixer of Gaussian, Mixer of Experts" dedi; slaytta "Uzman karışımları" ve "Random Lineer Oracle" yazıyor. "Mixture of Gaussians" adı slaytta yok. -->

## 6. Bagging

### 6.1 Yerine koyarak örnekleme

Bagging'in yaptığı iş yerine koyarak örneklemedir (resampling with replacement). Orijinal veri 10 örnekten oluşsun; örneklerin kaç boyutlu olduğu önemli değildir. Bu 10 örnekten 10 örnek seçilir: bir örnek seçilip yeni eğitim kümesine eklenir, sonra geri atılır. Yani bir kez seçilen örnek yine seçilebilir. Sonuçta bazı örnekler birden fazla kez, bazıları hiç alınmaz. Slayttaki tablo (ekrandan, 00:30:00):

| Data ID | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
|---|---|---|---|---|---|---|---|---|---|---|
| Bagging (Round 1) | 7 | 8 | 10 | 8 | 2 | 5 | 10 | 10 | 5 | 9 |
| Bagging (Round 2) | 1 | 4 | 9 | 1 | 2 | 3 | 2 | 7 | 3 | 2 |
| Bagging (Round 3) | 1 | 8 | 5 | 10 | 5 | 5 | 9 | 6 | 3 | 7 |

Birinci turda 8 iki kez, 10 üç kez alınmış, 1 hiç alınmamıştır. İkinci turda 1 iki kez, 2 üç kez alınmış, 8 ve 10 hiç alınmamıştır. Her yeni küme yine $n$ elemanlıdır ve bu $n$ örnekle bir temel öğrenici eğitilir. Sonra aynı işlem yine orijinal veriden (önceki turun kümesinden değil) tekrarlanır. İşlem $K$ kez tekrarlanırsa birbirinden farklı sonuçlar üreten $K$ öğrenici elde edilir.

### 6.2 Seçilen örneklerin oranı

Slayttaki soru: seçilen $n$ örnek, tüm örneklerin yaklaşık %63.2'sini içerir; neden? Belirli bir örneğin $n$ çekilişin hiçbirinde seçilmeme olasılığı

$$\left(1-\frac{1}{n}\right)^n \approx e^{-1} = 0.368$$

olduğundan, seçilme olasılığı $1-0.368 = 0.632$'dir (ekrandan, 00:30:00). Bir turdaki küme ortalama olarak orijinal verinin %63.2'sini içerir; geri kalan yeri seçilmiş örneklerin tekrarları doldurur. Python ile: $n=10$ için $0.651$, $n=100$ için $0.634$, $n=1000$ için $0.632$.

> **Ders sonrası not:** Hoca sözlü olarak "%60.2" dedi; slayttaki ve hesaptaki doğru değer %63.2'dir.

### 6.3 Algoritma

Formal tanımda girdi; $\Omega = \{\omega_1, \dots, \omega_C\}$ ile gösterilen $C$ sınıfa ait doğru etiketli $S$ eğitim verisi, bir zayıf öğrenme algoritması (WeakLearn, yani temel öğrenici) ve temel öğrenici sayısını belirten $T$ tamsayısıdır. Bir de $F$ oranı vardır: $F = \%100$ (oran 1) ise $n$ örnek içinden $n$, $F = \%50$ ise $n/2$ örnek rastgele seçilir. $F$ bir hiperparametre olarak düşünülebilir.

<!-- BELİRSİZ: Bagging algoritmasının slaytı (yaklaşık 00:31-00:34) karelerde yok; tanım altyazıdaki okumadan kuruldu. -->

- $t = 1, \dots, T$ için: $S$'den rastgele $F\%$ örnek çekilerek bootstrap kopyası $S_t$ alınır.
- $S_t$ WeakLearn'e verilir ve bir hipotez $h_t$ (eğitilmiş bir model, örneğin bir karar ağacı) elde edilir.
- $h_t$ topluluğa (ensemble) eklenir. $T$ tekrardan sonra toplulukta $T$ model bulunur.
- Test: etiketsiz bir $x$ örneği topluluktaki bütün modellere verilir; her model bir sınıf tahmin eder, yani oy verir. Çoğunluk oylamasıyla (majority voting, "demokrasi usulü") en çok oy alan sınıf seçilir.

## 7. Bagging Örneği: Basit Öğrenicilerden Karmaşık Karar Sınırı

Topluluk oluşturmanın güzel yanlarından biri, basit temel öğrenicilerin kararlarını birleştirerek karmaşık karar sınırları üretebilmektir. Soru şudur: uzayı yalnız iki bölgeye ayırabilen doğrusal öğrenicilerle doğrusal ayrılamayan bir problem çözülebilir mi?

### 7.1 Veri ve temel öğrenici

Eğitim verisi tek boyutludur: $x \le 0.3$ olanlar $+1$, $x \ge 0.8$ olanlar $+1$, 0.4 ile 0.7 arasındakiler $-1$ sınıfındadır (ekrandan, 00:35:00). Örnekler 0.1, 0.2, …, 1.0 olmak üzere 10 tanedir. Hedef 10 temel sınıflandırıcıdan oluşan bir bagging topluluğudur. Her temel sınıflandırıcı bir $K$ eşiğine sahiptir: $x \le K$ ise sınıf $+1$ ya da $-1$; $K$ toplam entropinin en küçüklenmesiyle seçilir.

Tek eşikli bir sınıflandırıcı uzayı nereden bölerse bölsün tam başarı sağlayamaz: iki uçta artılar, ortada eksiler vardır. Örneğin 0.35'ten bölünürse sağdaki artılar kaybedilir.

### 7.2 On bagging turu

Slayttaki 10 tur ve öğrenilen kurallar şöyledir (ekrandan, 00:40:00):

| Tur | Seçilen $x$ değerleri | Kural |
|---|---|---|
| 1 | 0.1, 0.2, 0.2, 0.3, 0.4, 0.4, 0.5, 0.6, 0.9, 0.9 | $x \le 0.35 \Rightarrow +1$, aksi $-1$ |
| 2 | 0.1, 0.2, 0.3, 0.4, 0.5, 0.8, 0.9, 1, 1, 1 | $x \le 0.65 \Rightarrow +1$, $x > 0.65 \Rightarrow +1$ |
| 3 | 0.1, 0.2, 0.3, 0.4, 0.4, 0.5, 0.7, 0.7, 0.8, 0.9 | $x \le 0.35 \Rightarrow +1$, aksi $-1$ |
| 4 | 0.1, 0.1, 0.2, 0.4, 0.4, 0.5, 0.5, 0.7, 0.8, 0.9 | $x \le 0.3 \Rightarrow +1$, aksi $-1$ |
| 5 | 0.1, 0.1, 0.2, 0.5, 0.6, 0.6, 0.6, 1, 1, 1 | $x \le 0.35 \Rightarrow +1$, aksi $-1$ |
| 6 | 0.2, 0.4, 0.5, 0.6, 0.7, 0.7, 0.7, 0.8, 0.9, 1 | $x \le 0.75 \Rightarrow -1$, aksi $+1$ |
| 7 | 0.1, 0.4, 0.4, 0.6, 0.7, 0.8, 0.9, 0.9, 0.9, 1 | $x \le 0.75 \Rightarrow -1$, aksi $+1$ |
| 8 | 0.1, 0.2, 0.5, 0.5, 0.5, 0.7, 0.7, 0.8, 0.9, 1 | $x \le 0.75 \Rightarrow -1$, aksi $+1$ |
| 9 | 0.1, 0.3, 0.4, 0.4, 0.6, 0.7, 0.8, 1, 1, 1 | $x \le 0.75 \Rightarrow -1$, aksi $+1$ |
| 10 | 0.1, 0.1, 0.1, 0.1, 0.3, 0.3, 0.8, 0.8, 0.9, 0.9 | $x \le 0.05 \Rightarrow -1$, aksi $+1$ |

Birinci turda seçilen kümede bir 0.1, iki 0.2, bir 0.3, iki 0.4, bir 0.5, bir 0.6 ve iki 0.9 vardır; etiketleri orijinal kurala göre yazılır ($\le 0.3$ ise $+1$, 0.4-0.7 arası $-1$, 0.9 için $+1$). En düşük hatayı veren bölme 0.35'tedir. İkinci turda 0.65'ten bölünmüştür, ama iki tarafta da çoğunluk $+1$ olduğu için iki durumda da $+1$ denmiştir. Onuncu turda seçilen örneklerin hepsi $+1$ olduğundan bölmenin bir anlamı yoktur; 0.05'ten bölünmüş ve her şeye $+1$ denmiştir.

### 7.3 Oylama

Her nokta için 10 sınıflandırıcının kaç tanesinin $+1$, kaç tanesinin $-1$ dediğine bakılır; slaytta kuralların değerleri toplanıp (sum) işareti (sign) alınır.

- $x = 0.1, 0.2, 0.3$: Tur 1, 2, 3, 4, 5 ve 10 $+1$ (6 oy), Tur 6-9 $-1$ (4 oy) der. Toplam $+2$, çıkış $+1$.
- $x = 0.4, 0.5, 0.6, 0.7$: yalnız Tur 2 ve 10 $+1$ der (2 oy), diğer 8'i $-1$ der. Toplam $-6$, çıkış $-1$.
- $x = 0.8, 0.9, 1.0$: Tur 2, 6, 7, 8, 9, 10 $+1$ (6 oy), Tur 1, 3, 4, 5 $-1$ (4 oy) der. Toplam $+2$, çıkış $+1$.

Çıkışlar gerçek sınıflarla bire bir aynıdır; topluluğun başarısı %100'dür (python ile doğrulandı).

> **Hocanın vurgusu:** Eğitilen sınıflandırıcıların hiçbirinin "şu bölgeden ve şu bölgeden böleyim" diye iki yerden bölme kabiliyeti yoktur. Ama birlikte kullanıldıklarında daha karmaşık bir şey üretirler. Basit şeyleri birleştirerek karmaşık bir karar sınırı üretmek, bu örneğin en önemli bulgusudur.

### 7.4 İki boyutta bagging

İki boyutlu veride de durum benzerdir. Slaytta her turda seçilen örnekler koyu, seçilmeyenler boş gösterilir; her seçimle farklı bir karar sınırı üretilir. Bunlar birleştirildiğinde kabaca ama fena olmayan bir karar sınırı elde edilir.

## 8. Bagging Bulguları

### 8.1 Eğitim verisine duyarlı öğreniciler

Slayttaki ilk bulgu: temel öğreniciler eğitim verisine duyarlı ise bagging iyi çalışır; slaytta "1NN? DT? ANN?" diye sorulur (ekrandan, 00:45:00). Eğitim verisine duyarlı olmak, eğitim kümesindeki küçük değişikliklerin üretilen karar sınırlarını değiştirmesi demektir. Karar ağaçları böyledir, çünkü varyansı yüksek algoritmalardır.

Varyans, birinci derste görülen bias-varyans ayrışımından hatırlanacağı gibi şudur: gerçek popülasyondan farklı örneklemler alındığında algoritma her örneklem için birbirinden çok farklı sonuçlar üretiyorsa varyansı yüksektir. Varyansı yüksek algoritmalar eğitim verisine duyarlıdır; karar ağaçları ve yapay sinir ağları bu açıdan bagging için iyidir.

### 8.2 Gürültüye karşı gürbüzlük

İkinci bulgu: bagging spesifik örneklere yoğunlaşmadığı için gürültülü verilere karşı gürbüzdür. Bir sürü siyah örneğin arasında gürültü olan tek bir beyaz örnek düşünülsün. Yeniden örneklemede çevresindeki yüzlerce örnek seçilirken o tek örneğin seçilmeme şansı yüksektir; bazı kümelerde hiç görünmez. Bu da algoritmayı gürültüye karşı dayanıklı yapar.

### 8.3 Ağaç büyüklüğü: başarı ve çeşitlilik ikilemi

Slaytın başlığı: "Ağaçları tamamen büyütürsek düşük başarı, yüksek çeşitlilik; daha genel bırakırsak yüksek başarı, az çeşitlilik" (ekrandan, 00:50:00). Geçen hafta karar ağaçlarında bölmenin ne zamana kadar süreceği sorulmuştu; %100 saflık ölçütü kullanılırsa tam ağaç (full tree) oluşur, yani her bölgede yalnız tek bir sınıfın örnekleri kalır.

Slaytta aynı eğitim verisinden üretilmiş iki ağaç vardır:

- $T_1$: kökte $x_2 < 1.94$, ardından $x_1 < -1.24$ ve $x_1 < 11.00$, daha aşağıda $x_2 < 7.45$, $x_2 < 9.25$ ve $x_1 < 1.58$ bölmeleri. Çok sayıda sınır çizer; birkaç bölme daha eklenirse eğitimde %100'e çıkar.
- $T_2$: yalnız $x_2 < 1.94$, $x_1 < -1.24$ ve $x_1 < 11.00$ bölmeleri. Daha genel bir ağaçtır; eğitim kümesinde bazı hataları vardır.

Ağaç çok büyütülürse gürültüye aşırı duyarlı hâle gelir; gürültülü noktaların tam çevresine sınır çizmeye çalışır ve fazladan çok bölme ekler.

**Soru:** Bu durumda ağaç aşırı öğrenmiş (overfit) olur, değil mi?

**Cevap:** Evet; bu da testte düşük başarıya yol açar.

Daha genel ağacın test başarısı muhtemelen daha yüksektir; ama bu veri kümesine göre değişebilir, hoca genel bir eğilimden söz ettiğini belirtti. Çeşitlilik açısından ise farklı eğitim kümelerinden üretilen tam ağaçlar birbirine daha az benzer; az sayıda sınır çizen küçük ağaçların kararları birbirine daha benzer olur. Böylece tekil öğrencilerin başarısı mı yüksek olsun, kararlarının çeşitliliği mi fazla olsun ikilemi görülür: bir tarafı iyileştirmek öbür tarafı kötüleştirir.

Bagging, birazdan görülecek algoritmalara göre tekil öğrenicilerin başarısını yüksek tutan, buna karşılık çeşitliliği daha az olan bir algoritmadır: ağaçlar tam üretilir, $n$ örnekten $n$ örnekle ve bütün özellikler kullanılarak eğitilir. Tekil başarı yüksektir, ama ağaçların kararları da birbirine benzerdir.

### 8.4 Sayısal karşılaştırma

Slaytta çeşitli veri kümelerinde tek ağaç (S) ile çok ağaçlı topluluğun (B) hataları karşılaştırılır. Hocanın okuduğu değerlere göre Waveform veri kümesinde tek ağaçla %29 olan hata toplulukla %19'a, bir başka veri kümesinde 4.9'dan 2.8'e düşmüştür. Hatalarda önemli düşüşler, yani başarıda artış vardır.

<!-- BELİRSİZ: Bu tablonun karesi yok; değerler altyazıdan alındı, ikinci veri kümesinin adı "Hard Data Set" diye geçiyor, gerçek adı anlaşılamadı. -->

Temel öğrenici olarak 1-NN kullanılırsa kararların birbirinden farkı çok az olur; slaytta 1-NN için tek öğrenici ile topluluğun hatası aynı çıkmıştır. Her denemede bu kadar aynı çıkmayabilir, ama en yakın komşu algoritması eğitim kümesindeki küçük farklara karşı o kadar değişken değildir, varyansı çok yüksek değildir. Bu yüzden temel öğrenici olarak karar ağacı kullanmak daha iyidir; yapay sinir ağları da varyansı yüksek algoritmalardır.

## 9. Boosting ve AdaBoost

### 9.1 Ardışık topluluklarla öğrenme

Boosting'in teorisi sonraki haftalarda incelenecek; bu derste kabaca ne yaptığı anlatıldı. Slayttaki tanım (ekrandan, 00:55:00): temel öğrenicilerin eğitileceği örneklerin seçiminde önceki temel öğrenicilerin hata yaptıkları örneklere öncelik verilir. Başlangıçta tüm örneklerin eğitim kümesine seçilme olasılıkları aynıdır; her iterasyonda seçilme olasılıkları güncellenir (bagging'de aynı kalıyordu).

Bagging'de 10 örnekli örnekte her örneğin her turda seçilme olasılığı $1/10$'dur ve önceki turdan elde edilen bilgi hiç kullanılmaz. AdaBoost'ta başlangıçta yine hepsi $1/N$'dir, ama olasılıklar önceki öğrenicilerin hatalarına göre güncellenir: bir öğrenici bir örnekte hata yaparsa o örneğin sonraki öğreniciler için seçilme olasılığı artırılır.

### 9.2 Sezgisel örnek

Boosting'in birinci turu bagging'in birinci turuyla aynıdır, yani rastgele seçimdir. Dördüncü örneğin sınıflandırılması zor olsun (gürültü olabilir ya da gerçekten zor bir noktada olabilir). Birinci öğrenici diğerlerini doğru yapıp dördüncüyü yapamazsa, ikinci turda dördüncünün seçilme olasılığı artar; slaytta ikinci turda üç kez seçilmiştir. Yine yapılamazsa olasılık daha da artar; üçüncü turda beş kez seçilmiştir.

Amaç, öncekilerin yanlış yaptığını birilerinin doğru yapmasıdır: birinin yapamadığını öbürü yapabilsin. Doğru sınıflanan örneklerin olasılığı azaltılır (ya da aynı bırakılır, ama ötekiler artırıldığı için normalizasyonla aynı sonuca varılır) ve dağılım yine bir olasılık dağılımı hâline getirilir.

### 9.3 AdaBoost algoritması

Slayttaki algoritma (ekrandan, 01:00:00):

```text
Training:
  For all {x^t, r^t}_{t=1}^N in X, initialize p_1^t = 1/N
  For all base-learners j = 1, ..., L
    Randomly draw X_j from X with probabilities p_j^t
    Train d_j using X_j
    For each (x^t, r^t), calculate y_j^t <- d_j(x^t)
    Calculate error rate: eps_j <- sum_t p_j^t * 1(y_j^t != r^t)
    If eps_j > 1/2, then L <- j - 1; stop
    beta_j <- eps_j / (1 - eps_j)
    For each (x^t, r^t), decrease probabilities if correct:
      If y_j^t = r^t  p_{j+1}^t <- beta_j * p_j^t   Else  p_{j+1}^t <- p_j^t
    Normalize probabilities:
      Z_j <- sum_t p_{j+1}^t ;  p_{j+1}^t <- p_{j+1}^t / Z_j
Testing:
  Given x, calculate d_j(x), j = 1, ..., L
  Calculate class outputs, i = 1, ..., K:
    y_i = sum_{j=1}^L (log 1/beta_j) d_ji(x)
```

Adımların anlamı:

- Eğitim kümesi $N$ tane $(x^t, r^t)$ çiftinden oluşur; başta hepsinin seçilme olasılığı $1/N$'dir, ilk seçim rastgeledir.
- $\mathcal{X}_j$ bu olasılıklara göre çekilir ve $d_j$ temel öğrenicisi (örneğin bir karar ağacı) onunla eğitilir.
- Sonra eğitim kümesinin tamamı $d_j$'ye verilir ve tahminler $y_j^t$ alınır; $r^t$ gerçek değerdir.
- $1(\cdot)$ gösterge fonksiyonudur: içi doğruysa 1, değilse 0 değerini alır. Böylece $\epsilon_j$, yanlış tahmin edilen örneklerin seçilme olasılıklarının toplamıdır.
- $\epsilon_j > 1/2$ ise, yani örneklerin ortalama yarısından fazlası yanlış yapılıyorsa algoritma durur; o anki $d_j$ topluluğa katılmaz, o ana kadar eğitilmiş olanlar katılır.

**Soru:** Eğitimden sonraki kısım tekrar anlatılabilir mi?

**Cevap:** $\mathcal{X}_j$, $p_j^t$ seçilme olasılıklarından oluşturuldu ve bir sınıflandırıcıya verildi, örneğin bir karar ağacı oluştu. Sonra bütün eğitim örnekleri için sınıflandırıcının tahminleri ($y_j^t$) alındı. $y_j^t$ ile $r^t$ eşit değilse $d_j$ o örneği yanlış yapmıştır. Yanlış yapılan örneklerin olasılıkları toplanır ve $\epsilon_j$ diye adlandırılır. İki sınıflı bir problemde %50'den fazla hata yapan bir sınıflandırıcı iyi bir sınıflandırıcı değildir, onu topluluğa katmanın anlamı yoktur.

Hata %50'den büyük değilse $\beta_j = \epsilon_j/(1-\epsilon_j)$ hesaplanır. Hocanın örneği: $\epsilon_j = 0.1$ ise $\beta_j = 0.1/0.9 = 1/9$ olur. $\beta_j$ 0 ile 1 arasında bir değerdir; doğru sınıflanan bir örneğin $p_j^t$ değeri bununla çarpılınca azalır, yanlış sınıflananınki aynı kalır. Doğruların olasılığı azaldığı için yanlışlarınki otomatik olarak göreli biçimde artar. Çarpmadan sonra olasılıkların toplamı 1'den farklı olur; hepsi $Z_j$ toplamına bölünerek yeniden olasılık dağılımı hâline getirilir.

<!-- BELİRSİZ: Hoca $\beta_j$ hesabından sonra "$\epsilon_j$'nin çok küçük olması durumunda bir normalizasyon sağlıyor" dedi, ama slaytta bunun yerini göremediğini söyleyip devam etti; bu açıklama nota alınmadı. -->

### 9.4 Test aşaması

Testte çoğunluk oylaması yapılmaz. $d_{ji}(x)$, $j$. öğrenicinin $i$. sınıf için çıkışıdır; her sınıf için $y_i$ hesaplanır ve en yüksek olan sınıf seçilir. Her öğrenicinin katkısı $\epsilon_j$'den türetilen ağırlıkla ağırlıklandırılır: hatası yüksek olanın karara etkisi az, hatası düşük olanın etkisi çok olur.

> **Ders sonrası not:** Hoca çıkışların "$\beta_j$ ile çarpıldığını" söyledi; slayttaki formülde ağırlık $\log(1/\beta_j)$'dir. Hatası düşük öğrenicide $\beta_j$ küçük, $\log(1/\beta_j)$ büyük olur. Örneğin $\epsilon_j = 0.1$ için $\ln 9 \approx 2.20$ (python ile hesaplandı).

Bu formüllerin nereden geldiği ve nasıl akla geldiği boosting teorisi haftasında ayrıntılı işlenecek. Slaytta AdaBoost'un seçilme olasılıklarının güncellenmesini gösteren bir örnek ve iki boyutlu bir AdaBoost örneği de vardır, ama bu derste üzerinde durulmadı.

## 10. Bagging ve Boosting Karşılaştırmaları

### 10.1 C4.5 ile karşılaştırma

Slaytta birçok veri kümesi; örnek sayısı, sınıf sayısı ve sürekli/ayrık öznitelik sayılarıyla listelenmiş ve C4.5 karar ağacının tek başına, bagging'in temel öğrenicisi olarak ve boosting'in temel öğrenicisi olarak hataları karşılaştırılmıştır.

- Bagging'in hataları çoğu veri kümesinde C4.5'ten düşüktür. Kırmızıyla işaretli yalnız üç veri kümesinde tek ağaç daha iyidir; örneğin birinde tek ağaç 4.80, bagging 5.43 hata yapmıştır.
- Boosting'de tek ağacın daha iyi olduğu 5-6 veri kümesi vardır; büyük çoğunlukta yine boosting daha iyidir.
- Bagging ile boosting karşılaştırıldığında hata oranlarının oranı 0.93 civarındadır; aralarında çok büyük bir fark yoktur.

<!-- BELİRSİZ: Bu tablonun (yaklaşık 01:08 ve 01:26) karesi yok; sayılar altyazıdan alındı. -->

### 10.2 Kazanma, beraberlik, kaybetme (win/draw/loss)

"Bunun sonucu bu, şunun sonucu şu, o hâlde bu daha iyi" diyebilmek için deneyler tekrarlanır; örneğin 10 katlı çapraz doğrulamayla (10-fold cross-validation) 10 test hatası elde edilir. Tablodaki hatalar bu 10 hatanın ortalamalarıdır. Win/draw/loss sütunları ise kaç kez birinin, kaç kez öbürünün kazandığını gösterir. Değerlerin toplamı her zaman 10 değildir: örneğin bir veri kümesinde bagging 9 kez kazanmış, C4.5 hiç kazanmamış, bir kez berabere kalmışlardır.

Kazanma ve kaybetme kararları hipotez testiyle, Student t-testiyle verilir; MATLAB ve Python'da bunun için hazır kütüphaneler vardır.

<!-- BELİRSİZ: Altyazıda bu bölüm "Windows" diye geçiyor; win/draw/loss olduğu ders 6'nın 02:00:00 karesindeki "Win/draw/loss" başlığından çıkarıldı. -->

### 10.3 Temel öğrenici sayısına göre hata

Slayttaki iki grafikte deneme sayısı $T$ (1'den 50'ye) arttıkça hata gösterilir (ekrandan, 01:30:00):

- Chess: boosting yaklaşık %8.5'ten %4 civarına, bagging yaklaşık %11'den %8 civarına iner. Bu veri kümesinde boosting daha başarılıdır.
- Colic: bagging yaklaşık %15 civarında, boosting %18 civarında kalır. Bu veri kümesinde bagging daha başarılıdır.

Bu yüzden "bagging daha iyidir" ya da "boosting daha iyidir" diye kesin bir şey söylenemez. Bütün veri kümelerinde bütün algoritmalardan daha başarılı tek bir algoritma yoktur (no free lunch); olsaydı yalnız o anlatılırdı. Veri kümesinden veri kümesine farklılık olması makine öğrenmesinin bir yönüdür.

## 11. Rastsal Altuzaylar (Random Subspace)

### 11.1 Yöntem

Buraya kadar eğitim kümeleri farklı örnek seçimleriyle oluşturuldu. Alternatifi özelliklerle oynamaktır. Tin Kam Ho'nun 1998'de önerdiği Random Subspace algoritması, topluluktaki her öğreniciyi tüm özellikler yerine özelliklerin bir bölümüyle eğitir. Her öğrenicinin eğitim seti oluşturulurken rastgele $d$ adet özellik seçilir ve yalnız bunlar eğitim kümesine alınır. Sonuçlar demokrasi usulü birleştirilir. Hoca bagging'in de 90'ların sonunda çıktığını, boosting'in biraz daha eski olduğunu ekledi.

Satırların örnekler, sütunların özellikler olduğu bir veri tablosu düşünülürse: bütün satırlar alınır, sütunların rastgele seçilmiş $d$ adetlik bir kısmı alınır ve bunda bir temel öğrenici eğitilir; başka bir $d$ adetlik kısım başka bir öğreniciye verilir. Burada yerine koyma yoktur, çünkü aynı özelliğin veri kümesinde birden fazla kez bulunmasının bir anlamı yoktur. Toplam $D$ özellik varsa farklı alt kümeler istendiği için en fazla $D-1$ özellik seçilmelidir.

**Soru (sohbetten):** Bu yöntemde aynı özellik setine sahip birden fazla model olabilir mi?

**Cevap:** Rastgele seçim yapıldığı için mümkündür, ama istenen bir şey değildir; öğreniciler deterministikse sonuçları aynı olur. Özellik sayısı azken bunun olasılığı daha yüksektir, özellik sayısı fazlayken pek olmaz.

### 11.2 Kaç özellik kullanılacak?

Slayttaki grafikte (perceptron ile bölme) x ekseni ağaç sayısı (1-50), y ekseni doğruluk yüzdesidir; 135, 90, 45, 23 ve 12 rastgele özellik için eğriler vardır (ekrandan, 01:35:00). Hoca veri kümesinin yanlış hatırlamıyorsa 180 özellikli olduğunu söyledi. Ağaç sayısı arttıkça başarı artar; alttaki iki eğri (az özellikli olanlar) dışındakiler arasında sonda büyük fark yoktur.

Bu tek bir veri kümesindeki denemedir ve genel bir sonuç çıkarmak mümkün değildir. Teorik bir sonuç olmasa da özelliklerin yaklaşık yarısını kullanmanın iyi sonuç verdiğine dair genel bir kabul vardır.

> **Ders sonrası not:** Hoca bu kabulü anlatırken bir yerde "eğitim kümesindeki örnek sayısının yarısı" dedi; bağlam özellik seçimi olduğu için kastedilen büyük olasılıkla özellik sayısının yarısıdır.

**Soru:** Grafikteki x ekseni ağaç sayısı mı, özellik sayısı mı?

**Cevap:** Ağaç sayısıdır. Bir eğri üzerindeki her nokta, örneğin 45 rastgele özellikle oluşturulmuş ağaçlardan 5, 6, 7, … tanesinin kararları birleştirildiğinde elde edilen başarıyı gösterir; bir eğri boyunca rastgele seçilen özellik sayısı aynıdır.

### 11.3 Eğrilerdeki zikzaklar

Hoca grafikteki bir duruma dikkat çekti: bir ağaçtan ikiye geçince başarı düşüyor, üçte çıkıyor, dörtte düşüyor, beşte çıkıyor, altıda yine düşüyor. Normalde ağaç eklendikçe başarı artmalıdır; genel eğilim de artış yönündedir. Bu zikzakların nedeni nedir?

**Soru (hocadan):** Arada neden düşüşler var?

**Cevap (bir öğrenci):** Ağaç sayısı çift olduğunda oylamada sorun çıkıyor. Hoca bunu doğruladı: çift sayıda ağaçta aynı örnek için bir ağaç A, öbürü B diyebilir; beraberlikte rastgele bir atama yapılır ve bu başarıyı düşürür.

### 11.4 Ağaçlar nasıl oluşturulmalı?

Ağaçları oluşturmaktan kastedilen, bölmelerin nereden geçeceğini bulma yöntemidir. Slaytta farklı yöntemler denenmiştir. Şimdiye kadar görülen düğümler tek değişkenli (univariate) idi: her düğümde tek bir özellik vardır. SVM ya da perceptron kullanılırsa çok değişkenli (multivariate) bir düğüm oluşur; eksenlere dik olmak zorunda olmayan, bütün özellikleri içeren doğrusal bir karar sınırı çizilebilir. Gain Ratio tek değişkenlidir; gözetimli kümeleme gibi yöntemler de denenmiştir. Kabaca bakıldığında Gain Ratio daha karmaşık yöntemlere göre genel olarak iyi bir başarı elde etmiştir ve hesaplama maliyeti de düşüktür. Bu yüzden topluluk üretiminde ağaç oluşturmak için iyi bir yöntem olarak değerlendirilir; ama bu yalnız bu veri kümeleri için çıkmış bir sonuçtur.

<!-- BELİRSİZ: Bölme yöntemleri karşılaştırma slaytının (slayt 25) karesi yok; yöntem adları altyazıdan alındı. -->

### 11.5 Tüm ağaçlar mı, en başarılılar mı?

50 ağaç üretildikten sonra hepsi mi kullanılmalı, yoksa her ağacın başarısına bakıp en başarılı $K$ tanesi mi seçilmeli? Slayttaki dna verisi grafiğinde (ekrandan, 01:40:00) ağaçlar başarılarına göre sıralanarak birleştirildiğinde (sorted trees) ve üretildikleri sırada birleştirildiğinde (unsorted trees) doğruluk eğrileri çok yakındır; ikisi de 50 ağaçta yaklaşık %95'e ulaşır. Oysa tekil başarılar yüksekse birleşimin daha iyi olacağını biliyoruz.

**Soru (hocadan):** En başarılı 10 ağacı birleştirmek neden 50 ağacın hepsini birleştirmekten daha iyi çıkmıyor?

**Cevap:** Öğrencilerden aşırı öğrenme ve oylama sonucunun değişmemesi gibi öneriler geldi; hoca bunların asıl neden olmadığını belirtti. Asıl neden, tekil ağaçların başarısı yükseldikçe çeşitliliğin azalmasıdır. Yalnız en başarılılar kullanıldığında bunlar birbirine benzer ve benzer şeyleri birleştirmenin pek anlamı kalmaz. Bu yüzden sıralı ve sırasız ağaçların performansları çok benzer çıkar.

### 11.6 Algoritmaların karşılaştırılması

Slaytta birkaç veri kümesinde Random Subspace, Bootstrapping (bagging'in diğer adı), Boosting, tek C4.5 ve budanmış (pruned) C4.5 karşılaştırılmıştır. Tekil ağaçlar her zaman alttadır; örneğin vehicle veri kümesinde üç topluluk algoritmasının hepsi tek ağaçtan başarılıdır. Bazı veri kümelerinde Random Subspace, bazılarında Boosting, bazılarında bagging öne çıkar. Bagging, boosting ve random subspace için birinin diğerinden çok daha iyi olduğu söylenemez; birbirleriyle yarışabilen algoritmalardır.

<!-- BELİRSİZ: Bu karşılaştırma grafiklerinin (slayt 28-30) karesi yok. -->

## 12. Rastsal Ormanlar (Random Forest)

### 12.1 Tanım

Random Forest algoritması 2001'de ortaya çıktı. Topluluk yöntemlerinin dezavantajlarından biri uzun eğitim süresidir: 10 ya da 100 model üretmek süreyi kabaca o kadar katına çıkarır. Random Forest'ın çok güzel bir özelliği, belli koşullarda tek bir ağaçtan daha hızlı bir topluluk üretebilmesidir.

Slayttaki tanım (ekrandan, 01:45:00):

- Öncekilerin aksine sadece karar ağaçları için tasarlanmış bir topluluk yöntemidir. Bagging, boosting ve random subspace'te temel öğrenici olarak karar ağacı, SVM ya da yapay sinir ağı kullanılabilir; Random Forest'ta, adından da anlaşılacağı gibi, yalnız ağaçlar kullanılır.
- İki tür rastgelelik kullanır:
  - Bagging: her ağacın eğitimi için orijinal eğitim kümesiyle aynı boyutta yeniden örnekleme yapar.
  - Rastgele özellikler: her karar düğümünde tüm özellikler yerine rastgele seçilmiş $F$ tanesini (RI) ya da $d$ adet özelliğin doğrusal kombinasyonlarından $F$ adedini (RC) kullanır.

Yani çok orijinal bir şey yapmaz, daha önceki iki yöntemi birleştirir. Random Subspace'te özellikler en başta bütün ağaç için seçilirken Random Forest her düğümde, önceki seçimlerden bağımsız olarak, yeniden rastgele özellik seçer. Budanmamış ağaçlar kullanılır ve sonuçlar demokrasi usulü birleştirilir.

### 12.2 Eğitim hızı

Eğitim hızını en çok etkileyen faktör $F$'dir. Normal bir ağaçta bir düğümde veri iki parçaya bölünürken bütün özellikler için bütün olası eşik değerleri denenir ve her özellik-eşik ikilisi için sonuç hesaplanır. Random Forest bunun yerine özelliklerin rastgele seçilmiş bir kısmını kullanır ve bu rastgeleliği oldukça abartır: "single input" seçeneğinde her düğümde tek bir özellik seçilir. Varsayılan değer ise özellik sayısının 2 tabanında logaritmasıdır.

- 1024 özellik varsa her düğümde 1024 yerine $\log_2 1024 = 10$ özellik denenir.
- Özellik sayısı bir milyon civarındaysa her düğümde yaklaşık 20 deneme yeter.

> **Ders sonrası not:** Hoca ikinci örnekte "1000 milyon" dedi; $\log_2(10^6) \approx 19.9$, $\log_2(10^9) \approx 29.9$'dur (python ile hesaplandı). "20 kontrol" ifadesine göre kastedilen büyük olasılıkla bir milyon özelliktir.

Böylece özellik sayısı yüksekse tek bir düğümün üretimi, her düğümde her şeyi deneyen karar ağaçlarına göre çok hızlanır.

### 12.3 Hangi ağaç daha büyük olur?

**Soru (hocadan):** Düğümlerde rastgele seçim yapınca mı, bütün olasılıkları kontrol edince mi daha büyük bir ağaç üretilir?

**Cevap:** Bir öğrenci bütün olasılıklar kontrol edilince ağacın daha büyük olacağını önerdi; hoca ağaç yapısının iki durumda da aynı türden olduğunu (her düğümde "47. özellik 3.5'ten büyük mü" gibi bir test), sorunun düğüm sayısıyla ilgili olduğunu belirtti. Çok iyi bir özellik varsa rastgele seçimde o özellik seçilmeyebilir; bu durumda bölme çok iyi olmayan bir özellikten yapılır ve iş uzar. 1024 özellik içinden yalnız birkaçı iyiyse, rastgele seçilen 10 özelliğin içinde onların bulunma olasılığı düşüktür. Bu yüzden Random Forest aslında işi uzatan bir algoritmadır: bütün özelliklere bakılsa çok daha küçük, kompakt bir ağaç çıkardı; Random Forest'ın ağaçları ise bütün olasılıkların denendiği ağaçlardan çok daha büyüktür. Düğüm sayısı artsa da, özellik sayısı fazlaysa toplam hız açısından yine daha başarılı olabilir.

### 12.4 Forest-RI sonuçları

Slayttaki tabloda AdaBoost, Selection, Forest-RI single input ve One tree hata yüzdeleri vardır (ekrandan, 01:50:00):

| Veri kümesi | AdaBoost | Selection | Forest-RI single input | One tree |
|---|---|---|---|---|
| Breast cancer | 3.2 | 2.9 | 2.7 | 6.3 |
| Diabetes | 26.6 | 24.2 | 24.3 | 33.1 |
| Sonar | 15.6 | 15.9 | 18.0 | 31.7 |
| Vowel | 4.1 | 3.4 | 3.3 | 30.4 |
| Ionosphere | 6.4 | 7.1 | 7.5 | 12.7 |
| Vehicle | 23.2 | 25.8 | 26.4 | 33.1 |
| German credit | 23.5 | 24.4 | 26.2 | 33.3 |
| Image | 1.6 | 2.1 | 2.7 | 6.4 |
| Ecoli | 14.8 | 12.8 | 13.0 | 24.5 |
| Votes | 4.8 | 4.1 | 4.6 | 7.4 |
| Liver | 30.7 | 25.1 | 24.7 | 40.6 |
| Letters | 3.4 | 3.5 | 4.7 | 19.8 |
| Sat-images | 8.8 | 8.6 | 10.5 | 17.2 |
| Zip-code | 6.2 | 6.3 | 7.8 | 20.6 |
| Waveform | 17.8 | 17.2 | 17.3 | 34.0 |
| Twonorm | 4.9 | 3.9 | 3.9 | 24.7 |
| Threenorm | 18.8 | 17.5 | 17.5 | 38.4 |
| Ringnorm | 6.9 | 4.9 | 4.9 | 25.7 |

Tabloda Glass satırı da vardır (AdaBoost 22.0, Selection 20.6, One tree 36.9); Forest-RI değeri karede imleçle kapalıdır. Tek ağaca göre bütün topluluk algoritmaları belirgin biçimde iyidir.

### 12.5 Gürültüye dayanıklılık

Bir sonraki karşılaştırmada eğitim kümesinin etiketlerinin bir kısmı rastgele değiştirilerek bozulur; test kümesi olduğu gibi kalır. Bu durumda AdaBoost'un hatası büyük oranda artar, Random Forest'ın hatası ise o kadar artmaz (bir veri kümesinde garip biçimde azalmıştır bile).

**Soru (hocadan):** AdaBoost neden gürültüye karşı dayanıksızdır?

**Cevap (bir öğrenci):** AdaBoost hatalı tahmin edilen örneklere odaklandığı için onların seçilme olasılığını artırır; gürültülü örnekler de sürekli hatalı tahmin edildiğinden algoritma bilerek üretilen bu gürültülere odaklanır. Hoca bunu doğruladı.

## 13. Aşırı Rastsal Ormanlar (Extremely Randomized Trees)

### 13.1 Fikir

2006'da Pierre Geurts, Damien Ernst ve Louis Wehenkel tarafından önerilmiştir (ekrandan, 01:55:00). Fikir şudur: öğrenmede rastgelelik ne kadar fazla olursa temel öğrenicilerin kararları birbirinden o kadar farklı olur. O hâlde ağacın karar düğümleri rastgele üretilsin.

Normal bir ağaçta, örneğin 100 özellik varken her özelliğin bütün olası eşik değerleri hesaplanır, her birinin iyiliği ölçülür ve en iyi özellik-eşik ikilisi seçilir. Random Forest'ta özelliklerin yalnız $K$ tanesi alınır, ama o $K$ özelliğin bütün olası eşikleri denenir. Aşırı rastsal ormanlarda yine $K$ rastgele özellik seçilir, ama her biri için yalnız bir rastgele eşik değeri belirlenir; bütün olası eşiklere bakılmaz. $K$ adet özellik-eşik ikilisinden en iyisi karar düğümü olur.

### 13.2 Ağaç büyüklüğü

**Soru (hocadan):** Aşırı rastsal ormanların ağaçları Random Forest'ın ağaçlarından daha mı büyük, daha mı küçük olur?

**Cevap:** Daha büyük olur. Bütün olası eşikler yerine rastgele eşiklerden hareket edildiği için iyi bir eşiği kaçırma olasılığı yüksektir; iyi bir yerden bölünemeyince iş uzar. Ağaç büyüklüğü sıralaması kabaca şöyledir:

- Tekil, bütün olasılıkları deneyen tam ağaçlar en küçüktür.
- Random Forest'ın ağaçları onlardan büyüktür.
- Random Subspace'in ağaçları ondan da büyüktür.
- Extremely Randomized Trees'in ağaçları en büyüktür.

### 13.3 Parametreler, avantajlar ve dezavantajlar

Parametreler $M$ (temel öğrenici sayısı) ve $K$'dır (rastgele seçilecek özellik sayısı). Önerilen kullanım: sınıflandırmada $K$ orijinal özellik sayısının karekökü kadar, regresyonda özellik sayısı kadar alınabilir.

- Avantajlar: rastgelelik sayesinde çeşitlilik çok yüksektir. Özellik-eşik ikilisini bulmak için olasılıkların çok azı denendiği için eğitim çok hızlıdır.
- Dezavantajlar: ağaç sayısı değil, ağaçların kendileri büyüktür; daha fazla bellek gerekir. Test de daha uzun sürer: maksimum derinliği 5 olan bir ağaçla 500 olan bir ağaç karşılaştırılırsa ikincisinde testte çok daha fazla kontrol yapmak gerekir.

### 13.4 Win/draw/loss karşılaştırması

Slayttaki tabloda tek ağaç (PST), Bagging (TB), Random Subspaces (RS), Random Forest (RF) ve Extremely Randomized Forest (ET) sınıflandırma ve regresyon problemlerinde karşılaştırılmıştır (ekrandan, 02:00:00). Her hücredeki üçlü, sütundaki yöntemin satırdaki yönteme karşı kazanma/beraberlik/kaybetme sayısıdır (hocanın okuduğu ET sütunuyla tutarlı okunuş):

| Sınıflandırma | PST | TB | RS | RF | ET |
|---|---|---|---|---|---|
| PST | – | 8/4/0 | 11/1/0 | 11/1/0 | 10/2/0 |
| TB | 0/4/8 | – | 7/5/0 | 7/5/0 | 7/5/0 |
| RS | 0/1/11 | 0/5/7 | – | 0/8/4 | 2/10/0 |
| RF | 0/1/11 | 0/5/7 | 4/8/0 | – | 5/7/0 |
| ET | 0/2/10 | 0/5/7 | 0/10/2 | 0/7/5 | – |

| Regresyon | PST | TB | RS | RF | ET |
|---|---|---|---|---|---|
| PST | – | 10/2/0 | 8/4/0 | 10/2/0 | 10/2/0 |
| TB | 0/2/10 | – | 0/9/3 | 1/11/0 | 4/8/0 |
| RS | 0/4/8 | 3/9/0 | – | 4/8/0 | 4/7/1 |
| RF | 0/2/10 | 0/11/1 | 0/8/4 | – | 3/7/2 |
| ET | 0/2/10 | 0/8/4 | 1/7/4 | 2/7/3 | – |

Hocanın sınıflandırma problemleri için ET sütunundan okuduğu sonuç: 12 veri kümesinde ET tek ağacı 10 kez yenmiş ve 2 kez berabere kalmış, bagging'i 7 kez yenmiş (5 beraberlik), Random Subspace'i 2 kez, Random Forest'ı 5 kez yenmiş ve hiç yenilmemiştir. Hoca önce yanlış yere bakıp sonra düzeltti.

## 14. Bir Algoritmayı Başarılı Yapan Nedir?

Yöntemler anlatılırken genelde yöntemlerin kendi makaleleri kullanılır, ve önerildikleri makalelerde yöntemler genelde diğerlerinden daha iyi görünür. Az sayıda veri kümesi üzerinde yapılan denemeler daha sorunludur. Çok sayıda veri kümesinde denenmiş ve başkaları tarafından tekrarlanıp doğrulanmış sonuçlar çok daha önemlidir.

Örneğin Extremely Randomized Trees çok ünlü bir algoritma değildir. Random Forest ise çok kullanılır, çünkü çok sayıda kişi tarafından başarıyla kullanılmış ve birbirinden çok farklı alanlarda diğer algoritmalardan daha başarılı olduğu gösterilmiştir. Kullanım kolaylığı ve kütüphanesinin olması da etkendir, ama daha önemlisi yazar dışındaki araştırmacıların kendi veri kümelerinde, kendi alanlarında, kendi amaçlarına uygun kullanarak iyi sonuçlar almasıdır.

> **Hocanın vurgusu:** Bir algoritmayı başarılı yapan, başkalarının onu kendi problemlerinde kullanıp iyi sonuç almasıdır. Bir algoritma yayımlandığı anda popüler olmaz; bu çok uzun sürebilir.

Rotasyon ormanları ve iyileştirilmiş uzay ormanları sonraki derse bırakıldı.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:16:39): Kollektif öğrenmede temel öğrenicilerin karar çeşitliliği dışında istenen ikinci kriter nedir, ve neden çeşitlilikle uzlaşmaz?

> **Çözüm:** Her tekil öğrenicinin doğruluğunun yüksek olması (bir öğrencinin cevabı). Tekil başarı arttıkça öğreniciler aynı örneklerde doğru karar verdiği için kararları birbirine benzer, yani çeşitlilik azalır.

**Soru 2** (ekrandan, 00:30:00): Bagging'de $n$ örnekten yerine koyarak seçilen $n$ örnek neden tüm örneklerin yaklaşık %63.2'sini içerir?

> **Çözüm:** Bir örneğin tek çekilişte seçilmeme olasılığı $1-1/n$, $n$ çekilişte hiç seçilmeme olasılığı $(1-1/n)^n \approx e^{-1} = 0.368$'dir. Seçilme olasılığı $1-0.368 = 0.632$'dir.

**Soru 3** (ekrandan, 00:35:00 ve 00:40:00): Eğitim verisi $x \le 0.3$ ve $x \ge 0.8$ için $+1$, $0.4$-$0.7$ arası $-1$ olan 10 örnekten oluşuyor. Tek eşikli sınıflandırıcılarla 10 turluk bagging topluluğu kuruluyor. 7.2'deki tabloda verilen kurallarla topluluğun $x = 0.1$ ve $x = 0.4$ için çıkışı nedir?

> **Çözüm:** $x = 0.1$'de Tur 1-5 ve 10 $+1$, Tur 6-9 $-1$ der: 6'ya 4, çıkış $+1$. $x = 0.4$'te yalnız Tur 2 ve 10 $+1$ der: 2'ye 8, çıkış $-1$. Bütün noktalar için topluluk gerçek sınıfları verir, başarı %100'dür (python ile doğrulandı).

**Soru 4** (ekrandan, 00:45:00): Bagging için temel öğrenici olarak 1NN mi, karar ağacı mı, yapay sinir ağı mı uygundur?

> **Çözüm:** Karar ağacı ve yapay sinir ağı. Bagging eğitim verisine duyarlı (yüksek varyanslı) öğrenicilerde iyi çalışır. 1-NN eğitim kümesindeki küçük farklara karşı duyarsızdır; slayttaki karşılaştırmada 1-NN'de topluluk ile tek öğrenicinin hatası aynı çıkmıştır.

**Soru 5** (derste sözlü, 01:03:13): AdaBoost'ta bir öğrenicinin hata oranı $\epsilon_j = 0.1$ ise $\beta_j$ nedir, doğru sınıflanan örneklerin olasılığına ne olur?

> **Çözüm:** $\beta_j = 0.1/(1-0.1) = 1/9 \approx 0.111$. Doğru sınıflanan örneklerin olasılığı $1/9$ ile çarpılarak azalır, yanlışlarınki aynı kalır; normalizasyondan sonra yanlış sınıflananların payı artar. Testte bu öğrenicinin ağırlığı $\log(1/\beta_j) = \ln 9 \approx 2.20$ olur (ağırlık hesabı derste sayısal olarak yapılmadı, python ile hesaplandı).

**Soru 6** (derste sözlü, 01:36:08): Random Subspace grafiğinde ağaç sayısı birden ikiye, üçten dörde, beşten altıya geçerken başarıda düşüşler görülüyor. Bu zikzakların nedeni nedir?

> **Çözüm:** Çift sayıda ağaçta oylamada beraberlik çıkabilir (bir ağaç A, öbürü B der); beraberlikte rastgele atama yapılır ve başarı düşer (bir öğrencinin cevabı, hoca doğruladı).

**Soru 7** (derste sözlü, 01:39:59): Ağaçları başarılarına göre sıralayıp en başarılıları birleştirmek, hepsini rastgele sırada birleştirmekten neden belirgin biçimde iyi çıkmaz?

> **Çözüm:** Tekil ağaçların başarısı yükseldikçe çeşitlilikleri azalır. En başarılı ağaçlar birbirine benzer; benzer kararları birleştirmek topluluğa pek bir şey katmaz.

**Soru 8** (derste sözlü, 01:50:25): Her düğümde özelliklerin yalnız küçük, rastgele bir kısmını denemek mi, bütün olasılıkları denemek mi daha büyük bir ağaç üretir?

> **Çözüm:** Rastgele seçim daha büyük ağaç üretir. İyi özellikler rastgele altkümeye girmeyebilir; bölmeler daha kötü özelliklerden yapılır ve ağaç uzar. Random Forest ağaçları tam ağaçlardan büyüktür, ama düğüm başına maliyet çok düştüğü için özellik sayısı yüksekse toplam süre yine kısa olabilir.

**Soru 9** (derste sözlü, 01:53:55): Eğitim etiketlerinin bir kısmı rastgele bozulduğunda AdaBoost'un hatası neden Random Forest'tan çok daha fazla artar?

> **Çözüm:** AdaBoost yanlış sınıflanan örneklerin seçilme olasılığını artırır. Etiketi bozulmuş örnekler sürekli yanlış sınıflandığından algoritma giderek bu gürültülü örneklere odaklanır (bir öğrencinin cevabı, hoca doğruladı).

**Soru 10** (derste sözlü, 01:56:59): Aşırı rastsal ormanların ağaçları Random Forest'ın ağaçlarından daha mı büyük, daha mı küçük olur?

> **Çözüm:** Daha büyük olur. Eşikler de rastgele seçildiği için iyi bir eşiği kaçırma olasılığı yüksektir; iyi yerden bölünemeyince ağaç uzar.

**Soru 11** (ekrandan, 02:15:00): Ödev 2'nin akademik içeriği. Bagging, Boosting ve Random Forest algoritmalarını temel öğrenici olarak tek değişkenli karar ağaçları kullanarak karşılaştırın.

- ZeroRule < 0.7 olan en az 12 UCI veri kümesi kullanılacak. ZeroRule, bütün örnekleri eğitim kümesinde en sık görülen sınıfa atayan algoritmadır; bu koşul hiçbir sınıfın veri kümesindeki oranının 0.7'den büyük olmaması demektir.
- Temel öğrenicilerin maksimum derinliği 1, 2, 3, 5, 10 ve sonsuz (tamamen saf ağaç) olacak; tekil öğrenici sayısı tüm denemelerde 100.
- Aynı derinlikteki ağaçlarla oluşturulan topluluklar ikili t-test (%95) ile karşılaştırılacak; 5×2 katlı çapraz doğrulama kullanılacak; karşılaştırmaya tüm örneklerle oluşturulan tekil ağaçlar da katılacak.
- İncelenecek ilişkiler: maksimum derinlik ile topluluk başarısı, maksimum derinlik ile ortalama tekil öğrenici başarısı, maksimum derinlik ile tekil öğrenici kararlarının benzerliği; algoritmaların eğitim sürelerinin karşılaştırması; bulguların beklentilerle uyuşup uyuşmadığının yorumu.
- Hiperparametreler: bagging'de $n$ örnekten $n$ örnek seçilir; boosting'in ayrıca bir hiperparametresi yoktur; Random Forest'ta seçilen özellik sayısı varsayılan $\log_2$(özellik sayısı) bırakılır. Yalnız maksimum derinlik değiştirilir.

## Dersin Toparlaması

Bu derste kollektif öğrenmenin temel ikilemi, yani tekil öğrenicilerin başarısı ile kararlarının çeşitliliği arasındaki gerilim, somut yöntemler üzerinden işlendi. Çeşitlilik farklı algoritmalar, farklı hiperparametreler ya da farklı eğitim setleriyle sağlanabilir; ders en basit ve en çok kullanılan yola, tek bir eğitim kümesinden farklı kümeler üretmeye odaklandı. Bagging örnekleri yerine koyarak yeniden örnekler, ortalama %63.2 farklı örnek içeren kümelerle yüksek varyanslı öğrenicileri eğitip oylamayla birleştirir; tek eşikli sınıflandırıcılarla doğrusal ayrılamayan bir problemin %100 çözülmesi, basit öğrenicilerden karmaşık karar sınırı üretilebildiğini gösterdi. AdaBoost hata yapılan örneklerin seçilme olasılığını artırarak ardışık öğreniciler kurar ve testte hatası düşük öğrenicilere daha çok ağırlık verir, ama bu yüzden etiket gürültüsüne duyarlıdır.

Özellik ekseninde Random Subspace her öğreniciye rastgele bir özellik alt kümesi verir; Random Forest bagging ile düğüm düzeyinde rastgele özellik seçimini birleştirerek hem çeşitlilik hem hız kazanır; Extremely Randomized Trees eşikleri de rastgele seçerek rastgeleliği en uca taşır, karşılığında büyük ağaçlar ve uzun test süresiyle öder. Karşılaştırmalar hiçbir yöntemin her veri kümesinde en iyi olmadığını gösterdi. Sonraki derste rotasyon ormanları, iyileştirilmiş uzay ormanları ve diğer kollektif öğrenme metotlarıyla devam edilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
