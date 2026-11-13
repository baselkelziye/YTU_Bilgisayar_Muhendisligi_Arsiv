# Ders 5 Çalışma Özeti

## Genel Konular

- Seminer sunumları
  - Bu ders öğrenci seminer sunumlarına ayrıldı. Her sunumda bir öğrenci veri sıkıştırmayla ilgili yayımlanmış bir makaleyi yaklaşık 15 dakikada anlattı; hoca sunum sırasında ve sonrasında sorular sordu.
  - Altı sunum yapıldı: blok tabanlı neredeyse kayıpsız görüntü sıkıştırma, dört metin sıkıştırma yönteminin (RLE, aritmetik kodlama, patlak Elias kodu, Goldbach kodu) karşılaştırılması, dil modeliyle metin sıkıştırma, veri sıkıştırma literatür taraması, iyileştirilmiş RLE (MRLE/iMRLE) ve CNN ile JPEG sıkıştırma kusurlarının bastırılması.
- Sunum 1: Huffman kullanan neredeyse kayıpsız görüntü sıkıştırma
  - Görüntü 2×2, 4×4 ya da 8×8 bloklara bölünür, bloklara matematiksel işlemler uygulanır, sonunda Huffman kodlaması yapılır. Amaç kayıplı ve kayıpsız sıkıştırmanın avantajlarını birlikte kullanmaktır (ekrandan, 00:10:00).
  - Adımlar: bloğun en küçük değeri bulunur ve bloktaki bütün değerlerden çıkarılır; tek değerlerden 1 çıkarılır; bütün değerler 2'ye bölünür; sonuca Huffman uygulanır (ekrandan, 00:15:15).
  - Yöntem gri tonlu ve renkli görüntülerde denenmiştir. Ölçütler MSE ve PSNR'dir; Huffman kayıpsız olduğundan MSE'si 0, PSNR'si sonsuzdur.
  - Sıkıştırma oranı (CR) çıktı boyutu / girdi boyutudur; küçük olması iyidir. Renkli görüntülerde ortalama CR: önerilen 2×2 0,94, 4×4 0,54, 8×8 0,48, Huffman 0,74 (ekrandan, 00:20:05).
- Sunum 2: RLE, aritmetik kodlama, patlak Elias kodu ve Goldbach kodu ile metin sıkıştırma
  - Test verisi 5, 10 ve 15 byte'lık metinlerdir. Hoca bu kadar küçük metinlerde başlığın sıkıştırılmış veriden büyük olacağını belirtti.
  - RLE: arka arkaya gelen semboller tekrar adedi ve sembol olarak kodlanır. Tekrarı az olan veride boyutu büyütebilir. Kaçış kodlu örnek: `8 8 8 8 8 96 12 45 45 45 45` → `255 5 8 96 12 255 4 45` (ekrandan, 00:28:50).
  - Aritmetik kodlama: bütün mesaj 0 ile 1 arasında tek bir sayıyla kodlanır; aralık her sembolde sembolün olasılığı oranında daralır (ekrandan, 00:29:50).
  - Patlak (punctured) kod: hata düzeltme bitleri eklenmiş bir koddan bu bitlerin bir kısmının atılmasıdır.
  - Patlak Elias kodu (P1): sayının ikilik karşılığı ters çevrilir; her 1 için bir 1 yazılıp sonuna 0 eklenen önek bu ters çevrilmiş değerin önüne konur. 13 → 1101 → 1011 → önek 1110 → kod 11101011 (ekrandan, 00:32:45).
  - Elias gamma kodu: ikilik karşılığın önüne (bit sayısı − 1) tane 0 konur. 13 → 0001101 (ekrandan, 00:33:40). Baştaki sıfır sayısı sayının aralığını gösterir; önek (prefix) koddur.
  - Goldbach kodları: her çift sayının iki asal sayının toplamı olarak yazılabileceği varsayımına (Goldbach konjektürü, kanıtlanmamıştır) dayanır. G0, G1 ve G2 sürümleri anlatıldı (ekrandan, 00:36:30; 00:39:10).
  - Sonuç (40 bitlik girdi): RLE 80 bit (%200), aritmetik kodlama 32 bit (%80), patlak Elias kodu 64 bit (%160), Goldbach kodu 14 bit (%35) (ekrandan, 00:43:00).
- Sunum 3: Dil modelleme yoluyla metin sıkıştırma
  - 2016 tarihli, Stanford NLP grubuna ait bir çalışma. Dil modeli kelime ya da kelime dizileri üzerindeki olasılık dağılımıdır; n-gram n tane karakter ya da kelimeden oluşan dizidir; korpus metin koleksiyonudur.
  - Perplexity (çapraşıklık) $= 2^{H(X)}$. Düşük perplexity veren dil modeli, iyi sıkıştırmaya izin veren düşük entropili dağılım demektir (ekrandan, 00:50:00).
  - Kelimeler eğitilmiş modelden çıkarılan unigram, bigram ve trigram olasılıklarına göre kurulan Huffman ağaçlarıyla kodlanır. Kelime bulunamazsa bilinmeyen (unknown) token yazılıp unigram modeline, orada da yoksa sabit Huffman kodlu karakter kodlamasına geri dönülür (back-off).
  - Uzantı önerileri: belgelerin konuya göre (spor, siyaset, ekonomi) kategorize edilmesi ve kayan bağlam penceresi. Bunlar makalede denenmemiş, yalnız önerilmiştir.
  - Eğitim cümlesi sayısı arttıkça sıkıştırılmış dosya boyutu düşer, ama yaklaşık 10.000 cümleden sonra eğri düzleşir (ekrandan, 01:00:00).
- Sunum 4: Veri sıkıştırma literatür taraması (2018 tarihli bir derleme)
  - Sıkıştırma dört eksende sınıflandırılmıştır: veri kalitesi (kayıplı/kayıpsız), kodlama şeması (Huffman, aritmetik kodlama, LZW, RLE, Burrows-Wheeler, wavelet), veri tipi (metin, görüntü, ses, video) ve uygulama (kablosuz sensör ağları, tıbbi görüntü, özel uygulamalar) (ekrandan, 01:10:00).
  - Gelecek yönleri: dosya formatından bağımsız sıkıştırma, sürekli tonlu görüntülerin yanında ayrık tonlu görüntüler ve makine öğrenmesiyle sıkıştırma.
- Sunum 5: Mespotine RLE (MRLE) ve iyileştirilmiş MRLE (iMRLE)
  - MRLE, RLE'nin çıktıyı orijinalden büyük yapma sorununu, her karakter için bir "Comp-Bit" (sıkıştırılabilir bit) belirleyerek çözer (ekrandan, 01:21:15).
  - Her karakterin her tekrar grubu bir sayaç değeri alır: 1 tekrar −1, 2 tekrar 0, 3 tekrar 1, 4 tekrar 2 ... Toplam 0'dan büyükse karakter sıkıştırılabilir (Comp-Bit 1), değilse sıkıştırılamaz (Comp-Bit 0).
  - Örnek `DDAAABCAACBDAAADBBBBB` için Comp-Bit listesi 1100 (A, B, C, D sırasıyla), sıkıştırılmış veri `DDA3B1CA2CB1DA3DB5` olur: 18 × 8 = 144 bit + 4 Comp-Bit = 148 bit; orijinal 21 × 8 = 168 bit (ekrandan, 01:23:55).
  - iMRLE, tekrarı az olan veride büyüyen Comp-Bit listesini küçültür: 256 bitlik Comp-Bit listesi 32 byte'tan 6 byte'a iner (ekrandan, 01:26:45).
- Sunum 6: CNN ile JPEG sıkıştırma kusurlarının (artefakt) bastırılması
  - Yüksek sıkıştırma oranlarında JPEG görüntüde görsel kusurlar oluşur; bu kusurları gidermek için 12 katmanlı, hiyerarşik atlama bağlantılı (skip connection) ve çok ölçekli kayıp fonksiyonlu bir CNN önerilmiştir.
  - Ölçütler: MSE, PSNR $= 10\log_{10}(1/\text{MSE})$ (ekrandan, 01:40:00), SSIM ve blok etkisi faktörünü ekleyen PSNR-B.
  - Sonuç: PSNR'de sıradan JPEG'e göre 1,79 dB'e, önceki en iyi CNN'e göre 0,36 dB'e kadar iyileşme; bir kalite faktörü için eğitilen ağ başka kalite faktörlerinde de iyi çalışır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sıkıştırma oranı çıktı / girdi oranıdır
  - %100'ün üzerindeki bir oran sıkıştırma değil büyümedir. Hoca, 40 bitin 80 bite çıkmasının sıkıştırma sayılamayacağını söyledi.
- Bir yöntemin her adımının gerekçesi sorgulanmalıdır
  - Hoca birinci sunumda tek değerlerden 1 çıkarmanın amacını sordu; renk değerinden 1 çıkarmanın nasıl bir avantaj sağladığını anlamak istedi.
- Çok küçük test verileri yanıltıcıdır
  - 5 byte'lık bir metin sıkıştırılınca başlık verinin kendisinden büyük olur.
- Sıkıştırma ile makine öğrenmesinin ilişkisi açık değildir
  - Hoca literatür taraması sunumunda makine öğrenmesinin sıkıştırmada nereye oturtulduğunu sordu ve bunun için ayrıca anahtar kelime araması yapılmasını önerdi.
- Patlak Elias ve Goldbach kodları
  - Hoca bu sunumla iki yeni önek kod öğrenildiğini vurguladı.

## Kısa Tekrar Notları

- Neredeyse kayıpsız blok yöntemi: en küçüğü çıkar, tek değerden 1 çıkar, 2'ye böl, Huffman uygula.
- CR = çıktı / girdi; küçük CR daha iyi sıkıştırma demektir.
- Elias gamma: (bit sayısı − 1) tane 0 + ikilik değer. $13 \to 0001101$.
- Patlak Elias (P1): 1 sayısı kadar 1, ardından 0, ardından ters çevrilmiş ikilik değer. $13 \to 11101011$.
- Goldbach G0: $2(n+3)$ iki asala ayrılır, bu asalların bit konumlarına 1 yazılır; her kodda iki tane 1 vardır.
- Goldbach G1: $2n = p_i + p_j$, kod $\gamma(i)\,\gamma(j-i+1)$.
- Perplexity $= 2^{H}$; düşük perplexity, düşük entropi ve iyi sıkıştırma.
- MRLE Comp-Bit: 1 tekrar −1, 2 tekrar 0, 3 tekrar +1 ...; toplam > 0 ise sıkıştırılabilir.
- PSNR $= 10\log_{10}(1/\text{MSE})$ (normalize edilmiş sinyal için).

## Detaylı Açıklamalar

- **Neredeyse kayıpsız blok yöntemi.** Slayttaki 8×8 örnekte (ekrandan, 00:15:15) A bloğunun en küçük değeri 188'dir. 188 − 188 = 0, 231 − 188 = 43, 195 − 188 = 7 gibi B tablosu elde edilir. Tek değerlerden 1 çıkarılınca 43 → 42, 7 → 6, 1 → 0 olur (C tablosu). 2'ye bölününce değerler 0, 21 ve 3'e iner (D tablosu). D'de yalnız üç farklı değer kaldığı için Huffman çok kısa kodlar verir; en sık değer 0'dır (python ile sayıldı: 33 tane 0, 28 tane 21, 3 tane 3). E tablosunda bu üç değer 0, 1 ve 2 simgeleriyle gösterilmiştir.
  - Soru: Tek değerlerden 1 çıkarmanın avantajı ne? Cevap: Sunan öğrenciye göre değerlerin 2'ye tam bölünebilmesi içindir; makale bunu açıklamamıştır.
  - Soru: Görüntüler 256 renkli palet mi, 24 bitlik mi? Cevap: Yöntem hem gri tonlu hem renkli görüntülerde uygulanmıştır.
  - Ders sonrası not: Sunumda 2×2 bloğun en iyi olduğu söylendi (00:22:25). Tablo 5'e göre (ekrandan, 00:20:05) en iyi sıkıştırma oranı 8×8 blokta (0,48), en düşük MSE ise 2×2 bloktadır; 2×2'nin ortalama CR'si (0,94) Huffman'dan (0,74) bile kötüdür.
  - Ders sonrası not: Slayttaki "%26 daha fazla tasarruf" 0,74 − 0,48 = 0,26 farkıdır, yani CR'deki mutlak farktır; Huffman'ın çıktısına göre oransal azalma yaklaşık %35'tir (python ile kontrol edildi).
- **Aritmetik kodlama örneği.** Olasılıklar a = 0,2, b = 0,3, c = 0,1, d = 0,4 (aralıklar [0; 0,2), [0,2; 0,5), [0,5; 0,6), [0,6; 1)) (ekrandan, 00:29:50). `b d a b` dizisinde aralık sırasıyla [0,2; 0,5), [0,38; 0,5), [0,38; 0,404), [0,3848; 0,392) olur (python ile doğrulandı).
  - Ders sonrası not: Sunumda d'nin %40, b'nin %30, c'nin %10 olduğu söylendi; a'nın olasılığı söylenmedi, slayta göre 0,2'dir.
- **Goldbach G0.** Asal indeks tablosu 3, 5, 7, 11, 13, 17, 19, 23 ile başlar. 3 için $2(3+3) = 12 = 5 + 7$; 3, 5, 7 konumlarına 0, 1, 1 yazılır ve kod 011 olur (ekrandan, 00:36:30). 6 için $18 = 7 + 11$, kod 0011 (ekrandan, 00:37:20).
  - Ders sonrası not: Slayttaki tabloda $n = 8$ için $22 = 5 + 17$ ve kod 0100001 yazıyordu (ekrandan, 00:37:20). Sütunlara (3, 5, 7, 11, 13, 17) göre bu kod 010001 olmalıdır; slayttaki 7 bitlik kod büyük olasılıkla bir yazım hatasıdır.
- **Goldbach G1.** Fikir: sayı büyüdükçe iki asal birbirine yakın kalır (örneğin 1000 = 497 + 503 diye söylendi), bu yüzden ikinci indeks yerine fark kodlanır. İndeks tablosunda 1 de yer alır (1, 3, 5, 7, 11 ...). 8 = 3 + 5, indeksler (2, 3), çift (2, 2), kod 010 010; 16 = 5 + 11, indeksler (3, 5), çift (3, 3), kod 011 011 (ekrandan, 00:39:10; python ile doğrulandı). G1 yalnız çift sayılar içindir.
  - Ders sonrası not: Sunumda 1000 için 497 + 503 örneği verildi (00:38:00). 497 = 7 × 71 asal değildir; 503 asaldır, ama 497 ile toplamı 1000 eder ve örnek büyük olasılıkla başka bir çift (örneğin 491 + 509) içindi.
- **Goldbach G2.** 1 ve 2 için sabit kodlar vardır; çift sayılar G1 benzeri bir yöntemle, asal tek sayılar Elias gamma koduna 1 eklenerek, asal olmayan tek sayılar ise sayının bir eksiğinin G2 kodunun başına 1 eklenerek kodlanır.
  - Ders sonrası not: Sunumda 11'in Elias gamma kodu "00101" diye söylendi (00:41:27). 11 = 1011 dört bitlik olduğundan gamma kodu 0001011'dir; 00101, 5'in gamma kodudur (python ile kontrol edildi).
- **Metin sıkıştırma sonuçları.** Makalede sıkıştırma olmayıp büyüme olan yöntemlerin oranı başına eksi konarak gösterilmiştir (grafikte RLE −200, patlak Elias −160) (ekrandan, 00:43:00). Hoca bunun anlamlı olmadığını, oran %100'ü geçiyorsa sıkıştırma olmadığını söyledi.
- **Dil modeliyle sıkıştırma sonuçları.** Sunan öğrencinin hesabına göre önerilen yöntemin sıkıştırma oranı yaklaşık 0,36, gzip yaklaşık 0,35, bzip2 yaklaşık 0,26'dır. Ayrıca perplexity yükseldikçe sıkıştırılmış dosyanın büyüdüğü gösterilmiştir.
  - Soru: Grafikte düşüşün bittiği nokta kaç cümleye karşılık geliyor? Cevap: Yaklaşık 10.000 cümle; en sık kullanılan trigramlar az sayıdadır, sonrakiler seyrek görüldüğü için eğri düzleşir.
- **MRLE çözme.** Comp-Bit'i 0 olan karakter olduğu gibi okunur. Comp-Bit'i 1 olan karakterden sonraki değer tekrar sayısıdır; karakter o kadar kez yazılır.
  - MRLE'nin dezavantajı: tekrar içermeyen `ABCDE` için 40 bitlik veriye 5 Comp-Bit eklenir ve 45 bit olur.
- **iMRLE örneği.** 256 bitlik Comp-Bit listesi (yalnız ilk ve son bit 1) 8 bitlik tamsayılara çevrilir: [128, 0, ..., 0, 1] (32 değer). Sıfır olmayanlardan indexVal = [128, 1] oluşturulur. Sıfır olmayan her değer 1 yapılarak 32 bitlik cmpBitList1 elde edilir; bu 4 byte'lık cmpBitList2 = [128, 0, 0, 1] olur. Birleştirme: [128, 0, 0, 1, 128, 1]; ilk 4 byte başlık, kalanlar indekstir. Sonuç 32 byte yerine 6 byte'tır (ekrandan, 01:26:45).
- **CNN mimarisi.** Kanal sayısı 1'den 128'e, sonra 256'ya çıkar; 2×2 adımlı (stride) konvolüsyonlar ve 2×2 ortalama havuzlama ile çözünürlük düşürülür. Yüksek çözünürlüklü ara sonuçlar daha önceki katmanların özellikleriyle birleştirilir (atlama bağlantıları); ara katmanlarda düşük çözünürlüklü çıktılar üretilip en yakın komşu enterpolasyonuyla büyütülerek özellik haritasına eklenir. Eğitim ImageNet görüntülerinden 120×120 piksellik kesitlerle, test LIVE1 veri setinin 29 görüntüsüyle yapılmıştır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
