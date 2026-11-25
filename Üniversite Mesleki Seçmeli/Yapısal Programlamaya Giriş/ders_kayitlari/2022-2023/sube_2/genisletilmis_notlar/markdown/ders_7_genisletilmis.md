# Ders 7 Genişletilmiş Notu: Uygulama 1: Sayının Tersi, Polinom Değeri ve Diziyi Bir Değere Göre Bölme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Uygulama oturumunun işleyişi
- 2. Soru 1: Sayıyı dizi kullanmadan tersine çevirme
- 3. Soru 2: Polinomun değerini hesaplama
- 4. Giriş tamponu ve scanf içindeki boşluk
- 5. Koşulu De Morgan ile yeniden yazma; or, ya da ve XOR
- 6. Soru 3: Diziyi bir x değerine göre bölme
- 7. İlk iki sorunun dizi kullanan çözümleri ve bellek karmaşıklığı
- 8. printf'in dönüş değeri, return 0 ve standart akışlar
- 9. Soru kısıtları ve iyi algoritma
- Örnek Sorular
- Dersin Toparlaması

## 1. Uygulama oturumunun işleyişi

Bu kayıt dersin ilk **uygulama** oturumudur. Uygulamada yeni konu anlatılmaz; ekrana bir soru konur, öğrencilere birkaç dakika düşünme süresi verilir, öneriler tartışılır ve çözüm C dilinde, Dev-C++ ortamında birlikte yazılıp çalıştırılır. Oturumu yürüten araştırma görevlisi soruları kendi hazırladığı bir sunumdan gösterdi; oturumun bir bölümünde dersin öğretim üyesi de tartışmaya katılıp ek sorular sordu ve açıklamalar yaptı.

Sunumda üç soru vardı (ekrandan, 00:15:00). İlk iki soru önce dizi kullanmadan çözüldü; üçüncü soruda dizi kullanıldı; sonra ilk iki soru bir de dizi ile yazılıp iki yaklaşım karşılaştırıldı.

### 1.1 Kodlama kuralları

Polinom sorusu yazılırken döngü değişkeni konusu açıldı ve dönem boyunca ödevlerde ve laboratuvarlarda geçerli olacak kodlama kuralları sıralandı:

- Döngü değişkeni `for (int i = 0; ...)` biçiminde döngünün içinde tanımlanmaz. Döngülerde kullanılacak değişkenler fonksiyonun başında tanımlanır.
- `main`'in üstünde tanımlanan **global değişken** kullanılmaz.
- `break` ve `continue` kullanılmaz.
- Her yerden erişilecek bir sabit gerekiyorsa `#define` ile **makro** olarak tanımlanır.
- Dizi boyutu `int a[50];` gibi doğrudan sayıyla yazılmaz; `#define MAX 50` tanımlanır ve `int a[MAX];` yazılır.

> **Hocanın vurgusu:** Bunlar bölümün standart C kullanımı için koyduğu kurallardır; bazı derleyiciler `for (int i = 0; ...)` yazımını kabul etse de bu dersin çalışmalarında istenmez.

## 2. Soru 1: Sayıyı dizi kullanmadan tersine çevirme

Soru metni: "Kullanıcıdan alınan bir sayıyı tersine çeviren programı yazınız." Örnek: girilen sayı 1283, ters sayı 3821 (ekrandan, 00:15:00). Sayının pozitif olması yeterlidir, basamak sınırı yoktur. Bu sorunun önce **dizi kullanmadan** çözülmesi istendi.

### 2.1 Fikir

Öğrencilerden gelen ilk öneri bölüm ve kalanı kullanmaktı. Bir sayının 10'a göre modu son basamağını verir: $1283 \bmod 10 = 3$. Sayıyı 10'a tam sayı bölümüyle bölmek son basamağı atar: $1283 / 10 = 128$. Bu iki işlem tekrarlandıkça basamaklar sondan başa doğru tek tek elde edilir.

Bir öğrenci önce basamak sayısını bulmak gerektiğini düşündü. Araştırma görevlisi buna gerek olmadığını açıkladı: sayı 10'a bölündükçe küçülür ve en sonunda 0 olur. Döngü "sayı 0'dan büyük olduğu sürece" dönerse basamak sayısı kadar döner; basamak sayısı arka planda bulunmuş olur ama ayrıca tutulması gerekmez.

Ters sayıyı kurmak için her yeni basamaktan önce eldeki ters sayı 10 ile çarpılır, yani bir basamak sola kaydırılır, sonra yeni basamak eklenir:

$$\text{ters} \leftarrow \text{ters} \cdot 10 + \text{kalan}$$

### 2.2 Adım adım izleme

`ters_sayi` başlangıçta 0'dır; böylece ilk adımda yalnızca ilk kalan kalır.

| Adım | sayi (başta) | kalan = sayi % 10 | ters_sayi | sayi /= 10 |
|---|---|---|---|---|
| 1 | 1283 | 3 | $0\cdot 10+3=3$ | 128 |
| 2 | 128 | 8 | $3\cdot 10+8=38$ | 12 |
| 3 | 12 | 2 | $38\cdot 10+2=382$ | 1 |
| 4 | 1 | 1 | $382\cdot 10+1=3821$ | 0 |

Sayı 0 olunca `while (sayi > 0)` koşulu yanlış olur ve döngü biter.

### 2.3 Kod

Ekrandaki çözüm (ekrandan, 00:25:00):

```c
#include <stdio.h>

int main() {

    int sayi,kalan,ters_sayi=0;

    printf("Lutfen sayi giriniz...\n");
    scanf("%d",&sayi);
    while(sayi>0){

        kalan=sayi%10;
        ters_sayi=ters_sayi*10+kalan;
        sayi/=10;//sayi=sayi/10;

    }

    printf("Ters sayimiz su sekildedir %d",ters_sayi);

    return 0;
}
```

Kod `gcc -Wall` ile derlendi ve 1283 girişiyle `3821` yazdı. `sayi /= 10;` ifadesi `sayi = sayi / 10;` ifadesinin kısa yazımıdır; `sayi` tam sayı olduğu için bölümün ondalık kısmı atılır.

### 2.4 Hata ayıklama ile izleme

Araştırma görevlisi aynı izlemeyi Dev-C++'ın hata ayıklayıcısıyla gösterdi: `while` satırına bir kesme noktası konur, program derleyici ayarı **Debug** iken hata ayıklama modunda (F5) başlatılır ve adım adım ilerlerken her değişkenin o anki değeri izlenir (ekrandan, 00:25:00). Bu yöntem yalnızca bu soru için değil, kendi yazdığınız her programda bir değişkenin hangi döngüde hangi değeri aldığını görmek için kullanılabilir.

### 2.5 Soru-cevap

**Soru:** Her kalanı bulduğumuz anda `printf` ile ekrana bassak olmaz mı?

**Cevap:** Ekranda yalnızca göstermek için olabilir. Ama o zaman ters sayının tamamı tek bir değişkende tutulmamış olur; ters sayıyla daha sonra bir işlem yapılacaksa bir değişkende saklanması gerekir. Bu yüzden ters sayı `ters_sayi` değişkeninde kurulur.

## 3. Soru 2: Polinomun değerini hesaplama

Soru metni: "Kullanıcıdan tek değişkenli bir polinom denkleminin derece sayısını, her bir derecenin katsayısını, değişken değerini alan ve sonucu ekrana yazan programı yazınız." Slayttaki örnek (ekrandan, 00:30:00):

$$N=2,\ a=3,\ b=2,\ c=4 \;\Rightarrow\; 3x^2+2x+4,\quad x=4 \;\Rightarrow\; \text{Sonuç}=60$$

Kontrol: $3\cdot 16 + 2\cdot 4 + 4 = 48 + 8 + 4 = 60$.

Öğretim üyesi bu sorunun önemini şöyle açıkladı: bir polinomun ya da bir fonksiyonun değerini bulmak, ileride sayısal analizde kök bulma gibi yöntemlerde çok sık yapılacak bir işlemdir. Bu yüzden bu işi verimli yapmayı bilmek gerekir.

### 3.1 Fikir

Bir öğrencinin önerisi doğru şablonu verdi: önce polinomun derecesi alınır, sonra bir `for` döngüsüyle dereceye ulaşılıncaya kadar katsayılar alınır; her katsayı $x$'in ilgili kuvvetiyle çarpılıp bir toplama eklenir ve en sonda toplam yazdırılır.

Kuvveti her terimde baştan hesaplamamak için `temp` adlı bir değişken kullanılır. $x^0 = 1$ olduğu için `temp = 1` ile başlanır. Her adımda önce `katsayi * temp` toplama eklenir, sonra `temp` $x$ ile çarpılır. Böylece `temp` sırasıyla $1, x, x^2, x^3, \dots$ değerlerini alır:

$$\text{toplam} = a_0\cdot 1 + a_1\cdot x + a_2\cdot x^2 + \dots + a_N\cdot x^N$$

Derece $N$ ise $N+1$ katsayı vardır; bu yüzden döngü `i = 0`'dan `i <= N`'e kadar döner.

### 3.2 Kod

Değişkenler ve döngü (ekrandan, 00:40:00):

```c
int N,toplam=0,x,katsayi,temp,i;
...
temp=1;

for(i=0;i<=N;i++)
{
    printf("%d dereceli terimin katsayisi ..?",i);
    scanf("%d",&katsayi);

    toplam+=katsayi*temp;
    temp*=x;
}
```

Sonra program bir `do-while` döngüsüne alındı ve sonunda kullanıcıya tekrar denemek isteyip istemediği soruldu (ekrandan, 00:50:00; 00:55:00):

```c
printf("Sonuc= %d",toplam);
printf("\nTekrar denemek için E veya e'ye basin");
scanf(" %c",&devam);
}while(devam=='E'|| devam=='e');
```

Burada `do-while` seçildi, çünkü programın gövdesi **en az bir kez** kesin çalışmalı, sonra kullanıcının cevabına göre tekrarlanmalıdır. `while` döngüsü koşulu başta denetler; `do-while` ise gövdeyi bir kez çalıştırıp koşulu sonda denetler.

Aşağıdaki tam sürüm, ekrandaki parçaların birleştirilmesiyle kuruldu. Derste bir öğrencinin uyarısıyla eklenen `toplam = 0;` sıfırlaması döngünün başına konuldu ve `devam` değişkeni `char` olarak tanımlandı (ara adım eklendi). Kod `gcc -Wall` ile derlendi ve aşağıdaki girdilerle denendi:

```c
#include <stdio.h>

int main() {

    int N,toplam,x,katsayi,temp,i;
    char devam;

    do{
        toplam=0;
        printf("Denklem kacinci dereceden olsun?..");
        scanf("%d",&N);

        printf("Degisken degeri ne olsun?..");
        scanf("%d",&x);

        temp=1;

        for(i=0;i<=N;i++)
        {
            printf("%d dereceli terimin katsayisi ..?",i);
            scanf("%d",&katsayi);

            toplam+=katsayi*temp;
            temp*=x;
        }

        printf("Sonuc= %d",toplam);
        printf("\nTekrar denemek icin E veya e'ye basin");
        scanf(" %c",&devam);
    }while(devam=='E'|| devam=='e');

    return 0;
}
```

### 3.3 Derste yapılan çalıştırma

Derste derece 2, $x = 3$, katsayılar sırasıyla 5, 2, 3 girildi ve program `Sonuc= 38` yazdı (ekrandan, 00:45:00):

| i | katsayı | temp (çarpmadan önce) | katsayı · temp | toplam | temp (sonra) |
|---|---|---|---|---|---|
| 0 | 5 | 1 | 5 | 5 | 3 |
| 1 | 2 | 3 | 6 | 11 | 9 |
| 2 | 3 | 9 | 27 | 38 | 27 |

Yani $3x^2 + 2x + 5$, $x=3$ için $27 + 6 + 5 = 38$. Slayttaki örnekle (derece 2, $x=4$, katsayılar 4, 2, 3) aynı program 60 verir.

**Soru:** Katsayıların en düşük dereceden başlayarak girildiğini kullanıcı nereden bilecek?

**Cevap:** Döngü `i = 0`'dan başladığı için ekrana önce "0 dereceli terimin katsayısı", sonra "1 dereceli terimin katsayısı" yazılır; kullanıcı hangi katsayıyı girdiğini bu mesajdan görür.

**Soru:** Program `E` ile baştan başladığında `toplam` değişkenini sıfırlamamız gerekmiyor mu?

**Cevap:** Evet, gerekir. Sıfırlanmazsa ikinci turda yeni sonuç bir önceki toplamın üzerine eklenir. `toplam`, her turun başında sıfırlanmalıdır.

### 3.4 Büyük dereceden başlamak neden daha kötü

Polinomlar genelde büyük dereceden küçüğe yazılır ($x^5$, $x^4$, ...). Bu sırayla hesaplamak için döngü `i = n`'den başlatılıp `i >= 0` iken `i--` ile azaltılabilir. Öğretim üyesi bu yaklaşımın maliyetini sordu: her terimde $x^i$'yi hesaplamak gerekir. Hazır bir kuvvet fonksiyonu kullanılmıyorsa bunun için içeride bir `for` daha gerekir. Dıştaki döngü $n$ kez, içteki döngü de en fazla $n$ kez döner; karmaşıklık $n^2$'ye çıkar.

> **Hocanın vurgusu:** Matematiksel olarak iki yol da aynı sonuca ulaşır, ama biri $n$, öbürü $n^2$ karmaşıklıktadır. Bir polinomun değeri hesaplanacaksa küçük dereceden başlayıp kuvveti bir önceki kuvvetten elde etmek gerekir. Şu ana kadar kuvvet almak için hazır `pow` fonksiyonu da kullanılmadı.

> **Ek bilgi (derste anlatılmadı):** Polinomu büyük dereceden başlayarak da $O(n)$'de hesaplamanın bilinen yolu Horner yöntemidir: $a_2x^2+a_1x+a_0 = (a_2x + a_1)x + a_0$ biçiminde iç içe çarpma yapılır. Burada her adımda `sonuc = sonuc * x + a_i` işlemi uygulanır. Bu, Soru 1'deki `ters = ters * 10 + kalan` işlemiyle aynı yapıdadır.

## 4. Giriş tamponu ve scanf içindeki boşluk

Araştırma görevlisi `scanf(" %c", &devam);` satırında `%c`'nin önüne bilerek bir boşluk koydu ve bunun nedenini programı iki kez çalıştırarak gösterdi. Boşluk varken `E` girildiğinde program baştan başladı. Boşluk kaldırılıp aynı girişler yapıldığında ise program kullanıcının bir şey girmesini beklemeden bitti.

Öğretim üyesi nedeni ayrıntılı açıkladı. Kullanıcı bir sayı yazıp Enter'a bastığında sayı `%d` ile değişkene atanır, ama Enter karakteri (`\n`) **giriş tamponunda** kalır; boşa gitmez. Sonraki `scanf("%c", &devam)` çağrısı tampondaki bu `\n` karakterini okur. `devam` ne `E` ne `e` olduğu için döngü biter. Kullanıcı Enter'a basmak zorundadır, çünkü programın bir sonraki adıma geçmesi için gereklidir; bu yüzden sorun her zaman ortaya çıkar.

İki çözüm gösterildi:

- `%c`'nin önüne boşluk koymak (`" %c"`). Bu, tampondaki boşluk ve Enter gibi beyaz boşluk karakterlerini atlar. Bu yöntem `char` okurken gerekir; `%d` zaten baştaki beyaz boşlukları atlar.
- `scanf`'ten önce tamponu temizlemek: `fflush(stdin);` (ekrandan, 01:45:00).

`fflush` "boşaltmak" anlamına gelir. `stdin` programcının uydurduğu bir değişken değildir; standart girişi gösteren hazır bir tanımlayıcıdır.

> **Ders sonrası not:** `fflush(stdin)` derste kullanılan Windows ortamında tamponu temizler, ama C standardına göre `fflush` yalnızca çıkış akışları için tanımlıdır; giriş akışında davranışı tanımsızdır ve büyük olasılıkla başka sistemlerde (örneğin Linux'ta) işe yaramaz. Taşınabilir çözüm `" %c"` biçimindeki boşluktur.

## 5. Koşulu De Morgan ile yeniden yazma; or, ya da ve XOR

### 5.1 De Morgan

Öğretim üyesi `while(devam=='E'|| devam=='e')` koşulunu, 31. satır aynı kalmak şartıyla başka nasıl yazabileceğimizi sordu. `||` (veya) kümelerdeki birleşime karşılık gelir: $A \cup B$. Burada iki kümenin kesişimi boştur, çünkü bir karakter aynı anda hem büyük hem küçük `E` olamaz.

De Morgan kuralına göre:

$$\overline{A \cup B} = \overline{A} \cap \overline{B}, \qquad A \cup B = \overline{\overline{A} \cap \overline{B}}$$

Buna göre "devam `E` ise veya `e` ise" koşulu, "devam `E`'den farklı **ve** `e`'den farklı" koşulunun değilidir:

```c
}while(!(devam != 'E' && devam != 'e'));
```

Bu sürüm de `gcc -Wall` ile derlendi ve özgün koşulla aynı davrandı. Ünlem işareti ifadenin bütününe uygulanır: önce iki "eşit değil" karşılaştırması `&&` ile birleştirilir, sonra sonucun değili alınır.

> **Hocanın vurgusu:** Bazen ikinci biçim (değilli olan) verilip birinciye dönüştürmeniz istenir, bazen tersi. De Morgan'ı unutmayın.

Bir öğrenci `'E'` ile `'e'`'nin ASCII değerlerinin bilinmesi gerekip gerekmediğini sordu. Cevap: ASCII tablosunu ezberlemek gerekmez; karakter sabiti yazıldığında dönüşüm zaten derleyici tarafından yapılır.

### 5.2 `or` operatörü ve "ya da"

**Soru:** "Veya" yerine "ya da" yazsak sorun olur mu? Ben C'de `or` yazdığımda kabul etmişti.

**Cevap:** C'de `or` diye bir operatör yoktur. Derste dosya `.cpp` olarak kaydedildiği için kabul edilmiş olabileceği düşünüldü; dosya `.c` olarak kaydedilip derlendiğinde derleyici `expected ')' before 'or'` hatası verdi (ekrandan, 01:00:00). Mantıksal "veya" C'de `||` ile yazılır.

Ayrıca "ya da" ile "veya" aynı şey değildir. Mantıkta "ya da" **XOR**'dur: iki koşuldan yalnızca biri doğruysa doğrudur. "Veya" ise en az biri doğruysa doğrudur. Bu soruda iki koşulun kesişimi boş olduğu için XOR da aynı sonucu verir; kesişimi boş olan bir "veya" aslında "ya da"dır. Ama genel olarak ikisi farklıdır.

C'de **mantıksal** XOR operatörü yoktur. **Bit düzeyinde** XOR operatörü vardır ve `^` (şapka) ile yazılır.

> **Ders sonrası not:** Oturumun sonunda öğretim üyesi, `or` sözcüğünün C++'ta `||` için alternatif bir yazım olarak tanımlı olduğunu söyledi (C++98'den beri). Bu yüzden `.cpp` olarak kaydedilen dosyada kabul edilmiştir. Bu derste kod C standardında yazılır.

> **Ek bilgi (derste anlatılmadı):** C'de de `<iso646.h>` başlığı eklenirse `or`, `and`, `not` gibi sözcükler makro olarak tanımlanır ve kullanılabilir. Başlık eklenmeden bu sözcükler C'de operatör değildir.

## 6. Soru 3: Diziyi bir x değerine göre bölme

Soru: Kullanıcıdan önce dizinin eleman sayısı, sonra elemanları alınır ve diziye aktarılır. Sonra bir $x$ sayısı alınır. Dizideki elemanlar $x$ ile karşılaştırılır; $x$'ten küçük olanlar dizinin sol tarafına, büyük olanlar sağ tarafına gelecek biçimde dizi güncellenir. $x$ dizinin elemanı değildir. Sol ve sağ taraflardaki elemanların kendi aralarında sıralı olması gerekmez.

Örnek dizi ve $x$ değeri slayta elle yazıldı (ekrandan, 01:05:00):

$$n = 6,\quad [7,\ 4,\ 5,\ 3,\ 8,\ 9],\quad x = 6$$

İstenen sonuçta solda 3, 4, 5, sağda 7, 8, 9 bulunmalıdır (sıraları önemsiz).

### 6.1 Fikir

Bir öğrenci, $x$'ten büyük bir eleman görünce onu hemen sağındaki elemanla yer değiştirmeyi önerdi. Ama iki komşu elemanın ikisi de $x$'ten büyükse bu yöntem başa dönüp tekrar kontrol etmeyi gerektirir; öğretim üyesi bunun kabarcık sıralamasına benzeyen, gereksiz karmaşık bir çözüm olduğunu belirtti.

Kullanılan fikir şudur: büyük görülen elemanlar sondan, küçük görülen elemanlar baştan yığılır. Bunun için iki indeks tutulur: `bas` dizinin başını, `son` dizinin sonunu gösterir.

- `dizi[bas] > x` ise bu eleman sağa gitmelidir. `dizi[bas]` ile `dizi[son]` yer değiştirir. Artık `son` konumundaki eleman $x$'ten büyüktür ve bir daha bakılmasına gerek yoktur; `son` bir azaltılır (`son--`). `bas` artırılmaz, çünkü başa yeni gelen eleman henüz karşılaştırılmamıştır.
- Değilse eleman zaten solda kalmalıdır; `bas` bir artırılır (`bas++`).
- Döngü `bas < son` olduğu sürece sürer.

Yer değiştirme için üçüncü bir değişken (`temp`) kullanılır: önce `temp = dizi[bas]`, sonra `dizi[bas] = dizi[son]`, en son `dizi[son] = temp`.

### 6.2 Kod

Ana döngü (ekrandan, 01:20:00):

```c
bas=0;
son=n-1;

while(bas<son){

    if(dizi[bas]>x)
    {
        temp=dizi[bas];
        dizi[bas]=dizi[son];
        dizi[son]=temp;
        son--;

    }
    else{
        bas++;
    }
}
```

Dizi boyutu kurala uygun olarak `#define MAX 50` ile verildi. Aşağıdaki tam program, ekrandaki ana döngüye ekrandaki çıktı mesajlarına göre giriş ve yazdırma kısımları eklenerek kuruldu; değişken tanım satırları karede görünmediği için yeniden yazıldı (ara adım eklendi). `gcc -Wall` ile derlendi ve derstekiyle aynı girişte aynı sonucu verdi:

<!-- BELİRSİZ: Derste yazılan programın değişken tanımları ve elemanları yazdıran for döngüsünün ayrıntısı karelerde görünmüyor; aşağıdaki tanımlar ve yazdırma biçimi ajan tarafından tamamlandı. -->

```c
#include <stdio.h>
#define MAX 50

int main() {

    int n,x,i,j,temp,bas,son;
    int dizi[MAX];

    printf("Dizinin eleman sayisi kac olsun: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("dizinin %d elemani :",i);
        scanf("%d",&dizi[i]);
    }
    printf("X kac olsun");
    scanf("%d",&x);

    bas=0;
    son=n-1;

    while(bas<son){

        if(dizi[bas]>x)
        {
            temp=dizi[bas];
            dizi[bas]=dizi[son];
            dizi[son]=temp;
            son--;
        }
        else{
            bas++;
        }
    }

    for(j=0;j<n;j++){
        printf("%d ",dizi[j]);
    }

    return 0;
}
```

### 6.3 Adım adım çalıştırma

Derste girilen dizi `7 4 5 8 3 9`, $x=6$ idi ve ekranda `3 4 5 8 9 7` sonucu görüldü (ekrandan, 01:25:00). (Derste elemanlar aralarında boşluk olmadan yazdırıldığı için çıktı bitişik görünüyordu.)

| Adım | bas | son | dizi[bas] | işlem | dizi |
|---|---|---|---|---|---|
| 1 | 0 | 5 | 7 | 7 > 6: 7 ile 9 yer değiştirir, son = 4 | 9 4 5 8 3 7 |
| 2 | 0 | 4 | 9 | 9 > 6: 9 ile 3 yer değiştirir, son = 3 | 3 4 5 8 9 7 |
| 3 | 0 | 3 | 3 | 3 ≤ 6: bas = 1 | 3 4 5 8 9 7 |
| 4 | 1 | 3 | 4 | 4 ≤ 6: bas = 2 | 3 4 5 8 9 7 |
| 5 | 2 | 3 | 5 | 5 ≤ 6: bas = 3 | 3 4 5 8 9 7 |
| 6 | 3 | 3 | – | bas < son yanlış, döngü biter | 3 4 5 8 9 7 |

Sonuçta 6'dan küçük olanlar (3, 4, 5) solda, büyük olanlar (8, 9, 7) sağdadır. Sonuç tam sıralı değildir; istenen de bu değildir.

### 6.4 Karmaşıklık ve QuickSort bağlantısı

Öğretim üyesi bu çözümün karmaşıklığını sordu. Her adımda ya `bas` bir artar ya `son` bir azalır; ikisi birbirine doğru ilerler ve buluştuklarında döngü biter. Bu yüzden en fazla $n$ adım vardır; karmaşıklık $O(n)$'dir.

Aynı işi önce diziyi sıralayarak yapmak da mümkündür, ama kabarcık sıralaması (bubble sort) gibi bir yöntemle $n^2$, daha iyi bir sıralama algoritmasıyla $n \log n$ adım gerekir. $n$, $n \log n$'den çok daha iyidir. Burada amaç bir şeyi sıralamak değil, işi daha az adımla yapmaktır.

> **Hocanın vurgusu:** Hazır bilinen bir algoritmayı (örneğin bir sıralamayı) kullanmak her zaman en iyi çözüm değildir. Soru sıralama istemiyorsa sıralamaya girmeden daha az karmaşık bir çözüm aranmalıdır.

Bu işlem **QuickSort** algoritmasını iyi yapan ön işlemlerden biridir. Buradaki 6 bir **pivot** (referans) elemanı gibi düşünülebilir: işlemden sonra pivotun solunda ondan küçükler, sağında ondan büyükler bulunur. QuickSort bu işi parçalar üzerinde tekrar tekrar uygulayarak diziyi sıralar; ayrıntıları sıralama algoritmaları ve özyinelemeli algoritmalar konusunda görülecektir.

## 7. İlk iki sorunun dizi kullanan çözümleri ve bellek karmaşıklığı

### 7.1 Sayıyı dizi ile ters çevirme

İlk sorunun dizi kullanan çözümü hazır olarak gösterildi (ekrandan, 01:30:00):

```c
#include <stdio.h>
#define MAX 50
int main() {
    int sayi, kalan, tersi = 0;
    int rakamlar[MAX];
    int i = 0, j;

    printf("Bir sayi girin: ");
    scanf("%d", &sayi);

    while (sayi != 0) {
        kalan = sayi % 10;
        rakamlar[i] = kalan;
        i++;
        sayi /= 10;
    }

    for (j = 0; j < i; j++) {
        tersi = tersi * 10 + rakamlar[j];
    }

    printf("Sayinin tersi: %d", tersi);

}
```

Sayı 0'dan farklı olduğu sürece modu alınır ve kalan dizinin `i`'nci elemanına yazılır. Sonra dizideki rakamlar baştan sona okunarak ters sayı kurulur. Kod `gcc -Wall` ile derlendi (ekranda görünmeyen `return 0;` ile birlikte) ve 123 girişinde 321 verdi.

Öğretim üyesi iki çözümü karşılaştırdı:

- **Zaman karmaşıklığı** aynıdır: ikisi de sayının basamak sayısı kadar adım atar.
- **Bellek karmaşıklığı** farklıdır. Dizisiz çözümde sayı ve tersi için iki `int` (4 + 4 bayt) yeter. Dizili çözümde bunlara ek olarak basamak sayısı kadar elemanlı bir `int` dizisi gerekir; her eleman 4 bayttır. Yani basamak sayısıyla orantılı ek bellek harcanır.

> **Hocanın vurgusu:** Her zaman dizi kullanmak iyi bir çözüm değildir. Algoritmik işlemlerle güzel bir yol bulunabiliyorsa diziye gerek yoktur. Bir soruda "dizi kullanmadan" denmişse dizi kullanılmamalıdır.

**Soru:** Dizili çözümde belleği azaltmak için ne yapılabilir?

**Cevap:** Bir öğrenci rakamları `char` olarak tutmayı önerdi. Öğretim üyesi bunu geliştirdi: rakam tek bir semboldür. Rakamlar dizisi `int` yerine `char` dizisi yapılırsa her rakam 1 bayt yer kaplar; 8 basamaklı bir sayı için 8 bayt yeter. Ekrana yazdırırken de bunlar bir döngüyle yazdırılır. Böylece aynı bilgi daha az bellekle saklanır.

### 7.2 Polinomu dizi ile hesaplama

İkinci sorunun dizi kullanan sürümünde katsayılar bir diziye alınır; hesap aynı kalır (ekrandan, 01:40:00):

```c
int katsayilar[MAX];
int x, sonuc = 0, temp;
char devam;

do {
    printf("Denklemin derecesini girin: ");
    scanf("%d", &derece);
    printf("Denklemin x degerini girin: ");
    scanf("%d", &x);
    katsayi = 1;
    for (i = 0; i <= derece; i++) {
        printf("x^%d nin katsayisini girin: ", i);
        scanf("%d", &katsayilar[i]);
        sonuc = sonuc + katsayilar[i] * temp;
        temp = temp * x;
    }

    printf("Denklemin sonucu: %d", sonuc);
    printf("\nTekrar denemek icin E ya da e?");
    scanf(" %c", &devam); // neden %c öncesi bosluk var acikla
} while (devam == 'E' || devam == 'e');
```

<!-- BELİRSİZ: Bu kodun ilk dört satırı (derece, i ve katsayi tanımları) karede görünmüyor. -->

> **Ders sonrası not:** Ekrandaki bu hazır kodda döngüden önce `katsayi = 1;` yazılmıştır; doğrusu `temp = 1;` olmalıdır. Aksi halde `temp` ilk değer almadan kullanılır. Ayrıca `sonuc` her turun başında sıfırlanmalıdır (bkz. Bölüm 3.3). Bu iki düzeltmeyle kod `gcc -Wall` ile derlendi; derece 2, $x=4$, katsayılar 4, 2, 3 için 60 verdi.

Öğretim üyesi, katsayıları saklamanın hangi durumda gerekli olduğunu açıkladı. Yalnızca bir polinomun değeri hesaplanacaksa katsayıları saklamaya gerek yoktur; ilk çözüm de saklamaz. Ama örneğin $x^2+3x$ ile $5x^2+7x$ polinomları analitik olarak toplanacaksa, ilk polinomun katsayıları ikincisi girilene kadar bir yerde saklanmalıdır. Bunun için bir dizi kullanılabilir; başka yollar da vardır: biri katsayıları, biri dereceleri tutan iki dizi ya da bir matris.

Bu durumda zaman karmaşıklığı değişmez; ek bellek gerekir, ama bu ek belleğe gerçekten ihtiyaç vardır. Polinomlar toplanırken, çarpılırken ya da başka işlemler yapılırken katsayıların bir yerde tutulması çoğu zaman zorunludur.

## 8. printf'in dönüş değeri, return 0 ve standart akışlar

### 8.1 `return 0` ve printf'in döndürdüğü değer

**Soru:** `int main`'in sonuna `return` koymazsak sorun çıkar mı?

**Cevap:** `return 0;` programın doğru biçimde, sonuna kadar gelerek bittiğini gösterir. Öğretim üyesi bunu göstermek için `printf`'in de bir değer döndürdüğünü hatırlattı: `printf`, ekrana yazdığı karakter sayısını döndürür. Dizili ters çevirme kodundaki yazdırma satırı şöyle değiştirildi (ekrandan, 01:35:00):

```c
printf("\n%d",printf("Sayinin tersi: %d", tersi));
```

İçteki `printf` önce çalışır ve `Sayinin tersi: 321` yazar. Bu metin 18 karakterdir (`Sayinin tersi: ` 15 karakter, `321` 3 karakter). Dıştaki `printf` bu 18 değerini yeni satırda yazar. Kod `gcc -Wall` ile derlendi; 123 girişinde ekrana önce `Sayinin tersi: 321`, alt satıra `18` yazıldı.

Derste `return 0;` varken program "return value 0" ile bitti; yani program sağ salim kapandı. `return 0;` kaldırılınca dönüş değeri 3 göründü. Bu 3, son çalışan `printf`'in yazdığı karakter sayısıydı: `\n` bir karakter, `18` iki karakter. `return 0;` yazmak, programın sonuna kadar geldiğini, arada bir istisna (exception), tuzak (trap), kesme (interrupt) ya da bölümleme hatası (segmentation fault) gibi bir şey olmadan kapandığını bildirmenin yoludur.

> **Ders sonrası not:** `main` sonunda `return` yoksa ne döneceği C standardının sürümüne bağlıdır. C99 ve sonrasında `main`'in sonuna ulaşılması `return 0;` ile aynıdır. Derste kullanılan derleyici büyük olasılıkla eski (C89/gnu90) varsayılanla derlediği için dönüş değeri, son `printf`'in döndürdüğü değer gibi rastgele bir sayı oldu. Her durumda `return 0;` açıkça yazılmalıdır.

**Soru:** `printf`'i bir metnin uzunluğunu ölçmek için kullanabilir miyiz?

**Cevap:** Kısmen. İçteki `printf`'e `%s` ile bir metin verilirse dönen değer o metnin karakter sayısıdır. Derste iç `printf`'e "merhaba" metni yazdırıldı; ekrana `merhaba` ve onun uzunluğu olan 7 yazıldı. Bu dönen değer bir değişkene de atanabilir ya da bir `if` koşulunda kullanılabilir.

<!-- BELİRSİZ: "merhaba" denemesinde iç printf satırının tam biçimi ve programın dönüş değerinin 2 olarak okunması altyazıdan kesin çıkmıyor; ilgili an karede görünmüyor. -->

### 8.2 Standart akışlar

Tampon konusu açılmışken öğretim üyesi işletim sistemiyle ilişkiyi anlattı. Bir program çalıştığında işletim sisteminin yönetiminde çalışan bir **süreç (process)** olur ve işletim sisteminin verdiği izinler ve imkânlar ölçüsünde çalışır. Bu imkânlardan biri, işletim sisteminin programa ayırdığı üç standart akıştır:

- `stdin`: standart giriş (klavye ile program arasındaki giriş tamponu),
- `stdout`: standart çıkış,
- `stderr`: standart hata.

Bu kavramlar başka programlama dillerinde de vardır, çünkü işletim sistemiyle haberleşmenin standart yoludur. Ayrıntıları işletim sistemleri dersinde görülecektir.

## 9. Soru kısıtları ve iyi algoritma

Oturumun sonunda öğretim üyesi, sorulardaki kısıtların önemine değindi. Bir soruda "dizi kullanmadan yapın", "tek bir `for` döngüsüyle yapın, iç içe iki döngü kullanmayın" ya da "sıralama yapmadan yapın" denebilir; hatta "`if` kullanmadan" çözülmesi istenen sorular da olabilir. Bu kısıtlar sorunun parçasıdır; çözüm, çalışsa bile, bu kısıtlara uymuyorsa sorunun istediğini karşılamaz.

Bu ders önceki dönemin programlama dersinden farklıdır: gelişigüzel bir algoritma değil, daha iyi bir algoritma aranır. Kullanılan yapılar (`for`, `while`, `do-while` gibi) yeni değildir; yeni olan, aynı araçlarla en mantıklı ve en az karmaşık çözüme ulaşmaktır. İleride bunlara fonksiyonlar da eklenecektir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00): Kullanıcıdan alınan bir sayıyı tersine çeviren programı yazınız. Örnek: girilen sayı 1283, ters sayı 3821. Önce dizi kullanmadan, sonra dizi kullanarak çözünüz.

> **Çözüm:** Dizisiz çözüm Bölüm 2.3'te, dizili çözüm Bölüm 7.1'dedir. Temel adım `kalan = sayi % 10; ters = ters * 10 + kalan; sayi /= 10;` döngüsüdür.

**Soru 2** (ekrandan, 00:30:00): Kullanıcıdan tek değişkenli bir polinom denkleminin derece sayısını, her bir derecenin katsayısını, değişken değerini alan ve sonucu ekrana yazan programı yazınız. Örneğin $N=2$, $a=3$, $b=2$, $c=4$ için $3x^2+2x+4$; $x=4$ için sonuç 60.

> **Çözüm:** Bölüm 3.2'deki program. $x=4$ için `temp` sırasıyla 1, 4, 16 olur; toplam $4\cdot 1 + 2\cdot 4 + 3\cdot 16 = 60$.

**Soru 3** (ekrandan, 01:05:00): Kullanıcıdan bir dizinin eleman sayısını ve elemanlarını, sonra bir $x$ sayısı alınız. Dizideki elemanları $x$'ten küçükler sola, büyükler sağa gelecek biçimde yeniden düzenleyen programı yazınız. Örnek: `[7 4 5 3 8 9]`, $x = 6$.

> **Çözüm:** Bölüm 6.2'deki `bas`/`son` iki indeksli program, $O(n)$. Bu örnek için sonuç `3 4 5 8 9 7` olur (yukarıdaki dizi derste `7 4 5 8 3 9` sırasıyla girilmişti; iki sıra için de sonuç aynıdır).

**Soru 4** (derste sözlü, 00:52:01): `while(devam=='E'|| devam=='e')` koşulunu, aynı anlamı koruyarak başka nasıl yazabilirsiniz?

> **Çözüm:** De Morgan kuralıyla `while(!(devam != 'E' && devam != 'e'))`.

**Soru 5** (derste sözlü, 01:22:03): Soru 3'teki `while` döngüsünün karmaşıklığı nedir?

> **Çözüm:** Her adımda `bas` artar ya da `son` azalır; en fazla $n$ adım, yani $O(n)$. Önce sıralama yapılsaydı kabarcık sıralamasıyla $O(n^2)$, iyi bir sıralamayla $O(n\log n)$ olurdu.

**Soru 6** (derste sözlü, 01:26:38): Sayı ters çevirmenin dizili çözümünün dizisiz çözümden karmaşıklık olarak farkı var mı?

> **Çözüm:** Zaman karmaşıklığı aynıdır (basamak sayısı kadar adım). Bellek karmaşıklığı artar: basamak sayısı kadar elemanlı ek bir dizi gerekir.

**Soru 7** (derste sözlü, 01:30:26): Dizi kullanarak ters çevirmede bellek kullanımını nasıl azaltabiliriz?

> **Çözüm:** Rakamlar `int` yerine `char` dizisinde tutulursa her rakam 4 yerine 1 bayt yer kaplar.

**Soru 8** (derste sözlü, 01:41:45): `scanf(" %c", &devam)` satırındaki boşluk kaldırılırsa program neden yanlış çalışır ve sorun nasıl giderilir?

> **Çözüm:** Önceki `%d` okumasından kalan Enter (`\n`) `%c` ile okunur ve döngü biter. Boşluk bu beyaz boşluğu atlar; derste alternatif olarak `scanf`'ten önce `fflush(stdin);` da gösterildi.

## Dersin Toparlaması

Bu uygulama oturumunda üç temel problem C ile çözüldü. Sayıyı tersine çevirmede `% 10` ile son basamağı alıp `/ 10` ile atma ve `ters * 10 + kalan` ile yeni sayı kurma tekniği görüldü. Polinom değerinde kuvveti her seferinde yeniden hesaplamak yerine bir önceki kuvveti $x$ ile çarparak $O(n)$ bir çözüm kuruldu; büyük dereceden başlayıp kuvveti ayrı bir döngüyle hesaplamanın $O(n^2)$'ye çıktığı gösterildi. Diziyi bir $x$ değerine göre bölmede iki indeksle, sıralama yapmadan $O(n)$ bir çözüm yazıldı ve bunun QuickSort'taki pivot etrafında bölme adımı olduğu belirtildi.

Yan konular olarak `do-while` döngüsü, giriş tamponunda kalan Enter karakteri ve `" %c"` çözümü, De Morgan kuralıyla koşul dönüşümü, C'de `or` operatörünün bulunmadığı, "veya" ile "ya da" (XOR) farkı, `printf`'in yazdığı karakter sayısını döndürmesi, `return 0`'ın anlamı ve `stdin`/`stdout`/`stderr` akışları ele alındı. Dizi kullanan çözümlerle karşılaştırma, aynı zaman karmaşıklığında dizinin ek bellek demek olduğunu ve diziye yalnızca veriyi gerçekten saklamak gerektiğinde (örneğin iki polinomu toplarken) başvurulması gerektiğini gösterdi. Sıralama algoritmaları ve özyinelemeli algoritmalar ilerleyen derslerde ele alınacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
