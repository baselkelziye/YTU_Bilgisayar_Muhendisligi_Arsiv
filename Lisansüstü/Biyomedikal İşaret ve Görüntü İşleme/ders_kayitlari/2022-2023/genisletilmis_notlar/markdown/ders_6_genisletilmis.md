# Ders 6 Genişletilmiş Notu: Proje İlerleme Görüşmeleri: TransUNet Son İşleme ve Histopatoloji Görüntülerinde Yama Tabanlı Sınıflandırma

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin biçimi
- 2. TransUNet bölütmesine Markov rastgele alanlarıyla son işleme
- 3. BreakHis veri setinde iyi huylu / kötü huylu sınıflandırma
- 4. Karşılaştırılacak modeller ve başarım ölçütleri
- 5. BACH veri seti ve hücre yoğunluğuna göre yama çıkarma
- 6. Örnek Sorular

## 1. Dersin biçimi

Bu kayıt konu anlatımı değil, dönem projelerinin ilerleme görüşmesidir. Öğrenciler sırayla bağlanıp ekranlarını paylaştı; hoca her projede gelinen noktayı inceleyip sonraki adımları belirledi. Kayıtta iki proje konuşuldu. İlki kısa bir durum aktarımıdır (bölütme çıktısına son işleme). İkincisi daha uzundur: hoca öğrencinin klasörlerini, karışıklık matrisini ve görüntülerini ekranda birlikte inceleyerek histopatoloji görüntüleriyle bir sınıflandırma deneyini baştan kurgular.

## 2. TransUNet bölütmesine Markov rastgele alanlarıyla son işleme

Bir öğrenci, önceki görüşmede TransUNet ile bir bölütme sonucu elde ettiğini hatırlattı. Elde edilen bölütme haritalarında gürültü (küçük, dağınık yanlış etiketli bölgeler) kalmıştı. Önceki görüşmede bu gürültüyü ortadan kaldırmak için bir son işleme (post-processing) adımı eklenmesine ve bunun için Markov rastgele alanlarının (Markov Random Fields, MRF) kullanılmasına karar verilmişti.

Öğrenci hazır bir MRF kodu bulup kendi projesinin girdi verisini alacak biçimde değiştirdiğini, kodun doğru çalıştığını, ama sonuçları henüz değerlendiremediğini anlattı. Görüntülerle çalışırken yaşadığı sorunlar nedeniyle son işlenmiş çıktıları henüz görsel olarak hazırlayamamıştı.

Ayrıca önceki görüşmede TransUNet dışında Swin-Unet ve UNet++ gibi bölütme modellerinin de denenmesi konuşulmuştu. Öğrenci bunlardan en az birini çalıştırıp ona da aynı son işlemeyi eklemeyi planladığını söyledi.

<!-- BELİRSİZ: altyazıda "Unet++++" diye geçen bir model adı daha var; büyük olasılıkla UNet 3+ kastedilmiştir. -->

> **Ek bilgi (derste anlatılmadı):** Markov rastgele alanı, her pikselin etiketinin yalnız komşu piksellerin etiketlerine bağlı olduğunu varsayan bir olasılık modelidir. Bölütmede bir veri terimi (pikselin kendi olasılığı) ile bir düzgünlük terimi (komşularla aynı etikete sahip olma eğilimi) birlikte en iyilenir. Bu sayede çevresinden farklı etiket almış tek tük pikseller ya da küçük adacıklar komşularının etiketine çekilir; bölütme çıktısındaki "tuz-biber" türü gürültü azalır.

## 3. BreakHis veri setinde iyi huylu / kötü huylu sınıflandırma

### 3.1 Veri setinin tanıtılması

İkinci projede bir öğrenci meme dokusu histopatoloji görüntülerini iyi huylu (benign) ve kötü huylu (malignant) olarak sınıflandırıyor. Hoca önce veri setinin tanıtılmasını istedi. Kullanılan veri seti BreakHis'tir ve öğrenci 400 kat büyütmeli (400X) görüntülerle çalışıyor. Öğrencinin klasöründe aynı görüntülerin 299x299 ve 224x224 boyutlu iki ayrı kopyası vardı; `benign` klasöründe 1146 görüntü bulunuyordu (ekrandan, 00:15:00 ve 00:25:00).

Hoca bu noktada iki şeyi sordu: görüntülerin ağa hangi boyutta verildiği ve özgün (yeniden boyutlandırılmamış) görüntülerin boyutu. Öğrenci girdi olarak 299x299 kullandığını söyledi.

<!-- BELİRSİZ: öğrencinin söylediği özgün görüntü boyutu altyazıda bozuk ("yedi yüz çarpı ... altmış"); BreakHis görüntüleri büyük olasılıkla 700x460 pikseldir. -->

### 3.2 224x224 görüntülerin nereden geldiği

Hoca 224x224'lük klasörü açtırıp içindekilerin nasıl hazırlandığını açıkladı. Özgün veri setindeki görüntüler daha büyüktür. Hazır indirilen bu kopyada, özgün görüntünün içinde 224x224'lük kare bir pencere gezdirilerek tek görüntüden birden çok parça elde edilmiştir. Yani 224x224'lük görüntüler küçültülmüş değil, kesilmiş parçalardır; bu nedenle doku ayrıntısını korurlar.

Hoca ayrıca görüntülerin neden 299x299'a getirildiğini sordu ve genellikle 224x224 kullanıldığını hatırlattı. Sonuçta bütün deneylerin 224x224'lük görüntülerle yapılmasını istedi.

> **Ek bilgi (derste anlatılmadı):** Inception-v3 ağının özgün girdi boyutu 299x299'dur; ResNet, DenseNet gibi ağlarınki ise 224x224'tür. Öğrencinin 299x299 seçmesi büyük olasılıkla bu yüzdendir. Bütün ağları aynı 224x224 girdiyle çalıştırmak, karşılaştırmayı adil kılar.

### 3.3 Inception sonucu: karışıklık matrisi

Hoca Inception ile alınan sonucu sordu. Öğrenci çapraz doğrulama deneyinin katlarına (fold) ait karışıklık matrislerini gösterdi. Ekranda "Breast Cancer Detection Using Inception Net. Fold2" başlıklı matris vardı (ekrandan, 00:20:00):

| Gerçek sınıf | Tahmin: benign | Tahmin: malignant | Satır yüzdesi |
|---|---|---|---|
| benign | 229 | 1 | %99,6 / %0,4 |
| malignant | 5 | 224 | %97,8 / %2,2 |
| Sütun yüzdesi | %97,9 / %2,1 | %99,6 / %0,4 | |

Bu matristen ölçütler adım adım şöyle hesaplanır (ara adım eklendi; python ile doğrulandı):

- Toplam örnek: $229 + 1 + 5 + 224 = 459$.
- Doğruluk: $\frac{229 + 224}{459} = \frac{453}{459} \approx \%98{,}7$.
- Benign için duyarlılık (recall, satır yüzdesi): $\frac{229}{230} \approx \%99{,}6$; malignant için: $\frac{224}{229} \approx \%97{,}8$.
- Benign için kesinlik (precision, sütun yüzdesi): $\frac{229}{234} \approx \%97{,}9$; malignant için: $\frac{224}{225} \approx \%99{,}6$.
- F-ölçütü $F = \frac{2PR}{P+R}$: benign için yaklaşık $\%98{,}7$, malignant için yaklaşık $\%98{,}7$.

### 3.4 Görüntülerin siyah görünmesi

Ekrandaki bazı görüntüler siyaha yakın görünüyordu. Bunun bir biçim (format) sorunu olduğu açıklandı: görüntüler 0 ile 1 arasına ölçeklenmiş, görüntüleyici ise 0-255 aralığında değer bekliyor; bu yüzden bütün pikseller çok koyu görünüyor. Farklı kaynaklardan gelen veri setleri farklı biçimlerde (ör. NumPy dizileri) saklanabildiği için, bunları doğru açıp içindeki bilgiyi çekmek de projede öğrenilen bir beceri olarak anıldı.

## 4. Karşılaştırılacak modeller ve başarım ölçütleri

Hoca tek modelle yetinilmemesini, birden çok önceden eğitilmiş ağla karşılaştırma yapılmasını istedi. Model adlarını Zoom sohbet kısmına da yazdı. İstenen ve istenmeyen modeller:

- Inception (hâlihazırda çalışan model).
- ResNet: büyük sürümü, ResNet-101.
- DenseNet: büyük sürümü, DenseNet-201.
- NASNet.
- EfficientNet.
- ShuffleNet istenmedi.

Hoca, var olan sonuçların silinmemesini, yeni modellerin bunlara eklenmesini söyledi. Bütün modeller 299x299 ile değil 224x224 ile çalıştırılacak.

Sonuçlar bir tablo halinde verilecek. Her model için doğruluk (accuracy, yüzde olarak), kesinlik (precision), duyarlılık (recall) ve F-ölçütü (F-measure) raporlanacak. Bu tablo önce BreakHis için, sonra ikinci veri seti (BACH) için hazırlanacak.

> **Hocanın vurgusu:** Bütün modellerin accuracy, F-measure, precision ve recall değerleri tek bir tabloda verilmeli; aynı tablo ikinci veri seti için de hazırlanmalı.

## 5. BACH veri seti ve hücre yoğunluğuna göre yama çıkarma

### 5.1 Veri setinin yapısı

İkinci veri seti ICIAR 2018 BACH (Breast Cancer Histology) veri setidir. Dört sınıf içerir: Benign, InSitu, Invasive ve Normal (ekrandan, 00:35:00). Hoca görüntü boyutunu sordurdu; görüntüler 2048x1536 pikseldir. Benign klasöründe yaklaşık 100 görüntü vardır.

Bu veri setinde, BreakHis'in hazır kopyasındaki gibi 224x224'lük parçalar yoktur. Görüntüler çok büyük olduğu için doğrudan ağa verilemez. Yeniden boyutlandırılırsa (224x224'e küçültülürse) hücre ayrıntısı kaybolur ve başarım çok düşer. Bu yüzden görüntüler 224x224'lük parçalara (yama, patch) kesilerek kullanılmalıdır.

### 5.2 Hangi bölgelerden yama alınır

Hoca uzaktan kontrol alıp bir görüntüyü Paint'te açtırdı ve üzerine 224x224'lük kareler çizerek gösterdi. Önemli noktalar:

- Yamalar yalnız hücrelerin yoğun olduğu bölgelerden alınmalı. Görüntünün kenarlarındaki ya da hücre barındırmayan açık renkli bölgelerinden yama alınmamalı.
- Mor renkli bölgeler daha çok hücre barındırır.
- Aynı görüntüden 3-4 ya da daha çok yama alınabilir ve yamalar üst üste binebilir. Önemli olan her yamanın çok hücre içermesidir.

### 5.3 Otomatik yama çıkarma programı

Bunu elle yapmak çok zor olduğu için hoca bir program yazılmasını istedi. Programın adımları:

```text
1. Görüntüye eşikleme (threshold) uygula; koyu (mor) bölgeleri, yani hücre bölgelerini bul.
2. 224x224'lük bir pencereyi görüntünün sol üst köşesinden başlat.
3. Penceredeki hücre piksellerinin oranını hesapla.
4. Oran eşikten büyükse (örneğin %40'tan fazla hücre) pencereyi yeni bir 224x224 yama olarak kaydet.
5. Pencereyi 50 piksel sağa kaydır (1 piksel değil); satır bitince 50 piksel aşağı inip yeniden başla.
6. Görüntü bitene kadar 3-5 adımlarını tekrarla; her sınıf için ayrı yap.
```

Böylece her sınıftaki 100 civarı görüntüden binlerce yama elde edilir. Bütün sınıflarda yama sayısı artar ve sınıflandırma kalitesi yükselir.

**Soru:** Bu bir tür veri artırma (augmentation) mı, hazır bir veri artırma programı kullanılabilir mi? **Cevap:** Amaç veri artırma değil. Görüntü çok büyük olduğu için ağa doğrudan verilemez, yeniden boyutlandırma da başarımı düşürür; görüntü bu yüzden kesilerek verilir. Hücre yoğun bölgeleri bulup kesen programı öğrencinin kendisi yazmalıdır. Yama sayısının artması bunun yan kazancıdır.

**Soru:** Dört sınıf için de ayrı ayrı mı yapılacak? **Cevap:** Evet, her sınıfın içinde ayrı ayrı yapılacak.

> **Hocanın vurgusu:** Pencereyi birer piksel kaydırma; 50'şer piksel hem sağa hem aşağı kaydır. Yalnız hücre yoğun pencereleri kaydet.

Çalışma sırası olarak hoca önce BreakHis ile bütün modellerin deneylerinin bitirilmesini, BACH yama çıkarma programının bu sırada hazırlanmasını ve ardından BACH deneylerine geçilmesini önerdi.

> **Ek bilgi (derste anlatılmadı):** Hücre bölgelerini bulmak için RGB görüntü doğrudan eşiklenebileceği gibi, renk dekonvolüsyonu ile hematoksilen kanalı ayrılıp o kanal Otsu yöntemiyle eşiklenebilir. Bu, mor çekirdekleri pembe stromadan daha güvenilir ayırır.

## 6. Örnek Sorular

**Soru 1** (ekrandan, 00:20:00; derste sözlü, 00:19:19): Inception ağıyla Fold 2'de aşağıdaki karışıklık matrisi elde edilmiştir. Doğruluğu ve her sınıf için kesinlik ile duyarlılığı bulun.

| Gerçek sınıf | Tahmin: benign | Tahmin: malignant |
|---|---|---|
| benign | 229 | 1 |
| malignant | 5 | 224 |

> **Çözüm (derste verilmedi; ekrandaki yüzdelerle ve python ile doğrulandı):** Toplam 459 örnek, 453 doğru: doğruluk $453/459 \approx \%98{,}7$. Benign: kesinlik $229/234 \approx \%97{,}9$, duyarlılık $229/230 \approx \%99{,}6$. Malignant: kesinlik $224/225 \approx \%99{,}6$, duyarlılık $224/229 \approx \%97{,}8$. İki sınıfta da F-ölçütü yaklaşık $\%98{,}7$'dir.

**Soru 2** (derste sözlü, 00:21:00): Görüntüleri neden 299x299'a getirdin, neden 224x224 kullanmadın?

> **Cevap (dersteki tartışmadan):** Hazır 224x224 görüntüler özgün görüntülerden kayan pencereyle kesilmiş parçalardır ve yaygın ağların girdi boyutu 224x224'tür; hoca bütün modellerin 224x224 ile çalıştırılmasını istedi.

**Soru 3** (derste sözlü, 00:35:14): 2048x1536 boyutlu histopatoloji görüntüleri bir CNN'e nasıl verilmeli?

> **Cevap (derste verildi):** Doğrudan verilemez; yeniden boyutlandırma başarımı çok düşürür. Eşiklemeyle hücre yoğun bölgeler bulunur, 224x224'lük pencere 50'şer piksel kaydırılarak gezdirilir ve hücre oranı örneğin %40'ı geçen pencereler yama olarak kaydedilir.

## Dersin Toparlaması

Bu görüşmede iki proje üzerinden tıbbi görüntü işlemede iki pratik konu öne çıktı. Bölütme tarafında, derin modelin çıktısındaki gürültünün Markov rastgele alanları gibi komşuluk bilgisini kullanan bir son işleme adımıyla temizlenebileceği ve sonuçların farklı bölütme modelleriyle karşılaştırılması gerektiği konuşuldu. Sınıflandırma tarafında ise histopatoloji görüntülerinin büyük boyutu nedeniyle küçültülmeden, hücre yoğun bölgelerden kesilen 224x224'lük yamalarla kullanılması gerektiği, bu yamaların eşikleme ve kayan pencereyle otomatik çıkarılabileceği anlatıldı.

Deney tasarımı açısından hocanın beklentisi nettir: aynı girdi boyutuyla birden çok önceden eğitilmiş ağ (Inception, ResNet-101, DenseNet-201, NASNet, EfficientNet) çalıştırılmalı; doğruluk, kesinlik, duyarlılık ve F-ölçütü her veri seti için ayrı bir karşılaştırma tablosunda sunulmalıdır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
