# Ders 11 Genişletilmiş Notu: EXTRN/PUBLIC ile Veri Aktarımı, Kesim Birleştirme, Sistem Reseti ve Kesmelere Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Alt Yordamda Yazmaçların Korunması
- 2. Yığın Üzerinden Parametre Aktarımının Varyasyonları
- 3. EBOB Örneğinde Yığının Adım Adım Çizimi
- 4. Özyinelemeli Sürüm: İsteğe Bağlı Ödev
- 5. Üçüncü Yöntem: EXTRN ve PUBLIC ile Veri Aktarımı
- 6. Minimum, Ortalama ve Maksimum Yordamları
- 7. Derleme, Linkleme, MAP Dosyası ve Debug
- 8. Üç Parametre Aktarım Yönteminin Özeti
- 9. Kesim Birleştirme Neden Gerekir?
- 10. Kod Segmentlerini Birleştirme
- 11. Birleşik Segmentte EXTRN ve NEAR Çağrı
- 12. Kesim Birleştirmenin Kazançları ve Veri Kesimi Birleştirme
- 13. Sistem Reseti
- 14. Veri Aktarım Tipleri: Polling, Kesme, DMA
- 15. Kesme Kaynakları
- 16. Kesme Bayrakları ve IRET
- 17. Kesme Vektör Tablosu
- 18. STI, CLI ve TF
- Örnek Sorular

## 1. Alt Yordamda Yazmaçların Korunması

Ders, önceki haftalarda işlenen yordamlar arası parametre aktarımının tekrarıyla başladı. Bir ana yordam bir alt yordamı çağırdığında yazmaçlar mevcut değerleriyle alt yordamda da kullanılabilir durumdadır. Yalnız birkaç yazmaç değişir. SP değişir, çünkü sistem dönüş adresini yığına otomatik olarak atar. NEAR çağrıda IP, FAR çağrıda hem IP hem CS değişerek alt yordama gidilir.

Bu özelliğin bir avantajı ve bir dezavantajı vardır. Avantajı şudur: parametre aktarımını yazmaç üzerinden yapmak istiyorsak bu doğrudan kullanılabilir. Yazmaçlar alt yordama değer değiştirmeden geçtiği için yazmaçla parametre aktarımı kendiliğinden sağlanmış olur.

Dezavantajı, alt yordamın yazmaçları geçici hesaplamalar için (temporary değişken gibi) kullanmak istediği durumda ortaya çıkar. Hocanın örneği şöyledir: ana yordamda CX bir döngünün sayacı olsun ve o anda 5 değerinde, yani kaçıncı adımda olunduğunu tutuyor olsun. Alt yordama gidildi, alt yordam içinde başka bir döngü kuruldu, CX'e yeni bir değer atandı ve döngü dönüldü. `LOOP` bittiğinde CX 0 olur. Alt yordamdan dönüldüğünde CX 0 olarak gelir; oysa ana yordam 5'ten devam etmeliydi.

Buradan bir temel kural çıkar: alt yordamda dönüş değeri için kullanılmayan ama geçici işler için kullanılan her yazmaç, alt yordama girer girmez yığına atılmalı ve çıkarken geri çekilerek orijinal değeri korunmalıdır.

> **Hocanın vurgusu:** Bu, yazılan bütün alt yordamlarda ve fonksiyonlarda dikkat edilmesi gereken çok önemli bir kuraldır. Geçici kullanılan yazmaçlar girişte `PUSH` ile saklanır, `RET` öncesinde `POP` ile geri yüklenir.

Dikkat edilecek ikinci nokta sıradır: yığına hangi sırayla atıldıysa ters sırayla çekilmelidir. Geçici kullanılan bütün yazmaçlar çekildiğinde dönüş anında yığının tepesinde yalnız dönüş IP'si ve (FAR çağrıda) CS değeri kalmalıdır.

Hoca bir çalışma yöntemi de önerdi: önce fonksiyonun görevini yerine getiren ana gövde yazılır. Böylece kullanılan yazmaçlar ortaya çıkar. Sonra bunlar girişte yığına atılır ve çıkışta ters sırada çekilir.

Yazmaç üzerinden parametre aktarımı az sayıda parametre için tercih edilir.

## 2. Yığın Üzerinden Parametre Aktarımının Varyasyonları

Hoca, ikinci yöntem olan yığın üzerinden parametre aktarımının önceki haftada görülen varyasyonlarını tekrar etti. Önerdiği sıra şudur: önce alt yordam tanımlanır, girdisi ve çıktısı gereksinimlere göre belirlenir. Bunlar belirlenince parametre aktarımının ve dönüşün nasıl olacağı kendiliğinden ortaya çıkar.

### 2.1 Çöp parametreleri ana yordam kaldırır

Önceki haftanın en büyük ortak bölen (EBOB) örneğinde alt yordam yığından iki word kabul ediyor ve sonucu AX'te döndürüyordu. Bunun için iki word, fonksiyon çağrılmadan önce yığına atılmış olmalıdır. Yığında en altta işletim sistemine dönüş CS'si ve sıfır offset değeri, onların üstünde iki parametre, FAR çağrıdan sonra da ana yordama dönüş CS'si ve IP'si bulunur.

Sonuç AX'te döndüğü için yığındaki iki parametre artık çöptür. Bu ilk sürümde yığına veriyi koyan ana yordam, işletim sistemine dönmeden önce bu iki parametreyi yığından kaldırmak zorundadır.

### 2.2 Çöp parametreleri alt yordam kaldırır: RETF n

İkinci sürümde yığından çöp veriyi kaldırma görevi alt yordama verildi. Tanım: alt yordam yığından iki word alır, AX'te değer döndürür ve yığına konulan parametreleri kendisi kaldırır.

Bunun pratik yolu `RET`/`RETF` komutundan sonra bir sayı yazmaktır. Bu sayı, dönüşle birlikte SP'nin o kadar artırılmasını sağlar. Sayı çift olmalıdır, çünkü yığına word yazılıp word okunur. Alt yordam FAR olduğu için dönüşü `RETF`'tir. İki word kaldırılmak istendiğinde `RETF 4` yazılır.

Hoca bunu yığın üzerinden anlattı. Alt yordama gelindiğinde yığında aşağıdan yukarı OS CS, OS IP, ana yordamın iki parametresi, ana yordama dönüş CS'si ve IP'si vardır. `RETF 4` önce tepedeki iki değeri IP ve CS'ye yükler. O anda SP iki parametreyi gösterir. Sonra SP 4 artırılır ve artık OS IP satırını gösterir. Böylece ana yordam `RET` yaptığında işletim sistemine düzgün şekilde döner.

### 2.3 Sonucun yığına yazılması

Üçüncü sürümde alt yordam yığından iki parametre alır, işlem sonucunu da artık çöp haline gelmiş parametre gözlerinden birinin üzerine yazar. İki word'ün EBOB'u yine tek bir word'e sığdığı için bu mümkündür. Sonucun hangi göze yazıldığına göre dönüşteki işlemler değişir.

Hoca önce şu genel kuralı hatırlattı: yığın üzerinden bir dönüş varsa sonucu yığından ana yordam çekmek zorundadır. Çöp olan değeri çekme görevi ise ana yordama ya da alt yordama bırakılabilir.

- Sonuç üstteki parametre gözüne yazılırsa: alt yordam `RETF` ile döner. SP parametreleri gösterir; ana yordam ilk `POP` ile sonucu alır, ikinci bir boş `POP` (ör. `POP AX`, AX'teki değerin çöp olduğu bilinerek) ile çöpü kaldırır.
- Sonuç alttaki parametre gözüne yazılır, çöpü ana yordam kaldırır: ana yordamın ilk `POP`'u çöp değeri alır, ikinci `POP` anlamlı sonucu alır ve ilgili belleğe yazar.
- Sonuç alttaki parametre gözüne yazılır, çöpü alt yordam kaldırır: alt yordam `RETF` yerine `RETF 2` ile döner. Üstteki çöp göz otomatik olarak atlanır, SP sonucu tutan gözü gösterir. Ana yordam tek `POP` ile sonucu alır.

## 3. EBOB Örneğinde Yığının Adım Adım Çizimi

Hoca bu konunun nasıl çalıştığını anlamanın önemli olduğunu söyledi ve yığından okurken nereye bakılacağını hatırlattı.

> **Hocanın vurgusu:** Yığından parametre aktarımı yaparken yığın çizilerek ilerlenmelidir. Yığın çizilirse neler olup bittiğini anlamak mümkündür.

Ekranda sağda ana yordam (`ANA.ASM`), solda alt yordam (`ALT_A_.ASM`) vardı. Örnek, son anlatılan varyasyona göredir: ana yordam iki word'ü yığına atar, alt yordamı çağırır; alt yordam sonucu alttaki göze yazar ve üstteki çöp gözü kendisi kaldırır.

### 3.1 Kod

Ana yordamın veri ve çağrı kısmı (ekrandan, 00:10:00 ve 00:25:00):

```text
EXTRN _GCD_PROC:FAR
...
DATASG   SEGMENT PARA 'DATA'
ASAYISI    DW 12
BSAYISI    DW 8
SONUC      DW ?
DATASG ENDS
...
BASLA   PROC FAR
        PUSH DS
        XOR AX,AX
        PUSH AX
        MOV AX, DATASG
        MOV DS, AX
        PUSH ASAYISI
        PUSH BSAYISI
        CALL _GCD_PROC
        POP SONUC
```

Ekranda `POP SONUC` satırının çevresinde önceki varyasyonlara ait `;POP AX` ve `;MOV SONUC, AX` satırları yorum olarak duruyordu.

Alt yordam (ekrandan, 00:10:00, 00:15:00 ve 00:30:00):

```text
PUBLIC _GCD_PROC

CDESG   SEGMENT PARA 'CODE'
        ASSUME CS:CDESG

_GCD_PROC PROC FAR
        PUSH BP
        MOV BP, SP
        PUSH AX
        PUSH BX
        PUSH DX
; AX<-[SS:(BP+6)]
        MOV BX, [BP+6]
        MOV AX, [BP+8]
        CMP AX, BX
        JAE TEKRAR
        XCHG AX, BX
TEKRAR: CMP BX, 0
        JA L1
        JMP EXIT
L1:     XOR DX, DX
        DIV BX
        MOV AX, BX
        MOV BX, DX
        JMP TEKRAR
EXIT:
        MOV [BP+8], AX
        POP DX
        POP BX
        POP AX
        POP BP
        RETF 2
_GCD_PROC ENDP
CDESG   ENDS
        END
```

### 3.2 Girişte yığın

EXE programa girildiğinde ilk üç satırın (`PUSH DS`, `XOR AX,AX`, `PUSH AX`) amacı işletim sistemine dönüşü sağlamaktır. EXE çalıştırıldığında işletim sistemi DS'ye dönüş segment değerini koyar ve DS'nin 0 offsetine dönülmesini bekler. Bu yüzden yığının en altında OS CS, onun üstünde OS IP bulunur.

Sonra yığına önce A sayısı (12), ardından B sayısı (8) atılır. `CALL` başka dosyadaki FAR yordamı çağırdığı için yığına ana yordamın dönüş CS'si ve IP'si eklenir.

### 3.3 Alt yordam içinde BP'nin rolü

Alt yordamda DIV işlemi olduğu için AX, BX ve DX kullanılır. Bunlar geri dönüş değeri için tutulmadığından korunmalıdır.

Hoca ikinci bir temel kuralı hatırlattı: alt yordam içinde başka `PUSH` ve `POP` işlemleri yapılırsa SP arada değişir. Aktarılan parametrelerin yerini yığının belirli bir noktasını referans alarak sabitlemek gerekir. Bunun için BP kullanılır. BP'nin varsayılan segment yazmacı SS'dir, yani yığındaki bir bölgeye erişmek için tam istenen işi yapar. BP de değiştirileceği için önce o korunur: `PUSH BP`. Ardından `MOV BP, SP` ile BP ve SP aynı adresi, yani yığına en son atılan BP'yi gösterir.

Sonra AX, BX ve DX yığına atılır. Her atmada SP yukarı doğru gider, yani adres küçülür; yığının en yüksek adresi en alttadır. BP ise atanan değerde kalır. İçeride SP oynayacağı için A ve B'ye SP ile güvenle erişilemez, ama BP'den emin olunur.

Yığının BP'ye göre görünümü şöyledir (ekrandan, 00:25:00 ve 00:30:00):

```text
düşük adres (SP buraya doğru ilerler)
  DX
  BX
  AX
  BP        <- BP (ve MOV BP,SP anındaki SP)
  ANA IP    BP+2
  ANA CS    BP+4
  B         BP+6
  A         BP+8
  OS IP
  OS CS
yüksek adres
```

Her göz 2 bayt olduğu için B, BP'den 2, 4, 6 bayt uzakta yani `BP+6`'dadır; A ise `BP+8`'dedir. Bunlar `MOV BX, [BP+6]` ve `MOV AX, [BP+8]` ile alınır. Hoca `[BP+6]` yazıldığında fiziksel adresin SS ile birlikte hesaplandığını özellikle belirtmek için koda `; AX<-[SS:(BP+6)]` açıklamasını yazdı.

### 3.4 Dönüşte yığın

EBOB hesaplandıktan sonra sonuç, aktarılan parametrelerden altta olanın yani A'nın gözüne yazılır: `MOV [BP+8], AX`. Hoca bu gözü çizimde "GCD" diye işaretledi.

Sonra korunan değerler tek tek çekilir; her çekişte SP 2 artar:

- İlk `POP DX`, tepedeki değeri alır; bu DX'in orijinal değeridir.
- `POP BX` sıradaki değeri, BX'in orijinal değerini alır.
- `POP AX` AX'in orijinal değerini alır.
- `POP BP` en başta atılan BP'yi geri yükler; BP artık o göze göstermez, orijinal değerine döner.

`RETF 2` tepedeki değeri IP'ye, sıradakini CS'ye yükler; ana yordama dönüş adresi doğru şekilde kurulmuş olur. Ardından SP 2 artırılarak B satırı boş geçilir. Ana yordama dönüldüğünde SP sonucu tutan gözü gösterir. `POP SONUC` bu değeri alıp SONUC'a yazar. Ana yordam `RET` ettiğinde yığının tepesindeki OS IP ve OS CS çekilir ve işletim sistemine dönülür. Böylece yığın üzerinden parametre aktarımı başarıyla tamamlanmış olur.

## 4. Özyinelemeli Sürüm: İsteğe Bağlı Ödev

Hoca bir adım daha ileri gidilebileceğini söyledi: alt yordamın dönüş değeri özyinelemeli (recursive) tanımlıysa fonksiyon kendini tekrar tekrar çağırır. Bu durumda yığına derinliğe göre parametreler, dönüş değerleri, tekrar parametreler, dönüş değerleri üst üste basılır. Daha önce EBOB'un özyinelemeli hali yapılmıştı, ama yığından parametre aktarımıyla birlikte yapılmamıştı.

Hocanın verdiği zorunlu olmayan ödev şudur: ana yordamda da alt yordamda da parametre aktarımı yığın üzerinden olmak şartıyla, yığından parametre alıp yığından sonuç döndüren özyinelemeli EBOB fonksiyonu assembly ile gerçeklenmelidir. Program derlendikten sonra Debug ile yığının içi ve yığından okunacak değerler incelenmeli, verilen bir A, B ikilisi için yığının en derin hali stack segment dump edilerek analiz edilmelidir.

## 5. Üçüncü Yöntem: EXTRN ve PUBLIC ile Veri Aktarımı

Hoca üç yöntemi kullanım yerine göre karşılaştırdı:

- Yazmaç üzerinden aktarım az sayıda veri varsa anlamlıdır.
- Yığın üzerinden aktarım özel durumlarda ve yine az sayıda veri için anlamlıdır.
- Daha yüksek kapasitede ve daha çok sayıda veri aktarımı için EXTRN ve PUBLIC kullanımı daha anlamlıdır. Örneğin bir dizi komple parametre olarak aktarılmak isteniyorsa.

Bu yapı, fonksiyonların ayrı dosyalardan kullanılmasına benzer. Ana yordam başka dosyadaki alt yordamı kullanacaksa onu `EXTRN` ile ve tipini belirterek tanımlıyordu; dışarıya fonksiyon kullandıran dosya da onu `PUBLIC` tanımlıyordu. Aynı mantıkla veri de dosyalar arasında paylaşılabilir.

### 5.1 Örneğin kurgusu

Örnekte 10 elemanlı bir word dizisi vardır. Bu dizinin minimum, ortalama ve maksimum değerleri hesaplanacaktır. Her biri ayrı bir dosyada tanımlı üç fonksiyon vardır: dizinin minimumunu, maksimumunu ve ortalamasını bulan fonksiyonlar. Fonksiyonlara aktarılması gereken şeyler dizi ve eleman sayısı değişkenleridir. Fonksiyonlar EXTRN/PUBLIC mantığında girdi kabul eder ve AX üzerinden değer döndürür. Ana yordam her fonksiyonu tek tek çağırıp sonucu ilgili bellek gözüne yazar ve sonra döner.

Hoca derste fonksiyonların kod segmentlerinin sınıf adlarını `CODE1`, `CODE2`, `CODE3` olarak değiştirdi, tiplerini FAR ve dönüşlerini `RETF` yaptı. Aynı örneğin kesim birleştirme konusunda da kullanılacağını söyledi.

### 5.2 Ana dosya

Ana dosya (ekrandan, 00:40:00):

```text
        PAGE 60,80
        TITLE pass parameter through extrn/public data

EXTRN DIZI_MAX_F:FAR, DIZI_MIN_F:FAR, DIZI_ORT_F:FAR
PUBLIC DIZI, ELEMAN

STACKSG SEGMENT PARA STACK 'STACK'
        DW 32 DUP(?)
STACKSG ENDS

DATASG  SEGMENT PARA 'DATA'
DIZI    DW 13, 12, 14, 25, 14, 12, 11, 4, 2, 12
ELEMAN  DW 10
MIN     DW ?
ORT     DW ?
MAX     DW ?
DATASG  ENDS

CODESG  SEGMENT PARA 'CODE'
        ASSUME CS:CODESG, DS:DATASG, SS:STACKSG

BASLA   PROC FAR
        PUSH DS
        XOR AX,AX
        PUSH AX
        MOV AX, DATASG
        MOV DS, AX
        ...
```

<!-- BELİRSİZ: Ana yordamda üç CALL satırının ve sonuçların MIN/ORT/MAX'a yazıldığı satırların tam metni karelerde görünmüyor. -->

Üç fonksiyon bu dosyada olmadığı için dışarıdan kullanılacaktır; bu yüzden linkleme aşamasında farklı OBJ dosyaları birlikte linklenmelidir ve fonksiyon adları FAR tipiyle `EXTRN` olarak tanımlanmalıdır. DIZI ve ELEMAN ise çok sayıda parametreye karşılık gelir. Yazmaçla aktarılamazlar; yığınla aktarılsalar dizi örneğin yüz elemanlı olduğunda yığın taşabilir. Bu yüzden referans olarak karşı tarafa aktarılırlar. Fonksiyonlarda olduğu gibi, veri segmentindeki değişkenler de `PUBLIC` tanımlanarak dışarıdan kullanılabilecek referanslar olduğu bildirilir. Bu haliyle ana yordam kendi başına derlenip OBJ dosyası oluşturabilir.

### 5.3 Alt dosyaların bildirimleri

Her alt dosya dışarıya bir fonksiyon kullandırdığı için o fonksiyonu `PUBLIC` tanımlamalıdır. Ayrıca dışarıdan iki değişken kullanır. DIZI aslında word tipindeki bir dizinin başlangıç adresidir, ELEMAN da orijinal haliyle word tipindedir. Bu yüzden tipleriyle birlikte `EXTRN` olarak bildirilirler (ekrandan, 01:35:00):

```text
PUBLIC DIZI_ORT_F
EXTRN DIZI:WORD, ELEMAN:WORD
```

Dosyada DIZI ve ELEMAN tanımları olmadığı halde dışarıdan kullanılacakları belirtildiği için bu dosya da tek başına derlenip OBJ oluşturabilir.

## 6. Minimum, Ortalama ve Maksimum Yordamları

### 6.1 DIZI_MIN_F

Görev: dışarıdan bir dizinin başlangıç adresi ve eleman sayısı verilmişken dizinin minimumunu AX'te döndürmek. Yöntem: dizinin bütün elemanları taranır. İlk okunan değer pivot, yani aday en küçük değerdir. Dizide ilerlerken elimizdeki en küçük değerden daha küçük bir değer görülürse pivot onunla değiştirilir.

Diziyi baştan sona taramak için döngü gerekir, bu yüzden CX kullanılır. Dizinin elemanlarını dolaşmak için SI kullanılır. CX ve SI içeride geçici değer tutan yazmaçlardır ve korunur. AX ise dönüş değerini tutacağı için korunmaz: çıkarken `POP AX` yapılsaydı içeride bulunan değer girişteki AX değeriyle ezilir, sonuç bozulurdu.

Kod (ekrandan, 00:45:00):

```text
        ASSUME CS:CODESG
DIZI_MIN_F PROC FAR
        PUSH CX
        PUSH SI
        LEA SI, DIZI
        MOV CX, ELEMAN
        MOV AX, [SI]
        DEC CX
TEKRAR: ADD SI,2
        CMP AX, [SI]
        JB L1
        MOV AX, [SI]
L1:     LOOP TEKRAR
        POP SI
        POP CX
        RETF
DIZI_MIN_F ENDP
CODESG  ENDS
        END
```

DIZI'nin başlangıç adresi SI'ya, eleman sayısı CX'e, ilk eleman AX'e alınır. İlk tahmine göre dizinin ilk elemanı en küçük elemandır. İlk eleman işlendiği için eleman sayısı kadar değil, bir eksik adım ilerlemek gerekir; bu yüzden `DEC CX` vardır. Her adımda SI 2 artırılarak sıradaki elemana geçilir ve AX ile karşılaştırılır. AX daha küçükse bir şey yapmadan döngüye dönülür. SI ile gösterilen eleman AX'ten küçükse yeni en küçük değer AX'e alınır. Döngü bittiğinde AX'te dizinin en küçük elemanı bulunur.

Hoca, ana görevi yerine getiren kısmı ekranda işaretledi; onun dışındaki satırlar orijinal değerleri korumak içindir.

### 6.2 DIZI_ORT_F ve 32 bitlik toplam

Bu dosyada da `DIZI_ORT_F` dışarıya kullandırıldığı için `PUBLIC`, DIZI ve ELEMAN dışarıdan kullanıldığı için `EXTRN ...:WORD` tanımlanır. Ana gövdedeki iş bir word dizisini toplamaktır.

> **Hocanın vurgusu:** Word dizisini toplarken yapılan hata quiz, ödev ve vize sınavında çok görüldü. Bu çok büyük bir hata olarak ortaya çıkıyor; buna dikkat edilmelidir.

Hocanın akıl yürütmesi şöyledir: eleman sayısı word tipinde olduğuna göre dizide en çok word kadar eleman olabilir. Her eleman da word'ün alabileceği en büyük değeri alabilir. Bu kadar sayıda en büyük değerin toplamı 16 bite sığmaz; 32 bitlik bir geçici yazmaçta tutulmalıdır. 8086 32 bitlik toplama ve bölme işlemlerini desteklemediği için 32 bitlik toplama yazılımla gerçeklenir. Bölüm ise en fazla word olur ve AX'e sığar.

> **Ders sonrası not:** Hoca word'ün en büyük değerini ve en çok eleman sayısını "65531" olarak söyledi; 16 bitlik işaretsiz en büyük değer 65535'tir. $65535 \times 65535 = 4\,294\,836\,225$ ve $2^{32} = 4\,294\,967\,296$ olduğundan toplam gerçekten 16 bite sığmaz ama 32 bite sığar (python ile doğrulandı).

Eleman sayısı word olduğuna göre 16 bitlik bölme yapılacaktır. 16 bitlik bölmede DX ve AX birlikte sanal bir 32 bitlik yazmaç gibi kullanılır. Bu yüzden 32 bitlik toplam DX yüksek word, AX düşük word olmak üzere DX:AX'te biriktirilir.

Kod (ekrandan, 00:50:00 ve 01:05:00):

```text
DIZI_ORT_F PROC FAR
        PUSH CX
        PUSH BX
        PUSH SI
        PUSH DX
        LEA SI, DIZI
        MOV CX, ELEMAN
        MOV BX, CX
        XOR AX, AX
        XOR DX, DX
TEKRAR: ADD AX, [SI]
        ADC DX, 0
        ADD SI,2
L1:     LOOP TEKRAR
        DIV BX
        POP DX
        POP SI
        POP BX
        POP CX
        RETF
DIZI_ORT_F ENDP
```

Dizinin başlangıç adresi SI'ya, eleman sayısı CX'e alınır. Döngü sonunda CX sıfırlanacağı için bölmede kullanılacak eleman sayısı `MOV BX, CX` ile BX'e kopyalanır. AX ve DX sıfırlanır.

İlk adımda AX 0 olduğu için `ADD AX, [SI]` sonucunda AX'e dizinin ilk elemanı gelir. Sıfırla toplamada elde oluşmaz, `ADC DX, 0` sonrasında DX 0 kalır. SI 2 artırılıp döngü başına dönülür. Sonraki elemanlar AX'e eklendikçe taşma, yani elde (carry) oluşabilir; `ADC DX, 0` bu eldeyi yakalayıp DX'te biriktirir. Hoca bunu onlu toplamaya benzetti: düşük basamaklardan elde çıkarsa bir sonraki basamağın toplamına eklenir.

Döngü bittiğinde DX:AX'te bütün elemanların toplamı vardır. `DIV BX` ile tamsayı bölmesi yapılır. Bölüm AX'te, kalan DX'te oluşur; DX kullanılmayacağı için orada çöp bir değer vardır. Bu yüzden DX, SI, BX ve CX'in orijinal değerleri sırasıyla geri çekilir ve dönüldüğünde AX'te ortalama bulunur.

### 6.3 DIZI_MAX_F

Üçüncü dosyada `DIZI_MAX_F` `PUBLIC`, DIZI ve ELEMAN word tipinde `EXTRN` tanımlıdır (ekrandan, 01:45:00). Ana gövde minimumu bulan gövdeyle aynıdır. SI ve CX geçici işlerde kullanılır ve korunur, sonuç AX'te döner. AX'e dizinin ilk elemanı, o ana kadar görülen en büyük eleman olarak alınır. İlk elemanla ilgili işlem yapıldığı için CX bir azaltılır. Sıradaki elemanlar AX ile karşılaştırılır: AX büyük ya da eşitse ("above or equal", `JAE`) sonraki elemana geçilir. AX daha küçükse `[SI]`'daki değer yeni en büyük eleman olarak AX'e alınır. Çıkışta SI ve CX girişteki sıranın tersine çekilir ve dönülür.

## 7. Derleme, Linkleme, MAP Dosyası ve Debug

### 7.1 Derleme ve linkleme

Dosyalar DOSBox içinde `MASM.EXE` ile tek tek derlendi: birinci dosya ana dosya, ikincisi minimumu, üçüncüsü ortalamayı, dördüncüsü maksimumu bulan dosyadır (dosya adları `301115_1_1.ASM` ... `301115_1_4.ASM`; DOS kısa adlarıyla `301115~1` ... `301115~4`). Üç alt dosya ve ana dosya için OBJ dosyaları oluştu. Sonra hepsi birlikte linklendi (ekrandan, 01:00:00):

```text
C:\MASM>c:\bin\LINK.EXE 301115~1.obj + 301115~2.OBJ + 301115~3.OBJ + 301115~4.OBJ
Run File [301115~1.EXE]: MOM
List File [NUL.MAP]: MOM
```

İlk denemede çalıştırılabilir dosyaya ad verilmediği için beklenen EXE oluşmadı; ikinci denemede EXE ve MAP dosyası "MOM" (minimum, ortalama, maksimum) adıyla oluşturuldu.

### 7.2 MAP dosyası

MAP dosyasında ana yordamdan gelen stack, data ve code segmentleri vardı. Alt yordam dosyalarında ise yalnız kod segmentleri vardı. Bunların adları aynı olsa da sınıfları farklı olduğu için farklı birer segment olarak tanımlandılar. Toplam 6 segment oluştu: üçü ana yordamın yığın, veri ve kod segmenti, diğer üçü alt yordamların kendi kod segmentleri. Hoca buna, aradan sonra segment birleştirme konusunda geri dönmek için baktığını söyledi.

### 7.3 Debug ile çalıştırma

Debug'da ana yordamda dönüş değerleri yığına atıldı, sonra veri segmenti ayarlandı. Veri segmentinin sıfırından dump yapıldığında dizinin word elemanları (13, 12, ...), ardından eleman sayısı 0AH (10) ve sonuçlar için ayrılan üç göz görüldü.

İlk `CALL` ile maksimumu bulan fonksiyona dallanıldı. İçeride DIZI'ye data segmentinin 0 offseti üzerinden erişiliyor. Fonksiyona girmeden önce DS 076EH idi, girildiğinde de 076EH oldu. Alt yordamın kendi veri segmenti olmadığı için yazmaçların aynen gelmesi sayesinde DS doğru veri segmentini gösterir. Hoca, bu program kendi içinde bir veri segmentine sahip olsaydı orada bir DS ayarlaması gerekebileceğini belirtti.

Adım adım yürütmede CX'e 10, AX'e dizinin ilk elemanı 13 okundu. Döngü bittiğinde AX'te 19H yani 25 vardı; orijinal dizinin en büyük değeri de 25'tir. Dönüşte yığından CX çekildiğinde CX girişteki 00FBH değerine döndü (ekrandan, 01:00:00 ve 01:05:00). Hoca bunu şöyle yorumladı: ana yordamda da alt yordamda da bir döngü olsaydı, ana yordamdaki sayaç ancak bu şekilde korunabilirdi. Dönüşte AX'teki 25 MAX gözüne yazıldı.

İkinci çağrı ortalamayı bulan fonksiyondu. Bölme işleminden sonra AX'te 000BH yani 11 kaldı; korunan değerler yığından çekildi ve `RETF` ile dönüldü. Ekranda `MOV [0018],AX` satırı görülüyor; 0018H ofseti, 10 word'lük dizi (14H bayt) ve ELEMAN'dan sonra gelen ORT gözüdür (ekrandan, 01:05:00). Ardından üçüncü fonksiyon `CALL 0773:0000` ile çağrıldı ve `g 0770:2e` komutuyla program sona kadar yürütüldü ("Program terminated normally").

Sonuçlar: MIN = 2, ORT = 11, MAX = 25. Python ile kontrol: dizinin toplamı 119'dur, $119 / 10 = 11$ (kalan 9); en küçük eleman 2, en büyük eleman 25'tir.

## 8. Üç Parametre Aktarım Yönteminin Özeti

Fonksiyon dışarıdan kullanılacaksa adı ve tipiyle `EXTRN` tanımlanıyordu. Dışarıdan kullanılacak değişkenler için de aynı şey geçerlidir: değişken adı ve tipiyle `EXTRN` olarak tanımlanır. Örneğin alt yordam dosyaları dışarıdan DIZI adlı word tipinde bir değişken kullanır; bu, word dizisinin başlangıç adresi olarak da okunabilir. ELEMAN da dışarıdan kullanılan ikinci word değişkendir. Karşı tarafta, değişkenlerin tanımlı olduğu yerde, tıpkı fonksiyonlarda olduğu gibi `PUBLIC` tanım yapılmalıdır. Bu şartlar sağlandığında fonksiyonlar da değişkenler de farklı dosyalarda tanımlanıp farklı dosyalardan kullanılabilir.

Böylece üç parametre aktarım yöntemi tamamlandı: yazmaç üzerinden, yığın üzerinden ve EXTRN/PUBLIC kelimeleriyle. EXTRN ve PUBLIC kullanımı büyük miktardaki veriyi parametre olarak aktarırken daha avantajlıdır.

Hoca aradan önce isteğe bağlı özyinelemeli EBOB ödevini yeni katılanlar için tekrar etti (Bölüm 4).

## 9. Kesim Birleştirme Neden Gerekir?

Aradan sonra kesim (segment) birleştirme konusuna geçildi. EXE ya da COM tipi bir programda tanımlanan her segment için bir yer ayrılır. Toplam $2^{16}$ farklı segment değeri olabilir ve her segment 64 KB'lık bir alanı kapsar; segmentler üst üste örtüşebilir ama kabaca her biri belli bir alan kaplar.

Segmentler yazılırken hizalama kodları kullanılır: BYTE, WORD, PARA, PAGE gibi. Bunlar segmentin sıradaki boş alandan, sıradaki 2'nin katı olan adresten, sıradaki 16'nın katı olan adresten ya da sıradaki 256'nın katı olan adresten başlamasını sağlar.

Hoca önceki örneğin veri segmentini Debug'da dump ederek gösterdi: 10 dizi elemanı, eleman sayısı ve üç sonuç değişkeninden sonra veri biter. Kod segmenti PARA hizalamasıyla başladığı için 16'nın tam katından başlar; aradaki iki word değeri (sıfır görünen) kullanılmaz, boş kalır.

Hizalamadan vazgeçmek de istenmez. Veriler hizalı olursa, örneğin word dizileri hep çift adreslerden başlarsa, mikroişlemcinin çift adresten 16 bit okuması tek adresten 16 bit okumasına göre iki kat hızlıdır. Bu hız farkından yararlanmak için hizalama gerekir; ama hizalama aralarda kullanılmayan boşluklar bırakır.

Bu nedenlerle, yani arada kalan boşluklar ve her segment tanımının segment uzayından yer kullanması yüzünden, segment birleştirmeye ihtiyaç duyulabilir.

## 10. Kod Segmentlerini Birleştirme

### 10.1 Birleştirme öncesi MAP

Hoca önceki örneğin MAP dosyasını segment segment inceledi (ekrandan, 01:50:00):

```text
 Start  Stop   Length Name     Class
 00000H 0003FH 00040H STACKSG  STACK
 00040H 0005BH 0001CH DATASG   DATA
 00060H 00081H 00022H CODESG   CODE
 00090H 000AAH 0001BH CODESG   CODE3
 000B0H 000D2H 00023H CODESG   CODE1
 000E0H 000FAH 0001BH CODESG   CODE2

 Program entry point at 0006:0000
```

- Yığın segmenti 64 bayttır; 0'dan 3FH'ye kadar gider, boyu 40H'dir. Tam hizalı olduğu için hiç fazladan yer harcanmamıştır.
- Veri segmentinde 14 değer vardır ve 28 bayt kaplar (1CH: C = 12, 12 + 16 = 28). 40H'den 5BH'ye kadar kullanılır, ama sonraki kod segmenti de PARA hizalı olduğu için 16'nın tam katından başlar ve 5CH ile 5FH arası kullanılamaz.
- Ana programın kod segmenti 60H'den 81H'ye kadar 22H yani 34 bayttır. 82H'den 8FH'ye kadar 14 baytlık alan, sonraki kod segmentinin 16'nın katından başlaması gerektiği için kullanılamaz. Bu durum diğer segmentler için de geçerlidir.

> **Ders sonrası not:** Hoca veri segmentindeki 14 değeri "14 tane byte" olarak saydı; bunlar 14 word'tür (10 dizi elemanı, ELEMAN, MIN, ORT, MAX) ve toplam 28 bayt kaplar.

### 10.2 Birleştirme şartları

Kod segmenti tanımında bir etiket (segment adı), `SEGMENT` anahtar kelimesi, hizalama parametresi ve sınıf adı vardır. Segmentlerin birleştirilebilmesi için etiketin, hizalama tipinin ve sınıf adının aynı olması gerekir. Dört dosya bu şekilde düzenlendi, her biri derlenip OBJ yapıldı ve birlikte linklendi. Hoca linklerken alt yordamlarda `END`'den sonra bir giriş noktası olmadığına, giriş noktasının yalnız ana yordamda bulunduğuna dikkat çekti. Yeni EXE ve MAP dosyaları `MOM_` adıyla oluşturuldu.

Ancak MAP'e bakıldığında segmentler birleşmemişti. Hoca bir süre nedenini aradı ve eksikliği buldu: dışarıya kullandırılan değişken ve fonksiyonlar için `PUBLIC` tanımı yapıldığı gibi, segment tanımında da birleştirme tipi olarak `PUBLIC` yazılmalıdır. Segment tanımı `CODESG SEGMENT PARA PUBLIC 'CODE'` biçiminde düzeltildi (ekrandan, 01:45:00).

> **Hocanın vurgusu:** Segmentleri birleştirmek için etiket, hizalama tipi ve sınıf adının yanında `PUBLIC` tanımlayıcısı da verilmelidir. Bu, derste tekrar görülerek üzerinden geçilen çok önemli bir noktadır.

> **Ek bilgi (derste anlatılmadı):** `SEGMENT` satırındaki bu alan "birleştirme tipi" (combine type) olarak bilinir. `PUBLIC` aynı ad ve sınıftaki segmentlerin linker tarafından ardışık yerleştirilip tek bir segment yapılmasını sağlar. Ana yordamdaki `STACK` de bir birleştirme tipidir.

### 10.3 Birleştirme sonrası MAP

Dosyalar yeniden derlenip linklendikten sonra MAP şöyle oldu (ekrandan, 01:40:00):

```text
 Start  Stop   Length Name     Class
 00000H 0003FH 00040H STACKSG  STACK
 00040H 0005BH 0001CH DATASG   DATA
 00060H 000FAH 0009BH CODESG   CODE

 Program entry point at 0006:0000
```

Orijinal durumda ana yordamın üç segmenti (code, data, stack) ve her alt yordamın ayrı birer kod segmenti vardı. Birleştirmeden sonra dört dosyanın kod segmentleri için tek bir kod segmenti oluştu. Hoca, önceden AAH-B0H, 81H-90H, D2H-E0H arasında kalan atıl alanlar olduğunu ve sonuncunun FAH'den sonra 100H'ye kadar boşluk bıraktığını belirtti; bunun dörtte birine düşürüldüğünü söyledi.

> **Ders sonrası not:** Ekrandaki iki MAP dosyasında birleşik CODESG'nin başlangıç ve bitişi (00060H-000FAH) birleştirme öncesiyle aynıdır. Birleşik uzunluk 9BH = 155 bayttır; dört parçanın toplamı ise 22H + 1BH + 23H + 1BH = 34 + 27 + 35 + 27 = 123 bayttır. Aradaki 32 bayt, parçaların her birinin PARA hizalamasını koruması yüzünden büyük olasılıkla birleşik segmentin içinde boşluk olarak kalmıştır. Yani bu örnekte toplam bellek kazancı büyük olasılıkla yoktur; asıl kazanç segment sayısının azalması ve çağrıların NEAR yapılabilmesidir. İç boşlukları gidermek için büyük olasılıkla alt dosyalarda BYTE ya da WORD hizalama kullanmak gerekir. Hoca da hizalama tiplerinin değiştirilerek etkisinin incelenebileceğini söyledi.

## 11. Birleşik Segmentte EXTRN ve NEAR Çağrı

Kod segmentleri birleşince bütün kodlar aynı segment içindeydi, oysa fonksiyonlar hâlâ FAR tanımlıydı. Hoca öğrencilere bu durumda akla bir soru gelip gelmediğini sordu.

### 11.1 EXTRN'e gerek kalıyor mu?

Bir öğrenci EXTRN yapmaya gerek kalıp kalmadığını sordu. Hoca bunu denedi: ana dosyadaki `EXTRN` satırı kaldırılıp yalnız o dosya MASM ile derlendi. MASM `error A2009: Symbol not defined` hatasını `DIZI_MAX_F`, `DIZI_ORT_F` ve `DIZI_MIN_F` için verdi; 3 ciddi hata (Severe Errors) oluştu (ekrandan, 01:45:00).

**Soru:** Kod segmentleri birleştiğine göre EXTRN tanımına gerek kalıyor mu? **Cevap:** Kalıyor. Bu dosya tek başına bir OBJ dosyasına derlendiği için içinde kullandığı fonksiyonların dışarıdan geleceğini bilmesi gerekir. EXTRN'e her durumda ihtiyaç vardır; bu deneyerek görüldü.

### 11.2 Fonksiyonlar NEAR yapılabilir mi?

Hoca soruyu tekrar sordu ve bir öğrenci doğru soruyu sordu: aynı segmentte olduklarına göre bu fonksiyonlar NEAR tipinde kullanılabilir mi? Yani çağrılar segment içi, NEAR `CALL` olabilir mi?

Önce yalnız kod segmentleri birleştirilmiş, başka hiçbir değişiklik yapılmamış sürüm Debug'da incelendi. Veri kesimi ayarları yapılıp `CALL` satırına gelindiğinde çağrının yine FAR olduğu görüldü. Bunun sebebi ana dosyada `EXTRN ...:FAR` yazılı olması ve fonksiyonların kendi dosyalarında FAR tanımlı olmasıdır.

Sonra fonksiyonların tipleri NEAR'a çevrildi, dönüşleri `RETF` yerine `RET` yapıldı. Hocanın belirttiğine göre çağırma satırlarında bir değişiklik yapmaya gerek yoktu. Dört dosya yeniden derlenip linklendi (yeni dosya `MOM__` adıyla). Debug'da veri kesimi ayarlarından sonra `CALL` satırına gelindiğinde çağrının artık NEAR yapıldığı görüldü.

<!-- BELİRSİZ: Bu son denemede ana dosyadaki EXTRN satırındaki tipin FAR olarak kalıp kalmadığı ya da NEAR'a çevrilip çevrilmediği altyazıdan ve karelerden anlaşılamıyor. -->

Hoca buradan bir sonuç çıkardı. Alt yordamların assembly kaynak kodu elde varsa, kod birleştirme yapılıp çağrılar NEAR'a çevrilebilir. Alt yordamların kaynak kodu yoksa ve yalnız açıklamasında içindeki fonksiyonun FAR olduğu bilinen bir OBJ dosyası varsa yapılacak bir şey yoktur.

## 12. Kesim Birleştirmenin Kazançları ve Veri Kesimi Birleştirme

Hoca kazançları birleştirme öncesiyle karşılaştırarak sıraladı.

Birleştirme öncesi:

- Dört dosya vardı; ana yordamın dosyasında üç segment, diğer dosyaların her birinde bir kod segmenti tanımı vardı. Her biri ayrı bir segment alanını işgal ediyordu.
- Hizalama tipi yüzünden sonraki segment hep 16'nın katında başlıyordu ve önceki segment 16'nın tam katında bitmiyorsa arada kullanılamayan alan kalıyordu: 5CH-60H, 82H-90H, ABH-B0H, D3H-E0H.
- Fonksiyonlar farklı dosyalarda, farklı segmentlerde olduğu için çağrılar FAR olmalıydı. FAR çağrıda dönüş için yığına hem segment hem offset atılır, IP ve CS değişir; dönüşte yığından iki değer çekilir.

Hoca hizalamanın neden önemli olduğunu tekrar açıkladı. Tek adresten 16 bitlik okuma ve yazma işlemci açısından ikiye bölünür: önce tek adresten 8 bit, sonra bir sonraki çift adresten 8 bit okunur, çünkü bu iki göz bellek arayüzünde aynı satıra denk gelmez. Çift adresten 8 bit ve bir sonraki tek adresten 8 bit ise aynı bellek satırına denk gelir; işlemci çift ve tek bloklardaki aynı numaralı satırları aynı anda etkinleştirip 16 biti tek seferde okur.

> **Ders sonrası not:** Hoca her segmentin "64 bitlik" bir alana denk geldiğini söyledi; bir segment 64 KB'lık bir alanı kapsar.

Birleştirme sonrası:

- Tek bir kod segmenti vardır.
- Hocaya göre dört kod segmenti arasındaki boşluklar giderilmiş, sonunda FBH'den 100H'ye kadar bir kerelik boşluk kalmıştır (bu konudaki not için Bölüm 10.3'e bakın).
- Bütün kodlar aynı segment içinde yer alabildiği için bütün fonksiyon çağrıları NEAR tanımlanabilir. NEAR çağrıda yığına yalnız offset atılır, alt yordama gitmek için yalnız IP'nin değişmesi yeterlidir ve dönüşte yalnız IP yığından çekilir.

Aynı işlem veri kesimlerini birleştirmek için de yapılabilir. Kural aynıdır: iki farklı dosyadaki veri segmentlerinin etiketleri, hizalama tipleri ve sınıf adları aynı olmalı ve mutlaka `PUBLIC` tanımlayıcısı kullanılmalıdır. Kazanç, segmentlerin hafızaya yerleşiminde hizalamadan kaynaklanan boş alanların birleştirilerek daha verimli kullanılmasıdır. Ancak iki dosya arasında veri paylaşımı yapılacaksa yine EXTRN ve PUBLIC kullanmak gerekir: veriyi tanımlayan dosyada `PUBLIC`, onu kullanan üç dosyada DIZI ve ELEMAN için `EXTRN` tanımı yine yazılmalıdır. Hoca, segment hizalama tiplerini değiştirerek etkilerinin ayrıca incelenebileceğini de ekledi.

Hoca son üç haftanın konularını şöyle özetledi: yazmaç üzerinden parametre aktarımı (EXE için görüldü ama COM için de geçerlidir), yığın üzerinden veri aktarımı, EXTRN/PUBLIC ile veri aktarımı ve bunların varyasyonlarının çalıştırma sonuçları; ardından fonksiyonları NEAR'a dönüştürme avantajı olan kod segmenti birleştirme ve aynı kurallarla veri segmenti birleştirme.

## 13. Sistem Reseti

8086'lı sistemlerde sistem resetlendiğinde bazı yazmaçlar özel başlangıç değerleriyle yüklenir. IP ve CS'nin başlangıç değerleri ve bunlardan hesaplanan fiziksel adres şöyledir (ekrandan, 02:00:00):

```text
CS <- 0FFFFH
IP <- 0000H

PA = (CSx10H) + IP
   =  0FFFF0H + 0000H
   =  0FFFF0H
```

Fiziksel adres, CS'nin 10H ile çarpılıp IP'nin eklenmesiyle bulunur. Böylece 20 bitlik reset vektörü 0FFFF0H olur. Hoca baştaki sıfırın da önemli olduğunu belirtti.

Bunun anlamı şudur: sistem ilk açıldığında bütün kontrolleri yapan ve eksiklikleri denetleyen BIOS bir ROM ile sağlanır. Bu ROM, adres uzayında 0FFFF0H adresini içerecek şekilde yerleşmeli ve tam bu adreste sistem açılışını ele almayı sağlayan dallanma komutu (`JMP`) bulunmalıdır.

Diğer yazmaçlarda bayrak yazmacının her biti sıfırlanır; DS, ES ve SS sıfır değerini alır.

Resetten sonraki adımlar:

1. Sistemdeki güç değerinin kararlı ve mantıklı bir değerde olup olmadığı denetlenir. Doğrulama işareti, yani "power good" sinyali gelirse sonraki aşamaya geçilir.
2. BIOS çipinin ilgili adresindeki `JMP` komutuyla BIOS sistemi devreye alır ve Power-On Self-Test (POST) işlemlerini yürütür: RAM, ekran kartı, bellek, sabit disk, klavye ve fare var mı gibi denetimler.
3. Sonra sistemi işletim sistemine devredecek dallanma yapılır.

## 14. Veri Aktarım Tipleri: Polling, Kesme, DMA

Dersin kalan kısmında bir sonraki konu olan kesmelere giriş yapıldı.

Mikroişlemci açısından üç farklı veri aktarım tipi vardır. Veri aktarımı derken örneğin bir G/Ç biriminden belleğe veri aktarımı düşünülebilir.

**Polling.** Klavye örneğinde bir tuşa basılır ve bu değerin bellekte belli bir bölgeye aktarılması gerekir. Yapılabilecek işlerden biri G/Ç cihazını sürekli denetleyip verinin hazır olup olmadığına bakmaktır: veri hazır mı, değil, tekrar bak; hazırsa oku. Bu, işlemciyi aktif olarak meşgul eder.

**Kesme.** İkinci seçenek işi kesmeyle ele almaktır. İşlemci G/Ç cihazını kesme üretecek şekilde, gelen kesmeyi de ilgili alt fonksiyonla değerlendirecek şekilde donanımsal olarak ayarlar ve bırakır. Sonra kendi işini yapar; örneğin ekranı sürer ya da hesaplama yapar. Tuşa basıldığında işlemciye bir kesme isteği gider. İşlemci ekran sürme işini geçici olarak bırakır, tuşu okuyup belleğe yazar ve kesmeye karşılık gelen fonksiyon yürütülmüş olur.

Hoca iki yöntemde de ortak bir noktaya dikkat çekti: veri G/Ç cihazından okunup işlemcinin içine kadar kopyalanır, sonra işlemciden bellek elemanına aktarılır. Yani her ikisinde de veri CPU'nun içinden dolaşır.

**DMA (Direct Memory Access).** Üçüncü yöntemde yardımcı bir devre, DMA denetleyicisi kullanılır ve veri aktarımında işlemci devreden çıkarılır. İşlemci denetleyiciyi hangi G/Ç adresinden hangi bellek adresine kaç veri yazılacağını belirtecek şekilde önceden programlar ve aktarım sırasında kontrolü DMA denetleyicisine devreder. Veri yolu ve adres yolunun kontrolünü denetleyici sağlar: G/Ç cihazının sıradaki adresinden okuma yapıp verinin veri yoluna çıkmasını sağlar, bellek elemanının da veriyi veri yolundan okumasını sağlar. Veri işlemciye kopyalanıp sonra belleğe gitmez; iki cihaz doğrudan birbirine bağlıdır.

Hocaya göre derste şimdiye kadar yapılan işlemlerde genel olarak polling mantığı kullanılmıştı. Kesme yapısı ise anlatılan mantık çerçevesinde çalışır. Hoca kullandığı slaytın Mikroişlemciler dersinde de kullandığı bir slayt olduğunu, kesme vektör tablosuna kadar olan kısmı açıklamak için uygun ve yeterli olduğunu söyledi.

## 15. Kesme Kaynakları

Slayttaki özet (ekrandan, 02:10:00):

```text
Kesme Kaynakları
- Yazılımsal olarak: INT, INTO, INT 3
- Donanımsal olarak: INTR, NMI
  - Donanım kesmesi ile ilgili acknowledge: INTA (aktif düşük)
- Kesme ile ilgili bayraklar: IF, TF
- Kesme ile ilgili dönüş komutu: IRET
```

Kesme kaynakları donanımsal ve yazılımsal olarak ikiye ayrılır. Yazılımsal kaynaklar da komuttan kaynaklananlar ve işlem sonucunda oluşanlar diye iki başlıkta incelenir.

### 15.1 Komuttan kaynaklanan yazılımsal kesmeler

`INT` komutu yanında 0 ile 255 arasında 8 bitlik bir sabit alır. Bu değer kesme tipini belirtir; yani komut, toplam 256 kesme tipinden istenenin tetiklenmesini sağlar. `INTO` (interrupt on overflow) gibi bazı özel komutlar ise parametre almaz; `INTO` taşma durumuna karşılık gelen kesme tipini tetiklemek için kullanılır. Slaytta ayrıca `INT 3` de yer alır.

### 15.2 İşlem sonucunda oluşan yazılımsal kesmeler

Bir bölme işleminde $x / 0$ yapılırsa, yani sıfıra bölme durumuyla karşılaşılırsa sıfıra bölme kesme tipi tetiklenir. Ayrıca işlem sonucunda taşma oluşursa da kesme oluşur: örneğin 16 bitlik bölmenin sonucu 16 bite sığmazsa.

Hoca burada öğrencilerden bir örnek istedi.

**Soru:** 16 bitlik bölme işleminde bölüm 16 bite sığmasın, AX'te taşma olsun; buna bir örnek verilebilir mi? **Cevap:** Bir öğrenci negatif değer önerdi; hoca negatif değer olmasının taşmayı garanti etmediğini söyledi. Doğru yolu gösteren bir öğrenci önerisini hoca şu örnekle somutlaştırdı (ekrandan, 02:15:00):

```text
MOV DX,100H
XOR AX, AX
MOV BX, 1
DIV BX

DX:AX = 100 0000H
DX:AX / 1 = 100 0000H
```

`DIV BX` komutunda DX:AX 32 bitlik sanal yazmacı BX'e bölünür ve bölüm AX'te saklanır. DX'te 100H, AX'te 0 olduğundan DX:AX = 1000000H olur. Bu 1'e bölündüğünde bölüm yine 1000000H'dir ve 16 bite, yani AX'e sığmaz; bölmede taşma olur. Hoca AX'i sıfırlamak için `MOV AX, 0` ya da `XOR AX, AX` yazılmasının fark etmediğini belirtti.

### 15.3 Donanımsal kesmeler: INTR ve NMI

Donanımsal kesmeler için işlemcinin iki fiziksel ucu vardır: INTR (interrupt request) ve NMI (non-maskable interrupt) (ekrandan, 02:20:00).

İşlemcinin NMI ucunda yükselen kenar görüldüğünde tip 2 kesmesi tetiklenir. NMI için hangi tipin çalışacağı hep sabittir.

INTR ucunda ise lojik 1 seviyesi belli bir süre bulunursa donanımsal kesme tetiklenir. Ancak hangi tip kesmenin tetikleneceğini işlemci ikinci bir çevrimde veri yolunun düşük anlamlı baytından okur. Hocanın örneği: klavyeyi okuyan bir çevre birimi düşünelim, tetikleme ucu INTR'ye bağlı olsun. Tuşa basıldığında işlemcinin INTR ucunda belli bir süre lojik 1 oluşur. İşlemci bir kesme isteği geldiğini anlar ama hangi tipin tetikleneceğini bilmez. Veri yolunun düşük 8 bitinden örnekleme yapar. Kesme tipleri 0-255 arasında olduğu için bu 8 bitlik değer hangi tipin tetikleneceğini belirlemeye yeter.

**NMI ne zaman kullanılır?** Adı üzerinde maskelenemez; yazılımla hiçbir şekilde kapatılamaz. Bu yüzden acil durumlar içindir. Örneğin resette "power good" sinyali gelmezse sistem açılmadan BIOS'un ilgili kesme programıyla kapatılabilir.

**INTR ne zaman kullanılır?** Normal çalışma sırasında çeşitli çevre birimlerinin kesme isteklerini almak için kullanılan tek uçtur. Bilgisayarda klavye, seri port, çeşitli denetim birimleri gibi pek çok çevre birimi vardır ve herhangi birinden kesme isteği gelebilir. Birden fazla kaynak olduğunda yardımcı bir devre, kesme denetleyicisi kullanılır. Denetleyici farklı kaynaklardan gelen istekleri alır, bunları işlemciye tek bir kesme isteği olarak bildirir ve her kaynak için atanmış kesme tipini veri yoluna çıkarır.

> **Ek bilgi (derste anlatılmadı):** 8086 tabanlı sistemlerde bu iş için genellikle Intel 8259A programlanabilir kesme denetleyicisi (PIC) kullanılır. Bir 8259A sekiz kesme isteği girişini toplayıp tek INTR çıkışına bağlar.

### 15.4 INTA ucu ve sinyalleşme

INTR işlemci açısından bir giriş ucudur. İşlemcinin bir de interrupt acknowledge ucu vardır: $\overline{INTA}$. Kesme tipinin ikinci çevrimde veri yolundan okunmasını tetikleyen bu uçtur. Sinyalleşme şöyle işler:

1. Çevre birimi INTR ucunda kesme isteği oluşturur.
2. İşlemci o anda ortasında kaldığı komutu bitirir.
3. İşlemci, gelen isteği değerlendirebileceği anlamında çevre birimlerine $\overline{INTA}$ onay işareti gönderir.
4. Çevre birimi onayı alınca kesme tipini veri yoluna çıkarır.

## 16. Kesme Bayrakları ve IRET

Kesmelerle ilgili iki önemli bayrak vardır: IF (interrupt flag) ve TF (trap flag).

NMI ucu maskelenemez; maskelenebilen kesme ucu INTR'dir. Maskeleme IF bayrağı ile yapılır. IF = 0 ise INTR ucundan gelen istekler değerlendirmeye alınmaz. INTR'den gelen donanımsal kesmelerin değerlendirilmesi için IF = 1 olmalıdır.

TF = 1 ise her komut yürütüldükten sonra tip 1 kesmesi tetiklenir. Bir komut yürütülür, tip 1 kesmesi oluşur; kesme alt programından dönülür, bir komut daha yürütülür ve TF hâlâ 1 olduğu için yine tip 1 kesmesi oluşur. Böylece her adımda bir "single step interrupt"a girilir. Bu bayrak adım adım debug yapmak için kullanılır.

Kesme isteklerine karşılık yürütülen kesme alt programlarının özel bir dönüş komutu vardır: `IRET` (interrupt return). Ayrı bir komut olması, `RET` ve `RETF`'ten farklı bir şey yaptığını gösterir:

- `RET` yığının tepesindeki değeri çekip IP'ye yazar.
- `RETF` tepedeki değeri IP'ye, sonraki değeri CS'ye yazar.
- `IRET` tepedeki değeri IP'ye, ikinci değeri CS'ye, üçüncü değeri de bayrak yazmacına yazar.

Buradan şu çıkar: kesme alt programları bir fonksiyon çağrısı gibi çağrılır, ama ondan farklı olarak yığına ayrıca bayraklar da atılır. Kesme fonksiyonuna gitmek için önce bayrak yazmacı, sonra geri dönüş segment değeri, sonra offset değeri yığına atılır. Örneğin işlemci ekranı sürerken kesme isteği gelir, kesme alt programına gidilir, işlemler yapılır ve kalınan yere dönülür. Dönüşte `IRET` yığından önce çektiği değeri IP'ye, sonrakini CS'ye, sonrakini bayrak yazmacına otomatik olarak yükler.

## 17. Kesme Vektör Tablosu

Slayttaki tanım (ekrandan, 02:30:00): kesme oluştuğunda mevcut CS:IP ile gösterilen kodun yürütülmesi bırakılarak kesmeye ilişkin fonksiyonun yer aldığı kesim ve offset değerindeki kod işlenmelidir. Her kesmeye ilişkin fonksiyonların hangi hafıza adresinde yer aldığı Kesme Vektör Tablosu ile tutulur.

8086'nın bir bellek bölgesi kesme vektör tablosu olarak ayrılmıştır. Bu tablo, kesme tiplerine karşılık çağrılacak fonksiyonların adreslerini tutar.

> **Hocanın vurgusu:** Kesme vektör tablosunda kesme fonksiyonlarının tanımı (kodu) yoktur. Tablo çok özettir ve çok az veri tutar: yalnız ve yalnız her kesme tipine karşılık çağrılacak fonksiyonun adres bilgisi vardır. Bu çok önemlidir.

256 kesme tipi olduğu için tabloda 256 göz vardır. Fonksiyonlar aynı segment içinde olmadığından her göz, bir FAR çağrıdaki gibi segment ve offset değerlerini içermelidir.

Tablo şöyle dolar: sistem açıldığında tablo boştur. Açılış BIOS'a devredilir; BIOS kendi kesme alt programlarının adreslerini tabloya yerleştirir ve denetimlerini yapar. Sonra sistemi örneğin DOS'a devreder. DOS açılırken kendi kesme fonksiyonlarını ilgili tiplerle eşleştirip adreslerini tablonun ilgili gözlerine yazar. İşletim sistemi açıldıktan sonra komut satırından kullanıcının kendi programı çalıştırılır. Program örneğin fare hareketleriyle ilgili özel işler yapacaksa, kendi kesme tiplerine karşılık yürütülecek kesme alt programlarının adreslerini de tabloya ekler.

**Soru (hocanın sorusu):** Kesme vektör tablosunun boyutu ne kadardır? **Cevap:** Bir öğrenci 8 dedi; hoca bunun yanlış olduğunu söyledi. 256 tip vardır ve her gözde segment ve offset değeri yani iki word bulunur. Doğru cevabı bir öğrenci verdi: $256 \times 4 = 1024$ bayt.

Tablo işlemcinin bellek uzayında 20 bitlik adres olarak 00000H'den başlayıp 003FFH'ye kadar, yani 0 ve 1023 dahil toplam 1024 baytlık alana yerleşiktir. Bu yüzden 0 adresinden itibaren 1024 baytlık alan için bellek uzayında uygun RAM ve ROM yapısının bulunması gerekir. Hoca bunu reset örneğine bağladı: orada 0FFFF0H adresini içerecek şekilde BIOS ROM'un yerleşik olması gerekiyordu, burada da benzer bir durum geçerlidir.

Bir kesme tetiklendiğinde işlemci her şeyi otomatik yapar. Örneğin NMI gelmişse tablonun 2 numaralı gözüne gider. INTR tetiklenmişse veri yolunun düşük 8 bitinden değer okur ve o numaralı kesme tipine gider. O gözden bir word alıp IP'ye, ikinci word'ü alıp CS'ye yazar ve ilgili kesme alt programına dallanmış olur.

> **Ek bilgi (derste anlatılmadı):** Tip $n$ için göz $4n$ adresinden başlar. İlk word (düşük adres) IP, ikinci word CS olarak yüklenir. Örneğin tip 2 (NMI) gözü 00008H-0000BH aralığındadır.

Tablonun genel yapısında (hocanın slayta dayalı anlatımı):

- Tip 0: sıfıra bölme.
- Tip 1: TF'den kaynaklanan, her komut yürütülmesinde tetiklenen kesme (single-step).
- Tip 2: NMI ucundaki yükselen kenarla gelen kesme istekleri.
- Tip 3: tek seferlik breakpoint'lere karşılık gelen kesme.
- Tip 4: taşma (overflow) olduğunda tetiklenen kesme.
- Bir bölge BIOS'a ya da DOS'a, belirli bir bölge de kullanıcıya ayrılmıştır.

<!-- BELİRSİZ: Tablonun genel yapısını gösteren slaytın (BIOS/DOS ve kullanıcıya ayrılan tip aralıkları) karesi yok; aralıkların sınırları altyazıda da verilmedi. -->

## 18. STI, CLI ve TF

Son olarak IF bayrağı için iki özel komut anlatıldı (ekrandan, 02:35:00). IF donanımsal kesmeleri açıp kapatmak için kullanılan bayraktır.

- `STI` (set interrupt flag): IF'i 1 yapar.
- `CLI` (clear interrupt flag): IF'i 0 yapar.

TF için özel bir komut yoktur. Hoca bunun için iki yol söyledi: `LAHF`/`SAHF` komutları, ya da bayrak yazmacının yığına atılıp yığında bit işlemi yapılması ve tekrar yığından bayrak yazmacına okunması. Slaytta bayrak yazmacının bit düzeni de vardı: bit 11 O, bit 10 D, bit 9 I, bit 8 T, bit 7 S, bit 6 Z, bit 4 A, bit 2 P, bit 0 C.

> **Ders sonrası not:** `LAHF` ve `SAHF` yalnız bayrak yazmacının düşük baytı (SF, ZF, AF, PF, CF) ile AH arasında aktarım yapar. TF, slayttaki düzende de görüldüğü gibi 8. bittedir ve bu komutlarla değiştirilemez. TF için geçerli yol hocanın andığı ikinci yöntemdir: `PUSHF` ile bayraklar yığına atılır, yığındaki değerin 8. biti değiştirilir, `POPF` ile geri yüklenir.

> **Ek bilgi (derste anlatılmadı):** 8086'da `INT n` ve donanım kesmesine girişte bayraklar yığına atıldıktan sonra IF ve TF otomatik olarak sıfırlanır. Böylece kesme alt programı kendisi adım adım kesilmez ve istenmedikçe yeni INTR istekleri kabul edilmez; `IRET` eski bayrakları geri yükleyince bu durum sona erer.

## Örnek Sorular

### Soru 1: FAR yordamda parametrelerin BP'ye göre yeri

(ekrandan, 00:25:00) Ana yordam `PUSH ASAYISI`, `PUSH BSAYISI`, `CALL _GCD_PROC` (FAR) yapıyor. Alt yordam girişte `PUSH BP`, `MOV BP, SP`, `PUSH AX`, `PUSH BX`, `PUSH DX` yapıyor. A ve B sayılarına BP'ye göre hangi adreslerle erişilir? Sonuç A'nın gözüne yazılıp çöp göz alt yordamca kaldırılacaksa dönüş komutu ne olmalıdır?

> **Çözüm (derste verildi):** BP'nin gösterdiği gözde eski BP, `BP+2`'de ana yordama dönüş IP'si, `BP+4`'te dönüş CS'si, `BP+6`'da B, `BP+8`'de A vardır. B `MOV BX, [BP+6]`, A `MOV AX, [BP+8]` ile okunur; adres SS ile hesaplanır. Sonuç `MOV [BP+8], AX` ile yazılır, yazmaçlar ters sırada çekilir ve `RETF 2` ile dönülür. Böylece B gözü atlanır ve ana yordam `POP SONUC` ile sonucu alır.

### Soru 2: Özyinelemeli EBOB (zorunlu olmayan ödev)

(derste sözlü, 00:32:19 ve 01:07:52) Ana yordamda da alt yordamda da parametre aktarımı yığın üzerinden olmak şartıyla, yığından parametre alıp sonucu yığından döndüren özyinelemeli EBOB alt yordamını assembly ile yazın. Verilen bir A, B ikilisi için Debug'da stack segmenti dump ederek yığının en derin halini inceleyin.

> **Çözüm (derste verilmedi):** Ödev olarak bırakıldı; burada kod verilmiyor. Derste kullanılan ikili için (A = 12, B = 8) beklenen sonuç python ile 4 olarak doğrulandı. Özyineleme $\gcd(x, y) = \gcd(y, x \bmod y)$, $\gcd(x, 0) = x$ ile $\gcd(12, 8) \to \gcd(8, 4) \to \gcd(4, 0) = 4$ zincirini izler. Yani ilk çağrıyla birlikte üç çağrı derinliği oluşur ve her derinlikte yığına parametreler ve dönüş adresi eklenir.

### Soru 3: Word dizisinin toplamı neye sığar?

(derste sözlü, 00:47:47) Bir word dizisinde en çok word kadar eleman olabiliyor ve her eleman en çok word'ün en büyük değerini alabiliyorsa, elemanların toplamı kaç bitlik bir yazmaca sığar? 8086'da bu toplam nasıl tutulur?

> **Çözüm (derste verildi, sayı ders sonrası düzeltildi):** Toplam 16 bite sığmaz, 32 bite sığar: $65535 \times 65535 = 4\,294\,836\,225 < 2^{32} = 4\,294\,967\,296$ (python ile doğrulandı). 8086'da 32 bit toplama komutu olmadığı için toplam DX:AX'te `ADD AX, [SI]` ve `ADC DX, 0` ile biriktirilir. Bölüm `DIV BX` ile AX'te elde edilir.

### Soru 4: Dizinin minimum, ortalama ve maksimumu

(ekrandan, 00:40:00) `DIZI DW 13, 12, 14, 25, 14, 12, 11, 4, 2, 12` ve `ELEMAN DW 10` için `DIZI_MIN_F`, `DIZI_ORT_F` ve `DIZI_MAX_F` yordamları AX'te hangi değerleri döndürür?

> **Çözüm (derste verildi):** Debug'da MIN = 2, ORT = 11 (000BH), MAX = 25 (19H) görüldü. Kontrol (python): toplam $119$, $119 / 10 = 11$ kalan 9; DX'teki kalan kullanılmaz.

### Soru 5: Kod segmentleri birleşince EXTRN ve NEAR

(derste sözlü, 01:42:19 ve 01:45:05) Dört dosyanın kod segmentleri `CODESG SEGMENT PARA PUBLIC 'CODE'` ile tek segmentte birleştirildi. (a) Ana dosyada `EXTRN` tanımına hâlâ gerek var mıdır? (b) Fonksiyonlar NEAR tanımlanabilir mi?

> **Çözüm (derste verildi):** (a) Evet. `EXTRN` kaldırılınca MASM `Symbol not defined` hatası verdi; her dosya tek başına derlendiği için dış adlar bildirilmelidir. (b) Evet. Fonksiyonlar NEAR yapılıp `RETF`'ler `RET`'e çevrilince Debug'da `CALL` NEAR göründü. Bu ancak alt yordamların kaynak kodu varsa yapılabilir. Yalnız segment birleştirilip fonksiyonlar FAR bırakılırsa çağrı FAR kalır.

### Soru 6: Reset vektörü

(ekrandan, 02:00:00) Resette CS = 0FFFFH ve IP = 0000H yüklenir. İlk komutun okunacağı 20 bitlik fiziksel adres nedir?

> **Çözüm (derste verildi):** $PA = CS \times 10H + IP = 0FFFF0H + 0000H = 0FFFF0H$. BIOS ROM bu adresi içerecek şekilde yerleşmeli ve burada bir dallanma komutu bulunmalıdır.

### Soru 7: 16 bitlik bölmede taşma örneği

(derste sözlü, 02:11:25; çözüm ekrandan, 02:15:00) 16 bitlik bir `DIV` işleminde bölümün AX'e sığmayıp taşma (bölme hatası kesmesi) oluşmasına bir örnek verin.

> **Çözüm (derste verildi):** `MOV DX,100H`, `XOR AX, AX`, `MOV BX, 1`, `DIV BX`. DX:AX = 1000000H; 1'e bölümü 1000000H olur ve 16 bite sığmaz. Negatif değer kullanmak tek başına taşmayı garanti etmez.

### Soru 8: Kesme vektör tablosunun boyutu ve yeri

(derste sözlü, 02:29:38) 8086'da kesme vektör tablosu kaç bayttır ve bellekte nerededir?

> **Çözüm (derste verildi):** 256 kesme tipi vardır, her gözde segment ve offset olmak üzere iki word (4 bayt) bulunur: $256 \times 4 = 1024$ bayt. Tablo 00000H ile 003FFH (0-1023) arasındadır.

## Dersin Toparlaması

Bu derste önce alt yordamlarda geçici kullanılan yazmaçların yığında korunması kuralı ve yığın üzerinden parametre aktarımının bütün varyasyonları tekrar edildi. EBOB örneğinde BP ile sabitlenen yığın çerçevesi göz göz çizildi. Ardından üçüncü parametre aktarım yöntemi olarak EXTRN/PUBLIC ile veri paylaşımı, ayrı dosyalardaki minimum, ortalama ve maksimum yordamlarıyla uygulandı. Word dizisinin toplamının DX:AX'te `ADC` ile 32 bit tutulması özellikle vurgulandı. Aynı örnek üzerinde kesim birleştirme gösterildi: aynı ad, hizalama ve sınıf ile `PUBLIC` birleştirme tipi verilince kod segmentleri tek segmentte toplandı ve yordamlar NEAR çağrılabildi, ama dosyalar arası adlar için `EXTRN` yine gerekti. Veri segmentlerinin de aynı kurallarla birleştirilebileceği belirtildi.

Dersin son bölümünde sistem reseti (CS:IP = FFFF:0000, ilk komut 0FFFF0H'de, POST ve işletim sistemine devir) ve kesmelere giriş işlendi: polling, kesme ve DMA ile veri aktarımı; yazılımsal ve donanımsal kesme kaynakları, INTR/NMI/$\overline{INTA}$ sinyalleşmesi, IF ve TF bayrakları, `IRET` ve 1024 baytlık kesme vektör tablosu. Hoca bir sonraki derste kesmelerle, özellikle kesme vektör tablosu ve kesme işleminde yürütülen adımlarla devam edileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
