# Ders 11 Çalışma Özeti

## Genel Konular

- Azaltarak yönetme (decrease and conquer) yaklaşımı
  - Böl ve yönete benzer bir yaklaşımdır. Problem her adımda elde işlenecek bilgi azaltılarak çözülür: ya işe yaramayan bilgi atılır ya da problem parça parça çözülerek kalan kısım küçültülür.
  - Üç türü anlatıldı: sabit miktarda azaltma (decrease by a constant), sabit bir oranda azaltma (decrease by a constant factor) ve değişken miktarda azaltma (variable size decrease).
- Sabit miktarda azaltma (decrease by a constant)
  - Örnekler: insertion sort, topolojik sıralama (topological sort), DFS ve BFS (ekrandan, 00:05:00).
  - Insertion sort'ta her adımda bir eleman sıralı kısma yerleştirilir ve işlenecek kısım bir azalır.
- Topolojik sıralama (topological sort)
  - Birbirine bağlı işlerin hangi sırayla yapılabileceğini bulur (iş zamanlama, ön şartlı dersler gibi). Bir kenar $X \to Y$, "Y'ye başlamadan önce X bitmeli" demektir.
  - Yalnız yönlü döngü (directed cycle) içermeyen yönlü çizgede (digraph) yapılabilir (ekrandan, 00:35:00).
  - Her düğümün giriş derecesi (in-degree), yani kendisinden önce bitmesi gereken iş sayısı bir dizide tutulur. Giriş derecesi 0 olan düğümler hemen yapılabilir. Bir düğüm yapılınca komşularının giriş derecesi 1 azaltılır.
  - Örnek çizge: $A \to B$, $A \to D$, $B \to C$, $C \to D$, $C \to E$, $D \to E$, F bağımsız. Giriş dereceleri A:0, B:1, C:1, D:2, E:2, F:0; sıra A F B C D E (ekrandan, 00:15:00 ve 00:20:00).
  - Kuyruk (queue) ile uygulama: giriş derecesi 0 olanlar kuyruğa konur; kuyruktan çıkan düğümün komşularının derecesi azaltılır, 0 olan hemen kuyruğa eklenir; kuyruk boşalınca işlem biter (ekrandan, 00:40:00).
- Topolojik sıralamanın karmaşıklığı
  - Klasik yol: giriş derecelerini hesaplamak $O(|E|)$; her turda dizide giriş derecesi 0 olan düğüm aramak $O(|V|^2)$; komşuları azaltmak toplamda $O(|E|)$. Toplam $O(|V|^2 + |E|)$ (ekrandan, 00:50:00).
  - Kuyrukla: kuyruğu başlatmak $O(|V|)$, çıkarmalar $O(|V|)$, azaltma ve eklemeler $O(|E|)$. Toplam $O(|V| + |E|)$, yani doğrusal.
- Sabit oranda azaltma (decrease by a constant factor): ikili arama
  - $n$ boyutlu problem her adımda yarıya iner; bir yarı atılır.
  - Özyinelemeli ikili arama kodu ekranda yazıldı (ekrandan, 01:15:00). Yineleme bağıntısı $T(n) = T(n/2) + c$, çözümü $O(\log n)$.
- Değişken miktarda azaltma (variable size decrease): en büyük ortak bölen
  - Öklid algoritması: $\gcd(a,b) = a$ ($b=0$ ise), değilse $\gcd(b, a \bmod b)$ (ekrandan, 01:20:00).
  - $\gcd(80,44) = \gcd(44,36) = \gcd(36,8) = \gcd(8,4) = \gcd(4,0) = 4$. Her adımda ne kadar azalacağı belli değildir.
- Hashing'e giriş
  - Hashing ile arama, ekleme ve silme $O(1)$, yani eleman sayısı $n$'e bağlı olmayan sabit karmaşıklıkta yapılabilir (ekrandan, 01:25:00).
  - Sıralı arama, ikili arama, ikili arama ağacı (BST) ve dengeli ağaç için arama, ekleme, silme karmaşıklıkları karşılaştırıldı; bunlarla elde edilebilecek en iyi değer $\log n$'dir.
  - Anahtar (key) bir hash fonksiyonundan geçirilir, bir indis elde edilir ve eleman $m$ uzunluklu hash tablosunun o gözüne yerleştirilir. Aramada aynı fonksiyon aynı indisi verir (ekrandan, 01:35:00).
  - Hash fonksiyonu kolay hesaplanabilir ve tutarlı (consistent) olmalıdır (ekrandan, 01:40:00).
  - Başarılı bir hash için üç soru: tablo ne kadar büyük olmalı, hash fonksiyonu nasıl seçilmeli, çakışma (collision) nasıl çözülmeli.
  - Bölme yöntemi (division method): $h(key) = key \bmod m$ (ekrandan, 01:45:00).
  - Çarpma yöntemi (multiplication method): $h(key) = \lfloor m \cdot ((key \cdot A) \bmod 1) \rfloor$, $A = \frac{\sqrt5 - 1}{2} \approx 0{,}618033$ (ekrandan, 01:50:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Topolojik sıralamada giriş derecesinin 1 ya da 2 olması, düğüme ne zaman sıra geleceğini göstermez.
  - Giriş derecesi 1 olan bir düğümün tek öncülü, zincirin en sonunda yapılacak bir iş olabilir. Bu yüzden sıralama giriş derecesi değerine göre yapılamaz; yalnız 0 olanlar işleme alınır.
- Çizgede yönlü döngü varsa topolojik sıralama yapılamaz.
  - Döngüdeki her iş bir öncekini bekler; giriş derecesi 0 olan düğümler bittikten sonra başlanabilecek iş kalmaz.
- Kuyruk kullanmak, giriş derecesi dizisini her turda baştan sona taramayı ortadan kaldırır.
  - Bir düğümün derecesi 0'a düştüğü anda kuyruğa eklenir; derecesi 0 olan bir düğüme bir daha uğranmaz, bu yüzden bir düğüm kuyruğa iki kez girmez.
- Hash fonksiyonunun karmaşık olması gerekmez.
  - "Çok karmaşık bir fonksiyon gerekir" düşüncesi yanlıştır. Başarıyı asıl tablo uzunluğu ve çakışmanın nasıl çözüldüğü belirler.
- Hash tablosu, algoritmik olarak sıradan bir dizidir.
  - Programlama dillerinin hazır hash tablosu yapılarıyla karıştırılmamalıdır; tabloyu ve boyutunu tasarlayan kişi siz olursunuz.
- Tablo uzunluğu eleman sayısından büyük olmalıdır, ama yer sonsuz değildir.
  - Boş yer arttıkça çakışma azalır; uzunluk hem yer hem zaman açısından dengelenmelidir.
- Ne kadar iyi bir hash fonksiyonu seçilirse seçilsin bir gün iki anahtar aynı indisi üretir; çakışma çözümü bu yüzden kritiktir.

## Kısa Tekrar Notları

- Decrease and conquer: her adımda işlenecek bilgi azalır.
- Sabit miktarda azaltma: insertion sort, topolojik sıralama, DFS, BFS.
- Sabit oranda azaltma: ikili arama, $T(n)=T(n/2)+c \Rightarrow O(\log n)$.
- Değişken miktarda azaltma: Öklid algoritması, $\gcd(80,44)=4$.
- Topolojik sıralama yalnız yönlü döngüsüz çizgede yapılır.
- Giriş derecesi 0 olan düğüm hemen yapılabilir; yapılınca komşuların derecesi 1 azalır.
- Klasik topolojik sıralama $O(|V|^2 + |E|)$, kuyrukla $O(|V| + |E|)$.
- Birden fazla geçerli topolojik sıra olabilir (düzeltilmiş örnekte A F D B C E de F A D B C E de doğrudur).
- Hashing: arama, ekleme, silme $O(1)$.
- Hash fonksiyonu: kolay hesaplanır, tutarlıdır.
- Bölme yöntemi: $key \bmod m$; çarpma yöntemi: $\lfloor m \cdot ((key \cdot A) \bmod 1) \rfloor$.
- $x \bmod 1$, $x$'in ondalık kısmını verir.

## Detaylı Açıklamalar

- Azaltarak yönetme ve ikili arama
  - Ders, önceki hafta işlenen böl ve yönet yaklaşımının (quicksort ve merge sort) hatırlatılmasıyla başladı. Hoca bir öğrencinin önerisiyle ikili aramanın bir azaltarak yönetme algoritması olduğunu belirtti: sıralı dizide aranan değer ortadaki elemandan küçükse ortadan büyük olan bütün elemanlar tek seferde elenir.
  - Özyinelemeli ikili arama (ekrandan, 01:15:00; başlangıçta `low = 0`, `high = N-1`):

    ```c
    BinarySearch(A, low, high, value)
    {
        if (low > high)
            return -1;   // not found
        mid = (low + high) / 2;
        if (A[mid] > value)
            return (BinarySearch(A, low, mid-1, value));
        else if (A[mid] < value)
            return (BinarySearch(A, mid+1, high, value));
        else
            return mid;
    }
    ```

  - Bir öğrenci özyinelemeli çağrılarda `return` yazmanın gerekip gerekmediğini sordu. Hoca, değer bulunduğunda `mid`'in çağrı zinciri boyunca geri döndürülerek en üste taşındığını anlattı.
  - Yineleme bağıntısı $T(n) = T(n/2) + c$'dir; $c$ her adımdaki sabit işlerdir. Geriye doğru yerine koyma (backward substitution) ile çözümü $O(\log n)$ çıkar.
- Topolojik sıralamanın elle yapılışı
  - Komşuluk listesi (adjacency list) kurulur: A → B, D; B → C; C → D, E; D → E; E ve F boş (ekrandan, 00:15:00).
  - Giriş derecesi dizisi önce sıfırlanır, sonra her kenar için hedef düğümün değeri 1 artırılır. Sonuç: A:0, B:1, C:1, D:2, E:2, F:0. Hoca başta E'yi 1 yazmıştı; bir öğrencinin uyarısıyla 2 olarak düzeltildi.
  - A ve F yapılır; A yapılınca B ve D'nin derecesi azalır, B 0 olur. B'den sonra C, C'den sonra D, en son E 0 olur. Sıra: A F B C D E (python ile doğrulandı).
  - Sonra hoca, bir soruyu açıklamak için çizgeye D → B kenarını ekledi. Bu kenar B → C → D → B döngüsünü oluşturdu ve A ile F'den sonra başlanabilecek iş kalmadı. Hoca bunun "yönlü döngü olmamalı" kuralını bozduğunu söyleyip C → D kenarını kaldırdı.
  - Düzeltilmiş çizge: A → B, D; B → C; C → E; D → B, E (ekrandan, 00:35:00). Giriş dereceleri A:0, B:2, C:1, D:1, E:2, F:0. Kuyrukla sıra A F D B C E olur (ekrandan, 00:40:00; python ile doğrulandı).
- Topolojik sıralamanın karmaşıklığı (ekrandan, 00:50:00)
  - Adım 1: her düğümün giriş derecesini diziye yaz, $O(|E|)$.
  - Adım 2 (klasik): düğüm kaldıkça giriş derecesi 0 olan bir düğüm bul ($O(|V|^2)$), ona komşu bütün düğümlerin derecesini 1 azalt ($O(|E|)$), bu düğümün derecesini $-1$ yaparak işaretle.
  - Adım 2 (kuyrukla): giriş derecesi 0 olan bütün düğümlerle kuyruğu başlat ($O(|V|)$); kuyrukta düğüm kaldıkça başındakini çıkar, komşularının derecesini azalt, 0 olanı kuyruğa ekle. Toplam $O(|V| + |E|)$.
- Öklid algoritması
  - Hoca $\gcd(80,44)$ örneğinde önce $44 \bmod 36$ işlemini yanlış (12) hesapladı; öğrenciler düzeltti. Doğru zincir: $80 \bmod 44 = 36$, $44 \bmod 36 = 8$, $36 \bmod 8 = 4$, $8 \bmod 4 = 0$; sonuç 4'tür (python ile doğrulandı). $44 = 11 \cdot 4$ ve 11 asal olduğu için de sonuç 4'tür.
- Arama yöntemlerinin karşılaştırılması (ekrandan, 01:30:00; tablonun hücreleri anlatımdan)
  - Sıralı arama (sırasız dizi), en kötü durum: arama $n$, ekleme 1 (sona ya da başa eklenir), silme $n$.
  - İkili arama (sıralı dizi): arama $\log n$, ekleme $n$, silme $n$ (yer sırayla bakılarak bulunur ve elemanlar kaydırılır).
  - BST: denge bozulmuşsa arama, ekleme, silme $n$.
  - Dengeli ağaç: hepsi $\log n$; ancak dengenin sürekli korunması gerekir.
  - Ortalama durumda BST ve dengeli ağaç $\log n$; sıralı arama $n/2$ <!-- BELİRSİZ: ortalama sütunu ekranda boş; altyazıda hangi satır için "N bölü 2" denildiği net değil -->.
- Hash tablosu ve hash fonksiyonları
  - Genelde benzersiz (unique) bir anahtar kullanılır; örneğin kişiler için ad yerine bir kimlik ya da öğrenci numarası. Ad benzersiz olmayabilir. Ancak uygulamaya göre tabloda aynı değerler de bulunabilir.
  - Hoca, 8 haneli bir numaranın hash fonksiyonundan geçip 3 indisini ürettiğini ve 3. göze konduğunu gösterdi. Gözde yalnız anahtar değil, ad, soyad gibi alanları olan bir yapı (structure) tutulabilir.
  - Çakışma örneği: iki farklı numara aynı hash fonksiyonundan geçip ikisi de 3 üretir; ikincisi geldiğinde 3. göz doludur (ekrandan, 01:40:00). Çakışma çözümü sonraki derse bırakıldı.
  - Bölme yöntemi, $m = 7$ (ekrandan, 01:45:00): $h(25) = 25 \bmod 7 = 4$, $h(2) = 2$, $h(7) = 7 \bmod 7 = 0$. Sonra gelen $key = 4$ için $h(4) = 4$ olur, ama 4. gözde 25 vardır: çakışma.
  - Çarpma yöntemi (ekrandan, 01:50:00): $m = 10000$, $key = 123456$ için $123456 \cdot A = 76300{,}0041151$, ondalık kısmı $0{,}0041151$, $\lfloor 10000 \cdot 0{,}0041151 \rfloor = 41$. Anahtar tablonun 41. gözüne yerleşir.
  - Ders sonrası not: $123456 \cdot 0{,}618033$ çarpımı $76299{,}882$ eder; ekrandaki $76300{,}0041151$ değeri $A$'nın tam değeriyle ($0{,}6180339887\ldots$) elde edilir. Sonuç 41 tam değerle doğrudur; altı haneye kesilmiş $A$ ile 8820 çıkar (python ile doğrulandı).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
