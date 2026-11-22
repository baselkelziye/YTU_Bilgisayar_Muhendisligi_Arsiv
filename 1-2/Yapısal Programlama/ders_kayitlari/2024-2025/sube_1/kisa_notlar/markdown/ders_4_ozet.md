# Ders 4 Çalışma Özeti

## Genel Konular

- Uygulama oturumunun kapsamı
  - Bu kayıt dönemin ilk uygulama oturumudur ve üç soru çözülür: dizi ve döngülerle Pisagor üçlüsü arama, işaretçi (pointer) konusunun hızlı tekrarı, işaretçiyle bir metin içinde alt kod (alt dizgi) arama.
  - Kodlar Dev-C++ ortamında yazılıp çalıştırılır; dizi ve arama mantığı Paint üzerinde çizilerek anlatılır.
- Kod yazmadan önce algoritma kurmak
  - Önce problem adımlara bölünür (akış şeması mantığı): eleman sayısını al, diziyi doldur, arama yap, sonucu yaz.
  - Kodun sözdizimini bilmekten çok, problemi çözen algoritmayı kafada kurmak önemlidir.
- Soru 1: Dizide Pisagor üçlüsü
  - Soru metni (ekrandan, 00:05:00): verilen bir dizi içinde Pythagorean triplet bulunup bulunmadığını kontrol eden, varsa üçlüyü ekrana yazan C programı. Örnek girdi `arr[] = {3, 1, 4, 6, 5}`, çıktı `True`, üçlü `(3, 4, 5)`.
  - Dizi boyutu `#define MAX 50` ile sabit tanımlanır, kullanıcıdan eleman sayısı (`esayi`) ve elemanlar `scanf` ile alınır.
  - Üç iç içe `for` ile bütün üçlü kombinasyonlar gezilir: `a` sıfırdan, `b` `a+1`'den, `c` `b+1`'den başlar.
  - Dizi sıralı olmadığından üç kare (`x`, `y`, `z`) hesaplanır ve üç durum birlikte denetlenir: `x==y+z || y==x+z || z==x+y`.
  - Bulunan her üçlü için bir sayaç (`count`) artırılır; döngüler bitince `count == 0` ise üçlü olmadığı yazılır.
- Soru 2: İşaretçi tekrarı
  - Bir değişken bellekte (RAM) bir adreste tutulur; `int` 4 bayt yer kaplar.
  - `&` işleci değişkenin adresini verir; `scanf("%d", &x)` de değeri bu adrese yazar.
  - İşaretçi bir adres tutan değişkendir: `int *ip; ip = &var;`. `ip` adresi, `*ip` o adresteki değeri (20) verir.
  - İşaretçinin türü, işaret ettiği verinin türüyle aynı olmalıdır (int için `int *`).
  - Dizi adı dizinin başlangıç adresidir: `ptr = arr;` ile `ptr = &arr[0];` aynıdır.
  - İşaretçi aritmetiği: `int *` için `ptr++` adresi 1 değil `sizeof(int)` = 4 bayt ilerletir; `char *` için 1 bayt.
  - `sizeof(dizi) / sizeof(dizi[0])` ile dizinin eleman sayısı bulunabilir (3 elemanlı int dizisi için 12/4 = 3).
- Soru 3: İşaretçiyle alt kod arama
  - Soru metni (ekrandan, 00:35:00): kimya laboratuvarında ana kod (ör. "NaClK") içinde alt kodun (ör. "Cl") geçip geçmediğini ve geçiyorsa ilk geçtiği indeksi dizi ve işaretçi kullanarak bulan program; geçmiyorsa "Aradığınız alt kod bulunamadı." gibi bir mesaj.
  - Derste örnek olarak metin "fenerbahce", aranan "bah" kullanılır; sonuç 5. indekstir.
  - `ptr` metnin o anki başlangıç noktasını tutar, `temp = ptr` ile karşılaştırma `temp` üzerinden yapılır ki başlangıç kaybolmasın.
  - İç döngü `*(temp + i) == pattern[i] && pattern[i] != '\0'` olduğu sürece `i`'yi artırır; desen sonuna (`'\0'`) varılmışsa eşleşme tamdır.
  - İlk eşleşmede indeks `ptr - text` ile, yani iki adresin farkıyla bulunur.

## Hocanın Özellikle Vurguladığı Kısımlar

- İşaretçi konusu C'nin en önemli konusudur
  - Veri yapıları ve algoritma analizi gibi sonraki derslerde sürekli kullanılacağı için iyi öğrenilmesi istenir.
- Bölümün kod yazım kuralları
  - Boyutu sabit diziler `#define` ile tanımlanan bir makro sabitle boyutlandırılır.
  - Döngü değişkeni `for (int i = 0; ...)` biçiminde döngü içinde tanımlanmaz, yukarıda tanımlanır.
  - `break`, `continue`, `goto` ve döngü içinde değişken tanımlama bölümün yazım kurallarına aykırıdır; kod doğru çıktı verse bile bu kurallara uymak gerekir.
- Algoritmik düşünme
  - Koda başlamadan önce problemin hangi adımlarla çözüleceği belirlenmelidir.
- Karmaşıklık
  - Üç iç içe döngü çalışma süresini artırır; aynı problem daha düşük karmaşıklıkla da çözülebilir (algoritma analizi dersinde görülecek).
- Başlangıç işaretçisini kaybetmemek
  - Aramada `ptr` sabit tutulup `temp` ile ilerlenir; böylece eşleşmenin başladığı adres elde kalır.

## Kısa Tekrar Notları

- Pisagor üçlüsü: $a^2 = b^2 + c^2$ olacak üç eleman; sırasız dizide üç eşitlik birlikte denetlenir.
- Üç iç içe döngü, başlangıçlar `a=0`, `b=a+1`, `c=b+1`: her üçlü bir kez denenir.
- Sayaç değişkeni (`count`) kullanılmadan önce 0 yapılmalıdır.
- `&x` adres, `int *p = &x;` işaretçi, `*p` değer.
- `ptr++` türün boyutu kadar ilerler (int: 4 bayt, char: 1 bayt).
- Dizi adı = ilk elemanın adresi.
- Alt dizgi arama: dış döngü başlangıcı kaydırır, iç döngü karakter karakter karşılaştırır; desen `'\0'`'a ulaşırsa bulundu.
- İndeks = `ptr - text` (işaretçi farkı eleman sayısı cinsindendir).

## Detaylı Açıklamalar

- Soru 1'in kodu derste şu iskelete göre yazılır (ekrandan, 00:20:00 ve 00:25:00): `int Array[MAX]; int i, esayi, a, b, c, x, y, z, count;` tanımlanır; `printf("Dizimiz kaç elemanlı olsun"); scanf("%d",&esayi);` ile boyut, `for(i=0;i<esayi;i++)` içinde `printf("Dizi [%d]. elemanını giriniz:",i); scanf("%d",&Array[i]);` ile elemanlar alınır. Ardından `for(a=0;a<esayi;a++)`, `for(b=a+1;b<esayi;b++)`, `for(c=b+1;c<esayi;c++)` içinde `x=Array[a]*Array[a]; y=Array[b]*Array[b]; z=Array[c]*Array[c];` hesaplanır ve `if(x==y+z||y==x+z||z==x+y)` sağlanınca `count++` yapılıp üçlü yazılır. Türkçe karakterlerin konsolda düzgün çıkması için `#include <locale.h>` ve `setlocale(LC_ALL, "Turkish");` kullanılır. Derste programa 5 elemanlı `5 8 1 3 4` girilince (5, 3, 4) üçlüsü bulunur; 10 elemanlı bir girdide (5, 3, 4) ve (5, 12, 13) iki üçlü olarak bulunur; 3, 4, 5 verilmeyen bir girdide üçlü olmadığı mesajı çıkar.
  - Ders sonrası not: Ekranda `int count;` ilk değer verilmeden tanımlanmış görünüyor (ekrandan, 00:25:00). Yerel değişkenin ilk değeri belirsizdir; `count++` ve `count == 0` denetiminin doğru çalışması için `int count = 0;` yazılmalıdır. `gcc -Wall -O2` bu satır için "may be used uninitialized" uyarısı verir.
  - Kodun, karede görünmeyen yazdırma satırları tamamlanmış hali `int count = 0;` ile `gcc -Wall` altında derlenip derste girilen `5 8 1 3 4` girdisiyle çalıştırıldı; (5, 3, 4) çıktısı alındı. <!-- BELİRSİZ: üçlüyü yazdıran printf satırının metni karede görünmüyor -->
- Soru 2'de bellek, adresli kutular olarak çizilir: `int var = 20;` tanımlanınca 4 baytlık bir alan ayrılır ve değer oraya yazılır. Ekrandaki kod (ekrandan, 00:30:00) önce `&var` adresini `%p` ile yazar, `int *ip;` ve `int *ptr = NULL;` tanımlar, `ip = &var;` atamasından sonra `ip` ile `&var`'ın aynı adresi, `*ip` ile 20'yi verdiği gösterilir. Dizide ise `ptr = arr;` (ya da `&arr[0]`) yapılıp `ptr++` ile ilerlenince adreslerin 4'er bayt arttığı görülür.
  - Ders sonrası not: Asistan, işaretçi boş bırakıldığında da sıfır atanacağını söyledi. Doğrusu: fonksiyon içindeki ilk değer verilmemiş bir işaretçinin değeri belirsizdir; ekranda 0 görülmesi şanstır. Güvenli tanımlama `int *ip = NULL;` biçimindedir. `gcc -Wall` bu kullanım için "used uninitialized" uyarısı verir.
- Soru 3'ün ekrandaki kodu (ekrandan, 00:45:00 ve 00:50:00) şöyledir: `char text[100], pattern[100];` dizileri `scanf("%s", ...)` ile okunur; `int i; int count = 0; int index = -1; char *ptr = text; char *temp = NULL;` tanımlanır. `while (*ptr != '\0')` dış döngüsünde `i = 0; temp = ptr;` yapılır, `while (*(temp + i) == pattern[i] && pattern[i] != '\0') i++;` ile karşılaştırılır; `if (pattern[i] == '\0')` ise `count++` yapılır ve `index == -1` ise iki adres yazdırılıp `index = ptr - text;` hesaplanır; sonra `ptr++`. "fenerbahce" ve "bah" girilince adreslerin son hanesi 5 ve 0 çıkar, fark 5 olduğundan alt kod 5. indekste bulunur.
  - Ders sonrası not: Asistan bir yerde indeks hesabını int gibi 4'er bayt üzerinden anlattı, sonra char'ın 1 bayt olduğunu söyleyerek düzeltti. Ayrıca işaretçi farkı (`ptr - text`) her durumda bayt değil eleman sayısı verir; bu yüzden indeks hesabı her türde doğrudur.
  - Ders sonrası not: Asistan, 100 elemanlı dizinin kullanılmayan kısmına `'\0'` konduğunu söyledi. Doğrusu: `scanf("%s")` yalnız okunan metnin sonuna tek bir `'\0'` ekler; yerel dizinin geri kalanı belirsiz kalır. Döngü yine ilk `'\0'`'da durduğu için kod doğru çalışır.
  - Kodun karede görünmeyen son kısmı ("bulunamadı" mesajı ve sonuç yazdırma) tamamlanarak `gcc -Wall` ile derlendi; "fenerbahce"/"bah" için 5, "NaClK"/"Cl" için 2 indeksi ve bulunmayan desen için "Aradığınız alt kod bulunamadı." çıktısı alındı. <!-- BELİRSİZ: kodun 36. satırdan sonraki kısmı karelerde görünmüyor -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
