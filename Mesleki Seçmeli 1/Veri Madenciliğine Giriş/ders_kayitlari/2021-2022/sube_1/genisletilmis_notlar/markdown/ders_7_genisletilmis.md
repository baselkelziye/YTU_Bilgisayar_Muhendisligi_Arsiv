# Ders 7 Genişletilmiş Notu: Sınıflandırma ve Karar Ağaçları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın. Kayıtta dersin ikinci saati (00:00:00-01:37:00) birinci saatinden (01:38:00 sonrası) önce yer alır; not, dersin anlatım sırasını izler.

## İçindekiler

- 1. Sınıflandırma ve Tahmin
- 2. Sınıflandırma: İki Adımlı Süreç
- 3. Karar Ağacı
- 4. Karar Ağacı Oluşturma Algoritması
- 5. Bölme Ölçütü ve Bölme Türleri
- 6. En İyi Bölmeyi Bulmak: Safsızlık
- 7. Entropi ve Bilgi Kazancı
- 8. Algoritmanın Özyinelemeli İşleyişi
- 9. Sürekli Değerli Öznitelikler
- 10. Kazanç Oranı
- 11. Gini İndeksi
- 12. Diğer Öznitelik Seçme Ölçüleri
- 13. Aşırı Uyum ve Eksik Uyum
- 14. Karar Ağaçlarının Güçlü ve Zayıf Yanları
- Örnek Sorular
- Dersin Toparlaması

## 1. Sınıflandırma ve Tahmin

Veri ön işleme konusundan sonra veri ambarları bölümü şimdilik atlanarak sınıflandırma bölümüne geçildi. Bu dersin tamamı karar ağaçlarına ayrıldı.

İlk derste veri madenciliği yöntemleri öngörücü (predictive) ve tanımlayıcı (descriptive) diye ikiye ayrılmıştı. Öngörücü yöntemlerin çıktısı ayrık ya da sürekli olabilir. Verinin çıktısı bir sınıfsa ve amaç yeni bir girdinin sınıfını (etiketini) tahmin etmekse bu bir **sınıflandırma** problemidir. Çıktı sürekli bir değerse yapılan iş **tahmindir** (prediction). Tahmin yapan teknikler genellikle regresyona dayanır: lineer regresyon, lojistik regresyon gibi. Sınıflandırma yapan modellere ise **sınıflandırıcı** (classifier) denir.

Sonraki haftalarda farklı sınıflandırıcılar işlenecektir: önce karar ağaçları, sonra olasılık dersindeki Bayes kuralına dayanan Bayes sınıflandırıcıları, karar ağaçlarına çok benzeyen kural tabanlı sınıflandırıcılar ve son olarak destek vektör makineleri.

Slayttaki listede yapay sinir ağlarının hem sınıflandırıcılar hem tahmin yöntemleri arasında yer aldığına dikkat çekildi. Bu bir yanlışlık değildir: yapay sinir ağları sınıflandırmada da, regresyon gibi sürekli bir değeri tahmin etmekte de kullanılabilir. Bazı yapay sinir ağı türleri kümeleme gibi tanımlayıcı işlerde bile kullanılır.

## 2. Sınıflandırma: İki Adımlı Süreç

Sınıflandırma iki adımda yapılır (ekrandan, 01:45:00):

- **Model oluşturma (model construction):** Her örneğin (tuple ya da sample, yani verideki her satır) önceden belirlenmiş bir sınıfa ait olduğu varsayılır; bunu sınıf etiketi özniteliği belirler. Model oluşturmakta kullanılan örneklerin kümesi **eğitim kümesidir** (training set). Model sınıflandırma kuralları, karar ağacı ya da matematiksel formüller biçiminde gösterilebilir.
- **Model kullanımı (model usage):** Model gelecekteki ya da etiketi bilinmeyen nesneleri sınıflandırmakta kullanılır. Önce modelin doğruluğu tahmin edilir: test örneğinin bilinen etiketi modelin verdiği sonuçla karşılaştırılır. Doğruluk oranı, test kümesinde doğru sınıflanan örneklerin yüzdesidir. Test kümesi eğitim kümesinden bağımsız olmalıdır, yoksa aşırı uyum oluşur. Doğruluk kabul edilebilirse model yeni verileri sınıflandırmakta kullanılır.

### 2.1 Bitki örneği

Hoca süreci bir bitki veri tabanıyla anlattı. Her satır bir bitkidir; yaprağın eni, boyu, bitkinin en yüksek boyu, çiçek rengi gibi öznitelikler ölçülmüş ve son sütuna bitkinin cinsi (sınıf) yazılmıştır. Diyelim ki 500 bitki böyle ölçülüp eğitim kümesine yazıldı. Bu kümeden bir model kurulur. Model kurulduktan sonra eğitim kümesiyle işimiz biter; artık yalnız model kullanılır.

Yeni bir bitki geldiğinde yaprağının eni, boyu, çiçek rengi bilinir ama cinsi bilinmez. Bu örnek modele sorulur ve model bir sınıf tahmin eder. Eğitim kümesinde $n$ sütun varsa bunların $n-1$ tanesi öznitelik, $n$'inci sütun sınıf etiketidir. Modele sorulacak yeni örnekte de aynı $n-1$ öznitelik bulunmalıdır. Model kök uzunluğu gibi bir öznitelikle eğitilmediyse, o bilgiyi modele vermenin anlamı yoktur.

### 2.2 Model ne kadar iyi çalışıyor?

Yeni gelen örneğin etiketi bilinmediği için modelin doğru tahmin edip etmediğini o örnekle anlayamayız. Bu yüzden elimizdeki etiketli verinin bir kısmı baştan ayrılır ve **test kümesi** olarak saklanır. Model yalnız geri kalan eğitim kümesiyle kurulur. Ayrılacak oran verinin büyüklüğüne bağlıdır: veri çoksa yaklaşık %10-%20, gerekirse %30'a kadar ayrılabilir. Veri çok azsa test için tek tek örnekler kullanılıp başka ek yöntemler uygulanır.

Hocanın örneğinde 10.000 satırın %10'u, yani 1000 satır test için ayrılır; model kalan 9000 satırla kurulur. Sonra test kümesindeki her örnek modele sorulur. Modelin tahminleri (pozitif, pozitif, negatif, negatif, pozitif, ...) ile gerçek etiketler (pozitif, pozitif, negatif, pozitif, pozitif, ...) yan yana konur ve karşılaştırılır.

**Doğruluk (accuracy)**, doğru tahminlerin tüm tahminlere oranıdır. Doğru tahminler, gerçek değer artı iken artı ve gerçek değer eksi iken eksi denen örneklerdir. Yanlış tahminler ise artı iken eksi ve eksi iken artı denenlerdir. 1000 tahminin 790'ı doğruysa:

$$\text{Doğruluk} = \frac{790}{1000} = 0.79 = \%79$$

Doğruluk genellikle yüzdeyle söylenir ("sistemimin doğruluğu %75'tir" gibi). Doğruluk dışındaki değerlendirme ölçüleri sınıflandırma konusu ilerledikçe işlenecektir.

> **Hocanın vurguladığı:** Test kümesini ayırırken verinin sonundaki kısmı almayın. Veri tabanından çekilen veri çoğunlukla bir şeye göre sıralıdır; örneğin beş yıllık verinin son %10'unu alırsanız yalnız son yılı test etmiş olursunuz. Test örnekleri rastgele seçilmeli ya da veri önce karıştırılmalıdır (shuffle).

Model kötü çalışıyorsa "kötü" neye göre ölçülür? İki sınıflı ve dengeli bir problemde hiç model kurmadan rastgele artı ya da eksi demek bile yaklaşık %50 doğruluk verir. Bu yüzden %60 doğrulukla çalışan bir model pek bir şey ifade etmez; çok daha yüksek doğruluk beklenir. Sınıf dağılımı dengesizse bu taban değer de farklı olur. Doğruluk kabul edilebilir düzeydeyse (problemine göre %85, %95 gibi) model müşteriye verilip kullanılabilir.

### 2.3 Tümevarım ve tümdengelim

Slaytta genel yaklaşım şöyle gösterilir (ekrandan, 02:00:00): eğitim kümesinden (Attrib1, Attrib2, Attrib3 ve Class sütunlu 10 satır) bir öğrenme algoritmasıyla model öğrenilir; bu adıma **induction** (tümevarım, çıkarım) denir. Sonra model, sınıfı "?" olan test kümesine (satır 11-15) uygulanır; bu adıma **deduction** (tümdengelim) denir.

> **Ders sonrası not:** Hoca anlatırken iki adım için de "induction" terimini söyledi. Slayttaki doğru eşleme şöyledir: modeli eğitim kümesinden öğrenmek induction, modeli test kümesine uygulamak deduction'dır (ekrandan, 02:00:00).

## 3. Karar Ağacı

Karar ağacı akış diyagramına benzeyen bir ağaçtır. İkili ağaç olmak zorunda değildir. Slayttaki tanım şöyledir (ekrandan, 02:05:00):

- Karar ağaçları örnekleri kökten bir yaprağa doğru indirerek sınıflandırır; yaprak örneğin sınıfını verir.
- Her iç düğüm örneğin bir özniteliğini test eder.
- Bir düğümden inen her dal o özniteliğin olası değerlerinden birine karşılık gelir.
- Her yaprak bir sınıf atar.

Kitaptaki örnek, gelen bir müşterinin bilgisayar alıp almayacağını tahmin eder. Ağacın kökünde `age?` vardır. `<=30` dalında `student?` sorulur (no ise no, yes ise yes); `31..40` dalı doğrudan `yes` yaprağıdır; `>40` dalında `credit_rating?` sorulur (excellent ise no, fair ise yes). (age = <=30, income = low, student = no, credit_rating = fair) örneği bu ağaçta önce `<=30` dalına, sonra `student = no` dalına iner ve negatif sınıflanır (ekrandan, 02:05:00).

Ağacı oluştururken akla gelen sorular şunlardır: Köke hangi öznitelik konacak? Yüzlerce öznitelik varsa sonraki düğümlere hangileri, hangi sırayla konacak? Ağaç çok yüksek olmamalıdır, çünkü yükseklik arttıkça karar vermek uzun sürer; ama yükseklik doğruluğu artırıyorsa buna razı olunabilir.

Öznitelikler kategorik, ikili ya da sayısal olabilir. Sürekli değerli öznitelikler için farklı bir işlem gerekir; başlangıçta ayrık değerlerle çalışılır. Örnek veride yaş zaten ayrık verilmiştir: `<=30`, `31..40`, `>40`. Gelir (income) low, medium, high değerlerini alır. Örnek ağaçta income hiç kullanılmamıştır; diğer özniteliklerle sınıflar ayrılabilmektedir. Veride `31..40` olan bütün satırlar yes olduğu için o dal doğrudan yes yaprağına bağlanır.

Bir yol üzerinde aynı öznitelik ikinci kez sorulmaz. Örneğin aşağılarda tekrar "age şöyleyse" diye sorulamaz; her öznitelik bir kez sorularak veri bölünür.

Slayttaki "karar ağacı, öznitelik değerleri üzerindeki kısıtların birleşimlerinin (conjunction) ayrımını (disjunction) gösterir" cümlesi de yorumlandı: kökten yaprağa her yol bir dizi koşulun "ve" ile birleşimidir, aynı sınıfa giden farklı yollar ise "veya" ile bağlanır. Hoca bu cümlenin gereğinden karışık yazıldığını söyledi.

## 4. Karar Ağacı Oluşturma Algoritması

Slayttaki genel algoritma şöyledir (ekrandan, 00:25:00):

```text
Generate_Decision_Tree(D, attribute_list)
  create a node N;
  if tuples in D are all of the same class C then
      return N as a leaf node labeled with the class C;
  if attribute_list is empty then
      return N as a leaf node labeled with the majority class in D;   // majority voting
  apply attribute_selection_method(D, attribute_list)
      to find the best splitting_criterion;
  label node N with splitting_criterion;
  if splitting_attribute is discrete-valued and multiway splits allowed then
      attribute_list <- attribute_list - splitting_attribute;          // remove splitting_attribute
  for each outcome j of splitting_criterion
      // partition the tuples and grow subtrees for each partition
      let D_j be the set of data tuples in D satisfying outcome j;     // a partition
      if D_j is empty then
          attach a leaf labeled with the majority class in D to node N;
      else attach the node returned by Generate_decision_tree(D_j, attribute_list) to node N;
  return N;
```

Adım adım anlamı:

- `D` verinin tamamıdır, yani bütün satırlar. `attribute_list` ağaca konabilecek özniteliklerin listesidir.
- **Hepsi aynı sınıfta:** D'deki bütün satırların etiketi aynıysa (tek sınıf varsa) düğüm o sınıfla etiketlenmiş bir yaprak olur.
- **Öznitelik listesi boş:** Düğüme konacak öznitelik kalmamışsa ama düğüm hâlâ tam ayrılmamışsa yine yaprak oluşturulur. Yaprağın etiketi kalan verinin çoğunluk sınıfıdır (majority voting). Örneğin düğümde 4 artı, 2 eksi kaldıysa yaprak artı olur.
- **En iyi bölme ölçütü:** Listedeki öznitelikler tek tek denenir ve veriyi en iyi bölen bulunur. "En iyi"nin sayısal olarak nasıl ölçüldüğü bölüm 6-11'de anlatılır. Bulunan öznitelik düğüme konur.
- **Özniteliği listeden çıkarma:** Öznitelik ayrık değerliyse ve çok yollu bölmeye izin veriliyorsa listeden çıkarılır.
- **Bölümleme:** Seçilen özniteliğin her değeri için veri bir bölüme ayrılır. Yaş örneğinde `<=30` olanlar $D_1$, `31..40` olanlar $D_2$, `>40` olanlar $D_3$ olur. Bir bölüm boşsa (örneğin hiç `31..40` örneği yoksa) çoğunluk sınıfıyla bir yaprak eklenir. Boş değilse algoritma o bölüm ve kalan öznitelik listesiyle kendini yeniden çağırır ve her bölüm için ayrı bir alt ağaç kurulur.

Algoritmanın durma koşulları iki tanedir: bakılacak örnek kalmaması ya da bir düğüme gelen bütün örneklerin aynı sınıfta olması. İkinci durumda düğüm doğrudan yaprak yapılır ve o dalda özyineleme devam etmez.

## 5. Bölme Ölçütü ve Bölme Türleri

Slayttaki tasarım soruları (ekrandan, 02:20:00):

- **Eğitim örnekleri nasıl bölünmeli?**
  - Test koşulunu belirleme yöntemi (splitting criterion): öznitelik tipine bağlıdır.
  - Test koşulunun iyiliğini ölçme (en iyi özniteliği seçme): bilgi kazancı, kazanç oranı, Gini indeksi, yanlış sınıflama hatası, istatistiksel test gibi ölçüler.
- **Bölme ne zaman durmalı?**
  - Bütün örnekler aynı sınıftaysa bölme durur.
  - İstatistiksel bir testin sonucuna göre erken durdurma yapılabilir.

Ağaç büyüdükçe çok başarılı ama çok büyük modeller elde edilebilir; bu her zaman iyi değildir. Ağacın daha küçük ve hızlı olması için biraz hataya göz yummak istenebilir.

Öznitelikler ikili, nominal, sıralı (ordinal) ya da sürekli olabilir. Bölmenin kaç yollu olacağı da öznitelikteki değer sayısına bağlıdır. Öznitelik iki değer alıyorsa (öğrenci mi: evet/hayır) yapılan bölmeye **ikili bölme** (binary ya da two-way split) denir. İkiden çok değer varsa **çok yollu bölme** (multi-way split) denir. Bir algoritma çok yollu bölmeye izin verebilir ya da yalnız ikili bölme yapabilir. Tek bir karar ağacı oluşturma yöntemi yoktur: CART (classification and regression trees), ID3, C4.5 gibi algoritmalar öznitelik tipine göre ve Gini indeksi mi entropi mi kullandıklarına göre farklılaşır.

> **Ders sonrası not:** Hoca tahtaya algoritma adlarını CART, ID3 ve "ID4.5" diye yazdı (ekrandan, 00:35:00). Algoritmanın doğru adı C4.5'tir; slaytta da C4.5 geçer (ekrandan, 00:45:00).

Bir öğrenci, çok yollu bölmenin ağacı daha kısa tuttuğunu sordu. **Cevap:** Böyle bir garanti yoktur. Bir dal hemen yes yaprağına bağlandığında ağaç kısa görünür, ama başka dallar yeniden dallanabilir. Çok yollu bölme her zaman köke yakın yapraklar vermez.

## 6. En İyi Bölmeyi Bulmak: Safsızlık

Örnek veride köke dört öznitelikten biri konabilir: age, income, student, credit_rating. Sınıf sütununda 9 yes ve 5 no vardır. Her özniteliğin bu artı ve eksileri nasıl dağıttığına bakılır:

- age: [2+,3-], [4+,0-], [3+,2-]
- income (low, medium, high): [3+,1-], [4+,2-], [2+,2-]
- student (no, yes): [3+,4-], [6+,1-]
- credit_rating (fair, excellent): [6+,2-], [3+,3-]

Hangisi daha iyidir? Sezgisel olarak [4+,0-] gibi bir dağılım iyidir, çünkü o dal doğrudan yaprağa bağlanır. Sınıfların eşit dağıldığı bir dal ise pek bir şey sağlamaz.

Derste bir soru da tartışıldı: bir öznitelik verinin %99'unu bir dala, %1'ini öteki dala atıyorsa bu iyi bir bölme midir? Burada önemli olan dallara düşen örnek sayısı değil, her dalın içindeki sınıf dağılımıdır. Ölçülen şey dalların ne kadar homojen olduğudur.

Algoritma açgözlü (greedy) yaklaşımla çalışır. Açgözlü algoritma adım adım ilerler ve her adımda bir ölçüye göre o anki en iyi seçeneği alır; global en iyiye bakmaz. Bu yüzden bulunan ağaç gerçekten en iyi ağaç olmayabilir, ama hızlı çalışır ve iyi bir ağaç verir.

Slayttaki ilke şöyledir (ekrandan, 02:25:00): homojen (daha saf) sınıf dağılımına sahip düğümler tercih edilir. [5+,5-] homojen değildir ve safsızlığı (impurity) yüksektir; [9+,1-] homojendir ve safsızlığı düşüktür. Saflık (purity) safsızlığın tersidir. Bu yüzden düğüm safsızlığını ölçen bir ölçüye ihtiyaç vardır: entropi, Gini indeksi, yanlış sınıflama hatası gibi.

En iyi bölmeyi bulma adımları şunlardır (ekrandan, 00:05:00):

1. Bölmeden önce safsızlık ölçüsünü (P) hesapla. Kökte henüz hiçbir özniteliğe bakmadan, yalnız sınıf dağılımı [9+,5-] üzerinden hesaplanır.
2. Bölmeden sonraki safsızlığı (M) hesapla: her çocuk düğümün safsızlığını bul; M, çocukların ağırlıklı safsızlığıdır.
3. En yüksek kazancı veren test koşulunu seç: $\text{Gain} = P - M$.

Aynı düğümde bütün öznitelikler için P sabittir. Bu yüzden kazancı en büyük yapmak, bölmeden sonraki M'yi en küçük yapmakla aynı şeydir; kök bulunurken çıkarma yapmak bile gerekmez.

Safsızlığı hesaplamanın üç yolu işlendi: bilgi kazancı (information gain), ona çok benzeyen kazanç oranı (gain ratio) ve Gini indeksi.

## 7. Entropi ve Bilgi Kazancı

### 7.1 Entropi

Entropi bilgi kuramından gelir. Bu kuram sinyaller ve veri için geliştirilmiştir ve verinin dağılımına bakarak veriyi daha az bitle nasıl gösterebileceğimizi inceler. Kuramın ayrıntısına girilmedi.

Pozitif ve negatif örnekler içeren bir S kümesinin entropisi şöyledir (ekrandan, 00:10:00):

$$\text{Entropy}(S) = -p_+\log_2 p_+ - p_-\log_2 p_-$$

Burada S eğitim örneklerinden oluşan bir kümedir, $p_+$ pozitif örneklerin oranı, $p_-$ negatif örneklerin oranıdır. Pozitifleri yes, negatifleri no gibi düşünebiliriz; A ve B diye iki sınıf varsa A'dakilerin ve B'dekilerin oranları gibi.

Formülün başındaki eksi işaretlerinin nedeni şudur: oranlar 0 ile 1 arasında bir kesirdir ve kesrin 2 tabanında logaritması negatiftir. Eksi işareti bu negatif değerleri pozitife çevirir.

Derste verilen örnekler:

- 12 yes ve 5 no (toplam 17): $-\frac{12}{17}\log_2\frac{12}{17} - \frac{5}{17}\log_2\frac{5}{17} \approx 0.874$. Hoca sonucu "0.8 küsur" diye söyledi; değer python ile doğrulandı. <!-- BELİRSİZ: Bu örneğin slaytı kare aralığına denk gelmedi; sayılar altyazıdan alındı. -->
- 8 yes ve 8 no: oranlar eşit olduğu için entropi 1'dir.
- 8 yes ve 0 no: entropi 0'dır. Homojenliği en yüksek olan budur.

İki sınıflı durumda entropi en az 0, en çok 1 olur.

Sınıf yalnız yes/no olmak zorunda değildir; A, B, C, D gibi birden çok sınıf olabilir. O zaman formül aynı biçimde her sınıf için bir terim eklenerek devam eder; oranlar toplam örnek sayısına bölünerek bulunur. Logaritmanın tabanı sınıf sayısına göre değişmez, 2 kalır; çünkü ölçülen şey bit cinsinden kodlamadır.

> **Ders sonrası not:** Hoca entropinin 0 ile 1 arasında olduğunu söyledi. Bu iki sınıf için doğrudur. $m$ sınıflı durumda taban 2 kaldığı için en büyük değer $\log_2 m$ olur (örneğin dört sınıf eşit dağılırsa entropi 2'dir).

### 7.2 Beklenen bilgi ve bilgi kazancı

Slayttaki genel tanımlar şunlardır (ekrandan, 00:15:00):

- En yüksek bilgi kazancı olan öznitelik seçilir.
- $p_i$, D'deki rastgele bir örneğin $C_i$ sınıfına ait olma olasılığıdır ve $|C_{i,D}|/|D|$ ile tahmin edilir.
- D'deki bir örneği sınıflandırmak için gereken beklenen bilgi (entropi):

$$\text{Info}(D) = -\sum_{i=1}^{m} p_i \log_2(p_i)$$

- A özniteliğiyle D, $v$ bölüme ayrıldıktan sonra sınıflandırma için gereken bilgi:

$$\text{Info}_A(D) = \sum_{j=1}^{v} \frac{|D_j|}{|D|} \times \text{Info}(D_j)$$

- A üzerinde dallanmakla kazanılan bilgi:

$$\text{Gain}(A) = \text{Info}(D) - \text{Info}_A(D)$$

$\text{Info}(D)$, hiçbir öznitelik kullanmadan önce düğümdeki verinin taşıdığı bilgidir. Düğüm bir öznitelikle iki, üç ya da daha çok çocuğa bölündüğünde her çocuğun entropisi hesaplanır ve çocuktaki örnek sayısının toplam örnek sayısına oranıyla ağırlıklandırılıp toplanır. Toplam entropiden bu ağırlıklı toplam çıkarılınca bilgi kazancı bulunur. Amaç kazancın en büyük olmasıdır: öznitelikler tek tek denenir ve en büyük kazancı veren öznitelik karar ağacında o düğüm için veriyi en iyi ayıran öznitelik kabul edilir.

### 7.3 Örnek veri kümesi

Slayttaki 14 satırlık veri şöyledir (ekrandan, 00:20:00):

| age | income | student | credit_rating | buys_computer |
|---|---|---|---|---|
| <=30 | high | no | fair | no |
| <=30 | high | no | excellent | no |
| 31..40 | high | no | fair | yes |
| >40 | medium | no | fair | yes |
| >40 | low | yes | fair | yes |
| >40 | low | yes | excellent | no |
| 31..40 | low | yes | excellent | yes |
| <=30 | medium | no | fair | no |
| <=30 | low | yes | fair | yes |
| >40 | medium | yes | fair | yes |
| <=30 | medium | yes | excellent | yes |
| 31..40 | medium | no | excellent | yes |
| 31..40 | high | yes | fair | yes |
| >40 | medium | no | excellent | no |

Age burada sürekli değil, üç ayrık (sıralı) değer olarak verilmiştir.

### 7.4 Köke ne konacak?

**Bölmeden önce:** 9 pozitif, 5 negatif örnek vardır, D: [9+,5-] (ekrandan, 00:20:00).

$$\text{Info}(D) = -\frac{9}{14}\log_2\frac{9}{14} - \frac{5}{14}\log_2\frac{5}{14} = 0.940$$

**age ile bölme:** `<=30` olan 5 satırın 2'si yes, 3'ü no; `31..40` olan 4 satırın 4'ü yes, 0'ı no; `>40` olan 5 satırın 3'ü yes, 2'si no'dur.

$\text{Info}([2+,3-]) = -\frac{2}{5}\log_2\frac{2}{5} - \frac{3}{5}\log_2\frac{3}{5} = 0.971$ (ara adım eklendi). Ağırlık, 14 satırın kaçının o dala düştüğüdür:

$$\text{Info}_{age}(D) = \frac{5}{14}\,\text{Info}([2+,3-]) + \frac{4}{14}\,\text{Info}([4+,0-]) + \frac{5}{14}\,\text{Info}([3+,2-])$$

$$= \frac{5}{14}(0.971) + \frac{4}{14}(0.0) + \frac{5}{14}(0.971) = 0.694$$

$$\text{Gain}(age) = 0.940 - 0.694 = 0.246$$

Hoca burada "bu çok güzel, age'i köke koyalım" diyemeyeceğimizi, önce diğer özniteliklere de bakmak gerektiğini vurguladı.

**income ile bölme:** Başlangıç bilgisi yine 0.940'tır; bu değer düğümdeki sınıf dağılımından geldiği için hep sabittir. Income üç değerlidir: low [3+,1-], medium [4+,2-], high [2+,2-]. Ağırlıklar 4/14, 6/14, 4/14'tür. $\text{Info}_{income}(D) = 0.911$, kazanç $0.940 - 0.911 = 0.029$ çıkar. Bu age'inkinden çok daha düşüktür.

**student ile bölme:** no [3+,4-], yes [6+,1-]:

$$\text{Info}_{student}(D) = \frac{7}{14}\,\text{Info}([3+,4-]) + \frac{7}{14}\,\text{Info}([6+,1-])$$

Kazanç 0.151'dir: income'dan iyi, ama age'den küçüktür.

**credit_rating ile bölme:** fair [6+,2-] (8 satır), excellent [3+,3-] (6 satır):

$$\text{Info}_{credit}(D) = \frac{8}{14}\,\text{Info}([6+,2-]) + \frac{6}{14}\,\text{Info}([3+,3-])$$

Kazanç 0.048'dir; dört öznitelik içinde en kötüsüdür.

Bütün değerler python ile doğrulandı ($\text{Info}_{age}=0.6935$, $\text{Info}_{income}=0.9111$, $\text{Info}_{student}=0.7885$, $\text{Info}_{credit}=0.8922$).

**Sonuç:** En büyük kazanç age'dedir, kök age olur. Algoritmaya göre age öznitelik listesinden çıkarılır. Artık her dal için ayrı bir $\text{Info}$ hesaplanır: `<=30` dalı için [2+,3-], `31..40` için [4+,0-], `>40` için [3+,2-]. [4+,0-] dalı algoritmanın ilk `if`'ine girer ve doğrudan yes yaprağı olur.

**Soru:** Age'den böldükten sonra hesaplar nasıl devam eder? **Cevap:** Örneğin `<=30` dalına 5 kişi düşer. Bundan sonra o dalda 14 kişiyle işimiz kalmaz; hesaplar yalnız bu 5 kişi üzerinden yapılır. Her dal kendi örnekleriyle ilerler; farklı dallardaki örnekler hesaplarda bir daha bir araya gelmez.

### 7.5 Alt düğümler

Kök age olduktan sonra her dal için en iyi öznitelik aranır (ekrandan, 02:15:00). `<=30` dalındaki 5 satır şöyledir:

| age | income | student | credit_rating | buys_computer |
|---|---|---|---|---|
| <=30 | high | no | fair | no |
| <=30 | high | no | excellent | no |
| <=30 | medium | no | fair | no |
| <=30 | low | yes | fair | yes |
| <=30 | medium | yes | excellent | yes |

Bu dalda student = no olanların hepsi no, student = yes olanların hepsi yes'tir; student bu dalı tam ayırır.

`>40` dalındaki 5 satır şöyledir:

| age | income | student | credit_rating | buys_computer |
|---|---|---|---|---|
| >40 | medium | no | fair | yes |
| >40 | low | yes | fair | yes |
| >40 | low | yes | excellent | no |
| >40 | medium | yes | fair | yes |
| >40 | medium | no | excellent | no |

Student'tan bölünse bir dalda bir yes ile bir no karışır; income'dan bölünse medium dalında yine bir no ayrışmaz. Credit_rating'e göre bölünce fair olanların hepsi yes, excellent olanların hepsi no olur; bu dal credit_rating ile tam ayrılır. Böylece bölüm 3'teki ağaç elde edilir.

Gerçek hayatta böyle olmaz: kurulan model eğitim kümesinin kendisi üzerinde bile genellikle %100 doğru çalışmaz. Burada sayımı gözle yaptık; algoritma bunu bilgi kazancı gibi sayısal bir ölçüyle yapar.

### 7.6 Kazanç negatif olabilir mi?

**Soru:** Bilgi kazancı negatif çıkabilir mi? **Cevap:** Hayır. İki terim de entropiden gelir. Bölmeden sonraki terim, çocukların entropilerinin örnek sayılarıyla ağırlıklandırılmış ortalamasıdır ve ebeveyndeki dağılım bu çocuk dağılımlarından oluşur. Örneğin bütün çocuklar 2'ye 2 gibi eşit dağılsaydı ebeveyn de 6'ya 6 gibi eşit dağılmış olurdu. Bu oranlama sayesinde bölme sonrası değer ebeveynin değerini aşmaz; kazanç negatif olmaz.

> **Hocanın vurgusu:** Entropi ve bilgi kazancıyla en iyi özniteliği seçmek en kolay yöntemdir ve sınavda kesin sorulur. Başka hiçbir şeye çalışmayan bile buna çalışsın.

## 8. Algoritmanın Özyinelemeli İşleyişi

Algoritma örnek veri üzerinden yeniden izlendi (ekrandan, 00:30:00). Önce bir düğüm oluşturulur. `31..40` dalındaki [4+,0-] bölümü ilk `if`'e girer ve yaprak olur. İkinci `if`'e (öznitelik listesi boş) nadiren girilir: bütün öznitelikler yol üzerinde kullanılmış ama düğüm hâlâ tam ayrılmamışsa çoğunluk oylaması yapılır.

En iyi öznitelik bulunup düğüme konduktan sonra öznitelik listeden çıkarılır ve for döngüsü başlar. Döngü önce $j=1$ için $D_1$ ile ve güncellenmiş öznitelik listesiyle fonksiyonu çağırır. Bu çağrı da kendi içinde en iyi özniteliği bulur, onu listeden çıkarır ve kendi çocukları için çağrı yapar. $D_2$ ancak $D_1$'den başlayan bütün alt ağaç bittikten sonra işlenir. Yani bu kod derinlik öncelikli (depth-first) ilerler: önce bir dalı en alta kadar indirir, sonra öteki dala geçer.

Derste bir öğrenci, kullanılan özniteliğin farklı bir dalda yeniden kullanılmasının daha iyi bir ağaç verebileceğini öne sürdü. Hoca, bu kodda bir yol üzerinde kullanılan özniteliğin o yolun altında yeniden kullanılmadığını; ama başka uygulamalarda, örneğin ileride işlenecek random forest gibi yöntemlerde aynı özniteliğin farklı dallarda tekrar tekrar gelebildiğini söyledi. Hocanın görüşüne göre bu derinlik öncelikli uygulama iyi bir uygulama değildir: eşik yoktur (örneğin 9'a 1 ise o bir örneği yok sayıp %90 doğrulukla yetinmek gibi), öznitelikleri kullana kullana en alta kadar iner. Genişlik öncelikli (breadth-first) ilerleyip özniteliklerin yeniden kullanılmasına izin vermek ve sonradan ağacı budamak (pruning) daha mantıklıdır; bazı algoritmalar böyle çalışır.

> **Ek bilgi (derste anlatılmadı):** Her özyinelemeli çağrı öznitelik listesinin kendi kopyasını alıyorsa, dalların derinlik öncelikli ya da genişlik öncelikli işlenmesi ortaya çıkan ağacı değiştirmez; yalnız işlem sırası değişir. Liste bütün çağrılar arasında paylaşılan tek bir nesne olarak değiştirilirse, bir dalda çıkarılan öznitelik kardeş dallarda da kaybolur ve ağaç farklılaşır. Bu yüzden uygulamada listenin değerle mi başvuruyla mı aktarıldığı önemlidir.

## 9. Sürekli Değerli Öznitelikler

Öznitelik sürekli ise önce değerler küçükten büyüğe sıralanır ve tekil değerler bulunur (veride aynı değer birçok kez geçebilir). Sonra sınıfın değiştiği yerlere bakılır.

Slayttaki örnek (ekrandan, 00:40:00):

| Temperature | 40 | 48 | 60 | 72 | 80 | 90 |
|---|---|---|---|---|---|---|
| Class | No | No | Yes | Yes | Yes | No |

Her değeri ayrı bir ayrık değer yapmak işe yaramaz; gerçek veride çok fazla değer ve aykırı değer olur. Bunun yerine yalnız sınıfın değiştiği geçiş noktaları alınır. No'dan Yes'e geçiş 48 ile 60 arasında, Yes'ten No'ya geçiş 80 ile 90 arasındadır. İki aday eşik vardır:

$$\frac{48+60}{2} = 54, \qquad \frac{80+90}{2} = 85$$

Bu eşiklerden $\text{Temperature}_{>54}$ ve $\text{Temperature}_{>85}$ adlı yeni ikili (boolean) öznitelikler tanımlanır, bilgi kazançları hesaplanır ve bunlar diğer ayrık değerli öznitelikler gibi kullanılır. Böylece sürekli değer, bütün değerler yerine yalnız geçiş noktaları kullanılarak ayrık hale getirilmiş olur. Bu örneğin kazanç hesabı derste yapılmadı; çözümü Örnek Sorular bölümündedir. Sürekli öznitelikte Gini indeksiyle bölme örneği bölüm 11.4'tedir.

## 10. Kazanç Oranı

Bilgi kazancında çocukların entropisi, düğüme düşen örnek sayısıyla ağırlıklandırılır. Bir dala çok sayıda örnek düşüyorsa o dal sonucu baskılayabilir; çok sayıda farklı değer olduğunda da hesap iyi çalışmaz. Slayttaki ifade şöyledir (ekrandan, 00:45:00):

- Bilgi kazancı ölçüsü çok sayıda değeri olan özniteliklere doğru yanlıdır.
- Bazı karar ağacı algoritmaları (C4.5 gibi) bu sorunu aşmak için **kazanç oranını** (gain ratio) kullanır; bu, bilgi kazancının normalize edilmesidir.

$$\text{SplitInfo}_A(D) = -\sum_{j=1}^{v} \frac{|D_j|}{|D|} \times \log_2\left(\frac{|D_j|}{|D|}\right)$$

$$\text{GainRatio}(A) = \frac{\text{Gain}(A)}{\text{SplitInfo}_A(D)}$$

SplitInfo, entropi formülüne benzer ama sınıflara bakmaz: verinin dallara nasıl dağıldığını, yani kaça kaç bölündüğünü ölçer. Bilgi kazancında her dal kendi içindeki sınıf oranlarıyla (örneğin [2+,3-] için 2/5 ve 3/5) değerlendiriliyordu. SplitInfo'da ise dalların toplam içindeki payları (her dalın örnek sayısı / ebeveyndeki örnek sayısı) kullanılır ve kazanç bununla bölünür.

**Income örneği (ekrandan, 00:45:00):** Income low, medium, high dallarına 4, 6 ve 4 örnek düşürür.

$$\text{SplitInfo}_{income}(D) = -\frac{4}{14}\log_2\frac{4}{14} - \frac{6}{14}\log_2\frac{6}{14} - \frac{4}{14}\log_2\frac{4}{14} = 1.557$$

$$\text{GainRatio}(income) = \frac{0.029}{1.557} = 0.019$$

Python ile SplitInfo 1.5567 bulundu; yuvarlanmamış kazanç (0.0292) kullanılınca oran 0.0188, yani yaklaşık 0.019'dur. Kazanç oranı en büyük olan öznitelik bölme özniteliği olarak seçilir.

## 11. Gini İndeksi

### 11.1 Tanım

Gini indeksi de çok kullanılan bir safsızlık ölçüsüdür. Bir düğümdeki sınıf oranlarının kareleri toplanıp 1'den çıkarılır:

$$\text{Gini} = 1 - \sum_{j} p_j^2$$

Örneğin düğümde 2 artı, 3 eksi varsa $1 - (2/5)^2 - (3/5)^2$ hesaplanır. Hocanın verdiği örnekler (iki sınıf, 6 örnek):

- [0,6]: $1 - (0/6)^2 - (6/6)^2 = 0$. Bütün örnekler tek sınıfta toplanmışsa Gini 0'dır.
- [1,5]: $1 - (1/6)^2 - (5/6)^2 = 0.278$ (ara adım eklendi).
- [3,3]: $1 - (3/6)^2 - (3/6)^2 = 0.5$. Eşit dağılımda değer en yüksektir.

Yani Gini de dağılımın nasıl olduğuna bakar: homojen dağılım sıfıra yakın, karışık dağılım büyük değer verir.

### 11.2 Bölme sonrası Gini

Bir ebeveyn düğüm $k$ çocuğa bölündüğünde (ekrandan, 00:50:00):

$$\text{GINI}_{split} = \sum_{i=1}^{k} \frac{n_i}{n}\,\text{GINI}(i)$$

Burada $n_i$ $i$'inci çocuktaki örnek sayısı, $n$ ebeveyndeki örnek sayısı, $\text{GINI}(i)$ $i$'inci çocuğun Gini değeridir. Bilgi kazancında olduğu gibi önce ebeveynin Gini'si bölmeden önceki sınıf dağılımından hesaplanır, sonra kazanç bulunur:

$$\text{GAIN} = \text{GINI}(parent) - \text{GINI}_{split}$$

Çocukların ağırlıklı ortalama Gini'sini en küçük yapan öznitelik seçilir. Gini indeksi CART, SLIQ, SPRINT gibi karar ağacı algoritmalarında kullanılır. Avantajı daha hızlı çalışmasıdır: logaritma gibi işlemler içermez, yalnız oranlar ve basit toplama, çarpma vardır.

> **Ders sonrası not:** Hoca Gini kullanan algoritmaları "TIIT gibi ya da Sprint gibi" diye söyledi (altyazıdaki biçimiyle); slaytta CART, SLIQ ve SPRINT yazar (ekrandan, 00:50:00).

### 11.3 İkili öznitelik örneği

Ebeveynde C0 sınıfından 6, C1 sınıfından 6 örnek vardır; $\text{Gini} = 0.500$. İki ikili öznitelik, A ve B, deneniyor (ekrandan, 00:55:00).

**A ile bölme:** Node N1'e C0'dan 4, C1'den 3 örnek; Node N2'ye C0'dan 2, C1'den 3 örnek düşer.

$$\text{Gini}(N1) = 1 - (4/7)^2 - (3/7)^2 = 0.49$$

$$\text{Gini}(N2) = 1 - (2/5)^2 - (3/5)^2 = 0.48$$

$$\text{Gini}_{splitA} = \frac{7}{12}\,\text{Gini}(N1) + \frac{5}{12}\,\text{Gini}(N2) = 0.486$$

**B ile bölme:** Node N1'e C0'dan 1, C1'den 4 örnek; Node N2'ye C0'dan 5, C1'den 2 örnek düşer.

$$\text{Gini}(N1) = 1 - (1/5)^2 - (4/5)^2 = 0.32$$

$$\text{Gini}(N2) = 1 - (5/7)^2 - (2/7)^2 = 0.408$$

$$\text{Gini}_{splitB} = \frac{5}{12}\,\text{Gini}(N1) + \frac{7}{12}\,\text{Gini}(N2) = 0.371$$

Değerler python ile doğrulandı (0.4857 ve 0.3714). B'nin ağırlıklı Gini'si daha küçüktür, yani çocukları daha homojendir; B seçilir. Ebeveynden çıkarınca kazanç da B için daha büyük olur.

Çok yollu bölmede de hesap aynıdır: iki yerine üç (ya da daha çok) çocuğun Gini'si hesaplanır ve ağırlıklı toplanır. Ağırlıklar kesir olduğu ve toplamları 1 ettiği için ek bir sorun çıkmaz.

### 11.4 Sürekli öznitelik örneği

Sürekli öznitelikte değerler sıralanır ve Gini indeksi en küçük olan bölme konumu seçilir (ekrandan, 01:10:00). Slayttaki veride sınıf sütunu Cheat (hile yaptı mı), öznitelik Annual Income'dır:

| Annual Income | 60 | 70 | 75 | 85 | 90 | 95 | 100 | 120 | 125 | 220 |
|---|---|---|---|---|---|---|---|---|---|---|
| Cheat | No | No | No | Yes | Yes | Yes | No | No | No | No |

Bölme konumları komşu değerlerin arasına konur. Her konum için `<=` ve `>` tarafındaki Yes/No sayıları ve ağırlıklı Gini şöyledir (ekrandan, 01:10:00):

| Konum | 55 | 65 | 72 | 80 | 87 | 92 | 97 | 110 | 122 | 172 | 230 |
|---|---|---|---|---|---|---|---|---|---|---|---|
| Yes (<=, >) | 0, 3 | 0, 3 | 0, 3 | 0, 3 | 1, 2 | 2, 1 | 3, 0 | 3, 0 | 3, 0 | 3, 0 | 3, 0 |
| No (<=, >) | 0, 7 | 1, 6 | 2, 5 | 3, 4 | 3, 4 | 3, 4 | 3, 4 | 4, 3 | 5, 2 | 6, 1 | 7, 0 |
| Gini | 0.420 | 0.400 | 0.375 | 0.343 | 0.417 | 0.400 | 0.300 | 0.343 | 0.375 | 0.400 | 0.420 |

Hoca önce sınıfın değiştiği ilk yere, 75 ile 85 arasındaki 80 konumuna baktı. 80'den küçük ya da eşit olup yes olan yoktur (0), no olan 3 tanedir; 80'den büyük olup yes olan 3, no olan 4 tanedir. Bu ikili bölmenin ağırlıklı Gini'si 0.343'tür. İkinci geçiş konumu olan 97'de Gini 0.300 çıkar. Daha düşük olan seçilir; bölme "Annual Income <= 97" ve "Annual Income > 97" diye yapılır. Tablodaki bütün değerler python ile yeniden hesaplanıp doğrulandı.

Çoğu algoritma sürekli özniteliği ikiye böler. Bazıları üç ya da dört parçaya da böler: örneğin Gini belli bir eşiğin altına inene kadar bölmek ya da en iyi dört konumu alıp dörde bölmek gibi; bu tür ayarlar algoritmalara parametre olarak verilebilir. Aynı Gini değerini veren birden çok konum varsa bunlardan biri seçilir.

## 12. Diğer Öznitelik Seçme Ölçüleri

Slayttaki diğer ölçüler şunlardır (ekrandan, 01:15:00):

- **CHAID:** Popüler bir karar ağacı algoritmasıdır; ölçüsü $\chi^2$ bağımsızlık testine dayanır.
- **G-istatistiği:** $\chi^2$ dağılımına yakın bir yaklaşıklığı vardır.
- **Çok değişkenli bölmeler** (birden çok değişkenin birleşimine göre bölme): CART, özniteliklerin lineer birleşimine dayalı bölmeler bulabilir.
- Hangi ölçü en iyisidir? Çoğu iyi sonuç verir; hiçbiri ötekilerden belirgin biçimde üstün değildir.

Hoca ki-kare yaklaşımını önceki derslerde görülen ki-kare hesabıyla ilişkilendirdi ve bu yöntemlerin pek kullanılmadığını, en çok entropi ve Gini indeksine dayalı yöntemlerin kullanıldığını söyledi.

### 12.1 Üç ölçünün karşılaştırması

- **Bilgi kazancı:** Entropiyle hesaplanır. Çocukların entropisi, düğüme düşen örnek sayısıyla ağırlıklandırılır. Örneğin 10.000 satırın 9000'i bir sınıftaysa o sınıf diğerini baskılayabilir ve sonuç yanıltıcı olur.
- **Kazanç oranı:** Kazancı, dalların ebeveyndeki toplamın kaçta kaçını aldığına (örneğin [3+,4-] dalındaki 7 örneğin 14'e oranına) göre normalize eder.
- **Gini indeksi:** Entropi içermez, tamamen oranlarla gider. Dağılım tek sınıfa yöneliyorsa sıfıra yakın, 3'e 3 gibi eşitse daha büyük değer verir.

Bir ağacı Gini ile ya da entropiyle kurmak farklı sonuçlar verebilir. Hatta öznitelik listesinin sırası karıştırılınca (shuffle) bile farklı ağaç çıkabilir, çünkü algoritmalar açgözlü çalışır. Hangisinin global en iyi olduğu bilinmez. Hazır kütüphaneler bu denemeleri çoğunlukla kendi içinde yapar.

Tek ağaç yerine çok sayıda küçük ağaç kurup sonuçlarını birleştirmek (en çok oyu alan sınıfı ya da ortalamayı almak) topluluk öğrenmesi (ensemble learning) konusunda, orman (forest) yöntemleriyle işlenecektir.

## 13. Aşırı Uyum ve Eksik Uyum

### 13.1 Aşırı uyum (overfitting)

Bu konu yalnız karar ağaçları için değil, neredeyse bütün yöntemler için geçerlidir. Kurulan model eğitim verisi üzerinde bile genellikle %100 çalışmaz. Modelin eğitim verisindeki hatasına **eğitim hatası** (training error), test kümesindeki hatasına **test hatası** (test error) denir. İyi bir modelde bu iki hatanın birbirine yakın olması beklenir.

Model eğitim verisinde çok iyi çalışıyor ama test verisinde iyi çalışmıyorsa (örneğin eğitimde %95, testte %70 doğruluk) model eğitim kümesine fazla bağlı kalmış, yani eğitim verisine **aşırı uyum** sağlamıştır. Örneğin ağaç, testte hiç karşılaşılmayacak çok nadir durumlar için gereksiz dallar açmıştır. Bu dallar eğitim hatasını düşürür ama genel durum için bir şey ifade etmez. Aşırı uyum yapay sinir ağlarında da çok görülür.

> **Hocanın vurgusu:** Aşırı uyum olup olmadığını anlamak için yalnız test hatasına bakılmaz, eğitim hatasına da bakılır. Eğitim hatasının %1-3 kadar düşük olması normaldir; aradaki fark açıldıkça aşırı uyum var demektir.

Slayttaki tanımlar ve grafik şöyledir (ekrandan, 01:20:00):

- Aşırı uyum, modelin eğitim verisine çok iyi uyduğu ama görülmemiş veriye kötü genelleştiği durumdur.
- Karmaşık modellerin aşırı uyum yapma olasılığı basit modellerinkinden yüksektir.
- Eksik uyum (underfitting): model çok basit olduğunda hem eğitim hem test hatası büyüktür.

Grafikte yatay eksen düğüm sayısı (0-300), dikey eksen hata yüzdesidir (%5-45). Düğüm sayısı arttıkça eğitim hatası (düz çizgi) sürekli azalır ve yaklaşık %9'a kadar iner. Test hatası (kesikli çizgi) başta azalır, yaklaşık 100-150 düğümde %32 dolaylarında en düşük düzeye gelir, sonra dalgalanır ve yaklaşık 180 düğümden sonra yeniden artar; dikey kesikli çizgi "Overfitting" bölgesinin başlangıcını gösterir. İstenen şey, test hatasının eğitim hatasına yaklaşarak gitmesidir.

Aşırı uyumun nedenleri (ekrandan, 01:20:00):

- **Gürültü (noise):** Eğitim verisinde gürültü olabilir.
- **Yetersiz örnek (insufficient examples):** Eğitim kümesi az olabilir. Örneğin 100 satırlık veriyle kurulan ağaç, 2000-3000 satırla daha iyi öğrenebilirdi; az veride entropi ya da Gini hesaplanırken sayılar küçük kaldığı için hata çıkar.

<!-- BELİRSİZ: 01:20:29-01:22:56 arasındaki soru-cevap altyazıda büyük ölçüde bozuk; sorunun tam metni çıkarılamadı, aşağıdaki biçim hocanın anlaşılır cümlelerinden kuruldu. -->

**Soru:** Eğitim verisi artarsa (satır sayısı) ağaç hep büyür mü? **Cevap:** Hayır; her düğümde en iyi öznitelik seçildiği için satır sayısı ağacın büyüklüğünü doğrudan artırmaz. Ayrıca belli bir noktadan sonra eğitim hatası düz gitmeye başlar ve ne eklenirse eklensin azalmaz. Gürültü yüzünden dallar sıfıra sıfır ayrılamaz. Öznitelikler tekrar tekrar kullanılırsa çok büyük ağaçlar oluşur ve bu daha çok aşırı uyuma yol açar.

> **Hocanın vurgusu:** Kurduğunuz modelin eğitim verisinde %100 çalışmasını istemezsiniz. %100 çalışıyorsa büyük olasılıkla büyük bir aşırı uyum vardır: model hem verinin genel yapısını hem de gürültüyü öğrenmiş ve gürültüye duyarlı hale gelmiştir.

### 13.2 Uzayı bölme çizimi

Hoca aşırı uyumu iki boyutlu bir çizimle anlattı (ekrandan, 01:25:00). Yatay ve dikey eksenler iki öznitelik (x ve y) gibi düşünülür. Uzaya iki sınıfı temsil eden mavi ve kırmızı noktalar dağıtılır; birkaç nokta da gürültü olarak öteki sınıfın bölgesine konur.

Karar ağacının her düğümü aslında uzayı bir özniteliğe göre ikiye böler: "x şundan büyük olanlar ve küçük olanlar" gibi. Birinci düğüm uzayı bir dikey çizgiyle ikiye ayırır. İkinci düğüm bir taraftaki mavileri ayırmak için yeni bir çizgi çeker, üçüncüsü bir başka çizgi çeker. Sonraki düğümler geriye kalan iki mavi nokta için, sonra da tek bir kırmızı gürültü noktası için uzayı yeniden böler. Ağaç büyüdükçe bölmeler gürültü noktalarını tek tek ayırmaya başlar. Böylece ağaç eğitim verisindeki gürültüyü de öğrenir ve gürültüye göre hassaslaşır.

### 13.3 Budama

Aşırı uyumdan kaçınmanın iki yolu vardır (ekrandan, 01:20:00):

- **Ön budama (prepruning):** Ağaç oluşumu erkenden durdurulur. Bir düğümü bölmek iyilik ölçüsünün belli bir eşiğin altına düşmesine yol açacaksa düğüm bölünmez. Örneğin Gini indeksi bir noktadan sonra iyileşmiyorsa dallanma durdurulur. Burada budama yapılmaz; ağaç tam oluşmadan büyümesi bir koşulla kesilir.
- **Son budama (postpruning):** Önce tam büyümüş bir ağaç kurulur. Bu ağaç gürültüyü de öğrenir; son dallanmalar çoğunlukla gürültüye özel dallardır. Örneğin bir düğümde 999 örnek bir sınıftan, 1 örnek gürültüyse, yalnız o tek örnek için bir düğüm daha açılmıştır. Son budamada bu dallar tam ağaçtan kesilir ve giderek daha çok budanmış bir ağaç dizisi elde edilir.

### 13.4 Eksik uyum (underfitting)

Eksik uyum, modelin yeterince eğitilmemiş olmasıdır. Grafikte eğitimi 200 düğüm yerine 100 düğümde durdurduğunuzu düşünün. Bu noktada hem eğitim hatası hem test hatası hâlâ yüksektir ve ikisi de düşme eğilimindedir; eğitime devam edilse daha da düşecektir. Model henüz özelleşememiş, çok basit kalmıştır.

Eğitim sırasında hata eğrilerini adım adım çizmek, modelin nasıl öğrendiğini görsel olarak anlamak için çoğu zaman önemlidir; özellikle aşırı uyumun daha sık görüldüğü yapay sinir ağlarında.

Aynı hatayı veren iki ağaçtan basit olanı tercih etmek çoğu zaman daha iyidir; eksik uyum olmadığından eminseniz basit model seçilir. Aşırı uyumda genellikle daha karmaşık, daha büyük ağaçlar ortaya çıkar ve eğitim hatası tek başına pek bir şey söylemez.

Slaytlarda genelleme hatasının tahmin edilmesine (iyimser ve kötümser yaklaşım, azaltılmış hata budaması) ilişkin bir bölüm de vardır (ekrandan, 01:30:00); hoca bu bölümü anlatmadan geçti.

## 14. Karar Ağaçlarının Güçlü ve Zayıf Yanları

### 14.1 Güçlü yanlar

- Uygulaması kolaydır, anlaşılması da kolaydır.
- Kategorik değerleri çok, sürekli değerleri az olan ve sınıfları düz sınırlarla ayrılabilen verilerde çok iyi çalışır. Gerçek dünyada insanların oluşturduğu verilerin çoğu böyle olduğu için karar ağaçları sık kullanılır.
- Çok büyük olmayan veri kümelerinde iyi sonuç verir ve hızlıdır. Hoca, yapay sinir ağları ve naive Bayes gibi yöntemlerden çok daha hızlı çalıştığını söyledi.
- Ağaçtan kurallar çıkarılabilir: kökten başlayıp "eğer şu düğümde şu koşul varsa ve sonraki düğümde şu koşul varsa ..." biçiminde if-then kuralları yazılabilir. Bu kurallar programa dökülebilir. Uzman bilgisi gerektiren alanlarda (örneğin telefonla bilgi veren uzmanların bilgisi) bilgi karar ağacına dökülünce, kullanıcının girdisi hangi kurala uyuyorsa sistem doğrudan cevap verebilir ve kararını açıklayabilir; insanlar da kuralı kolayca anlar.

> **Ders sonrası not:** Naive Bayes eğitimi büyük olasılıkla tek geçişte sayım yaparak tamamlandığı için genellikle çok hızlıdır. Hocanın karar ağaçlarının naive Bayes'ten "çok daha hızlı" olduğu karşılaştırması büyük olasılıkla her durum için geçerli değildir; hız veri boyutuna ve uygulamaya bağlıdır.

### 14.2 Zayıf yanlar

- Paralelleştirmeye uygun değildir. Çok büyük veride bellek hatası alınabilir; algoritmalar genellikle ölçeklenebilir değildir. RainForest ve SPRINT gibi daha yeni ve ölçeklenebilir algoritmalar bu sorun üzerinde çalışır.
- Her karar sınırında tek bir öznitelik vardır.

Slayttaki örnek bunu gösterir (ekrandan, 01:35:00). Soldaki veri kümesi eksenlere paralel çizgilerle ayrılabildiği için karar ağacı bunu kolayca öğrenir: kökte `x < 0.43?`, sonra Yes dalında `y < 0.47?`, No dalında `y < 0.33?` sorulur; dört yaprağa sırasıyla (4 üçgen, 0 daire), (0 üçgen, 4 daire), (0 üçgen, 3 daire) ve (4 üçgen, 0 daire) düşer. Sağdaki veride ise sınıflar köşegen bir doğruyla ayrılır. Burada test koşulunun birden çok özniteliği içermesi gerekir; karar ağacı bu tür bir veri kümesiyle başa çıkamaz. Eksenlere paralel bölmelerle köşegeni ancak çok sayıda basamakla yaklaşık olarak izleyebilir. Sınırın daha yüksek dereceli bir polinomla gösterilen bir eğri olduğu verilerde durum daha da kötüdür.

> **Ders sonrası not:** Hoca "karar ağaçları hep lineer ayırır, lineer ayrılabilen verilerde iyi çalışır" dedi. Daha doğru ifade şudur: karar ağacının her bölmesi tek bir özniteliğe dayandığı için sınırlar eksenlere paraleldir. Slayttaki sağ örnekte veri lineer olarak ayrılabilir (tek bir köşegen doğru yeter), ama doğru eğik olduğu için karar ağacı onu iyi temsil edemez (ekrandan, 01:35:00).

Ağaçtaki her düğüm (örneğin `x < 0.43?`) tek başına küçük bir sınıflandırıcı gibi düşünülebilir.

### 14.3 Karar ağacıyla sürekli değer tahmini

Hoca derste şu soruyu sordu: karar ağaçları sınıflandırma için kullanıldı; yapraklarda sürekli değer olması isteniyorsa ağaç nasıl kullanılır? CART algoritmasının adı "classification and regression trees"tir, yani regresyon da yapar. Sınıfta verilen cevap, ağacın yes/no yerine aralıklarla çalışması ve yaprakta bir aralık ya da değer üretmesiydi. Hoca konuyu araştırılacak bir soru olarak bıraktı (bkz. Örnek Sorular).

## Örnek Sorular

### Soru 1: Entropi değerleri

(derste sözlü, 00:11:08) [12+,5-], [8+,8-] ve [8+,0-] kümelerinin entropisi nedir? Hangisi en homojendir?

**Çözüm:** [12+,5-] için $-\frac{12}{17}\log_2\frac{12}{17} - \frac{5}{17}\log_2\frac{5}{17} \approx 0.874$; [8+,8-] için 1; [8+,0-] için 0. En homojen olan [8+,0-]'dır, entropisi en küçük değer olan 0'dır. (Derste ilk değer "0.8 küsur" diye söylendi; tam değer python ile hesaplandı.)

### Soru 2: Kök özniteliğini bilgi kazancıyla seçme

(ekrandan, 00:20:00) Bölüm 7.3'teki 14 satırlık veride (9 yes, 5 no) age, income, student ve credit_rating özniteliklerinin bilgi kazancını hesaplayın. Köke hangi öznitelik konur?

**Çözüm (derste verildi):**

- $\text{Info}(D) = -\frac{9}{14}\log_2\frac{9}{14} - \frac{5}{14}\log_2\frac{5}{14} = 0.940$
- age: $\frac{5}{14}(0.971) + \frac{4}{14}(0) + \frac{5}{14}(0.971) = 0.694$, Gain = 0.246
- income: $\text{Info}_{income}(D) = 0.911$, Gain = 0.029
- student: Gain = 0.151
- credit_rating: Gain = 0.048

En büyük kazanç age'dedir; kök age olur.

### Soru 3: Alt düğümlerde en iyi öznitelik

(ekrandan, 02:15:00) Kök age olduktan sonra `<=30` ve `>40` dallarında (bölüm 7.5'teki tablolar) hangi öznitelikle bölünmelidir?

**Çözüm:** Derste gözle sayılarak çözüldü. `<=30` dalında student = no olan 3 örneğin hepsi no, student = yes olan 2 örneğin hepsi yes'tir; student dalı tam ayırır. `>40` dalında credit_rating = fair olan 3 örneğin hepsi yes, excellent olan 2 örneğin hepsi no'dur; credit_rating dalı tam ayırır. Sayısal karşılığı (derste verilmedi, python ile hesaplandı): iki dalda da $\text{Info} = \text{Info}([2,3]) = 0.971$ ve seçilen özniteliğin bölmeden sonraki bilgisi 0 olduğu için kazanç 0.971'dir; bu, o dalda alınabilecek en büyük kazançtır.

### Soru 4: Örnek sınıflandırma

(ekrandan, 02:05:00) Karar ağacında kök age; `<=30` dalında student (no ise no, yes ise yes); `31..40` dalında yes; `>40` dalında credit_rating (excellent ise no, fair ise yes) sorulmaktadır. (age = <=30, income = low, student = no, credit_rating = fair) örneği nasıl sınıflanır?

**Çözüm (derste verildi):** age = `<=30` dalına inilir, student = no olduğu için no yaprağına ulaşılır. Örnek negatif sınıflanır. Income ve credit_rating bu yolda hiç sorulmaz.

### Soru 5: Sürekli öznitelikte aday eşikler

(ekrandan, 00:40:00) Temperature değerleri 40, 48, 60, 72, 80, 90; sınıflar No, No, Yes, Yes, Yes, No. Aday eşikler nelerdir ve hangisi daha iyidir?

**Çözüm:** Aday eşikler sınıfın değiştiği yerlerin orta noktalarıdır: $(48+60)/2 = 54$ ve $(80+90)/2 = 85$ (derste verildi).

> **Çözüm (derste verilmedi):** Ebeveyn [3 Yes, 3 No] olduğu için $\text{Info}(D) = 1$. Temperature > 54: sol taraf [0 Yes, 2 No] (entropi 0), sağ taraf [3 Yes, 1 No] (entropi 0.811); $\text{Info} = \frac{4}{6}(0.811) = 0.541$, kazanç $1 - 0.541 = 0.459$. Temperature > 85: sol taraf [3 Yes, 2 No] (entropi 0.971), sağ taraf [0 Yes, 1 No] (entropi 0); $\text{Info} = \frac{5}{6}(0.971) = 0.809$, kazanç $0.191$. Kazancı daha büyük olan Temperature > 54 seçilir. (Python ile hesaplandı.)

### Soru 6: Kazanç oranı

(ekrandan, 00:45:00) Income özniteliği 14 örneği 4, 6, 4 olarak üç dala ayırıyor ve bilgi kazancı 0.029'dur. SplitInfo ve kazanç oranını hesaplayın.

**Çözüm (derste verildi):**

$$\text{SplitInfo}_{income}(D) = -\frac{4}{14}\log_2\frac{4}{14} - \frac{6}{14}\log_2\frac{6}{14} - \frac{4}{14}\log_2\frac{4}{14} = 1.557$$

$$\text{GainRatio}(income) = 0.029 / 1.557 = 0.019$$

### Soru 7: İkili öznitelikte Gini

(ekrandan, 00:55:00) Ebeveynde C0 = 6, C1 = 6. A özniteliği N1 = (C0: 4, C1: 3), N2 = (C0: 2, C1: 3); B özniteliği N1 = (C0: 1, C1: 4), N2 = (C0: 5, C1: 2) verir. Hangi öznitelik seçilir?

**Çözüm (derste verildi):** $\text{Gini}(parent) = 0.5$. A için $\text{Gini}(N1) = 0.49$, $\text{Gini}(N2) = 0.48$, $\text{Gini}_{splitA} = \frac{7}{12}(0.49) + \frac{5}{12}(0.48) = 0.486$. B için $\text{Gini}(N1) = 0.32$, $\text{Gini}(N2) = 0.408$, $\text{Gini}_{splitB} = \frac{5}{12}(0.32) + \frac{7}{12}(0.408) = 0.371$. Ağırlıklı Gini'yi en küçük yapan B seçilir.

### Soru 8: Sürekli öznitelikte Gini ile bölme

(ekrandan, 01:10:00) Bölüm 11.4'teki Annual Income ve Cheat verisinde en iyi bölme konumu nedir?

**Çözüm (derste verildi):** Sınıfın değiştiği konumlara bakılır. 80 konumunda `<=` tarafı [0 Yes, 3 No], `>` tarafı [3 Yes, 4 No]'dur ve ağırlıklı Gini $\frac{3}{10}(0) + \frac{7}{10}\left(1 - (3/7)^2 - (4/7)^2\right) = 0.343$ olur. 97 konumunda `<=` tarafı [3 Yes, 3 No], `>` tarafı [0 Yes, 4 No]'dur ve ağırlıklı Gini $\frac{6}{10}(0.5) + \frac{4}{10}(0) = 0.300$ olur (ara adımlar eklendi). En küçük Gini 97'dedir; bölme Annual Income <= 97 ve > 97 diye yapılır.

### Soru 9: Bilgi kazancı negatif olabilir mi?

(derste sözlü, 00:36:58) Bilgi kazancı negatif çıkabilir mi?

**Cevap (derste verildi):** Hayır. Bölme sonrası bilgi, çocukların entropilerinin örnek sayılarıyla ağırlıklandırılmış ortalamasıdır ve ebeveyndeki dağılım bu çocuklardan oluşur; bu yüzden bölme sonrası değer ebeveynin entropisini aşmaz.

### Soru 10: Dengesiz bölme

(derste sözlü, 02:13:33) Bir öznitelik verinin %99'unu bir dala, %1'ini öteki dala atıyorsa bu iyi bir bölme midir?

**Cevap (derste verildi):** Bölmenin iyiliği dallara düşen örnek sayısıyla değil, her dalın içindeki sınıf dağılımının ne kadar homojen olduğuyla ölçülür. Dallarda sınıflar karışık kalıyorsa bölme iyi değildir; dallar saf ise iyidir. Bu, entropi ya da Gini gibi bir safsızlık ölçüsüyle sayısal olarak belirlenir.

### Soru 11: Rastgele tahminin doğruluğu

(derste sözlü, 01:58:05) Bir sınıflandırma modeli en kötü ne kadar doğruluk verir?

**Cevap (derste verildi):** İki sınıflı ve dengeli bir problemde hiç model kurmadan rastgele artı ya da eksi demek bile yaklaşık %50 doğruluk verir. Sınıf dağılımı dengesizse bu taban değer farklıdır. Bu yüzden %60 gibi doğruluklar başarı sayılmaz.

### Soru 12: Karar ağacıyla sürekli değer tahmini

(derste sözlü, 01:34:53) Karar ağaçları yapraklarda sürekli değer üretmek (regresyon yapmak) için nasıl kullanılır?

> **Çözüm (derste verilmedi):** Derste yalnız "sınıf yerine aralıklarla çalışılır" diye kısa bir cevap verildi ve konu araştırılmak üzere bırakıldı. Regresyon ağaçlarında (örneğin CART'ın regresyon kipi) her yaprak, büyük olasılıkla o yaprağa düşen eğitim örneklerinin hedef değerlerinin ortalamasını tahmin olarak verir. Bölme ölçütü olarak entropi ya da Gini yerine, bölme sonrası hedef değişkenin varyansındaki (ya da ortalama kare hatasındaki) azalma kullanılır.

## Dersin Toparlaması

Bu derste sınıflandırma bölümüne başlandı. Sınıflandırmanın tahminden farkı, model oluşturma ve model kullanma adımları, eğitim ve test kümelerinin ayrılması ve doğruluğun hesaplanması anlatıldı. Ardından karar ağaçlarının yapısı ve özyinelemeli oluşturma algoritması incelendi. En iyi bölmeyi seçmek için üç safsızlık ölçüsü işlendi: entropiye dayanan bilgi kazancı, çok değerli özniteliklere karşı yanlılığı azaltan kazanç oranı ve logaritma içermediği için hızlı olan Gini indeksi. Kitaptaki 14 satırlık "bilgisayar alır mı" verisinde kök age olarak bulundu. Sürekli özniteliklerin sınıf geçiş noktalarından bölünmesi gösterildi.

Dersin sonunda aşırı uyum ve eksik uyum, eğitim ve test hatasının birlikte izlenmesi, ön budama ve son budama ele alındı. Karar ağaçlarının kolay anlaşılması, hızlı olması ve kural üretebilmesi gibi güçlü yanları ile eksenlere paralel sınırları ve büyük veride ölçeklenme sorunu gibi zayıf yanları tartışıldı. Karar ağaçlarının regresyonda nasıl kullanıldığı bir soru olarak bırakıldı. Sonraki derslerde Bayes sınıflandırıcıları, kural tabanlı sınıflandırıcılar ve destek vektör makinelerine geçileceği söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
