# Ders 14 Çalışma Özeti

## Genel Konular

- Seminer sunumları (son hafta)
  - Bu ders de öğrenci seminer sunumlarına ayrıldı. Üç sunum yapıldı: IoT sensör verisi için ardışık veri gruplamaya dayalı sıkıştırma, dört metin sıkıştırma yönteminin (RLE, aritmetik kodlama, Punctured Elias, Goldbach kodu) karşılaştırması ve JPEG yapaylıklarını bastıran bir derin evrişimli sinir ağı (CAS-CNN).
  - Sunumlar arasında aritmetik kodlamada hangi sayının gönderileceğine dair bir soru-cevap yapıldı.
- Sunum 1: IoT verisinin ardışık veri gruplamayla sıkıştırılması
  - Çıkış noktası sensörlerin enerji tüketimidir. Sensörler çoğunlukla pille çalışır; enerjinin ortalama %80'i toplanan verinin baz istasyonuna ya da sunucuya gönderilmesinde harcanır. Bu yüzden sensörde sıkıştırma enerji tasarrufu sağlar.
  - Karşılaştırılan mevcut yöntemler: Compressive Sensing (CS; az ölçümle temsil, ama karmaşık algoritma nedeniyle bellek ve enerji ihtiyacı yüksek), Standard RBM (derin öğrenme tabanlı; eğitim sunucuda yapılır, sensörde basit ağ) ve Stacked RBM-AE (çok katmanlı, daha iyi sıkıştırma).
  - Önerilen yöntemde sıkıştırma oranı sabit değildir, veriye göre oluşur; yalnız basit işlemler kullanılır. Dayanağı: sensör verisi ardışık değerler üretir ve ardışık değerler arasındaki fark çoğu zaman ihmal edilebilir düzeydedir.
  - İhmal edilebilir eşik, sunucudaki eğitim verisinden RMSSD (ardışık farkların karelerinin ortalamasının karekökü) olarak hesaplanır (ekrandan, 00:09:45): $RMSSD = \sqrt{\frac{1}{N-1}\sum (v_i - v_{i-1})^2}$.
  - Karar kuralı: $|v_i - v_{i-1}| \le RMSSD$ ise değer öncekiyle gruplanır, değilse yeni değer olarak saklanır. Gönderilen her kayıt bir değer ve o değerin kaç kez tekrarlandığı (occurrence) bilgisidir.
  - Açma (ekrandan, 00:10:50): her sıkıştırılmış değer, occurrence sayısı kadar art arda listeye eklenir. Yöntem kayıplıdır; grup içindeki küçük farklar geri gelmez.
  - Deney: Intel Lab kablosuz sensör ağı verisi (sıcaklık, nem, ışık, voltaj); örnek olarak sıcaklık kullanıldı. Ölçütler (ekrandan, 00:11:55): CR (orijinal boyut / sıkıştırılmış boyut), PRD (yüzde karesel ortalama fark, yani kayıp), QS = CR / PRD.
  - Sonuçlar (ekrandan, 00:12:45): CS, Standard RBM ve Stacked RBM-AE'de CR 10'da sabit, önerilen yöntemde yaklaşık 11. PRD grafiğinde CS yaklaşık 38, Standard RBM yaklaşık 33, Stacked RBM-AE yaklaşık 10, önerilen yöntem sıfıra çok yakın. QS logaritmik ölçekte önerilen yöntemde çok daha büyük.
  - Enerji (ekrandan, 00:14:25): orijinal veri / önerilen yöntem ortalama tüketimi Wi-Fi 509,9 / 184,48 mW, 3G 1974,98 / 976,29 mW, LTE 1871,78 / 1367,95 mW. 3G ve LTE'de sabit bileşen $\beta$ büyük olduğundan oransal kazanç daha küçüktür.
- Sunum 2: Metin sıkıştırma yöntemlerinin karşılaştırılması
  - 40, 80 ve 120 bitlik (5, 10, 15 bayt) üç veri RLE, aritmetik kodlama, Punctured Elias ve Goldbach koduyla sıkıştırıldı.
  - RLE: veri (sayaç, değer) çiftlerine dönüştürülür. Örnek (ekrandan, 00:24:10): kalp şekilli piksel görüntüsü, her piksel 1 bayt sayılınca 81 bayt; 22 run, her run 2 bayt, toplam 44 bayt.
  - Aritmetik kodlama: olasılıklar bulunur, [0,1) aralığı olasılıklara göre bölünür, her sembolde seçilen aralık yeniden bölünür. Örnek "HEY!!" (ekrandan, 00:25:10): P(H)=P(E)=P(Y)=1/5, P(!)=2/5.
  - Elias gamma ve Punctured Elias (ekrandan, 00:25:58): Elias gamma önek (prefix) kullanır; Punctured Elias'ta sayının ikili hali ters yazılır ve önekler kısaltılır. Bazı değerlerde Elias'tan kısa, bazılarında uzundur. Slayttaki not: değer > 127 ise ortalama 3,15'ten 3,10 bit/bayta.
  - Goldbach kodu (ekrandan, 00:27:20; 00:30:00): "2'den büyük her çift sayı iki asalın toplamıdır" sanısına dayanır. Karakterler frekansa göre sıralanır, n. sıradaki karakter için $2(n+3)$ iki asalın toplamı yazılır. Asallar 3, 5, 7, 11, 13, 17, ... sırasıyla bit konumlarıdır; toplamda kullanılan asalların yerine 1, diğerlerine 0 yazılır ve kod ikinci 1'de biter. Her kod sözcüğünde tam iki 1 vardır, hepsi 1 ile biter, bu yüzden önek koşulu sağlanır.
  - "GOOD MORNING" örneği: 12 karakter × 8 bit = 96 bit, Goldbach koduyla 41 bit.
  - Deney sonuçları (ekrandan, 00:31:58): 40 bit için RLE 80, aritmetik 32, Punctured Elias 64, Goldbach 14 bit; 80 bit için 64, 56, 75, 28; 120 bit için 240, 65, 88, 49. Goldbach her deneyde en küçük çıktıyı verdi, ikinci sırada aritmetik kodlama; RLE iki deneyde veriyi büyüttü.
- Sunum 3: CAS-CNN, görüntü sıkıştırma yapaylıklarını bastıran derin evrişimli ağ
  - Kayıplı sıkıştırma (özellikle yüksek oranlarda JPEG) bloklaşma gibi yapaylıklar üretir. Bunlar hem görsel kaliteyi hem de düşük seviyeli görme algoritmalarını olumsuz etkiler.
  - Makalede 12 katmanlı bir evrişimli ağ önerilir. Önceki yöntemler: SA-DCT, BM3D, AR-CNN (JPEG yapaylıkları için eğitilmiş, transfer öğrenme kullanan ağ), L4/L8.
  - Mimari (ekrandan, 01:00:00): dört aşama; kanal sayısı 1'den 128'e, sonra 256'ya çıkar; çözünürlük her aşamada 2×2 alt örneklemeyle yarıya iner. Alt seviyedeki çıktılar üst örneklenip (US) daha yüksek çözünürlüklü özelliklerle birleştirilir (concat). Her ölçekte çıktı alınır; kayıp, çıktıda MSE ve ölçeklerde eşit ağırlıklı çok ölçekli MSE kaybıdır.
  - Ölçütler (ekrandan, 01:01:50): MSE, PSNR (dB, maksimum sinyal değerine göre normalize MSE), IPSNR (PSNR'ın bozuk girdiye göre artışı) ve SSIM (parlaklık, kontrast ve yapı benzerliği terimlerinin çarpımı).
  - Eğitim: ImageNet 2013 verisi, 120×120 kesitler, yalnız parlaklık (Y) kanalı; ilk ağ kalite faktörü 20 için eğitilip diğer kalite faktörlerine başlangıç olarak kullanıldı. Değerlendirme LIVE1 verisinde yapıldı.
  - Sonuç (ekrandan, 01:05:15): bütün kalite faktörlerinde önerilen ağ en yüksek PSNR'ı verdi; örneğin QF 10'da JPEG 27,77 dB, AR-CNN 29,13 dB, önerilen ağ (ince ayarlı) 29,44 dB.
- Aritmetik kodlamada gönderilecek sayı (soru-cevap)
  - Son aralık $[low, high)$ içindeki herhangi bir sayı gönderilebilir. $high$ alınamaz, çünkü aralığın üst ucu açıktır.
  - Kitaplarda ve kodlarda genelde $low$ alınır. Sayı float olarak değil, noktadan sonraki basamakları tamsayı gibi düşünülerek kodlanır; açarken başında "0." olduğu bilinir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kayıplı ve kayıpsız ayrımı sunumda açıkça söylenmeli
  - IoT sunumunda hoca, veriyi azaltan algoritmanın ne olduğunu ve orijinalin geri gelip gelmediğini sordu. Gruplanan değerler tek değerle temsil edildiği için yöntem kayıplıdır; açarken değer, grup sayısı kadar tekrarlanır.
- Tablodaki her sütunun bir anlamı olmalı
  - Goldbach tablosundaki "Primes" sütununun kod sözcüğünü nasıl belirlediğini hoca sınıfla birlikte çözdü: asallar bit konumlarıdır, kullanılan asalların yerine 1 yazılır.
- Deney verisinin türü sonucu belirler
  - RLE'nin kötü çıkması, deney verisinin metin olmasıyla açıklanabilir; metinde aynı karakterin art arda gelmesi azdır. Hoca, bir yöntemi değerlendirirken o yöntemin başarısız olacağı bilinen veri tipini almanın doğru olmadığını, verinin içeriğinin makalede açıklanması gerektiğini vurguladı.
- Aritmetik kodlamada aralığın üst ucu dahil değildir
  - Aralıktaki herhangi bir değer seçilebilir ama maksimum alınamaz; genelde $low$ kullanılır.

## Kısa Tekrar Notları

- IoT ardışık veri gruplama: eşik RMSSD; $|v_i - v_{i-1}| \le RMSSD$ ise grupla; (değer, tekrar sayısı) gönder; kayıplı.
- CR = orijinal / sıkıştırılmış; PRD = yüzde kayıp; QS = CR / PRD.
- Enerjinin çoğu iletimde harcandığı için sıkıştırma pil ömrünü uzatır; sabit enerji ($\beta$) büyükse kazanç oransal olarak azalır.
- RLE: (sayaç, değer); tekrarı az olan metinde veriyi büyütebilir.
- Aritmetik kodlama: [0,1) aralığı olasılıklara göre art arda bölünür; son aralıktan genelde $low$ gönderilir.
- Goldbach kodu: n. sıradaki karakter için $2(n+3) = p + q$; $p$ ve $q$'nun konumuna 1; her kodda iki 1 var ve kod 1 ile biter.
- "GOOD MORNING": 96 bit → 41 bit.
- CAS-CNN: 12 katmanlı, çok ölçekli, JPEG yapaylık bastırma; ölçütler PSNR, PSNR-B, SSIM.

## Detaylı Açıklamalar

- IoT sensör verisi ardışık değerlerden oluştuğu için, birbirine çok yakın değerlerin tek tek iletilmesinin sunucu tarafında bir anlamı yoktur. Önerilen yöntem bu değerleri tek bir kayıtta toplar. Sunan öğrencinin örneği: 100 ardışık değerden ilk 30'u birbirinden RMSSD'den küçük farklarla değişiyorsa (23,005 ve 23,004 gibi), bu 30 değer tek bir değer ve "30 tane" bilgisiyle gönderilir. Sunucu açarken aynı değeri 30 kez yazar; böylece değer sayısı korunur ama küçük farklar kaybolur. Hoca bunu görüntü sıkıştırmada renk sayısının azaltılmasına benzetti: veri kayıplıdır, ama boyut (öğe sayısı) aynı kalır.
  > **Ders sonrası not:** Slayttaki "Algorithm 1 Calculate RMSSD" sözde kodu (ekrandan, 00:09:45) farkların karesini ve karekökünü değil, mutlak farkların ortalamasını hesaplıyor; yani formülle uyuşmuyor. Ayrıca formülde toplam $i=1$'den başlıyor, $v_0$ olmadığı için büyük olasılıkla $i=2$'den başlaması gerekir.
- Metin karşılaştırmasında Goldbach kodu en iyi sonucu verdi, ama hoca deneydeki 40, 80, 120 bitlik verilerin içeriğinin makalede açıklanmadığını sorguladı. Metin verisinde art arda tekrar az olduğundan RLE'nin başarısız olması beklenir; RLE'nin değerlendirileceği bir deneyde ancak tekrarlı veri de kullanılmalıdır.
  > **Ders sonrası not:** "GOOD MORNING" tablosunda boşluk karakterinin ASCII kodu 83 olarak yazılmış (ekrandan, 00:30:00); doğrusu 32'dir (83 'S' harfinin kodudur). 8 bit sayıldığı için toplam 96 bit değişmez.
- CAS-CNN sunumunda hoca, makalenin standart CNN üzerinde tam olarak neyi değiştirdiğinin sunumdan anlaşılmadığını belirtti; sunan öğrenci de katmanlar arasındaki aktivasyonla ilgili değişikliği açıklayamadı. Mimari şeklinden çıkan fark, çok ölçekli çıktılar ve alt seviye özelliklerin üst seviyeyle birleştirilmesidir.
- Aritmetik kodlamada hoca, float işlemlerin zorluğu nedeniyle derste ilk dört basamağı tamsayı gibi alıp kaydırarak işlem yapılan bir sürüm gösterdiğini hatırlattı; yazılmış aritmetik kodlayıcıların çoğu bu yöntemi kullanır. 0,8125 gibi bir sayıda aslında 8125'in bit karşılığı kullanılır, açarken sayının "0." ile başladığı bilinir.
  > **Ders sonrası not:** Hoca "küçük olanın bit sayısı her zaman büyük olandan daha azdır ya da eşittir" dedi; bu, basamakları tamsayı olarak kodlama bakış açısında geçerlidir. Sayı ikili kesir olarak gönderilirse, aralıktaki en kısa ikili kesir büyük olasılıkla $low$ değil aradaki bir değer olabilir; öğrencinin sorusu da buna yönelikti.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
