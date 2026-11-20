# Ders 3 Genişletilmiş Notu: Biyolojik Veri Tabanları ve Perl/Python ile Programlamaya Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Biyomedikal Verinin Doğası ve Gösterimi
- 2. Protein Veri Tabanları: UniProt / Swiss-Prot
- 3. Enzim Veri Tabanı
- 4. Biyolojik Veri Tabanlarına İki Bakış
- 5. DNA Dizi Verisinin Saklandığı Yerler
- 6. Ölçekler: Baz Çifti ve Dosya Boyutu
- 7. Taksonomi, EST'ler ve Erişim Numaraları
- 8. Genom Tarayıcıları ve Arama
- 9. Bilgisayar Sistemlerine Teknolojik Bakış
- 10. Problem Çözmede Soyutlama Katmanları
- 11. Programlama Dilleri ve Programlama Süreci
- 12. Üç Temel Yapı
- 13. Neden Perl ve Python?
- 14. Kurulum, Çalıştırma ve Yardım
- 15. Hata Ayıklama
- 16. İlk Perl Programının Yapısı
- 17. Yineleme, Sabitler ve Değişken Kapları
- 18. Seçim ve Tek/Çift Programı
- 19. Veri Dosyalarını İşleme: Girdi İşleci
- 20. Örüntüler ve Düzenli İfadeler
- 21. Girdi/Çıktı ve Dosya Tanıtıcıları
- 22. Perl Değişkenleri
- Örnek Sorular

## 1. Biyomedikal Verinin Doğası ve Gösterimi

Hoca derse, geçen hafta konuşulan konuyu, yani verinin bir hesaplama ortamında nasıl temsil edildiğini ve temel veri tiplerini hatırlatarak başladı. Biyomedikal veri çok çeşitlidir: DNA ve protein dizileri, kan örnekleri gibi laboratuvar verileri, tek boyutlu işaretler, iki boyutlu tıbbi görüntüler, hatta üç boyutlu video verisi. Bunların hepsi tıpta yoğun olarak kullanılır. Bunların yanında "alışılmamış" veri de vardır: dergi makalelerinden ya da kaynakçalardan gelen metinler. Bu metinler bir hastanın tanısı için yararlı bilgi içerebilir. <!-- BELİRSİZ: 00:03:17-00:05:16 arası altyazı halüsinasyon tekrarlarıyla bozuk; bu kısımdaki veri türleri listesi tam okunamadı. -->

Metin dosyalarında her karakter 8 bitle tutulur. ASCII kodunun kendisi 7 bittir; kalan 1 bit eşlik (parity) kodlaması, yani hata sezimi için kullanılır.

Baz dizileri (hoca bazen "nükleotit", bazen "baz" dediğini belirtti) iki şekilde gösterilebilir. Birincisi, diziyi harflerden oluşan uzun bir dizgi (string) olarak tutmaktır. İkincisi, her nükleotidi bir listede bir sembol olarak tutmaktır; bu durumda bütün dizi bir semboller listesi, hesaplama veri tipi açısından bir karakter listesi olur. İki görünüm aslında aynı şeydir: metin bir karakter dizisidir, ya da metin bir dizgidir. Biyoenformatik tekniklerinin önemli bir kısmı tam olarak bu tür veriyle, yani metinle uğraşır.

## 2. Protein Veri Tabanları: UniProt / Swiss-Prot

Proteinler hakkında bilgi içeren büyük sayısal veri depoları vardır. Bunların iyi bilinenlerinden biri UniProt / Swiss-Prot Bilgi Tabanıdır (Knowledge Base). Bu, İsviçre Biyoenformatik Enstitüsü'nün (Swiss Institute of Bioinformatics) bir projesidir ve veri tabanında çok büyük miktarda veri bulunur. UniProt verileri ExPASy web sitesinden (`http://www.expasy.ch`) çeşitli biçimlerde indirilebilir (ekrandan, 00:10:00). Hoca bu siteyi derste açıp gösterdi.

### 2.1 Bir Swiss-Prot Kaydının Okunması

Sonraki slaytta, insan insülininin oluştuğu öncü proteinin Swiss-Prot kaydından kısaltılmış bir alıntı gösterildi (ekrandan, 00:15:00). Kaydın başı şöyledir:

```text
ID   INS_HUMAN       Reviewed;         110 AA.
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
FT   SIGNAL        1     24
FT   PEPTIDE      25     54       Insulin B chain.
FT                                /FTId=PRO_0000015819.
FT   PROPEP       57     87       C peptide.
FT                                /FTId=PRO_0000015820.
FT   PEPTIDE      90    110       Insulin A chain.
FT                                /FTId=PRO_0000015821.
FT   DISULFID     31     96       Interchain (between B and A chains).
FT   DISULFID     43    109       Interchain (between B and A chains).
FT   DISULFID     95    100
FT   VARIANT      34     34       H -> D (in familial hyperproinsulinemia;
FT                                Providence).
FT                                /FTId=VAR_003971.
FT   HELIX        35     43
FT   HELIX        44     46
FT   STRAND       48     50
FT   STRAND       56     58
FT   STRAND       74     76
FT   HELIX        79     81
FT   TURN         84     86
FT   HELIX        91     95
FT   HELIX       105    108
SQ   SEQUENCE   110 AA;  11981 MW;  C2C3B23B85E520E5 CRC64;
     MALWMRLLPL LALLALWGPD PAAAFVNQHL CGSHLVEALY LVCGERGFFY TPKTRREAED
     LQVGQVELGG GPGAGSLQPL ALEGSLQKRG IVEQCCTSIC SLYQLENYCN
```

Karede ikinci dizi satırındaki ikinci grup "GPGASLQPL" olarak dokuz harfli okunuyor; dizinin 110 amino asit olması için bu grubun "GPGAGSLQPL" olması gerekir (ajan python ile saydı: bu düzeltmeyle uzunluk 110 olur, `DISULFID` konumları 31, 43, 95, 96, 100, 109'daki harfler `C`, 34. konumdaki harf `H` çıkar; bu da `VARIANT 34 H -> D` satırıyla tutarlıdır).

Kayıttaki kısaltmaların tamamının ne anlama geldiği ExPASy sitesindeki belgelerde ayrıntılı olarak açıklanmıştır. Hocanın örnek olarak açıkladığı alanlar şunlardır:

- `DR` kayıtları çapraz referanslardır (cross-references). Bu örnekte Gene Ontology'ye (GO) yapılan çapraz referanslardır.
- `FT` kayıtları özellik tanımlarıdır (feature descriptions). `FT` etiketinden sonra gelen adlar özellik türleridir (SIGNAL, PEPTIDE, PROPEP, DISULFID, VARIANT, HELIX, STRAND, TURN); sayılar her özelliğin dizideki başlangıç ve bitiş konumlarıdır. Örneğin insülin B zinciri 25. ile 54., A zinciri 90. ile 110. amino asitler arasındadır.
- `SQ` bölümü asıl amino asit dizisini içerir; her amino asit için bir harf vardır.

Hoca formata geri dönüp "dizi başlamadan önceki bütün bu bilgilere ne ad verilir?" diye sordu (bkz. Örnek Sorular). Asıl verinin yalnız harflerden oluştuğunu ve `SQ` satırından sonra başladığını vurguladı. Önceki kısım verinin niteliğini ve özelliklerini anlatır. Bu veri dosyasını işlemek istediğinizde bu bölümü ayıklamanız (strip) ve kalan amino asit verisini işlemeniz gerekir.

## 3. Enzim Veri Tabanı

Daha önce de söylendiği gibi birçok protein enzim olarak işlev görür. Enzimler kimyasal tepkimeleri kolaylaştıran kimyasal bileşiklerdir; hocanın deyişiyle bir anlamda tepkimelerin başlatıcısı, bir tür "ateşleyici"dir. Biyolojik olarak önemli birçok tepkime, ilgili enzim olmadan ilerlemez. Bu yüzden bir protein hakkındaki önemli bilgilerden biri işlevidir: Protein bir enzim mi, enzimse ne tür bir enzim ve hangi tepkimeleri kolaylaştırıyor?

Sonraki slaytta yine aynı web sitesinden, enzim veri tabanından küçük bir alıntı gösterildi. Örnek enzim malat dehidrojenazdı. Kayıtta `ID`, `DE`, `AN`, `CA`, `CC`, `PR`, `DR` gibi alan kısaltmaları vardır:

- `ID` ile başlayan satır enzim komisyonu numarasıdır (Enzyme Commission number); her kayda özgüdür.
- `DE` satırı enzimin resmî adıdır.
- `AN` satırları alternatif adlar ya da eş anlamlılardır; birden fazla olabilir.
- `CA` satırı, malat dehidrojenazın katalizlediği tepkimeyi bir tür stilize, simgesel biçimde verir. NAD+ ve NADH molekülleri tepkimeye katılan koenzimlerdir.
- `CC` satırı bir yorumdur (comment), açıklama içerir. Hoca, programlama dillerindeki yorumlar gibi bunun da bir bilgisayar programı tarafından kullanılmak için konmadığını söyledi.
- `PR` satırı, proteinler hakkında başka bilgiler içeren PROSITE veri tabanına çapraz referanstır.
- `DR` satırı, Swiss-Prot veri tabanındaki kayıtlara çapraz referanslar kümesidir.

<!-- BELİRSİZ: Enzim kaydı slaytı karelerde görünmüyor (00:16:38-00:19:13 arası); EC numarası ve satırların tam metni bu yüzden yazılmadı. -->

## 4. Biyolojik Veri Tabanlarına İki Bakış

Hoca biyolojik veri tabanlarına iki bakış açısıyla yaklaşılabileceğini gösterdi (ekrandan, 00:20:00):

- **Tek bir nesneyi incelemek:** Bir veri tabanında tek bir geni, proteini, DNA molekülünü ya da başka türden bir nesneyi incelemek isteyebiliriz. Örneğin insan beta globini için bir gen (HBB), bir protein dizisi, bir protein yapısı ve çeşitli varyasyon türleri için kayıtlar vardır.
- **Büyük grupları incelemek:** İnsan genomundaki bütün globin genleri ya da bilinen bütün HBB varyantları gibi büyük grupları düşünebiliriz. Ya da daha önce bir hastalıkla (örneğin otizm) ilişkilendirilmiş 100 genlik bir kümenin hasta örneklerindeki varyasyonunu değerlendirmek isteyebiliriz.

## 5. DNA Dizi Verisinin Saklandığı Yerler

Önemli bir soru, kamuya açık veri tabanlarında ne kadar DNA dizisinin saklandığı ve bu verinin nerede tutulduğudur. 1982'den bugüne nükleotit dizi verisini saklamaktan sorumlu üç ana merkez vardır:

- **GenBank:** ABD Ulusal Sağlık Enstitüsü'ne (NIH) bağlı Ulusal Biyoteknoloji Bilgi Merkezi'nde (NCBI), Bethesda'da.
- **EMBL Nükleotit Dizi Veri Tabanı / Avrupa Nükleotit Arşivi:** Avrupa Moleküler Biyoloji Laboratuvarı'nın (EMBL) Avrupa Biyoenformatik Enstitüsü'nde (EBI), Hinxton, İngiltere'de.
- **DDBJ (DNA Data Bank of Japan):** Japonya'da Mishima'daki Ulusal Genetik Enstitüsü'nde.

Bu üç kaynak (Amerikan, Avrupa ve Japon) Uluslararası Nükleotit Dizi Veri Tabanı İşbirliği (INSDC) yapısı altında koordine edilir. NCBI'daki GenBank, EBI'daki EMBL-Bank ve DDBJ'nin nükleotit koleksiyonları birlikte yönetilir.

### 5.1 NCBI, EBI ve DDBJ'nin Yapısı

NCBI, GenBank'i yaklaşık 40 moleküler ve literatür veri tabanından oluşan Entrez sisteminin bir parçası olarak barındırır. Trace Archive dizileme izlerini (sequence traces), Sequence Read Archive (SRA) ise yeni nesil dizileme verisini saklar. Biyoenformatik çalışmaları yaparken ilgili veriye bu veri tabanlarının kendi web sayfalarından erişebilirsiniz.

EBI'daki EMBL-Bank, NCBI'daki GenBank ile aynı ham dizi verisini içerir; benzer veriler EBI'daki trace arşivi ve SRA'da da tutulur.

Japonya DNA Veri Bankası'nın yapısında üç kol vardır: Trad (geleneksel bölüm), Sequence Read Archive (SRA) ve BioProject/BioSamples (ekrandan, 00:25:00). Geleneksel bölüm, aynı ham dizi verisini GenBank ve EMBL-Bank ile günlük olarak paylaşır.

Bu veri tabanlarının hepsine web üzerinden ya da EDirect gibi programlarla erişilebilir. EDirect bir komut satırı programıdır.

DNA dizi depoları her gün büyür. Hocanın gösterdiği büyüme eğrisi, çoğu veri tabanının tipik büyüme hızını gösteriyordu: Büyüme hep yukarı doğrudur ve DNA dizilemedeki ilerlemeler bu büyümeyi azaltmayacak, tersine artıracaktır.

## 6. Ölçekler: Baz Çifti ve Dosya Boyutu

### 6.1 Baz Çifti Ölçeği

DNA'nın birimi baz çiftidir. Bir baz çifti 1 bp (base pair) diye kısaltılır; ileride "1 bp" görüldüğünde bir baz çifti anlaşılmalıdır. Ölçek şöyledir:

- 1 000 baz çifti: 1 kilobaz çifti (kb), $10^3$
- 1 milyon: 1 megabaz çifti (Mb), $10^6$
- $10^9$: 1 gigabaz çifti (Gb)
- $10^{12}$: 1 terabaz çifti (Tb)
- $10^{15}$: 1 petabaz çifti (Pb)

Bu ölçekte insan genomu yaklaşık 3 milyar ($3 \times 10^9$) baz çiftidir.

### 6.2 Dosya Boyutları ve Hocanın Düzeltmesi

Hoca bayt ve katlarını "bildiğiniz bir konu" olarak hatırlattı, ama bu slaytı özellikle bir hatayı göstermek için seçtiğini söyledi. Slayttaki tablo şuydu (ekrandan, 00:30:00):

| Boyut | Kısaltma | Bayt sayısı (slaytta) | Örnek |
|---|---|---|---|
| Bayt | -- | 1 | Tek metin karakteri |
| Kilobayt | 1 kb | $10^3$ | Metin dosyası, 1000 karakter |
| Megabayt | 1 MB | $10^6$ | Metin dosyası, 1 milyon karakter |
| Gigabayt | 1 GB | $10^9$ | GenBank'in boyutu: 600 GB |
| Terabayt | 1 TB | $10^{12}$ | 1000 Genom Projesi'nin boyutu: < 500 TB |
| Petabayt | 1 PB | $10^{15}$ | NCBI'daki SRA'nın boyutu: 5 PB |
| Eksabayt | 1 EB | $10^{18}$ | Yıllık dünya çapında üretim: > 2 EB |

Hoca "Bayt sayısı" sütunundaki bütün üslü değerleri kırmızı kalemle çizdi. Bunu bir kitabın PowerPoint sunumundan aldığını ve kilobaytın $10^3$, megabaytın $10^6$ olmadığını söyledi. Doğru değerleri sorduğunda bir öğrenci "2 üzeri 10" diye cevap verdi; hoca bunu onayladı: doğru değerler $2^{10}$, $2^{20}$, $2^{30}$, $2^{40}$ … şeklindedir.

Değerler (ara adım eklendi):

$$2^{10} = 1024, \quad 2^{20} = 1\,048\,576, \quad 2^{30} = 1\,073\,741\,824, \quad 2^{40} = 1\,099\,511\,627\,776$$

> **Hocanın vurgusu:** Bir kitap okurken ya da bir web sayfasından sunum indirirken dikkatli olun; bu tür kaynaklarda hatalar olabilir.

> **Ek bilgi (derste anlatılmadı):** Bu konuda iki gelenek vardır. SI önekleri (kB, MB, GB) ondalık olarak $10^3$, $10^6$, $10^9$ anlamına gelir; disk üreticileri ve ağ hızları bunu kullanır. IEC 1998'de ikili değerler için ayrı önekler tanımlamıştır: KiB ($2^{10}$), MiB ($2^{20}$), GiB ($2^{30}$). Bellek ve işletim sistemi bağlamında "KB" çoğu zaman 1024 bayt anlamında kullanılır; hocanın düzeltmesi bu ikili kullanıma dayanır.

## 7. Taksonomi, EST'ler ve Erişim Numaraları

### 7.1 Taksonomi

Veri tabanlarında canlıların sınıflarına ilişkin bilgi de bulunur: metazoa, mantarlar, bakteriler, virüsler vb. "Taxa", "taxon" sözcüğünün çoğuludur ve ileride bu ifade kullanılacaktır. Taxon, birbiriyle ilişkili organizmaların sınıflandırıldığı biyolojik sınıflandırmadaki herhangi bir grup ya da rütbedir. NCBI veri tabanlarında bu bilgiye taksonomi tarayıcısı (taxonomy browser) adı verilen özel bir tarayıcıyla erişilebilir.

Veri tabanlarında DNA, protein, RNA (mesajcı RNA ya da diğer RNA türleri) ve protein yapıları gibi farklı veri türleri bulunur. Hoca DNA, RNA ve protein dizilerinin hepsinin metin bilgisi, yani karakter dizileri olduğunu yineledi.

### 7.2 EST'ler ve UniGene

Hoca, ekspres dizi etiketleri (EST, expressed sequence tags) en çok dizilenmiş ilk 10 organizmayı gösteren bir tablo gösterdi: insan, fare, mısır, domuz, sığır, zebra balığı, soya fasulyesi, buğday, kurbağa vb. Tabloda organizmaların yaygın adları ve EST sayıları vardı. UniGene veri tabanı EST dizilerinin kümelerini içerir. Hoca bu tablolara zaman ayırmayacağını, yalnız ne tür verilerin var olduğunu göstermek istediğini söyledi. <!-- BELİRSİZ: EST tablosunun karesi yok; organizma listesi Whisper'ın bozduğu altyazıdan çıkarıldı ve sayılar yazılmadı. -->

> **Ek bilgi (derste anlatılmadı):** EST, bir hücrede ifade edilen mRNA'dan elde edilen tamamlayıcı DNA'nın (cDNA) kısa, tek okumalık bir parçasıdır. Bir genin o dokuda ifade edildiğini gösterir ve gen keşfinde kullanılmıştır.

### 7.3 Erişim Numarası Nedir?

NCBI'da DNA, RNA ve protein dizileri hakkında bilgi içeren veri tabanlarındaki her kaydın bir erişim numarası (accession number) vardır. Erişim numarası bir diziyi tanımlamak için kullanılan bir etikettir; bir moleküler diziye karşılık gelen harf ve/veya rakamlardan oluşan bir dizgidir. Slayttaki örnekler (ekrandan, 00:35:00):

| Tür | Erişim numarası | Açıklama |
|---|---|---|
| DNA | `CH471100.2` | GenBank genomik DNA dizisi |
| DNA | `NC_000001.10` | Genomik contig |
| DNA | `rs121434231` | dbSNP (tek nükleotit polimorfizmi) |
| RNA | `AI687828.1` | Bir ekspres dizi etiketi (184'ten 1'i) |
| RNA | `NM_001206696` | RefSeq DNA dizisi (bir transkriptten) |
| Protein | `NP_006138.1` | RefSeq protein |
| Protein | `CAA18545.1` | GenBank protein |
| Protein | `O14896` | SwissProt protein |
| Protein | `1KT7` | Protein Data Bank yapı kaydı |

### 7.4 RefSeq ve NCBI Gene

NCBI ana sayfasından erişilebilen RefSeq, bir dizinin en kararlı ve üzerinde uzlaşılmış referans sürümüne karşılık gelen, uzmanlarca düzenlenmiş (expertly curated) bir erişim numarası sağlar. RefSeq tanımlayıcıları şu önekleri kullanır: tam genom ve tam kromozom `NC`, genomik contig `NT`, mRNA (DNA) `NM`, protein `NP`. <!-- BELİRSİZ: RefSeq önek tablosunun karesi yok; önekler altyazıdaki bozuk okumadan çıkarıldı. -->

NCBI Gene harika bir başlangıç noktasıdır, çünkü her gen ve protein hakkındaki temel bilgileri büyük veri tabanlarından toplar ve bütün önemli organizmaları kapsar. RefSeq de her DNA için düzenlenmiş en uygun erişim numarasını verir. Tipik bir örnek olarak NCBI sayfasında "beta globin" araması yapıldığında her türlü bilgi gelir.

> **Hocanın vurgusu:** Bu web sayfalarına girip onlarla oynayın; bunlara alışmanın tek yolu budur.

## 8. Genom Tarayıcıları ve Arama

Genomların içeriğine ve özelliklerine göz atmak için genom tarayıcıları vardır. Bunlar kromozom konumlarını açıklamalarla (annotation) birlikte görselleştirmek için tasarlanmış çok yönlü araçlardır ve bir gen gibi ilgilenilen kromozomal bir özelliğe ilişkin veriyi keşfetmek için kullanışlıdır. Öne çıkan tarayıcılar Ensembl, UCSC ve NCBI'dır. Bunların dışında, bazıları belirli organizmalar ya da molekül türleri için olmak üzere yüzlerce özelleşmiş genom tarayıcısı vardır.

> **Ders sonrası not:** Hoca UCSC tarayıcısı için "University of California, Santa Clara, sanırım" dedi. Doğrusu: UCSC, University of California, Santa Cruz'dur.

Bir gen hakkında bilgi ararken resmî gen simgesini bildiğinizden ve doğru türü seçtiğinizden emin olun; bunun için `http://www.genenames.org` ziyaret edilebilir (ekrandan, 00:40:00). Bazı aramalar özellikle zordur; örneğin binlerce histon vardır. Arama sonuçlarını sınırlamak için AND, OR gibi Boole işleçleri kullanılır. HIV-1 proteinleri arandığında çok sayıda protein ve DNA sonucu çıkar (yaklaşık 1 milyon kayıt), ama yalnız bir RefSeq erişimi vardır. Bu, RefSeq projesinin yararını gösterir.

Biyoenformatik alanı hâlâ sürekli büyümektedir; bunun bir nedeni büyük miktarda dizi verisinin ortaya çıkmasıdır. Hoca bu çalışmalarla elde edilen verinin gerçekten büyük veri (big data) sayılabileceğini söyledi. Genomik veri saklayan birçok veri tabanı ve bilgi çıkarmak için birçok yaklaşım vardır. Hoca bunun dersin ana amacı olmadığını, yalnız var olan veri tabanlarını tanıtmak istediğini, gerçek algoritmalar anlatılırken bu verilerin bir kısmının kullanılacağını söyledi.

## 9. Bilgisayar Sistemlerine Teknolojik Bakış

Aradan sonra hoca, biyoenformatikte kullanılacak programlama ortamını tanıtmaya geçti. Bu bölümde önemli olan üç "C" kavramı olduğunu söyledi: sabitler (constants), komutlar (commands) ve koşullar (conditions); bunlara değişken kaplarının kullanımı ve özellikle düzenli ifadelere dayanan Perl örüntü eşleme işleçleri eklenir.

Dersin amaçlarından biri, öğrencilerin bir programlama dilini (Perl, Python) biyoenformatik alanında bilgisayar programları geliştirmenin temel aracı olarak anlamalarını ve kullanabilmelerini sağlamaktır (ekrandan, 01:00:00). Derste Perl ve kısmen Python kullanılacaktır.

### 9.1 Bilgisayarın İki Ana Bileşeni

Hoca modern bilgisayarların iki ana bileşen etrafında düzenlendiğini hatırlatıp bunların ne olduğunu sordu. Gelen bir cevap "CPU ve GPU" idi. Hoca daha önceki benzetmeyi hatırlattı: Bilgisayarın gövdesi donanımdır (hardware). Ruhu ise yazılımdır (software); yazılım olmadan bilgisayar elektronik bir hurdadır. Bilgisayar ona tam olarak ne söylerseniz onu yapar: Programlarsınız, o da buna göre çalışır.

### 9.2 Hesaplamaya Giriş

Kuramsal olarak bilgisayar, yeterli bellek ve zaman verildiğinde hesaplanması mümkün olan her şeyi hesaplayabilir (ekrandan, 01:05:00). Belirli bir programı bir PDA'da çalıştırırsanız bir sonuç alırsınız; bir iş istasyonunda ya da süper bilgisayarda çalıştırırsanız yine aynı sonucu alırsınız. Hoca bunu hesaplama sistemleriyle ilgili bir olgu olarak vurguladı.

Pratikte ise problem çözmek, kısıtlar altında hesaplama yapmak demektir:

- **Zaman:** Hava tahmini ya da animasyonun bir sonraki karesi gibi işler zamana bağlıdır; belirli bir sonucu almak için yeterli zamanınız olmalıdır.
- **Maliyet:** Cep telefonu, otomotiv motor denetleyicisi gibi ürünlerde maliyet belirleyicidir.
- **Güç:** Hoca bunu öğrencilere sordu, gelen cevap "güç" oldu. Güç özellikle cep telefonu ya da mobil uygulamalar için önemli bir kısıttır.

İşletim sistemi donanımla doğrudan etkileşir. Görevi hesaplama sisteminin kaynaklarını denetlemek ve kullanıcıların sistemle kolay etkileşmesini sağlamaktır.

## 10. Problem Çözmede Soyutlama Katmanları

Bir bilgisayar sistemine katmanlar olarak bakılabilir. En üstte problemler vardır; problemler algoritmalara kodlanır, algoritmalar dillerle ifade edilir. Bu ifadeler komut kümesi mimarisine (instruction set architecture, ISA) dönüştürülür; ISA bir mikromimariyle gerçekleştirilir (farklı mikromimariler vardır); mikromimari belirli devre gerçeklemeleriyle (CMOS, yani tümleyici metal oksit yarı iletken, ya da başka bir teknoloji) kurulur; en altta aygıtların fiziksel düzeyi, yani yarı iletken fiziği vardır.

Bilgisayarla bir problemi çözmek, soyutlama katmanları arasında sistematik bir dönüşümler dizisidir (ekrandan, 01:10:00):

```text
Problem
  | Yazılım tasarımı: algoritma ve veri yapılarını seç
  v
Algoritma
  | Programlama: tasarımı bir dille ifade et
  v
Program
  | Derleme/yorumlama: dili makine komutlarına çevir
  v
Makine komutları (işlemcinin komut kümesi mimarisi)
```

Makine komutları, programın çalışacağı işlemcinin komut kümesi mimarisini kullanır. Daha derine inilebilir: ISA'nın belirli bir işlemci tasarımı, o tasarımın da belirli bir mantık devresi gerçeklemesi vardır.

Problem tanımı genellikle konuştuğumuz doğal dille yapılır. Algoritmalar ise adım adım yöntemlerdir. Hoca bir algoritmanın bitmesinin garanti olması gerektiğini, bunda hiçbir şüphe olmaması gerektiğini, başlayıp bitmesi ve kesin (definite) olması gerektiğini söyledi. Algoritma bir bilgisayar diliyle, genellikle yüksek düzeyli bir dille ifade edilir.

### 10.1 Her Düzeyde Birçok Seçenek

Hoca her düzeyde birçok seçenek olduğunu bir ağaçla gösterdi (ekrandan, 01:15:00). Problem: bir denklem sistemini çözmek.

```text
Bir denklem sistemini çöz
├── Red-black SOR
├── Gauss eliminasyonu
│   ├── FORTRAN
│   ├── C
│   │   ├── PowerPC
│   │   ├── Intel x86
│   │   │   ├── Centrino
│   │   │   ├── Pentium 4
│   │   │   └── Xeon
│   │   └── Atmel AVR
│   ├── C++
│   └── Java
├── Jacobi yinelemesi
└── Multigrid
```

Önce hangi matematiksel ya da sayısal yaklaşımın kullanılacağına karar verilir; diyelim ki Gauss eliminasyonu seçildi. Sonra bir dil seçilir (C, C++, Java, Python vb.). Sonraki düzeyde mimari seçilir: PowerPC, Intel mimarisi, bir mikrodenetleyici ya da başka bir şey. Intel mimarisi seçildiyse farklı aile üyeleri vardır: Centrino, Pentium 4, Xeon; hoca bunların artık eskidiğini, bugün i3, i5, i7, i9 gibi işlemcilerin seçilebileceğini söyledi.

Pentium 4 seçildiyse toplayıcı gibi birimlerin gerçeklemesi için de seçenekler vardır: daha yavaş ama basit bir ripple-carry toplayıcı ya da carry-lookahead toplayıcıya dayalı daha hızlı bir gerçekleme. Carry-lookahead seçildiyse bu kez hangi yarı iletken teknolojisinin kullanılacağı seçilir: Güç önemliyse CMOS; daha hızlı bir gerçekleme isteniyor ve güç önemsenmiyorsa bipolar; çok yüksek performans gerekiyorsa galyum arsenit. Hoca her zaman bir ödünleşim (trade-off) olduğunu vurguladı. <!-- BELİRSİZ: 01:15:07-01:16:27 arası altyazı kırık; CMOS seçeneğinin gerekçesi bağlamdan tamamlandı. -->

Bilgisayar sistemi düzeyler hiyerarşisiyle temsil edilir; en az yedi düzey vardır: yüksek düzey dil, assembly dili, sistem yazılımı, makine düzeyi, denetim düzeyi, mantık düzeyi vb.

## 11. Programlama Dilleri ve Programlama Süreci

Yazılım bir program ya da programlar topluluğudur; donanımın veriyi işlemesini sağlar. Hoca ekrandaki adları (C, Fortran, Ada, Java) gösterip bunların ne olduğunu sordu; bunlar elbette programlama dilleridir.

Programlama dillerinin birçok farklı sınıflandırması vardır. Bunlardan biri derlenip derlenmemelerine göredir:

- **Derlenen diller:** C, Fortran, Ada gibi diller derlenir. Derleme sonunda elde edilen şey çalıştırılabilir koddur (executable).
- **Java:** Derlendikten sonra bir bayt kodu (bytecode) elde edilir; sonra bu bayt kodun yorumlanması gerekir.
- **Yorumlanan diller:** BASIC gibi diller yorumlanan diller olarak adlandırılır.

Sonuçta makine düzeyinde, belirli bir işlemcinin komut kümesi mimarisine ait ikili sayılardan oluşan bir dizi vardır; algoritma bir dizi donanım gerçeklemesi üzerinde çalıştırılır.

Programlama, istenen bir işlevi yerine getiren bilgisayar programları oluşturma yöntemleridir. Algoritmayı makine komutlarına çevirme sürecinde hata ayıklama (debugging) kullanılır. Hata ayıklama, bir program çalışmadıysa neden çalışmadığını bulmaktır. Hoca ilk aşamaya (tasarıma) zaman ayırırsak ikinci aşamada harcanan zamanı azaltabileceğimizi söyledi.

### 11.1 Adım Adım İyileştirme

İyileştirme (refinement), sistematik ayrıştırma (systematic decomposition) olarak da bilinir. İlk problem tanımıyla başlanır. Görev birkaç basit alt göreve ayrıştırılır; alt görevler daha küçük alt görevlere, onlar daha da küçüklerine bölünür ve bu, makine komutu düzeyine inene kadar sürer. Böylece varsa bir sorun belirlenebilir.

Problem tanımları İngilizce (doğal dille) yazıldığından bazen belirsiz ve/veya eksiktir. Hocanın örneğindeki bir dosyada karakter sayma problemi için sorulması gereken sorular:

- Dosya nerede?
- Ne kadar büyük?
- Sona geldiğimi nasıl anlarım?
- Sonuç sayısı nasıl yazdırılmalı, onluk sayı olarak mı?
- Karakter bir harfse hem büyük hem küçük harf geçişlerini saymalı mıyım?

Bu sorunlar ya problemin çözülmesini isteyen kişiye sorularak ya da bir karar verilip belgelenerek çözülür.

## 12. Üç Temel Yapı

Hoca klasik bir programlama dilinde programı oluşturan üç temel yapının ne olduğunu sordu. Bir öğrenci döngüyü söyledi; hoca bunu onaylayıp koşullu ifade olan `if`'i ve koşulsuz, döngüsüz basit deyimler olan doğrusal (linear) deyimleri ekledi. Bir görevi ayrıştırmanın üç temel yolu vardır (ekrandan, 01:25:00):

- **Sıralı (sequential, doğrusal):** Alt görev 1, ardından alt görev 2 çalışır.
- **Koşullu (conditional):** Bir koşul sınanır; doğruysa alt görev 1, yanlışsa alt görev 2 çalışır, sonra akış birleşir.
- **Yinelemeli (iterative):** Alt görev 1, alt görev 2, alt görev 3 tamamen aynıysa onları sırayla yazmak yerine bir döngü kurulur ve temel yapı birçok kez çalıştırılır.

Programlamanın biyoenformatikteki yararı, aynı analizi çok sayıda benzer veri dosyası üzerinde çalıştırabilmektir; bu bir otomasyondur. Ayrıca veriyi analiz etmek, karar vermek ve yeni analiz yöntemleri oluşturmak için de programlama kullanılır.

## 13. Neden Perl ve Python?

Derste Perl kullanılacaktır, ama hoca son zamanlarda biyoenformatikte giderek daha çok Python kullanıldığını söyledi.

Perl'ün yaygın kullanılmasının nedenleri:

- Metinle çalışmak için birçok güçlü işlevi vardır. Hocaya göre bu, Perl'ün yoğun kullanılmasının ana nedenlerinden biridir: Biyoenformatikteki ana veri türü metin, yani karakter ya da dizgidir. Bu yüzden arama, ayıklama, değiştirme ya da birleştirme Perl ile çok kolaydır.
- Başka programları da denetleyebilir.
- Ücretsizdir, bütün işletim sistemlerinde kullanılabilir ve biyoenformatikte en popüler dildir.
- Çok sayıda açık modülü ve geniş kütüphaneleri vardır; birçok platformla uyumludur.
- Diller derlenen ve yorumlanan diye sınıflandırılabilir; Perl ikisinin arasındadır, derlenebilir ya da yorumlanabilir. Bu esneklik sağlar: Perl bir betik (scripting) dili, yani yorumlanan bir dil olarak kullanılabilir ya da diğer diller gibi programlar yazılabilir.

Python da özellikle büyük veri, veri bilimi ve yapay zekâda çok popüler hale gelmiştir. Öğrenmesi ve kullanması kolaydır, olgunlaşmıştır ve destekleyici bir Python topluluğu vardır. Hoca R dilinin de biyoenformatikte yoğun kullanıldığını, ama derste ele alınmayacağını söyledi.

### 13.1 Perl ve Python'un Felsefesi

Perl, "Practical Extraction and Report Language" (pratik ayıklama ve rapor dili) kısaltmasıdır. Adı güçlü metin işleme işlevlerini yansıtır. Hocaya göre Larry Wall tarafından NASA'nın Jet İtki Laboratuvarı'nda (JPL), Unix sistemlerinde kendi e-postalarını işlemek için yazılmıştır. Daha sonra birçok kişi ve birçok biyolog tarafından genişletilmiştir, çünkü bir tür metin işleme dilidir ve biyoenformatikte ana veri türü metin ve karakterdir. <!-- BELİRSİZ: Perl'ün ilk yazıldığı kurum ve amaç altyazıda kısmen bozuk; kaynaklarda Larry Wall'un Perl'ü 1987'de büyük olasılıkla Unisys'te çalışırken rapor işleme amacıyla yazdığı da geçer. -->

Perl'ün sloganı "bir işi yapmanın birden fazla yolu vardır"dır (There's more than one way to do it): Belirli bir problem için genellikle tek bir çözüm değil, birden fazla çözüm vardır.

Python ise bir kısaltma değildir; adını Monty Python komedi grubundan alır. Hocanın aktardığı Python felsefesinden ilkeler:

- **Basit, karmaşıktan iyidir:** Bu yüzden Python programları birçok başka dile göre daha anlaşılırdır.
- **Karmaşık (complex), girift (complicated) olandan iyidir:** Bu iki sözcük farklıdır. Karmaşık olan, birçok zor işi kolayca yapmanızı sağlayan şeydir ama girift değildir.
- **Okunabilirlik önemlidir:** Bir koda baktığınızda kodun ne için olduğunu ve ne yaptığını anlamak kolay olmalıdır.

Hoca Perl'ün CGI (Common Gateway Interface) programlama yeteneğinden, yani dinamik web sayfaları üretmede kullanılabilmesinden de söz etti. Güçlü metin işleme yeteneği sayesinde bir kaynaktan veri ayıklayıp onu başka bir biçime çevirmeye uygundur. <!-- BELİRSİZ: 01:35:52-01:37:15 arası altyazı kırık; Perl/Python'un ek özellikleri tam okunamadı. -->

## 14. Kurulum, Çalıştırma ve Yardım

Python için `www.python.org`, Perl için `www.perl.org` adresleri verildi. Hoca öğrencilerin Python'u büyük olasılıkla zaten kurduğunu söyledi. İki dil için de gereken tek şey bir metin düzenleyicidir: Programı bu düzenleyiciyle yazar, dilin tanımlı uzantısıyla (`.pl`, `.py`) kaydedersiniz.

İki dilin de güçlü yardım olanakları vardır. Yardım komutuna bir işlev adı yazınca ilgili bilgi gelir; Perl ve Python bu açıdan biraz farklıdır. Perl'de bir anahtar sözcük için `-q` seçeneği kullanılabilir. <!-- BELİRSİZ: Yardım aracının adı altyazıda "perm-hpm" olarak bozuk; büyük olasılıkla perldoc kastedildi. -->

### 14.1 Yorumlanan mı, Derlenen mi?

Hoca Perl ve Python'un yorumlanan mı yoksa derlenen dil mi olduğunu sordu (ekrandan, 01:40:00) ve ikisinin de yorumlanan ya da derlenen dil olarak kullanılabileceğini söyledi. Perl ve Python'un bu açıdan Java'ya benzediğini, ancak Java'nın bayt kodu ürettiğini ekledi.

> **Ders sonrası not:** Hoca Perl ve Python'un bayt kodu üretmediğini, doğrudan ilgili komut kümesi mimarisine uygun kod ürettiğini söyledi. Doğrusu: Standart Perl kaynak kodunu önce bir iç işlem ağacına (op-tree), CPython ise `.pyc` bayt koduna derler; bu ara gösterim bir yorumlayıcı ya da sanal makine tarafından çalıştırılır. Doğrudan makine kodu üretilmez.

### 14.2 Programı Çalıştırma

Hoca öğrencilerin Python'da kod yazmayı büyük olasılıkla bildiğini, bu yüzden Perl'de kod yazmayı anlatacağını söyledi. Bir çalışma klasörü oluşturulur, herhangi bir metin düzenleyici açılır ve Perl ya da Python kodu yazılır. Perl dosyası komut satırında `perl dosya.pl` yazıp Enter'a basılarak, Python dosyası `python dosya.py` yazılarak çalıştırılır. Kodları doğrudan yazıp çalıştırmak için bir tümleşik geliştirme ortamı (IDE) da kullanılabilir.

## 15. Hata Ayıklama

Bir program yazıp doğru çalışmasını sağlamada hata ayıklama önemli bir aşamadır. Hata ayıklama hataları bulup düzeltmektir; özel bir beceridir ve iyi olmak için pratik gerekir. Programlama diline, program ve algoritma kavramlarına çok iyi hâkim olmak gerekir.

Derleyiciler ve yorumlayıcılar hataları belirlemek için yerleşik yeteneklere sahiptir; bir hata varsa size bir mesaj verirler.

> **Hocanın vurgusu:** Program yazarken bir hatayı çözmeye çalışırken ilk yapılacak iş hata mesajını dikkatle okumaktır. Mesajın ne söylediğini anlamak, hatayı bulmaya ve çözmeye harcayacağınız zamanı kısaltır. Birçok kişi bir hata görünce mesajı okumadan sorunu çözmeye girişir.

Bazen birden çok satırlık hata mesajı gelir. Bu durumda ilk satır numarasına gidip hataya bakılmalıdır; başta oluşan bir hata sonraki satırlarda da hatalara yol açacağından, bir önceki satıra da bakmak gerekebilir. İlk hata düzeltildikten sonra betik yeniden çalıştırılır; sonraki hatalar çoğu zaman kendiliğinden kaybolur.

### 15.1 Perl'de Anahtarlar: `-c` ve `-w`

Perl'de hata ayıklama bazı özel anahtarlarla (switch) yapılabilir. `-c` anahtarı "check" (denetle) içindir. `perl -c betik_adi` gibi bir komut girildiğinde Perl betiği çalıştırmadan derlemeyi dener; kodda bir sorun varsa sizi uyarır. `-c` uyarı özelliklerini devreye sokmadan derleme yapar.

Slaytta hatalı bir Perl betiği gösterildi (ekrandan, 01:50:00):

```perl
print "merhaba \n;
```

Bu satır `merhabe.pl` adıyla kaydedilip çalıştırılıyordu. Hoca, `print "merhaba \n";` gibi tek satırlık doğru bir program `-c` anahtarıyla çalıştırıldığında sonucu üretmeyeceğini, yalnız sözdiziminin doğru olduğunu söyleyeceğini anlattı. <!-- BELİRSİZ: Hatalı betiğin çalıştırılınca verdiği hata mesajının slaytı karelerde görünmüyor. -->

### 15.2 Sözdizimi ve Anlam Hataları

Program yazarken iki ana tür hatayla karşılaşılır: sözdizimi (syntax) hatası ve anlam (semantic) hatası. Bir Perl programı sözdizimi açısından doğru, ama anlam açısından yanlış olabilir. Anlam, dilin anlamıyla ilgilidir: Program dilin kurallarına uyar, ama beklediğiniz işi yapmaz. Birçok dil sözdizimi hatalarını bulmak için geniş olanaklar sunar, ama çok azı anlam hataları için kaynak sağlar.

Hoca anlamsal olarak yanlış basit bir Perl betiği gösterdi: Betikte fazladan bir noktalı virgül vardı. Betik sözdizimi açısından doğrudur, ama çalıştırıldığında hiçbir şey yapmaz, doğru sonucu alamazsınız. <!-- BELİRSİZ: Fazladan noktalı virgüllü örnek betiğin kodu karelerde görünmüyor. -->

Anlam hatalarının en azından bir kısmını bulmak için "warn" (uyar) anlamına gelen `-w` anahtarı kullanılır. Perl'ün anlamsal sorunları belirlemek için bazı yerleşik özellikleri vardır. Anahtarlar birleştirilebilir: `-c` ve `-w` birlikte kullanıldığında sözdiziminin doğru olduğu, ama anlam tarafında bir sorun bulunduğu bildirilebilir.

### 15.3 `use strict` Pragması

Perl programları için daha katı kurallar uygulanabilir. Betiğin başına şu satır konur (ekrandan, 01:55:00):

```perl
use strict;
```

Bu satırla Perl'e daha yüksek bir standarda uymaya istekli olduğunuzu söylersiniz; özellikle bütün değişkenlerinizi kullanmadan önce bildirmeye (declare) hazır olduğunuzu belirtirsiniz. C ya da Java gibi dillerde asıl kodu yazmadan önce değişkenleri bildirmeniz gerekir; Perl'de gerekmez, ama `use strict` kullanırsanız gerekir.

### 15.4 Python'da Hata Ayıklama

Python'da hata ayıklama için `pdb` (Python debugger) adlı yerleşik hata ayıklayıcı kullanılır. Komut satırı arayüzü olan basit bir araçtır. Hoca slaytta bazı `pdb` komutlarını gösterdi ama bunlara zaman ayırmadan Perl'e döndü.

## 16. İlk Perl Programının Yapısı

Hoca ilk Perl programının satırlarını tek tek açıkladı: <!-- BELİRSİZ: İlk Perl programının tam kodu karelerde görünmüyor; satırlar altyazıdaki açıklamadan özetlendi. -->

- Perl `#` ile başlayan satırları yok sayar; yorum yazmak istediğinizde satıra `#` ile başlarsınız.
- İlk satır farklıdır: İlk satırın başında `#` ünlem işaretiyle (`#!`) birleşince Unix sistemine dosyanın nasıl çalıştırılacağını, yani Perl yorumlayıcısının nerede olduğunu söylersiniz (ör. `#! /usr/bin/perl -w`).
- Perl'de ve neredeyse bütün programlama dillerinde programdaki her satır bir deyim (statement) olarak bilinir. Perl deyimleri noktalı virgülle (`;`) biter ve birbirinden onunla ayrılır.
- `print` basitçe yazdırma işlevidir. Kodun içinde çift tırnak arasındaki metin kod olarak yorumlanmaz; bir dizgidir.
- `\n` yeni bir satır başlatma yönergesidir: Program dizginin içinde bununla karşılaşınca sonraki cümle bir sonraki satırdan başlar.

Hoca aynı çıktıyı üreten, farklı biçimde yazılmış bir sürümünü de gösterdi.

## 17. Yineleme, Sabitler ve Değişken Kapları

### 17.1 `while` Döngüsü

Perl'de yineleme `while` yapısıyla gerçekleştirilir. Yineleme ya da tekrar yerine birçok programcı "döngü" (loop) sözcüğünü tercih eder (ekrandan, 02:10:00). `while` yapısında parantez içindeki ifade doğru olduğu sürece yineleme sürer. Koşulu hep doğru olan bir program sonsuza dek çalışır; Ctrl+Break'e basana kadar durmaz. Bu bir sonsuz döngüdür. <!-- BELİRSİZ: Sonsuz döngü örneğinin kodu karelerde görünmüyor. -->

### 17.2 Sabitler

Döngünün sonsuz yinelemeye düşmesini önlemek için bir denetim gerekir; bunun için sabitler kullanılabilir. Perl'de 1 değeri doğru, 0 değeri yanlış kabul edilir. Sabit, değeri hiçbir koşulda değiştirilemeyen bir program kabıdır; bu bütün diller için geçerlidir.

Perl'de gelenek, sabitlere bütünüyle büyük harfli adlar vermektir. Bu zorunlu değildir. Perl büyük/küçük harfe duyarlıdır (case-sensitive); örneğin büyük harfli `TRUE`, küçük harfli `true`'dan farklıdır. Bazı diller büyük/küçük harfe duyarsızdır; bir dilin duyarlı olup olmadığına dikkat etmek gerekir.

### 17.3 Değişken Kapları ve Skalerler

Sabitin karşıtı değişken kabı (variable container), kısaca değişkendir. Değişkenin değeri programın ömrü boyunca değişebilir; bir öğenin değerini değiştirmeniz gerekiyorsa değişken kabı kullanılır.

Skalerler bir sayı, bir sözcük, bir cümle ya da bütün bir disk dosyasını tutabilir: Bir skaler değişkene basit bir tamsayı ya da kayan noktalı sayı, bir sözcük ya da dizgi, ya da tam bir disk dosyası atanabilir. Hoca bunun çok esnek olduğunu söyledi. Perl programında skalerlerin adı dolar işaretiyle (`$`) başlar; `$` ile başlayan her ad bir skaler değişkendir.

Döngü değişkenlerle değiştirildiğinde bir sabit tanımlanır: `use constant HOWMANY` ile sabite bir değer atanır. Hoca örnekte 10 atanırsa döngünün 10 yinelemeyle sınırlanacağını söyledi.

Perl'de bir değişken kabını kullanmadan önce değerini ayarlamak gerekmez. Perl'ün bir değişken kabının ilk kullanımına uyguladığı bazı kurallar vardır (ekrandan, 02:15:00):

- Perl bir skaleri sayısal bir bağlamda ilk kez kullanıldığında sıfıra ayarlar.
- Bu özellik çok kullanışlı olabilir.
- Yine de değişken kaplarına her zaman açık bir başlangıç değeri vermek iyi bir fikirdir, çünkü bu, değişkenle ilgili niyetinizi tam olarak gösterir.

## 18. Seçim ve Tek/Çift Programı

Programlamanın temel yapı taşlarından biri seçim (selection) ya da koşuldur. Seçim mekanizması, programın birkaç olası eylem yolundan birini seçmesini sağlar. Genel biçimi `if`'tir ve başka dillerdekine çok benzer: Bir koşul vardır; doğruysa bir sonraki deyim, değilse diğer deyim yapılır. Hoca `if` yapısının `while` döngüsü içinde nasıl kullanıldığını gösterdi; böylece programcı yineleme üzerinde daha fazla denetime sahip olur.

Perl'ün "bir işi yapmanın birden fazla yolu vardır" sloganına uygun olarak, tek/çift sayıları yazan program üç farklı biçimde yazıldı. İkinci sürüm daha kısadır ve modülo (kalan) işlecini kullanır. Üçüncü sürüm ise modülo işlemini doğrudan `print` deyiminin içinde yapar ve diğer ikisinden çok daha kısadır. Üç programın da çıktısı aynıdır. <!-- BELİRSİZ: Üç tek/çift programının slaytları karelerde görünmüyor; aşağıdaki "terrible" sürümü 02:25:00 karesinden alındı. -->

Programın "kötü biçimlendirilmiş" (terrible) bir sürümü, sonraki bölümde girdi dosyası olarak kullanıldığı için ekranda tam olarak göründü (ekrandan, 02:25:00):

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

Programın işleyişi (ara adım eklendi): `HOWMANY` sabiti 4, `$count` başlangıçta 0'dır. Her yinelemede `$count` bir artırılır ve değeri 1, 2, 3, 4 olur; 1 ve 3 için `odd`, 2 ve 4 için `even` yazılır. `$count` 4 olduğunda `$count < HOWMANY` koşulu yanlış olur ve döngü biter. Program ajan tarafından `perl` ile çalıştırıldı; çıktısı:

```text
odd
even
odd
even
```

## 19. Veri Dosyalarını İşleme: Girdi İşleci

Biyoenformatikte veri dosyalarıyla çalışılır; bu yüzden bir veri dosyasının Perl programına nasıl okunacağını bilmek gerekir. Perl'de girdi işleci `<>`'dir (ekrandan, 02:20:00):

- Perl bu işleçle karşılaşınca standart girdiden (standard input) bir girdi satırı arar ve döndürür. Standart girdi, o anda programa girdi verisi sağlayan mekanizmanın adıdır.
- Perl'e aksi söylenmedikçe varsayılan girdi mekanizması klavyedir. Belirli bir girdi belirtmezseniz klavye kullanılır, ama girdi verisini bir dosyadan alacak şekilde değiştirebilirsiniz.
- Girdi işleci her kullanıldığında program klavyeden bir veri satırı alır.

Hoca programda bir satırın klavyeden okunup bir skalere atandığı bir deyim gösterip ne yapacağını sordu. Cevabı şuydu: Program sizin klavyeden bir şey girmenizi bekler. Bir metin, sayı ya da dizgi girip Enter'a basınca girdiğiniz şey `$line` adlı skaler değişkene atanır. Bunu kullanan küçük `getlines` programı, kullanıcıdan bir satır alır ve ekrana yazar.

Perl'de sayıların yanında dizgilerin de doğruluk değeri vardır: Hiç karakter içermeyen dizgi yanlış, diğerleri doğrudur. Perl'de standart girdiye ek olarak standart çıktı (terminal ekranı) ve standart hata da vardır; kısaca STDIN, STDOUT, STDERR. Hoca bunun C diline çok benzediğini söyledi.

### 19.1 Girdiyi Dosyadan Almak

Hoca şu komut satırı deyiminin ne yaptığını sordu (ekrandan, 02:25:00):

```text
> perl getlines.pl oddevent.pl
```

Bu komutla `getlines` programı bu kez tek/çift programının içeriğini okur, her satırı `$line` skalerine atar ve ekrana yazar. Yani girdi aygıtı klavye yerine bir veri dosyası olmuştur. `getlines` standart girdiyi kullandığı için varsayılan olarak klavyeyi kullanır; ama adı verilmiş bir disk dosyasıyla birlikte kullanıldığında girdi olarak o dosyanın içeriğini kullanır. Okunacak birden fazla adlandırılmış disk dosyası da verilebilir. Komutun ekrandaki çıktısı, yukarıda verilen "terrible" programın kaynak kodunun kendisidir.

## 20. Örüntüler ve Düzenli İfadeler

Perl'ün içinde bir dil daha vardır: Bu "dil içindeki dil", Perl'ün düzenli ifade (regular expression) ve örüntü eşleme (pattern matching) teknolojisini yoğun olarak kullanır. Perl'ün çevrim içi belgeleri düzenli ifadeyi kısaca bir örüntüyü tanımlayan bir dizgi olarak tanımlar. Örüntü, neyin eşleşmesinin umulduğunu belirtir; örüntüyü bulma işini ise Perl üstlenir.

Hoca burada dilleri sınıflandırmanın başka bir yolunu anlattı:

- Programcının ne istendiğini belirtmesine izin veren, işin nasıl yapılacağını teknolojiye bırakan dile bildirimsel (declarative) dil denir.
- Programcının sonuca nasıl ulaşılacağını tam olarak belirtmesini gerektiren dile yordamsal (procedural) dil denir.

Perl bu açıdan da ikisi olarak kullanılabilir; tıpkı yorumlanan/derlenen ayrımında olduğu gibi arada bir dildir.

### 20.1 `patterns` Programı

`patterns` programı, döngü bloğundaki `print` komutu dışında `getlines` programına çok benzer (ekrandan, 02:30:00):

```perl
print $line if $line =~ /even/;
```

Bu satırın Türkçe karşılığı: `$line` adlı skaler "even" örüntüsünü içeriyorsa ve yalnız o zaman `$line` skalerinin içeriğini göster. Bu deyimde `=~` bağlama işleci (binding operator) olarak adlandırılır. Bağlama işleci bir şeyi (bir değişken kabını) bir örüntüyle karşılaştırır. Örüntü, eğik çizgi (`/`) karakterleriyle çevrili herhangi bir karakter dizisi olarak tanımlanır. `$line`'ın içeriği satırın herhangi bir yerinde "even" örüntüsünü içeriyorsa eşleşme var denir.

Programcılar ilgilenilen bir şeyi çevreleyen karaktere sınırlayıcı (delimiter) der; buradaki `/` karakteri örüntüyü sınırlar ve düzenli ifade örüntüleri için varsayılan sınırlayıcıdır.

`patterns` programı tek/çift programı veri dosyası olarak verilerek çalıştırıldığında yalnız "even" içeren satırlar ekrana basılır. Ajan bunu, döngü kısmını kendisi yazarak (`while ( my $line = <> ) { ... }`, derste karede görünmedi) yukarıdaki "terrible" programla test etti; basılan satırlar şunlardır:

```text
# The 'terrible' program - a poorly formatted 'oddeven'.
{ print "even\n"; } elsif ( $count == 3 ) { print "odd\n"; }
{ print "even\n"; } }
```

İlk satır "oddeven" sözcüğünün içinde "even" geçtiği için eşleşir. Hoca düzenli ifadeler hakkında daha fazla bilgi edinilebileceğini, amacın her şeyi anlatmak değil, Perl'ün güçlü yanına, yani güçlü örüntü eşleme ve düzenli ifade işlevlerine dair temel bir fikir vermek olduğunu söyledi.

## 21. Girdi/Çıktı ve Dosya Tanıtıcıları

Perl'de girdi/çıktı başka dillerdekine çok benzer. Bir programa giren veri onun girdisi, programın ürettiği veri çıktısıdır; kısaca G/Ç (IO) denir. Girdi/çıktı olanaklarına genellikle akış (stream) denir: girdi akışı ya da çıktı akışı. Her Perl programının en az üç standart akışı vardır: standart girdi, standart çıktı ve standart hata.

### 21.1 Standart Girdi ve `chomp`

Standart girdi akışı, verinin programa girdiği varsayılan yerdir; genellikle klavyedir ama bir disk dosyası da olabilir. Standart girdiden veri okumak için girdi işleci kullanılır; hoca slayttaki iki yazımın aynı olduğunu söyledi. <!-- BELİRSİZ: Slayt karede yok; iki yazım büyük olasılıkla `<>` ve `<STDIN>`. -->

Hocanın gösterdiği basit programda klavyeden iki girdi okunur; ilki `$a` skalerine, ikincisi `$b` skalerine atanır. Ardından "garip" görünen iki satır gelir: `chomp $a;` ve `chomp $b;`. `chomp` satır sonu karakterini siler. Bir şey girip satır başı (carriage return) tuşuna bastığınızda bu satır sonu karakteri de girdiğiniz şeye eklenir. Perl değişkenlerine her şey karışık konabildiği için bu karakter değişkende kalır; `chomp` ile silinir. İki sayı girildiyse bunlar toplanıp sonuç alınabilir. <!-- BELİRSİZ: Toplama programının tam kodu karelerde görünmüyor. -->

> **Hocanın vurgusu:** İki skaler değişkene giriş yapıyorsanız `chomp` kullanmayı ve satır sonu karakterini silmeyi unutmamalısınız.

### 21.2 Standart Çıktı ve Yönlendirme

Standart çıktı ekrandır, ama bir disk dosyası da olabilir. Hoca slayttaki iki yazımın aynı olduğunu söyledi. Komut satırında yönlendirme işleci (`>`) kullanılarak çıktı ekran yerine bir metin dosyasına yönlendirilebilir; program bu işleçle çalıştırıldığında sonuç o dosyaya yazılır. <!-- BELİRSİZ: STDOUT slaytındaki iki eşdeğer biçim (büyük olasılıkla `print` ve `print STDOUT`) ve yönlendirme komutu karelerde görünmüyor. -->

### 21.3 Dosya Tanıtıcıları

Dosya tanıtıcısı (file handle), bir çıktı hedefiyle ilişkilendirilmiş özel bir değişken türüdür ve C'deki dosya tanıtıcılarına çok benzer. İş bitince dosya tanıtıcısı kapatılmalıdır. Örnek olarak kök klasörde `index.html` dosyasına kaydedilen yeni bir web sayfası oluşturan bir betik gösterildi (ekrandan, 02:40:00). Betik şöyle başlar:

```perl
open HTML, ">index.html";
```

Ardından `print` ile `HTML` tanıtıcısına HTML satırları yazılır ve dosya kapatılır. `index.html` açıldığında içeriği bu yazılan satırlar olur. <!-- BELİRSİZ: index.html örneğinin print satırları karelerde görünmüyor. -->

Bir dosya üç kipte açılabilir:

- **Okuma:** `<` işaretiyle ya da işaretsiz.
- **Yazma:** `>` işaretiyle.
- **Ekleme (append):** `>>` ile; var olan bir dosya açılır, sonuna bir şey eklenir ve kapatılır.

Hoca C'de bunların yerine okuma için `r`, yazma için `w`, ekleme için `a` harflerinin kullanıldığını, Perl'de ise küçük/büyük işaretlerinin ve ekleme için iki büyük işaretinin kullanıldığını söyledi.

Okuma ve yazma örneği olarak `DNA` adlı bir dosyayı açıp içeriğini `DNA copy` dosyasına kopyalayan bir program gösterildi; kopyalama `while` döngüsüyle yapılır. Bir hata olursa, örneğin dosya bulunamazsa, `die` işlevi bir hata döndürür; bu hata işleme içindir. Hata işlemede kullanılan ilgili bir deyimden daha söz edildi. <!-- BELİRSİZ: 02:43:18 civarında anılan ikinci hata işleme deyiminin adı altyazıda bozuk; büyük olasılıkla warn. Kopyalama programının kodu karelerde görünmüyor. -->

Hoca dosya işleme, döngü yazma ve doğrusal deyimler gibi kavramların başka dillerden çok farklı olmadığını, Perl'ün birçok farklı dilden ödünç aldığını söyledi.

## 22. Perl Değişkenleri

Perl programları veriyi bellekte saklamak için değişkenler kullanır. Perl tipsiz (typeless) bir dildir: Programcıyı bir değişkende saklanan verinin türünü ayırt etmeye zorlamaz (ekrandan, 02:45:00).

Hoca bunu C diliyle karşılaştırdı. C'de herhangi bir program yazmadan önce değişkenleri ve türlerini bildirmeniz gerekir. Örneğin `A` tamsayı (`int`), `B` kayan noktalı (`float`), `C` karakter (`char`) olarak bildirilebilir. Program yazarken tamsayı olarak bildirilen bir değişkene kayan noktalı bir değer atamaya çalışırsanız hata alırsınız. Perl'de böyle değildir; bir değişkene her şeyi atayabilirsiniz.

Perl üç yerleşik değişken türü sunar: skaler, dizi ve hash.

### 22.1 Skaler Değişkenler

En temel türdür. Tek bir değer tutar. Değer her türden veri olabilir: dizgi, tamsayı, kayan noktalı sayı, nesne ya da başka değişkenlere veya değişken kümelerine başvuru (reference). Daha önce söylendiği gibi tek bir değişkene bütün bir veri dosyası bile atanabilir. Skaler değişkenlerin önünde dolar işareti (`$`) bulunur. Hoca slaytta tamsayı, işlem, dizgi ve cümle atanan skaler örnekleri gösterdi.

### 22.2 Dizi Değişkenleri

Dizi değişkeni, adından da anlaşılacağı gibi bir değişkende birden fazla veri tutar. Bu karakterle başlayan her değişken dizi olarak yorumlanır.

> **Ders sonrası not:** Altyazıda dizi değişkenlerinin "ampersand" (`&`) işaretiyle başladığı geçiyor. Doğrusu: Perl'de dizi değişkenleri `@` işaretiyle başlar; `&` alt yordam (subroutine) çağrısında kullanılır.

Bir dizi, parantez içinde virgülle ayrılmış değerler listesi verilerek başlatılabilir. Hocanın örneklerinde yalnız dizgi içeren bir dizi, yalnız tamsayı içeren bir dizi ve karışık bir dizi vardı. Önce boş bir dizi oluşturulup sonra elemanlar köşeli parantez işleciyle atanabilir. Bir dizinin tek tek elemanlarına başvurulduğunda her eleman bir skaler değişkene eşittir; bu yüzden elemana `$` ile erişilir. Dizi indisleri 0'dan başlar.

C/C++ gibi dillerde bir dizinin bütün elemanlarının aynı türde olması gerekir: hepsi tamsayı, hepsi karakter ya da hepsi dizgi (ekrandan, 02:50:00). Perl'de ise karıştırılabilir: İlk eleman bir dizgi, ikincisi tamsayı, üçüncüsü kayan noktalı sayı, beşincisi bütün bir dosya olabilir.

Dizi işlemek için birçok işlev vardır. Bir diziye eleman eklemek için hocanın gösterdiği iki farklı yazım ya da `push` deyimi kullanılabilir; hepsi aynı işi yapar. <!-- BELİRSİZ: Eleman ekleme yazımlarının slaytı karelerde görünmüyor. -->

### 22.3 Hash Değişkenleri

Üçüncü tür hash değişkenidir; ilişkisel dizi (associative array) olarak da bilinir. Anahtarları kendiniz üretirsiniz ve değerlere bu anahtarlarla başvurursunuz. Yüzde işaretiyle (`%`) başlayan her şey hash değişkeni olarak yorumlanır. Hocanın örneklerinde boş bir hash ve dolu bir hash vardı; dolu hash'te ad, soyad, e-posta, doğum tarihi, yaş gibi alanlar bulunuyordu. Tablonun sütunlarının değerlerine süslü parantezle tek tek erişilir; dizilerde olduğu gibi tek bir değere erişirken `%` değil `$` kullanılır. Hash'le ilgili birçok işlev vardır: anahtarları ya da değerleri almak, bir anahtarı silmek, bir anahtarın var olup olmadığını sorgulamak vb.

> **Ders sonrası not:** Hoca hash'i "başka dillerdeki dizi dizisine (array of arrays) denk" diye tanıttı. Doğrusu: Hash, anahtar-değer çiftlerini tutan bir ilişkisel dizidir (Python'daki sözlük gibi); dizi dizisi ise iki boyutlu dizidir.

### 22.4 Dizgi İşlevleri

Dizgi uzunluğu `length` işleviyle hesaplanır. Bir karakterin dizgideki konumu `rindex` işleviyle belirlenir. Bir dizgi diziye, bir dizi de dizgiye dönüştürülebilir. Hocanın son örneği, insan ubikitininin amino asit dizisini alıp dizgiden diziye dönüştürmekti. <!-- BELİRSİZ: Ubikitin örneğinin kodu ve dizisi karelerde görünmüyor. -->

> **Ek bilgi (derste anlatılmadı):** Perl'de dizgiyi karakter dizisine çevirmek için genellikle `split //, $dizgi` kullanılır; ters işlem `join '', @dizi` ile yapılır. `index` bir alt dizginin ilk geçtiği konumu, `rindex` son geçtiği konumu verir; ikisi de konumu 0'dan sayar.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:13:32): Swiss-Prot kaydında `SQ` satırından önce gelen bütün bilgilere ne ad verilir, bunlar ne tür veridir?

Derste cevap: Hoca öğrencilerden cevap alamadı. Asıl verinin yalnız `SQ` sonrasındaki harfler olduğunu, önceki kısmın verinin niteliğini ve özelliklerini anlattığını, dosya işlenirken bu bölümün ayıklanıp kalan amino asit verisinin işlenmesi gerektiğini söyledi. <!-- BELİRSİZ: 00:14:43-00:15:07 arası altyazı bozuk; hocanın verdiği terim tam okunamadı. -->

> **Çözüm (derste verilmedi):** Bu kısım büyük olasılıkla "üst veri" (metadata) ve açıklamalar (annotation) olarak adlandırılır: kimlik, erişim numarası, açıklama, gen adı, organizma, çapraz referanslar ve özellik tablosu gibi, asıl dizi verisini tanımlayan veridir.

**Soru 2** (ekrandan, 00:30:00; derste sözlü, 00:29:16): Dosya boyutu tablosundaki "bayt sayısı" sütununda kilobayt $10^3$, megabayt $10^6$, gigabayt $10^9$ olarak verilmiştir. Doğru değerler nedir?

Derste cevap: Bir öğrenci "2 üzeri 10" dedi; hoca onaylayıp doğru değerlerin $2^{10}$, $2^{20}$, $2^{30}$, $2^{40}$ … olduğunu söyledi. Sayısal karşılıkları $2^{10} = 1024$, $2^{20} = 1\,048\,576$, $2^{30} = 1\,073\,741\,824$'tür (python ile doğrulandı).

**Soru 3** (derste sözlü, 00:59:51): Bir bilgisayar sistemi hangi iki ana bileşen etrafında düzenlenir?

Derste cevap: Donanım (bilgisayarın gövdesi) ve yazılım (ruhu). Yazılım olmadan bilgisayar elektronik bir hurdadır.

**Soru 4** (derste sözlü, 01:04:22): Pratikte bilgisayarla problem çözerken hangi kısıtlar altında çalışılır?

Derste cevap: Zaman (hava tahmini, animasyon), maliyet (cep telefonu, motor denetleyicisi) ve güç (özellikle mobil uygulamalar).

**Soru 5** (derste sözlü, 01:23:04): Bir program yazarken kullanılan üç temel yapı nedir?

Derste cevap: Doğrusal (sıralı) deyimler, koşullu yapı (`if`) ve döngü (yineleme).

**Soru 6** (derste sözlü, 01:39:43): Perl ve Python yorumlanan dil midir, derlenen dil mi?

Derste cevap: İkisi de yorumlanan ya da derlenen dil olarak kullanılabilir; arada bir konumdadırlar. Hocanın bayt kodu hakkındaki ifadesi için 14.1'deki ders sonrası nota bakın.

**Soru 7** (ekrandan, 01:50:00): Aşağıdaki tek satırlık betik `merhabe.pl` olarak kaydedilip çalıştırılırsa ne olur?

```perl
print "merhaba \n;
```

> **Çözüm (derste verilmedi):** Kapanış çift tırnağı eksik olduğu için bu bir sözdizimi hatasıdır. Ajan `perl -c` ile denedi; Perl betiği çalıştırmadan `Can't find string terminator '"' anywhere before EOF at merhabe.pl line 1.` biçiminde bir hata verir. Doğru biçim `print "merhaba \n";` satırıdır; bu `perl -c` ile denetlendiğinde `syntax OK`, çalıştırıldığında `merhaba` çıktısı verir.

**Soru 8** (derste sözlü, 02:20:16): Programda klavyeden bir satır okuyup `$line` skalerine atayan bir deyim varsa ne olur? <!-- BELİRSİZ: Deyimin tam yazımı karelerde görünmüyor; büyük olasılıkla `$line = <>;`. -->

Derste cevap: Program sizin klavyeden bir şey girmenizi bekler. Bir metin, sayı ya da dizgi girip Enter'a bastığınızda girdiğiniz şey `$line` adlı skaler değişkene atanır.

**Soru 9** (ekrandan, 02:25:00): `perl getlines.pl oddevent.pl` komutu ne yapar?

Derste cevap: `getlines` programı bu kez girdiyi klavyeden değil, `oddevent.pl` dosyasından okur; dosyanın her satırını `$line` skalerine atayıp ekrana yazar. Böylece ekranda tek/çift programının kaynak kodu görünür. Girdi aygıtı klavyeden veri dosyasına değişmiştir.

## Dersin Toparlaması

Dersin ilk yarısında biyomedikal verinin doğası ve biyoenformatikte kullanılan başlıca veri tabanları tanıtıldı. DNA ve protein dizileri hesaplama açısından karakter dizgileri ya da karakter listeleridir. UniProt/Swiss-Prot ve enzim veri tabanı kayıtlarında asıl dizinin önünde onu tanımlayan alanlar bulunur. Nükleotit dizileri INSDC çatısı altındaki GenBank, EMBL/ENA ve DDBJ'de saklanır ve günlük paylaşılır. Erişim numaraları ve RefSeq bir diziyi tek ve kararlı biçimde tanımlamaya yarar. Bu veriler hızla büyüyen gerçek bir büyük veridir; ölçeklerini doğru okumak için birimlere dikkat etmek gerekir.

İkinci yarıda programlama ortamına geçildi. Problemden algoritmaya, programdan makine komutlarına uzanan soyutlama katmanları, üç temel yapı ve hata ayıklama ilkeleri hatırlatıldıktan sonra, metin işleme gücü nedeniyle biyoenformatikte yaygın olan Perl'ün temelleri gösterildi: `while` döngüsü, sabitler, skalerler, `if`, girdi işleci `<>`, `=~` ile örüntü eşleme, standart akışlar ve dosya tanıtıcıları, ve skaler/dizi/hash değişkenleri. Hoca, veri tabanlarındaki verilerin bir kısmının ileride gerçek biyoenformatik algoritmaları anlatılırken bu programlama araçlarıyla işleneceğini belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
