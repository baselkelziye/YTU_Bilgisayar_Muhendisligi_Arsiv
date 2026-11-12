# Ders 12 Çalışma Özeti

## Genel Konular

- Dersin yapısı
  - Bu ders de öğrenci seminer sunumlarına ayrıldı. Her sunumda bir öğrenci veri sıkıştırma ile ilgili bir makaleyi özetledi; hoca sunumdan sonra sorular sordu ve yorum yaptı. Toplam beş sunum yapıldı. İngilizce yapılan üç sunumda altyazı çoğu yerde bozuk olduğu için içerik büyük ölçüde slaytlardan kuruldu.
- Sunum 1: RNN ile tam çözünürlüklü görüntü sıkıştırma (ekrandan, 00:10:00, 00:16:40, 00:20:00, 00:23:20)
  - Genel görüntü sıkıştırma modeli: kaynak görüntü → kaynak kodlayıcı (DFT, DCT, DWT gibi dönüşümlerle frekans uzayına geçiş; kayıpsız) → niceleyici (yüksek frekanslı bileşenleri atar; kayıplı) → entropi kodlayıcı (örneğin Huffman; kayıpsız) → sıkıştırılmış sinyal. Eşleyici (mapper) pikseller arası artıklığı, niceleyici psikogörsel artıklığı azaltır.
  - RNN zaman boyutunda derin bir yapıdır ve kaybolan gradyan sorunu yaşar; LSTM bunu hücre başına ek etkileşimlerle çözer. Hücre durumu (cell state) ve gizli durum (hidden state) bir sonraki hücreye aktarılır. Associative LSTM, LSTM'i holografik temsil ile genişletir.
  - Model: $32 \times 32 \times 3$ görüntü kodlayıcı → ikilileştirici (binarizer) → kod çözücü zincirinden geçer; her yinelemede kalan hata (residue) bir sonraki yinelemeye girer. $k$ yineleme sonunda toplam $m \cdot k$ bit üretilir; her adım 128 bit ekler, böylece bit hızı adım adım artırılabilir (ilerlemeli yöntem).
  - Yeniden kurma çerçevesinde üç yaklaşım incelendi: one-shot ($\gamma = 0$, her yinelemeden sonra tam görüntü tahmin edilir), toplamsal (additive, $\gamma = 1$, her yineleme yalnız kalan hatayı kurar, sonuç çıktıların toplamıdır) ve kalan hatanın ölçeklendirilmesi (residual scaling).
  - Sonuç: 32×32 veri setinde GRU (One Shot) iki ölçütte de birinci oldu (MS-SSIM AUC 1,8098, PSNR-HVS AUC 53,15). Yüksek entropili veri setiyle eğitilen modeller genelde daha iyidir; "zor" örneklerle eğitmenin önemli olduğu sonucuna varıldı.
- Sunum 2: Gürültü giderici otokodlayıcılarla denetimsiz cümle sıkıştırma (ekrandan, 00:36:40, 00:40:00, 00:43:15, 00:44:05, 00:44:50)
  - Cümle sıkıştırma, metin özetlemenin küçültülmüş bir sürümü olarak görülebilir. Çıkarımsal (extractive) yaklaşım metinden kelime ya da öbek seçer; soyutlayıcı (abstractive) yaklaşım metni yeniden ifade eder. Bu çalışma çıkarımsal özetlemeye odaklanır ve paralel derlem (uzun-kısa cümle çiftleri) kullanmaz.
  - Temel model, iki yönlü çok katmanlı LSTM'li dikkatli (attentional) bir kodlayıcı-kod çözücüdür; kayıp fonksiyonu negatif log-olabilirliktir. Eğitim düzeni: Additive Noising, Additive Sampling (başka cümlelerden rastgele kelime eklenmesi) ve Shuffling (unigram ya da bigram karıştırma). Model, karıştırılmış kelime kümesinden özgün cümleyi geri kurmayı öğrenir.
  - Uzunluk geri sayımı (length countdown) girdisi kod çözücüye istenen uzunlukta çıktı ürettirir. Özgün cümlenin InferSent cümle gömmesi de modele verilir.
  - ROUGE sonuçları: 2-g shuf + InferSent R-1/R-2/R-L 28,42 / 7,82 / 24,95; denetimli Seq2seq 35,50 / 15,54 / 32,45. Denetimsiz model, denetimli modelin gerisinde kalır ve basit taban çizgileriyle (All text, F8W) aynı düzeydedir.
  - İnsan değerlendirmesinde InferSent ROUGE'u iyileştirse de dilbilgisi ve anlam puanlarını düşürür; nicel değerlendirme insan değerlendirmesiyle iyi örtüşmez.
- Sunum 3: XML sıkıştırma teknikleri üzerine bir inceleme (survey) (ekrandan, 01:00:00, 01:02:00, 01:10:00, 01:16:05)
  - XML platformdan bağımsız, kendini tanımlayan bir işaretleme dilidir; açma etiketi, veri ve kapama etiketinin sürekli tekrarı dosyayı büyütür.
  - XML sıkıştırıcıları iki ölçüte göre sınıflandırılır: XML yapısını bilip bilmemesine göre (genel metin sıkıştırıcıları = XML-blind; XML-bilinçli olanlar şemaya bağımlı ya da bağımsız) ve yeteneğine göre (sorgulanabilir ya da sorgulanamaz; sorgulanabilirler homomorfik ya da homomorfik olmayan).
  - Genel metin sıkıştırıcıları: gzip (LZ77 + Huffman), bzip2 (Burrows-Wheeler dönüşümü + Huffman; gzip'ten iyi ama yavaş), PPM.
  - XMill: yapı veriden ayrılır; başlangıç etiketleri ve öznitelik adları sözlükle T1, T2, ... olarak kodlanır, kapama etiketleri "/" ile değiştirilir, veri değerleri kapsayıcı numarasıyla (C3, C4, ...) temsil edilir. Her kapsayıcı ayrı ayrı gzip ile sıkıştırılır. Örnekte düz gzip 1,75 MB, XMill 1,33 MB verir.
  - Diğer şemadan bağımsız yöntemler: XWRT (kelime değiştirme dönüşümü), XComp, XMLPPM, SCMPPM, Exalt (bağlamdan bağımsız dilbilgisi + aritmetik kodlama), AXECHOP (MPM ile dilbilgisi + BWT). Şemaya bağımlı yöntemler, alıcı ve göndericinin şemayı bilmesi gerektiği için pek kullanılmaz.
  - Sorgulanabilir sıkıştırıcılar (homomorfik: XGrind, XPRESS, QXT; homomorfik olmayan: XSeq, XCQ, TREECHOP, XQzip, XBzip, ISX, XCpaqs, XQueC) veriyi açmadan sorgulama ve güncelleme sağlar. TREECHOP'ta her düğüm atasının kodunu önek olarak alır; aynı XPath konumundaki düğümler aynı kod sözcüğünü paylaşır.
  <!-- BELİRSİZ: Sorgulanabilir sıkıştırıcı adları altyazıda "Xsec, Xcq, Tricop, Xzips, Xbzip, ISX, Xcaps, Xquick" diye geçiyor ve bu slaydın karesi alınmadı; yazımlar literatürdeki adlara göre düzeltildi. "AXEC-COP" da büyük olasılıkla AXECHOP'tur. -->
  - Deney sonuçları: yapısal belgelerde en iyi sıkıştırma oranını PPM, özgün belgelerde XMill-gzip vermiştir; SCMPPM ve XMLPPM'in açma süresi çok uzundur.
- Sunum 4: Fraktal görüntü sıkıştırmaya giriş (ekrandan, 01:33:00, 01:40:00, 01:41:20)
  - Fraktal görüntü, eğme, germe, döndürme ve ölçekleme yapan afin dönüşümlerin art arda uygulanmasıyla üretilir. Her dönüşüm 6 sayıyla ($a_i, b_i, c_i, d_i, e_i, f_i$) tanımlanır; görüntü bir dönüşüm topluluğu olarak kodlanır ("fotokopi makinesi" benzetmesi).
  - Yöntem kayıplıdır: insan gözünün küçük değişikliklere duyarsızlığından yararlanılır ve aralık (range) bloklarına birebir değil benzer alan (domain) blokları eşlenir. Yalnız bloklar ve afin dönüşümler saklanır.
  - Kod çözme: $\eta = \Gamma(\Omega)\Psi(\Omega)$; $\Gamma$ alçak geçiren süzgeç ve alt örneklemeyle alan görüntüsünü üretir, $\Psi$ alan bloklarından aralık bloklarına eşlemeleri uygular. 7'den az yinelemede iyi bir yaklaşım elde edilir.
  - Sonuç (128×128 Lena): 2×2 blokta kodlama 10 dk, SNR 27 dB, kod kitabı 16384 byte, 1 byte/piksel; 4×4 blokta kodlama 55 s, çözme 28 s, SNR 21 dB, kod kitabı 6144 byte, 0,375 byte/piksel.
- Sunum 5: API yanıtlarında küçük XML ve JSON belgelerinin sıkıştırılması (ekrandan, 01:48:10, 01:50:00, 01:54:30, 01:56:10)
  - Web servislerinde XML ve JSON ortak dildir. Etiketlerin her istekte tekrarlanması belgeyi kendini tanımlayıcı yapar ama gereksiz veriyle doldurur. Sunan öğrenciye göre örnekteki veri sıralı gönderilse 55 byte, JSON olarak 154 byte, XML olarak 169 byte tutar.
  - XMill ve SMCA yapı ile veriyi ayrı işler, etiketlere konumlarına göre numara verir, her veri yolu için bir kapsayıcı açar. Sorunları: küçük belgelerde az veri içeren çok sayıda kapsayıcı oluşur; sıra ile numara vermek sık etiketlere büyük sayılar verebilir; sıkıştırılmış belge sorgulanamaz.
  - Önerilen yöntem: yapılandırma aşamasında etiket tablosu (en sık etiket 1 numara) ve sembol tablosu kurulur; İngilizce karakterler (ASCII 32-127) ASCII değeri eksi 31 ile iki basamaklı sayılara eşlenir. Sıkıştırmada belge, 4 bitle temsil edilen sembollerden oluşan XMLN biçimine çevrilir (T = etiket, A = öznitelik, 0 = kapama etiketi), iki sembol bir byte'a paketlenir (XMLS) ve ardından bir arka plan sıkıştırıcı (bu çalışmada PPM) uygulanır.
  - Sonuç: küçük belgelerde önerilen yöntem XMill ve SMCA'dan iyidir; yaklaşık 1 MB'a kadar üstünlüğünü korur, 2 MB'tan büyük belgelerde SMCA ile çoğunlukla eşittir. Çok karakterli dillerde ve ikili veride etkinliği düşer.

## Hocanın Özellikle Vurguladığı Kısımlar

- Survey çalışmalarının değeri
  - Hoca, doktora yapanlara çalışma konularını belirleyince (örneğin tez önerisinden önce) o alanda bir survey hazırlamalarını önerdi: kim, hangi veri seti ve yöntemle, hangi sonucu almış. Son 3-4 yılda aynı konuda survey yoksa bunu yayın olarak göndermelerini, çünkü surveylerin çok atıf aldığını söyledi; ama yakın tarihte benzer bir survey varsa kabul almanın zor olacağını, tarihlerin mutlaka kontrol edilmesi gerektiğini vurguladı.
- Surveyde yöntem seçimi
  - XML sunumunda hoca, survey içinde çok sayıda yöntem olduğunu, anlatılacakların başarısı yüksek olanlardan seçilmesi gerektiğini belirtti.
- JSON zaten sade, neyi sıkıştırıyoruz?
  - Hoca, XML'de çok fazla gereksiz kısım olduğunu ama JSON'un "duru" olduğunu söyleyip JSON'da neyin sıkıştırıldığını sordu. Cevap: anahtarlardan (key) bir sözlük kurulup anahtarlar kısaltılır; verilerde pek bir şey yapılmaz.
- Tablodaki terimlerin anlamı
  - Hoca, RNN sunumunda tablolardaki "One Shot" ifadesini, cümle sıkıştırma sunumunda ROUGE tablosundaki "F8W/F&W" taban çizgisinin açılımını sordu. İki soruya da altyazıda net bir cevap yoktur.
  <!-- BELİRSİZ: 00:31:18 ve 00:49:31'deki öğrenci cevapları altyazıda anlaşılmıyor. -->
- Daha önce görülen yöntemlerle bağlantı
  - XML sunumunda bzip2'deki Burrows-Wheeler dönüşümü geçince hoca bu dönüşümün önceki bir seminerde anlatıldığını hatırlattı.

## Kısa Tekrar Notları

- Görüntü sıkıştırma hattı: dönüşüm (kayıpsız) → niceleme (kayıplı) → entropi kodlama (kayıpsız).
- RNN tabanlı sıkıştırma: kodlayıcı-ikilileştirici-kod çözücü yinelemesi; her yineleme 128 bit ekler; one-shot ($\gamma = 0$) ve toplamsal ($\gamma = 1$) yeniden kurma.
- Denetimsiz cümle sıkıştırma: gürültü ekle, karıştır, otokodlayıcıyla geri kur; uzunluk geri sayımı; InferSent ROUGE'u artırır ama insan değerlendirmesini düşürür.
- XML sıkıştırıcıları: XML-blind (gzip, bzip2, PPM) ve XML-bilinçli; sorgulanabilir (homomorfik/homomorfik olmayan) ve sorgulanamaz.
- XMill: yapı/veri ayrımı, T etiketleri, "/" kapama, C kapsayıcıları, kapsayıcı başına gzip; 1,75 MB → 1,33 MB.
- Fraktal sıkıştırma: afin dönüşüm başına 6 sayı; 2×2 blok kaliteli ama yavaş, 4×4 blok hızlı ve daha az bit.
- Küçük XML/JSON: sıklığa göre etiket tablosu, 4 bitlik XMLN sembolleri, byte'a paketleme, PPM; küçük belgede SMCA'dan iyi, büyükte eşit.

## Detaylı Açıklamalar

- RNN sunumu sonuç tablosu (ekrandan, 00:23:20)
  - 32×32 veri setiyle eğitim (MS-SSIM AUC sırası / değeri, PSNR-HVS AUC sırası / değeri): GRU (One Shot) 1 / 1,8098, 1 / 53,15; LSTM (Residual Scaling) 2 / 1,8091, 4 / 52,36; LSTM (One Shot) 3 / 1,8062, 3 / 52,57; LSTM (Additive Reconstruction) 4 / 1,8041, 6 / 52,22; Residual GRU (One Shot) 5 / 1,8030, 2 / 52,73; Residual GRU (Residual Scaling) 6 / 1,7983, 8 / 51,25; Associative LSTM (One Shot) 7 / 1,7980, 5 / 52,33; GRU (Residual Scaling) 8 / 1,7948, 7 / 51,37; taban çizgisi 1,7225 / 48,36.
  - Yüksek entropili veri setiyle eğitim (web'den rastgele 6 milyon 1280×720 görüntü): LSTM (One Shot) 1 / 1,8166, 8 / 48,86; GRU (One Shot) 2 / 1,8139, 2 / 53,07; Residual GRU (One Shot) 3 / 1,8119, 1 / 53,19; Residual GRU (Residual Scaling) 4 / 1,8076, 7 / 49,61; LSTM (Residual Scaling) 5 / 1,8000, 4 / 51,25; LSTM (Additive) 6 / 1,7953, 5 / 50,67; Associative LSTM (One Shot) 7 / 1,7912, 3 / 52,09; GRU (Residual Scaling) 8 / 1,8065, 6 / 49,97; Baseline LSTM 1,7408 / 48,88.
  - JPEG: YCbCr 4:4:4 1,7748 / 51,28; YCbCr 4:2:0 1,7998 / 52,61.
  - Modeller, oran-bozulma eğrisinin altındaki alan (AUC) ile sıralanır. MS-SSIM, RGB kanallarının her birine ayrı uygulanıp ortalaması alınır. Sonuç bölümüne göre içeriğe dayalı kalan hata ölçekleme ve GRU'nun yeni bir varyasyonu (Residual GRU), yüksek entropili veriyle eğitilen modeller arasında en yüksek PSNR-HVS'yi verir.
- Cümle sıkıştırma tabloları (ekrandan, 00:43:15, 00:44:05, 00:44:50)
  - ROUGE (R-1 / R-2 / R-L / ortalama uzunluk): All text 28,91 / 10,22 / 25,08 / 31,3; F8W 26,90 / 9,65 / 25,19 / 8; 2-g shuf 27,72 / 7,55 / 23,43 / 15,4; 2-g shuf + InferSent 28,42 / 7,82 / 24,95 / 15,6; Seq2seq 35,50 / 15,54 / 32,45 / 15,4; words-lvt2k-1sent (Nallapati vd., 2016) 34,97 / 17,17 / 32,70.
  - Ablasyon (R-1 / R-2 / R-L): 1-g shuf (dikkatsiz) 23,01 / 5,51 / 20,07; 2-g shuf (dikkatsiz) 22,36 / 5,18 / 19,60; 1-g shuf 27,22 / 7,63 / 23,55; 2-g shuf 27,72 / 7,55 / 23,43; 1-g shuf + InferSent 28,12 / 7,75 / 24,81; 2-g shuf + InferSent 28,42 / 7,82 / 24,95. Dikkat, bigram karıştırma ve cümle gömmesinin üçü de ROUGE'a olumlu katkı verir.
  - İnsan değerlendirmesi (6 değerlendirici; dilbilgisi / anlam): 2-g shuf 3,53 / 2,53; 1-g shuf + InferSent 2,82 / 2,50; 2-g shuf + InferSent 2,87 / 2,13; Seq2seq 3,43 / 2,60; gerçek özet (ground truth) 4,07 / 3,87. Gigaword veri setinde başlıklar bazen kaynak metinde olmayan bilgi içerdiği için gerçek özetin anlam puanı bile görece düşüktür.
- XMill yapı kodlaması örneği (ekrandan, 01:00:00)
  - Girdi: `<Book><Title lang="English">Views</Title><Author>Miller</Author><Author>Tai</Author></Book>`.
  - Atamalar: Book = T1, Title = T2, @lang = T3, Author = T4; English = C3, Views = C4, Miller ve Tai = C5.
  - Yapı akışı: `T1 T2 T3 C3 / C4 / T4 C5 / T4 C5 /`. Aynı yoldaki veriler (iki yazar adı) aynı kapsayıcıya (C5) girer.
- Küçük XML örneği ve XMLN dönüşümü (ekrandan, 01:48:10, 01:54:30)
  - XML: `<Havaalanı City="Edmonton">` altında Varış-Zamanı 16:02:30, Kalkış-Zamanı 16:22:30, Tarih 2019-12-24, Kapı 6 ve Kapı 7.
  - XMLN: `T2 A4 1314150616070616 T3 2526272829273028 0 T6 2526272929273028 0 T5 29282534232529232935 0 T1 23 0 T1 24 0 0`.
  - Örnekteki sembol kodları kendi içinde tutarlıdır (Edmonton, 16:02:30, 16:22:30 ve 2019-12-24 python ile karşılaştırıldı), ama sunumda söylenen "ASCII değeri eksi 31" kuralıyla örtüşmez (örneğin E için 38 beklenirdi, slaytta 13).
  <!-- BELİRSİZ: Kapı değerleri 6 ve 7 slaytta 23 ve 24 olarak kodlanmış; oysa aynı örnekte 6 = 26 ve "-" = 23. Büyük olasılıkla slayt hatasıdır. Sunan öğrenci 4 bitlik 13 sembolü "1-9, T, A ve 0" diye saydı; bu 12 eder, 13. sembol açıklanmadı. -->
- Fraktal sonuç tablosu (ekrandan, 01:41:20)
  - 2×2 blok (Yöntem I): 6 yineleme, kodlama 10 dk, kod kitabı 16384 byte, SNR 27 dB, tepe hata 115, 1 byte/piksel. 4×4 blok (Yöntem II): 6 yineleme, kodlama 55 s, çözme 28 s, kod kitabı 6144 byte, SNR 21 dB, tepe hata 95, 0,375 byte/piksel. $6144 / 16384 = 0{,}375$ ve $128 \times 128 = 16384$ (python ile doğrulandı).
  <!-- BELİRSİZ: Yöntem I'in çözme süresi slaytta imleç altında kalıyor; büyük olasılıkla 45 s. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
