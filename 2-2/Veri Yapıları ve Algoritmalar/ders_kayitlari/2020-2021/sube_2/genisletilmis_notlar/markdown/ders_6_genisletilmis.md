# Ders 6 Genişletilmiş Notu: Kilitli Dolap Problemi, Zaman-Bellek Dengesi ve İkili Aramanın Ön Koşulu

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Oturumun Yapısı
- 2. Kilitli Dolap Probleminin Çözüm Deseni
- 3. Tekrar Etmeyen Sayılar Problemi ve Zaman-Bellek Dengesi
- 4. Doğrusal Arama ve İkili Arama Tekrarı
- 5. Kod Yazmadan Önce Algoritma Tasarlamak
- Örnek Sorular
- Dersin Toparlaması

## 1. Oturumun Yapısı

Bu kayıt kısa bir uygulama oturumudur. Hoca oturuma, önceki uygulamada "açık uçlu" bırakıp düşünülmesini istediği iki problemi sorarak başladı. Öğrenciler buldukları yaklaşımları anlattı, hoca da bu yaklaşımlar üzerinden genel ilkelere değindi. Ardından önceki teori dersinde anlatılan doğrusal arama (sequential/linear search) ve ikili arama (binary search) kısaca tekrar edildi. Oturumun geri kalanı öğrencilerin kendi başlarına çözdüğü uygulamalı bir çalışmaya ayrıldı. Bu çalışmanın sorusu kayıtta ekranda görünmüyor; kameranın kapalı olduğu sessiz bir bölümle kayıt sürüyor. Bu yüzden notta o sorunun metni yoktur.

## 2. Kilitli Dolap Probleminin Çözüm Deseni

### 2.1 Problem

Problemin derste hatırlatılan hâli şudur: başta bütün dolaplar kapalıdır. Birinci kişi bütün dolapları açar. Sonraki her kişi, kendi sırasının katı olan dolapların durumunu tersine çevirir (kapalıysa açar, açıksa kapatır). Bütün kişiler geçtikten sonra hangi dolapların açık kalacağı sorulur.

### 2.2 Öğrencinin bulduğu desen

Bir öğrenci bu problemin "bir matematik problemi gibi" olduğunu, desen bulununca çözümün çıktığını söyledi. Bulduğu desen şuydu:

- Dolabın numarası bir tam kare ise son durumu, ilk durumunun tersi olur. Çünkü karekök olan bölen iki kez değil, aynı kişi olarak bir kez sayılır.
- Numara tam kare değilse dolap hangi durumla başladıysa o durumla biter.

Bu desenin nedeni bölen sayısıdır (ara adım eklendi). $k$ numaralı dolaba, sırası $k$'yi bölen her kişi bir kez dokunur; yani dolabın durumu $k$'nin bölen sayısı kadar değişir. Bölenler $d$ ve $k/d$ biçiminde çiftler hâlinde gelir. Örneğin $12$ için $(1,12)$, $(2,6)$, $(3,4)$ çiftleri vardır ve bölen sayısı $6$'dır. $d = k/d$ eşitliği yalnız $k = d^2$ iken, yani $k$ tam kare iken sağlanır; o zaman $d$ kendisiyle eşleşir ve bir kez sayılır. Örneğin $16$ için $(1,16)$, $(2,8)$, $(4,4)$ çiftlerinden bölen sayısı $5$ çıkar. Sonuç olarak tam karelerin bölen sayısı tek, diğer sayılarınki çifttir. Tek sayıda değişen dolap başlangıcın tersinde, çift sayıda değişen dolap başlangıç durumunda kalır.

Başta bütün dolaplar kapalı olduğuna göre sonunda yalnız tam kare numaralı dolaplar açık kalır. 100 dolap için bu durum python ile denendi; açık kalanlar $1, 4, 9, 16, 25, 36, 49, 64, 81, 100$ çıktı.

> **Ders sonrası not:** Hoca toparlarken "tam kare olanlar dolapları kurtarıyor, kapılar açık kalmıyor; tam kare olmayan herkesin dolabı açık kalıyor" dedi. Başta bütün dolaplar kapalıyken doğrusu tersidir: tam kare numaralı dolaplar açık kalır, diğerleri kapanır. Öğrencinin anlattığı desen doğrudur. <!-- BELİRSİZ: hocanın cümlesi altyazıda bozuk aktarılmış olabilir. -->

### 2.3 Hocanın yorumu

Hoca bunun aslında bir matematik problemi olduğunu kabul etti. Yine de bir probleme çözüm yaklaşımı getirirken "beni neler bekliyor, nasıl bir süreç bekliyor" diye önce süreci düşünmenin iyi bir alışkanlık olduğunu, bu problemin bunu göstermek için yararlı olduğunu söyledi.

## 3. Tekrar Etmeyen Sayılar Problemi ve Zaman-Bellek Dengesi

### 3.1 Öğrencinin yaklaşımı

Diğer problem için bir öğrenci optimal bir çözüm bulamadığını, bulduğu çözümün kaba kuvvete (brute force) dayandığını söyledi. Hoca bunu açmasını isteyince öğrenci şunları anlattı:

- Dizi üzerinde gezmek dışında bir yöntem bulamadığı için karmaşıklık her durumda $O(n^2)$ oluyor. <!-- BELİRSİZ: altyazıda "Ankara" yazıyor; bağlamdan "n kare" olarak yorumlandı. -->
- Farklı bir dizi oluşturmak da bir seçenek. Ama tam sayılardan söz edildiği için çok büyük değerler gelebilir ve bu yardımcı dizi için çok büyük bir yer ayırmak gerekir.
- Bu yüzden doğrudan kaba kuvvetle aramak dışında, döngü koşullarıyla aramayı biraz kısıtlamak mümkün, ama karmaşıklık yine $O(n^2)$ kalıyor.

### 3.2 Zaman ve bellek karmaşıklığı

Hoca öğrencinin bu tartışmayı yapmasını çok değerli buldu. Bir dizi, yedek bir dizi ya da yedek bir veri yapısı kullanmak çözümü hızlandırabilir, ama bu durumda bellek (space) karmaşıklığı artar. Programcı bazen zaman ve bellek karmaşıklığını dengelemek zorunda kalır, bazen de bellek karmaşıklığından yana tercih yapar. Örneğin kaynaklar kısıtlıysa çözüm buna uygun seçilir. Her durumda amaç, o hafta görülen Büyük-O gösterimindeki karmaşıklığı mümkün olduğunca azaltmaktır.

> **Hocanın vurgusu:** Zaman ve bellek karmaşıklığı birbirine karşı dengelenebilir. Yardımcı veri yapısı zamanı azaltırken belleği artırır; kaynak kısıtına göre karar verilir.

> **Ek bilgi (derste anlatılmadı):** Değer aralığı küçük ve biliniyorsa (örneğin 1 ile 1000 arası), her değerin kaç kez geçtiğini tutan bir sayaç dizisi kullanılabilir. Bu yöntem diziyi bir kez gezdiği için zamanı $O(n)$'e indirir, buna karşılık değer aralığı kadar ek bellek ister. Öğrencinin belirttiği gibi değerler çok büyük olabiliyorsa bu ek bellek kabul edilemez hâle gelir; bu, zaman-bellek dengesinin tipik bir örneğidir.

## 4. Doğrusal Arama ve İkili Arama Tekrarı

Hoca, önceki teori dersinde doğrusal arama ve ikili arama anlatıldığını hatırlatıp öğrencilerin bunları deneyip denemediğini sordu.

**Soru:** Dizi sıralı değil demiştik. O yüzden ikili arama pek mantıklı değil, değil mi?

**Cevap:** Evet. İkili arama için önce dizinin sıralanması ya da bir şekilde sıralı olmasının garanti edilmesi gerekir. Bu, insertion sort'a benzer bir mantıkla da sağlanabilir.

**Soru:** Verileri bir dizi olarak mı, yoksa sırayla tek tek mi alacağız? Ona bağlı değil mi?

**Cevap:** Bu, problemin doğasına göre değişir. Bazı problemlerde veriler tek tek alındığı için her yeni eleman insertion sort'taki gibi doğru yerine eklenerek dizi baştan sıralı tutulabilir. Veriler karışık bir sırada geliyorsa bu yapılamaz; ikili arama yapabilmek için önceden bir sıralama yapmak gerekir. Dizinin sıralı olduğu biliniyorsa ikili arama kullanılabilir.

Hoca, ikili aramadaki `low`, `mid` ve `high` indisleri konusunda kafası karışan öğrencilerin kodu oturup yazmasını ve denemesini önerdi.

> **Ek bilgi (derste anlatılmadı):** İkili aramada `low` ve `high` aranan bölgenin sınırlarını, `mid` ise ortadaki indisi gösterir. Aranan değer `mid` konumundakinden küçükse `high = mid - 1`, büyükse `low = mid + 1` yapılır; `low > high` olunca değer dizide yoktur. Her adımda bölge yarıya indiği için sıralı dizide arama $O(\log n)$ sürer.

## 5. Kod Yazmadan Önce Algoritma Tasarlamak

Uygulamalı çalışmaya geçmeden önce hoca, doğrudan C kodu yazmaya başlamamayı, önce bir algoritma tasarlamayı istedi. Özellikle karmaşıklıklar açısından nasıl bir çözüm geliştirileceği ve problemde istenenin nasıl karşılanacağı üzerine düşünülmesi gerektiğini söyledi. Kodların bir editörde yazılıp derlenerek denenmesi, kaynak kod dosyasının ANSI C standardında yazılması gerektiğini de hatırlattı.

## Örnek Sorular

**Soru 1 (derste sözlü, 00:03:46-00:04:50).** Başta bütün dolaplar kapalıdır. Birinci kişi bütün dolapları açar, sonraki her kişi kendi sırasının katı olan dolapların durumunu tersine çevirir. Sonunda hangi dolaplar açık kalır?

**Çözüm (derste bir öğrenci verdi):** Bir dolabın durumu, numarasının bölen sayısı kadar değişir. Yalnız tam karelerin bölen sayısı tektir, bu yüzden yalnız tam kare numaralı dolaplar başlangıcın tersinde, yani açık kalır. 100 dolap için açık kalanlar: $1, 4, 9, 16, 25, 36, 49, 64, 81, 100$ (python ile doğrulandı).

**Soru 2 (derste sözlü, 00:04:51-00:06:01).** Rastgele üretilmiş $n$ sayılık bir dizide yalnız bir kez geçen (tekrar etmeyen) sayıların sayısını bulun. <!-- BELİRSİZ: problemin tam metni bu kayıtta okunmuyor; değer aralığının büyük olasılıkla 1-1000 olduğu ve dizinin sıralanmadan çözülmesinin istendiği önceki uygulamadan alındı. -->

Derste bir öğrenci kaba kuvvetle $O(n^2)$ bir çözüm bulduğunu, yardımcı dizi kullanılırsa belleğin büyüyeceğini söyledi; tam çözüm verilmedi.

> **Çözüm (derste verilmedi):** Değerler 1 ile 1000 arasındaysa 1001 elemanlı bir sayaç dizisi tutulur. Dizi bir kez gezilerek her değerin sayacı artırılır, sonra sayacı tam 1 olan değerler sayılır. Zaman $O(n + 1000)$, ek bellek değer aralığı kadardır. Aşağıdaki program `gcc -Wall -ansi -pedantic` ile derlendi; `{5, 3, 5, 7, 1000, 3, 8}` için çıktı `3`'tür (7, 1000 ve 8).

```c
#include <stdio.h>

#define MAKS 1000

int tekrarsiz_say(const int dizi[], int n)
{
    int sayac[MAKS + 1] = {0};
    int i, adet = 0;

    for (i = 0; i < n; i++)
        sayac[dizi[i]]++;
    for (i = 1; i <= MAKS; i++)
        if (sayac[i] == 1)
            adet++;
    return adet;
}

int main(void)
{
    int dizi[] = {5, 3, 5, 7, 1000, 3, 8};
    int n = sizeof(dizi) / sizeof(dizi[0]);

    printf("%d\n", tekrarsiz_say(dizi, n));
    return 0;
}
```

## Dersin Toparlaması

Bu kısa uygulama oturumunda önce iki düşünme problemi konuşuldu. Kilitli dolap probleminde çözümün bölen sayısına dayandığı, yalnız tam kare numaralı dolapların tek sayıda kez değiştiği görüldü. Tekrar etmeyen sayılar probleminde kaba kuvvetin $O(n^2)$ zaman aldığı, yardımcı bir veri yapısının zamanı kısaltırken belleği artırdığı tartışıldı ve zaman ile bellek karmaşıklığı arasındaki denge vurgulandı.

Son olarak ikili aramanın ancak sıralı dizide kullanılabildiği hatırlatıldı: veri tek tek geliyorsa insertion sort mantığıyla sıralı tutulabilir, karışık geliyorsa önce sıralanmalıdır. Hoca, kod yazmadan önce algoritmayı ve karmaşıklığını düşünmenin önemini bir kez daha belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
