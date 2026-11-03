# Doğal Dil İşlemeye Kavramsal Bir Bakış Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.

### 📋 Genel Bilgiler
* **Ders:** Doğal Dil İşlemeye Kavramsal Bir Bakış (BLM5105)
* **Hoca:** Prof. Dr. Banu Diri
* **Dönem:** Güz
* **Akademik Yıl:** 2020-2021
* **Şube:** BLM5105 - 1

Bu dizin, ilgili ders kayıtlarının altyazı özetlerini, çalışma notlarını ve PDF kaynaklarını içermektedir.

## 📚 Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu, kaynak markdown dosyası ve doğrudan indirilebilir PDF formatındaki derlenmiş halleri listelenmiştir. Ders numaraları, kayıt arşivindeki ders kaydı sıra numaralarıdır (hafta numarası değildir).

| Ders No | Ders İçeriği / Konu Başlıkları | Kaynak Notlar (Markdown) | Çalışma Dosyası (PDF) |
| :---: | :--- | :---: | :---: |
| **Ders 1** | Doğal Dil İşlemeye Genel Bakış ve Dersin İşleyişi | [Özet](altyazi_ozetleri/ders_1_ozet.md) | [PDF (İndir)](ders_1_ozet.pdf) |
| **Ders 3** | Dilbiliminin Esasları, Biçim Bilim ve Chomsky Hiyerarşisi | [Özet](altyazi_ozetleri/ders_3_ozet.md) | [PDF (İndir)](ders_3_ozet.pdf) |
| **Ders 4** | Düzenli İfadeler ve Biçimbilimsel Analiz | [Özet](altyazi_ozetleri/ders_4_ozet.md) | [PDF (İndir)](ders_4_ozet.pdf) |
| **Ders 5** | Sentaktik Analiz, Ağaç Derlemleri ve Dil Modellerine Giriş | [Özet](altyazi_ozetleri/ders_5_ozet.md) | [PDF (İndir)](ders_5_ozet.pdf) |
| **Ders 6** | N-Gram Modelleri, Yumuşatma Teknikleri, Kelime Anlam Belirsizliği ve WordNet | [Özet](altyazi_ozetleri/ders_6_ozet.md) | [PDF (İndir)](ders_6_ozet.pdf) |
| **Ders 7** | Kelime Gösterimleri, Kelime Gömmeleri ve Metin Sınıflandırma | [Özet](altyazi_ozetleri/ders_7_ozet.md) | [PDF (İndir)](ders_7_ozet.pdf) |
| **Ders 8** | Metin İşleme Algoritmaları ve Bilgiye Erişim Modelleri | [Özet](altyazi_ozetleri/ders_8_ozet.md) | [PDF (İndir)](ders_8_ozet.pdf) |
| **Ders 9** | Gizli Anlamsal İndeksleme, Performans Ölçütleri ve Bilgi Çıkarımı | [Özet](altyazi_ozetleri/ders_9_ozet.md) | [PDF (İndir)](ders_9_ozet.pdf) |
| **Ders 10** | Vize Başlangıcı | [Özet](altyazi_ozetleri/ders_10_ozet.md) | [PDF (İndir)](ders_10_ozet.pdf) |
| **Ders 11** | Seminer Sunumları: Metin Benzerliği, Metin Kümeleme, Twitter Görüş Analizi, Alaycılık Tespiti ve Soyutlayıcı Özetleme | [Özet](altyazi_ozetleri/ders_11_ozet.md) | [PDF (İndir)](ders_11_ozet.pdf) |
| **Ders 12** | Seminer Sunumları: Kelime Gömmelerinin İyileştirilmesi, Sosyal Mühendislik Tespiti, Çok Kipli Duygu Analizi ve ÖSYM Sorularının Çözümü | [Özet](altyazi_ozetleri/ders_12_ozet.md) | [PDF (İndir)](ders_12_ozet.pdf) |
| **Ders 13** | Seminer Sunumları: Duygu Tespiti Yaklaşımları, Konu Bölümleme, Türkçe Kelime Bölümleme ve Bağımlılık Tabanlı Dil Modelleri | [Özet](altyazi_ozetleri/ders_13_ozet.md) | [PDF (İndir)](ders_13_ozet.pdf) |

> [!NOTE]
> 2 numaralı kayıt (15 Ekim 2020) arşivde yoktur, o hafta ders yapılmamıştır; 29 Ekim 2020 resmî tatildir.

## 🎯 Derslerin Detaylı Özetleri ve Kazanımları

### 🔹 Ders 1: Doğal Dil İşlemeye Genel Bakış ve Dersin İşleyişi
* **Genel Konular:**
  - Dersin işleyişi, değerlendirme sistemi ve beklentiler.
  - Dersin kapsamı ve konu listesi.
  - Dil nedir, doğal dil ve yapay dil (programming language) farkı.
  - Doğal dil işlemenin (Natural Language Processing, NLP) uygulama alanları.
  - Doğal dil işlemedeki zorluklar ve belirsizlikler (ambiguity).
  - Dil analizinin seviyeleri: ses bilimi (phonology), biçim bilim (morphology), söz dizimi (syntax), anlam bilimi (semantics), söylem (discourse), edim (pragmatics).
  - Biçimbilimsel analizde çoklu çözüm sorunu (Zemberek örneği).
* **Hocanın Vurgusu:**
  - Ders tamamen proje ağırlıklıdır.
    - Ödevler ve seminer verilse, vizeden 100 alınsa bile başı sonu olan bir proje teslim edilmezse dersten geçilmez.
  - Vize çoktan seçmeli test olacak.
    - Konu çok fazla olduğu için her konunun "olmazsa olmaz" anahtar kelimeleri ve tanımları sorulacak.
  - Yazılı final sınavı yok.
    - Final tarihinde proje demosu yapılacak.
  - Terimler hep İngilizce de verilecek, çünkü literatür İngilizce.
    - Örneğin "pragmatik" kelimesinin Türkçesi "edim"dir ama bu karşılık pek anlam ifade etmiyor.
  - Dil modelleri çok önemli.
    - Dil modeli olmadan bilgisayarda dille ilgili hiçbir çalışma yapılamaz. Derin öğrenmeden önce kural tabanlı ve istatistiksel yöntemlerde de dil modelleri temeldi.
* **Detaylı Açıklamalar:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.

### 🔹 Ders 3: Dilbiliminin Esasları, Biçim Bilim ve Chomsky Hiyerarşisi
* **Genel Konular:**
  - Dilbiliminin esasları (hızlı tekrar): sözlük (lexicon), gram kavramı, dil analizinin altı seviyesi.
  - NLP'de kullanılan model türleri.
  - Ses bilimi (phonology), fonetik diller ve fonetik alfabe.
  - Biçim bilim (morphology): çekim ve yapım ekleri, kök ve gövde (lemma), biçimbirim (morpheme) ve biçimcik (allomorph), biçimbirim türleri.
  - Biçimbilimsel analizde belirsizlik ve bağlılık analizi (dependency parsing) ihtiyacı.
  - Dağılıma bakarak biçimbirim bulma: Svahili örneği.
  - "ki"nin üç türü, ünlü uyumu ve kural dışı durumlar, fiil çatıları.
* **Hocanın Vurgusu:**
  - Doğal dille çalışmak için iki şey şarttır: kelimeler (sözlük, yani leksikon) ve dile özgü kurallar (gramer).
  - "Gram" ağırlık birimi değildir.
    - Dilde bölünebilen en küçük parça demektir. Dil modellerinde gram kelime de olabilir karakter de: kelime tabanlı ve karakter tabanlı n-gram.
  - Biçimbilimsel analiz araçları bir kelimenin bütün olası çözümlerini verir ama cümlede hangisinin doğru olduğunu söylemez.
    - Doğru çözümü seçmek için bağlılık analizi gerekir.
  - Bir kelime sözlükte varsa onun gövdesi (lemma) alınmalı, köküne kadar inilmemeli. "gözlük" kelimesini "göz" diye işlemek uygulamaya göre hataya yol açabilir.
  - Türkçe NLP çalışmaları geç başladı ve herkes bağımsız çalıştı.
    - Herkes kendi veri setini baştan oluşturuyor; çalışmalar bir araya getirilmiyor.
* **Detaylı Açıklamalar:** S => LAaR => LaaAR => LaaBR => LaBaR => LBaaR => LAaaR => LaaAaR => LaaaaAR => LaaaaC => ... => LCaaaa => aaaa ```

### 🔹 Ders 4: Düzenli İfadeler ve Biçimbilimsel Analiz
* **Genel Konular:**
  - Düzenli ifadeler (regular expression, regex): düzenli dillerle ilişkisi, otomat karşılıkları, kullanım alanları.
  - Temel regex komutları: `^`, `$`, `[]`, `[^]`, `.`, `?`, `*`, `+`, `\b`, `|`, sayaçlar `{n}`, `{n,m}`, `{n,}`, işlem önceliği ve özel karakterler.
  - Regex ödevi: farklı biçimlerde yazılmış adresleri bulmak.
  - Biçimbilimsel analiz (morphological analysis) ayrıntıları: biçimbirim (morpheme), kök ve gövde (stem), ek türleri.
  - İngilizce ve Türkçe biçim bilimi farkı ("You had been in the car" ve "arabadaymışsınız").
  - Biçimbilimsel analizin kullanım alanları ve bağlılık analizi (dependency parsing).
  - Biçimbilimsel çözümleyicinin bileşenleri: sözlük, biçim dizimi kuralları (morphotactic rules), imla kuralları (orthographic rules).
* **Hocanın Vurgusu:**
  - Düzenli ifadeler büyük-küçük harfe duyarlıdır (case sensitive).
    - Bunu unutmak çok hata yaptırır.
  - Yaklaşık 10 komutla regex ile yapılabilecek işlerin %80'i yapılabilir.
    - Gerisi ihtiyaç oldukça kaynaklardan bakılır. Regex bir dil gibi ezberlenmez, ihtiyaç anında kullanılır.
  - Aynı işi yapan iki regex'ten kısa ve sade olanı tercih edin.
    - Bir yıl sonra yeni bir durumu eklemek gerektiğinde karmaşık bir ifadeyi anlamak çok zorlaşır.
  - `*` ve `+` operatörleri bir döngü sayacı gibi düşünülebilir: `*` sıfırdan n'ye, `+` birden n'ye kadar sayar.
  - Biçimbilimsel analiz bir kelimenin bütün olası çözümlerini verir ama cümledeki doğru çözümü söylemez.
    - Anlamsal bilgi çıkarılacaksa doğru çözüm gerekir.
* **Detaylı Açıklamalar:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.

### 🔹 Ders 5: Sentaktik Analiz, Ağaç Derlemleri ve Dil Modellerine Giriş
* **Genel Konular:**
  - Morfolojik analizin kısa tekrarı ve sentaktik analize (söz dizimsel analiz, syntactic analysis) geçiş.
  - Kelime türleri, durak kelimeler (stop words) ve sözcük türü etiketleri (part of speech, POS).
  - Penn Treebank ve Brown etiket kümeleri, Türk dilleri için etiket kümesi.
  - Türkçe ile İngilizcenin söz dizimi farkları: serbest sıralı söz dizimi (free word order).
  - Bağlamdan bağımsız dilbilgisi (context-free grammar, CFG) ve ağaç derlemi (treebank).
  - Kural tabanlı ve olasılık tabanlı çözümleme, yukarıdan aşağı ve aşağıdan yukarı ayrıştırma (parsing).
  - Bağlılık ayrıştırması (dependency parsing).
* **Hocanın Vurgusu:**
  - Bu dersin konsepti hazır araçları kullanmaktır.
    - Morfolojik analizciyi öğrenciler yazmayacak.
  - Morfolojik analiz bir kelimeye birden fazla çözüm verebilir.
    - Hangisinin doğru olduğu bağlamdan (context) anlaşılır. Bu belirsizlik (ambiguity) sentaktik analizde çözülür.
  - Tümce ile cümle, sözcük ile kelime aynı anlamdadır.
  - Sık geçen bir kelime önemli demek değildir. "of" ve "in" çok sık geçer ama ayırt edici değildir.
  - Stop words çoğu uygulamada atılır.
    - Yazar tanıma (authorship) çalışmasında ise ayırt edici olabilir.

### 🔹 Ders 6: N-Gram Modelleri, Yumuşatma Teknikleri, Kelime Anlam Belirsizliği ve WordNet
* **Genel Konular:**
  - Dil modellerinin tekrarı ve n-gram modelinin pratikte kullanımı.
  - Bigram ile cümle olasılığı: "I want to eat Chinese food" örneği.
  - Seyrek (sparse) matrisler ve yumuşatma (smoothing) teknikleri:
    - Add-one smoothing.
  - N-gram modelinin biçimbirimsel belirsizliği gidermede kullanımı ("koyun" örneği).
  - Kelime anlamları, anlam (sense) kavramı ve kelime anlam belirsizliği giderme (word sense disambiguation, WSD).
  - Seçilmiş sözcük ve tüm sözcük yaklaşımları.
  - Bilgi tabanlı, derlem tabanlı ve makine öğrenmesi yöntemleri.
* **Hocanın Vurgusu:**
  - Kelimeler doğal dilde birbirinden bağımsız durmaz.
    - Bu yüzden kelime olasılıklarını bağımsız çarpmak gerçekçi sonuç vermez.
  - Tüm geçmişi kullanan n-gram pratikte uygulanamaz.
    - Çalışmalarda $n$ en fazla 5'e kadar çıkar. Genelde 2 ve 3 yeterlidir.
  - Hiçbir derlem ne kadar büyük olursa olsun bütün kelime ikililerini içermez.
    - Zipf yasası gereği seyrek veri her zaman olacaktır.
  - Sıfır olasılık, olasılık çarpan yöntemlerde (örneğin Naive Bayes) bütün sonucu sıfır yapar.
    - Bu yüzden yumuşatma gerekir.
  - Sıfırlara rastgele değer atanamaz.
    - Mantıklı bir yumuşatma tekniği kullanılmalıdır.

### 🔹 Ders 7: Kelime Gösterimleri, Kelime Gömmeleri ve Metin Sınıflandırma
* **Genel Konular:**
  - Kelime gösterimleri (word representation): klasik ve tahmin tabanlı gösterimler.
  - Vektör uzay modeli (vector space model), uzaklık ve benzerlik, cosine benzerliği.
  - One-hot, doküman tabanlı, bağlam (komşu kelime) tabanlı ve trigram tabanlı gösterimler.
  - Seattle-Denver örneği, Pointwise Mutual Information (PMI) ve kelime analojileri.
  - Kelime gömmeleri (word embeddings): word2vec (CBOW ve skip-gram), FastText, GloVe, BERT.
  - Makine öğrenmesinin NLP açısından hızlı tekrarı: özellik seçimi ve çıkarımı, k-NN, LVQ, çapraz geçerleme, kümeleme.
  - Metin sınıflandırma (text categorization): uygulamalar, özellikler, yazar tanıma özellikleri.
* **Hocanın Vurgusu:**
  - Hangi gösterimin, hangi özelliğin ve hangi yöntemin seçileceği uygulamaya bağlıdır.
    - Hepsi denenmeli, en iyi sonuç vereni seçilmelidir.
  - Vektörler normalize edilmeden kullanılırsa uzaklık hesaplarında yanıltıcı sonuçlar çıkar.
  - Metinlerde en çok kullanılan benzerlik ölçütü cosine benzerliğidir.
  - One-hot gösterimiyle kelimeler arasındaki benzerlik bulunamaz.
  - Türkçede embedding'ler kelimelerin kökünden değil, ekli hâlinden çıkarılmalıdır.
    - Anlamsal ilişkiler ekleri de kapsar.

### 🔹 Ders 8: Metin İşleme Algoritmaları ve Bilgiye Erişim Modelleri
* **Genel Konular:**
  - Vize duyurusu ve dönem içi değerlendirme oranları.
  - Metin işleme algoritmaları (text processing algorithms):
    - Ağaçların bağlı (linkli) gösterimi.
  - Ara sonrası: yazım hatası düzeltme üzerine soru-cevap ve bir öğrencinin adres verisi projesi.
  - Bilgiye erişim sistemleri (information retrieval, IR):
    - Kısa tarihçe ve IR sistemi mimarisi.
* **Hocanın Vurgusu:**
  - Vize 17 Aralık 2020'de yapılacak.
    - Test usulü olacak:
  - Bir sonraki hafta (10 Aralık) ders anlatılacak, ardından vize gelecek.
  - Yeni yönetmeliğe göre en az iki değerlendirme gerekiyor.
    - Yıl içinin %60'ı, yıl sonunun %40'ı alınacak.
  - Hocanın beklentisi: derste görülen her şeyi ezberlemek değil, ihtiyaç anında "böyle bir yöntem görmüştük" diyebilmek.
  - Doktora öğrencilerine not: yeterlilik sınavında hoca derste vurguladığı konulardan soru sorar.
* **Detaylı Açıklamalar:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.

### 🔹 Ders 9: Gizli Anlamsal İndeksleme, Performans Ölçütleri ve Bilgi Çıkarımı
* **Genel Konular:**
  - Vize, seminer ve dönemin geri kalanı hakkında duyurular.
  - Önceki dersin kısa tekrarı: Boole, genişletilmiş Boole ve bulanık modeller.
  - Gizli anlamsal indeksleme (latent semantic indexing, LSI) / gizli anlamsal analiz (latent semantic analysis, LSA):
    - Amaç, ön işlem ve terim ağırlıklandırma: yerel ağırlık (local weighting), global ağırlık (global weighting).
  - Arama motorları: web katalogları, Google mimarisi, PageRank, akıllı bir arama motorunda olması gerekenler.
  - Performans ölçütleri: karışıklık matrisi (confusion matrix), duyarlılık (sensitivity), özgüllük (specificity), kesinlik (precision), anma (recall), F-ölçüsü (F-measure).
  - Bilgi çıkarımı (information extraction, IE):
    - IR, IE ve soru cevaplama (question answering) ilişkisi.
* **Hocanın Vurgusu:**
  - Vize 17 Aralık 2020'de, test usulü:
    - Bazı sorularda kağıtta çözüm yapıp sonucu şıklarda aramak gerekecek.
  - Vizeden sonra seminerler başlıyor.
    - Seminerler arasında zaman kalırsa hoca 15-20 dakikalık konu anlatabilir.
  - Kalan konular: metin sınıflandırma (text classification), bilgi çıkarımı ve kısaca soru cevaplama sistemleri.
    - Hoca bazı konuları "acil ya da önemli değil" diye vermiyor.
  - Hocanın sınav beklentisi: not değil, öğrencinin "ihtiyacım olduğunda bunu görmüştüm" diyebilmesi. "Herkes kendisinden sorumludur."
  - LSI, terimlerin yalnızca geçip geçmediğine değil anlamsal ilişkilerine de bakar.
    - Ortak kelime olmasa bile benzer belgeleri bulabilir.
* **Detaylı Açıklamalar:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.

### 🔹 Ders 10: Vize Başlangıcı
* **Genel Konular:**
  - Ders 17 Aralık 2020 Perşembe günü online yapıldı. Kayıt yaklaşık 2 dakikalık bir vize başlangıcıdır. Akademik içerik yoktur.
  - O gün dersin vizesi vardır. Vize saat 9.30'da başlar.
* **Hocanın Vurgusu:**
  - Hoca soruları hafta içinde hazırlayıp sisteme koyduğunu ve öğrencilere e-posta attığını söylüyor.
  - Sınavı görenler hemen sınava girmeli.
* **Detaylı Açıklamalar:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.

### 🔹 Ders 11: Seminer Sunumları: Metin Benzerliği, Metin Kümeleme, Twitter Görüş Analizi, Alaycılık Tespiti ve Soyutlayıcı Özetleme
* **Genel Konular:**
  - Bu ders (24 Aralık 2020) öğrenci seminer sunumlarının ilk haftasıdır. Konu anlatımı yoktur.
  - Her öğrenci bir makaleyi inceleyip sunar. Hoca sunumların arasına girip sorular sorar ve ek açıklamalar yapar.
  - Bu derste 6 sunum yapılır:
    - 1. sunum: Doküman işleme ile anlamsal metin benzerliği analizi (Jaccard ve kosinüs benzerliği).
  - Sunumlardan sonra hoca, bir öğrencinin Türkçe dil modelleri ve konuşmadan metne (speech-to-text) sorusunu yanıtlar.
  - Ders sonunda hoca vize sonuçlarını değerlendirir: "Vizeler iyi değildi." Proje ve seminerlerin çok önemli olduğunu vurgular.
* **Hocanın Vurgusu:**
  - **Yeni buluş beklenmiyor:** 1. sunumdaki makale bir uygulamayı makaleye çevirmiştir.
    - Hoca "Bunu siz de rahatlıkla yapabilirsiniz" der.
  - **Başlık ve içerik uyumu:** 1. sunumdaki makalenin adında "anlamsal (semantic)" geçer.
    - Ama kullanılan yöntemler (Jaccard, kosinüs) sözcüksel benzerliğe dayanır. Anlamı yakalayan bir yöntem yoktur.
  - **Karşılaştırma aynı veri setinde yapılır:** Yeni bir yöntem (örneğin GloVe, BERT) çıktığında eski yöntemle aynı veri seti üzerinde karşılaştırılır.
    - Başarının artıp artmadığı böyle gösterilir.
  - **Türkçe kısıtlı kaynaklı bir dildir:** Türkçede etiketli veri seti azdır.
    - Kısıtlı kaynaklı diller (low-resource languages) için ayrı sempozyumlar yapılır. Endonezce, Arapça, Türkçe ve Afrika dilleri bu gruptadır.
  - **Kısaltmaları açın:** 3. sunumda hoca "LDA" kısaltmasını sorar.
    - LDA hem Linear Discriminant Analysis hem Latent Dirichlet Allocation olabilir. Sunumda hangisi olduğu belirtilmelidir.

### 🔹 Ders 12: Seminer Sunumları: Kelime Gömmelerinin İyileştirilmesi, Sosyal Mühendislik Tespiti, Çok Kipli Duygu Analizi ve ÖSYM Sorularının Çözümü
* **Genel Konular:**
  - Bu ders (31 Aralık 2020) öğrenci seminer sunumlarının ikinci haftasıdır. Yılın son günüdür. Konu anlatımı yoktur.
  - Bu derste 5 sunum yapılır:
    - 1. sunum: Duygu analizi için kelime gömmelerinin (word embedding) iyileştirilmesi.
  - Ders sonunda hoca final günü yapılacak proje değerlendirmesini anlatır.
* **Hocanın Vurgusu:**
  - **Küçük katkılar da değerlidir:** 1. sunumdaki çalışma bilinen bir problemi ele alır.
    - Bilinen yöntemlere küçük bir iyileştirme ekleyerek başarıyı artırmaya çalışır. Hoca bunun da geçerli bir araştırma yolu olduğunu söyler.
  - **Sosyal mühendislikten kimse muaf değildir:** Hoca kendi başına gelen bir olayı anlatır.
    - Bir yakınının hesabından gelen sahte bir yardım mesajına inanıp para göndermiştir.
  - **Görüntüden duygu çıkarmak zordur:** Metinden duygu çıkarmak anlaşılırdır.
    - Görüntüde ise yüz ifadesi dışında duyguyu belirlemek ve etiketlemek bile zordur.
  - **Zamanla değişen duygu:** 4. sunumdaki kar örneği güzeldir.
    - Kar ilk başta insanların hoşuna gider. Kar uzun sürdükçe moraller bozulur ve duygu olumsuza döner.
  - **Referans ve kaynak aynı şeydir:** Slaytta ikisini ayrı başlık olarak koymayın.
    - Birini kullanın.

### 🔹 Ders 13: Seminer Sunumları: Duygu Tespiti Yaklaşımları, Konu Bölümleme, Türkçe Kelime Bölümleme ve Bağımlılık Tabanlı Dil Modelleri
* **Genel Konular:**
  - Bu ders (7 Ocak 2021) dönemin son dersidir. Öğrenci seminer sunumlarının üçüncü ve son haftasıdır. Konu anlatımı yoktur.
  - Hoca kalabalık olunduğu için her sunumun 20 dakikayı geçmemesini ister.
  - Bu derste 6 sunum yapılır (programdaki iki öğrenci derse katılmaz):
    - 1. sunum: Metinden duygu tespiti yaklaşımları üzerine bir derleme.
  - Ders sonunda hoca final günü yapılacak proje değerlendirmesini ve final tarihini konuşur.
* **Hocanın Vurgusu:**
  - **Süreye uyun:** Sunumu uzatmak için ağırdan almayın.
    - Dinleyicinin dikkati bir noktadan sonra dağılır.
  - **Birlikte çalışmanın değeri:** 1. sunumda Aralık ayında olumlu paylaşımların arttığı sonucu tartışılır.
    - Hoca verinin hangi yarımküreden geldiğinin önemli olduğunu söyler. Aralık kuzeyde soğuk ve kasvetli, güneyde yazdır.
  - **Duygu sözlükleri genişletilebilir:** NRC duygu sözlüğünün Türkçe sürümü de vardır.
    - Sözlükte olmayan bir duygu kelimesi, derecesiyle birlikte eklenebilir. Sözlük sonuçta bir Excel dosyası gibidir.
  - **Emoji tabanlı otomatik etiketlemenin sınırı:** Emoji puanlarını toplayarak etiketlemek basittir.
    - Ama kırık kalp ile ağlayan yüz yan yana gelirse puanlar birbirini götürüp nötr çıkabilir. Oysa metin üzgün bir durumu anlatır. Emoji içermeyen tweet'ler de büyük olasılıkla elenmiştir.
  - **Veri seti oluşturmak atıf getirir:** Etiketli veri seti eksikliği öne çıkan bir sorundur.
    - İyi bir veri seti oluşturan çok atıf alabilir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
