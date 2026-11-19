# Ders 8 Genişletilmiş Notu: COM ve EXE Tipi Programlar, COM Şablonları ve Örnekler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Veri Tanımlarında Eleman Sayısı ve Tipi
- 2. EXE Tipi Programların Tekrarı
- 3. Dönüş Ofseti Neden 0?
- 4. EXE Programında Yığın ve SP
- 5. COM Tipi Programlar
- 6. COM Şablon 2
- 7. COM ve EXE Karşılaştırması
- 8. emu8086'da Komutların "Değişmesi"
- 9. Örnek 4: COM Programıyla En Büyük Ortak Bölen
- 10. Örnek 4'ün Derlenmesi ve DEBUG ile İzlenmesi
- 11. Örnek 5: 500 Elemanlı Word Dizisinin Ortalaması
- Örnek Sorular

## 1. Veri Tanımlarında Eleman Sayısı ve Tipi

Ders, geçen haftaki değerlendirmeden sonra sınav öncesinde kalınan konudan devam etti. Akademik ilk uyarı, problemde verilen eleman sayısı ve eleman tipiyle ilgiliydi. Bir dizinin 200 elemanlı olduğu söyleniyorsa bu sayı bir byte değişkene sığar ve eleman sayısı byte olarak tanımlanabilir. Ama byte'a sığmayacak eleman sayıları da verilebilir. Elemanların byte mı word mü olduğu da yazılacak kodu baştan değiştirir. Bu yüzden hoca, verilen eleman sayısına ve tipine mutlaka birebir uyulmasını istedi.

Çok elemanlı bir diziyi tanımlarken her elemanı tek tek yazmak gerekmez. Derste görüldüğü gibi bir kısım elemanlar açıkça yazılıp geri kalanı `DUP` ile sabit bir değer olarak tanımlanabilir.

> **Hocanın vurgusu:** Eleman sayısı ve eleman tipleri çok önemlidir, yazacağınız kodu çok değiştirir. Verilen eleman sayılarına ve tiplerine mutlaka uyun.

## 2. EXE Tipi Programların Tekrarı

İki hafta önce EXE ve COM tipi programların genel yapısını anlatan bir sunum işlenmişti. Bu derste önce EXE yapısı hızlıca tekrar edildi, ardından COM tipi programlar karşılaştırmalı olarak anlatıldı.

### 2.1 Şablon

Hoca, hiçbir iş yapmayan ama minimal bir EXE programının iskeleti olan şu şablonu gösterdi ve standart olarak kullanılabileceğini söyledi (ekrandan, 00:25:00):

```text
STACKSG SEGMENT PARA STACK 'STACK'
     DW 32 DUP(?)
STACKSG ENDS

DATASG  SEGMENT PARA 'DATA'
SAYI    DB ?
ELEMAN  DW ?
DATASG ENDS

CODESG  SEGMENT PARA 'CODE'
     ASSUME CS:CODESG, DS:DATASG, SS:STACKSG

BASLA   PROC FAR
     PUSH DS
     XOR AX,AX
     PUSH AX

     MOV AX, DATASG
     MOV DS, AX

     RETF
BASLA   ENDP
CODESG  ENDS
     END BASLA
```

EXE programında üç segment tanımı olur: yığın, veri ve kod. Yığın segmenti mutlaka olmalıdır. Yalnız yazmaçlarla işlem yapılacaksa veri segmenti gerekmeyebilir, ama pratikte değişken tanımlanıp onlar üzerinde çalışılacağı için veri segmenti de kullanılır.

### 2.2 Hizalama

Bu şablon bile derlenip işletim sistemi tarafından belleğe yüklendiğinde segmentler ardışık olarak yerleşir. Yerleştirme, segment tanımında verilen hizalama tipine göre yapılır. Şablonda hizalama `PARA` ile verilmiştir. Hizalama tipleri şunlardır:

- BYTE: segment sıradaki boş adresten başlar.
- WORD: segment sıradaki çift adresten başlar.
- PARA: segment 16'nın tam katı olan bir adresten başlar.
- PAGE: segment 256'nın tam katı olan bir adresten başlar.

Bütün segmentler PARA ile hizalandığında, iki hafta önce görüldüğü gibi, veri segmentinin bellekteki içeriğinde tanımlanan değişkenler görülür. Toplam tanım boyutu 16'nın tam katı değilse, bir sonraki 16'nın katına kadar bazı fazladan byte'lar kalır. Bu byte'lar o örnekte sıfır görünmüştü, ama hoca bunların herhangi bir çöp değer de olabileceğini söyledi. Nedeni, sonra gelen kod segmentinin de PARA ile hizalanıp bir sonraki 16'nın katından başlamasıdır.

### 2.3 Segmentleri amacına göre belirleyen şey

Segmentlere herhangi bir ad verilebilir. Bir segmenti yığın segmenti yapan, tanımındaki `STACK` kelimesidir. Tırnak içindeki `'STACK'` sınıf adıdır; yerine başka bir şey yazılabilir. Sınıf adları ileride segment birleştirmede önem kazanacaktır: segmentlerin birleştirilebilmesi için sınıf adlarının aynı olması gerekir. Hoca, segment adlarının değiştirilebileceğini, örneğin yığın segmentine `DATASG` ve veri segmentine `STACKSG` denmesinin çalışma açısından sorun çıkarmayacağını, ama okunabilirlik için anlamlı adların daha pratik olduğunu söyledi.

Bir segmenti kod segmenti yapan, kodun en altındaki `END` sözde komutundan sonra gelen etiketin o segmentin içinde olmasıdır. Bu etiket programın giriş noktasıdır (entry point); şablonda `BASLA`'dır.

Bir segmenti veri segmenti yapan ise DS'ye yüklenmesidir. İşletim sistemi EXE programını yüklediğinde DS, işletim sistemine dönüş segment değerini tutar. Dönüş ofseti olarak da 0 beklenir. Yani program, kendisini çağıran işletim sistemine DS'deki segmentin 0 ofsetine dönerek geri döner. Buradan çıkan sonuç şudur: EXE programında dönüş adresini yığına atmaktan programın kendisi sorumludur.

### 2.4 Dönüş adresi ve RETF

Bu yüzden giriş noktasında yapılan ilk iş, DS'deki değeri ve 0 değerini yığına atmaktır. Şablondaki `PUSH DS`, `XOR AX,AX`, `PUSH AX` satırları bunu yapar: DS yığına atılır, AX sıfırlanır ve bu sıfır da yığına atılır. Yığına iki değer atıldığı için programdan çıkarken iki değer çekilmelidir. Bunu `RETF` (return far) yapar: yığının en üstündeki değeri çekip IP'ye, bir sonrakini çekip CS'ye yazar. Böylece işletim sisteminde kalınan yere dönülür. Bu nedenle EXE programında en az bir FAR yordam olmalıdır ve giriş noktasının gösterdiği ana yordam FAR tipindedir.

DS'yi veri segmentiyle yüklemek için doğrudan bir komut yoktur; MOV ile DS'ye sabit bir değer atanamaz. Atama AX gibi bir yazmaç üzerinden yapılır. `DATASG` bir segment değerine karşılık gelir ve `MOV AX, DATASG` ile `MOV DS, AX` satırları yürütüldükten sonra bu segment veri segmenti görevini üstlenir.

Programcının kendi algoritmasını yazacağı yer, DS yüklendikten sonraki satırdan `RETF`'ye kadar olan bloktur. En sondaki `END` satırı da giriş noktasını belirlediği için mutlaka yazılmalıdır.

## 3. Dönüş Ofseti Neden 0?

Bir öğrenci dönüş ofsetinin neden 0 olduğunu sordu.

**Soru:** İşletim sistemine dönüş ofseti neden 0 olmak zorunda?

**Cevap:** Hoca bunun bir standart olduğunu söyleyip iki yönden açıkladı. 20 bitlik bir fiziksel adres farklı segment:ofset çiftleriyle oluşturulabilir. Fiziksel adres, segment değerinin 10H ile çarpılıp ofsetin eklenmesiyle bulunur. Örneğin FFFF0H adresi şöyle yazılabilir:

- Segment = FFFFH, ofset = 0000H: $FFFF0H + 0000H = FFFF0H$
- Segment = FAAAH, ofset = 5550H: $FAAA0H + 5550H = FFFF0H$

İşletim sistemine keyfi bir segment ve ofset çiftiyle dönülecek olsaydı, ofset için de veri segmentinde olduğu gibi ikinci bir yazmaç ve fazladan satırlar gerekebilirdi. Oysa her 20 bitlik adres bir segment ve 0 ofsetle yazılabilir. Sıkıntı yalnız en baştaki adreslerde çıkabilir, ama hoca oranın kesme vektör tablosu olduğunu ve zaten doğrudan kullanılmayacağını söyledi. Bu yüzden bir normalizasyon yapılır: dönüş adresi "segment + 0 ofset" olarak verilir ve ofset için ayrı bir yazmaç harcanmaz. Hoca bunu bir yazılım tasarımı kararı olarak değerlendirdi.

## 4. EXE Programında Yığın ve SP

### 4.1 Yığın yalnız word ile çalışır

Yığına yalnız word tipinde değer atılır ve yığından yalnız word çekilir. `PUSH AL` diye bir komut yoktur. 8 bitlik bir değer yığına atılmak isteniyorsa AX atılır ve yalnız AL'nin anlamlı olduğu, AH'nin çöp olduğu önceden kabul edilir. Bu yüzden yığın boyutu çift sayıda byte olmalıdır: yığın ya `DW` ile herhangi bir boyutla, ya da `DB` ile çift sayıda byte olarak tanımlanır. Yığın tanımının başlangıç ve bitiş satırları makine kodu üretmeyen sözde komutlardır.

### 4.2 SP'nin başlangıç değeri

Hoca, 64 byte'lık, yani 32 word'lük bir yığın çizdi (ekrandan, 00:50:00). Yığının başı yığın segmentinin 0 ofsetidir. SP başlangıçta yığının dışındaki bir yeri gösterir. SP her zaman "sıradaki dolu gözü" gösterdiği için başlangıç değeri yığın boyutu kadardır: 32 word'lük yığında 64. Yığın boşken yapılacak ilk iş yığına bir şey atmaktır. Bir word atılınca SP 62 olur ve yine dolu olan gözü gösterir.

> **Ders sonrası not:** Slayttaki çizimde `SP=64H` yazıyor. Hoca da önce "64 hash" deyip ardından "64 hash değil de 64" diye düzeltti. 64 byte $= 40H$ olduğundan doğrusu SP $= 64 = 40H$'dır.

Yığına bir şey atıldıkça SP ikişer azalır, yığından bir şey çekildikçe ikişer artar. Yığın doldurulurken SP küçülür. Yığın dolduğu halde veri atılmaya devam edilirse başka segmentlerin verileri ezilmeye başlar; buna dikkat edilmelidir.

## 5. COM Tipi Programlar

### 5.1 Genel özellikler

COM tipi programlar mantık olarak EXE'ye benzer, ama derlenmiş program daha kısadır. COM programı yalnız segment içi (intra segment) bir program tipidir; uzak segmentlere erişmek için varsayılan tip değildir. Farklı segmentlerle çalışılacaksa EXE daha mantıklıdır. COM daha çok kısa ve tek segmente sığabilecek programlar içindir.

EXE'de yalnız birkaç değişken tanımlanıp işlem yapılacak olsa bile üç ayrı segment kullanılır. Hizalama yüzünden fazladan yer harcanır, ayrıca EXE programının kendine ait bir header bilgisi vardır ve bu da yer kaplar. COM programında ise tek bir segment içinde header, kod, veri ve yığın birlikte kullanılır. COM programlarının en büyük farkı, tek bir segment içinde tanımlı olmalarıdır.

### 5.2 Şablon 1

Slayttaki COM şablonu şöyledir (ekrandan, 00:40:00):

```text
CODESG  SEGMENT PARA 'CODE'
     ORG 100H
     ASSUME CS:CODESG, SS:CODESG, DS:CODESG, ES:CODESG

BASLA   PROC NEAR

     RET
BASLA   ENDP

SAYIB   DB ?
SAYIW   DW ?
CODESG  ENDS
     END BASLA
```

Burada `SEGMENT` ile başlayıp `ENDS` ile biten yalnız bir segment vardır; adı önemli değildir. `ASSUME` sözde komutuyla assembler'a kod, yığın, veri ve ekstra segment olarak hep bu segmentin kullanılacağı bildirilir.

`ORG 100H` bir sözde komuttur ve bu satırdan sonra yazılan satırların makine kodlarının segmentin 100H ofsetinden itibaren yerleşeceğini söyler. Segmentin 0 ofsetinden 100H'ya kadar olan kısmı boş geçilir: program derlendikten sonra header bilgisi buraya yerleşir. İlk 100H, yani 256 byte header içindir. Yazılan program bu yüzden 100H'dan başlamak zorundadır.

### 5.3 Ana yordam NEAR'dır

> **Hocanın vurgusu:** COM tipi programlarda ana yordam NEAR tipinde olmalıdır. Hoca önce yanlışlıkla "FAR" dedi, hemen "yanlış söyledim, NEAR tipinde olması lazım" diye düzeltti.

Başka hiçbir fonksiyon olmasa bile COM programında en az bir NEAR prosedür vardır. Ana yordam NEAR olduğu için işletim sistemine `RET` ile dönülür; program sonlandığında yığından tek bir değer çekilir.

Peki bu dönüş değerini yığına kim atar? EXE'de bunu program kendisi yapıyordu. COM programı çağrıldığında ise dönüş ofseti yığına otomatik olarak atılır. Yani işletim sistemi COM programını near olarak çağırır ve near olarak dönülür; dönüş değeri yalnız bir ofsettir ve işletim sisteminin o anda bulunduğu segment içinde çalışılır. Program sonlandığında `RET` yığının en üstündeki değeri IP'ye yazar ve işletim sisteminde kalınan yere dönülür.

Şablon 1'de veri tanımları, prosedürler bittikten sonra `ENDS`'e kadar olan alanda yapılır.

### 5.4 Şablon 1'in DEBUG zorluğu

EXE programını DEBUG'da incelerken veriye gitmek kolaydı: DS'nin 0 ofseti dump edilirdi. COM programında ise verinin nerede başladığına dair bir işaret yoktur. Örneğin bir giriş ve bir çıkış değişkeni olsun; kodun mantıkça doğru çalışıp çalışmadığını görmek için bu değişkenlerin bulunduğu yere gidilmelidir. Bunun için bütün prosedürlerin kapladığı boyut hesaplanmalı, üzerine 100H eklenmeli ve oradan itibaren bellek dump edilmelidir. Hoca bunun zor ve dolambaçlı olduğunu, bu yüzden ikinci bir şablonun kullanılabileceğini söyledi.

### 5.5 COM programında yığın ve SP

COM programında tek segment olduğu için segmentin boyutu 64K'dır: ofset 0000H'dan FFFFH'ya kadar gider. Program çağrılır çağrılmaz yığına dönüş ofseti, yani bir word atılır. SP de yine sıradaki dolu gözü gösterir. Bu yüzden SP başlangıçta segmentin en ucunu değil, FFFEH'ı gösterir (ekrandan, 00:55:00). Çizimde 0000H'da header, 100H'da prosedür, segmentin sonunda FFFEH–FFFFH gözlerinde "işletim sistemi geri dönüş ofseti" vardır.

Hoca SP'nin neden FFFFH olmadığını iki gerekçeyle açıkladı: FFFFH tek bir sayıdır ve yığın word ile çalışır; ayrıca programa girer girmez yığına dönüş ofseti atılmıştır.

> **Ders sonrası not:** Altyazıda segmentin "FFFFFH'a kadar" gittiği geçiyor; 16 bitlik ofsetle segmentin son ofseti FFFFH'dır. Bu büyük olasılıkla bir okuma ya da Whisper hatasıdır.

Bellekte header'ın ardından prosedürler, onların ardından veri tanımları gelir; geri kalan alan yığın için kullanılabilir. Yığına aşırı veri atılırsa, örneğin yığına attıklarının takibini yapmayan özyinelemeli bir fonksiyon yazılırsa, yığın dolup veri tanımlarını, daha da ilerlerse programın kendisini bozabilir.

Hoca şablon 1'den şu çıkarımları özetledi:

- Tek segment tanımı vardır; `ASSUME` ile bu segment kod, yığın, veri ve ekstra segment olarak bildirilir.
- Program 100H'dan başlamak zorundadır, çünkü 100H'ya kadar olan kısım header'a ayrılmıştır.
- En az bir NEAR prosedür vardır; ana yordam NEAR'dır.
- Değişkenler bütün prosedürlerden sonra, segment tanımının bittiği yere kadar tanımlanabilir.
- `END`'den sonraki etiket ana prosedürü gösterir.

## 6. COM Şablon 2

Şablon 2'nin amacı, veriyi DEBUG'da dump ederek izlemek için verinin hangi ofsette olduğunu kesin olarak bilmektir. Slayttaki şablon şöyledir (ekrandan, 01:00:00):

```text
PAGE 60,80
     TITLE ornek____

CODESG  SEGMENT PARA 'CODE'
     ORG 100H
     ASSUME CS:CODESG, SS:CODESG, DS:CODESG, ES:CODESG
BILGI: JMP BASLA
SAYIB   DB ?
SAYIW   DW ?

BASLA   PROC NEAR

     RET
BASLA   ENDP
CODESG  ENDS
     END BILGI
```

Veri tanımı başa, `ORG 100H`'dan hemen sonraya alınır. Ama giriş noktasının yapısı bozulmamalıdır. Bu yüzden `END`'den sonra verilen etiket (`BILGI`), `ORG 100H`'dan hemen sonraki satırı gösterir ve oradaki komut koşulsuz dallanma komutu `JMP BASLA`'dır. Program yüklenince `BILGI` etiketine gidilir, oradan `BASLA`'ya atlanıp ana yordam yürütülmeye başlar. JMP ile prosedür arasında bir boşluk oluşturulmuş olur ve veri tanımları bu boşluğa yapılır.

COM programında bütün segment yazmaçları aynı segmenti gösterdiği için veriyi incelemek üzere bulunulan segmentin 100H ofsetinden itibaren bellek dump edilir. İlk görülen değer veri değil, JMP komutunun makine kodudur; ondan sonra veriler başlar.

> **Ders sonrası not:** Hoca burada "bir byte'lık JMP komutu gelecek" dedi. Derlenen örneklerde JMP üç byte yer kapladı (Bölüm 10.1 ve 11.3).

## 7. COM ve EXE Karşılaştırması

Hoca iki program tipini slayttaki tabloyla karşılaştırdı (ekrandan, 01:05:00 ve 01:10:00):

```text
Özellik                     COM Programı                      EXE Programı
Kullanılabilen Bellek       64KB - Header - Dönüş adresi      Boş bellek
Başlangıçta CS              Header'ın bulunduğu kesim         END komutundan sonraki etiketin
                                                              bulunduğu kesim
Başlangıçta IP              100H                              END komutundan sonraki etiketin
                                                              bulunduğu ofset
Başlangıçta DS              Header'ın bulunduğu kesim         Dönüş için gerekli kesim değeri
Değişkenlere Erişim İçin    Yok                               MOV AX, verikesimismi
Yapılması Gerekenler                                          MOV DS, AX
Değişkenlerin Tanımlandığı  ENDP'den sonra                    Veri kesiminde
Yer
Başlangıçta SS              Header'ın bulunduğu kesim         Yığın kesimi adresi
Başlangıçta SP              0FFFEH                            Yığın kesimi boyutu
Başlangıçta Yığın           0000H                             Boş
Yığın Büyüklüğü             64KB - 256 (header) - X byte      Yığın kesimi boyutu
                            Kod - Y byte Değişken
Ana Prosedür Tipi           NEAR                              FAR
Dönüş İçin Yapılması        Yok                               PUSH DS
Gereken                                                       XOR AX, AX
                                                              PUSH AX
```

Tablonun satırları derste şöyle açıklandı:

- **Kullanılabilen bellek:** COM programında tek segment, yani 64KB vardır. Ama bunun tamamı kod ya da veri için kullanılamaz: ilk 100H header'a ayrılmıştır ve yığının en üstüne dönüş ofseti olarak bir word yazılır. EXE programında FAR fonksiyonlar kullanılabildiği için boş belleğin tamamı kullanılabilir.
- **CS:** COM'da CS, header'ın da bulunduğu tek segmentin değeriyle başlar. EXE'de `END`'den sonraki etiket hangi segmentteyse CS o değerle yüklenir.
- **IP:** COM'da kod 100H'dan başladığı için IP 100H ile başlar; şablon 1 ve 2'de giriş etiketi bu yüzden `ORG 100H`'dan hemen sonraki yeri gösterir. EXE'de IP, giriş noktasının ofsetiyle yüklenir. Bu 0 olmak zorunda değildir: program birden fazla prosedürden oluşuyorsa ve ana yordam yardımcı yordamlardan sonra tanımlanmışsa IP belli bir ofsetle başlar.
- **DS ve değişkenlere erişim:** COM'da DS de header'ın bulunduğu segmenttir. Değişkenler aynı segmentteki etiketler olduğu için hiçbir işlem gerekmez. EXE'de DS işletim sistemine dönüş segmentini tutar; değişkenleri kullanmak için veri segmentinin değeri iki MOV satırıyla DS'ye yüklenmelidir.
- **Değişkenlerin yeri:** COM'da şablon 1'e göre `ENDP` ile `ENDS` arası ya da şablon 2'ye göre giriş noktası ile ana yordam arasındaki boşluk. EXE'de veri segmenti.
- **SS ve SP:** COM'da SS yine tek segmenttir; SP FFFEH ile başlar, çünkü yığında bir dönüş ofseti vardır ve SP sıradaki dolu gözü göstermelidir. EXE'de ayrı bir yığın segmenti vardır; SP yığın boyutuyla başlar ve sanal olarak yığının dışındaki ofseti gösterir.
- **Başlangıçta yığın:** COM'da yığında dönüş ofseti olan 0000H vardır. SP'nin 64K'nın ucundan farklı olmasının nedeni budur. EXE'de yığın başlangıçta boştur.
- **Yığın büyüklüğü:** COM'da 64KB'tan 256 byte header, X byte kod ve Y byte değişken çıkarıldıktan sonra kalan alan. EXE'de tanımlanan yığın segmentinin boyutu.
- **Ana prosedür ve dönüş:** COM'da NEAR ve dönüş için bir şey yapılmaz; `RET`'e gelince otomatik olarak işletim sistemine dönülür. EXE'de FAR; girişte DS ve 0 yığına atılır, `RETF` önce 0'ı ofset olarak, sonra dönüş segmentini çeker.

## 8. emu8086'da Komutların "Değişmesi"

Aradan önce bir öğrenci emu8086'da karşılaştığı bir durumu sordu.

**Soru:** emu8086'da arka arkaya birkaç MOV komutu yazıp adım adım çalıştırınca bazı MOV'lar ADD ya da AND komutuna dönüşüyor. Bu yazılan koddan mı kaynaklanıyor?

**Cevap:** Hoca önce kodun tam bir EXE programı mı yoksa bir kod parçası mı olduğunu sordu; öğrenci kod parçası olarak yazdığını söyledi. Hoca iki olası nedeni açıkladı. Birincisi, yazılan kod bloğu bittikten sonra bir sonraki bellek gözüne düşülür. Bu programlanmamış gözlerde çöp değerler vardır ve emulator bu değerleri makine kodu olarak çözüp ADD gibi komutlar olarak gösterir. İkincisi, kod doğru ofsetten değil de bir byte sonrasından başlatılırsa komutun tam ortasından girilmiş olur ve makine kodu yanlış noktadan çözülür. Hoca ekranda bunu gösterdi: kod 1000H ofsetinden yerleşmişken 1001H'dan bakıldığında oradaki `C3` byte'ı `RET` olarak okundu. Yanlış yerden başlanıp adım adım gidilirse sonraki komutlar da bozuk görünür. Doğru ofsetten başlanırsa bu sorun olmaz.

<!-- BELİRSİZ: Kodun emu8086'da yerleştiği ofset altyazıda "1000" olarak geçiyor; bu anın karesi yok. -->

## 9. Örnek 4: COM Programıyla En Büyük Ortak Bölen

Aradan sonra COM tipi programların nasıl yazıldığına geçildi. Hoca, standart COM şablonunu `örnek4.asm` (ekranda `O4.asm`) olarak kaydedip en büyük ortak böleni (EBOB, GCD) hesaplayan bir program yazdı.

### 9.1 Algoritma

Hoca önce tanımı verdi (ekrandan, 01:45:00):

$$\gcd(x, 0) = x, \qquad \gcd(x, y) = \gcd(y, x \bmod y)$$

Durma koşuluna varılana kadar EBOB bu şekilde hesaplanır. Örnek olarak 12 ile 28 alındı. Önce birinci parametrenin büyük olduğu duruma getirilir:

- $\gcd(12, 28) = \gcd(28, 12)$
- $28 \bmod 12 = 4$ olduğu için $\gcd(28, 12) = \gcd(12, 4)$
- $12 \bmod 4 = 0$ olduğu için $\gcd(12, 4) = \gcd(4, 0)$
- İkinci parametre 0 olduğu için sonuç $\gcd(4, 0) = 4$'tür.

### 9.2 Akış şeması

Hoca bunu bir akış şemasına çevirdi (ekrandan, 01:45:00). Girdi x ve y'dir. Önce bir if ile birinci parametrenin büyük olması sağlanır: $x \geq y$ ise (eşitlik dahil) bir şey yapılmaz, değilse `swap(x, y)` yapılır. Hoca bu takasın aslında gerekmeyebileceğini, ama program yazma pratiği için eklendiğini söyledi. İki kol birleştikten sonra bir while döngüsü gelir. Döngüde $x \bmod y$ hem y'ye atanacağı hem de x'e eski y yazılacağı için değerler bozulmasın diye geçici bir t değişkeni kullanılır:

```text
t = x % y
x = y
y = t
```

Döngüden çıkınca sonuç döndürülür.

> **Ders sonrası not:** Akış şemasında döngü koşulu `y>=0` olarak yazıldı ve hoca "y sıfırdan büyük eşit olduğu süre" dedi. İşaretsiz y her zaman $\geq 0$ olduğu için bu koşul döngüyü hiç bitirmez; doğrusu "y ≠ 0 olduğu sürece" (yani y > 0) dönmektir. Assembly kodunda koşul doğru yazıldı: `CMP DX,0` / `JE L3` ile y = 0 olunca döngüden çıkılır.

> **Ders sonrası not:** Hoca çıkışta "y değerini return ettireceğiz" dedi. Döngü y = 0 olunca bittiği için sonuç x'tir ($\gcd(x, 0) = x$). Assembly kodunda da sonuç x'in tutulduğu AX'ten yazıldı.

### 9.3 Veri tanımları

x ve y birer word dizisi olarak düşünüldü: beş elemanlı iki dizinin karşılıklı elemanları için EBOB hesaplanacak. Son hali şöyledir (ekrandan, 02:05:00 ve 02:20:00):

```text
X_DIZI DW 28, 0FFFFH, 1, 100, 511
Y_DIZI DW 12, 0FFFH, 28, 25, 3
ELEMAN DW 5
GCD_DIZI DW 5 DUP(0)
```

Sonuçlar yine bir word dizisi olan `GCD_DIZI`'de saklanır; beş gözü sıfırla ilklenir. İşlem bir NEAR prosedür içinde yapılır. Değişkenlerin değerlerini hızlı kontrol edebilmek için COM şablonlarından ikincisi kullanıldı.

### 9.4 Kodun gelişimi

Hoca dizileri dolaşmanın iki yolunu hatırlattı: dizilerin başlangıç adreslerini birer gösterici (pointer) gibi tutmak ya da indisli gösterim kullanmak. Önce gösterici yolunu seçti: `LEA SI, X_DIZI` ve `LEA DI, Y_DIZI` ile iki dizinin başlangıç adresleri alındı, her turda `ADD SI, 2` ve `ADD DI, 2` ile sonraki elemana geçildi, `MOV CX, ELEMAN` ile döngü sayısı verildi. Eleman sayısı word olarak tanımlandığı için doğrudan CX'e atanabildi.

Karşılaştırma için x AX'e, y ise bölmede kullanılacağı için DX'e alındı ve `CMP AX, DX` yapıldı. Değerler işaretsiz kabul edildiği için işaretsiz dallanma komutu gerekir. Değişiklik yalnız birinci eleman küçükse yapılacağı için hoca, daha az komutla bitirmek üzere boş kolun koşulunu yazdı: önce `JA L2` diye düşündü, sonra eşitlikte de bir şey yapmaya gerek olmadığı için `JAE L2` (jump above or equal) yazdı. AX < DX ise `XCHG AX, DX` ile ikisinin yeri değiştirilir.

L2'den sonra while döngüsü gelir. Boş kol DX'in 0 olduğu durumdur: `CMP DX, 0` ve `JE L3` ile DX = 0 ise döngü kırılır. Bu, $\gcd(x, 0) = x$ adımıdır. Çıkışta sonuç AX'te olduğu için üçüncü dizinin sıradaki gözüne yazılır. Hoca bunun için önce `LEA BX, GCD_DIZI` ile üçüncü bir gösterici tuttu.

Döngünün içinde AX, DX'e bölünecektir. 16 bitlik bölmede bölünen DX:AX ikilisidir; bölüm AX'e, kalan DX'e yazılır. Ama DX'te y vardır ve kaybedilmemelidir. Hoca önce y'yi yığına atmayı düşündü, sonra boşta yazmaç aradı: AX, BX, CX (döngü), DX, SI ve DI kullanılıyordu.

Çözüm olarak indis yaklaşımına geçildi: üç dizi için de yalnız SI kullanıldı ve dizilere `X_DIZI[SI]`, `Y_DIZI[SI]`, `GCD_DIZI[SI]` biçiminde erişildi. Böylece DI ve BX boşa çıktı ve her turda yalnız SI'yi 2 artırmak yetti. Boşalan BX, y'yi geçici olarak tutmak için kullanıldı: `MOV BX, DX`, `XOR DX, DX`, `DIV BX`. Bölmeden sonra DX'te $x \bmod y$ (yeni y) kalır, AX'e de BX'teki eski y (yeni x) yazılır: `MOV AX, BX`. Böylece geçici t değişkenine gerek kalmadı. Son olarak `JMP L2` ile döngünün başına dönülür. Hoca kodu kontrol ederken bir öğrenci bu dallanmanın L2'ye olması gerektiğini hatırlattı; hoca onayladı.

> **Ders sonrası not:** Hoca bir yerde "DX'te bölüm sonucu var" dedi. `DIV BX` sonrası DX'te bölümden kalan, AX'te bölüm vardır; anlatımın devamında ve ekrandaki yorumda (`DX<-AX%DX`) doğrusu kullanıldı.

### 9.5 Son kod

Ekrandaki son hali şöyledir (ekrandan, 02:20:00):

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

<!-- BELİRSİZ: L3 bloğu ekranda 02:00:00 karesinde görünüyor; RET, ENDP, ENDS ve END BILGI satırları son sürümün karesinde görünmüyor. RET, DEBUG çıktısında 014EH ofsetinde görülüyor (ekrandan, 02:25:00), diğerleri şablondan alındı. -->

## 10. Örnek 4'ün Derlenmesi ve DEBUG ile İzlenmesi

### 10.1 MASM ve LST dosyası

Hoca DOSBox'ta `masm` ile `O4.asm`'yi derledi. İlk derlemede dizi adları yanlış yazıldığı için iki hata çıktı (`DIZI_X` yerine `X_DIZI`); düzeltilince OBJ ve LST dosyaları oluştu. LST dosyasının başı şöyleydi (ekrandan, 02:05:00):

```text
0000            CODESG  SEGMENT PARA 'CODE'
0100                    ORG 100H
                        ASSUME CS:CODESG, SS:CODESG, DS:CODESG,
                ES:CODESG
0100  EB 21 90          BILGI:  JMP BASLA
0103  001C FFFF 0001 0064  X_DIZI DW 28, 0FFFFH, 1, 100, 511
      01FF
010D  000C 0FFF 001C 0019  Y_DIZI DW 12, 0FFFH, 28, 25, 3
      0003
0117  0005              ELEMAN DW 5
0119  0005[             GCD_DIZI DW 5 DUP(0)
      0000
            ]
0123                    BASLA   PROC NEAR
0123  33 F6                     XOR SI, SI
0125  8B 0E 0117 R              MOV CX, ELEMAN
0129                    L1:
0129  8B 84 0103 R              MOV AX, X_DIZI [SI]
012D  8B 94 010D R              MOV DX, Y_DIZI [SI]
0131  3B C2                     CMP AX, DX
0133  73 01                     JAE L2
0135  92                        XCHG AX, DX
0136                    L2:
0136  83 FA 00                  CMP DX,0
0139  74 0A                     JE L3
```

Gözlemler:

- 100H'dan JMP komutuna kadar makine kodu üretilmez. Segment tanımı, `ORG 100H` ve `ASSUME` sözde komutlardır.
- Makine kodu, `END`'den sonra verilen giriş etiketinin (`BILGI`) satırındaki JMP komutuyla başlar. JMP üç byte yer kaplar. Bu yüzden DEBUG'da veri incelenirken ilk üç byte atlanır.
- Veri 103H'dan başlar: X_DIZI 103H'da, Y_DIZI 10DH'da, ELEMAN 117H'da, GCD_DIZI 119H'da. Her dizi 5 word = 10 byte = 0AH kaplar.
- Ofsetlerin yanındaki `R` görece (relative) adres demektir. EXE programındaki veri segmenti adresi gibi "yüklendiğinde belli olacak" (`----`) bir değer burada yoktur, çünkü tek segment vardır. Segment belleğin neresine yüklenirse yüklensin, başından itibaren 117H ofsetinde ELEMAN değişkeni bulunur.

### 10.2 LINK ve EXE2BIN

Linkleme yapılınca LINK "no stack segment" uyarısı verdi. COM programı için izlenen yol, linkleme sırasında yine EXE tipi bir program oluşturmaya çalışır. Oluşan dosyanın uzantısı EXE'dir ama gerçekte EXE değildir; bu haliyle çalışmaz. Bu yüzden EXE'den farklı olarak bir adım daha vardır: EXE'yi COM'a çeviren program çalıştırılır (ekranda `c:\bin\exe2com.EXE O4.exe`, ekrandan 02:15:00). Bundan sonra COM programı elde edilir. Program çalıştırıldığında herhangi bir çıktı üretmedi, ama hata vermeden çalıştı.

### 10.3 Giriş noktası mutlaka 100H olmalı

Hoca, giriş etiketinin 100H'ya denk gelmesinin zorunlu olup olmadığını denedi: `BILGI` satırından önce isimsiz bir `DW` (0 değerli bir word) ekledi (ekrandan, 02:10:00). LST'de bu tanım için etiket olmasa da bir word yer ayrıldığı görüldü. Ama COM'a dönüştürme aşamasında "cannot convert" hatası çıktı ve program yüklenemedi.

> **Hocanın vurgusu:** COM tipi programlarda giriş noktası olan etiket mutlaka 100H'yı göstermelidir ki IP 100H ile başlasın. `ORG 100H` ile giriş etiketi arasına hiçbir tanım konmamalıdır.

### 10.4 Başlangıçtaki yazmaçlar

Fazladan tanım silinip program yeniden derlenip DEBUG ile açıldı. Daha hiçbir komut yürütülmeden `R` çıktısı şöyleydi (ekrandan, 02:15:00):

```text
AX=FFFF  BX=0000  CX=004F  DX=0000  SP=FFFE  BP=0000  SI=0000  DI=0000
DS=075A  ES=075A  SS=075A  CS=075A  IP=0100   NV UP EI PL NZ NA PO NC
075A:0100 EB21          JMP     0123
```

DS, ES, SS ve CS'nin hepsi aynı değere (075AH) sahiptir; bu, tek segmentin değeridir. IP 100H ile ilklenmiştir. EXE'de giriş etiketi tam 100H'ya denk gelmek zorunda değildi, burada IP otomatik olarak 100H'dan başlar. SP de FFFEH'dır.

Yığına atılmış dönüş ofsetini görmek için `D SS:FFFE` ile bellek dökülür: orada `00 00` vardır. EXE'de dönüş adresi DS'deki segmentin 0 ofsetiydi; COM'da da dönüş ofseti 0000H'dır ve otomatik yazılır. Hoca, az önceki "neden 0" sorusunu hatırlatıp başka bir yazmacı meşgul etmemek için böyle olduğunu tekrar söyledi.

### 10.5 JMP ve NOP

`D DS:100` ile veri bölgesi döküldü (ekrandan, 02:15:00):

```text
075A:0100  EB 21 90 1C 00 FF FF 01-00 64 00 FF 01 0C 00 FF
075A:0110  0F 1C 00 19 00 03 00 05-00 00 00 00 00 00 00 00
```

İlk byte'lar `EB 21`, `JMP BASLA` komutudur: kısa dallanma, $102H + 21H = 123H$'e, yani BASLA'ya gider. Ardından gelen `90` NOP komutudur; hoca bunu emulator'da NOP yazıp makine kodunun 90H olduğunu göstererek doğruladı. Programcı 90H değerinde bir byte tanımlamadı; MASM JMP'den sonra bu NOP'u kendisi koydu. Bu üç byte, verinin yerini sabitlemek için ödenen ek yüktür (overhead). Sonra veri gelir: `1C 00` (28), `FF FF`, `01 00`, `64 00`, `FF 01`; ardından Y_DIZI `0C 00`, `FF 0F`, `1C 00`, `19 00`, `03 00`; sonra ELEMAN `05 00` ve sıfırlanmış GCD_DIZI.

Hoca o anda NOP'un nedenini açıklayamadığını, bunun assembler'dan assembler'a değişebileceğini, kullanılan Microsoft Macro Assembler'da bu şekilde olduğunu söyleyip "tasarım gereği" dedi. Örnek 5'te bunun nedenine geri dönüldü (Bölüm 11.3).

### 10.6 Adım adım izleme

`T` ile ilerlendi. SI sıfırlandı, CX'e 5 yüklendi. İlk elemanlar alındı: AX = 1CH (28), DX = 0CH (12). AX'in DX'ten büyük olduğu biliniyor.

DEBUG, `JAE`'yi `JNB` (jump not below) olarak gösterdi. Hoca bunun nedeninin, ikisinin denk olması ve makine kodundan geri çevrilirken varsayılan bir komut adının kullanılması olduğunu söyledi; komut farklı değildir. Karşılaştırma sonucu doğru olduğu için L2'ye gidildi. Orada `CMP DX, 0` yapıldı; DEBUG `JE`'yi de eşdeğeri `JZ` olarak gösterdi. DX = 12 sıfır olmadığı için `MOV BX, DX`'ten devam edildi.

İlk turda DX geçici olarak BX'e alındı, DX sıfırlandı ve DX:AX $= 0:28$ değeri BX = 12'ye bölündü. Kalan DX = 4, bölüm AX = 2 oldu. Bir adım daha ile AX = 12 yapıldı. Yani $\gcd(28, 12)$'den $\gcd(12, 4)$'e geçildi.

İkinci turda DX = 4 sıfır değil; BX = 4, DX = 0, $12 / 4$ işleminde kalan DX = 0 oldu ve AX = 4 yapıldı. Döngünün başında DX = 0 olduğu için döngü kırıldı, `MOV GCD_DIZI[SI], AX` çalıştı, SI 2 arttı ve `LOOP` CX'i bir azaltıp L1'e döndü (ekrandan, 02:20:00). `D DS:100` ile bakıldığında GCD_DIZI'nin ilk gözünde `04 00` görüldü: 28 ile 12'nin EBOB'u 4.

### 10.7 G komutuyla kalan elemanlar

Kalan elemanlar için hoca, fazladan tanımın olmadığı LST dosyasından GCD döngüsünün hemen dışındaki ofseti (145H) buldu ve `G CS:145` ile her seferinde oraya kadar çalıştırdı:

- İkinci çift: AX = 0FH = 15. Hoca hesap makinesinde FFFFH'ın 0FH'ye bölündüğünü gösterdi.
- Üçüncü çift: 1 ile 28'in EBOB'u 1.
- Dördüncü çift: 100 ile 25'in EBOB'u 25 = 19H ($16 + 9 = 25$).
- Beşinci çift: 511 ile 3 aralarında asal olduğu için EBOB 1.

Son elemandan sonra `LOOP` döngüden çıktı ve `RET` satırına gelindi; bunun yürütülmesiyle işletim sistemine dönülür.

> **Ders sonrası not:** Hoca ikinci çifti "FFFF ile FFFF" olarak okudu. Kodda, LST'de ve bellekte ikinci y değeri 0FFFH'dır (`FF 0F`). $\gcd(FFFFH, 0FFFH) = \gcd(65535, 4095) = 15 = 0FH$ olduğu için sonuç doğrudur; iki değer de FFFFH olsaydı EBOB FFFFH olurdu.

Program yeniden yüklenip `G CS:14E` ile `RET` satırına kadar çalıştırıldı ve `D DS:100` ile bakıldı (ekrandan, 02:25:00):

```text
075A:0100  EB 21 90 1C 00 FF FF 01-00 64 00 FF 01 0C 00 FF
075A:0110  0F 1C 00 19 00 03 00 05-00 04 00 0F 00 01 00 19
075A:0120  00 01 00 33 F6 8B 0E 17-01 8B 84 03 01 8B 94 0D
```

GCD_DIZI (119H) gözlerinde `04 00`, `0F 00`, `01 00`, `19 00`, `01 00`, yani 4, 15, 1, 25, 1 vardır. 123H'den itibaren de kodun makine kodları (`33 F6` = `XOR SI, SI`, ...) başlar.

Hoca şablon 2'nin faydasını tekrar özetledi: COM programı yüklendiğinde IP hep 100H'dır. 100H'ya doğrudan veri yazılsaydı işlemci bu veriyi makine kodu sanıp komut olarak yürütmeye çalışırdı. 100H'ya bir JMP konunca JMP ile hedef etiket arasında bir boşluk oluşur ve bu boşluk veri tanımına ayrılır. Böylece verinin belli bir ofset aralığında olduğu kesin olarak bilinir. Şablon 1'de ise ana programın makine kodu boyutunu hesaplayıp o ofsete gitmek gerekirdi; bu hiç pratik değildir.

> **Hocanın vurgusu:** Ödev uygulamasında varsayılan derleme ortamı DOSBox'tır; yazılan kod DOSBox'ta çalışmak zorundadır. emu8086'da `SHL AX, 2` gibi bir yazım kabul edilir, ama DOSBox'taki assembler bunu kabul etmez.

> **Ek bilgi (derste anlatılmadı):** Orijinal 8086'da öteleme ve döndürme komutları yalnız 1 sayısını ya da CL'yi sayaç olarak alır. `SHL AX, 2` gibi sabit sayaçlı biçim 80186 ve sonrasında eklenmiştir. emu8086 bu yazımı kabul ederken MASM'ın 8086 kipi kabul etmez; 8086 için `MOV CL, 2` / `SHL AX, CL` yazılır.

## 11. Örnek 5: 500 Elemanlı Word Dizisinin Ortalaması

### 11.1 Problem

Hoca örnek listesindeki bir problemi değiştirerek kullandı. Asıl problem bir byte dizisi içindi; hoca bunu word dizisine çevirdi ve dizinin çok elemanlı, en az 500 elemanlı olmasını istedi. Soru, kaynak dosyanın başına yorum olarak yazıldı (ekrandan, 02:45:00):

```text
; işaretsiz sayılardan oluşan word tipindeki
500 elemanlı dizinin ortalamasını bulan COM
tipi Assembly kodunu yazınız
```

### 11.2 Analiz

Eleman sayısı 500 olduğu için word olarak tanımlanmalıdır. Hoca, bir önceki örnekte 5 elemanın bile word tanımlandığını hatırlattı: eleman sayısı byte olarak tanımlansaydı CX'e atarken sorun çıkardı. Byte tanımlı bir eleman sayısını CX'e atamak için önce CX sıfırlanır, sonra sayı 8 bitlik CL'ye atanır.

Elemanların her biri word olduğu için ortalama bir word'e sığar. Ama dizi toplanırken biriktirilen değer 16 biti aşabilir. Bu yüzden toplamı tutacak değişken 32 bitlik sanal bir yazmaç olmalıdır. 16 bitlik bölme zaten DX:AX üzerinden yapıldığı için biriktirme DX:AX'te yapıldı.

Veri şöyle tanımlandı: ilk beş eleman 0FFFFH, 100, 28, 1, 0 olarak açıkça yazıldı, kalan 495 eleman `DUP` ile 256 değeriyle dolduruldu. Toplam 500 word, yani 1000 byte'tır; 64K'lık segmentte yer sorunu beklenmez.

İlk derlemede `DUP 495 (256)` yazımı "DUP'un count'u verilmedi" hatası verdi. `DUP`'ta tekrar sayısı başa yazılır: `495 DUP (256)`, yani "495 tane 256 değerini tekrarla".

### 11.3 Kod ve LST

Bu kez dizi gösterici yöntemiyle dolaşıldı: `LEA SI, DIZI`, her turda `ADD SI, 2`. Döngüye girmeden önce AX ve DX `XOR` ile sıfırlanmalıdır. Döngüde sıradaki eleman `ADD AX, [SI]` ile AX'e eklenir. İlk turda AX 0 olduğu için elde oluşmaz, ama ilerleyen turlarda AX'teki toplamla yeni word toplandığında elde oluşabilir. Bu elde `ADC DX, 0` ile DX'e aktarılır: ADC, DX ile 0 sabitini toplar ve varsa carry bitini de ekler. Döngü bittiğinde DX:AX'te bütün elemanların toplamı vardır. Sonra eleman sayısı BX'e alınıp `DIV BX` ile DX:AX / BX yapılır: kalan DX'e, bölüm AX'e yazılır. Bölüm ortalamadır ve `ORT` değişkenine yazılır.

Kod şöyleydi (ekrandan, 02:40:00 ve 02:50:00):

```text
CODESG  SEGMENT PARA 'CODE'
        ORG 100H
        ASSUME CS:CODESG, SS:CODESG, DS:CODESG, ES:CODESG
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
CODESG  ENDS
        END BILGI
```

<!-- BELİRSİZ: MOV ORT, AX, RET ve sonraki satırlar karelerde görünmüyor; altyazıdaki anlatımdan ve şablondan alındı. -->

LST dosyasında (ekrandan, 02:45:00) JMP bu kez `0100  E9 04EF R` olarak görüldü. DIZI 103H'da başlar; ELEMAN 4EBH'de (`01F4`), ORT 4EDH'de (`0000`), BASLA 4EFH'de yer alır. $103H + 500 \cdot 2 = 103H + 3E8H = 4EBH$ olduğu için bu ofsetler tutarlıdır. Döngü kodları: `04FB 03 04` = `ADD AX, [SI]`, `04FD 83 D2 00` = `ADC DX, 0`, `0500 83 C6 02` = `ADD SI, 2`, `0503 E2 F6` = `LOOP L1`.

Hoca, bu kez JMP'nin ardında 90H (NOP) olmadığını fark etti ve şöyle yorumladı: veri tanımı kısaysa ana prosedür yakında başlar ve dallanma 8 bitlik bir uzaklıkla gösterilebilir; bu durumda üç byte'ın sonuncusuna NOP konur. NOP'a hiçbir zaman düşülmez, çünkü JMP onun üzerinden atlar. Veri tanımı çok genişse JMP ve 16 bitlik uzaklık doğrudan bu üç byte'a yazılır. Her iki durumda da veri JMP'den sonraki üç byte'tan itibaren başlar ve veri başlangıcı standart kalır.

> **Ek bilgi (derste anlatılmadı):** MASM gibi assembler'lar ileriye doğru bir etikete (forward reference) dallanmada, etiketin uzaklığı henüz bilinmediği için ilk geçişte büyük olasılıkla üç byte'lık yakın JMP'ye yer ayırır. Hedef sonradan 127 byte'tan yakın çıkarsa iki byte'lık kısa JMP (`EB xx`) üretilir ve ayrılan üçüncü byte NOP ile doldurulur. Örnek 4'teki `EB 21 90` ile örnek 5'teki `E9 ...` arasındaki fark büyük olasılıkla bundan kaynaklanır; `JMP SHORT BASLA` yazılsaydı NOP oluşmazdı.

### 11.4 DEBUG ile izleme

Program masm, link ve exe2com aşamalarından geçirilip DEBUG'da açıldı. Hoca girişte yine SP'nin FFFEH olduğunu ve `SS:FFFE`'de 0000 bulunduğunu, COM programında geri dönüş için ek bir işlem gerekmediğini vurguladı.

`LEA SI, DIZI` sonrası SI = 103H oldu. Bu, 100H'daki üç byte'lık JMP'den hemen sonraki ofsettir ve dizinin başlangıcıdır. CX'e 500 = 1F4H yüklendi; hoca bunu $256 + 15 \cdot 16 + 4 = 500$ diye doğruladı. AX ve DX sıfırlandı.

İlk turda AX = FFFFH, DX = 0 oldu ve elde oluşmadı (NC). İkinci turda 100 eklenince elde oluştu; AX güncellendi ve `ADC DX, 0` ile DX bir arttı. Toplam döngüsünün bittiği yere kadar `G CS:505` ile çalıştırıldı (ekrandan, 02:50:00). Orada DX = 0002, AX = EF80 görüldü.

Hoca bunu hesap makinesiyle doğruladı (ara adım eklendi):

$$100H \cdot 495 + FFFFH + 129 = 126720 + 65535 + 129 = 192384 = 2EF80H$$

Burada 129, diğer elemanların toplamıdır ($100 + 28 + 1 + 0$). DX:AX = 0002:EF80 olduğu için toplama doğrudur.

Sonra `MOV BX, ELEMAN` ile BX = 01F4H (500) yapıldı ve `DIV BX` çalıştırıldı:

$$192384 = 500 \cdot 384 + 384$$

Bölüm AX = 180H (384), kalan DX = 180H (384) oldu. Hoca kalanla bölümün aynı çıkmasını ilginç bulup hesap makinesinde tekrar kontrol etti. Ortalama, analizde beklendiği gibi 256'dan biraz büyüktür.

Bölüm `MOV ORT, AX` ile 4EDH ofsetine yazıldı. Veri çok uzun olduğu için `D DS:100` ile bu göze ulaşılamaz; hoca `D DS:4ED` ile baktı ve düşük byte'ı 80H, yüksek byte'ı 01H olan değeri, yani 180H'yı gördü. Bir adım daha yürütülünce işletim sistemine (DOSBox'a) dönüldü.

> **Ek bilgi (derste anlatılmadı):** `DIV BX`'te bölüm 16 bite sığmazsa işlemci bölme hatası kesmesi üretir. Burada toplam en fazla $500 \cdot 65535$ olabileceği için bölüm en fazla 65535 olur ve sığar. Aynı yöntem eleman sayısından küçük bir sayıya bölmede (örneğin toplamı 2'ye bölmede) taşma riski taşır.

Hoca bu örneğin word dizileriyle çalışırken boyutlara ve alınabilecek en büyük değerlere dikkat edilmesi gerektiğini vurgulayan bir örnek olduğunu söyledi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:30:17): İşletim sistemine dönüş adresinin ofseti neden 0'dır?

> **Çözüm:** Her 20 bitlik fiziksel adres farklı segment:ofset çiftleriyle yazılabilir ve bir segment + 0 ofset biçimine normalize edilebilir. Örneğin FFFF0H = `FFFF:0000` = `FAAA:5550` ($FAAA0H + 5550H = FFFF0H$). Ofset 0 kabul edilince ofset için ikinci bir yazmaç harcanmaz. Bu bir yazılım tasarımı kararıdır.

**Soru 2** (derste sözlü, 00:55:47): COM tipi programda SP neden FFFFH değil de FFFEH ile başlar?

> **Çözüm:** FFFFH tek bir sayıdır, yığın ise word ile çalışır. Ayrıca program çağrılır çağrılmaz işletim sistemi dönüş ofsetini (0000H) yığına atar ve SP sıradaki dolu gözü gösterir. Bu yüzden SP = FFFEH'dır ve `SS:FFFE`'de `00 00` görülür.

**Soru 3** (derste sözlü, 01:10:11): emu8086'da yazılan MOV komutları adım adım çalıştırılırken neden ADD, AND ya da RET gibi görünebilir?

> **Çözüm:** Disassembly bir komutun ortasından başlatılırsa makine kodu yanlış byte'tan çözülür; örneğin bir byte ileriden bakılınca `C3` byte'ı `RET` olarak okunur. Kod bloğu bittikten sonraki programlanmamış gözlerdeki çöp değerler de komut gibi çözülür. Kod doğru ofsetten başlatılırsa sorun olmaz.

**Soru 4** (ekrandan, 01:45:00 ve 02:20:00): `X_DIZI DW 28, 0FFFFH, 1, 100, 511` ve `Y_DIZI DW 12, 0FFFH, 28, 25, 3` dizilerinin karşılıklı elemanlarının en büyük ortak bölenlerini `GCD_DIZI`'ye yazan COM tipi programı yazınız.

> **Çözüm (derste verildi):** Bölüm 9.5'teki kod. $\gcd(x, y) = \gcd(y, x \bmod y)$ ve $\gcd(x, 0) = x$ kullanılır; x < y ise `XCHG AX, DX` ile takas edilir, DX ≠ 0 olduğu sürece `MOV BX, DX`, `XOR DX, DX`, `DIV BX`, `MOV AX, BX` tekrarlanır. Sonuç: `GCD_DIZI` = 4, 0FH, 1, 19H, 1 (yani 4, 15, 1, 25, 1). Örneğin $\gcd(12, 28) = \gcd(28, 12) = \gcd(12, 4) = \gcd(4, 0) = 4$.

**Soru 5** (ekrandan, 02:45:00): İşaretsiz sayılardan oluşan word tipindeki 500 elemanlı dizinin ortalamasını bulan COM tipi Assembly kodunu yazınız. Dizi: `DW 0FFFFH, 100, 28, 1, 0, 495 DUP (256)`.

> **Çözüm (derste verildi):** Bölüm 11.3'teki kod. Toplam DX:AX'te `ADD AX, [SI]` ve `ADC DX, 0` ile biriktirilir, `DIV BX` (BX = 500) ile bölünür. Toplam $= 65535 + 129 + 495 \cdot 256 = 192384 = 2EF80H$; bölüm $= 384 = 180H$ (ORT), kalan $= 384 = 180H$.

**Soru 6** (derste sözlü, 02:10:00): COM programında `ORG 100H` ile giriş etiketi `BILGI` arasına bir `DW 0` tanımı eklenirse ne olur?

> **Çözüm (derste denendi):** LST'de bu tanım için bir word yer ayrılır, ama COM'a dönüştürme "cannot convert" hatası verir ve program yüklenmez. COM programında giriş noktası tam 100H'da olmalıdır, çünkü IP her zaman 100H ile başlar.

## Dersin Toparlaması

Bu derste EXE tipi program yapısı tekrar edilip COM tipi programlarla karşılaştırıldı. EXE'de üç segment, FAR ana yordam, girişte dönüş adresini yığına atan `PUSH DS` / `XOR AX,AX` / `PUSH AX` ve DS'yi yükleyen iki MOV satırı gerekir. SP yığın boyutuyla başlar ve yığın boştur. COM'da ise tek segment vardır. `ORG 100H` ile ilk 256 byte header'a ayrılır, ana yordam NEAR'dır, dönüş ofseti 0000H işletim sistemi tarafından yığına konur ve SP FFFEH, IP 100H ile başlar. Bütün segment yazmaçları aynı değeri taşır. Verinin ofsetini sabitlemek için şablon 2'de giriş noktasına bir JMP konup veri onun arkasına yazılır. Giriş noktası tam 100H'da değilse COM'a dönüştürme başarısız olur.

İki COM örneği yazılıp MASM, LINK ve EXE2BIN/exe2com ile derlendi ve DEBUG'da izlendi. EBOB örneğinde Öklid algoritması tek indis yazmacıyla (SI) ve `DIV`'in kalan üretmesinden yararlanarak geçici değişken olmadan yazıldı. Ortalama örneğinde 500 word'ün toplamı DX:AX'te `ADD`/`ADC` ile biriktirilip `DIV` ile bölündü. LST dosyalarında MASM'ın kısa dallanmada `EB xx 90`, uzak dallanmada `E9 xx xx` ürettiği görüldü. Hoca, EXE programları arasında parametre paylaşımının ve segment birleştirme mantığının (sınıf adlarının rolü dahil) henüz görülmediğini, bunların ilerideki konular olduğunu söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
