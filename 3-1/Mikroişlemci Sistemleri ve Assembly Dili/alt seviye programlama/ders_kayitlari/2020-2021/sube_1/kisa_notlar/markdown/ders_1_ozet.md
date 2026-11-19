# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin kapsamı: x86 ailesinin 16 bitlik assembly dili
  - Derste Intel x86 mimarisinin 16 bitlik (8086) işlemcileri için assembly dili öğretilir. 32 ve 64 bitlik karşılıklara ve C ile birlikte kullanıma dönem sonunda değinilir.
  - Derleme zinciri: kaynak kod → ön işlemci (makroların yerine yazılması) → derleyici (assembly karşılığı) → assembler (makine kodu, yani bit dizisi).
  - Mikroişlemci üreticisi işlemciyle birlikte assembly dilini de sağlar; C derleyicileri genellikle üçüncü taraflarca yazılır.
- Assembly neden öğrenilir?
  - Donanımın desteklediği yetenekleri öğrenmek için. Örnek: bir yazmaçtaki 1 bitlerini sayan `POPCNT` (population count) komutu, yazılımla bit genişliği kadar adım süren işi donanımda tek komutla yapar.
  - Derleyiciler her kodu en iyi biçimde optimize edemez. Assembly bilen biri kodu inceleyip hızlandırabilir. Godbolt (Compiler Explorer) sitesinde C/C++ kodunun assembly karşılığı görülebilir; uygun optimizasyon parametresiyle 1'den n'e kadar toplam döngüsü $n(n+1)/2$ formülüne indirgenebilir.
  - Vektör (SIMD, single instruction multiple data) komutları, performans gerektiren işler (ör. borsa işlemleri), mikrodenetleyiciler ve GPU tarafı assembly'nin önemli olduğu alanlardır.
- Kullanılacak araçlar
  - EMU8086: hızlı deneme için simülatör. Makine kodu karşılıkları, komut uzunlukları, yazmaçlar ve bayraklar adım adım izlenebilir, yazmaçlar elle değiştirilebilir. Ancak sonuçlarına tam güvenilmez: 8086'da tanımlı olmayan `shl ax, 3` komutunu kabul edip üç ayrı `SHL AX, 1` komutuna çevirir (ekrandan, 00:25:00).
  - DOSBox + MASM (Microsoft Macro Assembler): esas kullanılacak ortam. Yerel bir klasör `mount` ile sürücü olarak bağlanır; bu satırlar yapılandırma dosyasının `autoexec` bölümüne yazılırsa her açılışta otomatik çalışır.
  - Komut kümesi (instruction set) PDF'i: her komutun aldığı parametreler, makine kodu, süresi ve etkilediği bayraklar için başvuru kaynağı.
- Neden 16 bit?
  - Bir döneme sığan, öğretici bir kapsamdır. 64 bitlik komut kümesi çok genişlemiş ve karmaşıklaşmıştır.
  - Geriye dönük uyumluluk: 16 bitte öğrenilen komutların çoğu 64 bitlik işlemcilerde de geçerlidir.
  - Günümüz bilgisayarları 16 bitlik programı doğrudan çalıştıramaz; bu yüzden emülatör/simülatör kullanılır.
- Mikroişlemci ile mikrodenetleyici farkı
  - Mikroişlemci tek başına çalışamaz; hafıza, çevre birimleri, saat darbe üreteci, reset devresi, tutucu ve tekrarlayıcı devreler gerekir. Genel amaçlıdır.
  - Mikrodenetleyici bu birimlerin hepsini kendi içinde barındırır, daha özel ve basit işler için tasarlanmıştır.
- Dönem boyunca işlenecek konular (ders tanıtım formu, ekrandan, 00:45:00)
  - Komutlar: veri aktarma, aritmetik, dallanma, çevrim, bayrak, mantıksal, öteleme/döndürme, katar (string) işlemleri, ön ekler.
  - Adresleme modları, programlama araçları, debug kullanımı, EXE ve COM tipi programlar.
  - Yordam ve makro, parametre aktarma yöntemleri, EXTRN/PUBLIC, kesme ve kesme vektör tablosu, yüksek seviyeli dillerle birlikte kullanım.
- Mikroişlemcilerin tarihsel gelişimi
  - 4004 (ilk Intel mikroişlemcisi): 4 bit, adresleme kapasitesi 4096 x 4 bit, 45 komut, saniyede 50000 işlem (ekrandan, 01:30:00).
  - 8008: 8 bit, 16 KB adresleme, 48 komut (ekrandan, 01:35:00). 8080: 8 bit, 64 KB.
  - 8086 (1978) ve 8088 (1979): 16 bit, 1 MB adresleme (20 adres ucu), 400 ns komut süresi, 4 veya 6 byte'lık komut kuyruğu, çarpma/bölme komutları, varyasyonlarıyla 20000'i bulan komut sayısı (ekrandan, 01:40:00). 8086'nın veri yolu 16 bit, 8088'in 8 bit.
  - 80286, 80386 (32 bit, 4 GB), 80486 (1989; cache kullanımı, DX modelinde matematik işlemci ana işlemciyle birleşik) (ekrandan, 01:50:00); ardından Pentium, Celeron, Itanium, Core, Core 2, Core i.
- Sayı sistemleri ve tabanlar arası dönüşüm
  - Rakam, sayı ve konumsal (basamak) değer kavramları; ikilik, sekizlik, onluk ve onaltılık tabanlar.
  - Onluktan başka tabana: tam kısım sürekli tabana bölünür, kalanlar en düşük anlamlı basamaktan başlayarak yazılır. Kesirli kısım tabanla çarpılır, tam kısımlar soldan sağa yazılır.
- İşaretli sayı gösterimleri
  - İşaretli genlik, 1'e tümleyen ve 2'ye tümleyen. İlk ikisinde iki farklı sıfır gösterimi vardır. Günümüz işlemcileri 2'ye tümleyen kullanır.
- Veri formatları
  - Alfanümerik veri: ASCII (7 bit, 128 karakter; 8 bitlik genişletilmiş hali), Unicode, BCD.
  - byte (8 bit), word (16 bit), double word (32 bit). 8086'da kayan noktalı sayı komutları yoktur.
  - Little endian ve big endian saklama düzeni; 8086 little endian kullanır.
- 8086'nın iç yapısı ve yazmaçları
  - Mikroişlemcinin temel parçaları: yazmaçlar, ALU, kontrol birimi ve bunlar arasındaki yollar.
  - Genel amaçlı yazmaçlar AX, BX, CX, DX (8 bitlik L/H yarılarıyla), SI, DI, SP, BP; segment yazmaçları SS, CS, DS, ES; özel amaçlı IP; bayrak yazmacı (ekrandan, 02:50:00).
  - Fiziksel adres = segment x 10h + offset (20 bit).
  - 32 bitte E önekli (EAX), 64 bitte R önekli (RAX) yazmaçlar; ek olarak R8-R15, FS, GS (ekrandan, 02:55:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Assembly hem işlemcinin yeteneklerini hem de kısıtlarını gösterir
  - Ders boyunca iki şey birlikte yapılacak: işlemcinin neleri desteklediğini görmek ve assembly'nin dayattığı kısıtlara (ör. dallanma kısıtları, adresleme modları) uyarak program yazmak.
- EMU8086'ya tam güvenilmez
  - Yalnız hızlı deneme, makine kodu ve byte genişliği görmek için kullanılır. Doğruluk için DOSBox + MASM esas alınır.
- Debug çıktıları önemli
  - Programın sonucunu göstermek için debug komutlarının çıktıları kullanılacak.
- Bir mikroişlemcinin kaç bitlik olduğu yazmaç genişliğiyle belirlenir, adres ucu sayısıyla değil
  - 4004'ün 12 adres ucu vardır ama yazmaçları ve veri yolu 4 bit olduğu için 4 bitlik işlemcidir.
- Belirli komutlar belirli yazmaçları varsayılan olarak kullanır
  - `LOOP` her adımda CX'i bir azaltır; çarpma ve bölme AX ile DX'i kullanır. Bu varsayılan yazmaçlar bozulmadığı sürece genel amaçlı yazmaçların hepsi serbestçe kullanılabilir.
- Bit dizisinin işaretli mi işaretsiz mi yorumlanacağını komut belirler
  - Örneğin `MUL` işaretsiz, `IMUL` işaretli çarpma yapar; aynı bit dizisi iki komutta farklı anlam taşır.
- 2'ye bölme için `DIV` yerine sağa öteleme
  - `DIV` çok sayıda saat çevrimi süren karmaşık bir komuttur. 2'nin kuvvetlerine bölmede sağa öteleme (shift) yeterlidir.
- Ders kitabı esas kaynaktır
  - Derste yanlış bir şey söylenirse doğrusu ders kitabına (80x86 Assembly Dili, A. Tevfik İnan) bakılarak düzeltilir (ekrandan, 00:40:00).

## Kısa Tekrar Notları

- Derleme zinciri: ön işlemci → derleyici → assembler → makine kodu.
- `POPCNT`: yazmaçtaki 1 bitlerini donanımda tek komutla sayar; 8086'da yoktur, öteleme/döndürme ile yazılır.
- EMU8086 = hızlı deneme (simülatör); DOSBox + MASM = esas ortam.
- Mikroişlemci yardımcı birimlere muhtaçtır; mikrodenetleyici hepsini içinde barındırır.
- $N$ adres ucu → $2^N$ hafıza gözü. 4004: 12 adres, 4 veri ucu. 8008: 14 adres, 8 veri ucu. 8086/8088: 20 adres ucu (1 MB), veri yolu 16/8 bit.
- K = $2^{10}$, M = $2^{20}$, G = $2^{30}$.
- 45 farklı komut için en az $\lceil \log_2 45 \rceil = 6$ bit gerekir.
- Komut kuyruğu (prefetch queue) atlama ve dallanmalarda boşa gider; günümüzde dallanma tahmini kullanılır.
- CISC: farklı uzunlukta komutlar, farklı yürütme süreleri, çarpma/bölme gibi karmaşık komutlar.
- Cache 486 ile gelir; uzamsal (spatial) ve zamansal (temporal) yerellikten yararlanır.
- 4 bit işaretli genlik ve 1'e tümleyen: aralık $-7 \ldots +7$, iki sıfır. 2'ye tümleyen: $-8 \ldots +7$, tek sıfır.
- 2'ye tümleyen pratik yolu: sağdan ilk 1 dahil olduğu gibi bırak, soldakilerin hepsini tersle.
- 8 bit: işaretsiz 0-255, işaretli -128..127; en anlamlı bitin ağırlığı işaretsizde $+128$, işaretlide $-128$.
- BCD: her onluk basamak 4 bit; $(526)_{10} = (0101\ 0010\ 0110)_{BCD}$.
- Little endian: düşük anlamlı byte düşük adreste (8086). Big endian: yüksek anlamlı byte düşük adreste (Motorola).
- Fiziksel adres = segment x 10h + offset.
- Bayraklar: CF, PF, AF, ZF, SF, TF, IF, DF, OF.

## Detaylı Açıklamalar

- **Assembly'nin yeri.** Yüksek seviyeli bir dilde tek satır olan bir işlem, assembly'de birden çok satıra karşılık gelebilir. Tersine, donanımın özel olarak desteklediği bir işlem (ör. `POPCNT`) assembly'de tek komutken C'de döngüyle yazılır. Godbolt örneğinde 1'den `num`'a kadar toplayan bir C++ fonksiyonunun x86-64 clang 9.0.0 çıktısında döngü `cmp`, `jge` ve `jmp` komutlarıyla kurulur (ekrandan, 00:15:00). Matematikte bu toplam $n(n+1)/2$ ile sabit sürede bulunur; derleyici uygun optimizasyon parametresiyle bu dönüşümü kendisi yapabilir. Ama her kodu bu kadar iyi optimize edemeyebilir. Assembly bilmek bu açığı kapatmayı sağlar.
- **EMU8086 ve DOSBox.** EMU8086'da `emulate` ile her satırın makine kodu ve kapladığı byte görülür. Örneğin `jmp start` satırı `EB 0C` olmak üzere 2 byte yer kaplar (ekrandan, 00:25:00). Yazmaçlar ve bayraklar her adımda izlenir, geri ve ileri adım atılabilir, yazmaç değeri elle değiştirilebilir. DOSBox ise bir DOS emülatörüdür; üzerine MASM kurulur. Hoca kendi sürümünün büyük olasılıkla MASM 5.0 olduğunu söyledi. DOSBox'ın kendi diski olmadığı için yerel klasör `mount` ile sürücü olarak bağlanır, `C:`/`D:` ile sürücüler arasında geçilir.
- **Makro ve yordam.** Yordam (procedure) fonksiyona karşılık gelir: çağrıldığında kodun bulunduğu yere dallanılır, iş bitince geri dönülür. Makro ise C'deki `#define` gibidir: her çağrıldığı yere derleme öncesinde kopyalanır. Bu yüzden makro hiç çağrılmazsa makine koduna etkisi yoktur, her çağrıda kod makro boyu kadar büyür. Yordam ise bir kez yer kaplar, çağrı sayısı kod boyunu artırmaz ama her çağrının bir maliyeti (overhead) vardır: durumu korumak için yazmaçlar yığına atılır ve dönüşte geri alınır. Sonuç: kısa, çağrı maliyetini aşmayan işler makroyla, uzun ve karmaşık işler yordamla yazılır.
- **Parametre aktarımı (ileride işlenecek).** Yazmaç üzerinden, ortak hafıza üzerinden, EXTRN/PUBLIC ile farklı dosyalar arasında ve yığın üzerinden aktarım görülecek. Hocaya göre assembly'de her şey aslında değer olarak aktarılır; bir adres aktarıldığında da adresin değeri aktarılmış olur, bu bir referans olarak yorumlanabilir. Farklı dosyalarda derlenen modüllerde dışarıdan kullanılan değişken `extern`, dışarıya açılan değişken `public` olarak tanımlanır ve bağlama (link) sırasında eşleşir.
  - **Ders sonrası not:** Hoca `CALL` komutundan önce işlemcinin yazmaçları otomatik olarak yığına attığını söyledi. Doğrusu: 8086'da `CALL` yalnız dönüş adresini (yakın çağrıda IP, uzak çağrıda CS ve IP) yığına atar. Diğer yazmaçları korumak programcının işidir (`PUSH`/`POP`).
  - **Ders sonrası not:** Hoca Linux tarafında 7 parametrenin 7 yazmaçla döndürüldüğünü söyledi. Doğrusu: Linux x86-64 çağrı kuralında (System V) ilk 6 tam sayı parametre RDI, RSI, RDX, RCX, R8, R9 yazmaçlarıyla aktarılır, fazlası yığından geçer. Dönüş değeri RAX'tedir.
- **Kesme mantığı.** Bir tuşu beklemenin iki yolu vardır. Yoklama (polling) yönteminde program sürekli düğmeyi okuyup değerini kontrol eder, yani aktif bekler. Kesme yönteminde düğme fiziksel bir kesme ucuna bağlanır ve bir kesme numarasına (örnekte 10) atanır. Düğmeye basıldığında ana akış kesilir, o kesmenin alt programı çalışır, sonra kalınan yere dönülür. Böylece aktif bekleme gerekmez.
- **Adres ve veri yolu hesabı.** Mikroişlemcinin adres uçları hafıza biriminin adres uçlarına doğrudan bağlıdır. $N$ adres ucuyla $2^N$ göz seçilebilir; her gözün bit sayısı da veri yolu genişliğini verir. 4004 için $4096 = 2^{12}$ olduğundan 12 adres ucu vardır; her göz 4 bit tuttuğundan veri yolu 4 bittir. 4004'ten sonrası için her hafıza gözünün 8 bit (1 byte) tuttuğu varsayılır. 8008'de $16\text{K} = 2^4 \cdot 2^{10} = 2^{14}$ olduğundan 14 adres ucu vardır. 8086/8088'de $1\text{M} = 2^{20}$ olduğundan 20 adres ucu vardır. 386'da $2^{32} = 2^2 \cdot 2^{30}$ byte, yani 4 GB adreslenir.
  - **Ders sonrası not:** Hoca 8080 için "64 KB = $2^8 \cdot 2^{10}$, 18 adres ucu" dedi. Doğrusu: $64\text{K} = 2^6 \cdot 2^{10} = 2^{16}$, yani 16 adres ucu.
  - **Ders sonrası not:** Hoca 4004'ün saniyede 50000 işlemini "frekansı 50 kHz" diye yorumladı. Saniyedeki işlem sayısı saat frekansıyla aynı şey değildir; bir komut birden çok saat çevrimi sürer. 4004'ün saat frekansı büyük olasılıkla 740 kHz civarındadır.
- **Komut kuyruğu ve dallanma tahmini.** Hafızaya erişim en çok zaman alan iştir. 8086 hafızaya gitmişken sıradaki birkaç komutu birlikte okuyup kuyruğa (prefetch queue) alır. Sıradaki komut bir atlama (`JMP`) ya da koşullu dallanma olursa kuyruktaki komutlar boşa gider. Günümüz işlemcileri dallanma tahmini (branch prediction) ile kuyruğu doldurur. Hoca, Intel işlemcilerde çıkan bazı donanım açıklarından birinin bu tahmin mekanizmasını kullandığını hatırlattı.
- **Cache.** 486 ile gelen cache, hafıza hiyerarşisinde yazmaçlardan sonra işlemciye en yakın, RAM'den hızlı bir tampondur. Döngüde dizinin ardışık gözlerine erişmek uzamsal yerelliktir (spatial locality). Aynı `sum` değişkenine farklı zamanlarda tekrar tekrar erişmek zamansal yerelliktir (temporal locality). Her iki durumda da veri cache'te bulunursa RAM'e gitmek gerekmez. Cache'teki veri güncellenince RAM'in ne zaman güncelleneceği gibi konular Bilgisayar Donanımı dersine bırakıldı.
- **Tabanlar arası dönüşüm.** Konumsal gösterimde her basamağın ağırlığı tabanın kuvvetidir: $132 = 10^2 \cdot 1 + 10^1 \cdot 3 + 10^0 \cdot 2$ (ekrandan, 01:55:00). Aynı "11" rakamları 2 tabanında 3, 8 tabanında 9, 10 tabanında 11 eder. Kesirli kısımda ağırlıklar negatif kuvvettir: $(0.1)_2 = 0.5$. Onluktan onaltılığa: $109 = 6 \cdot 16 + 13$ olduğundan $(109)_{10} = (6D)_{16}$. Kesirli dönüşümde $(0.625)_{10}$: $0.625 \cdot 2 = 1.25$ (1), $0.25 \cdot 2 = 0.5$ (0), $0.5 \cdot 2 = 1.0$ (1) → $(0.101)_2$ (ekrandan, 02:00:00). Kesirli kısım sıfıra hiç ulaşmayabilir: $(0.2)_{10} = (0.\overline{0011})_2$.
  <!-- BELİRSİZ: Onluktan ikilik ve sekizlik tabana tam sayı dönüşüm örneklerinde kullanılan sayılar altyazıdan çıkmıyor; ilgili kare yok. -->
- **İşaretli gösterimler (4 bit).** İşaretli genlikte en anlamlı bit işarettir, kalan bitler genliktir: $0011 = +3$, $1011 = -3$ (ekrandan, 02:05:00); $0000$ ve $1000$ iki ayrı sıfırdır. 1'e tümleyende negatif sayının genlik bitleri terslenir: $0011 = +3$, $1011 = -4$; $0000 = +0$ ve $1111 = -0$ (ekrandan, 02:10:00). 2'ye tümleyende genlik bitlerinin 1'e tümleyenine 1 eklenir: $1011$ için $011 \to 101$, sonuç $-5$ (ekrandan, 02:15:00). 4 bitte en büyük sayı $0111 = 7$, en küçük $1000 = -8$; aralık simetrik değildir ama 16 gösterimin hepsi kullanılır.
- **8 bit işaretli sayılar.** En anlamlı bitin ağırlığı işaretsizde $2^7 = 128$, işaretlide $-2^7 = -128$ alınabilir (ekrandan, 02:35:00). Hocanın örneğinde $10001111$ işaretsiz yorumla $128 + 15 = 143$, işaretli yorumla $-128 + 15 = -113$ eder. Klasik yolla da genlik $01110001 = 113$ çıkar, sonuç $-113$. Python ile doğrulandı.
  <!-- BELİRSİZ: 02:11:59'daki 8 bitlik 2'ye tümleyen alma örneğinin bitleri altyazıda tutarsız; kare yok. -->
- **BCD.** Her onluk basamak 4 bitle tutulur: $(526)_{10} = (0101\ 0010\ 0110)_{BCD}$, 12 bit (ekrandan, 02:25:00). Aynı sayı ikilik tabanda $1000001110$, yani 10 bittir. BCD daha çok yer kaplar ama insan tarafından daha kolay okunur. 3 bit yalnız 0-7'yi gösterebildiği için yetmez. 4 bitle 16 değerden 6'sı kullanılmaz.
  - **Ders sonrası not:** Hoca en anlamlı biti 1 olan BCD değerlerinden yalnız 9'un kullanıldığını söyledi. Doğrusu: 8 ($1000$) ve 9 ($1001$) kullanılır; $1010$-$1111$ arasındaki 6 değer kullanılmaz.
- **Endian.** 32 bitlik $12345678h$ değeri 100h adresinden itibaren little endian düzende 100h: 78h, 101h: 56h, 102h: 34h, 103h: 12h olarak saklanır (ekrandan, 02:40:00). Big endian düzende 100h: 12h, 101h: 34h, 102h: 56h, 103h: 78h olur.
- **Yazmaçlar.** AX (akümülatör) ALU sonuçlarını saklar ve kendine özel, daha kısa ve hızlı komutları vardır. BX taban (base) yazmacıdır, CX sayaçtır (`LOOP`), DX çarpma ve bölmede AX'in yardımcısıdır. SP ve BP yığın, SI ve DI dizi indisi ve katar işlemlerinde kaynak/hedef adresi için kullanılır. 16 bitlik yazmaçlarla 20 bitlik adres üretmek için segment yazmacı 10h ile çarpılır (sonuna bir onaltılık 0 eklenir) ve 16 bitlik offset eklenir. Bayraklar: CF (elde), PF (eşlik), AF (4 bitlik işlemlerde yardımcı elde), ZF (sıfır), SF (işaret), TF (adım adım debug), IF (donanım kesmelerini açma/kapama), DF (katar işlemlerinin yönü), OF (taşma).
- **32 ve 64 bit.** 32 bitte E (extended) önekiyle EAX gibi yazmaçlar gelir; EAX'in alt 16 biti AX, onun yarıları AL ve AH'dir. EAX'in üst 16 bitine ayrı bir adla erişilemez. Hoca bunu tasarım tercihi olarak yorumladı; gerekirse 16 bit sağa ötelenerek üst kısım AX'e alınabilir. 64 bitte R önekli yazmaçlar (RAX vb.) ve R8-R15 eklenir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
