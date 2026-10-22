# Ders 24 Çalışma Özeti

## Genel Konular

- Bu ders, sınav haftasındaki ikinci tekrar dersidir. Ara sınavın ikinci sorusu tekrar edilir, ardından kümelerdeki bağıntılar üzerinden yeni problemler konuşulur.
- Ara sınav 2. soru: matristen sütun silme (ekrandan, 00:09:50)
  - Akış diyagramı:
    - N, M, `matris[N][M]` ve silinecek sütun X okunur.
    - `J ← X+1 || 1 || M`, `I ← 1 || 1 || N`: `matris[I][J−1] = matris[I][J]`. Silinen sütunun sağındaki sütunlar birer sola kaydırılır.
    - `I ← 1 || 1 || N`: `matris[I][M] = 0`. Son sütun bir kez sıfırlanır.
  - Bazı öğrenciler atamayı `matris[I][J] = matris[I][J+1]` biçiminde yazıp J'yi X'ten başlatmıştır. Bu da doğrudur.
  - Uç durum: son sütun silinirse (X = M = 4) döngü J = 5'ten başlar. $5 \le 4$ yanlış olduğu için kaydırma döngüsüne hiç girilmez. Yalnızca son sütun sıfırlanır ve algoritma doğru çalışır.
  - İlk sütunu, ortadaki bir sütunu ve son sütunu silmek birbirinden farklı durumlardır. Ödevlerde bu durumların her biri için ekran çıktısı istenir.
- Kümelerde bağıntı özellikleri (ekrandan, 00:31:30)
  - Bir küme ve elemanları arasındaki ikili bağıntılar verilir. Örnek küme $\{1, 2, 3, 5, 7\}$, bağıntılar $\{(1,2), (3,5), (2,1), (3,7), (7,3), (1,1), (5,3)\}$.
  - Simetri özelliği: her $(a, b)$ için $(b, a)$ da bağıntıda bulunmalıdır. $(1, 1)$ gibi bir eleman simetriyi bozmaz, çünkü kendisinin karşılığıdır.
  - Yansıma özelliği: kümenin her x elemanı için $(x, x)$ bağıntıda bulunmalıdır. Örnek kümede bunun için $(1,1), (2,2), (3,3), (5,5), (7,7)$ gerekir.
  - Geçişkenlik özelliği: $(1,2)$ ve $(2,3)$ varsa $(1,3)$ da bulunmalıdır. Derste yalnızca adı geçti.
  - Bağıntılar hatalı verilmez ve aynı bağıntı iki kez bulunmaz.
- Simetri kontrolü için çözüm 1: bağıntı matrisi
  - Kümenin elemanları kadar satır ve sütunu olan bir matris kullanılır. Örnek için 7×7. Her $(a, b)$ bağıntısı için `matris[a][b] = 1` yapılır, diğer gözler 0'dır.
  - Bağıntı simetrikse matris kendi transpozuna eşittir: her I, J için `matris[I][J] = matris[J][I]`.
  - Bütün matrisi gezmeye gerek yoktur. Köşegenin yalnızca bir tarafı gezilir ve karşılığıyla karşılaştırılır.
  - İlk eşitsizlikte döngüden çıkılabileceği için while kullanılmalıdır.
  - Daha iyisi, matrisin tamamı yerine yalnızca verilen bağıntıları gezmektir: her $(a, b)$ için `matris[b][a]` 1 mi diye bakılır. Bu örnekte 7 kontrol yeterlidir.
  - Yansıma kontrolü matrisle kolaydır: köşegendeki gözlerin hepsi 1 olmalıdır.
  - Dezavantajı: kümede büyük sayılar varsa (ör. 999) çok büyük bir matris gerekir ve bellek boşa harcanır.
- Simetri kontrolü için çözüm 2: matris kullanmadan
  - Bağıntılar iki sütunlu bir yapıda saklanır.
  - Her $(a, b)$ bağıntısı için listenin başından itibaren $(b, a)$ aranır. Arama listenin tamamında yapılır, bağıntının kendisi de dahil. Böylece $(1, 1)$ gibi bağıntılar kendi karşılıklarını bulur.
  - Bir `flag` değişkeni her bağıntı için aramaya başlamadan önce 0 yapılır, $(b, a)$ bulununca 1 yapılır. İç döngüden `flag = 0` olarak çıkılırsa simetri bozulmuştur ve dış döngü de biter.
  - Örnek: bağıntılara $(3, 1)$ eklenirse $(1, 3)$ bulunamaz ve bağıntı simetrik olmaz.
- Kümelerle ilgili başka problem örnekleri
  - İki kümenin kesişimi var mı, varsa hangi elemanlardan oluşur?
  - Birleşim kümesi, fark kümesi (X'te olup Y'de olmayan elemanlar).
  - Bir küme diğerinin alt kümesi mi? Alt kümenin bütün elemanları diğer kümede bulunmalıdır. Bir eleman bile yoksa alt küme değildir.
  - Bir küme diğerini kapsıyor mu?
- Polinomlar
  - Bir polinomun kökleri bilgisayarla bulunabilir. İkinci dereceden bir denklemde diskriminant $\Delta = b^2 - 4ac$ hesaplanır. $\Delta \ge 0$ ise gerçel kök vardır, $\Delta < 0$ ise yoktur.
  - Bir polinomun bütün katsayıları en yüksek dereceden başlayarak, olmayan terimler için 0 yazılarak verilirse polinom yazdırılabilir. Örnek: `1 5 0 2 7` → $x^4 + 5x^3 + 2x + 7$. Katsayılar negatif de olabilir: `1 −5 0 2 7` → $x^4 - 5x^3 + 2x + 7$.
  - Yalnızca katsayılar verilip derecesi verilmezse, en yüksek derecenin ne olduğu bilinmeyeceği için polinom yazılamayabilir. Bu yüzden girdinin nasıl verildiği çok önemlidir.
  - Katsayılar bir karakter dizisi (string) olarak verilirse (ör. `"1507"` veya `"-1507"`), karakterler tek tek okunur. `-` görülürse bir sonraki rakam negatif alınır. Rakamın değeri `c − '0'` ile bulunur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Uç durumları (ilk, orta ve son sütunu silmek gibi) mutlaka deneyin. Ödevlerde farklı durumlar için ekran çıktısı istenmesinin sebebi budur.
- Final soruları muhtemelen ara sınavdan biraz daha zor olacaktır. İkinci ara sınav yapılmadığı için buna göre hazırlanın.
- Transpoz kontrolünde bütün matrisi gezmeyin. Köşegenin bir tarafı yeterlidir.
- İlk eşitsizlikte çıkılabilecek döngülerde while kullanın. Adım sayısı belli değildir.
- Bir problemi sıralayarak çözmek her zaman akla gelir, ama sıralama maliyetli bir iştir. Gerekmiyorsa sıralamayın.
- Karakter sabiti (`'A'`) ile ASCII değeri (65) arasında performans farkı yoktur. Karakter sabiti, değeri ezberlemek gerekmediği için tercih edilir.
- Farklı hocaların farklı anlatım stilleri vardır. Mümkün olduğunca farklı hocalardan ders alın ve farklı stilleri görün.
- Hem soru sorun hem fikir üretin. Yalnızca sormak da, yalnızca fikir üretmek de sizi bir yere götürmez.

## Kısa Tekrar Notları

- Sütun silme: X+1'den M'e kadar sola kaydır, son sütunu bir kez sıfırla. Son sütun silinirken kaydırma döngüsüne girilmez.
- Simetri: her $(a,b)$ için $(b,a)$ var mı?
- Yansıma: her x için $(x,x)$ var mı?
- Geçişkenlik: $(a,b)$ ve $(b,c)$ varsa $(a,c)$ var mı?
- Bağıntı matrisi: simetri = matris kendi transpozuna eşit. Yansıma = köşegen tamamen 1.
- Matrissiz çözüm: her bağıntı için listenin tamamında tersini ara. `flag` her aramadan önce 0.
- Polinom yazdırmak için bütün katsayılar (0'lar dahil) ve derece bilgisi gerekir.

## Detaylı Açıklamalar

Ders kısa tutulmuştur. Önce ara sınavın ikinci sorusunun akış diyagramı gösterilir ve son sütunun silinmesi gibi bir uç durum için algoritmanın doğru çalıştığı analiz edilir. Ardından kümelerde bağıntı kavramı hatırlatılır ve bir bağıntının simetrik olup olmadığını bulan algoritma için iki farklı yaklaşım tartışılır. Kümelerle ilgili başka soru tipleri ve polinomlarla ilgili problemler konuşulur. Son bölümde öğrencilerin C ve işletim sistemleriyle ilgili soruları cevaplanır. Hoca, bir sonraki iki haftanın uygulama derslerinde ekranda C kodu yazacağını söyler.

### Matrissiz simetri kontrolünde $(1,1)$ durumu

Bir öğrencinin ilk önerisi, $(a, b)$'nin ilk elemanını alıp diğer bağıntıların ikinci elemanlarında aramaktı. Hoca bunun eksik kaldığını gösterdi: $(1, 2)$ için arama yapılırken 1, $(1, 1)$ bağıntısında da bulunur. Bu eşleşmenin karşılığında 2 olmadığı için, yalnızca ilk bulunan eşleşmeye bakan bir algoritma simetrinin olmadığına yanlışlıkla karar verebilir. Doğrusu, her $(a, b)$ için iki elemanı birlikte karşılaştırarak $(b, a)$'yı aramaktır. Bir başka öğrencinin önerisiyle arama her bağıntı için listenin başından yapılır. $(1, 1)$ bağıntısının karşılığı kendisidir ve arama listenin tamamında yapıldığı için bu bağıntı da karşılığını bulur.

Bir öğrenci her bağıntının iki elemanını yer değiştirip $(b, a)$'yı listede aramayı önerdi. Hoca bunun da aynı kapıya çıktığını, yine iç içe iki döngü gerektirdiğini söyledi.

### Kontrol

Ders sonrasında matrissiz simetri ve yansıma kontrolleri C'ye çevrildi ve `gcc -Wall` ile derlendi. Derste kullanılan bağıntı kümesi simetrik bulundu. $(3, 1)$ eklendiğinde simetri bozuldu. Yansıma kontrolü örnek bağıntılarda yansımanın olmadığını, $(1,1), (2,2), (3,3), (5,5), (7,7)$ eklendiğinde ise sağlandığını gösterdi.

```c
int simetrik_mi(int bag[][2], int K)
{
    int i=0,j,flag=1;
    while(i<K && flag==1)
    {
        flag=0;                     /* (b,a) bulunana kadar 0 */
        j=0;
        while(j<K && flag==0)
        {
            if(bag[j][0]==bag[i][1] && bag[j][1]==bag[i][0])
                flag=1;
            j++;
        }
        i++;
    }
    return flag;
}
```

### Ders sonrası not

Derste ikinci dereceden denklemin kök formülü hatırlanamadı. Kökler $x_{1,2} = \dfrac{-b \pm \sqrt{\Delta}}{2a}$, $\Delta = b^2 - 4ac$ formülüyle bulunur. Bir öğrencinin söylediği gibi $2a$'ya bölünür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
