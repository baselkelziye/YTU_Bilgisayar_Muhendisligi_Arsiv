# Ders 18 Çalışma Özeti

## Genel Konular

- Fonksiyonun tanımı
  - Fonksiyon, isimlendirilmiş ve parametre alabilen bir algoritmadır (ekrandan, 00:10:00). Başka algoritmalar ya da başka fonksiyonlar tarafından kullanılsın diye yazılır.
  - İki taraf vardır: fonksiyonu çağırmak ve fonksiyonu yazmak.
  - Çağırma yazımı: `[çıkış parametreleri] = fonksiyon_ismi(giriş parametreleri)` (ekrandan, 00:10:00).
  - Algoritma gösteriminde birden fazla çıkış parametresi yazılabilir; ancak C gibi bazı diller tek bir değer döndürür. C'de bir dizi ya da matris döndürülmek istendiğinde, bellekte başladığı adres döndürülür ve oradan okunur.
- Hazır fonksiyonlar ve kütüphaneler
  - `main` de bir fonksiyondur; `printf` ve `scanf` dille birlikte gelen hazır fonksiyonlardır. `printf` hem yazdırılacak şeyi hem de biçimi parametre olarak alır.
  - Hazır fonksiyonlar kütüphanelerde durur; programın başında `include` edilen `stdio`, `stdlib`, `math`, `time` gibi `.h` uzantılı dosyalar bu kütüphanelerin başlık dosyalarıdır.
  - Kişi kendi fonksiyonlarını da yazıp kütüphane hâline getirebilir.
- Fonksiyon yazmanın faydaları
  - Bir kez yaz, hep kullan ya da başkaları kullansın (ekrandan, 00:10:00). Sıralama gibi sık kullanılan parçalar Lego parçalarına benzetilir.
  - Birlikte çalışma: proje parçalara bölünür, her parça bir fonksiyon olur, ekipte herkes kendi parçasını yazar, sonra parçalar ana yapıda birleştirilir.
  - Kolay düzeltme: bir hata fonksiyonda tek yerde düzeltilince her yerde düzelir. Kod kopyalanmış olsaydı her kopyanın ayrı ayrı düzeltilmesi gerekirdi.
  - Kolay güncelleme: fonksiyonun yapması gereken iş değişebilir (örneğin en büyük değerin yanında yerini de döndürmesi). Değişiklik tek yerde yapılır.
- Fonksiyon çağrısının maliyeti ve yığın (stack)
  - Fonksiyon çağrılınca ana programın çalışması durur, o andaki değişkenler ve kalınan satır (program sayacı) yığına yazılır, fonksiyon çalışır, bitince değerler yığından geri alınır ve kalınan yerden devam edilir.
  - Fonksiyon başka bir fonksiyonu çağırabilir (A, F1'i; F1, F2'yi). Her çağrının bilgileri yığında üst üste durur; böylece aynı adlı değişkenler (örneğin ana programdaki A ile fonksiyondaki A) birbirine karışmaz.
  - Yığına yazma ve yığından okuma zaman alır. Fonksiyonun kodunu her kullanıldığı yere kopyalamak programı hızlandırır (ekrandan, 00:20:00); fonksiyonlar hız için değil, sağladıkları faydalar için kullanılır.
- Belgeleme ve isimlendirme
  - Fonksiyonun kısıtları, yapabildikleri ve parametreleri iyi belgelenmelidir. Parametre, fonksiyona gönderilen (giriş) ya da fonksiyondan geri alınan (çıkış) değerlerdir.
  - Fonksiyon ve değişken adları ne yaptığını ya da ne tuttuğunu anlatmalıdır; `f1`, `f2`, `f3` gibi adlar kötüdür. Uzun ad sorun değildir.
- Fonksiyonun akış diyagramında gösterimi
  - Başlangıç şekli iki katlıdır: üst kısımda fonksiyon adı ve parantez içinde giriş parametreleri, alt kısımda çıkış parametreleri yazılır. Algoritma bunun altına çizilir ve `return` ile biter (ekrandan, 00:35:00).
  - `return` ile çıkış parametrelerinin değerleri fonksiyonu çağıran yere döner.
  - Giriş parametreleri fonksiyona hazır gelir; fonksiyon içinde bunlar yeniden okunmaz.
- Örnek: `maxbul(A, N)` fonksiyonu
  - Çağrı: `[maxD, max_ind] = max_bul(A, N)`; A dizi, N dizinin boyutu, `maxD` en büyük değer, `max_ind` onun indisi (ekrandan, 00:35:00).
  - Algoritma: `maxD = A[1]`, `max_ind = 1`; `i = 2`'den N'ye kadar `maxD < A[i]` ise `maxD = A[i]`, `max_ind = i`; döngüden sonra `return`.
- Parametrik fonksiyon yazımı
  - Değişebilecek şeyler dışarıdan parametre olarak alınır; böylece fonksiyon sayısı azalır. 4, 5, 7 elemanlı diziler için ayrı sıralama fonksiyonları yerine uzunluğu N parametresi olan tek fonksiyon yazılır.
  - Küçükten büyüğe (`kbsirala(D, N)`) ve büyükten küçüğe (`bksirala(D, N)`) iki ayrı fonksiyon yerine yön parametresi alan tek fonksiyon yazılabilir: `sirali_dizi = sirala(Dizi, N, y)` (ekrandan, 00:45:00).
- Örnek: `minmax(D, N, bk)` fonksiyonu (ekrandan, 00:45:00)
  - `bk = 1` ise en büyük, `bk = 0` ise en küçük eleman ve indisi döner; çıkış `d, ind`.
  - `d = D[1]`, `ind = 1`; `bk == 1` sorusunun doğru kolunda `i = 2..N` için `d < D[i]` ise `d = D[i]`, `ind = i`; yanlış kolunda aynı döngü karşılaştırma ters çevrilerek kurulur; iki kol birleşir ve `return` ile biter.
  - Parametrenin hangi değerinin ne anlama geldiği fonksiyonun belgesine yazılmalıdır.
- Fonksiyon aşırı yükleme (function overloading)
  - Aynı adlı, ilişkili ama farklı işler yapan birden fazla fonksiyon yazmaktır. Giriş parametreleri farklı olmalıdır; yalnız parametre adlarının farklı olması yetmez, tipleri (ya da farklı tiplerin sırası) farklı olmalıdır.
  - Örnek (ekrandan, 01:10:00): `[D, ind] = minmax(D, N, bk)` dizi için, `[D, ind] = minmax(matris, M, N, bk)` matris için.
  - Matris sürümü dizi sürümünü kullanır: önce `K[i] = 0` (i = 1..M); sonra her i satırı için `A[j] = matris[i, j]` (j = 1..N) ile satır bir diziye kopyalanır ve `[K[i], ind] = minmax(A, N, bk)` ile satırın en büyüğü (ya da en küçüğü) K'ya yazılır; en sonda `[D, ind] = minmax(K, M, bk)`.
  - Bu sürümde dönen `ind`, yalnız en büyük ya da en küçük elemanın bulunduğu satırı gösterir; sütunu göstermez.
  - Alternatif: matrisin bütün elemanları M x N uzunluğunda tek bir diziye atılıp `minmax(A, M*N, bk)` çağrılabilir.
- Birbirine en yakın iki nokta problemi
  - Tek boyut: `[ind1, ind2] = enyakin(A, N)`. `min_dist = ∞`, `ind1 = ind2 = 0`; `i = 1..N-1`, `j = i+1..N`; `|A[i] - A[j]| < min_dist` ise `min_dist = |A[i] - A[j]|`, `ind1 = i`, `ind2 = j` (ekrandan, 01:25:00).
  - j'nin i+1'den başlaması, bir elemanın kendisiyle ve aynı çiftin iki kez karşılaştırılmasını önler.
  - K boyut: noktalar N x K matrisin satırlarıdır (N nokta sayısı, K boyut sayısı). `enyakin(A, N, K)` içinde her (i, j) çifti için `dist = 0`, `k = 1..K` için `dist = dist + |A[i,k] - A[j,k]|`; `dist < min_dist` ise güncellenir (ekrandan, 01:35:00).
- Uzaklık ölçüleri
  - Mutlak farkların toplamı L1 normu (cityblock ya da Manhattan uzaklığı), farkların karelerinin toplamının karekökü L2 normu (Öklid uzaklığı) olarak anılır (ekrandan, 01:45:00).
  - Hangisinin daha doğru olduğu söylenemez; noktaların dağılımına bağlıdır. Gauss dağılımlı veride L2 ya da Mahalanobis uzaklığı daha uygun olabilir.
- Çöpçatan sitesi problemi (ekrandan, 01:55:00)
  - Erkekler matrisi `E (M x D)`, kadınlar matrisi `K (N x D)`; D soru sayısıdır ve cevaplar sayısaldır.
  - `[ind1, ind2] = enuygun(E, M, K, N, D)`: `i = 1..M`, `j = 1..N`, `k = 1..D` için `dist = dist + |E[i,k] - K[j,k]|`; `min_dist > dist` ise güncellenir.
  - Fark: önceki problemde aynı matrisin satırları karşılaştırılıyordu, burada iki farklı matrisin satırları karşılaştırılır; bu yüzden j 1'den başlar.
  - Değişkenlerin aralıkları çok farklıysa (yaş ve aylık gelir gibi), aralığı büyük olan değişken uzaklığa baskın gelir; normalize etmek gerekir.
- `void`
  - Geriye değer döndürmeyen fonksiyonun çıkış kısmı `void` olur: `yazdir(A)`. Parametre almayan fonksiyonun giriş kısmı da `void` olur: `yazdir(void)` (ekrandan, 02:10:00).
- Doktor-hasta-teşhis problemi (ekrandan, 02:10:00)
  - D doktor, H hasta; `T (D x H)` teşhis matrisi, `G (H)` doğru teşhis dizisi. Hastalıklar 1-100 arası kodlarla gösterilir.
  - T'nin i'inci satırı i'inci doktorun bütün hastalara koyduğu teşhisler, j'inci sütunu j'inci hastaya konan bütün teşhislerdir.
  - En başarılı doktor: `basarilar = kisisel_basari(T, D, H, G)` (D uzunluklu dizi), sonra `[deg, sind] = minmax(basarilar, D, max)` (ekrandan, 02:20:00).
  - Birbirine en yakın iki doktor: `[ind1, ind2] = enyakinV2(T, D, H)`. Kodlar anlamsal sıra taşımadığı için uzaklık farkların toplamı değil, farklı teşhis sayısıdır: `T[i,h] != T[j,h]` ise `dist = dist + 1`.
  - Birbirine en benzeyen iki hasta: `TT = transpose(T)`, `[ind3, ind4] = enyakinV2(TT, H, D)` (ekrandan, 02:35:00).
  - En nadir teşhis: `HD = diziyecevir(T, D, H)`, `frekanslar = frekansbul(HD, D*H)` (100 boyutlu dizi), sonra frekanslar dizisinin en küçüğünün indisi `minmax` ile bulunur (ekrandan, 02:35:00).
  - Yanlış teşhis konan hastalar (ekrandan, 02:45:00): `KL = yanlis_teshis(T, D, H, G)`; her hasta için D doktorun teşhisleri bir diziye alınır, `frekansbul` ve `minmax(..., max)` ile çoğunluk (demokrasi) kararı `secim` bulunur; `secim == G[i]` değilse `KL[i] = 1`.

## Hocanın Özellikle Vurguladığı Kısımlar

- Fonksiyonlar programı hızlandırmaz, biraz yavaşlatır
  - Yığına yazma ve atlama maliyeti vardır; ama yeniden kullanım, birlikte çalışma, kolay düzeltme ve güncelleme faydaları bu yavaşlamadan çok daha büyüktür.
- Belgeleme ve anlamlı isimler
  - Yıllar önce yazılmış, belgelenmemiş bir kodu yazanın kendisi bile zor anlar. Zekice yollarla çözülmüş kod daha da zor hatırlanır.
- Parametrik tasarım
  - Değişebilecek her şeyi parametre yapmak (dizi uzunluğu, sıralama yönü, en büyük ya da en küçük seçimi) fonksiyon sayısını azaltır.
- Aşırı yüklemede tip farkı
  - Aynı adlı iki fonksiyonun giriş parametreleri tip olarak ayırt edilebilmelidir; aksi halde hangisinin çağrılacağı anlaşılamaz.
- Problemi doğru anlamak
  - K boyutlu en yakın nokta probleminde matristeki birbirine en yakın iki sayı aranmaz; her satır bir noktadır ve satırlar karşılaştırılır.
- Kodların anlamı
  - Hastalık kodları rastgele verildiği için kodlar arasındaki sayısal fark anlamsızdır (99 ile 100 birbirine "yakın" değildir). Yalnız eşit mi farklı mı olduğuna bakılır.
- Bir kez yaz, defalarca kullan
  - `minmax`, `enyakin`, `frekansbul` gibi fonksiyonlar bir kez yazılıp farklı problemlerde tekrar tekrar kullanıldı; tekerleği yeniden icat etmeye gerek kalmaz.

## Kısa Tekrar Notları

- Fonksiyon: isimlendirilmiş, parametre alabilen algoritma.
- Çağrı: `[çıkışlar] = ad(girişler)`; C tek değer döndürür.
- Akış diyagramı: üstte `ad(girişler)`, altta çıkışlar; sonda `return`.
- Giriş parametreleri fonksiyonda yeniden okunmaz.
- Faydalar: yeniden kullanım, ekip çalışması, kolay düzeltme, kolay güncelleme.
- Fonksiyon çağrısı yığın (stack) kullanır; kodu kopyalamak daha hızlıdır ama bakımı zordur.
- `minmax(D, N, bk)`: `bk = 1` en büyük, `bk = 0` en küçük.
- Aşırı yükleme: aynı ad, farklı tipte giriş parametreleri (`minmax` dizi ve matris sürümleri).
- En yakın iki nokta: çift döngü, `j = i+1..N`; K boyutta iç döngüde mutlak farklar toplanır.
- İki farklı küme (çöpçatan) karşılaştırılırken j 1'den başlar.
- L1 (cityblock) ve L2 (Öklid) uzaklıkları; doğruluk veri dağılımına bağlıdır.
- Kategorik kodlarda uzaklık: farklı olan konum sayısı.
- Sütunları karşılaştırmak için matrisin transpozu alınıp satır fonksiyonu kullanılır.
- `void`: dönüş değeri ya da parametre yoksa kullanılır.

## Detaylı Açıklamalar

Ders, fonksiyon kavramıyla başlar. Fonksiyon isimlendirilmiş ve parametre alabilen bir algoritmadır; başka algoritmaların onu adıyla çağırıp kullanabilmesi için yazılır. Çağırma tarafında genel yazım `[çıkış parametreleri] = fonksiyon_ismi(giriş parametreleri)` biçimindedir. Algoritmalar dilden bağımsız yazıldığı için birden fazla çıkış gösterilebilir; C ise tek bir değer döndürür. Bir dizi döndürülmek istendiğinde dizinin bellekteki başlangıç adresi döner. C programlarında yazılan `main`, kullanılan `printf` ve `scanf` de birer fonksiyondur. Bunlar dille gelen kütüphanelerde durur ve programın başındaki `#include` satırlarıyla bu kütüphanelerin başlık dosyaları programa eklenir.

Fonksiyon yazmanın dört faydası anlatılır: bir kez yazıp her yerde kullanmak, ekip içinde işi bölüşmek, hatayı tek yerde düzeltmek ve fonksiyonun işini tek yerde güncellemek. Buna karşılık fonksiyon çağrısı programı biraz yavaşlatır. Çağrı anında çalışan kodun değişkenleri ve hangi satırda kalındığı yığına (stack) yazılır, fonksiyon başka bir bellek bölgesinde çalışır, bitince değerler yığından geri alınır. İç içe çağrılarda (A, F1'i; F1, F2'yi çağırır) bilgiler yığında üst üste durur ve sondan başa doğru geri alınır. Fonksiyon kodu her kullanıldığı yere kopyalanırsa bu atlamalar olmaz ve program daha hızlı çalışır. Yine de bu yol bakım açısından çok daha pahalıdır; bir hata bulunduğunda her kopyanın ayrı ayrı düzeltilmesi gerekir.

İyi bir fonksiyon iyi belgelenmelidir: neyi yapabildiği, kısıtları ve parametreleri açıklanmalıdır. Fonksiyon ve değişken adları yaptıkları işi anlatmalıdır. Akış diyagramında fonksiyon iki katlı bir başlangıç şekliyle gösterilir: üst katta ad ve giriş parametreleri, alt katta çıkış parametreleri yer alır. Diyagram `return` ile biter. Giriş parametreleri çağıran tarafından okunup gönderildiği için fonksiyon içinde yeniden okunmaz. İlk örnek `max_bul(A, N)` fonksiyonudur. Dizinin ilk elemanı başlangıç en büyüğü kabul edilir, sonra 2'den N'ye kadar her eleman bununla karşılaştırılır ve daha büyük bulunursa hem değer hem indis güncellenir.

Fonksiyonlar parametrik yazılmalıdır. Değişebilecek her şey parametre olunca fonksiyon sayısı azalır. Sıralama yönü için `y`, en büyük ya da en küçük seçimi için `bk` parametresi kullanılır. `minmax(D, N, bk)` fonksiyonunda `bk == 1` sorusu iki kol açar. Doğru kolda en büyük, yanlış kolda en küçük aranır. İki kol birleşip `return` ile biter.

Fonksiyon aşırı yüklemede aynı ad, giriş parametreleri tip olarak farklı olan birden fazla fonksiyona verilir. Matris için yazılan `minmax(matris, M, N, bk)`, dizi için yazılan `minmax`'ı kullanır. Her satır geçici bir A dizisine kopyalanır, satırın en büyüğü (ya da en küçüğü) K dizisine yazılır ve sonunda K dizisinin en büyüğü (ya da en küçüğü) bulunur. Bu çözümde dönen indis yalnız satırı gösterir. Sütunu da bulmak için ek iş gerekir.

İkinci yarıda birbirine en yakın iki nokta problemi önce tek boyutta, sonra K boyutta çözülür. Tek boyutta her eleman kendinden sonraki elemanlarla karşılaştırılır; mutlak fark o ana kadarki en küçük uzaklıktan küçükse indisler güncellenir. K boyutta noktalar N x K matrisin satırlarıdır ve iki satır arasındaki uzaklık, k = 1..K için mutlak farkların toplamıdır. Bir öğrencinin sorusu üzerine L1 (cityblock) ve L2 (Öklid) uzaklıkları karşılaştırılır. Hoca, hangisinin daha doğru olduğunun veri dağılımına bağlı olduğunu söyler. Aynı yapı çöpçatan sitesine uygulanır. Bu kez erkekler (M x D) ve kadınlar (N x D) iki ayrı matristir ve her erkek her kadınla karşılaştırılır. Hoca, aralıkları çok farklı değişkenlerin (yaş, gelir) normalize edilmesi gerektiğini de ekler.

Son bölümde doktorların hastalara koyduğu teşhislerden oluşan `T (D x H)` matrisi ve doğru teşhisleri tutan `G` dizisi üzerinde sorular çözülür. En başarılı doktor, doktor başarılarını hesaplayan bir fonksiyondan sonra `minmax` ile bulunur. Birbirine en yakın iki doktor için `enyakin` fonksiyonunun uzaklık kısmı değiştirilir (`enyakinV2`). Kodlar anlamsız sayılar olduğu için iki doktorun farklı teşhis koyduğu hasta sayısı uzaklık olarak alınır. Birbirine en benzeyen iki hasta için T'nin transpozu alınır ve aynı fonksiyon `(TT, H, D)` boyutlarıyla çağrılır. En nadir teşhis için matris diziye çevrilir, frekanslar bulunur ve en küçük frekansın indisi alınır. Yanlış teşhis konan hastalarda her hastanın teşhisleri için çoğunluk kararı frekans ve `minmax` ile bulunur, doğru teşhisle aynı değilse işaretlenir. Hoca bu örneklerle aynı küçük fonksiyonların farklı problemlerde tekrar tekrar kullanılabildiğini gösterir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
