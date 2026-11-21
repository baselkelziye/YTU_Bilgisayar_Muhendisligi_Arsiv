# Ders 1 Genişletilmiş Notu: Kollektif Öğrenmeye Giriş, Bias-Varyans ve Çeşitlilik

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Isınma: Kollektif Öğrenme Nedir? (Grup Tahminleri)
- 2. Dersin Yeni Kapsamı
- 3. Kollektif Öğrenmenin Tanımı ve Temel Şeması
- 4. Nerelerde Kullanılır?
- 5. Neden Kullanılır?
- 6. Neden Daha Doğru Sonuçlar? Oy Çokluğu Örneği
- 7. Dart Sorusu
- 8. Bias ve Varyans
- 9. Bias-Varyans Ayrıştırması ve Ortalamanın Üstünlüğü
- 10. Dart Tahtasında Bias ve Varyans
- 11. Ortalama Almak Karar Sınırını Nasıl Değiştirir?
- 12. Kollektif Öğrenmenin İki Bileşeni ve 2'li Optimizasyon
- 13. Dezavantajlar
- 14. Derin Öğrenmede Kollektif Öğrenme
- 15. Bilimsel Okuma Üzerine Bir Tavsiye
- Örnek Sorular

## 1. Isınma: Kollektif Öğrenme Nedir? (Grup Tahminleri)

Hoca, dersin konusunu anlatmadan önce öğrencileri Zoom'un küçük oda (breakout room) özelliğiyle 3-4 kişilik gruplara ayırdı ve her gruptan, "kollektif öğrenme ne olabilir?" sorusunu kendi aralarında tartışıp bir tanım getirmesini istedi. Bu etkinliğin kendisi de dersin işleniş biçimine bir göndermeydi: ders "hep birlikte öğrenme" mantığıyla, ödevlerin sınıfta birlikte incelenip tartışıldığı bir yapıda yürüyecek.

Grupların getirdiği tanımlar şöyle özetlenebilir:

- Birden fazla algoritmanın ya da modelin bir arada kullanılıp daha iyi bir sonuç elde edilmeye çalışıldığı yöntem. Bu grup, etkinliğin kendisinin de buna örnek olduğunu söyledi: her grubun kendi fikri var ve fikirler bir araya gelince doğru fikri bulma ihtimali artıyor.
- Birden fazla bilgi kaynağı olduğunda en doğru bilgiyi elde etmek için çeşitlilikten faydalanma yöntemi.
- Verinin farklı modellerle eğitilip bu modellerin bilgilerinin birleştirilerek daha doğru bir sonuca ulaşılması ("bir elin nesi var, iki elin sesi var").
- Makine öğrenmesi ve derin öğrenme yöntemlerinin daha iyi modeller ve daha doğru sonuçlar için müşterek kullanılması.

**Soru:** Modellere verilmeden önce veri alt kümelere mi bölünüyor, yoksa bütün modellere aynı veri mi veriliyor? **Cevap:** İkisi de mümkün. Çeşitlilik üretmek için ya aynı veri birbirinden farklı modellere verilir ya da aynı modele farklı veriler verilir. Önemli olan, ortaya çıkan tahminlerin birbirinden farklı olmasıdır. Bu konu ilerleyen derslerde ayrıntılı işlenecek.

Hoca grupların tanımlarında yanlış olan pek bir şey olmadığını söyledi.

## 2. Dersin Yeni Kapsamı

Dersin slaytı (`kolektif_ogrenme_nedir.pptx`) "Yeni kapsam, Nedir?, Nerelerde kullanılır?, Neden kullanılır?, Avantaj ve dezavantajları" başlıklarıyla açılıyor (ekrandan, 01:05:00).

Dersin değişmeyen çekirdeği, farklı modeller üretip kararlarını birleştirmektir. Önceki dönemlerde bu "farklı modeller" hep karar ağaçlarıydı. Bu dönem kapsama kırmızıyla işaretlenen yeni kısımlar eklendi:

- Temel modeller arasına yapay sinir ağları (YSA) da katıldı.
- Optimizasyon işlenecek. Hoca bunun derin öğrenme için değil, kollektif öğrenmeyi anlamak için gerekli olduğunu, YSA'larda da işe yarayacağını söyledi.
- Derin öğrenmede kollektif öğrenme yaklaşımlarının nasıl kullanıldığı anlatılacak.

Klasik kollektif öğrenme yöntemlerinden sonra boosting ve onun teorisi (teorem-ispat biçiminde), ardından YSA'larla kollektif öğrenme ve makine öğrenmesindeki yeni nesil problemler ve yaklaşımlar ele alınacak.

## 3. Kollektif Öğrenmenin Tanımı ve Temel Şeması

Elimizde bir tahminleyici sistem olduğunu düşünelim. Tahmin edilen şey bir sayı da olabilir (regresyon), bir kategori de (sınıflandırma). Kollektif öğrenme, tek bir model kullanmak yerine birden fazla modelin bu tahmin sürecine katılmasıdır. İngilizcesi **ensemble learning**'dir.

"Tahmin sürecine katılmak" bilerek geniş tutulmuş bir ifadedir:

- Modellerin tahminlerinin ortalamasını almak ya da tahminleri başka bir şekilde birleştirmek.
- Modellerin birbirlerinin eğitim süreçlerine katkı vermesi: birlikte öğrenmeleri, birbirlerinden öğrenmeleri. Bu dönem bu tür yaklaşımlar da kollektif öğrenme kapsamında ele alınacak.

Slayttaki örnek şema, kararların birleştirilmesine dayalı en basit kullanımı gösteriyor. Klasik yöntemde elimizdeki veri kümesiyle bir model eğitilir ve test kümesindeki örneklerin etiketleri ya da değerleri bu modelle tahmin edilir. Kollektif öğrenmede tek bir model yerine çok sayıda model kullanılır. Çok sayıda model eğitebilmek için farklı verilere ihtiyaç vardır; bu farklı veriler orijinal veriden üretilir. En sonda bu farklı verilerle eğitilmiş modellerin her birinin tahmini kullanılarak test örneği için nihai tahmin verilir. Hoca bunun yollardan yalnızca biri olduğunu, başka türlerinin de görüleceğini belirtti.

## 4. Nerelerde Kullanılır?

Kollektif öğrenme ilke olarak bütün makine öğrenmesi problemlerinde kullanılabilir; "şurada olur, burada olmaz" diye bir sınır yoktur. Dersin uygulamalarında sınıflandırmaya, bu dönem özellikle de metin verilerine ağırlık verilecek. Bu, görüntü, ses ya da standart tablo verilerinin hiç kullanılmayacağı anlamına gelmiyor. <!-- BELİRSİZ: 01:09:16'da "kalın based yapılar" diye geçen ifade (büyük olasılıkla "graph based") altyazıdan net değil. -->

## 5. Neden Kullanılır?

### 5.1 Çünkü biz de kullanıyoruz

Slaytta ilk gerekçe "Çünkü biz de kullanıyoruz" diye yazılı (ekrandan, 01:10:00):

- Önemli kararlarımızı farklı zamanlarda tekrar tekrar düşünürüz.
- Önemli kararlarımızı birçok bilene danışırız.
- Kritik bir ameliyatta tek bir doktorun görüşü yerine birçok görüş alırız.
- Doktorlar konsültasyon yaparlar.
- Şirketleri yönetim kurulları yönetir.
- Devletleri meclisler yönetir.

Hoca birinci maddeyi, önemli bir karar verirken onu kafamızda tekrar tekrar döndürmemizle açıkladı: tek seferde karar verip hemen uygulamayız, çünkü önemli kararlar kritik sonuçlara yol açabilir. Böylece farklı zamanlardaki kendimizle bir tür kollektif öğrenme yapmış oluruz. Ameliyat örneğinde de bir doktor kesin ameliyat gerektiğini söylese bile genelde başka doktorların görüşü alınır. Konsültasyonda ise bir hastanın durumu hakkında, farklı uzmanlık alanlarından olabilen birçok doktor fikrini söyler; birçok organı ya da sistemi etkileyen bir hastalıkta her sistemin uzmanı bulunur ve tedavi süreci bu doktorların ortak kararıyla belirlenir.

### 5.2 Veri çok büyük

Makine öğrenmesi açısından bakıldığında, verimiz tek bir öğrenici tarafından modellenemeyecek kadar büyük olabilir. Bu, ya hiç modellenemiyor ya da aşırı yavaş modelleniyor demektir: örneğin eğitim süresi örnek sayısıyla doğrusal değil, çok daha hızlı (hoca "eksponansiyel" dedi) artıyorsa, örnek sayısını iki katına çıkarmak eğitim süresini iki katından çok daha fazla artırır.

Böyle bir durumda veri alt kümelere bölünür. Örneğin 100 bin örnek 100 parçaya ayrılır; binlik bir parçanın eğitimi yeterince kısa sürüyorsa her alt küme ayrı bir öğreniciyle modellenir ve sonuçlar birleştirilir.

### 5.3 Veri çok küçük

Veri çok küçükse resampling teknikleriyle yeni alt kümeler elde edilebilir. Verinin kendisini doğrudan kullanmak yerine yeniden örneklemeyle çoğaltılmış veri kümeleri üretmek mümkündür. Bu teknikler ilerleyen derslerde görülecek.

### 5.4 Verinin karmaşıklığı yüksek

Slayt bu durumu şöyle özetliyor (ekrandan, 01:15:00): elimizdeki öğrenicinin karmaşıklığı veriyi modellemeye yetmiyor; veriden resampling ile yeni alt kümeler elde edilir, her alt küme ayrı bir öğreniciyle modellenir ve sonuçlar birleştirilir.

Hocanın örneği: elimizde yalnız iki sınıflı ve doğrusal ayrım yapabilen bir sınıflandırıcı var (doğrusal ayrım yapabilen bir sınıflandırıcı zaten en fazla iki sınıfı birbirinden ayırabilir). Verinin ise doğrusal ayrılabilir olmadığını biliyoruz. Doğrusal modellerin kararlarını birleştirerek doğrusal olmayan bir karar uzayı oluşturmak mümkündür. Böylece kollektif öğrenmeyle tek bir öğrenicinin üretebileceğinden daha karmaşık karar sınırları elde edilir.

### 5.5 Veri farklı türde bilgiler içeriyor

Bir örneğin hem sayısal, hem kategorik, hem de zaman serisi öznitelikleri olabilir; ama bunların hepsiyle birlikte iyi çalışan tek bir öğrenici olmayabilir. Bir model sayısal verilerle, bir başkası kategorik verilerle, bir üçüncüsü zaman serileriyle iyi çalışıyordur. Bu durumda verinin her parçası onunla iyi çalıştığı bilinen modele verilir. Satırlarda örnekler, sütunlarda öznitelikler olduğu düşünülürse bu, verinin sütun bazlı parçalanmasıdır: sayısal öznitelikler A modeline, kategorik öznitelikler B modeline, zaman serisi öznitelikleri C modeline verilir ve sonra kararlar birleştirilir.

### 5.6 Daha doğru kararlar ve tahminler

En temel gerekçelerden biri, daha doğru kararlar ve tahminler üretmektir. Bunun neden böyle olduğu bir sonraki bölümde basit bir hesapla gösterildi.

## 6. Neden Daha Doğru Sonuçlar? Oy Çokluğu Örneği

### 6.1 Oy çokluğu

Ensemble'ın kararı temel öğrenicilerin oy çokluğuyla belirlenebilir. Örneğin üç sınıflı bir sınıflandırma problemi çözüyoruz ve elimizde 10 model var. Bir test örneğinin sınıfını tahmin etmek istiyoruz. Her model bir tahmin yapar: biri "A", öteki "A", bir başkası "C", bir başkası "B" der. Bu durumda 10 oy vardır ve frekansı en yüksek olan sınıf seçilir. Buna kararları oy çokluğuyla birleştirmek denir.

### 6.2 Sayısal örnek

Slayttaki örnek (ekrandan, 01:20:00):

- Temel öğrenici sayısı $T = 25$.
- Temel öğrenicilerin hata oranı $\varepsilon = 0.35$.
- Temel öğrenici kararları birbirinden bağımsız.
- Ensemble'ın kararı temel öğrenicilerin oy çoğunluğu ile belirleniyor.
- Ensemble kararının hatası:

$$\sum_{i=13}^{25}\binom{25}{i}\varepsilon^{i}(1-\varepsilon)^{25-i} = 0.06$$

Burada "temel öğrenici" (base learner) ile kastedilen, topluluğu oluşturan tek tek modellerdir. "Kararlar birbirinden bağımsız" ifadesi, öğrenicilerin birbirine benzeyen hatalar yapmaması demektir; hepsi aynı hataları yapsaydı birleştirmenin bir anlamı olmazdı.

Hesabın mantığı (ara adım eklendi): 25 öğrenicinin oy çokluğunda ensemble'ın yanılması için en az 13 öğrenicinin yanılması gerekir. Öğreniciler bağımsız ve her biri $0.35$ olasılıkla yanıldığından, tam $i$ tanesinin yanılma olasılığı $\binom{25}{i}0.35^{i}\,0.65^{25-i}$'dir. Bu olasılıklar $i = 13$'ten $25$'e kadar toplanır. Python ile kontrol edildiğinde toplam $0.0604$ çıkıyor, yani slayttaki $0.06$ doğrudur.

Sonuç çarpıcıdır: tek başına %65 başarılı olan 25 model birleştirildiğinde topluluğun başarısı yaklaşık %94'e çıkıyor.

> **Hocanın vurgusu:** Bu formülün genel hali buradakinden çok farklı değil; nasıl ve nereden çıktığını kendiniz araştırın, benim söylediğimi kabul etmeyin, kendinizi ikna edin.

### 6.3 Ampirik sonuç: ensemble boyutu ve temel öğrenici başarısı

Bir sonraki slayt formüle değil denemeye dayanan bir grafik gösteriyor. Yatay eksende ensemble boyutu, yani topluluktaki tekil öğrenici sayısı; dikey eksende 1000 örnekten kaç tanesinin doğru bilindiği var. Üç eğri, temel öğrenici başarısının 0.60, 0.70 ve 0.80 olduğu durumları gösteriyor. Üçünde de ensemble boyutu arttıkça topluluk başarısı yükseliyor ve bireysel başarı ne kadar yüksekse eğri o kadar yukarıda.

Hoca grafiği şöyle okudu: başarısı %70 olan yaklaşık 4 öğreniciyi birleştirerek elde edilen sonuca, başarısı %60 olan öğrenicilerle ancak 14-16 tanesini birleştirerek ulaşılabiliyor. Dolayısıyla ensemble başarısındaki en önemli etkenlerden biri, içindeki tekil öğrenicilerin bireysel başarısıdır.

Grafiği üreten kod bir MATLAB dosyasıdır (`ens_acc.m`). Grafikteki kırıklıklar ve yer yer düşüşler deneyin ampirik olmasından kaynaklanıyor; yukarıdaki analitik formül kullanılarak çizilirse çok daha düzgün bir eğri elde edilir. <!-- BELİRSİZ: ens_acc.m kodu ve grafiğin sayısal değerleri karelerde okunur değil (slayt 13-14, yaklaşık 01:21-01:24 arası); kod bu yüzden nota alınmadı. -->

> **Ek bilgi (derste anlatılmadı):** Analitik formülle kabaca yapılan bir kontrol hocanın okumasıyla tutarlı görünüyor: bireysel başarı 0.70 iken 3 öğrenicinin oy çokluğu yaklaşık 0.78, bireysel başarı 0.60 iken 17 öğrenicinin oy çokluğu yaklaşık 0.80 başarı veriyor. Grafik ampirik olduğundan değerler bundan biraz farklı olabilir.

## 7. Dart Sorusu

Hoca bias-varyans konusuna geçmeden bir soru sordu (slayt: "DART", ekrandan, 01:25:00). Bu oyunda ortada bir hedef (gerçek değer, ground truth) var ve okun hedefe ne kadar yakın düştüğüne göre puan alınıyor. Soru şuydu: attığınız okların geldikleri yerleri değil de ortalamalarını kabul etseniz nasıl olur? Rakibiniz bunu kabul eder mi, bu akıllıca bir şey olur mu?

Öğrencilerden gelen cevaplar:

- Bir öğrenci, iki büyük hatanın birbirini dengeleyip başarı gibi görünebileceğini söyledi. Hoca bunu netleştirdi: bir ok sağ üst köşeye, diğeri sol alt köşeye giderse ortalama hedefe yaklaşır; ama ikisi de sağ üst köşeye giderse ortalama almanın bir faydası olmaz.
- Bir başka öğrenci atış sayısının önemli olduğunu, birden fazla atış yapıldığında ortalamayı kullanmanın daha mantıklı olabileceğini söyledi.

Hoca, tahminlerin kendileri yerine ortalamalarını kullanmanın dart oyunundaki bu fikre karşılık geldiğini söyledi ve konuya bias-varyans anlatıldıktan sonra döndü.

## 8. Bias ve Varyans

Slayttaki tanımlar (ekrandan, 01:30:00):

- **Bias (yanlılık):** Aynı dağılımdan gelen farklı eğitim kümeleri için üretilen modellerin kararlarının ortalamasının gerçeğe uzaklığı.
- **Varyans:** Aynı dağılımdan gelen farklı eğitim kümeleri için üretilen modellerin kararlarının kendi ortalamalarına uzaklığı.

"Aynı dağılımdan gelen farklı eğitim kümeleri" ifadesini hoca şöyle açıkladı: gerçek popülasyonun tamamına hiçbir zaman erişemeyiz, her zaman ondan örnekler alırız. Kedileri sınıflandırmak istiyorsak dünyadaki bütün kedilerin her açıdan fotoğrafını çekemeyiz; dünyanın çeşitli yerlerinden kedi resimleri toplarız. Bir kişi 100 kedi resmi çekerek bir veri kümesi, bir başkası 100 kedi resmi çekerek başka bir veri kümesi oluşturur. Bunlar aynı dağılımdan gelen farklı veri kümeleridir.

Tek bir test örneği üzerindeki kararları inceleyelim. Elimizde bir test örneği ve her biri farklı bir eğitim kümesiyle eğitilmiş çok sayıda model var; her model bu örnek için farklı bir tahmin üretiyor. Örneğin sayısal bir değer tahmin ettiğimiz bir regresyon problemi düşünelim:

- $Y$: gerçek değer.
- $y$: modellerin her birinin tahmini.

Slayttaki şekilde bir doğru üzerinde dizilmiş $y$'ler, onların ortalaması $E[y]$ ve gerçek değer $Y$ gösteriliyor. $E[y]$ ile $Y$ arasındaki uzaklık $\mathrm{Bias}(y)$, $y$'lerin yayılması $\mathrm{Var}(y)$ olarak işaretli.

Modellerden birinin tahminini rastgele seçersek yapacağımız hatanın karesinin beklenen değeri:

$$\mathrm{MSE}(y) = E[(Y-y)^2]$$

Fark karesi, artı ve eksi işaretlerle uğraşmamak için alınıyor. $E$ beklenen değer (expectation) demektir: herhangi bir $y$'yi seçtiğimizde ortalama olarak elde edeceğimiz değer.

## 9. Bias-Varyans Ayrıştırması ve Ortalamanın Üstünlüğü

### 9.1 Ayrıştırma

Slayttaki türetme (ekrandan, 01:35:00):

$$E[(Y-y)^2] = E[(Y-E[y]+E[y]-y)^2]$$

$$= E[(Y-E[y])^2] + E[(E[y]-y)^2] + 2E[(Y-E[y])(E[y]-y)]$$

$$= E[(E[y]-y)^2] + E[(Y-E[y])^2] \quad \text{(Neden?)}$$

$$= \mathrm{varyans}(y) + \mathrm{bias}^2(y)$$

Adımlar şöyle kuruldu:

- İlk satırda parantezin içine aynı terim ($E[y]$) bir artı bir eksi olarak eklendi; bunda bir sakınca yok.
- İkinci satırda $(a+b)^2 = a^2 + b^2 + 2ab$ açılımı kullanıldı. Beklenen değer toplamın üzerine dağılabildiği için her terim ayrı bir beklenen değer olarak yazıldı.
- Üçüncü satırda son terim kayboldu. Hoca bunun nedenini sordu.

**Soru:** Son terim neden sıfır oluyor? **Cevap:** Bir öğrenci, son çarpandaki terimin beklenen değerinin sıfır olduğunu söyledi; hoca da bir ifadenin beklenen değerinin beklenen değeri kendisine eşit olduğu için bu terimin sıfır olacağını, sıfırla çarpılan terimin de sıfırlanacağını belirtti (ara adım eklendi): $Y$ ve $E[y]$ sabittir, dolayısıyla $E[(Y-E[y])(E[y]-y)] = (Y-E[y])\,E[E[y]-y]$ ve $E[E[y]-y] = E[y]-E[y] = 0$ olur.

Kalan iki terim, bir önceki slayttaki tanımlarla eşleşir:

- $E[(Y-E[y])^2]$: ortalama tahmin ile gerçek arasındaki farkın karesi, yani bias'ın karesi.
- $E[(E[y]-y)^2]$: tahminlerin kendi ortalamalarından farklarının karelerinin ortalaması, yani $y$'nin varyansı.

Böylece rastgele seçilen bir modelin beklenen kare hatası varyans ile bias karesinin toplamıdır. İki terim de hatayla doğru orantılıdır:

- Tahminler çok uzaklara dağılmışsa (yüksek varyans), rastgele seçilen bir tahminin hatası büyük olur.
- Tahminlerin ortalaması gerçekten uzaksa (yüksek bias), yine herhangi bir tahminin hatası büyük olur.

### 9.2 Tahmin olarak ortalamayı kullanmak

Slaytın ikinci kısmı şunu iddia ediyor: tahmin olarak $y$ yerine $E[y]$ kullanırsak,

$$E[(Y-y)^2] \geq E[(Y-E[y])^2] \quad \text{(Neden? Yorumu?)}$$

Yani tek tek $y$'leri kullandığımızda elde edeceğimiz hatanın beklenen değeri, $y$'lerin ortalamasını kullandığımızda elde edeceğimiz hatadan büyüktür; dolayısıyla ortalamayı kullanmak daha iyidir.

**Soru:** Bu her bir $y$ için geçerli mi? **Cevap:** Hayır. Beklenen değer bütün $y$'ler üzerinden, rastgele seçilen herhangi bir $y$ için hesaplanıyor. Tek bir $y$, $y$'lerin ortalamasından gerçeğe daha yakın olabilir. Ama gerçeği bilmediğimiz için hangisinin o olduğunu bilemeyiz; $y$'lerden birini rastgele seçeriz ve bulmaya çalıştığımız şey bu rastgele seçimdeki beklenen hatadır.

Neden doğru olduğu yukarıdaki ayrıştırmadan okunur: sol taraf $\mathrm{varyans}(y) + \mathrm{bias}^2(y)$, sağ taraf ise yalnız $\mathrm{bias}^2(y)$'dir. Sol tarafın sağdan büyük ya da ona eşit olması için aradaki farkın, yani varyansın negatif olmaması yeterlidir. Varyans bir karenin beklenen değeri olduğu için negatif olamaz. Bu yüzden eşitsizlik her zaman doğrudur; eşitlik yalnız varyans sıfırken sağlanır. Yani tahmin olarak $E[y]$ kullanılırsa daha düşük bir beklenen hata elde edilir.

### 9.3 Yansız (unbiased) tahminler

Elimizde yansız tahminler varsa $\mathrm{bias}(y) = 0$, dolayısıyla $Y = E[y]$ olur. Bu durumda ayrıştırmadaki bias terimi kaybolur ve geriye yalnız varyans kalır:

$$E[(Y-y)^2] = E[(E[y]-y)^2] = \mathrm{varyans}(y)$$

Hoca, terimlere alışınca bu türetmelerde hileli bir şey olmadığını belirtti.

## 10. Dart Tahtasında Bias ve Varyans

Hoca dart örneğine dört hedefli bir şekille döndü (ekrandan, 01:45:00). Her hedefe altı ok atılmış:

| | Düşük bias | Yüksek bias |
|---|---|---|
| Düşük varyans | Oklar birbirine yakın ve hedefin çevresinde | Oklar birbirine yakın ama hedeften uzakta |
| Yüksek varyans | Oklar dağınık ama ortalamaları hedefe yakın | Oklar dağınık ve ortalamaları hedeften uzak |

Bias ortalamanın hedefe uzaklığı olduğu için sol sütundaki atışların ortalaması hedefe yakın, sağ sütundakilerinki uzaktır. Varyans tahminlerin kendi ortalamasına yakınlığı olduğu için üst satırdaki tahminler birbirine benzer, alt satırdakiler birbirinden uzaktır.

Şeklin altında iki soru yazılı: "Bias=0 ise tahminleri birleştirmek hatayı azaltır mı? Varyans=0 ise tahminleri birleştirmek hatayı azaltır mı?"

- Bias sıfır durumu bir önceki bölümde konuşuldu: ortalama gerçeğe eşit olur ve tahminleri birleştirmek iyi bir şeydir.
- Varyans sıfır demek, bütün okların aynı yere gitmesi demektir. Bu durumda tahminleri birleştirseniz de birleştirmeseniz de hiçbir şey değişmez.

Bu yüzden modellerin kararlarını birleştirmek istiyorsanız tahminlerin mutlaka birbirinden farklı olması gerekir. Hocanın benzetmesiyle: bir yönetim kurulunda herkes aynı şeyi söylüyorsa o kadar kişinin orada bulunmasının bir önemi yoktur; ancak birbirinden farklı şeyler söyleyenler varsa o kadar kişiyi bir araya toplamak anlamlı olur.

> **Hocanın vurgusu:** Farklılık, kararları iyileştirebilmenin tek yoludur.

Böylece kollektif öğrenmenin başarılı olması için gereken iki koşul ortaya çıkar. Birincisi, temel öğrenicilerin bireysel başarılarının yüksek olması; bu düşük bias'a karşılık gelir ve 6. bölümdeki ampirik grafikte de görülmüştü. İkincisi, kararların birbirinden farklı olması, yani varyansın sıfırdan büyük, hatta yüksek olması. Düşük bias tek başına yeterli değildir.

## 11. Ortalama Almak Karar Sınırını Nasıl Değiştirir?

Slayt: "Neden daha doğru sonuçlar? Maksimum margin'e sahip karar sınırları üretebilir (SVM gibi)" (ekrandan, 01:50:00).

### 11.1 Sınıflandırma: perceptronlar ve SVM

İki boyutlu, iki sınıflı bir veri düşünelim ve bu iki sınıfı ayıran iteratif bir model eğittiğimizi varsayalım. Böyle bir model örnekleri doğru ayırdığı anda eğitimi durdurur. Örneğin bir perceptron doğrusal bir modeldir, yani tek bir doğrusal karar sınırı çizebilir. Şekilde mor, yeşil ve siyah renkte birkaç olası sınır çizilmiş.

**Soru:** Bu veriye kaç tane böyle sınır çizilebilir ve bunların başarısı nedir? **Cevap:** Sonsuz sayıda sınır çizilebilir ve hepsinin eğitim başarısı aynıdır: %100. Hepsi eğitim kümesindeki bütün örnekleri doğru sınıflandırır, dolayısıyla modeliniz bunlardan herhangi biri olabilir.

Bunlardan herhangi birini seçmek yerine kararlarının birleştirilmesi kabaca maksimum marjine sahip bir karar sınırı üretir. Bütün olası çizgilerin ortalaması şekildeki siyah çizgi gibi bir şey olacaktır. Bu çizgiyi seçmek, örneğin örneklere çok yakından geçen mor çizgiyi seçmekten daha güvenlidir: mor çizginin hemen yanındaki örneklere benzeyen yeni bir örnek çizginin öteki tarafına düşerse yanlış sınıflandırılır. Bu yüzden örneklerden olabildiğince uzak, marjini yüksek sınırlar istenir; SVM'in temel mantığı budur. SVM eğitmek yerine çok sayıda perceptron eğitip kararlarının ortalamasını almak da benzer bir davranış sağlar.

### 11.2 Regresyon

Aynı fikir regresyonda da geçerlidir. Slayttaki ikinci şekilde (yatay eksende Ozone, dikey eksende Temperature) mavi noktalar eğitim kümesi, gri eğrilerin her biri bir model. Bu modellerden herhangi birini kullanmak yerine kırmızı eğriyle gösterilen ortalama modeli kullanmak daha makul bir sonuç verir.

Bunun ardından gelen ve aynı konuya başka bir örnek veren slaytı (slayt 20) hoca derste açıklamadı, öğrencilerin kendilerinin anlamasına bıraktı. <!-- BELİRSİZ: slayt 20'nin içeriği karelerde okunur değil. -->

## 12. Kollektif Öğrenmenin İki Bileşeni ve 2'li Optimizasyon

Slaytta kollektif öğrenmenin iki bileşeni şöyle özetleniyor:

- **Temel öğrenicilerin performansı:** ne kadar yüksek olursa o kadar iyi.
- **Temel öğrenicilerin kararlarının birbirinden bağımsızlığı, farklılığı, ayrıklığı (diversity):** temel öğrenicilerin hepsinin kararları aynıysa kararlarını birleştirmenin bir anlamı yoktur; bu da ne kadar yüksek olursa o kadar iyi.

Bir sonraki slayt "2'li optimizasyon" başlığını taşıyor (ekrandan, 01:55:00):

- Önerilen ensemble algoritmalarının tamamına yakını bu 2 bileşenle alakalı.
- Ancak, hem yüksek performanslı hem de birbirinden bağımsız kararları olan modeller üretmek çok kolay değil. Çünkü bu 2 bileşen birbiriyle ters orantılı.

Ensemble yöntemlerinin bir kısmı temel öğrenicilerin performansını artırmaya, bir kısmı kararlarını birbirinden olabildiğince farklı kılmaya yöneliktir; bunlar ilerleyen derslerde görülecek.

**Soru:** İki bileşen neden ters orantılı? **Cevap:** Bir öğrencinin ifadesiyle, doğru cevap tektir. Temel öğrenicilerin performansını %100'e çıkarırsanız hepsi aynı kararı verir ve varyans sıfır olur. Ne kadar başarılı modeller üretirseniz kararları birbirine o kadar benzemeye başlar. Dolayısıyla kollektif öğrenmede birbiriyle çelişen iki şey aynı anda optimize edilmeye çalışılır.

Dersin terimler slaytında şu karşılıklar verildi:

- Base learner: temel öğrenici.
- Ensemble: öğrenici topluluğu.
- Diversity: temel öğrenicilerin kararlarının birbirlerinden farklılığı, ayrıklığı.
- Base learner performance: temel öğrenici başarısı.

## 13. Dezavantajlar

Avantajlardan sonra hoca dezavantajları sıraladı:

- **Daha yavaş eğitim ve test:** Bir model yerine çok sayıda model eğitilir; test zamanında da tek modelden cevap almak yerine çok sayıda modelden cevap alınır. Bu daha yavaş bir süreç, daha fazla bellek ve daha fazla işlemci zamanı demektir.
- **Daha zor anlaşılan modeller:** Örneğin karar ağaçları oldukça kolay anlaşılır; uzman olmayan biri bile bir karar ağacına bakıp modelin ne yaptığını rahatça anlayabilir. Ama modele bir değil yüz ağaç katılırsa topluluğun yorumlanması çok zorlaşır. Hoca, günümüzde yorumlanabilirliğin önceliği daha düşük olduğu için bunun çok büyük bir handikap olmayabileceğini ekledi.
- **Teori eksikliği:** Ensemble başarısının diversity (kararların farklılığı) ve temel öğrenici başarısı cinsinden, veri kümesinden bağımsız bir açıklaması henüz bulunabilmiş değil. Bu iki büyüklük birbiriyle çeliştiği için nasıl birleştiklerinde daha başarılı bir topluluk ortaya çıkacağı teorik olarak tam açıklanamıyor.

## 14. Derin Öğrenmede Kollektif Öğrenme

Dersin son slaytı "Derin öğrenmede kolektif öğrenme" başlığını taşıyor (ekrandan, 02:00:00):

- Temel öğreniciler YSA (yüksek varyans).
- Veri artırımı.
- Karar birleştirme (birçok veri kümesindeki en başarılı sonuçlar ensemble içeriyor).
- Hata parametre uzayını incelemek, snapshot ensembles.
- Birbirinden öğrenme: model saflaştırma, distillation (öğretmen-öğrenci modelleri).
- Birbiriyle yarışan modeller.

### 14.1 YSA neden yüksek varyanslı bir temel öğrenicidir?

YSA'lar uzun zamandır ensemble'larda kullanılan temel öğrenicilerdir ve deterministik değildirler. Deterministik bir öğrenme algoritmasına aynı veri kümesini kaç kere verirseniz verin hep aynı modeli üretir; veri kümesini değiştirmeden farklı modeller elde edemezsiniz. Karar ağaçları böyledir, çünkü işin içinde şans yoktur.

YSA'lar ise stokastiktir, yani içlerinde bir rastgelelik bileşeni vardır. En basitinden başlangıç ağırlıkları (initial weights) değiştirildiğinde, aynı veriyle eğitilseler bile farklı modeller, farklı karar sınırları ve farklı kararlar elde edilir. Bu yüzden YSA'larla aynı veri kümesini kullanarak da kollektif öğrenme yapılabilir; illa farklı veri kümeleri oluşturmak gerekmez.

Yine de veri kümeleri birbirine ne kadar benzerse modellerin kararları da o kadar benzer olur. Farklı veri kümeleri kullanmak modellerin kararlarındaki farklılığı, yani diversity'yi artırır. Veri kümelerini çeşitlendirmek için çeşitli veri artırma yöntemleri görülecek.

### 14.2 Karar birleştirme ve ötesi

Hoca, derin öğrenmede bile yarışmaların liderlik tablolarına bakıldığında en başarılı sonuçların çoğunun derin modellerin ensemble'larından oluştuğunu söyledi. Bir YSA, bir karar ağacı ya da herhangi bir model, doğru tasarlanmış bir ensemble'ın içine konduğunda büyük olasılıkla tekil modelden daha başarılı bir sistem ortaya çıkar.

Ders kararları birleştirmenin ötesine de geçecek:

- Hata parametre uzayları incelenecek ve snapshot ensemble'lar görülecek.
- Birbirinden öğrenme başlığında distillation, yani öğretmen-öğrenci modelleri ve YSA'ların birbirine öğrettiği modeller ele alınacak. Distillation bugün büyük, önceden eğitilmiş modelleri çok daha küçük hacimlere sığdırmak, yani modelleri sıkıştırmak için kullanılıyor. Örneğin 1 milyon parametreli bir modelle benzer performansa sahip 10 bin parametreli bir model elde edilebilir; böylece büyük bir sunucuda çalışan bir sistem cep telefonunda çalışır hale getirilebilir.
- Birbiriyle yarışan modeller başlığında kısaca GAN benzeri yapılardan bahsedilecek.

Hoca, ders içeriğiyle ilgili yöntemlerin MATLAB kodlarını paylaşacağını, bunların Python karşılıklarının kolayca yazılabileceğini ya da bulunabileceğini söyledi. Ensemble kütüphaneleri oldukça gelişmiş durumdadır; R'de, scikit-learn'de ve MATLAB'de hazır olarak bulunurlar, sıfırdan yazmak gerekmez.

## 15. Bilimsel Okuma Üzerine Bir Tavsiye

Hoca dersi soru sorarak, etkileşimli biçimde işlemeye çalıştığını, slaytlara bilerek "Neden?" soruları koyduğunu ve bazılarının cevabını yazmadığını anlattı: hazır çözümler sunmak yerine öğrencileri bir şeyin neden öyle olduğunu sorgulamaya teşvik etmek istiyor. Lisansüstü öğrencilerin bilimsel çalışma yapacağını, bu bakış açısının onlara büyük katkı sağlayacağını söyledi.

> **Hocanın vurgusu:** Bir şeyi okurken ya da görürken her şeyi sorgulayın. Bir makaleyi okurken "neden" sorusunu kendiniz ekleyip cevabını bulmaya çalışırsanız okuma süreciniz sizin için en faydalı hale gelir. İyi makaleler genelde bu soruları kendisi sorar; yalnız "şunu denedim, şunu buldum" diyen bir makaleden pek bir şey öğrenilmez.

Ders sonundaki geri bildirimde bias-varyans türetmesinde $E$ ile gösterilen beklenen değerin, yani tahminlerin ortalamasının ne anlama geldiğinin önce açıklanmasının anlamayı kolaylaştıracağı konuşuldu. **Soru:** Beklenen değer yerine "ortalama" (mean) demek yanlış olur mu? **Cevap:** Olmaz; burada ortalama ile beklenen değer arasında bir fark yok, yalnız genelde $E$ ile gösteriliyor.

## Örnek Sorular

**Soru 1** (ekrandan, 01:20:00): Temel öğrenici sayısı $T = 25$, temel öğrenicilerin hata oranı $\varepsilon = 0.35$, kararlar birbirinden bağımsız ve ensemble kararı oy çokluğuyla veriliyor. Ensemble kararının hatası nedir?

> **Çözüm:** Ensemble'ın yanılması için 25 öğrenicinin en az 13'ünün yanılması gerekir. Yanılan öğrenici sayısı binom dağılır: $\sum_{i=13}^{25}\binom{25}{i}0.35^{i}\,0.65^{25-i} \approx 0.06$ (python ile: $0.0604$). Topluluk başarısı yaklaşık %94'tür.

**Soru 2** (derste sözlü, 02:10:46; slayt 12 "Genel formül ?"): Ensemble hatasının genel formülü nereden geliyor?

> **Çözüm (derste verilmedi):** $T$ tek sayı, öğreniciler bağımsız ve her birinin hata oranı $\varepsilon$ ise, oy çokluğunun yanılması için yanılan öğrenici sayısının $\lfloor T/2 \rfloor + 1$ ya da daha fazla olması gerekir. Tam $i$ öğrenicinin yanılma olasılığı $\binom{T}{i}\varepsilon^{i}(1-\varepsilon)^{T-i}$ olduğundan $\text{Hata}_{\text{ensemble}} = \sum_{i=\lfloor T/2 \rfloor + 1}^{T}\binom{T}{i}\varepsilon^{i}(1-\varepsilon)^{T-i}$ olur. $T = 25$ için alt sınır 13'tür ve Soru 1'deki ifade elde edilir. Slayttaki formülün tam yazımı karede okunamadı. <!-- BELİRSİZ: slayt 12'deki genel formülün alt sınır yazımı karede okunur değil. -->

**Soru 3** (ekrandan, 01:25:00): Dart oyununda attığınız okların geldikleri yerleri değil de ortalamalarını kabul etseniz nasıl olur?

> **Çözüm:** Derste konuşulduğu gibi, oklar hedefin farklı yönlerine dağılıyorsa ortalamaları hedefe yaklaşır ve büyük hatalar birbirini dengeler; hepsi aynı yöne sapıyorsa ortalama almanın faydası olmaz. Bu, tahminlerin ortalamasını almanın karşılığıdır ve 9.2'deki eşitsizlikle kesinleşir: ortalamanın beklenen hatası rastgele seçilen tek bir tahminin beklenen hatasından büyük olamaz.

**Soru 4** (ekrandan, 01:35:00): $E[(Y-y)^2]$ açılımında $2E[(Y-E[y])(E[y]-y)]$ terimi neden kaybolur?

> **Çözüm:** $Y$ ve $E[y]$ sabittir, bu yüzden terim $2(Y-E[y])\,E[E[y]-y]$ olarak yazılır ve $E[E[y]-y] = E[y]-E[y] = 0$ olduğundan sıfırdır.

**Soru 5** (ekrandan, 01:40:00): Tahmin olarak $y$ yerine $E[y]$ kullanılırsa neden $E[(Y-y)^2] \geq E[(Y-E[y])^2]$ olur? Yorumu nedir?

> **Çözüm:** Sol taraf $\mathrm{varyans}(y) + \mathrm{bias}^2(y)$, sağ taraf $\mathrm{bias}^2(y)$'dir. Aradaki fark varyanstır ve bir karenin beklenen değeri olduğu için negatif olamaz. Yorum: rastgele seçilen tek bir modelin tahmini yerine modellerin ortalama tahminini kullanmak beklenen hatayı hiçbir zaman artırmaz, varyans sıfırdan büyükse azaltır.

**Soru 6** (ekrandan, 01:45:00): Bias sıfırsa tahminleri birleştirmek hatayı azaltır mı? Varyans sıfırsa azaltır mı?

> **Çözüm:** Bias sıfırsa ortalama tahmin gerçeğe eşittir; tek bir modelin beklenen hatası varyansa eşitken ortalamanın hatası sıfırdır, yani birleştirmek hatayı azaltır. Varyans sıfırsa bütün tahminler aynıdır; birleştirmek hiçbir şeyi değiştirmez.

**Soru 7** (derste sözlü, 01:49:54): Doğrusal ayrılabilir iki sınıflı bir veriye kaç tane perceptron karar sınırı çizilebilir, bunların eğitim başarısı nedir ve bunların ortalamasını almak ne sağlar?

> **Çözüm:** Sonsuz sayıda sınır çizilebilir ve hepsinin eğitim başarısı %100'dür. Ortalamaları kabaca maksimum marjinli bir sınır (SVM benzeri) verir; bu sınır örneklerden uzak geçtiği için yeni örneklerde daha güvenlidir.

**Soru 8** (ekrandan, 01:55:00): Hem yüksek performanslı hem de birbirinden bağımsız kararları olan modeller üretmek neden kolay değildir?

> **Çözüm:** Çünkü iki bileşen ters orantılıdır. Temel öğrenicilerin başarısı arttıkça hepsi doğru cevaba, yani aynı cevaba yaklaşır; başarı %100 olduğunda kararlar tamamen aynı olur ve varyans sıfıra iner.

## Dersin Toparlaması

Bu derste kollektif öğrenmenin, tek bir model yerine birden fazla modelin tahmin sürecine katılması olduğu, bu katılımın kararları birleştirmekten modellerin birbirinden öğrenmesine kadar uzanabildiği görüldü. Kullanım gerekçeleri günlük hayattan örneklerle (danışma, konsültasyon, kurullar) ve makine öğrenmesi durumlarıyla (çok büyük, çok küçük, karmaşık ya da farklı türde veri) ortaya kondu. $T = 25$, $\varepsilon = 0.35$ örneğinde bağımsız öğrenicilerin oy çokluğunun hatayı 0.06'ya indirdiği gösterildi. Bias-varyans ayrıştırmasıyla da tahminlerin ortalamasını kullanmanın beklenen hatayı hiçbir zaman artırmadığı, kazancın varyansa eşit olduğu kanıtlandı.

Buradan kollektif öğrenmenin iki bileşeni çıktı: temel öğrenicilerin bireysel başarısı ve kararlarının farklılığı (diversity). İkisi birbiriyle ters orantılı olduğu için ensemble yöntemleri aslında iki çelişen hedefi birlikte optimize etmeye çalışır. Ders, YSA'ların stokastik yapısı sayesinde yüksek varyanslı temel öğreniciler olduğu ve derin öğrenmede ensemble'ların (veri artırımı, snapshot ensemble'lar, distillation, yarışan modeller) nasıl kullanıldığına dair bir çerçeveyle kapandı. İlerleyen derslerde önce optimizasyon, sonra karar ağaçları ve klasik ensemble yöntemleri işlenecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
