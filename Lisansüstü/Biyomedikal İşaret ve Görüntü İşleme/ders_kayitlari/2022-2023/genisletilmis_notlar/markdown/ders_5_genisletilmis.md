# Ders 5 Genişletilmiş Notu: Proje İlerleme Görüşmeleri: Grafik Evrişim Ağları, Transfer Öğrenme ve Bölütleme Sonrası İşleme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin biçimi
- 2. Grafik evrişim ağlarında komşuluk matrisi
- 3. Hücre görüntülerinde yama tabanlı sınıflandırma
- 4. Öz-gözetimli öğrenmeden önce transfer öğrenme tabanı
- 5. Çekirdek segmentasyonu ve GPU bellek hatası
- 6. Servikal sitolojide derin özellik ve makine öğrenmesi
- 7. Meme kanseri görüntülerinde transfer öğrenme ve derin topluluk
- 8. Dört sınıflı histopatoloji sınıflandırmasında değerlendirme
- 9. Çok organlı bölütleme, son işleme ve SinGAN-Seg
- 10. Örnek Sorular

## 1. Dersin biçimi

Bu kayıt bir konu anlatımı değil, dönem projelerinin ilerleme görüşmesidir. Öğrenciler sırayla ekranlarını paylaşıp bir haftada ne yaptıklarını, hangi makaleyi ve kodu temel aldıklarını, nerede takıldıklarını anlattı. Hoca her projede bir sonraki adımı belirledi. Projelerin hepsi tıbbi görüntülerde sınıflandırma ya da bölütleme üzerinedir. Görüşmelerde öğrenciler de birbirine öneride bulundu; hoca bunu ortak çalışmanın amacı olarak destekledi.

Görüşmelerde tekrar eden yöntem çizgisi şudur:

- Temel alınan makalenin kodunu anlamak, gerekirse debug edip ara çıktıları çizdirmek.
- Standart transfer öğrenme modelleriyle bir karşılaştırma tabanı kurmak.
- Bu tabanın üzerine kendi katkısını (yeni bir matris tasarımı, topluluk yöntemi, son işleme, sentetik veri) koymak.

## 2. Grafik evrişim ağlarında komşuluk matrisi

### 2.1 Temel alınan çalışma

Bir öğrenci COVID görüntüleri içeren 4 sınıflı bir veri setinde çalışıyordu. Papers with Code üzerinden bulduğu, çok etiketli görüntü tanımada grafik evrişim ağı (Graph Convolutional Network, GCN) kullanan bir CVPR 2019 makalesini temel aldı: "Multi-Label Image Recognition With Graph Convolutional Networks" (ekrandan, 00:05:00). Makalenin ilk şeklinde etiketler arasında yönlü bir grafik kuruluyor: örneğin "Person", "Sports Ball", "Tennis Racket", "Tie", "Ski" düğümleri. Şekil açıklamasına göre "Label A → Label B" oku, A görüldüğünde B'nin de görülme olasılığının yüksek olduğunu, ama tersinin doğru olmayabileceğini anlatır. Bu çalışma COCO veri tabanını kullanır; COCO'da 80 nesne sınıfı vardır ve GCN bu 80 sınıf üzerinde çalışır.

### 2.2 Koddaki komşuluk matrisi

Öğrenci kodu kendi problemine uyarlarken GCN'in komşuluk (adjacency) matrisinin dışarıdan yüklendiğini fark etti. Matris önceden hesaplanıp bir pickle dosyasına kaydedilmiş, kod bunu içe aktarıyor. COCO için matris 80x80'dir. Kodda matrisi hazırlayan bir fonksiyon (`gen_A` benzeri, altyazıda "Generate A") sınıf sayısını (80), bir eşik değeri `t` ve bu komşuluk dosyasını parametre olarak alıyor. Dosyada matrisin yanında bir de sayı listesi var; ekranda 80 satırlık bu liste görünüyor, örneğin ilk satırlar 2243, 1171, 3924 ve 14. satır 5968 (ekrandan, 00:10:00).

Hoca önce matrisin anlamını sordu. Öğrencinin tahmini, matrisin sınıfların birbirleriyle ilişkisini gösterdiğiydi. Hoca bu tahmini kabul etti: matris düğümler, yani sınıflar arasındaki bağlantıları gösterir.

### 2.3 Hocanın önerileri

Hoca matrisin nasıl kurulacağı üzerine birkaç yol önerdi:

- **Önce anlamak.** Kod debug modunda matrisin yüklendiği satıra kadar çalıştırılmalı, matris Python ya da MATLAB'da görüntü gibi iki boyutlu çizdirilmelidir. Her satırın en büyük değerinin nerede olduğu ve diğer sınıflara olan küçük bağlantılar incelenmelidir. Makalede değerlerin nasıl elde edildiği de okunmalıdır.
- **Sayı listesini kontrol etmek.** Listedeki sayılar sınıflardaki örnek sayısıyla uyuşuyorsa, matris sınıfların örnek dağılımıyla ilişkili bir şeydir. Örneğin 14. satırdaki 5968, o sınıfın diğer sınıflarla bağlantısının hesaplanmasında kullanılıyor olabilir.
- **Kendi matrisini kurmak.** Dört sınıflı problem için 4x4'lük bir matris gerekir. İlk deneme olarak rastgele değerlerle başlatılabilir ve farklı rastgele başlatmalarla sonuç izlenebilir. Daha anlamlı bir yol olarak bir kümeleme yapılıp sınıf merkezlerinin birbirine uzaklıkları matrise konabilir. Matrisin iteratif olarak iyileştirilip iyileştirilemeyeceği de araştırılabilir.
- **Problem bilgisini kullanmak.** Sağlıklı sınıf dışındaki hastalık sınıflarının birbirleriyle ilişkisi matrise yansıtılabilir.

<!-- BELİRSİZ: Hoca "bir ön sınıflandırıcıya verip" diye bir öneri daha başlatıyor ama cümle yarım kalıyor; önerinin ayrıntısı altyazıdan anlaşılmıyor. -->

> **Hocanın vurgusu:** Matrisin anlamı çözülüp kendi problemine göre yeniden kurulması, çalışmanın yeniliği olabilir; bu, yöntemi farklı bir probleme uyarlamak demektir.

Hoca ayrıca bu koda bağlı kalmak zorunda olunmadığını, başka GCN kodlarına da bakılabileceğini söyledi. Önemli olan, programın hata vermemesi için matrisin boyutunun doğru olması ve değerlerin dağılımıdır.

> **Ek bilgi (derste anlatılmadı):** Bu makalenin resmi kodunda pickle dosyası büyük olasılıkla iki şey tutar: eğitim setinde her etiketin kaç kez geçtiği (`nums`) ve iki etiketin birlikte kaç kez geçtiği (`adj`). Koşullu olasılık $P(L_j \mid L_i) = M_{ij} / N_i$ biçiminde hesaplanır, eşik `t` ile ikili hale getirilir ve yeniden ağırlıklandırılır. Ekranda görülen 80 sayılık liste büyük olasılıkla bu `nums` dizisidir.

## 3. Hücre görüntülerinde yama tabanlı sınıflandırma

Bir öğrencinin veri setinde her görüntüde yüzlerce hücre bulunuyordu. Öğrenci görüntüleri yamalara (patch) ayırıp her hücre için yeni, sabit boyutlu bir görüntü oluşturdu ve bunları bir CNN'e vermeyi planladı.

<!-- BELİRSİZ: Altyazıda hücre sayısı "50 / 500" ve yama boyutu "24'ye 24" diye geçiyor; değerler karede doğrulanamadı. -->

Hoca CNN'in sıfırdan mı kurulacağını yoksa standart transfer öğrenme yöntemlerinin mi kullanılacağını sordu. Önerisi standart modellerdir: Inception, EfficientNet, ResNet ve DenseNet. Bu sonuçlar görüldükten sonra projenin asıl hedefi olan yarı gözetimli (semi-supervised) öğrenmeye geçilmesi gerekir.

## 4. Öz-gözetimli öğrenmeden önce transfer öğrenme tabanı

Bir öğrenci, önceki görüşmede konuşulan öz-gözetimli (self-supervised) yaklaşımı ağır bulduğunu söyledi. Hocanın önerisi bir sıra izlemektir:

- Önce veri seti tanıtılır: kaç sınıftan oluştuğu, ne tür görüntüler içerdiği.
- Sonra transfer öğrenme yöntemleriyle veri setinde yüzde kaç sınıflandırma başarısı elde edildiği ölçülür.
- Öz-gözetimli yönteme geçerken karşılaşılan sorunlar bilinirse, hoca yöntemsel olarak yön verebilir; gerekirse konu değiştirilebilir.

> **Hocanın vurgusu:** Yapılan denemeler, sonuç vermese bile anlatılmalıdır; hoca ancak takılınan yeri bilirse yöntemsel olarak yönlendirebilir.

## 5. Çekirdek segmentasyonu ve GPU bellek hatası

### 5.1 Proje ve kod

Bir öğrenci hücre çekirdeği (nucleus) segmentasyonu üzerine çalışıyordu. Kullandığı veri kaynağında iki ayrı veri seti vardı. <!-- BELİRSİZ: Veri setlerinin adları altyazıda bozuk ("Nucleek", "lamp bezleri"); karede doğrulanamadı. --> Öğrenci yalnız önerilen modeli değil, karşılaştırma için PSPNet dahil altı segmentasyon modelini tanımladı ve hepsini bir döngüde sırayla eğitti. Ekrandaki kod şöyledir (ekrandan, 00:20:00):

```python
for model_name, model_instance in models_dict.items():
    name = model_name
    model_name = model_instance
    model_name.to("cuda:0")
    x = torch.zeros(8, 3, 32, 32, dtype=torch.float, requires_grad=False)
    x = x.to("cuda:0")
    outputs_x = model_name(x)
    make_dot(outputs_x, params=dict(list(model_name.named_parameters())))

    optimizer = torch.optim.Adam(params = model_name.parameters(),
                                 lr=1e-4,
                                 betas=(0.9, 0.999),
                                 eps=1e-08,
                                 weight_decay=0,
                                 amsgrad=False)

    criterion = torch.nn.BCEWithLogitsLoss()

    history = dict(train_loss = [],
                   train_dice = [],
                   test_loss = [],
                   test_dice = [])

    logs = []

    training(model = model_name, epochs = 20, batch_size = 32)

    histories.append(logs)

    # Saving the model weights for each model in working directory
    working_dir = 'saving models'
    weights_path = os.path.join(working_dir, name + '_weights.pth')
    logs_path = os.path.join(working_dir, name + '_logs')
    torch.save(model_name.state_dict(), weights_path)
```

Her model GPU'ya taşınıyor, Adam optimizasyonu ve ikili çapraz entropi (logit girişli) kaybıyla eğitiliyor; eğitim ve test için kayıp ve Dice değerleri tutuluyor, ağırlıklar dosyaya kaydediliyor. Kod parçası derste yazıldığı gibi aktarılmıştır, derlenip çalıştırılmamıştır.

### 5.2 "CUDA out of memory" hatası

Eğitim sırasında "CUDA out of memory" hatası alındı. Öğrencinin bilgisayarında 4 GB GPU belleği vardı. Konuşmada şu öneriler çıktı:

- **Batch boyutunu düşürmek.** Bir öğrenci, 4 GB bellek için 32'lik batch'in fazla olabileceğini söyledi.
- **Bellek yönetimi.** Yüklenip işlenen eski görüntüler bellekte tutulmamalı; arka planda gereksiz yere bellekte tutulan nesneler temizlenmelidir.
- **Bulut ortamı.** Kod Google Colab'e ya da Kaggle not defterine taşınabilir. Bir öğrenciye göre Colab'de yaklaşık 12 GB GPU belleği vardır; ama batch büyütülürse orada da aynı hata alınır.
- **Veri miktarı.** Olmazsa eğitim verisi biraz küçültülebilir.
- **Hata araştırması.** Hata mesajı aratılıp benzer hatayı alanların bellek sorununu nasıl çözdüğüne bakılmalıdır.

Hata mesajında "CUDA" ifadesi geçtiği için sorunun GPU belleğinden kaynaklandığı görüldü.

> **Ders sonrası not:** Görüşmede bir öğrenci bu hatanın ekran kartı NVIDIA değilse alındığını söyledi. Doğrusu büyük olasılıkla şudur: "CUDA out of memory" hatası CUDA'nın çalıştığı, yani NVIDIA bir GPU'da, GPU belleği yetmediğinde alınır. NVIDIA olmayan sistemde hata farklıdır (CUDA bulunamadı gibi). Bu yüzden asıl çözüm batch boyutunu ve bellek kullanımını düşürmektir.

## 6. Servikal sitolojide derin özellik ve makine öğrenmesi

### 6.1 Temel alınan çalışma

Bir öğrenci servikal kanser hücre görüntüleri üzerinde çalışıyordu; veri seti SIPaKMeD'dir (altyazıda "SparkMac" diye bozulmuş). Temel aldığı çalışma "Cervical Net: A Novel Cervical Cancer Classification Using Feature Fusion" başlıklı makaledir (ekrandan, 00:35:00). Slayttaki şemada:

- SIPaKMeD veri seti üç gruba ayrılıyor: Normal (Superficial, Parabasal), Abnormal (Metaplastic), Benign (Dyskeratotic, Koilocytotic).
- Görüntüler önce iyileştiriliyor (Image Enhancement).
- Önceden eğitilmiş ShuffleNet'ten 544 derin özellik, yeni önerilen Cervical-Net'ten 1024 derin özellik çıkarılıyor; ikincisi PCA ile 544'e indiriliyor.
- İki özellik kümesi kanonik korelasyon analiziyle (Canonical Correlation Analysis) birleştiriliyor.
- Her özellik kümesi ve birleşik küme ANN, SVM, KNN, RF ve NB sınıflandırıcılarına veriliyor. Birleşik özelliklerle en yüksek doğruluk SVM'de %99,1 olarak işaretlenmiş.

### 6.2 Öğrencinin akışı

Öğrenci makalenin kodunu kullanmadı, akışı kendisi kodladı:

- Veriyi aldı ve ön işlem olarak filtreleme uyguladı.
- Keras'taki hazır derin öğrenme modellerinin (Keras Applications) performansına bakarak modelleri seçti.
- Seçilen modellerle özellik çıkardı; şimdilik modelleri tek tek deniyor, birleştirmedi.
- Özellikleri ölçekledi (scaler) ve PCA uyguladı.
- Makine öğrenmesi sınıflandırıcılarına verdi ve hiperparametre iyileştirmesi yaptı.

Ekrandaki Kaggle not defterinde hiperparametre iyileştirmesinin çıktısı ve bir "stacking & ensemble" fonksiyonu görünüyor (ekrandan, 00:25:00):

```python
# Stacking & Ensemble Learning
def voting_classifier(best_models, X, y):
    print("Voting Classifier...")
    voting_clf = VotingClassifier(estimators=[('KNN', best_models["KNN"]), ('RF', best_models["RF"]),
                                              ('LightGBM', best_models["LightGBM"])],
                                  voting='soft').fit(X, y)
    cv_results = cross_validate(voting_clf, X, y, cv=3, scoring=["accuracy", "f1", "roc_auc"])
    print(f"Accuracy: {cv_results['test_accuracy'].mean()}")
    print(f"F1Score: {cv_results['test_f1'].mean()}")
    print(f"ROC_AUC: {cv_results['test_roc_auc'].mean()}")
    return voting_clf
```

Çıktıdaki ara sonuçlar şunlardır:

| Model | Doğruluk (iyileştirme sonrası) | En iyi parametreler |
|---|---|---|
| KNN | 0,8402 | `n_neighbors: 3` |
| CART | 0,7024 | `max_depth: 7`, `min_samples_split: 5` |
| RF | 0,837 | `max_depth: 15`, `max_features: 'auto'`, `min_samples_split: 15`, `n_estimators: 200` |
| XGBoost | (çıktı henüz gelmemişti) | |

En iyi modeller yumuşak oylamayla (her modelin sınıf olasılıkları ortalanarak) birleştiriliyor ve 3 katlı çapraz doğrulamayla doğruluk, F1 ve ROC AUC ölçülüyor. Öğrencinin sonraki planı, farklı derin modellerin özelliklerini birleştirip kendi modelini kurmaktır.

Öğrenci Kaggle'ın GPU hizmetini kullanıyordu ve eğitimin yavaş olduğunu söyledi. Hoca derin öğrenme yöntemlerinin genel olarak yavaş çalıştığını, bunun sorun olmadığını; önemli olanın programın hata vermeden çalışması olduğunu belirtti.

> **Ders sonrası not:** Ekrandaki `VotingClassifier`'da üçüncü model LightGBM'dir, ama hiperparametre çıktısında XGBoost başlığı görünüyor; kod ile çıktı farklı bir sürüme ait olabilir. Ayrıca sklearn'de `scoring="f1"` ikili sınıflandırma içindir; çok sınıflı veride büyük olasılıkla `f1_macro` gibi bir ortalama türü gerekir.

## 7. Meme kanseri görüntülerinde transfer öğrenme ve derin topluluk

### 7.1 Proje

Bir öğrenci yedi sınıflı bir meme kanseri veri setinde derin topluluk öğrenmesi (ensemble deep learning) ile sınıflandırma yapacaktı. <!-- BELİRSİZ: Veri setinin adı altyazıda "Brex" diye geçiyor; 7 sınıflı olması BRACS veri setini düşündürüyor ama karede doğrulanamadı. --> Öğrenci bir yandan topluluk yöntemleri üzerine makaleleri ve kodları incelerken bir yandan da üç transfer öğrenme modelini (VGG, ResNet, Inception) denedi. Ekrandaki Colab kodu şöyle başlıyor (ekrandan, 00:30:00):

```python
from google.colab import drive
drive.mount('/content/drive')

train_data_dir = '/content/drive/My Drive/train'
validation_data_dir = '/content/drive/My Drive/val'

from keras.applications.vgg19 import VGG19
from keras.models import Model
def Build_CNN_Model():
    #---------------------------
    #          TRANSFER VGG MODEL
    #---------------------------
    #Load VGG model
    vgg = VGG19(include_top=True, input_shape=(224,224,3))

    #mark loaded layers as trainable
    for layer in vgg.layers:
        layer.trainable = True

    #Flatten and Fully connected Layer
    Flat_layer = Flatten()(vgg.layers[11].output)
    FC_layer = Dense(100)(Flat_layer)
```

VGG19 ImageNet ağırlıklarıyla yükleniyor, bütün katmanları eğitilebilir yapılıyor, 11. katmanın çıkışı düzleştirilip 100 nöronlu tam bağlantılı bir katmana veriliyor. Kod parçası derste görüldüğü kadarıyla aktarılmıştır, çalıştırılmamıştır.

### 7.2 Colab'de yavaşlık

Hiçbir modelde sonuç alınamamıştı, çünkü tek bir batch bile çok uzun sürüyordu. Öğrencinin bulduğu neden: görüntüler Drive'a tek tek yüklenmiş ve eğitim sırasında Drive'dan okunuyordu. Görüntüler zip olarak yüklenip Colab'de açılırsa (unzip) dosyalar Colab'in kendi diskinden ve belleğinden okunur, bu da çok daha hızlıdır. Bir öğrencinin sohbetten sorduğu soru üzerine çalışma zamanının (runtime) GPU'ya alındığı da kontrol edildi; bu ayarlanmıştı, ama yavaşlığı çözmemişti. Batch boyutu ve epoch sayısı da süreyi etkileyebilir.

### 7.3 Derin topluluk

Hoca, öncelikle sınıflandırma sonuçlarını birleştiren topluluk yaklaşımları üzerinde çalışılmasını önerdi. "Deep ensemble" araması yapıldığında konuyu iyi anlatan Towards Data Science, Medium gibi sitelerin bulunduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** Sonuç düzeyinde topluluk yöntemlerinin en basitleri çoğunluk oylaması ve olasılık ortalamasıdır (yumuşak oylama). Daha gelişmiş bir yol, modellerin çıktılarını girdi alan ikinci bir sınıflandırıcı eğitmektir (stacking).

## 8. Dört sınıflı histopatoloji sınıflandırmasında değerlendirme

Bir öğrenci meme kanseri histoloji görüntüleri üzerinde transfer öğrenme ile sınıflandırma yapıyordu; sunum dosyası ICIAR 2018 BACH yarışmasıyla ilgilidir ve slaytlarından birinin başlığı "Transfer deep learning methods for classification based on breast cancer histology images"dir (ekrandan, 00:40:00). Veri setinde iki ve dört sınıflı ayrımlar vardı. Hocanın önerileri:

- **Veri artırma.** Görüntü sayısı az olduğu için mutlaka veri artırma (data augmentation) yapılmalıdır.
- **K-katlı çapraz doğrulama.** Eldeki kod verinin %10'unu doğrulamaya ayırıyordu. Hoca bunu istemedi; eğitim ve test kümesini sabit ayırmak yerine k-katlı çapraz doğrulama (k-fold cross validation) uygulanmasını ve $k=5$ seçilmesini söyledi.
- **Başarım ölçütleri.** Sınıflandırma sonucu için accuracy, precision, recall ve F1 (F-measure) bulunması yeterlidir.
- **Modeller.** Inception, EfficientNet, DenseNet ve ResNet denenmelidir.

Öğrencinin sunum slaytında ölçütler accuracy, sensitivity, specificity, precision, recall, f_measure, g-mean 1, g-mean 2 ve AUC; modeller Inception, ShuffleNet, Xception ve GoogLeNet olarak listelenmişti (ekrandan, 00:40:00).

> **Ek bilgi (derste anlatılmadı):** 5 katlı çapraz doğrulamada veri beş eşit parçaya bölünür. Her turda bir parça test, kalan dördü eğitim için kullanılır; beş turun ölçüt ortalaması raporlanır. Veri artırma yalnız eğitim parçalarına uygulanmalıdır, yoksa test kümesine sızıntı olur.

## 9. Çok organlı bölütleme, son işleme ve SinGAN-Seg

### 9.1 TransUNet ile organ bölütleme

Bir öğrenci karın BT görüntülerinde TransUNet ile organ bölütlemesi yapıyordu. Önceki denemede model yalnız bir organı buluyordu. Nedeni araştırıldığında, eğitimi hızlı bitirmek için ayarların çok düşük tutulduğu ve modelin yeterince öğrenemediği görüldü. Epoch sayısı 100'e çıkarılıp batch boyutu değiştirilince model farklı organları da bulmaya başladı; görüntü boyutu büyütülünce daha fazla ayrıntı çıktı. Slaytta aynı kesit (Slice 120) için orijinal görüntü, ground truth ve tahmin "Eski Sonuç" ve "Yeni Sonuç" olarak yan yana gösteriliyor; eski tahminde tek bir bölge, yenisinde birden çok organ var (ekrandan, 00:45:00).

Veri setinde 8 organ etiketi vardır; gösterilen kesitte ground truth'a göre dört organ bulunmalıdır. Hoca farklı organların farklı etiketlerde olduğunu doğruladı. Bazı bölgeler yanlış çıkmıştı; hoca bunların son işlemle düzeltilebileceğini söyledi.

Hoca güncel bölütleme algoritmalarıyla devam edilmesini önerdi: UNet++, UNet 3+ ve Swin-UNet. <!-- BELİRSİZ: Altyazıda "Sivinyunet" diye geçiyor; Swin-UNet olduğu bağlamdan tahmin edildi. -->

### 9.2 Son işleme: Markov Random Field

Öğrenci kendi katkısının ne olabileceğini sordu. Hocanın önerisi, ek bir yöntem geliştirmek yerine bölütleme sonrasına bir son işleme (post-processing) adımı eklemektir. Bölütleme sonuçları ground truth'a tam benzemiyor; Markov Random Field (MRF) bu sonuçları düzeltmek için kullanılabilir. MRF hem orijinal görüntüyü hem de bulunan bölütleri kullanır. Örneğin tahminde bir organın içinde (sağ altta) bir delik varsa, MRF orijinal görüntüye ve çevredeki bölütlere bakarak o deliği kapatmaya çalışır.

> **Ek bilgi (derste anlatılmadı):** MRF tabanlı son işlemde her pikselin etiketi iki terimin toplamını küçültecek biçimde seçilir: pikselin kendi sınıf olasılığına (ağın çıktısına) uyum ve komşu piksellerle aynı etiketi alma eğilimi. Komşuluk terimi, çevresi tek bir organa ait olan küçük delikleri ve gürültülü adacıkları ortadan kaldırır.

### 9.3 SinGAN-Seg

Öğrencinin asıl ilgisi GAN tabanlı sentetik veri üretimiydi. Bu veri setini GAN ile kullanan bir çalışma bulamadı, ama koşullu GAN'lar ve SinGAN-Seg üzerine çalışmaları inceledi. SinGAN-Seg'in yaptığı iş şudur: elde yeterli veri yoksa tek bir görüntü (single image) alınır, bu görüntüden çok sayıda sentetik görüntü, maskeleriyle birlikte üretilir; üretilen görüntü-maske çiftleri eğitimde kullanılabilir. Slaytta tek bir polip görüntüsünden (maske bilgisiyle birlikte) üretilmiş `0_img.png`, `0_mask.png` gibi sentetik çiftler görünüyor. Eğitim komutu şöyledir (ekrandan, 00:50:00):

```text
main_train.py --input_name polyp_with_4_channels.png --nc_z 4 --nc_im 4 --gpu_id 0 --niter 100
```

Görüntü 4 kanallıdır (3 renk kanalı ve maske). Öğrencinin fikri, eğittiği veri setinden bir görüntü alıp SinGAN-Seg ile çoğaltmak ve sentetik görüntüleri TransUNet'e tekrar vermekti. Hoca, eğitim sürerken görüntü boyutunun küçükten başlayıp büyüdüğünü, bu yüzden sürenin uzadığını öğrencinin anlatımıyla birlikte değerlendirdi ve şunları söyledi:

- Tek görüntü yerine birden fazla görüntü alabilen bir GAN yapısı kurulabilir mi, araştırılmalıdır; herhangi bir GAN ile bu yapı kendi başına kurulabilir.
- GAN tarafı ikinci plandır. Öncelik iyi bir bölütleme elde etmektir: Swin-UNet, UNet 3+, UNet++ denenmeli, ardından bunlara Markov Random Field uygulanmalıdır.

> **Hocanın vurgusu:** Bu tür projelerde takılmak ve hata almak işin doğasıdır; öğrenme zorluktan doğar.

## 10. Örnek Sorular

**Soru 1** (derste sözlü, 00:04:33): ML-GCN gibi bir modeli kendi 4 sınıflı problemine uyarlarken komşuluk matrisinin boyutu ne olmalıdır?

> **Çözüm (derste verildi):** Komşuluk matrisi sınıflar (düğümler) arasındaki ilişkiyi tuttuğu için boyutu sınıf sayısına göre belirlenir: COCO'nun 80 sınıfı için 80x80, 4 sınıflı problem için 4x4'tür. Örnek sayısıyla değil, sınıf sayısıyla ilgilidir.

**Soru 2** (derste sözlü, 00:20:12): Eğitim sırasında alınan bellek hatası GPU belleğinden mi, bilgisayarın RAM'inden mi kaynaklanır?

> **Çözüm (derste verildi):** Hata mesajı "CUDA out of memory" olduğu için sorun GPU belleğindedir. 4 GB GPU belleğinde 32'lik batch fazla gelebilir; batch boyutu düşürülür, gereksiz tensörler bellekten atılır ya da daha büyük GPU belleği olan bir ortama (Colab, Kaggle) geçilir.

**Soru 3** (derste sözlü, 00:38:05): Eğitim verisinin %10'unu doğrulamaya ayırmak yerine hangi doğrulama yöntemi kullanılmalıdır?

> **Çözüm (derste verildi):** Veri az olduğu için k-katlı çapraz doğrulama kullanılmalı, $k=5$ seçilmelidir. Ayrıca veri artırma yapılmalı ve accuracy, precision, recall, F1 raporlanmalıdır.

## Dersin Toparlaması

Bu görüşmede konu anlatımı yerine projeler üzerinden uygulamalı derin öğrenme konuşuldu. Ortak mesaj şudur: temel alınan çalışmanın kodu ve ara yapıları (örneğin GCN'in komşuluk matrisi) gerçekten anlaşılmalı, standart transfer öğrenme modelleriyle bir taban kurulmalı, değerlendirme veri artırma ve k-katlı çapraz doğrulama ile güvenilir yapılmalıdır. Bunun üzerine öğrencinin katkısı gelir: probleme özgü bir komşuluk matrisi, derin özelliklerin birleştirilmesi ve oylamalı topluluklar, ya da bölütlemede MRF gibi bir son işleme adımı.

Pratik sorunlar da yöntem kadar önemlidir. GPU bellek hataları batch boyutunu düşürerek ve bellek yönetimiyle, Colab'deki yavaşlık verinin zip olarak taşınıp yerel diske açılmasıyla çözülür. GAN tabanlı sentetik veri üretimi (SinGAN-Seg) umut verici bir ek yön olarak görüldü, ama önceliği iyi bir bölütlemeden sonra gelir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
