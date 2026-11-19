# Ders 13 Genişletilmiş Notu: Yüksek Seviyeli Dil ile Assembly Bağlantısı: Inline Assembly, Obje Kodu ve Çağırma Kuralları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ödev Sorularının Çözümü: Boyut Analizi ve İşlem Sırası
- 2. Yüksek Seviyeli Dil ile Assembly Bağlantısının İki Yolu
- 3. Visual Studio'da Assembly Dosyası Derleme Ortamı
- 4. Inline Assembly Örneği: Dizi Elemanlarının Bitlerini Ters Çevirme
- 5. Visual Studio'da Disassembly ve Yığın İncelemesi
- 6. Ayrı Assembly Dosyası: Selection Sort Örneği
- 7. Çağırma Kuralları (Calling Conventions)
- 8. Assembly Yordamında Yığından Parametre Okuma
- 9. Release ve Debug Derlemelerinde Derleyicinin Ürettiği Kod
- 10. Linux'ta GCC ve NASM ile C-Assembly Bağlantısı
- 11. GDB ile Hata Ayıklama
- Örnek Sorular
- Dersin Toparlaması

## 1. Ödev Sorularının Çözümü: Boyut Analizi ve İşlem Sırası

Dönemin son dersi, yüksek seviyeli dillerle assembly arasındaki bağlantıya ayrılmıştı. Hoca konuya geçmeden önce, öğrencilerin kodlama sorularında sık yaptığı hataları ödevdeki üç soru üzerinden gösterdi. Kodları emu8086'da yazıp adım adım yürüttü.

### 1.1 Genel hata: yüksek yarının belirsiz kalması

En sık görülen hata, 16 bitlik bir işlem yapılırken yazmacın yüksek yarısının (DH, AH ya da DX) değerinin kesinleştirilmemesiydi. Önceki işlemler 8 bitlik yapılıp son toplama 16 bitlik bir yazmaç üzerinden yapıldığında, yüksek yarıda o an ne varsa (rastgele bir değer) sonuca karışır.

### 1.2 Ardışık çarpma ve bölmede sıra

İkinci yaygın hata, ardışık çarpma ve bölme işlemlerinin sırasıyla ilgiliydi (sınavdaki "dizinin her elemanının beşte birinin ortalaması" ya da "üç katı" gibi sorular). Hoca'nın kuralı şudur: önce çarpma, sonra bölme. 16 bitlik `MUL` sonucunu DX:AX'e yazar; DX'teki eski değerin üzerine çarpımın yüksek word'ü gelir. Ardından yapılan `DIV` de DX:AX'i böler, böylece doğru sayı bölünmüş olur. Önce bölme yapılırsa DX'te kalan bulunur; hoca bu kalanla gerekli işlem yapılmadan çarpmaya geçilirse kalanın yüksek anlamlı word gibi işleme girdiğini söyledi. Aynı kural 8 bitlik çarpma ve bölmede AH için de geçerlidir.

> **Hocanın vurgusu:** Sıralı çarpma ve bölmede matematiksel açıdan sıranın önemi yoktur, ama assembly'de oluşan değerlerin kontrolü ve kesinleştirilmesi açısından çok büyük önemi vardır. Önce çarpma, sonra bölme yapın.

> **Ders sonrası not:** Hoca, önce bölme yapılınca DX'teki kalanın sonraki `MUL` ile birlikte çarpıldığını söyledi. Doğrusu: `MUL r/m16` yalnız AX'i çarpar; DX'i girdi olarak kullanmaz, üzerine yazar. Önce bölmenin asıl sakıncaları, kalanın (kesirli kısmın) kaybolması ve DX'teki kalanın daha sonraki bir `DIV` ya da 32 bitlik işlemde DX:AX'in parçası sayılmasıdır.

### 1.3 Boyut analizi

Üçüncü sorun boyut analiziydi. Bir dizinin toplamı biriktirilecekse, gereken boyut en büyük eleman değeri ile eleman sayısının çarpımından çıkarılır. Hocanın örnekleri:

- Elemanlar işaretli 8 bite sığıyor, eleman sayısı 60 000 civarında: $127 \times 60\,000 = 7\,620\,000$, 16 bite sığmaz, 32 bit gerekir.
- Word tipinde 500 elemanlı bir dizinin ortalaması: en büyük word değeriyle 500'ün çarpımı da 16 biti aşar, 32 bit gerekir.

> **Ders sonrası not:** Hoca en büyük word değerini 65534 dedi; doğrusu 65535'tir (FFFFH). $65535 \times 500 = 32\,767\,500$ olup yine 16 bite sığmaz.

Toplam 32 bite taşıyorsa izlenecek strateji, işlemcinin çarpma ve bölmede zaten kullandığı "sanal 32 bitlik yazmaç" DX:AX'i kullanmaktır: düşük anlamlı word AX'te biriktirilir, her toplamanın eldesi `ADC DX, 0` ile DX'e eklenir. Bu durumda DX ve AX yalnız bu iş için ayrılır, diğer işler için başka yazmaçlar kullanılır. Hoca, aynı işi veri kesiminde `DD` ile tanımlanmış bir değişkenle yapanların cevabını da doğru saydığını, ama DX:AX kullanmanın daha pratik olduğunu söyledi.

### 1.4 Soru 1: AL, AH, BL ve CL'nin toplamını DX'te saklamak

Soru metni ekranda şöyleydi (ekrandan, 00:10:00): "AL, AH, BL ve CL'yi toplayıp sonucu DX'te saklayan komutları yazınız."

Önce boyut: dört 8 bitlik işaretsiz değerin toplamı en çok $4 \times 255 = 1020$'dir, 16 bite sığar. Strateji: DL'de düşük 8 bitlerin toplamı, DH'da her 8 bitlik toplamanın eldesi biriktirilir. DH da biriktirmede kullanılacağı için başta sıfır olduğundan emin olunmalıdır. Hocanın yazdığı kod (ekrandan, 00:15:00):

```asm
XOR DX, DX
ADD DL, AL
ADD DL, AH
ADC DH, 0
ADD DL, BL
ADC DH, 0
ADD DL, CL
ADC DH, 0
```

İlk toplamada (DL = 0 + AL) elde oluşamaz, bu yüzden ardından `ADC` yoktur. Sonraki üç toplamanın her birinde taşma olabilir; elde `ADC DH, 0` ile DH'a eklenir.

Sağlama için hoca dört yazmaca da olabilecek en büyük değeri (255) yükleyip kodu adım adım yürüttü. İkinci, üçüncü ve dördüncü toplamada CF = 1 oldu ve her seferinde DH'a aktarıldı. Programlayıcı modundaki hesap makinesiyle kontrol: $4 \times 255 = 1020 = 03FCH$; DX'te 03FCH elde edildi.

> **Hocanın vurgusu:** Yazdığınız kodu mutlaka olabilecek en büyük değerlerle sağlayın. Yapılabilecek en iyi kontrol budur.

### 1.5 Soru 2: DL'deki sayının küpü

Soru metni (ekrandan, 00:20:00): "DL'de tutulan sayının küpünü bulan assembly komutlarını yazınız."

Boyut analizi: en büyük değer 255'tir. $255^2 = 65\,025$ 16 bite sığar; $255^3 = 16\,581\,375$ ise 16 milyonu aşar ve 32 bite sığar. 24 bitlik yazmaç olmadığı için 8, 16, 32 bit diye ilerlenir.

Adım 1, kare: 8 bitlik `MUL` AL ile operandı çarpar ve sonucu AX'e yazar ($AX \leftarrow AL \times op$). Bu yüzden önce DL, AL'ye kopyalanır:

```asm
MOV AL, DL
MUL DL        ; AX <- DL^2
```

Adım 2, küp: ikinci kez `MUL DL` yazılırsa yine AL ile DL çarpılır ve AH'daki anlamlı kısım kaybolur (ekranda hoca bu yanlış satırı önce yazıp üzerinde durdu). Yapılması gereken 16 bitlik bir çarpmadır: AX × DL. AX ile DL boyut olarak uyumsuz olduğu için DL, DX'e genişletilir: `XOR DH, DH` ile DH sıfırlanır, böylece DX, DL'nin 16 bitlik eşdeğeri olur. Sonra `MUL DX` ile DX:AX ← AX × DX elde edilir.

```asm
MOV AL, DL
MUL DL        ; AX <- DL^2
XOR DH, DH    ; DX = DL (16 bit)
MUL DX        ; DX:AX <- DL^3
```

Sağlama (DL = 255): ilk çarpmadan sonra AX = FE01H ($65025$). İkinci çarpmadan sonra DX:AX = 00FD02FFH ($16\,581\,375$); hoca sonucu "FD02FF" diye okudu.

**Soru:** İşaretli sayı kabul eden cevaplar ne olacak? **Cevap:** Hoca bu cevapları da kontrol ettiğini ve doğru çalıştığını söyledi. İşaretli sayıda `IMUL` kullanılır ve DL'nin DX'e genişletilmesi işaret korunarak yapılmalıdır: DL'nin en yüksek biti 1 ise sayı negatiftir ve DH = FFH olmalıdır.

> **Ders sonrası not:** Hoca önce örneği işaretsiz kabul ettiğini söyledi, biraz sonra "örneği işaretli sayı olarak yaptım" dedi. Ekrandaki kod `MUL` kullandığı için örnek işaretsizdir; bu söz büyük olasılıkla dil sürçmesidir.

### 1.6 Soru 3: Rastgele sayı üretimi

Üçüncü soru doğrusal eşlik (çarp-topla-mod) yöntemiyle rastgele sayı üretimiydi. Hoca cevap anahtarındaki kodu gösterdi (ekrandan, 00:25:00):

```asm
MOV AX, CODESG   ; DS'yi bozmadan, ES yardimiyla
MOV ES, AX       ; CS:23'teki word,
MOV AX, ES:[23]  ; yani seed AX'e okunur
MUL A_SAY        ; DX:AX <-- AX * A_SAY
ADD AX, C_SAY    ; DX:AX <-- DX:AX + C_SAY
ADC DX, 0
DIV M_SAY        ; DX <-- DX:AX % M_SAY ; AX <-- DX:AX / M_SAY
MOV SONRAKI, DL  ; 16 bitlik sayinin LSb'si kullanildi
```

Dikkat edilecek noktalar:

- İlk seed kod segmentinin 23. ofsetinden alınır. Kod segmentinin açıkça kullanılması gerekiyorsa segment adı ve iki nokta yazılır: `CS:[23]` ya da CODESG değeri ES'ye atanıp `ES:[23]`.
- Sıra yine önce çarpma, sonra toplama, en son bölmedir (mod). Toplamada 32 bite taşma olabileceği için `ADC DX, 0` gerekir.
- Bölümden sonra kalan (16 bitlik rastgele sayı) DX'tedir. 8 bitlik bir sayıya indirmek için en pratiği düşük anlamlı baytı (DL) almaktır; ya da 256'ya göre mod alınıp 0-255 arasında bir sayı elde edilebilir.

**Soru:** Soruda n adet rastgele sayı mı isteniyordu? **Cevap:** Hayır, bir tane üretmek yeterliydi; birden fazla üretenlerin cevabı da doğru sayıldı.

**Soru:** Çıkan değer 0-255 arasında değilse yeniden hesaplamak doğru mu? **Cevap:** Böyle yapan uygulamalar da doğru kabul edildi; bu, bir rastgele sayı dizisi üretmeye karşılık gelir ve koşul en az bir tane üretmektir.

## 2. Yüksek Seviyeli Dil ile Assembly Bağlantısının İki Yolu

Haftanın asıl konusu yüksek seviyeli dillerle assembly bağlantısıydı: Windows'ta Visual Studio ve onunla gelen assembler, Linux'ta GCC ve NASM. Hem Windows hem Linux için ortak iki yaklaşım vardır (ekrandan, 00:30:00):

- **Inline:** Yüksek seviyeli dil kodunun içine assembly kodlarının yerleştirilmesi.
- **Object code:** Derlenen assembly programından oluşan obje dosyasının, yüksek seviyeli dille kodlanan program içinden çağrılması. Assembly dosyası derlenir, oluşan obje dosyası C kodunun obje dosyasıyla birlikte linklenir. Fonksiyon assembly dosyasında yazılıdır, C tarafından çağrılır (assembly function call).

Bu iletişim iki yönlü olabilir: C tarafından assembly fonksiyonu çağrılabildiği gibi assembly tarafından C fonksiyonu da çağrılabilir. Derste yalnız yüksek seviyeli dilden assembly yordamının çağrılmasına bakıldı; assembly'den C fonksiyonu çağırma konusu atlandı.

## 3. Visual Studio'da Assembly Dosyası Derleme Ortamı

Visual Studio'da `.asm` dosyalarını derleyebilmek için birkaç hazırlık gerekir (hoca bunlar için YouTube'da anlatım videoları bulunduğunu da belirtti):

1. Visual Studio'da boş bir proje (Empty Project) oluşturulur.
2. Source Files kısmında "Ekle" ile yeni bir öğe eklenir. Hoca öğe türü olarak header dosyası seçildiğini ama uzantının `.asm` verildiğini söyledi.
3. `.asm` dosyası için özel bir derleme kuralı tanımlanır: dosyanın Özellikler menüsünde Genel bölümünde Öğe Türü (Item Type) olarak "Custom Build Tool" seçilir.
4. Custom Build Tool için açılan bölümde Command Line ve Outputs alanları doldurulur. Command Line, Visual Studio ile gelen yerleşik assembler'ın (`ml`) hangi bayraklarla çalışacağını belirtir: `ml /c /Cx /coff` ve ardından dosyanın tam yolu (çift tırnak ve yüzde işaretleriyle yazılan bir makro). Description yalnız açıklamadır. Outputs alanına dosya adının `.obj` uzantılı hali yazılır.

<!-- BELİRSİZ: Command Line ve Outputs alanlarının tam metni ekranda okunamadı; altyazıda "ml /c /Cx /coff" ve "çift tırnak, yüzde ve full path" diye geçiyor. -->

> **Ek bilgi (derste anlatılmadı):** Bu tür kurulumlarda Command Line genellikle `ml /c /Cx /coff "%(FullPath)"`, Outputs da `%(Filename).obj` biçiminde yazılır. `/c` yalnız derleme yapıp linklemeyi atlar, `/Cx` dış ve public sembollerde büyük-küçük harfi korur, `/coff` COFF biçiminde obje dosyası üretir.

Bu hazırlıktan sonra `.asm` dosyaları projenin geri kalanıyla birlikte derlenir.

## 4. Inline Assembly Örneği: Dizi Elemanlarının Bitlerini Ters Çevirme

### 4.1 C tarafı

Örnek projede (`inline`) tek bir `Source.c` dosyası vardır (ekrandan, 01:00:00 ve 00:40:00):

```c
#include <stdlib.h>
#include <stdio.h>

const int n = 10;

int main() {
    int dizi[10];
    int i;
    // printf("%d", sizeof(int));
    printf("Dizinin orjinal hali:\n");
    for (i = 0; i < n; i++) {
        dizi[i] = i + 1;
        printf("%08x, ", dizi[i]);
    }

    __asm {
        ...
    }

    printf("\nDizinin reverse hali:\n");
    for (i = 0; i < n; i++)
        printf("%08x, ", dizi[i]);
```

<!-- BELİRSİZ: Dosyanın son satırları (return ve kapanış) karelerde görünmüyor. -->

Dizinin elemanları 1'den 10'a kadar değerler alır ve aralarında virgül olacak şekilde yan yana yazdırılır.

**Soru (hoca sınıfa sordu):** Değerler neden 8 hex basamak (`%08x`) olarak yazdırılıyor? **Cevap:** Dizi int tipindedir. Hoca `sizeof(int)` değerini yazdırıp breakpoint ile baktı: 4. Dört bayt 32 bit eder; her hex basamak 4 bit olduğundan 32 bit 8 hex basamakla gösterilir. Hoca, Visual Studio'da 32 ya da 64 bit derlemede int boyutu sabit görünse de başka bir platform ya da derleyiciye geçildiğinde int boyutunun kontrol edilmesi gerektiğini ekledi.

### 4.2 Algoritma: 32 bitlik değeri ters çevirmek

Assembly bloğunun görevi dizinin her gözünü bit bazında ters çevirmektir: en düşük anlamlı bit en yüksek anlamlı bite gider, sıradaki bitler de ayna görüntüsü gibi yer değiştirir. Bu 10 eleman için yapılır.

Hocanın önerdiği yol: orijinal değer sağa doğru ötelenerek her seferinde en düşük biti carry bitine düşürülür; carry biti de bir yardımcı yazmaca sağdan beslenir. Orijinal değer sağa ötelenirken yardımcı yazmaç sola ötelenir (döndürülür). Bu işlem 32 bit için tek tek yapılınca orijinal değer yardımcı yazmaçta ters sırada oluşur. Hoca bunu tahtada `0010...011` gibi bir dizinin `110...0100` gibi bir diziye dönüşmesiyle gösterdi.

### 4.3 Assembly bloğu

Ekrandaki kod (ekrandan, 00:40:00 ve 00:45:00):

```asm
__asm {
    mov ecx, n
    xor esi, esi

L2 : mov eax, dizi[esi]
     push ecx
     mov ecx, 32

     L1 : shr eax, 1
          rcl ebx, 1
          loop L1
          mov dizi[esi], ebx
          add esi, 4
          pop ecx
          loop L2
}
```

Kodun çalışması:

- **Dış döngü (L2):** 10 eleman için döner. 16 bitlik assembly'de CX'e n atanırdı; burada 32 bitlik assembly kullanıldığı için ECX'e n atanır.
- **İndis:** Dolaylı adresleme `dizi[esi]` biçimindedir, bu yüzden ESI döngüden önce `xor esi, esi` ile sıfırlanır.
- **Eleman okuma:** Dizi elemanı 4 baytlık (32 bitlik) bir değerdir, bu yüzden 32 bitlik bir yazmaca (EAX) alınır.
- **İç döngü (L1):** Her eleman için 32 kez döner. İç döngü de ECX'i kullandığı için dış döngünün ECX değeri bozulmasın diye iç döngüden önce `push ecx`, sonra `pop ecx` yapılır.
- **Ters çevirme:** `shr eax, 1` ile EAX bir kez sağa ötelenir, en düşük biti CF'ye gelir. `rcl ebx, 1` (rotate through carry left) carry dahil EBX ile 33 bitlik bir sanal yazmaç üzerinde bir kez sola döndürme yapar; böylece EAX'ten çıkan bit EBX'in en düşük bitine yüklenir. 32 tekrar sonunda EBX, EAX'teki orijinal değerin bit sırası ters çevrilmiş halidir.
- **Yazma:** EBX dizinin aynı gözüne yazılır. ESI 4 artırılır, çünkü int 4 bayttır ve sonraki eleman 4 bayt ötededir.

> **Ek bilgi (derste anlatılmadı):** EBX iç döngüden önce sıfırlanmasa da sonuç doğrudur: 32 kez `rcl` yapılınca EBX'in eski bitlerinin hepsi dışarı (CF'ye) çıkar ve yerlerine EAX'ten gelen 32 bit girer.

### 4.4 32 bitlik inline assembly kuralları

> **Hocanın vurgusu:** 32 bitlik assembly yazdığımız için derleme kuralı mutlaka x64 değil x86 seçilmelidir.

- Köşeli parantez içinde dolaylı adreslemede kullanılan yazmaç ESI'dir. 64 bitlik derleme yapılsaydı RSI olması gerekirdi. 32 bitte dolaylı adreslemede ESI, EDI ve EBX kullanılabilir. 64 bit seçilip bu kod denenseydi `[esi]` ve ECX ile döngü yüzünden hata verirdi.
- Döngüler artık CX değil ECX üzerinden döner.
- Visual Studio'da 32 ya da 64 bit derleme vardır; 16 bitlik derleme imkânı yoktur.
- 8, 16 ve 32 bitlik veri erişimi vardır: EAX ile çalışılabileceği gibi AX ile de çalışılabilir. Örneğin char dizisi tanımlansaydı her eleman AL'ye alınabilirdi. AL, AH, CL, CH, DL, DH gibi yazmaçlara erişim sürer, ama EAX'in yüksek anlamlı 16 bitine ayrı bir adla erişim yoktur.
- Yığın tanımı yapılmaz; bu bir C dosyası olduğu için yığın C programının tanımından gelir.
- Hoca, kendi i7 işlemcisinde 8086'da olmayan ek komutlar ve modlar bulunduğunu (ör. population count komutları, bazı özel bellekten belleğe aktarımlar) ama ödev için 16 bitlik assembly'de görülen kapsamın yeterli olduğunu söyledi. Dikkat edilecek nokta, özel görevli yazmaçların 32 bitlik adlarıyla (E önekiyle) kullanılmasıdır.

### 4.5 Çalıştırma sonucu

Ekrandaki çıktı (ekrandan, 00:50:00):

```text
Dizinin orjinal hali:
00000001, 00000002, 00000003, 00000004, 00000005, 00000006, 00000007, 00000008, 00000009, 0000000a,
Dizinin reverse hali:
80000000, 40000000, c0000000, 20000000, a0000000, 60000000, e0000000, 10000000, 90000000, 50000000,
```

Hocanın yorumu:

- 1'in yalnız en düşük biti 1'dir (31 sıfır, bir 1). Ters çevrilince 1 en yüksek bite gelir. En üstteki 4 bit 1000B = 8H, kalan 28 bit sıfır olduğundan 7 hex sıfır daha gelir: 80000000H. Hoca bunu ekranda "0000.......00001 → 1000...000" diye gösterdi.
- 2 ters çevrilince en üstteki 4 bit 0100B = 4H olur: 40000000H.
- 10 = 0AH = 1010B; ters çevrilince en üstteki 4 bit 0101B = 5H olur: 50000000H.

Bu değerler python ile de doğrulandı.

## 5. Visual Studio'da Disassembly ve Yığın İncelemesi

### 5.1 Disassembly penceresi

Fonksiyonun girişine breakpoint konup Debug modda başlatılınca, Debug > Windows menüsünden Disassembly açılabilir. Burada C kodunun derlenmiş assembly karşılığı görülür:

- main'in başında genel tanımlarla ve işletim sistemine dönüş değeriyle ilgili işlemler vardır.
- `printf` gibi bir C fonksiyonunun assembly'den nasıl çağrıldığı ve parametrelerin nasıl aktarıldığı görülür.
- for döngüsü için hangi karşılaştırmaların yapıldığı görülür.
- F11 ile assembly seviyesinde adım adım ilerlenebilir. Ekrana yazdırma kısmına girmemek için for döngüsünden sonrasına breakpoint koyup Continue ile oraya kadar gitmek daha pratiktir.
- Include edilen başlık dosyalarına karşılık gelen kodlar da disassembly'de eklenmiş olarak görülür.
- Inline assembly yazılmış olsa bile derleyicinin bazı durumlarda kodu biraz değiştirdiği görülür.

Registers penceresinde yazmaç değerleri izlenebilir. Gerçek modda olunmadığı, tablolar üzerinden çalışan sanal/korumalı bir mod kullanıldığı için görülen adresler fiziksel adreslere denk gelmez.

### 5.2 Derleyici optimizasyonu ve elle assembly

Hoca dönem başında gösterdiği çevrimiçi derleyici aracını yeniden önerdi: orada derleyici optimizasyon bayrakları açılıp kapatılarak üretilen kodun nasıl değiştiği incelenebilir.

> **Hocanın vurgusu:** Ne yaptığımızı çok net bilmiyorsak, elle yazdığımız assembly kodu, aynı işi C'de yazıp derleyici optimizasyonlarını uygun şekilde açtığımız durumdan daha düşük performansta kalabilir. Harici olarak ve net biçimde ne yaptığımızı biliyorsak assembly ile daha hızlı çalışma elde etmek mümkündür.

Derleyici optimizasyonu iyi kullanıldığı halde yüksek performans istenen çok özel fonksiyonlar varsa, kod disassembly edilip derleyicinin ürettiği assembly incelenir; gereksiz işlemler giderilerek hızlandırma yapılabilecek yerler varsa devreye alınır. Hoca ayrıca Debug ve Release derlemelerinde farklı optimizasyonlar yapıldığını, Release'de main tanımından sonra oluşan kodun farklılaştığını gösterdi.

### 5.3 PUSH işleminin yığındaki etkisi

Aradan sonra hoca, ilk yarıda bulamadığı yığın içeriğini gösterdi (ekrandan, 01:20:00). `push ecx` satırına breakpoint konup kod başlatıldı. Debug > Windows > Registers penceresinden ESP'nin 32 bitlik değeri kopyalanıp Debug > Windows > Memory penceresinde adres olarak açıldı (aynı anda 4 farklı bellek alanı izlenebilir).

Sıradaki komut `push ecx`'tir ve ECX'te 10 vardır (dizinin eleman sayısı). F11 ile bir adım yürütülünce:

- ESP değeri azaldı: yığına bir şey atıldıkça yığın işaretçisi azalır.
- Sonraki komuta geçildiği için IP (EIP) de değişti.
- Yığının daha düşük adreslerine bakıldığında, en son atılan 10 değeri 4 bayt olarak little endian biçimde görüldü (`0A 00 00 00`).

## 6. Ayrı Assembly Dosyası: Selection Sort Örneği

### 6.1 Projenin yapısı

İkinci örnek (`sort` çözümü) üç dosyadan oluşur (ekrandan, 01:25:00): ana programın bulunduğu `mainer.cpp`, selection sort'un C ile yazıldığı `SelSortInC.cpp` ve aynı işin assembly ile yazıldığı `SelSortInAsm.asm`. Amaç, aynı işi yapan C ve assembly kodları arasında performans farkı olup olmadığını incelemektir.

Ana programda:

- Dışarıdan kullanılacak assembly fonksiyonu için prototip tanımlanır: dönüş değeri olmayan (`void`), biri int işaretçisi, biri int olan iki parametre alan `SelSortASM`. Hoca bunun dış kaynaklı ve C çağırma kuralına uygun (`extern`) olduğunun belirtilmesi gerektiğini söyledi.
- main dışında tanımlanan C fonksiyonu `SelSortC` için de prototip yazılır.
- 100 000 elemanlı bir dizi oluşturulur, fonksiyona giriş ve çıkış anlarındaki saat değerleri (`clock()`) tutulup farkı ekrana yazdırılır. Sıralamanın doğruluğunu görmek için dizinin ilk ve son elemanları da yazdırılır.

<!-- BELİRSİZ: mainer.cpp'deki prototip satırının tam metni karelerde görünmüyor; altyazıdan extern ve C çağırma kuralı bildirimi olduğu anlaşılıyor. -->

### 6.2 C sürümü

Ekrandaki kod (ekrandan, 01:25:00):

```c
void SelSortC(int *sdizi, int boyut){
    int i, j, tmp, max;
    for (i = 0; i < boyut - 1; i++){
        max = i;
        for (j = i + 1; j < boyut; j++)
            if (sdizi[j] > sdizi[max])
                max = j;
        tmp = sdizi[max];
        sdizi[max] = sdizi[i];
        sdizi[i] = tmp;
    }
}
```

Selection sort her adımda dizinin kalanındaki en büyük elemanı bulup sıradaki baş indise yazar. İç içe iki döngü olduğundan karmaşıklık $O(n^2)$'dir. Sonuç büyükten küçüğe sıralı bir dizidir.

Release modda, x86 (32 bit) olarak C sürümü çalıştırıldığında yaklaşık 14,66 saniye sürdü ve dizinin büyükten küçüğe sıralandığı görüldü.

### 6.3 Assembly sürümü: tanımlar

Assembly dosyasının başı (ekrandan, 01:40:00):

```asm
.586

PUBLIC _SelSortASM

_CODE SEGMENT dword public 'CODE' use32
ASSUME CS:_CODE

_SelSortASM PROC NEAR

        PUSH EBP
        PUSH ECX
        PUSH EDI
        PUSH ESI
        PUSH EAX
        PUSH EBX
        PUSH EDX

        MOV EBP, ESP
```

Tanımlar MASM uyumludur ama farklı bir yapıdadır:

- Bir kod segmenti tanımlanır. Fonksiyon dışarıya kullandırılacağı için `PUBLIC` ile bildirilir; böylece main ile birlikte linklenirken dışarıdan kullanılacağı bilinir.
- Kullanılan kod segmenti main ile aynıdır (segment birleştirme). Bu yüzden fonksiyon farklı bir dosyada olsa bile NEAR tipinde çağrılabilir.
- C tarafında çağrılan ad `SelSortASM` iken assembly dosyasında tanımın başında alt çizgi olmalıdır: `_SelSortASM`. Hoca bunu Visual Studio tarafındaki çağırma kuralının bir gereği olarak açıkladı. Kod segmentinin etiketi de alt çizgiyle (`_CODE`) verilir, bitişi de aynı adla yapılır.

## 7. Çağırma Kuralları (Calling Conventions)

Hoca, C'den assembly'ye parametrelerin nereden aktarıldığı sorusuyla çağırma kurallarına geçti. Dönem içinde assembly tarafında yığından parametre aktarıp yığından döndürme, yazmaçtan aktarıp yazmaçtan döndürme, yığından aktarıp yazmaçtan döndürme gibi farklı versiyonlar elle uygulanmıştı. C, Pascal gibi dillerde ve farklı işletim sistemlerinde bunun bir standardı vardır ve yazılan programlar bu standarda uymak zorundadır. Bu standarda calling convention (çağırma kuralı) denir.

Hoca Wikipedia'daki "x86 calling conventions" makalesindeki tabloyu gösterdi (ekrandan, 01:30:00). Tabloda her kural için parametrelerin aktarıldığı yazmaçlar, yığına aktarma sırası ve yığını kimin temizlediği yazar:

- **Sıra:** LTR (left to right) soldan sağa demektir. Örneğin Turbo C'de (16 bit) parametreler AX, DX, BX yazmaçlarıyla soldan sağa aktarılır: üç parametreli bir fonksiyonda ilk (en soldaki) parametre AX'te, ikincisi DX'te, üçüncüsü BX'te hazır olarak alt fonksiyona girilir. RTL (right to left) ise sağdan sola demektir.
- **Yığın temizliği:** Dönem içinde yığına iki parametre atılıp tek parametre döndürülen durumda yığında bir çöp değer kalıyordu ve bunu alt yordam ya da ana yordam kaldırabiliyordu. Tabloda "Callee" yazıyorsa çağrılan fonksiyon, "Caller" yazıyorsa çağıran (ana yordam) yığını temizlemekle görevlidir.
- **Vektör yazmaçları:** Tamsayı parametreler için genel amaçlı yazmaçlar, float tipi parametreler için XMM, YMM, ZMM multimedya vektör yazmaçları kullanılır. X, Y ve Z arasında her seferinde iki kat kapasite farkı vardır.
- **Linux 64 bit (System V AMD64 ABI):** Tamsayı parametrelerin ilk 6'sı RDI, RSI, RDX, RCX, R8, R9 yazmaçlarıyla aktarılır, kalanlar yığından. Örneğin 15 parametre aktarılırsa ilk 6'sı bu yazmaçlarda, geri kalanı yığında olur. Float parametreler için XMM0-7 kullanılır.

Ekrandaki tablodan bazı satırlar (ekrandan, 01:30:00):

| Kural | Kullanan | Parametre yazmaçları | Yığın sırası | Temizleyen |
|---|---|---|---|---|
| cdecl | Microsoft | (yok) | RTL (C) | Caller |
| stdcall | Microsoft | (yok) | RTL (C) | Callee |
| fastcall | Microsoft | ECX, EDX | RTL (C) | Callee |
| register | Delphi ve Free Pascal | EAX, EDX, ECX | LTR (Pascal) | Callee |
| Microsoft x64 | Windows (Visual C++, GCC, ...) | RCX/XMM0, RDX/XMM1, R8/XMM2, R9/XMM3 | RTL (C) | Caller |
| System V AMD64 ABI | Solaris, Linux, BSD, OS X | RDI, RSI, RDX, RCX, R8, R9, [XYZ]MM0–7 | RTL (C) | Caller |

> **Ek bilgi (derste anlatılmadı):** Tablodaki "RTL (C)" ifadesi, parametrelerin yığına sağdan sola atıldığını, yani ilk parametrenin yığının en üstünde (en düşük adreste) kaldığını belirtir. C'nin `printf` gibi değişken sayıda parametre alan fonksiyonları bu sayede ilk parametreyi her zaman aynı ofsette bulabilir.

Hoca derste fonksiyonun içine breakpoint koyup Release modda parametrelerin hangi yazmaçta ya da yığının neresinde olduğunu bulmaya çalıştı. 100 000'in hex karşılığını (186A0H) yazmaçlarda ve yığında aradı ama bulamadı. Sonunda bu örnekte parametrelerin yığından aktarıldığını söyledi.

> **Ders sonrası not:** Ekrandaki Call Stack penceresinde "[Inline Frame] SelSortC" yazıyor ve disassembly'de dizi boyutu `cmp edx, 186A0h` gibi bir sabit olarak geçiyor (ekrandan, 01:35:00). Yani Release modda derleyici `SelSortC`'yi main'in içine gömmüştü; parametre aktarımı hiç yapılmadığı için değerler yazmaçlarda ya da yığında bulunamadı. Hoca bunu dersin ilerleyen kısmında gösterdi (bkz. Bölüm 9).

## 8. Assembly Yordamında Yığından Parametre Okuma

### 8.1 Yığının düzeni

Assembly sürümü (`_SelSortASM`) Release modda çalıştırıldığında C sürümüne göre 3-4 kat kadar hızlı çıktı. Hoca, optimizasyon bayraklarının hepsinin uygun şekilde açılmamış olabileceğini ayrı bir not olarak ekledi.

Parametreler yığından geldiği için BP (burada EBP) sabit referans olarak kullanılır. Kodda ECX, EDI, ESI, EAX, EBX ve EDX geçici amaçlarla kullanıldığı için bunlar da yığına atılır. Çağırma kuralı sağdan soladır (RTL): yığına önce sağdaki parametre (n), sonra soldaki (dizi adresi) atılır. Fonksiyon NEAR tipinde olduğu için çağrıda yığına yalnız dönüş IP'si atılır.

`MOV EBP, ESP` satırından sonra yığının durumu (ekrandan, 01:45:00; üstten alta, düşük adresten yükseğe):

```text
EBP+0   EDX
EBP+4   EBX
EBP+8   EAX
EBP+12  ESI
EBP+16  EDI
EBP+20  ECX
EBP+24  EBP (eski)
EBP+28  ANA IP (dönüş adresi)
EBP+32  dizi (adres)
EBP+36  n
```

Her değer 4 bayt yer kaplar. EBP'den itibaren 7 yazmaç ve dönüş IP'si geçilince dizi adresi 32 ofset, n de 36 ofset ötededir. n, döngü için ECX'e; dizi adresi dolaylı adresleme yapılabilsin diye EDI'ye okunur.

### 8.2 Kodun gövdesi

Ekranda görünen gövde (ekrandan, 01:45:00):

```asm
        DEC ECX
        MOV EAX, EDI

dis_don:MOV EBX, ECX
        MOV ESI, EAX
        MOV EDI, EAX
        MOV EDX, [EDI]
ic_don: ADD ESI, 4
        CMP [ESI], EDX
        JGE ATLA
        MOV EDI, ESI
        MOV EDX, [EDI]
ATLA:   DEC EBX
        JNZ ic_don
        MOV EDX, [ESI]
        XCHG EDX, [EDI]
        MOV [ESI], EDX
        LOOP dis_don
```

<!-- BELİRSİZ: 20-22. satırlar (büyük olasılıkla dizi adresini ve n'i [EBP+32] ve [EBP+36]'dan okuyan MOV'lar) ile 40. satırdan sonrası (yazmaçların POP edilmesi ve RET) karelerde görünmüyor. -->

Hocanın anlatımı:

- Dış döngü, C'deki gibi eleman sayısının bir eksiği kadar döner (`DEC ECX`) ve `LOOP` ile kurulur. İç döngü ise karşılaştırma ve koşullu sıçramayla (`DEC EBX`, `JNZ`) kurulur.
- EBX iç döngünün adedini tutar: dizinin geri kalanı o anki ECX kadar elemandır (C'de j, i+1'den boyuta kadar gider).
- İç döngüde seçilen elemanın değeri EDX'te tutulur, adresi de saklanır; iç döngüden sonra bu eleman `XCHG` ile değiş tokuş edilerek yerine yazılır.

> **Ders sonrası not:** Hoca ESI'nin C'deki `i`'ye (en büyük elemanın yazılacağı göz), EDI'nin `j`'ye (tarayan işaretçi) karşılık geldiğini söyledi. Ekrandaki kodda ise roller terstir: ESI her adımda 4 artarak dizinin geri kalanını tarar, EDI o ana kadar seçilen elemanın adresini tutar. `CMP [ESI], EDX` / `JGE ATLA` yüzünden yalnız daha küçük bir eleman bulununca seçim değişir, yani seçilen eleman en küçüktür ve iç döngü sonunda kalan aralığın son gözüne (ESI) yazılır. Aralık her dış adımda bir küçüldüğü için sonuç yine büyükten küçüğe sıralı dizidir. Görünen satırlar, eksik satırlar yukarıdaki gibi varsayılarak python ile benzetildi ve rastgele dizilerde büyükten küçüğe sıralama verdi.

## 9. Release ve Debug Derlemelerinde Derleyicinin Ürettiği Kod

Hoca C sürümünün derleyici tarafından üretilen assembly karşılığını, kendi yazdığı assembly ile karşılaştırmak için Release modda disassembly'ye baktı (ekrandan, 01:50:00):

- Derleyici `cmovle` gibi karşılaştırmalı MOV (conditional move) komutları kullanmıştı; bu komutlar 8086'da yoktur.
- Döngüler LOOP ile değil, iki ayrı `cmp` ve koşullu sıçramayla (`jge`, `jl`) kurulmuştu; hiç LOOP komutu yoktu. Dizi boyutu `cmp edx, 186A0h` gibi doğrudan sabit olarak geçiyordu.
- Çeşitli seviyelerde optimizasyon yapıldığı için kod anlamsal sırayla değil, optimize edilmiş haliyle üretilir; bu yüzden takip etmek zordur.

Hoca ardından assembly fonksiyonunun çağrıldığı yere baktı. Release modda `SelSortC` çağrısı hiç görünmüyordu: derleyici çağrıyı ortadan kaldırıp fonksiyonun içini main'e gömmüştü. Debug modda ise çağrı açıkça görülüyordu (ekrandan, 01:55:00):

```text
    SelSortASM(dizi, n);
lea   eax,[esp+38h]
push  186A0h
push  eax
call  _SelSortASM (09F1000h)
```

Önce n (100 000 = 186A0H), sonra dizinin adresi yığına atılır; bu sağdan sola (RTL) kurala uyar. Debug modda C sürümünün iç içe döngüleri de yine iki karşılaştırmayla (`cmp`) kuruluyordu; Release'deki optimize koddan da bu beklenirdi.

> **Hocanın vurgusu:** Release modda derleyici optimizasyonu öyle bir seviyededir ki CALL işlemini bile ortadan kaldırıp fonksiyonu main'in içine taşıyabilir. Bu örnekleri hem Debug hem Release modda, hem ana program hem alt program tarafında inceleyerek siz de deneyin.

## 10. Linux'ta GCC ve NASM ile C-Assembly Bağlantısı

### 10.1 Araçlar

Linux'ta GCC derleyicisi ve NASM assembler'ı kurulmalıdır. Linux'ta birden fazla assembler vardır; NASM, şimdiye kadar görülen MASM sözdizimine yakın olduğu için seçilir. Hoca bu kısmı Windows'tan dosyaları açarak anlattı. Örnek klasörlerde `main.c`, assembly dosyası, `makefile` ve `README.md` bulunuyordu (ekrandan, 02:00:00).

### 10.2 Makefile

Makefile derleme adımlarını toplu hale getirir: normalde komut satırında ayrı ayrı çalıştırılacak iki satır, `make` komutuyla bir seferde yürütülür:

1. NASM ile assembly dosyası (`topla.asm`) derlenir; biçim olarak `elf32` ya da `elf64` seçilir. Çıktı `topla.o` obje dosyasıdır.
2. GCC ile `main.c` ve `topla.o` birlikte derlenip linklenir; `topla` adlı çalıştırılabilir dosya oluşur.

Ardından terminalden `./topla` ile çalıştırılır.

<!-- BELİRSİZ: makefile'ın tam satırları karelerde görünmüyor. -->

> **Ek bilgi (derste anlatılmadı):** Bu iki adım büyük olasılıkla `nasm -f elf32 topla.asm -o topla.o` ve `gcc -m32 main.c topla.o -o topla` biçimindedir; 64 bitte `-f elf64` kullanılır ve `-m32` bayrağı yazılmaz.

### 10.3 32 bit sürüm

`main.c`'de dışarıdan tanımlanan `Topla` fonksiyonu bir int işaretçisi (dizinin adresi) ve bir int (eleman sayısı) alır ve int döndürür; uygun çağırma kuralıyla çağrılır.

Assembly tarafı (ekrandan, 02:05:00):

```asm
global Topla

Topla:
        PUSH EBP
        PUSH EDI
        PUSH ECX
        MOV  EBP, ESP

        MOV  EDI, [EBP+16]
        MOV  ECX, [EBP+20]
        XOR  EAX, EAX
L1:     ADD  EAX, [EDI]
        ADD  EDI, 4
        LOOP L1

        POP  ECX
        POP  EDI
        POP  EBP
        RET
```

- Dosyadaki bölüm tanımları (`section .data`, `section .text`) segment tanımlarına karşılık gelir; kodun kendine ait bir veri segmenti var diye düşünülebilir.
- `Topla` dışarıya kullandırılacağı için NASM'de `global` olarak tanımlanır.
- 32 bitte parametreler yine yığından gelir. İçeride EDI (dizinin sıradaki elemanı) ve ECX (döngü) kullanılır, bu yüzden yığına atılır; EBP sabit referans içindir.

Yığın hesabı: çağrıda yığında önce n, üstünde dizi adresi, üstünde dönüş IP'si vardır. Hoca önce FAR çağrı varsayıp dönüş CS'sini de ekledi (ECX, EDI, EBP, ANA IP, ANA CS, dizi, n), ama ofsetler koddakiyle tutmadı. NEAR çağrıya göre yeniden saydı ve tuttu:

```text
EBP+0   ECX
EBP+4   EDI
EBP+8   EBP (eski)
EBP+12  ANA IP
EBP+16  dizi
EBP+20  n
```

Hoca, çağrının NEAR mı FAR mı olduğunun kesin olarak ancak kod segmentinin main tarafıyla uyumuna bakılarak anlaşılabileceğini, burada deneme yanılmayla bulunduğunu belirtti.

Döngü her seferinde EDI'nin gösterdiği dizi gözündeki değeri EAX'e ekler. Elemanlar 1'den n'e kadar sayılar olduğu için toplam $n(n+1)/2$'dir; int tipinde n için 32 biti taşma olabilir ve burada bunun kontrolü yapılmamıştır. Dönüş değeri EAX'tedir: fonksiyon int döndürdüğü için dönüş değeri EAX'te kalır, C tarafında bir değişkene atanıp yazdırılır.

> **Hocanın vurgusu:** Parametre aktarımında yazmaç kullanılmadı (yığından geldi), dönüş değeri ise EAX'tedir. Önemli bir nokta.

### 10.4 64 bit sürüm

Makefile'da bu kez biçim 64 bit olarak ayarlanır. Assembly dosyasında dolaylı adreslemede RDI, RSI, RBX gibi 64 bitlik yazmaçlar kullanılmalıdır. `main.c`'de fark yoktur: `Topla` yine bir int işaretçisi ve bir int alır, int döndürür ve linkleme aşamasında bulunabilmesi için dış fonksiyon olarak bildirilir.

Assembly tarafı (ekrandan, 02:10:00):

```asm
section .data

section .text

global Topla

Topla:
    PUSH RCX
; for the 64-bit assembler, the first 6 parameters are passed by register
; and the rest are placed on the Stack
; While for the x86 assembler, all the parameters are placed on the Stack.
; RDI   1st argument
; RSI   2nd argument
; RDX   3rd argument
; RCX   4th argument
; R8    5th argument
; R9    6th argument
    MOV  RCX, RSI
    XOR  RAX, RAX
L1: ADD  RAX, [RDI]
    ADD  RDI, 4
    ...
```

<!-- BELİRSİZ: 22. satırdan sonrası karede görünmüyor; altyazıya göre LOOP L1, POP RCX ve RET ile biter. -->

- Visual Studio'da fonksiyon adının başına alt çizgi gerekiyordu; Linux'ta GCC ile adın C tarafındakiyle aynı olması gerekir.
- İlk parametre (dizi adresi) RDI'da, ikinci parametre (n) RSI'dadır.
- Döngü LOOP ile yapılacağı için sayaç RCX'e alınır; RCX bozulmasın diye girişte PUSH, çıkışta POP edilir. Diğer yazmaçların bozulması bu örnekte önemli değildir.
- RDI'nin gösterdiği adresin içeriği RAX'e toplanır, RDI her adımda 4 artar (int 4 bayt). RAX kullanıldığı için en büyük toplam $n(n+1)/2$ RAX'te birikebilir, taşma olmaz.
- Dönüş değeri RAX'tedir.

> **Ders sonrası not:** Hoca RAX kullanıldığı için taşma sorunu olmadığını söyledi. Ancak `ADD RAX, [RDI]` bellekten 8 bayt okur, int ise 4 bayttır; her adımda sonraki elemanın 4 baytı da RAX'in yüksek yarısına eklenir ve son adımda dizinin sonundan 4 bayt fazla okunur. Sonuç büyük olasılıkla yalnız dönüş değeri int'e (EAX'e) kesildiği için doğru çıkar; toplam da yine 32 bitle sınırlı kalır. 4 baytlık okuma için `movsxd rdx, dword [rdi]` gibi genişleten bir okuma daha doğrudur.

Hoca, `.lst` gibi listeleme dosyalarının oluşması için NASM'e bir parametre vermek gerekebileceğini ama o an hatırlamadığını söyledi; derlemeyi Linux'ta yapıp oluşan dosyaları incelemeyi önerdi.

## 11. GDB ile Hata Ayıklama

8086'daki DEBUG'a benzer şekilde Linux'ta derlenmiş kodu adım adım yürütmek için GDB kullanılır. Hoca kitaptaki tabloyu gösterdi (ekrandan, 02:15:00; "Tablo 25-26: Örnek 15-5 için GDB ile debug adımları"):

| Adım | Açıklama | Komut |
|---|---|---|
| 1 | Komut satırından GDB'nin topla programı için başlatılması | `gdb topla` |
| 2 | main fonksiyon girişine kesme noktası eklenmesi | `break main` |
| 3 | main girişine kadar programın çalıştırılması | `run` |
| 4 | Intel anımsatıcı kullanımı | `set disassembly-flavor intel` |
| 5 | main'in disassembly'si | `disassemble main` |

- `gdb topla` çalıştırılabilir dosyanın bulunduğu klasörde (current working directory) yazılır; GDB içinde olunduğu `(gdb)` belirteciyle anlaşılır.
- Her çalıştırılabilir C programında main bulunduğu için `break main` ile main etiketine kesme noktası konur; `run` ile oraya kadar çalıştırılır.
- Varsayılan disassembly, alışık olunmayan farklı bir sözdizimiyle (AT&T) görünür; `set disassembly-flavor intel` ile Intel/MASM'e alışık olunan biçime geçilir.
- `disassemble main`, main etiketinden itibaren belirli bir alanı disassembly eder. Baştaki komutlar ana fonksiyonun işletim sistemine dönüşüyle ilgili başlangıç işlemleridir.
- `x/i $rip` ile instruction pointer'ın gösterdiği sıradaki komut görülür. x komutu main etiketinden sonraki alanı bayt bayt dökmek için de kullanılır (hoca ekranda ilk 8 baytın, sonra 8. ve 9. baytların döküldüğünü gösterdi).
- `info registers` bütün yazmaç içeriklerini döker; tek bir yazmaç için `print $eax` gibi bir komut kullanılır. Çıktıdaki `$2` gibi ifade içerikle ilgili değildir, kaçıncı izleme olduğunu gösterir (bir nevi watch numarası).

Kitaptaki diğer komutlar (ekrandan, 02:20:00):

| Komut | İşlev |
|---|---|
| `info break` | Kesme noktalarını listeler |
| `run` | Hataya veya kesme noktasına kadar kodu koşturur |
| `continue` | Bir sonraki hataya veya kesme noktasına kadar koşturmaya devam eder |
| `finish` | Mevcut fonksiyon sonlanana kadar kodu koşturur |
| `step` | Bir sonraki kod satırını koşturur |
| `stepi` | Bir sonraki makine komutunu koşturur |
| `step N` | Sonraki N adet kod satırını koşturur |
| `next` | Fonksiyon içine girmeden bir sonraki kod satırını koşturur |
| `nexti` | Fonksiyon içine girmeden bir sonraki makine komutunu koşturur |
| `print/(fmt) var` | var değişkeninin içeriğini fmt biçiminde yazdırır |
| `x/(num)(frmt)(size) addr` | addr'de yerleşik num adet, size boyutlu içerikleri frmt biçiminde gösterir |
| `backtrace` | Yığın izini yazdırır |
| `disassemble fn` | fn fonksiyonunun anımsatıcı karşılıklarını gösterir |
| `up` / `down` | Yığında bir üst / alt seviyeye geçer |
| `kill` | Mevcut hata ayıklama oturumunu sonlandırır |
| `quit` | GDB'den çıkar |

Komut adlarındaki ilk harf (kitapta köşeli parantezle gösterilir) kısaltma olarak kullanılabilir: `b`, `r`, `c`, `s`, `n`, `p`, `x` gibi.

Hoca, hem Visual Studio'da hem Linux'ta GCC ve NASM ile bu örnekleri derleyip çıkan assembly sonuçlarını incelemeyi ve sistemin kabaca nasıl çalıştığını irdelemeyi tavsiye etti.

## Örnek Sorular

**Soru 1** (ekrandan, 00:10:00): AL, AH, BL ve CL'yi toplayıp sonucu DX'te saklayan komutları yazınız.

> **Çözüm (derste verildi, 00:15:00):** Dört 8 bitlik işaretsiz değerin toplamı en çok 1020'dir, 16 bite sığar.
>
> ```asm
> XOR DX, DX
> ADD DL, AL
> ADD DL, AH
> ADC DH, 0
> ADD DL, BL
> ADC DH, 0
> ADD DL, CL
> ADC DH, 0
> ```
>
> Sağlama: dördü de 255 iken DX = 03FCH (1020).

**Soru 2** (ekrandan, 00:20:00): DL'de tutulan sayının küpünü bulan assembly komutlarını yazınız.

> **Çözüm (derste verildi, 00:21:00):** $255^3$ 32 bite sığar, sonuç DX:AX'te tutulur.
>
> ```asm
> MOV AL, DL
> MUL DL        ; AX <- DL^2
> XOR DH, DH    ; DX = DL
> MUL DX        ; DX:AX <- DL^3
> ```
>
> Sağlama: DL = 255 için önce AX = FE01H, sonra DX:AX = 00FD02FFH. İşaretli kabulde DL işaret korunarak DX'e genişletilir ve `IMUL` kullanılır.

**Soru 3** (ekrandan, 00:25:00): Seed değeri kod segmentinin 23. ofsetindeki word olmak üzere, sonraki rastgele sayıyı $(A \cdot seed + C) \bmod M$ ile hesaplayıp 8 bitlik SONRAKI değişkenine yazan kodu yazınız.

<!-- BELİRSİZ: Sorunun tam metni ekranda görünmüyor; yalnız cevap anahtarındaki kod ve açıklamaları görünüyor. A_SAY, C_SAY, M_SAY ve SONRAKI adları koddan alındı. -->

> **Çözüm (derste verildi, 00:25:00):**
>
> ```asm
> MOV AX, CODESG
> MOV ES, AX
> MOV AX, ES:[23]   ; seed
> MUL A_SAY         ; DX:AX <- AX * A_SAY
> ADD AX, C_SAY
> ADC DX, 0         ; DX:AX <- DX:AX + C_SAY
> DIV M_SAY         ; DX <- kalan, AX <- bolum
> MOV SONRAKI, DL   ; 16 bitlik sayinin dusuk baytı
> ```
>
> Önce çarpma ve toplama, sonra bölme yapılır. 8 bitlik sonuç için kalanın düşük baytı alınabilir ya da 256'ya göre mod alınabilir.

**Soru 4** (derste sözlü, 00:36:09): Inline assembly örneğinde dizi elemanları neden 8 hex basamak (`%08x`) olarak yazdırılıyor?

> **Çözüm (derste verildi):** `sizeof(int)` = 4 bayt = 32 bit; her hex basamak 4 bit olduğundan 32 bit 8 hex basamakla gösterilir.

**Soru 5** (derste sözlü, 01:40:59; ekrandan, 01:45:00): `_SelSortASM` girişinde EBP, ECX, EDI, ESI, EAX, EBX, EDX sırayla yığına atılıp `MOV EBP, ESP` yapılıyor. Fonksiyon NEAR ve parametreler sağdan sola aktarılıyorsa dizi adresi ve n hangi ofsetlerdedir?

> **Çözüm (derste verildi):** 7 yazmaç × 4 bayt = 28 bayt (EBP+0 ... EBP+24), dönüş IP'si EBP+28'de. Dizi adresi [EBP+32], n [EBP+36].

**Soru 6** (derste sözlü, 02:04:01; ekrandan, 02:05:00): Linux 32 bit `Topla` fonksiyonunda girişte EBP, EDI, ECX yığına atılıp `MOV EBP, ESP` yapılıyor. Dizi adresi ve n hangi ofsetlerdedir?

> **Çözüm (derste verildi):** NEAR çağrıda ECX [EBP], EDI [EBP+4], eski EBP [EBP+8], dönüş IP'si [EBP+12]; dizi [EBP+16], n [EBP+20]. FAR varsayılsaydı dönüş CS'si de araya girer ve ofsetler 4 kayardı; koddaki 16 ve 20 ofsetleri NEAR çağrıya uyar.

## Dersin Toparlaması

Bu derste önce ödevdeki üç kodlama sorusu üzerinden assembly'de sık yapılan hatalar ele alındı: yazmacın yüksek yarısının belirsiz bırakılması, ardışık çarpma ve bölmede sıranın önemi ve işlemden önce boyut analizi yapılması. Toplamı DX'te biriktirme, küp alma ve rastgele sayı üretme örneklerinde DX:AX'in sanal 32 bitlik yazmaç gibi kullanılması ve sonucun en büyük değerlerle sağlanması gösterildi.

Ardından yüksek seviyeli dil ile assembly bağlantısının iki yolu işlendi. Visual Studio'da inline assembly (`__asm { }`) ile bir int dizisinin bitleri `shr`/`rcl` ile ters çevrildi; 32 bitlik kod için x86 derleme, ESI/EDI/EBX ile dolaylı adresleme ve ECX ile döngü kuralları vurgulandı. Ayrı bir `.asm` dosyasında yazılan selection sort, C sürümüyle karşılaştırıldı; MASM tarafında alt çizgili ad, `PUBLIC` bildirimi ve segment birleştirme, C tarafında extern prototip gerektiği görüldü. Çağırma kuralları (cdecl'de sağdan sola yığın aktarımı ve EAX'te dönüş, System V AMD64'te RDI, RSI, RDX, RCX, R8, R9) ve yığındaki parametre ofsetlerinin hesaplanması örneklerle gösterildi. Release modda derleyicinin fonksiyonu inline ettiği, LOOP yerine CMP/Jcc ve `cmovle` kullandığı görüldü. Son olarak Linux'ta NASM ve GCC ile 32 ve 64 bitlik `Topla` örnekleri ve GDB ile hata ayıklama komutları anlatıldı. Hoca dönemin genel tekrarı için parametre aktarım yöntemlerini, segment birleştirmeyi ve EXE ile COM farkını karşılaştırarak gözden geçirmeyi; dersteki bütün örnekleri ezberden değil, emu8086 ya da DOSBox gibi araçlarda derleyip çalıştırarak kendi başına çözmeyi önerdi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
