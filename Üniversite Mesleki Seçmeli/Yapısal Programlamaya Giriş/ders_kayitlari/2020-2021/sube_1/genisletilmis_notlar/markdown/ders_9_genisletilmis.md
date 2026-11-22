# Ders 9 Genişletilmiş Notu: Laboratuvar 1: Ardışık Dizide Kayıp Sayıyı Bulma

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Laboratuvar problemi
- 2. Derste netleşen varsayımlar
- 3. Verimlilik beklentisi ve kod yazım kısıtları
- 4. Çözüm fikri ve örnek bir C programı
- Örnek Sorular
- Dersin Toparlaması

Bu kayıt dersin ilk laboratuvar oturumudur. Oturumun başında laboratuvar sorusu ekranda paylaşıldı ve anlatıldı; ardından öğrenciler soruyu kendi başlarına çözdü, bu sırada sorulan sorular cevaplandı. Problemin çözümü derste anlatılmadı. Aşağıdaki çözüm bölümü bu yüzden ajan tarafından eklenmiştir ve öyle işaretlenmiştir.

## 1. Laboratuvar problemi

### 1.1 Problem metni

Ekranda paylaşılan laboratuvar belgesindeki problem şudur (ekrandan, 00:10:00):

- **Görev:** Ardışık sayılardan oluşan bir dizide, ardışıklığı bozan kayıp sayıyı bulan algoritmanın kodlanması.
- **Girdi:** Sıralı sayılardan oluşan dizinin boyutu ve dizi elemanları.
- **Çıktı:** Kayıp sayı varsa sayının kendisi, yoksa kayıp sayı olmadığı ekrana yazılmalı.
- **Önemli:** Program büyük boyutlu diziler de düşünülerek verimli şekilde tasarlanmalı.
- **İpucu:** Ardışık sayılar sıralı olduğu için, sıralı bir dizide arama yapmayı kolaylaştıracak yöntemler kullanılmalı.

Anlatımda problem şöyle özetlendi: kullanıcıdan bir dizi alınır ve bu dizinin özelliği ardışık elemanlardan oluşmasıdır. Ancak kullanıcının bir elemanı eksik girdiği, yani bir sayıyı unuttuğu varsayılır; ya da kullanıcı hiçbir elemanı eksik girmemiş de olabilir. Programın görevi unutulan bu sayıyı bulmaktır.

### 1.2 Ekrandaki örnekler

Belgede üç örnek vardır (ekrandan, 00:10:00):

| Girdi | Çıktı |
|---|---|
| 2 3 4 5 7 8 9 10 | 6 |
| -8 -7 -6 -5 -3 -2 -1 0 | -4 |
| 10 11 12 | No missing value |

İlk örnekte 5'ten sonra 7 gelir, 6 eksiktir. İkinci örnek aynı durumun negatif sayılarla kurulmuş hâlidir: -5'ten sonra -3 gelir, -4 eksiktir. Anlatımda da aynı şeyin negatif sayılarda gerçeklenebileceği belirtildi. Üçüncü örnek iki şeyi gösterir: dizilerin boyu farklı olabilir (bu kullanıcıya bağlıdır) ve dizide hiç kayıp değer olmayabilir.

## 2. Derste netleşen varsayımlar

Problem anlatıldıktan sonra öğrencilerin sorularıyla şu varsayımlar netleşti:

- **Girdi kullanıcıdan alınır.** Programın içinde sabit bir dizi verilmez; hem eleman sayısı hem elemanlar kullanıcıdan okunur.
- **Dizi artan sıradadır.** Sağdaki eleman her zaman soldakinden büyüktür; azalan (tersine sıralanmış) diziler düşünülmez.
- **Ardışıklık birer birerdir.** 1, 2, 3, ... gibi; 1, 3, 5, 7 gibi farklı adımlı diziler kapsam dışıdır.
- **En çok bir kayıp sayı vardır.** Birden fazla kayıp elemana bakmaya gerek yoktur: ya tam bir kayıp sayı vardır ya da hiç yoktur.
- **Kayıpsız durum kontrol edilmelidir.** Dizi sıralı alınsa da üçüncü örnekteki gibi hiç eleman unutulmamış olabilir; program bunu ayrıca denetlemelidir.

## 3. Verimlilik beklentisi ve kod yazım kısıtları

### 3.1 Yalnız sonuca ulaşmak yeterli değil

Kullanıcı 10 değer girebilir, 100 de olabilir, 1000 de olabilir. Laboratuvarda asıl görülmek istenen, verimli bir çözüm üretilip üretilemediğidir. Elemanlara tek tek bakan bir çözüm istenmemektedir. Bunun için belgede ipucu verilmiştir ve bu ipucuna bağlı kalarak geliştirilen program tam karşılığı alır.

> **Hocanın vurgusu:** Sadece sonuca ulaşmak önemli değil; sonuca nasıl ulaşıldığı da önemli. Tek tek bakmak yerine ipucundaki gibi sıralı dizide aramayı kolaylaştıran bir yöntem kullanılmalı.

### 3.2 Yasak yapılar

Oturum sırasında şu kısıtlar da hatırlatıldı:

- `break`, `continue`, `goto` gibi komutlardan kaçınılmalı, bunlar kullanılmamalı.
- Global değişken kullanılmamalı.

Bu kısıtlar, döngülerin çıkış koşulunun döngünün kendi koşulunda açıkça yazılmasını gerektirir.

## 4. Çözüm fikri ve örnek bir C programı

Bu bölüm derste anlatılmadı. Çözüm ajan tarafından, problem metnindeki ipucu ve derste netleşen varsayımlar izlenerek yazıldı.

### 4.1 Kayıp olup olmadığını anlamak

Elemanlar birer birer arttığı için kayıp olmayan $n$ elemanlı bir dizide son eleman ile ilk eleman arasındaki fark tam $n - 1$'dir. Bir sayı eksikse bu fark $n$ olur. Bu yüzden tek bir karşılaştırmayla kayıp olup olmadığı anlaşılır:

- 10 11 12 için $n = 3$, $12 - 10 = 2 = n - 1$: kayıp yoktur, çıktı "No missing value".
- 2 3 4 5 7 8 9 10 için $n = 8$, $10 - 2 = 8 \neq 7$: bir sayı eksiktir.
- -8 ... 0 için $n = 8$, $0 - (-8) = 8 \neq 7$: bir sayı eksiktir.

### 4.2 Kayıp sayının yerini bulmak

Kayıp olmayan bir dizide $i$. konumdaki (0'dan sayarak) eleman $a[0] + i$'dir, yani $a[i] - a[0] = i$ olur. Kayıp sayıdan sonraki bütün elemanlar bir kaymış olduğundan bu konumlarda $a[i] - a[0] = i + 1$ olur. Böylece dizi iki bölgeye ayrılır: başta "$a[i] - a[0] = i$" koşulunu sağlayan konumlar, sonra sağlamayanlar. Aranan, bu iki bölgenin sınırıdır.

Sınırı bulmak için elemanlara tek tek bakmak $n$ adım sürer. Dizi sıralı olduğu için ikili arama kullanılabilir: aralığın ortasındaki konum denenir; koşul sağlanıyorsa kayıp sağ yarıdadır, sağlanmıyorsa sol yarıdadır. Her adımda aralık yarıya iner.

> **Ek bilgi (derste anlatılmadı):** İkili arama, sıralı bir dizide aranan değeri ya da bir koşulun değiştiği sınırı her adımda aralığı yarıya indirerek bulur. $n$ elemanlı dizide yaklaşık $\log_2 n$ adım yeter; örneğin 1000 eleman için yaklaşık 10 adım, oysa tek tek bakmak 1000 adıma kadar sürebilir. Laboratuvar belgesindeki "sıralı bir dizide arama yapmayı kolaylaştıracak yöntemler" ipucu büyük olasılıkla bu yöntemi kastetmektedir.

### 4.3 Ekrandaki ilk örnekte adım adım

Girdi 2 3 4 5 7 8 9 10, $n = 8$. Başlangıçta `sol = 0`, `sag = 7`. Döngü `sag - sol > 1` olduğu sürece sürer:

| Adım | sol | sag | orta | a[orta] | a[orta] - a[0] | Koşul ($= orta$) | Sonuç |
|---|---|---|---|---|---|---|---|
| 1 | 0 | 7 | 3 | 5 | 3 | sağlanır | sol = 3 |
| 2 | 3 | 7 | 5 | 8 | 6 | sağlanmaz | sag = 5 |
| 3 | 3 | 5 | 4 | 7 | 5 | sağlanmaz | sag = 4 |

Artık `sag - sol = 1` olduğu için döngü biter. Kayıp sayı `a[sol] + 1 = a[3] + 1 = 6` olur. İkinci örnekte (-8 -7 -6 -5 -3 -2 -1 0) adımlar aynıdır: `orta = 3` için $-5 - (-8) = 3$ (sağlanır), `orta = 5` için $-2 - (-8) = 6$ (sağlanmaz), `orta = 4` için $-3 - (-8) = 5$ (sağlanmaz); sonuç $a[3] + 1 = -5 + 1 = -4$ olur. Her iki örnekte de 3 adım yetmiştir. Bu izler python ile doğrulandı.

### 4.4 Program

Aşağıdaki program derste yazılmadı; ajan tarafından yazıldı, `gcc -Wall` ile uyarısız derlendi ve ekrandaki üç girdiyle denendi. Çıktılar sırasıyla 6, -4 ve "No missing value" oldu. Derste istenen kısıtlara uygun olarak `break`, `continue`, `goto` ve global değişken içermez.

```c
#include <stdio.h>

int main(void) {
    int n, i, sol, sag, orta, kayip;
    int a[1000];

    printf("Dizinin boyutu: ");
    scanf("%d", &n);
    printf("Elemanlar (artan sirada): ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    if (a[n - 1] - a[0] == n - 1) {
        printf("No missing value\n");
    } else {
        /* a[i] - a[0] == i olan son konumu ikili aramayla bul */
        sol = 0;
        sag = n - 1;
        while (sag - sol > 1) {
            orta = (sol + sag) / 2;
            if (a[orta] - a[0] == orta)
                sol = orta;
            else
                sag = orta;
        }
        kayip = a[sol] + 1;
        printf("%d\n", kayip);
    }
    return 0;
}
```

Programda dizi boyutu 1000 ile sınırlıdır; daha büyük diziler için dizi boyutu artırılmalıdır. Elemanların okunması zaten $n$ adım sürdüğü için kazanç arama kısmındadır: kayıp sayının yeri $n$ yerine yaklaşık $\log_2 n$ karşılaştırmayla bulunur.

## Örnek Sorular

**Soru 1** (ekrandan, 00:10:00): Ardışık sayılardan oluşan bir dizide, ardışıklığı bozan kayıp sayıyı bulan programı yazın. Girdi: sıralı sayılardan oluşan dizinin boyutu ve dizi elemanları. Çıktı: kayıp sayı varsa sayının kendisi, yoksa kayıp sayı olmadığı. Program büyük boyutlu diziler düşünülerek verimli tasarlanmalı; sıralı dizide aramayı kolaylaştıran yöntemler kullanılmalı. Örnekler: 2 3 4 5 7 8 9 10 → 6; -8 -7 -6 -5 -3 -2 -1 0 → -4; 10 11 12 → No missing value.

> **Çözüm (derste verilmedi):** Önce $a[n-1] - a[0] = n - 1$ ise "No missing value" yazılır. Değilse $a[i] - a[0] = i$ koşulunun değiştiği sınır ikili aramayla bulunur ve kayıp sayı, koşulu sağlayan son konumdaki elemanın bir fazlasıdır. Bölüm 4.4'teki program `gcc -Wall` ile derlendi ve üç örnekte 6, -4 ve "No missing value" çıktılarını verdi.

**Soru 2** (derste sözlü, 00:13:42): Ardışıklık birer birer mi olacak, yoksa 1, 3, 5, 7 gibi diziler de düşünülebilir mi?

> **Cevap (derste verildi):** Birer birer: 1, 2, 3, ... Ayrıca dizi artan sıradadır, azalan dizi düşünülmez.

**Soru 3** (derste sözlü, 00:23:05): Birden fazla kayıp sayı olabilir mi?

> **Cevap (derste verildi):** Hayır; ya tek bir kayıp sayı vardır ya da hiç yoktur.

## Dersin Toparlaması

Bu laboratuvar oturumunda, önceki derslerde akış diyagramlarıyla çalışılan "önce çalışan çözüm, sonra verimli çözüm" yaklaşımı bir C programlama problemine taşındı. Problem, artan sıralı ve birer birer ardışık bir dizide en çok bir eksik sayıyı bulmaktı. Vurgu yalnız doğru sonuca değil, büyük dizilerde de verimli çalışan bir yönteme, yani sıralılıktan yararlanan bir aramaya verildi; ayrıca `break`, `continue`, `goto` ve global değişken kullanılmaması istendi.

Kayıp olup olmadığı ilk ve son elemanın farkından tek karşılaştırmayla anlaşılır. Kaybın yeri ise $a[i] - a[0] = i$ koşulunun değiştiği sınır olduğundan, bu sınır ikili aramayla tek tek bakmaktan çok daha az adımda bulunabilir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
