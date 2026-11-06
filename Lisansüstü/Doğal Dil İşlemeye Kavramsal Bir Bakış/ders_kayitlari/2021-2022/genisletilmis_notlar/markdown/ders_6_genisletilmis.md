# Ders 6 Genişletilmiş Notu: 5G Konu Analizi, Haber Duygu Analizi, Özgeçmişte NER ve Türkçe BERT Soru Cevaplama Sunumları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

Ders 5 Ocak 2022 tarihlidir ve dört öğrenci sunumundan oluşur. Kaydın ikinci parçası sessizdir; bu not birinci parçaya dayanır. Slaytlar altyazıda yer almadığı için sunumlardaki şekil ve tabloların içeriği yalnız sözlü anlatımdan aktarılmıştır.

## İçindekiler

- 1. Birinci Sunum: Twitter'da 5G Görüş Analizi ve Konu Belirleme
- 2. İkinci Sunum: Haber Makalelerinde Belge Düzeyinde Duygu Analizi
- 3. Üçüncü Sunum: Özgeçmişlerde Yarı Denetimli Varlık İsmi Tanıma
- 4. Dördüncü Sunum: BERT Tabanlı Türkçe Soru Cevaplama Sistemi
- Dersin Toparlaması
- Ders Sonrası Notlar

## 1. Birinci Sunum: Twitter'da 5G Görüş Analizi ve Konu Belirleme

### 1.1 Çalışmanın Konusu

Bu sunumda, doktora programındaki bir öğrenci "Twitter opinion analysis and topic" başlıklı bir 5G makalesini anlatır. Makale 2019'da yazılmış, 2020'de çevrim içi yayımlanmıştır. Çalışmada üç görev vardır: duygu belirleme (sentiment analysis), sınıflandırma modeli ve konu modelleme (topic modeling).

Öğrenci önce 5G teknolojisini kısaca tanıtır. Teknolojinin indirme ve yükleme hızında avantajı vardır. Pratikteki zorlukları ise güvenlik ve gizlilik, hava şartları, zaman kayması ve gecikmeler, eski cihazların desteklenmemesidir. Şu an teknoloji daha çok üst segment yeni cihazlarda desteklenir ve test aşamasındadır. Öğrenci pratik kullanıma örnek olarak, Türk Telekom'un 5G destekli gözlüklerle gerçek bir ameliyat yaptığına dair okuduğu bir haberi anar.

Literatürde Twitter ve diğer sosyal medya verilerinden duygu analizi yapılmıştır. Örnek konular bot hesap tespiti, seçimler, şirketler ve ürünlerdir. Bu çalışmalarda SVM ve Random Forest gibi farklı algoritmalar kullanılmıştır. Öğrenciye göre makalenin aktardığı literatürde derin öğrenme ağları pek görünmemektedir.

### 1.2 Yöntemin Adımları

Yöntem üç adımdan oluşur:

- 1. adım: Twitter veri kümesi hazırlanır. RStudio'da R dili ve Twitter Search API ile tweet çekilir.
- 2. adım: Sınıflandırma yapılır. Google Cloud'un Natural Language API aracı veriyi etiketler. Etiketli veri AutoML Natural Language'e verilir ve kendi modelleri eğitilip test edilir.
- 3. adım: Aynı veri kümesiyle konu belirlenir. LDA (Latent Dirichlet Allocation) çıktısı hem elle hem de Google Cloud ile sınıflandırılır.

Burada aslında iki sınıflandırma vardır. Birincisi doğrudan API ile yapılır ve veriyi etiketler. İkincisi bu etiketli veriyle eğitilen kendi modelleriyle yapılır. Modelin yapısı hakkında makalede bilgi verilmemiştir.

Konu belirleme adımı, 5G ana başlığının altındaki alt konuları bulmayı amaçlar. Sunumda hastalık, teknoloji ve IoT bu tür alt başlıklara örnek verilir.

### 1.3 Veri Kümesi

Tweetler rtweet kütüphanesiyle çekilmiştir. Yazarlar kütüphanede parametre değişikliği yaparak son 8 günden daha geniş bir tarih aralığından veri almıştır. Toplam 46.559 tweet alınmış, şu filtreler uygulandıktan sonra 8102 geçerli tweet kalmıştır:

- Kullanıcının profil ve arka plan fotoğrafı olmalıdır.
- Tweet, retweet olmamalıdır.
- En az 80 karakter olmalıdır.
- Yalnız İngilizce tweetler alınır.

Yani çekilen tweetlerin yaklaşık %17,4'ü filtreden geçmiştir (ara adım eklendi: $8102/46559 \approx 0{,}174$).

### 1.4 Google Cloud Araçları ve Duygu Etiketleri

Google Cloud'da iki farklı araç kullanılmıştır:

- **Natural Language API:** Hazır modeller içerir. Kullanıcı yalnız veriyi verir, duygu analizi ya da sınıflandırma sonucunu alır.
- **AutoML Natural Language:** Kullanıcı kendi modelini oluşturur. Kendi verisiyle eğitim ve test yapabilir.

API her tweet için iki değer döndürür. **Score** değeri $-1$ ile $+1$ arasındadır: $-1$ çok negatif, $0$ nötr, $+1$ çok pozitiftir. **Magnitude** ise duygunun yoğunluğu ya da büyüklüğüdür.

Tweetlere üç sınıf etiketi verilmiştir: $-1$ (negatif), $0$ (nötr), $+1$ (pozitif). Sonra etiketli veri %80 eğitim, %10 doğrulama ve %10 test olarak bölünüp kendi modelleri eğitilmiştir.

### 1.5 LDA ile Konu Modelleme

Öğrenci LDA'yı kısaca anlatır. Bir doküman gizli konulardan oluşur. Konular da kelimelerden oluşur. Bir dokümanda birden fazla konu olabilir ve her konunun 0-1 aralığında, toplamı 1 olan bir olasılığı vardır. Her konu da birden fazla kelimeden oluşur ve kelimelerin de olasılığı vardır. Bu yüzden öğrenci yapıyı "olasılıkların olasılığı" diye özetler.

LDA denetimsiz (unsupervised) bir yöntemdir. Çıktısında sınıf etiketi olmadığı için konular elle etiketlenmiştir.

Çalışmada 30 konu belirlenmiştir, ama bu sayının nasıl seçildiği makalede açık değildir. Öğrenci kendi deneyiminde konu sayısını 1, 2, 3, 4 diye deneyerek en iyi değeri aradığını söyler.

Bu noktada hoca araya girer: Tahmini bir konu sayısı veren bir yöntem vardır. Bu yöntemle tahmini sayı bulunur, sonra onun biraz üstü ve altı denenir. Bir öğrencinin aklına "Perlex" gibi bir ad gelir; bunun perplexity olduğu dersin ilerleyen yerinde netleşir.

**Soru:** Bir öğrenci sunum sonunda, başka bir sunumda coherence skorunu gördüğünü ve bugün daha çok onun kullanıldığını söyler. **Cevap:** Hoca bunu doğrular. Öğrenciye göre bazı kaynaklar hep perplexity'yi yazar ama coherence daha iyi sonuç verir.

> **Ek bilgi (derste anlatılmadı):** Perplexity, modelin görmediği veriyi ne kadar iyi açıkladığını olasılık üzerinden ölçer; düşük olması istenir. Coherence ise bir konudaki sık kelimelerin birlikte ne kadar anlamlı durduğunu ölçer. Bu yüzden konuların insanlar için anlamlı olması hedefleniyorsa coherence daha çok tercih edilir.

Ön işleme ve ağırlıklandırma adımları şöyledir:

- Kelimeler ve tweetler TF-IDF ile ağırlıklandırılır.
- Derlemde 5'ten az geçen kelimeler atılır.
- Stop word'ler çıkarılır.
- En çok geçen kelimelerin %5'i de atılır. Öğrenci bunun, sık geçip anlam taşımayan kelimeler olarak düşünüldüğünü tahmin eder.

### 1.6 Sonuçlar

Veri kümesi dengesizdir: tweetlerin yaklaşık %65'i pozitif, %25'i negatif, %11'i nötr etiketlenmiştir. Öğrencinin sözlü verdiği sayılar yaklaşık 5200 pozitif ve 900 nötr tweettir. Bu sayılar 8102 toplamla karşılaştırıldığında yaklaşık %64,2 ve %11,1 eder (ara adım eklendi), yani oranlarla uyumludur.

Pozitif sınıfta precision %84,3, recall %94,7'dir. Öğrenci bunları şöyle yorumlar:

- Pozitif olarak işaretlediklerimizin %84,3'ü gerçekten pozitiftir.
- Gerçekte pozitif olanların %94,7'si pozitif olarak bulunmuştur. Kalan kısım kaçırılmıştır.

Nötr sınıfta precision ve recall çok düşüktür; öğrenci yaklaşık %54 değerini anar. Öğrenciye göre bunun nedeni büyük ihtimalle sınıfların dengesiz olmasıdır.

<!-- BELİRSİZ: Nötr sınıfın %54 değerinin precision mı recall mı olduğu ve sınıf bazlı tablonun kalanı slaytta; altyazıda net değil. -->

LDA sonucunda 30 konunun ilk üçü verilmiştir: Health/Disease (sağlık/hastalık), Networking ve Technology Innovation. Her konunun yanında onu anlamlandıran kelimeler vardır.

Tablodaki sol sütun elle yapılan etiketlemedir. Sağ sütun ise LDA çıktısının Google Cloud ile sınıflandırılmasıdır. Google Cloud'da yaklaşık yüz küsur sınıf olduğu için, elle verilen etiketin karşılığı olmayan satırlara "no category found" yazılmıştır.

<!-- BELİRSİZ: LDA konu tablosu ve hashtag grafiğinin tam içeriği slaytta. -->

5G etiketli tweetlerde en çok birlikte geçen hashtag IoT'dir. Öğrenci, bu kısmın bir sınıflandırma sonucu olmadığını, yalnızca hashtag sayımı olduğunu belirtir.

Makalenin ilgi çekici bulgusu şudur: İnsanlar 5G radyasyonu nedeniyle kansere yakalanmaktan korkmaktadır.

### 1.7 Hocanın Soruları ve Değerlendirme

**Soru:** Hoca, standart Natural Language API kullanıldıysa modelin anlatılmamasının nedeni bu olabilir mi diye sorar. **Cevap:** Öğrenci akışı açıklar. Veri önce Google Cloud'da etiketlenir, sonra kendi modelleriyle yeniden sınıflandırılır. Öğrenciye göre Google Cloud'un veriyi ne kadar iyi etiketlediği bilinmediği için sonuçlar güven vermez. Etiketleme kötüyse kendi modellerinin başarısı da düşük çıkabilir.

**Soru:** Hoca, kendi modelleri LDA üzerine kurulmuş olabilir mi diye sorar. **Cevap:** Öğrenci hayır der: LDA yalnız 5G ile birlikte hangi konuların konuşulduğunu bulmak için kullanılmıştır. Yani sınıflandırma modelinden ayrı bir adımdır.

Sunumu yapan öğrencinin kendi ders projesi de LDA ile konu modellemedir. Hoca, projeyi bu kadar yakın zamanda bitirmişken perplexity kavramının neden bu kadar geç hatırlandığını sorar.

## 2. İkinci Sunum: Haber Makalelerinde Belge Düzeyinde Duygu Analizi

### 2.1 Amaç ve Duygu Analizi Düzeyleri

Makalenin adı "Document Level Sentiment Analysis from News Articles"tır ve Ağustos 2017 tarihlidir. Amaç, haber makalelerini iyi, kötü ya da nötr haber olarak sınıflamaktır.

Duygu analizi, metnin ifade ettiği duyguyu pozitif, negatif ve nötr sınıflarından biri olarak belirlemeyi amaçlar. Kaynak olarak metinler, tweetler, bloglar, sosyal medya, haber makaleleri ve ürün yorumları kullanılır.

Duygu analizinin üç düzeyi vardır:

- **Belge düzeyi (document level):** Belgenin tamamı analiz edilir ve kutbu bulunur. Belgenin genel olarak olumlu mu olumsuz mu olduğu hesaplanır.
- **Cümle düzeyi (sentence level):** Her cümlenin kutbu incelenir. Makale bu düzeyin faydasının öznellik sınıflandırmasında olduğunu belirtir.
- **Varlık ve özellik düzeyi (entity/aspect level):** Bir görüş, bir olumlu ya da olumsuz yargı ve hedeften oluşur. Amaç varlıklar ve onların yönleri hakkındaki duyguları bulmaktır.

### 2.2 Veri Kümesi ve Ön İşleme

Veri kümesi BBC haber veri tabanıdır. İş, eğlence, politika, spor ve teknoloji olmak üzere 5 alanda toplam 2225 belge vardır. Dosyalar TXT biçimindedir.

Ön işlemede hashtag, reklam gibi anlamsız metinler çıkarılır. Amaç, istenen bilgiyi içermeyen ham verileri temizlemektir.

### 2.3 Önerilen Yaklaşım

Yöntem R dilinde uygulanmıştır:

- 1. adım: Veri temizlenir. URL, gereksiz sözcükler (stop word), noktalama işaretleri ve fazla boşluklar silinir.
- 2. adım: Kök bulma (stemming) yapılır. R'daki bir stem fonksiyonu kullanılır. Öğrencinin örneği "education" kelimesinin köküne indirilmesidir.
- 3. adım: Terim sıklığına dayanan belge-terim matrisi (document-term matrix, DTM) oluşturulur.
- 4. adım: Bir duygu sözlüğü ile kelimeler karşılaştırılır. Sözlükte 2006 olumlu ve 4783 olumsuz kelime vardır.
- 5. adım: Puan duyarlılığı fonksiyonu her metin için sözcüklere dayalı puan döndürür.

Akış şöyle özetlenir: Dokümanlar derleme (corpus) çevrilir, ön işlemeden geçirilir, kök bulma yapılır, her kelime sözlükle karşılaştırılıp puan bulunur.

### 2.4 Sonuçlar

İş kategorisinde 510 makale incelenmiş, 262'si pozitif, 214'ü negatif, 34'ü nötr çıkmıştır (toplam 510). Aynı değerlendirme 5 konu başlığının her biri için yapılmıştır.

Makalenin yorumları şöyledir:

- İş ve spor kategorilerinde makale sayısı hemen hemen aynıdır. Nötr sayısı da yakındır. Pozitif ve negatif sayılarda fark vardır.
- Eğlence ve teknoloji kategorilerinde makale sayısı ve üç sınıfın sayıları birbirine yakındır.
- Siyasette pozitif kutup fazla, negatif ve nötr azdır.

<!-- BELİRSİZ: İş dışındaki kategorilerin sayısal sonuçları slaytta; altyazıda verilmedi. -->

### 2.5 Eleştiri

Makale "gelecek çalışma" olarak cümle puanlarına göre anlamsal kutupluluğu tanımayı ve farklı makine öğrenmesi algoritmaları uygulamayı anar. Öğrenci, makalede bir makine öğrenmesi modelinin kurulmadığını vurgular. Model bölme oranı ya da başarı oranı yoktur. Yalnız sözlük karşılaştırması ve R fonksiyonları vardır.

Hoca da 2017 yılı için bile içeriğin yalnız puan değerlerinden ibaret olmasını zayıf bulur ve şunu sorar: Yazarların adları aratılıp 2017'den sonra söz verdikleri çalışmayı yapıp yapmadıkları kontrol edildi mi?

> **Hocanın vurgusu:** Bir makale "gelecekte şunu yapacağız" diyorsa yazarların sonraki çalışmalarına bakın. Söz tutulmuş mu, yoksa makale "uyduruktan" mı yazılmış? "Detektif gibi iş göreceksiniz."

## 3. Üçüncü Sunum: Özgeçmişlerde Yarı Denetimli Varlık İsmi Tanıma

### 3.1 Çalışmanın Amacı

Makale, özgeçmişlerin eğitim bölümlerini ayrıştırmak için yarı denetimli (semi-supervised) ve derin öğrenme tabanlı bir varlık ismi tanıma (Named Entity Recognition, NER) modeli önerir. Yazarlar Hindistanlı bir araştırmacı grubudur. Makale Eylül 2020'de Springer'in Neural Computing and Applications dergisinde yayımlanmıştır.

Problem şudur: Büyük firmalar çok fazla özgeçmiş toplar, ama bu kalabalıktan anlamlı veri çıkaramaz. Bu çalışma, eğitim bilgisine önem veren bir şirket için yapılmıştır. Amaç akademik dereceleri (ön lisans, lisans, yüksek lisans, doktora) ve üniversite ya da enstitü adlarını doğru çıkarıp işe alım sürecini hızlandırmaktır. Referans alınan benzer bir çalışma yaklaşık %82 F-skor almıştır; yazarlar bunu geçmeyi hedefler.

Derin öğrenme tabanlı yöntemler doğruluğu artırır ve farklı verilerde genelleştirilebilir, ama genellikle çok büyük veri ister. Yazarların başlangıç sorusu şudur: Daha küçük veri kümesiyle başlayıp yüksek doğruluk elde edebilir miyiz? Cevapları yarı denetimli bir döngüdür: Küçük başlanır, tahmin yapılır, tahminler düzeltilip veriye eklenir, veri büyüdükçe doğruluk artar.

### 3.2 Veri ve Ön İşleme

Toplam 550 etiketli özgeçmiş kullanılmıştır: 500 eğitim, 50 test. Veri bir şirketten satın alındığı için paylaşılmamıştır.

Hazırlık şöyle yapılır:

- PDF dosyaları JSON'a çevrilir.
- NLTK (Natural Language Toolkit) ile sözcük türü (part of speech) etiketlemesi yapılır.
- Varlıklar elle etiketlenir. Kurum adları herkes tarafından farklı yazılabildiği için bu adım özen ister.

Etiketleme şeması şöyledir: B bir kalıbın başlangıcı, I devamı, U tek kelimelik varlık, O diğer kelimeler. Örnek etiketler kurum (`NIST` benzeri) ve derece (`DEC` benzeri) türleri içindir.

<!-- BELİRSİZ: Etiket adları ("B, NIST", "B, DEC") slaytta; altyazıda kesin biçimi okunmuyor. -->

Temizlikte şu sorunlar giderilmiştir:

- **Parantez hataları:** İki adı olan bir üniversitenin parantezle yazılması yanlış ayrılmaya yol açmıştır. Parantez silinip iki ad ayrı kelime olarak alınmıştır.
- **Fazla boşluk:** İkiden fazla boşluk yanlışlıkla gerçek bir kelime gibi algılanmıştır. Bu boşluklar silinmiştir.
- **Bozulan karakter:** `&` işareti PDF'ten JSON'a çevrilirken "amp" gibi bozulmuştur. Elle temizlenmiştir.
- **İstenmeyen karakterler:** İki nokta üst üste gibi karakterler çıkarılmıştır.

### 3.3 Model ve Yarı Denetimli Döngü

Model derin öğrenme tabanlı bir sınıflandırıcıdır. Katmanları word embedding, CNN, BiLSTM ve softmax'tir. Öğrenci makalenin de bu kısma çok girmediğini söyler.

<!-- BELİRSİZ: Model katmanları arasında altyazıda "Trapat" diye geçen öğe anlaşılmıyor. -->

Ana veri dışında 360 etiketsiz özgeçmiş vardır. Bunlar da ön işlemeden geçirilir ve 30'arlık 12 gruba bölünür ($12 \times 30 = 360$). Her iterasyonda:

1. Model bir grubu etiketler.
2. Düzeltme modülü yanlış tahminleri düzeltir.
3. Düzeltilen grup ana veri kümesine eklenir.
4. Model yeniden eğitilir ve doğruluğu ölçülür.

Böylece 12 iterasyonda 12 farklı sonuç elde edilir. Yazarlara göre daha fazla veriyle iterasyon sayısı artırılırsa daha doğru sonuçlar alınabilir.

### 3.4 Düzeltme Modülü

Modül iki liste kullanır. L1, Hindistan ve ABD üniversitelerinin adlarını içerir, çünkü özgeçmişlerdeki öğrenciler bu ülkelerdendir. L2 ise olası bütün dereceleri içerir.

Varlık çıkarılırken iki işaretçi kullanılır. Soldan başlanır, B etiketi görülen yere başlangıç işaretçisi (start pointer) konur, varlığın sonuna da bitiş işaretçisi (end pointer) konur. Çıkan ifade L1 ve L2 ile karşılaştırılır.

Karşılaştırma FuzzyWuzzy kütüphanesiyle yapılır. Eşleşme doğruysa bir şey yapılmaz. Değilse kütüphane listeden en benzer 5 adayı çıkarır ve benzerliği en yüksek olan doğru kabul edilip etiket düzeltilir.

### 3.5 Sonuçlar ve Eleştiri

Birinci iterasyonda ana veri üzerinde başarı yaklaşık %85'tir. 12 iterasyon sonunda %92'ye çıkmıştır. Bu, referans alınan %82'lik çalışmadan daha iyidir.

Öğrencinin eleştirisi şudur: Düzeltme modülünden önceki ham tahmin doğruluğu verilmemiştir. Örneğin ilk iterasyondaki 30 özgeçmişin 29'u yanlış tahmin edilip FuzzyWuzzy ile düzeltilmiş olabilir. Modülün ne kadar düzeltme yaptığı bilinmemektedir.

**Soru:** Hoca sorar: Böyle bir çalışmaya neden gerek duymuşlar? **Cevap:** Öğrenci de bunu merak ettiğini söyler. Daha büyük verilerde %98'e ulaşan modeller vardır. Veri kümesine bakarken, verinin özel bir firma için kullanıldığı ve paylaşılamadığı notunu görmüştür. Bundan, çalışmanın bir firma için yapılmış uygulamalı bir iş olduğu sonucuna varır.

### 3.6 Öğrencinin Projesi Üzerine Konuşma

Öğrencinin ders projesi de NER ile bilgi çıkarımıdır. Önce özgeçmiş denemiş, ama özel isimleri etiketlemek zorlamıştır. Sonra hocanın kemik sayfasındaki haber veri kümesine dönmüştür. Bu küme sınıflandırma için önerilmiştir ve küçüktür.

**Soru:** Öğrenci, küçük bir haber veri kümesinin çok basit kalıp kalmayacağını sorar. **Cevap:** Hoca küçük olmasının sorun olmadığını söyler.

**Soru:** Öğrenci haberde ne çıkarmasını sorar. **Cevap:** Konu çıkarmak gibi işler az zaman kaldığı için zorlar. Klasik varlık türleriyle devam edilmelidir: kişi (person), yer (location), kurum (organization).

> **Hocanın vurgusu:** Bir çalışmanın neden yapıldığını, hangi ihtiyaçtan doğduğunu sorgulayın. Dar zamanda seçilen bir projede de iddialı alt görevlere girmeyin.

## 4. Dördüncü Sunum: BERT Tabanlı Türkçe Soru Cevaplama Sistemi

### 4.1 Makale ve Amaç

Makale "A Turkish Question Answering System Based on Deep Learning Neural Networks" başlığını taşır. Eylül 2021'de DergiPark'taki Zeki Sistemler Teori ve Uygulamaları Dergisi'nde yayımlanmıştır. Yazarlar Yeditepe Üniversitesi bağlantılıdır. Öğrenci, yazarların bankacılık alanında çalıştığını ve çalışmanın büyük ihtimalle bir banka projesiyle ilgili olduğunu düşünür.

Öğrenci bu makaleyi, kendi projesinde ve tezinde BERT tabanlı sınıflandırma yapacağı için seçmiştir.

Amaç, bankacılık sektörü için Türkçe bir soru cevaplama sistemi kurmaktır. Bu sistem makinenin okuyarak cevap ürettiği bir yapıdır (Machine Reading for Question Answering, MRQA). Örneğin kullanıcı bir konuda bilgi ister, sistem "şu kadar kredi alabilirsiniz" gibi bir cevap üretir.

Türkçe sondan eklemeli ve morfolojik olarak karmaşıktır. Bu tür dillerde kaynak az olduğu için başarı İngilizcenin gerisindedir.

### 4.2 Arka Plan ve Dil Modelleri

Türkçe soru cevaplama çalışmaları daha çok arama motoru sorgularının cevaplarını iyileştirmeye yöneliktir. Türkçe için Zemberek ve Treebank gibi morfolojik analiz kaynakları vardır. Öğrenciye göre bunlar genellikle kural tabanlı yaklaşımlardır; Zemberek'in sınıflandırma kısmı ayrı tutulmalıdır, çünkü o kısım derin öğrenme kullanır.

GPU'nun ve paralel hesaplamanın gelişmesiyle sinir ağlarının başarısı artmıştır. ELMo, GPT (Generative Pre-trained Transformer) ve 2018'de Google'ın çıkardığı BERT (Bidirectional Encoder Representations from Transformers) bu dönemin modelleridir. Öğrenci GPT'nin tek yönlü, BERT'in çift yönlü çalıştığını belirtir.

2019'da İngilizce MRQA için bir yarışma düzenlenmiş, BERT tabanlı modeller öne çıkmıştır. Sonra başka dillere uyarlama ihtiyacı doğmuştur. Çok dilli bir BERT, ana modelin üzerine bir iki katman eklenerek oluşturulmuştur, ama performansı iyi olmamıştır, çünkü diller özel çalışma ister.

Bu nedenle dile özgü modeller geliştirilmiştir:

- **Arapça:** AraBERT. Ön eğitimde Arapça okuma anlama veri kümesi kullanılır. İnce ayarda (fine-tuning) İngilizce SQuAD makine çevirisiyle Arapçaya çevrilmiştir. Performans düşük kalmıştır.
- **Fransızca:** CamemBERT.
- **Korece:** KorBERT. Korece de eklemeli bir dil olduğu için, öğrenciye göre bu modelin Türkçede de başarılı olabileceğine işaret eden çalışmalar vardır.
- **Farsça:** ParsBERT.
- **Çince:** 2018'de Google üç veri kümesini birleştirerek bir model eğitmiştir.

<!-- BELİRSİZ: Çince model için altyazıda "SimearC, DRC'di, JRC" diye geçen veri kümesi adları anlaşılmıyor. -->

### 4.3 Ön Eğitim ve İnce Ayar

BERT'te iki aşama vardır: ön eğitim (pre-training) ve ince ayar (fine-tuning). BERT, genelleştirilmiş bir dil modelidir. Çok büyük metinler üzerinde uzun süre eğitilir. Yazarların böyle bir donanımı olmadığı için, öğrencinin anlatımına göre eğitilmiş ağırlıkların üzerine yeni katmanlar eklenerek kendi alan ve diline göre ince ayar yapılmıştır. Örneğin BERT içindeki 12 transformer katmanının üzerine kendi katmanını ekleyip parametre ayarlarını değiştirmek bu türden bir işlemdir.

Çalışmada iki grup veri kullanılır.

Ön eğitim verisi:

- Türkçe Wikipedia sayfaları: yaklaşık 4,5 milyon cümle.
- Haber makaleleri: yaklaşık 20 milyon cümle.
- Ekonomi derlemi: ekonomi blog sayfalarından yaklaşık 270 bin.

Kelime sözlüğünde 32 bin kelime vardır. Bunların 2000'i yazarların belirlediği finans terimleridir.

İnce ayar verisi:

- İngilizce SQuAD kümesinin makine çevirisiyle Türkçeleştirilmiş hali.
- Haberlerden alınan Türkçe soru-cevap kümesi.
- Yazarların ve birkaç kişinin hazırladığı bankacılık kümesi: 679 doküman ve 17.708 soru-cevap.

Çevrilen veride yanlış cevaplar ve paragraf başlangıcıyla hizalanmayan cevaplar görülmüş, bu yüzden ayrıca ön işleme yapılmıştır.

### 4.4 RNN'den Transformer'a

Öğrenci mimarinin gelişimini şöyle anlatır:

- **RNN:** Cümle sıralı kelimelerden oluşur ve kelimelerin sırası akılda tutulmalıdır. RNN bunu başarır, ama uzun cümlelerde maliyetlidir.
- **LSTM:** Önemli kelimelerin ağırlığının düşmesini engelleyip önemli bilgiyi daha uzun tutar.
- **Encoder-decoder:** RNN yapısında bir gizli katman çıktısı sonrakine girdi olur. Encoder'ın yalnız son gizli durumu decoder'a verilir.
- **Attention:** Encoder'ın bütün gizli durumları decoder'a birlikte verilir. Örneğin 3 gizli durum varsa üçü de verilir. Bu yöntem uzun cümlelerde başarı getirmiştir.
- **Transformer:** Attention'ın başarısı ve GPU'nun gelişmesiyle ortaya çıkmıştır. Kelimeler sayısallaştırılır. Kelimenin sırası da konum kodlamasıyla (positional encoding) bir vektöre çevrilir. İki vektör toplanarak hem kelime hem sıra bilgisi tutulur.

### 4.5 BERT'in Bileşenleri

Çalışmada BERT'in iki boyutundan BERT-Base kullanılmıştır. Model şu bileşenlerden oluşur: alt kelime tabanlı gömme (WordPiece), maskeli dil modeli (Masked Language Model, MLM), sonraki cümle tahmini (Next Sentence Prediction, NSP) ve çift yönlü transformer'lar.

**WordPiece:** Makaledeki örnekte Zemberek, "Çekoslovakya" benzeri bir kelimeyi köklerine ayırırken sorun yaşar. WordPiece metni tarar, kelimeleri harflerine ayırır ve harflerin birlikte geçme olasılığını hesaplar. Birlikte geçen parçayı bir birim olarak alır. Son ek olabileceğini düşündüğü parçaların başına iki diyez (`##`) koyar.

<!-- BELİRSİZ: Zemberek ve WordPiece karşılaştırmasındaki örnek kelime ve parçaları slaytta; öğrenci kelimeyi "okuyamıyorum" diyerek geçiyor. -->

**MLM:** Bir cümlede bazı kelimeler maskelenir ve model onları tahmin eder. Böylece kelimeler arasındaki benzerliği, anlamı ve bağlamı öğrenir. Öğrencinin örneğinde bir cümledeki "yağ" kelimesi maskelenir, model o kelimeyi görmez. Oranlar için Ders Sonrası Notlar'a bakın.

**NSP:** MLM kelimeler arasındaki ilişkiye, NSP cümleler arasındaki ilişkiye bakar. Yöntemin doğru anlatımı için Ders Sonrası Notlar'a bakın.

### 4.6 Sonuçlar

Eğitim sonunda yazarlar, cümle, doküman ve sorgu uzunluğunun başarıyı nasıl etkilediğini incelemiştir. EM (Exact Match), tahmin edilen cevabın gerçek cevapla birebir eşleşmesini gösterir.

- Dizi uzunluğu 512 token, sorgu uzunluğu 64 token iken F-skor yaklaşık %79'dur.
- Soru da cevap da uzunsa başarı artar.
- Soru uzun, cevap kısaysa başarı düşer.

Yaklaşık 17 bin sorunun yaklaşık %3,2'sinde cevap tamamen yanlıştır. Bu hatalardan 572 örnek 7 sınıfa ayrılmıştır. Örnekler: birden çok olası cevabı olan sorular ve daha fazla bilgi içermesi gereken sorular. Yazarlara göre bu sorulara insanlar da yanlış cevap verebilir.

### 4.7 Öğrencinin Kendi Çalışması

Hoca makaleyi zorlu bulur, sunumu iyi hazırlanmış bulur ve arada nefes alınmasını önerir. Öğrenci bu alanda önceden çalışmadığını, tezi için BERT'i araştırmaya başladığını anlatır:

- Türkçe için önerilen BERT modelleriyle iyi bir çalışma bulamamıştır.
- ConvBERT benzeri bir modeli denemiş, beklediği başarıyı alamamıştır.
- Kendi modelini oluşturmuş, kemik haber sınıflandırma kümesinde yaklaşık %87 başarı almıştır.
- Sonucu yeterli bulmamaktadır. Model uzun metinlerde iyidir; kısa metinlerde daha iyi sonuç için BERT'i başka modellerle birleştirmeyi düşünmektedir.

## Dersin Toparlaması

Dört sunum doğal dil işlemenin farklı uygulamalarını gösterir: sosyal medyada duygu analizi ve konu modelleme, sözlük tabanlı belge düzeyi duygu analizi, küçük veriyle yarı denetimli varlık ismi tanıma ve önceden eğitilmiş dil modeliyle soru cevaplama. Yöntemler sözlük karşılaştırmasından transformer'lara kadar uzanır.

Hocanın sorularındaki ortak çizgi, bir makalenin sonuçlarını olduğu gibi kabul etmemektir. Yöntemin neden seçildiği, verinin nereden geldiği, gelecek çalışma sözünün tutulup tutulmadığı ve çalışmanın hangi ihtiyaçtan doğduğu sorgulanmalıdır.

## Ders Sonrası Notlar

> **Ders sonrası not:** 1. sunumda magnitude için "büyük ihtimal 0-1 aralığında" denildi. Google Natural Language API'de magnitude $[0, +\infty)$ aralığındadır ve metin uzadıkça büyüyebilir.

> **Ders sonrası not:** 1. sunumda recall için kaçırılan kısım "%6" diye söylendi. $100 - 94{,}7 = 5{,}3$ olduğu için doğrusu %5,3'tür. Sınıf oranlarının toplamı da yuvarlama nedeniyle %101 eder.

> **Ders sonrası not:** 1. sunumdaki "Artifit kütüphanesi" rtweet, "Latent Directing Algorithm" ve "Leda" ise LDA (Latent Dirichlet Allocation) demektir. Hoca ve öğrencinin aradığı kavram perplexity'dir.

> **Ders sonrası not:** 2. sunumda "300 ile 400 makale" dendi, ama $2225/5 = 445$ ortalama ve iş kategorisindeki 510 makale bu aralığın üstündedir. Bu ifade tutarlı değildir.

> **Ders sonrası not:** 2. sunumda "education" kelimesinin kökü "educate" diye söylendi. Porter türü kök bulucular çoğunlukla daha kısa bir gövde üretir ("educ"); gövde sözlükteki bir kelime olmak zorunda değildir.

> **Ders sonrası not:** 2. sunumdaki "Bintli sözlüğü" büyük olasılıkla Bing Liu'nun görüş sözlüğüdür; sayılar (2006 olumlu, 4783 olumsuz) bu sözlükle uyumludur. "TN paketi altında DTM metodu" ifadesi R'daki `tm` paketinin `DocumentTermMatrix` fonksiyonudur. DTM de bir ön işleme değil, ön işlenmiş metnin matris gösterimidir.

> **Ders sonrası not:** 3. sunumda devam etiketlerinin "U ile başladığı" ve sonun U ile bulunduğu söylendi. Aynı sunumda U tek kelimelik varlık, I devam diye de tanımlandı. BILOU şemasında B başlangıç, I iç, L son, U tek kelimelik varlık, O varlık dışıdır.

> **Ders sonrası not:** 3. sunumdaki "Fazı Vazı" FuzzyWuzzy kütüphanesidir. "Named Entry and Recognition" Named Entity Recognition demektir.

> **Ders sonrası not:** 4. sunumda MLM oranları karışık anlatıldı. Doğrusu: Token'ların %15'i seçilir. Seçilenlerin %80'i `[MASK]` ile değiştirilir, %10'u rastgele bir token'la değiştirilir, %10'u aynen bırakılır.

> **Ders sonrası not:** 4. sunumda NSP "ikinci cümlenin kelimelerinin yarısı karıştırılır" diye anlatıldı. Doğrusu: Örneklerin %50'sinde ikinci cümle gerçekten sonraki cümledir, diğer %50'sinde derlemden rastgele bir cümledir. Model bu ikisini ayırt etmeyi öğrenir.

> **Ders sonrası not:** 4. sunumda "Transformer 6 attention'ın paralel çalışmasından oluşur" denildi. Doğrusu: Orijinal Transformer'da encoder ve decoder 6'şar katmandır ve her katmanda çok başlı dikkat (multi-head attention, 8 baş) vardır. BERT-Base 12, BERT-Large 24 katmandır.

> **Ders sonrası not:** 4. sunumda ELMo ve GPT birlikte "tek yönlü transformer" diye anılır. ELMo transformer değildir; iki yönlü LSTM tabanlıdır. Tek yönlü transformer tanımı GPT için geçerlidir.

> **Ders sonrası not:** 4. sunumda BERT'in "8 milyar kelime" ile eğitildiği söylendi. Doğrusu: BooksCorpus (yaklaşık 800 milyon kelime) ve İngilizce Wikipedia (yaklaşık 2,5 milyar kelime), toplam yaklaşık 3,3 milyar kelime.

> **Ders sonrası not:** 4. sunumda BERT ön işlemesine "part of speech" de eklendi. BERT sözcük türü etiketi kullanmaz; girdisi WordPiece token'larıdır.

> **Ders sonrası not:** 4. sunumdaki adlar: "math language / NBERT" çok dilli BERT (Multilingual BERT, mBERT), "Perspert" ParsBERT, "Cameron BERT" CamemBERT, "KovBERT" büyük olasılıkla ConvBERT, "Tribank" Treebank, "Stanford Quarlesming" SQuAD. Makale yazarları altyazıda bozuk geçtiği için not metnine yazılmadı. "BERT-Base daha çok OpenAI'a benzeyen taraf" ifadesi, BERT-Base'in OpenAI GPT ile karşılaştırılabilir boyutta tasarlanmasına işaret eder.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
