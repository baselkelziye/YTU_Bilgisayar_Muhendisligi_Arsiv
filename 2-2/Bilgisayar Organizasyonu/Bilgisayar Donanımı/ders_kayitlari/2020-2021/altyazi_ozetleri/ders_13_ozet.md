# Ders 13 Çalışma Özeti

## Genel Konular

- Dersin tarihi 11 Haziran 2021 Cuma. Dönemin son dersidir. Ders Zoom üzerinden yapıldı.
  - Asıl ders yaklaşık 00:07'de başlar. Kaydın başı bekleme kısmıdır.
  - Ders üç bölümdür: tekrar ve kavramlar, slayt örnekleri, Word üzerinde çözülen iki sınav tipi örnek.
- Cache tekrarı
  - Cache zorunlu değildir, sistemi hızlandırır.
  - Zamansal ve uzamsal yerellik, cache tasarım seçenekleri (kapasite, N-way, yerine koyma, L2, yazma politikası).
  - Genelleştirilmiş önbellekleme (generalized caching): dosya sistemi önbelleği, web sayfası önbelleği, memoization.
- Sanal bellek (virtual memory)
  - Sanal adresten fiziksel adrese dönüşüm (address translation).
  - Sayfa (page), sayfa tablosu (page table), page table entry (PTE): valid bit, erişim hakları, fiziksel sayfa numarası.
  - Sayfa hatası (page fault) ve işletim sisteminin page fault handler'ı.
  - Yerleştirme (placement) ve yerine koyma (replacement) politikaları, parçalanma (fragmentation).
  - Cache ile sanal belleğin karşılaştırılması.
  - TLB (Translation Lookaside Buffer).
  - Sayfa yerine koyma: FIFO, LRU, optimal.
- Örnekler
  - 48 bit sanal adres, 4 KB sayfa: sayfa tablosu büyüklüğü.
  - Fully associative TLB örneği (Example-2).
  - 2-way set associative, 512 girdili TLB (2010 sınav sorusu).
  - 20 bit sanal adres, 18 bit fiziksel adres, 2-way 16 girdili TLB ve sayfa tablosu.
- Final ve kapanış bilgileri.

## Hocanın Özellikle Vurguladığı Kısımlar

- Son haftaların konuları (cache ve virtual memory) mesleğiniz için çok önemli.
  - Bu konu İşletim Sistemleri dersiyle bağlantılıdır. Donanım tarafını bilmek orada işinizi kolaylaştırır.
- Zamansal yerellik ve uzamsal yerellik kavramlarını yıllar sonra bile hatırlamalısınız.
  - Yüksek lisans mülakatlarında sıkça sorulur.
- Her bellek seviyesi, bir üst (daha büyük) seviyenin bir alt kümesini tutar.
  - Cache ana belleğin, ana bellek de diskin bir parçasını tutar.
- Sanal bellekte birim **sayfa**dır, cache'te **blok**tur.
  - Cache'teki miss'in karşılığı sanal bellekte **page fault**'tur.
- Sanal bellekte yerleştirme her zaman fully associative'dir (sayfa tablosu üzerinden).
  - Yazma politikası yalnız write-back'tir. Sayfa çok büyük olduğu için her yazmada diske gidilmez.
- Page offset alanı sanal ve fiziksel adreste aynı uzunluktadır.
  - Fiziksel adres = fiziksel sayfa numarası (PPN) ile offset'in yan yana yazılması (birleştirme).
- Set associative TLB'de bir index altındaki **bütün setlere** bakın.
  - 2010 sınav sorusunda ilk sette tag eşleşip valid 0 görünüyordu. İkinci sete bakmayan hit'i kaçırır.
- FIFO ve LRU'yu bilmeniz yeterli. Optimal ve diğerleri İşletim Sistemleri dersinde ayrıntılı işlenecek.
- Sınavlarda iş birliği yapmayın, kendi bildiğinizle kendinizi sınayın.

## Kısa Tekrar Notları

- Sanal adres = VPN (virtual page number) | VPO (virtual page offset).
- Fiziksel adres = PPN (physical page number) | PPO (physical page offset). VPO = PPO.
- Offset bit sayısı $= \log_2(\text{sayfa boyutu})$. 1 KB sayfa → 10 bit, 4 KB sayfa → 12 bit.
- Sayfa tablosu VPN ile indekslenir. Girdi sayısı $= 2^{\text{VPN bit sayısı}}$.
- PTE alanları: valid bit, erişim hakları (read-only, read-write, executable), dirty bit, PPN.
- Valid bit 0 ise sayfa fiziksel bellekte yoktur: **page fault**. İşletim sistemi sayfayı diskten getirir.
- TLB, sayfa tablosunun son kullanılan girdilerini tutan özel bir cache'tir.
  - Set associative TLB'de VPN = TLB tag | TLB index (TLBI = VPN'in düşük bitleri).
  - TLB miss olursa sayfa tablosuna bakılır. Sayfa tablosunda valid 0 ise page fault olur.
- Cache ile sanal bellek karşılaştırması:

| Kavram | Cache | Sanal bellek |
| :--- | :--- | :--- |
| Birim | Blok (line) | Sayfa (page) |
| Bulunamama | Miss | Page fault |
| Yerleştirme | Direct mapped, N-way, fully associative | Fully associative (sayfa tablosu) |
| Yerine koyma | LRU, random | LRU (yaklaşık) |
| Yazma | Write-through veya write-back | Yalnız write-back |

## Detaylı Açıklamalar

### Cache'in donanım ve işletim sistemi tarafı

- Bir öğrenci cache'e hangi verinin alınacağına işletim sisteminin karar verip vermediğini sordu.
  - Hoca: eşleme tekniği (direct mapped, N-way vb.) işlemci üretilirken donanımda belirlenir.
  - Erişilen adresin çevresindeki bloğun cache'e alınmasını da donanım yapar (bkz. ders sonrası notlar).
- Cache kapasitesi büyüdükçe hız artar. Cache SRAM ile üretildiği için maliyet kapasiteyi sınırlar.
- Genelleştirilmiş önbellekleme fikri: pahalı bir işi tekrar tekrar yapacaksanız bir kez yapın, sonucu saklayın.

### Sanal adresten fiziksel adrese dönüşüm

- Program kendi sanal adres uzayında çalışır. Donanımdaki eşleme (hardware mapping) birimi sanal adresi fiziksel adrese çevirir.
- Slayt örneği: sayfa 1 KB, sanal bellek 32 sayfa (32 KB), fiziksel bellek 8 sayfa (8 KB).
  - Hangi sanal sayfanın hangi fiziksel sayfada olduğunu sayfa tablosu tutar.
- Dönüşüm adımları:
  - Sanal adresin düşük bitleri offset olarak ayrılır.
  - Kalan yüksek bitler (VPN) sayfa tablosunda satır seçer.
  - Satırdaki valid bit 1 ise PPN okunur, offset ile birleştirilir.
  - Valid bit 0 ise page fault olur.
- Sayfa tablosu ana bellekte tutulur. Her dönüşüm fazladan bir bellek erişimi gerektirir. TLB bu maliyeti azaltır.
- Fiziksel bellek doluysa yeni sayfa için bir sayfa çıkarılır (swap). Çıkarılan sayfa değiştirilmişse (dirty) önce diske yazılır.
- Kullanıcıların sayfaları arasında kalan küçük boşluklar parçalanma (fragmentation) sorununa yol açar. Ayrıntısı İşletim Sistemleri dersinde.

### Örnek 1: sayfa tablosu büyüklüğü

- 4 KB sayfa, 64 bit word, 48 bit sanal adres. Program ve verisi 4395 sayfa kullanıyor.
- Offset $= \log_2 4096 = 12$ bit. VPN $= 48 - 12 = 36$ bit.
- Tek seviyeli sayfa tablosu VPN ile indekslendiği için $2^{36}$ girdilidir.

### Örnek 2: fully associative TLB (Example-2)

- VPN 20 bit, PPN 12 bit, offset 12 bit. Sanal adres 32 bit, fiziksel adres 24 bit.
- Offset 3 hex hane, VPN 5 hex hane, PPN 3 hex hanedir.
- TLB içeriği (valid, dirty, VPN, PPN): (1, 1, 01AF4, FFF), (0, 0, 0E45F, E03), (0, 0, 012FF, 2F0), (1, 0, 01A37, 788), (1, 0, 02BB4, 45C), (0, 1, 03CA0, 657).

| Sanal adres | VPN | Offset | Sonuç | Fiziksel adres |
| :---: | :---: | :---: | :--- | :---: |
| 02BB4A65 | 02BB4 | A65 | TLB hit (valid 1) | 45CA65 |
| 0E45FB32 | 0E45F | B32 | Girdi var ama valid 0 | — |
| 0D34E9DC | 0D34E | 9DC | TLB'de yok (miss) | — |
| 03CA0777 | 03CA0 | 777 | Girdi var ama valid 0 | — |

- (a)'da dirty bit 0'dır: sayfa fiziksel belleğe geldiğinden beri değiştirilmemiştir.
- (d)'de dirty bit 1 görünür ama valid 0 olduğu için önemsizdir.

### Örnek 3: 2-way set associative TLB (2010 sınav sorusu)

- Sanal adres 32 bit, VPN 24 bit, PPN 32 bit. Offset $= 32 - 24 = 8$ bit. Fiziksel adres $= 32 + 8 = 40$ bit.
- Bit aralıkları:
  - VPO: sanal adresin 0–7. bitleri. VPN: 8–31. bitleri.
  - PPO: fiziksel adresin 0–7. bitleri. PPN: 8–39. bitleri.
- TLB 512 girdili ve 2-way: $512 / 2 = 256 = 2^8$ satır.
  - TLB index (TLBI) = VPN'in 0–7. bitleri, TLB tag (TLBT) = VPN'in 8–23. bitleri (16 bit).
- TLB'nin ilgili satırları (set 0 | set 1):

| Index | Valid | Tag | PPN | Valid | Tag | PPN |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 3D | 1 | 083F | 0913ABDE | 1 | 083E | AB18ED24 |
| 3E | 0 | F3E9 | 0913ABDE | 1 | 083F | 0118ED24 |
| 3F | 1 | 409A | C013ABDE | 1 | 083E | AC18ED24 |
| 40 | 0 | 083E | 0513ABDE | 1 | 083E | 0918ED24 |

- Sanal adres 0x083F3E9A:
  - VPN = 083F3E, VPO = 9A, TLBI = 3E, TLBT = 083F.
  - 3E satırında set 1'de tag 083F ve valid 1 var: **hit**.
  - PPN = 0x0118ED24, fiziksel adres = 0x0118ED249A.
- Sanal adres 0x083E409B:
  - VPN = 083E40, VPO = 9B, TLBI = 40, TLBT = 083E.
  - 40 satırında set 0'da tag 083E var ama valid 0. Set 1'de tag 083E ve valid 1 var: **hit**.
  - PPN = 0x0918ED24, fiziksel adres = 0x0918ED249B.

### Örnek 4: TLB ve sayfa tablosu birlikte

- Sanal adres 20 bit (1 MB), fiziksel adres 18 bit (256 KB), sayfa 1 KB.
  - VPO 10 bit, VPN 10 bit. PPO 10 bit, PPN 8 bit.
- TLB 2-way ve 16 girdili: $16 / 2 = 8$ satır. TLBI 3 bit, TLBT $10 - 3 = 7$ bit.
- Sanal adres 0x04AA4 = `0000 0100 1010 1010 0100`:
  - VPN = 0x012, VPO = 0x2A4, TLBI = 0x2, TLBT = 0x02.
  - TLB'nin 2. satırında tag 02 ve valid 1 var: **TLB hit**, page fault yok.
  - PPN = 0x68. Fiziksel adres = 0x1A2A4.
- Sanal adres 0x078E6:
  - VPN = 0x01E, VPO = 0x0E6, TLBI = 0x6, TLBT = 0x03.
  - TLB'nin 6. satırında tag 03 yok: **TLB miss**.
  - Sayfa tablosunda 1E girdisi valid: page fault yok. PPN = 0x57.
  - Fiziksel adres = 0x15CE6.
- Sayfa tablosunda da valid 0 olsaydı page fault olurdu. Sayfa diskten getirilir, gerekirse dolu bir sayfa çıkarılır. Çıkarılan sayfanın dirty biti 0 ise diske yazmaya gerek yoktur.

### Sayfa yerine koyma: FIFO ve LRU

- 3 çerçeveli (frame) bellek, başta boş. Referans dizisi: A B C A B D A D B C B.
- FIFO (ilk gelen ilk çıkar): 7 page fault.
  - D gelince en eski sayfa A çıkar. A tekrar gelince bu kez B çıkar. B gelince C çıkar. C gelince D çıkar.
- LRU (en uzun süredir kullanılmayan çıkar): aynı dizide 5 page fault.
  - D geldiğinde LRU, C'yi çıkarırdı. FIFO ise A'yı çıkardı.

### Final ve kapanış

- Finalde cache ve virtual memory konuları ağırlıklı sorulacak (ders 12'deki duyuru).
- Final sınavının şimdilik test olarak yapılması düşünülüyor.
- Finalde mazeret yoktur, bütünleme sınavı vardır. Mazeret yalnız teknik aksaklık durumunda verilir.
- Hoca ders duvarına çözümlü bir cache örneği ve bir virtual memory örneği daha koyacağını söyledi.
- Aynı gün saat 11:00'de bir öğrencinin mazeret sınavı vardı.

### Ders sonrası notlar

- Örnek 1'deki "minimum number of page tables" sorusu derste tek seviyeli tablonun $2^{36}$ girdisi olarak cevaplandı.
  - Soru metninde 64 bit word bilgisi verildiği için soru büyük ihtimalle çok seviyeli sayfa tablosu istiyor.
  - 8 byte'lık PTE ile 4 KB'lık bir tabloya $4096/8 = 512 = 2^9$ girdi sığar. 36 bitlik VPN $4 \times 9$ bitlik dört seviyeye bölünür.
  - 4395 sayfa ardışık yerleşirse $\lceil 4395/512 \rceil = 9$ son seviye tablo ve üst seviyelerde birer tablo gerekir. En az $9 + 1 + 1 + 1 = 12$ sayfa tablosu.
- Örnek 2'de (b) ve (d) için derste "page fault oldu" dendi.
  - TLB'de valid biti 0 olan bir girdi, o VPN için TLB'de geçerli bir dönüşüm olmadığını gösterir. Bu durum TLB miss gibi değerlendirilir.
  - Page fault olup olmadığını anlamak için sayfa tablosuna bakmak gerekir. Soru yalnız TLB'yi verdiği için kesin cevap "TLB miss, fiziksel adres bu tablodan bulunamaz" olmalıdır.
- Örnek 3'te ilk adresin cevap anahtarında PPN 0xAC18ED24 yazıyordu. Hoca bunu 0x0118ED24 olarak düzeltti.
  - Düzeltme doğrudur: 3E satırının set 1 girdisi 0x0118ED24'tür. 0xAC18ED24, 3F satırına aittir.
- Örnek 4'te hoca bir an "10 bitin 3 biti TLB tag, 7 biti TLB index" dedi. Doğrusu ters: TLB index 3 bit, TLB tag 7 bit. Tahtadaki çözüm doğrudur.
- Derste sayfa tablosu girdisi için "valid 1 ise sayfa virtual memory'de mevcuttur" dendi. Doğrusu: valid 1 ise sayfa **fiziksel bellekte** (ana bellekte) mevcuttur.
- Derste "erişilen adresin çevresindeki bloğu işletim sistemi cache'e taşıyor" dendi. Cache'e blok yükleme tamamen donanım (cache denetleyicisi) tarafından yapılır. İşletim sistemi sayfa düzeyinde (sanal bellek) devreye girer.
- Hoca LRU için "virtual memory tarafında LRU kullanılıyor" dedi. Gerçek sistemlerde tam LRU pahalıdır. Genellikle referans bitiyle yaklaşık LRU (ör. clock algoritması) kullanılır.
- TLB'nin bir cache olduğu, fully associative, direct mapped veya set associative tasarlanabileceği derste doğru anlatıldı.
- FIFO ve LRU sayıları, örnek 3 ve 4'teki bütün adres hesapları Python ile doğrulandı. Tablo değerleri ekran karelerinden okundu.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.
