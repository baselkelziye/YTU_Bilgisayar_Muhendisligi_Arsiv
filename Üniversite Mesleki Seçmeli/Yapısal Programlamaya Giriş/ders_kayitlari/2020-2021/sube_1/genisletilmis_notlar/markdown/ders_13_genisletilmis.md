# Ders 13 Genişletilmiş Notu: Laboratuvar 2: Seyrek Matrisin Sıkıştırılmış Forma Dönüştürülmesi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Laboratuvar problemi
- 2. Programdan istenenler
- 3. Derste netleşen varsayımlar
- 4. Çözüm fikri ve örnek bir C programı
- Örnek Sorular
- Dersin Toparlaması

Bu kayıt dersin ikinci laboratuvar oturumudur. Oturumda laboratuvar sorusu ekranda paylaşıldı; öğrenciler soruyu kendi başlarına çözerken gelen sorular cevaplandı ve soruyu kavramakta zorlananlar için problem bir kez daha sözlü olarak açıklandı. Problemin çözümü derste anlatılmadı. Aşağıdaki çözüm bölümü bu yüzden ajan tarafından eklenmiştir ve öyle işaretlenmiştir.

## 1. Laboratuvar problemi

### 1.1 Seyrek matris

Laboratuvar belgesi şu tanımla başlar (ekrandan, 00:30:00): bir matristeki sıfırdan farklı değer sayısı, o matrisin eleman sayısına göre az ise bu matris bir **seyrek matristir**. Seyrek bir matriste yalnız sıfır olmayan girişlerin saklanmasıyla önemli bellek gereksinimi azaltmaları gerçekleştirilebilir.

### 1.2 Sıkıştırılmış form

Seyrek bir matris sıkıştırılmış formda temsil edilmek istenirse, sıfırdan farklı her değer bulunduğu **satır**, **sütun** ve **değeri** ile ifade edilir. Böylece sıkıştırılmış matrisin her satırı üç sayıdan oluşur ve satır sayısı, seyrek matristeki sıfırdan farklı eleman sayısı kadardır.

Anlatımda bu şöyle özetlendi: elimizde bir matris vardır. Bu matrisin içindeki sıfırdan farklı değerlerin satır, sütun ve değer bilgisi başka, yeni bir matriste tutulur. Daha sonra "sıkıştırılmış matris" diye adlandırılan bu matristen orijinal matris yeniden elde edilir.

### 1.3 Ekrandaki örnek

Belgedeki örnek matris şudur (ekrandan, 00:30:00):

$$
A = \begin{bmatrix}
0 & 0 & 0 & 1 & 0 & 0 \\
0 & 2 & 0 & 0 & 0 & 0 \\
0 & 0 & 0 & 3 & 0 & 0 \\
0 & 0 & 0 & 0 & 5 & 0 \\
8 & 0 & 0 & 0 & 0 & 0
\end{bmatrix}
$$

A matrisinde sıfırdan farklı değerler 1, 2, 3, 5 ve 8'dir. Satır ve sütun numaraları 0'dan başlayarak sayıldığında sıkıştırılmış form şu tablodur (ekrandan, 00:30:00):

| Satır | Sütun | Değer |
|---|---|---|
| 0 | 3 | 1 |
| 1 | 1 | 2 |
| 2 | 3 | 3 |
| 3 | 4 | 5 |
| 4 | 0 | 8 |

Belgedeki açıklamaya göre sıkıştırılmış formun ilk satırı (0 3 1), seyrek matriste 0'ıncı satır 3'üncü sütundaki değerin 1 olduğunu ifade eder. İkinci satır (1 1 2) ise seyrek matriste 1'inci satır 1'inci sütundaki değerin 2 olduğunu ifade eder. Diğer satırlar da aynı biçimde okunur: 2'nci satır 3'üncü sütunda 3, 3'üncü satır 4'üncü sütunda 5, 4'üncü satır 0'ıncı sütunda 8 vardır.

> **Ek bilgi (derste anlatılmadı):** Bu örnekte A matrisi $5 \times 6 = 30$ eleman içerir; sıkıştırılmış formda ise $5 \times 3 = 15$ sayı saklanır. Kazanç, sıfırdan farklı eleman sayısı azaldıkça büyür. Sıfırdan farklı eleman sayısı toplam eleman sayısının üçte birini geçerse bu formda saklanan sayı orijinal matristen fazla olur; bu yüzden form yalnız gerçekten seyrek matrislerde işe yarar. Bu satır-sütun-değer temsili kaynaklarda büyük olasılıkla "üçlü (triplet)" ya da "koordinat (COO)" biçimi diye de geçer.

## 2. Programdan istenenler

### 2.1 Görev

Belgede istenen, seyrek matristen sıkıştırılmış matrisi ve sıkıştırılmış matristen seyrek matrisi elde eden programın aşağıdaki kurallara uyularak C dilinde kodlanmasıdır (ekrandan, 00:30:00).

### 2.2 Menü ve programın sürekliliği

Birinci kural (ekrandan, 00:30:00): program bir menü içermeli ve kullanıcı hangi modda çalışacağını seçebilmelidir. Seçeneklerden biri de programın sonlanmasını sağlamalıdır. Program bir işlemi tamamladığında kendini yinelemelidir. Ekrandaki menü şöyledir:

```text
Menu:
(1) Seyrek Matristen Sikistirilmis Matrise
(2) Sikistirilmis Matristen Seyrek Matrise:
(3) Cikis
```

Sözlü açıklamada "programın devamlılığı" ve "kendini yineleme" şöyle anlatıldı: örneğin kullanıcı seyrek matristen sıkıştırılmış matris oluşturmak istemiş olsun. Bu işlem tamamlanıp sıkıştırılmış matris ekrana yazdırıldıktan sonra kullanıcının yapabileceği işlemler, yani menü, tekrar görünmelidir. Program sürekli çalışmalı, bir işlemden sonra kendiliğinden sonlanıp kapanmamalıdır. Ancak kullanıcı çıkmak isterse çıkış seçeneğini çalıştırır ve program sonlanır. Seçeneklerden biri seyrek matristen sıkıştırılmış matrise dönüştürme, ikincisi tam tersi sıkıştırılmıştan seyrek matrise dönüştürme, üçüncüsü programı sonlandırmadır.

### 2.3 Ekrandaki örnek çalışma

Belgede programın bir örnek çalışması da gösterilir (ekrandan, 00:30:00):

```text
Menu:
(1) Seyrek Matristen Sikistirilmis Matrise
(2) Sikistirilmis Matristen Seyrek Matrise:
(3) Cikis
1

Matrisin Boyutlarini Girin (Satir, Sutun): 3
2

Matrisin Elemanlarini Giriniz
[0][0]: 0
[0][1]: 0
[1][0]: 1
[1][1]: 1
[2][0]: 3
[2][1]: 0

Sikistirilmis Matris

1       0       1
1       1       1
2       0       3

Menu:
(1) Seyrek Matristen Sikistirilmis Matrise
(2) Sikistirilmis Matristen Seyrek Matrise:
(3) Cikis
3
```

Burada kullanıcı önce 1'i seçer, 3 satırlı ve 2 sütunlu bir matris girer. Matris şudur:

$$
\begin{bmatrix}
0 & 0 \\
1 & 1 \\
3 & 0
\end{bmatrix}
$$

Matris satır satır tarandığında sıfırdan farklı elemanlar sırasıyla 1. satır 0. sütundaki 1, 1. satır 1. sütundaki 1 ve 2. satır 0. sütundaki 3'tür. Bu yüzden sıkıştırılmış matris (1 0 1), (1 1 1), (2 0 3) satırlarından oluşur. İşlemden sonra menü yeniden gelir, kullanıcı 3'ü seçince program sonlanır.

### 2.4 Yeni bir matris oluşturulmalı

İkinci kural (ekrandan, 00:35:00): seyrek bir matristeki 0'dan farklı değerlerin satır, sütun ve değer bilgisini tutan yeni bir matris (sıkıştırılmış form) oluşturulmalıdır. Yani sıkıştırılmış formu yalnız ekrana yazdırmak yetmez; değerler gerçekten yeni bir matriste saklanmalıdır. Bu nokta oturumun sonunda bir öğrencinin sorusuyla da tekrar edildi (bkz. Örnek Sorular).

<!-- BELİRSİZ: Belgenin sonraki sayfasında başka kurallar da var (00:35:12'de switch-case ve if-else ile ilgili bir sorunun fark edildiği ve ikisinin de kullanılabileceği söylendi), ancak bu kısım karelerde görünmüyor. -->

## 3. Derste netleşen varsayımlar

Öğrencilerin soruları ve tekrar açıklamalar sırasında şu varsayımlar netleşti:

- **Matris kare olmak zorunda değildir.** Satır ve sütun sayısı kullanıcıdan alındığı için matrisin kare olup olmaması kullanıcının girdiği değerlere bağlıdır. Belgedeki örnek çalışmada da 3 x 2'lik bir matris girilmiştir. (Başta "kare şeklinde ilerleyin" denmiş, ardından bu düzeltilmiştir.)
- **Seyreklik denetlenmez.** Girilen matrisin seyrek olup olmadığını kontrol etmek gerekmez. Deneme yaparken zaman kaybetmemek için seyrek bir matris girmek yeterlidir.
- **Boyutlar kullanıcıdan alınır.** Satır ve sütun sayısı program içinde sabit verilmez.
- **Her satırda sıfırdan farklı eleman olması gerekmez.** Bir satırın tamamı sıfır olabilir. Programı denerken yeni matrisin doğru oluştuğunu görebilmek için birkaç sıfırdan farklı değer girilmesi önerildi.
- **Switch-case ya da if-else kullanılabilir.** Menü seçimini ayırt etmek için ikisinden biri kullanılabilir; bu konuda bir zorunluluk yoktur.
- **İyi tasarım beklenir.** Çözüm mümkün olan en iyi biçimde yazılmalıdır. Fonksiyonlar öğrenilmiş olsaydı fonksiyon kullanılması istenirdi; henüz öğrenilmediği için her şey `main` içinde yapılabilir.

## 4. Çözüm fikri ve örnek bir C programı

Bu bölüm derste anlatılmadı. Çözüm ajan tarafından, problem metni ve derste netleşen varsayımlar izlenerek yazıldı.

### 4.1 Seyrek matristen sıkıştırılmış matrise

Seyrek matris iç içe iki döngüyle satır satır taranır. Sıkıştırılmış matriste kaç satırın dolduğunu tutan bir sayaç (`adet`) 0'dan başlar. Sıfırdan farklı bir eleman bulunduğunda sıkıştırılmış matrisin `adet`. satırına sırasıyla satır numarası, sütun numarası ve değer yazılır, sonra sayaç bir artırılır. Tarama bittiğinde `adet`, sıfırdan farklı eleman sayısına eşittir. Satır satır tarandığı için sıkıştırılmış matrisin satırları ekrandaki tablodaki gibi satır numarasına göre sıralı çıkar.

Ekrandaki A matrisinde tarama şöyle ilerler: 0. satırda yalnız 3. sütun sıfırdan farklıdır, (0, 3, 1) yazılır ve `adet` 1 olur; 1. satırda (1, 1, 2), 2. satırda (2, 3, 3), 3. satırda (3, 4, 5), 4. satırda (4, 0, 8) yazılır ve sonunda `adet` 5 olur.

### 4.2 Sıkıştırılmış matristen seyrek matrise

Geri dönüşümde seyrek matrisin boyutları ve sıkıştırılmış matrisin satırları bilinir. Önce seyrek matrisin bütün elemanları 0 yapılır. Sonra sıkıştırılmış matrisin her satırı için `seyrek[satır][sütun] = değer` ataması yapılır. Sıkıştırılmış formda sıfırlar saklanmadığı için bu ilk sıfırlama adımı gereklidir.

### 4.3 Menü döngüsü

Programın her işlemden sonra menüyü yeniden göstermesi için menü bir `do-while` döngüsünün içine konur. Döngü koşulu "seçim 3 değil" olduğundan, kullanıcı 3'ü seçene kadar menü tekrar gelir. Döngüden çıkış koşulu döngünün kendi koşulunda yazıldığı için `break` gerekmez.

### 4.4 Program

Aşağıdaki program derste yazılmadı; ajan tarafından yazıldı, `gcc -Wall` ile uyarısız derlendi ve ekrandaki girdilerle denendi:

- 3 x 2'lik örnekte (elemanlar 0, 0, 1, 1, 3, 0) çıktı ekrandaki gibi (1 0 1), (1 1 1), (2 0 3) oldu.
- 5 x 6'lık A matrisinde çıktı ekrandaki tablo (0 3 1), (1 1 2), (2 3 3), (3 4 5), (4 0 8) oldu; bu tablo 2. seçenekle girildiğinde A matrisi aynen geri kuruldu.

Dersin genel kurallarına uygun olarak `break`, `continue`, `goto` ve global değişken içermez. Fonksiyonlar henüz işlenmediği için her şey `main` içindedir. Ekranda görünen kısımda 2. seçenekte sıkıştırılmış matrisin nasıl girileceği yer almadığından bu seçeneğin giriş biçimi (boyutlar, sıfırdan farklı eleman sayısı, ardından her satır için satır, sütun ve değer) ajan tarafından seçildi.

```c
#include <stdio.h>
#define MAX 20

int main(void) {
    int secim, satir, sutun, i, j, k, adet;
    int seyrek[MAX][MAX];
    int sikis[MAX * MAX][3];

    do {
        printf("Menu:\n");
        printf("(1) Seyrek Matristen Sikistirilmis Matrise\n");
        printf("(2) Sikistirilmis Matristen Seyrek Matrise:\n");
        printf("(3) Cikis\n");
        scanf("%d", &secim);

        if (secim == 1) {
            printf("Matrisin Boyutlarini Girin (Satir, Sutun): ");
            scanf("%d %d", &satir, &sutun);
            printf("Matrisin Elemanlarini Giriniz\n");
            for (i = 0; i < satir; i++)
                for (j = 0; j < sutun; j++) {
                    printf("[%d][%d]: ", i, j);
                    scanf("%d", &seyrek[i][j]);
                }
            /* sifirdan farkli her eleman icin (satir, sutun, deger) satiri */
            adet = 0;
            for (i = 0; i < satir; i++)
                for (j = 0; j < sutun; j++)
                    if (seyrek[i][j] != 0) {
                        sikis[adet][0] = i;
                        sikis[adet][1] = j;
                        sikis[adet][2] = seyrek[i][j];
                        adet++;
                    }
            printf("Sikistirilmis Matris\n");
            for (k = 0; k < adet; k++)
                printf("%d\t%d\t%d\n", sikis[k][0], sikis[k][1], sikis[k][2]);
        } else if (secim == 2) {
            printf("Seyrek matrisin boyutlari (Satir, Sutun): ");
            scanf("%d %d", &satir, &sutun);
            printf("Sifirdan farkli eleman sayisi: ");
            scanf("%d", &adet);
            for (k = 0; k < adet; k++) {
                printf("%d. satir (Satir Sutun Deger): ", k + 1);
                scanf("%d %d %d", &sikis[k][0], &sikis[k][1], &sikis[k][2]);
            }
            /* once tum elemanlar 0, sonra kayitli degerler yerine konur */
            for (i = 0; i < satir; i++)
                for (j = 0; j < sutun; j++)
                    seyrek[i][j] = 0;
            for (k = 0; k < adet; k++)
                seyrek[sikis[k][0]][sikis[k][1]] = sikis[k][2];
            printf("Seyrek Matris\n");
            for (i = 0; i < satir; i++) {
                for (j = 0; j < sutun; j++)
                    printf("%d ", seyrek[i][j]);
                printf("\n");
            }
        }
    } while (secim != 3);
    return 0;
}
```

Programda matris boyutu `MAX` (20) ile sınırlıdır; sıkıştırılmış matris en kötü durumda bütün elemanları tutabilsin diye `MAX * MAX` satırlıdır. Daha büyük matrisler için `MAX` artırılmalıdır.

> **Ek bilgi (derste anlatılmadı):** Gerçek uygulamalarda sıkıştırılmış matris için yer, sıfırdan farklı eleman sayısı önce sayılarak tam gerektiği kadar ayrılır; böylece bellek kazancı gerçekten elde edilir. Bu programda diziler sabit boyutlu olduğu için amaç bellek kazancı değil, iki temsil arasındaki dönüşümün mantığını göstermektir. Dinamik bellek ayırma büyük olasılıkla dersin ilerleyen konularındandır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:30:00): Seyrek matristen sıkıştırılmış matrisi ve sıkıştırılmış matristen seyrek matrisi elde eden programı C dilinde yazın. Sıkıştırılmış formda sıfırdan farklı her değer bulunduğu satır, sütun ve değeri ile ifade edilir. Program bir menü içermeli ((1) Seyrek Matristen Sıkıştırılmış Matrise, (2) Sıkıştırılmış Matristen Seyrek Matrise, (3) Çıkış), seçeneklerden biri programı sonlandırmalı ve program bir işlemi tamamladığında kendini yinelemelidir. Sıfırdan farklı değerlerin satır, sütun ve değer bilgisini tutan yeni bir matris oluşturulmalıdır. Örnek: yukarıdaki 5 x 6'lık A matrisinin sıkıştırılmış formu (0 3 1), (1 1 2), (2 3 3), (3 4 5), (4 0 8) satırlarıdır.

> **Çözüm (derste verilmedi):** Seyrek matris satır satır taranır, sıfırdan farklı her eleman için sıkıştırılmış matrisin bir sonraki satırına (satır, sütun, değer) yazılır. Geri dönüşümde önce bütün elemanlar 0 yapılır, sonra her satırdaki değer kendi konumuna atanır. Menü `do-while` döngüsüyle "Çıkış" seçilene kadar tekrar gösterilir. Bölüm 4.4'teki program `gcc -Wall` ile derlendi; A matrisi için ekrandaki tabloyu, 3 x 2'lik örnek için (1 0 1), (1 1 1), (2 0 3) çıktısını verdi.

**Soru 2** (derste sözlü, 00:22:50): Matrisi kare matris olarak mı alacağız?

> **Cevap (derste verildi):** Hayır, kare olmak zorunda değil. Satır ve sütun sayısı kullanıcıdan alınıyor; belgedeki örnek çalışmada da satır sayısı 3, sütun sayısı 2 olan bir matris girilmiş. Kare olup olmaması kullanıcının girdiği değerlere bağlıdır.

**Soru 3** (derste sözlü, 00:25:38): Algoritmanın nasıl tasarlandığının bir önemi olacak mı, yoksa her şekilde olur mu?

> **Cevap (derste verildi):** En iyi şekilde yazmaya çalışılmalı. Fonksiyonlar öğrenildiyse fonksiyon kullanılmalı; öğrenilmediyse her şey `main` içinde yapılabilir.

**Soru 4** (derste sözlü, 00:27:53): Girilen matrisin seyrek olmama durumuyla ilgilenecek miyiz?

> **Cevap (derste verildi):** Hayır, bu durumla ilgilenmeye gerek yok; zaman kaybetmemek için deneme yaparken seyrek bir matris girilebilir.

**Soru 5** (derste sözlü, 00:38:37): Sıkıştırılmış matrisi yalnız yazdırmak yetiyor mu, yoksa bir matris tanımlamamız mı gerekiyor?

> **Cevap (derste verildi):** Bir matris tanımlanmalı. Belgede de yeni bir matris oluşturulması gerektiği belirtilmiştir.

**Soru 6** (derste sözlü, 00:38:56): Her satırda sıfırdan farklı bir eleman bulunmak zorunda mı?

> **Cevap (derste verildi):** Hayır, böyle bir zorunluluk yok. Ama programı test edebilmek için birkaç sıfırdan farklı değer girilmeli ve yeni matrisin oluşup oluşmadığı kontrol edilmeli.

## Dersin Toparlaması

Bu laboratuvar oturumunda iki boyutlu diziler, iç içe döngüler ve menü döngüsü bir arada kullanıldı. Problem, büyük kısmı sıfır olan bir seyrek matrisin yalnız sıfırdan farklı elemanlarını (satır, sütun, değer) üçlüleri hâlinde yeni bir matriste tutmak ve bu sıkıştırılmış matristen orijinal matrisi geri elde etmekti. Program bir menüyle çalışmalı, her işlemden sonra menüyü yeniden göstermeli ve yalnız "Çıkış" seçildiğinde sonlanmalıydı.

Derste matrisin kare olmak zorunda olmadığı, seyreklik denetimi gerekmediği, bir satırın tamamen sıfır olabileceği ve sıkıştırılmış formun yalnız yazdırılmayıp yeni bir matriste saklanması gerektiği netleşti. Dönüşümün bir yönü matrisi satır satır tarayıp sıfırdan farklı elemanları sırayla kaydetmek, diğer yönü ise sıfırlarla dolu bir matrise kayıtlı değerleri yerleştirmektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
