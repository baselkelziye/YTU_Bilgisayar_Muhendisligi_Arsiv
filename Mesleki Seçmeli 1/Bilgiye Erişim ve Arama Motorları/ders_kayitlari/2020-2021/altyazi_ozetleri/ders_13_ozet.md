# Ders 13 Çalışma Özeti

## Genel Konular

- Dersin tarihi 7 Ocak 2021 Perşembe, dönemin son haftası. Zoom üzerinden yapıldı. Kayıt yaklaşık 4 saat 45 dakika sürüyor.
- Bu derste konu anlatılmadı. Bütün kayıt dönem projesi sunumlarından oluşuyor.
  - Gruplar bekleme odasına (waiting room) alındı. Her grup sırayla toplantıya alınıp projesini sundu.
  - Sunum düzeni: önce öneri (proposal) belgesine göre amaç, sonra çalışan demo, sonra kodların anlatımı.
- Sunulan projeler dersin dört ana konusuna göre gruplanabilir:
  - **Web tarayıcı (crawler) uygulamaları:** Birden fazla e-ticaret sitesinden ürün verisi toplayıp tek sayfada gösterme ve filtreleme.
  - **Sınıflandırma projeleri:** Haber başlığı sınıflandırma, kredi kartı sahtecilik (fraud) tespiti, blog sayfası olup olmadığını belirleme, yorum kaldırma tahmini.
  - **Öneri sistemleri (recommendation systems):** Film, şarkı, ürün ve akademik makale başlığı önerisi.
  - **Fikir madenciliği (opinion mining) ve duygu analizi (sentiment analysis):** Tweet duygu analizi, haber metinlerinde taraf belirleme, ürün yorumu analizi, emoji tabanlı duygu kümeleme.

## Hocanın Özellikle Vurguladığı Kısımlar

- **Grup üyelerinin hepsi sunumda bulunmalı.** Bir üyenin "çalışıyorum, katılamayacağım, arkadaşım sunsun" diye yazdığı grubun sunumu kabul edilmedi. İki üye birlikte bekleme odasına geldiğinde yeniden sunum hakkı verileceği söylendi.
- **Ekran paylaşımı yapılabilmeli.** Teknik sorunu önceden çözmek grubun sorumluluğu.
- **Crawler projelerinde filtreleme şart.** Birden fazla siteden toplanan veri kategoriye ve fiyata göre süzülüp sıralanabilmeli.
  - Hocanın örneği: E-ticaret sitesinde bütün ürünler yerine yalnız Nike ürünlerini ya da yalnız 43 numara ayakkabıları görmek istersiniz.
  - Verileri yalnız CSV'ye yazıp filtrelemeyi arayüze koymayan grubun projesi eksik bulundu. Hoca, projeyi kabul ederken istediğinin bu olmadığını söyledi.
- **Öneri sistemlerinde değerlendirme (evaluation) gerekli.** Yalnız benzerlik skorlarını listelemek yeterli değil. Yapılan önerilerin iyi mi kötü mü olduğu bir değerlendirme yöntemiyle gösterilmeli.
- **Sınıflandırma projelerinde en az üç farklı algoritma.** Kendi etiketli verinizle üç ayrı model eğitilip karşılaştırılmalı. Hazır bir kütüphane fonksiyonuyla (ör. TextBlob'un duygu fonksiyonu) sonuç almak yeterli değil.
  - Az veriyle bile etiketleyip model kuran gruplar var.
  - Hoca derste işlenen tekniklerin kodun içinde görülmesini istiyor.
- **Zaman yönetimi:** Proje iki ay önceden verildi ve öneri belgesi istendi. Öneri belgesinde ne zaman, neyin yapılacağı yazılıyordu. Hoca "başka derslerin projeleri vardı" gerekçesini kabul etmedi. Bunun nota yansıyacağını söyledi.
- **Teslim:** Kodlar Google Drive bağlantısıyla, readme dosyasıyla birlikte gönderilmeli. Bazı gruplar GitHub ve Heroku bağlantısı gönderdi. Hoca kodun proje olarak gönderilmesini istedi.
- Bitirme projesinden uyarlanan projeler de sunuldu. Hoca bunları biliyordu.
- Sunumun sonunda hoca final sınavı haftasına geçildiğini söyledi ve sınavlarda başarılar diledi.

## Kısa Tekrar Notları

- Proje değerlendirmesinde bakılanlar:
  - Öneri belgesiyle uyum.
  - Çalışan bir kullanıcı arayüzü ve canlı demo.
  - Kodların anlatılması ve sorulara cevap.
  - Derste işlenen tekniklerin (TF-IDF, sınıflandırıcılar, öneri yöntemleri, crawler) kullanılması.
  - Sonuçların değerlendirilmesi: sınıflandırmada precision, recall, F1, accuracy; öneride bir başarı ölçütü.
  - Teslim edilen paketin readme ile başkasının bilgisayarında çalışabilmesi.
- Sunumlarda geçen yöntemler:
  - Scrapy ve Selenium ile tarama, Django ya da React ile arayüz, MongoDB ya da Firebase ile saklama.
  - TF-IDF vektörleri ve kosinüs benzerliği (cosine similarity) ile isim tabanlı ürün önerisi.
  - Pearson korelasyonu ile kullanıcı tabanlı işbirlikçi filtreleme (user-based collaborative filtering), MovieLens veri seti.
  - scikit-learn ile Decision Tree, Random Forest, Naive Bayes, Logistic Regression, SGD.
  - Word2Vec, LSTM, metin vektörleştirme (vectorizer).

## Detaylı Açıklamalar

### Örnek crawler projesi akışı

- Hedef: Hepsiburada ve n11'den dizüstü bilgisayarların markasını, fiyatını, özelliklerini ve satış bağlantısını toplamak.
- Selenium tarayıcıyı sürekli çalıştırdığı için yavaş bulundu. Scrapy'ye geçildi.
- Scrapy örümceğinde (spider) başlangıç URL'si, XPath ile fiyat, bağlantı ve özellik alanları tanımlandı. Sayfa numarası artırılarak 50 sayfa tarandı.
- Fiyat metni ondalık sayıya çevrildi. Yoksa fiyat aralığına göre süzme çalışmıyordu.
- Sonuçlar CSV'ye yazıldı ve Django ile bir veri tablosunda gösterildi. Tabloda en düşük ve en yüksek fiyat, marka ve özellik (ör. 4 GB) ile arama yapılabiliyor. Satırdaki bağlantı ürünün satıldığı siteye götürüyor.

### Örnek ürün takip ve öneri projesi

- Kullanıcı Google hesabıyla giriş yapıyor. Her kullanıcı için Firebase'de bir tablo tutuluyor.
- Kullanıcı ürün bağlantısını ekliyor. Sistem ürünün adını, fiyatını ve fotoğrafını tarayıp çekiyor. Kullanıcı bir hedef fiyat ve not girebiliyor.
- Öneri: Birkaç sitenin indirimli ve çok satan ürünleri taranıyor. Ürün adları TF-IDF ile vektörleştiriliyor. Eklenen ürüne kosinüs benzerliği en yüksek ürün öneriliyor.
- Hedef fiyata ulaşınca bildirim gönderme özelliği tamamlanamadı.

### Örnek haber sınıflandırma projesi

- Bir haber veri setinin başlıkları 5 kategoriye ayrıldı. Eğitim verisi dengeli olacak şekilde örneklendi.
- Decision Tree, Random Forest ve Naive Bayes eğitildi. Doğruluklar sırasıyla yaklaşık %58, %67 ve %73 çıktı.
- Twitter API ile iki haber hesabının son tweetleri çekildi. Resim bağlantıları düzenli ifadeyle (regex) temizlendi ve model her tweete kategori tahmin etti.
- Grup, veri setinin 2017'ye kadar olduğunu fark etti. COVID ile ilgili tweetler ve sonraki siyasi olaylar doğru sınıflanamıyordu. Bu, eğitim verisinin zamanla eskimesine (concept drift) güzel bir örnek.

### Örnek film öneri projesi

- MovieLens veri setinde yaklaşık 20 milyon puan ve 140 bin kullanıcı var.
- En çok puan veren 100 kullanıcı alındı. Girilen kullanıcı puanlarıyla Pearson korelasyonu hesaplandı ve en benzer 50 kullanıcı seçildi.
- Her film için benzerlikle ağırlıklandırılmış puanlar toplandı ve benzerliklerin toplamına bölündü. En yüksek ortalama skora sahip 10 film önerildi.
- Grup yöntemi "content-based" diye adlandırdı. Anlatılan yöntem kullanıcı tabanlı işbirlikçi filtrelemedir.

### Ders sonrası notlar

- **Yöntem adı:** Film öneri grubunun anlattığı yöntem (benzer kullanıcıların ağırlıklı puan ortalaması) içerik tabanlı (content-based) değil, kullanıcı tabanlı işbirlikçi filtrelemedir (user-based collaborative filtering). İçerik tabanlı yöntem filmlerin özelliklerine (tür, oyuncu, etiket) bakar.
- **Öneri değerlendirmesi:** Hocanın istediği değerlendirme için yaygın ölçütler: bekletilen (hold-out) puanlarda RMSE ya da MAE, ilk $k$ öneride precision@k ve recall@k.
- **Kişisel bilgiler:** Kayıtta öğrencilerin adları, öğrenci numaraları ve ekranlarındaki belgeler görünüyor. Özete bunların hiçbiri alınmadı.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
