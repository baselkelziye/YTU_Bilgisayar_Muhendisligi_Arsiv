# Ders 3 Genişletilmiş Notu: Algoritmadan Programa: Dil Seviyeleri, C Derleme Süreci ve Temel Veri Tipleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Algoritmadan Programa
- 2. Programlama Dillerinin Seviyeleri
- 3. Çeviri, Biçimsel Diller ve Derleme Zincirine İlk Bakış
- 4. C Diline Giriş: Tarihçe, Avantajlar ve Tehlikeler
- 5. Yazılım Üretiminin Aşamaları ve Köprü Benzetmesi
- 6. Derleme Süreci, IDE ve Dev-C++
- 7. Komut Satırından gcc ve Ara Dosyalar
- 8. Derleyici Hataları ve Noktalı Virgül Kuralı
- 9. Tersine Derleme ve Kod Karmaşıklaştırma
- 10. Değişkenler, Sabitler ve Veri Tipleri
- 11. Giriş-Çıkış: printf ve scanf
- 12. Karışık Tipli İşlemler ve Tip Dönüşümleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Algoritmadan Programa

Önceki derslerde algoritma kavramına temelden yaklaşılmış, iyi algoritmanın ne olduğu tartışılmış ve bir problem üzerinde algoritmayı iyileştirmenin çalışma süresine etkisi görülmüştü. Süreyi belirleyen en önemli parametrelerden biri, temel işlemin kaç kez tekrarlandığıydı.

Ders şu soruyla açıldı: algoritmayı tasarlamakla iş biter mi? Cevap hayırdır. Algoritmanın bir makinede gerçekten çalışabildiğinden emin olmak, yani onu fiziksel hâle getirmek gerekir. Bunun yolu algoritmayı programa dönüştürmektir. Program da aslında bir algoritmadır; algoritmanın bir ifade biçimidir.

Basit bir algoritma kağıt üzerinde izlenebilir (trace): bütün değişkenler adım adım takip edilir. Ancak gerçek problemler bundan çok daha büyüktür ve algoritmayı programa çevirip çalıştırmak zorunlu hâle gelir. Bu noktada şu durum ortaya çıkar: program bir donanım üzerinde çalışacaktır. Bilgisayar katmanlı bir mimari olarak düşünülürse en altta donanım (hardware) katmanı, onun içinde de bizi en çok ilgilendiren CPU vardır. Bir algoritmayı komutlarla ifade etmek, onu CPU'nun anladığı dilde yazmak demektir.

## 2. Programlama Dillerinin Seviyeleri

Hoca bu bölümü tahtaya katmanlı bir şekil çizerek anlattı (ekrandan, 00:20:00): en altta donanım (CPU, düşük seviyeli diller), üstünde orta seviyeli diller, en üstte yüksek seviyeli diller ve en tepede kullanıcı (user).

### 2.1 Makine dili

Algoritmayı doğrudan CPU'ya uygun yazdığımızda buna makine dili (machine language) denir. Makine dili 0 ve 1'lerden oluşur ve doğrudan CPU'ya özeldir. Aynı marka işlemcilerde bile model değiştiğinde makine dili değişebilir, bu da programın yeniden yazılması demektir. Bu duruma makineye bağımlılık (machine dependent) denir ve taşınabilirlik (portability) açısından istenmeyen bir durumdur: bir bilgisayarda yazılan programı başka bir bilgisayara aktarmak gerektiğinde her işlemci için programı yeniden yazmak anlamsızdır.

### 2.2 Assembly dili

Makine dilinin biraz daha anlaşılır hâli assembly dilidir. Assembly, günlük hayattaki ifadeleri kısaltan anımsatıcılardan (mnemonic) oluşur: toplama için `ADD`, veri aktarmak için `MOV`, artırma için `INC` (increment), azaltma için `DEC` (decrement). Ancak assembly komutları makine dilindeki karşılıklarıyla birebir eşleşir; bu yüzden assembly de makineye bağlıdır. Tek kolaylığı, 0 ve 1'lerle kod yazmak yerine daha anlaşılır ifadelerle yazmaktır. Makine dili ve assembly birlikte düşük seviyeli diller (low-level languages) olarak anılır. "Düşük seviye", makineye en yakın olan demektir.

Düşük seviyeli diller hız açısından en hızlı diller sayılabilir, çünkü makinenin anladığı dilde doğrudan konuşulur ve araya tercüman girmez. Hoca bunu bir benzetmeyle anlattı: dilini bilmediğiniz bir yabancıyla tercüman aracılığıyla 20 dakika konuşursanız, sürenin yarısı çeviriye gider ve aslında 10 dakika konuşmuş olursunuz.

### 2.3 Orta seviyeli diller ve C

Makineye bağımlılıktan kurtulmak için yeni bir katman eklenir: orta seviyeli diller (mid-level languages). Orta seviyeli diller hızlı bir şekilde makinenin anlayacağı dile çevrilebilir. C bu grubun tipik örneğidir: az bir işlemle ve az optimizasyonla önce assembly diline, sonra makine diline çevrilebilir. C'de genellikle sistem programları, işletim sistemleri ve gömülü sistem (embedded system) programları yazılır (ekrandan, 00:20:00). Bütün ayrıntılarıyla ve güvenlik gereksinimleriyle tamamen kendi kontrolünüzde olmasını istediğiniz bir program yazacaksanız C uygun bir seçimdir.

C'de yazılan `print`, `for`, `if`, `while` gibi yapılar hemen her dilde bulunur ve yazımı makine diline göre çok daha esnektir. Bu kod dönüşümle makine diline çevrildiği için C makineden bağımsızdır (machine independent).

C'nin bir dezavantajı küçük bir dil olmasıdır: kelime sayısı, yani ifade edilebilen kavram sayısı azdır. Az kelimeyle çok şey anlatılmaya çalışıldığı için programlar uzayabilir. Örneğin ekrana "Hello World" yazdırmak C'de beş altı satır sürerken Python'da tek satırdır. Bir web programı ya da mobil uygulama C'de, gerekli kütüphaneler varsa yazılabilir ama iş uzar.

### 2.4 Yüksek seviyeli diller

En tepede bir kullanıcı vardır ve kullanıcı PowerPoint ya da Zoom gibi programları çalıştırmak ister. Bu tür uygulamaları C'de yazmak zordur; bunlar için yüksek seviyeli diller (high-level languages) kullanılır: Java, C#, Python, Rust ve web uygulamalarında çok karşılaşılan JavaScript (ekrandan, 00:20:00). Hoca, Rust'ın artık C'ye alternatif olarak gösterildiğini ve orta seviyeli dil olarak da düşünülebileceğini ekledi. Günümüzde ChatGPT gibi araçlara "şunu yapan bir program yaz" demek, kullanıcı bakış açısından program üretmenin bir örneğidir.

Kullanıcıya ne kadar yaklaşılırsa araya o kadar çok tercüman, dönüşüm ve ek işlem girer. Bu da bir ek yük (overhead), yani gereksiz bekleme anlamına gelebilir. Hangi seviyede yazılırsa yazılsın, en sonunda kodun çalışacağı bir donanım ve CPU vardır; yukarıdan aşağıya bir çeviri (translation) yapılması gerekir.

## 3. Çeviri, Biçimsel Diller ve Derleme Zincirine İlk Bakış

### 3.1 Biçimsel ve doğal diller

Bir programlama dilini tasarlamak ile o dilde yazılmış bir programı makine diline çevirmek ayrı işlerdir. Bu derste dil tasarlanmaz; var olan bir dilde program yazılır ve makine diline çevrilir. Hoca, merak edenlerin bir yapay zeka aracına "bana bir programlama dili yazabilir misin" diye sorup sonuçları incelemesini önerdi.

Var olan her dilin bir alfabesi ve grameri vardır; çeviri bu alfabe ve gramere uygun yapılmalıdır. C, assembly ve makine dili dahil bütün programlama dilleri biçimsel (formal) dillerdir (ekrandan, 00:20:00). Günlük konuşma dilleri de alfabe ve gramere sahiptir ama onlara doğal diller (natural languages) denir. Doğal dil işleme (natural language processing) bu dillerle ilgilenir: bir cümlenin öğelerini ayırmak ya da bir paragrafın konusunu tahmin etmek gibi. Bu derste biçimsel diller üzerinde çalışılır; ayrıntılar hesaplama kuramı dersinin konusudur.

### 3.2 Derleme zincirinin genel şekli

Hoca tahtaya bir zincir çizdi (ekrandan, 00:25:00). Zincirin başında günlük konuşma diline çok yakın, ama biçimsel bir dilde, C'de yazılmış `my.c` adlı bir program vardır. Sonunda ise CPU'nun anlayacağı makine kodu, yani `.exe` ya da `.out` uzantılı çalıştırılabilir (runnable) bir dosya olmalıdır.

```text
my.c  ->  ön işleme  ->  derleme (compiler)  ->  bağlama (linker)  ->  my.exe / my.out  ->  makine dili
```

- Ön işleme (preprocessing): kodun içindeki `define` işlemleri, makrolar ve yerine koyma (substitution) işlemleri yapılır.
- Derleme (compile): bir ara kod, nesne kodu (object code) üretilir. Koddaki bazı satırlar doğrudan makine koduna çevrilmelidir. Örneğin `a = 5` satırının derleme aşamasındaki karşılığı `MOV AX,5` gibi bir komuttur. Ama `printf` gibi satırların çevrilmiş hâli zaten bir yerlerde hazırdır; her seferinde yeniden derlenmeleri zaman kaybıdır. `stdio` dosyası eklenirken aslında bu hazır kod kullanılır. Bu yüzden derleme sonrasında `printf` olduğu gibi kalır.
- Bağlama (linking): derlenmiş kendi kodumuz ile başka yerlerde önceden derlenmiş kütüphane kodları birleştirilir. Bu işi bağlayıcı (linker) adlı bir program yapar; derleme işini de derleyici (compiler) adlı bir program yapar.

Bağlamadan sonra program çalıştırılabilir hâle gelir. Üstüne çift tıklandığında artık işletim sistemine devredilir. Bu taşınabilirlik sayesinde geliştirici programını dağıtabilir (deployment): yazılan programı hedef makineye, örneğin bir müşterinin bilgisayarına taşıyıp orada çalıştırılabilir hâle getirmek.

Algoritmadan programa geçerken bilinmesi gereken, bu çeviri sürecidir; özellikle de C'nin alfabesi ve grameri. Hoca burada yaygın bir yanılgıya dikkat çekti: "algoritmayı geliştirirsen programı yazmak kolaydır" sözü her zaman doğru değildir. C'de gramer tarafında belki algoritmadan bile fazla ayrıntı vardır. Akış diyagramında ok, kare ve altıgen sembolleri bilmek yeterliyken programlama dilinde alfabe ve gramer çok daha kalabalıktır.

## 4. C Diline Giriş: Tarihçe, Avantajlar ve Tehlikeler

Bu bölümden itibaren hoca hazır slaytlar üzerinden ilerledi. Slaytlarda C için önerilen kaynak kitaplar ve çevrimiçi kurslar yer alıyordu. Hoca, dilin gramerini ve kurallarını öğrenmenin ezberle değil kod yazarak olacağını vurguladı: bir `for` döngüsünün nasıl yazıldığını deftere yazıp tekrar etmeye gerek yoktur, kod yazdıkça öğrenilir. Slaytlardaki akış diyagramı örnekleri bu derste anlatılmadı.

### 4.1 Dillerin hiyerarşik sınıflandırması

Slaytta programlama dillerinin hiyerarşisi tekrar edildi: makine dili, günlük dile biraz daha yakın olan assembly (bu ikisi makineye bağlı), makineden bağımsız yüksek seviyeli diller ve en üstte günlük konuşmaya en yakın doğal diller. Bütün bu dillerin konuşma diline bir benzerliği vardır, çünkü program yazarken bilgisayara "şunu yap, bunu yap" diye emirler verilir.

### 4.2 Derleyici ve yorumlayıcı

Derleyici ve bağlayıcının yanında bir de yorumlayıcı (interpreter) kavramı vardır. C'den sonraki dillerin bir kısmı (Java, Python, Matlab gibi) derlenmek yerine yorumlanarak çalıştırılabilir. Programın tamamını inceleyip çalıştırılabilir kod üretmek bir yöntemdir; programı tamamen değil de satır satır, parça parça çalıştırılabilir koda çevirme stratejisine yorumlama denir.

### 4.3 Yüksek seviyeli dillerin avantaj ve dezavantajları

Avantajları şunlardır:

- Taşınabilirdir (portable).
- Okunup anlaşılması kolaydır. Makine dilindeki 0 ve 1'lerin neye karşılık geldiğini anlamak için işlemcinin kullanım kılavuzuna (datasheet) bakıp kodu çözmek gerekir; bu zordur.
- Okuması ve anlaması kolay olan kodun bakımı ve sürdürülmesi de kolaydır; değişiklik yapmak ve hata düzeltmek rahattır.

Dezavantajları şunlardır:

- Verimlilik (efficiency) açısından sıkıntılıdır.
- Makineye bağlı değildir ama derleyiciye bağlıdır; uygun derleyicinin bulunması ve çeviri yapılması gerekir.

Slaytta bu durum bir şemayla gösterildi (ekrandan, 00:30:00): tek bir kaynak kod (Source Code), Compiler A, Compiler B ve Compiler C ile derlenir ve sırasıyla A, B ve C bilgisayarları için ayrı makine dili programları (ML program for computer A/B/C) üretilir. Aynı kaynak kodun farklı derleyicilerle farklı makinelere özgü programlara dönüşmesi, yüksek seviyeli dillerde bir dezavantaj olarak görülebilir.

Hoca bununla birlikte şunu ekledi: günümüz uygulamalarında gömülü sistem ve sistem programlarının oranı küçüktür. Mobil, web, masaüstü ve IoT uygulamalarında hazır çatılar ve kütüphaneler sayesinde yüksek seviyeli dillerle çok hızlı geliştirme yapılabilir; algoritma bilmeyen biri bile bir programı hızla ayağa kaldırabilir.

### 4.4 C'nin tarihçesi ve kullanım alanları

C, 1972 yıllarında Bell Laboratuvarları'nda geliştirilmiştir ve geliştiricisinin kendi kitabı da vardır. 1972'den bu yana farklı sürümleri çıkmıştır; eğitimde genellikle 1989 ve 1999 standartları kullanılır. 1989 standardına ANSI C ya da standart C denir. Bu standarda uygun program yazmayı öğrenen biri için diğer sürümler kolay gelir.

C işletim sistemlerinde, mikrodenetleyicilerde, gömülü sistemlerde ve DSP işlemcilerinde kullanılır. Bunların ortak noktası performansın önemli olması ve donanıma yakın çalışmasıdır. Örneğin ses üzerine çalışan bir denetleyici yazılacaksa donanıma hemen dönüşebilen bir koda ihtiyaç vardır.

### 4.5 C'nin özellikleri

- Az kelimesi vardır; grameri ve alfabesi görece basittir.
- Kullanıcı kendi veri tiplerini oluşturabilir. Şu ana kadar bilinen tamsayı, kayan noktalı sayı ve karakter gibi birkaç temel tipten bileşik tipler türetilebilir; örneğin sayısal analizde bir polinomu modellemek için.
- İşaretçiler (pointer) yoluyla belleğe hükmedilebilir; diziler işaretçilerle verimli kullanılabilir.
- Dışarıda geliştirilmiş kütüphaneler programa kolayca eklenebilir.
- Kolayca derlenebilir ve makro desteği vardır.

### 4.6 C'nin tehlikeli yanları

Hoca C'yi bıçağa benzetti: bıçak faydalıdır, ama yerine göre doğru kullanılırsa. C güçlü bir dildir ama:

- **Dizi sınır denetimi (range checking) yapmaz.** Beş elemanlı bir `A[5]` dizisinin altıncı elemanına bazı diller erişime izin vermez; C bu denetimi yapmaz, programcıya bırakır.
- **Çalışma zamanında tip denetimi (type checking) yapmaz.** Örneğin `int a;` tanımlayıp `scanf("%d", &a);` ile okuma yapıldığında, diğer dillerde girilen veri önceden denetlenir ve gerekirse kırpılır. C'de kullanıcı sayı yerine harf girerse değer doğrudan atanmaya çalışılır, atama yapılamayınca program hata verebilir ve çökebilir (crash). Derleme ve bağlama aşamalarında hiçbir sorun yokken program çalışırken, belki müşterinin elinde patlayabilir; bu da itibar kaybına yol açar.

> **Hocanın vurgusu:** C'de her şeyi kendiniz yazmanız ve bütün ayrıntılara kendiniz hakim olmanız gerekir. Bu dilin güçlü tarafı da budur. Bir bilgisayar mühendisini diğer programcılardan ayıran şey, özellikle bilgisayar belleğine dair konulara hakim olmasıdır; bunu C'de öğrenmek en önemli taraflardan biridir.

## 5. Yazılım Üretiminin Aşamaları ve Köprü Benzetmesi

Slaytta yazılım üretiminin aşamaları şöyle sıralandı (ekrandan, 00:35:00):

- Product Specification (ürün tanımı): problemin ne olduğunu anlamak.
- Architectural Design (mimari tasarım): hangi değişkenlerin ve veri yapılarının kullanılacağına, kullanıcıdan hangi girdilerin alınacağına ve hangi çıktıların üretileceğine karar vermek. Örneğin problem metninden üç girdi ve iki çıktı olduğu çıkarılır.
- Project Planning (proje planlama).
- Detailed Design (ayrıntılı tasarım): örneğin algoritmanın akış diyagramını çizmek.
- Coding (kodlama).
- Debugging (hata ayıklama): kodu uç değerlerle denemek, doğru sonuç verip vermediğine bakmak ve bulunan hataları gidermek.
- Testing (test): programı bütünüyle sınamak.
- Maintenance (bakım).

Hoca bu aşamaların her birinin günümüzde ayrı bir ders olduğunu söyledi: kodlama programlama derslerinde, ayrıntılı tasarım yazılım mühendisliğinde anlatılır.

### 5.1 Köprü benzetmesi

Büyük bir köprü yapımında her şey baştan çok düzgün planlanır. Önce arazinin yer şekilleri incelenir, sonra köprü ayaklarının olacağı yerlere temel atılır, kuleler dikilir, kuleler arasında "kedi yolu" denen bağlantı yolları kurulur, ardından tabliye denen parçalar iki uçtan başlanarak birleştirilir. Temeli sağlam olmayan bir yapının acı sonuçları görülmüştür. Yazılımda da proje büyüdükçe tasarım ve planlama aşaması önem kazanır: program kim için, ne için, nasıl ve nerede çalışacak gibi sorularla bir bilgi birikimi oluşturulmalıdır.

Hoca, geçmişte bir kazanın sebebinin bir değişken dönüşümü hatası olduğunun programlama kitaplarına girdiğini anlattı. En ufak bir ayrıntı atlandığında çok kötü sonuçlar doğabilir; hatalar ne kadar erken, tercihen program kullanıma alınmadan keşfedilirse o kadar iyidir. Önceden hazırlanmış parçaların kullanımı da geliştirme süresini kısaltabilir.

> **Ders sonrası not:** Hoca bu örneği bir uçak kazası olarak andı. Ders kitaplarında en çok anılan değişken dönüşümü kazası büyük olasılıkla 1996'daki Ariane 5 roketidir: 64 bitlik kayan noktalı bir değerin 16 bitlik tam sayıya dönüştürülmesi taşmaya ve roketin kaybına yol açmıştır.

Köprü ile yazılımın farkı şudur: köprü bittikten sonra değiştirilemez. "İki şerit ekleyelim" ya da "üstünden tren de geçsin" denemez; köprünün amacı bellidir ve başka bir ihtiyaç doğmaz. Yazılım ise günlük ihtiyaçları kolaylaştıran bir üründür ve ihtiyaçlar değişir. Örneğin bir banka uygulamasına ileride yeni bir modül eklenmesi gerekebilir. Bu yüzden yazılım **değişim için tasarlanmalıdır**: ileride eklenebilecekler düşünülerek açık uçlar bırakılmalı, parçalar yeniden kullanılabilir olmalı ve sürekli değişim olduğu için yazılım test edilebilir olmalıdır.

## 6. Derleme Süreci, IDE ve Dev-C++

### 6.1 Derleme süreci şeması

Slaytta C'nin derleme süreci şu şekilde gösterildi (ekrandan, 00:40:00):

```text
source file   source file   source file   source file
   compile       compile       compile       compile
object file   object file   object file   object file
       \           |            |           /
                     Link  <---  Runtime Library
                       |
              çalıştırılabilir dosya
```

Tek bir kaynak dosya olabileceği gibi birden fazla kaynak dosya da olabilir. Her biri derleyiciyle nesne koduna dönüştürülür. Nesne kodları birbirine ve `printf` gibi fonksiyonları içeren çalışma zamanı kütüphanelerine (runtime library) bağlanır; sonunda çalıştırılabilir kod üretilir.

### 6.2 IDE

Bu işleri yapan bir yazılıma, "program yapan programa" ihtiyaç vardır. Bunlara IDE (Integrated Development Environment, tümleşik geliştirme ortamı) denir. Kaynak kod not defterinde de yazılabilir; bir IDE'nin farkı şu görevleri üstlenmesidir:

- Dilin anahtar kelimelerini farklı renklerde göstermek, hataları bildirmek, öneri sunmak, kodu otomatik tamamlamak.
- Kodu derlemek.
- Gerekirse kodu bağlamak ve çalıştırmak.
- Hata bulunursa hatanın yerini söylemek ve düzeltme önerisi sunmak.

"Tümleşik" (integrated) sözcüğü, bütün bu adımları programcı adına tek bir yazılımın yapmasını anlatır. Derste Dev-C++ ya da Code::Blocks, Mac kullananlar için Xcode önerildi; bunlar gcc derleyicisini barındırır. Hoca, bu derste çok gelişmiş, her şeyi otomatik yapan ortamların değil, temelden ve ayrıntılara hakim olarak çalışılmasını istedi. Mac'te doğrudan gcc kullanılabilir; Linux'ta da gcc vardır. Vim gibi her şeyi kendinizin yapmanız gereken editörler de el alışkanlığı için önerilebilir.

### 6.3 Linux'ta derleme

Slaytta Linux'ta derleme gösterildi: kaynak dosyanın `.c` uzantısı vardır; gcc derleyicisi bu metni alır ve derlenmiş kod üretir. Örneğin `bubblesort.c` dosyası `gcc bubblesort.c -o bubblesort` komutuyla derlenir ve oluşan dosya çalıştırıldığında programın çıktısı görülür.

### 6.4 Dev-C++ ile ilk program

Windows'ta derleme Linux'taki kadar kolay değildir, ek ayarlar gerekir. Dev-C++ kurulduktan sonra `File > New > Source File` ile yeni bir kaynak dosya açılır; şimdilik proje oluşturmaya gerek yoktur. Hoca şu kodu yazdı (ekrandan, 00:50:00):

```c
#include <stdio.h>

int main(){
    int a=5;
    printf("a = %d",a);

    return 0;
}
```

Kodun mantığı şöyledir: `#include` ile bir kütüphane eklenir; her C programı `main` ile başlar ve onun bloğuyla biter; bir değişken tanımlanır, değeri ekrana yazdırılır ve `return 0` ile çıkılır. Program kapandığında 0 değeri görülüyorsa program kazasız belasız tamamlanmış demektir; 0'dan farklı bir değer arada bir hata olduğunu gösterir. Buraya `return 5` de yazılabilir, ama 0 döndürmek bir gelenek hâline gelmiştir. Kod `gcc -Wall` ile derlenip çalıştırıldı; çıktı `a = 5`, çıkış kodu 0.

`Compile` komutu verildiğinde Dev-C++ önce dosyanın kaydedilmesini ister. Hoca masaüstünde `Kodlar` adlı bir klasör açıp dosyayı `Kod1.c` olarak kaydetti.

> **Hocanın vurgusu:** Dosya tipi C olarak kaydedilmelidir, C++ olarak kaydetmeyin. C++ olarak kaydedilirse derleyici C++ standardına göre çalışır. Bu derste dosyalar C olarak kaydedilir.

Derleme günlüğünde tek dosya derlendiği, derleyicinin gcc olduğu ve sürüm bilgisi görülür. Dev-C++, gcc programını tam yoluyla çağırır; çünkü gcc kendi klasöründedir ve kaynak kodun yolu da verilmelidir. Komutta `-o` ile oluşacak `.exe` dosyasının adı verilir; geri kalan bayraklar bazı iyileştirmelerdir. Sonuçta derleme hatasız ve uyarısız tamamlandı (ekrandan, 00:50:00): `Errors: 0`, `Warnings: 0`, `Output Size: 144,9599609375 KiB`, `Compilation Time: 0,44s`.

### 6.5 Neden bu kadar büyük?

Kaynak dosya `Kod1.c` yaklaşık 1 KB iken derlenmiş program yaklaşık 145 KB çıktı. Hoca aradaki yaklaşık 144 KB'lık farkın nereden geldiğini sordu. Bir öğrencinin cevabı doğruydu: kullanılan kütüphanelerden gelir. `#include` ile `stdio.h` (Standard Input Output; "stüdyo" diye okunmamalıdır) başlık dosyası programa dahil edilir.

Derlenen `.exe` dosyasına çift tıklandığında program açılıp hemen kapanır ve sonuç görülemez. Bunun yerine Dev-C++'ta `Compile & Run` kullanılırsa konsolda `a = 5` yazdığı ve programın 0 ile tamamlandığı görülür.

## 7. Komut Satırından gcc ve Ara Dosyalar

### 7.1 Path ayarı

Hoca, IDE'nin arka planda yaptığı işi elle yapmak istedi. Komut istemi (cmd) açılıp `cd desktop` ve `cd kodlar` ile kaynak klasöre gidildi; `dir` ile klasördeki dosyalar listelendi. Önceki `.exe` silindi.

Komut istemine yalnız `gcc` yazıldığında, gcc bulunduğumuz klasörde olmadığı için komutun tanınmadığı mesajı gelir. Her seferinde uzun yolu yazmamak için, yazılan komutların arandığı bir "havuz" tanımlanır: ortam değişkenlerindeki `Path`. Yol şöyledir: Bilgisayar özellikleri > Gelişmiş sistem ayarları > Ortam değişkenleri (Environment Variables) > `Path` > Düzenle > Yeni. Bulunulan klasörde olmayan bir program, `Path` listesindeki klasörlerde aranır; liste noktalı virgülle ayrılmış klasörlerden oluşur.

gcc'nin yeri Dev-C++ kurulduysa genellikle Program Files altındaki Dev-C++ klasöründe, `MinGW64` klasörünün içindeki `bin` alt klasörüdür. Bu yol kopyalanıp `Path`'e eklenir. Yalnız o kullanıcı için ya da bütün kullanıcılar için (sistem değişkenleri) eklenebilir; derste bunun önemli olmadığı söylendi. Komut istemi yeniden açılmazsa değişiklik görülmez.

Komut istemi yeniden açılıp `gcc` yazıldığında bu kez `gcc: fatal error: no input files` ve `compilation terminated.` mesajları geldi (ekrandan, 00:55:00). Bu, gcc'nin artık bulunduğunu ama yanlış kullanıldığını (girdi dosyası verilmediğini) gösterir. Ardından `gcc Kod1.c -o BenimProgramim` komutu çalıştırıldı ve klasörde yaklaşık 125 KB'lık `BenimProgramim.exe` oluştu (ekrandan, 01:00:00).

### 7.2 Ara dosyaları saklamak: -save-temps

Ön işleme, derleme ve bağlama sırasında oluşan ara dosyalar normalde derleyici tarafından silinir. Bunları görmek için komuta `-save-temps` (geçici dosyaları sakla) bayrağı eklenir. Hoca burada gcc'nin de parametre alan bir program olduğunu, `main(int argc, char *argv[])` gibi yazılan parametrelerin bununla ilgili olduğunu belirtti.

`gcc Kod1.c -save-temps -o BenimProgramim` çalıştırıldığında klasörde `.i`, `.o`, `.s` uzantılı dosyalar ve `.exe` görüldü. Hoca komutu tahtaya şöyle açıkladı (ekrandan, 01:10:00):

```text
gcc  myprogram.c  -save-temps  -o  mycompiledprogram
 |        |            |        |          |
 |        |            |        |          +-- derlenmiş program dosyasının yeni adı
 |        |            |        +-- derleme için bayrak (çıktı adı)
 |        |            +-- geçici dosyalar için bayrak
 |        +-- kaynak kod
 +-- derleyici program
```

`-o` ile ad verilmezse derleyici varsayılan bir ad kullanır.

### 7.3 Ön işleme (preprocessing)

Ön işleme, kaynak koddaki yerine koyma (substitution) işlemleri içindir: `#include`, `#define` ve makrolar (ekrandan, 01:20:00). Program derlenmeden önce `#include <stdio.h>` satırının yerine o dosyanın içeriği yapıştırılır. Bu yüzden ön işlenmiş dosyada daha fazla satır görülür.

Hoca öğrencilere sordu: girdi `myprogram.c` ise çıktının uzantısı `i`, `o`, `s` seçeneklerinden hangisidir? Bir öğrenci doğru cevabı verdi: `myprogram.i`.

`.i` dosyası açıldığında başta zaman, `pack`, `vsscanf`, `snprintf` gibi daha önce görülmemiş birçok tanım görüldü. Bunlar `printf` ve `scanf`'in daha genel hâlleridir ve `stdio.h` içinde yazılı kodlardır. Hoca, `int main` satırına gelene kadar yaklaşık 690 satırın yerine koyma işlemiyle geldiğini gösterdi.

Ardından koda `#define MAX 100` eklendi ve `a`'ya 5 yerine `MAX` atandı. Bunun anlamı "nerede `MAX` görürsen 100 yaz"dır; derlemeye geçmeden önce her `MAX`'in yerine 100 yapıştırılır. Ayrıca koda yorum satırları eklendi. Yorumlar kodun kendisiyle ilgili değildir ve makine koduna çevrilmez, bu yüzden ön işlemede silinmeleri gerekir.

Yeniden derlendiğinde `.i` dosyasının sonu şöyleydi (ekrandan, 01:15:00):

```text
# 2 "Kod1.c" 2

int main(){
 int a=100;
 printf("a = %d",a);



 return 0;
}
```

`#define` satırı kaybolmuş, `MAX` yerine 100 yazılmış ve yorumlar silinmişti; dosya 702 satıra ulaşmıştı. Bu hâlde hâlâ makine koduna benzeyen bir şey yoktur: `printf`, `int` ve `a=100` yerinde durur. Bu davranış gcc ile ayrıca denendi; ön işlenmiş dosyada `int a=100;` satırı görüldü.

### 7.4 Derleme (compilation)

İkinci adım derlemedir: kaynak kodun assembly koduna dönüştürülmesi (conversion from source code into assembly code). Girdi `myprogram.i`, çıktı `myprogram.s`'dir (ekrandan, 01:20:00). Ana programdaki atama gibi satırlar derlenebilir, ama `printf` daha önce bir yerlerde derlendiği için derlenmez; assembly karşılıklarında `printf` olduğu gibi kalır.

`.s` dosyası açıldığında bir assembly dosyasına benzediği görüldü: `main` fonksiyonunu gösteren bir etiket, 100 değerini bir yere aktaran bir komut (atama) ve bilinmeyen başka işlemler vardı. `printf` hâlâ çözülmemişti; dosya, `printf`'in başka bir yerden geleceğini belirtiyordu. Derste aynı kod gcc ile ayrıca derlendiğinde `.s` dosyasında `movl $100, ...` ve `call printf` satırları görüldü.

### 7.5 Çeviri: assembly'den makine koduna

Üçüncü adım, assembly kodunun makine koduna dönüştürülmesidir (conversion from assembly into machine code). Girdi `myprogram.s`, çıktı `myprogram.o`'dur. Ortaya kodlanmış (encoded) bir dosya çıkar (ekrandan, 01:20:00). Makine kodu 0 ve 1'lerden oluşur, ama dosyada 0101 diye değil kodlanmış biçimde saklanır; insanın anlaması beklenmez. Burada da `printf` hâlâ çözülmeden durur, çünkü henüz bağlanmamıştır.

### 7.6 Bağlama (linking)

Son adım bağlamadır: diğer `.o` dosyalarını birleştirerek çalıştırılabilir dosya üretmek (combining other `.o` files into executable files). Bir `.o` bizim programımıza aittir; `printf`'in `.o`'su ve başka `.o`'lar da gelir. Sonunda `mycompiledprogram.exe` çıkar ve çalıştırılır (run executable file), çıktı elde edilir (ekrandan, 01:55:00).

Dosya boyutları bu süreci yansıtır: yaklaşık 1 KB'lık kaynaktan yaklaşık 41 KB'lık `.i` oluştu; `.i`'den `.s`, `.s`'den `.o` üretildi; `printf` de getirilip bağlandığında dosya yaklaşık 125 KB oldu. `printf`'in arka planda birçok kodu vardır; ekrana bir şey yazdırmak için ekran kartının harekete geçmesi ve verilerin yollar üzerinden taşınması gibi birçok işlem gerekir.

Bütün bu adımların öncesinde de iki adım vardır. Hoca bunları tahtaya ekledi (ekrandan, 01:55:00): önce algoritmanın tasarlanması (design an algorithm), sonra programın yazılıp düzenlenmesi (edit your program). Bu adımların her biri de ayrı bir derstir: derleyici yazmak, çeviri ve bağlama programlama dilleri teorisi derslerinde işlenir.

```text
Adım 0: algoritmayı tasarla
Adım 1: programı yaz ve düzenle (myprogram.c)
Adım 2: ön işleme      myprogram.c -> myprogram.i
Adım 3: derleme        myprogram.i -> myprogram.s
Adım 4: çeviri         myprogram.s -> myprogram.o
Adım 5: bağlama        myprogram.o + diğer .o dosyaları -> mycompiledprogram.exe
Adım 6: çalıştırma     -> çıktı
```

## 8. Derleyici Hataları ve Noktalı Virgül Kuralı

### 8.1 Eksik noktalı virgül

Hoca bir soru sordu: `printf` satırının sonundaki noktalı virgül kaldırılıp kaydedilir ve komut satırından gcc ile derlenirse ne olur? Bir öğrenci gcc'nin uyarı vereceğini söyledi. Derlendiğinde gcc, `return`'den önce beklenen bir noktalı virgül olduğunu bildiren bir hata verdi. Dev-C++'ta derlendiğinde de aynı hata görüldü. Daha güncel ortamlar hatanın yerini daha açık işaret eder. Hata düzeltilmeden program oluşmaz; programcı yeniden düzenleme (edit) adımına döner.

### 8.2 Noktalı virgül nereye konabilir?

**Soru:** gcc'nin istediği yere, yani `return` satırının başına noktalı virgül koysam da çalışır mı?
**Cevap:** Evet. Ön işleme yorumları ve boş satırları sildiği için `printf(...)` ifadesi ile `return` arasındaki her şey ortadan kalkar; noktalı virgül `return`'ün önüne konduğunda ifade yine doğru şekilde sonlanır. Ancak arada çalıştırılabilir bir ifade olsaydı (örneğin `a = 8;`), noktalı virgülün ondan önce konması gerekirdi. Yani arada çalıştırılabilir bir şey olmadıkça noktalı virgül istenen yere konabilir.

### 8.3 Noktalı virgül kuralı

Noktalı virgül emir (imperatif) bildiren ifadelerin sonuna konur: "`a`'ya `MAX` değerini ata", "ekrana şunu yaz", "`a`'yı bir artır", "kullanıcıdan bir `a` değeri al" gibi. Bu ifadeler Türkçeye ya da İngilizceye çevrildiğinde emir kipiyle ifade edilir.

Emir bildirmeyen yapılar da vardır. `if (koşul)` "koşul doğruysa" demektir ama doğruysa ne yapılacağını söylemez. `if`'ten hemen sonra noktalı virgül konursa "doğruysa hiçbir şey yapma" anlamına gelir; bu yüzden `if`'ten sonra noktalı virgül konmaz. Aynı şekilde `for (...)` başlığından sonra noktalı virgül konursa boş bir döngü elde edilir; `while` için de aynısı geçerlidir. Bu yapılarda noktalı virgül başlığa değil, altındaki bloktaki ifadelere konur. Tek istisna `do-while` döngüsüdür; onun sonunda noktalı virgül bulunur.

> **Ek bilgi (derste anlatılmadı):** `do { ... } while (kosul);` biçiminde koşul döngünün sonunda yer alır ve ifade noktalı virgülle biter. `if (x > 0); y = 1;` yazıldığında ise `y = 1;` koşuldan bağımsız olarak her zaman çalışır.

### 8.4 Hata mesajı her zaman asıl hatayı göstermez

Daha sonra bir `printf` satırındaki virgül silinip derlendiğinde Dev-C++ bir parantez hatası bildirdi; oysa asıl hata eksik virgüldü. Hoca bu tür hataların derleyici mesajlarını okuyarak ve hataları gidere gidere öğrenileceğini söyledi.

## 9. Tersine Derleme ve Kod Karmaşıklaştırma

**Soru:** Çeviri işlemi tersine çevrilebilir mi; makine kodu assembly ya da kaynak koda geri çevrilebilir mi?
**Cevap:** Bunu yapan programlar vardır ve bunlara tersine derleyici (decompiler) denir. Özellikle Java ve C# gibi yüksek seviyeli diller için yaygındır; C için de büyük olasılıkla vardır. Tersine derleyici makine kodunu alır ve karşılaştıra karşılaştıra özgün program koduna çevirmeye çalışır. Ancak her zaman tam başarılı olmaz: `.o` dosyası sıkıştırılmışsa ya da güvenlik amacıyla kod karmaşıklaştırma (obfuscation) uygulanmışsa sonuç verimsiz olabilir. Bazı derleyiciler kodu derleyip makineye özgü hâle getirir, sıkıştırır ve gerekirse şifreler; program ancak şifre sağlanınca çalışır. Durum dile ve derleyiciye göre değişir.

Hoca kod karmaşıklaştırmayı (code obfuscation) internette arayarak örnekler gösterdi (ekrandan, 01:30:00): özgün kod ile yeniden adlandırma ya da kontrol akışı karmaşıklaştırması uygulanmış kodun yan yana karşılaştırmaları ve tek harfli değişkenlerle sıkıştırılmış, okunaksız C kodları. Bu alanda yarışmalar da düzenlenir; örneğin çalıştırıldığında dünya haritasına benzeyen bir çıktı üreten, okunması neredeyse imkânsız bir program ödül almıştır. Bir öğrenci de çalıştırıldığında dönen bir halka (donut) şekli çizen ünlü bir karmaşık programı hatırlattı. Kod karmaşıklaştırma, özgün kaynak kodun bulunmasını istemeyen geliştiricilerin kullandığı bir yöntemdir ve bilişim güvenliğinin bir alt konusudur.

## 10. Değişkenler, Sabitler ve Veri Tipleri

### 10.1 Bir dili öğrenmek

Bir programlama dilini öğrenmek iki şeyi öğrenmektir: dilin kurallarını, yani gramerini (`for`, `if`, değişken ve sabit tanımlama, toplama, çıkarma, atama) ve dilin veri yapılarını (data structure). Hoca asıl önemli olanın veri yapıları olduğunu söyledi. En bilinen veri yapısı değişkendir; ardından dizi (array), matris ve karakter dizisi (string) gelir (ekrandan, 01:35:00).

### 10.2 Değişken nedir?

Matematikte problem çözerken $x$, $y$, $z$ gibi değişkenlerle denklem kurulur. Programda da verileri saklamak için bilgisayarın belleğindeki alanlar kullanılır; bu veriler değişebilir. Slayttaki örnek şöyledir (ekrandan, 01:25:00 ve 01:35:00):

```text
Statement 1:  j = 5 + 10;
Statement 2:  i = j - 2;
Statement 3:  i = i + 2;

Değişken   Adres   Değer
           2482
j          2486    15
i          2490    13 -> 15
```

Birinci deyimde önce $5 + 10$ hesaplanır, sonra $j$'ye 15 yazılır. İkinci deyimde $j - 2 = 13$ hesaplanıp $i$'ye yazılır. Üçüncü deyimde $i$ iki artırılır ve $13 + 2 = 15$ olur. Değişken adı ($j$) bir etikettir; bu etiketin bellekte fiziksel bir adresi, bir değeri ve bir aralığı (range) vardır. Bir değişkenin kaç bayt yer tutacağı bellidir; tam sayı genellikle 4 bayttır (tabloda adresler de 4'er artar). Noktalı virgülle biten her ifadeye deyim (statement) denir. Değişkenlerin belleğe gelişigüzel yerleşmediği ve belleğin nasıl düzenlendiği sonraki derste kodla gösterilecektir.

### 10.3 İsimlendirme kuralları

İsimlendirme kuralları değişkenler, sabitler ve fonksiyonlar için geçerlidir:

- Ad yalnız harf, rakam ve alt çizgi (`_`) içerebilir. Virgül, noktalı virgül, ünlem işareti, nokta ya da dolar işareti içeremez (bazı dillerde `$` kullanılabilir, C'de kullanılamaz).
- Ad bir harfle ya da alt çizgiyle başlamalıdır; rakamla başlayamaz.
- Ad C'nin ayrılmış kelimelerinden (reserved keyword) biri olamaz; örneğin `int`, `for`, `return` adlı değişken tanımlanamaz. C'de ayrılmış kelime sayısı azdır ve kullandıkça tanınır.
- C büyük-küçük harfe duyarlıdır: küçük harfle ve büyük harfle yazılan aynı ad farklı değişkenlerdir ve bellekte ayrı alanlar ayrılır.

### 10.4 Değişken bildirimi

Değişken ya da sabit tanımlamanın genel biçimi şöyledir:

```c
veri_tipi degisken_adi;
veri_tipi degisken_adi1, degisken_adi2;
```

### 10.5 Veri tipleri

`void` de bir veri tipidir; bu dönem kullanılmayacaktır. Skaler (ilkel, primitive) tipler, ilk derslerde 0 ve 1'lerden türetilerek anlatılan temel tiplerdir: aritmetik tipler (tam sayılar ve kayan noktalı sayılar), işaretçiler ve numaralandırılmış (enumerated) tipler. Derste bunların büyük kısmı görülecektir.

Bileşik (aggregate) tipler ise temel tipler birleştirilerek oluşturulan yeni tiplerdir. Örneğin bir karmaşık sayı iki kayan noktalı sayıdan oluşur. Bir daireyi yalnız yarıçapıyla değil merkeziyle de tanımlamak için merkezin $x$ ve $y$ koordinatları ve yarıçap $r$ gerekir; üç gerçel sayıdan oluşan "daire" adlı yeni bir tip yazılabilir. Bu, sayısal analiz dersinde gerekli olacaktır.

Temel tipler `char`, `int`, `float`, `double` ve `enum`'dur. Bunlardan `float` ve `double` kayan noktalıdır, diğerleri tam sayı tipidir; `char` da bir tam sayı tipidir. Bu tiplerin önüne niteleyiciler (qualifier) konarak boyutları ve aralıkları değiştirilebilir: `long int`, yalnız pozitif değerler için `unsigned int`, pozitif ve negatif değerler için `signed int`.

### 10.6 Boyutlar ve aralıklar

Slayttaki tablo ezberlemek için değil, aşinalık için verildi (ekrandan, 01:40:00):

| Veri tipi | Açıklama | Boyut (bayt) | Alt sınır | Üst sınır |
|---|---|---|---|---|
| char | Tek karakter ya da çok küçük tam sayı | 1 | -128 | 127 |
| unsigned char | Tek karakter ya da çok küçük tam sayı | 1 | 0 | 255 |
| short int | Küçük tam sayı | 2 | -32768 | 32767 |
| unsigned short int | Küçük tam sayı | 2 | 0 | 65536 |
| int | Tam sayı | 4 | -2,147,483,648 | 2,147,483,647 |
| unsigned int | Tam sayı | 4 | 0 | 4,294,967,295 |
| long int | Büyük tam sayı | 8 | $-2^{63}$ | $2^{63}-1$ |
| unsigned long int | Büyük tam sayı | 8 | 0 | $2^{64}-1$ |
| float | Kayan noktalı sayı | 4 | | |
| double | Kayan noktalı sayı | 8 | | |

> **Ders sonrası not:** Tabloda `unsigned short int` üst sınırı 65536 yazıyor; doğrusu $2^{16}-1 = 65535$'tir (python ile doğrulandı).

`char` tek bir karakter tutar; örneğin `'A'` ya da `'1'` karakteri. Boyutu 1 bayttır. Hoca bunu dosya boyutuyla ilişkilendirdi: diskte 1 KB görünen kaynak dosyanın özelliklerine bakıldığında boyutu 149 bayttır; yani dosyada boşluklar dahil 149 karakter vardır, disk üzerinde ise 1 KB'a tamamlanmıştır.

Aralıkların hesabı şöyledir. 1 bayt 8 bittir. Tipin önünde bir şey yazmıyorsa işaretlidir; 8 bitin 1 biti işarete gider ve kalan 7 bitle $2^7 = 128$ durum gösterilir:

$$-2^7 = -128 \quad \text{ile} \quad 2^7 - 1 = 127$$

Pozitif tarafta 0 da sayıldığı için üst sınır bir eksiktir. Bu aralıktaki değerler `char` içinde tam sayı olarak ya da ASCII karakter kodu olarak tutulabilir. `unsigned` yapılırsa işarete bit ayrılmaz ve 8 bitin tamamı kullanılır:

$$0 \quad \text{ile} \quad 2^8 - 1 = 255$$

Aynı mantık diğer tiplere de uygulanır. 4 baytlık işaretli `int` 32 bittir; aralığı $-2^{31}$ ile $2^{31}-1$ arasıdır. İşaretsiz hâli $0$ ile $2^{32}-1$ arasıdır. 8 baytlık (64 bit) `long int` için aralık $-2^{63}$ ile $2^{63}-1$, işaretsiz hâli için $0$ ile $2^{64}-1$'dir. Bu değerler python ile doğrulandı: $2^{31}-1 = 2\,147\,483\,647$, $2^{32}-1 = 4\,294\,967\,295$.

> **Hocanın vurgusu:** Bir problem çözerken değişkenin tipi, alacağı değerlerin aralığına göre seçilmelidir. Girilecek sayılar çok büyükse `long long int` gibi tipler kullanılmalıdır.

### 10.7 sizeof operatörü

Tiplerin boyutu bilgisayardan bilgisayara değişebilir; bunu öğrenmek için `sizeof` kullanılır. Hoca `sizeof`'un fonksiyon değil bir operatör olduğunu vurguladı. Yeni bir kaynak dosyada tiplerin boyutlarını yazdıran bir program çalıştırdı: `char` 1, `short` 2, `int` 4 bayt çıktı; `long` da 4 bayt çıktı; `long long` ile daha büyük değerlere çıkılır.

> **Ders sonrası not:** `long` boyutu platforma bağlıdır. Hocanın Windows'taki denemesinde 4 bayt çıktı; tablodaki 8 bayt ise büyük olasılıkla 64 bit Linux içindir. Aynı tipler 64 bit Linux'ta gcc ile denendiğinde `char` 1, `short` 2, `int` 4, `long` 8 bayt çıktı. Hocanın "`long long` 16 bayta çıkıyor" sözü de doğru değildir; `long long` gcc'de 8 bayttır, 16 bayta çıkan büyük olasılıkla `long double`'dır.

<!-- BELİRSİZ: sizeof programının kaynak kodu ve tam çıktısı hazır karelerde görünmüyor; yalnız altyazıdaki anlatım aktarıldı. -->

Programın sonunda `return` yazılmadığında ekranda programın 22 değeriyle bittiği görüldü. Hoca bunun nedenini şöyle açıkladı: son `printf` 22 karakter basmış ve bu değer dönüş değeri olarak düşmüş. `return 0` eklenince program 0 ile tamamlandı.

> **Ek bilgi (derste anlatılmadı):** `printf` ekrana yazdığı karakter sayısını döndürür. Derste görülen 22 büyük olasılıkla bu dönüş değerinin kalıntısıdır: C89'da `main`'in sonunda `return` yoksa dönüş değeri tanımsızdır; C99'dan itibaren `main` sonunda `return` yoksa 0 döndürülmüş sayılır.

Hoca ayrıca okunabilirlik için blok içindeki satırların bir boşluk girintili yazılmasını önerdi; bu kurallara örneklerle tekrar tekrar dönülecektir.

### 10.8 Bildirim, tanımlama ve camelCase

Değişkenin yalnız tipini ve adını vermek bildirimdir (declaration). Slaytta karakter tipinde değişkenler ve aynı satırda iki değişken bildirimi örnekleri vardı. Değişkene bildirildiği yerde ilk değer verilirse (initialization) bu bir tanımlama (definition) olur. Tek tırnak içindeki değer bir karakterdir; bir değişkene tam sayı, bir başkasına `double` değer atanabilir.

Birden fazla kelimeden oluşan değişken adları camelCase ile yazılır: ilk kelime küçük harfle, sonraki her kelime büyük harfle başlar, örneğin `numberOfStudents`. Değişkenlere anlamlı adlar verilmelidir ki kodu okuyan kişi programı anlamakta güçlük çekmesin.

Slayttaki bir örnekte `unsigned char` tipindeki bir değişkene 25 atanıyordu. Burada örtük bir dönüşüm (implicit conversion) vardır: `char` bir tam sayı tipi olduğu için 25 bu şekilde saklanır, ama karakter olarak yazdırıldığında ASCII tablosunda 25'e karşılık gelen karakter görülür.

### 10.9 Sabitler

Bir şeyin önüne `const` yazılırsa o değer sabitlenir ve sonradan değiştirilemez. Sabit tanımlamanın iki yolu vardır (ekrandan, 01:45:00):

```c
const float PI=3.142857;
const int maxHour=24;
const double force=9.912391;

#define PI   3.142857
#define MAX  100
```

`#define` bir değişken değil, bir ön işlemci yönergesidir. Derlemeden önce adın geçtiği her yere değeri yazılır. Bu yüzden `PI = PI + 3;` yazılamaz; ön işleme sonrasında bu ifade `3.142857 = 3.142857 + 3;` gibi anlamsız bir şeye dönüşür. `const` ile tanımlanan `PI` için de aynı ifade yazılamaz, çünkü değer sabitlenmiştir.

**Soru:** `#define` ile ne büyüklükte değerler tanımlanabilir?
**Cevap:** Büyüklük önemli değildir; `#define` satırının sonuna noktalı virgül de konmaz. Ön işlemci adı gördüğü yere tanımlanan metni yazar; istenirse çok büyük bir sayı yazılabilir. Ancak bu değeri kullanacak değişkenler buna uygun aralıkta olmalıdır. Örneğin çok basamaklı bir pi değeri `float` tipinde bir `x` değişkenine atanırsa `float` bu kadar uzun bir sayıyı saklayamaz; değişken tipleri yukarıdaki tanıma göre planlanmalıdır.

### 10.10 Değişmezler (literal)

Değişkene aktarılan sabit değerlere değişmez (literal) denir. `22` bir tam sayı değişmezidir. Değişmezin sonuna ek konarak tipi belirtilebilir: `22u` işaretsiz, `22L` uzun (`long`) tam sayıdır. Örneğin `long int j = 22L;` ile başlangıç değeri küçük olsa da `long` olarak yer ayrılması sağlanır; bu, değerin ileride büyüyebileceği durumlar için anlamlıdır. Kayan noktalı değişmezler için `double`, `float` ve `long double` biçimleri vardır; `e3` gösterimi $10^3$ ile çarpmayı ifade eder (örneğin `1.5e3` $= 1500$).

Sayılar farklı tabanlarda da yazılabilir. Onaltılık (hexadecimal) bir sayı `0x` önekiyle yazılır: `int x = 0x4;`. Değer onaltılık olarak gösterilebilir ya da ekrana yazdırılırken bu biçim kullanılabilir.

<!-- BELİRSİZ: hocanın sekizlik taban örneği altyazıda net değil ("decimal 4, 8'lik taban da böyleydi"); slayt hazır karelerde görünmüyor. -->

> **Ek bilgi (derste anlatılmadı):** C'de sekizlik (octal) sayılar başa `0` konarak yazılır: `04` sekizlik 4, `010` ise onluk 8'dir. Bu yüzden `010` ile `10` farklı değerlerdir.

Kayan noktalı tipler gerçel sayıları göstermek için kullanılır: `0.1`, `7.0` gibi. `float` IEEE 754'ün 32 bitlik, `double` 64 bitlik biçimine karşılık gelir. Slaytta geçerli (legal) ve geçersiz (illegal) kayan noktalı yazımlar listelendi; hoca geçerli yazımları bilmenin yeterli olduğunu söyledi.

## 11. Giriş-Çıkış: printf ve scanf

### 11.1 printf

`printf` verileri ekrana yazdırmak için kullanılır. İlk argümanı iki tırnak arasında bir karakter dizisidir (biçim dizisi); gerekirse ardından argümanlar gelir. Biçim dizisinin içinde argümanlarla ilişki kurmak için biçim belirleyiciler (format specifier) kullanılır. `%` işaretinden sonra gelen harf neyin yazılacağını söyler; her belirleyici sıradaki argümana bağlanır:

- `%c` bir karakter yazdırır.
- `%d` bir tam sayı yazdırır. `printf("%d %d", a, b)` gibi bir satırda ilk `%d` `a`'ya, ikincisi `b`'ye bağlanır.
- Argüman `a + b` gibi bir ifade ise önce toplama yapılır, sonuç `%d`'ye bağlanır.
- `%f` değeri kayan noktalı biçimde yazdırır.
- `%5d` gibi bir genişlik verilirse beş karakterlik yer açılır ve sayı (örneğin 123) sağa dayalı yazılır.

### 11.2 scanf

`scanf` dışarıdan veri okumak için kullanılır. Ne okunacağı biçim belirleyiciyle söylenir. Hoca bunu "C'de her şeyi kendiniz yapmak zorundasınız" sözünün güzel bir örneği olarak verdi: dışarıdan bir sayı okunacaksa hangi tür verinin okunacağı ve nereye okunacağı yetmez, belleğin hangi adresine okunacağı da söylenmelidir. Tanımlanan her değişkenin bellekte bir adresi vardır; bu adres `&` (ampersand) operatörüyle elde edilir. Slayttaki örnekler (ekrandan, 01:50:00):

```c
scanf("%d",&sayi1);
scanf("%f",&temprature);
scanf("%x",&sayi2);
scanf("%d %d",&x,&y);
scanf("%c",&harf);
char kelime[10];
scanf("%s",kelime);
```

Hoca bu konuları hazırlık amacıyla anlattığını, bunların ezberlenecek şeyler olmadığını ve kod yazdıkça, hata yaptıkça öğrenileceğini söyledi. Slaytta karakter okuma ve yazma için daha kolay fonksiyonlar da vardı; bunlar geçildi.

> **Ek bilgi (derste anlatılmadı):** Son örnekte `kelime` bir dizidir ve dizinin adı zaten ilk elemanının adresini verdiği için `&` kullanılmaz. Slaytta geçilen daha kolay fonksiyonlar büyük olasılıkla `getchar`/`putchar` ya da `gets`/`puts`'tur.

## 12. Karışık Tipli İşlemler ve Tip Dönüşümleri

### 12.1 Örtük dönüşüm

Bir matematiksel işlemde operatörün iki yanındaki değerlere işlenen (operand) denir. İki işlenenin tipleri tutarlı olmalıdır. Tutarlı değilse küçük tipteki işlenen büyük tipe dönüştürülür. Buna arka planda yapılan örtük (implicit) dönüşüm denir. Büyüklük sıralamasında en üstte `double`, sonra `float`, sonra `int` gibi tam sayı tipleri gelir. Bir `int` ile bir `double` işleme girerse sonuç `double` olur.

Hocanın örnekleri şunlardır (sonuçlar C ile derlenip doğrulandı):

- `1/2`: iki işlenen de tam sayıdır, sonuç tam sayı bölmesiyle `0` olur. İşlenenlerden biri `2.0` olsaydı (`1/2.0`) sonuç `0.5` olurdu.
- `-3/4 + 2.5`: önce bölme yapılır. $-3$ ve $4$ tam sayı olduğu için $-3/4 = 0$ olur (ara adım eklendi: C'de tam sayı bölmesi sıfıra doğru kırpılır). Sonra $0 + 2.5 = 2.5$ bulunur; sonuç kayan noktalıdır.
- `2 + 3.5`: 2 tam sayısı $2.0$'a dönüştürülür, sonuç $5.5$ olur.

Dönüşüm hiyerarşisinde en üstte `long double` vardır. Aşağıdan yukarıya dönüşümde sorun olmaz, ama yukarıdan aşağıya dönüşümde (örneğin `long double`'dan `double`'a) veri kaybı yaşanır.

> **Hocanın vurgusu:** Sayısal analizde "yanlış sonuç görüyoruz" denen durumların çoğu veri tipi dönüşümlerini doğru yapmamaktan kaynaklanır. Örtük dönüşüm tehlikelidir; bir ayrıntı unutulursa sonuç farklı çıkabilir.

### 12.2 Açık dönüşüm (type casting)

Dönüşüm açıkça da yapılabilir. Değişkenin önüne parantez içinde yeni tipi yazılır:

```c
(float)j / k
```

$j = 3$ ve $k = 2$ iken bölmeden önce $j$'nin yeni tipi oluşturulur ve $3.0$ olur. $3.0$ kayan noktalı olduğu için $k$ de kayan noktalıya dönüştürülür ve $3.0 / 2 = 1.5$ bulunur. Tip zorlaması olmasaydı $3/2$ tam sayı bölmesiyle $1$ verirdi.

> **Ders sonrası not:** Hoca açık dönüşüme bir an "unboxing" dedi; C'de bu işlemin adı büyük olasılıkla kastedildiği gibi tip zorlaması (type casting) ya da açık dönüşümdür. "Unboxing" Java ve C# gibi dillerde nesne içindeki ilkel değerin çıkarılmasını anlatan farklı bir kavramdır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:07:46): Algoritmayı tasarlamakla iş biter mi?

> **Çözüm:** Hayır. Algoritmanın makinede çalışabildiğinden emin olmak için onu bir programa dönüştürmek, programı da CPU'nun anlayacağı makine diline çevirmek gerekir.

**Soru 2** (derste sözlü, 00:48:44): Yaklaşık 1 KB'lık `Kod1.c` dosyası derlendiğinde yaklaşık 145 KB'lık bir çalıştırılabilir dosya oluştu. Aradaki fark nereden gelir?

> **Çözüm:** `#include <stdio.h>` ile eklenen ve bağlama aşamasında programa katılan kütüphane kodlarından (örneğin `printf`'in derlenmiş kodundan) gelir.

**Soru 3** (derste sözlü, 01:10:05): `gcc myprogram.c -save-temps -o mycompiledprogram` komutunda ön işleme adımının girdisi `myprogram.c` ise çıktısının uzantısı `i`, `o`, `s` seçeneklerinden hangisidir?

> **Çözüm:** `myprogram.i`. Ardından derleme `.s`, çeviri `.o` üretir; bağlama da çalıştırılabilir dosyayı oluşturur.

**Soru 4** (derste sözlü, 01:21:54): `printf` satırının sonundaki noktalı virgül silinip program gcc ile derlenirse ne olur?

> **Çözüm:** Derleme hatası alınır; gcc, `return`'den önce bir `;` beklendiğini bildirir ve çalıştırılabilir dosya oluşmaz. Ön işleme yorumları ve boş satırları sildiği için, arada çalıştırılabilir bir ifade yoksa noktalı virgül `return` satırının başına konduğunda da kod derlenir.

**Soru 5** (ekrandan, 01:40:00): 1 baytlık işaretli ve işaretsiz `char` ile 4 baytlık işaretli `int` hangi aralıkta değer tutar?

> **Çözüm:** 8 bitin biri işarete gider: işaretli `char` için $-2^7 = -128$ ile $2^7 - 1 = 127$. İşaretsiz `char` için $0$ ile $2^8 - 1 = 255$. 32 bitlik işaretli `int` için $-2^{31} = -2\,147\,483\,648$ ile $2^{31} - 1 = 2\,147\,483\,647$.

**Soru 6** (ekrandan, 01:45:00): `#define PI 3.142857` ya da `const float PI=3.142857;` tanımından sonra `PI = PI + 3;` yazılabilir mi?

> **Çözüm:** Hayır. `#define` durumunda ön işlemci ifadeyi `3.142857 = 3.142857 + 3;` biçimine çevirir ve bir sabite atama yapılamaz. `const` durumunda değer sabitlenmiştir ve değiştirilemez.

**Soru 7** (derste sözlü, 01:51:25): `1/2`, `-3/4 + 2.5`, `2 + 3.5` ve $j = 3$, $k = 2$ için `(float)j/k` ifadelerinin değerleri nedir?

> **Çözüm:** `1/2 = 0` (tam sayı bölmesi), `-3/4 + 2.5 = 0 + 2.5 = 2.5`, `2 + 3.5 = 2.0 + 3.5 = 5.5`, `(float)j/k = 3.0/2 = 1.5`. Değerler C ile derlenip doğrulandı.

## Dersin Toparlaması

Bu derste algoritmadan programa giden yol bütünüyle izlendi. Önce programlama dillerinin seviyeleri ele alındı: makineye bağlı düşük seviyeli diller (makine dili ve assembly), makineden bağımsız ama donanıma yakın orta seviyeli C ve kullanıcıya yakın yüksek seviyeli diller. Ardından C'nin tarihçesi, kullanım alanları, avantajları ve sınır ya da tip denetimi yapmaması gibi tehlikeli yanları tartışıldı. Yazılım üretiminin aşamaları köprü benzetmesiyle anlatıldı ve yazılımın değişim için tasarlanması gerektiği vurgulandı.

Dersin uygulamalı kısmında Dev-C++ ve komut satırındaki gcc ile basit bir C programı derlendi. `-save-temps` bayrağıyla ön işleme (`.i`), derleme (`.s`), çeviri (`.o`) ve bağlama (`.exe`) adımlarının ara dosyaları tek tek incelendi; `#define` yerine koymasının, yorumların silinmesinin ve `printf`'in ancak bağlama aşamasında çözülmesinin nasıl gerçekleştiği görüldü. Son bölümde değişken ve sabit kavramları, isimlendirme kuralları, temel veri tiplerinin boyut ve aralıkları, değişmezler, `printf`/`scanf` ile giriş-çıkış ve örtük ya da açık tip dönüşümleri işlendi. Hoca, sonraki derslerden itibaren bir problem için önce algoritmanın tartışılacağını, ardından kodunun yazılıp çalıştırılacağını ve daha iyi bir algoritma aranacağını söyledi; değişkenlerin bellekte nasıl yerleştiği de bir sonraki derste kod üzerinde gösterilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
