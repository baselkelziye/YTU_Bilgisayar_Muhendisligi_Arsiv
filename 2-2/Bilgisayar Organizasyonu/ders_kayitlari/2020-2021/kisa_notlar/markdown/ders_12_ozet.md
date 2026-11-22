# Ders 12 Çalışma Özeti

## Genel Konular

- Direct mapped önbellekte adres bölümleme (address partitioning)
  - Adres en düşük anlamlıdan başlayarak byte offset, word offset, index ve tag alanlarına bölünür. Byte offset, word içindeki byte'ı; word offset, blok (satır) içindeki word'ü; index, önbelleğin hangi satırına gidileceğini gösterir. Tag, aynı satıra düşen farklı adresleri ayırt eden kalan yüksek anlamlı bitlerdir (ekrandan, 00:05:00).
  - Word genişliği mimariye bağlıdır: 8086'da 16 bitlik veri yolu olduğundan word 2 byte, 32 bitlik mimaride word 4 byte'tır.
  - Her satırda tag ile birlikte bir valid biti tutulur. Önbellek ilk açıldığında içindeki değerler rastgeledir; tag şans eseri tutsa bile valid biti 0 ise veri geçerli değildir. Arama sırası: önce valid bitine, sonra tag eşleşmesine bakılır.
  - Direct mapped yapıda farklı adresler hep aynı index'e düşerse önbelleğin geri kalanı boş kalır; bu yapının temel zayıflığıdır.
- Blok genişliği ile miss rate ilişkisi (ekrandan, 00:10:00)
  - Blok küçükken uzamsal yerellikten (spatial locality) yeterince yararlanılmaz ve miss rate yüksektir. Blok büyüdükçe miss rate bir optimuma kadar düşer.
  - Blok çok büyürse sabit kapasitede satır sayısı azalır, aynı index'e düşen başka bir erişimin mevcut bloğu bozma olasılığı artar; zamansal yerellik (temporal locality) zarar görür ve miss rate yeniden yükselir.
- Örnek: 16 KB, 4 word'lük bloklu direct mapped önbellek, 32 bit mimari (ekrandan, 00:15:00 ve 00:20:00)
  - Word = 4 byte, blok = $4 \times 4 = 16$ byte, satır sayısı $= 16 \cdot 2^{10} / 16 = 2^{10}$.
  - Index $= \log_2 2^{10} = 10$ bit, word offset $= \log_2 4 = 2$ bit, byte offset $= \log_2 4 = 2$ bit, tag $= 32 - 14 = 18$ bit.
  - `0000000AH` adresi: tag 18 tane 0, index 10 tane 0 (satır 0), word offset `10` (2. word), byte offset `10` (2. byte).
- Örnek: aynı önbellekte erişim dizisi (ekrandan, 00:25:00 ve 00:30:00)
  - Adresler: `0x00000014`, `0x0000001C`, `0x00000034`, `0x00008014`; önbellek boş başlar.
  - `0x14`: index 1, valid 0, miss; 10, 14, 18, 1C adreslerindeki A, B, C, D word'leri satır 1'e çekilir, tag 0 yazılır.
  - `0x1C`: index 1, valid 1, tag 0 eşleşir, hit (D word'ünün en düşük byte'ı).
  - `0x34`: index 3, valid 0, miss; E, F, G, H satır 3'e çekilir.
  - `0x8014`: index 1, tag 2, satırdaki tag 0 ile uyuşmaz, miss; satır 1'deki A, B, C, D atılır, yerine I, J, K, L yazılır, tag 2 olur.
  - Sonuç: 3 miss, 1 hit.
- Önbellek erişiminin dört durumu
  - Cache loading: önbellek boşken (valid bitleri 0) ilk kez veri getirilmesi.
  - Cache miss: aranan veri önbellekte yok, bellekten getirilir.
  - Cache hit: aranan blok önbellekte var.
  - Tag uyuşmazlığıyla oluşan miss sonucunda bloğun değiştirilmesi (replacement).
- Vektör çarpımı örneği ve thrashing (ekrandan, 00:35:00 ve 00:40:00)
  - `dot_prod` fonksiyonu iki 1024 elemanlı `float` dizinin elemanlarını çarpıp toplar. Makine: 64 KB direct mapped önbellek, satır 16 byte. Slayttaki performans: iyi durum 24 çevrim/eleman, kötü durum 66 çevrim/eleman.
  - Bir satıra 4 float (4 byte) sığar; x[0] okununca x[0..3] birlikte gelir.
  - İyi durum (x ve y farklı satırlara düşer): her 8 okumada 2 miss, miss rate $2/8 = 1/4$.
  - Kötü durum (x[i] ile y[i] aynı satıra düşer): her okuma diğerinin bloğunu siler, 8 okumada 8 miss, miss rate %100.
- Ortalama erişim süresi (ekrandan, 00:45:00)
  - $h$ hit oranı, $m = 1 - h$ miss oranı, $t_c$ önbellek, $t_m$ bellek erişim süresi. Miss durumunda veri önce önbelleğe getirilip sonra oradan okunur: $t_a = h\,t_c + m(t_m + t_c) = t_c + (1-h)\,t_m$.
  - Örnek: $h = 0.85$, $t_m = 50$ ns, $t_c = 5$ ns ise $t_a = 5 + 0.15 \times 50 = 12.5$ ns. Önbellek olmasaydı her erişim 50 ns sürerdi.
- İki seviyeli önbellek örneği (ekrandan, 00:50:00)
  - L1 hit süresi 1 çevrim, L1 miss rate %5, L2 hit süresi 5 çevrim, L2 miss rate %15, L2 miss penalty (bellekten L2'ye getirme) 100 çevrim.
  - Önce L2 ve bellek tek blok gibi düşünülür: $t_{a,L2} = 5 + 0.15 \times 100 = 20$ çevrim (L1 miss penalty).
  - Sonra $t_a = 1 + 0.05 \times 20 = 2$ çevrim. 100 çevrimlik bellek erişimi ortalama 2 çevrime iner.
- Fully associative önbellek
  - Adreste index alanı yoktur; bir blok önbelleğin herhangi bir satırına yerleşebilir, satırlar arasında öncelik yoktur.
  - Arama için bütün satırların tag'leri referans adresinin tag'iyle karşılaştırılır (donanımda paralel). "Yok" diyebilmek için tüm satırlara bakmak gerekir.
  - Örnek: 16 KB, blok 16 byte, 32 bit: offset 4 bit (2 bit word, 2 bit byte), tag 28 bit. Satır sayısını bulmaya gerek yoktur.
  - Boş satır varsa yeni blok oraya konur; doluysa değiştirme politikası (FIFO, LRU, random) gerekir.
- Set associative önbellek (ekrandan, 01:25:00)
  - Direct mapped ile fully associative'in birleşimidir. Bir satırda (set) birden fazla blok (way) bulunur; aynı satırdaki bloklar kendi içinde fully associative, satırlar birbirine göre direct mapped çalışır.
  - Örnek: 16 KB, 4-way, blok 16 byte, 32 bit: bir satır $4 \times 16 = 64$ byte, satır sayısı $2^{14}/2^6 = 2^8 = 256$, index 8 bit, word offset 2 bit, byte offset 2 bit, tag 20 bit.
  - Arama: index ile satıra gidilir, o satırdaki 4 way'in tag'i karşılaştırılır. Fully associative'deki 1024 karşılaştırma yerine yalnız 4 karşılaştırma yapılır.
  - Değiştirme yalnız o satırın blokları arasında yapılır.
- Değiştirme (replacement) politikaları (ekrandan, 01:30:00)
  - Direct mapped'te ayrı bir politika yoktur; index hangi satırı gösteriyorsa o satır değiştirilir.
  - Optimal: gelecekte en uzun süre kullanılmayacak blok atılır (geleceği bilmeyi gerektirir).
  - LRU (least recently used): en uzak geçmişte erişilen blok atılır; gerçeklemesi zordur.
  - FIFO: önbelleğe ilk konan blok atılır; gerçeklemesi kolaydır. İlk konan blok, en az yakın zamanda kullanılan olmak zorunda değildir.
  - Random: rastgele bir blok atılır; gerçeklemesi daha da kolaydır.
- Yazma politikaları ve tutarlılık (consistency)
  - Write-through: store işleminde önbellek ve bellek aynı anda güncellenir. Bellek her zaman önbellekle tutarlıdır, ama her yazmada belleğe gidildiği için yavaştır (ekrandan, 01:35:00).
  - Write-back: yalnız önbellek güncellenir, satırın dirty biti 1 yapılır. Dirty biti 1 olan satır değiştirilecekken önce bellek güncellenir. Daha hızlıdır ama ek kontrol ister.
- Write-through ve write-back örneği (ekrandan, 01:40:00 ve 01:45:00)
  - 16 byte'lık bellek, 2 satırlı fully associative önbellek, blok 2 byte (offset 1 bit, tag = adres/2), LRU.
  - Komutlar: `Ld R1 <- M[1]`, `Ld R2 <- M[7]`, `St R2 -> M[0]`, `St R1 -> M[5]`, `Ld R2 <- M[10]`.
  - Sonuç: miss, miss, hit, miss, miss; toplam 4 miss, 1 hit.
  - Write-through'da iki store belleği hemen günceller (M[0] = 173, M[5] = 29).
  - Write-back'te store'lar yalnız önbelleği günceller, dirty biti 1 olur. Son load'da LRU satır (tag 0, dirty) atılmadan önce belleğe yazılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Adres bölümlemede word offset ve byte offset ayrı ayrı gösterilmeli
  - Hoca çözümlerde offset alanının word offset ve byte offset olarak ayrı yazılmasını istedi.
- Ortalama erişim süresi formülü
  - Miss durumunda verinin önce bellekten önbelleğe, sonra önbellekten işlemciye geldiğini, formülün $h\,t_c + m(t_m + t_c)$'den türediğini özellikle vurguladı.
- İki seviyeli önbellek örneği
  - Her seviyenin ortalama erişim süresinin hesaplanıp bir üst seviyeye miss penalty olarak aktarılması önemli bir örnek olarak belirtildi.
- Üç önbellek yapısında üç soru
  - Direct mapped, fully associative ve set associative için adres bölümlemenin, verinin nasıl arandığının ve değiştirme politikasının net anlaşılması gerektiğini söyledi.
- Önbellek ile sanal belleğin birlikte düşünülmesi
  - Bir sonraki konu olan sanal bellek önbellek yapısına dayanır; hoca ikisini birlikte içeren bütüncül bir soru gelebileceğini belirtti.

## Kısa Tekrar Notları

- Adres: tag | index | word offset | byte offset.
- Satır sayısı = kapasite / satır (set) boyutu; index = $\log_2$(satır sayısı).
- Valid bit 0 ise otomatik miss.
- 16 KB, 16 byte blok, 32 bit: direct mapped 18/10/2/2, fully associative 28/–/2/2, 4-way 20/8/2/2.
- $t_a = t_c + (1-h)\,t_m$; örnek 12.5 ns.
- İki seviye: $t_{a,L2} = 5 + 0.15 \cdot 100 = 20$, $t_a = 1 + 0.05 \cdot 20 = 2$ çevrim.
- Thrashing: x[i] ve y[i] aynı satıra düşerse miss rate %100.
- Değiştirme politikaları: optimal, LRU, FIFO, random; direct mapped'te index belirler.
- Write-through: önbellek + bellek birlikte; write-back: dirty bit, değiştirilirken belleğe yazma.

## Detaylı Açıklamalar

- Direct mapped önbellekte bir adresin önbellek karşılığını bulmak için adres alt alanlara bölünür. Satır içinde birden fazla word, her word'de birden fazla byte olabileceği için offset de ikiye ayrılır: en düşük bitler byte offset, onun üstü word offset'tir. Index satırı seçer. Ardışık adresler aynı satıra birlikte geldiği için her satırda tek bir tag yeterlidir. Valid biti, satırın daha önce bellekten doldurulup doldurulmadığını gösterir; önbellek açıldığında rastgele değerler bulunduğu için bu bit olmadan yanlış hit oluşabilir.
- 16 KB'lık, 4 word'lük bloklu direct mapped örnekte 32 bit mimari hem 32 bit veri yolu hem 32 bit adres yolu anlamına gelir; burada veri yolu word'ün 4 byte olduğunu söyler. Blok 16 byte, satır sayısı $2^{10}$ olduğundan adres 18 bit tag, 10 bit index, 2 bit word offset, 2 bit byte offset olarak bölünür. Erişim dizisi örneğinde bir miss olduğunda yalnız istenen word değil, son 4 bit dışında aynı olan dört word birlikte önbelleğe çekilir. `0x8014` adresi `0x14` ile aynı index'e (1) ama farklı tag'e (2) sahip olduğu için satır 1'i değiştirir.
- Vektör çarpımı örneği, programcının önbellek yapısını bilmesinin performansı nasıl etkilediğini gösterir. 16 byte'lık satıra 4 float sığar; x ve y farklı satırlara düşerse her dört iterasyonda bir x ve bir y miss'i olur. x[i] ve y[i] aynı index'e düşerse her okuma diğer dizinin bloğunu siler ve her erişim belleğe gider.
- Ortalama erişim süresinde hit oranı ölçülerek (çeşitli programlar çalıştırılarak) bulunan bir değerdir; önbellek tipine, blok genişliğine ve toplam boyuta bağlıdır. Çok seviyeli önbellekte en alttaki seviyeden başlanır: L2 ile bellek bir blok gibi düşünülüp $t_{a,L2}$ bulunur, bu değer L1 için "bellek erişim süresi" (miss penalty) yerine geçer.
- Fully associative önbellek, direct mapped'in tek satıra yığılma sorununu çözer ama her aramada bütün tag'lerin karşılaştırılmasını gerektirir. Set associative yapı bu ikisinin iyi yönlerini birleştirir: index ile arama tek satıra indirgenir, satır içinde birden fazla blok esnekliği sağlanır. 4-way örneğinde satır başına 4 blok olduğu için direct mapped'e göre index 2 bit kısalır (10 yerine 8), tag 2 bit uzar (18 yerine 20).
- Yazma işleminde önbellek ile bellek arasındaki tutarlılık sağlanmalıdır, çünkü başka bir program veriyi bellekten okuyabilir. Write-through basit ama yavaştır. Write-back belleğe erişimi azaltır, ancak dirty biti ile hangi satırın güncellendiğini izlemeyi gerektirir. Hangisinin seçileceği bu ödünleşime göre duruma bağlıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
