# Ders 29 Çalışma Özeti

## Genel Konular

- Tek boyutlu diziden çok boyutlu diziye geçiş
  - Değişken, bellekte belirli boyutta bir alana isimle erişmeyi sağlar. Aynı türden çok sayıda veri üzerinde ortak işlem yapmak için tek boyutlu dizi kullanılır; ortak işlemi mümkün kılan şey indis mantığıdır.
  - Çok boyutlu dizi: aynı türdeki verilerin tek sıra hâlinde değil, mantıksal olarak satır-sütun düzeninde tutulduğu yapı (ekrandan, 00:15:00).
  - İki boyutlu dizi matris (tablo) gibidir: birinci indis satırları, ikinci indis sütunları gezer. Üç boyutluda satır, sütun ve derinlik (dilim) için üç indis gerekir. Daha fazla boyut da tanımlanabilir (n boyut), ama 3 boyuttan sonrası görselleştirilemez.
  - Kaç indis varsa o kadar iç içe döngü gerekir.
- Bellekte tek boyut vardır
  - Bellek ardışık, özdeş depolama bloklarından oluşur. C'de çok boyutlu diziler içsel olarak tek boyutlu dizi biçiminde saklanır (ekrandan, 00:15:00).
- Çok boyutlu dizi tanımlama
  - Biçim: `<tür> [boyut1][boyut2][boyut3] ...`; boyutlar sabit ifadeler olmak zorundadır (ekrandan, 00:25:00).
  - `int A[5][8];` iki boyutlu bir dizidir (matris). İndisler `A[0][0]` ile `A[4][7]` arasında değişir.
  - Akış diyagramında iki boyutlu dizinin gezilmesi: dıştaki `i` döngüsü satırları, içteki `j` döngüsü sütunları gezer; örnek gövde `A[i][j] = i*j` (ekrandan, 00:25:00).
- İlk değer ataması
  - `int a[5][2] = {{10,20},{30,40},{50,60},{70,80},{90,100}};` ya da tek küme parantezinde `int a[5][2] = {10,20,30,40,50,60,70,80,90,100};` aynı sonucu verir; değerler `a00 a01 a10 a11 ... a40 a41` sırasıyla yerleşir (ekrandan, 00:30:00).
  - Okuma biçimi: `a`, her elemanı 2 elemanlı tamsayı dizisi olan 5 elemanlı bir tamsayı dizisidir. Örnekte `a[2][1]` = 60.
- Belleğe yerleşim
  - Satırlar sırayla yerleşir: önce 0. satır, sonra 1. satır (satır öncelikli düzen).
  - Örnek: `int a[5][2]` 1FC0 adresinden başlasın, her tamsayı 2 bayt olsun: `a[0][0]`=1FC0, `a[0][1]`=1FC2, `a[1][0]`=1FC4, `a[1][1]`=1FC6, `a[2][0]`=1FC8, `a[2][1]`=1FCA, `a[3][0]`=1FCC, `a[3][1]`=1FCE, `a[4][0]`=1FD0, `a[4][1]`=1FD2 (ekrandan, 00:35:00).
  - İki boyutlu dizilerin satır elemanları (`a[0]`, `a[1]`, ...) sol taraf değeri (lvalue) değildir; satırların bellekteki başlangıç adresini gösterirler.
- Matris toplama
  - Aynı boyutlu iki matriste aynı indisli elemanlar toplanır: `C[i][j] = A[i][j] + B[i][j]`. İç içe iki döngü yeterlidir.
- Matris çarpımı
  - $A$ matrisi $M \times N$, $B$ matrisi $P \times Q$ ise çarpım için $N = P$ olmalıdır; sonuç $M \times Q$ boyutludur.
  - Her sonuç gözü, A'nın bir satırı ile B'nin bir sütununun karşılıklı elemanlarının çarpımlarının toplamıdır: $C_{ij} = \sum_{k} A_{ik} B_{kj}$.
  - Üç iç içe döngü gerekir: `i` (A'nın satırları), `j` (B'nin sütunları), `k` (satır-sütun çarpımlarının toplanması). Akıştaki işlem kutusu: `C[i][j]=C[i][j]+A[i][k]*B[k][j]` (ekrandan, 00:55:00).
- Dizi tanımlarını katman katman okuma
  - `int w[10][20][30];` 10 elemanlı bir dizidir; her elemanı `int x[20][30]` gibi bir matristir; onun her elemanı `int y[30]` gibi bir dizidir; onun her elemanı `int z` gibi bir tamsayıdır (ekrandan, 01:10:00).
  - İlk indis her zaman bellekte bir bloğun başlangıç adresini gösterir.
- Çok boyutlu karakter dizileri
  - Tek boyutlu karakter dizileri: `char y[10] = {'y','i','l','d','i','z','\0'};`, `char t[]={'t','e','k','n','i','k','\0'};`, `char u[15]="universitesi";` (ekrandan, 01:15:00).
  - Çok boyutlu: `char ytu[3][15]={"yildiz","teknik","universitesi"};` 3x15 = 45 baytlık bir alan ayırır; çift tırnakla verilen dizgilerin sonuna `\0` derleyici tarafından konur. Kullanılmayan gözler boşa gider.
  - `a[i]` ile tek indis kullanmak bir satırın (bir karakter dizisinin) başlangıç adresini verir; `puts(a[i])` ya da `printf("%s\n", a[i])` `\0` görene kadar yazar.
- Karakter matrisi üzerinde işlemler
  - Boyutu aşan dizge: `char a[5][5]` içine "abuzittin" verilince yalnız ilk 5 karakter saklanır ve derleyici uyarı verir.
  - Tanımlanan satır sayısı kadar döngü döner; boş satırlar için de döngü çalışır. Yalnız dolu satırları yazmak için satırın ilk karakteri kontrol edilmelidir.
  - Her satırdaki karakter dizisini tersine çevirme: önce `\0`'a kadar sayarak uzunluk `k` bulunur, sonra `k/2` adımda baştaki ve sondaki karakterler `temp` ile yer değiştirilir (ekrandan, 01:45:00).
- Değişken izleme (iz sürme) tablosu
  - Algoritmanın doğru çalıştığını göstermek için her adımda değişkenlerin aldığı değerler bir tabloya yazılır (ters çevirme örneğinde `i`, `j`, `k`, `kk`, `ytu[i]`).

## Hocanın Özellikle Vurguladığı Kısımlar

- C'de çok boyutlu dizinin "dizilerden oluşan dizi" olarak okunması
  - `int a[5][2]` "her biri ikilik dizilerden oluşan beşlik dizi"dir. Bu bakış açısı C'nin dizi mantığını ve bellek yerleşimini anlamanın anahtarıdır.
- Bellek tek boyutludur
  - Kaç eksen tanımlanırsa tanımlansın, dizi arka planda tek boyutlu ve satır öncelikli olarak saklanır. Satır adları (`a[0]`, `a[1]`) satır başlangıç adresleridir.
- Boyutlar sabit olmalı
  - Dinamik bellek ayırma henüz bilinmediği için dizi boyutları `#define` ya da sabit sayıyla verilir; kullanıcıdan okunan değişkenle boyut verilmez. Bunun yerine büyük bir dizi (ör. 10x10) açılıp gerçek boyutlar (m, n) okunur.
- Matris çarpımında boyut kontrolü
  - Birinci matrisin sütun sayısı ikincinin satır sayısına eşit değilse çarpım yapılmaz; kontrol ikinci matris okunmadan önce yapılabilir.
- Dizi sınırını aşmamak
  - Ayrılan boyuttan uzun veri yazmak bu ortamda yalnız uyarı verse de başka ortamlarda hataya yol açabilir; sınır asla aşılmamalıdır.
- Kod okunabilirliği
  - Uzun kodlarda kapanan blokların yanına `// for j`, `// for i`, `// end else` gibi yorumlar yazmak takibi kolaylaştırır.

## Kısa Tekrar Notları

- Çok boyutlu dizi: satır-sütun düzeninde mantıksal yapı; bellekte tek boyutlu, satır öncelikli saklanır.
- Tanım: `tür ad[b1][b2]...`; boyutlar sabit ifade.
- `int a[5][2]` = 5 elemanlı dizi, her eleman 2 elemanlı tamsayı dizisi.
- İlk değer: iç içe küme parantezi ya da tek küme parantezi, değerler satır satır yerleşir.
- `a[i]` satır başlangıç adresidir, sol taraf değeri değildir.
- Toplama: `C[i][j]=A[i][j]+B[i][j]`, 2 döngü.
- Çarpma: $N=P$ şartı, sonuç $M\times Q$, 3 döngü, `sum += a[i][k]*b[k][j]`, her gözden sonra `sum=0`.
- Karakter matrisi: `char ytu[3][15]`, `printf("%s", ytu[i])` satırı `\0`'a kadar yazar.
- Satırı ters çevirme: uzunluk `k`, son indis `kk=k-1`, `j<k/2` boyunca takas ve `kk--`.

## Detaylı Açıklamalar

- **İki boyutlu dizinin gezilmesi.** `int A[5][8]` tanımında birinci boyut 5 satırı, ikinci boyut 8 sütunu verir. Akış diyagramında dıştaki döngü satırları (yavaş dönen), içteki döngü sütunları (hızlı dönen) gezer; iç döngü her satır için baştan sona çalışır. Örnek gövdede her göze `A[i][j] = i*j` atanır. Aynı yapı okuma, yazdırma ya da başka bir atama için de kullanılır (ekrandan, 00:25:00).

- **Bellek yerleşimi örneği.** `int a[5][2]` 1FC0 adresinden başlasın ve tamsayılar 2 bayt olsun. Her adımda adres 2 artar: 1FC0, 1FC2, 1FC4, 1FC6, 1FC8, 1FCA, 1FCC, 1FCE, 1FD0, 1FD2. Onaltılık sistemde 1FCE + 2 = 1FD0 olur (E, F'den sonra elde ile C, D'ye döner). `a[0]` 1FC0'ı, `a[1]` 1FC4'ü, `a[2]` 1FC8'i, `a[3]` 1FCC'yi, `a[4]` 1FD0'ı gösterir (ekrandan, 00:35:00). İşletim sistemi bu alanı fiziksel olarak parçalara bölebilir, ama program açısından mantıksal olarak ardışık bir bloktur.

- **Matris toplama kodu.** Derste `M=5`, `N=2` sabitleriyle iki matris ilk değerle verildi ve toplam ayrı bir `c` matrisine yazıldı; çarpma için de üçüncü matris gerekeceğinden toplam `a`'nın üzerine yazılmadı (kod ekrandan, 00:45:00; yazdırma biçimi çıktıdan, 01:00:00). Aşağıdaki kod `gcc -Wall` ile derlenip çalıştırıldı (yalnız tek küme parantezli ilk değer için `-Wmissing-braces` uyarısı verir, sonuç doğrudur):

```c
#include <stdio.h>
#define M 5
#define N 2

int main()
{
    int a[M][N]={10,20,30,40,50,60,70,80,90,100};
    int b[M][N]={5,10,15,20,25,30,35,40,45,50};
    int c[M][N];
    int i,j;

    for (i=0;i<M;i++)
        for(j=0;j<N;j++){
            c[i][j]=a[i][j]+b[i][j];
            printf("[%d][%d]=%d\n",i,j,c[i][j]);
        }

    return 0;
}
```

  Çıktı: `[0][0]=15`, `[0][1]=30`, `[1][0]=45`, ..., `[4][1]=150`.

- **Matris çarpımı kodu.** Diziler 10x10 açılır, gerçek boyutlar kullanıcıdan okunur. Boyut kontrolü ikinci matris okunmadan yapılır. Toplam `sum` değişkeninde biriktirilir, göz yazıldıktan sonra sıfırlanır. Kod ekrandan alındı (01:00:00, 01:05:00); ekranda ilk okuma döngüsünde bir an görünen `j<m` hatası hocanın düzelttiği hâliyle `j<n` yazıldı. Bu kod `gcc -Wall` ile derlenip çalıştırıldı:

```c
#include <stdio.h>

int main()
{
    int a[10][10], b[10][10], c[10][10];
    int m,n, p, q, i, j, k, sum=0;

    printf("m-n degerlerini giriniz:");
    scanf("%d%d",&m,&n);

    for (i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    printf("p-q degerlerini giriniz:");
    scanf("%d%d",&p,&q);

    if (n!=p)
        printf("boyutlar tutarsiz. Carpilamazlar.");
    else{
        for (i=0;i<p;i++)
            for(j=0;j<q;j++)
                scanf("%d",&b[i][j]);
        //carpim islemi
        for(i=0;i<m;i++){
            for(j=0;j<q;j++){
                for(k=0;k<p;k++){
                    sum+=a[i][k]*b[k][j];
                }
                c[i][j]=sum;
                sum=0;
            } // for j
        } // for i

        printf("\nCarpim Sonucu:\n");
        for(i=0;i<m;i++){
            for(j=0;j<q;j++)
                printf("%4d",c[i][j]);
            printf("\n");
        }
    } // end else

    return 0;
}
```

  Derste denenen girdi: 2x2 `{1,2,3,4}` ile 2x2 `{5,6,7,8}`; sonuç `19 22 / 43 50`. `%4d` her sayıya 4 karakterlik yer ayırır.
  - Ders sonrası not: Hoca önce 3x3 ile 3x2 matris girip "çarpılamazlar" çıktısı aldı ve girdiyi ters yazdığını söyledi. 3x3 ile 3x2 aslında çarpılabilir ($N=P=3$); bu çıktı büyük olasılıkla boyutların yanlış girilmesinden kaynaklandı.

- **Çok boyutlu karakter dizisini yazdırma.** `char a[N][N] = {"ali","veli","ayse","can"};` (`N=5`) tanımında `for(i=0;i<N;i++) printf("%s\n",a[i]);` her satırı `\0` görene kadar yazar; ikinci bir döngü gerekmez (ekrandan, 01:20:00). `char a[10][10]` içine karakter karakter `{'a','l','i','\0'}`, `{'v','e','l','i','\0'}`, `{'f','a','t','m','a','\0'}` verildiğinde döngü 10 kez döner; boş satırlar boş yazdırılır (ekrandan, 01:25:00). `while (a[i] != '\0')` koşulu ise satırın adresini kontrol ettiği için hiç yanlış olmaz ve döngü dizinin sınırını aşıp yüzlerce satır yazar (ekrandan, 01:30:00). Doğrusu satırın ilk karakterini (`a[i][0]`) kontrol etmektir; bu şekilde yalnız `0: ali`, `1: veli`, `2: fatma` yazdırılır (çıktı ekrandan, 01:35:00). <!-- BELİRSİZ: son düzeltilmiş kodun tam satırı karede görünmüyor; altyazıya göre ilk karakter kontrolü eklendi. -->

- **Karakterleri sütun sütun yazdırma (sözlü).** `ali`, `veli`, `can` satırlarını sütun sütun yazınca `a v c l e a i l n i` elde edilmelidir (ekrandan, 01:35:00). Hoca kodu yazmadı, yöntemi anlattı: `while` ile sütun sayacı sabitken satırlar gezilir, satırlar bitince satır sayacı sıfırlanıp sütun sayacı artırılır; `\0`'dan sonraki bilinmeyen karakterler yazılmasın diye `\0` görülen satırın bir sonraki gözü de `\0` yapılır. Bu alıştırma öğrencilere bırakıldı.

- **Her satırı ters çevirme.** `char ytu[N][15]` içindeki her dizge için önce `for(k=0;ytu[i][k];k++);` ile uzunluk `k` bulunur, `kk=k-1` son karakterin indisidir. `j`, 0'dan `k/2`'ye kadar giderken `ytu[i][j]` ile `ytu[i][kk]` takas edilir ve `kk--` yapılır. `k` döngü sınırında kullanıldığı için azaltılmaz; ayrı bir kopya (`kk`) kullanılır. Derste `{"i","love","yildiz","teknik","universitesi","so","gut"}` ile sonuç `i, evol, zidliy, kinket, isetisrevinu, os, tug` oldu (ekrandan, 01:50:00); tek, iki ve üç karakterli dizgilerde de doğru çalıştığı görüldü. Kod `gcc -Wall` ile derlenip aynı çıktı alındı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
