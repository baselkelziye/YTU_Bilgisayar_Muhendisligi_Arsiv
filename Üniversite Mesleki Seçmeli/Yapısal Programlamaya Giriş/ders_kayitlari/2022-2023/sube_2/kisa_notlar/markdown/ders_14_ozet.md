# Ders 14 Çalışma Özeti

## Genel Konular

- Fonksiyonların amacı ve tanımı
  - Bir kez yazılıp tekrar tekrar kullanılabilen, başkalarının da kullanabildiği, isimlendirilmiş ve parametre alan algoritmalardır (ekrandan, 00:10:00).
  - Faydaları: bir kez yaz, tekrar kullan; böl-yönet ile büyük işi modüllere ayırma; kolay düzeltme (debug) ve kolay bakım; kod tekrarının önlenmesi.
  - Genel gösterim: `[çıkış parametreleri] = Fonksiyon_ismi(giriş parametreleri)`. Python, MATLAB gibi dillerde birden fazla değer döndürülebilir; C'de `return` ile en fazla bir değer döner.
  - İyi dokümantasyon: kısıtlar, kabiliyetler, parametreler açıklanmalı; içerideki yardımcı değişkenlerin ne tuttuğu yazılmalı; değişken adları ne tuttuğunu anlatmalı, uzun olabilir (`numberOfStudents` gibi).
- Tanım, çağrı, parametre ve argüman
  - Tanım: dönüş tipi (`void` ya da başka bir tip), fonksiyon adı, parametreler, değişken tanımları ve gövde.
  - Çağrı (call / invoke): fonksiyon adı ve argümanlar. Tanımda yazılanlar parametre, çağrıda gönderilenler argümandır. Örnek: `int f1(int x, char c)` tanımında `x`, `c` parametre; `x = f1(8, 'c');` çağrısında `8` ve `'c'` argümandır.
  - Kütüphane fonksiyonları ve kullanıcı tanımlı fonksiyonlar olmak üzere iki tür vardır.
- Fonksiyon tasarım ilkeleri (Deitel slaytları, ekrandan, 00:15:00 ve 00:20:00)
  - Düşük bağlaşım (low coupling): bir parçanın diğer parçalara bağımlılığı düşük olmalı. Düşük bağlaşım bir değişikliğin daha az yeri etkilemesini ve yeniden kullanılabilirliği sağlar.
  - Yüksek uyum (high cohesion): fonksiyonun adı, parametreleri ve yaptığı işler birbiriyle tutarlı olmalı. Anlaşılma, yeniden kullanım ve bakım kolaylaşır.
  - Düşük bağlaşım genelde yüksek uyumu, yüksek bağlaşım düşük uyumu beraberinde getirir.
  - Örnek: diziyi hem sıralayıp hem yazdıran fonksiyon kötüdür. Sıralama, yazdırma ayrı fonksiyonlar olmalı; gerekirse bunları sırayla çağıran bir sarmalayıcı (wrapper) fonksiyon yazılır.
- Akış diyagramında fonksiyon
  - Fonksiyon kutusunun üstüne fonksiyon adı ve giriş parametreleri, altına çıkış parametreleri yazılır. Fonksiyon akışının sonunda `return` yerine `stop` kullanılır; stop, çağrılan yere geri dönüş demektir.
- Programın bellekteki yerleşimi ve fonksiyon çağrısı (ekrandan, 00:25:00 ve 00:30:00)
  - Bölümler (alttan üste): Instructions (salt okunur, çalıştırılabilir), Literals (salt okunur), Static Data, Dynamic Data (Heap, programcı yönetir), Stack (derleyici otomatik yönetir). Heap ve stack birbirine doğru büyür.
  - Her çağrıda çağrılan fonksiyon stack'e eklenir; yerel değişkenler ve dönüş satırı (program counter) ile işlemci durumu (status register vb.) orada saklanır. Fonksiyon bitince kaydı stack'ten silinir, program saklanan satırdan devam eder.
  - Bu yüzden yerel değişkenler yalnız fonksiyon çalışırken yaşar. Kalıcı olması gereken veri heap'te tutulur (`malloc` vb., bu dersin konusu değil).
- Dizinin en küçük ve en büyük elemanının yerini bulan fonksiyon
  - `void minmaxBul(int dizi[], int N, int *min, int *max)`: iki değer döndürmek gerektiği için sonuç pointer parametrelerle çağrılan yere yazılır (ekrandan, 00:45:00).
  - Diziler fonksiyona adresiyle gider (call by reference); fonksiyonda yapılan değişiklik orijinal diziye yansır. `int` gibi değişkenler değer olarak kopyalanır.
- Aynı fonksiyonla matrisin en küçük ve en büyük elemanı (`minmaxBulv2`)
  - Matrisin her satırı bir dizi gibidir. Her satırın min ve max'ı bulunup `dizimin` ve `dizimax` yedek dizilerine yazılır; sonra `dizimin`'in en küçüğü ve `dizimax`'ın en büyüğü bulunur. Aynı fonksiyon satırlar için $m$ kez, sonra iki yedek dizi için birer kez, toplam $m+2$ kez çağrılır; kod yeniden yazılmaz. (Hoca ilk anlatımda $m+1$ dedi; kodda iki yedek dizi ayrı ayrı gönderildiği için $m+2$ oldu.)
  - İyileştirme: satırı yedek diziye kopyalamak yerine `matris[i]` doğrudan dizi gibi gönderilir; iç kopyalama döngüsü kalkar (ekrandan, 01:15:00).
  - Doğrusu, min ve max için ayrı `minBul` ve `maxBul` fonksiyonları yazmaktır (tasarım ilkelerine uygun).
- Dizinin tek bir elemanını fonksiyona gönderme
  - `f2(dizi[2])` sıradan bir `int` göndermektir; fonksiyondaki değişiklik diziye yansımaz. Yansıması için adres gönderilir: `f3(&dizi[2])` ve `*x = 5` (ekrandan, 01:35:00).
- Fonksiyon aşırı yükleme (overloading)
  - Aynı isimli fonksiyonun farklı tip ve sayıda parametreyle tanımlanmasıdır. Nesne tabanlı dillerde vardır, C'de doğrudan yoktur.
- En yakın ikili (closest pair) problemi
  - Bir boyutlu: noktalar bir dizide tutulur, uzaklık mutlak farktır. Sırasız dizide iç içe iki döngüyle bütün ikililere bakılır ($O(n^2)$); sıralı dizide yalnız ardışık elemanlara bakmak yeterlidir ($O(n)$).
  - İki boyutlu: noktalar $m \times 2$ matriste tutulur; uzaklık Öklid uzaklığıdır, karşılaştırma için kare kök almaya gerek yoktur.
  - $k$ boyutlu: noktalar $m \times k$ matriste tutulur; boyutlar üzerinde üçüncü bir döngüyle kare farklar toplanır.
- Gerçek hayat uygulamaları
  - Çöpçatan sitesi: $N$ erkek ve $M$ kadının $D$ soruya sayısal cevapları iki matriste tutulur; en küçük uzaklıklı (erkek, kadın) ikilisi en uyumlu ikilidir. Öneri sistemlerinin temelinde de benzer bir benzerlik hesabı vardır.
  - Kategorik cevaplarda fark anlamsızdır; aynıysa uzaklık 0, farklıysa 1 verilir.
  - Doktor-hasta teşhis problemi: en başarılı doktor, birbirine en benzeyen iki doktor ya da iki hasta, en nadir konulan teşhis, demokrasi usulünde yanlış teşhis konan hastalar. Hepsi min-max bulma, frekans (histogram) ve closest pair problemlerine indirgenir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Fonksiyon çağrısında bellekte (stack) olan olaylar
  - Hoca "bu çok önemli" diyerek çağrı yığınının nasıl dolup boşaldığını adım adım gösterdi. Yerel değişkenlerin fonksiyon bitince yok olduğu buradan anlaşılır.
- Low coupling ve high cohesion
  - Yazılım mühendisliğinin temel kuralıdır; nesne yönelimli programlama bunun üzerine kuruludur. "İsviçre çakısı" gibi her işi yapan fonksiyon yazılmaz.
- C'de fonksiyon prototipi
  - C'de fonksiyonlar `main`'den sonra yazılırsa prototip zorunludur. Prototipte parametre adları yazılmayabilir, yalnız tipleri yeterlidir. Prototip unutulunca derleyici "implicit declaration" ve "conflicting types" uyarısı verdi.
- Pointer ile değer döndürme
  - C'de `return` ile tek değer döner; birden fazla sonuç pointer parametrelerle döndürülür. `main`de normal değişken olan `min`'i yazdırırken `*` kullanılmaz; `*` yalnız pointer'ın gösterdiği değere erişmek içindir.
- Parametre sayısı
  - Bir fonksiyonun 20-30 parametre alması kötü tasarımdır.
- Sınavlarda bu tür senaryo soruları
  - Hoca, doktor-hasta gibi bir veriden 5-6 soru üretilebileceğini ve sınavlarda buna benzer sorular sorduklarını söyledi.

## Kısa Tekrar Notları

- Parametre: tanımda; argüman: çağrıda.
- C'de `return` ile en fazla bir değer döner; fazlası için pointer parametre kullanılır.
- Dizi ve matris adresiyle gider; içerideki değişiklik `main`'e yansır. Dizinin tek elemanı (`dizi[2]`) değerle gider; yansıması için `&dizi[2]` gönderilir.
- Yerel değişkenler stack'te durur ve fonksiyon bitince yok olur.
- Stack çerçevesinde yerel değişkenler, dönüş adresi (program counter) ve işlemci durumu saklanır.
- Matrisin `i`. satırı `matris[i]` ile doğrudan dizi gibi bir fonksiyona gönderilebilir.
- Low coupling + high cohesion: her fonksiyon tek, uyumlu bir iş yapar.
- Closest pair: sırasız 1B $O(n^2)$, sıralı 1B $O(n)$; 2B ve $k$B için kare farklar toplamı kullanılır, kare köke gerek yoktur.
- Kategorik veride uzaklık: aynı 0, farklı 1.
- Min-max başlatırken ilk eleman en küçük ve en büyük kabul edilir, döngü 1'den başlar.

## Detaylı Açıklamalar

- **Bellekte fonksiyon çağrısı örneği.** Hoca şu yapıyı çizdi (ekrandan, 00:30:00): `main` 1. satırda başlar, 2. satırda `f1()`, 3. satırda `f2()` çağrılır; `f1` 10. satırda başlayıp 11. satırda `f3()`'ü çağırır; `f2` 20. satırda başlayıp 21. satırda `f3()`'ü çağırır; `f3` 30. satırda başlayıp 31. satırda `f4()`'ü çağırır; `f4` 40. satırdadır ve başka çağrı yapmaz.
  - `main` stack'e girer. 2. satırda `f1` çağrılınca dönüş satırı 2 saklanır, `f1` stack'in üstüne eklenir.
  - `f1` 11. satırda `f3`'ü çağırınca 11 saklanır; `f3` 31. satırda `f4`'ü çağırınca 31 saklanır.
  - `f4` bitince stack'ten silinir; 31. satırdan devam edilir. `f3` bitince silinir; 11. satırdan devam edilir. `f1` bitince 2. satıra dönülür ve 3. satırda `f2` için aynı süreç tekrarlanır.
  - Bir öğrencinin sorusu üzerine: stack'e yalnız değişkenler değil, program counter ve işlemcinin durum yazmacı gibi bilgiler de yedeklenir. Komutların kendisi Instructions bölümünde durur. Bu işler işletim sisteminin denetiminde yapılır.
- **`minmaxBul` (ekrandan, 00:45:00 ve 00:50:00).**

  ```c
  #include <stdio.h>
  #define MAX 15
  void minmaxBul(int dizi[], int N, int *min, int *max);
  int main(){
      int dizi[MAX]={2,4,7,9,1,6,-8};
      int min, max;
      int N = sizeof(dizi)/sizeof(dizi[0]);
      minmaxBul(dizi,N,&min,&max);
      printf("Min = Dizi[%d] -> %d\n",min,dizi[min]);
      printf("Max = Dizi[%d] -> %d\n",max,dizi[max]);
      return 0;
  }
  void minmaxBul(int dizi[], int N, int *min, int *max){
      int i;
      int minI=0, maxI=0;
      for(i=1;i<N;i++){
          if(dizi[i]<dizi[minI]){
              minI = i;
          }
          if(dizi[i]>dizi[maxI]){
              maxI = i;
          }
      }
      *min = minI;
      *max = maxI;
  }
  ```

  - Prototip eklenmiş haliyle `gcc -Wall` ile derlendi ve çalıştırıldı; çıktı `Min = Dizi[6] -> -8`, `Max = Dizi[3] -> 9`.
  - Ders sonrası not: hoca `N`'nin 7 olacağını söyledi; ama `dizi` `MAX` (15) elemanlı tanımlandığı için `sizeof(dizi)/sizeof(dizi[0])` 15 verir (bunu derste bir öğrenci de fark etti). Kalan 8 eleman 0'dır; bu örnekte en küçük $-8$, en büyük $9$ olduğu için sonuç değişmez, ama dizide yalnız pozitif ya da yalnız negatif sayılar olsaydı yanlış sonuç çıkardı.
- **Matris sürümü ve hata ayıklama.** İlk sürümde her satır `dizi`'ye kopyalanıp `minmaxBul(dizi,n,&m1,&m2)` çağrıldı, sonra `dizimin[i] = dizi[m1]` yazıldı (ekrandan, 01:00:00). Kopyalama döngüsü kaldırılıp `minmaxBul(matris[i],n,&m1,&m2)` yazılınca sonuç yanlış (0) çıktı; Dev-C++ hata ayıklayıcısı ve "Add Watch" ile incelenince sebebin `dizimin[i] = dizi[m1]` satırı olduğu görüldü: `dizi` artık doldurulmuyordu. Doğrusu `dizimin[i] = matris[i][m1]` ve `dizimax[i] = matris[i][m2]`'dir (ekrandan, 01:15:00). Matris `{{3,2,1},{6,2,8}}` için sonuç min 1, max 8; bir eleman (büyük olasılıkla 8) $-8$ yapılınca min $-8$, max 6 oldu. <!-- BELİRSİZ: ilk satır karede {3,2,1} olarak görünüyor; ikinci satır ve değiştirilen eleman altyazıdan kuruldu. -->
- **Bir boyutlu closest pair, sırasız (ekrandan, 01:55:00).** `dist` ilk iki elemanın uzaklığıyla başlatılır; `i` 0'dan `N-2`'ye, `j` `i+1`'den `N-1`'e gider; `temp = abs(dizi[i]-dizi[j])` daha küçükse `dist`, `x`, `y` güncellenir; sonunda `*e1 = x; *e2 = y;` yazılır.
- **Bir boyutlu closest pair, sıralı (ekrandan, 02:00:00).** Tek döngüde `abs(dizi[i]-dizi[i+1])`'e bakılır; `i < N-1` koşulu dizinin dışına taşmayı önler. `x` ve `y`'ye başlangıç değeri (0 ve 1) verilmezse çöp değerle kalır; derste bu hata hata ayıklayıcıyla bulundu.
- **$k$ boyutlu closest pair (ekrandan, 02:30:00).** `tmp = 0; for(t=0;t<n;t++) tmp += pow(matris[i][t]-matris[j][t],2);` ve `tmp < d` ise `*x = i; *y = j; d = tmp;`. `d` başlangıçta `INT_MAX`'tır.
- **Çöpçatan (ekrandan, 02:25:00).** Slayttaki sözde kod: `min_dist=100000; ind1=0; ind2=0;` sonra `for i=1:M`, `for j=1:N`, `dist=0`, `for k=1:D` `dist=dist+|E(i,k)-K(j,k)|`, `dist<min_dist` ise `min_dist=dist; ind1=i; ind2=j;`. Burada uzaklık mutlak farkların toplamıdır; hoca kare almanın da sonucu değiştirmeyeceğini söyledi.
- **Doktor-hasta problemi (ekrandan, 02:40:00).** $D$ doktorun $H$ hastaya koyduğu teşhisler $D \times H$ matrisinde, gerçek teşhisler $H$ elemanlı `G` dizisindedir. En başarılı doktor için `D[i][j] == G[j]` ise `DT[i]++` yapılır, sonra `DT`'nin en büyüğünün indisi (`maxBul(DT)`) bulunur. Hasta başına teşhis frekansı çıkarılıp en çok konulan teşhis gerçek teşhisle karşılaştırılırsa "çoğunluğun yanıldığı" hastalar bulunur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
