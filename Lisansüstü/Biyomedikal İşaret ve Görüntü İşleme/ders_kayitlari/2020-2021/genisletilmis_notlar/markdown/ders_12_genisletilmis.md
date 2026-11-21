# Ders 12 Genişletilmiş Notu: Proje İlerleme Sunumları: Transfer Öğrenme, Topluluk Modelleri ve Histopatolojik Veri Setleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yapısı
- 2. Kolon Kanseri Hücre Çekirdeği Sınıflandırma
- 3. Transfer Öğrenme ve Topluluk Modelleri
- 4. MATLAB'de Transfer Öğrenme Akışı
- 5. Kan Hücresi Sınıflandırma ve Hesaplama Kaynakları
- 6. CRC ve Extended-CRC ile k Katlı Çapraz Doğrulama
- 7. PanNuke Veri Seti ve Çekirdek Yaması Çıkarma
- 8. Beyin Tümöründe GAN ve Bellek Sorunu
- 9. Servikal Sitoloji: Koordinat Uyuşmazlığı ve U-Net
- 10. Makale Yazımına Hazırlık
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Yapısı

Bu ders, dönem projelerinin ilerleme sunumlarından oluştu. Her öğrenci ekranını paylaşarak bir hafta içinde ne yaptığını gösterdi, hoca da yöntem, veri hazırlama ve değerlendirme konusunda geri bildirim verdi. Projelerin çoğu histopatolojik ya da sitolojik görüntülerde hücre çekirdeği sınıflandırma ve bölütleme üzerinedir. Ortak araç önceden eğitilmiş derin ağlarla transfer öğrenmedir. Bu notta sunumlar, hocanın yorumlarıyla birlikte ders sırasıyla anlatılır. Sunum yapanlar "bir öğrenci" diye anılır.

## 2. Kolon Kanseri Hücre Çekirdeği Sınıflandırma

### 2.1 Veri ve yama çıkarma

İlk sunumdaki veri seti kolon kanseri histopatoloji görüntülerinden oluşur. Görevi hücre çekirdeklerini tespit edip sınıflandırmaktır. Öğrencinin anlattığına göre toplam dört çekirdek sınıfı vardır; altyazıda fibroblast ve epitel hücreleri adıyla geçer. Görüntüler 500×500 boyutludur. Her çekirdeğin konumu ayrı bir dosyada piksel koordinatı olarak verilmiştir.

<!-- BELİRSİZ: Dört sınıfın tam adları altyazıda bozuk ("fibroblast, endötenli diğer hücreler", "Hibitay hücreler"); büyük olasılıkla epitel, fibroblast, iltihabi ve diğer hücreler. Veri setinin adı da geçmiyor. -->

Öğrenci, verilen koordinatları merkez alarak her çekirdeğin etrafından 27×27 piksellik bir yama kırptı. Hoca önce şunu sordu: verilen noktalar gerçekten hücrelerin üstüne denk geliyor mu? Bunu görmek için noktaların görüntünün üzerine basılması gerekir. Öğrenci kırptığı bir fibroblast yamasında çekirdeğin ortalandığını gösterdi. Hoca bu yamaların sınıflarına göre ayrı klasörlerde toplanmasını istedi.

### 2.2 Yöntem: transfer öğrenme

Öğrenci sınıflandırma için transfer öğrenme kullanmayı planlıyor. MATLAB'in Deep Network Designer aracında SqueezeNet tabanlı bir ağ açtı. Ekranda ağın son katmanları görünüyor: `conv10` (convolution2dLayer), `relu_conv10` (reluLayer), `pool10` (globalAveragePooling) ve `prob` (softmax). Ağın özelliklerinde 68 katman, 75 bağlantı, girdi tipi görüntü ve çıktı tipi sınıflandırma yazıyor (ekrandan, 00:10:00).

Hoca hazır bir araç kullanılmasına karşı değil, ama tek bir ağla yetinilmemesini istedi:

- SqueezeNet dışında NASNet, Inception, ResNet, DenseNet gibi ağlar denenmeli. Olabildiğince yeni yöntemler de eklenmeli ki başarım karşılaştırılabilsin.
- Transfer öğrenmenin farklı biçimleri de denenmeli: yalnız sondaki katmanları eğitmek ya da ortadaki katmanları belli bir derinliğe kadar eğitmek.

## 3. Transfer Öğrenme ve Topluluk Modelleri

### 3.1 Kullanılan modeller

İkinci sunumun konusu bir histopatoloji görüntü setinde transfer öğrenme ve topluluk (ensemble) modelleri oluşturmaktır. Öğrenci bir önceki hafta Inception modelini eğitmişti. Bu hafta yedi modelle çalıştı. Slayttaki liste şöyledir (ekrandan, 00:15:00):

- Kullanılan modeller: InceptionV3, InceptionResNetV2, VGG16, VGG19, DenseNet201, DenseNet169, ResNet152V2. Hepsi ImageNet ağırlıklarına göre başlatıldı.
- Kullanılacaklar: EfficientNet (tek başına 0,89 doğruluk), TensorFlow 2.3.
- EfficientNet Python 3.8 ile, diğer modeller Python 3.6 ile eğitildiği için birlikte kullanılırken yapılandırma hatası veriyor. Diğer modeller Python 3.8 ile yeniden eğitilecek.
- Recall, precision, F1-skoru ve ROC eğrileri çizdirilecek.

<!-- BELİRSİZ: Veri setinin adı altyazıda "10.000 istikleri seti" diye bozuk geçiyor; 10.000 görüntülük bir histoloji seti olabilir. -->

Öğrenci her modelde son katmanı yeni sınıflara göre değiştirdi. Diğer katmanları dondurmadı, eğitilebilir bıraktı. Böylece bütün ağ, ImageNet ağırlıklarını başlangıç değeri kabul ederek yeniden eğitildi. Literatürde en iyi sonucu veren (state of the art) model olarak EfficientNet geçtiği için onu da eklemek istedi. EfficientNet'in 0,89 sonucu ise yalnız sistemin çalışıp çalışmadığını görmek için yapılmış, başlangıç değerleri ve veri seçimi ayarlanmamış bir denemedir.

### 3.2 Model ortalaması ve ağırlıklı ortalama

Öğrenci Machine Learning Mastery sitesindeki topluluk yöntemleri listesini temel aldı. Bu hafta iki yöntemi uyguladı:

- **Model ortalaması (model averaging ensemble):** Bütün modellerin çıktıları eşit ağırlıkla birleştirilir.
- **Ağırlıklı ortalama (weighted average ensemble):** Her modelin çıktısı bir ağırlıkla çarpılıp toplanır. Doğruluğu yüksek modele daha büyük ağırlık verilir.

Tek başına modellerin doğrulukları bir tabloda verildi. Örneğin InceptionV3 0,84, bir diğeri 0,82 civarındaydı. Bütün modeller eşit ağırlıkla birleştirildiğinde doğruluk 0,88'e çıktı. Öğrenci ağırlıkları şimdilik elle, doğruluk değerlerine göre verdi; bu durumda doğruluk 0,88'den 0,89'a yükseldi (derste sözlü, 00:16:32-00:17:06). Topluluk modeli, grafikteki bütün tekil modellerden daha iyi çıktı. Öğrenci ağırlıkları otomatik bulan bir yöntem kullanmayı planlıyor.

<!-- BELİRSİZ: Ağırlıkları otomatik bulan yöntem altyazıda "derivatif yöntem" diye geçiyor; 0,82 doğruluklu modelin adı da "3G" diye bozuk. -->

> **Ek bilgi (derste anlatılmadı):** Machine Learning Mastery'deki ağırlıklı topluluk örneklerinde ağırlıklar büyük olasılıkla diferansiyel evrim (differential evolution) gibi türev gerektirmeyen bir global optimizasyon yöntemiyle aranır. Amaç fonksiyonu, doğrulama verisinde topluluk doğruluğudur; ağırlıklar toplamı 1 olacak biçimde normalize edilir. Ağırlıkları test verisine göre seçmek başarımı iyimser gösterir, bu yüzden ayrı bir doğrulama kümesi kullanılır.

### 3.3 Hocanın değerlendirme isteği

Hoca sonuçlarda önce genel doğruluğa (overall accuracy) bakılmasını istedi: kaç sınıf varsa, doğruya doğru, yanlışa yanlış ne kadar denmiş. Ardından F-ölçütü değerlerine bakılmalı. Öğrenci recall, precision, F-ölçütü ve ROC değerlerini zaten hesapladığını, genel doğruluğu da bir karışıklık matrisi üzerinden çıkaracağını söyledi. Hoca bu ölçütlerin bütün modeller için bir tabloda karşılaştırmalı sunulmasını, ağırlıklandırmayla ilgili yeni yöntemlerin de araştırılmasını istedi.

## 4. MATLAB'de Transfer Öğrenme Akışı

Hoca, ilk sunumu yapan öğrenci için MathWorks'ün "Get Started with Transfer Learning" sayfasını açtı. Sayfadaki "Reuse Pretrained Network" şeması beş adımdan oluşur (ekrandan, 00:20:00):

```text
1. Önceden eğitilmiş ağı yükle
   (ilk katmanlar düşük seviyeli öznitelikleri öğrenmiştir: kenar, leke, renk;
    son katmanlar göreve özgü öznitelikleri öğrenmiştir;
    eğitim: 1 milyon görüntü, binlerce sınıf)
2. Son katmanları değiştir
   (yeni katmanlar kendi veri setine özgü öznitelikleri öğrenir;
    daha az sınıf, daha hızlı öğrenme)
3. Ağı eğit (yüzlerce görüntü, onlarca sınıf; eğitim seçenekleri)
4. Tahmin et ve ağın doğruluğunu ölç (test görüntüleri)
5. Sonuçları kullan (deploy)
   -> gerekirse ağı iyileştir ve başa dön
```

Sayfaya göre transfer öğrenmeyle ince ayar, rastgele ağırlıklarla sıfırdan eğitmekten genellikle çok daha hızlı ve kolaydır, ve öğrenilmiş öznitelikler daha az eğitim görüntüsüyle yeni bir göreve aktarılabilir. Hoca aynı dokümantasyondaki önceden eğitilmiş ağ listesine dikkat çekti: SqueezeNet'in yanında NASNet, ShuffleNet ve DarkNet-53 gibi daha yeni yapılar da var. Öğrenciden hepsini karşılaştırmalı denemesini istedi.

## 5. Kan Hücresi Sınıflandırma ve Hesaplama Kaynakları

### 5.1 Yeni veri seti

Üçüncü öğrenci akyuvar (white blood cell) sınıflandırması üzerinde çalışıyor. Önceki veri setinde kendi bölütleme yöntemiyle hücreleri çıkarmıştı. Bu hafta daha net ve temiz bir veri seti buldu. Sınıflar aynıdır: eozinofil, lenfosit, monosit ve nötrofil. Öğrencinin bölge tabanlı bölütleme yöntemi bu veri setinde yaklaşık %95-98 doğrulukla çalıştı. Eski veri setinin kalitesi düşük olduğu için yöntem orada iyi çalışmamıştı. Öğrenci ayrıca semantik bölütleme ağını hocanın önerdiği gibi farklı bir yöntemle eğitti.

<!-- BELİRSİZ: Yeni veri setinin adı altyazıda "S1-UFIL" diye bozuk geçiyor. -->

Hoca iki veri setinin karşılaştırmalı kullanılmasını istedi: aynı yöntemlerin yeni ve eski veri setindeki sonuçları birlikte verilmeli.

### 5.2 CPU ile eğitim süresi

Öğrencinin MATLAB eğitim ekranı CPU ile eğitimin ne kadar uzun sürdüğünü gösteriyor (ekrandan, 00:25:00):

| Bilgi | Değer |
|---|---|
| Donanım | Multiple CPUs |
| Epoch | 50 / 300 |
| İterasyon | 736 / 4500 |
| Epoch başına iterasyon | 15 |
| Öğrenme oranı | 0,001 (sabit) |
| Geçen süre | 219 dk 48 sn |
| Eğitim | elle durduruldu |

Komut penceresindeki tabloda ilk iterasyonda mini-batch doğruluğu %35,74 ve kayıp 1,1963, 50. epoch'ta (736. iterasyon) doğruluk %55,64 ve kayıp 0,5544'tür (ekrandan, 00:25:00). Maksimum iterasyon sayısı $300 \times 15 = 4500$ ile tutarlıdır. 50 epoch $50 \times 15 = 750$ iterasyon eder; eğitim 50. epoch'un içinde, 736. iterasyonda durdurulmuştur (ara adım eklendi).

Öğrencinin bilgisayarında GPU var, ama MATLAB GPU'yu tanımıyor. Hata mesajı sürücü sürümünün eski olduğunu söylüyor; öğrenci sürümün 10.1'in üstünde olması gerektiğini okudu. Bu yüzden eğitim paralel CPU ile çalışıyor ve çok yavaş.

<!-- BELİRSİZ: Hata mesajındaki sürüm numaraları (9 ve 10.1) ekranda görünmüyor, altyazıdan alındı. -->

### 5.3 Hocanın önerileri

Hoca derin öğrenmede eğitim süresinin gerçekten bir sorun olduğunu söyledi ve şu seçenekleri sıraladı:

- **Google Colab ve Kaggle:** Ücretsiz GPU hizmeti verir, ama MATLAB çalıştırmaz.
- **MATLAB'in bulut sürümü:** Amazon Web Services üzerinde çalışabilen bir MATLAB sürümü var.
- **MathWorks Cloud Center:** Hoca öğrenciden sayfayı açmasını istedi. Sayfaya göre Cloud Center, Amazon bulutunda paralel hesaplama kümeleri kurmaya ve bunlara MATLAB oturumundan erişmeye yarar. Kümelere MATLAB'den Parallel Computing Toolbox ile iş gönderilir; dosya ve veri kümeye taşınabilir. Şemada istemci bilgisayar, bulutta küme, GPU ve çok çekirdekli CPU görünüyor (ekrandan, 00:30:00).
- **Üniversite lisansı:** Okulun MathWorks lisansı olduğu için öğrenci e-postasıyla açılan hesapla bu hizmetler denenebilir.

Hoca kodlar bulutta koşturulursa hem işin hızlanacağını hem de kişisel bilgisayarın rahatlayacağını söyledi.

## 6. CRC ve Extended-CRC ile k Katlı Çapraz Doğrulama

### 6.1 Birleşik veri seti

Dördüncü sunum İngilizce yapıldı. Hoca bir önceki hafta iki kolorektal kanser veri setinin, CRC ve Extended-CRC'nin birleştirilmesini önermişti. Slayttaki tablo şöyledir (ekrandan, 00:35:00):

| | Grade-1 (normal) | Grade-2 (düşük derece) | Grade-3 (yüksek derece) | Toplam |
|---|---|---|---|---|
| CRC | 71 | 33 | 35 | 139 |
| Extended-CRC | 106 | 88 | 53 | 247 |
| Toplam | 177 | 121 | 88 | 386 |

Satır ve sütun toplamları tutarlıdır: $71+33+35=139$, $106+88+53=247$, $139+247=386$.

### 6.2 Modeller ve sonuçlar

Öğrenci ResNet50 ve DenseNet201 gibi önceden eğitilmiş modellerle çalıştı. Veriyi bir kez eğitim ve test diye bölmek yerine k katlı çapraz doğrulama kullandı. MATLAB kodunda kat sayısı `num_folds=3` olarak ayarlanmış ve her kat için bir döngü kurulmuştur (ekrandan, 00:40:00):

```matlab
%%K-fold Validation
% Number of folds
num_folds=3;

% Loop for each fold
for fold_idx=1:num_folds
    fprintf('Processing %d among %d folds \n',fold_idx,num_folds);
```

Öğrenci üç katın sonuçlarını tek tek göstermeye başlayınca hoca araya girdi.

> **Hocanın vurgusu:** k katlı çapraz doğrulamayla 3 sonuç elde edildiyse sonucu sunarken bunların ortalaması alınır. Bütün katların sonuçlarını ayrı ayrı göstermek gerekmez; ortalama sonuç gösterilir.

Ortalama doğruluk ResNet50 ile %92, DenseNet201 ile %93 çıktı (derste sözlü, 00:39:05-00:39:37). Hoca sonucu makul buldu. Öğrenciye de MATLAB'in transfer öğrenme sayfasını gösterdi ve SqueezeNet, ResNet, DarkNet, ShuffleNet, NASNet gibi diğer ağları da denemesini önerdi.

## 7. PanNuke Veri Seti ve Çekirdek Yaması Çıkarma

### 7.1 Veri setinin yapısı

Beşinci öğrenci PanNuke veri setiyle çalışıyor. Hoca bu veri setinin hem sınıflandırma hem bölütleme için kullanılabildiğini, ek veri arayanların ona da bakabileceğini söyledi. Veri üç parça (fold) halinde paylaşılır. Görüntüler 256×256×3'tür; bir parçada yaklaşık 2500-2700 görüntü vardır ve parçalar arasında yüz civarı sayı farkı bulunur.

Her görüntünün maskesi 6 katmanlıdır. Öğrencinin gösterdiği makale ekine göre PanNuke'daki kategoriler neoplastik, neoplastik olmayan epitel, bağ dokusu (connective), iltihabi (inflammatory) ve ölü hücrelerdir (dead). Neoplastik ve neoplastik olmayan alt tipler makalenin Tablo A1'inde şöyle verilir (ekrandan, 00:45:00):

| Plastisite | Alt tipler |
|---|---|
| Neoplastik | Malign tümörler, benign tümörler |
| Neoplastik olmayan | Normal, hiperplastik, hipertrofik, metaplastik, iltihabi, dejeneratif, atipi/displazi |

Aynı sayfada, displazinin henüz iyi ya da kötü huylu tümöre dönüşmemiş, neoplazi öncesi bir evre olduğu ve bu yüzden displastik kolon hücrelerinin neoplastik olmayan epitel olarak etiketlendiği yazar. PanNuke'daki neoplastik etiketi iyi ve kötü huylu tümör hücrelerine karşılık gelir (ekrandan, 00:45:00). Makale ekinde doku tiplerine göre çekirdek boyut dağılımları da verilir; öğrencinin yorumuna göre neoplastik çekirdekler çoğunlukla en büyük olanlardır.

Öğrenci katmanları makaleye göre altı sınıfa eşledi; son katman (indis 5) çekirdek olmayan bölgeyi, yani arka planı gösterir. Bu katmanda çekirdekler 0, geri kalan bölge 1 değeri alır. Diğer katmanlarda ise arka planın tamamı 0'dır.

<!-- BELİRSİZ: Öğrencinin okuduğu katman sırası altyazıda "neoplastik, non-neoplastik, inflamasyon, connective, dead, non-nükleer" diye bozuk geçiyor; katman-sınıf eşlemesi derste kesinleşmedi. -->

Ayrıca her görüntünün hangi dokudan alındığını veren bir tip dosyası vardır. Öğrencinin bir parça için saydığı dağılım 19 doku tipini gösterir (ekrandan, 00:55:00):

| Doku | Sayı | Doku | Sayı |
|---|---|---|---|
| Adrenal_gland | 134 | Lung | 80 |
| Bile-duct | 159 | Ovarian | 54 |
| Bladder | 21 | Pancreatic | 78 |
| Breast | 827 | Prostate | 77 |
| Cervix | 155 | Skin | 59 |
| Colon | 478 | Stomach | 50 |
| Esophagus | 155 | Testis | 60 |
| HeadNeck | 70 | Thyroid | 80 |
| Kidney | 37 | Uterus | 17 |
| Liver | 65 | | |

Bu sayıların toplamı 2656'dır; öğrencinin bir parça için verdiği 2500-2700 aralığıyla tutarlıdır (ara adım eklendi).

### 7.2 Maske değerleri ne anlama geliyor?

Öğrenciyi en çok zorlayan, maske katmanlarındaki sayısal değerlerdir. Bir maske katmanında `numpy.unique(mask2, return_counts=True)` ile değerler sayıldığında şu sonuç çıktı (ekrandan, 00:50:00):

```text
{0.0: 60518, 49.0: 315, 54.0: 1358, 62.0: 473,
 63.0: 1337, 80.0: 559, 83.0: 976}
```

Sayıların toplamı $65536 = 256 \times 256$'dır, yani katmanın bütün pikselleri sayılmıştır (ara adım eklendi). 0 arka plandır. Öğrenci 49, 54, 62, 63 gibi değerlerin neye karşılık geldiğini makalede ve atıf yapılan çalışmalarda bulamadığını söyledi. Ekranda maskeler mavi, yeşil ve sarı tonlarında görünüyordu. Hoca renklerin bir anlamı olmadığını, renklendirmeyi Python'un kendisinin yaptığını, aslında yalnızca matris değerleri bulunduğunu söyledi. Bir katmanda sıfırdan farklı değer alan bütün pikseller o katmanın çekirdek tipine aittir.

> **Ek bilgi (derste anlatılmadı):** PanNuke maskelerinde bir katmandaki sıfırdan farklı değerler büyük olasılıkla örnek (instance) kimlikleridir: her çekirdek ayrı bir tam sayıyla etiketlenir. Bu durumda yukarıdaki katmanda 6 ayrı çekirdek vardır ve her değerin sayısı o çekirdeğin piksel alanıdır. Bu yapı, aynı tipteki komşu çekirdekleri birbirinden ayırmayı ve her çekirdeğin çerçevesini ayrı ayrı bulmayı kolaylaştırır.

### 7.3 Soru-cevap: bir görüntü tek sınıfa mı ait?

**Soru (hoca):** 256×256'lık bir görüntü yalnız bir sınıfa mı aittir?

**Cevap (öğrenci):** Öğrenci bunu böyle yorumladığını söyledi, ama görüntülerde birden fazla çekirdek olabildiğini de gösterdi.

Hoca bu yorumu düzeltti: bir görüntünün içinde farklı tipte birçok çekirdek olabilir; hepsinin neoplastik olması gerekmez. Bu yüzden önce problemin ne olduğu netleştirilmelidir: çekirdek tipi mi, yamanın (patch) tipi mi, yoksa dokunun tipi mi sınıflandırılacak? Öğrenci çekirdek kategorilerini sınıflandıracağını söyledi.

### 7.4 Hocanın önerdiği yöntem

Çekirdek tipi sınıflandırılacaksa görüntünün tamamı ağa verilemez. Hoca şu adımları önerdi:

1. Bir katmanı seç (örneğin neoplastik olmayan çekirdeklerin katmanı).
2. Bu katmandaki her çekirdeğin etrafına onu kapsayan en küçük çerçeveyi al. Bunun için hazır minimum çerçeve komutları vardır.
3. Bütün veri setindeki çekirdekleri sığdıracak ortak bir çerçeve boyutu belirle (bazısı 32×32'ye, bazısı 50×50'ye sığar). Ağa verilecek girdilerin aynı boyutta olması gerekir.
4. Kesilen yamaları sınıf numarasına göre ayrı klasörlere kaydet: 1 numaralı sınıftakileri bir yere, 2 numaralı sınıftakileri başka bir yere.
5. Elde edilen sınıfları farklı ağlarla ve k katlı çapraz doğrulamayla eğit; sınıflar birbirinden ayrışabiliyor mu diye bak.
6. Arka plan katmanındaki hücresiz bölgelerden de yama çıkar. Böylece model hücre olmayan yapıları da öğrenir; bu sınıf arka plan ile hücreyi ayırmak için kullanılır.

**Soru:** Yamaları boyuta göre mi yoksa renk tonlarına göre mi ayırmak daha isabetli olur?

**Cevap:** Bir katmanda farklı renkte görünen hücrelerin hepsi aynı tiptedir, renk fark etmez. Görüntüden hücreler, maskedeki çerçevelere göre kesilip çıkarılır.

### 7.5 Alternatif problem: doku tipi sınıflandırma

Tip dosyası, görüntülerin 19 farklı dokudan (karaciğer, tiroid, kolon vb.) alındığını gösteriyor. Hoca bunun ayrı bir problem olarak da çalışılabileceğini söyledi: görüntünün tamamına bakarak hangi dokudan alındığını bulmak, yani çok sınıflı doku tipi sınıflandırması. Örneğin tiroid ile kolondan alınan görüntüler birbirinden ayrışıyor mu? Hoca öğrenciden literatürde 19 sınıflı mı yoksa daha çok 6 sınıflı (çekirdek tipi) çalışmaların mı yapıldığını, ve çekirdek tabanlı yama çıkarma yapan çalışma olup olmadığını araştırmasını istedi. Öğrencinin gözlemine göre literatürde çekirdek bölütleme ve sınıflandırma çalışmaları daha fazladır. Böyle bir çalışma bulunamazsa hocanın önerdiği yama çıkarma yoluyla veri seti oluşturulacak ve her sınıftan kaç yama çıktığına bakılacak.

## 8. Beyin Tümöründe GAN ve Bellek Sorunu

### 8.1 Çalışma

Altıncı öğrenci beyin tümörü görüntülerinde GAN (çekişmeli üretici ağ) uygulamalarına bakıyor. Hoca bir önceki hafta Papers with Code sitesini önermişti. Öğrenci bu sitede iki GAN uygulaması buldu ve birini hatalarını düzelterek çalıştırmayı başardı. Ekrandaki kod Spyder'da açık bir vox2vox projesidir. Kodda BraTS2020 verisinin eğitim ve doğrulama klasörlerinden her hasta için T1, T1ce, T2, FLAIR ve bölütleme (seg) dosyaları sıralı listeler halinde okunuyor; sınıf sayısı `Nclasses = 4` (ekrandan, 01:05:00). Kodun bir yerinde `train_test_split(idx, test_size=0.25)` satırı yorum içine alınmış; öğrenci veri setini önceden böldüğü için eğitim ve doğrulama listelerini ayrı ayrı tanımladığını söyledi.

### 8.2 Bellek yetersizliği

Kod çalıştı, ama "out of memory" hatası verdi. Öğrenci TensorFlow'u kurup GPU ile denediğinde de aynı hata çıktı. Hoca iki öneride bulundu:

- Programlama yaparken her şeyi değişkenlerde tutmamak; işlenen değişkeni işi bitince silmek.
- Kaggle ya da Google Colab'in hizmetlerini kullanmak; bunlar genellikle bellek hatası vermez.

Öğrenci Kaggle'da GPU hizmeti bulamadığını söyleyince hoca birlikte baktı: Kaggle'da yeni bir not defteri oluşturulduğunda sağdaki ayarlarda bir hızlandırıcı (Accelerator) seçeneği vardır. Buradan GPU, hatta TPU seçilebilir. Hocanın hatırladığına göre kullanım belli bir saatle sınırlıdır (39-40 saat civarı), ama kesin süre araştırılmalıdır.

### 8.3 k-fold için hazır fonksiyon

Öğrencinin veriyi elle böldüğünü görünce hoca sordu: k-fold için otomatik bir seçenek yok mu? Öğrenci bunun vox2vox koduna özgü olduğunu düşündü. Hoca açıkladı: k-fold, uygulanacak modelden bağımsızdır. KFold fonksiyonu veri setini kendisi bölümlere ayırır ve her kat için hangi örneklerin kullanılacağını indis numaralarıyla verir. Elle bölmeye gerek yoktur.

> **Ek bilgi (derste anlatılmadı):** Python'da bu iş için büyük olasılıkla scikit-learn'ün `sklearn.model_selection.KFold` sınıfı kastediliyor. `KFold(n_splits=k, shuffle=True).split(X)` her kat için eğitim ve test indislerini üretir. Sınıf oranlarını katlarda korumak gerekiyorsa `StratifiedKFold` kullanılır.

### 8.4 Verinin boyutu

**Soru:** Bellek kullanımını azaltmak için optimizasyon ya da veri boyutunu düşürme yöntemi var mı?

**Cevap:** Hoca önce verinin yapısını sordu. Öğrenci verinin şeklini 2, 64, 64, 64, 128 diye okudu; tek bir örnek işlenirken bellekte 200-300 MB yer tuttuğunu düşünüyor. Hoca bunun 64×64'lük bir görüntünün 128 katmanı mı olduğunu sordu, öğrenci emin olamadı. Hoca verinin yapısı tam açıklanmadan cevap veremeyeceğini, veri anlaşıldıktan sonra konuşulmasını istedi. Öğrenci önce çevrim içi ortamda eğitmeyi, olmazsa kod optimizasyonunu deneyecek.

<!-- BELİRSİZ: Veri şekli (2, 64, 64, 64, 128) derste açıklanmadı; ekranda da görünmüyor. -->

## 9. Servikal Sitoloji: Koordinat Uyuşmazlığı ve U-Net

### 9.1 Cervix93 verisinde koordinatlar

Yedinci öğrenci servikal sitoloji verileriyle çalışıyor. Cervix93 veri setinde çekirdeklerin koordinatları ayrı bir dosyada verilmiş. Öğrenci bu koordinatları Colab'de görüntünün üzerine mavi noktalar olarak bastı. Ekranda noktalar görüntünün üst ve sağ kısmında, hücrelerin seyrek olduğu açık bölgede toplanıyor; koyu çekirdekler ise sol ve alt bölgede yoğun (ekrandan, 01:10:00). Makaleye göre bir çekirdeğin yarısı çerçevenin içindeyse ya da sınıra 10 piksel uzaklıktaysa işaretlenmiştir. Ama noktaların bir kısmı hiç hücre olmayan yerlere düşüyor.

<!-- BELİRSİZ: Veri setinin adı altyazıda "Servix 93" diye geçiyor; büyük olasılıkla Cervix93 sitoloji veri seti. -->

Hoca koordinatlarda bir hata olduğunu söyledi: hücrelerin yoğun olduğu yer aşağısı, noktaların yoğun olduğu yer yukarısı. Noktaların köşegene göre simetrisinin, yani tam köşegenin altına denk gelecek biçimde basılmasının gerektiğini düşünüyor. Önerisi:

- Koordinatların transpozunu alıp (satır ile sütunu değiştirip) yeniden basmak.
- Görüntüyü döndürüp noktaları yeniden basmak.
- Başka görüntülerde de denemek, koordinatları farklı biçimlerde çakıştırmaya çalışmak.

> **Hocanın vurgusu:** Noktaları hücrelere denk getirmeye çalışmak hata ayıklamaktır ve veriyi tanımanın parçasıdır. Bir deneme olmadı diye bir sonraki derse kadar beklenmez; araştırmaya devam edilir. Bu veri setini başkaları kullanmıştır, demek ki doğru kullanmanın bir yolu vardır.

Hoca ekranında görüntüyü çevirerek noktaların nasıl denk gelmesi gerektiğini de gösterdi. Öğrenci görüntüyü çevirmenin de işe yarayabileceğini söyledi; hoca denemenin ona ait olduğunu belirtti.

> **Ek bilgi (derste anlatılmadı):** Bu tür uyuşmazlıkların yaygın nedeni koordinat düzenidir. Görüntü dizilerinde ilk indis satırı (y), ikinci indis sütunu (x) gösterir; çizim fonksiyonları ise noktaları (x, y) sırasıyla bekler. Ayrıca görüntü ekseninde y aşağı doğru artar. Koordinatların sırası karışırsa noktalar köşegene göre yansımış görünür; transpoz bu yüzden ilk denenecek düzeltmedir.

### 9.2 Herlev verisinde U-Net

Aynı öğrenci Herlev veri setinde bölütleme için U-Net modelini kurdu: görüntüleri ve maskeleri okudu, veriyi böldü ve eğitime başladı. Bölütlemeden sonra sınıflandırma yapacak. Ancak eğitim başarısı iyi çıkmadı.

Hoca önceden eğitilmiş ağların kullanılmasını önerdi. Öğrenci de veri sayısının az olduğunu, sıfırdan eğitilen ağın bu yüzden öğrenemediğini kabul etti. Daha önce Inception kullanmıştı ve iyi sonuç vermişti. Hoca Inception'ın yanında birkaç ResNet modelinin de denenmesini ve sonuçların karşılaştırmalı sunulmasını istedi, çünkü makalede karşılaştırma gerekir.

## 10. Makale Yazımına Hazırlık

Hoca dersin ortasında ve sonunda bütün öğrencilere aynı uyarıyı yaptı: projelerin sonunda bir bildiri ya da makale yazılacak, bu yüzden hazırlık şimdiden başlamalı.

- **Kaynaklar:** Her yayında en az 20 civarı kaynak olur. Okunan çalışmalar kaydedilmeli. Kaynaklar web sayfalarından çok bilimsel makaleler olmalı. Towards Data Science ve Machine Learning Mastery gibi sitelerde bulunanların altında kullanılan kaynaklar da not edilmeli.
- **Giriş (introduction):** En az 1-1,5 sayfalık bir giriş gerekir. Okurken girişte kullanılabilecek güzel cümleler, daha sonra uyarlanmak üzere ayrı bir yere kaydedilmeli.
- **Örnek makaleleri incelemek:** Aynı veri setini kullanan makalelerin veri setini nasıl tanıttığına, tablolara nasıl döktüğüne, farklı sınıflardan örnek görüntü verip vermediğine, nasıl bir akış şeması (flowchart) çizdiğine bakılmalı.
- **Başarımın ifadesi:** O alandaki çalışmaların başarımı nasıl verdiği not edilmeli: F-ölçütü, genel doğruluk, kesinlik, duyarlılık, ROC eğrisi altındaki alan. Çalışılan alandaki genel yaklaşımın ne olduğu öğrenilmeli.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:38:21): k katlı çapraz doğrulama ile 3 katın her birinden ayrı bir doğruluk elde edildi. Sonuç nasıl raporlanmalıdır?

> **Cevap (derste verildi):** Katların sonuçlarının ortalaması alınır ve ortalama sonuç raporlanır; her katın sonucu ayrı ayrı gösterilmez.

**Soru 2** (derste sözlü, 00:47:33 ve 00:53:31): PanNuke'daki 256×256'lık bir görüntü tek bir sınıfa mı aittir? Çekirdek tipi sınıflandırılacaksa görüntü ağa doğrudan verilebilir mi?

> **Cevap (derste verildi):** Hayır. Bir görüntüde farklı tipte birçok çekirdek olabilir. Önce çekirdek tipi mi, yama mı, doku tipi mi sınıflandırılacağı netleştirilir. Çekirdek tipi için her çekirdeğin etrafından ortak boyutlu bir yama kesilip sınıf klasörlerine kaydedilir, ağlar bu yamalarla eğitilir.

**Soru 3** (derste sözlü, 00:48:22): Maskede arka plan hangi değeri alır?

> **Cevap (derste verildi):** Çekirdek katmanlarında arka planın tamamı 0'dır. Arka plan (çekirdek olmayan) katmanında ise tersine çekirdekler 0, arka plan 1'dir.

**Soru 4** (derste sözlü, 01:04:59): k-fold için veriyi elle mi bölmek gerekir?

> **Cevap (derste verildi):** Hayır. k-fold, uygulanacak modelden bağımsızdır; KFold fonksiyonu her kat için kullanılacak örneklerin indislerini verir.

**Soru 5** (derste sözlü, 01:09:28): Verilen çekirdek koordinatları görüntüye basıldığında noktalar hücrelerin olmadığı bölgeye düşüyor. Ne yapılmalıdır?

> **Cevap (derste verildi):** Koordinat düzeninde bir hata olduğu düşünülür. Koordinatların transpozu alınıp yeniden basılır, görüntü döndürülerek denenir, başka görüntülerde de kontrol edilir. Bu, veriyi tanımanın ve hata ayıklamanın parçasıdır.

**Soru 6** (derste sözlü, 01:15:39): Az veriyle sıfırdan eğitilen U-Net iyi öğrenemiyorsa ne yapılabilir?

> **Cevap (derste verildi):** Önceden eğitilmiş ağlarla transfer öğrenme kullanılır (örneğin Inception, ResNet) ve sonuçlar karşılaştırmalı sunulur.

## Dersin Toparlaması

Bu derste dönem projelerinin ilerlemesi üzerinden derin öğrenmeyle biyomedikal görüntü analizinin pratik adımları ele alındı. Transfer öğrenmede ImageNet ağırlıklarıyla başlatılan bir ağın son katmanları yeni sınıflara göre değiştirilir; yalnız son katmanları ya da belli bir derinliğe kadar katmanları eğitmek gibi seçenekler denenmelidir. Birden fazla modelin çıktıları eşit ya da doğruluğa göre ağırlıklandırılarak birleştirildiğinde (topluluk modeli) tekil modellerden daha iyi sonuç alınabilir. Değerlendirmede genel doğruluk, F-ölçütü, kesinlik, duyarlılık ve ROC tablo halinde verilmeli; k katlı çapraz doğrulamada katların ortalaması raporlanmalıdır.

Veri tarafında, PanNuke gibi çok katmanlı maskeli veri setlerinde önce problemin (çekirdek, yama ya da doku sınıflandırması) netleştirilmesi, çekirdek sınıflandırması için çekirdek çevresinden ortak boyutlu yamalar çıkarılması gerektiği görüldü. Koordinat ve görüntü uyuşmazlıkları gibi sorunların transpoz ve döndürme denemeleriyle çözülmesi veriyi tanımanın bir parçasıdır. Uzun eğitim süreleri ve bellek hataları için Colab, Kaggle ve MATLAB bulut hizmetleri önerildi. Hoca son olarak, projelerin sonunda yazılacak makale için kaynak, giriş cümleleri, veri seti tanıtımı ve başarım tablosu örneklerinin şimdiden toplanmasını istedi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
