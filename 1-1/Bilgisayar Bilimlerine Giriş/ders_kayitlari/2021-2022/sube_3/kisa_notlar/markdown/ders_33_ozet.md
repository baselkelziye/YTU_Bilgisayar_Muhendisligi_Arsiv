# Ders 33 Çalışma Özeti

## Genel Konular

- Sıralama probleminin tanımı
  - Sıralama, aynı türden nesnelerden oluşan bir koleksiyonu büyüklük-küçüklük açısından mantıksal bir düzene sokmaktır (ekrandan, 00:10:00).
  - Girdi: $\{a_1, a_2, \dots, a_n\}$. Çıktı: girdinin öyle bir $\{a_1', a_2', \dots, a_n'\}$ permütasyonu ki $a_1' \le a_2' \le \dots \le a_n'$ olsun.
  - Örnek girdi `8 2 4 4 4 9 3 6` (üç 4 farklı renklerle ayırt edilmiş). `2 3 4 4 4 6 8 9` çıktısı, tekrar eden 4'ler hangi sırada çıkarsa çıksın, koşulu sağladığı için geçerli bir sıralama çıktısıdır (ekrandan, 00:10:00).
  - Kullanım alanları: işlem (transaction) işleme, kombinatoryal optimizasyon, astrofizik, moleküler dinamik, dilbilim, genbilim, hava tahmini. Sıralı girdiyle çalışacak her algoritmada ilk iş sıralamaktır.
  - Temel bir problem olsa da çalışmalar sürüyor: Quicksort, 20. yüzyılın en iyi 10 algoritmasından biri seçilmiştir (ekrandan, 00:10:00).
- Sıralama algoritmalarını değerlendirme ölçütleri (ekrandan, 00:15:00)
  - Performans: çalışma zamanı; karşılaştırma ve değiştirme (swap) sayısı (değiştirme yoksa dizi erişim sayısı).
  - Ekstra bellek: yerinde sıralama (in-place; raftaki kitapları rafta sıralamak) ya da harici bellek alanına sıralama (out-of-place; kitapları yere döküp sıralamak).
  - Tekrar eden değerler: istikrarlı (stable) algoritma tekrar eden değerleri girdideki sırayla çıktıya koyar; istikrarsız (unstable) algoritmada bu garanti yoktur.
  - Tek bir doğru yoktur: bellek, karşılaştırma ya da swap maliyetine ve sıranın önemli olup olmamasına göre algoritma seçilir.
- Bubble Sort (kabarcık sıralama)
  - Komşu elemanlar karşılaştırılır; sıra yanlışsa yer değiştirilir. Her dış döngü adımında kalan elemanların en büyüğü dizinin sonuna doğru "kabarcık gibi" taşınır.
  - İç döngü `n-1-i`'ye kadar gider: her dış adımda sondaki yerleşmiş bir eleman daha dışarıda kalır. Dış döngü `n-1` adımdır, çünkü tek elemanlık dizi zaten sıralıdır.
  - On elemanlı örnek `8 5 2 6 9 3 1 4 0 7` adım adım sıralandı (ekrandan, 00:30:00-00:40:00).
  - Kod OnlineGDB'de yazıldı ve çalıştırıldı (ekrandan, 00:45:00).
- Karşılaştırma sayarak sıralama (ekstra dizi ile)
  - Her elemanın kaç elemandan büyük olduğu sayılır; sayı + 1, elemanın ikinci dizideki konumudur. Swap yapılmaz ama ikinci bir $n$ elemanlık dizi gerekir (ekrandan, 00:55:00).
- Selection Sort (seçmeli sıralama)
  - Her iterasyonda kalan elemanların en küçüğünün indisi bulunur ve iterasyonun sonunda tek bir swap ile baştaki göze yerleştirilir (ekrandan, 01:00:00).
  - On elemanlı örnek `8 6 2 5 9 3 1 4 0 7` minimum indis izlenerek sıralandı (ekrandan, 01:05:00-01:10:00). Kod OnlineGDB'de yazıldı (ekrandan, 01:15:00).
- Konu dışı ek yöntemler (kısaca)
  - Insertion Sort (eklemeli sıralama): sıralı alt diziye her yeni eleman kaydırılarak araya sokulur. Neredeyse sıralı girdide çok az işlem yapar.
  - Shell Sort: dizi aralıklı parçalara bölünüp parçalar kendi içinde sıralanır, sonra son adımda insertion sort uygulanır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Tek bir doğru algoritma yoktur
  - Bellek pahalıysa yerinde sıralama, swap pahalıysa swap sayısı az olan, sıra önemliyse istikrarlı algoritma seçilir. Bu ölçütler birlikte düşünülmelidir.
- Bubble Sort en basit ama verimsiz yöntemdir
  - En kötü durum tersten sıralı dizidir. Yer değiştirme yapılsın ya da yapılmasın `if` karşılaştırması her adımda çalışır. Tek artısı yerinde çalışması ve yalnız bir geçici değişkene ihtiyaç duymasıdır.
- Selection Sort'un üstünlüğü swap sayısıdır
  - Karşılaştırma sayısı yaklaşık $n^2/2$ olarak kalır, ama swap yalnız dış döngü kadar ($n-1$) yapılır.
- Girdinin doğası önemlidir
  - Neredeyse sıralı girdide insertion sort çok az kaydırma yapar. Farklı yöntemler arka arkaya (hibrit) kullanılabilir.
- Basit algoritmalar çoğu zaman yeterlidir
  - Büyük sistemler bile çoğu zaman kendini kanıtlamış basit algoritmaları kullanır. Örneğin hocaya göre Java'daki `String.indexOf` kaba kuvvetle (brute force) çalışır.

## Kısa Tekrar Notları

- Sıralama çıktısı, girdinin $a_1' \le a_2' \le \dots \le a_n'$ koşulunu sağlayan bir permütasyonudur.
- Ölçütler: çalışma zamanı, karşılaştırma sayısı, swap sayısı, ekstra bellek (in-place / out-of-place), istikrar (stable / unstable).
- Bubble Sort: `for(i=0;i<n-1;i++) for(j=0;j<n-1-i;j++) if(a[j]>a[j+1]) swap`.
- Bubble Sort her dış adımda kalanların en büyüğünü sona taşır; en kötü durum tersten sıralı dizidir.
- Karşılaştırma sayarak sıralama: konum = (kendinden küçük eleman sayısı) + 1; swap yok, ekstra dizi var.
- Selection Sort: `mi = i`; `j = i+1 .. n-1` içinde `a[j] < a[mi]` ise `mi = j`; iç döngüden sonra tek swap.
- Selection Sort: yaklaşık $n^2/2$ karşılaştırma, $n-1$ swap.
- Insertion Sort neredeyse sıralı girdide iyidir; Shell Sort aralıklı parçaları önceden sıralayıp son adımda insertion sort uygular.

## Detaylı Açıklamalar

- Sıralama problemi ve geçerli çıktı
  - Sıralama algoritmasının çıktısı girdinin bir permütasyonudur; girdideki bütün değerler aynı tekrar sayısıyla çıktıda yer almalı ve çıktı küçükten büyüğe (küçük eşit) sıralı olmalıdır. Slayttaki örnekte üç 4 siyah, kırmızı ve gri renkle ayırt edilmiştir. Çıktıda bunlar girdideki sırayla (siyah, kırmızı, gri) çıkabilir ya da karışık çıkabilir; her iki durumda da sıralama koşulu sağlanır. Fark yalnız istikrar ölçütünde ortaya çıkar: aynı notu almış öğrencilerin geliş sırası korunmak isteniyorsa istikrarlı bir algoritma seçilmelidir.
- Değerlendirme ölçütleri
  - Çalışma zamanı ilk ölçüttür, ama tek başına yeterli değildir. Bazı mimarilerde karar (`if`) işlemi pahalıdır; o zaman karşılaştırma sayısı az olan algoritma istenir. Bellek erişimi pahalıysa her swap bir okuma, yazma ve geçici değişken kullanımı demek olduğundan swap sayısı az olan algoritma tercih edilir. Gömülü sistemlerde bellek kısıtlıdır, diziyi kopyalayıp ikinci dizi üzerinde çalışmak mümkün olmayabilir; bu durumda yerinde sıralama gerekir. Hoca bunu raf benzetmesiyle anlattı: yerinde sıralama kitapları raftan indirmeden tek tek yer değiştirerek dizmek, harici bellekle sıralama ise kitapları yere döküp sonra sırayla rafa dizmektir.
- Bubble Sort'un mantığı
  - Önce `8 2 7 1 6 4 3` dizisi üzerinde sezgisel olarak düşünüldü: 8 ile 2 karşılaştırılıp yer değiştirildi (geçici değişkenle), ardından 8 sırayla 7, 1, 6, 4, 3 ile karşılaştırılıp her seferinde sağa taşındı ve dizinin sonuna ulaştı (ekrandan, 00:25:00). Bu işlem kalan elemanlar için tekrarlanır.
  - Algoritmada dış döngü `i`, iç döngü `j`'dir. İç döngü `j` ile `j+1` gözlerini karşılaştırır, `j+1`'deki eleman küçükse swap yapar. `n-1-i` sınırı, her dış adımda sona yerleşmiş elemanların tekrar karşılaştırılmamasını sağlar.
  - Adı, büyük elemanın gazoz kabarcıkları gibi dizinin başından sonuna doğru "fokurdayarak" yükselmesinden gelir.
- Bubble Sort örneği (ekrandan, 00:30:00-00:40:00)
  - Girdi (indis 0-9): `8 5 2 6 9 3 1 4 0 7`.
  - Her dış adımın (`i`) sonundaki dizi: `i=0`: `5 2 6 8 3 1 4 0 7 9`; `i=1`: `2 5 6 3 1 4 0 7 8 9`; `i=2`: `2 5 3 1 4 0 6 7 8 9`; `i=3`: `2 3 1 4 0 5 6 7 8 9`; `i=4`: `2 1 3 0 4 5 6 7 8 9`; `i=5`: `1 2 0 3 4 5 6 7 8 9`; `i=6`: `1 0 2 3 4 5 6 7 8 9`; `i=7`: `0 1 2 3 4 5 6 7 8 9`; `i=8`: değişiklik yok.
  - `i=0` adımında 8, 9'a kadar taşınır; 9'la karşılaşınca kabarcık 9 olur ve 9 sona gider. Dizi `i=7`'de sıralı hâle gelir, ama algoritma bunu bilmediği için `i=8` adımında da karşılaştırma yapar.
- Bubble Sort C kodu (ekrandan, 00:45:00)

  ```c
  #include <stdio.h>
  #define n 5

  int main()
  {
      int a[n]={81, 23, 16, 4, 55};
      int i,j, tmp;

      for(i=0; i<n-1; i++)
          for(j=0; j<n-1-i; j++)
              if (a[j]>a[j+1]){
                  tmp = a[j];
                  a[j]=a[j+1];
                  a[j+1]=tmp;
              }

      for (i=0;i<n;i++)
          printf("%d ",a[i]);
      printf("\n");

      return 0;
  }
  ```

  - Çıktı: `4 16 23 55 81`. İlk denemede dizi `8 2 6 4 5` idi ve çıktı `2 4 5 6 8` oldu. Kod `gcc -Wall` ile derlenip iki dizi için de çalıştırıldı; çıktılar aynıdır.
- Bubble Sort'un en kötü durumu ve iyileştirme önerisi
  - En kötü durum tersten sıralı dizidir (örnek: `88 77 66 55 44`). Her karşılaştırmada swap gerekir; hoca bunu "kabaca $n \times n$ atama" diye ifade etti.
  - Ders sonrası not: Hoca kabaca $n \times n$ dedi; tersten sıralı dizide swap sayısı tam olarak $n(n-1)/2$'dir ($n=5$ için 10). Mertebe yine $n^2$'dir.
  - Bir öğrenci dış `for` yerine `do-while` ile bir bayrak değişkeni kullanmayı önerdi: bir geçişte hiç swap olmazsa durulur. Hoca, sıralı girdide bunun işe yaradığını, ama tersten sıralı girdide her geçişte fazladan bir kontrol daha getireceğini belirtti.
- Karşılaştırma sayarak sıralama (ekrandan, 00:55:00)
  - A = `8 6 9 1 3 7` (konum 1-6). 8, dört elemandan (6, 1, 3, 7) büyüktür; B dizisinin 5. gözüne yazılır. 6 iki elemandan büyük → 3. göz. 9 beş elemandan büyük → 6. göz. 1 hiçbirinden büyük değil → 1. göz. 3 bir elemandan büyük → 2. göz. 7 üç elemandan büyük → 4. göz. Sonuç B = `1 3 6 7 8 9`.
  - Swap yapılmaz; swap pahalıysa Bubble Sort'tan iyi çalışır, ama ikinci dizi için bellek gerekir. Hoca bu yönteme "sort with counting / linear sort with counting" dedi.
  - Ders sonrası not: Bu yöntemde her eleman bütün elemanlarla karşılaştırıldığı için karşılaştırma sayısı büyük olasılıkla $n^2$ mertebesindedir; "linear" adı karşılaştırma sayısını değil, büyük olasılıkla ikinci diziye doğrudan yazmayı anlatır. Ayrıca eşit değerler varsa aynı konum hesaplanacağı için ek bir kural gerekir.
- Selection Sort algoritması (ekrandan, 01:00:00)
  - Slayttaki sözde kod:

  ```text
  for i <- 0 to n-1 do
     min <- i
     for j <- (i + 1) to n do
        if A[j] < A[min]
           min <- j
     tmp <- A[i]
     A[i] <- A[min]
     A[min] <- tmp
  ```

  - Akış diyagramı (tahtaya çizilen): `i = 1 .. N-1` döngüsü → `mi = i` → `j = i+1 .. N` döngüsü → karar `a[j] < a[mi]`; doğruysa `mi = j`, yanlışsa bir şey yapılmaz → iç döngü bitince swap → dış döngüye dönülür → sonunda yazdır ve dur.
  - Swap işlemi hızlı dönen iç döngünün dışına taşınmıştır. Karşılaştırmalar matrisin köşegeninin bir tarafı gibi üçgen biçimindedir: toplam yaklaşık $n^2/2$ karşılaştırma, $n-1$ swap.
- Selection Sort örneği (ekrandan, 01:05:00-01:10:00)
  - Girdi: `8 6 2 5 9 3 1 4 0 7`.
  - `i=0`: min indis 0 → 1 → 2 → 6 → 8 olur; 0. ve 8. gözler yer değiştirir: `0 6 2 5 9 3 1 4 8 7`.
  - `i=1`: min indis 6; `0 1 2 5 9 3 6 4 8 7`. `i=2`: min indis 2, kendisiyle yer değiştirir.
  - `i=3`: min indis 5; `0 1 2 3 9 5 6 4 8 7`. `i=4`: min indis 7; `0 1 2 3 4 5 6 9 8 7`.
  - `i=5` ve `i=6`: değişiklik yok. `i=7`: min indis 9; `0 1 2 3 4 5 6 7 8 9`. `i=8`: değişiklik yok. Son eleman tek kaldığı için `n-1` adım yeterlidir.
- Selection Sort C kodu (ekrandan, 01:15:00)

  ```c
  #include <stdio.h>
  #define n 5

  int main()
  {
      int a[n]={9, 1, 5, 2, 8};
      int i,j, mi, tmp;

      for(i=0; i<n-1; i++){
          mi = i;
          for(j=i+1; j<n; j++){
              if(a[j] < a[mi])
                  mi = j;
          }
          //swap
          tmp = a[mi];
          a[mi] = a[i];
          a[i] = tmp;
      }

      for (i=0;i<n;i++)
          printf("%d ",a[i]);
      printf("\n");

      return 0;
  }
  ```

  - Karede swap'ın son satırı (`a[i] = tmp;`) henüz yazılmamıştı; satır anlatıma göre tamamlandı. Kod `gcc -Wall` ile derlenip çalıştırıldı; çıktı `1 2 5 8 9`, derste söylenen çıktıyla aynıdır.
  - Eşit elemanlar varsa koşul `<` olduğu için minimum indis değişmez; hoca bunu tekrar eden 55 değerleriyle ve minimum indisleri yazdırarak gösterdi. <!-- BELİRSİZ: Bu denemedeki dizinin tam değerleri karede görünmüyor. -->
- Insertion Sort (konu dışı, ekrandan, 01:20:00)
  - `8 6 2 5 9 3 1 4 0 7` üzerinde: tek eleman (8) zaten sıralıdır; 6 gelir → `6 8`; 2 kaydırılarak başa → `2 6 8`; 5 → `2 5 6 8`; 9 hiç kaydırma gerektirmez; 3 ve 1 çok kaydırma gerektirir; 4, 9-8-6-5'i geçip 3'te durur; 0 en kötü durumdur, bütün elemanları geçer; 7 yalnız 9 ve 8'i geçer.
  - Girdi neredeyse sıralıysa kaydırma sayısı çok azalır; hoca bu yüzden girdinin doğasına göre bu yöntemin seçilebileceğini söyledi.
- Shell Sort fikri (konu dışı, ekrandan, 01:25:00)
  - Aynı dizi üçer aralıklı parçalara ayrıldı: 0, 3, 6, 9. gözler `8 5 1 7` → `1 5 7 8`; 1, 4, 7. gözler `6 9 4` → `4 6 9`; 2, 5, 8. gözler `2 3 0` → `0 2 3`. Yeni dizi `1 4 0 5 6 2 7 9 3 8` oldu (ekrandan, 01:30:00).
  - Bu dizi insertion sort ile toplam 11 kaydırmayla sıralanır (0 için 2, 2 için 3, 3 için 5, 8 için 1). Bu sayı python ile doğrulandı. Aynı insertion sort ilk dizide 29 kaydırma yapar (python ile hesaplandı, derste söylenmedi).
  - Önce bir yöntemle girdi düzenlenip sonra başka bir yöntemle bitirilebilir; parçalar ayrı işlemcilerde eş zamanlı sıralanabilir.
- Soru-cevap: Windows Gezgini'ndeki sıralama
  - Bir öğrenci Windows'un dosya sıralamasında hangi algoritmanın kullanıldığını sordu. Hoca kesin bir kaynak bulamadı; genellikle kendini kanıtlamış temel algoritmaların tercih edildiğini, bir klasörde en fazla binlerce dosya olacağı için basit bir algoritmanın bile yeterli olacağını söyledi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
