# Ders 14 Çalışma Özeti

## Genel Konular

- Ders bağlamı: yordamlar arası parametre aktarımından kod kesimlerinin birleştirilmesine geçiş
  - Önceki haftalarda yordamlar arası parametre aktarma yöntemleri, `EXTRN`/`PUBLIC` ile değişken paylaşımı ve yığın üzerinden parametre gönderme işlendi.
  - Bu derste farklı dosyalarda ve farklı kod kesimlerinde yazılan yordamların tek bir kod kesiminde nasıl birleştirildiği, iki EXE tipi örnek üzerinden ve MAP dosyası incelenerek anlatıldı.
- Örnek 1: word dizide byte tanımlı bir elemanın kaç kez geçtiğini bulan program (ekrandan, 00:30:00)
  - Soru: "Word tanımlı bir dizide byte tanımlı bir elemanın kaç kez geçtiğini bulan EXE tipi ASM programını yazınız. Dizinin adresini, eleman sayısını ve aranan sayıyı stack'e atan ve sonucu AX üzerinden döndüren bir harici yordam kullanınız. Kod kesimini ortak alan olarak belirleyecek ek işlemleri gerçekleştiriniz."
  - Deneme verisi: `dizi DW 12, 12, 12, 12, 12, 12, 13, 14, 15, 16, 17`, `n DW 11`, `aranan DB 12`, `sonuc DW ?` (ekrandan, 00:45:00, 01:15:00). 12 için sonuç 6, 13 için 1, 18 için 0 bekleniyor ve DEBUG'da bu sonuçlar görüldü.
  - Sayma yordamının akış diyagramı: `TMP = 0`; `i = 0 .. n-1` için `dizi[i] == aranan` ise `TMP++`; sonunda `TMP` döndürülür. TMP burada AX'tir.
  - Sınav sorularında dizi `300 elemanlı` gibi verilirse amaç eleman sayısının 255'ten büyük olduğunu, yani `n`'in word tanımlanması gerektiğini ima etmektir. Böyle bir dizi `DW 300 DUP(?)` ile tanımlanabilir.
- Byte değeri word'e genişletme: işaretsiz ve işaretli durum (ekrandan, 00:40:00)
  - Yığına yalnız word atılabildiği için `PUSH aranan` (byte) yazılamaz. `n` word olduğu için `PUSH n` yazılabilir.
  - İşaretsiz sayı: `XOR AX, AX` / `MOV AL, aranan` / `PUSH AX`. AH sıfır olur, değer korunur.
  - İşaretli sayı: `MOV AL, aranan` / `CBW` / `PUSH AX`. `CBW` (convert byte to word) operand almaz; AL'nin en anlamlı biti 1 ise AH'nin bütün bitlerini 1, 0 ise 0 yapar.
  - Örnek: `AL = 10110011b`. İşaretsiz okunursa $128+32+16+2+1 = 179$. İşaretli okunursa ikiye tümleyen ile $01001100 + 1 = 01001101 = 77$, yani $-77$; ya da $179 - 256 = -77$. Bu sayıya AH = 0 eklenirse en anlamlı bit 0 olur ve sayı pozitif 179'a döner; işaret ancak `CBW` ile korunur.
  - `CBW` yalnız AL'yi AX'e genişletir; `CBW BL, BX` gibi bir kullanım yoktur.
- Ana yordam ve harici yordam (ekrandan, 00:45:00, 01:10:00)
  - Ana yordam sırasıyla `n`'i, word'e çevrilmiş `aranan`'ı ve `LEA AX, dizi` ile dizinin adresini yığına atar, `CALL SAY` ile yordamı çağırır, dönen değeri `MOV sonuc, AX` ile yazar.
  - Harici yordam başka dosyada olduğu için ana dosyada `EXTRN SAY:FAR`, yordamın dosyasında `PUBLIC SAY` yazılır.
  - Yordam içinde `PUSH BP` / `MOV BP, SP` sonrası parametreler: `[BP+2]` dönüş ofseti, `[BP+4]` CS, `[BP+6]` dizinin adresi, `[BP+8]` aranan, `[BP+10]` n.
  - Kullanılan yazmaçlar (CX, DI, BX) yığına atılıp sonda ters sırayla geri alınır. AX sonuç taşıdığı için saklanmaz.
  - Döngü: `XOR AX, AX` / `L1: CMP BX, [DI]` / `JNE atla` / `INC AX` / `atla: ADD DI, 2` / `LOOP L1`. Dizi word olduğu için DI 2 artar.
  - `RETF 6`: RETF yığından 4 byte (IP ve CS) çeker, 6 ise ana yordamın attığı 3 word'ü (6 byte) temizler; toplam 10 byte.
- Yığın çerçevesi ve BP'nin sabit kalması (ekrandan, 00:55:00, 01:00:00)
  - `MOV BP, SP` parametre okumadan önce yapıldığı için, ardından CX, DI, BX yığına atılsa da BP aynı yeri gösterir; BP'ye göre ofsetler değişmez.
  - Ofsetler, değerler BP'nin üstüne itildikten sonra BP kurulursa değişir (önceki hafta öyle bir örnek yapıldı).
- MAP dosyası ile kesim yerleşimi (01:05:00 - 01:12:17)
  - Bağlama (LINK) sırasında komut satırının sonuna noktalı virgül konmazsa MAP dosyası adı sorulur; MAP dosyası kesimlerin fiziksel adresini ve boyutunu gösterir.
  - Yığın kesimi `DW 20 DUP(?)` = 40 byte = $28_h$. Sonraki kesim $28_h$ yerine $30_h$'tan başlar, çünkü hizalama tipi `PARA`'dır (16'nın katı). `BYTE` verilseydi $28_h$'tan, `PAGE` verilseydi $100_h$'tan başlardı.
  - Veri kesimi $1B_h = 27$ byte: dizi $11 \cdot 2 = 22$, `n` 2, `aranan` 1, `sonuc` 2 byte.
  - Birleştirmeden önce iki ayrı kod kesimi görülür ($21_h$ ve $22_h$ byte).
- Kod kesimlerini birleştirme: `PUBLIC` birleştirme tipi (ekrandan, 01:10:00, 01:15:00)
  - Her iki dosyadaki kod kesimi tanımına sınıf adından önce `PUBLIC` eklenir: `mycs SEGMENT PARA PUBLIC 'code'`. Kesim adları ve sınıf adları aynı olmalıdır; hizalama tiplerinin de aynı olması istenir.
  - Birleştirmeden sonra MAP dosyasında tek kod kesimi kalır, boyutu $52_h$ olur. Bu $21_h + 22_h$ değildir: ilk parça `PARA` hizalaması yüzünden $30_h$'a kadar yer kaplar, $30_h + 22_h = 52_h$.
  - Hizalama `BYTE` yapılınca ikinci yordam ilk parçanın hemen bittiği yerden başlar; DEBUG'da `RETF`'nin hemen ardından yordamın `PUSH BP` komutu görülür.
  - Birleştirmeden sonra uzak çağrı aynı CS değerine yapılır; aynı kesim içinde olduğu için başka bir yordamın içindeki bir ofsete bile dallanılabilir.
- Örnek 2: her elemanı, ikili gösterimindeki 1 sayısına bölen program (ekrandan, 01:35:00 - 01:55:00)
  - Dizi: `dizi DW 0FAh, 0FFh, 0ABh, 12h, 16h`, `n DW 5`. Sonuç aynı dizinin üzerine yazılır.
  - Ana yordam: `XOR SI, SI` / `MOV CX, n` / `L1: PUSH dizi[SI]` / `CALL SAYveBOL` / `MOV dizi[SI], AX` / `ADD SI, 2` / `LOOP L1`.
  - Yordam 1'leri sayar: `XOR BX, BX` / `MOV CX, 16` / `L1: SHR AX, 1` / `ADC BX, 0` / `LOOP L1`. Kaydırılan bit CF'ye düşer, `ADC` ile toplanır.
  - 16 kez `SHR` sonrası kaydırılan yazmaç 0 olur; değer yığından tekrar okunur. `ROR` ile döndürülseydi değer korunurdu.
  - Elemanlar işaretli olduğu için bölme `CWD` / `IDIV BX` ile yapılır: `CWD`, AX'i işaretini koruyarak DX:AX'e genişletir; bölüm AX'e, kalan DX'e düşer. DX'i sıfırlamak işaretli sayıda işareti bozar.
  - Eleman 0 ise 1 sayısı da 0 olur; `IDIV` sıfıra bölme hatası verir. Bu yüzden `CMP BX, 0` / `JE sorunvar` ile kontrol edilir ve AX = 0 döndürülür.
  - Sonuçlar: $FA_h = 250$, 6 tane 1, $250 / 6 = 41 = 29_h$; $FF_h = 255$, 8 tane 1, $255 / 8 = 31 = 1F_h$. DEBUG'da 29 ve 1F görüldü.
  - Yordam bir parametre aldığı için `RETF 2` ile döner.
- Aynı kesimde yakın (NEAR) yordam (ekrandan, 01:55:00)
  - Kesimler birleştirildiğinde harici yordam `PROC NEAR` tanımlanabilir ve `RET 2` ile döner; `CALL` artık yalnız ofset yazar.
  - Yakın çağrıda CS yığına atılmaz; parametre `[BP+6]` yerine `[BP+4]`'tedir. Bu düzeltilmeden çalıştırılınca sonuçlar bozuk çıktı, düzeltilince 29 yeniden görüldü.

## Hocanın Özellikle Vurguladığı Kısımlar

- Yığına yalnız word atılır
  - Byte tanımlı bir değer `PUSH` ile atılamaz; önce AX'e genişletilir. İşaretsizse AH sıfırlanır, işaretliyse `CBW` kullanılır.
- `CBW` ve `CWD` işareti koruyarak genişletir
  - Negatif bir sayının üst yarısını 0 yapmak sayıyı pozitife çevirir. İşaretli bölmede `CWD` + `IDIV`, işaretsiz bölmede DX'i sıfırlayıp `DIV` kullanılır.
- Veri kesimi boyutunun hesabı
  - Hoca bu tür boyut hesaplarının sınavda sorulduğunu söyledi: eleman sayısı × eleman boyutu ve tek tek değişkenlerin boyutları toplanır, sonuç onaltılık yazılır.
- Yığının temizlenmesi
  - Ana yordamın attığı parametreleri yardımcı yordam `RETF n` / `RET n` ile temizler. `n` byte cinsindendir (3 word için 6).
- Sıfıra bölme kontrolü
  - Bölmeden önce bölen 0 mı diye bakılmalıdır; aksi halde program bir kesme ile durdurulur. Ödev ve sınavlarda da karşılaşılabilir.
- NEAR yordamda ofset değişir
  - Yakın çağrıda yığında CS olmadığı için parametre ofsetleri 2 azalır.

## Kısa Tekrar Notları

- `EXTRN SAY:FAR` (çağıran dosya), `PUBLIC SAY` (yordamın dosyası).
- FAR yordamda `PUSH BP` / `MOV BP, SP` sonrası: `[BP+2]` IP, `[BP+4]` CS, `[BP+6]` son atılan parametre.
- NEAR yordamda: `[BP+2]` IP, `[BP+4]` son atılan parametre.
- `RETF 6` = 4 byte dönüş adresi + 6 byte parametre = 10 byte yığından çekilir.
- `CBW`: AL → AX; `CWD`: AX → DX:AX; ikisi de operand almaz.
- $10110011_b$: işaretsiz 179, işaretli $-77$.
- `PARA` hizalaması: kesim 16'nın katında başlar; `BYTE`: hemen bitişte; `PAGE`: 256'nın katında.
- Kod kesimi birleştirme: aynı kesim adı + aynı sınıf adı + `PUBLIC`.
- 1'leri sayma: `SHR`/`ROR` ile CF'ye kaydır, `ADC BX, 0` ile topla, 16 kez.
- Bölmeden önce bölen 0 kontrolü.

## Detaylı Açıklamalar

- Örnek 1'de ana yordamın görevi yalnız parametreleri hazırlamak ve sonucu yazmaktır. `n` word olduğu için doğrudan `PUSH n` yazılabilir. `aranan` byte olduğu için önce AX'e alınır: işaretsiz kabul edilirse `XOR AX, AX` ile AH sıfırlanıp `MOV AL, aranan` yapılır; işaretli kabul edilirse `MOV AL, aranan` ve `CBW` yazılır. Dizinin adresi `LEA AX, dizi` ile alınır; bu, C'deki dizi işaretçisine karşılık gelir. Yordam çağrıldıktan sonra sonuç AX'ten `sonuc` değişkenine yazılır.
- Yordamın içinde parametreler BP üzerinden okunur. Yığın sırası (alttan üste): DS, 0 (EXE dönüş bilgisi), n, aranan, dizinin adresi, dönüş CS'si, dönüş IP'si, eski BP. `MOV BP, SP` bu noktada yapılır. Sonra CX, DI ve BX yığına atılır ama BP yerinde kaldığı için `[BP+6]`, `[BP+8]`, `[BP+10]` ofsetleri geçerli kalır. CX'e `n`, DI'ye dizinin adresi, BX'e word'e çevrilmiş `aranan` alınır. `CMP BX, [DI]` köşeli parantez nedeniyle DI'nin gösterdiği adresten bir word okuyup BX ile karşılaştırır.
- Derste ilk yazımda `L1` etiketi `XOR AX, AX` satırına konmuştu; her turda sayaç sıfırlanacağı için bir öğrencinin uyarısıyla etiket `CMP` satırına taşındı.
- Derlemede iki dosya ayrı ayrı `MASM` ile derlenir, `LINK` aşamasında `+` ile birlikte bağlanır, `DEBUG` ile incelenir. Birleştirmeden önce DEBUG'da ana kod kesimi ile yordamın kesim değerleri farklıdır (farklı CS'ye uzak çağrı). Veri kesiminin dökümünde dizi elemanları little endian olarak (`0C 00 ...`), ardından `n = 0B 00`, `aranan = 0C`, `sonuc` görülür.
- Kod kesimlerini birleştirmenin yararı: her harici yordam ayrı bir kesim olarak 64K'lık ayrı bir alan anlamına gelir. C'de `stdio.h` ile `printf`/`scanf` hazır kullanıldığı gibi assembly'de de birçok yordam ayrı dosyalarda yazılır; `EXTRN`/`PUBLIC` ve `PUBLIC` birleştirme tipiyle bağlama aşamasında tek bir kod kesiminde toplanabilir. Aynı kesim içinde olunca yakın çağrı ve yakın dallanma kullanılabilir.
- Örnek 2'de ana yordam her elemanı yığına atıp `SAYveBOL` yordamını çağırır, dönen AX'i aynı elemanın yerine yazar. Yordam, elemanı AX'e alır, BX'i sıfırlar ve 16 kez `SHR AX, 1` / `ADC BX, 0` yaparak 1'leri BX'te sayar. Sonra eleman yeniden AX'e alınır, BX sıfırsa AX = 0 döndürülür; değilse `CWD` ile DX:AX'e genişletilip `IDIV BX` ile bölünür. Kullanılan BX, CX, DX yığında saklanır ve ters sırayla geri alınır.
- Kesimler birleştirildiğinde yordam `PROC NEAR` yapılabilir. Bu durumda `CALL` yalnız ofset atar, dönüş `RET 2` olur ve parametre `[BP+4]`'e kayar. Derste ofset güncellenmeden çalıştırıldığında yanlış sonuç alındı; bir öğrencinin uyarısıyla `[BP+4]` yapılınca doğru sonuç (ilk eleman için $29_h$) elde edildi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
