# Ders 6 Çalışma Özeti

19 Kasım 2020 Perşembe, online ders (yaklaşık 1 saat). Dersin ilk yarısı Türkçe tekrar, ikinci yarısı İngilizce. Konu: Bing Liu, *Web Data Mining*, Chapter 6 (Information Retrieval and Web Search) devamı.

## Genel Konular

- Vize bilgisi ve sınav kapsamı
- Önceki dersin Türkçe tekrarı
  - IR modelleri, dokümanın ve sorgunun vektör temsili
  - TF-IDF, kosinüs benzerliği, Okapi
  - İlgililik geri bildirimi (relevance feedback) ve sorgu genişletme (query expansion)
- Metin ön işleme (text pre-processing)
  - Durak kelimelerin çıkarılması (stopword removal)
  - Kök bulma (stemming)
  - TF-IDF ağırlıklarının hesaplanması
- Erişim değerlendirmesi: kesinlik (precision) ve duyarlılık (recall)
  - Precision@10 gibi web ölçütleri, precision-recall eğrisi
- Web aramasındaki zorluklar: çok anlamlı sorgular, otoriter sayfalar, çeşitlilik
- Ters indeks (inverted index) ve arama sırasında indeksin kullanılması
- Arama motorlarını başarılı kılan etkenler

## Hocanın Özellikle Vurguladığı Kısımlar

- Vize gelecek hafta, saat 15:00'te. Çakışması olan hocaya bildirmeli.
- Vize kapsamı: şimdiye kadar işlenen tüm bölümler, Chapter 5 hariç.
- Sınava hazırlık:
  - Yalnızca slaytlar değil, kitaptaki ilgili bölümler de okunmalı.
  - Slaytlardakine benzer kitap örnekleri çalışılmalı.
  - Bölüm sonu soruları gözden geçirilmeli.
- Sınav biçimi:
  - Çoktan seçmeli, doğru/yanlış ve boşluk doldurma soruları.
  - Yaklaşık 45 dakika, en fazla 1 saat.
  - Okulun yeni sınav aracı kullanılacak.
- Kosinüs benzerliği önemli; Okapi formülünü ezberlemeye gerek yok.
- Önce durak kelimeler çıkarılır, sonra kök bulma uygulanır. İkisi de kural tabanlı ayrıştırıcıdır (rule-based parser).
- Global arama motorlarında recall ölçülemez, çünkü toplam ilgili doküman sayısı bilinmez. Bu yüzden Precision@10, @20, @30 kullanılır.

## Kısa Tekrar Notları

- Durak kelimeler kendi başına anlamı olmayan kelimelerdir (İngilizcede "the", "of", "to"; Türkçede bağlaçlar). Hocaya göre çıkarılmaları indeks boyutunu yaklaşık %30 küçültür.
- Kök bulma, kelimenin tüm biçimleri yerine kökünü indeksler ("users, used, using" yerine "use"). Hocaya göre indeks boyutunu %40–50 küçültür.
- Her dilin kendi kök bulma kuralları vardır; Türkçenin de vardır.
- $A$ ilgili dokümanlar, $B$ getirilen dokümanlar olmak üzere:
  - $precision=\frac{|A\cap B|}{|B|}$: getirilenlerin ne kadarı ilgili?
  - $recall=\frac{|A\cap B|}{|A|}$: ilgililerin ne kadarı getirildi?
- Precision-recall eğrisinde x ekseni recall (%10, %20, ..., %100), y ekseni precision'dır. Birden çok sorgunun ortalaması alınır.
- Ters indeks: her kelime için o kelimeyi içeren dokümanların listesi (posting list).
- Gelişmiş girdi biçimi: (doküman kimliği, kelimenin geçme sayısı, konum).
- Sıralama iki bileşenlidir:
  - İçerik tabanlı: TF-IDF.
  - Bağlantı tabanlı: PageRank, HITS.

## Detaylı Açıklamalar

### Sınav ve Ders Duyuruları

- Ders kitabında şimdiye kadar ilk 4 bölüm ve Chapter 6 işlendi. Chapter 5 (Partially Supervised Learning) işlenmedi.
- Ders sayfasında Chapter 5 ve 6 slaytlarının eksik olduğu söylendi. Hoca Chapter 6 slaytlarını ekleyeceğini söyledi.
- Kitabın sitesinde de tüm bölümlerin slaytları ve PDF'leri var.
- Vize saati sabah planlanmıştı, öğleden sonraya (15:00) alındı.
- Proje önerileri incelenmeye başlandı. Sonuçlar hafta sonu bir Excel dosyasıyla ders sayfasında duyurulacak.

### IR Modellerinin Tekrarı (Türkçe)

- IR modeli sorgunun ve dokümanın iç temsilini ve aralarındaki karşılaştırma ölçütünü tanımlar.
- Doküman setindeki tüm terimler sözlüğü oluşturur. $n$ terim varsa her doküman $n$ boyutlu bir vektördür.
- Boolean modelde vektörde 1 ve 0 vardır, eşleşme tam eşleşmedir (sorguyu true yapan dokümanlar).
- Vektör uzayı modelinde ağırlık TF-IDF'tir, benzerlik kosinüs ile ölçülür.
- Arama motorları kullanıcının sorgusuna görünmeden kelime ekleyebilir:
  - Önceki aramalardan çıkarılan kelimeler.
  - Kullanıcının bulunduğu şehir ve ülke (ör. elektronik cihaz aramasında yakındaki mağazalar çıksın diye).
- İlgililik geri bildirimi:
  - Özellikle IEEE, ACM gibi özel arama motorlarında bulunur.
  - Kullanıcı sonuçlardan ilgili olanları işaretler ve "Refine Search Results" der.
  - Sistem ilgili sayfalarda sık geçen terimleri sorguya ekler, ilgisiz işaretlenenlerdeki terimleri çıkarır.
  - Örneğin 2 kelimelik sorgu 5 kelimeye genişler ve arama tekrarlanır.

### Metin Ön İşleme

İndeksleyici (indexer) doküman koleksiyonunu işleyip arama yapılacak indeksi oluşturur. Adımlar:

1. Dokümanlardan anlamlı terimler çıkarılır, durak kelimeler atılır.
2. Kök bulma uygulanır ("engineering, engineers, engineer" tek girdi olur).
3. Her dokümandaki her terim için TF-IDF hesaplanır.
4. Her doküman, elemanları TF-IDF olan bir vektörle indekste temsil edilir.

### Değerlendirme: Precision ve Recall

Getirilen sonuçların iyi olup olmadığını anlamak için iki soru sorulur:

- Getirilen dokümanların hepsi ilgili mi? Bu precision'dır.
- İlgili dokümanların hepsi getirildi mi? Bu recall'dur.

Örnek: koleksiyonda sorguyla ilgili 15 doküman var, sistem ilk 10 sonucu gösteriyor ve bunların 5'i ilgili.

- Precision@10 $=5/10=0{,}5$.
- Recall $=5/15\approx0{,}33$.

Diğer örnekte ilk 10'da 3 ilgili sonuç varsa Precision@10 $=3/10$ olur.

Web'de recall bilinemez. Arama motorları şöyle karşılaştırılır:

1. Bir sorgu için her motorun ilk 10 sonucu alınır.
2. Kullanıcılara hangi sonuçların ilgili olduğu sorulur.
3. Precision@10, @20, @30 hesaplanır.
4. Bu işlem çok sayıda sorgu için yapılıp ortalama alınır.

Precision-recall eğrisi ancak her sorgu için ilgili doküman sayısının bilindiği küçük koleksiyonlarda çizilebilir.

### Web Aramasında Zorluklar

- Kullanıcılar genelde geniş anlamlı, birden çok anlamı olan kelimeler girer. Motor kullanıcının niyetini anlamakta zorlanır. Bu yüzden ilk 10'da yüksek precision yakalamak zordur.
- İlgili doküman sayısı çok fazladır; hangilerinin gösterileceğine karar vermek gerekir.
- Motorların çözümleri:
  - Sorgu geçmişine ve konuma bakıp sorguyu genişletirler.
  - Otoriter (authoritative), popüler sayfaları öne alırlar. Bunu bağlantı analiziyle (Chapter 7) hesaplarlar.
  - Sonuçlarda çeşitliliğe (diversity) dikkat ederler. Tüm sonuçlar tek alan adından gelirse başarı düşer.

### Ters İndeks (Inverted Index)

- Doküman koleksiyonunu tarayıcı (web crawler) oluşturur. Tarayıcı web sayfalarını bulup içeriklerini indirir. Bu konu vizeden sonra işlenecek.
- Ters indeks, dokümanları içerdikleri kelimelere göre indeksler. Arama gerçek zamanda bu tablo üzerinde yapılır.
- Basit örnekte 3 doküman var; ilk sütunda kelimeler, ikinci sütunda o kelimeyi içeren dokümanlar bulunur.
- Gelişmiş örnekte her girdi bir üçlüdür: (doküman kimliği, sayı, konum).
  - Örneğin "mining" üç dokümanda birer kez geçer; konumu ikisinde 2, birinde 3'tür.
- Global arama motorları daha zengin bilgi tutar:
  - Kelime başlıkta mı, gövdede mi, meta etiketinde mi?
  - Kalın ya da italik yazılmış mı?
  - Sayfa sahibi bir kelimeyi başlığa koymuşsa o kelimeye önem veriyordur. Bu, aramada avantaj olarak kullanılabilir.

Arama sırasında:

1. Sorgudaki her kelime indekste aranır (lookup), ilgili doküman listeleri alınır.
2. Çok kelimeli sorguda ("web mining") listeler birleştirilir.
3. Sonuçlar TF-IDF ve bağlantı tabanlı yöntemlerle (PageRank, HITS) yeniden sıralanıp gösterilir.

Arama motorlarının başarısı üç şeye dayanır:

- İndekste tuttukları zengin bilgi.
- Sorgu işleme (genişletme, sorgu sınıflandırma).
- Sıralama algoritmaları (Google için PageRank).

### Ders sonrası notlar

- Altyazının precision/recall anlatımının bir kısmı (yaklaşık 00:55:16 ve 00:57:33 civarı) döngüye girmiş, okunamıyor. Bu bölüm slayttaki tanımlara göre özetlendi.
- Hocanın "ilk 10'da 3 ilgili sonuç" örneğinden sonra ikinci sistemle yaptığı karşılaştırma altyazıda bozuk olduğu için özete alınmadı.
- Durak kelime çıkarma ve kök bulmanın indeks boyutuna etkisi için verilen yüzdeler (%30, %40–50) kaba tahminlerdir. Gerçek oran dile, koleksiyona ve indeksin neyi saydığına (sözlük boyutu ya da posting sayısı) bağlıdır.
- Ters indeksteki konum bilgisi gerçekte bir liste olabilir. Bir kelime dokümanda birden çok kez geçerse tüm konumları tutulur.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
