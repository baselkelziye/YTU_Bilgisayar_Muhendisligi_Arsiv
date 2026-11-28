# Ders 2 Genişletilmiş Notu: Biyolojik Veritabanları ve Perl/Python ile Programlamaya Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

<!-- BELİRSİZ: Kaydın altyazısı birçok yerde bozuk ya da tekrarlı (Whisper halüsinasyonu). Slaytların önemli kısmı yalnız 5 dakikada bir alınan karelerden doğrulanabildi; karelerde görünmeyen slayt içerikleri altyazıdan, genel ifadeyle aktarıldı. -->

## İçindekiler

- 1. Moleküler biyolojinin temelleri: tRNA, merkezî dogma, gen ve genom
- 2. Biyomedikal verinin bilgisayarda temsili
- 3. Biyolojik veritabanı kayıtları
- 4. Biyolojik veritabanları ve dizi depoları
- 5. Ölçekler, taksonomi, erişim numaraları ve genom tarayıcıları
- 6. Hesaplamaya giriş
- 7. Programlama ve üç temel yapı
- 8. Perl ve Python
- 9. Hata ayıklama
- 10. İlk Perl programları: sabitler, değişkenler, seçim
- 11. Veri dosyalarını işleme
- Örnek Sorular

## 1. Moleküler biyolojinin temelleri: tRNA, merkezî dogma, gen ve genom

Ders, önceki derste kalınan moleküler biyoloji slaytlarından devam etti.

### 1.1 Taşıyıcı RNA

Taşıyıcı RNA (transfer RNA, tRNA) küçük bir RNA türüdür. Uzunluğu genelde 74 ile 95 nükleotit arasındadır, 100'ü geçmez; yani bir tRNA en fazla yaklaşık 100 harften oluşur. Görevi, çeviri (translation) sırasında belirli bir amino asidi, protein sentezinin yapıldığı ribozomdaki büyüyen polipeptit zincirine taşımaktır.

### 1.2 Merkezî dogma

Merkezî dogma bir şekil üzerinden anlatıldı (ekrandan, 00:10:00). Şekilde üç süreç vardır:

- Replikasyon (replication, DNA duplicates): DNA kendini eşler; bilgi bir DNA'dan iki DNA'ya geçer.
- Transkripsiyon (transcription, RNA synthesis): çekirdekte (nucleus) DNA'nın bir bölümü açılır ve ondan mRNA sentezlenir.
- Translasyon (translation, protein synthesis): mRNA çekirdek zarından (nuclear envelope) sitoplazmaya geçer, ribozomda okunur ve protein üretilir.

Şeklin solunda bilgi akışının özeti DNA → RNA → Protein biçimindedir; DNA'dan kendine dönen ok replikasyonu gösterir.

### 1.3 Gen, genom, transkriptom, proteom

Gen, kalıtımın fiziksel ve işlevsel birimidir; bilgiyi bir kuşaktan ötekine taşır. Genom, bir organizmanın bütün genleri dahil eksiksiz DNA kümesidir. Her genom, o organizmayı kurmak ve sürdürmek için gereken bilginin tamamını içerir.

Genom büyüklüğü ve gen sayısı organizmanın karmaşıklığıyla ilgilidir ama karmaşıklığı belirleyen baskın etken değildir. Hoca bir genom karşılaştırma tablosu gösterdi: insan genomu yaklaşık 3 milyar baz çifti, gen sayısı yaklaşık 30.000 olarak verildi; farenin gen sayısı insanınkine yakındır ama genomu daha küçüktür; meyve sineği gibi diğer organizmaların genom büyüklükleri, gen sayıları ve kromozom büyüklükleri farklıdır.

<!-- BELİRSİZ: Genom karşılaştırma tablosunun değerleri karelerde görünmüyor; yalnız altyazıda söylenen insan ve fare bilgisi aktarıldı. -->

> **Ek bilgi (derste anlatılmadı):** Güncel tahminlere göre insanın protein kodlayan gen sayısı büyük olasılıkla 20.000 civarındadır; 30.000 değeri daha eski kaynaklarda geçen bir tahmindir.

İki terim daha tanımlandı:

- Transkriptom: bir organizmanın olası bütün mRNA'larının tamamıdır. Genomun mRNA'ya yazılan bölgeleri de transkriptom diye anılır. Tanım, yapısal ve düzenleyici amaçlı kodlamayan RNA'lar dahil bütün yazılan öğeleri kapsayacak biçimde genişletilebilir. Hoca, DNA'da kodlayan ve kodlamayan (intron) bölgeler olduğunu, RNA'da da kodlayan ve kodlamayan bölümler bulunduğunu, ama bunların amaçlarının farklı olduğunu hatırlattı.
- Proteom: bir organizmanın üretebileceği proteinlerin tamamıdır.

## 2. Biyomedikal verinin bilgisayarda temsili

### 2.1 Nicel ve nitel veri

Bilgisayar programlarının biyomedikal veriyle çalışabilmesi için verinin bilgisayarda temsil edilmesi gerekir (ekrandan, 00:15:00). Veri temelde iki büyük sınıfa ayrılır: nicel (quantitative) ve nitel (qualitative). Bu sınıflandırma daha önce konuşulmuştu; bu derste biyoenformatik bağlamında açıklandı.

Temsil edilmesi gereken biyomedikal veri türleri şunlardır:

- DNA ve protein dizileri, karakter dizileri olarak.
- Kan örnekleri üzerinde yapılan testlerden gelen laboratuvar verileri; örneğin kan hücresi sayısı nicel bir bilgidir.
- Klinik ya da hastanede hastalardan elde edilen diğer veriler ve tıbbi görüntüler (görüntünün nasıl temsil edildiği daha önce anlatılmıştı).
- Medline makale veritabanı gibi geniş kaynakça veritabanlarında arama ve sıralama yapmak için gereken metin verileri.

### 2.2 DNA dizisinin temsili

Baz dizileri harflerle, diziler uzun dizgeler (string) ya da karakter dizileri olarak temsil edilebilir. Bir başka yol, her nükleotidi bir listede bir sembol olarak tutmaktır; bütün dizi bir sembol listesi olur. Slaytta gösterilen örnek (ekrandan, 00:20:00):

```text
(C A C T G G C A T G A T C A G G A C T C A C T G
 C A G C C T T G A C T C C C A G G C T C A G T A
 G A T C C T C C T A C C T C A G C C T C T C G A
 G T A A C T G G G A C C A C A G G C G A G C A T
 C A C C A T G C T C A G C T A G T T T T T G T A T
 T T G T A G A G A T G A G G T T T C A C C A T A
 T T G C C C A G G C T G G T C T T G A A C T C C
 T G G G C T C A A G C A A G C C A C C C A C C T
 T G G C C A C C C A A A G T G C T)
```

<!-- BELİRSİZ: Beşinci satırdaki ardışık T sayısı karede kesin sayılamadı; diğer satırlar 24 harf, bu satır okunduğu haliyle 25 harf. -->

Hoca bunun aslında bir karakter dizisi ya da dizge olduğunu söyledi; hangisi denirse densin yapı aynıdır. Ardından bu verinin hangi sınıfa girdiğini sordu (bkz. Örnek Sorular).

## 3. Biyolojik veritabanı kayıtları

### 3.1 UniProt kaydı: insan insülini

Hoca, biyoenformatik verilerin indirilebildiği UniProt/Swiss-Prot sitesini açtı ve buradan çok çeşitli biyoenformatik veri indirilebileceğini söyledi. Slaytta insan insülininin kaydı gösterildi (ekrandan, 00:25:00). Kaydın başlıca satırları şunlardır:

```text
ID   INS_HUMAN              Reviewed;         110 AA.
AC   P01308; Q5EEX2;
DE   Insulin precursor [Contains: Insulin B chain; Insulin A chain].
GN   Name=INS;
OS   Homo sapiens (Human).
DR   GO; GO:0006953; P:acute-phase response; NAS:UniProtKB.
DR   GO; GO:0046631; P:alpha-beta T cell activation; IDA:UniProtKB.
DR   GO; GO:0008219; P:cell death; NAS:UniProtKB.
DR   GO; GO:0007267; P:cell-cell signaling; IC:UniProtKB.
DR   GO; GO:0006006; P:glucose metabolic process; TAS:ProtInc.
DR   GO; GO:0015758; P:glucose transport; IDA:UniProtKB.
FT   SIGNAL       1     24
FT   PEPTIDE     25     54       Insulin B chain.
FT   PROPEP      57     87       C peptide.
FT   PEPTIDE     90    110       Insulin A chain.
FT   DISULFID    31     96       Interchain (between B and A chains).
FT   DISULFID    43    109       Interchain (between B and A chains).
FT   DISULFID    95    100
FT   VARIANT     34     34       H -> D (in familial hyperproinsulinemia).
FT   HELIX       35     43
FT   HELIX       44     46
FT   STRAND      48     50
FT   STRAND      56     58
FT   STRAND      74     76
FT   HELIX       79     81
FT   TURN        84     86
FT   HELIX       91     95
FT   HELIX      105    108
SQ   SEQUENCE   110 AA;  11981 MW;  C2C3B23B85E520E5 CRC64;
     MALWMRLLPL LALLALWGPD PAAAFVNQHL CGSHLVEALY LVCGERGFFY TPKTRREAED
     LQVGQVELGG GPGAGSLQPL ALEGSLQKRG IVEQCCTSIC SLYQLENYCN
```

(Slayttaki `/FTId=...` alt satırları ve varyantın kaynak bilgisi kısaltıldı.)

`DR` satırlarında Gene Ontology (GO) terimleri vardır. Hoca, bu alanlarda genelde üstveri (metadata) bulunduğunu söyledi. `FT` (feature) satırları amino asit dizisinde farklı yapıların, örneğin alfa sarmal (helix) ve beta iplik (strand) yapılarının yer aldığı konumları gösterir. Her alanın tam açıklaması ExPASy sitesindeki belgelerdedir.

### 3.2 Enzim kaydı

Birçok protein enzim olarak çalışır. Enzimler kimyasal tepkimeleri kolaylaştıran bileşiklerdir ve biyolojik açıdan önemli birçok tepkime ilgili enzim olmadan ilerlemez. Bu yüzden bir protein hakkındaki önemli bilgilerden biri işlevidir: protein bir enzim mi, öyleyse hangi tür enzim, hangi tepkimeyi kolaylaştırıyor?

Sonraki slaytta ExPASy sitesindeki enzim veritabanından küçük bir alıntı gösterildi:

- `ID` ile başlayan satır, her kayda özgü enzim komisyonu (EC) numarasıdır.
- `DE` satırı enzimin resmî adıdır.
- Sonraki satırlar eş adları (synonym) verir.
- NAD+ ve NADH molekülleri koenzimdir.
- Malat dehidrojenazın katalizlediği tepkime, `CA` ile başlayan satırda simgesel biçimde yazılıdır.
- `CC` satırı yorum bilgisi verir.

<!-- BELİRSİZ: Enzim kaydının karesi yok; EC numarası ve tepkime metni aktarılamadı. -->

## 4. Biyolojik veritabanları ve dizi depoları

### 4.1 Veritabanlarına iki bakış

Biyolojik veritabanlarında iki bakış açısı vardır:

- Tek bir nesneyi incelemek: bir gen, protein, DNA molekülü ya da başka bir nesne. Örneğin insan beta-globini için bir gen (HBB), bir protein dizisi, protein yapısı kayıtları ve çeşitli varyasyon kayıtları vardır.
- Büyük grupları incelemek: insan genomundaki bütün globin genleri, bilinen bütün HBB varyantları ya da daha önce bir hastalıkla ilişkilendirilmiş 100 genin hasta örneklerindeki çeşitliliği.

Bunlar veritabanlarında aramayı düşünmenin farklı yollarıdır.

### 4.2 Nükleotit dizileri nerede saklanır?

Slayttaki sorular (ekrandan, 00:30:00): Kamuya açık veritabanlarında ne kadar DNA dizisi saklanıyor? Veriler nerede saklanıyor? 1982'den bugüne nükleotit dizisi verilerini saklamaktan sorumlu üç ana merkez vardır:

- GenBank: ABD'de, Ulusal Sağlık Enstitüleri'ne (NIH) bağlı Ulusal Biyoteknoloji Bilgi Merkezi'nde (NCBI), Bethesda'da.
- EMBL-Bank: Avrupa Biyoenformatik Enstitüsü'ndeki (EBI) Avrupa Nükleotit Arşivi'nin (ENA) parçası, Birleşik Krallık'ta.
- DDBJ (DNA Data Bank of Japan).

NCBI'daki GenBank, EBI'daki EMBL-Bank ve DDBJ'nin nükleotit koleksiyonları International Nucleotide Sequence Database Collaboration (INSDC) tarafından eşgüdümlenir. Hoca ayrıca EBI'nin örgüt yapısını gösteren bir şema gösterdi.

> **Ders sonrası not:** Altyazıda EBI'nin yeri "Houston" diye geçiyor; bu büyük olasılıkla Whisper hatasıdır. EBI, Birleşik Krallık'ta Hinxton'dadır; hoca da "UK" dedi.

### 4.3 Dizi depolarının büyümesi

Bir slayt DNA dizi depolarının büyümesini gösteriyordu. Grafik 2015-2016'ya kadar olan veriyi içeriyordu, son dört beş yıl eksikti; ama hocaya göre eğilim aynıdır ve büyüme hızı giderek daha da dikleşmektedir.

## 5. Ölçekler, taksonomi, erişim numaraları ve genom tarayıcıları

### 5.1 DNA baz çifti ölçekleri

Slayttaki tablo (ekrandan, 00:35:00):

| Baz çifti | Birim | Kısaltma | Örnek |
|---|---|---|---|
| 1 | 1 baz çifti | 1 bp | |
| 1000 | 1 kilobaz çifti | 1 kb | Bir genin tipik kodlayan bölgesinin büyüklüğü |
| 1.000.000 | 1 megabaz çifti | 1 Mb | Tipik bir bakteri genomunun büyüklüğü |
| $10^9$ | 1 gigabaz çifti | 1 Gb | İnsan genomu 3 milyar baz çiftidir |
| $10^{12}$ | 1 terabaz çifti | 1 Tb | |
| $10^{15}$ | 1 petabaz çifti | 1 Pb | |

> **Hocanın vurgusu:** 1 kilobaz $10^3$ baz çiftidir, $2^{10}$ baz çifti değildir; karıştırmayın.

Hoca ardından dosya büyüklüğü ölçeklerini (kilo, mega, ...) içeren bir hatırlatma slaytı gösterdi ve bunun bu niceliklerle ilgili üçüncü hatırlatma olduğunu söyledi.

### 5.2 GenBank'ta temsil edilen taksonlar

GenBank'ta Archaea, Bacteria, Eukaryota, Fungi, Metazoa gibi gruplar vardır; bunlar canlıların resmî ya da bilimsel adlarıdır. Taxa, taxon (takson) sözcüğünün çoğuludur: akraba organizmaların sınıflandırıldığı biyolojik sınıflandırmadaki herhangi bir grup ya da basamaktır.

### 5.3 Merkezî dogma ve veri türleri

Çeşitli veritabanlarında saklanan veri türleri merkezî dogma üzerinden kavramsallaştırılabilir: genomik DNA, öncül mRNA'ya yazılan protein kodlayan genleri içerir; öncül mRNA işlenip olgun mRNA olur ve proteine çevrilir. Slayttaki protein yapısı 1HPS erişim numaralı kayıttandır. Hoca bu dogmanın derste ikinci ya da üçüncü kez, biraz farklı sunumlarla gösterildiğini belirtti. İşleme sırasında kodlamayan bölgeler olan intronlar çıkarılır, kodlayan bölgeler olan ekzonlar birleştirilir; bu sürece splicing denir. Ardından mRNA proteine çevrilir.

Bir slaytta dizilenmiş organizmaların ilk 10'u listelendi; altyazıda fare, mısır, domuz, sığır, zebra balığı, buğday, kurbağa gibi adlar geçiyor.

<!-- BELİRSİZ: "Top 10 organisms" slaytının başlığı ve tam listesi altyazıda bozuk, karede yok. -->

### 5.4 Erişim numaraları

Erişim numarası (accession number) dizilere verilen etikettir (ekrandan, 00:40:00): bir moleküler diziye karşılık gelen numaradır. Bütün DNA, RNA ve protein dizilerinin erişim numarası vardır. Hoca NCBI tabanlı arayüzde insan beta-globin örneklerini ve başka örnekleri gösterdi.

### 5.5 Genom tarayıcıları

Genom tarayıcıları (genome browser) genomları gezmek için kullanılan web tabanlı uygulamalardır. Hoca bir tarayıcıyı canlı açmayı denedi ve örneğin COVID-19 ile ilgilenenler için orada çok sayıda bilgi ve bağlantı bulunduğunu gösterdi.

Bölümü şöyle bağladı: Biyoenformatik alanı, kısmen işlenmesi gereken büyük miktarda dizi verisi yüzünden çok hızlı büyümektedir. Genomik veri saklayan birçok veritabanı ve bilgi çıkarmak için birçok yaklaşım vardır. Bu veritabanları hakkında bilgi için Wikipedia iyi bir başlangıç noktasıdır; "List of biological databases" sayfasındaki bölümler gezilip veritabanlarıyla denemeler yapılabilir.

## 6. Hesaplamaya giriş

Aradan sonra yeni bir slayt grubuna geçildi. Hoca, öğrencilerin Java, C ve belki Python gibi dilleri, istatistiksel veri analizinde R'yi, sinyal işleme gibi derslerde MATLAB'i gördüğünü; biyoenformatikte ise Perl kullanılacağını, en azından bu dille tanışılması gerektiğini söyledi. Python da karşılaştırmalı olarak ele alınacaktı.

### 6.1 Öğrenme hedefleri

Slayttaki hedefler (ekrandan, 01:05:00): bu dersten sonra şunlar anlaşılmalıdır:

- sıra, yineleme ve seçim (sequence, iteration and selection);
- programlamanın temel yapı taşları;
- üç C: sabitler, yorumlar ve koşullar (constants, comments and conditions);
- değişken kaplarının kullanımı (variable containers);
- bazı Perl işleçleri ve örüntü eşleme (pattern-matching) teknolojisi.

### 6.2 Bilgisayarın bileşenleri

Hoca, modern bilgisayarların iki ana bileşen etrafında düzenlendiğini söyleyip bunların ne olduğunu sordu (bkz. Örnek Sorular). Cevap donanım ve yazılımdır: donanım vardır, böylece yazılım bir şey yapabilir. Bu modern bilgisayarın çok genel bir tanımıdır.

Hesaplama sistemleri genellikle işlev ve yapı açısından tanımlanır:

- İşlevler: veri işleme, veri saklama, veri taşıma ve denetim.
- Yapı: CPU (işlemci), bellek, giriş/çıkış sistemi ve sistem bağlantısı (veri yolu, bus).

Hoca bilgisayarın bir "elektronik dâhi" değil, bir "elektronik aptal" olduğunu söyledi: dâhinin yaratıcılığı vardır, bilgisayarın yoktur. Bilgisayar ne söylenirse tam olarak onu yapar, fazlasını yapmaz.

### 6.3 Kuramda ve uygulamada hesaplama

Kuramda bilgisayar, hesaplanması mümkün olan her şeyi, yeterli bellek ve zaman verilirse hesaplayabilir (ekrandan, 01:10:00). Basit bir bilgisayar, bir süper bilgisayar ya da basit bir hesap makinesi, yeterli zaman ve bellekle aynı şeyi hesaplar; aynı probleme aynı çözümü vermek üzere tasarlanmıştır. Aynı probleme farklı çözümler çıkıyorsa bir şeyler yanlıştır.

Uygulamada problem çözmek kısıtlar altında hesaplama yapmak demektir. Üç ana kısıt zaman, maliyet ve güçtür; sonuç belirli bir süre içinde alınmalıdır.

### 6.4 Teknoloji katmanları

Bir hesaplama sistemindeki teknolojiler katmanlar olarak gösterilebilir. En üstte uygulamalar, altında araçlar, onun altında işletim sistemi vardır; bunlar yazılımdır. En altta donanım vardır; donanım fare, ekran, klavye gibi çevre birimlerine, ağa ya da başka bilgisayarlara bağlıdır. Katmanların açıklaması (ekrandan, 01:15:00):

- İşletim sistemi: donanımla doğrudan etkileşir; donanım kaynaklarının verimli kullanılmasından sorumludur. Donanım ile kullanıcı ya da diğer uygulamalar arasında arayüz yazılımıdır.
- Araçlar: işletim sisteminin sunduklarından yararlanan yazılımlardır; programlama dilleri, veritabanları, editörler, arayüz oluşturucular.
- Uygulamalar: yazılımın en kullanışlı kategorisidir; web tarayıcıları, e-posta istemcileri, web sunucuları, kelime işlemciler.

Hoca, araçları kullanabilmek için en azından eğitimli olmak gerektiğini; işletim sistemi düzeyinde üretken olmak ve arayüzler yazmak için ise yalnız yazılımda değil donanımda da gerçekten uzman olmak gerektiğini söyledi.

### 6.5 Problemden komutlara: her düzeyde seçim

Bir problem için birden fazla çözüm olabilir. Önce bir çözüm seçilir; örneğin karekök bulmak için sayısal analizden hatırlanan birçok algoritma vardır ve bunlardan biri, örneğin Newton-Raphson yöntemi seçilir. Ardından algoritma bir dilde yazılır ve derleyici gibi araçlarla işlemcinin komut kümesi mimarisine çevrilir.

Her düzeyin kendi gereksinimi vardır:

- Algoritma düzeyi: adım adım bir yöntemle tanımlanır; belirsizlik olmamalı ve sonlu olmalıdır.
- Programlama dili: algoritmanın bir bilgisayar dilinde ifadesidir.
- Komut kümesi mimarisi (ISA): bilgisayarın yapabileceği komutları belirtir; veri türleri ve adresleme kipleri önemlidir; belirli mimariyle sınırlıdır.

Her düzeyde birçok seçenek vardır (ekrandan, 01:20:00):

```text
Solve a system of equations
├── Red-black SOR
├── Gaussian elimination
│   ├── FORTRAN
│   ├── C
│   │   ├── PowerPC
│   │   ├── Intel x86
│   │   └── Atmel AVR
│   ├── C++
│   └── Java
├── Jacobi iteration
└── Multigrid
```

Hoca ayrıca bir toplayıcının (adder) iki farklı devre yaklaşımıyla gerçeklenebileceğini örnek verdi.

<!-- BELİRSİZ: Toplayıcı gerçekleme yaklaşımlarının adları altyazıda bozuk ("keri-adır"); büyük olasılıkla ripple-carry ve carry-lookahead toplayıcılar kastediliyor. -->

### 6.6 Bilgisayar düzey hiyerarşisi ve diller

Bilgisayar düzey hiyerarşisi yedi katmanlı bir şekille gösterildi. Hoca katmanların çoğunun sanal (yazılım), yalnız birinin fiziksel olduğunu söyledi.

<!-- BELİRSİZ: Yedi katmanlı hiyerarşi şeklinin karesi yok; altyazıdaki sayılar bozuk. -->

Program bir adımlar dizisi olarak tanımlanabilir: her adımda mantıksal ya da aritmetik bir komut vardır ve komutlar sırayla yürütülür.

Diller şöyle sınıflandırıldı (ekrandan, 01:25:00):

```text
C, Fortran, Ada, etc.  ->  Compiler  ->  Assembly Language  ->  Assembler
Basic                                                       ->  Interpreter
Java  ->  Compiler  ->  Byte Code                           ->  Interpreter
```

- C, Fortran, Ada derlenen (compiled) dillerdir.
- Basic yorumlanan (interpreted) bir dildir.
- Java platformdan bağımsız bir dil olarak anılır. Java'da da bir derleme vardır, ama Java derleyicisi mimariye özgü çalıştırılabilir kod üretmez; işlemci mimarisinden bağımsız bayt kodu (byte code) üretir. Belirli bir mimarideki çalışma ortamı bu bayt kodunu alıp çalıştırır. Bu yüzden bayt kodu platformdan bağımsızdır, ama çalıştırmak için yine de Java çalışma ortamı (JRE) gerekir.

## 7. Programlama ve üç temel yapı

### 7.1 Programlama ve hata ayıklama

Programlama, istenen işlevi yerine getiren bilgisayar programları oluşturma yöntemleridir. Problem çözmeyi içerir: bilgisayara ne yaptıracağımıza nasıl karar verdiğimizdir. Problem tanımı adım adım iyileştirme ile algoritmaya, algoritma da makine komutlarına çevrilir.

Programlamanın önemli adımlarından biri hata ayıklamadır (debugging): program çalışmadığında nedenini bulma sürecidir. Yazmaçları ve belleği incelemeyi, kesme noktaları (breakpoint) koymayı içerir.

### 7.2 Adım adım iyileştirme

Adım adım iyileştirme (stepwise refinement) sistematik bir ayrıştırmadır:

- Problem tanımıyla başlanır.
- Görev birkaç basit alt göreve bölünür.
- Her alt görev daha küçük alt görevlere, onlar da daha küçüklerine bölünür; makine komutu düzeyine inilene kadar sürer.

Problem tanımları İngilizce (doğal dille) yazıldığı için bazen belirsiz ya da eksiktir. Bu sorunları çözmek için problemi çözülmesini isteyen kişiye sorulur ya da bir karar verilip belgelenir.

### 7.3 Üç temel yapı

Programlama dillerindeki üç temel yapı şunlardır:

- Sıra (sequential): alt görevler sırayla yürütülür.
- Koşul (conditional): bir koşul sınanır; doğruysa bir alt görev, yanlışsa başka bir alt görev yürütülür. Programın akışı doğrusal değildir. Tipik deyimler `if`, `else` gibi deyimlerdir.
- Yineleme (iterative, loop): bir sınama koşulu vardır; koşul doğru olduğu sürece belirli bir görev yürütülür. Sınama sonucuna göre akış belirli bir adrese yönlendirilir ve oradan devam eder. Tipik deyimler `for`, `do`, `while`, `repeat` gibi deyimlerdir.

### 7.4 Neden program yazarız?

Program, elle yapılan bilgisayar işini otomatikleştirmek için yazılır; programlama bir tür otomasyon gerçeklemesidir. Zaman kazandırır ve hataları azaltır. Hocanın örneği: 100 veri dosyasını indirmek için veri sitesine 100 kez gidip dosyaları tek tek indirmek yerine basit bir betik yazıp indirmeyi otomatikleştirmek.

## 8. Perl ve Python

### 8.1 Neden Perl, neden Python?

Hoca, Python'ın çok popüler hale geldiğini, bu yüzden Python'ın özelliklerini de karşılaştırmalı olarak vereceğini söyledi. Perl'in temellerini öğrenmek oldukça kolaydır ve özellikle metinle çalışmak için güçlü işlevleri vardır; dil zaten metin bilgisini işlemek için ortaya çıkmıştır. Python da öğrenmesi ve kullanması kolay bir dildir; olgun ve destekleyici bir topluluğu vardır, sorun yaşandığında topluluktan yardım almak olasıdır; yüzlerce kütüphane ve çatı (framework) sunar.

### 8.2 Perl ve Python nedir?

Slayttaki karşılaştırma (ekrandan, 01:40:00):

- Perl:
  - Practical Extraction and Report Language'in kısaltmasıdır; güçlü metin işleme işlevleri vardır.
  - İlk olarak Larry Wall tarafından NASA'nın JPL'inde Unix sistemlerinde e-posta işlemek için yazılmıştır; hocanın deyişiyle e-posta da temelde metindir.
  - "Yapıştırıcı" (glue) dil olarak başlamıştır; birçok kişi ve birçok biyolog tarafından genişletilmiştir.
  - Birkaç dilin en iyi özelliklerini birleştirir.
  - Slayttaki güncel kararlı sürüm: Perl 5.32.1.
  - Perl sloganı TMTOWTDI'dir: "There's More Than One Way To Do It"; hoca bir görevi yapmanın genelde en az üç yolunun bulunduğunu söyledi.
- Python:
  - Bir kısaltma değildir; adını Monty Python komedi grubundan alır.
  - 1980'lerin sonunda Guido van Rossum tarafından ABC programlama dilinin ardılı olarak tasarlanmıştır.
  - Nesne yönelimli bir dil olarak tasarlanmıştır.
  - Slayttaki güncel kararlı sürüm: Python 3.9.2.
  - Temel felsefe (Zen of Python): güzel çirkinden iyidir; açık örtükten iyidir; basit karmaşıktan iyidir; karmaşık girift olandan iyidir; okunabilirlik önemlidir.

Hoca, bir dilin başladığı halde popüler olmadan ölebileceğini ya da daha gelişmiş dillere evrilip ad değiştirebileceğini, ABC'nin de böyle bir dil olduğunu belirtti.

### 8.3 Kullanım alanları

Perl web sayfası üretiminde kullanılan CGI programlamada, güçlü metin işlemede (bir kaynaktan veri çıkarıp başka bir biçime çevirmede) ve veritabanı işlemede kullanılır; veri yönetimi kolaydır. Python'ın kullanım alanları arasında hızlı uygulama geliştirme, platform geliştirme, sistem araçları, internet programlama ve veritabanı programlama sayıldı.

### 8.4 Kurulum ve yardım

Perl için bir geliştirme ortamı ve paket kurulumu gösterildi. Kurulumu denetlemek için `perl -v` yazılır; `v` sürüm (version) demektir. Komut satırından başka modüller de kurulabilir. Python kurulumu da kolaydır: Python paketi indirilir. Yaygın Python IDE'leri arasında Spyder, Jupyter, Thonny, Atom gibi ortamlar sayıldı; Python komut satırından ya da bir tümleşik geliştirme ortamından kullanılabilir. Kurulumu denetlemek için `python --version` yazılır.

Yardım almak için Perl'de `perldoc` kullanılır: `perldoc -f` ile bir işlevin, `perldoc -q` ile sık sorulan sorularda bir anahtar sözcüğün belgesine bakılır. Python biraz farklıdır: `help()` yazılarak yardım ortamına geçilir ve orada işlevin adı yazılır.

<!-- BELİRSİZ: perldoc komutlarının tam yazımı altyazıda bozuk ("pergob q"); karede yok. -->

Perl ve Python betik (scripting) dilleri olarak da anılır; kod belirli bir makine koduna değil, özel bir sanal makine koduna çevrilir.

### 8.5 Perl/Python kodu nasıl yazılır?

Slayttaki adımlar (ekrandan, 01:50:00):

- Bir çalışma klasörü (dizin) oluşturun.
- Notepad'i (ya da herhangi bir metin editörünü) açın ve kurallara uyarak Perl/Python kodunu yazın.
- Dosyayı uygun uzantıyla kaydedin: Perl için `pl` ya da `plx`, Python için `py`.
- Dosya yöneticisinde dosyaya çift tıklayın.

Çift tıklandığında komut satırı penceresi çok kısa bir an görünüp kaybolabilir. Bunun yerine Windows'ta CMD ile komut satırına geçilip program `perl` komutuyla çalıştırılabilir. Program, bir IDE'nin çalıştırma seçeneğiyle IDE içindeki bir pencerede de çalıştırılabilir.

Bir Perl betiğinin neye benzediğini göstermek için basit bir `print` örneği verildi: program satırları sırayla işler ve üç satırlık bir selamlama çıktısı üretir. `\n` satır sonudur. Aynı programın Python sürümü de gösterildi; hoca iki dilin biçiminin aşağı yukarı aynı karmaşıklıkta olduğunu, Python'ın birkaç seçenek sunduğunu ve üretilen çıktının aynı olduğunu söyledi.

<!-- BELİRSİZ: Selamlama programının kodu ve çıktı metni karelerde yok; altyazıdaki kelimeler bozuk. -->

## 9. Hata ayıklama

### 9.1 Hata ayıklamanın doğası

Hata ayıklama, hataları bulma ve düzeltme sürecidir. Özel bir beceri gerektirir ve iyi olmak için pratik yapmak gerekir. Yeni başlayan programcılar arasında, saatler gibi gelen bir süre boyunca kafayı klavyeye vurup sonunda sorunun aslında betiğin bakılan yerden bambaşka bir kısmında olduğunu keşfetmek yaygındır.

Perl (ve Python dahil birçok dil) hatanın nerede olduğunu söylemek için elinden geleni yapar (ekrandan, 02:10:00). Bu diller programcının işini kolaylaştırmaya çalışan gelişmiş dillerdir; bu yüzden hata iletileri dikkatle okunmalıdır. Bazen birden çok satırlık hata verilir; sonraki hatalar ilk hatanın tetiklediği ardışık hatalar olabilir.

> **Hocanın vurgusu:** Hata iletilerini gerçekten dikkatle okuyun.

### 9.2 `-c` anahtarı

Perl'de hata ayıklama oldukça güçlüdür. Derleme ve çalıştırma anahtarları kullanılabilir. `-c` (check) anahtarı, `perl -c betik_adı` biçiminde, betiği çalıştırmadan derlemeye çalışır ve sözdizimini denetler; uyarı özelliğini çalıştırmaz. Sözdizimi doğruysa "syntax OK" iletisi verir; programı çalıştırmaz ama hata ayıklamaya yardım eder.

Bir örnekte `print "merhaba\n";` deyiminin kapanış çift tırnağı eksik bırakıldı. `-c` ile çalıştırıldığında Perl "Can't find string terminator" iletisi verir: bir dizge çift tırnakla başlamış, ama sonlandırıcı eksiktir.

### 9.3 Sözdizimi ve anlam hataları

Programlama dillerinde hatalar genelde ikiye ayrılır: sözdizimi (syntax) hataları ve anlam (semantics) ya da mantık hataları (ekrandan, 02:15:00). Bir Perl programı (ya da herhangi bir program) sözdizimi açısından doğru, anlam açısından yanlış olabilir. Anlam dilin ne demek istediğiyle ilgilidir ve genelde mantık hatası diye bilinir.

Gösterilen örnekte sözdizimi tamamen doğruydu, `-c` anahtarı mantık hatasını belirleyemedi. `-w` (warning) anahtarı ise Perl'e, betikte sorun olabileceğini düşündüğü şeyler hakkında uyarı vermesini söyler. Betik `-w` ile yeniden çalıştırıldığında Perl iki uyarı verir:

- "Useless use of a constant ... in void context": `merhaba` dizgesi boş bağlamda kullanılmıştır.
- "Use of uninitialized value ... in print": `print` başlangıç değeri olmayan bir değeri basmaya çalışmaktadır.

Hocanın açıklamasına göre sorun, `print` sözcüğünün hemen ardından deyim sonu işareti olan noktalı virgülün gelmesidir; ondan sonra yalnız bir dizge sabiti ve deyim sonu kalır ve bu hiçbir şey yapmaz.

> **Ek bilgi (derste anlatılmadı):** `print ; "merhaba\n";` biçimindeki bir satır bu iki uyarıyı üretir: ilk deyim öntanımlı değişken `$_`'yi basmaya çalışır (değeri yoktur), ikinci deyim yalnız bir dizgedir. Satır ajan tarafından perl ile denenmiştir; slayttaki satır karede görülmediği için büyük olasılıkla buna benzer bir satırdır.

Anahtarlar birleştirilebilir: `-cw` hem sözdizimi denetimini hem uyarıları açar. Böyle çalıştırıldığında hem önceki uyarılar hem "syntax OK" iletisi alınır.

### 9.4 `use strict` pragması

Perl ve büyük olasılıkla Python gibi bazı dillerde, C ya da Java'nın tersine, programın başında değişkenleri bildirmek gerekmez. C'de bütün değişkenler ve işlevler başta bildirilir. Perl'de bildirimi zorunlu kılmak için betiğin başına `use strict;` yazılır. Slayttaki açıklama (ekrandan, 02:20:00):

- Betiğin başına yakın `use strict;` satırını koyarak Perl'e daha yüksek bir standarda uymaya istekli olduğunuzu söylersiniz.
- Özellikle bütün değişkenleri kullanmadan önce bildirmeye istekli olduğunuzu söylersiniz.
- Bu, değişken adlarındaki yazım hatalarına karşı korur: betik ilk derleme aşamasında bildirilmemiş bir değişkenle karşılaşırsa hata iletisiyle durur.
- Ayrıca değişkenlere uygun kapsam (scope) vermenizi, görünürlüklerini sınırlamanızı sağlar; böylece betiğin başka yerindeki aynı adlı değişkenlerle etkileşebilecek "global" değişkenler oluşmaz.
- Bütün bunlar hata ayıklama süresinde büyük kazanç demektir.

### 9.5 Python'da hata ayıklama

Python da iyi hata ayıklama olanakları sunar. Python'ın yerleşik hata ayıklayıcısı `pdb`'dir: ana işi yapan, komut satırı arayüzlü basit bir araçtır. Python, Perl'den biraz farklı bir yol izler. `pdb` komutları arasında `list`, `up`, `down`, `step`, `next`, `break` gibi komutlar sayıldı. Amaç, geliştirme süresini olabildiğince kısaltmaktır.

## 10. İlk Perl programları: sabitler, değişkenler, seçim

### 10.1 İlk program

İlk Perl programında hoca şunları açıkladı:

- Perl'de `#` ile başlayan her satır yorumdur ve Perl tarafından yok sayılır.
- İlk satırın başındaki `#!` Unix'e dosyanın nasıl çalıştırılacağını söyler; bu satıra shebang satırı denir. Bu durumda dosya, belirtilen dizinde bulunan Perl yorumlayıcısına verilmelidir. Çoğu öğrenci Windows kullandığı için bu satır genelde önemsenmez.
- `\n` yeni satır (satır sonu) yönergesidir.
- Program tek bir deyimden oluşabilir: örneğin "Welcome to the Wonderful World of Bioinformatics!" yazdıran bir `print` deyimi.

Aynı çıktıyı üreten başka bir sürüm (ekrandan, 02:25:00):

```perl
print "Welcome ";
print "to ";
print "the ";
print "Wonderful ";
print "World ";
print "of ";
print "Bioinformatics!";
print "\n";
```

Slayttaki komut satırı penceresinde önce `perl -cw welcome2.pl` çalıştırılmış ve "welcome2.pl syntax OK" iletisi alınmış, sonra `perl welcome2.pl` ile program çalıştırılıp şu çıktı elde edilmiştir:

```text
Welcome to the Wonderful World of Bioinformatics!
```

(Kod ve çıktı ajan tarafından perl ile çalıştırılarak doğrulandı.)

### 10.2 Yineleme: `while` ve sabitler

Sonraki örnek, selamlamayı bir `while` döngüsü içinde tekrar tekrar yazdıran ve her yazdırmadan sonra `sleep 1` ile bekleyen bir programdı. `sleep` bilgisayarı bir saniye bekleten bir işlevdir. Hoca yineleme ile döngünün aynı kavram olduğunu, bunun daha önce anlatılan yineleme yapısının `while` ile Perl'deki karşılığı olduğunu hatırlattı.

<!-- BELİRSİZ: Bu programın kodu karelerde yok. -->

İlk örnekte iki sabit tanımı vardı: biri doğru (true), öteki yanlış (false) sabiti. Perl, `while` yapısı içinde 1 değerini doğru, 0 değerini yanlış olarak okur.

Sabit (constant), program içinde değeri hiçbir koşulda değiştirilemeyen bir kaptır; adı da bunu söyler. Zorunlu olmasa da sabitlere bütünüyle büyük harfli adlar vermek bir gelenektir. Perl büyük-küçük harfe duyarlıdır: büyük harfle ve küçük harfle yazılmış aynı ad iki farklı sabittir, eşit sayılmaz.

### 10.3 Değişken kapları

Slayttaki açıklama (ekrandan, 02:30:00):

- Sabitin karşıtı değişken kabıdır (variable container), kısaca değişken.
- Bir değişkenin değeri programın ömrü boyunca değişebilir; bir an 1 atanır, sonra -1 ya da başka bir şey olabilir.
- Bir öğenin değerini değiştirmek gerektiğinde değişken kabı kullanılır.
- Perl her tür değişken kabını çok iyi destekler.
- En basit değişken kabı türü skalerdir (scalar). Skalerler bir sayı, bir kelime, bir cümle ya da bir disk dosyası tutabilir.

Hoca değişkenlerin ileride ayrıntılı ele alınacağını, burada programlarda kullanıldığı için kısa bir giriş yapıldığını söyledi. Döngü değişkenlerle yeniden düzenlenirse daha denetlenebilir bir döngü elde edilir: ikinci yineleme programı bir sayaç skalerini 0'a ilkler ve döngüyü 10 kez çalıştırır. `$count++` gösterimi diğer dillerdeki gibi bir artırmadır (auto-increment).

Perl'de başlangıç değeri verilmeden kullanılan bir değişken, sayısal bir nicelik için kullanılıyorsa 0 kabul edilir. Bu kullanışlı olabilir, ama değişken kaplarına açık bir başlangıç değeri vermek her zaman iyi bir fikirdir. Kısa programlarda denetim kolaydır; yüzlerce satırlık programlarda ise değişkenleri ilklemek, sonradan kodu denetlemeyi kolaylaştırır.

> **Hocanın vurgusu:** Değişkenlere her zaman açık bir başlangıç değeri verin.

### 10.4 Seçim (koşul)

Programlamanın temel yapı taşlarından biri seçim ya da koşullardır. Bir seçim mekanizması, programın birkaç olası eylem yolundan ya da akıştan birini seçmesini sağlar. Perl'deki genel biçim, C'deki `if` deyimine çok benzeyen `if` deyimidir: koşul doğruysa bir sonraki deyim, doğru değilse öteki deyim yürütülür (ekrandan, 02:35:00).

Bir `while` döngüsü içinde `if` kullanan `oddeven` adlı bir örnek program anlatıldı; ardından aynı işi kötü biçimlendirilmiş biçimde yapan `terrible` programı ve başka bir yapı kullanan `oddeven2` gösterildi. Üçü aynı çıktıyı üretir.

`terrible` programı (komut satırı çıktısından, ekrandan, 02:50:00):

```perl
#! /usr/bin/perl -w
# The 'terrible' program - a poorly formatted 'oddeven'.
use constant HOWMANY => 4; $count = 0;
while ( $count < HOWMANY ) { $count++;
if ( $count == 1 ) { print "odd\n"; } elsif ( $count == 2 )
{ print "even\n"; } elsif ( $count == 3 ) { print "odd\n"; }
else # at this point $count is four.
{ print "even\n"; } }
```

Hoca bu programın aynı işi yaptığını, ama okunmasının çok zor olduğunu söyledi.

`oddeven2` programı (ekrandan, 02:40:00):

```perl
#! /usr/bin/perl -w
# The 'oddeven2' program - another version of 'oddeven'.
use constant HOWMANY => 4;
$count = 0;
while ( $count < HOWMANY )
{
    $count++;
    if ( $count % 2 == 0 )
    {
     print "even\n";
    }
    else # $count % 2 is not zero.
    {
     print "odd\n";
    }
}
```

Bu sürüm sayıları tek tek karşılaştırmak yerine kalan (`%`) işlecini kullanır: kalan sıfır değilse sayı tektir. Döngü adım adım şöyle işler (ara adım eklendi):

| `$count` (artırmadan sonra) | `$count % 2` | Çıktı |
|---|---|---|
| 1 | 1 | odd |
| 2 | 0 | even |
| 3 | 1 | odd |
| 4 | 0 | even |

`$count` 4 olunca `$count < HOWMANY` koşulu yanlış olur ve döngü biter. İki program da ajan tarafından perl ile çalıştırıldı; ikisinin çıktısı da odd, even, odd, even'dır.

## 11. Veri dosyalarını işleme

### 11.1 Giriş işleci ve standart giriş

Perl'de giriş işleci `<>`'dir: küçüktür ve büyüktür işaretleri yan yana yazılır (ekrandan, 02:45:00). Perl bir program içinde bu işleçle karşılaştığında standart girişten (standard input) bir satır arar ve döndürür. Hoca burada başka bir giriş belirtilmediğinde standart girişin ne olduğunu sordu (bkz. Örnek Sorular). Cevap klavyedir: bilgisayar giriş işleciyle karşılaşınca klavyeden bir şey girilmesini bekler; girilip Enter'a basılınca değer döndürülür ya da bir atama varsa bir değişkene atanır.

Standart giriş, Perl'e aksi söylenmedikçe programa o anda giriş verisi sağlayan mekanizmanın adıdır; belirli bir giriş kapısı da tanımlanabilir. Giriş işleci her kullanıldığında program klavyeden bir satır alır. Örneğin girişin bir skalere atandığı bir deyimle karşılaşıldığında klavyeden bir satır okunur ve o skalere konur.

Sonraki küçük program `getlines` adını taşır ve bu deyimden yararlanır: basit bir `while` yapısı her seferinde bir satır girilmesini bekler ve girilen satırı basar.

<!-- BELİRSİZ: getlines programının kodu karelerde yok. -->

### 11.2 Standart çıkış ve standart hata

Perl'de standart girişin yanında standart çıkış da vardır. Hoca, aksi belirtilmezse standart çıkışın ne olduğunu sordu. Aksi söylenmedikçe Perl hem standart çıkış hem standart hata için ekranı kullanır. Bu üç akış kısaca STDIN, STDOUT ve STDERR diye anılır; bu adlarla giriş, çıkış ve hata iletilerinin nereye gideceği açıkça tanımlanabilir. Kullanılmazsa giriş klavye, çıkış ekrandır; ama bunlar değiştirilebilir.

### 11.3 Dosyayı giriş olarak vermek

Slayttaki komut satırı deyimi (ekrandan, 02:50:00):

```text
> perl getlines.pl oddevent.pl
```

Normalde program giriş beklerdi, ama burada standart giriş değiştirilmiştir: `getlines.pl` verilen dosyayı okur, her satırı değişkene atar ve basar. Sonuçta dosyanın tamamı ekrana basılır; slayttaki çıktı yukarıdaki `terrible` programının metnidir.

`getlines` programı standart girişi kullandığı için öntanımlı olarak klavyeden okur; adı verilen bir disk dosyasıyla birlikte kullanıldığında ise dosyanın içeriğini giriş olarak kullanır. Birden fazla dosya adı da verilebilir. Programcılar komut satırında program adından sonra gelen şeylerin listesine programın komut satırı argümanları ya da parametreleri der. Hocanın gösterdiği son çağrıda `getlines` üç komut satırı argümanı almıştı.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:18:47): Bir DNA dizisinin harf dizisi ya da sembol listesi olarak temsili veri sınıflandırması açısından nicel veri midir, nitel veri mi?

> **Cevap (derste verildi):** Nitel veridir. Bir öğrenci nicel dedi; hoca harflerin sayısal nicelik değil, karakter ve sembol olduğunu söyledi.

**Soru 2** (derste sözlü, 01:06:09): Modern bilgisayarlar hangi iki ana bileşen etrafında düzenlenir?

> **Cevap (derste verildi):** Donanım ve yazılım. Bir öğrencinin "işlemci ve bellek" cevabını hoca doğru ama yeterince kapsamlı değil diye değerlendirdi.

**Soru 3** (derste sözlü, 02:42:52): Bir programda giriş işleci (`<>`) var ve özel bir giriş belirtilmemiş. Program çalışırken bu işleçle karşılaşınca bilgisayar ne yapar? Standart giriş nedir?

> **Cevap (derste verildi):** Program durur ve giriş gelene kadar bekler. Öntanımlı standart giriş klavyedir; girilen satır döndürülür ya da bir değişkene atanır.

**Soru 4** (derste sözlü, 02:48:13): Aksi belirtilmezse standart çıkış nedir?

> **Cevap (derste verildi):** Ekran. Perl aksi söylenmedikçe standart çıkış ve standart hata için ekranı kullanır.

## Dersin Toparlaması

Dersin ilk yarısında moleküler biyolojinin temelleri tamamlandı (tRNA, merkezî dogma, gen, genom, transkriptom, proteom) ve biyomedikal verinin bilgisayarda nasıl temsil edildiği tartışıldı. DNA dizisinin nitel bir sembol dizisi olduğu, UniProt ve enzim veritabanı kayıtlarının satır kodlarıyla düzenlendiği, nükleotit dizilerinin INSDC çatısındaki GenBank, ENA/EMBL-Bank ve DDBJ'de saklandığı, dizilere erişim numaralarıyla ulaşıldığı ve genom tarayıcılarıyla gezilebildiği görüldü.

İkinci yarıda hesaplamanın temelleri (donanım-yazılım, teknoloji katmanları, her düzeydeki seçimler, derlenen/yorumlanan diller), programlamanın üç temel yapısı ve Perl ile Python'a giriş anlatıldı. Perl'de `-c`, `-w` ve `use strict` ile hata ayıklama, sabit ve değişken kapları, `while` ve `if` yapıları ile `<>` giriş işleci üzerinden standart giriş/çıkış ve dosya işleme örneklendi. Hoca, bu konulara bir sonraki derste devam edileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
