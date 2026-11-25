# Ders 14 Çalışma Özeti

## Genel Konular

- Önbellek mimarilerinin kısa tekrarı
  - Doğrudan eşlemeli (direct mapped) önbellekte fiziksel adres tag, index ve offset (word offset, byte offset) alanlarına bölünür. Index adresin hangi satıra gideceğini belirler; aynı satıra düşen adresleri ayırmak için tag saklanır. Satırda tag, valid biti ve ana bellekten getirilen veri bloğu tutulur.
  - Tam ilişkili (fully associative) önbellekte index alanı yoktur. Blok ilk boş yere konur; önbellek doluysa LRU, FIFO ya da rastgele gibi bir değiştirme politikası uygulanır. Aramada bütün satırların tag'leri karşılaştırılır.
  - Küme ilişkili (set associative) yapı ikisini birleştirir: index ile satıra gidilir, satırdaki kümeler (way) arasında esneklik vardır. Aynı kapasitede doğrudan eşlemeliye göre satır sayısı, dolayısıyla index bit sayısı azalır, tag alanı büyür.
- Yazma işleminde tutarlılık (ekrandan, 00:05:00)
  - Okuma veriyi değiştirmediği için sorun çıkarmaz. Yazmada güncel verinin önbellekte mi ana bellekte mi olduğu, başka bir birimin eski kopyaya erişip erişmeyeceği sorunu doğar.
  - Write-through: her yazma hem önbellekte hem ana bellekte yapılır. Tutarlılık her zaman sağlanır ama her güncellemede ana belleğe erişilir.
  - Write-back: yazma yalnız önbellekte yapılır, satırın değiştiği ek bir dirty (kirli) bitiyle işaretlenir. Dirty biti 1 olan blok önbellekten çıkarılırken ana bellek güncellenir. Donanım biraz karmaşıklaşır ama ana bellek erişimi azalır.
  - Bazen önbelleğin boşaltılması (flush) gerekir: G/Ç ve çok işlemcili durumlar (ekrandan, 00:05:00).
- Store miss durumu (ekrandan, 00:15:00)
  - Yazılacak adres önbellekte yoksa store miss oluşur.
  - Write-allocate: yazılan blok önbelleğe getirilir, blok içindeki word güncellenir; bloğun yeniden kullanılacağı öngörülür.
  - No-write allocate: yalnız ana bellek güncellenir, önbellek içeriği değişmez.
- Write-through örneği (ekrandan, 00:20:00 - 00:30:00)
  - 16 byte'lık bellek (4 bit adres), 4 byte kapasiteli, 2 byte bloklu, iki satırlı, tam ilişkili, LRU'lu önbellek. Adres 3 bit tag ve 1 bit byte offset'e bölünür.
  - Komut dizisi: `Ld R1←M[1]`, `Ld R2←M[7]`, `St R2→M[0]`, `St R1→M[5]`, `Ld R2←M[10]`. Sonuç: 4 miss, 1 hit; her store hem önbelleği hem belleği günceller.
- Write-back örneği (ekrandan, 00:35:00)
  - Aynı önbellek ve aynı komut dizisi, ek olarak dirty biti. Store'lar yalnız önbelleği günceller ve dirty bitini 1 yapar; dirty blok yalnız LRU ile çıkarılırken belleğe yazılır.
- Sanal belleğe geçiş: önbellek tekrarı ve genelleştirilmiş önbellekleme (ekrandan, 00:55:00 ve 01:00:00)
  - Önbellek zorunlu değildir; veri aktarımını hızlandırır. Hiyerarşinin her seviyesi bir üstünün alt kümesidir. Zamansal yerellik yakın zamanda kullanılan veriyi, 1 word'den büyük blok ise uzamsal yerelliği kullanır.
  - Aynı mantık ana bellek ile ikincil bellek arasında da uygulanır: program parçalar (sayfa, page) halinde yüklenir.
- Sanal adresten fiziksel adrese dönüşüm (ekrandan, 01:10:00)
  - Her program kendi sanal adres uzayında çalışır ve adresleri kendi başlangıcına göre ifade eder; programlar birbirinden korunur; işletim sistemi programın bellekte nereye konacağına karar verir; donanım sanal-fiziksel eşlemeyi yapar.
  - Sanal adres uzayı fiziksel adres uzayından büyük olabilir.
- Sayfalama örneği (ekrandan, 01:15:00)
  - 1 KB sayfa, 32 sayfalık (32 KB) sanal uzay, 8 sayfalık (8 KB) fiziksel bellek. Sanal adres 15 bit: 5 bit VPN (virtual page number) + 10 bit VPO (virtual page offset). Fiziksel adres 13 bit: 3 bit PPN + 10 bit PPO.
  - Offset dönüşmez; yalnız VPN, PPN'ye eşlenir.
- Sayfa tablosu (page table) (ekrandan, 01:20:00)
  - VPN ile indekslenir; her girdide (PTE) valid biti, erişim hakları (access rights) ve PPN bulunur. VPN tabloda saklanmaz, çünkü indeksin kendisidir.
  - $2^{VPN}$ satırlıdır ve çoğu satırı boştur (seyrek). Tablonun başlangıç adresi özel bir yazmaçta (page table base register) tutulur.
  - Tabloyu işletim sistemi yönetir; kullanıcı doğrudan değiştiremez. Böylece programlar birbirlerinin alanlarına erişemez.
- Önbellek ile sanal belleğin karşılaştırılması
  - Blok/satır karşılığı sayfa; miss karşılığı page fault. Page fault'ta işletim sistemi sayfayı ikincil bellekten getirir.
  - Önbellek blokları onlarca byte, sayfalar KB mertebesindedir. Sanal bellekte tam ilişkili yerleştirme, LRU türü değiştirme ve write-back kullanılır; ikincil belleğe erişim çok yavaş olduğu için write-through düşünülmez.
- TLB (Translation Lookaside Buffer) (ekrandan, 01:30:00)
  - Yakın zamanda kullanılan sayfa tablosu girdilerinin önbelleğidir. Girdilerde sanal sayfa, fiziksel sayfa, dirty, ref, valid ve erişim bitleri bulunur. Erişim süresi önbelleğinkine yakındır.
  - Akış: önce TLB'ye bakılır; hit ise fiziksel adres doğrudan oluşur. Miss ise girdi sayfa tablosundan TLB'ye getirilir. Fiziksel adres oluştuktan sonra önbellek adres bölümlemesine göre veri önbellekte aranır.
- Sayfa değiştirme politikaları (ekrandan, 01:45:00 ve 01:50:00)
  - Rastgele, FIFO (en eski yüklenen), optimal (gelecekte en geç kullanılacak), LRU (en uzun süredir kullanılmayan), NFU (en az sıklıkla kullanılan).
  - Örnek (3 çerçeve, A B C A B D A D B C B): FIFO 7, optimal 5, LRU 5 page fault.
- Sanal adres, fiziksel adres ve önbellek bölümlemesinin birlikte kullanımı (ekrandan, 01:55:00 - 02:15:00)
  - 1 KB sayfa, 32 bit veri yolu, 20 bit sanal adres, 18 bit fiziksel adres: VPO = PPO = 10 bit, VPN = 10 bit, PPN = 8 bit.
  - Tam ilişkili TLB'de tag VPN'in kendisidir. 512 word'lük, 8 yollu, 8 word'lük bloklu önbellek: 8 satır, 3 bit index, 3 bit word offset, 2 bit byte offset, 10 bit tag.

## Hocanın Özellikle Vurguladığı Kısımlar

- Write-through ve write-back mantığı
  - Hoca bunların önemli olduğunu ve en azından nasıl çalıştıklarının bilinmesi gerektiğini söyledi. Seçim, store hit/miss oranlarına ve çalıştırılan algoritmaya bağlı bir ödünleşimdir (trade-off).
- Örneklerdeki önbellek tam ilişkilidir
  - Hoca write-through örneğini önce doğrudan eşlemeli gibi (1 bit index ile) anlattı, sonra düzeltti: tam ilişkili yapıda index yoktur, adres 3 bit tag + 1 bit offset olarak bölünür. Örnekler bu gözle tekrar çözülmelidir.
- Önbellek tasarım soruları
  - Önbellek boyutunun hıza ve kapasiteye etkisi, mimari seçimi ve küme sayısı, hit/miss oranları, değiştirme kuralı, çok seviyeli önbellek ve yazma güncellemesi; hepsi tekil ve toplam performansa göre değerlendirilir.
- TLB'de valid biti 0 olan girdi
  - TLB sayfa tablosunun yalnız bir özetidir. TLB'de miss olması page fault olduğu anlamına gelmez; page fault olup olmadığı için sayfa tablosuna bakmak gerekir.
- Sanal adres, fiziksel adres ve önbellek adres bölümlemesi birbirine bağlıdır
  - Fiziksel adres sayfa tablosu/TLB üzerinden elde edilir, ardından önbellek yapısına göre yeniden bölünür.

## Kısa Tekrar Notları

- Write-through: her yazma önbellek + bellek. Write-back: yalnız önbellek, dirty bit, çıkarılırken belleğe yaz.
- Store miss: write-allocate (bloğu getir, güncelle) ya da no-write allocate (yalnız belleği güncelle).
- Write-through örneği (tam ilişkili, 2 satır, 2 byte blok, LRU): 4 miss, 1 hit.
- Write-back örneğinde dirty blok (M[0], M[1]) yalnız son load'da çıkarılırken belleğe yazılır.
- Sayfa = sanal belleğin bloğu; page fault = sanal belleğin miss'i.
- Sanal adres = VPN + VPO; fiziksel adres = PPN + PPO; VPO = PPO = $\log_2(\text{sayfa boyutu})$.
- Sayfa tablosu girdisi: valid, access rights, PPN. VPN saklanmaz.
- TLB: sayfa tablosunun önbelleği; tam ilişkili TLB'de tag = VPN.
- TLB miss page fault demek değildir.
- FIFO 7, optimal 5, LRU 5 page fault (3 çerçeve, A B C A B D A D B C B).
- 20 bit VA, 18 bit PA, 1 KB sayfa: VPN 10, VPO/PPO 10, PPN 8 bit.

## Detaylı Açıklamalar

- **Write-through örneği adım adım (ekrandan, 00:20:00 - 00:30:00):** Bellek içeriği adres 0-15 için 78, 29, 120, 123, 71, 150, 162, 173, 18, 21, 33, 28, 19, 200, 210, 225'tir. Önbellek boş başlar (valid bitleri 0). `Ld R1←M[1]`: adres `0001`, tag 0, offset 1; valid 0 olduğu için load miss. Tag'i 0 olan 0 ve 1 adresleri (78, 29) ilk boş satıra getirilir, R1 = 29. `Ld R2←M[7]`: adres `0111`, tag 3; yok, ikinci satıra 6 ve 7 (162, 173) gelir, R2 = 173 (miss). `St R2→M[0]`: tag 0 mevcut, store hit; önbellekte ve bellekte M[0] = 173. `St R1→M[5]`: adres `0101`, tag 2; yok, store miss. LRU satır (tag 3) çıkarılır, 4 ve 5 (71, 150) getirilir, offset 1'e 29 yazılır; bellekte de M[5] = 29 olur. `Ld R2←M[10]`: adres `1010`, tag 5; yok, load miss. LRU satır (tag 0) çıkarılır, 10 ve 11 (33, 28) getirilir, R2 = 33. Toplam 4 miss, 1 hit (ekrandan, 00:30:00). Her miss'te 2 byte okunduğu için 8 byte okuma, iki store için 2 byte yazma yapılmıştır.
- **Write-back örneği adım adım (ekrandan, 00:35:00):** İlk iki load aynıdır (iki miss), satırların dirty bitleri 0'dır. `St R2→M[0]`: tag 0 satırında hit; önbellekte 78 yerine 173 yazılır, dirty = 1; bellekte M[0] hâlâ 78'dir. `St R1→M[5]`: tag 2 yok, store miss; LRU satır tag 3 satırıdır ve dirty 0 olduğu için belleğe yazmadan çıkarılır. 71, 150 getirilir, 150'nin yerine 29 yazılır, dirty = 1, tag = 2. `Ld R2←M[10]`: tag 5 yok, load miss; LRU satır tag 0 satırıdır ve dirty 1'dir, bu yüzden önce bloğun iki byte'ı (173, 29) belleğe (M[0], M[1]) yazılır. Hangi byte'ın değiştiği bilinmediği için bloğun tamamı yazılır. Sonra 33, 28 getirilir, dirty = 0, R2 = 33. Aynı veri birkaç kez güncellense de belleğe tek yazma yeterli olur.
- **Write-through ile write-back karşılaştırması:** Write-through'da yazma sayısı kabaca iki katına çıkar (hem önbellek hem bellek), ama bellek her zaman günceldir. Write-back'te bir veri üç kez güncellenip sonra çıkarılırsa belleğe üç yerine bir kez yazılır. Seçim; toplam miss oranına, belleğe kaç kez yazılması gerektiğine ve ortalama store hit/miss değerlerine göre yapılır.
- **Sayfa boyutunun seçimi:** Önbellekte blok boyutu belli bir değere kadar artınca kazanç sağlar, aynı kapasitede daha da artırılınca değiştirmeler çoğaldığı için kazanç düşer. Sayfa boyutu da benzer biçimde ana belleğin ve ikincil belleğin boyutu ve erişim süreleri ile çalışan kodun yapısına göre seçilir; genelde KB mertebesindedir.
- **Sayfalama örneği (ekrandan, 01:15:00):** Sanal uzay 0'dan 31744'e kadar başlayan 32 sayfadır (32 KB, $2^{15}$), fiziksel bellek 0'dan 7168'e kadar başlayan 8 sayfadır (8 KB, $2^{13}$). Sayfa içi offset $\log_2 1024 = 10$ bit, VPN $15 - 10 = 5$ bit, PPN $13 - 10 = 3$ bit. Sayfa tablosu 5 bitlik VPN ile indekslenir, 3 bitlik PPN verir; PPN, 10 bitlik offset ile birleştirilerek 13 bitlik fiziksel adres elde edilir.
- **Sayfa tablosunun boyutu:** İlk akla gelen tasarım $2^{VPN}$ satır, her satırda bir PPN'dir. Bu tablo çok büyüktür, ana bellekte tutulmalıdır ve bir program o anda yalnız birkaç sayfasını yüklediği için satırlarının çoğu kullanılmaz (seyrek tablo). TLB bu dönüşümü hızlandıran küçük bir ara yapıdır.
- **TLB örneği (Example-2, ekrandan, 01:40:00):** VPN 20 bit, PPN 12 bit, offset 12 bit (VA 32 bit, PA 24 bit), tam ilişkili TLB. 02BB4A65: VPN 02BB4 TLB'de valid 1, PPN 45C, fiziksel adres 45CA65 (hit). 0E45FB32: girdi var ama valid 0, TLB miss; page fault olup olmadığı TLB'den söylenemez. 0D34E9DC: VPN TLB'de yok, TLB miss; page fault bilinmez. 03CA0777: girdi valid 0 (dirty 1), TLB miss.
- **Birleşik örnek (ekrandan, 02:00:00 - 02:15:00):** 0x04AA4: VPN 0x012, VPO 0x2A4; TLB'de 012 valid 1, PPN A1; TLB hit, page fault yok, fiziksel adres 0x286A4. 0x078E6: VPN 0x01E, VPO 0x0E6; TLB'de 01E valid 0, TLB miss; sayfa tablosunda 01E valid 1, PPN 57, page fault yok; fiziksel adres 0x15CE6. 0x000F4: VPN 000, TLB'de PPN 1F (valid 1), fiziksel adres 0x07CF4 = `00 0111 1100 1111 0100`; önbellek bölümlemesinde tag 0x07C, index 7, word offset 5, byte offset 0.
- **Ders sonrası notlar:**
  - Hoca write-back için "bu senaryoda üçte bir daha az G/Ç erişimi" dedi; üç güncellemede belleğe üç yerine bir kez yazıldığı için erişim büyük olasılıkla üçte bire iner.
  - Hoca TLB örneğinde dirty biti 1 olan girdiyi bir yerde "C şıkkı" diye andı; ekrandaki tabloya göre bu girdi (d) şıkkındaki 03CA0 girdisidir.
  - Hoca LRU örneğinin sonunda toplamı "5-6" gibi söyledi; adımlar sayıldığında LRU için 5 page fault çıkar (python ile kontrol edildi).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
