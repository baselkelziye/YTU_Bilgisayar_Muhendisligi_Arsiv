# Ders 13 Genişletilmiş Notu: Seminer Sunumları: Duygu Tespiti Yaklaşımları, Konu Bölümleme, Türkçe Kelime Bölümleme ve Bağımlılık Tabanlı Dil Modelleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın. Altyazıda okunmayan slayt içeriği (GloVe hata fonksiyonu ve RNN denklemleri gibi) kısa nottan alınmıştır; bu turda kareyle yeniden doğrulanmamıştır.

## İçindekiler

- 1. Dersin Yapısı
- 2. Birinci Sunum: Metinden Duygu Tespiti Yaklaşımları
- 3. İkinci Sunum: Konu Bölümleme Algoritmalarının Karşılaştırılması
- 4. Üçüncü Sunum: Haber Makalelerinde Sözlük Tabanlı Duygu Analizi
- 5. Dördüncü Sunum: Türkçe Metin Sınıflandırma için Kelime Bölümleme
- 6. Beşinci Sunum: Cümle Tamamlama için Bağımlılık Tabanlı RNN Dil Modelleri
- 7. Altıncı Sunum: Haber Makalelerinde Doküman Düzeyinde Duygu Analizi

## 1. Dersin Yapısı

Bu kayıt, dönemin son dersidir ve öğrenci seminer sunumlarının son haftasıdır. Konu anlatımı yoktur; öğrenciler kendilerine verilen makaleleri sunar, hoca sunumların arasına girip sorular sorar ve yorum yapar. Bu derste altı sunum yapılır.

Hoca sunumların akıcı olmasını ve her birinin 20 dakikayı geçmemesini ister. Gerekçesi dinleyicinin dikkatidir: insan bir yere kadar dinleyebilir, sonra dikkati dağılır.

## 2. Birinci Sunum: Metinden Duygu Tespiti Yaklaşımları

### 2.1 Makale Seçimi ve Derleme Çalışması

Bir öğrenci sunumuna bir düzeltmeyle başlar. Kendisine verilen makalenin 2000 yılına ait olduğunu sonradan fark etmiştir ve bu kadar eski bir çalışma içine sinmemiştir. Bu yüzden 2018 tarihli bir derleme (survey) çalışmasını temel alır. Derleme, 2014-2017 arasındaki 50'ye yakın yöntemi tablolar hâlinde verir, ama ayrıntılı anlatmaz. Öğrenci bunların arasından örnek olarak birkaçını ayrıntılandırır. Hoca bu seçimi, "birkaç yılda nereden nereye gelindiğini görmüş oluruz" diye karşılar.

### 2.2 Duygu Analizi ve Metnin Sınırı

Duygu analizi, duyguların metinlerde hangi yollarla anlatıldığını ve bu anlatımlardaki olumlu ya da olumsuz durumları tespit etmeyi amaçlar. İnsanların görüşlerinin, değerlendirmelerinin ve tutumlarının hesaplamaya dayalı olarak incelenmesi olarak tanımlanır.

İnsanlar duygularını yalnızca sözcüklerle anlatmaz. Ses tonu, mimikler, el hareketleri ve hatta heyecanlanınca değişen vücut ısısı da duygu taşır. Yalnızca metne dayanmak bu nedenle bir kısıttır. Öğrenciye göre, çok çalışılmış bir konu olmasına rağmen alanın görece geç gelişmesinin sebebi de budur.

### 2.3 Duygu Modelleri

Duygu teorilerinde iki çeşit model vardır.

**Kategorik model.** Duygular ayrı kategorilerdir: sinirli olmak, korkmak, mutlu olmak, şaşırmak gibi. Ekman'ın modeli 6 temel duygu alır. Başka bir model 8 duyguyu tek tek kategori olarak değil, zıt çiftler (bipolar setler) olarak ele alır; örneğin sevinç ve üzüntü (joy, sadness) bir çifttir.

**Boyutsal model.** Duygular boyutlarla tanımlanır. Circumplex modeli iki boyut kullanır:

- Hoşluk boyutu: duygunun hoş mu nahoş mu olduğu.
- Uyarılma boyutu: duygunun sakin mi heyecanlı mı olduğu.

Her boyutta duyguya bir aktivasyon derecesi verilir. Duygunun olumlu ya da olumsuz diye sınıflandırılması bu boyutlarla mümkün olur. Çalışmaların bir kısmı bu genel modelleri kullanır, bir kısmı kendi kategorilerini oluşturur.

### 2.4 Veri Setleri

İyi etiketlenmiş veri seti bulmak zordur. Çalışmaların birbiriyle karşılaştırılabilmesi için de ortak veri setleri gerekir. En çok kullanılanlardan üçü şunlardır:

| Veri seti | Kaynak | Boyut | Duygu sayısı |
| :--- | :--- | :--- | :--- |
| ISEAR | Farklı kültürlerden katılımcıların etiketlemesi | 7666 cümle | 7 |
| Fairy Tales | 185 çocuk öyküsü | Yaklaşık 15.000 cümle | 8 |
| SemEval | Google Haberler, BBC, CNN haber başlıkları | (altyazıda söylenmiyor) | 6 |

ISEAR en eski ve güvenilir etiketli veri setlerindendir, duyguları düzenli dağılmıştır. Fairy Tales'te dağılım ötekilere göre daha az düzgündür. SemEval'in farkı şudur: her cümleye tek duygu atanmaz, birden çok duygu farklı derecelerle atanır. Öğrenci bunu temsilî sayılarla anlatır: "0,7 sinirli, 0,5 korkmuş".

**Soru:** Bu veri setlerine şu an erişilebiliyor mu?
**Cevap:** Öğrenci, Kaggle'dan indirilebildiğini söyler.

### 2.5 Ön İşleme

Çalışma kendi derlemini oluşturuyorsa daha kapsamlı ön işleme yapmak zorundadır. Hazır veri setlerinde genellikle basit adımlar yeter: tokenization, lemmatization, kök bulma (stemming), işlevsel kelimelerin (stop words) çıkarılması, bağlantılar gibi gürültünün temizlenmesi ve kısaltmaların açılması.

### 2.6 Dört Ana Yaklaşım

Metinden duygu tespiti yaklaşımları dört başlıkta incelenir:

- **Anahtar kelime tabanlı (keyword):** En basit yaklaşımdır. Duygu ifade eden kelimelerin varlığına ve sıklığına bakılır. Bazı çalışmalar bu kelimelerden sözlük oluşturur. Kelimeler arası ilişkiye bakılmadığı için genellikle yetersiz kalır.
- **Derlem tabanlı (corpus):** Anahtar kelime yaklaşımının genişletilmiş hâlidir. Kelimelere bir olasılık ya da ağırlık verilir. Değerlendirmede en çok kesinlik (precision), duyarlılık (recall) ve F-ölçüsü kullanılır. Sonunda yine bir sınıflandırıcı gerekir; derlemedeki tablodan örnek bir çalışmada J48 kullanılmıştır.
- **Öğrenme tabanlı:** Denetimli (supervised) ve denetimsiz (unsupervised) yöntemler. Kelime düzeyi dışında konu düzeyinde çalışanlar da vardır.
- **Karma (hybrid):** Yukarıdakilerin birleştirilmesi.

### 2.7 Derlem Tabanlı Örnek: myPersonality

Bu çalışma, myPersonality projesindeki Facebook verisini kullanır. Veride 5865 kullanıcının yaklaşık 1 milyon durum güncellemesi vardır. Kullanıcıların takip ettikleri ve beğendikleri sayfalar, eğitim ve iş geçmişi de yer alır. Amaç, duyguyu yaş, cinsiyet ve kişilik özellikleriyle ilişkilendirmektir.

Kişilik özellikleri veride 1 ile 5 arasında puanlarla verilir. Çalışma, başka bir veri setinde kullanılan eşik değerlerine göre bu puanları eşikler ve 5 kişilik kategorisi elde eder.

<!-- BELİRSİZ: Eşik değerlerinin alındığı veri setinin adı altyazıda "VCPR" diye geçiyor; slaytta. -->

Duygu sözlüğü olarak NRC sözlüğü kullanılır. 14.177 İngilizce kelime içerir ve 10 boyutludur; her boyut bir duyguyu ya da polariteyi (olumlu, olumsuz, sinirli gibi) tutar. Bir cümle içindeki kelimelere göre aynı anda birden çok boyutta değer alabilir, örneğin hem olumlu hem sevinç. Bu özellikler ağırlıklandırılır ve olasılık hesabında kullanılır.

**Soru (hoca):** NRC kaç dil için var?
**Cevap (hoca, kendisi tamamlıyor):** NRC birçok dil için vardır, Türkçesi de vardır. Sözlüğü kullanarak çalışmak isteyen ek yapabilir.

**Soru:** "Ek yapabilmek" bir özellik (feature) eklemek gibi bir şey mi?
**Cevap:** Hayır, kelime kelime eklemek demektir. Sözlükte Türkçede duygu ifade eden bir kelime yoksa, derecesini vererek eklersin. Sözlük sonuçta bir Excel dosyası gibidir.

Hesap, duygu kategorisinin cinsiyete, yaş grubuna ve kişilik özelliklerine göre olasılığını bulmaya dayanır. Bulgular şöyledir:

- Kadınlar erkeklerden daha çok durum güncellemesi yapar.
- En çok paylaşım 41-50 yaş aralığındadır ve bu paylaşımlar olumludur. Öğrenci bunu ilginç bulur.
- Nevrotik kişiler daha az ve daha az olumlu paylaşım yapar.
- Deneyime açık (openness) kişiler en çok paylaşımı yapar, olumlu paylaşımları da çoktur.
- En çok olumlu paylaşım Aralık ayındadır.
- Pazartesi-Perşembe arasında sinirli olma ve şaşkınlık duyguları daha çok görülür.

Sonuçların anlamlılığı Pearson ki-kare testiyle sınanır. $p < 0{,}01$ olanlar anlamlı sayılır.

**Aralık ayı tartışması.** Hoca, Aralık bulgusuna itiraz eder. Aralık güney yarım kürede güzel, kuzey yarım kürede soğuk ve kasvetlidir. Bu yüzden verinin hangi konumdan alındığı önemlidir. Öğrenci ise yılbaşını düşündüğünü, sonucu buna bağladığını söyler. Hocanın aklına da bu gelmemiştir.

> **Hocanın vurgusu:** "Birlikte iş yapmak, çalışmak böyle olur." Birinin düşünmediğini diğeri düşünür.

### 2.8 Denetimli Örnek: Arapça Tweet'lerde Emoji

Bu çalışma Arapça tweet'lerle yapılır, ama dil belirleyici değildir; asıl kullanılan emojilerdir. 134.000 tweet'ten söz edilir. Verinin bir kısmı elle, bir kısmı otomatik etiketlenir ve iki yol karşılaştırılır.

Otomatik etiketleme için her emojiye $-5$ ile $+5$ arasında puan veren bir sözlük kullanılır. Sözlükte örneğin kırık kalbin bir ağırlığı vardır. Bir cümledeki emojilerin puanları toplanır ve sonuç hangi kategoriye düşüyorsa cümle öyle etiketlenir. Öğrencinin temsilî örneği: kalp $+5$, ağlama $-2$ ise toplam $+3$ olur (ara adım eklendi).

Elle etiketlemek zor olduğu için elle etiketlenen veri yaklaşık 2000, otomatik etiketlenen veri yaklaşık 22.000 örnektir. Veri %80 eğitim, %20 test olarak ayrılır. SVM ve Naive Bayes kullanılır. Otomatik etiketli veri daha başarılı sonuç verir.

Öğrenci bunu şöyle yorumlar: elle etiketlemenin daha iyi olmasını bekleriz, ama elle etiketli veri çok az olduğu için büyük olasılıkla aşırı öğrenme (overfitting) olmuş ve test başarısı düşmüştür. Aynı sayıda olsaydı elle etiketli verinin geçeceğini düşünür. Hoca "olabilir" der, ama asıl başka bir şeye takılır:

- Etiketleme emojiye bakarak yapılıyorsa, emoji içermeyen tweet'ler büyük olasılıkla elenmiştir. 134.000'den kalanlar böyle azalmış olabilir.
- Emojilerden otomatik etiketlemede zor bir şey yoktur. Kategorideki emojilerden biri varsa tweet o kategoriye atanır.
- Kalbi kırılmış ve ağlayan birinin tweet'inde bu iki emoji yan yana olabilir. Hoca böyle bir durumda sonucun nötr çıkabileceğini söyler, oysa metin üzgün bir durumu anlatır.

<!-- BELİRSİZ: Hocanın "nötr olur" dediği cümle altyazıda bozuk ("n-gram dil ne olur? Nötr olur."). Kırık kalp ve ağlamanın sözlükteki puanları slaytta. -->

### 2.9 Denetimsiz Örnek: YouTube Yorumları ve PMI

Bu çalışma YouTube yorumlarından kendi derlemini oluşturur ve noktasal karşılıklı bilgi (Pointwise Mutual Information, PMI) kullanır. Formülde her duygu ($E_j$), o duyguya ait kelimeler, derlemdeki bütün kelimeler ve derlemin satır sayısı ($N$) yer alır. Her duygu için ayrı PMI hesaplanır ve en yüksek değerli duygu cümleye atanır. Değer 0,25'e eşit ya da daha küçükse cümle nötr sayılır.

<!-- BELİRSİZ: PMI formülünün tam yazımı slaytta. -->

Yaklaşım denetimsiz olduğu için derlemin tamamı etiketlenmez. Başarıyı göstermek için etiketli bir alt küme oluşturulur ve kesinlik, duyarlılık, doğruluk bu alt kümede hesaplanır.

### 2.10 Konu Düzeyinde Örnek: Biterm Konu Modeli

Öğrenci bu çalışmanın matematiğini tam anlamadığını söyler, ama yaklaşım farklı olduğu için ekler. Kelimeler önce konular altında kümelenir. Kullanılan Biterm Konu Modeli'ni (Biterm Topic Model) diğerlerinden ayıran özellik, derlem düzeyinde çalışmasıdır.

Konu düzeyinde çalışmanın avantajı bir örnekle anlatılır: Bir cümle benzinin pahalılığından, başka bir cümle bir araba markasının özelliğinden söz etsin. Ortak kelimeleri yoktur, ama konuları otomobildir. Konu düzeyi bu cümleleri kaçırmamayı sağlar. Kümeleme adımı için çevrim içi bir platform da vardır: metin ve küme sayısı girilir, kelimeler kümelenir.

> **Ek bilgi (derste anlatılmadı):** "Biterm", kısa bir metinde birlikte geçen sırasız kelime çiftidir. Model belge başına değil derlem genelinde bu çiftlerin konu dağılımını öğrenir. Bu yüzden tweet gibi kısa metinlerde kelime birlikteliği seyrekliğine karşı daha dayanıklı olması amaçlanır.

### 2.11 Karma Örnek: Topluluk Sınıflandırıcı

Farklı sınıflandırıcılar kurulur:

- Temel öğrenici olarak kelime torbası (Bag of Words): TF-IDF ağırlıkları ve SVM.
- Kelime gömme tabanlı sınıflandırıcı: CBOW vektörleri üç ayrı ağırlıklandırmayla birleştirilir. Birincisinde bütün kelimelerin ağırlığı 1'dir. İkincisi TF-IDF'tir. Üçüncüsünde yazarlar, kelimelerin ortalama ve standart sapmasından kendi önem değerlerini üretir.

Bu sınıflandırıcıların sonuçları birleştirilip topluluk (ensemble) oluşturulur. Yazarların kendi ağırlıklandırmasını kullanan topluluk yöntemi en başarılı çıkar. Çalışmada word2vec ve GloVe sonuçları da vardır, ama öğrenci süre nedeniyle bunları göstermez.

### 2.12 Derlemenin Sonucu

Makine öğrenmesi yöntemleri yaygın olarak tercih edilir. Karma yöntemlere kıyasla derin öğrenme ve topluluk yöntemleri daha umut vericidir. Veri seti eksikliği öne çıkar: iyi bir veri seti oluşturan çok atıf alabilir. Hoca, öğrenciye bu atıfları belki kendi çalışmasıyla alabileceğini söyler.

## 3. İkinci Sunum: Konu Bölümleme Algoritmalarının Karşılaştırılması

### 3.1 Konu ve Amaç

2017'de bir konferansta yayımlanmış karşılaştırmalı bir çalışmadır. Konu bölümleme (topic segmentation), bir dokümanı anlamlı bölümlere ayırma işlemidir. Çalışmanın amacı, kelime anlamlarını analiz etmede en iyi kelime vektörü temsilini veren algoritmayı bulmaktır. Çalışmalar genelde İngilizce için yapılmıştır; bu çalışma hem İngilizce hem Arapça için yapılır.

### 3.2 İçsel ve Dışsal Yaklaşımlar

- **İçsel (intrinsic):** Yalnızca bölümlenecek dokümana dayanır. Örnekler: TextTiling, C99, LCseg, F06, TopicTiling.
  - LCseg sözcük tekrarlarını kullanır.
  - F06 ve TopicTiling, TextTiling'i temel alır. F06'nın farkı, benzerlik için kosinüs yerine Dice ölçütünü kullanmasıdır.
- **Dışsal (extrinsic):** Dış kaynakları da kullanır. Örnekler: LSI, birlikte geçme ağları (co-occurrence networks) ve üretici Bayes modelleri.

**Soru (hoca):** "İçsel" ile neyi anlayacağım?
**Cevap:** Bir doküman bölümlenecekse, içsel yaklaşımda yalnızca o dokümandaki bilgiler kullanılır. Dışsal yaklaşımda dış kaynaklar da kullanılabilir.

### 3.3 Karşılaştırılan Üç Temsil

**LSA.** Derste de görülen istatistiksel bir yöntemdir ve iki temel adımı vardır. Önce satırları terim, sütunları doküman olan terim-doküman matrisi kurulur. Sonra bu matris tekil değer ayrışımıyla (SVD) üç matrise ayrılır. Sonuç, sıklık eşiklerine, ağırlıklandırma fonksiyonuna ve anlamsal uzayın boyutuna bağlıdır. Yazarlardan birinin önceki çalışması parametre seçiminin bölümleme başarısını etkilediğini göstermiştir. Bu çalışmada da oradaki değerler kullanılır: yerel sıklık 3, küresel sıklık 1, yerel ağırlık TF, küresel ağırlık IDF.

**word2vec (Mikolov, 2013).** Kelimeleri bağlamlarına göre tahmin eden, sinir ağı tabanlı bir yöntemdir. Girdi, gizli ve çıktı katmanları vardır. İki biçimi vardır:

- CBOW: girdi bağlamdır, çıktı kelimedir.
- Skip-gram: girdi kelimedir, çıktı bağlamdır.

Mikolov'a göre skip-gram küçük eğitim verisinde iyi çalışır. CBOW ise daha hızlıdır ve sık geçen kelimelerde daha iyidir.

**GloVe (Pennington vd., 2014).** Kelime gösterimlerini öğrenir; word2vec'ten farklı olarak kelimelerin birlikte geçme sıklığını da kullanır. Önce birlikte geçme matrisi $X$ kurulur. $X_{ij}$, $j$ kelimesiyle birlikte geçen $i$ kelimesinin sıklığıdır. Sonra bir hata fonksiyonu en aza indirilir:

$$J = \sum_{i,j} f(X_{ij})\left(w_i^{T}\tilde{w}_j + b_i + \tilde{b}_j - \log X_{ij}\right)^2$$

Burada $w_i$ ve $\tilde{w}_j$ kelime vektörleridir.

### 3.4 Önerilen Bölümleme Algoritması

Algoritma beş adımdan oluşur:

1. **Ön işleme:** dil tespiti, durak kelimelerin çıkarılması, kök bulma.
2. **Sıklık sözlüğü:** Sözlük vektörlerden oluşur, her vektör bir cümleyle ilişkilendirilir. Anlamsal uzayda olmayan terim boş vektörle temsil edilir.
3. **Benzerlik matrisi:** Çiftler arasında benzerlik hesaplanır. Formül cümlelerin birbirine benzerliğini verir.
4. **Sıralama (rank) matrisi** kurulur.
5. **Konu sınırları** Reynar algoritmasıyla belirlenir.

### 3.5 Veri ve Değerlendirme

İngilizce için yalnızca bilgisayar bilimleri makalelerinden oluşan bir külliyat, Arapça için ekonomi, politika, sağlık gibi çeşitli konulardan bir külliyat kullanılır. Eğitim seti anlamsal uzayı kurmak, test seti LSA, word2vec ve GloVe'u değerlendirmek için kullanılır. Ölçüt WindowDiff'tir ve yüzde cinsinden hata oranıdır.

### 3.6 Sonuçlar

**word2vec ayarları.** Negatif örnekleme (negative sampling) ve hiyerarşik softmax da denenir:

| Dil | CBOW için iyi olan | Skip-gram için iyi olan |
| :--- | :--- | :--- |
| İngilizce | Negatif örnekleme | Hiyerarşik softmax |
| Arapça | Negatif örnekleme | Negatif örnekleme |

İngilizcede CBOW'un hatası daha düşüktür. Öğrenci bunu Mikolov'un sözüyle bağlar: külliyat tek alandan olduğu için aynı kelimeler çok tekrar eder ve CBOW sık kelimelerde iyidir. Arapçada skip-gram daha iyi sonuç verir.

**İngilizce karşılaştırması.** LSA en yüksek hatayı verir. word2vec ve GloVe birbirine çok yakındır. word2vec hem en küçük anlamsal uzaya hem de en düşük hataya sahiptir.

**Arapça karşılaştırması.** LSA'nın anlamsal uzayı diğerlerine göre çok büyüktür, hatası da yüksektir. En düşük ve en yüksek hata değerleri GloVe'dadır, ama ortalamada en iyi sonuç GloVe'dur.

**Yazarların açıklaması.** GloVe'un anlamsal uzayı word2vec'ten büyüktür ve bir kelimenin anlamını öğrenmek için daha çok bilgiye ihtiyaç duyar. Arapça gramer açısından çeşitli, biçimbilimsel olarak karmaşık bir dildir ve kelimelerin anlamını tespit etmek için de daha çok bilgi gerekir. Yazarlar, GloVe'un Arapçadaki başarısını buna bağlar.

**Arapçanın zorluğuna örnek.** Aynı kökten gelen "scientist" kelimesi ile çoğulu arasındaki kosinüs benzerliği düşük kalır: LSA 0,3, word2vec 0,05, GloVe 0,2. Aynı konudaki "medicine" ve "diagnosis" için oranlar daha da düşüktür; en iyisi 0,26 ile GloVe'dur. Slaytta yedi kelimenin anlamsal uzaydaki gösterimi vardır. Öğrenci, "scientist", "world" ve "universe" kelimelerinin Arapçada aynı kökten geldiğini aktarır.

> **Ek bilgi (derste anlatılmadı):** Bu örnek Arapçanın kök yapısını gösterir. "Âlim" (bilim insanı) ile "âlem" (dünya, evren) aynı üç harfli (ayın-lam-mim) kökten türer. İngilizce çevirilerinde bu bağ görünmez.

**İçsel ve dışsal yöntemler.** Çalışma önceki bölümleme çalışmalarıyla da karşılaştırılır. Her iki dilde dışsal yöntemler daha iyidir. Yazarlara göre dış bilgi eklemek bölümleme başarısını artırır. Diller arasında büyük fark vardır: İngilizcede en fazla %8 hata varken Arapçada hata %30'a kadar çıkar.

**Genel sonuç:**

- LSA iki dilde de en kötü sonucu verir.
- word2vec ve GloVe'un performansı birbirine yakındır, ama word2vec daha küçük uzayla iyi sonuç verir.
- İngilizce için word2vec, Arapça için GloVe daha iyidir.
- Karmaşık yapısı nedeniyle Arapçada başarı İngilizcenin gerisinde kalır.

**Hocanın yorumları.** Hoca, çalışmanın 2017 tarihli olduğunu öğrenince "BERT ekleseler durum değişirdi" der. Yazarların Arap olup olmadığını da sorar; öğrenci Tunus'taki bir laboratuvardan olduklarını söyler.

## 4. Üçüncü Sunum: Haber Makalelerinde Sözlük Tabanlı Duygu Analizi

### 4.1 Makale ve Motivasyon

Makale "Sentiment Analysis of News Articles: A Lexicon Based Approach" başlığını taşır ve iCoMET 2019 konferansında yayımlanmıştır. Basılı gazete ve dergiler yerini çevrim içi platformlara bırakmaktadır, çünkü etkileşim çok ve erişim kolaydır. Sosyal medyanın ürettiği büyük veri, duygu analizini popüler yapmıştır. Duygu analizinde iki popüler yaklaşım vardır: sözlük (lexicon) tabanlı yaklaşım ve denetimli/denetimsiz öğrenme.

### 4.2 Literatür

- New York Times, BBC, Reuters ve Daily Mail'den yaklaşık 69.907 manşet incelenir. Olumlu ve olumsuz başlıkların daha çok ilgi gördüğü bulunur.
- Çevrim içi haberleri sınıflandırmak için cümle düzeyinde, duygu kutupluluğunu dinamik bir sözlükten çıkaran bir yaklaşım.
- Finansal haberlerde sözlük tabanlı duygu analizi.
- Python paketleri ve SentiWordNet 3.0 ile görüş madenciliği.

### 4.3 Yöntem

Veri, BBC haber sitesinin 2004-2005 haberleridir. 2225 belge ve 5 kategori içerir: iş, eğlence, politika, spor, teknoloji.

1. **Ön işleme:** Gürültü ve yanlış yazılmış kelimeler temizlenir. RapidMiner ile tokenization yapılır. Noktalama atılır. Kelimelerin tamamı büyük harfe çevrilir. Durak kelimeler çıkarılır. Kök bulunur.
2. **Ağırlıklandırma:** Kelimeler TF-IDF ile ağırlıklandırılır.
3. **Duygu puanı:** Puanlar WordNet ve SentiWordNet ile atanır. Öğrenciye göre WordNet 118.000'den fazla kelime biçimi ve 90.000'den fazla kelime anlamı içerir.
4. **Etiket:** Toplam puan negatifse olumsuz, pozitifse olumlu, sıfırsa nötr etiketi verilir.

Kutupluluk belge, cümle ve kelime düzeyinde hesaplanır.

### 4.4 Sonuçlar

İş kategorisindeki 510 makalenin 274'ü olumlu, 205'i olumsuz, 31'i nötr çıkar. Sayıların toplamı 510'dur. Genel olarak iş ve spor kategorileri daha olumlu, eğlence ve teknoloji kategorileri daha olumsuz makalelerden oluşur.

Hoca, sunumun çok hızlı bittiğini söyler ve konuya "sevimsiz" der. Sebep bu konuların derste çok dinlenmiş olmasıdır, sıkıcı gelmesi sunucuyla ilgili değildir.

### 4.5 Türkçe ve Etiketli Veri Sorunu

Bir öğrenci kendi okuduğu yazıda, duygu analizinin İngilizce ve Çincede popüler olduğunu, Arapça ve İtalyancada duygu sözlüklerinin kısıtlı olduğunu aktarır. Önceki sunumda Arapçadaki hatanın yüksek çıkmasını da buna bağlar. Hoca şöyle cevaplar: Çalışmaların büyük çoğunluğu İngilizce üzerinedir, nüfusu büyük olduğu için Çincede de çok çalışma vardır. Öteki dillerde çalışma azdır. Türkçede birçok konuda etiketli bir veri seti bile yoktur.

> **Hocanın vurgusu:** Türkçe bir çalışma yayına gönderilince "Bunu hangi çalışmaya göre karşılaştırıyorsun, başarını neye göre kıyasladın?" diye sorulur. Türkçe başka bir dille de kıyaslanamayacağı için araştırmacı arada kalır. Veri setinin az olması ve çalışma sayısının kısıtlı olması başarıyı da düşürür.

## 5. Dördüncü Sunum: Türkçe Metin Sınıflandırma için Kelime Bölümleme

### 5.1 Problem

Makale, Türkçe kelimelerin metin sınıflandırma için nasıl bölünmesi gerektiğini inceler. Türkçe gibi biçimbilimsel açıdan zengin ve sondan eklemeli dillerde kelime dağarcığı çok büyür. Sinir ağlarını eğitmek zor ve maliyetlidir. Sözlük dışı kelime sayısının artması da sınıflandırıcının karar vermesini zorlaştırır.

Literatürde bu sorun için kelimeleri Byte Pair Encoding (BPE) ile önceden öğrenilmiş alt kelime (subword) birimlerine ayırma önerilmiştir. Bu yöntem hem kelime dağarcığını hem test süresini azaltır. Türkçe doküman sınıflandırmada daha önce biçimbilimsel, hece, boşluk tabanlı ve karma yaklaşımlarla dört yöntem incelenmiştir. Bu makale farklı alanlarda daha modern yöntemler dener. Amaç, bölümleme yöntemi seçiminin sınıflandırıcı başarısına etkisini araştırmaktır.

### 5.2 Bölümleme Yöntemleri

Makalede 16 yöntem denenir:

| Yöntem | Açıklama |
| :--- | :--- |
| Kelime tabanlı | Boşluklara göre bölünür. Yakın zamana kadar en yaygın yöntemdi. |
| Karakter tabanlı | Metin karakterlere bölünür. |
| Karakter n-gram | $n = 2, 3, 4, 5, 6, 7$ (6 yöntem). Bilgi çıkarımı ve metin sınıflandırmada sık kullanılır. |
| Gövde (stem) tabanlı | Kelimelerin ekleri çıkarılır. Snowball kök bulucu kullanılır. |
| Lemma tabanlı | Kelimelerin kökü bulunur. Zemberek kullanılır. |
| Biçimbilimsel | Her kelime dilbilgisi kurallarına göre biçimbirimlerine ayrılır. |
| Morfessor | Kelimeleri biçimbirim benzeri parçalara bölen denetimsiz bir algoritma. |
| BPE | Aslında bayt dizilerini birleştiren bir veri sıkıştırma algoritmasıdır. Burada bayt yerine karakter dizileri birleştirilir (2 yöntem). |
| WordPiece | Korece ve Japonca gibi boşlukla ayrılmayan diller için geliştirilmiş, sonra İngilizceye de uygulanmıştır. |
| Unigram dil modeli | Bir tür alt kelime bölümleme algoritmasıdır. |

Yöntem sayıları tabloda toplanınca 16 eder.

**Morfessor üzerine soru.** Hoca, yöntemlerin örnek bir cümle üzerindeki çıktılarını gösteren tablodan Morfessor satırını yeniden açtırır. Bölünen parçaların neye göre seçildiğini anlayamaz. Çekim eki, yapım eki ya da hece sınırına uymayan bölmeler görür. Öğrenci de bunu açıklayamadığını söyler. Hoca, "bunu incelemek lazım" diyerek konuyu kapatır.

<!-- BELİRSİZ: Örnek cümle ve yöntemlerin bölme çıktıları slaytta; altyazıda yalnız "kurul" parçası duyuluyor. -->

> **Ek bilgi (derste anlatılmadı):** Morfessor dilbilgisi kuralı kullanmaz. Derlemi en kısa biçimde kodlayacak parçaları istatistiksel olarak arar. Bu yüzden parçaları gerçek biçimbirim sınırlarına her zaman oturmaz; hocanın gördüğü durum bununla uyumludur.

### 5.3 Veri Setleri

- **Twitter duygu analizi:** Olumlu, olumsuz, nötr etiketleri. YTÜ Kemik Doğal Dil İşleme Grubu tarafından toplanıp etiketlenmiştir.
- **Film yorumları:** 4,5 puan üzeri olumlu, 1,5 puan altı olumsuz.
- **Haber:** YTÜ Kemik Grubu tarafından oluşturulmuştur.
- **Ürün yorumları:** Kaggle'daki Türkçe veri seti. 1-5 arası puan; 5 olumlu, 1 ya da 2 olumsuz.

### 5.4 Mimariler ve Deney

Üç mimari kullanılır: doğrusal model, CNN (100 çekirdek) ve iki katmanlı çift yönlü LSTM. Aşırı öğrenmeye karşı dropout, optimizasyon için Adam kullanılır. Donanım sınırı nedeniyle her girdi 256 token ile sınırlanır.

<!-- BELİRSİZ: Modellerin öğrenme oranı değerleri altyazıda bozuk. -->

Bölümlemeden önceki ön işleme adımları şunlardır: bağlantıları çıkarma, küçük harfe çevirme, alfabetik karakterleri noktalamadan boşlukla ayırma, birden çok boşluğu teke indirme, art arda tekrar eden karakterleri teke indirme.

Her deney daha güvenilir sonuç için 5 kez tekrarlanır. Tabloda ortalama F1 skorları ve parantez içinde standart sapmalar verilir.

### 5.5 Sonuçlar

Bölümleme yöntemi, alanla ve sinir ağı mimarisiyle uyumlu seçilmelidir. Sonuçlar şu şekilde özetlenir:

| Mimari | Normalize edilmiş metin | Normalize edilmemiş metin (tweet gibi) |
| :--- | :--- | :--- |
| Dizileri modelleyebiliyor | Biçimbilimsel analize dayalı bölümleme | Morfessor |
| Dizileri modelleyemiyor | BPE, WordPiece, unigram gibi yöntemler benzer sonuç verir | Karakter n-gram, özellikle $n=5$ |

<!-- BELİRSİZ: Son satırdaki yöntem adları altyazıda bozuk geçiyor ("BERT, PAYER, ENCLING, word2vec, borç"); kısa nottaki okumaya göre yazıldı. -->

Hoca, en iyi sonucu veren yöntemlerden birinin kendisinin anlayamadığı Morfessor olmasına yeniden dikkat çeker.

## 6. Beşinci Sunum: Cümle Tamamlama için Bağımlılık Tabanlı RNN Dil Modelleri

### 6.1 Makale ve Amaç

Makalenin adı "Dependency Recurrent Neural Language Models for Sentence Completion" şeklindedir. Yazarları Piotr Mirowski ve Andreas Vlachos'tur. ACL yayınıdır; öğrenci tarihi Aralık 2015 olarak verir. Amaç, daha önce RNN ile yapılmış cümle tamamlama çalışmasının başarısını artırmaktır. Bunun için bağımlılık ayrıştırmasının (dependency parsing) ürettiği ağaç ve kelime etiketleri kullanılır.

### 6.2 Dil Modelleri

Dil modelleri, doğal dildeki kelimelerin ve cümlelerin olasılık dağılımını hesaplar. Makine çevirisi, konuşma tanıma ve dilbilgisi düzeltmede kullanılır.

- **Sayıma dayalı (count-based) modeller:** Cümle olasılığını n-gram ile hesaplar. Geçmişte ağırlıklı olarak bunlar kullanılmıştır.
- **Sinirsel dil modelleri:** Her kelimeyi bir vektöre yerleştirir ve kelimenin öteki kelimelerle ilişkisini derin öğrenmeyle tanımlar. İşlemcilerin gelişmesiyle ağırlıklı olarak bunlar kullanılır ve daha iyi sonuç verir.

### 6.3 RNN

Bir sinir ağında girdi, gizli ve çıktı katmanları vardır. Sıradan bir ağda çıktılar birbirinden bağımsız düşünülür. Veri hava durumu ya da cümle gibi bir diziyse, önceki sonuç sonrakini etkileyebilir. Bu durumda RNN kullanmak daha mantıklıdır: önceki adımın gizli durumu her adımda ek girdi olur.

$$s(t) = f\big(U\,w(t) + W\,s(t-1)\big), \qquad y(t) = g\big(V\,s(t)\big)$$

Burada $s(t-1)$ önceki kelimenin sonucudur ve ağırlık matrisi $W$ ile çarpılır. Ek girdi olan $w(t)$ mevcut kelimedir. $U$ sözlükteki kelimeler için girdi kelime gömme matrisi, $V$ çıktı gömme matrisidir. $f$ sigmoid aktivasyon fonksiyonudur, $g$ softmax'tır ve olasılık sonuçlarını verir.

### 6.4 RNN ile Maksimum Entropi

İlk çalışmalar yalnızca RNN kullanır. Thomas Mikolov 2011'de n-gram ile RNN'i birleştirir ve daha iyi sonuç alır. RNN'in kelime olasılık matrisine kelimelerin n-gram sonuçları eklenir. Derlem çok büyükse n-gramları hesaplamak zorlaşır. Daha önce hesaplanmış bir n-gram bağlamını yeniden hesaplamamak için bir özet (hash) fonksiyonu kullanılır. Bu, hız kazandırır.

### 6.5 Bağımlılık RNN'i

Önceki RNN çalışması kelimeleri n-gram'a benzer biçimde sıralı bir dizi gibi işler. Bağımlılık RNN'i (dependency RNN) ise cümlenin ayrıştırma ağacını işler. Derlemdeki her cümle için bağımlılık ayrıştırmasıyla ağaç üretilir, ağaç RNN ile işlenir.

**Ata kelime (ancestor).** Bir kelimenin ataları, kökten başlayıp o kelimeye ulaşırken uğranan kelimelerdir. Cümlenin olasılığı, her kelimenin atalarına koşullu olasılıklarının çarpımıdır:

$$P(\text{cümle}) = \prod_{i} P\big(w_i \mid A(w_i)\big)$$

Öğrenci slayttaki ağaçtan bir örnek verir: Kökten başlanır, "binoculars" ve "strong" kelimelerine uğranır, sonra hedef kelimeye ulaşılır. Bunlar hedef kelimenin atalarıdır.

<!-- BELİRSİZ: Örnek cümle ve ağaç slaytta. Altyazıda kök "soft/so" ve hedef kelime "veri" diye geçiyor. -->

Sunumda hoca "ata" sözünü anlayamaz. Öğrenci İngilizcesini ("ancestor") söyleyince konu açılır. Hoca kavramı kendi sözleriyle toparlar:

> **Hocanın vurgusu:** Kastedilen, ağaçta o düğümden önce gelen, onun üstünde kalan düğümlerdir. Bir kelimenin olasılığı, ağaçta üstünde kalan kelimelerle birlikte kullanım olasılığıyla hesaplanır.

Öğrenci, terimleri Türkçeye çevirirken zorlandığını ve İngilizce ifadelerin daha anlaşılır olduğunu söyler.

### 6.6 Etiketli Bağımlılık RNN'i

Bağımlılık RNN'i, kelimenin özne, nesne ya da yüklem olması gibi dilbilgisi bilgilerini kullanmaz. Etiketli bağımlılık RNN'i (labeled dependency RNN) bu etiketleri de hesaba katar. Kelime olasılık sonuçlarını kelime etiketlerine bağlayan bir $G$ matrisi kullanılır. Önceki formüle $G$ ile kurulan bir terim eklenir. N-gram ve özet fonksiyonu burada da kullanılır.

<!-- BELİRSİZ: Etiketli modelin formülünün tam yazımı slaytta. -->

### 6.7 Veri ve Sonuçlar

Veri, 19. yüzyılda yazılmış 522 romandan alınan cümlelerdir. Sözlükte 72.846 kelime vardır. 1040 cümle test için kullanılır; bu veri Microsoft Research Sentence Completion Challenge verisidir. Cümle bölme, sözcük türü etiketleme ve ayrıştırma için Stanford CoreNLP kullanılır.

Karşılaştırma 2-gram, 3-gram ve 4-gram düzeylerinde yapılır. Normal RNN'e göre yaklaşık %10'luk artış görülür. Makale bu artışı öne çıkarır. Yazarlar projeyi GitHub'da açık kaynak olarak paylaşmıştır.

### 6.8 Basit Fikirler Üzerine Bir Konuşma

Öğrenci, makaleyi okurken Mikolov'un alana katkısına hayran kaldığını söyler. Hoca, çok basit fikirlerin başkaları tarafından bulunduğunu hatırlatır ve Kruskal algoritmasını örnek verir: çok kolay bir algoritmadır, "o buluyor da biz niye bulamıyoruz?" Öğrenci bunun sebebini, her şeyin bulunduğuna dair ön yargılara bağlar. Hoca ise "belki de tembeliz, öyle düşünmek işimize geliyor" der.

## 7. Altıncı Sunum: Haber Makalelerinde Doküman Düzeyinde Duygu Analizi

### 7.1 Makale ve Kavramlar

"Document Level Sentiment Analysis from News Articles" adlı bu makale 2017 tarihli bir konferans bildirisidir. BBC haber verisini kullanarak haberlerin olumlu mu olumsuz mu olduğuna karar vermeye çalışır. Duygu analizinin amacı, metin verisinin kutupluluğunu hesaplamaktır; bir kişinin bir konu hakkındaki fikrini belirlemeye çalışır. Veri kaynakları metinler, tweet'ler, bloglar, sosyal medya, haber makaleleri ve ürün yorumlarıdır.

Üç genel yöntem vardır:

- **Makine öğrenmesi:** Sınıflandırılmış veriyle eğitim yapılır, yeni verinin sınıfı saptanır.
- **Sözcük tabanlı:** Kutupluluğu belli bir kelime listesi kullanılır. Bu makalenin yöntemi budur.
- **Dilbilimsel analiz:** Kelime ve cümlelerin olumsuzluğu ve metnin yapısı kullanılır.

### 7.2 Duygu Analizi Düzeyleri

- **Doküman düzeyi:** Doküman bütün olarak analiz edilir ve tek bir olumlu ya da olumsuz sonuç çıkar. Yalnız bir ürüne ait yorumları içeren bir metinde işe yarar. Birden çok ürüne ait yorum içeren metinde düzgün çalışmaz, çünkü sonucun hangi ürüne ait olduğu bilinemez.
- **Cümle düzeyi:** Her cümle işlenir ve olumlu, olumsuz ya da nötr sonucu alır. Nötr cümleler duygu ya da fikir belirtmez.
- **Varlık ve görünüm (entity/aspect) düzeyi:** Özellik tabanlı duygu analizi olarak da adlandırılır. Görüş temellidir: bir duygudan (olumlu ya da olumsuz) ve bir hedeften oluşur. Hedefi olmayan görüşün kullanımı sınırlıdır.

### 7.3 Önerilen Sistem

Makale ön işlemenin önemini çok vurgular. Sistem beş aşamalıdır:

1. Temizleme: durak kelimeler gibi anlama etki etmeyen kelimeler çıkarılır.
2. Bütün kelimeler küçük harfe çevrilir.
3. Kök bulunur.
4. Köklerden terim-doküman matrisi kurulur.
5. Matris bir duygu sözlüğüyle karşılaştırılır, dokümana bir puan verilir. Puana göre haberin olumlu, olumsuz ya da nötr olduğuna karar verilir.

### 7.4 Sözlük Tartışması

Sözlük olarak altyazıda "Binkliyor" diye geçen bir olumlu-olumsuz kelime sözlüğü kullanılır. Hoca bunun ne olduğunu ve yazar adı olup olmadığını sorar. Öğrenci, makalede yalnızca bu adın geçtiğini söyler. Hoca atıf verilip verilmediğini sorar, öğrenci baktıktan sonra verilmediğini söyler. Hoca tepki gösterir: "Ne saçmalık!"

### 7.5 Sonuçlar ve Olumsuz Sonuç Tartışması

Veri, BBC veri setinin beş kategorisidir. İş kategorisinde 510 makalenin 262'si olumlu, 214'ü olumsuz bulunur, 34'ü hakkında karar verilemez. Sayıların toplamı 510'dur. Eğlence ve teknoloji gibi kategorilerde olumlu ve olumsuz sayılar birbirine çok yakın, bazen aynıdır.

Yazarlar, bu yöntemin bir makalenin olumlu ya da olumsuz olduğu hakkında kesin bilgi vermediği sonucuna varır. Gelecek çalışma olarak, cümle puanlarına dayalı makine öğrenmesi tekniklerini uygulamayı planlarlar.

Hoca şaşırır: "Ben boş bir çalışma yaptım mı demek istiyor?" Öğrenci, çalışmanın yöntemin kullanılabileceğinden çok kullanılamayacağını gösterdiğini söyler. Hoca bunun da bir sonuç olduğunu kabul eder.

> **Hocanın vurgusu:** "Bir şeyin olmayacağını da gösterirsin." Ama bir makale gelecek çalışma vaat ediyorsa, o çalışmanın yapılıp yapılmadığını araştırmak gerekir. Hoca öğrenciden 2017'den sonra böyle bir çalışma yapılıp yapılmadığına bakmasını ister.

## Dersin Toparlaması

Son haftanın sunumları, duygu analizi ve kelime temsili etrafında toplanır. Birinci sunum alanın genel haritasını verir: duygu modelleri, veri setleri ve dört ana yaklaşım. Üçüncü ve altıncı sunumlar aynı BBC verisi üzerinde sözlük tabanlı yöntemi işler. Üçüncü sunum yöntemin sonuç ürettiğini gösterir, altıncı sunum ise kesin karar vermekte yetersiz kaldığını öne sürer.

İkinci sunum, LSA, word2vec ve GloVe temsillerini konu bölümlemede karşılaştırır ve dil yapısının sonucu etkilediğini gösterir. Dördüncü sunum bu fikri Türkçeye taşır: sondan eklemeli bir dilde bölümleme yöntemi, alana ve mimariye göre seçilmelidir. Beşinci sunum ise kelime dizisi yerine bağımlılık ağacı kullanarak dil modelini iyileştirir.

Sunumlarda hocanın tekrar ettiği kaygılar şunlardır: verinin nereden geldiğine bakmak, kaynak göstermek, başarıyı neyle karşılaştırdığını bilmek ve Türkçe için etiketli veri eksikliği.

## Ders Sonrası Notlar

> **Ders sonrası not:** Birinci sunumda nevrotiklik "içine kapanık, sinirli" olmak, deneyime açıklık da "dışarıya dönük" olmak gibi anlatıldı. Beş faktör kişilik modelinde bunlar ayrı özelliklerdir: içine kapanıklık/dışa dönüklük ayrı bir boyuttur (extraversion). "Openness" deneyime açıklık demektir.

> **Ders sonrası not:** Sekiz duyguyu zıt çiftler olarak alan model altyazıda adlandırılmıyor. Tanım, büyük olasılıkla Plutchik'in modelidir; altyazıdan kesin değildir.

> **Ders sonrası not:** Emoji örneğinde kalp ve ağlama için verilen $+5$ ile $-2$ toplamı $+3$'tür, yani nötr değil olumludur. Kırık kalp ve ağlama ikisi de olumsuz puanlıysa toplam da olumsuz çıkar. Hocanın itirazının özü, emoji puanlarını toplamanın metnin anlattığı durumu kaçırabileceğidir. "Nötr" sonucu ise ancak puanlar birbirini götürürse çıkar.

> **Ders sonrası not:** İkinci sunumda yazarların "kullanılan dilden bağımsız olarak word2vec GloVe'dan daha iyidir" dediği aktarıldı. Bu, aynı sunumdaki "Arapça için GloVe daha iyidir" sonucuyla çelişiyor. Altyazıdan hangi anlamda söylendiği anlaşılmıyor; olası anlam, word2vec'in daha küçük anlamsal uzayla yakın sonuç vermesidir.

> **Ders sonrası not:** Arapçadaki en yüksek hata, ikinci sunumda %30 olarak söylendi. Üçüncü sunumun sonundaki tartışmada bir öğrenci "%36'ya kadar" dedi, ama kendisi de emin değildi. Doğrusu sunumdaki %30 kabul edilmiştir.

> **Ders sonrası not:** Hoca, Çincedeki çalışma çokluğunu Çin'in "dünya nüfusunun büyük çoğunluğunu" oluşturmasına bağladı. Çin nüfusu dünya nüfusunun yaklaşık altıda biridir; büyük bir pay, ama çoğunluk değildir.

> **Ders sonrası not:** Dördüncü sunumda altyazıda "over-optimization" geçen yer aşırı öğrenme (overfitting), "dizileri modelleyemiyorsa, LSTM" diye geçen yer ise büyük olasılıkla doğrusal modeldir. LSTM dizileri modelleyen mimaridir.

> **Ders sonrası not:** Beşinci sunumda sıradan sinir ağında "sonuçların girdilerden bağımsız" olduğu söylendi. Kastedilen, bir çıktının önceki adımların girdilerinden bağımsız olmasıdır; çıktı elbette kendi girdisine bağlıdır.

> **Ders sonrası not:** Beşinci sunumdaki ağaç örneğinde altyazıda "soft/so" ve "veri" geçen kelimeler, makalenin bilinen örneği "I saw the ship with very strong binoculars" ise "saw" ve "very" olmalıdır. Bu cümlede kök ana fiil "saw"dur. Öğrenci kökün seçimini "I" kelimesinin durak kelime olarak atılmasına bağladı ve makalede açıklama görmediğini söyledi. Bağımlılık ağacında kök genelde ana fiil olur, "I" ise fiile bağlı bir düğümdür. Örnek cümle slaytta olduğu için bu okuma kesin değildir.

> **Ders sonrası not:** Altıncı sunumda BBC verisinin "225 doküman" içerdiği ve her sınıfta "300-400 makale" olduğu söylendi. Üçüncü sunumda aynı veri 2225 dokümandır ve aynı sunumda iş kategorisi 510 makaledir. Doğru sayı büyük olasılıkla 2225'tir.

> **Ders sonrası not:** Üçüncü ve altıncı sunumlarda iş kategorisi için verilen sayılar (274/205/31 ve 262/214/34) farklı çalışmalara aittir; ikisi de 510 eder.

**Altyazıda bozuk geçen terimlerin doğru yazımları:**

- "International Server on Emotion" = ISEAR. "Fair Tales" = Fairy Tales. "Sam Ivali" = büyük olasılıkla SemEval.
- "Afin Leksikon" = AFINN benzeri bir puan sözlüğü. "VCPR" = büyük olasılıkla WCPR (kişilik tanıma çalıştayı).
- "B-Term Topic" = Biterm Topic. "Key Square" = ki-kare. "NaviPayas" = Naive Bayes.
- "Seabov", "Sibov", "C-Ball" = CBOW. "Sıkık gram", "Scriptgram", "Skit krem" = skip-gram.
- "World2Vac", "Word to Back" = word2vec. "Glob", "Glover" = GloVe. "LSE", "LST" = LSA.
- "TextTilling" = TextTiling. "LCSec" = LCseg.
- "IcomED" = iCoMET. "CentiWordNet" = SentiWordNet.
- "Morfesör", "morfolosur" = Morfessor. "White-Pair-Encoding" = Byte Pair Encoding. "Word PIS" = WordPiece. "Edeb" = Adam. "Q-Integram" = 5-gram.
- "kemik NLP/enerji grup" = YTÜ Kemik Doğal Dil İşleme Grubu.
- "Sentence Complulation", "Sentence Compression" = Sentence Completion. "Piotr Mirovski" = Piotr Mirowski. "Anchester" = ancestor. "Thomas Mikolov" = Tomas Mikolov. "Kurskal" = Kruskal.
- "Binkliyor" = büyük olasılıkla Bing Liu'nun görüş sözlüğü (opinion lexicon); altyazıdan kesin değildir.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
