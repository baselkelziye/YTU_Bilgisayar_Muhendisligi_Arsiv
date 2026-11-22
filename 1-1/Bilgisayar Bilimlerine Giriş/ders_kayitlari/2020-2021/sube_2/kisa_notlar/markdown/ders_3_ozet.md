# Ders 3 Çalışma Özeti

## Genel Konular

- Bilgisayar sisteminin bileşenleri
  - Slayttaki katmanlı şemada dört bileşen vardır: bilgisayar donanımı (computer hardware), işletim sistemi (operating system), sistem ve uygulama programları (compiler, assembler, text editor, database system) ve kullanıcılar (user 1 ... user n) (ekrandan, 00:20:00).
  - Bilgisayar sistemi yalnız masaüstü bilgisayar değildir: tablet, cep telefonu, PC, mainframe, sunucu, mikrodenetleyicili bir buzdolabı ya da dijital saat de bir bilgisayar sistemidir.
  - Temel iki kaynak işlemci (CPU) ve bellektir (memory). Kaynaklar yeterliyse donanımın üzerinde işletim sistemi çalışır. Küçük mikrodenetleyicilerde (8, 16, bazen 32 bit) uygulama işletim sistemi olmadan doğrudan donanımda çalışabilir; buna "bare metal" denir.
  - Her bilgisayar sisteminde sonunda bir kullanıcı faktörü vardır.
- İşletim sisteminin görevi
  - İşletim sistemi olmasaydı her uygulama klavye, ekran, disk, USB gibi bütün çevre birimlerinin sürücülerini (driver) kendi içinde taşımak zorunda kalırdı. İki sayı alıp ekrana yazan bir program bile klavye ve ekran sürücüsü yazmayı gerektirirdi.
  - Bare metal çalışmada da üretici genellikle bir kütüphane verir; geliştirici mikrodenetleyicinin bileşenlerini bu kütüphanedeki fonksiyonları çağırarak kullanır.
  - En temel tanım: işletim sistemi bir **kaynak yöneticisidir**. Kaynakların uygulamalar tarafından verimli kullanılmasını sağlar.
  - İşlemci yönetimi: bir işlem G/Ç (I/O) beklerken işletim sistemi onu işlemciden alır, G/Ç kuyruğuna koyar ve sıradaki işlemi çalıştırır. Böylece işlemci boşta (idle) kalmaz.
  - Bellek yönetimi: her işleme sanal adres uzayı (virtual address space) verilir. Toplam gerçek ihtiyaç fiziksel belleği aşarsa az kullanılan bellek parçaları diske yazılır.
- Eş zamanlılık (concurrency) ve paralellik
  - Concurrency: tek işlemcide A, B, C işlerinin parça parça sırayla çalıştırılması. İşler birbirinin bitmesini beklemeden ilerler.
  - Paralellik: birden fazla işlemcide işlerin gerçekten aynı anda çalışması; bunun için birden fazla kaynak gerekir.
  - Tek işlemcili sistemde çoklu iş parçacığı (multithreading) yalnız concurrency sağlar; işlemci birden fazlaysa paralel çalışma olur. Java kodu donanım yerine işletim sisteminin üzerindeki Java sanal makinesinde (JVM) çalışır.
- Sistem programları
  - Sistemi yönetmek ve geliştirmek için gereken temel programlardır: metin editörü (yapılandırma dosyalarını değiştirmek için), kabuk (shell, komut satırı), derleyici (compiler) ve assembler.
  - Konsol tabanlı vi editörü en eski ve hâlâ kullanılan editörlerden biridir; farklı çalışma kipleri (düzenleme, görüntüleme, makro vb.) vardır.
- Bilgisayar organizasyonu
  - Slayttaki şemada CPU, disk denetleyicisi (disk controller), USB denetleyicisi (mouse, klavye, yazıcı) ve grafik adaptörü (monitör) ortak yolla belleğe bağlıdır (ekrandan, 00:50:00).
  - Birimler arası iletişim bellek üzerinden olur. Günümüzde CPU disk denetleyicisine "şu adresteki veriyi getir, belleğin şu bölgesine yaz" der ve aradan çekilir; bu sırada başka işlere geçebilir.
  - Bellek yolu tek olduğu için bellek erişimi darboğazdır (bottleneck).
- Bilgisayarların tarihçesi
  - Abaküs mekanik hesaplamanın başlangıcı olarak gösterildi.
  - Charles Babbage'ın Difference Engine'i (Fark Makinesi) çarklarla astronomik ve matematik tabloları hesaplıyordu; 20-30 basamaklı sayılarla çalışabiliyor ama mekanik hassasiyet yüzünden son basamaklarda hata yapabiliyordu.
  - Babbage daha sonra Analytic Engine adını verdiği, ev büyüklüğünde, 6 buhar makinesiyle beslenen **programlanabilir** bir cihaz tasarladı; bunun için delikli kart (punched card) kullandı (ekrandan, 00:55:00).
  - Ada Byron (Lovelace) Analytic Engine için ilk programları yazdı; ilk programcı bir kadındır.
  - Bilgisayarın ortaya çıkışında temel ihtiyaç ordunun ağır silahları için ateşleme tablolarının hesaplanmasıydı; bu hesapları kadınlar elle yapıyordu (ekrandan, 01:00:00).
  - ENIAC: 1946'da U. Penn.'de US Army için yapılan ilk genel amaçlı bilgisayar; Electronic Numerical Integrator and Calculator; J. Presper Eckert ve John Mauchly; 30 ton, 1500 sq. ft., 500.000 dolar; veri girişi delikli kartla, programlama kablo ve anahtarları elle değiştirerek; decimal veriyle çalışır; matematiksel hesaplar, hava tahmini ve atom enerjisi hesapları (ekrandan, 01:15:00).
  - İlk elektronik bilgisayar olarak Atanasoff'un 1939 prototipi (ABC) anıldı.
  - Mainframe'ler: oda ya da bina büyüklüğünde, her bileşeni ayrı kasa olan makineler. Bugün üretmeye devam eden IBM'dir; NASA son mainframe'ini 2012'de kapattı (ekrandan, 01:25:00). Sanallaştırma teknolojisinin iyi uygulandığı ilk yer mainframe'dir.
  - Mainframe'lerin yüksek erişilebilirliği (high availability): birden fazla güç girişi, işlemci ve depolama birimlerinde pil yedeği, birden fazla denetleyici; elektrik kesilince önbellekteki veriyi diske yazıp düzgün kapanma.
  - Kişisel bilgisayarlar: 1965'te Olivetti Programma 101 (3200 dolar) ilk kişisel bilgisayarlardan sayıldı; sonra Apple gibi bilgisayarlar geldi.
- Donanım fiyat farkları
  - Sunucu diskleri 7/24 çalışmak üzere tasarlanır; masaüstü diskleri öyle değildir. Sunucu dönen diskleri daha yüksek devirde döner (10.000-15.000 RPM), daha çok akım çeker ve daha çok ısınır. Bileşenlerin çalışma aralığı, malzeme ve kalite fiyatı belirler.
- Yazılım türleri
  - Sistem yazılımı: işletim sistemiyle iç içe (tightly coupled) çalışan editör, kabuk, derleyici.
  - Uygulama yazılımı: sunum programı, tarayıcı gibi programlar.
- Programlama dillerinin nesilleri
  - 1. nesil, makine kodu: komutlar 0 ve 1 ile yazılır. Örnek iki sayının toplanması için 32 bitlik makine kodu: `000000 00001 00010 00110 00000 100000` (ekrandan, 01:40:00).
  - 2. nesil, assembly dilleri: ADD, MOV gibi İngilizce kısaltmalar kullanılır. Bilgisayar yalnız makine kodunu işleyebilir; assembly kodunu makine koduna **assembler** çevirir (ekrandan, 01:45:00). Her işlemci ailesinin ayrı assembly dili vardır (Intel x86 ile PowerPC farklıdır; PowerPC'de taşıma load ve store ile yapılır).
  - 3. nesil, yüksek seviyeli diller: 1950-1970 arasında COBOL, Fortran, Pascal, C; Java da bu gruptadır. Taşınabilirlik ve kolaylık için İngilizce komutlara dayanır.
  - Nesneye dayalı programlama: yazılımlar büyüyüp karmaşıklaşınca (stok kontrol, ERP, CRM) 1967'den itibaren ortaya çıktı.
  - Yorumlayıcı (interpreter): program bir seferde değil satır satır işlenir; pek çok dil hem derleyici hem yorumlayıcı ile çalışabilir; örnekler Basic, Lisp, MATLAB, SmallTalk (ekrandan, 01:50:00).
  - 4. nesil: rapor üretme dilleri, veritabanı sorgulama dili SQL, PL/SQL, MATLAB.
  - 5. nesil: belirli amaca yönelik, kısıtlı diller; sürükle-bırak blok dilleri (Simulink vb.) ve yapay zekâ ile doğal dil işlemede kullanılan Prolog, Lisp gibi diller.
  - Cross compilation: A mimarisinde çalışan derleyicinin B mimarisi için çıktı üretmesi (ör. PC'de yazılan kodun ARM tabanlı bir mikrodenetleyici için derlenmesi).
- Sayı sistemleri
  - İkili (binary) sistemde yalnız 0 ve 1 kullanılır; iki sayısı "10" yazılır; toplam iki olunca bir sonraki haneye aktarılır (elde). İkili yazım genellikle daha uzundur, çünkü her hane daha az bilgi ifade eder; hanelere **bit** denir (ekrandan, 02:10:00).
  - Dört bitle ifade edilebilen en büyük değer $1+2+4+8 = 15$'tir.
  - Sekizli (octal) sistemde her hane ikili sistemde üç haneye karşılık gelir. PDP-8 gibi bazı eski sistemler sekizli sistemi kullanıyordu.
  - Ondalık (decimal) sistem: Hindu-Arabic olarak da bilinir, 10 rakam kullanılır, kesirli sayılarda **nokta** işareti kullanılır. $543.21 = (5\times10^2)+(4\times10^1)+(3\times10^0)+(2\times10^{-1})+(1\times10^{-2})$ (ekrandan, 02:15:00).
  - Onaltılı (hexadecimal) sistem: 10 rakam ve 6 harf (A=10, B=11, C=12, D=13, E=14, F=15) kullanılır; her hane ikili sistemde dört haneye karşılık gelir. 32 ya da 64 bitlik sayılar ve adresler için daha kısa ve okunaklıdır.
  - Örnek: $256058_{10} = 11\,1110\,1000\,0011\,1010_2 = 764072_8 = 3E83A_{16}$ (ekrandan, 02:20:00).
- Bit, nibble, byte, word
  - Her ikili basamak bir bittir; 8 bit byte, 16 bit word, 32 bit double word olarak anıldı.
  - İkili sayılar okunabilirlik için dörderli gruplar hâlinde yazılır; dört bitlik gruba **nibble** denir ve her nibble bir onaltılı haneye karşılık gelir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Yuvarlak cevap vermemek
  - "Kolaylaştırmak için" gibi bir cevap yetmez; kolaylığın nereden geldiği açıklanmalıdır. İşletim sistemi örneğinde kolaylık, sürücülerin ve kaynak yönetiminin uygulamadan alınıp işletim sistemine verilmesinden gelir.
- İşletim sistemi = kaynak yöneticisi
  - Farklı kaynaklarda uzun tanımlar olsa da en temel tanım budur.
- Concurrency ile paralellik farklıdır
  - Concurrency tek kaynağı paylaştırır; paralellik birden fazla kaynak ister.
- Onluktan ikiliye çevirmede bölme yöntemi beklenmiyor
  - İkiye bölüp kalanları tersten dizme yöntemi bilinse de hoca pratik yolu istedi: basamak değerlerini (1, 2, 4, ..., 128, 256) bilip sayının içinde hangilerinin olduğunu bulmak.
- En az ikili ve ondalık sistem çok iyi bilinmeli; onaltılı sistem programlamada sık görülecek.
- Kesirli sayılarda virgül değil nokta
  - Floating point ve fixed point konuları da noktadan yürüyecek.
- Slayttaki dönüşüm hatası
  - Hoca "Sayı Sistemleri Arasında Geçiş" slaytındaki sekizli ve onaltılı karşılıkların yanlış olduğunu söyledi.

## Kısa Tekrar Notları

- Bilgisayar sistemi: donanım, işletim sistemi, sistem/uygulama programları, kullanıcı.
- İki temel kaynak: işlemci ve bellek.
- İşletim sistemi olmadan çalışmaya bare metal denir.
- İşletim sistemi bir kaynak yöneticisidir: işlemci zamanını paylaştırır, belleği yönetir, sürücüleri sunar.
- G/Ç bekleyen işlem işlemciden alınır, işlemci boşta bırakılmaz.
- Sanal adres uzayı fiziksel bellekten büyük olabilir; taşan kısım diske yazılır.
- Concurrency: parça parça sırayla; paralellik: aynı anda, birden fazla işlemcide.
- Birimler arası haberleşme bellek üzerinden; bellek darboğazdır.
- Babbage: Difference Engine, sonra programlanabilir Analytic Engine (delikli kart).
- İlk programcı: Ada Byron (Lovelace).
- ENIAC: 1946, ilk genel amaçlı bilgisayar, decimal, kabloyla programlama.
- Mainframe: yüksek erişilebilirlik; IBM hâlâ üretiyor.
- Dil nesilleri: makine kodu, assembly, yüksek seviyeli, 4. nesil (SQL), 5. nesil (amaca yönelik).
- Assembler: assembly kodunu makine koduna çevirir.
- Yorumlayıcı: satır satır çalıştırır.
- Sekizlide 1 hane = 3 bit; onaltılıda 1 hane = 4 bit (nibble).
- $195_{10} = 1100\,0011_2$.
- $1000\,0101\,1110\,0011_2 = 85E3_{16}$.

## Detaylı Açıklamalar

- **İşletim sistemi neden var?** Donanımı doğrudan kullanan bir uygulama, çalıştığı her çevre biriminin nasıl kullanılacağını kendi içinde taşımak zorundadır. Kullanıcıdan iki sayı alıp ekrana yazan küçük bir program bile klavye ve ekran sürücüsü gerektirir. İşletim sistemi bu sürücüleri bir kez sunar ve uygulamaları birbirinden yalıtarak aynı anda çalıştırır. İşlemci tarafında bir işlem G/Ç beklediğinde onu kenara alıp başka bir işlemi çalıştırır; hangi işlemin seçileceği (öncelik, burst time vb.) işletim sistemleri dersinde ayrıntılı işlenecek. Bellek tarafında her işleme, örneğin 4 GB belleği olan bir makinede, "4 GB senin" diyen sanal bir adres uzayı verir. Üç işleme 4'er GB verilmesi toplam 12 GB "satmak" demektir; gerçek ihtiyaçlar 2 GB, 1,5 GB ve 1 GB olursa toplam 4,5 GB fiziksel 4 GB'ı aşar ve az kullanılan bellek parçaları diske taşınır.

- **Concurrency örneği.** Tek işlemci ve iki iş olsun: birincisi 30 birim, ikincisi 3 birim sürsün. Sırayla çalıştırılırsa kısa iş 30 birim bekler. Her işe 2'şer birim verilerek dönüşümlü çalıştırılırsa kısa iş ikinci turunda tamamlanıp sistemden çıkar; sistemdeki yük azalır, bekleme süresi düşer, sistem etkileşimli hâle gelir. Paralellikte ise iki işlemciye birer iş verilir.

- **Bilgisayar organizasyonu.** Eski kişisel bilgisayarlarda diskten okuma işini de işlemci yapıyordu: veriyi okuyor, belleğe yazıyor, sonra işliyordu. Bugün CPU işi disk denetleyicisine devreder; denetleyici veriyi okuyup belleğe yazar, CPU bu sırada başka işlere geçer. Bütün denetleyiciler ve CPU aynı bellek yolunu kullandığı için temel darboğaz belleğe erişimdir.

- **Ada Byron'ın programı.** Hoca slaytta Analytic Engine için yazılmış kart dizisini anlattı. Satırlar N tipi kartla başlıyordu: biri 123 değerini 1 numaralı bellekte, diğeri 456 değerini 2 numaralı bellekte saklıyordu. Ardından boş bir yorum kartı, toplama kartı ve "L1, L2, S3" kartları geliyordu: 1. ve 2. adresi yükle, topla, sonucu 3. adrese yaz. <!-- BELİRSİZ: Slayttaki kart sözdizimi karede yok; yalnız altyazıdan aktarıldı (00:57:51-00:59:50). -->

- **Mainframe ve yüksek erişilebilirlik.** Mainframe'in işlemci birimi yüzlerce çekirdek içerir, gazlı ya da sıvı soğutulur. En az dört elektrik girişi farklı kaynaklara bağlanır; hepsi kesilse bile pil yedeği sayesinde işlemci elektriğin gittiğini anlar, yeni iş almaz, önbellekteki her şeyi yazıp düzgün kapanır. Depolama biriminde de iki ya da dört denetleyici ve disk gruplarının altında pil yedeği vardır. Bu yüzden mainframe'ler pahalı ve niş ürünlerdir; bugün bunun yerine çok sayıda ucuz bilgisayarla yazılımsal çözümler tercih ediliyor.

- **Dil tasarımı sorusu.** Bir öğrenci yeni bir dilin bilgisayara nasıl "tanımlandığını" sordu. Hoca, dilin önce tasarlanması (anahtar kelimeler, sözdizimi kuralları) gerektiğini, sonra derleyicinin bu kurallara göre yazılmış kodu bulunduğu mimarinin (ör. Intel x86) makine koduna ve işletim sisteminin kurallarına uygun çıktıya çevirdiğini anlattı. Başka mimari için derleyicinin o mimariye uyarlanması ya da cross compiler kullanılması gerekir. Derleyici tasarımı ayrı bir derste işlenecek.

- **Onluktan ikiliye pratik çevirme.** Basamak değerleri sağdan sola 1, 2, 4, 8, 16, 32, 64, 128, 256 diye gider. 195 için 256 büyüktür, 128 sığar: $195-128=67$. 64 sığar: $67-64=3$. 32, 16, 8, 4 sığmaz; $3 = 2+1$. Sonuç $1100\,0011_2$. Bölme yöntemiyle de aynı sonuç çıkar ama hoca bu pratik yolu istedi.

- **İkiliden onaltılıya ve sekizliye.** Sayı sağdan dörderli gruplara ayrılır, her grup bir onaltılı haneye çevrilir: $256058$ örneğinde sağdan $1010=A$, $0011=3$, $1000=8$, $1110=E$, $11=3$, yani $3E83A$. Sekizli için üçerli gruplar alınır: $111\,110\,100\,000\,111\,010 = 764072_8$. Slayttaki ikinci örnekte $1000\,0101\,1110\,0011$ sayısını hoca derste $8, 5, E, 3$ diye çözdü.

- **Ders sonrası not:** Slaytta $1\,000\,010\,111\,100\,011$ sayısının sekizli karşılığı "173", $1000\,0101\,1110\,0011$ sayısının onaltılı karşılığı "A09C" yazıyordu (ekrandan, 02:25:00). Hoca slaytın yanlış olduğunu söyledi. Python ile kontrol edildi: iki gösterim aynı sayıdır, $= 34275_{10} = 102743_8 = 85E3_{16}$.

- **Ders sonrası not:** Altyazıda ENIAC tasarımcısı "Maculay" diye geçiyor; slaytta "John Mauchley" yazıyor. Doğru yazımı büyük olasılıkla John Mauchly'dir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
