# Ders 22 Çalışma Özeti

## Genel Konular

- Uygulamalı bölüme geçiş
  - Dizi, matris, özyineleme ve rastgelelik konuları bitti. Bundan sonraki derslerde bu yapılar bilgisayar bilimlerindeki farklı problemlere uygulanır: sepet analizi, dil işleme, kriptoloji, görüntü işleme.
  - Çözümler yine dizi ve matrislerle, işlemler fonksiyonlarla yapılır; gerekirse özyineleme kullanılır.
- Sepet analizi (birliktelik analizi, association analysis) (ekrandan, 00:05:00)
  - Soru: en çok birlikte satılan (alınan) ürün ikilileri hangileridir?
  - Veri: `S` matrisi, `N` satır ve 2 sütun: `sepetID`, `ürünID`. Bir sepette birden çok ürün varsa her ürün ayrı satıra yazılır; satır sayısı sepet ya da ürün sayısından bilinemez.
  - Gerçek hayattaki kullanımı: alışveriş sitelerinde "bunu alanlar şunu da aldı" önerileri ve birlikte alım indirimleri, müzik ve video tavsiyeleri.
  - Birliktelik mantıklı olmak zorunda değildir; veri madenciliğinin konusudur. Hocanın örneği: bir bölgede bebek bezi ile bir içeceğin birlikte çok satıldığı bulunmuş.
- Üç matrisle çözüm (ekrandan, 00:35:00 ve 01:05:00)
  - `S` (sepet) matrisinden doğrudan ikili saymak zordur. Önce `A` matrisi kurulur: satır ürün, sütun sepet, değer 1 (ürün o sepette var) ya da 0.
  - `A` da tek başına yetmez; satırdaki 1'leri saymak ürünün kaç sepette olduğunu verir, aynı sepette olup olmadığını vermez.
  - `T` matrisi (ürün × ürün): `T[i][j]`, `i` ve `j` ürünlerinin aynı sepette kaç kez bulunduğudur. `T`'nin en büyük elemanının indisleri en çok birlikte satılan ikiliyi verir.
  - `T` simetriktir ve köşegeni anlamsızdır; bu yüzden yalnız üst üçgen (`j = i+1`'den başlayarak) hesaplanır.
- Ürün üçlüleri
  - `T` üç boyutlu olur: `T[i][j][k]`, döngüler `j = i+1`, `k = j+1`'den başlar; sepet döngüsü için dördüncü bir değişken (`m`) gerekir.
  - Bellek iyileştirmesi (bir öğrencinin önerisi): `T` dizisi tutulmaz; her üçlü için sayaç `c` hesaplanır ve en büyük değerle anında karşılaştırılır.
  - Zaman iyileştirmesi fikri: `A[i][m]` 1 değilse `j` ve `k` ürünlerine hiç bakılmaz (iç içe `if` ile gereksiz karşılaştırmalar atlanır). Hoca bu kodu test etmeden taslak olarak yazdı.
- Karmaşıklık
  - İkililer: ürün sayısı × ürün sayısı × sepet sayısı; hepsi $n$ alınırsa $O(n^3)$.
  - Üçlüler: $O(n^4)$. Üç boyutlu `T` için bellek $O(n^3)$.
  - Genel: $r$'li gruplar için zaman $O(n^{r+1})$; ürün altılıları için $O(n^7)$ zaman ve altı boyutlu matris.
- Yığın (stack) ve kuyruk (queue) (ekrandan, 01:35:00)
  - Programlardaki geri al / ileri al mekanizması yığınla yapılır. Geri alınan adımlar ikinci bir yığına konur; ileri al o yığından geri alır.
  - Yığın: yalnız tepeden ekleme (push) ve tepeden çıkarma (pop). Yığın işaretçisi (stack pointer) ekleme ve çıkarma yerini gösterir.
  - Kuyruk: arkadan eklenir, önden çıkılır; önce gelen önce hizmet alır.
  - Dizi ve bağlı liste veriyi saklamak için, yığın ve kuyruk veriye erişmek için kullanılan yapılardır.
- Kelime birliktelikleri (ekrandan, 01:40:00 - 02:15:00)
  - Metindeki her kelimeye bir sayı (ID) verilir; metin bir sayı dizisi `M` olur.
  - Arka arkaya en çok geçen kelime ikilileri: `W[M[i]][M[i+1]]++`.
  - $\pm K$ komşuluk: her kelimenin $K$ önceki ve $K$ sonraki kelimeleriyle birlikteliği `WK` matrisinde sayılır; kelimenin kendisiyle eşleşmesi sonunda bir azaltılır.
  - Kullanım: collocation (birlikte kullanım) listeleri, Academic Word List, anlamsal uzay, OCR hatalarının düzeltilmesi.
- Anlamsal uzay (ekrandan, 02:25:00)
  - Birlikte geçen kelimeler anlamca birbirine yakındır. `W` matrisi bir yöntemle iki boyutlu düzleme çizilince benzer kelimeler kümelenir (eşyalar, hayvanlar, giysiler).
  - `W` matrisi arama motorundaki ikili arama sonuç sayılarıyla da kurulabilir.
  - Yapısal benzerlik (harflerin benzemesi) ile anlamsal benzerlik farklıdır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Veriyi problemi çözmeye uygun biçime dönüştürmek
  - Ham `S` matrisiyle doğrudan çözüm aranırsa kod matrisin içinde kaybolur. Önce `A` (varlık/yokluk), sonra `T` (birliktelik sayısı) matrisi kurulur.
- `if` yerine çarpma
  - `A[i][k]` ve `A[j][k]` 0/1 değerli olduğu için çarpımları ancak ikisi de 1 iken 1 olur. `if((A[i][k]==1) && A[j][k]==1) T[i][j]+=1;` yerine `T[i][j] += A[i][k]*A[j][k];` yazılır; hocanın sayımına göre dört işlem ikiye iner.
  - `if`'ten kurtulmak için `while` kullanılmaz; `while` bir döngüdür.
- Simetri ve gereksiz hesaplar
  - 1 ile 2 bir kez hesaplanınca 2 ile 1 tekrar hesaplanmaz. İç döngü `i+1`'den başlar.
- Dizi sınırları
  - Kelime ikilisi sayımında `i+1` kullanıldığı için döngü `MAX-1`'e kadar gitmelidir; $\pm K$ komşulukta `i`, `K`'dan başlar ve `MAX-K`'dan önce durur.
- Algoritmanın karmaşıklığına bakılmalı
  - Projelerde de algoritmanın karmaşıklığı hesaplanmalıdır. En yüksek dereceli terim alınır.

## Kısa Tekrar Notları

- `A[urun][sepet] = 1` dönüşümü: `A[sepet[i][1]][sepet[i][0]] = 1;` (her `S` satırı için).
- `T[i][j] += A[i][k]*A[j][k];`, `i < urunSayisi`, `j = i+1 ... urunSayisi`, `k < sepetSayisi`.
- En çok birlikte satılan ikili: `T`'nin en büyük elemanının indisleri.
- Üçlüler: dört iç içe döngü, $O(n^4)$; `T` tutulmazsa bellek tasarrufu sağlanır, zaman yine $O(n^4)$.
- Yığın: tepeden ekle, tepeden çıkar. Kuyruk: arkadan ekle, önden çıkar.
- Geri al / ileri al: iki yığın.
- Kelime ikilileri: `W[M[i]][M[i+1]]++`, `i < N-1`.
- $\pm K$ komşuluk: `for(i=K; i<N-K; i++) for(j=-K; j<=K; j++) WK[M[i]][M[i+j]]++;` sonra `WK[M[i]][M[i]]--;`.
- Birlikte geçen kelimeler anlamca yakındır; anlamsal uzay bu fikirle kurulur.

## Detaylı Açıklamalar

- Sepet analizi kodu (ekrandan, 00:20:00 - 00:50:00)
  - Test verisi `int sepet[MAX][2]` ile yazıldı (`#define MAX 10`), `N=8`, `urunSayisi=5`, `sepetSayisi=5`. `A[MAX][MAX]={{0}}` ile sıfırlandı.
  - Hocanın son ikili verisi (ekrandan, 00:45:00 çıktısıyla tutarlı): `{1,2},{2,1},{2,4},{2,2},{1,4},{3,2},{4,1},{4,2}` (sepet, ürün). Sepet 1: {2,4}, sepet 2: {1,4,2}, sepet 3: {2}, sepet 4: {1,2}.
  - Çıktı: `T[1][2]=2`, `T[2][4]=2`, `T[1][4]=1`. En büyük değeri bulma kısmı derste öğrencilere bırakıldı.
  - Aşağıdaki kod karelerden kuruldu; en büyük değeri bulan son kısım derste yazılmadı, ajan ekledi. `gcc -Wall` ile derlendi, çalıştırıldı ve ekrandaki çıktıyla aynı sonucu verdi.

```c
#include <stdio.h>
#define MAX 10
int main(){
    int sepet[MAX][2]={ {1,2},{2,1},{2,4},{2,2},{1,4},{3,2},{4,1},{4,2} };
    int N=8;
    int urunSayisi = 5;
    int sepetSayisi = 5;
    int A[MAX][MAX]={{0}};
    int T[MAX][MAX]={{0}};
    int i,j,k;
    for(i=0;i<N;i++){
        A[sepet[i][1]][sepet[i][0]] = 1;
    }
    for(i=0;i<urunSayisi;i++){
        for(j=0;j<sepetSayisi;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<urunSayisi;i++){
        for(j=i+1;j<urunSayisi;j++){
            for(k=0;k<sepetSayisi;k++){
                T[i][j] += A[i][k]*A[j][k];
            }
        }
    }
    printf("\n");
    for(i=0;i<urunSayisi;i++){
        for(j=0;j<urunSayisi;j++){
            printf("%d ",T[i][j]);
        }
        printf("\n");
    }
    /* derste verilmedi: T'nin en büyüğü */
    int max=0, yi=0, yj=0;
    for(i=0;i<urunSayisi;i++)
        for(j=i+1;j<urunSayisi;j++)
            if(T[i][j]>max){ max=T[i][j]; yi=i; yj=j; }
    printf("En cok birlikte satilan ikili: %d-%d (%d kez)\n", yi, yj, max);
    return 0;
}
```

- Ürün üçlüleri (ekrandan, 01:20:00 - 01:30:00)
  - Veri: `{1,2},{2,2},{2,4},{2,3},{1,3},{1,4},{4,1},{4,2}`. Sepet 1 ve sepet 2'de 2, 3, 4 ürünleri birlikte vardır; çıktı `2-3-4` oldu.
  - Bellek iyileştirmeli sürümde her `(i,j,k)` için sayaç `c` sayılır, `c > max` ise `max` ve `yi, yj, yk` güncellenir.
- Kelime birliktelikleri (ekrandan, 02:10:00 ve 02:15:00)
  - Dizi: `M[MAX] = {2,4,3,5,2,4,5,2,4,3}` (son eleman derste sonradan eklendi), `K = 3`.
  - Komşu ikililerde en büyük değer `W[2][4]=3` oldu. $\pm K$ komşulukta 5 ile 2 ve 5 ile 4 dörder kez birlikte geçti.
- Ders sonrası notlar
  - Kelime ikilisi döngüsü önce `i < MAX` diye yazıldı. Son adımda `M[i+1]`, yani `M[10]` okunur; bu dizi sınırı dışıdır ve C'de tanımsız davranıştır. Hoca bunu işletim sisteminin engellemesiyle açıkladı. Tanımsız davranışta sonuç önceden bilinemez; program çökebilir ya da hatasız görünebilir. Düzeltme `i < MAX-1` oldu.
  - Derste $\pm K$ iç döngüsü `for(j=-K; j<K; j++)` diye yazıldı (ekrandan, 02:05:00). Bu döngü $K$ önceki kelimeye ama yalnız $K-1$ sonraki kelimeye bakar. Ders notundaki `for j=-K:K` ise iki yönde de $K$ kelimeye bakar; simetrik sayım için C'de `j <= K` yazılmalıdır. Ekrandaki `WK` çıktısı `j < K` ile üretilmiştir.
  - Üçlü kodunda sayaç `c`'nin her üçlü için sıfırlandığı satır karede görünmüyor (ekrandan, 01:25:00). `c` her `(i,j,k)` için `0`'dan başlamazsa önceki üçlülerin sayısı birikir ve sonuç yanlış olabilir. Ders verisinde son geçerli üçlü zaten `2-3-4` olduğu için çıktı doğru göründü.
  - Ekrandaki programlar `main` sonunda `return 0;` olmadan çalıştırıldı; dönüş değeri olarak anlamsız sayılar (5, 10) görüldü. `return 0;` yazılması önerilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
