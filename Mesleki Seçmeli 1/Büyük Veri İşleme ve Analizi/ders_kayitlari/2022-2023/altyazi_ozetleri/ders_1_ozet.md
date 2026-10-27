# Ders 1 Çalışma Özeti

Tarih: 1 Mart 2023 Çarşamba. Online ders (Zoom), saat 09.00. Dersin ilk bölümü (işleyiş ve kurallar) Türkçe, giriş anlatımı İngilizce. Hoca, gelecek haftalardan itibaren dersin tamamen İngilizce işleneceğini söyledi.

## Genel Konular

- Dersin işleyişi, değerlendirme ve takvim.
- Ders kitabı: Mining of Massive Datasets (MMDS). Kitabın web sitesi, slaytlar ve videolar.
- Büyük verinin (big data) kaynakları ve neden özel algoritmalar gerektirdiği.
- Dağıtık depolama (distributed storage): parçalama ve kopyalama (replication).
- Veriden bilgi çıkarma: tanımlayıcı (descriptive) ve tahmine dayalı (predictive) yöntemler.
- Verinin gerçek hayatı yansıtması gerekliliği.
- Büyük verinin zorlukları, veri türleri (modality) ve bir büyük veri sisteminin bileşenleri.
- NoSQL ve ilişkisel veritabanı farkı.
- Dersin kapsadığı problem ve veri türleri: yüksek boyutlu veri, graf verisi, sonsuz (akış) verisi.
- Soru-cevap: Veri kopyalama neden yapılır?

## Hocanın Özellikle Vurguladığı Kısımlar

- Değerlendirme (ekrandaki "important dates" belgesi):
  - 1. vize (midterm): %30, 8. hafta, 19 Nisan 2023.
  - Vize mazeret (makeup): 14. hafta, 31 Mayıs 2023.
  - Final: %40, final haftası.
  - Dönem projesi (term project): %30. Bir veya iki kişilik gruplarla yapılır.
- Proje önerisi (term project proposal): 4. haftada (gecikirse 5. haftada) bir sayfalık öneri istenecek. Öğrenciler, işlenecek konularla ilgili proje fikri ve kullanılacak veri setlerini araştıracak.
- Başarı notu 40'ın altında olan öğrenci dersten FF ile kalır. 40, CC'ye karşılık gelmez (yönetmelik notu).
- Derse katılım: Üniversitenin istediği oran %75. Hoca en az %60 katılım bekliyor. Kayıtlar sonradan izlenebilse de derse katılım isteniyor.
- Ders sayfası duyurular için takip edilmeli. Hoca, derslerden bir gün önce sayfaya bakılmasını istedi. Ders sayfası ve kitap sitesi linkleri chatte paylaşıldı.
- Ders, Stanford'da verilen "Mining Massive Data Sets" dersinin içeriğini temel alıyor. Kitabın tüm bölümleri yazarlar tarafından online yayımlanmış. Satın almaya gerek yok.
- Tezsiz yüksek lisans öğrencileri lisans programındaki dersleri alsalar bile bunu kendi programlarına saydıramazlar (Fen Bilimleri Enstitüsü ile teyit edildi).
- Veri kopyalama (replication) güvenlik için değil, erişilebilirlik (availability) için yapılır.

## Kısa Tekrar Notları

- Büyük veri tek bir bilgisayara sığmaz. Dağıtık veritabanlarında veya veri merkezlerinde (data center) çok sayıda sunucuda saklanır.
- Büyük dosya küçük parçalara bölünür. Her parça birden fazla sunucuda kopyalanır. Kullanıcı dosyayı istediğinde sistem parçaları toplayıp bütün dosyayı verir.
- Tanımlayıcı yöntemler: Veriyi anlatan örüntüleri (pattern) çıkarır. Örnek: ortalama, standart sapma, en büyük ve en küçük değer.
- Tahmine dayalı yöntemler: Geçmiş veriden model kurar, modelle geleceği tahmin eder. Örnek: öneri sistemleri, hava durumu tahmini, finansal tahmin.
- Çıkarılan örüntüler geçerli (valid), faydalı ve beklenmedik durumları yakalayabilen nitelikte olmalı. Ayrıca açıklanabilir olmalı ki insanlar sonuçlara güvenip harekete geçebilsin.
- Veri gerçek hayattan gelmeli, zaman ve boyut açısından yeterince büyük olmalı. Sentetik veriden çıkarılan bilgi anlamsız olabilir.
- Büyük veri işlemlerinde basit `get` / `put` sorguları kullanılır. Karmaşık SQL sorguları ilişkisel veritabanlarına (küçük ölçekli veri) özgüdür.
- Ders istatistik, makine öğrenmesi ve veritabanı sistemlerinin kesişimindedir. Veritabanı tarafında NoSQL ve dağıtık dosya sistemleri kullanılır.

## Detaylı Açıklamalar

### Dersin hedefi

- Büyük veri işleme ve analizi tekniklerini öğrenmek.
- Bu teknikler için kullanılan algoritmaları öğrenmek.
- Algoritmaları bir problem üzerinde dönem projesiyle uygulamak.
- Gelecek hafta 1. ve 2. bölümle (chapter 1-2) başlanacak, bölümler sırayla işlenecek.

### Büyük verinin kaynakları

- Akış (streaming) uygulamaları, müzik verisi, cep telefonu kullanımı, sosyal ağlar.
- Elektronik bilim (e-science) verisi ve dijital kütüphaneler.
- Amaç: Biriken veriden bilgi çıkarmak, bu bilgiyi hayatı kolaylaştırmak ve gelecek tahmini için kullanmak.
- Bunun için veri saklanmalı, yönetilmeli ve analiz edilmeli.

### Dağıtık depolamanın yönetimi

- Bir dosya veri merkezine yazıldığında birden fazla sunucuda kopyası tutulur.
- Dosya çok büyükse küçük parçalara bölünür ve parçalar farklı sunuculara dağıtılır.
- Yönetim sistemi her kopyanın ve parçanın nerede olduğunu bilmelidir.
- Kopyalar ve parçalar dağınık dururken bile veri analiz edilebilmelidir. Bu ders bu analiz için algoritmaları öğretir.

### Büyük verinin boyutları

- Zorluklar:
  - Ölçeklenebilirlik (scalability): Veri çok sayıda sunucuya dağıtılmalı ki hızlı analiz edilebilsin.
  - Akış verisi: Veri sisteme sürekli gelir. Örnek: deprem bölgesindeki sensörlerden gelen sismik sinyal. Artçı deprem olup olmadığını anlamak için sürekli analiz gerekir.
  - Bağlam (context): Verinin üretildiği zaman ve yer kaydedilmeli.
  - Veri kalitesi: Örneğin sensörün doğru çalışıp çalışmadığı.
- Veri türleri (modality): yapılandırılmış veri, sosyal ağ verisi, metin, çoklu ortam (video, resim, ses), sinyal verisi.
- Kapsamlı bir büyük veri sisteminin işlevleri: veri toplama, analize hazırlama, temsil etme, model çıkarma ve akıl yürütme (reasoning), görselleştirme.

### Dersin kapsadığı yöntemler ve problemler

- Etiketli veri üzerinde büyük veri için tasarlanmış denetimli öğrenme (supervised learning).
- MapReduce, akış verisi algoritmaları, tek bellekte değil birden fazla makinede duran veriyi işleyen algoritmalar.
- Gerçek dünya problemleri:
  - E-ticaret siteleri için öneri sistemleri (recommender systems).
  - Fiziksel marketler için pazar sepeti analizi (market basket analysis).
  - İstenmeyen içerik tespiti (spam detection).
  - Kopya belge tespiti (duplicate document detection).
- Veri türüne göre problemler:
  - Yüksek boyutlu veri: kümeleme (clustering), boyut indirgeme (dimensionality reduction).
  - Graf verisi: spam tespiti, topluluk tespiti (community detection), sıralama (ranking).
  - Sonsuz veri: akışlar üzerinde sorgular, akış filtreleme.
- Uygulama çıktıları: büyük veride çalışan öneri sistemleri, ilişki kuralları (association rules) veya kopya belge tespiti kullanan karar destek sistemleri.

### Soru-cevap: Veri kopyalama neden yapılır?

- Örnek: Google Drive veya Dropbox gibi dağıtık depolama sistemleri.
- Bu sistemler, yüklenen dosyanın her zaman erişilebilir olacağını taahhüt eder.
- Bunun için dosyanın birden fazla kopyası farklı fiziksel sunuculara, mümkünse farklı konumlara konur.
- Bir sunucuya bir şey olursa diğer kopyadan erişilir. Tek kopya olsaydı o sunucu bozulunca dosyaya erişilemezdi.
- Neredeyse tüm dağıtık depolama sistemleri kopyalama yapar.

### Soru-cevap: Başka bölümün seçmeli dersinde sorun

- Bir öğrenci, başka bölümün açtığı seçmeli derste hocanın derse gelmediğini sordu.
- Üniversite son yıllarda öğrencilerin diğer bölümlerin seçmeli derslerini alabilmesine izin veriyor.
- Derste bir sorun olursa öğrenci, dersin ait olduğu bölümün başkanına e-posta yazma hakkına sahiptir.
- Dersi bırakıp başka seçmeliye geçmek isteyenler, bölüme dilekçe ile başvurabilir.

### Ders sonrası notlar

- Hoca kendini bölüm başkan yardımcısı olarak tanıttı. Ekrandaki belgede dersin hocası "Assoc. Prof. Dr. Mehmet S. AKTAŞ" olarak yazıyor.
- Kayıtta 00:34:24 civarındaki bir bölüm ve 00:48:26 civarı bozuk (döngüye girmiş altyazı). Bu kısımlar özetlenmedi.
- Hoca "Mining Massive Data Sets" dersinin adını söylerken altyazıda kelimeler karışmış. Doğru ad: Mining of Massive Datasets (Stanford CS246).

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
