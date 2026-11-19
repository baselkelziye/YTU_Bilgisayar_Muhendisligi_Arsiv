# Ders 8 Çalışma Özeti

## Genel Konular

- Veri tanımlarında eleman sayısı ve eleman tipi
  - Problemde verilen eleman sayısı ve tipi kodu doğrudan değiştirir. 200 elemanlı bir dizinin eleman sayısı byte'a sığar, ama byte'a sığmayan eleman sayıları da verilebilir. Bu yüzden eleman sayısı ve tipine birebir uyulmalıdır.
  - Çok elemanlı dizilerde her eleman tek tek yazılmaz. Bir kısmı yazılıp kalanı `DUP` ile sabit bir değerle tanımlanabilir.
  - Eleman sayısı byte olarak tanımlanırsa CX'e doğrudan atanamaz. Önce CX sıfırlanır, sonra sayı CL'ye yazılır. Bu yüzden derste eleman sayıları word olarak tanımlandı.
- EXE tipi programların tekrarı (ekrandan, 00:25:00)
  - Şablon: `STACKSG SEGMENT PARA STACK 'STACK'` / `DW 32 DUP(?)`, `DATASG SEGMENT PARA 'DATA'`, `CODESG SEGMENT PARA 'CODE'`, `ASSUME CS:CODESG, DS:DATASG, SS:STACKSG`, `BASLA PROC FAR`, `PUSH DS`, `XOR AX,AX`, `PUSH AX`, `MOV AX, DATASG`, `MOV DS, AX`, `RETF`, `END BASLA`.
  - Üç segment olur: yığın, veri ve kod. Yalnız yazmaçlarla çalışan bir programda veri segmenti gerekmeyebilir.
  - Hizalama: BYTE sıradaki boş adres, WORD sıradaki çift adres, PARA 16'nın katı, PAGE 256'nın katı. PARA ile hizalanan segmentler arasında 16'nın katına kadar kullanılmayan (çöp) byte'lar kalır.
  - Yığın segmentini yığın yapan `STACK` kelimesidir. Segment adı ve tırnak içindeki sınıf adı keyfidir; sınıf adı segment birleştirmede önem kazanır.
  - Kod segmentini kod segmenti yapan, `END`'den sonra gelen giriş noktası etiketinin o segmentte olmasıdır.
  - Veri segmentini veri segmenti yapan `MOV AX, DATASG` ve `MOV DS, AX` satırlarıdır. DS'ye doğrudan sabit atanamaz, bir yazmaç üzerinden atanır.
  - Program yüklendiğinde DS işletim sistemine dönüş segmentini tutar, dönüş ofseti 0'dır. Dönüş adresini yığına koymak EXE programın kendi sorumluluğudur. Bu yüzden ana yordam FAR olur ve `RETF` yığından önce IP'yi, sonra CS'yi çeker.
  - Yığına yalnız word atılıp çekilir; `PUSH AL` diye bir komut yoktur. Bu yüzden yığın boyutu çift sayıda byte olmalıdır.
- Dönüş ofsetinin neden 0 olduğu
  - Aynı 20 bitlik fiziksel adres farklı segment:ofset çiftleriyle yazılabilir. Örneğin FFFF0H hem `FFFF:0000` hem `FAAA:5550` ile gösterilir.
  - Her adres segment + 0 ofset biçimine normalize edilebildiği için dönüş adresinin ofseti 0 kabul edilir. Böylece ofset için ikinci bir yazmaç harcanmaz. Hoca bunu bir yazılım tasarımı kararı olarak yorumladı.
- EXE programda yığın göstergesi (ekrandan, 00:50:00)
  - 32 word'lük (64 byte) yığında SP başlangıçta yığın boyutu kadardır, yani yığının hemen dışını gösterir. SP "sıradaki dolu gözü" gösterir.
  - PUSH ile SP ikişer azalır, POP ile ikişer artar. Yığın dolduktan sonra veri atılmaya devam edilirse başka segmentlerin verisi ezilir.
- COM tipi programlar (ekrandan, 00:40:00 ve 00:55:00)
  - Tek segment vardır. Bu segment içinde header, kod, veri ve yığın birlikte bulunur. EXE'ye göre derlenmiş boyut daha küçüktür; EXE'nin ayrıca bir header'ı ve hizalama boşlukları vardır.
  - COM programlar segment içi (intra segment) çalışır. Uzak segmentlerle çalışılacaksa EXE daha uygundur.
  - Şablon 1: `CODESG SEGMENT PARA 'CODE'`, `ORG 100H`, `ASSUME CS:CODESG, SS:CODESG, DS:CODESG, ES:CODESG`, `BASLA PROC NEAR` ... `RET`, `BASLA ENDP`, ardından veri tanımları, `CODESG ENDS`, `END BASLA`.
  - `ORG 100H` sonraki satırların 100H ofsetinden itibaren yerleşmesini sağlar. İlk 100H (256) byte header içindir.
  - Ana yordam NEAR'dır ve `RET` ile döner. İşletim sistemi COM programı near olarak çağırır ve dönüş ofsetini yığına kendisi koyar. Bu değer 0000H'dır.
  - SP başlangıçta FFFEH'dır: segmentin en uç adresi tek sayı olan FFFFH'dır ve yığına zaten bir word (dönüş ofseti) atılmıştır.
  - Yığın segmentin sonundan aşağı doğru büyür. Kontrolsüz yığın kullanımı (örneğin takibi yapılmayan özyineleme) önce veri tanımlarını, sonra kodu bozabilir.
- COM şablon 2 (ekrandan, 01:00:00)
  - Şablon 1'de veri prosedürlerden sonra geldiği için DEBUG'da verinin ofsetini bulmak üzere bütün prosedürlerin makine kodu boyutu hesaplanmalıdır.
  - Şablon 2'de `ORG 100H`'dan hemen sonra `BILGI: JMP BASLA` yazılır, veri tanımları onun ardından gelir, `END BILGI` ile giriş noktası verilir. Veri her zaman 100H'dan sonraki birkaç byte'lık JMP kodunun hemen arkasında başlar.
- COM ve EXE karşılaştırması (ekrandan, 01:05:00 ve 01:10:00)

  ```text
  Özellik                  COM programı                       EXE programı
  Kullanılabilen bellek    64KB - Header - Dönüş adresi       Boş bellek
  Başlangıçta CS           Header'ın bulunduğu kesim          END'den sonraki etiketin kesimi
  Başlangıçta IP           100H                               END'den sonraki etiketin ofseti
  Başlangıçta DS           Header'ın bulunduğu kesim          Dönüş için gerekli kesim değeri
  Değişkenlere erişim      Yok                                MOV AX, verikesimismi / MOV DS, AX
  Değişkenlerin yeri       ENDP'den sonra                     Veri kesiminde
  Başlangıçta SS           Header'ın bulunduğu kesim          Yığın kesimi adresi
  Başlangıçta SP           0FFFEH                             Yığın kesimi boyutu
  Başlangıçta yığın        0000H                              Boş
  Yığın büyüklüğü          64KB - 256 - X byte kod - Y byte   Yığın kesimi boyutu
  Ana prosedür tipi        NEAR                               FAR
  Dönüş için yapılacak     Yok                                PUSH DS / XOR AX, AX / PUSH AX
  ```

  - EXE'de IP 0 olmak zorunda değildir: ana yordam yardımcı yordamlardan sonra tanımlanmışsa IP onun ofsetiyle başlar.
- emu8086'da komutların "değişmesi"
  - Disassembly bir komutun ortasından başlatılırsa makine kodu yanlış yerden çözülür ve komutlar başka komutlar (ADD, AND, RET gibi) olarak görünür. Örneğin bir sonraki byte'taki `C3` kodu RET olarak okunur. Kod doğru ofsetten başlatılırsa sorun olmaz.
  - Yazılan kod parçasının sonundan sonra gelen programlanmamış bellek gözleri de çöp değerlerden komut gibi çözülür.
- Örnek 4: COM tipi programla en büyük ortak bölen (ekrandan, 01:45:00 – 02:25:00)
  - Tanım: $\gcd(x, 0) = x$ ve $\gcd(x, y) = \gcd(y, x \bmod y)$. Örnek: $\gcd(12, 28) = \gcd(28, 12) = \gcd(12, 4) = \gcd(4, 0) = 4$.
  - Akış: x < y ise takas; y sıfır olmadığı sürece `t = x % y`, `x = y`, `y = t`; sonuç x.
  - Veri: `X_DIZI DW 28, 0FFFFH, 1, 100, 511`, `Y_DIZI DW 12, 0FFFH, 28, 25, 3`, `ELEMAN DW 5`, `GCD_DIZI DW 5 DUP(0)`.
  - Kodda tek indis SI kullanıldı (`DIZI_X[SI]` biçimi), böylece DI ve BX boşa çıktı. Takas için `CMP AX, DX` / `JAE L2` / `XCHG AX, DX`; döngü için `CMP DX, 0` / `JE L3`, `MOV BX, DX`, `XOR DX, DX`, `DIV BX`, `MOV AX, BX`, `JMP L2`.
  - Sonuçlar: 4, 0FH (15), 1, 19H (25), 1.
- MASM ile COM programı derleme ve DEBUG
  - Sıra: `masm` ile OBJ ve LST, `link` ile EXE (LINK "no stack segment" uyarısı verir), sonra `exe2bin` (DOSBox'ta exe2com) ile COM.
  - LST'de `ORG`, `ASSUME` ve segment satırları makine kodu üretmez. İlk makine kodu `JMP BASLA` satırıdır: `EB 21 90`, yani kısa JMP ve bir NOP. Değişkenlerin ofsetlerinde `R` (görece) vardır, ama EXE'deki `---- R` gibi yüklemede belli olacak değer yoktur.
  - Giriş etiketiyle 100H arasına bir tanım konunca dönüştürme "cannot convert" hatası verdi. COM programında giriş noktası tam 100H'da olmalıdır.
  - DEBUG'da başlangıçta CS = DS = ES = SS (075AH), IP = 0100H, SP = FFFEH görüldü. `D SS:FFFE` ile yığındaki dönüş ofsetinin `00 00` olduğu görüldü (ekrandan, 02:15:00).
  - `G CS:<ofset>` ile kod belli bir ofsete kadar çalıştırıldı, `D DS:100` ile veri incelendi.
- Örnek 5: 500 elemanlı word dizisinin ortalaması (ekrandan, 02:40:00 – 02:50:00)
  - Veri: `DIZI DW 0FFFFH, 100, 28, 1, 0, 495 DUP (256)`, `ELEMAN DW 500`, `ORT DW 0`. `DUP`'ta tekrar sayısı başa yazılır; `DUP 495 (256)` yazımı hata verdi.
  - Toplam 16 biti aşabileceği için DX:AX sanal 32 bitlik yazmacında biriktirilir: `ADD AX, [SI]` ve `ADC DX, 0`. Sonra `DIV BX` ile eleman sayısına bölünür; bölüm AX'te, kalan DX'tedir.
  - Toplam 2EF80H, bölüm 180H (384), kalan da 180H çıktı. Ortalama ORT'un ofseti olan 4EDH'ye `80 01` olarak yazıldı.
  - Uzun veride JMP `E9` ile üç byte'lık yakın dallanma olarak kodlandı ve NOP konmadı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Eleman sayısı ve eleman tipine mutlaka uyulmalı
  - Byte'a sığmayan eleman sayısı, word dizisi gibi ayrıntılar yazılacak kodu baştan değiştirir.
- EXE programını EXE yapan üç şey
  - `STACK` kelimesi yığın segmentini, iki MOV satırı veri segmentini, `END`'den sonraki etiket kod segmentini belirler. Ana yordam FAR'dır ve dönüş adresi programın girişinde yığına atılır.
- COM programında ana yordam NEAR'dır
  - Hoca önce yanlışlıkla FAR dedi, hemen düzeltti: COM programlarında en az bir NEAR prosedür vardır. Dönüş ofseti yığına otomatik atıldığı için `RET` yeterlidir.
- COM programında SP = FFFEH ve IP = 100H
  - Hoca bunun kesin söylenebileceğini, giriş etiketinin mutlaka 100H'yı göstermesi gerektiğini deneyerek gösterdi.
- Şablon 2'nin amacı
  - Verinin ofsetini sabitleyip DEBUG'da hızlıca dump edebilmek. Baştaki JMP kodu bunun bedeli olan birkaç byte'lık ek yüktür.
- DOSBox (MASM) varsayılan derleme ortamıdır
  - emu8086'nın kabul ettiği `SHL AX, 2` gibi yazımları MASM kabul etmez. Kod DOSBox'ta derlenip çalışmalıdır.
- Word dizilerinde boyut ve taşma
  - Toplam için 32 bitlik DX:AX kullanılmalı, alınabilecek en büyük değerler hesaba katılmalıdır.

## Kısa Tekrar Notları

- EXE: 3 segment, ana yordam FAR, girişte `PUSH DS` / `XOR AX,AX` / `PUSH AX`, sonra `MOV AX, DATASG` / `MOV DS, AX`, çıkışta `RETF`.
- EXE'de SP başlangıçta yığın boyutudur; yığın başlangıçta boştur.
- COM: tek segment, `ORG 100H`, ana yordam NEAR, çıkışta `RET`.
- COM'da CS = DS = ES = SS, IP = 100H, SP = FFFEH, yığında dönüş ofseti 0000H.
- COM'da kullanılabilir bellek: 64KB − header − dönüş adresi.
- Şablon 2: `BILGI: JMP BASLA` + veri + prosedür, `END BILGI`. Veri 100H'dan birkaç byte sonra başlar.
- Giriş etiketi 100H'yı göstermezse COM'a dönüştürme başarısız olur.
- COM derleme: masm → link → exe2bin/exe2com.
- MASM kısa ileri dallanmayı `EB xx 90` (JMP + NOP), uzak olanı `E9 xx xx` ile kodladı.
- `DIV BX`: DX:AX / BX, bölüm AX, kalan DX. Bölmeden önce DX sıfırlanmalı ya da DX:AX bilinçli hazırlanmalı.
- 32 bit toplama: `ADD AX, [SI]` + `ADC DX, 0`.
- `n DUP (değer)`: tekrar sayısı başta yazılır.
- Disassembly komutun ortasından başlarsa komutlar yanlış görünür.

## Detaylı Açıklamalar

Ders, EXE tipi programların kısa bir tekrarıyla başladı. EXE şablonunda üç segment vardır. Yığın segmenti `STACK` birleştirme kelimesiyle tanınır; segment adı ve sınıf adı keyfidir. Kod segmenti, `END` sözde komutundan sonra yazılan giriş noktası etiketinin bulunduğu segmenttir. Veri segmenti ise DS'ye yüklenen segmenttir. DS'ye doğrudan sabit atanamadığı için `MOV AX, DATASG` ve `MOV DS, AX` satırları gerekir. İşletim sistemi EXE programını yüklediğinde DS kendi dönüş segmentini tutar ve dönüş ofseti olarak 0 bekler. Bu yüzden program girişte `PUSH DS`, `XOR AX, AX`, `PUSH AX` ile dönüş adresini yığına atar ve sonda FAR yordamdan `RETF` ile döner. `RETF` yığının en üstündeki değeri IP'ye, sonrakini CS'ye yazar. Bir öğrencinin "ofset neden 0" sorusuna hoca şöyle cevap verdi: aynı fiziksel adres birçok segment:ofset çiftiyle gösterilebilir (FFFF0H = `FFFF:0000` = `FAAA:5550`). Her adres segment + 0 ofset olarak normalize edilebildiği için ofset için ayrı bir yazmaç gerekmez.

Yığına yalnız word atılabildiği için yığın boyutu çift olmalıdır. EXE'de SP başlangıçta yığın boyutuna eşittir. 32 word'lük yığında bu 64'tür ve yığının hemen dışını gösterir. İlk PUSH SP'yi 2 azaltır, değer 62. ofsete yazılır.

> **Ders sonrası not:** Slaytta (ekrandan, 00:50:00) `SP=64H` yazıyor. Hoca da önce "64 hash" deyip sonra "64 hash değil de 64" diye düzeltti. 32 word = 64 byte = 40H olduğu için doğrusu SP = 64 = 40H'dır.

COM programlarında tek segment vardır. `ORG 100H` ile kod 100H ofsetinden başlar, ilk 256 byte header'a ayrılır. Ana yordam NEAR'dır ve `RET` ile döner, çünkü işletim sistemi programı near olarak çağırıp dönüş ofsetini (0000H) yığına kendisi atar. Segmentin son adresi FFFFH tek sayıdır ve yığında zaten bir word vardır, bu yüzden SP FFFEH ile başlar. Tüm segment yazmaçları aynı değeri taşır. Değişkenler şablon 1'de prosedürlerden sonra, şablon 2'de `JMP BASLA` ile prosedür arasındaki boşlukta tanımlanır. Şablon 2'de veri hep 100H'dan sonraki JMP kodunun arkasında başladığı için DEBUG'da `D DS:100` ile hemen bulunur.

Örnek 4'te beş çift sayının en büyük ortak böleni hesaplandı (ekrandan, 02:20:00):

```text
CODESG  SEGMENT PARA 'CODE'
        ORG 100H
        ASSUME CS:CODESG, SS:CODESG, DS:CODESG, ES:CODESG
BILGI:  JMP BASLA
X_DIZI DW 28, 0FFFFH, 1, 100, 511
Y_DIZI DW 12, 0FFFH, 28, 25, 3
ELEMAN DW 5
GCD_DIZI DW 5 DUP(0)

BASLA   PROC NEAR
        XOR SI, SI
        MOV CX, ELEMAN
L1:
        MOV AX, X_DIZI [SI]
        MOV DX, Y_DIZI [SI]
        CMP AX, DX
        JAE L2
        XCHG AX, DX
L2:
        CMP DX,0
        JE L3
        MOV BX, DX ; BX<-y
        XOR DX, DX
        DIV BX; 0:AX/DX; DX<-AX%DX;
        MOV AX, BX
        JMP L2
L3:
        MOV GCD_DIZI[SI], AX
        ADD SI, 2
        LOOP L1
        RET
BASLA   ENDP
CODESG  ENDS
        END BILGI
```

<!-- BELİRSİZ: RET, ENDP, ENDS ve END BILGI satırları bu kod sürümünün karesinde görünmüyor; şablondan ve LST'deki RET (014EH) satırından alındı. -->

İşaretsiz karşılaştırma yapıldığı için `JAE` kullanıldı; DEBUG bunu eşdeğeri olan `JNB`, `JE`'yi de `JZ` olarak gösterdi. Her turda y BX'e saklanır, DX sıfırlanıp `DIV BX` ile $x \bmod y$ DX'te elde edilir, eski y de AX'e geçer. 28 ile 12 için ilk turda AX = 2 (bölüm), DX = 4 (kalan) olur, sonra AX = 12; ikinci turda kalan 0 olur ve AX = 4 sonucu `GCD_DIZI`'ye yazılır. Programın bitiminde `D DS:100` çıktısında `GCD_DIZI` (0119H) gözlerinde `04 00 0F 00 01 00 19 00 01 00` görüldü (ekrandan, 02:25:00).

> **Ders sonrası not:** Hoca ikinci çifti "FFFF ile FFFF" diye okudu. Kodda ve bellekte ikinci y değeri 0FFFH'dır (`FF 0F`). $\gcd(65535, 4095) = 15 = 0FH$ olduğu için sonuç doğrudur; $\gcd(FFFFH, FFFFH)$ olsaydı sonuç FFFFH olurdu.

Örnek 5'te 500 elemanlı işaretsiz word dizisinin ortalaması bulundu (ekrandan, 02:50:00):

```text
BILGI:  JMP BASLA
DIZI    DW 0FFFFH, 100, 28, 1, 0, 495 DUP (256)
ELEMAN  DW 500
ORT     DW 0

BASLA   PROC NEAR
        LEA SI, DIZI
        MOV CX, ELEMAN
        XOR AX, AX
        XOR DX, DX
L1:
        ADD AX, [SI]
        ADC DX, 0
        ADD SI, 2
        LOOP L1
        ; DX:AX toplam
        MOV BX, ELEMAN
        DIV BX
        MOV ORT, AX
        RET
BASLA   ENDP
```

<!-- BELİRSİZ: MOV ORT, AX ve RET satırları karede görünmüyor; altyazıdaki anlatımdan alındı. -->

Toplam $65535 + 100 + 28 + 1 + 0 + 495 \cdot 256 = 192384 = 2EF80H$'dır. DEBUG'da döngü sonunda DX = 0002, AX = EF80 görüldü. $192384 / 500$ işleminde bölüm 384 = 180H, kalan da 384 = 180H çıkar. Bellekte ORT gözünde `80 01` görülür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
