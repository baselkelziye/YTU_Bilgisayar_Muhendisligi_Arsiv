# Ders 7 Genişletilmiş Notu: Makine Öğrenmesinde Yeni Problemler (Devam): Çok Görevli Eğitimden Hayat Boyu Öğrenmeye

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Tekrarı: Aktif Öğrenme, Yarı Eğiticili Öğrenme, Öğrenmenin Transferi
- 2. Çok Görevli Eğitim (Multi-task Learning)
- 3. Hiperparametre Optimizasyonu
- 4. Aktif Örnekleme (Active Sampling)
- 5. İnsan-Makine İşbirliği ve Zayıf Denetim
- 6. Az Sayıda Örnekle Eğitim: One-shot ve Zero-shot Öğrenme
- 7. Veri Zenginleştirme (Data Augmentation)
- 8. ML Algoritmalarını Kandırmak (Adversarial Attacks)
- 9. Planlı Öğrenme (Curriculum Learning)
- 10. Hayat Boyu Öğrenme (Lifelong Learning)
- 11. Ders Sonu Sorusu: Dengesiz Metin Verisi
- Örnek Sorular
- Dersin Toparlaması

## 1. Önceki Dersin Tekrarı: Aktif Öğrenme, Yarı Eğiticili Öğrenme, Öğrenmenin Transferi

Ders, "Makine öğrenmesinde yeni problemler" başlıklı slayt dizisinin (bolum4) devamıydı. Hoca önce geçen hafta işlenen üç konuyu öğrencilere sorarak hatırlattı.

### 1.1 Aktif öğrenme

**Soru:** Aktif öğrenme neydi, ne amaçla kullanılıyordu? **Cevap:** Bir öğrenci, veri kümesinin küçük bir kısmıyla eğitime başlayıp kullanıcıdan istenen örneklerin etiketlerini alarak veri kümesini büyüten bir yöntem olduğunu söyledi. Hoca bunu düzeltip tamamladı: örnekler zaten eldedir, "örneklerin olmaması" diye bir durum yoktur. Algoritma "sen bunun etiketini ver bana" der. Amaç daha az etiketli örnekle iş yapabilmek, yani etiketleme maliyetini azaltmaktır.

> **Hocanın vurgusu:** Noktaları (örnekleri) elde etmek genelde kolay, etiketlerini elde etmek genelde pahalıdır. Aktif öğrenmede tasarruf edilen şey etiketlerdir.

### 1.2 Yarı eğiticili öğrenme

**Soru:** Yarı eğiticili öğrenme neydi? **Cevap:** Bir öğrenci, verilerin bir kısmının etiketli, bir kısmının etiketsiz olduğu durum olarak tanımladı. Hoca ekledi: etiketsizleri de sürece katmak istiyoruz. Etiketli verilerle etiketsizlerin etiketleri tahmin edilir ve bu tahmini etiketler de kullanılarak yalnız etiketli verilerle elde edilecek performanstan daha yüksek bir performans hedeflenir.

Slayttaki basit örnekte (ekrandan, 00:10:00) içi beyaz ve içi siyah iki etiketli nokta, bir de çok sayıda gri (etiketsiz) nokta vardır. Yalnız iki etiketli noktayla model kurulursa ayırıcı ikisinin ortasından geçen düz bir çizgidir. Etiketsizlerin etiketleri tahmin edilip hesaba katılırsa ayırıcı, veri yığınlarının arasından kıvrılarak geçebilir.

Hoca bu tahminin tek adımda yapılmasının iyi bir yaklaşım olmayabileceğini hatırlattı. Elde yalnız iki etiketli nokta varken tek adımda bütün etiketsizler tahmin edilirse model yine aynı düz çizgiyi kullanır: çizginin solundakilerin hepsi beyaz, sağındakilerin hepsi siyah olur. Bunun yerine iteratif ilerlemek daha mantıklıdır: önce etiketli noktalara en yakın etiketsiz noktalar etiketlenir (bunlar beyaz, şunlar siyah), sonra yeni etiketlenenlere yakın olanlar, böylece devam edilir. Kıvrımlı bir yığının hepsini doğru sınıfa etiketleyebilmek için bu iteratif süreç gerekir.

İteratif süreç sona kadar gitmek zorunda değildir. Etiketsiz verilerin hepsini etiketleyip katmak şart değildir, çünkü bazıları işe yaramayabilir, hatta modeli bozabilir.

Hoca geçen haftanın `semi_supervised_learning.m` grafiklerine yeniden baktı. Supervised ve batch çizgileri tek seferde, tek adımda yapılan işlemlerdir; iteratif çizgide dalgalanma vardır. Dalgalanmanın sebebi, eklenen etiketlerin gerçek etiket değil tahmin olmasıdır. autos veri kümesinde başta az sayıda tahmini etiketli örnek katmak daha iyi sonuç verirken, audiology veri kümesinde bütün etiketsizleri etiketleyip katmak iyi bir sonuç gibi görünmektedir; yani kural her durumda geçerli değildir.

### 1.3 Öğrenmenin transferi ve önceden eğitilmiş modeller

Öğrenmenin transferi, bir problemi çözdükten sonra benzer bir problemi sıfırdan çözmek yerine önceki bilgileri kullanmaktır. Hoca bugün işin büyük ölçüde önceden eğitilmiş (pretrained) modellere döndüğünü söyledi. Bu modeller büyük problemler üzerinde eğitilir: klasik problemler olabileceği gibi, gerçekte var olmayan, araştırmacının veriden kurduğu yapay görevler de olabilir. <!-- BELİRSİZ: altyazıda "Poseidon tasklar"; büyük olasılıkla "pretext task" ya da "pseudo task" --> Böyle bir görevin çözümü başka problemlerin çözümüne de yardımcı olur.

Örnekler: metin işlemede bir kelimeyi kapatıp onu tahmin etmek. Normalde böyle bir uygulamaya ihtiyaç yoktur, ama bu görevle model eğitilebilir. Görüntü işlemede "şu iki resim parçası aynı resimden mi?" sorusu da böyle bir görevdir; bu tür görevler özellikle karşıtlıklı (contrastive) modellerin önceden eğitiminde kullanılır.

Transfer edilebilecekler: veriler, modelin tamamı, metinler için kelime vektörleri, resimler için CNN filtreleri (yani filtre katsayıları). Transfer, yeni problem için yeterli veri yoksa ve eski ile yeni problem ilgiliyse işe yarar. Slayttaki grafikte "aggressive" çizgisi çok fazla bilgi transferini gösterir; benzer bir karakteristik yarı eğiticili öğrenme için de söylenebilir: etiketsiz verilerin hepsini etiketleyip katmak agresif, bir kısmını katmak daha temkinli bir yaklaşımdır.

Hoca, ilgililiği artırmak için önceden eğitim tarafında yapılanı anlattı. Örneğin kuş türü ayıran bir model için önceden eğitimde yalnız kuş veri kümesi kullanılmaz; her türlü nesnenin olduğu veri kümeleri kullanılır ki modeli sonra kim alırsa işine yarasın. Metinde de BERT gibi önceden eğitilmiş modeller her konudan metin verisiyle eğitilir.

## 2. Çok Görevli Eğitim (Multi-task Learning)

### 2.1 Tanım ve transferden farkı

Çok görevli eğitim, aynı anda birden fazla şey öğrenmektir. Ardışık biçimi de vardır, ama derste ele alınan eşzamanlı (simultaneous) olanıdır: birden fazla görevi aynı anda öğrenmek, örneğin hem satranç hem dama oynayabilen tek bir sistem kurmak.

Transfer öğrenmede bir kaynak görev (source task) vardır; o problem çözülür, elde edilen bilgi başka bir probleme aktarılır. Çok görevli öğrenmede ise bütün görevler birbiriyle etkileşim hâlindedir ve birbirine fayda sağlayabilir.

### 2.2 Görüntüde örnek: bölütleme, örnek ayırma ve derinlik

Slayttaki örnekte (ekrandan, 00:16:30) girdi, caddede yürüyen insanların olduğu bir resimdir. Tek bir Encoder'ın çıkışı üç ayrı çözücüye gider:

- Semantic Decoder: resmin bölgelerini belirler (anlamsal bölütleme).
- Instance Decoder: her bir birimi (her bir insanı) ayrı ayrı bulur.
- Depth Decoder: resmin derinlik haritasını çıkarır.

Her çözücünün çıkışı bir görev belirsizliğiyle (Semantic/Instance/Depth Task Uncertainty) birleşir ve bunlar toplanarak tek bir Multi-Task Loss oluşur. Üç görev aynı yapının içinde birlikte öğrenilir. Hoca, derinliği farklı olan şeylerin büyük olasılıkla farklı nesneler olduğunu, yani bölütlemede derinlik bilgisinin işe yarayabileceğini söyledi. Birbirine fayda sağlayabilecek görevlerin birlikte öğrenilmesi anlamlıdır; birbiriyle alakasız şeyleri birlikte öğrenmek belki çok fayda sağlamayacaktır.

### 2.3 NLP'de örnek: NLP Decathlon

NLP alanında soru cevaplama, duygu analizi, makine çevirisi gibi pek çok farklı görev vardır. NLP Decathlon'u (decaNLP) hazırlayanlar, var olan bütün görev türlerini bir soru-cevap biçimine dönüştürmüştür (ekrandan, 00:20:00). Her örnek üç parçadan oluşur: soru (Question), bağlam (Context), cevap (Answer). Slayttaki örneklerden bazıları:

| Görev | Soru | Bağlam (kısaltılmış) | Cevap |
|---|---|---|---|
| Soru cevaplama | What is a major importance of Southern California in relation to California and the US? | ...Southern California is a major economic center for the state of California and the US... | major economic center |
| Çeviri | What is the translation from English to German? | Most of the planet is ocean water. | Der Großteil der Erde ist Meerwasser |
| Özetleme | What is the summary? | Harry Potter star Daniel Radcliffe gains access to a reported £320 million fortune... | Harry Potter star Daniel Radcliffe gets £320M fortune... |
| Doğal dil çıkarımı | Hypothesis: Product and geography are what make cream skimming work. Entailment, neutral, or contradiction? | Premise: Conceptually cream skimming has two basic dimensions – product and geography. | Entailment |
| Duygu analizi | Is this sentence positive or negative? | A stirring, funny and finally transporting re-imagining of Beauty and the Beast and 1930s horror film. | positive |
| SQL'e çeviri | What is the translation from English to SQL? | The table has column names... Tell me what the notes are for South Australia | SELECT notes from table WHERE 'Current Slogan' = 'South Australia' |

Doğal dil çıkarımı (textual entailment) problemi, bir cümle doğruyken ötekinin de kesinlikle doğru olup olmadığını sorar. Bu görevde sistemin bunu anlaması için başlara "Hypothesis" ve "Premise" gibi küçük etiketler eklenmiştir. Duygu analizinde soru "pozitif mi negatif mi?", bağlam cümlenin kendisi, doğru cevap "positive"dir.

Farklı türdeki görevler aynı biçime çevrilince hepsi için aynı mimari kullanılabilir ve hepsi birlikte eğitilebilir; bu yüzden NLP Decathlon çok görevli bir eğitimdir. Hocanın aktardığına göre, örneğin soru cevaplamayı tek başına öğrenmek yerine diğer görevlerle birlikte öğrenmenin performansı daha yüksek çıkmıştır.

### 2.4 Hocanın deneyi: ilgisiz görevler tek ağda öğrenilebilir mi?

Hoca, birbiriyle alakası olmayan görevlerin de aynı anda öğretilip öğretilemeyeceğini merak ederek küçük bir deney yaptı (`multi_task_learning.m`, ekrandan, 00:22:40). Beş veri kümesinin yalnız iki boyutu alınmıştır; hepsi iki boyutlu ve iki sınıflıdır. Girdileri ve çıktıları birbirinden farklıdır, ama biçimleri aynıdır. 10 gizli nöronlu bir YSA eşit eğitim süresiyle eğitilmiş, farklı başlangıçlarla 3 deneme yapılmıştır.

Çok görevli eğitimde beş veri kümesi birlikte tek ağa verilir. Ağın hangi görevde olduğunu anlayabilmesi için X1 ve X2'nin yanında bir görev (veri kümesi) kimliği de verilmelidir; hem eğitimde hem testte. Kimlik olmazsa ağ aynı iki boyutlu uzaydaki noktaların hangi probleme ait olduğunu ayırt edemez.

Slayttaki sonuçlar (tr_acc eğitim, acc test doğruluğu):

| Deneme | Ölçü | VK1 | VK2 | VK3 | VK4 | VK5 |
|---|---|---|---|---|---|---|
| 1 | single_tr_acc | 1.0000 | 0.5875 | 0.8462 | 0.9714 | 0.7663 |
| 1 | single_acc | 0.9067 | 0.5017 | 0.6923 | 0.9771 | 0.7554 |
| 1 | multi_tr_acc | 0.9333 | 0.5611 | 0.7483 | 0.9657 | 0.7609 |
| 1 | multi_acc | 0.8667 | 0.4785 | 0.7343 | 0.9656 | 0.7935 |
| 2 | single_tr_acc | 1.0000 | 0.5479 | 0.8671 | 0.9771 | 0.7989 |
| 2 | single_acc | 0.9467 | 0.5050 | 0.7063 | 0.9656 | 0.7228 |
| 2 | multi_tr_acc | 0.8133 | 0.5446 | 0.7692 | 0.9600 | 0.7935 |
| 2 | multi_acc | 0.7200 | 0.4983 | 0.7413 | 0.9656 | 0.7446 |
| 3 | single_tr_acc | 0.9733 | 0.5380 | 0.8112 | 0.9686 | 0.7935 |
| 3 | single_acc | 0.9200 | 0.4521 | 0.6783 | 0.9656 | 0.7772 |
| 3 | multi_tr_acc | 0.9600 | 0.4785 | 0.7662 | 0.9571 | 0.7446 |
| 3 | multi_acc | 0.9600 | 0.4884 | 0.7203 | 0.9570 | 0.7772 |

Hoca ilk denemeyi okudu: tek başına eğitimde birinci veri kümesinin eğitim doğruluğu %100, diğerleri %58.75, %84.6, %97.1, %76.6; test doğrulukları eğitimden doğal olarak daha düşüktür (%90.7, %50.2, ...). Birlikte eğitimde de doğruluklar "korkunç kötü" değildir. <!-- BELİRSİZ: hocanın veri kümesi bazında karşılaştırmayı söylediği sayılar (00:23:42-00:24:09) altyazıda bozuk; değerler slayttan alındı -->

Test doğruluklarının ortalamaları (python ile hesaplandı, ara adım eklendi):

| Deneme | single_acc ortalaması | multi_acc ortalaması |
|---|---|---|
| 1 | 0.7666 | 0.7677 |
| 2 | 0.7693 | 0.7340 |
| 3 | 0.7586 | 0.7806 |

Veri kümesi bazında da kazanan denemeden denemeye değişir: örneğin VK3'te üç denemenin üçünde de birlikte eğitim daha iyidir, VK1'de ise ilk iki denemede tek başına eğitim daha iyidir. Hocanın yorumu: tek tek ve birlikte eğitim birbirinden çok farklı değildir; bazen biri, bazen öteki daha iyidir. "Tek başına eğitmenin performansı kesinlikle daha yüksektir" denemez. İlgisiz görevler aynı ağın içinde eğitildiğinde hâlâ eğitilebilmektedir; yani aynı mimari kabaca farklı görevleri tutabilmektedir.

Bulgu ve yorum slaytındaki açık sorular: iyileşmenin olduğu veri kümeleri vardır, ama genel bir şey söylemek için çok daha fazla deneme gerekir. Bir ağ kaç problemi kapsayabilir? 10 gizli nöronlu tek bir ağ beş veri kümesini öğrenebildi; bu sayı 50'ye çıkarılsa hâlâ iyi öğrenebilir mi?

## 3. Hiperparametre Optimizasyonu

### 3.1 Hiperparametre nedir?

**Soru:** Hiperparametre ne demekti? **Cevap:** Hoca: algoritmanın kendisinin öğrenemediği, bizden beklediği, dışarıdan müdahale edebildiğimiz parametrelerdir. Örnekler: k-NN'de k, bütün iteratif algoritmalardaki öğrenme katsayısı, hangi optimizasyon yönteminin kullanılacağı.

**Soru:** Bir algoritmanın çok sayıda hiperparametresi olmasının avantaj ve dezavantajları nedir? **Cevap:** Öğrencilerin cevabı ve hocanın onayı: dezavantajı, çok sayıda olasılık olması ve hepsinin denenmesinin çok uzun sürmesidir. Avantajı, algoritmaya doğrudan müdahale edilebilmesi, yani algoritmanın esnek olmasıdır.

### 3.2 Kaç deneme gerekir?

Hoca şu örneği verdi: 5 hiperparametre var, her biri 10 farklı değer alabiliyor. Bütün olasılıkları denemek için kaç deneme gerekir?

- Verilen: 5 hiperparametre, her biri 10 değer.
- İşlem: birinci için 10, ikinci için 10, ... seçenek; seçenekler çarpılır.
- Sonuç: $10 \times 10 \times 10 \times 10 \times 10 = 10^5 = 100\,000$ deneme.

Her deneme bir eğitim demektir. Eğitim kısa sürüyorsa belki yapılabilir, ama bir eğitimin bir saat sürdüğü düşünülürse bütün olasılıkları denemek çok uzun zaman alır.

### 3.3 Arama yöntemleri

Slayt (ekrandan, 00:30:00) soruyu şöyle koyar: hiperparametre uzayının hangi noktalarında deneme yapalım? Seçenekler: ızgara (grid) arama, rastgele arama, Bayesian optimization.

Hiperparametreler ayrık ya da sürekli olabilir. k-NN'deki k ayrıktır (1, 2, 3, 4, 5, ...). Bir yapay sinir ağının öğrenme katsayısı (ör. 0.01) ise süreklidir; sonsuz farklı değer alabilir, hepsini denemek mümkün değildir. Bu yüzden sürekli durumda bile sonlu sayıda örnek değer (bir küme) seçmek gerekir; bu da ızgara aramaya denk gelir.

- Izgara arama: her boyutta kaç deneme yapılacağı belirlenir ve ızgaranın noktaları sistematik olarak denenir.
- Rastgele arama: ızgaranın üzerinde rastgele dolaşmak (random walk) gibidir; "şunu deneyeyim, şunu deneyeyim", toplamda belirli sayıda deneme.
- Bayesian optimizasyon: eldeki deneme sonuçlarına göre en fazla iyileşmenin sağlanabileceği değeri tahmin eder.

### 3.4 Bayesian optimizasyon sezgisi

Slayttaki grafikte (ekrandan, 00:30:00) x ekseni hiperparametre değeri, y ekseni modelin başarısıdır. Mavi daireler eldeki deneme sonuçları, kırmızı daire en fazla iyileşmeyi sağlayacağı tahmin edilen değerdir.

Hoca adım adım bir örnek kurdu:

- 1, 2 ve 4 değerleri denenmiştir. 1'den 2'ye başarı artmış, 4'te bir miktar düşmüştür.
- Bir sonraki deneme nerede yapılmalı? 1'den önce, 4'ten sonra, yoksa 2 ile 4 arasında mı? Kesinlikten değil olasılıktan söz ediyoruz; ama 1→2 arasında bir yükselme eğilimi var ve 4 düşük olduğuna göre, 2 ile 4 arasında daha yüksek bir yer olabilir.
- 3 denenmiş ve başarı 2'dekinden biraz yüksek çıkmış olsun. Artış 1→2→3 boyunca sürmektedir. Artışın biraz daha sürüp sonra düşeceğine inanılıyorsa bir sonraki deneme örneğin 3.5 civarında yapılabilir.

Aralarda çok dar bir aralıkta kocaman bir tepe de olabilir, ama bunlar çok istenen şeyler değildir. Bayesian optimizasyon verilere interpolasyon uygular ve bu interpolasyonun maksimum olacağını tahmin ettiği yeri bir sonraki nokta olarak belirler.

> **Ek bilgi (derste anlatılmadı):** Bayesian optimizasyonda deneme sonuçlarına genellikle bir Gauss süreci (Gaussian process) uydurulur. Sonraki nokta, yalnız tahmini ortalamanın değil belirsizliğin de hesaba katıldığı bir edinim fonksiyonuyla (ör. beklenen iyileşme, expected improvement) büyük olasılıkla seçilir.

## 4. Aktif Örnekleme (Active Sampling)

### 4.1 Aktif öğrenmeden farkı

Aktif örnekleme Bayesian optimizasyondan esinlenmiştir: kullanıcıdan girdi uzayı için yeni örnekler istenebilir mi? Aktif öğrenmede, hangi örneklerin çıkışlarını (etiketlerini) kullanıcıdan isteyeceğimizi belirliyorduk. Aktif örneklemede ise örneklerin kendisi, yani girdisi ve çıktısı istenir.

Diğer yöntemlerin hepsinde veriler, etiketli ya da etiketsiz, hazırdı. Burada veriler hazır değildir; en azından bir miktar etiketli veri vardır ve bunlarla model kurulur. Sonra "bana şu bölgeden, şu tarz girdiler ver" denir.

### 4.2 `active_sampling.m` örneği

Slayttaki örnek (ekrandan, 00:40:00) bir regresyon problemidir: x ekseni girdi, y ekseni çıktıdır; mavi noktalar eldeki eğitim kümesidir. Sağdaki grafikte, farklı eğitim kümeleriyle eğitilmiş modellerin tahmin eğrileri üst üste çizilmiştir. Slayt metni:

- Model varyansının en yüksek olduğu yerler = tahminlere en az güvenebileceğimiz yerler.
- Modelin bir noktadaki varyansı, farklı eğitim kümeleri için o noktanın tahminlerinin standart sapmasıdır.
- Buralardan yeni örnek istemeliyiz.

Kırmızıyla işaretlenmiş x ≈ 0.2 civarında modellerin tahminleri birbirinden çok farklıdır; o bölgedeki tahminler güvenilir değildir. **Soru:** Kırmızı bölge nasıl bir bölge, orada elimizde ne yok? **Cevap:** Veri yok. O bölgede çok fazla veri olmadığı için modelin varyansı yüksektir.

### 4.3 Metinde aktif örnekleme

Hoca duygu analiziyle bir benzetme yaptı. Etiketli verilerle bir model kurdunuz. Bazı kelimeler hem pozitif hem negatif sınıfta geçiyor, ya da bir kelime yalnız pozitiflerde geçiyor ama yalnız bir iki kez. O kelimenin güvenilir olup olmadığını bilemezsiniz. Twitter için duygu analizi yapıyorsanız "içinde şu kelime ya da şu kelime geçen tweetleri topla ve etiketleyip getir" diyebilirsiniz. Ekrandaki regresyon örneğinde istek "0.2 civarından örnek ver" diye tarif edilir; metinde ise "içinde şu kelimeler geçen" diye tarif edilir.

Aktif örnekleme çok daha etkileşimli bir süreçtir: model "şu noktada bir örnek alayım" diye örnek ister. Bu aslında deney tasarımına benzer. Kullanıcıdan istenen noktalar, o noktalarda deney yapılması gerektiğini söyler; deney sonucu da "şu girdiye karşılık şu çıktı" diye bir örnek olur. Bu yüzden fiziksel değil yazılımsal anlamda bilimsel araştırmalara yardımcı robotlarda aktif örnekleme kullanılabilir. Aktif örnekleme, diğerlerinden farklı olarak hangi girdi ve çıktıların isteneceğinin de bulunduğu bir süreçtir.

## 5. İnsan-Makine İşbirliği ve Zayıf Denetim

### 5.1 İnsanlar ve makineler

Slayt (ekrandan, 00:41:40): "the combination of human and machine intelligence / Human in loop / weak supervision". Amaç insanları süreçten tamamen çıkarmak değil, insan ile makinenin iyi taraflarını birleştirmektir.

- İnsanlar (yavaş, doğru):
  - Veri etiketleyebilir.
  - Tahminleri düzeltebilir.
  - Tahminler arasından seçim yapabilir (100 sınıftan en olası 5'inden doğru olanı seçebilir).
  - Örneklerin ortak bir özelliği için kural verebilir ("İçinde şu ifade geçenler negatiftir", "Kedilerin kuyruğu vardır").
- Makineler (hızlı, çok sayıda bilgiyle başa çıkabilir, az doğru):
  - Tahmin üretebilir.

### 5.2 Video etiketleme

Dışarıda sabit bir kamera, örneğin yukarıdan bir otoparka bakıyor olsun; bir araç bir noktadan başlayıp yolda ilerliyor. Bütün karelerdeki arabanın etiketlenmesi gerekir. Saniyede 30 kare varsa ve aracın yolu 30 saniye sürüyorsa:

- Verilen: 30 kare/saniye, 30 saniye.
- İşlem: $30 \times 30$.
- Sonuç: 900 kare.

Bu 900 karenin her birinde arabayı tek tek işaretlemek insan için "ızdıraptır". Bunun yerine insan birkaç anahtar karede "burada araba var, burada da var, aynı araba" diye işaretler; aradaki yüzlerce kareyi makine öğrenmesiyle eğitilmiş sistemler otomatik doldurur.

Çeviride de bugün otomatik çeviri artı insan düzeltmesi yaygınlaşmıştır.

### 5.3 Zayıf denetim (weak supervision)

Klasik yapıda her örneğe tek tek etiket verilir: 1. örnek → etiketi, 2. örnek → etiketi (ekrandan, 00:50:00). Zayıf denetimde ise kural yazılır:

- Kural1: metnin içinde «çekmiyor» varsa negatiftir.
- Kural2: ... (ör. "harikasın" varsa pozitiftir).

Bu bir etiket değil, bir kuraldır. Tek bir kural, içinde "çekmiyor" geçen bütün metinleri birden etiketler. Kuralları insanlar oluşturur ve asıl iş budur; ama bu yaklaşım, kurallar uygunsa (alana bağlı olarak) tek tek etiketlemeden çok daha hızlı olabilir.

**Soru:** Buradaki sıkıntı nerede olabilir? Kural 1 ve kural 2 ne yapabilir? **Cevap:** Öğrenciler kuralların birbiriyle çelişebileceğini ve örtüşebileceğini söyledi; hoca onayladı. Bir metnin içinde hem pozitife hem negatife dair ifadeler olabilir. Klasik yapıda örneğin kendisine bakılıp etiket verildiği için böyle bir durum oluşmaz. Kurallı yapıda ise çelişen örnekler eğitim kümesine belki hiç alınmaz.

### 5.4 Kuralların birleştirilmesi (Snorkel)

Hoca, Snorkel'e bakılabileceğini söyleyip fikri kabaca anlattı ve ekranda bir tablo kurdu (ekrandan, 00:53:30): satırlar kurallar, sütunlar örneklerdir; her hücre, o kurala göre o örneğin pozitif mi negatif mi olduğunu gösterir. En alta bir satır eklenir; burası birleştirme kuralının sonucudur.

| | örnek1 | örnek2 | ... | örnekN |
|---|---|---|---|---|
| Kural1 | + | − | | − |
| Kural2 | + | + | | + |
| ... | | | | |
| kuralM | − | − | | − |
| birleştirme | ? | | | |

Birleştirmede örneğin kuralların çoğu ne diyorsa o yazılabilir: 5 kural "+", 3 kural "−" diyorsa sonuç "+" olur. İnsanlar kural üretir, bu kurallarla örnekler etiketlenir, çelişen durumlar için bir çözüm mekanizması geliştirilir; böylece örneklerin her birine tek tek bakmadan etiketleme yapmak mümkün olur.

**Soru:** Kural1'de metnin içinde "çekmiyor" varsa negatif dedik. Yoksa pozitif mi oluyor? Tabloda kural1 örnek1 için "+" demiş. **Cevap:** Hoca, kuralın uygulanmadığında ne diyeceğinin tasarımcıya bağlı olduğunu söyledi. Bir hücrenin olası değerleri üçtür: pozitif, negatif ya da hiçbir şey söylememek (çekimser, soru işareti). "Varsa negatif, yoksa pozitif" gibi kurallar da olabilir, ama bu tarz sistemlerde kuralların genelde çekimser kalan bir tarafı olur.

> **Ek bilgi (derste anlatılmadı):** Snorkel'de bu tür kurallara "labeling function" denir. Snorkel, büyük olasılıkla basit çoğunluk oyunun ötesinde, kuralların doğruluklarını ve aralarındaki ilişkileri etiketsiz veriden tahmin eden bir etiket modeliyle olasılıklı etiketler üretir; bu etiketlerle sonra asıl sınıflandırıcı eğitilir.

## 6. Az Sayıda Örnekle Eğitim: One-shot ve Zero-shot Öğrenme

### 6.1 Chollet'nin sözü

Aradan sonra hoca, Keras'ın geliştiricisi François Chollet'nin bir sözünü okuttu (ekrandan, 01:10:00):

> "Any problem can be treated as a pattern recognition problem if your training data covers a sufficiently dense sampling of the problem space. What's interesting is what happens when your training data is a sparse sampling of the space -- to extrapolate, you will need intelligence."

Hocanın yorumu: eğitim verisi uzayı yoğun biçimde kaplıyorsa iş çok kritik değildir; bu biraz ezberlemeye benzer. Örnekler uzayda seyrek yer aldığında ekstrapolasyon ya da interpolasyon yapmak için zekâya ihtiyaç vardır. Yani az sayıda örnekle eğitim asıl kritik olan şeydir.

### 6.2 One-shot (tek çekimle) öğrenme

Her sınıf için çok az ya da tek bir örneğin olduğu problemlerdir. Örneğin zürafa sınıfına ait tek bir örneğin olması ile çok sayıda örneğin olması çok farklıdır. Bütün zürafaları sisteme gösterebilirseniz öğrenmesi kolaydır; mühim olan az şeyle öğrenebilmektir.

### 6.3 Zero-shot (sıfır çekimle) öğrenme

Zero-shot, one-shot'ın bir adım ötesidir (ekrandan, 01:11:40):

- Test örneklerini eğitim kümesinde hiç örneği bulunmayan sınıflara atama yapabilmek.
- Eğitim kümesindeki sınıflarla test kümesindeki sınıflar ayrıktır.
- Çok kipli (multimodal) yaklaşımlar kullanılır. Kip; görüntü, metin, ses gibi her bir veri türüdür.
- Örnek: eğitim sürecinde her eğitim örneğinin tanımları (attribute), sınıfı ve resmi vardır. Çıkarım (inference) sürecinde ise tanım-yeni sınıflar matrisi ve test örneğinin tanımları vardır.

Hoca bunun "çok garip" göründüğünü, ama tanımlar üzerinden yeni sınıflara geçilebildiğini belirtti.

> **Ek bilgi (derste anlatılmadı):** Tanımlara dayalı zero-shot öğrenmenin klasik örneği büyük olasılıkla şudur: model resimden "çizgili", "dört bacaklı", "at benzeri" gibi tanımları tahmin etmeyi öğrenir. Eğitimde hiç zebra görmemiş olsa bile, zebra sınıfının tanımları verildiğinde test resminin tahmin edilen tanımlarını bu tanım vektörüyle eşleştirerek "zebra" diyebilir.

### 6.4 Google'ın zero-shot makine çevirisi

Hoca zero-shot'ın belki en iyi kullanım alanı olarak Google'ın makine çevirisini gösterdi (ekrandan, 01:14:00). Bir çeviri sisteminde girdi A dilinde, çıktı B dilindedir; örneğin İngilizce'den Japonca'ya çeviri için birebir eşlenmiş paralel derlemlere ihtiyaç vardır.

Google çok sayıda dil için çeviri yapar. Slayt:

- Her olası dil ikilisi için ayrı birer model eğitmek yerine (100 dilden 100 dile),
- A→B ve B→C var, A→C yok,
- Girişler ortak bir katmana,
- Çıkışlar ortak bir katmandan.

Örneğin İngilizce-Fransızca ve Fransızca-Türkçe paralel derlem var, İngilizce-Türkçe yok. Bütün diller ortak bir yere indirilir ve her şey ortak bir yerden dönüştürülür. Slayttaki görselleştirmede her nokta bir cümledir. Kümelerden biri büyütüldüğünde, aynı anlamlı farklı kaynak dillerdeki (İngilizce, Korece, Japonca) cümlelerin temsillerinin uzayın benzer bölgelerinde olduğu görülür.

Bunun önemi: paralel derlemler insanlar arasında ticaret, hukuk gibi bir etkileşim olduğunda oluşur. Aralarında hiçbir bağlantı olmayan iki ülkenin dilleri arasında paralel derlem oluşmaz. Ortak yapı olmadan 100 dilden 100 dile çeviri yapmak kabaca mümkün değildir.

## 7. Veri Zenginleştirme (Data Augmentation)

Veri zenginleştirme, yeni eğitim verileri üretmektir: görüntüler için, metinler için ve genel veriler için.

**Soru:** Elimizde eğitim kümesi zaten var; niye yeni eğitim verileri üretmeye uğraşıyoruz? **Cevap:** Bir öğrenci, etiketlerin zaten elde olduğunu, veriyi biraz bozarak yeni etiketli veri elde edilebileceğini ve bunun daha iyi bir model üretmeye yardım edebileceğini söyledi. Hoca onayladı: gerçekten elde olmayan ve iyi veriler üretilebilirse bu faydalı olur.

> **Hocanın vurgusu:** Veri zenginleştirmede "bedavadan" etiketli veri üretiyoruz: elde bir tane etiketli veri var, oradan bir sürü etiketli veri üretiyorsunuz.

### 7.1 Görüntüler için

Slayt (ekrandan, 01:16:15), Simard ve ark. 2003'ten MNIST rakamları üzerinde dönüşümler gösterir:

- A satırı: orijinal örnekler.
- B satırı: yatay eksende eğme (horizontal shearing).
- C satırı: 35 derece döndürme.
- D ve E satırları: farklı derecelerde elastik deformasyon.

Slaytta ilgili kodlar da anılır: processMNISTdata.m, d2gauss.m, data_aug.m.

Bir sonraki slayttaki dönüşümler (ekrandan, 01:20:00): rastgele kırpma, ayna yansıması, renk bilgilerinde değişim vb. Kelebek örneğinde orijinal resimden dokusu kaldırılmış (de-texturized), rengi kaldırılmış (de-colorized), kenarları güçlendirilmiş (edge enhanced), belirgin kenar haritası (salient edge map) ve çevrilmiş/döndürülmüş (flip/rotate) sürümler üretilir.

Hoca, derin öğrenmeyi büyük ilgi odağı yapan 2012 makalesinde (Krizhevsky ve ark. 2012, ImageNet sınıflandırması) rastgele kırpmanın kullanıldığını anlattı. Resmin tamamını tek seferde vermek yerine etiketli bir kedi resminden 224×224'lük çok sayıda parça kesilir ve hepsi "kedi" olarak işaretlenir. Bazı parçalar pek kediye benzemeyebilir, ama parçaların büyük kısmı kedi içerdiği sürece bu büyük bir sorun değildir.

Bu her zaman işe yaramaz. **Soru:** Kırpma karesinin büyüklüğü küçültülürse kedi olmayan resim üretme şansı ne olur? **Cevap:** Artar. Bu yüzden kırpma kutusu yeterince büyük olmalıdır.

Hoca, ImageNet'in WordNet'in resimlerle zenginleştirilmesi için başlatılmış bir çalışma olduğunu hatırlattı (WordNet'teki synset'ler, kavramlar ve o kavramlara ait resimler). Genelde bir resimde bir kavram, bir nesne vardır. Ama içinde farklı nesneler olan resimlerde rastgele kırpılan parçalar aynı şeyi göstermeyebilir. Örneğin bir çocuk parkı resminde kırpılan parça yalnız bir çocuğu gösterebilir ve o çocuk "çocuk parkı" diye etiketlenir; hoca, çocuk parkında çocuk olmasının anormal olmadığını, bunun çok kötü bir durum olmayabileceğini söyledi. İçinde tek bir kedi ya da tek bir kelebek olan resimlerde ise farklı parçalar alınsa da nesnenin ne olduğu yine ortaya çıkar.

### 7.2 Üretici çekişmeli ağlar (GAN)

Sınıflandırıcılar sınıfları birbirinden ayırt eden modeller kurar, yani karar sınırları üretir. Regresörler sayı tahmin eder, yüzeyler öğrenir. Üretici (generative) modellerin yaptığı ise temelde örnek üretmeyi öğrenmektir: "elimde böyle bir küme var, bu kümeden bana yeni örnekler üret."

Hoca bunu iki boyutlu bir örnekle anlattı: ekranda yeşil noktalardan oluşan bir küme vardır. "Bu yeşillerden yeni bir örnek üretin" denince, kümenin şekline uyan yeni noktalar (turuncu noktalar) üretmek mümkündür. Bir sınıftan noktalar verilir ve o türden yeni noktalar üretilmesi istenir. Yüz üretmek için sisteme çok sayıda yüz resmi verilir, sistem yeni yüzler üretir; kedi için de aynı. İlginç olan, yüzlerin iki boyutlu değil çok yüksek boyutlu olmasına rağmen bunun başarılı yapılabilmesidir.

GAN iki ağdan oluşur. "Üretici" kısmı üretmesinden gelir. "Çekişmeli" kısmı ise iki ağın çekişmesidir: biri kandırmaya, öteki kanmamaya çalışır.

- Üretici ağ: rastgele bir gürültüden eğitim kümesine benzer örnekler üretmeye çalışır.
- Ayırt edici ağ: gerçek eğitim örnekleri ile yapay örnekleri birbirinden ayırmayı öğrenir.

**Soru:** Ayırt edici ağ gerçek ve yapay örnekleri çok iyi ayırabiliyorsa bunun anlamı nedir? **Cevap:** Bir öğrenci, üreticinin gerçeğe çok benzer örnekler üretemediğini söyledi; hoca onayladı. Ayırt edici çok başarısızsa tam tersi geçerlidir: artık gerçeklerle yapayları ayıramıyordur, yani üretici başarılıdır. Üretici ağ çok başarılıysa ayırt edici ağ doğal olarak başarısız olur.

Slayttaki örnekte üstte sistemin ürettiği insan yüzleri, altta her birine eğitim kümesindeki en benzer gerçek yüzler gösterilmiştir. Hoca, üretilen yüzlerin bu gerçek yüzlerin birleştirilmesiyle elde edildiğinin düşünülmemesi gerektiğini, yalnız en benzeyenlerin gösterildiğini belirtti. Bu tür resimleri gördükçe ayırt etmeyi öğrenmek mümkündür ("bunu GAN mı üretti, insan mı?" testlerinde insanlar genelde başarılı olur): arka plan genelde bulanık (blurry, soft), ön plan daha ayrıntılıdır.

GAN'lar özellikle görüntülerde çok gerçekçi yapay örnekler üretir. Hocaya göre metinler için henüz aynı şeyi söylemek mümkün değildir; metin üretme sistemleri vardır ama GAN'larla çok başarılı sonuçlar henüz elde edilememiştir. Veri zenginleştirme için GAN kullanmak biraz pahalı olabilir, ama uygulanamayacak bir şey değildir.

### 7.3 Metin verileri için

Slayt (ekrandan, 01:30:00):

- Eş anlamlı kelime / deyişler:
  - "Bizim oğlan komşu kızına abayı yakmış" → "Bizim oğlan komşu kızına aşık olmuş"
  - "Bir gün bana yaptıklarının acısını senden çıkaracağım" → "Senden intikamımı elbet alacağım" <!-- BELİRSİZ: ilk cümlenin ortası karede araç çubuğunun altında kalıyor; "acısını senden çıkaracağım" kısmı altyazıdan -->
- Çeviri:
  - orijinal örnek → başka bir dildeki karşılığı → yeni örnek
  - "Sinema salonunda kırmızı ayakkabıları olan bir kadın gördüm" → "Sinema salonunda kırmızı ayakkabılı bir kadın gördüm."

Amaç benzer anlamlı bir cümle oluşturmaktır; bu işe yeniden ifade etme (paraphrasing) da denir ve kolay bir işlem değildir. Hoca bunu Chollet'nin sözüne bağladı: sistemler örneklerini gördükleri, verinin yoğun olduğu bölgelerde bunu yapabilir, ama dilde uzay genel olarak hep seyrektir.

Çeviriyle zenginleştirmeye geri çeviri (back-translation) denir ve basit bir yoldur. Metin başka bir dile (ör. İngilizce'ye) çevrilir, sonra geri çevrilir. A'dan B'ye, sonra B'den A'ya çevrildiğinde A1 cümlesinden A2 cümlesi elde edilir; ikisi tamamen aynı olmaz, ama genelde anlamca benzerdir (bazen komik sonuçlar da çıkabilir). Araya birkaç ara dil (hop) konabilir: A→B→C→D→A. Zincir uzadıkça A1 ile A2 birbirine daha az benzer. Hoca bunu kulaktan kulağa oyununa benzetti: herkes duyduğunu ötekine aktarır, sona doğru cümle değişir. Ne kadar benzer ya da ne kadar farklı örnek istendiğine göre zincir seçilir. Geri çeviri, veri zenginleştirme için görece ucuz bir yoldur.

### 7.4 Genel amaçlı veriler için

Slayt (ekrandan, 01:40:00): görüntülerde ve metinlerde etiketi değiştirmeyen dönüşümler kullandık (insan yüzlerinden yeni insan yüzleri, bir metinden benzer bir metin). Genel amaçlı (UCI vb.) veri kümelerinde (iki boyutlu, beş boyutlu, yüz boyutlu, kategorik değerli) ne yapılabilir? Burada etiketi değiştirmeyen dönüşümleri tanımlamak kolay değildir.

Birinci seçenek: her sınıf için bir olasılık yoğunluk fonksiyonu (pdf, probability distribution function) tahmin edip ondan yeni örnekler üretmek. Hoca ekranda turuncu noktalar çizip bunlara bir pdf uydurulduğunu ve bu pdf'ten kırmızı yeni noktalar üretilebileceğini gösterdi. Ancak pdf her zaman doğru tahmin edilemez; iki boyutta belki daha kolaydır, ama çok boyutlu verilerde tahmin edilen pdf'ler çok başarılı olmayabilir.

İkinci seçenek SMOTE'tur. SMOTE dengesiz veri kümeleri için önerilmiştir: örneğin örneklerin %5'i bir sınıftan, %95'i diğer sınıftan olsun. Küçük olan azınlık (minority) sınıftan yeni örnekler üretmek için kullanılır; ama yalnız buna özel değildir, herhangi bir veri kümesinde örnek üretmek için kullanılabilir. Slayttaki tanım:

- Az örnekli sınıftan bir örneğe en yakın k komşusunu bul.
- Bunlardan onunla aynı sınıfta olan birini seç.
- Bu ikisini birleştiren çizgi üzerinde yeni bir örnek üret.

Slayttaki şekilde (ekrandan, 01:40:50) taralı kareler çoğunluk sınıfı (majority class samples), siyah noktalar azınlık sınıfı (minority class samples), kırmızı noktalar sentetik örneklerdir (synthetic samples). Bir azınlık örneği x1 için kendi sınıfından en yakın örnekler x2, x3, x4, x5, x6'dır. Bunlardan biri, örneğin x3 seçilir ve x1 ile x3'ü birleştiren çizginin üzerinde yeni bir örnek (a ya da b gibi) üretilir; diğer komşularla c, d, e gibi örnekler üretilir.

> **Ek bilgi (derste anlatılmadı):** SMOTE'ta yeni örnek genellikle $x_{\text{yeni}} = x_i + \lambda\,(x_{\text{komşu}} - x_i)$ ile üretilir; burada $\lambda$, 0 ile 1 arasında rastgele seçilen bir sayıdır. Böylece yeni örnek iki örneği birleştiren doğru parçasının üzerinde bir yere düşer.

Slaytın sağ tarafı SMOTE'un bir sorununu ve çözümünü anlatır. SMOTE özellikle karar sınırına yakın yerlerde yapay örnek ürettiğinde sert sınıf geçişlerini zorlaştırır. Bunu önlemek için SMOTE-IPF geliştirilmiştir (Sáez ve ark. 2015):

1. Önce SMOTE ile örnekler üretilir.
2. Sonra hem orijinal hem yeni üretilmiş örneklerden bazıları elenir. Elemede veri kümesi k adet eşit parçaya bölünür.
3. Her bir parça kullanılarak bir model eğitilir.
4. Ardından tüm modeller tüm veri kümesi üzerinde tahmin yürütür; her veri için k adet tahmin üretilir.
5. Bu tahminlerin tutarsız olduğu örnekler veri kümesinden çıkarılır.

Bu eleme ile karar sınırlarının daha yumuşak modellenebilir hâle gelmesi amaçlanmaktadır. <!-- BELİRSİZ: slayt metninin başında "SMOTE-IBF" yazıyor, kaynakça ve metnin devamı "SMOTE-IPF"; büyük olasılıkla yazım hatası -->

Hoca, son zamanlarda bu fikrin resimlere de uygulandığını söyledi. İki köpek resmi de aslında birer noktadır: 100×100'lük bir resim 10 000 boyutlu uzayda bir noktadır. İki nokta arasındaki çizgi tanımlanabilir ve oradan yeni örnekler üretilebilir. Yani yalnız tablo biçimindeki veri kümelerinde değil, resim ya da metin veri kümelerinde de bu yapılabilir.

## 8. ML Algoritmalarını Kandırmak (Adversarial Attacks)

### 8.1 Eski bir olay, yeni bir boyut

Slayt (ekrandan, 01:45:20): "Kararlar makinelere bırakıldığı anda onları kandırma çalışmaları da başlar." Örnek: istenmeyen e-postalar. Spam filtreleri birer karar vericidir; e-postanın spam olup olmadığına karar verir. Bu kararı makinelere bırakmış durumdayız, çünkü uğraşmaya vaktimiz yok ve spam olmayan bir şeye spam demesi çok sık olmadıkça onlara güveniyoruz. Ama bir kararın makinelere bırakıldığı anda birileri onları kandırmaya çalışır; makineler de bir şekilde kolay kanan sistemlerdir.

### 8.2 Papağan ve kitaplık

Derin öğrenme mimarilerinin başarılarının ardından şu ortaya çıktı. Slayttaki üç resimden en soldaki orijinal bir papağandır; Inception v3 mimarisine göre %97 olasılıkla "papağan"dır. Bu resmin üzerine, özel olarak hazırlanmış sağdaki gürültü eklenerek ortadaki resim oluşturulmuştur. Aynı Inception mimarisine göre ortadaki resim %99 olasılıkla "kitaplık"tır.

Hoca, sağdaki gürültünün görselde abartıldığını, gerçekte çok daha küçük bir oranla (binde bir gibi) eklendiğini söyledi. Gürültü rastgele değildir; bu resme "kitaplık" dedirtmek için üretilmiştir, ama kitaplıkla bir ilgisi yoktur. İnsan ortadaki resme hâlâ papağan der; makine diyemez.

> **Hocanın vurgusu:** Derin öğrenme mimarileri olayları bizim gördüğümüz gibi görmez. "Gagası var, kuş, şu renkler var" gibi bir mekanizma yoktur; çok küçük, minimal desenler yakalanır ve bütün kararlar onların üzerinden verilir. Bu desenler orijinal görüntüde korunur; saldırı, bu desenleri istenen sınıfın (kitaplığın) desenine doğru çeker.

Slaytta ayrıca "Daha önce gördüğümüz GAN'lar bu tür ataklara karşı dayanıklı mimariler üretmek için geliştirilmiştir" yazmaktadır.

> **Ders sonrası not:** Slaytta GAN'ların bu tür ataklara karşı dayanıklı mimariler üretmek için geliştirildiği yazıyor. Büyük olasılıkla GAN'lar (Goodfellow ve ark. 2014) öncelikle gerçekçi örnek üretmek (üretici modelleme) için önerilmiştir; ataklara dayanıklılık için daha çok saldırı örnekleriyle eğitim (adversarial training) kullanılır. İki fikir aynı "çekişme" sezgisini paylaşır ve GAN'lar savunma amacıyla da kullanılmıştır.

### 8.3 Yarışmalar ve tek piksel

Slayt (ekrandan, 01:50:00):

- Sadece derin öğrenme mimarileri tehdit altında değil.
- Bir Kaggle yarışması (3 görev), NIPS 2017:
  - Hedef belli atak ("şu resme şunu dedirt"): elde hazır mimariler vardır; size bir resim ve hedef sınıf (ör. "kitaplık") verilir, mimarinin o resme "kitaplık" demesini sağlayacak resmi üretirsiniz.
  - Hedef belirsiz atak ("kandır"): hedef sınıf yoktur; papağana papağan dışında ne derse desin, kandırmak yeterlidir.
  - Savunma.
- Sadece tek bir piksel değişimiyle bile mümkün (arXiv 1710.08864).

Hocaya göre bu konuda hâlâ sıkıntı vardır: her türlü atağa karşı bir savunma yoktur, çünkü atakların nasıl üretileceği tam bilinemez. Sorun şudur: insan baktığında o hâlâ bir papağandır, insanlar buna kanmaz.

### 8.4 Neden önemli?

Spam kararı makineye bırakılabilir; ama arabaların gidişinin kararı makinelere bırakılırsa (kendi kendine giden araçlar) birisi görü sistemlerini kandırmak için atak düzenlediğinde ne olacak? Trafik levhalarının üzerine bazı desenler yapıştırılarak örneğin bir yasak levhasının başka bir levha olarak algılandığı örnekler vardır. Hoca bir de, bir dönem gösterilerde yüz tanıma sistemlerini kandırmak için özel desenli tişörtler giyildiğini hatırlattı: yüz tanıma sistemleri önce insanı bulur, sonra yüzü; tişörtün üzerindeki özel tasarlanmış desen, papağan örneğindeki gürültü gibi, "insan var"ı "insan yok"a çevirebilir. Bunlar ticari ya da kritik kararlar makinelere bırakılırken düşünülmesi gereken problemlerdir.

## 9. Planlı Öğrenme (Curriculum Learning)

### 9.1 Örneklerin sırası önemli mi?

Slaytta (Bengio ve ark. 2009'a atıfla) konu şöyle açılır: yeni örnekler geldiğinde eğitime baştan başlaması gerekmeyen öğreniciler (online learning) için örneklerin öğreniciye veriliş sırası önemli midir? Bir müfredat oluşturulmalı mıdır?

İnsanlar bir müfredatla öğrenir: önce çizgi çizmek, sonra eğik çizgiler, sonra harfler ve sesler, sonra heceler, kelimeler, cümleler, sonra kapsamı daha geniş konular. "Curriculum" zaten müfredat demektir; "müfredatlı öğrenme" diye de çevrilebilir, hoca slaytta "planlı öğrenme" demiştir. Örnekler öğreniciye rastgele değil, bir müfredat dahilinde gelir: önce kolaylar (makine için kolay ne demekse), sonra biraz daha zorlar. Bunun faydası olup olmadığı üzerine çalışmalar sürmektedir.

Eldeki tüm veriler müfredata dahil edilmeli midir? Şart değildir. Aktif öğrenmede örneklerin sırasına karışmak, müfredatı kısıtlamak gibi düşünülebilir. Veriler sıralanıp verilirken bazı örnekler işe yaramaz bulunursa dışarı atılabilir.

### 9.2 "Kime göre kolay?"

Slayt (ekrandan, 01:55:20):

- İnsanlar için müfredat: ilköğretim, lise, üniversite, ...; kolaydan zora?
- Örneklerin kolaylık ölçütü?
  - Önceden belirlenip sabit kalsın:
    - İnsan belirler.
    - Bir algoritmanın sınıflara atama olasılıkları.
    - Geometrik yaklaşımlar (Ho ve ark. 2002).
  - Öğrenme sırasında değişsin (self-paced learning).

Hoca "kolaydan zora"daki soru işaretini açıkladı: üniversitedeki biri için ilköğretim müfredatı kolaydır, ama ilköğretim öğrencisine kendi müfredatı belki üniversite öğrencisine kendi müfredatının geldiğinden daha zor gelir. Yani "kime göre kolay?" sorusu vardır. Yine de genel bir bakış açısıyla bir sıralama yapılabilir.

### 9.3 Kolaylık nasıl ölçülür?

Algoritmanın sınıf olasılıklarını kullanmak, aktif öğrenmedeki fikre benzer. Aktif öğrenmede sınıf olasılıkları birbirine yakın (ör. %33, %33, %33) olan örnek için karar verilemediğinden onun etiketi isteniyordu. Burada etiketler bilinir; bir model eğitilir ve modele göre bir örneğin her sınıfa ait olma olasılıkları birbirine çok yakınsa, o örnek zor bir örnek sayılabilir.

Geometrik yaklaşımlarda minimum yayılan ağaç (minimum spanning tree) gibi yapılar kurulur. Çok sayıda bağlantısı olan, çok şeyin ortasında duran bir örnek iyi bilinen, kolay bir örnektir. Uzakta duran ve benzeri pek olmayan örnek zor sayılabilir.

İnsan belirlemesine örnek (slayt "Örneklerin zorlukları"): şekil sınıflandırmada ilk satır basit, ikinci satır zor örneklerdir. Resimler gerçek değil, belli kurallarla (GAN'la değil) üretilmiştir. Kolay örneklerde eşkenar üçgenler, daireler ve kareler vardır ve arka plan ile ön plan renkleri arasında büyük fark vardır. Zor örnekler çeşitkenar üçgenler, elipsler ve dikdörtgenlerdir. Varsayım, bir dairenin elipse göre, eşkenar üçgenin çeşitkenara göre daha kolay öğrenileceğidir; hoca bu varsayımın ne kadar geçerli olduğundan emin olmadığını söyledi. Problem, şeklin dairemsi mi, üçgenimsi mi, karemsi mi olduğunu bulan üç sınıflı bir problemdir. Araştırılan soru şudur: bütün örnekleri karışık vermek yerine önce kolayları, sonra zorları vermek sistemin daha iyi öğrenmesini sağlar mı? Metin için insan belirlemesi düşünülürse çok geçen kelimelerin kolay, kısa cümlelerin kolay olduğu gibi varsayımlar denenebilir; ama bunları belirlemek kolay değildir.

### 9.4 Zorluğu ensemble belirlesin

Ensemble (kolektif öğrenme), tek bir model yerine çok sayıda model üretip kararlarını birleştirmektir: tek bir SVM, tek bir karar ağacı ya da tek bir yapay sinir ağı yerine birçok model eğitilir. En basit birleştirme "demokrasi usulü"dür: test örneği bütün modellere sorulur, söylediklerine göre son karar verilir.

Zorluk belirlemede: 10 model ayrı ayrı eğitilmiş olsun. 10 modelin hepsi aynı şeyi söylüyorsa örnek kolaydır. 5'i A, 5'i B diyorsa örnek zordur, çünkü ensemble'daki kararlar birbirinden çok farklıdır.

Slayttaki grafiklerde (ekrandan, 02:00:00) x ekseni eğitim ilerlemesi, y ekseni hatadır; mavi klasik (kolaylık-zorluğa bakmadan, rastgele sıra), kırmızı curriculum (önce kolaylar, sonra zorlar), pembe anti-curriculum (önce zorlar, sonra kolaylar) yaklaşımdır. Hocanın okumasına göre sol sütun eğitim, sağ sütun test kümeleridir. Bazı veri kümelerinde klasik yaklaşım eğitim hatasını daha çok düşürmüştür; bazılarında curriculum ve anti-curriculum testte daha düşük hata vermiştir. Bazen curriculum, bazen anti-curriculum başarılı olabilir. Bir sonraki slaytta ("Kolaydan zora / Zordan kolaya") UCI veri kümelerinde klasik, curriculum ve anti-curriculum karşılaştırması vardır; hocanın aktardığına göre curriculum genel olarak daha başarılı sonuçlar vermiştir. <!-- BELİRSİZ: "Kolaydan zora / Zordan kolaya" tablosunun değerleri karelerde okunamadı -->

## 10. Hayat Boyu Öğrenme (Lifelong Learning)

Slayt (ekrandan, 02:10:00):

- Öğrenme sürecinin bitmediği,
- Tüm eğitim verilerinin elde olmadığı / zaman içinde erişildiği,
- Test örneklerinin sadece eğitim örneklerinin sınıflarından gelmediği (Open World),
- Önceki öğrenilenlerin nelerin / nasıl öğrenileceğine etken olduğu,
- Endüstride daha yaygın olan

bir öğrenme biçimidir.

### 10.1 Zaman içinde değişen veri

Hoca duygu analizi örneğini verdi. Bir parti, bir kişi ya da bir firma kamuoyu algısını bedavaya, hızlı ve yaygın biçimde ölçmek ister. Örnekler toplanır, model eğitilir ve çalışmaya başlar. Ama bu model bir kez eğitilip iki yıl boyunca kullanılamaz: dil yaşayan bir şeydir, yeni kavramlar ve jargonlar çıkar. Kampanyalar ve sloganları kamuoyuna sunulur ve bunların nasıl algılandığını ölçmek gerekir. Basit sanılan bir duygu analizi problemi bile zamana bağlıdır: eğitim kümesinin toplandığı zamandan uzaklaştıkça işler karışır. Hoca, kendi yaptıkları analizlerde bazı yılların geçmiş verilere yakın durduğunu, bazı yılların ise uzaklaşabildiğini söyledi.

Çeviri sistemi için de aynısı geçerlidir: 10 yıl sonra aynı çeviri sistemini kullanmak mümkün değildir, çünkü insanların çevirmek isteyeceği cümleler ve kelimeler değişecektir. Bütün eğitim kümesini baştan oluşturmak kaynak yetersizliğinden değil, fiziksel bir kısıttan dolayı imkânsızdır: bunun için zamanda ileri gitmek gerekirdi. Bu yüzden model zaman içinde sürekli eğitim kümesi toplayıp öğrenmeye devam etmelidir.

### 10.2 Açık dünya (open world)

A, B ve C sınıflarını ayırmayı öğrenen bir resim sınıflandırıcı kurdunuz. Gerçek bir robot etrafta gezip nesneleri sınıflandırmaya çalışıyor olsun ve içine 10, 100 ya da 1000 sınıf koymuş olun. Robot gerçek dünyada çalışıyorsa, sizin koymadığınız sınıflardan nesnelere de rastlayacaktır. "Test örneklerinin sadece eğitim örneklerinin sınıflarından gelmemesi" bunu anlatır.

### 10.3 Önceki öğrenilenlerin etkisi ve endüstri

Ne bildiğiniz, neyi merak edeceğinizi, neyi öğrenmek isteyeceğinizi ve nasıl öğreneceğinizi etkiler; bu da hayat boyu öğrenmenin prensiplerinden biridir.

Akademik dünyada genelde bir veri kümesi alınır, üzerinde çalışılır, yayımlanır ve iş biter. Endüstride ise bir ürünün yaşam döngüsü (life cycle) vardır ve ürün bu süre boyunca yaşamak zorundadır. Özellikle dile bağlı ürünlerde (görüntüde de olabilir ama dilde çok daha bariz) bir kez eğitip bırakmak yetmez; sürekli bakım ve yeniden eğitim gerekir.

## 11. Ders Sonu Sorusu: Dengesiz Metin Verisi

**Soru:** 200-300 sınıflı bir metin sınıflandırma veri kümesi düşünelim; veri çok dengesiz, bir sınıfta 5000 örnek varken bir başkasında 50-100 örnek var. Aşırı örnekleme (oversampling) gerçekten başarılı sonuç verir mi? **Cevap:** Hoca, dengesiz veride metin verisini artırmak için çeşitli yöntemler (geri çeviri gibi) kullanılabileceğini, ama bunların ne kadar başarılı olacağının belli olmadığını söyledi. Bir başka yaklaşım, eğitime önce eşit sayıda sınıf örneğiyle başlayıp süreci sonra bütün veriyle tamamlamaktır. Buradaki yaklaşımların hiçbirinin veri kümesinden bağımsız olarak daha başarılı ya da başarısız olacağını söylemek mümkün değildir; Türkçe için de özel bir durum yoktur. Öğrencinin "deneyip göreceğiz" sonucuna hoca "veriden veriye değişiyor, aynen öyle" diye katıldı.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:02:50): Aktif öğrenme nedir ve ne amaçla kullanılır?

> **Çözüm (derste verildi):** Örnekler eldedir, ama etiketleri yoktur ya da pahalıdır. Algoritma etiketini istediği örnekleri kendisi seçer ("bunun etiketini ver"). Amaç daha az etiketli örnekle iş yapabilmek, yani etiketleme maliyetini düşürmektir.

**Soru 2** (derste sözlü, 00:04:15): Yarı eğiticili öğrenme nedir? Etiketsiz veriler süreçte nasıl kullanılır?

> **Çözüm (derste verildi):** Elde hem etiketli hem etiketsiz veri vardır. Etiketli verilerle etiketsizlerin etiketleri tahmin edilir ve tahmini etiketler de kullanılarak yalnız etiketlilerle elde edilecek performanstan daha yüksek performans hedeflenir. Tahmin tek seferde ya da (daha mantıklı olarak) iteratif yapılabilir; bütün etiketsizleri katmak şart değildir.

**Soru 3** (derste sözlü, 00:25:56): Hiperparametre nedir? Bir algoritmanın çok sayıda hiperparametresi olmasının avantajı ve dezavantajı nedir?

> **Çözüm (derste verildi):** Algoritmanın kendisinin öğrenemediği, dışarıdan verilen parametredir (k-NN'de k, öğrenme katsayısı, optimizasyon yöntemi). Avantajı algoritmanın esnek olması, doğrudan müdahale edilebilmesidir. Dezavantajı olasılık sayısının çok olması ve hepsini denemenin çok uzun sürmesidir.

**Soru 4** (derste sözlü, 00:27:45): 5 hiperparametre var ve her biri 10 farklı değer alabiliyor. Bütün olasılıkları denemek için kaç deneme gerekir?

> **Çözüm (derste verildi):** $10^5 = 100\,000$ deneme. Her deneme bir eğitimdir; eğitim bir saat sürüyorsa bu çok uzun zaman alır.

**Soru 5** (derste sözlü, 00:34:00): Bir hiperparametrenin 1, 2, 3 ve 4 değerleri denenmiştir; 1'den 3'e başarı artmış, 4'te düşmüştür. Bir sonraki deneme nerede yapılmalıdır?

> **Çözüm (derste verildi):** Artışın biraz daha sürüp sonra düşeceğine inanılıyorsa örneğin 3.5 civarı denenebilir. Bayesian optimizasyon bunu verilere interpolasyon uygulayıp interpolasyonun maksimumunu tahmin ederek yapar. Kesinlik değil olasılık söz konusudur.

**Soru 6** (derste sözlü, 00:37:43): Aktif örnekleme grafiğinde modellerin tahminlerinin çok farklı olduğu kırmızı bölge nasıl bir bölgedir?

> **Çözüm (derste verildi):** O bölgede eğitim verisi azdır. Veri az olduğu için modelin varyansı yüksektir; yeni örnekler o bölgeden istenmelidir.

**Soru 7** (derste sözlü, 00:45:17): 30 fps çekilmiş bir videoda bir araç 30 saniye boyunca hareket ediyor. Kaç karede etiket gerekir ve insan-makine işbirliği bunu nasıl kolaylaştırır?

> **Çözüm (derste verildi):** $30 \times 30 = 900$ kare. İnsan yalnız birkaç anahtar karede aracı işaretler ("burada araba var, burada da var, aynı araba"), aradaki kareleri eğitilmiş sistemler otomatik doldurur.

**Soru 8** (derste sözlü, 00:48:56): Zayıf denetimde (her örneğe etiket yerine kural yazmak) sıkıntı nerede olabilir?

> **Çözüm (derste verildi):** Kurallar birbiriyle çelişebilir ve örtüşebilir: bir metinde hem pozitife hem negatife dair ifadeler olabilir. Bu yüzden bir birleştirme mekanizması gerekir (ör. çoğunluk oyu); çelişen örnekler eğitime alınmayabilir.

**Soru 9** (ekrandan, 00:53:30): Aşağıdaki örnek × kural tablosunda birleştirme satırı ("?") çoğunluk oyuyla nasıl doldurulur? Yalnız görünen kurallar (Kural1, Kural2, kuralM) hesaba katılsın.

| | örnek1 | örnek2 | örnekN |
|---|---|---|---|
| Kural1 | + | − | − |
| Kural2 | + | + | + |
| kuralM | − | − | − |

> **Çözüm (derste verilmedi):** Çoğunluk oyu (python ile sayıldı): örnek1 için 2 "+", 1 "−" → "+"; örnek2 için 1 "+", 2 "−" → "−"; örnekN için 1 "+", 2 "−" → "−". Hoca derste yalnız kuralı verdi (5 "+" ve 3 "−" ise "+"). Gerçek tabloda "..." satırlarındaki kurallar ve çekimser hücreler de sonucu değiştirebilir.

**Soru 10** (derste sözlü, 00:54:46): Kural1 "metnin içinde «çekmiyor» varsa negatiftir" ise, "çekmiyor" geçmeyen bir metin için bu kural ne der?

> **Çözüm (derste verildi):** Bu tasarımcıya bağlıdır. Bir hücrenin olası değerleri pozitif, negatif ya da çekimserdir (soru işareti). "Varsa negatif, yoksa pozitif" de tasarlanabilir, ama genelde kural uygulanmadığında çekimser kalır.

**Soru 11** (derste sözlü, 01:16:40 ve 01:19:00): Elde eğitim kümesi varken neden yeni eğitim verileri üretiriz? Rastgele kırpmada kırpma karesi küçültülürse ne olur?

> **Çözüm (derste verildi):** Etiket zaten elde olduğu için etiketi değiştirmeyen dönüşümlerle bir etiketli örnekten çok sayıda yeni etiketli örnek "bedavaya" üretilir; iyi ve elde olmayan örnekler daha iyi model sağlayabilir. Kırpma karesi küçüldükçe sınıfa ait olmayan (ör. kedi içermeyen) parça üretme şansı artar; kırpma yeterince büyük olmalıdır.

**Soru 12** (derste sözlü, 01:25:24): GAN'da ayırt edici ağ gerçek ve yapay örnekleri çok iyi ayırabiliyorsa bu ne demektir? Çok başarısızsa ne demektir?

> **Çözüm (derste verildi):** Çok iyi ayırabiliyorsa üretici gerçeğe benzer örnekler üretememiştir. Çok başarısızsa, yani gerçeklerle yapayları ayıramıyorsa, üretici başarılıdır.

**Soru 13** (derste sözlü, 02:11:09): Çok sınıflı ve çok dengesiz bir metin sınıflandırma verisinde aşırı örnekleme işe yarar mı?

> **Çözüm (derste verildi):** Geri çeviri gibi zenginleştirmeler ya da eşit sayıda sınıf örneğiyle eğitime başlayıp süreci sonra tamamlamak denenebilir. Hangi yaklaşımın daha iyi olacağı veri kümesine bağlıdır; deneyip görmek gerekir.

## Dersin Toparlaması

Ders, geçen hafta başlanan "makine öğrenmesinde yeni problemler" listesini tamamladı. Aktif öğrenme, yarı eğiticili öğrenme ve öğrenmenin transferinin kısa tekrarından sonra çok görevli eğitim işlendi: tek bir ortak gövdenin birden çok görevi birlikte öğrenmesi (bölütleme, örnek ayırma ve derinlik; NLP Decathlon'da bütün görevlerin soru-bağlam-cevap biçimine çevrilmesi). Hocanın deneyi ilgisiz görevlerin bile tek ağda öğrenilebildiğini, ama birlikte öğrenmenin her zaman daha iyi ya da daha kötü olmadığını gösterdi. Hiperparametre optimizasyonunda ızgara arama, rastgele arama ve Bayesian optimizasyon karşılaştırıldı; aktif örneklemede model varyansının yüksek olduğu, yani verinin az olduğu bölgelerden yeni örnek istemek anlatıldı. İnsan-makine işbirliğinde insanın yavaş ama doğru, makinenin hızlı ama az doğru olduğu; video etiketleme ve kurallarla zayıf denetim (çelişen kuralların çoğunluk oyuyla birleştirilmesi) örneklendi.

İkinci yarıda az sayıda örnekle eğitim (one-shot, tanımlara dayalı zero-shot ve Google'ın ortak katmanlı zero-shot çevirisi), veri zenginleştirme (görüntü dönüşümleri ve rastgele kırpma, GAN, eş anlamlı ifade ve geri çeviri, pdf tahmini, SMOTE ve SMOTE-IPF), ML algoritmalarını kandırmak (papağanı kitaplık yapan gürültü, hedef belli ve belirsiz ataklar, tek piksel saldırısı), planlı öğrenme (kolaylık ölçütleri, ensemble ile zorluk belirleme, curriculum ve anti-curriculum) ve hayat boyu öğrenme (zamanla değişen dil, açık dünya, endüstrideki yaşam döngüsü) işlendi. Ortak tema, etiketli verinin pahalı ve sınırlı olduğu, dünyanın da zamanla değiştiği gerçek koşullarda öğrenmedir. Hoca bir sonraki derste bağlam temelli dil modellerine geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
