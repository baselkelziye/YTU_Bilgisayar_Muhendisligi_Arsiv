# Ders 2 Çalışma Özeti

## Genel Konular

- Tanışma, dersin işleyişi ve değerlendirme sistemi.
- Web verisinin yapısı: hypertext, papyon (bow-tie) yapısı, statik, dinamik, gizli (hidden) ve anlamsal (semantic) web.
- Web verisinin büyüklüğü, karmaşıklığı, mahremiyeti (privacy) ve çelişkili (adversarial) bilgi içermesi.
- Web madenciliğinin amacı ve kalabalığın bilgeliği (wisdom of crowds) örnekleri.
- Veritabanından veri çekme (data retrieval) ile bilgi erişimi (information retrieval, IR) farkı.
- Veri, bilgi, kavrayış ve bilgelik sırası (data, information, knowledge, wisdom).
- Web'de IR'nin zorlukları, tarayıcı (crawler), ters indeks (inverted index), TF-IDF.
- IR başarı ölçütleri: kesinlik (precision) ve duyarlılık (recall), çeşitlilik (diversity).
- Doküman gösterimi: kelime torbası (bag of words).
- İnternet ve web farkı; link, hyperlink, HTTP, HTML, URL, anchor text kavramları.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ders, Bing Liu'nun "Web Data Mining" kitabını takip ediyor. Kitabın PDF'i ve yazarın slaytları internette var.
- Değerlendirme: vize, tek kişilik dönem projesi ve final.
  - Dönem projesi notu vize kadar etkili. Final %40.
  - 4. veya 5. haftada bir sayfalık proje önerisi (proposal) istenecek. Her öğrenci önerisini yaklaşık 5 dakikada sunacak.
  - Öneri kabul edilirse proje 5. haftadan 14. haftaya kadar sürecek. Sunumlar 14. haftada.
  - Proje, verilen konu başlıklarından birinde bir uygulama geliştirmek. Öneride dil, amaç, yöntem ve zaman planı (timeline) olacak. Hoca bir şablon form paylaşacak.
- Derslere en az %70 katılım şartı var. Sistem katılımı raporluyor.
- Hoca etkileşim istiyor: sorularınızı chat yerine mikrofonla sorun, ara ara geri bildirim verin.
- Ders salı 9-12 arası, 45-50 dakikalık iki oturum halinde.
- Web'de recall genellikle hesaplanamaz. Bu yüzden web aramasında ağırlıklı ölçüt precision.
- İyi bir arama motoru hem doğru hem çeşitli sonuç getirmeli. İlk 10 sonucun hepsi aynı alan adından (domain) gelmemeli.
- Gelecek hafta: birliktelik kuralları (association rules) ve sıralı örüntüler (sequential patterns), kitabın 2. bölümü. Hedef, dönem sonunda fikir madenciliği (opinion mining) ve duygu analizine (sentiment analysis) kadar gelmek.

## Kısa Tekrar Notları

- Web verisi: yapısız (unstructured) veya yarı yapılı (semi-structured), hypertext, dağıtık.
- Hypertext: bir metnin başka bir metne link vermesi. Bu linkler yönlü bir graf oluşturur.
- Papyon yapısı (2000 çalışması):
  - Core: birbirine çok bağlı sayfalar.
  - IN: link veren ama link almayan sayfalar.
  - OUT: link alan ama dışarıya link vermeyen sayfalar.
  - Tendrils: yalnız IN'den link alan veya yalnız OUT'a link veren sayfalar.
  - Kopuk bileşenler (disconnected components): kendi içinde bağlı, dışarıya kapalı gruplar.
- Statik web: URL'nin karşılığı olan dosya değişmez. İndekslenebilir, arama motoruyla aranabilir.
- Dinamik web: sayfa, istek geldiği anda bir script ile oluşturulur. Örnek: haber siteleri.
- Hidden web: yalnız bir sitenin kendi arama kutusundan erişilebilen içerik.
- Semantic web: RDF, OWL gibi XML tabanlı dosyalar. Uygulamaların çıkarım yapmasını sağlar.
- Precision $= \dfrac{|A \cap B|}{|B|}$, recall $= \dfrac{|A \cap B|}{|A|}$. Burada $A$ ilgili (relevant) dokümanlar, $B$ getirilen (retrieved) dokümanlar.
- Yaygın ölçüt: ilk 10 sonuçta precision (precision at 10).
- Ters indeks: kelime ve o kelimeyi içeren sayfaların bağlı listesi (linked list; altyazıda "link list").
- Bag of words: kelime sırası ve doküman yapısı kaybolur, ama basit ve az yer kaplar.

## Detaylı Açıklamalar

### Hocanın tanıtımı ve dersin kapsamı

- Hoca: Prof. Dr. Mehmet Sıddık Aktaş. Çalışma alanları: büyük veri işleme ve analizi, bulut bilişim, web madenciliği, ölçeklenebilir makine öğrenmesi, yazılım mühendisliği.
- Ders kapsamında şu sorulara cevap aranacak:
  - Web verisi nasıl toplanır ve indirilir?
  - Nasıl indekslenir?
  - Arama sonuçları önem sırasına göre nasıl sıralanır (ranking)?
  - Sayfalarda metin madenciliği (text mining) ve duygu analizi nasıl yapılır?
  - Link analizi ile önemli sayfalar nasıl bulunur? Örnek: PageRank.
  - Sosyal ağ analizi (social network analysis) metrikleri nelerdir?
- Makine öğrenmesi teknikleri dersin başında giriş düzeyinde hatırlatılacak. Amaç, bu tekniklerin web verisine uygulanmasını göstermek.

### Web'in kısa tarihi

- 1990: CERN'de Tim Berners-Lee, araştırma grubunda bilgi paylaşımı için basit bir HTTP sunucusu ve HTML'in ilk basit sürümünü geliştirdi. Uygulama komut satırından çalışıyordu.
- 1992-93: ilk tarayıcılar (browser) geliştirildi.
- 1993: NCSA'da geliştirilen Mosaic tarayıcısı web'in yaygınlaşmasını sağladı. Tarayıcı, HTTP ile sayfa ister ve HTML'i ekranda gösterir (render).
- 1993-2000: kurumlar verilerini web'de paylaşmaya başladı. Sayfalar merkezi bir kontrol olmadan birbirine link veriyor.

### Papyon yapısı

- 2000 yılında yapılan bir çalışmada web'in o anki link yapısı incelendi ve papyona benzetildi.
- Ortadaki çekirdekte (core) yaklaşık 56 milyon sayfa vardı.
- Hoca, bu yapının 2020'de de değişmediğini söyledi.
- Kopuk bileşenler çoğunlukla kurum içi ağlar (intranet) gibi kendi içinde bağlı yapılar.

### Web verisinin özellikleri

- E-posta, dijital kütüphane, kişisel disk, kurum intranet'i ve web verisi karşılaştırıldı.
- Büyüklük: en küçük e-posta, en büyük web.
- Karmaşıklık: en düşük e-posta. En yüksek, CRM ve ERP gibi eski (legacy) uygulamaların çalıştığı intranet.
- Mahremiyet: web'de en düşük, çünkü herkes erişebilir.
- Çelişkili bilgi: herkes bilgi paylaştığı için web'de en yüksek.

### Web'in büyüklüğü

- Hoca, indekslenmiş web'in büyüklüğünü gösteren bir siteyi açtı.
- O günkü tahmin: yaklaşık 5,47 milyar indekslenmiş sayfa. Google indeksine dayalı tahmin 60 milyara yakın.
- Site, Google ve Bing indekslerinden zaman içindeki değişimi ve ülkelere göre sayfa sayılarını gösteriyor.

### Wisdom of crowds

- Birbirinden habersiz çok sayıda insanın paylaşımından bilgi çıkarmak.
- Örnek 1: Yandex veya Google Maps. Kullanıcıların telefonları konum ve hız gönderir. Sistem bundan trafik tahmini yapar ve diğer kullanıcılara iletir.
- Örnek 2: Flickr'da "jaguar" etiketli resimler. Etiketler kullanılarak araba, vahşi hayvan, gitar ve savaş uçağı kümeleri ayrıldı. Görüntü işleme ile bu kümeleme çok daha maliyetli ve zor olurdu.
- Örnek 3: Barselona'da turistlerin GPS etiketli fotoğrafları. Haritada turistlerin hangi saatte nerede yoğunlaştığı görülüyor. Kısa sürede gezilecek yerler buradan çıkarılabilir.
- Arama motorları bu bilgiyi sıralamada kullanır. Kaynaklar: sayfa yazarlarının linkleri, etiketler (tags), kullanıcı sorguları (queries).
- Örnek: Google Trends, aramalardan dönemsel ilgiyi çıkarır.

### Data retrieval ve information retrieval

- Veritabanında veri yapılıdır (structured): tablolar, primary key, foreign key, kolon tipleri ve sorgu sözdizimi belli.
- IR'de veri HTML, PDF, metin gibi dosyalarda yapısız tutulur. Sorgunun belli bir sözdizimi yoktur, kelime veya kelime grubu girilir.
- Arama motoru, IR'nin web'deki örneğidir. Intranet üzerinde çalışan IR sistemleri de vardır.

### Data, information, knowledge, wisdom

- Ham sayfalar: veri (raw data).
- Bir sorguya dönen sonuç listesi (list of results): information.
- Kullanıcı sonuçları inceleyip konuyu öğrenince: knowledge.
- Çok sayıda insan aynı knowledge'a ulaşırsa: wisdom.

### Web'de IR'nin zorlukları

- Dokümanlar dünya genelinde dağıtık HTTP sunucularında. Çok sayıda veri var, toplamak ve saklamak zor.
- Eş zamanlı çok sayıda kullanıcıya yüksek performansla arama yaptırmak gerekiyor.
- Spam: sayfayı temsil etmeyen kelimelerle doldurulan sayfalar, sonuçlarda üste çıkmaya çalışır.

### Tarayıcı, ters indeks ve TF-IDF

- Bir öğrenci, arama motorlarının artık anahtar kelimeye bakmayıp bakmadığını sordu. Hoca: Hâlâ anahtar kelimeye de, popülerliğe de bakılıyor.
- Crawler: sayfaları önceden bulup indiren, içindeki kelimeleri çıkarıp indeksleyen uygulama. Örnekler: Googlebot, MSNbot. Kitapta 8. bölümde ayrıca işlenecek.
- Ters indeks: birinci kolon kelimeler, ikinci kolon o kelimeyi içeren sayfaların bağlı listesi (linked list).
- Arama ham veri üzerinde değil, indeks üzerinde yapılır. Bulunan sayfalar PageRank gibi popülerlik tabanlı bir algoritmayla yeniden sıralanır.
- TF-IDF: bir kelimenin sayfa içindeki önemini ölçen temel metrik. Kelimenin sayfada bulunduğu yer (başlık, gövde vb.) de önemini etkileyebilir. Günümüz arama motorları bunun çok daha gelişmiş sürümlerini kullanıyor.

### IR modelleri

- Örnekler: Boolean model, vektör uzayı modeli (vector space model). Derste tek tek işlenecek.
- Bir model şunları tanımlar: sorgu dili (query language), dokümanların ve sorguların gösterimi, eşleştirme (comparison) algoritması.
- Sonuç olarak kullanıcıya sonuç listesi gösterilir.

### Precision ve recall örneği

- Bir öğrenci jaguar örneğini sordu: 10 resimden 3'ü aranan vahşi hayvan ise precision $3/10$.
- Recall için veri kümesindeki toplam jaguar (hayvan) resmi sayısını bilmek gerekir. Bilinmiyorsa hesaplanamaz.
- Recall genellikle toplam ilgili doküman sayısının bilindiği kontrollü veri kümelerinde kullanılır.
- Kapsamlı karşılaştırmada precision at 10, 20, 30 gibi farklı kesimler denenmelidir.

### Çeşitlilik

- Örnek bir sorguda Google'ın ilk sonuçlarının hepsi aynı alan adından geldi.
- Sonuçlar ilgili olsa bile bu istenmez, çünkü tek bir bakış açısı kullanıcıya dayatılmış olur.

### Bag of words

- Örnek cümle: "That's one small step for a man, a giant leap for mankind."
- Her kelime bir kez yazılır, yanına tekrar sayısı eklenir.
- Alternatif: sözlükteki tüm kelimeler için 0/1 vektörü veya tekrar sayılarından oluşan vektör.
- Dezavantajları: kelime sırası kaybolur, çok farklı dokümanlar benzer gösterime sahip olabilir, doküman yapısı ve metadata (kalın, italik vb.) yok sayılır.
- Avantajları: anlamlı sonuçlar verir, az yer kaplar, basittir.

### İnternet ve web

- Öğrenci cevapları: İnternet "network of networks", web ise bilgi koleksiyonu. Ulaşılmak istenen web, bunu sağlayan internet.
- Hoca: İnternet fiziksel ağ altyapısı (network katmanı). Web ise bunun üzerindeki yazılım ve veri katmanı, birbirine link veren hypertext dokümanların ağı.
- Web'in yazılım katmanında HTTP sunucuları, tarayıcılar, DNS sunucuları, sanal switch'ler ve arama uygulamaları var.

### Kavramlar

- Hyperlink: metne gömülü, arka planda bir URL'ye eşlenmiş bağlantı. Tıklanınca tarayıcı o URL'ye gider.
- Hypertext ve hypermedia: metin veya multimedya içeriğin bir URL ile eşlenmesi.
- HTML: tarayıcıların gösterdiği hypertext biçimi.
- HTTP: tarayıcının sunucudan doküman istediği protokol.
- URL: tarayıcının istekte kullandığı link.
- Anchor text: URL'ye karşılık gelen, kullanıcıya görünen metin.

### Duyurular

- Ders notları ve duyurular için hoca bu hafta bir karar verip e-posta ile bildirecek: yeni online sistem, Google Sites veya bir öğrencinin önerdiği Google Classroom.
- Öğrencilerin GİSİS'te tanımlı e-posta adreslerini kontrol etmeleri istendi.
- Hoca, öğrencilerin kendi aralarında duyurular için bir WhatsApp grubu kurmasını önerdi.

### Ders sonrası notlar

- Hoca, bag of words için "avantajları" diyerek başladı ama listelediği maddeler (kelime sırasının kaybolması vb.) dezavantajlardır. Avantajları sonra ayrıca saydı.
- Hoca web sayfalarının "farklı DNS sunucuları üzerinde tutulduğunu" söyledi. Doğrusu: sayfalar web (HTTP) sunucularında tutulur. DNS sunucuları alan adlarını IP adreslerine çevirir.
- Hoca kendini bu kayıtta doçent olarak tanıtıyor (2020). Bu klasörde güncel unvanı kullanıldı.
- Altyazıdaki bozuk adlar: "Tim Bernersley" doğrusu Tim Berners-Lee; "N-S-S-A" doğrusu NCSA; "OVL" doğrusu OWL; "dandridge" doğrusu tendrils; "Business of Crowds" ve "Wisdom of Krauts" doğrusu wisdom of crowds.
- Papyon çalışmasını yapanların adı altyazıda bozuk geçiyor ("Guleme ve Latepi"). Bilinen kaynak, Broder ve arkadaşlarının 2000 tarihli "Graph Structure in the Web" makalesi.
- Kayıt iki parçadan birleşmiş. Ders yaklaşık 02:13'te bitiyor. Sonrasında dersle ilgisi olmayan kısa konuşmalar var.
- Hoca IN sayfalarını "link almayan", OUT sayfalarını "link vermeyen" diye tanımladı. Doğrusu büyük olasılıkla bunun çekirdeğe göre geçerli olmasıdır: IN sayfaları çekirdekten link almaz, OUT sayfaları çekirdeğe link vermez.
- Hoca ilk uygulamanın tamamen komut satırından çalıştığını söyledi. Berners-Lee büyük olasılıkla 1990'da grafik arayüzlü bir tarayıcı-düzenleyici de yazmıştır.
- Hoca statik web'i indeksli web ile eşitledi. Bu eşitlik büyük olasılıkla kesin değildir: hocanın dinamik web örneği olan haber siteleri de arama motorlarında çıkar.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
