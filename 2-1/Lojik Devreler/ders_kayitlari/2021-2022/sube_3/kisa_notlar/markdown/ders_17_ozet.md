# Ders 17 Çalışma Özeti

## Genel Konular

- Türetilmiş kapılarla temel lojik kapıların yapılması
  - Amaç, bir devreyi olabildiğince tek tür kapıyla gerçekleştirmektir. Bir tümleşik devre (çip) içinde aynı türden birden çok kapı bulunur; tek tür kapı kullanılırsa çipin bütün kapıları değerlendirilebilir ve daha az çip gerekir.
  - NAND ve NOR kapılarının yapımı, maliyet bakımından AND ve OR kapılarına göre daha uygun olduğu için tercih edilir.
  - NOT: NAND ya da NOR kapısının iki girişi kısa devre edilip aynı $a$ girişi verilirse çıkış $a'$ olur. Gerekçe: $a\cdot a = a$ ve $a + a = a$; dolayısıyla $(a\cdot a)' = a'$, $(a+a)' = a'$ (ekrandan, 00:15:00).
  - AND: $f = ab = ((ab)')'$. NAND ile: bir NAND $(ab)'$ üretir, girişleri kısa devre edilmiş ikinci bir NAND tümler. NOR ile: De Morgan'dan $ab = (a' + b')'$; $a'$ ve $b'$ birer NOR'la, dış ifade bir NOR'la yapılır (toplam 3 NOR) (ekrandan, 00:20:00).
  - OR: $f = a + b = ((a+b)')'$. NOR ile: bir NOR $(a+b)'$ üretir, ikinci bir NOR tümler. NAND ile: De Morgan'dan $a + b = (a'b')'$; $a'$ ve $b'$ birer NAND'la, dış ifade bir NAND'la yapılır (toplam 3 NAND).
- İndirgenmiş ifadelerin aynı tür kapılarla gerçeklenmesi
  - Genel gösterimler: çarpımlar toplamı $f = \sum\prod x_i$, toplamlar çarpımı $f = \prod\sum x_i$ (ekrandan, 00:30:00).
  - Dört tasarım ele alındı: A1 çarpımlar toplamının NAND (TVE) tasarımı, A2 çarpımlar toplamının NOR (TVEYA) tasarımı, B1 toplamlar çarpımının NAND (TVE) tasarımı, B2 toplamlar çarpımının NOR (TVEYA) tasarımı.
  - Bütün dönüşümler yalnız çift tümleme ($x = (x')'$) ve De Morgan kurallarına dayanır.
- A1: Çarpımlar toplamının NAND tasarımı
  - $f = \left(\prod (\prod x_i)'\right)'$: içteki çarpımlar NAND, dıştaki toplam da bir NAND olur (ekrandan, 00:35:00).
  - Örnek: $f = \bar a\bar b c + \bar a b c + a b\bar c + abc$. Karnaugh haritasından $f = ab + \bar a c$ bulundu (ekrandan, 00:35:00). NAND biçimi $f = \left((ab)'\,(\bar a c)'\right)'$; devre 4 NAND kapısıyla kuruldu (ekrandan, 00:40:00).
- A2: Çarpımlar toplamının NOR tasarımı
  - Bir çarpım terimi De Morgan ile $\prod x_i = (\sum \bar x_i)'$ biçiminde yazılır (ekrandan, 00:40:00). Böylece $f = \sum(\sum \bar x_i)'$; içteki terimler NOR olur. Dıştaki toplamı NOR yapmak için önce $f'$ alınır, sonra çıkış bir NOR'la yeniden tümlenir.
  - Örnek: $f = ab + \bar a c = (\bar a + \bar b)' + (a + \bar c)'$; $f' = \left[(\bar a + \bar b)' + (a + \bar c)'\right]'$; çıkışa kısa devre edilmiş bir NOR eklenerek $f$ elde edilir (ekrandan, 00:45:00).
- B1: Toplamlar çarpımının NAND tasarımı
  - Bir toplam terimi $\sum x_i = (\prod \bar x_i)'$ biçimine getirilir; içteki terimler NAND olur. Dıştaki çarpım için önce $f'$ yazılır, sonra çıkış NAND'la tümlenir (ekrandan, 00:55:00).
  - Örnek: $f(a,b,c) = (a+b)(\bar a + c) = (\bar a\bar b)'\,(a\bar c)'$; $f' = \left[(\bar a\bar b)'(a\bar c)'\right]'$; çıkışa bir NAND daha eklenir. Toplam 7 NAND kullanıldı (ekrandan, 00:55:00).
- B2: Toplamlar çarpımının NOR tasarımı
  - $f' = \sum(\sum x_i)'$, buradan $f = \left[\sum(\sum x_i)'\right]'$: içteki toplamlar NOR, dıştaki işlem de NOR olur (ekrandan, 01:05:00).
  - Örnek: $f = (a+b)(\bar a + c)$ için $f = \left[(a+b)' + (\bar a + c)'\right]'$; devre $a+b$ için bir NOR, $\bar a$ için girişleri kısa devre edilmiş bir NOR, $\bar a + c$ için bir NOR ve çıkış NOR'undan oluşur (ekrandan, 01:05:00).
- Kombinezonsal devreler
  - Tanım: çıkışı yalnız o andaki girişlere bağlı olan, bilinen kapıların bir araya getirilmesiyle oluşan lojik devrelerdir. Hafıza elemanı yoktur; $t$ anındaki girişler $t$ anındaki çıkışı üretir (ekrandan, 01:20:00).
  - Bölümde görülecek devreler: yarı toplayıcı ve çıkarıcı, tam toplayıcı ve çıkarıcı, çoğullayıcı (multiplexer, seçici), dağıtıcı (demultiplexer), kod çözücü (decoder), kodlayıcı (encoder), ALU (aritmetik lojik birim), 7 bölmeli gösterge (seven segment display) ve çıkış bağlantı şekilleri.
- Kombinezonsal devre tasarım adımları (ekrandan, 01:25:00)
  - 1: Problemin sözle tanımı (kutunun ne yapacağı).
  - 2: Giriş ve çıkış değişkenlerinin sayısı ve adlandırılması ($x_1 \dots x_n$ girişler, $z_1 \dots z_m$ çıkışlar).
  - 3: Probleme ilişkin doğruluk tablosu.
  - 4: Her çıkışın lojik fonksiyonu ayrı ayrı yazılır ve indirgenir (Karnaugh haritası ya da Quine-McCluskey).
  - 5: Kullanılacak devre elemanları belirlenir; tek tip kapı isteniyorsa indirgenmiş fonksiyonlara NAND/NOR dönüşümleri uygulanır.
  - 6: Lojik devre şeması çizilir.
- Tasarım örnekleri
  - İki girişli bir çıkışlı devre: girişlerin ikisi de 0 ise çıkış 0, aksi halde 1. Karnaugh haritasından $z = x_1 + x_2$, yani tek bir OR kapısı (ekrandan, 01:30:00).
  - İki girişli bir çıkışlı devre: girişler eşitse çıkış 1, farklıysa 0. $z = \bar x_1\bar x_2 + x_1 x_2$; NOT, AND ve OR kapılarıyla ya da tek bir XNOR kapısıyla gerçeklenir (ekrandan, 01:35:00).
  - 2 bitlik genlik karşılaştırıcı (amplitude comparator): $A = a_1a_0$, $B = b_1b_0$; çıkışlar $Z_{A>B}$, $Z_{A=B}$, $Z_{A<B}$ ve her girişte bunlardan yalnız biri 1'dir (ekrandan, 01:35:00 ve 01:40:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Tek tür kapı kullanmanın çip sayısını azaltması
  - B1 örneğinde devre 7 NAND ile kuruldu. Aynı ifade NOT, OR ve AND ile kurulsaydı daha az kapı ama 3 farklı kapı türü, yani 3 ayrı çip gerekecekti; bir çipte 8 NAND bulunuyorsa 7 NAND'lı devre tek çiple yapılır.
- Bütün dönüşümlerin De Morgan ve çift tümlemeye dayanması
  - Hoca, dört tasarımda da yapılan işin yalnız De Morgan kuralını ve çift tümlemeyi uygulamak olduğunu, başka bir şey gerekmediğini vurguladı.
- Neden önce $f'$ hesaplanıyor
  - A2 ve B1'de dıştaki işlemi istenen kapı biçimine ($(x+y)'$ ya da $(xy)'$) getirmek için önce $f'$ gerçeklenir; bir fonksiyonun çıkışını tümlemek kolay olduğundan sonda girişleri kısa devre edilmiş bir kapıyla $f$'e dönülür.
- Karşılaştırıcı devresini simülatörde kurma önerisi
  - Hoca, karşılaştırıcının iç yapısının karmaşık olduğunu, devreyi bir lojik simülatörde kurup girişleri değiştirerek çıkışları gözlemenin el alışkanlığı için yararlı olduğunu söyledi.

## Kısa Tekrar Notları

- $(a\cdot a)' = a'$ ve $(a+a)' = a'$: NAND/NOR girişlerini kısa devre etmek NOT verir.
- AND $= $ NAND + NOT(NAND) $= $ NOR($\bar a$, $\bar b$); OR $= $ NOR + NOT(NOR) $= $ NAND($\bar a$, $\bar b$).
- A1: $f = \left(\prod(\prod x_i)'\right)'$ (iki seviye NAND).
- A2: $\prod x_i = (\sum\bar x_i)'$; $f' = \left[\sum(\sum\bar x_i)'\right]'$, çıkışta NOR ile tümleme.
- B1: $\sum x_i = (\prod\bar x_i)'$; $f' = \left[\prod(\prod\bar x_i)'\right]'$, çıkışta NAND ile tümleme.
- B2: $f = \left[\sum(\sum x_i)'\right]'$ (iki seviye NOR).
- $ab + \bar a c = \left((ab)'(\bar a c)'\right)'$ (4 NAND).
- $(a+b)(\bar a + c) = \left[(a+b)' + (\bar a + c)'\right]'$ (4 NOR).
- Kombinezonsal devre: hafızasız, çıkış yalnız anlık girişlere bağlı.
- Tasarım: tanım, giriş/çıkış sayısı, doğruluk tablosu, her çıkış için indirgeme, eleman seçimi/dönüşüm, şema.
- Eşitlik devresi: $\bar x_1\bar x_2 + x_1x_2$ = XNOR.
- 2 bitlik karşılaştırıcı:
  - $Z_{A>B} = a_1\bar b_1 + a_0\bar b_1\bar b_0 + a_1a_0\bar b_0$
  - $Z_{A=B} = \bar a_1\bar a_0\bar b_1\bar b_0 + \bar a_1a_0\bar b_1b_0 + a_1a_0b_1b_0 + a_1\bar a_0b_1\bar b_0$
  - $Z_{A<B} = \bar a_1b_1 + \bar a_1\bar a_0b_0 + \bar a_0b_1b_0$

## Detaylı Açıklamalar

- Türetilmiş kapılar ve maliyet
  - Ders bir önceki haftada işlenen indirgemenin devamı olarak başlar. Bir devre farklı kapı türleriyle kurulduğunda her tür için ayrı bir çip gerekir ve çiplerdeki kapıların çoğu boşta kalır. Aynı devre yalnız NAND ya da yalnız NOR ile kurulursa tek bir çipteki kapıların hepsi kullanılabilir. NAND ve NOR'un yapımı da AND ve OR'a göre daha ucuzdur. Bu yüzden önce temel kapıların (NOT, AND, OR) NAND ve NOR ile nasıl yapılacağı, sonra da indirgenmiş bir fonksiyonun tamamının tek tür kapıyla nasıl gerçekleneceği gösterildi.
  - NOT için girişler birbirine bağlanır: NAND'de $(a\cdot a)' = a'$, NOR'da $(a + a)' = a'$. Hoca bunu, çipte boşta kalan bir NOR ya da NAND kapısının bacaklarını kısa devre edip ihtiyaç duyulan bir NOT kapısı olarak kullanma örneğiyle açıkladı.
  - AND için iki yol vardır. Birincisi $ab = ((ab)')'$: bir NAND $(ab)'$ üretir, ardından girişleri kısa devre edilmiş ikinci bir NAND bunu tümler. İkincisi De Morgan ile $ab = (a' + b')'$: $a'$ ve $b'$ girişleri kısa devre edilmiş iki NOR'la elde edilir, bunlar üçüncü bir NOR'a verilir. İki devre de aynı çıkışı verir; tasarımcı elindeki kapı türüne göre seçer.
  - OR için de aynı mantık geçerlidir: $a + b = ((a+b)')'$ iki NOR ile, $a + b = (a'b')'$ ise üç NAND ile kurulur.
- Dört tek tür kapı tasarımı
  - A1 (çarpımlar toplamı, NAND): $f = \sum\prod x_i$ ifadesinin iki kez tümleyeni alınır ve içteki tümleme De Morgan ile dağıtılır. Toplam çarpıma, her çarpım terimi de NAND'e dönüşür: $f = \left(\prod(\prod x_i)'\right)'$. Hoca bunu $(ab + cd)' = (ab)'(cd)'$ örneğiyle gösterdi (ekrandan, 00:30:00).
  - Örnek fonksiyon $f = \bar a\bar b c + \bar a b c + a b\bar c + abc$ önce indirgendi. 3 değişkenli Karnaugh haritasında ($a$ satır, $bc$ sütun: 00, 01, 11, 10) $a=0$ satırında $bc = 01, 11$; $a = 1$ satırında $bc = 11, 10$ hücreleri 1'dir. İki ikili grup $\bar a c$ ve $ab$ verir: $f = ab + \bar a c$ (ekrandan, 00:35:00). NAND gerçeklemesi: $a,b \to$ NAND; $a \to$ kısa devre NAND $\to \bar a$; $\bar a, c \to$ NAND; iki çıkış son bir NAND'e girer (ekrandan, 00:40:00).
  - A2 (çarpımlar toplamı, NOR): bir çarpım terimi $\prod x_i = (\sum \bar x_i)'$ olarak yazılır; örneğin $ab = (\bar a + \bar b)'$. Böylece $f = \sum (\sum\bar x_i)'$ olur ve her terim bir NOR'dur. Dıştaki toplamın da NOR olması için $f' = \left[\sum(\sum\bar x_i)'\right]'$ gerçeklenir, sonra çıkış girişleri kısa devre edilmiş bir NOR'la tümlenir. Aynı örnek için $f = (\bar a + \bar b)' + (a + \bar c)'$ ve $f' = \left[(\bar a + \bar b)' + (a + \bar c)'\right]'$ yazıldı (ekrandan, 00:45:00). Devrede $\bar a$, $\bar b$, $\bar c$ kısa devre NOR'larla üretilir, $(\bar a + \bar b)'$ ve $(a + \bar c)'$ birer NOR'la, $f'$ bir NOR'la ve $f$ son bir NOR'la elde edilir.
  - B1 (toplamlar çarpımı, NAND): bir toplam terimi $\sum x_i = (\prod \bar x_i)'$ olarak yazılır; örneğin $a + b = (\bar a\bar b)'$. İçteki terimler NAND'dir; dıştaki çarpım için $f'$ alınır ve çıkış bir NAND'le tümlenir. Örnek $f(a,b,c) = (a+b)(\bar a + c)$ için $f = (\bar a\bar b)'(a\bar c)'$, $f' = \left[(\bar a\bar b)'(a\bar c)'\right]'$ (ekrandan, 00:55:00). $\bar a$, $\bar b$, $\bar c$ için 3, iki terim için 2, $f'$ için 1 ve çıkış tümlemesi için 1 olmak üzere 7 NAND kullanılır.
  - B2 (toplamlar çarpımı, NOR): $f = \prod\sum x_i$ için $f' = \sum(\sum x_i)'$ ve $f = \left[\sum(\sum x_i)'\right]'$ olur; hem içteki hem dıştaki işlem NOR'dur. Aynı örnekte $f = \left[(a+b)' + (\bar a + c)'\right]'$ (ekrandan, 01:05:00): $a, b \to$ NOR; $a \to$ kısa devre NOR $\to \bar a$; $\bar a, c \to$ NOR; iki çıkış son bir NOR'a girer.
  - Bütün sonuçlar python ile doğruluk tablosu üzerinden denetlendi; dönüştürülmüş devreler özgün fonksiyonla bütün girişlerde aynı çıkışı verir.
- Kombinezonsal devre tasarımı
  - Kombinezonsal devre $x_1,\dots,x_n$ girişli, $z_1,\dots,z_m$ çıkışlı bir kutu olarak düşünülür; çıkış yalnız o anki girişlere bağlıdır, hafıza yoktur. Tasarım altı adımda yapılır: sözel tanım, giriş/çıkış sayısı, doğruluk tablosu, her çıkışın ayrı fonksiyon olarak indirgenmesi, kullanılacak kapı türünün seçimi ve gerekiyorsa NAND/NOR dönüşümü, şemanın çizilmesi.
  - İlk örnekte doğruluk tablosu $z = 0, 1, 1, 1$ çıkar; Karnaugh haritasındaki iki grup $x_1$ ve $x_2$'yi verir, $z = x_1 + x_2$ tek bir OR kapısıdır. İkinci örnekte (girişler eşitse 1) $z = \bar x_1\bar x_2 + x_1x_2$ bulunur; bu ifade iki NOT, iki AND ve bir OR ile ya da tek bir XNOR ile kurulabilir.
  - 2 bitlik genlik karşılaştırıcıda doğruluk tablosu 16 satırdır ve $A$'nın 0, 1, 2, 3 değerlerine göre dört bloğa ayrılarak doldurulur. Her çıkış için ayrı bir 4 değişkenli Karnaugh haritası çizilir. $Z_{A>B}$ ve $Z_{A<B}$ için 6'şar adet 1 vardır ve üçer terimle örtülür. $Z_{A=B}$ haritasında 1'ler köşegen üzerindedir, hiçbiri komşu değildir; bu yüzden fonksiyon dört adet dört girişli AND teriminin toplamıdır (ekrandan, 01:45:00). Sonuçta ortaya çıkan devre, girişlerin tümleyenleri, iki, üç ve dört girişli AND kapıları ve OR kapılarından oluşan oldukça büyük bir yapıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
