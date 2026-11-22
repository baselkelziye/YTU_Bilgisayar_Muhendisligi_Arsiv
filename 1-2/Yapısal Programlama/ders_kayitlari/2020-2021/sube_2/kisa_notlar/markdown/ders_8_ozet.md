# Ders 8 Çalışma Özeti

## Genel Konular

- İşaretçiler hakkında kısa tekrar
  - `int a` ile `int *pa` farklı veri tipleridir; doğrudan birbirine atanmaz. `pa = &a` ve `a = *pa` biçimleri geçerlidir.
  - İfadelerde önce `&` (adres) ya da `*` (dereferans) çalışır, sonra atama yapılır.
- Veri organizasyonu ve diziler
  - Bir problemin çözümü kod ve veriden oluşur. Algoritma tasarımından sonra verinin bellekte nasıl saklanacağına (data organization, veri yapısı) karar verilir.
  - 100 not için 100 ayrı değişken yerine `grade[100]` gibi tek bir dizi tanımlanır (ekrandan, 00:15:00). Diziye sıralı (sequential) ve rastgele (random) erişim yapılabilir.
  - 100 öğrencinin vize ve final notları iki ayrı dizi yerine tek bir matriste tutulabilir.
  - RAM tek boyutlu bir dizi gibi düzenlenmiştir. Matris, liste, yığın (stack), ağaç ve graf gibi veri yapıları bu tek boyutlu yapının üzerine kurulur.
- Dizi tanımı (declaration)
  - Söz dizimi: tip belirteci, dizi adı, `[boyut]`, isteğe bağlı başlatıcı (ekrandan, 00:20:00). Tip belirteci `int`, `char` ya da ileride görülecek `struct ogrenci` gibi kullanıcı tipi olabilir.
  - Boyut bir sabit (literal) olmalıdır ya da `#define N 365` ile önişlemci sabiti olarak verilir.
  - İndisler 0'dan başlar: `int dailyTemp[365]` dizisinin son elemanı `dailyTemp[364]`'tür.
  - Sınır dışı erişimi C denetlemez; programcıya kalmıştır. Java aynı durumda `ArrayIndexOutOfBoundsException` hatası verir.
- Dizinin bellekteki yerleşimi
  - `int ar[5]` için elemanlar ardışık adreslerdedir: `ar[0]` 0x1000'de ise `ar[1]` 0x1004, `ar[2]` 0x1008, `ar[3]` 0x100C, `ar[4]` 0x1010'dadır (ekrandan, 00:25:00).
  - Değer atanmamış elemanların içeriği tanımsızdır (önceki program çalışmasından kalan değer).
  - Dizi adı ilk elemanın adresidir: `ar == &ar[0]`. `ar + i`, adrese `i * sizeof(int)` ekler.
- Dizilere ilk değer verme
  - Eleman sayısından fazla başlatıcı yazmak yanlıştır; eksik yazılırsa kalan elemanlar 0 olur (ekrandan, 00:30:00).
  - `int b_ar[5] = {1, 2, 3.5, 4, 5};` dizisinde 3.5 tamsayıya çevrilir, 3 olur.
  - Boyut yazılmazsa (`char d_ar[] = {'a','b','c','d'};`) derleyici boyutu başlatıcıdan bulur.
- Dizi elemanlarına işaretçiyle erişim
  - `p = &ar[0];` ile `p = ar;` aynıdır. `*(p+3)` ile `ar[3]` aynı bellek gözünü gösterir (ekrandan, 00:35:00).
  - `scanf("%d", &ar[3]);` ile `scanf("%d", (p+3));` eşdeğerdir; `p+3` zaten adres olduğu için önüne `&` konmaz.
  - Geçerli ve geçersiz atamalar (`float ar[5], *p;`): `p = ar;` geçerli; `ar = p;`, `&p = ar;`, `ar++;` geçersiz; `ar[1] = *(p+3);` ve `p++;` geçerli.
- Sıralama örnekleri ve swap
  - Kabarcık sıralaması (bubble sort) komşu elemanları karşılaştırıp yer değiştirir; her turda en büyük eleman sona gider (ekrandan, 00:40:00).
  - Seçmeli sıralama (selection sort) kalan elemanlar içinde en küçüğü bulup başa getirir.
  - İki algoritmanın da temel işlemi swap'tır: `t = dizi[i]; dizi[i] = dizi[j]; dizi[j] = t;` ya da işaretçi aritmetiğiyle `t = *(dizi+i); *(dizi+i) = *(dizi+j); *(dizi+j) = t;`.
- Dev-C++ uygulaması: indis ve işaretçiyle dizi işlemleri
  - `a[i]`, `*(a+i)`, `&a[i]`, `a+i`, `&a[0]+i` ifadeleri karşılaştırıldı; ardışık adresler 4'er bayt arttı (ekrandan, 00:50:00).
  - `scanf("%d", pB);` ve `scanf("%d", (pB+1));` ile işaretçi üzerinden okuma; `*(pB+2) = *(pB) + *(pB+1) + 10;` gibi atamalar (ekrandan, 01:05:00).
  - `*(pB+5) = (int)(pA+4);` satırı bir adresi tamsayıya çevirdiği için derleyici "cast from pointer to integer of different size" uyarısı verdi (ekrandan, 01:10:00).
  - `pA + 4` adrese 4 değil `4 * sizeof(int) = 16` bayt ekler.
- Karakter dizileri (string)
  - String, null karakterle (`'\0'`, sayısal değeri 0) biten bir karakter dizisidir (ekrandan, 01:30:00). Null karakter boşluk karakteriyle karıştırılmamalıdır.
  - `char str[] = "some text";` (10 bayt), `char str[10] = "yes";`, `char *ptr = "more text";` tanımları.
  - `printf("%s", str)` verilen adresten başlayıp `'\0'` görene kadar yazar.
  - `sizeof` ile `strlen` farklıdır: `char str[10] = "AAA BBB";` için `sizeof(str)` 10, `strlen(str)` 7 (ekrandan, 01:40:00).
  - `char *ptr = "AAA BBB";` ile gösterilen sabit stringin bir karakteri değiştirilemez; `ptr[3] = 'C';` çalışma anında segmentasyon hatası verdi (ekrandan, 01:45:00).
- Hata ayıklama (debug)
  - Dev-C++'ta satır numarasına tıklanarak kesme noktası (breakpoint) konur, Execute > Debug ile çalıştırılır. "Add Watch" ile değişken izlenir, "Next line" ile adım adım ilerlenir.
- String atamaları ve karakterler
  - `array = "not OK";` geçersizdir (dizi adı adres sabitidir); `*ptr2 = "not OK";` tip uyuşmazlığıdır; `ptr2 = "OK";` geçerlidir (ekrandan, 01:50:00).
  - Karakter tek tırnakla (1 bayt), string çift tırnakla yazılır: `char *p = "a";` için 2 bayt ayrılır. `*p = 'a';` doğru, `*p = "a";` yanlış, `p = "a";` doğrudur (ekrandan, 01:55:00).
- String okuma, yazma ve string fonksiyonları
  - `scanf("%s", str)` boşluk, Enter ya da Tab görünce durur ve sona `'\0'` ekler; dizi girdiyi alacak kadar uzun olmalıdır (ekrandan, 02:00:00).
  - `strlen` `'\0'` görene kadar sayaç artırır. Diğer fonksiyonlar: `strcpy`, `strncpy`, `strcat`, `strncat`, `strcmp`, `strncmp`, `strstr`.
  - Büyük harfe 32 eklenerek küçük harf elde edilir ('A' = 65, 'a' = 97).
- Örüntü eşleme (pattern matching)
  - Kaba kuvvet (brute force) yöntemi aranan parçayı metin üzerinde birer kaydırarak karakter karakter karşılaştırır (ekrandan, 02:05:00). Boyer-Moore ve Horspool gibi algoritmalar sondan karşılaştırarak daha hızlı kaydırır.
- Çok boyutlu diziler
  - `int ar[3][5];` 5 elemanlı 3 diziden oluşur. `ar[1][2]` ifadesi `*(ar[1]+2)`, o da `*(*(ar+1)+2)` olarak yorumlanır (ekrandan, 02:10:00).
  - `int exap[5][3]` başlatılırken iç küme parantezleri satırları belirler; parantezsiz yazılırsa değerler sırayla satırlara dolar, kalanlar 0 olur (ekrandan, 02:15:00).
- İşaretçi dizileri ve işaretçinin işaretçisi
  - İşaretçiler de dizi halinde tanımlanabilir (`char *ptr[5]` gibi).
  - `int r = 5; int *q = &r; int **p = &q;` ile `r = 10;`, `*q = 10;`, `**p = 10;` aynı gözü değiştirir (ekrandan, 02:20:00).
- Dinamik bellek yönetimine giriş
  - Program belleği kod, ilk değerli/ilk değersiz değişkenler, yığın (stack) ve heap bölgelerine ayrılır. Stack küçük ve sınırlıdır; heap daha büyüktür ve işletim sisteminden izinle alınır.
  - Heap'ten alınan yer işi bitince açıkça serbest bırakılmalıdır; bırakılmazsa bellek sızıntısı (memory leak) olur.

## Hocanın Özellikle Vurguladığı Kısımlar

- İşaretçi bir tiptir
  - `int`, `int *` ve `int **` ayrı tiplerdir; atamada iki tarafın derecesi uyuşmalıdır. Birinci dereceden bir işaretçi ikinci dereceden bir işaretçiye atanmaz.
- Diziler 0'dan başlar
  - "Sıfırıncı elemanı kullanmıyorum, boyutu bir fazla açtım" alışkanlığı yanlıştır. 365 elemanlı dizinin 365. indisi yoktur.
- Diziyi sıfırlamanın en kolay yolu
  - `int a[10] = {0};` yazmaktır; `static` kullanmak bunun yolu değildir.
- Sınır denetimi programcıdadır
  - Sınır dışı bir adres programa ait değilse hata alınır, aitse hata alınmadan yanlış değer okunur.
- `scanf` ve `&`
  - `scanf("%d", &ar[i])` yazılırken `&` gerekir; `scanf("%d", p+3)` yazılırken gerekmez, çünkü `p+3` zaten adrestir. Bu çok yapılan bir hatadır.
- Dizi adı sabittir
  - `ar = p;` ve `ar++;` geçersizdir, çünkü dizi adresini derleyici belirler ve değiştirilemez.
- Dersin özü
  - Dersin özü işaretçi, dizi, struct ve fonksiyon konularının birlikte kullanımıdır: işaretçi × dizi, sonra işaretçi × dizi × fonksiyon, en sonunda struct dizisini işaretçiyle fonksiyona göndermek. Dosya işlemleri, thread ve soket programlama bunların uygulamasıdır.
- Bellek sızıntısı
  - Heap'ten alınan yer serbest bırakılmazsa bellek dolar; programlar hatalı görünmeye başlar.

## Kısa Tekrar Notları

- `ar == &ar[0]`, `ar[i] == *(ar+i)`, `&ar[i] == ar+i`.
- `p + k` adrese `k * sizeof(*p)` bayt ekler.
- Eksik başlatıcı kalan elemanları 0 yapar; `int a[10] = {0};` en kısa sıfırlama yoludur.
- Değer atanmamış yerel dizi elemanı tanımsızdır.
- `ar = p`, `&p = ar`, `ar++` geçersiz; `p = ar`, `p++`, `ar[1] = *(p+3)` geçerli.
- String = `'\0'` ile biten `char` dizisi. `sizeof` ayrılan bayt sayısını, `strlen` `'\0'`'a kadarki karakter sayısını verir.
- `char *ptr = "..."` sabit stringi gösterir; karakterleri değiştirilemez.
- `'a'` 1 bayt karakter, `"a"` 2 bayt string.
- `scanf("%s", ...)` ilk boşlukta durur.
- `ar[i][j] == *(*(ar+i)+j)`.
- `int **p = &q;` ise `**p` ile `r`'ye ulaşılır.
- Heap'ten alınan bellek açıkça serbest bırakılmalıdır.

## Detaylı Açıklamalar

- **Dizi ve adres hesabı.** Bir dizi bellekte ardışık gözlere yerleşir. `int ar[5]` dizisinin ilk elemanı 0x1000 adresinde ise sonraki elemanlar `sizeof(int)` = 4 bayt arayla 0x1004, 0x1008, 0x100C ve 0x1010 adreslerindedir (ekrandan, 00:25:00). Dizi adı `ar` ilk elemanın adresini tutar. `ar[i]` yazıldığında derleyici arka planda `ar + i * sizeof(int)` adresini hesaplar ve oradaki değeri getirir. `scanf` adres istediği için `&ar[i]` yazılır. Aynı adres `ar + i` diye de yazılabilir, o zaman `&` konmaz. Slayttaki örnekte `ar[0] = 15`, `ar[1] = 17`, `ar[3] = ar[0] + ar[1] = 32` atanır; `ar[2]` ve `ar[4]` tanımsız kalır.

- **İşaretçiyle erişim ve geçerli atamalar.** `short ar[4]; short *p;` tanımında `p = &ar[0];` ile `p = ar;` aynı işi görür (ekrandan, 00:35:00). Bundan sonra `*(p+3)` ifadesi `ar[3]` ile aynı gözdür. `float ar[5], *p;` örneğinde `p = ar;` ve `p++;` geçerlidir, çünkü `p` bir değişkendir; `p++` onu bir sonraki `float` elemana götürür. `ar = p;` ve `ar++;` geçersizdir, çünkü dizi adresi sabittir. `&p = ar;` da geçersizdir: `&p` bir değişkenin adresidir, atamanın sol tarafında yer alamaz. Hoca bunu "sol taraf ikinci dereceden, sağ taraf birinci dereceden" diye açıkladı.

- **Swap ile sıralama.** Kabarcık sıralamasında komşu elemanlar karşılaştırılır, sıra bozuksa yer değiştirilir; bir turun sonunda en büyük eleman sona ulaşır ve sonraki turlar bir eksik elemanla tekrarlanır (ekrandan, 00:40:00). Seçmeli sıralamada her adımda kalan elemanların en küçüğü bulunup sıradaki konuma alınır. İki algoritmada da yer değiştirme bir geçici değişkenle yapılır:

  ```c
  t = dizi[i];          /* indisle */
  dizi[i] = dizi[j];
  dizi[j] = t;

  t = *(dizi + i);      /* isaretci aritmetigiyle */
  *(dizi + i) = *(dizi + j);
  *(dizi + j) = t;
  ```

  İki yazım arasındaki fark, birinde adres hesabını derleyicinin, ötekinde programcının yapmasıdır. Algoritmaların tam kodu ileride fonksiyonlar konusunda yazılacak.

- **Dev-C++ uygulaması.** Derste yazılan programın son hali (ekrandan, 00:50:00, 01:05:00, 01:25:00, 01:35:00 ve 01:40:00 karelerinden birleştirildi; `a[2]` ve `a[1]` okuma satırlarının bir kısmı karelerde görünmüyor, altyazıdan kuruldu). Program bu notu hazırlarken `gcc -Wall` ile derlendi ve `7, 8, 2, 2` girdileriyle çalıştırıldı:

  ```c
  #include<stdio.h>
  #define N 5
  int main(){

      int a[N]={1,2,3};
      int b[N+1];
      int i;
      int *pA,*pB;
      pA=a; // pA=&a[0]
      pB=&b[0];

      for(i=0;i<N;i++){
          printf("A[%d]= %d --- &A[%d]= %p\n",i,a[i],i,&a[i]);
      }
      printf("Pointer ile\n");
      for(i=0;i<N;i++){
          printf("A[%d]= %d --- &A[%d]= %p ---&A[%d]= %p\n",i,*(a+i),i,(a+i),i,(&a[0]+i));
      }

      printf("Enter a value for a[2]");
      scanf("%d",&a[2]);
      printf("Enter a value for a[1]");
      scanf("%d",(a+1));
      for(i=0;i<N;i++){
          printf("A[%d]= %d --- &A[%d]= %p ---&A[%d]= %p\n",i,*(a+i),i,(a+i),i,(&a[0]+i));
      }

      printf("Enter a value for b[0]");
      scanf("%d",pB); //&pB[0]
      printf("Enter a value for b[1]");
      scanf("%d",(pB+1));
      printf("B dizisi\n");
      *(pB+2)=*(pB)+ *(pB+1) +10;
      *(pB+3)=-5;
      *(pB+4)=*(pA+3);
      *(pB+5)=(int)(pA+4);
      for(i=0;i<N+1;i++){
          printf("B[%d]= %d --- &B[%d]= %p ---&B[%d]= %p\n",i,*(b+i),i,(b+i),i,(&b[0]+i));
      }

      printf("Integer*4=%d",4*sizeof(int));
      return 0;
  }
  ```

  Çıktıda `A` dizisi 1, 2, 3, 0, 0 olarak başlar; okumalardan sonra `a[1] = 8`, `a[2] = 7` olur. `B` dizisi 2, 2, 14, -5, 0 ve son gözde `a[4]`'ün adresinden türeyen büyük bir sayı olarak çıkar; `Integer*4=16` yazılır. 64 bit Linux'ta `gcc -Wall`, `(int)(pA+4)` satırı için "cast from pointer to integer of different size", son `printf` için de `%d` ile `size_t` uyuşmazlığı uyarısı verir; program yine çalışır.

- **String ve null karakter.** Karakter dizisinin sonuna derleyici otomatik olarak `'\0'` ekler. `printf("%s", str)` ve `strlen` bu karakteri görene kadar ilerler. Hoca `char str[10] = "AA\0A BBB";` tanımıyla `'\0'`'ın stringi gerçekten bitirdiğini gösterdi: `%s` yalnız `AA` yazdı (ekrandan, 01:45:00). `strlen` mantığı: indis `'\0'` olmayan her karakterde bir artırılır, `'\0'` sayılmaz. `str[i] + 32` ile büyük harfler küçüğe çevrilebilir; boşluğa da 32 eklenince `@` çıkar, bu yüzden boşluk ayrıca kontrol edilmelidir.

- **Çok boyutlu diziler ve işaretçi.** `int ar[3][5]` için `ar + 1` ikinci satırın adresidir; `*(ar+1)` o satırın ilk elemanının adresine dönüşür; `*(ar+1) + 2` o satırda iki eleman ilerler; en dıştaki `*` değeri verir: `ar[1][2] == *(*(ar+1)+2)` (ekrandan, 02:10:00). Hoca üç boyutlu dizi (`char x[3][4][5]`) için aynı yazımı çalışma sorusu olarak bıraktı.

- **İşaretçinin işaretçisi.** `r` 100, `q` 200, `p` 300 adresinde olsun (ekrandan, 02:20:00). `q = &r` ile `q` içinde 100, `p = &q` ile `p` içinde 200 bulunur. `*p` `q`'ya, `**p` ise `*q`'ya, yani `r`'ye eşittir; `*` ve `&` birbirini götürür. Birinci dereceden işaretçiler tek boyutlu, ikinci dereceden işaretçiler iki boyutlu dizilerle, üçüncü dereceden işaretçiler üç boyutlu dizilerle kullanılır. Asıl kullanım alanı dinamik bellek ayırmadır.

- **Ders sonrası notlar.**
  - Hoca, `sizeof(ptr)` çıktısındaki 8'i "AAA BBB" stringinin 7 karakteri ile `'\0'` diye yorumladı. `ptr` bir işaretçi olduğu için `sizeof(ptr)` işaretçinin boyutunu verir (64 bit sistemde 8 bayt); 8 çıkması tesadüftür. Bu not hazırlanırken derlenen programda da `sizeof(ptr)` 8, `strlen(ptr)` 7 çıktı.
  - Hoca `strcmp`'in eşit stringlerde 1 döndürdüğünü ve fark negatifse birinci stringin büyük olduğunu söyledi. Doğrusu: `strcmp` eşit stringlerde 0 döndürür; birinci string sözlük sırasında önce geliyorsa negatif, sonra geliyorsa pozitif değer döndürür.
  - Hoca, ilk çalıştırmada `b[2]`'de görülen 7'nin nereden geldiğini bilmediğini söyledi. Ekranda o sırada `int b[N]={5,6,7};` tanımı vardı (ekrandan, 00:50:00); 7 bu başlatıcıdan gelir.
  - Hoca, boyutu yazılmayan dizide "biraz performans kaybı" olduğunu söyledi. Boyut derleme anında başlatıcıdan bulunur; büyük olasılıkla çalışma anında bir maliyeti yoktur.
  - Hoca, fonksiyonda tanımlı `int a` değişkeni `return a` ile döndürülünce değerin görülemeyebileceğini söyledi. Değerle döndürmede değer kopyalandığı için sorun yoktur; sorun yerel değişkenin adresi döndürüldüğünde çıkar. Hoca büyük olasılıkla adres döndürmeyi kastetti.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
