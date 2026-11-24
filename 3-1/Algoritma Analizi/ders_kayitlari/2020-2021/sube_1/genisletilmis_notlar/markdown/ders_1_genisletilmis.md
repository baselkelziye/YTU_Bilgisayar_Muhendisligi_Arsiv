# Ders 1 Genişletilmiş Notu: Derse Giriş, İyi Algoritmanın Özellikleri ve Çalışma Zamanının Ölçülmesi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kaynaklar ve Dönemin Konuları
- 2. Algoritma Analizi Neden Gerekli?
- 3. Algoritma Kavramı
- 4. İyi Bir Algoritma Nasıl Olur?
- 5. Gerçek Bir Kod Üzerinden İnceleme: min-diff
- 6. Çalışma Zamanını Deneysel Olarak Ölçmek
- 7. Çalışma Zamanını Etkileyen Etkenler
- 8. Matematiksel Model: Maliyet ve Sıklık
- 9. Basitleştirme ve Tilde Gösterimi
- 10. Büyüme Dereceleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Kaynaklar ve Dönemin Konuları

Ders slaytları üç kitabın slaytlarından derlenmiştir ve dönem boyunca üçü birlikte kullanılır (ekrandan, 00:05:00):

- Anany Levitin, *Introduction to the Design & Analysis of Algorithms*, 2011.
- R. Sedgewick ve K. Wayne, *Algorithms, Fourth Edition*, 2013. Kitabın slaytlarına `http://algs4.cs.princeton.edu` adresinden erişilebilir.
- Steven Skiena, *The Algorithm Design Manual*, 2010.

Levitin'in kitabı, programlamaya fazla girmeden algoritma analizini temel seviyede ve anlaşılır biçimde anlatır; kütüphanede bulundurmak için önerilen kitap budur. Sedgewick'in kitabı konuları ayrıntılı anlatır, algoritmalarla birlikte veri yapılarını da işler ve örnekleri Java ile verir. Skiena'nın kitabı yedek kaynak olarak kullanılır; içinde algoritmaların gerçek kullanımına dair güzel hikâyeler vardır.

Dönem boyunca görülecek konular slaytta şöyle listelenmiştir (ekrandan, 00:20:00):

- Giriş
- Asimptotik analiz
- Özyinelemesiz ve özyinelemeli algoritmaların analizi
- Böl ve yönet (divide and conquer) algoritmalarının analizi
- Azalt ve yönet (decrease and conquer) algoritmalarının analizi
- Karma (hashing) algoritmaları
- Dinamik programlama
- Çizge algoritmalarının analizi
- Geri izleme (backtracking)
- Dal ve sınır (branch-and-bound) algoritmaları
- Zaman ve yer ödünleşimleri (space and time trade-offs)
- P, NP, NP-tam ve NP-zor problemler

Hoca bu listeyi şöyle açıkladı. Asimptotik analizde bir algoritmanın karmaşıklığının nasıl hesaplanacağı ayrıntılı görülecek. Özyinelemeli algoritmaların analizi yineleme (recurrence) bağıntılarıyla yapılacak. Önceki dönemde başlanan böl ve yönet algoritmalarının bu kez analizi yapılacak, ardından azalt ve yönet algoritmaları gelecek. Karma, veriye en verimli biçimde erişmek için kullanılan arama yöntemlerinden biridir; ne kadar yer ayrılacağı gibi kararlar karmaşıklığı belirlediği için analizi yapılacak.

Dinamik programlama yeni bir tasarım biçimidir. Özyinelemeli tasarım gibi bir yineleme bağıntısı kurar, ama özyinelemede daha önce hesaplanan değerler tekrar tekrar hesaplanırken dinamik programlamada bu değerler saklanıp sonra kullanılır. Böylece genellikle $2^n$ karmaşıklıkta olan çözümler çok daha hızlı hâle getirilebilir. Önceki dönemde görülen derinlik öncelikli arama (DFS) ve genişlik öncelikli arama (BFS) gibi çizge algoritmaları bu kez kullanım alanlarına ve problemlere odaklanarak işlenecek.

Geri izleme, sonuç başarısız oldukça geriye dönerek arama yapan yaklaşımdır. Labirentte yol bulma buna iyi bir benzetmedir: yol çıkmaza girerse bir adım geri gidip yeni bir yol denersiniz. Satranç tahtasına vezirleri yerleştirme problemi de bu türdendir. Dönemin sonunda polinom ve deterministik olmayan polinom (NP) kavramları ele alınacak. Karmaşıklığı $n^2$, $n^3$ gibi olan problemler polinomdur ve makul sürede çözülür. Karmaşıklığı $2^n$ olan bir problem polinom değildir ve makul sürede çözülemeyen gruba girer; bu tür problemler için doğrulamaya dayalı yaklaşımlar görülecek.

## 2. Algoritma Analizi Neden Gerekli?

Birinci sınıfta bir problemin bilgisayarda algoritma tasarlanarak nasıl çözüleceği, bir dizinin en büyüğünü bulmak gibi temel problemlerle öğrenildi. Sonraki programlama dersleri bu bilgiyi pekiştirdi. Veri yapıları ve algoritmalar dersinde ise şu fikir öne çıktı: bazı problemlerin verimli çözümü, algoritmanın yanında uygun bir veri yapısının kullanılmasını gerektirir.

Hoca bunu bir harita uygulamasıyla örnekledi. Bir semtten başka bir semte nasıl gidileceği sorulduğunda sistemin şehirdeki bütün olası ara noktaları bilmesi, bu noktalar arasındaki bağlantıları, mesafeleri ve gerçek zamanlı olarak bu mesafelerin ne kadar süreceğini tutması gerekir. Her şeyi sıfırdan matrislerle kurmak yerine, yerleri çizgenin düğümleri, aralarındaki mesafe ve süreyi kenarlar olarak tutan hazır bir çizge yapısı kullanılır. Sonra uygun çizge algoritmalarıyla en kısa yol ya da her yolun ne kadar süreceği bulunur.

Buradan iki tarafı olan bir tablo çıkar: bir yanda belirli problemleri çözmeye uygun verimli veri yapıları, öbür yanda bu yapılar için geliştirilmiş, çok ihtiyaç duyulan problemleri (en kısa yol, bir noktadan diğerine ulaşılabilirlik gibi) çözen algoritmalar.

**Soru:** Bir web sayfasından başka bir sayfaya, oradan başka bir sayfaya geçip sonra sırayla geri dönmek istiyoruz. Bunun için hangi veri yapısı uygundur? **Cevap:** Yığın (stack). Her yeni adrese geçildiğinde önceki adres yığına konur. Geri dönmek istendiğinde yığının tepesinde en son gelinen yer bulunur (derste sözlü, 00:23:11).

Önceki dönemde arama ve sıralama gibi çok kullanılan algoritmalar ile yığın, kuyruk, ağaç ve çizge gibi veri yapıları görüldü. Bu dönemin amacı, algoritmaların analizine yoğunlaşmaktır. Bir algoritma yazarken iki temel kaynak vardır: zaman ve yer. Hedef, zamanı ve yeri iyi kullanan algoritmalar tasarlamaktır. Bu dönem şu sorulara cevap aranacak: Zamanı ve yeri ne kadar iyi kullandım? Bunu nasıl ölçerim? Daha iyi kullanmasını nasıl sağlarım?

## 3. Algoritma Kavramı

Slayttaki tanım şöyledir (ekrandan, 00:30:00):

> An algorithm is a sequence of unambiguous instructions for solving a problem, for obtaining a required output for any legitimate input in a finite amount of time.

Yani algoritma, bir problemi çözmek için her geçerli girdiden istenen çıktıyı sonlu sürede elde eden, belirsizlik içermeyen komutlar dizisidir. Slayttaki şemada problem algoritmaya, algoritma da "bilgisayar"a gider; bilgisayar girdiyi alıp çıktıyı üretir:

```text
            problem
               |
               v
           algoritma
               |
               v
girdi --> "bilgisayar" --> çıktı
```

Hoca tanımı şu özelliklerle açtı: elimizde giriş bilgileri ve bu girişler için istenen bir çıkış vardır; algoritma bilgisayar ortamında bu girişlerden istenen çıkışa ulaşmamızı sağlayan tasarımdır. Bu tasarım sonlu bir zamanda çalışmalı, temel komutlarla ifade edilmeli ve kararlı olmalıdır: aynı girdi için bazen bir türlü, bazen başka türlü davranmamalıdır.

## 4. İyi Bir Algoritma Nasıl Olur?

Algoritma analizinde akılda tutulan temel sorular slaytta şöyle verilir (ekrandan, 00:35:00):

- Algoritma ne kadar iyi?
  - Doğruluk (correctness)
  - Verimlilik (efficiency): zaman ve yer. "Bir algoritma, çalışma süresi polinom ise verimlidir."
  - Basitlik (simplicity)
  - Genellik (generality)
- Daha iyi bir algoritma var mı?
  - Alt sınırlar (lower bounds)
  - Optimallik (optimality)

### 4.1 Doğruluk

İyi bir algoritma her şeyden önce doğru algoritmadır. Hoca, giriş programlama derslerinde öğrencilerin çok karmaşık algoritmalar yazdığını, "bu böyle yazılmaz" denildiğinde de cevabın hep "ama çalışıyor" olduğunu anlattı. Doğru çalışmak gerçekten ilk hedeftir, ama profesyonel anlamda bir algoritmanın iyi sayılması için bu yeterli değildir.

### 4.2 Verimlilik

Algoritmanın zamanı ve yeri nasıl kullandığı değerlendirilmelidir. Slayttaki tanıma göre verimli algoritma, polinom zamanda çalışan algoritmadır; örneğin $n^2$ ya da $n^3$ karmaşıklıklı bir algoritma bu anlamda verimlidir.

### 4.3 Basitlik

Basitlikten kasıt, iş hayatında bir proje ekibinde yazdığınız algoritmaları kullanan ya da siz ayrıldıktan sonra üzerinde çalışacak kişilerin ne yaptığınızı kolayca anlayabilmesidir. Hoca bunu COBOL örneğiyle anlattı. COBOL çok eski bir dildir; dosyalar üzerinde müşteri kayıtlarıyla çalışmak kolay olduğu için o dönemde bankalar bu dili tercih etmiştir. Bugün hâlâ birçok banka COBOL kullanmaktadır ve bunun başlıca sebebi, o zaman yazılmış programların o kadar karmaşık ve büyük olması ki yeniden yazılmaya cesaret edilememesidir. COBOL kodunu otomatik olarak Java'ya çeviren projeler bile vardır; gerçek zamanlı ve hızlı çalışması gereken bir banka yazılımı için bu iyi bir çözüm değildir. Ders çıkarılacak nokta: kod basit ve anlaşılır yazılmalı, başkaları ona bakıp kolayca yeniden gerçekleyebilmelidir.

### 4.4 Genellik

Sınavda bir algoritma sorulup altına örnek olarak beş elemanlı bir dizi verildiğinde bazı öğrenciler çözümü yalnızca o diziye göre yazar; hatta çözüm yalnız o sayılar için çalışır, başka bir dizi verildiğinde problemi çözemez. Çözüm, problemin olası her senaryosu için doğru cevap vermelidir.

### 4.5 Daha İyi Bir Algoritma Var mı?

Yazdığınız algoritmadan daha iyisinin olup olmadığını anlamak için karmaşıklığını ölçersiniz. Örneğin $n^2$ karmaşıklıklı bir sıralama algoritması yazdıysanız, $n\log n$ karmaşıklıklı sıralama algoritmalarının var olduğunu bildiğiniz için sizinkinden daha iyileri olduğunu söyleyebilirsiniz. Karmaşıklığı ölçmek, algoritmanın optimum olup olmadığını değerlendirmenin yoludur.

> **Ek bilgi (derste anlatılmadı):** Karşılaştırmaya dayalı sıralama algoritmaları için en kötü durumda $\Omega(n\log n)$ karşılaştırmalık bir alt sınır vardır. Bu yüzden mergesort gibi $n\log n$ algoritmalar bu sınıfta asimptotik olarak optimaldir. Slayttaki "alt sınır" ve "optimallik" başlıkları bu tür sonuçları kasteder.

## 5. Gerçek Bir Kod Üzerinden İnceleme: min-diff

Hoca, açık kaynak bir radyo kanal ayarı programından alınmış, gerçekten çalışan ve gömülü bir sistemde (Raspberry Pi) kullanılan bir kod parçası gösterdi ve öğrencilerden kodun ne yaptığını bulmalarını istedi. Programda 64 kanal vardır; her kanalın frekans için bir üst sınırı (`ifcf_lev_over`) ve bir alt sınırı (`ifcf_lev_under`) bulunur. Kod ekranda şöyleydi (ekrandan, 00:40:00 ve 00:45:00):

```c
for (i=0;i!=64;i++){
    ifcf_diff[i]= ifcf_lev_over[i] - ifcf_lev_under[i];
    //printf("diff%d ",ifcf_diff[i]);
}

for(cf_v=0;cf_v!=50;cf_v++){
    if(ifcf_set==1){break;}
    //printf(" cf_v=%u ",cf_v);

    for (i=0;i!=64;i++){
        ifcf_diff2 = ifcf_diff[i];
        ifcf_val3=i;
        if ((ifcf_diff2>=-cf_v)&&(ifcf_diff2<=cf_v)){ifcf_set=1;break;}
    }
}
```

### 5.1 Kod Ne Yapıyor?

İlk döngü her kanal için üst sınır ile alt sınırın farkını `ifcf_diff` dizisine yazar. İkinci kısımda `cf_v` 0'dan başlayıp 49'a kadar artar. Her `cf_v` değeri için 64 kanal baştan taranır ve farkı $-cf\_v \le fark \le cf\_v$ aralığında olan ilk kanal aranır. Böyle bir kanal bulununca `ifcf_set` bayrağı 1 yapılır ve iç döngüden çıkılır; dış döngü de bir sonraki turun başında bayrağı görüp durur. Bu anda `ifcf_val3`, o kanalın indisini tutar.

`cf_v` sıfırdan başlayıp birer birer arttığı için ilk bulunan kanal, mutlak değerce en küçük farka sahip kanaldır. Yani kod, **en küçük frekans farkının bulunduğu kanalı** bulmaktadır. Farkın 0 ile 50 arasında olduğu bilindiği için dış döngü 50'ye kadar kurulmuştur. $-cf\_v$ ve $+cf\_v$ ile iki karşılaştırma yapılmasının sebebi, yazarın mutlak değer almamasıdır: fark $-3$ de olsa $+3$ de olsa büyüklüğün 3 olduğunu bu iki koşulla anlar. `break` ise en küçük fark bulunduğu anda aramayı durdurmak içindir.

> **Ders sonrası not:** Bu yorum not hazırlanırken python ile denetlendi: farkların $[-49, 49]$ aralığında olduğu rastgele 64 elemanlı dizilerde kod, tek döngüde mutlak değerce en küçük farkın ilk indisini bulan yöntemle her denemede aynı indisi verdi. Hiçbir farkın mutlak değeri 49'dan küçük ya da eşit değilse bayrak kurulmaz ve `ifcf_val3` son kanalın indisinde kalır; bu durum derste konuşulmadı.

### 5.2 Kodun Sorunları

Kod çalışıyor ve çok kişinin kullandığı bir projenin parçası. Buna rağmen iki temel sorunu var:

- **Basit ve anlaşılır değil.** Mutlak değer alınsaydı ne yapıldığı hemen anlaşılırdı. İç içe döngüler, bayrak değişkeni ve `break` ile çıkışlar okumayı zorlaştırıyor. `break` kullanmak yerine `while` döngüsüyle çıkmak daha temiz olurdu.
- **Verimli değil.** Bir dizinin en küçük elemanını bulmanın karmaşıklığı dizinin boyutu kadardır: tek bir 64'lük döngüde farkı hesaplayıp o ana kadarki en küçüğü tutmak yeterlidir. Bu kod ise önce 64 adım, sonra en kötü durumda $50\times64$ adım döner. Yazar muhtemelen "en küçük fark 0 ya da 1 ise hemen bulurum" diye düşünerek daha verimli bir şey yaptığını sanmıştır. Oysa en küçük fark örneğin 10 ise kod, sonuca ulaşmadan önce yaklaşık $10\times64=640$ kez boşuna dönmüş olur.

$50\times64$ çok büyük bir sayı değildir, ama kodun gömülü bir sistemde çalıştığı düşünülürse bu gereksiz iş sorun olabilir.

> **Hocanın vurgusu:** Bir algoritmanın problemi çözmesi yetmez. Algoritmalarınızı tasarlarken öncelikle zamanı ve yeri iyi kullanmalarına odaklanmalısınız.

Hoca bu vurgunun son yıllarda neden arttığını da açıkladı. Birkaç yıl öncesine kadar donanım kaynakları bol olduğu için pek çok kişi zaman ve yer verimliliğine odaklanmıyordu. Gömülü sistem uygulamaları yaygınlaştıkça bu değişti; akıllı telefon da sonuçta gömülü bir sistemdir ve üzerindeki uygulamaların hızlı çalışması beklenir.

## 6. Çalışma Zamanını Deneysel Olarak Ölçmek

Bir algoritmanın zamanı nasıl kullandığını ölçmenin ilk yolu, gerçekten süresini ölçmektir. C'de `time.h` başlığındaki `clock()` fonksiyonu algoritmanın çalıştığı bölümün başında (`begin`) ve sonunda (`end`) çağrılır; aradaki fark `CLOCKS_PER_SEC` makrosuna bölünerek geçen süre saniye cinsinden bulunur. `CLOCKS_PER_SEC` yine `time.h` içinde tanımlıdır ve kullanılan donanıma göre değişir. <!-- BELİRSİZ: clock() örneğinin bulunduğu slayt karelerde görünmüyor; kod ayrıntıları altyazıdan aktarıldı. -->

Bu kötü bir yöntem değildir. Çok büyük ve karmaşık programlarda karmaşıklığı hesaplamak zorlaştığında gerçekten bu yapılır: "Şu donanımda bu algoritma şu kadar milisaniyede çalışıyor" denir. Sorun, buradan genellemeye gitmenin zorluğudur. "3 milisaniye çalıştı" bilgisi tek başına anlamsızdır: 30 eleman için mi, 3000 eleman için mi? Girdi boyutu da bir parametredir. Bu yüzden algoritma $N$ eleman için çalıştırılır, farklı $N$ değerleri için süre ölçülür ve bu ölçümlere bir eğri uydurulur. Örneğin 2000 eleman için 0,8 saniye sürüyorsa 16000 eleman için ne kadar süreceği tahmin edilmeye çalışılır.

### 6.1 Log-log Grafik

Slayttaki örnekte (ekrandan, 01:05:00) çalışma süresi $T(N)$, $N$'e karşı log-log ölçekte çizilmiştir. Yatay eksende $\lg N$ (1K, 2K, 4K, 8K), dikey eksende $\lg T(N)$ vardır. Noktalar eğimi 3 olan düz bir çizgi üzerine düşer; dikey eksen yaklaşık üç büyüklük mertebesine (0,1 ile 51,2 saniye arası) yayılır.

Düz çizgi denklemi ve regresyonla bulunan katsayılar:

$$\lg T(N) = b\lg N + c,\qquad b = 2.999,\qquad c = -33.2103$$

Bu bir kuvvet yasasına (power law) karşılık gelir:

$$T(N) = a N^{b},\qquad a = 2^{c}$$

Slayttaki hipotez: çalışma süresi yaklaşık $1.006\times10^{-10}\times N^{2.999}$ saniyedir. Gerçekten $2^{-33.2103}\approx1.006\times10^{-10}$ olur (python ile kontrol edildi).

Bu modelle farklı $N$ değerleri için süre tahmin edilebilir (ara adım eklendi):

- $N = 8000$: $T \approx 1.006\times10^{-10}\times 8000^{2.999}\approx 51$ saniye.
- $N = 16000$: $T \approx 1.006\times10^{-10}\times 16000^{2.999}\approx 408$ saniye. Hoca bunu yaklaşık 400 saniye olarak verdi. Üs yaklaşık 3 olduğu için girdi iki katına çıkınca süre yaklaşık $2^3=8$ katına çıkar.

Böylece algoritmanın gerçek çalışma süresi $N$'e bağlı olarak ifade edilmiş olur. Aynı işi yapan başka bir algoritma için de böyle bir süre verilmişse ikisi karşılaştırılabilir.

## 7. Çalışma Zamanını Etkileyen Etkenler

Ölçüm sırasında bir öğrenci, sonucun işlemci hızına bağlı olduğunu söyledi. Hoca bunun doğru olduğunu, ama çalışma süresini etkileyen çok daha fazla etken bulunduğunu belirtti. Slayttaki sınıflandırma şöyledir (ekrandan, 01:10:00):

- Sistemden bağımsız etkenler
  - Algoritma
- Sisteme bağlı etkenler
  - Donanım: CPU, bellek, önbellek
  - Yazılım: derleyici, yorumlayıcı vb.
  - Sistem: işletim sistemi, ağ vb.

Algoritmanın kendisi, ne kadar karmaşık yazıldığına göre süreyi belirler. Ama aynı algoritma farklı donanımda, farklı derleyiciyle, farklı programlama diliyle ya da farklı işletim sisteminde farklı sürelerde çalışır.

Hoca programlama dilinin etkisini bir hikâyeyle anlattı. Bir bilgisayar ağları dersinde öğrencilere Dijkstra algoritmasını yazmaları ve en hızlı çalışan programa ek puan verileceği söylenmiş. Herkes C ile en verimli kodu yazmaya çalışırken bir öğrenci, ana bilgisayarın (mainframe) çok zor olan assembly dilini önce öğrenmiş, sonra Dijkstra algoritmasını bu assembly dilinde yazmış. Onun programı, C ile yazılanlardan kat kat hızlı çalışmış. Aynı algoritma C'de, Java'da ya da assembly'de yazıldığında farklı sürelerde çalışır.

Bir başka örnek derin öğrenmeden verildi. Derin öğrenme makalelerinde sistemin eğitiminin "şu özelliklerdeki donanımda şu kadar gün sürdü" diye yazıldığı görülür. Aynı donanımı sağlamak mümkün olmadığından okuyucu kendi donanımında bunun ne kadar süreceğini kestirmekte zorlanır. Bu yüzden algoritmanın verimliliğini sistem süresine göre değerlendirmek çok geçerli bir yaklaşım değildir. Bunun yerine matematiksel bir modelle ilerlenebilir.

## 8. Matematiksel Model: Maliyet ve Sıklık

Algoritma analizi alanında çok tanınmış, Turing ödüllü Donald Knuth'un ortaya koyduğu yaklaşım şudur: algoritmadaki her komutun ne kadar sürdüğüne ve kaç kez çalıştığına bakılır, bunların çarpımları toplanır.

$$\text{Toplam süre} = \sum_{\text{işlemler}} \text{maliyet} \times \text{sıklık}$$

<!-- BELİRSİZ: Altyazıda "Donald Turing ödülü olan..." geçiyor; soyadı Whisper'da düşmüş. Slaytın bu kısmı karelerde yok; Sedgewick'in slaytlarındaki Knuth atfına dayanarak "Donald Knuth" yazıldı. -->

### 8.1 Temel İşlemlerin Maliyeti

İlk adım, her temel işlemin maliyetini belirlemektir. Kitaptaki deneyde işlemler assembly seviyesinde tek tek ölçülmüştür. Hocanın sözlü aktardığı değerlere göre tam sayı toplama yaklaşık 2,1 nanosaniye, tam sayı çarpma 2,4 nanosaniye, kayan noktalı bölme 13,5 nanosaniye, kütüphane fonksiyonuyla arktanjant hesabı 129 nanosaniye sürmüştür (derste sözlü, 01:12:18). Bu ölçümler 2,2 GHz bir MacBook Pro üzerinde yapılmıştır. Çarpma ve bölmenin pahalı olduğunun söylenmesinin sebebi budur.

Çoğu temel işlem sabit zaman alır. Slayttaki tablo (ekrandan, 01:15:00; alt not: OS X, 2,2 GHz MacBook Pro, 2 GB RAM):

| işlem | örnek | nanosaniye |
|---|---|---|
| değişken tanımı | `int a` | $c_1$ |
| atama | `a = b` | $c_2$ |
| tam sayı karşılaştırma | `a < b` | $c_3$ |
| dizi elemanına erişim | `a[i]` | $c_4$ |
| dizi uzunluğu | `a.length` | $c_5$ |
| 1B dizi oluşturma | `new int[N]` | $c_6 N$ |
| 2B dizi oluşturma | `new int[N][N]` | $c_7 N^2$ |

Bir öğrenci bellek okuma ve yazma işlemlerinin dört işlemden daha yavaş olduğunu belirtti. Hoca bunu doğruladı ve ekledi:

> **Hocanın vurgusu:** Bir algoritmanın sistem süresini ölçecekseniz giriş/çıkış işlemlerini dışarıda bırakın. Okuma ve yazma çok yavaş olduğu için algoritmanın çalışma hızına katılmaz.

### 8.2 Örnek: Dizideki Sıfırları Saymak

$N$ elemanlı bir dizide kaç tane sıfır olduğunu sayan tek döngülü bir algoritma için işlem sıklıkları şöyle hesaplanır (derste sözlü, 01:16:05):

- Değişken tanımı: `count` ve `i` için 2 kez.
- Atama: 2 kez.
- "Küçüktür" karşılaştırması (`i < N`): $N+1$ kez. Döngü 0'dan başlar; $i=N$ olduğunda, yani $N+1$'inci karşılaştırmada döngüden çıkılır.
- Eşitlik karşılaştırması (`a[i] == 0`): döngüye $N$ kez girildiği için $N$ kez.
- Dizi erişimi: $N$ kez.
- Artırma: `i++` her turda yapılır ($N$ kez); `a[i]` sıfırsa `count` da artırılır. Bu yüzden artırma sayısı $N$ ile $2N$ arasında değişir.

<!-- BELİRSİZ: Bu örneğin kodu ve sıklık tablosunun bulunduğu slayt karelerde yok; değerler altyazıdaki anlatımdan aktarıldı. -->

### 8.3 Örnek: Toplamı Sıfır Olan Çiftleri Saymak

İkinci örnekte $i$ 0'dan $N-1$'e, $j$ ise $i+1$'den $N-1$'e kadar değişir ve her çift için `a[i] + a[j] == 0` denetlenir. İç içe iki döngü olduğundan bu denetim

$$\sum_{i=0}^{N-1}\ \sum_{j=i+1}^{N-1} 1 \;=\; \sum_{i=0}^{N-1} (N-1-i) \;=\; 0 + 1 + \dots + (N-1) \;=\; \frac{N(N-1)}{2}$$

kez yapılır (ara adım eklendi). Hoca, $1$'den $n$'e kadar sayıların toplamı gibi bu tür toplam formüllerinin ayrıca tablo olarak verileceğini söyledi.

Bu örnekteki bütün işlemlerin sıklıkları bir sonraki bölümdeki tabloda verilmiştir. Böyle bir hesap kısa bir kod için bile uzundur: $N+2$, $\tfrac12 N(N-1)$, $\tfrac12(N+1)(N+2)$ gibi terimler ortaya çıkar.

> **Ek bilgi (derste anlatılmadı):** Tablodaki "küçüktür" karşılaştırma sayısı şöyle elde edilir: dış döngü $N+1$ kez, $i$'ninci turdaki iç döngü $N-i$ kez karşılaştırma yapar. Toplam $(N+1) + \sum_{i=0}^{N-1}(N-i) = (N+1) + \tfrac{N(N+1)}{2} = \tfrac12 (N+1)(N+2)$ olur. Bu eşitlik python ile denetlenmiştir.

## 9. Basitleştirme ve Tilde Gösterimi

Bu kadar ayrıntılı hesap yorucudur; bu yüzden basitleştirmeye gidilir. Slayttaki ilkeler (ekrandan, 01:20:00):

- Çalışma süresi (ya da bellek) girdi boyutu $N$'in fonksiyonu olarak tahmin edilir.
- Düşük dereceli terimler göz ardı edilir:
  - $N$ büyükken bu terimler önemsizdir,
  - $N$ küçükken zaten süreyle ilgilenmeyiz.

Örneğin $N+2$ ifadesindeki 2, $N$ büyükken önemsizdir; buna $\sim N$ denir. $\tfrac12 N(N-1)$ için de $\sim\tfrac12 N^2$ yazılır. Çift sayma örneğinin sıklık tablosu ve tilde karşılıkları (ekrandan, 01:20:00):

| işlem | sıklık | tilde gösterimi |
|---|---|---|
| değişken tanımı | $N+2$ | $\sim N$ |
| atama | $N+2$ | $\sim N$ |
| küçüktür karşılaştırması | $\tfrac12(N+1)(N+2)$ | $\sim\tfrac12 N^2$ |
| eşitlik karşılaştırması | $\tfrac12 N(N-1)$ | $\sim\tfrac12 N^2$ |
| dizi erişimi | $N(N-1)$ | $\sim N^2$ |
| artırma | $\tfrac12 N(N-1)$ ile $N(N-1)$ arası | $\sim\tfrac12 N^2$ ile $\sim N^2$ arası |

Bu yaklaşık değerlerle gereksiz toplamalardan kurtulunur, ama sonuç yine $3N^2$ gibi katsayılı bir ifade olur. Toplam süre, örneğin $c_1$ kadar dizi erişimi, $c_2$ kadar toplama, $c_3$ kadar karşılaştırmanın maliyetlerinin toplamıdır. Büyük bir algoritmada her komutun maliyetini bilip sıklığını hesaplamak çok yorucudur.

Bu nedenle bir adım daha atılır:

- Sabitler de atılır: $N^2+2$ ise 2, $2N^2$ ise baştaki 2 elenir.
- Algoritmanın asıl yükü döngülerin içinde yapılan işlemlerdir. Döngü dışındaki işlemler tamamen göz ardı edilir. Döngü içinde de, zaman ölçülmek istense en ağır olan dizi erişimidir.
- Ama asıl amaç zamanı ölçmekten vazgeçip yalnız $N$'e bağlı bir sonuç üretmektir. Çünkü işlem maliyetleri (üç tane $a$, iki tane $b$ gibi katsayılar) tamamen makineye ve derleyiciye bağlıdır.

Böylece $N$'e bağlı olarak en çok yapılan işlem bulunur. Çift sayma örneğinde iç içe iki döngü vardır; karmaşıklık, bu iki döngüye kaç kez girildiğine bakılarak hesaplanır. $N$'e bağlı bir sonuç verildiğinde derleyici, donanım gibi sisteme bağlı etkilerden tamamen kurtulunur ve algoritmanın verimliliği hakkında aşağı yukarı bir fikir edinilir.

## 10. Büyüme Dereceleri

Slayttaki büyüme dereceleri tablosu (ekrandan, 01:25:00):

| büyüme derecesi | ad | tipik kod kalıbı | açıklama | örnek | $T(2N)/T(N)$ |
|---|---|---|---|---|---|
| $1$ | sabit | `a = b + c;` | ifade | iki sayıyı toplama | 1 |
| $\log N$ | logaritmik | `while (N > 1) { N = N / 2; ... }` | ikiye bölme | ikili arama | $\sim 1$ |
| $N$ | doğrusal | `for (int i = 0; i < N; i++) { ... }` | döngü | en büyüğü bulma | 2 |
| $N\log N$ | doğrusal-logaritmik | (mergesort dersine bakınız) | böl ve yönet | mergesort | $\sim 2$ |
| $N^2$ | karesel | iç içe iki `for` | çift döngü | tüm çiftleri denetleme | 4 |
| $N^3$ | kübik | iç içe üç `for` | üçlü döngü | tüm üçlüleri denetleme | 8 |
| $2^N$ | üstel | (kombinatoryal arama dersine bakınız) | kapsamlı arama | tüm alt kümeleri denetleme | $T(N)$ |

Hoca tabloyu şu örneklerle açıkladı:

- **Sabit:** Verilen bir sayının mutlak değerini hesaplayan algoritma alt alta birkaç komuttan oluşur ve $N$'e bağlı değildir. Büyüme derecesi 1'dir.
- **Logaritmik:** İkili aramada önce $N$ eleman vardır. Aranan eleman dizinin ilk yarısındaysa ikinci yarı elenir ve $N/2$ eleman kalır; bir adım sonra $N/4$ eleman kalır. Bu şekilde ikiye bölerek ilerleyen algoritmaların karmaşıklığı $\log N$'dir.
- **Doğrusal:** En küçük ya da en büyük elemanı bulmak ya da sırasız bir dizide bir elemanın yerini aramak, en kötü durumda bütün diziyi dolaşmayı gerektirir; karmaşıklık $N$'dir.
- **Doğrusal-logaritmik:** Böl ve yönet algoritmalarının bir kısmı $N\log N$ karmaşıklıktadır. İşlem $N$ kez yapılıyor ama her biri $\log N$ ile çarpılan bir maliyete sahip gibi düşünülebilir.
- **Karesel ve kübik:** İç içe iki döngü $N^2$, iç içe üç döngü $N^3$ karmaşıklık verir.
- **Üstel:** Tüm alt kümeleri deneyen algoritmalar $2^N$ karmaşıklıktadır.

Son sütun, girdi iki katına çıktığında sürenin kaç katına çıktığını gösterir. Örneğin karesel bir algoritmada $T(2N)/T(N) = (2N)^2/N^2 = 4$ olur.

> **Ders sonrası not:** Hoca $N\log N$ sınıfı için böl ve yönet örneği verirken "Heapsort gibi algoritmalarda bölerek işlem yapılıyor" dedi. Slayttaki örnek mergesort'tur. Heapsort da $N\log N$ sürede çalışır, ama bir yığın (heap) veri yapısına dayanır ve genellikle böl ve yönet algoritması olarak sınıflandırılmaz.

<!-- BELİRSİZ: Altyazıda 01:25:56-01:26:50 arasındaki T(2N)/T(N) oranı açıklaması Whisper tarafından bozulmuş; tablo değerleri kareden alındı. -->

### 10.1 İki Yaklaşımın Karşılaştırması

Ders boyunca algoritmanın zamanı verimli kullanıp kullanmadığını anlamak için iki yol görüldü: gerçekten çalışma süresini ölçmek ve her komutun kaç kez çalıştığına bakarak hesap yapmak. İkisi de pratikte kullanılır. Bütün algoritmaların karmaşıklığı kolay hesaplanamaz; örneğin bir derin öğrenme algoritmasında yapılan işlemlerin karmaşıklığını ifade etmek zordur, bu yüzden böyle durumlarda karmaşıklık yerine ölçülen süre verilir.

> **Hocanın vurgusu:** Temel algoritmaların karmaşıklığı sorulduğunda yapılması gereken, karmaşıklığı $N$'e bağlı olarak ve sabit değerleri dikkate almadan bulmaktır.

## Örnek Sorular

### Soru 1

(derste sözlü, 00:23:11)

Bir web sayfasından başka sayfalara art arda geçtikten sonra, bulunduğunuz yerden bir önceki sayfaya, oradan da bir öncekine geri dönmek istiyorsunuz. Bu problemi çözmek için hangi veri yapısını kullanmak uygun olur?

> **Çözüm:** Yığın (stack). Her yeni sayfaya geçerken önceki sayfanın adresi yığına itilir. Geri dönülmek istendiğinde yığının tepesindeki adres, yani en son gelinen yer alınır.

### Soru 2

(ekrandan, 00:40:00)

Aşağıdaki kod parçası 64 kanallı bir radyo programından alınmıştır. `ifcf_lev_over[i]` ve `ifcf_lev_under[i]`, $i$'ninci kanalın üst ve alt sınırlarıdır. Kod ne yapmaktadır?

```c
for (i=0;i!=64;i++){
    ifcf_diff[i]= ifcf_lev_over[i] - ifcf_lev_under[i];
}

for(cf_v=0;cf_v!=50;cf_v++){
    if(ifcf_set==1){break;}
    for (i=0;i!=64;i++){
        ifcf_diff2 = ifcf_diff[i];
        ifcf_val3=i;
        if ((ifcf_diff2>=-cf_v)&&(ifcf_diff2<=cf_v)){ifcf_set=1;break;}
    }
}
```

> **Çözüm:** Kod, üst ve alt sınır farkı mutlak değerce en küçük olan kanalı bulur ve indisini `ifcf_val3` değişkenine yazar. `cf_v` 0'dan artarken her değer için 64 kanal taranır; $|fark| \le cf\_v$ koşulunu sağlayan ilk kanalda arama durur. İki karşılaştırma mutlak değerin yerini tutar. En kötü durumda $64 + 50\times64$ iç adım yapılır; oysa aynı sonuç tek bir 64'lük döngüde mutlak farkların en küçüğü tutularak bulunabilir (derste sözlü, 00:45:50).

### Soru 3

(derste sözlü, 00:45:41)

Bir dizinin en küçük elemanını bulmanın karmaşıklığı nedir?

> **Çözüm:** Dizinin bütün elemanlarına bir kez bakmak gerekir ve bu yeterlidir; $N$ elemanlı bir dizi için karmaşıklık $N$'dir (doğrusal). min-diff örneğinde bu, 64 adımlık tek bir döngü demektir.

### Soru 4

(derste sözlü, 01:02:16)

Bir algoritmanın zamanı nasıl kullandığını nasıl ölçebilirsiniz?

> **Çözüm:** İlk yol, çalışma süresini gerçekten ölçmektir: C'de `clock()` ile başlangıç ve bitiş zamanları alınıp farkı `CLOCKS_PER_SEC`'e bölünür, farklı $N$ değerleri için ölçüm yapılıp log-log grafikle $T(N)=aN^b$ modeli kurulur. Ancak sonuç donanıma, derleyiciye, dile ve işletim sistemine bağlıdır. İkinci yol, matematiksel modeldir: her işlemin maliyeti ile sıklığı çarpılıp toplanır, sonra sabitler ve düşük dereceli terimler atılarak yalnız $N$'e bağlı büyüme derecesi elde edilir.

## Dersin Toparlaması

Bu giriş dersinde önce dönem boyunca görülecek konular ve kaynaklar tanıtıldı, algoritma analizinin veri yapıları ve algoritmalar dersinin devamı olarak neden gerekli olduğu anlatıldı. Algoritma, her geçerli girdi için sonlu sürede doğru çıktı veren, belirsizlik içermeyen komutlar dizisi olarak tanımlandı. İyi bir algoritmanın doğru, zaman ve yer açısından verimli, basit ve genel olması gerektiği vurgulandı. Gerçek bir açık kaynak kod parçası üzerinden, çalışan ama anlaşılmaz ve gereksiz yere $50\times64$ adım dönen bir tasarımın, tek döngülük bir en küçük eleman aramasıyla nasıl çok daha sade ve verimli yazılabileceği gösterildi.

Dersin ikinci yarısında çalışma süresini ölçme yolları ele alındı. Deneysel ölçüm ve log-log regresyon, $T(N)=aN^b$ biçiminde bir tahmin modeli verir ama sisteme bağlıdır. Knuth'un matematiksel modeli işlemlerin maliyet ve sıklıklarını toplar; tilde gösterimi ve sabitlerin atılmasıyla bu model, yalnız $N$'e bağlı büyüme derecesine indirgenir. Son olarak sabit, logaritmik, doğrusal, doğrusal-logaritmik, karesel, kübik ve üstel büyüme dereceleri tipik kod kalıplarıyla tanıtıldı. Bir sonraki derste algoritma çözümüne ve asimptotik analize geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
