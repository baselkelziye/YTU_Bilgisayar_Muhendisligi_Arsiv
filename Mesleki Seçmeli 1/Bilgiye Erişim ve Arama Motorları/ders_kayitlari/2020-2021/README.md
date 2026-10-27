# Bilgiye Erişim ve Arama Motorları Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.

### 📋 Genel Bilgiler
* **Ders:** Bilgiye Erişim ve Arama Motorları (BLM3120)
* **Hoca:** Prof. Dr. Mehmet Sıddık Aktaş
* **Dönem:** Güz
* **Akademik Yıl:** 2020-2021
* **Şube:** BLM3120 - 1

Bu dizin, ilgili ders kayıtlarının altyazı özetlerini, çalışma notlarını ve PDF kaynaklarını içermektedir.

## 📚 Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu, kaynak markdown dosyası ve doğrudan indirilebilir PDF formatındaki derlenmiş halleri listelenmiştir. Ders numaraları, kayıt arşivindeki ders kaydı sıra numaralarıdır (hafta numarası değildir).

| Ders No | Ders İçeriği / Konu Başlıkları | Kaynak Notlar (Markdown) | Çalışma Dosyası (PDF) |
| :---: | :--- | :---: | :---: |
| **Ders 2** | Derse Giriş: Web Verisi, Bilgi Erişimi ve Arama Motorlarına Genel Bakış | [Özet](altyazi_ozetleri/ders_2_ozet.md) | [PDF (İndir)](ders_2_ozet.pdf) |
| **Ders 3** | İlişkilendirme Kuralı Madenciliği ve Apriori Algoritması | [Özet](altyazi_ozetleri/ders_3_ozet.md) | [PDF (İndir)](ders_3_ozet.pdf) |
| **Ders 4** | Sıralı Örüntü Madenciliği, Gözetimli Öğrenme ve K-Means Kümeleme | [Özet](altyazi_ozetleri/ders_4_ozet.md) | [PDF (İndir)](ders_4_ozet.pdf) |
| **Ders 5** | Hiyerarşik Kümeleme, Uzaklık Fonksiyonları ve Bilgiye Erişim Modelleri | [Özet](altyazi_ozetleri/ders_5_ozet.md) | [PDF (İndir)](ders_5_ozet.pdf) |
| **Ders 6** | Metin Ön İşleme, Precision-Recall Değerlendirmesi ve Ters İndeks | [Özet](altyazi_ozetleri/ders_6_ozet.md) | [PDF (İndir)](ders_6_ozet.pdf) |
| **Ders 9** | Web Tarayıcıları: Mimari, Gerçekleştirme Sorunları ve Tercihli Tarama | [Özet](altyazi_ozetleri/ders_9_ozet.md) | [PDF (İndir)](ders_9_ozet.pdf) |
| **Ders 10** | Sosyal Ağ Analizi, Ağ Temsilleri ve Merkezilik Metrikleri | [Özet](altyazi_ozetleri/ders_10_ozet.md) | [PDF (İndir)](ders_10_ozet.pdf) |
| **Ders 11** | Ortak Atıf, Bibliyografik Eşleşme ve PageRank Algoritması | [Özet](altyazi_ozetleri/ders_11_ozet.md) | [PDF (İndir)](ders_11_ozet.pdf) |
| **Ders 12** | HITS Algoritması ve Web Kullanım Madenciliği | [Özet](altyazi_ozetleri/ders_12_ozet.md) | [PDF (İndir)](ders_12_ozet.pdf) |
| **Ders 13** | Dönem Projesi Sunumları | [Özet](altyazi_ozetleri/ders_13_ozet.md) | [PDF (İndir)](ders_13_ozet.pdf) |

> [!NOTE]
> 1, 7 ve 8 numaralı kayıtlar arşivde yoktur; 29 Ekim 2020 tatildir.

## 🎯 Derslerin Detaylı Özetleri ve Kazanımları

### 🔹 Ders 2: Derse Giriş: Web Verisi, Bilgi Erişimi ve Arama Motorlarına Genel Bakış
* **Genel Konular:**
  - Dersin tarihi 15 Ekim 2020 Perşembe. Ders Zoom üzerinden, saat 09:00'da başladı.
    - Asıl anlatım yaklaşık 00:12'de başlar. 01:09 ile 01:19 arasında ara var.
  - Dersin tanıtımı (syllabus)
    - Ekrandaki izlencede dersin adı "BLM3581 Information Retrieval and Web Search Engines", hoca "Dr. Mehmet Aktaş" olarak geçer.
  - Web verisinin (web data) özellikleri
    - Web verisi yapısız (unstructured), yarı yapılı (semi-structured), hiper metin (hypertextual) ve dağıtık (distributed) bir veridir.
  - Derste öğrenilecek işler
    - Veriyi taramak (crawling), indekslemek (indexing), sıralamak (ranking).
  - Web'in kısa tarihi
    - Web 1990'da CERN'de Tim Berners-Lee tarafından başlatıldı: ilk HTTP sunucusu ve basit bir işaretleme dili.
  - Web'in yapısı: papyon (bow-tie) modeli, 2000 yılında yayımlanmış bir çalışmadan.
  - Web verisine farklı bakış açıları: karmaşıklık, hacim, gizlilik, düşmanca içerik (adversarial).
* **Hocanın Vurgusu:**
  - **Dönem projesi:**
    - Grup en fazla 2 kişi olabilir; tek kişi de yapılabilir. 3 kişilik grup kesinlikle olmaz.
  - **Katılım:** Kayıtlar sonradan izlenebilse de derse çevrim içi katılım isteniyor.
    - Bu aynı zamanda bölümün de şartı.
  - **Arama nasıl yapılır:** Arama, web sayfalarının kendisinde değil, önceden taranıp oluşturulmuş ters indeks tablosunda yapılır.
  - **Web arama motorunun kalitesi:** Ağırlıklı olarak precision ile ölçülür.
    - Tüm ilgili belgelerin sayısı bilinmediği için web'de recall hesaplanamaz.
  - **Çeşitlilik:** İyi bir arama motoru sonuçları tek bir siteden değil, farklı sitelerden getirmelidir.
* **Detaylı Açıklamalar:** Hoca izlencede dersin kitabı bölüm bölüm izleyeceğini söyler. Kitabın PDF'i ve her bölümün slaytları web'de bulunabilir. Hoca kendi slaytlarını da paylaşacağını söyler.

### 🔹 Ders 3: İlişkilendirme Kuralı Madenciliği ve Apriori Algoritması
* **Genel Konular:**
  - Dersin tarihi 22 Ekim 2020 Perşembe. Ders Zoom üzerinden yapıldı.
    - Asıl anlatım yaklaşık 00:05'te başlar. 01:04 ile 01:18 arasında ara var.
  - Dönem projesi ve değerlendirme hatırlatması
  - İlişkilendirme kuralı madenciliğinin (association rule mining) motivasyonu
    - Çapraz satış (cross-sell) ve üst satış (upsell).
  - Gösterim: öğe (item), öğe kümesi (itemset), işlem (transaction), işlem veri kümesi.
  - Kuralın yapısı $X\rightarrow Y$, destek (support) ve güven (confidence).
  - İki örnek üzerinde kural çıkarma.
  - Web verisine benzetme: belgeler = işlemler, anahtar sözcükler = öğeler.
* **Hocanın Vurgusu:**
  - **Dönem projesi:**
    - Notu üç şey belirler: vize, dönem projesi ve final.
  - **Bonus puan:** Proje, yerel geliştirme ortamı dışında ölçeklenebilir bir bulut ortamında (Amazon AWS, Azure, Google Cloud) sanallaştırma teknolojileriyle (Docker, Docker Swarm vb.) çalıştırılıp gösterilirse bonus verilecek.
  - **Güven ve destek farkı:** Bir kuralın support değeri, kuralın iki tarafı yer değiştirince değişmez.
    - Confidence değeri ise değişir.
  - **Pratikte:** Kurallar genellikle yüksek confidence ama düşük support değerine sahiptir.
  - **Kural üretmek için veriye geri dönmeye gerek yok:** Apriori çalışırken tüm alt kümelerin support değerleri zaten hesaplanmıştır.
    - Bu değerler bir tabloda (hash table) tutulur, confidence buradan hesaplanır. Hoca "bu kısım önemli" diye vurgular.
* **Detaylı Açıklamalar:** Problem önce fiziksel mağazalarda ortaya çıktı. Sonra e-ticaret sitelerine taşındı. Ardından web madenciliğine uyarlandı. Bu uyarlamada her belge bir işlem, belgedeki her anahtar sözcük bir öğe sayılır. Böylece bir belge kümesinde en sık birlikte geçen anahtar sözcükler bulunur.

### 🔹 Ders 4: Sıralı Örüntü Madenciliği, Gözetimli Öğrenme ve K-Means Kümeleme
* **Genel Konular:**
  - Dersin tarihi 5 Kasım 2020 Perşembe. Ders Zoom üzerinden yapıldı.
    - Asıl anlatım yaklaşık 00:11'de başlar. 01:34 ile 01:46 arasında ara var.
  - Sıralı örüntü madenciliği (sequential pattern mining), kitabın 2. bölümünün devamı
    - Gösterim: dizi (sequence), eleman (element), boyut (size), uzunluk (length), alt dizi (subsequence).
  - Gözetimli öğrenme (supervised learning), Bölüm 3
    - Temel kavramlar: eğitim ve test verisi, doğruluk (accuracy), "öğrenme" tanımı.
  - Gözetimsiz öğrenme (unsupervised learning), Bölüm 4
    - Kümeleme (clustering) ve kullanım alanları.
  - Dönem projesi önerisi duyurusu.
* **Hocanın Vurgusu:**
  - **Sıralı örüntülerin web'deki önemi:** Kullanıcının bir sitede tıklayarak izlediği gezinme örüntüsü (navigational pattern) bulunursa, kullanıcının bir sonraki adımı tahmin edilebilir.
  - **Öğrenmenin ölçütü:** Bir modelin öğrendiğini söylemek için, hiç öğrenme yapılmayan durumdan daha iyi tahmin etmesi gerekir.
    - İki sınıflı veride bu en az %50'dir. Pratikte %80–90 beklenir.
  - **Eğitim ve test verisinin dağılımı aynı olmalı.** Aksi hâlde modelin gerçek başarısı ölçülemez.
  - **Karar ağacı tek değildir:** Kullanılan nitelik önem ölçütü değişince ağaç değişir.
    - Her ağacın doğruluğu farklı olur.
  - **kNN model kurmaz:** Önceki üç yöntem eğitim verisinden bir model (ağaç, kural kümesi, olasılık kümesi) çıkarır. kNN ise her yeni örnekte eğitim verisinin kendisine döner.
    - Veri, modelin kendisidir.
* **Detaylı Açıklamalar:** İlişkilendirme kuralı madenciliği yalnız öğelerin aynı işlemde birlikte alınıp alınmadığına bakar, alış sırasını dikkate almaz. Birçok uygulamada sıra önemlidir: - Market sepetinde, insanların hangi ürünleri hangi sırayla aldığı. - Web madenciliğinde, tıklama akışı verisi. Kullanıcı ana sayfadan başlar, bağlantılara tıklayarak sitenin diğer sayfalarına geçer. Sık gezinme örüntüleri bulunursa kullanıcının bir sonraki hareketi tahmin edilip pazarlama yapılabilir.

### 🔹 Ders 5: Hiyerarşik Kümeleme, Uzaklık Fonksiyonları ve Bilgiye Erişim Modelleri
* **Genel Konular:**
  - Hiyerarşik kümeleme (hierarchical clustering) ve dendrogram (dendrogram)
    - Aşağıdan yukarı (agglomerative, bottom-up) ve yukarıdan aşağı (divisive, top-down) kümeleme
  - Kümeler arası uzaklık hesaplama stratejileri
    - Single link, complete link, average link, centroid
  - Uzaklık fonksiyonları (distance functions)
    - Sayısal veri: Minkowski, Öklid (Euclidean), Manhattan, ağırlıklı Öklid, kareli Öklid, Chebyshev
  - Kümeleme değerlendirmesi (cluster evaluation)
    - Küme içi (intra-cluster) ve kümeler arası (inter-cluster) uzaklık
  - Chapter 6: Bilgiye erişim ve web araması (information retrieval and web search)
    - Bilgiye erişim ile veritabanı sorgusu farkı
  - Dönem projesi önerileri
* **Hocanın Vurgusu:**
  - k-means'in iki zayıflığı var:
    - Küme sayısı $k$ baştan verilmeli.
  - Hiyerarşik kümeleme bu iki soruna çözümdür.
    - Derste aşağıdan yukarı (agglomerative) yöntem işlendi, çünkü yaygın kullanılan odur.
  - Hangi uzaklık stratejisinin ve hangi uzaklık fonksiyonunun en iyi sonucu vereceği baştan bilinmez.
    - Algoritma bunlarla parametrik yazılmalı.
  - Entropi ve saflık formüllerini ezberlemeye gerek yok.
    - Değerlerin nasıl yorumlanacağı bilinmeli.
  - Kosinüs benzerliği formülü önemli; Okapi yalnızca bilgi için.
* **Detaylı Açıklamalar:** Derse önceki haftadan kalan kümeleme konusuyla başlandı. Hoca k-means'in bölümleme tabanlı (partition-based) bir algoritma olduğunu hatırlattı.

### 🔹 Ders 6: Metin Ön İşleme, Precision-Recall Değerlendirmesi ve Ters İndeks
* **Genel Konular:**
  - Vize bilgisi ve sınav kapsamı
  - Önceki dersin Türkçe tekrarı
    - IR modelleri, dokümanın ve sorgunun vektör temsili
  - Metin ön işleme (text pre-processing)
    - Durak kelimelerin çıkarılması (stopword removal)
  - Erişim değerlendirmesi: kesinlik (precision) ve duyarlılık (recall)
    - Precision@10 gibi web ölçütleri, precision-recall eğrisi
  - Web aramasındaki zorluklar: çok anlamlı sorgular, otoriter sayfalar, çeşitlilik
  - Ters indeks (inverted index) ve arama sırasında indeksin kullanılması
  - Arama motorlarını başarılı kılan etkenler
* **Hocanın Vurgusu:**
  - Vize gelecek hafta, saat 15:00'te.
    - Çakışması olan hocaya bildirmeli.
  - Vize kapsamı: şimdiye kadar işlenen tüm bölümler, Chapter 5 hariç.
  - Sınava hazırlık:
    - Yalnızca slaytlar değil, kitaptaki ilgili bölümler de okunmalı.
  - Sınav biçimi:
    - Çoktan seçmeli, doğru/yanlış ve boşluk doldurma soruları.
  - Kosinüs benzerliği önemli; Okapi formülünü ezberlemeye gerek yok.
* **Detaylı Açıklamalar:** İndeksleyici (indexer) doküman koleksiyonunu işleyip arama yapılacak indeksi oluşturur. Adımlar:

### 🔹 Ders 9: Web Tarayıcıları: Mimari, Gerçekleştirme Sorunları ve Tercihli Tarama
* **Genel Konular:**
  - Proje önerilerine verilen geri bildirimler
  - Tarayıcıların (crawler) amacı ve sınıflandırması (taxonomy)
    - Evrensel (universal) ve tercihli (preferential) tarayıcılar
  - Temel sıralı tarayıcı (basic sequential crawler) ve modülleri
    - Frontier listesi, fetcher, parser, repository
  - Gerçekleştirme sorunları (implementation issues)
    - Aynı sayfayı tekrar indirmeme, frontier önceliklendirme
  - Eşzamanlı (concurrent) çok iş parçacıklı tarayıcı
  - Evrensel tarayıcılar: kapsam ile tazelik (coverage vs freshness) dengesi
  - Tercihli tarama algoritmaları: Best-N-First, PageRank, SharkSearch, InfoSpiders
* **Hocanın Vurgusu:**
  - Bu bölüm önemli, çünkü projelerin çoğu bir web tarayıcısı geliştiriyor.
  - Frontier listesine konacak tüm URL'ler mutlak (absolute) ve kanonik (canonical) biçimde olmalı.
  - Frontier'a eklemeden önce URL'nin daha önce indirilip indirilmediği kontrol edilmeli.
  - Fetcher sağlam (robust) olmalı ve zaman aşımı mekanizması içermeli.
  - Eşzamanlı tarayıcıda frontier paylaşılan veri yapısıdır.
    - Erişim frontier manager üzerinden senkronize edilmeli.
* **Detaylı Açıklamalar:** Hoca proje önerileri için hazırladığı notları bir dosyada yayımladı:

### 🔹 Ders 10: Sosyal Ağ Analizi, Ağ Temsilleri ve Merkezilik Metrikleri
* **Genel Konular:**
  - Dersin tarihi 17 Aralık 2020 Perşembe. Ders Zoom üzerinden yapıldı. Kayıt yaklaşık 00:24'te başlıyor ve 2 saat 10 dakika sürüyor.
    - Ders büyük ölçüde İngilizce anlatıldı. Hoca ders başında, aralarda ve sonda Türkçe açıklamalar yaptı.
  - Sosyal ağ analizinin web madenciliğindeki (web mining) yeri ve görselleştirme örnekleri.
    - Karmaşık ağ (complex network), ayrık alt ağlar, dev bileşen, yalıtılmış (island) düğümler.
  - İnternet ile Dünya Çapında Ağ (World Wide Web) farkı.
  - Temel terimler: düğüm (node) ve bağlantı (link), yönlü (directed) ve yönsüz (undirected) graf, bağlantı nitelikleri (link attributes).
  - Ağ verisinin üç temsil biçimi:
    - Komşuluk matrisi (adjacency matrix).
  - Ağın bağlantı yapısını özetleyen metrikler:
    - Derece (degree), giriş derecesi (in-degree), çıkış derecesi (out-degree), derece dizisi (degree sequence) ve derece dağılımı (degree distribution).
  - Bağlantı analizine dayalı sıralamanın tarihçesi: HITS (Cornell) ve PageRank (Stanford).
* **Hocanın Vurgusu:**
  - Sosyal ağ analizinin raporları genellikle görselleştirmeyle sunulur.
    - Düğümün büyüklüğü, seçilen metriğe göre önemini gösterir.
  - Aynı kavram farklı bilim dallarında farklı adlar alır:
  - **Yönlü mü yönsüz mü sorusu:**
    - LinkedIn yönsüzdür. Bağlantı isteğini kimin başlattığı bilinmez.
  - Bağlantı nitelikleri:
    - Ağırlık (weight): iletişim sıklığı. Telefon kaydı (CDR) verisinde arama sayısı, e-posta verisinde e-posta sayısı ağırlık olarak kullanılabilir.
  - Komşuluk matrisinde satır bağlantıyı vereni, sütun bağlantıyı alanı gösterir.
    - Bir satırın toplamı o düğümün çıkış derecesini verir.

### 🔹 Ders 11: Ortak Atıf, Bibliyografik Eşleşme ve PageRank Algoritması
* **Genel Konular:**
  - Dersin tarihi 24 Aralık 2020 Perşembe. Ders Zoom üzerinden yapıldı. Kayıt yaklaşık 2 saat sürüyor.
    - İlk 10 dakikada proje soruları cevaplandı. Ders yaklaşık 00:21'de başlıyor.
  - Önceki dersin özeti: merkezilik (centrality) ve prestij (prestige) metrikleri, sıra prestijinin (rank prestige) matris gösterimi.
  - Ortak atıf (co-citation) ve bibliyografik eşleşme (bibliographic coupling) metrikleri.
  - Popülerliğe dayalı sıralama (popularity-based ranking): PageRank ve HITS.
  - PageRank:
    - Akış denklemi (flow equation) ve basit örnek üzerinde çözüm.
  - PageRank'in avantajları ve sorgudan bağımsız (query independent) olmasının eleştirisi.
* **Hocanın Vurgusu:**
  - Prestij metrikleri giriş bağlantılarıyla (in-link) ilgilenir.
    - Her bağlantının önemi aynı değildir. Bir şirketin genel müdüründen gelen bağlantı, iş arkadaşından gelen bağlantıdan daha değerlidir.
  - Web'de arama yaparken iki sorun vardır:
    - Hangi sayfalar güvenilirdir (trustworthy)? Varsayım: güvenilir sayfalar birbirine bağlantı verir. Örneğin Wikipedia'nın spam sayfalara bağlantı vermesi beklenmez.
  - Çok bağlantı alan sayfa popülerdir ve güvenilir kabul edilir.
    - Örnek: stanford.edu çok sayıda bağlantı alır, adı bilinmeyen bir site tek bağlantı alır.
  - **Tek bağlantı alan sayfanın PageRank'i yüksek olabilir.** Örnekteki C düğümü yalnız bir bağlantı alıyor.
    - Ama bu bağlantı ağın en önemli düğümünden geliyor. Bu yüzden C'nin skoru 4 bağlantı alan E'ninkinden yüksek.
  - Bir düğüm PageRank değerini çıkış bağlantılarına eşit olarak paylaştırır.
    - 3 çıkış bağlantısı olan düğüm her birine değerinin $1/3$'ünü aktarır.

### 🔹 Ders 12: HITS Algoritması ve Web Kullanım Madenciliği
* **Genel Konular:**
  - Dersin tarihi 31 Aralık 2020 Perşembe, yılın son günü. Ders Zoom üzerinden yapıldı. Kayıt yaklaşık 2 saat sürüyor.
    - Bu ders büyük ölçüde Türkçe anlatıldı.
  - Bağlantı analizinin kısa özeti: merkezilik, prestij, ortak atıf (co-citation), bibliyografik eşleşme (bibliographic coupling), PageRank.
  - HITS algoritması (Hypertext Induced Topic Search):
    - Kök küme (root set) ve taban küme (base set).
  - Web kullanım madenciliği (web usage mining), kitabın 12. bölümü:
    - Veri kaynakları ve tıklama akışı (clickstream) verisi.
  - Dönem projesi sunumlarının nasıl yapılacağı.
* **Hocanın Vurgusu:**
  - PageRank ve HITS 1998'de ortaya çıktı.
    - PageRank Stanford'dan, HITS Cornell'den çıktı. Hoca PageRank'i Google'ın, HITS'i Yahoo'nun kullanmaya başladığını söyledi. PageRank, Google'ın ortaya çıkmasını sağlayan nedenlerden biriydi.
  - İki algoritmanın da ilk adımı aynıdır: sorgu, TF-IDF'e göre ters dizin (inverted index) tablosunda aranır ve eşleşen belgeler bulunur.
  - PageRank sorgudan bağımsızdır.
    - Örnek: "web data mining" araması.
  - HITS sorguya bağımlıdır.
    - Sorguya göre küçük bir graf kurar ve onun üzerinde hesaplar.
  - İyi otorite, çok sayıda iyi merkezden bağlantı alır.
    - İyi merkez, çok sayıda iyi otoriteye bağlantı verir. İki skor birbirini besler.

### 🔹 Ders 13: Dönem Projesi Sunumları
* **Genel Konular:**
  - Dersin tarihi 7 Ocak 2021 Perşembe, dönemin son haftası. Zoom üzerinden yapıldı. Kayıt yaklaşık 4 saat 45 dakika sürüyor.
  - Bu derste konu anlatılmadı. Bütün kayıt dönem projesi sunumlarından oluşuyor.
    - Gruplar bekleme odasına (waiting room) alındı. Her grup sırayla toplantıya alınıp projesini sundu.
  - Sunulan projeler dersin dört ana konusuna göre gruplanabilir:
    - **Web tarayıcı (crawler) uygulamaları:** Birden fazla e-ticaret sitesinden ürün verisi toplayıp tek sayfada gösterme ve filtreleme.
* **Hocanın Vurgusu:**
  - **Grup üyelerinin hepsi sunumda bulunmalı.** Bir üyenin "çalışıyorum, katılamayacağım, arkadaşım sunsun" diye yazdığı grubun sunumu kabul edilmedi.
    - İki üye birlikte bekleme odasına geldiğinde yeniden sunum hakkı verileceği söylendi.
  - **Ekran paylaşımı yapılabilmeli.** Teknik sorunu önceden çözmek grubun sorumluluğu.
  - **Crawler projelerinde filtreleme şart.** Birden fazla siteden toplanan veri kategoriye ve fiyata göre süzülüp sıralanabilmeli.
    - Hocanın örneği: E-ticaret sitesinde bütün ürünler yerine yalnız Nike ürünlerini ya da yalnız 43 numara ayakkabıları görmek istersiniz.
  - **Öneri sistemlerinde değerlendirme (evaluation) gerekli.** Yalnız benzerlik skorlarını listelemek yeterli değil.
    - Yapılan önerilerin iyi mi kötü mü olduğu bir değerlendirme yöntemiyle gösterilmeli.
  - **Sınıflandırma projelerinde en az üç farklı algoritma.** Kendi etiketli verinizle üç ayrı model eğitilip karşılaştırılmalı.
    - Hazır bir kütüphane fonksiyonuyla (ör. TextBlob'un duygu fonksiyonu) sonuç almak yeterli değil.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
