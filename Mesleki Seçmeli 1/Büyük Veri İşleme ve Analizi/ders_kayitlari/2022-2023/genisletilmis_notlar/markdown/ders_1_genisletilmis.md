# Ders 1 Genişletilmiş Notu: Derse Giriş, Büyük Veri Kavramları ve Dersin İşleyişi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Amacı ve Kaynakları
- 2. Büyük Veri Nereden Geliyor?
- 3. Büyük Verinin Saklanması: Dağıtık Depolama
- 4. Bu Ders Aslında Veri Bilimi
- 5. Çıkarılan Örüntülerin Taşıması Gereken Nitelikler
- 6. Tanımlayıcı ve Tahmine Dayalı Yöntemler
- 7. Veri Gerçek Hayatı Yansıtmalı
- 8. Büyük Verinin Boyutları
- 9. Büyük Veri Sorguları ve İlişkisel Veritabanları
- 10. Dersin Kapsamı: Yöntemler, Problemler ve Uygulamalar
- 11. Soru-Cevap: Veri Neden Kopyalanır?

## 1. Dersin Amacı ve Kaynakları

Hoca dersin ilk bölümünü Türkçe, giriş anlatımını İngilizce yaptı. Bu tanıtım dersinden sonra dersin tamamının İngilizce işleneceğini söyledi.

Dersin üç hedefi var:

- Büyük veri işleme ve analizi tekniklerini öğrenmek.
- Bu teknikler için kullanılan algoritmaları öğrenmek.
- Bu algoritmaları bir problem üzerinde uygulamak. Bu yüzden ders bir dönem projesi (term project) içerir.

Hoca, öğrencilerin işlenecek konularla ilgili bir proje fikri bulmak için biraz "Google mühendisliği" yapmasını istedi: Öğreneceğimiz konularla nasıl bir proje yapılabilir, hangi veri setleri (data sets) üzerinde çalışılabilir?

### 1.1 Ders Kitabı: Mining of Massive Datasets

Derste *Mining of Massive Datasets* (MMDS) kitabı kullanılıyor. Kitabın farklı sürümleri var. Hoca en son sürümün büyük olasılıkla üçüncü sürüm (third edition) olduğunu söyledi ("sanırım" diyerek). Kitabın bütün bölümlerini (chapter) yazarları internette yayımlamış. Bu yüzden kitabı satın almaya ya da kütüphaneye gitmeye gerek yok.

Kitabın sitesinde ayrıca şunlar bulunuyor:

- Yazarların hazırladığı PowerPoint slaytları.
- Yazarların bazı bölümler için hazırladığı YouTube videoları.

Böylece ders içeriğine hem hocanın derslerinden hem de kitabın yazarlarının videolarından ulaşılabilir.

Hocaya göre bu ders, Stanford Üniversitesi'nde aynı adla uzun süredir verilen "Mining Massive Data Sets" dersinin içeriğini temel alıyor. Hoca aynı içeriği "Big Data Processing and Analysis" dersi olarak vermeye çalışıyor. Kitaptaki bölümlerin olabildiğince fazlası dönem içinde işlenecek. Gelecek hafta birinci ve ikinci bölümle birlikte başlanacak, sonra bölümler sırayla gidecek.

<!-- BELİRSİZ: 00:18:02'de Stanford dersinin adı altyazıda bozuk ("Mining Massive Data Sessizliğe geçen"). Dersin adı bağlamdan kuruldu. -->

> **Ek bilgi (derste anlatılmadı):** Kitabın yazarları büyük olasılıkla Jure Leskovec, Anand Rajaraman ve Jeffrey D. Ullman'dır. Stanford'daki karşılık gelen ders büyük olasılıkla CS246 "Mining Massive Data Sets" dersidir.

## 2. Büyük Veri Nereden Geliyor?

Hoca İngilizce anlatıma, elimizdeki veri miktarının çok hızlı büyüdüğünü söyleyerek başladı. Bu veri farklı kaynaklardan geliyor:

- **Akış (streaming) uygulamaları:** Akış uygulamalarını kullanmaya başladığımızdan beri veri miktarı çok sert biçimde arttı.
- **Müzik verisi.**
- **Cep telefonu kullanımı** sonucu biriken veri.
- **Sosyal ağ siteleri** kullanımından doğan veri.
- **Elektronik bilim (e-science)** ile ilgili veri.
- **Dijital kütüphaneler:** Bunlarda çok büyük miktarda veri bulunur.

Amaç, böyle büyük ölçekli veriyi işleyip analiz etmemize yardım edecek algoritmalar ve teknikler bulmaktır. Yıllar içinde biriken bu veriden bilgi (knowledge) çıkarmak isteriz. Böyle bir veriden bilgi çıkarabilen araçlarımız olduğunda bu bilgi farklı şekillerde kullanılabilir:

- Hayatımızı kolaylaştırmak için.
- Gelecek hakkında tahmin (prediction) yapmak için.

Bunun için verinin bir yerde saklanması, yönetilmesi ve analiz edilmesi gerekir.

## 3. Büyük Verinin Saklanması: Dağıtık Depolama

Söz konusu veri çok büyük olduğu için tek bir bilgisayarda saklanamaz. Bu yüzden dağıtık veritabanları (distributed databases) ya da çok sayıda sunucu barındıran veri merkezleri (data centers) kullanılır. Veri bu yerlerde saklanır.

### 3.1 Dağıtık Depolamayı Yönetmek Ne Demek?

Veri merkezlerinde ve dağıtık depolama sistemlerinde saklanan verinin yönetilmesi de gerekir. Hoca bunu şöyle açıkladı:

- Bir veri merkezine bir dosya yazdığınızda, o dosya kopyalama (replication) için birden fazla sunucuda saklanır.
- Dağıtık veri yönetim sistemi, o dosyanın kopyalarının nerede olduğunu bulabilmelidir.
- Dosya çok büyükse küçük parçalara bölünür. Bu küçük parçalar birden fazla sunucuda saklanır.
- Kullanıcı o dosyayı istediğinde sistem bütün parçaları depolamadan çeker, birleştirir ve dosyayı kullanıcıya bütün olarak verir.

Yani yalnızca aynı dosyanın kopyası tutulmaz, dosya ayrıca küçük parçalara da bölünerek saklanır. Bu yüzden büyük ölçekli dağıtık depolama sistemlerinde verinin saklanması ve yönetimi hem çok önemli hem de karmaşıktır.

### 3.2 Parçalar Dağınıkken Analiz

Asıl zorluk şudur: Verinin parçaları birden fazla sunucuda dururken ve dosyaların kopyaları birden fazla sunucuya dağılmışken bu veriyi analiz edebilmek isteriz. Bu derste öğrenilecek teknikler ve algoritmalar tam olarak bu analiz içindir.

## 4. Bu Ders Aslında Veri Bilimi

Hocaya göre bu derste öğrenilecek şey temelde veri bilimidir (data science). Veriyi analiz edip ondan bilgi çıkarmaya yarayan algoritmalar öğrenilecek. Ama bunlar özel algoritmalardır: Çok sayıda dağıtık veri deposu üzerinde çalışabilen, "büyük veri algoritmaları" (big data algorithms) dediğimiz algoritmalar.

Hoca ardından, bilgi teknolojileri pazarında veri bilimine ve veri bilimcilere olan talebi gösteren bir slayt açtı. Slaytın biraz eski olduğunu, ama talebin hâlâ büyüdüğünü düşündüğünü söyledi. Bu talep her yıl artıyor. Büyük veriyi analiz etmeye yarayan araçları, teknikleri ve algoritmaları bilen, veri bilimi hakkında bilgisi olan kişiler bu pazarda iyi işler bulabiliyor.

<!-- BELİRSİZ: Talep slaytındaki sayılar altyazıda okunmadı; hoca sayı vermedi. -->

## 5. Çıkarılan Örüntülerin Taşıması Gereken Nitelikler

Bu derste şu varsayımla çalışılacak: Çok fazla veri var ve bu veri tek bir sunucuda değil, birden fazla sunucuda saklanıyor. Bu veriden çıkarılabilecek örüntüler (patterns) ve modeller öğrenilecek. Bu örüntülerden ve modellerden beklenenler:

- **Geçerli (valid) olmalı:** Çıkarılan örüntüler ve kurulan modeller belirli bir kesinlik (certainty) taşımalıdır.
- **Faydalı (useful) olmalı:** Bütün bu algoritmalar faydalı bilgi çıkarmak için uygulanır. İnsanlar bu bilgiyi kullanacak ve buna göre harekete geçecek.
- **Beklenmedik durumları yakalamalı:** Bu teknikler beklenmedik durumları (unexpected situations) ortaya çıkarmak için de öğrenilir.
- **Anlaşılabilir olmalı:** Algoritmalar anlaşılamayacak kadar karmaşıksa, nasıl çalıştıklarını açıklamanın başka yollarını bulmak gerekir. Ancak böylece insanlar bu tekniklere güvenebilir ve sonuçlarına göre harekete geçebilir.

<!-- BELİRSİZ: 00:34:24-00:35:24 arası altyazı döngüye girmiş ("bir şekilde" tekrarı). Bu arada anlatılan nitelik(ler) okunamadı; "anlaşılabilirlik" maddesi 00:35:24'teki cümlenin devamından kuruldu. -->

## 6. Tanımlayıcı ve Tahmine Dayalı Yöntemler

Derste öğrenilecek algoritmalar iki ana kategoriye ayrılır: tanımlayıcı yöntemler (descriptive techniques) ve tahmine dayalı yöntemler (predictive techniques).

### 6.1 Tanımlayıcı Yöntemler

Tanımlayıcı yöntemler, veriyi tarif eden örüntülerin nasıl çıkarılacağıyla ilgilidir. Çıkarılan örüntüler bize veri hakkında daha fazla şey söylemelidir.

Hocanın örneği istatistikti. Size bir tamsayı dizisi (array of integers) verilse ve bu tamsayılar hakkında tanımlayıcı bilgi istense şunları verebilirsiniz:

- Ortalama (average).
- Standart sapma (standard deviation).
- En büyük (maximum) ve en küçük (minimum) değer.

Bunların hepsi tanımlayıcı bilgidir. O tamsayı dizisi hakkında bize bir şey söyler. Başka tanımlayıcı yöntemler de vardır. Derste bu tanımlayıcı yöntemlerin, birden fazla sunucuya dağılmış büyük ölçekli veriye nasıl uygulanacağı öğrenilecek.

### 6.2 Tahmine Dayalı Yöntemler

İkinci kategori tahmine dayalı yöntemlerdir. Burada veriden model çıkarmak ve bu modelleri gelecek hakkında tahmin yapmak için kullanmak öğrenilecek. Elimizde geçmişte olmuş olaylara ait veri olacak. Bu veriyi analiz edip model kuran algoritmalar ve yöntemler olacak. Sonra bu modellerle geleceğe dair tahmin yapılacak.

Tahmine dayalı yöntemlerin kullanım alanları çoktur. Hocanın saydıkları:

- Öneri (recommendation).
- Tahmin, örneğin hava durumu tahmini (weather forecast).
- Finansal veri tahmini.

## 7. Veri Gerçek Hayatı Yansıtmalı

Hoca, üzerinde çalışılan verinin niteliğinin önemini vurguladı. Veri gerçek hayattan geliyorsa, gerçek hayatta olanlara dair bir iç görü (insight) taşır. Bu durumda veride öğrenilecek bir şey varsa, tanımlayıcı ya da tahmine dayalı tekniklerle faydalı bilgi çıkarılabilir.

Ama veri gerçek hayatta olanı düzgün biçimde yakalamıyorsa, çıkarılan örüntüler ve bilgi anlamsız olur. Bu yüzden herhangi bir veri bilimi çalışmasına başlamadan önce şunlardan emin olunmalıdır:

- Veri, içinde gerçekten bir bilgi olduğunu söyleyebileceğimiz bir alandan gelmelidir. Çünkü gerçek hayatta olanı yakalar.
- Veri, zaman içinde olanları yakalayacak kadar büyük olmalıdır. Hem zaman açısından uzun hem de boyut açısından büyük olmalıdır.

> **Hocanın vurgusu:** Veri yapay olarak üretilmişse (synthetically generated), ondan çıkarılan bilginin anlamsız olabileceğinden şüphelenmelisiniz.

Hoca slayttaki bir örneği atladı.

## 8. Büyük Verinin Boyutları

Hoca, veriyle uğraşırken farklı boyutlar (dimensions) olduğunu söyledi ve bunları sırayla anlattı.

### 8.1 Zorluklar

Birinci boyut zorluklardır (challenges):

- **Ölçeklenebilirlik (scalability):** Veri çok sayıda sunucuya dağıtılmalıdır ki analiz edilmek istendiğinde hızlı ve verimli analiz edilebilsin.
- **Akış (streaming) verisi:** Büyük veri sisteme sürekli olarak gelebilir. Hocanın örneği sismik sinyal verisiydi. Deprem bölgesinden sismik veriyi sürekli toplayan sensörler vardır. Bir artçı deprem (aftershock) olup olmadığını anlamak için bu verinin sürekli analiz edilmesi gerekir.
- **Bağlam (context):** Verinin üretildiği bağlam, yani zaman ve yer de önemlidir ve kaydedilmelidir.
- **Veri kalitesi (quality):** Örneğin veriyi üreten sensörlerin düzgün çalışıp çalışmadığı.
- **Verinin kullanımı (usage):** Bu da önemlidir. Derste ağırlıklı olarak veriyi analiz edip ondan bilgi çıkaran algoritmalara odaklanılacak.

### 8.2 Veri Türleri (Modality)

Veri farklı türlerde (modalities) ve biçimlerde olabilir:

- Yapılandırılmış (structured) veri.
- Sosyal ağ verisi.
- Metin.
- Çoklu ortam (multimedia) verisi: video, resim, ses dosyaları.
- Sinyal verisi.

Sistem, farklı biçimlerde gelen veriyi işleyebilmelidir.

### 8.3 Kapsamlı Bir Büyük Veri Sisteminin İşlevleri

Kapsamlı bir büyük veri sisteminde farklı veri işleçleri (operators) bulunmalıdır. Sistem şunları yapabilmelidir:

- Veriyi toplamak (collect).
- Veriyi analize hazırlamak (prepare).
- Veriyi temsil etmek (represent).
- Model çıkarmak ve bu modellerle akıl yürütme (reasoning) yapmak.
- Veriyi görselleştirmek (visualize).

Hocaya göre bunların her biri, büyük veriyle uğraşırken üzerinde çalışılabilecek ayrı bir alt alandır.

## 9. Büyük Veri Sorguları ve İlişkisel Veritabanları

Bu derste üzerinde çalışılan veri büyük ölçekli veridir. Böyle bir veriye erişmek ve onu getirmek için basit sorgular kullanılır: `get` ve `put` sorguları. Aradığınız verinin kimliğini (ID) verirsiniz, sistem de o veriyi size getirir.

Burada operasyonel veritabanlarından söz edilmiyor. Bu yüzden SQL işlemleri yapılmaz. Ağırlıklı olarak NoSQL veritabanlarıyla çalışılır. Temelde dosyalar dağıtık dosya sistemine (distributed file system) yazılır.

İlişkisel veritabanlarında (relational databases) ise durum farklıdır:

| | Büyük veri (bu ders) | İlişkisel veritabanı |
|---|---|---|
| Veri ölçeği | Büyük ölçekli | Küçük ölçekli |
| Depolama | NoSQL veritabanları, dağıtık dosya sistemi | İlişkisel veritabanı |
| Sorgular | Basit `get` / `put` | SQL ile çoğunlukla karmaşık sorgular |

> **Ek bilgi (derste anlatılmadı):** `get`/`put` arayüzü anahtar-değer (key-value) depolarının tipik arayüzüdür: `put(anahtar, değer)` veriyi yazar, `get(anahtar)` anahtara karşılık gelen değeri getirir. Birleştirme (join) gibi karmaşık işlemler bu arayüzde doğrudan yoktur.

### 9.1 Dersin Dayandığı Üç Alan

Derste makine öğrenmesi teknikleri kullanılacak, ama büyük veri için makine öğrenmesi. İstatistik de kullanılacak, ama büyük ölçekli veriye uygulanabilen istatistik yöntemleri ve denklemleri. Yani ders üç alanı kullanır:

- İstatistik.
- Makine öğrenmesi.
- Veritabanı sistemleri. Burada geleneksel ilişkisel veritabanlarına değil, veri depolama için dağıtık NoSQL veritabanlarına bakılacak.

<!-- BELİRSİZ: 00:48:26-00:48:54 arası altyazı bozuk ("bu dağılık"). Bu arada anlatılan kısım okunamadı. -->

## 10. Dersin Kapsamı: Yöntemler, Problemler ve Uygulamalar

### 10.1 Öğrenilecek Teknikler

- Etiketli veri (labeled data) üzerinde, büyük veri için tasarlanmış denetimli öğrenme (supervised learning) algoritmaları.
- MapReduce.
- Akış verisi (streaming data) için farklı algoritmalar.
- Veriyi yalnızca tek bir bellekte değil, birden fazla makinede saklanmışken de işleyebilen algoritmalar.

### 10.2 Gerçek Dünya Problemleri

Bu tekniklerle çözülecek problemlerin hepsi gerçek dünyadan geliyor. Slayttaki örnekler:

- **Öneri sistemleri (recommender systems):** E-ticaret siteleri kullanıyor.
- **Pazar sepeti analizi (market basket analysis):** Fiziksel marketler kullanıyor.
- **İstenmeyen içerik tespiti (spam detection):** Birçok farklı alanda görülen bir problem.
- **Kopya belge tespiti (duplicate document detection):** Bu da birçok alanda görülüyor.

Hoca bunların yalnızca bazı örnekler olduğunu, başka problemlerin de işleneceğini söyledi.

### 10.3 Veri Türüne Göre Problemler

Slayttaki tablonun ilk sütunları farklı veri kategorilerini gösteriyordu. Her veri türünde farklı problemler var:

| Veri türü | Problemler |
|---|---|
| Yüksek boyutlu veri (high dimensional data) | Veriyi gruplama, yani kümeleme (clustering); yüksek boyutu az sayıda boyuta indirme, yani boyut indirgeme (dimensionality reduction) |
| Graf verisi (graph data) | Spam tespiti, topluluk tespiti (community detection), sıralama (ranking) |
| Sonsuz veri (infinite data) | Akışlar üzerinde sorgular (queries on streams), veri akışlarını filtreleme |

Slaytta bu problemleri çözmeye yarayan bazı makine öğrenmesi teknikleri de listelenmişti. Hoca bunların yalnızca bir kısmının slaytta olduğunu söyledi.

<!-- BELİRSİZ: Slayttaki tablonun diğer sütunları (makine öğrenmesi teknikleri ve uygulamalar) altyazıda tek tek okunmadı. -->

### 10.4 Uygulamalar

Bu tekniklerin sonucunda bazı uygulamalar kurulacak:

- Büyük veri üzerinde çalışabilen öneri sistemleri.
- İlişki kurallarını (association rules) kullanan karar destek sistemleri (decision support systems).
- Kopya belge tespitini kullanan karar destek sistemleri.

Hoca dersin sonunda, derse geç katılanlar için kitabı, kitap sitesini (bölümler, slaytlar, video dersler) ve ders sitesini tekrar hatırlattı. Derste işlenecek slaytlar ders sitesinde paylaşılmış. Her dersten önce slaytlara bakılabilir.

## 11. Soru-Cevap: Veri Neden Kopyalanır?

Ders sonunda chatten bir soru geldi.

**Soru:** Veri kopyalamaya (data replication) neden ihtiyaç duyarız? Güvenlik (security) için mi?

**Cevap:** Veri kopyalama çoğunlukla güvenlik için değil, erişilebilirlik (availability) için yapılır. Hoca Google Drive örneğini verdi. Google Drive'a bir dosya yüklediğinizde o dosyayı 10 gün sonra ya da bir ay sonra da görmek istersiniz. Yani dosyanın her zaman erişilebilir olmasını beklersiniz. Google Drive ve Dropbox gibi dağıtık depolama sistemlerinin kullanıcıyla anlaşması, dosyayı her zaman erişilebilir tutmaktır.

Bu erişilebilirliği sağlamak için sistemler veriyi kopyalar: Dosyanın birden fazla kopyasını yapar ve farklı fiziksel sunuculara koyar. Bu sunucuların büyük olasılıkla farklı konumlarda olması gerekir. Kopyalardan birini tutan sunucuya bir şey olursa Google Drive diğer kopyalara erişip dosyayı size sunabilir. Kopyalama olmasaydı ve Google Drive dosyanın tek kopyasını tutsaydı, o sunucuya bir şey olduğunda dosyaya erişmenin hiçbir yolu kalmazdı.

> **Hocanın vurgusu:** Kopyalama güvenlik için değil, erişilebilirlik sağlamak içindir. Neredeyse bütün dağıtık depolama sistemleri veri kopyalaması yapmak zorundadır.

> **Ek bilgi (derste anlatılmadı):** Hadoop'un dağıtık dosya sistemi HDFS'te bir dosya bloklara bölünür ve her blok varsayılan olarak büyük olasılıkla 3 kopya halinde farklı düğümlerde tutulur. Bu, Bölüm 3'te anlatılan "parçalama + kopyalama" düzeninin somut bir örneğidir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:36:35)

Size bir tamsayı dizisi verilse ve bu dizi hakkında tanımlayıcı (descriptive) bilgi istense neler verebilirsiniz?

**Çözüm (derste verildi):** Dizinin ortalaması, standart sapması, en büyük ve en küçük değeri. Bunların hepsi diziyi tarif eden tanımlayıcı bilgilerdir. Bu, tanımlayıcı yöntemlerin en basit örneğidir; derste bu tür yöntemlerin birden fazla sunucuya dağılmış veriye nasıl uygulanacağı öğrenilecek.

**Soru 2** (derste sözlü, 00:56:39)

Dağıtık depolama sistemlerinde veri kopyalaması (data replication) neden yapılır? Güvenlik için mi?

**Çözüm (derste verildi):** Hayır, çoğunlukla erişilebilirlik (availability) içindir. Dosyanın kopyaları farklı fiziksel sunuculara, mümkünse farklı konumlara konur. Bir sunucu bozulursa dosyaya diğer kopyadan erişilir. Tek kopya olsaydı o sunucu bozulunca dosyaya erişilemezdi.

## Dersin Toparlaması

Bu tanıtım dersinde büyük verinin nereden geldiği, neden tek bir bilgisayarda saklanamadığı ve dağıtık depolama sistemlerinde nasıl tutulduğu anlatıldı: Büyük dosyalar parçalara bölünür, parçalar ve kopyalar farklı sunuculara dağıtılır, yönetim sistemi bunların yerini bilir. Dersin asıl konusu, veri bu şekilde dağınık dururken onu analiz edebilen büyük veri algoritmalarıdır. Bu algoritmalar tanımlayıcı ve tahmine dayalı yöntemler olarak ikiye ayrılır. Çıkarılan örüntülerin geçerli, faydalı ve anlaşılabilir olması, verinin de gerçek hayatı yansıtacak kadar büyük ve gerçek olması gerekir.

Ders istatistik, makine öğrenmesi ve (NoSQL tabanlı) veritabanı sistemlerinin kesişiminde duruyor. Dönem boyunca MapReduce, akış verisi algoritmaları, yüksek boyutlu veri, graf verisi ve sonsuz veri üzerindeki problemler işlenecek. Gelecek hafta kitabın birinci ve ikinci bölümüyle başlanacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
