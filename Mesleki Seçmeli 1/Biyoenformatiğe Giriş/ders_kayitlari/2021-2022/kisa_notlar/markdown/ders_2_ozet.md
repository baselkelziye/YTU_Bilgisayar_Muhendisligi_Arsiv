# Ders 2 Çalışma Özeti

## Genel Konular

- Moleküler biyolojinin temelleri (önceki dersin devamı)
  - Taşıyıcı RNA (tRNA) küçük bir RNA türüdür: genelde 74-95 nükleotit, en fazla yaklaşık 100 harf. Çeviri (translation) sırasında belirli bir amino asidi ribozomda büyüyen polipeptit zincirine taşır.
  - Merkezî dogma şekil üzerinden anlatıldı (ekrandan, 00:10:00): DNA kendini eşler (replication, DNA duplicates); çekirdekte DNA'dan mRNA sentezlenir (transcription, RNA synthesis); mRNA çekirdek zarını geçip sitoplazmaya çıkar; ribozomda proteine çevrilir (translation, protein synthesis).
  - Gen: kalıtımın fiziksel ve işlevsel birimidir, bilgiyi bir kuşaktan ötekine taşır. Genom: bir organizmanın bütün genleri dahil eksiksiz DNA kümesidir; organizmayı kurmak ve sürdürmek için gereken bilginin tamamını içerir.
  - Genom büyüklüğü ve gen sayısı organizmanın karmaşıklığıyla ilgilidir ama belirleyici etken değildir. İnsan genomu yaklaşık 3 milyar baz çiftidir, gen sayısı yaklaşık 30.000 olarak verildi; farenin gen sayısı insana yakın, genomu daha küçüktür.
  - Transkriptom: bir organizmanın olası bütün mRNA'larının tamamı; kodlamayan RNA'lar da dahil edilerek genişletilebilir. Proteom: bir organizmanın üretebileceği proteinlerin tamamı.
- Bilgisayarda biyomedikal verinin temsili
  - Veri nicel (quantitative) ve nitel (qualitative) olarak ikiye ayrılır. Biyoenformatikte DNA ve protein dizileri, kan testi gibi laboratuvar verileri (örneğin kan hücresi sayısı nicel bir bilgidir), tıbbi görüntüler ve Medline gibi kaynakça veritabanlarındaki metinler temsil edilmelidir.
  - DNA dizisi harf dizisi (string, karakter dizisi) ya da her nükleotidin bir sembol olduğu bir liste olarak temsil edilir (ekrandan, 00:20:00).
  - DNA dizisi nitel veridir: harfler sembol olup sayısal nicelik değildir.
- Biyolojik veritabanı kayıtları
  - UniProt/Swiss-Prot gibi veritabanlarından biyoenformatik veri indirilebilir. Bir kayıt satır kodlarıyla alanlara ayrılır. İnsan insülini örneği (ekrandan, 00:25:00): `ID` (INS_HUMAN, 110 AA), `AC` (erişim numaraları), `DE` (açıklama), `GN` (gen adı), `OS` (organizma), `DR` (çapraz referans, örneğin Gene Ontology terimleri), `FT` (özellikler: sinyal peptidi, zincirler, disülfit bağları, varyant, sarmal/iplik/dönüş), `SQ` (dizi).
  - Gene Ontology (GO) alanları kayda üstveri (metadata) sağlar. `FT` satırları amino asit dizisinde alfa sarmal, beta iplik gibi yapıların yerlerini gösterir.
  - Birçok protein enzim olarak çalışır. Enzim veritabanı (ExPASy) kaydında `ID` satırı her kayda özgü enzim komisyonu (EC) numarasını, `DE` resmî adı, diğer satırlar eş adları, `CA` satırı katalizlenen tepkimeyi simgesel biçimde verir. Örnek: malat dehidrojenaz, koenzim NAD+/NADH.
- Biyolojik veritabanlarında arama
  - İki bakış açısı: tek bir geni/proteini incelemek (örneğin insan beta-globin geni HBB, protein dizisi, yapısı, varyantları) ya da büyük grupları incelemek (insan genomundaki bütün globin genleri, bilinen bütün HBB varyantları, bir hastalıkla ilişkili 100 genin hasta örneklerindeki çeşitliliği).
  - 1982'den bu yana nükleotit dizilerini saklayan üç ana merkez (ekrandan, 00:30:00): ABD'de NIH'e bağlı NCBI'daki GenBank (Bethesda), Avrupa Biyoenformatik Enstitüsü (EBI, Birleşik Krallık) bünyesindeki ENA/EMBL-Bank ve Japonya'daki DDBJ. Üçü International Nucleotide Sequence Database Collaboration (INSDC) ile eşgüdümlüdür.
  - Dizi depolarındaki veri miktarı hızla, üstel biçimde büyümektedir.
- DNA baz çifti ölçekleri (ekrandan, 00:35:00)
  - 1 bp; 1 kb = 1000 bp (tipik bir genin kodlayan bölgesi); 1 Mb = $10^6$ bp (tipik bir bakteri genomu); 1 Gb = $10^9$ bp (insan genomu yaklaşık 3 milyar bp); 1 Tb = $10^{12}$; 1 Pb = $10^{15}$ bp.
  - Baz çiftinde kilo $10^3$ demektir, $2^{10}$ değil.
- Taksonomi, erişim numaraları ve genom tarayıcıları
  - GenBank'taki veriler Archaea, Bacteria, Eukaryota, Fungi, Metazoa gibi taksonlara ayrılır. Takson (çoğulu taxa): akraba organizmaların sınıflandırıldığı herhangi bir grup ya da basamak.
  - Veri türleri merkezî dogmaya göre düşünülebilir: genomik DNA'daki protein kodlayan genler öncül mRNA'ya yazılır, intronlar çıkarılıp ekzonlar birleştirilir (splicing), olgun mRNA proteine çevrilir.
  - Erişim numarası (accession number): DNA, RNA ve protein dizilerine verilen etikettir. NCBI arayüzünde beta-globin örnekleri gösterildi.
  - Genom tarayıcıları (genome browser) genomları gezmek için web tabanlı uygulamalardır. Veritabanlarının listesi için Wikipedia'daki "List of biological databases" iyi bir başlangıç noktasıdır.
- Hesaplamaya giriş
  - Biyoenformatikte Perl kullanılacak, Python ile karşılaştırılacak. Dersin hedefleri (ekrandan, 01:05:00): sıra, yineleme ve seçim; programlamanın temel yapı taşları; üç C (constants, comments, conditions); değişken kapları; Perl işleçleri ve örüntü eşleme.
  - Modern bilgisayarın iki ana bileşeni donanım ve yazılımdır. İşlevleri: veri işleme, veri saklama, veri taşıma ve denetim. Yapısı: CPU, bellek, giriş/çıkış ve sistem bağlantısı (veri yolu).
  - Kuramda yeterli bellek ve zaman verilirse bütün bilgisayarlar aynı şeyleri hesaplayabilir (ekrandan, 01:10:00). Uygulamada hesaplama zaman, maliyet ve güç kısıtları altında yapılır.
  - Teknoloji katmanları (ekrandan, 01:15:00): işletim sistemi donanımla doğrudan etkileşir ve kaynakların verimli kullanılmasından sorumludur; araçlar (programlama dilleri, veritabanları, editörler, arayüz oluşturucular) işletim sisteminin sunduklarını kullanır; uygulamalar (web tarayıcıları, e-posta istemcileri, web sunucuları, kelime işlemciler) en kullanışlı yazılım türüdür.
  - Her düzeyde birçok seçenek vardır (ekrandan, 01:20:00): bir denklem sistemi Red-black SOR, Gauss yok etme, Jacobi yinelemesi ya da Multigrid ile çözülebilir; Gauss yok etme FORTRAN, C, C++ ya da Java ile yazılabilir; C kodu PowerPC, Intel x86 ya da Atmel AVR mimarisine derlenebilir.
  - Derlenen, yorumlanan ve platformdan bağımsız diller (ekrandan, 01:25:00): C, Fortran, Ada derleyiciyle assembly diline, oradan assembler ile makine koduna çevrilir; Basic yorumlayıcıyla çalışır; Java derleyicisi mimariye bağlı olmayan bayt kodu üretir, bayt kodu çalışma ortamı (JRE) yorumlar.
- Programlama, hata ayıklama ve üç temel yapı
  - Programlama: problem tanımını adım adım iyileştirme (stepwise refinement) ile algoritmaya, algoritmayı makine komutlarına çevirmektir. Görev alt görevlere, onlar daha küçük alt görevlere bölünür. İngilizce yazılan problem tanımı belirsiz ya da eksik olabilir; problemi isteyene sorulur ya da karar verilip belgelenir.
  - Üç temel yapı: sıra (sequential), koşul (conditional: if, else) ve yineleme (iterative/loop: for, do, while, repeat).
  - Program yazmanın amacı elle yapılan işleri otomatikleştirmektir: zaman kazandırır, hatayı azaltır. Örnek: 100 veri dosyasını tek tek indirmek yerine bir betikle indirmek.
- Perl ve Python (ekrandan, 01:40:00)
  - Perl: Practical Extraction and Report Language. Güçlü metin işleme işlevleri vardır; Larry Wall tarafından NASA JPL'de Unix'te e-posta işlemek için yazıldı; "yapıştırıcı" dil olarak başladı, biyologlar dahil birçok kişi genişletti. Sürüm 5.32.1. Slogan: TMTOWTDI (There's More Than One Way To Do It).
  - Python bir kısaltma değildir, Monty Python komedi grubundan adını alır; 1980'lerin sonunda Guido van Rossum tarafından ABC dilinin ardılı olarak tasarlandı; nesne yönelimlidir. Sürüm 3.9.2. Temel felsefe: güzel çirkinden, açık örtükten, basit karmaşıktan, karmaşık girift olandan iyidir; okunabilirlik önemlidir.
  - Kurulum sonrası sürüm denetimi: Perl'de `perl -v`, Python'da `python --version`. Perl'de belge için `perldoc`, Python'da `help()` ortamı kullanılır.
  - Kod yazmak (ekrandan, 01:50:00): bir çalışma klasörü oluştur, metin editörüne kodu yaz, Perl için `.pl` ya da `.plx`, Python için `.py` uzantısıyla kaydet; dosyaya çift tıkla ya da komut satırından `perl dosya.pl` ile çalıştır. İki dil de betik (scripting) dilidir; kod özel bir sanal makine koduna çevrilir.
- Perl'de hata ayıklama
  - Perl hatanın yerini söylemeye çalışır; hata iletileri dikkatle okunmalıdır. Birden çok satırlık hatalarda sonraki hatalar ilkinden tetiklenmiş olabilir.
  - `-c` anahtarı betiği çalıştırmadan derler ve sözdizimini denetler; kapanmayan bir dizgede "Can't find string terminator" hatası verir.
  - Hatalar sözdizimi (syntax) ve anlam (semantics, mantık hatası) olarak ikiye ayrılır (ekrandan, 02:15:00). Sözdizimi doğru bir program anlamca yanlış olabilir; `-c` bunu yakalayamaz, `-w` (uyarı) anahtarı "Useless use of a constant ... in void context" gibi uyarılar verir. `-cw` iki denetimi birleştirir.
  - `use strict;` satırı bütün değişkenlerin kullanılmadan önce bildirilmesini zorunlu kılar, yazım hatalarından korur, değişkenlere kapsam verir (ekrandan, 02:20:00).
  - Python'da yerleşik hata ayıklayıcı `pdb` vardır (list, up, down, step, next, break gibi komutlar).
- İlk Perl programları
  - `#` ile başlayan satır yorumdur. İlk satırdaki `#!` (shebang) Unix'e dosyanın hangi yorumlayıcıyla çalıştırılacağını söyler; Windows'ta önemsenmez. `\n` satır sonudur.
  - Aynı çıktı tek `print` ile ya da kelime kelime birçok `print` ile üretilebilir (ekrandan, 02:25:00).
  - `while` döngüsünde Perl 1'i doğru, 0'ı yanlış sayar. `sleep 1` bir saniye bekletir. Sabit (constant) değeri değiştirilemeyen kaptır; adları büyük harfle yazılır; Perl büyük-küçük harfe duyarlıdır.
  - Değişken kabı (variable container): değeri programın ömrü boyunca değişebilir; en basit türü skalerdir, bir sayı, kelime, cümle ya da disk dosyası tutabilir (ekrandan, 02:30:00). Başlangıç değeri verilmeyen sayısal skaler 0 olur, ama açık bir başlangıç değeri vermek iyi uygulamadır. `$count++` bir artırır.
  - Seçim (if/else) yapısı C'dekine benzer. `oddeven2` programı 1'den 4'e kadar her sayının tek ya da çift olduğunu yazar (ekrandan, 02:40:00).
- Veri dosyalarını işleme
  - Perl'de giriş işleci `<>`'dir; standart girişten bir satır okuyup döndürür (ekrandan, 02:45:00). Başka giriş belirtilmezse standart giriş klavyedir; program giriş gelene kadar bekler. Standart çıkış ve standart hata öntanımlı olarak ekrandır (STDIN, STDOUT, STDERR).
  - `perl getlines.pl oddevent.pl` gibi bir komutta dosya adı verildiğinde program girişi dosyadan okur ve içeriği ekrana basar (ekrandan, 02:50:00). Program adından sonra gelenler komut satırı argümanlarıdır; birden çok dosya verilebilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- DNA dizisi nitel veridir
  - Bir öğrenci nicel dedi; hoca harflerin sembol olduğunu, sayısal nicelik olmadığını, bu yüzden verinin nitel olduğunu vurguladı.
- Kilo baz çifti $10^3$'tür
  - 1 kb = $10^3$ bp; bellekteki gibi $2^{10}$ ile karıştırılmamalıdır.
- Bilgisayar "elektronik aptal"dır
  - Bilgisayarın yaratıcılığı yoktur, ne söylenirse tam olarak onu yapar. Aynı probleme farklı bilgisayarlar farklı sonuç veriyorsa bir yanlışlık vardır.
- Hata iletilerini dikkatle okuyun
  - Yeni başlayanlar hatayı saatlerce yanlış yerde arar; Perl ve Python hatanın yerini söylemeye çalışır.
- Değişkenlere başlangıç değeri verin
  - Kısa programlarda sorun olmaz, ama yüzlerce satırlık programlarda açık başlangıç değeri kodu denetlemeyi kolaylaştırır.

## Kısa Tekrar Notları

- tRNA: 74-95 nükleotit, amino asidi ribozoma taşır.
- Merkezî dogma: replikasyon, transkripsiyon (çekirdekte), translasyon (sitoplazmada, ribozomda).
- Gen: kalıtım birimi; genom: bütün DNA; transkriptom: bütün mRNA'lar; proteom: bütün proteinler.
- DNA dizisi: harf dizisi ya da sembol listesi; nitel veri.
- UniProt kaydı alanları: ID, AC, DE, GN, OS, DR, FT, SQ.
- Üç nükleotit veritabanı: GenBank (NCBI), ENA/EMBL-Bank (EBI), DDBJ; INSDC ile eşgüdümlü.
- 1 kb = $10^3$, 1 Mb = $10^6$, 1 Gb = $10^9$ bp; insan genomu yaklaşık 3 Gb.
- Erişim numarası: dizinin etiketi.
- Bilgisayar: donanım + yazılım; işlevler: işleme, saklama, taşıma, denetim.
- Katmanlar: uygulamalar, araçlar, işletim sistemi, donanım.
- Derlenen (C, Fortran, Ada), yorumlanan (Basic), bayt kodlu (Java).
- Üç yapı: sıra, seçim, yineleme.
- Perl: TMTOWTDI, `.pl`/`.plx`; Python: `.py`, Zen of Python.
- `perl -c` sözdizimi, `perl -w` uyarı, `perl -cw` ikisi; `use strict;` bildirimi zorunlu kılar.
- Python hata ayıklayıcı: `pdb`.
- `<>` giriş işleci; öntanımlı giriş klavye, çıkış ve hata ekran.

## Detaylı Açıklamalar

- Ders, moleküler biyolojinin temellerinin kalan kısmıyla başladı. tRNA en fazla yaklaşık 100 harflik küçük bir RNA'dır ve çeviri sırasında amino asitleri ribozoma getirir. Merkezî dogma şekli DNA'nın kendini eşlemesini, çekirdekte mRNA'ya yazılmasını, mRNA'nın çekirdek zarından sitoplazmaya geçmesini ve ribozomda proteine çevrilmesini gösterir. Genom büyüklüğü ve gen sayısı organizmalar arasında değişir; fare ile insanın gen sayısı yakın olduğu halde genom büyüklükleri farklıdır. Bu yüzden genom büyüklüğü tek başına karmaşıklığı belirlemez.
- Bilgisayarda biyomedikal veriyi temsil etmek için önce verinin türü belirlenir. Kan hücresi sayısı nicel bir bilgidir. DNA dizisi ise A, C, G, T harflerinden oluşan bir dizgedir ve her harf bir sembol olduğu için nitel veridir. Slaytta yaklaşık 200 harflik bir DNA dizisi parantez içinde sembol listesi olarak gösterildi (ekrandan, 00:20:00).
- Protein veritabanı kayıtları iki harfli satır kodlarıyla düzenlenir. İnsan insülini kaydında 110 amino asitlik öncül protein, 1-24 arası sinyal peptidi, 25-54 arası B zinciri, 57-87 arası C peptidi, 90-110 arası A zinciri, zincirler arası disülfit bağları ve sarmal/iplik/dönüş yapılarının konumları yer alır (ekrandan, 00:25:00). Alanların ayrıntılı açıklaması ExPASy sitesindeki belgelerdedir.
- Nükleotit dizileri üç büyük merkezde saklanır ve bu merkezler verilerini INSDC çatısı altında eşgüdümle paylaşır. Dizi depolarının büyüme hızı giderek artmaktadır. Kayıtlara erişim numaralarıyla ulaşılır; genom tarayıcıları bu verileri görsel olarak gezmeyi sağlar.
- Dersin ikinci yarısı hesaplamaya ve programlamaya ayrıldı. Bir problem çözülürken her düzeyde seçim yapılır: önce yöntem (örneğin karekök için Newton-Raphson ya da denklem sistemi için Gauss yok etme), sonra dil, sonra işlemci mimarisi. Algoritma düzeyinde adımlar belirsizliksiz ve sonlu olmalıdır; komut kümesi mimarisi bilgisayarın yapabileceği komutları, veri türlerini ve adresleme kiplerini belirler.
- Perl ve Python betik dilleridir. Perl'de `-c` ile sözdizimi, `-w` ile olası anlam sorunları denetlenir. Örneğin `print` sözcüğünün hemen ardından noktalı virgül gelip dizge ondan sonra yazılırsa sözdizimi doğrudur, ama dizge boşlukta kalır; `-w` bunu "Useless use of a constant ... in void context" uyarısıyla bildirir. `oddeven2` programı `HOWMANY` sabiti 4 olan bir `while` döngüsünde sayacı artırır ve `$count % 2 == 0` koşuluyla "even" ya da "odd" yazar; çıktı sırasıyla odd, even, odd, even olur (ajan tarafından perl ile çalıştırılarak doğrulandı).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
