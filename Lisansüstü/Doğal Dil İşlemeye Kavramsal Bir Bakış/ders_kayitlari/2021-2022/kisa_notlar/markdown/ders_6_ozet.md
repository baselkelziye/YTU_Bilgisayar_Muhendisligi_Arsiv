# Ders 6 Çalışma Özeti

## Genel Konular

- Ders 5 Ocak 2022 tarihlidir. Dönemin son dersidir ve tamamen öğrenci seminer sunumlarından oluşur.
- Kaydın ikinci parçası boştur. Bu özet birinci parçaya dayanır.
- Bu derste dört makale sunulur:
  - 1. sunum: Twitter'da 5G konusunda görüş analizi ve konu belirleme (topic detection).
  - 2. sunum: Haber makalelerinde belge düzeyinde duygu analizi (document-level sentiment analysis).
  - 3. sunum: Özgeçmişlerin eğitim bölümleri için yarı denetimli (semi-supervised) derin öğrenme tabanlı varlık ismi tanıma (Named Entity Recognition, NER).
  - 4. sunum: Derin öğrenme ve BERT tabanlı Türkçe soru cevaplama (question answering) sistemi.
- Ders sonunda final ve proje değerlendirmesiyle ilgili duyurular yapılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- LDA'da konu sayısını seçmek için perplexity gibi ölçütler kullanılır. Bu ölçütlerle tahmini bir konu sayısı bulunur, sonra bu sayının biraz altı ve üstü denenir.
  - Bir öğrenci coherence skorunun bugün daha çok kullanıldığını ekler. Hoca bunu doğrular.
- Bir makale "gelecekte makine öğrenmesi algoritmaları uygulayacağız" diyorsa yazarların sonraki çalışmalarını kontrol edin. Söz tutulmuş mu, yoksa makale "uyduruktan" mı yazılmış? "Detektif gibi iş göreceksiniz."
- Bir çalışmanın neden yapıldığını, hangi ihtiyaçtan doğduğunu sorgulayın.
- Proje konusu dar zamanda seçiliyorsa iddialı alt görevlere girmeyin. NER projesinde klasik varlık türleriyle başlayın: kişi (person), yer (location), kurum (organization).
- Hoca sunumların zamanında ve anlaşılır biçimde yapılmasını, sunum sırasında nefes alınmasını ister.

## Kısa Tekrar Notları

- rtweet: R dilinde Twitter Search API ile tweet çeken kütüphane.
- Google Cloud Natural Language API: hazır modellerle duygu analizi yapar. Her metin için iki değer döndürür:
  - score: $[-1, 1]$ aralığında, duygunun yönü.
  - magnitude: duygunun büyüklüğü.
- AutoML Natural Language: kendi verinizle kendi modelinizi eğitmenizi sağlar.
- LDA (Latent Dirichlet Allocation): her belge konuların bir olasılık dağılımıdır, her konu da kelimelerin bir olasılık dağılımıdır.
- Duygu analizinin üç düzeyi: belge (document), cümle (sentence), varlık/özellik (entity/aspect).
- Belge-terim matrisi (document-term matrix, DTM): satırlar belgeler, sütunlar terimler, hücreler frekanslar.
- BIO/BILOU etiketleme: B başlangıç, I iç, L son, U tek kelimelik varlık, O varlık dışı.
- FuzzyWuzzy: bulanık dize karşılaştırma (fuzzy string matching) kütüphanesi.
- Transformer: dikkat mekanizmasına (attention) dayanan, RNN kullanmayan mimari.
- BERT (Bidirectional Encoder Representations from Transformers): çift yönlü, önceden eğitilmiş (pre-trained) dil modeli. İnce ayar (fine-tuning) ile göreve uyarlanır.
- WordPiece: alt kelime (subword) tabanlı tokenizer. Kelimenin devamı olan parçaların başına `##` konur.
- MLM (Masked Language Model) ve NSP (Next Sentence Prediction): BERT'in iki ön eğitim görevi.
- EM (Exact Match): tahmin edilen cevabın gerçek cevapla birebir eşleşme oranı.

## Detaylı Açıklamalar

### 1. sunum: Twitter'da 5G Görüş Analizi ve Konu Belirleme

- Çalışma 2019'da yazılmış, 2020'de çevrimiçi yayımlanmıştır.
- Üç görev vardır: duygu belirleme, sınıflandırma modeli, konu belirleme.
- Veri:
  - R'da rtweet ile 5G etiketli 46.559 tweet çekilmiştir.
  - Geçerli tweet filtreleri: profil ve arka plan fotoğrafı olan hesap, retweet olmayan, en az 80 karakterli, yalnız İngilizce tweet.
  - Filtre sonrası 8102 tweet kalmıştır.
- Duygu analizi akışı:
  - Tweetler önce Natural Language API'ye verilir. Score değerine göre üç sınıf atanır: $-1$ negatif, $0$ nötr, $+1$ pozitif.
  - Bu etiketli veri AutoML Natural Language'e verilir ve kendi modelleri eğitilir. Bölme oranı %80 eğitim, %10 doğrulama, %10 test.
  - Modelin yapısı makalede anlatılmamıştır.
- Konu belirleme:
  - LDA ile 30 konu çıkarılmıştır. Bu sayının nasıl seçildiği belirtilmemiştir.
  - TF-IDF ağırlıklandırma yapılmıştır. Korpusta 5'ten az geçen kelimeler, stop word'ler ve en sık kelimelerin %5'i atılmıştır.
  - İlk üç konu: Health/Disease (sağlık/hastalık), Networking, Technology Innovation.
  - LDA çıktısı hem elle etiketlenmiş hem de Google Cloud ile sınıflandırılmıştır. Google Cloud'da karşılığı olmayan konular "no category found" diye işaretlenmiştir.
- Sonuçlar:
  - Pozitif sınıfta precision %84,3, recall %94,7.
  - Veri dengesizdir: yaklaşık %65 pozitif, %25 negatif, %11 nötr. Bu yüzden nötr sınıfta precision ve recall düşüktür.
  - İlgi çekici bir bulgu: insanlar 5G radyasyonunun kansere yol açacağından korkmaktadır.
  - Hashtag analizinde 5G ile en çok birlikte geçen etiket IoT'dir. Bu kısım bir sınıflandırma sonucu değil, basit bir sayımdır.
- Hocanın sorusu: Natural Language API standart bir servisse, model anlatılmamasının nedeni bu olabilir mi?
  - Sunumu yapan öğrencinin yorumu: veri önce Google Cloud ile etiketlenmiş, sonra kendi modelleriyle yeniden sınıflandırılmıştır. Google Cloud'un etiketleme kalitesi bilinmediği için sonuçlar güvenilir değildir.
- Sunumu yapan öğrencinin ders projesi LDA ile konu modelleme olduğu için hoca perplexity'yi bu kadar geç hatırlamasını sorgulamıştır.

### 2. sunum: Haber Makalelerinde Belge Düzeyinde Duygu Analizi

- Makale Ağustos 2017 tarihlidir.
- Amaç: haber makalelerini iyi, kötü veya nötr haber olarak sınıflamak.
- Duygu analizinin üç düzeyi:
  - Belge düzeyi: belgenin tamamının kutbu bulunur.
  - Cümle düzeyi: her cümlenin kutbu bulunur.
  - Varlık/özellik düzeyi: varlıklara ve onların yönlerine ilişkin duygular bulunur.
- Veri: BBC haber veri kümesi. 5 alan (iş, eğlence, politika, spor, teknoloji), toplam 2225 belge.
- Yöntem (R dilinde):
  - Temizlik: URL, noktalama, gereksiz boşluk ve stop word silinir.
  - Kök bulma (stemming): örneğin "education" → öğrencinin söylediği "educate" (Porter kök bulucu büyük olasılıkla "educ" verir).
  - `tm` paketiyle belge-terim matrisi oluşturulur.
  - Duygu puanı için 2006 olumlu ve 4783 olumsuz kelimelik bir duygu sözlüğü kullanılır. Her kelime sözlükle karşılaştırılıp puanlanır.
- Sonuçlar: Örneğin iş kategorisinde 510 makaleden 262'si pozitif, 214'ü negatif, 34'ü nötr çıkmıştır.
- Sunumu yapan öğrencinin eleştirisi: Makalede bir makine öğrenmesi modeli kurulmamıştır. Yalnız sözlük karşılaştırması vardır. Makine öğrenmesi "gelecek çalışma" diye bırakılmıştır.
- Hoca, 2017 yılı için bile yalnız sözlük puanının zayıf olduğunu belirtir. Yazarların sonradan söz verdikleri çalışmayı yapıp yapmadığını araştırmayı önerir.

### 3. sunum: Özgeçmişlerde Yarı Denetimli Varlık İsmi Tanıma

- Makale Eylül 2020'de Springer'in Neural Computing and Applications dergisinde yayımlanmıştır. Yazarlar Hindistan'dandır.
- Amaç: özgeçmişlerin eğitim bölümünden akademik dereceyi (ön lisans, lisans, yüksek lisans, doktora) ve kurum adını doğru çıkarmak. İşe alım süreci hızlanır.
- Önceki benzer çalışma yaklaşık %82 F1 almıştır. Bu çalışma onu geçmeyi hedefler.
- Veri:
  - 550 etiketli özgeçmiş: 500 eğitim, 50 test.
  - Veri bir şirketten satın alındığı için paylaşılmamıştır.
  - PDF'ler JSON'a çevrilmiştir. NLTK ile POS etiketlemesi yapılmış, varlıklar elle etiketlenmiştir.
  - Temizlik: parantez hataları, fazla boşluklar, `&` işaretinin "amp" olarak bozulması ve istenmeyen karakterler düzeltilmiştir.
- Model: kelime gömmesi + CNN + BiLSTM + softmax. Ayrıntı makalede de azdır.
- Yarı denetimli döngü:
  - 360 etiketsiz özgeçmiş 30'arlık 12 gruba bölünür.
  - Her iterasyonda model bir grubu etiketler. Bir düzeltme modülü hatalı etiketleri düzeltir. Düzeltilmiş grup eğitim kümesine eklenir ve model yeniden eğitilir.
  - Düzeltme modülü iki liste kullanır: L1 (Hindistan ve ABD üniversite adları), L2 (olası dereceler).
  - Çıkarılan varlık FuzzyWuzzy ile listelerle karşılaştırılır. Eşleşme yoksa en benzer 5 aday içinden en yüksek benzerlikteki seçilir.
- Sonuç: başlangıçta yaklaşık %85 olan doğruluk 12 iterasyon sonunda %92'ye çıkmıştır.
- Sunumu yapan öğrencinin eleştirisi: düzeltme modülünden önceki ham tahmin doğruluğu verilmemiştir. Modülün ne kadar düzeltme yaptığı bilinmiyor.
- Hocanın sorusu: Bu çalışmaya neden gerek duyulmuş?
  - Öğrenci, daha büyük veride %98'e ulaşan modeller olduğunu belirtir. Çalışmanın bir firma için yapılmış uygulamalı bir iş olduğu sonucuna varır.
- Ders projesi: haber metninde NER. Öğrenci kemik veri setlerinden küçük bir haber kümesi kullanmayı düşünür.
  - Hoca: küçük veri sorun değil. Konu çıkarma gibi zor işlere girme; kişi, yer ve kurum çıkar.

### 4. sunum: BERT Tabanlı Türkçe Soru Cevaplama Sistemi

- Makale: "A Turkish Question Answering System Based on Deep Learning Neural Networks". Eylül 2021'de DergiPark'taki Zeki Sistemler Teori ve Uygulamaları Dergisi'nde yayımlanmıştır.
- Sunumu yapan öğrencinin tez danışmanı dersin hocasıdır.
- Amaç: bankacılık alanı için makinenin okuyabildiği Türkçe soru cevaplama (MRQA, Machine Reading for Question Answering) sistemi kurmak.
- Arka plan:
  - Türkçe sondan eklemeli ve morfolojik olarak karmaşıktır. Bu yüzden kaynak azdır ve başarı İngilizcenin gerisindedir.
  - Türkçe için kural tabanlı araçlar: Zemberek, Treebank.
  - GPU ve paralel hesaplamanın gelişmesiyle ELMo, GPT ve BERT gibi önceden eğitilmiş modeller çıkmıştır.
  - GPT tek yönlü, BERT çift yönlüdür.
  - 2019'da İngilizce MRQA yarışmasında BERT tabanlı modeller öne çıkmıştır.
  - Diğer diller için uyarlamalar: AraBERT (Arapça), CamemBERT (Fransızca), KorBERT (Korece), ParsBERT (Farsça), Çince modeller. Korece de eklemeli bir dil olduğu için KorBERT Türkçe için de umut vericidir.
- RNN'den Transformer'a:
  - RNN uzun cümlelerde sırayı tutmakta zorlanır. LSTM önemli bilgiyi daha uzun tutar.
  - Klasik encoder-decoder'da yalnız son gizli durum decoder'a gider.
  - Attention'da encoder'ın tüm gizli durumları decoder'a verilir.
  - Transformer yalnız attention'a dayanır. Kelime vektörüne konum kodlaması (positional encoding) eklenerek sıra bilgisi korunur.
- Veri:
  - Ön eğitim: Türkçe Wikipedia (yaklaşık 4,5 milyon cümle), haber makaleleri (yaklaşık 20 milyon cümle), ekonomi blog korpusu (yaklaşık 270.000).
  - Kelime sözlüğü 32.000 kelimedir; bunun 2000'i finans terimidir.
  - İnce ayar: makine çevirisiyle Türkçeye çevrilmiş SQuAD, Türkçe haber soru-cevap kümesi ve yazarların hazırladığı bankacılık kümesi. Bankacılık kümesi 679 belge ve 17.708 soru-cevaptan oluşur.
  - Çevrilmiş veride yanlış cevaplar ve paragraf hizalama sorunları olduğu için ek ön işleme yapılmıştır.
- Model: BERT-Base. Tokenizer olarak WordPiece kullanılır. Ön eğitimde MLM ve NSP görevleri vardır.
  - Makaledeki örnekte Zemberek "Çekoslovakya" benzeri bir kelimeyi köklerine ayırırken sorun yaşar. WordPiece ise harflerin birlikte geçme olasılığına göre parçalar üretir. Sık geçen parçayı ayrı birim olarak alır, ek olabilecek parçaların başına `##` koyar.
- Sonuçlar:
  - Dizi uzunluğu 512 token ve sorgu uzunluğu 64 token iken F1 yaklaşık %79'dur.
  - Soru ve cevap uzun olduğunda başarı artar. Soru uzun, cevap kısa olduğunda başarı düşer.
  - Soruların yaklaşık %3,2'sinde cevap tamamen yanlıştır. 572 hatalı örnek 7 hata sınıfına ayrılmıştır. Örnekler: birden çok doğru cevabı olan sorular, daha fazla bilgi gerektiren sorular. Yazarlara göre bunlara insanlar da yanlış cevap verebilir.
- Öğrencinin kendi çalışması:
  - Türkçe BERT modellerini araştırmış, ConvBERT benzeri bir modeli denemiş ama beklediği başarıyı alamamıştır.
  - Kendi modelini kurmuş, kemik haber sınıflandırma kümesinde yaklaşık %87 başarı almıştır.
  - Kısa metinlerde başarıyı artırmak için BERT'i başka modellerle birleştirmeyi düşünmektedir.
- Hoca sunumu beğenmiş, makaleyi zorlu bulmuştur. Arada nefes alınmasını önermiştir.

### Ders sonrası notlar

- 1. sunumda magnitude için "büyük ihtimal 0-1 aralığında" denmiştir. Doğrusu: Google Natural Language API'de magnitude $[0, +\infty)$ aralığındadır ve metin uzadıkça büyüyebilir.
- 1. sunumdaki "Artifit kütüphanesi" rtweet'tir. "Latent Directing Algorithm" ve "Leda" LDA (Latent Dirichlet Allocation) demektir.
- 1. sunumdaki oranlar (%65 + %25 + %11) yuvarlama nedeniyle %100'ü biraz aşar.
- 2. sunumdaki "Bintli sözlüğü" büyük olasılıkla Bing Liu'nun opinion lexicon'udur. Bu sözlükte yaklaşık 2006 olumlu ve 4783 olumsuz kelime vardır. "TN paketi altında DTM metodu" ifadesi R'daki `tm` paketinin `DocumentTermMatrix` fonksiyonudur.
- 3. sunumda devam etiketleri "U ile başlıyor" denmiştir. Doğrusu: BILOU şemasında devam I, son L, tek kelimelik varlık U ile etiketlenir. Varlığın sonu L etiketiyle bulunur.
- 3. sunumdaki "Fazı Vazı" FuzzyWuzzy kütüphanesidir. Model listesindeki "Trapat" kelimesi altyazıda anlaşılmıyor.
- 4. sunumda MLM yanlış anlatılmıştır. Doğrusu:
  - Token'ların %15'i seçilir.
  - Seçilenlerin %80'i `[MASK]` ile değiştirilir, %10'u rastgele bir token'la değiştirilir, %10'u aynen bırakılır.
- 4. sunumda NSP "ikinci cümlenin kelimelerinin yarısı karıştırılır" diye anlatılmıştır. Doğrusu: Örneklerin %50'sinde ikinci cümle gerçekten sonraki cümledir. Diğer %50'sinde korpustan rastgele bir cümledir. Model bu ikisini ayırt etmeyi öğrenir.
- 4. sunumda "Transformer 6 attention'ın paralel çalışmasından oluşur" denmiştir. Doğrusu: Orijinal Transformer'da encoder ve decoder 6'şar katmandır. Her katmanda çok başlı dikkat (multi-head attention, 8 baş) vardır. BERT-Base 12, BERT-Large 24 katmandır.
- 4. sunumda ELMo tek yönlü bir transformer gibi anlatılmıştır. ELMo transformer değildir; iki yönlü LSTM tabanlıdır.
- 4. sunumda BERT'in "8 milyar kelime" ile eğitildiği söylenmiştir. Doğrusu: BooksCorpus (yaklaşık 800 milyon kelime) ve İngilizce Wikipedia (yaklaşık 2,5 milyar kelime), toplam yaklaşık 3,3 milyar kelime.
- 4. sunumdaki "Math language / NBERT" çok dilli BERT'tir (Multilingual BERT, mBERT). "Perspert" ParsBERT, "Cameron BERT" CamemBERT'tir.
- 4. sunumdaki "BERT-Base daha çok OpenAI'a benzeyen taraf" ifadesinin anlamı şudur: BERT-Base, OpenAI GPT ile karşılaştırılabilsin diye ona benzer boyutta tasarlanmıştır.

### Duyurular

- Sınıf kalabalık olduğu için hoca final günü bütün projelere yetişemeyebilir. Projesini önceden bitiren öğrenci haber verirse hoca daha önce de bakabilir. Hoca bunu e-postayla da duyuracaktır.
- Sınav takvimi belli olmuştur. Hoca dersin hangi haftada olduğunu ayrıca bildirecektir.
- Herkes sunum dosyasını Drive'a koymalıdır. Notlar buna göre sisteme girilecektir.
- Önceki haftadan sunumu kalan öğrenci derse gelmemiş ve hocaya dönüş yapmamıştır. Hoca, öğrenci son sunumdan sonra da gelmezse seminerini vermemiş sayacağını kayda geçirir.
- Ders "finalde görüşmek üzere" diye biter.

İsterseniz bu özeti NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
