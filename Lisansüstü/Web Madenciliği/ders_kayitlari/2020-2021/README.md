# Web Madenciliği Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.

### 📋 Genel Bilgiler
* **Ders:** Web Madenciliği (BLM5121)
* **Hoca:** Prof. Dr. Mehmet Sıddık Aktaş
* **Dönem:** Güz
* **Akademik Yıl:** 2020-2021
* **Şube:** BLM5121 - 1

Bu dizin, ilgili ders kayıtlarının altyazı özetlerini, çalışma notlarını ve PDF kaynaklarını içermektedir.

## 📚 Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu, kaynak markdown dosyası ve doğrudan indirilebilir PDF formatındaki derlenmiş halleri listelenmiştir. Ders numaraları, kayıt arşivindeki ders kaydı sıra numaralarıdır (hafta numarası değildir).

| Ders No | Ders İçeriği / Konu Başlıkları | Kaynak Notlar (Markdown) | Çalışma Dosyası (PDF) |
| :---: | :--- | :---: | :---: |
| **Ders 1** | Tanışma ve Dersin Ertelenmesi | [Özet](altyazi_ozetleri/ders_1_ozet.md) | [PDF (İndir)](ders_1_ozet.pdf) |
| **Ders 2** | Web Verisi, Bilgi Erişimi ve Değerlendirme Ölçütleri | [Özet](altyazi_ozetleri/ders_2_ozet.md) | [PDF (İndir)](ders_2_ozet.pdf) |
| **Ders 3** | Birliktelik Kuralları ve Apriori Algoritması | [Özet](altyazi_ozetleri/ders_3_ozet.md) | [PDF (İndir)](ders_3_ozet.pdf) |
| **Ders 4** | Sıralı Örüntü Madenciliği ve Gözetimli Öğrenme | [Özet](altyazi_ozetleri/ders_4_ozet.md) | [PDF (İndir)](ders_4_ozet.pdf) |
| **Ders 5** | Gözetimsiz Öğrenme: K-Means, Hiyerarşik Kümeleme ve Uzaklık Fonksiyonları | [Özet](altyazi_ozetleri/ders_5_ozet.md) | [PDF (İndir)](ders_5_ozet.pdf) |
| **Ders 6** | Bilgi Erişimi ve Web Araması: Boolean Model, Vektör Uzayı Modeli ve TF-IDF | [Özet](altyazi_ozetleri/ders_6_ozet.md) | [PDF (İndir)](ders_6_ozet.pdf) |
| **Ders 7** | Metin Ön İşleme, Precision-Recall, Ters İndeks ve Web Crawler'lara Giriş | [Özet](altyazi_ozetleri/ders_7_ozet.md) | [PDF (İndir)](ders_7_ozet.pdf) |
| **Ders 10** | Web Taraması: Tarayıcı Türleri, Uygulama Sorunları ve Tercihli Tarama | [Özet](altyazi_ozetleri/ders_10_ozet.md) | [PDF (İndir)](ders_10_ozet.pdf) |
| **Ders 11** | Sosyal Ağ Analizi: Gösterimler, Merkezilik ve Prestij Ölçüleri | [Özet](altyazi_ozetleri/ders_11_ozet.md) | [PDF (İndir)](ders_11_ozet.pdf) |
| **Ders 13** | Co-Citation, Bibliographic Coupling ve PageRank Algoritması | [Özet](altyazi_ozetleri/ders_13_ozet.md) | [PDF (İndir)](ders_13_ozet.pdf) |
| **Ders 14** | HITS Algoritması ve Web Kullanım Madenciliği | [Özet](altyazi_ozetleri/ders_14_ozet.md) | [PDF (İndir)](ders_14_ozet.pdf) |

> [!NOTE]
> 8 numaralı kayıt (24 Kasım 2020) vize haftasıdır; 9 numaralı kayıt (1 Aralık 2020) arşivde yoktur; 12 numaralı kayıt (22 Aralık 2020) haftasında ders yapılamamıştır.

## 🎯 Derslerin Detaylı Özetleri ve Kazanımları

### 🔹 Ders 1: Tanışma ve Dersin Ertelenmesi
* **Genel Konular:**
  - İlk hafta, kısa tanışma ve duyuru dersi (yaklaşık 10 dakika).
  - Hoca, bir gün önce bölüm hocalarından Prof. Dr. Veli Hakkoymaz'ın vefat ettiğini duyurdu.
  - Bu nedenle ders işlenmedi. Hoca bu dersin telafisini sonraki haftalarda yapacağını söyledi.
  - Dersin işleyişi, kaynak kitap ve değerlendirme hakkında kısa bilgi verildi.
* **Hocanın Vurgusu:**
  - Syllabus, textbook ve değerlendirme (grading) bilgileri ders sayfasında ve e-posta ile paylaşılacak.
  - Öğrencilerin sistemde tanımlı e-posta adreslerini kontrol etmeleri gerekiyor.
  - Kaynak kitap: "Web Data Mining" (lisanstaki Information Retrieval dersiyle aynı kitap).
  - Bu ders, lisanstaki Information Retrieval (bilgi erişimi) dersiyle aynı konuları kapsıyor.
  - Fark: bu ders daha araştırma odaklı.
    - Okuma ödevleri (reading), dönem projesi (term project) ve birlikte makale okuma olacak.

### 🔹 Ders 2: Web Verisi, Bilgi Erişimi ve Değerlendirme Ölçütleri
* **Genel Konular:**
  - Tanışma, dersin işleyişi ve değerlendirme sistemi.
  - Web verisinin yapısı: hypertext, papyon (bow-tie) yapısı, statik, dinamik, gizli (hidden) ve anlamsal (semantic) web.
  - Web verisinin büyüklüğü, karmaşıklığı, mahremiyeti (privacy) ve çelişkili (adversarial) bilgi içermesi.
  - Web madenciliğinin amacı ve kalabalığın bilgeliği (wisdom of crowds) örnekleri.
  - Veritabanından veri çekme (data retrieval) ile bilgi erişimi (information retrieval, IR) farkı.
  - Veri, bilgi, kavrayış ve bilgelik sırası (data, information, knowledge, wisdom).
  - Web'de IR'nin zorlukları, tarayıcı (crawler), ters indeks (inverted index), TF-IDF.
* **Hocanın Vurgusu:**
  - Ders, Bing Liu'nun "Web Data Mining" kitabını takip ediyor.
    - Kitabın PDF'i ve yazarın slaytları internette var.
  - Değerlendirme: vize, tek kişilik dönem projesi ve final.
    - Dönem projesi notu vize kadar etkili. Final %40.
  - Derslere en az %70 katılım şartı var.
    - Sistem katılımı raporluyor.
  - Hoca etkileşim istiyor: sorularınızı chat yerine mikrofonla sorun, ara ara geri bildirim verin.
  - Ders salı 9-12 arası, 45-50 dakikalık iki oturum halinde.

### 🔹 Ders 3: Birliktelik Kuralları ve Apriori Algoritması
* **Genel Konular:**
  - Dönem projesi önerisi (proposal) formatı ve proje fikirleri.
  - Birliktelik kuralları madenciliği (association rule mining) ve kullanım alanları: çapraz satış (cross-sell), üst satış (up-sell).
  - Destek (support) ve güven (confidence) ölçütleri.
  - Apriori algoritması: sık öğe kümeleri (frequent itemsets), aşağı kapalılık özelliği (downward closure property), aday üretimi (candidate generation), kural üretimi.
  - Tablo verisinin işlem (transaction) formatına çevrilmesi.
  - Sınıf birliktelik kuralları madenciliği (class association rule mining).
  - Sıralı örüntü madenciliğine (sequential pattern mining) kısa giriş. Ayrıntısı gelecek hafta.
* **Hocanın Vurgusu:**
  - Ders, kitabı bölüm bölüm takip ediyor.
    - Her bölümden sonra ilgili bölümü, içindeki örnekleri ve bölüm sonu sorularını okumak öğrencinin sorumluluğunda.
  - Vize ve final soruları kitaptaki ve slaytlardaki konu ve örneklerden geliyor.
    - Başka yerden soru sorulmuyor.
  - Proje önerisi 5. haftada isteniyor.
    - Sonrasında yaklaşık 8 haftalık (2 aylık) çalışma süresi var.
  - Bonus: Proje raporu IEEE iki kolonlu konferans formatında bir makaleye dönüştürülür, hoca onaylar ve bir konferansta kabul edilirse harf notu bir basamak yükseltilir.
    - Not açıklandıktan sonra kabul gelse bile hoca bunu yapmaya çalışıyor.
  - Apriori'nin maliyeti algoritmanın kendisinden değil, her seviyede veritabanının diskten baştan sona okunmasından geliyor.

### 🔹 Ders 4: Sıralı Örüntü Madenciliği ve Gözetimli Öğrenme
* **Genel Konular:**
  - Sıralı örüntü madenciliği (sequential pattern mining): kavramlar, veri formatı, örnek ve GSP algoritması.
  - Makine öğrenmesine genel bakış: gözetimli (supervised), gözetimsiz (unsupervised), boyut indirgeme (dimension reduction), sığ (shallow) ve derin (deep) modeller.
  - Gözetimli öğrenmenin aşamaları: eğitim (training), test, doğruluk (accuracy) ve diğer ölçütler.
  - Sınıflandırıcılar: karar ağacı (decision tree), kural tabanlı sınıflandırma (class association rules), Naive Bayes, k en yakın komşu (k-nearest neighbor, kNN).
  - Aşırı öğrenme (overfitting) ve çapraz doğrulama (cross-validation).
* **Hocanın Vurgusu:**
  - Birliktelik kuralları işlem içindeki sırayı dikkate almaz.
    - Sıralı örüntü madenciliği zamanı ve sırayı dikkate alır.
  - Sıralı örüntü madenciliği web'de log dosyalarındaki popüler sıralı aksiyonları bulmak için çok kullanılıyor.
  - Churn analizinde "next best action": terk etmek üzere olan müşteriye uygulanacak en başarılı aksiyon zinciri.
  - Bu bölüm bir tekrar (overview).
    - Makine öğrenmesi derinlemesine işlenmeyecek. Amaç web madenciliğindeki kullanımlar.
  - Web madenciliğinde makine öğrenmesi çoğunlukla clickstream verisinden çıkarılan öz nitelikler üzerinde çalışır.

### 🔹 Ders 5: Gözetimsiz Öğrenme: K-Means, Hiyerarşik Kümeleme ve Uzaklık Fonksiyonları
* **Genel Konular:**
  - Ders 3 Kasım 2020 tarihlidir. Kitabın gözetimsiz öğrenme (unsupervised learning) bölümünün tekrarı yapılmıştır.
  - Dersin başında İzmir depremi (30 Ekim 2020) konuşulmuştur. Hoca ve öğrenciler hal hatır sormuştur.
  - Hoca ders kitabını (Web Data Mining) bölüm bölüm işlediğini söylemiştir. Dönem sonuna kadar web kullanım madenciliği (web usage mining) bölümüne kadar gitmeyi planlamaktadır.
  - Ana konular:
    - Gözetimli ve gözetimsiz öğrenme farkı
* **Hocanın Vurgusu:**
  - Tek bir kümeleme algoritması her veri setinde başarılı olmaz.
    - Farklı kategorilerden birer temsilci algoritma seçilmelidir.
  - K-Means yuvarlak ve eliptik kümeleri iyi bulur.
    - Garip şekilli ya da iç içe geçmiş kümeleri bulamaz.
  - Hiyerarşik algoritmalar şekilden bağımsız kümeleri bulabilir.
    - Ama hesaplama maliyeti yüksektir. Verinin tamamı bellekte olmalıdır.
  - K-Means'te veri diskte kalabilir.
    - Bu yüzden büyük veriye ölçeklenir.
  - Uzaklık fonksiyonu tüm kümeleme algoritmalarında olmazsa olmazdır.
    - Seçimi sonucu doğrudan etkiler. Seçimin gerekçesi (justification) verilebilirse sonuç daha başarılı olur.

### 🔹 Ders 6: Bilgi Erişimi ve Web Araması: Boolean Model, Vektör Uzayı Modeli ve TF-IDF
* **Genel Konular:**
  - Ders 10 Kasım 2020 tarihlidir. Hoca dersi Atatürk'ü ölüm yıl dönümünde anarak başlatmıştır.
  - Hoca dersin sayfasını (Google Sites) paylaşmıştır. Tüm ders notları ve örnek proje fikirleri bu sayfadadır.
  - O ana kadar işlenen bölümler: Bölüm 1 (genel bakış), Bölüm 2 (birliktelik kuralı madenciliği, association rule mining), Bölüm 3 (gözetimli öğrenme), Bölüm 4 (gözetimsiz öğrenme).
  - Bu derste kitabın 6. bölümü başlamıştır: bilgi erişimi (information retrieval) ve web araması (web search). Bu konu web içerik madenciliğinin (web content mining) parçasıdır.
  - Ana konular:
    - Web içerik madenciliğinin kapsamı
  - Dersin ikinci yarısında öğrencilerin dönem projesi önerileri tek tek konuşulmuştur.
* **Hocanın Vurgusu:**
  - Bilgi erişiminde dokümanlar da sorgular da yapısızdır (unstructured).
    - Veri tabanında ise hem saklama hem sorgu yapılıdır (SQL).
  - Web araması, bilgi erişiminin büyük ölçekli ve dağıtık web dokümanlarına özel bir versiyonudur.
  - Bugünkü arama motorlarının başarısı sayfalar arasındaki köprü bağlantıları (hyperlink) kullanmalarından gelir.
    - En bilinen algoritma PageRank'tir.
  - Bir bilgi erişimi modelinin dört bileşeni vardır: sorgu dili, sorgunun iç gösterimi, dokümanın iç gösterimi, sıralama fonksiyonu.
  - Vektör uzayı modeli bugün en yaygın kullanılan modeldir.

### 🔹 Ders 7: Metin Ön İşleme, Precision-Recall, Ters İndeks ve Web Crawler'lara Giriş
* **Genel Konular:**
  - Ders 17 Kasım 2020 tarihlidir.
  - O ana kadar 5. bölüm (kısmi gözetimli öğrenme, partially supervised learning) dışındaki bölümler sırayla işlenmiştir.
  - Bu derste bilgi erişimi ve web araması bölümünün kalan kısımları bitirilmiş, ardından web crawling bölümüne giriş yapılmıştır.
  - Ana konular:
    - Bilgi erişimi sisteminin genel akışının tekrarı
  - Dersin sonunda bir öğrencinin proje önerisi konuşulmuştur.
  - Vize duyurusu yapılmıştır: gelecek hafta (24 Kasım 2020), ders saatinde.
* **Hocanın Vurgusu:**
  - Vize gelecek hafta ders saatindedir.
    - Kapsam: 5. bölüm hariç ilk 6 bölüm. Crawler bölümü vizeye dahil değildir.
  - Doküman artık kendisiyle değil, temsilci vektörüyle temsil edilir.
    - Bu vektör yanlış oluşturulursa sorgu-doküman eşleştirmesi de yanlış olur.
  - Web ortamında başarı en çok Precision@10 ile ölçülür.
    - Kullanıcılar genelde ilk 10 sonuca bakar. Bulamazlarsa anahtar kelimeyi değiştirirler.
  - Web ortamında recall ölçülemez.
    - Bir sorguya karşılık gelen tüm ilgili dokümanların sayısı bilinemez.
  - Arama motorları arasındaki başarı farkı, ters indekse ne kadar ek bilgi koyduklarından gelir: kelimenin başlıkta, gövdede ya da meta etiketinde geçmesi, kalın yazılması vb.

### 🔹 Ders 10: Web Taraması: Tarayıcı Türleri, Uygulama Sorunları ve Tercihli Tarama
* **Genel Konular:**
  - Ders kitabının 8. bölümü: web taraması (web crawling).
  - Tarayıcı (crawler) neden gerekir, nasıl çalışır.
  - Durdurma koşulları (stopping condition).
  - `robots.txt` dosyası ve tarayıcı kuralları.
  - Tarayıcıların kullanım alanları.
  - Tarayıcı sınıflandırması (taxonomy): evrensel (universal) ve tercihli (preferential) tarayıcılar.
  - Odaklı (focused) ve konusal (topical) tarayıcılar.
* **Hocanın Vurgusu:**
  - Proje bilgileri ve vize notları dersin sayfasında yayınlandı.
    - Hoca bazı projelere yorum yazdı ve ek isteklerini sayfaya not etti.
  - Projesini gönderdiği hâlde hocaya ulaşmayan öğrenci haber vermeli.
    - Gönderdiğini gösteren e-postanın ekran görüntüsünü almalı. Aksi hâlde proje notu olmaz.
  - Arama ham sayfalar üzerinde yapılmaz.
    - Arama ters dizin (inverted index) üzerinde yapılır. Tarayıcı bu dizin için sayfaları toplar.
  - Tohum URL (seed URL) seçimi çok önemli.
    - Yanlış tohumla başlayan tarayıcı web'in ilgisiz yerlerini tarar. İstenen sayfalara çok geç ulaşır.
  - İndirme modülü en çok zaman alan modüldür.
    - Sebep: ağ gecikmesi (network latency).

### 🔹 Ders 11: Sosyal Ağ Analizi: Gösterimler, Merkezilik ve Prestij Ölçüleri
* **Genel Konular:**
  - Ders kitabının 7. bölümü: sosyal ağ analizi (social network analysis) ve bağlantı analizi (link analysis).
  - Bağlantı analizinin arama motorundaki yeri: TF-IDF sıralamasının üstüne popülerlik sıralaması.
  - Sosyal ağ analizi örnekleri ve neler çıkarılabileceği.
  - Yönlü (directed) ve yönsüz (undirected) çizgeler.
  - Bağlantı nitelikleri (attribute): ağırlık, sıra (rank), tür (type), olumlu/olumsuz işaret.
  - Veri gösterimleri: komşuluk matrisi (adjacency matrix), kenar listesi (edge list), komşuluk listesi (adjacency list).
  - Derece (degree), derece dizisi (degree sequence) ve derece dağılımı (degree distribution).
* **Hocanın Vurgusu:**
  - Arama motoru yalnız içerik benzerliğiyle (TF-IDF) sıralama yapmaz.
    - Ters dizinden gelen liste bağlantı analizinden çıkan popülerlik değerleriyle yeniden sıralanır.
  - Yalnız içerik benzerliğine dayalı sıralama kolay kandırılır (spam).
    - Sayfalar içeriklerine çok sayıda anahtar kelime koyar. Bu yüzden 1996 sonrası bağlantı tabanlı yöntemlere geçildi.
  - Degree centrality tek başına yeterli değildir.
    - Bağlantı sayısı çok olan bir düğüm ağın bütününde kenarda kalabilir. Betweenness ve closeness da hesaplanmalı.
  - Centrality daha çok dışa giden bağlantılarla (outlink), prestige ise gelen bağlantılarla (inlink) ilgilenir.
    - Prestige: başkaları tarafından ne kadar tercih edildiğin, yani popülerlik.
  - Betweenness örneğinde iki düğüm arasında birden fazla en kısa yol varsa katkı yol sayısına bölünür.
    - Hoca bu örneğin önemli olduğunu ve iyi takip edilmesi gerektiğini söyler.

### 🔹 Ders 13: Co-Citation, Bibliographic Coupling ve PageRank Algoritması
* **Genel Konular:**
  - Önceki dersin tekrarı: centrality ve prestige ölçüleri, rank prestige formülü.
  - Rank prestige'in matris biçimi ve özdeğer sistemi (eigensystem).
  - Co-citation ve bibliographic coupling ölçüleri.
  - Web çizgesi (web graph) ve popülerlik tabanlı sıralama gerekçesi.
  - PageRank: temel fikir, oyuncak örnekte denklem sistemi.
  - Stokastik komşuluk matrisi (stochastic adjacency matrix) ve $r = M r$ denklemi.
  - Kuvvet yinelemesi (power iteration) yöntemi.
* **Hocanın Vurgusu:**
  - Geçen hafta ders yapılamadı.
    - Hoca 1–2 ders borcu olduğunu, bu dersleri kayıt olarak sisteme yükleyeceğini söyledi.
  - PageRank ve HITS tamamen rank prestige ölçüsünün üzerine kurulmuştur.
  - Co-citation ve bibliographic coupling formüllerini ezberlemeye gerek yok.
    - Matris üzerindeki mantık hatırlanırsa formül kolayca yazılır.
  - Yalnız içerik benzerliğine (TF-IDF) dayalı arama kandırılmaya (spam) açıktır.
    - Popülerlik tabanlı ölçüler güvenilir ve sorguya uyan sayfaları ilk 10 sonuçta göstermeye yarar.
  - PageRank'te iki şeye bakılır: bir düğümün aldığı bağlantılar ve bu bağlantıları veren düğümlerin PageRank değerleri.

### 🔹 Ders 14: HITS Algoritması ve Web Kullanım Madenciliği
* **Genel Konular:**
  - Bağlantı analizinin tekrarı: centrality, prestige, co-citation, bibliographic coupling, PageRank.
  - PageRank'in sorgudan bağımsız (query independent) olması ve sonucu.
  - HITS (Hypertext Induced Topic Search) algoritması: otorite (authority) ve merkez (hub) puanları.
  - Kök küme (root set) ve taban küme (base set).
  - HITS'in matris biçimi ve co-citation, bibliographic coupling matrisleriyle bağı.
  - HITS'in güçlü ve zayıf yanları.
  - Ders kitabının 12. bölümü: web kullanım madenciliği (web usage mining).
* **Hocanın Vurgusu:**
  - Bağlantı analizi bölümündeki tüm ölçüler çok önemli.
    - Sınavda büyük olasılıkla çıkacak. Verilen örnek bir çizge üzerinde PageRank, HITS, co-citation, bibliographic coupling ve sosyal ağ ölçülerinin hesaplanması iyi bilinmeli.
  - PageRank sorgudan bağımsızdır.
    - Bu yüzden çok popüler ama sorguya en uygun olmayan sayfalar ilk 10 sonuca girebilir.
  - HITS sorguya bağlıdır (query dependent).
    - Puanlar sorgu anında, sorgunun sonuçlarından kurulan küçük çizge üzerinde hesaplanır.
  - Web kullanım madenciliğinde sunucu günlük (log) kaydı şekli önemli.
    - Hoca bu şekle iyi bakılmasını istedi.
  - Oturum belirleme ve kullanıcı belirleme iyi öğrenilmeli.
    - Sınavda çıkabilir. Farklı tekniklerin kullanım madenciliğinde hangi amaçla kullanıldığı da bilinmeli.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
