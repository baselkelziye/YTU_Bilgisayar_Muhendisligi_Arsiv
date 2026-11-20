# Ders 2 Çalışma Özeti

## Genel Konular

- Analogdan sayısala dönüşüm (ADC)
  - Bilgisayarlar sayısal aygıtlardır; sürekli (analog) bir işaretin işlenebilmesi için sayısallaştırılması gerekir. Zamanlamadaki belirsizlik ve ölçüm süresindeki sınırlar sistem güvenilirliğini etkiler.
  - ADC dört adımdan oluşur: süzme (filtering), örnekleme (sampling), nicemleme (quantization) ve ikili kodlama (binary encoding) (ekrandan, 00:10:00).
  - Analog işaret sayısallaştırılmadan önce süzülmelidir. Örnekleme genelde eşit zaman aralıklarıyla yapılır; örnekleme kuramına göre örnekleme frekansı işaretin en yüksek frekans bileşeninin en az iki katı olmalıdır.
  - Nicemlemede örnekler $0, d, 2d, 3d, \dots$ düzeylerine yuvarlanır ($d$: düzey aralığı). 8 düzey varsa her örnek $\log_2 8 = 3$ bit ile kodlanır. Nicemleme bir hata getirir: nicemleme hatası (ekrandan, 00:15:00). <!-- BELİRSİZ: 00:12:43 civarında okunan nicemlenmiş kod dizisi ("2, 5, 7, 7, 6, 2, 1, 2, 2") ve yuvarlama yönü kareyle doğrulanamadı. -->
  - Bant sınırlama, örnekleme, nicemleme ve kodlama ADC adımlarıdır; sayısaldan analoğa dönüşümde örnekle-tut, görüntü reddetme ve süzme adımları vardır. Örtüşme (aliasing), örtüşme önleyici süzgeç gibi kavramlar ders kapsamı dışında bırakıldı.
- Sayısal veri birimleri (ekrandan, 00:20:00)
  - Bit: en küçük sayısal bilgi, 1 ya da 0. Nibble: 4 bit. Byte: 8 bit, 2 nibble. Word: 16 bit, 2 byte, 4 nibble.
  - İlgili terimler: tamsayı, işaretli tamsayı, uzun tamsayı, 2'ye tümleyen, onaltılık, sekizlik, kayan nokta.
- Kapasite ve hız ölçüleri (ekrandan, 00:25:00)
  - Kilo $=10^3$ ya da $2^{10}$, Mega $=10^6$ ya da $2^{20}$, Giga $=10^9$ ya da $2^{30}$, Tera $=10^{12}$ ya da $2^{40}$, Peta $=10^{15}$ ya da $2^{50}$.
  - Hangisinin kullanılacağı ölçülen şeye bağlıdır: bellek kapasitesi 2'nin kuvvetleriyle, hız ve diğer başarım ölçüleri 10'un kuvvetleriyle ifade edilir.
- Veri türleri: nicel ve nitel
  - Bütün veriler bilgisayarda ikili olarak tutulur. Sayılar nicelik (quantity) temsil eder; metin, görüntü, ses ve mantıksal komutlar ise bir nitelik (quality) temsil eden kodlardır.
- Basamaklı (ağırlıklı) sayı sistemi
  - Onluk sistemde her basamağın bir ağırlığı vardır (birler, onlar, yüzler; ondalık kısımda onda birler, yüzde birler). Bilgisayar da aynı sistemi 2 tabanında kullanır (birler, ikiler, dörtler, sekizler).
- İşaretsiz tamsayılar
  - Bellek adresleri işaretsiz tamsayıdır. $n$ bitlik adres yolu olan bir işlemci $2^n$ adres görebilir; adresler $0$ ile $2^n-1$ arasındadır.
- İşaretli tamsayılar ve 2'ye tümleyen gösterim (ekrandan, 00:45:00)
  - $a$'yı $-a$'ya dönüştürmek için bütün bitler ters çevrilir ve sonuca 1 eklenir.
  - $N$ bit için aralık: $-2^{N-1} \le i \le 2^{N-1}-1$. 5 bitte $-16 = 10000$, $-1 = 11111$, $+15 = 01111$.
  - 2'ye tümleyen bir kod değil, ağırlıklı bir sayı sistemidir: en anlamlı bitin ağırlığı negatiftir. $1011 = -8 + 0 + 2 + 1 = -5$.
  - Bilgisayar bütün aritmetik işlemleri bu sistemde yapar.
- Kayan nokta sayılar (IEEE 754)
  - Tamsayıların aralığı ve çözünürlüğü sınırlı olduğundan çok küçük ve çok büyük sayılar için kayan nokta biçimi kullanılır. Temel fikir sayıyı üstel (mühendislik) biçimde göstermektir.
  - Tek duyarlık (C'de `float`): 32 bit, 4 byte. 1 işaret biti, 8 bit kaydırılmış (biased) üs, 23 bit kesir (mantis). Değer: $(-1)^s \times 1.\text{kesir} \times 2^{(\text{üs}-127)}$.
  - Çift duyarlık (`double`): 64 bit; 1 işaret, 11 bit üs, 52 bit kesir; $N = (-1)^s \times 1.\text{kesir} \times 2^{(\text{üs}-1023)}$ (ekrandan, 01:00:00).
  - Daha yüksek duyarlık için 80 ve 128 bitlik biçimler de vardır.
- Niteliklerin kodlanması
  - 8 renk 3 bit, 16 renk 4 bit ile kodlanır. Ses, karakter gibi nitelikler de benzer biçimde kodlanır.
  - Dönüşüm (conversion) ile kodlamayı (coding) ayırmak gerekir: 57'nin ikili karşılığı bir dönüşümdür; 5 ve 7'nin ayrı ayrı BCD ile yazılması bir koddur. ASCII karakter kodları, hata bulma/düzeltme kodları da koddur.
- Mantık işlemleri
  - Sayısal bilgisayar ikili anahtarların birleşimidir; anahtarlar CMOS ya da TTL transistörlerle yapılan kapılarla gerçeklenir.
  - XOR: A ya da B 1'dir ama ikisi birden değil; $A \oplus B = A\cdot B' + A'\cdot B$. XNOR bunun tümleyenidir (ekrandan, 01:05:00).
- Biyomedikal verinin doğası ve temsili
  - Ders slaytının hedefleri: moleküler biyolojinin temelleri, moleküler veritabanı türleri, erişim numaraları (accession number) ve dizi tanımlayıcıları, genom tarayıcıları.
  - Biyolojik nesnelerin bazı özellikleri sayısaldır: kandaki bir kimyasalın derişimi, tümörün boyutu, bir hücre, doku ya da sıvının pH değeri. Bazıları yalnız adlandırılabilir: gen transkripsiyonuyla üretilen protein, bir organın varlığı ya da yokluğu (ekrandan, 01:30:00).
  - Nitel veri iki türdür: nominal (sırasız) ve ordinal (sıralı). Organın var ya da yok olması nominaldir; hafif/orta/ağır gibi derecelendirme ordinaldir.
  - Nitel veriyle çalışmak için ya nitel veriye uygun bir algoritma bulunur ya da nitel veri nicel veriye dönüştürülür.
- Üst veri (metadata) (ekrandan, 01:40:00)
  - Verinin bir ya da daha fazla yönü hakkında bilgi veren veridir; veriyi izlemeyi ve onunla çalışmayı kolaylaştırır.
  - Örnekler: verinin oluşturulma yolu, amacı, oluşturulma tarihi ve saati, oluşturan kişi, oluşturulduğu ağ konumu, kullanılan standartlar, dosya boyutu. İşaretleme dilleri de üst veri taşır.
- Hücreler
  - Hücre yaşamın yapı taşıdır. Çoğu bakteri tek hücreli, insan gibi canlılar çok hücrelidir.
  - Hücre türleri: yassı (squamous), epitel, kas ve kan hücreleri; kan hücreleri kırmızı ve beyaz olarak ayrılır (ekrandan, 01:45:00). Bunlar kategorik verilerdir ama sayılarak sayısal veriyle ilişkilendirilebilir.
  - Ökaryot hücre, prokaryot hücreden yaklaşık 10 kat büyüktür. Ökaryotlarda kromozomal DNA çekirdekte, prokaryotlarda sitoplazmada bulunur; mitokondri gibi organeller de DNA içerir.
- Kromozomlar
  - Kromozom, hücrelerde bulunan DNA ve proteinlerden oluşan düzenli yapıdır. Ad Yunanca *chroma* (renk) ve *soma* (beden) sözcüklerinden gelir; bazı boyalarla çok güçlü boyanmalarından dolayı (ekrandan, 01:50:00).
  - Tek bir kromozom çok sayıda gen, düzenleyici öğe ve başka nükleotit dizileri içeren tek parça bir DNA'dır. İnsanda 22 çift otozom ve 1 çift cinsiyet kromozomu vardır. Japon balığında 100-104 kromozom vardır.
- DNA ve nükleotitler
  - DNA (deoksiribonükleik asit) biyolojik varlıkta bilginin uzun süreli saklanmasını sağlar. Kimyasal olarak nükleotit adı verilen basit birimlerden oluşan iki uzun polimerdir.
  - Dört nükleotit: adenin (A), sitozin (C), guanin (G), timin (T). A ve G pürin, C ve T pirimidin grubundadır.
  - Nükleotit üç parçadan oluşur: azotlu baz, şeker (riboz ya da deoksiriboz) ve fosfat grubu.
- Genetik kod (ekrandan, 02:10:00)
  - Genetik malzemede (DNA ya da mRNA) kodlanmış bilginin canlı hücrelerce proteine çevrilme kurallarıdır; 64 girdili bir tabloyla gösterilebilir.
  - RNA'da dört baz vardır (A, C, G, U). Üç nükleotitlik her grup bir kodondur: $4^3 = 64$ olası kodon.
  - Başlama kodonu AUG; durma kodonları UAA, UAG, UGA. Amino asitleri kodlayan 61 kodon vardır (AUG dahil).
  - 20 amino asit vardır; çoğu amino asidi birden fazla kodon kodlar, yani genetik kodda fazlalık (redundancy) vardır.
- DNA verisinin bilgisayardaki türü
  - DNA dizisi nitel bir veridir ve bilgisayarda karakter dizisi (string) olarak tutulur. Biyoenformatikte işlemlerin çoğu bu karakter dizileri üzerinde yapılır.
- Amino asitler ve proteinler
  - Amino asitler proteinlerin yapı birimleridir; suyu seven (hidrofilik) ve suyu sevmeyen (hidrofobik) türleri vardır. Kısa zincirlere peptit, uzun zincirlere polipeptit ya da protein denir. mRNA şablonundan bu zincirin kurulmasına translasyon denir.
  - Proteinler moleküler makinenin temel bileşenidir: kastaki miyozin ve aktin hareketi sağlar (ekrandan, 02:15:00). Enzim (biyokimyasal tepkimeleri hızlandıran katalizör), sinyal ve yapı bileşeni olarak görev yaparlar.
  - Protein, amino asitlerin peptit bağlarıyla doğrusal bir zincirde birleşmesiyle oluşan büyük bir organik bileşiktir; amino asit sırası gen tarafından belirlenir.
- HIV enfeksiyonu örneği
  - Virüs hücreye girer, hücre virüsün genetik kodunu okur, hücre yeni HIV proteinleri ve virüsler üretir, yeni virüsler hücreden çıkıp başka hücreleri enfekte eder. Bu süreci anlamak ilaç keşfi için biyoenformatiği gerekli kılar.
- RNA ve türleri (ekrandan, 02:25:00)
  - RNA genelde tek iplikli, DNA çift iplikli ve tümleyendir. RNA'da riboz, DNA'da deoksiriboz bulunur. RNA'da timin yerine urasil (U) vardır.
  - RNA, DNA'dan RNA polimeraz enzimleriyle kopyalanır ve protein sentezinin ara aşamasıdır.
  - mRNA (haberci RNA) bilgiyi DNA'dan ribozomlara taşır. Ökaryot genlerinde ekzonlar kodlayan, intronlar kodlamayan bölgelerdir. İntronların çıkarılıp ekzonların birleştirilmesine splicing denir; splice bölgelerini bulmak biyoenformatikte önemlidir.
  - tRNA (taşıyıcı RNA) küçük bir RNA'dır; translasyon sırasında belirli bir amino asidi ribozomdaki büyüyen polipeptit zincirine taşır.
- Merkezi dogma (ekrandan, 02:30:00)
  - Replikasyon (DNA kendini çoğaltır), transkripsiyon (RNA sentezi), translasyon (ribozomda protein sentezi).
  - Gen: kalıtımın fiziksel ve işlevsel birimi. Genom: bir organizmanın DNA'sının tamamı (insanda yaklaşık 23.000 gen). Transkriptom: olası bütün mRNA'lar. Proteom: üretilebilecek bütün proteinler.
- Merkezi dogmanın hesaplamalı modeli (örnekler)
  - DNA dizisinin tümleyeni alınır, T'ler U ile değiştirilir, dizi üçlülere bölünür ve her kodon genetik kod tablosundan amino aside çevrilir. Bu işlem yalnız metin işlemedir.
  - Dizi bir bazlık kaydırılınca bambaşka bir amino asit dizisi çıkar; mutasyon kavramını gösterir.
  - Ters yönde, bir amino asit dizisine karşılık gelen olası birden fazla DNA dizisi vardır (DIK için 12).

## Hocanın Özellikle Vurguladığı Kısımlar

- 10'un ve 2'nin kuvvetleri karıştırılmamalı
  - Bellek kapasitesi 2'nin, hız gibi başarım ölçüleri 10'un kuvvetleriyle ifade edilir. "Saniyede 1 kilobyte" aktarım hızı 1000 byte/s'dir, 1024 değil. Hoca bunun hep yapılan bir hata olduğunu söyledi.
- 2'ye tümleyen bir kod değil, ağırlıklı sayı sistemidir
  - En anlamlı bitin ağırlığı negatiftir; sayı ağırlıklar toplanarak bulunur. "Başı 1 olan sayı negatiftir, gerisi büyüklüktür" diye düşünmek yanlıştır: o yorumla $1011$ "$-3$" olurdu, oysa değeri $-5$'tir.
  - Hoca bu konuların biyoenformatikle doğrudan ilgili olmasa da çok temel olduğu için üzerinde durduğunu belirtti.
- Dönüşüm mü, kodlama mı?
  - Bir gösterimin sayının ikiliye dönüşümü mü yoksa bir kod mu olduğunun farkında olunmalıdır.
- Verinin önemi
  - Projelerde emeğin büyük kısmı veri hazırlama ve temizlemeye gider; geri kalanı algoritma uygulama ve sonuç değerlendirmedir. Nitel veri ya uygun bir algoritmayla işlenmeli ya da nicel veriye dönüştürülmelidir.
- DNA bir karakter dizisidir
  - Kimyasal yapılar bilgisayarda karakter dizisi olarak temsil edilir; biyoenformatikte karakter ve dizgi işleme başlangıç noktasıdır.

## Kısa Tekrar Notları

- ADC: süzme → örnekleme → nicemleme → ikili kodlama. Örnekleme frekansı en yüksek frekansın en az iki katı olmalı.
- $L$ düzey için gereken bit sayısı $\log_2 L$; 8 düzey → 3 bit.
- 12 bitlik, 0-10 V girişli ADC: $10/2^{12} = 10/4096 \approx 2{,}44$ mV.
- Bit, nibble (4), byte (8), word (16 bit).
- Bellek → 2'nin kuvvetleri; hız → 10'un kuvvetleri. 1 KB/s = 1000 byte/s.
- İşaretsiz $n$ bit: $0 \dots 2^n-1$. 2'ye tümleyen $N$ bit: $-2^{N-1} \dots 2^{N-1}-1$.
- $-a$: bitleri ters çevir, 1 ekle. $1011_2 = -5$.
- IEEE 754 tek duyarlık: 1 + 8 + 23 bit, kaydırma 127. Çift duyarlık: 1 + 11 + 52 bit, kaydırma 1023.
- $25{,}75 = 11001{,}11_2 = 1{,}100111 \times 2^4$ → üs $4+127 = 131$.
- Nitel veri: nominal (organ var/yok) ve ordinal (hafif/orta/ağır).
- Bazlar: A, C, G, T (RNA'da T yerine U). Pürin: A, G. Pirimidin: C, T.
- Kodon = 3 nükleotit; $4^3=64$ kodon; başlama AUG; durma UAA, UAG, UGA; 61 kodon, 20 amino asit.
- Merkezi dogma: replikasyon, transkripsiyon, translasyon.
- Ekzon kodlar, intron kodlamaz; splicing intronları çıkarır.
- DNA verisi bilgisayarda karakter dizisidir.

## Detaylı Açıklamalar

- ADC çözünürlük örneği (ekrandan, 00:15:00 civarı; değerler altyazıdan)
  - 12 bitlik bir ADC'nin giriş aralığı 0-10 V ise analog doğruluğu, yani çıkışta bir değişiklik oluşturan en küçük giriş değişimi sorulur.
  - Aralık $V_{max} - V_{min} = 10 - 0 = 10$ V. Düzey sayısı $2^{12} = 4096$.
  - Doğruluk $= 10 / 4096 \approx 0{,}0024$ V $= 2{,}4$ mV. Girişteki yaklaşık 2,4 mV'lik değişim çıkışta bir basamak değişikliği yaratır (python ile doğrulandı: $0{,}00244$ V).
- 2'ye tümleyen örneği (ekrandan, 00:45:00)
  - $1011$ sayısı ağırlıklarla çözülür: $1\cdot(-8) + 0\cdot 4 + 1\cdot 2 + 1\cdot 1 = -5$.
  - Sayı bir kod olarak, "işaret biti + büyüklük" diye okunsaydı $-3$ çıkardı. 2'ye tümleyende işaret ayrı bir kod değildir; en anlamlı bit $-2^{N-1}$ ağırlığını taşır.
- IEEE 754 örneği: 25,75 (ekrandan, 00:55:00)
  - $25{,}75 \Rightarrow 00011001{,}110 \Rightarrow 1{,}1001110 \times 2^4$. Ondalık nokta 4 basamak sola kaydırıldığından sayı $2^4$ ile çarpılarak normalize edilir.
  - Sayı pozitif olduğundan $s = 0$. Normalize sayının başındaki 1 saklanmaz; kesir alanı $1001110$ ve ardından 0'larla 23 bite tamamlanır.
  - Kaydırılmış üs $= 4 + 127 = 131 = 10000011_2$. 8 bitlik üs alanı için kaydırma miktarı $2^{8-1} - 1 = 127$'dir; kaydırma negatif üsleri pozitif bölgeye taşımak içindir.
  - Sonuç: $0\ 10000011\ 10011100000000000000000$ (ders sonrası python ile denetlendi; onaltılık karşılığı `41CE0000`).
  - Hocaya göre kayan nokta aritmetiği tamsayı aritmetiğinden farklı ve daha zordur; örneğin kayan nokta toplaması çarpmasından çok daha karmaşıktır.
- Merkezi dogmanın hesaplamalı uygulaması (ekrandan, 02:35:00)
  - Verilen DNA: `TCATAATACGTTTTGTATTCGCCAGCGCTTCGGTGT`.
  - 1. Adım, tümleme (G yerine C, C yerine G, T yerine A, A yerine T): `AGTATTATGCAAAACATAAGCGGTCGCGAAGCCACA`.
  - 2. Adım, T'ler U olur: `AGUAUUAUGCAAAACAUAAGCGGUCGCGAAGCCACA`. Hoca bunun bir arama ve değiştirme algoritmasıyla kolayca yapılacağını söyledi.
  - 3. Adım, üçlülere bölme: AGU AUU AUG CAA AAC AUA AGC GGU CGC GAA GCC ACA.
  - 4. Adım, genetik kod tablosu: AGU → S (serin), AUU → I (izolösin), ... Sonuç `SIMQNISGREAT` (python ile doğrulandı). Hoca böyle bir protein olmadığını, örneğin kavramı göstermek için seçildiğini belirtti.
- Kaydırma örneği (Örnek 3)
  - Önceki dizi bir kalıntı sola kaydırılıp aynı adımlar uygulanınca hocaya göre V, L, C, K, T ve bir durma kodonu çıkar. Python denetimi: kaydırılmış RNA'nın ilk altı kodonu GUA UUA UGC AAA ACA UAA → `VLCKT` ve durma (UAA). <!-- BELİRSİZ: Örnek 3 slaytı karede boş görünüyor (02:40:00); kaydırılmış dizi ekrandan okunamadı, yukarıdaki dizi ilk örnekten hesaplandı. -->
  - Hoca bunu mutasyonla ilişkilendirdi: proteini oluşturan kimyasal dizideki küçük bir değişiklik tamamen farklı bir protein yapısına yol açar.
- Ters yönlü örnek: DIK
  - Amino asit dizisi DIK verildiğinde bu diziyi üretebilecek olası diziler istenir. D için 2 (GAU, GAC), I için 3 (AUU, AUC, AUA), K için 2 (AAA, AAG) kodon vardır; toplam $2 \times 3 \times 2 = 12$ olası dizi (python ile doğrulandı). Bu, genetik koddaki fazlalığın sonucudur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
