# Büyük Veri İşleme ve Analizi Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.

### 📋 Genel Bilgiler
* **Ders:** Büyük Veri İşleme ve Analizi (BLM4120)
* **Hoca:** Prof. Dr. Mehmet Sıddık Aktaş
* **Dönem:** Bahar
* **Akademik Yıl:** 2022-2023
* **Şube:** BLM4120 - 1

Bu dizin, ilgili ders kayıtlarının altyazı özetlerini, çalışma notlarını ve PDF kaynaklarını içermektedir.

## 📚 Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu, kaynak markdown dosyası ve doğrudan indirilebilir PDF formatındaki derlenmiş halleri listelenmiştir. Ders numaraları, kayıt arşivindeki ders kaydı sıra numaralarıdır (hafta numarası değildir).

| Ders No | Ders İçeriği / Konu Başlıkları | Kaynak Notlar (Markdown) | Çalışma Dosyası (PDF) |
| :---: | :--- | :---: | :---: |
| **Ders 1** | Derse Giriş, Büyük Veri Kavramları ve Dersin İşleyişi | [Özet](altyazi_ozetleri/ders_1_ozet.md) | [PDF (İndir)](ders_1_ozet.pdf) |
| **Ders 2** | Dağıtık Dosya Sistemleri ve MapReduce Programlama Modeli | [Özet](altyazi_ozetleri/ders_2_ozet.md) | [PDF (İndir)](ders_2_ozet.pdf) |
| **Ders 3** | MapReduce İyileştirmeleri, Shingling ve MinHashing | [Özet](altyazi_ozetleri/ders_3_ozet.md) | [PDF (İndir)](ders_3_ozet.pdf) |
| **Ders 4** | Benzer Dokümanlar: MinHashing ve Locality Sensitive Hashing | [Özet](altyazi_ozetleri/ders_4_ozet.md) | [PDF (İndir)](ders_4_ozet.pdf) |
| **Ders 5** | Büyük Veride Kümeleme: Hiyerarşik, K-Means, BFR ve CURE | [Özet](altyazi_ozetleri/ders_5_ozet.md) | [PDF (İndir)](ders_5_ozet.pdf) |
| **Ders 7** | Veri Akışları: Bloom Filtresi, DGIM ve Dönem Projesi | [Özet](altyazi_ozetleri/ders_7_ozet.md) | [PDF (İndir)](ders_7_ozet.pdf) |
| **Ders 8** | Bağlantı Analizi ve PageRank: Stokastik Matris, Kuvvet Yinelemesi ve Işınlanma | [Özet](altyazi_ozetleri/ders_8_ozet.md) | [PDF (İndir)](ders_8_ozet.pdf) |
| **Ders 10** | Öneri Sistemleri: İçerik Tabanlı Öneri ve İşbirlikçi Filtreleme | [Özet](altyazi_ozetleri/ders_10_ozet.md) | [PDF (İndir)](ders_10_ozet.pdf) |
| **Ders 12** | Sık Öğe Kümeleri ve Birliktelik Kuralları: Apriori, PCY, Multistage ve Multihash | [Özet](altyazi_ozetleri/ders_12_ozet.md) | [PDF (İndir)](ders_12_ozet.pdf) |
| **Ders 14** | Dönem Projesi Değerlendirmeleri | [Özet](altyazi_ozetleri/ders_14_ozet.md) | [PDF (İndir)](ders_14_ozet.pdf) |

> [!NOTE]
> 5 Nisan 2023 (6. ders) hoca konferansta olduğu için ders yapılmamıştır. 9, 11 ve 13 numaralı ders kayıtları arşivde bulunmamaktadır.

## 🎯 Derslerin Detaylı Özetleri ve Kazanımları

### 🔹 Ders 1: Derse Giriş, Büyük Veri Kavramları ve Dersin İşleyişi
* **Genel Konular:**
  - Dersin işleyişi, değerlendirme ve takvim.
  - Ders kitabı: Mining of Massive Datasets (MMDS). Kitabın web sitesi, slaytlar ve videolar.
  - Büyük verinin (big data) kaynakları ve neden özel algoritmalar gerektirdiği.
  - Dağıtık depolama (distributed storage): parçalama ve kopyalama (replication).
  - Veriden bilgi çıkarma: tanımlayıcı (descriptive) ve tahmine dayalı (predictive) yöntemler.
  - Verinin gerçek hayatı yansıtması gerekliliği.
  - Büyük verinin zorlukları, veri türleri (modality) ve bir büyük veri sisteminin bileşenleri.
* **Hocanın Vurgusu:**
  - Değerlendirme (ekrandaki "important dates" belgesi):
    - 1. vize (midterm): %30, 8. hafta, 19 Nisan 2023.
  - Proje önerisi (term project proposal): 4. haftada (gecikirse 5. haftada) bir sayfalık öneri istenecek.
    - Öğrenciler, işlenecek konularla ilgili proje fikri ve kullanılacak veri setlerini araştıracak.
  - Başarı notu 40'ın altında olan öğrenci dersten FF ile kalır.
    - 40, CC'ye karşılık gelmez (yönetmelik notu).
  - Derse katılım: Üniversitenin istediği oran %75.
    - Hoca en az %60 katılım bekliyor. Kayıtlar sonradan izlenebilse de derse katılım isteniyor.
  - Ders sayfası duyurular için takip edilmeli.
    - Hoca, derslerden bir gün önce sayfaya bakılmasını istedi. Ders sayfası ve kitap sitesi linkleri chatte paylaşıldı.

### 🔹 Ders 2: Dağıtık Dosya Sistemleri ve MapReduce Programlama Modeli
* **Genel Konular:**
  - Tek makinede büyük veri işlemenin sınırları: bellek ve disk okuma hızı.
  - Küme hesaplama (cluster computing): raf kabinleri (rack), anahtarlar (switch), sıradan (commodity) Linux sunucular.
  - Düğüm arızaları (node failure) ve uzun süren hesaplamalarda arıza.
  - Ağ darboğazı (network bottleneck) ve dağıtık programlamanın karmaşıklığı.
  - Dağıtık dosya sistemi (distributed file system, DFS): parça sunucuları (chunk server), ana düğüm (master node / NameNode), istemci kütüphanesi (client library).
  - Hangi veri DFS'de tutulur: çok büyük, nadiren güncellenen, genelde sona eklenen (append) veri.
  - Kelime sayma (word count) örneği: Linux komut zinciri ve MapReduce karşılığı.
* **Hocanın Vurgusu:**
  - CPU yalnız fiziksel bellekteki veriyle çalışır.
    - Disk ile CPU arasında doğrudan bağlantı yoktur. Bu yüzden belleğe sığmayan veri birden fazla makineye bölünmelidir.
  - Hesaplamayı veriye taşı, veriyi hesaplamaya taşıma.
    - Kodun boyutu verinin boyutundan çok küçüktür. Ağ üzerinden yalnız ara sonuçlar taşınır.
  - MapReduce üç sorunu çözer:
    - Veriyi birden fazla düğümde yedekli (redundant) saklayarak kalıcılık (persistency) ve erişilebilirlik sağlar.
  - Programcı yalnız iki fonksiyon yazar: `map` ve `reduce`.
    - Gruplama (group by key), taşıma, zamanlama ve arıza yönetimi kütüphaneye (Hadoop, Spark vb.) aittir.
  - Group by key adımı hiçbir hesaplama yapmaz.
    - Yalnız aynı anahtarlı (key) çiftleri bir araya getirir.
* **Detaylı Açıklamalar:** reduce(key, values): // key: kelime; values: sayılar result = 0 for each count v in values: result += v emit(key, result) ```

### 🔹 Ders 3: MapReduce İyileştirmeleri, Shingling ve MinHashing
* **Genel Konular:**
  - MapReduce'un kısa tekrarı: Map, Group by Key, Reduce, arıza yönetimi.
  - Büyük veri yazılım yığını (big data stack): HDFS, YARN / Mesos, Hadoop / Spark.
  - MapReduce iyileştirmeleri (refinements):
    - Birleştirici (combiner) fonksiyonu.
  - MapReduce uygulamaları ve bulut ortamları.
  - Örnek sınav sorusu: asal bölenlerle MapReduce.
  - 3. bölüm: Benzer belgeleri bulma problemi ve uygulamaları.
  - Üç adım: shingling, MinHashing, yerele duyarlı özetleme (Locality Sensitive Hashing, LSH).
* **Hocanın Vurgusu:**
  - Bu ders önemli.
    - Dönem projesi tamamen MapReduce programlama modeli üzerine olacak. Projede herkes HDFS kullanacak.
  - Sınavda da benzer MapReduce soruları çıkabilir: Verilen Map ve Reduce tanımıyla girdiden çıktıyı bulma.
  - MapReduce'ta en çok zaman alan iş, ara çiftlerin Map sunucularından Reduce sunucularına kopyalanmasıdır.
    - Birleştirici bu trafiği azaltır.
  - Birleştirici, programcının yazdığı üçüncü fonksiyondur.
    - Reduce ile aynı hesabı yapar ama Map sunucusunda, yerel veriler üzerinde çalışır.
  - Birleştirici yalnız Reduce fonksiyonu değişme ve birleşme özelliklerine sahipse eklenebilir.
    - Toplama uygundur. Ortalama ve medyan doğrudan uygun değildir.

### 🔹 Ders 4: Benzer Dokümanlar: MinHashing ve Locality Sensitive Hashing
* **Genel Konular:**
  - Ders 22 Mart 2023 Çarşamba günü online yapıldı.
  - Hoca dersi Türkçe ve İngilizce karışık anlattı.
  - Konu: 3. bölüm (chapter 3), büyük veri kümelerinde benzer kümeleri bulma (Finding Similar Sets).
  - İşlenen konular:
    - Benzer doküman bulmanın kullanım alanları.
  - 3. bölüm bu derste bitti.
  - Dönem projesi için ilk duyurular yapıldı.
* **Hocanın Vurgusu:**
  - **Problemin büyüklüğü.** Doküman sayısı çok fazla ve her doküman çok büyük.
    - Veri tek bir bilgisayarın belleğine sığmaz. Bu bölümdeki algoritmalar problemi tek bilgisayar belleğiyle bile çözmeyi sağlar.
  - **Üç aşamalı süreç:** Shingling, MinHashing, Locality Sensitive Hashing.
  - **MinHashing'in temel ilkesi.** İki dokümanın imza matrisindeki benzerliği, girdi matrisindeki Jaccard benzerliğine yakınsar.
    - Bu yüzden benzerliğe imza matrisi üzerinden bakılabilir.
  - **İmza matrisinin asıl avantajı az yer kaplamasıdır.** Kolon sayısı aynı kalır.
    - Satır sayısı hash fonksiyonu sayısına düşer.
  - **Permütasyon tabanlı hash büyük veride uygun değildir.** Her hash fonksiyonu için milyonlarca satırlık bir permütasyonu bellekte tutmak gerekir.
    - Bunun yerine $h(x) = (ax+b) \bmod n$ biçimli hash fonksiyonları kullanılır.

### 🔹 Ders 5: Büyük Veride Kümeleme: Hiyerarşik, K-Means, BFR ve CURE
* **Genel Konular:**
  - Ders 29 Mart 2023 Çarşamba günü online yapıldı.
  - Ders büyük ölçüde İngilizce anlatıldı. Bazı kısımlar Türkçe tekrar edildi.
  - Konu: 7. bölüm (chapter 7), büyük veri kümelerinde kümeleme (clustering).
  - İşlenen konular:
    - Kümelemenin tanımı ve neden zor olduğu.
  - Gelecek hafta ders yok. Vize ve dönem projesi duyuruları yapıldı.
* **Hocanın Vurgusu:**
  - **Kümeleme gözetimsiz öğrenmedir (unsupervised learning).** Amaç verinin altındaki yapıyı ve bölümleri (segment) bulmaktır.
  - **Kümelemeyi zorlaştıran üç şey:**
    - Gerçek verilerde kümeler birbirine çok yakındır.
  - **Hiyerarşik kümeleme bellek içi (in-memory) bir algoritmadır.** İyi sonuç verir, iç içe geçmiş yapıları da bulabilir.
    - Ama zaman karmaşıklığı yüksektir ve bütün verinin bellekte olmasını ister. Büyük veride doğrudan kullanılamaz.
  - **Merkez hesaplanırken yalnız o kümedeki noktalar kullanılır.** Bütün veri kümesi kullanılmaz.
    - Bu, derste bir öğrencinin sorusu üzerine açıklandı.
  - **K-means ve BFR yalnız Öklid uzayında çalışır.** Öznitelik değerleri sayısal olmalıdır.
* **Detaylı Açıklamalar:** 1. Çok noktalı bir küme nasıl temsil edilir? 2. İki kümenin yakınlığı nasıl ölçülür? 3. Birleştirmeye ne zaman son verilir?

### 🔹 Ders 7: Veri Akışları: Bloom Filtresi, DGIM ve Dönem Projesi
* **Genel Konular:**
  - Ders 12 Nisan 2023 Çarşamba günü online yapıldı. 5 Nisan'da ders yapılmadı.
  - Ders İngilizce anlatıldı. Bazı kısımlar Türkçe tekrar edildi.
  - Şu ana kadar işlenen bölümler: 1, 2, 3 ve 7. Bu derste 4. bölüm (chapter 4) başladı: veri akışlarında madencilik (Mining Data Streams).
  - İşlenen konular:
    - Akış verisi (stream data) ve akış veri yönetim sistemi (DSMS).
  - Dersin sonunda dönem projesi ayrıntılı anlatıldı.
  - Vize tarihi konuşuldu.
* **Hocanın Vurgusu:**
  - **Akış verisinde giriş hızı sistemin kontrolünde değildir.** İlişkisel veritabanında veriyi geliştirici ekler.
    - Akışta veri dışarıdan, istediği zaman ve hızda gelir.
  - **Akış verisi arşivlenir ama sorgulanmaz.** Arşiv genellikle HDFS gibi dağıtık bir sistemdedir.
    - Bu arşiv operasyonel veritabanı değildir; üzerinde sorgu çalıştırmak çok uzun sürer.
  - **Asıl hesap sınırlı bellekte yapılır.** Akış hakkındaki özet bilgi (en büyük, en küçük, ortalama, standart sapma vb.) bellekte tutulur ve her yeni elemanla güncellenir.
  - **Bloom filtresinde yanlış pozitif olabilir, yanlış negatif olmaz.** Filtre "görmedim" diyorsa %100 doğrudur.
  - **İkili sayıya çevirme bilinmeli.** Bir öğrenci sordu.
    - Hoca bunun sınavda bilinmesi gereken temel bir beceri olduğunu söyledi.

### 🔹 Ders 8: Bağlantı Analizi ve PageRank: Stokastik Matris, Kuvvet Yinelemesi ve Işınlanma
* **Genel Konular:**
  - Vize ve dönem projesi teklifi duyuruları.
  - Büyük veri türleri: yüksek boyutlu veri, graf verisi, sonsuz (akış) veri.
  - Graf verisi örnekleri: sosyal ağlar, atıf ağları, internet ve web (World Wide Web).
  - Web grafı: düğümler web sayfaları, kenarlar köprüler (hyperlink). Yönlü graf.
  - Web'de bilgiye erişim: dizin (directory) gezme ve web araması (web search).
  - Web aramasının iki zorluğu: kime güvenilecek (spam sayfalar) ve sorguya en iyi cevap hangisi.
  - Bağlantı analizi (link analysis) ve popülerlik tabanlı sıralama. PageRank ve HITS.
* **Hocanın Vurgusu:**
  - **Vize:** 28 Nisan Cuma öğleden sonra.
    - Ders sonunda kesin tarihin bölüm sitesinde ilan edildiği söylendi.
  - **Vize biçimi:** Online.
    - Büyük olasılıkla çoktan seçmeli. Doğru/yanlış, kutucuk işaretleme ve boşluk doldurma soruları da olabilir. Açık uçlu soru yok.
  - **Vize konuları:** 1, 2, 3 ve 4. bölümler, bağlantı analizi bölümü ve kümeleme bölümü (7. bölüm).
  - **Proje teklifi son tarihi:** 2 Mayıs Salı, gün sonuna kadar.
    - Uzatma yok.
  - **Teklif, proje belgesinde yazan e-posta adresine gönderilecek.** Hocanın okul e-postasına gönderilmeyecek.
    - Belge ders sitesinde.

### 🔹 Ders 10: Öneri Sistemleri: İçerik Tabanlı Öneri ve İşbirlikçi Filtreleme
* **Genel Konular:**
  - Vize sonuçları, not ağırlıkları ve dönem projesi takvimi.
  - Öneri sistemleri (recommendation systems), kitabın 9. bölümü.
  - Fiziksel mağaza ile çevrimiçi mağaza farkı ve uzun kuyruk (long tail) olgusu.
  - Öneri türleri: editoryal (elle seçilmiş), istatistik tabanlı (en çok satanlar), kişiye özel.
  - Fayda fonksiyonu (utility function) ve fayda matrisi (utility matrix).
  - Öneri sistemlerinin üç sorunu: bilinen puanları toplamak, bilinmeyen puanları tahmin etmek, başarıyı ölçmek.
  - Açık (explicit) ve örtük (implicit) puanlar.
* **Hocanın Vurgusu:**
  - **Vize ağırlığı %30.** Müfredatta %40 yazıyor ama bu bir hata.
  - **Dönem projesi de %30.** Bu yüzden proje çok önemli.
  - **Proje teklifi son günü bu ders günüydü** (3 Mayıs), gün sonuna kadar.
    - Teklif göndermeyen proje yapmayacak sayılır.
  - **Onay beklemeden projeye başlayın.** Değişiklik gereken teklifler için hoca kendisi iletişime geçecek.
    - Haber gelmezse teklif kabul edilmiş sayılır.
  - **Proje teslimi ve demo dönemin son haftasında, çarşamba günü.** Her grup kodunu gösterecek, demo yapacak ve kısa bir sunumla projeyi anlatacak.
    - Şimdilik sınıfta yapılması planlanıyor. Değişiklik olursa online da yapılabilir.
* **Detaylı Açıklamalar:** 1. **Bilinen puanları toplamak:** Az kişi geri bildirim verir. 2. **Bilinmeyen puanları tahmin etmek:** Hangi algoritma kullanılacak? 3. **Başarıyı ölçmek:** Öneri algoritmasının performansı nasıl değerlendirilecek?

### 🔹 Ders 12: Sık Öğe Kümeleri ve Birliktelik Kuralları: Apriori, PCY, Multistage ve Multihash
* **Genel Konular:**
  - Dönem projesi hatırlatması.
  - Kitabın 6. bölümü: sık öğe kümeleri (frequent itemsets).
  - Pazar sepeti modeli (market basket model): öğeler (items) ve sepetler (baskets).
  - Destek (support) eşiği ve sık öğe kümesi tanımı.
  - Uygulamalar: süpermarket, intihal (plagiarism) tespiti, birlikte geçen kelimeler.
  - Birliktelik kuralları (association rules) ve güven (confidence) eşiği.
  - Sık öğe kümelerinden kural çıkarma.
* **Hocanın Vurgusu:**
  - **Proje teslimi dönemin son haftasındaki ders saatinde.** O gün her grup projesini anlatacak ve demo yapacak.
    - Hoca projeyle ilgili ve projenin tamamlanıp tamamlanmadığına dair sorular soracak.
  - **Proje ağırlığı vizeyle aynı: %30.** Soruları e-postayla sorun, cevapsız soru bırakmayın.
  - 6. bölümün slaytları ders sitesinde.
  - **Birliktelik kuralı madenciliğinde zor kısım sık öğe kümelerini bulmaktır.** Sık kümeler bulunduktan sonra kural çıkarmak kolaydır.
  - **Bu algoritmalarda maliyet CPU süresiyle değil, disk geçişi sayısıyla ölçülür.** Diske her erişim CPU'ya göre çok pahalıdır.

### 🔹 Ders 14: Dönem Projesi Değerlendirmeleri
* **Genel Konular:**
  - Dönem projesi (term project) değerlendirmelerinin işleyişi.
  - Breakout odalarına katılma talimatı.
* **Hocanın Vurgusu:**
  - Hoca 50 tane breakout odası açtı.
  - Her proje grubu, proje arkadaşıyla birlikte boş bir odaya girip sırasını bekleyecek.
  - Hoca odalara rastgele bir sırayla girip projeleri orada değerlendirecek.
  - Ana odada (genel alanda) beklenmemeli.
    - Ana oda, bulunulmaması gereken yer.
  - Proje arkadaşı henüz gelmediyse öğrenci yine bir odaya girmeli ve arkadaşına hangi odada olduğunu yazmalı.
    - Arkadaşı gelince aynı odaya katılır.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
