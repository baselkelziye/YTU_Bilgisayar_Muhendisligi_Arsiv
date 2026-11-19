# Ders 13 Çalışma Özeti

## Genel Konular

- Uygulama dersinin yapısı
  - Bu kayıt, öğretim elemanının yürüttüğü bir uygulama (laboratuvar) oturumudur. Önceki laboratuvarlarda sorulmuş iki problem, hazır C kodları üzerinden anlatıldı: matris tabanlı bir metin şifreleme/çözme algoritması ve Eratosthenes Kalburu (Sieve of Eratosthenes) ile asal sayı bulma.
  - İki problemin ortak konusu dinamik bellek yönetimidir (`malloc`, `calloc`, `realloc`, `free`). Ekrandaki ikinci belgenin adı "Yapısal Programlama Lab 1 (Memory Allocation, loops, if&else statements)" idi (ekrandan, 00:35:00).
- Problem 1: Metni MxM'lik bir "image" matrisine gömmek (ekrandan, 00:05:00)
  - Harflerin ASCII karşılıkları MxM bir matrise yazılır. Her hücre 0-255 arasında bir piksel değeridir; 0 o pikselde harf olmadığı anlamına gelir. Kelimenin ilk harfi `[0][0]`, ikincisi `[0][1]` hücresine konur. Stringin uzunluğunun önceden bilinmediği varsayılır.
  - Örnek: `"YILDIZTEKNIK"` (12 harf) için matris `89 73 76 68 / 73 90 84 69 / 75 78 73 75 / 0 0 0 0` olur (ekrandan, 00:05:00).
  - Matrisin tam kare olması için kenar uzunluğu `m = ceil(sqrt(textSize))` ile bulunur. 13 karakterlik `YILDIZ TEKNIK` için $\sqrt{13} \approx 3{,}6$ yukarı yuvarlanır, 4x4 matris oluşur.
- Şifreleme kodu (`encryption.c`) (ekrandan, 00:10:00 ve 00:45:00)
  - Kullanıcıdan önce metnin uzunluğu, sonra metin alınır. `text` için `malloc` ile `textSize` karakterlik yer ayrılır.
  - `scanf("%c",&junk);` önceki `scanf`'ten kalan Enter (`'\n'`) karakterini "çöpe atar". `scanf("%[^\n]",text);` satır sonuna kadar (boşluklar dahil) okur; `^` "değil" anlamındadır, yani "yeni satır olmadıkça al".
  - Matris `int **theImage` ile tutulur. Başta `calloc` ile bir satır işaretçisi ve bir `int` ayrılır, sonra döngüde `realloc` ile dış dizi `(i+1)` işaretçiye, her satır `(j+1)` tamsayıya büyütülür. `pixel = (int)text[k];` ile ASCII değeri matrise yazılır; metin bittiğinde hücreye 0 yazılır.
  - Ayrılan yerler program sonunda `free` ile bırakılır.
- `-lm` bağlama hatası (ekrandan, 00:15:00)
  - `gcc encryption.c` komutu `undefined reference to 'sqrt'` ve `'ceil'` hatası verdi. `math.h` include edilse de GCC'de matematik kütüphanesinin bağlanması için `-lm` verilmesi gerekir: `gcc encryption.c -lm`.
- `ceil`, `floor`, `round`
  - `ceil` en yakın üst tam sayıya, `floor` en yakın alt tam sayıya, `round` en yakın tam sayıya yuvarlar (4,6 yukarı, 4,4 aşağı).
- Şifre çözme kodu (`decryption.c`) (ekrandan, 00:20:00)
  - Bu kez matrisin boyutu (M) bilinir ama metnin uzunluğu bilinmez, çünkü kaç tane 0 olduğu baştan bilinmez. Metin için başta yalnız bir karakterlik yer ayrılır, matris için MxM yer ayrılır.
  - Pikseller (dosyadan okumak C'de zor olduğu için) sol üstten sağ alta tek tek klavyeden girilir. Her piksel `(char)` ile karaktere dönüştürülüp metne eklenir, `textIndex` artırılır.
  - Derste `89 73 76 68 73 90 32 84 69 75 78 73 75 0 0 0` girilince çıktı `The Text That Was Hidden Into The Image is: YILDIZ TEKNIK` oldu (ekrandan, 00:25:00).
- Problem 2: Eratosthenes Kalburu (`findPrimes.c`) (ekrandan, 00:25:00 - 00:40:00)
  - Amaç n'ye kadar olan bütün asal sayıları bulmaktır. Önce bütün sayılar asal kabul edilir; listenin en küçük asalı alınır ve katları elenir, sonra işaretlenmemiş bir sonraki sayıya geçilir. Bu yüzden "elek" (sieve) denir.
  - Örnek n = 10: 2 alınır ($2^2 \le 10$), 4, 6, 8, 10 elenir; 3 alınır ($3^2 \le 10$), 9 elenir; geriye 2, 3, 5, 7 kalır (ekrandan, 00:35:00).
  - Kodda `n -= 1;` yapılır, çünkü 1 asal değildir ve dizi 2'den başlar; `prime_states` dizisinin `i`. elemanı `i+2` sayısını temsil eder.
  - `prime_states` `char` dizisidir: `char` 1 bayt olduğu için 1 (true) ve 0 (false) saklamak için yeterlidir. Bellek ayrılamazsa hata mesajı verilip `exit(0)` ile çıkılır.
  - Dış döngü `(i+2)*(i+2) <= n+1` koşuluyla döner. Asal olarak işaretli sayının karesinden başlayan iç döngü `j += i+2` adımıyla katları gezer ve `prime_states[j-2] = 0` yapar.
  - Sonra 1 olanlar sayılır (`prime_count`), o kadar `int`'lik `primes` dizisi ayrılır, asallar bu diziye kopyalanır ve onar onar yazdırılır.
  - `setlocale(LC_ALL, "Turkish")` Türkçe karakterleri yazdırmak için kullanılır. Boolean için `stdbool.h` kütüphanesi de kullanılabilir.
- Bellek ayırma fonksiyonlarının özeti
  - `malloc(sizeof(char)*textSize)`: textSize karakterlik yer. `calloc(1,sizeof(int*))`: bir tamsayı adresi saklayacak kadar yer. `calloc(1,sizeof(int))`: bir tamsayılık yer.
  - `realloc` elde olan alanı büyütür: her adımda "artık iki, artık üç, artık dört tane istiyorum" denir. Sonunda MxM matris, her biri M tamsayıdan oluşan M dizi ve bu dizilerin adreslerini tutan bir üst dizi demektir.

## Hocanın Özellikle Vurguladığı Kısımlar

- `free` ile belleği işletim sistemine geri vermek
  - Ayrılan yerler program bitmeden `free` ile bırakılmalıdır. Öğretim elemanı kaynakların her zaman önemli olduğunu, bırakılmayan alanların başka programlar için sorun çıkarabileceğini söyledi.
- `math.h` kullanınca `-lm`
  - GCC'de matematik fonksiyonları kullanılıyorsa derleme komutuna `-lm` eklenmezse bağlayıcı (linker) hatası alınır.
- Kalburda karekökten sonrasına bakmaya gerek yok
  - $n = a \cdot b$ biçiminde çarpanlara ayrılan bir sayıda çarpanlardan biri $\sqrt{n}$'den küçük ya da eşittir. Bu yüzden $a^2 \le n$ olan asallara bakmak yeterlidir.
- Eleme neden karesinden başlar
  - En küçük asaldan başlandığı için bir asalın karesinden küçük katları daha önce daha küçük bir asal tarafından elenmiştir (örneğin 6, 3'e gelindiğinde 2 tarafından zaten elenmiştir).

## Kısa Tekrar Notları

- Metin şifreleme: harfler ASCII değeriyle MxM matrise yazılır, boş hücre 0'dır, `m = ceil(sqrt(uzunluk))`.
- `scanf("%c",&junk)` artık Enter'ı temizler; `scanf("%[^\n]", s)` boşluklu bir satırı okur.
- `int **` ile dinamik 2B dizi: önce satır işaretçileri dizisi, sonra her satır için tamsayı dizisi.
- `realloc(p, yeniBoyut)` bloğu büyütür; boyut her adımda bayt olarak verilir (`(j+1)*sizeof(int)`).
- `ceil` yukarı, `floor` aşağı, `round` en yakına yuvarlar.
- `math.h` + GCC = `-lm`.
- Şifre çözmede `(char)piksel` ile karakter elde edilir.
- Kalbur: hepsini asal işaretle, $p^2 \le n$ olan her asal p için $p^2$'den başlayıp p adımla katları ele.
- İndeks kaydırma: `prime_states[i]` sayısı `i+2`'yi temsil eder.
- Her `malloc`/`calloc`/`realloc` sonunda `free` ile bırakılır.

## Detaylı Açıklamalar

- Şifreleme programının akışı
  - Program önce metnin uzunluğunu `scanf("%d",&textSize)` ile alır. Bu çağrıdan sonra girdi tamponunda Enter karakteri kalır; bir sonraki okuma bu karakterle hemen biterdi. Bu yüzden önce `scanf("%c",&junk)` ile bu karakter okunup atılır. Öğretim elemanı satır okumak için `fgets` ve `gets` gibi başka yolların da bulunduğunu, ama her derleyicide aynı davranmayabileceklerini söyledi.
  - `m = ceil(sqrt(textSize))` ile kare matrisin kenarı bulunur. `sqrt` `double` döndürdüğü ve sonuç genelde tam sayı olmadığı için yukarı yuvarlanır. 12 karakterlik bir metin 2x6 da yapılabilirdi, ama görüntü olacağı için kare tercih edildi.
  - Derste `13` ve `YILDIZ TEKNIK` girildiğinde çıktı (ekrandan, 00:20:00):

```text
89 73 76 68
73 90 32 84
69 75 78 73
75 0 0 0
```

  - 32 boşluk karakterinin ASCII değeridir; diğerleri harflerin karşılıklarıdır (Y=89, I=73, L=76, D=68, Z=90, T=84, E=69, K=75, N=78).
- Şifre çözme
  - M=4 girilip 16 piksel değeri tek tek verildi. Her değer `(char)` ile karaktere çevrilip metnin sonuna eklendi. Karedeki döngü (ekrandan, 00:20:00):

```c
for (i=0;i<m;i++)
{
    for(j=0;j<m;j++)
    {
        text=(char*)(realloc)(text,sizeof(char));
        text[textIndex]=(char)theImage[i][j];
        textIndex++;
    }
}
```

- Ders sonrası not (kodlardaki bellek hataları; öğretim elemanı bunlara değinmedi)
  - Şifre çözme döngüsünde `realloc(text, sizeof(char))` bloğu her seferinde yalnız 1 bayta ayarlar. Öğretim elemanı "her karakter geldiğinde bir tane büyütüyoruz" dedi; bunun için boyutun `(textIndex+1)*sizeof(char)` (sondaki `'\0'` için bir fazlası) olması gerekir. Derste program doğru çıktı verdi, ama bu tanımsız davranıştır ve büyük olasılıkla şans eseri çalışmıştır.
  - Şifreleme kodunda `text` için `textSize` bayt ayrılır, ama `scanf("%[^\n]",text)` sona `'\0'` da yazar; 13 karakterlik metin 14 bayt yazar. Ajan AddressSanitizer ile bu taşmayı doğruladı. `textSize+1` bayt ayrılmalıdır.
  - Aynı kodda `if(k>textSize)` denetimi `text[k]` okunduktan sonra yapılır ve sınır `k >= textSize` olmalıdır. Ayrıca dış dizi `realloc` ile büyütüldüğünde yeni `theImage[i]` gözü ilk değer almadan `realloc`'a verilir; güvenli olması için önce `theImage[i] = NULL;` yapılmalıdır.
- Kalburun kodu ve çıktısı
  - Karedeki ana döngüler (ekrandan, 00:30:00):

```c
for(i = 0; (i + 2)*(i + 2) <= n+1; i++)
{
    if(prime_states[i] == 1) // 1 = true
    {
        for(j = (i + 2)*(i + 2); j <= n+1; j += i+2 )
        {
            prime_states[j-2] = 0; // 0 = false
        }
    }
}
```

  - `i = 0` iken sayı 2'dir: j = 4, 6, 8, 10 elenir. `i = 1` iken sayı 3'tür: j = 9 elenir, sonraki 12 sınırı aşar.
  - Derste n = 80 girildi; ekranda "0-80 arasındaki asal sayılar" başlığı altında 2'den 71'e kadar 20 asal göründü (ekrandan, 00:40:00).
  - Ders sonrası not: 80'e kadar 22 asal vardır; 73 ve 79 ekrandaki çıktıda görünmüyor. Yazdırma döngüsü karede görünmediği için nedeni bilinmiyor. <!-- BELİRSİZ: yazdırma kodu karede yok; 73 ve 79'un neden çıkmadığı belirlenemedi -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
