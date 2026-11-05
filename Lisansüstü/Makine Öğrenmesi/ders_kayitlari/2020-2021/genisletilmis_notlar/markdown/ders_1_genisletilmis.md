# Ders 1 Genişletilmiş Notu: Makine Öğrenmesine Giriş: Öğrenme Türleri, Veri Toplama ve Ön İşleme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Neden Makine Öğrenmesi?
- 2. Yapay Zeka, Makine Öğrenmesi ve Komşu Kavramlar
- 3. Uygulama Alanları
- 4. Öğrenme Türleri
- 5. Bir Öğrenme Sisteminin Ana Adımları
- 6. Problemi Anlama ve Öğrenme Yöntemini Seçme
- 7. Veri Toplama
- 8. Eğitim, Doğrulama ve Test Verisi
- 9. Veri Toplamadaki Sorunlar: Eksik Veri ve Dengesiz Sınıflar
- 10. Veri Tipleri
- 11. Ön İşleme ve Normalizasyon
- 12. Varsayımlar
- 13. Özellikler ve Model Seçimi
- 14. Derin Öğrenmeye Kısa Bakış

Ders, Prof. Dr. M. Elif Karslıgil tarafından verilen lisansüstü Makine Öğrenmesi dersinin giriş dersidir. Hoca, dersin temel kaynaklarının iki kitap olduğunu söyler: Ethem Alpaydın'ın "Introduction to Machine Learning" kitabı ve Christopher Bishop'ın "Pattern Recognition and Machine Learning" kitabı. Alan çok hızlı geliştiği için güncel yayınlardan da yararlanılacaktır. Hoca, Alpaydın'ın kitabının MIT Press'ten basıldığını ve yayınevinin en çok kullanılan ilk 10 kitabı arasında olduğunu, bunun Türkiye için gurur verici olduğunu belirtir.

## 1. Neden Makine Öğrenmesi?

### 1.1 İnsan Zekası ve Yapay Zekanın Amacı

Hoca konuya önce insan zekasının ne olduğunu sorarak girer. İnsanın düşünme, akıl yürütme, nesnel gerçekleri algılama, kavrama, yargılama ve sonuç çıkarma yeteneklerinin tümüne **zeka** denir.

Günlük hayatta farkına varmadan zekamızı kullandığımız pek çok iş vardır:

- Konuşulanı anlamak ve anladığımız şeye cevap vermek.
- Aklımızdaki bir fikri yabancı biriyle başka bir dilde (ör. İngilizce) paylaşmak ya da o dilde yazılmış bir belgeyi anlamak.
- Satranç oynamak.
- Araba kullanırken önümüzdeki engelleri fark edip onlara çarpmadan ilerlemek.

**Yapay zeka (artificial intelligence)** çalışmalarının amacı da budur: olaylar karşısında insan gibi düşünen, öğrenen ve davranan sistemlerle problemleri çözmek.

### 1.2 Kural Tabanlı Bir Sistemin Sınırı: Kredi Kartı Sahtekarlığı

Makine öğrenmesinin bu tablodaki yerini göstermek için hoca bir örnek verir. Bir bankanın kredi kartı sahtekarlığını (fraud) tespit eden bir yazılıma ihtiyacı olsun. Bunu ilk akla gelen yolla, yani kural tabanlı bir yazılımla yapmak istediğimizi düşünelim.

Hoca, bir bankanın bu iş için kullandığı kural tabanlı yazılımı gördüğünü anlatır. Kurallar şuna benzer:

- Günlük harcama belli bir tutarın (ör. 1500-2000 TL) üzerindeyse alarm ver.
- Bir kişi aynı gün 3 farklı ülkede alışveriş yapıyorsa alarm ver.
- Aynı yerde belli bir tutarın üzerinde alışveriş yapılıyorsa alarm ver.

Bu kurallar, zaman içinde sahtekarlık yapanların harcamalarına bakılarak oluşturulmuştur. Ama iki temel sorun vardır.

Birincisi, **her kural her kişi için geçerli değildir.** Bir öğrenci günde 40 TL harcıyor olabilir, bir iş insanı ise günde rahatlıkla 5000 TL harcayabilir. İş insanına sürekli "kartınızı siz mi kullanıyorsunuz?" diye alarm göstermek rahatsız edici olur.

İkincisi, kuralın yakaladığı durum gerçekte olağan olabilir. Aynı gün 3 ülkede bulunmak mümkündür: Sabah Türkiye'de havaalanında bir kahve alırsınız. Öğlen aktarma yaptığınız bir Avrupa ülkesinin havaalanında yine bir şey satın alırsınız. Akşam da varış ülkenizde bir harcama daha yaparsınız.

Hoca bu kuralla ilgili kendisine anlatılan bir olayı aktarır. Kuralları yazan yazılımcı bir toplantı için İtalya'ya gider, akşam komşu bir ülkeye geçer ve otelde rezervasyon yaparken kartı kapanır. Kart, aynı gün 3 ülkede kullanıldığı için sahtekarlık işlemi uygulanmıştır. Kodu kendisi yazdığı için durumu anlar ve sistemci arkadaşlarını arayıp kartın normale çekilmesini ister. Hoca, bugün dinlediğimizde bu çözümlerin son derece ilkel geldiğini söyler.

Buradan çıkan sonuç şudur: **Böyle bir problemi kural tabanlı bir algoritmayla çözmek çok zordur.** Çok fazla kural gerekir, hepsini kapsamak gerekir, ama her kural her zaman geçerli değildir.

### 1.3 Öğrenen Sistem Fikri

Peki bir algoritma tasarlamak yerine şöyle yapsak ne olur? Bankadan normal yapılan harcamalarla ilgili veri toplarız. Sahte olduğu beyan edilmiş işlemlerle ilgili örnekler de toplarız. Sonra sistemden bu örneklerden kendi kendine sonuç çıkarmasını isteriz.

Makine öğrenmesi çalışmalarında yapılan şey budur: **program yazmadan, sistemin verilen girişler için istenen çıkışı elde etmesini sağlamak.** Bu problemde sistem çok sayıda örnekten karakteristik özellikleri kendisi çıkarır. Böylece bilinmeyen bir örnek geldiğinde bu harcamanın gerçek mi sahte mi olduğuna kendisi karar verebilir.

Hoca bu amacı Arthur Samuel'in 1959'da söylediği cümleyle özetler: bilgisayarı programlamadan, yani program yazmadan, öğrenme özelliğine sahip sistemler geliştirmek.

## 2. Yapay Zeka, Makine Öğrenmesi ve Komşu Kavramlar

<!-- BELİRSİZ: Hoca bu bölümde slaytta yapay zeka, makine öğrenmesi, veri madenciliği, veri bilimi, büyük veri ve derin öğrenmenin kesişimlerini gösteren bir şema kullanıyor ("kesişim bölgelerine bakacak olursanız"). Şemanın kendisi altyazıda yok; aşağıdaki ilişkiler sözlü anlatımdan kuruldu. -->

### 2.1 Kural Tabanlı Sistemlerden Öğrenen Sistemlere

Yapay zeka çalışmaları 1940'lı yıllardan beri yapılmaktadır. Başlangıçta öğrenme özelliği olmayan, kural tabanlı sistemler kullanılıyordu.

Hoca parmak izi tanımayı örnek verir. Kişilerin parmak izleri toplanır. Parmak izindeki çizgiler aslında kopuk kopuk şekillerdir. Bu kopuklukların başlangıç noktaları, bitiş noktaları ve çatallanmaları tek tek işaretlenip kaydedilir. Yeni bir parmak izi geldiğinde bu noktaların kayıtlılarla nasıl eşleştiğine bakılır. Burada bir öğrenme yoktur. İşlem adımları belli olan bir sistem, bir takım karşılaştırmalarla sonuca gider.

İlerleyen yıllarda bu sistemlerin yetersiz kaldığı görüldü. İnsan zekası ezberleyerek değil öğrenerek çalışır ve daha önce karşılaşmadığı problemleri de çözebilir. O hâlde sistemlerin de öğrenme özelliği olmalıdır. Böylece yapay zeka çalışmalarında problemlerin çözümünde öğrenme kullanılmaya başlandı.

**Makine öğrenmesi (machine learning)**, bu yüzden yapay zekanın bir alt alanıdır: yapay zeka çalışmalarında problemin öğrenme ile çözülmesini sağlayan parçadır. Hocaya göre yapay zeka, ancak insan gibi düşünen ve öğrenen bir sistemle insana yakın başarılı sonuçlar verebilir.

### 2.2 Büyük Veri

Yapay zeka ve makine öğrenmesi çalışmaları ilk başladığında hedef, insanın beş duyusuyla yaptığı temel işleri yapmaktı: görme, işitme gibi. Yüz tanıma, parmak izi tanıma, sesten konuşanın kim olduğunu anlama bu dönemin tipik problemleridir.

Alanın bugün bu kadar popüler olmasının sebebi ise başkadır. Kullanılan veri çok büyüyünce veriye hakim olmak ve veri üzerinde işlem yapmak zorlaşır. Bu duruma **büyük veri (big data)** denir.

Hoca e-ticaretten örnek verir. Bir e-ticaret firması hangi tür müşterilerinin hangi ürünleri tercih ettiğini bilmek ister. Eskiden bu da kural tabanlı yapılıyordu: "Üniversite mezunu, kadın, hem çalışan hem evli olanlara şu tür ürünleri göster" gibi. Bu kurallar firmadaki sorumlu kişilerin tecrübesine göre yazılıyordu. Amazon gibi firmalarda müşteri sayısı milyonlara çıkınca bu kurallar işe yaramaz oldu. O zaman büyük veriden bilgi çıkarmak gerekti: hangi tür müşterilere hangi ürünler gösterilirse satın alıyorlar?

İkinci örnek **tavsiye sistemleridir (recommendation systems).** Netflix'in milyonlarca izleyicisi vardır. İnsanlar her zaman aynı türde film izlemez: bazen komedi, bazen belgesel, bazen suç filmi izler. Aynı tür içinde bile zevkler farklıdır. Kimi durum komedisinden hoşlanır, kimi içeriği olan ama komik anları da olan filmlerden. Kimi vurdulu kırdılı dizileri sever, kimi düşünceye dayalı yapımları. Netflix, birbirine benzeyen kullanıcıları bulup birinin beğendiği ve diğerinin henüz izlemediği filmleri ona "bunları da izlemek isteyebilirsiniz" diye öneren bir sistem geliştirdi ve bu çok başarılı oldu.

Bu örneklerde ortak olan şey şudur: elde bilgi çıkarılması gereken çok büyük bir veri vardır ve bu bilgi makine öğrenmesi yöntemleriyle çıkarılır. Hoca, özellikle son 5-10 yılda yapay zeka ve makine öğrenmesinin "gördüğünü anlasın, önündeki engele çarpmasın" düzeyinden bir adım öteye geçerek milyonlarca kişinin verisinden bilgi çıkarmaya kaydığını söyler.

### 2.3 Veri Madenciliği

Bilgi çıkarma deyince **veri madenciliği (data mining)** ve **veri bilimi (data science)** devreye girer. Veri madenciliği, veride madencilik yapmak, yani veriden anlamlı bilgi çıkarmaktır. "Bunu alan kullanıcılar şunu da aldı" önerisi bir veri madenciliği sonucudur: bir ürünü alan kullanıcıların en çok tercih ettiği diğer ürün yöntemle bulunur.

Buradaki hedef, büyük veriden **önyargısız** bilgi çıkarmaktır. İnsan bir şey önermeye çalıştığında aklına gelen ilişkiyi önerir: kola alana cips, kefir alana yanında başka bir sağlıklı ürün. Bunlar "bunu alan herhalde bunu da alıyordur" diye yapılan önyargılı önerilerdir.

Hoca veri madenciliği derslerinde çok anlatılan bir örneği aktarır. Amerika'da hangi ürünleri alanların yanında başka ne aldığına bakan bir analizde **bebek bezi alanların bira da aldığı** bulunur. Bu, "kola alan cips alır" türündeki varsayımlarımızla açıklanamayan bir ilişkidir. İncelendiğinde şu ortaya çıkar: küçük bebeği olan ailelerde babalar akşamları "bebek bezi almaya gidiyorum" diye çıkıp aynı zamanda bira da alıyorlarmış. Hoca örneğin akılda kalsın diye biraz esprili verildiğini söyler.

> **Ders sonrası not:** "Bebek bezi ve bira" örneği veri madenciliği literatüründe çok anlatılır, ama kaynağı belirsizdir ve bir şehir efsanesi olarak da bilinir. Örneğin amacı ilişki kuralı madenciliğinin önyargısız ilişki bulabildiğini göstermektir.

Veri madenciliğinin hedefi, insanların önyargıları olmadan verinin ne söylediğini anlamak ve bu bilgiyi kullanmaktır.

### 2.4 Veri Bilimi

**Veri bilimi**, veri madenciliğinin daha büyük veriyle uğraşılmaya başlanınca evrilmiş hâlidir. Soru şudur: farklı sektörlerde elimdeki veriden nasıl bilgi çıkarmalıyım, neleri anlamalıyım, nasıl yorumlamalıyım?

Hoca televizyon reklamlarından örnek verir. Amaç, izleyiciye segmentine göre reklam göstermektir. Önce bir izleyicinin hangi segmente dahil olduğu makine öğrenmesiyle anlaşılır. Sonra herkese aynı reklam yerine, bulunduğu segmente göre farklı reklamlar gösterilir. Önce bilgi çıkarılır, bu bilgi de makine öğrenmesi yöntemleriyle çıkarılır.

### 2.5 Derin Öğrenme

**Derin öğrenme (deep learning)**, temelde klasik makine öğrenmesi yöntemlerinin veri büyüdüğünde kullanılabilmesini sağlayan yöntemlerdir.

Hoca çıkış noktasını şöyle anlatır. Stanford Üniversitesi'ndeki bir ekip, insanlara resim etiketleten bir sistem kurdu. İnternette gezinirken karşınıza etiketsiz resimler çıkar ve siz bunları "bu kedidir, bu köpektir" diye etiketlersiniz. Böylece milyonlarca resim etiketlendi. **ImageNet** bu şekilde oluştu: milyonlarca etiketli, farklı durumlara ait resim içeren bir veri kümesidir.

<!-- BELİRSİZ: Altyazıda etiketleme sisteminin adı "Label Mini" olarak geçiyor; doğru adı altyazıdan anlaşılmıyor. -->

> **Ek bilgi (derste anlatılmadı):** ImageNet'teki etiketleme işi büyük ölçüde Amazon Mechanical Turk adlı kitle iş gücü platformu üzerinden yaptırılmıştır. Veri kümesi Stanford'dan Fei-Fei Li ve ekibi tarafından hazırlanmıştır.

Hoca kendi çalışma alanının görüntü işleme olduğunu, tanıma aşamasına gelince makine öğrenmesine geçtiğini anlatır. O dönemin en büyük sıkıntısını şöyle açıklar. Ayakkabı tanıyan bir sistem yapmak isteyelim. Ayakkabının topuklusu, spor ayakkabısı, bağcıklısı, burnu açığı, burnu kapalısı vardır. Hepsine örnek toplayıp etiketlemek altından kalkılacak bir iş değildi, düşünülmezdi bile. Bu yüzden sisteme çok basit, temel şekiller öğretilirdi. Kedi öğretilecekse dört ayağının üzerinde duran, başı karşıdan görünen, gözleri ve kulakları seçilen kediler öğretilirdi.

ImageNet ile durum değişti. Yatan kedi, kollarını açmış kedi, başı görünen ya da görünmeyen kedi gibi milyonlarca farklı fotoğraf olduğu için bunlardan bilgi çıkarılabildi. Bu kadar karmaşık veriden bilgi çıkarabilmek için **çok katmanlı yapay sinir ağları (artificial neural networks)** kullanıldı. "Derin" adı buradan gelir. Yapay sinir ağları da 1940'larda ortaya çıkmıştır.

İlk kez şu yaklaşım benimsendi: eskiden olduğu gibi 100-200 örnekle sistem eğitmeye çalışmak yerine milyonlarca örnekle eğitelim, böylece sistem gerçek karakteristikleri elde etsin. Hoca bunu insanın öğrenmesine benzetir: arkası dönük bir kediyi nasıl tanırız? Yıllar içinde öğrenme sistemimiz çok farklı durumlardaki örnekleri toplar ve öğrendikçe tanıma başarımız artar.

Derin öğrenme, yıllarca başarısı yetersiz olduğu için tercih edilmeyen modellerin, hem örnek sayısının artması hem de modelin daha etkili hâle gelmesi sayesinde çok yüksek başarı göstermesini sağladı. Örneğin eskiden yüz tanımada "fotoğraf karşıdan çekilecek, yüz en fazla ±15 derece sağa sola dönebilir" gibi bir sürü kural konurdu. Şimdi doğal ortamlarda kişilerin çok sayıda fotoğrafı tutulduğu için tanıma başarıları %100'e yakın düzeylere geldi. Bu avantaj yüzünden derin öğrenme birden k-en yakın komşu, karar ağacı gibi klasik makine öğrenmesi yöntemlerinin önüne geçti.

Ama zaman içinde şu da fark edildi: **bazı problemlerin çözümü için derin öğrenmeye gerek yoktur.** Bazı problemler yapısı gereği karar ağacı, k-en yakın komşu, destek vektör makineleri gibi temel yöntemlerle ve daha az veriyle başarılı olabilir. Bunların derin öğrenmeyle yapılmış modelleriyle karşılaştırıldığında başarı çok artmaz. Üstelik derin öğrenmede modelin eğitimi günler alır ve daha yavaştır.

> **Hocanın vurgusu:** Çok büyük veri işleniyorsa ve doğrusal olarak ayrılamayan, çok karmaşık problemler varsa derin öğrenme daha faydalı olabilir. Ama klasik makine öğrenmesi yöntemleri aynı ya da yakın başarıyı veriyorsa problem klasik yöntemlerle çözülmeye devam edilmelidir.

Kavramların birbirine göre yeri şöyle özetlenebilir:

- Makine öğrenmesi, yapay zekanın öğrenme ile problem çözen alt alanıdır.
- Derin öğrenme, makine öğrenmesinin büyük veri kullanan ve çok katmanlı yapay sinir ağlarına dayanan alt alanıdır.
- Veri madenciliği ve veri bilimi, veriden bilgi çıkarmayı hedefler. Bu bilgiyi çıkarmanın aracı makine öğrenmesidir. Büyük veri kullandıkları için derin öğrenmeyi de çok kullanırlar.

## 3. Uygulama Alanları

Makine öğrenmesinin çok geniş bir kullanım alanı vardır. Hocanın verdiği örnekler:

- **Biyoinformatik:** Bir ailede kansere sebep olan gen hangisidir? Burada da içinden bilgi, örüntü ve motif çıkarılması gereken çok büyük bir veri vardır.
- **Profil çıkarma:** Hoca bir Avrupa Birliği projesinden söz eder. Soru şudur: 57 numaralı yolcu potansiyel bir tehdit midir? Kişinin hareketlerine bakılır: yürüyüşü, izlediği rota, saklanarak mı yoksa ortada rahatça mı yürüdüğü, aceleci olup olmadığı.
- **Pazarlama:** Bir web sayfasını gezen kişi potansiyel müşteri midir, ona hangi ürünler gösterilmelidir?

Hoca, farkında olalım ya da olmayalım, günlük hayatta pek çok bilgisayar uygulamasının artık makine öğrenmesiyle çalıştığını söyler. Bu derste makine öğrenmesi yöntemleri ve bunların nasıl kullanılacağı, bilginin sisteme alınmasından çıkışa kadar bütün aşamalarıyla işlenecektir.

## 4. Öğrenme Türleri

Temelde üç öğrenme yöntemi vardır: **eğitmenli öğrenme**, **eğitmensiz öğrenme** ve **pekiştirmeli öğrenme** (ödül ve ceza ile öğrenme). Bunların arasında son yıllarda çok kullanılan bir ara tür de vardır: **yarı eğitmenli öğrenme**.

### 4.1 Eğitmenli Öğrenme (Supervised Learning)

Eğitmenli öğrenmede elimizde hem giriş bilgisi hem de çıkış bilgisi etiketli olarak bulunur. Sistem, $x$ girişi verildiğinde $y$ çıkışının nasıl elde edileceğini öğrenir.

Burada da kod yazılmaz. "Boyu şu kadar santimden uzunsa, kilosu şu kadardan fazlaysa, yaşı da şöyleyse..." gibi kurallar verilmez. Yalnızca örnekler verilir. Sınıflarımız vardır ve her sınıf için yeterli sayıda örneğimiz vardır. Hoca "yeterli sayı" meselesinin ilerleyen derslerde inceleneceğini söyler. Sistem bu örneklerden, verilen $x$ için doğru $y$ çıkışının ne olduğunu öğrenir.

Hocanın verdiği eğitmenli öğrenme problemleri:

- Girişte bir kişinin ses bilgisi verilir, çıkışta sesin sahibi bulunur (sesten kişi tanıma, bir biyometri uygulaması).
- Girişte optik ya da kızılötesi görüntü verilir, çıkışta görüntünün insana mı araca mı ait olduğu bulunur (ör. askeri bir uygulama).
- Girişte kredi kartı harcama bilgisi verilir, çıkışta harcamanın sahtekarlık olup olmadığı bulunur.
- Girişte ağ trafiği bilgisi verilir, çıkışta bir ağ saldırısı olup olmadığı bulunur.

Hoca slaytta ImageNet görüntüleri üzerinde elde edilmiş tanıma sonuçlarını gösterir. Tilki resimlerinde birinin yalnız başı, birinin yarısı, birinin tamamı görünür. Eski klasik sistemler yalnız tamamı görünen tilkiyi tanıyabilirdi; yeni sistemler diğerlerini de tanır. Bir resimde arka plana çok karışmış, farklı açılardan görünen ve birinin bir gözü görünmeyen iki kurbağa vardır. Hoca bunları kendisinin bile zorlukla ayırt ettiğini söyler; eski sistemler ancak karşıdan çekilmiş bir kurbağayı tanıyabilirdi. Bir başka resimde ne olduğunu anlamanın zor olduğu bir yemek "kroket" olarak doğru tanınmıştır.

Eğitmenli öğrenmede biz yalnızca giriş örneklerini verir ve çıkışta ne istediğimizi söyleriz. Kredi kartı örneğinde girişte normal ve sahte harcamalara ait örnekler verilir. Çıkışta iki sınıf vardır: sistem bilinmeyen bir örnek için "bu sahte kullanımdır" ya da "bu normal kullanımdır" demelidir.

Bunun bir bedeli vardır: **bütün verinin etiketlenmesi gerekir.** Etiketlemek, sisteme verilecek örneklerin hepsinin ne olduğunun bilinmesi demektir. Tilki resmini öğretmek için veriyorsanız, resimdeki tilkileri tek tek "bu tilki, bu tilki" diye göstermeniz gerekir.

Hoca slaytta etiketli örnekler üzerinde öğrenilen **karar sınırlarını (decision boundaries)** gösterir. Kullanılan makine öğrenmesi yöntemi bu sınırları oluşturur. Bilinmeyen bir örnek geldiğinde, sistem örneğin sınırların hangi tarafında kaldığına bakarak "bu artı sınıfına aittir" gibi bir karar verir.

### 4.2 Eğitmensiz Öğrenme (Unsupervised Learning)

Verileri her zaman etiketlemek mümkün değildir. Böyle bir durumda sistemin veriler arasındaki ilişkiyi kendi kendine kurması gerekir. Yaklaşım şudur: birbirine çok benzeyen örnekler aynı gruptadır, az benzeyenler farklı gruptadır. Sistem bu düşünceyle örnekleri gruplar. Bu işleme **kümeleme (clustering)** denir.

Çıkışta "bu kedidir, bu köpektir" gibi bir sınıf adı yoktur. Sistem yalnızca grupları verir. Siz gruplara bakarak "bu grupta şu tür örnekler, şu grupta başka örnekler var" dersiniz ve etiketleri biliyorsanız gruba etiket verirsiniz.

Hocanın verdiği örnekler:

- **Benzer fotoğrafları gruplamak.** Bir yerde fotoğraf çekerken genelde aynı yerde 5-6 fotoğraf birden çekeriz. Sistem telefondaki bu fotoğrafları benzerliklerine göre gruplayabilir. Burada etiketleme yapmanın anlamı da yoktur: etiketleyecek olsanız zaten elle gruplardınız. Başlangıçta eğitmensiz öğrenme, az veriyle ve etiketlemenin gerekli ya da kolay olmadığı bu tür durumlarda kullanılıyordu.
- **Belgeleri içeriğe göre gruplamak.** Amaç, belgelerin ekonomi haberi mi spor haberi mi olduğunu söylemek ve bilinmeyen bir belge geldiğinde de bunu yapabilmektir. Eğitmenli yaklaşımda çok sayıda belgeyi önce okuyup elle etiketlemek gerekir; bu çok zaman alır. Hoca yıllar önce, bankada çalışan bir yüksek lisans öğrencisinin "ekonomi haberlerinin borsadaki değişime etkisi" tezinde bin civarında haberi tek tek okuyup olumlu ya da olumsuz diye etiketlemek zorunda kaldığını anlatır. Bugün eğitmensiz yöntemler oldukça başarılıdır: sistem önce belgeleri kendi gruplar, siz gruptaki örneklere bakarak gruba etiket verirsiniz. Böylece çalışma hızlanır.
- **Kelimelerin hiyerarşik kümelenmesi.** Hoca slaytta kelimelerin benzerliklerine göre ağaç yapısında gruplandığı bir örnek gösterir. "Graph theory" ve "number theory" gibi terimler kendi aralarında gruplanmış ve bir üst başlığın altında toplanmıştır. "Chemistry" altında başka terimler gruplanmıştır. Bazı kelimeler iki grupta birden geçmektedir.

<!-- BELİRSİZ: Hiyerarşik kümeleme örneğindeki kelimeler ve üst başlık slayttadır; altyazıda yalnız "graph teori, logic number teori, chemistry" geçiyor ve "metin altındalar" ifadesi anlaşılmıyor. -->

**Grupların içine yanlış örnekler karışmaz mı?** Hocanın bu soruya iki cevabı vardır.

Birincisi, karışabilir; ama bu tür problemlerde insanlar da farklı etiketleyebilir. Hoca, öğrencilerine yıllarca yaptırdığı bir çalışmayı anlatır: afet sonrası atılan tweet'leri "önemli" ve "önemsiz" diye gruplamak. Amaç, ilk yardımda bu mesajlardan yararlanmaktı. Afetten sonra insanlar sosyal medyada "çok üzüldük, herkese geçmiş olsun" gibi iyi dilek mesajları yazar; bunların bilgi değeri yoktur. Ama "şu ilçede çok sayıda ev yıkıldı, göçük altında kalanlar var" ya da "şu köyde hasar çok fazla" gibi mesajlar, sıkıntının fark edilmediği bir yere hemen yardım göndermeyi sağlayabilir. Bu tür çalışmalarda aynı veri farklı 5-10 kişiye etiketletilir ve en çok verilen etiket (çoğunluk oyu) alınır. Etiketleyiciler "binlerce kişi öldü, çok sayıda yaralı var" gibi mesajlarda hemfikirdi. Ama "bu köyde hasar çok fazla" gibi mesajlarda biri "neye göre çok, belirsiz" deyip önemsiz, diğeri önemli diye etiketliyordu. Yani "bu kedi mi köpek mi" gibi cevabı somut olarak bilinen bir durum yoktur; etiketleme zaten sıkıntılıdır.

İkincisi, arada ufak tefek yanlışlar olursa bunlar sistemin bütününe çok zarar vermez.

**Soru:** Eğitmensiz yöntemde hatalı gruplananlar nasıl düzeltiliyor? Hatalı olup olmadığını nasıl anlıyoruz? **Cevap:** Hatalı olanlar düzeltilmez. Ama sistem hiçbir zaman kontrolsüz bırakılmaz. Kurulan modelin önce bir prototipi yapılır. Eğitmensiz bir yöntem kullanıyor olsanız bile önce sistemin başarısını etiketini bildiğiniz verilerle değerlendirirsiniz; aksi hâlde iyi bir sistem kurup kurmadığınızı ölçemezsiniz. Böylece tasarım aşamasında sistemin genelde %1-2 mi yoksa yarı yarıya mı yanlış grupladığını bilirsiniz. Sonra milyonlarca etiketsiz veri üzerinde çalışırken modelin iyi olduğunu ve çok yanlış bir şey yapmayacağını bilirsiniz. Bir milyon veriyi etiketleyecek zamanınız ve elemanınız yoksa, aradaki kaçakların yanlış olmasını göze almış olursunuz. Örneğin banka müşterilerini harcama karakteristiklerine göre gruplarken 30-40 özellik vardır; iki üç özellik olsa çizip bakardınız, ama bu kadar özellikte kimin neden aynı gruba düştüğünü anlamak mümkün değildir. Orada yapıya güvenirsiniz.

> **Hocanın vurgusu:** Bu sistemler hiçbir zaman başıboş bırakılmamalıdır. Makine öğrenmesi yöntemlerinin en önemli noktalarından biri başarı ölçümüdür. Önce bir prototip üzerinde başarıyı ölçer, sistemin yeterince iyi olduğunu anlar, sonra gerçek kullanıma açarsınız.

### 4.3 Yarı Eğitmenli Öğrenme (Semi-Supervised Learning)

Yarı eğitmenli öğrenme, az sayıda etiketli ve çok sayıda etiketsiz veriden öğrenmektir. Veriyi hiç etiketleyemiyorsak eğitmensiz öğrenme kullanırız; biraz da olsa etiketleme fırsatımız varsa yarı eğitmenli öğrenme kullanılabilir. Hoca bunun, eğitmensiz yöntemdeki hatalarla ilgili soruya da bir ölçüde cevap olduğunu söyler.

Hoca slaytta aynı veri üzerinde üç durumu karşılaştırır:

- Eğitmenli öğrenmede bütün örnekler etiketlidir ve yöntem karar sınırlarını oluşturur.
- Eğitmensiz öğrenmede hiçbir örnekte etiket yoktur; sistem aynı örnekleri benzerliklerine göre kendi gruplar.
- Yarı eğitmenli öğrenmede bazı örnekler (kırmızı artılar, yıldızlar) sizin etiketlediğiniz örneklerdir, siyah olanlar etiketsizdir. Etiketli örnekler sayesinde kümeleme daha başarılı olur.

Son yıllarda çok yapılan yaklaşım şudur: verinin etiketleyebildiğimiz kadar küçük bir bölümünü etiketleriz, etiketsizleri de etiketli bilgisinden yararlanarak gruplamaya çalışırız.

### 4.4 Pekiştirmeli Öğrenme (Reinforcement Learning)

Türkçede "pekiştirmeli öğrenme" denir, ama hoca bu adı sevmez ve "ödül-ceza ile öğrenme" adının konuyu daha iyi anlattığını düşünür.

Hoca bir örnekle anlatır. Uzaya bir robot gönderdiniz ve değerli taşları toplamasını istiyorsunuz. Robot yolu bilmiyor, hangi yoldan gitmesi gerektiğini bilmiyor. Siz ona şunu söylersiniz: taşlara ulaşırsan ödül alırsın; büyük bir kayaya çarpıp yolda ilerleyemezsen ceza alırsın. Bu sistemde siz yalnızca ödülleri ve cezaları belirlersiniz ve ne yapmasını istediğinizi söylersiniz. Başka hedef örnekleri: bir labirentten çıkmak, insansız bir taşıtın A noktasından B noktasına kuşlara çarpmadan gitmesi.

Ödüllerin pozitif puanları, cezaların negatif puanları vardır. Sistem hangi yollardan gitmenin etkili olacağını kendi kendine öğrenir: bir noktaya geldiğinde bundan sonra hangi tarafa gitmesinin daha uygun olduğunu öğrenir.

Bu yaklaşım önce oyunlarda, sonra insansız taşıt uygulamalarında çok kullanıldı. Ama uzun süre alanı çok genişleyemedi. Son yıllarda derin öğrenme yöntemlerinin başarılı olmasıyla pekiştirmeli öğrenme derin öğrenme içinde kullanılmaya başlandı, çok başarılı sonuçlar alındı ve şu anda pek çok farklı uygulamada aktif olarak kullanılıyor: çıkış yolunu kendi bulma, taşıtların engellere çarpmadan gitmesi gibi.

Hoca, ilk bakışta pek ilgisiz görünen bir uygulama da anlatır: **internet reklamları.** Büyük firmalar reklamlarını Google'da, Facebook'ta ve başka yerlerde yayınlar. Reklamın kime gösterileceği de makine öğrenmesiyle belirlenir. Örneğin kırmızı spor ayakkabı reklamı, genç, üniversite öğrencisi ve sporla ilgili, protein içeceği arayan kişilere gösterilir; sağlıklı bitki içecekleri reklamı yoga matı arayanlara gösterilir, çünkü bu kişilerin bu tür ürünlerle ilgileneceği düşünülür.

Sorun reklamın etkisinin değerlendirilmesindedir. Kullanıcı satış sayfasına Google araması üzerinden geldiyse firma "reklamımı Google'da gördü ve geldi" der. Oysa kullanıcı reklamı belki önce Facebook'ta görmüş, orada incelemiş, sonra Google'da görüp satın almaya gelmiştir. Sistem yalnız son geliş yerini aklında tuttuğu için Facebook'taki etkileşimi kaybeder. Bu tür bir etkiyi klasik öğrenme yöntemleriyle öğretmek mümkün değildir. Pekiştirmeli öğrenmeyle ise kişinin uğradığı farklı ortamlar, reklamları gördüğü yerler, sitede ne kadar kaldığı ve en sonunda satın alması arasındaki yol incelenebilir. Satın almaya giden yoldaki her durağın etkisi öğrenilir. Böylece firma "Facebook'a da reklam vermeli miyim?" sorusunun cevabını bulur. Hoca bunun çok karmaşık bir problem olduğunu, Alibaba'nın yakın zamanda yayımlanan bir makalesinde oldukça başarılı biçimde çözüldüğünü okuduğunu söyler.

### 4.5 Öğrenme Türlerinin Karşılaştırması

Verilen bilgi miktarına göre bakıldığında:

- Eğitmensiz öğrenme en az bilgiyle çalışır.
- Pekiştirmeli öğrenmede sisteme karar verebilmesi için biraz bilgi (ödül ve ceza) verilir.
- Eğitmenli öğrenme ise tam bir eğitimle, etiketli veriyle karar veren modellerdir.

Bugün bu türler iç içe geçmiş durumdadır. Yarı eğitmenli öğrenme hem eğitmenli hem eğitmensiz öğrenmenin özelliklerini taşır. Pekiştirmeli öğrenmede de sisteme ne yapacağını tam söylemezsiniz, ama ödül ve cezalarla yönlendirirsiniz.

## 5. Bir Öğrenme Sisteminin Ana Adımları

Hoca bir öğrenme sisteminin ana adımlarını slaytta bir akış şeması olarak gösterir:

```text
Gerçek dünyadan gelen bilgi (sensör: mikrofon, kamera; veritabanı)
  -> Ön işleme
  -> Ayırt edici özelliklerin çıkarılması / seçilmesi
  -> Model (eğitmenli / eğitmensiz / pekiştirmeli)
  -> Model seçimi ve değerlendirme
```

**Bilginin alınması.** Önce bir yerden bilgi alınır. Bu bir bankadaki müşteri işlemleri (transaction) olabilir, reklamlardan e-ticaret sayfanıza gelip alışveriş yapan kişilerin bilgisi olabilir. Eskiden bilgi genelde dış dünyadan sensörler aracılığıyla alınırdı: ses için mikrofon, görüntü için kamera. Ya da veritabanlarından, örneğin bankanın kayıtlı müşteri bilgisinden gelir.

**Ön işleme.** Bilgiyi olduğu gibi kullanmak genellikle mümkün değildir. Görüntü ise iyileştirilmesi gerekebilir ya da başka bir renk uzayında daha iyi sonuç alınıyorsa renk uzayı değiştirilebilir. Banka müşteri verisinde birçok bilgi yanlış girilmiş, hiç girilmemiş ya da eksik olabilir; bunların temizlenmesi ve düzeltilmesi gerekir. Ön işlemle bilgi kullanılabilir hâle getirilir.

**Ayırt edici özelliklerin çıkarılması.** Kredi kartı sahtekarlığı örneğinde bir müşteri işleminin 30-40 bilgisi vardır. Bunların hepsi işe yarayan, karakteristik bilgiler midir? Örneğin kişinin adres bilgisi kullanılmalı mıdır? Kullanılsın diye düşünebiliriz, ama belki hiçbir ayırt ediciliği yoktur. Bunu anlamamız gerekir.

> **Hocanın vurgusu:** Eğitmenli, eğitmensiz ya da pekiştirmeli, ne yaparsanız yapın, **sınıf içi benzerliği çok, sınıflar arası benzerliği az** yapan karakteristik özellikler seçilmelidir.

Özellik sayısı kararında olmalıdır. Az özellik kullanırsanız karakteristikleri yakalayamayabilirsiniz. Gereğinden çok özellik kullanırsanız bu sefer sınıflar arası benzerlik artmaya başlar: aynı özellikler hem sahte hem normal sınıfında etkili olur. Bu istenmeyen bir durumdur. Hoca bu aşamayı "feature selection / projection" (özellik seçimi / izdüşümü) olarak adlandırır.

**Model.** Bu özellikleri kullanarak sistemin öğrenmesini sağlayan bir model gerekir: eğitmenli, eğitmensiz ya da pekiştirmeli bir yöntem.

**Model seçimi.** Hoca, TÜBİTAK TEYDEB projelerinde ve Sanayi Bakanlığı'nın Ar-Ge merkezi değerlendirmelerinde hakemlik yaparken gördüğü bariz bir hatayı anlatır. Firma bir yöntem seçer, örneğin k-en yakın komşu ile sınıflandırma yapar, ve "performansımızı %5 artırdık" der.

**Soru (hocanın sınıfa sorusu):** Bir yöntem seçtim, modelimi kurdum ve performansımın arttığını gördüm; örneğin sahtekarlıkları yakalayıp daha az para kaybediyorum. Bu yeterli mi? **Cevap (bir öğrenci, hoca onaylıyor):** Yeterli değil. Farklı algoritmalarla farklı modeller geliştirip karşılaştırmak ve en doğru olanı kullanmak gerekir.

Hoca bunun çok sık yapılan bir hata olduğunu söyler: "performans iyileşti" deyip kestirip atmamak gerekir. Literatür bir problem için hangi yöntemin iyi olacağı konusunda yol gösterebilir. Örneğin yüz tanımada özellik azaltmak için temel bileşen analizi (principal component analysis, PCA) ve üzerine k-en yakın komşu (k-NN) kullanmanın en iyi performansı verdiğini görebilirsiniz ve gerçekten öyle olur. Ama özel problemlerde literatürde birebir aynı çalışmayı bulamazsanız bunun bir garantisi yoktur.

> **Hocanın vurgusu:** Tek model değil, kullanılabilecek bütün olası modeller denenmeli; en uygun model ve onun en uygun parametreleri performans analiziyle belirlenmelidir. Örneğin k-en yakın komşuda $k=3$ mü $k=5$ mi olmalı, destek vektör makinesinde parametreler ne olmalı? Sizin yönteminiz performansı %5 artırmış olabilir, ama başka bir yöntem %10-15 artırabilir.

## 6. Problemi Anlama ve Öğrenme Yöntemini Seçme

İlk yapılması gereken şey problemi çok iyi anlamaktır. Hoca, bilgisayar mühendisliğinde basit bir veritabanı tasarımında bile öğrencilerden önce iyi bir sistem analizi ve fizibilite çalışması istendiğini hatırlatır. Burada da aynısı geçerlidir. Nasıl bir veriniz var, bu veri ne kadar sürede toplanıyor, sınıflara ait örnekler ne kadar sürede elde ediliyor: bunların hepsini çok iyi biliyor olmanız gerekir.

Sonra problemin çözümü için hangi öğrenme yönteminin uygun olduğuna karar verilir:

- **Etiketlenebilen veri varsa eğitmenli öğrenme kullanılabilir.** Kredi kartı sahtekarlığı tespitinde elinizde müşterinin "sahte kullanım / normal kullanım" etiketli verisi zaten vardır.
- **Etiket yoksa eğitmensiz öğrenme kullanılabilir.** Örneğin Netflix izleyicilerini izledikleri filmlere ve dizilere göre benzerliklerine bakarak segmentlere ayırmak istiyorsunuz. Segmentleri bilmiyorsunuz; sonunda yalnızca "bunlar benzer" diyeceksiniz.
- **Anomali tespiti (anomaly detection) gerekebilir.** Ağ saldırısı tespitinde belirli saldırılar için kural tabanlı bir şey yapabilir ya da model geliştirebilirsiniz. Ama siz bir saldırıyı öğrendikçe saldırgan saldırı türünü değiştirir. O zaman sisteme hangi durumların normal, hangilerinin anormal olduğunu öğretmeniz gerekir.

Eğitmenli öğrenme seçildiyse sorulacak sorular şunlardır (kredi kartı sahtekarlığı üzerinden):

- **Veri etiketlenebiliyor mu?** Evet. Sahte kullanım ve normal kullanım diye iki sınıf var.
- **Çıkış sürekli mi, sınıf mı?** Burada sınıf; iki sınıf var.
- **Veriyi etiketlemek kolay mı?** Etiketlemede çok sıkıntı çekilen durumlarda eğitmenliden eğitmensize geçilebilir. Etiketli veri var diye illa eğitmenli öğrenme kullanmak gerekmez.

**Sürekli çıkış ne demektir?** Hoca ev fiyatı örneğini verir. Bölgedeki evlerin satış fiyatları, metrekareleri gibi bilgiler giriş olarak verilir. Sonra "1970 yılında yapılmış, 100 metrekare, Beşiktaş'ta bir ev kaç liradır?" diye sorulur. Sistem bir tahmin yapar, örneğin "700 bin liradır" der. Bu sürekli bir çıkıştır. Sistem "pahalıdır" ya da "ucuzdur" deseydi çıkış sınıf olurdu.

> **Ek bilgi (derste anlatılmadı):** Çıkışı sınıf olan eğitmenli öğrenme problemlerine **sınıflandırma (classification)**, çıkışı sürekli bir sayı olan problemlere **regresyon (regression)** denir. Ev fiyatı tahmini tipik bir regresyon problemidir.

## 7. Veri Toplama

### 7.1 Veri Toplanabileceğinden Emin Olmak

Hoca veri toplamayı ikinci ve en büyük aşama olarak tanımlar.

> **Hocanın vurgusu:** Belli miktarda veri toplamadan asla projeye başlamamalısınız.

Hoca iki örnek anlatır. Birincisi, pandeminin yeni başladığı dönemde hakemlik yaptığı bir projedir. Bir turizm firması, kişilerin uçuş bilgilerini toplayıp (İstanbul-Ankara, İstanbul-İzmir, İstanbul-Küba gibi) makine öğrenmesiyle "senin gittiğin yönde şu ucuz uçuşlar var" diye uçuş öneren bir sistem kurmak istiyordu. Hocaya göre güzel ve yapılabilir bir projeydi. Ama firma o noktada veri toplamamıştı; veriyi birlikte çalıştığı IATA'dan rahatça alabileceğini düşünüyordu. O dönem herkes karantinanın birkaç ayda biteceğini sanıyordu. Proje, sırf veri toplanamayabileceği gerekçesiyle kabul edilmedi.

İkincisi, hocanın jürisinde bulunduğu bir doktora tezidir. Öğrenci, ortopedik bir rahatsızlığın görüntüden tanınması üzerine çalışıyordu. Rahatsızlık çok az görüldüğü için öğrencinin 4 yıllık tez süresi boyunca toplayabildiği veri sayısı 20'yi geçmedi.

Hoca bunun yalnız büyük firma projeleri için değil, yüksek lisans ve doktora tezleri için de geçerli olduğunu söyler: önce verinin toplanabilir olduğundan emin olmanız gerekir.

### 7.2 Sınıf Sayısı ve Örnek Çeşitliliği

Veri toplarken, problem bir sınıflandırma problemiyse önce kaç sınıf olacağına karar verilir. Sonra örneklerin çeşitliliğine nasıl karar verileceği gelir. Hoca bunun çok önemli bir problem olduğunu vurgular.

Derin öğrenmenin örnek sayısını artırarak başarıyı yükselttiğini söylemiştik. Bunun arkasında yatan gerçek, örnek sayısı arttıkça örneklerin çeşitliliğinin de artmasıdır. Derin öğrenme kullanmasanız ve o kadar çok veri toplayamasanız bile, örneklerinizin çeşitliliği başarınızı artırır. Örneğin farklı gelir seviyelerinden, farklı eğitim seviyelerinden, farklı şehirlerden olabildiğince çeşitli örnek toplanmalıdır.

Hocanın bunun için iki önerisi vardır:

- **Örnek sayısını artırmak.** Böylece çeşitlilik kendiliğinden oluşur.
- **Problemle ilgili ana senaryoları çıkarmak ve bu senaryolar için önce örnek toplamak.**

Ana senaryolar şu demektir. İnsansız uçan bir drone yapıyorsunuz. Güzergahında düzgün gitmesine engel olacak ana problemler nelerdir? Örneğin uçtuğu yükseklikte karşısına sürekli kuş çıkıyor olabilir; bu, yüzyılda bir değil, sürekli karşılaşılan bir problemdir. Sağanak yağışta görüş alanı azalıyor ve uçamıyor olabilir. Hoca bu örnekleri canlandırmak için uydurduğunu, drone'larla ilgili bir tecrübesi olmadığını belirtir. Yüz tanımadan bir örnek: sistem ışığı az ortamlarda alınan görüntülerde başarısız oluyorsa ve bu ortam sık görülüyorsa, o ortamdaki görüntüleri de veriye katmanız gerekir.

Yani çok örnek toplamak anlamlıdır; ama problemi analiz edip ana senaryoları belirlemek ve bu senaryolara karşı dayanıklı (robust) bir sistem kurmaya çalışmak gerekir.

### 7.3 Veri Toplamada Sorulması Gereken Diğer Sorular

- **Eksik veri var; nasıl kullanılacak?** Bir sınıfa ait zaten az veri varsa ve bunların bir kısmı eksikse, eksik örnekleri atmak veriyi daha da azaltır. Bunları kullanmanın bir yolu var mı? (Bölüm 9'da işleniyor.)
- **Ne kadar veri yeterli?** Hoca, sahtekarlık tespitinde bir yıllık işlem ve 10 bin müşterinin yeterli olmadığını, milyon mertebesinde müşteri gerektiğini söyler.
- **İyi örnekler kadar kötü örnekler de olmalı mı?** Hoca bunun çok kritik bir soru olduğunu söyler: sistemi iyi temsil etmeyen örnekler kullanırsanız başarıyı düşürebilir, sistemi doğrudan hedeften uzaklaştırabilirsiniz.
- **Simülasyonla veri üretilip kullanılabilir mi?** Eskiden kredi kartı sahtekarlığı ya da ağ saldırısı gibi konularda üretilen sahte veri kullanıldığında başarı düşüyordu. Şimdi derin öğrenmede gerçekçi sahte veri üreten modeller var ve bunlar sayesinde örneği az olan sınıfların örnek sayısı artırılabiliyor.

## 8. Eğitim, Doğrulama ve Test Verisi

Toplanan veri mutlaka üçe bölünmelidir.

**Eğitim verisi (training data).** Sistem bu veriyle eğitilir.

**Doğrulama verisi (validation data).** Hangi modelin daha başarılı olduğu bu veriyle ölçülür.

> **Hocanın vurgusu:** Başarı asla eğitim yapılan veriyle ölçülmez.

Eğitim verisiyle başarı ölçmek yalnız bir şey için anlamlıdır: sistemin ezberleyip ezberlemediğini anlamak. Öğrenme modelinin eğitim başarısı doğrulama başarısından yüksekse model ezberlemiş demektir. Örneğin eğitimde %100 başarı alıyorsunuz ama doğrulamada başarı %80'in üzerine çıkmıyorsa, geri dönüp neler olduğuna bakmanız gerekir.

> **Ek bilgi (derste anlatılmadı):** Modelin eğitim verisini ezberleyip yeni veride başarısının düşmesine **aşırı öğrenme (overfitting)** denir. Eğitim ve doğrulama başarısı arasındaki büyük fark bunun tipik işaretidir.

**Test verisi (test data).** Doğrulama verisiyle en iyi model seçilir. Örneğin karar ağacının en başarılı sonucu verdiğine karar verdiniz, ağacı budadınız, başka ayarlar yaptınız ve şu anda elinizde en iyi model var. Ondan sonra test verisiyle, **hiçbir şeyi değiştirmeden**, başarı ölçülür. Artık model hazırdır: ne parametrelerle oynayabilirsiniz ne de başka bir şey yapabilirsiniz. Modelin bu hâliyle başarısı ölçülür ve sonra sistem kullanıma açılır.

| Veri | Ne için kullanılır? |
| :--- | :--- |
| Eğitim | Modeli eğitmek. Bu veriyle ölçülen başarı yalnız ezberleme kontrolü içindir. |
| Doğrulama | Modeller ve parametreler arasından en başarılısını seçmek. |
| Test | Seçilen modelin son başarısını hiçbir şeyi değiştirmeden ölçmek. |

Hoca verinin bu üç gruba nasıl ayrılacağının dönem içinde işleneceğini söyler.

## 9. Veri Toplamadaki Sorunlar: Eksik Veri ve Dengesiz Sınıflar

Hoca bu bölümdeki konuların çoğunun ilerleyen derslerde ayrıntılı işleneceğini, şimdilik ana yapının akılda şekillenmesi için bütün aşamaları genel olarak anlattığını belirtir.

### 9.1 Eksik Veri

Eksik verisi olan kayıtlar için seçenekler:

- **Çok örnek varsa eksik kayıtlar kullanılmaz.** Bir sıkıntı yoktur, atılır.
- **Az örnek varsa benzer örneklerin değerleriyle doldurulur.** Önce eksik örneğe benzeyen örnekler bulunur. Sonra bu örneklerde o özellik için en çok kullanılan değer boşluğa konur. Hoca benzerliğin olabildiğince mantıklı kurulması gerektiğini söyler.
- **Aynı sınıftaki diğer örneklerin ortalamasıyla doldurmak.** Hoca bu yaklaşımı pek beğenmediğini söyler.
- **O özelliği hiç kullanmamak.** Eksik örnek çoksa böyle bir yola gidilebilir, ama hoca bunun doğru bir yaklaşım olmadığını belirtir: o özellik faydalı olabilir ve kullanmamak sıkıntı yaratabilir.
- **Özelliğin ortalaması ya da medyanı ile doldurmak.**

Hoca slaytta bazı özelliklerin (ör. ülke, güvenilirlik) "not available" (mevcut değil) olduğu örnek bir tablo gösterir.

### 9.2 Dengesiz Sınıf Dağılımı

Veri toplamadaki önemli sorunlardan biri, örneklerin sınıflara dengesiz dağılmasıdır.

- **Tıbbi problemler:** Hastalık nadir görülüyorsa hasta verisi az olur. Ya da yalnız hasta verisi elde edilebildiği için kontrol grubu olan sağlıklı insanların verisini toplamak zor olabilir.
- **Ağ saldırısı:** Normal durum verisi çok fazladır, saldırı ise az olduğu için saldırı verisi toplamak zordur.

Eski çalışmaların çoğunda bunun için bir şey yapılmaz, bir sınıfta az, diğerinde çok örnekle model kurulurdu. Bugün kullanılan çözümler:

1. **Az örnekli sınıf için gerçekçi sahte örnek üretmek.** Derin öğrenmede çok kullanılan **çekişmeli üretici ağlar (Generative Adversarial Network, GAN)** gerçeğe çok benzer sahte örnekler üretebilir.
2. **Örnekleri kopyalayarak çoğaltmak.** Eski bir yaklaşımdır. Örneğin görüntü tanımada aynı görüntü biraz sağa döndürülür, bir kısmı kesilir ve böylece çoğaltılır.
3. **Çok örnekli sınıfın örneklerini azaltarak denge sağlamak.**

> **Ek bilgi (derste anlatılmadı):** GAN'da iki ağ birlikte eğitilir: biri sahte örnek üretir (üretici), diğeri örneğin gerçek mi sahte mi olduğunu ayırt etmeye çalışır (ayırt edici). İkisi birbirine karşı yarıştıkça üreticinin örnekleri gerçeğe yaklaşır. Görüntüyü döndürme, kesme gibi işlemlerle örnek çoğaltmaya ise **veri artırma (data augmentation)** denir.

**Azaltma nasıl yapılır?** Kredi kartı sahtekarlığında örneğin aynı gün için 1 milyon normal örneğe karşılık 1000 sahte örnek olur. Simülasyonla örnek üreterek sınıf dengesini sağlayamıyorsanız, bir sınıfta 1 milyon, diğerinde 1000 örnek olması modelin zorlanmasına yol açar.

> **Hocanın vurgusu:** Çok örnekli sınıfın örnekleri kademe kademe azaltılarak farklı modeller kurulmalıdır. Örneğin 1 milyon normal / 1000 sahte, 500 bin normal / 1000 sahte gibi. Eğitim örneklerinde normal örneklerin sahte örneklere oranı ne olduğunda en başarılı modelin elde edildiği bulunur ve o kullanılır.

Hoca, BKM için bir TÜBİTAK projesi çerçevesinde yaptıkları kredi kartı sahtekarlığı tespit sisteminde bu oranın **5'e 1** çıktığını anlatır: 5 normal örneğe 1 sahte örnek olduğunda en iyi eğitilmiş model elde edilmiştir.

**Örnek 1 (azaltılacak örneklerin seçimi).** 1 milyon normal ve 1000 sahte örnek var; 5:1 oranı için 1000 sahteye 5000 normal örnek gerekiyor. Yeni problem şudur: 1 milyon normal örnekten 5000 tanesi nasıl seçilecek?

- Rastgele seçilebilir. Ama rastgele seçerken birbirine benzer örnekleri seçiyor olabilirsiniz.
- Daha mantıklı yol, örnekleri önce benzerliklerine göre gruplamak, sonra her gruptan eşit sayıda seçmektir. 10 grup varsa her gruptan 500 örnek seçilir: $10 \times 500 = 5000$ örnek.
- Hoca bunun hassas bir hesap olduğunu, bu yola ancak örnek sayınız çok değilse başvurulması gerektiğini söyler. 1 milyon örnek varsa rastgele seçilen 5000 örnek zaten yeterince gelişigüzel olur, bir tarafa yığılmaz. Hoca kendi denemelerinde de çok örnekte böyle bir yığılma olmadığını gördüklerini belirtir.

## 10. Veri Tipleri

Hoca üç tür veri tipi tanımlar ve bu konuya derste bir daha dönmeyeceğini tahmin ettiğini söyler.

**Kullanılmayan (useless) veri.** Sayı da olabilir, kategorik de olabilir; ama öğrenmede işleme alınmaması gereken özelliklerdir. Örneğin kredi kartı sahtekarlığı tespitinde kimlik numarası ya da ad soyad. Bunların bir önemi yoktur. Zaten veriden kimlik anlaşılması istenmediği için bu bilgiler size kodlanmış olarak verilir.

**Sıralı (ordinal) veri.** Aralarında ilişki kurulabilen, ölçülebilen ve sıralanabilen değerlerdir. Tam sayı olmaları gerekmez, kesirli sayı da olabilirler. Örneğin kişilerin yaşları arasında anlamlı bir bağlantı vardır: 43 yaş ile 75 yaş arasındaki mesafe anlamlı bir bilgidir. 70 kilo ile 90 kilo arasındaki fark da ölçülebilir bir ilişkidir.

Ama bir değerin sayı olması onu sıralı yapmaz. Türkiye'deki plaka kodlarını düşünelim: 34 İstanbul'dur, 36 Kars'tır. 36'dan 34'ü çıkarıp "Kars ile İstanbul arasındaki mesafe 2'dir" diyemeyiz; bunun bir anlamı yoktur. Bu yüzden plaka numarası sıralı veri olarak kullanılamaz.

**Kategorik (nominal) veri.** Birbirinden farklı olan, ama birbirlerine göre ölçümsel bir karşılaştırma ya da üstünlük değerlendirmesi yapılamayan değerlerdir. Örneğin yaşanılan şehir: İstanbul ve Ankara'nın hava şartları farklıdır, ama bu iki değer arasında bir ölçme yapılamaz. Kredi kartı harcamasının ATM'den ya da internetten yapılmış olması da kategoriktir; bunları birbirinden çıkarmak gibi bir şansınız yoktur.

Kullanılacak örneklerin özelliklerine bakıp her özelliğin sıralı mı kategorik mi olduğu belirlenmelidir. Buna göre kullanılacak yöntemler seçilir ya da özelliklerin dönüştürülmesi gerekebilir.

## 11. Ön İşleme ve Normalizasyon

### 11.1 Ön İşleme

Ön işlemede amaç, veriyi kullanmadan önce daha iyi şartlara getirmek, gereksiz bilgiden arındırmak ve bilgi kalitesini artırmaktır.

**Gereksiz bilgiyi çıkarmak.** Belge işlemede **durak kelimeler (stop words)** mutlaka çıkarılır: "and", "or", "if" gibi her belgede karşılaşılabilecek kelimeler. Bunlar sınıflar arasındaki benzerliği gereksiz yere artırır. Yüz tanımada renkli değil gri seviyeli görüntüyle çalışılır, çünkü orada renk bilgisinin hiçbir önemi yoktur.

**İyileştirme.** Gerekiyorsa veri iyileştirilir. Karanlık bir görüntüye histogram işlemi uygulanarak görüntü daha aydınlık, kontrastlı ve daha dengeli hâle getirilebilir. Ses tanımada sesin seviyesi artırılabilir ya da parazitli bir ses parazitten temizlenebilir.

**Hatalı ve eksik verinin düzeltilmesi.** Bir özelliğin yanlış ya da eksik olması durumunda dönüştürülmesi ve değiştirilmesi de ön işleme kategorisine girer.

### 11.2 Normalizasyon Neden Gerekir?

Hoca normalizasyonu mutlaka dikkat edilmesi gereken önemli bir ön işlem olarak tanımlar. Benzerlik ölçerken ilk yapılan şeylerden biri farklara bakarak mesafe ölçmektir: Öklid uzaklığı (Euclidean distance), Manhattan uzaklığı (Manhattan distance) gibi. Bunlar ilerleyen derslerde işlenecektir.

Sorun şudur: farklı özelliklerde aynı sayısal farkın etkisi aynı değildir. İnsan kilosunda 100 kilo ile 98 kilo arasındaki 2 kiloluk fark çok büyük bir fark değildir. Ama altın ölçüyorsanız, 1 kilo ile 3 kilo arasındaki 2 kiloluk fark çok büyüktür; altında gramlar arasındaki fark bile önemlidir. Buradaki "2" ile oradaki "2" aynı etkide değildir.

Yapılması gereken şey, normalizasyonla değerleri belli bir aralığa çekerek özelliklerin birbirlerine göre daha eşit şartlarda olmasını sağlamaktır.

### 11.3 Min-Max Normalizasyonu

Değerleri $[0,1]$ aralığına çekmek için önce eldeki örneklerdeki en küçük ve en büyük değer bulunur. Sonra en küçük değer 0, en büyük değer 1 olacak şekilde dönüşüm uygulanır. $i$. örneğin yeni değeri:

$$x_i' = \frac{x_i - x_{min}}{x_{max} - x_{min}}$$

> **Ek bilgi (derste anlatılmadı):** Küçük bir sayısal örnek: Bir özellikte en küçük değer 40, en büyük değer 90 olsun. 65 değeri için $x' = \frac{65-40}{90-40} = \frac{25}{50} = 0{,}5$ olur. 40 değeri 0'a, 90 değeri 1'e karşılık gelir.

**$[-1,1]$ aralığı.** Merkezin sıfır olması isteniyorsa değerler $-1$ ile $+1$ arasına çekilir.

<!-- BELİRSİZ: Hoca [-1,1] dönüşümünün bağıntısını slayttan gösteriyor, sözlü okumuyor ("şu bağıntıyla"). Aşağıdaki formül standart [-1,1] ölçeklemesidir, slayttaki ifadeyle birebir aynı olduğu doğrulanamadı. -->

$$x_i' = 2\,\frac{x_i - x_{min}}{x_{max} - x_{min}} - 1$$

Hoca genelde $[0,1]$ normalizasyonunun kullanıldığını söyler.

**Belli sınırlar arasında normalizasyon.** Bazı çalışmalarda istenen bir aralığa normalizasyon yapılır. Görüntü işlemede bu çok yapılır: gri seviyenin en büyük değeri 255 ise değerler $[0,255]$ aralığına çekilir, yani en büyük değer 255, en küçük değer 0 olur. Genel hâli:

$$x_i' = \frac{x_i - x_{min}}{x_{max} - x_{min}}\,(yeni_{max} - yeni_{min}) + yeni_{min}$$

### 11.4 Z-Skor Normalizasyonu (Standartlaştırma)

Verinin dağılımına göre bir normalizasyon yapmak istenirse genelde **Z-skor normalizasyonu (Z-score normalization)** kullanılır. Hoca bunun aslında normalizasyon değil **standartlaştırma (standardization)** olarak adlandırıldığını söyler. Örnek değerinden verinin ortalaması çıkarılır ve sonuç standart sapmaya bölünür:

$$z_i = \frac{x_i - \mu}{\sigma}$$

Burada $\mu$ verinin ortalaması, $\sigma$ standart sapmasıdır.

Bu yöntem veri **Gauss (normal) dağılımlıysa** iyi sonuç verir. Veri düzgün (uniform) dağılmışsa her değerden yaklaşık eşit miktarda vardır. Gerçek hayattaki dağılımlar ise çoğunlukla Gauss dağılımıdır. Hoca Türkiye'deki insanların boylarını örnek verir: çoğunluk orta boyludur; çok az kısa ve çok az uzun insan vardır. Kadınlarda boyların çoğu 1,55-1,65 m arasındadır; çok azı 1,45-1,50 m ya da 1,80 m ve üzeridir. Böyle bir veride normalizasyon yerine standartlaştırma yapmak daha doğrudur.

<!-- BELİRSİZ: Hoca z-skorun amacını "daha uniform dağılmış bir şekilde verinizi örneklemek, bir tarafa yığılmayı engellemek" olarak anlatıyor. Z-skor dağılımın şeklini değiştirmez, yalnız ortalamayı 0 ve standart sapmayı 1 yapar; bu ifade altyazıda tam anlaşılmıyor. -->

## 12. Varsayımlar

Problemi çözmek için bazı varsayımlarda bulunmak gerekir. Hocaya göre bütün problemleri tek bir projede çözmeye odaklanmak doğru bir yaklaşım değildir. Genellikle bir parçası bir yerde, diğer parçası başka bir yerde çözülebilecek büyüklükte problemlerle uğraşılır.

Hocanın örnekleri:

- **Tavsiye sistemi.** "Yalnız iki aydan uzun süredir film izleyen kişilere öneride bulunacağım" denebilir. Netflix'e yeni üye olmuş birine nasıl öneri yapılacağı **soğuk başlangıç (cold start)** denen bambaşka bir problemdir ve genel tavsiye sistemiyle karıştırılmamalıdır.
- **Kredi kartı sahtekarlığı.** Model önce internet üzerinden alışveriş yapanlar için kurulabilir. Başarılı sonuç alındıktan sonra, ATM harcamaları tamamen farklıysa onlar için başka bir model kurulabilir. Aynı model iki probleme de çözüm oluyorsa sıkıntı yoktur.
- **Hedef tespiti.** Gece hedef tespiti için gece kamerası gerekir, ama gündüz bunu kullanmak istemezsiniz (ör. gereksiz enerji harcadığı için). O zaman "bu projede yalnız gündüz görüntüleri için çözüm üreteceğim" dersiniz.

Varsayımlar, kurulacak modelin hangi problemlere çözüm üreteceğine dair önceden verilen kararlardır. Avantajı da şudur: her işe çözüm veren tek bir sistem yerine, ana konunun içindeki farklı problemlere ayrı ayrı çözüm üretmek bazen daha etkili sonuçlar verir.

## 13. Özellikler ve Model Seçimi

### 13.1 Özellik Vektörü

Hoca bu konuların ayrıca işleneceğini söyleyerek kısaca geçer. Özellikler nesnenin ayırt edici karakteristikleri olmalıdır. Bir örneğin bütün özellikleri bir **özellik vektörü (feature vector)** oluşturur.

Hoca slaytta 2 özellikle 3 sınıfı ayıran bir model gösterir. Özellikler fena değildir, ama iki sınıf biraz karışmaktadır ve bunları ayırmak zor olacaktır. Daha iyi olması için sınıflar arası farklılığı ve sınıf içi benzerliği artıracak özellikler bulunmalıdır. Slaytta iyi ve kötü özellik örnekleri de yan yana gösterilir.

<!-- BELİRSİZ: İyi ve kötü özellik örneklerinin görselleri slayttadır; altyazıdan ayrıntıları anlaşılmıyor. -->

Özellik seçerken iki şeye bakılır:

- Özellik ayırt edici olmalıdır.
- Özelliğin elde edilmesi kolay ve kısa süreli olmalıdır. Bir yıl sonra elde edilebilecek bir özellik için sistemi bekletmek yerine, eldeki özelliklerle işin içinden çıkılıp çıkılamayacağına bakılmalıdır.

### 13.2 Hata Ölçütünün Seçimi

Model seçimi ve değerlendirmesinin nasıl yapılacağı ders içinde ayrıca işlenecektir. Farklı modeller arasından hatası en düşük olanı seçmek doğrudur. Ama "hatanın en düşük olması" ne demektir, bunu da bilmek gerekir.

Örneğin bir hastalık teşhisinde sizin için önemli olan, hasta olanları olabildiğince doğru bulmaktır. Kanser olmayan birine "kanser" demek (yanlış pozitif, false positive) kötüdür, ama asıl önemli olan kanser olan herkesi yakalayabilmektir, yani doğru pozitif (true positive) sayısının yüksek olmasıdır. Model belirlenirken hangi başarının sizin için daha önemli olduğuna dikkat edilmelidir.

> **Ek bilgi (derste anlatılmadı):** Gerçekte pozitif olanların ne kadarının doğru yakalandığını gösteren ölçüte **duyarlılık (recall, sensitivity)** denir: $\text{recall} = \frac{TP}{TP + FN}$. Hastalık teşhisinde hastaları kaçırmamak bu ölçütün yüksek olmasını istemek demektir. Başarı ölçütleri ilerleyen bir derste ayrıca işlenmektedir.

Hoca ders boyunca eğitmenli, eğitmensiz ve pekiştirmeli öğrenmenin ve öğrenme modeline gelene kadarki bütün işlem adımlarının işleneceğini söyler.

## 14. Derin Öğrenmeye Kısa Bakış

Dönemin sonunda derin öğrenmeye de bir giriş yapılacaktır. Bölümde ayrıca açılan bir derin öğrenme dersi vardır. Ama derin öğrenmenin temeli yapay sinir ağlarıdır ve bu dersin içinde yapay sinir ağları ve destek vektör makineleri zaten işlenecektir; devamında derin öğrenme de bir derste kısaca ele alınacaktır.

**Tarihçe.** Yapay sinir ağları 1940'lardan beri vardır; derin öğrenme ise 2012'de kullanılmaya başlanır. Yapay sinir ağları, insan beyninin çalışma prensibinin bir simülasyonu olarak ortaya çıkar. İnsan beyninde milyonlarca nöron birbiriyle iletişim hâlindedir ve paralel çalışabilir. Ama yapay sinir ağlarının ilk kullanıldığı yıllarda donanımlar yeterince iyi değildi. Bu yüzden problemler çok küçük ağlarla çözülüyordu ve bunlar aslında oldukça başarılıydı.

Hoca, 2012'de bir nesne tanıma yarışmasında derin öğrenmenin ilk kez kullanıldığını ve YouTube'daki 10 milyon etiketsiz resmin içinden 3 gün çalışan bir programla kedi yüzü öğrenen bir sistem yapıldığını anlatır. Hocaya göre bu sistem önceki sistemlerden %70 daha başarılı oldu ve dikkat çekti. Ardından Go oyunu oynayan bir program ve İngilizceden Çinceye gerçek zamanlı çeviri yapan bir uygulama yazıldı; sonra derin öğrenme yaygınlaştı.

> **Ders sonrası not:** Hoca iki ayrı 2012 olayını tek olay gibi anlatıyor. YouTube videolarından alınan 10 milyon etiketsiz kareden kedi yüzü öğrenen sistem, Google Brain ekibinin çalışmasıdır (Le ve ark., 2012). Aynı yıl ImageNet nesne tanıma yarışmasını derin bir evrişimli ağ olan AlexNet büyük farkla kazanmıştır. "%70 daha başarılı" oranı altyazıdaki ifadedir; iki çalışmadaki gerçek iyileşme oranları farklıdır. Go oyununu oynayan program DeepMind'ın AlphaGo'sudur (2016).

**Derin öğrenmenin başarısının sebebi.** Eski yöntemlerde veri artırıldığında başarı bir noktadan sonra iyileşmiyordu. Derin öğrenmede veri ne kadar artarsa performans da o kadar yükselir. Bunu çok katmanlı, çok nöronlu ve insan beynini daha gerçekçi simüle eden yapısı sağlar. Bunun hayata geçmesini de özellikle oyunlar için yaygınlaşan GPU'lu bilgisayarlar mümkün kıldı: donanımlar artık bu ağları gerçekleştirmeye yetecek kadar iyiydi.

**Dezavantajı.** Derin öğrenmeyle bir sistem eğitilirken bu kadar çok örnek için eğitimin bir hafta, bir ay, hatta iki ay sürdüğü olur.

> **Hocanın vurgusu:** Makine öğrenmesinin klasik yöntemleri size yetiyorsa, derin öğrenmenin performans sıkıntıları vardır. Şu an için klasik makine öğrenmesi yöntemleri hâlâ pek çok problemin çözümü için yeterlidir ve tercih edilebilir.

Hocanın öngörüsü şudur: derin öğrenmedeki performans sıkıntıları farklı çözümlerle giderilmeye başlandı. Önümüzdeki 5-10 yılda alan büyük olasılıkla yavaş yavaş tamamen derin öğrenmeye kayacaktır. Derin öğrenme bugün çoğunlukla yapay sinir ağlarından ve pekiştirmeli öğrenmeden yararlanıyor; zamanla diğer klasik yöntemlerin bir kısmının da derin öğrenme tarafına nasıl uyarlanabileceğine bakılacaktır. Hoca bu konuda iddialı olmadığını da ekler.

Ders sonundaki bir soruya cevap olarak hoca, derste uygulama (kod, araç üzerinde veri işleme) gösterilmeyeceğini, bunların ödevlerde öğrencilerin yapacağı işler olduğunu söyler. Anlatılan konuların ise teorik değil, doğrudan pratikte kullanılacak bilgiler olduğunu vurgular.

## Dersin Toparlaması

Bu derste makine öğrenmesinin neden gerektiği, kural tabanlı sistemlerin sınırları üzerinden anlatıldı: çok sayıda kural gerektiren ve her kuralın herkes için geçerli olmadığı problemlerde, sistemin örneklerden kendi kendine öğrenmesi gerekir. Makine öğrenmesinin yapay zeka, büyük veri, veri madenciliği, veri bilimi ve derin öğrenme ile ilişkisi kuruldu. Üç temel öğrenme türü (eğitmenli, eğitmensiz, pekiştirmeli) ve ara tür olan yarı eğitmenli öğrenme örneklerle tanıtıldı.

Dersin ikinci yarısında bir öğrenme sisteminin uçtan uca adımları ele alındı: problemi anlama ve yöntem seçme, verinin toplanabilir olduğundan emin olma, örnek çeşitliliği ve ana senaryolar, verinin eğitim-doğrulama-test olarak bölünmesi, eksik veri, dengesiz sınıflar, veri tipleri, ön işleme, normalizasyon, varsayımlar, özellik seçimi ve hata ölçütünün probleme göre seçimi. Hoca bu konuların çoğunun (mesafe ölçüleri, veri bölme yöntemleri, model seçimi ve başarı ölçütleri, yapay sinir ağları, destek vektör makineleri ve derin öğrenme) ilerleyen derslerde ayrıntılı işleneceğini belirtti.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
