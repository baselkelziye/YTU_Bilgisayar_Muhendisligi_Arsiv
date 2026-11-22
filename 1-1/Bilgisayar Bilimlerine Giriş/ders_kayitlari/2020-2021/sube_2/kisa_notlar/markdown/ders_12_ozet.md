# Ders 12 Çalışma Özeti

## Genel Konular

- Dizide verilen değere sahip tüm elemanları bulmak
  - Problem: `N` elemanlı `A` dizisinde, dışarıdan verilen `X` değerine sahip tüm elemanları bulan algoritmanın akış diyagramı. Örnek dizi `3, 5, 7, 11, 8, 7, 6, 5` (ekrandan, 00:20:00).
  - Hoca örneğe 5 ile başladı, sonra 5'in üstünü çizip "verilen" yazdı: aranan değer sabit değildir, kullanıcıdan okunur. Girdi kutusu `N, A(N), X` olur.
  - Bütün elemanlara bakılması gerekir. Bu yüzden adım sayısı belli olan for döngüsü kullanılır: `I ← 1 || 1`, bitiş `N`. Gövdede `A(I) = X` sorulur; doğruysa `I` yazdırılır, yanlışsa döngü devam eder (ekrandan, 00:25:00).
  - Bir elemanı dizide tanımlayan şey konumudur. "Elemanları bul" denince eleman sayısı değil, konumları (indisleri) istenir. Sayaç tutup sonunda kaç tane olduğunu yazdırmak bu soruya cevap değildir.
- Akışın analizi
  - `N = 8`, `X = 5` için izleme: `I = 2` ve `I = 8`'de eşitlik var, çıktı 2 ve 8 (ekrandan, 00:30:00).
  - `X = 15` için akış hiçbir çıktı üretmeden biter. "İstenilen değer dizide bulunmamaktadır" gibi bir mesaj yoktur.
  - Bir öğrencinin önerisi: `T` kolunda bir sayacı artırmak, döngüden sonra sayacın 0 olup olmadığını sorup 0 ise "yok" yazdırmak. Hoca bunu makul buldu.
- Dizide bir değerin olup olmadığını bulmak
  - Bu sefer yalnız "var mı" sorulur. Birden fazla geçiş önemli değildir. Eleman bulunursa aramayı kesmek mümkündür; en kötü durum, eleman dizide yokken bütün dizinin dolaşılmasıdır.
  - Adım sayısı belli olmadığı için koşullu döngü kullanılır (ekrandan, 00:45:00 ve 00:50:00):
    - `I = 1` ile başlanır (çizimde bilerek `I = 0` yazılmıştı; diziler 1'den başladığı için doğrusu `I = 1`).
    - Koşul `I <= N AND A(I) ≠ X` doğru oldukça `I = I + 1`.
    - Döngüden sonra `I > N` sorulur: `T` ise "YOK", `F` ise "VAR" yazdırılır.
  - AND iki koşulun birlikte sağlanmasını ister. Koşullardan biri sağlanmayınca döngüden çıkılır. Eleman yoksa `I` en sonda `N + 1` olur, bu yüzden çıkışta `I > N` kontrol edilir.
  - Akış diyagramında mantıksal operatörler AND ve OR olarak yazılır.
- İkili arama (binary search) üzerine
  - Bir öğrenci daha hızlı bulmak için ikili arama kullanılıp kullanılamayacağını sordu. İkili arama yalnız sıralı dizide çalışır; soruda dizinin sıralı olduğu söylenmediği için kullanılamaz.
- Matris
  - Matris iki boyutlu dizidir. Birinci indis satırı, ikinci indis sütunu gösterir. 4. satır 5. sütundaki elemana `M(4)(5)` ile erişilir.
  - Harita bilgisi ve görüntüler matrisle tutulabilir. İki boyutlu resimler matris biçimindedir.
  - Matris okuma: önce boyutlar `N, M` okunur. Sonra `I ← 1..N` dış döngüsü içinde `J ← 1..M` iç döngüsüyle `A(I)(J)` tek tek okunur. Her satır aslında bir dizidir. Kısa gösterim: `N, M, A(N)(M)`, önce boyutlar sonra matris (ekrandan, 01:05:00).
- Örnek: matrisin satır toplamlarını yeni bir diziye aktarmak
  - Soru (ekrandan, 01:15:00): "Verilen bir matrisin satırlarının toplamını yeni bir diziye aktaran algoritmaya ait akışı çiziniz." Satır numarası ile yazılacağı dizi gözünün numarası aynı olmalıdır.
  - Son akış (ekrandan, 01:30:00 ve 01:35:00): `N, M, A(N)(M)` okunur. `I ← 1..N` döngüsünde önce `SUM = 0`, sonra `J ← 1..M` döngüsünde `SUM = SUM + A(I)(J)`, iç döngü bitince `B(I) = SUM`. En sonda ayrı bir `I ← 1..N` döngüsüyle `B(I)` yazdırılır.
  - İlk çizimdeki hatalar: `SUM = 0` dış döngüden önceydi, bu yüzden her satırda sıfırlanmıyordu; çıktıda `SUM` yazdırılıyordu, doğrusu `B(I)`.
  - Analiz: `N = 4`, `M = 5`, satırlar `1..5`, `6..10`, `11..15`, `16..20`. Birinci satır toplamı 15, ikinci 40, üçüncü 65 (ekrandan, 01:40:00 ve 01:45:00). Dördüncü satır derste izlenmedi; toplamı 90'dır (python ile kontrol edildi).

## Hocanın Özellikle Vurguladığı Kısımlar

- Sorunun ne istediğini anlamak
  - "Tüm elemanları bul", "kaç tane var" ve "var mı" farklı sorulardır ve farklı akışlar ister. Önce soru iyice irdelenmeli, şartları sağlanmalı; hızlandırma ondan sonra düşünülür.
- Analiz akış çizmenin parçasıdır
  - Analizde akıştaki değişkenler ve durumları adım adım izlenir. Analiz son değere kadar yılmadan yapılmalı; örnekler farklı durumları (aranan değerin olduğu ve olmadığı durumlar gibi) deneyecek şekilde seçilmeli.
- Net ifade
  - "O döngü", "şu ok" gibi muğlak ifadeler yerine referans noktaları kullanılmalı: "`I` birden `N`'e kadar olan döngü", "`J` birden `M`'e kadar olan döngü".
- Döngü değişkenini yeniden kullanmak
  - Birbirinden bağımsız (ardışık) döngülerde aynı döngü değişkeni tekrar kullanılabilir, çünkü for kutusu ilk değeri yeniden atar. İç içe döngülerde aynı değişken kullanılamaz.
- İndis ve değişken adları
  - `I, J, K, L` genelde indis olarak, `A, B, C` ve `X, Y, Z` değişken ve dizi adı olarak kullanılır (ekrandan, 01:30:00).
- Geçici değişken
  - `SUM` yerine doğrudan `B(I)` üzerinde toplamak çalışır, ama dizi elemanına erişim başlangıç adresinden indis kadar ilerleyerek hesaplanır ve tek bir değişkene erişmekten pahalıdır. Çok tekrarlanan erişimde geçici değişken daha verimlidir.
- Matris koordinat sistemi değildir
  - Matriste satır indisi aşağı doğru artar. Kartezyen koordinat sistemine oturtmak için yapıyı ters çevirmek gerekir; ikisi ayrı tutulmalıdır.

## Kısa Tekrar Notları

- Bütün elemanlara bakılacaksa for döngüsü, koşul sağlanınca durulacaksa koşullu döngü.
- Elemanı tanımlayan konumudur; "elemanları bul" indisleri yazdırmak demektir.
- `I <= N AND A(I) ≠ X` döngüsünden sonra `I > N` ise eleman yok.
- Diziler 1'den başlar; `I = 0` ilk değeri hatalıdır.
- İkili arama yalnız sıralı dizide çalışır.
- Matris `A(N)(M)`: `N` satır, `M` sütun; `A(I)(J)` `I`. satır `J`. sütun.
- Satır toplamı için `SUM = 0` her satırın başında, dış döngünün içinde yapılır.
- Ekrana yazılan çıktı, ekran temizlenmedikçe kaybolmaz.
- Bağımsız döngülerde aynı indis tekrar kullanılabilir, iç içe döngülerde kullanılamaz.

## Detaylı Açıklamalar

- Tüm elemanları bulma akışında döngü `I ← 1 || 1` ile başlar ve `N`'e kadar gider. Her adımda `A(I) = X` sorulur. Doğru kolunda `I` ekrana yazdırılır; hoca konumların istenirse ayrı bir dizide de saklanabileceğini söyledi. Örnek dizide `X = 5` için çıktı 2 ve 8'dir. `X = 15` için akış sessizce biter. Bir öğrenci, döngüden sonra ekrandaki 2'nin silinip silinmeyeceğini sordu. Hoca, ekran tamponu temizlenmedikçe önceki çıktıların kaybolmadığını, terminalde bir komutun çıktısının sonraki komutu yazınca da görünmeye devam ettiğini hatırlattı.
- Var/yok akışında koşullu döngü kullanmanın nedeni aramayı erken kesebilmektir. Koşul iki parçalıdır ve AND ile bağlanır: indis sınır içinde olmalı ve o anki eleman aranan değere eşit olmamalı. Eşit eleman bulununca ikinci koşul bozulur ve döngüden çıkılır; o anda `I ≤ N`'dir ve sonuç "VAR"dır. Eleman hiç yoksa `I` son adımda `N + 1` olur, birinci koşul bozulur ve sonuç "YOK"tur. Python ile kontrol: `X = 5` için `I = 2`'de VAR, `X = 15` için `I = 9`'da YOK.
- Satır toplamı örneğinde iki iç içe for döngüsü vardır. Dış döngü satırları, iç döngü bir satırın sütunlarını dolaşır. Bir öğrenci döngülerin yerini değiştirmenin fark edip etmeyeceğini sordu; hoca, yerleri değiştirilirse sütunların toplanacağını, analizin tam da bunu görmek için yapıldığını söyledi. Analizde `SUM` sırasıyla 1, 3, 6, 10, 15 olur ve `B(1) = 15`; ikinci satırda 6, 13, 21, 30, 40 ve `B(2) = 40`; üçüncü satırda 11, 23, 36, 50, 65 ve `B(3) = 65` bulunur.

<!-- BELİRSİZ: Var/yok sorusunun ikinci örnek dizisi altyazıda karışık okunuyor (3, 7, 14, ... ve sonradan eklenen 9); kareler bu ana denk gelmiyor. Notta yalnız ilk elemanları kullanıldı. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
