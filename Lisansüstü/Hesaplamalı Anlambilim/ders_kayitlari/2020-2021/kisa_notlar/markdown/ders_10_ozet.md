# Ders 10 Çalışma Özeti

## Genel Konular

- Metin sınıflandırma ve duygu durum analizi (tekrar)
  - Uygulamalar slaytına önceki derste kalınan yerden dönüldü. Metin sınıflandırma LSI ile ya da TF-IDF ve n-gram temsilleriyle yapılabilir; eğitim örneği sayısı arttıkça başarı artar.
  - Duygu durum analizinde karşılaştırılan temsiller: kelime torbası (bag of words, her kelime bir özellik), karakter 3-gram torbası (sözlük ardışık üç karakterden oluşur), kelime vektörü ortalamaları, kelime bazlı LSTM, kelime bazlı CNN ve karakter bazlı CNN.
  - Kelime vektörü ortalaması: metindeki kelimelerin word2vec ya da fastText vektörlerinin her boyutta ortalaması alınır. Böylece farklı uzunluktaki metinler aynı uzunlukta bir vektörle temsil edilir ve metnin genel konusu yakalanır. Sakıncası: metinde birbirinden çok uzak kelimeler varsa ortalama hiçbirine yakın olmayan bir noktaya düşer.
  - Kelime bazlı CNN (ekrandan, 00:20:00): metin, her satırı bir kelime vektörü olan bir M matrisine (resme) dönüştürülür. Kısa metinlerin kalan satırları 0 ile doldurulur (padding); CNN eşit boyutlu girdi ister, LSTM'e ise kelimeler tek tek verildiği için padding gerekmez. M üzerinde $k_m \times d_m$'lik filtreler gezdirilir, sonuçlar F'de tutulur, her sütunun maksimumu B vektörüne yazılır, B ile çıkış S arasında tam bağlı katman vardır.
  - Karakter bazlı CNN'de karakterler one-hot kodlanır (karakterler arasında anlamsal benzerlik anlamlı olmadığı için). Matrisin satır sayısı karakter sayısıdır; örneğin 80 farklı karakter varsa $3 \times 80$'lik filtreler gezdirilir.
- Karakter bazlı yapılar neden daha iyi çalıştı?
  - Sözlük dışı kelime sorunu yoktur: kelime bazlı yaklaşımda vektörü bilinmeyen kelime temsil edilemez.
  - Türkçede ekler (olumsuzluk "-me/-ma" gibi) anlam taşır. Karakter bazlı yapı, kelimeyi hiç bilmese bile "seviyorum / sevmiyorum" farkını eklerden yakalayabilir.
- Duygu durum analizi neden zordur?
  - "Yemeğimi 5 dakikada getirdiniz çok teşekkürler" ile "Yemeğimi 55 dakikada getirdiniz çok teşekkürler" arasında tek karakter fark var ama ikincisi alaydır; "2500 TL'lik fatura için çok teşekkürler" de öyle. Eğitimde birini, testte ötekini gören sistem ikisini çok yakın bulur.
  - Farkı yakalamak için hayat bilgisi (dünya bilgisi) veri tabanları gerekir. Üstelik aynı cümle bağlama göre farklı yorumlanabilir (dağ başında 55 dakika iyi bir süre olabilir, faturası her ay 5000 gelen biri için 2500 sevindiricidir); bağlam bazen metnin dışındadır (kişinin önceki tweet'leri, konumu).
  - Hocaya göre örneklerin kabaca %20'lik bir kısmı gerçekten zordur.
- Varlık ismi tanıma (NER) (ekrandan, 00:28:40)
  - Tanım: bir metnin içindeki önceden tanımlanmış varlıkları ve türlerini bulmak. Slayttaki örnekte AKBANK ORGANIZATION; İstanbul, Ankara, Adana LOCATION; Tania Maria PERSON olarak işaretlenmiş.
  - Sekans-to-sekans (seq2seq) bir problemdir: giriş bir dizi, çıkış da bir dizidir. Girdi $w_1 \dots w_5$ için çıkış "O İ İ O O" gibi her kelimeye bir etikettir (O: varlık değil) (ekrandan, 00:35:40). Başka seq2seq örnekleri: makine çevirisi, soru cevaplama (cevabın metindeki yerini bulma), metin özetleme.
  - Özetleme iki türlüdür: çıkarımlı (extractive) özetleme metindeki önemli cümleleri seçer, daha kolaydır; soyutlayıcı (abstractive) özetleme yeni cümleler kurar, gerçek özet budur.
  - Klasik yaklaşım CRF'dir (Conditional Random Fields). Hocaya göre derin öğrenme NER alanında CRF'leri ortadan kaldıramadı; CRF'ler derin ağların içinde bir katman olarak hâlâ kullanılıyor.
  - Derste karakter tabanlı LSTM kullanıldı: giriş karakter one-hot vektörleri, çıkış her karakterin sınıfı. "Akbank'a gittim" girdisinde "Akbank" karakterleri banka (organizasyon) etiketi, kalanlar O alır. Sekans uzar ama karakter tabanının avantajları korunur.
  - Aynı "a" harfinin bir yerde varlığın, bir yerde ekin parçası olmasını LSTM'in hafızası ayırır: LSTM ve GRU gibi RNN mimarileri daha önce gördükleri karakterlerin bilgisini içeride tutar; CNN'de böyle bir hafıza yoktur.
  - Sonuçlar (ekrandan, 00:40:00), hiçbir ek bilgi ya da liste kullanılmadan: 3 sınıflı veri kümesi (NEtrain.txt, 27563 cümle, yarısı eğitim yarısı test) test başarıları 0,8457, 0,8182, 0,7803, varlık olmayan 0,9852. 7 sınıflı veri kümesi (24819 cümle eğitim, 1572 cümle test; PERSON, ORGANIZATION, LOCATION, DATE, PERCENTAGE, MONEY, TIME) test başarıları 0,8693, 0,7810, 0,8458, 0,8214, 0,8889, 0,8049, 1,0000, varlık olmayan 0,9922.
  - "O" etiketi diğerlerinden çok daha fazladır, yani sınıf dağılımı dengesizdir. Bu durumda genel ortalama başarı yanıltıcıdır, F1 skoru kullanılır.
- Paragraf anlama (ekrandan, 00:43:00)
  - Bir sistemin metni anladığını, metne ait soruları cevaplayabilmesinden anlarız. Üniversite giriş sınavındaki paragraf soruları örnektir (ana fikir, çıkarılabilir/çıkarılamaz, akışı bozan cümle vb.).
  - Türkçe veri kümesinde yalnız en yaygın tür olan "Bu paragraftan aşağıdakilerden hangisi çıkarılabilir / çıkarılamaz?" soruları vardır, beş şıklıdır.
  - Eğitimsiz basit yöntem: "çıkarılabilir" sorusunda paragrafa en yakın, "çıkarılamaz" sorusunda en uzak şık seçilir. Benzerlik karakter 3-gramlarıyla ölçüldü; başarı yaklaşık %35, şans %20.
- Soru cevaplama: cevap nerede?
  - Büyük bir derlemde cevabın geçtiği doküman, sayfa, bölüm ya da cümleyi bulmak ya da cevabı doğrudan vermek. Doğrudan cevapta doğruluğu ölçeklenebilir biçimde test etmek zordur: "İstanbul'u kim fethetti?" sorusuna "7. Osmanlı padişahı" cevabı ile beklenen "Fatih Sultan Mehmet" aynıdır ama düz karşılaştırmada farklı görünür.
  - Cevap paragrafın karakter aralığı (örneğin 48. ile 78. karakter arası) olarak istenirse test ölçeklenebilir olur.
  - Türkçe "cevap nerede" veri kümesi (ekrandan, 00:51:40): 500'er soruluk 2 küme, paragraflar hikaye, her paragraf için çok sayıda (soru, cevabın olduğu cümle) ikilisi. Yöntem: soruya en benzeyen cümleyi seç (eğitim yok). Şans 1/ortalama cümle sayısı, yaklaşık %10; karakter 3-gramlarıyla yaklaşık %70 başarı (soru türleri kolay olduğu için).
  - İngilizce: SQuAD 2.0 (ekrandan, 00:53:20). Makale, soru ve cevabın makalede başlayıp bittiği yer; 130 bin eğitim, 9 bin test sorusu; cevaplanamayacak sorular da var (sistem "cevap yok" demeli). Derin öğrenmeyle tam cevap başarısı yaklaşık %70.
- Bilim soruları, açıklamalı çözümler, matematik ve SWAG
  - Allen AI'ın bilim soruları gerçek ortaokul ve lise sınav sorularıdır (ekrandan, 01:10:00). Besin zinciri sorusu gibi şekilli sorular hem metni hem şekli anlamayı gerektirir; hocaya göre bunları başarıyla çözen bir sistem henüz yoktur.
  - Açıklamalı çözümler (ekrandan, 01:12:30): eğitim kümesinde soru, şıklar ve doğru cevabın açıklaması var; testte açıklama yok. Sistemin eğitimde açıklamalardan yararlanması amaçlanır ("daha fazla emek, daha az örnek"). Benzeri matematik için yapılmış: 100 bin soru, şıklar ve çözüm açıklaması.
  - SWAG (ekrandan, 01:14:30): bir cümlenin dört seçenekten hangisiyle devam edeceğini tahmin etmek. Videolar sisteme verilmez; yalnız soruları üretmek için video altyazıları (caption) kullanılmıştır.
- Basit hikayelerde çıkarım (bAbI) ve memory networks
  - Amaç: soru cevaplamanın anahtar kelimeye değil çıkarıma dayandığını, hayat bilgisine ihtiyaç duymadan göstermek. Otomatik üretilmiş veri (eğitim 3000, test 1000 soru), çok küçük sözlük, çok basit gramer (ekrandan, 01:16:20).
  - Örnek: 1 Mary banyoya gitti. 2 Sandra bahçeye gitti. 3 Daniel bahçeye gitti. 4 Daniel ofise gitti. 5 Sandra oradaki sütü aldı. 6 Sandra sütü oraya bıraktı. 7 Süt nerede? Cevap: bahçe; cevapla ilgili cümlelerin indisleri 6 ve 2. Hoca 5. cümlenin de ilgili olduğunu belirtti.
  - 20 ayrı görev var (tek destekleyici cümle, iki/üç destekleyici cümle, ilişkiler, yol bulma, evet/hayır soruları vb.). Bu veriler için memory networks önerildi ve çok düşük hatalar elde edildi (ayrıntıları sonraki derste anlatılacak).
- İtiraz: veri kümesindeki arka kapılar (ekrandan, 01:22:00)
  - Bir sonraki çalışma 5 veri kümesinde 3 modeli, veri kümesinin orijinal hâliyle, yalnız metinle (soru boş) ve yalnız soruyla (metin yok) test etti. "Harika sonuç" alınan bazı veri kümelerinde eksik hâllerle de orijinale yakın sonuçlar alındı.
  - Bunun anlamı: sistem metinle soruyu birlikte anlamıyor, metinden ya da sorudan cevaba bir eşleme (ezber) yapıyor; veri kümesi hedeflenen yeteneği ölçmüyor. Bu durum overfit değildir, test başarısı da yüksektir.
- Entailment veri kümelerinde benzer problemler (ekrandan, 01:32:30)
  - Entailment: cümle 1 ve cümle 2 arasındaki ilişkiyi üç sınıftan biri olarak bulmak: gerektirir (cümle 1 doğruysa cümle 2 kesin doğru), karşıt, ilgisiz (cümle 2 doğru da yanlış da olabilir).
  - Arka kapı testi: sisteme yalnız bir cümleyi vermek. Doğru sınıfı yine buluyorsa istenen işi yapmıyordur. Mantıksal tutarlılık kontrolleri (karşıtlık zincirleri) de bir yoldur.
  - İnsanlar veri üretirken "gerektirir" cümlesini genelleştirerek yazar ("Parkta oynayan çocuklar var" → "Parkta oynayan insanlar var", kediler → hayvanlar, otomobil → araç). Böylece "insan", "hayvan" gibi üst kavram kelimeleri tek başına sınıfı ele verir.
- LSTM ile metin üretimi
  - Dil modeli bir sonraki kelimeyi (karakteri) tahmin edebiliyorsa, tahmini girdiye ekleyip tekrar sorarak metin üretilebilir.
  - Şiir üretimi (ekrandan, 01:40:00): yaklaşık 4 milyon karakterlik Türkçe şiir derlemi; LSTM bir sonraki karakteri tahmin etmek için eğitildi (many to many). 100'den fazla geçen 84 karakter kullanıldı; her giriş 84 boyutlu one-hot vektör, her çıkış 84 sınıftan biri. İlk 200 bin karakter, 512 LSTM hücresi, 500 iterasyon, yaklaşık 2 saat eğitim (ekrandan, 01:42:30).
  - Üretilen şiirler gramer olarak uygun, satır atlıyor, ikilik ve dörtlükler kuruyor; yerel güzel ifadeler ("Çile çoğaltılar güllerinde", "Ben kimim içimde bir de gör") derlemde geçmiyor. Ama bütünlük yok. Slayt notu: "Falcı 10 şey söyler 1'i tutar, falcı bildi olur."
  - Haber üretimi: 500 bin karakterlik spor haberleri, 512 hücre, 30 iterasyon, 2 saat eğitim. Yerel anlamlı parçalar var, bütün anlamsız; tekrarlı yapılar ("bu kadar değil, bu kadar değil...") dil modellerinin tipik problemidir.
  - Şiirin makine tarafından yazıldığını anlamak haberinkinden zordur, çünkü şiir semboliktir ve yoruma açıktır; haberde problemli kısımlar bariz görünür.
  - Üretici süreçleri objektif değerlendirmek zordur: altın standart yoktur, insan değerlendirmesi gerekir, bu da ölçeklenebilir değildir. GAN'lar resim üretmede başarılı oldu ama metin üretmede o kadar başarılı olmadı.
## Hocanın Özellikle Vurguladığı Kısımlar

- Karakter bazlı temsilin gücü
  - Sözlük dışı kelimeler ve Türkçedeki anlam taşıyan ekler nedeniyle karakter bazlı yapılar (CNN, LSTM) hem duygu analizinde hem NER'de başarılı oldu.
- Duygu analizinin zor %20'si
  - Sık kullanılan ifadelerle başarı sağlanır ama ironi ve bağlama bağlı ifadeler gibi kabaca %20'lik bir kısım hayat bilgisi ve metin dışı bağlam olmadan çözülemez.
- NER'de CRF ve dengesiz sınıflar
  - CRF klasik ve hâlâ çok başarılı bir yaklaşımdır. "O" etiketinin baskın olduğu dengesiz veride ortalama başarıya değil F1 skoruna bakılmalıdır.
- Benchmark veri kümelerine şüpheyle bakmak
  - "Her gördüğünüz sizi ikna etmesin." bAbI üzerindeki yüksek başarılar, sonradan yalnız metin ya da yalnız soru ile de elde edilebildiği gösterilince sorgulandı. Bu kötü niyetli bir aldatma değildir; otomatik ya da insan eliyle üretilen veride farkında olmadan arka kapılar oluşur.
  - Kendi çalışmalarınızda benchmark'ı çözmenin o yeteneği göstermek için gerekli ve yeterli olup olmadığını sorgulayın; yalnız metin / yalnız soru gibi testler yapın.
  - Entailment örneğinde veri kümesini oluşturanlardan birinin itiraz makalesinde yer alması bilimsel dürüstlük açısından önemli bir örnektir.
- Üretici modelleri değerlendirmek
  - Birkaç iyi örneğe bakıp "makine güzel şiir yazıyor" algısına kapılmamak gerekir; üretimin değerlendirilmesi insan yargısı ister ve ölçeklenmez.

## Kısa Tekrar Notları

- Kelime vektörü ortalaması: farklı uzunluktaki metinleri sabit uzunlukta temsil eder; uzak kelimelerde hiçbirine yakın olmayan bir nokta verir.
- CNN eşit boyutlu girdi ister (padding), LSTM kelimeleri tek tek alır.
- Karakter bazlı: one-hot karakterler, sözlük dışı kelime sorunu yok, ekleri yakalar.
- Duygu analizinde ironi ("5 dakika" / "55 dakika") hayat bilgisi ister.
- NER: önceden tanımlı varlıkları ve türlerini bulma; seq2seq; klasik yaklaşım CRF; derste karakter tabanlı LSTM; "O" baskın, F1 kullan.
- Seq2seq örnekleri: NER, çeviri, soru cevaplama, özetleme. Özetleme: extractive (seçme) / abstractive (yeniden yazma).
- LSTM/GRU hafızalıdır, CNN'in hafızası yoktur.
- Paragraf anlama: çıkarılabilir → en yakın şık, çıkarılamaz → en uzak şık; karakter 3-gram ile ~%35 (şans %20).
- Cevap nerede (Türkçe): soruya en benzer cümle, ~%70 (şans ~%10). SQuAD 2.0: 130 bin eğitim, 9 bin test, cevapsız sorular, ~%70.
- Bilim soruları, açıklamalı çözümler, matematik soruları, SWAG: çıkarım ve dünya bilgisi gerektiren veri kümeleri.
- bAbI: 20 görev, küçük sözlük; memory networks çok düşük hata. İtiraz: yalnız metin ya da yalnız soru ile de benzer başarı → veri kümesinde arka kapı.
- Entailment: gerektirir / karşıt / ilgisiz; tek cümleyle sınıf bulunabiliyorsa arka kapı var; genelleştirici kelimeler ("insan", "hayvan") ipucu veriyor.
- LSTM ile karakter düzeyinde şiir ve haber üretimi: yerel güzellik, bütünlük yok; şiirin sahteliğini anlamak daha zor.
- Üretimi değerlendirmek zor: altın standart yok, insan yargısı ölçeklenmez.

## Detaylı Açıklamalar

- **Duygu analizinde temsil seçenekleri.** Kelime torbasında her kelime bir boyut (özellik) olarak düşünülür ve TF-IDF gibi ağırlıklar kullanılır. Karakter 3-gram torbasında sözlük kelimelerden değil, metin karakter karakter kaydırılarak elde edilen ardışık üç karakterlerden oluşur. Kelime vektörü ortalamasında word2vec ya da fastText ile elde edilen, örneğin 300 boyutlu kelime vektörlerinin her boyutu ayrı ayrı ortalanır ve sonuç metnin koordinatı olur. Bu, metnin genel olarak hangi konulardan bahsettiğini gösterir; ama kelimeler anlamsal uzayda birbirinden çok uzaksa ortalama hiçbirini temsil etmez. Kelimeler birkaç yakın topak oluşturuyorsa ortalama daha makuldür.
- **Metni resme dönüştürmek.** Kelime bazlı CNN'de metnin her kelimesi M matrisinin bir satırına kelime vektörü olarak yazılır; satır sayısı en uzun metnin uzunluğudur, kısa metinler 0 ile doldurulur. Resimlerdeki $3 \times 3$, $5 \times 5$ kerneller yerine bir kelimenin tamamını kapsayan, örneğin $2 \times d$'lik filtreler aşağı doğru kaydırılır. Hocanın sezgisiyle, filtrelerden biri "çok güzel" gibi bir ifadeyi temsil eder ve onu gördüğü yerde yüksek cevap verir. Pooling ile her filtrenin çıktısı tek değere iner, sonra tam bağlı katman gelir. Böylece metinler resme dönüşür ve resimler üzerinde çalışan her tür yöntem metinlere uygulanabilir. Karakter bazlı sürümde satırlar karakterlerdir ve one-hot kodlanır; slayttaki örnekte "Allah cezanı versin XXX tüm müşterilerini kaybedersin inşallah." cümlesi için solda kelime vektörü tabanlı, sağda karakter tabanlı M matrisi gösterildi (ekrandan, 00:21:10).
- **Karakter bazlı yapı neden daha iyi?** Bir öğrenci sözlük dışı kelimeleri önerdi; hoca bunu doğruladı ve Türkçeye özgü asıl nedenin ekler olduğunu söyledi. Olumsuzluk gibi anlam katan ekleri kelime bazlı yapılar ayrı ayrı temsil edemez, karakter bazlı yapılar ise "seni seviyorum / seni sevmiyorum" farkını kelimeyi bilmese bile sondaki karakterlerden yakalar.
- **Varlık ismi tanıma ve sekans etiketleme.** NER'de varlığı bulmak, varlığın metindeki yerini bulmak demektir; slayttaki etiketli metinde varlıklar `<b_enamex TYPE="...">...<e_enamex>` biçiminde işaretlenmiştir. Sınıflandırmada çıkış tek bir sınıftır; seq2seq'te her girdi öğesi için bir çıkış üretilir. Karakter tabanlı LSTM'de her karakter bir etiket alır. Bir öğrenci, aynı "a" harfinin "Akbank" içinde varlığın parçası, "Akbank'a" ekinde ise anlamsız olduğunu, sistemin bunu nasıl ayırdığını sordu. Hoca, LSTM ve GRU gibi RNN mimarilerinin hafızası sayesinde önceki karakterleri bildiğini, bu yüzden aynı karakterin farklı bağlamlarda farklı etiket alabildiğini, hatta çok önceki bir karakterin bile etkisini tutabildiğini açıkladı. CNN'de böyle bir hafıza yoktur.
- **NER sonuçları ve dengesiz sınıflar.** 3 sınıflı veri kümesinde etiket sayıları PERSON 16291, ORGANIZATION 9183, LOCATION 11715, toplam 37189'dur. 7 sınıflı kümede eğitim/test etiket sayıları PERSON 14693/658, ORGANIZATION 9160/410, LOCATION 9767/637, DATE 1366/119, PERCENTAGE 648/62, MONEY 597/41, TIME 148/19, toplam 36379/1946'dır (ekrandan, 00:40:00). Varlık olmayan "O" karakterleri bunlardan çok daha fazladır (hocanın örneğiyle sınıf başına bin, "O" için yüz bin), bu yüzden F1 kullanılır.
  <!-- BELİRSİZ: Slaytta test başarılarının hangi sınıfa ait olduğu ayrıca yazılmıyor; değerlerin sırası büyük olasılıkla tablolardaki sınıf sırasıdır. -->
- **Paragraf anlama neden zor?** Paragraf soruları zaten insanların anlama yeteneğini ölçmek için tasarlanmıştır; iyi hazırlanmış zekâ testleri gibi bilgisayarlar için de çok zordur. Derste gösterilen basit yöntem hiçbir eğitim kullanmaz; daha karmaşık yöntemlerde bir eğitim süreci kurmak mümkün olabilir.
- **Doğrudan cevap ve ölçeklenebilir test.** Serbest metin cevapta "7. Osmanlı padişahı" ile "Fatih Sultan Mehmet"in aynı olduğunu otomatik anlamak zordur. Cevabın paragraftaki karakter aralığı istenirse doğruluk otomatik ölçülür; aynı cevap metinde birden fazla yerde geçiyorsa birden fazla doğru aralık tanımlanabilir, ama bu veri hazırlamayı zorlaştırır. Türkçe "cevap nerede" kümesinde ise cevabın geçtiği cümle (örneğin altıncı cümle) istenir; bu, "çıkarılamaz" türü sorulara göre çok daha basit bir problemdir.
- **Çıkarım ve arka kapılar.** bAbI benzeri veri kümeleri, sistemin hayat bilgisine ihtiyaç duymadan çıkarım yapabildiğini göstermek için kuruldu; memory networks bu görevlerde LSTM'lerin çözemediği görevleri çözdüğünü iddia etti. Slayttaki sonuç tablosunda (ekrandan, 01:30:00) LSTM'in ortalama hatası 1k eğitim verisinde %51,3 (20 görevin 20'si başarısız), 10k veride %36,4; güçlü gözetimli MemNN'in ortalama hatası %6,7 ve %3,2'dir. İtiraz çalışması, yalnız metin ya da yalnız soru verildiğinde bazı veri kümelerinde orijinale yakın sonuçlar alındığını gösterdi. Normalde soruyu görmeden doğru cevap vermek mümkün olmamalıdır; mümkünse veri kümesi metinden ya da sorudan cevaba bir eşleme içeriyordur. Hocanın çıkardığı ders: hiçbir sonuç sizi kolayca ikna etmesin ve kendi veri kümelerinizde bu tür testleri yapın.
- **Metin üretimi ve değerlendirme.** Dil modeli "A'dan sonra ne gelir?" sorusuna C derse, "A B C'den sonra ne gelir?" diye tekrar sorulur ve böylece metin üretilir. Şiirlerde böyle bir model yerel güzellikler üretse de çok sayıda üretimden birkaçının iyi görünmesi modelin iyi şiir yazdığını göstermez. İki sistemin ürettiği 10'ar şiirden hangisinin iyi olduğunu söyleyecek altın standart yoktur; insan değerlendirmesi gerekir ve bu ölçeklenmez. GAN'lar resimlerde bütünlüklü, yüksek çözünürlüklü üretim yapsa da metin üretiminde başarılı olamadı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
