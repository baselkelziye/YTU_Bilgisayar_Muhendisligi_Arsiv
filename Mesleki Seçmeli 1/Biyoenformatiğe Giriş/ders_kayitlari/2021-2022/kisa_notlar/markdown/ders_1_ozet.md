# Ders 1 Çalışma Özeti

<!-- BELİRSİZ: Bu kaydın altyazısında uzun Whisper tekrarları ve anlaşılmayan bölümler çok fazladır. Özet, okunabilen altyazı parçaları ve ekran karelerinden kurulmuştur; karede görülmeyen ve altyazıda bozuk kalan yerler eksik olabilir. -->

## Genel Konular

- Hesaplamalı biyolojinin alt alanları
  - Genomik: genomun, yani bir organizmadaki genetik malzemenin (DNA) tamamının incelenmesidir; bir organizmadaki bütün genleri ve aralarındaki ilişkileri, büyüme ve gelişme üzerindeki ortak etkilerini belirlemek için inceler (ekrandan, 00:05:00).
  - Proteomik: proteomun büyük ölçekli incelenmesidir. Proteom, bir organizmada, sistemde ya da biyolojik bağlamda üretilen proteinlerin kümesidir; sabit değildir, hücreden hücreye ve zamanla değişir.
    - Proteomik, proteinlerin ne zaman ve nerede ifade edildiğini, üretim hızlarını, düzenlenmelerini, kararlı durum miktarlarını ve nasıl değiştirildiklerini araştırır.
    - Tipik sorular: belirli bir proteinle hangi proteinler etkileşir, hangi proteinler belirli bir hücre içi bölmede bulunur, hangi proteinler belirli bir biyolojik sürece katılır.
  - Yapısal biyoenformatik (yapısal genomik): protein, RNA ve DNA gibi biyolojik makromoleküllerin üç boyutlu yapısının analizi ve tahminiyle ilgilenir; katlanma ve yerel motif karşılaştırmaları, moleküler katlanma ilkeleri, evrim, bağlanma etkileşimleri ve yapı-işlev ilişkileri konularıdır.
  - Fonksiyonel genomik: genomik ve transkriptomik projelerin ürettiği büyük veriyi gen işlevlerini ve etkileşimlerini betimlemek için kullanır.
- Biyoenformatiğin önemi ve uygulamaları
  - GenBank veritabanının büyüme grafiği gösterildi; veri miktarı bugün çok daha yüksektir.
  - Hastalıklarla mücadele: kalıtsal hastalıklar (örneğin diyabet) ve COVID gibi viral hastalıklar.
  - İlaç geliştirme yaşam döngüsü: keşif (2-10 yıl), klinik öncesi test (laboratuvar ve hayvan testleri), ardından klinik faz çalışmaları ve ilgili kurumun onayı (ekrandan, 00:15:00).
  - "Killer application": biyoteknoloji sektöründe herkes bir sonraki "killer app"i bulmayı umar (ekrandan, 00:20:00). İlaç şirketleri bilgisayarlaştırmayı kişiye özel, daha küçük ölçekli ilaç üretiminin çözümü olarak görür; kişiselleştirilmiş tıp hedeflenir (ekrandan, 00:25:00).
  - Hesaplama uygulamaları: genom analizine dayanarak ilaç etkinliğini ve yan etkilerini tahmin etme, protein yapılarını görselleştirme, rakip ilaçların göreli etkinliğini yaşam kalitesi ve maliyet açısından Faz IV klinik deneyler sırasında olası sonuçların Markov benzetimiyle gösterme.
- Biyoenformatikte araçlar ve çalışma alışkanlıkları
  - NCBI, EBI gibi merkezi kaynaklar, genom tarayıcıları, web tabanlı ve komut satırı araçları vardır.
  - Linux kullanmayı ve Python, Perl ya da R öğrenmek gerekir; bu derste çoğunlukla Perl kullanılacaktır.
  - Programlama öğrenmek için kitap ve derslerin yanında çevrim içi eğitim siteleri vardır (codeschool, codecademy, datacamp, software-carpentry, github) (ekrandan, 00:40:00).
  - Tekrarlanabilir araştırma: bilim birikimli ve ilerleyicidir; web tabanlı ya da komut satırı araç kullanılsın, araştırma hem araştırmacının kendisi hem başkaları tarafından tekrarlanabilir yapılmalıdır (ekrandan, 00:35:00).
  - İş akışı iyi belgelenmeli, karmaşık komutlar ve URL'ler metin dosyalarında tutulmalı, bilgisayardaki bilgi düzenli olmalı, veri başkalarına açılmalı, programlara açıklama satırı yazılmalıdır.
  - Metaveri, verinin kendisi kadar önemlidir; açıklayıcı metaverisi olmayan büyük bir veri dosyası birkaç ay sonra anlaşılamayabilir.
- Temel kavramlar: veri, bilgi, bilgi birikimi (knowledge)
  - Veri: yorum ya da analiz eklenmemiş, işlenmemiş olgu ve rakamlardır; örnek: "Ham petrolün fiyatı varil başına 80 dolardır" (ekrandan, 00:45:00).
  - Bilgi (information): yorumlanmış ya da işlenmiş, kullanıcı için anlamı olan veridir.
  - Zamanla biriken bilgiden bilgi birikimi (knowledge) oluşur.
- Sistem, bilgi sistemi, dijital sistem
  - Sistem: belirli amaçlara ulaşan bütünleşik öğeler kümesidir; bileşenleri vardır, bileşenler birbiriyle ilişkilidir ve ortak bir amaç etrafında toplanır.
  - Bilgi sistemi: kuruluşların bilgilerini saklama, taşıma, düzenleme ve işleme yollarıdır (ekrandan, 00:50:00). Bilgi teknolojisi, bilgi sistemlerini gerçekleştiren donanım ve yazılım bileşenleridir.
  - Dijital sistem: ayrık girişler ve ayrık iç bilgi (sistem durumu) alıp ayrık çıkışlar üretir (ekrandan, 00:55:00).
- Sürekli bilginin ayrık hale getirilmesi
  - Bilgisayarların belleği ve işlem gücü sınırlıdır; sonsuz (sürekli) bilgi saklanamaz ve işlenemez, sonlu hale getirilmelidir.
  - Örnekleme (sampling) ve nicemleme (quantization) ile sürekli bilgi ayrık bilgiye çevrilir, sonra ikili kodlanır. 8 seviye için $\log_2 8 = 3$ bit yeter.
  - İki hata kaynağı vardır: örnekler arasındaki bilgi kaybolur ve örnek değerleri yuvarlanır (nicemleme hatası). Buna rağmen elde kalan bilgi genelde yeterlidir.
- Sayı sistemleri ve sayısal veri türleri
  - Taban $r$ olan konumsal sayı sisteminde bir sayı $A_{n-1}\dots A_1A_0 . A_{-1}\dots A_{-m}$ basamak dizisiyle gösterilir ($0 \le A_i < r$) ve değeri $\sum_{i=0}^{n-1} A_i r^i + \sum_{j=-m}^{-1} A_j r^j$ (tam kısım + kesir kısmı) olur (ekrandan, 01:05:00).
  - İşaretsiz ikili tamsayı: $N$ bit ile $0$ ile $2^N-1$ arası (ekrandan, 01:10:00).
  - İşaretli ikili tamsayı (ikiye tümleyen): $-2^{N-1}$ ile $2^{N-1}-1$ arası; $a$'dan $-a$ elde etmek için bütün bitler ters çevrilir ve 1 eklenir (ekrandan, 01:15:00).
  - Kayan noktalı sayılar (IEEE-754): örnek $25.75 \Rightarrow 00011001.110 \Rightarrow 1.1001110 \times 2^4$ (ekrandan, 01:20:00); daha fazla duyarlık için çift duyarlıklı biçim kullanılır.
- Sayısal olmayan veri ve kodlama
  - Herhangi bir ikili birleşim (kod sözcüğü), veri benzersiz kodlandığı sürece herhangi bir veriye atanabilir (ekrandan, 01:25:00).
  - Renkler piksel başına bitlerle kodlanır: siyah-beyaz için 1 bit, 256 renk için 8 bit.
  - Eşlik (parity) biti: verideki 1'lerin sayısı çift ya da tek olacak şekilde düzenlenir.
  - ASCII karakter kodları ve Unicode; ikili mantık işlemleri Boole cebiriyle gerçekleştirilir.
- Biyomedikal verinin doğası
  - Biyoloji ve tıp kitaplarında fotoğraflar, diyagramlar, çizimler, kimyasal formüller ve uzun betimlemeler bulunur; bunlar farklı veri türleridir.
  - Biyolojik nesnelerin bazı özellikleri sayısaldır (kandaki bir kimyasalın yoğunluğu, tümör boyutu, hücredeki pH, vücut ağırlığı); bazıları ise yalnız adlandırılabilen niteliklerdir (bir proteinin hangi genden üretildiği, bir organın var olup olmadığı) (ekrandan, 02:00:00).
  - Metaveri türleri: betimleyici, yönetimsel (teknik), koruma (uzun süreli yönetim), haklar (fikri mülkiyet), yapısal metaveri; işaretleme dilleri de metaveri sayılır. Örnekler: verinin oluşturulma yolu, amacı, zamanı, oluşturanı, ağdaki konumu, kullanılan standartlar, dosya boyutu.
- Moleküler biyolojiye giriş
  - Hücre: canlı organizmaların yapısal ve işlevsel birimi, yaşamın yapı taşıdır. Tipik hücre boyutu yaklaşık 10 mikrometre, kütlesi yaklaşık 1 nanogramdır.
  - Prokaryotlarda çekirdek zarfı ve çekirdek yoktur; çoğu hücre içi organel de yoktur. İki türü vardır: bakteriler ve arkeler. Mitokondri, kloroplast ve Golgi aygıtı gibi organellerin işlevlerini plazma zarı üstlenir. Üç mimari bölgeleri vardır; ilki hücre yüzeyine bağlı flagella ve pili gibi uzantılardır (ekrandan, 02:10:00).
  - Ökaryotlarda DNA, histon proteinleriyle ilişkili kromozomlar halinde çekirdekte tutulur.
  - Kromozom adı "chroma" (renk) ve "soma" (beden) sözcüklerinden gelir. İnsanda 22 çift otozom ve 1 çift cinsiyet kromozomu vardır (ekrandan, 02:15:00).
  - DNA (deoksiribonükleik asit) genetik talimatları uzun süreli saklar; bu yüzden bir bilgi taşıyıcısıdır. Genetik bilgi taşıyan DNA parçalarına gen denir.
  - Nükleotitler: adenin (A), sitozin (C), guanin (G), timin (T); A ile T, G ile C eşleşir. Bu nedenle DNA çift sarmal olsa da yalnız bir zincirin bazlarını göstermek yeter (ekrandan, 02:30:00).
  - Genetik kod: genetik malzemedeki bilginin canlı hücrelerde proteine çevrilme kurallarıdır. Translasyonu ribozom yapar; mRNA'nın belirlediği sırada amino asitleri bağlar, tRNA mRNA'yı üçer nükleotit okur (ekrandan, 02:25:00).
  - Kodon: üç nükleotitlik birleşim; $4^3 = 64$ olası kodon vardır. Başlangıç kodonu AUG, durdurma kodonları UAA, UAG, UGA'dır. 61 kodon amino asit kodlar (AUG dahil), oysa yalnız 20 amino asit vardır, yani kodda fazlalık vardır (ekrandan, 02:35:00).
  - Amino asitler proteinlerin yapı taşlarıdır; bazıları suyu sever (hidrofilik), bazıları suyu sevmez (hidrofobik). Kısa zincirlere peptit, uzun zincirlere polipeptit ya da protein denir.
  - Proteinler enzim olarak tepkimeleri hızlandırır, sinyal görevi görür ve hücre ile doku yapısının bileşenidir.
  - Örnek vaka, HIV proteazı: virüs hücreye girer, hücre virüsün "kodunu" okur ve HIV proteinlerini üretir (ekrandan, 02:45:00). Virüsün bağlanacağı yere önceden bağlanan ilaçlar enfeksiyonu engelleyebilir; ardından toksikoloji çalışmaları gelir.
  - RNA (ribonükleik asit): genelde tek zincirlidir, şekeri riboz, DNA'da ise deoksiribozdur; timin yerine urasil bulunur. RNA polimeraz enzimleri DNA'dan RNA'yı yazar (transkripsiyon).
  - mRNA işlenmesi: kodlamayan intronlar çıkarılır, eksonlar birleştirilir (splicing); işlenmiş mRNA proteine çevrilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Biyoenformatikte Linux ve bir betik dili bilmek gerekir; derste çoğunlukla Perl kullanılacaktır.
- İş akışını belgelemek, programlara açıklama yazmak ve veriyi metaveriyle saklamak gerekir; aksi halde birkaç ay sonra kişi kendi verisini ve kodunu anlayamaz.
- İkiye tümleyen gösteriminde en anlamlı bit "eksi işareti" diye düşünülürse cevap yanlış olur. Doğru düşünce ağırlıklı sayı sistemidir: en anlamlı bitin ağırlığı negatiftir (5 bitte $-16$), diğer ağırlıklar her zamanki gibidir.
- İkiye tümleyen gösterimi önemlidir, çünkü modern bilgisayarlardaki bütün aritmetik işlemler bu gösterimle yapılır.
- DNA bilgi taşır; dersin başında anlatılan veri işleyip bilgi çıkarma fikri, biyolojik veride de aynıdır.
- Moleküler biyoloji kısmı yorucu gelebilir, ama ders gen ifadesi konuları etrafında döndüğü için bunların anlaşılması gerekir; hesaplama kısmı daha kolay gelecektir.

## Kısa Tekrar Notları

- Genomik: genomun tamamı; proteomik: proteinlerin tamamı, zamanla ve hücreye göre değişir.
- Yapısal biyoenformatik: makromoleküllerin 3B yapısı; fonksiyonel genomik: gen işlevleri ve etkileşimleri.
- İlaç geliştirme uzun sürer (keşif 2-10 yıl); kişiselleştirilmiş tıp biyoenformatiğin "killer app"idir.
- Tekrarlanabilir araştırma: belgele, düzenle, paylaş, metaveri tut.
- Veri: işlenmemiş olgu; bilgi: işlenmiş, anlamlı veri.
- Dijital sistem: ayrık giriş, ayrık durum, ayrık çıkış.
- Sürekli → örnekleme → nicemleme → ikili kod; iki hata: örnekler arası kayıp ve nicemleme hatası.
- $N$ bit işaretsiz: $0 \dots 2^N-1$; ikiye tümleyen: $-2^{N-1} \dots 2^{N-1}-1$.
- $-a$ = bitleri ters çevir + 1; 5 bitte $11101 = -16+8+4+1 = -3$.
- $25.75 = 11001.11_2 = 1.100111 \times 2^4$.
- 256 renk için 8 bit.
- Prokaryot: çekirdek yok (bakteri, arke); ökaryot: DNA çekirdekte, kromozomlar halinde.
- İnsan: 22 çift otozom + 1 çift cinsiyet kromozomu.
- A-T, G-C eşleşir; RNA'da T yerine U.
- $4^3 = 64$ kodon; AUG başlangıç; UAA, UAG, UGA durdurma; 61 kodon → 20 amino asit.
- mRNA işlenmesi: intronlar çıkar, eksonlar birleşir.

## Detaylı Açıklamalar

- Hesaplamalı biyoloji birçok alt alanı kapsar. Genomik bir organizmanın bütün genetik malzemesini inceler ve genlerin birlikte büyüme ve gelişmeyi nasıl etkilediğini anlamaya çalışır. Proteomik ise genomdan farklı olarak değişken bir hedefle uğraşır: aynı organizmada bile hücreden hücreye ve zamanla değişen protein kümesi. Protein etkinliği yalnız ilgili genin ifade düzeyine bağlı değildir, başka birçok etkene de bağlıdır. Bu nedenle protein etkileşimlerini hesaplamalı olarak inceleyen çok sayıda biyoenformatik çalışması vardır. Yapısal biyoenformatik makromoleküllerin üç boyutlu yapısıyla, fonksiyonel genomik ise büyük genom ve transkriptom verisinden gen işlevlerini çıkarmakla ilgilenir.
- Biyoenformatiğin en büyük motivasyonlarından biri hastalıklarla mücadeledir. İlaç geliştirme süreci keşifle başlar, laboratuvar ve hayvan testleriyle sürer, insan üzerinde fazlar halinde klinik deneylerle devam eder ve ilgili kurumun onayıyla biter. Bu süreç yıllar sürer ve çok pahalıdır. Kişiselleştirilmiş tıpta herkesin kendine özgü bir ilacı olması hedeflenir; bu ancak sürecin bilgisayarla kısaltılmasıyla mümkün olabilir. Bu yüzden ilaç şirketleri genom analizi, protein yapısı görselleştirme ve Markov benzetimi gibi hesaplama uygulamalarına yatırım yapar.
- Biyoenformatik çalışırken merkezi veritabanları ve araçlar kullanılır, ama iş akışının düzeni de en az araçlar kadar önemlidir. Karmaşık komutlar, URL'ler ve veri parçaları metin dosyalarında tutulmalı, dosyalar düzenli saklanmalı, veri başkalarıyla paylaşılabilmeli ve her veri dosyasının ne olduğunu açıklayan metaverisi olmalıdır. Programlara açıklama satırı yazılmazsa birkaç ay sonra kişi kendi programını anlamakta zorlanır.
- Bilgisayarlar sonlu bellek ve sonlu işlem gücüyle çalıştığı için sürekli (analog) bilgi doğrudan işlenemez; sonsuz bilgiyi işlemek sonsuz zaman ve sonsuz bellek gerektirirdi. Bu nedenle sürekli bilgi örneklenir, nicemlenir ve ikili kodlanır. Örneğin sinyal 8 seviyeye nicemlenirse her seviye $\log_2 8 = 3$ bitle kodlanabilir. Bu işlemde örnekler arasındaki bilgi kalıcı olarak kaybolur ve örnek değerleri en yakın seviyeye yuvarlanır (nicemleme hatası). Yine de kalan bilgi çoğu uygulama için yeterlidir. Analog ve dijital arasındaki dönüşüm analog-dijital çeviricilerle yapılır.
- Konumsal sayı sistemlerinde her basamak tabanın bir kuvvetiyle çarpılıp toplanır. İşaretsiz ikili tamsayılarda $N$ bit ile $0$ ile $2^N-1$ arası gösterilir; örneğin 3 bitle 0-7, 4 bitle 0-15. İkiye tümleyen gösteriminde de aynı ağırlıklı toplama mantığı geçerlidir, tek fark en anlamlı bitin ağırlığının negatif olmasıdır. 5 bitte ağırlıklar $-16, 8, 4, 2, 1$'dir: $10000 = -16$, $11101 = -16 + 8 + 4 + 1 = -3$ (ekrandan, 01:15:00).
- Kayan noktalı gösterimde sayı ikili yazılır ve noktası en soldaki 1'in sağına kaydırılır. $25.75$ ikili olarak $11001.11$'dir; nokta 4 basamak sola kaydırılınca $1.100111 \times 2^4$ elde edilir (ekrandan, 01:20:00). Noktanın "kayması" bu gösterime adını verir.
- Moleküler biyoloji, biyoenformatik verisinin ana kaynağıdır. Hücreler, prokaryotlar ve ökaryotlar, kromozomlar, DNA, RNA ve proteinler bu verinin anlaşılması için gereken temel kavramlardır. DNA dört harfli (A, C, G, T) bir dizi olarak temsil edilir ve bazlar eşleşik olduğu için tek zincir yeterlidir; slaytta BRCA (meme kanseri geni) çevresinden kısa bir DNA dizisi örnek olarak gösterildi (ekrandan, 02:30:00). Genetik kod, mRNA'daki üçlü kodonları amino asitlere eşler; 64 kodonun 3'ü durdurma kodonudur, kalan 61'i 20 amino asidi kodlar, bu yüzden çoğu amino asit birden fazla kodonla gösterilir (örneğin lizin AAA ve AAG ile, lösin altı farklı kodonla) (ekrandan, 02:35:00).
- HIV proteazı örneğinde virüs hücreye bağlanıp girer, hücre virüsün genetik kodunu okuyup virüs proteinlerini üretir. Bunu önlemenin bir yolu, virüsün bağlanacağı noktaya önceden bağlanan bir ilaç molekülü bulmaktır. Hangi molekülün bu proteine bağlanacağı sorusu biyoenformatik ile araştırılır; ardından ilacın kendisinin zararlı olmadığını göstermek için toksikoloji çalışmaları gerekir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
