# Ders 4 Çalışma Özeti

## Genel Konular

- Ders, dönem projelerinin ilerleme sunumları biçiminde yürütüldü
  - Öğrenciler kendi projelerindeki son durumu ekran paylaşarak anlattı; hoca her projeye yöntem ve deney tasarımı açısından yön verdi.
  - Dört proje konuşuldu: graf evrişim ağlarıyla göğüs görüntüsü sınıflandırma, histopatoloji görüntülerinde hücre tipi sınıflandırma, TransUNet ile çoklu organ bölütleme ve Vision Transformer ile göğüs röntgeni sınıflandırma.
- Graf evrişim ağları (GCN)
  - Bir graf, düğümler ve aralarındaki bağlantılarla tanımlanır. Komşuluk (adjacency) matrisi $A$'da iki düğüm arasında bağlantı varsa ilgili eleman 1, yoksa 0'dır.
  - Derece matrisi $D$ köşegen bir matristir; her düğümün kaç bağlantısı olduğunu tutar.
  - Tam bağlantılı bir katman $H^{(l+1)} = \sigma(W^{(l)} H^{(l)} + b)$ biçimindedir; graf katmanında bu çarpıma komşuluk matrisi de girer.
  - Makalelerde ortak kullanılan normalleştirme $D^{-1/2} A D^{-1/2}$'dir. Normalleştirilmiş komşuluk matrisi öznitelik matrisi ve ağırlıklarla çarpılır: $H^{(l+1)} = \sigma(D^{-1/2} A D^{-1/2} H^{(l)} W^{(l)})$.
  - GCN yöntemleri iki ana gruba ayrılır: spektral (spectral) yöntemler ve uzamsal (spatial) yöntemler (ekrandan, 00:05:00). Taranan çalışmalarda çoğunlukla spektral yöntemler kullanılmış.
  - Bazı çalışmalar sabit bir graf kurup bağlantıları ağırlıklandırır, bazıları grafın bağlantılarının kendisini öğrenir.
  - Görüntü verisinde yaygın yol: önce ResNet gibi bir CNN ile öznitelik çıkarmak, sonra bu öznitelikleri graf düğümleri olarak kullanıp graf öğrenmesi uygulamak.
  - Çok etiketli görüntü tanıma (multi-label image recognition) için GCN kullanan bir çalışma örnek gösterildi; projedeki veri setinde ise dört sınıflı tek etiketli bir problem var.
- Hücre tipi sınıflandırma (histopatoloji)
  - Veri setinde her görüntüde yüzlerce hücre için sınırlayıcı kutu (bounding box), boyut ve merkez (centroid) bilgisi var; 6 hücre tipi ayrıştırılacak. Toplam yaklaşık 50 bin hücre yaması (patch) var; yamalar yaklaşık 64x64.
  - Merkez noktalarına uygulanmış filtre çıktılarıyla SVM denemesi tek görüntüde yüksek, tüm veri setinde yaklaşık %50 doğruluk verdi.
  - Klasik makine öğrenmesinde ayrıştırıcı uzamsal öznitelik çıkarmak gerekir: SIFT, SURF, HOG gibi yöntemlerle her yamadan vektör çıkarılıp SVM ya da rastgele ormana (random forest) verilebilir.
  - CNN bu öznitelikleri kendisi öğrendiği için yamaları doğrudan CNN'e vermek daha uygundur.
- TransUNet ile çoklu organ bölütleme
  - TransUNet, Transformer kodlayıcıyı U-Net yapısıyla birleştiren bir tıbbi görüntü bölütleme modelidir (ekrandan, 00:15:00).
  - Synapse veri seti üç boyutlu BT (CT) hacimlerinden oluşur; kesitler 512x512 pikseldir. Voxel aralığı bilgisi, pikseller arası mesafeyi ve kesitler arası mesafeyi verir.
  - Hazır kodla (yama boyutu 16) yapılan denemede tahmin yalnız karaciğeri buldu; gerçek etiket (ground truth) ise birden çok organı farklı renklerle gösteriyordu (ekrandan, 00:20:00).
- Vision Transformer (ViT) ile göğüs röntgeni sınıflandırma
  - Önceden eğitilmiş ViT-B/16 ile normal / anomali (zatürre) sınıflandırması denendi. Eğitim kümesinde 1341 normal ve 3875 anomali görüntüsü var.
  - Karşılaştırma için CNN transfer öğrenme modelleri (ResNet, DenseNet, Inception, EfficientNet) ve farklı ViT türevleri (CrossViT, IEViT, SepViT, VATT, MobileViT, Pale Transformer, DeiT III) önerildi.
  - IEViT makalesindeki ViT ve IEViT modellerinin yama boyutu, katman sayısı, gizli boyut ve parametre sayısı tablosu gösterildi (ekrandan, 00:35:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Önce temel çizgi (baseline): transfer öğrenme
  - Her projede önce ResNet, DenseNet, Inception, EfficientNet gibi önceden eğitilmiş modellerle sonuç alınmalı; geliştirilen yöntem bu sonuçlarla karşılaştırılmalı. AlexNet gibi eski mimariler gerekmez.
- K-katlı çapraz doğrulama
  - Veri eğitim/test olarak ayrılmamışsa $K=5$ seçilir: verinin 4/5'iyle eğitilir, 1/5'iyle test edilir, test bölümü her katta değişir ve sonuçların ortalaması alınır.
- Yarı denetimli öğrenmede az etiketli örnek
  - Önemli olan her sınıfı temsil eden etiketli örnektir. 6 sınıf için sınıf başına 1, 2, 3, 5, 10, 20 örnekle sırasıyla 6, 12, 18, 30, 60, 120 etiketli örnekle deney yapılabilir.
- CNN'e girdi boyutu
  - CNN'e koordinat değil, görüntü yaması verilir. 64x64 yama, modelin özgün girdi boyutuna (ör. 224x224) yeniden boyutlandırılabilir; ardışık filtrelerin anlamlı öznitelik çıkarması için bu daha iyidir.
- Bölütleme çıktısı ve değerlendirme
  - İkili bölütlemede çıktı 0/1 maskesidir. Çok organlı veri setinde etiketler 0'dan sınıf sayısının bir eksiğine kadar gider, yani bölütlemeyle birlikte sınıflandırma da öğrenilir.
  - Bölütleme başarısı gerçek etiketle örtüşmeye bakılarak ölçülür: kesişim / birleşim (Intersection over Union, IoU).
- Literatür taraması
  - Tek makale yerine aynı veri setini kullanan makaleler birlikte taranmalı; böylece problemin doğası anlaşılır.
  - Hazır kodu çalıştırmak yalnız başlangıç noktasıdır; yöntemsel bir yenilik ve karşılaştırmalı bir tablo hedeflenmelidir.

## Kısa Tekrar Notları

- GCN: $A$ komşuluk, $D$ derece matrisi; normalleştirme $D^{-1/2} A D^{-1/2}$.
- GCN türleri: spektral ve uzamsal.
- Klasik öğrenme için uzamsal öznitelik (SIFT, SURF, HOG) gerekir; CNN bunu kendi öğrenir.
- Baseline: ResNet, DenseNet, Inception, EfficientNet ile transfer öğrenme.
- K=5 katlı çapraz doğrulama: 4/5 eğitim, 1/5 test, ortalama.
- Yarı denetimli deney: sınıf başına k örnek, toplam $6k$ etiketli örnek.
- Yamayı modelin girdi boyutuna (224x224) yeniden boyutlandır.
- Bölütleme değerlendirmesi: IoU.
- ViT'ler, CNN transfer öğrenmesiyle karşılaştırmalı olarak değerlendirilir; ViT türevleri: CrossViT, IEViT, SepViT, MobileViT, DeiT III vb.

## Detaylı Açıklamalar

- **Graf evrişim ağları.** Bir graf düğümlerden ve kenarlardan oluşur. Komşuluk matrisi $A$, $i$ ve $j$ düğümleri bağlıysa $A_{ij}=1$, değilse $0$ değerini tutar. Derece matrisi $D$ köşegen bir matristir ve $D_{ii}$, $i$ düğümünün bağlantı sayısıdır. Tam bağlantılı bir ağ katmanı girdiyi ağırlıkla çarpıp yanlılık ekler ve aktivasyondan geçirir. Graf evrişim katmanında komşuluk matrisi bu çarpıma eklenir; böylece her düğümün yeni temsili komşularının özniteliklerinden de beslenir. Komşuluk matrisi doğrudan kullanılmaz, iki taraftan $D^{-1/2}$ ile çarpılarak normalleştirilir. GCN yöntemleri spektral ve uzamsal olarak ikiye ayrılır.
- **Görüntüden grafa.** Görüntü sınıflandırmada önce bir CNN (ör. ResNet) ile öznitelikler çıkarılır, bu öznitelikler graf düğümleri olur ve graf öğrenmesi bu düğümler üzerinde yapılır. Çok etiketli tanıma çalışmalarında düğümler etiketleri temsil edebilir; tek etiketli dört sınıflı bir problemde bu yapının nasıl uyarlanacağı ayrıca düşünülmelidir. Hoca, hazır kodların Papers with Code ve GitHub'da aranmasını, önce mevcut kodla kendi veriyle sonuç alınmasını önerdi.
- **Hücre yamalarının sınıflandırılması.** SVM bir vektör alır; yalnız merkez noktası ya da tek bir filtrenin çıktısı yeterince ayrıştırıcı değildir. Yamadan SIFT, SURF, HOG gibi uzamsal öznitelik çıkarıp SVM ya da rastgele ormana vermek bir yoldur. CNN ise öznitelikleri kendisi öğrenir; bu yüzden yamalar doğrudan, gerekirse 224x224'e yeniden boyutlandırılarak CNN'e verilir. Yarı denetimli yöntemlerde etiketli eğitim kümesinin büyük olması gerekmez; sınıf başına birkaç örnekle başlanıp örnek sayısı artırılarak başarının nasıl değiştiği incelenir.
- **TransUNet ve Synapse.** Synapse veri seti karın BT hacimlerinden oluşur; her kesit 512x512 pikseldir, voxel aralığı pikseller arası ve kesitler arası uzaklığı verir. Gerçek etiket maskesinde her organ farklı bir sınıf numarasıyla (farklı renkle) gösterilir. Denemede model yalnız karaciğeri buldu. Hoca, çok sınıflı bölütlemede çıktının yalnız 0/1 olmadığını, etiketlerin 0'dan 8'e kadar gidebileceğini ve bu durumda modelin aynı anda sınıflandırma da öğrendiğini belirtti. Sonuç, tahmin edilen bölütün gerçek etiketle örtüşmesi (IoU) ile ölçülür. Başlangıç için tek organa (ör. karaciğer) odaklanmak da bir seçenektir.
- **Vision Transformer.** Hazır bir ViT'i çalıştırmak bir temel çizgidir; asıl katkı farklı ViT türevlerini ve CNN transfer öğrenme modellerini aynı veri ve aynı değerlendirme düzeniyle karşılaştırmaktır. IEViT, ResNet'teki atlamalı bağlantıdan esinlenir: girdinin bir temsili, paralel bir evrişim bloğuyla üretilip her Transformer kodlayıcı katmanının çıkışına tekrar tekrar eklenir (ekrandan, 00:35:00). Hoca, görüntüye elle filtre uygulamanın ViT için gerekli olmadığını, bu dönüşümleri modelin kendisinin öğrenmesinin beklendiğini söyledi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
