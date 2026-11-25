# Ders 21 Genişletilmiş Notu: Uygulama: Vize Sorularının Çözümü (Rastgele Sayılarla Olasılık, Özyineleme İzleme), En Uzun Ardışık Dizi ve Özyinelemeli Dizilim/Kombinasyon Üretimi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Rastgele sayılarla olasılık: 1. vize sorusu
- 2. İki koşullu olasılık bölgesi: 2. vize sorusu
- 3. Özyinelemeli fonksiyonu tabloyla izleme: 3. vize sorusu
- 4. Geri dönüşte çalışan özyineleme: 4. vize sorusu
- 5. En uzun ardışık dizi (Longest Sequence)
- 6. Özyineleme ile tekrarlı dizilim ve tekrarsız kombinasyon üretme
- 7. Rastgele nokta deneyinin görselleştirilmesi
- 8. Proje problemi üzerine algoritmik notlar
- Örnek Sorular
- Dersin Toparlaması

Bu oturum bir uygulama (problem çözme) oturumuydu. Önce vize sınavında sorulan dört soru çözüldü, ardından iki algoritmik problem C ile kodlandı. Oturumun sonunda rastgele sayı sorularının bir görselleştirmesi gösterildi ve proje problemi tanıtıldı.

## 1. Rastgele sayılarla olasılık: 1. vize sorusu

### 1.1 Soru

Ekrandaki soru şöyledir (ekrandan, 00:15:00):

> Aşağıdaki sözde kod çalıştırıldığında `say/N` değeri $N$'in büyük değerleri için kaça yakınsar? (NOT: `rand()`: 0-1 aralığında ondalıklı rastgele bir sayı üretir. $x^2$'nin integrali $x^3/3$'tür.)

```text
oku(N);
say=0;
for i=1:N
   s1=rand();
   s2=rand();
   if (s1*s1<=s2)
      say=say+1;
   end
end
yaz(say/N)
```

### 1.2 Neden "N'in büyük değerleri için"?

Kod $N$ kez iki rastgele sayı üretir ve $s_1^2 \le s_2$ koşulu sağlanınca sayacı artırır. Bu yüzden `say/N`, koşulun ortalama olarak sağlanma oranıdır. $N$ küçükken bu oran rastgeleliğe çok bağlıdır ve tahmin edilemez. $N$ büyüdükçe üretilen sayılar 0-1 aralığına eşit biçimde dağılır ve oran koşulun gerçek olasılığına yakınsar. Soruda özellikle "büyük değerler" denmesinin nedeni budur.

### 1.3 Olasılık neden alan oranıdır?

Olasılığın genel tanımı "istenen durum sayısı / tüm durumların sayısı"dır. Yazı-tura atışında tüm durumlar yazı ve turadır. Burada ise 0 ile 1 arasında sonsuz tane sayı olduğu için hem tüm durumlar hem de istenen durumlar sonsuzdur. Sonsuz nokta tek değişkende bir doğru parçası, iki değişkende bir düzlem bölgesi (alan), üç değişkende bir hacim oluşturur. İki değişken ($s_1$, $s_2$) olduğundan:

$$P = \frac{\text{istenen bölgenin alanı}}{\text{tüm uzayın alanı}}$$

Tüm uzay $0 \le s_1 \le 1$, $0 \le s_2 \le 1$ birim karesidir, alanı 1'dir. Bu karenin dışı uzaya dahil değildir.

### 1.4 Bölgenin çizilmesi ve alan hesabı

Eşitsizlik bölgesi çizilirken önce eşitlik durumu çizilir: $s_2 = s_1^2$ parabolü (ekrandan, 00:15:00). Sonra bir test noktasıyla hangi tarafın istendiğine bakılır: $s_1 = 0$, $s_2 = 1$ için $0 \le 1$ doğrudur; demek ki parabolün **üstündeki** bölge istenir.

Bu bölgenin alanını doğrudan bulmak yerine tümleyeni hesaplanır. Parabolün altındaki bölgeye $A$, üstündekine $B$ denirse:

$$A = \int_0^1 x^2\,dx = \left.\frac{x^3}{3}\right|_0^1 = \frac{1}{3}, \qquad B = 1 - A = \frac{2}{3}$$

Sonuç: `say/N` değeri $2/3 \approx 0.667$'ye yakınsar.

### 1.5 C ile simülasyon ve tamsayı bölmesi

Sözde kod C'ye aktarılıp çalıştırıldı. Koddaki önemli nokta, oran hesaplanırken ifadenin `1.0 *` ile çarpılmasıdır.

**Soru:** Burada neden `1.0` ile çarptık? **Cevap:** Tamsayı bölmesi olmasın diye. `say` ve `n` ikisi de `int` olduğu için `say/n` tamsayı bölmesi yapar ve ondalık sonuç kaybolur; ekrana `float` yazdırılmaya çalışılsa bile sonuç yanlış olur. İfadeye bir ondalık sayı katılarak tür dönüşümü (typecasting) yapılır.

Çalıştırmada küçük $N$ için 0.70, 0.60 gibi birbirinden farklı sonuçlar çıktı; $N = 1\,000\,000$ için iki denemede de 0.66 çıktı. Ajan tarafından Python ile yapılan $10^6$ örnekli kontrol de yaklaşık 0.667 verdi.

## 2. İki koşullu olasılık bölgesi: 2. vize sorusu

### 2.1 Soru

(ekrandan, 00:20:00)

> Aşağıdaki sözde kod çalıştırıldığında `say/N` değeri $N$'in büyük değerleri için kaça yakınsar? (`rand()`: 0-1 aralığında ondalıklı rastgele bir sayı üretir.)

```text
oku(N);
say=0;
for i=1:N
   s1=rand();
   s2=rand();
   if (s1>1-s2) && (s2<0.5)
      say=say+1;
   end
end
yaz(say/N)
```

### 2.2 Çözüm

Yine birim kare çizilir ve iki koşulun ortak bölgesi aranır.

- **Birinci koşul $s_1 > 1 - s_2$:** Önce eşitlik $s_1 = 1 - s_2$ çizilir. $s_2 = 0$ iken $s_1 = 1$, $s_1 = 0$ iken $s_2 = 1$ olduğundan doğru $(1,0)$ ve $(0,1)$ noktalarından geçer. Test noktası $(0,0)$ için $0 > 1$ yanlıştır; demek ki istenen bölge doğrunun öbür (sağ-üst) tarafıdır.
- **İkinci koşul $s_2 < 0.5$:** $s_2 = 0.5$ yatay doğrusunun altı. Bu doğru, birinci doğruyu $s_2 = 0.5$ iken $s_1 = 0.5$ noktasında keser.

İki koşulu birlikte sağlayan tek bölge, köşeleri $(1,0)$, $(1, 0.5)$ ve $(0.5, 0.5)$ olan dik üçgendir. Tabanı ve yüksekliği $0.5$'tir:

$$P = \frac{1}{2} \cdot \frac{1}{2} \cdot \frac{1}{2} = \frac{1}{8} = 0.125$$

C ile çalıştırmada $N=10$ için bir denemede 0, bir başkasında 0.1 çıktı; büyük $N$ için 0.12 civarı değer, yani $1/8$ elde edildi. Ajanın Python kontrolü de yaklaşık 0.125 verdi.

## 3. Özyinelemeli fonksiyonu tabloyla izleme: 3. vize sorusu

### 3.1 Soru

(ekrandan, 00:25:00)

```text
main()
   i=82, j=3;
   f(i,j);

f(i, j)
   if (i==0)
      return 0;
   else
      return f(i/j, j)+1;
```

`f` fonksiyonunun döndürdüğü sonuç sorulmaktadır.

### 3.2 Çözüm

`f` kendini çağıran (özyinelemeli) bir fonksiyondur. Özyinelemede en önemli konu **durma koşulu**dur; burada `i == 0`'dır. `i` sıfır değilse `i`, `j`'ye bölünüp fonksiyon yeniden çağrılır ve dönen sonuca 1 eklenerek bir üst çağrıya döndürülür. Soru C mantığıyla, yani tamsayı bölmesiyle düşünülür: $82/3 = 27.33\ldots$ değil 27, $1/3 = 0.33\ldots$ değil 0 olur.

İzleme tablosu (her satır bir çağrı):

| Çağrı | `i` | `j` | `i == 0`? | Dönen değer |
|---|---|---|---|---|
| 1 (main'den) | 82 | 3 | hayır | 4 + 1 = 5 |
| 2 | 27 | 3 | hayır | 3 + 1 = 4 |
| 3 | 9 | 3 | hayır | 2 + 1 = 3 |
| 4 | 3 | 3 | hayır | 1 + 1 = 2 |
| 5 | 1 | 3 | hayır | 0 + 1 = 1 |
| 6 | 0 | 3 | evet | 0 |

Altıncı çağrı 0 döndürür; dönüşte her seviye 1 ekler ve `main`'e **5** döner. Derste C kodu çalıştırılarak gönderilen değerler (82, 27, 9, 3, 1, 0) ekrana yazdırıldı ve sonuç 5 bulundu. Ajan da bu fonksiyonu C ile derleyip çalıştırarak 5 sonucunu doğruladı.

## 4. Geri dönüşte çalışan özyineleme: 4. vize sorusu

### 4.1 Soru

(ekrandan, 00:30:00)

> Aşağıdaki verilen sözde kod çalıştırılınca elde edilecek çıktı nasıl olur?

```text
function(3);
function(n){
int i;
if (n==0) return;
function(n-1);
for(i=n; i > 0; i--)
   print("*");
print("\n");
}
```

### 4.2 Çözüm

Durma koşulu yine `n == 0`'dır. Fark şudur: önceki soruda işlem her adımda yapılıp sonuç yukarı taşınıyordu. Burada fonksiyon önce kendini `n-1` ile çağırır, yazdırma işlemi bu çağrıdan **sonra** gelir. Yani işlem en aşağıya inildikten sonra, geri dönüşte yapılır.

- 1. çağrı `n=3`, 2. çağrı `n=2`, 3. çağrı `n=1`, 4. çağrı `n=0` (durur, geri döner).
- 3. çağrıya dönülür: `n=1`, bir yıldız ve satır sonu yazılır.
- 2. çağrıya dönülür: `n=2`, iki yıldız ve satır sonu.
- 1. çağrıya dönülür: `n=3`, üç yıldız ve satır sonu.

Çıktı:

```text
*
**
***
```

C koduyla çalıştırıldığında da 1, 2, 3 yıldızlı satırlar görüldü. Ajanın derleme kontrolü aynı çıktıyı verdi.

## 5. En uzun ardışık dizi (Longest Sequence)

### 5.1 Problem

(ekrandan, 00:35:00)

```text
Girdi : Dizi[7] = {199, 198, 200, 1, 0, 2, 3}
Çıktı: 0,1,2,3
```

Sıralı olmayan bir dizide, değerleri birer birer artan en uzun ardışık sayı grubu aranır. Sayılar dizide yan yana olmak zorunda değildir. Öğrencilere birkaç dakika düşünme süresi verildi.

### 5.2 İlk fikirler

**Soru:** Bu soru en basit, hiç karmaşıklaştırmadan (brute force) nasıl çözülür? **Cevap (öğrenciden):** Dizi sıralanır. Hoca bunun en basit çözümlerden biri olduğunu söyledi: sıralanınca ardışık sayılar yan yana gelir ve yalnız bir sonraki elemana bakarak dizi gezilebilir.

**Soru:** Sıralamadan nasıl yapılır? **Cevap:** Her eleman için, aralarındaki fark 1 olan diğer elemanlar aranır. Bunun için iki döngü gerekir: biri bütün elemanları başlangıç adayı olarak gezer, diğeri her eleman için bütün diziyi tarar. Derste bunun $O(n^2)$ karmaşıklık olduğu söylendi (aşağıdaki ders sonrası nota bakın).

### 5.3 Kaba kuvvet çözümünün kodu

Kod derste adım adım yazıldı (ekrandan, 00:45:00 ve 00:50:00):

```c
#include<stdlib.h>
#include<stdio.h>

void Brute(int Arr[],int len){
    int i,j;
    int currNumber;
    int currSequence;
    int Max=0;
    int Start;
    for(i=0;i<len;i++){
        j=0;
        currNumber=Arr[i];
        currSequence=1;
        while((j<len)){
            if(Arr[j]-1==currNumber){
                currNumber=Arr[j];
                currSequence++;
                j=0;
            }else{
                j++;
            }
        }
        if(Max<currSequence){
            Max=currSequence;
            Start=Arr[i];
        }
    }

    printf("Longest Sequence ");
    j=0;
    currNumber=Start;
    while(j<len){
        if(Arr[j]-1==currNumber){
            printf("%d ",currNumber);
            currNumber++;
            j=0;
        }else{
            j++;
        }
    }
    printf("%d ",currNumber);
}

int main(){
    int Arr[9]={199,198,200,1,0,2,3,201,202};
    int len=9;

    Brute(Arr,len);
}
```

Kodun mantığı:

- Dış `for` her elemanı bir **başlangıç adayı** olarak ele alır. Burada önemli olan, bakılan sayının en uzun dizinin içinde olup olmadığına değil, en uzun dizinin başlangıç noktası olup olmadığına bakılmasıdır.
- `currNumber` o an zincirin ulaştığı son sayıyı tutar. İlk elemanın hep kendisine bakılmaz: zincir ilerledikçe karşılaştırma yeni bulunan sayı üzerinden yapılır.
- İç döngü `for` değil `while` ile yazıldı. **Soru:** Bunu `for` ile yapabilir miyiz, yapsak ne olur? **Cevap:** Eleman bulununca arama baştan başlamalıdır; `for` gereksiz işlem yaptırır, `while` ile döngü sayacı kendi koşulumuzla yönetilir. `Arr[j]-1 == currNumber` olan eleman bulununca zincir uzar ve `j = 0` yapılarak dizi baştan taranır; bulunamazsa `j` artar. Yani bu `while` diziyi bir kez değil, zincire her yeni eleman eklendiğinde yeniden gezer.
- Dizi bittiğinde zincirin uzunluğu `Max`'tan büyükse `Max` ve başlangıç değeri `Start` güncellenir.
- Yazdırmak için ek bir bilgi tutulmadığından aynı arama `Start`'tan başlayarak bir kez daha yapılır; her bulunan sayıda `currNumber` yazılıp bir artırılır. Döngüden sonra zincirin son sayısı ayrıca yazdırılır.

İlk derlemede hata alındı. **Soru:** Sizce neden hata verdi? **Cevap (öğrenciden):** Fonksiyon parametresi dizi olarak tanımlanmamıştı (`int Arr` yazılmıştı). Parametre `int Arr[]` yapılınca kod çalıştı ve `0 1 2 3` çıktısı alındı (ekrandan, 00:50:00). Sonra diziye 201 ve 202 eklenip boyut 9 yapıldı; böylece 198'den 202'ye kadar beş elemanlı daha uzun bir zincir oluştu.

Ajan, bu kodu `gcc -Wall` ile uyarısız derleyip çalıştırdı: 7 elemanlı girdi için `Longest Sequence 0 1 2 3`, 9 elemanlı girdi için `Longest Sequence 198 199 200 201 202` çıktısı alındı.

> **Ders sonrası not:** Derste bu çözümün $O(n^2)$ olduğu söylendi. Zincire her eleman eklendiğinde iç arama `j = 0`'dan yeniden başladığı için tek bir başlangıç adayı için adım sayısı $O(n \cdot L)$'dir ($L$ zincir uzunluğu). Dizi tamamen ardışık sayılardan oluşuyorsa toplam adım $O(n^3)$'e çıkar; büyük olasılıkla doğru en kötü durum sınırı budur.

### 5.4 Fonksiyon parametresinde dizi boyutu

**Soru:** Diziyi parametre olarak tanımlarken köşeli parantezin içine boyut yazmamız gerekiyor mu? **Cevap:** Tek boyutlu dizide gerekmez. Matris gibi iki ya da daha çok boyutlu dizilerde (ilk boyut dışındaki) boyutların yazılması gerekir. **Soru:** Nedeni nedir? **Cevap (öğrenciden, hocanın onayıyla):** Her köşeli parantezde farklı bir atlama miktarı vardır; bir satır atlarken derleyicinin sütun sayısını bilmesi gerekir ki o kadar atlayıp sonraki satıra geçsin. Tek boyutlu dizide böyle bir atlama olmadığı için boyut gerekmez. Parametre ayrıca `int *Arr` biçiminde, yıldız işaretiyle de yazılabilir; işaretçiler (pointer) derste kısaca anlatılmıştı.

**Soru:** Dizinin bittiğini nasıl anlıyor? **Cevap:** Aslında anlamıyor. Dizinin sınırı aşılırsa bellek erişim hatası oluşabilir, ama bunun dışında C bir kontrol yapmaz. Dizi erişimi doğrudan bellek adresiyle yapılır; bu konu ileride işlenecek.

> **Ek bilgi (derste anlatılmadı):** C'de dizi sınırı dışına erişim tanımsız davranıştır. Program her zaman hata vererek durmaz; yanlış bir değer okuyup sessizce devam edebilir. Bu yüzden döngü sınırlarının doğru yazılması programcının sorumluluğundadır.

### 5.5 Dizi sıralı olsaydı

**Soru:** Dizi sıralı olsaydı bunu nasıl bulurduk, kaç döngü gerekirdi? **Cevap:** Tek döngü yeter, karmaşıklık $O(n)$ olur. Kaba kuvvet çözümünde yazdırma için eklenen ikinci arama karmaşıklığı artırmaz, çünkü o da aynı mertebededir.

**Soru:** Dizi sırasız verilse ve biz önce sıralayıp sonra bu tek geçişi yapsak karmaşıklık $O(n)$ olur mu? **Cevap:** Olmaz. Çözümün en pahalı adımı artık en uzun diziyi bulmak değil sıralamak olur; karmaşıklık sıralama algoritmasınınkine eşit olur ($O(n \log n)$ ya da bubble sort, selection sort gibi bir sıralamayla $O(n^2)$). Sıralamak çoğu çözümü basitleştirir, ama sıralamadan daha iyi karmaşıklıklı bir çözüm varsa sıralamak kötü bir seçimdir.

Sıralı dizideki çözümün anlatılan yapısı:

- Değişkenler: en uzun bölümün uzunluğu `Max`, bitiş indisi `End` ve o anki uzunluk `currSequence` (1'den başlar). Dizi sıralı olduğu için bitiş noktası belli olur; başlangıç oradan hesaplanabilir.
- Dizi bir kez gezilir. `Arr[i]+1 == Arr[i+1]` ise (bir `+1` köşeli parantezin dışında, biri içinde) `currSequence` artar. Değilse sıralı bölüm bozulmuştur: `currSequence > Max` ise `End = i` ve `Max = currSequence` yapılır, `currSequence = 1`'e döner.
- Yazdırma: `i = 0`'dan `Max`'a kadar `Arr[End - Max + i + 1]` yazdırılır; `+1`, sayacın 1'den başlatılmasından gelir.

Derste dizi `{1, 2, 3, 4, 100, 200}`, uzunluk 6 alındı ve `1 2 3 4` bulundu. <!-- BELİRSİZ: sorted fonksiyonunun gövdesi karelerde görünmüyor; yukarıdaki yapı konuşmadan kuruldu. -->

> **Ders sonrası not:** Anlatılan döngü `i < len` iken `Arr[i+1]`'i okur; `i = len - 1` olduğunda bu, dizinin dışına erişimdir (tanımsız davranış). Ayrıca en uzun bölüm dizinin sonundaysa döngü içinde hiç kaydedilmez. Ajanın düzelttiği ve derleyip denediği sürüm aşağıdadır; derste bu biçimde yazılmadı. `{1,2,3,4,100,200}` ve `{100,200,1,2,3,4}` girdilerinin ikisinde de `1 2 3 4` verir.

```c
void sorted(int Arr[], int len){
    int i, Max = 1, End = 0, currSequence = 1;
    for(i = 1; i < len; i++){
        if(Arr[i-1] + 1 == Arr[i]) currSequence++;
        else currSequence = 1;
        if(currSequence > Max){ Max = currSequence; End = i; }
    }
    for(i = End - Max + 1; i <= End; i++) printf("%d ", Arr[i]);
    printf("\n");
}
```

## 6. Özyineleme ile tekrarlı dizilim ve tekrarsız kombinasyon üretme

### 6.1 Problem

(ekrandan, 01:00:00)

```text
6. Concat(Tekrarlı, Tekrarsız Kombinasyon)
Girdi : Char Set1[] = {'a','b','c','d','e','f','g'}
K = 4;
N= 7;
Tekrarlı Kombinasyon Çıktı:
aaaa
aaab
aaac
aaad
aaae
aaaf
aaag
aaba
```

Bir karakter dizisinden $K$ uzunluklu, karakterlerin tekrar edebildiği bütün dizgiler sırayla üretilecek: `aaaa`, `aaab`, ..., `aaag`, sonra `aaba`, ...; sonunda `b` ile başlayanlar gelir. Çözümün özyinelemeli olması istendi. Öğrencilere düşünmek için birkaç dakika verildi.

### 6.2 Neden özyineleme?

Bir öğrenci her birini bir `for` içinde çağırmayı önerdi. $K = 4$ sabitse iç içe dört `for` ile çözülebilir. **Soru:** $K$, 4 değil de 5 olsaydı ya da kullanıcıdan alınsaydı? İç içe döngü sayısı koda sabit yazılır; 3'te, 5'te ya da değişken bir derinlikte durmak iteratif kodla çok zordur.

Özyinelemenin önemli özelliği, dallanarak ilerlerken her adımın kendi içeriğini (durumunu) korumasıdır. Önceki vize sorularında bu özellik pek kullanılmamıştı, çünkü her adımda tek bir çağrı yapılıyordu. Burada ise bir ağaç gezilir (ekrandan, 01:10:00):

- Kök boş önekle başlar ve kümedeki bütün karakterleri gezer.
- `a`'ya inince önek `"a"` olur; bu düğüm yine bütün karakterleri gezer.
- Tekrar `a`'ya inince `"aa"`, sonra `"aaa"`, sonra `"aaaa"` olur. Burada $K = 4$'e ulaşıldığı için durulur.
- Geri dönüldüğünde durum kendiliğinden bir adım geri gider (`"aaa"`); sonra `b` için çağrılır ve `"aaab"` elde edilir. Durumu programcının elle geri sarması gerekmez.

İteratif çözümde, aşağı inerken yukarı çıkabilmek için bazı bilgileri kaydetmek gerekir; aşağıdan yukarı çıkmak iteratifte zordur. Özyinelemede ise her adımda yapılan iş aynıdır: "bütün harfleri gez, her biri için bir alt seviyeyi çağır". Fonksiyon basit kalır, kod azalır.

Hoca daha iyi bir örnek olarak labirentte gezinmeyi verdi: her yol ayrımında iki seçenek vardır (yukarı ya da aşağı). İteratif gezinmede her çıkmaz sokakta geriye doğru elle sarma yapmak gerekir; özyinelemede her adım ayrı bir fonksiyon çağrısı olduğu için çıkmazdan geri dönmek çok daha kolaydır.

**Soru:** Kodun okunma karmaşıklığı ve işlem karmaşıklığı farklı şeylerdir. Özyineleme işlem karmaşıklığını azaltır mı? **Cevap:** Azaltmaz. Yapılması gereken işlemler bellidir ve yapılmak zorundadır. Özyineleme, bu işlemleri yaparken yazılan kodun karmaşıklığını, yani okunma karmaşıklığını azaltır.

### 6.3 Yardımcı fonksiyon: dizginin sonuna karakter ekleme

C'de bunun için hazır bir fonksiyon (`strcat` ailesi) vardır, ama daha basit bir şey istendiği ve içinin görülmesi için kendi fonksiyonumuz yazıldı (ekrandan, 01:15:00):

```c
void String_concat(char* dest, char source){
    int First_len=strlen(dest);
    dest[First_len]=source;
    dest[First_len+1]='\0';
}
```

- `strlen` verilen dizginin uzunluğunu bulur; sıfırdan başlayan son indeksi değil, birden başlıyormuş gibi sayılan boyutu verir. Son harfe erişmek için `First_len - 1` kullanılır.
- Burada son harfe değil, sonun bir sonrasına yeni karakter yazılmak istenir: `dest[First_len]`.

**Soru:** Karakteri yazıp çıkmak doğru mu, başka bir işlem gerekir mi? **Cevap:** Gerekir. Bu bir dizgi (string) olduğu için bittiği yer gösterilmelidir. Yeni karakter eski `'\0'` sonlandırıcısının üzerine yazıldı, yani dizginin bitiş noktası silindi; bu yüzden `dest[First_len+1] = '\0'` ile yeni bitiş noktası belirlenir.

### 6.4 Tekrarlı dizilimleri üreten fonksiyon

(ekrandan, 01:20:00 ve 01:25:00)

```c
void printAllPermutation(char set[],char prefix[],int n,int k){
    int i;
    char Newprefix[100];
    if(k==0){
        printf("%s \n",prefix);
        return;
    }
    for(i=0;i<n;i++){
        strcpy(Newprefix,prefix);
        String_concat(Newprefix,set[i]);
        printAllPermutation(set,Newprefix,n,k-1);
    }
}
```

- `set`: kullanılacak karakterler; `n`: karakter sayısı.
- `prefix` (önek): önceki adımlarda eklenmiş harfler. Yeni harf bunun sonuna eklenir; yazdırılacak dizgi de odur.
- `k`: eklenmesi gereken kalan harf sayısı. Durma koşulu "4 harf eklendi", yani ağaçta 4 adım atıldı; bu derinlik ayrı bir sayaçla da tutulabilirdi, ama kalan sayıyı `k` ile tutmak daha basittir. $k = 0$ olunca önek yazdırılır ve geri dönülür.
- `k` sıfır değilse karakterler gezilir. Gelen önek doğrudan değiştirilmez; değiştirilirse önceki durumlar kaybolur. Bunun yerine yeni bir `Newprefix` dizisine `strcpy` ile kopyalanır, `set[i]` eklenir ve fonksiyon aynı küme, aynı `n`, yeni önek ve `k-1` ile çağrılır.

`main` içinde ilk çağrı boş bir önekle yapılır (ekrandan, 01:25:00):

```c
int main(){
    char set1[]={'a','b','c','d','e','f','g'};
    int k=4;
    int n=7;
    char Prefix[100]="";
    printAllPermutation(set1,Prefix,n,k);
}
```

Çalıştırıldığında 4 harfli bütün dizgiler yazdırıldı.

> **Ders sonrası not:** Slaytta bu çıktıya "tekrarlı kombinasyon", derste "tekrarlı permütasyon" dendi. Üretilen dizgilerde sıra önemlidir (`aaab` ile `aaba` ayrıdır), bu yüzden matematikte bu, tekrarlı permütasyondur (dizilim); sayısı $N^K = 7^4 = 2401$'dir. Tekrarlı kombinasyon (sırasız) olsaydı sayısı $\binom{N+K-1}{K} = \binom{10}{4} = 210$ olurdu.

### 6.5 Tekrarsız kombinasyon

**Soru:** Tekrarsız olursa, yani kombinasyonlar nasıl üretilir? Mantık aynıdır: önek yine boştan başlar, her harf gezilir. Ama artık her düğüm yalnız kendisinden **sonraki** harflere bakar: `a`'dan sonra yeniden `a`'ya değil `b`'ye gidilir; `ab`'den sonra `a` ve `b`'ye değil `c`'ye gidilir.

Bunun için fonksiyona son eklenen harfin indisini tutan yeni bir argüman (`LastAdded`) eklenir ve döngü bu indisin bir sonrasından başlar (ekrandan, 01:25:00):

```c
void printAllCombinations(char set[],char prefix[],int n,int k, int LastAdded){
    int i;
    char Newprefix[100];

    if(k==0){
        printf("%s \n",prefix);
        return;
    }

    for(i=LastAdded+1;i<n;i++){
        strcpy(Newprefix,prefix);
        String_concat(Newprefix,set[i]);
        printAllCombinations(set,Newprefix,n,k-1,i);
    }
}
```

Değişen yalnız iki yerdir: döngü `0`'dan değil `LastAdded+1`'den başlar ve alt çağrıya `LastAdded` olarak `i` gönderilir. İlk çağrıda döngünün 0'dan başlaması için `-1` gönderilir: `printAllCombinations(set1, Prefix, n, k, -1);`. Çıktı `abcd`, `abce`, ... gibi tekrarsız kombinasyonlardır.

Ajan, iki fonksiyonu yukarıdaki `main` ile `gcc -Wall` kullanarak uyarısız derleyip çalıştırdı: `printAllPermutation` $2401$ satır (`aaaa`, `aaab`, ..., `aaag`, `aaba`, ...), `printAllCombinations` $\binom{7}{4} = 35$ satır (`abcd`, `abce`, `abcf`, `abcg`, `abde`, ...) üretti.

> **Ek bilgi (derste anlatılmadı):** `set1` dizisi `'\0'` ile bitmediği için bir dizgi değil, yalnız bir karakter dizisidir. Kod bunu `%s` ile yazdırmadığı ve uzunluğu `n` ile ayrıca verdiği için sorun çıkmaz. `Newprefix[100]` her çağrıda stack'te yeni yer kaplar; $K$ küçük olduğu için bu derinlik sorun değildir.

## 7. Rastgele nokta deneyinin görselleştirilmesi

Uygulama bölümünden sonra dersin hocası, 1. ve 2. sorulardaki rastgele sayı deneyini görsel olarak gösterdi. C koduyla bu noktaları çizmek kolay olmadığı için ekrana nokta koyan küçük bir JavaScript (tarayıcı) programı kullanıldı. Ekrana sığması ve rahat anlaşılması için 0-1 aralığı yerine 0-100 aralığında (100 dahil) sayılar üretildi.

- Sayfa çalıştığı sürece rastgele noktalar üretilir ve yalnız koşulu sağlayanlar ekrana konur; $N$ sonsuza giderken noktalar koşulun belirttiği bölgeyi doldurur.
- 2. sorunun koşulu ($s_1 > 1 - s_2$ ve $s_2 \le 0.5$ gibi) çalıştırılınca üçgen biçimli bir bölge dolmaya başladı (ekrandan, 01:30:00). Başta hızlı dolar; bir süre sonra noktalar üst üste düştüğü için kalan boşluklara ulaşmak uzun sürer (ekrandan, 01:35:00). Limitte, sonsuz kez yapılınca bütün alan kaplanır.
- Bu görsel, `say/N` oranının neden bölgenin alanına yakınsadığını sezgisel olarak gösterir.

## 8. Proje problemi üzerine algoritmik notlar

Oturumun son bölümünde bir programlama projesi tanıtıldı. Teslim ve değerlendirme ayrıntıları bu nota alınmadı; yalnız algoritmik kısımlar aşağıdadır.

### 8.1 Problem

- $N \times N$ bir matriste 1'den $N$'e kadar sayıların her biri ikişer kez, rastgele ve üst üste gelmeyecek biçimde yerleştirilir (ya da konumları dosyadan okunur; dosyada her sayı için satır ve sütun bilgisi vardır).
- Amaç, aynı sayıları birbirine bağlayan yolları çizmektir. Yollar birbirini kesmez; oyun bittiğinde boş hücre kalmaz. Boş hücreler 0 ile gösterilebilir.
- Hareketler **4 komşuluk** üzerinedir: sağ, sol, yukarı, aşağı. Kuzeydoğu, güneybatı gibi çapraz yönlü 8 komşuluk kullanılmaz.
- Bir hamle, bir başlangıç ve bir bitiş hücresi verilerek yapılır; aradaki hücrelere başlangıç hücresindeki sayı yazılır (ör. önce $(3,2)$'den $(1,2)$'ye, sonra $(1,2)$'den $(1,4)$'e gibi parça parça).
- Rastgele yerleştirmede tahtanın çözümü olmayabilir; bunu oynamadan kontrol etmek kolay değildir, otomatik mod çözüm bulamazsa bunu bildirmelidir. En kısa yol istenmez; bazen çözüm için uzun bir yol gerekir.

### 8.2 Otomatik çözüm için ipuçları

- Derste daha önce anlatılan **bağlantılı bileşen (connected component)** bulma algoritması ve özyineleme temel alınabilir: bir sayının konumu bulunur, sağına, soluna, yukarısına ve aşağısına bakılarak eşine giden yol aranır. Hoca buna flood fill gibi düşünmeyi de önerdi.
- Yanlış bir hamle çözümsüz bir duruma götürebilir. Bu durumda **geri alma (undo)** gerekir: matrisin önceki durumları (örneğin son birkaç durum) saklanır ve bir ya da iki adım geri dönülür. Otomatik modda gidecek yol kalmayınca bu geri almalardan yararlanmaya **backtracking** denir.
- Yapılan her birleştirmenin ve geri almanın ekrana yazdırılması, hata ayıklama (debug) için de yararlıdır.
- Algoritmanın zaman karmaşıklığı $T(n)$ analitik olarak çıkarılmalıdır. Hoca, kullanıcı skoru için ölçülen tamamlanma süresinin $T(n)$ ile karıştırılmaması gerektiğini vurguladı: $T(n)$ asimptotik (algoritmik) analizdir, süre ise ölçülen bir parametredir. Süre ölçmek için `time.h` ile başlangıç ve bitiş zamanları alınabilir.

> **Ek bilgi (derste anlatılmadı):** Bu tür "kesişmeyen yollarla çiftleri bağlama" bulmacaları genel olarak zor problemlerdir; geri izlemeli arama en kötü durumda üstel sayıda durum deneyebilir. Bu yüzden test için küçük matrisler (4, 5, en çok 6 boyut) kullanmak, hocanın da önerdiği gibi, pratik bir yoldur.

### 8.3 Statik ve global değişkenler, memcpy

- Projede global ve statik değişken, `continue` ve `goto` kullanılmaması istendi. Hocanın açıklamasına göre statik değişkenin özel kullanım alanları vardır, her yerde kullanılmaz. Statik tanımlanan bir dizi ya da matrisin bütün değerleri otomatik olarak sıfırlanır, ama statiğin başka yan etkileri de vardır. Bu kısıtların amacı dile hakimiyeti ve algoritmik düşünmeyi geliştirmektir.
- Kullanıcı adı ve skorunu birlikte tutmak gibi işler için `struct` kullanılabilir; algoritmanın ana yapısı matris olmalıdır.
- `memcpy` ile matris kopyalamanın `malloc` ile oluşturulmuş dinamik matrislerde kullanılabileceği söylendi.

> **Ders sonrası not:** Hoca sabit uzunluklu matrislerde `memcpy` kullanılamayacağını söyledi. C dilinde `int A[N][N]` gibi bir matris bellekte bitişik durduğu için `memcpy(B, A, sizeof(A))` geçerli bir kopyalamadır; söylenen büyük olasılıkla bu projeye özgü bir kısıttır, dilin bir kısıtı değildir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00): Aşağıdaki sözde kod çalıştırıldığında `say/N` değeri $N$'in büyük değerleri için kaça yakınsar? (`rand()`: 0-1 aralığında ondalıklı rastgele sayı; $x^2$'nin integrali $x^3/3$.)

```text
oku(N); say=0;
for i=1:N
   s1=rand(); s2=rand();
   if (s1*s1<=s2) say=say+1; end
end
yaz(say/N)
```

> **Çözüm:** Birim karede $s_2 = s_1^2$ eğrisinin üstündeki bölge istenir. $\int_0^1 x^2 dx = 1/3$ olduğundan cevap $1 - 1/3 = 2/3$.

**Soru 2** (ekrandan, 00:20:00): Aynı yapıda koşul `(s1>1-s2) && (s2<0.5)` olduğunda `say/N` kaça yakınsar?

> **Çözüm:** İki koşulun ortak bölgesi köşeleri $(1,0)$, $(1,0.5)$, $(0.5,0.5)$ olan dik üçgendir; alanı $\frac{1}{2}\cdot 0.5 \cdot 0.5 = 1/8$.

**Soru 3** (ekrandan, 00:25:00): `main`'de `i=82, j=3; f(i,j);` çağrılıyor. `f(i,j)`: `i==0` ise 0, değilse `f(i/j, j)+1` döndürüyor. Sonuç nedir?

> **Çözüm:** Çağrılar 82, 27, 9, 3, 1, 0 değerleriyle yapılır; 0'da 0 döner ve beş seviyenin her biri 1 ekler. Cevap 5.

**Soru 4** (ekrandan, 00:30:00): `function(3)` çağrısının çıktısı nedir? (`function(n)`: `n==0` ise döner; değilse `function(n-1)` çağırır, sonra `n` tane `*` ve satır sonu yazar.)

> **Çözüm:** Yazdırma geri dönüşte yapılır; çıktı sırasıyla `*`, `**`, `***` satırlarıdır.

**Soru 5** (ekrandan, 00:35:00): `{199, 198, 200, 1, 0, 2, 3}` dizisinde ardışık değerlerden oluşan en uzun grubu bulan programı yazınız. Beklenen çıktı `0,1,2,3`.

> **Çözüm:** Bölüm 5.3'teki kaba kuvvet kodu; dizi sıralıysa Bölüm 5.5'teki tek geçişli çözüm.

**Soru 6** (ekrandan, 01:00:00): `{'a','b','c','d','e','f','g'}` kümesinden ($N=7$) $K=4$ uzunluklu, tekrar içeren bütün dizgileri (`aaaa`, `aaab`, ..., `aaag`, `aaba`, ...) özyinelemeli olarak üreten fonksiyonu yazınız. Tekrarsız kombinasyonlar için fonksiyon nasıl değişir?

> **Çözüm:** Bölüm 6.4'teki `printAllPermutation` ($7^4 = 2401$ dizgi) ve Bölüm 6.5'teki `printAllCombinations` ($\binom{7}{4} = 35$ kombinasyon).

## Dersin Toparlaması

Bu uygulama oturumunda vize sınavındaki dört soru ve iki algoritmik problem üzerinden derste işlenen konular pekiştirildi. Rastgele sayı sorularında `say/N` oranının $N$ büyüdükçe bir olasılığa yakınsadığı, bu olasılığın da birim karede koşulu sağlayan bölgenin alanı olduğu görüldü: parabolün üstü için $2/3$, iki doğrunun sınırladığı üçgen için $1/8$. Tamsayı bölmesini önlemek için tür dönüşümünün gerekli olduğu hatırlatıldı. Özyineleme sorularında her çağrının tabloyla izlenmesi, durma koşulunun önemi ve özyinelemeli çağrıdan sonra yapılan işlemin geri dönüşte çalıştığı gösterildi.

En uzun ardışık dizi probleminde kaba kuvvet ve sıralı dizi çözümleri karşılaştırıldı; ön işlem olarak sıralamanın karmaşıklığı nasıl belirlediği tartışıldı. Karakter kümesinden dizilim ve kombinasyon üretme probleminde ise özyinelemenin her çağrıda kendi durumunu saklayarak geri dönüşü kendiliğinden yönettiği, işlem sayısını değil kod karmaşıklığını azalttığı vurgulandı. Bu fikir, tanıtılan projede bağlantılı bileşen arama ve geri izleme (backtracking) ile yolları otomatik bulmanın da temelini oluşturur.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
