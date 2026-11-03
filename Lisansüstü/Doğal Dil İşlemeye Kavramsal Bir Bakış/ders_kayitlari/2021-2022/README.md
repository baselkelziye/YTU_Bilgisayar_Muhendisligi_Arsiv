# Doğal Dil İşlemeye Kavramsal Bir Bakış Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.

### 📋 Genel Bilgiler
* **Ders:** Doğal Dil İşlemeye Kavramsal Bir Bakış (BLM5105)
* **Hoca:** Prof. Dr. Banu Diri
* **Dönem:** Güz
* **Akademik Yıl:** 2021-2022
* **Şube:** BLM5105 - 1

Bu dizin, ilgili ders kayıtlarının altyazı özetlerini, çalışma notlarını ve PDF kaynaklarını içermektedir.

## 📚 Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu, kaynak markdown dosyası ve doğrudan indirilebilir PDF formatındaki derlenmiş halleri listelenmiştir. Ders numaraları, kayıt arşivindeki ders kaydı sıra numaralarıdır (hafta numarası değildir).

| Ders No | Ders İçeriği / Konu Başlıkları | Kaynak Notlar (Markdown) | Çalışma Dosyası (PDF) |
| :---: | :--- | :---: | :---: |
| **Ders 4** | Öğrenci Sunumları: Çok Etiketli Duygu Sınıflandırması, Emoji Duygu Sözlüğü, Türkçe Kelime Bölütleme ve Metin Benzerliği | [Özet](altyazi_ozetleri/ders_4_ozet.md) | [PDF (İndir)](ders_4_ozet.pdf) |
| **Ders 5** | Duygu Analizi, Hisse Senedi Tahmini, Denetimsiz Metin Sınıflandırma ve WSD Sunumları | [Özet](altyazi_ozetleri/ders_5_ozet.md) | [PDF (İndir)](ders_5_ozet.pdf) |
| **Ders 6** | 5G Konu Analizi, Haber Duygu Analizi, Özgeçmişte NER ve Türkçe BERT Soru Cevaplama Sunumları | [Özet](altyazi_ozetleri/ders_6_ozet.md) | [PDF (İndir)](ders_6_ozet.pdf) |

> [!NOTE]
> Arşivde bu döneme ait yalnızca 4, 5 ve 6 numaralı kayıtlar vardır.

## 🎯 Derslerin Detaylı Özetleri ve Kazanımları

### 🔹 Ders 4: Öğrenci Sunumları: Çok Etiketli Duygu Sınıflandırması, Emoji Duygu Sözlüğü, Türkçe Kelime Bölütleme ve Metin Benzerliği
* **Genel Konular:**
  - Bu ders (22 Aralık 2021) tamamen öğrencilerin makale sunumlarına (seminer) ayrılmıştır. Toplam altı sunum vardır.
  - 1. sunum: Mikroblog verisinde çok etiketli (multi-label) duygu sınıflandırması (sentiment classification).
  - 2. sunum: Sosyal medya içeriklerinde gerçek zamanlı olay tespiti, duygu analizi ve duygu tahmini sistemi (Polaris).
  - 3. sunum: Emojiler için gözetimsiz (unsupervised) yöntemle duygu sözlüğü (sentiment lexicon) oluşturma.
  - 4. sunum: Türkçe doküman sınıflandırmada kelime bölütleme (word segmentation) yöntemlerinin sinir ağı sınıflandırıcılarına etkisi.
  - 5. sunum: Demiryolu güvenliği belgelerinde anlamsal metin benzerliği (semantic text similarity): Jaccard ve kosinüs benzerliği.
  - 6. sunum: Hisse senedi trend tahmininde teknik analiz ile haberlerden çıkarılan duygu gömmelerinin (sentiment embedding) birleştirilmesi.
* **Hocanın Vurgusu:**
  - Sunuma veri setiyle değil, çalışmanın amacıyla başlanmalıdır.
    - Önce "bu çalışma ne yapıyor?" sorusu bir iki cümleyle cevaplanmalıdır.
  - Her sunumda makalenin hangi yıl ve nerede (dergi veya konferans) yayınlandığı söylenmelidir.
    - Hoca bunu her sunucuya sormuştur.
  - Makale okunmadan sunum yapılmamalıdır.
    - Yazarların kim olduğu ve veri setinin nereden geldiği bilinmelidir.
  - Çok etiketli (multi-label) ile çok sınıflı (multi-class) sınıflandırma arasındaki fark net anlatılmalıdır.
  - Çok az veriyle ve dengesiz etiket dağılımıyla yapılan çalışmaların iddiaları sorgulanmalıdır.

### 🔹 Ders 5: Duygu Analizi, Hisse Senedi Tahmini, Denetimsiz Metin Sınıflandırma ve WSD Sunumları
* **Genel Konular:**
  - Ders 29 Aralık 2021 tarihlidir. Ders tamamen öğrenci seminer sunumlarından oluşur.
  - Her sunum en fazla 20 dakikadır. Hoca süre aşımına ve gereksiz ayrıntıya müdahale eder.
  - Bu derste beş makale sunulur:
    - 1. sunum: Twitter'da 5G teknolojisine yönelik duygu analizi (sentiment analysis).
  - Ortak temalar: Twitter verisi, ön işleme (pre-processing), sözlük tabanlı duygu araçları, klasik makine öğrenmesi ile derin öğrenmenin karşılaştırılması.
* **Hocanın Vurgusu:**
  - Sınıfın zaten bildiği yöntemleri (Naive Bayes, SVM vb.) sunumda tek tek anlatmayın. "Bu yöntemler kullanılmıştır" deyip geçin.
  - Cümleleri uzatmayın, "ağdalı" anlatmayın.
    - 20 dakikayı aşmayın.
  - Naive Bayes denetimli (supervised) bir yöntemdir.
    - Başlığında "unsupervised" geçen bir çalışmada denetimsiz kısmın tam olarak nerede olduğunu açıklayabilmelisiniz.
  - Denetimsiz yöntem olarak en azından K-Means'i bilin.
  - PCA (Principal Component Analysis) sınıf etiketini kullanmaz.
    - Ama bir kümeleme modeli değil, öznitelik çıkarma (feature extraction) yöntemidir. Kümeleme örnekleri K-Means ve X-Means'tir.
* **Detaylı Açıklamalar:** İsterseniz bu özeti NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.

### 🔹 Ders 6: 5G Konu Analizi, Haber Duygu Analizi, Özgeçmişte NER ve Türkçe BERT Soru Cevaplama Sunumları
* **Genel Konular:**
  - Ders 5 Ocak 2022 tarihlidir. Dönemin son dersidir ve tamamen öğrenci seminer sunumlarından oluşur.
  - Kaydın ikinci parçası boştur. Bu özet birinci parçaya dayanır.
  - Bu derste dört makale sunulur:
    - 1. sunum: Twitter'da 5G konusunda görüş analizi ve konu belirleme (topic detection).
  - Ders sonunda final ve proje değerlendirmesiyle ilgili duyurular yapılır.
* **Hocanın Vurgusu:**
  - LDA'da konu sayısını seçmek için perplexity gibi ölçütler kullanılır.
    - Bu ölçütlerle tahmini bir konu sayısı bulunur, sonra bu sayının biraz altı ve üstü denenir.
  - Bir makale "gelecekte makine öğrenmesi algoritmaları uygulayacağız" diyorsa yazarların sonraki çalışmalarını kontrol edin.
    - Söz tutulmuş mu, yoksa makale "uyduruktan" mı yazılmış? "Detektif gibi iş göreceksiniz."
  - Bir çalışmanın neden yapıldığını, hangi ihtiyaçtan doğduğunu sorgulayın.
  - Proje konusu dar zamanda seçiliyorsa iddialı alt görevlere girmeyin.
    - NER projesinde klasik varlık türleriyle başlayın: kişi (person), yer (location), kurum (organization).
  - Hoca sunumların zamanında ve anlaşılır biçimde yapılmasını, sunum sırasında nefes alınmasını ister.
* **Detaylı Açıklamalar:** İsterseniz bu özeti NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
