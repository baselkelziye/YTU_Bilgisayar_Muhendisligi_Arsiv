# Ders 1 Genişletilmiş Notu: Olasılık Kuramına Giriş, Örnek Uzay, Olaylar ve Olay İşlemleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin kapsamı, kaynakları ve öğrenme çıktıları
- 2. Olasılık ve istatistiğe giriş
- 3. Tarihsel bir not: el-Kindî ve frekans analizi
- 4. Olasılık teorisinin bilgisayar bilimindeki uygulamaları
- 5. Deney, sonuç ve örnek uzay
- 6. Olaylar ve kuvvet kümesi
- 7. Kesin olay ve imkânsız olay
- 8. Olaylar üzerinde işlemler
- 9. Ayrık ve bütüncül olaylar
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin kapsamı, kaynakları ve öğrenme çıktıları

Ders İngilizce anlatılıyor; hoca sunum kullanmıyor, tablete el yazısıyla yazarak ilerliyor. Ekrandaki başlıkta dersin kodu BLM2011 (eski kodu BLM1541), adı "Probability and Statistics" olarak geçiyor (ekrandan, 01:15:00). Hoca öğrencilerin de kendisiyle birlikte yazarak not tutmasını istiyor; yavaş yavaş, bastıra bastıra yazdığı için yazmadan izleyenin sıkılacağını, not tutanın dersi çok daha verimli işleyeceğini söylüyor.

### 1.1 Dersin amacı ve konuları

Dersin amacı, bilgisayar mühendisliği öğrencilerine olasılık ve istatistiği tanıtmaktır (ekrandan, 00:15:00). Ekranda yazılan konu listesi şöyledir:

- Kombinatorik ve küme teorisi
- Olasılık aksiyomları
- Koşullu olasılık
- Rastgele değişkenler (dağılımlar): kesikli rastgele değişkenler ve sürekli rastgele değişkenler
- Beklenen değer operatörü ve kullanımları: varyans, kovaryans, çarpıklık (skewness), basıklık (kurtosis); beklenen değer operatörüyle dağılımın momentlerinin bulunması
- Dağılımların parametre kestirimi: momentler yöntemi ve en çok olabilirlik (maximum likelihood) yöntemi
- Hipotez testleri: ortalama (mean) ve varyans üzerine hipotez testleri; z, t ve ki-kare ($\chi^2$) istatistikleri

Parametre kestirimini hoca şöyle açıkladı: derste kesikli ya da sürekli pek çok dağılım görülecek; bu dağılımların modellerinde bazı parametreler bulunur. Elimizdeki veriden bu parametrelerin değerleri bulunmaya çalışılır; örneğin veriden modelin ortalaması kestirilir. Bulunan değerler daha sonra analizlerde kullanılır.

Konuların yaklaşık sırası da anlatıldı: giriş ve olasılığın temelleri, rastgele değişkenler, beklenen değer ile varyans, kovaryans, basıklık ve çarpıklık, Bernoulli ve binom dağılımları, olasılık yoğunluk fonksiyonu, düzgün (uniform), üstel, gama ve normal (Gauss) dağılımlar, merkezi limit teoremi, parametre kestirimi, güven aralıkları, hipotez testleri, p-değerleri ve varyanslar üzerine çıkarım.

### 1.2 Kaynak kitaplar

Hoca ana kaynak olarak Michael Baron'un *Probability and Statistics for Computer Scientists* kitabını (CRC Press, 2007) gösterdi; ikinci kaynak olarak da Hossein Pishro-Nik'in *Introduction to Probability, Statistics and Random Processes* kitabını tanıttı ve bu kitabın çevrim içi erişilebilir olduğunu söyledi. <!-- BELİRSİZ: İkinci kitabın yayıncısı altyazıda "Kruppler Research" diye bozuk geçiyor; yazar adı da Whisper'da "Pişronik" olarak yazılmış. --> Öğrenciler hem kitaptaki ilgili bölümlerden hem de derste anlatılan bütün içerikten sorumludur.

### 1.3 Öğrenme çıktıları

Ekranda ders sonunda kazanılacak yetenekler sıralandı (ekrandan, 00:45:00). Ders sonunda öğrenci:

- Olasılığın öngörülemezliği (belirsizliği) modellemek için nasıl kullanılacağını anlayabilmeli.
- Sayma (frekanslar) ve çeşitli olasılık kurallarıyla olasılık hesaplayabilmeli.
- Merkezi limit teoremini (CLT) anlayıp uygulayabilmeli.
- Çeşitli rastgele modeller için ortalama, varyans, kovaryans ve korelasyon hesaplayabilmeli, modellerin parametrelerini örnek veriden kestirebilmeli.
- Veriyi histogram ve ampirik yoğunluk fonksiyonuyla gösterebilmeli.
- Güven aralıklarını anlamalı ve örneklere (veriye) dayalı istatistikleri hesaplamayı öğrenmeli.
- Hipotez testlerini anlamalı, ortalama ve varyans için bu testleri yapabilmeli.

> **Hocanın vurgusu:** Olasılık "bilim ve teknolojinin motorudur". Hoca, gelişmiş ülkelerde üniversitelerdeki en önemli derslerden birinin olasılık ve istatistik olduğunu, kuantum programlamanın ve yapay zekânın arkasındaki mantığın olasılık bilinmeden anlaşılamayacağını söyledi. Salgın döneminde de politikaların hesaplanan istatistiklere göre belirlendiğini örnek verdi. Program yazmanın tek başına mühendislik olmadığını; mühendislik problemlerini çözmek isteyenin olasılık ve istatistiği çok iyi öğrenmesi gerektiğini vurguladı.

## 2. Olasılık ve istatistiğe giriş

### 2.1 Tanım

Ekrandaki tanım şöyledir (ekrandan, 01:10:00): olasılık teorisi ve istatistik, belirsizlikle (uncertainty) başa çıkmak için geliştirilmiş matematik dallarıdır. Olasılık teorisi, deney ve veri analizi yoluyla yapılan istatistiksel çıkarım (statistical inference) biliminin temel araçlarını sağlar.

Hoca bu tanımı genişletti: olasılık, olasılığın kendisiyle ve rastgele olayların analiziyle ilgilenen matematik dalıdır. Olasılık teorisinin merkezi nesneleri rastgele değişkenler ve olaylardır; bunlar deterministik olmayan olayların ya da ölçülen niceliklerin matematiksel soyutlamalarıdır. Olasılık teorisi istatistiğin matematiksel temelidir; iyi bir istatistikçi olmak için önce olasılığı bilmek gerekir. Olasılık yöntemleri, yalnız durumlarının bir kısmı bilinen karmaşık sistemlerin betimlenmesinde de kullanılır; hoca burada kuantum bilgisayarları örnek verdi: bu bilgisayarlar için program geliştirirken C ya da Java gibi diller yetmez, kuantum mekaniğinin olasılıksal yapısını bilmek gerekir.

### 2.2 Rastgelelik nereden gelir: yazı-tura örneği

Rastgelelik ve belirsizlik günlük hayatta ve bilim, teknoloji, mühendislik gibi bütün disiplinlerde vardır. Olasılık teorisi, çevremizdeki rastgele olguları betimlemeye ve analiz etmeye yarayan matematiksel bir çerçevedir. Rastgele olgu, sonucu kesinlikle öngörülemeyen olay ya da deney demektir.

Hoca rastgeleliği en basit deneylerden biri olan hilesiz bir paranın atılmasıyla açıkladı. Paranın yazı mı tura mı geleceği pek çok etkene bağlıdır:

- Paranın hangi kuvvetle atıldığı
- Paranın başlangıçtaki yönü
- Parmak ile para arasındaki etki
- Havadaki türbülans
- Masa yüzeyinin pürüzsüzlüğü
- Havanın yoğunluğu

Bütün bu etkenleri bilseydik paranın yazı mı tura mı geleceğini kesin olarak söyleyebilirdik. Ama sonucu etkileyen etkenlerin sayısı neredeyse sonsuzdur ve biz bunların ancak bir kısmını ölçebiliriz. Bilgi eksik olduğu için atışın sonucunu öngöremeyiz ve sonuca rastgele deriz: bazen yazı, bazen tura gelir. Yani rastgelelik, sınırlı bilgiden doğar.

Öte yandan para atma ya da zar atma gibi tek tek olaylar çok sayıda etkenden etkilense de, çok sayıda tekrarda incelenebilen ve öngörülebilen belirli örüntüler ortaya çıkar. Bu örüntüleri anlatan iki temsilî matematiksel sonuç büyük sayılar yasası ve merkezi limit teoremidir.

## 3. Tarihsel bir not: el-Kindî ve frekans analizi

Hoca öğrencilere olasılık ve istatistiğin "babasının" kim olduğunu sordu; sonra el-Kindî'yi (Ebû Yûsuf Ya'kûb b. İshâk es-Sabbâh el-Kindî) tanıttı. Hocanın anlatımına göre el-Kindî Kûfe'de doğmuş, yaklaşık 801-873 yılları arasında yaşamış bir İslam bilginidir ve şifreli mesajları çözmek için olasılık ve istatistiği kullanmıştır. Ekranda el-Kindî'nin *On Deciphering Cryptographic Messages* el yazmasının ilk sayfası, kriptanalizde frekans analizinin bilinen en eski tarifi olarak gösterildi (ekrandan, 01:20:00). Ekrandaki açıklamada yöntem şöyle özetleniyor: şifreli mesajın dili biliniyorsa, aynı dilde yazılmış başka bir düz metin alınır ve harflerin kaç kez geçtiği sayılır. En sık geçen harf "birinci", sonraki "ikinci" diye sıralanır. Sonra şifreli metindeki semboller de sayılıp sıklığa göre sıralanır; en sık geçen sembol düz metindeki "birinci" harfe, ikinci en sık geçen sembol "ikinci" harfe çevrilir ve bu işlem bütün semboller için sürdürülür.

<!-- BELİRSİZ: 01:18:20-01:18:46 arasında hoca 0-9 rakamlarından ve el-Kindî'den söz ediyor; altyazı bozuk olduğu için bağlantı anlaşılamadı. -->

> **Ders sonrası not:** Hoca el-Kindî'yi olasılık ve istatistiğin babası olarak tanıttı. El-Kindî'nin frekans analizi, istatistiksel düşüncenin bilinen en erken uygulamalarından biridir; ancak olasılık kuramının matematiksel temelleri genelde büyük olasılıkla 17. yüzyılda Pascal ve Fermat'nın yazışmalarına dayandırılır.

## 4. Olasılık teorisinin bilgisayar bilimindeki uygulamaları

Ekranda olasılık teorisinin bilgisayar bilimi ve mühendisliğe uygulamaları şöyle sıralandı (ekrandan, 01:25:00):

- **Sistem güvenilirliğinin ve kalitesinin değerlendirilmesi.** Hoca, bilimsel makalelerde sistem kalitesinin olasılık teorisiyle değerlendirildiğini ve yeni teknolojiler geliştirmek için olasılığın iyi bilinmesi gerektiğini söyledi.
- **Ölçüm doğruluğunun yorumlanması.** Ölçüm yapılırken hatalar da yapılır; olasılık teorisiyle ölçümlerin ne kadar doğru olduğu yorumlanabilir.
- **Uygun kalite kontrollerinin sürdürülmesi.** Sistemin kalitesi olasılık araçlarıyla korunur.

Olasılık teorisinin amacı, bir deneyde ortaya çıkabilecek çeşitli sonuçların şanslarını ve olabilirliklerini (chances and likelihoods) anlamak için matematiksel bir yapı sağlamaktır (ekrandan, 01:30:00). Hoca bu cümlenin anahtar sözcüklerini vurguladı: bir **deney** yapılır ve bu deneyden **sonuçlar** elde edilir.

## 5. Deney, sonuç ve örnek uzay

### 5.1 Deneyin sonucu rastgeledir

Bir deney yapıldığını düşünelim. Deney bazen $a$, bazen $b$, bazen $c$, bazen $d$ sonucunu verir; sonra yine $a$, yine $b$ gelebilir. Burada $a, b, c, d$ deneyin olası sonuçlarıdır ve deneyin sonucu rastgeledir (ekrandan, 01:30:00). Örneğin deney beş kez yapılırsa sonuçlar $a, d, b, c, d$ olabilir. Sonuçların belirli bir sırayla gelmesi gerekmez ve bir sonuç birden fazla kez çıkabilir (bu örnekte $d$ iki kez geldi). Her sonucun ortaya çıkma olasılığı farklı olabilir.

### 5.2 Deney ve örnekler

Ekrandaki tanım (ekrandan, 01:35:00): **deney**, bir sonuç ya da gözlem veren tekrarlanabilir bir süreçtir. Derste verilen dört örnek:

- Örnek 1: Para atmak.
- Örnek 2: Zar atmak. Olası sonuçlar 1, 2, 3, 4, 5, 6'dır.
- Örnek 3: Bir bankadaki müşterilerin sayısını saymak. Hoca "#" işaretinin "sayı" anlamına geldiğini belirtti.
- Örnek 4: Bir bankaya gelen iki ardışık müşterinin geliş zamanları arasındaki süreyi ölçmek.

### 5.3 Sonuç ve örnek uzay

**Sonuç (outcome)**, bir deneyin temel (elementer) sonucudur. **Örnek uzay**, bir deneyin bütün olası sonuçlarının kümesidir; $\Omega$ ya da $S$ ile gösterilir (ekrandan, 01:40:00). Derste $\Omega$ kullanılacaktır.

Dört örneğin örnek uzayları (ekrandan, 01:40:00 ve 01:45:00):

$$\Omega_1=\{T, H\}=\{0,1\}$$

Burada $T$ yazı (tail), $H$ tura (head) demektir; iki sonuç 0 ve 1 ile de kodlanabilir.

$$\Omega_2=\{1,2,3,4,5,6\}$$

Ekranda önce zarın altı yüzü noktalarla çizildi, sonra sayılarla yazıldı.

$$\Omega_3=\{0,1,2,3,\dots\}$$

Müşteri sayısı negatif olmayan tamsayılardır ve sıfırı içerir: kişi kendini saymazsa bankada hiç müşteri olmayabilir.

$$\Omega_4=\{x \mid x\in[0,\infty)\}$$

Geliş zamanları arasındaki süre sürekli bir büyüklüktür, sıfırdan sonsuza kadar her değeri alabilir.

Örnek uzayın elemanlarına **örnek noktaları** ya da **temel olaylar** (elementary events) da denir. Örneğin zar deneyinde altı temel olay vardır.

## 6. Olaylar ve kuvvet kümesi

### 6.1 Olay tanımı

Hoca olay kavramını rakamlarla sayılar arasındaki ilişkiye benzetti: 0'dan 9'a kadar olan rakamlar temel yapı taşlarıdır ve bunlarla doğal sayılar tanımlanır. Benzer biçimde temel olaylar elimizdeyse bunlarla olaylar tanımlanır.

Ekrandaki tanım (ekrandan, 01:50:00): **olay**, sonuçların bir kümesidir; yani örnek uzayın bir alt kümesidir; yani temel olayların bir kümesidir.

**Soru:** Olay ile deney arasındaki fark nedir? **Cevap:** Deney süreçtir; temel olaylar deneyin olası sonuçlarıdır, olay ise bu sonuçlardan oluşan kümedir.

### 6.2 Kuvvet kümesi

Örnek uzay $\Omega=\{a,b,1\}$ olsun. Bu küme liste biçiminde ya da Venn şemasıyla (bir elips içinde $a$, $b$, $1$ noktaları) gösterilebilir (ekrandan, 01:50:00).

Ekrandaki tanım: bir A kümesinin **kuvvet kümesi**, A'nın bütün alt kümelerinin kümesidir ve $\mathcal{P}(A)$ ile gösterilir. Hoca, bu italik (el yazısı) $\mathcal{P}$'nin olasılık anlamına gelmediğine dikkat çekti.

$\Omega=\{a,b,1\}$ için alt kümeler şunlardır (boş küme de örnek uzayın bir alt kümesidir):

$$\mathcal{P}(\Omega)=\{\emptyset,\{a\},\{b\},\{1\},\{a,b\},\{a,1\},\{b,1\},\{a,b,1\}\}$$

Bu alt kümelerin her biri bir olaydır. $|\Omega|$, örnek uzaydaki temel olayların sayısıdır (örnek uzayın büyüklüğü). Bu örnekte:

- $|\Omega|=3$
- $|\mathcal{P}(\Omega)|=8$
- Genel olarak $|\mathcal{P}(\Omega)|=2^{|\Omega|}$; burada $2^3=8$.

Ekrandaki sonuç (ekrandan, 02:10:00): $n$ sonuçlu bir örnek uzay $2^n$ olası olay verir.

### 6.3 Bir olayın gerçekleşmesi: otobüs/taksi örneği

Hoca ikinci aradan sonra şu örnek uzayı yazdı (ekrandan, 02:10:00):

$$\Omega=\{\text{full, empty, bus, taxi, arrive(s), depart(s)}\}$$

ve üç olay tanımladı:

$$E_1=\{\text{empty, bus, departs}\},\quad E_2=\{\text{full, taxi}\},\quad E_3=\{\text{bus, taxi}\}$$

Bir öğrenci $E_1$'i "boş otobüs kalkıyor" diye bir cümle gibi okudu. Hoca bunun doğru olmadığını açıkladı: $E_1$ bir cümle değil, bir kümedir. Deneyin her denemesi yalnız **bir** sonuç üretir; "boş otobüs kalktı" diye bir sonuç çıkmaz. Deneyin sonucu "bus" ise sonuç $E_1$'in elemanı olduğundan $E_1$ olayı gerçekleşmiştir.

Sonuç "taxi" ise ne olur? Taxi hem $E_2$'nin hem $E_3$'ün elemanıdır; bu yüzden $E_2$ ve $E_3$ olayları aynı anda gerçekleşir. $E_1$ ise gerçekleşmez.

> **Ders sonrası not:** Hoca sonuç "bus" iken $E_1$ olayının gerçekleştiğini söyledi. Bus, $E_3=\{\text{bus, taxi}\}$'ün de elemanı olduğundan bu durumda $E_3$ de gerçekleşir.

Ekranda ayrıca $E_1\subset\Omega$, $E_2\subset\Omega$, $E_3\subset\Omega$ yazıldı; yani üçü de örnek uzayın alt kümesi olduğu için birer olaydır (ekrandan, 02:20:00).

Genel kural da ekranda yazıldı (ekrandan, 02:20:00): $\Omega=\{a,b,c,d\}$ örnek uzayından bir $E=\{a,b\}$ olayı alalım. Deneyin değeri $a$ ya da $b$ ise $E$ olayı gerçekleşmiş deriz:

$$a,b\in E\subset\Omega$$

Bunlardan biri ortaya çıkarsa $E$ olayı gerçekleşir.

## 7. Kesin olay ve imkânsız olay

**Kesin olay**, deneyin her tekrarında kesinlikle gerçekleşen olaydır (ekrandan, 02:25:00). Her deneyin bir örnek uzayı vardır ve deneyin sonucu her zaman örnek uzayın bir elemanıdır. Olay, sonuçların kümesidir; örnek uzay da bütün olası sonuçların kümesidir. Bu yüzden $\Omega$ kesin olaydır.

**İmkânsız olay**, deneyde hiçbir zaman gerçekleşmeyen olaydır ve $\emptyset$ (boş küme) ile gösterilir.

Hoca bunu Türkçe şöyle açıkladı: para atıldığında sonuç ya yazıdır ya turadır; başka bir şey gelemez. Bir öğrenci paranın dik gelebileceğini söyleyince hoca öyle bir durumun bu deneyde tanımlı olmadığını belirtti. Zar atıldığında da sonuç 1-6'dan biridir; örnek uzayda olmayan bir şey gelemez. Dolayısıyla hiçbir sonucu içermeyen olay, yani boş küme, imkânsız olaydır.

## 8. Olaylar üzerinde işlemler

Olaylar sonuç kümeleri olarak tanımlandığı için olaylar üzerindeki işlemler küme teorisine dayanır (ekrandan, 02:30:00).

### 8.1 Birleşim

A ve B olaylarının birleşimi $A\cup B$ ile gösterilir; $\cup$ simgesinin adı "cup"tır, bu yüzden "A cup B" diye de okunur (Türkçesi birleşim). $A\cup B$, A ya da B olaylarından **en az biri** gerçekleştiğinde gerçekleşir ve bu iki olayın bütün sonuçlarından oluşur (ekrandan, 02:30:00).

$|A|$, A olayındaki eleman (temel olay) sayısıdır. Birleşimin büyüklüğü için (ekrandan, 02:35:00):

$$|A\cup B|\le |A|+|B|$$

### 8.2 Kesişim

A ve B olaylarının kesişimi $A\cap B$ ile gösterilir; $\cap$ simgesinin adı "cap"tir (ekrandan, 02:35:00). Kesişim de bir olaydır ve A ile B olayları **aynı anda** gerçekleştiğinde gerçekleşir. "Aynı anda" ne demek? Otobüs/taksi örneğinde sonuç taxi olduğunda taxi hem $E_2$'de hem $E_3$'te bulunduğu için $E_2$ ve $E_3$ aynı anda gerçekleşmiştir; taxi, $E_2\cap E_3$'ün elemanıdır.

$$|A\cap B|\le\min(|A|,|B|)$$

### 8.3 Tümleyen

Bir A olayının tümleyeni (Türkçesi tersi) $\bar{A}$ ile gösterilir. Başka kitaplarda $A'$ ya da $A^c$ gibi gösterimler de kullanılır; hepsi aynı anlama gelir. Derste $\bar{A}$ kullanılacaktır.

**Soru:** Kitaplarda tümleyen için başka işaretler de karşımıza çıkar mı? **Cevap:** Bu kitabın kendi gösterimine bağlıdır; her kitabın kendi gösterimi vardır. Derste izlenen kitapta hem $\bar{A}$ hem $A^c$ geçer, ama hoca $\bar{A}$'yı tercih ediyor. Bir kitaba başlarken önce onun gösterimini öğrenmek önemlidir.

Venn şemasında örnek uzay içindeki A bölgesinin dışında kalan her yer $\bar{A}$'dır (ekrandan, 02:40:00):

$$A\cup\bar{A}=\Omega,\qquad A\cap\bar{A}=\emptyset$$

Tümleyenin büyüklüğü, örnek uzayın büyüklüğünden A'nın büyüklüğü çıkarılarak bulunur:

$$|\bar{A}|=|\Omega|-|A|$$

### 8.4 Fark

A ve B olaylarının farkı $A\setminus B$ ile gösterilir (ekrandan, 02:40:00). Hoca simgenin sola yatık bir dik çizgi olduğuna dikkat çekti; "A fark B" diye okunur. $A\setminus B$, A'da olup B'de olmayan sonuçlardan oluşur.

### 8.5 Venn şeması üzerinde bölgeler

Örnek uzay içinde kesişen iki olay A ve B çizildi (ekrandan, 02:45:00). Üç bölge vardır:

- Ortak bölge: $A\cap B$
- Yalnız A'ya ait bölge: $A\setminus B$
- Yalnız B'ye ait bölge: $B\setminus A$

Fark işlemi kesişim ve tümleyenle yazılabilir:

$$B\setminus A=B\cap\bar{A},\qquad A\setminus B=A\cap\bar{B}$$

Hoca ardından $(A\setminus B)\cup(B\setminus A)$ bölgesinin A ve B cinsinden nasıl yazılacağını sordu ve şöyle açtı (ekrandan, 02:45:00):

$$(A\setminus B)\cup(B\setminus A)=(A\cap\bar{B})\cup(B\cap\bar{A})$$

Birleşimin kesişim üzerine dağılma özelliğiyle:

$$=(B\cup A)\cap(B\cup\bar{B})\cap(A\cup\bar{A})\cap(\bar{A}\cup\bar{B})$$

Burada $B\cup\bar{B}=\Omega$ ve $A\cup\bar{A}=\Omega$'dır. Örnek uzayla kesişim bir olayı değiştirmez: $\Omega\cap A=A$, $\Omega\cap B=B$, $\Omega\cap(A\cup B)=A\cup B$ ve $\Omega\cap(\bar{A}\cup\bar{B})=\bar{A}\cup\bar{B}$. Böylece (ara adım eklendi):

$$(A\setminus B)\cup(B\setminus A)=(A\cup B)\cap(\bar{A}\cup\bar{B})$$

> **Ek bilgi (derste anlatılmadı):** De Morgan kuralına göre $\bar{A}\cup\bar{B}=\overline{A\cap B}$'dir. Bu yüzden sonuç $(A\cup B)\setminus(A\cap B)$ olarak da yazılabilir: iki olaydan tam olarak birinin gerçekleşmesi. Bu işleme simetrik fark denir ve çoğu kaynakta $A\,\triangle\,B$ ile gösterilir.

## 9. Ayrık ve bütüncül olaylar

### 9.1 Ayrık olaylar

$A, B, C, D, \dots$ olaylarına **ayrık** (disjoint), **bağdaşmaz** (incompatible) ya da **karşılıklı dışlayan** (mutually exclusive) denir; bu üç terim eş anlamlıdır. Tanım: olaylar ancak ve ancak bütün olası kesişimleri boşsa ayrıktır. Yani (ekrandan, 02:50:00):

$$A\cap B=\emptyset,\quad A\cap C=\emptyset,\quad A\cap D=\emptyset,\quad A\cap E=\emptyset,\ \dots$$
$$B\cap C=\emptyset,\quad B\cap D=\emptyset,\ \dots,\quad C\cap D=\emptyset,\ \dots$$
$$A\cap B\cap C=\emptyset,\quad A\cap B\cap D=\emptyset,\ \dots,\quad A\cap B\cap C\cap D\cap\dots=\emptyset$$

Bütün kesişimler boşsa olaylar birbirinden tamamen ayrılmıştır ve ayrık oldukları söylenir.

### 9.2 Dört olaylı Venn örneği

Hoca örnek uzay içine dört olay (A, B, C, D) çizdi ve kesişimlerine baktı (ekrandan, 02:55:00):

- $A\cap C=\emptyset$, öyleyse A ve C ayrıktır.
- $A\cap B\neq\emptyset$, öyleyse A ve B karşılıklı dışlayan değildir.
- $C\cap D=\emptyset$, öyleyse C ve D bağdaşmazdır.
- $C\cap B\neq\emptyset$, öyleyse C ve B ayrık değildir.

Dördünün ortak kesişimi $A\cap B\cap C\cap D=\emptyset$'dir.

**Soru:** Öyleyse A, B, C, D ayrık mıdır? Bir öğrenci "ayrıktır, karşılıklı dışlayandır" diye cevap verdi. **Cevap:** Hayır. Yalnız ortak kesişime bakmak yetmez; bütün olası kesişimlere bakmak gerekir. $C\cap B\neq\emptyset$ olduğu için A, B, C, D ayrık değildir.

> **Hocanın vurgusu:** Ayrıklık için yalnız bir durumu değil, bütün olası kesişimleri kontrol etmek gerekir.

### 9.3 Bütüncül olaylar

$A, B, C, \dots$ olaylarının birleşimi örnek uzaya eşitse bu olaylar **bütüncüldür** (exhaustive):

$$A\cup B\cup C\cup\dots=\Omega$$

Yani bütüncül olaylar bütün örnek uzayı kaplar.

Örnek: örnek uzay içinde bir A olayı ve onun dışında kalan $\bar{A}$ olsun. $A\cup\bar{A}=\Omega$ olduğundan A ile $\bar{A}$ bütüncüldür. Ayrıca $A\cap\bar{A}=\emptyset$ olduğundan A ile $\bar{A}$ ayrıktır (ekrandan, 03:00:00). Yani bir olay ile tümleyeni hem ayrık hem bütüncüldür.

### 9.4 Zar örneği

Zar deneyinde örnek uzay $\Omega=\{1,2,3,4,5,6\}$'dır (ekrandan, 03:00:00). Üç olay tanımlanır:

- Çift sayı gelmesi: $A=\{2,4,6\}$
- Tek sayı gelmesi: $B=\{1,3,5\}$
- Asal sayı gelmesi: $C=\{2,3,5\}$

Önce birleşime bakılır:

$$A\cup B\cup C=\{1,2,3,4,5,6\}=\Omega$$

Öyleyse A, B, C bütüncüldür.

Sonra kesişime bakılır: $A\cap B=\emptyset$ olduğundan $A\cap B\cap C=\emptyset$'dir. Ama ikili kesişimler boş değildir: $A\cap C=\{2\}$ ve $B\cap C=\{3,5\}$ (ara adım eklendi). Bu yüzden A, B, C ayrık değildir. <!-- BELİRSİZ: Altyazıda hoca gerekçeyi "C is not an empty space" diye söylüyor; bu cümle bozuk, kastedilen büyük olasılıkla C'nin A ve B ile kesişiminin boş olmaması. -->

Son olarak yalnız A ve B'ye bakılır:

$$A\cup B=\Omega,\qquad A\cap B=\emptyset$$

Öyleyse A ve B ayrıktır; birleşimleri örnek uzayı verdiği için bütüncüldürler de.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:34:28): Zar atma deneyinin olası sonuçları nelerdir?

> **Çözüm:** Bir öğrenci altı sayı olduğunu söyledi; olası sonuçlar 1, 2, 3, 4, 5, 6'dır.

**Soru 2** (derste sözlü, 01:38:34): Para atma deneyinin örnek uzayı nedir?

> **Çözüm:** Yazı ya da tura: $\Omega_1=\{T,H\}$; sayılarla $\{0,1\}$ (ekrandan, 01:40:00).

**Soru 3** (derste sözlü, 01:40:11): Bir bankadaki müşteri sayısını sayma deneyinin örnek uzayı nedir?

> **Çözüm:** Bir öğrenci "pozitif sayılar" dedi; hoca sıfırın da dahil olduğunu belirterek düzeltti: negatif olmayan tamsayılar, $\Omega_3=\{0,1,2,3,\dots\}$ (ekrandan, 01:45:00).

**Soru 4** (derste sözlü, 01:41:18): Bankaya gelen iki müşterinin geliş zamanları arasındaki süreyi ölçme deneyinin örnek uzayı nedir?

> **Çözüm:** Süre süreklidir ve negatif olamaz: $\Omega_4=\{x\mid x\in[0,\infty)\}$ (ekrandan, 01:45:00).

**Soru 5** (derste sözlü, 01:47:39): $\Omega=\{a,b,1\}$ kümesinin kaç alt kümesi vardır ve bunlar nelerdir?

> **Çözüm:** Bir öğrenci 8, boş küme de sayılırsa belki 9 olduğunu söyledi. Hoca $2^n=2^3=8$ olduğunu açıkladı; boş küme bu sekizin içindedir: $\emptyset,\{a\},\{b\},\{1\},\{a,b\},\{a,1\},\{b,1\},\{a,b,1\}$. Buna göre $|\Omega|=3$, $|\mathcal{P}(\Omega)|=8$.

**Soru 6** (ekrandan, 02:10:00; derste sözlü, 02:15:42): $\Omega=\{\text{full, empty, bus, taxi, arrive(s), depart(s)}\}$, $E_1=\{\text{empty, bus, departs}\}$, $E_2=\{\text{full, taxi}\}$, $E_3=\{\text{bus, taxi}\}$ olsun. Deneyin sonucu taxi ise hangi olaylar gerçekleşmiştir?

> **Çözüm:** Taxi hem $E_2$'nin hem $E_3$'ün elemanıdır; $E_2$ ve $E_3$ aynı anda gerçekleşir, $E_1$ gerçekleşmez.

**Soru 7** (derste sözlü, 02:24:23): İmkânsız olayı gösteren $\emptyset$ simgesi ne anlama gelir?

> **Çözüm:** Boş küme.

**Soru 8** (derste sözlü, 02:38:50): Bir A olayının tümleyeninin büyüklüğü nedir?

> **Çözüm:** Bir öğrenci doğru cevabı verdi: $|\bar{A}|=|\Omega|-|A|$.

**Soru 9** (ekrandan, 02:45:00): İki olaylı Venn şemasında ortak bölge, yalnız A'ya ait bölge ve yalnız B'ye ait bölge nasıl gösterilir? $(A\setminus B)\cup(B\setminus A)$ bölgesi A ve B cinsinden nasıl yazılır?

> **Çözüm:** Bölgeler sırasıyla $A\cap B$, $A\setminus B=A\cap\bar{B}$ ve $B\setminus A=B\cap\bar{A}$'dır. Dağılma özelliğiyle $(A\cap\bar{B})\cup(B\cap\bar{A})=(A\cup B)\cap(B\cup\bar{B})\cap(A\cup\bar{A})\cap(\bar{A}\cup\bar{B})=(A\cup B)\cap(\bar{A}\cup\bar{B})$ olur (son sadeleştirme ara adım olarak eklendi).

**Soru 10** (ekrandan, 02:55:00; derste sözlü, 02:54:09): Dört olaylı Venn örneğinde $A\cap C=\emptyset$, $A\cap B\neq\emptyset$, $C\cap D=\emptyset$, $C\cap B\neq\emptyset$ ve $A\cap B\cap C\cap D=\emptyset$'dir. A, B, C, D ayrık mıdır?

> **Çözüm:** Hayır. Ortak kesişim boş olsa da $C\cap B\neq\emptyset$ olduğu için olaylar ayrık değildir.

**Soru 11** (ekrandan, 03:00:00): Zar deneyinde $A=\{2,4,6\}$, $B=\{1,3,5\}$, $C=\{2,3,5\}$ olsun. A, B, C bütüncül müdür, ayrık mıdır? A ve B ayrık mıdır?

> **Çözüm:** $A\cup B\cup C=\Omega$ olduğundan A, B, C bütüncüldür. $A\cap B\cap C=\emptyset$ olsa da $A\cap C=\{2\}\neq\emptyset$ olduğundan ayrık değildir. $A\cup B=\Omega$ ve $A\cap B=\emptyset$ olduğundan A ve B ayrıktır (ve bütüncüldür).

## Dersin Toparlaması

Bu ilk derste önce dersin kapsamı ve öğrenme çıktıları tanıtıldı: kombinatorikten olasılık aksiyomlarına, rastgele değişkenlerden parametre kestirimi, güven aralıkları ve hipotez testlerine uzanan bir yol. Ardından olasılık ve istatistiğin belirsizlikle başa çıkmak için geliştirilmiş matematik dalları olduğu, rastgeleliğin sonucu etkileyen etkenler hakkındaki eksik bilgiden doğduğu yazı-tura örneğiyle açıklandı. Tarihsel bir not olarak el-Kindî'nin frekans analizi anlatıldı ve olasılığın bilgisayar bilimindeki uygulamaları (güvenilirlik, ölçüm doğruluğu, kalite kontrol) sayıldı.

Dersin teknik kısmında olasılık kuramının temel dili kuruldu: deney, sonuç, örnek uzay $\Omega$, temel olaylar ve örnek uzayın alt kümeleri olarak olaylar. $n$ sonuçlu bir örnek uzayın $2^n$ olay verdiği kuvvet kümesiyle gösterildi; kesin olayın $\Omega$, imkânsız olayın $\emptyset$ olduğu anlatıldı. Olaylar üzerinde birleşim, kesişim, tümleme ve fark işlemleri tanımlandı; ayrık (bağdaşmaz, karşılıklı dışlayan) ve bütüncül olaylar Venn şemaları ve zar örneğiyle ayırt edildi. Bu kavramlar, sonraki derslerde olasılık aksiyomlarının ve olasılık kurallarının üzerine kurulacağı temeli oluşturuyor.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
