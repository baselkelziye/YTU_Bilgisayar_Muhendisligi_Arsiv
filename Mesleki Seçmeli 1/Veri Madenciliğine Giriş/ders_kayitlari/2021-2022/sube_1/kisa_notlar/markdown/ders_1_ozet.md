# Ders 1 Çalışma Özeti

## Genel Konular

- Önceki dersin kısa tekrarı: veri madenciliği yöntemlerinin iki ana grubu
  - Veri madenciliğinin amacı ham veriden işe yarayan bilgiyi çıkarmaktır. Ham veri tek başına çok şey ifade etmez.
  - Tahmin edici (predictive) yöntemlerde verinin etiketi (label) vardır ve bu etiket tahmin edilmeye çalışılır.
    - Sınıflandırma (classification): etiketler ayrık (discrete) değerlerdir.
    - Regresyon (regression): tahmin edilen değer sürekli (continuous) bir değerdir.
  - Tanımlayıcı (descriptive) yöntemlerde etiket yoktur.
    - Kümeleme (clustering): örneğin müşteri bölümleme (customer segmentation). Hangi müşterinin hangi kümeye ait olduğu ve kümelerin özellikleri önceden bilinmez. Hiyerarşik olmayan yöntemlerde küme sayısı parametre olarak kullanıcı tarafından verilir.
    - Aykırı değer bulma (outlier / anomaly detection): elde "bu kayıt aykırıdır" etiketi yoktur. Genel eğilimden farklılaşan kayıtlar şüpheli olarak bulunur, bu yüzden tanımlayıcı bir yöntemdir. Aykırı görünen bir değer her zaman gerçek bir anomali olmayabilir.
- Bu dersin konusu: "Getting to Know Your Data" (ekrandan, 00:05:00)
  - Veri nesneleri ve öznitelik türleri (Data Objects and Attribute Types).
  - Verinin temel istatistiksel tanımları (Basic Statistical Descriptions of Data).
  - Veri benzerliği ve benzemezliğinin ölçülmesi (Measuring Data Similarity and Dissimilarity).
- Başarılı veri madenciliği için veriyle ilgili konular (ekrandan, 00:10:00)
  - Verinin türü: veri setleri birçok açıdan farklıdır. Veri türü hangi analiz tekniğinin kullanılacağını belirler.
  - Verinin kalitesi: veri çoğu zaman kusursuz değildir. Kaliteyi artırmak analiz sonucunun kalitesini artırır.
    - Elle girişte yapılan hatalar (örneğin ondalık ayracı unutulup 21.2 yerine 212 yazılması) ve cihaz kalibrasyonu gibi kaynaklı gürültü (noise) örnek verildi.
  - Ön işleme adımları: ham veri kalitesini artırmak ve veriyi seçilen tekniğe daha uygun hale getirmek için işlenir.
  - Verideki ilişkiler: nesneler arasındaki ilişkiler (benzerlik/uzaklık) bulunur, analiz bu ilişkiler üzerinden yapılır. Uygun ölçü veri türüne ve uygulamaya bağlıdır. Öznitelikler birbiriyle ilişkili (korele) olabilir ya da olmayabilir.
- Veri nesnesi ve öznitelik (ekrandan, 00:15:00)
  - Veri kümesi (data set) hangi türde olursa olsun (görüntü, sinyal, tablo) "veri kümesi" diye anılır.
  - Satırlar veri nesneleridir (data object). Diğer adları: sample, instance, example, tuple, object.
  - Sütunlar özniteliklerdir (attribute, Türkçesi öz nitelik). Diğer adları: variable, field, feature, characteristic.
  - Örnek tablo: Tid, Refund, Marital Status, Taxable Income, Cheat sütunlarından oluşan 10 satırlık bir tablo.
  - Öznitelik sütunun adıdır; öznitelik değeri (attribute value) o sütundaki hücrelerin aldığı değerdir. Örneğin Refund özniteliğinin değerleri Yes ve No'dur.
- Dört temel öznitelik türü (ekrandan, 00:20:00)
  - Nominal: kategorik (nitel). Kategoriler, durumlar ya da "şeylerin adları". Örnek: saç rengi, medeni durum, meslek, kimlik numaraları, posta kodları.
    - Binary (ikili) öznitelik: yalnız iki durumu (0 ve 1) olan nominal özniteliktir.
  - Ordinal (sıralı): kategorik (nitel). Değerlerin anlamlı bir sırası vardır, ama ardışık değerler arasındaki farkın büyüklüğü bilinmez. Örnek: boyut = {small, medium, large}, notlar, askeri rütbeler.
  - Interval (aralık): sayısal (nicel). Eşit büyüklükte birimlerle ölçülür, sırası vardır, gerçek sıfır noktası yoktur, oranlar anlamlı değildir. Örnek: Celsius ya da Fahrenheit sıcaklık, takvim tarihleri.
  - Ratio (oran): sayısal (nicel). Doğal sıfır noktası vardır, oranlar anlamlıdır. Örnek: Kelvin sıcaklık, uzunluk, sayımlar, parasal değerler.
- Nominal öznitelikler (ekrandan, 00:25:00)
  - Değerler sembol ya da isimdir; her değer bir kategori, kod ya da durum gösterir. Değerlerin anlamlı bir sırası yoktur.
  - Örnek: marital_status değerleri single, married, divorced, widowed.
  - Ortalama (mean) ve ortanca (median) anlamsızdır; yalnız en sık görülen değer (mode) bulunabilir.
  - Öğrenci numarası ve TC kimlik numarası gibi değerler sayıyla yazılsa da üzerinde aritmetik işlem yapılmadığı için nominal tutulur.
- Simetrik ve asimetrik ikili öznitelikler
  - Simetrik: 0 ile 1 arasında bir üstünlük yoktur, yerleri değiştirilebilir (örneğin cinsiyetin 0/1 ile tutulması).
  - Asimetrik: değerlerden biri bir şeyin varlığını gösterir (örneğin tıbbi testte pozitif = 1, negatif = 0).
- Ordinal öznitelikler
  - Kategoriktir ama değerler sıralanabilir: içecek boyu küçük/orta/büyük, çocuk/genç/yaşlı.
  - Derste ortalama ve ortancanın bir şey söylemediği, modun ise ("en çok orta boy alınmış") kullanılabileceği söylendi.
- Interval öznitelikler (ekrandan, 00:30:00)
  - Değerler arasındaki fark karşılaştırılabilir ve sayısallaştırılabilir: 20 °C, 15 °C'den 5 derece sıcaktır.
  - Celsius'ta 0 °C "sıcaklık yok" anlamına gelmez, yani gerçek sıfır yoktur. Bu yüzden "10 °C, 5 °C'nin iki katı sıcaktır" denemez.
  - Merkezi eğilim mod, medyan ve ortalama ile gösterilebilir.
- Ratio öznitelikler
  - Değerler sıfıra göre kat cinsinden ifade edilebilir (Kelvin, yaş, kütle, uzunluk, sayım).
  - Yaş örneği: eksi yaş yoktur ve "iki kat daha fazla yaşamış" denebilir, bu yüzden yaş oransal bir özniteliktir; dört işlemin hepsi anlamlıdır.
- Öznitelik değerlerinin özellikleri (ekrandan, 00:35:00)
  - Farklılık (distinctness): $=$, $\neq$
  - Sıra (order): $<$, $>$
  - Toplama (addition): $+$, $-$
  - Çarpma (multiplication): $*$, $/$
  - Nominal: farklılık; Ordinal: farklılık ve sıra; Interval: farklılık, sıra ve toplama; Ratio: dört özelliğin hepsi.
- Kategorik (nitel) ve sayısal (nicel) öznitelikler (ekrandan, 00:40:00)
  - Nominal ve ordinal öznitelikler birlikte kategorik ya da nitel (qualitative) öznitelikler diye anılır. Çalışan numarası gibi değerler tamsayıyla gösterilse de sembol gibi ele alınmalıdır; ortalamaları anlamsızdır.
  - Interval ve ratio öznitelikler birlikte nicel (quantitative) ya da sayısal öznitelikler diye anılır. Tamsayı ya da sürekli değerli olabilirler; ortalama ve standart sapma gibi işlemler anlamlıdır.
- Ayrık (discrete) ve sürekli (continuous) öznitelikler
  - Ayrık öznitelikler tamamen ayrık değerler alır, genellikle tamsayılarla gösterilir (örneğin öğrenci numaraları).
  - Sürekli öznitelikler genellikle gerçek dünya ölçümleridir (sıcaklık, uzunluk, uzaklık) ve ondalık değer alır.
  - Gerçek dünyadaki şeylerin çoğu süreklidir; insanlar ve bilgisayarlar onları ayrıklaştırarak anlar (sinyalin bir eşik değerine göre 0/1 olarak algılanması, yaşın aralıklarla sorulması).
- Vektör olarak veri
  - Bir veri nesnesinin öznitelikleri birleşince bir vektör oluşur.
  - Sinyal ve görüntüden çıkarılan öznitelikler genellikle sabit boyutlu (fixed window size) vektörlerdir; vektörün her elemanı tabloya yeni bir öznitelik sütunu olarak eklenir.
  - Çoğu yöntem girdiyi sayısal ister: kategorik değerler sayısala çevrilir (örneğin her kategori için ayrı bir 0/1 girişi), sayısal değerler de normalize edilir. Ayrıntısı ön işleme konusundadır.
- Veri seti türleri
  - Kayıt verisi (record data): Excel tablosu, veri tabanı tablosu, düz metin dosyası.
  - Veri matrisi (data matrix): çok boyutlu olabilir, görsel ve hızlı analiz sağlar.
  - Graf ve ağ verisi; video ve zaman serisi gibi sıralı (ordered) veri.
  - Doküman (metin) verisi (ekrandan, 00:50:00): her doküman bir terim vektörü olur; her terim bir öznitelik, değeri terimin dokümanda geçme sayısıdır (document-term matrix). Bağlaç ve edat gibi anlam taşımayan kelimeler önceden atılır.
- Metin madenciliği ve NLP üzerine kısa değerlendirme
  - Basit kelime sayma yaklaşımı eş sesli kelimeler ve bağlam yüzünden iyi çalışmaz; yeni sistemler kelimelerin birbirine uzaklığını gösteren kelime uzaylarını kullanır.
  - Konuşma tanımada eskiden Hidden Markov modelleriyle harf/kelime geçiş olasılıkları modellenirdi; derin öğrenmeyle bu yaklaşım yerini çok büyük veriyle eğitilen modellere bıraktı. Bu modeller çok veri ister; bu yüzden İngilizcede Türkçeden daha iyi çalışırlar.

## Hocanın Özellikle Vurguladığı Kısımlar

- Veri türü kullanılacak yöntemi belirler
  - Hangi öznitelik türüyle çalışıldığı bilinmeden yapılan matematiksel işlem (normalizasyon, çarpma vb.) hatalı sonuç verebilir. Interval ile ratio ayrımının önemi buradan gelir.
- Öznitelik türleri dönem boyunca sürekli kullanılacak
  - Örneğin bir ordinal değerin karar ağacına nasıl verileceği gibi sorularda bu türler tekrar karşımıza çıkacak.
- Numara gibi görünen kimlikler nominaldir
  - Öğrenci numarası, TC kimlik numarası, posta kodu tamsayı gibi dursa da üzerinde işlem yapılmadığı için nominal tutulur.
- Celsius'ta çarpma ve bölme anlamsızdır
  - Gerçek sıfır olmadığı için Celsius değerini çarpmak verinin anlamını bozar. Bütün değerlerin aynı oranda ölçeklendiği normalizasyon bunun dışında tutuldu.
- Aykırı değer bulma tanımlayıcı bir yöntemdir
  - Aykırılığı belirleyen eşik önceden bilinseydi veri madenciliğine gerek kalmaz, veri tabanı sorgusu yeterdi.

## Kısa Tekrar Notları

- Predictive: etiket var (sınıflandırma: ayrık, regresyon: sürekli). Descriptive: etiket yok (kümeleme, aykırı değer bulma).
- Satır = veri nesnesi (sample, instance, tuple); sütun = öznitelik (feature, variable, field).
- Dört öznitelik türü: nominal, ordinal (kategorik/nitel); interval, ratio (sayısal/nicel).
- Binary, iki durumlu nominal özniteliktir; simetrik ya da asimetrik olabilir.
- Nominal: yalnız mod. Ordinal: sıra var, aralık bilinmez. Interval: fark anlamlı, oran anlamsız (Celsius). Ratio: gerçek sıfır var, oran anlamlı (Kelvin, yaş, uzunluk, sayım, para).
- İzin verilen işlemler birikerek artar: nominal $=,\neq$; ordinal bunlara ek $<,>$; interval ek olarak $+,-$; ratio ek olarak $*,/$.
- Ayrık ve sürekli ayrımı ayrı bir eksendir; gerçek dünya çoğunlukla süreklidir.
- Metin verisi document-term matrix ile kayıt verisine çevrilir.

## Detaylı Açıklamalar

- **Veriyi tanımak neden önemli?** Veri madenciliği yöntemleri girdinin türüne duyarlıdır. Ders, önce verinin satır ve sütun yapısını, sonra her sütunun hangi türden değer taşıdığını tanıtır. Bir sonraki adım olan ön işlemede (normalizasyon, kategorik değerlerin sayısala çevrilmesi) bu tür bilgisi gerekir. Yanlış türde bir işlem, örneğin Celsius değerlerini oranlamak ya da kimlik numaralarının ortalamasını almak, anlamsız sonuç üretir.
- **Dört tür arasındaki hiyerarşi.** Türler, desteklediği işlemlere göre iç içe geçer. Nominal yalnız eşitliği sorgular. Ordinal buna sıralamayı ekler; "küçük < orta < büyük" denebilir ama aradaki farkın ne kadar olduğu bilinmez. Interval buna eşit aralıklı farkı ekler; 15 ile 20 °C arasındaki fark 5 ile 10 °C arasındaki farka eşittir. Ratio buna gerçek sıfırı ekler; böylece "iki katı" gibi oransal ifadeler anlamlı olur. Kelvin'de 0 K gerçek bir sıfırdır, Celsius'ta 0 °C keyfi bir başlangıçtır.
- **Yaş örneği.** Derste yaşın neden ratio olduğu soruldu. Eksi yaş yoktur, sıfır anlamlı bir başlangıçtır ve "bu kişi diğerinin iki katı yaşamış" denebilir. Bu yüzden yaşta dört işlem de anlamlıdır.
- **Doküman verisinin tabloya çevrilmesi.** Örnek tabloda (ekrandan, 00:50:00) team, coach, play, ball, score, game, win, lost, timeout, season sütunları vardır. Document 1 satırı 3, 0, 5, 0, 2, 6, 0, 2, 0, 2 değerlerini alır; yani team 3 kez, coach hiç, play 5 kez geçmiştir. Document 2: 0, 7, 0, 2, 1, 0, 0, 3, 0, 0. Document 3: 0, 1, 0, 0, 1, 2, 2, 0, 3, 0. Bu gösterim kelime sırasını kaybeder ve eş sesli kelimeleri ayırt edemez; bu yüzden metin sınıflandırmada sınırlı başarı verir.

- **Ders sonrası not (çubuk örneği).** Hoca 1, 2, 3 ve 5 birimlik çubukları anlatırken, uzunlukları birim katı olarak yazmayı ratio, santimetreyle ölçmeyi (1,3 cm, 2,6 cm gibi) interval diye örnekledi. Slaytta ise uzunluk ratio örneğidir. Santimetreyle ölçülen uzunluğun da gerçek sıfırı vardır (0 cm = uzunluk yok) ve 2,6 cm, 1,3 cm'nin iki katıdır; bu yüzden büyük olasılıkla bu ölçüm de ratio sayılmalıdır. <!-- BELİRSİZ: 00:32:26-00:33:11 arası altyazı kopuk, hocanın bu ayrımla tam olarak neyi kastettiği net değil. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
