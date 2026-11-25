# Ders 15 Genişletilmiş Notu: Kesmeler (Interrupt) ve Vektör Tablosu

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Akışı
- 2. Kesme (Interrupt) Nedir?
- 3. İşlemci ile Yavaş Birimler Arasındaki İlişki
- 4. Zaman ve Grafik Kesmeleri
- 5. Kesme Çeşitleri
- 6. Kesme Öncelikleri
- 7. Kesme Oluştuğunda Yapılan İşlemler
- 8. Kesmeden Dönüş ve Yığın Kullanımı
- 9. Vektör Tablosunun Görevi ve Konumu
- 10. Vektör Tablosunda Değişiklik
- 11. Kesme Servis Programı Yazarken Dikkat Edilecekler
- 12. Kesmeleri Kullanırken
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Akışı

Önceki haftalarda EXE ve COM tipi program yapısı, makro ve yordam kullanımı, yordamlar ve makrolar arasında parametre aktarımı, ortak veri ve kod kesimi kullanımı ve harici yordamlarda yığın kesiminin ortak kullanımı ile parametrelerin yığın üzerinden aktarılması işlenmişti. Bu derste kesmeler (interrupt) anlatıldı: kesmenin temel çalışma prensibi ve assembly dilinde kesmelerin nasıl kullanıldığı. Ders Zoom üzerinden, slayt paylaşılarak yürütüldü; slaytların köşesinde "BLM2021 Alt Seviye Programlama, Hafta 13" yazıyordu (ekrandan, 00:15:00). Derste kod yazılmadı ya da çalıştırılmadı; konu slaytlar üzerinden kavramsal olarak anlatıldı.

## 2. Kesme (Interrupt) Nedir?

Slayttaki tanım şöyledir (ekrandan, 00:15:00):

> Çeşitli kriterler ve önceliklerle program işleyişlerinin kesintiye uğratılarak eş zamanlı çalışmanın sağlanması interrupt mekanizması ile sağlanır.

Hoca konuya bir 8086 işlemci ile başladı ve günümüzün çok çekirdekli işlemcilerini de andı. Temel gözlem şudur: herhangi bir işlemci (çekirdek) aynı anda yalnız tek bir iş yapabilir. Müzik çalıyorsa yalnız onu, web sayfası gösteriyorsa yalnız onu, Word belgesi ya da oyun çalıştırıyorsa yalnız onu yapabilir. Tek işlemcinin aynı anda birden fazla işi eş zamanlı yürütme imkânı yoktur.

Çok çekirdekli işlemciler de bu sorunu tek başına çözmez. Bilgisayar açıldığında yalnız işletim sisteminin çalışması için gerekli yüz, iki yüz alt program görev yöneticisinde görülebilir. Bilgisayarın saatinin belirli aralıklarla güncellenmesi, görüntünün ekrana yansıtılması, internet trafiğinin denetlenmesi, diske yazma ve okuma işlerinin her biri ayrı programlardır. Buna rağmen kullanıcı aynı anda müzik dinleyip oyun oynayabilir ve mesajlaşabilir. Bunun nasıl mümkün olduğu sorusunun cevabı kesme mekanizmasıdır.

### 2.1 İşlemci neden en hızlı birimdir?

İşlemci, bilgisayardaki diğer elektronik birimlerden (temelde RAM ve disk) ve çevre birimlerinden çok daha hızlı çalışır. Disklerin (HDD, SSD ve yeni nesil hızlı SSD'ler) yazma ve okuma hızları her geçen gün artıyor, ama yine de işlemciyle yarışamıyorlar. Hoca RAM hızlarındaki artışın işlemcilerdekinden daha fazla olduğunu söyledi; örneğin 3200 MHz'lik bir RAM 4,2 GHz'lik bir işlemciye hız olarak yaklaşmış olabilir, ama işlemcinin 10 çekirdeği vardır. Bu yüzden işlemci hâlâ bilgisayarın içindeki en hızlı birimdir.

Çevre birimleri (fare, klavye, yazıcı, monitör) ise çok daha yavaştır. Bir saniyede klavyeye ancak birkaç kez basılabilir. Monitörler saniyede 50, 120, 200 kez, belki 1000 kez yenilenir. İşlemci ise saniyede milyarlarca işlem yapabilecek kapasitededir.

Bu yüzden işlemci yavaş çalışan birimlerle sırayla ilgilenir. Ekranın saniyede 50 kez yenilenmesi gerekiyorsa ve bir yenileme nanosaniyeler mertebesinde sürüyorsa, işlemci ekranı yeniler, sonra başka birinin işiyle uğraşır: müziğin notalarını hoparlöre verecek işi yapar, oyunun aksiyonlarını işler, internetten yapılan aramayı yürütür. Bunların hepsini kullanıcının fark edemeyeceği bir hızla, hiçbiri gerçek zamanı kaçırmayacak şekilde yapar. İşlemci %100 yükte çalıştığında bu hız yakalanamaz; fareden gelen sinyali alıp işleyecek programa sıra gelmez ve fare bile hareket ettirilemez. Donma bu yüzden olur.

Hoca kesmeyi "bölmek, ara verdirmek" olarak açıkladı: "Sen dur, ben çalışayım; sen dur, ben çalışayım." Dersin yürütüldüğü anda bile Zoom programı, PowerPoint, mikrofondan sesi okuyan ve kameradan görüntüyü alan sürücüler ayrı programlardır ve her biri kesmelerle sırayla çalışarak aynı anda çalışıyormuş gibi görünür.

## 3. İşlemci ile Yavaş Birimler Arasındaki İlişki

Kesme mekanizması günümüzde de, 8086 döneminde de etkin olarak kullanılır. Ondan önce ya da onun yanında başka yöntemler de düşünülmüştür. Slaytta üç yöntem sıralanır (ekrandan, 00:25:00): busy waiting, polling ve interrupt. Hoca üçünü de "eve misafir gelecek" benzetmesiyle anlattı.

### 3.1 Busy waiting

Bir porttan bir birimin işlemciden hizmet isteyip istemeyeceği beklenir; işlemci bu sırada boşta bekler. Benzetmede misafirin hangi saatte geleceği bilinmez; ev sahibi misafir kapıda beklemesin diye kapıya çıkar ve hiçbir başka işle uğraşmadan orada bekler. Misafir gelince içeri alınır, ağırlanır, uğurlanır; yenisi gelene kadar yine kapıda beklenir. İşlemcinin, o iş için istek gelene kadar boşta beklemesine busy waiting denir.

Hoca örnek olarak yalnız bir yazıcıya atanmış bir işlemci düşündürdü: yazıcı sürekli bağlı ve hazır, ama belki bir aydır hiç istek gelmemiş. İşlemci saniyede çok sayıda işlem yapabilecek kapasitedeyken, belki bir iş gelir diye boşta bekler.

### 3.2 Polling

Polling, busy waiting'den "bir tık daha iyi" bir yöntemdir. Misafiri kapıda beklemek yerine ev sahibi içeride başka işlerle uğraşır ve belirli aralıklarla (örnekte "her 5 dakikada bir") kapıya gidip misafirin gelip gelmediğine bakar. Aralığın 5 dakika olması yalnız örnektir; gerçekte belirli bir zaman aralığı (time interval) vardır.

Dezavantajı şudur: ev sahibi kapıyı kapattığı anda misafir gelmiş olabilir; o zaman misafir bir sonraki kontrole kadar, 4 dakika 59 saniyeye kadar bekleyebilir. Avantajı ise kontroller arasındaki sürede başka isteklere cevap verilebilmesidir. Kontrol anında misafir 4,5 dakika, 2 dakika ya da yalnız 1 saniye beklemiş olabilir.

Hoca polling'in busy waiting'e göre daha avantajlı olduğunu, ama busy waiting'in de günümüzde hâlâ kullanıldığını belirtti.

### 3.3 Interrupt

Interrupt mekanizmasında kapıya bir zil konur. Ev sahibi oturup kitabını okur; misafir gelince zili çalar. Ev sahibi kitabın arasına bir ayraç koyar, gerekirse kaldığı satırın altını çizer, kapıya gidip misafiri alır, sonra kitabına kaldığı yerden devam eder. Yeni bir misafir gelirse yine zil çalar.

Burada önemli olan iki noktadır. Birincisi, ev sahibi misafir gelecekmiş gibi davranmaz; kendi işlerini (kitap okumak, yemek yapmak, televizyon izlemek) yapar, onu bölen misafirdir. İkincisi, kesilen bir programın nerede durdurulduğu bir yerde tutulmalıdır. Kitaba ayraç koymak gibi, program yeniden çalıştırılmak istendiğinde kaldığı yerin bilinmesi gerekir.

## 4. Zaman ve Grafik Kesmeleri

Bilgisayarda çalışan birçok program zamana duyarlı olabilir: her gece saat birde bir şeyleri kontrol eden, güncellemelerle zamana göre ilgilenen ya da her 5 saniyede bir çeşitli işlemler yapan programlar. Ekranın yenilenmesi de belirli bir frekansta olur. Hoca, frekansa dayalı çalışan her şeyin temelde zaman kesmeleri tarafında olduğunu söyledi; bilgisayarın saatinin güncellenmesi de buna dahildir. Bunlara ek olarak ekranın yenilenmesiyle ilgili grafik kesmeleri vardır.

## 5. Kesme Çeşitleri

Slayttaki sınıflandırma şöyledir (ekrandan, 00:30:00):

- Temel kesmeler
  - Donanım kesmeleri
  - Yazılım kesmeleri
- Interrupt Handler
- Dahili kesmeler
  - Logical interrupt
  - Sıfıra bölme
  - Adım adım çalıştırma
  - Vb.
- Harici kesmeler
  - Maskelenemez kesmeler (NMI)
  - Maskelenebilir kesmeler (INTR)
    - IF durumu önemli!

### 5.1 Donanım ve yazılım kesmeleri

Bilgisayarda işletim sistemi yüklü olmasa bile anakartla gelen bir yazılım vardır: BIOS. BIOS'un içindeki kesmeler temelde donanım kesmeleridir ve donanımı kontrol etmek için kullanılır. 8086 tarafında BIOS'un üzerine DOS işletim sistemi yüklenir (derste örnekler hep DOSBox'ta yapılmıştı); DOS'un sağladığı kesmelere yazılım kesmeleri denir.

Donanım kesmelerinin bir kısmı çok acil olabilir. Hoca RAM'in yuvasından çıktığı durumu örnek verdi: RAM yokken bilgisayar çalışamaz, hemen bir kesme üretilir ve işin devam ettirilemeyeceğine dair bir uyarı verilebilir. Klavyede bir tuşa basılması (bir editörde ya da metin kutusundaysak tuşun yazılıp görüntülenmesi gerekir) ve farenin oynatılması da donanım istekleridir.

### 5.2 Interrupt handler

Kesmelerin nereden geldiğini, nasıl davranacaklarını ve nereye gideceklerini kontrol eden yapıya interrupt handler denir.

### 5.3 Dahili kesmeler

Hoca önce trap flag'i hatırlattı: TF, programı adım adım çalıştırmak için kullanılıyordu. Derslerde programlar DEBUG ekranında `t` (trace) ile zaten adım adım ilerletilmişti. Ama ödevde olduğu gibi program komut satırından çalıştırılırsa, `g` (go) demiş gibi başlar, işini yapar ve sonlanır. Bu durumda adım adım çalıştırmak için TF ayarlanır ve bunun için bir kesme gerekir. Mantıksal işler için de ayrıca kesmeler gerekir.

Sıfıra bölme hatası da bir dahili kesmedir. Sıfıra bölme matematiksel olarak imkânsızdır, ama `DIV` komutunun yazılması sözdizimi açısından hiçbir aykırılık oluşturmaz. Kimse dikkatsizlikle `DIV 0` yazmaz; `DIV sayi` yazılır. Ama `sayi` değişkeni üstteki kodda yapılan çarpma, bölme, toplama ve çıkarma işlemleri sonucunda sıfıra düşmüş olabilir ve programcı farkında olmadan sıfıra bölmüş olur. Sözdizimi doğrudur, ama işlemcinin bu komutu gerçekleştirecek kapasitesi yoktur; bir kesme üretilir ve programın akışına son verilir.

### 5.4 Harici kesmeler

Harici kesmeler işlemcinin iki bacağı aracılığıyla alınır:

- NMI (non-maskable interrupt, maskelenemez kesme): herhangi bir şekilde engellenemez. RAM'in yerinden çıkması gibi durumlar bu türdendir; RAM olmadan bilgisayar zaten çalışmaz, maskelenecek bir şey kalmaz.
- INTR (maskelenebilir kesme): programcı IF'yi (interrupt flag) ayarlayarak yazdığı programın bu kesmelerle kesilmemesini sağlayabilir. Slayttaki "IF durumu önemli!" notu bunu anlatır. Bu kesmeler 8259A bütünleşik devresi üzerinden gelir.

IF sıfırlanmış bir program maskelenebilir kesmelerle kesilmeden devam edebilir; ama maskelenemez bir kesme geldiğinde işlem yine sekteye uğrar.

> **Ders sonrası not:** Hoca bu kısımda bir yerde "programınız maskelenemez kesmeler tarafından kesilmeden devam edebilir" ve "8259A üzerinden sürdürülebiliyor, maskelenemez kesmeler" dedi. Bağlama göre kastedilen maskelenebilir kesmelerdir: IF = 0 ile engellenen ve 8259A kesme denetleyicisi üzerinden gelen kesmeler maskelenebilir (INTR) kesmelerdir; NMI IF ile engellenemez.

## 6. Kesme Öncelikleri

Kesmelerin öncelikleri vardır. Hoca birden altıya kadar öncelik düşündürdü: program 3 numaralı öncelikteki bir kesmeyi çalıştırırken kendisinden daha yüksek öncelikli bir kesme gelirse o kesme çalıştırılır; daha düşük öncelikli kesmeler gelirse çalışan kesmenin kodunun tamamlanmasını bekler.

Hocanın sıraladığı öncelikler, en yüksekten en düşüğe:

- 1. Sıfıra bölme hatası. Komut sözdizimi açısından doğrudur ama işlemci gerçekleştiremez; güvensiz bir durum (unsafe state) oluşur. Program sonlandırılır; DOS tarafında bazı durumlarda işletim sisteminin yeniden başlatılması gerekebilir.
- 2. Yazılım olarak numarası verilerek çalıştırılan kesmeler (`INT #`). `#` yerine bir sayı gelir; örneğin ödevlerde kullanılan `INT 21h`, ekrandan okuma ve yazma işleri için kullanılan DOS kesmesidir ve alt fonksiyonları vardır.
- 3. Taşma (overflow) ile ilgili kesmeler.
- 4. Maskelenemez kesmeler (NMI); bellekte oluşan çok kritik hatalar gibi. Hoca bunun için "Interrupt 02" dedi.
- 5. 8259A entegresi üzerinden gelen kesmeler.
- 6. Trap flag ile programı adım adım çalıştırırken gelen kesmeler.

<!-- BELİRSİZ: Öncelik tablosunun slaytı karelerde yok; sıra altyazıdan kuruldu. Hoca NMI'yi önce "üçüncü öncelikte", hemen ardından "dördüncü öncelikle ... bellek üzerinde oluşan kritik hatalar, Interrupt 02" diye andı. -->

Öncelik mekanizması iş değişimini kolaylaştırır. Örneğin program sıfıra bölme ile yarıda kesilmişse, başka yeni bir kesme çağırıp programa ya da işletim sisteminin akışına doğrudan devam edilemez; çünkü daha yüksek öncelikli bir kesme gelmiştir ve önce o sorunun çözülmesi gerekir.

> **Ek bilgi (derste anlatılmadı):** 8086'da INT 2 vektörü NMI'ye ayrılmıştır; INT 0 sıfıra bölme, INT 1 tek adım (TF), INT 4 ise `INTO` komutuyla tetiklenen taşma kesmesidir. Ders kitaplarında 8086 öncelik sırası büyük olasılıkla "dahili kesmeler (bölme hatası, INT n, INTO) > NMI > INTR > tek adım" biçiminde verilir; hocanın sırası bununla uyumludur.

## 7. Kesme Oluştuğunda Yapılan İşlemler

Program bir kesme tarafından kesildiğinde ya da program bir kesme kullandığında otomatik olarak şunlar olur (ekrandan, 00:35:00):

- 1. Bayraklar yığında saklanır (`PUSHF`).
- 2. `TF = 0`.
- 3. `IF = 0` (`CLI`).
- 4. CS yazmacı yığına atılır (`PUSH CS`).
- 5. IP yazmacı yığına atılır (`PUSH IP`).
- 6. `INT` çalıştırılır (`# x 4` sonucunda vektör tablosundaki adrese erişilir.)
  - Alınan ilk word değeri IP yazmacına,
  - İkinci word değeri CS yazmacına yerleştirilir.

IF'nin 0 yapılması, bu sırada başka bir (maskelenebilir) kesme alınmaması demektir.

Hoca bunu FAR tipi yordam çağrısıyla karşılaştırdı. FAR tipi bir yordam çağrıldığında da kod kesimi ve o anki ofset değeri (IP) yığına atılıyordu. Kesmeye de sanki harici bir yordama dallanıyormuş gibi dallanılır; yalnız `CALL` yerine `INT` komutu kullanılır. Fark, bayrakların da ek olarak yığına atılmasıdır:

| Dallanma | Yığına atılan | Bayt |
|---|---|---|
| NEAR yordam (`CALL`) | IP | 2 |
| FAR yordam (`CALL FAR`) | CS, IP | 4 |
| Kesme (`INT`) | Bayraklar, CS, IP | 6 |

### 7.1 `INT n` ile vektör tablosuna erişim

`INT` komutundan sonra kesmenin numarası yazılır. Her kesmenin kod bloğu fiziksel bellekte bir yere kopyalanmış durumdadır. Oraya gitmek için iki şey bilinmelidir: kod kesimi (1 word) ve ofset adresi (1 word); toplam 2 word, yani 4 bayt. Her kesme için 4 baytlık bir adres yeri tutulduğundan bir sonraki kesmenin adresi 4 bayt sonradadır.

Hoca bunu elemanları double word (4 bayt) olan bir diziye benzetti: dizinin ilk elemanı 0. adreste, ikinci elemanı 4. adreste, üçüncü elemanı 8. adrestedir. Kesmenin adresine erişmek için kesme numarası 4 ile çarpılır.

Örnek: `INT 21h` kullanılıyor.

- 21h = 2 x 16 + 1 = 33 (onluk).
- 33 x 4 = 132.
- 132 ve 133. adreslerdeki word IP'ye konur.
- 134 ve 135. adreslerdeki ikinci word CS'ye konur.
- Programın akışı kesmenin kodunun bulunduğu yerden devam eder.

Python ile kontrol edildi: 21h x 4 = 132 = 84h; IP 84h-85h, CS 86h-87h adreslerinden alınır.

## 8. Kesmeden Dönüş ve Yığın Kullanımı

Kesme kodunu programcı kendisi yazacaksa yazmaçlara çok dikkat etmelidir. Harici bir yordam yazılırken yordama girildiği anda kullanılan yazmaçlar `PUSH` ile yığına konur ve dönmeden önce `POP` ile geri alınırdı. Kesme yordamında da aynı şekilde başta kullanılan yazmaçlar yığına atılır, sonda geri çekilir.

Kesmeden `IRET` (interrupt return) komutuyla dönülür:

- FAR tipi yordamdan `RETF` (return far) ile dönülür; yığından otomatik olarak 4 bayt çekilir.
- NEAR tipi yordamdan `RET` ile dönülür; yığından 2 bayt çekilir.
- Kesmeden `IRET` ile dönülür; kesmeye giderken otomatik olarak yığına atılan 3 word (6 bayt) yığından çekilir.

### 8.1 Kesmeye yığın üzerinden parametre aktarma

Daha önce yordamlara yığın üzerinden parametre aktarma örnekleri yapılmıştı; aynısı kesmeler için de yapılabilir. Hoca şu örneği verdi: her biri word olan 5 parametre gönderilmiş, yığında toplam 10 baytlık değer var. Hocaya göre `IRET`'in yanına 10 yazıldığında (`IRET 10`) otomatik çekilen 6 bayt ile birlikte 10 bayt da temizlenir; toplam 16 bayt yığından temizlenir ve SP 16 artar.

> **Ders sonrası not:** Hoca `IRET 10` biçimini kullandı; 8086'da `IRET` komutu işlenen almaz. `RET n` ve `RETF n` biçimleri vardır, `IRET n` biçimi yoktur. Kesmeye yığından gönderilen parametreler `IRET`'ten sonra çağıran tarafta `ADD SP, 10` ya da gerekli sayıda `POP` ile temizlenir. Hocanın asıl söylemek istediği (parametrelerin yığından temizlenmesinin programcının sorumluluğunda olduğu ve 6 + 10 = 16 baytın çekilmesi gerektiği) doğrudur.

Bu senaryonun yığın üzerindeki etkisi python ile adım adım izlendi (başlangıç SP = FFFEh varsayıldı, ara adım eklendi):

| Adım | SP |
|---|---|
| Başlangıç | FFFEh |
| 5 word parametre `PUSH` edildi (10 bayt) | FFF4h |
| `INT`: bayraklar, CS, IP yığına atıldı (6 bayt) | FFEEh |
| `IRET`: IP, CS, bayraklar çekildi (6 bayt) | FFF4h |
| `ADD SP, 10` | FFFEh |

> **Hocanın vurgusu:** Yığına bir şey konduğunda yığın göstericisinin (SP) değeri azalır, yığından bir şey çekildiğinde artar. "Bunu lütfen unutmayın."

## 9. Vektör Tablosunun Görevi ve Konumu

Slayttaki tanım (ekrandan, 00:40:00): "Kesme servis programları gerek BIOS gerekse İşletim Sistemi tarafından sağlanan değişik uzunluktaki kod parçalarıdır."

Her kesme programının kodunun boyu aynı değildir: biri fareyi hareket ettirir ve 30 satırdır, diğeri ekranı yeniler ve 150 satırdır, bir başkası daha karmaşık bir iş yapar ve 1000 satırdır. Bu önemli değildir; her birinin adresi 4 bayttır. Bu kod parçaları bilgisayar açıldığında belleğe, her biri farklı fiziksel alanlara yerleştirilir. Onlara erişmek için vektör tablosu kullanılır. Vektör tablosunda yalnız kesmelerin başlangıç adresleri vardır.

Bu adresler belleğin 00000h fiziksel adresinden 003FFh fiziksel adresine kadar olan 1024 baytlık alana yerleştirilir. Her kesme 4 bayt yer kapladığına göre:

$$\frac{1024}{4} = 256 \text{ kesme}$$

Her kesmenin alt fonksiyonları, her alt fonksiyonun da alt fonksiyonları olabilir; hoca bunların ayrıntısının ders kitabında görülebileceğini söyledi.

Programcı kendi kesmesini yazmak istiyorsa, yazacağı kesmeleri kullanıcıya ayrılmış olan 60h ile 67h arasına yerleştirmelidir; toplam 8 farklı kesme yazılabilir. Ayrıca var olan bir kesme tam istenen işi yapmıyorsa, ona ek bir iş yaptırılmak isteniyorsa ya da (bir virüs gibi) bozulmak isteniyorsa var olan kesmelerin kodları da değiştirilebilir.

## 10. Vektör Tablosunda Değişiklik

Slayttaki maddeler (ekrandan, 00:45:00):

- Programcı kendi kesmesini yazabilir.
- Var olan bir kesmeden hemen önce devreye girebilecek bir kesme yazabilir.
- Her iki durumda da yazılan kesme vektör tablosuna yerleştirilmelidir.
- Bunun için yapılması gereken işlemler;
  - 1. Kesmenin TSR ile belleğe yerleştirilmiş olması gerekir. (TSR -> Terminate and Stay Resident)

<!-- BELİRSİZ: Slaytın sonraki maddeleri karelerde görünmüyor; aşağıdaki adımlar altyazıdan kuruldu. -->

### 10.1 Var olan bir kesmenin önüne ya da sonuna kod eklemek

Hoca 37 numaralı bir kesme düşündürdü. Bu kesmenin vektör tablosunda kod kesimi ve ofsetten oluşan bir adresi vardır; oraya gidildiğinde 37 numaralı kesmenin kod bloğu başlar. Programcı bu kesme her çağrıldığında kendi kodunun da çalışmasını istiyorsa kod bloğunu kesmenin önüne ya da sonuna (`IRET`'ten hemen önce) yerleştirebilir.

Başka bir yol da şudur: yeni yazılan kesmenin hangi kod kesiminde ve hangi ofsette olduğu bellidir. 37 numaralı kesmeye girildiği anda far tipi bir `JMP` ile o kod kesimine ve ofsete atlanır, oradaki işlemler yapılır ve sonra başlanan noktaya geri dönülür.

### 10.2 TSR ile kalıcılık

Yazılan kesme yalnız RAM'deki bir program parçasıysa bilgisayar kapatılıp açıldığında kaybolur. RAM uçucudur (volatile): elektrik varken veri tutar, elektrik gidince sıfırlanır; yeniden açılışta BIOS ile birlikte içine yeniden bir şeyler yazılmaya başlanır. Kesmenin kalıcı olması için TSR (Terminate and Stay Resident) ile belleğe yerleştirilmesi gerekir.

### 10.3 Adresin vektör tablosuna yazılması

Yazılan kodun adresi (ofset ve kesim) vektör tablosunda ilgili yere yazılır. Hoca, kesme 60h ile 67h arasına yazılmışsa, örneğin 63h kullanılmışsa, adresin 63h x 4 hesabıyla bulunacağını söyledi ve sonucu 252 olarak verdi: IP 252 ve 253. baytlara, CS 254 ve 255. baytlara yazılır.

> **Ders sonrası not:** Hoca 63h x 4 = 252 dedi; bu, 63'ün onluk alınmasıyla bulunur. 63h = 6 x 16 + 3 = 99, 99 x 4 = 396 = 18Ch. Doğru adresler IP için 396-397 (18Ch-18Dh), CS için 398-399 (18Eh-18Fh) baytlarıdır (python ile kontrol edildi). Kullanıcı kesmeleri bölgesi 60h x 4 = 384 (180h) ile 67h x 4 + 3 = 415 (19Fh) arasındadır.

Bu yazma işlemi sırasında kesmeler kapatılmalıdır (disable). Sebebi şudur: vektör tablosuna 4 baytlık bir değer (CS ve IP) yazılırken IP yazılmış ama CS henüz yazılmamışken bir kesme gelirse ve o kesme bu yarım yazılmış adresi kullanırsa beklenmedik durumlar oluşur.

### 10.4 Var olan bir kesmenin adresini değiştirmek

Hoca, fareyi hareket ettiren kesmenin 12h numaralı kesme olduğunu varsaydı. Vektör tablosunda bunun adresi:

- 12h = 1 x 16 + 2 = 18 (onluk).
- 18 x 4 = 72.
- Adres 72, 73, 74 ve 75. baytlardadır.

Bu 4 baytlık alandaki adres kaldırılıp yerine programcının kendi kesme bloğunun adresi konabilir. Böylece yalnız 60h-67h arasındaki kullanıcı alanı değil, boşta olan ya da gerekmeyen kesmeler de bu şekilde değiştirilebilir. Python ile kontrol edildi: 12h x 4 = 72 = 48h, alan 48h-4Bh.

> **Ders sonrası not:** Hocanın 12h'yi fare kesmesi olarak alması büyük olasılıkla yalnız bir varsayımdır. Standart PC'de INT 12h BIOS'un bellek boyunu bildiren kesmesidir; fare sürücüsü genellikle INT 33h'yi kullanır.

Ancak üzerine yazılan orijinal adres bilinmezse, bozulan şeyi sonradan yerine koymak mümkün olmaz. Bu yüzden eski adres bir yerde (bellekte, bir yazmaçta ya da yığında) saklanmalıdır. Kesme artık çalışmasın istendiğinde vektör tablosuna gidip orijinal adres geri yazılabilmelidir.

### 10.5 Vektör tablosuna yazan DOS fonksiyonu

Hoca vektör tablosuna verilerin, 21h numaralı kesmenin bir fonksiyonu kullanılarak yazıldığını söyledi. Bu fonksiyon vektör tablosunun nerede olduğunu (fiziksel olarak 00000h'den başladığını) bilerek adresi gidip yazar.

<!-- BELİRSİZ: Altyazıda fonksiyon numarası "15" geçiyor; kare yok. -->

> **Ders sonrası not:** DOS'ta kesme vektörünü yazan fonksiyon büyük olasılıkla `INT 21h`, `AH = 25h` (set interrupt vector; AL kesme numarası, DS:DX yeni adres) fonksiyonudur. Eski adresi okumak için `AH = 35h`, programı bellekte kalıcı bırakarak sonlandırmak (TSR) için `AH = 31h` kullanılır.

Yazma işlemi bittikten sonra kesmelere yeniden izin verilir. Kendi kesmemiz yazılmışsa `IRET` ile dönülmelidir (6 bayt çekilir). Orijinal kesmenin önünde çalışan bir kod yazılmışsa, iş bitince `JMP` ile orijinal kesmenin koduna atlanır. Kullanım tamamlandıktan sonra, adresler değiştirilmişse, orijinal adreslerin vektör tablosuna geri yazılması gerekir.

## 11. Kesme Servis Programı Yazarken Dikkat Edilecekler

Slayttaki ilk madde (ekrandan, 00:50:00): "Kesme kodu içerisinde girildiğinde kesmelere izin verilmelidir."

<!-- BELİRSİZ: Slaytın sonraki maddeleri karelerde görünmüyor; aşağıdaki maddeler altyazıdan kuruldu. -->

### 11.1 Kesmelere izin vermek

Yazılan kesme de genellikle başka kesmeler tarafından bölünebilmelidir. Her program "ben bölünmek istemiyorum" derse kesme mekanizmasının bir anlamı kalmaz. Vektör tablosu güncellenirken kesmelerin kapatılması ayrı ve önemli bir durumdur, çünkü kesmeler o tabloya bakarak çalışır. Ama yazılan bir kesme kodu da kesme alabilmelidir. Hoca klavyeden basılan tuşu algılayıp ekrana gönderen bir kesme örneğini verdi: bu kesme de kesme almalıdır, yoksa sürekli busy waiting yapmış olur. Bu genel bir kullanım yaklaşımıdır; her durumda zorunlu değildir.

### 11.2 Yazmaçları saklamak

Kesmeye harici bir yordama dallanır gibi dallanılır. Bir yordam olduğu için içeride kullanılan bütün yazmaçları saklamak programcının sorumluluğundadır.

### 11.3 Yığın payı

Program çalışırken otomatik olarak bir kesmeye uğrayabilir ve bu durumda yığında 6 baytlık yer işgal edilir. Programcı yığını tasarlarken "en yoğun durumda bile 4 baytlık boşluk var" diye hesaplamış olabilir; ama program stack overflow verir ve sebebi bulunamaz. Sebep, araya giren bir kesmenin 6 baytı ile yığının taşması olabilir.

### 11.4 Yazmaçlara değer yüklemek

Kesme programı birden fazla kez kullanılacaksa gerekli değerler kesmeye gitmeden önce ilgili yazmaçlara yüklenmelidir. Kesmelerin alt fonksiyonları vardır ve bunlarla farklı işler yapılır; örneğin 21h'nin alt fonksiyonları farklı okuma ve yazma işlerine karşılık gelir. Kesme tekrar tekrar kullanılacaksa her seferinde ilgili yazmaçlara doğru değerler yazılmalıdır.

### 11.5 BIOS kesmesi içinde DOS kesmesi kullanılamaz

Kesme bir donanım kesmesinin yerine geçebilir. 00000h-003FFh arasındaki tablodaki kesmelerin bir kısmı donanım (BIOS) kesmesi, bir kısmı yazılım (DOS) kesmesidir. Bir kesmenin içinde başka bir kesme kullanılabilir; ama BIOS kesmesi yazılıyorsa DOS kesmeleri kullanılamaz. BIOS çalışırken henüz DOS (işletim sistemi) yoktur; işletim sistemini BIOS başlatır.

> **Ders sonrası not:** Hoca burada tabloyu "1024 tane kesme" diye andı; tablo 1024 bayttır, kesme sayısı 256'dır.

### 11.6 TSR ve yığın temizliği

Kesmenin TSR ile belleğe yerleştirilmesi gerekir. Kesmeye girmeden önce kesmenin içinde kullanılmak üzere yığına veriler konduysa, kesmeden dönerken bu verilerin yığından temizlenmesi programcının sorumluluğundadır (bkz. bölüm 8.1).

## 12. Kesmeleri Kullanırken

Slayt (ekrandan, 00:55:00):

- 00H-1FH arasında BIOS kesmeleri,
- 20H-2FH arasında DOS kesmeleri bulunur.
- Kesmeler çağırılırken,
  - Fonksiyon numarası AH'a,
  - Eğer varsa alt fonksiyon numarası AL'ye aktarılır.
  - INT komutu kullanılır.
- Örnek;
  - `MOV AH, 1H`
  - `INT 21H`

Kesme çağrılırken fonksiyon numarası AH'ye, varsa alt fonksiyon numarası AL'ye konur; ardından `INT` komutuyla kesmenin numarası yazılır ve kesme otomatik olarak çalıştırılır. AH ve AL'nin kullanılması zorunludur; değer başka bir yazmaca konursa olmaz. Hoca bunu `MUL` komutuna benzetti: `MUL` verilen işlenenle AX'i otomatik olarak çarpıp sonucu DX:AX'e yazar; `INT` de fonksiyonu AH'den, alt fonksiyonu AL'den otomatik olarak alır. Örnekte 21h kesmesinin 1h fonksiyonu kullanılmak istendiğinde önce AH'ye 1 konur, sonra `INT 21H` çağrılır.

> **Hocanın vurgusu:** Fonksiyon numarası AH'ye, alt fonksiyon numarası AL'ye konmalıdır; başka yazmaçları kullanmak söz konusu değildir. "Bu önemli, buna dikkat edilmesi lazım."

> **Ek bilgi (derste anlatılmadı):** DOS'ta `INT 21h`, `AH = 01h` büyük olasılıkla "klavyeden yankılı karakter oku" fonksiyonudur; okunan karakterin ASCII kodu AL'ye döner.

## Örnek Sorular

**1.** (derste sözlü, 00:36:51) `INT 21h` kullanılıyor. 21h onluk tabanda kaçtır ve kesmenin adresi vektör tablosunun hangi baytlarından alınır?

> **Çözüm (derste verildi):** 21h = 2 x 16 + 1 = 33. 33 x 4 = 132. 132 ve 133. baytlardaki word IP'ye, 134 ve 135. baytlardaki word CS'ye konur (132 = 84h; python ile kontrol edildi).

**2.** (derste sözlü, 00:45:13) Kullanıcı kesmesi olarak 63h numarası kullanılırsa kesmenin adresi vektör tablosunda nereye yazılır?

> **Çözüm (derste verildi, düzeltildi):** Hoca 252-253 (IP) ve 254-255 (CS) dedi. Doğrusu: 63h = 99, 99 x 4 = 396 = 18Ch; IP 396-397 (18Ch-18Dh), CS 398-399 (18Eh-18Fh) baytlarına yazılır (python ile kontrol edildi).

**3.** (derste sözlü, 00:46:46) 12h numaralı kesmenin adresi vektör tablosunda hangi baytlardadır?

> **Çözüm (derste verildi):** 12h = 18, 18 x 4 = 72; adres 72, 73, 74 ve 75. baytlardadır (48h-4Bh; python ile kontrol edildi).

**4.** (derste sözlü, 00:38:57) Bir kesmeye yığın üzerinden her biri word olan 5 parametre gönderildi. Kesmeden dönüldüğünde yığından toplam kaç bayt temizlenmelidir?

> **Çözüm (derste verildi):** Kesmenin otomatik attığı 6 bayt (bayraklar, CS, IP) ve 5 x 2 = 10 bayt parametre; toplam 16 bayt, SP 16 artar. Hoca bunun `IRET 10` ile yapılacağını söyledi; 8086'da `IRET` işlenen almadığından 6 bayt `IRET` ile, 10 bayt çağıran tarafta `ADD SP, 10` ile temizlenir (bkz. bölüm 8.1).

## Dersin Toparlaması

Bu derste kesme mekanizması işlendi. Tek bir işlemcinin aynı anda tek iş yapabildiği, ama yavaş birimlerle sırayla ilgilenerek eş zamanlı çalışma görüntüsü sağladığı anlatıldı. Busy waiting, polling ve interrupt yöntemleri misafir benzetmesiyle karşılaştırıldı. Kesmeler temel (donanım/BIOS ve yazılım/DOS), dahili (sıfıra bölme, adım adım çalıştırma) ve harici (NMI ve IF ile engellenebilen INTR) diye sınıflandırıldı ve öncelik sırası verildi. Bir kesme oluştuğunda bayrakların, CS'nin ve IP'nin yığına atıldığı (6 bayt), TF ve IF'nin sıfırlandığı, kesme numarası 4 ile çarpılarak vektör tablosundan yeni IP ve CS'nin alındığı ve `IRET` ile dönüldüğü görüldü.

Vektör tablosunun 00000h-003FFh arasında 1024 bayt olduğu ve 256 kesmenin adresini tuttuğu, kullanıcı kesmeleri için 60h-67h aralığının ayrıldığı, kendi kesmesini yazan programcının TSR ile kodu belleğe yerleştirip adresini kesmeler kapalıyken vektör tablosuna yazması ve eski adresi saklaması gerektiği anlatıldı. Kesme yazarken yazmaçların saklanması, yığın payının hesaba katılması, BIOS kesmesi içinde DOS kesmesi kullanılmaması ve fonksiyon numarasının AH'ye, alt fonksiyonun AL'ye konması vurgulandı. Bir sonraki derste assembly dilinin yüksek seviyeli dillerle birlikte kullanımına geçilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
