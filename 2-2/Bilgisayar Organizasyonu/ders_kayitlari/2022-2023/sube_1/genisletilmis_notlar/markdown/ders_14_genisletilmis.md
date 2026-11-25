# Ders 14 Genişletilmiş Notu: Önbellekte Yazma Politikaları, Sanal Bellek ve TLB

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önbellek Mimarilerinin Tekrarı
- 2. Yazma İşleminde Tutarlılık: Write-Through ve Write-Back
- 3. Store Miss: Write-Allocate ve No-Write Allocate
- 4. Write-Through Örneği
- 5. Write-Back Örneği
- 6. Önbellekten Sanal Belleğe
- 7. Sanal Adres Uzayı ve Sayfalama
- 8. Sayfa Tablosu
- 9. Önbellek ile Sanal Belleğin Karşılaştırılması
- 10. Translation Lookaside Buffer (TLB)
- 11. Sanal Bellek Örnekleri
- 12. Sayfa Değiştirme Politikaları
- 13. Sanal Adres, Fiziksel Adres ve Önbellek Bölümlemesi
- 14. Örnek Sorular

## 1. Önbellek Mimarilerinin Tekrarı

Ders, önceki haftada görülen önbellek (cache) tasarım yapılarının tekrarıyla başladı. Önceki derslerde görülen bütün yapılar veri okumaya, yani veri erişimine yönelikti. Bu derste önce yazma durumunda ne olacağı, ardından sanal bellek (virtual memory) ve sanal belleğin önbellekle ilişkisi ele alındı.

Üç farklı önbellek mimarisi görülmüştü:

- **Doğrudan eşlemeli (direct mapped):** Fiziksel adresin belirli bir kısmı index alanı olarak ayrılır ve index, adresin hangi önbellek satırına gideceğini belirler. Satır içinde hangi byte ile işlem yapılacağını offset bitleri (word offset ve byte offset) belirler. Birden fazla adres aynı satıra düştüğü için bunları ayırt etmek amacıyla adresin bir parçası olan tag alanı da saklanır. Satırda tag, valid biti ve ana bellekten getirilen veri bloğu tutulur.
- **Tam ilişkili (fully associative):** Fiziksel adres bölünürken index alanı yoktur. İlk yerleştirmede blok sıradaki boş yere konur. Önbelleğin tamamı doluysa bir değiştirme politikası (replacement policy) uygulanır: LRU (least recently used), FIFO (first in first out) ya da rastgele. Önbellekte yine tag, valid biti ve veri saklanır.
- **Küme ilişkili (set associative):** İkisinin güçlü yanlarını birleştirir. Doğrudan eşlemelide nereye bakılacağı bellidir; tam ilişkilide ise boş alanlar daha akıllıca kullanılabilir. Küme ilişkili yapıda bir index kavramı vardır, ama her satırda birden çok küme (yol, way) bulunur ve bunlar kendi aralarında değiştirilebilir. Yani bir yönde tam ilişkili, diğer yönde doğrudan eşlemeli gibi çalışır. Aynı önbellek kapasitesinde 2, 4, 8 yollu bir yapının doğrudan eşlemeliye göre daha az satırı, dolayısıyla daha az index biti vardır; bu yüzden tag alanı biraz daha büyüktür. Bir adres aranırken index ile satıra gidilir ve satırdaki bütün kümelerin tag'leri adresin tag'iyle karşılaştırılır.

Ayrıca veri önbelleği (data cache) ve komut önbelleği (instruction cache) ayrı olabilir.

## 2. Yazma İşleminde Tutarlılık: Write-Through ve Write-Back

Önbellek ve ana bellek iki ayrı bloktur. İşlemci bir veriyi okuyup yazmacında güncellediğinde bu güncellemenin nereye ve ne zaman yazılacağı sorusu ortaya çıkar (ekrandan, 00:05:00). Veri önbellekte güncellenmişken başka bir birim aynı veriye ana bellekten erişmek isteyebilir. Bu durumda ana bellekteki eski ($t-1$ anındaki) kopyaya mı erişecek, yoksa en güncel haline mi? Önbellekte güncellenen veri ana bellekte de güncellenmeli mi, ne zaman?

Bu soruların hiçbiri okuma yönlü erişimlerde yoktur: okuma veriyi değiştirmediği için bir kaynaktan birden fazla birim sorunsuz okuyabilir. Yazma ise veriyi güncellediği için tutarlılığı (consistency) sağlamak gerekir. Bunun için iki yöntem vardır.

### 2.1 Write-through

Bir güncelleme yapıldığında veri hem önbellekte hem ana bellekte aynı anda güncellenir. Böylece her güncelleme ana belleğe kadar yayılır; veri önbellekten çıkarılsa bile başka bir birim ana bellekten güncel veriyi okuyabilir. İşlemci veriyi alır, yazmacında günceller, güncelleme hem önbelleğe hem ana belleğe yazılır. Aynı veri iki yere yazıldığı için yazma işlemi kabaca iki katına çıkar. Hoca, write-through işleminin ek tamponlar (buffer) kullanarak da yürütülebildiğini belirtti.

### 2.2 Write-back

Bu biraz daha karmaşık bir yöntemdir. Güncelleme öncelikle yalnız önbellekte yapılır. Verinin güncellendiği, önbellekte ayrı bir bit olarak tutulur: dirty (kirli) biti. Dirty biti 1 olan bir blok önbellekten çıkarılacaksa güncel verinin kaybolma riski vardır; bu yüzden blok çıkarılırken ana bellekte de güncellenir (ekrandan, 00:05:00).

Akış şöyledir: İşlemci bir komut yürütür, adresle ilgili veri önbellekte aranır; yoksa ana bellekten getirilir. Veri işlemciye okunur, güncellenir ve önbellekte güncellenir. Aynı veriye tekrar erişilip yeniden güncellenebilir; her seferinde yalnız önbellek güncellenir. Daha sonra başka bir adrese erişilir, o veri önbellekte yoktur ve ana bellekten getirilirken daha önce güncellenen veriyi çıkarması gerekir. Bu veri önbellekte güncel, bellekte eski haldedir. Çıkarılacak satırın dirty bitine bakılır; 1 ise veri ana bellekte de güncellenir (write-back). Burada önemli nokta, aynı veri birkaç kez güncellense de belleğe tek bir yazmanın yeterli olmasıdır; write-through'da her güncellemenin belleğe yazılması gerekirdi.

### 2.3 Ödünleşim

İki yöntem arasında bir performans ödünleşimi (trade-off) vardır. Write-through tutarlılığı her zaman sağlar, ama her güncellemede ana belleğe erişildiği için G/Ç işlemleri daha fazla zaman alır. Write-back'te veri önbellekten çıkarılmadıkça ana belleğe yazmaya gerek yoktur; örneğin üç güncellemeden sonra yalnız en son hal belleğe yazılır. Write-back donanımı ise ek bir bit gerektirdiği için biraz daha karmaşıktır.

> **Ders sonrası not:** Hoca bu senaryo için "üçte bir daha az G/Ç erişimi" dedi. Üç güncellemede belleğe üç yerine bir kez yazıldığı için erişim sayısı büyük olasılıkla üçte bire iner.

Slaytta ayrıca bazen önbelleğin boşaltılması (flush) gerektiği yazıyordu: G/Ç ve çok işlemcili (multiprocessing) durumlar (ekrandan, 00:05:00).

## 3. Store Miss: Write-Allocate ve No-Write Allocate

Store miss şu anlama gelir: Bir veri alınıp işlendi, sonra önbelleğe yazılacak, ama yazılacak adres önbellekte yok. Yapılabilecek iki şey vardır (ekrandan, 00:15:00):

- **Write-allocate:** Yazılan blok önbelleğe getirilir, blok içindeki word güncellenir ve bloğun ileride yeniden kullanılacağı öngörülerek önbellekte tutulur.
- **No-write allocate:** Yalnız ana bellek güncellenir, önbellek içeriği değişmez.

## 4. Write-Through Örneği

### 4.1 Kurulum

Ekrandaki örnekte dört yazmaçlı (R0-R3) bir işlemci, 16 byte'lık bir ana bellek ve bir önbellek vardır (ekrandan, 00:20:00). Bellek içeriği:

```text
Adres: 0   1   2    3    4   5    6    7    8   9   10  11  12  13   14   15
Veri : 78  29  120  123  71  150  162  173  18  21  33  28  19  200  210  225
```

Yürütülecek komutlar:

```text
Ld R1 <- M[1]
Ld R2 <- M[7]
St R2 -> M[0]
St R1 -> M[5]
Ld R2 <- M[10]
```

Fiziksel adresler 0-15 olduğu için adres 4 bittir. Önbellek iki satırdan oluşur, her satırda 2 byte'lık bir blok vardır, yani kapasite 4 byte'tır. Önbellek tam ilişkilidir ve değiştirme politikası LRU'dur. Başlangıçta önbellek boştur, valid bitleri 0'dır; satırlarda yazan değerler geçerli değildir.

### 4.2 Adresin bölünmesi ve hocanın düzeltmesi

Blok 2 byte olduğu için blok içindeki byte'ı seçmek için 1 bit byte offset yeterlidir; word offset kullanılmaz (word genişliği 1 byte kabul edilir). Hoca örneği önce doğrudan eşlemeli bir önbellek gibi anlatmaya başladı ve iki satır için 1 bit index, kalan 2 biti tag olarak ayırdı. Örnek ilerlerken bunun yanlış olduğunu fark edip düzeltti: önbellek tam ilişkili olduğu için index alanı yoktur. Doğru bölümleme 1 bit byte offset ve 3 bit tag'dir.

> **Hocanın vurgusu:** Örnekler tam ilişkili önbellek için çözülmelidir; buna dikkat ederek örnekleri tekrar çözümleyin.

Aşağıdaki çözüm düzeltilmiş (tam ilişkili) haliyle verilmiştir.

### 4.3 Adım adım çözüm

1. `Ld R1 <- M[1]`: Adres `0001`; tag `000` = 0, offset 1. Bütün valid bitleri 0 olduğu için veri önbellekte yoktur: **load miss**. Tag'i 0 olan 0 ve 1 adreslerinin içeriği (78, 29) ilk boş satıra getirilir, tag 0 yazılır, valid 1 yapılır. Offset 1'deki değer okunur: R1 = 29.
2. `Ld R2 <- M[7]`: Adres `0111`; tag `011` = 3, offset 1. İlk satırın tag'i 3 değildir, ikinci satır valid değildir: **load miss**. 6 ve 7 adresleri (162, 173) ikinci satıra getirilir, tag 3, valid 1. R2 = 173.
3. `St R2 -> M[0]`: Adres `0000`; tag 0, offset 0. Tag 0 ilk satırda vardır: **store hit**. İlk satırın offset 0'ındaki 78 yerine 173 yazılır. Write-through olduğu için bellekte de M[0] = 173 yapılır.
4. `St R1 -> M[5]`: Adres `0101`; tag `010` = 2, offset 1. Satırlarda 0 ve 3 tag'leri vardır, 2 yoktur: **store miss**. En uzun süredir kullanılmayan satır (tag 3 satırı; tag 0 satırı bir önceki adımda kullanıldı) çıkarılır. Tag'i 2 olan 4 ve 5 adresleri (71, 150) getirilir. R1'deki 29, offset 1'e (150'nin yerine) yazılır; bellekte de M[5] = 29 olur (ekrandan, 00:25:00).
5. `Ld R2 <- M[10]`: Adres `1010`; tag `101` = 5, offset 0. Tag 5 yoktur: **load miss**. LRU satır (tag 0 satırı) çıkarılır, 10 ve 11 adresleri (33, 28) getirilir. Offset 0'daki değer okunur: R2 = 33.

Sonuç: 4 miss, 1 hit; R1 = 29, R2 = 33 (ekrandan, 00:30:00). Bellekte M[0] = 173 ve M[5] = 29 olmuştur. Her miss'te 2 byte'lık veri okunduğu için toplam 8 byte okuma, her store'da 1 byte güncellendiği için 2 byte yazma yapılmıştır.

<!-- BELİRSİZ: Hoca bu noktada "günümüz önbelleklerinde bu oran kabaca %20" gibi bir oran söyledi; hangi oranı kastettiği altyazıdan net değil. -->

## 5. Write-Back Örneği

Aynı önbellek (4 byte, tam ilişkili, 2 byte blok, LRU) ve aynı komut dizisi bu kez write-back ile çalıştırılır. Satırlarda valid ve tag'e ek olarak bir dirty biti vardır (ekrandan, 00:35:00). Adres yine 3 bit tag ve 1 bit offset'e bölünür.

1. `Ld R1 <- M[1]`: tag 0, valid bitleri 0, **load miss**. 0 ve 1 adresleri (78, 29) getirilir; tag 0, valid 1, dirty 0. R1 = 29.
2. `Ld R2 <- M[7]`: tag 3; birinci satırda yok, ikinci satır valid değil, **load miss**. 6 ve 7 (162, 173) getirilir; tag 3, valid 1, dirty 0. R2 = 173.
3. `St R2 -> M[0]`: tag 0, offset 0. Tag 0 birinci satırda vardır, **store hit**. 78 yerine 173 yazılır ve veri güncellendiği için dirty = 1 yapılır. Tag değişmez. Bellekte M[0] hâlâ 78'dir; bellek henüz güncellenmemiştir.
4. `St R1 -> M[5]`: tag 2, eşleşme yok, **store miss**. LRU satır tag 3 satırıdır; dirty biti 0 olduğu için belleğe yazmaya gerek yoktur. Tag 2'li 4 ve 5 adresleri (71, 150) getirilir, tag 2 yazılır. R1'deki 29, offset 1'e (150'nin yerine) yazılır ve dirty = 1 yapılır. Bellekte M[5] hâlâ 150'dir (ekrandan, 00:35:00).
5. `Ld R2 <- M[10]`: tag 5, eşleşme yok, **load miss**. LRU satır tag 0 satırıdır ve dirty biti 1'dir. Bu yüzden satır çıkarılmadan önce içeriği belleğe yazılır: tag 0 ve offset 0, 1 olan adresler, yani M[0] ve M[1], 173 ve 29 ile güncellenir. Bloğun hangi byte'ının değiştiği bilinmediği için iki byte birden yazılır. Ardından 10 ve 11 adresleri (33, 28) getirilir, tag 5, dirty 0. Offset 0'daki 33, R2'ye okunur.

Bu örnekte de miss'ler oluşur, ama her güncellemede belleğe erişilmediği için G/Ç işlemi daha azdır. Hangi yöntemin seçileceği toplam miss oranına, belleğe kaç kez güncelleme yazılması gerektiğine, çalıştırılan algoritmaya ve ortalama store hit/miss değerlerine bakılarak belirlenir; burada da bir ödünleşim vardır.

> **Hocanın vurgusu:** Write-through ve write-back önemlidir; en azından mantıklarının nasıl çalıştığı bilinmelidir.

## 6. Önbellekten Sanal Belleğe

Aradan sonra hoca sanal belleğe geçmeden önce önbellekten akılda kalması gerekenleri özetledi (ekrandan, 00:55:00):

- Önbellek zorunlu değildir: işlemci aritmetik işlemleri yapar, bellek veriyi saklar, önbellek yalnızca veri aktarımını hızlandırır. Ama kullanılan yapıya göre performansı 5-10 kat mertebesinde artırabildiği için kullanmak avantajlıdır.
- Bellek hiyerarşisinin her seviyesi bir üst seviyenin alt kümesidir.
- Önbellek zamansal yerellik (temporal locality) sayesinde hızlandırır: yakın zamanda kullanılan veri saklanır.
- 1 word'den büyük blok, uzamsal yerellik (spatial locality) sayesinde hızlandırır: yakın zamanda kullanılan word'lerin komşuları da saklanır.

Önbellekleme genel bir fikirdir ve bilgisayar sistemlerinde tekrar tekrar karşımıza çıkar: dosya sistemi önbelleği, web sayfası önbelleği, yazılımda hafızalama (memoization). Genel fikir şudur: pahalı bir işi tekrar tekrar yapmak gerekiyorsa bir kez yapıp sonucu saklamak (ekrandan, 01:00:00).

Bu mantık bütün bellek hiyerarşisine yayılabilir. CPU ile ana bellek arasına bir önbellek konduğu gibi, ana bellek ile ikincil bellek birimleri arasında da benzer bir denetim gerekir. Çalıştırılacak kodun boyutu ana bellekteki boş alandan ya da programa ayrılan alandan büyük olabilir; ayrıca veri yönetimi küçük bloklarla yürütülebilir. Bu yüzden kodun tamamı bir seferde yüklenmek yerine sayfa (page) adı verilen bloklar halinde, sayfa sayfa yüklenir. Mantık önbellektekinin aynısıdır: ikincil bellekten ana belleğe bir sayfa yüklendiğinde o sayfadaki kod ve verilere büyük olasılıkla tekrar erişileceği için zamansal yerellikten, dizi ve matrislerde komşu verilere erişileceği için uzamsal yerellikten yararlanılır. Böylece veri ikincil bellekten yeniden okunmaz, ana bellekte bulunur.

Önbellek ile sanal bellek bir noktada daha benzeşir: büyük bir bellek alanını daha küçük bir bellek alanına haritalamak (eşlemek) için bir denetim gerekir. Önbellekte doğrudan eşlemeli yapı adresin bir kısmına göre yeri belirliyordu; tam ilişkili yapıda ise böyle bir eşleme yapılmadan bütün satırlarda arama yapılıyordu. Sanal bellekte de büyük bir adres alanı küçük bloklara adreslenmeli ve oraya taşınmalıdır.

Hoca önbellekle ilgili akılda kalması gereken tasarım sorularını şöyle sıraladı: önbellek boyutunun erişim hızına ve kapasiteye etkisi; doğrudan eşlemeli, tam ilişkili ve küme ilişkili yapılarda kaç küme olmasının anlamlı olduğu; hit ve miss oranlarının nasıl değiştiği; bir blok değiştirilecekse hangi kuralın kullanılacağı; birden fazla seviye önbellek kullanıldığında senaryonun nasıl değiştiği; veri store yönünde değiştirildiğinde güncellemenin nasıl yapılacağı. Bunların hepsi sistemin tekil ve toplam performansı açısından değerlendirilerek karar verilir.

## 7. Sanal Adres Uzayı ve Sayfalama

### 7.1 Sanal adres uzayı

Yazılan programlar kendi yerel adres uzaylarını kullanır; buna sanal bellek denir. Bir program çalıştırıldığında adresleri kendi adres uzayı içinde bir başlangıç referansına (orijin) göre ifade eder. Programın doğrudan genel bir fiziksel adresi göstermesi anlamlı değildir, çünkü çalıştırılmadan önce program bloğunun hangi fiziksel adrese yerleşeceği belli değildir. Her programın kendine ait bir sanal bellek uzayı vardır ve bu uzay fiziksel adres uzayından daha geniş olabilir: belleğe bir seferde sığmayacak bir program da olabilir, bellekte birden fazla programla birlikte küçük bir bloğa sığacak bir program da. Ayrıca enerji kesildiğinde kaybolmaması gereken veri ve programlar ikincil diskte saklanır ve çalıştırılmak için ana belleğe aktarılmaları gerekir. Bu etkileşimi yönetecek bir sisteme ihtiyaç vardır.

Böylece iki denetim katmanı oluşur: ikincil diskten belleğe taşımayı denetleyen sanal bellek denetimi ve ana bellekten CPU'ya taşırken kullanılan önbellek denetimi. Bir programın sanal adresi önce fiziksel adrese dönüştürülür; elde edilen fiziksel adres de önbellek adres yapısına göre bölünerek anlamlandırılır.

Ana bellekteki adresleme fiziksel adreslemeye dayanır: CPU'nun adres uçlarında bir değer oluşturulur ve bu değer bellekte gerçekten var olan bir hücreyi gösterir. Önbellekte bu fiziksel adrese karşılık bir önbellek adres bölümlemesi yapılıyordu; veri ararken ve yer değiştirirken bu mantık kullanılıyordu. Benzerini ikincil bellek ile ana bellek arasında da kullanmak gerekir. Program fiziksel bellekte bir yere yerleştiğinde, erişmek istediği adreslere yerleştiği yerin karşılığı eklenerek erişim yürütülür; bu, bellek yönetim birimiyle ilgili bir konudur ve doğrudan kullanıcıyı ilgilendirmez.

Ekrandaki slayt bu yapıyı şöyle özetler (ekrandan, 01:10:00):

```text
Program (kendi sanal      sanal adres            fiziksel adres         Fiziksel bellek
adres uzayında çalışır) --(komut getirme,--> HW eşleme --(komut getirme,--> (önbellekler dahil)
                           load, store)                  load, store)
```

- Her program kendi sanal adres uzayında, sanki tek çalışan programmış gibi çalışır.
- Programlar birbirinden korunur.
- Her programın bellekte nereye konacağına işletim sistemi karar verir.
- Sanaldan fiziksele eşlemeyi donanım sağlar.

### 7.2 Sayfa boyutu ve temel sorular

Önbellekte ana bellekten blok boyutu kadar veri aktarılıyordu. Blok boyutu belli bir miktara kadar arttırıldığında avantaj sağlıyor, aynı kapasitede arttırılmaya devam edildiğinde ise değiştirmeler çoğaldığı için ortalama erişim performansı düşüyordu; yani optimum bir blok genişliği vardı. Sanal bellekteki bloklara sayfa denir ve sayfa boyutu da benzer biçimde belirlenir: ana belleğin boyutu ve erişim süresi, ikincil bellek birimlerinin boyutu ve erişim süreleri, koşturulacak kodların türü ve yapısı dikkate alınarak optimal bir genişlik seçilir. Genel olarak KB mertebesinde sayfa genişlikleri kullanılır.

İncelenmesi gereken başlıklar şunlardır:

- Sayfa boyutu nasıl belirlenir (erişim sürelerine göre optimize edilir)?
- Ana bellekte boş yer varsa yeni sayfa oraya nasıl yüklenir?
- Ana bellek doluysa hangi sayfa çıkarılır (değiştirme politikası)?
- Aranan veri ana bellekte yoksa ikincil bellekten nasıl getirilir?
- Önbellekteki write-through/write-back gibi, güncellenen veride tutarlılık (coherence) nasıl sağlanır? Sistemler çok süreçli ve çok işlemcili olduğu için bir işlemin güncellediği veriye başka bir işlem ihtiyaç duyabilir; bunun uygun biçimde yönetilmesi gerekir.

Her programın kendine has bir bellek uzayı olması sistemi bir yandan kolaylaştırır, öte yandan sanal bellek yönetimini gerekli kılar.

### 7.3 Sayfalama örneği

Ekrandaki örnekte 1 KB'lık sayfalar kullanılır (ekrandan, 01:15:00). Fiziksel bellek 8 sayfadır (8 KB; sayfaların başlangıç adresleri 0, 1024, ..., 7168). Programın sanal adres uzayı 32 sayfadır (32 KB; başlangıç adresleri 0, 1024, 2048, ..., 31744). Bu 8 sayfanın hepsi programın kullanımında olmayabilir; bir kısmı işletim sistemine, bir kısmı başka kullanıcıların programlarına ayrılmış olabilir. 32 KB'lık bir program 8 KB'lık bir bellekte nasıl adreslenecektir?

- Sanal adres uzayı 32 KB = $2^{15}$ byte olduğu için sanal adres 15 bittir.
- Fiziksel bellek 8 KB = $2^{13}$ byte olduğu için fiziksel adres 13 bittir.
- Sayfa 1 KB = 1024 byte olduğu için sayfa içindeki adresi göstermek için $\log_2 1024 = 10$ bit gerekir. Bu alan sanal adreste **VPO** (virtual page offset), fiziksel adreste **PPO** (physical page offset) adını alır.
- Sanal adresin kalan $15 - 10 = 5$ biti hangi sayfaya erişildiğini verir: **VPN** (virtual page number).
- Fiziksel adresin kalan $13 - 10 = 3$ biti **PPN** (physical page number) alanıdır.

Belleğe sayfa sayfa yüklendiği için bir sayfadaki 1024 byte fiziksel bellekte de bir sayfanın içinde yer alır; offset değerleri sanal ve fiziksel tarafta birebir örtüşür. Dolayısıyla adres dönüşüm fonksiyonunun (address translation map) yapması gereken tek şey VPN'e karşılık PPN üretmektir. Bunu yapan tabloya **sayfa tablosu (page table)** denir. Sanal uzay fiziksel uzaydan geniş olduğu için birçok sanal sayfa aynı fiziksel sayfaya düşebilir; bu yüzden değiştirme ve arama mantıkları burada da gündeme gelir.

## 8. Sayfa Tablosu

### 8.1 Kim yönetir?

Sayfa tablosunu işletim sistemi yönetir. Bazı işletim sistemi uygulamalarında her program için ayrı bir tablo, bazılarında ortak bir tablo olur; her durumda tablo kernel tarafındadır ve kullanıcının doğrudan müdahale edebileceği bir yer değildir. Kullanıcı tabloyu değiştirebilseydi başka programların alanlarına erişebilirdi. Bu sayede kullanıcıların kendilerine izin verilen adres aralıklarının dışına çıkması da engellenir. Hoca sayfa tablosuyla ilgili ayrıntıların işletim sistemleri dersinde daha ayrıntılı görüleceğini söyledi.

### 8.2 Tablonun yapısı

Akla gelen ilk tasarım, her VPN değeri için bir satır içeren, yani $2^{VPN}$ satırlı ve her satırında bir PPN tutan tablodur. Bu tablo çok büyüktür ve ana bellekte tutulması gerekir. Üstelik satırlarının hepsi aynı anda etkin değildir: bir programın bir seferde tamamı değil, belirli sayfaları yüklenir; bellekte o programa ait az sayıda sayfa vardır. Bu yüzden tablo seyrektir (sparse), çoğu satırı boştur.

Sayfa tablosunun her satırına **sayfa tablosu girdisi (page table entry, PTE)** denir. Bir girdide şunlar bulunur (ekrandan, 01:20:00):

- **Valid biti:** O VPN-PPN dönüşümünün geçerli olup olmadığını gösterir. Sistem ilk başlatıldığında ya da program ilk yüklendiğinde valid bitleri 0'dır.
- **Erişim hakları (access rights):** Örneğin bir alan birinci kullanıcının erişimine açılmışsa ikinci kullanıcı erişmek istediğinde erişim hakkı olup olmadığına bakılır ve hakkı yoksa izin verilmez. Erişim hakları kullanıcıya ve programlar arası erişime göre belirlenir.
- **Fiziksel sayfa numarası (PPN):** VPN'in hangi fiziksel sayfaya eşlendiğini tutar.

Tablo VPN ile indekslenir. Önceki örnekte 5 bitlik VPN ile tablodan 3 bitlik PPN okunur; bu 3 bit 10 bitlik offset ile birleştirilerek 13 bitlik fiziksel adres elde edilir. Bellek 13 bitlik olduğu için bu adres doğrudan erişilebilir bir hücreyi gösterir.

Güncel işlemcilerde bu tabloların kurulması ve tablolara erişim özel yazmaçlarla sağlanır. Tablo ana bellekte bir yerde oluşturulur; başlangıç adresi bir taban yazmacında (page table base register) tutulur ve o bölgeye yalnız işletim sistemi erişebilir.

### 8.3 Sayfa tablosunun sağladıkları

- Ortak bir ana belleğin kullanımı ve yönetimi sağlanır.
- Farklı kullanıcılar ve programlar arasındaki erişim izinleri düzenlenir.
- Program kodlanırken ya da makine koduna çevrilirken kendine ait bir sanal adres uzayı olur. Programcı yazdığı kodun fiziksel olarak nereye erişeceğini düşünmek zorunda kalmaz; adres dönüşümlerini işlemci ya da bellek yönetim birimi yapar.

Bir sanal adres üretildiğinde tablo üzerinden fiziksel adrese dönüştürülür. Sayfa ana bellekte varsa erişim önbellek üzerinden yürür. Aranan sayfa ana bellekte yoksa işletim sistemi süreci devralır ve sayfayı ana belleğe getirir.

## 9. Önbellek ile Sanal Belleğin Karşılaştırılması

Ekrandaki karşılaştırma slaytının içeriği anlatımdan şöyle derlenebilir (ekrandan, 01:25:00):

```text
Önbellek                              Sanal bellek
Blok ya da satır (block/line)         Sayfa (page)
Miss                                  Page fault
Blok boyutu: 50-100 byte mertebesi    Sayfa boyutu: 8-10 KB mertebesi
Direct mapped, set assoc., fully assoc.  Tam ilişkili
LRU, FIFO, rastgele                   LRU türü
Write-through ya da write-back        Write-back
```

- Sanal bir adres üretilip tabloya bakıldığında aranan sayfanın ana belleğe yüklenmemiş olduğu anlaşılırsa page fault oluşur ve işletim sistemi devreye girip sayfayı yükler.
- Sanal bellekte tam ilişkili mantık kullanılır. Tablo seyrek olduğu için doğrudan eşleme yapılsaydı aynı yere denk gelme ve belleğin bir kısmını hiç kullanmama riski olurdu; daha esnek bir yapı gerekir.
- İkincil bellek birimlerine erişim çok daha yavaş olduğu için write-through burada düşünülmez; write-back mantığı kullanılır.

<!-- BELİRSİZ: Karşılaştırma slaytının satırları kare anında henüz görünmüyordu; tablo altyazıdaki anlatımdan derlendi. -->

## 10. Translation Lookaside Buffer (TLB)

### 10.1 Neden gerekir?

Sayfa tablosu, farklı VPN değerleri kadar satır içerdiği için çok büyüktür ve satırlarının hepsi etkin değildir. Bunu iyileştirmek için sayfa tablosu bir önbellek gibi düşünülerek sanal adres ile fiziksel adres arasındaki dönüşümü yapan ayrı bir denetim eklenebilir. Buna **Translation Lookaside Buffer (TLB)** denir; sanal belleğin önbelleğidir (ekrandan, 01:30:00). Aranan dönüşüm için büyük sayfa tablosunun satırlarına bakmak yerine bu küçük ara bloğa bakılır; dönüşüm varsa PPN doğrudan buradan alınır.

Slayttaki tanım: VM dönüşümünü hızlandırmanın bir yolu, yakın zamanda kullanılan sayfa tablosu girdileri için özel bir önbellek kullanmaktır; bunun birçok adı vardır, en sık kullanılanı TLB'dir. TLB aslında sayfa tablosu eşlemeleri üzerinde bir önbellektir; erişim süresi önbellek erişim süresine yakın, ana bellek erişim süresinden çok kısadır.

TLB girdisinde şunlar bulunur (ekrandan, 01:30:00):

```text
Virtual Address | Physical Address | Dirty | Ref | Valid | Access
```

### 10.2 TLB ile erişim akışı

TLB küçük bir yapıdır ve küme ilişkili bir önbellek mantığıyla kullanılabilir: doğrudan indeksleme aramayı kolaylaştırır, satırdaki kümeler arasındaki değişim de esneklik sağlar. Akış şöyledir:

1. Program erişmek istediği değer için bir sanal adres üretir.
2. Sanal adres bölünerek TLB'nin hangi satırına bakılacağı belirlenir; o satırın bütün kümelerinde aranan VPN var mı diye bakılır.
3. VPN TLB'de bulunur ve valid biti 1 ise bu dönüşüm sayfa tablosunda da geçerlidir; TLB hit olur ve fiziksel adres doğrudan hesaplanır.
4. VPN TLB'de yoksa (TLB miss) dönüşüm sayfa tablosundan TLB'ye getirilir, sonra fiziksel adres oluşturulur.
5. Fiziksel adres oluştuktan sonra önbellek adres bölümlemesine göre veri önbellekte aranır. Önbellekte varsa doğrudan CPU'ya aktarılır, yoksa ana bellekten getirilir.

TLB olmasaydı CPU'nun ürettiği her sanal adres doğrudan sayfa tablosunda aranacaktı. Veri ve komut için ayrı TLB blokları da düşünülebilir.

**Soru:** Şekildeki dönüşüm (translation) kısmı aslında bir sayfa tablosu mu?
**Cevap:** Evet, orası sayfa tablosudur.

## 11. Sanal Bellek Örnekleri

### 11.1 Example-1

Bir sanal bellek sistemi 4 KB'lık sayfalar, 64 bitlik word'ler ve 48 bitlik sanal adres kullanıyor; bir program ve verisi 4395 sayfa gerektiriyor (ekrandan, 01:35:00). Hoca bu örnekte yalnız adres alanlarını hesapladı: sayfa 4 KB = $2^{12}$ byte olduğu için VPO = PPO = 12 bit, VPN = $48 - 12 = 36$ bit. Fiziksel adres genişliği verilmediği için PPN hesaplanamaz. Slayttaki (a) ve (b) soruları derste çözülmedi; soru ve çözüm Örnek Sorular bölümündedir.

### 11.2 Example-2: TLB'de arama

Küçük bir TLB'de VPN 20 bit, PPN 12 bit, sayfa offset'i 12 bittir; dolayısıyla sanal adres 32 bit, fiziksel adres 24 bittir (ekrandan, 01:40:00). TLB tam ilişkilidir; tag alanında VPN'in kendisi saklanır. TLB girdileri:

```text
Valid  Dirty  Tag (VPN)  Data (PPN)
1      1      01AF4      FFF
0      0      0E45F      E03
0      0      012FF      2F0
1      0      01A37      788
1      0      02BB4      45C
0      1      03CA0      657
```

Sayı ve offset'ler onaltılıktır. Her sanal adreste son 3 onaltılık hane (12 bit) offset, ilk 5 hane VPN'dir.

- **(a) 02BB4A65:** VPN 02BB4 TLB'de valid 1 ile vardır; PPN 45C. TLB hit; fiziksel adres PPN ile offset birleştirilerek 45CA65 olur.
- **(b) 0E45FB32:** VPN 0E45F TLB'de vardır ama valid biti 0'dır; bu bir TLB miss'tir. TLB sayfa tablosunun yalnız bir özeti olduğu için page fault olup olmadığı buradan söylenemez; soru işareti olarak kalır.
- **(c) 0D34E9DC:** VPN 0D34E TLB'de yoktur; TLB miss. Page fault olup olmadığı yine söylenemez.
- **(d) 03CA0777:** VPN 03CA0 vardır ama valid biti 0'dır; TLB miss. Hoca bu girdinin dirty bitine dikkat çekti: valid biti 1 olsaydı TLB hit olurdu (fiziksel adres 657777), ancak dirty biti 1 olduğu için sayfa tablosundaki değer güncel olmazdı ve girdi TLB'den çıkarılırken sayfa tablosunun güncellenmesi gerekirdi.

> **Ders sonrası not:** Hoca bu açıklamayı yaparken bir yerde "C şıkkı" dedi; ekrandaki tabloya göre dirty biti 1 olan girdi (d) şıkkındaki 03CA0 girdisidir. Ayrıca hoca (c) şıkkı için bir an "page fault olduğunu da söyleyebiliriz" dedi, hemen ardından aranan girdi bulunamadığı için bir şey söylenemeyeceğini belirtti; doğrusu, TLB'ye bakarak page fault hakkında karar verilemeyeceğidir.

## 12. Sayfa Değiştirme Politikaları

Aranan sayfa ana bellekte yoksa ikincil bellekten getirilip bellekteki bir sayfanın yerine konmalıdır. Önbellekteki değiştirme politikalarına benzer seçenekler vardır:

- **Rastgele:** Rastgele bir sayfa çıkarılır.
- **FIFO:** Bellekteki sayfalar arasında ilk yüklenen (en eski) sayfa çıkarılır.
- **Optimal (minimum):** Gelecekte en uzun süre ihtiyaç duyulmayacak sayfa çıkarılır. Tam olarak hesaplanamaz, ancak tahminle yaklaşılabilir.
- **LRU:** Uzun zamandır kullanılmayan sayfa çıkarılır.
- **NFU (not frequently used):** Sık kullanılmayan sayfa çıkarılır. Bir sayfaya yakın zamanda erişilmiş olabilir, ama 100 erişimde bir kullanılıyorsa önümüzdeki uzun süre boyunca sırası gelmeyecek demektir. Bu LRU değildir, ama optimal politikaya bir tahmin kapısı açar.

Üç politika aynı örnek üzerinde karşılaştırıldı: bellekte 3 sayfalık çerçeve (frame) vardır, hepsi başta boştur, sayfa referans dizisi `A B C A B D A D B C B`'dir (ekrandan, 01:45:00 ve 01:50:00).

### 12.1 FIFO

İlk üç erişim (A, B, C) boş çerçevelere yerleşir ve üç page fault oluşturur. A ve B çerçeve 1 ve 2'de bulunduğu için hit olur. D geldiğinde ilk giren A'dır; A çıkarılıp yerine D konur (çerçeve 1). Bellekte D, B, C vardır. A gelince ilk giren artık B'dir; B çıkarılıp A konur (çerçeve 2). D hit olur. B gelince ilk giren C'dir; C çıkarılıp B konur (çerçeve 3). C gelince ilk giren D'dir; D çıkarılıp C konur (çerçeve 1). Son B hit olur. Toplam **7 page fault**.

```text
Ref:     A  B  C  A  B  D  A  D  B  C  B
Frame1:  A  A  A  A  A  D  D  D  D  C  C
Frame2:     B  B  B  B  B  A  A  A  A  A
Frame3:        C  C  C  C  C  C  B  B  B
Fault:   *  *  *        *  *     *  *
```

### 12.2 Optimal

İlk üç erişim yine üç fault'tur; A ve B hit olur. D geldiğinde bellekte A, B, C vardır. Geleceğe bakılır: A ve B'ye yakında erişilecek, C'ye ise en geç erişilecektir. C çıkarılır, yerine D konur (çerçeve 3). A, D, B hit olur. C geldiğinde yakında B'ye erişileceği, A ve D'ye ise uzun süre (bu dizide hiç) erişilmeyeceği görülür; C, çerçeve 1'e ya da çerçeve 3'e konabilir, sonuç değişmez (birden çok eşit aday varsa biri rastgele seçilir). Son B hit olur. Toplam **5 page fault**.

### 12.3 LRU

İlk üç fault ve A, B hit'leri aynıdır. D geldiğinde en son B'ye, ondan önce A'ya erişilmiştir; C en uzun süredir kullanılmayandır. C çıkarılır, D konur. A, D, B hit olur. C geldiğinde bellekte A, B, D vardır; yakın zamanda B'ye ve D'ye erişilmiş, A'ya ise uzun süredir erişilmemiştir. A çıkarılır, C konur. Son B hit olur. Toplam **5 page fault**.

> **Ders sonrası not:** Hoca LRU örneğinin sonunda toplamı "5-6" gibi söyledi. Adımlar sayıldığında LRU için 5 page fault çıkar (python ile kontrol edildi).

## 13. Sanal Adres, Fiziksel Adres ve Önbellek Bölümlemesi

Son olarak sanal adres uzayı ile fiziksel adres uzayı birbirine bağlandıktan sonra, bunların önbelleğe de bağlandığı süreç bir örnek soru üzerinden incelendi (ekrandan, 01:55:00). Hoca bu sorunun ödevdeki konuyla çok benzediğini söyledi.

### 13.1 Alan genişlikleri

Sistemde sayfa boyutu 1 KB, veri yolu genişliği 32 bit, sanal adres genişliği 20 bit, fiziksel adres genişliği 18 bittir (ekrandan, 02:00:00):

- Sayfa 1 KB = $2^{10}$ byte olduğu için VPO = PPO = 10 bit.
- VPN = $20 - 10 = 10$ bit.
- PPN = $18 - 10 = 8$ bit.

Sayfa tablosunda indeksler 3 onaltılık haneyle yazılmıştır, ama VPN 10 bit olduğu için en yüksek anlamlı 2 bit her zaman 0'dır; satırlar 0'dan 1023'e kadardır, yani $2^{10} = 1024$ satır vardır. Sayfa tablosunda VPN saklanmaz, çünkü VPN zaten satır indisidir. Her satırda 8 bitlik (2 onaltılık haneli) PPN, valid biti ve ekranda görünmese de erişim hakları bulunur.

TLB'de tag, PPN ve valid sütunları vardır; ekranda görünmese de erişim hakları da saklanır. TLB tam ilişkilidir ve 16 girdisi vardır. Tam ilişkili olduğu için herhangi bir girdi herhangi bir yere konabilir; bu yüzden TLB tag'i VPN'in kendisidir ve VPN genişliğindedir. Sayfa tablosunda ise VPN saklanmaz; ikisi karıştırılmamalıdır.

Ekrandaki TLB ve sayfa tablosunun (ilk 32 satır) içeriği (ekrandan, 02:10:00):

```text
TLB                      Sayfa tablosu (VPN: PPN valid)
Tag  PPN  Valid          000: 1F 1   008: 02 0   010: 60 0   018: C3 1
01E  71   0              001: 28 1   009: 35 1   011: 57 0   019: 04 0
013  35   1              002: 93 1   00A: 41 0   012: A1 1   01A: F1 1
3A1  F1   0              003: AB 0   00B: 86 1   013: 35 1   01B: 12 1
022  30   1              004: D6 0   00C: A1 1   014: 0D 0   01C: 30 0
012  A1   1              005: 53 1   00D: D5 1   015: 2B 0   01D: 4E 1
033  4E   1              006: 1F 1   00E: 8E 0   016: 9F 0   01E: 57 1
000  1F   1              007: 80 1   00F: D4 0   017: 62 0   01F: 38 1
324  09   0
```

### 13.2 Sanal adres 0x04AA4

İkilik yazılış `0000 0100 1010 1010 0100`'dür (ekrandan, 02:05:00). Düşük anlamlı 10 bit offset'tir: `10 1010 0100` = 0x2A4 (VPO). Yüksek anlamlı 10 bit VPN'dir: `00 0001 0010` = 0x012. TLB tam ilişkili olduğu için TLB tag'i de 0x012'dir. TLB'de 012 valid biti 1 ile vardır ve PPN'si A1'dir: **TLB hit**, page fault yok. PPN = A1 = `1010 0001` (8 bit) ile offset `10 1010 0100` birleştirilir:

$$\text{PA} = \texttt{1010 0001 10 1010 0100}_2 = \texttt{0x286A4}$$

Hoca burada, TLB 4 yollu küme ilişkili gibi başka bir yapıda olsaydı 10 bitlik VPN'in index ve tag alanlarına ayrılması gerekeceğini, o durumda TLB tag'inin VPN ile birebir aynı olmayacağını hatırlattı.

### 13.3 Sanal adres 0x078E6

İkilik yazılış `0000 0111 1000 1110 0110`'dır. Düşük 10 bit `00 1110 0110` = 0x0E6 (VPO), yüksek 10 bit `00 0001 1110` = 0x01E (VPN ve TLB tag'i). TLB'de 01E vardır ama valid biti 0'dır: aranan dönüşüm TLB'de bulunamadı, **TLB miss**. Page fault olup olmadığını anlamak için sayfa tablosunun 01E satırına bakılır: valid biti 1, PPN 57. Dolayısıyla **page fault yok**. PPN 0x57 (8 bit) ile 10 bitlik offset birleştirilerek 18 bitlik fiziksel adres elde edilir: **0x15CE6** (ekrandan, 02:05:00).

### 13.4 Önbellek bölümlemesi

Önbellek toplam 512 word saklar; her satırda 8 küme (yol) vardır ve her blokta 8 word bulunur (ekrandan, 02:15:00). Veri yolu 32 bit olduğu için bir word 4 byte'tır.

- Bir satırda $8 \times 8 = 64$ word vardır; satır sayısı $512 / 64 = 8$, index için **3 bit** gerekir.
- Bir blokta 8 word olduğu için word offset **3 bit**.
- Bir word 4 byte olduğu için byte offset **2 bit**.
- Tag: $18 - 3 - 3 - 2 =$ **10 bit**.

### 13.5 Sanal adres 0x000F4 için önbellekteki yer

Sanal adres 0x000F4'ün yüksek 10 biti VPN = 0'dır. TLB'de 000 valid biti 1 ile vardır, PPN 1F'dir. Fiziksel adres 8 bitlik PPN (`0001 1111`) ile 10 bitlik offset (`00 1111 0100`) birleştirilerek bulunur:

```text
PA = 00 0111 1100 | 111 | 101 | 00
     tag (10 bit) | idx | wo  | bo
```

- Byte offset `00` = 0, word offset `101` = 5, index `111` = 7, tag `00 0111 1100` = 0x07C.
- 7 numaralı satıra gidilir; satırdaki her kümenin valid biti ve tag alanı 0x07C ile karşılaştırılır. Eşleşme ve valid 1 bulunursa aranan veri o kümedeki 8 word'lük (32 byte'lık) bloğun 5 numaralı word'ünün 0 numaralı byte'ıdır.

Örnekte önbelleğin veri içeriği verilmediği için önbellek içeriği gösterilemez; yapılması gereken bu bölümlemedir.

Hoca bu örnekle şunu bağladı: sanal adres uzayı ile fiziksel adres uzayı arasındaki dönüşüm bu haftanın konusudur, ama bu dönüşümün önbellek adres bölümlemesiyle de bağlantısı vardır. Fiziksel adres sayfa tablosu ya da TLB üzerinden elde edilir; elde edilen fiziksel adresin önbellekte nereye karşılık geldiğini bulmak için önbellek yapısına göre yeniden bölünmesi gerekir. Sanal adres, fiziksel adres ve önbellek bölümlemesi birbirine bağlı olarak yürür.

## 14. Örnek Sorular

### Soru 1 (ekrandan, 00:20:00)

16 byte'lık bir bellek (adres 0-15 içerikleri: 78, 29, 120, 123, 71, 150, 162, 173, 18, 21, 33, 28, 19, 200, 210, 225), 4 byte kapasiteli, 2 byte bloklu, tam ilişkili, LRU'lu ve başta boş bir önbellek veriliyor. `Ld R1←M[1]`, `Ld R2←M[7]`, `St R2→M[0]`, `St R1→M[5]`, `Ld R2←M[10]` komutları write-through politikasıyla yürütüldüğünde hit/miss sayıları, yazmaçlar ve bellek ne olur?

> **Çözüm (derste verildi):** Adres 3 bit tag + 1 bit offset. Sırasıyla load miss, load miss, store hit, store miss, load miss: 4 miss, 1 hit. R1 = 29, R2 = 33. Bellekte M[0] = 173, M[5] = 29 (her store hem önbelleğe hem belleğe yazılır). Son durumda önbellekte tag 5 (33, 28) ve tag 2 (71, 29) blokları vardır.

### Soru 2 (ekrandan, 00:35:00)

Soru 1'deki önbellek ve komut dizisi write-back politikasıyla (dirty bitli) yürütülürse ne değişir?

> **Çözüm (derste verildi):** Hit/miss dizisi aynıdır (4 miss, 1 hit). `St R2→M[0]` yalnız önbelleği günceller (dirty = 1), `St R1→M[5]` store miss'te dirty 0 olan tag 3 satırını yazmadan çıkarır, 4-5 bloğunu getirip 29 yazar (dirty = 1). Son `Ld R2←M[10]`'da LRU satır dirty biti 1 olan tag 0 satırıdır; önce 173 ve 29 belleğe (M[0], M[1]) yazılır, sonra 33, 28 getirilir, R2 = 33. Bellekte M[5] hâlâ 150'dir; güncel değer (29) önbellekte dirty olarak durur.

### Soru 3 (ekrandan, 01:35:00)

Bir sanal bellek sistemi 4 KB'lık sayfalar, 64 bitlik word'ler ve 48 bitlik sanal adres kullanıyor. Belirli bir program ve verisi 4395 sayfa gerektiriyor. (a) En az kaç sayfa tablosu gerekir? (b) Son sayfa tablosunda kaç girdi vardır?

> **Derste verilen kısım:** VPO = PPO = 12 bit, VPN = $48 - 12 = 36$ bit.

> **Çözüm (derste verilmedi):** Her sayfa tablosu girdisinin bir word (8 byte) olduğu ve bir sayfa tablosunun bir sayfaya sığdığı varsayılırsa, bir tablo $4096 / 8 = 512$ girdi tutar. (a) $\lceil 4395 / 512 \rceil = 9$ sayfa tablosu gerekir. (b) İlk 8 tablo $8 \times 512 = 4096$ girdi tutar; son tabloda $4395 - 4096 = 299$ girdi vardır. (Varsayım büyük olasılıkla sorunun kastettiği varsayımdır; python ile hesaplandı.)

### Soru 4 (ekrandan, 01:40:00)

VPN 20 bit, PPN 12 bit, sayfa offset'i 12 bit olan küçük bir TLB'nin girdileri Bölüm 11.2'deki tabloda verilmiştir. (a) 02BB4A65, (b) 0E45FB32, (c) 0D34E9DC, (d) 03CA0777 sanal adreslerinin her biri için hit olup olmadığını, hit ise fiziksel adresi belirtiniz.

> **Çözüm (derste verildi):** (a) Hit, fiziksel adres 45CA65. (b) Girdi var ama valid 0: TLB miss; page fault TLB'den belirlenemez. (c) VPN TLB'de yok: TLB miss; page fault belirlenemez. (d) Girdi var ama valid 0: TLB miss. Valid 1 olsaydı hit olurdu (657777) ve dirty biti 1 olduğu için sayfa tablosunun güncellenmesi gerekirdi.

### Soru 5 (ekrandan, 01:45:00)

Üç sayfalık, başta boş bir bellekte `A B C A B D A D B C B` referans dizisi için FIFO, optimal ve LRU politikalarıyla kaçar page fault oluşur?

> **Çözüm (derste verildi):** FIFO 7, optimal 5, LRU 5 page fault (python ile kontrol edildi).

### Soru 6 (ekrandan, 01:55:00)

Şekil ile verilen sanal bellek, TLB, sayfa tablosu ve önbellek yapısı için sayfa boyutu 1 KB, veri yolu genişliği 32 bit, sanal adres genişliği 20 bit, fiziksel adres genişliği 18 bittir. Önbellek 512 word, 8 yollu, 8 word'lük bloklu; TLB ve sayfa tablosu içeriği Bölüm 13.1'deki tablodadır.

a) Adres dönüşümünde oluşan adres parçalarının kaç bit uzunlukta olduğunu ve sayfa tablosu satır sayısını bulunuz.

b) 0x04AA4 ve 0x078E6 sanal adresleri için VPN, VPO, TLB tag'i, TLB hit/miss, page fault, PPN ve fiziksel adresi (onaltılık) bulunuz.

c) Boş bir önbellekle başlandığı varsayılarak sırasıyla 0x000F4, 0x004E2 ve 0x008F1 sanal adreslerine erişilirse önbellek içeriğinin son hali nasıl olur?

> **Çözüm (derste verildi, a ve b):** VPO = PPO = 10 bit, VPN = 10 bit, PPN = 8 bit; sayfa tablosu $2^{10} = 1024$ satır. Önbellek: index 3 bit, word offset 3 bit, byte offset 2 bit, tag 10 bit. 0x04AA4: VPN 0x012, VPO 0x2A4, TLB tag 0x012, TLB hit, page fault yok, PPN 0xA1, fiziksel adres 0x286A4. 0x078E6: VPN 0x01E, VPO 0x0E6, TLB tag 0x01E, TLB miss, page fault yok, PPN 0x57, fiziksel adres 0x15CE6.

> **Çözüm (c'nin ilk adresi derste verildi):** 0x000F4: VPN 000, TLB hit, PPN 1F, fiziksel adres 0x07CF4; tag 0x07C, index 7, word offset 5, byte offset 0.

> **Çözüm (derste verilmedi, c'nin kalan adresleri):** 0x004E2: VPN 001, TLB'de yok (TLB miss), sayfa tablosunda 28 valid 1 (page fault yok); fiziksel adres 0x0A0E2, tag 0x0A0, index 7, word offset 0, byte offset 2. 0x008F1: VPN 002, TLB miss, sayfa tablosunda 93 valid 1; fiziksel adres 0x24CF1, tag 0x24C, index 7, word offset 4, byte offset 1. Üç adres de 7 numaralı satıra düşer ama tag'leri farklıdır; satır 8 yollu olduğu için çakışma olmaz. Önbellek boş başladığı için son durumda 7 numaralı satırın üç yolu dolar (yerleştirme sırasıyla tag 0x07C, 0x0A0, 0x24C; her birinde ilgili 32 byte'lık blok, valid 1); diğer bütün yollar boştur. (Python ile hesaplandı.)

## Dersin Toparlaması

Dersin ilk bölümünde önbellekte yazma işlemleri ele alındı. Write-through her yazmayı hem önbelleğe hem ana belleğe yansıtarak tutarlılığı her zaman sağlar; write-back yazmayı yalnız önbellekte yapar, değişen bloğu dirty biti ile işaretler ve blok çıkarılırken belleğe yazar. Store miss için write-allocate ve no-write allocate seçenekleri tanıtıldı. İki politika aynı komut dizisi ve aynı tam ilişkili önbellek üzerinde adım adım karşılaştırıldı.

İkinci bölümde önbellek mantığı bellek hiyerarşisinin bir alt katmanına, ana bellek ile ikincil bellek arasına taşındı. Her programın kendi sanal adres uzayı olduğu; sanal adresin VPN ve VPO'ya, fiziksel adresin PPN ve PPO'ya bölündüğü; VPN'den PPN'ye dönüşümün işletim sisteminin yönettiği sayfa tablosuyla yapıldığı ve bu dönüşümün TLB ile hızlandırıldığı görüldü. Sayfa değiştirme politikaları (FIFO, optimal, LRU) bir örnekle karşılaştırıldı. Son olarak bir örnek soruda sanal adresin TLB ve sayfa tablosu üzerinden fiziksel adrese dönüştürülmesi ve fiziksel adresin önbellek yapısına göre tag, index, word offset ve byte offset alanlarına bölünmesi birlikte uygulandı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
