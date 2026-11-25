# Ders 27 Çalışma Özeti

## Genel Konular

- Diziye araya eleman ekleme (belirli bir indise)
  - Dizi `10, -20, 40, -10, 90, 50, 30, 45, 60` üzerinde 6. indise 55 değeri eklenir (ekrandan, 00:20:00).
  - Eleman sayısı `N` bir artırılır, sonra `i = N`'den `Pos`'a doğru geriye giden bir döngüyle `A[i] = A[i-1]` kaydırması yapılır, en sonda `A[Pos] = X` atanır.
  - Kaydırma soldan yapılırsa değerler ezilir; bu yüzden sondan başa doğru gidilir.
  - Dinamik bellek henüz bilinmediği için dizi baştan büyük açılır, gerçek eleman sayısı ayrı bir değişkende tutulur.
- Belirli bir değerden sonraya ekleme
  - Pozisyon doğrudan verilmez, bir anahtar değer (`key`) verilir. Önce `f = -1` ile başlanıp dizide `key` aranır, bulunursa `f = i` yapılır.
  - `f >= 0` ise `Pos = f + 1`, değilse eleman sona eklenir (`Pos = N`). Sonrası önceki ekleme algoritmasıdır.
- Tek geçişte en küçük iki elemanı bulma
  - Dizi `20, 30, 1, 20, 40, 9`, varsayım: eleman değerleri < 100 (ekrandan, 00:50:00).
  - `m1 = m2 = 1000` ile başlanır. `A[i] < m1` ise önce `m2 = m1`, sonra `m1 = A[i]`. Değilse `A[i] < m2` ve `A[i] != m1` ise `m2 = A[i]`.
  - Döngü sonunda `m2` hâlâ 1000 ise ikinci küçük eleman yoktur.
- C'de global ve yerel değişken
  - `main` dışında tanımlanan dizi global değişkendir; programın başından sonuna kadar bellekte yer tutar.
- Karakter sabitleri
  - Tek tırnak içinde yazılan tek karakter (`'a'`, `'G'`, `'<'`) karakter sabitidir.
  - `char` 1 bayt (8 bit) yer kaplar; bellekte karakterin ASCII kod tablosundaki sıra numarası tutulur (`'a'` = 97, `'A'` = 65, boşluk = 32).
  - `%c` karakteri, `%d` sayısal kodu yazdırır. `'a' + 1` = 98 = `'b'`.
- Ters bölü ile başlayan önceden tanımlı karakterler (kaçış dizileri)
  - `\a` (7, alarm), `\b` (8, backspace), `\f` (12, form feed), `\n` (10, new line), `\r` (13, carriage return), `\t` (9, tab), `\v` (11, vertical tab) (ekrandan, 01:30:00).
  - `\\` ters bölüyü, `\"` çift tırnağı yazdırır. `\0` ASCII 0, null karakterdir.
  - Karakter sabiti onaltılık (`'\x41'` = 65 = `'A'`) ya da sekizlik (`'\12'` = 10 = new line) kodla da verilebilir.
- Karakter dizileri (string)
  - `char y[10] = {'y','i','l','d','i','z','\0'};` gibi tek tek karakterlerle ya da `char u[] = "universitesi";` gibi çift tırnakla ilk değer verilir (ekrandan, 01:45:00).
  - Her karakter dizisi null karakterle (`'\0'`) bitmelidir. Tek tek verirken bunu koymak programcının sorumluluğudur; çift tırnakta derleyici kendisi ekler.
  - `%s` null karaktere kadar yazdırır. `n` elemanlı bir karakter dizisi en fazla `n-1` kullanılabilir karakter tutar.
- Hazır fonksiyonlar: `gets` ve `puts`
  - `gets` satırı okur ve sona `'\0'` koyar, ama dizi boyutunu denetlemez; taşma çalışma zamanında `stack smashing detected` hatasıyla programı kapatabilir.
  - `puts(s)`, `printf("%s\n", s)` ile denktir.
- Karakter dizisi örnekleri
  - Uzunluk bulma: `while (s[k] != '\0') k++;`
  - Ters çevirme: dizinin yarısına kadar `s[j]` ile `s[n-j-1]` yer değiştirir (`merhaba` → `abahrem`).
  - Harf frekansı: 26 (boşluk dahil 27) gözlü sayaç dizisi; her karakter için `counter[s[i]-'a']++`.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kaydırmada yön
  - Araya ekleme yapılırken sondan başa doğru kopyalanır; soldan başlanırsa sonraki değerler ezilip kaybolur.
- Tek geçiş şartı
  - En küçük iki eleman problemi sıralamadan ve iki ayrı minimum aramadan, tek döngüyle çözülmelidir. Sıralamak dizinin üzerinden en az iki kez geçmek demektir.
  - `m1` güncellenirken önce eski `m1` değeri `m2`'ye aktarılmalı; aksi halde kaybolur.
- Null karakterin sorumluluğu
  - Karakter dizisini elle (tek tırnakla ya da karakter karakter okuyarak) oluşturuyorsanız sona `'\0'` koymak sizin sorumluluğunuzdur. Konmazsa `printf` bellekte ilk `'\0'` görene kadar yazmaya devam eder.
- Kaçış karakterlerinde okunabilirlik
  - Alarm karakteri `'\a'`, `'\x07'` ya da `'\07'` diye yazılabilir; hoca okunaklı olduğu için `'\a'` biçimini tercih ediyor.
- `gets` tehlikelidir
  - Derleyici uyarı verir; dizi boyutundan uzun girdi çalışma zamanında hataya yol açar.
- Okunabilir döngü
  - Uzunluğu `for(n=0; s[n]; n++);` gibi tek satırla bulmak mümkündür ama önerilmez; `while` döngüsü daha okunaklı ve akış diyagramına daha uygundur.
- Akış diyagramında indis
  - Akış diyagramında döngüler genel çözüm için 1'den N'e yazılır; C'de karşılığı 0'dan N-1'e kadardır.
- Akış diyagramında oklar
  - Oklar her zaman çizilmelidir.

## Kısa Tekrar Notları

- Araya ekleme: `N = N+1`; `for (i=N; i>pos; i--) a[i] = a[i-1];` sonra `a[pos] = x;`.
- Değerden sonra ekleme: önce ara (`f`), bulunursa `pos = f+1`, bulunamazsa sona ekle.
- En küçük iki eleman: `m1 = m2 = büyük değer`; `a[i] < m1` → `m2 = m1; m1 = a[i];` değilse `a[i] < m2 && a[i] != m1` → `m2 = a[i];`.
- C'de gerçek "en büyük değer" için `limits.h` başlık dosyasındaki en büyük `int` değeri (max int) kullanılabilir.
- Global değişken bütün fonksiyonlardan erişilebilir, program boyunca bellekte kalır; mümkünse yerel değişken kullanılır.
- Dizi ilk değer atamasında küme parantezinden sonra `;` zorunludur.
- `char` = 8 bit sayı; `'a'` = 97, `'A'` = 65, `'a'+1` = `'b'`.
- Kaçış dizileri: `\a` 7, `\b` 8, `\t` 9, `\n` 10, `\v` 11, `\f` 12, `\r` 13, `\0` 0; `\\`, `\"`.
- `'\x..'` onaltılık, `'\...'` sekizlik kod.
- Karakter dizisi `'\0'` ile biter; çift tırnaklı sabitte derleyici ekler.
- `%s` null karaktere kadar yazar; dizi boyutu küçük verilirse taşma ve beklenmedik çıktı olur.
- `gets` okur ve `'\0'` ekler ama sınır denetlemez; `puts(s)` = `printf("%s\n", s)`.
- Uzunluk: null karaktere kadar say. Ters çevirme: `n/2` adım, `s[j]` ↔ `s[n-j-1]`.
- Harf frekansı: `counter[s[i]-'a']++`.

## Detaylı Açıklamalar

- Diziye araya eleman ekleme
  - Dizi `10, -20, 40, -10, 90, 50, 30, 45, 60` (9 eleman) ve 6. indise 55 eklenmek isteniyor. Akış diyagramında `N` gerçek eleman sayısı, `M` dizinin bellekte ayrılan boyu, `X` yeni değer, `Pos` hedef indistir (ekrandan, 00:35:00).
  - Akış: START → `N, M, A[M], X, Pos` oku → `N = N + 1` → döngü (`i = N`'den `Pos`'a, adım `-1`): `A[i] = A[i-1]` → döngüden sonra `A[Pos] = X` → STOP.
  - Derste yazılan kod (ekrandan, 00:30:00):

```c
#include <stdio.h>
#define N 9

int a[N]= {10, -20, 40, -10, 90, 50, 30, 45, 60};

int main()
{
    int i, x=55, pos=6;

    for (i=N; i>pos; i--)
        a[i] = a[i-1];

    a[pos] = x;

    for (i=0;i<N+1; i++){
        printf("%d ",a[i]);
    }

    return 0;
}
```

  - Yazdırma döngüsü önce `i=N+1` (atama) diye yazıldığı için program sonsuz döngüye girdi; `i<N+1` olarak düzeltildi. Çıktı: `10 -20 40 -10 90 50 55 30 45 60`.
  - `#define N 9` bir önişlemci tanımıdır: kodda `N` görülen her yerde 9 kullanılır; bu sayede dizi boyutu `N` ile verilebilir.
  - Ders sonrası not: Hoca dizinin bir göz fazlasıyla açıldığını söyledi; ama `int a[N]` (N = 9) tam 9 gözlüdür ve `a[9]`'a yazmak dizinin dışına taşar (tanımsız davranış). Doğrusu diziyi `int a[N+1]` ya da daha büyük açmaktır. `a[N+1]` ile yazılan sürüm `gcc -Wall` ile derlendi ve aynı çıktıyı verdi (ajan tarafından test edildi).
- Global değişken
  - Dizi `main`'in dışında tanımlandığı için globaldir: her fonksiyondan erişilebilir, derleyici yerini baştan ayırır ve program bitene kadar bellekte kalır. Yerel değişken ise yalnız fonksiyon çalıştığı sürece yer tutar. Çok sayıda modülün ortak veriye erişmesi gerektiğinde işe yarar, ama gereksiz kullanıldığında bellek ayak izini büyütür.
- Belirli bir değerden sonraya ekleme
  - Örnek: 50 değerinden sonraki göze ekle. `key` okunur, `f = -1` yapılır, `i = 1..N` için `A[i] = key` ise `f = i` atanır (ekrandan, 00:35:00).
  - Döngüden sonra `f >= 0` ise `Pos = f + 1`, değilse `Pos = N` (sona ekleme). Sonra kaydırma ve atama aynıdır.
  - Arama `while` ile bulununca çıkacak şekilde daha verimli yazılabilir; derste yer darlığından `for` kullanıldı.
- En küçük iki elemanı tek geçişte bulma
  - Akış (ekrandan, 00:50:00): START → `N, A[N]` oku → `m1 = 1000, m2 = 1000` → döngü `i = 1..N`: `A[i] < m1` ise (T) `m2 = m1; m1 = A[i]`; (F) ise `A[i] < m2` ve `A[i] ≠ m1` mi? (T) `m2 = A[i]`. Döngüden sonra `m2 = 1000` ise "ikinci küçük yok" ve yalnız `m1` yazdırılır, değilse `m1` ve `m2` yazdırılır → STOP.
  - Elle izleme (`20, 30, 1, 20, 40, 9`): 20 → `m1=20, m2=1000`; 30 → `m2=30`; 1 → `m2=20, m1=1`; 20 → değişmez (20 < m2 değil); 40 → değişmez; 9 → `m2=9`. Sonuç `m1 = 1, m2 = 9`.
  - `A[i] ≠ m1` şartı aynı en küçük değerin tekrarının `m2` olarak alınmasını engeller. Bütün elemanlar eşitse (`20, 20, ...`) `m2` 1000'de kalır ve ikinci küçük eleman yok denir.
  - Kodda kullanılan dizi (ekrandan, 00:55:00 ve 01:00:00):

```c
#include <stdio.h>

int main()
{
    int a[] = {20, 30, 1, 10, 40, 9};
    int n = 6;
    int i, m1=1000, m2=1000;

    for (i=0; i<n; i++){
        if(a[i]<m1){
            m2=m1;
            m1=a[i];
        }
        else if(a[i]<m2 && a[i]!=m1)
            m2=a[i];
    } //for i

    if(m2==1000)
        printf("ikinci kucuk eleman yok, min1:%d \n",m1);
    else
        printf("1.kucuk: %d  2.kucuk:%d \n",m1,m2);

    return 0;
}
```

  - Çıktı: `1.kucuk: 1  2.kucuk:9`. Son eleman 1 yapılınca `1` ve `10`, bütün elemanlar 20 olunca `ikinci kucuk eleman yok, min1:20` çıktı. Kod `gcc -Wall` ile derlenip bu üç girdiyle çalıştırıldı (ajan tarafından test edildi).
  - Diziyi kullanıcıdan okumak için `int a[6];` tanımlanıp `for` içinde `printf("%d. elemanı girin:\n", i); scanf("%d", &a[i]);` yazıldı (ekrandan, 01:05:00).
- Karakter sabitleri ve ASCII
  - `char ch; ch = 'a'; printf("%c %d", ch, ch);` → `a 97`. `ch = 'a' + 1;` → `b 98` (ekrandan, 01:20:00 ve 02:05:00).
  - `char` 8 bitlik (işaretli, -128..127) bir sayıdır; karakter görüntüsü yalnızca kod tablosu varsayımıdır. Bu yüzden karakterler üzerinde aritmetik yapılabilir.
- Kaçış dizileri
  - `\` kaçış karakteridir; arkasından gelen harfin özel anlamda kullanıldığını belirtir. `\a` anakarttaki buzzer'dan bip sesi çıkarır. `\b` bir karakter geri gider, sonraki karakter öncekinin yerine yazılır. `\r` aynı satırın başına döner; bazı yazıcılarda satır sonu `\r\n` olarak kullanılır, Linux türevlerinde `\n` yeterlidir. `\t` sekme boşluğu verir. `\v` dikey sekmedir, pek kullanılmaz.
  - `printf("\"Hello\\ \\World\"")` çıktısı `"Hello\ \World"` olur (ekrandan, 01:35:00).
  - Onaltılık: `'\x41'` → `A 65`; `'\x1d'` → 29 (ekranda gösterilemeyen karakter); `'\xF1'` → ekranda bir sembol ve `-15` (ekrandan, 01:50:00).
  - Sekizlik: `'\12'` → 10, yani new line. `'\a'`, `'\x07'`, `'\07'` aynı karakteri (7) gösterir.
  - <!-- BELİRSİZ: Hoca sekizlik 123 örneğini denerken bir hata yaptı; ekranda `+ 43` çıktısı görünüyor (01:55:00). Hangi sabitin yazıldığı karede okunmuyor. -->
- Karakter dizileri
  - `char y[10] = {'y','i','l','d','i','z','\0'};` 10 gözlük yere 6 karakter ve null koyar. `char t[] = {'t','e','k','n','i','k','\0'};` boyutu ilk değerlerden (7) belirlenir. `char u[] = "universitesi";` çift tırnakla verilir, `'\0'` derleyicice eklenir (ekrandan, 01:40:00 ve 01:45:00).
  - `printf("%s %s %s \n", y, t, u);` → `yildiz teknik universitesi`.
  - `t` dizisinde `'\0'` unutulursa `printf` bellekte ilk null karaktere kadar yazmaya devam eder; derste önceki çıktılardan kalan karakterler de yazdırıldı.
  - `u[3]` gibi küçük boyut verilince derleyici uyarı verdi (ekranda `initializer-string for array of chars is too long`), dizi `uni` ile kaldı ve null olmadığı için arkasından başka veri yazdırıldı (çıktı `uniteknik`, ekrandan, 01:45:00). Boyut 30 verilince sorun olmadı ama 30 bayt yer ayrıldı.
  - Null karakter sayesinde dizinin uzunluğunu ayrıca bilmek gerekmez; string alan fonksiyonlara boyut göndermek gerekmez. Bedeli her zaman bir bayttır: `n` elemanlı dizi en fazla `n-1` karakter tutar.
- `gets` ve `puts`
  - `char aa[20]; printf("adınızı giriniz:"); gets(aa);` ve `while (aa[i] != '\0')` döngüsüyle karakterler tek tek yazdırıldı (ekrandan, 01:55:00). `gets` null karakteri kendisi ekler.
  - Dizi 10 ya da 5 gözlü yapılıp uzun bir kelime girilince program `stack smashing detected` ile sonlandı. Boşluklu girdi, rakam ve semboller de karakter dizisine alınır.
  - `puts(aa);` ile `printf("%s\n", aa);` denktir (ekrandan, 02:00:00).
- Karakter dizisini okuma akışı
  - Akış (ekrandan, 02:05:00): START → `i = 0` → `i = i + 1` → `ch[i]` oku → `ch[i] ≠ '\0'` ise başa dön, değilse `ch` artık karakter dizisi olarak kullanılabilir. C gibi düşünülürse başlangıç `i = -1` alınabilir.
- Uzunluk ve ters çevirme
  - Uzunluk: `while (s[k] != '\0') k++;` `merhaba` → 7, `merhaba dostum` → 14.
  - Ters çevirme (ekrandan, 02:15:00): `merhaba`, `n = 7`, `n div 2 = 3` adım: `merhaba` → `AerhabM` → `ABrhaEM` → `abahrem`. Tek uzunlukta ortadaki eleman yerinde kalır.

```c
for(j=0; j<n/2; j++){
    temp = s[j];
    s[j] = s[n-j-1];
    s[n-j-1] = temp;
}
puts(s);
```

  - `teknik` → `kinket`. Tam program (uzunluk + ters çevirme) `gets` yerine `fgets` ile ajan tarafından derlenip denendi; derste `gets` kullanıldı.
- Harf frekansı (sayaç dizisi)
  - Metin: `hello friends what are you doing`, küçük İngilizce harfler (ekrandan, 02:25:00).
  - Adımlar: 1) diziyi oku, 2) uzunluğunu bul, 3) döngü içinde her karakter için sayaç dizisinin ilgili gözünü 1 artır, 4) sayaç dizisini yazdır. Sayaç başta sıfırlanır; istenirse boşluk için 27. göz eklenir.
  - `'b' - 'a'` = 98 - 97 = 1 olduğundan `counter[s[i]-'a']++` harfi doğrudan indise çevirir (ekrandan, 02:30:00). Boşluk (32) için ayrı kontrol gerekir.
  - Bu örneğin kodu derste yazılmadı; hoca alıştırma olarak bıraktı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
