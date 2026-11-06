# Ders 3 Genişletilmiş Notu: Dilbiliminin Esasları, Biçim Bilim ve Chomsky Hiyerarşisi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Planı ve Temel Malzeme: Sözlük, Gramer, Gram
- 2. Dil Analizinin Altı Seviyesi
- 3. Doğal Dil İşlemede Kullanılan Modeller
- 4. Ses Bilimi ve Fonetik
- 5. Yabancı Kelimelerin Söylenişi Üzerine Bir Soru
- 6. Biçim Bilime Giriş
- 7. Ekler
- 8. Biçimbilimsel Belirsizlik ve Bağlılık Analizi
- 9. Kök, Gövde ve Ölü Kökler
- 10. Sözcük Birim, Sözcük Biçim ve Yazım Hatası Düzeltme
- 11. Svahili Örneği: Biçimbirimleri Dağılımdan Bulmak
- 12. Biçimbirim Gösterimi ve Ünlü Uyumu
- 13. Biçimbirim Türleri
- 14. Biçimbilimsel Analizin Görevleri ve Yöntemleri
- 15. "ki"nin Üç Türü, Uyum Dışı Durumlar ve Fiil Çatıları
- 16. Gramer ve Diller: Temel Kavramlar
- 17. Gramerin Biçimsel Tanımı
- 18. Chomsky Hiyerarşisi
- 19. Tür 0: Kısıtlamasız Gramer
- 20. Tür 1: Bağlama Bağımlı Gramer
- 21. Tür 2: Bağlamdan Bağımsız Gramer
- 22. Tür 3: Düzenli Gramer ve Düzenli İfadeler
- 23. Yukarıdan Aşağı ve Aşağıdan Yukarı Ayrıştırma
- 24. Gerçek Dil Örnekleri
- 25. Genişletilmiş Geçiş Ağları

Bu derste iki slayt bitirilir. İlki dilbiliminin esaslarıdır ve çok sözel olduğu için hızlı geçilir; bu bölümde yer yer atlanan konular vardır. Asıl ağırlık ikinci slayttadır: gramer ve diller. Buradaki gramer okulda öğrendiğimiz gramer değildir; dillerin Tür 0'dan Tür 3'e kadar biçimsel sınıflarıdır.

## 1. Dersin Planı ve Temel Malzeme: Sözlük, Gramer, Gram

Doğal dille iş yapmak için iki şeye mutlaka ihtiyaç vardır: kelimeler ve kurallar. Kelimeler sözlükte tutulur. Sözlüğün teknik adı leksikondur (lexicon). Yeri geldiğinde yalnız isimlerden, yalnız fiillerden veya yalnız eklerden oluşan ayrı leksikonlar kullanılır. Kurallar ise dile özgü gramerlerdir.

Hoca genel kültür olarak Türk kültüründeki ilk sözlüğü anar: Türkçeden Arapçaya hazırlanan Divânu Lugâti't-Türk.

Gramer kelimesinin içinde dil modellerinde karşımıza çıkacak "gram" kavramı vardır. Bu gram ağırlık birimi değildir. Hoca, Arapçadaki sarf ve nahiv ilmini ve Batı dillerindeki "gram" kelimesini anarak bunu bir dilde bölünebilen en küçük parçacık diye tanımlar.

Bu tanımın pratikte anlamı şudur: Bir dokümanın en küçük birimi kelimedir, gerekirse her kelimeye gram denir. Kelimeler de karakterlerden oluşur, gerekirse her karaktere gram denir. Bu yüzden dil modellerinde kelime tabanlı n-gram ve karakter tabanlı n-gram diye iki tür kullanılır.

## 2. Dil Analizinin Altı Seviyesi

Doğal dil işlemenin altı ana başlığı ilk dersten hatırlanır. Hoca bunları bir zincir gibi anlatır: karakterler kelimeleri, kelimeler tümceleri, tümceler metni oluşturur. Her seviye bir öncekinin çıktısını kullanır.

Hoca terimler için bir not düşer. Kelime yerine sözcük, cümle yerine tümce kullanılabilir; ikisi de aynıdır. Kendisi ilkokul alışkanlığıyla bazen "kelime" der.

### 2.1 Fonoloji (Phonology)

Fonoloji dilin ses özelliklerini inceler. Bu derste bu konuya pek girilmez. Hoca fikri şöyle anlatır: Her dilde her karakterin bir frekansı vardır. Konuşmadan metne çevirmede (speech to text) bu frekanstan, yani sesten, hangi karaktere karşılık geldiği çıkarılır.

### 2.2 Biçim Bilim (Morphology)

Karakterler bir araya gelip kelimeyi oluşturur. Kelimenin yapısını inceleyen seviye biçim bilimdir. Biçimbilimsel analiz kelimenin kökünü ve o köke eklenebilecek ekleri bulur. Zemberek bu bilgiyi verir. Hoca, İngilizce için de NLTK'yı anar.

### 2.3 Söz Dizimi (Syntax)

Kelimeler bir araya gelip tümceyi oluşturur. Tümcenin yapısını inceleyen seviye söz dizimi bilgisidir. Söz dizimsel analiz yazılan tümcenin o dile ait olup olmadığını söyler.

Hocanın örneği: "Kitap, kuş, petrol, araba." Bu kelimelerin hepsi biçimbilimsel analizden geçer, sonuna nokta da konmuştur. Ama bu bir tümce değildir, çünkü Türkçe için anlamı olan bir cümle yapısı taşımaz. Bunu söyleyecek olan söz dizimsel analizdir. Bu konu dersin ikinci yarısında ayrıntılı işlenir.

### 2.4 Anlam Bilim (Semantics)

Tümcenin dile ait olduğu anlaşıldıktan sonra anlamsal analize geçilir. Anlamsal analiz tümcenin, kelimelerin ve kelime öbeklerinin anlamını çıkarmaya çalışır. Hocanın ölçütü şudur: Bu tümceye kim, ne, nerede, neden sorularını sorduğumda cevabını alabilmeliyim.

Eş dizimlilik (birlikte kullanılan söz öbekleri) de burada önemlidir. Hocanın örneği "Yıldız Teknik Üniversitesi"dir. "Yıldız", "teknik" ve "üniversite" ayrı ayrı değerlendirilirse tümce çok farklı bir anlama gidebilir; belki "yıldız" özne gibi alınır. Oysa üçü birlikte kullanılan tek bir söz öbeğidir. Analizde tümcenin özneleri ve öğeleri de bulunur.

### 2.5 Söylem (Discourse)

Tümceyi anlamak tek başına yetmez, bağlamı da (context) bilmek gerekir. Söylem bilgisi farklı türdeki metinlerin yapısını inceler. Bağımsız değerlendirilen bir tümce ile metin içinde değerlendirilen tümce farklı anlamlar verebilir.

Hocanın örneği: "Eşyalarını, paralarını sakladı." Bu cümle tek başına okunduğunda kişinin cimri olduğu sanılabilir. Metnin bütününe bakılınca belki savaş anıdır ve insanlar eşyaları gasp edilmesin diye saklıyordur. Bütüne bakıldığında cümle daha olumlu bir anlam taşır.

### 2.6 Edim (Pragmatics)

Edim seviyesinde metnin dışından bilgiye ihtiyaç vardır. İlk dersteki örnek hatırlanır: Kiracı "köpeğim de var" deyince ev sahibi "bu kötü bir şey" der. Ev sahibi-kiracı ilişkisinde evde hayvan beslemenin çoğu ev sahibince hoş karşılanmadığı bilgisi metinde yazmaz, sisteme dışarıdan verilmelidir. Kira artış oranı da benzerdir: ev sahibine göre normal olan bir oran kiracıya göre olumsuz olabilir.

Bu seviyelerin hepsini bir arada toplayan bir çalışma mükemmel olurdu. Ancak söylem ve edim üzerinde yeni yeni çalışılıyor. Hepsini içinde barındıran eksiksiz bir NLP çalışması henüz yok; varsa da deneme aşamasında veya alana özeldir.

## 3. Doğal Dil İşlemede Kullanılan Modeller

Bu seviyelerde iş yapabilmek için modeller gerekir. Hoca şu türleri sayar:

- **Sonlu durum makineleri (finite state machine):** Klasik biçimbilimsel analizde hep vardır. Son zamanlarda yerine derin öğrenme modelleri de kullanılmaya başlandı, ama hoca böyle bir çalışmayı henüz bizzat dinlemediğini veya görmediğini söyler.
- **Kural tabanlı sistemler:** Kurallar önceden belirlenip çıkarılır. Sırayla "bu kurala uydu mu, şuna uydu mu" diye kontrol edilir.
- **Mantık (logic) kullanan sistemler.**
- **Olasılık teorisi kullanan sistemler:** Dil modelleri tamamen olasılık teorisini kullanır.
- **Makine öğrenmesi modelleri:** Son dönem makalelerin çoğunda görülür.

Hoca makine öğrenmesi ile derin öğrenme farkını da açar. Makine öğrenmesi az veriyle de daha başarılı sonuç verebilir. Aynı veriyle derin öğrenmede aynı sonuç alınamaz; çok veri ve çok parametre gerekir. Bireysel donanımlar bunu sağlayamadığı için makine öğrenmesi üzerinde çalışılmaya devam edilebilir. Derin öğrenme modeli kurulup makine öğrenmesi kadar iyi sonuç alınamazsa sebebi de bellidir: ara katman sayısı yeterince artırılamıyor ve sistem yeterince çok veriyle beslenemiyor.

## 4. Ses Bilimi ve Fonetik

Ses biliminde girişe akustik bir işaret verilir, çıkışta alfabedeki bir karakterin karşılığı alınır. Ses birimine fon denir.

Doğal dillerin hepsi fonetik değildir. Fonetik dil yazıldığı gibi okunan dildir. Hocanın örnekleri Türkçe, Japonca ve Fincedir. Yazıldığı gibi okunmanın anlamı şudur: Her sese bir sembol karşılık gelir, yani bir karaktere bir ses vardır. Bazı dillerde iki karakter yan yana gelince farklı okunur; bunlar fonetik dil sayılmaz.

Bundan ayrı bir kavram fonetik alfabedir. Bir kelime telefonda iyi duyulmuyorsa veya kişinin şivesi yüzünden anlaşılmıyorsa "kodla" ya da "harf harf söyle" deriz. Fonetik alfabede her harfin karşılığı olan bir kelime belirlenmiştir. NATO'nun kullandığı alfabe buna örnektir, Türkiye'de kullanılanı da vardır.

Hoca bir televizyon yarışmasını hatırlatır: orada "Lüleburgaz'ın L'si, Kastamonu'nun K'sı" denir. Biz bunları kafamızdan söyleriz, ama gerçekte kullanacak olsak bu alfabeyi kullanmamız gerekir. Hoca yine de bazı seçimleri garip bulur: "Ü" için "Ünye" kullanılmış, oysa Türkiye'de bu ilçeyi herkes bilmez ve "üzüm" daha anlamlı olurdu. Slayttaki bir satırı da kitaptan olduğu gibi aldığını, doğruluğundan emin olmadığını söyler.

<!-- BELİRSİZ: Fonetik alfabe tablosu slaytta. Altyazıda yalnız "Ü için Ünye" ve "J ... Jerusalem" okunuyor. -->

## 5. Yabancı Kelimelerin Söylenişi Üzerine Bir Soru

Bu noktada iş yerinde Ar-Ge mühendisi olarak çalışan bir öğrenci projesini anlatır ve soru sorar. Soru-cevap dersin önemli bir uygulama örneğidir.

**Soru:** Bir leksikon üzerinde çalışıyorum. Türkçeye başka dillerden çok kelime girdiği için söyleyişte araya farklı fonemler giriyor. "Transfer" yazılıyor ama söylerken T ile R arasına I giriyor. "Profesyonel"de araya I da girebiliyor, U da. Bu varyasyonları eklemek gerekiyor. SAMPA adlı, dil bilimcilerin geliştirdiği bir gösterimi ve Almanya'daki bir hocanın hazırladığı biçimbilimsel analiz kütüphanesini kullanıyorum. Kural tabanlı bir kod yazdım ama varyasyonlar o kadar farklı ki sonunda elle ekleme yapmak zorunda kalıyoruz. Bunu otomatize edecek yöntem var mı?

**Cevap:** Hoca ses tarafıyla değil metin tarafıyla ilgilendiğini, bu yüzden literatürü taramak gerektiğini belirtir. Önerileri şunlardır:

- **Dil bilimcilerle çalışmak:** Bu konu tamamen dil bilimcilerin ilgi alanındadır. Hocanın bildiği kadarıyla en iyi dil bilimciler İstanbul Üniversitesi'ndedir. Bir araştırma görevlisiyle iletişime geçmek yardımcı olabilir.
- **Kuralları azaltmak:** Hoca, Türkçede ekler ayrıldıktan sonra gövdede iki sessiz harfin yan yana geldiği kelimelerin az olduğunu söyler. "Okullar"daki iki L ek sınırında oluşur, gövdede değildir. Bu az sayıdaki kelimeler çıkarılıp onlara özel kural yazılabilir. Heceleme araçları da fikir verebilir: Türkçede hecelemenin 8-9 kuralı vardır, "profesyonel" gibi kelimeler için mutlaka ek kural gerekir. Hoca bunu öğrencilere sorar, cevap "pro-fes-yo-nel" olur.
- **İstatistiksel yaklaşım:** Türkçede "pr" başlangıcının olasılığı çok düşüktür. Saklı Markov modellerinde (Hidden Markov Model) bir durumdan diğerine olasılığı büyük olan geçiş tercih edilir. Olasılık küçükse burada bir sorun var demektir, yani kelime Türkçe olmayabilir. Hoca yine de bu duruma kural tabanlı yaklaşımın daha uygun olacağını düşünür.

Öğrenci kelime sayısının binlerce olduğunu ve "geleceğim" kelimesinin konuşma dilindeki söylenişinin de aynı anahtara bağlandığını ekler. Hoca bunun üzerine dil modeline dikkat çeker: "Ben yarın okula ..." cümlesinde sondaki kelimeyi biçimbilimsel analiz çözümleyemezse kelime yanlış diye işaretlenir. Dil modeli ise "okula"dan sonra hangi kelimenin gelebileceğini söyler. Bunun için gigabaytlarca derlemden kelime tabanlı ikili ve üçlü istatistikler çıkarılır, saklı Markov modelleri bunların üzerinde kullanılır. Sistem yanlış yazılan kelimenin aslında "git" olduğunu bulur, sonra bağlama bakarak hangi ekleri alabileceğini söyler.

## 6. Biçim Bilime Giriş

Biçimbilimsel analiz ortografik kelimelerle de uğraşır. Aynı anlam farklı yazımlarla verilebilir: "Ayşe gelmişti" ile "Ayşe gelmiş idi", "arabayla" ile "araba ile". Analiz bunların hepsini söyleyebilmelidir.

Hoca slaytta boşluksuz yazılmış bir cümle gösterir. İnsan hangi kelimelerden sonra boşluk geleceğini rahatça söyler, ama bilgisayar için bu bilinmeyen bir kelimedir ve çözümleyemez.

<!-- BELİRSİZ: Boşluksuz yazılmış cümle slaytta, altyazıda yok. -->

Türkçe bitişken (agglutinative) bir dildir, kelime ek alarak büyür. Slaytta zorlanarak yazılmış bir kelimede 11 ek vardır. Böyle bir kelime Türkçe olarak doğru çözümlenebilir, ama günlük hayatta bir kelimede en fazla 4 veya 5 ek kullanılır. Hocaya göre sondan eklemeli dillerde analiz İngilizceye göre çok daha zordur. İngilizcede ekleri atınca kalan zaten kelimenin köküdür.

<!-- BELİRSİZ: 11 ekli örnek kelime slaytta, altyazıda yok. -->

## 7. Ekler

Ekler çekim ekleri ve yapım ekleri diye ikiye ayrılır. Birleşik kelimeler de çözülmesi gereken ayrı bir problemdir.

### 7.1 Çekim Ekleri

Çekim ekleri eklendiği kelimenin anlamını değiştirmez. İsimlere ve fiillere eklenenler ayrı ayrı sayılır.

İsme eklenenler:

- **Çoğul eki:** kitaplar, çocuklar.
- **Hal ekleri:** "kalemi verdik", "duvara bak".
- **İyelik ekleri (sahiplik):** kitabım, kitabın, kitabımız, kitabı, kitapları.
- **İlgi (tamlama) ekleri (-ın, -in, -un, -ün):** "kapının kolu".
- **Ek eylem:** İsim soylu sözcükleri yüklem yapar. "İyi" isim soylu bir kelimedir, "iyiyim" yüklemdir. "Bugün nasılsın?" sorusuna "İyiyim." cevabı tek kelimelik bir cümledir.

Fiile eklenenler:

- **Zaman ekleri:** gelmiş, okudu.
- **Dilek ekleri:** şart, istek ve gereklilik anlatır. "Gidersem", "gitmeliyim".
- **Şahıs ekleri:** geliyorum (ben), geliyorsun (sen).

### 7.2 Yapım Ekleri

Yapım ekleri kelimenin anlamını değiştirir.

- **İsimden isim:** kömür + lük = kömürlük (kömürlerin konduğu yer).
- **İsimden fiil:** su + la = sula.
- **Fiilden isim:** düşün + ce = düşünce.
- **Fiilden fiil:** gül + dür = güldür.

### 7.3 Ekler Neden Önemli?

Biçimbilimsel analiz kökü bulduktan sonra ekleri POS etiketleriyle birlikte verir. Örneğin "-lar" çoğul eki, "-dı" geçmiş zaman eki diye etiketlenir. Fiilden fiil yapan bir ek de kendi etiketiyle gelir. Hoca Brown derleminde (Brown corpus) bu etiketleri göstereceğini söyler.

Bu etiketler anlamsal analizde kullanılır: "Bu olay geçmiş zamanda yapılmış." veya "kapının kolu"nda kolun kapının bir özelliğini anlattığı çıkarılır.

## 8. Biçimbilimsel Belirsizlik ve Bağlılık Analizi

### 8.1 "kitapları" Örneği

Kelimeler her zaman tek şekilde çözümlenmez, belirsiz (ambiguous) durumlar olur. Şu üç cümleye bakalım:

- "Bunlar Ahmet'in kitapları."
- "Kardeşimin kitaplarını kaplamalıyım."
- "Ahmet kitapları okudu."

Hepsinde kök "kitap"tır. Birinci cümlede çözümleme çoğul eki ve üçüncü tekil iyeliktir. İkincide "-lar" çoğul, "-ını" iyelik ekidir. Üçüncüde çoğul ve belirtme hâlidir (hocanın söylediği "durum 2"). Yani çözümleme kelimenin cümledeki yerine göre değişir.

Araca yalnız "kitapları" kelimesi verilirse bütün çözümleri verir, hangisinin en uygun olduğunu söylemez. Sıralamada dilde en sık karşılaşılan durumu ilk sıraya koyar; bu istatistik milyonlarca cümleden çıkarılmıştır.

Hangi çözümün gerektiği uygulamaya bağlıdır. Yalnız "kitap" kelimesinin kaç kez geçtiği bulunacaksa kök bilgisi yeter, hangi çözümün seçildiğinin önemi yoktur. Cümlenin söz dizimsel yapısı kullanılacaksa doğru çözümün bilinmesi gerekir. Bunun için bağlılık analizi (dependency parsing) yapılır.

### 8.2 Türkçe İçin Kaynaklar

Hoca bağlılık analizinin bizim kullandığımız araçlarda olmadığını söyler. Bazı üniversitelerde akademik çalışmalar vardır:

- ODTÜ'de ve Boğaziçi'nde çalışmalar var. Boğaziçi'ndeki hocalardan istenince verilebiliyor.
- İTÜ'de üst üste yapılan doktora çalışmalarından bir boru hattı (pipeline) oluşturulmuş. Biçimbilimsel analiz, söz dizimsel analiz, varlık ismi çıkarımı ve bağlılık analizini yapıyor. Yalnız web üzerinden açık: girdi gönderiliyor, çıktı alınıyor. Bu süreci yavaşlattığı için pek tercih edilmiyor. Akademik kullanım için izin de isteniyor.
- Geçen haftaki sempozyumda, bir firmada çalışan mezunlar bir ağaç bankası (treebank) sundu. Binlerce Türkçe cümlenin bağlılık ilişkileri elle etiketlenmiş. "Bunlar Ahmet'in kitapları" cümlesinde "bunlar" kitapları gösterir, kitaplar Ahmet'indir.

Bu ağaç bankasında çift kör etiketleme yapılmıştır: birinin etiketlediğini diğeri kontrol eder. Açık olarak paylaşılacağı söylenmiştir. Hoca bunun sistem eğitmek için çok faydalı bir girdi olduğunu belirtir.

> **Hocanın vurgusu:** Türkçe için çalışmalar çok geç başladı ve herkes bağımsız çalıştı. Herkes veri setini yeniden oluşturuyor. Çalışmalar birleştirilse her yeni gelen üzerine bir şey ekleyerek ilerlenirdi, ama böyle bir şey hâlâ görülmüyor.

### 8.3 "gider" Örneği

- "Bu gider tablosu çok detaylı hazırlanmıştır." Burada "gider" isimdir. "Gider tablosu" da bir birleşik isimdir; hoca az önce aradığı söz öbeği örneğini burada bulur.
- "Ayşe her gün okula gider." Burada "gider" zaman eki almış fiildir.

Araç iki çözümü de verir. Cümle bilinmeden hangisinin doğru olduğu anlaşılmaz. Hoca ipucu olarak konumu gösterir: İlk cümlede kelime isimden önce ve cümlenin başındadır, fiil olması beklenmez. İkincisinde cümlenin sonunda ve yüklemdir, fiildir.

Bu tür çalışmaların çoğu ilk çözümü alır. Herkes aynı şeyi yaptığı için aynı veri setinde sonuçlar birbiriyle kıyaslanabilir.

## 9. Kök, Gövde ve Ölü Kökler

İki önemli kavram vardır: kök (root) ve gövde (lemma). Gövdeye indirgeme işlemine lemmatization denir.

Hocanın örneği "gözlük"tür. Kelime "göz"den türemiştir, kökü "göz"dür. Ama sözlükte "gözlük" de vardır: "göze takılan araç". O hâlde "gözlük" kelimesini köküne indirmemek gerekir. "Gözlük" alınırsa gövde hâli alınmış olur; "göz" olarak işlenirse uygulamaya göre hata yapılmış olabilir.

> **Hocanın vurgusu:** Bir kelime sözlükte varsa onu o hâliyle almak yeterlidir, daha da köküne inmeye gerek yoktur.

"Kayak" örneği bunu güçlendirir. "kayak"tan harf atarsak "kaya" (sözlükte var), "kay" (fiil olarak var), "ka" kalır. Nereye kadar inileceği belli olmaz. "Kayak" sözlükte varsa "kayak" alınır.

Bazı eylemler kullanılmamaktan ölmüştür. Hoca "çalış" eylemini örnek verir. Eskiden "çal" diye bir eylem varmış: Kerpiç evler yapılırken elle çamuru alıp duvara atma işine "çalma" denirmiş. Nasreddin Hoca'nın göle maya çalması da aynı kullanımdır. Bu kelimeler günümüzde ölü sayılır.

## 10. Sözcük Birim, Sözcük Biçim ve Yazım Hatası Düzeltme

Kelimenin kendisine sözcük birim (lexeme) denir. Aldığı her ek onu bir sözcük biçime (word form) dönüştürür, çünkü kelimenin biçimini değiştirir.

Türkçede "ev" kelimesinin bütün biçimlerine bakıldığında evden türediği rahatça anlaşılır. İngilizcede durum böyle değildir. "Going, goes, gone" biçimlerinin "go"dan geldiği anlaşılır, ama birdenbire "went" çıkar. İngilizceyi ilk kez öğrenen biri bunun başka bir kelime olduğunu düşünebilir. Bu yüzden İngilizce çalışmalarda düzenli ve düzensiz fiiller ayrı leksikonlarda tutulur.

Anlamlı en küçük birime biçimbirim (morpheme) denir.

Hoca buradan öğrencinin sorusuna döner. Yanlış söylenmiş veya yanlış yazılmış kelimeler kolayca düzeltilebilir. Arama motorlarının "bunu mu demek istediniz?" önerisi arkada dil modellerini, yani n-gram modellerini kullanır.

**OCR örneği:** Elimizde resim formatında bir metin var ve OCR ile metne çeviriyoruz. OCR her zaman başarılı olmaz; kağıdın kalitesi bile çok önemlidir. Bir kelimedeki L harfi T olarak okunmuş ve "getecek" çıkmış olsun. Türkçede böyle bir kelime yoktur. İki yol vardır:

- **Kelime tabanlı dil modeli:** önündeki veya arkasındaki kelimeye bakarak buranın "gelecek" olduğunu söyler.
- **Karakter tabanlı dil modeli:** önünde E, iki önünde G, arkasında E ve onun arkasında C varsa buraya T değil L geleceğini söyler.

## 11. Svahili Örneği: Biçimbirimleri Dağılımdan Bulmak

Hoca aradan önce sınıfla bir uygulama yapar. Slaytta bir dilin birkaç cümlesi ve Türkçe karşılıkları verilmiştir. Dil Svahili'dir. Hoca bu dili hiç bilmediğini, ama kalem bile kullanmadan ve hiçbir model tasarlamadan çözebildiğini söyler.

| Svahili | Türkçe |
|---|---|
| nilipata | aldım |
| ulipata | aldın |
| valipata | aldılar |
| nilikipata | onu aldım |
| nitakipata | onu alacağım |
| ulikipata | onu aldın |
| nitakupata | seni alacağım |

Çözüm adımları şöyledir:

1. Hepsinde ortak olan "pata" almak fiilidir.
2. "Onu" içeren satırlarda "ki" vardır, diğerlerinde yoktur. O hâlde "ki" = onu.
3. "Aldım" ve "alacağım" satırlarında kişi "ben"dir ve ortak parça "ni"dir. O hâlde "ni" = ben. "Aldım" satırı bunu doğrular.
4. "Seni" karşılığı "ku"dur.
5. "Aldılar" satırında "va" vardır; üçüncü çoğul kişidir.

Böylece başka bir fiil verilirse dil çözülebilir: aynı biçimbirimler yeni kökün başına eklenir.

<!-- BELİRSİZ: Hocanın ikinci fiille verdiği örnek altyazıda bozuk ("Git, kata", "Nili kata", "Olikata"). Fiilin anlamı ve kesin biçimi okunmuyor. -->

Hoca bunun anlamını şöyle bağlar: Ben hiçbir model kullanmadan kuralları mantıkla çıkarabiliyorsam, bir derin öğrenme yapısına da bu kelimeleri verip "öğren" dediğimde "pata"nın almak, "u"nun ikinci tekil kişi olduğunu öğrenir. Bunu makine öğrenmesi yöntemleriyle de yapabilirim.

## 12. Biçimbirim Gösterimi ve Ünlü Uyumu

Bir kelime biçim birimlerini alırken farklı koşullara girer. "Bilecek" ve "bulacak" karşılaştırılırsa ses uyumu görülür: kalın sesliden sonra kalın, ince sesliden sonra ince sesli gelir. Buna uymayan durumlar da vardır: "-ken" eki önündeki sesli ne olursa olsun hep "ken"dir, "kan", "kun" olmaz.

İngilizcede benzer ön ekler için kural yoktur. Bir kelimenin önüne "il-", "im-", "in-" veya "ir-" geleceği belirlenemez. Dile yetenekli kişiler kulağa uyumlu geleni tahmin edebilir. Hoca kendisinin ancak kelimeyi defalarca görerek öğrendiğini söyler. Bu yüzden İngilizcede bu ön ekleri alan kelimeler ayrı leksikonlarda tutulur.

Biçimbirimler için bir gösterim vardır:

- **Köşeli parantez:** İçindeki her şey olduğu gibi kullanılır.
- **Süslü parantez:** İçindeki büyük harfler farklı okunabilir.
  - A: a veya e.
  - I: ı, i, u veya ü.
  - Ç: ç veya c.
  - T: t veya d.

| Biçimbirim | Biçimcikler |
|---|---|
| {AcAk} | [acak], [ecek] |
| {ÇI} | [çı], [çi], [çu], [çü], [cı], [ci], [cu], [cü] |
| {lIk} | [lık], [lik], [luk], [lük] |
| {TA} | [ta], [te], [da], [de] |
| {ken} | [ken] |

Bu gösterim sayesinde kelimenin nasıl okunacağı ve nasıl değişeceği söylenebilir. Örneğin "git" sözcük birimi ek alarak "gidecek" sözcük biçimi olur. Kök "giT" diye büyük T ile gösterilir: tek başına kullanıldığında t, ek aldığında d olur. "-ecek" de önündeki fiile göre "-acak" veya "-ecek" olur.

## 13. Biçimbirim Türleri

**Bağımlı ve bağımsız biçimbirimler (bound / free morpheme):** Ekler her zaman bağımlıdır, tek başına kullanılamaz. Tek başına görünmeyen kökler de bağımlıdır. Hocanın örnekleri "öğre" ve "nite"dir. "Öğrenmek" ve "öğrenci" kelimeleri "öğre"den, "nitel" ve "nitelik" kelimeleri "nite"den gelir, ama bu kökler bugün tek başına kullanılmaz. Bunların dışında kalanlar bağımsızdır.

**Sıfır biçimcik:** Hoca bunu hiçbir ek almadan tek başına kullanılabilenler diye tanımlar (bkz. Ders Sonrası Notlar).

**Portmanto biçimbirim:** Hoca adı bir benzetmeyle açıklar: Evde veya sınıfta üzerimizden çıkardıklarımızı astığımız bir askı vardır. Bazen bir çengele birden fazla kişi kıyafetini asar, üst üste biner. Dilde de bir ek birden fazla anlamı içinde barındırıyorsa portmanto biçimciktir.

- "geliyorsunuz": hem "siz"i hem çoğulu anlatır.
- "geldik": hem "biz"i hem geçmiş zamanı anlatır (bkz. Ders Sonrası Notlar).
- İngilizcedeki "-s": hem geniş zamanı hem üçüncü tekil kişiyi gösterir.

**Tekcil biçimbirim:** Yalnız tek bir kökle kullanılan biçimbirimdir. "Yağmur" kelimesinin "yağ" eylemiyle bağlantısı açıktır, ama "-mur" eki Türkçede "yağ" kökünden başka hiçbir kelimeye eklenmez. "Hamur" bir karşı örnek değildir, çünkü kökü "ha" değildir. İngilizcede "cranberry"deki "cran" yalnız "berry" ile kullanılır.

## 14. Biçimbilimsel Analizin Görevleri ve Yöntemleri

Biçimbilimsel analizin görevleri üçtür:

- Kelimenin türünü tespit etmek: isim, sıfat, fiil, edat.
- Kelimeyi oluşturan kökü ve ona eklenen biçimbirimleri söylemek.
- Aldığı eklerin türünü vermek. "Armudu yedim" ile "Ali'nin armudu"nda aynı "-u" eki vardır, ama birincide nesne eki, ikincide tamlanan ekidir.

İki yöntem vardır:

- **Bildirimsel (declarative) yöntem:** Kelimeler biçimbilimsel bilgileriyle birlikte sözlükte tutulur. Analizde kelime aranır, sonuç doğrudan alınır. En basit yöntemdir, ama sözlüğün bir kez hazırlanması çok zahmetlidir.
- **Yordamsal (procedural) yöntem:** Sözlükte yalnız kökler saklanır. Ekler biçimbilimsel kurallarla ayrılır. Kalan kök sözlükte varsa kabul edilir.

## 15. "ki"nin Üç Türü, Uyum Dışı Durumlar ve Fiil Çatıları

### 15.1 "ki"nin Üç Türü

- **Bağlaç olan "ki":** Ayrı yazılır. Çıkarıldığında cümlenin anlamı bozulmuyorsa bağlaçtır. "Bir yemek yapmış ki yeme de yanında yat."
- **Sıfat yapan "-ki":** İsmin "-de" hâlinden sonra gelir. "Karşıdaki patika" denince patika tanımlanmış, yani sıfat yapılmış olur.
- **Zamir yapan "-ki":** Bir ismin yerini tutar. "Benim çantamın rengi siyahmış. Seninki ne renk?"

Hoca bir dönem metindeki "ki" eklerini bulmayı ödev olarak verdiğini hatırlatır.

### 15.2 Ünlü Uyumu Dışındaki Durumlar

Türkçede büyük ve küçük ünlü uyumuna uymayan çok durum vardır. Birleşik sözcükler uymaz. "-daş" ("gönüldaş", "meslektaş"), "-yor" ve "-ımtırak" gibi ekler uymaz. "Anne, dahi, elma, kardeş, şişman" kelimeleri uymaz; bunların çoğu dile başka dillerden girmiştir.

### 15.3 Fiil Çatıları

Hoca bunlara ayrıntılı girmez, çünkü biçimbilimsel analiz bu bilgileri zaten söyleyecektir. Yine de çıktıda "geçişsiz fiil" görülünce anlaşılması için kısaca açıklar:

- **Geçişli fiil:** Fiile "neyi, kimi" sorulur veya başına "onu" zamiri getirilir. Cevap alınıyorsa geçişlidir. "Seni duyuyorum." "Kimi duyuyorsun?" "Seni."
- **Geçişsiz fiil:** "Lütfen otur." "Neyi otur?" cevap yok, "onu otur" da anlamsız. Geçişsizdir.
- **Etken:** "Evi güzelce temizledi." "Kim temizledi?" sorusunun özneden cevabı vardır.
- **Edilgen:** "Ev temizlendi." "Kim temizledi?" sorusunun cevabı yoktur.
- Çatılı, çatısız ve dönüşlü fiiller de vardır; hoca bunları geçer.

## 16. Gramer ve Diller: Temel Kavramlar

Aradan sonra konunun rengi değişir. Hocanın göstermek istediği şudur: Elimizde bir dil var. Bu dilin grameri, cümle yapıları, sözlükleri ve dili dil yapan özellikleri verildiğinde tümcesel yapılar (sentential form) nasıl oluşturulur ve dil nasıl modellenir? Bunu gerçek bir doğal dille göstermek imkansızdır. Bu yüzden önce sembolik örneklerle gösterilir, slaydın sonunda gerçek dil örneklerine geçilir.

Elimizdeki alfabe dili oluşturan karakterlerdir. Türkçe için 29 karakterdir. Örneklerde ise a, b, c veya 0, 1 gibi az elemanlı sözlükler kullanılır. Bir gramer, kuralları ve tümcesel yapıları vardır. Tümcesel yapı bu kurallar çerçevesinde oluşabiliyorsa geçerlidir, aksi hâlde geçersizdir.

Gösterimde iki önemli kavram vardır:

- **Söz dizimsel değişken (nonterminal):** Büyük harfle gösterilir. İsim cümlesi, fiil cümlesi, dolaylı tümleç gibi birden fazla yapının arka arkaya gelmesiyle oluşan yapılardır.
- **Uç değişken (terminal):** Küçük harfle gösterilir. Kelimeler, yani tek başına olan kavramlardır.

Yayınlarda semboller değişebilir. Kimi uç değişkenleri a, b, c, 0, 1 diye, kimi u, v, w, y diye gösterir. Anlam aynıdır.

Kuralın genel biçimi $\alpha \rightarrow \beta$ şeklindedir. Hoca bunu "alfa ise beta" diye okur ve anlamını programlama dillerindeki atamaya benzetir: Beta değerini al, alfanın yerine koy. Örneğin bir cümle bir isim cümlesi ile bir fiil cümlesinden oluşuyorsa kural "S → isim cümlesi + fiil cümlesi" olur.

Gramer iki yönde okunabilir: soldan veya sağdan. Sonuç değişmez. Soldan okuma alışkanlığımıza daha yatkın olduğu için kitaplarda ve derslerde hep soldan anlatılır.

Ayrıştırma ağacı iki yönde kurulur:

- **Yukarıdan aşağı (top-down parsing):** "Banu okula gitti." cümlesinden başlanır. "Banu" özne, "okula gitti" fiil cümlesidir. "Okula" da okul (isim) + a (yönelme eki), "gitti" de git + ti (geçmiş zaman eki) diye ayrılır.
- **Aşağıdan yukarı (bottom-up parsing):** Tersi yapılır. "git" ile geçmiş zaman eki birleşir, "okul" ile yönelme eki birleşir. "Okula gitti" fiil cümlesi olur. "Banu" isimle birleşip cümleye ulaşılır.

## 17. Gramerin Biçimsel Tanımı

Hoca genelde bu konuyu tahtada anlattığını, çünkü ancak öyle anlatılabileceğini düşündüğünü söyler. Çevrim içi derste notlarını ekrana geçirip üzerine yazar.

Bir gramer dört bileşenden oluşur:

$$G = \langle V_N, V_T, P, S \rangle$$

- $V_N$: Söz dizimsel değişkenler. Sonlu bir kümedir.
- $V_T$: Uç değişkenler. Sonlu bir kümedir, yani elimizdeki sözlüktür.
- $V_N \cap V_T = \emptyset$: Bu iki küme ayrıktır, aralarında ortak eleman olamaz.
- $P$: Yeniden yazma ve türetme kuralları, $\alpha \rightarrow \beta$. Dile özgü kurallar burada verilir.
- $S$: Başlangıç değişkeni, $S \in V_N$. İşleme cümleden başlanır.

En genel biçimde $V = V_N \cup V_T$ olmak üzere $\alpha \in V^+$ ve $\beta \in V^*$ yazılır.

### 17.1 Artı ve Yıldız Operatörleri

Hoca lisans derslerinden hatırlatır. Bunlar düzenli ifadelerde Kleene operatörleri olarak geçer:

- **Artı ($a^+$):** En az bir kez, istenildiği kadar tekrar eder. a, aa, aaa, ...
- **Yıldız ($a^*$):** Hiç olmayabilir veya istenildiği kadar tekrar eder. Boş, a, aa, aaa, ...

Bu yüzden $\alpha \in V^+$ yazıldığında boşluk çıkarılmıştır. Sol tarafta hiçbir zaman boş küme yoktur, çünkü boş kümeye bir şey atanamaz. Sağ taraf $V^*$ olduğu için boş olabilir.

### 17.2 Dilin Tanımı

Dil (L, language) G gramerine sahiptir. Dildeki tümceler $V_T^*$ elemanıdır, yani tamamı uç değişkenlerden oluşur. Türetme kuralları art arda uygulanarak S'den bunlara ulaşılır:

$$L(G) = \{ w \mid w \in V_T^*,\ S \Rightarrow^* w \}$$

### 17.3 Örnek: $G_1$

$V_N = \{S\}$, $V_T = \{0, 1\}$, $P: S \rightarrow 0S1 \mid 01$ verilmiş. Dili modellemek için önce kurallarla yazılabilen tümcesel yapılar çıkarılır. Başlangıç S'dir. Bir ifadenin tamamı uç değişkense o tümce bitmiştir.

```text
S => 01
S => 0S1 => 0011
S => 0S1 => 00S11 => 000111
```

İç içe devam edilebilir. Sayılara bakılınca bir örüntü görülür: bir 0 bir 1, iki 0 iki 1, üç 0 üç 1. Genelleme şudur:

$$L(G_1) = \{ 0^n 1^n \mid n \ge 1 \}$$

$n=1$ için 01, $n=2$ için 0011, $n=3$ için 000111 elde edilir.

Gerçek dünyada $P$'nin yerine Türkçedeki bütün cümle kuralları, $V_T$'nin yerine sözlükteki kelimeler, $V_N$'nin yerine isim cümlesi, fiil cümlesi, zarf tümleci gibi yapılar gelir.

## 18. Chomsky Hiyerarşisi

Noam Chomsky en ünlü dil bilimcidir. Dilleri dört türe ayırır. Hoca bunu iç içe çemberlerle anlatır. En dıştaki çember sınırsızdır: yazabildiğiniz her şeyi yazarsınız. İçeri doğru gidildikçe kurallar ve kısıtlar gelir, kafanıza göre hareket edemezsiniz.

| Tür | Adı | Kısıt |
|---|---|---|
| Tür 0 | Özyinelemeli sayılabilir (recursively enumerable), kısıtlamasız | Yalnız $\alpha \rightarrow \beta$, $\alpha \in V^+$, $\beta \in V^*$ |
| Tür 1 | Bağlama bağımlı (context-sensitive) | Ek olarak $\lvert\alpha\rvert \le \lvert\beta\rvert$ |
| Tür 2 | Bağlamdan bağımsız (context-free) | Sol tarafta tek bir söz dizimsel değişken |
| Tür 3 | Düzenli (regular) | Sağ taraf boş, tek uç değişken veya uç değişken + söz dizimsel değişken |

Hoca Tür 2 için programlama dillerini örnek verir: kod satırını kafanıza göre yazamazsınız, sözdizimi hatası alırsınız. Tür 3 daha da katıdır, hiç esneklik yoktur. Birçoğumuzun kullandığı düzenli ifadeler (regular expression, regex) bu sınıfa karşılık gelir.

> **Ek bilgi (derste anlatılmadı):** Bu dört sınıfın her biri bir tanıyıcı makine türüne karşılık gelir: Tür 0 Turing makinesine, Tür 1 doğrusal sınırlı otomata, Tür 2 yığınlı otomata, Tür 3 sonlu otomata. Dersteki genişletilmiş geçiş ağları ve sonlu durum makineleri bu çizginin son halkalarıyla ilişkilidir.

## 19. Tür 0: Kısıtlamasız Gramer

Hiçbir kısıt yoktur. Yalnız $\alpha \rightarrow \beta$ kuralları verilir ve sol taraf boş olamaz. Hoca "artık ne yapabiliyorsan yap diyor" der.

**Örnek $G_2$ (slayttan):**

- $V_N = \{S, L, R, A, B, C\}$, $V_T = \{a\}$. Bütün kelimeler yalnız a'dan türer.
- $P$: $S \rightarrow LAaR$, $Aa \rightarrow aaA$, $AR \rightarrow BR \mid C$, $aB \rightarrow Ba$, $LB \rightarrow LA$, $aC \rightarrow Ca$, $LC \rightarrow \lambda$

Dikey çizgi "veya" anlamındadır, λ boş kümedir.

Türetme yöntemi şudur: İfade soldan taranır. Sol tarafı eşleşen bir kural var mı diye önce ikili gruplara bakılır, yoksa bir sembol kaydırılır. Tekli ve üçlü alfa olmadığı için onlara bakılmaz. Eşleşme bulununca ifade değiştirilir ve yeniden soldan başlanır. Bütün semboller uç değişken olunca tümce biter.

```text
S => LAaR       (L yok, LA yok; Aa bulundu)
  => LaaAR      (AR bulundu, C seçildi)
  => LaaC       (aC bulundu)
  => LaCa       (aC bulundu)
  => LCaa       (LC bulundu, boş yazıldı)
  => aa
```

$AR$ için C yerine BR seçilirse başka bir tümce çıkar:

```text
S => LAaR => LaaAR => LaaBR => LaBaR => LBaaR => LAaaR
  => LaaAaR => LaaaaAR => LaaaaC => LaaaCa => LaaCaa => LaCaaa => LCaaaa => aaaa
```

Bu çıktılardan örüntü avlanır: 2, 4, sonra 8, 16 tane a.

$$L(G_2) = \{ a^i \mid i = 2^n,\ n \ge 1 \}$$

Bu modele göre "aba" bu dile ait değildir. Hoca zaten $V_T$ içinde b olmadığını, bunu örnek olsun diye koyduğunu söyler. Tek kelimeli bir dil de olmaz; örneğin amacı Tür 0'da kuralların ne kadar serbest olduğunu göstermektir.

## 20. Tür 1: Bağlama Bağımlı Gramer

Biraz daha içeri girilince kısıt gelir: Kuralın alfa tarafındaki eleman sayısı beta tarafındakinden küçük veya ona eşit olmalıdır.

$$\lvert\alpha\rvert \le \lvert\beta\rvert$$

Hocanın örnekleri:

- $A \rightarrow b$ yazılabilir (1 ≤ 1).
- $Aa \rightarrow b$ yazılamaz (2 ≤ 1 yanlış).
- $A \rightarrow ba$ yazılabilir (1 ≤ 2).

**Örnek $G_3$ (slayttan):**

- $V_N = \{S, A, B\}$, $V_T = \{a, b, c\}$
- $P$: $S \rightarrow aSAB$, $S \rightarrow aAB$, $BA \rightarrow AB$, $aA \rightarrow ab$, $bA \rightarrow bb$, $bB \rightarrow bc$, $cB \rightarrow cc$

Hepsinde beta tarafı alfa kadar veya daha uzundur, bu yüzden Tür 1'dir.

```text
S => aAB => abB => abc

S => aSAB => aaABAB => aabBAB => aabABB => aabbBB => aabbcB => aabbcc
```

Sırada 3 a, 3 b, 3 c, sonra 4 a, 4 b, 4 c gelir.

$$L(G_3) = \{ a^n b^n c^n \mid n \ge 1 \}$$

Yanlış bir yol seçilince uç değişkenlere ulaşılamaz, tıkanılır. Hoca bunu önceki örneğine bağlar: "Gökyüzü, çöp tenekesi, deniz, araba." Kelimeler dile aittir ama cümle değildir. Analizde bir yerde tıkanılır ve yerine konacak bir şey görülmez. Sonuç şudur: Bu kurallar bu cümleyi yazmaya uygun değildir.

**Bir tümce bu dile ait mi?** "abbcc" verilmiş olsun. Ya S'den başlanıp aşağı inilerek yapraklarda bu kelimeler oluşturulmaya çalışılır, ya da bunlar birleştirilerek S'ye ulaşılmaya çalışılır. Ulaşılamıyorsa tümce bu dile ait değildir. Belki de bir İngilizce cümle verilmiştir ve Türkçe gramerde aranıyordur.

## 21. Tür 2: Bağlamdan Bağımsız Gramer

Bir tık daha daralır. Kural şudur: Kuralın sol tarafında her zaman ve her zaman tek bir söz dizimsel değişken bulunur. Hep o tek değişken açılarak ilerlenir.

Hoca bunu programlama dilleriyle anlatır: "a + b = 5" yazılabilir mi? Hayır. Atamanın solunda hep tek bir değişken vardır (bkz. Ders Sonrası Notlar).

**Örnek:** $V_N = \{S\}$. Uç değişkenler v (variable, değişken), c (constant, sabit), aritmetik işaretler ve parantezlerdir.

$$S \rightarrow S+S \mid S*S \mid S-S \mid S/S \mid (S) \mid v \mid c$$

Sağdan türetme örneği şöyledir. Hoca slayttaki türetmenin karışık yapıldığını görüp baştan sağdan yazar:

```text
S => S*S
  => S*(S)
  => S*(S-S)
  => S*(S-v)
  => S*(c-v)
  => v*(c-v)
```

Sonuç, bizim yazdığımız bir aritmetik ifadeden farksızdır. Aynı ifade soldan açılarak da türetilebilir.

## 22. Tür 3: Düzenli Gramer ve Düzenli İfadeler

Son sınıfın tek kuralı vardır: Sol tarafta her zaman tek bir söz dizimsel değişken olur. Sağ taraf ya boştur, ya tek bir uç değişkendir, ya da bir uç değişkeni takip eden bir söz dizimsel değişkendir. Bir sonraki slaytta görülecek düzenli ifadeler bu dille türetilmiş dillerdir.

**Örnek $G_5$ (slayttan):**

- $V_N = \{S, A, B\}$, $V_T = \{0, 1\}$
- $P$: $S \rightarrow 0S \mid 0A \mid 0 \mid \lambda$, $A \rightarrow 0B$, $B \rightarrow 1S$

Bütün kurallar Tür 3 şartına uyar: uç değişken + söz dizimsel değişken, uç değişken veya boşluk.

```text
S => 0S => 00
S => 0A => 00B => 001S => 001
S => 0S => 00A => 000B => 0001S => 00010A => 000100B => 0001001S => 00010010
```

Burada önceki türler kadar kolay bir genelleme yapılamaz. Bunu sözle söylemek yetmez, düzenli ifadeyle göstermek gerekir. Yazılan ifade bir girdi için sağlanıyorsa o tümce bu gramere aittir; sağlanmıyorsa ya yazılan ifade yanlıştır ya da tümce bu gramere ait değildir.

Hoca dersi ilk anlatırken şu ifadeyi yazmıştır:

```text
(0)*(001(0)*)^n(0)*        n >= 0
```

Tecrübe arttıkça daha kısa olanını yazar. İkisinin de aynı işi yaptığını düşünür:

```text
((00)+1)*0*
```

### 22.1 Birinci İfade ile Üç Tümce

- **"00":** $n=0$ alınır, parantez hiç çalışmaz. Baştaki ve sondaki yıldızlardan birer 0 gelir. Veya biri hiç çalışmaz, diğeri iki kez çalışır.
- **"001":** $n=1$ alınır. Parantezin içine bir kez girilir, yıldızların hiçbiri çalışmaz.
- **"00010010":** Burada 001 örüntüsü iki kez geçer. $n=2$ alınır. Baştan bir 0 alınır, parantez iki kez çalışır ve 001 001 üretir, çıkarken son yıldızdan bir 0 alınır.

### 22.2 İkinci İfade Üzerine Sınıf Tartışması

Hoca sınıfa sorar: Daha kısa olan ifade bu üç tümceyi üretebilir mi?

**Soru:** Bir öğrenci üçüncü tümceyi üretmeyeceğini söyler: "Çift sıfırlar çifter gittiği için, bizim 3 sıfırımız var, üretemez." Başka bir öğrenci üretebileceğini savunur ve kalemle gösterir: ilk 0 için son yıldızdaki 0 çalışır, ilk parantez boş geçilir; 001 için parantez çalışır ve böyle devam edilir.

**Cevap:** Hoca ikinci öğrencinin anlatımındaki sorunu gösterir: Düzenli ifade akan bir girdi üzerinde çalışır. Parantezi atlayıp sondaki 0'ı aldıktan sonra sola geri dönülemez. Geri dönebilmek için ifadenin bütününün dışına bir yıldız daha koymak gerekir. O zaman içine bir, iki, üç, dört, istendiği kadar girilebilir ve girdi bitene kadar çalışır:

```text
(((00)+1)*0*)*
```

"00010010" bu hâliyle üretilir: Birinci turda parantez atlanır, 0 alınır. İkinci turda 001 001 üretilir, son turda 0 alınır. Yıldız konmazsa üretilemez.

> **Hocanın vurgusu:** Kod yazıp girdi işlerken bir bölümü atlayıp ilerleyince aynı noktaya geri dönülemez. Geri dönülecekse bunu ifadenin kendisi sağlamalıdır.

### 22.3 Sağ ve Sol Doğrusal Okuma

Sağ doğrusal (right-linear) okumada yerleştirmeye sağdan, sol doğrusal (left-linear) okumada soldan başlanır. Slaytlarda aynı iki tümcesel yapı ($W_1$, $W_2$) soldan ve sağdan türetilmiştir, aynı sonuç çıkar. Hoca öğrencilerin bu örneklere bakmasını ister.

> **Hocanın vurgusu:** Kod yazılıyorsa ya soldan türetecek ya da sağdan türetecek şekilde yazılır. Kafasına göre bir sağdan bir soldan olmaz.

<!-- BELİRSİZ: W1, W2 ve sağ/sol doğrusal slaytlarının içeriği altyazıda okunmuyor. -->

## 23. Yukarıdan Aşağı ve Aşağıdan Yukarı Ayrıştırma

### 23.1 Yukarıdan Aşağı Örnek

Gramer verilmiş ve ağacı yukarıdan aşağı üretmek istenmiş. S ile başlanır. S'nin yerine $0S0$, sonra $1S1$, sonra $0A0$ konmuş. Burada A'nın yerine işi bitirecek bir şey gerekir: A ya 01 ya da 10 olabilir. Diyelim 01 kondu. Ağaç soldan okununca tümcesel yapı çıkar: 0, 1, 0, 0, 1, 0, 1, 0.

Bir tümce için ağacın içinde ilerleyerek onu oluşturabiliyorsak tümce gramere uygundur.

### 23.2 Aşağıdan Yukarı Deneme

Hoca sonra verilen bir tümce için tersini dener: Parçalar birleştirilip S'ye ulaşılmaya çalışılır. Örneğin sondaki "01" için A yazılır. Ardından "0A1" diye bir kural var mı diye bakılır. Yoktur. Öyleyse bu yol doğru değildir. Bir öğrenci "1A0A" gibi başka bir birleştirme önerir ve deneme yapılır; A ile başlayan kural olmadığı için oradan da S çıkmaz. Hoca verdiği tümceyi kafadan seçtiğini söyler. Sonuç: Bütün denemeler yapılıp S'ye varılabilirse tümce bu dile aittir, varılamazsa değildir.

<!-- BELİRSİZ: Bu örnekte hocanın sorduğu tümce ve gramerin tamamı slaytta; altyazıda kısmen okunuyor. -->

### 23.3 Maksimum Çakışma ile Arama

Yukarıdan aşağı örnekte (slaytta) S'nin her kuralı açılır. Bazı dallar kural gereği ilerleyemez ve durur, bazıları uç değişkene iner. Yeni tümce oluşturmak için yeni kural eklenir.

> **Hocanın vurgusu:** Yukarıdan aşağı gitmek her zaman çok daha kolaydır. Zor olan aşağıdan yukarı gitmektir.

Aşağıdan yukarı örnek bunu gösterir. Kurallar ve "aababbaba" gibi bir dizge verilmiş; dizgenin dile ait olup olmadığı sorulmuştur. Çalışma şöyledir:

1. Dizge üzerinde ikili parçalar taranır. Bir kuralın sağ tarafına uyan her parça için o kuralın sol tarafı yazılarak yeni bir aday ifade oluşturulur.
2. Örnekte böylece 6 aday çıkar.
3. Her aday için kurallarla en fazla kaç sembolde çakıştığı hesaplanır. Örneğin iki adayda çakışma 2'dir, birinde 3'tür.
4. En büyük çakışmayı veren aday önce denenir. Eşitlik varsa seçim kodlayana kalmıştır; hoca hep en son bulunanla devam eder.
5. Bir yol tıkanırsa (örneğin "SB" diye bir kural yoksa) geri dönülür ve sıradaki aday alınır.
6. Sonunda "aS → S" ile S'ye ulaşılır. Bu, dizgenin dile ait olduğunu ve ağaçta hangi aşamalardan geçildiğini gösterir.

Kural sayısı arttıkça olasılıklar da artar. Kod ne kadar iyi optimize edilirse cevap o kadar hızlı gelir. Söz dizimsel analiz arka planda tam olarak bunu yapar: Bir cümlenin dile ait olup olmadığını anlamak için cümleyi o dilin kurallarına göre yukarıdan veya aşağıdan ayrıştırır.

<!-- BELİRSİZ: Bu örneğin kural listesi ve aday ifadeleri slaytta; altyazıda tam okunmuyor. Dizge kısa nottaki gibi yazıldı. -->

## 24. Gerçek Dil Örnekleri

### 24.1 Gramer

Basit bir İngilizce gramer ve sözlükler verilir. Hoca bunları ekrana yazar ve standart etiketleri açıklar: S (cümle), NP (noun phrase, isim öbeği), VP (verb phrase, fiil öbeği), Aux (yardımcı fiil), Det (belirleyici), Noun, Verb, ProperNoun (özel isim). Bunlar söz dizimsel değişkendir.

```text
S       -> NP VP | Aux NP VP | VP
NP      -> Det Nominal | ProperNoun
Nominal -> Noun
VP      -> Verb | Verb NP

Noun : book, flight, meal, chair, pen ...
Verb : book, include, go, paint ...
Aux  : does, is, do, are ...
Det  : the, a, this, that ...
```

### 24.2 Yukarıdan Aşağı: "Does this flight include a meal?"

Yukarıdan aşağı, soldan sağa ve derinlik öncelikli (depth-first) yapılır. Derinlik öncelikli arama, başlanan noktadan gidilebildiği kadar derine inmektir: başlangıç cümledir, en derin yerler yapraklardır.

1. Gelen ilk kelime "does". S → NP VP denenir. NP → Det Nominal için Det sözlüğüne bakılır, "does" yoktur. NP → ProperNoun için özel isim sözlüğüne bakılır, yine yoktur. Bu kuralla devam edilemez.
2. S → Aux NP VP denenir. "does" Aux sözlüğünde vardır, eşleşir.
3. Sırada "this" var. NP → Det Nominal: "this" Det sözlüğünde vardır.
4. "flight" Nominal, yani Noun. Noun sözlüğünde vardır.
5. "include" için VP. VP → Verb denenir, "include" fiil sözlüğünde vardır. Ama arkadan "a" gelir ve bu kural fiilde bitmiştir.
6. VP → Verb NP alınır. NP → Det Nominal: "a" Det, "meal" Noun.

Bütün kelimeler yapraklara oturur. Hoca bunu Türkçeye bağlar: Türkçe bir cümlede kelimelerin ekleri de ilgili sözlüklerde bulunup ağaçta açılır. Kelimelerden biri fiil sözlüğünde olmasaydı bu cümle için "İngilizce değil" denirdi. Sözlüğe eklenmesi unutulmuş olabilir veya kelime dile yeni girmiş olabilir.

Hocanın örneği COVID'dir. Bu kelime daha önce hayatımızda yoktu. Sözlüklere eklenmezse "Ayşe COVID'e yakalandı." cümlesi Türkçe değil diye işaretlenir. Özel isim olarak sözlüğe yerleştirilirse cümle analiz edilir.

### 24.3 Aşağıdan Yukarı: "Book that flight"

"Book" kelimesi iki sözlükte de vardır: Noun sözlüğünde kitap, Verb sözlüğünde rezervasyon yapmak anlamındadır (bkz. Ders Sonrası Notlar).

**Noun olarak alınırsa:** "that" Det, "flight" Noun ve Nominal olur. Det ile Nominal birleşince NP olur. "Book" Nominal olur. Kurallarda Nominal'i takip eden NP diye bir şey yoktur, ikisi bağlanamaz. Bu ağaç cümlenin dile ait olmadığını söyler.

**Verb olarak alınırsa:** "that flight" yine NP olur. Verb ile NP'yi birleştiren kural VP'dir. S → VP de vardır. Cümleye ulaşılır.

> **Hocanın vurgusu:** Kelime belirsizse (ambiguous) farklı türleriyle de analiz yapılmalıdır. İlk denemede olmadı diye durulursa yanlış bir söz dizimsel analiz yapılmış olur.

Slaytta Türkçe için hazırlanmış "İG, FG" gibi etiketlerin olduğu ilkel bir örnek de vardır. Hoca bunun literatüre aykırı olduğunu, kimsenin bilmeyeceğini söyler ve üzerinde durmaz. Slaytta başka bir örnek de vardır: "A flight from Indianapolis".

> **Hocanın vurgusu:** Bu terminoloji hocanın uydurduğu değildir, POS etiketleridir, bütün dünya böyle bilir. NP görülünce isim öbeği, Det görülünce belirleyici, Aux görülünce yardımcı fiil anlaşılır. Standart etiketler kullanılmalıdır.

## 25. Genişletilmiş Geçiş Ağları

Söz dizimsel gösterim her zaman ağaç olmak zorunda değildir. Genişletilmiş geçiş ağı (Augmented Transition Network, ATN) adı verilen bir ağla da gösterilebilir. Hoca zor olmadığını, durumlardan (state) ve durumdan duruma geçiş şartlarından oluştuğunu söyler. Bir başlangıç durumu (start) ve bir bitiş durumu (stop, final) vardır. Bitiş durumu kimi kaynakta S ile, kimi kaynakta çift halka ile gösterilir.

### 25.1 Küçük Otomat Örneği

Hesaplama teorisi dersinden hatırlanacak 4 durumlu ($q_1$-$q_4$) bir otomat verilir. Kural şudur: Okların yönünde hareket edilir, döngüler olabilir, girdinin tamamı işlenmiş olmalı ve bitiş durumunda bitilmelidir. Girdi bitiş durumuna gelmeden biterse veya bitiş durumuna gelindiği hâlde girdi bitmemişse kabul edilmez.

- **"b":** $q_1$'den b ile $q_4$'e gidilir. Bitiş durumu, girdi bitti. Tanınır.
- **"abba":** a, b, b ile $q_2$'ye gelinir. Sonraki geçiş epsilon'dur: hiçbir şey okumadan $q_3$'e geçilir. a ile $q_4$'e gelinir. Tanınır.
- **"baab" gibi bir girdi:** b ile $q_4$'e gelinir, ama geriye "aab" kalır. Bitiş durumundan geri dönüş yoktur. Tanınmaz.
- **"abb" ile başlayıp "a" sonra "b" gelen bir girdi:** $q_4$'e gelindikten sonra b okunacak bir yol yoktur. Tanınmaz.

<!-- BELİRSİZ: Otomatın geçişlerinin tamamı ve slayttaki girdi listesi çizimde; altyazıdan yalnız bu kadarı okunuyor. -->

### 25.2 "Ali camı kırdı" Örneği

Önce biçimbilimsel analiz yapılır: Ali (özel isim, özne), cam (isim), ı (ek), kır (fiil; aynı zamanda isim), dı (geçmiş zaman eki).

Ağ basitleştirilmiş olarak şöyledir: Cümle ya özne + yüklem, ya da özne + nesne + yüklemden oluşur ve biter. Alt ağlar da şunlardır:

- **Özne:** isim sözlüğünde olmalı.
- **Nesne:** isim + nesne eki. Bir isim kaç ek alıyorsa ağ o kadar karmaşıklaşır.
- **Yüklem:** fiil + zaman eki. Burada da ek sayısı kadar geçiş olur.

İşleyiş şöyledir:

1. "Ali" özne ağına gider. İsim sözlüğünde vardır, özne tamamlanır, cümle ağında $q_1$'e geçilir.
2. "cam" önce yüklem olarak denenir. Fiil sözlüğünde yoktur, sonlanamaz. Geri dönülür.
3. "cam" nesne olarak denenir. İsim sözlüğünde vardır. "-ı" nesne eki sözlüğünde vardır. Nesne tamamlanır, $q_2$'ye geçilir.
4. "kır" fiil sözlüğünde, "-dı" zaman eki sözlüğünde vardır. Yüklem tamamlanır.
5. Cümle ağı bitiş durumuna gelir ve girdi biter. Cümle doğrudur.

Ağaç gösteriminden farkı yoktur. Hoca akademik kaynaklarda bu gösterimin daha az yer kapladığı için tercih edilebileceğini söyler.

### 25.3 Döngü: Sıfatlar

Durumlar üzerinde döngü olabilir. Hoca "top" kelimesinin önüne onlarca sıfat konabileceğini söyler: "yırtık, kırmızı, büyük, ağır, pütürlü, ekose desenli top". Bir ismin önüne kaç sıfat geleceği bilinmez. Sıfat sayısı kadar durum yazmak yerine aynı durumda döngü yapılır: Gelen kelime sıfat sözlüğünde varsa durum kendine döner. "Top" sıfat sözlüğünde yoktur, isim durumuna geçilir. İsim sözlüğünde vardır ve sonlanır.

## Dersin Toparlaması

Bu ders, bir kelimenin içinden bir dilin bütününe uzanan bir çizgi çizer. İlk bölümde dil analizinin seviyeleri hatırlanır, biçim bilimde ekler, kök ve gövde, biçimbirim türleri ve belirsizlik işlenir. Araçların bütün çözümleri verdiği, doğruyu seçmenin ise bağlam ve bağlılık analizi gerektirdiği görülür.

İkinci bölümde gramer biçimsel olarak dört bileşenle tanımlanır ve diller Chomsky hiyerarşisine göre sınıflanır. Her türde kısıt artar: Tür 0'da yalnız sol tarafın boş olmaması gerekir, Tür 1'de sol taraf sağdan uzun olamaz, Tür 2'de sol tarafta tek değişken bulunur, Tür 3'te sağ taraf en katı biçimi alır. Ardından bir cümlenin dile ait olup olmadığının türetme, ayrıştırma ağacı ve geçiş ağıyla nasıl sınandığı görülür.

Bir sonraki adım Tür 3'ün pratik karşılığı olan düzenli ifadelerdir.

## Ders Sonrası Notlar

> **Ders sonrası not:** `((00)+1)*0*` ifadesi "00010010" dizgesini üretmez, çünkü `(00)+` yalnız çift sayıda 0 üretir. Hocanın eklediği dış yıldızla `(((00)+1)*0*)*` hâli üretir. Bu dil için uzunluğu 11'e kadar bütün dizgeler python ile karşılaştırıldı: dış yıldızlı ifade, birinci ifade ve daha kısa olan `(0*001)*0*` aynı dizgeleri kabul eder. $G_5$'in türettiği dizgelerle de (uzunluk 8'e kadar) birinci ifade birebir tuttu.

> **Ders sonrası not:** Hoca biçimbilimsel analiz yöntemlerini anlatırken önce bildirimsel ve yordamsal yöntemleri karıştırdı, sonra "aslında yanlış söyledim" diye düzeltti. Doğrusu 14. bölümde yazıldığı gibidir.

> **Ders sonrası not:** Hoca "determiner" için "bağlaç" dedi. Bağlaç "conjunction"dır. "Determiner" belirleyicidir.

> **Ders sonrası not:** Hoca Tür 0 diller için "ön yinelemeli sayılabilir" dedi. Doğru terim özyinelemeli sayılabilir (recursively enumerable) dildir.

> **Ders sonrası not:** Hoca NLTK'yı Stanford Üniversitesi'nin aracı olarak andı. NLTK Pennsylvania Üniversitesi'nde geliştirilmiştir (Bird ve Loper). Stanford'un aracı Stanford CoreNLP'dir.

> **Ders sonrası not:** Hoca sıfır biçimciği "hiçbir ek almadan tek başına kullanılabilenler" diye tanımladı. Dil biliminde sıfır biçimbirim, anlamı olan ama ses veya yazı karşılığı olmayan biçimbirimdir. Örneğin "geldi"de üçüncü tekil kişiyi gösteren görünür bir ek yoktur. Hocanın tanımı daha çok bağımsız biçimbirime yakındır.

> **Ders sonrası not:** "geldik" kelimesi portmanto için iyi bir örnek değildir: Geçmiş zamanı "-di", birinci çoğul kişiyi "-k" taşır, yani iki ayrı ek vardır. Portmantoda iki anlam tek ekte birleşir. İngilizcedeki "-s" bunun doğru örneğidir.

> **Ders sonrası not:** Hoca "a + b = 5" örneğini gramerin sol tarafındaki tek değişkenle eşleştirdi. Bu bir benzetmedir: Programlama dilinin kendi gramerinde kuralın solunda gene tek söz dizimsel değişken vardır, atamanın solu ise bu kuraldan ayrı bir şeydir. Ayrıca programlama dillerinin söz dizimi bağlamdan bağımsızdır, ama "değişken önce tanımlanmış olmalı" gibi kurallar bağlama bağlıdır ve derleyicide ayrı bir aşamada denetlenir.

> **Ders sonrası not:** Hoca Svahili için "çok küçük bir kitle tarafından kullanılan" dedi. Svahili Doğu Afrika'da yaygın kullanılan bir ortak dildir. Hocanın 3000-4000 dil sayısı da güncel değildir; güncel tahminler yaklaşık 7000'dir (bkz. Ders 1).

> **Ders sonrası not:** Hoca ağ türünü "Augmented Network Translation Grammar" diye adlandırdı. Doğru ad Augmented Transition Network'tür. Türkçesi söylediği gibi genişletilmiş geçiş ağıdır.

> **Ders sonrası not:** "Book" fiili burada "kayıt olmak" değil, "rezervasyon yapmak, yer ayırtmak" anlamındadır. Hoca "kayıt olmak" dedi.

> **Ders sonrası not:** Altyazıda bozuk geçen terimlerin doğru yazımları: "Shomsky", "Narmu Shomsky" = Noam Chomsky; "NLTL kit" = NLTK; "LSTM" (sözcük birim için) = lexeme, LSTM bir sinir ağı modelidir; "bronluk korpus" = Brown corpus; "embedding durumlar" = ambiguous durumlar; "Santos" = sentence; "Hidden Markov" için "D-Dimarkov"; "clini" = Kleene; "tribank" = treebank; "ruled" = root; "word phrase" = verb phrase; "Excellary carry" = auxiliary; "kilgen, kili" uyum dışı ek listesinde okunmuyor; "word1vec" burada büyük ihtimalle Word gibi bir kelime işlemcinin yanlış yazımıdır.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
