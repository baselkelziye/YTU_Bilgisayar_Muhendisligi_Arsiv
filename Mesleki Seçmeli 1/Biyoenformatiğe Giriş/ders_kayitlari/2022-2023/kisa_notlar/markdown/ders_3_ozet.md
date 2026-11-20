# Ders 3 Çalışma Özeti

## Genel Konular

- Biyomedikal verinin doğası ve gösterimi
  - Biyomedikal veri; DNA ve protein dizileri, kan örnekleri gibi laboratuvar verileri, tek boyutlu işaretler, iki boyutlu tıbbi görüntüler ve üç boyutlu video verisi gibi çok farklı türlerden oluşur. Dergi makaleleri ve kaynakçalar gibi metinler de tanıya yardımcı olabilecek "alışılmamış" veridir.
  - Metin dosyalarında her karakter 8 bitle tutulur: ASCII kodu 7 bittir, 1 bit eşlik (parity) yani hata sezimi için kullanılır.
  - Baz (nükleotit) dizileri iki biçimde gösterilebilir: uzun bir karakter dizgisi (string) ya da her bazın bir sembol olduğu bir liste (karakter listesi). Biyoenformatik tekniklerinin önemli bir kısmı bu metin verisiyle çalışır.
- Protein veri tabanları
  - UniProt / Swiss-Prot Bilgi Tabanı, İsviçre Biyoenformatik Enstitüsü'nün bir projesidir; veriler ExPASy web sitesinden (`http://www.expasy.ch`) çeşitli biçimlerde indirilebilir (ekrandan, 00:10:00).
  - Örnek kayıt: insan insülin öncüsü (`INS_HUMAN`, erişim numarası `P01308`, 110 amino asit) (ekrandan, 00:15:00).
    - `ID` kimlik, `AC` erişim numarası, `DE` açıklama, `GN` gen adı, `OS` organizma, `DR` çapraz referanslar (burada Gene Ontology'ye), `FT` özellik tanımları, `SQ` asıl amino asit dizisidir.
    - `FT` satırlarında etiketten sonra özellik türü (SIGNAL, PEPTIDE, PROPEP, DISULFID, VARIANT, HELIX, STRAND, TURN), ardından özelliğin dizideki başlangıç ve bitiş konumları gelir.
    - Dosya işlenirken `SQ` öncesindeki açıklama kısmı ayıklanır, yalnız amino asit harfleri işlenir.
- Enzim veri tabanı
  - Birçok protein enzim olarak çalışır; enzimler kimyasal tepkimeleri başlatan/kolaylaştıran bileşiklerdir ve birçok biyolojik tepkime ilgili enzim olmadan ilerlemez. Bu yüzden bir proteinin işlevi, enzimse türü ve hangi tepkimeyi kolaylaştırdığı önemli bilgidir.
  - Örnek kayıt (malat dehidrojenaz): `ID` satırı her kayda özgü enzim komisyonu (EC) numarası, `DE` resmî ad, `AN` alternatif adlar, `CA` katalizlenen tepkimenin simgesel gösterimi, `CC` yorum, `PR` PROSITE veri tabanına, `DR` Swiss-Prot kayıtlarına çapraz referanslardır. NAD+ ve NADH tepkimeye katılan koenzimlerdir. <!-- BELİRSİZ: Enzim kaydının slaytı karelerde görünmüyor; EC numarası ve satır içerikleri altyazıdan yazıldı. -->
- Biyolojik veri tabanlarına iki bakış (ekrandan, 00:20:00)
  - Tek bir nesneyi incelemek: örneğin insan beta globini için bir gen (HBB), bir protein dizisi, bir protein yapısı ve çeşitli varyasyon kayıtları vardır.
  - Büyük grupları incelemek: insan genomundaki tüm globin genleri, bilinen tüm HBB varyantları ya da bir hastalıkla (örneğin otizm) ilişkilendirilmiş 100 genin hasta örneklerindeki varyasyonu.
- DNA dizi verisinin saklandığı yerler
  - 1982'den bu yana üç ana merkez: ABD Ulusal Sağlık Enstitüsü (NIH) bünyesindeki NCBI'daki GenBank (Bethesda), Avrupa Moleküler Biyoloji Laboratuvarı (EMBL) / Avrupa Nükleotit Arşivi (Avrupa Biyoenformatik Enstitüsü, Hinxton, İngiltere) ve Japonya DNA Veri Bankası (DDBJ, Ulusal Genetik Enstitüsü, Mishima).
  - Üçü Uluslararası Nükleotit Dizi Veri Tabanı İşbirliği (INSDC) altında koordine edilir ve ham dizi verisini günlük olarak paylaşır.
  - NCBI, GenBank'i yaklaşık 40 moleküler ve literatür veri tabanından oluşan Entrez sisteminin parçası olarak barındırır; Trace Archive dizileme izlerini, Sequence Read Archive (SRA) yeni nesil dizileme verisini saklar.
  - DDBJ'nin yapısı: Trad (geleneksel bölüm), Sequence Read Archive (SRA), BioProject/BioSamples (ekrandan, 00:25:00).
  - Bu veri tabanlarına web tarayıcısıyla ya da EDirect gibi komut satırı programlarıyla erişilebilir.
  - DNA dizi depoları her gün büyür; dizileme teknolojisindeki gelişmeler bu büyümeyi azaltmaz, artırır.
- Ölçek birimleri
  - Baz çifti (bp), kilobaz (kb, $10^3$), megabaz (Mb, $10^6$), gigabaz (Gb, $10^9$), terabaz (Tb, $10^{12}$), petabaz (Pb, $10^{15}$). İnsan genomu yaklaşık 3 milyar baz çiftidir.
  - Dosya boyutu tablosu: bayt tek bir metin karakteridir; slayttaki örnekler GenBank boyutu 600 GB, 1000 Genom Projesi 500 TB'den az, NCBI'daki SRA 5 PB, yıllık dünya çapında üretim 2 EB'den fazla (ekrandan, 00:30:00).
- Taksonomi, erişim numaraları ve RefSeq
  - Taxa, "taxon" sözcüğünün çoğuludur: canlıların sınıflandırıldığı herhangi bir grup ya da rütbe (mantarlar, bakteriler, metazoa, virüsler vb.). NCBI'da taksonomi tarayıcısıyla gezilebilir.
  - Ekspres dizi etiketleri (EST) ve EST kümelerini içeren UniGene veri tabanı örnek olarak gösterildi.
  - Erişim numarası (accession number) bir diziyi tanımlayan, harf ve/veya rakamlardan oluşan etikettir (ekrandan, 00:35:00).
  - RefSeq, bir dizinin en kararlı ve üzerinde uzlaşılmış referans sürümüne karşılık gelen, uzmanlarca düzenlenmiş (curated) erişim numarası verir. Önekler: `NC` tam genom/kromozom, `NT` genomik contig, `NM` mRNA, `NP` protein.
  - NCBI Gene, her gen için ana veri tabanlarından temel bilgileri topladığı için iyi bir başlangıç noktasıdır.
- Genom tarayıcıları ve arama
  - Genom tarayıcıları kromozom konumlarını açıklamalarıyla birlikte görselleştirir; bir gen gibi kromozomal bir özelliğe ilişkin veriyi keşfetmeye yarar. Öne çıkanlar Ensembl, UCSC ve NCBI'dır.
  - Bir gen aranırken resmî gen simgesi bilinmeli ve doğru tür seçilmelidir (`http://www.genenames.org`). Bazı aramalar zordur (binlerce histon vardır); sonuçları daraltmak için AND, OR gibi Boole işleçleri kullanılır (ekrandan, 00:40:00).
  - HIV-1 proteinleri aranınca yaklaşık 1 milyon protein ve DNA sonucu çıkar ama yalnız bir RefSeq erişimi vardır; bu RefSeq projesinin yararını gösterir.
- Bilgisayar sistemlerine teknolojik bakış
  - Bilgisayar iki ana bileşen etrafında düzenlenir: donanım (gövde) ve yazılım (ruh). Yazılım olmadan bilgisayar elektronik hurdadır.
  - Kuramsal olarak bilgisayar, yeterli bellek ve zaman verilirse hesaplanabilir her şeyi hesaplayabilir; aynı program PDA'da, iş istasyonunda ya da süper bilgisayarda aynı sonucu verir. Pratikte problem çözme kısıtlar altında yapılır: zaman (hava tahmini, animasyonun sonraki karesi), maliyet (cep telefonu, otomotiv motor denetleyicisi) ve güç (özellikle mobil uygulamalar) (ekrandan, 01:05:00).
  - İşletim sistemi donanımla doğrudan etkileşir, sistem kaynaklarını denetler ve kullanıcının sistemi kolay kullanmasını sağlar.
- Problem çözmede soyutlama katmanları
  - Problem → (yazılım tasarımı: algoritma ve veri yapısı seçimi) → algoritma → (programlama: tasarımı bir dille ifade etme) → program → (derleme/yorumlama: dili makine komutlarına çevirme) → komut kümesi mimarisi (ISA) → mikromimari → devre → aygıtlar (ekrandan, 01:10:00).
  - Algoritma adım adım bir yöntemdir; bitmesi garanti olmalı ve kesin (definite) olmalıdır.
  - Her düzeyde birçok seçenek vardır: bir denklem sistemi Red-black SOR, Gauss eliminasyonu, Jacobi yinelemesi ya da Multigrid ile çözülebilir; Gauss eliminasyonu FORTRAN, C, C++ ya da Java ile yazılabilir; C programı PowerPC, Intel x86 ya da Atmel AVR üzerinde çalışabilir; Intel x86 için Centrino, Pentium 4, Xeon seçilebilir (ekrandan, 01:15:00). Sonra toplayıcı tasarımı (ripple-carry ya da daha hızlı carry-lookahead) ve yarı iletken teknolojisi (CMOS, hız için bipolar, çok yüksek performans için galyum arsenit) seçilir; her seçim bir ödünleşimdir.
  - Bilgisayar sistemi en az yedi düzeyli bir hiyerarşi olarak görülür: yüksek düzey dil, assembly, sistem yazılımı, makine, denetim ve mantık düzeyleri vb.
- Programlama dilleri ve programlama süreci
  - Derlenen diller (C, Fortran, Ada): derleme sonunda çalıştırılabilir kod elde edilir. Java derlenince bayt kodu (bytecode) üretir, bu kod yorumlanır. BASIC gibi diller yorumlanan dillerdir.
  - Programlama, istenen işlevi yapan bilgisayar programları oluşturma yöntemleridir. Hata ayıklama (debugging) programın neden çalışmadığını bulmaktır; ilk aşamaya (tasarım) zaman harcamak ikinci aşamada (hata ayıklama) harcanan zamanı azaltır.
  - Adım adım iyileştirme (sistematik ayrıştırma): problem, makine komutu düzeyine inene kadar daha küçük alt görevlere bölünür. Doğal dille yazılmış problem tanımları belirsiz ya da eksik olabilir (dosya nerede, ne kadar büyük, sona gelindiği nasıl anlaşılır, büyük/küçük harf ayrı sayılır mı); bu sorular problemi isteyene sorulur ya da bir karar verilip belgelenir.
  - Üç temel yapı: sıralı (sequential/linear), koşullu (conditional) ve yinelemeli (iterative/loop) (ekrandan, 01:25:00).
  - Programlamanın biyoenformatikteki yararı: aynı analizi çok sayıda benzer veri dosyasında çalıştırmak (otomasyon), veriyi analiz etmek, karar vermek ve yeni analiz yöntemleri oluşturmak.
- Perl ve Python
  - Dersin amaçlarından biri, biyoenformatik programlarının geliştirilmesinde temel araç olarak bir programlama dilini (Perl, Python) anlamak ve kullanabilmektir (ekrandan, 01:00:00).
  - Perl'ün biyoenformatikte yaygın olmasının nedeni metinle çalışmaya yönelik güçlü işlevleridir: biyoenformatikte ana veri türü metin (karakter, dizgi) olduğu için arama, ayıklama, değiştirme ve birleştirme kolaydır. Başka programları denetleyebilir, ücretsizdir, tüm işletim sistemlerinde çalışır, çok sayıda açık modülü vardır.
  - Perl, "Practical Extraction and Report Language" kısaltmasıdır. Sloganı "bir işi yapmanın birden fazla yolu vardır"dır.
  - Python bir kısaltma değildir, Monty Python komedi grubundan adını alır. Felsefesinden: basit karmaşıktan iyidir; karmaşık (complex), girift (complicated) olandan iyidir; okunabilirlik önemlidir. Büyük veri, veri bilimi ve yapay zekâda yaygındır, öğrenmesi kolaydır.
  - R dili de biyoenformatikte yaygın kullanılır ama derste ele alınmayacak.
  - Her iki dil için de yalnız bir metin düzenleyici yeterlidir; Perl dosyası `perl dosya.pl`, Python dosyası `python dosya.py` ile çalıştırılır. İkisi de yorumlanan ya da derlenen dil olarak kullanılabilir.
- Hata ayıklama
  - İlk iş hata mesajını dikkatle okumaktır. Çok satırlı hatalarda ilk satıra (ve bir önceki satıra) bakılır; ilk hata düzeltilince sonrakiler çoğu kez kaybolur.
  - Perl'de `-c` anahtarı betiği çalıştırmadan derlemeyi dener ve sözdizimini denetler; `-w` (warn) bazı anlamsal sorunları uyarır; ikisi birleştirilebilir. `use strict;` tüm değişkenlerin kullanılmadan önce tanımlanmasını zorunlu kılar (ekrandan, 01:55:00).
  - Hata türleri: sözdizimi (syntax) hatası ve anlam (semantic) hatası. Program dilin kurallarına uyup yine de beklenen işi yapmıyorsa anlam hatası vardır; diller sözdizimi hatası için çok, anlam hatası için az destek sunar.
  - Python'da yerleşik hata ayıklayıcı `pdb`'dir.
- Perl temelleri
  - `#!` ile başlayan ilk satır Unix sistemine dosyanın nasıl çalıştırılacağını (Perl yorumlayıcısının yerini) söyler; diğer `#` satırları yorumdur. Deyimler `;` ile biter; çift tırnak içindeki metin dizgidir; `\n` yeni satır başlatır.
  - Yineleme `while` ile yapılır; koşul doğru oldukça döngü sürer. Perl'de 1 doğru, 0 yanlıştır; karakter içermeyen dizgi yanlış, diğerleri doğrudur.
  - Sabit (`use constant HOWMANY => 4;`) programda hiçbir koşulda değiştirilemeyen kaptır; sabit adları gelenek olarak büyük harfle yazılır. Perl büyük/küçük harfe duyarlıdır.
  - Değişken kabı (variable container) programın ömrü boyunca değişebilir. Perl bir skaleri sayısal bağlamda ilk kullanıldığında sıfıra ayarlar, ama açık bir başlangıç değeri vermek iyi bir alışkanlıktır (ekrandan, 02:15:00).
  - Seçim (koşul) `if`/`elsif`/`else` ile yapılır. Tek/çift örneği üç farklı uzunlukta yazıldı; en kısası modülo işlecini kullanır.
  - Girdi işleci `<>` standart girdiden bir satır döndürür; varsayılan girdi klavyedir, ama komut satırında dosya adı verilirse dosya okunur (ekrandan, 02:20:00).
  - Düzenli ifade ve örüntü eşleme: `print $line if $line =~ /even/;` ifadesinde `=~` bağlama (binding) işlecidir, `/` karakteri sınırlayıcıdır (ekrandan, 02:30:00).
  - Bildirimsel (declarative) dil ne istendiğini söyler, yöntemi teknoloji bulur; yordamsal (procedural) dil sonuca nasıl ulaşılacağını tam olarak belirtir. Perl ikisi olarak da kullanılabilir.
  - Standart akışlar: STDIN, STDOUT, STDERR. `chomp` girilen satırın sonundaki satır sonu karakterini siler. Çıktı `>` ile dosyaya yönlendirilebilir.
  - Dosya tanıtıcısı (file handle): `open` ile okuma (`<`), yazma (`>`) ve ekleme (`>>`) kipinde açılır, `print` ile yazılır, `close` ile kapatılır. Dosya açılamazsa `die` ile hata verilir.
  - Perl tipsiz (typeless) bir dildir; değişken tipi bildirilmez. Üç yerleşik değişken türü: skaler (`$`), dizi (`@`) ve özet/ilişkisel dizi (hash, `%`). Dizi indisleri 0'dan başlar; bir dizinin elemanları farklı türlerde olabilir; `push` ile eleman eklenir. Hash değerlerine anahtarla süslü parantezle erişilir.
  - Dizgi işlevleri: `length` uzunluk, `index`/`rindex` bir karakterin konumu; dizgi diziye, dizi dizgiye dönüştürülebilir (insan ubikitin amino asit dizisi örneği).

## Hocanın Özellikle Vurguladığı Kısımlar

- Kitaplardaki ve indirilen sunumlardaki hatalara dikkat
  - Hoca, bir kitabın sunumundan alınan dosya boyutu tablosundaki $10^3, 10^6, \dots$ değerlerini kırmızıyla çizdi; doğrusunun $2^{10}, 2^{20}, 2^{30}, \dots$ olduğunu söyledi ve kitap ya da internetten indirilen sunum okurken dikkatli olunmasını istedi.
- Veri tabanlarını kendiniz kullanın
  - Bu sitelere girip denemek, onlara alışmanın tek yoludur. Veri tabanları dersin ana amacı değildir; ilerde algoritmalar anlatılırken bu verilerin bir kısmı kullanılacaktır.
- Biyoenformatikte ana veri türü metindir
  - Perl'ün bu alanda yaygın olmasının temel nedeni güçlü metin işleme işlevleridir.
- Hata mesajını okuyun
  - Hata görünce mesajı okumadan çözmeye çalışmak yaygın bir hatadır; ilk yapılacak iş mesajı dikkatle okumaktır.
- `chomp` unutulmamalı
  - Klavyeden iki sayı okunup toplanacaksa satır sonu karakteri `chomp` ile silinmelidir.

## Kısa Tekrar Notları

- Biyoenformatikte DNA/protein dizileri karakter dizgisi ya da karakter listesi olarak tutulur.
- UniProt/Swiss-Prot kaydında `SQ` öncesi açıklama, `SQ` sonrası asıl dizidir; `FT` satırları özellik türü ve başlangıç-bitiş konumları verir.
- Üç büyük nükleotit veri tabanı: GenBank (NCBI, ABD), EMBL/ENA (EBI, Avrupa), DDBJ (Japonya); INSDC altında günlük veri paylaşırlar.
- RefSeq önekleri: `NC` genom/kromozom, `NT` contig, `NM` mRNA, `NP` protein.
- Baz çifti ölçeği: bp, kb, Mb, Gb, Tb, Pb; insan genomu yaklaşık $3 \times 10^9$ bp.
- Hesaplama kısıtları: zaman, maliyet, güç.
- Problem → algoritma → program → makine komutları → ISA → mikromimari → devre → aygıt.
- Üç temel yapı: sıralı, koşullu, yinelemeli.
- Perl: `-c` sözdizimi denetimi, `-w` uyarılar, `use strict;` değişken bildirimi zorunluluğu.
- Perl değişkenleri: `$` skaler, `@` dizi, `%` hash.
- `<>` girdi işleci, `=~` bağlama işleci, `chomp` satır sonu silme, `open`/`close` dosya tanıtıcıları, `die` hata.

## Detaylı Açıklamalar

- UniProt kaydının okunması
  - Ekranda gösterilen insülin öncüsü kaydında (ekrandan, 00:15:00) ilk satır `ID INS_HUMAN Reviewed; 110 AA.`, ikinci satır `AC P01308; Q5EEX2;` şeklindedir. `DE` satırı "Insulin precursor [Contains: Insulin B chain; Insulin A chain]" açıklamasını, `GN Name=INS;` gen adını, `OS Homo sapiens (Human).` organizmayı verir. `DR GO; GO:0006953; P:acute-phase response; ...` gibi satırlar Gene Ontology'ye çapraz referanslardır. `FT SIGNAL 1 24`, `FT PEPTIDE 25 54 Insulin B chain.`, `FT PROPEP 57 87 C peptide.`, `FT PEPTIDE 90 110 Insulin A chain.` satırları özellik türünü ve dizideki konumunu verir; `DISULFID` satırları B ve A zincirleri arasındaki disülfit bağlarını, `VARIANT 34 34 H -> D` bir varyantı, `HELIX`, `STRAND`, `TURN` satırları ikincil yapı öğelerini gösterir. `SQ SEQUENCE 110 AA;` satırından sonra dizi gelir: `MALWMRLLPL LALLALWGPD PAAAFVNQHL ...`.
  - Hoca bu kayıt üzerinden "dizi başlamadan önceki tüm bu bilgilere ne denir" diye sordu; verinin yalnız `SQ` sonrasında başladığını, dosya işlenirken bu bölümün ayıklanıp kalan amino asit verisinin işleneceğini söyledi.
- Dosya boyutları tablosu ve hocanın düzeltmesi
  - Slayttaki tabloda (ekrandan, 00:30:00) bayt = 1 (tek metin karakteri), kilobayt = $10^3$ (1000 karakterlik metin dosyası), megabayt = $10^6$, gigabayt = $10^9$ (GenBank: 600 GB), terabayt = $10^{12}$ (1000 Genom Projesi: < 500 TB), petabayt = $10^{15}$ (NCBI SRA: 5 PB), eksabayt = $10^{18}$ (yıllık dünya üretimi: > 2 EB) yazıyordu. Hoca bu üs değerlerini çizdi ve bir öğrencinin cevabıyla doğrusunun $2^{10} = 1024$, $2^{20}$, $2^{30}$, $2^{40}$ … olduğunu söyledi.
  - > **Ek bilgi (derste anlatılmadı):** Bu konuda iki gelenek vardır. SI önekleri (kB, MB, GB) ondalık olarak $10^3, 10^6, 10^9$ anlamına gelir ve disk üreticileri ile ağ hızları bunu kullanır; IEC 1998'de ikili değerler için KiB ($2^{10}$), MiB ($2^{20}$), GiB ($2^{30}$) öneklerini tanımlamıştır. Bellek ve işletim sistemi bağlamında "KB" çoğu zaman 1024 bayt anlamında kullanılır; hocanın düzeltmesi bu ikili kullanıma dayanır.
- Perl'de tek/çift programı ve girdi işleci
  - Ekranda `perl getlines.pl oddevent.pl` komutu gösterildi (ekrandan, 02:25:00). `getlines` programı standart girdiden satır okuyup yazar; burada girdi klavye yerine komut satırında verilen dosyadır. Çıktı olarak tek/çift programının "kötü biçimlendirilmiş" sürümünün kaynak kodu ekrana basıldı:

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

  - Bu program `perl` ile ajan tarafından çalıştırıldı; çıktısı sırayla `odd`, `even`, `odd`, `even` satırlarıdır.
  - Aynı dosya `patterns` programına girdi olarak verilince yalnız `even` örüntüsünü içeren satırlar basılır: `print $line if $line =~ /even/;` (ekrandan, 02:30:00).
- Ders sonrası notlar
  - Hoca Perl ve Python'un Java gibi bayt kodu üretmediğini, doğrudan işlemcinin komut kümesine uygun kod ürettiğini söyledi. Doğrusu: standart Perl kaynak kodu önce iç bir işlem ağacına (op-tree), CPython ise `.pyc` bayt koduna derler ve bu ara gösterim bir yorumlayıcı/sanal makine tarafından çalıştırılır; doğrudan makine kodu üretilmez.
  - Altyazıda dizi değişkenlerinin "ampersand" (`&`) ile başladığı geçiyor. Doğrusu: Perl'de dizi değişkenleri `@` ile başlar; `&` alt yordam (subroutine) çağrısı içindir.
  - Hoca hash değişkenini "başka dillerdeki dizi dizisine (array of arrays) denk" diye tanıttı. Doğrusu: hash, anahtar-değer çiftlerini tutan ilişkisel dizidir (Python'daki sözlük gibi); dizi dizisi ise iki boyutlu dizidir.
  - Hoca UCSC genom tarayıcısını "University of California, Santa Clara, sanırım" diye andı. Doğrusu: UCSC, University of California, Santa Cruz'dur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
