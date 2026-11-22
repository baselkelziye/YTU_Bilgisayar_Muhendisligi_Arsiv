# Ders 26 Çalışma Özeti

## Genel Konular

- Akış diyagramlarında sık görülen mantık ve gösterim hataları
  - İki sıralı diziyi üçüncü bir dizide birleştirmede yalnız elemanı taşınan dizinin indisi artırılır. A'nın elemanı küçükse `C(K) = A(I)` yazılır ve `I = I + 1` yapılır; B'nin indisi için `J = J` gibi bir atama gereksizdir, çünkü değişken değerini zaten korur.
  - Aynı soruda kullanılan iki dizinin adları farklı olmalıdır (A ve B, X ve Y gibi). N elemanlı bir A dizisiyle M elemanlı başka bir A dizisi aynı anda okunamaz, sonra ikisine ayrı ayrı başvurulamaz.
  - En büyük ikinci elemanı bulma sorusunda dizinin bütün elemanlarından en büyüğü çıkarıp yeni bir B dizisi oluşturmak gereksizdir ve zaman kaybıdır. Ayrıca böyle bir işlem tek satırda yazılamaz, döngü gerekir.
  - Arama ve benzeri işlerde verilen dizi değiştirilmez: bulunan eleman silinmez, yerine sıfır ya da başka bir değer atanmaz. Diziyi yerinde değiştiren işlem ancak sıralama gibi bir iş istendiğinde yapılır.
  - Giriş (input) şekline yukarıdan girilir, aşağıdan çıkılır. Yandan girip öbür yandan çıkan bağlantılar, eşkenar dörtgen ya da derste kullanılmayan uydurma şekiller kabul edilmez.
  - Karar şeklinin çıkışları `T` ve `F` ile etiketlenir; "evet/hayır", "doğru/yanlış" gibi kendi gösteriminizi kullanmayın.
  - Döngü şeklinden çıkan akış "uzay boşluğuna" gönderilmez, döngünün çıkışı akışın devamına bağlanır.
  - Çok sayıda bağlantı yuvarlağı (connector) akışı okunmaz hale getirir. Parçaları puzzle gibi bölüp numaralarla birleştirmeye bırakan akış doğru değildir.
- Kümelerde kesişim bulma yaklaşımı
  - Örnek: $A = \{3, 5, 7, 8, 11\}$, $B = \{3, 4, 8, 41\}$ (ekrandan, 01:00:00).
  - A'nın her elemanı için dönen dıştaki `for` döngüsü uygundur. B içinde ise bütün elemanları gezen bir `for` yerine eşleşme bulunmadığı sürece dönen koşullu bir döngü kurulmalıdır.
  - Küme elemanları sıralı olmak zorunda değildir; hoca kolaylık olsun diye sıralı yazdı.
- Sonsuz döngü ve kullanıcıdan sürekli girdi alma (sudoku sorusu)
  - Sunucu gibi programlar durdurulana kadar çalışır. C'de bu `while(1)` ya da üç ifadesi de boş bırakılmış `for(;;)` ile yazılır.
  - Kullanıcının elektronik olarak sudoku oynadığı bir program da oyun bitene ya da kullanıcı çıkmak isteyene kadar dönmelidir. Akışta döngü koşulu `DONE ≠ 1 AND EXIT ≠ 1` olarak çizildi (ekrandan, 00:45:00).
  - Döngüde önce girdi okunur. Girdi `q` ya da `e` ise `EXIT = 1` yapılır ve döngünün başına dönülür; sayıysa yerleştirileceği koordinatlar da okunur.
- Matris okuma ve karakter matrisleri
  - Matris okunurken önce boyutlar (N, M), sonra iç içe iki döngüyle elemanlar okunur. Kısaltma olarak tek bir giriş kutusunda `N, M, A(N)(M)` yazılabilir (ekrandan, 01:15:00).
  - Bu kısaltma yalnız okuma içindir. Bütün matrisin ya da dizinin çıktısını almak için tek kutuda böyle yazılamaz; `A(N)(M)` boyutlardan önce de yazılamaz.
  - Matrisin elemanları sayı olabileceği gibi karakter de olabilir (`'A'`, `'B'`, `'Z'`, `'X'`, `'Y'`, `'K'`). İlk derslerdeki encoding konusunda konuşulduğu gibi karakterler de bellekte sayılarla tutulur.
  - Akışta çıktı kutusunda değişken adları tırnaksız yazılır (`X, N`). Metin mesajı tırnak içinde yazılır (`'Merhaba'`) (ekrandan, 01:20:00).
- Karakter matrisinde bir karakterin geçtiği bütün yerleri bulma
  - Matris iç içe iki döngüyle taranır. `A(I)(J) = 'X'` ise satır ve sütun numarası iki satırlı bir B matrisine yazılır: `B(1)(K) = I`, `B(2)(K) = J`, ardından `K = K + 1` (ekrandan, 01:25:00).
  - `K` döngülerden önce `K = 1` olarak ilklendirilmelidir. Derste ilk çizimde bu eksikti, hata olarak bulundu.
  - `K` her zaman bir sonraki boş gözü gösterir. Bu yüzden döngü bitince bulunan konum sayısı `K - 1`'dir; B'yi yazdıran döngünün sınırı `K` değil `K - 1` olmalıdır.
  - Karakter sabiti apostrofla yazılır (`'X'`). Aranan karakter dışarıdan bir değişkene (örneğin `Z`) okunduysa karşılaştırma `A(I)(J) = Z` biçiminde, tırnaksız yazılır.
- Kelime içinde bir harfin geçip geçmediğini bulma
  - Kelime ya da cümle aslında bir karakter dizisidir. Boşluk da bir karakterdir (space).
  - Soru yalnız harfin geçip geçmediğiyse sayaçlı ve bütün diziyi gezen bir `for` gerekmez. Akış: `I = 1`; `A(I) ≠ X AND I <= N` olduğu sürece `I = I + 1`; döngüden çıkınca `I > N` ise harf yoktur, değilse vardır (ekrandan, 01:45:00).
  - Analiz örneği: kelime "Terminator", $N = 10$, $X = $ `t`. $I = 1..7$ için koşul sağlanır, $I = 8$'de `t ≠ t` yanlış olur ve döngüden çıkılır. $8 > 10$ yanlış olduğu için sonuç 'VAR' (ekrandan, 01:55:00).
  - Büyük `T` ile küçük `t` encoding'de farklı sayılardır, bu yüzden eşit değildir (case sensitivity).
- C'de string
  - Sayı dizisinde önce eleman sayısı, sonra elemanlar tek tek okunur. Karakter dizileri için programlama dilleri genelde string adlı ayrı bir yapı sunar.
  - C'de `char word[100];` tanımlanır ve `scanf("%s", word);` ile tek seferde bir kelime okunur (ekrandan, 02:00:00).
  - "ali" okunduğunda `word[0] = 'a'`, `word[1] = 'l'`, `word[2] = 'i'`, `word[3] = '\0'` olur. Üç harfli kelime dört göz kaplar.
  - Null karakteri sayısal değeri sıfır olan karakterdir. `'0'` karakteri ise encoding'de başka bir sayıya karşılık gelir.
  - C'de string null-terminated'dır. `printf("%s", word);` null karakterini görene kadar yazdırır. Null yoksa ekrana anlamsız şeyler çıkabilir ya da program bozulabilir.
- `string.h` kütüphanesi
  - `#include <string.h>` ile kullanılır. `x = strlen(word);` stringin uzunluğunu verir (ekrandan, 02:05:00).
  - `strlen`'in yaptığı iş: `i = 0; while(word[i]) i++;`. "ali" için `i` 3 olur.
  - `strcpy` bir stringi başka bir stringe kopyalar, `strtok` stringi parçalara (token) ayırır.
  - `strcpy` kopyalanan uzunluğu kontrol etmediği için güvenli değildir ve buffer overflow saldırılarında kullanılabilir. Yerine en fazla kaç karakter kopyalanacağı verilen `strncpy` önerildi.
- Tek karakter, karakter karakter ve string okuma farkı
  - `char x, word[10];` için üç durum gösterildi (ekrandan, 02:15:00):
    - `scanf("%c", &x);` yalnız tek bir karakter okur.
    - `for(i=0; i<10; i++) scanf("%c", &word[i]);` dizinin her gözüne bir karakter yazar, sona null eklemez.
    - `scanf("%s", word);` bir kelime okur ve sonuna null karakteri eklemeye çalışır.
  - `word[10]` iken 12 harfli "Çekoslovakya" girilirse dizinin dışına yazılır, null'a da yer kalmaz. Ardından `%s` ile yazdırmak hatalı sonuç verir.
  - Akışta kelime `N` ve `WORD(N)` biçiminde okunur. C'ye aktarılırken doğrudan string olarak okunur. Akış evrenseldir, onu programlama diline doğru aktarmak programcının işidir.
  - `scanf("%s", word)`'de `&` kullanılmaz, çünkü dizi adı tek başına kullanıldığında ilk elemanın adresini verir: `word` ile `&word[0]` aynıdır.
- Sayıyı ikilik tabanda yazdırma: mod yerine bit işlemleri
  - Bir öğrencinin onluk-ikilik dönüşüm programı ekranda incelendi. Program çalışıyordu ama hoca yöntemi yanlış buldu.
  - Mod alma maliyetli bir aritmetik işlemdir. Bunun yerine 1 maskesiyle AND alınır (son bit), maske her adımda bir sola kaydırılır. 99 için bitler sondan başa 1, 1, 0, 0, 0, 1, 1, 0 çıkar; 8 bitlik yazımı `01100011`.
  - İkilik sayı girdisi bit bit alınacaksa tutulan sayı bir bit kaydırılır, yeni bit OR ile eklenir.
  - Değişkenlerin `unsigned` tanımlanması beklenir.
- Matrise yeni bir sütun eklemek yerine ayrı dizi
  - N×M matrisin satır toplamlarını M+1'inci sütuna yazmak yerine ayrı bir tek boyutlu dizide tutmak daha temiz ve yönetilebilir bir çözümdür.
  - Bazı dillerde tek komutla sütun eklenir, ama arka planda yeni ve büyük bir matris açılır, eski matris kopyalanır. 1000 elemanlı alana 10 eleman eklemek için bir süre 1000 + 1010 elemanlık yer kullanılır.
  - Sık ekleme ve çıkarma yapılacak büyük kayıtlar için bağlı liste (linked list) daha uygundur. Bütün diziyi yeniden ayırmak yerine yalnız yeni eleman için bellek ayrılır ve bağlantılar değiştirilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Akış diyagramı bir düşünme sistematiği kazandırmak için öğretilir
  - Hocaya göre iyi bir mühendisi belirleyen şey bildiği teknoloji değil, sistematik düşünme yeteneğidir. Teknolojiler değişir; akış mantığı kalıcıdır.
- Derste anlatılan gösterime uymak
  - Kendi sembolünü uydurmak, C sözdizimini akışa taşımak, `T` ve `F` yerine başka etiketler kullanmak hatadır.
- Analiz sistematik yapılmalıdır
  - Değişkenlerin değerleri ve koşulların sonuçları sırayla, adım adım yazılır. Değişmeyen `N` her satıra yeniden yazılmaz.
  - Analiz akıştaki hatayı gösterebilmelidir; sırf yer doldurmak için rastgele değer yazmanın anlamı yoktur.
- Sorunun tam olarak ne istediğini okumak
  - "Geçiyor mu?", "kaç kere geçiyor?" ve "nerelerde geçiyor?" farklı sorulardır. İlki için ilk eşleşmede durmak yeter, sonuncusu için bütün yapı taranmalıdır.
- Bilgisayarın çalışma biçimine uygun akış
  - Akışı çizmek kolay olsun diye kestirme yollara sapılmamalı. Bilgisayar mimarisi açısından makul olan yöntem seçilmeli.
  - `X ∈ A` gibi küme gösterimleri ya da `A(I) = B(I) = X` gibi AND ile bağlanmamış zincir karşılaştırmalar bilgisayarın çalışma biçimine uymaz.
- Null-terminated string ve taşma
  - Ayrılan alandan uzun bir girdi kontrol dışı yazmaya yol açar. String kavramı C'de her zaman null-terminated olarak düşünülmelidir.

## Kısa Tekrar Notları

- Birleştirmede yalnız taşınan dizinin indisi artırılır; `J = J` gereksizdir.
- İki dizi aynı adı taşıyamaz.
- Verilen dizi aramada değiştirilmez.
- Input şekline yukarıdan girilir, aşağıdan çıkılır. Karar çıkışları `T` / `F` olarak etiketlenir.
- Kesişimde içteki arama "eşleşme yokken dön" koşullu döngüsüyle yapılır.
- Sonsuz döngü: `while(1)` ya da `for(;;)`.
- Bütün konumları bulmada `K = 1` ilklendirilir, bulunan konum sayısı `K - 1` olur.
- Karakter sabiti `'X'` biçiminde; değişkenle karşılaştırmada tırnak kullanılmaz.
- Varlık sorusu: `A(I) ≠ X AND I <= N` iken `I = I + 1`; sonra `I > N` ise YOK, değilse VAR.
- Büyük ve küçük harf farklı karakterlerdir.
- C'de string null (`'\0'`, sayısal değeri 0) ile biter; "ali" 4 göz kaplar.
- `scanf("%s", word)`'de `&` yoktur; `word` ile `&word[0]` aynıdır.
- `strlen`, `strcpy`, `strtok` `string.h` içindedir; `strcpy` güvensizdir, `strncpy` önerildi.
- İkilik yazdırmada mod yerine AND ve kaydırma (shift) kullanılır.
- Matrise sütun eklemek yerine sonuç ayrı dizide tutulur; sık eklemede bağlı liste kullanılır.

## Detaylı Açıklamalar

- Dersin ilk bölümünde hoca akış diyagramlarında sık gördüğü hataları tahtada canlandırdı. İki sıralı dizinin birleştirilmesinde her adımda hangi dizinin elemanı küçükse o eleman C'ye taşınır ve yalnız o dizinin indisi bir artırılır. Diğer indis olduğu yerde kalır; ona `J = J` yazmak gereksizdir. İki diziyle çalışılan sorularda dizilerin adları farklı olmalıdır. En büyük ikinci elemanı bulmada diziyi baştan değiştirmek ya da yeni diziler türetmek gereksizdir. Arama türü sorularda girdi verisi değiştirilmez.
- Gösterim konusunda hoca input şeklinin yukarıdan girilip aşağıdan çıkıldığını, karar çıkışlarının `T` ve `F` ile işaretlendiğini ve döngü çıkışının akışa bağlanması gerektiğini vurguladı. Bağlantı yuvarlakları ancak elektronik ortamda yer sıkıştığında kullanılmalıdır. Parçaların numaralarla birbirine bağlandığı dağınık akışlar okunamaz.
- Kesişim örneğinde ($A = \{3, 5, 7, 8, 11\}$, $B = \{3, 4, 8, 41\}$) A'nın her elemanı için B'de arama yapılır. A için `for` uygundur, ama B'deki arama eşleşme bulunmadığı sürece dönen bir döngüyle yapılmalıdır. Kesişim $\{3, 8\}$'dir.
- Bir öğrenci kullanıcıyla etkileşen bir sudoku programını sordu. Hoca bunu sunucu programlarındaki sonsuz döngüye benzetti. Döngü `DONE ≠ 1 AND EXIT ≠ 1` olduğu sürece döner; her turda girdi okunur, çıkış tuşuysa `EXIT = 1` yapılır, sayıysa koordinatlarla yerleştirilir.
- Karakter matrisinde `X`'in bütün konumlarını bulan akışta matris iç içe iki döngüyle taranır. Her eşleşmede satır `B(1)(K)`'ya, sütun `B(2)(K)`'ya yazılır ve `K` artırılır. `K = 1` ilklendirmesi unutulmamalıdır. `K` daima bir sonraki boş gözü gösterdiği için bulunan konum sayısı `K - 1`'dir. Karakter sabitleri apostrof içinde yazılır; dışarıdan okunan bir değişkenle karşılaştırırken tırnak kullanılmaz.
- Kelime içinde harf arama sorusu yalnız varlık sorusudur. Bu yüzden ilk eşleşmede duran koşullu döngü yeterlidir. "Terminator" ve `t` analizinde `I` 1'den 8'e kadar ilerler; 8. karakter `t` olduğu için döngü biter. $8 > 10$ yanlış olduğundan sonuç VAR'dır. İlk karakter büyük `T` olduğu için küçük `t`'ye eşit sayılmaz.
- C'de string, sonu null karakteriyle işaretlenmiş bir karakter dizisidir. `scanf("%s", word)` kelimeyi okur ve sona `'\0'` ekler. `printf("%s", word)` ve `string.h` fonksiyonları bu sonlandırıcıya dayanır. `strlen` null görene kadar sayar. Ayrılan alandan uzun girdi dizinin dışına yazar; bu, güvenlik açıklarının da kaynağıdır.
- Son bölümde bir öğrencinin onluk-ikilik dönüştürücüsü üzerinden yöntem ile çalışan program arasındaki fark konuşuldu. Bitleri mod ve bölmeyle bulmak yerine maske ve kaydırmayla bulmak daha hızlı ve doğaldır. Ayrıca bir matrise sütun eklemek yerine sonucu ayrı bir dizide tutmak gerektiği, arka planda boyut değişikliğinin yeniden ayırma ve kopyalama demek olduğu anlatıldı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
