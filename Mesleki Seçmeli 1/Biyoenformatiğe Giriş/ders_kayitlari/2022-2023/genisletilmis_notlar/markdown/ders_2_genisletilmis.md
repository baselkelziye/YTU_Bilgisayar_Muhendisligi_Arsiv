# Ders 2 Genişletilmiş Notu: Sayısal Veri Temsili ve Moleküler Biyolojinin Temelleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Analogdan Sayısala Dönüşüm
- 2. Sayısal Veri Birimleri ve Ölçüler
- 3. Veri Türleri ve Basamaklı Sayı Sistemi
- 4. Tamsayıların Temsili
- 5. Kayan Nokta Sayılar
- 6. Niteliklerin Kodlanması ve Mantık İşlemleri
- 7. Biyomedikal Verinin Doğası ve Temsili
- 8. Üst Veri (Metadata)
- 9. Hücreler ve Kromozomlar
- 10. DNA, Nükleotitler ve Genetik Kod
- 11. Amino Asitler ve Proteinler
- 12. RNA, Merkezi Dogma ve Temel Tanımlar
- 13. Merkezi Dogmanın Hesaplamalı Modeli
- Örnek Sorular

## 1. Analogdan Sayısala Dönüşüm

Hoca, önceki derste başlanan temel kavramlara kaldığı yerden devam etti. Bilgisayarlar sayısal aygıtlardır; doğadaki işaretlerin çoğu ise sürekli, yani analogdur. Bir analog işaret ölçülürken zamanlamadaki belirsizlik ve ölçüm süresindeki sınırlamalar ortaya çıkar. Bunlar sistemin güvenilirliğini etkiler.

Sürekli analog işaretin aksine sayısal işaret örneklenmiş bir işarettir ve sonlu bir bellek alanında saklanabilir. Analog işareti sayısal veriye çeviren işleme analogdan sayısala dönüşüm (analog-to-digital conversion, ADC) denir.

### 1.1 ADC'nin Dört Adımı

ADC bir analog işareti sayısallaştırmak için dört adımdan oluşur (ekrandan, 00:10:00):

1. Süzme (filtering)
2. Örnekleme (sampling)
3. Nicemleme (quantization)
4. İkili kodlama (binary encoding)

Analog işaret, sayısallaştırma uygulanmadan önce süzülmelidir. Örnekleme genellikle eşit zaman aralıklarıyla yapılır. Burada iyi bilinen örnekleme kuramı devreye girer: örnekleme frekansı, işaretin içerdiği en yüksek frekans bileşeninin en az iki katı olmalıdır. Hoca örnekleme türlerinin ayrıntısına girmedi.

### 1.2 Nicemleme ve Kodlama

Örneklemeden sonra genlik eksenini düzeylere bölmek gerekir; buna nicemleme denir. Slaytta düzeyler $0, d, 2d, 3d, 4d, \dots$ olarak gösterildi; $d$ düzeyler arasındaki aralıktır. Her örnek bir düzeye yerleştirilir ve böylece nicemlenmiş kodlar elde edilir. <!-- BELİRSİZ: 00:12:43 civarında altyazıda nicemlenmiş kodlar "2, 5, 7, 7, 6, 2, 1, 2, 2" diye geçiyor ve hocanın "genelde bir üst tamsayıya yuvarlanır" dediği anlaşılıyor; ilgili slayt karelerde görünmüyor, değerler doğrulanamadı. -->

Gerçek değer ile atanan düzey arasındaki fark nicemleme hatasıdır (normalize hata). Bir işaret nicemlendiğinde mutlaka bir hata eklenmiş olur (ekrandan, 00:15:00).

Son adım ikili kodlamadır. Örnekte 8 düzey vardır; 8 düzeyi ikili olarak göstermek için 3 bit gerekir. Gereken bit sayısı düzey sayısının 2 tabanında logaritmasıdır: $\log_2 8 = 3$.

Hocanın özetiyle, sürekli bir işaret (örneğin konuşma sesi) sonsuz miktarda bilgi taşır; örnekleme ve nicemleme ile bu işaret onu temsil eden sonlu sayıda örneğe dönüştürülür. Sayısal veri, bilgi ya da işaret bu süreçle elde edilir.

### 1.3 ADC Çözünürlüğü Örneği

Sürekli bir işareti sayısal işarete çeviren elektronik aygıta analogdan sayısala dönüştürücü denir. Girişi sürekli bir işaret, çıkışı $n$ bitlik sayısal veridir. Hoca 12 bitlik bir ADC örneği verdi: giriş aralığı 0-10 V ise ADC'nin analog volt cinsinden doğruluğu nedir? Doğruluk burada çıkışta değişikliğe yol açan en küçük giriş gerilimi değişimidir.

- Aralık: $V_{max} - V_{min} = 10 - 0 = 10$ V.
- Düzey sayısı: $2^{\text{bit sayısı}} = 2^{12} = 4096$.
- Doğruluk: $\dfrac{10}{4096} \approx 0{,}0024$ V $= 2{,}4$ mV.

Yani girişteki yaklaşık 2,4 mV'lik değişim, dönüştürücünün çıkışında bir değişiklik yaratır. (Hesap python ile doğrulandı: $10/4096 = 0{,}00244$.)

### 1.4 Ders Kapsamı Dışında Bırakılanlar

Aşırı örnekleme, düzensiz örnekleme, doğrusal ve logaritmik örnekleme, örtüşme (aliasing), örtüşme önleyici süzgeç ve görüntü önleyici süzgeç gibi kavramlar yalnız adıyla anıldı. ADC adımları bant sınırlama, örnekleme, nicemleme ve kodlama; sayısaldan analoğa dönüşüm adımları ise örnekle-tut, görüntü reddetme ve süzme olarak sayıldı.

## 2. Sayısal Veri Birimleri ve Ölçüler

### 2.1 Bit, Nibble, Byte, Word

A/D dönüşümünün son ürünü sayısal veridir ve şu birimlerle ifade edilir (ekrandan, 00:20:00):

- Bit: en küçük sayısal bilgi, ikili 1 ya da 0.
- Nibble: 4 bit.
- Byte: 8 bit, 2 nibble.
- Word: 16 bit, 2 byte, 4 nibble.

Bu alanda sık kullanılan terimler: tamsayı, işaretli tamsayı, uzun tamsayı, 2'ye tümleyen, onaltılık, sekizlik ve kayan nokta.

Hoca, bilgisayarların sayısal aygıtlar olduğunu ve sayısal sistemde her şeyin temsil edilmesi gerektiğini hatırlattı. Sonsuz miktarda bilgi tutulamaz. Temsil edilecek iki tür şey vardır: nicelikler (sayılar) ve nitelikler (karakter gibi nitel veriler).

### 2.2 10'un ve 2'nin Kuvvetleri

İnsanlar 10 tabanında, bilgisayarlar 2 tabanında matematik kullanır. Kilo, mega, giga gibi kısaltmalar yaygın kullanılır, ama bir ölçüde kilo tam olarak $10^3$, başka bir ölçüde $2^{10}$ anlamına gelir. İkisi aynı değildir (ekrandan, 00:25:00):

| Önek | Söylenişi | 10'un kuvveti | 2'nin kuvveti |
|---|---|---|---|
| Kilo (K) | 1 bin | $10^3$ | $2^{10}$ |
| Mega (M) | 1 milyon | $10^6$ | $2^{20}$ |
| Giga (G) | 1 milyar | $10^9$ | $2^{30}$ |
| Tera (T) | 1 trilyon | $10^{12}$ | $2^{40}$ |
| Peta (P) | 1 katrilyon | $10^{15}$ | $2^{50}$ |

Slayttaki ana cümle şudur: bir ölçünün 10'un mu yoksa 2'nin mi kuvvetine karşılık geldiği, neyin ölçüldüğüne bağlıdır. Hesaplama sistemlerinde bellek kapasitesi 2'nin kuvvetleriyle; hız gibi diğer başarım ölçüleri 10'un kuvvetleriyle ifade edilir.

Hoca her yıl sorduğu "uç" bir soruyu sordu: Bir hesaplama sisteminde veri yolu aktarım hızı saniyede 1 kilobyte ise kaç byte'tan söz ediyoruz? Bir öğrenci 1024 byte dedi, başka bir öğrenci de katıldı. Hocanın cevabı: Yanlış, çünkü burada ölçülen hızdır. Saniyede 1 kilobyte aktarım, saniyede 1000 byte aktarım demektir; kapasiteden değil hızdan söz ediyoruz.

> **Hocanın vurguladığı:** Bunlar karıştırılmamalıdır; her zaman hatırlanması gereken önemli bir noktadır ve hep yapılan hatalardan biridir.

Hoca uzunluk gibi ölçülerin de (örneğin 1 µm boyutunda bir transistör) 10'un kuvvetleriyle ifade edildiğini ekledi.

## 3. Veri Türleri ve Basamaklı Sayı Sistemi

### 3.1 Nicel ve Nitel Veri

Burada "veri türü" ile bir programlama dilindeki türler değil, bir hesaplama sistemindeki temel veri türleri kastedilmektedir. Veri türleri nicelikleri ve nitelikleri temsil etmek için kullanılır. Sayılar, metin, görüntü, ses ya da mantıksal komutlar gibi birçok veri türü vardır ve hepsi ikili olarak tutulur; bunda bir tartışma yoktur.

Ancak aralarında bir fark vardır: sayılar sadece sayıdır, yani bir nicelik temsil eder. Metin, görüntü, ses ve mantıksal komutlar ise koddur; bir nicelik değil belirli bir nitelik temsil eder. Bu yüzden nicel (quantitative) ve nitel (qualitative) veri türlerinden söz edilir.

### 3.2 Basamaklı (Ağırlıklı) Sayı Sistemi

Hoca, Türkçede "basamaklı sayı sistemi" denen yapının İngilizcede "weighted number system" olarak adlandırıldığını belirtti. Bu sistemde bir kesir noktası ve onun solunda ve sağında basamaklar ($a_0, a_1, \dots$) vardır. Onluk sistemde basamaklar 0-9 arasındaki sembollerdir ve her basamağın bir ağırlığı vardır: birler, onlar, yüzler, binler; noktanın sağında onda birler, yüzde birler.

Örneğin $3546$ sayısı "6 tane bir, 4 tane on, 5 tane yüz, 3 tane bin" demektir. <!-- BELİRSİZ: Altyazıda "altı tane bir, dört tane on, beş tane yüz, üç tane bin" deniyor; slayttaki sayı karede görünmüyor, 3546 bu sözlü ifadeden kuruldu. -->

Bilgisayar da aynı sistemi kullanır, yalnızca tabanı 2'dir: basamaklar birler, ikiler, dörtler, sekizler diye gider.

> **Hocanın vurguladığı:** Biz ve bilgisayarlar tam olarak aynı temsili kullanırız. Her zaman hatırlanması gereken ilk şey budur.

## 4. Tamsayıların Temsili

### 4.1 İşaretsiz Tamsayılar

Hesaplama sistemindeki ilk veri türü tamsayıdır, çünkü bellek adresleri tamsayılarla temsil edilir. Hoca bellek adresinin ne tür bir tamsayı olduğunu sordu; bir öğrencinin "onaltılık" cevabına karşı hoca, onaltılık gösterimin yalnızca insanların okuması için kullanıldığını, bilgisayarda her şeyin ikili olduğunu söyledi. Doğru cevap: bellek adresi işaretsiz (unsigned) tamsayıdır.

$n$ bitlik adres yolu olan bir işlemcinin adresleyebileceği en büyük bellek $2^n$'dir. En küçük adres $0$, en büyük adres $2^n - 1$'dir. Bu, işaretsiz tamsayının aralığıdır (ekrandan, 00:35:00 slayt başlığı). C'de bir değişken işaretsiz tamsayı olarak tanımlanırsa aralığı da budur.

### 4.2 İşaretli Tamsayılar: 2'ye Tümleyen

Pozitif ve negatif tamsayılar için bilgisayar 2'ye tümleyen (two's complement) sistemini kullanır (ekrandan, 00:45:00):

- Dönüşüm: $a$'yı $-a$'ya çevirmek için $a$'nın bütün bitleri ters çevrilir ve sonuca 1 eklenir.
- Aralık: $-2^{N-1} \le i \le 2^{N-1} - 1$.

Slayttaki 5 bitlik tablo:

| Ondalık | 2'ye tümleyen |
|---|---|
| $-16$ | `10000` |
| ... | ... |
| $-3$ | `11101` |
| $-2$ | `11110` |
| $-1$ | `11111` |
| $0$ | `00000` |
| $+1$ | `00001` |
| $+2$ | `00010` |
| $+3$ | `00011` |
| ... | ... |
| $+15$ | `01111` |

Hoca bu sistemde negatif sayıların nasıl temsil edildiğini sordu. Bir öğrenci en anlamlı bitin 1 olmasıyla sayının negatif olduğunu söyledi. Hoca "sayının geri kalanı nasıl hesaplanır?" diye sorup tahtaya `1011` yazdı ve ondalık karşılığını istedi. Cevap $-5$'tir. Hoca hesabı ağırlıklarla yaptı:

$$1011_2 = 1\cdot(-8) + 0\cdot 4 + 1\cdot 2 + 1\cdot 1 = -5$$

Buradaki mantık, 2'ye tümleyenin de bir basamaklı (ağırlıklı) sayı sistemi olmasıdır; tek fark en anlamlı bitin ağırlığının negatif olmasıdır. Aynı bit dizisi "ilk bit işaret, gerisi büyüklük" diye bir kod gibi okunsaydı $-3$ çıkardı. 2'ye tümleyende bu bir kod değil, tamamen matematiksel bir ağırlıktır; toplam $-5$'i verir.

> **Hocanın vurguladığı:** İkisi arasında temel bir fark vardır. Hesaplama sistemi bütün aritmetik işlemleri bu sayı sisteminde yapar. Bu konular biyoenformatikle doğrudan ilgili olmasa da çok temel olduğu için üzerinde ısrarla durdu.

> **Ek bilgi (derste anlatılmadı):** Ters çevir-1 ekle kuralı ağırlıklı yorumla tutarlıdır: $5 = 0101$ → ters çevrilince $1010$ → 1 eklenince $1011$, yani yukarıdaki $-5$. Ters çevirme işlemi bir sayıyı $-(a+1)$'e götürür, 1 eklemek de $-a$'yı verir.

### 4.3 Tamsayı Gösteriminin Sınırları

Gerçek hayatta işaretli ya da işaretsiz tamsayıların aralığı çok sınırlı ve çözünürlüğü çok düşüktür (ekrandan, 00:50:00 slayt başlığı). Oysa çok küçük ve çok büyük sayılarla sık çalışılır. Hesaplama sisteminde kaynaklar sınırlı olduğundan, rasyonel sayıları temsil etmek için de belirli bir biçime ihtiyaç vardır. Bunun için kayan nokta sayı sistemi kullanılır.

## 5. Kayan Nokta Sayılar

### 5.1 Tek Duyarlık (float)

Hoca, C'de `float` türünde tanımlanan bir değişkenin her öğesinin bellekte kaç byte kapladığını sordu. Cevap 4 byte'tır (32 bit). Kayan nokta türlerindeki temel fikir, sayıyı üstel biçimde (mühendislik biçimi olarak da bilinir) göstermektir.

IEEE 754 kayan nokta standardında 32 bitlik biçim şöyledir:

- En soldaki (en anlamlı) bit işarettir: sayı pozitifse $s = 0$, negatifse $s = 1$.
- Sonraki 8 bit kaydırılmış (biased) üstür.
- Kalan 23 bit kesir kısmıdır (mantis).

Temsil edilen değer:

$$N = (-1)^s \times 1.\text{kesir} \times 2^{(\text{kaydırılmış üs} - 127)}$$

### 5.2 Örnek: 25,75'in Kayan Nokta Gösterimi

Klavyeden 25,75 girildiğinde bilgisayarın bunu nasıl sakladığı soruldu (ekrandan, 00:55:00):

1. Sayı ikili sisteme çevrilir: $25{,}75 \Rightarrow 00011001{,}110$. ($25 = 11001_2$, $0{,}75 = 0{,}11_2$; ara adım eklendi.)
2. Normalize edilir: $1{,}1001110 \times 2^4$. Nokta 4 basamak sola kaydırıldığı için sayı $2^4$ ile çarpılır; taban 2 olduğundan.
3. İşaret: sayı pozitif, $s = 0$.
4. Kesir: normalize sayının noktadan sonraki kısmı `1001110`, 23 bite 0'larla tamamlanır. Baştaki 1 saklanmaz.
5. Üs: $4 + 127 = 131 = 10000011_2$.

Kaydırma miktarı 8 bitlik üs alanı için $2^{8-1} - 1 = 2^7 - 1 = 127$'dir. Hocaya göre bu kaydırmanın amacı negatif üsleri sıfırın üstüne taşımaktır.

Sonuç: $0\ \ 10000011\ \ 10011100000000000000000$. Ders sonrası python ile denetlendi; onaltılık karşılığı `41CE0000`'dır.

Hoca bu gösterimin başka özellikleri de olduğunu ama onları atladığını söyledi.

### 5.3 Çift Duyarlık (double) ve Daha Uzun Biçimler

`float` yetmezse aynı biçimin farklı bit sayılı hali olan `double` kullanılır (ekrandan, 01:00:00):

- İşaret biti: 1
- Kaydırılmış üs: 11 bit; kaydırma miktarı $2^{10} - 1 = 1023$
- Kesir: 52 bit
- Toplam 64 bit, yani 8 byte

$$N = (-1)^s \times 1.\text{kesir} \times 2^{(\text{kaydırılmış üs} - 1023)}$$

Bu da yetmezse 80 bitlik ve 128 bitlik genişletilmiş biçimler vardır.

Kayan nokta aritmetiği tamsayı aritmetiğinden farklı bir yaklaşım ister ve daha zordur. Hocaya göre örneğin kayan nokta toplaması, kayan nokta çarpmasından çok daha karmaşıktır. Bu ayrıntılar ders kapsamı dışındadır.

## 6. Niteliklerin Kodlanması ve Mantık İşlemleri

### 6.1 Nitelikleri Kodlamak

Renk, ses, karakter, dizgi ve komut gibi nitelikleri temsil etmek için kodlama kullanılır; bunlar da sonuçta ikili sayılardır. Hoca renk örneğini verdi: 8 rengi temsil etmek için kaç bit gerekir? Cevap 3 bittir, çünkü 3 bitle 8 farklı ikili sayı yazılabilir. 16 renk için bir bit daha (4 bit) gerekir; milyonlarca renk için daha fazla bit kullanılır. Bu, nitel bir verinin, yani rengin kodlanmasına örnektir. Ses ve diğer nitelikler için de benzer kavramlar kullanılır.

### 6.2 Dönüşüm mü, Kodlama mı?

57 sayısının ikili karşılığı yazılırsa bu bir sayı dönüşümüdür. Ama 5 ve 7 ayrı ayrı ikili kodlanmış onluk (BCD) karşılıklarıyla yazılırsa bu bir sayı temsili değil, bir koddur. Hata bulma ve düzeltme kodları ile ASCII karakter kodları da ikili sayılarla yazılan kodlardır.

> **Hocanın vurguladığı:** Son bir uyarı olarak, bir gösterimin dönüşüm mü yoksa kodlama mı olduğunun farkında olunmalıdır.

### 6.3 Temel Mantık İşlemleri

Temel mantık işlemleri (AND, OR, NOT, XOR vb.) kapılarla gerçeklenir. Sayısal bilgisayar sistemi ikili anahtarların birleşimidir; bu anahtarlar mantık kapılarıyla, kapılar da CMOS ya da TTL transistörlerle yapılır. Bu ayrıntılar ders kapsamı dışındadır.

Slaytta XOR ve XNOR doğruluk tabloları gösterildi (ekrandan, 01:05:00):

| A | B | $A \oplus B$ | $(A \oplus B)'$ |
|---|---|---|---|
| 0 | 0 | 0 | 1 |
| 0 | 1 | 1 | 0 |
| 1 | 0 | 1 | 0 |
| 1 | 1 | 0 | 1 |

XOR (dışlayan VEYA): A ya da B 1'dir, ama ikisi birden değil. $A \oplus B = A\cdot B' + A'\cdot B$.

## 7. Biyomedikal Verinin Doğası ve Temsili

Aradan sonra yeni slayt grubuna geçildi. Bu slayt grubunun öğrenme hedefleri şunlardır: moleküler biyolojinin temellerini anlamak, moleküler veritabanı türlerini tanımlamak, erişim numaralarını (accession number) ve bazı dizi tanımlayıcılarının önemini tanımlamak, temel genom tarayıcılarını tanıtıp bir genomik bölgenin özelliklerini incelemek için kullanmak.

### 7.1 Biyolojik Veri Türleri

Tipik bir biyoloji ya da tıp kitabında ve ilgili dergilerde fotoğraf, diyagram, çizim, kimyasal formül ve çok sayıda betimleme gibi farklı veri türleri görülür. Hoca, bu farklı veri türlerinin temsilinin dersin ilk yarısında anlatılan nicelik ve nitelik temsiliyle doğrudan ilgili olduğunu vurguladı. Bu kavramlar hücre, organ, doku, sıvı ya da bunlarda bulunan kimyasal bileşikler gibi biyolojik varlıkların özellikleri, aralarındaki ilişkiler ve özellikleri hakkındadır.

Biyolojik nesnelerin bazı özellikleri (ekrandan, 01:30:00):

- Sayısal (nicelik):
  - kandaki belirli kimyasalların derişimi,
  - bir tümörün boyutu,
  - bir hücre, doku, organ ya da vücut sıvısındaki pH (asitlik derecesi).
- Yalnız adlandırılabilen, sayılamayan nitelikler:
  - gen transkripsiyonuyla üretilen protein(ler),
  - bir organizmada bir organın varlığı ya da yokluğu.

Tümör boyutu için hoca, bir görüntüleme yöntemiyle ilgili dokunun görüntülendiğini ve radyolog ya da görüntüleme uzmanlarının bu görüntüden tümörün boyutunu kestirdiğini anlattı.

pH için altyazıda "7 asidik özellikleri, 7'den küçük bazik özellikleri temsil eder" gibi bir ifade geçiyor.

> **Ders sonrası not:** Altyazıya göre hoca pH 7 ve altını asidik/bazik diye eşleştirdi; doğrusu, pH 7 nötr, 7'den küçük asidik, 7'den büyük baziktir. Ses kaydındaki ifade büyük olasılıkla bozuk aktarılmıştır.

### 7.2 Nominal ve Ordinal Nitel Veri

Hoca iki nitel veri türünün adını sordu. Cevap: nominal ve ordinal. Ardından iyi bir sınav sorusu olabileceğini söylediği soruyu sordu: Bir organın varlığı ya da yokluğu bir değişkenle temsil edilirse, bu nitel değişken nominal midir, ordinal mi? Cevap nominaldir; değerler arasında sıra yoktur. Buna karşılık hafif, orta, ağır (mild, medium, severe) gibi bir derecelendirme ordinaldir, çünkü değerler arasında bir sıra vardır.

### 7.3 Nitel Veriyle Çalışmak

Nitel veriyle çalışmak için iki yol vardır: ya nitel veriye uygun bir algoritma bulunur ya da nitel veri nicel veriye dönüştürülür. Bunun için yöntemler vardır; hoca öğrencilerin bunları veri madenciliği gibi derslerde görmüş olabileceğini söyledi.

> **Hocanın vurguladığı:** Bu çok önemlidir. Projelerde emeğin büyük kısmı veri hazırlama ve veri temizlemeyle geçer; geri kalanı algoritmaların uygulanması ve sonuçların değerlendirilmesidir. Bu yüzden veri önemlidir.

## 8. Üst Veri (Metadata)

Hoca, filogenetik ağaçlar ve gen ifadesi gibi biyolojik bilgilerin betimlenmesinde üst verinin önemine değindi. İşaretleme dilleri (markup languages) zaten üst veri sayılır; içeriğe üst veri ve diğer yapısal ya da anlamsal özellikler için işaretler ekler.

Tanım ve örnekler (ekrandan, 01:40:00):

- Üst veri, verinin bir ya da daha fazla yönü hakkında bilgi veren veridir.
- Veri hakkındaki temel bilgileri özetlemek için kullanılır; bu da belirli bir veriyi izlemeyi ve onunla çalışmayı kolaylaştırır.
- Örnekler:
  - verinin oluşturulma yolu,
  - verinin amacı,
  - oluşturulma tarihi ve saati,
  - verinin oluşturucusu ya da yazarı,
  - verinin oluşturulduğu bilgisayar ağı konumu,
  - kullanılan standartlar,
  - dosya boyutu.

Slaytta üst veri için kaynak olarak NISO'nun "Understanding Metadata" belgesi gösterildi.

## 9. Hücreler ve Kromozomlar

İyi bir biyoenformatikçi olmak için genetik ya da moleküler biyoloji hakkında temel bilgi gerektiğinden, hoca moleküler biyolojiye genel bir bakışa geçti. Bazı kavramlar anlaşılmazsa endişelenmemeyi, kendisinin de hepsini anlamadığını söyledi.

### 9.1 Hücreler

Hücreler kromozomlar, DNA, RNA, amino asitler ve proteinlerden oluşur; genom, transkriptom ve proteom olarak bilinen süreçleri içerir. Slaytta tipik bir hayvan hücresi gösterildi; hoca bileşenleri tek tek anlatmadı, yalnızca hatırlatma amaçlı olduğunu söyledi. Hücre, bir doku ya da vücut oluşturan karmaşık bir yapıdır ve sıklıkla yaşamın yapı taşı diye anılır.

Sınıflandırma açısından çoğu bakteri gibi bazı organizmalar tek hücrelidir; insan gibi diğerleri çok hücrelidir ve çok farklı türde hücreler içerir. Hücre türleri (ekrandan, 01:45:00):

- yassı hücreler (squamous cells),
- epitel hücreleri,
- kas hücreleri,
- kan hücreleri: kırmızı ve beyaz hücreler.

Hoca bunların kategorik nitelikler (kategorik veri) olduğunu, ama sayısal değerlerle de ilişkili olduğunu vurguladı: kırmızı ve beyaz hücre kategorik değişkenlerdir, ama kırmızı hücrelerin sayısı sayılabilir; örneğin "11 kırmızı hücre" sayısal bir niceliktir.

### 9.2 Prokaryot ve Ökaryot Hücreler

Tek hücreli organizmaların hepsi prokaryot değildir. Ökaryot hücre, prokaryot hücreden yaklaşık 10 kat büyüktür. Ökaryotlarda kromozomal DNA'nın tamamı, sitoplazmadan bir zarla ayrılmış hücre çekirdeğinde saklanır. Mitokondri gibi bazı organeller de bir miktar DNA içerir.

### 9.3 Kromozomlar

Kromozomlar, hücrelerde bulunan DNA ve proteinlerden oluşan düzenli yapılardır. "Kromozom" sözcüğü Yunanca *chroma* (renk) ve *soma* (beden) sözcüklerinden gelir; bazı boyalarla çok güçlü boyanma özelliklerinden dolayı bu adı almıştır (ekrandan, 01:50:00). Hoca *chroma* sözcüğünün görüntü işleme ve görüntüleme sistemlerinde de kullanıldığını hatırlattı.

Bir kromozom, birçok gen, düzenleyici öğe ve başka nükleotit dizileri içeren tek parça bir DNA'dır. Kromozomlar ayrıca DNA'yı paketlemeye ve işlevlerini denetlemeye yarayan DNA'ya bağlı proteinler içerir. İnsanda 22 çift otozom ve 1 çift cinsiyet kromozomu vardır. Slaytta bazı bitkilerin ve canlıların kromozom sayıları gösterildi; hoca örneğin Japon balığının 100-104 kromozomu olduğunu, bunun insandan çok daha fazla olduğunu söyledi. <!-- BELİRSİZ: 01:52:14 civarında bitki kromozom sayıları sayılıyor, ancak altyazı bozuk ve tablo karelerde görünmüyor. -->

Son olarak bir kromozom resmi gösterildi: hücrenin içinde kromozomlar, kromozomun içinde de DNA vardır.

## 10. DNA, Nükleotitler ve Genetik Kod

### 10.1 DNA

DNA, deoksiribonükleik asidin kısaltmasıdır; bir nükleik asittir, yani kimyasal bir bileşiktir. DNA moleküllerinin ana görevi bilginin uzun süreli saklanmasıdır; DNA biyolojik varlığın bilgi saklama öğesidir. Bu DNA kodları transkripsiyon ve translasyon süreçleriyle bir protein sentezlemek ve sonunda hücreleri ve molekülleri oluşturmak için kullanılır.

Kimyasal olarak DNA, nükleotit adı verilen basit birimlerden oluşan iki uzun polimerden oluşur. Bu bilgi, proteinlerdeki amino asitlerin sırasını belirleyen genetik kodla okunur. Kod, DNA'nın parçalarının ilgili nükleik asit olan RNA'ya kopyalanmasıyla okunur; bu işleme transkripsiyon denir.

Ökaryot organizmalar DNA'yı hücre çekirdeğinde, prokaryotlar ise hücre sitoplazmasında saklar. Kromozomun içinde histon gibi kromatin proteinleri DNA'yı sıkıştırır ve düzenler; bu sıkı yapılar DNA ile diğer proteinler arasındaki etkileşimlere yön verir.

### 10.2 Nükleotitler

Dört farklı nükleotit vardır; bunlar kimyasal maddelerdir:

- Adenin (A)
- Sitozin (C)
- Guanin (G)
- Timin (T)

Nükleotitler üç birleşik yapıdan oluşan organik bileşiklerdir: azotlu baz, şeker ve fosfat grubu. En yaygın nükleotitler iki ana gruba ayrılır: A ve G pürinler, C ve T pirimidinlerdir. Şekerleri riboz ya da deoksiriboz olan nükleotitler RNA'nın ve DNA'nın yapı birimleridir.

### 10.3 Genetik Kod

Genetik kod, genetik malzemede (DNA ya da mRNA dizileri) kodlanmış bilginin canlı hücreler tarafından proteinlere çevrildiği kurallar kümesidir. Translasyonu ribozom yapar: amino asitleri mRNA'nın belirlediği sırayla bağlar; amino asitleri taşımak ve mRNA'yı üçer nükleotit okumak için tRNA moleküllerini kullanır (ekrandan, 02:00:00). Genetik kod bütün organizmalarda büyük ölçüde aynıdır ve 64 girdili basit bir tabloyla ifade edilebilir. Kod, kodon adı verilen nükleotit üçlülerinin, protein sentezinde sıradaki amino asidin hangisi olacağını nasıl belirlediğini tanımlar.

Hoca bu biyoloji ve biraz kimya arka planını, kullanılan veri türünü betimlemek için verdiğini açıkladı.

### 10.4 DNA Verisinin Bilgisayardaki Türü

Hoca şu soruyu sordu: DNA ve genetik kod dört maddeyle temsil ediliyorsa, DNA'yı ya da RNA'yı temsil eden veri dosyası ne tür veridir? Nicel mi, nitel mi? Bir öğrenci önce "ordinal" dedi; hoca önce nicel mi nitel mi olduğunun belirlenmesini istedi. Cevap nitel veridir. Peki bu, bilgisayar sisteminde hangi veri türüne karşılık gelir? Cevap: karakter (char) dizisi, bazen de dizgi (string).

Yani bütün bu kimyasal yapılar hesaplama sisteminde karakter dizileri olarak temsil edilir. Bu tür veriyi betimleyebilmek için moleküler biyolojiden geçmek gerekmiştir.

> **Hocanın vurguladığı:** Biyoenformatikteki problem buradan görülür: büyük olasılıkla bu karakterleri ve dizgileri işlemeye başlayacaksınız. Biyoenformatikte kullanılan veri türleri elbette bundan çok daha fazladır, ama başlangıç noktası budur.

### 10.5 Kodonlar, Başlama ve Durma Kodonları

Genetik kod slaytı (ekrandan, 02:10:00):

- 4 olası baz vardır (A, C, G, U).
- Üç nükleotidin her birleşimine kodon denir.
- $4^3 = 4 \times 4 \times 4 = 64$ olası kodon dizisi vardır.
- Her kodon bir amino aside karşılık gelmez:
  - Başlama kodonu: AUG
  - Durma kodonları: UAA, UAG, UGA
- Amino asitleri kodlayan 61 kodon vardır (AUG dahil).
  - 20 amino asit vardır; genetik kodda fazlalık (redundancy) vardır.
  - Amino asitlerin çoğu için aynı amino asidi temsil eden birkaç kodon vardır.

Hoca kimyadan kaç amino asit bilindiğini sordu; kuramsal olarak 64'e kadar olabilir, ama biyolojik olarak 20 amino asit vardır. Hoca başlama ve durma kodonlarını bir veri dosyasının başlangıç ve bitiş adresine benzetti: bir protein oluşturmak için bir başlama kodonu, ardından proteinin gövdesi (DNA bilgisinin tamamı) ve sonunda bir durma kodonu gerekir.

Ardından 20 amino asit, kısaltmaları ve karşılık gelen kodonlarıyla bir tabloda gösterildi: glisin, alanin, valin vb. Amino asitler belirli harflerle (G, A, V, ...) temsil edilir; genelde adlarının ilk harfiyle. Hoca biyoenformatikteki temel veri türlerinin ya DNA dizileri ya da amino asit dizileri olduğunu vurguladı.

## 11. Amino Asitler ve Proteinler

### 11.1 Amino Asitler

Amino asitler proteinlerin temel yapı birimleridir. Suya yatkınlık açısından farklı türleri vardır: hidrofilik amino asitler suda çözünür, hidrofobik olanlar çözünmez. Amino asitler kısa polimer zincirleri (peptitler) ya da daha uzun zincirler (polipeptitler ya da proteinler) oluşturur. Bu yapının haberci RNA (mRNA) şablonundan oluşturulması translasyon olarak bilinir ve protein biyosentezinin bir parçasıdır. Standart genetik kodla kodlanan 20 amino aside proteinojenik ya da standart amino asitler denir.

### 11.2 Proteinler

Proteinler moleküler makinenin temel bileşenleridir. Kaslarınızdaki proteinler (miyozin ve aktin) hareket etmenizi sağlar (ekrandan, 02:15:00).

Protein özellikleri; proteinin işlevi, onu kodlayan gen ve yokluğu ya da mutasyonuyla ilişkili hastalıklardır. Hocaya göre proteinler mutasyona uğradığında farklı bir yapı ortaya çıkar ve bu yapıya temelde kanser denir.

> **Ders sonrası not:** Hoca protein mutasyonundan doğan farklı yapının "temelde kanser" olduğunu söyledi; bu bir sadeleştirmedir. Mutasyonların çoğu büyük olasılıkla kansere yol açmaz; kanser, hücre büyümesini denetleyen genlerdeki belirli mutasyonların birikmesiyle ilişkilidir.

Proteinlerin hücre ve dokulardaki görevleri:

- Biyokimyasal tepkimeleri kolaylaştıran enzimler olarak görev yaparlar; enzimler biyokimyasal tepkimelerin katalizörleridir.
- Sinyal olarak diğer süreçleri düzenleyebilirler.
- Hücre ve doku yapılarının bileşenleridir.

Proteinler, doğrusal bir zincirde dizilmiş ve komşu amino asit kalıntılarının karboksil ve amino grupları arasındaki peptit bağlarıyla birleşmiş amino asitlerden oluşan büyük organik bileşiklerdir. Hocaya göre "protein" sözcüğü "birincil" anlamına gelen bir Yunanca sözcükten gelir, çünkü protein moleküler makinenin birincil ve temel yapısıdır. Bir proteindeki amino asit sırası bir gen tarafından tanımlanır ve genetik kodla kodlanır. Proteinler organizmaların vazgeçilmez parçalarıdır ve hücredeki her sürece katılırlar.

### 11.3 HIV Enfeksiyonu Örneği

Hoca HIV enfeksiyonunun nasıl gerçekleştiğini bir görselle anlattı:

1. Bir hücre HIV virüsüyle karşılaşır.
2. HIV insan hücresine girer.
3. Hücre, HIV'in genetik kodunu okur.
4. Hücre yeni HIV proteinleri üretir; bu proteinler HIV'i başka hücreleri enfekte etmeye hazırlar.
5. Böylece hücreye giren tek bir virüsten sizin hücreniz tarafından çok sayıda yeni virüs üretilir; yeni virüsler hücreden çıkıp başka hücreleri enfekte eder.

Bu süreci anlamak, yani genetik yapıyı, işlevleri, hücre ve protein üretimini anlamak için biyoenformatiğe ihtiyaç vardır. Bu, ilaç keşfi (drug discovery) olarak bilinen alandır; slaytta yapı tahmini ve karşılaştırmalı modelleme gibi kavramlar da anıldı. <!-- BELİRSİZ: 02:21-02:22 arası altyazı bozuk; ilaç keşfi slaytının ayrıntıları çıkarılamadı. -->

Hoca daha önce anlatılan tanımları kısaca hatırlattı: genomik bir organizmanın genomunun incelenmesidir; proteomik proteinlerin, özellikle yapı ve işlevlerinin büyük ölçekli incelenmesidir. Yapısal biyoenformatik, proteinler gibi biyolojik makromoleküllerin üç boyutlu yapısının analizi ve tahminiyle ilgilenen biyoenformatik dalıdır.

## 12. RNA, Merkezi Dogma ve Temel Tanımlar

### 12.1 RNA

RNA (ribonükleik asit) bir nükleik asittir: uzun bir nükleotit birimleri zinciridir ve her nükleotit azotlu bir baz, riboz şekeri ve bir fosfattan oluşur. RNA, DNA'ya çok benzer, ama birkaç önemli yapısal ayrıntıda farklıdır (ekrandan, 02:25:00):

- Hücrede RNA genelde tek iplikli, DNA ise genelde çift iplikli ve tümleyendir.
- RNA nükleotitleri riboz, DNA ise deoksiriboz (bir oksijen atomu eksik bir riboz türü) içerir.
- RNA'da DNA'daki timin yerine urasil bazı bulunur. DNA dizisindeki T, RNA'ya çevrildiğinde U olur.

RNA, DNA'dan RNA polimeraz adı verilen enzimlerle kopyalanır ve genelde başka enzimlerle işlenir. RNA protein sentezinin merkezindedir; protein sentezinde bir ara aşamadır.

### 12.2 mRNA, Ekzonlar, İntronlar ve Splicing

Farklı görevleri olan RNA türleri vardır. mRNA (messenger, haberci RNA) bilgiyi DNA'dan ribozom denen yapılara taşır. DNA'nın bir RNA molekülüne kopyalandığı sürece transkripsiyon denir.

Ökaryot genleri parçalardan birleştirilebilir. DNA dizisinde ekzonlar ve intronlar vardır: ekzonlar kodlayan, intronlar kodlamayan bölgelerdir. Haberci RNA işlenmesi sırasında kodlamayan bölgeler çıkarılır; bu sürece splicing (kırpılma ve birleştirme) denir.

> **Hocanın vurguladığı:** Biyoenformatikte splice bölgeleri önemlidir; bir DNA'nın ne yaptığını anlayabilmek için splice bölgelerini belirlemek gerekir.

Slayttaki örnekte DNA'da ekzonlar mavi, intronlar turuncu gösterildi. Splicing süreci turuncu bölgeleri çıkarır ve mavi bölgeleri birleştirerek haberci RNA'yı oluşturur. İşlenmiş mRNA daha sonra protein dizisine çevrilebilir.

### 12.3 tRNA ve Translasyon

Bir başka RNA türü tRNA'dır (transfer, taşıyıcı RNA). Hocanın sözlü ifadesine göre 72-95 nükleotit içeren küçük bir RNA'dır. Translasyon sırasında belirli bir amino asidi, protein sentezinin gerçekleştiği ribozomdaki büyüyen polipeptit zincirine taşır. İyi tanımlanmış üç boyutlu bir yapısı vardır ve proteinlerin oluşumu için kritik bir süreçtir. Hoca bütün bunların kimyasal olarak gerçekleştiğini, derste ise kodla modelleneceğini belirtti.

Translasyon, işlenmiş mRNA'nın nükleotit dizisinin, ribozomlar ve tRNA yardımıyla amino asitleri birleştirip bir protein oluşturmak için kullanıldığı süreçtir.

### 12.4 Merkezi Dogma

Merkezi dogma şemasında üç aşama vardır (ekrandan, 02:30:00):

1. Replikasyon: DNA kendini çoğaltır.
2. Transkripsiyon: RNA sentezi; çekirdekte DNA'dan mRNA üretilir.
3. Translasyon: protein sentezi; mRNA çekirdek zarından sitoplazmaya geçer ve ribozomda protein üretilir.

Hocaya göre süreç yanlış giderse üretilen protein bozuk bir yapı, bir tür kanser olabilir; her şey doğru giderse yaşam için yeni bir protein elde edilir.

### 12.5 Gen, Genom, Transkriptom, Proteom

- Gen: kalıtımın fiziksel ve işlevsel birimidir; bilgiyi bir kuşaktan sonrakine taşır.
- Genom: bir organizmanın DNA'sının tamamıdır. Hocanın sözlü ifadesine göre insan (Homo sapiens) genomunda yaklaşık 23.000 gen vardır.
- Transkriptom: bir organizmanın olası bütün haberci RNA'larının tamamıdır.
- Proteom: bir organizmanın üretebileceği bütün proteinlerin tamamıdır.

Hoca bunların moleküler biyolojideki temel veri türleri olduğunu söyledi.

## 13. Merkezi Dogmanın Hesaplamalı Modeli

Hoca, kimyayı anlamanın zor olduğunu, kimyacı olmadığımızı ama hesaplama sürecini anlayabileceğimizi söyleyerek örneklere geçti. Bu örneklerde veri türü sayısal değil, yalnızca karakterlerdir.

### 13.1 DNA'dan Amino Asit Dizisine

Soru: Aşağıdaki DNA'yı RNA'ya transkribe edin, sonra genetik kodu kullanarak bir amino asit dizisine çevirin (ekrandan, 02:35:00).

Verilen DNA:

```text
TCATAATACGTTTTGTATTCGCCAGCGCTTCGGTGT
```

Çözümde merkezi dogma bu diziye hesaplamalı olarak uygulanır:

1. Transkripsiyon için önce her baz karşılığıyla değiştirilir: G yerine C, C yerine G, T yerine A, A yerine T.

```text
AGTATTATGCAAAACATAAGCGGTCGCGAAGCCACA
```

2. RNA'da timin (T) bazlarının urasil (U) olduğu hatırlanır. Hocanın deyişiyle bir arama algoritması uygulanır, T'ler bulunup U ile değiştirilir; hesaplama açısından çok kolaydır.

```text
AGUAUUAUGCAAAACAUAAGCGGUCGCGAAGCCACA
```

3. RNA dizisi kodonlara karşılık gelen üçlülere bölünür:

```text
AGU AUU AUG CAA AAC AUA AGC GGU CGC GAA GCC ACA
```

4. Her üçlü genetik kod tablosunda aranır. Programda bir genetik kod tablosu bulunur ve her üçlünün hangi amino aside karşılık geldiğine bakılır. Örneğin AGU serine (S), AUU izolösine (I) karşılık gelir.

```text
AGU AUU AUG CAA AAC AUA AGC GGU CGC GAA GCC ACA
 S   I   M   Q   N   I   S   G   R   E   A   T
```

Sonuç: `SIMQNISGREAT`. Tüm adımlar ders sonrası python ile doğrulandı. Hoca, açıkça böyle bir amino asit dizisinin (proteinin) gerçekte olmadığını, örneğin alındığı kaynağın bunu kavramı göstermek için kurduğunu belirtti. <!-- BELİRSİZ: Son amino asit dizisinin gösterildiği slayt karelerde yok; sonuç tablodan hesaplandı. -->

> **Hocanın vurguladığı:** Hesaplamalı yaklaşım bu kadar basittir; yalnızca metin işlemedir. Bilgisayar becerileriniz bir moleküler biyoloğa böyle yardım eder.

### 13.2 Diziyi Bir Kalıntı Kaydırmak (Örnek 3)

İkinci örnekte önceki örnekteki dizinin bir kalıntı sola kaydırılması ve aynı translasyonun yapılması istenir. Kaydırılmış diziye aynı merkezi dogma adımları uygulanınca hocanın okuduğu sonuç V, L, C, K, T ve ardından bir durma kodonudur.

Python denetiminde, ilk örnekteki dizi bir baz sola döndürülünce RNA şöyle olur:

```text
GUA UUA UGC AAA ACA UAA ...
 V   L   C   K   T  dur
```

Altıncı kodon UAA bir durma kodonudur; translasyon burada biter. <!-- BELİRSİZ: Örnek 3 slaytı karede boş görünüyor (02:40:00); kaydırılmış dizi ekrandan okunamadı, yukarıdaki dizi ilk örnekten hesaplandı ve hocanın sözlü sonucu (VLCKT ve durma) ile uyumlu. -->

Hoca bunu mutasyonla ilişkilendirdi: biyolojik bir yapıda mutasyon, proteini oluşturan bir kimyasal maddenin bir şekilde değişmesi demektir ve tamamen farklı bir protein yapısına yol açar.

### 13.3 Ters Yön: Amino Asit Dizisinden DNA'ya

Hocanın "DNA ile amino asit dönüşümünü açıklayan iyi bir örnek" dediği son örnek ters yönlüdür. Amino asit dizisi DIK verilir ve bu amino asit dizisinin sentezine yol açabilecek olası DNA dizilerinin belirlenmesi istenir.

Genetik kod tablosu kullanılırsa her amino asit için olası kodonlar şunlardır (RNA bazlarıyla; DNA'da U yerine T yazılır):

- D (aspartik asit): GAU, GAC → 2 seçenek
- I (izolösin): AUU, AUC, AUA → 3 seçenek
- K (lizin): AAA, AAG → 2 seçenek

Olası dizi sayısı: $2 \times 3 \times 2 = 12$. Hoca da toplam 12 farklı olası DNA dizisinin DIK amino asit dizisini verdiğini söyledi (python ile doğrulandı). Bu, genetik koddaki fazlalığın doğrudan sonucudur: yalnızca 4 temel kimyasal bileşen olmasına rağmen çok farklı diziler aynı proteine yol açabilir.

Ders sonunda hoca bu örneklerle biyolojik kimyasal süreçlerin bilgisayarda nasıl temsil edildiğini, veri türü olarak ilgi alanımıza nasıl yansıdığını gösterdiğini; bunun aynı zamanda merkezi dogmanın basit bir modellemesi olduğunu söyledi.

## Örnek Sorular

**Soru 1** (ekrandan ve derste sözlü, 00:15:56): 12 bitlik bir ADC'nin giriş aralığı 0-10 V ise ADC'nin analog volt cinsinden doğruluğu nedir?

> **Çözüm (derste verildi):** Aralık $10 - 0 = 10$ V, düzey sayısı $2^{12} = 4096$. Doğruluk $10/4096 \approx 0{,}0024$ V $= 2{,}4$ mV.

**Soru 2** (derste sözlü, 00:23:56): Bir hesaplama sisteminde veri yolu aktarım hızının saniyede 1 kilobyte olduğu söyleniyor. Saniyede kaç byte aktarılır?

> **Çözüm (derste verildi):** 1000 byte. Ölçülen kapasite değil hız olduğundan 10'un kuvveti kullanılır.

**Soru 3** (derste sözlü, 00:36:49): Bir işlemcinin $n$ bitlik adres yolu var. Adreslenebilecek en büyük bellek ne kadardır, adresler hangi aralıktadır?

> **Çözüm (derste verildi):** $2^n$ adres; adresler $0$ ile $2^n - 1$ arasındadır (işaretsiz tamsayı).

**Soru 4** (ekrandan, 00:45:00): 2'ye tümleyen gösterimde `1011` sayısının ondalık karşılığı nedir?

> **Çözüm (derste verildi):** $1\cdot(-8) + 0\cdot 4 + 1\cdot 2 + 1\cdot 1 = -5$.

**Soru 5** (derste sözlü, 00:51:03): C'de `float` türünde tanımlanan bir değişkenin her öğesi bellekte kaç byte kaplar?

> **Çözüm (derste verildi):** 4 byte (32 bit).

**Soru 6** (ekrandan, 00:55:00): 25,75 sayısının IEEE 754 tek duyarlık kayan nokta gösterimini bulun.

> **Çözüm (derste verildi):** $25{,}75 = 11001{,}11_2 = 1{,}1001110 \times 2^4$. $s = 0$; kesir `1001110` ve 0'lar (23 bit); üs $4 + 127 = 131 = 10000011_2$. Sonuç `0 10000011 10011100000000000000000` (python ile denetlendi, `41CE0000`).

**Soru 7** (derste sözlü, 01:00:55): 8 rengi temsil etmek için kaç bit gerekir? 16 renk için?

> **Çözüm (derste verildi):** 8 renk için 3 bit, 16 renk için 4 bit.

**Soru 8** (derste sözlü, 01:32:00): Bir organın varlığı ya da yokluğu bir değişkenle temsil edilirse bu nitel değişken nominal midir, ordinal mi? Hafif/orta/ağır derecelendirmesi nedir?

> **Çözüm (derste verildi):** Organın varlığı/yokluğu nominaldir. Hafif/orta/ağır ise sıralı olduğu için ordinaldir.

**Soru 9** (derste sözlü, 02:02:06): DNA verisi nicel midir, nitel mi? Bilgisayarda hangi veri türüyle tutulur?

> **Çözüm (derste verildi):** Niteldir; karakter (char) dizisi ya da dizgi (string) olarak tutulur.

**Soru 10** (derste sözlü, 02:06:57): Kuramsal olarak 64 kodon varken biyolojik olarak kaç amino asit vardır?

> **Çözüm (derste verildi):** 20 amino asit. 61 kodon amino asit kodlar, 3 kodon durma kodonudur; fazlalık vardır.

**Soru 11** (ekrandan, 02:35:00): `TCATAATACGTTTTGTATTCGCCAGCGCTTCGGTGT` DNA dizisini RNA'ya transkribe edip genetik kodla amino asit dizisine çevirin.

> **Çözüm (derste verildi, son dizi python ile hesaplandı):** Tümleme `AGTATTATGCAAAACATAAGCGGTCGCGAAGCCACA`, T→U `AGUAUUAUGCAAAACAUAAGCGGUCGCGAAGCCACA`, kodonlar AGU AUU AUG CAA AAC AUA AGC GGU CGC GAA GCC ACA, sonuç `SIMQNISGREAT`.

**Soru 12** (ekrandan ve derste sözlü, 02:40:00): Önceki örnekteki diziyi bir kalıntı sola kaydırıp translasyon yapın.

> **Çözüm (derste sözlü verildi, python ile denetlendi):** GUA UUA UGC AAA ACA UAA → V L C K T ve durma kodonu (UAA).

**Soru 13** (derste sözlü, 02:42:21): DIK amino asit dizisinin sentezine yol açabilecek olası DNA dizilerini belirleyin.

> **Çözüm (derste verildi, python ile doğrulandı):** D: GAU/GAC, I: AUU/AUC/AUA, K: AAA/AAG; $2 \times 3 \times 2 = 12$ olası dizi.

## Dersin Toparlaması

Dersin ilk yarısı, biyoenformatikte kullanılacak verinin bilgisayarda nasıl temsil edildiğine ayrıldı: analog işaretlerin süzme, örnekleme, nicemleme ve kodlama ile sayısallaştırılması; bit, byte ve 10'un/2'nin kuvvetleri; işaretsiz tamsayı, 2'ye tümleyen ve IEEE 754 kayan nokta gösterimleri; niteliklerin kodlanması ve dönüşüm ile kodlama arasındaki fark. Ortak fikir şudur: nicelikler ağırlıklı sayı sistemiyle, nitelikler ise kodlarla temsil edilir.

İkinci yarıda bu bakış biyolojik veriye uygulandı. Biyolojik özelliklerin nicel ya da nitel (nominal/ordinal) olabileceği, üst verinin rolü, hücreler, kromozomlar, DNA, nükleotitler, genetik kod, amino asitler, proteinler, RNA türleri ve merkezi dogma anlatıldı. Sonuçta DNA ve amino asit dizilerinin bilgisayarda karakter dizileri olduğu ve merkezi dogmanın tümleme, harf değiştirme, üçlülere bölme ve tablo arama gibi basit metin işlemleriyle modellenebileceği gösterildi. Hoca, sonraki derslerde dersin asıl konularına doğru giriş yapılacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
