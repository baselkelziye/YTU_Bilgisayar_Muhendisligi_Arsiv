# Ders 17 Genişletilmiş Notu: Laboratuvar: Akışlardan İlk C Programlarına

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Laboratuvar Ortamı ve Çalışma Düzeni
- 2. İlk Program: Hello World
- 3. Derleme, Çalıştırma ve Çıktı Adı
- 4. Faktöriyel Programı ve Derleyici Hata Mesajları
- 5. Newton Yöntemiyle Karekök
- 6. Üçgenin Türünü Bulan Program
- 7. Dizinin Ortalaması
- 8. Ortalama Programı Üzerine Sorular
- 9. Değişken Boyutlu Dizi Sorusu
- 10. Laboratuvar Sonrası Çalışma
- Örnek Sorular

## 1. Laboratuvar Ortamı ve Çalışma Düzeni

Bu laboratuvar saatinde, önceki teorik derste konuşulan C programlamanın küçük bir kısmı uygulamaya geçirildi. Hoca, teorik derste görülen bütün veri yapıları ve kontrol akışlarının bir anda değil, en temelden başlayarak adım adım ele alınacağını söyledi.

Uygulama, daha önceki Linux laboratuvarında anlatılan ortamda yapıldı: sanal makine üzerine kurulmuş Ubuntu ve sonradan yüklenen geliştirme araçları, özellikle `gcc`. Bu ortamın hazır olması gerekiyordu.

Hoca önce masaüstünde `BBG` adlı bir klasör, onun içinde de `Lab01` adlı ikinci bir klasör açtı. Haftanın bütün örnekleri bu klasöre kondu. Aynı yere terminalden de gidildi (ekrandan, 00:05:00):

```text
cd Desktop/
ls -la
cd BBG/
ls -la
cd Lab01/
ls -la
```

`ls -la` ile klasörün içeriği listelendi; `Lab01` başta boştu. Hoca, alışkanlıkla hızlı yazabileceğini, görüntüde bir şey kaçırılırsa durdurup sorulabileceğini söyledi.

### 1.1 Editör ve derleyici

Bu aşamada editör ve derleyici ayrı ayrı kullanıldı. Hoca, öğrenciler alıştıktan sonra işleri kolaylaştıracak bir bütünleşik geliştirme ortamına (IDE) geçileceğini söyledi. Hangi IDE'nin kullanılacağı önemli değildir; hocaya göre asıl önemli olan, hiçbir geliştirme ortamına bağımlı olmadan da kendi başına program yazabilmektir.

Editör olarak Ubuntu'da standart gelen `gedit` kullanıldı. `Alt+F2` ile komut penceresi açılıp `gedit` yazılınca boş bir editör açılır.

### 1.2 Dosya adı ve uzantı

Yeni dosya kaydedilirken gedit nereye kaydedileceğini sorar ve ad verilmezse "Untitled Document 1" adını koyar. Hoca dosyaların böyle adlandırılmaması gerektiğini söyledi. Bir C programı yazılıyorsa dosyaya buna uygun bir uzantı verilmelidir. Uzantının iki faydası vardır:

- Dışarıdan bakan kişi dosyanın bir C programı olduğunu anlar.
- Editör de bunun bir C dosyası olduğunu bilir ve sözdizimini buna göre renklendirir.

Hoca önce dosyaya `#include <stdio.h>` yazıp kaydetti. Dosya yöneticisi, ad `.c` ile bitmese bile içerideki `include` satırından bunun bir C dosyası olduğunu anlamıştı. Yine de doğru yol dosyayı yeniden adlandırmaktır (sağ tık ve Rename ya da `F2`). Dosyanın adı `hello.c` yapıldı (ekrandan, 00:10:00).

## 2. İlk Program: Hello World

### 2.1 main fonksiyonu

Hoca, C'nin fonksiyonlardan oluşan bir dil olduğunu hatırlattı. Çalıştırılabilir her programın bir başlangıç noktası olmalıdır; bu başlangıç noktası `main` fonksiyonudur. Yazılan her çalıştırılabilir program için bir `main` fonksiyonu bulunur.

- `main`'in dönüş değeri `int`'tir.
- Bu derste `main` parametre almaz. Parametre kısmı bu dersin değil, yapısal programlama dersinin konusudur.

`main`'in dönüş değerinin anlamı şudur: yazılan kod çalışınca bir süreç (proses) olur. Bu süreç işini bitirdiğinde, kendisini çalıştıran başka bir sürece durumunu bu değerle bildirir. Yazılı bir kural olmasa da Unix ve türevi işletim sistemlerinde başarıyla biten bir sürecin dönüş değeri 0'dır. Bu yüzden fonksiyonun sonuna `return 0;` yazılır.

### 2.2 return ile exit farkı

Programı bitirmenin bir başka yolu `exit` kullanmaktır. `main`'in son satırında `return 0` ile `exit(0)` arasında fark yoktur. Ancak başka bir fonksiyonun içinde fark büyüktür:

- `return`, içinde bulunulan fonksiyondan çıkıp çağırana döner.
- `exit`, bütün programı sonlandırır.

Hoca bunu "kaş yapayım derken göz çıkarmak" diye anlattı: yanlış yerde kullanılan `exit` programı beklenmedik biçimde bitirir.

### 2.3 Programın yazılması

Şablon ekrana şöyle yazıldı (ekrandan, 00:10:00):

```c
#include <stdio.h>

int main(void)  {


    return 0;
}
```

İlk örnek, her programlama dilinin temel örneği olan ekrana "Hello World" yazdırmaktı. Hoca bilerek önce yeni satır karakteri olmadan yazdırdı: `printf("Hello World...");`.

## 3. Derleme, Çalıştırma ve Çıktı Adı

### 3.1 gcc ve a.out

En basit derleme komutu `gcc hello.c`'dir. Derleme bitince klasörde `a.out` adlı bir dosya oluşur. Bu dosyayı çalıştırmak için `./a.out` yazılır.

`./` öneki, içinde bulunulan klasördeki bir çalıştırılabilir dosyanın çalıştırılacağını söyler. Önek yazılmazsa sistem, işletim sisteminin genelinde yüklü uygulamalar arasında `a.out` adlı bir program arar.

### 3.2 Yeni satır karakterinin önemi

İlk çalıştırmada çıktı `Hello World...` oldu ve komut istemi hemen aynı satırın devamında, `Hello World...` yazısına bitişik olarak başladı (ekrandan, 00:15:00). Bunun nedeni, çıktıdan sonra yeni satıra geçileceğinin söylenmemiş olmasıdır. `printf("Hello World...\n");` yazılıp program yeniden derlenince mesaj yazıldı, alt satıra geçildi ve istem orada çıktı. Hoca, bütün çıktılarda bu tür ayrıntıları takip etmenin programcının sorumluluğunda olduğunu söyledi. Çıktılar düzgün olursa programın çalışıp çalışmadığı ve çıktının nereye gittiği daha kolay analiz edilir.

### 3.3 Komut geçmişi

Terminalde yukarı ve aşağı ok tuşlarıyla daha önce yazılan komutlar arasında gezilebilir. Böylece aynı komutu tekrar tekrar yazmak gerekmez.

Hoca yeniden derleme sonrasında `a.out` dosyasının değişme zamanının güncellendiğini gösterdi. Sanal makinenin saat ayarı kaymış olduğu için zaman yanlış görünüyordu, ama dosya bir önceki halinden daha yeniydi.

## 4. Faktöriyel Programı ve Derleyici Hata Mesajları

### 4.1 Programın tasarımı

İkinci örnek, daha önce akışı çizilen faktöriyel hesabıydı. Hoca, akışı çizilmiş programlardan gidince takibin daha kolay olacağını söyledi. Önceki dosya farklı adla (`fac.c`) kaydedildi ve içi boşaltıldı.

Akış hatırlandı: önce dışarıdan bir sayı okunur, sonra bir döngü içinde n'e kadar olan sayılar çarpıla çarpıla ilerlenir. Bu yüzden üç değişken gerekir:

- `n`: faktöriyeli hesaplanacak sayı.
- `i`: döngü değişkeni.
- `mul`: çarpımları tutan değişken (multiplication). Çarpma 1'den başlayacağı için tanımlanırken 1 ile ilklendirilir.

Hoca, değişkenlerin tanımlanırken ilklendirilebileceğini ve aynı satırda ya da ayrı satırlarda tanımlanmalarıyla ilgili bir kısıt olmadığını hatırlattı.

Kullanıcıya ne yapacağını bildiren bir mesaj yazdırıldı, sonra sayı okundu. Girilen sayı tamsayı olduğundan biçim `%d`'dir. Okumanın yapılabilmesi için değişkenin adresi verilir; bu yüzden `n`'nin önüne `&` konur.

### 4.2 Bloklar hakkında bir alışkanlık

`for`, `if` ve `while` için daha önce şu konuşulmuştu: gövdede tek bir işlem varsa süslü parantezle blok açmak zorunlu değildir. Hoca yine de hatayı önlemek ve alışkanlık olması için her seferinde blok açtığını, öğrencilerin de böyle yapmasının mantıklı olacağını söyledi.

### 4.3 Kod

Ekrana yazılan kod şuydu (ekrandan, 00:20:00):

```c
#include <stdio.h>

int main(void)  {

    int n, i, mul=1;

    printf("Please enter a number:");
    scanf("%d", &n);

    for(i = 1;i <= n; i++)  {
        mul = mul * i;
    }

    printf("%d! is equal to %d\n", n, mul);

    return 0;
}
```

### 4.4 İlk derleme hatası

`gcc fac.c` ile derlenince hata alındı. Klavyede yazarken dosyanın başına kendiliğinden bir `+` karakteri girmişti. Derleyicinin mesajları şunlardı (ekrandan, 00:20:00):

```text
fac.c:1:1: error: expected identifier or '(' before '+' token
    1 | +#include <stdio.h>
fac.c:1:2: error: stray '#' in program
    1 | +#include <stdio.h>
```

Hoca hata mesajının nasıl okunacağını anlattı. Mesaj hangi dosyada, kaçıncı satırda ve kaçıncı sütunda hata olduğunu söyler ve yeri işaretle gösterir. Bu örnekte hata tam bulunduğu yerde gösterildi. Ancak hatanın türüne bağlı olarak mesaj çok alakasız bir yerden de gelebilir; örneğin bir tanımlamada unutulan noktalı virgül, hatanın bambaşka bir satırda görünmesine yol açabilir.

Hata mesajları, derleyicinin fark ettiği ilk hatadan başlayarak yukarıdan aşağıya listelenir. Mesaj sayısı çok olunca alt alta takip edilemez hale gelebilir.

> **Hocanın vurgusu:** Hataya her zaman en baştan yaklaşılır. İlk hata mesajı nerede, ona bakılır; çünkü ilk hata büyük olasılıkla aşağıdaki başka hataların da sebebidir.

Fazladan karakter silindi, dosya kaydedildi ve program derlendi.

### 4.5 Çıktıya ad vermek

Yeni derlemeyle yine `a.out` oluştu ve eski `a.out`'un yerine geçti; eskisi silindi. Hoca, her programın adının `a.out` olmasının saçma bir yaklaşım olacağını söyledi. İki yol vardır: derledikten sonra dosyanın adını değiştirmek ya da derleme sırasında çıktının adını vermek. İkincisi `-o` seçeneğiyle yapılır (ekrandan, 00:25:00):

```text
gcc fac.c -o Fac
```

Oluşan `Fac` dosyası terminalde yeşil görünür, çünkü çalıştırılabilirdir. `a.out` ile boyutları aynıdır (16800 bayt), çünkü aynı programdır; yalnız adı farklıdır. Karışıklık olmasın diye `a.out` `rm a.out` ile silindi.

### 4.6 Programın denenmesi

`./Fac` çalıştırılıp 5 girildi (ekrandan, 00:25:00):

```text
Please enter a number:5
5! is equal to 120
```

Hoca sonucu elle kontrol etti: $5 \cdot 4 = 20$, $20 \cdot 3 = 60$, $60 \cdot 2 = 120$, $120 \cdot 1 = 120$.

Sonra döngünün başlangıcı 1'den 2'ye çekildi, çünkü 1'i 1 ile çarpmanın bir anlamı yoktur. Program yeniden derlendi ve aynı sonuç alındı.

Bu son hal ajan tarafından `gcc -Wall` ile derlenip 5 girdisiyle denendi; çıktı `5! is equal to 120` oldu.

> **Ders sonrası not:** Hoca programın 20 gibi bir değerin faktöriyelini de hesaplayacağını söyledi. Bu programda `mul` bir `int` olduğu için 12!'den büyük değerler doğru tutulamaz; ajan denemesinde 13 girildiğinde program yanlış bir sayı (1932053504) yazdı. Daha büyük değerler için daha geniş bir veri tipi gerekir.

### 4.7 Bütün uyarıları açmak

Hoca, şimdiye kadar yazılan programların sade olduğunu, ama yazarken hata yapmanın doğal olduğunu söyledi. Yalnız `gcc dosya.c` ile derlenirse derleyici bazı şüpheli durumları görmezden gelir. Bu yüzden tavsiyesi bütün uyarıları açmaktır:

```text
gcc -Wall fac.c -o Fac
```

Kodda uyarılacak bir şey yoksa derleyici bir şey söylemez. Alışılmışın dışında bir şey görürse hata değil uyarı verir. Hoca, özellikle yeni öğrenenler için bunun önemli olduğunu söyledi.

## 5. Newton Yöntemiyle Karekök

### 5.1 Gereken değişkenler

Üçüncü örnek, derslerde üzerinde çok konuşulan Newton yöntemiydi. Önceki dosya `newton.c` adıyla kaydedilip içi boşaltıldı. Hoca akışları hatırlatarak gereken değişkenleri tek tek çıkardı:

- `x`: karekökü bulunacak sayı, kullanıcıdan alınır.
- `th`: eşik (threshold). Yöntem iteratiftir; her iterasyonda yeni bir değer hesaplanır, eskisiyle arasındaki farka bakılır ve fark eşiğin altına inmediği sürece devam edilir. Eşik de kullanıcıdan alınır.
- `old` ve `new`: eski ve yeni değerler.
- `e`: eski ile yeni değer arasındaki fark (hata).
- `i`: çözümün kaçıncı adımda bulunduğunu izlemek (monitoring) için sayaç.

Okunan değerler gerçel olduğundan `float` kullanıldı ve `scanf` içinde `%f` yazıldı.

### 5.2 Algoritma

İlk tahmin 1'dir. Yeni değer Newton formülüyle hesaplanır:

$$\text{new} = \frac{\text{old} + \dfrac{x}{\text{old}}}{2}$$

Fark mutlak değerle hesaplanır: $e = |\text{new} - \text{old}|$. Hoca bunun nedenini hatırlattı: bir sonraki değerin eskisinden büyük mü küçük mü olacağı bilinmez.

Fark eşikten büyük olduğu sürece döngü sürer. Döngüde her adımda durum yazdırılır, `i` bir artırılır, eski değere yeni değer atanır, yeni değer aynı formülle tekrar hesaplanır ve fark yeniden bulunur.

### 5.3 İlk deneme ve uyarılar

Hoca formülü yazarken bir an `new = (old + new) / 2;` yazdı ve döngünün içi de henüz tamamlanmamıştı (ekrandan, 00:30:00). Derlemede iki uyarı alındı:

- `fabs` fonksiyonu için kütüphane eklenmemişti. Gerçel sayılar için mutlak değer veren `fabs`'i kullanmak için `#include <math.h>` gerekir. Derleyici önce uyarı verdi, sonra ne eklenmesi gerektiğini not olarak düştü.
- `-Wall` açık olduğu için derleyici yanlış formülü de yakaladı: `'new' is used uninitialized in this function` (ekrandan, 00:35:00). `new` daha değer almadan kullanılıyordu. Formül, Newton formülüne uygun haliyle düzeltildi.

> **Hocanın vurgusu:** Programın derlenmesi sorunsuz çalıştığı anlamına gelmez. Çalıştırıp gerçekten doğru çalıştığını kontrol etmek gerekir.

### 5.4 Biçimlenmemiş çıktı

İlk çalıştırmada (1024, eşik 0.0001) iterasyon satırlarında `\n` olmadığı için bütün izleme çıktısı tek bir yığın halinde basıldı (ekrandan, 00:35:00). Hoca, adım adım durumu bu halde takip etmenin çok zor olduğunu ve en başta söylediği şeyin bu olduğunu belirtti. `\n` eklendi ve program 1024 ile eşik 0.00001 için yeniden çalıştırıldı.

<!-- BELİRSİZ: Altyazıda hoca eşikleri 0.001 ve 0.0001 diye söylüyor; ekranda girilen değerler 0.0001 ve 0.00001'dir. Notta ekrandaki değerler kullanıldı. -->

### 5.5 Son kod

```c
#include <stdio.h>
#include <math.h>

int main(void)  {


    int i=1;
    float x, new, old, th, e;

    printf("Please enter a number : ");
    scanf("%f", &x);

    printf("Please enter threshold : ");
    scanf("%f", &th);

    old = 1;
    new = (old + x/old) / 2;
    e = fabs(new - old);

    while(e > th)  {

        printf("#%d > old : %f - new : %f - e : %f\n", i, old, new, e);
        i++;
        old = new;
        new = (old + x/old) / 2;
        e = fabs(new - old);
    }

    printf("Square root of %f is %f at iteration : %d\n", x, new, i);

    return 0;
}
```

Kod ekrandan alındı (ekrandan, 00:35:00; mesajlardaki `" : "` boşlukları 00:40:00 karesinden). Ajan tarafından `gcc -Wall newton.c -o newton -lm` ile derlenip ekrandaki girdilerle denendi; çıktılar ekrandakiyle birebir aynı çıktı.

### 5.6 1024 için iterasyonlar

Girdi: $x = 1024$, eşik $0.00001$ (ekrandan, 00:35:00).

```text
#1 > old : 1.000000 - new : 512.500000 - e : 511.500000
#2 > old : 512.500000 - new : 257.249023 - e : 255.250977
#3 > old : 257.249023 - new : 130.614807 - e : 126.634216
#4 > old : 130.614807 - new : 69.227325 - e : 61.387482
#5 > old : 69.227325 - new : 42.009586 - e : 27.217739
#6 > old : 42.009586 - new : 33.192490 - e : 8.817097
#7 > old : 33.192490 - new : 32.021423 - e : 1.171066
#8 > old : 32.021423 - new : 32.000008 - e : 0.021416
Square root of 1024.000000 is 32.000000 at iteration : 9
```

İlk adımı elle izlemek için (ara adım eklendi): $\text{new} = (1 + 1024/1)/2 = 512.5$, $e = |512.5 - 1| = 511.5$. Hoca sonucu "9. iterasyonda 32 bulundu, ilk iterasyon 512.5" diye okudu. 8. satırdaki yeni değer 32.000008'dir; döngü sonundaki 9. hesapta fark eşiğin altına iner ve sonuç 32.000000 yazılır.

### 5.7 4096 için deneme

Girdi: $x = 4096$, eşik $0.00001$ (ekrandan, 00:40:00).

```text
#1 > old : 1.000000 - new : 2048.500000 - e : 2047.500000
#2 > old : 2048.500000 - new : 1025.249756 - e : 1023.250244
#3 > old : 1025.249756 - new : 514.622437 - e : 510.627319
#4 > old : 514.622437 - new : 261.290833 - e : 253.331604
#5 > old : 261.290833 - new : 138.483429 - e : 122.807404
#6 > old : 138.483429 - new : 84.030487 - e : 54.452942
#7 > old : 84.030487 - new : 66.387352 - e : 17.643135
#8 > old : 66.387352 - new : 64.042923 - e : 2.344429
#9 > old : 64.042923 - new : 64.000015 - e : 0.042908
#10 > old : 64.000015 - new : 64.000000 - e : 0.000015
Square root of 4096.000000 is 64.000000 at iteration : 11
```

Ardından izleme satırı `//printf(...)` ile yoruma alındı ve program yalnız sonucu yazdı: `Square root of 4096.000000 is 64.000000 at iteration : 11` (ekrandan, 00:40:00).

### 5.8 İzleme satırındaki printf

Bir öğrenci, `while` döngüsündeki ilk `printf`'in içini anlamadığını yazdı.

**Soru:** Döngünün içindeki `printf` ne yapıyor?

**Cevap:** O `printf`'in tek amacı bilgi vermektir: her iterasyonda yeni değerin ne hesaplandığını, eskisinin ne olduğunu ve aradaki farkı takip edebilmek. Baştaki `#` tamamen görünüş içindir; çıktıda `#1`, `#2`, `#3` diye iterasyon numaraları görünür. İstenirse yerine "iteration number" gibi bir metin yazılabilir. `>` işareti de yalnız ayırmak içindir, yerine parantez konabilir. `%d` yerine iterasyon sayısı, her `%f` yerine sırasıyla bir değişkenin değeri gelir: `old`, `new` ve `e`. Aradaki `old :`, `new :`, `e :` etiketleri satırın okunur olması içindir; en sonda `\n` ile yeni satıra geçilir. Değişkenler biçim dizgesindeki sırayla verilir: `i, old, new, e`.

Hoca açıklamadan sonra biçimi değiştirip programı 144 ve eşik 0.001 ile çalıştırdı (ekrandan, 00:45:00):

```text
iteration number : 1) old : 1.000000 - new : 72.500000 - e : 71.500000
iteration number : 2) old : 72.500000 - new : 37.243103 - e : 35.256897
iteration number : 3) old : 37.243103 - new : 20.554796 - e : 16.688307
iteration number : 4) old : 20.554796 - new : 13.780231 - e : 6.774566
iteration number : 5) old : 13.780231 - new : 12.114992 - e : 1.665238
iteration number : 6) old : 12.114992 - new : 12.000546 - e : 0.114447
Square root of 144.000000 is 12.000000 at iteration : 7
```

Çıktının nasıl görüneceği tamamen `printf`'in içine ne yazıldığına bağlıdır.

## 6. Üçgenin Türünü Bulan Program

### 6.1 Akışın hatırlanması

Dördüncü örnek, kenarları verilen bir üçgenin türünü söyleyen programdı; akışı daha önce çizilmişti. Dosya `triangle.c` adıyla kaydedildi. Üç kenar için üç tamsayı değişken tanımlandı: `a`, `b`, `c`. Kullanıcıdan birinci, ikinci ve üçüncü kenar ayrı ayrı istendi. Hoca mesajları kopyala-yapıştır ile çoğalttı ve sonra her birini düzeltti (ekrandan, 00:45:00 ve 00:50:00).

Akıştaki mantık şuydu:

- Önce iki kenar karşılaştırılır. `a == b` ise üçgen ya eşkenar ya ikizkenardır.
  - Bu durumda `b == c` de doğruysa üç kenar eşittir: eşkenar.
  - Değilse ikizkenar.
- `a != b` ise `b == c` sorulur. Doğruysa ikizkenar.
- O da değilse son olarak `a == c` sorulur. Doğruysa yine ikizkenar.
- Hiçbir kenar diğerine eşit değilse çeşitkenar.

Hoca ilk yazarken bir dalda yanlışlıkla "eşkenar" yazdığını fark edip "ikizkenar" diye düzeltti; alıştığından farklı bir klavye kullandığını söyledi.

### 6.2 Kod

```c
#include <stdio.h>
#include <math.h>

int main(void)  {


    int a, b, c;

    printf("Please enter first dimension of the triangle : ");
    scanf("%d", &a);

    printf("Please enter second dimension of the triangle : ");
    scanf("%d", &b);

    printf("Please enter third dimension of the triangle : ");
    scanf("%d", &c);

    if(a == b)  {
        if(b == c) {
            printf("eskenar ucgen...\n");
        } else {
            printf("ikizkenar ucgen...\n");
        }
    } else {
        if(b == c) {
            printf("ikizkenar ucgen...\n");
        } else {
            if(a == c)  {
                printf("ikizkenar ucgen...\n");
            } else {
                printf("cesitkenar ucgen...\n");
            }
        }
    }

    return 0;
}
```

Kod ekrandan alındı (ekrandan, 00:50:00). Hoca daha sonra `math.h`'nin bu programda gereksiz yere eklendiğini, bunun fazla kopyala-yapıştırın bir sonucu olduğunu söyledi. Ajan `math.h` satırı olmadan derleyip denedi; sonuç değişmedi.

### 6.3 Derleme ve deneme

`gcc -Wall triangle.c -o Triangle` ile derlendi. Hoca, bütün uyarılar açıkken bir hata çıkmasını beklediğini, ama sözdizimi hatası olmadığını söyledi. Sözdizimsel hata yoksa sıra mantık hatası olup olmadığını kontrol etmeye gelir. Denenen girdiler (ekrandan, 00:50:00):

| a | b | c | Çıktı |
|---|---|---|---|
| 3 | 4 | 5 | çeşitkenar |
| 6 | 6 | 6 | eşkenar |
| 4 | 4 | 5 | ikizkenar |
| 3 | 4 | 4 | ikizkenar |

Hoca olası kombinasyonların bir kısmının denendiğini ve hiçbirinde sorun çıkmadığını söyledi. Ajan ayrıca `a == c` dalını sınayan 4 5 4 girdisini denedi; çıktı ikizkenar oldu.

### 6.4 Geçerlilik kontrolü

Bir soru üzerine hoca, bu aşamada girilen değerlerin üçgen oluşturup oluşturmadığının kontrolünü beklemediğini söyledi. Örneğin 1, 1, 15 ya da 3, 5, 27 kenarlarının bir üçgen olup olmadığı kontrol edilmiyor. Gerçek hayatta bunların hepsini kontrol etmek gerekir, ama şu an amaç ana soruna yönelmektir.

> **Ek bilgi (derste anlatılmadı):** Üç uzunluğun bir üçgen oluşturması için her kenarın diğer ikisinin toplamından küçük olması gerekir (üçgen eşitsizliği). 1, 1, 15'te $1 + 1 < 15$ olduğu için bu kenarlar üçgen oluşturmaz.

## 7. Dizinin Ortalaması

### 7.1 Gerekenler

Son örnek, verilen bir dizinin ortalamasını bulan programdı. Dosya `average.c` adıyla kaydedildi. Hoca birkaç kavramın burada bir arada kullanılacağını söyledi ve gerekenleri sıraladı:

- n elemanlı bir dizi.
- Dizinin elemanları üzerinde `for` döngüsüyle ilerlemek için bir döngü değişkeni.
- Ortalamayı tutacak, ilklendirilmiş bir `avg` değişkeni.

Dizinin kaç elemanlı olacağı program yazılırken bilinmez; çalışma zamanında, kullanıcı boyutu girdikten sonra öğrenilir. Ama dizinin o zamana kadar tanımlanmış olması gerekir. Bu yüzden kullanıcının gireceğinden büyük olduğu düşünülen sabit boyutlu bir dizi tanımlanır. Boyut dinamik olarak da belirlenebilir, ama bunun için dinamik bellek ayırmanın öğrenilmiş olması gerekir. O zamana kadarki genel varsayım şudur: belli büyüklükte bir dizi vardır ve dışarıdan girilen eleman sayısı bu boyuttan çok daha küçüktür.

### 7.2 İlk sürüm ve mantık hatası

İlk sürümde dizi `int ar[100];` diye tanımlandı. Birinci döngü elemanları okudu, ikinci döngü topladı (ekrandan, 00:55:00). Program 5 eleman ve 1, 2, 3, 4, 5 ile denenince sonuç `15.000000` çıktı (ekrandan, 01:00:00). Hoca hatayı buldu: bütün elemanlar `avg`'ye toplanmış, ama sonunda n'e bölünmemişti. `avg /= n;` eklenince sonuç `3.000000` oldu.

### 7.3 Döngü değişkeninin 0'dan başlaması

Hoca kodu tartışmaya açtı. Akış diyagramlarında döngü değişkeni hep 1'den başlatılmıştı; burada iki döngü de 0'dan başlatıldı. Nedeni şudur: akış programlama dilinden bağımsız bir ortamdır, C ise kendi kuralları olan bir programlama dilidir. C'de dizinin elemanları 0'dan başlar; 0. indise ulaşabilmek için döngü 0'dan başlatılır.

Döngüyü 1'den başlatıp indis üzerinde hesap yapmak da mümkündür, ama gereksizdir. Önemli olan, akışta 1'den n'e kadar çizilen yapının C'ye ona uygun biçimde aktarılmasıdır:

- Akışta 1'den n'e gidilince toplam n adım atılır.
- C'de `i` 0'dan başladığı için koşul `i < n` olur. `i` n olduğunda döngüden çıkılır; işlem son kez `n-1` için yapılır. 0'dan başlandığı için yine toplam n adım atılmış olur.

### 7.4 Sabitler için makro

Kodun içinde `100` gibi sabitlerin bulunması istenmez. Bunun yerine kodun başında bir makro tanımlamak her zaman daha iyidir: `#define MAX_SIZE 100`. Böylece bu değer kodun başka yerlerinde de kullanıldığında ve sonra değiştirilmesi gerektiğinde tek bir noktadan değiştirilir ve bakımı tek noktadan yapılır.

### 7.5 Son kod

```c
#include <stdio.h>

#define MAX_SIZE 100

int main(void)  {


    int i, n;
    int ar[MAX_SIZE];
    float avg = 0.0;

    printf("Please enter number of elements : ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Please enter %d. element : ", i+1);
        scanf("%d", &ar[i]);
    }

    for(i = 0; i < n; i++) {
        avg += ar[i];
    }

    avg /= n;

    printf("Average value of the elements is %f\n", avg);

    return 0;
}
```

Kod ekrandan alındı (ekrandan, 01:00:00; `i+1` değişikliği 01:05:00). Ajan tarafından `gcc -Wall` ile derlenip denendi: 1..5 için `3.000000`, 1..10 için `5.500000`; ekrandaki sonuçlarla aynı.

Hoca 10 eleman ve 1'den 10'a kadar sayılarla da denedi; sonuç `5.500000` oldu (ekrandan, 01:00:00). Kontrol (ara adım eklendi): $\frac{1+2+\dots+10}{10} = \frac{55}{10} = 5.5$.

## 8. Ortalama Programı Üzerine Sorular

### 8.1 0.0 mı, 0 mı?

**Soru:** `avg` neden `0.0` ile ilklendirildi? `float avg = 0;` yazılsa olmaz mı?

**Cevap:** Olur. `avg` bir `float` değişkendir; 0 atansa da değeri otomatik olarak 0.0 olur. Teknik olarak sonuçta bir fark yoktur. Hoca, veri tiplerinin bir arada kullanılmasıyla ilgili sunumdaki hiyerarşiyi hatırlattı: en altta `int` vardır ve tip `long double`'a kadar yükselir. `avg = 0` yazılınca derleyiciye bir tamsayıyı `float`'a atanacağı söylenir; derleyici değeri önce üst tipe çevirir. `0.0` yazılınca ise sağ taraf zaten gerçel bir sabittir; aslında `double` olarak görülür ve `float`'a atanırken hassasiyet nedeniyle yine dönüştürülür. Hoca bunun üzerinde takılınacak bir nokta olmadığını söyledi.

**Soru:** Gerçel sabitler `float` mı, `double` mı?

**Cevap:** C'nin spesifikasyonu, gerçel sabit değerleri `double` kabul eder. Bu yüzden böyle bir sabit `float` bir değişkene atanırken daha alt tipe indirilir. Bir derleyicinin uygulamaya özgü olarak sabitleri `float` tutması ayrı bir konudur ve bu dersi ilgilendirmez.

> **Ek bilgi (derste anlatılmadı):** C'de bir gerçel sabitin sonuna `f` eklenirse (`0.0f`) sabit `float` tipinde olur. Eki olmayan `0.0` ise `double`'dır.

### 8.2 Neden iki ayrı for döngüsü?

**Soru:** Neden iki farklı `for` döngüsü kullanıldı?

**Cevap:** Birinci döngü diziyi okur, ikinci döngü ortalamayı hesaplar (aslında yalnız toplamayı yapar). Bu iki iş akışta da birbirinden ayrı çizilir. Diziyi tek tek okurken toplama da aynı döngüde yapılabilir. Ancak girdi her zaman böyle tek tek gelmez; bir cihazdan ya da dosyadan toplu (bulk) okuma yapılıyor olabilir. Böyle bir durumda işi tek tek adımlarla birleştirmek zaman kazandırmaz, tersine kaybettirir. Hoca, ayrı yazmanın edinilmesi gereken bir alışkanlık olduğunu söyledi.

### 8.3 Kullanıcıya 1'den başlayan sıra göstermek

Bir öğrenci, ekranda "0. eleman" diye sorulmasıyla ilgili sordu. Hoca soruyu, kullanıcıya gösterilen sıranın 1'den başlaması olarak anladı: `printf` içinde `i` yerine `i+1` yazılırsa ekranda birinci, ikinci, ..., beşinci eleman diye sorulur (ekrandan, 01:05:00). Dizi indisi değişmez; okuma yine `&ar[i]`'ye yapılır.

### 8.4 main içindeki void

**Soru:** `main` içindeki `void` yazılmasa ne olur?

**Cevap:** `printf` bir fonksiyondur ve parantez içinde parametre alır: bazen yalnız bir biçim dizgesi, bazen biçim dizgesi ve içindeki biçim belirteçlerine karşılık gelen değişkenler. `main`'e de benzer biçimde parametre aktarılabilir, ama bunun ne zaman ve nasıl yapıldığı şu anın konusu değildir. Parametre aktarılmayacaksa makul olan `void` yazmaktır. `void` hiç yazılmazsa derleyici orayı `void` kabul edip devam eder. Hoca `void`'u silip programı yeniden derledi ve çalıştırdı; sonuç değişmedi.

## 9. Değişken Boyutlu Dizi Sorusu

Bir öğrenci, önce kullanıcıdan n değerini alıp sonra diziyi n boyutunda tanımlamanın mümkün olup olmadığını sordu. Hoca soruyu ayrı bir dosyada gösterdi (ekrandan, 01:10:00):

```c
#include <stdio.h>

int main()  {

    int i, n;

    scanf("%d", &n);

    int ar[n];
    float avg = 0.0;


    return 0;
}
```

**Soru:** n kullanıcıdan alındıktan sonra `int ar[n];` diye tanımlanabilir mi?

**Cevap:** Hayır. Hoca, bunun C'nin çalışma prensibine aykırı olduğunu, çalıştığını iddia eden arkadaşlara inanılmaması gerektiğini söyledi. İki nedeni var:

- Bir fonksiyonun içinde takip edilebilirlik ve anlaşılabilirlik için önce değişkenler tanımlanır, sonra deyimler yazılır. Bir deyimden sonra değişken tanımlamaya kalkmak sorundur.
- n değeri çalışma zamanında alınır, ama dizinin boyutunun derleme sırasında belli olması istenir. Hocaya göre standart C bunu desteklemez; çalışıyor gibi görünse de yanlış çalışır. Yapılmaması gereken birkaç şey art arda yapılırsa, örneğin C programı bir C++ programıymış gibi derlenirse çalışır, ama dersin derdi bu değildir.

Hoca bunun ayrıntısının yapısal programlama dersinde ya da uygun bir zamanda anlatılacağını söyledi. Bu tür bir tanımlamayı, işin geri kalanı ne olursa olsun, en temel şeyin anlaşılmadığının işareti olarak gördüğünü belirtti.

> **Ders sonrası not:** Hocanın "standart C desteklemez" ifadesi C89/C90 için doğrudur: ajan denemesinde `gcc -std=c89 -pedantic` hem "ISO C90 forbids variable length array" hem de "ISO C90 forbids mixed declarations and code" uyarısını verdi. Ancak C99 değişken uzunluklu dizileri büyük olasılıkla standarda eklemiştir; aynı kod `gcc -std=c99` ile derlenip doğru çalıştı. "C++ gibi derlenirse çalışır" ifadesi de tam doğru değildir: standart C++ bunu kabul etmez, g++ "ISO C++ forbids variable length array" uyarısı verir ve bunu yalnız bir eklenti olarak destekler. Ders kuralı ise değişmez: bu derste dizi boyutu `MAX_SIZE` gibi sabit olarak verilir.

### 9.1 For döngüsü nereden başlar?

**Soru:** C'de `for` döngüsü nereden başlar?

**Cevap:** Böyle bir soru olmaz; `for` döngüsü istenen yerden başlar, istenirse 15000'den başlar. 0'dan başlayan, dizilerin indisidir. Bu yüzden döngü içinde diziyle bir şey yapılıyorsa döngü dizi indislerine uygun biçimde başlatılır ve sürdürülür.

> **Hocanın vurgusu:** C'de döngüler istenen yerden başlar, istenen yere gider. Dizilerin indisi ise 0'dan başlar. Diziyle bir şey yapılacaksa `for` döngüsü buna göre kurulur.

Hoca bu soru üzerine kavramların doğru ve yerinde kullanılmasının önemini vurguladı. Sorular parça parça değil, tam ve net bir mantık sırası içinde sorulmalıdır. Sonraki derslerde ve profesyonel hayatta, altında birden fazla şeyi ifade eden karmaşık kavramlarla anlaşılacaktır; bir kavramı yanlış kullanmak karşı tarafla birbirini yanlış anlamak demektir ve bu bir kar topu gibi büyüyerek saçma durumlara yol açabilir.

## 10. Laboratuvar Sonrası Çalışma

Hoca, artık bir akışta kullanılan bütün sembollerin (`for`, `while` ve kontrol yapıları) C'de nasıl uygulandığının görüldüğünü söyledi. Veri tipinin ve değişkenin nasıl tanımlanacağı, `main` fonksiyonunun nasıl yazılacağı ve programın nasıl derlenip çalıştırılacağı da konuşulmuştu. Bundan sonra yapılması gereken, şimdiye kadar çizilen bütün akışları alıp C koduna çevirmek, derlemek, çalıştırmak, hataları görmek, düzeltmeye uğraşmak ve takılınan yerde soru sormaktır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:20:00) Bir sayının faktöriyelini hesaplayan C programını yazın. Kullanıcıdan `n` okunacak, çarpım bir döngüde hesaplanacak ve `n! is equal to ...` biçiminde yazdırılacak.

> **Çözüm (derste verildi):** Bölüm 4.3'teki kod. 5 için çıktı `5! is equal to 120`.

**Soru 2** (ekrandan, 00:35:00) Newton yöntemiyle, kullanıcının girdiği bir sayının karekökünü ve eşik değerini alarak sonucu ve kaçıncı iterasyonda bulunduğunu yazdıran programı yazın. 1024 ve eşik 0.00001 için sonuç nedir?

> **Çözüm (derste verildi):** Bölüm 5.5'teki kod. Çıktı `Square root of 1024.000000 is 32.000000 at iteration : 9`. 144 ve eşik 0.001 için `12.000000`, 7. iterasyon.

**Soru 3** (ekrandan, 00:50:00) Kenar uzunlukları girilen bir üçgenin eşkenar, ikizkenar ya da çeşitkenar olduğunu söyleyen programı yazın. 3 4 5, 6 6 6, 4 4 5 ve 3 4 4 için çıktılar nedir?

> **Çözüm (derste verildi):** Bölüm 6.2'deki kod. Sırasıyla çeşitkenar, eşkenar, ikizkenar, ikizkenar.

**Soru 4** (ekrandan, 01:00:00) Eleman sayısı ve elemanları kullanıcıdan okunan bir tamsayı dizisinin ortalamasını bulan programı yazın. 1, 2, ..., 10 için sonuç nedir?

> **Çözüm (derste verildi):** Bölüm 7.5'teki kod. Sonuç `5.500000`. İlk sürümde `avg /= n;` unutulduğunda 1..5 için 15 çıktığını hatırlayın.

**Soru 5** (derste sözlü, 00:58:24) `float avg = 0.0;` yerine `float avg = 0;` yazılırsa ne değişir?

> **Cevap (derste verildi):** Sonuç değişmez; iki durumda da `avg` 0.0 olur. `0` bir tamsayı sabitidir ve `float`'a dönüştürülür; `0.0` ise `double` bir sabittir ve `float`'a atanırken dönüştürülür.

**Soru 6** (derste sözlü, 01:08:24) Kullanıcıdan n okunduktan sonra `int ar[n];` tanımlaması bu derste kullanılabilir mi?

> **Cevap (derste verildi):** Hayır. Dizi boyutu derleme zamanında belli olmalıdır ve değişkenler deyimlerden önce tanımlanmalıdır. Bu derste sabit boyut (`#define MAX_SIZE 100`) kullanılır. (Standartlarla ilgili ayrıntı için Bölüm 9'daki ders sonrası nota bakın.)

## Dersin Toparlaması

Bu laboratuvarda C programlamaya ilk adım atıldı. Ubuntu üzerinde gedit ile dosya yazmak, `.c` uzantısı vermek, `gcc` ile derlemek, `./` ile çalıştırmak, `-o` ile çıktıya ad vermek ve `-Wall` ile bütün uyarıları açmak görüldü. `main` fonksiyonunun yapısı, `return 0`'ın anlamı ve `return` ile `exit` farkı konuşuldu. Derleyici hata mesajlarının ilk hatadan başlayarak okunması gerektiği gösterildi.

Ardından daha önce akış diyagramı çizilen dört problem C'ye aktarıldı: faktöriyel, Newton yöntemiyle karekök, üçgenin türü ve dizinin ortalaması. Bu aktarımda akış ile C arasındaki en önemli fark olarak dizi indislerinin 0'dan başlaması ve döngünün buna göre `i = 0; i < n` biçiminde kurulması vurgulandı. Sabitlerin makroyla tanımlanması, çıktıların `\n` ve etiketlerle okunur hale getirilmesi, derlenen programın mutlaka çalıştırılıp denenmesi ve dizi boyutunun derleme zamanında sabit olması gerektiği üzerinde duruldu. Öğrencilerden, şimdiye kadar çizilen bütün akışları C'de yazıp denemeleri istendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
