# Ders 23 Çalışma Özeti

## Genel Konular

- Bu ders, sınav haftasında yapılan kısa bir tekrar dersidir. 3. ödev (sözlük uygulaması) ve birinci ara sınavın yazılı bölümündeki ilk soru üzerinden geçilir. Yeni konu anlatılmaz.
- 3. ödev: kelimeleri alfabetik sıralama
  - Kelimeler karışık verilir ve alfabetik sıraya dizilmesi istenir. Normal sayı sıralamasından farkı, iki kelimenin harf harf karşılaştırılmasıdır.
  - İki kelime karşılaştırılırken harfler eşit olduğu sürece bir sonraki harfe geçilir. İlk farklı harfte, harfi küçük olan kelime alfabetik olarak öndedir.
  - Öğrencilerin önerdiği yaklaşımlar:
    - Önce ilk harfe göre gruplamak, sonra her grubu ikinci harfe göre sıralamak ve tek eleman kalana kadar devam etmek. Hoca bunun çok verimli olmadığını söyledi.
    - Bubble sort benzeri bir yapıyla, iç içe iki döngüde kelimeleri harf harf karşılaştırmak.
    - Önce kelimelerin uzunluğunu bulmak, sonra ortak harfleri atlayıp ilk farklı harfe göre karar vermek.
  - Kelimelerin yerini değiştirmek yerine sıra (indis) dizisi kullanmak: her kelimenin sırası ayrı bir sayı dizisinde tutulur. Karşılaştırmada yer değiştirmesi gerektiğinde kelimelerin kendisi değil, bu dizideki sıralar değiştirilir. En sonda kelimeler bu diziye göre bir kez yerleştirilir. Böylece her adımda bütün harfleri kopyalamak gerekmez ve iş daha az karmaşık olur.
  - C'de bir karakter dizisi başka bir diziye `=` ile doğrudan atanamaz. Harf harf kopyalanmalıdır (ya da `string.h` fonksiyonları kullanılır, bu ödevde yasaktı).
- 3. ödev: harf başlangıç dizisi
  - Sıralamadan sonra, her harfle başlayan kelime grubunun sözlükte kaçıncı satırdan başladığı ayrı bir dizide saklanır. Bu harfle başlayan kelime yoksa değer 0 olur. Örneğin F 1. satırdan, L 2. satırdan, S 3. satırdan, T 5. satırdan başlayabilir.
  - Amaç aramayı hızlandırmaktır. Aranan kelimenin ilk harfine bakılır, o harfin başlangıç satırına gidilir ve arama oradan başlar. Her karşılaştırma bir arama adımıdır.
  - Örneğin S ile başlayan iki kelime varsa ve aranan kelime ikisi de değilse, üç adımda (iki karşılaştırma ve grubun bitmesi) kelimenin olmadığına karar verilir.
- Büyük programlarda analiz
  - Uzun programlarda her değişkeni adım adım kağıt üzerinde takip etmek beklenmez.
  - Analizde farklı durumlar için verilen girdilere karşı beklenen çıktıların üretildiği gösterilmelidir.
  - IDE'lerin hata ayıklama (debug) özelliği de analiz için kullanılabilir.
- Ara sınav 1. soru: onaltılık karakter dizisinin onluk karşılığı (ekrandan, 00:25:20)
  - Akış diyagramı:
    - N ve `A[N]` okunur. `X = 1`, `toplam = 0`.
    - `I ← N || −1 || 1`: dizi sağdan sola dolaşılır.
    - `A[I] <= '9' AND A[I] >= '0'` ise `tmp = A[I] − '0'`, değilse `tmp = A[I] − 'A' + 10`.
    - `toplam = toplam + tmp * X`, `X = X * 16`.
    - Döngüden sonra `toplam` yazdırılır.
  - Analiz (`1 0 A F`):

    | I | X | toplam | A[I] | tmp |
    |---|---|---|---|---|
    | 4 | 1 | 0 | F | 15 |
    | 3 | 16 | 15 | A | 10 |
    | 2 | 256 | 175 | 0 | 0 |
    | 1 | 4096 | 175 | 1 | 1 |

    Son adımda `toplam = 175 + 1 * 4096 = 4271` olur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sınavın ilk sorusunda en sık yapılan hatalar:
  - Basamak değerini $16^0$ yerine $16^1$ ile başlatmak. Döngüye bir kez fazla girildiği için en sağdaki basamak 16 ile çarpılır.
  - Karakterlerle sayı gibi işlem yapmak. `'1'`, `'0'`, `'A'` birer karakterdir. Sayısal değerleri ancak `'0'` çıkarılarak (rakamlar için) veya `'A'` çıkarılıp 10 eklenerek (harfler için) bulunur.
  - ASCII değerlerini (48, 49, 55, 65 gibi) veya "7 çıkar" gibi hesapları kullanmak. Derste defalarca söylendiği gibi karakter sabitleri kullanılmalıdır. Bu çözümlerden puan kırıldı.
  - Her basamak için $16^k$'yı ayrı bir döngüyle yeniden hesaplamak. Çarpanı her turda 16 ile çarpmak yeterlidir.
  - `toplam`'ı sıfırlamamak ya da `X = 1` ve `toplam = 0` atamalarını döngünün içinde yapmak. Her turda sıfırlandığı için toplam kaybolur.
  - 0-9 ve A-F aralıklarını tek tek if'lerle kontrol etmek (A'ya eşit mi, B'ye eşit mi...) veya dizinin gözlerine 10, 11, ... 15 değerlerini tek tek atamak.
  - Hex rakamlarını bir diziye koyup verilen karakteri 16 değerle tek tek karşılaştırarak yerini bulmak. Çözüm yanlış değildir ve puan alır, ama istenen çözüm şekli değildir.
- Girdilerin doğru verildiği varsayıldığı için 0-9 ve A-F aralıklarının ikisini birden kontrol etmek gerekmez. Biri kontrol edilir, değilse diğeri kabul edilir.
- Sınavda sakin olmaya çalışın. Paniklemek, bilinen konularda bile hata yapmaya yol açar.
- Anlamadığınız konuları tekrar haftasında sorun. Sınav kağıtlarında görülen hatalar, konuların herkes için oturmadığını gösteriyor.

## Kısa Tekrar Notları

- Kelime karşılaştırma: harfler eşit oldukça ilerle, ilk farklı harfte karar ver.
- Kelimeleri kopyalamak yerine sıra dizisini değiştir, sonda bir kez yerleştir.
- C'de karakter dizisi `=` ile atanmaz, harf harf kopyalanır.
- Harf başlangıç dizisi: her harfin sözlükteki ilk satırı. Arama oradan başlar.
- Hex karakterin değeri: rakamsa `c − '0'`, harfse `c − 'A' + 10`.
- Basamak çarpanı 1'den başlar ve her turda 16 ile çarpılır.
- `toplam = 0` ve `X = 1` döngüden önce atanır.

## Detaylı Açıklamalar

Dersin ilk yarısında 3. ödev konuşulur. Öğrenciler kelimeleri alfabetik sıralamak için kullandıkları yöntemleri anlatır. Hoca, kelimeleri doğrudan yer değiştirmek yerine bir sıra dizisi üzerinde çalışma fikrini öne çıkarır. Ardından harf başlangıç dizisinin aramayı nasıl hızlandırdığı açıklanır. İkinci yarıda birinci ara sınavın ilk sorusunun akış diyagramı ve analizi gösterilir, sınav kağıtlarında görülen hatalar tek tek anlatılır. Kalan sürede öğrencilerin genel soruları cevaplanır.

### Sıra dizisi ile sıralama

Bir öğrencinin önerdiği yöntem şöyledir: kelimeler matriste olduğu yerde kalır. Ayrı bir tamsayı dizisi `sira[]` başlangıçta `0, 1, 2, ...` değerlerini tutar. Sıralama algoritması iki kelimeyi karşılaştırırken `kelime[sira[i]]` ve `kelime[sira[j]]` kullanır. Yer değiştirmek gerektiğinde yalnızca `sira[i]` ve `sira[j]` değiştirilir. Bir kelimeyi yer değiştirmek bütün harflerini kopyalamak demektir. Bir indisi değiştirmek ise tek bir atamadır. Sıralama bitince `sira[]` dizisi kelimelerin doğru sırasını gösterir ve kelimeler bu sıraya göre bir kez yerleştirilir.

### Sınav sorusunda tek döngü ile çarpan

Hoca, dizinin sondan başlanarak işlenmesini önerdi. Böylece çarpan $16^0 = 1$ ile başlar ve her turda 16 ile çarpılarak $16^1, 16^2, 16^3$ olur. Dizinin başından başlayan bazı çözümler, her basamak için 16'yı yeniden birkaç kez kendisiyle çarpıyordu. Bu doğru sonuç verir ama gereksiz işlem yapar ve tam puan almaz.

### Öğrencilerin derleyiciyle ilgili gözlemleri

- Bir öğrenci, sütun silme sorusunda son sütunu sıfırlamadığı hâlde Dev-C++'ta ekranda 0 gördüğünü söyledi. Hoca, ilk değer verilmeyen değişkenlerin bellekte o an ne varsa onu gösterdiğini belirtti. Ancak bu örnekte son sütunda eski değerlerin (4, 8, 12) görünmesi gerektiğini, kodu görmeden yorum yapamayacağını söyledi.
- Bir öğrenci, `string.h` eklenmeden `strcmp`'nin çalıştığını söyledi. Normalde kütüphane eklenmeden bu fonksiyon kullanılamaz ve derleme sırasında hata verilir. Hoca kodu görüp bakacağını söyledi.
- Ders sonrası kontrol: bu durum derleyicinin uyduğu C standardına bağlıdır. Eski C standartlarında (C89) bildirilmemiş bir fonksiyon çağrısı örtük olarak bildirilmiş sayılır. `strcmp` standart C kütüphanesinde bulunduğu için program bağlanır ve çalışır. Güncel GCC (15) aynı kodu varsayılan ayarlarla `implicit declaration of function 'strcmp'` hatasıyla reddederken, `-std=gnu89` ile derleyip çalıştırdı. Öğrencinin gözlemi bu yüzden olabilir. Doğru olan her durumda `#include <string.h>` yazmaktır. Bu ödevde ise `string.h` fonksiyonlarını kullanmak zaten yasaktı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
