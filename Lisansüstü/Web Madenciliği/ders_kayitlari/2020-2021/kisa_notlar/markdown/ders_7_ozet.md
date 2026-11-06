# Ders 7 Çalışma Özeti

## Genel Konular

- Ders 17 Kasım 2020 tarihlidir.
- O ana kadar 5. bölüm (kısmi gözetimli öğrenme, partially supervised learning) dışındaki bölümler sırayla işlenmiştir.
- Bu derste bilgi erişimi ve web araması bölümünün kalan kısımları bitirilmiş, ardından web crawling bölümüne giriş yapılmıştır.
- Ana konular:
  - Bilgi erişimi sisteminin genel akışının tekrarı
  - Metin ön işleme (text preprocessing): terim çıkarma, durak kelime çıkarma (stop word removal), kök bulma (stemming)
  - Doküman-terim matrisi ve TF-IDF tekrarı
  - Bilgi erişimi başarısının ölçülmesi: kesinlik (precision), duyarlılık (recall), Precision@10, çeşitlilik (diversity), precision-recall eğrisi
  - Ters indeks (inverted index) yapısı ve arama sırasında kullanımı
  - Sorgu genişletme (query expansion)
  - Crawler'ın çalışma mantığı, robots.txt, kullanım alanları
  - Crawler sınıflandırması (taxonomy): universal, preferential, focused, topical crawler
- Dersin sonunda bir öğrencinin proje önerisi konuşulmuştur.
- Vize duyurusu yapılmıştır: gelecek hafta (24 Kasım 2020), ders saatinde.

## Hocanın Özellikle Vurguladığı Kısımlar

- Vize gelecek hafta ders saatindedir.
  - Kapsam: 5. bölüm hariç ilk 6 bölüm. Crawler bölümü vizeye dahil değildir.
  - Çoktan seçmeli ve doğru-yanlış sorular olabilir.
  - Sınav, üniversitenin yeni satın aldığı sınav sistemi üzerinde yapılacaktır. Değişiklik olursa ders sayfasından duyuru yapılacaktır.
  - Bölüm slaytları ders sayfasından indirilebilir. Kitaptaki örnekler ve bölüm sonu sorular mutlaka çalışılmalıdır.
- Doküman artık kendisiyle değil, temsilci vektörüyle temsil edilir. Bu vektör yanlış oluşturulursa sorgu-doküman eşleştirmesi de yanlış olur.
- Web ortamında başarı en çok Precision@10 ile ölçülür. Kullanıcılar genelde ilk 10 sonuca bakar. Bulamazlarsa anahtar kelimeyi değiştirirler.
- Web ortamında recall ölçülemez. Bir sorguya karşılık gelen tüm ilgili dokümanların sayısı bilinemez.
- Arama motorları arasındaki başarı farkı, ters indekse ne kadar ek bilgi koyduklarından gelir: kelimenin başlıkta, gövdede ya da meta etiketinde geçmesi, kalın yazılması vb.
- Crawler'lar kullanıcı dostu olmalıdır: robots.txt dosyasına uymalıdır.
- Proje önerisi için: sınıflandırma algoritmalarıyla sayısal değer tahmini yapılıyor denmemelidir. "Elma ile armudu karıştırma."

## Kısa Tekrar Notları

- Bilgi erişimi akışı: crawler doküman koleksiyonunu oluşturur, indeksleyici ters indeksi oluşturur, kullanıcı sorgusu çalıştırılabilir sorguya çevrilir, ters indekste arama yapılır, sonuçlar sıralanıp gösterilir.
- Metin ön işleme adımları:
  - Terimleri çıkarma (parser ile PDF, Word, HTML'den)
  - Durak kelimeleri çıkarma: indeks boyutunu yaklaşık %20-30 küçültür.
  - Kök bulma (stemming): indeks boyutunu yaklaşık %40-50 küçültür.
  - TF-IDF hesaplama
- Doküman-terim matrisi: satırlar dokümanlar, sütunlar vocabulary kelimeleri, hücreler TF-IDF değerleridir.
- Precision: getirilen dokümanların ne kadarı ilgili? $P = |A \cap B| / |B|$
- Recall: tüm ilgili dokümanların ne kadarı getirildi? $R = |A \cap B| / |A|$
- $A$ ilgili dokümanlar kümesi, $B$ getirilen dokümanlar kümesidir.
- Ters indeks: anahtar (key) kelime, değer (value) o kelimeyi içeren dokümanların sıralı bağlı listesidir (linked list).
- Zengin ters indeks girdisi: doküman ID, kelimenin dokümandaki frekansı, pozisyonları, istenirse başlık ya da kalın yazı gibi ek bilgiler.
- Crawler: tohum (seed) URL'lerden başlar, sayfaları indirir, içlerinden yeni URL'ler çıkarır, onları da indirir. Bir durma kriterine kadar devam eder.
- Crawler sınıfları:
  - Universal crawler: genel arama motorları için.
  - Preferential crawler: dikey (vertical) arama motorları için. İkiye ayrılır:
    - Focused crawler: belli bir konu için önceden indeks oluşturur.
    - Topical crawler: indeksi önceden oluşturmaz, sorgu anında web'i tarar.

## Detaylı Açıklamalar

### Bilgi erişimi sisteminin tekrarı

- Crawler dağıtık ortamdaki dosyaları alıp bir doküman koleksiyonu oluşturur. Bazen ise yerel ortamdaki dokümanlar üzerinde arama yapılır.
- Doküman koleksiyonunda doğrudan arama yapılmaz. Önce bir doküman indeksi oluşturulur:
  - Birinci kolon: aranacak anahtar kelimeler.
  - İkinci kolon: her kelimeyi içeren dokümanların TF-IDF skoruna göre sıralı listesi.
- Kullanıcının sorgusu çalıştırılabilir sorguya çevrilir. Bu sorgunun kelimeleri tabloda aranır (lookup). Tablo bir hash tablosu gibi düşünülebilir. Bulunan girdilerdeki doküman listeleri birleştirilip sıralanarak gösterilir.
- Bu tabloya "ters indeks" (inverted index) denir. Çünkü kelimelerden dokümanlara ulaşılır.
- Vektör uzayı modelinde benzerlik kosinüs benzerliğiyle, Boolean modelde AND, OR, NOT ile tam eşleşmeyle bulunur.

### Metin ön işleme

- HTML dokümanında URL'ler ve resimler vardır. Resim HTML'e gömülü değildir, ayrı bir dosyadır. HTML'den resme bir link vardır.
- Doküman, kelime torbası (bag of words) şeklinde bir vektörle temsil edilir. Bu vektör doğru oluşturulmalıdır.
- Terim çıkarma: bir parser ile PDF, Word ya da HTML dokümanından kelimeleri çıkarmak kolaydır.
- Durak kelimeler (stop words):
  - Kendi başına anlamı olmayan, cümle kurmak için gramerde kullanılan kelimelerdir.
  - Örnekler: Türkçede bağlaçlar, İngilizcede "the", Almancada "der, die, das".
  - Dokümanı tanımlayıcı değildirler. Vektöre alınmazlar.
  - Genelde dokümanı tanımlayan kelimeler terimler, yani isimlerdir.
  - Çıkarılmaları toplam kelime sayısını ve indeks boyutunu yaklaşık %20-30 azaltır.
- Kök bulma (stemming):
  - Sondan eklemeli dillerde (örnek: Türkçe) aynı kelimenin farklı ek almış biçimleri olur.
  - İngilizce örnekler: "user, users, used, using" kelimelerinin kökü "use"tur. "engineering, engineered" kelimeleri de aynı kökten türemiştir.
  - Bu biçimler ayrı kelime olarak alınmaz. Kökü bulunup vektöre kök yazılır.
  - İndeks boyutunu yaklaşık %40-50 azaltır.
  - Stemming kütüphaneleri genelde kural tabanlıdır ve her dil için farklıdır. Ek geldiğinde kökün son harfleri değişebilir. Her durum bir kurala çevrilmelidir.
- Vektör oluşturulurken kelimenin dokümanda kaç kez geçtiği de tutulmalıdır. Vektör elemanı 1 ya da 0 yerine frekans olabilir.
- Bir öğrenci dokümanın web sayfası mı olduğunu sormuştur. Hoca: web araması için doküman web sayfasıdır. Yerel bilgi erişiminde ise Word ya da PDF dokümanlarıdır.

### Doküman-terim matrisi ve TF-IDF

- TF (terim frekansı): kelimenin bir doküman içindeki önemi. Kelime dokümanda ne kadar sık geçiyorsa TF-IDF o kadar yüksek olur.
- IDF (ters doküman frekansı): kelimenin tüm doküman setindeki önemi. Kelime ne kadar az dokümanda geçiyorsa TF-IDF o kadar yüksek olur.
- Vektörün boyutu, tüm doküman setinden çıkarılan benzersiz kelime sayısı, yani vocabulary boyutudur.
- Tüm doküman seti bir matrisle gösterilir (tablodaki sayılar örnek amaçlıdır, derste geçmiyor):

```
            kelime_1   kelime_2   ...   kelime_V
doküman_1     0.12       0          ...    0.40
doküman_2     0          0.35       ...    0
...
doküman_N     0.08       0          ...    0.22
```

- Kelime dokümanda varsa hücrede sıfırdan farklı (non-zero) TF-IDF değeri vardır.
- İndeksleyici bu matristen ters indeks tablosunu oluşturur.
- Bağlı listedeki düğümler dokümanın kendisi değildir. Dokümanın ID'sini içeren özet bilgidir.

### Bilgi erişimi başarısının ölçülmesi

- Örnek: 100 dokümanlık sette "web mining" aranıyor. Motor ilk 10 dokümanı getiriyor. Bunlardan kaçının ilgili (relevant) olduğuna bakılır.
- Kesinlik ve duyarlılık iki soruya cevap verir:
  - Precision: "Getirilen dokümanların hepsi ilgili mi?" (Are all retrieved documents relevant?)
  - Recall: "İlgili dokümanların hepsi getirildi mi?" (Have all the relevant documents been retrieved?)
- Küme gösterimi: doküman koleksiyonu içinde $A$ (sorguyla ilgili dokümanlar) ve $B$ (motorun getirdiği dokümanlar) kümeleri vardır.

$$precision = \frac{|A \cap B|}{|B|} \qquad recall = \frac{|A \cap B|}{|A|}$$

- Precision tek başına kullanılmaz. İlk $k$ sonuç için verilir: Precision@10, Precision@20, Precision@30.
- Web ortamında:
  - En yaygın metrik Precision@10'dur.
  - Recall ölçülemez. Paydaki değer bulunabilir, ama paydadaki gerçek ilgili doküman sayısı bilinemez.
  - Yerel bir doküman setinde ise ilgili doküman sayısı tespit edilebilir. Recall hesaplanabilir.
- Çeşitlilik (diversity):
  - Arama motorları karşılaştırılırken sonuçların farklı alan adlarından (domain) gelip gelmediğine de bakılır.
  - Bir motor tüm sonuçları tek bir alan adından getirirse, diğeri farklı alan adlarından getirirse ikincisine daha çok güvenilir. Çünkü tek bir sayfanın görüşünü empoze etmez.
- Precision-recall eğrisi:
  - X ekseni recall, Y ekseni precision'dır.
  - Recall %0'dan %100'e %10 adımlarla artırılır. Her recall değerinde precision hesaplanır.
  - Örnek: 100 dokümanda sorguyla ilgili 10 doküman vardır.
    - İlk sonuç ilgiliyse recall %10, precision %100'dür.
    - İlk iki sonuç ilgiliyse recall $2/10 = \%20$, precision %100'dür.
    - İlk üç sonuç ilgiliyse recall %30, precision %100'dür.
    - Dördüncü sonuç ilgili değilse recall %30'da kalır, precision düşer. Hoca burada "%40 olduğu zaman precision düşüyor" demiştir. Recall %40'a ancak dördüncü ilgili doküman gelince çıkar.
  - Tek bir sorguyla değerlendirme yapılmaz. Farklı alanlardan çok sayıda sorgu seçilir. Her sorgu için tablo çıkarılır. Her recall seviyesinde precision değerlerinin ortalaması alınır. Eğri bu ortalama tablodan çizilir.

### Ters indeks (inverted index)

- Arama anında doküman koleksiyonunda arama yapılamaz, çünkü arama çok hızlı olmalıdır. Koleksiyon önce ters indekse çevrilir.
- Derste üç dokümanlık bir örnek iki tabloyla gösterilmiştir:
  - Basit tablo: her kelime için onu içeren doküman ID'leri. Örnek: "applications" yalnız 2. dokümanda, "hyperlink" yalnız 3. dokümanda, "mining" üç dokümanda da geçer.
  - Ayrıntılı tablo: her girdi (doküman ID, frekans, pozisyonlar) üçlüsüdür. Örnek: "applications" 2. dokümanda 1 kez, 3. pozisyonda geçer. "structure" 3. dokümanda 2 kez, 2. ve 8. pozisyonlarda geçer.

```
applications: <id2, 1, [3]>
mining:       <id1, 1, [..]>, <id2, 1, [..]>, <id3, 1, [..]>
structure:    <id3, 2, [2, 8]>
```

- Pozisyonların tutulma sebepleri:
  - Yakınlık sorguları (proximity search): kelimeler aynı paragrafta ya da cümlede olan dokümanlar öne alınır.
  - Kelimenin meta etiketi ya da başlık içinde, kalın ya da italik yazılmış olması gibi önemini gösteren bilgiler de girdiye eklenebilir. Üçlü vektör dörtlü, beşli, altılı olabilir.
- Arama adımları:
  - Vocabulary araması: sorgudaki her kelime için tabloda lookup yapılır. Örnek: "web mining" için önce "web" girdisine, sonra "mining" girdisine gidilir.
  - Sonuçları birleştirme (merge): kelimelerden gelen doküman listeleri TF-IDF skorlarına göre birleştirilir.
  - Yeniden sıralama (re-ranking): web aramasında genellikle link tabanlı sıralama ile yapılır. Bu yöntem web yapı madenciliği (web structure mining) bölümünde işlenecektir.

### Sorgu genişletme

- Arama motorları daha iyi sonuç için kullanıcının sorgusunu arka planda genişletir.
- Örnek: kullanıcı önce "İstanbul", "Yıldız Teknik Üniversitesi" ve İstanbul'daki lokantaları aramıştır. Sonra "web mining" yazar.
  - Akıllı bir motor ilk 10 sonuçta Çin'deki bir üniversitenin web mining dersini getirmez.
  - Kullanıcının konumunu ve önceki aramalarını dikkate alır. Sorguya "İstanbul", "Türkiye" ya da "Yıldız Teknik Üniversitesi" ekleyebilir.
  - Bu genişletme kullanıcıya gösterilmez, arka planda yapılır.

### Bölümde işlenmeyen konular

- Başka bilgi erişimi modelleri: istatistiksel dil modeli (statistical language model), gizli anlamsal indeksleme (Latent Semantic Indexing, LSI).
- İndeks sıkıştırma (index compression) yöntemleri.
- Web sayfası ön işlemenin ayrıntıları (kitaptan okunabilir).
- Web spam'in nasıl önleneceği.
- Farklı sıralama mekanizmalarının nasıl birleştirileceği.

### Web crawling: motivasyon ve çalışma mantığı

- Arama bir indeks üzerinde yapılır. İndeks için önceden dokümanları indiren bir uygulama gerekir. Bu uygulama crawler'dır.
- Web aramasında milyonlarca, hatta milyarlarca doküman vardır. Dikey arama motorlarında (örnek: elektronik ya da yemek tarifi) milyonlar mertebesindedir.
- İndirilen dokümanlar tek bir düğümde değil, veri merkezindeki bir kümede (cluster) çok düğümlü NoSQL veri saklama teknolojileriyle tutulur. İndeksleme bunun üzerinde yapılır.
- Crawler'ın temel fikri:
  - Crawler'a başlangıç noktası olarak tohum (seed) URL'ler verilir.
  - Crawler bu URL'lere HTTP isteği yapar. HTTP yanıtı içinde HTML dosyaları gelir.
  - İndirilen sayfalar ayrıştırılır (parse). İçlerinden yeni URL'ler çıkarılır.
  - Yeni URL'ler de indirilir, ayrıştırılır, yeni URL'ler çıkarılır.
  - Bir durma kriterine (stopping criteria) kadar devam edilir. Örnek: tohum URL'lerden 3 seviye derinliğe inince durmak.
- Her arama motorunun bir crawler'ı vardır. Örnekler: Google için Googlebot, Bing için MSNbot. İsimleri genelde "bot" ile biter.
- Hoca, crawler'ların sürekli çalıştığı için dünya genelindeki internet bant genişliğini en yoğun kullanan uygulamalar olduğunu söylemiştir. Altyazıda bunun için bir ölçüm verilmez.
- robots.txt:
  - Her uygulama sunucusunda crawler'ın hangi sayfaları indeksleyip hangilerini indeksleyemeyeceğini belirten bir dosya vardır.
  - Bu dosyada crawler'ın sayfayı hangi sıklıkta ziyaret edebileceği bilgisi de vardır. Örnek: "beni günde bir kez ziyaret et".
  - Crawler buna uymazsa sunucuyu gereksiz meşgul eder. Site yöneticisi o crawler'ı yasaklayabilir.
- Google örneğinde mimari:
  - Crawler sayfaları bir sayfa deposuna (page repository) koyar. Bu, doküman koleksiyonudur.
  - Depo üzerinde metin ön işleme yapılıp ters indeks (text index) oluşturulur.
  - Link analizi yapılıp ikinci bir tablo oluşturulur: PageRank tablosu. Bu HITS ya da başka bir link tabanlı algoritma da olabilir.
  - Sorgu anında ters indekste lookup yapılır. Bulunan sonuçlar PageRank skorlarıyla birleştirilir. Hem TF-IDF hem PageRank dikkate alınarak sıralanmış sonuçlar kullanıcıya gösterilir.

### Crawler kullanım alanları

- Genel (universal) arama motorlarını desteklemek: Google, Yahoo, Yandex, Bing.
- Dikey (vertical) arama motorları: yemek tarifleri, alışveriş siteleri, haberler, Google Scholar gibi akademik yayın aramaları.
- İş zekası (business intelligence):
  - Örnek: bir elektronik perakendecisi, rakip firmaların sayfalarını ürün ve fiyat bazında sürekli tarar. Fiyatların ortalamasını ve standart sapmasını alıp kendi fiyatıyla karşılaştırır. Çok yüksek ya da çok düşük fiyatı düzeltir. Rakiplerin sattığı ama kendisinin satmadığı ürünleri fark edip ürün çeşitliliğini artırır.
  - Aynı şey online marketler için de geçerlidir.
- Web sitelerindeki değişiklikleri izlemek: haber sitelerinde bir önceki güne göre yeni haberler gibi.
- Pazarlama: e-posta adresi toplamak. Örnek: akademik konferanslar ve tercüme firmaları, üniversite sayfalarını crawl ederek akademisyenlerin e-posta adreslerine ulaşır ve toplu e-posta gönderir.

### Crawler sınıflandırması

- Universal crawler'lar: Yahoo, Google gibi genel arama motorlarının doküman koleksiyonlarını oluşturur. Ayırım yapmadan tüm web sitelerinden indeks oluşturur.
- Preferential crawler'lar: dikey arama motorlarının doküman koleksiyonlarını oluşturur. İkiye ayrılır:
  - Focused crawler'lar:
    - Örnek: yemek tarifleri, elektronik ürünler ya da süpermarket ürünleri için arama motorları.
    - Hangi konu için arama motoru geliştiriliyorsa o konunun dokümanlarını indirip önceden indeks oluşturur.
  - Topical crawler'lar:
    - İndeksi önceden oluşturmaz, sorgu anında oluşturur.
    - Sorgu girilince web taranmaya başlanır. Sorguya uyan sonuçlar adım adım sıralanarak gösterilir.
    - Hocanın örneği: "The North Face" sorgusunun geçtiği sayfaları gerçek zamanlı izleyen bir izleme aracı.
    - Uyarlamalı (adaptive) olabilir: tarama sırasında öğrenilen yeni bilgi dikkate alınır.
    - Statik olabilir: genişlik öncelikli arama (breadth-first search), derinlik öncelikli arama (depth-first search) ya da link analizi skorlarına göre sayfadan sayfaya gidilir.
- Bu konular sınav haftasından sonraki derste ayrıntılı işlenecektir.
- Bir öğrenci crawler ile scraper arasındaki farkı sormuştur. Hoca scraper terimini bilmediğini, bakıp e-posta ile konuşabileceklerini söylemiştir.

### Proje önerisi görüşmesi

- Bir öğrenci, yayınlanan uygulamaların (application) kullanıcılardan alacağı puanı (1-5 arası) önceden tahmin etmeyi önermiştir. Hazır bir veri seti, Python ve Pandas kullanılacaktır.
- Hocanın geri bildirimi:
  - Sayısal değer tahmini için regresyon analizi ya da LSTM tabanlı tahmin kullanılmalıdır.
  - Öneride yazılan algoritmalar sınıflandırma algoritmalarıdır. Bunlar kategorik değer tahmin eder.
  - Puanlar 1, 2, 3, 4, 5 gibi tam sayı kategoriler olarak ele alınırsa problem çok sınıflı (multi-class) tahmin olur. Bu durumda sınıflandırma algoritmaları (örnek: random forest, k-en yakın komşu, destek vektör makinesi) kullanılabilir.
  - Hocanın bir tercihi yoktur. Regresyon da sınıflandırma da kabul edilir. Ama seçilen yaklaşımda en az 3 algoritma kullanılmalıdır.
  - Yaklaşım literatürdeki makalelere dayandırılarak açıklanmalıdır.
- Öğrenci öneriyi güncelleyip e-posta ile gönderecektir.
- Diğer öğrenciler güncellenmiş önerilerini göndermiştir. Hoca henüz bakmadığını, bakacağını söylemiştir.

### Ders sonrası notlar

- Altyazıda "sistemik / steming" diye geçen işlem stemming'dir. "Stop quote" stop word'dür.
- "Turn frequency" term frequency, "TFI" TF-IDF demektir.
- "PageReposter" page repository'dir.
- "Precision top-down" Precision@10 (precision top 10) demektir.
- "Base first search" breadth-first search'tür.
- "MSN Bot" Bing'in eski crawler'ının adıdır. Bugün Bingbot olarak bilinir.
- "Canary's neighbor" k-nearest neighbor (k-en yakın komşu), "random porus" random forest'tır.
- "Hashtag olarak tutmak" ifadesi hash tablosu (hash table) demektir.
- Hoca precision'ı ilk anda "relevant olanların sayısı" diye tanımlamış, sonra oran olarak düzeltmiştir. Doğrusu: getirilen dokümanlar içinde ilgili olanların oranıdır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
