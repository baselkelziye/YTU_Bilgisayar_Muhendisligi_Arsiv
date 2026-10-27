# Ders 2 Çalışma Özeti

Tarih: 21 Mayıs 2026 Perşembe. Kurban Bayramı öncesi online yapılan ders. Süre yaklaşık 1 saat 50 dakika (arada ara var). Makine öğrenmesi konularının son dersi. Slaytlar Prof. Dr. M. Fatih Amasyalı'nın ders notları ile hocanın hazırladığı ek slaytlardan.

## Genel Konular

- Eğiticili öğrenmenin (supervised learning) açmazı: yeterli etiketli veri bulmak.
- Öz denetimli öğrenme (self-supervised learning):
  - Otokodlayıcılar (autoencoder) ve gizli uzay (latent space).
  - Varyasyonel otokodlayıcılar (variational autoencoder, VAE) ve difüzyon modelleri (diffusion models).
  - Tamamlayıcılar: otoregresif modeller (GPT), maskeli dil modelleri (BERT), Word2Vec, ELECTRA, BART.
  - Karşısal öğrenme (contrastive learning).
  - İnsan ödülü olmadan pekiştirmeli öğrenme: AlphaZero, RLHF ve PPO.
- Uygulama: MNIST verisini otokodlayıcıyla 32 boyuta indirip KNN, SVM ve MLP ile sınıflandırma (Google Colab).
- Üretici modeller (generative models): dağılımdan örnekleme, VAE, GAN, difüzyon, koşullu üretim.
- Transformer mimarisi ve öz dikkat (self-attention).
- Büyük dil modelleri (LLM): ölçek, zero-shot / one-shot / few-shot öğrenme, InstructGPT.
- Halüsinasyon, ince ayar (fine-tuning) ve bilgi getirmeyle güçlendirilmiş üretim (Retrieval-Augmented Generation, RAG).

## Hocanın Özellikle Vurguladığı Kısımlar

- Makine öğrenmesinde en büyük darboğaz insandır. Yeterli etiketli veri sağlanamazsa makine öğrenemez.
- Öz denetimli öğrenmede cevap verinin kendisinde vardır. Verinin bir parçası maskelenir, silinir veya bozulur. Model bu parçayı tahmin eder.
- Bu yöntemle hem ucuz hem hızlı biçimde çok büyük miktarda eğitim örneği üretilebilir. İnsan hatalarından bağımsızlık sağlanır.
- Otokodlayıcının amacı veriyi özünü kaybetmeden sıkıştırmaktır. Girdi $x$ ile yeniden oluşturulan $\hat{x}$ arasındaki fark en aza indirilir.
- Klasik otokodlayıcı veriyi gizli uzayda tek bir noktaya eşler. VAE ise bir bölgeye (dağılıma) eşler. Bu yüzden VAE yeni veri üretebilir.
- GPT soldan sağa bir sonraki kelimeyi tahmin eder. BERT iki yönlüdür, boşluğu iki taraftaki bağlama bakarak doldurur.
- "Attention Is All You Need" (2017) makalesini okumanız tavsiye edildi.
- Basit problemlerde otokodlayıcı başarıyı artırmayabilir. Problem zorlaştıkça ve boyut arttıkça faydalıdır.
- Kaynaklardaki ayrıntılar sınavda sorulmayacak, ama mühendis adayı olarak incelenmesi tavsiye edildi.

## Kısa Tekrar Notları

- Öğrenme türleri: eğiticili (etiketli veri), eğiticisiz (unsupervised, kümeleme), pekiştirmeli (reinforcement learning).
- Etiket az: yarı denetimli (semi-supervised) ve öz denetimli öğrenme. Veri de az: üretici modeller.
- Otokodlayıcı: kodlayıcı (encoder) → gizli vektör $z$ → çözücü (decoder). Kayıp: ortalama kare hata (MSE).
- MNIST: $28\times28=784$ piksel. Otokodlayıcı katmanları $784\to128\to64\to32$.
- Difüzyon: ileri yönde veriye adım adım gürültü eklenir. Model gürültüyü adım adım temizlemeyi öğrenir.
- Tamamlayıcı yaklaşımlar:
  - sonraki parçayı tahmin (GPT, Vision Transformer),
  - eksik parçayı tahmin (BERT, görüntüde in-painting),
  - çevreyi tahmin (Word2Vec),
  - değiştirilen parçayı bulma (ELECTRA),
  - bozulmuş metni düzeltme (BART),
  - sıra tahmini (BERT'teki NSP).
- BERT eğitiminde kelimelerin %15'i maskelenmiş.
- Karşısal öğrenme: Benzer örnekler (pozitif) yaklaştırılır, farklı örnekler (negatif) uzaklaştırılır. Zor negatifler (hard negatives) ince ayrımları öğretir.
- GAN: üretici (generator) sahte örnek üretir. Ayırıcı (discriminator) gerçeği sahteden ayırmaya çalışır. İkisi rekabetle birlikte eğitilir.
- Öz dikkat: Her token diğer tüm token'larla nokta çarpımı (dot product) ile karşılaştırılır. Sonuç softmax'tan geçirilir. Karmaşıklık $O(n^2)$.
- Query, key, value: "ne arıyorum", "bende ne var", "bulunursam ne veririm".
- RAG: anlık ve kuruma özel bilgiye erişim, kaynak gösterme, halüsinasyonu azaltma. Model yeniden eğitilmez.

## Detaylı Açıklamalar

### Etiketli veri sorunu

- On-on beş yıl önce makine öğrenmesi belirli problemleri çözmek için kullanılıyordu: yüz tanıma, belirli bir alandaki metni sınıflandırma, belirli oyunlar.
- Banka örneği: Dekontlar üzerindeki el yazısına göre "fatura ödemesi" veya "kredi ödemesi" gibi sınıflara ayrılacak. Bankada binlerce etiketli örnek var. OCR ile metin çıkarılıp KNN, Naive Bayes, karar ağacı, SVM veya yapay sinir ağıyla sınıflandırılabilir. Problem küçük ölçeklidir.
- Türk sanat müziği makamlarını sınıflandırma örneği: Batı müziği için 8.000 ve 24.000 örnekli hazır veri setleri var. Makamlar için yeterli etiketli veri yok. 20-30 örnekle yeterli başarıya ulaşılamıyor.
- Para harcayıp uzmanlara etiketletmek mümkün ama her problemde yeterli değil. ImageNet'teki 14 milyon görüntüyü etiketlemek için yılda 25 bin kişi gerektiği hesaplanmış.

### Otokodlayıcılar ve MNIST uygulaması

- Örnek: $1000\times1000$ piksellik bir ekran görüntüsünde 1 milyon (RGB ile 3 milyon) değer vardır. Bu kadar büyük bir özellik vektörüyle çalışmak zordur. Veriyi en iyi temsil eden küçük bir gizli uzay bulunursa iletim ve sınıflandırma kolaylaşır.
- MNIST'te görüntülerin büyük kısmı siyah arka plandır. 784 özelliğin çoğu gereksizdir.
- Colab uygulaması (10.000 örnek, 5 katlı çapraz doğrulama):
  - Otokodlayıcı 15 epoch'ta kaybı yaklaşık 0,01'e indirdi.
  - 32 boyutlu vektörlerle KNN, SVM ve MLP doğruluğu yaklaşık %92-94.
  - Ham 784 boyutlu veriyle doğruluk yaklaşık %94-95.
  - Bu basit problemde otokodlayıcı başarıyı artırmadı. Ham veriyle çalışmak ise daha uzun sürdü.
- Kod kısadır: Hazır kütüphanelerle 15-20 satırda bir otokodlayıcı yazılabilir.

### VAE ve difüzyon modelleri

- VAE, gizli uzayda her örneği ortalama ve standart sapmayla tanımlı bir dağılıma eşler. Bu bölgeden rastgele bir nokta alınıp çözülünce gerçekçi yeni örnekler üretilir.
- Örnekler arası interpolasyon: 1'den 9'a rakamlar, kediden zürafaya geçiş.
- Difüzyon modelleri (DALL-E, Stable Diffusion) her adımda ne kadar gürültü eklendiğini öğrenir. Cevap verinin içinde olduğu için insan etiketi gerekmez.

### Tamamlayıcı modeller

- Otoregresif: "İstanbul'un tarihi ..." cümlesinde sonraki kelime ("yarımadası") tahmin edilir. GPT-1'de 117 milyon parametre vardı. Fikir hep aynıdır: bir sonraki kelimeyi tahmin etmek.
- Maskeli: "İstanbul [MASK] tarihi" cümlesinde boşluk iki yönlü bağlamdan doldurulur. "Ankara Türkiye'nin başkentidir" örneğinde BERT hem öncesine hem sonrasına bakar.
- BERT anlama ve sınıflandırmada, GPT üretimde güçlüdür. Google aramaları BERT kullanıyor.
- Word2Vec benzer kullanılan kelimeleri vektör uzayında yakın tutar: "kedi" ile "mama", "tatlı" yakın; "bisiklet tekerleği", "astronomi" uzak. Kral − erkek + kadın ≈ kraliçe ilişkisi.
- ELECTRA: Kelimeyi maskelemek yerine değiştirir ("The chef cooked the meal" → "The chef ate the meal"). Ayırıcı model hangi kelimenin değiştirildiğini bulur.
- BART: Metni birden çok şekilde bozar (token silme, yer değiştirme, döndürme). Orijinali yeniden oluşturmayı öğrenir. Özetleme ve çeviride kullanılır.

### Karşısal öğrenme

- Aynı köpeğin farklı parçaları birbirine yaklaştırılır. Köpek ayağı ile sandalye ayağı, ikisi de "ayak" olsa da uzaklaştırılır.
- Telefonlardaki fotoğraf gruplama uygulamaları bu mantıkla çalışır: aynı kişinin fotoğrafları bir grupta toplanır.
- Cümle düzeyi: "Hava çok sıcak" ile "Bugün kavurucu" yakın, "Matematik zordur" uzak olur.
- Zor negatif örneği: "Kedi tatlı bir hayvandır" ve "Kedi çok tehlikeli olabilir" iki cümle de kediden bahseder ama anlamları zıttır.

### İnsan ödülü olmadan pekiştirmeli öğrenme

- AlphaZero kendi kendine milyonlarca oyun oynar. Yeni politika eskisini yenerse korunur, yenemezse atılır. Ödül insandan değil, oyunun sonucundan gelir.
- Ödül kaynakları: kendi kendine oyun (satranç, Go), ortamdan gelen skor (Atari, Mario), başka bir modelden gelen ödül.
- ChatGPT'nin eğitimi (RLHF):
  1. İnsanların yazdığı örnek konuşmalarla eğiticili ince ayar.
  2. Model birden çok cevap üretir, insan bunları sıralar. Ödül modeli bu sıralamayı öğrenir.
  3. PPO algoritmasıyla dil modeli, ödül modelini en yükseğe çıkaracak cevaplar üretmeyi öğrenir.
  - 2. ve 3. adımlar tekrar eder. Başta insan etkisi vardır, sonra süreç büyük ölçüde makineyle ilerler.

### Üretici modeller

- Verinin dağılımı biliniyorsa (ortalama ve varyans), bu dağılımdan yeni örnekler üretilebilir.
- Normal dağılım örneği: Ortalama boy 170 cm, standart sapma 5 cm ise insanların yaklaşık %68'i 165-175 cm aralığındadır (hocanın verdiği sayılar örnek amaçlı).
- Dağılım bilinmiyorsa otokodlayıcı, VAE, GAN ve difüzyon modelleri kullanılır.
- Yeterli verinin olmadığı problemlerde (ör. müzik makamları) mevcut veriden yeni örnek üretmek çok önemlidir.
- Koşullu üretim: "Ahmet Hamdi Tanpınar üslubunda yaz", "bir proje hakemi üslubuyla yaz". Ses → metin (Whisper), metin → kod (GitHub Copilot), metin → görüntü, görüntü + metin → video.

### Transformer ve öz dikkat

- "Bankaya gittim, orada para yatırdım" cümlesinde "orada" kelimesinin "banka"ya bağlandığını dikkat mekanizması bulur.
- Adımlar: kelimeler vektörlere dönüştürülür, konum bilgisi (positional encoding) eklenir, her token diğerleriyle ilişkilendirilir, ileri beslemeli (feed-forward) dönüşüm uygulanır.
- İlk GPT'de her Transformer bloğu: matris çarpımı, maskeleme, softmax, dropout ve yeniden matris çarpımı.

### Büyük dil modelleri

- Belirli bir ölçeği geçince modellerde beklenmedik yeni yetenekler ortaya çıkar. Hoca bunu sudan buza faz geçişine benzetti.
- Zero-shot: hiç örnek vermeden ("İngilizceden Türkçeye çevir"). One-shot: tek örnekle. Few-shot: birkaç örnekle.
- Geleneksel makine öğrenmesinde her görev için ayrı model eğitilir. LLM yeni görevi yalnız prompt ile yapar, gradyan güncellemesi gerekmez.

### Halüsinasyon, ince ayar ve RAG

- Dil modelleri gerçek gibi görünen yanlış bilgiler üretebilir. Örnek: Bir Türkçe dil modeli insansız arabanın 1899'da geliştirildiğini söylemiş.
- İnce ayar sınava çalışarak girmeye, RAG ise sınava kitapla girmeye benzer.
- Bölümün staj ve proje yönetmelikleri için yapılan bir projede genel bir model staj süresini yanlış verebiliyordu. RAG ilgili belgeden doğru cevabı kaynağıyla getirdi.
- RAG iki aşamalıdır:
  - İndeksleme (çevrim dışı): Belgeler parçalara (chunk) bölünür, gömme (embedding) vektörlerine çevrilir, vektör veritabanına kaydedilir.
  - Sorgulama ve üretim: Soru vektöre çevrilir, en yakın $k$ parça bulunur, bağlam olarak LLM'e verilir. Cevap kaynağıyla birlikte döner.
- Parçalama örneği: 512 kelimelik parçalar, 50 kelime örtüşme (overlap). İkinci parça birincinin son 50 kelimesiyle başlar.
- RAG açıklanabilir yapay zekaya (explainable AI) yakındır: "Bu cevabı şu kaynaktan ürettim."
- Plan yapmada LLM'ler hâlâ zayıf kalabiliyor. Bölümde proje sınavı jüri programı için klasik genetik algoritma yöntemleri daha başarılı çıkmış.

### Ders sonrası notlar

- Hoca GPT-3'te "175 bin parametre" diyor. Doğrusu 175 milyar parametredir.
- GPT-4'ün parametre sayısını OpenAI açıklamadı. Derste geçen "1 trilyon" bir tahmindir.
- Normal dağılımda bir standart sapma içinde kalan oran %68,27'dir (Python ile doğrulandı). Hoca "%65 veya %67" dedi.
- Hoca bir yerde "alfa-beta" diyor. AlphaZero'nun alfa-beta budamasıyla ilgisi yoktur. AlphaZero, kendi kendine oyun ile eğitilen bir sinir ağı ve Monte Carlo ağaç araması kullanır.
- "Otokodlayıcıyla kağıdı buruşturup açınca hiçbir şey kaybolmaz" benzetmesi tam doğru değil. Otokodlayıcı kayıplı sıkıştırma yapar; amaç kaybı en aza indirmektir. Hoca da $x$ ile $\hat{x}$'in birebir aynı olmasını beklemediğimizi söylüyor.
- 512 kelimelik parçalarda 50 kelime örtüşmeyle ikinci parça 463. kelimeden başlar ($512-50=462$ kelimeden sonra).
- Altyazıda "Kozmos", Türkçe bir dil modeli olan Cosmos GPT'dir. "Rock/RAK" RAG, "Pintuinik" fine-tuning'dir.

### Duyurular

- Makine öğrenmesi konuları bu derste bitti. Son konu "Yapay Zeka ve Etik", bayramdan sonraki hafta (4 Haziran) normal ders saatinde işlenecek.
- Ödev 2'de RLHF benzeri cevap sıralama ve gömme yöntemleri kullanılmıştı.
- Fatih Amasyalı'nın grubunun dil modellerini kodlarıyla anlatan bir video serisi ve ileri RAG teknikleri kaynakları paylaşılacak.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
