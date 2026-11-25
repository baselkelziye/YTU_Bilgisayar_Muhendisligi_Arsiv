# Ders 16 Genişletilmiş Notu: Yüksek Seviyeli Dillerle Assembly Kullanımı (C + NASM, C + MASM, Satır İçi Assembly)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ders Öncesi Sorular: LOOP'tan Sonra Gelen Etiket
- 2. Yüksek Seviyeli Dillerle Assembly
- 3. Örnek 1: Linux'ta C'den NASM Yordamı Çağırma
- 4. C'nin Yığın Üzerinden Parametre Aktarması
- 5. Derleme, Bağlama ve Çalıştırma (Linux)
- 6. Segmentation Fault ve Düzeltilmesi
- 7. MOV AX, 0ABCDh Sorusu
- 8. Örnek 2: Visual Studio'da C ve MASM ile Selection Sort
- 9. Ayrıştırılmış Kod ile Adım Adım İzleme
- 10. Örnek 3: Satır İçi Assembly ile Bit Aynalama
- 11. Dersin Kapanışı
- Örnek Sorular

## 1. Ders Öncesi Sorular: LOOP'tan Sonra Gelen Etiket

Derse öğrencilerin ödevle ilgili soruları ile başlandı. Akademik kısmı şudur: makine kodundan geri çevrilen (disassemble edilen) bir programda `LOOP 9` gibi bir satır görülürse, buradaki sayı bir etikettir. `LOOP` komutundan sonra her zaman bir etiket gelir ve etiket, programdaki bir satırın ofset adresidir. Kaynak kodda satıra bir isim verilir; ama etiket isimleri nesne kodu oluşurken kaybolur, makine kodunda yalnız o satırın ofset adresi kalır. Bu yüzden geri çevrilmiş kodda etiket adı değil, sayısal bir ofset görülür.

Hoca, bir programın akış diyagramı çizilirken `PUSH`, `POP` gibi alt seviye komutların yazılmaması, programın yaptığı işin üst seviye kavramlarla anlatılması gerektiğini de belirtti.

## 2. Yüksek Seviyeli Dillerle Assembly

Yüksek seviyeli dillerden kasıt C, Pascal, Java, Python gibi dillerdir. Bu dillerle assembly birlikte kullanılabilir. Kitapta hem Pascal hem C örnekleri vardır; konu kapsamlı olduğu için derste yalnız C üzerinden örnek verildi.

Derste üç yöntem gösterildi:

- Linux (Ubuntu) tarafında **NASM** (Netwide Assembler) ile yazılan bir yordamı C'den çağırmak. Amaç, bu işlerin yalnız Windows'ta olmadığını ve NASM sözdizimini görmekti. Microsoft tarafında MASM (Microsoft Macro Assembler) kullanılır.
- Windows'ta Visual Studio ile, C kodundan MASM ile yazılmış harici bir yordamı çağırmak.
- C kodunun içine doğrudan satır içi (inline) assembly yazmak.

Her örnekte temel fikir aynıdır: C'de basit bir program akışı yazılır ve bu akışın içinden, sanki bir C fonksiyonuymuş gibi tanımlanan, ama gerçekte assembly ile yazılmış bir yordam çağrılır.

## 3. Örnek 1: Linux'ta C'den NASM Yordamı Çağırma

### 3.1 Problem

Kullanıcıdan bir `n` değeri okunur. 1'den `n`'e kadar sayılar bir diziye yerleştirilir. Dizinin adresi ve eleman sayısı assembly yordamına gönderilir. Yordam dizinin bütün elemanlarını toplar ve sonucu döndürür; C tarafı sonucu ekrana yazar.

### 3.2 C tarafı

Hoca önce bir terminal açıp bir çalışma klasörü oluşturdu ve gedit'te C dosyasını yazdı. `n = 10` girilirse dizinin 0. elemanı $0+1 = 1$, $n-1$. (9.) elemanı 10 olur. Dizinin adresi C'de dizinin adı yazılarak verilir. Son hâli (ekrandan, 00:30:00):

```c
#include <stdio.h>

extern int Topla(int *, int);

int main(){
    int i, n, top;
    printf("n: ");
    scanf("%d", &n);
    int dizi[n];

    for(i = 0; i < n; i++)
        dizi[i] = i + 1;

    top = Topla(dizi, n);

    printf("Toplam: %d\n", top);

    return 0;
}
```

- Fonksiyon geriye bir tamsayı döndürdüğü için dönüş tipi `int`'tir. İlk parametre dizinin adresi olduğu için `int *`, ikincisi eleman sayısı olduğu için `int`'tir.
- `Topla`, eklenen kütüphanelerde ya da bu dosyanın devamında bulunmadığı için başına `extern` yazılır (ekrandan, 00:20:00). `Topla` bir C fonksiyonu olarak da yazılabilirdi; burada assembly yordamı olarak yazılıyor.
- `printf("n: ");` satırı ilk çalıştırmadan sonra eklendi: program ilk denemede hiçbir şey yazmadan beklediği için kullanıcının neyin istendiğini anlaması amacıyla eklendi (ekrandan, 00:15:00 ve 00:30:00 karşılaştırması).

Bu dosya, `main` içerdiği için gcc ile derlenip denendi: makinede 32 bitlik kütüphaneler ve NASM bulunmadığından `Topla`, aynı işi yapan bir C fonksiyonuyla değiştirilerek 64 bitte çalıştırıldı; `n = 10, 5, 7, 100, 99` için sırasıyla 55, 15, 28, 5050, 4950 çıktı.

### 3.3 NASM'de kesimler ve yordam tanımı

MASM'de bir program kod, veri ve yığın kesiminden (segment) oluşuyordu. NASM'de bunlara **section** denir ve sözdizimi biraz farklıdır:

- `section .data`: veri kesimi. Altına `DW`, `DB` ile değişken tanımlanabilir. Bu örnekte değişkene ihtiyaç yoktu; hoca yalnız göstermek için yazdı.
- `section .text`: kod kesimi. Kod buraya yazılır.
- `section .stack`: yığın kesimi.

**Soru:** Veri kesimi nerede bitiyor, `END` gibi bir şey yok mu? **Cevap:** `section .text`'e kadar olan her şey veri kesimidir; ondan sonra gelen her şey kod kesimidir.

MASM'de yordam `isim PROC FAR|NEAR` diye tanımlanıyordu. NASM'de yalnız yordamın adından sonra iki nokta konur (`Topla:`) ve gövdeye başlanır. Yordamın başka dosyadan kullanılabilmesi için dışa açılması gerekir: MASM'de ana yordamın bulunduğu dosyada `EXTRN`, harici yordamın bulunduğu dosyada `PUBLIC` yazılıyordu; NASM'de `PUBLIC` yerine **`global`** anahtar sözcüğü kullanılır. C tarafındaki `extern` de bunun karşılığıdır.

### 3.4 Yordamın kodu

Son (düzeltilmiş) hâli (ekrandan, 00:35:00):

```nasm
section .data

section .text

global Topla

Topla:
    PUSH EBP
    PUSH ECX
    PUSH ESI

    MOV EBP, ESP
    MOV ECX, [EBP+20]
    MOV ESI, [EBP+16]
    XOR EAX, EAX
L1: ADD EAX, [ESI]
    ADD ESI, 4
    LOOP L1

    POP ESI
    POP ECX
    POP EBP
    RET
```

Satır satır:

- `EBP` yığına atılır. `BP` 16 bitlik bir yazmaçtır; başına `E` gelince 32 bitlik sürümü olan `EBP` kullanılır. Bu kural bütün yazmaçlar için geçerlidir.
- Dizinin bütün elemanları döngüyle toplanacak; eleman sayısı `ECX`'e konacağı için `ECX` saklanır.
- Dizinin her elemanına erişmek için indis olarak `ESI` kullanılacağı için o da saklanır.
- `MOV EBP, ESP`: artık `EBP` yığının tepesini gösterir ve parametrelere ona göre erişilir.
- `ECX` ← eleman sayısı, `ESI` ← dizinin ilk elemanının adresi. Hoca bunu "sanki `ESI`'ye `LEA` ile adres yüklemişiz gibi" diye açıkladı.
- Sonuç `EAX` üzerinden döneceği için `EAX`, `XOR` ile sıfırlanır.
- `ADD EAX, [ESI]`: köşeli parantez, `ESI`'deki adresteki elemanı alır ve `EAX`'e ekler.
- `ADD ESI, 4`: bir sonraki elemana geçmek için 4 eklenir, çünkü dizi `int` tanımlıdır ve kullanılan mimaride `int` 32 bit, yani 4 byte'tır. Hoca boyutu `sizeof` ile öğrendiğini söyledi. Farklı bir mimaride `int` 16 ya da 64 bit olabilir. Dizi `short` tanımlansaydı her eleman 2 byte olur ve 2'şer, `char` tanımlansaydı 1'er artırılırdı.
- `LOOP L1` döngüyü kapatır. Saklanan yazmaçlar ters sırayla geri alınır ve `RET` ile dönülür.

Hoca, başlarındaki `E`'ler kaldırılırsa bunun şimdiye kadar yapılan örneklerle çok benzer, standart bir yordam olduğunu söyledi.

## 4. C'nin Yığın Üzerinden Parametre Aktarması

Hoca bu kısmın önemli olduğunu vurguladı. Daha önceki bir derste yordamlar arasında yığın üzerinden parametre aktarma anlatılmıştı; C de parametreleri yığın üzerinden aktarır.

> **Hocanın vurgusu:** Parametreler prototipteki sıraya göre **sağdan sola** yığına atılır. `Topla(dizi, n)` için önce `n`, sonra `dizi`nin adresi atılır. Fonksiyonun 30 parametresi de olsa en sağdaki ilk atılır.

Sonra `Topla` yordamına NEAR yordam gibi dallanılır; NEAR dallanmada dönüş ofseti (göreli konum) de yığına atılır. Bu örnekte 32 bitlik mimariyle çalışıldığı için yığın da 32 bittir: yığına atılan her eleman 4 byte'tır. 16 bitlik mimaride göreli konumlar $+2$, $+2$ diye sayılıyordu; burada $+4$, $+4$ diye sayılır.

Yordamın başında `EBP`, `ECX`, `ESI` de atıldıktan ve `MOV EBP, ESP` yapıldıktan sonra yığın şöyledir (python ile kontrol edildi):

```text
[EBP+20]  n               (ilk atılan: en sağdaki parametre)
[EBP+16]  dizinin adresi
[EBP+12]  dönüş ofseti    (CALL)
[EBP+8]   eski EBP
[EBP+4]   ECX
[EBP+0]   ESI             <- ESP = EBP
```

> **Hocanın vurgusu:** Sonuç `EAX` (akümülatör) üzerinden döndürülür. Yordamdan `RET` ile dönmeden önce sonucun `EAX`'te olduğundan emin olunmalıdır.

C'de bir fonksiyonun `return a, b, c` gibi birden fazla değer döndürememesinin nedeni de budur: alt tarafta dönüş yalnız `EAX` üzerinden olur. Birden fazla değer döndürmek gerekirse değerler bir alana (dizi, matris) yerleştirilir ve o alanın adresi döndürülür. 32 bitlik mimaride değişkenin, dizinin ya da matrisin boyutu ne olursa olsun adresi 32 bittir; adresi ve uzunluğu bilinen bir alanın geri kalanı programcının kontrolündedir.

> **Hocanın vurgusu:** C, yığına kendi attığı parametreleri çağrıdan sonra otomatik olarak kendisi temizler. Önceki derslerde yığından parametre alan yordamlar `RET 4` gibi bir sayıyla dönüyordu; C'den çağrılan yordamda `RET 8` gibi bir şey yazılması beklenmez, yazılırsa sorun çıkar.

## 5. Derleme, Bağlama ve Çalıştırma (Linux)

MASM'de iki ayrı `.asm` dosyası ayrı ayrı derlenip `.obj` dosyaları üretiliyor, sonra bu nesne kodları aralarına `+` konarak birlikte bağlanıyordu. Burada da aynısı yapılır: assembly kodu derlenip bir nesne kodu üretilir, C kodu da derlenir ve ikisi birleştirilerek çalıştırılabilir dosya oluşturulur.

- NASM kurulu değilse `sudo apt-get install` ile kurulabilir.
- `nasm -f elf32 -o ornek.o ornek.asm`: `-f` çıktı biçimini (ELF, yani bağlanabilir biçimin 32 bitlik sürümü), `-o` çıktı dosyasının adını belirtir, en sonda kaynak dosya yazılır. NASM ile 16, 32 ya da 64 bitlik sürümlere göre derleme yapılabilir. Sözdizimi hatası olsaydı NASM uyarı verirdi; uyarı yoksa sözdizimsel hata yoktur (mantıksal hata olabilir).
- `gcc -m32 -o asp ornek.o ornek.c`: gcc 32 bitlik çalışmaya zorlanır, çıktı adı verilir, nesne kodu ile C dosyası birlikte verilir.
- Çalıştırma: `./asp`.

<!-- BELİRSİZ: terminal komutları karede görünmedi; altyazıdan ("NAS-F1132", "-o", "örnek nokta o", "32 bitlik çalışmaya zorlayacak şekilde") kuruldu. Bayrakların yazımı ve dosya adları kesin değil. -->

### 5.1 Çalıştırılabilir dosya ve izin biti

Dev C++ gibi Windows ortamlarında derleme başarılıysa `.exe` uzantılı bir dosya üretilir. Linux'ta ise bir dosyanın çalıştırılabilir olması uzantısıyla ilgili değildir; dosyanın "çalıştırılabilir" olup olmadığını belirten bir **izin biti** vardır. Hoca dosya yöneticisinde dosyanın Özellikler → İzinler kısmından "programı çalıştırmaya izin ver" seçeneğini kaldırınca dosyanın yeşil renginin (çalıştırılabilir işareti) gittiğini, yeniden işaretleyince geri geldiğini gösterdi. Çalıştırılabilir dosya `./dosya_adi` yazılarak çalıştırılır.

## 6. Segmentation Fault ve Düzeltilmesi

İlk denemede yordam `n`'yi `[EBP+16]`'dan, dizinin adresini `[EBP+20]`'den alıyordu (ekrandan, 00:25:00). `n = 10` girilince program **segmentation fault** verdi. Bu hata, belleğin erişilmemesi gereken bir bölgesine erişildiğinde alınır.

Hoca hatayı birlikte aradı: C tarafı `n`'yi okuyor, diziyi dolduruyordu; sorun büyük olasılıkla çağrılan yordamdaydı. Yığına atılma sırası gözden geçirilince hata bulundu: sağdan sola kuralına göre önce `n`, sonra dizi atılır, dolayısıyla `n` `[EBP+20]`'de, dizi `[EBP+16]`'dadır. İlk sürümde `ECX`'e dizinin adresi (çok büyük bir sayı), `ESI`'ye 10 değeri gidiyordu; `[ESI]` ile 10 adresine erişilmeye çalışılması hataya yol açtı (ara adım eklendi). Yerler değiştirilince (ekrandan, 00:35:00) önce assembly kodu, sonra C kodu yeniden derlendi ve `n = 10` için 1'den 10'a kadar sayıların toplamı 55 bulundu. Hoca 5, 7, 100 ve 99 değerlerini de denedi.

> **Ders sonrası not:** Ekranda yalnız ilk çıktı okunabilir değildi; bu değerler için doğru sonuçlar büyük olasılıkla $15, 28, 5050, 4950$'dir ($n(n+1)/2$; python ve C karşılığıyla hesaplandı).

Hoca, yanlış göreli konum yazıldığında bu hatanın alınmasının öğretici olduğunu söyledi: sağdan sola sırası unutulursa $+4$, $+8$ gibi doğru yerlere erişilemez.

> **Ek bilgi (derste anlatılmadı):** `LOOP` önce `ECX`'i azaltıp sonra sıfırla karşılaştırdığı için `n = 0` girilirse `ECX` $0 \rightarrow \text{FFFFFFFF}_h$ olur ve döngü yaklaşık $2^{32}$ kez döner. Gerçek bir programda bu durum için döngüden önce `JECXZ` gibi bir denetim eklenir.

**Soru:** `section .data` ve `section .text` neydi? **Cevap:** Klasik sürümde segment denilen şeylere burada section deniyor. `section .data` veri kesimini, `section .stack` yığın kesimini, `section .text` kod kesimini tanımlar. Bu örnekte `section .data` yazılmasa da olurdu.

## 7. MOV AX, 0ABCDh Sorusu

Aradan sonra sohbetten gelen bir soru cevaplandı: `MOV AX, 0ABCDh` yazıldığında ne olur?

`AX`, `AH` (yüksek) ve `AL` (düşük) olmak üzere iki parçadır. Sayının yüksek anlamlı kısmı `AB` `AH`'ye, düşük anlamlı kısmı `CD` `AL`'ye girer. Soruda önerilen "`AH` = CD, `AL` = AB" doğru değildir; tam tersidir.

Öğrenci makine kodunda değerlerin ters sırada göründüğünü söyleyince hoca, makine kodu öyle görünse de `MOV` komutunun `AB`'yi `AH`'ye koyduğunu, makine kodunda ikinci gelen byte'ın `AH`'ye, ilk gelen byte'ın `AL`'ye girdiğini açıkladı.

> **Ek bilgi (derste anlatılmadı):** `MOV AX, 0ABCDh` komutunun makine kodu `B8 CD AB`'dir. x86 little endian olduğu için anlık değerin düşük byte'ı (`CD`) önce yazılır. Bellekte ters görünmesi yazmaçtaki değeri değiştirmez.

## 8. Örnek 2: Visual Studio'da C ve MASM ile Selection Sort

### 8.1 Proje ve amaç

Bu örnek Windows'ta Visual Studio (hocanın sürümü 2017) ile yapıldı. Boş bir proje (empty project) oluşturuldu ve içine bir C++ kaynak dosyası eklendi. Visual Studio'da C++ dosyasının içine doğrudan C kodu yazılıp çalıştırılabilir; yazılan kod C'dir.

Amaç: bir diziyi **büyükten küçüğe** sıralayan Selection Sort'u önce C fonksiyonuyla, sonra assembly yordamıyla çalıştırıp süreleri karşılaştırmak. Sıralama algoritmasının en kötü durumu dizinin ters yönde sıralı olmasıdır; bu yüzden dizi küçükten büyüğe sıralı verilir.

### 8.2 C tarafı

Başlangıç iskeleti (ekrandan, 01:05:00):

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int n = 10;

int main() {
    int i;


    system("PAUSE");
    return 0;
}
```

- `stdlib.h`, programı `system("PAUSE")` ile durdurmak için eklendi (konsol penceresi açılıp hemen kapanmasın diye). `time.h` süre ölçmek içindir.
- `n` kullanıcıdan okunmaz, sabittir (`const int n`); farklı değerlerle test edilir.
- Dizi `dizi[i] = i + 1` ile doldurulur. Hoca burada da `int`'in 32 bitlik olduğuna dikkat çekti.
- Sıralamadan önce ve sonra dizinin ilk ve son elemanı yazdırılır, böylece sıralamanın gerçekten yapıldığı görülür.
- Sıralama fonksiyonuna dizinin adresi ve eleman sayısı verilir; geri dönüş beklenmediği için `void`'dir. Prototip `void SelSortC(int *, int);` biçimindedir. <!-- BELİRSİZ: prototip satırı karede tam görünmedi; ad "SelSortC" ayrıştırılmış koddan (01:20:00), parametre tipleri altyazıdan. -->
- Süre `clock_t` türündeki iki değişkenle ölçülür: `bas` ve `bit`. `clock()` saat darbesi (clock cycle) cinsinden değer döndürür; fark `CLOCKS_PER_SEC`'e bölünerek saniyeye çevrilir. Hoca bunları kronometreye benzetti.

Karede görünen ölçüm ve yazdırma kısmı (ekrandan, 01:10:00):

```c
    SelSortC(dizi, n);
    bit = clock();

    sure = (double)(bit - bas) / CLOCKS_PER_SEC;
    printf("Siralamadan sonra: dizi[0]: %d, dizi[n-1]: %d\n", dizi[0], dizi[n - 1]);
    printf("Toplam sure: %.2f\n", sure);
```

Sıralama öncesi satır ayrıştırılmış kodda `"Siralamadan once: dizi[0]: %d, ..."` olarak görülür (ekrandan, 01:20:00). Selection Sort fonksiyonunun gövdesi hazır yapıştırıldı; ayrıştırılmış koddan görünen başı şudur (ekrandan, 01:25:00):

```c
    int i, j, tmp, max;
    for (i = 0; i < boyut - 1; i++) {
        max = i;
        for (j = i + 1; j < boyut; j++)
        ...
```

<!-- BELİRSİZ: SelSortC'nin geri kalanı karede görünmedi. -->

### 8.3 C sürümünün çalıştırılması

`n = 10` için dizinin ilk elemanı 1, son elemanı 10 iken sıralamadan sonra ilk eleman 10, son eleman 1 oldu. İki basamak hassasiyetle süre 0 saniye göründü. `n = 100000` yapılınca (ekrandan, 01:10:00: `Siralamadan once: dizi[0]: 1, dizi[n-1]: 100000`) sıralama **12,31 saniye** sürdü.

### 8.4 Assembly yordamı

C fonksiyonunun çağrısı yorum satırı yapıldı ve aynı prototipte `SelSortASM` çağrıldı. Prototipin başına `extern` yazılır; ayrıca dosya C++ olarak derlendiği için yordamın C kuralıyla aranacağını belirtmek üzere `"C"` de eklenir, yani `extern "C" void SelSortASM(int *, int);` biçimindedir. <!-- BELİRSİZ: bu satır karede görünmedi; altyazıdan kuruldu. -->

Yordam projeye ayrı bir kaynak dosyası (`ornek2.asm`) olarak eklendi. MASM sözdizimi alışılan sürüme yakındır:

- Klasik 8086 yerine yeni Intel işlemciler (586 mimarisi) için derleneceği `.586` ile belirtilir.
- Gerçek kip (real mode) ve korumalı kip (protected mode) vardı; korumalı kipte, düz (flat) bellek modeliyle program yazıldığı `.model flat` ile belirtilir.
- Kesimler `.stack <boyut>`, `.data` ve `.code` ile tanımlanır. <!-- BELİRSİZ: .stack boyutu altyazıda "180" diye geçiyor; karede görünmedi. -->
- Yordam tanımı alışılanla aynıdır: adı C'deki adla birebir aynı olmalıdır; `SelSortASM PROC NEAR` ... `RET` ... `SelSortASM ENDP` ve dosyanın en sonunda `END`.

> **Hocanın vurgusu:** C'den bir assembly yordamı da çağrılsa, bir C fonksiyonu da çağrılsa kesimler arası değil, kesim içi (NEAR) dallanma yapılır.

Yordamın görülen kısmı (ekrandan, 01:15:00; satırlar 1-14 ve 35 sonrası karede yok):

```asm
        PUSH EDI
        PUSH ESI
        PUSH EAX
        PUSH EBX
        PUSH EDX

        MOV EBP, ESP
        MOV EDI, [EBP+32]
        MOV ECX, [EBP+36]

        DEC ECX
        MOV EAX, EDI

dis_don: MOV EBX, ECX
        MOV ESI, EAX
        MOV EDI, EAX
        MOV EDX, [EDI]
ic_don: ADD ESI, 4
        CMP [ESI], EDX
        JGE ATLA
        ...
```

Hoca, kullandığı yazmaçları yığına attıktan sonra parametreleri `EBP`'ye göre 32 ve 36 göreli konumundan, yani yığındaki 8. ve 9. elemandan (0'dan sayarak) aldığını; birini (`dizi` adresi) `EDI`'ye, diğerini (`n`) `ECX`'e koyduğunu söyledi. $32 = 8 \cdot 4$ olduğundan `EBP`'nin üstünde 8 eleman vardır: dönüş ofseti `[EBP+28]`'de, yani yordam başında 7 yazmaç atılmıştır (python ile kontrol edildi). Karede bunlardan beşi (`EDI, ESI, EAX, EBX, EDX`) görünür. <!-- BELİRSİZ: kalan iki PUSH (büyük olasılıkla EBP ve ECX) karede görünmedi. --> Yine sağdan sola kuralı gereği önce `n`, sonra dizi atıldığı için `n` daha yüksek adrestedir (`+36`).

> **Ek bilgi (derste anlatılmadı):** Görünen iç döngü, `ESI` ile ilerleyip `CMP [ESI], EDX` / `JGE` ile o ana kadarki en büyük değerden büyük ya da eşit bir eleman bulunca onu yeni aday yapan bir Selection Sort taramasıdır; büyükten küçüğe sıralamada her dış turda kalan kısmın en büyüğü öne alınır.

### 8.5 Özel derleme aracı (Custom Build Tool)

GCC ve NASM'de derleme komut satırından parametrelerle yapılıyordu. Visual Studio'da `.asm` dosyası için özel bir derleme aracı tanımlanır:

- `.asm` dosyasına sağ tıklanıp **Özellikler** seçilir; öğe türü olarak **Özel Derleme Aracı (Custom Build Tool)** seçilip Uygula denir.
- Özel Derleme Aracı sayfasında **Komut Satırı** alanına, derlerken çalıştırılacak MASM (`ml`) komutu tırnak içinde dosyanın tam yolu ile yazılır; **Çıktılar** alanına `%(Filename).obj` yazılır. Diğer alanlar doğrudan önemli değildir.
- Hoca bu komutu ezberlemeyi beklemediğini, kendisinin de internetten baktığını söyledi.
- Sonra çözüm temizlenip yeniden derlenir.

<!-- BELİRSİZ: komut satırının tam metni karede görünmedi; altyazıda yalnız "CX parametreleri", "cutoff", "tırnak içinde full path" geçiyor. -->

> **Ek bilgi (derste anlatılmadı):** Bu ayar için yaygın kullanılan komut büyük olasılıkla `ml /c /Cx /coff "%(FullPath)"` biçimindedir: `/c` yalnız derler (bağlamaz), `/Cx` dış semboller için büyük/küçük harfi korur, `/coff` 32 bitlik COFF nesne biçimi üretir. Visual Studio'da bunun yerine proje için MASM derleme özelleştirmesini açmak da mümkündür.

### 8.6 Süre karşılaştırması

Çözüm başarıyla derlendi; hem C hem assembly kodu kullanıldı. Çalıştırınca dizi yine büyükten küçüğe sıralandı ve süre **3,44 saniye** oldu. C ile 12,31 saniye süren işin assembly ile 3,44 saniyede yapılması yaklaşık 3,5 katlık hızlanmadır ($12{,}31 / 3{,}44 \approx 3{,}58$).

> **Hocanın vurgusu:** Süreler bilgisayara göre değişir; "sizin bilgisayarınızda 12 saniye sürdü ama benimkinde 3 saniye" gibi bir karşılaştırma anlamsızdır. Önemli olan iki süre arasındaki orandır. Hız gereken durumlarda, örneğin gerçek zamanlı projelerde bu fark çok önemlidir; C içinden, sanki C fonksiyonu çağırıyormuş gibi bir assembly yordamı çalıştırılabilir.

## 9. Ayrıştırılmış Kod ile Adım Adım İzleme

### 9.1 Assembly yordamının çağrılması

Hoca programı hata ayıklama (Debug) kipinde çalıştırıp **Hata Ayıkla → Pencereler → Ayrıştırılmış Kod** (Disassembly) penceresini açtı. Bu pencerede yazılan C kodunun satırları ve her birinin assembly karşılığı, ayrıca derleyicinin eklediği işler görülür. **Yazmaçlar** penceresinde yazmaçların değerleri görülür; değişen yazmaçlar kırmızıyla boyanır. F11 ile adım adım ilerlenir.

`SelSortASM(dizi, n);` satırının karşılığı (ekrandan, 01:20:00):

```text
00571A38  push  186A0h
00571A3D  lea   eax,[dizi]
00571A43  push  eax
00571A44  call  _SelSortASM (0571159h)
00571A49  add   esp,8
```

- Önce `n` yığına atılır: $186A0_h = 100000$ (python ile kontrol edildi).
- Dizinin adresi `LEA` (load effective address) ile `EAX`'e alınır ve yığına atılır. Bu, sağdan sola kuralının derleyicideki karşılığıdır.
- `call` ile yordama dallanılır (dönüş ofseti yığına atılır).
- Dönüşten sonra `add esp,8` gelir: iki eleman atılmıştır, her biri 32 bit (4 byte), toplam 8 byte. C, yığına attıklarını kendisi temizler.

> **Hocanın vurgusu:** Her programlama dili yığını bu şekilde temizlemeyebilir. Assembly'yi hangi dille kullanıyorsanız o dilin bu özelliğini bilerek hareket etmelisiniz.

F11 ile `call` adımında hocanın yazdığı assembly koduna geçildi ve `DEC ECX` gibi satırlar adım adım izlendi. 100.000 eleman için bunu sonuna kadar izlemek çok uzun süreceği için durduruldu; hoca eleman sayısı 3 yapılarak bütün akışın izlenebileceğini önerdi.

### 9.2 C fonksiyonunun derlenmiş hâli

Ardından assembly çağrısı kapatılıp C fonksiyonu açıldı ve aynı pencereden `SelSortC` izlendi (ekrandan, 01:25:00). Bütün programlama dilleri (derste C üzerinden konuşuldu) çalıştırılmadan önce assembly'ye (makine koduna) dönüştürülür ve çalışan şey o assembly'dir. C fonksiyonunun derlenmiş hâlinde de el ile yazılanla aynı kalıp görülür: önce base pointer yığına atılır, sonra stack pointer ile eşitlenir, değerler yığından alınır. `for (i = 0; i < boyut - 1; i++)` satırı örneğin şöyle açılır:

```text
mov  dword ptr [i],0
jmp  SelSortC+3Ah
mov  eax,dword ptr [i]
add  eax,1
mov  dword ptr [i],eax
mov  eax,dword ptr [boyut]
sub  eax,1
cmp  dword ptr [i],eax
jge  SelSortC+0AFh
```

Derleyicinin ürettiği kod, elle yazılan assembly'den daha uzundur: dönüştürme sırasında pek çok durum göz önüne alınır ve hata ayıklama için araya ek kodlar konur (örneğin karede `rep stos` ile yerel alanın doldurulması ve `__CheckForDebuggerJustMyCode` çağrısı görülür). 12 saniyede çalışan şey bu koddur; aynı iş assembly'de daha optimize yazılabilir. Ayrıca bu pencere, yazılan C kodunun yazmaçları adım adım nasıl değiştirdiğini izlemek için de kullanılabilir.

Hoca ilk ödevde bazı öğrencilerin C kodunu Visual Studio'da yazıp ayrıştırılmış koddan assembly karşılığını aldığını, yazmaçların başındaki `E`'leri silerek 16 bite uyarladığını söyledi ve bunun da geçerli bir yaklaşım olduğunu belirtti.

**Soru:** 32 bit için yapılan bu iş 64 bit için de yapılabilir mi? **Cevap:** Evet. Derlerken özel derleme aracına 32 bit için komut yazıldı; 64 bit için o komut satırında ne çalıştırılması gerektiğine bakılır ve `R` harfiyle başlayan 64 bitlik yazmaçlar (`RAX`, `RBX`...) kullanılır. Kullanılan mimari ve IDE 64 biti desteklemelidir.

## 10. Örnek 3: Satır İçi Assembly ile Bit Aynalama

### 10.1 Aynalama nedir

Üçüncü yöntem satır içi (inline) assembly'dir: assembly kodu ayrı dosyaya değil, tek bir C dosyasının içine yazılır. Örnek problem: 10 elemanlı bir dizinin her elemanının ikili gösterimindeki birleri ve sıfırları **aynalamak**, yani bit sırasını tersine çevirmek.

Hoca 16 bitlik bir örnekle gösterdi (ekrandan, 01:30:00):

```text
1101010100010101   <->   1010100010101011
0D515h                   0A8ABh
```

Sağdaki sayı, soldakinin bitleri sondan başa doğru okunarak yazılır. Onaltılık karşılıklar dörder bit gruplanarak bulunur: `1101` = 13 = D, `0101` = 5, `0001` = 1, `0101` = 5 → `D515h`; başı harfle başladığı için önüne 0 konur. Aynalanmış sayı `1010` = A, `1000` = 8, `1010` = A, `1011` = B → `0A8ABh` (python ile doğrulandı).

Hoca bunun bazı sistemlerde, örneğin veri iletişiminde kullanıldığını söyledi: bir tarafta en anlamlı bit önce, diğer tarafta en sona gönderilir ve dönüşüm gerekir.

> **Ders sonrası not:** Hoca bu dönüşümü big endian / little endian dönüşümü olarak adlandırdı. Big/little endian büyük olasılıkla **byte** sırasıyla ilgili bir kavramdır (çok byte'lı bir değerin byte'larının bellekteki sırası). Bit aynalama ise seri iletimde bitlerin önce en anlamlıdan mı, en az anlamlıdan mı gönderildiği (bit sırası) farkını gidermek için kullanılır.

### 10.2 Assembly'de üç satırla aynalama

C'de her değerin bitlerini tek tek alıp ters çevirmek uğraştırıcıdır. Assembly'de kaydırma ve döndürme komutlarıyla kısa yoldan yapılır. Hoca fikri şöyle anlattı: `MOV AX, 0D515h` ile sayı `AX`'e konur, sağa bir kaydırılır; düşen bit carry bayrağına (CF) gider. CF'ye düşen bu bit, döndürme (rotate) komutuyla başka bir yazmaca (`BX`) itilebilir. `BX`'in ilk değeri önemsizdir (don't care); 16 bitlik bir sayı için işlem 16 kez yapılınca `BX`'in bütün eski bitleri dışarı itilir ve `BX`'te aynalanmış sayı kalır. 32 bitlik bir sayı için 32 kez döner.

> **Ders sonrası not:** Hoca sağa kaydırmada "en anlamlı bitin" carry bayrağına düştüğünü söyledi; doğrusu `SHR` ile sağa kaydırmada **en düşük anlamlı** bit CF'ye düşer. `RCL EBX, 1` bu biti `EBX`'in en sağına sokar ve önceki bitleri sola iter; böylece ilk alınan (en düşük) bit sonunda en yüksek konuma ulaşır. 16 bitlik örnek python ile `SHR`/`RCL` adım adım benzetilerek doğrulandı: `D515h` → `A8ABh`.

Hoca bazı durumlarda assembly'de program geliştirme süresinin de kısa olabileceğini, bu örneğin bunu gösterdiğini söyledi.

### 10.3 Inline kod

Kod hazır getirildi ve düzenlendi (ekrandan, 01:35:00 ve 01:40:00):

```c
#include <stdio.h>
const int n = 10;

//00000000000000000000000000000011
//11000000000000000000000000000000
//C0000000
int main() {
    int dizi[n], i;
    for (i = 0; i < n; i++) {
        dizi[i] = i + 1;
        printf("%8x, ", dizi[i]);
    }
    printf("\n\n");
    __asm {
        MOV ECX, n
        XOR ESI, ESI
    L2: MOV EAX, dizi[ESI]
        PUSH ECX
        MOV ECX, 32
    L1: SHR EAX, 1
        RCL EBX, 1
        LOOP L1
        POP ECX
        MOV dizi[ESI], EBX
        ADD ESI, 4
        LOOP L2
    }
    for (i = 0; i < n; i++)
        printf("%8x, ", dizi[i]);
    return 0;
}
```

<!-- BELİRSİZ: yorum satırlarındaki sıfır sayısı karede tam sayılamadı; 3'ün 32 bitlik gösterimi ve aynası olarak yazıldı. `return 0;` satırı karede yarım görünüyor. -->

- C kodunun içinde iki alt çizgiyle `__asm` yazılıp süslü parantez açılır; parantezler arasına satır içi assembly yazılır.
- Yukarıda tanımlanan C değişkenleri (`n`, `dizi`) assembly'de doğrudan kullanılabilir; global olmaları gerekmez. Yalnız okumak için değil, yazmak için de kullanılabilir (`MOV dizi[ESI], EBX`).
- İç döngü 16 kez değil 32 kez döner, çünkü `int` 32 bittir. Çift döngü olduğu için dış döngünün sayacı `ECX`, iç döngüye girmeden önce yığına atılır, iç döngüden sonra geri alınır.
- Dizinin elemanları `int` (4 byte) olduğu için `ESI` 4'er artırılır.
- `%8x`: değeri onaltılık olarak, 8 karakterlik alanda yazar.

> **Ders sonrası not:** Hoca `%8x`'in baştaki sıfırları da gösterdiğini söyledi. `%8x` alanı soldan **boşlukla** doldurur (`       1`); sıfırla doldurmak için `%08x` yazılır (`00000001`). Bu, kodun C karşılığı gcc ile çalıştırılarak denendi.

Hoca, C'de bunun daha fazla satır süreceğini, C'de daha fazla satır süren bir kodun assembly'ye dönüştürüldüğünde de kesinlikle daha uzun olacağını söyledi. Bitlerle ilgili işlemlerde C içinde inline assembly yazabilmek bir avantajdır. Başka dillerde ve derleyicilerde de yapılabilir ama sözdizimi farklıdır; örneğin GCC'de yazmaçların önüne `%` işareti gelir. Derleyici, C kısmını assembly'ye dönüştürür; inline assembly kısmını ise zaten assembly olduğu için olduğu gibi bırakır.

### 10.4 Çıktının yorumlanması

Program çalıştırılınca ilk satırda `1, 2, ..., 9, a` (1'den 10'a kadar sayıların onaltılık gösterimi) yazıldı. Hoca aynalanmış değerleri elle hesapladı (ekrandan, 01:40:00):

- 1, 32 bitte 31 sıfır ve bir 1'dir. Aynalanınca 1 başa gelir, arkasından 31 sıfır gelir. Dörder gruplayınca ilk grup `1000` = 8 → `80000000`.
- 2 = `...0010`. Aynası `0100...0` → ilk grup 4 → `40000000`.
- 3 = `...0011`. Aynası `1100...0` → ilk grup $8 + 4 = 12$ = C → `C0000000`.

Aynı kodun C karşılığı gcc ile çalıştırıldığında 1..10 için `80000000, 40000000, c0000000, 20000000, a0000000, 60000000, e0000000, 10000000, 90000000, 50000000` çıktı.

### 10.5 Inline ile harici yordamın karşılaştırması ve izleme

- **Inline assembly:** küçük işlemler için hızlıdır; işlem assembly'de yapılır, C değişkenleri kullanılır ve sonuç yine C değişkenlerine yazılır.
- **Harici yordam:** dosya karmaşık değildir; yarısı C yarısı assembly bir dosya yerine C kodu bir bütün olarak kalır.

Hoca `__asm` satırına kesme noktası koyup ayrıştırılmış kod penceresinden izledi: bu kez bir dallanma (`call`) yoktur; doğrudan `n` değerini `ECX`'e atarak başlar ve hemen üstteki C satırından sonra assembly karşılıkları sırayla gelir. Adım adım izleme çok uzun süreceği için durduruldu.

## 11. Dersin Kapanışı

Hoca dönemin son dersinde şunları vurguladı: bütün programlama dilleri işlemci tarafından çalıştırılmadan önce assembly'ye dönüştürülür; bu yüzden arka tarafta assembly'nin nasıl çalıştığını bilmek önemlidir. Assembly özellikle siber güvenlik ve veri iletişimi alanlarında sıkça kullanılır. Doğrudan kullanılmasa bile, üst seviyede program yazarken kodun assembly'ye nasıl dönüşeceğini düşünerek yazma bakışı kazandırır.

## Örnek Sorular

**1.** (derste sözlü, 00:06:40) Makine kodundan geri çevrilen bir programda `LOOP 9` görülüyor. Buradaki 9 nedir?

> **Çözüm (derste verildi):** Bir etikettir, yani etiketlenen satırın ofset adresidir. Etiket isimleri nesne kodu oluşurken kaybolur; makine kodunda yalnız ofset kalır.

**2.** (ekrandan, 00:25:00) `Topla(dizi, n)` çağrısında yordam `PUSH EBP`, `PUSH ECX`, `PUSH ESI`, `MOV EBP, ESP` yaptıktan sonra `n`'yi `[EBP+16]`'dan, diziyi `[EBP+20]`'den alıyor. Program neden segmentation fault veriyor?

> **Çözüm (derste verildi):** C parametreleri sağdan sola atar; önce `n`, sonra dizinin adresi atılır. Bu yüzden `n` `[EBP+20]`'de, dizinin adresi `[EBP+16]`'dadır. Yanlış sürümde `ESI`'ye 10 gibi geçersiz bir adres gittiği için erişilmemesi gereken belleğe erişilir. Düzeltme: `MOV ECX, [EBP+20]`, `MOV ESI, [EBP+16]` (ekrandan, 00:35:00).

**3.** (derste sözlü, 00:59:51) `MOV AX, 0ABCDh` komutundan sonra AH ve AL'de ne vardır?

> **Çözüm (derste verildi):** AH = `ABh`, AL = `CDh`. Makine kodunda (`B8 CD AB`) anlık değerin byte'ları little endian sırada göründüğü için ters görünebilir.

**4.** (derste sözlü, 01:25:23) C'den assembly çağırma 64 bit için de yapılabilir mi?

> **Çözüm (derste verildi):** Evet; derleme komutu 64 bite göre değiştirilir ve `RAX`, `RBX` gibi 64 bitlik yazmaçlar kullanılır. Mimari ve IDE 64 biti desteklemelidir.

**5.** (ekrandan, 01:30:00) `0D515h` sayısının 16 bitlik ikili gösterimini aynalayınız (bit sırasını ters çeviriniz).

> **Çözüm (derste verildi):** `1101010100010101` → `1010100010101011` = `0A8ABh`. Assembly'de `SHR AX, 1` / `RCL BX, 1` 16 kez tekrarlanarak bulunur.

**6.** (ekrandan, 01:40:00) 32 bitlik `int` dizisinde 1, 2, 3 değerleri aynalanınca hangi onaltılık değerler çıkar?

> **Çözüm (derste verildi):** `80000000`, `40000000`, `C0000000`.

## Dersin Toparlaması

Bu derste yüksek seviyeli bir dil olan C ile assembly'nin birlikte kullanımı üç yolla gösterildi. Linux'ta NASM ile yazılan `Topla` yordamı C'den çağrıldı; NASM'de kesimlerin `section`, dışa açmanın `global` ile yapıldığı görüldü. C'nin parametreleri sağdan sola yığına attığı, sonucu `EAX`'ten aldığı ve attığı parametreleri çağrıdan sonra kendisinin temizlediği, yanlış göreli konum yüzünden alınan segmentation fault üzerinden pekiştirildi. Windows'ta Visual Studio ile aynı fikir MASM'de (`.586`, `.model flat`, özel derleme aracı) uygulandı; 100.000 elemanlı en kötü durum dizisinde assembly Selection Sort, C sürümünden yaklaşık 3,5 kat hızlı çalıştı. Ayrıştırılmış kod penceresinde hem C'nin çağrı kalıbı (`push`, `call`, `add esp,8`) hem de C fonksiyonunun derleyici tarafından üretilen daha uzun assembly karşılığı izlendi.

Son olarak satır içi assembly ile C değişkenleri doğrudan kullanılarak bir dizinin elemanları `SHR` ve `RCL` ile aynalandı. Hoca, bu son dersle dönem boyunca işlenen alt seviye programlamanın, bütün dillerin arka planda assembly'ye dönüştüğünü bilerek daha bilinçli program yazmaya hizmet ettiğini belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
