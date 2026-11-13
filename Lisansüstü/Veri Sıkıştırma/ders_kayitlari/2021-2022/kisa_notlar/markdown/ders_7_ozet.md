# Ders 7 Çalışma Özeti

## Genel Konular

- Seminer sunumları ve proje gösterimleri
  - Bu ders, önceki ders gibi öğrenci seminerlerine ayrıldı. Her sunumda bir öğrenci veri sıkıştırmayla ilgili bir makaleyi yaklaşık 15 dakikada anlattı; hoca sunum sırasında ve sonunda sorular sordu.
  - Sekiz sunum yapıldı: çok katmanlı görüntü temsili, mobil uygulamalarda metin sıkıştırma (BWT, MTF, aritmetik kodlama), Transformer ile kayıpsız sıkıştırma, gürültü giderici otomatik kodlayıcıyla denetimsiz cümle sıkıştırma, sinir ağlarıyla kayıpsız sıkıştırma (LSTM ve Transformer), DNN ile sismik veri sıkıştırma, evrişimsel RNN ile göğüs röntgeni sıkıştırma ve Burrows-Wheeler dönüşümü (BWT).
  - Dersin sonunda iki öğrenci Huffman kodlamasıyla görüntü sıkıştırma projelerini gösterdi; hoca header yapısı, kod tablosu ve renk sayısını azaltma üzerine sorular sordu.
- Sunum 1: Çok katmanlı görüntü temsili (multi-layered image representation)
  - Pürüzsüz bölgeler ile dokulu bölgeleri bir arada içeren görüntüleri verimli kodlamak için görüntü, tutarlı katmanların üst üste binmesi (süperpozisyon) olarak temsil edilir: pürüzsüz bölgeler katmanı, dokular katmanı.
  - Algoritma: görüntü önce dalgacık (wavelet) tabanında sıkıştırılır; bu ilk katman görüntünün genel şeklini, bir tür karikatürünü verir. Sıkıştırma hatası birinci artıktır (residual); artıklar dokulardan oluşur ve dalgacık paketleri ya da yerel kosinüs (local cosine, yerel trigonometrik taban) ile sıkıştırılır. İkinci artık, birinci artığın sıkıştırma hatasıdır. Artıkta yapı kalmayana, yalnız gürültü kalana kadar devam edilir.
  - Bit bütçesi (budget, bpp olarak önceden belirlenir) katmanlara paylaştırılır: düz (smooth) görüntülerde (Lena) bütçenin çoğu dalgacık katmanına, dokulu görüntülerde (Roofs, çatı kiremitleri) doku katmanına verilir.
  - Deneyler: Roofs, Barbara ve Clown, hepsi 8 bpp ve 512×512; karşılaştırma SPIHT (Said ve Pearlman) ile (ekrandan, 00:10:00).
  - PSNR sonuçları (desibel, yüksek daha iyi), örneğin Roofs için 0,125 bpp'de çok katmanlı 25,23, SPIHT 23,77; Clown'da fark çok küçüktür (ekrandan, 00:09:35). Görsel olarak çatı dokusu, Barbara'nın pantolonu ve masa örtüsü daha iyi korunur; Barbara'nın yüzünde doku ile düz bölge yan yana olduğundan bozulma görülür.
- Sunum 2: Mobil uygulamalarda metin sıkıştırma
  - Bellek ve kapasite kısıtlı mobil uygulamalarda metin dosyası sıkıştırması. Veri: bir hadis kitabının (Sünen-i İbn Mace, 32 kitap) Bahasa çevirisi; blok boyutları 1024, 2048, 4096 ve 8192 (ekrandan, 00:20:00).
  - Dört yöntem karşılaştırıldı: yalnız aritmetik kodlama; MTF + aritmetik kodlama; BWT + aritmetik kodlama; BWT + MTF + aritmetik kodlama. Hepsi kayıpsızdır.
  - Aritmetik kodlama örneği: karakterler alfabetik dizilip olasılıklarına göre $[0,1)$ aralığı bölünür (ekrandan, 00:21:40). Move-to-front örneği: `aaafhhimst` dizisi için çıktı 0,0,0,5,7,0,8,12,18,19 (ekrandan, 00:22:30).
  - Sıkıştırma oranı = sıkıştırılmış boyut / orijinal boyut × 100 (düşük daha iyi). Yalnız aritmetik kodlamada en iyi oran %58,9 (en büyük dosya), en kötü %75,73 (en küçük dosya) (ekrandan, 00:24:15).
  - Sonuç: BWT, MTF ve aritmetik kodlama sırayla kullanıldığında en iyi sonuç alındı; BWT büyük blok boyutunda daha iyi sıkıştırır. <!-- BELİRSİZ: MTF + AC, BWT + AC ve üçlü yöntemin oranları altyazıda karışık (%36,30, %59, %76, %32); tablo karesi alınmadı. -->
- Sunum 3: Transformer ile kayıpsız veri sıkıştırma
  - Kayıpsız sıkıştırmada istatistiksel yöntemler ve PAQ ailesi (PAQ8 vb.) çok iyi sıkıştırır ama yavaş ve maliyetlidir; el yapımı istatistikler yerine modelin kendisinin öğrenmesi hedeflenir.
  - Sinir ağıyla kayıpsız sıkıştırmanın iki unsuru: tahminci (predictor) ve entropi kodlama şeması.
  - Transformer-XL tabanlı model; daha önce sıkıştırılmış veriyi tekrar ziyaret etmek (revisit) ve n-gram girdisi eklemek denenmiş. Veri: enwik8 (100 MB), büyük harfler küçüğe çevrilmiş; 12, 18, 24 katman ve 256, 512, 1024 gizli boyut denenmiş, 12 katmandan sonra iyileşme görülmemiş.
  - enwik8 tablosu (BPC): gzip -9 2,92; xz -9 1,99; paq8hp12any 1,31; CMIX 1,20; lstm-compress 1,65; Transformer (Bellard 2019) 1,46; LSTM (Bellard 2019) 1,35; tekrar ziyaretsiz 1,33; tekrar ziyaretli 1,20 (ekrandan, 00:37:10).
  - Büyük-küçük harf ön işlemi 0,01 BPC, n-gram 0,025 BPC iyileştirme sağlar; dropout p = 0,25 ile 0,05 BPC iyileşme (ekrandan, 00:40:00).
- Sunum 4: Gürültü giderici otomatik kodlayıcıyla denetimsiz cümle sıkıştırma
  - Cümle sıkıştırma: gereksiz bilgiyi atıp önemli içeriği koruyan daha kısa cümle üretmek. Denoising autoencoder, girdisi bilerek bozulmuş veriden orijinali kurtarmayı öğrenir.
  - Eğitim: referans cümleye veri setindeki başka cümlelerden örneklenen kelimeler eklenir (additive sampling), kelimeler karıştırılır (shuffle), model orijinal cümleyi kurtarmak üzere eğitilir. InferSent cümle gömmesi de modele verilir.
  - Veri: Gigaword haber makaleleri (ilk cümle ve başlık), yaklaşık 3,8 milyon eğitim, 400 bin doğrulama örneği; GloVe gömmeleri; 20 bin kelimelik sözlük; 3 katmanlı, 512 gizli birimli LSTM kodlayıcı ve çözücü; batch boyutu 128.
  - ROUGE ablasyonu: en iyi model 2-gram karıştırma + InferSent, R-1 28,42, R-2 7,82, R-L 24,95 (ekrandan, 00:50:00). Kısa cümlelerde performans daha iyidir; insan değerlendirmesi de yapılmıştır.
  - Hoca, kayıplı metin sıkıştırmanın tercih edilen bir şey olmadığını ve çalışmanın amacını anlamadığını söyledi.
- Sunum 5: Sinir ağlarıyla kayıpsız veri sıkıştırma (Bellard)
  - Sinir ağı, önceki sembollerden $s_t$ için olasılık vektörü tahmin eder; $s_t$ yaklaşık $-\log_2 p(s_t)$ bitle aritmetik kodlayıcıyla kodlanır. Kod çözücü simetrik çalıştığı için model parametrelerinin iletilmesi gerekmez.
  - LSTM modeli: Graves'in modeline benzer, hücre durumu sınırlandırılmış; katman normalizasyonu; aşırı öğrenme olasılığı çok düşük olduğu için dropout yok; 20 zaman adımlı kesilmiş geri yayılım; Adam optimizasyonu (ekrandan, 01:00:00).
  - Transformer modeli: göreli yerine öğrenilen konum gömmeleri, 64 adımlık segmentler, 8 dikkat başlığı, doğrusal azalan öğrenme oranı.
  - Her CPU ve işletim sisteminde aynı sonucu vermek için harici kitaplığa bağlı olmayan özel bir C kitaplığı kullanılır.
  - Ön işlemciler: CMIX metin ön işlemcisi (yaklaşık 45 bin kelimelik sözlük, kelimeler 1-3 baytlık kodlarla değiştirilir, büyük harfler kaçış koduyla küçüğe çevrilir) ve alt kelime tabanlı ön işlemci (sıfırıncı derece entropiyi en çok düşüren sembol çiftleri birleştirilir, yaklaşık 16 bin sembollük sözlük).
  - enwik8 sonuçları (bpb): CMIX 1,19 en iyi ama çok yavaş (1,56 kB/s); LSTM (large2) 1,34; Transformer 1,45. enwik9'da CMIX 0,93, LSTM (large2) 1,00 (ekrandan, 01:05:40).
- Sunum 6: DNN ile sismik veri sıkıştırma
  - Sismik veri, yer altı yapısı hakkında bilgi için sensörlerle toplanır; çok büyük olduğundan iletim için sıkıştırılır. Kayıpsız yöntemler tamsayıda en çok 5:1, ondalıklı (float) değerlerde 2:1 sıkıştırır (ekrandan, 01:20:00).
  - Kayıplı sıkıştırmanın üç adımı: dekorelasyon (dalgacıklar, yerel trigonometrik fonksiyonlar ya da ikisinin kombinasyonu), kuantalama ve kodlama.
  - Tahmine dayalı yöntem: örneklerin bir kısmıyla gönderici tarafta model eğitilir, ağırlıklar alıcıya gönderilir; artıklar K-Means ile kuantalanır, Huffman ile kodlanır (ekrandan, 01:21:50). Karşılaştırma doğrusal tahmin (LPC) ile yapılmış.
  - SNR tablosu: LPC 23,1–30,27 dB, DNN 42,07–58,82 dB; kuantalama seviyesi arttıkça başarı artar (ekrandan, 01:24:10). Huffman, sabit uzunluklu kodlamaya göre ortalama kod uzunluğunu kısaltır. 40 dB üzeri SNR ile yaklaşık 10:1 sıkıştırma elde edilmiş.
- Sunum 7: Evrişimsel RNN ile göğüs röntgeni sıkıştırma
  - Tıbbi görüntüler çok büyüktür; uzmana iletmek için kayıplı sıkıştırılır. ChestX-ray8 veri seti; 1024×1024 görüntülerden 128×128 ve 256×256 kesitler; 20.000 eğitim, 1.000 doğrulama, 500 test örneği, karıştırılarak seçilmiş (ekrandan, 01:30:00).
  - Kodlayıcı: havuzlama + 1×1 evrişim ile adım 2 olan 3×3 evrişim paralel çalışıp ortalaması alınır; ardından RNN-Conv katmanları (LSTM'deki ağırlık çarpımları yerine evrişim) ve $1\times1\times\beta$ darboğaz; sıkıştırılmış tensör $H/16 \times W/16 \times \beta$. Çözücü: RNN-Conv blokları ve depth-to-space (D2S) ile yeniden büyütme (ekrandan, 01:32:50).
  - $\beta$ sıkıştırma oranını ayarlar; sunumda $\beta = 256 / R$ diye verildi ($R = 2$ için $\beta = 128$).
  - Sonuç (128×128, ekrandan, 01:34:15): önerilen yöntem PSNR'de Toderici ve arkadaşları ile JPEG 2000'den iyidir (oran 8'de 35,93 dB); oran 2'de SSIM'de JPEG 2000 (0,9801) daha iyidir.
- Sunum 8: Burrows-Wheeler dönüşümü (BWT)
  - BWT, aynı karakterleri yan yana getirerek metni daha iyi sıkıştırılabilir hale getirir; ek bilgi olarak yalnız orijinal satırın indisi gerekir. Zincir: bloklara ayrılmış veri → BWT → MTF → Huffman ya da aritmetik kodlama; açmada tersleri (ekrandan, 01:40:00).
  - abracadabra örneği: dönüşümün çıktısı `bdbcarraaaa`, orijinal dizi 5. satırda (ekrandan, 01:40:45). Ters dönüşümde sıralama ve SıraBul vektörü (6, 9, 7, 8, 1, 10, 11, 2, 3, 4, 5) ile 5. konumdan başlanarak abracadabra geri elde edilir (ekrandan, 01:42:30).
  - bzip2, BWT ile Huffman kodlamasını kullanır.
- Proje gösterimleri: Huffman ile görüntü sıkıştırma
  - Birinci proje: BMP görüntülerin piksel değerleri için frekans tablosu, Huffman ağacı ve kod tablosu; sıkıştırma ve açma. Kazanç %4 (2.359.326 → 2.265.942 bayt), %19 ve %31 (1.130.022 → 782.515 bayt) (ekrandan, 01:50:00).
  - İkinci proje: genel dosya sıkıştırma altyapısı ve 256 renk paletli bitmap için başlık ile raster verisini ayırıp yalnız raster'ı Huffman ile kodlama; bit düzeyinde okuma-yazma (bit packing). Örnek görüntüde entropi 3,013041, ortalama kod uzunluğu 3,03688 bit, 133.136 → 50.540 bayt (ekrandan, 02:02:30); Lena'da entropi 8 bite yakın olduğundan kazanç az.

## Hocanın Özellikle Vurguladığı Kısımlar

- BWT ve MTF, entropi kodlayıcının önünde bir dönüşümdür
  - Görüntü sıkıştırmada DCT ya da dalgacık dönüşümü birbirine yakın değerleri yan yana getirir; metinde de BWT ve MTF aynı karakterleri arka arkaya getirerek aritmetik kodlamanın ya da Huffman'ın başarısını artırır. Bunlar metin üzerindeki dönüşüm yöntemleridir.
- Kayıplı metin sıkıştırma tercih edilmez
  - Hoca, cümle sıkıştırma çalışmasında cümle açıldığında orijinaline dönmediğini, metinde kayıplı sıkıştırmanın genelde yapılmadığını vurguladı.
- Tıbbi görüntüde kayıplı sıkıştırma riski
  - Röntgende küçücük bir lezyon kayıplı sıkıştırmada kaybolabilir; bu yüzden tıbbi görüntüde kayıplı sıkıştırmaya temkinli yaklaşılmalıdır.
- Huffman'dan önce renk sayısını azaltmak
  - Gözün ayırt edemediği renk tonları kuantalama ile azaltılırsa Huffman ağacı küçülür, sıkıştırma başarısı artar.
- Kod çözücünün kodlara ihtiyacı vardır
  - Açan taraf aynı kodları üretebilmek için ağacı ya da kod tablosunu (header) almalıdır; header'ın büyüklüğü sıkıştırma kazancını etkiler.
- Basit görünen yöntemler
  - BWT çok basit görünür, ama bulunması zordur; hoca bu tür yöntemlerin basit olsa da akla gelmesinin değerini vurguladı.

## Kısa Tekrar Notları

- Çok katmanlı temsil: önce dalgacık katmanı, sonra artıklar dalgacık paketi ya da yerel kosinüsle; artıkta yalnız gürültü kalınca durulur.
- PSNR yüksek ise kalite iyidir; SPIHT, ağaç tabanlı bir dalgacık kodlayıcısıdır.
- Mobil metin sıkıştırmada en iyi zincir BWT → MTF → aritmetik kodlama.
- MTF: `aaafhhimst` → 0,0,0,5,7,0,8,12,18,19.
- Sinir ağı tabanlı kayıpsız sıkıştırma = olasılık tahmincisi + aritmetik kodlayıcı; çözücü simetrik olduğundan ağırlıklar gönderilmez (Bellard).
- enwik8'de CMIX yaklaşık 1,19-1,20 BPC ile en iyi ama en yavaş.
- Sismik veride DNN tahmini + K-Means kuantalama + Huffman; LPC'ye göre SNR yaklaşık iki katı.
- Röntgen sıkıştırmada RNN-Conv, darboğaz $\beta$ ile oran ayarı, D2S ile yeniden büyütme.
- BWT: abracadabra → `bdbcarraaaa`, indis 5; bzip2 = BWT + Huffman.
- Huffman projelerinde: kazanç görüntünün renk dağılımına bağlıdır; entropisi 8 bite yakın görüntü (Lena) çok az sıkışır.

## Detaylı Açıklamalar

- Çok katmanlı görüntü temsili
  - Tek bir dönüşüm, görüntünün her bölgesi için uygun değildir: dalgacıklar pürüzsüz bölgeleri ve kenarları iyi temsil eder, periyodik dokuları kötü temsil eder. Bu yöntemde $L_0$ başlangıç kütüphanesiyle (dalgacık) görüntü sıkıştırılır, çözülen görüntü $\hat{R}_0$ ile orijinal arasındaki fark $R_1$ artığıdır. $R_1$ başka bir kütüphaneyle (yerel kosinüs ya da dalgacık paketleri) sıkıştırılır; kalan $R_2$ ise artık yalnız gürültü içerir. Sıkıştırılmış görüntü, katmanların toplamıdır.
  - Clown görüntüsü dalgacık dostu bir görüntü olarak bilinir; bu görüntüde ikinci katman için dalgacık paketleri yerel kosinüsten daha iyi kütüphane olmuş. Fark PSNR'de küçük olsa da duvar kağıdı dokusu daha iyi korunmuş.
  - Ders sonrası not: Hoca sunum sonunda dalgacık dönüşümünün DCT yerine kullanıldığını ve JPEG'te de kullanıldığını söyledi. Klasik JPEG DCT kullanır; dalgacık dönüşümü büyük olasılıkla JPEG 2000'i kastetmektedir.
- Mobil metin sıkıştırma ve aritmetik kodlama örneği
  - Aritmetik kodlama tablosu (ekrandan, 00:21:40): SPACE 1/10 $[0,00;0,10)$, A 3/10 $[0,10;0,40)$, F 1/10 $[0,40;0,50)$, H 1/10 $[0,50;0,60)$, I 1/10 $[0,60;0,70)$, M 1/10 $[0,70;0,80)$, S 1/10 $[0,80;0,90)$, T 1/10 $[0,90;1,00)$.
  - Ders sonrası not: Slaytta örnek kelime "FATIMA AS" yazıyor, ama tablodaki olasılıklar (10 karakter, H dahil, üç A) "FATIMAH AS" dizisine uyar.
  - MTF'de başlangıç listesi alfabedir; her karakterin listedeki indisi yazılır ve karakter listenin başına alınır. Tekrar eden karakterler 0 üretir; bu yüzden BWT'den sonra MTF çıktısında küçük sayılar ve sıfırlar baskın olur.
- Transformer ve LSTM ile kayıpsız sıkıştırma
  - İki sunum da aynı fikre dayanır: bir dil modeli bir sonraki sembolün olasılığını tahmin eder, aritmetik kodlayıcı bu olasılıkla kodlar. Modelin tahmini ne kadar iyiyse BPC o kadar düşer.
  - Transformer çalışmasında model, daha önce sıkıştırılmış veri üzerinden tekrar geçerek (revisit) eğitime devam eder; bu 1,33 BPC'yi 1,20 BPC'ye düşürür, ama daha çok bellek ister.
  - Bellard çalışmasında BPB tüm veri üzerinde tek geçişle (tek epoch) hesaplanır; açma hızı sıkıştırma hızından düşüktür. LSTM yavaştır ama kodu basittir ve bellek tüketimi makuldür.
  - Ders sonrası not: Sunumda CMIX'in 1,56 ile en hızlı model olduğu söylendi; tabloda 1,56 kB/s sıkıştırma hızıdır ve en yavaş değerdir (gzip -9 17.400 kB/s).
- Sismik veri sıkıştırma
  - Gönderici, eğitilmiş tahmincinin kurulum bilgisini ve veri segmentlerini alıcıya gönderir; alıcı aynı tahminciyle tahmini üretip kodlanmış artığı ekleyerek veriyi yeniden kurar (ekrandan, 01:21:50).
  - LPC, ortalama kare uydurma ile regresyon yapan doğrusal tahmincidir; karmaşık ilişkileri modelleyemez. Her iz (trace) kendi içinde 0-1 aralığına normalize edilir. Veri seti (East Texas) eğitim, doğrulama ve test için üç eşit parçaya bölünür; ölçüt SNR'dir.
  - Ders sonrası not: Sunumun sonunda kayıpsız yöntemler için "tamsayıda 2:1, float'ta 5:1" denildi; slayttaki doğru değerler tamsayı için 5:1, float için 2:1'dir (ekrandan, 01:20:00).
- Röntgen sıkıştırma metrikleri
  - PSNR'de ortalama kare hata paydadadır; PSNR büyükse hata küçüktür. SSIM (yapısal benzerlik) de büyük olduğunda daha iyidir.
  - 256×256 görüntülerde sonuçlar oranla neredeyse değişmemiş; önerilen yöntem önceki çalışmanın bulanık çıktısına göre daha net görüntü vermiş.
- BWT
  - Sıralanmış döndürmelerin ilk sütunu çıktı olarak alınır; orijinal dizinin satır numarası (5) da gönderilir. Ters dönüşümde çıktı sıralanır; her girdi karakterinin sıralı dizideki yeri SıraBul vektörünü verir. 5. konumdan başlanıp vektör izlenerek a, b, r, a, c, a, d, a, b, r, a çıkar.
- Huffman projeleri
  - Kazancın görüntüye bağlı olması: büyük beyaz alanı olan görüntüde beyaz sembol (255) 70.012 kez geçer ve 1 bitlik kod alır; bu yüzden ortalama kod uzunluğu 3,04 bite iner. Ortalama kod uzunluğu entropiye (3,013) çok yakındır, Huffman'da olması gerektiği gibi entropiden biraz büyüktür.
  - Açma sonrası orijinal dosya ile açılmış dosya bayt bayt karşılaştırılarak kayıpsızlık doğrulanır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
