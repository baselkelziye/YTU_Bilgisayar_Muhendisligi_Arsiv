# Ders 9 Genişletilmiş Notu: Prosedürler ve Makrolar, Ayrı Dosyada Yordam Çağırma ve Özyinelemeli EBOB

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Neden Prosedür ve Makro?
- 2. Prosedür ile Makronun Farkı
- 3. Prosedür Tanımı ve CALL/RET Sırasında Yığın
- 4. Makro Tanımı ve LOCAL
- 5. Parametre Aktarım Yolları
- 6. EBOB Örneğinin İki Dosyaya Bölünmesi
- 7. EXTRN ve PUBLIC: Assembler ve Linkleme Hataları
- 8. Döngüsel GCD_PROC ve Derleme
- 9. LST ve MAP Dosyalarının İncelenmesi
- 10. Debug ile FAR Çağrıda Yığının İzlenmesi
- 11. Aynı Dosyada İki Prosedür: FAR PTR ve NEAR Çağrı
- 12. Özyinelemeli GCD_PROC
- 13. Debug ile Özyinelemeli Çağrılarda Yığın
- 14. Dersin Özeti ve Sonraki Konular
- 15. Soru-Cevap: Tail Call Optimization
- Örnek Sorular

## 1. Neden Prosedür ve Makro?

Bu haftanın konusu makrolar ve yordamlardır (slayt başlığı "PROSEDÜR VE MAKRO", ekrandan, 00:15:00). Hoca konuya diğer programlama dillerinden bilinen fonksiyon mantığıyla girdi. Geliştirilen yazılımdaki fonksiyonel birimlerin hepsini tek bir dosyada tutmak, onları sürdürmeyi ve iyileştirmeyi zorlaştırır. Kendi içinde bütün olan bir işi ayrı bir fonksiyon olarak geliştirmek, gerektiğinde iyileştirmek ve ihtiyaç olduğunda herhangi bir koda harici bir fonksiyon olarak çağırmak, takip edilebilir ve sürdürülebilir bir yapı verir.

Tek dosya içinde ana prosedür ve alt prosedürler şeklinde fonksiyonel bir yapı kurmak da mümkündür. Hocaya göre daha sürdürülebilir olanı, fonksiyonları ayrı bir kütüphane ya da dosya olarak geliştirip ana prosedürden çağırmaktır. Aynı düşünce makrolar için de geçerlidir: makro da kendi başına anlamı olan bütüncül bir kod parçasıdır ve ayrı dosyalarda tanımlanıp iyileştirilebilir.

Ders boyunca şu sorulara yanıt aranır: Program fonksiyon, prosedür ve makro gibi parçalara nasıl bölünür? Bu parçalar ana prosedürden nasıl çağrılır? Onlara nasıl parametre aktarılır? Bir makro birden çok kez çağrıldığında nelere dikkat edilir?

### 1.1 EXE ve COM programlarında yordam tipleri

Hoca önceki haftalardan şunu hatırlattı: EXE tipi programlarda bir ana prosedür bulunmalıdır ve bu prosedür kesinlikle FAR tipinde tanımlanmalıdır. Programın ana akışını bu prosedür belirler. Bu prosedür içinden çeşitli alt yordamlar çağrılabilir; bunlar NEAR tipinde tanımlanabilir.

> **Hocanın vurgusu:** COM tipi programda aynı dosya içinde kullanılan fonksiyonların hepsi NEAR tipindedir. Buna dikkat edilmelidir.

### 1.2 Modülerliğin kazançları

Prosedür ve makro yaklaşımı modüler geliştirmeyi sağlar. Bir modül, beklediği girdiler ve üretebileceği çıktılarla tanımlı olduğu için, girdi ve çıktıların tipi ve sayısı sağlandığı sürece farklı prosedürlerden çağrılabilir. Kod modüler olduğunda iyileştirme o fonksiyona özel yapılabilir. Örneğin bir uç durum gözden kaçmışsa, yalnız ayrı dosyadaki o fonksiyona odaklanılarak düzeltilir. Ayrıca kod düz (structural) bir akış yerine fonksiyon yapısı içinde kullanıldığı için tekrar kullanılabilir ve aynı şeyleri yeniden yazma derdi ortadan kalkar.

## 2. Prosedür ile Makronun Farkı

Bir prosedür çağrıldığında program akışı o anki Instruction Pointer noktasını bırakır, fonksiyonun yazıldığı bölgeye gider ve oradan itibaren kodu çalıştırır. Dönüşte RET ile, fonksiyonun çağrıldığı CALL satırından hemen sonraki satırdan devam edilir.

Makro çağrıldığında ise makronun kodu bir blok olarak çağrıldığı yere kopyalanır. Bu yüzden iki yaklaşımın kod boyutuna etkisi farklıdır:

- **Prosedür:** Çağrılan fonksiyonun makine kodu programda tek bir kopya olarak bulunur. Her çağrı kod boyutunu büyütmez.
- **Makro:** Her çağrıda kod bloğunun bir kopyası ana fonksiyonda çağrıldığı yere konur. Her makro çağrısı makine kodunu makro boyutu kadar artırır.

## 3. Prosedür Tanımı ve CALL/RET Sırasında Yığın

### 3.1 Tanım şablonu

Slayttaki şablon şöyledir (ekrandan, 00:20:00):

```text
Yordam_ismi PROC {NEAR|FAR}
        yordam_kodu
        RET
Yordam_ismi ENDP
```

Önce söz dizimine uygun bir yordam ismi verilir. Bu etiketin bir prosedür olduğunu belirtmek için `PROC` kelimesi yazılır. Ardından isteğe bağlı olarak tip yazılır; tip belirtilmezse NEAR kabul edilir, FAR istenirse açıkça yazılmalıdır. Yordam aynı etiket ve `ENDP` kelimesiyle kapatılır. FAR tipindeki yordamdan mutlaka `RETF` (return far) ile, NEAR tipindekinden `RET` ile dönülür. İki tanım arasında, RET'e kadar olan alanda yordamın yapacağı işler yazılır.

### 3.2 Yazmaçlar parametre gibidir

Ana programda bir kod parçası yürütülürken bir CALL ile karşılaşıldığında IP değiştirilerek alt yordamın tanımlı olduğu bölgeye gidilir. Bu anda yazmaçlardaki değerler ana programda neyse öyle kalır. Bu yüzden yazmaçlar alt yordama doğrudan aktarılmış parametreler gibi düşünülebilir. İstisnalar şunlardır: NEAR çağrıda IP zaten yığına atılır ve değişir; FAR çağrıda CS ve IP birlikte yığına atılır ve değişir. Bunların aktarılacak anlamlı bir veri taşıması mümkün değildir.

### 3.3 Dönüş CALL'dan sonraki satıra yapılır

FAR çağrıda dönüşte (RETF) yığından önce ofset, sonra segment değeri çekilir ve IP ile CS'ye yüklenir. Böylece ana programda kalınan yerden devam edilir. Kalınan yer CALL satırı değil, bir sonraki satırdır. Hoca bunu şöyle açıkladı: akış yukarıdan aşağı gelip CALL ile alt yordama gitse, işi bitirip yeniden CALL satırına dönse, CALL tekrar çalışır ve alt yordam yeniden çağrılırdı. Bu anlamlı değildir; doğru davranış, CALL'dan sonraki satırdan devam etmektir.

### 3.4 NEAR prosedür çağırma

Slayttaki EXE programında yığın, veri ve kod kesimi vardır; kod kesiminde bir ana prosedür ve bir `PROSEDÜR P1` bulunur. Ana prosedür içinde iki kez `CALL P1` geçer (ekrandan, 00:25:00). Akış şöyledir: yukarıdan aşağı gelinir, birinci `CALL P1`'de P1 yürütülür, sonra birinci CALL'dan sonraki satırdan devam edilir; ikinci `CALL P1`'de yine P1'e gidilir ve dönüşte ikinci CALL'dan sonraki kısımla akış tamamlanır.

NEAR prosedür için yığının durumu şöyledir. CALL'dan hemen önce, parametre aktarımı açısından yığın boş düşünülebilir; yalnız ana prosedürün sonundaki RET ile ilgili, işletim sistemine dönüş değerleri bulunabilir. CALL NEAR ise IP değeri yığına atılır (slaytta "İlk CALL sonucu IP yığına atılır"). Alt yordamın RET satırına gelindiğinde yığının en üstündeki değer çekilip IP'ye yüklenir.

> **Hocanın vurgusu:** RET, yığının içinde IP değerini arayıp bulmaz; yığının en üstündeki değeri alıp IP'ye yükler. Alt yordam yürütülürken yığına bir şey atılır ve uygun şekilde geri çekilmezse, en üstteki değer artık dönüş adresi olmaz ve program yanlış bir yere döner. Yığına bir şey atıyorsak uygun seviyede ve sırada geri çekmeliyiz.

### 3.5 FAR prosedür çağırma

Çağrılan alt prosedür FAR tipindeyse, CALL anında yığına önce o anki kod segment değeri, sonra IP değeri atılır. Alt yordam yürütülür, yığına atılanlar uygun sırada geri çekilir ve RETF satırına gelinir. RETF yığının en üstündeki değeri çekip IP'ye, sıradaki değeri çekip CS'ye yazar. Hoca burada da sistemin yığında "IP" ya da "CS" olarak etiketlenmiş değerleri aramadığını vurguladı; böyle bir şey mümkün değildir, çünkü yığındaki değerlerden hangisinin ne olduğunu bilemez. Yalnız sıraya göre çalışır.

## 4. Makro Tanımı ve LOCAL

### 4.1 Tanım şablonu

Slayttaki makro şablonu şöyledir (ekrandan, 00:30:00):

```text
Makro_ismi MACRO {parametre_listesi}
        LOCAL ...
        makro_kodu
        ENDM
```

Makro bir isim etiketiyle başlar; makro olduğunu belirtmek için `MACRO` kelimesi kullanılır. Ardından virgülle ayrılan bir parametre listesi verilebilir; bu parametreler makro içinde olduğu gibi kullanılır. Örneğin makro çağrılırken veri kesiminde tanımlı değerler parametre olarak verilebilir. Burada uyumluluk önemlidir: tanımda ilk parametre bir dizinin başlangıç adresi, ikinci parametre o dizinin eleman sayısıysa, ana yordamda çağırırken veri kesimindeki benzer boyut ve tipteki değerler bu sırayla verilmelidir. Makro `ENDM` (end macro) ile biter.

### 4.2 LOCAL ile benzersiz etiketler

Makro tanımından hemen sonra gelen `LOCAL` kelimesinin ardındaki adlar parametre değildir. Bunlar makro kodu içinde dallanma ve döngüler için kullanılan etiketlerdir. Bu liste, makro tekrar tekrar çağrıldığında benzersiz değerler üretmek için kullanılır.

Hocanın örneği: makronun içinde bir `L1` etiketi ve bu etikete koşullu bir dallanma olsun. Makro birden çok kez çağrılırsa kod blok olarak kopyalandığı için programda birden fazla `L1` etiketi oluşur. `LOCAL` kullanıldığında assembler birinci ve ikinci kopyadaki `L1`'leri otomatik olarak benzersiz adlarla değiştirir. Üstelik kopyadaki `JA L1` gibi dallanma komutunun hedefi de bu yeni adla uyumlu olacak şekilde değiştirilir. Böylece tekrarlı makro çağrılarında etiketlerin karışması önlenir.

### 4.3 Makronun kodu nerede üretilir?

Bir EXE programında ana prosedür içinde M1 adlı bir makronun iki kez çağrıldığını ve makronun tanımının da aynı dosyada olduğunu düşünelim. Derlemeye geçmeden önce her makro çağrısının yerine ilgili kod parçası olduğu gibi kopyalanır. Kod boyutu M1'in boyutunun iki katı kadar büyür. Makro tanımının kendisi için makine kodu üretilmez; makine kodu yalnız makronun kopyalandığı yerler için üretilir.

## 5. Parametre Aktarım Yolları

Hoca, sonra makro ve yordam örneklerine (aynı dosyada ve farklı dosyalarda) ve aralarındaki parametre aktarımına bakılacağını söyledi. Parametre aktarımı farklı yollarla yapılabilir:

- **Yazmaçlar üzerinden:** Varsayılan durumdur. Alt yordam çağrıldığında yazmaçlardaki değerler olduğu gibi alt yordama taşınır; yani bunlar zaten aktarılmış parametrelerdir.
- **Yığın üzerinden:** Alt yordamı çağırmadan, yani CALL'dan önce gerekli parametreler yığına atılır. Örneğin FAR çağrıda yığının en üstünde CS ve IP olur, aktarılan parametreler bunların altında kalır. Alt yordamda parametrelerin yığının o anki tepesine göre nerede olduğu belirlenmelidir; bunun için BP yazmacı kullanılacak, BP ile parametrelerin yığındaki ofseti bulunup oradan çekilecektir. Dönüş için birkaç seçenek vardır: iki parametre aktarılıp iki değer dönülecekse parametrelerin üzerine yazılarak yığından dönülebilir; iki parametre aktarılıp bir değer dönülecekse aynı mantıkla, ama hangi parametrenin üzerine yazıldığı özellikle belirlenerek yapılır; ya da parametre yığından aktarılıp sonuç yazmaçtan döndürülebilir.
- **Ortak veri kesimi ya da harici veri üzerinden:** İki ayrı dosyada tanımlı veri kesimlerindeki etiketler `EXTRN` ve `PUBLIC` kelimeleriyle birbirinden kullanılabilir. Bunun ileri aşaması ortak veri kesimi kullanımıdır; veri kesimleri birleştirilir ve aynı segmentin farklı ofsetleri üzerinden veriye erişilir.

Yığın üzerinden aktarım başka bir haftanın konusudur. Bu derste yazmaç üzerinden aktarım ve prosedürlerin nasıl ele alınacağı işlenir.

## 6. EBOB Örneğinin İki Dosyaya Bölünmesi

### 6.1 Önceki haftanın örneği

Hoca, önceki haftalarda yazılan en büyük ortak bölen (EBOB, GCD) örneğini hatırlattı. Gösterilen `O4.asm` bir COM programıdır: `ORG 100H`, bütün kesim yazmaçları `CODESG`'yi gösterir, `X_DIZI DW 28, 0FFFFH, 1, 100, 511`, `Y_DIZI DW 12, 0FFFH, 28, 25, 3`, `ELEMAN DW 5`, `GCD_DIZI DW 5 DUP(0)` tanımlıdır ve `BASLA PROC NEAR` içinde dizilerin karşılıklı elemanları AX ve DX'e alınarak EBOB hesaplanır (ekrandan, 00:40:00). İki dizinin karşılıklı elemanlarının EBOB'u üçüncü bir diziye yazılıyordu. Bu programda ana prosedür ve EBOB'u hesaplayan kısım aynı düz akış içindeydi.

Sürdürülebilirlik açısından izlenecek yol, word tipindeki iki sayının EBOB'unu hesaplayan kısmı bir fonksiyon, bir kütüphane haline getirmektir. Tek bir sayı çifti için fonksiyon bir kez çağrılır; dizilerin karşılıklı elemanları için dizi eleman sayısı kadar çağrılır.

### 6.2 Ana yordam dosyası: GCD_reg.ASM

Ana yordam ve alt yordam ayrı birer ASM dosyasında tutulur. Ana yordam dosyası, yazmaçlar üzerinden parametre aktarılan bir alt yordam çağırma örneğidir. Veri kesiminde A ve B sayıları vardır; dışarıda tanımlı fonksiyon bu sayılarla çağrılır ve sonuç yine veri kesimindeki bir yere yazılır. Program EXE tipindedir ve EXE'nin başlangıç hazırlığını içerir (ekrandan, 00:50:00, 01:15:00 ve 01:30:00):

```text
        PAGE 60,80
        TITLE ornek____

EXTRN GCD_PROC:FAR

STACKSG SEGMENT PARA STACK 'STACK'
        DW 32 DUP(?)
STACKSG ENDS

DATASG  SEGMENT PARA 'DATA'
ASAYISI    DW 13
BSAYISI    DW 15
GCD        DW ?
DATASG ENDS

CODESG  SEGMENT PARA 'CODE'
        ASSUME CS:CODESG, DS:DATASG, SS:STACKSG

BASLA   PROC FAR
        PUSH DS
        XOR AX,AX
        PUSH AX

        MOV AX, DATASG
        MOV DS, AX

        MOV AX, ASAYISI
        MOV DX, BSAYISI

        CALL GCD_PROC
        MOV GCD, AX

        RETF
BASLA   ENDP

CODESG  ENDS
        END BASLA
```

A ve B, yazmaç üzerinden parametre olarak aktarılmak için veri kesiminden AX ve DX'e alınır, sonra fonksiyon çağrılır. Sonucun nereden döneceği alt yordamın tanımına bağlıdır; burada AX'ten döner ve `GCD` etiketine yazılır. Daha sonra fonksiyonda bir uç durum eksikse ya da gereksiz bir kontrol varsa, yalnız ayrı dosyadaki kod iyileştirilip başka programlarda da kullanılabilir.

Hoca standart EXE iskeletini işaretleyerek bu iskelette `GCD_PROC` adlı bir etiket tanımı olmadığına dikkat çekti. Amaç onu harici bir dosyadan kullanmaktır. En üstteki `EXTRN` satırı bu yüzden vardır.

## 7. EXTRN ve PUBLIC: Assembler ve Linkleme Hataları

### 7.1 EXTRN

`GCD_PROC`'un dışarıdan kullanılacak bir fonksiyon olduğunu, karşılığının linkleme seviyesinde bulunacağını belirtmek için `EXTRN GCD_PROC:FAR` yazılır. Hoca bunu deneyle gösterdi (ekrandan, 00:45:00):

- **EXTRN satırı kaldırıldığında:** `GCD_reg.asm` derlenirken assembler hata verir; çünkü CALL'da adres olarak kullanılan `GCD_PROC` etiketi bu EXE programının kodunda tanımlı değildir.
- **EXTRN geri konduğunda:** Alt yordamı içeren dosya henüz derlenmemiş olsa bile ana dosyanın obje dosyası oluşur.
- **Tek başına linklendiğinde:** Bu kez linkleme aşamasında etiketin linke verilen hiçbir obje dosyasında bulunamadığı hatası çıkar.

Çözüm, alt yordamı içeren `GCD_alt.asm`'yi de assembler'dan geçirip obje dosyasını oluşturmak ve iki obje dosyasını birlikte linklemektir. Ana yordamda dış alt yordam EXTRN olarak ve FAR tipinde tanımlanmıştır; alt dosyadaki fonksiyon da FAR tipindedir. İkisi linklenince EXE oluşur.

> **Hocanın vurgusu:** EXTRN tanımı yapılmazsa obje dosyası oluşturulurken (assembly aşamasında) hata alınır. EXTRN yazılır ama etiketin karşılığı bir obje dosyası olarak linke verilmezse linkleme seviyesinde hata alınır. İki seviyenin de uygun şekilde geçilmesi gerekir.

### 7.2 PUBLIC

Ana yordamda EXTRN ne ise, alt yordamda da benzer bir işlem `PUBLIC` kelimesiyle yapılmalıdır. `PUBLIC GCD_PROC`, bu dosyada tanımlanan etiketin linkleme aşamasında başka dosyalar tarafından adresleneceğini, yani dışarıya kullandırılacağını belirtir. Hoca alt dosyadaki satırı `;PUBLIC GCD_PROC` biçiminde yorum yaparak denedi (ekrandan, 00:50:00): ana yordam derlendi, obje dosyası oluştu; alt yordam derlendi, obje dosyası yine oluştu ve hata yoktu, çünkü henüz kimse bu fonksiyona dışarıdan erişmeye çalışmamıştı. Dışarıdan ilk erişim linkleme aşamasında olur ve orada yine "`GCD_PROC` etiketine erişemedim" hatası çıktı. Ana dosyada EXTRN olsa bile etiketi PUBLIC olarak sunan bir obje dosyası olmadığı için aynı hata alınır.

### 7.3 Linkleme komutu ve sıra

İki dosya linklenirken komut `LINK birinci_obje + ikinci_obje` biçimindedir; isteğe bağlı olarak bir MAP dosyası da oluşturulur. Hoca, alt yordamın obje dosyasını önce vererek ters sırayla da linkledi ve sorun çıkmadı. Sıra önemli değildir; önemli olan bir dosyada PUBLIC, diğerinde EXTRN tanımının bulunmasıdır.

## 8. Döngüsel GCD_PROC ve Derleme

### 8.1 Girdi ve çıktının belgelenmesi

Hoca bir prosedür tanımlanırken girdisinin ve çıktısının mutlaka belirtilmesi gerektiğini söyledi. `GCD_PROC` girdi olarak AX ve DX'i kabul eder, sonucu AX'ten döndürür. Bu, dosyada yorum olarak yazıldı: `;GCD_PROC input AX, DX` ve `;GCD_PROC output AX` (ekrandan, 00:55:00).

Geçen hafta çizilen akışta x ve y sayıları vardı ve tanım şuydu:

$$\gcd(x,0)=x, \qquad \gcd(x,y)=\gcd(y,\ x \bmod y)$$

y sıfır olduğunda bu bir sonlanma koşuludur ve x döndürülür. x ilk parametre olduğu için AX'e, y ikinci parametre olduğu için DX'e karşılık gelir; çıktı da AX'tir.

### 8.2 Alt yordam dosyasının yapısı

Ana yordamı içeren EXE programında yığın, veri ve kod kesimi tanımlanır. Alt yordamı içeren dosyada ise yalnız bir kod kesimi yeterlidir (`CDESG SEGMENT PARA 'CODE'`, `ASSUME CS:CDESG`). Alt yordam kendine ait bir veri kesimi kullanmaz; kendine ait bir yığın kesimi de kullanmaz. Alt yordam çağrıldığında ana yordamın yığını kullanılır. Bunun nedeni şudur: ana program başladığında `STACK` kelimesiyle tanımlanan kesim yığın kesimi olur. Alt yordam çağrılınca yazmaçlar aynı değerlerle alt yordama taşındığından SS hâlâ ana programın yığınını gösterir. Alt yordamdaki RETF de bu yığını kullanır. Tek bir yığın vardır.

Prosedür FAR tipinde olduğu için `RET` yazılsa bile assembler onu RETF olarak algılar. Hoca yine de bir anlaşma yaptı: FAR tipinde bir yordam tanımlanıyorsa dönüşü de açıkça RETF yazılacaktır. Dosyadaki `RET` bu yüzden `RETF` olarak değiştirildi (ekrandan, 00:55:00).

### 8.3 Döngüsel gövde

Hoca önce özyinelemeli gövdeyi yoruma alıp geçen haftanın döngüsel akışını alt yordama taşıdı. Son hali şöyledir (ekrandan, 01:10:00):

```text
GCD_PROC PROC FAR

        CMP AX, DX
        JAE L2
        XCHG AX,DX

L2:
        CMP DX,0
        JE L3
        MOV BX, DX ; BX<-y
        XOR DX, DX
        DIV BX; 0:AX/DX; DX<-AX%DX;
        MOV AX, BX
        JMP L2

L3:
        RETF
```

Akış şöyledir. Önce iki sayı karşılaştırılır ve büyük olan AX'te, küçük olan DX'te kalacak şekilde gerekirse yerleri değiştirilir (`XCHG`). Sonra ikinci parametrenin sıfır olup olmadığı kontrol edilir. Sıfırsa ilk parametre, yani AX'teki değer sonuçtur ve dönülür. Sıfır değilse DX geçici olarak BX'e kopyalanır. 16 bitlik bölmede bölünen DX:AX sanal 32 bitlik çifti olduğu için DX sıfırlanır. Bölmeden sonra bölüm AX'te, kalan (mod değeri) DX'te kalır. İstenen, bölmeden önceki DX değerinin (BX'te saklanan eski y) yeni birinci parametre olmasıdır; bu yüzden `MOV AX, BX` yapılır ve başa dönülür. Bu, geçen hafta yapılan işlemin birebir karşılığıdır.

> **Ders sonrası not:** Koddaki `DIV BX; 0:AX/DX; DX<-AX%DX;` yorumu bölenin DX olduğunu düşündürebilir. `DIV BX` komutu DX:AX çiftini BX'e böler. DX = 0 yapıldığı için işlem AX / BX'tir; bölüm AX'e, kalan (AX mod BX) DX'e yazılır. BX eski y değerini tuttuğu için kalan $x \bmod y$ olur.

### 8.4 Derleme sırasında düzeltilen hatalar

İlk derlemede `DEVAM` diye bir etiketin bulunmadığı hatası alındı; döngü etiketi `L2` olarak düzeltildi. Hoca ayrıca karşılaştırma dallanmasını yeniden kontrol etti. İlk yazımda `JA` olan dallanma son kodda `JAE L2` biçimindedir (ekrandan, 01:00:00 ve 01:10:00). Ardından `GCD_alt` derlendi, ana yordam `GCD_REG` adlı bir LST dosyasıyla derlendi ve iki obje dosyası `GCD_REG` adlı bir EXE ve MAP dosyası oluşturacak şekilde linklendi.

## 9. LST ve MAP Dosyalarının İncelenmesi

### 9.1 Ana yordamın LST dosyası

Ana yordamın LST dosyasında (ekrandan, 01:05:00) yığın kesimi `0000`'dan `0040`'a kadar uzanır (`DW 32 DUP(?)` → `0020[????]`). Veri kesiminde `ASAYISI` 0000 ofsetinde `000D`, `BSAYISI` 0002 ofsetinde `000F`, `GCD` 0004 ofsetinde `0000` olarak görünür. Kod kesiminin başında `PUSH DS` (`1E`), `XOR AX,AX` (`33 C0`), `PUSH AX` (`50`) ve `MOV AX, DATASG` (`B8 ---- R`) bulunur.

Hoca özellikle CALL satırına dikkat çekti. Alt yordamın nerede olacağı bilinmediği ve EXTRN olarak tanımlandığı için, bu satırda linkleme ya da programın belleğe yüklenmesi sırasında doldurulmak üzere bir yer bırakılır. Geri kalan her şey alışılmış durumdur: örneğin `DATASG` etiketi de program belleğe yüklendiğinde göreli olarak belirlenir, çünkü veri kesiminin nereye yükleneceği bilinmez.

CALL satırında `FAR PTR` kullanılmamıştır. Gerek yoktur, çünkü `EXTRN GCD_PROC:FAR` tanımı yüzünden bu çağrı FAR olarak yapılır: yığına IP ve CS atılır, dönüşte de yığının tepesinden IP ve CS çekilir.

### 9.2 Alt yordamın LST dosyası

Alt yordamın LST dosyasında özel bir durum yoktur. Yalnız PUBLIC olarak tanımlanan fonksiyon, linkleme aşamasında diğer tarafa bir etiket olarak sunulur.

### 9.3 MAP dosyası

MAP dosyası linkleme aşamasında oluşur ve oluşan EXE'de hangi kesimlerin tanımlandığını gösterir. İki dosyalı yapıda ana yordamın bulunduğu `GCD_REG` dosyasından üç kesim (yığın, veri, kod) gelir. Bunlara ek olarak alt yordamı içeren dosyanın kod kesimi de vardır. Yani bu EXE programın iki kod kesimi olmuştur.

Hoca karşılaştırma için önceki haftaların iki programının MAP dosyalarını da oluşturdu:

- **COM programı (O4.asm):** COM programı EXE2BIN ile EXE'den dönüştürülür. MAP dosyasında tek bir kesim vardır; bu kesim hem kod, hem yığın, hem veri kesimi olarak kullanılır.
- **Tek prosedürlü EXE programı (O3.asm):** Yığın, veri ve kod için üç ayrı kesim görülür.
- **İki dosyalı yapı:** İki kod kesimi, bir veri kesimi ve bir yığın kesimi görülür.

MAP dosyasındaki giriş noktası (entry point) `END BASLA` etiketinden gelir ve ana kod kesiminin sıfır ofsetini gösterir.

## 10. Debug ile FAR Çağrıda Yığının İzlenmesi

### 10.1 Başlangıç ve SP'nin değeri

EXE programı DEBUG ile yüklendiğinde (ekrandan, 01:10:00) yazmaçlar `SP=0040`, `DS=075A`, `SS=076A`, `CS=076F`, `IP=0000` değerlerindedir. EXE programlarında işletim sistemi programı yüklediğinde DS'de işletim sistemine dönüş segment değeri bulunur ve işletim sistemi, verdiği DS'nin sıfır ofsetine dönülmesini ister. Bunun için ilk üç satır (`PUSH DS`, `XOR AX,AX`, `PUSH AX`) dönüş segmentini ve sıfır ofsetini kendi yığınımıza yazar. Sonraki iki satır (`MOV AX, DATASG`, `MOV DS, AX`) tanımlanan veri kesimini DS'ye yükler.

SP'nin değeri şöyle açıklanır (ara adım eklendi): yığın için 32 word, yani 64 byte yer ayrılmıştır. Başlangıçta SP onluk 64'e, yani 40h'ye karşılık gelir. DS değeri yığına atılınca SP 2 azalarak 3Eh olur. Sıfır da atılınca 3Ch olur.

Hoca `d ss:3C` ile yığına baktı. Yığının dibinde little endian biçiminde işletim sistemine dönüş segment değeri, onun üzerinde 0 ofseti vardır. Bunlar işletim sistemine dönüş değerleridir.

### 10.2 Parametrelerin yüklenmesi ve CALL

Trace ile devam edildiğinde `MOV AX,[0000]` ile AX = 000D (13), `MOV DX,[0002]` ile DX = 000F (15) olur (ekrandan, 01:15:00). Sonra CALL satırına gelinir. Debug bu satırı `076F:0010 9A00007107 CALL 0771:0000` olarak gösterir. Belirli bir segmentin belirli bir ofsetindeki fonksiyonun çağrılması FAR çağrıdır; NEAR çağrı olsaydı yalnız IP'ye yüklenecek bir ofset görülecekti.

Hoca burada öğrencilere CALL çalıştığında hangi yazmaçların değişeceğini sordu ve cevabı verdi: CS ve IP. Trace sonrası CS, gidilecek kodun segment değeri olan 0771'e, IP de gidilecek ofset olan 0000'a güncellendi. Sıradaki komut `CMP AX,DX`'tir.

> **Ders sonrası not:** Hoca CALL sırasında yalnız CS ve IP'nin değiştiğini söyledi. Ekrandaki yazmaç dökümünde SP de 003C'den 0038'e değişmiştir (ekrandan, 01:15:00); CALL dönüş adresini yığına attığı için SP 4 azalır. Hoca hemen ardından SP'nin bu değişimini kendisi de gösterdi.

### 10.3 Yığına atılan dönüş adresi

SP 3Ch'den 38h'ye inmiştir; yığına iki değer daha atılmıştır: IP ve CS. `d ss:38` ile bakıldığında yukarıdan aşağı şu değerler görülür: ana yordamdaki dönüş ofseti, ana yordamın kod segmenti, işletim sistemine dönüş ofseti (0), işletim sistemine dönüş segmenti.

CALL çağrılmadan önce IP 0010'du, ama yığına dönüş ofseti olarak 0015 yazılmıştır. Hoca `u 076F:0015` ile bu adrese baktı: orada `MOV [0004],AX`, yani `MOV GCD, AX` satırı vardır. CALL komutu 5 byte uzunluğundadır (`9A 00 00 71 07`), bu yüzden dönüş adresi bir sonraki satırı gösterir (ara adım eklendi: 0010h + 5 = 0015h).

Hoca yığının bu anki halini ekranda şöyle çizdi (ekrandan, 01:20:00), yukarıdan aşağı:

```text
ANA IP        <- SP = 0038h
ANA CS
OS IP = 0
OS CS
```

### 10.4 Döngünün yürütülmesi

Trace ile devam edildiğinde: karşılaştırma yapıldı, değerler küçük-büyük sıradaydı ve yerleri değiştirildi (AX = 15, DX = 13). İkinci parametre sıfır değildi; BX'e kopyalandı, 16 bitlik bölme yapıldı, kalan DX'te kaldı, ilk parametre güncellendi ve başa dönüldü. Bu birkaç tur tekrarlandı ve sonunda AX = 1 elde edildi. Gönderilen 13 ve 15 aralarında asal olduğu için EBOB 1'dir.

Ara değerler (ara adım eklendi, python ile doğrulandı):

| Tur | AX (x) | DX (y) | Bölme | Yeni AX | Yeni DX |
|---|---|---|---|---|---|
| Başlangıç (XCHG sonrası) | 15 | 13 | 15 / 13 | 13 | 2 |
| 2 | 13 | 2 | 13 / 2 | 2 | 1 |
| 3 | 2 | 1 | 2 / 1 | 1 | 0 |
| Son | 1 | 0 | DX = 0, dön | | |

Ekranda son turların izi görülür: `MOV AX,BX`, `JMP 0005`, `CMP DX,+00`, `JZ 0014` ve `0771:0014 CB RETF` (ekrandan, 01:20:00). Debug `JE` komutunu `JZ` olarak gösterir.

### 10.5 RETF ve yığının durumu

Alt yordamda yığına hiçbir şey atılmadığı için RETF anında yığın yukarıda çizildiği gibidir. RETF yığının en üstündeki değeri, etiketine bakmadan, IP'ye yükler; bu değer yığından düşer. Sıradaki en üst değeri CS'ye yükler. Böylece `MOV GCD, AX` satırına dönülür. RETF sonrası `d ss:3C` ile bakıldığında iki değerin yığından çekildiği ve SP'nin 3Ch'yi gösterdiği görülür.

### 10.6 SP'nin altındaki çöp değerler

Hoca burada ilginç bir şey gösterdi. SP 3Ch'yi gösterdiği için SP'den yukarıdaki (yığının sonuna doğru olan) değerler anlamlıdır. Fakat `d ss:38` ile SP'nin altına bakılınca orada hâlâ bazı değerler görülür. Bunlar az önce yığına atılan değerler de olabilir, onlardan bağımsız da olabilir; her durumda çöp değerlerdir ve anlamlı değildir.

> **Hocanın vurgusu:** Yığında anlamlı olan, SP'nin gösterdiği noktadan yığının sonuna kadar olan değerlerdir. Buna özellikle dikkat edilmelidir.

### 10.7 Sonucun yazılması ve programın bitişi

Dönüşte sonuç AX'tedir; DX'teki değer de alt yordamda belirlenmiştir ama sonuç değildir. `MOV GCD, AX` çalıştırıldıktan sonra `d ds:0` ile veri kesimine bakılınca 13, 15 ve sonucu tutan word'de 1 görülür. Sonra ana programın RETF'i çalışır: yığında yalnız işletim sistemine dönüş değerleri vardır, bir adım daha yürütülünce farklı bir segmente, işletim sisteminin koduna geçilir ve SP 40h'ye ulaşır. Bu, yığının tamamen boşaldığı anlamına gelir.

## 11. Aynı Dosyada İki Prosedür: FAR PTR ve NEAR Çağrı

### 11.1 FAR alt yordam aynı dosyada

Başka bir yol, `GCD_PROC` fonksiyonunu ana yordamın dosyasına ikinci bir prosedür olarak yazmaktır. Bu da geçerli, fonksiyonel bir çalışmadır: aynı dosyada iki prosedür bulunur. Hoca alt yordamı ana dosyaya kopyaladı ve `EXTRN` satırını yorum yaptı. Bu durumda ana fonksiyon içinde çağrılan fonksiyonun FAR olduğunu belirten bir şey yoktur, ama fonksiyon FAR tipindedir. Derleme üç hata verdi; ilki prosedürün FAR tanımlı olup FAR olarak çağrılmamasıyla ilgiliydi. Çözüm `CALL FAR PTR GCD_PROC` yazmaktır (ekrandan, 01:25:00); hoca "yanlış hatırlamıyorsam" diyerek bunu yazdı ve derleme başarılı oldu.

İlk debug denemesinde CALL farklı bir fonksiyonu çağırıyordu; çünkü obje dosyası oluşturulmuş ama linklenmemişti, eski EXE çalışıyordu. Linkleme yapılınca CALL satırında bu kez aynı kod kesiminin farklı bir ofsetindeki fonksiyonun FAR tipinde çağrıldığı görüldü. Önceki durumda başka bir kod kesiminin sıfır ofseti çağrılıyordu.

> **Hocanın vurgusu:** Aynı dosyadaki FAR yordamı FAR olarak çağırmak için `FAR PTR` açıkça belirtilmelidir. Farklı dosyadayken `EXTRN ...:FAR` tanımı FAR çağrıyı garanti eder.

### 11.2 NEAR alt yordam aynı dosyada

Sonra fonksiyon NEAR tipinde tanımlandı ve çağrıda hiçbir şey belirtilmedi; bu durumda çağrı NEAR olarak algılanır. Dosya assembler'dan geçirilip linklendi ve debug ile CALL satırına gelindi. Aynı segmentte farklı bir ofsetteki fonksiyon çağrıldığı için CALL, NEAR çağrıya dönüşmüştü.

CALL yürütüldükten sonra `d ss:3A` ile yığına bakıldı. Farklı dosyada ya da FAR çağrıda yığında işletim sistemiyle ilgili iki, fonksiyonla ilgili iki değer olurdu. NEAR çağrıda ise işletim sistemine dönüş için iki değer (segment ve 0 ofseti), fonksiyondan dönüş için tek bir değer bulunur: 0013. Hoca önce bu değerin fonksiyonu gösterdiğini söyledi, sonra düzeltti: bu değer bir sonraki satırı gösterir. `u` ile kod kesiminin 13h ofsetine bakıldığında, AX'teki dönüş değerini `GCD` değişkenine yazan satır görüldü. Alt yordam yığına hiçbir şey atmadığı için RET anında yığının tepesinde yine 0013 olur ve oraya dönülür.

Bu deneyden sonra fonksiyon ana dosyadan kaldırıldı ve `EXTRN ... :FAR` hali geri getirildi.

## 12. Özyinelemeli GCD_PROC

### 12.1 Tanımın hatırlanması

Şimdi aynı işlem özyinelemeli (recursive) yapılır: ana yordam EBOB'u hesaplayan alt yordamı çağırır, alt yordam ise hesabı kendini çağırarak yapar. Fonksiyon ana yordama kullandırılacağı için yine PUBLIC olmalıdır; veri kesimi kullanmadığı için yalnız kendi kod kesimi vardır. MAP dosyasında oluşan EXE'nin iki kod kesimi, bir veri kesimi ve bir yığın kesimi olduğu da görülmüştü.

Hoca tanımı ekranda yazdı (ekrandan, 01:35:00):

$$\gcd(x,0)=x$$
$$AX=\gcd(x,y)=\gcd(y,\ x \bmod y)$$

Ekrandaki oklar x'in AX'e, y'nin DX'e karşılık geldiğini, yeni çağrıda eski y'nin birinci parametreye (AX), $x \bmod y$'nin ikinci parametreye (DX) geçtiğini gösterir. Bir sonlanma koşulu, bir de özyinelemeli kısım vardır. Sonlanma koşulu sağlandığında AX'te zaten x vardır; AX ile dönmek yeterlidir.

### 12.2 Kod

Özyinelemeli gövde şöyledir (ekrandan, 01:30:00):

```text
;GCD_PROC input AX, DX
;GCD_PROC output AX
GCD_PROC PROC FAR

        CMP AX, DX
        JAE DEVAM
        XCHG AX,DX

DEVAM:  CMP DX, 0
        JA RECUR
        JMP EXIT
RECUR:  MOV BX, DX
        XOR DX, DX
        DIV BX
        MOV AX, BX
        CALL GCD_PROC
EXIT:   RETF
GCD_PROC ENDP

CDESG   ENDS
        END
```

Alt yordama girilince önce, girdiler AX ve DX olduğu için, küçük olan DX'te kalacak şekilde gerekirse değiştirme yapılır. Sonra küçük olanın sıfır olup olmadığı kontrol edilir. Hoca bu sıralamanın nedenini de açıkladı: küçük sayının sıfır olması sonlanma koşuludur. "Küçük sayının büyük sayıya bölümünden kalan küçük sayının kendisidir" diye ilerlemek yerine doğrudan değiştirme yapmak daha anlaşılırdır; geçen hafta bu yönde bir öneri gelmişti.

Sonlanma koşulu DX'in sıfır olmasıdır. DX sıfırsa `JA RECUR` sağlanmaz, alttaki satıra geçilir ve `JMP EXIT` ile RETF'e gidilir. AX'te x, DX'te y ile dönülür; çağıran taraf AX'teki dönüş değerini alıp ilgili yere yazar.

DX sıfır değilse özyinelemeli kısım çalışır. DX geçici olarak BX'e alınır ve bölme yapılır. Bir adım sonra x'in yerinde bir önceki y, y'nin yerinde ise bir önceki x'in y'ye bölümünden kalan olmalıdır. 16 bitlik bölmede kalan zaten DX'tedir; böylece y parametresinin yerine kalan konmuş olur. Bir önceki y BX'e kopyalanmıştı; o da AX'e atanır. Bu adımlarla özyineleme bir adım yürütülmüş olur ve aynı fonksiyon yeni parametrelerle yeniden çağrılır. Döngüsel halde fonksiyonu çağırmak yerine döngünün başına dönülüyordu; burada fonksiyon kendini çağırır.

## 13. Debug ile Özyinelemeli Çağrılarda Yığın

### 13.1 Derleme, LST ve MAP

Ana dosya LST dosyasıyla, `gcdalt.asm` de LST dosyasıyla derlendi ve ikisi bir MAP dosyası üretecek şekilde birlikte linklendi. Ana yordamın LST'si, değişiklik yapılmadığı için önceki EXTRN durumuyla aynıdır. Alt yordamın LST'sinde ise farklı olarak göreli bir fonksiyon çağırma satırı vardır; döngüsel sürümde böyle bir çağrı yoktu. MAP dosyası beklendiği gibi iki kod kesimi, bir yığın ve bir veri kesimi gösterir.

### 13.2 Başlangıç ve eski EXE sorunu

Debug başladığında yine işletim sistemine dönüş segmenti ve 0 ofseti yığına atıldı; `d ss:3C` ile iki değer görüldü. Sonraki iki adımda veri kesimi DS'ye yüklendi.

> **Hocanın vurgusu:** Bu iki satır (`MOV AX, DATASG`, `MOV DS, AX`) yürütülmezse `MOV AX,[0000]` veri kesimimizin 0 ofsetini göstermez. O anda DS'de işletim sisteminin dönüş segment değeri vardır ve başka bir bölgenin ofsetlerine erişilmiş olur. Çok dikkat edilmesi gereken bir noktadır.

AX'e 13, DX'e 15 alındıktan sonra CALL satırının NEAR olarak göründüğü fark edildi (`CALL 0017`, makine kodu `E80400`, ekrandan, 01:40:00). Bir öğrenci yalnız bir dosyanın derlendiğini hatırlattı. Dosyalar yeniden derlenip linklenince ve DOSBox kapatılıp açılınca sorun çözüldü. Hocaya göre önceden derlenmiş bir dosya kalmıştı; ekrandaki NEAR çağrı büyük olasılıkla NEAR denemesinden kalan EXE'ye aitti.

### 13.3 Çağrı çağrı yığın

Ana yordam, nerede olduğunu obje dosyası oluşurken bilmediği ama FAR olduğunu bildiği `GCD_PROC`'u FAR olarak çağırır. İki obje dosyası linklendiği için sistem artık fonksiyonun hangi segmentin hangi ofsetinde olduğunu bilir.

**Birinci çağrı (ana yordamdan):** Karşılaştırma yapılır ve yerler değişir; AX = 15, DX = 13 olur. İkinci parametre sıfır değildir. DX BX'e alınır, DX sıfırlanır ve AX, BX'e bölünür. Mantıksal karşılığı x / y'dir: bölüm AX'te, kalan DX'te kalır. Sonra eski y AX'e atanır. Özyinelemeli CALL satırına gelindiğinde AX = 13, DX = 2'dir. Bu anda `d ss:38` ile yığının tepesinde ana yordama dönüş adresi görülür; `u 076F:0015` bu adresin ana yordamdaki `MOV GCD, AX` satırı olduğunu gösterir.

**İkinci çağrı:** Trace sonrası SP 34h olur; yığına iki değer daha atılmıştır. Hoca burada öğrencilere en üstteki iki değerin nereye dönüşü gösterdiğini sordu (sorunun ayrıntısı Örnek Sorular'da). `d ss:34` ile yukarıdan aşağı şunlar görülür (ekrandan, 01:45:00): `1A 00 71 07 15 00 6F 07 00 00 5A 07`. Yani en üstte 0771:001A, altında 076F:0015 (ana yordama dönüş), en altta 075A:0000 (işletim sistemine dönüş) vardır. `u 0771:001A` bu adresin alt yordamdaki RETF satırı olduğunu gösterir. CALL satırı 0771:0015'tedir ve 5 byte uzunluğundadır; dönüş bir sonraki satır olan `EXIT: RETF`'e yapılır.

> **Hocanın vurgusu:** İç içe kaç fonksiyon çağrılmışsa, alt yordamlardaki bütün dönüşler alt yordamın RETF satırına olur. Yalnız ilk çağrılan alt yordamdan dönüş ana yordamdaki `MOV GCD, AX` satırına yapılır.

Bu çağrıda AX = 13, DX = 2 ile aynı fonksiyon yeniden çalışır: birinci sayı büyüktür, ikinci sayı sıfır değildir, bölme yapılır, parametreler yer değiştirir ve yine CALL satırına gelinir.

**Üçüncü çağrı:** Fonksiyon bu kez 2 ve 1 değerleriyle çağrılır. `d ss:30` ile bakıldığında yığının iyice dolduğu görülür: işletim sistemine dönüş, ana yordama dönüş, birinci özyinelemeli adımın RETF'ine dönüş ve ikinci özyinelemeli adımın RETF'ine dönüş. Bölme yapılır, x ve y yer değiştirir.

**Dördüncü çağrı:** AX = 1, DX = 0 ile çağrılır; SP 2Ch'ye düşer. En üstteki değerler yine bir üst seviyedeki fonksiyonun RETF'ine dönüşü gösterir. AX ile DX karşılaştırılır; AX büyüktür, DX sıfırdır. Bu kez RETF satırına gidilir ve ilk dönüş gerçekleşir.

Çağrılara göre SP (ara adım eklendi, python ile doğrulandı):

| Çağrı | Giriş AX, DX (XCHG sonrası) | Çağrı sonrası SP |
|---|---|---|
| Ana yordamdan | 15, 13 | 0038h |
| Özyineleme 1 | 13, 2 | 0034h |
| Özyineleme 2 | 2, 1 | 0030h |
| Özyineleme 3 | 1, 0 | 002Ch |

### 13.4 Dönüşler

Yığının en dolu anı 2Ch ofsetinden yığının sonuna kadar olan değerlerdir. Hoca, fonksiyonun 13 ve 15 için kendini kaç kez çağıracağı hesaplanabilirse yığının ne kadar dolacağının da mantıksal olarak hesaplanabileceğini söyledi.

En içteki çağrının RETF'i çalışınca AX = 1 ile bir üst seviyedeki çağrının RETF satırına dönülür. O RETF de AX = 1 ile bir üst seviyeye döner; üçüncü seviyeden de dönülür. Dördüncü dönüşte ana yordama varılır. `d ss:3C` ile bakıldığında yığında yalnız işletim sistemine dönüş değerleri kalmıştır. Dört dönüşün üçü alt yordamın RETF satırına, sonuncusu ana yordamdaki `MOV GCD, AX` satırınadır (ekrandan, 01:50:00: `IP=001A RETF` adımlarından sonra `CS=076F IP=0015 MOV [0004],AX` ve `SP=003C`).

### 13.5 Özyinelemenin yığın açısından dersleri

> **Hocanın vurgusu:** Özyinelemeli fonksiyonlarda iç içe ne kadar çağrı olacağı kabaca öngörülmeli ve yığın bu mertebede geniş tanımlanmalıdır. İkinci olarak fonksiyon çağırmanın mantığı ve pratiği kavranarak yığın derinliğinin nereye vardığı anlaşılmalıdır. Üçüncü olarak, ileride görülecek yığından parametre aktarımında yığında yalnız dönüş adresleri değil parametreler de olacaktır; aktarılan parametreyi alıp kullanabilmek için yığının nasıl düzenlendiği dikkatle kavranmalıdır.

## 14. Dersin Özeti ve Sonraki Konular

Hoca derste yapılanları şöyle topladı:

- Bir ana yordam ve bir alt fonksiyon aynı dosyada kullanılabilir. Ana yordam EXE programında olduğu için mutlaka FAR olmalıdır; alt yordamlar NEAR ya da FAR tanımlanabilir.
- Aynı dosyadaki alt yordam FAR tanımlıysa ana yordamda `CALL FAR PTR` kullanılmalıdır. NEAR tanımlıysa `CALL GCD_PROC` ile doğrudan çağrılabilir.
- İki farklı dosya için iki obje dosyası oluşturulmalıdır. Ana yordamın obje dosyası oluşturulurken dışarıdan çağrılacak fonksiyon EXTRN olarak ve tipiyle tanımlanmalıdır; bu durumda çağrı FAR çağrıya dönüştürülür.
- EXTRN yapılmazsa, ana yordamda `GCD_PROC`'a ilişkin bir tanım olmadığı için assembly aşamasında hata alınır.
- EXTRN yapılsa bile alt yordamın obje dosyası oluşturulmazsa linkleme aşamasında hata alınır.
- Obje dosyası oluşturulsa bile PUBLIC tanımı yapılmazsa EXTRN tanımı karşılık bulamaz ve yine linkleme aşamasında hata alınır.
- Bu hatalar geçildikten sonra alt yordam FAR tipinde önce döngüsel, sonra özyinelemeli olarak tanımlandı. NEAR, FAR döngüsel ve FAR özyinelemeli fonksiyonlar için yığındaki veriler incelendi ve yorumlandı.

Böylece başka bir dosyadan fonksiyon çağırma ve fonksiyon geliştirme tamamlanmış, yazmaç üzerinden parametre aktarımı işlenmiş oldu. Sonraki derslerde aynı işlemler makrolar için yapılacak, ardından yığın üzerinden ve kesim üzerinden parametre aktarımı incelenecek. Ayrıca EXE yerine COM tipi programlarda ana ve alt yordamların birlikte nasıl kullanılacağına da değinilecek.

## 15. Soru-Cevap: Tail Call Optimization

**Soru:** Programlarda "tail call optimization" diye bir mantık var. Burada özyinelemeli çağrıyı fonksiyonun sonunda, RET'ten hemen önce yapıyoruz ve her çağrı yığına bir değer daha atıyor. Tail call optimization'da çağrı dönüşten hemen önceyse yığına bir şey atılmıyor; en içteki çağrı dönünce en dıştaki de dönmüş oluyor. Bunun için hazır bir mekanizma var mı, yoksa kendimiz mi kurgulamalıyız?

**Cevap:** Bu durum günümüzün güncel derleyicilerinde varsa güncel mikroişlemcilerin assembly dilinde de destekleniyor olmalıdır. Ancak incelenen yapı 8086 olduğu için burada yoktur. Daha güncel assembly dillerinde olabilir; bakmak gerekir, hoca bunu doğrudan bilmediğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Tail call optimization büyük olasılıkla donanımın değil derleyicinin yaptığı bir dönüşümdür. Fonksiyonun son işi bir çağrıysa derleyici `CALL ... / RET` çifti yerine doğrudan `JMP` üretir; böylece yığına yeni bir dönüş adresi eklenmez. Derste yazılan `GCD_PROC`'ta `CALL GCD_PROC` satırının yerine `JMP DEVAM` yazmak, kodu derste gösterilen döngüsel sürüme dönüştürmekle aynı anlama gelir.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:14:20): Debug'da `076F:0010 9A00007107 CALL 0771:0000` satırı çalıştırıldığında hangi yazmaçlarda değişiklik olur?

> **Çözüm:** Hocanın cevabı CS ve IP'dir: CS gidilecek kodun segmenti olan 0771'e, IP gidilecek ofset olan 0000'a güncellenir. Ayrıca FAR CALL yığına dönüş CS'sini ve IP'sini attığı için SP 4 azalır (003Ch → 0038h, ekrandan, 01:15:00). Genel amaçlı yazmaçlar (AX = 000D, DX = 000F) değişmez; bu yüzden parametre olarak kullanılabilirler.

**Soru 2** (derste sözlü, 01:06:26): Ana ve alt yordam içeren iki dosyalı EXE programın MAP dosyasında iki kod, bir veri, bir yığın kesimi görüldü. EXE2BIN ile oluşturulan bir COM programın MAP dosyasında kaç kesim beklenir?

> **Çözüm:** Tek kesim. COM programında tek kesim vardır ve bu kesim hem kod, hem yığın, hem veri kesimi olarak kullanılır. Tek prosedürlü bir EXE programda ise üç kesim (yığın, veri, kod) görülür.

**Soru 3** (derste sözlü, 01:00:52): `GCD_reg.obj` ile `GCD_alt.obj` ters sırayla, önce alt yordam verilerek linklenirse sorun olur mu?

> **Çözüm:** Olmaz; derste ters sırayla linklendi ve EXE hatasız oluştu. Sıra önemli değildir. Gerekli olan, bir dosyada etiketin `PUBLIC`, diğerinde `EXTRN` olarak tanımlanmasıdır.

**Soru 4** (derste sözlü, 01:44:18): Özyinelemeli `GCD_PROC` ikinci kez (alt yordamın içinden) çağrıldıktan sonra SP = 0034h olmuştur. Yığının en üstündeki iki değer hangi satıra dönüşü gösterir? Seçenekler: ana yordamdaki `MOV GCD, AX` satırı, alt yordamın başı, alt yordamdaki `RETF` satırı.

> **Çözüm:** Alt yordamdaki `RETF` satırı. Yığın dökümü `1A 00 71 07 15 00 6F 07 00 00 5A 07` biçimindedir (ekrandan, 01:45:00). En üstteki 0771:001A, alt yordamda CALL'dan sonraki satır olan `EXIT: RETF`'tir. Altındaki 076F:0015 ana yordamdaki `MOV GCD, AX` satırına, en alttaki 075A:0000 işletim sistemine dönüştür.

**Soru 5** (derste sözlü, 01:48:25): Özyinelemeli `GCD_PROC`, AX = 13 ve DX = 15 ile çağrıldığında kendini kaç kez çağırır ve yığın en çok ne kadar dolar? (Altyazıda sayılar "13'e 5" diye geçiyor; derste kullanılan değerler 13 ve 15'tir.)

> **Çözüm:** Çağrılar (15, 13) → (13, 2) → (2, 1) → (1, 0) şeklindedir. Ana yordamdan 1 çağrı, fonksiyonun kendini çağırması 3 kezdir; toplam 4 FAR çağrı yapılır. Her FAR çağrı yığına 4 byte (CS ve IP) ekler. SP 003Ch'den 4 × 4 = 16 byte inerek en derinde 002Ch olur; derste de 2Ch görüldü. İşletim sistemine dönüş değerleriyle birlikte yığında 10 word dolu olur (ara adım eklendi).

**Soru 6** (derste gösterildi, 01:26:04): `GCD_PROC` ana yordamla aynı dosyada NEAR olarak tanımlanıp `CALL GCD_PROC` ile çağrılırsa yığına ne atılır, RET nereye döner?

> **Çözüm:** NEAR CALL yalnız dönüş ofsetini atar. Yığında işletim sistemine dönüş için iki değer (segment ve 0) ile fonksiyon dönüşü için tek değer, 0013h, bulunur (SP = 003Ah). 0013h, `MOV GCD, AX` satırının ofsetidir; RET yığının tepesindeki bu değeri IP'ye yükler ve oraya döner (ara adım eklendi: 3 byte'lık NEAR CALL 0010h'ta olduğu için 0010h + 3 = 0013h).

## Dersin Toparlaması

Bu derste prosedür ile makronun farkı (tek kopya ve akışın gidip gelmesi ile her çağrıda kodun kopyalanması), PROC/ENDP ve MACRO/LOCAL/ENDM şablonları ve NEAR/FAR çağrılarda yığının nasıl kullanıldığı işlendi. Ardından önceki haftanın EBOB programı ana yordam ve alt yordam olarak iki dosyaya bölündü. EXTRN ve PUBLIC eksik olduğunda hatanın hangi aşamada (assembler ya da linker) çıktığı tek tek gösterildi. LST ve MAP dosyaları, aynı dosyada FAR PTR ile ve NEAR olarak çağırma, döngüsel ve özyinelemeli sürümlerde yığının adım adım değişimi DEBUG ile izlendi. Dersin ana fikri şudur: RET ve RETF yığında etiket aramaz, yalnız tepedeki değerleri alır. Bu yüzden yığın düzeni, özyinelemede yığın derinliği ve SP'nin altındaki değerlerin çöp olduğu iyi bilinmelidir.

Sonraki derslerde aynı yapı makrolar için kurulacak, ardından yığın üzerinden (BP ile) ve kesim üzerinden parametre aktarımı ile COM programlarında ana ve alt yordam kullanımı ele alınacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
