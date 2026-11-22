# Ders 17 Genişletilmiş Notu: Uygulama 3: Matris İşlemleri, Tekrar Eden Elemanlar, Toplamı Sıfır Alt Dizi ve En Uzun Ardışık Dizi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Uygulama oturumunun düzeni
- 2. Soru 1: Matris operasyonları
- 3. Soru 2: Dizide tekrar eden elemanların atılması
- 4. Soru 3: Toplamı sıfır olan alt dizi
- 5. Soru 4: Dizideki en uzun devamlı dizi
- Örnek Sorular
- Dersin Toparlaması

## 1. Uygulama oturumunun düzeni

Bu kayıt dersin üçüncü uygulama oturumudur; slayt dosyasının adı "uygulama 3"tür (ekrandan, 00:10:00). Oturumun konusu matrislerde ve dizilerde gezinme, diziler üzerinde değişiklik yapma ve fonksiyonlara dizi göndermektir. Fonksiyondan dizi "almaya çalışma" da konuya dahil edildi, çünkü C'de bu tam olarak yapılamaz. Dört soru çözüldü. Plana göre ilk soru basit olduğu için doğrudan çözülecek, sonraki sorularda öğrencilere birkaç dakika düşünme süresi verilecekti; zaman darlığı yüzünden ikinci soruda bu süre verilmedi, üçüncü ve dördüncü soruda kısa bir süre tanındı. Bütün kodlar Dev-C++ üzerinde yazıldı ve çalıştırıldı.

Laboratuvarlarda girdilerin kullanıcıdan alınması istenir; burada zaman kısıtı nedeniyle matrisler ve diziler tanım sırasında başlangıç değeriyle verildi. Dinamik bellek ayırma henüz işlenmediği için bütün diziler sabit boyutla tanımlandı.

## 2. Soru 1: Matris operasyonları

### 2.1 Slayttaki soru

Slayttaki ilk soru şudur (ekrandan, 00:10:00):

- Matris operasyonları
  - İki matrisin toplamı
  - İki matrisin çarpımı
  - İki matrisin iç çarpımı
  - Matrisin normalizasyonu (Min-Max Scaling)

Slaytta ayrıca bir iç çarpım şekli ve normalizasyon formülü vardır. Şekilde $3\times 2$'lik $\begin{bmatrix} A & B \\ C & D \\ E & F \end{bmatrix}$ matrisi $\begin{bmatrix} G \\ H \end{bmatrix}$ sütunuyla çarpılır ve sonuç $\begin{bmatrix} A\times G + B\times H \\ C\times G + D\times H \\ E\times G + F\times H \end{bmatrix}$ olur. Formül:

$$X_{new} = \frac{X_i - \min(X)}{\max(X) - \min(X)}$$

Main'de iki matris aynı değerlerle tanımlandı (ekrandan, 00:10:00):

```c
int m_One[3][3]={{1,2,3},{4,5,6},{7,8,9}};
int m_Two[3][3]={{1,2,3},{4,5,6},{7,8,9}};
```

### 2.2 Sonuç nerede tutulacak?

Toplama için iki matristen başka bir de sonucu tutacak yer gerekir. İki yol anlatıldı. Birincisi, gönderilen iki matristen birinin üzerine yazmaktır; matris fonksiyona adres olarak gittiği için sonuç main'de aynı değişkenden okunabilir. Ama bu, işleme katılan elemanları değiştirdiği için tercih edilmedi. İkinci yol, main'de bir sonuç matrisi tanımlayıp onu diğer iki matrisle birlikte parametre olarak göndermektir.

Burada değişkenlerin kapsamı (scope) da hatırlatıldı: main'de tanımlanan bir değişkene fonksiyonun içinden, fonksiyonda tanımlanan bir değişkene de main'den erişilemez. Dinamik bellek kullanılsaydı sonuç fonksiyonun içinde ayrılıp döndürülebilirdi. Sonuç matrisini parametre olarak göndermek bu ikisinin orta noktasıdır.

> **Hocanın vurgusu:** Global değişken bu sorunun bir çözümüdür ama kullanılmaz. İleride kullanılacak çok iş parçacıklı (multithreading) programlarda global değişkenler kontrolü imkânsız hâle getirir. Bölüm olarak global değişkenlere ve `break`'e karşı olunduğu, ödevlerde ve lablarda ikisinden de kaçınılması gerektiği söylendi.

Fonksiyonun dönüş tipi soruldu. Bir öğrenci "dizi" dedi; sohbetten gelen doğru cevap `void` oldu. Sonuç zaten parametreyle geldiği için bir şey döndürmeye gerek yoktur. Ayrıca bu biçimde (`int m[3][3]`) tanımlanmış bir matrisin C'de fonksiyondan döndürülemediği, dinamik bellek ayırmayla bunun mümkün olduğu söylendi.

Fonksiyonlar bu grupta henüz ayrıntılı işlenmemişti; bu yüzden kısaca anlatıldı: main de bir fonksiyondur. Fonksiyon çağrıldığında program başka bir kod parçasına gidip orada çalışır; o parçanın değişkenleri main'inkilerden farklıdır, ama iletişim parametreler ve dönüş değeriyle kurulur ve işleyiş yine sıralıdır.

### 2.3 İki matrisin toplamı

Matrisler fonksiyona boyutlarıyla gönderilir. Derste, bu tarz tanımlanmış matrislerde derleyicinin sütun sayısını yeterli bulduğu, ama hepsinin yazıldığı söylendi. Fonksiyon başlığı (ekrandan, 00:15:00):

```c
void sum(int colLength,int rowLength,int mOne[rowLength][colLength],int mTwo[rowLength][colLength],int Res[rowLength][colLength]){
```

Matris iki boyutludur; dizide bir indis yeterken matriste iki indis (`i`, `j`) gerekir. Bütün elemanlar gezileceği için `for` döngüsü kullanılır; durma koşulu matrisin boyudur. Satırlarda `i`, sütunlarda `j` ile gezilir (ekrandan, 00:20:00):

```c
    int i,j;

    for(i=0;i<rowLength;i++){
        for(j=0;j<colLength;j++){
            Res[i][j]=mOne[i][j]+mTwo[i][j];
        }
    }
}
```

Dönüş değeri olmadığı için fonksiyon döngüler bitince sona erer. Main'de `sum(3,3,m_One,m_Two,Result);` ile çağrılır ve sonuç iki iç içe döngüyle yazdırılır. Ajanın denemesinde çıktı `2 4 6 / 8 10 12 / 14 16 18` oldu.

`stdlib.h` her dosyaya alışkanlıkla eklendi: çok kullanılan fonksiyonların bulunduğu bir kütüphanedir ve burada gerekmese de eklemenin bir zararı yoktur.

### 2.4 Aynı toplam işaretçiyle

Gruplardan birinin işaretçileri henüz görmediği anlaşıldı, ama aynı toplamın işaretçili bir sürümü de gösterildi. Dizi zaten bir işaretçidir; matrisi fonksiyona `int *` olarak gönderip bellek üzerinde hesapla gezmek mümkündür. Parametredeki `*` işaretçi demektir: bellekteki bir adresi gösterir ve o adresteki değere erişilebilir. İşaretçiler doğrudan belleğe eriştiği için, değişken kapsamı yüzünden ulaşılamayan bir değere de işaretçiyle ulaşılabilir. Bu yüzden çok kullanılan, popüler ve zor bir konu olduğu söylendi.

İşaretçi bir tam sayı (adres) olduğu için üzerinde basit aritmetik yapılarak bellekte ilerlenebilir. Matrisin elemanları bellekte satır satır arka arkaya dizilir: önce `1 2 3`, hemen yanında `4 5 6`, onun yanında `7 8 9`. İşaretçi ilk elemanı (1) gösterir. Sütunda ilerlemek için adrese `j` eklenir: `j=0` ilk elemanı, `j=1` ikinciyi, `j=2` üçüncüyü gösterir. Bir satır aşağı inmek için sütun sayısı kadar atlamak gerekir; bu yüzden `i*colLength` eklenir. Derste önce `rowLength` yazıldı, sonra "sütun sayısı kadar atlaması gerekiyor" denerek `colLength` olarak düzeltildi. Ekrandaki satır (ekrandan, 00:25:00):

```c
void sum_Alt(int colLength,int rowLength,int *mOne,int *mTwo,int *Res){
    int i,j;

    for(i=0;i<rowLength;i++){
        for(j=0;j<colLength;j++){
            *((Res+i*colLength)+j)
```

Satırın sağ tarafı karede görünmüyor; anlatıma göre aynı adres hesabı `mOne` ve `mTwo` için de yapılır:

```c
            *((Res+i*colLength)+j)=*((mOne+i*colLength)+j)+*((mTwo+i*colLength)+j);
```

Adres hesabı yapılırken değiştirilmek istenen adresin kendisi değil, gösterdiği değerdir. Değere `*` ile erişilir. `*` konmayan yerde adres değeri kullanılır; `*` koyulduğu anda adresin içindeki değer kullanılır. `*` en dışa, bütün adres işlemlerinden sonra konur. Örneğin `*` yanlış yere, `Res`'in hemen önüne konsaydı, hesap bellekteki "bir milyonuncu adres" gibi bir adres üzerinden değil, o adresteki değer (1) üzerinden yapılırdı.

Program çalıştırıldığında aynı sonuçlar elde edildi.

> **Ek bilgi (derste anlatılmadı):** Main'de `int m_One[3][3]` matrisi `int *` parametresine doğrudan verilirse derleyici tür uyuşmazlığı uyarısı verir, çünkü matrisin adı `int (*)[3]` türündedir. Ajanın denemesinde çağrı `sum_Alt(3,3,&m_One[0][0],&m_Two[0][0],&Result[0][0]);` biçiminde yazıldı ve `gcc -Wall` uyarısız derledi. Derste çağrının nasıl yazıldığı karede görünmüyor.

### 2.5 İki matrisin çarpımı

Toplamın aynısıdır; yalnız işlem eleman eleman çarpmadır (ekrandan, 00:30:00):

```c
void mul(int colLength,int rowLength,int mOne[rowLength][colLength],int mTwo[rowLength][colLength],int Res[rowLength][colLength]){

    int i,j;

    for(i=0;i<rowLength;i++){
        for(j=0;j<colLength;j++){
            Res[i][j]=mOne[i][j]*mTwo[i][j];
        }
    }
}
```

Sonuç `1 4 9 / 16 25 36 / 49 64 81` çıktı.

### 2.6 İki matrisin iç çarpımı

İç çarpımın ne olduğu soruldu ve slayttaki şekille anlatıldı: bir matrisin bir satırındaki elemanlar ($A$, $B$) diğer matrisin sütunundaki elemanlarla ($G$, $H$) sırayla çarpılır, bu çarpımların toplamı sonucun bir elemanı olur. Aynısı $C, D$ satırıyla yapılır: $C\times G + D\times H$.

**Soru:** Bu işlem matris çarpımı diye bilinmiyor mu; yukarıda yapılan yalnız elemanları çarpmak değil mi? **Cevap:** Bir anlam karışıklığı olduğu kabul edildi. İngilizcesinin "dot product" olarak bilindiği, Türkçesine çeviriden bakıldığı ve yanlış olabileceği söylendi.

> **Ders sonrası not:** Derste "çarpım" denen ve `Res[i][j]=mOne[i][j]*mTwo[i][j]` ile yapılan işlem eleman eleman çarpımdır (Hadamard çarpımı). "İç çarpım" diye yazılan işlem ise olağan matris çarpımıdır; öğrencinin söylediği gibi "matris çarpımı" adı bu işleme aittir. İç çarpım (dot product) iki vektör arasındaki işlemdir; matris çarpımında sonucun her elemanı bir satır ile bir sütunun iç çarpımıdır.

Burada farklı bir durum vardır: birinci matrisin satırı boyunca ve ikinci matrisin sütunu boyunca adım adım ilerlemek gerekir. Bu yüzden üçüncü bir indise (`k`) ihtiyaç vardır. Çarpımların toplamı için `tmpSum` değişkeni tanımlandı. Derste kare matrislerle çalışıldı; boyutların farklı olabilmesi için bir değişken daha ekleyip sınırları değiştirmenin yeterli olduğu, mantık aynı kaldığı için bunun yapılmadığı söylendi.

Kod ilk yazıldığında "Bu çalışır mı?" diye soruldu. Öğrenciler iki hata buldu: `k`'li `for` satırında noktalı virgül yerine virgül konmuştu ve `tmpSum`'a ilk değer verilmemişti. `tmpSum`'ın nerede sıfırlanacağı soruldu; doğru cevap "`j`'nin her artışında" oldu, çünkü sonucun her elemanı için toplamın sıfırdan başlaması gerekir. Son hâli (ekrandan, 00:35:00):

```c
void dot(int colLength,int rowLength,int mOne[rowLength][colLength],int mTwo[rowLength][colLength],int Res[rowLength][colLength]){
    int i,j,k;
    int tmpSum;
    for(i=0;i<rowLength;i++){
        for(j=0;j<colLength;j++){
            tmpSum=0;
            for(k=0;k<rowLength;k++){
                tmpSum+=mOne[i][k]*mTwo[k][j];
            }
            Res[i][j]=tmpSum;
        }
    }
}
```

Sonucun kontrol edildiği ve doğru olduğu söylendi. Ajanın denemesinde `1..9` matrisinin kendisiyle çarpımı `30 36 42 / 66 81 96 / 102 126 150` çıktı ve python ile doğrulandı.

### 2.7 Matrisin normalizasyonu

Normalizasyon, verinin ölçeğini değiştirmektir; veri madenciliği ve yapay zekâ konularında kullanılır. Farklı türleri vardır. Bir türde ortalama çıkarılıp standart sapmaya bölünür; böylece ortalaması 0, standart sapması 1 olan bir veri elde edilir. Min-Max Scaling ise bütün veri setini 0 ile 1 arasına taşır. Formüldeki $\min$ verideki en küçük, $\max$ en büyük sayıdır.

Yapılışında farklılıklar olabilir: işlem bütün veriye, yalnız sütun bazında ya da yalnız satır bazında uygulanabilir; bu veri setine göre değişir. Sütun sütun ayrılmış bir veri setinde yalnız sütun bazında yapılabilir.

**Soru:** Bu bir filtre mi? **Cevap:** Hayır, filtreler farklıdır. Örneğin bir resmin değerleri 0 ile 255 arasındadır; resim yapay sinir ağı gibi bir işleme sokulacaksa değerlerin 0 ile 1 arasında olması daha iyidir. Normalizasyon bunu sağlar.

Sonuçlar 0 ile 1 arasında olacağı için `float` çıkar; bu yüzden sonuç matrisi `float` tanımlandı (ekrandan, 00:40:00):

```c
void Norm(int colLength,int rowLength,int mOne[rowLength][colLength],float Res[rowLength][colLength]){
```

En küçük ve en büyük değeri bulmak için iki ayrı fonksiyon yazmak yerine bir `mode` parametresi alan tek bir fonksiyon yazıldı. Değişkenin adı `currMax` olsa da en küçük değer için de kullanılır. Başlangıç değeri olarak en büyük/en küçük int sabitleri kullanılabileceği, ama matrisin herhangi bir elemanını vermenin de aynı kapıya çıktığı söylendi (ekrandan, 00:40:00):

```c
int minMax(int colLength,int rowLength,int mOne[rowLength][colLength],int mode){
    int i,j;
    int currMax=mOne[0][0];
    for(i=0;i<rowLength;i++){
        for(j=0;j<colLength;j++){
            if(mode==0){
                if(currMax<mOne[i][j])
                    currMax=mOne[i][j];
            }else{
                if(currMax>mOne[i][j])
                    currMax=mOne[i][j];
            }

        }
    }

    return currMax;

}
```

`mode==0` en büyük, diğer değer en küçük sayıyı bulur. `Norm` fonksiyonunda `min` `minMax(...,1)` ile, `max` `minMax(...,0)` ile bulundu ve her eleman formüle göre hesaplandı. Program ilk çalıştırıldığında yanlış sonuç verdi. Önce sonucun `%d` ile yazdırıldığı fark edildi; `float` matris `%f` ile yazdırılmalıdır. Düzeltmeden sonra da sonuç yanlıştı; bir öğrenci nedeni buldu: işlemdeki bütün değerler `int` olduğu için tam sayı bölmesi yapılıyordu. İşlemin başına `(float)` dönüşümü eklenince bölme ondalıklı yapıldı.

`Norm`'un gövdesi karelerde görünmüyor; aşağıdaki sürüm anlatıma göre kurulmuş ve `gcc -Wall` ile denenmiştir:

```c
void Norm(int colLength,int rowLength,int mOne[rowLength][colLength],float Res[rowLength][colLength]){
    int i,j;
    int min,max;
    min=minMax(colLength,rowLength,mOne,1);
    max=minMax(colLength,rowLength,mOne,0);
    for(i=0;i<rowLength;i++){
        for(j=0;j<colLength;j++){
            Res[i][j]=(float)(mOne[i][j]-min)/(max-min);
        }
    }
}
```

`1..9` matrisinde $\min = 1$, $\max = 9$ olduğu için her eleman $(x-1)/8$ olur: `0.000 0.125 0.250 / 0.375 0.500 0.625 / 0.750 0.875 1.000` (ajanın denemesi).

## 3. Soru 2: Dizide tekrar eden elemanların atılması

### 3.1 Slayttaki soru

Slayttaki soru "Dizide Tekrar Eden Elemanların Atılması"dır (Removing Duplicates From An Array). Örnek (ekrandan, 00:45:00):

- Original Array: `1 4 7 4 2 7`
- After Removing Duplicates: `1 4 7 2 X X`

### 3.2 Olası yöntemler

Öğrencilere ilk akla gelen çözüm soruldu. Üç fikir konuşuldu:

- Her eleman için bütün diziyi gezmek (düz mantık). Dizinin sıralı olması gerekmez.
- Her elemanın yalnız sol tarafına bakmak. Bir öğrencinin önerisiydi. Bunun koşulu sorulduğunda cevap "dizinin sıralı olması" oldu; dizi sıralı değilse önce sıralanması gerekir.
- Histogram (sayma) dizisi mantığı. Sorunu, değer aralığının çok geniş olabilmesidir: beş elemanlı bir dizide bir eleman bir milyon olabilir.

Bir öğrenci, elemanları ayrı bir diziye koyup her yeni elemanın orada olup olmadığına bakmayı önerdi. Bunun da düz mantıkla aynı yere çıktığı söylendi: bütün elemanlar farklıysa, bir süre sonra her eleman için neredeyse bütün diziyi gezmek gerekir.

### 3.3 Düz mantık çözüm: iki döngü

İki döngüyle her eleman kendinden sonrakilerle karşılaştırılır; eşit olanlara `-1` yazılır, en sonda `-1`'ler sona toplanır. Sonuç yazdırılacağı için fonksiyon yine `void` döner. Dizi tek boyutlu olduğu için işaretçiyle gönderilebilir; iki boyutlu olsaydı önceki soruda gösterilen adres hesabı gerekirdi.

**Soru:** Önceki soruda matrisi de işaretçiyle göndermiştik; iki boyutta sorun çıkar derken ne kastediliyor? **Cevap:** Matrisi işaretçiyle gönderdiğimizde `i` ve `j`'nin adrese nasıl eklendiğini hesaplayan karmaşık bir düzen kullanmıştık. O yolla kullanılabilir, ama işaretçi parametresinde `Arr[i][j]` biçiminde iki indisle erişilemez.

Önce iç içe döngü yazıldı: zaten `-1` yazılmış bir elemana bakılmaz; değilse kendinden sonraki elemanlarla karşılaştırılır ve eşit olanlara `-1` yazılır.

Sonra `-1`'lerin sona alınması gerekir. Her `-1` görüldüğünde dizinin geri kalanını kaydırmak (cascading) da bir çözümdür; burada daha farklı bir yöntem kullanıldı. `i` diziyi gezen indis, `j` elemanın yazılacağı yerdir. `-1` olmayan bir eleman görüldüğünde `Arr[j]=Arr[i]` yapılır ve ikisi de artar. `-1` görüldüğünde yalnız `i` artar. İlk `-1`'e kadar iki indis birlikte ilerler; `-1`'den sonra `j` `-1`'in yerini gösterir, `i` bir sonrakine geçer. Böylece üzerine yaza yaza kaydırma tek geçişte biter. En sonda `j`'den dizinin sonuna kadar `-1` yazılır.

İlk çalıştırmada sonuç yanlış çıktı. Nedeni iç döngünün `j=0`'dan başlamasıydı; geriye bakmak gerekmediği için `j=i+1` olmalıdır. Düzeltilmiş kod (ekrandan, 00:55:00 ve 01:00:00):

```c
void DoubleLoop(int *Arr,int len){
    int i,j;

    for(i=0;i<len;i++){
        for(j=i+1;j<len;j++){
            if(Arr[i]!=-1){
                if(Arr[i]==Arr[j]){
                    Arr[j]=-1;
                }
            }
        }
    }

    i=0;
    j=0;
    while(i<len){
        if(Arr[i]!=-1){
            Arr[j]=Arr[i];
            i++;
            j++;
        }else{
            i++;
        }
    }
    for(i=j;i<len;i++){
        Arr[i]=-1;
    }
}
```

Main'de kullanılan dizi karede görünmüyor <!-- BELİRSİZ: altyazıda "len eşittir 13" geçiyor; dizinin elemanları okunamadı -->. Ajanın denemesinde slayttaki `1 4 7 4 2 7` dizisi için çıktı `1 4 7 2 -1 -1` oldu; bu, slayttaki `1 4 7 2 X X` sonucudur.

> **Ek bilgi (derste anlatılmadı):** Bu yöntem `-1`'i "silindi" işareti olarak kullanır. Dizide gerçekten `-1` değeri varsa bu değer silinmiş sanılır ve sonuç bozulur. Böyle durumlarda dizide geçmeyeceği bilinen başka bir işaret değeri ya da ayrı bir işaret dizisi kullanılır.

### 3.4 Sıralı dizi çözümü

Dizi sıralıysa her eleman yalnız kendinden öncekine bakılarak kontrol edilir. Ama araya `-1`'ler girebileceği için asıl bakılması gereken, son yazılan farklı elemandır. Bu yüzden yine iki indis kullanıldı: `i=1`, `j=0` (ekrandan, 01:00:00).

**Soru:** Burada neden `for` değil `while` kullanılıyor? **Cevap:** İndisin düz olarak ilerlemesi istenmiyor; indis her adımda aynı biçimde artmayacak, artışın kontrolü programcıda olmalı. Bu yüzden `while` kullanıldı.

`Arr[i]` ile `Arr[j]` eşitse yalnız `i` artırılır. Eşit değilse, yukarıdakiyle aynı mantıkla `Arr[i]`, `j`'nin bir sonraki yerine yazılır ve `i` artırılır. Elemanlar üzerine yazılarak geldiği için ayrıca `-1` koyup kaydırmaya gerek kalmaz. En sonda `j+1`'den sona kadar `-1` yazılır. Ekranda fonksiyonun yalnız ilk satırları görünüyor; aşağıdaki gövde anlatıma göre tamamlanmış ve `gcc -Wall` ile derlenip sıralı bir diziyle denenmiştir:

```c
void Sorted(int* Arr,int len){
    int i=1,j=0;

    while(i<len){
        if(Arr[i]==Arr[j]){
            i++;
        }else{
            j++;
            Arr[j]=Arr[i];
            i++;
        }
    }
    for(i=j+1;i<len;i++){
        Arr[i]=-1;
    }
}
```

Derste programın doğru sonuç ürettiği görüldü. Derste kullanılan sıralı dizi karede görünmüyor.

### 3.5 Karmaşıklık ve hashing

Bu iki çözümün de en iyi çözüm olmadığı söylendi. İki döngüyle gezmek çok fazla işlem yaptırır. Sıralı dizi çözümü için önce dizinin sıralanması gerekir; sıralama iki döngüden daha hızlı çalışır ama yine de maliyetli bir işlemdir. Bunun yerine hashing kullanılır.

Elemanları bir diziye koyup sonra o dizide arama yapmak, aramada yine bütün dizi tarandığı için iki döngüyle aynı yere çıkar. Hashing ise bir dizi içinde bakma işlemini $O(1)$'e, yani tek bir işleme kadar indirir. Gerçek hayatta bu her zaman $O(1)$ olmaz, biraz daha fazla olur, ama yine de çok hızlandırır.

Temel fikir şudur: dizideki 4'ün bulunduğu indisle bir ilgisi yoktur. Elemanlar öyle bir diziye konmalı ki değerden indise ulaşılabilsin; buna hashing denir. Bir öğrenci elemanı doğrudan kendi değerinin indisine koymayı önerdi ve bunun hashing'in ana mantığı olduğu söylendi. Bu yöntemin sorunu sorulduğunda öğrenciler cevap verdi: değerler arasında büyük açıklık varsa dizi gereksiz yer kaplar; sayılar trilyon, katrilyon gibi büyükse bellek bile yetmez.

Bu yüzden ilişki doğrudan değil bir fonksiyonla kurulur; buna hash fonksiyonu denir. Eleman, bu fonksiyonun sonucuna göre bir kovaya (bucket, bin) konur. En basit hash fonksiyonu değerin kova sayısına göre modudur. 7 kova varsa 8 birinci kovaya, 9 ikinci kovaya gider. Aynı sayılar aynı kovaya düşeceği için arama azalır. Her kovada yalnız bir eleman olma olasılığı yüksektir, böylece bakma sayısı $O(1)$'e düşer. Farklı değerlerin aynı kovaya düşmesi çakışmadır; gerçek hayatta kovaların içinde de kontrol gerekir. Slaytta anahtarların (keys) bir hash fonksiyonuyla kovalara (buckets) ve oradan kayıtlara (entries) bağlandığı, iki anahtarın aynı kovaya düştüğü bir telefon rehberi şekli gösterildi (ekrandan, 01:00:00).

Dizilerde arama yapan bir programın saatler sürebildiği, hashing mantığı eklenince bir saniyenin altında sonuç verebildiği bir örnekle anlatıldı.

Tekrar eden elemanlar hashing ile şöyle bulunur: her elemana gelinir ve hash tablosuna "bu var mı?" diye sorulur; bakma karmaşıklığı birdir. Yoksa tabloya eklenir, varsa atlanır. Böylece dizi yalnız bir kez gezilerek tekrar eden bütün elemanlar bulunur.

## 4. Soru 3: Toplamı sıfır olan alt dizi

### 4.1 Slayttaki soru

Slayttaki soru (ekrandan, 01:20:00):

- Bir dizide toplamı 0 olan sub array
  - `1, 4, -2, -2, 5, -4, 3` dizisinde sonuç: `4, -2, -2` olmalı (ya da 1. indexten 3. indexe)

Alt dizi (subarray) yan yana duran elemanlardır: `1, 4` ya da `4, -2, -2` gibi. Yalnız bir tane bulmak yeterlidir.

### 4.2 Öğrencilerin önerileri

Birkaç dakika verildikten sonra öğrenciler fikirlerini anlattı.

Birinci öneri: önce tek elemanlı alt dizilere bakılır, sıfır olan eleman varsa odur. Yoksa iki elemanlı alt dizilere bakılır: bir elemanın negatifi var mı? Sonra iki elemanın toplamının negatifi aranır ve böyle ilerlenir. Bunun bir çözüm olduğu söylendi.

İkinci öneri: dizi sıralanır, artıdan eksiye geçilen indis bulunur, artı taraftan bir sayı seçilip eksi taraftan elemanlar eklenerek toplam dengelenmeye çalışılır. Bu yaklaşımın iki sorunu gösterildi. Birincisi, elemanların kombinasyonu yüzünden doğru toplam kaçabilir: örneğin artı tarafta 21, eksi tarafta `-10, -10, -10, -1` varsa hangi sırayla eklendiğine göre `-21` yakalanmadan `-30`'a gidilebilir. İkincisi ve asıl sorun, alt dizinin elemanları bitişik olmalıdır; dizinin sırası bozulamaz, bu yüzden sıralama yapılamaz.

Üçüncü öneri: elemanlar sırayla toplanır ve her ara toplam işaretlenir. `3, 4, -2, -2` dizisinde ara toplamlar 3, 7, 5, 3 olur. Aynı toplama geri dönülmesi, aradaki elemanların toplamının sıfır olduğu anlamına gelir. Bu cevabın doğru olduğu söylendi. Ara toplamın kendisinin sıfıra ulaşması da ayrıca kontrol edilmelidir. Bu çözümde de ara toplamlar başka bir dizide arandığı için en kötü durumda $n^2$ işlem yapılır. Ara toplamlar hash tablosunda tutulursa arama gerekmez ve karmaşıklık düşer. Dört sorudan üçünün en iyi çözümünün hashing olduğu söylendi.

### 4.3 Kötü çözüm: bütün alt diziler

Her başlangıç noktası `i` için toplam sıfırlanır ve `j=i`'den itibaren elemanlar eklenir; toplam sıfır olursa alt dizi bulunmuştur. Toplamın, kullanıldığı yerin hemen öncesinde, yani dış döngünün içinde sıfırlanması gerekir (ekrandan, 01:15:00):

```c
void findSubArray_Bad(int *Arr,int len){
    int i,j;
    int Sum;
    for(i=0;i<len;i++){
        Sum=0;
        for(j=i;j<len;j++){
```

İç döngünün gövdesi karede görünmüyor <!-- BELİRSİZ: printf'teki metin altyazıdan okunamadı -->. Anlatıma göre `Sum+=Arr[j];` yapılır ve `Sum==0` ise `i` ile `j` yazdırılır:

```c
            Sum+=Arr[j];
            if(Sum==0)
                printf("From %d to %d\n",i,j);
        }
    }
}
```

**Soru:** `int` yazdıktan sonra yıldızı hemen koymakla (`int* Arr`) değişkenin önüne koymak (`int *Arr`) arasında fark var mı? **Cevap:** Hiçbir fark yok. Ama yıldızın değişkenin yanına konması doğru yazım biçimidir; özellikle bir satırda birden fazla değişken tanımlanırken yıldızın türün yanında durması yanıltıcıdır.

Main'deki dizi şudur (ekrandan, 01:20:00): `int Arr[7]={1,5,-2,-1,-1,1,3};`. Çıktıda iki alt dizi bulundu: 2'den 6'ya ($-2-1-1+1+3=0$) ve 4'ten 5'e ($-1+1=0$). Ajanın denemesi de aynı iki satırı verdi. Bu yöntem bütün alt dizileri bulur; basittir ama karmaşıklığı yüksektir.

### 4.4 Önek toplamı çözümü

Önerilen üçüncü yöntem kodlandı. Önce, bir dizinin ilk `limit` elemanında bir değerin bulunup bulunmadığına bakan bir fonksiyon yazıldı. Değer bulunursa 0, bulunmazsa 1 döner (ekrandan, 01:25:00):

```c
int Exists(int *Arr,int Val,int limit){
    int i;

    for(i=0;i<limit;i++){
        if(Arr[i]==Val)
            return 0;
    }
    return 1;
}
```

Ara toplamlar `PrefixSum` dizisinde tutulur. Yöntemin mantığı şudur: sırayla gelen sayılar toplanır; `1, 4, -2, -2` dizisinde ara toplamlar 1, 5, 3, 1 olur. Toplam daha önceki bir değere geri dönmüşse aradaki elemanlar etkisiz elemandır; toplamada etkisiz eleman sıfır olduğu için aranan alt dizi bulunmuştur.

`while` döngüsünün çıkış koşulları üçtür: dizinin sonuna gelmek (`i<len` bozulur), ara toplamın doğrudan sıfır olması (örneğin dizi `4, -2, -2` ile başlasaydı toplam doğrudan sıfır olurdu; bu ihtimal göz ardı edilemez) ve ara toplamın daha önce görülmüş olması. Sonuncusu için `Exists`'e `PrefixSum`, `currSum` ve sınır olarak `i-1` gönderilir. Döngünün içinde `PrefixSum` doldurulur, toplama yapılır ve `while` kullanıldığı için indis artırılır (ekrandan, 01:25:00):

```c
void findSubArray_Good(int *Arr,int len){
    int PrefixSum[len];
    int i,j;
    int Start;
    int End;
    int currSum=Arr[0];
    i=1;
    while((i<len)&&(currSum!=0)&&(Exists(PrefixSum,currSum,i-1))){
        PrefixSum[i-1]=currSum;
        currSum+=Arr[i];
        i++;
    }
```

**Soru:** `PrefixSum`'a hiçbir değer atamadan `Exists` içinde kullanmıyor muyuz? **Cevap:** Öyle, ama ilk çağrıda sınır 0 olduğu için `Exists`'in döngüsüne hiç girilmez. Sınır tam bu yüzden konmuştur. İlk değer atamamanın çok yaygın olduğu ve ödevlerdeki hataların çoğunu oluşturduğu söylendi.

Döngüden üç koşuldan biriyle çıkılabileceği için üç `if` dalı yazılır (ekrandan, 01:30:00 ve 01:35:00):

```c
    if(i==len){
        printf("No Sub Array");
        return;
    }else if(currSum==0){
        i--;
        End=i;
        currSum=Arr[i];
        while(currSum!=0){
            i--;
            currSum+=Arr[i];
        }
        Start=i;

    }else{
        End=i--;
        while(PrefixSum[i]!=currSum)
            i--;
        Start=i-1;

    }

    printf("From %d to %d",Start,End);
}
```

- `i==len` ise dizinin tamamı gezilmiş ve sıfırlayan bir alt dizi bulunamamıştır.
- `currSum==0` ise bir alt dizi bulunmuştur, ama indisler tutulmadığı için geriye dönmek gerekir. Döngüde `i` en sonda artırıldığı için son eklenen eleman bir öncekidir; bu yüzden önce `i--` yapılır ve bu indis `End` olur. Sonra yukarıdaki toplama geriye doğru tekrarlanır: toplam sıfır olana kadar `i` azaltılır ve eleman eklenir. Varılan yer `Start`'tır.
- Üçüncü dalda döngüden `Exists` yüzünden çıkılmıştır. `End` atanır, sonra ara toplamın `PrefixSum` içinde eşleştiği yere kadar geri gidilir.

**Soru:** `currSum` sıfırsa, o ana kadar gelinen bütün elemanların toplamı sıfır değil mi; baştan şu anki indise kadar olan kısım doğrudan alt dizi olarak yazılamaz mı? **Cevap:** Önce toplama katılan son elemanın yazdırıldığı açıklandı: döngüde `i` en sonda artırıldığı için `i`'nin gösterdiği eleman toplama katılmamıştır. Öğrenci soruyu tekrarlayınca bunun doğru olduğu, bu durumda alt dizinin baştan (`0`) son eklenen elemana kadar olduğu ve geriye doğru gitmeye gerek olmadığı kabul edildi.

**Soru:** `currSum` sıfırken yapılan geri gitme işlemi tam olarak ne yapıyor? **Cevap:** `1, 4, -2, -2` örneğinde döngü bittiğinde `i` 4'tür ve 5'i gösterir. Toplama katılan son eleman `-2` olduğu için bir azaltılır ve `End` `-2`'nin indisi olur. Sonra sondan geriye doğru aynı toplama yapılır: `-2`, sonra `-4`, sonra 4 eklenince 0. Sıfır olunca durulur.

**Soru:** Dizide sıfır elemanı varsa algoritma tek elemanlı bir alt dizi olarak onu bulur mu? **Cevap:** Sıfır dizinin başındaysa bulur. Başında değilse ara toplam sıfır olmayabilir ve bulamayabilir; denemek gerektiği söylendi. Bu yöntemin, kötü çözümden farklı olarak yalnız ilk bulduğu alt diziyi verdiği de belirtildi.

> **Ek bilgi (derste anlatılmadı):** Ortada duran bir sıfır elemanı da bu yöntemle bulunur: sıfır eklendiğinde ara toplam değişmez, yani bir önceki ara toplam tekrar etmiş olur ve `Exists` onu yakalar. Ajanın düzeltilmiş sürümüyle (aşağıda) `{1,2,0,3}` dizisiyle yaptığı denemede çıktı `From 2 to 2` oldu.

`--i` ile `i--`'nin farkı soruldu: `--i` önce azaltır sonra değeri verir; `i--` önce değeri verir sonra azaltır. `i--; End=i;` iki satırının `End=--i;` ile aynı olduğu bir öğrencinin sorusu üzerine konuşuldu.

Kod çalıştırıldığında önce "2'den 5'e" çıktı; toplamı sıfır olmadığı için `End` satırı değiştirildi ve sonuç ekrandaki gibi oldu. `Start=i-1` ifadesinin nedeni sorulduğunda, bunun deneme yanılmayla bulunduğu açıkça söylendi: `i` yazdırıldığında bir fazlası çıkmış, bu yüzden bir eksiği konmuştur.

> **Ders sonrası not:** Ekrandaki son kodun üçüncü dalı doğru indisleri vermiyor. Döngüden çıkıldığında `currSum`, `Arr[0]`'dan `Arr[i-1]`'e kadar olan elemanların toplamıdır. `PrefixSum[k]` bu değere eşitse toplamı sıfır olan alt dizi `k+1`'den `i-1`'e kadardır. Ekrandaki kodda ise `End=i--` ile `End` bir fazla çıkar, arama da hiç doldurulmamış `PrefixSum[i]` konumundan başlar. Ajan bu kodu `gcc -Wall` ile derleyip denedi. Ekrandaki `{1,5,-2,-1,-1,1,3}` dizisinde "From 2 to 6" çıktı. Bu aralığın toplamı rastlantı sonucu sıfırdır, oysa algoritmanın yakaladığı tekrar (ara toplam 3) 4-5. indisleri (`-1, 1`) gösterir. Slayttaki `1, 4, -2, -2, 5, -4, 3` dizisinde çıktı "From -1 to 4" oldu; doğrusu 1-3'tür. Ayrıca `while` koşulunda önce `i<len` bozulursa son ara toplam kontrol edilmeden döngüden çıkılır ve `if(i==len)` dalı yanlışlıkla "No Sub Array" yazar. Örneğin `{1,-1}` dizisinde bu olur.

Aşağıdaki düzeltilmiş sürüm derste yazılmadı; ajan tarafından yazıldı ve `gcc -Wall` ile denendi. Öğrencinin önerisine uygun olarak `currSum==0` durumunda alt dizi doğrudan baştan alınır:

```c
#include <stdio.h>

int Exists(int *Arr,int Val,int limit){
    int i;
    for(i=0;i<limit;i++){
        if(Arr[i]==Val)
            return 0;
    }
    return 1;
}

void findSubArray_Fixed(int *Arr,int len){
    int PrefixSum[len];
    int i=1,k;
    int currSum=Arr[0];
    while((i<len)&&(currSum!=0)&&(Exists(PrefixSum,currSum,i-1))){
        PrefixSum[i-1]=currSum;
        currSum+=Arr[i];
        i++;
    }
    /* currSum = Arr[0] + ... + Arr[i-1] */
    if(currSum==0){
        printf("From %d to %d\n",0,i-1);
    }else if(!Exists(PrefixSum,currSum,i-1)){
        k=0;
        while(PrefixSum[k]!=currSum)
            k++;
        printf("From %d to %d\n",k+1,i-1);
    }else{
        printf("No Sub Array\n");
    }
}

int main(){
    int Arr[7]={1,5,-2,-1,-1,1,3};
    int Slayt[7]={1,4,-2,-2,5,-4,3};
    findSubArray_Fixed(Arr,7);
    findSubArray_Fixed(Slayt,7);
    return 0;
}
```

Çıktı: `From 4 to 5` ve `From 1 to 3`.

### 4.5 Önek toplamı yönteminin adım adım izlenmesi

Bir öğrencinin isteği üzerine yöntem slayttaki dizinin başıyla (`1, 4, -2, -2`) adım adım yeniden anlatıldı. Slayta not alınan ara toplamlar şunlardır (ekrandan, 01:40:00): `CurSum = 1 — 5 — 3 — 1`, `Prefix: 1, 5, 3`.

- Başlangıç: `currSum = 1`, `i = 1`. `currSum` sıfır değil ve önek dizisinde (henüz boş) yok; döngüye girilir. `PrefixSum[0] = 1`, `currSum = 1 + 4 = 5`, `i = 2`.
- `currSum = 5` sıfır değil, önek dizisinde (`1`) yok. `PrefixSum[1] = 5`, `currSum = 5 + (-2) = 3`, `i = 3`.
- `currSum = 3` sıfır değil, önek dizisinde (`1, 5`) yok. `PrefixSum[2] = 3`, `currSum = 3 + (-2) = 1`, `i = 4`.
- `currSum = 1` sıfır değil, ama önek dizisinde var. Döngüden çıkılır.

Toplama sonucunda daha önceki bir sayı çıktığı için aradaki elemanlar (`4, -2, -2`) etkisizdir, yani toplamları sıfırdır. Başlangıç noktası, ara toplamın önek dizisinde yakalandığı yerden bulunur; bitiş noktası son eklenen elemandır.

`currSum` sıfır olarak çıkıldıysa, son elemandan önceki bütün sayıların toplamı sıfırdır; bu durumda geriye doğru yapılan işlemlerin aslında gereksiz kaldığı, alt dizinin doğrudan baştan alınabileceği bu anlatımda da söylendi.

Hashing ile çözüldüğünde yalnız `Exists` fonksiyonunun değiştiği, aramanın tek adıma indiği için daha iyi bir sonuç elde edildiği söylendi.

## 5. Soru 4: Dizideki en uzun devamlı dizi

### 5.1 Slayttaki soru

Slayttaki soru (ekrandan, 01:45:00):

- Bir dizide bulunan en uzun devamlı dizi
  - `[100, 4, 200, 1, 3, 2]` gibi verilen bir dizide istenen sonuç `[1, 2, 3, 4]`

Devamlı dizi, aralarında 1 fark olan ardışık sayılardır: 1, 2, 3, 4. Elemanların dizide yan yana durması gerekmez; tek bir dizi verilir ve içindeki en uzun ardışık sayı kümesi istenir.

### 5.2 Öğrencilerin önerileri

Bir öğrenci önce sıralamayı önerdi; bunun bir yöntem olduğu, ama sıralamanın maliyetli olduğu söylendi. Bir başka öğrenci komşu elemanların farklarını yeni bir diziye yazmayı önerdi; 4 ile 200'ün yan yana olduğu, oysa 4'ün sonucun bir parçası olduğu gösterilerek bunun sıralama yapılmadan çalışmayacağı belirtildi. Bir öğrenci de elemanları kendi değerlerinin indisine koyup en uzun ardışık dolu bölgeyi aramayı önerdi; bunun doğru olduğu ama bellek sorunu taşıdığı, en iyi yolun yine hashing olduğu söylendi.

### 5.3 Kaba kuvvet çözümü

En kaba yöntem şudur: dizi üzerinde gidilir. 4'e gelinir, 4'ün bir fazlası var mı? Yok. 200'e bakılır, yok. 1'e bakılır: bir fazlası (2) var. Sonra 2'nin bir fazlası aranır: 3 var. 3'ün bir fazlası: 4 var. 4'ün bir fazlası yok. Her adımda mevcut dizi uzunluğu (`currSeq`) bir artırılır.

Bu yöntemin selection sort'a çok benzediği, hatta ondan da kötü olduğu söylendi: selection sort'ta taranan kısım gittikçe azalır, burada azalma yoktur, her seferinde bütün dizi kontrol edilir. Karmaşıklık aynıdır.

Sayı değiştiği için o anki sayı ayrı bir değişkende (`currNumber`) tutulur. İç döngünün türü soruldu; cevap `while` oldu: döngüden doğrudan gezip çıkması değil, bir fazlası bulunduğunda yeniden başlaması isteniyor. Bir fazlası bulunduğunda döngüden çıkılmaz; `currNumber` ve `currSeq` artırılır, `j` sıfırlanır ve artmış sayı dizinin başından yeniden aranır. Bulunamazsa `j` artırılarak aramaya devam edilir; dizinin sonuna gelindiğinde `while` biter. Ekrandaki kod (ekrandan, 01:50:00 ve 01:55:00):

```c
void Brute(int *Arr,int len){
    int i,j;
    int currNumber;
    int currSeq;
    int Max=0;
    int Start;

    for(i=0;i<len;i++){
        j=0;
        currSeq=1;
        currNumber=Arr[i];
        while(j<len){
            if(Arr[j]-1==currNumber){
                currNumber+=1;
                currSeq+=1;
                j=0;

            }else{
                j++;
            }

        }
        if(Max<currSeq){
            Max=currSeq;
            Start=Arr[i];
        }
    }

    printf("Longest Sequence ");
    for(i=0;i<Max;i++)
        printf("%d ",Start+i);
}
```

`Start`, en uzun dizinin başladığı değerdir; `Arr[i]` her `i` için o dizinin başlangıcı olduğu için en uzun dizi bulunduğunda `Start=Arr[i]` yapılır. Yazdırırken başlangıç değerinden itibaren `Max` tane ardışık sayı basılır. Main'de `len` 6 alındı ve slayttaki dizi verildi. Ajanın `gcc -Wall` denemesinde çıktı `Longest Sequence 1 2 3 4` oldu.

`currNumber+=1` yazıldıktan sonra `++` kullanmanın daha mantıklı olduğu söylendi ve `j++` ile `j+=1` farkı soruldu. Derste ikisinin arka planda farklı komutlarla gerçeklendiği, `++`'nın artırma (increment) komutu olduğu için çok daha hızlı çalıştığı söylendi.

> **Ders sonrası not:** Bir `int` değişkeni artırırken `i++`, `++i` ve `i+=1` aynı işi yapar ve derleyiciler bunları aynı makine koduna çevirir. Ajanın denemesinde gcc, `-O0` ve `-O2` ile `i++` ve `i+=1` için birebir aynı makine kodunu üretti. Bu yüzden aralarında bir performans farkı yoktur. Hangisinin kullanılacağı okunabilirlik tercihidir.

### 5.4 Sıralı dizi çözümü

Dizi sıralıysa yalnız bir sonraki elemana bakmak yeterlidir: `Arr[i]+1==Arr[i+1]` ise mevcut dizi uzar; değilse yeni bir dizi başlar ve gerekirse en büyük uzunluk ile bitiş indisi güncellenir. Başlangıç ayrıca tutulmaz; bitiş indisinden `Max` kadar geriye gidilerek bulunur. Ekrandaki kısım (ekrandan, 01:55:00):

```c
void Sorted(int *Arr,int len){
    int i;
    int Max=0;
    int Start=0;
    int End;
    int currSeq=1;
    for(i=0;i<len;i++){
        if(Arr[i]+1==Arr[i+1]){
            currSeq++;

        }else{
            if(currSeq>Max){
                End=i;
                Max=currSeq;
            }
```

`Start` kullanılmadığı için sonradan silindi (ekrandan, 02:00:00). İlk çalıştırmada program çalışmadı; sıralanmamış dizi verildiği anlaşıldı ve sıralı diziyle çalıştı <!-- BELİRSİZ: derste kullanılan sıralı dizi ve yazdırma satırının tam hâli karelerde görünmüyor -->.

> **Ders sonrası not:** Ekrandaki döngü `i<len` olduğu için son adımda `Arr[i+1]` dizinin dışına (`Arr[len]`) taşar. Döngü `i<len-1` olmalı ve döngüden sonra son dizi için `currSeq>Max` kontrolü ayrıca yapılmalıdır. `else` dalında `currSeq`'in yeniden 1 yapılması da gerekir; bu satır karede görünmüyor. Aşağıdaki tamamlanmış sürüm ajan tarafından yazıldı ve `gcc -Wall` ile sıralanmış `1 2 3 4 100 200` dizisiyle denendi; çıktı `Longest Sequence 1 2 3 4` oldu.

```c
void Sorted(int *Arr,int len){
    int i;
    int Max=0;
    int End=0;
    int currSeq=1;
    for(i=0;i<len-1;i++){
        if(Arr[i]+1==Arr[i+1]){
            currSeq++;
        }else{
            if(currSeq>Max){
                End=i;
                Max=currSeq;
            }
            currSeq=1;
        }
    }
    if(currSeq>Max){
        End=len-1;
        Max=currSeq;
    }
    printf("Longest Sequence ");
    for(i=0;i<Max;i++)
        printf("%d ",Arr[End-Max+1+i]);
    printf("\n");
}
```

### 5.5 Hashing çözümü

Hashing çözümü basittir. Bütün elemanlar hash tablosuna konur. Sonra her eleman için bir eksiği tabloda aranır. Bir eksiği yoksa bu eleman devamlı bir dizinin başlangıç noktası olabilir; bu durumda bir fazlası, iki fazlası... aranarak dizinin uzunluğu sayılır. Bir eksiği varsa eleman bir başlangıç noktası değildir ve geçilir. (Anlatımda önce bir fazlasının arandığı söylendi, sonra "bir eksiği aranır" diye düzeltildi.)

Slayttaki dizide:

- 100: 99 yok, başlangıç olabilir. 101 yok. Uzunluk 1.
- 4: 3 var, başlangıç noktası değil, geçilir.
- 200: 199 yok, başlangıç olabilir. 201 yok. Uzunluk 1.
- 1: 0 yok, başlangıç olabilir. 2 var (uzunluk 2), 3 var (3), 4 var (4), 5 yok. Uzunluk 4.

En uzun devamlı dizi 4 uzunluğundadır: 1, 2, 3, 4. Çıkışta başlangıç noktası tutulur ve kaba kuvvet çözümündeki gibi oradan itibaren yazdırılır. Ajan bu sonucu python ile doğruladı.

**Soru:** Varlığı kontrol ederken bir sayaç dizisi mi tutuyoruz, yoksa `Exists` gibi bir fonksiyonla mı kontrol ediyoruz? **Cevap:** İkisi de değil; hash tablosu tutuluyor. Mantık daha çok `Exists`'e benzer: elimizde dizinin bütün elemanları var ve bir elemanın bunlar arasında olup olmadığına bakıyoruz. Bu aramayı tek tek yapmak kötü bir çözümdür; hash tablosunda ise eleman tek adımda bulunur.

## Örnek Sorular

**Soru 1** (ekrandan, 00:10:00). Matris operasyonları: iki matrisin toplamı, iki matrisin çarpımı, iki matrisin iç çarpımı ve matrisin normalizasyonu (Min-Max Scaling, $X_{new} = \frac{X_i - \min(X)}{\max(X) - \min(X)}$). Matrisler `{{1,2,3},{4,5,6},{7,8,9}}`.

> **Çözüm (derste verildi):** Sonuç matrisi parametreyle gönderilir, fonksiyonlar `void` döner. Toplam ve eleman eleman çarpım iki iç içe `for` ile, iç çarpım üçüncü indis `k` ve her eleman için sıfırlanan `tmpSum` ile yapılır. Normalizasyonda `minMax` ile en küçük ve en büyük değer bulunur, bölme `(float)` dönüşümüyle yapılır. Sonuçlar: toplam `2 4 6 / 8 10 12 / 14 16 18`, eleman eleman çarpım `1 4 9 / 16 25 36 / 49 64 81`, iç çarpım (matris çarpımı) `30 36 42 / 66 81 96 / 102 126 150`, normalizasyon `0 0.125 0.25 / 0.375 0.5 0.625 / 0.75 0.875 1` (ajanın denemesi). Kodlar Bölüm 2'dedir.

**Soru 2** (derste sözlü, 00:11:27). Matris toplamı fonksiyonunun dönüş değeri ne olmalıdır?

> **Çözüm (derste verildi):** `void`. Sonuç zaten parametre olarak gönderilen matrise yazılır; ayrıca bu biçimde tanımlanmış bir matris C'de fonksiyondan döndürülemez.

**Soru 3** (derste sözlü, 00:32:14). İç çarpım kodu ilk yazıldığı hâliyle doğru çalışır mı? `tmpSum` nerede sıfırlanmalıdır?

> **Çözüm (derste verildi):** Çalışmaz: `k`'li `for`'da noktalı virgül yerine virgül vardı ve `tmpSum`'a ilk değer verilmemişti. `tmpSum`, `j` döngüsünün her adımında, `k` döngüsünden hemen önce sıfırlanmalıdır; çünkü sonucun her elemanı ayrı bir toplamdır.

**Soru 4** (derste sözlü, 00:43:13). Normalizasyon programı neden 0 ve 1 dışında değer vermedi?

> **Çözüm (derste verildi):** Önce `float` matris `%d` ile yazdırılıyordu. Düzeltildikten sonra da işlemdeki bütün değerler `int` olduğu için tam sayı bölmesi yapılıyordu. Başa `(float)` eklenince bölme ondalıklı yapıldı.

**Soru 5** (ekrandan, 00:45:00). Dizide tekrar eden elemanları atınız. Örnek: `1 4 7 4 2 7` → `1 4 7 2 X X`.

> **Çözüm (derste verildi):** İç içe döngüyle tekrar edenlere `-1` yazılır, sonra iki indisle `-1` olmayanlar tek geçişte sola kaydırılır ve kalan yerlere `-1` yazılır (Bölüm 3.3). Dizi sıralıysa her eleman son yazılan farklı elemanla karşılaştırılır (Bölüm 3.4). En iyisi hashing'dir: her eleman hash tablosunda aranır, yoksa eklenir, varsa atlanır. Ajanın denemesinde `DoubleLoop` slayttaki dizi için `1 4 7 2 -1 -1` verdi.

**Soru 6** (derste sözlü, 00:46:03). Her elemanın yalnız sol tarafına bakarak tekrarları bulmanın koşulu nedir?

> **Çözüm (derste verildi):** Dizinin sıralı olması. Dizi sıralı değilse önce sıralanması gerekir.

**Soru 7** (derste sözlü, 00:56:46). Sıralı dizi çözümünde neden `for` değil de `while` kullanıldı?

> **Çözüm (derste verildi):** İndis her adımda aynı biçimde ilerlemiyor; yalnız bazı koşullarda artıyor. Artışın kontrolü programcıda olsun diye `while` kullanıldı.

**Soru 8** (derste sözlü, 01:02:07). Her elemanı doğrudan kendi değerinin indisine koymanın (hashing'in ana fikri) sorunu nedir?

> **Çözüm (derste verildi):** Değerler arasında büyük açıklık varsa dizi gereksiz yer kaplar; sayılar çok büyükse bellek bile yetmez. Bu yüzden ilişki bir hash fonksiyonuyla kurulur (örneğin değerin kova sayısına göre modu).

**Soru 9** (ekrandan, 01:20:00). Bir dizide toplamı 0 olan alt dizi (sub array) bulunuz. `1, 4, -2, -2, 5, -4, 3` dizisinde sonuç `4, -2, -2` olmalı (ya da 1. indexten 3. indexe).

> **Çözüm (derste verildi):** Kötü çözümde her başlangıç için toplam sıfırlanıp sağa doğru toplanır ($O(n^2)$, Bölüm 4.3). İyi çözümde ara toplamlar tutulur; ara toplam sıfır olursa ya da tekrar ederse aradaki elemanların toplamı sıfırdır (Bölüm 4.4). Slayttaki dizide ara toplamlar 1, 5, 3, 1'dir; 1 tekrar ettiği için alt dizi 1-3. indislerdir. Ekrandaki kodun indis hesabındaki hata ve düzeltilmiş sürüm Bölüm 4.4'tedir.

**Soru 10** (derste sözlü, 01:22:50). Önek toplamı döngüsünden çıkıldığında `i==len` olması ne anlama gelir?

> **Çözüm (derste verildi):** Dizinin tamamı gezilmiş ve sıfırlayan bir alt dizi bulunamamıştır.

**Soru 11** (derste sözlü, 01:30:53). `End=--i;` ile `End=i--;` arasındaki fark nedir?

> **Çözüm (derste verildi):** `--i` önce azaltır, sonra azalmış değeri atar. `i--` önce mevcut değeri atar, sonra azaltır.

**Soru 12** (ekrandan, 01:45:00). Bir dizide bulunan en uzun devamlı diziyi bulunuz. `[100, 4, 200, 1, 3, 2]` için sonuç `[1, 2, 3, 4]`.

> **Çözüm (derste verildi):** Kaba kuvvette her eleman için bir fazlası dizinin başından yeniden aranır (Bölüm 5.3). Sıralı dizide her eleman bir sonrakiyle karşılaştırılır (Bölüm 5.4). Hashing'de bir eksiği tabloda olmayan elemanlardan başlanıp bir fazlası, iki fazlası... aranır (Bölüm 5.5). Ajanın denemesinde `Brute` `Longest Sequence 1 2 3 4` verdi.

**Soru 13** (derste sözlü, 01:47:24). Kaba kuvvet çözümündeki iç döngü `while` mı olmalı, `for` mu?

> **Çözüm (derste verildi):** `while`. Bir fazlası bulunduğunda arama dizinin başından yeniden başlamalıdır (`j=0`); döngünün düz olarak gezip çıkması istenmez.

## Dersin Toparlaması

Bu uygulamada dizi ve matrislerin fonksiyonlara nasıl gönderildiği dört problem üzerinden çalışıldı. İlk problemde matris toplamı, eleman eleman çarpım, matris çarpımı ve min-max normalizasyonu yazıldı. Sonuç matrisinin parametreyle gönderilmesi, global değişkenden kaçınılması, matrisin işaretçiyle satır satır gezilmesi, ilk değer atamanın önemi ve tam sayı bölmesi tuzağı bu sırada konuşuldu. Sonraki üç problemde (tekrar eden elemanların atılması, toplamı sıfır olan alt dizi, en uzun ardışık dizi) her soru için önce iç içe döngülerle kaba bir çözüm, sonra sıralama ya da önek toplamı gibi daha iyi bir çözüm yazıldı.

Üç problemin ortak sonucu, en iyi çözümün hashing olmasıdır. Bir değerin bir kümede bulunup bulunmadığını sormak, düz bir dizide bütün diziyi taramayı gerektirir; hash tablosunda ise bu soru ortalama tek adımda cevaplanır. Böylece iç içe döngülü $O(n^2)$ çözümler, diziyi bir kez gezen çözümlere dönüşür.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
