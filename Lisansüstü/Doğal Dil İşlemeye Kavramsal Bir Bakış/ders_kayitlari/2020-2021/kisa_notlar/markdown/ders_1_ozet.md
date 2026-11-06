# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin işleyişi, değerlendirme sistemi ve beklentiler.
- Dersin kapsamı ve konu listesi.
- Dil nedir, doğal dil ve yapay dil (programming language) farkı.
- Doğal dil işlemenin (Natural Language Processing, NLP) uygulama alanları.
- Doğal dil işlemedeki zorluklar ve belirsizlikler (ambiguity).
- Dil analizinin seviyeleri: ses bilimi (phonology), biçim bilim (morphology), söz dizimi (syntax), anlam bilimi (semantics), söylem (discourse), edim (pragmatics).
- Biçimbilimsel analizde çoklu çözüm sorunu (Zemberek örneği).
- Sözcük türü (Part of Speech, POS) etiketleri, eş dizimlilik (collocation), ayrıştırma (parsing).
- Varlık ismi tanıma (Named Entity Recognition), zamir çözümleme (anaphora resolution), edat bağlama (prepositional attachment), kelime anlamı belirginleştirme (word sense disambiguation).
- Bilgiye erişim (information retrieval), bilgi çıkarımı (information extraction), soru cevaplama (question answering), makine çevirisi (machine translation).
- Söylem ve edim bilgisinin bağlama (context) bağımlılığı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ders tamamen proje ağırlıklıdır. Ödevler ve seminer verilse, vizeden 100 alınsa bile başı sonu olan bir proje teslim edilmezse dersten geçilmez.
- Vize çoktan seçmeli test olacak. Konu çok fazla olduğu için her konunun "olmazsa olmaz" anahtar kelimeleri ve tanımları sorulacak.
  - Hoca bir şeyi derste ne kadar çok tekrar ediyor ve vurguluyorsa o konunun temel anahtar kelimesi odur.
- Yazılı final sınavı yok. Final tarihinde proje demosu yapılacak.
  - Her öğrenci ekranını paylaşıp yaklaşık 15 dakikada projenin konusunu, kullandığı yöntemleri ve çalışır hâlini gösterecek.
  - Ayrıca 1 (gerekirse 2) sayfalık bir rapor teslim edilecek. Hoca bu raporu sınav evrakı olarak saklayacak.
- Terimler hep İngilizce de verilecek, çünkü literatür İngilizce. Örneğin "pragmatik" kelimesinin Türkçesi "edim"dir ama bu karşılık pek anlam ifade etmiyor.
- Dil modelleri çok önemli. Dil modeli olmadan bilgisayarda dille ilgili hiçbir çalışma yapılamaz. Derin öğrenmeden önce kural tabanlı ve istatistiksel yöntemlerde de dil modelleri temeldi.
- Türkçe sondan eklemeli (agglutinative) bir dildir ve bu yüzden işlenmesi zordur.
- Bilgisayarın bilmediği dile bakışı, bizim hiç bilmediğimiz bir dile bakışımız gibidir. Dili ona adım adım anlatmak gerekir.
- Söylem ve edim çalışmalarında bağlamı bilmeden doğru yorum yapılamaz. Bilgisayarı ülkeyi ve kültürü hiç bilmeyen bir yabancı gibi düşünün.
- Projelerde dil kısıtı yok. Türkçe veya İngilizce üzerinde çalışılabilir. Programlama dili olarak NLP kütüphaneleri çok olduğu için Python öneriliyor. Java da kullanılabilir.

## Kısa Tekrar Notları

- Değerlendirme: dönem içi %60, final %40.
  - Dönem içi: 1-2 küçük ödev (biri düzenli ifadeler, biri n-gram), bir seminer, vize.
  - Final: proje demosu ve kısa rapor.
- Seminer: hoca konuları ve makaleleri (paper) belirleyecek. Her öğrenci bir makale seçecek. Seçimler grup üzerinden paylaşılacak ki aynı konu iki kez seçilmesin. Konular proje çıkabilecek konulardan seçilecek.
- Doktora öğrencilerinin geçme notu yüksek lisanstan daha yüksektir.
- Dersin slaytları hocanın AVESİS sayfasında. Slaytlar her hafta güncellenebileceği için hepsini toplu indirmeyin.
- Kaynaklar:
  - Jurafsky ve Martin, Speech and Language Processing (temel ders kitabı).
  - Manning ve Schütze, Foundations of Statistical Natural Language Processing.
  - İnternet (ders slaytları, kitap bölümleri).
- Dil: sözcük ve cümle birimleri aracılığıyla düşünceyi konuşma ile ilişkilendiren çok seviyeli bir sistem. Kısaca insanlar arasındaki iletişim aracı.
- Sondan eklemeli diller: Türkçe, Fince, Japonca.
  - İngilizcede "book" yalnızca birkaç biçim alır (-s, -ing, -ed).
  - Türkçede "kitap" kelimesine çok sayıda ek eklenebilir: kitabı, kitaba, kitapta, kitaptan, kitabımız, kitabıydı...
- Yeryüzünde 3000 ile 4000 arasında dil var.
- UNESCO'nun belirlediği büyük diller: Çince, İngilizce, İspanyolca, Rusça, Fransızca, Arapça. Slayta göre Türk dili ve lehçeleri 5. sırada; hoca bu bilginin hangi yıla ait olduğunu kaynakta belirtmediğini söylüyor.
- İlk yapay dil: Zamenhof'un ortaya attığı Esperanto.
- Hiyerarşi: bilgisayar bilimleri > yapay zeka > doğal dil işleme.
  - Yapay zekanın diğer dalları: robotik, uzman sistemler, örüntü tanıma, görüntü tanıma, veri madenciliği.
- Türkçe için biçimbilimsel analiz aracı: Zemberek (POS etiketleriyle çıktı verir).
- İngilizce için yaygın araç: NLTK (Natural Language Toolkit).
- Varlık isminin en önemli beş türü: kişi (person), yer (location), kurum (organization), tarih (date), para birimi (currency).
- Anlamsal analizde 5N1K soruları: kim, ne, nerede, ne zaman, nasıl, neden.
- Makine çevirisi için paralel derlem (parallel corpus) şarttır. Örnek: Kanada Parlamentosu'nun İngilizce ve Fransızca tutanakları.

## Detaylı Açıklamalar

### Dersin İşleyişi ve Duyurular

- Ders slaytlar üzerinden anlatılacak. Tahtada anlatılması gereken konular için hoca video çekip derste gösterecek.
- Hoca her 50 dakikada bir ara vermeye çalışacak.
- Soru sormak için sohbet (chat) kullanılabilir.
- Öğrencilerden hocanın Gmail adresine e-posta atmaları istendi. E-postada:
  - Yüksek lisans mı doktora mı olduğunuz.
  - Lisans bölümünüz.
  - Doktora öğrencileri için yüksek lisansta çalıştıkları konu.
- Hoca e-postalara aynı gün içinde, bazen tek kelimeyle hızlıca cevap verir. Bunu kızgınlık olarak algılamayın.
- 15 Ekim 2020 haftasında ders büyük ihtimalle yapılmayacak:
  - Hoca aynı gün yürütme kurulunda olduğu bir sempozyumun açılışında ve fakülte temsilcisi olduğu bir Bilimsel Araştırma Projeleri toplantısında olacak.
  - Ders, ek ders modülü gelince telafi edilecek.
  - Akıllı Sistemlerde Yenilikler ve Uygulamaları Sempozyumu (ASYU) oturumlarının bağlantısı paylaşılacak. 3 gün süren sempozyumda NLP oturumları da var. Müsait olunca dinleyin; proje fikri bulmanıza yardımcı olabilir.
- Projeler büyük olmamalı. Bazı konular bir yılda ancak bitebilecek (doktora tezi düzeyinde) çalışmalardır. Hoca seminer konularını proje çıkabilecek konulardan seçecek. Öğrenci isterse seminer ve projesini farklı konulardan seçebilir.

### Dersin Kapsamı

- Dersin adının "kavramsal bir bakış" olmasının sebebi: yurt dışında her biri bir dönemlik ders olan konular (bilgiye erişim, makine çevirisi, makine öğrenmesi, soru cevaplama) bu derste birer haftaya sığdırılıyor.
- Hoca bilgisayar bilimleri kökenli olduğu için dersi metin işleme (text processing) ağırlıklı anlatıyor. Elektronik kökenli biri sinyal işleme tarafını, yani konuşmadan metne (speech to text) ve metinden konuşmaya (text to speech) dönüşümü öne çıkarırdı.
- Ders iki parçadan oluşur:
  - Birinci parça: dil biliminin ilgilendiği klasik aşamalar. İngilizce için bunlar hazır araçlara (tool) dönüşmüş, başarılar %95-98'in üstünde. Türkçe için araçlar var ama eksik.
  - İkinci parça: yapay zeka uygulamaları. Bunlar birinci parçadaki araçları kullanır.
- Konu listesi (slayttan):
  - Doğal Dil İşlemeye Genel Bakış (Course Overview)
  - Dilbiliminin Esasları (Linguistics Essentials)
  - Gramer ve Diller (Grammar and Language)
  - Düzenli Diller (Regular Expression): küçük bir ödev verilecek.
  - Dil Modelleri, N-Gram (Language Models): küçük bir ödev verilecek.
  - Biçimbilimsel Analiz (Morphological Analysis)
  - Sözdizimsel Analiz ve POS (Syntax Analysis, Part of Speech Tagging)
  - Anlam Bilgisi (Semantics), Söylem (Discourse) Bilgisi, Edim (Pragmatics) Bilgisi
  - Eş Dizimlilik (Collocation)
  - Saklı Markov Modeli (Hidden Markov Model, HMM) ve Viterbi algoritması: slaytta italik, zaman kalırsa anlatılacak.
  - Makine Öğrenmesi (Machine Learning): bir dönemlik ders 1-2 saatte özetlenecek.
  - Metin Sınıflandırma (Text Classification)
  - Bilgiye Erişim Sistemleri (Information Retrieval)
  - Bilgi Çıkarımı (Information Extraction)
  - Kelime Anlamları (Word Semantics)
  - Kelime Gömmeleri (Word Embedding): RNN, CNN, LSTM gibi modeller derinlemesine anlatılmayacak; bunlar derin öğrenme dersinin konusu.
  - Duygu Analizi (Sentiment Analysis)
  - Soru Cevaplama Sistemleri (Question Answering)
  - Makine Çevirisi (Machine Translation): slaytta italik. Hoca bu konuyla hiç çalışmadığını söylüyor.
  - Projeler, Araştırma Ödevi, Seminer

### Dil ve Doğal Dil İşleme

- İnsanlar önce duman ve el kol hareketleriyle, sonra seslerle anlaştı. Sesler kelimelere, kelimeler cümlelere, cümleler paragraflara, paragraflar dokümanlara dönüştü.
- Dili bilgisayara aktarmak için dili modellemek gerekir. Çok basit dillerin modellenmesi kolaydır ama zaten bilgisayara aktarılmaları gerekmez.
- İlk NLP çalışmalarında bilgisayarcılar dil bilimcilerle (linguist) birlikte çalıştı.
  - Dil bilimciler dil modelini kağıt üzerinde çıkardı, bilgisayarcılar kodladı. Mimarın çizdiği binayı inşaat mühendisinin yapması gibi.
  - Sonra dil bilimciler bu çalışmalardan çekildi.
- NLP son 10 yılda popüler oldu. Önceden çalışmalar çoğunlukla görüntü işleme üzerineydi.
- Doküman sayısı üstel (exponential) olarak artıyor. İşlenmeyen bir yazılı belge arşivde kalmaya mahkûmdur. Önemli olan onu işleyip bilgiye dönüştürmektir.
- Yayınların çoğu İngilizce üzerine. Son zamanlarda Çince çalışmalar arttı.
- Aynı aileden diller arasında bile kültür farkı önemlidir. Azerice haberde "uçak düştü" ifadesi "uçak indi" anlamında kullanılır.
- İnsanı bilgisayardan ayıranlar: sağduyu (common sense), mantıklı düşünüp kıyaslama yapma ve deneyim. Bilgisayarın üstünlüğü: öğrendiğini hiç unutmaz.

### Doğal Dil İşleme Uygulamaları

- Yazım yanlışı denetimi: "çocukler" yazınca editör hatayı işaretler, çünkü arkadaki dil modeli "çocuk" kelimesinin "-ler" eki almayacağını bilir.
- Makine çevirisi:
  - İlk çeviriler İngilizce ile ona yakın diller arasında başladı.
  - Yarı otomatik çeviri: makine çevirir, insan düzeltir.
  - Google Translate'in son yıllardaki başarısı derin öğrenmeye geçmesinden gelir. Kısa cümleleri iyi çevirir, 3-4 satırlık uzun cümlelerde zorlanır.
- Soru cevaplama:
  - Veri tabanı tabanlı sistemler: "Bugün saat 9'da hangi dersim var?" sorusundan anahtar kelimeler çıkarılır ve bir SQL sorgusu kurulur. Bu sistemler başarılıdır.
  - Konuya odaklı (closed domain) sistemler: örneğin yalnızca banka müşterilerinin sorularını cevaplayan sistem. Başarı yüksektir.
  - Açık alan (open domain) sistemler: "internette ne sorarsan sor" türü. Başarı hemen düşer.
  - İç içe sorular: "Mustafa Kemal Atatürk'ün kurduğu devletin başkenti neresidir?" Önce devlet bulunur, sonra başkenti aranır.
- Bilgisayar destekli dil öğretimi.
- Çok dilli sözlüklere erişim: soru Türkçe sorulur, anahtar kelime çevrilir, yabancı dilde arama yapılır, cevap bulunup tekrar Türkçeye çevrilir. Arada bilgiye erişim, bilgi çıkarımı ve soru cevaplama vardır.
- Cümle ve metin üretme: verilen kelimelerle anlam bütünlüğü olan cümleler kurma.
- Metin özetleme:
  - Metinden en uygun cümleleri seçme (kolay yöntem).
  - Aynı konudaki birden fazla metinden tek özet çıkarma: aynı anlamı veren farklı cümlelerin tespiti gerekir.
  - Yorumlayarak özetleme: okuyup kendi cümleleriyle yazma. Çok zor; derin öğrenmeyle şekillenmeye başladı.
- Otomatik konuşma ve komut anlama.
- Konuşmadan metne (STT) ve metinden konuşmaya (TTS):
  - Metni konuşmaya çevirmek daha kolay: kelime hecelere bölünür, sesler birleştirilir. Vurgu da işaretlenirse daha insan gibi konuşur.
  - Konuşmayı metne çevirmek daha zor: şive, lehçe, hızlı konuşma, noktalama olmaması, yanlış telaffuz ("geliyorum" yerine "celiyorum").
- Metinden bilgi çıkarma: verilen şirket web sayfalarından telefon ve adres bilgilerini bir uygulamayla çıkarmak, tek tek okumaktan kolaydır.
- Gelecekteki hedef: klavye ve fare kullanmadan göz hareketi ve sesle bilgisayarı yönetmek.

### Doğal Dil İşlemedeki Zorluklar

- Kuralsız ve anlaşılmaz konuşmalar, argo kelimeler.
- Kuralsız ve bozuk yazılar: önce düzeltme gerekir. Eksik harf için ekleme (insertion), yanlış harf için değiştirme (substitution) işlemi.
- Konuşmayı bölme: durmadan konuşan birinin cümlesinin nerede başlayıp bittiği belli değildir.
- Metni bölme: paragraf uzunluğundaki cümlelerin bölünmesi.
- Yanlış çeviri örneği: "Köprücüler İstanbul'da toplanıyor."
  - İngilizce haberde "bridge" kelimesi geçiyor. Otomatik çeviri sözlükteki ilk anlam olan "köprü"yü almış.
  - Doğrusu kağıt oyunu "briç". Yani "Briç oyuncuları İstanbul'da toplanıyor."
  - Bir yanlış, analizde başka yanlışları getirir.
- Anlam belirsizliği örneği:
  - "Banu armutları ayılara aç oldukları için verdi."
  - "Banu armutları ayılara tatlı oldukları için verdi."
  - İki cümle de söz dizimi açısından doğru ama anlamları farklı. "Aç" ayılarla, "tatlı" armutlarla ilişkili. Kelimeler arasındaki ilişkiler kurulmadan bu anlam çıkarılamaz.
- NLP problemleri çok fazla belirsizlik içerir ve genel hâlleriyle çözülemez. Belirli, dar bir probleme indirgenerek çözülmeye çalışılır.
- Hocanın genel tavsiyesi: Sistem %80 başarılıysa, ek uğraşla %82'ye çıkarmanın bu eforu hak edip etmediğine siz karar verirsiniz.

### Dil Analizinin Seviyeleri

- Konuşma dilinde pek kural yoktur. "Ben gitmek Sultanahmet" diyen turisti anlarız ama bilgisayar anlayamaz. Yazı dili seviyelerden oluşur:

```text
Ses bilimi (phonology)      : sesler ve onlara atanan semboller (harfler)
Biçim bilim (morphology)    : kelimenin yapısı, kök ve ekler
Söz dizimi (syntax)         : cümle o dile ait mi?
Anlam bilimi (semantics)    : cümlenin anlamı (5N1K)
Söylem (discourse)          : birden fazla cümle, bağlam
Edim (pragmatics)           : metni anlayıp yorumlama, kullanım
```

- Söz dizimi örneği: "Gökyüzü solucan deniz sevmek." Kelimelerin hepsi Türkçe ve biçimbilimsel analizden geçer, ama bu bir cümle değildir. Söz dizim analizi cümlenin o dile ait olup olmadığına karar verir.

### Biçimbilimsel Analiz ve Zemberek

- Dört cümlede de "çocukları" kelimesi geçiyor:
  - "Sevgi'nin çocukları Ayşe ve Mehmet geldiler."
  - "Yeni gelen çocukları gördünüz mü?"
  - "Ayşe ile Mehmet'in çocukları Gökhan ile Sevgi'dir."
  - "Ayşe'nin çocukları Gökhan ile Sevgi'dir."
- Kelime aynı ama çözümlemeler farklı:
  - Kök "çocuk" (isim) + çoğul "-lar" + 3. tekil kişi iyelik "-ı".
  - Kök "çocuk" + çoğul "-lar" + belirtme hâli "-ı".
  - Kök "çocuk" + 3. çoğul kişi iyelik "-ları" (sahip iki kişi).
- Zemberek bir kelimenin bütün olası çözümlerini verir, en sık kullanılanı birinci sıraya koyar. Ama cümle için hangisinin doğru olduğunu söylemez.
- Doğru çözümü seçmek için bağlılık analizi (dependency parsing) gerekir: yüklem kime bağlı, nesne kime bağlı, kim kimden etkilenmiş.
- Akademik çalışmalarda genellikle Zemberek'in verdiği ilk çözüm kullanılır.
  - Amaç yalnızca "çocuk" kelimesinin metinde kaç kez geçtiğini veya kaç isim olduğunu bulmaksa bu yeterlidir.
  - 5N1K gibi anlamsal analiz yapılacaksa doğru çözümün seçilmesi gerekir.
- Türkiye'de bu alandaki ilk çalışmalar Kemal Oflazer'e aittir. İTÜ'deki Doğal Dil İşleme grubu (Gülşen Hoca) bu çalışmaları ilerletti.
  - Grubun web üzerinden sunduğu bir boru hattı (pipeline) var: metni cümlelere ve kelimelere ayırır, biçimbilimsel çözümleme, söz dizimi analizi ve bağlılık analizi yapar.
  - Açık kaynak değil. Ticari kullanım engellendiği için yalnızca izinle, akademik çalışmalarda web üzerinden kullanılabiliyor. Binlerce doküman için yavaş kalıyor.

### Söz Dizimi Analizi ve İlgili Problemler

- POS etiketleri: kelimeye sözcük türü etiketi verilir.
  - "The dog ate my homework": "dog" isim (noun), "ate" geçmiş zaman fiil (simple past verb). Çoğul isimler ayrı etiket alır.
  - Dünya genelinde tek bir standart etiket kümesi kullanılır. Önceden herkes farklı etiket kullanıyordu ve karışıklık çıkıyordu.
- Eş dizimlilik (collocation):
  - "hot dog": "sıcak köpek" (sıfat + isim) değil, tek bir isim (sosis).
  - "kitap kurdu": çok okuyan kişi. İşaretlenmezse "kurdu" hayvan olan "kurt" mu, "kurmak" fiilinin geçmiş zamanı mı belirsiz kalır.
  - Bu yüzden işlemden önce eş dizimlilerin çıkarılması gerekebilir. Bu ayrı bir uygulama ve maliyettir.
  - Türkçe için eş dizimlilik çalışmaları daha çok dil bilimciler tarafından teorik olarak yapılmış.
- Ayrıştırma (parsing): cümle bir ağacın köküdür. Cümle parçalana parçalana yapraklara inilir.
  - "The dog chased the bear": önce özne kısmı ve yüklem kısmı olarak ikiye bölünür, sonra her kısım kendi içinde bölünür.
  - NP: isim öbeği (noun phrase). VP: fiil öbeği (verb phrase).
  - "John loves Mary": "John" isim öbeği, "loves Mary" fiil öbeği. Fiil öbeği de fiil ve isim öbeğinden oluşur.

```text
S
├── NP: John
└── VP
    ├── V: loves
    └── NP: Mary
```

- Bütün kelimeler yapraklara oturuyorsa cümle söz dizimi analizinden geçer. Ayrıştırma bir yerde tıkanırsa cümle hatalıdır.
- Kurallar (bir cümle hangi öğelerden oluşur, öğeler hangi ekleri alır) dil bilimciler tarafından çıkarılır, uygulamayı yazanlar bunları kodlar.
- Öğrenci sorusu: Bilgisayar "John" ve "Mary"nin özel isim olduğunu nasıl anlar?
  - Ya metinde varlık ismi tanıma (Named Entity Recognition) yapılır ya da elde bir özel isim sözlüğü olur.
  - Sözlükler bu çalışmalarda çok önemli. Fiil sözlüğü olmazsa "love"ın fiil olduğu anlaşılmaz. İngilizce için düzenli ve düzensiz fiillerin ayrı sözlükleri gerekir.
- Zamir çözümleme (anaphora resolution):
  - "Köpek odaya girdi ve beni korkuttu." Beni korkutan kim? İngilizcede "it" zamiri köpeği gösterir.
  - Türkçede zamir yazılmayabilir. "korkuttu"daki "-du" ekinden 3. tekil şahıs olduğu anlaşılır ve köpeğe bağlanır.
  - Türkçe için bu konudaki çalışmalar az ve yetersiz.
- Edat bağlama (prepositional attachment):
  - "I saw the man in the park with a telescope."
  - Anlam 1: Parkta teleskoplu bir adam gördüm.
  - Anlam 2: Teleskopumla bakarak parkta bir adam gördüm.
  - İki ayrıştırma ağacı da İngilizce kurallarına uyar. Doğrusunu bulmak için önceki cümlelere bakmak gerekir.

### Anlamsal Analiz ve Kelime Anlamı Belirginleştirme

- Anlamsal analizde problem kelimelerdeki belirsizliktir. Çözümüne kelime anlamı belirginleştirme (word sense disambiguation) denir.
- "plant": endüstriyel tesis (industrial plant) veya canlı organizma (bitki).
  - Makine çevirisinde yanlış çeviriye yol açar.
  - Bilgiye erişimde "plant" araması iki anlamdaki dokümanları da getirir.
- "Fatih" örneği:
  - "Bugün Fatih ile görüşeceğim." Kişi (person).
  - "Biz Fatih'te oturuyoruz." Yer (location).
  - İkisi de büyük harfle başlayan özel isimdir. Ayırt etmek için varlık ismi tanıma gerekir.
- "yüz" kelimesini İngilizceye çevirmek: hundred mı, face mi, swim mi?
  - Sözlük tabanlı çeviri ilk karşılığı alır ve yanlış olabilir.
  - Derin öğrenme yaklaşımı: her anlam için yaklaşık bin cümle toplanır ve sistem bunlarla eğitilir.
  - "Yüzmek" anlamındaki cümlelerde spor, deniz, güneş, tatil gibi kelimeler; "yüz" sayısı anlamındakilerde sayı, para gibi kelimeler geçer.
  - Çevrilecek cümledeki komşu kelimeler hangi anlamın kelimeleriyle örtüşüyorsa o anlam seçilir.
  - En zor kısım cümlelerin bulunup etiketlenmesidir. Wikipedia sayfaları ve bağlantıları kullanılarak etiketli cümle çıkarılabilir mi diye düşünülebilir.
  - Hoca bunun iyi bir proje konusu olabileceğini söylüyor.
- Hocanın tahmini: Bu ayrıntılar dikkate alınmadan yapılan bir çalışma %70 civarı başarı verir. Dikkate alınırsa başarı %70-80 aralığına çıkabilir. Hoca bunun kendi denemesi değil, yapılan çalışmaların gösterdiği yaklaşık bir değer olduğunu söylüyor.

### Bilgiye Erişim, Bilgi Çıkarımı ve Soru Cevaplama

- Bilgiye erişim: arama motorlarında her gün yaptığımız iş.
  - İlerleyen derslerde vektör modelleri (vector models), Boolean modeller ve anlamsal ilişki tabanlı modeller anlatılacak.
  - Arama motorlarında en önemli şey indekslemedir (indexing). Daha çok sayfa, daha sık indekslenirse sonuç daha başarılı olur. Bunun için güçlü bilgisayar ve hızlı algoritma gerekir.
- Bilgi çıkarımı: getirilen sayfanın içinden aranan bilgiyi okumadan, bir uygulamayla çıkarmak.
  - Varlık ismi tanıma da bilgi çıkarımının bir alt konusudur.
  - Örnek cümle: "75. karayolunda yaklaşık 8-9 kişilik bir grup var." Cümleden kaç kişi, hangi yol, nerede gibi bilgiler çıkarılır.
  - Bunun için kalıplar (pattern) yazılır ve metinde aranır.
  - ABD'de bu alanda ödüllü yarışmalar düzenleniyor. Amaç internetteki her veriyi hızla izleyip ilgili bilgiyi bulmak.
- Örnek proje fikri: düz metin olarak yazılmış özgeçmişten (CV) bilgi çıkarma.
  - Çıkarılacaklar: ad, askerlik durumu, mezun olunan üniversite, konuşulan diller, bilinen programlama dilleri, ilgi alanları.
  - Metin yapılandırılmamış (unstructured). Düzenli ifade (regex) yazılabilir veya insanların bu bilgiyi ifade ettiği 3-5 kalıp çıkarılıp metinde aranabilir.
- Soru cevaplama: alan daraldıkça başarı artar. Çift aşamalı soru örneği: "Dünyanın en yüksek tepesi ne kadar yüksektir?" Önce tepe (Everest), sonra yüksekliği bulunur.
- Diller arası bilgiye erişim (cross-language information retrieval):
  - Örnek soru: "İtalya'da araba kiralamak için en az kaç yaşında olmak gerekir?"
  - Anahtar kelimeler (en az yaş, araba kiralama, İtalya) İtalyancaya çevrilir ve aranır.
  - Gelen sayfada bu kelimelerle birlikte 18-20 gibi bir sayı geçen cümle kullanıcıya gösterilir.
- Makine çevirisi metinden metne veya konuşmadan konuşmaya yapılabilir. Paralel derlem şarttır.
  - Kanada'da iki resmî dil olduğu için parlamento tutanakları İngilizce ve Fransızca tutulur. Bu hazır bir paralel derlemdir.
  - Wikipedia'nın İngilizce ve Türkçe sayfaları birebir çeviri olmadığı için bu amaçla kullanılamaz.

### Söylem (Discourse) ve Edim (Pragmatics)

- Söylem: kendimizi yazılı, sözlü veya elektronik ortamda ifade etmemiz. Yazılı ve elektronik ortamın üslubu farklı olduğu için ayrı sayılır.
  - Söylem cümle bazında değil, dokümanda cümleler arası ilişkilere ve bağlama bakılarak çıkarılır.
  - Uzun bir metni anlamlandırmak için onu başlık, giriş, gelişme ve sonuç kısımlarına bölmek gerekir.
- Etkili bir söylemin şartları:
  - Dil: söylem yapılan dile hakim olmak.
  - Söyleyiş biçimi: telaffuz, şive, lehçe farkları. Vücut dili konuşmayı renklendirir.
  - İlişki: samimi bir arkadaşla ve bir rektörle farklı konuşulur. Sosyal medyada vücut dili olmadığı için yanlış anlaşılmalar olur; emojiler bunu tamamlamak için geliştirildi.
  - Etkinlik türü: ders anlatmak, tanıdık veya tanımadık kalabalığa konuşmak farklıdır.
  - Ülkü: sonuca ulaşmak, yani karşıdakine vermek istenen anlamın verilebilmesi.
- Gerçek bir örnek (2019 Mart, İstanbul Garipçe Köyü'ndeki bir tabela): "Mayo ve bikini ile denize girmek yasaktır."
  - Yabancının olası yorumları: denize çıplak girilir; denize elbiseyle girilir; burası plaj değil, denize girilmez.
  - Türk biri ne denmek istendiğini anlar. Bilgisayar ise o yabancı gibidir; ülkeyi ve kültürü bilmez.
- Edim (pragmatics, "kullanım" olarak da geçer):
  - Söz dizimi ve anlam bilimi tek cümle üzerinde, söylem birden fazla cümle üzerinde çalışır. Edim metni anlayıp yorumlamaya çalışır.
  - Örnek 1: Yolcu "Metro istasyonu nerede biliyor musun?" diye sorar. Karşıdaki "Evet, biliyorum." deyip gider. Soruya cevap verilmiştir ama beklenen cevap yerin söylenmesidir.
  - Örnek 2: Ev sahibi "Çocuğunuz var mı?" diye sorar. Kiracı "10 yaşında bir oğlum ve küçük bir köpeğim var." der. Ev sahibi "Bu kötü." der.
    - Bağlam bilinmeden köpek sahibi olmanın kötü olduğu anlaşılır.
    - Gerçek anlam: kiracı adayında az kişi olması ve evcil hayvan olmaması aranıyor. "Bu kötü" aslında "evi sana vermem" demektir.
  - Bu tür bilgileri bilgisayara öğretmek bitmeyen bir iştir. Bu da başarıyı düşürür.

### Ders sonrası notlar

- Hoca NLP problemleri için "NP problem" ifadesini "non-polynomial" olarak açıkladı. Doğrusu: NP, "nondeterministic polynomial" (belirlenimci olmayan polinom zaman) sınıfının kısaltmasıdır. Hocanın asıl vurgusu doğru: bu problemlerin genel hâlinin verimli bir çözümü bilinmiyor, bu yüzden problem daraltılarak çözülüyor.
- Hoca NLTK'nin Stanford Üniversitesi'nin geliştirdiği bir araç olduğunu söyledi. NLTK aslında Pennsylvania Üniversitesi'nde geliştirildi. Stanford'un aracı Stanford CoreNLP'dir.
- Altyazıda kitap yazarları "Jorowski" ve "Schultz" olarak geçiyor. Doğrusu Jurafsky ve Schütze.
- Altyazıda Esperanto'nun yaratıcısı "Zamenkov" olarak geçiyor. Doğrusu Zamenhof.
- Hoca 5N1K sorularını sayarken bir an takıldı. Altı soru: kim, ne, nerede, ne zaman, nasıl, neden (niçin).

İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
