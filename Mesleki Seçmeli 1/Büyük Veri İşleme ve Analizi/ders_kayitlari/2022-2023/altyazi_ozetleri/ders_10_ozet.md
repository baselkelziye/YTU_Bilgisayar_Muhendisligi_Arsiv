# Ders 10 Çalışma Özeti

## Genel Konular

- Vize sonuçları, not ağırlıkları ve dönem projesi takvimi.
- Öneri sistemleri (recommendation systems), kitabın 9. bölümü.
- Fiziksel mağaza ile çevrimiçi mağaza farkı ve uzun kuyruk (long tail) olgusu.
- Öneri türleri: editoryal (elle seçilmiş), istatistik tabanlı (en çok satanlar), kişiye özel.
- Fayda fonksiyonu (utility function) ve fayda matrisi (utility matrix).
- Öneri sistemlerinin üç sorunu: bilinen puanları toplamak, bilinmeyen puanları tahmin etmek, başarıyı ölçmek.
- Açık (explicit) ve örtük (implicit) puanlar.
- Soğuk başlangıç sorunu (cold start problem).
- İçerik tabanlı öneri (content-based recommendation): öğe profili, kullanıcı profili, TF-IDF, kosinüs benzerliği.
- İşbirlikçi filtreleme (collaborative filtering): Jaccard, kosinüs ve merkezlenmiş kosinüs (Pearson korelasyonu).
- Kullanıcı-kullanıcı ve öğe-öğe işbirlikçi filtreleme.
- Değerlendirme: test verisi ayırma ve RMSE.

## Hocanın Özellikle Vurguladığı Kısımlar

- **Vize ağırlığı %30.** Müfredatta %40 yazıyor ama bu bir hata.
- **Dönem projesi de %30.** Bu yüzden proje çok önemli.
- **Proje teklifi son günü bu ders günüydü** (3 Mayıs), gün sonuna kadar. Teklif göndermeyen proje yapmayacak sayılır.
- **Onay beklemeden projeye başlayın.** Değişiklik gereken teklifler için hoca kendisi iletişime geçecek. Haber gelmezse teklif kabul edilmiş sayılır.
- **Proje teslimi ve demo dönemin son haftasında, çarşamba günü.** Her grup kodunu gösterecek, demo yapacak ve kısa bir sunumla projeyi anlatacak. Şimdilik sınıfta yapılması planlanıyor. Değişiklik olursa online da yapılabilir.
- Derste kişiye özel öneriler (3. tür) ele alınıyor.
- **Soğuk başlangıç** en önemli sorundur. Geçmişi olmayan yeni kullanıcıya veya yeni öğeye öneri yapmak zordur.
- **Jaccard benzerliği puanları hesaba katmaz.** Bu yüzden zevkleri zıt olan kullanıcıları benzer gösterebilir.
- **Merkezlenmiş kosinüs (Pearson)** sezgiyi en iyi yakalayan benzerlik ölçüsüdür.
- **Uygulamada öğe-öğe işbirlikçi filtreleme, kullanıcı-kullanıcıdan daha iyi çalışır.** İnsanların zevkleri çok yönlüdür, öğeler ise daha basittir.

## Kısa Tekrar Notları

- **Uzun kuyruk:** Çevrimiçi mağazada rafa ürün eklemenin maliyeti neredeyse sıfırdır. Az satan ürünler de satılabilir. Ama bu ürünleri bulmak zorlaşır, bu yüzden öneri gerekir.
- **Fayda fonksiyonu:** $u: C \times S \to R$. $C$ müşteriler, $S$ öğeler, $R$ puanlar (0-5 yıldız veya 0-1 arası gerçek sayı).
- **Açık puan:** Kullanıcının verdiği yıldız. Az kullanıcı verdiği için ölçeklenmez.
- **Örtük puan:** Davranıştan çıkarılır. Örnekler: filmi birden çok izlemek, şarkıyı sık dinlemek, ürün sayfasına farklı günlerde tekrar bakmak.
- **İçerik tabanlı öneri adımları:**
  1. Kullanıcının beğendiği her öğe için öğe profili vektörü çıkar.
  2. Bunların ortalamasıyla kullanıcı profili vektörünü oluştur.
  3. Kullanıcı profilini veritabanındaki tüm öğe profilleriyle karşılaştır.
  4. En benzer öğeleri öner.
- **TF-IDF:**
  - TF: bir kelimenin bir belge içindeki önemi.
  - IDF: bir kelimenin belge koleksiyonu içindeki değeri. $IDF_i = \log \frac{N}{n_i}$.
  - Ağırlık: $w = TF \times IDF$.
- **Kosinüs benzerliği:** $\cos(x, y) = \frac{x \cdot y}{\lVert x \rVert \lVert y \rVert}$. Değer büyükse vektörler benzerdir.
- **Merkezlenmiş kosinüs:** Önce her kullanıcının puanlarından o kullanıcının ortalaması çıkarılır. Sonra kosinüs hesaplanır.
- **Öğe-öğe tahmin formülü:** $r_{xi} = \frac{\sum_{j \in N(i;x)} s_{ij} \cdot r_{xj}}{\sum_{j \in N(i;x)} s_{ij}}$.
- **Değerlendirme:** Bilinen puanların bir kısmı test verisi olarak gizlenir. Tahminlerle gerçek değerler RMSE ile karşılaştırılır. Diğer ölçüler: MAE, MAPE.

## Detaylı Açıklamalar

### Öneri sistemlerine giriş

- Web'deki uygulamalar: kitap satış siteleri, Netflix, YouTube, Spotify, haber siteleri.
- Kullanıcı bir öğeyi kategorilerde gezerek veya arama kutusuna yazarak bulur.
- Milyonlarca öğe varken az bilinen bir öğeyi bu yollarla bulmak verimli değildir. Bu yüzden öneri algoritmaları gerekir.

### Uzun kuyruk

- Grafikte x ekseni popülerliğe göre sıralanmış öğeleri gösterir. y ekseni haftalık satış sayısını gösterir.
- Fiziksel mağazanın (örneğin Kadıköy'deki bir kitapçı şubesi) rafı sınırlıdır. Bu yüzden yalnız eşik değerinin üstündeki popüler ürünleri satar.
- Çevrimiçi mağazada (sanal market, çevrimiçi kitapçı) ürün eklemek yalnız veritabanına bir kayıt eklemektir. Eşiğin altındaki az popüler ürünler de sınırsızca listelenebilir.
- Eşiğin altında kalan bu geniş alana **uzun kuyruk** denir.
- Sorun: Çok ürün olunca kullanıcının aradığını bulması zorlaşır. Öneri sistemi bu öğeleri kullanıcıya getirir.
- **Örnek:** "Touching the Void" dağcılık kitabı yayımlandığında popüler değildi. Yıllar sonra aynı konudaki "Into Thin Air" çok satınca öneri motorları ilk kitabı da önerdi. Sonunda "Touching the Void" da çok satanlar listesine girdi ve ikincisinden fazla sattı.

### Öneri türleri

- **Editoryal / elle seçilmiş:** Starbucks'taki tahtada önerilen içecekler, kitapçıda bir köşeye dizilmiş kitaplar, gazetenin önerdiği makaleler.
- **İstatistik tabanlı:** En çok satan 10 kitap, en çok dinlenen 10 şarkı, geçen ayın en çok izlenen filmleri.
- **Kişiye özel:** Kullanıcının geçmişindeki dijital izler (okuduğu, izlediği, dinlediği) analiz edilir. Ders bu türe odaklanıyor.
- Kullanım alanları: kitap, film, müzik, haber (Google News), Facebook, LinkedIn, Twitter.

### Fayda matrisi

- Satırlar kullanıcılar, sütunlar öğelerdir. Hücreler puanlardır.
- Örnekte 4 kullanıcı (Alice, Bob, Carol, David) ve 4 film var. Bilinen puanlar açık puanlardır.
- Amaç boş hücreleri tahmin etmektir. Örneğin Alice "Lord of the Rings" filmine kaç verirdi?
- Tahmin edilen en yüksek puanlı öğe kullanıcıya önerilir.

### Üç temel sorun

1. **Bilinen puanları toplamak:** Az kişi geri bildirim verir.
2. **Bilinmeyen puanları tahmin etmek:** Hangi algoritma kullanılacak?
3. **Başarıyı ölçmek:** Öneri algoritmasının performansı nasıl değerlendirilecek?

### Puan toplama

- **Açık:** Film sonunda yıldız istemek. Kitap satın alana e-posta ile görüş sormak. Ölçeklenmez.
- **Örtük:** Etkileşim sıklığından puan türetilir.
  - Filmi birden çok izlemek beğeni göstergesidir.
  - Spotify'da bir şarkıyı çok dinlemek yüksek puan demektir.
  - Bir e-ticaret sitesinde ürün detayına farklı günlerde bakmak ilgi göstergesidir.

### Soğuk başlangıç sorunu

- İçerik tabanlı ve işbirlikçi algoritmalar kullanıcının geçmişine ihtiyaç duyar.
- Yeni gelen kullanıcı için geçmiş yoktur. Yeni eklenen öğe için de etkileşim geçmişi yoktur.
- Algoritmalar ancak veritabanında yeterli geçmiş biriktikten sonra verimli çalışır.

### İçerik tabanlı öneri

- Kullanıcıya daha önce yüksek puan verdiği öğelere benzeyen öğeler önerilir.
- **Öğe profili:** Her öğe için bir özellik vektörü.
  - Film için: yönetmen, oyuncular, tür (aksiyon, bilim kurgu).
  - Metin (makale, haber) için: önemli kelimeler. Önemli kelimeler TF-IDF ile seçilir.
- **TF-IDF ayrıntısı:**
  - Kelime bir belgede çok tekrar ediyorsa TF yüksektir. Kelime o belgede önemlidir.
  - Kelime koleksiyondaki her belgede geçiyorsa değeri düşüktür. Az belgede geçiyorsa değeri yüksektir.
  - Hocanın ezber önerisi: "Her yerde olan şeyin değeri düşüktür. Nadir bulunan şeyin değeri yüksektir."
  - Kelimeyi içeren belge sayısı $n_i$ büyükse IDF küçüktür. $n_i$ küçükse IDF büyüktür.
- **Kullanıcı profili:** Kullanıcının puanladığı öğe profillerinin ortalaması. Basit ortalama veya ağırlıklı ortalama kullanılabilir.

#### Oyuncu örneği

- Öğe profilinde her özellik bir oyuncudur. Oyuncu filmde varsa 1, yoksa 0.
- Kullanıcı X beş film izlemiş. A oyuncusu 2 filmde, B oyuncusu 3 filmde oynuyor.
- **Ağırlıklı (Boole) profil:** A için $2/5 = 0{,}4$, B için $3/5 = 0{,}6$.
- **Yıldız puanlı, normalize profil:**
  - A'lı filmlere verilen puanlar: 3 ve 5. B'li filmlere verilen puanlar: 1, 2 ve 4.
  - Kullanıcının ortalama puanı: $(3+5+1+2+4)/5 = 15/5 = 3$.
  - Her puandan ortalama çıkarılır. A: 0 ve 2. B: -2, -1 ve 1.
  - Profil ağırlıkları: A için $(0+2)/2 = 1$, B için $(-2-1+1)/3 = -2/3$.

#### Karşılaştırma

- Kullanıcı profili ile her öğe profili arasında kosinüs benzerliği hesaplanır.
- Benzerliği yüksek olan öğeler önerilir.

#### Artılar

- Başka kullanıcıların verisine gerek yok.
- Kendine özgü zevki olan kullanıcılara öneri yapılabilir. Örnek: yalnız klasik müzik dinleyen biri.
- Yeni ve popüler olmayan öğeler önerilebilir. Yalnız öğenin özellikleri gerekir.
- Önerinin nedeni açıklanabilir: "Şunları izlediğiniz için bunu öneriyoruz."

#### Eksiler

- Her öğe için doğru özellikleri bulmak zordur. Görüntü veya müzik için hangi özellikler seçilecek?
- **Aşırı uzmanlaşma (overspecialization):** Hep kullanıcının bildiği türde öneri yapılır. İnsanların birden çok ilgi alanı olabilir.
- **Soğuk başlangıç:** Profili oluşmamış yeni kullanıcıya öneri yapılamaz.

### İşbirlikçi filtreleme

- Kullanıcının tercihleri diğer kullanıcılarınkiyle karşılaştırılır. Tercihleri benzer kullanıcılar bulunur.
- Benzer kullanıcıların izleyip bu kullanıcının izlemediği öğeler önerilir.
- Örnek: Bilim kurgu ve tarih filmleri seven benzer kullanıcılar aksiyon filmleri de izlemiş. Bu kullanıcıya aksiyon filmi önerilir.
- Bu yöntem kullanıcıyı daha önce görmediği türde bir öneriyle "şaşırtabilir".

#### Benzerlik ölçüsü seçimi

- Örnekte 4 kullanıcı ve 7 film var. Filmler: HP1, HP2, HP3, Twilight, SW1, SW2, SW3.
  - A: HP1=4, TW=5, SW1=1.
  - B: HP1=5, HP2=5, HP3=4.
  - C: TW=2, SW1=4, SW2=5.
- **Sezgi:** A ile B ortak izledikleri filmi ikisi de beğenmiş. A ile C ise zıt zevklere sahip. Bu yüzden $sim(A,B) > sim(A,C)$ olmalı.
- **Jaccard:** $sim(A,B) = 1/5$, $sim(A,C) = 2/4$. Sonuç $sim(A,B) < sim(A,C)$, yani yanlış. Jaccard puanları dikkate almaz.
- **Kosinüs (boşluklar 0 kabul edilerek):** $sim(A,B) = 0{,}38$, $sim(A,C) = 0{,}32$. Sıralama doğru ama değerler birbirine çok yakın.
- **Merkezlenmiş kosinüs:**
  - A'nın ortalaması $(4+5+1)/3 = 10/3$. Normalize puanlar: $2/3$, $5/3$, $-7/3$.
  - B'nin ortalaması $(5+5+4)/3 = 14/3$. Normalize puanlar: $1/3$, $1/3$, $-2/3$.
  - Aynı işlem C ve D için yapılır. Boşluklar 0 kabul edilir.
  - $sim(A,B) = 0{,}09$, $sim(A,C) = -0{,}56$. Fark artık belirgin.
  - Buna Pearson korelasyonu benzerliği de denir.

#### Kullanıcı-kullanıcı ve öğe-öğe

- **Kullanıcı-kullanıcı:** Fayda matrisinin satırları kullanıcılar, sütunları öğelerdir.
- **Öğe-öğe:** Satırlar öğeler (filmler), sütunlar kullanıcılardır. Yöntem aynıdır.
- **Komşuluk (neighborhood) parametresi $|N|$:** Tahminde kaç benzer satırın kullanılacağını belirler. Örnekte $|N| = 2$.

#### Öğe-öğe örneği

- Hedef: 5. kullanıcının 1. filme vereceği puan.
- Adımlar:
  1. Her satırın ortalamasını hesapla. 1. satırın ortalaması 3,6.
  2. Her bilinen puandan satır ortalamasını çıkar.
  3. Normalize matriste her satırın 1. satırla kosinüs benzerliğini hesapla. 1. satırın kendisiyle benzerliği 1'dir.
  4. 5. kullanıcının puan verdiği satırlar arasından en benzer 2 satırı seç: 3. ve 6. filmler.
  5. Benzerliklerle ağırlıklı ortalama al.
- Benzerlikler: $s_{13} = 0{,}41$, $s_{16} \approx 0{,}56$. 5. kullanıcının puanları: 3. filme 2, 6. filme 3.
- $r_{15} = \frac{0{,}41 \cdot 2 + 0{,}56 \cdot 3}{0{,}41 + 0{,}56} \approx 2{,}6$.
- Tüm boş hücreler böyle doldurulur. Kullanıcı mağazaya geldiğinde izlemediği filmlerden en yüksek tahminli olan önerilir.

#### Neden öğe-öğe daha iyi?

- Kullanıcıların zevkleri karmaşıktır. Aynı kişi hem klasik müzik hem rock sevebilir.
- Bu yüzden iki kullanıcıyı karşılaştırmak tercih benzerliğini iyi yakalamayabilir.
- Altyazının bu kısmı kesik. Kitaptaki gerekçe şudur: öğeler daha basit, tek tip varlıklardır. Bu yüzden öğe benzerliği daha anlamlıdır.

### Değerlendirme

- **Anket:** Kullanıcıya önerilerin uygun olup olmadığı sorulur. Geri bildirim almak zordur.
- **Test verisi yöntemi:**
  1. Fayda matrisinden bilinen puanların bir kısmını test verisi olarak ayır. Örnekte 5 puan.
  2. Bu puanları bilinmiyormuş gibi "?" yap.
  3. Algoritmayı çalıştırıp tüm boşlukları, "?"ler dahil, tahmin et.
  4. Tahminleri gerçek değerlerle karşılaştır.
- **RMSE:** $\sqrt{\frac{1}{N}\sum_{xi}(r_{xi} - r^*_{xi})^2}$. Küçükse algoritma iyi öneriyor. Büyükse iyileştirme gerekir.
- Alternatif hata ölçüleri: ortalama mutlak hata (MAE) ve ortalama mutlak yüzde hata (MAPE).

### Ders sonrası notlar

- **Kosinüs benzerliği:** Hoca "kosinüs benzerliği küçükse vektörler benzerdir" dedi. Doğrusu tersidir. Açı küçükse kosinüs büyük olur ve vektörler benzerdir. Hocanın kendi örneklerindeki sonuçlar da bu doğru yorumla tutarlıdır.
- **Jaccard tanımı:** Hoca "paydada kesişim" dedi. Doğrusu: pay (üst) kesişim, payda (alt) birleşimdir, yani $|A \cap B| / |A \cup B|$.
- **Hata ölçüsü adı:** Hoca "mean average error" dedi. Doğru ad "mean absolute error" (MAE). Aynı şekilde "mean average percentage error" doğrusu "mean absolute percentage error" (MAPE).
- **Benzerlik değeri:** Hoca 6. satırın benzerliğini 0,56 olarak okudu. Kitaptaki aynı örnekte bu değer 0,59'dur. İki değerle de sonuç yaklaşık 2,6 çıkar.
- **Kitapların sırası:** "Touching the Void" (1988), "Into Thin Air"den (1997) yaklaşık dokuz yıl önce yayımlandı. Hoca "birkaç yıl önce" dedi.
- **Kayıt kesintisi:** Okul internetindeki sorun nedeniyle bağlantı koptu. Kayıtta yaklaşık 4 dakikalık bir kesinti var (00:31-00:36). Ayrıca birkaç yerde altyazı döngüye girmiş. O kısımlar özete alınmadı.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
