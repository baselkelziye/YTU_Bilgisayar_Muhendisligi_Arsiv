# Ders 4 Genişletilmiş Notu: Proje İlerleme Sunumları: Graf Evrişim Ağları, Hücre Sınıflandırma, TransUNet ve Vision Transformer

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin biçimi
- 2. Graf evrişim ağları ile göğüs görüntüsü sınıflandırma
- 3. Histopatoloji görüntülerinde hücre tipi sınıflandırma
- 4. TransUNet ile çoklu organ bölütleme
- 5. Vision Transformer ile göğüs röntgeni sınıflandırma
- 6. Projeler için ortak yöntem önerileri
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin biçimi

Bu ders, dönem projelerinin ilerleme sunumlarına ayrıldı. Her proje sahibi ekranını paylaşarak o haftaki çalışmasını gösterdi, hoca da soru sorarak ve öneriler vererek projeyi yönlendirdi. Bu notta sunumların teknik içeriği ve hocanın yöntemsel önerileri yer alır. Dört proje konuşuldu: graf evrişim ağları (GCN) ile göğüs görüntüsü sınıflandırma, histopatoloji görüntülerinde hücre tipi sınıflandırma, TransUNet ile karın BT görüntülerinde çoklu organ bölütleme ve Vision Transformer (ViT) ile göğüs röntgeni sınıflandırma.

## 2. Graf evrişim ağları ile göğüs görüntüsü sınıflandırma

### 2.1 Tam bağlantılı katmandan graf katmanına

Sunum, sıradan bir tam bağlantılı sinir ağı katmanının matematiksel ifadesiyle başladı. Bir katmanın çıkışı, girdi öznitelik temsilinin ağırlıkla çarpılması, yanlılık (bias) eklenmesi ve sonucun bir aktivasyon fonksiyonundan geçirilmesiyle bulunur:

$$H^{(l+1)} = \sigma\left(W^{(l)} H^{(l)} + b^{(l)}\right)$$

Grafa geçildiğinde bu çarpıma bir de komşuluk (adjacency) matrisi $A$ girer. Yani graf sinir ağlarında öznitelik matrisi $H$ ve ağırlık matrisi $W$ ile birlikte $A$ da çarpıma katılır.

<!-- BELİRSİZ: Slayttaki formül küçük önizlemede okunamadı; formüller altyazıdaki anlatımdan kuruldu. -->

### 2.2 Komşuluk ve derece matrisleri

Bir grafın düğümleri 1, 2, 3, 4 diye numaralandırılmış olsun. Komşuluk matrisi, bu düğümlerin birbirine bağlı olup olmadığını tutar: $i$ ve $j$ düğümleri arasında bağlantı varsa $A_{ij} = 1$, yoksa $A_{ij} = 0$ olur.

Derece matrisi $D$ ise her düğümün kaç bağlantıya sahip olduğunu tutar. Köşegen bir matristir; $D_{ii}$, $i$ düğümünün derecesidir.

> **Ek bilgi (derste anlatılmadı):** Derece, komşuluk matrisinin satır toplamıdır: $D_{ii} = \sum_j A_{ij}$. Yaygın GCN tanımında her düğümün kendisiyle de bağlantılı sayılması için $\tilde{A} = A + I$ alınır ve $\tilde{D}$ bu matristen hesaplanır.

### 2.3 Normalleştirilmiş graf evrişimi

Taranan makalelerin hepsinde ortak olan kısım $D^{-1/2} A D^{-1/2}$ ifadesidir. Komşuluk matrisi derece matrisiyle iki taraftan çarpılarak normalleştirilir, ardından öznitelik matrisi ve ağırlıklarla çarpılır:

$$H^{(l+1)} = \sigma\left(D^{-1/2} A D^{-1/2} H^{(l)} W^{(l)}\right)$$

> **Ek bilgi (derste anlatılmadı):** Normalleştirme olmadan $A H$ çarpımı her düğümün komşularının özniteliklerini toplar; çok bağlantılı düğümlerde değerler büyür. $D^{-1/2} A D^{-1/2}$ bu toplamı düğüm derecelerine göre ölçekler. Bu biçim büyük olasılıkla Kipf ve Welling'in GCN çalışmasıyla yaygınlaşmıştır.

### 2.4 Graf kurma yaklaşımları ve GCN türleri

Çalışmalar grafı farklı yollarla kullanmış. Bazıları belirli bir graf bağlantısını baştan kurup sonra bu bağlantıları ağırlıklandırarak ağ oluşturmuş. Bazıları ise düğümler arasındaki bağlantıların kendisini öğrenmeye yönelik eğitim yöntemleri geliştirmiş.

Evrişimli sinir ağlarıyla birlikte kullanılan graf evrişim ağları iki alt grupta incelenir (ekrandan, 00:05:00):

- Spektral yöntemler (Spectral Methods)
- Uzamsal yöntemler (Spatial Methods)

Taranan literatürde çoğunlukla spektral yöntemler kullanılmış.

### 2.5 Görüntü verisinde graf öğrenmesi

Görüntü çalışmalarında yaygın akış şudur: önce ResNet gibi bir CNN ile öznitelikler çıkarılır, sonra bu öznitelikler graf düğümleri olarak kullanılır ve graf öğrenmesi bunların üzerinde uygulanır. Sunumda, spektral bir yöntem seçilirse spektral yapının farklı özniteliklerden oluşan bir matristen elde edilebileceği fikri de dile getirildi; bu, araştırılacak bir yön olarak kaldı.

Projeye yakın bir çalışma olarak Papers with Code'da bulunan çok etiketli görüntü tanıma (multi-label image recognition) makalesi gösterildi. Bu çalışmada COCO gibi nesne tanıma veri setleri kullanılmış. Hoca, çok etiketli problemde bir görüntüde birden çok nesne (ör. tenis topu, oyuncu, ağaç, kar) bulunduğunu, projede ise tek etiketli bir problem olduğunu hatırlattı. Projedeki veri setinde dört sınıf var (ör. zatürre için negatif, tipik görünüm gibi sınıflar).

Makalenin kodu oldukça düzenli hazırlanmış: bir graf evrişim sınıfı (`GraphConvolution`) tanımlanmış, altında evrişim katmanı ve toplu normalleştirme (batch normalization) gibi katmanlarla bir ResNet omurgası kullanılmış, ardından komşuluk matrisleri oluşturulmuş. Plan, önce bu kodu doğrudan kendi veriyle çalıştırıp sonuç almak, sonra yöntemi daha derin inceleyip değiştirilebilecek yerleri belirlemektir. Hoca da kodların Papers with Code ve GitHub gibi kaynaklardan aranmasını, bulunan kodla denemeye başlanmasını önerdi.

## 3. Histopatoloji görüntülerinde hücre tipi sınıflandırma

### 3.1 Veri seti

İkinci projede veri seti, doku kesiti (histopatoloji) görüntülerinden oluşuyor (ekrandan, 00:10:00). Her görüntüde çok sayıda hücre var; örneğin bir görüntüde 500'e yakın hücre bulunuyor. Her hücre için bir sınırlayıcı kutu (bounding box), bu kutunun boyutları ve hücrenin merkezi (centroid) veriliyor. Görüntüler farklı kaynak veri setlerinden toplanmış. Ayrıştırılacak 6 farklı hücre tipi var. Toplamda yaklaşık 50 bin hücre örneği bulunuyor, her hücre yaması yaklaşık 64x64 piksel.

### 3.2 SVM denemesi ve uzamsal öznitelikler

Deneme olarak SVM kullanıldı. Tek bir görüntüde %95'e yakın başarı alındı, ama tüm veri setiyle yaklaşık %50'ye düştü. SVM'e her hücrenin merkezi etrafında veri setinde hazır verilen bir filtrenin çıktısı veriliyordu.

Hoca burada SVM'in girdisini sorguladı: SVM bir vektör alır ve yalnız merkez noktası ya da tek bir filtrenin çıktısı hücre tiplerini ayırmaya yetecek kadar ayrıştırıcı değildir. Klasik makine öğrenmesi yöntemleriyle çalışılacaksa her 64x64 yamadan ayrıştırıcı uzamsal öznitelikler çıkarılmalıdır. Hoca örnek olarak SIFT, SURF ve HOG'u saydı; bu yöntemlerle elde edilen yeni vektör SVM'e ya da rastgele ormana (random forest) verilebilir.

<!-- BELİRSİZ: Hocanın saydığı yöntemlerden biri altyazıda "STFA" diye geçiyor; hangi yöntem olduğu anlaşılamadı. -->

CNN'ler bu öznitelikleri otomatik çıkardığı için hoca yamaların doğrudan CNN'e verilmesini önerdi.

### 3.3 CNN'e ne verilir?

**Soru:** Sınırlayıcı kutuların koordinatları biliniyor; CNN'e koordinatlar mı verilecek? **Cevap:** Hayır. CNN'e girdi olarak görüntü verilir; koordinatlarla belirlenen 64x64'lük yama CNN'e verilir.

Hoca ayrıca yamanın, kullanılan önceden eğitilmiş modelin özgün girdi boyutuna (ör. 224x224) yeniden boyutlandırılabileceğini söyledi. Gerekçesi: CNN'ler ardışık filtreler kullanır. 64x64 gibi küçük bir girdi verilirse arka arkaya gelen filtreler anlamlı öznitelikler çıkaramayabilir. Filtrelerin anlamlı sonuç vermesi için modelin beklediği boyutta girdiyle çalışmak daha iyidir.

### 3.4 Yarı denetimli öğrenme için deney tasarımı

Bu proje yarı denetimli (semi-supervised) öğrenme üzerine kurulu. Hoca, önce transfer öğrenme yöntemleriyle hangi başarının elde edildiğinin görülmesini, sonra yarı denetimli yöntemle bu başarıya ne kadar yaklaşılabildiğine bakılmasını istedi. Transfer öğrenme için ResNet, DenseNet, Inception ve EfficientNet gibi dört modelin sonuçlarının karşılaştırılması önerildi.

Yarı denetimli yöntemlerde eğitim kümesinin büyük olması gerekmez; önemli olan sınıfları temsil edebilecek etiketli örneklerdir. 6 sınıf için hocanın önerdiği deney dizisi:

| Sınıf başına etiketli örnek | Toplam etiketli örnek |
|---|---|
| 1 | $1 \times 6 = 6$ |
| 2 | $2 \times 6 = 12$ |
| 3 | $3 \times 6 = 18$ |
| 5 | $5 \times 6 = 30$ |
| 10 | $10 \times 6 = 60$ |
| 20 | $20 \times 6 = 120$ |

Her satırda sınıflandırma sonucuna bakılarak etiketli örnek sayısı arttıkça başarının nasıl değiştiği izlenir.

Veri eğitim ve test olarak önceden ayrılmamışsa K-katlı çapraz doğrulama kullanılır: $K = 5$ seçilir, verinin $4/5$'iyle eğitilir, $1/5$'iyle test edilir (bkz. Bölüm 6.2).

## 4. TransUNet ile çoklu organ bölütleme

### 4.1 Model ve kod

Üçüncü proje, ileride üretici çekişmeli ağ (GAN) eklenecek bir bölütleme çalışması. Önce standart bir TransUNet ile çalışılması, sonra GAN eklenmesi kararlaştırılmış. Sunumda TransUNet'in kodu ve makalesi gösterildi: "TransUNet: Transformers Make Strong Encoders for Medical Image Segmentation" (ekrandan, 00:15:00). Model, kodlayıcı tarafında Vision Transformer kullanır.

### 4.2 Synapse veri seti

Kullanılan veri seti Synapse. Üç boyutlu BT hacimlerinden oluşur; her kesit 512x512 pikseldir. Sunumda bir hacimde 198 kesit olduğu belirtildi. Veri setinde voxel aralığı (voxel spacing) bilgisi de var. Hoca bunun pikseller arasındaki mesafe olduğunu, üçüncü değer de verilmişse kesitler arasındaki mesafeyi gösterdiğini açıkladı. Veri üç boyutlu olduğu için bu değerler hacmin gerçek boyutlarını verir.

Denemede veri setinden üç hacim seçildi: ikisi eğitim, biri test için. Yama boyutu 16 alındı. Eğitim uzun sürdüğü için epoch sayısı ve toplu iş boyutu (batch size) küçültüldü.

### 4.3 Sonuç ve tartışma

Gösterilen sonuçta üç görüntü vardı: özgün BT kesiti, gerçek etiket (ground truth) ve tahmin (ekrandan, 00:20:00). Gerçek etikette karaciğer ve diğer organlar farklı renklerle gösteriliyordu; tahminde ise yalnız karaciğer bulunmuştu. Veri setinde toplam 9 sınıf olduğu belirtildi.

Hoca şu noktaya dikkat çekti: basit bir bölütlemede bir yapının var olup olmadığına bakılır ve çıktı 0/1 maskesidir. Burada ise organlar 0'dan 8'e kadar farklı etiketlerle işaretleniyorsa yöntem yalnız bölütleme değil, aynı zamanda sınıflandırma da öğreniyor demektir. Model yalnız karaciğeri bulduysa ya kod yanlış çalıştırılmış ya da sınıf sayısı ayarı yanlış yorumlanmış olabilir. Aynı veri setini kullanan çalışmaların organları hep birlikte bulduğu görülmüş; bu da çalıştırmada bir hata olabileceğini düşündürüyor.

> **Ek bilgi (derste anlatılmadı):** TransUNet'in Synapse deneylerinde büyük olasılıkla 8 karın organı (aort, safra kesesi, dalak, sol ve sağ böbrek, karaciğer, pankreas, mide) bölütlenir; arka plan da bir sınıf sayıldığı için sınıf sayısı 9 olur. Yani 9, tek bir organın değil toplam sınıf sayısının değeridir.

Hoca, bölütleme başarısının tahmin edilen bölütün gerçek etiketle ne kadar örtüştüğüne bakılarak ölçüldüğünü hatırlattı. Bunun için kesişim / birleşim (Intersection over Union, IoU) ölçütü kullanılır:

$$\text{IoU} = \frac{|P \cap G|}{|P \cup G|}$$

Burada $P$ tahmin edilen bölge, $G$ gerçek etiket bölgesidir (ara adım eklendi).

> **Ders sonrası not:** Hoca ölçütün adını "Intersection of Union" diye söyledi; doğrusu "Intersection over Union"dır.

Hocanın önerileri:

- Bu veri setiyle yapılmış çalışmalar Google Scholar'da taranmalı; çalışmaların organları ayrı ayrı mı, hepsini birlikte mi bulduğu incelenmeli.
- Problem çok karmaşık gelirse daha basit bölütleme içeren başka veri setlerine bakılabilir.
- Bir alternatif, tek organa (karaciğer) odaklanmak ve aynı kodu farklı organlar için ayrı ayrı çalıştırmaktır. Tek organla GAN eklemek de daha kolay olabilir.

> **Hocanın vurgusu:** Tek bir makale okumak yerine aynı veri setini kullanan makaleler birlikte gözden geçirilmeli; "burada bunu yapmış, burada şunu yapmış" diye bakıldığında işin doğası anlaşılmaya başlar.

## 5. Vision Transformer ile göğüs röntgeni sınıflandırma

### 5.1 Deneme

Dördüncü projede göğüs röntgenlerinde normal / anomali (zatürre) sınıflandırması yapılıyor. Kendi bilgisayarında eğitim yavaş olduğu için Kaggle'daki GPU'lar kullanılmış. Önceden eğitilmiş ViT-B/16 modeli kullanıldı. Daha önce sıfırdan yazılan bir CNN ile çalışılmış, ama önceden eğitilmiş olmadığı için başarısı düşük kalmış.

Eğitim verisinde 1341 normal ve 3875 anomali görüntüsü var; veri setinin tamamında 5863 görüntü olduğu belirtildi. Test için yalnız 16 görüntü verildi (8 normal, 8 anomali); bunlardan bir normal görüntü anomali diye sınıflandırıldı.

> **Ders sonrası not:** $1341 + 3875 = 5216$ eder; bu, büyük olasılıkla Kaggle'daki göğüs röntgeni veri setinin eğitim bölümüdür. Aynı veri setinde büyük olasılıkla 624 test ve 16 doğrulama görüntüsü daha vardır. Ekranda görülen 8 normal görüntüsü doğrulama klasöründendi (ekrandan, 00:30:00); yani denemede kullanılan 16 görüntü büyük olasılıkla bu doğrulama kümesidir.

Hoca test kümesinin çok küçük olduğunu, bu haliyle yüzde başarı vermenin anlamlı olmadığını söyledi. Göğüs röntgeniyle ilgili çok sayıda ve çok daha büyük veri seti olduğunu, bunların da kullanılmasını, test kümesinin büyütülmesini istedi.

### 5.2 Karşılaştırma için modeller

Hoca, ViT dışında transfer öğrenme modellerinin de çalıştırılmasını istedi: ResNet, DenseNet, Inception ve EfficientNet. AlexNet gibi eski mimarilere gerek olmadığını, daha çok bağlantılı gelişmiş mimarilerin seçilmesi gerektiğini belirtti.

Farklı ViT yaklaşımları birlikte tarandı. Keras'taki ViT sınıflandırma örneğinden ve Papers with Code'dan başlanarak şu türevler konuşuldu:

- CrossViT
- IEViT (Input Enhanced Vision Transformer)
- SepViT
- VATT (öz denetimli, self-supervised öğrenme yapan bir yaklaşım)
- MobileViT
- Pale Transformer
- DeiT III

### 5.3 IEViT makalesindeki model tablosu

Hoca IEViT makalesini açıp model boyutlarını veren tabloyu gösterdi (ekrandan, 00:35:00):

| Model | Yama ($P \times P$) | Katman ($L$) | Gizli boyut ($D$) | MLP boyutu | Başlık sayısı | Parametre |
|---|---|---|---|---|---|---|
| ViT-B/16 | 16x16 | 12 | 768 | 3072 | 12 | 85.8M |
| ViT-B/32 | 32x32 | 12 | 768 | 3072 | 12 | 87.4M |
| ViT-L/16 | 16x16 | 24 | 1024 | 4096 | 16 | 303.3M |
| ViT-L/32 | 32x32 | 24 | 1024 | 4096 | 16 | 305.5M |
| IEViT-B/16 | 16x16 | 12 | 768 | 3072 | 12 | 90.8M |
| IEViT-B/32 | 32x32 | 12 | 768 | 3072 | 12 | 92.4M |
| IEViT-L/16 | 16x16 | 24 | 1024 | 4096 | 16 | 309.9M |
| IEViT-L/32 | 32x32 | 24 | 1024 | 4096 | 16 | 312.1M |

<!-- BELİRSİZ: Karede son üç sütunun başlıkları görünmüyor; "MLP boyutu" ve "Başlık sayısı" adları standart ViT tablosuna göre verildi. -->

Aynı sayfada IEViT'in fikri de görülüyordu: yöntem ResNet'teki atlamalı bağlantıdan (girdinin her evrişim bloğunun çıkışına eklenmesi) esinlenir. ViT ağına paralel bir evrişim bloğu tasarlanır; bu blok bütün girdi görüntüsünü alıp bir temsil üretir ve bu temsil her Transformer kodlayıcı katmanının çıkışına tekrar tekrar eklenir (ekrandan, 00:35:00).

> **Ek bilgi (derste anlatılmadı):** ViT-B/16'da 224x224 görüntü 16x16'lık yamalara bölündüğünde $(224/16)^2 = 196$ yama oluşur; bunlar $D = 768$ boyutlu vektörlere gömülür ve sınıf belirteciyle birlikte Transformer kodlayıcıya dizi olarak verilir. Yama boyutu büyüdükçe (B/32) dizi kısalır ve hesap yükü azalır.

### 5.4 Görüntü işleme filtreleri hakkında soru

**Soru:** Görüntülere çeşitli görüntü işleme filtreleri uygulayıp öyle eğitmek bir yenilik olabilir mi? **Cevap:** Buna gerek yok; Vision Transformer'ların bu tür dönüşümleri kendilerinin öğrenmesi beklenir.

**Soru:** ViT modeli TensorFlow ile sıfırdan mı kurulmalı, yoksa önceden eğitilmiş model kullanılmaya devam mı edilmeli? **Cevap:** Veri setini hazır modele verip sonucu almak çok doğrudan bir yaklaşımdır ve yalnız bir temel çizgi (base) olur. Önce standart transfer öğrenme yöntemleri K-katlı çapraz doğrulamayla uygulanmalı, sonra farklı ViT yaklaşımları karşılaştırılmalıdır. Tek bir kodla çalışmak yeterli değildir; içeriği zenginleştirmek gerekir.

> **Hocanın vurgusu:** Hedef, farklı Vision Transformer yaklaşımlarını uyarlayıp sonunda karşılaştırmalı bir tablo çıkarmaktır. Transfer öğrenme sonuçlarını ViT'lerle aşıp aşamadığımız sorusunu cevaplayan bir makale yazmak daha değerlidir.

## 6. Projeler için ortak yöntem önerileri

### 6.1 Temel çizgi olarak transfer öğrenme

Hocanın bütün projelere verdiği ortak öneri, önce önceden eğitilmiş CNN'lerle (ResNet, DenseNet, Inception, EfficientNet) transfer öğrenme sonuçlarının alınmasıdır. Bu sonuçlar, geliştirilen yöntemin (graf ağı, yarı denetimli öğrenme, ViT, GAN) gerçekten bir katkı sağlayıp sağlamadığını göstermek için karşılaştırma ölçütü olur.

### 6.2 K-katlı çapraz doğrulama

Veri seti eğitim ve test olarak ayrılmamışsa K-katlı çapraz doğrulama kullanılır. $K = 5$ seçildiğinde veri beş eşit parçaya bölünür. Her turda dört parça ($4/5$) eğitim, bir parça ($1/5$) test için kullanılır. Test parçası her turda değişir; beş turun sonuçlarının ortalaması alınarak nihai başarı bulunur. Vision Transformer'larda da sınıflandırma için aynı değerlendirme düzeni kullanılır.

### 6.3 Hazır kodun yeri

Hazır kodu bulup çalıştırmak bir başlangıçtır, sonuç değildir. Bir yayının sonuçlarını aynı veriyle tekrarlamak yalnız bir temel çizgi sağlar. Asıl beklenen, yöntemsel bir yenilik eklemek ve bunu karşılaştırmalı deneylerle göstermektir.

> **Hocanın vurgusu:** Dönem sonuna doğru ince ayar (fine tuning) ve yazım işleri yoğunlaşır; deneylerin bundan önce ilerletilmesi gerekir.

## Örnek Sorular

**1. (derste sözlü, 00:09:04)** SVM ile hücre sınıflandırırken SVM'e girdi olarak ne verilmelidir? Yalnız hücre merkezinin koordinatı yeterli midir?

> **Cevap (derste verildi):** Yeterli değildir. SVM bir öznitelik vektörü alır; merkez koordinatı hücre tipini ayırt etmez. Yamadan SIFT, SURF, HOG gibi ayrıştırıcı uzamsal öznitelikler çıkarılıp vektör olarak verilmelidir. CNN kullanılıyorsa yamanın kendisi verilir.

**2. (derste sözlü, 00:13:20)** Bir CNN'e hücrenin sınırlayıcı kutu koordinatları mı, yoksa kutunun içindeki görüntü mü verilir? 64x64 yama doğrudan verilebilir mi?

> **Cevap (derste verildi):** CNN'e kutunun içindeki görüntü yaması verilir. Yama, modelin özgün girdi boyutuna (ör. 224x224) yeniden boyutlandırılabilir; küçük girdide ardışık filtreler anlamlı öznitelik çıkaramayabilir.

**3. (derste sözlü, 00:11:59)** 6 sınıflı bir problemde yarı denetimli öğrenme deneyi sınıf başına 1, 2, 3, 5, 10 ve 20 etiketli örnekle yapılırsa her deneyde toplam kaç etiketli örnek kullanılır?

> **Cevap (derste verildi):** $6k$: sırasıyla 6, 12, 18, 30, 60 ve 120 örnek.

**4. (derste sözlü, 00:20:38)** Çok organlı bir bölütleme veri setinde maske değerleri 0'dan 8'e kadar gidiyorsa bu, basit (ikili) bölütlemeden nasıl ayrılır? Başarı nasıl ölçülür?

> **Cevap (derste verildi):** İkili bölütlemede maske 0/1'dir. 0-8 arası etiketler her pikselin bir organ sınıfına atandığını, yani bölütlemeyle birlikte sınıflandırma da yapıldığını gösterir. Başarı tahmin ile gerçek etiketin örtüşmesiyle, IoU ölçütüyle ölçülür.

**5. (derste sözlü, 00:31:35)** Veri seti eğitim ve test olarak ayrılmamışsa 5 katlı çapraz doğrulama nasıl uygulanır?

> **Cevap (derste verildi):** Veri beş parçaya bölünür; her turda $4/5$ ile eğitilir, $1/5$ ile test edilir, test parçası her turda değişir ve beş sonucun ortalaması alınır.

## Dersin Toparlaması

Bu derste dört dönem projesinin ilerlemesi üzerinden biyomedikal görüntü analizinde güncel derin öğrenme yöntemleri tartışıldı. Graf evrişim ağlarında komşuluk ve derece matrisleri, $D^{-1/2} A D^{-1/2}$ normalleştirmesi ve spektral/uzamsal yöntem ayrımı ele alındı. Hücre sınıflandırmasında klasik öğrenme için uzamsal öznitelik çıkarmanın gerekliliği, CNN'e yama verme ve yamayı yeniden boyutlandırma, yarı denetimli öğrenmede sınıf başına az örnekle deney tasarımı konuşuldu. TransUNet ve Synapse veri setiyle çok sınıflı bölütlemede etiketlerin anlamı ve IoU ile değerlendirme tartışıldı. Göğüs röntgeni projesinde ViT-B/16 ile başlayıp CNN transfer öğrenmesi ve IEViT gibi ViT türevleriyle karşılaştırma yapılması önerildi.

Bütün projeler için ortak mesaj şuydu: önce transfer öğrenmeyle güvenilir bir temel çizgi kurulmalı, K-katlı çapraz doğrulamayla değerlendirilmeli, sonra önerilen yöntemin bu temel çizgiyi aşıp aşmadığı karşılaştırmalı bir tabloyla gösterilmelidir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
