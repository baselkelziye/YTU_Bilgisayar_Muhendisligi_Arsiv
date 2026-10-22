# Ders 27 Çalışma Özeti

## Genel Konular

- Dönem projesiyle ilgili sorular
  - Rapordaki "çözüm" kısmında algoritma değil, kullanılan yaklaşımlar anlatılır: tahtanın nasıl oluşturulduğu, kontrollerin nasıl yapıldığı, hangi tasarımın ne avantaj sağladığı veya neyin yeterince verimli olmadığı. Bir uzunluk sınırı yoktur.
  - Struct ve pointer kullanılabilir. Ancak öğrenci, kendi öğrenmediği bir bilgiyi kullanırsa onunla ilgili sorulara da hazır olmalıdır. Başkasından yardım alarak eklenen yapılar kabul edilmez.
  - Fonksiyon kullananlar için: değişkenler fonksiyonların içinde (yerel, local) tanımlanmalıdır. Fonksiyonların dışında tanımlanan global değişkenler bu ödevde kullanılmamalıdır. Bir fonksiyonda tanımlanan değişken yalnızca orada geçerlidir. Değişkenler diğer fonksiyonlara parametre olarak iki şekilde aktarılır: adresi gönderilerek ya da değerinin bir kopyası gönderilerek. Bir fonksiyon yalnızca bir değer döndürebilir.
  - Tahtanın ekranda gösterimi için öğrencilerin yaklaşımları: tamsayı matrisi tutup yazdırırken değere göre karakter seçmek, her hücreyi ekranda birden fazla karakter genişliğinde yazdırmak, matriste indis tutup etiketleri ayrı bir karakter matrisinde saklamak.
  - Fikir alışverişi serbesttir, ama kod paylaşımı yapılmamalıdır. Benzer kod tespit edilirse iki taraf da sıfır alır.
- Canlı kodlama 1: dizideki en küçük ve en büyük eleman
  - Eleman sayısı `int`, veri seti `float veriSeti[100]` olarak tanımlanır. Elemanlar `scanf("%f", &veriSeti[i])` ile tek tek okunur. `veriSeti[n]` ya da `veriSeti[elemanSayisi]` gibi tek bir göze okumak sık yapılan bir hatadır.
  - Okurken kullanıcıya kaçıncı elemanı girdiği de gösterilebilir: `printf("%d. elemani giriniz", i+1);`
  - İlk eleman hem en küçük hem en büyük kabul edilir: `min = max = veriSeti[0]`. Döngü `i = 1`'den başlar, çünkü ilk eleman zaten atanmıştır.
  - `veriSeti[i] < min` ise `min = veriSeti[i]`. Değilse `veriSeti[i] > max` ise `max = veriSeti[i]`. Bir eleman en küçükse aynı zamanda en büyük olamayacağı için ikinci kontrol `else` ile yazılır.
  - Veri seti float ise `min` ve `max` da float tanımlanmalıdır. Bu derste önce int tanımlandıkları için yanlış sonuç alındı.
  - Değer yerine yer (indis) aranırsa `min` ve `max` değişkenlerine gerek kalmaz: `minYer = maxYer = 0`, `veriSeti[i] < veriSeti[minYer]` ise `minYer = i`. Değer gerektiğinde `veriSeti[minYer]` kullanılır.
  - Yer kullanıcıya gösterilirken dizinin 0'dan başladığı unutulmamalı ve `minYer + 1` yazdırılmalıdır.
  - Bütün diziye bir kez bakıldığı için bu iş N adımda tamamlanır.
- Formatlı yazdırma
  - `%.2f` gibi biçimlerde noktadan sonraki sayı, kesirli kısmın kaç basamak yazdırılacağını belirler. Yazdırılırken yuvarlama yapılır: örneğin 5.99 tam sayıya yuvarlanınca 6, −99.99 da −100 olur.
- Medyan (ortanca)
  - Medyan, küçükten büyüğe sıralanmış bir veri grubunda en ortadaki elemandır.
  - Karışık verilen bir veri setinin medyanı için önce sıralama yapılır. Eleman sayısı çiftse ortadaki iki elemanın ortalaması alınabilir ya da ikisinden biri seçilebilir. Bilgisayar bilimlerinde bu detay hesaba katılmadan da çalışılabilir.
  - Önemli nokta: medyanı bulmak için dizinin tamamını sıralamaya gerek yoktur. Sıralama, ortadaki elemana kadar yapılmalıdır. Bir milyon elemanlı bir dizide yalnızca 500 bin elemanı sıralamak yeterlidir.
  - Medyanın kullanım amacı: standart sapması yüksek verilerde ortalama, verinin merkezini iyi göstermez. Örneğin değerlerin çoğu 22-23 civarındayken 0 ve 100 gibi uç değerler ortalamayı 30-35'e çeker. Medyan, verinin gerçekten yoğunlaştığı noktayı daha doğru gösterir.
- Canlı kodlama 2: karakter dizisinin medyanı
  - Veri seti `char` tipindedir ve `%c` ile okunur.
  - Selection sort yalnızca medyan sınırına kadar çalıştırılır: dış döngünün her turunda kalanların en küçüğü bulunur (`min` indisi) ve `i`. konuma yerleştirilir.
  - Yer değiştirmede önce `tmp = veriSeti[i]` alınmalıdır. Hoca bilerek `tmp = veriSeti[min]` yazdı. Bu durumda `veriSeti[i]`'nin değeri kaybolur.
  - `scanf("%c", ...)` Enter tuşunu da bir karakter olarak okur. Bu yüzden `%c`'den önce bir boşluk konur: `scanf(" %c", &veriSeti[i]);` Alternatif olarak karakterlerin tamamı `%s` ile tek seferde okunabilir.
  - Sınır, döngü koşulunun içinde her turda hesaplanmamalıdır. Kötü bir derleyici `(elemanSayisi + 1) / 2` işlemini her turda yeniden yapar. Bunun yerine bir değişkene bir kez hesaplanır: `medyanSinir = (elemanSayisi + 1) / 2`.
  - `%d` ile yazdırılırsa karakterin ASCII karşılığı, `%c` ile karakterin kendisi görünür.
  - Karakterlerde ortadaki iki elemanın ortalamasını almak anlamlı bir sonuç vermez. Bu yüzden çift sayıda elemanda ortadaki elemanlardan biri alınır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bir algoritma doğru çalışsa bile gereksiz iş yapıyorsa sınavda puan farkı olur. Örneğin medyan için tüm diziyi sıralayan ile ortasına kadar sıralayan arasında puan farkı olur.
- İlk akla gelen basit çözümler genelde kaba kuvvet (brute force) yaklaşımlardır. Bazıları zaten verimlidir, ama bazılarının iyileştirilmesi gerekir. Problemin ne istediğini, girdiyi ve çıktıyı doğru tespit edip ona göre çözüm üretin.
- C büyük-küçük harfe duyarlıdır. `maxYer` ile `maxyer` farklı değişkenlerdir.
- Kodda yapılan her değişiklikten sonra kod yeniden derlenmelidir. Derlenmezse değişiklik programa yansımaz.
- Tek işlemli bloklarda süslü parantez zorunlu değildir, ama kullanmak her zaman daha garantidir.
- C bu dersin konusu değildir. Derste gösterilen temel yapıları (if, for, while, atama) kendi çalışmanızda algoritmaları koda dökerek pekiştirmeniz beklenir. Gelecek yıllarda uygulama saatlerinde daha çok kod yazılacak.

## Kısa Tekrar Notları

- Min/max: ilk elemanla başla, `i = 1`'den itibaren karşılaştır. Küçük değilse büyük mü diye bak (`else if`).
- Yer arıyorsan değer değişkenine gerek yok: `veriSeti[minYer]`.
- Kullanıcıya yer gösterirken `+1`.
- `float` veri için `min` ve `max` da `float` olmalıdır.
- `%.2f`: noktadan sonra 2 basamak, yuvarlanarak.
- Medyan: sıralı dizinin ortası. Yalnızca ortaya kadar sırala.
- `medyanSinir = (n+1)/2`. Döngü `i < medyanSinir`, medyan `veriSeti[medyanSinir−1]`.
- `scanf(" %c", ...)` — boşluk Enter'ı atlar.
- `%d` ASCII değeri, `%c` karakteri yazdırır.

## Detaylı Açıklamalar

Dersin ilk bölümünde dönem projesi raporuyla ve kodun yapısıyla ilgili sorular cevaplanır. Ardından OnlineGDB üzerinde iki program birlikte yazılır: bir veri setinin en küçük ve en büyük elemanını (ve yerini) bulan program ve bir karakter dizisinin medyanını bulan program. Hoca, kodu yazarken bilerek bazı hatalar yapar ve öğrencilerle birlikte bulur.

### Medyan sınırının bulunması

Medyan programında sınır birkaç denemeyle bulundu:

1. Önce selection sort bütün dizi için yazıldı ve `veriSeti[elemanSayisi/2]` yazdırıldı. Doğru sonuç verdi, ama bütün dizi sıralanıyordu.
2. Dış döngü `elemanSayisi/2`'ye kadar çalıştırıldı. 5 elemanda tam sayı bölmesi 2 verdiği için ortadaki eleman (3. eleman) sıralanmadı ve yanlış sonuç alındı.
3. Sınır `(elemanSayisi+1)/2` yapıldı ve bir değişkene alındı. 5 elemanda doğru, 6 elemanda yanlış sonuç alındı.
4. Sonunda iki tutarlı seçenek bulundu: ya dış döngü `i <= medyanSinir` olur ve `veriSeti[medyanSinir]` yazdırılır, ya da dış döngü `i < medyanSinir` olur ve `veriSeti[medyanSinir−1]` yazdırılır. Önemli olan, yazdırılacak gözün sıralamaya dahil edilmesidir. Sıralanmayan bir göz o an orada ne varsa onu gösterir.

Çift sayıda elemanda (ör. 6) bu yöntem 3. elemanı verir. 4. eleman da medyan olarak kabul edilebilir.

### Kontrol

Ders sonrasında iki program son hâlleriyle derlendi (`gcc -Wall`).

- Min/max programı `-22.22 -99.99 5.99 3.1 0.01` için en küçük elemanı −99.99 (2. sırada), en büyük elemanı 5.99 (3. sırada) olarak buldu.
- Medyan programı 1 ile 12 arasında eleman içeren 300 rastgele harf dizisinde, sıralanmış dizinin $\lceil n/2 \rceil$. elemanıyla aynı sonucu verdi.

```c
#include <stdio.h>

int main()
{
    int elemanSayisi,i,j,min,medyanSinir;
    char veriSeti[100],tmp;

    scanf("%d",&elemanSayisi);
    for(i=0;i<elemanSayisi;i++)
        scanf(" %c",&veriSeti[i]);          /* %c önündeki boşluk Enter'ı atlar */

    medyanSinir=(elemanSayisi+1)/2;          /* döngü koşulunda her turda hesaplanmasın */
    for(i=0;i<medyanSinir;i++)               /* selection sort yalnızca ortaya kadar */
    {
        min=i;
        for(j=i+1;j<elemanSayisi;j++)
            if(veriSeti[j]<veriSeti[min])
                min=j;
        tmp=veriSeti[i];
        veriSeti[i]=veriSeti[min];
        veriSeti[min]=tmp;
    }
    printf("Medyan: %c\n",veriSeti[medyanSinir-1]);
    return 0;
}
```

### Ders sonrası not

Derste `%3.2f` biçimindeki 3'ün "noktadan önceki kısım için ayrılan alan" olduğu söylendi. C'de bu sayı, sayının nokta ve kesirli kısım dahil toplam en az kaç karakter genişliğinde yazdırılacağını belirtir. Örneğin `%7.2f` ile 3.14159, başına üç boşluk eklenerek `   3.14` olarak yazdırılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
