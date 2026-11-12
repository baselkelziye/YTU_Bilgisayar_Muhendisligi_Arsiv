# Ders 11 Çalışma Özeti

## Genel Konular

- Duygu durum analizinde ima ve bağlam (önceki dersten devam, 00:11:15)
  - Önceki derste gösterilen "Yemeğimi 55 dakikada getirdiniz çok teşekkürler" gibi iğnelemeli cümleler, öğrencilerin denediği bir sohbet modeline verildiğinde olumlu olarak sınıflandırılmış. <!-- BELİRSİZ: Denenen modelin adı altyazıda anlaşılmıyor ("Abin dedi"). -->
  - Sosyal medya içerikleri düz metinlerden daha zordur. Kirlilik ya da yazım hataları değil kastedilen; kısa mesaj sınırı yüzünden dil oyunu, zekâ oyunu ve dolaylı göndermeler bu ortamda daha yaygındır.
  - Aynı cümle farklı zamanlarda farklı anlama gelebilir. Ülkenin ya da alanın gündemindeki bir konunun varlığı ya da yokluğu bir mesajın anlamını değiştirir. Mesajın içinde görünmeyen birçok gönderme vardır; bu yüzden yalnız metne bakarak anlam çıkarmak çok güçtür.
- Varlık ismi tanıma (NER) (ekrandan, 00:20:00 ve 00:22:00)
  - Tanım: bir metnin içindeki önceden tanımlanmış varlıkları ve türlerini bulmak. Hoca "detection" (bulma) ile "recognition" (bulup türünü söyleme) arasında fark olduğunu, NER'in ikincisini ifade ettiğini söyledi.
  - Slayttaki örnek, ENAMEX biçiminde işaretlenmiş bir metindir: Akbank ORGANIZATION; İstanbul, Ankara, Adana LOCATION; Tania Maria PERSON.
  - Sekanstan sekansa (seq2seq) mimariler kullanılır. Klasik yaklaşım CRF'dir (Conditional Random Fields): derin öğrenme öncesinden gelen, başarılı ama özellik mühendisliği (feature engineering) gerektiren bir yöntem. Derin öğrenme tabanlı yaklaşımın en büyük avantajı bu özellik mühendisliğine takılmamasıdır.
  - Derste anlatılan yaklaşım: karakter tabanlı LSTM. Giriş karakterlerin one-hot vektörleri, çıkış her karakterin sınıfıdır. Varlık türlerinin yanında "hiçbiri" sınıfı da vardır; en çok elemanı olan sınıf odur.
  - NER problemlerinin karakteristik özelliği sınıf dengesizliğidir: sınıfların örnek sayıları birbirine hiç yakın değildir.
  - Sonuçlar (ekrandan, 00:22:00, ek bilgi ya da liste kullanılmadan):
    - 3 sınıflı veri kümesi (NEtrain.txt): 27563 cümle, yarısı eğitim yarısı test. Etiket sayıları PERSON 16291, ORGANIZATION 9183, LOCATION 11715, toplam 37189. Test başarıları 0.8457, 0.8182, 0.7803; varlık olmayan 0.9852. Hocaya göre bu, aslında 4 sınıflı bir problemdir.
    - 7 sınıflı veri kümesi: 24819 cümle eğitim, 1572 cümle test. Sınıflar PERSON, ORGANIZATION, LOCATION, DATE, PERCENTAGE, MONEY, TIME (eğitimde toplam 36379, testte 1946 etiket). Test başarıları 0.8693, 0.7810, 0.8458, 0.8214, 0.8889, 0.8049, 1.0000; varlık olmayan 0.9922. Bu da aslında 8 sınıflı bir problemdir.
  - Karakter düzeyinde son işlem (post-processing): bir kelimenin içinde dört LOCATION, bir ORGANIZATION, sonra yine dört LOCATION çıkması makul değildir. Çıkışlar makul kurallarla düzeltilebilir.
  - Kural tabanlı ekler: örneğin büyük harfle başlayan kelimelerden sonra "A.Ş." geliyorsa hepsini kurum say. Bu tür kurallar eğitim kümesi az olduğunda çok işe yarar; yeterli eğitim verisi varsa kurallar olmadan da başarılı sonuçlar alınır.
- Paragraf anlama (ekrandan, 00:28:50 ve 00:30:00)
  - Bir sistemin metni anladığını, insanlarda olduğu gibi metne ait soruları cevaplayıp cevaplayamadığına bakarak anlarız.
  - Üniversite giriş sınavlarındaki paragraf soru tipleri: ana fikir; hangisi çıkarılabilir / çıkarılamaz; anlatımın akışını bozan cümle; sözleri söyleyen kişi için hangisi söylenemez; sözler hangi soruya karşılık söylenmiş olabilir.
  - Türkçe veri kümesi: uni_paragraf, YTÜ Bilgisayar Mühendisliği öğrencileriyle toplanmış, 500'er soruluk 3 veri kümesi.
  - Yöntem: en yaygın soru türü (çıkarılabilir / çıkarılamaz vb.) hedeflendi. Olumlu sorularda paragrafa en yakın, olumsuz sorularda en uzak şık seçildi; eğitim yok. Temsil olarak karakter 3-gramlarının TF vektörleri ve kosinüs benzerliği kullanıldı.
  - Sonuç: şans %20 (5 şık), karakter 3-gramlarıyla yaklaşık %35. Hoca bu basit yöntemin, tek bir kelimenin eş anlamlısını yazmak gibi küçük bir değişiklikle çökeceğini söyledi. Görev çok zordur.
- Soru cevaplama (ekrandan, 00:40:00 ve 00:40:50)
  - Cevabın nerede olduğunu bulmak (hangi paragraf ya da cümle) ile cevabın tam ne olduğunu bulmak iki ayrı iştir.
  - Değerlendirme zordur: "Yedinci Osmanlı padişahı", "Fatih Sultan Mehmet" ve "İstanbul'u fetheden Osmanlı padişahı" aynı kişiyi anlatır. Beklenen cevap biriyken sistem diğerini verirse bunu yanlış saymamak için eşdeğerliği otomatik değerlendiren bir sistem gerekir. Bağlam (bir kitap gibi) büyüdükçe değerlendirme ölçeklenemez hale gelir. <!-- BELİRSİZ: Altyazıda "Başsultan Mehmet" geçiyor; büyük olasılıkla "Fatih Sultan Mehmet". -->
  - Türkçe "cevap nerede" veri kümesi: 500'er soruluk 2 veri kümesi; paragraflar internetten toplanmış hikâyeler; her paragraf için çok sayıda "soru, cevabın olduğu cümle" ikilisi; soruların bir kısmı internetten, bir kısmı elle üretilmiş. Yöntem: soruya en benzeyen cümleyi seç (eğitim yok). Şans 1/ortalama cümle sayısı, yaklaşık %10; karakter 3-gramlarıyla yaklaşık %70.
  - Hocaya göre %70, soruların bu yönteme uygun olmasından gelir: soru ile cevap cümlesindeki kelimeler birbirine çok benzer. Karakter 3-gramlarının başarılı olduğu bir veri kümesi basit bir veri kümesidir; cümlelerin parafrazları yazılırsa başarı çok düşer.
  - SQuAD (Stanford Question Answering Dataset): makale, soru ve cevabın makalenin neresinde başlayıp bittiği; 130 bin eğitim, 9 bin test sorusu. İlk sürümde her sorunun cevabı paragrafta vardı; SQuAD 2.0 cevaplanamayacak soruları da içerir. Derin öğrenme yöntemleriyle tam eşleşme (exact match) başarısı yaklaşık %70.
- Başka soru cevaplama veri kümeleri (ekrandan, 00:55:50, 00:58:10, 01:00:00)
  - Bilim soruları (Allen AI, ARC): gerçek sınav soruları. Besin zinciri sorusu gibi bazılarını cevaplamak için şekli algılamak gerekir; şekil değişirse cevap da değişir.
  - Açıklamalı çözümler: soru ve şıkların yanında cevaba nasıl ulaşıldığını anlatan bir açıklama (explanation, reasoning) kısmı vardır. Hazırlaması daha zordur.
  - Matematik: açıklamalı çözümler, 100 bin soru (arXiv:1705.04146). Bu tür veri kümelerinin büyük ölçekte üretilmesi insan emeğine, dolayısıyla paraya bağlıdır.
  - SWAG (arXiv:1808.05326, 2018): video altyazılarından üretilmiş "sonraki olay ne olur" soruları. Yanlış şıklar rastgele üretilirse soru çok kolaylaşır; bu yüzden şıklar özel bir mekanizmayla (çekişmeli seçim) üretilmiş. Yine de BERT yayımlandıktan sonra bu veri kümesinde %80'in üzerinde başarıya ulaştı.
- Çok basit hikâyelerde çıkarım: bAbI (ekrandan, 01:03:00)
  - Otomatik üretilmiş veri: eğitim 3000, test 1000 soru; sözlük çok küçük (yüz küsur kelime), gramer çok basit.
  - Örnek (Türkçe çeviri): 1 Mary banyoya gitti. 2 Sandra bahçeye gitti. 3 Daniel bahçeye gitti. 4 Daniel ofise gitti. 5 Sandra oradaki sütü aldı. 6 Sandra sütü oraya bıraktı. 7 Süt nerede? Cevap: bahçe; cevapla ilgili cümlelerin indisleri 6 ve 2.
- Memory Networks (arXiv:1410.3916, 2014) (ekrandan, 01:10:00 ve 01:12:30)
  - Yapay sinir ağı artı harici bir bellek. Belleğe yalnız yazılır ve okunur, değiştirme yoktur.
  - $m$: hikâyenin tutulduğu bellek; $m_{o_1}$, $m_{o_2}$: cevabı üretecek bellek parçaları; $x$: soru; $r$: tek kelimelik cevap.
  - $o_1 = \arg\max_{i=1..N} s_O(x, m_i)$; $o_2 = \arg\max_{i=1..N} s_O([x, m_{o_1}], m_i)$; $r = \arg\max_{w \in W} s_R([x, m_{o_1}, m_{o_2}], w)$.
  - Benzerlik: $s(x, y) = \Phi_x(x)^T U^T U \Phi_y(y)$. $\Phi$ bir metni $D$ boyutlu kelime torbası (BoW) gösterimine çevirir. $s_O$ ve $s_R$'nin $U$ matrisleri farklıdır; eğitimde öğrenilen yalnız bu $U$ matrisleridir.
  - Kayıp fonksiyonu, doğru bellek parçalarına ve doğru cevaba benzerliği arttırıp diğer bütün seçeneklere benzerliği azaltan, $\gamma$ paylı bir hinge kaybıdır.
  - Eksik: eğitim verisinde cevapla ilgili cümlelerin (örnekte 6 ve 2) işaretlenmesi gerekir.
- End-to-End Memory Networks (arXiv:1503.08895, 2015) (ekrandan, 01:16:50, 01:20:00, 01:30:00)
  - Cevapla ilişkili cümlelerin işaretlenmesi gerekliliğini ortadan kaldırır.
  - $p_i = \mathrm{Softmax}(u^T m_i)$: $m_i$ bellek slotları (A matrisiyle gömülmüş cümleler), $u$ sorunun gömmesi (B matrisi), $p_i$ slotların soruyla ilişkili olma olasılıkları.
  - $o = \sum_i p_i c_i$ ($c_i$: aynı cümlelerin C matrisiyle elde edilen ikinci temsili), $\hat{a} = \mathrm{Softmax}(W(o + u))$. Eğitimde A, B, C, W matrisleri öğrenilir.
  - Katı (arg max) seçim yerine bütün bellek, ağırlıklarla birlikte işe katılır; hoca bunu Transformer'daki dikkat mekanizmasına benzetti. Burada soru ile cümleler arasında bir çapraz dikkat (cross-attention) vardır; A ve C temsilleri, Transformer'daki key/value gibi aynı şeyin farklı temsilleridir.
  - Çok adımlı (multi-hop) yapı: üç adımda her adımın kendi A ve C matrisleri vardır ($A^1, C^1, A^2, C^2, A^3, C^3$). Adım sayısı mimaride önceden belirlenir. Üç adımlı bir mimari tek adım gerektiren soruları da çözebilir.
  - Konum gömmeleri (position embeddings): BoW gösterimi kelime sırasını önemsemez. Çözüm $m_i = \sum_j l_j \cdot A x_{ij}$ (eleman bazlı çarpım), $l_{kj} = (1 - j/J) - (k/d)(1 - 2j/J)$. Yakın konumdaki kelimeler benzer, uzak konumdakiler farklı vektörlerle çarpılır.
  - bAbI'deki 20 görevde (tek destekleyici bilgi, üç destekleyici bilgi, evet/hayır, yol bulma vb.) hücre ısı haritaları her adımdaki $p$ değerlerini gösterir. Sonuçlar LSTM ve Memory Networks gibi temel yöntemlere göre iyidir; cümle işaretlemesi olmadan da iş yapılabildiği görülür.
- İtiraz: kısa yol öğrenme (arXiv:1808.04926) (ekrandan, 02:00:00 ve 02:08:40)
  - 5 veri kümesi üzerinde 3 modelin performansı, veri kümelerinin orijinal hali, yalnız metin (passage only) ve yalnız soru (question only) halleriyle ölçülmüş.
  - Bazı veri kümelerinde eksik hallerle orijinale yakın sonuçlar alınmış; yani sistem yalnız metne ya da yalnız soruya bakıp cevabı tahmin edebiliyor.
  - bAbI görevlerinden örnekler: görev 1'de orijinal %100, yalnız soru %18, yalnız metin %53 (iyi bir görev); görev 13'te orijinal %94, yalnız metin de yaklaşık %94 (başarının anlamı yok); görev 3'te orijinal %39, yalnız soru %22, yalnız metin %60 (kötü kurulmuş bir görev).
  - Hocaya göre bu, veri kümesinin doğru kurulmadığını gösterir: model, istenen ilişkiyi değil veri kümesindeki kısa yolları (shortcut) öğrenir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Makine öğrenmesine "nasıl"ı söyleyemeyiz
  - Makine öğrenmesini girdiden çıktıya geçişi algoritma olarak yazamadığımız problemlerde kullanırız. Modele ne yapacağını söyleriz ama nasıl yapacağını söyleyemeyiz; model de istemediğimiz yollardan problemi çözebilir. Bu anormal değildir ama bunun farkında olmak gerekir.
- Tank örneği
  - Düşman ve dost tankları ayırmak için eğitilen bir model test kümesinde %90'ın üzerinde başarılıyken sahada çok kötü çalışmış. Dost tankların fotoğrafları açık havada, düşmanınkiler kapalı havada çekildiği için model aslında havanın açık mı kapalı mı olduğunu öğrenmiş.
- İyi veri kümesi nasıl olmalı
  - Aynı metin için farklı cevaplı farklı sorular, aynı soru için farklı cevaplı farklı metinler olmalıdır. Alakasız bir ipucuyla eşleme yapma ihtimali varsa model büyük olasılıkla bunu yakalar.
- Her kısa yol zararlı değildir
  - Bazı kısa yollar bizim fark etmediğimiz ama gerçekten işe yarayan ilişkilerdir ve problemi anlamamıza katkı sağlar. Bazıları ise yalnız eşlemeye yarar, problemin gerçek çözümüne katkı sağlamaz.
- Basit veri kümesi uyarısı
  - Karakter 3-gramları gibi çok basit bir yöntem bir veri kümesinde yüksek başarı alıyorsa, o veri kümesi basittir ve parafrazlarla başarı kolayca düşürülebilir.
- Benzerlik hesaplamayı küçümsememek
  - Memory Networks'ün yaptığı temelde benzerlik hesaplamaktır; buna ne kadar "çıkarım" denebileceği tartışmalıdır. Yine de bugün her şey sonraki token tahmini gibi basit bir işlemden türüyorsa, benzerlik bulma da küçümsenecek bir mekanizma değildir.
- Konum gömmelerinin kökeni
  - Konum gömmeleri 2015'te End-to-End Memory Networks ile görülmeye başlanmış ve günümüze yansımış bir yaklaşımdır. Toplama ve çarpma yer değiştirebilen işlemler olduğu için kelime sırası bilgisi ayrıca eklenmelidir.

## Kısa Tekrar Notları

- Sosyal medyada ima, dil oyunu ve gündem bağlamı anlamı değiştirir; duygu analizini zorlaştırır.
- NER = varlıkları bulma + türlerini söyleme. Klasik: CRF (özellik mühendisliği). Derste: karakter tabanlı LSTM, girişte karakter one-hot, çıkışta karakter sınıfı.
- NER'de "hiçbiri" sınıfı en kalabalık sınıftır; sınıf dengesizliği tipiktir.
- 3 sınıflı NER aslında 4, 7 sınıflı NER aslında 8 sınıflıdır.
- Karakter düzeyinde çıktılar son işlemle ve kurallarla (örneğin "A.Ş.") düzeltilebilir; kurallar az veride çok işe yarar.
- Paragraf anlama (uni_paragraf): 5 şıkta şans %20, karakter 3-gram + kosinüs ile yaklaşık %35.
- Cevap nerede (Türkçe): şans yaklaşık %10, karakter 3-gram ile yaklaşık %70; veri kümesi basit.
- SQuAD: 130 bin eğitim, 9 bin test; SQuAD 2.0 cevaplanamayan soruları da içerir; tam eşleşme yaklaşık %70.
- Soru cevaplamada değerlendirme zordur: aynı cevabın farklı yazımları doğru sayılmalı.
- SWAG: çekişmeli üretilmiş yanlış şıklar; BERT kısa sürede %80'in üzerine çıktı.
- bAbI: otomatik üretilmiş, küçük sözlüklü, 20 görevli çıkarım veri kümesi.
- Memory Networks: arg max ile katı seçim, $s(x,y) = \Phi_x(x)^T U^T U \Phi_y(y)$, destekleyici cümleler eğitimde işaretli olmalı.
- End-to-End Memory Networks: $p_i = \mathrm{Softmax}(u^T m_i)$, $o = \sum_i p_i c_i$, $\hat{a} = \mathrm{Softmax}(W(o+u))$; yumuşak seçim, dikkat mekanizmasına benzer; çok adımlı; konum gömmeleri.
- Yalnız metin ya da yalnız soru ile yüksek başarı, veri kümesinde kısa yol olduğunu gösterir (shortcut learning).

## Detaylı Açıklamalar

- Karakter tabanlı NER nasıl kodlanır?
  - Metnin her karakteri bir one-hot vektördür; çıkışta her karaktere bir sınıf atanır. "Akbank" kelimesinin bütün karakterlerine ORGANIZATION, "8." ve "Caz" gibi varlık olmayan kısımların karakterlerine "hiçbiri" denmesi beklenir. Giriş ve çıkış uzunluğu eşittir. Çıkış karakter karakter verildiği için bir kelimenin ortasında sınıf değişmesi gibi tutarsızlıklar oluşabilir; bunlar kelime düzeyinde bir son işlemle kolayca düzeltilir. Sınıfların başarısı örnek sayısına ve diğer sınıflardan ne kadar ayrık olduğuna bağlıdır; "hiçbiri" sınıfının başarısı bu yüzden çok yüksektir.
- Eğitimsiz benzerlik yöntemleri neden bir taban çizgisidir?
  - Paragraf anlama ve "cevap nerede" deneylerinde hiç eğitim yoktur: soru ile şıklar ya da cümleler karakter 3-gram TF vektörlerine çevrilir, kosinüs benzerliği alınır. Bu yöntem yalnız ortak karakter üçlülerine bakar, anlamsal benzerliği doğrudan kurmaz. Şansın üstünde çıkan başarı, veri kümesinde yüzeysel benzerliğin cevabı ne kadar ele verdiğini gösterir. Başarı çok yüksekse veri kümesi basittir; aynı cümleler parafraz edilirse yöntem çöker.
- Memory Networks'ün iki adımlı çıkarımı
  - "Süt nerede?" sorusunda önce soruya en benzeyen cümle bulunur: "Sandra sütü oraya bıraktı" (6). Sonra soru ile bu cümle birleştirilir ve bu birleşime en benzeyen cümle aranır: "Sandra bahçeye gitti" (2). Son adımda soru ve iki cümlenin birleşimine sözlükteki en yakın kelime cevap olarak seçilir: "bahçe". Seçimler arg max ile katı (ayrık) yapılır. Eğitimde $U$ matrisleri, doğru cümleyi (6, sonra 2) ve doğru cevabı diğer bütün seçeneklerden en az $\gamma$ payıyla daha benzer yapacak şekilde öğrenilir; bunun için doğru cümlelerin eğitim verisinde verilmesi gerekir.
- End-to-End Memory Networks'te yumuşak seçim
  - Soru gömmesi $u$ ile her bellek slotu $m_i$ arasındaki iç çarpım bir benzerlik skorudur. Softmax bunları olasılıklara çevirir. Çıkış vektörü $o$, aynı cümlelerin C ile alınmış temsillerinin bu olasılıklarla ağırlıklı toplamıdır. Örneğin 5. cümle çok benziyorsa ve diğerleri hiç benzemiyorsa $o$ yalnız 5. cümleden etkilenir; olasılık 1. ve 4. cümle arasında %50-%50 bölünmüşse $o$ ikisinin temsillerinin ağırlıklı toplamı olur. Bütün işlem türevlenebilir olduğu için hangi cümlenin seçileceği dışarıdan söylenmeden uçtan uca eğitilebilir.
- Konum gömmeleri
  - BoW gösteriminde cümle gömmesi kelime gömmelerinin toplamı olduğundan kelime sırası kaybolur. $l_{kj} = (1 - j/J) - (k/d)(1 - 2j/J)$ formülünde $j$ kelimenin cümledeki sırası, $J$ cümle uzunluğu, $k$ gömme boyutunun indisi, $d$ gömme boyutudur. Slayttaki $d = 128$, $J = 25$ için $L$ matrisinin her sütunu bir konuma karşılık gelir; komşu konumların sütunları birbirine benzer, uzak konumlarınki farklıdır. Böylece aynı kelimenin cümle başında ve sonunda farklı etkisi olur.
- Kısa yol öğrenme deneyinin yorumu
  - Eğitimde (metin, soru, cevap) üçlüleri kullanılır; sorun eğitimde değil, testtedir. Testte metin çıkarılıp yalnız soru verildiğinde ya da soru çıkarılıp yalnız metin verildiğinde model hâlâ doğru cevap veriyorsa, cevabı metin ile soruyu birlikte kullanarak değil, birinin içindeki bir ipucundan (örneğin "metinde kedi geçiyorsa cevap şudur") üretiyordur. Bu ezberleme (overfitting) değildir, çünkü test başarısı yüksektir; veri kümesinin bu kısa yollara izin verecek şekilde kurulmuş olmasından kaynaklanır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
