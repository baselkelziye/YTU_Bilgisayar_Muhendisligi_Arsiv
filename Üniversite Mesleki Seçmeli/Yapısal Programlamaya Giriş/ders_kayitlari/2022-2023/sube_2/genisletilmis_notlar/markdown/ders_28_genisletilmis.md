# Ders 28 Genişletilmiş Notu: Matris Çarpımı ve Çarpım Sırası, Dış Birleştirmeli Sıralama, P ve NP Problemler, Gezgin Satıcı Problemi ve Sezgisel Çözümler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Vektör çarpımı ve matris çarpımı
- 2. Matris çarpımının kullanım alanları
- 3. Matris çarpımını hızlandırma: böl-yönet ve paralelleştirme
- 4. Matris zinciri çarpımında sıranın önemi
- 5. Bellek hiyerarşisi ve donanım hızları
- 6. Dış birleştirmeli sıralama (External Merge Sort)
- 7. Disk hızı, SSD ve darboğaz; ara sorular
- 8. Problem türleri: P ve NP
- 9. Alt küme toplamı problemi
- 10. Gezgin satıcı problemi (TSP)
- 11. Zaman, bellek, doğruluk ve yaklaşık çözüm
- 12. En yakın komşu sezgiseli
- 13. Karınca kolonisi ve genetik algoritma örneği
- 14. Neden bu problemler doğrudan kodlanamıyor?
- 15. Önerilen kaynaklar ve dersin genel değerlendirmesi
- Örnek Sorular
- Dersin Toparlaması

## 1. Vektör çarpımı ve matris çarpımı

Dönemin son dersi, çok kod yazmaktan çok, dersin kazandırdıklarını ve sonraki derslere açılan konuları tartışmaya ayrıldı. İlk konu matris çarpımıdır.

### 1.1 İki vektörün çarpımı

Matris çarpımından önce iki vektörün çarpımı ele alındı. $N$ elemanlı bir $A$ vektörü ile $N$ elemanlı bir $B$ vektörünün çarpımı, karşılıklı elemanların çarpılıp bu çarpımların toplanmasıdır (ekrandan, 00:20:00):

$$A \cdot B = \sum_{i=1}^{N} A_i \, B_i$$

Bunun için iki vektörün de aynı uzunlukta olması zorunludur. Bu işleme skaler çarpım da denir.

### 1.2 Matris çarpımının kuralı

Matris çarpımı, vektör çarpımının genelleştirilmiş hâlidir. Hoca önce $A \times B$ ile $B \times C$ boyutlu iki matrisle anlattı, sonra harfleri $n \times m$ ve $m \times p$ olarak değiştirdi (ekrandan, 00:20:00). $n \times m$ boyutlu $A$ matrisi ile $m \times p$ boyutlu $B$ matrisi çarpılabilir; ortadaki iki boyutun eşit olması gerekir. Bunun nedeni, $A$'nın bir satırı ile $B$'nin bir sütununun vektör çarpımının alınmasıdır: $A$'nın satır uzunluğu $m$, $B$'nin sütun uzunluğu da $m$ olmalıdır. Sonuç olan $C$ matrisi $n \times p$ boyutludur.

$A$'nın birinci satırı ile $B$'nin birinci sütunu çarpılınca $C$'nin $(1,1)$ elemanı, aynı satır ile ikinci sütun çarpılınca $(1,2)$ elemanı bulunur ve bu böyle sürer.

### 1.3 Sözde kod

Hoca algoritmayı tahtada sözde kodla yazdı (ekrandan, 00:20:00):

```text
for (i = 1 ; n)
    for (j = 1 ; p)
        sum = 0;
        for (k = 1 ; m)
            sum += A[i][k] * B[k][j]
        end for
        C[i][j] = sum;
```

Kodun kurulma mantığı şöyle anlatıldı. Birinci satırı ve birinci sütunu gezip tek bir sayısal sonuç elde etmek için bir döngü gerekir; ama bütün satırları ve sütunları doldurmak için iki döngü daha gerekir. Böylece üç döngü ortaya çıkar:

- Dış döngü $i$, $A$'nın $n$ satırını gezer.
- Orta döngü $j$, $B$'nin $p$ sütununu gezer.
- İç döngü $k$, 1'den $m$'ye kadar gider; çünkü her satır ile sütun $m$ eleman üzerinden çarpılır.

İç döngüde $i$. satır sabit kalır ve $k$ sağa doğru ilerler; $B$'de $j$. sütun sabit kalır ve $k$ aşağı doğru iner. Hoca "$A$'nın $i$'sinin $k$'sı ile $B$'nin $k$'sının neyini çarpacağız?" diye sordu; bir öğrenci "$j$'sini" diye cevap verdi.

Çarpımlar `sum` adlı bir değişkende birikir (`sum +=`). Her yeni $(i,j)$ elemanına geçerken `sum` sıfırlanmalıdır; aksi hâlde bir önceki elemanın toplamı yenisine eklenir. İç döngü bittiğinde biriken değer `C[i][j]`'ye yazılır.

Aşağıdaki C kodu derste yazılmadı; tahtadaki sözde kodun 0 tabanlı indisli C karşılığıdır. Ajan tarafından `gcc -Wall` ile derlendi ve $2 \times 3$ ile $3 \times 2$ boyutlu matrislerle çalıştırıldı; çıktı `58 64` ve `139 154` oldu.

```c
#include <stdio.h>
#define N 2
#define M 3
#define P 2
int main(void){
    int A[N][M]={{1,2,3},{4,5,6}};
    int B[M][P]={{7,8},{9,10},{11,12}};
    int C[N][P];
    int i,j,k,sum;
    for(i=0;i<N;i++){
        for(j=0;j<P;j++){
            sum=0;
            for(k=0;k<M;k++)
                sum+=A[i][k]*B[k][j];
            C[i][j]=sum;
        }
    }
    for(i=0;i<N;i++){
        for(j=0;j<P;j++) printf("%d ",C[i][j]);
        printf("\n");
    }
    return 0;
}
```

### 1.4 Zaman karmaşıklığı

Hoca kodun zaman karmaşıklığını sordu. Öğrenciler "$n^3$" dedi. Hoca bunun hangi varsayımla söylendiğini sordu: matrisler $n \times m$ ve $m \times p$ olduğu için karmaşıklık üç değişkene bağlıdır. Dış döngü $n$, orta döngü $p$, iç döngü $m$ kez döner. Temel işlem olan çarpma $n \cdot p \cdot m$ kez yapılır:

$$T(n, m, p) = n \cdot m \cdot p$$

Kare matrislerde $n = m = p$ olduğundan bu $n^3$'e, yani $O(n^3)$'e eşittir. Öğrenciler kare matrisi düşündükleri için $n^3$ demişlerdi; hoca bunun doğru olduğunu, ama genel hâlin üç boyuta bağlı olduğunu belirtti.

## 2. Matris çarpımının kullanım alanları

Hoca, matris çarpımının bilgisayar biliminin birçok alt alanının temel işlemi olduğunu anlattı (ekrandan, 00:20:00): bilgisayar grafiği, sanal ve artırılmış gerçeklik, oyun programlama, robotik, yapay zekâ ve özellikle derin öğrenme. Derin öğrenmede veriler matris biçiminde alınır ve bir optimizasyonla bilgisayara öğretim yapılır.

### 2.1 Robotik manipülatör

Hoca "manipülatör nedir?" diye sordu. Bir öğrenci "yönlendirici" dedi; hoca yönlendiricinin router olduğunu söyledi ve internette bir görsel açtı. Başka bir öğrenci görselin bir robot kola benzediğini söyledi; doğru cevap buydu.

Robotik manipülatör, insan kolu gibi eklemlerden oluşan bir robot koldur. Omuzdan bir dönme hareketi yaptığınızda dirsek, bilek ve parmak uçlarına kadar her eklemin konumu değişir. Robota "şu parçayı al" komutu verildiğinde uç kısmın konum değiştirmesi gerekir. Bir eklemdeki dönmenin (rotasyon) ve ötelemenin (transformasyon) uçta ne kadar değişim yaratacağı, eklem sayısı kadar $4 \times 4$ matrisin art arda çarpılmasıyla hesaplanır. Örneğin uçta 5 cm'lik bir hareket istendiğinde bunun her eklemde neye karşılık geleceği bu çarpımlarla bulunur. Bu konuya robot kinematiği denir ve robotik derslerinde ayrıntılı işlenir.

## 3. Matris çarpımını hızlandırma: böl-yönet ve paralelleştirme

### 3.1 Böl ve yönet

Klasik algoritma $n^3$'tür; ama ilerideki algoritma analizi dersinde görülecek daha iyi algoritmalar vardır. Hoca bunlardan birinin adını Strassen olarak yazdı. Bu yöntemler böl ve yönet (divide and conquer) stratejisine dayanır: büyük problem küçük alt parçalara bölünür, her parça kolayca çözülür ve çözümler birleştirilir.

Hoca bunu dönem içinde işlenen $x^n$ hesabına bağladı. $x^n$ normalde $n$ çarpmayla hesaplanır; ama önce $x^{n/2}$, ondan önce $x^{n/4}$ hesaplanarak işlem sayısı $\log_2 n$'e indirilmişti. Matris çarpımında da matris küçük parçalara bölünerek üs 3'ün altına indirilir.

> **Hocanın vurgusu:** $n^3$'ten $n^{2.x}$'e inmek bile çok iyi bir kazançtır. Bazı durumlarda süre çok önemlidir; örneğin oyun oynarken oyunun takılmasını istemezsiniz.

> **Ders sonrası not:** Hoca bu algoritmaların karmaşıklığını "yaklaşık $n^{2.6}$" diye andı. Strassen algoritmasının karmaşıklığı $n^{\log_2 7} \approx n^{2.81}$'dir; daha sonra geliştirilen algoritmalar üssü yaklaşık 2.37'ye kadar indirmiştir.

Hoca ayrıca programlama dillerinin ve kütüphanelerin matris çarpımını hazır sunduğunu, bu hazır fonksiyonların arka planda paralelleştirme ve ölçekleme yaptığını, dolayısıyla uygulamada üç döngüyü elle yazmanın gerekmediğini söyledi.

### 3.2 Paralelleştirme

Günümüz işlemcilerinde birden çok çekirdek (core), çekirdeklerin içinde de iş parçacıkları (thread) vardır; işlemci aynı anda birden çok komut yürütebilir. Matris çarpımında satır-sütun çarpımları birbirinden bağımsızdır. Hoca vektörleri 1, 2, 3, 4 diye numaralandırıp "1 ile 2'yi çarparken aynı anda 1 ile 3'ü çarpsam sonuca bir zararı olur mu?" diye sordu. Öğrenciler zarar olmayacağını söyledi. İşlemci müsaitse 1 ile 4 de aynı anda çarpılabilir. Buna ölçeklenebilirlik (scalability) denir; MATLAB, Python ve C'de paralel kod yazılabilir.

Hoca bir hesap örneği verdi: $n = 1000$ için $n^3$'lük kod tek işlemcide ölçülmüş olarak 1 dakika sürsün. İki işlemciyle ideal durumda bu süre 30 saniyeye, üç işlemciyle 20 saniyeye iner.

> **Hocanın vurgusu:** Bu hesap karmaşıklık üzerinden değil, ölçülmüş süre üzerinden yapıldı. Paralelleştirme karmaşıklığı değiştirmez, yine $n^3$'lük iş yapılır; değişen, işin süresidir.

## 4. Matris zinciri çarpımında sıranın önemi

Robot kolunda her eklem arasında bir matris olduğunu düşünelim: $A \cdot B \cdot C \cdot D$. Bu çarpım farklı sıralarla hesaplanabilir (ekrandan, 00:35:00):

$$A \cdot B \cdot C \cdot D = (A B)(C D) = A (B C) D = A B (C D)$$

Matrislerin birbiriyle çarpılabilir olduğu kabul edilir; robotikte genelde $4 \times 4$ kare matrisler kullanıldığı için bu sorun olmaz. Sonuç her sırada aynıdır, ama yapılan işlem sayısı değişebilir. Kaç farklı sıra olduğunu bulmak kombinatoryal bir problemdir.

### 4.1 Sayısal örnek

Ders notlarındaki örnek (ekrandan, 00:35:00): $A: 10 \times 30$, $B: 30 \times 5$, $C: 5 \times 60$. Sıra bozulamaz, yani $A$ ile $C$ önce çarpılamaz. Yalnız iki ihtimal vardır: ya önce $A$ ile $B$, ya da önce $B$ ile $C$ çarpılır.

Birinci yol, $(AB)C$:

- $A \cdot B$: $10 \cdot 30 \cdot 5 = 1500$ çarpma. Sonuç $10 \times 5$ boyutludur.
- $(AB) \cdot C$: $10 \cdot 5 \cdot 60 = 3000$ çarpma.
- Toplam: $1500 + 3000 = 4500$ çarpma.

İkinci yol, $A(BC)$:

- $B \cdot C$: $30 \cdot 5 \cdot 60 = 9000$ çarpma. Sonuç $30 \times 60$ boyutludur.
- $A \cdot (BC)$: $10 \cdot 30 \cdot 60 = 18000$ çarpma.
- Toplam: $9000 + 18000 = 27000$ çarpma.

Birinci yol toplam karmaşıklık bakımından çok daha iyidir. Bu karar, çarpma yapılmadan önce yalnız boyutlara bakılarak verilen bir ön işlemdir. Ön işlemin maliyeti birkaç çarpmadır, yani çok küçüktür. İki yolda da algoritma yine $n^3$'lük çalışır; ama 4500 üzerinden yapılan iş ile 27000 üzerinden yapılan iş arasında büyük fark vardır.

Dört matris olduğunda daha çok sıra vardır: önce $AB$, $BC$ ya da $CD$ çarpılıp sonuç komşusuyla çarpılabilir, ya da $AB$ ve $CD$ ayrı ayrı çarpılıp sonuçlar birleştirilebilir. Bütün olası durumları sayıp maliyetlerini çıkaran algoritmalar vardır.

**Soru:** İşlem sayısının daha az ya da çok olması neye göre belirleniyor? Örneğin ilk işlemde boyutlar birbirine yakınsa daha mı az işlem çıkar?

**Cevap:** Böyle bir genelleme yapılamaz. Matris çarpımında temel işlem en içteki çarpmadır ve sayısı boyutların çarpımı kadardır. Boyutların birbirine yakınlığı ya da uzaklığıyla ilgili bir kural olup olmadığı ayrıca matematiksel olarak araştırılmalıdır. Yapılacak şey, olası sıraların maliyetlerini hesaplayıp en ucuzunu seçmektir.

**Soru:** Tahtadaki çarpımlardan birinde boyut yanlış yazılmış olabilir mi?

**Cevap:** Hoca hesapları tek tek tekrar kontrol etti: $B \cdot C$ için $30 \cdot 5 \cdot 60 = 9000$ ve sonuç $30 \times 60$; $A \cdot B$ için sonuç $10 \times 5$ ve ardından $10 \cdot 5 \cdot 60 = 3000$. Bir hata yoktu.

## 5. Bellek hiyerarşisi ve donanım hızları

Hoca zaman karmaşıklığından sonra bellek konusuna geçti ve dış sıralamaya zemin hazırlamak için bilgisayarın bellek yapısını tahtaya çizdi (ekrandan, 00:55:00).

### 5.1 CPU, RAM ve yollar

Bütün işlemler işlemcide (CPU) yapılır. İşlemci çalıştıracağı kodları ve işleyeceği verileri RAM'den alır. CPU ile RAM arasında üç yol (bus) vardır: adres yolu (address bus), veri yolu (data bus) ve kontrol yolu (control bus). Örneğin iki sayıyı toplayan bir program yazdığınızda programın satırları teker teker işlemciye gelir, gerekiyorsa veriler de gelir, işlenir ve sonuçlar RAM'e geri yazılır. Bu konular bilgisayar organizasyonu ve işletim sistemleri derslerinde ayrıntılı işlenir.

RAM'in miktarı sınırlıdır; kişisel bilgisayarlarda 8 GB ile 32 GB arası yaygındır. RAM uçucudur (volatile): elektrik kesilince içindeki her şey silinir. Kalıcı saklama için HDD ya da SSD kullanılır; bunların kapasitesi 1 TB ile 10 TB düzeyindedir. Gerektiğinde veri diskten RAM'e getirilir. Ama disk RAM'e göre çok yavaştır; işlemcinin doğrudan disk üzerinde çalışması işi çok yavaşlatır. Bu fark, bileşenlerin fiziksel hız kabiliyetinden kaynaklanır.

### 5.2 Register ve önbellek

**Soru:** CPU'ya RAM eklesek daha hızlı olur mu?

**Cevap:** CPU'ya RAM eklenmez. CPU'nun içinde yalnız register'lar vardır ve bunlar birkaç baytlık veri tutar. RAM'i büyütmek ayrı bir şeydir (örneğin 32 GB'tan 64 GB'a çıkmak). CPU genişletilirse CPU olmaktan çıkar.

**Soru:** CPU'daki ön bellek nedir?

**Cevap:** CPU içinde L1 önbellek (cache), CPU ile RAM arasında L2 ve L3 önbellek bulunur. Önbellek RAM'den hızlı, register'lardan yavaştır. Sürekli RAM'e gidip gelmek yavaş olduğu için arada önbellek kullanılır. Ama kapasitesi küçüktür (tahtada 64 MB örneği). Hoca, birazdan anlatılacak problemde RAM bile yetmediği için önbelleğin hiç çözüm olmadığını söyledi.

### 5.3 Hız karşılaştırması

Hoca hızları frekans üzerinden karşılaştırdı (ekrandan, 01:00:00):

- İşlemci: 1 GHz bir işlemci saniyede yaklaşık $10^9$ komut işleyebilir. Günümüz işlemcileri daha da hızlıdır.
- RAM: derste örnek olarak 10 MHz alındı, yani $10 \cdot 10^6 = 10^7$.
- İşlemci ile RAM arasındaki oran: $10^9 / 10^7 = 10^2$. Bir öğrenci bunu doğru cevapladı; fark 2 kat değil, 100 kattır.
- Disk: 7200 rpm (revolutions per minute) bir disk dakikada 7200 tur atar. Saniyeye çevrilince $7200 / 60 = 120$ Hz $\approx 10^2$ elde edilir.
- İşlemci ile disk arasındaki oran: $10^9 / 10^2 = 10^7$, yani on milyon kat.

Hoca bunu günlük bir gözlemle bağladı: bir diziyi sıralayıp ekrana yazdırırken ekranda uzun uzun yazı akar, ama işlemci sıralamayı çoktan bitirmiştir; yavaş olan, verinin RAM'den ekran kartına ve ekrana gitmesidir.

> **Ders sonrası not:** Derste RAM için örnek alınan 10 MHz bugünkü bellekler için düşüktür; DDR4/DDR5 bellekler birkaç bin MT/s hızında çalışır (bir öğrenci de derste 3600-4500 değerlerini hatırlattı). Buradaki oranlar yalnız büyüklük mertebesini göstermek içindir.

## 6. Dış birleştirmeli sıralama (External Merge Sort)

Bellek boyutları büyüdüğü için bu yöntem bugün biraz göz ardı edilir, ama bazı durumlarda hâlâ işe yarar.

### 6.1 Problem

Problem tahtada şöyle yazıldı (ekrandan, 00:50:00):

- RAM: 1 GB.
- Veri (diskte): 9 GB $= 9 \cdot 2^{30} \approx 2^{33}$ bayt.
- Problem: veriyi sıralamak.

Insertion Sort, Bubble Sort ve Selection Sort $n^2$ karmaşıklıktadır. $2^{33}$ hücrelik veriyi bunlarla sıralamak $(2^{33})^2 = 2^{66}$ düzeyinde işlem demektir. Asıl sorun işlem sayısı bile değildir: işlenecek verinin RAM'de bulunması gerekir, 9 GB'lık veri 1 GB'lık RAM'e fiziksel olarak sığmaz.

### 6.2 Birinci aşama: parçaları yerinde sıralama

Veri 1 GB'lık 9 parçaya bölünür. Her 1 GB'lık parça RAM'e getirilir; RAM'in tamamını kapladığı için yerinde (in-place) sıralanmalıdır. Bu yüzden burada Merge Sort kullanılamaz, çünkü Merge Sort ayrıca verinin boyutu kadar (1 GB) ek bellek ister. Selection Sort ya da daha hızlı olsun diye Quick Sort kullanılır. Sıralanan parça diskteki yerine geri yazılır, sonra sıradaki parça getirilir.

Sonuçta alt parçaları sıralanmış bir dizi elde edilir. Hoca dizinin tamamının sıralı olup olmadığını sordu; bir öğrenci "olmuyor, merdiven gibi bir şey oluyor" dedi. Örnek (ekrandan, 00:50:00): bir parça 2, 8, 18; diğeri 1, 4, 7; diğeri 70, 78, 98; diğeri 71, 77, 80. Her parça kendi içinde sıralıdır, ama dizi bütün olarak sıralı değildir. Bu ön işlem diziyi sıralamaya yaklaştırır.

### 6.3 Hatırlatma: iki sıralı diziyi birleştirme

Dönemin ilk haftalarında iki sıralı diziyi tek bir sıralı diziye birleştiren (merge) algoritma yazılmıştı. $A$ dizisinde $i$, $B$ dizisinde $j$ indisi tutulur. $A[i]$ ile $B[j]$ karşılaştırılır, küçük olan sonuç dizisinin $k$. yerine yazılır ve onun indisi bir artırılır. Bu bir sıralama değil, birleştirme işlemidir. Diziler $n$ ve $m$ uzunluktaysa $n + m$ işlem yapılır; ikisi de $n$ ise $2n$, yani $O(n)$.

### 6.4 İkinci aşama: çok yollu birleştirme

RAM 100 MB'lık 10 bölüme ayrılır. Diskteki her sıralı 1 GB'lık parçanın ilk 100 MB'ı RAM'e getirilir; 9 parça olduğu için 9 bölüm dolar (toplam 900 MB), bir bölüm boş kalır. Boş bölüm çıktı tamponu olarak kullanılır.

İkili birleştirmenin 9 yollu hâli yazılır (genel olarak $n$ yollu da yazılabilir). Her bölümün başındaki elemanlar karşılaştırılır, en küçüğü çıktı tamponuna yazılır ve o bölümün işaretçisi (pointer) bir ilerler. Çıktı tamponu dolunca diskin başka bir yerine yazılır; bu veriler bütün parçaların en küçük değerlerinden oluştuğu için sonuç dizisi sıralı biçimde ilerler. Bir giriş bölümü boşaldıkça ilgili parçanın sonraki 100 MB'ı diskten getirilir. RAM sürekli dolup boşalır. İş bitince bütün veri diskin yeni yerinde sıralı durur; eski yerdeki veri silinir (aslında yalnız ona işaret eden kayıt silinir). Dosyanın yeri değişse de ona yine adıyla erişilir.

9 yollu birleştirmenin ayrıntısına girilmedi; 9 ya da 10 değişken ya da bir dizi üzerinden yapılabileceği, bunu yapan algoritmalar olduğu söylendi.

**Soru (arada):** Birleştirme gerçekten doğru çalışır mı? Örneğin sonradan getirilen bir 100 MB'lık bölümdeki en küçük değer, daha önce yazılmış değerlerden küçük olabilir mi?

**Cevap:** Olamaz, çünkü birinci aşamada her 1 GB'lık parça kendi içinde sıralanmıştır. Bir parçanın sonraki bölümündeki değerler, aynı parçanın önceki bölümündeki değerlerden küçük olamaz. İki sıralı diziyi birleştirmenin ön şartı dizilerin sıralı olmasıdır. Öğrenci bu ön şartı unuttuğunu söyledi.

### 6.5 Bellek ve disk veri yapıları

Diziler, matrisler, bağlı listeler ve ağaçlar RAM üzerindeki veri yapılarıdır (ekrandan, 00:55:00). Bunların yanında disk veri yapıları da vardır; bunlarda daha çok dengeli ağaçlardan yararlanılır. Bu konu dosya organizasyonu (file organization) dersinde işlenir.

## 7. Disk hızı, SSD ve darboğaz; ara sorular

**Soru:** SSD'lerde DRAM kullanılıyor; hızlandırma bu şekilde mi sağlanıyor?

**Cevap:** Hoca eski sabit disklerin demir tozlarından oluşan ferromanyetik malzeme kullandığını, okuma-yazmanın bloklar hâlinde yapıldığını ve bu yüzden yavaş olduğunu anlattı. SSD'ler farklı bir malzeme yapısına sahiptir, transistörlerle veriyi hem kalıcı saklar hem de daha hızlı okur ve yazar. Derste internette bakılan bir SSD örneğinde yazma hızı yaklaşık 530 MB/s, okuma hızı 550 MB/s idi. SSD klasik disklere göre çok daha hızlıdır, ama maliyeti yüksektir ve sorunu tamamen çözmez. Ne kullanılırsa kullanılsın, bileşenin çalışma hızına bakmak gerekir. Statik ve dinamik RAM ayrıntıları donanım derslerinde görülecektir.

> **Ders sonrası not:** Hoca SSD'yi "dinamik RAM" tabanlı diye anlattı. SSD'ler büyük olasılıkla NAND flash bellek kullanır; DRAM yalnız bazı SSD'lerde önbellek olarak bulunur.

### 7.1 Darboğaz

CPU çok hızlı, RAM ondan biraz yavaş, disk ise çok daha yavaştır. Sistemin hızı en zayıf halka kadar olur; buna darboğaz (bottleneck) denir (ekrandan, 01:15:00). Malzeme biliminde disk malzemeleri üzerine araştırmalar sürmektedir. Hoca, sorunun algoritmik, donanımsal ve işletim sistemi düzeyinde ayrı ayrı çözümleri olduğunu, herkesin kendi alanının çözümleriyle ilgilenmesi gerektiğini söyledi.

Bir öğrenci, işlemcinin çekirdek ve iş parçacığı sayısı da hesaba katılınca işlem gücünün her durumda belleği aştığını belirtti; hoca bunu onayladı.

> **Ders sonrası not:** Hoca işlemci frekansları için bir yerde "belki 40 GHz seviyesinde" dedi. Bugünkü işlemcilerin saat hızı büyük olasılıkla birkaç GHz düzeyindedir; toplam işlem gücü çekirdek ve iş parçacığı sayısıyla artar.

### 7.2 Isınma

**Soru:** İşlemciler ısınınca neden hızları düşüyor?

**Cevap:** İşlemcinin içinde yarı iletken malzemeden yapılmış çok sayıda transistör vardır. Elektrik verildiğinde iletkenler ısınır; iletkenler arasındaki yalıtkan boşluklar nedeniyle kapasitif etkiler de oluşur. Bu dirençsel ve kapasitif etkiler ısı üretir. Sistemin kendini koruması gerekir; BIOS üzerinden yazılımla yapılan ayarlar ve donanımın kendi içindeki koruma mekanizmaları aşırı ısınmada bazı işlevleri pasifleştirip hızı düşürür.

### 7.3 GPU ve TPU

**Soru:** Ekran kartları yapay zekâ geliştirmek için nasıl kullanılıyor?

**Cevap:** Ekran kartlarının kendi işlemcileri (GPU, Graphical Processing Unit) vardır. CPU'da birkaç çekirdek bulunurken GPU'da binlerce işlem elemanı bulunur, çünkü grafik işlemleri çok fazla matris işlemi gerektirir. Yapay zekâ kodları GPU üzerinde çalıştırılarak modeller çok daha hızlı eğitilir. TPU (Tensor Processing Unit) ise matrisin üç ve dört boyutlu hâlleri (tensörler) üzerinde çalışır. Vektör çarpımında karşılıklı çarpımlar birbirinden bağımsız olduğu için, bunu yapan bir donanımla $n$ turluk döngü tek adıma indirilebilir; matrisleri ve üç boyutlu matrisleri tek adımda çarpan donanım çözümleri de vardır. GPU ve TPU'ların mantığı daha çok işlem elemanıdır. Bunların kendi RAM'leri de vardır; o ayrı bir konudur.

## 8. Problem türleri: P ve NP

Aradan sonra hoca problem türlerine (problem types) geçti; bu konunun ileriki dönemlerde ayrıntılı işleneceğini söyledi. Problemler çözülebilirlik açısından en genel hâlde iki gruba ayrılır (ekrandan, 01:25:00).

### 8.1 P-type

P, polinom (polynomial) demektir; $n^2$, $n^3$, $n^4$ gibi. Bir problemi çözen polinom zamanlı bir algoritma varsa o problem P-type'tır. Örneğin sıralama (sort) bir problemdir; Selection Sort bu problemi çözen $n^2$'lik bir algoritmadır. Sıralama $n^2$ (Insertion Sort, Selection Sort) ya da $n \log n$ (Quick Sort) ile çözüldüğü için P-type'tır. $n \log n$ zaten $n^2$'nin altındadır.

> **Hocanın vurgusu:** Algoritmalar P-type olmaz; problemler P-type olur. "Selection Sort P-type'tır" demek yanlıştır, sık karıştırılır. Sıralama ve arama algoritmaları, P-type problemler için önerilmiş algoritmalardır.

NP'nin NP-complete ve NP-hard gibi alt türleri de vardır; derste en genel hâli olan NP kullanıldı.

### 8.2 Deterministik ne demek?

Hoca "deterministik" kavramını sordu. Bir öğrenci "sonucu belli" dedi. Hoca bunu açtı: bir deneyi her yaptığınızda aynı parametrelerle aynı sonucu buluyorsanız ortada rastlantısal (stokastik) olmayan, deterministik bir durum vardır; iki kere iki her seferinde dörttür.

NP (non-deterministic polynomial) derste şöyle tanımlandı (ekrandan, 01:25:00): polinom zamanlı bir algoritmayla çözülüp çözülmediği belli olmayan problemler. Bazı durumlarda polinom zamanda çözülebilen, bazı durumlarda çözülemeyen problemler vardır.

> **Ders sonrası not:** NP'nin standart tanımı, bir çözümün polinom zamanda doğrulanabildiği (eşdeğer olarak deterministik olmayan bir makinede polinom zamanda çözülebildiği) problemler sınıfıdır; P de NP'nin içindedir. Derste verilen "polinom zamanda çözülüp çözülmediği belli değil" ifadesi, NP-complete gibi zor problemler için bugün bilinen durumun sezgisel bir açıklamasıdır.

### 8.3 Karmaşıklık sırası

Hoca öğrencilerle birlikte iyi karmaşıklıktan kötüye doğru bir sıra kurdu (ekrandan, 01:25:00):

- P ailesi: $1 \to \log\log N \to \log N \to N \to N \log N \to N^2, N^3, N^4, \dots, N^k$.
  - $\log\log N$, dönem içinde görülen interpolasyon aramasının karmaşıklığıdır.
  - $N^k$'da $k$ sabittir ($N^{10}$ gibi); $N^N$'e kadar gitmez.
- Polinom olmayan aile: $2^N, 3^N, k^N, N!, N^N$.
  - $N!$, 1'den $N$'e kadar sayıların çarpımıdır; $N^N$ ise $N$ tane $N$'nin çarpımıdır, daha da kötüdür.
  - Örneğin bir yöntem $N!$, diğeri $2^N$ ile çözüyorsa $2^N$ daha iyidir.

Polinom ailesi "iyi" sayılır; mümkün olduğunca 1'e yaklaşmak hedeflenir. Bir problemi bugüne kadar yalnız polinom olmayan zamanda çözebiliyorsak bu, hiçbir zaman polinom zamanlı çözüm bulunamayacağı anlamına gelmez; birisi gelip daha iyi bir yöntem bulabilir.

> **Hocanın vurgusu:** Dönem boyunca daha çok P-type problemlerle uğraşıldı: dizilerde dolaşma, matris işlemleri, rastgele algoritmalar, matris çarpımı. Sepet analizinde ürün üçlülerini bulmak bile $n^4$'lük bir algoritmayla çözüldüğü için P-type'tır.

### 8.4 Son yüzyılın önemli algoritmalarından örnekler

Hoca bir önceki gün öğrencilerle paylaştığı "20. yüzyılın en iyi 10 algoritması" listesinden örnekler verdi:

- Quick Sort: $n \log n$ sürede ve ek bellek kullanmadan sıralar. Merge Sort da $n \log n$'dir ama ek bellek ister; bellek yetmiyorsa Merge Sort kullanılamaz.
- Hızlı Fourier dönüşümü (Fast Fourier Transform): normal Fourier dönüşümü $n^2$'dir, FFT bunu $n \log n$'e indirir. Sinyaller ve sistemler ya da işaret işleme derslerinde görülecektir; yapay zekâdaki konvolüsyon işlemlerinin arkasında da vardır.
- Matris ayrıştırma (matrix decomposition): büyük matrisleri daha basit matrisler cinsinden yazarak birçok problemi kolayca çözmeyi sağlar.
- Doğrusal programlamada Simplex yöntemi: endüstri mühendislerinin çok kullandığı, örneğin $N$ işçi ve $M$ iş varken hangi işçiye hangi işin verileceğini maliyeti en aza, verimi en çoğa indirecek biçimde belirleyen bir algoritmadır.

> **Ders sonrası not:** Hoca Quick Sort için "$n^2$'den $n \log n$'e indiriyor" dedi. Quick Sort'un ortalama karmaşıklığı $n \log n$, en kötü durumu ise $n^2$'dir; Merge Sort her durumda $n \log n$'dir.

## 9. Alt küme toplamı problemi

Polinom olmayan ailenin ilk örneği (ekrandan, 01:35:00): **$N$ sayı içinde toplamı $K$ olan bir alt küme var mı?** Bu bir varlık-yokluk (existence) problemidir.

Tahtadaki dizi $A = [4, 8, 2, -1, 5, 10, 6]$ ve $K = 15$ idi; hoca sonradan diziye 15'i de ekledi. Öğrencilere "algoritmik değil, gözle bakın" dedi. Bulunan alt kümeler (ekrandan, 01:35:00):

- {10, 5}
- {8, 2, 5}
- {10, 6, −1}
- {8, 2, 6, −1}
- {10, 4, 2, −1}
- {6, 4, 5}

Hoca bunları nasıl bulduklarını sordu. Öğrenciler önce ikişer ikişer, sonra üçlü kombinasyonlara baktıklarını, 15'e yaklaşmaya çalıştıklarını söyledi. Hoca bunun algoritmik bir çözüm olmadığını vurguladı: bir yerden başlayıp adım adım giden bir yöntem yoktur, kodu yazılamaz. Dizi küçük olduğu için gözle çözülebildi; 70 bin elemanlı bir dizide bu yöntem çalışmaz.

### 9.1 Sistematik çözüm

$N$ elemanlı bir kümenin $2^N$ alt kümesi vardır; boş küme hariç $2^N - 1$. 7 elemanda $2^7 - 1 = 127$, 15 eklenince 8 elemanda $2^8 - 1 = 255$ durum vardır (ekrandan, 01:35:00).

Kodla çözmek için önce tek elemanlı alt kümelere bakılır: dizide $K$'ya eşit bir eleman var mı (1-sum)? Bunun sayısı

$$\binom{N}{1} = \frac{N!}{(N-1)! \, 1!} = N$$

olup tek bir `for` döngüsüyle bakılır. Sonra iki elemanlı alt kümelere ($\binom{N}{2}$, iki iç içe döngü, 2-sum), sonra üç elemanlılara (3-sum, üç iç içe döngü), ... $N$ elemanlıya kadar bakılır. Hoca dönem başında gösterilen 3-sum sunumunu hatırlattı.

Bir öğrenci ikilik sayaç (binary counter) önerdi: alt kümeler ikilik sayılarla gösterilebilir; her bit bir elemanın alınıp alınmadığını belirtir (0000, 0001, ... gibi). Hoca bunun da $2^N$ durum demek olduğunu söyledi.

Hoca, diziyi önce $n \log n$ ile sıralayıp sonra ikili aramayla kontrol etmenin 3-sum probleminde olduğu gibi bir miktar iyileştirme sağlayabileceğini, ama problemin üstel ailede kaldığını belirtti.

> **Ders sonrası not:** Hoca bu kaba kuvvet çözümün karmaşıklığının kod olarak yazıldığında $N!$'e çıktığını söyledi. Oysa $\sum_{r=1}^{N} \binom{N}{r} = 2^N - 1$'dir; her alt kümenin toplamını hesaplamakla birlikte kaba kuvvet çözüm $O(N \cdot 2^N)$'dir. Bu üsteldir, ama $N!$ değildir.

## 10. Gezgin satıcı problemi (TSP)

İkinci örnek gezgin satıcı problemidir (Traveling Salesman Problem, TSP) (ekrandan, 01:40:00). Hoca birkaç ili (İstanbul, İzmit, Sakarya, Düzce, Bursa, Balıkesir, Eskişehir gibi) tahtaya çizdi. Bir ilden başlanır, bütün illerden geçilir, başlangıca geri dönülür; en az maliyetli (en kısa) rota aranır. Hoca her ilden her ile bir yol (uçak, tren, karayolu) olduğunu varsaydı.

### 10.1 Olası rota sayısı

7 şehirde İstanbul'dan başlanırsa ilk adımda 6, sonra 5, 4, 3, 2, 1 seçenek vardır; sonra İstanbul'a dönülür (ekrandan, 01:40:00). $N$ şehir için $(N-1)!$ rota denenmelidir; her rotanın maliyeti hesaplanır ve en küçüğü seçilir. 7 şehirde bu sayı küçüktür ve denenebilir; ama Türkiye'nin 81 ili için $80!$ rota vardır, bütün ihtimalleri denemek mümkün değildir. Genel olarak TSP'nin kaba kuvvet karmaşıklığı $N!$ diye anılır.

> **Ders sonrası not:** Hoca "6 faktöriyel 127, 840 gibi bir şey" dedi. Doğrusu $6! = 720$, $7! = 5040$'tır.

### 10.2 Donanım neden yetmez?

Hoca $N!$ ile $(N+1)!$ arasında kaç kat fark olduğunu sordu; bir öğrenci "$N+1$" dedi. $(N+1)! = N! \cdot (N+1)$'dir. $N!$'lik bir problemi hızlı çözen müthiş bir işlemci tasarlasanız bile probleme bir veri daha eklendiğinde donanımın $N+1$ kat daha hızlı olması gerekir. Bu mümkün olmadığı için tasarlanan donanım çöpe gider. Bu yüzden $N!$'lik bir çözüm klasik döngülerle kodlanamaz.

## 11. Zaman, bellek, doğruluk ve yaklaşık çözüm

Hoca bir algoritmanın değerlendirilmesinde üç ölçüt olduğunu hatırlattı (ekrandan, 01:50:00): zaman (time), bellek (memory) ve doğruluk (accuracy). Bunlar arasında ödünleşim (trade-off) vardır; örneğin zamandan kazanmak için bellekten ödün verilebilir ya da tersi.

NP tipi problemlerde zamandan ve bellekten ödün verilemez; doğruluktan ödün verilir. Belki $N!$'lik bir problem $N^4$'lük bir yöntemle çözülür; $N^4$ ya da $N^{10}$ bile hiç çözmemekten iyidir.

- Kesin çözüm: optimal / exact solution.
- Yaklaşık çözüm: approximate solution.

Hoca uydurma bir örnek verdi: Türkiye'deki bütün illeri gezmenin gerçek çözümü 7800 km olsun ve bunu bulmak 1000 yıl sürsün. Yaklaşık bir çözüm 9500 km'lik bir rotayı 3 dakikada bulsun. Gezecek biri için aradaki fark çok önemli değildir; 1000 yıl ile 3 dakika arasında ise çok büyük fark vardır (ekrandan, 01:50:00).

> **Hocanın vurgusu:** Optimal çözümü bulmak için zaman ve bellek yetersiz kalıyorsa doğruluktan ödün vererek yaklaşık çözüm bulunur. Bu önemli bir konudur.

Bu tür algoritmalar daha çok yapay zekâ derslerinde işlenir ve sezgisel (heuristic) diye adlandırılır. Çoğu doğadaki olaylardan esinlenir: canlıların davranışları, sinir sistemi, yerçekimi gibi fiziksel olaylar, biyolojik ve kimyasal süreçler. Örneğin karınca kolonisi algoritması, TSP'deki tek tek aramadan çok daha hızlı, polinom zamanlı bir arama algoritmasıdır. Tam sonucu garanti etmez, ama iyi bir yaklaşık sonuç verir. Bir algoritma 9500 km, diğeri 9300 km bulursa ikincisi daha iyidir; bu alanda yarışmalar yapılır ve daha iyi sonuç veren yöntemler makalelerle literatüre girer.

Hoca, dönem projesinin uzun çalışmasının da problemin karmaşıklığından kaynaklandığını söyledi. Daha büyük tahtalı oyunlarda (örneğin $8 \times 8$ satranç yerine daha büyük satranç türlerinde) çözüm neredeyse imkânsız hâle gelir.

## 12. En yakın komşu sezgiseli

Hoca öğrencilere Türkiye'yi gezmek için nasıl bir yaklaşık çözüm önereceklerini sordu.

- Bir öğrenci, önce Türkiye'nin çevresini sonra içerisini daire çizerek dolaşmayı önerdi. Hoca bunun bazı bölgeleri (örneğin Trakya ile İç Anadolu arasında) gereksiz yere tekrar dolaşmaya yol açabileceğini söyledi.
- Başka bir öğrenci zikzak çizmeyi önerdi.

Hoca en yaygın sezgisel yöntemi anlattı: **bir şehirden başla, her adımda ziyaret edilmemiş en yakın şehre git.** Ziyaret edilmiş bir şehre tekrar gidilmez; en yakın şehir ziyaret edildiyse ikinci, üçüncü en yakın seçilir. Bütün şehirler gezilince başa dönülür.

### 12.1 Karmaşıklığı

$N$ şehir varsa ilk şehrin $N-1$ komşusu vardır; en yakını seçilir. Sonraki şehirde $N-2$, sonra $N-3$ seçenek kalır, ... 1'e kadar. Toplam (ekrandan, 02:00:00):

$$(N-1) + (N-2) + (N-3) + \dots + 1 = \frac{N(N-1)}{2} \approx \frac{N^2}{2} \ll N!$$

Bu, $N!$'e kıyasla çok küçük bir değerdir. Zaman ve bellek bakımından iyidir; ödün verilen doğruluktur, bulunan rotanın optimal olduğu garanti edilemez.

### 12.2 Başlangıç noktası ve yerel minimum

Bir öğrenci, iki şehir birbirine çok yakınsa (örnek olarak Burdur ve Isparta verildi) başlangıcı ikisinden birinden yapıp diğerini en sona bırakmanın daha iyi olabileceğini önerdi. Hoca bunun bir iyileştirme olduğunu ve başlangıç noktasının önemli olduğunu söyledi.

Hoca bir Türkiye haritası açıp Batı Anadolu'da kıyıya yakın bir ilden başlayarak en yakın komşuları seçti. Birkaç adım sonra rota kıyı bölgesinde sıkıştı: gidilecek ziyaret edilmemiş komşu kalmadı ve geri dönmek problemin kısıtını bozacaktı.

Maliyet fonksiyonu çizildiğinde global ve yerel minimum noktaları olan bir eğri gibi düşünülebilir. Sezgisel çözümler yerel minimumlara takılabilir. Türkiye gibi bir haritada mümkün olduğunca orta bölgelerden başlamak bu sorunu azaltır. Başka bir öğrenci de çok komşusu olan büyük bir ilden (örneğin Ankara ya da Konya) başlamayı önerdi.

### 12.3 Ders notlarındaki örnek

Hoca ders notlarındaki örneği açtı (ekrandan, 02:00:00). Şehirler ve aralarındaki maliyetler:

| Kenar | Maliyet |
|---|---|
| A – B | 2 |
| B – C | 1 |
| C – D | 1 |
| D – E | 1 |
| E – F | 1 |
| A – F | 6 |

- Sezgisel algoritma B'den başlasın. B'nin komşuları A (2) ve C (1); en yakını C. Sonra D, E, F ve son olarak A. Rota B C D E F A, uzunluğu $1 + 1 + 1 + 1 + 6 = 10$.
- B'den başlayan daha iyi bir çözüm: B A B C D E F. Önce A'ya gidip B'ye geri dönülür, sonra C, D, E, F gezilir. Uzunluk $2 + 2 + 1 + 1 + 1 + 1 = 8$. Hoca bunun kuralı biraz esnettiğini (B'den iki kez geçildiğini) ama daha iyi bir sonuç verdiğini söyledi.
- Optimal çözümlerden biri: A B C D E F, uzunluk $2 + 1 + 1 + 1 + 1 = 6$.

Bu örnekte başlangıca dönüş maliyeti hesaba katılmadı; amaç bütün şehirleri gezmekti. Örnek hem yerel minimuma takılmayı hem de başlangıç noktasının doğru seçilmesinin önemini gösterir.

Notlardaki diğer maddeler: bazı sezgisel yaklaşımlar bazı problem türlerinde ve bazı kısıtlar altında optimal çözümü garanti eder, ama çoğunlukla böyle değildir. Optimumu bulmanın şart olmadığı durumlarda çok beklemek yerine optimal olmayan ama hızlı bulunan çözümler tercih edilir; gezgin satıcıya "beş yıl bekle, sana optimal rotayı vereyim" denemez. Bu algoritmaların ayrıntıları yapay zekâ dersinde işlenir.

Literatürdeki en iyi yaklaşık çözüm herkesçe kabul görür ve kullanılır; daha iyisini bulan kişi tanınır ve ödüllendirilir.

## 13. Karınca kolonisi ve genetik algoritma örneği

Hoca, Türkiye'nin 81 ili üzerinde TSP'yi karınca kolonisi algoritması ve genetik algoritma ile çözen yayımlanmış bir çalışmayı ve onun arayüzünü gösterdi (ekrandan, 02:10:00). Harita özel veri yapılarıyla saklanır; arayüzde bulunan rotalar farklı renklerle çizilir. Bu rotalar kesinlikle optimal değildir.

- Karınca kolonisi algoritması (ant colony optimization): karıncaların yem arama ve kendi aralarındaki etkileşim davranışını modelleyen bir algoritmadır. 1000 adımda yaklaşık 9966 km'lik bir rota buldu; arama yaklaşık 15 dakika sürdü. Rota Burdur (15) ile başlıyor, Isparta (32), Uşak (64), Afyon (3), Kütahya (43), Eskişehir (26), Bilecik (11), Bursa (16), Yalova (77), Kocaeli (41), Sakarya (54), Düzce (81) diye devam ediyordu. Hoca bunun bir öğrencinin önerdiği Burdur-Isparta başlangıcına uyduğunu belirtti.
- Genetik algoritma: biyolojideki çaprazlamayı (crossing over) kullanan bir yöntemdir. 1000 adımda 11739 km'lik bir rota buldu; arama süresi 00:15:10 idi (ekrandan, 02:10:00).

İki yöntemin arama süreleri hemen hemen aynıydı. Hoca, algoritma daha uzun çalıştırılırsa rotanın kısalabileceğini ve bugün daha iyi çözümlerin büyük olasılıkla bulunmuş olduğunu söyledi. Karayolu verileri çalışmanın yapıldığı yıllara aitti; yeni yollarla mesafeler değişmiş olabilir.

**Soru:** Karınca kolonisi algoritması ile genetik algoritma kaç örnek üzerinden karşılaştırılıyor?

**Cevap:** Karşılaştırma örnek sayısı üzerinden değil, problem uzayı üzerinden yapılır. Bunlar her türlü arama problemine uygulanabilen, maliyeti en aza indirmeye çalışan optimizasyon algoritmalarıdır ve birçok parametresi vardır (örneğin karınca sayısı; 30 ya da 100 karınca farklı sonuç ve farklı süre verir). Problem bir haritaysa örnek uzayı sabittir. Bir makinenin çalışma parametrelerini belirlemek gibi problemlerde ise farklı veriler toplanır. Bu algoritmalar, bir dizinin en küçük elemanını bulan algoritmanın her türlü veriye uygulanabilmesi gibi geneldir.

**Soru:** Sezgisel algoritmalar her çalıştırmada farklı çözüm mü verir?

**Cevap:** Evet, verebilir; bu yüzden deterministik değildir. Bütün parametreler aynı verilir ve rastgele bir bileşen yoksa aynı sonuç elde edilir; ama bu algoritmaların iç yapısı rastgele sayı üretimine ve rastgele işlemlere dayanır.

**Soru:** Sonuç her seferinde farklı olduğuna göre bir algoritmanın diğerinden üstün olduğunu göstermek için kaç deney gerekir?

**Cevap:** İstatistiksel olarak en az 30-35 deney yapmak gerekir. Ama "genetik algoritma her problemde karınca algoritmasından kötüdür" gibi genel bir yargıya varılamaz; bazı problemlerde biri, bazı problemlerde diğeri daha iyidir. Arı, kedi ve balık sürüsü gibi başka doğadan esinlenen algoritmalar da vardır.

**Soru:** Bu algoritmalar sonuçlar Gauss (normal) dağılıma ulaşana kadar mı çalıştırılır?

**Cevap:** Böyle bir şart yoktur. Belli durumlarda yapılabilir, ama tekrar sayısını artırmanın da bir maliyeti vardır. Bu tür yapay zekâ çözümlerinde "şunu uygularsan şunu elde edersin" denemez; deterministik olmadıkları için belli durumlarda belli yöntemler işe yarar.

Hoca bu algoritmalar için *Clever Algorithms* kitabını önerdi (ekrandan, 02:20:00). Kitap her algoritmanın mantığını, nereden esinlendiğini ve kodunu verir. Gruplar arasında sinirsel algoritmalar, bağışıklık algoritmaları (örneğin klonal seçim, yapay bağışıklık tanıma sistemi), sürü algoritmaları (parçacık sürü optimizasyonu, karınca sistemi, karınca kolonisi sistemi, arı algoritması), olasılıksal algoritmalar ve fiziksel algoritmalar vardır.

## 14. Neden bu problemler doğrudan kodlanamıyor?

Hoca TSP gibi problemlerde doğrudan kod yazılamamasının nedenini bellek yapısıyla açıkladı (ekrandan, 02:05:00).

Bellek (RAM) aslında düz bir yapıdır; bir dizi ya da sayı doğrusu gibidir: 0. hücre, 1. hücre, 2. hücre... Tek boyutlu sayı doğrusunda her gerçek sayı tek bir büyüklükle ifade edilir; bellekte de her hücreye tek bir adresle ulaşılır. Diziler, matrisler, bağlı listeler, haritalar, hepsi bu tek boyutlu yapıya uyarlanır.

Gerçek dünya ise tek boyutlu değildir. En basit örnek karmaşık sayılardır: $x + yi$ biçimindeki bir sayı gerçel ve sanal kısımlarıyla iki boyutludur. Gerçek dünya geometriktir; iki, üç, dört boyutlu yapılar her zaman tek boyuta indirgenemez. Öğrencilerin vize ve final notlarını tutan iki boyutlu bir tablo tek boyuta kolayca indirgenir, çünkü çözüm uzayı bellidir. Ama TSP gibi problemlerde çözüm olasılıkları bir ağaç gibi dallanıp budaklanır; $N!$ kadar olasılık için bellekte yer yoktur, bu kadar durumu işleyecek işlem kapasitesi de yoktur.

Hoca, kuantum hesaplamanın ileride yenilikler getirebileceğini, ama mevcut bilgisayar sistemlerinin bu problemlerin gerçek çözümüne ulaşmak için yeterli olmadığını söyledi.

## 15. Önerilen kaynaklar ve dersin genel değerlendirmesi

### 15.1 Kitaplar

- Donald Knuth, *The Art of Computer Programming*: birkaç ciltlik bir seri. Ciltler temel algoritmalar, yarı sayısal algoritmalar, sıralama ve arama, kombinatoryal algoritmalar gibi konuları ele alır (ekrandan, 02:15:00).
- Robert Sedgewick ve Kevin Wayne, *Algorithms* (4. baskı): çevrimiçi kod, animasyon, alıştırma ve ders videolarıyla birlikte gelir (ekrandan, 02:15:00). Hoca kitabı "Stanford'ın" diye andı; ekranda açılan site Princeton Üniversitesi'nindi.
- *Clever Algorithms*: doğadan esinlenen algoritmalar.

Hoca bu kitapların ayrık matematik, veri yapıları ve algoritmalar, algoritma analizi gibi sonraki derslerde farklı bakış açıları kazandıracağını söyledi. Bilgisayar mühendisinin işi yalnız matematiksel boyut değildir; ama çok geç sonuç veren ya da çok fazla bellek tüketen problemler için daha iyi algoritma geliştirmek önemlidir.

### 15.2 Dersin özeti

Hoca dönemin genel değerlendirmesini yaptı: algoritma nedir, iyi algoritma nedir, bir algoritmaya hangi açılardan iyi denir, bunlar kod ve akış diyagramı (flow chart) üzerinden örneklerle çalışıldı. Ders yalnız bir programlama dersi değildir; algoritmik bakış açısı kazandırmayı amaçlar. Giriş dersi olduğu için basit algoritmalar ele alındı, ama bunların iyileştirilme adımları ("şunu değiştirsek ne olur?") üzerinde duruldu.

> **Hocanın vurgusu:** Bir algoritmayı bellek ya da zaman kullanarak iyileştiremiyorsanız matematiği ve mantığı kullanarak çok iyi çözümler üretebilirsiniz. Dönem içinde matematik kullanılarak $n$'lik bir algoritmanın $O(1)$'e indirildiği örnekler vardı.
## Örnek Sorular

**Soru 1** (ekrandan, 00:35:00): $A: 10 \times 30$, $B: 30 \times 5$, $C: 5 \times 60$ matrisleri için $A \cdot B \cdot C$ çarpımında $(AB)C$ ve $A(BC)$ sıralarının çarpma sayılarını bulun. Hangisi daha iyidir?

> **Çözüm (derste verildi):** $(AB)C$: $10 \cdot 30 \cdot 5 = 1500$ ($AB$ $10 \times 5$ olur), $10 \cdot 5 \cdot 60 = 3000$; toplam 4500. $A(BC)$: $30 \cdot 5 \cdot 60 = 9000$ ($BC$ $30 \times 60$ olur), $10 \cdot 30 \cdot 60 = 18000$; toplam 27000. $(AB)C$ daha iyidir.

**Soru 2** (derste sözlü, 00:20:08): $n \times m$ ile $m \times p$ boyutlu iki matrisi çarpan üç döngülü algoritmanın zaman karmaşıklığı nedir?

> **Çözüm (derste verildi):** Çarpma işlemi $n \cdot m \cdot p$ kez yapılır. Kare matrislerde ($n = m = p$) $O(n^3)$.

**Soru 3** (derste sözlü, 00:24:05): $n = 1000$ için $n^3$'lük kod tek işlemcide 1 dakika sürüyor. İdeal durumda iki ve üç işlemciyle süre ne olur?

> **Çözüm (derste verildi):** İki işlemciyle 30 saniye, üç işlemciyle 20 saniye. Karmaşıklık değişmez, süre işlemci sayısına bölünür.

**Soru 4** (derste sözlü, 00:55:53): 1 GHz ($10^9$) işlemci, 10 MHz ($10^7$) RAM'den kaç kat hızlıdır? 7200 rpm bir disk kaç Hz'e karşılık gelir?

> **Çözüm (derste verildi):** $10^9 / 10^7 = 10^2$, yani 100 kat. $7200 / 60 = 120$ Hz $\approx 10^2$; işlemci diskten yaklaşık $10^7$ kat hızlıdır.

**Soru 5** (ekrandan, 00:50:00): 1 GB RAM'i olan bir bilgisayarda 9 GB'lık veri nasıl sıralanır?

> **Çözüm (derste verildi):** Veri 1 GB'lık 9 parçaya bölünür; her parça RAM'de yerinde (örneğin Quick Sort ile) sıralanıp diske yazılır. Sonra RAM 100 MB'lık bölümlere ayrılır, her parçanın ilk 100 MB'ı RAM'e alınır ve 9 yollu birleştirme yapılır. Çıktı tamponu doldukça diske yazılır, boşalan giriş bölümleri diskten doldurulur.

**Soru 6** (ekrandan, 01:35:00): $A = [4, 8, 2, -1, 5, 10, 6, 15]$ dizisinde toplamı $K = 15$ olan alt kümeleri bulun. Kaç alt kümeye bakmak gerekir?

> **Çözüm (derste verildi):** Derste {10, 5}, {8, 2, 5}, {10, 6, −1}, {8, 2, 6, −1}, {10, 4, 2, −1}, {6, 4, 5} bulundu. 8 elemanlı dizide $2^8 - 1 = 255$ boş olmayan alt küme vardır.

> **Ders sonrası not:** Dizide 15'in kendisi de bulunduğu için {15} de bir çözümdür. Python ile bütün alt kümeler denendiğinde toplamı 15 olan 7 alt küme bulunur: yukarıdaki altı küme ve {15}.

**Soru 7** (derste sözlü, 01:39:52): $N!$ ile $(N+1)!$ arasında kaç kat fark vardır? Bu, donanımla hızlandırma açısından ne anlama gelir?

> **Çözüm (derste verildi):** $(N+1)! = (N+1) \cdot N!$, yani $N+1$ kat. Probleme bir veri eklenince donanımın $N+1$ kat hızlanması gerekir; bu mümkün olmadığından donanım çözümü yetersiz kalır.

**Soru 8** (ekrandan, 02:00:00): Kenar maliyetleri A–B 2, B–C 1, C–D 1, D–E 1, E–F 1, A–F 6 olan şehirlerde en yakın komşu sezgiseli B'den başlarsa hangi rotayı bulur? Daha iyi bir rota ve optimal çözüm nedir?

> **Çözüm (derste verildi):** Sezgisel rota B C D E F A, uzunluk 10. B'den başlayan daha iyi çözüm B A B C D E F, uzunluk 8. Optimal çözümlerden biri A B C D E F, uzunluk 6.

**Soru 9** (ekrandan, 02:00:00): En yakın komşu sezgiselinin karmaşıklığı nedir?

> **Çözüm (derste verildi):** $(N-1) + (N-2) + \dots + 1 = N(N-1)/2 \approx N^2/2$; bu $N!$'den çok küçüktür, ama optimal çözümü garanti etmez.

## Dersin Toparlaması

Dönemin bu son dersinde algoritmaların verimliliği üç yönden ele alındı. Matris çarpımı örneğinde zaman karmaşıklığının boyutlara bağlı olduğu ($n \cdot m \cdot p$), böl-yönet algoritmalarının üssü düşürebildiği, paralelleştirmenin süreyi kısalttığı ve matris zincirinde çarpım sırasının işlem sayısını altı kattan fazla değiştirebildiği görüldü. Dış birleştirmeli sıralama örneği ise bellek sınırının bir algoritmanın seçimini nasıl belirlediğini gösterdi: RAM'e sığmayan veri önce parça parça yerinde sıralanır, sonra çok yollu birleştirmeyle disk üzerinde sıralı hâle getirilir. Bu bölümde CPU, RAM ve disk arasındaki hız farkları ve darboğaz kavramı da tartışıldı.

Dersin ikinci yarısında problemler P ve NP diye ayrıldı. Alt küme toplamı ve gezgin satıcı problemleri, kaba kuvvetle çözülmesi üstel ya da faktöriyel zaman alan problemlerdir. Bu problemlerde doğruluktan ödün verilerek en yakın komşu, karınca kolonisi ve genetik algoritma gibi sezgisel yöntemlerle makul sürede yaklaşık çözümler bulunur; bu yöntemler yerel minimuma takılabilir ve başlangıç noktasına duyarlıdır. Hoca bu konuların veri yapıları, algoritma analizi, ayrık matematik ve yapay zekâ derslerinde derinleştirileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
