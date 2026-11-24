# Ders 2 Çalışma Özeti

## Genel Konular

- Dersin biçimi: proje ilerleme sunumları
  - Öğrenciler dönem projeleri için seçtikleri tıbbi görüntü veri setlerini ve inceledikleri yöntemleri sundu; hoca her sunumdan sonra yöntem ve veri seti önerileri verdi.
  - Ortak çerçeve: önce standart transfer öğrenmesiyle bir temel (baseline) sonuç alınır, ardından güncel bir derin öğrenme yöntemiyle yöntemsel yenilik aranır ve iki sonuç karşılaştırılır.
- Vision Transformer (ViT) ile göğüs röntgeni sınıflandırması
  - ViT, doğal dil işlemede kullanılan Transformer yapısının görüntüye uyarlanmış hâlidir. Görüntü sabit boyutlu yamalara (patch) bölünür, yamalar sıralı bir dizi olarak kodlayıcıya verilir.
  - ViT yalnız nesne bulmada değil, görüntünün bütününü "hastalıklı / hastalıksız" gibi sınıflara ayırmada da kullanılır (ekrandan, 00:05:00).
  - Karşılaştırma için DenseNet, ResNet, Inception gibi transfer öğrenmesi mimarileri kullanılır.
- Göğüs röntgeni veri setleri
  - RSNA yarışma verisi: dört sınıf (negatif, tipik COVID-19 görünümü, belirsiz görünüm, atipik görünüm) ve akciğerdeki opasite bölgelerini gösteren sınırlayıcı kutular (bounding box). Görüntüler DICOM biçimindedir, veri yaklaşık 128 GB'tır.
  - Diğer setler (ekrandan, 00:10:00): Pneumonia (RSNA zatürre yarışması), VinBigData Chest X-ray Abnormalities Detection (13 sınıf, akciğer başlangıç ve bitiş piksel koordinatları), Chest14, PadChest (PA ve lateral görüntüler birlikte).
  - Yarışmada birinci olan çalışma akciğer loblarını YOLO ile tespit edip çevredeki gereksiz bölgeleri elemiştir; hoca projede önce yalnız sınıflandırmaya odaklanılmasını istedi.
- Graph Learning
  - Graf, varlıklar (köşe, vertex) ve aralarındaki ilişkiler (kenar, edge) kümeleriyle tanımlanır (ekrandan, 00:15:00).
  - Uygulama örnekleri: proteinler arası etkileşim grafıyla tedavi keşfi, şehir trafiğinde bölge ve zaman yoğunluk ilişkilerinden tahmin.
  - Graflar üzerinde makine öğrenmesi görevleri: düğüm sınıflandırma (node classification), bağlantı tahmini (link prediction), topluluk tespiti (community detection), kümeleme ve regresyon.
- BRACS meme kanseri histopatoloji veri seti ve manifold öğrenme
  - BRACS: 547 etiketli tam slayt görüntüsü (WSI), 4539 etiketli ilgi bölgesi (ROI), 189 hasta (ekrandan, 00:20:00).
  - Üç ana sınıf (iyi huylu, atipik, kötü huylu tümör) ve yedi alt sınıf: Normal, Pathological Benign, Usual Ductal Hyperplasia, Flat Epithelial Atypia, Atypical Ductal Hyperplasia, Ductal Carcinoma In Situ, Invasive Carcinoma. Böylece hem 3 sınıflı hem 7 sınıflı sınıflandırma yapılabilir.
  - Manifold öğrenme (Isomap, Laplacian Eigenmaps vb.) boyut indirgeme ve öznitelik çıkarma için kullanılabilir; elde edilen temsiller sınıflandırıcıya ya da otokodlayıcıya (autoencoder) verilip başarımları karşılaştırılır. Alternatif: Deep Ensemble Learning; dokuya dayalı fikir olarak "Learning Texture Manifolds" çalışması.
- Servikal hücre segmentasyonu ve GAN
  - İncelenen çalışmada servikal hücrelerde üst üste binen hücreleri ayırmak için GAN tabanlı segmentasyon kullanılmış; yöntem "Generation" ve "Discrimination" aşamalarından oluşuyor.
  - Bir başka veri seti: miyokard patolojisi segmentasyonu (çok dizili kardiyak MR, 256x256 boyutlu görüntüler, iki aşamalı derin öğrenme) (ekrandan, 00:30:00).
  - Hoca segmentasyon için PanNuke, Warwick veri setleri ve kolorektal çekirdek segmentasyonu verisini önerdi.
- Kolorektal kanser histopatolojisi ve patching
  - Kolorektal kanser (kalın bağırsak, kolon ve rektum kanseri) görüntülerinde sınıflandırma, self-supervised öğrenme ve segmentasyon en sık kullanılan yaklaşımlardır; Vision Transformer ve Graph Learning daha az kullanılır.
  - Klasik makine öğrenmesinde (SVM, Naive Bayes) önce öznitelik çıkarılır; CNN'de öznitelik çıkarma konvolüsyon katmanlarında, ağın içinde yapılır.
  - Patching: büyük görüntüden 224x224 parçalar örtüşmeli kaydırmayla kesilir (örneğin 112 piksel adım); bu hem ağın giriş boyutuna uyar hem veriyi artırır (ekrandan, 00:40:00).
  - Güncel yöntem seçenekleri: self-supervised, weakly supervised, few-shot learning, Bayesian deep learning, Graph Learning, Vision Transformer.
- Derin metrik öğrenme
  - Mesafe metriği üzerinde benzer örnekleri yakınlaştırıp farklıları uzaklaştıran yöntemler; PyTorch'ta pytorch-metric-learning kütüphanesiyle uygulanır (ekrandan, 00:50:00).
- Semantik segmentasyon karşılaştırma yöntemleri
  - DeepLab v3, SegNet, U-Net ve sürümleri (TransUNet, Swin-UNet, UNet++); ayrıca panoptik segmentasyon.
- Lizard ve diğer histopatoloji veri setleri
  - Gösterilen setler (ekrandan, 01:05:00): GlaS, CRAG, ConSeP, PanNuke, TCGA, DigestPath.
  - Lizard: altı sınıf etiketli, hem sınıflandırma hem segmentasyon için kullanılabilir; etiketler otomatik ve yarı otomatik yöntemlerle üretilmiştir.
  - Yarı denetimli (semi-supervised) öğrenmede verinin bir kısmının etiketi kullanılmaz; değerlendirme K-katlı çapraz doğrulama (5 katta 4 eğitim, 1 test) ile yapılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Transfer öğrenmesi yöntem değil, karşılaştırma basamağıdır
  - Transfer öğrenmesi birkaç satır kodla uygulanabilen standart bir araçtır; projede asıl beklenen güncel bir yöntemle yöntemsel yeniliktir.
  - Sonuçlar "transfer öğrenmesine göre artıyor mu, azalıyor mu" diye karşılaştırılır.
- Derin yöntemlerde ayrı öznitelik çıkarma gerekmez
  - Klasik sınıflandırıcıya giderseniz ayrıca öznitelik çıkarma yöntemleri çalışmanız gerekir; derin yöntemlerde bu adım ağın içindedir.
- Alt görüntü boyutu önemlidir
  - Ağlar genelde 224x224 giriş alır; görüntü yeniden boyutlandırılır ya da kaydırmalı yamalara bölünür. Bir piksel kaydırmanın anlamı yoktur, makul bir örtüşme seçilir.
- Literatür kaydı
  - İncelenen çalışmalar bir referans dosyasında (BibTeX) toplanmalı; giriş bölümü için 20-25 kaynak gerekir ve LaTeX'te yazarken işe yarar.

## Kısa Tekrar Notları

- ViT: görüntü → sabit yamalar → düzleştirme → doğrusal gömme + konum gömmesi → Transformer kodlayıcı → MLP başlığı → sınıf.
- Transfer öğrenmesi mimarileri: AlexNet, VGG, DenseNet, ResNet, Inception.
- Graf = köşeler (varlıklar) + kenarlar (ilişkiler); görevler: düğüm sınıflandırma, bağlantı tahmini, topluluk tespiti.
- BRACS: 3 ana, 7 alt sınıf; 547 WSI, 4539 ROI, 189 hasta.
- Patching: 224x224 yama, örtüşmeli kaydırma (ör. 112 adım), veri artırma etkisi.
- Segmentasyon karşılaştırması: SegNet, U-Net, UNet++, TransUNet, Swin-UNet, DeepLab v3, panoptik segmentasyon.
- Yarı denetimli öğrenme: etiketlerin bir kısmı kullanılmaz; 5 katlı çapraz doğrulama ile ortalama başarım raporlanır.
- Panoptik segmentasyon ile "panoramik segmentasyon" aynı şey değildir.

## Detaylı Açıklamalar

- Vision Transformer mimarisi (ekrandan, 00:05:00)
  - Ekranda gösterilen adımlar: (1) görüntü sabit boyutlu yamalara bölünür, (2) yamalar düzleştirilir, (3) düzleştirilmiş yamalardan daha düşük boyutlu doğrusal gömmeler üretilir, (4) konum gömmeleri eklenir, (5) dizi Transformer kodlayıcıya verilir, (6) model büyük bir veri setinde görüntü etiketleriyle ön eğitilir, (7) hedef veri seti için ince ayar yapılır.
  - Kodlayıcı bloğu: Norm → Multi-Head Attention → artık bağlantı (+) → Norm → MLP → artık bağlantı (+), bu blok L kez tekrarlanır. Dizinin başına ek, öğrenilebilir bir sınıf gömmesi (class token) eklenir ve sınıf kararı MLP başlığından alınır.
  - Hoca, göğüs röntgeni için "Enhanced Vision Transformer Architecture for Chest X-Ray Image Classification" gibi çalışmaları örnek gösterdi; ViT tabanlı sınıflandırıcının sonuçları DenseNet, ResNet, Inception gibi transfer öğrenmesi yapılarıyla karşılaştırılacak.
- Klasik öğrenme ile CNN farkı
  - Standart sınıflandırıcılarda (SVM, Naive Bayes) önce öznitelik çıkarma adımı uygulanır, sonra öznitelikler sınıflandırıcıya verilir.
  - Konvolüsyonel ağlarda iki boyutlu görüntünün kendisi verilir; öznitelik çıkarma çeşitli filtrelerle konvolüsyon katmanlarında yapılır, ardından sınıflandırılır.
  - Transfer öğrenmesi mimarileri, CNN'in farklı katman düzenleriyle kurulmuş adlandırılmış hâlleridir (AlexNet, VGG, DenseNet, ResNet, Inception).
- Patching yöntemi (ekrandan, 00:40:00)
  - Görüntü ağın giriş boyutundan büyükse ya yeniden boyutlandırılır ya da içinden 224x224'lük parçalar kesilir.
  - İlk parça kesildikten sonra pencere belli bir örtüşmeyle kaydırılır (örneğin 224'lük pencere için 112 piksel), satır bitince aşağı kaydırılarak devam edilir. Böylece hem giriş boyutu sağlanır hem eğitim verisi çoğalır.
- Segmentasyon ve yarı denetimli öğrenme
  - Segmentasyon çalışanlar için temel karşılaştırma ailesi SegNet ve onun geliştirilmiş hâli U-Net ile U-Net türevleridir; panoptik segmentasyon da karşılaştırmaya eklenebilir.
  - Etiketli bir veri setinde yarı denetimli yöntemleri sınamak için verinin bir kısmının etiketi kullanılmaz. Eğitim ve test ayrımı hazır değilse K-katlı çapraz doğrulama kullanılır ve katların ortalaması sonuç olarak verilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
