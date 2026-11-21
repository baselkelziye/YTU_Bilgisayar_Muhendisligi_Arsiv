# Ders 13 Genişletilmiş Notu: Proje İlerleme Sunumları: Transfer Öğrenme, Bölütleme Değerlendirmesi ve K-Katlı Çapraz Doğrulama

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yapısı
- 2. Kolon Kanseri Çekirdek Sınıflandırma ve Transfer Öğrenme
- 3. MR'da Beyin Tümörü Bölütleme: Yer Gerçeği ve Değerlendirme Metrikleri
- 4. Cervix93 ve Herlev: Yama Tabanlı Sınıflandırma
- 5. BraTS 2020: Kesit Seçimi ve Çok Kanallı Girdi
- 6. Akyuvar Sınıflandırma ve K-Katlı Çapraz Doğrulama
- 7. Önceden Eğitilmiş Ağların Seçimi ve Eğitim Eğrileri
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Yapısı

Bu derste yeni bir konu anlatılmadı. Öğrenciler dönem projelerindeki ilerlemeyi ekran paylaşarak gösterdi; hoca her sunumdan sonra veri setinin doğru kullanımı, yöntem seçimi, karşılaştırma ve değerlendirme üzerine öneriler verdi, gerektiğinde beyaz tahtada çizerek açıkladı. Projeler tıbbi görüntü analizi üzerinedir: kolon kanseri histoloji görüntülerinde çekirdek sınıflandırma, MR görüntülerinde beyin tümörü bölütleme (iki ayrı proje), servikal sitoloji görüntülerinde çekirdek tespiti ve sınıflandırma, kan yayması görüntülerinde akyuvar sınıflandırma. Not, sunumlardaki akademik içeriği ve hocanın önerilerini sunum sırasıyla aktarır; sunum yapanlar "bir öğrenci" diye anılır.

## 2. Kolon Kanseri Çekirdek Sınıflandırma ve Transfer Öğrenme

### 2.1 Veri seti ve yamalar

Bir öğrencinin projesi kolon kanseri histoloji görüntülerinde hücre çekirdeklerini sınıflandırmaktır. Slayta göre veri setinde 100 görüntü vardır; görüntüler 500×500 pikseldir, 9 hastanın 10 tam slaytından 0,55 µm/piksel çözünürlükte (20x optik büyütme) elde edilmiştir ve hem normal hem kanserli bölgeler içerir (ekrandan, 00:10:00).

Hoca önce sınıf yapısını sordu: dört sınıf varsa ve her sınıfa ait 100 görüntü varsa toplam 400 görüntü olması gerekirdi. Öğrenci durumun farklı olduğunu açıkladı: 100 görüntünün her birinde dört sınıfın çekirdekleri bir arada bulunabilir. Sınıflar fibroblast, epitel, kanserli (hastalıklı) hücre ve diğerleridir (nekrotik vb.). Bazı görüntülerde epitel hiç yoktur, bazılarında dört sınıfın hepsi vardır. Bu yüzden görüntünün tamamı tek bir sınıfa atanamaz; sınıflandırma çekirdek düzeyinde yapılmalıdır.

Öğrenci, veri setinde verilen çekirdek konumlarını kullanarak her çekirdeği merkeze alan 27×27 boyutlu yamalar kırpmıştır. Fibroblast için yaklaşık 5149, epitel için 7069 yama elde etmiştir. <!-- BELİRSİZ: kanserli ve "diğer" sınıflarının yama sayıları altyazıda bozuk ("altı bir", "1700-21") -->

### 2.2 İlk sonuçlar

Öğrencinin slaytındaki tabloya göre (ekrandan, 00:10:00):

| Model | Doğrulama |
|---|---|
| SqueezeNet | %80,04 |
| ResNet50 | %79,05 |

<!-- BELİRSİZ: öğrenci sözlü olarak ilk denemelerde 66 ve 75 gibi değerlerden söz etti; bunların hangi denemeye ait olduğu altyazıdan anlaşılmıyor. Tablodaki değerler ekrandan alındı. -->

Öğrenci eğitimde bir ayar sorununu da anlattı: MATLAB'in eğitim seçeneklerindeki doğrulama sabrı (validation patience) 5, 10, 15 gibi bir değerdeyken eğitim, doğrulama başarısı bir süre iyileşmeyince erken duruyordu. Değeri `Inf` (sonsuz) yapınca eğitim belirlenen dönem sayısının sonuna kadar sürdü.

### 2.3 Önceden eğitilmiş ağırlıklar

Hoca, önceki ağırlıkları yükleyip onların üzerinden mi eğittiğini sordu. Öğrenci ağı ağırlık yüklemeden, yalnız mimari olarak kullanmıştı. Hoca aynı mimarinin önceden eğitilmiş ağırlıklarla ve ağırlıksız çalıştırılmasının aynı sonucu vermeyeceğini belirtti ve MATLAB belgelerindeki "Pretrained Deep Neural Networks" sayfasını açtırdı.

Sayfada anlatılanlar şöyle özetlendi:

- MATLAB'de hazır ağlar vardır: NASNet, DenseNet, Inception, Xception, DarkNet, ResNet ve diğerleri. Sayfadaki karşılaştırma grafiği NASNet gibi ağların daha yüksek doğruluk verdiğini gösterir.
- Önce ağ yüklenir ("Load Pretrained Networks").
- Transfer öğrenme ("Reuse Pretrained Networks") bölümü bu projeler için en önemli kısımdır. ImageNet ile eğitilmiş ağlar, bir milyonu aşkın görüntü ve bin sınıf üzerinden alt seviye özellikleri zaten öğrenmiştir.
- Son katmanlar değiştirilir ("Replace Final Layers"); yeni katmanlar veri setine özgü özellikleri öğrenir.

Hoca bunun bu projeye uygulanışını şöyle anlattı: 27×27 yamalar ağa verilir, özellikle son katmanlar yeniden eğitilir ve ağırlıklara ince ayar (fine tuning) yapılır. Sayfada adım adım anlatılan bu akış izlenmeli ve listedeki bütün ağlar çalıştırılıp sonuçları karşılaştırılmalıdır.

### 2.4 ONNX

Aynı sayfada Caffe ve PyTorch gibi çerçevelerden model aktarma da geçiyordu. Hoca ONNX'e dikkat çekti: Python tarafı ile MATLAB'in paylaştığı ortak bir ara katmandır ve modeller bu biçimle bir ortamdan ötekine aktarılabilir. Öğrenciden, kendi konusuyla ilgili ONNX biçiminde paylaşılmış modeller olup olmadığını araştırmasını istedi.

> **Ek bilgi (derste anlatılmadı):** ONNX (Open Neural Network Exchange), sinir ağı modellerini çerçeveden bağımsız bir biçimde saklamak için açık bir standarttır. PyTorch ya da TensorFlow'da eğitilmiş bir model ONNX'e dışa aktarılıp MATLAB'e alınabilir ya da tersi yapılabilir.

## 3. MR'da Beyin Tümörü Bölütleme: Yer Gerçeği ve Değerlendirme Metrikleri

### 3.1 Öğrencinin seçtiği makale

İkinci sunumdaki öğrencinin konusu "Segmentation Method for Pathological Brain Tumor and Accurate Detection using MRI" başlıklı makaleydi (ekrandan, 00:15:00). Makalenin özetine göre:

- MR görüntüleri üç düzlemde alınır (eksenel, koronal, sagital) ve gürültülüdür; tümör konumunun tespiti zordur.
- Görüntüye ikili eşikleme (binarization) uygulanır, gereksiz nesneler çıkarılır ve tümör çevresinde kontur oluşturulur.
- Yoğunluk değişimine göre tümörü ayırmak için bulanık K-ortalama ile öz düzenlemeli haritanın melezi (FKM-SOM) kullanılır.
- Öznitelikler ayrık dalgacık dönüşümü (DWT) ile çıkarılır, temel bileşen analizi (PCA) ile azaltılır; her görüntüden 13 öznitelik elde edilir.
- Sınıflandırma destek vektör makinesiyle (SVM) yapılır; RBF, doğrusal ve polinom çekirdekler denenir.
- Değerlendirme F-ölçüsü, kesinlik (precision), doğruluk, özgüllük ve duyarlılık (recall) ile yapılır.

Öğrenci makalenin MATLAB kodunu ve arayüzünü (GUI) gösterdi. Klasörde `Benign` ve `Malignant` görüntü klasörleri, `Brain_DWT_PCA`, `BrainMRI_GUI`, `crossfun` gibi MATLAB dosyaları ile `Normalized_Features` ve `Trainset` veri dosyaları vardı (ekrandan, 00:20:00). Öğrenci karşılaştırma yapmak için ayrıca bir Kaggle veri seti indirmişti.

### 3.2 Hocanın sorusu: bölütleme doğruluğu neye göre ölçülüyor?

Hoca, bölütleme doğruluğunun nasıl ölçüldüğünü ve bir yer gerçeği (ground truth) dosyası olup olmadığını sordu. Öğrenci veri setinde maske dosyalarını aradı, ancak açılan dosyalar beklenen türde değildi. Hoca bunun üzerine kavramı beyaz tahtada açıkladı (ekrandan, 00:25:00):

- Veri setinde orijinal MR görüntüleri bulunur; farklı çekim türlerinden birden çok MR görüntüsü olabilir.
- Bunların yanında bir **yer gerçeği (GT) dosyası** bulunmalıdır. Bu dosya tümörün nerede olduğunu, yani tümör alanlarını gösterir.
- Bir yöntem uygulanınca **bölütlenmiş görüntü** elde edilir. Bu görüntüde tümör bölgesi olabilir, ama yanında artefaktlar da bulunabilir; yöntem hangisinin tümör olduğunu kendiliğinden bilmez.
- Bölütlemenin iyi mi kötü mü olduğunu anlamak için sonuç yer gerçeğiyle karşılaştırılır: tümör bölgesinin konumları üst üste konur ve ne kadarının örtüştüğüne bakılır.
- Örtüşme, tümör alanına doğru düşen piksellerin yüzdesi, kesişim/birleşim (IoU) ya da Dice ölçüsü gibi metriklerle sayısallaştırılır.

> **Hocanın vurgusu:** Bölütleme sonucunu yer gerçeğiyle karşılaştırmadan yöntemin başarısı için sayısal bir sonuç elde edilemez; sonuçları değerlendirmek için bu dosyaya ihtiyaç vardır.

> **Ek bilgi (derste anlatılmadı):** $A$ bölütleme sonucu, $B$ yer gerçeği maskesi olmak üzere $\mathrm{IoU} = \dfrac{|A \cap B|}{|A \cup B|}$ ve $\mathrm{Dice} = \dfrac{2|A \cap B|}{|A| + |B|}$ biçiminde tanımlanır. İkisi de 0 ile 1 arasındadır; 1 tam örtüşmeyi gösterir.

### 3.3 Sınıflandırma veri seti ile bölütleme veri seti farkı

Öğrencinin gösterdiği Kaggle veri setinde yalnız `yes` ve `no` klasörleri vardı; `no` klasöründe 98 dosya bulunuyordu ve etiketler sağlık, sınıflandırma, derin öğrenme gibi etiketlerdi (ekrandan, 00:30:00). Hoca, görüntünün maske dosyası gibi görünen kısmının ayrıntılarının ancak uygun bir programla açılınca görülebileceğini söyledi ve veri setinin açıklama sayfasını okutmaya çalıştı. Bu tür bir sette görüntü yalnız "tümör var/yok" diye etiketlidir; bölütleme için gereken piksel düzeyinde maske yoktur.

Hoca Kaggle'da BraTS adlı beyin tümörü bölütleme setini açtı ve açıklamasını okuttu: 2015 yarışmasına (challenge) ait, dört tür MR görüntüsü içeren, eğitim ve test vakaları ayrı verilmiş bir bölütleme kıyaslama (benchmark) setidir. Bu tür bir sette derin öğrenme yöntemleriyle bölütleme yapılabilir ve sonuç yer gerçeğiyle karşılaştırılabilir.

Hoca ikinci çizimde süreci şöyle bağladı (ekrandan, 00:35:00): MR görüntüsü U-Net, SegNet gibi bir derin öğrenme ağına verilir; ağın ürettiği bölütleme, tümörün kesin konumunu gösteren yer gerçeğiyle karşılaştırılır; buradan genel doğruluk (OA), IoU gibi değerlendirme metrikleri elde edilir. Yer gerçeğiyle %100 örtüşme beklenmez.

> **Hocanın vurgusu:** Görev "MRI segmentation evaluation" konusunu araştırmaktır: 2018'den sonraki MR bölütleme makaleleri okunmalı, hangi veri setlerini ve hangi değerlendirme metriklerini kullandıkları çıkarılmalıdır. BraTS 2015 ile başlanıp sonraki BraTS setlerine geçilebilir.

Hoca ayrıca arayüz istemediğini, herhangi bir araç kutusunun (toolbox) kullanılabileceğini, kendisine yalnız sonuçların yeteceğini söyledi.

## 4. Cervix93 ve Herlev: Yama Tabanlı Sınıflandırma

### 4.1 Koordinat sorunu ve bağlantılı bileşenler

Üçüncü sunumdaki öğrenci, Cervix93 veri setinde verilen çekirdek koordinatlarının önceki hafta yanlış yerlere düşmesi sorununu çözmüştü. Slayttaki sol görüntü orijinal kare, sağdaki ise verilen koordinatlarda çekirdeklerin yuvarlak içine alındığı hâliydi (ekrandan, 00:50:00). Bu yuvarlaklara bağlantılı bileşen analizi (connected component analysis) uygulamıştı. Amacı önce bölütlemeyle çekirdekleri bulmak, sonra rahim ağzı kanseri derecelerine göre sınıflandırma yapmaktı.

### 4.2 Veri setinin makalesi

Hoca, veri setini yayımlayanların onu nasıl kullandığını görmek için orijinal makaleyi açtırdı: "A New Cervical Cytology Dataset for Nucleus Detection and Image Classification (Cervix93) and Methods for Cervical Nucleus Detection" (ekrandan, 00:40:00). Özete göre:

- Veri seti 93 gerçek görüntü yığınından (image stack) oluşur; her yığının genişletilmiş alan derinliği (EDF) görüntüsü ve odak katmanları verilir.
- Görüntüler üç Pap testi derecesine ayrılır: Negative, düşük dereceli skuamöz intraepitelyal lezyon (LSIL) ve yüksek dereceli skuamöz intraepitelyal lezyon (HSIL).
- Toplam 2705 çekirdek elle işaretlenmiştir.

Öğrenci, etiket dosyasında harf ile derecenin, 0 ile eğitim, 1 ile test görüntüsünün gösterildiğini açıkladı. Örnek olarak açılan üç kare üç farklı sınıfı gösteriyordu: biri yüksek dereceli bozukluk, biri düşük dereceli bozukluk, biri normal. Bir yığın yaklaşık 20 katmanlıdır.

Hoca önemli bir soruyu netleştirdi: sınıf görüntünün tamamına mı aittir? Öğrenci, makalede her görüntünün tek bir sınıfa atandığını söyledi. Buna göre bir görüntüdeki hücrelerin hepsi o görüntünün sınıfına ait kabul edilebilir.

Makalenin derin öğrenme bölümünde şu ayrıntılar vardı (ekrandan, 00:45:00):

- CNN iki evrişim katmanı ve iki tam bağlantılı katmandan oluşur; her evrişimden sonra maksimum havuzlama, her tam bağlantılı katmandan sonra ReLU gelir; çıkış katmanında iki nöron ve softmax vardır. Ağ her yamanın çekirdek olup olmadığının olasılığını üretir.
- Eğitim karelerinin gri seviye hâlinden 75×75 yamalar 15 piksel aralıkla alınır; elle işaretli bir noktaya 15 pikselden yakın yama pozitif, diğerleri negatif etiketlenir.
- Öğrenme oranı sabit 0,001, eğitim 100 dönem; toplam 654.948 yama, bunların yalnız %1,71'i pozitif.
- Testte yamalar 3 piksel aralıkla alınır; isabet haritası genişletilir ve 0,5 eşiğiyle eşiklenir; 100 pikselden küçük bölgeler atılır.

> **Ders sonrası not:** Hoca 75×75 yamaların büyük olasılıkla hücre merkezleri bulunduktan sonra etraflarından alındığını tahmin etti. Ekrandaki makale metnine göre bu yamalar düzenli 15 piksellik ızgaradan alınıyor ve "çekirdek / çekirdek değil" tespiti için kullanılıyor; görüntü derecesini sınıflandırmak için kullanılmıyor.

### 4.3 Hocanın önerdiği akış

Hoca, yalnız yama alınacaksa hücre merkezlerini ayrıca bulmanın şart olmadığını, ama yamaların hücre içeren bölgelerden alınması gerektiğini söyledi; 75×75'lik bir yama beyaz (boş) bölgeye denk gelirse anlamsız olur. Önerdiği akış:

- Hücre merkezleri etrafından yamalar al. Yama boyutu olarak 64, 128 ve 256 karşılaştırılsın. Öğrencinin çalıştığı görüntüler yaklaşık 960×1280 boyutunda olduğu için 75×75 yerine daha büyük yamalar düşünülebilir. Öğrenci 256'nın 128'den iyi sonuç verdiğini, 512'nin ise belleği zorladığını söyledi; hoca büyük yamanın daha çok uzamsal bilgi taşıdığını, bunun yazıda vurgulanacağını belirtti.
- Veri artırma (data augmentation) uygula: yamaları döndür ve köşegen boyunca yansıt.
- Önceden eğitilmiş ağlarla transfer öğrenme yap ve son katmanı üç sınıfa göre ayarla. MATLAB ya da Python kullanılabilir.

Hoca yama sayısını sözlü olarak hesapladı: sınıf başına yaklaşık 30 görüntü olduğu varsayılsın; gösterilen bir görüntüde yaklaşık 20 hücre sayılabiliyor. Her görüntüden 20 yama alınırsa sınıf başına $30 \times 20 = 600$ yama elde edilir. Bu yamalar dört yöne döndürülerek ve köşegen yansıtmayla çoğaltılır.

> **Hocanın vurgusu:** Kabul şudur: bir görüntüden kesilen her yama, o görüntüyle aynı hastalık tipindeki hücrelerden oluşur. Yaklaşımı netleştirip veri artırma ve ardından transfer öğrenmeyle sonuçları iyileştirmek gerekir.

Öğrenci U-Net ile bölütleme denemişti; veri sayısı az olduğu için başarı düşük kalıyordu. Hoca, veri setinde hücre bölütleri değil yalnız hücre merkezleri verildiğini öğrenince yukarıdaki yama tabanlı sınıflandırma yolunu önerdi.

### 4.4 Herlev veri seti

Öğrenci ikinci veri seti olarak Herlev'i de kullanıyordu. Herlev'de hem bölütleme hem sınıflandırma yapılabilir ve 7 sınıf vardır. Slaytta solda verilen maske, sağda öğrencinin U-Net ile elde ettiği maske vardı: açık mavi çekirdek, koyu mavi sitoplazma sınırı, kırmızı arka plan; gri bölgeler çözünürlüğün düşük olduğu belirsiz bölgelerdi. U-Net bölütlemesinde yaklaşık %85 başarı elde etmişti. Hoca iki veri setinin birlikte kullanılmasını, Herlev'de önce bölütleme başarısının verilip sonra yamalarla sınıflandırmaya geçilmesini önerdi.

Ağ seçimi için hoca şunu söyledi: VGG artık eskide kaldı; ResNet, Inception, Xception ve yeni ağlardan NASNet gibi birkaç farklı ağ denenip karşılaştırılmalıdır.

## 5. BraTS 2020: Kesit Seçimi ve Çok Kanallı Girdi

### 5.1 Veri setinin yapısı

Dördüncü sunumdaki öğrenci, önceki haftalarda veri setini koda yükleyemediği BraTS ile çalışmayı başarmıştı. Slaytta BraTS2020'den bir MR kesiti ve karşılık gelen tümör maskesi gösterildi (ekrandan, 00:55:00). Veri setinin yapısı şöyledir:

- 349 beyin MR hacmi vardır (öğrencinin kullandığı 2020 seti).
- Her hacim 155 kesitten (katman) oluşur.
- Her hasta için dört farklı çekim yöntemiyle alınmış görüntü vardır: FLAIR, T1, T1CE, T2. Beşinci dosya bölütleme maskesidir; maske de 3B veridir.
- İlk yaklaşık 40 ve son yaklaşık 30 kesitte maske görünmez, bu kesitlerde tümör yok kabul edilir.

Hoca bunu 3B bir nesne olarak düşünmeyi önerdi: tümör, beyin hacminin içindeki bir nesnedir. Kesitler sırayla alındığında tümöre ulaşmayan kesitlerde maske boştur; tümörü kesmeye başlayan kesitte yer gerçeği küçük bir bölge olarak ortaya çıkar, sonraki kesitlerde büyür, sonra yeniden küçülüp kaybolur. Her kesitte tümör olması beklenmez.

Dört çekim yönteminin anlamı da konuşuldu: öğrenci bunları aynı görüntüye farklı süzgeçler uygulanmış gibi düşünülebileceğini söyledi. Hoca önce her yöntemin ayrı ayrı denenmesini, sonra dördünün birlikte kullanılmasını istedi.

> **Ek bilgi (derste anlatılmadı):** FLAIR, T1, T1CE (kontrast madde verildikten sonra T1) ve T2, MR'da farklı doku özelliklerini öne çıkaran çekim dizileridir. Örneğin FLAIR tümör çevresindeki ödemi, T1CE ise tümörün kontrast tutan aktif kısmını daha iyi gösterir; bu yüzden birlikte kullanıldıklarında birbirini tamamlarlar.

### 5.2 Hangi kesitler kullanılmalı?

Hoca kesit seçimini beyaz tahtada anlattı (ekrandan, 01:05:00). Her hacmin 150 küsur kesitinden yer gerçeği içerenler seçilir. Örnek: her hastada 100 kesit tümör içersin. O zaman

$$349 \times 100 = 34.900$$

kesitlik bir veri değerlendirilir. Aslında hasta sayısının kendisi çok önemli değildir; asıl ölçülen, beyin bölgesindeki tümör bölütlerinin doğru bulunup bulunmadığıdır.

Kesit seçiminde dikkat edilecekler:

- Önce her hastanın yer gerçeğine bakılır; hangi kesitlerde maske varsa onlar üzerinde çalışılır.
- Bazı kesitlerde yalnız 15-20 piksellik noktasal bölgeler kalabilir. Hoca yaklaşık 25-50 piksel düzeyinde bir alt sınır önerdi: 25 pikselin altındaki bölgeler alınmaz, üstündekiler alınır.
- Yer gerçeği verilmişse bölge kabul edilir; öğrencinin kesitlere bakıp "gerçekten bölge var mı" diye kuşkulanmasına gerek yoktur.

> **Hocanın vurgusu:** Parça çok küçükse ağ çevresinden bir doku (texture) bilgisi yakalayamaz ve onun tümör olduğunu öğrenemez. Yeterli yer gerçeği olmayan kesitler başarımı düşürür; belli bir büyüklüğün altındakiler ayıklanmalı, okunan makalelerde ne yapıldığına da bakılmalıdır.

Öğrenci de benzer bir çalışmada ilk ve son kesitlerin doğrudan dışarıda bırakıldığını gördüğünü söyledi.

### 5.3 Dört kanallı girdi

Hoca, U-Net'e verilecek girdiyi şöyle tarif etti: örneğin 25. kesit seçilmişse dört çekim yönteminin her birinin 25. kesiti alınır. Böylece dört katmanlı bir görüntü elde edilir; çıktısı olarak yer gerçeğinin 25. kesiti verilir. Sonra 26. kesite geçilir ve aynı işlem tekrarlanır. Dört farklı çekim tekniği dört farklı öznitelik sağladığı için bu yolla daha iyi sonuç beklenir. Öğrenci kesit boyutunu 256×256 olarak verdi; girdi 256×256×4 olur.

<!-- BELİRSİZ: öğrenci kesit boyutunu 256×256 dedi; ekrandaki BraTS çiziminin eksenleri yaklaşık 240'a kadar uzanıyor ve koddaki satır input_shape = (240, 240, 1) (ekrandan, 00:55:00 ve 01:00:00). Koddaki tek kanal, dört kanallı girdi açıklamasıyla da örtüşmüyor. -->

> **Ders sonrası not:** BraTS hacimleri büyük olasılıkla 240×240×155 boyutundadır; ekrandaki kodda da girdi 240×240 olarak tanımlı. Öğrencinin söylediği 256×256 büyük olasılıkla yeniden boyutlandırılmış bir hâli ya da yanlış hatırlanmış bir değerdir.

### 5.4 Kullanılan ağlar

Öğrenci U-Net ile U-Net ve ResUNet karışımı melez bir ağ kullanmıştı; bunların özgün olmadığını, karşılaştırma için en az 2-3 sonuç elde etmek amacıyla denendiğini söyledi. Jupyter'de gösterdiği ResUNet kodunda (ekrandan, 01:00:00) bir artık blok (`resblock`) şöyle tanımlanıyordu:

```python
def resblock(X, f):
    X_copy = X  # copy of input

    # main path
    X = Conv2D(f, kernel_size=(1,1), kernel_initializer='he_normal')(X)
    X = BatchNormalization()(X)
    X = Activation('relu')(X)

    X = Conv2D(f, kernel_size=(3,3), padding='same', kernel_initializer='he_  # satır sonu ekranda kesik
    X = BatchNormalization()(X)

    # shortcut path
    X_copy = Conv2D(f, kernel_size=(1,1), kernel_initializer='he_normal')(X_  # satır sonu ekranda kesik
    X_copy = BatchNormalization()(X_copy)

    # Adding the output from main path and short path together
    X = Add()([X, X_copy])
    X = Activation('relu')(X)

    return X

def upsample_concat(x, skip):
    X = UpSampling2D((2,2))(x)
    merge = Concatenate()([X, skip])

    return merge

input_shape = (240, 240, 1)
X_input = Input((input_shape))
```

Kod ekrandan aktarılmıştır; iki satırın sonu ekranda kesik olduğu için öyle bırakılmıştır, bu yüzden kod bu hâliyle çalışmaz. Derste kodun ayrıntısı anlatılmadı. Blok iki yoldan oluşur: ana yolda 1×1 ve 3×3 evrişimler, toplu normalleştirme ve ReLU; kısayol yolunda girdinin 1×1 evrişim ve toplu normalleştirmeden geçirilmiş kopyası. İki yol `Add()` ile toplanır. `upsample_concat`, kod çözücüde görüntüyü iki kat büyütüp kodlayıcıdan gelen atlama bağlantısıyla birleştirir. Aynı ekranda bir makaleden alınmış, T1, T1-Gd, T2, T2-FLAIR görüntüleri ile otomatik ve elle bölütleme sonuçlarını iyi ve kötü örnekler olarak karşılaştıran bir şekil de görünüyordu.

Hoca Double U-Net adlı bir ağı da not almasını istedi. Bölütleme ağlarının çalışma ilkesini şöyle özetledi: ağa bir görüntü ve yer gerçeği verilir, ağ kendi bölütlemesini üretmeyi öğrenir.

Öğrenci doğrulama doğruluğunun %90-99 gibi çok yüksek çıkmasının kafasını karıştırdığını söyledi. Ayrıca GAN ile bölütleme denemek istemiş, ancak veri büyüklüğü belleği aştığı için çalıştıramamıştı. Hoca önce U-Net ve Double U-Net'in çalıştırılmasını, yöntemlerin sonra zenginleştirilmesini önerdi.

> **Ek bilgi (derste anlatılmadı):** Bölütlemede piksel doğruluğu yanıltıcı olabilir: bir kesitte piksellerin çok büyük kısmı arka plandır, bu yüzden hiç tümör bulmayan bir model bile yüksek piksel doğruluğu alabilir. Bu nedenle bölütleme çalışmalarında doğruluk yerine ya da yanında Dice ve IoU raporlanır.

## 6. Akyuvar Sınıflandırma ve K-Katlı Çapraz Doğrulama

### 6.1 Projenin akışı

Beşinci sunumdaki öğrenci kan yayması görüntülerinde akyuvar (beyaz kan hücresi) sınıflandırması yapıyordu. Slayttaki akış şemasına göre (ekrandan, 01:15:00):

- Ana veri setinde dört sınıf vardır: eozinofil, lenfosit, monosit, nötrofil.
- Ön işlem: histogram, RGB'den gri seviyeye dönüşüm, medyan süzgeç.
- Bölütleme iki yoldan yapılır. Bölge tabanlı (region-based) bölütleme iki yeni veri seti üretir: kırmızı kan hücreleri (RBC) ve beyaz kan hücreleri (WBC). İkinci yol derin öğrenmeyle anlamsal bölütlemedir (semantic segmentation); burada her piksel kırmızı hücre, beyaz hücre ya da arka plan olarak etiketlenir.

Öğrenci üç eğitim yapmıştı: birincisi dört hücre tipinin sınıflandırılması, ikincisi bölütlenmiş hücreler üzerinde sınıflandırma, üçüncüsü anlamsal bölütleme. Her görüntüde bir ana hücre vardır; örneğin eozinofil görüntüsünde yalnız eozinofil işaretlidir.

### 6.2 Sonuçlar

"Training 1" slaytına göre ResNet50 ile dört sınıflı sınıflandırmada %90 doğruluk elde edilmişti (ekrandan, 01:20:00). Aynı slaytta MATLAB kodundan şu satırlar görünüyordu:

```matlab
[YPred,score] = classify(netTransfer, ...);
%% Accuracy
YValidation = imdsValidation.Labels;
accuracy = mean(YPred == YValidation)
%% Test Network on One Image
load('net4classResnet50.mat')
```

İlk satırın sonu ekranda kesiktir. Tek bir eozinofil görüntüsü sınandığında ağın çıktısı 1×4'lük bir satır vektörüydü (ekrandan, 01:20:00):

$$Y = [\,0{,}9647 \quad 0{,}0058 \quad 0{,}0191 \quad 0{,}0104\,]$$

Birinci sınıfın (eozinofil) olasılığı 0,9647'dir; öğrenci bunu "%96 eozinofil" diye okudu. Dört değerin toplamı $0{,}9647 + 0{,}0058 + 0{,}0191 + 0{,}0104 = 1{,}0000$ olur (python ile kontrol edildi), bu da softmax çıktısıyla tutarlıdır.

Hoca %90'ın tek bir görüntü için mi yoksa genel ortalama mı olduğunu sordu; öğrenci %90'ın bütün doğrulama kümesine ait olduğunu söyledi. Veri ayırma olarak her sınıftan yaklaşık 1200 görüntü kullandığını ve verinin %70'ini eğitime, %30'unu teste ayırdığını belirtti. Eğitim CPU'da çok uzun sürüyordu; GPU'lu bir bilgisayarla birkaç saate indiğini, sürenin ağa (ResNet, VGG16) göre değiştiğini söyledi.

> **Hocanın vurgusu:** Şu aşamada farklı hücre tiplerini ayrıştırmak, yani sınıflandırma görevi proje için yeterlidir. Bu görev farklı önceden eğitilmiş ağlarla (DenseNet, ResNet, NASNet, Inception, Xception) tam olarak yapılmalı ve sonuçlar karşılaştırılmalıdır. Derin öğrenmeyle bölütleme daha sonra ayrı bir çalışma olarak yapılır.

### 6.3 K-katlı çapraz doğrulama

Hoca, verinin %70/%30 diye elle bir kez ayrılması yerine K-katlı çapraz doğrulama (K-fold cross-validation) kullanılmasını önerdi ve bunu beyaz tahtada anlattı (ekrandan, 01:25:00). Hoca rakamların uydurma olduğunu, yalnız anlatım için seçildiğini belirtti.

Verilen:

- Dört sınıf: eozinofil (E), lenfosit (L), monosit (M) ve dördüncü sınıf (tahtada $L_2$). Her birinden 1000 örnek.
- Toplam $4 \times 1000 = 4000$ örnek.
- Kat sayısı $K = 5$.

İşlem:

1. Her sınıf beş parçaya bölünür; ya da 4000 örneklik veri her parçada her sınıftan eşit sayıda örnek olacak biçimde beş parçaya bölünür.
2. Her parçada $4000 / 5 = 800$ örnek vardır. Bunun $800 / 4 = 200$'ü birinci sınıf, 200'ü ikinci, 200'ü üçüncü, 200'ü dördüncü sınıftır.
3. Birinci denemede 1, 2, 3, 4. parçalar eğitim ($4 \times 800 = 3200$ örnek), 5. parça test (800 örnek) olarak kullanılır.
4. İkinci denemede 1, 2, 3, 5 eğitim, 4 test; üçüncü denemede 1, 2, 4, 5 eğitim, 3 test olur. Böyle devam edilerek her parça bir kez test edilir.
5. Beş denemenin test sonuçlarının ortalaması alınır. Hocanın örneğinde denemelerden %91, %85, %75 gibi sonuçlar çıkıyor ve genel sonuç bunların ortalamasıdır.

Sonuç: verinin her tarafı bir kez test olarak kullanılmış olur. Bu, elle yapılan tek bir ayırmaya göre daha sağlam bir sonuç verir. Hoca MATLAB'de bunun için "Partition data for cross-validation" belgesindeki `cvpartition` komutunu gösterdi ve ayrıntısını okumasını istedi.

> **Hocanın vurgusu:** %70'e %30 diye elle ayırmak yerine K-katlı çapraz doğrulamayla verinin değişik yerleri test ve eğitim olarak kullanılmalıdır; böylece daha sağlam sonuçlar elde edilir. Genelde 5 kat kullanılır: %80 eğitim, %20 test.

## 7. Önceden Eğitilmiş Ağların Seçimi ve Eğitim Eğrileri

### 7.1 Hangi ağlar denenmeli?

Hoca MATLAB'in "Pretrained Deep Neural Networks" sayfasındaki karşılaştırma grafiğini yeniden açtı ve MATLAB ile çalışan bütün öğrencilerin denemesi gereken ağları işaretledi (ekrandan, 01:30:00): ResNet-50, ResNet-101, Inception-v3, DarkNet-53, Xception, Inception-ResNet-v2, DenseNet-201 ve NASNet-Large. Grafikte ayrıca ResNet-18, GoogLeNet, ShuffleNet, SqueezeNet, MobileNet-v2, DarkNet-19, EfficientNet-b0, NASNet-Mobile, VGG-16 ve VGG-19 da yer alıyordu. Hoca işaretlediği kısmın yüksek sonuç verdiğini, diğerlerinin de iyi sonuç verebileceğini ve denenebileceğini söyledi.

### 7.2 Bölütleme ağları için kaynak

Beyin tümörü bölütleme üzerinde çalışan öğrencilere hoca U-Net ile başlamalarını ve sonra geliştirmelerini söyledi; çünkü U-Net derin öğrenmeyle bölütlemede temel bir yapı olarak kalmıştır. Double U-Net ile NASNet'in farklı yapılar olduğunu, NASNet'in sınıflandırma ağı olduğunu hatırlattı. Bölütleme yapan öğrenciler için birçok yöntemi karşılaştıran bir derleme (survey) makalesi olan "Deep Learning Segmentation" kaynağını paylaştı; oradaki yeni yöntemlere bakılmasını istedi.

### 7.3 Doğrulama eğrisindeki dalgalanma

**Soru:** Eğitimde doğrulama eğrisi düzenli yükselmek yerine bir anda %90'lara çıkıyor, sonra geri düşüyor; bunun nedeni ne olabilir?

**Cevap:** Hoca projenin ayrıntısını incelemediğini belirtti. Önceden eğitilmiş ağlar hazır ağırlıklarla başladığı için eğitim ister istemez belli bir doğruluktan başlar. Biyomedikal görüntüler çok karmaşık değildir, ağ bunlara çabuk uyum sağlayabilir; bu da verinin iyi ayrıştığını gösterebilir. Bu durum tek başına bir hata anlamına gelmez. Ara grafiklerin çıkarılmasına da gerek yoktur; 5 katlı çapraz doğrulama ile %80 eğitim, %20 test yeterlidir.

## Örnek Sorular

**Soru 1** (ekrandan, 01:25:00): Dört sınıfın her birinden 1000 örnek olan bir veri setinde 5 katlı çapraz doğrulama uygulanıyor. Her katta kaç örnek vardır, her katta her sınıftan kaç örnek bulunur, her turda kaç örnekle eğitim ve kaç örnekle test yapılır? Nihai sonuç nasıl bulunur?

> **Çözüm (derste verildi):** Toplam $4 \times 1000 = 4000$ örnek. Her kat $4000/5 = 800$ örnek, her sınıftan $800/4 = 200$. Her turda 4 kat eğitim ($3200$ örnek), 1 kat test ($800$ örnek). Beş tur sonunda her kat bir kez test edilmiş olur; nihai başarı beş test sonucunun ortalamasıdır.

**Soru 2** (ekrandan, 01:05:00): BraTS veri setinde 349 hasta var ve her hastanın 155 kesitinden yaklaşık 100'ünde tümör maskesi bulunduğu varsayılıyor. Yalnız tümör içeren kesitlerle çalışılırsa kaç kesit değerlendirilir? Bu kesitler U-Net'e hangi biçimde verilir?

> **Çözüm (derste verildi):** $349 \times 100 = 34.900$ kesit. Her kesit için dört çekim yönteminin (FLAIR, T1, T1CE, T2) aynı numaralı kesiti dört kanal olarak üst üste konur (öğrencinin verdiği boyutla $256 \times 256 \times 4$); çıktı olarak aynı kesitin yer gerçeği maskesi verilir. Çok küçük (yaklaşık 25 pikselin altındaki) maskeler ayıklanır.

**Soru 3** (derste sözlü, 00:48:50): Cervix93'te her sınıftan yaklaşık 30 görüntü olduğu ve her görüntüden yaklaşık 20 hücre yaması çıkarılabildiği varsayılıyor. Sınıf başına kaç yama elde edilir ve bu sayı nasıl artırılır?

> **Çözüm (derste verildi):** $30 \times 20 = 600$ yama. Sayı veri artırmayla çoğaltılır: yamalar dört yöne döndürülür ve köşegen boyunca yansıtılır.

**Soru 4** (derste sözlü, 00:22:12): Bir MR bölütleme yönteminin iyi mi kötü mü olduğunu nasıl anlarız? Bunun için veri setinde ne bulunmalıdır?

> **Çözüm (derste verildi):** Veri setinde tümörün gerçek konumunu gösteren bir yer gerçeği (ground truth) maskesi bulunmalıdır. Yöntemin ürettiği bölütleme bu maskeyle üst üste konur; tümör alanına doğru düşen piksellerin yüzdesi, IoU ya da Dice ölçüsü hesaplanır. Yer gerçeği olmadan sayısal bir başarı ölçüsü elde edilemez; yalnız "tümör var/yok" etiketli bir sınıflandırma setiyle bölütleme değerlendirilemez.

**Soru 5** (ekrandan, 01:20:00): Dört sınıflı bir ağ tek bir görüntü için $[0{,}9647,\ 0{,}0058,\ 0{,}0191,\ 0{,}0104]$ çıktısını veriyor. Görüntü hangi sınıfa atanır, bu değerler neyi gösterir?

> **Çözüm (derste verildi):** En büyük değer birinci sınıfa (eozinofil) aittir, görüntü eozinofil olarak sınıflandırılır. Değerlerin toplamı 1,0000'dır (python ile kontrol edildi); bunlar softmax katmanının sınıf olasılıklarıdır.

## Dersin Toparlaması

Bu ders, dönem projelerinin ara durumunu gösteren sunumlardan oluştu ve hocanın geri bildirimleri birkaç ortak ilkede toplandı. Sınıflandırma projelerinde ağlar sıfırdan değil, ImageNet'te eğitilmiş ağırlıklarla transfer öğrenme ve ince ayarla kullanılmalı; VGG gibi eski ağlar yerine ResNet, Inception, Xception, DenseNet, DarkNet ve NASNet gibi ağlar denenip karşılaştırılmalıdır. Görüntünün tamamı tek bir sınıfa aitse ya da çekirdek konumları biliniyorsa sınıflandırma yamalar üzerinden yapılabilir; yamalar döndürme ve yansıtmayla çoğaltılmalıdır. Sonuçlar tek bir elle ayırmayla değil, K-katlı çapraz doğrulamayla ve katların ortalamasıyla raporlanmalıdır.

Bölütleme projelerinde temel ilke, sonucun yer gerçeğiyle karşılaştırılmasıdır: bu karşılaştırma IoU ve Dice gibi metriklerle sayısallaştırılır, bu yüzden piksel düzeyinde maske veren BraTS gibi kıyaslama setleri kullanılmalıdır. 3B MR hacimlerinde yalnız tümör içeren ve maskesi belli bir büyüklüğün üstündeki kesitler seçilmeli, aynı kesitin farklı çekim yöntemleri çok kanallı girdi olarak birleştirilmelidir. Başlangıç modeli olarak U-Net, ardından Double U-Net gibi gelişmiş yapılar ve derleme makalesindeki yeni yöntemler incelenecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
