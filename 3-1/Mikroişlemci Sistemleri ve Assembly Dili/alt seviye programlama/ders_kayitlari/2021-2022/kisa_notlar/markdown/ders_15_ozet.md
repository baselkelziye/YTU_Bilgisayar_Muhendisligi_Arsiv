# Ders 15 Çalışma Özeti

## Genel Konular

- Kesme (interrupt) nedir? (ekrandan, 00:15:00)
  - Slayttaki tanım: "Çeşitli kriterler ve önceliklerle program işleyişlerinin kesintiye uğratılarak eş zamanlı çalışmanın sağlanması interrupt mekanizması ile sağlanır."
  - Tek bir işlemci (çekirdek) bir anda yalnız bir iş yapabilir. Yalnız işletim sistemi için bile arka planda yüzlerce alt program (saat güncelleme, ekran yenileme, ağ trafiği, disk işlemleri vb.) çalışır. Kullanıcının aynı anda müzik dinleyip oyun oynayıp mesajlaşabilmesi kesme mekanizmasıyla sağlanır.
  - İşlemci; RAM, disk (HDD, SSD) gibi elektronik birimlerden ve fare, klavye, yazıcı, monitör gibi çevre birimlerinden çok daha hızlıdır. Bu yüzden yavaş birimlerle sırayla ilgilenir: "sen dur, ben çalışayım" mantığıyla her birine kısa süre ayırır.
  - İşlemci %100 yükteyken fareden gelen sinyali işleyecek programa sıra gelmez; donma bu yüzden olur.
- İşlemci ile yavaş birimler arasındaki ilişki (ekrandan, 00:20:00, 00:25:00)
  - Busy waiting: işlemci, bir birimden istek gelip gelmeyeceğini başka hiçbir iş yapmadan boşta bekler. Benzetme: misafir gelecek diye kapıda beklemek.
  - Polling: işlemci belirli aralıklarla (örneğin "her 5 dakikada bir") birimi kontrol eder; aradaki sürede başka işlerle uğraşabilir. Dezavantajı: istek kontrolden hemen sonra gelirse bir sonraki kontrole kadar bekler.
  - Interrupt: birim, hizmet gerektiğinde işlemciyi kendisi böler. Benzetme: kapıya zil koymak; zil çalınca kitaba ayraç konur, misafir alınır, sonra kitaba kaldığı yerden devam edilir.
  - Kesmede kritik nokta: kesilen programın nerede durdurulduğu (ayraç) bir yerde saklanmalıdır ki program kaldığı yerden sürdürülebilsin.
- Zaman ve grafik kesmeleri
  - Zamana ya da frekansa bağlı çalışan her iş (saat güncelleme, belirli aralıklarla yapılan kontroller, güncellemeler, ekran yenileme) zaman kesmeleriyle; ekranın yenilenmesiyle ilgili işler grafik kesmeleriyle ilişkilidir.
- Kesme çeşitleri (ekrandan, 00:30:00)
  - Temel kesmeler: donanım kesmeleri ve yazılım kesmeleri.
    - Donanım kesmeleri: işletim sistemi olmadan da anakartla gelen BIOS yazılımının içindeki kesmeler; donanımı kontrol eder.
    - Yazılım kesmeleri: 8086 tarafında BIOS'un üzerine yüklenen DOS'un sağladığı kesmeler.
  - Interrupt handler: kesmelerin nereden geldiğini, nasıl davranacağını ve nereye gideceğini yönetir.
  - Dahili kesmeler: logical interrupt, sıfıra bölme, adım adım çalıştırma (trap flag) vb.
  - Harici kesmeler: işlemcinin iki bacağından gelir.
    - Maskelenemez kesmeler (NMI): engellenemez; örneğin RAM yuvasından çıkması gibi kritik donanım hataları.
    - Maskelenebilir kesmeler (INTR): IF (interrupt flag) ile engellenebilir; slayttaki not: "IF durumu önemli!". 8259A kesme denetleyicisi üzerinden gelir.
- Kesme öncelikleri
  - Bir kesme çalışırken daha yüksek öncelikli bir kesme gelirse o çalıştırılır; daha düşük öncelikli kesme, çalışan kesmenin bitmesini bekler.
  - Hocanın sıraladığı öncelikler (en yüksekten): sıfıra bölme hatası; `INT #` ile numarası verilerek çağrılan yazılım kesmeleri; taşma (overflow) kesmesi; NMI (bellekteki kritik hatalar, INT 02); 8259A üzerinden gelen kesmeler; trap flag ile adım adım çalıştırma.
  <!-- BELİRSİZ: Öncelik tablosunun slaytı karelerde yok; sıra altyazıdan kuruldu. Hoca NMI için hem "üçüncü" hem "dördüncü öncelik" dedi. -->
- Kesme oluştuğunda yapılan işlemler (ekrandan, 00:35:00)
  - 1. Bayraklar yığında saklanır (`PUSHF`).
  - 2. `TF = 0`.
  - 3. `IF = 0` (`CLI`).
  - 4. CS yazmacı yığına atılır (`PUSH CS`).
  - 5. IP yazmacı yığına atılır (`PUSH IP`).
  - 6. `INT` çalıştırılır: `# x 4` sonucunda vektör tablosundaki adrese erişilir; alınan ilk word IP'ye, ikinci word CS'ye yerleştirilir.
- Yığına atılan bayt sayısı ve dönüş komutları
  - NEAR yordam çağrısı: yalnız IP (2 bayt); `RET` 2 bayt çeker.
  - FAR yordam çağrısı: CS ve IP (4 bayt); `RETF` 4 bayt çeker.
  - Kesme: bayraklar, CS ve IP (3 word = 6 bayt); kesmeden `IRET` (interrupt return) ile dönülür, 6 bayt çekilir.
  - Kesme yordamında kullanılan yazmaçlar başta `PUSH`, sonda `POP` ile saklanıp geri yüklenmelidir.
- Vektör tablosunun görevi ve konumu (ekrandan, 00:40:00)
  - Kesme servis programları BIOS ya da işletim sistemi tarafından sağlanan, değişik uzunlukta kod parçalarıdır; bilgisayar açılınca belleğin farklı yerlerine yerleştirilirler.
  - Vektör tablosunda yalnız bu programların başlangıç adresleri (CS:IP, her biri 4 bayt) tutulur.
  - Tablo, belleğin 00000h ile 003FFh fiziksel adresleri arasındaki 1024 baytlık alandadır: 1024 / 4 = 256 kesme.
  - Kesmelerin alt fonksiyonları, onların da alt fonksiyonları olabilir; ayrıntısı ders kitabındadır.
  - Kullanıcının yazacağı kesmeler için 60h-67h arası ayrılmıştır (8 kesme).
- Vektör tablosunda değişiklik (ekrandan, 00:45:00)
  - Programcı kendi kesmesini yazabilir ya da var olan bir kesmeden hemen önce devreye girecek bir kesme yazabilir; her iki durumda yazılan kesme vektör tablosuna yerleştirilmelidir.
  - Var olan bir kesmenin başına `JMP` ile kendi koduna (far) atlayıp sonra geri dönmek ya da kesmenin sonuna (`IRET`'ten hemen önce) kod eklemek mümkündür.
  - Adımlar: kesme TSR (Terminate and Stay Resident) ile belleğe yerleştirilir; kodun adresi (ofset ve kesim) vektör tablosunda ilgili yere yazılır; yazma sırasında kesmeler kapatılır (disable), yazma bitince yeniden açılır.
  - Var olan bir kesmenin adresinin üzerine yazılacaksa eski adres bir yerde (bellekte, yazmaçta ya da yığında) saklanmalıdır ki sonradan geri konabilsin.
- Kesme servis programı yazarken dikkat edilecekler (ekrandan, 00:50:00)
  - Kesme kodunun içine girildiğinde kesmelere izin verilmelidir (vektör tablosu güncellenirken kapatılması ayrı bir durumdur).
  - Kullanılan bütün yazmaçlar saklanmalıdır.
  - Her kesme yığında 6 bayt yer kaplar; yığın boyu tasarlanırken bu pay hesaba katılmalıdır.
  - Kesme birden fazla kez kullanılacaksa gerekli değerler her çağrıdan önce ilgili yazmaçlara yeniden yüklenmelidir.
  - BIOS kesmesi yazılıyorsa içinde DOS kesmeleri kullanılamaz (BIOS çalışırken DOS henüz yoktur).
  - Kesmeye yığın üzerinden parametre gönderildiyse dönüşte bu parametreler yığından temizlenmelidir.
- Kesmeleri kullanırken (ekrandan, 00:55:00)
  - 00h-1Fh arasında BIOS kesmeleri, 20h-2Fh arasında DOS kesmeleri bulunur.
  - Fonksiyon numarası AH'ye, varsa alt fonksiyon numarası AL'ye konur; ardından `INT` komutu kullanılır. Başka bir yazmaç kullanılamaz.
  - Örnek: `MOV AH, 1H` / `INT 21H`.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kesilen programın kaldığı yer saklanmalıdır
  - "Kitabın arasına ayraç koymak" benzetmesi: CS, IP ve bayraklar yığına atılır ki program kaldığı yerden devam edebilsin.
- Yığına bir şey konunca SP azalır, yığından bir şey çekilince SP artar
  - Hoca bunu "lütfen unutmayın" diyerek vurguladı.
- Kesmenin adresi her zaman 4 bayttır
  - Kesme kodunun uzunluğu (30, 150 ya da 1000 satır) önemli değildir; vektör tablosundaki adresi 4 bayttır. Bu yüzden kesme numarası 4 ile çarpılarak tablodaki yeri bulunur.
- Vektör tablosu güncellenirken kesmeler kapatılmalıdır
  - IP yazılıp CS yazılmadan bir kesme gelirse yarım yazılmış adresle yanlış yere gidilebilir.
- Kesme yığından 6 bayt kullanır
  - "En yoğun durumda bile 4 bayt boşluk var" diye hesaplanan bir yığın, araya giren bir kesmenin 6 baytı yüzünden taşabilir (stack overflow).
- AH ve AL önemlidir
  - `MUL`'un sonucu otomatik olarak DX:AX'e yazdığı gibi, `INT` de fonksiyon numarasını AH'den, alt fonksiyonu AL'den okur.

## Kısa Tekrar Notları

- Tek işlemci aynı anda tek iş yapar; eş zamanlılık kesmelerle sağlanır.
- Busy waiting: boşta bekle. Polling: aralıklarla kontrol et. Interrupt: birim işlemciyi kendisi böler.
- Temel kesmeler: donanım (BIOS) ve yazılım (DOS). Dahili kesmeler: sıfıra bölme, adım adım çalıştırma, logical interrupt. Harici kesmeler: NMI (maskelenemez) ve INTR (maskelenebilir, IF'ye bağlı).
- En yüksek öncelikli kesme sıfıra bölme hatasıdır; trap flag ile adım adım çalıştırma en düşüktür.
- Kesme oluşunca: `PUSHF`, `TF = 0`, `IF = 0`, `PUSH CS`, `PUSH IP`, sonra vektör tablosundan yeni IP ve CS.
- NEAR çağrı 2, FAR çağrı 4, kesme 6 bayt yığın kullanır. Dönüşler: `RET`, `RETF`, `IRET`.
- Vektör tablosu: 00000h-003FFh, 1024 bayt, 256 kesme, kesme başına 4 bayt (önce IP, sonra CS).
- `INT 21h`: 21h = 33, 33 x 4 = 132; IP 132-133. adreslerden, CS 134-135. adreslerden alınır.
- Kullanıcı kesmeleri 60h-67h (8 adet). TSR ile belleğe yerleştirilir.
- BIOS kesmeleri 00h-1Fh, DOS kesmeleri 20h-2Fh. Fonksiyon AH'de, alt fonksiyon AL'de.
- BIOS kesmesi içinde DOS kesmesi kullanılamaz.

## Detaylı Açıklamalar

- Neden kesme gerekir?
  - İşlemci, bilgisayardaki diğer birimlerden çok daha hızlıdır. Hoca RAM'in hız artışının işlemcilerden daha hızlı olduğunu, ancak işlemcilerin çekirdek sayısının da arttığını, bu yüzden işlemcinin hâlâ en hızlı birim olduğunu söyledi. Çevre birimleri ise çok daha yavaştır: bir saniyede klavyeye ancak birkaç kez basılır, monitörler saniyede 50, 120, 200 kez yenilenir; işlemci ise saniyede milyarlarca işlem yapabilir. Bu yüzden işlemci, ekranı yeniler, müziğin hoparlöre gidecek verisini hazırlar, oyundaki aksiyonları işler, internet işini yapar ve bunları kullanıcının fark edemeyeceği bir hızla sırayla tekrarlar. Zoom görüntüsü, PowerPoint, mikrofon ve kamera sürücüleri de ayrı programlardır ve her biri kesmelerle sırayla çalışır.
- Busy waiting, polling ve interrupt karşılaştırması
  - Busy waiting'de işlemci bir işe adanmış gibi boşta bekler; hoca, bir aydır hiç kullanılmayan ama sürekli hazır bekleyen bir yazıcıya atanmış işlemci örneğini verdi. Polling'de işlemci belirli aralıklarla kontrol eder ve arada başka işler yapar; ancak istek kontrolden hemen sonra gelirse neredeyse bir aralık boyunca bekler (5 dakikalık aralıkta 4 dakika 59 saniyeye kadar). Interrupt'ta birim hizmete ihtiyaç duyduğunda zili çalar, işlemci yaptığı işin yerini işaretler, kesmeyle ilgilenir ve sonra kaldığı yerden devam eder. Hoca busy waiting'in günümüzde de kullanıldığını belirtti.
- Sıfıra bölme kesmesi
  - `DIV 0` gibi bir şeyi kimse bilerek yazmaz; ama `DIV sayi` komutundaki `sayi` değişkeni önceki işlemler sonucunda sıfır olabilir. Komut sözdizimi açısından doğrudur, fakat işlemci bu işlemi gerçekleştiremez; bir kesme üretilir ve programın akışı sonlandırılır. Hoca bunu güvensiz durum (unsafe state) olarak adlandırdı; DOS'ta bazı durumlarda işletim sisteminin yeniden başlatılması gerekebilir.
- Trap flag ile adım adım çalıştırma
  - DEBUG'da `t` (trace) komutu programı zaten adım adım çalıştırır. Komut satırından çalışan bir programı adım adım çalıştırmak için TF ayarlanır; bunun için de bir kesme gerekir.
- `INT` komutunun vektör tablosunu kullanması
  - Her kesmenin kodu bellekte bir yerdedir; oraya gitmek için kod kesimi (1 word) ve ofset (1 word), toplam 4 bayt bilinmelidir. Vektör tablosu, elemanları 4 bayt olan (double word) bir dizi gibidir: 0. eleman 0. adreste, 1. eleman 4. adreste, 2. eleman 8. adrestedir. Bu yüzden kesme numarası 4 ile çarpılır. Örnek: `INT 21h` için 21h = 2 x 16 + 1 = 33, 33 x 4 = 132. 132 ve 133. adreslerdeki word IP'ye, 134 ve 135. adreslerdeki word CS'ye konur ve program kesmenin kodundan devam eder (python ile kontrol edildi: 132 = 84h).
- Kesmeye yığından parametre aktarma
  - Yordamlarda olduğu gibi kesmeye de yığın üzerinden parametre gönderilebilir. Hoca, 5 word parametre (10 bayt) gönderildiğinde `IRET 10` yazılarak otomatik 6 bayt ile birlikte 10 baytın da temizleneceğini, toplam 16 bayt çekileceğini söyledi.
  - **Ders sonrası not:** 8086'da `IRET` komutu işlenen almaz; `RET n` ve `RETF n` biçimleri vardır ama `IRET n` biçimi yoktur. Kesmeye yığından gönderilen parametreler `IRET`'ten sonra çağıran tarafta `ADD SP, 10` ya da `POP` komutlarıyla temizlenir. Python ile yapılan yığın benzetiminde SP = FFFEh iken 5 parametre sonrası FFF4h, `INT` sonrası FFEEh, `IRET` sonrası FFF4h, `ADD SP, 10` sonrası yeniden FFFEh oldu.
- Vektör tablosunda adres hesabı örnekleri
  - Kullanıcı kesmesi 63h için hoca 63 x 4 = 252 hesabını yaptı ve IP'nin 252-253, CS'nin 254-255. adreslere yazılacağını söyledi.
  - **Ders sonrası not:** 63h onaltılıktır; 63h = 99, 99 x 4 = 396 (18Ch). Doğru adresler IP için 396-397 (18Ch-18Dh), CS için 398-399 (18Eh-18Fh) olur. Hocanın 252'si 63'ün onluk alınmasıyla bulunur (python ile kontrol edildi).
  - 12h numaralı kesme için 12h = 18, 18 x 4 = 72; adres 72, 73, 74 ve 75. baytlardadır (48h-4Bh). Bu hesap doğrudur.
  - **Ders sonrası not:** Hoca 12h kesmesini fareyi hareket ettiren kesme diye örnekledi. Büyük olasılıkla bu yalnız bir varsayımdır; standart PC'de INT 12h BIOS'un bellek boyunu bildiren kesmesidir, fare sürücüsü genellikle INT 33h'yi kullanır.
- Vektör tablosuna yazma ve TSR
  - Kendi yazdığımız kesme yalnız RAM'deki bir program parçasıysa bilgisayar kapanınca kaybolur. Kesmenin kalıcı olması için TSR (Terminate and Stay Resident) ile belleğe yerleştirilir. Ardından kodun adresi vektör tablosundaki ilgili yere yazılır. Hoca bu yazmanın 21h kesmesinin bir fonksiyonuyla yapıldığını söyledi; bu fonksiyon tablonun yerini bilerek adresi yazar.
  <!-- BELİRSİZ: Hoca fonksiyon numarasını "15" diye söyledi (altyazı). -->
  - **Ders sonrası not:** DOS'ta vektör tablosuna adres yazan fonksiyon büyük olasılıkla `INT 21h`, `AH = 25h` (set interrupt vector) fonksiyonudur; eski adresi okumak için `AH = 35h`, programı bellekte kalıcı bırakarak sonlandırmak için `AH = 31h` kullanılır.
  - Yazma işlemi sırasında kesmeler kapatılır; yazma bitince açılır. Kendi kesmemiz `IRET` ile döner; var olan bir kesmenin önüne eklenmiş bir kodsa `JMP` ile orijinal kesmenin koduna atlanır. Kullanım bitince değiştirilen adresler orijinal değerleriyle geri yazılmalıdır.
- Maskelenebilir ve maskelenemez kesmeler
  - IF sıfırlanarak bir programın maskelenebilir kesmelerle kesilmesi engellenebilir; ama maskelenemez bir kesme geldiğinde program yine kesilir.
  - **Ders sonrası not:** Hoca bu kısımda bir yerde "maskelenemez kesmeler tarafından kesilmeden devam edebilir" ve "8259A üzerinden sürdürülen maskelenemez kesmeler" dedi; bağlama göre kastedilen maskelenebilir kesmelerdir. IF = 0 ile engellenen ve 8259A kesme denetleyicisi üzerinden gelen kesmeler maskelenebilir (INTR) kesmelerdir.
  - **Ders sonrası not:** Hoca bir yerde vektör tablosundaki kesmeleri "1024 tane kesme" diye andı; tablo 1024 bayttır, kesme sayısı 256'dır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
