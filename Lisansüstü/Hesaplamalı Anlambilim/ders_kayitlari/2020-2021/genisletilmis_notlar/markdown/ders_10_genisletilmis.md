# Ders 10 Genişletilmiş Notu: Varlık İsmi Tanıma, Soru Cevaplama, Veri Kümelerindeki Arka Kapılar ve Metin Üretimi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Tekrar: Metin Sınıflandırma ve Duygu Durum Analizinde Temsiller
- 2. Karakter Bazlı Yapılar ve Duygu Analizinin Zorluğu
- 3. Varlık İsmi Tanıma (NER)
- 4. Paragraf Anlama
- 5. Soru Cevaplama: Cevap Nerede?
- 6. Bilim Soruları, Açıklamalı Çözümler ve SWAG
- 7. Basit Hikayelerde Çıkarım ve Memory Networks
- 8. İtiraz: Veri Kümelerindeki Arka Kapılar
- 9. Entailment Veri Kümelerinde Benzer Problemler
- 10. LSTM ile Metin Üretimi
- Örnek Sorular
- Dersin Toparlaması

## 1. Tekrar: Metin Sınıflandırma ve Duygu Durum Analizinde Temsiller

Ders, Bölüm 6'nın "Uygulamalar" slaytına (bolum6.pptx) önceki derste kalınan yerden dönerek başladı. Metin sınıflandırmanın ne olduğu biliniyor: paylaşılan kodlarda metinler LSI ile ya da TF-IDF ve n-gram temsilleriyle sınıflandırılıyor ve eğitim örneği sayısı arttıkça başarı artıyor. Bu klasik bir sonuçtur.

Duygu durum analizinde (ekrandan, 00:15:10) amaç, bir firma, kişi, parti, kurum ya da olay hakkında kamuoyu algısını ölçmektir. Slaytta ayrıca algı operatörü botlara dikkat edilmesi gerektiği (tahminen %20), eğitim kümelerinin genelde eskidiği ve metin temsilinde klasik yaklaşımların (kelime, kelime kökü, n-gram) ve yeni yaklaşımların (semantik uzaylar, LSTM, CNN) bulunduğu yazıyor. Paylaşılan kodda (`sentiment_deep_or_classical` deposu) şu yöntemler karşılaştırılıyor:

- **Kelime torbası (bag of words):** Her kelime bir özellik, yani bir boyut olarak düşünülür; TF-IDF gibi ağırlıklar kullanılabilir.
- **Karakter 3-gram torbası:** Sözlük kelimelerden değil, metin karakter karakter kaydırılarak elde edilen ardışık üç karakterlerden oluşur.
- **Kelime vektörü ortalamaları:** Aşağıda anlatılıyor.
- **Kelime bazlı LSTM, kelime bazlı CNN ve karakter bazlı CNN.**

### 1.1 Kelime vektörü ortalaması

Daha önce görülen word2vec ve fastText gibi yöntemlerle her kelimenin anlamsal uzaydaki temsili (vektörü) bulunabilir. Beş kelimelik bir metnin koordinatını belirlemek için bu beş kelimenin vektörlerinin ortalaması alınır. Kelime vektörleri örneğin 300 boyutluysa, kelimelerin birinci boyutlarının ortalaması metnin birinci boyutu olur, ikinci boyutların ortalaması ikinci boyutu olur ve bu böyle gider.

Ortalama almanın iki yararı var. Birincisi, farklı uzunluktaki metinler aynı uzunlukta bir vektörle temsil edilir: metinde beş kelime de olsa elli kelime de olsa sonuç 300 boyutludur. İkincisi, ortalama metnin genel olarak hangi konulardan bahsettiğini bir ölçüde ifade eder.

Sakıncası da var. Hoca tahtaya çizerek anlattı: metindeki kelimeler anlamsal uzayda birbirinden çok uzak noktalardaysa, ortalamaları hiçbirine yakın olmayan bir noktaya düşer. Kelimeler birkaç yakın topak oluşturuyorsa, onları bir ortalama noktayla (hocanın çizimindeki yıldızla) temsil etmek çok büyük bir sorun olmayabilir.

### 1.2 Kelime bazlı CNN: metni resme dönüştürmek

Kelime bazlı evrişimsel sinir ağında (ekrandan, 00:20:00) metin bir M matrisine dönüştürülür. Slayttaki tanıma göre M matrisi $n_m$ satır ve $d_m$ sütundan oluşur; $d_m$ kelimelerin temsil edildiği vektörlerin boyutudur. Metnin her kelimesine karşılık gelen vektör, metindeki sırasıyla matrisin bir satırına yazılır. $n_m$ en büyük metin uzunluğudur; metin daha kısaysa matrisin geri kalan alt kısmı 0'larla doldurulur (padding).

Padding'in amacı, verileri bu tür mimarilere aynı yapıda vermektir. Farklı boyutlu verileri CNN'lere vermek kolay değildir. LSTM'ler için durum farklıdır: kelimeler teker teker verilir. Resimlerde de aynı sorun vardır; ya resimler yeniden boyutlandırılır ya da padding yapılır.

Resimlerde klasik olarak $3 \times 3$, $5 \times 5$ gibi kerneller gezdirilir. Burada ise bir kelimenin tamamını kapsayan, örneğin $2 \times d$'lik kerneller kaydırılır. Slayta göre M'nin üzerinde $t$ adet $k_m \times d_m$'lik filtre gezdirilir ve evrişim sonuçları F'de tutulur. F'nin her sütunu bir filtrenin sonuçlarını gösterir. Her sütunun maksimum değeri bulunup B vektörüne yazılır. B vektörü ile S çıkış vektörü arasında tam bağlı bir katman vardır.

Hocanın sezgisi: kernellerden biri örneğin "çok güzel" ifadesini temsil ediyor olabilir; metinde bu ifadeyi gördüğü anda "burada bu var" der. Pooling gibi mekanizmalarla her filtrenin çıktısı tek bir değere iner ve tek boyutlu bir vektör oluşur. Böylece metinler bir resme dönüştürülmüş olur ve CNN gibi resimler üzerinde çalışan her tür uygulama metinlere de uygulanabilir hâle gelir.

### 1.3 Karakter bazlı CNN

Kelimeler 300 boyutta temsil edildiği gibi karakterler de temsil edilebilir. Ancak karakterlerin birbirine anlamsal benzerliği pek anlamlı olmadığı için harflerin temsilinde one-hot encoding kullanmak makuldür.

Slaytta (ekrandan, 00:21:10) "Allah cezanı versin XXX tüm müşterilerini kaybedersin inşallah." cümlesi için iki M matrisi gösterildi: solda kelime vektörü tabanlı, sağda karakter tabanlı. Sol matriste bilgi taşıyan satır sayısı kelime sayısına, sağdakinde karakter sayısına eşittir; sağ matriste her satırda yalnız bir hücre doludur (ilk karakter A, sonra L, L, tekrar A vb.). Bu matris de bir resimdir ve üzerinde, örneğin 80 farklı karakter varsa, $3 \times 80$'lik kerneller gezdirilebilir.

## 2. Karakter Bazlı Yapılar ve Duygu Analizinin Zorluğu

### 2.1 Karakter bazlı yapı neden daha iyi çalıştı?

Karşılaştırmada karakter bazlı evrişimsel ağlar biraz daha iyi çıkmıştı. Hoca bunun nedenini sordu.

**Soru:** Kelime bazlı yapı o kadar iyi çalışmamışken karakter bazlı yapının daha iyi çalışmasının temel sebebi ne olabilir? **Cevap:** Bir öğrenci sözlük dışı kalan kelimeleri önerdi; hoca bunun doğru olduğunu söyledi: kelime bazlı yaklaşımda kelimenin vektörünün elde olması gerekir, yoksa bu bir problemdir. Başka bir öğrencinin önerdiği "ç/c, ğ/g karışıklığı" ise hocanın aradığı cevap değildi. Hocanın asıl vurguladığı neden Türkçeye özgüdür: ekler. Olumsuzluk ve olumluluk gibi anlam katan çok sayıda ek vardır. Kelime bazlı yapılar bu ekleri tek başlarına iyi temsil edemez; karakter bazlı yapılar ise "seni seviyorum / seni sevmiyorum" farkını, yani "-mi, -ma, -me" gibi olumsuzluk eklerini çok kolay yakalayabilir. Kelimeyi bilmese bile sonuna gelen iki karaktere bakarak farkı yakalar.

### 2.2 Duygu durum analizi neden zordur?

Slayttaki örnekler (ekrandan, 00:30:00 karesinin kenar küçük resminde de görünür) şunlardı: "Yemeğimi 5 dakikada getirdiniz çok teşekkürler", "Yemeğimi 55 dakikada getirdiniz çok teşekkürler", "2500 TL'lik fatura için çok teşekkürler". İlk iki cümle arasında yalnız tek bir karakter fark var; ilki gerçekten bir teşekkür, ikincisi ise dalga geçiyor. Üçüncüsünde de gerçekten teşekkür edilmediği anlaşılıyor.

Bunların olumsuz olduğunu sisteme anlatmak çok zordur. Eğitim kümesinde ilk cümle, test kümesinde ikinci cümle varsa, test cümlesine en yakın eğitim örneği (bütün olumsuz örneklerden daha yakın olarak) ilk cümle çıkacaktır.

**Soru:** Bu iki cümle arasındaki farkı yakalamak için ne gerekir? **Cevap:** Bir öğrenci dakikadan önce gelen sayının, ortalama sipariş süresiyle karşılaştırılmasını önerdi. Hoca, sistemin 5 dakika ile 55 dakika arasındaki farkı algılaması gerektiğini, bunun da daha önce konuşulan hayat bilgisi veri tabanlarına (hayatımıza dair bilgileri içeren veri tabanlarına) denk geldiğini söyledi. Bu tür bilgi olmadan iki cümle arasındaki farkı algılamak pek mümkün değildir.

Üstelik bu ifadeler bağlama göre farklı yorumlanabilir. Dağın başındaki birine yemeğin normalde 3 saatte geldiğini düşünürsek, 55 dakika için teşekkür gerçek olabilir. Faturası her ay 5000 gelen biri 2500'lük fatura için gerçekten teşekkür ediyor olabilir. Bağlam bazen yalnız metnin içinden anlaşılamaz: kişinin daha önceki tweet'lerini, nerede olduğunu bilmek gerekebilir.

> **Hocanın vurgusu:** Duygu durum analizi gerçekten zor bir problemdir. Genel geçer, sık kullanılan ifadelerle başarılı olunabilir; ama bütün örneklerin kabaca %20'lik bir kısmı vardır ki onu çözmek gerçekten zordur.

## 3. Varlık İsmi Tanıma (NER)

### 3.1 Tanım ve etiketli veri

Varlık ismi tanıma (named entity recognition), slayttaki tanımla (ekrandan, 00:28:40), bir metnin içindeki önceden tanımlanmış varlıkları ve türlerini bulmaktır. Varlığı bulmak, aslında varlığın metindeki yerini bulmaktır.

Slayttaki örnek metin bir caz festivali haberidir ("8. Caz Festivali, 8-21 Ekim tarihleri arasında İstanbul, Ankara ve Adana'da caz ustaları ile müzikseverleri buluşturacak..."). Etiketli hâlinde varlıkların sağına soluna işaretler konur:

```text
<b_enamex TYPE="ORGANIZATION">AKBANK<e_enamex> 8. Caz Festivali , 8 - 21 Ekim tarihleri arasında ,
<b_enamex TYPE="LOCATION">İstanbul<e_enamex> , <b_enamex TYPE="LOCATION">Ankara<e_enamex> ve
<b_enamex TYPE="LOCATION">Adana<e_enamex> 'da caz ustaları ile müzikseverleri buluşturacak Festival 'in
<b_enamex TYPE="LOCATION">İstanbul<e_enamex> 'daki açılış konserini vokal ve piyano virtüözü Brezilyalı sanatçı
<b_enamex TYPE="PERSON">Tania Maria<e_enamex> yapacak
```

Burada "AKBANK" ifadesinin bir varlık (entity) olduğu ve tipinin organizasyon olduğu işaretlenmiş; İstanbul, Ankara ve Adana yer ismi (LOCATION), Tania Maria kişi (PERSON) olarak işaretlenmiş.

### 3.2 Sekans-to-sekans problemler

NER bir sekans-to-sekans (seq2seq) problemidir. Hoca slayta şunu yazdı (ekrandan, 00:35:40):

```text
Input:  W1 w2 w3 w4 w5
output: O  İ  İ  O  O
```

Bir sınıflandırma problemi çözülseydi çıkış tek bir sınıf olurdu: metin A sınıfından ya da B sınıfındandır. Seq2seq'te ise giriş de çıkış da bir dizidir. Örnekte $w_2$ ve $w_3$ isim, diğerleri değil; bu yüzden çıkış "O, İsim, İsim, O, O" olur. Buradaki O, "hiçbir şey değil" (varlık değil) anlamındadır.

**Soru:** Sekans-to-sekans mimarilere başka hangi problem türleri örnek verilebilir? **Cevap:** Öğrenciler üç örnek verdi ve hoca hepsini onayladı:

- **Çeviri (translation):** Giriş bir cümle, çıkış başka dildeki karşılığı olan bir cümledir.
- **Soru cevaplama:** Cevabın bir metnin içindeki yerini bulmak.
- **Metin özetleme:** Giriş bir metin, çıkış o metnin özetidir; bütün metni okumak istemezsiniz.

Hoca özetlemenin iki türünü ayırdı. Birincisi metnin içindeki önemli cümleleri bulup onları ifade etmektir; bu kolay olan, çıkarımlı (extractive) özetlemedir, metnin içinden bir şeyler seçilir. İkincisi gerçekten özetlemektir: girişteki cümlelerle çıkıştaki cümleler farklıdır; örneğin birden fazla olay tek bir cümlede birleştirilebilir. Gerçek özet budur (soyutlayıcı, abstractive özetleme). Çıkarımlı olan daha kolaydır ve uygulaması daha yaygındır.

> **Ders sonrası not:** Hoca konuşma sırasında iki türü de "abstractive summarization" diye andı (00:32:03); anlattığı ayrım, önemli cümleleri seçen extractive özetleme ile yeni cümleler kuran abstractive özetleme arasındadır.

### 3.3 Klasik yaklaşım: CRF

Bu tür sekans problemlerinde en klasik yaklaşım CRF'lerdir (Conditional Random Fields). Özellikle varlık ismi tanımada çok başarılıdırlar.

> **Hocanın vurgusu:** Derin öğrenme bile NER alanında CRF'leri ortadan kaldıramadı. CRF'ler hâlâ derin öğrenme mimarilerinin içine bir katman olarak giriyor; tek başlarına da sonuçları hiç fena değil.

> **Ek bilgi (derste anlatılmadı):** CRF, girdi dizisi verildiğinde etiket dizisinin koşullu olasılığını modelleyen ayırt edici bir olasılıksal modeldir. Doğrusal zincir CRF, komşu etiketler arasındaki geçişleri de hesaba kattığı için örneğin bir kişi adının ortasında birden "O" etiketine geçmek gibi tutarsız diziler üretmeyi cezalandırır. Derin ağlarda yaygın kullanım biçimi BiLSTM ya da Transformer çıktılarının üzerine bir CRF katmanı koymaktır.

### 3.4 Karakter tabanlı LSTM ile NER

Derste paylaşılan kodlar (ekrandan, 00:40:00) `seq2seq_ner_3class.m`, `seq2seq_ner_7class.m` ve `leftPad.m`, veri kümeleri `Train7.MUClabeled`, `WFS7.MUClabeled` ve `NEtrain.txt`'tir. Slayta göre burada karakter tabanlı bir LSTM kullanılmıştır: giriş karakterlerin one-hot vektörleri, çıkış her karakterin sınıfıdır.

Yani her kelime için bir etiket bulunmuyor; girdide karakterler var ve her karakter için bir etiket söyleniyor. Bu, sekansın uzunluğunu artırır: kelime tabanında 5 girişlik bir dizi, karakter tabanında çok daha uzun olur. Ama karakter tabanının, özellikle sözlük dışı kelimelerde (out of vocabulary) ve eklerin kritik olduğu yerlerde, yukarıda anlatılan avantajları vardır.

**Soru:** Kelime tabanlı NER'de kelimeleri organizasyon, mekân gibi etiketleyebiliyoruz; karakter tabanlıda her karakter için nasıl bir çıktı veriliyor? **Cevap:** Hoca slayta "Akbank a gittim" yazdı ve altına "bbbbb..." diye etiketleri gösterdi (ekrandan, 00:35:40). Akbank'ın karakterleri banka (organizasyon) etiketi alır, sonraki karakterler O alır.

**Soru:** "Akbank" içindeki "A" harfi bir bankayı tarif ederken "Akbank'a" ekindeki "a" yalnız bir ek; iki "a" harfi farklı şeyleri temsil ediyor. Karakterler tek tek verildiğinde sistem bu farkı nasıl çözebiliyor? **Cevap:** Burada LSTM'ler kullanılıyor. LSTM'ler RNN tipinde mimarilerdir; RNN'ler, LSTM'ler, GRU'lar hafızaya sahiptir. Hafızanın anlamı şudur: karakterler birer birer verilse de daha önce hangi karakterlerin verildiği bilgisi içeride, hafızada durur. Bu yüzden "Akb"den sonra gelen "a" ile "Akbank"tan sonra gelen "a" farklı olarak anlaşılabilir. CNN'de ise hafıza yoktur; daha önce ne gördüğüyle hiç ilgilenmez. Öğrenci bunu n-gram'ların önceki kelimelere bakmasına benzetti; hoca LSTM'lerin çok daha uzununa bakabildiğini, çok önceki bir şeyin bile etkisini tutabildiğini ekledi.

### 3.5 Sonuçlar ve dengesiz sınıflar

Slayttaki sonuçlar (ekrandan, 00:40:00) hiçbir ek bilgi ya da liste kullanılmadan alınmıştır.

3 sınıflı veri kümesi (`NEtrain.txt`): 27563 cümle, yarısı eğitim yarısı test. Sınıflar person, organization ve location; bir de varlık olmayan "O" var. Etiket sayıları:

| Sınıf | Etiket sayısı |
|---|---|
| PERSON | 16291 |
| ORGANIZATION | 9183 |
| LOCATION | 11715 |
| Toplam | 37189 |

Test başarıları: 0,8457, 0,8182, 0,7803; varlık olmayan 0,9852.

7 sınıflı veri kümesi: 24819 cümle eğitim (`Train7.MUClabeled`), 1572 cümle test (`WFS7.MUClabeled`). Person, organization ve location dışında date, percentage, money ve time sınıfları da var; bunların etiketli miktarları çok daha azdır.

| Sınıf | Eğitim | Test |
|---|---|---|
| PERSON | 14693 | 658 |
| ORGANIZATION | 9160 | 410 |
| LOCATION | 9767 | 637 |
| DATE | 1366 | 119 |
| PERCENTAGE | 648 | 62 |
| MONEY | 597 | 41 |
| TIME | 148 | 19 |
| TOPLAM | 36379 | 1946 |

Test başarıları: 0,8693, 0,7810, 0,8458, 0,8214, 0,8889, 0,8049, 1,0000; varlık olmayan 0,9922. Tabloların toplamları python ile doğrulandı.

<!-- BELİRSİZ: Slaytta test başarılarının hangi sınıfa ait olduğu ayrıca yazılmıyor; değerlerin sırası büyük olasılıkla tablolardaki sınıf sırasıdır. -->

> **Ders sonrası not:** Hoca 3 sınıflı kümeyi anlatırken "27 bin cümle, yarısı eğitim yarısı test" dedi, sonra 7 sınıflı kümeye geçerken "24.000 cümle eğitim, 1500 test" dedi. Slayttaki doğru değerler 3 sınıflı için 27563 cümle (yarı yarıya), 7 sınıflı için 24819 eğitim ve 1572 test cümlesidir.

Dikkat edilmesi gereken nokta: "O" etiketlilerin sayısı diğerlerinden çok çok fazladır, çünkü metnin çok büyük kısmı varlık ismi içermez. Hoca bunu sınıf dağılımının dengesizliğine çok güzel bir örnek olarak verdi: person, organization ve location için biner örnek (karakter) varken varlık olmayan için belki yüz bin örnek vardır. Bu durumda bütün sistemin ortalama sınıflandırma başarısına bakmak iyi bir fikir değildir; dengesiz veri kümeleri için F1 skorları çok daha doğru bir yaklaşım gösterir.

> **Ek bilgi (derste anlatılmadı):** F1 skoru, bir sınıf için kesinlik (precision) ve duyarlılığın (recall) harmonik ortalamasıdır: $F_1 = \dfrac{2PR}{P + R}$. Baskın sınıfı her zaman tahmin eden bir sistem yüksek doğruluk (accuracy) alabilir ama azınlık sınıflarında duyarlılığı sıfır olduğu için F1'i düşük çıkar. NER çalışmalarında başarı genelde varlık düzeyinde F1 ile raporlanır.

## 4. Paragraf Anlama

### 4.1 Bir sistemin metni anladığını nasıl anlarız?

İlkokuldan beri "okuduğumuzu anlayalım" türü çalışmalarla karşılaşırız. Bir insanın bir metni anlayıp anlamadığını test etmenin yolu, o metne dair sorular sormaktır; cevap verebilirse anlamıştır. Slayta göre (ekrandan, 00:43:00) bunun klasik örneği üniversite giriş sınavlarındaki paragraf sorularıdır:

- Bu paragrafın ana fikri aşağıdakilerden hangisidir?
- Bu paragraftan aşağıdakilerden hangisi çıkarılabilir / çıkarılamaz?
- Bu parçada anlatımın akışını bozan cümle aşağıdakilerden hangisidir?
- Bu sözleri söyleyen kişi için aşağıdakilerden hangisi söylenemez?
- Bu sözler aşağıdaki sorulardan hangisine karşılık olarak söylenmiş olabilir?

Bunların genel yapısı aynıdır: yukarıda bir paragraf, sonra bir soru, altta şıklar.

### 4.2 Türkçe paragraf veri kümesi ve basit yöntem

Türkçe için oluşturulan veri kümesinde soru türlerinden yalnız biri hedeflendi: en yaygın olan "Aşağıdakilerden hangisi yukarıdaki paragraftan çıkarılabilir / çıkarılamaz?" soruları (ekrandan, 00:50:00). Şıklar yine beş tanedir; yalnız soru türü kısıtlanmıştır.

Bu problem zordur, çünkü zaten insanların anlama kabiliyetini ölçmek için yapılmış bir testtir. Hocaya göre iyi hazırlanmış zekâ sorularını bilgisayarların çözmesi gerçekten çok zordur; bu, bilgisayarların günümüzdeki ve yakın gelecekteki sınırlarındandır.

En basit yöntem hiçbir eğitim yapmadan şudur: soru "çıkarılabilir" ise paragrafa en yakın şık, "çıkarılamaz" ise en uzak şık seçilir. Beş şıktaki metinlerden hangisinin paragraf metnine en yakın olduğu bulunur. Bu biraz naif bir yaklaşımdır. Benzerlik karakter 3-gramlarıyla ölçüldü: paragraf ile her şıkkın karakter 3-gramları bazında ortaklığına bakıldı. Sonuç yaklaşık %35'lik bir başarıdır. Bu kötü değildir, çünkü beş şık olduğu için şans başarısı %20'dir. Hocaya göre kelimelerle bu kadar tutmuyor, karakter 3-gramlarıyla tutuyor.

> **Ders sonrası not:** Hoca şans oranını önce "%20", ardından "%25 tane şık olduğu için" diye söyledi (00:45:58). Beş şıklı soruda rastgele seçimin başarısı $1/5 = \%20$'dir.

Hoca daha karmaşık yöntemler için fikir sordu; sınıftan öneri gelmedi. Kendi notu: bu yaklaşımda bir eğitim kümesi (bu sorunun cevabı şudur bilgisi) kullanılmıyor; bir eğitim süreci kurmak belki mümkün olabilir.

## 5. Soru Cevaplama: Cevap Nerede?

### 5.1 Cevabın yerini bulmak ve doğrudan cevap

Soru cevaplamanın başka bir türü şıklı değildir: amaç, cevabın nerede olduğunu bulmaktır. Elinizde çok büyük bir derlem var ve bir soru soruyorsunuz; o sorunun cevabının derlemde nerede olduğunu bulmak istiyorsunuz. Bu, bir doküman, sayfa, bölüm ya da cümle bulmak olabilir. Bir de cevabı doğrudan bulmak vardır.

Doğrudan cevapta doğruluğu ölçeklenebilir biçimde test etmek zordur. Slayttaki örnek: "İstanbul'u kim fethetti?" sorusuna sistem "7. Osmanlı padişahı" diyor, sizin elinizdeki doğru cevapta "Fatih Sultan Mehmet" yazıyor. Bunlar aslında aynı şeydir; ama düz bakıldığında tamamen farklı görünürler ve aynı olduklarını otomatik anlamak kolay değildir.

Cevap şöyle istenirse durum değişir: bir paragraf ve bir soru var, şık yok; cevap olarak "paragrafın 48. karakterinden 78. karakterine kadar olan kısım" isteniyor. Bu durumda test ölçeklenebilir olur, çünkü sistemin gerçekten 48. ve 78. karakterleri bulup bulmadığı kontrol edilebilir. Aynı cevap metinde birden fazla yerde geçiyorsa birden fazla doğru aralık tanımlanabilir (slaytta "paragraph(48:78 || 89:104)" biçiminde); ama bu tür verileri hazırlamak daha güçtür.

### 5.2 Türkçe "cevap nerede" veri kümesi

Slayttaki bilgiler (ekrandan, 00:51:40):

- `cevap_nerede` adlı, 500'er soruluk 2 veri kümesi.
- Paragraflar hikayedir ve internetten toplanmıştır.
- Her paragraf için çok sayıda (soru, cevabın olduğu cümle) ikilisi vardır; cümlenin numarası değil kendisi verilir.
- Soruların bir kısmı internetten alınmış, bir kısmı elle üretilmiştir.
- Yöntem: soruya en benzeyen cümleyi seç (eğitim yok).
- Şans: 1/ortalama cümle sayısı, yaklaşık %10.
- Karakter 3-gramlarıyla yaklaşık %70 başarı (soru türlerinden dolayı kolay veri kümeleri).

Burada cevabın tam yeri değil, cevabın olduğu cümle isteniyor; örneğin sorunun cevabı paragrafın altıncı cümlesindeyse bulunması gereken altıncı cümledir. Bu, "çıkarılamaz" türü paragraf sorularına göre oldukça basit bir problemdir; soru türleri üniversite sınavı soruları gibi değildir.

### 5.3 SQuAD

Bu tür veri kümelerinin en ünlüsü SQuAD'dır; slayta göre (ekrandan, 00:53:20) SQuAD 2.0:

- Makale (paragraf), soru ve cevabın makalenin neresinde başlayıp bittiği verilir.
- 130 bin eğitim, 9 bin test sorusu vardır.
- Cevaplanamayacak sorular da içerir. SQuAD 1 bunları içermiyordu. Paragraf ve soru vardır ama cevap paragrafta yoktur; sistemin "cevap yok" diyebilmesi gerekir. Bunu derse doğru cevap vermiş olur; paragrafın herhangi bir aralığını gösterirse, neresi olursa olsun, yanlış cevap vermiş olur.
- Derin öğrenme yöntemleriyle tam cevap başarısı yaklaşık %70'tir.

Hoca, SQuAD'ın oldukça popüler ve büyük olduğunu, derin öğrenme yöntemleri için gereken büyük eğitim verisini sağladığını, eğitim kümesinin büyüklüğü arttıkça derin öğrenmeyle iyi sonuçlar elde edildiğini söyledi.

## 6. Bilim Soruları, Açıklamalı Çözümler ve SWAG

### 6.1 Allen AI bilim soruları

Allen AI enstitüsü yapay zekâ ve özellikle metin işleme alanında çok çalışma yapıyor. Bilim soruları (science questions) gerçek sınav sorularıdır; ortaokul ve liselerde sorulan sorulardır (ekrandan, 01:10:00). Üniversite seviyesinde olmadıkları için dört şıklıdırlar. Yalnız sorular ve cevapların ötesinde, bilim kitaplarının metinlerini kullanarak cevabı bulmaya çalışan yaklaşımlar da var. Slayttaki bağlantılar: `data.allenai.org/ai2-science-questions/` ve `data.allenai.org/arc/`.

Daha zor bir soru türü şekil içerir: Güneş, bitkiler, tırtıllar, kurbağalar ve yılanlardan oluşan bir besin zinciri çizimi verilir ve "Bu besin zincirindeki hangi organizmalar diğer bütün organizmaların hayatta kalması için gereklidir?" diye sorulur. Bunu yalnız metne bakarak çözmek mümkün değildir; resmin neyi ifade ettiğini, döngünün ne olduğunu anlamak gerekir. Hoca çözümü sesli kurdu: sinekler (tırtıllar) olmasa kurbağalar aç kalır, kurbağalar olmasa yılanlar aç kalır, bitkiler olmasa hepsi birden ölür; cevap bitkilerdir. Hem metni hem şekli anlamayı gerektiren bu problem oldukça güçtür.

> **Hocanın vurgusu:** Günümüzde bu tür şekilli soruları başarıyla çözebilen bir sistem henüz yok.

### 6.2 Açıklamalı çözümler ve matematik

Bir adım ileride açıklamalı çözümler üretiliyor (ekrandan, 01:12:30). Slayttaki başlıklar "Daha fazla emek, daha az örnek" ve `cognitiveai.org/explanationbank/`. Her örnekte soru, cevap seçenekleri ve doğru cevabı seçmenin mantıksal süreci (explanation) vardır. Eğitim kümesinde açıklamalar bulunur; test zamanında yalnız soru ve seçenekler verilir. Önemli olan, sistemin eğitimde açıklamaları kullanarak iyi bir şeyler öğrenmesi ve bunu test sorularına yansıtabilmesidir.

Benzeri matematik için yapılmıştır: soru, seçenekler ve çözüm açıklaması. Slayta göre 100 bin soru vardır (arXiv:1705.04146); hoca bunun 2017 tarihli bir çalışma olduğunu söyledi. Amaç sistemin sorudan cevaba giderken açıklamadaki bilgileri nasıl kullanacağını öğrenmesidir. Her türlü matematik sorusuna cevap verecek bir sistem tasarlamak hâlâ oldukça güçtür.

### 6.3 SWAG: videolarda bir sonraki olayın tahmini

SWAG'da (ekrandan, 01:14:30; arXiv:1808.05326) sistemden, verilen bir cümlenin dört seçenekten hangisiyle devam etmesinin daha olası olduğunu bulması istenir. Bütün soruların genel yapısı "Bu cümle aşağıdakilerden hangisiyle devam eder?" biçimindedir.

Başlıkta "videolar" geçse de videolar sisteme verilmez. Slaytta da yazdığı gibi ("the videos are never used"), video altyazıları (caption) yalnız veri kümesini, yani "şundan sonra ne olur" sorularını üretmek için kullanılmıştır. Hoca bunun bir ara oldukça popüler bir veri kümesi olduğunu söyledi.

## 7. Basit Hikayelerde Çıkarım ve Memory Networks

### 7.1 Çıkarım, hayat bilgisi ve bAbI veri kümesi

Bu çalışmaların ortak hedefi, soru cevaplamanın anahtar kelime tabanlı değil, çıkarım tabanlı yapılabilmesidir. Çıkarım da hayat bilgisine ve alan (domain) bilgisine bağlıdır; örneğin bilim sorularında suyun yüz derecede kaynadığı gibi pek çok bilgiyi sisteme vermek gerekir. Bir çalışma iki şeyi birden göstermeyi hedefledi: sistemlerin çıkarım yapabildiğini ve bunu hayat bilgisi verilerine ihtiyaç duymadan yapabildiğini. Bu amaçla bir veri kümesi oluşturuldu.

Slayttaki bilgiler (ekrandan, 01:16:20): otomatik üretilmiş (eğitim 3000, test 1000 soru), sözlük boyutu çok küçük, çok basit bir gramer. Eğitim verisine bir örneğin çevirisi:

```text
1 Mary banyoya gitti.
2 Sandra bahçeye gitti.
3 Daniel bahçeye gitti.
4 Daniel ofise gitti.
5 Sandra oradaki sütü aldı.
6 Sandra sütü oraya bıraktı.
7 Süt nerede?      bahçe      6 2
```

Hoca çözümü adım adım kurdu: Sandra oradaki sütü aldı; orası neresi? Sandra bahçeye gitmişti. Sütü bahçede aldı ve oraya bıraktı. O hâlde süt hâlâ bahçededir. Son sütundaki "6 2", cevabı bulmak için yukarıdaki cümlelerden hangi numaralıların kullanıldığını (cevapla ilgili cümlelerin indislerini) gösterir.

> **Ders sonrası not:** Hoca, 5. cümlenin de cevapla ilgili olduğunu, slayttaki indis listesine 5'in de konması gerektiğini belirtti.

Veri kümesinin yapısı: bir hikaye, bir soru, cevabı ve cevabı bulmak için kullanılan cümle numaraları. Sözlük kasıtlı olarak çok küçüktür (hocanın tahminiyle 100 kelime civarı, 50-60 fiil, 50-60 kişi, birkaç yer adı). Amaç, sistemin bilmediği ekstra bir bilgi yüzünden çözememesi değil, eldeki bilgilerin yetmesidir.

Slayttaki İngilizce örnek de aynı yapıdadır: "Joe went to the kitchen. Fred went to the kitchen. Joe picked up the milk. Joe travelled to the office. Joe left the milk. Joe went to the bathroom." Sorular ve cevaplar: "Where is the milk now? A: office", "Where is Joe? A: bathroom", "Where was Joe before the office? A: kitchen".

### 7.2 Yirmi görev

Bu türden 20 görev (task) üretilmiştir: yalnız tek bir cümleye bakarak cevap verilebilen problemler, iki ya da üç cümleye bakmayı gerektirenler, "şununla şunun arasındaki ilişki nedir" soruları, "şuradan şuraya nasıl gidilir" soruları, cevabı evet ya da hayır olan sorular vb. Hepsinde gramer ve sözlük çok basittir ve hepsi çıkarım gerektirir; insanlar için oldukça basit görevlerdir.

Slayttaki görev örnekleri (ekrandan, 01:20:00) şunlardır (her biri için destekleyici cümleler ve modelin her "hop"ta cümlelere verdiği ağırlıklar tabloda gösteriliyor):

- Story 17 (positional reasoning): "The red square is below the red sphere. The red sphere is below the triangle." Soru: "Is the triangle above the red square?" Cevap: yes; tahmin: no.
- Story 18 (size reasoning): "Does the suitcase fit in the chocolate?" Cevap: no; tahmin: no.
- Story 19 (path finding): "How do you go from the kitchen to the bedroom?" Cevap: s,w; tahmin: n,n.
- Story 20 (agent's motivation): "Why did antoine go to the kitchen?" Cevap: thirsty; tahmin: thirsty.

### 7.3 Memory networks

Bu veri kümelerini modellemek için memory networks ortaya atıldı; ayrıntıları sonraki derste anlatılacak. Hoca bunların bir ara çok popüler olan bir Facebook çalışması olduğunu söyledi. Ders sonunda gösterilen slayta göre (ekrandan, 01:50:00; arXiv:1410.3916) memory network bir YSA + memory mimarisidir: hafızaya yalnız yazar ve okur, değiştirmez; $m$ hikayenin tutulduğu hafıza, $x$ soru, $r$ tek kelimelik cevaptır.

Hoca birinci tür problemlerde %96, üçüncü türde %100, beşinci türde %98, yedinci türde %92 gibi yüksek başarılara erişildiğini okudu.

<!-- BELİRSİZ: Hocanın okuduğu %96, %100, %98, %92 değerlerinin hangi slayttan ve hangi modelden olduğu karelerde görülemedi; 01:30:00 karesindeki tablonun değerleriyle örtüşmüyor. -->

Slayttaki "Harika! Sonuçlar MemNN ve MemN2N" tablosunda (ekrandan, 01:30:00) yüzde hata değerleri var. 1k eğitim verisinde ortalama hata LSTM için %51,3 (20 görevin 20'si başarısız, yani hata > %5), güçlü gözetimli MemNN için %6,7 (4 görev başarısız), MemN2N sürümleri için yaklaşık %12-26'dır. 10k eğitim verisinde LSTM'in ortalama hatası %36,4, güçlü gözetimli MemNN'inki %3,2'dir. Hoca standart yaklaşımların hatalarının %30'lar civarında olduğunu söyledi; tabloda LSTM için bu değer 10k veride %36,4, 1k veride %51,3'tür. Bu sonuçlara göre memory networks, LSTM'lerle çözülemeyen görevleri çözebildiklerini iddia ediyordu.

Bu, makinelerin artık çıkarım yapabildiği sonucuna yönlendiriyordu. Hocanın ifadesiyle, makineler çıkarım yapabiliyorsa bu süper bir şeydir: hayat bilgisi veri tabanını onlara uygun biçimde verebilirsek bu sistemlerde bir sıkıntı kalmayacaktır.

## 8. İtiraz: Veri Kümelerindeki Arka Kapılar

### 8.1 İtiraz çalışması

Ardından bir itiraz çalışması geldi (ekrandan, 01:22:00; arXiv:1808.04926). Slayttaki maddeler:

- (metin, soru, cevap) üçlüleri genel yapı.
- 5 veri kümesi üzerinde 3 modelin performansları ölçülmüş.
- Veri kümelerinin orijinal hâlleri, sadece metin kısımları ve sadece soru kısımları kullanılmış. Bazı veri kümelerinde (özellikle "harika sonuçlar" dediğimiz yerlerde) bu eksik hâlleriyle orijinal veri kümesine yakın sonuçlar alınmış.
- Bunun anlamı, bazı veri kümeleri için sistemin sadece metne ya da sadece soruya bakıp cevabı tahmin etmesinin mümkün olduğudur.

Yani test sırasında sisteme metin verilmiş ama soru boş bırakılmış (sıfır padding) ya da metin verilmeden yalnız soru verilmiş. Sistem yine bir cevap üretir; ama normalde bunun doğru olması beklenmez.

**Soru:** Bu neden kötü bir şey? **Cevap:** Bir öğrenci sistemin overfit olduğunu önerdi. Hoca, overfit denemeyeceğini açıkladı: eğitim kümesinde başarı yüksekken test kümesinde düşük olsaydı overfit olurdu; burada test kümesinde de çok başarılı sonuçlar var (yalnız birkaç görevde, örneğin %64 ve %35 gibi düşük başarılar var). Başka bir öğrenci cevapların soru cümlelerinde geçtiğini söyledi; hoca, sistemin tek bir kelimeyi (yer adı, yes/no gibi) tahmin ettiğini belirtip asıl sorunu şöyle açıkladı.

Elinizde, yalnız metindeki bazı ipuçlarından ya da yalnız sorudaki bazı ipuçlarından cevabın çıkarılabildiği bir veri kümesi var. Normalde böyle bir şey olmamalıdır: bir sistem soruyu görmeden neyin cevabını verecek? Modelin öğrenmesini istediğimiz şey metne ve soruya birlikte bakıp cevabı bulmaktır. Ortaya çıkan ise "yalnız metni ver, cevabı versin" ya da "yalnız soruyu ver, cevabı versin" durumudur. Bu, "çok başarılı" denen sonuçlarda da sistemin metinle soruyu birlikte anlayarak cevap üretmediği anlamına gelir.

Bu durumda sistemin yaptığı tamamen bir ezberdir, bir eşlemedir (mapping): metinde şöyle bir şey geçiyorsa cevap şudur, soruda şöyle bir şey geçiyorsa cevap şudur. Metinden ya da sorudan cevaba bir eşleme yapılabiliyorsa, veri kümesi hedeflenen şeyi içermiyor demektir.

Veri kümesini hazırlayanlar bunu bile isteye yapmamıştır, farkında değillerdir. Binlerce metin-soru-cevap üçlüsü makinelerce otomatik olarak üretilmiştir ve ortaya çıkan veri kümesi maalesef böyle sıkıntılar oluşturabilmektedir.

### 8.2 Hikayenin dersi

**Soru:** Bu hikaye bize nasıl bir ders veriyor? **Cevap:** Bir öğrenci bir metne birden fazla soru yazmayı önerdi; hoca bunun sorunu çözmeye yönelik bir öneri olduğunu, kendisinin ise çıkarılacak dersi sorduğunu söyledi. Sınıftan başka cevap gelmeyince kendisi cevapladı.

> **Hocanın vurgusu:** Her gördüğünüz şey sizi ikna etmesin. Bu çalışma vakti zamanında çok popüler olmuş, "artık makineler çıkarım yapabiliyor" yorumlarına yol açmıştı; sonra hepsinin "hikaye" olduğu ortaya çıktı.

Kritik nokta, bunun kötü niyetli kişilerce yapılmış bir aldatma olmamasıdır. Çalışmalar tamamen iyi niyetle, bilimsel çalışma anlamında yapılmıştır. Memory networks'ün oldukça güzel bir mimarisi vardır ve başka alanlarda hâlâ kullanılmaktadır. Sorun, farkında olmadan veri kümelerinin çok kritik olmasıdır.

> **Hocanın vurgusu:** Benchmark olarak oluşturulan veri kümeleri çok önemlidir. Kendi çalışmalarınızda kullanacağınız veri kümelerinin bu tür problemler içerip içermediğini, bir benchmark'ı çözmenin o problemi çözmek için gerekli ve yeterli olup olmadığını anlamak gerekir: o veri kümesinde başarı sağlayan bir şey gerçekten o veri kümesinin problemini çözüyor mu, yoksa bambaşka bir yolla mı çözüyor?

## 9. Entailment Veri Kümelerinde Benzer Problemler

### 9.1 Entailment problemi

Slaytta (ekrandan, 01:32:30) "Entailment veri kümelerinde de benzer problemler" başlığı altında yapı şöyledir: cümle 1, cümle 2 ve üç sınıftan biri. Sınıflar gerektirir, karşıt ve ilgisizdir.

- **Gerektirir (entailment):** Cümle 1 doğruysa cümle 2 kesinlikle doğrudur.
- **Karşıt (contradiction):** Cümle 1 doğruysa cümle 2 yanlıştır.
- **İlgisiz (neutral):** Cümle 1 doğruyken cümle 2 doğru da olabilir yanlış da.

> **Ders sonrası not:** Hoca karşıt sınıfını anlatırken "Cümle 1 doğru iken cümle 2 doğru da olabilir yanlış da olabilir" cümlesini söyledi ve hemen "bu da ilgisiz aslında" diye düzeltti (01:33:05). Doğru ayrım yukarıdaki gibidir: karşıtta cümle 2 kesin yanlış, ilgiside belirsizdir.

Bu problem için çok büyük veri kümeleri oluşturulmuş ve üzerlerinde %80'ler, %90'lar gibi başarılar alınmıştır. Entailment'ı gerçekten iyi çözebilen bir sistem oldukça iyi çalışıyor demektir.

### 9.2 Arka kapı nasıl test edilir?

**Soru:** Bu sistemin bir arka kapı kullanıp kullanmadığını nasıl test edebilirsiniz? **Cevap:** Bir öğrenci mantıksal tutarlılık kontrolü önerdi: cümle 1 ile cümle 2 karşıt, cümle 2 ile cümle 3 de karşıtsa cümle 1 ile cümle 3 arasındaki ilişki de buna uygun olmalıdır; sistem tutarsız bir sınıf veriyorsa sorun vardır. Hoca bunun doğru ve güzel bir yaklaşım olduğunu söyledi, ama önceki örneğe benzer çok daha basit bir yol istedi: sisteme yalnız cümle 1'i (ya da yalnız bir cümleyi) vermek. Yalnız bir cümleye bakarak gerektirir, karşıt ya da ilgisiz olduğunu doğru söyleyebiliyorsa, sistem cümleden sınıfa bir arka kapı kullanıyordur ve istenen işi kesinlikle yapmıyordur.

### 9.3 İnsanların ürettiği verideki ipuçları

Bu veri kümelerinde örnekleri makine değil insanlar üretmiştir. Basit bir örnek: insanların önüne "Parkta oynayan çocuklar var." cümlesi konup "Bu doğruysa kesinlikle doğru olan bir cümle yaz" denir. İnsanlar "Parkta oynayan insanlar var." yazar; ikisi arasında gerektirme ilişkisi vardır. Slaytta da "Parkta oynayan kediler var. / Parkta oynayan hayvanlar var." örneği görünüyor (ekrandan, 01:40:00 karesinin kenar küçük resmi).

Bu cümleleri üretirken insanlar genelde bir şeyleri genelleştirir: çocuk yerine insan, kedi yerine hayvan, otomobil ya da motosiklet yerine araç yazarlar. Böylece "insan", "hayvan", "araç" gibi belli üst kavram kelimeleri (sayıca 15-20 kadar) doğrudan cevabı ele verir. Sisteme yalnız "Parkta oynayan hayvanlar var." verilse bile, içinde "hayvan" geçtiği için "bu kesin gerektirir" diyebilir. İnsanlar bunu da kötü niyetle yapmaz, ama ortaya çıkan durum budur.

Hocanın vurguladığı soru şudur: makineler bir veri kümesinde başarı sağladığında, bunu gerçekten istediğiniz şeyi yaparak mı, yoksa veri kümesinde sizin hiç aklınıza gelmeyen bir arka kapıyı bulup kullanarak mı sağlıyorlar? İleride yapacağınız çalışmalarda gerçekten anlamlı bir şey yapıp yapmadığınızı ölçmek için bu tür testler yapmak iyi olur.

Hoca bu hikayenin bir yönünü daha vurguladı: veri kümesini üreten ve çeşitli mimarilerle çok yüksek başarılar aldıklarını yazan yazarlardan biri itiraz makalesinde de yer alıyor. "İçinde bulunduğum bir grup böyle bir veri kümesi oluşturdu ama bu veri kümesinde bu problemler var" demek, bilimsel dürüstlük açısından çok önemli bir yaklaşımdır. Hocanın hatırladığına göre bu çalışma, bu tür problemleri olmayan bir veri kümesinin nasıl oluşturulacağını da öneriyor, hatta öyle bir veri kümesi yayımlıyor.

> **Ek bilgi (derste anlatılmadı):** Bu konu literatürde "annotation artifacts" (işaretleme artıkları) olarak bilinir. Büyük olasılıkla hocanın kastettiği çalışma, SNLI ve MultiNLI üzerinde yalnız ikinci cümleyle (hypothesis-only) sınıflandırmanın şans düzeyinin çok üstünde başarı verdiğini gösteren 2018 tarihli çalışmalardır; bu çalışmaların yazarları arasında SNLI'yi oluşturan araştırmacılardan biri de vardır. Genelleştirici kelimeler gerektirme, olumsuzluk kelimeleri ise karşıtlık sınıfıyla güçlü biçimde ilişkili bulunmuştur.

## 10. LSTM ile Metin Üretimi

### 10.1 Dil modelinden üretime

Dersin başlarında istatistiksel dil modellerinden bahsedilmişti: klasik dil modelleri belli kelimelerden sonra hangi kelimenin geleceğini tahmin edebilir. Bu, metin üretmenin de anahtarıdır. Hoca slayta yazarak gösterdi (ekrandan, 01:42:30 karesinin kenar küçük resminde "A B C / A B C G / A B C G K" görünür): modele A ve B verilir, "ne dersin?" diye sorulur, C der. Sonra A, B, C verilir, G der. Sonra A, B, C, G verilir, K der. Bir sonraki kelimeyi iyi tahmin edebilmek, metin üretebilmek demektir.

### 10.2 Şiir üretimi

Slayta göre (ekrandan, 01:40:00):

- LSTM ile şiir üretimi; kod `siir_uretimi.m`, veri `tum_siirler.txt`.
- Yaklaşık 4 milyon karakter içeren Türkçe şiirler.
- LSTM bir sonraki karakteri tahmin etmesi için eğitildi (many to many).
- 100'den fazla geçen 84 karakter kullanıldı.
- Her bir giriş 84 boyutlu one-hot vektör, her bir çıkış 84 sınıftan biri.

Yani her karakter bir sınıf gibi düşünülür ve her adımda modelin ürettiği tek bir karakterdir.

> **Ders sonrası not:** Hoca önce "65 tane farklı karakter vardı herhalde" dedi, slaytı görünce 84 karakter olduğunu düzeltti (01:41:13-01:41:31).

Eğitim ayrıntıları (ekrandan, 01:42:30): ilk 200 bin karakter eğitim için kullanıldı (4 milyonun tamamı uzun süreceği için), 512 LSTM hücresi, 500 iterasyon, yaklaşık 2 saat eğitim. Farklı başlangıçlarla üretilen örnek şiirlerden bazı satırlar:

```text
Kaç yolcu bu yolda yürekler
Bir gün karanlığın beni
Görmeyen bir gün kalmadım
Doğmaya bakarsan bir zaman
Saçların kış günük değil kaç yolcu
Yaşamak bir değil
Bir güzel ülküdür gönül verdiğim.
Bahçem yaralı kapılar gibi
Garip gitme kalan y'
```

```text
Ben kimim içimde bir de gör.
Sen bir yana bağrına bakarsak
Bir damla dağların bir çocuk kanıyorum
```

Hoca şiirleri okuyup değerlendirdi. Bunun bir makine mi bir insan mı tarafından yazıldığı anlaşılabilir: bütünlük yoktur. Ama "Çile çoğaltılar güllerinde" ya da "Ben kimim içimde bir de gör" gibi, slaytta kırmızıyla işaretlenmiş, hiç akla gelmeyen güzel ifadeler var. Bu ifadeler 200 bin karakterlik eğitim şiirlerinin içinde geçmiyor. Üretim gramer olarak uygun ve şiire benziyor; model satır atlamayı kendisi yapıyor, ikilikler ve dörtlükler yazıyor.

> **Hocanın vurgusu:** Model çok sayıda şey üretiyor; bunlardan birkaçı iyi göründüğünde makinenin güzel şiir ürettiği algısına kapılmamak lazım. Slayttaki notla: "Falcı 10 şey söyler 1'i tutar, falcı bildi olur."

Hoca öğrencilerin kodu çalıştırabileceğini, 4 milyon karakterin tamamıyla eğitmenin günümüz makinelerinde çok daha kısa süreceğini söyledi.

### 10.3 Haber üretimi

Aynı teknik haber üretimi için de denendi: 500 bin karakterlik spor haberleri, 512 hücre, 30 iterasyon, 2 saat eğitim. Üretilen metinden örnek ifadeler: "gazetecilere yaptığı açıklamada Türkiye Futbol Federasyonu tarafından düzenlenen...", "bu sezon iyi bir takım olarak görevini yaptı", "bu kadar değil, bu kadar değil, bu kadar değil...". Üretilen metinde gerçek bir futbolcu ve teknik direktör adının birleştirildiği komik bir ad da çıkmıştı.

Tekrarlı yapılar dil modellerinde genel bir problemdir. Küçük küçük anlamlı birlikler var, ama bütününe bakıldığında anlamlı bir sonuç yoktur.

**Soru:** Bir şiirin makine tarafından yazılıp yazılmadığını anlamak, spor haberine göre neden daha zor? **Cevap:** Bir öğrenci şiirin sembolik olduğunu, "şair burada ne demek istedi?" diye yoruma açık olduğunu söyledi. Hoca bunu onayladı: "Çile çoğalttılar güllerinde" ya da "soyuna sığamamış" gibi ifadeler yorumla anlamlı hâle gelebilir. Haber metinleri ise yoruma gelmez; problemli kısımlar bariz biçimde ortaya çıkar.

### 10.4 Üretici süreçleri değerlendirmek

Kelime tabanlı üretim de yapılabilir (embedding gerekir); hikaye üretimi, bir hikayeden soru üretimi gibi başka üretim problemleri de var. Ancak üretici süreçleri objektif olarak değerlendirmek oldukça zordur. İki sistem aynı veri kümesinde eğitilip 10'ar şiir üretse, hangisinin daha iyi olduğunu söylemek için elde bir altın standart (golden) yoktur; "iyi şiir budur" diye makineye değerlendirme yaptırılamaz. İş insan değerlendirmesine kalır, bu da problemi ölçeklenebilir olmaktan çıkarır.

Bu yüzden GAN'larda makinenin ürettiği ile gerçek resmi ayırt etmeyi öğrenen bir ağ geliştirilmişti. GAN'lar resimlerde çok yüksek çözünürlüklü, bütünlüklü ve kaliteli üretim yapınca metin üretiminde de kullanılmaları denendi, ama metin üretiminde oldukça başarısız oldular. Hoca, bir mimari başarısız oldu diye alanın hızla ilerlediğini, belki ileride başarılı bir çözümün bulunabileceğini ya da bulunmuş olabileceğini ekledi.

> **Ek bilgi (derste anlatılmadı):** GAN'ların metin üretiminde zorlanmasının bilinen bir nedeni, metnin kesikli (discrete) simgelerden oluşmasıdır: üretecin bir kelime seçmesi türevlenebilir bir işlem değildir, bu yüzden ayırt edicinin gradyanı üretece doğrudan geri yayılamaz. Bu sorunu aşmak için pekiştirmeli öğrenme (ör. SeqGAN) ya da Gumbel-softmax gibi yaklaşımlar denenmiştir.

Sonraki derste memory networks'ün mimarisi (neyi ve nasıl öğrendiği, sorunun cevabını bulmak için nasıl bir süreç izlediği) ve End-to-End Memory Networks gibi gelişmiş sürümleri anlatılacak, ardından sohbet botu uygulamalarına geçilecektir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:22:00): Duygu analizi karşılaştırmasında karakter bazlı evrişimsel ağlar kelime bazlı olanlardan daha iyi çıktı. Bunun temel sebepleri neler olabilir?

> **Çözüm:** (1) Kelime bazlı yaklaşımda her kelimenin vektörü bilinmelidir; sözlük dışı kelimeler temsil edilemez. (2) Türkçede ekler anlam taşır; karakter bazlı yapı, kelimeyi bilmese bile "seviyorum / sevmiyorum" farkını olumsuzluk ekinden yakalar.

**Soru 2** (ekrandan, 00:30:00 kenar küçük resim; derste sözlü, 00:24:57): "Yemeğimi 5 dakikada getirdiniz çok teşekkürler" eğitim kümesinde, "Yemeğimi 55 dakikada getirdiniz çok teşekkürler" test kümesinde ise sistem ikinciyi neden yanlış sınıflandırır, farkı yakalamak için ne gerekir?

> **Çözüm:** İki cümle tek karakterle ayrıldığı için test cümlesine en yakın eğitim örneği olumlu olan ilk cümle çıkar. Farkı yakalamak için yemeğin normalde ne kadar sürede geldiği gibi hayat bilgisi gerekir; bazen metin dışı bağlam (kişinin konumu, önceki paylaşımları) da gerekir.

**Soru 3** (derste sözlü, 00:30:43): Varlık ismi tanıma dışında sekans-to-sekans mimarilere hangi problem türleri örnek verilebilir?

> **Çözüm:** Makine çevirisi (giriş cümle, çıkış başka dildeki cümle), soru cevaplama (cevabın metindeki yerini bulma) ve metin özetleme (giriş metin, çıkış özet).

**Soru 4** (derste sözlü, 00:35:48): Karakter tabanlı LSTM'de "Akbank'a gittim" girdisindeki iki "a" harfinden biri banka adının, öteki ekin parçasıdır. Karakterler tek tek verildiği hâlde model bunları nasıl farklı etiketleyebilir?

> **Çözüm:** LSTM (ve GRU gibi RNN'ler) hafızalıdır; daha önce verilen karakterlerin bilgisi içeride tutulur. Bu yüzden aynı karakter farklı önceki bağlamlarla farklı etiket alabilir. CNN'de böyle bir hafıza yoktur.

**Soru 5** (ekrandan, 01:10:00): "The Sun appears to move across the sky each day, rising in the east and setting in the west. What causes this apparent motion? (A) the rotation of Earth on its axis (B) the revolution of the Sun around Earth (C) the Earth's distance from the Sun (D) the properties of Earth's atmosphere"

> **Çözüm (derste verilmedi):** (A). Güneş'in gökyüzündeki günlük görünür hareketi, Dünya'nın kendi ekseni etrafında dönmesinden kaynaklanır.

**Soru 6** (ekrandan, 01:10:00): Güneş → bitkiler (Plants) → tırtıllar (Caterpillars) → kurbağalar (Frogs) → yılanlar (Snakes) besin zinciri veriliyor. "Which organisms in this food chain are needed for all the other organisms to survive? A caterpillars B frogs C plants D snakes"

> **Çözüm:** (C) plants. Hocanın derste kurduğu akıl yürütme: tırtıllar olmasa kurbağalar, kurbağalar olmasa yılanlar aç kalır; bitkiler olmasa zincirdeki bütün canlılar ölür.

**Soru 7** (ekrandan, 01:12:30): Açıklamalı çözüm örnekleri. (a) "Which of these organisms has cells with cell walls? (A) bluebird (B) A pine tree (C) A ladybug (D) A fox squirrel" (b) "What form of energy causes an ice cube to melt? (A) mechanical (B) magnetic (C) sound (D) heat" (c) "Which of the following events involves a consumer and producer in a food chain? (A) A cat eats a mouse. (B) A deer eats a leaf. (C) A hawk eats a mouse. (D) A snake eats a rat."

> **Çözüm:** Slaytta doğru cevaplar ve açıklamaları verilmiştir. (a) (B) A pine tree: "A pine tree is a kind of plant. A cell wall is a part of a plant cell." (b) (D) heat: "An ice cube is a solid. Changing from a solid to a liquid is called melting. Melting happens when solids are heated. Heated means added heat. Heat is a kind of energy." (c) (B) A deer eats a leaf: "A leaf is a kind of plant. A deer is a kind of animal. In a food chain, an animal is a consumer. In a food chain, green plants are producers."

**Soru 8** (ekrandan, 01:14:30): SWAG örnekleri. (a) "On stage, a woman takes a seat at the piano. She a) sits on a bench as her sister plays with the doll. b) smiles with someone as the music plays. c) is in the crowd, watching the dancers. d) nervously sets her fingers on the keys." (b) "A girl is going across a set of monkey bars. She a) jumps up across the monkey bars. b) struggles onto the monkey bars to grab her head. c) gets to the end and stands on a wooden plank. d) jumps up and does a back flip." (c) "The woman is now blow drying the dog. The dog a) is placed in the kennel next to a woman's feet. b) washes her face with the shampoo. c) walks into frame and walks towards the dog. d) tried to cut her face, so she is trying to do something very close to her face."

> **Çözüm:** Slaytta kalın gösterilen doğru devamlar: (a) d, (b) c, (c) a.

**Soru 9** (ekrandan, 01:16:20): "1 Mary banyoya gitti. 2 Sandra bahçeye gitti. 3 Daniel bahçeye gitti. 4 Daniel ofise gitti. 5 Sandra oradaki sütü aldı. 6 Sandra sütü oraya bıraktı. 7 Süt nerede?" Cevap nedir ve hangi cümleler gerekir?

> **Çözüm:** Bahçe. Sandra bahçeye gitti (2), oradaki sütü aldı (5) ve oraya bıraktı (6); süt bahçededir. Slayttaki indisler 6 ve 2'dir; hoca 5'in de ilgili olduğunu belirtti.

**Soru 10** (ekrandan, 01:16:20): "Joe went to the kitchen. Fred went to the kitchen. Joe picked up the milk. Joe travelled to the office. Joe left the milk. Joe went to the bathroom." Where is the milk now? Where is Joe? Where was Joe before the office?

> **Çözüm:** Slayttaki cevaplar: office, bathroom, kitchen.

**Soru 11** (derste sözlü, 01:23:17): Bir soru cevaplama veri kümesinde yalnız metin ya da yalnız soru verildiğinde de orijinale yakın başarı elde ediliyor. Bu neden kötüdür; overfit midir?

> **Çözüm:** Overfit değildir, çünkü test başarısı da yüksektir. Sorun, sistemin metinle soruyu birlikte anlamadan metinden ya da sorudan cevaba bir eşleme (ezber) yapabilmesidir. Bu, veri kümesinin hedeflenen yeteneği (çıkarım) ölçmediğini gösterir.

**Soru 12** (derste sözlü, 01:33:32): Bir entailment sisteminin arka kapı kullanıp kullanmadığını nasıl test edersiniz?

> **Çözüm:** Sisteme yalnız tek bir cümle vermek: doğru sınıfı yine buluyorsa cümleden sınıfa bir arka kapı kullanıyordur. Ayrıca mantıksal tutarlılık kontrolleri (örneğin karşıtlık zincirlerinde sınıfların tutarlı olup olmadığı) yapılabilir.

**Soru 13** (derste sözlü, 01:46:25): Bir şiirin makine tarafından yazılıp yazılmadığını anlamak, bir spor haberine göre neden daha zordur?

> **Çözüm:** Şiir semboliktir ve yoruma açıktır; tutarsız ifadeler bile anlamlı bir imge gibi okunabilir. Haber metni yorum kaldırmaz, problemli kısımlar bariz görünür.

**Soru 14** (ekrandan, 01:51:30; ödevin akademik problemi): Verilen 3 kelimeden bir cümle üretmek için en az 2 yöntem geliştiriniz. Yöntemleri en az 50 kelime üçlüsü için ürettikleri cümleler üzerinden karşılaştırınız; karşılaştırmada insan yargısı da kullanınız. Örnek giriş: "çocuk inek hava"; örnek çıkış: "hava açınca dışarı çıkan çocuk inek gördü". Eğitim kümesinin nasıl oluşturulacağı ve hangi yöntem ya da mimarilerin kullanılacağı ödevin araştırma sorusudur.

> **Çözüm:** Derste bir çözüm verilmedi; hoca yalnız iki noktayı açıkladı. Karşılaştırma, satırlarda 50 kelime üçlüsü, sütunlarda her sistemin ürettiği cümle olan bir tabloyla yapılır. Üç kelimeyi içeren bir cümleyi büyük bir derlemde arayıp getirmek çözüm değildir; bu bir erişim (retrieval) problemidir, istenen ise üretimdir (generation). Çıktı üç kelimeyi içermeli ve mümkün olduğunca anlamlı olmalıdır.

## Dersin Toparlaması

Bu derste uygulamalar bölümü, metin sınıflandırma ve duygu analizinin kısa bir tekrarından sonra, dili anlama ve üretme problemlerine doğru ilerledi. Kelime vektörü ortalaması, kelime ve karakter bazlı CNN'ler hatırlatıldı; Türkçede eklerin ve sözlük dışı kelimelerin karakter bazlı yapıları neden güçlü kıldığı ve duygu analizindeki ironi örneklerinin neden hayat bilgisi gerektirdiği tartışıldı. Varlık ismi tanıma bir sekans etiketleme problemi olarak ele alındı; klasik CRF yaklaşımı, karakter tabanlı LSTM ile alınan sonuçlar ve dengesiz sınıflarda F1 kullanımı anlatıldı. Paragraf anlama, "cevap nerede" kümeleri, SQuAD, bilim ve matematik soruları ve SWAG ile makinelerin metni ne ölçüde anladığını sınayan veri kümeleri tanıtıldı.

Dersin ana mesajı bAbI ve entailment hikayelerindeydi: yüksek benchmark başarıları, yalnız metin, yalnız soru ya da yalnız tek cümleyle de elde edilebiliyorsa, sistem istenen çıkarımı değil veri kümesindeki bir arka kapıyı öğrenmiştir. Son olarak LSTM ile karakter düzeyinde şiir ve haber üretimi gösterildi ve üretici modellerin değerlendirilmesinin neden zor olduğu tartışıldı. Sonraki derste memory networks'ün mimarisi ve End-to-End Memory Networks anlatılacak, ardından sohbet botu uygulamalarına geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
