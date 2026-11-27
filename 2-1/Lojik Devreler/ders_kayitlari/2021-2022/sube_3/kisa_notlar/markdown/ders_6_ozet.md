# Ders 6 Çalışma Özeti

## Genel Konular

- Analog işaretin sayısallaştırılması ve çözünürlük
  - Analog işaret zamanla sürekli değişen bir büyüklüktür (gerilim, akım, sıcaklık vb.). Belirli aralıklarla örneklenip her aralıkta değeri sabit tutularak basamaklı bir sayısal işarete çevrilir.
  - Bilgisayar sonlu bir makinedir; sonsuz değerli sürekli işareti doğrudan işleyemez, bu yüzden ayrıklaştırma gerekir.
  - Analogdan sayısala çevirme ADC, tersi DAC ile yapılır. Bit sayısı arttıkça basamak sayısı artar ve sayısal işaret orijinale daha çok yaklaşır (16 bitlik ADC, 8 bitlikten daha hassastır).
  - Çözünürlük (adım) formülü (ekrandan, 00:15:00): $a = \dfrac{V_{maks}}{2^n}$.
- Sayı sistemleri ve taban dönüşümleri
  - Onluk (10), sekizlik (8), ikili (2) ve onaltılı (16) tabanlar; her tabanda sayı basamak ağırlıklarıyla çözümlenir.
  - İkili sistemde her hane "bit", 4 bit "nibble", 8 bit "byte", 16 bit (2 byte) "word" adını alır.
  - Onluktan başka tabana: tam kısım tabana bölünerek (kalanlar tersten okunur), kesirli kısım tabanla çarpılarak çevrilir.
  - İkili ile sekizli/onaltılı arasında 3'lü/4'lü bit gruplarıyla doğrudan geçiş yapılır.
- Aritmetik işlemler ve tümleyen aritmetiği
  - Farklı tabanlarda toplama, elde mantığıyla yapılır.
  - Bilgisayarda çıkarma yoktur; çıkan sayının tümleyeni alınıp toplanır. Bire tümleyen ve ikiye tümleyen yöntemleri.
- Bilgisayarda işaretli sayıların gösterimi
  - İşaret biti ile gösterim (eski sistemler) ve tümleyen aritmetiği ile gösterim (günümüz).
- Kodlama
  - Doğrudan kodlama, tablo tabanlı kodlama (ASCII), BCD, üç fazlalık kodu, Aiken kodu, bitişik kodlar ve Gray kodu, Hamming uzaklığı.
- Temel lojik işlemler ve kapılar
  - VE (AND), VEYA (OR), DEĞİL (NOT), VE DEĞİL (NAND), VEYA DEĞİL (NOR), ÖZEL VEYA (XOR), ÖZEL VEYA DEĞİL (XNOR).
  - Her işlem için lojik devre gösterimi, doğruluk tablosu, anahtar devresi ve zamanlama diyagramı.
- Boole cebri
  - Venn diyagramı sezgisi, aksiyomlar ve teoremler, De Morgan kuralı, Boole cebriyle sadeleştirme, dualite ilkesi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bilgisayarda çıkarma işlemi yoktur
  - Çıkarma, çıkan sayının bire ya da ikiye tümleyeni alınıp toplanmasıyla yapılır. Günümüz işlemcileri ikiye tümleyen aritmetiğini kullanır.
- Bire tümleyende elde kuralı
  - Toplamda elde 1 oluşursa sonuç pozitiftir ve elde en sağdaki basamağa eklenir. Elde oluşmazsa sonuç negatiftir ve gerçek sonuç, bulunan sonucun tümleyenidir.
- İşaret bitiyle gösterimin sakıncaları
  - Bir bit işarete gittiği için büyüklük için bir bit eksik kalır (8 bit yerine 7 bit) ve $+0$ ile $-0$ diye iki ayrı sıfır oluşur.
- Gray kodu Karnaugh haritalarında kullanılacak
  - Ardışık kod sözcükleri arasındaki Hamming uzaklığı 1'dir; Karnaugh haritalarının satır/sütun etiketleri bu düzende yazılır.
- Gerçek donanımda NAND ve NOR tercih edilir
  - Bu kapılar daha hızlıdır ve tek bir NAND ya da NOR türüyle hem VE hem VEYA işlemleri kurulabilir; böylece farklı entegre sayısı azalır.
- XOR ile kontrollü tümleme
  - Bir girişe veri akışı, diğerine kontrol biti verilirse kontrol 0 iken veri aynen geçer, 1 iken verinin bire tümleyeni çıkar.
- De Morgan kuralı en çok kullanılacak kural
  - $\overline{a+b}$ ifadesi $\bar a + \bar b$ değildir; üst çizgi içeri dağıtılırken işlem de değişir: $\overline{a+b}=\bar a\cdot\bar b$, $\overline{a\cdot b}=\bar a+\bar b$. Bu sık yapılan bir hatadır.

## Kısa Tekrar Notları

- Çözünürlük: $a = V_{maks}/2^n$. 0-15 V aralığını 100 mV duyarlılıkla kodlamak için $2^n \ge 150$, yani $n = 8$ bit gerekir.
- 4 bitlik DAC'de $1111 \to 6$ V ise adım $6/2^4 = 0{,}375$ V.
- $(1010)_2 = 10$, $(11001)_2 = 25$, $(111{,}101)_2 = 7{,}625$.
- $(33)_{10} = (100001)_2$, $(172)_{10} = (10101100)_2$.
- $(1357)_{10} = (54D)_{16}$, $(25{,}125)_{10} = (19{,}2)_{16}$.
- İkili-sekizli: 3 bitlik gruplar; ikili-onaltılı: 4 bitlik gruplar (virgülün iki yanından dışa doğru).
- Bire tümleyen: bitleri ters çevir. İkiye tümleyen: bire tümleyene 1 ekle.
- $1001 - 1101$: $1001 + 0010 = 1011$, elde yok, sonuç $-(0100)_2 = -4$.
- İşaret bitiyle $-5 = 10101$; ikiye tümleyenle $-5 = 1011$ (4 bit).
- BCD: her onluk basamak ayrı 4 bitle yazılır; üç fazlalık kodu: her basamağın 3 fazlası yazılır.
- Gray / bitişik kod: ardışık kod sözcükleri arasında Hamming uzaklığı 1.
- AND: ikisi de 1 ise 1; OR: biri 1 ise 1; NOT: tersler; NAND: ikisi de 1 ise 0; NOR: ikisi de 0 ise 1; XOR: farklıysa 1; XNOR: aynıysa 1.
- $A \oplus B = \bar A B + A \bar B$.
- Yutma: $a + ab = a$, $a(a+b) = a$; $a\bar b + b = a + b$.
- De Morgan: $\overline{a+b}=\bar a\,\bar b$, $\overline{ab}=\bar a+\bar b$.
- Dual: VE ile VEYA, 0 ile 1 yer değiştirir; değişkenler ve tümleyenleri aynı kalır.

## Detaylı Açıklamalar

- Sayısallaştırma ve çözünürlük
  - Tek eşik (threshold) kullanılırsa analog işaret 1 bitle gösterilir: eşiğin altı 0, üstü 1. Hoca bunu klimadaki termostata benzetti: sıcaklık bir eşiğin üstündeyse klima çalışır, altındaysa durur. Sıcaklık aslında sürekli bir büyüklüktür ama eşikle 1 ve 0'a indirgenir.
  - Birden fazla eşik (örneğin 2, 4 ve 6 seviyeleri) kullanılırsa işaret daha fazla basamağa bölünür ve bu basamaklara ikili etiket vermek için daha fazla bit gerekir. Bit sayısı, sayısallaştırılmış işaretin çözünürlüğünü belirler.
  - Örnek: 0-15 V arasında değer alan bir işaret 100 mV duyarlılıkla kodlanacak. Basamak sayısı $15\,000 / 100 = 150$ olur. $2^7 = 128 < 150$ olduğundan 7 bit yetmez, $2^8 = 256 \ge 150$ olduğundan 8 bitlik ADC gerekir.
  - Ters örnek: 4 bitlik bir DAC'de $0000 \to 0$ V ve $1111 \to 6$ V. Adım $6/2^4 = 0{,}375$ V alınarak dönüşüm tablosu kurulur. Hoca, formülde paydanın bazı kaynaklarda $2^n - 1$ yazıldığını da belirtti.
  - > **Ders sonrası not:** Hoca bir yerde 15 V'u "1500 milivolt" dedi; doğrusu 15 000 mV'tur (hesapta da 150 basamak kullanıldı). Ayrıca $1111$ kodunun tam 6 V'a karşılık gelmesi isteniyorsa adım büyük olasılıkla $6/(2^4-1) = 0{,}4$ V olmalıdır; $6/2^4$ ile $1111$ kodu $5{,}625$ V'a karşılık gelir.
- Taban dönüşümleri
  - Herhangi bir tabandaki sayı basamak ağırlıklarıyla çözümlenir (ekrandan, 00:25:00): $(173{,}25)_{10} = 1\cdot10^2 + 7\cdot10^1 + 3\cdot10^0 + 2\cdot10^{-1} + 5\cdot10^{-2}$, $(10111)_2 = 1\cdot2^4 + 0\cdot2^3 + 1\cdot2^2 + 1\cdot2^1 + 1\cdot2^0$.
  - Onluktan ikiliye ilk yöntem 2'ye art arda bölmektir; ilk kalan LSB (en anlamsız bit), son kalan MSB (en anlamlı bit) olur. İkinci yöntem sayıdan sığan en büyük 2 kuvvetini çıkara çıkara gitmektir: $172 = 128 + 32 + 8 + 4$, yani $(10101100)_2$.
  - Kesirli kısım tabanla çarpılır; virgülün soluna geçen basamak sırayla alınır ve ilk alınan, virgülden sonraki en anlamlı basamaktır. Örneğin $0{,}8125 \cdot 2 = 1{,}625$ ile ilk bit 1 bulunur ve işlem kesir sıfırlanana kadar sürer.
  - Onaltılık tabanda A-F harfleri 10-15'i gösterir. $(1357)_{10}$ 16'ya bölünerek $13(D), 4, 5$ kalanlarıyla $(54D)_{16}$ olur; $0{,}125 \cdot 16 = 2$ olduğundan $(25{,}125)_{10} = (19{,}2)_{16}$ (ekrandan, 00:40:00).
- Tümleyen aritmetiği
  - Bire tümleyenle çıkarma: çıkan sayının bitleri ters çevrilip çıkılan sayıyla toplanır. Elde oluşursa sonuç pozitiftir ve elde en sağ basamağa eklenir; oluşmazsa sonuç negatiftir ve sonucun bire tümleyeni alınır.
  - İkiye tümleyenle çıkarma: bire tümleyene 1 eklenir. Elde oluşursa atılır ve sonuç pozitiftir; oluşmazsa sonuç negatiftir ve büyüklüğü bulunan sonucun ikiye tümleyenidir.
  - Tümleme aslında sayıyı, o bit genişliğinde alabileceği en büyük değerden çıkarmaktır; bu fikir onluk tabanda da (9'a/10'a tümleyen) aynı biçimde uygulanır.
- İşaretli sayılar
  - İşaret bitiyle gösterimde en soldaki bit işarettir: $10110 = -6$, $00110 = +6$. Bu yöntemde $10000$ ($-0$) ve $00000$ ($+0$) diye iki sıfır oluşur.
  - Tümleyen aritmetiğinde negatif sayı pozitif sayının ikiye tümleyeniyle yazılır: $5 = 0101 \to 1010 \to 1011 = -5$. Aynı $1011$ işaret biti sisteminde $-3$ olarak okunurdu; hangi gösterimin kullanıldığına dikkat edilmelidir.
- Kodlar
  - ASCII tablo tabanlı bir koddur: klavyeden girilen "A" harfi tabloya göre 65 değeriyle ve onun ikili karşılığıyla tutulur.
  - BCD her onluk basamağı ayrı 4 bitle yazar: 24 doğrudan ikilide $11000$ iken BCD'de $0010\;0100$ olur.
  - Üç fazlalık kodunda her rakam 3 fazlasının ikili karşılığıyla yazılır ($0 \to 0011$, $9 \to 1100$). Alıcı tarafın kodun türünü bilmesi gerekir, yoksa veriyi çözemez.
  - Aiken kodunda 0-4 düz ikili, 5-9 ise sırasıyla 4, 3, 2, 1, 0'ın bire tümleyenidir.
  - Hamming uzaklığı iki kod sözcüğü arasında farklı olan bit sayısıdır. Bitişik kodlarda ardışık sözcükler arasındaki uzaklık 1'dir; ilk ve son sözcük arasında da 1 ise kod çevrimli bitişik koddur.
- Lojik kapılar ve Boole cebri
  - Boole cebri üç temel işleme dayanır: VE, VEYA ve tümleme. Diğer kapılar bunlardan türetilir. Tasarımın amacı problemi bir $F$ fonksiyonuyla ifade edip bu fonksiyonu kapılarla gerçeklemektir.
  - Doğruluk tablosu, bütün giriş kombinasyonlarında $F$'nin değerini verir. Girişler yazılırken LSB her satırda, sonraki bit iki satırda bir, sonraki dört satırda bir değişir.
  - Boole cebriyle sadeleştirme, Karnaugh haritalarından önce öğrenilecek ilk sadeleştirme yöntemidir. Teoremler (değişme, birleşme, dağılma, yutma, De Morgan vb.) bu sadeleştirmede kullanılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
