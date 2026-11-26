# Ders 7 Çalışma Özeti

## Genel Konular

- İşaretçinin işaretçisi (pointer to pointer)
  - Slayttaki örnek (ekrandan, 00:20:00): `int r = 5;` bir tamsayı, `int *q = &r;` tamsayıyı gösteren işaretçi, `int **p = &q;` işaretçiyi gösteren işaretçidir. Böylece `p` → `q` → `r` zinciri kurulur.
  - Aynı değişkene üç yoldan atama yapılabilir: `r = 10;` (doğrudan), `*q = 10;` (bir dolaylama), `**p = 10;` (iki dolaylama).
  - Bu yapının asıl kullanımı dinamik bellekle iki boyutlu alan ayırmada görülür.
- Bellek ayırma fonksiyonları (ekrandan, 00:25:00)
  - `void* malloc(total_size_in_bytes)`: istenen toplam bayt kadar yer ayırır, bloğun başını gösteren `void*` döndürür.
  - `void* calloc(number_of_elements, element_size)`: malloc gibidir; parametreler eleman sayısı ve eleman boyutudur. Ayrılan baytları sıfırlar. Toplam alan iki fonksiyonda da aynıdır (eleman sayısı × eleman boyutu).
  - `void* realloc(void *prev_ptr, total_size_in_bytes)`: daha önce ayrılmış bloğun boyunu değiştirir. Blok yeni bir yere taşınabilir; yeni adres fonksiyonun dönüş değeridir. Eski içerik korunur, eklenen kısmın temiz olduğu varsayılmamalıdır.
  - `void free(void *ptr)`: malloc, calloc ya da realloc ile ayrılmış belleği serbest bırakır.
  - Dönen `void*`, saklanacak veri türünün işaretçisine dönüştürülür (cast).
- Dinamik dizi ayırma şablonu (ekrandan, 00:30:00)
  - Eleman sayısı kullanıcıdan alınır, `list = (int *) malloc(n * sizeof(int));` ya da `list = (int *) calloc(n, sizeof(int));` ile yer ayrılır.
  - Dönen işaretçi `NULL` ise hata mesajı verilip çıkılır (fonksiyonda `return -1;`, main'de çıkış).
  - Bellek kullanılır, iş bitince `free(list)` çağrılır.
- Dinamik matris ayırma (ekrandan, 00:40:00)
  - `int **mat;` tanımlanır. Önce satır sayısı kadar satır işaretçisi için yer ayrılır: `mat = (int **) malloc(n * sizeof(int *));`
  - Sonra her satır için ayrı ayrı sütun sayısı kadar eleman ayrılır: `mat[i] = (int *) malloc(m * sizeof(int));`
  - Boşaltma ters sırada yapılır: önce her satır, sonra satır işaretçileri dizisi.
- Dinamik bellekle dizi sıralama uygulaması (Dev-C++)
  - Eleman sayısı kullanıcıdan alınır, main içinde malloc ile yer ayrılır, elemanlar okunur.
  - `printList`, `bubbleSort`, `getPosOfMin`, `selectionSort` ve `swap` fonksiyonları yazılır. Global değişken kullanılmaz; fonksiyonlara dizinin başını gösteren işaretçi ve eleman sayısı gönderilir.
- İki boyutlu karakter dizileri üzerinde işaretçi erişimleri
  - `char **text` (calloc ile tamamen dinamik) ile `char *mat[ROWS]` (sabit metinlere işaretçi dizisi) karşılaştırılır.
  - `%s` ve `%c` ile farklı yıldız, artı ve köşeli parantez birleşimlerinin hangi çıktıyı verdiği tek tek denenir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Dinamik bellek şablonu her soruda uygulanmalıdır
  - Yer ayır, `NULL` kontrolü yap, ayrılamadıysa mesaj verip çık, işi bitince `free` et. Hoca bu adımların sınavlarda önemli puan bileşeni olacağını söyledi.
- `free` unutulmamalıdır
  - C'de bellek yönetimi programcının elindedir. Program bitince işletim sisteminin belleği boşaltacağına güvenilmemelidir; farklı sistemlerin ve sürümlerin bellek yöneticileri farklı davranabilir.
- `free` edilecek işaretçi bloğun başını göstermelidir
  - İşaretçi `++`/`--` ile kaydırıldıysa `free` öncesinde başa getirilmeli ya da başlangıç ayrı bir işaretçide (ör. `listHead`) saklanmalıdır.
- Her malloc'a karşılık bir free
  - İç içe süslü parantezler gibi: en son ayrılan ilk boşaltılır (matriste önce satırlar, sonra satır işaretçileri).
- `sizeof(int)` yazın, sabit `4` yazmayın
  - Taşınabilirliği artırır; ayrıca koddaki başka anlamlı `4`'lerle (ör. ders sayısı) karışmayı önler.
- İşaretçi tek başına uzunluk bilgisi taşımaz
  - Fonksiyona dizinin başlangıç adresi yanında eleman sayısı da parametre olarak verilmelidir. İstisna: null ile sonlandırılmış karakter dizileri.
- Fonksiyona dizi gönderirken işaretçinin adı yazılır
  - Ne başına `*` ne de `&` konur. Fonksiyon tanımında parametre `tür *ad` biçimindedir.
- Değişkenlere her zaman ilk değer verilmelidir
  - Bellekteki eski içeriğe güvenilmez; toplamda ilk değer 0, çarpımda 1 olmalıdır.
- Karakter matrisi örnekleri sınav öncesi mutlaka çalışılmalıdır.

## Kısa Tekrar Notları

- `int **p = &q;` → `**p` iki dolaylamayla `r`'ye ulaşır.
- malloc: tek parametre (toplam bayt), içerik sıfırlanmaz. calloc: iki parametre (eleman sayısı, eleman boyutu), içerik sıfırlanır.
- realloc: eski blok taşınabilir, dönen adres kullanılmalıdır; eski veri korunur.
- Şablon: ayır → `NULL` kontrolü → kullan → `free`.
- Matris: önce `n * sizeof(int *)`, sonra her satıra `m * sizeof(int)`; boşaltma ters sırada.
- `scanf("%d", p+i)` ya da `scanf("%d", &p[i])` doğrudur; `scanf("%d", p[i])` yanlıştır (adres yerine değer gider).
- `printf("%d", *(list+i))` ile `list[i]` aynıdır; yıldızsız `list+i` adres verir.
- `getPosOfMin` döngüsü `i < n` olmalıdır; `i < n-1` son elemanı atlar (off-by-one).
- `char **text` için `*text` ilk satırı (`text[0]`) verir; `printf("%s", **text)` çöker.
- `*(*(text+1)+2)` = `text[1][2]`; `text[3]` gibi olmayan satıra erişim çalışma zamanında çöker.
- `mat[2][4] - mat[1][4]` iki karakterin kod farkıdır: `'G' - 'A' = 6`.

## Detaylı Açıklamalar

- **İşaretçinin işaretçisi ve dinamik bellek**
  - `int **p` türü bir işaretçinin adresini tutar. Hoca bu yapının tek başına pek kullanılmadığını, asıl dinamik iki boyutlu alan ayrılırken gerektiğini söyledi. Dinamik bellek yönetiminde temel iş; malloc ya da calloc ile yer ayırmak, bu alana işaretçi aritmetiğiyle erişmek ve sonunda `free` ile geri vermektir.
  - realloc için hoca bir ders kayıt örneği verdi: her biri 100 kişilik iki grup dolmuşken sonradan 4 öğrenci daha gelirse yeni bir grup açmak yerine her gruba 2 öğrenci eklenir. Bunun için gruptaki kayıt alanı `realloc(eski_isaretci, 102 kayıtlık yeni toplam boyut)` ile büyütülür. Bitişik yer yetmezse blok başka adrese taşınabilir; eski bilgiler kopyalanır. Adresin değişebileceği unutulmamalı, başka bir yerde saklanan eski başlangıç adresi varsa güncellenmelidir.
- **Dinamik dizi şablonu** (ekrandan, 00:30:00)

  ```c
  int n;
  int *list;
  ...
  printf("How many numbers are you going to enter ?");
  scanf("%d", &n);
  list = (int *) malloc( n * sizeof(int) ); //OR: (int *) calloc( n, sizeof(int) );
  if(list==NULL) {
      printf("%s:%d>Can not allocate memory for the array...\n",__FILE__, __LINE__);
      return -1;
  }
  //use the memory and then
  free(list)
  ```

  - `__FILE__` ve `__LINE__` makrolarını kullanmak zorunlu değildir; kısa bir "bellek yetersiz" mesajı verip `return -1` ya da çıkış yapmak yeterlidir.
- **Dinamik matris** (ekrandan, 00:40:00)

  ```c
  int **mat;
  int n,m;
  printf("Please enter number of rows");scanf("%d", &n);
  printf("Please enter number of columns");scanf("%d", &m);
  mat = (int **) malloc( n * sizeof(int *) );
  if(mat == NULL) {
      printf("%s:%d>Can not allocate memory for the array...\n",__FILE__, __LINE__);
      return -1;
  }
  for(i = 0; i < n; i++) {
      mat[i] = (int *)malloc(m * sizeof(int) );
  }
  //will be continued in the next slide
  ```

  - Hoca Excel'de 3 satır × 5 sütunluk bir tabloyla anlattı (ekrandan, 00:35:00): `mat[0]` (ya da `*(mat+0)`) ilk satırı, `mat[1]` ikinci satırı gösteren işaretçidir. `mat[0][0]` gözü `*(*(mat+0)+0)`, `mat[1][2]` gözü `*(*(mat+1)+2)` diye de yazılabilir.
  - Slaytta her satırın ayrımı ayrıca `NULL` diye denetlenmemiştir; hoca ilk denetimin mutlaka yapılması gerektiğini söyledi.
- **Sıralama uygulaması** (ekrandan, 01:30:00 ve 01:50:00)
  - Main içinde eleman sayısı alınır, `p = (int*) malloc( n * sizeof(int) );` ile yer ayrılır, `NULL` ise "Bellekte yer ayrilamadi" mesajıyla çıkılır.
  - Eleman okuma denemesinde `scanf("%d", p[i])` program takılmasına yol açtı; `scanf("%d", p+i)` ve bir öğrencinin hatırlattığı `scanf("%d", &p[i])` doğru çalıştı. scanf her zaman adres bekler.
  - `printList(int *list, int n)` elemanları `*(list+i)` ile yazar; yıldız konmazsa adresler yazılır.
  - calloc/malloc karşılaştırması: elemanlar okunmadan önce yazdırıldığında calloc ile ayrılan alanın tamamen sıfır olduğu görüldü.
  - `bubbleSort` iç içe döngüyle `list[i] > list[j]` ise yer değiştirir. `getPosOfMin(list, n, pos)` `pos+1`'den sona kadar en küçüğün konumunu döndürür; `selectionSort` her adımda bunu çağırıp `swap(list+i, list+minPos)` ile yer değiştirir.
  - Derste iki hata çıktı: `getPosOfMin` içinde `pos` adıyla ikinci bir değişken tanımlanınca derleyici "declaration of 'pos' shadows a parameter" uyarısı verdi (ekrandan, 01:40:00); döngü sınırı `i<n-1` yazılınca son eleman karşılaştırılmadı ve `i<n` ile düzeltildi.
  - Önceki dizi sürümüyle karşılaştırma: algoritmalar aynı kaldı; asıl kazanç global değişkenlerden kurtulmak ve eleman sayısını çalışma anında belirleyebilmektir.
- **Karakter matrisi erişimleri** (ekrandan, 02:20:00 ve 02:50:00)
  - `char **text` calloc ile satır satır ayrılır ve `strcpy` ile `"012345\n"`, `"6789AB\n"`, `"CDEFGH\n"` kopyalanır; `char *mat[ROWS]` aynı metinlerle ilk değer alır. `mat`'ın gösterdiği metinler sabittir, değiştirilmeye çalışılmamalıdır. `text` hem boyut hem içerik açısından tamamen dinamiktir.
  - `char *bp, *mp;` satırında yıldız her değişkene ayrı uygulanır; `*mp` `**mp` olmaz.
  - `bp = text[0]; mp = text[1];` ile çıktılar: `mp` → `6789AB`, `mp+1` → `789AB`, `mp+2` → `89AB`, `*text` → `012345`, `*bp` → `0`, `*(bp+2)` → `2`, `**text` → `0`, `*(*(text+1)+2)` → `8`, `*((text[1])+3)` → `9`, `*(*(mat+1)+2)` → `8`, `mat[2][4]-mat[1][4]` (`%d`) → `6`.
  - `%c` ile `text`, `bp` ya da `*text` vermek (adres vermek) anlamsız karakter basar; `%s` ile `**text` vermek programı çökertir.
  - Tek bir `printf("%s", ...)` ile bütün matris yazdırılamaz; her satır döngüde ayrı yazdırılır.
  - Sonunda önce her `text[i]`, sonra `text` boşaltılır. malloc/calloc ile ayrılmayan `mat` için `free` gerekmez.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
