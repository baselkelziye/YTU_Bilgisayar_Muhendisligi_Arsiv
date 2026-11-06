# Ders 12 Genişletilmiş Notu: Seminer Sunumları: Kelime Gömmelerinin İyileştirilmesi, Sosyal Mühendislik Tespiti, Çok Kipli Duygu Analizi ve ÖSYM Sorularının Çözümü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

> Bu ders öğrenci seminerlerinden oluşur. Konu anlatımı yoktur. Sunumlar sıra numarasıyla anılır, sunum yapan öğrencilerin adları yazılmaz. Slaytlarda kalan bazı adlar kısa nottan alınmıştır.

## İçindekiler

- 1. Dersin Yapısı
- 2. Birinci Sunum: Duygu Analizi için Kelime Gömmelerinin İyileştirilmesi
- 3. İkinci Sunum: Sosyal Mühendislik Saldırılarının Tespiti
- 4. Üçüncü Sunum: Derin Öğrenme ile Çok Kipli Duygu Analizi
- 5. Dördüncü Sunum: Sosyal Medyada Duygu Analizi ve Tahmini (Polaris)
- 6. Beşinci Sunum: ÖSYM Sözel Sorularının Doğal Dil İşleme ile Çözülmesi
- 7. Sunumlardan Çıkan Genel Dersler

## 1. Dersin Yapısı

31 Aralık 2020 tarihli bu kayıtta beş öğrenci seminer sunar. Her sunumda bir makale ya da tez incelenir. Hoca sunumlar sırasında araya girer, anlaşılmayan yerleri sordurur ve kendi deneyimlerini ekler.

Sunumların konuları birbirine yakındır. Üçü duygu analiziyle ilgilidir. Biri makine öğrenmesini güvenlik problemine uygular. Sonuncusu metin benzerliği ölçütlerini Türkçe sınav sorularına uygular.

## 2. Birinci Sunum: Duygu Analizi için Kelime Gömmelerinin İyileştirilmesi

İncelenen makale "Refining Word Embeddings for Sentiment Analysis" başlıklıdır. 2017'de yayımlanmıştır.

### 2.1 Problem ve Motivasyon

Kelime gömmeleri (word embedding) kelimelerin anlamsal bilgisini yakalar. Duygu bilgisini ise tam yakalayamaz. Zıt duygulu kelimeler benzer vektörler alabilir.

Kelime gömme yöntemleri genelde denetimsizdir (unsupervised). Daha önceki iyileştirme çalışmaları ise veriyi etiketlemek zorunda kalmıştır. Bu makalenin yazarları iyileştirmeyi otomatik yapan bir yöntem geliştirir. Temel amaç, aynı duyguya sahip kelimelerin vektörlerinin birbirine yakın olmasıdır.

### 2.2 Veri Seti

Duygu analizinde çok kullanılan Stanford Sentiment Treebank veri seti kullanılır. İki tür sınıflandırma yapılır:

- **İkili sınıflandırma:** olumlu, olumsuz.
- **Ayrıntılı sınıflandırma:** çok olumlu, olumlu, nötr, olumsuz, çok olumsuz.

### 2.3 word2vec

Makale word2vec ve GloVe'u kullanır, ama anlatmaz. Sunucu bu yüzden ikisini kısaca tanıtır.

word2vec denetimsiz ve tahmin tabanlı bir yöntemdir. Ana parametresi pencere boyutudur (window size). Pencere boyutu, ortadaki kelimenin sağında ve solunda kaç kelimeye bakılacağını belirler. Pencere boyutu 3 ise ortadaki kelimenin iki yanında üçer kelime yer alır.

word2vec'in iki yöntemi vardır. Farkları, penceredeki kelimelerin girdi ve çıktı olarak nasıl kullanıldığıdır:

- **CBOW:** Merkezde olmayan kelimeler girdidir. Merkezdeki kelime çıktıdır, yani tahmin edilir.
- **Skip-gram:** Merkezdeki kelime girdidir. Merkezde olmayan kelimeler tahmin edilir.

Sunucu, pencere boyutu 1 olan bir örnekle işleyişi gösterir. Örnek cümle slayttadır. Başta "bir", ardından "yandan" gibi kelimeler geçer.

<!-- BELİRSİZ: Örnek cümlenin tamamı slaytta. Altyazıda yalnız "bir", "yandan" ve "daha" kelimeleri okunuyor. -->

Örneğin işleyişi şöyledir:

1. İlk adımda ortadaki kelime "bir" olur. Solunda kelime yoktur. Sağında "yandan" vardır.
2. Pencere bir kelime kaydırılır. Ortadaki kelime "yandan" olur. Solunda "bir", sağında "daha" vardır.
3. Cümle bitene kadar pencere kaydırılmaya devam eder. Yöntem, cümlenin sonunda kendiliğinden durur.

CBOW'da her adımda komşular girdi, ortadaki kelime çıktı olur. Skip-gram'da ise ortadaki kelime verilir ve komşular tahmin edilir.

Bu makale skip-gram kullanır. Sunucuya göre CBOW daha az veride, skip-gram daha çok veride kullanılır ve skip-gram daha çok işlem gerektirir (bu konuda bkz. Ders Sonrası Notlar).

### 2.4 GloVe

GloVe, "Global Vectors" adındaki bir yöntemdir. Pennington ve arkadaşlarının 2014 tarihli çalışmasıdır.

Sunucu iki yöntemi şöyle ayırır. word2vec yerel istatistiklere dayanır: gördükçe öğrenir. GloVe ise küresel istatistiklere de bakar: bir kelimenin tüm metinde ne kadar geçtiğini kullanır.

GloVe bir birlikte geçme (co-occurrence) matrisi kurar. Bu matris, hangi kelimenin hangi kelimeyle bağlam içinde kaç kez birlikte geçtiğini gösterir. Yöntem istatistiği bu matristen öğrenir.

Sunucunun verdiği örnekte katı (solid) kelimesi buz (ice) ile birlikte yüksek olasılıkla geçer. Su ile buhar da birlikte sık kullanılır. "solid ile ice" olasılığı "solid ile steam" olasılığına oranlanınca oran çok büyük çıkar. Buradan "buz katı olarak bulunur" anlamı çıkarılır.

### 2.5 Önerilen Yöntem

Yöntem hedef kelime üzerinden anlatılır. Slaytta hedef kelime "good" kelimesidir.

1. Kosinüs benzerliği ile hedefe en yakın $k=10$ kelime bulunur. Listede "bad" gibi zıt duygulu kelimeler de vardır. Bunlar aslında orada olmaması gereken kelimelerdir.
2. Kelimelere bir duygu sözlüğünden puan verilir. Puanlar 1 ile 9 arasındadır. 9 en olumlu, 1 en olumsuzdur.
3. Komşular bu puana göre yeniden sıralanır. Zıt duygulu kelimeler listenin sonuna düşer.
4. Hedef vektör güncellenir. Zıt duygulu kelimelerden uzaklaştırılır, aynı duygulu kelimelere yaklaştırılır.

<!-- BELİRSİZ: Güncelleme denklemleri ve gösterilen vektör grafiği slaytta. Altyazıda denklemlerin açık biçimi okunmuyor. Sıralamadaki diğer zıt kelime "LOSİ/LUSSE" diye geçiyor; hoca da bu kelimenin anlamını bilmediğini söylüyor. -->

**Hocanın açıklaması.** Hoca sunumu durdurup önceki slayta döndürür ve konuyu kendi sözleriyle özetler. "good" ve "bad" aynı cümle yapılarında geçer. Bu yüzden vektörleri birbirine yakın olur. Oysa zıt anlam taşırlar. Elde 1-9 arası puanlayan ayrı bir kaynak vardır. Kelimeler bu kaynağa göre sıralanınca "bad" sıranın sonuna düşer. Sonra bir formül yardımıyla "good", zıt kelimelerden ayrılıp kendisine yakın vektörlere doğru götürülür.

**Soru:** Hoca sorar: "Başka bir takım vektörler çıkıyor dedin, o bölümü bir daha anlatır mısın?"

**Cevap:** Sunucu şöyle açıklar. Yalnız "good" örneğine bakıldığında sorun görünmez. "good" güncellendikten sonra başka bir olumlu kelime denendiğinde, o kelime de aynı konuma gelmeye başlamıştır. Yani farklı kelimeler için birbirine çok benzer yeni vektörler oluşur. Bunu önlemek için ilk denkleme bir ek yapılır: orada zaten bir vektör varsa yeni vektör biraz daha kaydırılır.

Yöntemin ikinci aşaması buna dayanır:

- Denkleme vektörün bir sonraki konumunu gösteren $v_i^{t+1}$ terimi eklenir.
- $\alpha$ ve $\beta$ parametreleri eklenir. Bu parametreler ilgili terimi devre dışı bırakmaya ya da çalıştırmaya yarar. Bu çalışmada ikisi de bütün işlemler boyunca $0{,}1$ alınır.
- Türev almayı kolaylaştırmak için kelime vektörü boyunca farklar kullanılır.
- Sonunda bir sonraki $v_i^{t+1}$ değerini hesaplayan yinelemeli bir yordam yazılır.

### 2.6 Karşılaştırma ve Sonuçlar

Klasik word2vec ile iyileştirilmiş word2vec, klasik GloVe ile iyileştirilmiş GloVe karşılaştırılır. Sunucu, listedeki "High Rank" diye geçen yöntemin karşılaştırmada etkisi olmadığını söyler. Yazarlar onu açık kaynak olduğu için eklemiştir.

Sınıflandırıcı olarak CNN, çift yönlü LSTM ve slaytta üçlü LSTM (Tri-LSTM) diye geçen bir model kullanılır.

**Soru:** Hoca sorar: "Çok ayıp olacak ama ben bu Tri-LSTM'e hiç rastlamamıştım."

**Cevap:** Sunucu da ilk kez burada gördüğünü söyler. Makalede ayrıntı verilmemiştir. Hoca, yazarların ek bir şey yapıp bu adı vermiş olabileceğini, bunu bilemeyeceklerini söyler (bkz. Ders Sonrası Notlar).

Sonuçlar şöyledir:

- İyileştirilmiş modeller her seferinde daha iyi sonuç verir.
- Artış ortalama olarak ikili sınıflandırmada yaklaşık 1,7, beşli sınıflandırmada yaklaşık 1,6 yüzde puandır. Sunucuya göre bu çok küçük bir farktır.

Sunucunun dikkatini çeken asıl nokta gürültüdür. Gürültü, seçilen 10 kelime içinde kaç tanesinin zıt anlamlı olduğudur. word2vec'te gürültü %24'tür, yani 10 kelimenin ortalama 2,4'ü zıt anlamlıdır. İyileştirilmiş modelde bu oran %14'e iner. Sunucu, başarı artışının en büyük nedeninin bu azalma olduğunu düşünür: zıt kelime azaldıkça başarı yükselir.

Yazarlar, daha iyi duygu gömmelerinin performansı artırdığı ve gürültüyü azalttığı sonucuna varır. Daha derin analiz için yeni deneyler yapılacağını söyler.

> **Hocanın vurgusu:** Çalışmadaki problem bilinen bir problemdir ve onunla çok sayıda uygulama yapılır. Başarıyı biraz daha artırmak için "şu noktaya dikkat etmemiz gerekir" denir ve o noktada iyileştirme yapılır. Bilinen yöntemlere yapılan küçük katkılar da bir araştırma yoludur.

## 3. İkinci Sunum: Sosyal Mühendislik Saldırılarının Tespiti

İncelenen makale 2020'de IEEE'de yayımlanmıştır. Konusu, doğal dil işleme ve makine öğrenmesi ile sosyal mühendislik saldırılarının tespitidir. Yazarlar uygulamaya SEADer++ v2 adını verir (Social Engineering Attack Detection). Aynı ekip daha önce SEADer++ adlı ilk sürümü ve benzer bir çalışmayı yayımlamıştır.

### 3.1 Sosyal Mühendislik Saldırısı Nedir?

Sosyal mühendislik saldırıları siber uzayda sık görülen saldırılardır. Sunucuya göre bunlar bir siber saldırının ön aşaması sayılabilir. Amaç, hedef kişiden saldırıda işe yarayacak bilgileri insan zaafları kullanarak almaktır. Teknik bilgi gerektirmediği için sık başvurulur.

Sunucunun örneği, "savcılıktan arıyoruz" yalanıyla insanlardan para istenmesidir. Sunucu, bunun bilgi almaktan çok para almaya yönelik olduğunu da belirtir.

> **Hocanın vurgusu:** Hoca araya girip kendi başından geçen bir olayı anlatır. Bir yakınının hesabından gelen mesajda hastanedeki bir hasta için yardım toplandığı yazıyordur. Hoca sorular sorar, mantıklı cevaplar alır ve para gönderir. Sonra şüphelenip kişiye ailesiyle ilgili bir soru sorar ve cevap alamaz. Hesabın ele geçirildiği sonradan anlaşılır. Hocanın çıkardığı ders şudur: "Ben bilirim" havasına girmemek gerekir. Bu saldırılar insanın boş bir anına denk gelir.

### 3.2 Veri Seti

Ham veri, hedef kişilere gönderilmiş, kurumsal e-posta gibi görünen ya da çevrim içi yazışma uygulamalarından alınmış metinlerdir. Sunucu, verinin kısıtlı olmasından dolayı yarısının sentetik olduğunu tahmin eder: yarısı yazarlar tarafından üretilmiş, yarısı gerçektir. Etiketler saldırı için 1, saldırı olmayan için 0'dır.

### 3.3 İlgili Çalışmalar

Sunucu önceki çalışmaları şöyle özetler:

- 2005 tarihli erken bir çalışma konuyu daha çok sosyolojik yönden ele alır.
- Bir çalışma, fiil-isim çiftlerinden oluşan bir veri tabanıyla özel bilgi isteyen soruları belirlemeye çalışır.
- İki çalışma, saldırıyı hafifletmek için durum makineleri kullanır.
- Bir çalışma, diyalogların anlam bilimini geliştiren bir çözüm sunar.
- Bir çalışma, insanın bu süreçteki en zayıf halka olduğunu gösterir.

### 3.4 Ön İşleme ve Skorlar

Yöntemin çerçevesi üç aşamalıdır: ön işleme, model seçimi, modelin uygulanması. Çalışmayı öncekinden ayıran şey ön işleme adımlarıdır. 14 adımın ilk 12'si önceki çalışmayla aynıdır. Son iki adım performans etkisini ölçmek için eklenmiştir.

Ön işleme üç skor üretir. Hepsi 0 ile 1 arasına ölçeklenir.

**Bağlantı skoru ($S_L$).** Bu skor 1-5. adımlarda hesaplanır.

1. Metinden regex deseniyle URL çekilir.
2. URL, Web of Trust API'sine gönderilir.
3. API iki değer döndürür: 0-100 arası bir itibar değeri (reputation value) ve 17 kategoriden biri.

Kategoriler ilk rakama göre gruplanır:

| İlk rakam | Anlamı | Örnekler |
| :--- | :--- | :--- |
| 1 | Olumsuz | 101 kötü amaçlı yazılım (malware), 103 oltalama (phishing), 104 dolandırıcılık (scam) |
| 2 | Şüpheli | 201 yanıltıcı bilgi, 205 spam, 207 reklam açılır pencereleri |
| 3 | Nötr | çevrim içi izleme (online tracking), tartışmalı içerik (controversial) |
| 5 | Olumlu | sorunsuz site |

Kategori 1 ya da 2 ile başlıyorsa bağlantı doğrudan kötü sayılır ve $S_L = 1$ olur. Kategori 3 ya da 5 ile başlıyorsa itibar değeri kullanılır:

$$S_L = 1 - \frac{\text{itibar}}{100}$$

**Yazım skoru ($S_{SP}$).** Bu skor 6-7. adımlarda hesaplanır. SymSpellPy kütüphanesi ile metindeki yanlış yazılmış kelime sayısı $x$ bulunur. Yazarlar kötü yazılmış bir metni saldırı belirtisi sayar. Sunucu, makalede bunun neden ayırt edici olduğunun gerekçelendirilmediğini belirtir. Skor üstel bir fonksiyonla ölçeklenir:

$$S_{SP} = 1 - e^{-\alpha x}$$

Denemeler sonunda en iyi değer $\alpha = 0{,}5$ bulunur. Slaytta $x=1$ ve $x=5$ için değerler gösterilir. Bu $\alpha$ ile $x=1$ için $S_{SP} \approx 0{,}39$, $x=5$ için $S_{SP} \approx 0{,}92$ olur (ara adım eklendi).

**Niyet skoru ($S_I$).** Bu skor 8-11. adımlarda hesaplanır ve yazımı düzeltilmiş metin üzerinde çalışır. İki eşleşme sayısı tutulur:

- $M_B$: Metnin, 48 kelimelik bir güvenlik politikası sözlüğünden türetilen kara listeyle eşleşme sayısı. Listede "password", "credentials", "database" gibi kelimeler vardır.
- $M_O$: Metnin, kişiyi belli bir hedefe yönelten ya da paniğe sevk eden kelimelerle eşleşme sayısı. Örnekler "must", "need", "urgent" kelimeleridir.

İki değer ağırlıklarla çarpılıp $x$ eşleşme değeri bulunur. Aynı üstel fonksiyonla ölçeklenir. Burada en iyi değer $\alpha = 0{,}4$ çıkar.

<!-- BELİRSİZ: $M_B$ ve $M_O$ ağırlıklarının değerleri ve birleştirme denkleminin açık biçimi slaytta. -->

**Yeni adım: Konu modellemesi.** Çalışmanın yeni katkısı LDA (Latent Dirichlet Allocation) kullanımıdır. LDA ile üç konulu bir konu modellemesi yapılır. Üç konu olasılığı veri setine öznitelik olarak eklenir.

> **Ek bilgi (derste anlatılmadı):** LDA, her belgeyi konuların bir karışımı, her konuyu da kelimeler üzerinde bir olasılık dağılımı olarak modeller. Konu sayısı önceden verilir. Modelin çıktısı, her belge için konuların olasılıklarıdır. Bu makalede bu üç olasılık doğrudan öznitelik olarak kullanılmıştır.

Sunucu veri setini ekranda gösterir. Son hâlin sütunları şunlardır: niyet skoru, yazım skoru, bağlantı skoru, üç konu olasılığı ve etiket.

### 3.5 Model Seçimi ve Sonuçlar

Bir topluluk yöntemi, bir yapay sinir ağı ve bir klasik yöntem denenir: rastgele orman (Random Forest), çok katmanlı algılayıcı (Multilayer Perceptron) ve K en yakın komşu (KNN). Doğrulamada 5 katlı çapraz doğrulama, ölçümde doğruluk (accuracy) ve kesinlik (precision) kullanılır. En iyi sonucu her iki ölçütte de Random Forest verir.

Sonra Random Forest optimize edilir: 10 ve 100 ağaçlı modeller karşılaştırılır. 100 ağaçlı model çok az daha iyidir. Yeni yöntem, önceki çalışmanın yöntemiyle 100 ağaçlı Random Forest üzerinde karşılaştırılır:

| Ölçüt | Önerilen yöntem | Önceki çalışma |
| :--- | :---: | :---: |
| Doğruluk | %80,1 | %78,4 |
| Kesinlik | %79,7 | %80,1 |
| AUC | yaklaşık 0,9 | slaytta |

<!-- BELİRSİZ: Önceki çalışmanın AUC değeri slaytta; altyazıda yalnız önerilen yöntemin yaklaşık 0,9 olduğu söyleniyor. -->

Kesinlikte önceki yöntem çok az daha iyidir. Yazarlar yine de konu modellemesini eklemenin performansı artırdığı sonucuna varır.

Gelecek çalışma olarak bulanık mantık (fuzzy logic) tekniklerinin tespit kalitesine etkisi araştırılacaktır. Sunucunun kişisel tahmini, bunun LDA'nın üç sınıflı olasılık dağılımı yerine bulanık küme üyeliği olarak kullanılabileceğidir.

## 4. Üçüncü Sunum: Derin Öğrenme ile Çok Kipli Duygu Analizi

İncelenen makale 2018'de IEEE International Conference on Machine Learning and Applications konferansında yayımlanmıştır.

### 4.1 Motivasyon

Duygu analizi çoğunlukla metin üzerinde yapılır. Sosyal medyada ise görüntü, video ve ses paylaşımı çok artmıştır. Video için YouTube ve Dailymotion, görüntü için Facebook, Instagram ve Flickr, ses için podcast'ler örnek verilir. Bu nedenle farklı kiplerden (modality) görüş çıkarmak ve duygu tahmini yapmak önem kazanır. Makale, görsel tanıma ve doğal dil işleme içeren derin sinir ağlarıyla bu probleme yaklaşır.

### 4.2 Literatür

Sunucu önce iki kaynağı anar: çok kipli duygu analizi veri setlerini, tekniklerini ve zorluklarını inceleyen bir derleme (survey) ve farklı kiplerin sonuçlarını bütünleştirmenin zorluklarını inceleyen bir çalışma.

Çok kipli bir sistem iki adımda ele alınır: her kipten ayrı özellik çıkarımı ve bu özelliklerin birleştirilmesi. Metinden duygu çıkarımı hem akademide hem endüstride çok kullanılır. Şirketler ürünleri hakkındaki düşünceleri, siyasi partiler seçmen görüşlerini anlamak için bunu kullanır. Haberler, bloglar, tweet'ler ve müşteri yorumları veri kaynağıdır.

Çok kipli birleştirmenin önündeki büyük engel, farklı kaynaklardan gelen bilgiyi farklı zaman ölçekleri ve ölçüm değerleri üzerinde bütünleştirmektir. İki ana strateji vardır:

- **Özellik düzeyinde birleştirme:** Başta sınıflandırma yapılmaz. Her kanaldan çıkarılan özellikler ortak bir vektörde birleştirilir. Farklı girdi özelliklerini bütünleştirmek zorluk yaratır.
- **Karar düzeyinde birleştirme:** Her kip bağımsız modellenir ve sınıflandırılır. Tek kipli sonuçlar istatistiksel ağırlıklandırmayla süreç sonunda birleştirilir.

Anılan bir çalışma iki stratejiyi de dener ve karar düzeyinde birleştirmeyi daha başarılı bulur.

### 4.3 Zorluklar

- Tweet gibi kısa metinler karakter sınırı yüzünden az bağlam içerir. Metin madenciliği araçları için zor bir türdür.
- Blog ve makale gibi uzun metinlerde değişen ve çelişen görüşler olabilir.
- Görüntülerde anlam belirten belirteçler azdır. Bilgisayarlı görmenin elde ettiği piksel grupları ile duygu analizinin gerektirdiği kavram düzeyi arasında anlamsal bir boşluk (semantic gap) vardır.

### 4.4 Veri Setleri

| Veri seti | İçerik | Boyut |
| :--- | :--- | :--- |
| Large Movie Review | İkili duygu sınıflandırması için film yorumları | Sunumda 20.000 eğitim, 5.000 test; ayrıca etiketsiz veri |
| Twitter görüntü veri seti | Olumlu ya da olumsuz etiketli görüntüler | 1269 görüntü: 969 eğitim, 300 test |
| MOSI (Multimodal Corpus of Sentiment Intensity) | Her biri $-3$ ile $+3$ arasında duygu puanlı video klipler | 2.199 klip |

### 4.5 Uygulamalar ve Sonuçlar

Makalede iki uygulama gerçekleştirilir.

**Uygulama 1: Metin.** Film yorumları üzerinde iki model karşılaştırılır:

| Özellik | RNN (LSTM) modeli | CNN modeli |
| :--- | :--- | :--- |
| Önceden eğitilmiş gömme | Yok | GloVe (300 boyut, 840 milyar token) |
| Gizli birim | 512 | - |
| En fazla token | 250 | 200 |
| Kayıp fonksiyonu | Ortalama kare hata (MSE) | İkili çapraz entropi |
| Eğitim ayarı | Öğrenme oranı 0,001 | Adadelta |

CNN çok az daha iyi doğruluk verir (yaklaşık %88,53). Sonuç, önceden eğitilmiş gömme kullanmanın avantaj sağladığını gösterir.

**Uygulama 2: Görüntü.** Twitter görüntülerinden özellikler çıkarılıp bir CNN'e verilir. Yapı 3 evrişim katmanı ve maksimum havuzlamadan oluşur. Kayıp MSE, optimize edici Adam'dır. Başarı metne göre çok daha düşüktür.

<!-- BELİRSİZ: Görüntü modelinin başarısı altyazıda bozuk ("167"); kısa nottaki gibi yaklaşık %67 olduğu anlaşılıyor, kesin değil. Sonuç tablosunun kendisi slaytta. -->

Makalede ayrıca ikinci bir CNN modelinde metin yönteminin aktarıldığı ve başarının arttığı söylenir. Gelecek çalışma olarak metin ve görüntüyü birleştiren çok kipli bir modelin tek kipli modellerden iyi olup olmadığına bakılacaktır.

### 4.6 Tartışma: Görüntüden Duygu Nasıl Çıkarılır?

**Soru:** Hoca sınıfa sorar: "Metinden duyguyu çıkarabiliyorum. Görüntüden duygu çıkarmak için ancak yüz resmi gibi bir şey olmalı. Başka görüntüden bunu nasıl yapabilirim?"

**Cevap:** Bir öğrenci, etiketlemenin başta insan tarafından yapılmış olması gerektiğini söyler. Olumlu ya da olumsuz etkisi açık görüntüler seçilmiş olabilir: hastanede yatan bir hasta olumsuz, gülüp eğlenen insanlar olumlu sayılabilir. Sevilen ya da sevilmeyen bir kişinin resmi de buna göre etiketlenmiş olabilir. Öğrenci bunun tahmin olduğunu, makalenin ayrıntısına bakmadığını belirtir.

Hoca etiketlemenin bile öznel olduğunu söyler: yağmurlu bir manzara birisi için güzel, başkası için kasvetlidir. Sunucu da kullanılan veriye bakacağını söyler. Soru derste kesin bir cevaba bağlanmaz.

## 5. Dördüncü Sunum: Sosyal Medyada Duygu Analizi ve Tahmini (Polaris)

İncelenen makale "sosyal medya içeriğine dayalı duygu analizi ve tahmin sistemi" konusundadır ve 2018'de yayımlanmıştır.

### 5.1 Motivasyon

Sosyal medya, olaylar ve doğal afetler hakkında ilk elden bilgi verir. Kullanıcıların yazdığı metinler doğrudan ve önemli bilgi taşıyabilir. İçeriğin oluşma zamanı da analiz için önemlidir. Farklı bölgelerdeki insanların duyguları incelendiğinde bir olayla ilgili birçok bilgi elde edilir. Yayılma yollarından olayın yönü çıkarılabilir.

İçerik gerçek zamanlı ve büyük hacimlidir. Bu yüzden verimli bir veri yönetim sistemi gerekir. Bu çalışmada AsterixDB tercih edilir.

Duygu analizi teknikleri sözlüğe dayalı ve makine öğrenmesine dayalı olarak ikiye ayrılır.

### 5.2 Polaris Sistemi

Polaris, olayları gerçek zamanlı algılar, yörünge analiziyle olayın yolunu çıkarır, duyguları CNN ile sınıflandırır ve sonraki duyguyu tahmin eder.

Çalışma, kar yağışıyla ilgili duyguların zaman içindeki değişimini örnek alır. Haritada olumlu duygular mavi, olumsuz duygular kırmızı gösterilir. Düğümlerin boyutu, anahtar kelimenin o bölgede kaç kez geçtiğini gösterir.

### 5.3 Olay Tespiti ve Yörünge

1. Başlangıç anahtar kelimeleri seçilir. Makaledeki örnekler suç, af ve kaza ile ilgili kelimelerdir.
2. Kelimeler ODP sınıflandırmasına göre toplanır.
3. Belirli bir zaman dilimindeki makaleler taranarak başlangıç kelimeleri genişletilir. 2015'ten itibaren yayımlanan makaleler kullanılır.
4. Anahtar kelimeyi içeren içerikler önce meydana geldikleri bölgeye, sonra oluşma zamanına göre sınıflandırılır.
5. Böylece her zaman dilimindeki sınıflar sıralanır ve anahtar kelimenin yolu ortaya çıkar.

<!-- BELİRSİZ: Olay tespiti süreci, yörünge örneği ve zaman penceresi şekilleri slaytta. -->

### 5.4 Duygu Sınıflandırma ve Tahmin

**Sınıflandırma.** Cümle sınıflandırma için CNN kullanılır. Cümledeki kelimeler word2vec ile vektörleştirilir. Böylece cümle, görüntü gibi iki boyutlu bir girdi olur. Eğitim verisi Sentiment140'tır: 800.000 olumlu ve 800.000 olumsuz etiketli tweet.

**Tahmin.** Zaman penceresi 7 gün alınır. Pencere boyunca gözlenen duygulara göre bir sonraki dönemin duygusu LSTM ile tahmin edilir. Böylece bir olayın beklendiği yerdeki duygu önceden kestirilebilir.

### 5.5 Deneyler ve Sonuçlar

Deney verisi Nisan 2016'ya ait bir aylık tweet verisidir. Bu verinin içinden yaklaşık 10 milyon anlamlı tweet kullanılır. Görselleştirme Google Haritalar animasyonlarıyla yapılır.

Örnek olarak kar ve kasırga ile ilgili duygu yörüngeleri gösterilir. ABD'de kuzeye doğru gidildikçe Nisan başında kar yağışı görülür. Sunucuya göre sistem, yörüngeleri gerçek hareket yollarına benzer biçimde yansıtır.

Doğruluk ölçümleri şöyledir:

- Duygu modeli, eğitim dışı 100.000 olumlu ve 100.000 olumsuz tweet ile test edilir. Doğruluk yaklaşık %84'tür.
- Geleneksel teknikler iyi çalışsa da en iyi doğruluk CNN ile elde edilir.
- Yetersiz veriye sahip anahtar kelimelerde hata oranı daha yüksektir.
- Artan iterasyon her zaman hatayı azaltmaz. Sunucu, 1500 ve 4500 iterasyon sonuçlarını karşılaştırır.

<!-- BELİRSİZ: Kelime boyutuna göre doğruluk tablosu ve iterasyon grafiklerinin değerleri slaytta. -->

Yazarlar, eğitim verisi artırılırsa sonuçların iyileşebileceği sonucuna varır. Sunucu da bir aylık verinin yetersizliğini vurgular. Sistem deprem ve tsunami gibi durumlarda iletişim kanalı ve kaza bilgilendirme servisi olarak, ayrıca pazarlamada kullanılabilir.

### 5.6 Tartışma

Bir öğrenci, aynı yöntemin bir etiket (hashtag) üzerinden uygulanabileceğini önerir. Bir etikete binlerce tweet atılır ve bunlar günlere yayılır. İnsanların görüşünün zamanla değişip değişmediği izlenebilir. Sunucu, veri miktarının yine önemli olduğunu hatırlatır.

> **Hocanın vurgusu:** Kar örneği çok güzel bir örnektir. Kar ilk başta insanların hoşuna gider. Süre uzadıkça moraller bozulur. Şekildeki yüz ifadeleri de ilk zaman diliminde mutludur, sonra bazıları iyiden kötüye döner.

Hoca sunum sonunda bir de biçim uyarısı yapar: referans ve kaynak aynı şeydir. Slaytta ikisinden biri kullanılmalıdır.

## 6. Beşinci Sunum: ÖSYM Sözel Sorularının Doğal Dil İşleme ile Çözülmesi

Bu sunumda bir makale yerine yüksek lisans tezi incelenir. Tez Işık Üniversitesi'nde hazırlanmıştır. Danışmanı Olcay Taner Yıldız'dır. Hoca, danışmanın artık Özyeğin Üniversitesi'nde olduğunu belirtir. Sunucu, tezden çıkan bildiriyi de derlemin hazırlanışı için incelemiştir.

### 6.1 Amaç ve Soru Tipleri

ÖSYM'nin çoktan seçmeli sınavlarından dört sözel soru tipi seçilir. Bu sorulardan bilgisayarın işleyebileceği bir derlem (corpus) kurulur. Sorular doğal dil işleme teknikleriyle çözülmeye çalışılır. Soru tipleri şunlardır:

1. Anlam bütünlüğünü bozan cümleyi bulma.
2. Cümle parçalarının doğru sıralamasını bulma.
3. Paragrafı özetleyen cümleyi bulma.
4. Verilen cümleyle aynı anlamı taşıyan cümleyi bulma.

### 6.2 Derlemin Oluşturulması

ÖSYM sınavları taranır ve 973 soru bulunur. Süreç şöyledir:

1. Sorular OCR ile metne çevrilir. Hangi OCR motorunun kullanıldığı belirtilmez.
2. Apache POI ile Excel biçimine aktarılır.
3. Excel'den XML üretilir.
4. XML'e cümlelerin biçimbilimsel (morphological) analizleri eklenir.

Sunucu, benzer bir derlemi açık bir veri tabanında paylaşmayı düşündüğünü, ama ÖSYM sorularının telif durumunu bilmediği için çekindiğini söyler.

### 6.3 Bölümleme ve Benzerlik Ölçütleri

Cümleler dört biçimde bölümlenir (segmentation): kelime, hece, karakter ve kök. Kök bölümlemesinde kelimenin kökü bulunup o dikkate alınır.

Beş metin benzerlik ölçütü kullanılır:

- **q-gram benzerliği:** İki kelime ya da cümle belirli uzunlukta karakter parçalarına bölünür. Ortak parçaların oranına bakılır. Ayrıştıkları oranda birbirlerine uzak sayılırlar.
- **Manhattan (blok) uzaklığı:** İki nokta arasındaki uzaklık, dik parçalar boyunca ölçülür. Formülü $d = \sum_i |x_i - y_i|$ biçimindedir.
- **Levenshtein uzaklığı:** Bir dizgiyi diğerine çevirmek için gereken en az ekleme, silme ve değiştirme sayısıdır.
- **Jaccard benzerliği:** Kesişimin birleşime oranıdır. Tezdeki örnekte iki cümlede toplam 22 token vardır ve yalnız biri ortaktır: $1/22 \approx 0{,}045$.
- **Örtüşme katsayısı (overlap coefficient):** Kesişimin küçük kümenin boyutuna oranıdır.

$$\mathrm{overlap}(A,B) = \frac{|A \cap B|}{\min(|A|,|B|)}$$

Sunucu tezde bir karışıklık bulur: açıklama kısmında "overlap coefficient" yerine ona çok benzeyen "overlapping coefficient" kavramı yanlış kullanılmıştır.

### 6.4 Çözümün Yapısı

"Aynı anlamı taşıyan cümle" sorusu en basit durumdur. Soru cümlesi ile her şık bir fonksiyona girer. Bölümleme yöntemi ve benzerlik ölçütüne göre her şık için bir sayı çıkar. En yüksek değerli şık seçilir. Örneğin C şıkkı 0,5 ile en yüksekse C seçilir.

Dört bölümleme ve beş ölçüt olduğu için $4 \times 5 = 20$ farklı benzerlik dizisi elde edilir.

"Paragrafı özetleyen cümle" sorusunda paragrafın cümleleri her şıkla karşılaştırılır. Bu yüzden çıktı tek bir dizi değil, sayısal bir matristir. Satırlar şıklara karşılık gelir.

### 6.5 Bütünsel İndirgeme Yöntemleri

Matrisi şık başına tek bir değere indirmek için bütünsel (holistic) yöntemler kullanılır:

| Yöntem | İşlem | Seçim |
| :--- | :--- | :--- |
| max-max | Matristeki en büyük değer bulunur | O değerin bulunduğu şık |
| Çarpım | Her satırdaki değerler çarpılır | En büyük çarpımın şıkkı |
| Ortalama | Her satırın ortalaması alınır | En büyük ortalamanın şıkkı |
| max-min | Her satırın en küçük değeri alınır | Bunların en büyüğünün şıkkı |

Sunucunun örneğinde max-max için en büyük değer 0,42'dir ve D şıkkı seçilir. Çarpım ve max-min için de D şıkkı çıkar; max-min değeri 0,14'tür.

<!-- BELİRSİZ: Örnek matrisin değerleri slaytta. Sunucunun ardından söylediği "0,5 ve C şıkkı" ifadesi, önceki dizi örneğine mi bu matrise mi ait, altyazıdan anlaşılmıyor. -->

Çarpım yönteminde herhangi bir yumuşatma uygulanmamıştır; sunucu bunu ayrıca belirtir. Sunucu, "max-max" adını ilk gördüğünde bulanık ilişkilerdeki işlemi düşündüğünü, ama burada başka bir şey olduğunu anladığını da ekler.

### 6.6 Sonuçlar ve Eleştiriler

Bütün birleşimler doğru cevaplarla karşılaştırılır. Paragraf soruları için $4 \times 5 \times 4 = 80$ farklı sonuç olur. En iyi başarı kök bölümleme, q-gram benzerliği ve max-max birleşimiyle yaklaşık %28'dir. Cümle sorusunda ise en iyi başarının kök bölümleme ve blok uzaklığıyla geldiği söylenir.

Tez ayrıca soruların, şıkların ve benzerlik değerlerinin görüldüğü bir arayüz sunar.

Sunucunun eleştirileri şunlardır:

- Rastgele seçimle karşılaştırma yapılmamıştır. Beş şıkta rastgele seçim yaklaşık %20 başarı verir. Yöntemin bunun ne kadar üzerinde olduğu açıkça değerlendirilmemiştir.
- Bu sorular anlam karşılaştırması gerektirir. Harf ve karakter düzeyinde karşılaştırmayla başarı alınması zordur.

Hoca bu eleştirilere şöyle karşılık verir: "Adama derler ki o zaman otur, sen daha iyisini yap." Hoca, tezden çıkan bildirinin bir sempozyumda hakem olarak kendisine geldiğini de hatırlar.

## 7. Sunumlardan Çıkan Genel Dersler

- Bilinen bir problemde küçük ama ölçülebilir bir iyileştirme de değerli bir katkıdır (1. sunum).
- Yöntem başarısını yorumlamak için temel bir karşılaştırma gerekir. Rastgele seçimle karşılaştırma bunun en basit biçimidir (5. sunum).
- Eklenen özelliğin etkisi, önceki çalışmayla aynı ölçütlerde karşılaştırılarak gösterilir (2. sunum).
- Metin dışındaki kiplerde asıl zorluk çoğu zaman etiketlemenin öznelliğidir (3. sunum).
- Zaman boyutu duygu analizine yeni bir bilgi katar (4. sunum).

## Dersin Toparlaması

Bu derste beş çalışma incelendi. Birinci sunumda kelime gömmelerinin duygu bilgisini kaçırması ele alındı. Duygu sözlüğü ile komşular yeniden sıralanıp vektörler güncellendi ve gürültü azaldı. İkinci sunumda sosyal mühendislik saldırıları bağlantı, yazım ve niyet skorlarıyla ölçüldü, LDA ile konu özellikleri eklendi ve Random Forest ile sınıflandırıldı.

Üçüncü sunumda metin ve görüntü için ayrı derin modeller karşılaştırıldı. Görüntüden duygu çıkarmanın ve etiketlemenin zorluğu tartışıldı. Dördüncü sunumda Polaris sistemi, duygunun zaman ve yer içindeki yörüngesini izledi ve LSTM ile tahmin yaptı. Beşinci sunumda ÖSYM sorularına karakter ve kök düzeyinde benzerlik uygulandı. En iyi başarı yaklaşık %28 oldu. Bu sonuç, anlam gerektiren sorularda yüzeysel benzerliğin sınırını gösterir.

## Ders Sonrası Notlar

> **Ders sonrası not:** Sunucu CBOW anlatımına "girdi olarak ortadakini alacak" diye başlıyor. Doğrusu, kendi önceki cümlesinde olduğu gibi, CBOW'da ortadaki kelimenin çıktı olmasıdır.

> **Ders sonrası not:** Sunucu "CBOW daha az veride, skip-gram daha çok veride kullanılır" diyor. Mikolov'un ifadesine göre ise skip-gram küçük eğitim verisinde iyi çalışır. CBOW daha hızlıdır ve sık geçen kelimelerde biraz daha iyidir.

> **Ders sonrası not:** Sunumda makalenin yeri "ACL'in Erdesel Metodlar Konferansı" diye geçiyor. Bu, EMNLP'dir (Empirical Methods in Natural Language Processing). Kısa nottaki bilgiyle uyumludur.

> **Ders sonrası not:** "Tri-LSTM" diye geçen model büyük olasılıkla ağaç yapılı LSTM'dir (Tree-LSTM). Altyazıdan kesin değildir. Duygu sözlüğünün altyazıda "N" diye geçen adı da büyük olasılıkla ANEW'dir; kesin değildir.

> **Ders sonrası not:** Artış değerleri "1,7 ve 1,5 arasında, beşli olursa 1,6" diye geçiyor. Bu notta kısa notla uyumlu olarak ikili için 1,7, beşli için 1,6 yazıldı. Bunlar yüzde puan farkıdır, başarının yüzdesi değildir.

> **Ders sonrası not:** Large Movie Review veri setinin yaygın bölünmesi 25.000 eğitim ve 25.000 test örneğidir. Sunumda 20.000 ve 5.000 deniyor. Bu, makalenin kendi bölünmesi olabilir; altyazıdan doğrulanamıyor.

> **Ders sonrası not:** Görüntü uygulamasında sınıflar bir yerde "pozitif, nötr, negatif" diye geçiyor. Veri seti tanıtımında ise yalnız olumlu ve olumsuz denmişti. Metin LSTM ve görüntü CNN modellerinde kayıp olarak MSE söyleniyor; sınıflandırmada genellikle çapraz entropi kullanılır.

> **Ders sonrası not:** Dördüncü sunumda ham tweet sayısı önce "yaklaşık 30 milyon", tartışmada "40 milyon" deniyor. Kullanılan veri her iki yerde yaklaşık 10 milyondur.

> **Ders sonrası not:** Jaccard benzerliği sunumda "kesişim bölü toplam adet" diye anlatılıyor. Doğru tanım kesişim bölü birleşimdir. Tezdeki 22 sayısının birleşim boyutu olduğu varsayılmıştır. Levenshtein bir benzerlik değil, uzaklık ölçüsüdür; sunumda iki adla da geçiyor.

> **Ders sonrası not:** Altyazıda bozuk geçen terimlerin doğru yazımları: "Refining for the Embedding for the Sentiment Analyze" = "Refining Word Embeddings for Sentiment Analysis"; "Stanford Sentinel Treebank" = Stanford Sentiment Treebank; "SIBO, Sibov" = CBOW; "Skip-crumb, SkipCrab, Zikip Krab" = skip-gram; "Glow, GLOV" = GloVe; "Penington" = Pennington; "Seader Plus Plus" = SEADer++; "simspell PY" = SymSpellPy; "MOSSİ" = MOSI; "Föntüvek" = büyük olasılıkla word2vec; "Asterix database" = AsterixDB; "sentiment 141" = Sentiment140; "Eczema" = XML; "Apache Point" = Apache POI; "tecelere" = hecelere; "mehnatın uzaklığı" = Manhattan uzaklığı; "Levinstein" = Levenshtein; "Jakart" = Jaccard; "holistik sahileleştirme" = bütünsel indirgeme; "Starlink/sterlang" = büyük olasılıkla StarLang (danışmanın doğal dil işleme kütüphanesi).

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
