# Ders 11 Çalışma Özeti

## Genel Konular

- Örnek tabanlı öğrenme (instance-based learning)
  - Instance, verideki tek bir örnek (sample), yani tablodaki bir satırdır.
  - Bu yaklaşımda eğitim verisinden bir model üretilmez. Örneklerin kendisi model gibi kullanılır: test örneğine en çok benzeyen eğitim örneklerinin sınıfı, test örneğinin sınıfı kabul edilir.
  - Bu yöntemlere tembel öğrenme (lazy learning) denir. Model kuran karar ağacı gibi yöntemlere ise hevesli öğrenme (eager learning) denir.
- k-en yakın komşu (k-nearest neighbor, kNN) sınıflandırması (ekrandan, 00:10:00)
  - Bütün eğitim örnekleri $\langle x_i, \text{Class}(x_i)\rangle$ biçiminde saklanır. Yeni bir $x_q$ için en yakın $k$ komşuya bakılır.
  - $k=1$ ise en yakın eğitim örneği $x_n$ bulunur ve $\text{Class}(x_q) = \text{Class}(x_n)$ olur.
  - $k>1$ ise en yakın $k$ örneğin sınıfları arasında çoğunluk oylaması yapılır: $y' = \arg\max_v \sum_{(x_i,y_i)\in D_z} I(v = y_i)$. Burada $I(\cdot)$ koşul doğruysa 1, değilse 0 veren gösterge fonksiyonudur.
  - Uzaklık olarak genellikle Öklid uzaklığı kullanılır: her özniteliğin farkının karesi toplanır, karekökü alınır.
  - $k$ genellikle tek sayı (3, 5 gibi) seçilir; böylece oylamada eşitlik çıkmaz.
- kNN örneği (ekrandan, 00:15:00)
  - Eğitim verisi: (1,1) no, (2,1) no, (3,2) yes, (7,7) yes, (8,8) yes. Sorgu örneği $\langle 3,3\rangle$.
  - Uzaklıklar: $\sqrt{8}$, $\sqrt{5}$, $\sqrt{1}$, $\sqrt{32}$, $\sqrt{50}$.
  - 1-NN: en yakın (3,2), sınıf yes. 3-NN: en yakın üç örnek iki no, bir yes verir; sonuç no.
- Uzaklık ağırlıklı kNN (distance weighted kNN) (ekrandan, 00:20:00)
  - Her komşunun oyu eşit sayılmaz; oy, uzaklığın karesinin tersiyle ($w = 1/d^2$) ağırlıklandırılır. Yakın komşunun etkisi büyük, uzaktakinin etkisi küçük olur.
  - Aynı örnekte no ağırlığı $1/8 + 1/5 = 13/40$, yes ağırlığı $1/1 = 1$. $1 > 13/40$ olduğu için sonuç yes olur.
- kNN'nin sorunları (ekrandan, 00:25:00)
  - $k$ çok küçükse gürültülü noktalara duyarlı olur. $k$ çok büyükse komşuluğa başka sınıfların noktaları girer.
  - Ölçekleme: değer aralığı büyük olan öznitelik uzaklığa hâkim olur. Bu yüzden kNN'den önce öznitelikler normalize edilir (örneğin 0-1 aralığına).
  - Eğitim zamanı yoktur ama test zamanı pahalıdır: her sorguda bütün örneklerle uzaklık hesaplanır. Büyük veride çok yavaş çalışır.
  - Hızlandırma fikri: veri uzayı ızgaralara (grid) bölünür, önce sorgunun düştüğü bölge bulunur, sonra yalnız o bölgedeki örneklerle karşılaştırma yapılır.
- NumPy
  - NumPy (Numerical Python), çok boyutlu diziler için `ndarray` (n-dimensional array) veri tipini sunar; Pandas da NumPy üzerine kuruludur.
  - `ndarray`, C dizilerine benzer: boyutu sabittir ve bütün elemanlar aynı tiptedir. Python listesi ise dinamik büyür ve farklı tipte eleman alabilir.
  - Boyut değiştirilirse bellekte yeni bir dizi ayrılır, elemanlar kopyalanır, eski dizi silinir.
  - Örnek (ekrandan, 00:45:00): `a = np.array([[3., 0.], [20., 230.], [21., 275.]])`; `a[2,0]` ve `a[2][0]` sonucu `21.0`; `a[:2, :]` ilk iki satırı verir. İndeksleme 0'dan başlar; satır yönü axis 0, sütun yönü axis 1'dir.
  - `shape` boyutu (3, 2), `dtype` veri tipini (`float64`), `itemsize` eleman başına bayt sayısını (8) verir.
  - Dilimleme bir görünüm (view) döndürür. View üzerinde yapılan değişiklik asıl diziyi de değiştirir.
  - `reshape` yeni şekilli diziyi döndürür, asıl diziyi değiştirmez; `resize` dizinin kendisini değiştirir (ekrandan, 00:50:00).
  - `a.sum()`, `a.max()` gibi hazır fonksiyonlar vardır; `a.sum(axis=0)` sütun toplamlarını verir: 44 ve 505.
  - Yapılandırılmış diziler (structured arrays): sütunlara ad ve ayrı tip verilebilir (`'Age'` int, `'Weight'` float); `a['Age']` → `[3, 20, 21]` (ekrandan, 00:55:00).
- Pandas veri yapıları: Series ve DataFrame
  - Series tek boyutlu veridir (sinyal, zaman serisi gibi). DataFrame iki boyutludur: sütunlar öznitelik, satırlar örnek (instance) karşılığıdır.
  - Series oluşturma (ekrandan, 01:15:00): `pd.Series([3, 20, 21], index=[...], name='Age')`. `index` değerlere ad verir, `name` serinin adıdır; ikisi de isteğe bağlıdır. `s.array` değerleri indekssiz verir.
  - Eksik değer NaN ile gösterilir (C'deki null'a benzer).
  - Series dilimi de view'dur; dilimde yapılan değişiklik asıl seriye yansır.
  - İki seri toplanınca indekse göre otomatik hizalama yapılır (ekrandan, 01:20:00). Karşılığı olmayan indeks NaN olur; `s.add(u, fill_value=0)` ile eksik taraf 0 kabul edilir.
  - DataFrame, serilerden oluşan bir sözlük (dictionary of series) gibi düşünülebilir. `df.shape` (3, 2), `df.size` 6, `df.columns`, `df.index`, `df.dtypes` gibi özellikleri vardır (ekrandan, 01:25:00).
  - `df.head(n)` ilk n satırı (varsayılan 5), `df.tail(n)` son n satırı gösterir. `df.to_numpy()` NumPy dizisine dönüştürür.
  - Mantıksal indeksleme: `df[df['A'] > 0]` A sütunu pozitif olan satırları getirir; `df[df > 0]` negatif değerleri NaN yapar. Döngü yazmadan vektörel olarak çalışır.
- Eksik veri ve diğer Pandas işlemleri (ekrandan, 01:35:00)
  - `dropna` NaN içeren satır ya da sütunları siler; `fillna(value=0)` NaN'ları verilen değerle doldurur; `isna` her hücre için NaN olup olmadığını gösterir.
  - `pd.read_csv(dosya, index_col=...)` dosyayı ya da web adresindeki CSV'yi okur; `to_csv` DataFrame'i CSV'ye yazar.
  - `value_counts` her değerin kaç kez geçtiğini sayar (histogram gibi). `concat`, `append`, `merge` (veritabanındaki join gibi) birleştirme yapar.
  - `groupby('A').sum()` A sütunundaki değerlere göre gruplar ve diğer sütunları toplar (Excel'deki pivot tabloya benzer).
  - Kategorik veri: `pd.Series(["a","b","c","a"], dtype="category")` (ekrandan, 01:40:00).
  - Matplotlib ile çizim: `cumsum` ile kümülatif toplam alınıp `plot` ile çizdirilir.
- Google Colab ve uygulama
  - Colab, Jupyter Notebook gibi çalışan, kurulum gerektirmeyen bir ortamdır; metin ve kod hücreleri vardır, GPU/TPU seçilebilir.
  - Örnek: bir DataFrame oluşturulup `to_csv(..., index=False)` ile kaydedildi ve `files.download` ile indirildi; CSV'nin virgülle ayrılmış düz metin olduğu gösterildi (ekrandan, 01:45:00 ve 01:50:00).
  - Iris verisi `files.upload()` ile yüklenip `pd.read_csv` ile okundu (ekrandan, 02:15:00). Veride indeks sütunu yokken `index_col=0` verilirse ilk öznitelik indeks gibi okunur.
  - `describe` sayısal sütunların sayı, ortalama, min, max ve çeyrek (%25, %50 = medyan, %75) değerlerini verir.
  - Seçim: `iloc` satır/sütun numarasıyla (`iloc[0]`, `iloc[:, -1]`, `iloc[0:5, 1:3]`), `loc` etiketle (`data.loc[data['b'] == 1.4]`, koşul ve sütun listesiyle) seçim yapar.
- scikit-learn ile karar ağacı sınıflandırması
  - Akış: Pandas ile veri okunur ve temizlenir, eğitim ve test kümesine ayrılır, scikit-learn'deki yöntemle model kurulur.
  - `load_iris()` ile 150 satırlık Iris verisi alınır, `feature_names` sütun adı yapılarak DataFrame kurulur, sınıflar `target` sütununa (0, 1, 2) konur (ekrandan, 02:25:00).
  - `train_test_split(X, y, test_size=0.2, random_state=42)`: eğitim 120×4, test 30×4. Test kümesinde 10 tane 0, 9 tane 1, 11 tane 2 sınıfı var (ekrandan, 02:30:00).
  - `DecisionTreeClassifier(max_depth=2)`; `fit(X_train, Y_train)` modeli eğitir, `predict` tahmin eder, `score(X_test, Y_test)` doğruluğu verir. Hoca sonucu yaklaşık 0.96 diye okudu; ekrandaki tahmin dizisinde 30 örnekten 29'u doğrudur ($29/30 \approx 0{,}967$) (ekrandan, 02:35:00).
    <!-- BELİRSİZ: 02:35:00 karesinde score çıktısı 0.9333 görünüyor; tahmin dizisiyle uyuşmadığından büyük olasılıkla eski bir çıktıdır. -->
  - Döngüyle `max_depth` 1'den 5'e değiştirildi: derinlik 1'de doğruluk yaklaşık 0.63, derinlik 4 ve 5'te %100.
  - Ödev niteliğinde örnek: meyve sınıflandırma tutorial'ı (59 meyve, 7 öznitelik); Seaborn ile histogram/boxplot/scatter, `MinMaxScaler`, karar ağacı, kNN, Gaussian Naive Bayes, SVM, `confusion_matrix` ve `classification_report` (precision, recall, F1) (ekrandan, 02:40:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- kNN'de öznitelikleri normalize etmek
  - Bir özniteliğin aralığı 0-1, diğerininki ±1 milyon ise uzaklığı büyük aralıklı öznitelik belirler ve diğeri hiç etkili olmaz.
- kNN'nin maliyeti test zamanındadır
  - Model kurulmadığı için eğitim hızlıdır; ama her sorguda bütün örneklerle uzaklık hesaplandığı için büyük veride çok yavaştır. Dengeli bir ağaçta arama $\log n$ iken burada $n$ karşılaştırma gerekir.
- View davranışı
  - NumPy dizisinin ya da Pandas serisinin bir dilimi üzerinde değişiklik yapmak asıl veriyi de değiştirir. Verinin bir kısmıyla çalışırken bu unutulmamalıdır.
- `pd`, `np` kısaltmaları
  - `import pandas as pd`, `import numpy as np` fiilî standarttır; başkası kodu okuyacağı için başka kısaltma uydurulmamalıdır.
- Hazır fonksiyonların parametreleri
  - scikit-learn'de karar ağacı, Naive Bayes, Random Forest, AdaBoost gibi her yöntemin parametreleri vardır; kullanılan yöntemin parametrelerine mutlaka bakılmalıdır.
- Hata alınca
  - Anlaşılmayan hata mesajı kopyalanıp internette (Stack Overflow vb.) aranmalıdır.

## Kısa Tekrar Notları

- Instance-based learning model kurmaz; lazy learning'dir. Karar ağacı gibi model kuranlar eager learning'dir.
- kNN: en yakın $k$ komşunun sınıfına çoğunluk oylaması; uzaklık Öklid; $k$ tek sayı seçilir.
- $\langle 3,3\rangle$ örneği: 1-NN → yes, 3-NN → no, uzaklık ağırlıklı 3-NN → yes (no: $13/40$, yes: $1$).
- Ağırlık $w = 1/d^2$.
- $k$ küçük → gürültüye duyarlı; $k$ büyük → başka sınıflar karışır. Öznitelikler normalize edilmeli.
- `ndarray`: sabit boyut, tek tip; liste: dinamik, karışık tip.
- `reshape` yeni dizi döndürür, `resize` diziyi kendisi değiştirir.
- Series 1 boyut, DataFrame 2 boyut; eksik değer NaN.
- `dropna`, `fillna`, `isna`; `read_csv`, `to_csv`; `head`, `tail`, `describe`; `groupby`; `iloc` (numara), `loc` (etiket).
- `train_test_split` → `fit` → `predict` → `score`.

## Detaylı Açıklamalar

- **kNN ve uzaklık ağırlıklı kNN.** kNN'de test örneği için bütün eğitim örnekleriyle Öklid uzaklığı hesaplanır: $d(x_i, x_q) = \sqrt{\sum_j (x_{ij} - x_{qj})^2}$. En küçük $k$ uzaklık seçilir ve bu komşuların sınıflarında çoğunluk oylaması yapılır. Ders örneğinde $\langle 3,3\rangle$ için (1,1) noktasına uzaklık $\sqrt{(3-1)^2 + (3-1)^2} = \sqrt{8}$, (2,1) noktasına $\sqrt{1+4} = \sqrt{5}$, (3,2) noktasına $\sqrt{1}$ çıkar. En yakın komşu yes olduğu için 1-NN yes der; ama en yakın üç komşuda iki no bulunduğundan 3-NN no der. En yakın komşunun daha uzaktaki iki komşu tarafından "yenilmesi" uzaklık ağırlıklı kNN'yi doğurur: her komşunun oyu $1/d^2$ ile çarpılır. No için $1/8 + 1/5 = 13/40$, yes için $1/1 = 1$ çıkar ve sonuç yes olur.
- **Derste çözdürülen alıştırma.** Yine iki öznitelikli, 3 yes ve 2 no sınıflı beş örnekli bir veri kümesinde $\langle 5,5\rangle$ için 3-NN istendi. En yakın üç komşu uzaklığı $\sqrt{10}$ ve $\sqrt{5}$ olan iki yes ile uzaklığı 1 olan bir no idi. Ağırlıksız oylamada sonuç yes, uzaklık ağırlıklı oylamada yes için $1/10 + 1/5 = 3/10$, no için $1$ çıktığından sonuç no oldu.
  <!-- BELİRSİZ: Alıştırmanın veri tablosu karelerde görünmüyor; yalnız altyazıdaki uzaklıklar ($\sqrt{32}$, $\sqrt{10}$, $\sqrt{5}$, 1 ve (6,5) noktası) biliniyor. -->
  - Ders sonrası not: Hoca yes ağırlığı için "3 bölü 15 gibi bir şey" dedi; doğrusu $1/10 + 1/5 = 3/10$. Sonuç (no) değişmez.
- **NumPy'ın hızı.** `ndarray`'in bütün elemanları aynı tipte ve aynı boyutta olduğu için bellekte art arda durur; işaretçi her seferinde sabit adım (örneğin 8 bayt) ilerler. Bu, vektörel işlemlerin (çarpma, toplama, koşullu seçme) C/Fortran ile yazılmış alt katmanda hızlı yapılmasını sağlar. Python listesinde elemanların boyutları farklı olabildiğinden bu hız yoktur.
- **Pandas'ta indeks.** Series ve DataFrame'deki indeks veri değildir, satırlara verilen addır. Zaman serisinde tarihleri indeks yapmak belli bir tarihteki değere doğrudan erişmeyi kolaylaştırır. Gerçek veri kümelerinde satırlara genellikle ad verilmez, indeks 0'dan otomatik ilerler.
- **Veri temizlemede mantıksal indeksleme.** C'de iki iç içe döngü ve if ile yapılacak "şu eşikten büyük değerleri sil/değiştir" işlemi Pandas'ta `df[df > 0]` gibi tek ifadeyle, vektörel olarak yapılır. Eksik değerler `fillna` ile sabit bir değerle doldurulabilir ya da `dropna` ile atılabilir.
- **scikit-learn akışı.** Veri `X` (öznitelikler) ve `y` (sınıf etiketleri) olarak ayrılır. `train_test_split` veriyi rastgele böler; `random_state` tekrarlanabilirlik için verilen tohumdur. Model `fit` ile eğitim verisine uydurulur, `predict` ile test örneklerinin sınıfı tahmin edilir, `score` tahminlerin kaçının `y_test` ile aynı olduğunu (doğruluk) verir. Iris örneğinde derinliği 2 olan ağaç 30 test örneğinin 29'unu doğru bildi (yaklaşık 0.96); derinlik artırılınca doğruluk %100'e çıktı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
