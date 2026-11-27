# Ders 17 Genişletilmiş Notu: Vize Çözümleri, Öncelikli Kuyruk (Priority Queue) ve Huffman Ağacı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Vize Test Sorularının Çözümü
- 2. Vize Algoritma Sorularının Çözümü
- 3. Öncelikli Kuyruk Nedir?
- 4. Max ve Min Öncelikli Kuyruk ve Uygulamaları
- 5. Öncelikli Kuyruk İşlemleri
- 6. Max-Priority Queue C Kodu
- 7. Huffman Ağacı
- Örnek Sorular
- Dersin Toparlaması

## 1. Vize Test Sorularının Çözümü

Dersin ilk bölümünde hoca vize sorularını beyaz tahtaya yapıştırıp tek tek çözdü. Soru metinleri, şıklar ve çözümlerin tamamı "Örnek Sorular" bölümünde yer alıyor. Bu bölümde çözümlerde öne çıkan kavramsal noktalar anlatılıyor.

### 1.1 Bağlı liste mi, dizi mi?

Bağlı listenin en güçlü yanı ekleme ve silmenin kolaylığıdır. Dizinin ortasından bir eleman silinirse arkasındaki bütün elemanlar kaydırılmak zorundadır ve bu $O(n)$ işlemdir. Bağlı listede ise yalnız silinecek düğüm bağlantılardan çıkarılır. Güncellemede durum terstir: dizide indisteki göz doğrudan değiştirilir, bağlı listede önce düğüm aranıp bulunmalıdır. Aramada da dizi üstündür; hele dizi sıralıysa arama çok daha verimli yapılır. Bağlı listede ise `next`, `next` diye tek tek ilerlemek gerekir. En küçük ya da en büyük elemanı bulmada bağlı listenin ek bir avantajı yoktur.

### 1.2 Ağacın yüksekliği ekleme sırasına bağlıdır

Sıralı bir dizi (5, 8, 9, 12, 24, 48, 64) sırayla ikili arama ağacına eklenirse "büyükler sağa, küçükler sola" kuralı yüzünden her eleman bir öncekinin sağına gider. Sonuç, aslında bir bağlı liste gibi görünen zincir biçiminde bir ağaçtır. Ağacı dengeli kurmak için ortadaki eleman köke alınır, sonra her alt dizinin ortadaki elemanı o alt ağacın kökü yapılır. Hoca AVL ağacının yüksekliği $\log n$ mertebesinde tutmak için döndürme işlemleri yaptığını hatırlattı, ama bu soruda bunun bilinmesine gerek olmadığını söyledi. Bu şekilde kurulan ağaç mükemmel (perfect) bir ikili ağaçtır. 7 eleman en az 3 seviyeye sığdığı için bundan daha iyi bir ağaç kurulamaz.

### 1.3 İşleme göre veri yapısı seçimi

Fonksiyonlara gidip dönme işlemleri derste anlatılan fonksiyon çağrı yığıtıyla (function call stack) yönetilir. Klavyede basılan tuşların ekrana yazılmasında ilk basılan tuş önce yazılmalıdır, yani ilk giren ilk çıkar (FIFO): tuş olayları bir kuyrukta tutulur. Dengesiz bir ikili ağaç dizide tutulursa boş gözler için de yer ayrılması gerekir. Hoca bunu P, R, V, Z düğümlerinden oluşan dengesiz bir ağaçla gösterdi: bağlı listeyle 4 düğüm yeterken dizide 15 göz açmak gerekir. Satrançta bir sonraki hamle önceki hamlelere bağlıdır. Kökte ilk hamle, her hamleden sonra olası hamleler çocuk düğümler olarak dallanır; bu bir ağaçtır.

### 1.4 Kuyruğu yığıtla ters çevirme

Kuyruktaki elemanlar sırayla dequeue edilip yığıta push edilir, sonra yığıttan pop edilip yeniden kuyruğa enqueue edilir. Yığıt sırayı ters çevirdiği için kuyruk da ters çevrilmiş olur. Soruda ilk döngüde `enqueueQueue(queue)` yazılmıştı. Hoca bunun bir yazım hatası olduğunu kabul etti. Kuyruk parametresi alıp bir değer döndüren fonksiyonun imzasından işlemin dequeue olduğunun anlaşılması gerektiğini söyledi.

> **Hocanın vurgusu:** Enqueue, dequeue, push ve pop dört temel işlemdir. Bir fonksiyonun aldığı parametre ve döndürdüğü değer, onun hangi işlem olduğunu gösterir.

### 1.5 İkili arama ağacında arama yolu

"Hangi sıra ile bakılamaz?" sorusu aslında "Bu dizilerden hangisi bir ikili arama ağacındaki arama yolu olamaz?" demektir. Arama yolunda her adımda aranan değerin bulunabileceği aralık daralır. Örneğin 2'den sağa, 7'den sola gidildiyse artık görülecek her düğüm 2 ile 7 arasında olmalıdır.

**Soru:** Ağaçta verilenlerin dışında başka elemanlar da olabilir; o elemanları sırayla ekleyerek böyle bir ağaç kurulamaz mı? **Cevap:** Soruda sorulan, arama sırasında karşılaştırılan elemanlardır. 2'nin sağında 7 varken 7'nin sol alt ağacında 8 duramaz; 8 ancak 7'nin sağında olabilir. Durmuyorsa ağaç ikili arama ağacı değildir.

### 1.6 Heap'ten birden çok eleman silme

Bir extract-min işleminde kök çıkarılır, son eleman köke konur ve heapify ile aşağı taşınır. Bu $O(1)$ artı $O(\log n)$, yani $O(\log n)$ işlemdir. Üç kez yapıldığında $3\log n$ olur. Big-O gösteriminde katsayı atıldığı için sonuç $O(\log n)$'dir.

### 1.7 Parantez dengesi ve yığıt

Açılış parantezi görülünce yığıta push edilir, kapanış parantezi görülünce en üstteki pop edilip karşılaştırılır. Hoca 4 açılış ve 5 kapanış parantezinden oluşan rastgele bir diziyi örnek olarak işledi. Bir kapanış parantezi geldiğinde yığıtta pop edilecek eleman kalmadığı için parantezlerin dengeli olmadığına karar verildi. Yığıtta aynı anda bulunabilecek en fazla eleman sayısı, açılış parantezi sayısıdır. Bu sayıya, 4 açılış parantezi arka arkaya geldiğinde ulaşılır.

### 1.8 İç içe döngü karmaşıklığı

Dış döngü $n/2$'den $n$'e kadar birer birer artar. Örneğin $n = 10$ için 5, 6, 7, 8, 9, 10 değerlerini alır, yani yaklaşık $n/2$ kez döner. İç döngü `j = 2`'den başlar ve `j *= 2` ile ikiyle çarpılarak büyür: 2, 4, 8, 16, ... Bu yaklaşık $\log_2 n$ adımdır. İçteki atama ve bölme sabit sayıda işlemdir. Toplam $\frac{n}{2}\cdot\log n$ olur; Big-O'da katsayı atılınca $O(n\log n)$ elde edilir. Logaritmanın tabanı 2'dir, ama Big-O'da taban yazılmaz.

> **Ders sonrası not:** Hoca iç döngüyü anlatırken önce "2, 4, 6, 8 diye gidiyor" dedi, sonra ikinin katları şeklinde ilerlediğini söyledi. Doğrusu, `j *= 2` ile `j` 2, 4, 8, 16, 32, 64, ... diye ikinin kuvvetleri olarak ilerler. Sonuç ($\log n$ adım) değişmez. Python ile sayıldığında iç gövde tam olarak $(n/2+1)\lfloor\log_2 n\rfloor$ kez çalışır (örneğin $n = 1024$ için 5130).

### 1.9 Üçlü (ternary) heap

Hoca heap'in yalnız ikili olmak zorunda olmadığını hatırlattı. Derste ikili heap'lere odaklanıldı, ama heap farklı ağaç yapılarıyla da gerçeklenebilir. Üçlü min-heap'te her ebeveyn düğümün kendinden büyük değere sahip 3 çocuğu vardır ve ağaç complete'tir (son seviye soldan doludur). İkili heap'ten tek farkı, heapify sırasında iki yerine üç çocukla karşılaştırma yapılmasıdır.

### 1.10 Ara adımdan sıralama algoritmasını tanıma

Selection sort her iterasyonda kalanların en küçüğünü bulup sıradaki göze yerleştirir. Bu yüzden dizinin başında hep genel sıralamanın en küçük elemanları görülür. Insertion sort ise elemanları kart dizer gibi alıp kaydırarak yerine koyar. Dizinin başında kendi içinde sıralı bir bölüm vardır, ama bu bölüm henüz görülmemiş küçük elemanları içermeyebilir. Heap sort'ta ise dizi bir max-heap düzenindedir: kökte en büyük eleman, çocuklarında daha küçükler vardır. Büyükten küçüğe doğru bir sıralanma eğilimi insertion sort ile açıklanamaz.

## 2. Vize Algoritma Sorularının Çözümü

Hoca test soruları ile algoritma sorularının ayrı oturumlarda sorulmasının nedenini, her soruya ayrı süre tanınması olarak açıkladı. Ardından iki algoritma sorusunun çözüm yolunu anlattı (kod yazmadan).

### 2.1 Seyrek (sparse) matriste sıfır sütunları

Bir matrisin elemanlarının yarısından fazlası sıfırsa ona seyrek (sparse) matris denir. Sıfırlar gereksiz yer kaplamasın diye matris bağlı listeyle saklanır. Her düğümde satır indisi, sütun indisi, değer ve `next` işaretçisi bulunur. Soruda girdi doğrudan bağlı liste biçiminde okunur, matristen listeye dönüşüm kodu beklenmez.

Hocanın önerdiği çözüm şudur: sütun sayısı kadar bir dizi açılır ve her göze 1 yazılır (anlamı: "bu sütun tamamen sıfır olabilir"). Sonra bağlı liste bir kez gezilir. Listede yalnız sıfırdan farklı hücreler bulunduğu için her düğümün sütun gözü 0 yapılır. Gezinti bitince 1 kalan gözler tamamen sıfırdan oluşan sütunlardır. Başlangıç değeri olarak 0 yazıp görülen sütunlara 1 yazmak da aynı işi görür. Böylece toplam sütun sayısı kadar ek bir diziyle ve listenin tek bir gezintisiyle sonuca ulaşılır. Hoca bu diziyi bir sigorta ya da semafor gibi düşünebileceğimizi söyledi.

### 2.2 Yazıcı kuyruğu ve aradan silme

Ağdaki bilgisayarlara hizmet veren bir yazıcıya gelen işler gelme sırasıyla basılacağı için FIFO bir kuyruk kurulur. İstenen üç parça şunlardı:

- Sıradaki işi basan fonksiyon: kuyruğun başındaki iş dequeue edilir ve sayfa sayısı kadar bir `for` döngüsü döner. Döngünün içinde her sayfa için bir `printf` yazılabilir ya da döngü boş bırakılabilir.
- Aradan silme fonksiyonu (örneğin `cancel_print`): kuyrukta bekleyen bir işi diğerlerinin sırasını bozmadan siler, iş kuyrukta yoksa uyarı verir.
- Yazma isteklerini alan (iş numarası ve sayfa sayısını okuyup enqueue eden) ve bu fonksiyonları kullanan ana program.

Asıl nokta, silmenin yalnız kuyruk işlemleriyle yapılmasıdır. Dizide arayıp kaydırmak bu sorunun beklediği çözüm değildir. Hoca ve öğrencilerle birlikte üç yol konuşuldu:

- Yedek kuyrukla boşalt-doldur: ana kuyruktan dequeue edilen her iş yedek kuyruğa enqueue edilir. Silinecek iş (örnekte 43) bulunduğunda hiçbir yere eklenmez. Ana kuyruk tamamen boşalana kadar devam edilir, sonra yedek kuyruktaki işler aynı şekilde ana kuyruğa geri aktarılır. Hoca sınavda kendisinin bu yolu seçeceğini söyledi.
- Kuyrukların rolünü değiştirmek: geri aktarmak yerine bundan sonra yedek kuyruk ana kuyruk olarak kullanılır. Hangi kuyruktan basıldığını gösteren bir işaret (flag) ya da pointer basma fonksiyonuna gönderilir. Hoca bunu en iyi (optimum) çözüm olarak niteledi.
- Tek kuyrukla dairesel dolaşma: eleman sayısı bilindiği için aynı kuyrukta dequeue edip yeniden enqueue ederek tam bir tur dönülür, silinecek iş geri eklenmez. Bu yol front ve rear işaretçilerine dikkat etmeyi gerektirir.

**Soru:** Algoritmanın başında yedek kuyruğu `malloc` ile oluşturup her silmede yeniden yaratmak doğru mu? **Cevap:** Yanlış değildir, ama gereksiz iş yükü getirdiği için verimli değildir.

**Soru:** Enqueue ve dequeue fonksiyonları verilmediği için herkes farklı yazmış olabilir; ana programda nasıl bir çıktı beklendi? **Cevap:** Ana programın biçimi serbesttir, basma döngüsünde sayfanın basıldığını gösteren bir `printf` yeterlidir. Enqueue ve dequeue bilinçli olarak öğrenciye bırakıldı; dizi ya da bağlı listeyle gerçeklenmesi serbesttir. Değerlendirilen asıl kısım yedek ya da dairesel kuyruk mekanizmasıdır.

**Soru:** Bellek sızıntısı (memory leak) sorun olur mu? **Cevap:** Program segmentation fault veriyorsa sorundur. Belleği `free` etmek iyi olur, ama etmemek programı tek başına yanlış yapmaz.

## 3. Öncelikli Kuyruk Nedir?

Aradan sonra hoca bu haftanın konusu olan öncelikli kuyruğa (priority queue) geçti. Bunun yeni bir veri yapısı olmadığını, vizeden önceki haftanın konusu olan heap ile gerçekleneceğini söyledi.

Öncelikli kuyruk da aynı tipteki elemanları bir arada tutan bir veri yapısıdır. Farkı, her elemanın bir anahtar (öncelik) değeriyle ilişkilendirilmesidir. Anahtar değerinin büyüklüğüne ya da küçüklüğüne göre elemanlar önceliklendirilir ve bu sırayla işlenir ya da hizmet alır. Bir heap ile gerçeklenirse işlenecek eleman (en büyük önceliğe sahip ya da en küçük sıra numaralı) her zaman birinci gözde durur. Birinci elemana bakmak $O(1)$'dir. Onu çekmek ve kuyruğu yeniden düzenleyip sıradakini hazırlamak $O(\log n)$ sürer. Özetle öncelikli kuyruk temelde bir heap'tir ve heap'te tutulan değerler elemanların öncelik numaralarıdır.

## 4. Max ve Min Öncelikli Kuyruk ve Uygulamaları

### 4.1 Max-priority-queue ve işletim sistemi zamanlayıcısı

Max-priority-queue bir max-heap ile gerçeklenir: yüksek önceliğe sahip eleman önce hizmet alır. Slaytta işlemler şöyle verildi (ekrandan, 01:50:00):

- `insert(s,x)`: $x$ önceliğine sahip bir elemanı kuyruğa ekleme
- `max(s)`: en büyük önceliğe sahip elemanı sorgulama
- `extract_max(s)`: en büyük öncelikli elemanı kuyruktan çıkarma
- `increase_key(s,x,k)`: $x$ önceliğine sahip elemanın önceliğini $k$'ya çıkarma ($k \ge x$)

Örnek, işletim sistemindeki süreç zamanlayıcıdır (process scheduler). Her sürecin bir kimliği (process ID), bellek ve kod adresleri gibi bilgileri vardır. İşletim sistemi açısından her süreç sistem kaynaklarına erişmek isteyen bir istemcidir ve bunların önceliklendirilmesi gerekir. Bunun için her sürece bir öncelik değeri atanır. Örneğin 100 üzerinden düşünülürse 100 öncelikli bir iş, her şey dursun ve mutlaka o çalışsın denecek kadar kritik bir iştir; 1 öncelikli bir iş ise ara sıra hizmet alır.

Bir iş bittiğinde ya da kendisine ayrılan sürede bitmeyip kesintiye uğradığında zamanlayıcı, sıradaki en yüksek öncelikli işi tek bir `extract_max` ile alır ve çalıştırır. Zamanlayıcı herhangi bir anda `insert` ile yeni bir iş ekleyebilir; yeni iş mevcutlardan daha yüksek ya da daha düşük öncelikli olabilir ve olması gereken yere yerleşir. Hoca Windows görev yöneticisinde bir sürecin önceliğini artırma ya da azaltma seçeneğini örnek verdi. Gerektiğinde bir işin önceliği artırılabilir ya da düşürülebilir. Zamanlayıcı bütün bunları öncelikli kuyruk üzerindeki işlemlerle hızlı ve verimli biçimde yapabilmelidir.

Min-priority-queue'da `max` yerine `min`, `extract_max` yerine `extract_min` kullanılır.

### 4.2 Olay güdümlü simülatör

Olay güdümlü simülatörde (event-driven simulator) olayların gerçekleşme zamanları anahtar değerleridir. Önce gerçekleşen olay simülasyonda önce yer almalıdır. Bir olayın simülasyonu gelecekte başka olayların doğmasına neden olabilir. Bu yeni olaylar kuyruğa eklenir, belki mevcut olayların önüne geçer. Böyle bir simülatörde her seferinde `extract_min` ile en küçük zaman değerine sahip olay çekilir, yeni doğan olaylar da `insert` ile min-priority-queue'ya eklenir.

### 4.3 Banka sıra numarası örneği

Bankada düğmeye basıp sıra numarası alınır: 342, sonra 343, 344... Bu numaralar müşterinin geliş sırasıdır ve küçük numara önce hizmet alır; yani bu bir min-priority-queue'dur. Bankanın müşterisi olan biri kartını kullanarak numara aldığında ona örneğin 120 gibi daha küçük bir numara verilebilir. Bu müşteri, 342 ve 343'ün önüne geçerek heap'in köküne yerleşir. Daha da öncelikli bir müşteri 10 numarayı alırsa o da yukarı taşınarak köke çıkar, 120 onun altına iner. Görevli bir sonraki müşteriyi çağırdığında olan şey bir `extract_min` işlemidir: önce 10, sonra 120 hizmet alır, 342 ve 343 beklemeye devam eder.

Önceliği artırmaya da banka örneği verildi: sıra numarası 343 olan bir müşteri, önüne sürekli birileri geçtiği için kartını kullanıp yeni bir numara (örneğin 160) alırsa anahtar değerini iyileştirmiş olur. Min-priority-queue'da bu daha küçük bir değere gitmek, max-priority-queue'da ise anahtarı artırmak demektir.

## 5. Öncelikli Kuyruk İşlemleri

Hoca max-heap üzerinden devam etti. Bütün `max`'lar `min`'e çevrildiğinde min-priority-queue elde edilir.

### 5.1 En büyük elemana bakmak

`HEAP_MAXIMUM` yalnız `A[1]`'i döndürür. Eleman kuyruktan çekilmez, yalnız değeri okunur. Tek işlem olduğu için $O(1)$'dir.

### 5.2 En büyük elemanı kuyruktan çıkarmak

Slayttaki adımlar ve akış diyagramı (ekrandan, 02:00:00):

- Heap boş olmamalı ($n \ge 1$ kontrolü).
- Kök elemanın kopyası çıkarılır: `max = A[1]`.
- Son düğüm kök düğüm yapılır: `A[1] = A[n]`.
- Bir az eleman sayısı ile `MAX_HEAPIFY(A, 1, n-1)` yapılır (heap boyutu 1 azaltılır).
- `max` değeri işlemler için çağırana döndürülür.

Hoca son elemanın köke "bilerek ve isteyerek" konduğunu, böylece heap özelliğinin bilinçli olarak bozulduğunu, sonra `MAX_HEAPIFY` ile yeniden sağlandığını vurguladı. `MAX_HEAPIFY` yüzünden karmaşıklık $O(\log n)$'dir. Kuyrukta 1024 müşteri bekliyorsa en öncelikli müşteri yaklaşık 10 adımda çekilebilir. Sayı büyüdükçe bu kazanç daha belirgin olur.

Örnek heap (max-priority-queue, süreç öncelikleri) şöyleydi. Python ile doğrulanan dizi biçimi 20, 15, 8, 10, 5, 7, 6, 2, 9, 1'dir.

```text
            20
         /      \
       15        8
      /  \      / \
    10    5    7   6
   /  \   /
  2    9 1
```

`extract_max` ile 20 çıkar ve son eleman 1 köke gelir. 1; çocukları 15 ve 8 ile karşılaştırılır, büyük olan 15 yukarı çıkar. 1 yeni yerinde çocukları 10 ve 5 ile karşılaştırılır, 10 yukarı çıkar. Sonra 2 ve 9 ile karşılaştırılır, 9 yukarı çıkar ve 1 yaprağa iner. Sonuç dizi 15, 10, 8, 9, 5, 7, 6, 2, 1 olur (python ile doğrulandı). Hoca önceliği 1 olan sürecin büyük olasılıkla bütün bu süreçlerden sonra çalışacağını, ama önceliği yükseltilirse ona da sıra gelebileceğini ekledi.

### 5.3 Anahtar değerini artırmak

Yeni değer mevcut değerden büyük ya da ona eşit olmalıdır; bu kontrol yapılır. Sonra $i$. göze yeni anahtar yazılır ve eleman ebeveyniyle karşılaştırılarak yukarı taşınır. Slayttaki örnek (ekrandan, 02:05:00):

- (a) Heap: 16; 14, 10; 8, 7, 9, 3; 2, 4, 1. $i$ ile gösterilen düğümün değeri 4'tür.
- (b) 4 değeri 15 yapılır.
- (c) 15, ebeveyni 8'den büyük olduğu için onunla yer değiştirir.
- (d) 15, ebeveyni 14'ten büyük olduğu için onunla yer değiştirir. Sonraki ebeveyn 16'dan küçük olduğu için orada durur.

Sonuç dizi 16, 15, 10, 14, 7, 9, 3, 2, 8, 1 olur (python ile doğrulandı). 15 köke çıkamaz; başka bir eleman gelmez ya da başka bir öncelik değişmezse 16'dan sonra ikinci sırada hizmet alır. Hoca, heap'te yalnız ebeveynin çocuklarından büyük olmasının garanti edildiğini, 15'in başka bir konumda da durabileceğini hatırlattı.

### 5.4 Yeni eleman eklemek

Heap'te yeni bir göz açılır (son eleman) ve max-heap olduğu için anahtar olarak $-\infty$ yazılır. Hoca bunun için `limits.h` kütüphanesinden yararlanılabileceğini söyledi. Ardından `increase_key` ile bu göze $k$ değeri verilir ve eleman ebeveynleriyle karşılaştırılarak yukarı taşınır. En fazla ağacın köküne kadar gidebileceği için karmaşıklık $O(\log n)$'dir.

## 6. Max-Priority Queue C Kodu

Hoca bir heap gerçeklemesinin öncelikli kuyruk olarak nasıl kullanılacağını göstermek için C kodunu slaytlardan anlattı. Kod sabit boyutlu bir dizi kullanır: `tree_array_size` 20'dir, başta `heap_size` 0'dır. `heap_size` asıl öncelikli kuyruğun boyutudur. Artı sonsuz için `INF` olarak 100000 tanımlanmıştır. Hoca normalde `limits.h` içindeki `INT_MAX`'ın kullanılmasının daha doğru olacağını, kodu basit tutmak için kütüphane eklenmediğini söyledi. İki adresteki değeri geçici bir değişkenle yer değiştiren basit bir `swap` fonksiyonu da vardır; değerler yukarı taşınırken bu fonksiyon kullanılır.

### 6.1 Yardımcı fonksiyonlar

Hoca bu kodun daha fazla kontrol içeren, "tam teşekküllü" bir sürüm olduğunu söyledi. Sağ çocuk, sol çocuk ve ebeveyn indisleri sınır kontrolüyle alınır; sınır dışındaysa $-1$ döner (ekrandan, 02:10:00):

```c
int get_right_child(int A[], int index) {
  if((((2*index)+1) < tree_array_size) && (index >= 1))
    return (2*index)+1;
  return -1;
}

int get_left_child(int A[], int index) {
    if(((2*index) < tree_array_size) && (index >= 1))
        return 2*index;
    return -1;
}

int get_parent(int A[], int index) {
  if ((index > 1) && (index < tree_array_size)) {
    return index/2;
  }
  return -1;
}
```

Örneğin çocuğu olmayan bir yaprak için `get_right_child` çağrılırsa $2i+1$ dizi boyutunu aşar; bu kontrol yapılmazsa hata alınır. Ebeveyn için $i/2$ tam sayı bölmesi kullanılır.

### 6.2 MAX_HEAPIFY

<!-- BELİRSİZ: max_heapify, extract_max, increase_key ve decrease_key fonksiyonlarının slayt kodları karelerde görünmüyor; aşağıdaki anlatım altyazıdan kurulmuştur. -->

`max_heapify`, verilen bir indis için heap özelliğini garanti eder. Önce sol ve sağ çocukların indisleri sınır kontrolüyle alınır. Başlangıçta `largest` verilen indis kabul edilir. Sol çocuk heap sınırları içindeyse ve değeri `largest`'taki değerden büyükse `largest` sol çocuk olur. Aynı kontrol sağ çocuk için yapılır. `largest` verilen indise eşit değilse `swap` ile iki değer yer değiştirir. Aşağı inen değerin de kendi çocukları olabileceği için `max_heapify` o alt ağaç için özyinelemeli olarak yeniden çağrılır. `largest` verilen indise eşitse heap özelliği zaten korunuyordur ve hiçbir şey yapılmaz.

### 6.3 Öncelikli kuyruk oluşturma

`build_max_heap`, `heap_size/2`'den 1'e kadar geriye doğru her düğüm için `max_heapify` çağırır (ekrandan, 02:15:00):

```c
void build_max_heap(int A[]) {
  int i;
  for(i=heap_size/2; i>=1; i--) {
    max_heapify(A, i);
  }
}
```

Hoca bunu 6 düğümlü bir heap çizerek anlattı. Heap dizisinde 0. göz boş geçilir. $n/2$'ye kadar olan gözler çocuğu olan düğümlerdir, $n/2$'den sonrakiler yapraktır. 6 düğümlü örnekte 3, 2 ve 1. düğümler sırayla heapify edilir. Hoca 6. düğümü, 3. düğümün de çocuğu olsun diye eklediğini söyledi. Özyineleme nedeniyle üstteki bir düğüm heapify edilirken alttaki düğümlere yeniden bakılması gerekebilir. 3, 2, 1 sırasıyla yapılan heapify bütün ağacın max-heap olmasını garanti eder. Max-priority-queue oluşturmak da birebir aynıdır.

### 6.4 extract_max, increase_key, decrease_key

`extract_max` kodu algoritmanın aynısıdır: `A[1]` bir `maximum` değişkenine kopyalanır, `A[heap_size]` köke konur, heap boyutu bir azaltılır ve 1. düğüm için `max_heapify` çağrılır. Hoca her şeyin dönüp dolaşıp `max_heapify`'a geldiğini, bu fonksiyon doğru yazıldıktan sonra heap'in ve öncelikli kuyruğun bütün işlemlerinin $O(\log n)$'de rahatça yapılabileceğini söyledi.

`increase_key`'de de ek kontroller vardır. Koşul (indisin 1'den büyük olması ve ebeveyndeki değerin daha küçük olması) doğru olduğu sürece eleman ebeveyniyle `swap` edilir ve indis ebeveynin indisine güncellenir. `decrease_key`'de verilen göz yeni, daha küçük değerle değiştirilir. Bu max-heap özelliğini bozabileceği için o göz için doğrudan `max_heapify` çağrılır ve değer aşağı taşınır.

### 6.5 insert

Yeni eleman son eleman olarak eklenir (ekrandan, 02:20:00):

```c
void insert(int A[], int key) {
  heap_size++;
  A[heap_size] = -1*INF;
  increase_key(A, heap_size, key);
}
```

### 6.6 Sürücü (main) fonksiyonu

`main` içinde bir heap oluşturulur ve süreçler sırayla eklenir: öncelikleri 20, 15, 8, 10, 5, 7, 6, 2, 9, 1 olan süreçler zamanlayıcıda beklemeye başlar. Zamanlayıcının durumu bir `print_heap` fonksiyonuyla yazdırılır. Sonra 5 öncelikli süreç 22 önceliğine çıkarılır ve en üste taşınır. Ardından 1. indisteki elemanın önceliği 13'e indirilir ve eleman ağacın ortalarına bir yere iner. Maksimuma bakılır, bir eleman çekilip hizmet verilir ve kalan durum yine yazdırılır. Birkaç kez `extract_max` yapılarak heap boşaltılabilir ve bir süreç zamanlayıcısının çalışması böylece simüle edilir. Bu sırayla `insert` yapıldığında oluşan heap, 5.2'deki örnek heap'in aynısıdır (python ile doğrulandı).

Hoca bu örnekte yalnız tam sayılar kullanıldığını, gerçek uygulamada heap elemanlarının birer struct olması gerektiğini söyledi. Struct'ın anahtar alanı heap anahtarı olarak kullanılırsa gerçekleme bir anda bir öncelikli kuyruk veri yapısına dönüşür. Böylece işlem ya da hizmet önceliği $O(\log n)$ karmaşıklıkla düzenlenebilir. Uygulamada düşük sayının mı yüksek sayının mı öncelikli olduğuna göre min-heap ya da max-heap seçilir.

**Soru:** Anahtar değerleri benzersiz olmak zorunda mı, aynı önceliğe sahip elemanlar olabilir mi? **Cevap:** Olabilir. Bu durumda gerçekleme önemlidir: `insert` içindeki `increase_key`'de eşitlik görüldüğünde yeni gelenin yukarı mı taşınacağına yoksa aşağıda mı kalacağına probleme göre karar verilmelidir.

## 7. Huffman Ağacı

Hoca öğrencilerin Huffman ağacını ayrık matematikte gördüklerini öğrendi ve bunu öncelikli kuyruğun bir uygulaması olarak ele aldı.

### 7.1 Neden Huffman kodlaması?

Elimizde bir roman gibi karakterlerden oluşan uzun bir metin olsun ve bunu sıkıştırıp karşı tarafa göndermek isteyelim. ASCII'de 256 karakter vardır, ama bir romanda kullanılan farklı karakter sayısı bunun çok altındadır (hoca yüz civarı olduğunu tahmin etti). Doğal dilde karakterlerin kullanım sıklıkları birbirinden farklıdır: sesli harfler çok, Türkçedeki yumuşak g gibi harfler az kullanılır. Hoca dilin entropisinin buradan ortaya çıktığını söyledi, ama bu konuya girmedi.

Fikir şudur: en çok kullanılan karakter olabildiğince kısa, en az kullanılan karakter daha uzun bir kodla gösterilir. Normalde her karakter 8 bittir. Romanın yarısı tek bir harften oluşsaydı ve bu harf 8 bit yerine 2 bitle kodlansaydı o harf için $2/8 = 1/4$ yer, yani %75 tasarruf sağlanırdı. Az kullanılan karakterlerin kodu 8 biti geçebilir, ama geçmemesi tercih edilir. Karakterleri kullanım sıklıklarına göre önceliklendirmek, onları bir öncelikli kuyrukta tutmak demektir. Kodlar ağaçtaki yolun 0 ve 1 ile yazılmasıyla elde edilir. Yöntem kayıpsızdır: veri geri döndürülebilir.

Slayttaki özet (ekrandan, 02:25:00):

- Veriyi kayıpsız sıkıştırma için karakterleri kullanım sıklıklarına göre önceliklendirir; öncelikli kuyruk ile gerçekleştirilebilir.
- En sık kullanılan karaktere en kısa kodu, en az kullanılan karaktere en uzun kodu verirsek sabit kod uzunluğuna göre daha kısa bir çıktı üretebiliriz.
- Denk sıklıktaki karakterler aynı uzunluktaki kodu alacaktır.

Örneğin iki karakter romanda 610 ve 587 kez gibi yakın sıklıklarda geçiyorsa benzer uzunlukta kodlar almalıdır.

### 7.2 Neden min-priority-queue?

İlk akla gelen, çok kullanılanı önce almak için max-priority-queue kullanmaktır. Ama ağaç aşağıdan yukarı kurulacağı için olay tersten ele alınır. En az kullanılan karakterler önce işlenirse ağaçta aşağıda kalır ve uzun kod alır. Sık kullanılanlar yukarıda kalır ve kökten 1-2 adımda erişilir. Bu yüzden min-priority-queue kullanılır ve anahtar değerler karakterlerin frekanslarıdır.

### 7.3 Algoritma

- Metindeki bütün karakterler sayılır ve frekanslarıyla birlikte bir min-priority-queue'ya konur.
- İki kez `extract_min` yapılarak en düşük frekanslı iki düğüm alınır.
- Bunların frekansları toplanır ve bu toplam bir ara düğüme atanır. Ara düğüm artık tek bir karakter değildir; sol ve sağ çocukları bu iki düğümdür.
- Ara düğüm `insert` ile kuyruğa eklenir ve kuyrukta uygun yerine çıkar.
- Kuyrukta tek bir düğüm kalana kadar 2. ve 3. adımlar tekrarlanır. Kalan son düğüm ağacın köküdür.

> **Ders sonrası not:** Hoca algoritmayı anlatırken kalan son düğümün "en yüksek frekansa sahip karakter" olduğunu söyledi. Doğrusu, kalan son düğüm bir karakter değil, Huffman ağacının köküdür ve değeri bütün frekansların toplamıdır (aşağıdaki örnekte 100).

### 7.4 Sayısal örnek

Romanda yalnız 6 karakter olsun (ekrandan, 02:35:00):

| Karakter | Frekans |
|---|---|
| a | 5 |
| b | 9 |
| c | 12 |
| d | 13 |
| e | 16 |
| f | 45 |

Adımlar (her satırda kuyruktan çekilen iki değer ve oluşan ara düğüm):

| Adım | Kuyruk (önce) | Çekilenler | Ara düğüm | Kuyruk (sonra) |
|---|---|---|---|---|
| 1 | 5, 9, 12, 13, 16, 45 | 5 (a), 9 (b) | 14 | 12, 13, 14, 16, 45 |
| 2 | 12, 13, 14, 16, 45 | 12 (c), 13 (d) | 25 | 14, 16, 25, 45 |
| 3 | 14, 16, 25, 45 | 14, 16 (e) | 30 | 25, 30, 45 |
| 4 | 25, 30, 45 | 25, 30 | 55 | 45, 55 |
| 5 | 45, 55 | 45 (f), 55 | 100 | 100 |

Adımlar python `heapq` ile doğrulandı. Yaprak düğümlerin (karakterlerin) sol ve sağ işaretçileri boştur. Ara düğümlerde karakter alanı yoktur; hoca istenirse buraya birleşen karakterlerin (örneğin "ab") yazılabileceğini, bunun önemli olmadığını söyledi.

Oluşan ağaç (sola giden kenar 0, sağa giden kenar 1) (ekrandan, 02:40:00):

```text
              100
           0 /   \ 1
          f:45    55
               0 /  \ 1
               25    30
            0 / \1  0/ \1
          c:12 d:13 14  e:16
                  0 / \ 1
                  a:5  b:9
```

Kod tablosu (ekrandan, 02:45:00):

| Karakter | Kod |
|---|---|
| f | 0 |
| c | 100 |
| d | 101 |
| a | 1100 |
| b | 1101 |
| e | 111 |

Hoca "fbfdc" dizgisini kodladı. Sabit 8 bitlik kodla $5 \times 8 = 40$ bit gerekir. Huffman kodlarıyla:

- f → 0
- b → 1101
- f → 0
- d → 101
- c → 100

Toplam $1 + 4 + 1 + 3 + 3 = 12$ bit eder (python ile doğrulandı). Kazanç $28/40 = 7/10$, yani %70 tasarruftur; sıkıştırılmış veri özgün boyutun %30'u kadardır. Hiçbir kod başka bir kodun başlangıcı olmadığı için bitler bitişik yazılsa da çözülebilir.

**Soru (hocanın kendi sorusu):** Bu ağacı da karşı tarafa göndermek gerekmez mi? **Cevap:** Evet, hangi bit dizisinin hangi karaktere karşılık geldiğini gösteren ağaç ya da kod tablosu da gönderilmelidir. Bu bir ek yüktür (overhead). Bu küçük örnekte oranı belirgin biçimde düşürebilir, ama kilobaytlarca ya da megabaytlarca veride birkaç baytlık ek yük oranı pek değiştirmez.

Hoca, uzun metinlerde sık kullanılan karakterlerden büyük kazanç, bazı seyrek karakterlerden ise küçük kayıplar (8 biti geçen kodlar) olacağını söyledi. Karakterlerden oluşan bir verinin bu yolla kabaca %70'ler mertebesinde sıkıştırılabileceğini belirtti. zip gibi sıkıştırma yöntemlerinin de mantık olarak kullanım sıklıklarını farklı ağaç yapılarıyla gösterme fikrine dayandığını ekledi.

> **Ek bilgi (derste anlatılmadı):** Hiçbir kodun başka bir kodun öneki olmadığı kodlara önek kodu (prefix code) denir. Huffman kodlarında karakterler yalnız yapraklarda bulunduğu için bu özellik kendiliğinden sağlanır. Çözücü, bit dizisini kökten başlayarak okur ve bir yaprağa her ulaştığında bir karakter yazıp köke döner.

## Örnek Sorular

### Soru 1 (vize, test) (derste sözlü, 00:06:41)

<!-- BELİRSİZ: Bu sorunun metni ve şıkların sırası karelerde görünmüyor; altyazıdan kuruldu. -->

Aşağıdaki işlemlerin hangisinde ya da hangilerinde bağlı liste kullanmak, dizi kullanımına göre genel olarak daha avantajlıdır? (İşlemler: ekleme, silme, güncelleme, arama, en küçük/en büyük elemanı bulma.)

**Çözüm (derste verildi):** Ekleme ve silmede bağlı liste avantajlıdır; dizide kaydırma $O(n)$ sürer, bağlı listede yalnız düğüm bağlantıları değişir. Güncellemede doğrudan indis erişimi sayesinde dizi daha hızlıdır. Aramada dizi (özellikle sıralı dizi) daha verimlidir. Min/max bulmada bağlı listenin avantajı yoktur. Cevap: 1,2.

### Soru 2 (vize, test) (ekrandan, 00:15:00)

5, 8, 9, 12, 24, 48, 64 şeklinde verilen bir sıralı diziden İkili Arama Ağacı oluşturulması isteniyor. Bu diziden belirli bir kurala göre oluşturulan ağaç; en iyi durumda dengelidir ve ...... seviyeden oluşur; en kötü durumda dengesizdir ve ...... seviyeden oluşur. Oluşturulan ağacın kökünde ise; en iyi durumda ...... sayısı, en kötü durumda ise ...... sayısı bulunur. Not: Hesaplamalarda kök 0. seviye kabul edilmelidir. (Örnek cevap: 1,3,5,7)

**Çözüm (derste verildi):**

- En kötü durum: elemanlar sırayla eklenir, her biri bir öncekinin sağına gider. Zincir: 5 → 8 → 9 → 12 → 24 → 48 → 64. Seviyeler 0'dan 6'ya; kökte 5.
- En iyi durum: ortadaki eleman köke alınır ve alt dizilerde de hep ortadaki seçilir. Kök 12; solda 8 (çocukları 5 ve 9), sağda 48 (çocukları 24 ve 64). Seviyeler 0, 1, 2; kökte 12.
- Cevap: 2,6,12,5.

### Soru 3 (vize, test) (ekrandan, 00:20:00)

Aşağıdaki her işlem için kullanılabilecek en uygun veri yapısını sıra ile yazınız. a. Bir derleyicinin fonksiyonlara gidip dönme işlemlerini düzenlemek için; b. Bir klavyede basılan tuşları ekrana yazarken; c. Dengeli olmayan bir ikili ağacı saklamak için; d. Satranç oyununda bir sonraki hamleyi belirlemek için.

**Çözüm (derste verildi):** Yığın (Stack), Kuyruk (Queue), Linkli Liste (Linked List), Ağaç (Tree).

### Soru 4 (vize, test) (ekrandan, 00:25:00)

Aşağıdaki program parçası çalıştırıldığı anda kuyrukta 1 2 3 4 sayıları bulunmaktadır (1 kuyruğun başında, 4 en sonundadır). Stack boştur. Program parçasının çalışması bittiğinde kuyrukta bulunan elemanları kuyruk başından itibaren sıra ile yazınız.

```c
.......
   while( !isQueueEmpty(queue))
   {
value = enqueueQueue(queue);
pushStack(value,stack);
}
while(!isStackEmpty(stack))
{
value = popStack(stack);
enqueueQueue(value,queue));
}
.....
```

**Çözüm (derste verildi):** İlk döngüdeki `enqueueQueue(queue)` bir yazım hatasıdır, `dequeue` olmalıydı (fonksiyon kuyruğu alıp bir değer döndürüyor). İlk döngüde 1, 2, 3, 4 sırayla dequeue edilip yığıta push edilir; yığıtın tepesinde 4 vardır. İkinci döngüde 4, 3, 2, 1 sırasıyla pop edilip kuyruğa eklenir. Cevap: 4 3 2 1 (kuyruk ters çevrilir).

### Soru 5 (vize, test) (ekrandan, 00:30:00)

Bir ikili arama ağacında 5 sayısı aranırken ağaçta bulunan elemanlara hangi sıra ile bakılamaz? a. 10, 9, 8, 7, 6, 5; b. 1, 10, 2, 9, 3, 5; c. 2, 7, 3, 8, 4, 5; d. 1, 2, 10, 4, 8, 5; e. Hepsi doğru.

**Çözüm (derste verildi):**

- a: 10'dan sola, 9'dan sola, ... 6'dan sola; 5 bulunur. Geçerli.
- b: 1'den sağa, 10'dan sola, 2'den sağa, 9'dan sola, 3'ten sağa; 5 bulunur. Geçerli.
- c: 2'den sağa, 7'den sola; bundan sonra değerler 2 ile 7 arasında olmalı. 3'ten sağa gidildikten sonra 8 gelemez (8, 7'nin sağında durmak zorundadır). Geçersiz.
- d: 1'den sağa, 2'den sağa, 10'dan sola, 4'ten sağa, 8'den sola; 5 bulunur. Geçerli.
- Cevap: c. Dört dizinin geçerliliği python ile aralık kontrolüyle doğrulandı.

### Soru 6 (vize, test) (ekrandan, 00:35:00)

En küçük elemanın kökte yer aldığı N elemanlı bir heap ağacında en küçük 3 elemanı silmenin karmaşıklığı en kötü durumda ne olur? Big-Oh notasyonu ile gösteriniz.

**Çözüm (derste verildi):** Her extract-min: kökü al, son elemanı köke koy ($O(1)$), heapify ile aşağı taşı ($O(\log n)$). Üç kez: $3\log n$. Big-O'da $O(\log N)$.

### Soru 7 (vize, test) (derste sözlü, 00:35:34)

<!-- BELİRSİZ: Bu sorunun metni karelerde görünmüyor; altyazıdan kuruldu. Şıklar altyazıda "1, 3, 4, 6, 7" olarak geçiyor. -->

Bir ifadedeki parantezlerin dengeli olup olmadığı yığıtla kontrol ediliyor. Rastgele sırada 4 açılış ve 5 kapanış parantezi verildiğinde, herhangi bir anda yığıtta en fazla kaç parantez bulunabilir?

**Çözüm (derste verildi):** Yığıta yalnız açılış parantezleri push edilir. En kötü durumda 4 açılış parantezi arka arkaya gelir ve aralarına kapanış girmez. Cevap: 4.

### Soru 8 (vize, test) (ekrandan, 00:40:00)

Verilen C kodunun (en kötü durumda) çalışma zamanı karmaşıklığını Big-Oh notasyonunda ifade ediniz.

```c
int fonksiyon(int n) {
   int i, j, k = 0;
   for (i = n/2; i <= n; i++) {
      for (j = 2; j <= n; j*=2) {
         k += n/2;
      }
   }
   return k;
}
```

**Çözüm (derste verildi):** Dış döngü yaklaşık $n/2$ kez, iç döngü yaklaşık $\log n$ kez döner; içerisi sabit işlemdir. Toplam $\frac{n}{2}\log n$, yani $O(n\log n)$. (Python ile sayım: iç gövde $(n/2+1)\lfloor\log_2 n\rfloor$ kez çalışır.)

### Soru 9 (vize, test) (ekrandan, 00:45:00)

Elimizde üçlü (ternary) min-heap veri yapısı bulunmaktadır (her ebeveyn düğümünün kendinden büyük değere sahip 3 alt düğümü olan tam (complete) üçlü ağaç). Aşağıda verilen min-ternary-heap'te en küçük eleman silindiğinde heap dizisinin son hali ne olur? Değerleri aralarında birer boşluk bırakarak giriniz.

Verilen heap (hocanın tahtaya çizdiği biçim):

```text
                 3
        /        |        \
      13         4         91
    /  |  \    /  |  \
  49  29  98  32  30  15
```

**Çözüm (derste verildi):**

- Kök 3 çıkarılır, son eleman 15 köke yazılır.
- 15'in çocukları 13, 4, 91; en küçüğü 4. 4 yukarı çıkar, 15 onun yerine iner.
- 15'in yeni çocukları 32 ve 30; 15 ikisinden de küçük, durur.
- Cevap: 4 13 15 91 49 29 98 32 30 (python ile doğrulandı).

### Soru 10 (vize, test) (ekrandan, 00:50:00)

En soldaki sütun orijinal veri dizisidir. I, II, III sütunları ise 3 farklı sıralama algoritmasının herhangi bir adımında oluşan dizilerdir. Buna göre I, II, III sütunlarındaki veriler hangi sıralama algoritması kullanılarak sıralanmaktadır? (Şıklarda insertion, selection ve heap sort'un kombinasyonları vardı.)

| Orijinal | I | II | III |
|---|---|---|---|
| that | from | your | been |
| with | have | with | from |
| have | know | will | good |
| this | that | this | have |
| that | that | they | know |
| will | that | want | that |
| will | they | will | that |
| your | this | that | that |
| from | will | from | that |
| they | will | that | they |
| know | with | know | this |
| that | your | that | want |
| want | want | have | will |
| been | been | been | your |
| that | that | that | with |
| good | good | good | will |

**Çözüm (derste verildi):**

- III: en başta alfabetik olarak en küçük eleman (been) ve ardından sırayla en küçükler var; her iterasyonda kalanların en küçüğü sıradaki göze konmuş. Selection sort.
- II: kökte your, çocukları with ve will; dizi büyükten küçüğe bir max-heap düzeninde. Insertion sort böyle ters bir düzen oluşturamaz. Heap sort.
- I: ilk 12 eleman (from ... your) kendi içinde sıralı, ama en küçük eleman (been) henüz başta değil; son dört eleman (want, been, that, good) henüz yerine kaydırılmamış. Insertion sort.
- Cevap: I insertion sort, II heap sort, III selection sort. Python ile kontrol: I, orijinal dizinin ilk 12 elemanının sıralanmış hali ile kalan 4 elemanın birleşimidir; II'nin tamamı max-heap özelliğini sağlar; III'ün ilk 13 elemanı genel sıralamanın ilk 13 elemanıdır.

### Soru 11 (vize, algoritma sorusu) (ekrandan, 00:55:00)

Bir matris üzerinde tutulan bilgilerin yarısından fazlası "0" ise bu matris "sparse matris" olarak adlandırılır. Bu tür matrislerin bilgileri, kullanılan bellek miktarını azaltmak için linkli liste yapısı kullanılarak saklanır. 0'dan farklı olan matris hücrelerinin satır, sütun ve değer bilgisi, linkli liste elemanlarında tutulur. Linkli liste yapısında verilen NxM'lik bir sparse matris bilgilerini kullanarak hangi sütunlarının tamamen "0"lardan oluştuğunu bulan programı C dilinde kodlayınız. (Önemli: Matris bilgisinden linkli liste dönüşümü kodunu yazmayınız. Bilgiler linkli liste formatında okunmalıdır.) Örnek: Aşağıda açık hali verilen matrisin linkli listeye dönüştürülmüş hali girdi olarak verildiğinde programınızın 0,3,4 çıktısını üretmesi beklenmektedir.

```text
0300001
0020004
0100002
0000000
0000000
0000050
```

**Çözüm (derste verilen yol, ekrandan, 01:00:00):** 7 elemanlı bir işaret dizisi açılır, her göz 1 yapılır. Liste düğümleri (0,1,3), (0,6,1), (1,2,2), (1,6,4), (2,1,1), (2,6,2), (5,5,5) sırayla gezilir; her düğümün sütun gözü 0 yapılır. Sonda 1 kalan gözler 0, 3 ve 4'tür.

> **Çözüm (derste verilmedi):** Derste kod yazılmadı. Aşağıdaki program ajan tarafından yazıldı, `gcc -Wall` ile uyarısız derlendi ve örnek girdiyle `0,3,4` çıktısını verdi.

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int row, col, value;
    struct Node *next;
} Node;

Node *push_back(Node *head, int r, int c, int v) {
    Node *n = malloc(sizeof(Node));
    n->row = r; n->col = c; n->value = v; n->next = NULL;
    if (head == NULL) return n;
    Node *p = head;
    while (p->next != NULL) p = p->next;
    p->next = n;
    return head;
}

void zero_columns(Node *head, int m) {
    int *empty = malloc(m * sizeof(int));
    for (int j = 0; j < m; j++) empty[j] = 1;      /* başta hepsi "tamamen sıfır" */
    for (Node *p = head; p != NULL; p = p->next)
        empty[p->col] = 0;                          /* dolu hücrenin sütunu elenir */
    int first = 1;
    for (int j = 0; j < m; j++)
        if (empty[j]) { printf(first ? "%d" : ",%d", j); first = 0; }
    printf("\n");
    free(empty);
}

int main(void) {
    /* Örnek matrisin linkli liste hali: (satır, sütun, değer) */
    Node *head = NULL;
    head = push_back(head, 0, 1, 3);
    head = push_back(head, 0, 6, 1);
    head = push_back(head, 1, 2, 2);
    head = push_back(head, 1, 6, 4);
    head = push_back(head, 2, 1, 1);
    head = push_back(head, 2, 6, 2);
    head = push_back(head, 5, 5, 5);
    zero_columns(head, 7);
    while (head) { Node *t = head; head = head->next; free(t); }
    return 0;
}
```

### Soru 12 (vize, algoritma sorusu) (ekrandan, 01:05:00)

Bir ağ üzerinde bulunan bilgisayarlara hizmet veren bir yazıcıya gelen yazdırılacak dosyalar ve her dosyanın sayfa sayısı bir kuyrukta tutulmaktadır.

- 1. Her sayfanın bir döngü adımı süresinde basıldığını varsayarak, bir iş bittiğinde kuyruktaki sıradaki işe hizmet veren fonksiyonu yazınız. (Örneğin kuyruk başındaki işin sayfa sayısı 4 ise, döngüde 4 defa dönüldüğünde basılma işlemi tamamlanmış olur.)
- 2. Bir kullanıcının kuyrukta bekleyen yazma isteğini bekleyen diğer isteklerin sırasını bozmadan silebilmesini sağlayan, eğer silinmesi istenen dosya kuyrukta bulunmuyorsa uyarı veren fonksiyonu yazınız. (Bu işlem için 2. bir kuyruktan faydalanabilirsiniz.)
- 3. Bu fonksiyonları kullanarak yazma isteklerini alan, yazılmasını sağlayan ve silme isteklerini yerine getiren ana programı C dilinde yazınız.

Not 1: Kuyruk üzerinde işlem yapılırken sadece enqueue ve dequeue fonksiyonları kullanılarak kuyruğun başındaki elemana erişilebilir. Ara elemanlar üzerinde işlem yapılamaz. Not 2: Kuyruğa eleman ekleme (enQueue), kuyruktan eleman silme (deQueue) ve kuyrukta eleman olup olmadığı kontrolü (isEmpty) işlemlerine ait fonksiyonları yazmayınız, hazır olduğunu varsayarak kullanınız. Not 3: Kolaylık açısından kuyrukta bulunan yazılacak dosyaların birbirinin aynı olmayan sayılar ile gösterildiğini varsayınız.

Örnek:

| Dosya No | 11 | 26 | 43 | 75 |
|---|---|---|---|---|
| Sayfa Sayısı | 5 | 1 | 7 | 2 |

Kuyruk başı 11 no'lu dosya 5 döngü adımında basılır. Bu durumda iken örneğin 43 no'lu dosyanın silinmesi istenirse kuyruğun yeni hali aşağıdaki gibi olur:

| Dosya No | 11 | 26 | 75 |
|---|---|---|---|
| Sayfa Sayısı | 5 | 1 | 2 |

**Çözüm (derste verilen yol, ekrandan, 01:15:00):** 11 ve 26 dequeue edilip yedek kuyruğa enqueue edilir. 43 dequeue edilir ve hiçbir yere eklenmez. 75 de yedek kuyruğa aktarılır. Yedek kuyruk 11, 26, 75 olur. Sonra ya yedek kuyruktaki işler aynı şekilde ana kuyruğa geri aktarılır ya da yedek kuyruk yeni ana kuyruk olarak kullanılır. Üçüncü yol, eleman sayısı bilindiği için aynı kuyrukta dairesel bir tur dönmektir. Ayrıntılar 2.2'de.

> **Çözüm (derste verilmedi):** Derste kod yazılmadı. Aşağıdaki program ajan tarafından yazıldı. Soruda hazır kabul edilen `enQueue`, `deQueue` ve `isEmpty` yalnız test için dairesel dizi ile yazıldı. Program `gcc -Wall` ile uyarısız derlendi. Çalıştırıldığında 43 silindikten sonra kuyruk (11,5) (26,1) (75,2) oldu, olmayan bir dosya için uyarı verildi ve 11 numaralı dosyanın 5 sayfası basıldı.

```c
#include <stdio.h>

#define CAP 100
typedef struct { int id[CAP], pages[CAP]; int front, rear, count; } Queue;

/* Soruda hazır kabul edilen işlemler (test için yazıldı) */
void init(Queue *q) { q->front = 0; q->rear = -1; q->count = 0; }
int isEmpty(Queue *q) { return q->count == 0; }
void enQueue(Queue *q, int id, int pages) {
    q->rear = (q->rear + 1) % CAP; q->id[q->rear] = id; q->pages[q->rear] = pages; q->count++;
}
void deQueue(Queue *q, int *id, int *pages) {
    *id = q->id[q->front]; *pages = q->pages[q->front];
    q->front = (q->front + 1) % CAP; q->count--;
}

/* 1. Kuyruk başındaki işi bas: sayfa sayısı kadar döngü adımı */
void printNext(Queue *q) {
    int id, pages;
    if (isEmpty(q)) { printf("Kuyruk bos\n"); return; }
    deQueue(q, &id, &pages);
    for (int i = 1; i <= pages; i++)
        printf("Dosya %d: sayfa %d basildi\n", id, i);
}

/* 2. Sırayı bozmadan aradan silme: yedek kuyrukla boşalt-doldur */
void cancelPrint(Queue *q, int target) {
    Queue tmp; int id, pages, found = 0;
    init(&tmp);
    while (!isEmpty(q)) {
        deQueue(q, &id, &pages);
        if (id == target) found = 1;          /* silinecek iş yedeğe aktarılmaz */
        else enQueue(&tmp, id, pages);
    }
    while (!isEmpty(&tmp)) {                  /* yedekten ana kuyruğa geri doldur */
        deQueue(&tmp, &id, &pages);
        enQueue(q, id, pages);
    }
    if (!found) printf("Uyari: %d numarali dosya kuyrukta yok\n", target);
}

void show(Queue *q) {
    for (int k = 0, i = q->front; k < q->count; k++, i = (i + 1) % CAP)
        printf("(%d,%d) ", q->id[i], q->pages[i]);
    printf("\n");
}

int main(void) {
    Queue q; init(&q);
    enQueue(&q, 11, 5); enQueue(&q, 26, 1); enQueue(&q, 43, 7); enQueue(&q, 75, 2);
    cancelPrint(&q, 43); show(&q);
    cancelPrint(&q, 99);
    printNext(&q); show(&q);
    return 0;
}
```

### Soru 13 (derste örnek, Huffman) (ekrandan, 02:40:00)

Frekansları a:5, b:9, c:12, d:13, e:16, f:45 olan karakterler için Huffman ağacını kurunuz ve "fbfdc" dizgisini kodlayınız. Sabit 8 bitlik kodlamaya göre kazanç nedir?

**Çözüm (derste verildi):** Ağaç ve kodlar 7.4'teki gibidir: f=0, c=100, d=101, a=1100, b=1101, e=111. "fbfdc" → 0 1101 0 101 100 = 12 bit; sabit kodla 40 bit. Kazanç $28/40$, yani %70 (python ile doğrulandı).

## Dersin Toparlaması

Dersin ilk bölümünde vize soruları üzerinden bağlı liste ile dizinin karşılaştırması, ekleme sırasının ikili arama ağacının yüksekliğine etkisi, yığıt ve kuyruğun tipik kullanım alanları, ikili arama ağacında geçerli arama yolları, heap işlemlerinin karmaşıklığı, üçlü heap ve ara adımdan sıralama algoritmasını tanıma tekrar edildi. İki algoritma sorusunda seyrek matrisin bağlı listeyle tek geçişte işlenmesi ve bir kuyruğun ortasından yalnız kuyruk işlemleriyle (yedek kuyruk ya da dairesel dolaşma) eleman silinmesi anlatıldı.

İkinci bölümde öncelikli kuyruğun aslında bir heap olduğu görüldü. Max-priority-queue işlemleri (`max`, `extract_max`, `increase_key`, `insert`) heap işlemlerinin birebir karşılığıdır ve hepsi `max_heapify` etrafında döner; `max` dışındakiler $O(\log n)$'dir. İşletim sistemi zamanlayıcısı, olay güdümlü simülatör ve banka sırası örnekleri bu yapının nerede kullanıldığını gösterdi. Son olarak min-priority-queue'nun bir uygulaması olarak Huffman ağacıyla kayıpsız veri sıkıştırma işlendi. Hoca sonraki konuların çizgeler, minimum yayılan ağaç, böl ve yönet algoritmaları, string arama ve sıralama algoritmaları olacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
