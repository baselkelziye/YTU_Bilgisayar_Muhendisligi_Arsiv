# Ders 19 Çalışma Özeti

## Genel Konular

- Özyinelemeli (recursive) fonksiyonlara giriş
  - Bu oturum bir uygulama dersidir. Konunun kısa bir özeti verildi, ardından beş örnek birlikte C ile yazılıp derlendi (ekrandan, 00:15:00).
  - Özyineleme, küçük parçalara bölünebilen problemleri çözen algoritmalarda sık kullanılır. Böl ve fethet (divide and conquer) yaklaşımı ileride algoritmalar dersinde görülecektir.
  - Özyinelemeli bir fonksiyonun iki bölümü vardır:
    - Base case (temel durum): fonksiyonun kendini çağırmayı bıraktığı durum. C'de genellikle bir `if` koşuluyla yazılır.
    - Recursive part (özyinelemeli kısım): fonksiyonun kendini parametresi değişmiş olarak yeniden çağırdığı kısım. Parametre her çağrıda aynı kurala göre değişir (örneğin bir azalır ya da ikiye bölünür).
- Çalışma mantığı: `fonk` örneği (ekrandan, 00:10:00)
  - Slayttaki `fonk(n)` fonksiyonu `n==1` ise 1, değilse `1+fonk(n-1)` döndürür; yani kaç kez çağrıldığını sayar. Slaytta `1+fonk(n)` yazıyordu, ders anlatılırken bunun `n-1` olması gerektiği söylendi.
  - `main` `fonk(3)`'ü çağırır; `fonk(3)` `fonk(2)`'yi, o da `fonk(1)`'i çağırır. `fonk(1)` base case'e düşer ve 1 döndürür. Her fonksiyon değerini kendisini çağıran yere döndürür: `fonk(2)` $1+1=2$, `fonk(3)` $1+2=3$ döndürür, `main` 3 yazdırır.
  - Döngü olmadığı için özyineleme "ucuz" görünür, ama her çağrının yerel değişkenleri yığına (stack) konur; çok derin çağrılar yığının dolmasına yol açabilir.
- Tasarımda iki soru
  - Base case nedir, yani çağrılar nerede duracak?
  - Yeni parametre ile önceki parametre arasındaki bağıntı nedir, yani problem nasıl bölünecek (bir azaltma, ona bölme, iki sayının farkı vb.)?
- Örnek 1: string uzunluğu (`strLen`) (ekrandan, 00:35:00)
  - Base case: gösterilen karakter `'\0'` (null) ise string boştur ve 0 döner. String için ayrılan yer (50) değil, `'\0'`'a kadar olan kısım sayılır.
  - Özyinelemeli kısım: `return 1+strLen(++str1);`. İşaretçi bir artırılarak bir sonraki karakterden başlayan daha kısa string gönderilir, geçilen karakter için 1 eklenir.
  - Ekrandaki 12 karakterlik girdi için çıktı `Lenght of your string is: 12` oldu.
- Örnek 2: bir sayının basamak sayısı (`countDigits`) (ekrandan, 00:45:00 ve 00:50:00)
  - Base case: sayı 0'dan büyük değilse 0 döner. Özyinelemeli kısım: sayı tam sayı bölmesiyle 10'a bölünerek yeniden çağrılır ve 1 eklenir ($239 \to 23 \to 2 \to 0$).
  - `1234567` girdisi için çıktı `7 Digits In Your Number` oldu.
- Örnek 3: 1'den $n$'ye kadar toplam (`sumOfNumber`) (ekrandan, 01:00:00)
  - Base case: `n1==1` ise 1 döner. Özyinelemeli kısım: `return n1+sumOfNumber(n1-1);`.
  - $n=3$ için $3+(2+1)=6$; $n=5$ için 15 bulundu.
- Örnek 4: EBOB (`EBOB`), çıkarmaya dayalı Öklid yöntemi (ekrandan, 01:10:00)
  - İki sayı eşitse EBOB sayının kendisidir; bu base case'tir. Eşit değillerse büyükten küçük çıkarılır ve fonksiyon yeni ikiliyle çağrılır.
  - Denemeler: (12, 3) ve (3, 12) için 3; (45, 15) için 15; (36, 45) için 9; (17, 3) için 1 (ekrandan, 01:15:00).
- Örnek 5: string'i ters yazdırma (`reverseStr`) (ekrandan, 01:25:00 ve 01:35:00)
  - Önce `char*` döndüren bir fonksiyon düşünüldü, sonra daha anlaşılır olduğu için `void` fonksiyon seçildi: fonksiyon bir şey döndürmez, yalnız yazdırır.
  - Karakter `'\0'` değilse fonksiyon `str1+1` ile çağrılır; çağrı döndükten sonra her çağrı kendi elindeki ilk karakteri (`*str1` ya da `str1[0]`) yazdırır. Böylece karakterler sondan başa doğru yazılır.
- İşaretçi hatırlatması
  - String bir karakter dizisidir; dizinin adı ilk elemanın adresidir. Bu yüzden `scanf("%s", str)` yazılırken `&` konmaz, `int` için `scanf("%d", &number)` yazılırken konur.
  - `ptr` adresi, `*ptr` o adresteki değeri verir. `int b=3;` için `&b`, `b`'nin adresidir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Doğru özyinelemeli fonksiyonun temeli base case'i doğru belirlemektir.
  - Çağrıların nerede duracağı iyi planlanmazsa fonksiyon durmaz. İkinci önemli karar problemin nasıl bölüneceğidir.
- Fonksiyon bildirimi (declaration) ve gerçekleme (implementation) ayrımı
  - Fonksiyonun imzası (signature) `main`'den önce bildirilir, gövdesi sonra yazılır. İmza iki yerde birebir aynı olmalıdır.
  - Böylece önce `main` tasarlanır, hangi fonksiyonların hangi parametrelerle kullanılacağı belli olur, gerçekleme sonraya bırakılabilir (modülerlik).
- Kendi fonksiyonlarınıza C'nin kütüphane fonksiyonlarıyla karışmayacak adlar verin (örneğin `strlen` yerine `strLen`).
- Farklı fonksiyonlarda aynı parametre ve yerel değişken adlarını kullanmayın; uzun programlarda karışıklığa yol açar (örneğin `str` yerine `str1`).
- Kopyala-yapıştır yerine kodu yeniden yazın; kopyalanan koddaki hata ileriye yayılır.
- Özyineleme ve işaretçi aritmetiğini kendiniz deneyerek öğrenin; birinin oklarla göstermesi kendi denemenizin yerini tutmaz.

## Kısa Tekrar Notları

- Özyinelemeli fonksiyon = base case + kendini değişmiş parametreyle çağıran kısım.
- Her çağrı değerini kendisini çağıran fonksiyona döndürür; sonuç geri dönüşte birikir.
- Her çağrının yerel değişkenleri yığına konur; çok derin özyineleme yığını doldurabilir.
- `strLen`: `'\0'` ise 0, değilse `1+strLen(++str1)`.
- `countDigits`: $n>0$ değilse 0, değilse `1+countDigits(n/10)`.
- `sumOfNumber`: $n=1$ ise 1, değilse `n+sumOfNumber(n-1)`.
- `EBOB`: eşitse sayının kendisi, değilse büyükten küçük çıkarılıp yeniden çağrılır.
- `reverseStr`: önce `str1+1` ile çağır, dönüşte `*str1` yazdır.
- Dizi adı adrestir; `scanf("%s", str)` içinde `&` yoktur.
- `*str1` ile `str1[0]` aynı karakteri verir.

## Detaylı Açıklamalar

- `fonk` örneğinde çağrı zinciri `main → fonk(3) → fonk(2) → fonk(1)` biçimindedir. `fonk(1)` 1 döndürünce `fonk(2)` bunu kendi 1'iyle toplayıp 2 döndürür, `fonk(3)` 3 döndürür ve `main` bunu yazdırır (ekrandan, 00:10:00).
- `strLen` örneğinde string, 50 karakterlik bir diziye `scanf("%s", str)` ile okunur (alternatif olarak `gets(str)` yorum satırında duruyordu). Fonksiyon `int strLen(char *str1)` olarak bildirilir. İlk derlemede çağrıda ad `srtLen` yazıldığı için `undefined reference` hatası alındı; düzeltilince program çalıştı (ekrandan, 00:35:00). Çağrılar her seferinde bir karakter kısalan string'i görür; 12 karakterlik girdide 13. çağrı yalnız `'\0'`'ı görür ve 0 döndürür, geri dönüşte birler toplanarak 12 elde edilir.

  ```c
  #include<stdio.h>

  int strLen(char *str1);

  int main()
  {
      char str[50];
      int len;
      printf("Enter Your String\n");
      scanf("%s",str);
      //gets(str);
      len=strLen(str);

      printf("Lenght of your string is: %d\n",len);

      return 0;
  }

  int strLen(char *str1)
  {
      if(*str1!='\0')
          return 1+strLen(++str1);
      return 0;
  }
  ```

  Bu kod `gcc -Wall` ile uyarısız derlendi; 12 karakterlik bir girdiyle 12 sonucu alındı.
- `countDigits` örneğinde base case `number1>0` değilse 0 döndürmektir. Sayı tam sayı bölmesiyle 10'a bölündükçe bir basamak düşer; 0'a ulaşıldığında durulur. İlk derlemede kodun altına yorum işareti konmadan yazılan `239 -> 23 -> 2 -> 0` satırı derleme hatası verdi (ekrandan, 00:50:00). Ekranda ilk yazılan `scanf("%d",number)` satırına `&` eklendi; neden string'de `&` konmadığı hatırlatıldı.
- `sumOfNumber` örneğinde çözüm "biri bana $n-1$'e kadar olan toplamı verirse ben de $n$'yi ekleyip döndürürüm" fikrine dayanır. İlk derlemede gövdede `n` yazıldığı için `'n' undeclared` hatası alındı, `n1` yapılınca düzeldi (ekrandan, 01:00:00).
- `EBOB` örneğinde fonksiyon `int EBOB(int n_1,int n_2)` olarak yazıldı. `while(n_1!=n_2)` koşulunun içinde büyükten küçük çıkarılarak `return EBOB(...)` yapılır; sayılar eşit olunca `return n_1;` çalışır (ekrandan, 01:10:00). Döngü gövdesi her durumda `return` ile bittiği için bu `while` burada bir `if` gibi davranır.
- `reverseStr` örneğinde fonksiyon `void reverseStr(char* str1)` olarak yazıldı. Karakter `'\0'` değilse `reverseStr(str1+1)` çağrılır; ardından `printf("%c",str1[0]);` gelir. Ekranda yorum olarak `*str1 = str[0]` yazıldı: iki gösterim aynı karakteri verir (ekrandan, 01:35:00). Sohbetten gelen bir öneriyle `*str1` yerine `str1[0]` yazılıp denendi ve aynı sonucun alındığı görüldü; bu yazımın değeri görmeyi kolaylaştırdığı söylendi. <!-- BELİRSİZ: Sohbetteki önerinin tam metni okunmuyor; kod değişikliğinden str1[0] önerisi olduğu çıkarıldı. -->
- İşaretçi soruları
  - `int *ptr;` bir tamsayı adresini tutar. `ptr` adresi, `*ptr` adresteki değeri verir. `*ptr`'ye değer atamak adresin içini değiştirir.
  - `*` işaretiyle değişken adı arasında boşluk olup olmaması fark etmez.

> **Ders sonrası not:** Derste $1$'den $n$'ye toplamın kapalı formülü "$n(n-1)/2$" diye söylendi; doğrusu $n(n+1)/2$'dir ($n=5$ için $15$).

> **Ders sonrası not:** `reverseStr` kodunda `printf` `if`'in dışında olduğu için base case çağrısı da `str1[0]` yani `'\0'` karakterini yazdırır. Ekranda görünmez, ama çıktıya fazladan bir null bayt girer (ajan `gcc -Wall` ile derleyip çıktıyı bayt bayt inceleyerek doğruladı). `printf` satırı `if` bloğunun içine alınırsa bu olmaz.

> **Ders sonrası not:** Derste adresin `%d` ile yazdırılabileceği söylendi ve derleyici `-Wformat` uyarısı verdi (ekrandan, 01:35:00). Adres yazdırmak için doğru biçim `%p`'dir. Ayrıca adres atanmamış bir işaretçinin (`int *ptr;`) gösterdiği yere `*ptr` ile yazmak tanımsız davranıştır; önce `ptr` geçerli bir adrese (örneğin `ptr=&b;`) bağlanmalıdır.

> **Ders sonrası not:** Derste `scanf("%s", str)` ile `gets(str)` arasında fark olmadığı söylendi. Aslında `scanf("%s", ...)` ilk boşlukta durur, `gets` bütün satırı okur. `gets` taşma denetimi yapmadığı için güvensizdir ve C11'de dilden kaldırılmıştır. Ayrıca `&str`, iki boyutlu dizi değil, 50 elemanlı dizinin tamamına işaretçidir (`char (*)[50]`); adres değeri `str` ile aynıdır, türü farklıdır.

> **Ders sonrası not:** `countDigits` 0 için 0 basamak döndürür ve negatif sayıları saymaz; 0'ın bir basamağı vardır. Derste yalnız pozitif girdiyle denendi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
