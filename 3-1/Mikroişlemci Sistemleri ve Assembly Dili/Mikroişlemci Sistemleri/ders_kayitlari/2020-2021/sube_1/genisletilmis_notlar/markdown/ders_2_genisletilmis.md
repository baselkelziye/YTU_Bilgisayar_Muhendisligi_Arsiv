# Ders 2 Genişletilmiş Notu: 8086 Temel Kavramları, Yazmaçlar, Bayraklar ve Adresleme Modları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Hafıza Erişim Modları: Real, Protected ve Virtual
- 2. Prefetch Queue ve Pipeline
- 3. Offset Memory Model ve Fiziki Adres
- 4. Time Multiplexing (Zaman Çoğullama)
- 5. Coprocessor (Yardımcı İşlemci)
- 6. Cache (Önbellek)
- 7. 8086 İç Yapısı ve Yazmaçlar
- 8. Bayrak Yazmacı
- 9. Real Mod ve Protected Mod Hafıza Adresleme
- 10. Komut Yapısı ve Operand Sayısı
- 11. Veri Adresleme Modları
- 12. Program Hafızası ve Yığın Adresleme
- 13. 8086 Uç Tanımlarına Giriş
- Örnek Sorular
- Dersin Toparlaması

## 1. Hafıza Erişim Modları: Real, Protected ve Virtual

Bu ders, bir önceki derste başlanan "Genel Tanımlar ve Karşılaştırma" slaytından devam etti. Slaytta iki sütun hâlinde şu kavramlar vardı: real mode, protected mode, virtual mode, prefetch queue, pipeline; offset memory model, time multiplexing, coprocessor, cache (ekrandan, 00:15:00).

İlk üç kavram (real, protected, virtual mod) mikroişlemcinin hafızaya nasıl eriştiğiyle ilgilidir. **Real mod** 8086'nın erişim biçimidir ve hoca slayta "Real mode → 1 MB" diye not düştü. Bu modda herhangi bir program 1 MB'lık hafızanın tamamına erişebilir. Bunun bir sonucu da vardır: herhangi bir yazılım, örneğin işletim sisteminin dosyalarına dokunabilir ve onlara zarar verebilir.

**Protected modda** ise her program parçası için çalışacağı adres aralığı ve bu aralıktaki izinler tanımlanır. Program yalnız kendisi için ayrılmış alanı görebilir; hafıza programa sanal olarak sunulmuş olur. Hoca bu modların ayrıntısına ilerleyen slaytlarda döneceğini söyledi (bkz. Bölüm 9).

## 2. Prefetch Queue ve Pipeline

**Prefetch queue**, 8086 iç yapısında gördüğümüz komut kuyruğudur. Hoca slayta "Komut kuyruğu" diye yazdı. İç yapı şemasında bu kuyruk 6 gözlü "Instruction Queue" olarak görünür (ekrandan, 00:35:00).

**Pipeline** önemli bir kavramdır: birim zamanda mikroişlemcide yürütülen komut sayısını artıran bir optimizasyon yöntemidir. Hoca bunu şöyle anlattı. Bir komutun yürütülmesi beş adımdan oluşur:

- Komutun hafızadan çekilmesi (Instruction Fetch, IF)
- Komutun çözülmesi (Instruction Decode, ID)
- Operandların hafızadan çekilmesi (Operand Fetch, OF)
- Komutun yürütülmesi (Execute, EX)
- Gerekiyorsa sonucun hafızaya geri yazılması (Write Back, WB)

Bu beş adımı yapan mantığın tek bir fonksiyonel blok olduğunu düşünelim. O zaman her seferinde işlemciye tek bir komut girer ve tek bir komut çıkar: birim zamanda bir komut.

Şimdi bu beş adımı beş ayrı fonksiyonel blok hâline getirelim. Hoca tahtaya IF, ID, OF, EX, WB etiketli beş kutuyu merdiven biçiminde çizdi (ekrandan, 00:15:00). Bu durumda şöyle bir imkân doğar: daha önce çekilmiş, çözülmüş, operandları alınmış ve yürütülmüş birinci komutun yalnız geri yazma işi kalmıştır ve bu iş WB bloğunda yapılır. Aynı anda EX bloğu ikinci bir komutu yürütür, OF bloğu üçüncü bir komutun operandlarını çeker, ID bloğu dördüncü komutu çözer, IF bloğu beşinci komutu hafızadan alır. Böylece beş blokta beş farklı komutun birer parçası aynı anda yürütülür. Bu duruma pipeline denir.

8086'da pipeline yoktur; sonraki mikroişlemcilerde ortaya çıkar. Ama temel mantığı budur: birim zamanda yürütülen komut sayısı artar.

## 3. Offset Memory Model ve Fiziki Adres

### 3.1 Neden gerekli?

8086'da 20 adres ucu ve 16 veri ucu vardır, yazmaçlar ise 16 bittir. 20 bitlik bir adres değerini tek bir yazmaçla oluşturmak mümkün değildir. Bu yüzden fiziki adres (PA, physical address) bir işlem bloğuyla üretilir. Hoca formülü slayta yazdı (ekrandan, 00:20:00):

$$PA = \text{segment} \times 10H + \text{ofset}$$

Segment tipindeki bir yazmaç alınır, onaltılık 10 (10H) ile çarpılır ve buna bir ofset yazmacının değeri eklenir.

**Soru:** Bir sayıyı onaltılık 10 ile, yani 10H ile çarpmak ne demektir? **Cevap:** 16 ile çarpmak demektir; başka bir açıdan da 4 bit sola kaydırmak, yani sağına dört tane 0 biti koymak demektir. Segment yazmacı zaten 16 bit olduğundan bu çarpımla değer 20 bite çıkar. Ofset ise bu 20 bitlik taban değerinin üzerinde 16 bitlik bir aralıkta hareket etmeyi sağlar.

### 3.2 Kaç segment tanımlanabilir?

**Soru:** 1 MB'lık alan içinde birbiriyle örtüşmeyen kaç segment tanımlanabilir? **Cevap:** Bir segment $2^{16} = 64\text{K}$ bayttır; $1\text{M} / 64\text{K} = 16$ olduğundan birbirinden bağımsız, örtüşmeyen 16 segment tanımlanabilir. 16 bitlik ofset de bu 64 KB'lık segment içinde gezinmeyi sağlar.

Hoca burada önceki dersten bir bağlantı kurdu: yazmaç genişliğinden daha fazla adres ucunun olduğu durumların zorluğu tam olarak budur. 8086'da 20 bitlik adresi üretmek için ayrı bir adres üretme bloğu gerekir; bu yüzden 8086'da offset memory model kullanılır.

### 3.3 Segmentlere göre ofset yazmaçları

Hoca assembly dersinden hatırlanması gereken eşleşmeleri öğrencilere sorarak çıkardı ve slayta yazdı (ekrandan, 00:30:00):

```text
Veri:  DS x 10H + (SI, DI, BX)
Kod:   CS x 10H + IP
Yığın: SS x 10H + (SP, BP)
```

- **Kod:** Kod için ayrılan segmenti CS (code segment) belirler; ofset yazmacı IP'dir (instruction pointer). CS'ye değer yazılabilir ama IP'ye doğrudan değer yazılamaz. IP yürütülen komutlara göre belirlenir: ardışık komutlarda her komutun boyu kadar artar, near jump'ta verilen miktar kadar değişir, far jump'ta da verilen değere göre değişir.
- **Yığın:** Segment SS (stack segment), ofset SP ya da BP'dir. Bir öğrenci SI dedi; hoca SI olmadığını, doğru cevabın SP ve BP olduğunu söyledi. SP otomatik belirlenir: yığına değer atınca, yığından değer çekince, CALL ve RET sırasında yığına otomatik değerler yazıldığı için değişir.
- **BP'nin görevi:** **Soru:** BP'yi ne için kullanıyorduk? **Cevap:** Yığın üzerinden parametre aktarırken SP'yi bozmamak için alt programa girer girmez SP değeri BP'ye kopyalanır ve bir referans oluşturulur. Yığına gönderilen parametrelere bu referansa göre erişilir. Hoca bu cevabı veren öğrencilerin cevabını doğru kabul etti.
- **Veri:** Segment DS (data segment), ofset yazmaçları SI, DI ve BX'tir. Bir öğrenci AX'i önerince hoca şunu hatırlattı: veri erişiminde köşeli parantez içinde AX, CX ya da DX kullanılırsa assembler hata verir.

## 4. Time Multiplexing (Zaman Çoğullama)

8086'nın 20 adres ucu, 16 veri ucu, yaklaşık 4 besleme ucu ve 10'dan fazla kontrol ucu vardır. Toplam en az 50 fonksiyonel uç gerekir. Oysa 8086 çipinin fiziksel olarak 40 bacağı vardır. Bu yüzden bazı fiziksel uçlar farklı zamanlarda farklı görevleri yürütür. Buna **time multiplexing** (zaman çoğullama) denir.

Hoca bunu bir örnek komutla anlattı ve slayta `MOV AX, [100H]` yazdı (ekrandan, 00:30:00).

**Soru:** Bu komutta varsayılan segment hangisidir? **Cevap:** Veri erişimi olduğu için DS'dir. DS 10H ile çarpılır, ofset olan 100H eklenir.

İşlemci bu fiziki adresi önce hafızaya çıkarmalı, sonra gelen veriyi almalıdır. İkisi de aynı fiziksel uçlarda olur. Komutun yürütülmesi dört zaman diliminde gerçekleşir: T1 anında ortak uçlardan adres çıkar, T2 anında aynı uçlar veriyle ilgili işlev görür. Ortak uçlarda o an adres mi veri mi olduğu **ALE** (Address Latch Enable) isimli bir uçla bildirilir; ayrıntısı uç tanımlarında görülecektir.

### 4.1 Frekans çoğullama ile karşılaştırma

Hoca çoğullamanın (multiplexing) başka bir biçimini de sordu: Aynı anda birçok kişi aynı GSM hattı üzerinden ya da Wi-Fi'de 2.4 GHz bandı civarında haberleşebiliyor; bu nasıl bir çoğullamadır? Bir öğrencinin cevabı doğru değildi. Hocanın açıklaması: burada **frekans çoğullaması** vardır. Herkes tam 2.4 GHz'de değil, 2.4 GHz civarındaki farklı alt bantlarda haberleşir; herkesin verisi karşı tarafa farklı bir frekansla gider. 8086'daki ise zaman çoğullamasıdır: farklı zamanlarda aynı fiziksel uçlardan farklı işlevler çıkar.

## 5. Coprocessor (Yardımcı İşlemci)

Uzun süre mikroişlemcilerin içinde dahili bir matematik işlemci yoktu. Matematik işlemci ikinci bir yardımcı işlemci olarak sağlanıyordu; örneğin 8086'nın yardımcı matematik işlemcisi 8087'dir. Bir ana ve bir yardımcı işlemcinin birlikte çalıştığı durum coprocessor kullanımına karşılık gelir.

8086 özelinde, yardımcı işlemcilerle çalışmaya yalnız **maksimum modda** izin vardır. Hoca dersin başında da söylediği gibi derste 8086'nın **minimum modda** kullanılacağını hatırlattı. Minimum mod, herhangi bir yardımcı işlemcinin olmadığı duruma karşılık gelir.

> **Ders sonrası not:** Hoca dahili matematik işlemcinin "8486'ya kadar" olmadığını söyledi ve bunu yanlış hatırlıyor olabileceğini ekledi. İşlemcinin doğru adı 80486'dır; kayan nokta birimi büyük olasılıkla 80486 (DX sürümü) ile işlemcinin içine alınmıştır.

## 6. Cache (Önbellek)

Cache, Türkçesiyle önbellek, hafıza hiyerarşisinde yazmaçlarla RAM arasında yer alan bir hafıza bloğudur. RAM'e göre oldukça hızlı, yazmaçlara göre çok yavaştır. Kapasitesi yazmaçlardan büyük, RAM'den küçüktür. Bir öğrenci sorusu üzerine hoca kapasite mertebesini de verdi: genelde kilobayt mertebesindedir; L2, L3 seviyelerinde megabaytlara ulaşmış olabilir, ama RAM'e oranla çok küçüktür.

Cache olmasaydı mikroişlemci her veriye erişmek için RAM'e gitmek zorunda kalırdı; RAM'e erişim, üretim teknolojisi nedeniyle uzun sürer. Cache ile işleyiş şöyledir: işlemci önce cache'e bakar. Aranan veri cache'te yoksa RAM'e gider; aranan veriyi ve çevresindeki bir bloğu alıp cache'e kopyalar. Bundan sonraki erişimler büyük olasılıkla cache'ten karşılanır.

Cache'in fayda sağlamasının iki nedeni vardır:

- **Spatial locality (uzamsal yerellik):** Bir veriye erişildiyse sonraki adımlarda onun komşusu olan verilere erişilmesi olasıdır. Örneğin bir `for` döngüsünde dizinin elemanlarına sırayla erişilir. Veri cache'e blok olarak alındığı için sonraki iterasyonlarda aranan veri cache'te bulunur.
- **Temporal locality (zamansal yerellik):** Erişilen bir veriye kısa süre sonra yeniden erişilmesi olasıdır. Örneğin 1'den $n$'e kadar sayıların toplamı alınırken sonuç sürekli bir `sum` değişkeninde biriktirilir; bu değişkene defalarca erişilir.

Aranan veri cache'te bulunursa erişim çok hızlanır. Eskiden cache işlemcinin dışında da olabiliyordu; günümüzde işlemcinin içinde entegre gelir ve L1, L2, L3 gibi seviyeleri vardır.

## 7. 8086 İç Yapısı ve Yazmaçlar

### 7.1 İç yapı

Hoca 8086'nın iç yapı şemasını gösterdi (ekrandan, 00:35:00). Şemada üstte BIU bölümü vardır: CS, DS, SS, ES, IP yazmaçları, iç iletişim yazmaçları, 20 bitlik adres yolunu üreten toplayıcı (SUMMATION), veri yolu, yol denetimi (Bus Control) ve 6 gözlü komut kuyruğu. Altta EU bölümü vardır: AL/AH, BL/BH, CL/CH, DL/DH, SP, BP, DI, SI yazmaçları, geçici yazmaçlar, ALU, bayraklar ve EU kontrol birimi. Hocanın özetiyle işlemcinin içinde yazmaçlar, aritmetik-lojik birim, kontrolcüler ve bunları birbirine bağlayan yollar vardır. Kontrol biriminin komutları nasıl işlediği bilgisayar donanımı dersinin konusudur; hoca bunu slaytların sonuna eklediğini söyledi.

### 7.2 Genel amaçlı yazmaçlar

Yazmaç listesi slaytta şöyleydi: AX (AL, AH), BX (BL, BH), CX (CL, CH), DX (DL, DH), SP, BP, SI, DI, SS, CS, DS, IP, ES (ekrandan, 00:40:00).

AX, BX, CX, DX ve bunlarla birlikte SI, DI genel amaçlı yazmaçlardır: programda çok düşünmeden veri ve sonuç saklamak için kullanılabilirler. Ama bazı komutlarda gizli operand olarak kullanıldıkları için o komutların değerlerini bozmamaya dikkat etmek gerekir.

- **AX (akümülatör):** Akümülatöre özel komutlar vardır ve akümülatör üzerinden çalışan komutlar diğerlerine göre biraz daha hızlıdır. Bu yüzden bir işlem akümülatörle yapılabiliyorsa onu kullanmak kodu hızlandırır. 16 bitlik AX'in düşük 8 bitine AL, yüksek 8 bitine AH adıyla ayrı ayrı erişilir.
- **BX (base register):** Dolaylı adreslemede kullanılır; erişilecek hafıza gözü BX'e görece, onu taban alarak tanımlanır. Düşük ve yüksek baytları BL ve BH'dir.
- **CX (count):** Genel amaçlı olmakla birlikte esas olarak döngülerde kullanılır. LOOP komutu her döngüde CX'i 1 azaltır, CX 0 olunca döngüyü kırar. Birden fazla öteleme yapılacaksa öteleme sayısı CL'ye yazılır. En geniş yazmaç 16 bit olduğundan bir yazmaç en fazla 16 kez anlamlı biçimde ötelenebilir; bu yüzden CL yeterlidir.
- **DX (data register):** DL ve DH ile 8 bitlik parçalarına erişilir. Çarpma ve bölmede AX ile birlikte gizli operand olarak kullanılır: komutta yazılmadıkları hâlde sonuç AX ve DX'te üretilir. Slaytta DX için "çarpma ve bölme komutlarında bölünen sayıyı oluşturmak için kullanılır" ve "giriş çıkış işlemlerinde port numarasını saklar" yazıyordu (ekrandan, 00:45:00).

### 7.3 Yığın, indeks ve segment yazmaçları

**SP ve BP**, yığın erişiminde ofset yazmacı olarak işlev görür. Yığın, stack (yığıt) mantığıyla çalışan bir hafıza bölgesidir. EXE ve COM tipi programlarda bir yığın bölgesi tanımlanır; bu bölge veri aktarımı ve alt programdan dönüş adreslerinin tutulması için kullanılır. Alt programa girer girmez SP'nin BP'ye kopyalanması, alt program içinde yığına yeni değerler atılıp çekilse ve SP değişse bile parametrelerin yerinin kaybolmamasını sağlar. SP, SS ile birlikte kullanılır ve word tipinde veriyle çalıştığı için her seferinde 2 artar ya da 2 azalır.

**SI ve DI** (source index, destination index), C'deki bir döngünün iterasyon değişkeni gibi kullanılabilir. Asıl özel kullanımları katar (string) işlemleridir. Katar işlemi bir hafıza bloğunu başka bir bloğa kopyalamak, bir bloğu bir değerle doldurmak ya da iki bloğu karşılaştırmak gibi işlemlerdir. İki blok arasında işlem yapılırken biri kaynak, diğeri hedeftir: SI kopyalanacak verinin başlangıcını, DI verinin taşınacağı yeni yerin başlangıcını gösterir. SI, DS ile; DI ise ES ile kullanılır.

**Segment yazmaçları** SS, CS ve DS'dir; bunlar hafıza bölgelerini (segmentleri) tanımlar ve 20 bitlik fiziki adresin oluşturulmasında kullanılır. IP, kod segmentinin ofset yazmacıdır; CS ile birleşerek programın hangi hafıza gözünde olduğunu verir. Ardışık bir kod bloğunda, dallanma yoksa, IP her komutta komutun boyu kadar artar; koşullu dallanma ya da near jump varsa buna göre güncellenir. Son olarak **ES** (extra segment) vardır; özellikle katar işlemlerinde DI için segment değeri üretir.

### 7.4 Assembly dersinden yeni olan: IN ve OUT

Hoca assembly dersinde kullanılmayan ama bu derste sık kullanılacak **IN** ve **OUT** komutlarına dikkat çekti. Bu komutlarda AX ve AL veri operandı olarak, DX ise port numarasını vermek için kullanılır. Hoca örneği sohbet penceresine yazdı:

```text
MOV DX, 200H
IN  AX, DX
```

Bu komut çifti, IN ya da OUT komutunda AX ile DX'in birlikte kullanılacağını gösterir.

### 7.5 Örnek: fiziki adres hesabı

Segment ve ofset yazmaçlarının birlikte kullanımına hoca bir örnek verdi: DS = 1230H, SI = 0045H.

- Segment değerinin sonuna bir onaltılık 0 eklenir: $1230H \times 10H = 12300H$.
- Ofset eklenir: $12300H + 0045H = 12345H$.
- Sonuç 20 bitlik fiziki adres 12345H'dır.

**Soru:** 12345H fiziki adresi farklı segment ve ofset değerleriyle de üretilebilir mi, yoksa bunu üreten tek çift 1230H ve 0045H mi? **Cevap:** Öğrencilerin dediği gibi örtüşme (overlap) vardır. Örtüşmeyen 16 segment tanımlanabilir, ama segmentler örtüştürülebilir. Bu yüzden farklı segment ve ofset değerleriyle aynı fiziki adres üretilebilir.

> **Hocanın vurgusu:** "Bir fiziki adres değeri sadece tek bir segment ve offset ikilisiyle üretilebilir" ifadesi yanlıştır.

## 8. Bayrak Yazmacı

Bayrak (flag) yazmacındaki her bit belirli bir görev yapar. Slaytlarda bayraklar şöyle tanımlanıyordu (ekrandan, 00:50:00 ve 00:55:00):

- **Carry Flag (CF):** İşaretsiz işlemlerde taşma olursa 1 değerini alır.
- **Parity Flag (PF):** İşlem sonucunda 1 olan bitlerin sayısı tek ise 0, çift ise 1 değerini alır.
- **Auxiliary Flag (AF):** 4 bitlik kısımların toplama-çıkarma sonucu elde değerini tutar.
- **Zero Flag (ZF):** İşlem sonucu 0 ise ZF = 1 olur.
- **Sign Flag (SF):** İşlem sonucu negatif ise SF = 1 olur.
- **Trap Flag (TF):** Her komuttan sonra kesme oluşmasını sağlar.
- **Interrupt enable Flag (IF):** Kesme kaynaklarının kesme oluşturmasına izin verir.
- **Direction Flag (DF):** Dizi işlemlerinde başlangıç adresinden itibaren artırarak ya da azaltarak sıradaki göze erişimi belirler.
- **Overflow Flag (OF):** İşaretli işlemlerde taşma durumunda 1 değerini alır.

### 8.1 Durum bayrakları

**CF:** İşaretsiz bir işlemde, örneğin bir ADD işleminde taşma olursa 1 olur. Daha pratik bir tanımla, toplama sonucunda elde üretiliyorsa CF = 1 olur. Bu iki tanım aynı şeye karşılık gelir: elde üretilmesi işaretsiz işlemlerdeki taşmadır.

**PF:** Eşlik biti, işlem sonucunun doğruluğunu kontrol etmeye yarayan bir kontrol bitidir. Hoca eşlik bitinin seri haberleşmede de kullanıldığını söyledi. Veri ve eşlik biti birlikte düşünüldüğünde toplam 1 sayısının çift olması isteniyorsa buna çift eşlik, tek olması isteniyorsa tek eşlik denir.

> **Ek bilgi (derste anlatılmadı):** 8086'da PF büyük olasılıkla yalnız sonucun düşük anlamlı 8 bitine bakılarak belirlenir.

**AF:** 4 bitlik işlemlerdeki taşmayı tutar, 4 bitlik elde gibi düşünülebilir. Örneğin `ADD AL, AH` işleminde düşük anlamlı 4 bitlerin toplamından yüksek anlamlı 4 bitlik kısma elde taşınıyorsa AF = 1 olur. Bütün bayraklar gibi tek bitlik bir bayraktır.

**ZF:** Bir aritmetik ya da lojik işlemin sonucu 0 ise ZF = 1 olur.

> **Hocanın vurgusu:** Yazmaçta 0 değeri oluştuysa zero flag 1 olur. Bu sık karışan bir noktadır, özellikle dikkat edilmeli.

### 8.2 Ayar bayrakları: TF, IF, DF

Hoca, diğer bayraklar bir durumu gösterirken TF, IF ve DF'nin birer ayar bayrağı olduğunu belirtti.

**TF (trap flag):** Her komut yürütüldükten sonra kendisiyle ilişkili bir kesme alt programını tetikler. Hoca bununla ilgili bir örneğin kesmeler konusunda geleceğini söyledi. Kullanım amacı adım adım debug'dır. Örneğin her adımda AX'in değerine bakmak istiyoruz. TF ayarlanır ve kod çalıştırılır. Her komuttan sonra TF'ye bağlı kesme alt programı tetiklenir. Bu alt program, elimizde bir LCD ekran varsa AX'in değerini ekrana yazar ve bir tuşa basılmasını bekler. Tuşa basılınca kesme alt programından dönülür ve bir sonraki komuta geçilir.

> **Ders sonrası not:** Hoca örnekte "TF bayrağını öncelikli olarak reset ettim" dedi. Her komuttan sonra kesme oluşması için TF'nin 1 yapılması (set edilmesi) gerekir; TF = 0 iken adım adım kesme oluşmaz.

**IF (interrupt enable flag):** Donanımsal kesmeleri açıp kapatmaya yarar. 8086'nın INTR isimli bir ucu vardır. Bu uç dış kesme kaynakları tarafından tetiklendiğinde IF = 1 ise işlemci dışarıdan gelen kesme isteğini değerlendirir. INTR ucuna istek gelse bile IF = 0 ise dış kesmeler değerlendirilmez.

**DF (direction flag):** Katar işlemlerinde her adımda bir sonraki hafıza gözüne mi yoksa bir öncekine mi ilerleneceğini belirler. DF = 0 ise her adımda bir sonraki hafıza gözüne ilerlenir. Başta CX ayarlanmıştır; CX her adımda 1 azalır ve 0 olana kadar her seferinde bir sonraki adrese ilerlenerek veri kopyalanır. Slayta göre DF, erişimin artırarak ya da azaltarak yapılacağını belirler; yani DF = 1 iken bir önceki göze doğru ilerlenir.

<!-- BELİRSİZ: DF = 1 durumunun sözlü açıklaması kayıtta kesik (00:54:55–00:55:27); yukarıdaki cümle slayttaki "arttırarak/azaltarak" ifadesine dayanıyor. -->

### 8.3 Overflow Flag

OF, işaretli işlemlerde sonuç yazmaca sığmıyorsa 1 olur. Hoca basit bir örnek sordu: 8 bitlik işaretli sayılar hangi aralıkta temsil edilir? Cevap: $-128$ ile $127$ arası. $127 + 100$ gibi bir toplamanın sonucu 8 bitlik işaretli sayılarla ifade edilemez, bu durumda OF = 1 olur. Bölme, çarpma ve öteleme işlemleri de taşma üretebilir.

> **Ders sonrası not:** Hoca $127 + 100$ toplamının sonucunu "200" dedi; doğrusu $227$'dir. Sonuç $127$'yi aştığı için taşma yine olur. 8 bitlik işaretli yorumla sonuç $227 - 256 = -29$ olarak görünür.

Hoca son olarak 8086'da genel amaçlı tek bitlik bir bayrak olmadığını, her bayrağın tanımlanan özel bir işlevi olduğunu belirtti.

## 9. Real Mod ve Protected Mod Hafıza Adresleme

### 9.1 Real mod

8086 real modda çalışır; sonraki Intel işlemcileri protected modda da çalışabilir, bu yüzden ikisi karşılaştırmalı verildi. 8086'nın hafıza kapasitesi 1 MB'tır ve real mod 1 MB'lık adreslenebilir alanın tamamını kullanmaya izin verir; 8086 için bu, bütün hafızayı kullanmak demektir. 80x86 ailesindeki bütün bilgisayarlar ilk açılışta real modda çalışmaya başlar.

Real modda offset memory model çerçevesinde herhangi bir hafıza gözüne erişilir: segment yazmacı 10H ile çarpılıp ofset eklenince 1 MB içindeki istenen noktaya ulaşılır. Slayt şöyleydi (ekrandan, 01:00:00):

- Real modda segment adres ve ofset adres değerlerinin birleşimiyle hafızada istenen alana erişilir.
- Bir segment değeri 64 KB'lık alanı gösterir (NEDEN?).
- Ofset değeri 64 KB'lık alan içinde bir yeri gösterir.
- Örnek: Segment değeri 1000H, ofset değeri 2000H ise mikroişlemcide erişilen fiziki adres ne olur?
- $1000H \times 10H + 2000H = 12000H$ (`1000H:2000H`).

**Soru:** Segment değeri sabitken neden yalnız 64 KB'lık bir alana erişilebilir? **Cevap:** Bu tamamen ofset yazmacının 16 bit olmasıyla ilgilidir. Segment sabitlenince ofset 0000H ile FFFFH arasında değer alır. Bu $2^{16} = 64\text{K}$ farklı değer demektir; her adres bir baytı gösterdiği için bir segment değerine karşılık 64 KB'lık bir aralık vardır.

Slayttaki örnekte segment değeri 1000H'ın sonuna bir 0 eklenir (10000H), ofset 2000H eklenir ve fiziki adres 12000H bulunur. Segment ve ofset, aralarına iki nokta üst üste konarak `1000H:2000H` biçiminde de yazılabilir.

### 9.2 Protected mod

Protected modda işlemcinin erişebileceği toplam hafıza 1 MB'tan fazladır; bu durum 20'den fazla adres ucu olan işlemciler için geçerlidir. Fakat 16 MB ya da 64 MB gibi daha büyük alanın tamamına erişim izni verilmez. Her programın kullanabileceği adres aralığı bir tablo üzerinden tanımlanır. Bir program başka hafıza gözlerine erişmeye çalışsa bile nereye eriştiğini bilmez ve oraya erişim izni yoktur. Geniş hafızadaki erişimi belirleyen tanımlamaların yanında, programa ayrılmış alandaki erişimi tanımlayan özel tanımlamalar da olabilir.

## 10. Komut Yapısı ve Operand Sayısı

Hoca, assembly dersinden getirilmesi gereken adresleme modlarına geçmeden önce komutların genel yapısını hatırlattı. Adresleme modları veri erişimi için geçerlidir; ama hafızadan veriye de, program koduna da erişilebilir. Bu yüzden veri adresleme modları ve program hafızası adresleme modları ayrı incelenecektir.

Bir 8086 komutu hiç operand almayabilir, bir operand ya da iki operand alabilir.

**Soru:** Açıkça verilen üç operandlı bir komut var mı? **Cevap:** Yok. Ama gizli operandlı işlemler vardır.

**Soru:** `MUL BX` komutunda hangi yazmaçlar kullanılır? AX 16 bit, BX 16 bit; sonuç 16 bite sığmazsa ne olur? **Cevap:** Bir öğrenci DX:AX gösterimini yazdı ve hoca bunu doğru kabul etti; sonuç taşmaya gitmez. DX:AX gösterimi, 16 bitlik DX ile 16 bitlik AX'in birlikte 32 bitlik bir değer oluşturması demektir. `MUL BX` komutunda gizli operand AX çarpılanlardan biridir ve BX ile çarpılır; sonuç 32 bitlik DX:AX çiftine yazılır. DX'te sonucun yüksek anlamlı 16 biti, AX'te düşük anlamlı 16 biti saklanır. Böylece gizli operandlarla birlikte üç farklı yazmaç kullanan bir komut görülmüş olur.

> **Hocanın vurgusu:** Açıkça verilen operandlarla 8086'da asla üç operandlı bir komut yoktur.

**Soru:** Tek operand alan bir komut? **Cevap:** Öğrencilerin verdiği INC (increment) örnekleri doğrudur. **Soru:** Hiç operand almayan bir komut? **Cevap:** NOP (no operation) operand almaz. Öğrencilerden gelen CWD (convert word to double word) da operand almaz. JLE bir operand alır ama bu operand yazmaç değildir. RET'in operand alan ve almayan iki biçimi vardır.

Genel yapı: önce komutun kısaltması (mnemonic), sonra operandlar gelir. `ADD AX, BX` komutunda AX ve BX toplanır, sonuç AX'te saklanır. Yani sonucun saklandığı yer komuta yakın olan operanddır. Slaytta `MOV AX, BX` için AX'in hedef (destination), BX'in kaynak (source) olduğu oklarla gösteriliyordu (ekrandan, 01:05:00).

Hoca, komutların nasıl yürütüldüğüne bir örnek olarak şunu verdi: AX = 1234H, BX = ABCDH olsun. `MOV AX, BX` çalıştırılınca AX hedef olduğu için işlem kaynaktan hedefe taşıma biçiminde yürür ve komuttan sonra hem AX'te hem BX'te ABCDH bulunur.

## 11. Veri Adresleme Modları

### 11.1 Yazmaç adresleme

Operandlar yazmaçsa bu yazmaç adreslemedir. MOV komutlarında 8 bitlik işlemler için AL, AH, BL, BH, CL, CH, DL ve DH; 16 bitlik işlemler için AX, BX, CX, DX, SP, BP, SI ve DI kullanılabilir.

### 11.2 Hemen adresleme (immediate addressing)

Bir önceki modda bir yazmacın değeri başka bir yazmaca kopyalanıyordu. Hemen adreslemede ise sabit bir değer bir yazmaca ya da hafıza bölgesine kopyalanır. Slayttaki tanım: sabit değer atamayı ifade eder; 16 bit ya da 8 bit sabit değer atama söz konusu olabilir. Örnekler (ekrandan, 01:10:00):

```text
MOV AL, 0F2H
MOV CX, 100
MOV BL, 01010101B
MOV AH, 'A'   ;ASCII A karakteri AH yazmacına atanır
```

- Sabit değer yazmaç genişliğine uygun olmalıdır. AL'ye 16 bitle ifade edilebilen bir sabit vermek anlamlı değildir. F2H 8 bite sığar.
- Onaltılık bir sayının en yüksek anlamlı basamağı A–F harflerinden biriyse sayı mutlaka 0 ile başlamalıdır; bu yüzden `0F2H` yazılır.
- Yanında hiçbir tanımlayıcı olmayan sayı onluktur: `100` onluk yüz demektir.
- İkilik yazmak için sayının sonuna B harfi eklenir.
- ASCII karakterler de birer sabittir: `MOV AH, 'A'` komutu AH'ye A karakterinin ASCII kodunu atar.

### 11.3 Doğrudan adresleme

Doğrudan adreslemede hafıza erişimindeki ofset köşeli parantez içinde sabit olarak verilir. Hemen adreslemeden temel farkı budur: hemen adreslemede sabitin etrafında köşeli parantez yoktur, doğrudan adreslemede vardır. Köşeli parantez "bu ofsetteki veriyi al ve kopyala" anlamına gelir.

Örneğin `MOV BX, [1234H]` komutunda ofset 1234H'dır. Veri erişimi olduğu için varsayılan segment DS'dir. DS 10H ile çarpılır, 1234H eklenir; hafızanın $DS \times 10H + 1234H$ numaralı gözündeki değer alınıp BX'e kopyalanır.

### 11.4 Dolaylı adresleme ve BYTE PTR / WORD PTR

Dolaylı adreslemede köşeli parantez içindeki değer sabit değil, bir yazmaçta tutulan değerdir.

> **Hocanın vurgusu:** Veri erişiminde köşeli parantez içine ofset yazmacı olarak yalnız üç yazmaç yazılabilir: BX, DI ve SI. Yığın erişiminde ise BP yazılabilir.

Örneğin önce BX'e bir değer atanır, sonra `MOV AX, [BX]` çalıştırılır. Varsayılan segment DS olduğundan DS o an neye ayarlıysa $DS \times 10H + BX$ numaralı gözün içeriği AX'e kopyalanır.

Dolaylı adreslemede dikkat edilmesi gereken bir nokta vardır: bazı durumlarda erişilen hafıza gözünden bayt mı word mü alınacağı açıkça belirtilmelidir. Slayt şöyleydi (ekrandan, 01:15:00): dolaylı adreslemelerin bir kısmında BYTE PTR, WORD PTR gibi özel tanımlayıcılar vermek gerekir; artırma komutu INC, dolaylı adreslemeyle hafızada bir word mü yoksa bayt mı artıracağını bilemez; örnek `INC WORD PTR [BX]`; dolaylı adreslemede operandlardan biri yazmaç ise BYTE PTR, WORD PTR'ye gerek yoktur (NEDEN?).

Hoca farkı bir örnekle gösterdi. İlk denemede seçtiği değerlerin farkı iyi göstermediğini söyleyip örneği değiştirdi:

- Verilen: BX = 100H. Hafızada 100H gözünde FFH, 101H gözünde 12H var.
- `INC BYTE PTR [BX]`: İşlemci hafızanın 100H gözüne gider ve buradaki FFH'ı bir artırır. Sonuç 00H olur ve elde (carry) oluşur. 101H gözüne dokunulmaz.
- `INC WORD PTR [BX]`: 100H adresinden itibaren 2 bayt yer kaplayan word bir artırılır. Little endian yerleşimde düşük bayt 100H'da, yüksek bayt 101H'dadır; word 12FFH'tır. Bir artırılınca 1300H olur: 100H gözü 00H, 101H gözü 13H olur.

Bayt sürümünde yalnız 100H gözü 00H olur; word sürümünde 100H ve 101H gözlerindeki word birlikte artırılır. Aradaki fark budur.

> **Ders sonrası not:** Hoca bayt örneğinde FFH 00H olunca ilgili carry bayrağının etkileneceğini söyledi. INC komutu büyük olasılıkla CF'yi değiştirmez; sonucun 00H olması ZF'yi 1 yapar.

**Soru:** BYTE PTR ya da WORD PTR yazılmazsa ne olur? **Cevap:** Hoca assembler'ın bunu ne kabul ettiğini o an bilmediğini, büyük ihtimalle hata verebileceğini söyledi.

> **Hocanın vurgusu:** Veri tipinin belli olmadığı durumlarda, bu ders kapsamında, işlemin hangi veri tipiyle yapılacağı BYTE PTR ya da WORD PTR ile açıkça yazılmalıdır. Hoca bunu dersin ortak kuralı olarak belirledi.

**Soru:** `MOV AX, [100H]` komutunda 100H adresinden word mü bayt mı alınacağı belirtilmediği hâlde neden BYTE PTR ya da WORD PTR gerekmez? **Cevap:** AX kullanıldığı için AX'in genişliği (16 bit) otomatik olarak veri tipi kabul edilir. Hoca bu cevabı doğru buldu.

### 11.5 Yazmaç dolaylı adreslemenin kullanım yeri

Slayt: dizi olarak tutulan veriye sıralı erişimde yazmaç dolaylı adresleme kullanımı uygundur. Şekilde BX benzeri bir yazmacın bir tablonun başlangıcını (Table) gösterdiği, sonraki gözlerin Table+1, Table+2, ..., Table+49 olduğu bir hafıza görünüyordu (ekrandan, 01:20:00). BX, DI ya da SI bir taban oluşturacaksa, örneğin bir arama tablosunun (lookup table) başlangıç adresini tutmak için yazmaç dolaylı adresleme uygundur.

### 11.6 Taban + indeks ve taban + indeks + sabit

Bir sonraki modda bir taban yazmacı (BX ya da BP) ile bir indeks yazmacı birlikte kullanılır. Köşeli parantez içinde şunlara izin verilir:

- Yalnız bir sabit değer
- Yalnız BX, SI, DI ya da BP yazmaçlarından biri
- `[BX+DI]` ya da `[BX+SI]` gibi bir toplam (matris ve benzeri yapılarda kullanılabilir)
- Taban + indeks + sabit, örneğin `[BX+SI+100H]`

Son örnekte de varsayılan segment DS'dir: DS 10H ile çarpılır, $BX + SI + 100H$ eklenir ve 20 bitlik adres üretilir.

## 12. Program Hafızası ve Yığın Adresleme

### 12.1 Doğrudan program hafızası adresleme

Program komutlarına erişirken kullanılan adresleme modları doğrudan, göreli ve dolaylı olarak üçe ayrılır. Doğrudan adresleme JMP ve CALL gibi komutların far sürümlerinde geçerlidir: segment ve ofset değeri açıkça verilerek hangi program bölgesine gidileceği belirtilir. İlk verilen değer CS'ye, ikinci değer IP'ye yazılır ve başka bir segmentteki kod bloğuna atlanır. JMP'ye tek bir değer verilseydi bulunulan segment içinde görece bir dallanma olurdu. Aynı şey CALL ile de yapılabilir.

### 12.2 Göreli program hafızası adresleme

Göreli adresleme, bulunulan kod satırındaki IP değerine göre nereye gidileceğini belirler; near jump komutları için geçerlidir. Slayt (ekrandan, 01:25:00): mevcut IP yazmacı değerine göre hangi program hafızasının adresleneceğini ifade eder; JMP komutu 1 bayt ya da 2 bayt işaretli sabit değerli operand kabul eder. Örnekler:

```text
JMP 100
JMP 0FFH ; IP değeri 1 azalır (NEDEN?)
JMP 1000H
```

`JMP 100` denildiğinde bulunulan IP'den 100 birim ileri gidilir, yani IP + 100'deki komut yürütülür.

**Soru:** `JMP 0FFH` çalıştırılınca IP neden 1 azalır? **Cevap:** Öğrencilerin dediği gibi near jump'ta verilen değer işaretli sayı olarak değerlendirilir. En yüksek biti 1 olan bir dallanma miktarı negatif sayı olarak anlaşılır. FFH'ın ikiye tümleyen karşılığı $-1$'dir; bu yüzden IP 1 azalır ve bir adım geri gidilir. 8 bitlik bir değer verilirse bu değer $-128$ ile $127$ arasında olabilir. Daha uzağa gitmek için far jump kullanılmalı ya da uygun biçimde iki kez jump yapılmalıdır.

<!-- BELİRSİZ: Slayttaki üçüncü örnek "JMP 1000H" derste sözlü olarak açıklanmadı. -->

### 12.3 Dolaylı program hafızası adresleme

Dolaylı adresleme de JMP ve CALL komutlarıyla kullanılır. Doğrudan bir yazmaç verilebilir (`JMP BX`) ya da köşeli parantez içinde dolaylı bir adres verilebilir (`JMP [BX]`). İkincisinde BX'in içeriğine göre hafızanın ilgili gözüne gidilir ve gidilecek alt programın adresi oradan alınır.

### 12.4 Yığın adresleme

Veri erişimi ve program hafızası erişiminden sonra yığın segmentindeki erişim kaldı. Yığına veri yazan ya da yığından veri çeken bütün komutlar, örneğin PUSH ve POP, yığın adresleme modlarını kullanır. Bunlar varsayılan segment olarak SS'yi, ofset yazmacı olarak SP'yi kullanır.

- Özel durum: CS'ye yığından veri çekilemez, ama CS değeri yığına basılabilir.
- Yığın işlemleri word tipindeki veriler üzerinden yapılır. Yığına atılan değer word olmalı, yığından çekilen değer word tipinde bir yazmaca ya da hafıza bölgesine okunmalıdır. Bu yüzden `PUSH BL` yanlıştır: 8 bitlik bir değer yığına atılamaz.
- PUSH ve POP işlemlerinde her seferinde 2 bayt atılır ya da çekilir.

Hoca toparlarken yığın adreslemede dolaylı bir biçim olmadığını, dolaylı adreslemenin veri erişimine ait olduğunu söyledi: köşeli parantez içinde taban yazmacı (yazmaç dolaylı), taban + indeks ve taban + indeks + sabit. Bu ders için önemli olanlar veri erişimindeki adresleme modlarıdır; diğerleri daha çok bilgi amaçlıdır.

## 13. 8086 Uç Tanımlarına Giriş

Hoca buraya kadar 8086 ve genel mikroişlemci kavramlarının karşılaştırmalı olarak tanımlandığını, karşılaştırmalı tanımın farkı anlamayı sağladığı için önemli olduğunu söyledi. Ardından assembly dersinden getirilmesi gereken bilgilerin üzerinden geçildi. Bundan sonra 8086'nın fiziksel, donanım tarafındaki özelliklerine geçilecek ve ilk konu 8086'nın uçlarıdır.

### 13.1 Maksimum ve minimum mod

Uçlar iki farklı moda göre tanımlanır: maksimum mod ve minimum mod. Slaytta 40 bacaklı 8086 entegresi vardı (ekrandan, 01:30:00). Sol tarafta 1'den 20'ye: GND, AD14, AD13, ..., AD0, NMI, INTR, CLK, GND. Sağ tarafta 40'tan 21'e: Vcc, AD15, A16/S3, A17/S4, A18/S5, A19/S6, /BHE/S7, MN/MX, /RD, sonra moda göre değişen sekiz uç, ardından /TEST, READY, RESET. Moda göre değişen uçlar şunlardır:

| Maksimum mod | Minimum mod |
|---|---|
| /RQ, /GT0 | HOLD |
| /RQ, /GT1 | HLDA |
| /LOCK | /WR |
| /S2 | IO/M |
| /S1 | DT/R |
| /S0 | /DEN |
| QS0 | ALE |
| QS1 | /INTA |

Derste 8086 minimum modda, yardımcı işlemci olmadan kullanılacağı için maksimum mod fonksiyonları (kırmızı) kullanılmayacak, mavi işaretli minimum mod fonksiyonları geçerli olacaktır.

### 13.2 MN/MX ucu ve aktif 0 gösterimi

Minimum ve maksimum mod arasındaki geçişi MN/MX ucu sağlar. Hoca bu uç üzerinden önemli bir gösterimi anlattı. Ucun adı aslında MN ve üzeri çizgili MX olarak yazılır; hoca slayta bu biçimi elle çizdi (ekrandan, 01:35:00). Üst çizgiyi matbu yazıda göstermek pratik olmadığı için önüne bir eğik çizgi (`/`) konur. Ayrıca MN ile MX'i ayırmak için araya virgül ya da eğik çizgi konabilir. Bu gösterimlerin hepsi aynı şeyi ifade eder: ucun adı MN/MX'tir.

İşleyişi şöyledir: uçta lojik 0 varsa MX fonksiyonu, yani maksimum mod; lojik 1 varsa MN fonksiyonu, yani minimum mod geçerlidir. 8086'yı minimum moda sokmak için MN/MX ucuna 1 verilir.

> **Hocanın vurgusu:** Bir entegrenin uç adında üst çizgi ya da `/` olan fonksiyon aktif 0'dadır. MN/MX ucunda 0 maksimum, 1 minimum fonksiyonunu gösterir. Bu gösterim ders boyunca kullanılacak, önemli bir notasyondur.

### 13.3 Adres/veri uçları, ALE ve /DEN

20 adres ucunun yeri şöyledir: AD0'dan AD15'e kadar olan uçlar hem adres hem veri işlevi gören, zaman çoğullamalı adres/veri uçlarıdır. A16, A17, A18 ve A19 ise bazı durum (status) bitleriyle zaman çoğullamalı kullanılan adres uçlarıdır. Böylece 20 adres ucu oluşur. 16 veri ucu da AD0–AD15'tir. Bu uçlar zaman çoğullamalı olduğu için T1 anında adres değerleri, T2 anında veri değerleri bu uçlardan çıkar.

**Soru:** AD uçlarında hangi anda adres, hangi anda veri olduğu nasıl anlaşılır? **Cevap:** Bunun için iki uç vardır.

- **ALE (Address Latch Enable):** AD uçlarında adres değeri varken ALE 1'e çıkar. Bu ucun 1 olduğu an yakalanınca AD uçlarındaki değer kopyalanıp tutulur ve komut yürütülürken sisteme bu adres değeri sunulur. Bunun nasıl yapıldığı sonraki derslerde görülecektir.
- **/DEN (Data Enable):** AD uçlarında veri olduğu bu uçla anlaşılır. Adının başında eğik çizgi olduğu için aktif 0'dır, yani işlev gördüğünde 0 değerini alır. /DEN'in 0'a düştüğü an yakalanıp AD uçlarındaki değer alınınca sisteme veri değerleri sunulur.

> **Hocanın vurgusu:** ALE ve /DEN mantığı önemlidir; diğer uçlar da bu çerçevede açıklanacak.

Bundan sonraki plan şöyledir: her ucun hangi fonksiyonu gösterdiği ve nasıl çalıştığı anlatılacak; ardından 8086'nın çalışması için gereken yardımcı devreler, örneğin saat darbesi üreteci ve AD uçlarındaki değeri tutan latch ile buffer entegreleri ele alınacak ve çalışır bir sistem elde edilecek. En sonda veri okuma ve yazma zaman diyagramlarına kısaca değinilerek 8086'nın genel özellikleri bitirilecek.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:17:54): Bir sayıyı onaltılık 10 (10H) ile çarpmak ne anlama gelir?

> **Çözüm:** 16 ile çarpmaktır; ikilik düzende 4 bit sola kaydırmak, yani sağa dört tane 0 biti eklemektir. 16 bitlik segment değeri böylece 20 bite çıkar.

**Soru 2** (derste sözlü, 00:19:59): 1 MB'lık alan içinde birbiriyle örtüşmeyen kaç segment tanımlanabilir?

> **Çözüm:** Bir segment $2^{16} = 64\text{K}$ bayttır. $1\text{M} / 64\text{K} = 2^{20} / 2^{16} = 16$ segment.

**Soru 3** (derste sözlü, 00:21:28): Kod, yığın ve veri erişiminde kullanılan segment ve ofset yazmaçları hangileridir?

> **Çözüm:** Kod: CS ve IP. Yığın: SS ve SP ya da BP. Veri: DS ve BX, SI ya da DI (ekrandan, 00:30:00).

**Soru 4** (ekrandan, 00:30:00): `MOV AX, [100H]` komutunda varsayılan segment hangisidir ve fiziki adres nasıl hesaplanır?

> **Çözüm:** Veri erişimi olduğu için DS. $PA = DS \times 10H + 100H$.

**Soru 5** (derste sözlü, 00:28:58): Aynı anda birçok kişinin 2.4 GHz civarında Wi-Fi ile haberleşebilmesi hangi çoğullama türüdür?

> **Çözüm:** Frekans çoğullaması: herkes 2.4 GHz civarındaki farklı alt bantlarda haberleşir. 8086'daki ise zaman çoğullamasıdır.

**Soru 6** (derste sözlü, 00:46:12): DS = 1230H, SI = 0045H ise fiziki adres nedir? Bu adres başka segment:ofset çiftleriyle de üretilebilir mi?

> **Çözüm:** $1230H \times 10H + 0045H = 12300H + 0045H = 12345H$. Segmentler örtüşebildiği için aynı fiziki adres farklı segment:ofset çiftleriyle de üretilebilir.

**Soru 7** (ekrandan, 01:00:00): Segment değeri 1000H, ofset değeri 2000H ise mikroişlemcide erişilen fiziki adres ne olur?

> **Çözüm:** $1000H \times 10H + 2000H = 10000H + 2000H = 12000H$; gösterim `1000H:2000H`.

**Soru 8** (ekrandan, 01:00:00): Bir segment değeri neden 64 KB'lık alanı gösterir?

> **Çözüm:** Segment sabitken ofset 16 bittir ve 0000H–FFFFH arasında $2^{16} = 64\text{K}$ farklı değer alır; her adres bir bayt olduğundan 64 KB.

**Soru 9** (derste sözlü, 00:55:36): 8 bitlik işaretli sayılar hangi aralıktadır? $127 + 100$ işleminde hangi bayrak 1 olur?

> **Çözüm:** Aralık $-128$ ile $127$'dir. $127 + 100 = 227 > 127$ olduğundan sonuç 8 bitlik işaretli sayıya sığmaz ve OF = 1 olur (hoca sonucu "200" dedi; doğrusu 227).

**Soru 10** (derste sözlü, 01:03:04): `MUL BX` komutunda hangi yazmaçlar kullanılır? Sonuç 16 bite sığmazsa ne olur?

> **Çözüm:** AX gizli operanddır ve BX ile çarpılır. 32 bitlik sonuç DX:AX'e yazılır: DX yüksek 16 bit, AX düşük 16 bit. Taşma oluşmaz.

**Soru 11** (derste sözlü, 01:04:51): Tek operand alan ve hiç operand almayan birer komut örneği veriniz. Açık üç operandlı komut var mıdır?

> **Çözüm:** Tek operand: INC. Operandsız: NOP, CWD. 8086'da açık üç operandlı komut yoktur.

**Soru 12** (derste sözlü, 01:15:14): BX = 100H, hafızada [100H] = FFH ve [101H] = 12H iken `INC BYTE PTR [BX]` ve `INC WORD PTR [BX]` komutlarının sonuçları nedir?

> **Çözüm:** BYTE PTR: [100H] = 00H olur, [101H] = 12H değişmez. WORD PTR: little endian word 12FFH bir artar ve 1300H olur; [100H] = 00H, [101H] = 13H.

**Soru 13** (ekrandan, 01:15:00): Dolaylı adreslemede operandlardan biri yazmaç ise neden BYTE PTR / WORD PTR gerekmez?

> **Çözüm:** Yazmacın genişliği veri tipini belirler. `MOV AX, [100H]` komutunda AX 16 bit olduğu için word alınır.

**Soru 14** (ekrandan, 01:25:00): `JMP 0FFH` komutunda IP değeri neden 1 azalır?

> **Çözüm:** Near jump'ın operandı işaretli sayıdır. FFH'ın en yüksek biti 1 olduğundan ikiye tümleyende $-1$ demektir; IP 1 azalır. 8 bitlik görece değer $-128$ ile $127$ arasındadır.

## Dersin Toparlaması

Bu derste 8086'ya ve genel mikroişlemci kavramlarına ait tanımlar karşılaştırmalı olarak tamamlandı. Real ve protected mod, pipeline, zaman ve frekans çoğullama, yardımcı işlemci ve cache'in uzamsal/zamansal yerellik ilkeleri ele alındı. Ardından assembly dersinden getirilmesi gereken bilgiler hatırlatıldı: $PA = \text{segment} \times 10H + \text{ofset}$ ile fiziki adres hesabı, segment-ofset eşleşmeleri, genel amaçlı ve özel yazmaçların görevleri, bayrak yazmacındaki her bitin anlamı, veri, program hafızası ve yığın adresleme modları. Bu derse özgü yeni bilgi olarak IN/OUT komutlarında AX/AL ve DX kullanımı vurgulandı.

Dersin sonunda donanım tarafına geçildi. 8086'nın 40 bacaklı uç şeması, maksimum ve minimum mod farkı, MN/MX ucu üzerinden aktif 0 gösterimi ve zaman çoğullamalı AD uçlarında adres ile veri anlarını ayıran ALE ve /DEN uçları anlatıldı. Sonraki derste uçların tek tek açıklanmasıyla devam edilecek; saat üreteci, latch ve buffer devreleri ile okuma/yazma zaman diyagramları görülecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
