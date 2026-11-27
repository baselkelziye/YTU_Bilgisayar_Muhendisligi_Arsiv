# Ders 4 Çalışma Özeti

## Genel Konular

- Eratosthenes Kalburu'nun kodlanması ve asal sayıların artışının izlenmesi
  - Teorik derste akış diyagramı çizilen kalbur yöntemi C ile kodlandı. İkinci akış diyagramı izlendi: yalnız 1 ve 0'lardan oluşan bir "asal mı" dizisi tutulur.
  - 2'den $n$'e kadar bütün gözler 1 (asal) diye ilklendirilir. Sonra 2'den başlayarak her göz gezilir. Göz hâlâ 1 ise, o sayının katları ($i \cdot j < n$ olduğu sürece $j$ birer artırılarak) 0 yapılır.
  - Döngü bitince 1 olan gözler asal sayılardır, 0 olan gözler asal çarpanı olan sayılardır.
  - Koda bir ekleme yapıldı: her asal sayının yanına çizgilerle bir "grafik" yazdırılarak $n$'e kadar asal sayıların nasıl arttığı izlenmek istendi. Çizgi sayısını azaltmak için bir adım (step) sabiti kullanıldı: her `step` birim tek bir çizgiyle gösterilir.
  - $n = 100$ için çıktıda 2'den 97'ye kadar asal sayılar listelendi (ekrandan, 00:10:00).
- Tam sayının karekökünün alta yuvarlanmış hali: $\lfloor \sqrt{N} \rfloor$
  - Hazır `sqrt` ya da `floor` fonksiyonu kullanmadan, verilen negatif olmayan bir $N$ tam sayısı için $\lfloor \sqrt{N} \rfloor$ bulunmak istendi.
  - Çözüm adım adım iyileştirildi: önce bütün karelerin bir dizide tutulması, sonra yalnız "şimdiki ve önceki" değerin tutulması, en son tek bir değişkenle çözüm.
  - Son akış: $i \leftarrow 0$; $i \cdot i \le N$ olduğu sürece $i \leftarrow i + 1$; döngüden çıkınca $i \leftarrow i - 1$ ve $i$ yazdırılır (ekrandan, 00:25:00).
- Sıralı iki dizinin kesişim kümesi
  - Küçükten büyüğe sıralı iki dizinin kesişim kümesi bulunacak. Küme olduğu için aynı eleman bir kez yazılmalıdır.
  - Örnek: $a = [2, 5, 5, 5]$, $b = [2, 2, 3, 5, 5, 7]$ için $[2, 5, 5]$ yanlış, $[2, 5]$ doğru cevaptır (ekrandan, 00:35:00).
  - Çözüm iki indisle dizileri tek yönde gezmektir. Küçük olan elemanın indisi artırılır. Eşitlik varsa eleman yazdırılır ve tekrar eden eşit elemanlar atlanır. Dizilerden biri bitince durulur.
- Düşünme problemleri (derste çözülmedi)
  - 1 ile 1000 arasında rastgele üretilen $n$ sayı içinde yalnız bir kez geçen (tekrar etmeyen) sayıların sayısı. Dizi sıralanmadan çözülmesi istendi.
  - Kilitli dolap problemi: $n$ dolap, $n$ öğrenci; $k$. öğrenci $k$'nin katı olan dolapların durumunu tersine çevirir. Sonunda hangi dolapların açık kalacağı soruldu.

## Hocanın Özellikle Vurguladığı Kısımlar

- Önce basit bir temel çözüm, sonra iyileştirme
  - Problemi çözerken önce çalışan basit bir çözümden yola çıkılmalıdır. Sonra "daha az yer kaplar mı, bu `if`'ten kurtulabilir miyim, bu döngüyü azaltabilir miyim, hepsine bakmam gerekiyor mu" diye sorularak çözüm iyileştirilmelidir.
- Uç nokta analizi: `<` mü, `<=` mü?
  - Karekök örneğinde koşul $i \cdot i < N$ yazılırsa tam kare sayılarda (ör. $N = 9$, $N = 16$) sonuç yanlış çıkar. Koşulda eşitlik bulunursa döngü sonrasında ek bir kontrol gerekmez, her zaman $i - 1$ doğru cevaptır.
  - Kesişim örneğinde de indis artırımları, dizi sonları ve tekrar sayıları uç noktalardır; bunlar mutlaka test edilmelidir.
- Algoritmayı kod yapısıyla değil yaklaşımla anlatmak
  - "Bir `for`, içine bir `while` koyarım" demek yerine "şu diziyi şu gözden başlayarak şöyle gezerim, şu sırayla şunlara bakarım" diye bir çözüm yaklaşımı anlatmak daha doğrudur.
- Verilen bilgiyi kullanmak
  - Kesişim probleminde dizilerin sıralı olduğu bilindiği için başa dönüp elemanlara tekrar tekrar bakmaya gerek yoktur.
- Yer ile işlem arasındaki denge
  - Karekök döngüsünde her adımda $i \cdot i$ yeniden hesaplanır. Kareyi ayrı bir değişkende tutmak bir çarpmayı kurtarır ama bir değişken daha gerektirir. C'de bunun verimi etkileyip etkilemediğinin kesin cevabı yoktur; ortama, derleyiciye ve optimizasyon ayarlarına bağlıdır.

## Kısa Tekrar Notları

- Eratosthenes Kalburu: bütün gözleri 1 yap, her asal $i$ için $i \cdot j < n$ olan katları 0 yap; kalan 1'ler asaldır.
- $n = 10\,000$'den küçük en büyük asal sayı 9973'tür.
- $\lfloor \sqrt{N} \rfloor$: `while (i*i<=N) i++;` sonra `--i`.
- Koşuldaki `<=` tam karelerde doğru sonucu garanti eder.
- Sıralı iki dizinin kesişimi: iki indis, küçük olanı ilerlet, eşitse yazdır ve tekrarları atla, bir dizi bitince dur.
- Kesişim kümesinde aynı eleman bir kez yazılır: $[2, 5]$, $[2, 5, 5]$ değil.
- Önce basit çözüm, sonra adım adım iyileştirme; uç noktaları test et.

## Detaylı Açıklamalar

- **Kalbur kodu ve çizgi grafiği:** Kodda $n$ ve adım sayısı sabit olarak tanımlandı. İlklendirmeden sonra dış döngü 2'den $n$'e kadar gider; göz 1 ise iç döngü $j$'yi birer artırarak $i \cdot j$ gözlerini 0 yapar. Örneğin $i = 2$ iken 4, 6, 8, 10, 12, ... silinir; $i = 3$ iken 6 zaten silinmiş olsa da tekrar kontrol yapılmadan yeniden 0 yapılır. Asal sayılar yazdırılırken yanına çizgi eklendi. $n = 100$ çıktısı yaklaşık 0,15 saniyede bitti (ekrandan, 00:10:00). $n = 1000$ için çizgiler ekrana sığmayınca adım 10 yapıldı; $n = 10\,000$ için adım 100 seçildi ve en büyük asal 9973 olarak görüldü. Hoca süreleri 0,14 s, 0,51 s ve 3,7 s olarak okudu ve bu tür denemelerle çalışma süresinin $n$'e göre nasıl değiştiğinin incelenebileceğini söyledi.
  - Bir öğrenci 5 için 5 çizgi çıktığını, oysa 5'e kadar 5 asal sayı olmadığını fark etti. Hoca kodda asal sayının değeri kadar çizgi çizdirdiğini kabul etti; doğrusu için asal sayıları sayan ayrı bir sayaç gerektiğini söyledi ve düzeltmeyi öğrencilere bıraktı. Ekrandaki çıktıda da 2'nin yanında 2, 7'nin yanında 7 çizgi vardır (ekrandan, 00:10:00).
  - Ders sonrası not: Hoca çıktıya bakarak asal sayı sayısının doğrusal arttığını söyledi. Çizgiler asal sayının kendi değeri kadar çizildiği için çıktı doğrusal görünüyordu. Asal sayı sayısı büyük olasılıkla $n / \ln n$ gibi doğrusaldan biraz yavaş artar: 100'e kadar 25, 1000'e kadar 168, 10 000'e kadar 1229 asal vardır (python ile sayıldı).
- **$\lfloor \sqrt{N} \rfloor$ algoritmasının gelişimi:** İlk öğrenci önerisi $N$'e kadar sayıların karelerini bir dizide tutup $N$'i geçtiği yerde durmaktı; hoca bunu verimsiz ama kabul edilebilir bir başlangıç (baseline) saydı. İkinci öneri dizisiz, yalnız şimdiki ve önceki değeri tutmaktı. Hoca bir adım daha ileri giderek önceki değerin zaten $i - 1$ olduğunu, bu yüzden tek değişkenin yettiğini gösterdi. Akış diyagramında `if` yoktur: tek koşul, tek döngü, tek atama ve sonda tek çıkarma. $N = 10$ için $i$ sırayla 0, 1, 2, 3 olur (kareleri 0, 1, 4, 9 hep $\le 10$); $i = 4$ iken $16 > 10$ olduğu için döngüden çıkılır ve $i - 1 = 3$ yazdırılır. $N = 16$ için $4 \cdot 4 = 16 \le 16$ olduğundan döngüye bir kez daha girilir, $i = 5$ olur, sonuç $5 - 1 = 4$'tür. $i$, $N = 0$ olabileceği için 0'dan başlatılır.
  - Kod (ekrandan, 00:30:00):

```c
#include <stdio.h>

#define N 10

int main(void){
    int i=0;

    while (i*i<=N) i++;

    printf("%d\n",--i);

    return 0;
}
```

  - Hoca kodu daha sonra $N = 16$ ile çalıştırıp 4 sonucunu gördü. Kod `gcc -Wall` ile derlendi; $N$ = 0, 1, 9, 10, 15, 16, 17, 99, 100 için sırasıyla 0, 1, 3, 3, 3, 4, 4, 9, 10 verdi.
- **Kesişim algoritması:** Her iki dizide de ilk elemandan başlanır. $a[i] < b[j]$ ise $i$, $b[j] < a[i]$ ise $j$ artırılır. İkisi de olmazsa elemanlar eşittir; eleman yazdırılır ve eşitlik bozulana kadar indisler ilerletilir. Örnekte önce 2 = 2 yakalanır ve 2 yazdırılır. Sonra 5 ile 2, 5 ile 3 karşılaştırılırken $b$'nin indisi ilerler; 5 = 5 bulununca 5 yazdırılır ve tekrar eden 5'ler atlanır. $a$ bitince durulur. Hocanın derste gösterdiği kodda tekrarları atlayan kısım bilerek tam kontrol edilmeden bırakıldı; öğrencilerden bu kodu bozan bir örnek bulmaları istendi. Bir öğrenci, eşit elemanlar dizinin sonuna kadar sürerse dizi dışına taşma (index out of bounds) olabileceğini söyledi; hoca hepsi aynı olursa böyle bir durum olabileceğini kabul etti, denemede program hata vermeden bitti.
  <!-- BELİRSİZ: Hocanın kesişim kodu ve sohbete yazdığı kod parçası karelerde görünmüyor; kodun satırları nota alınamadı. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
