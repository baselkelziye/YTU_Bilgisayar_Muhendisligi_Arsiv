# Ders 14 Çalışma Özeti

## Genel Konular

- Çoklu ağaçların (m-ary / n-ary tree) tekrarı
  - Bir düğümün ikiden fazla çocuğu olabilen ağaçlardır. Kaynaklara göre m'li ya da n'li ağaç diye adlandırılır.
  - Ağacın derecesi, ağaçtaki en çok çocuğa sahip düğümün çocuk sayısıdır. Slayttaki örnekte kök A'nın 6 çocuğu (B, C, D, E, F, G) olduğu için ağaç 6'lı ağaçtır (ekrandan, 00:10:00).
- Çoklu ağacın ikili ağaç olarak gösterilmesi
  - Slayttaki kural: "Çok evlatlı ağaçlar, ikili ağaç olarak ifade edilebilir. İlk oğul için bir işaretçi, sağdaki ilk kardeş için bir işaretçi yeterlidir." (ekrandan, 00:10:00).
  - Her düğümde yalnız iki bağlantı tutulur: ilk çocuk (first child) ve sağdaki ilk kardeş (next sibling).
  - Aynı seviyedeki kardeşler bağlı liste mantığıyla `next`, `next` diye gezilir; `child` ile bir alt seviyeye inilir.
- İki işaretçi ile (genel) ağaç oluşturma
  - Düğüm yapısı: veri, çocuk işaretçisi, kardeş işaretçisi (ekrandan, 00:15:00).
  - Slayttaki C yapısı (ekrandan, 00:15:00):

    ```c
    struct node{
      int data;
      struct node *next;
      struct node *child;
    };
    ```

  - Veri alanı `int` yerine karakter ya da karakter dizisi olabilir.
- Uygulama problemi: ağaç yapısıyla dizin (klasör) simülasyonu
  - İşletim sistemindeki dosya/dizin yapısı bir ağaçtır. Problemde gerçek dosya sistemi çağrıları kullanılmaz, dizin hiyerarşisi bir veri yapısıyla simüle edilir.
  - Kök dizin `root` adıyla baştan vardır. Düğümler veri olarak karakter dizisi (dizin adı) tutar.
  - Beş komut (ekrandan, 00:20:00): `mkdir`, `chdir`, `rmdir`, `dir`, `count`.

## Hocanın Özellikle Vurguladığı Kısımlar

- İki işaretçili gösterimde ağacın yüksekliği (seviye sayısı) artar, ama her düğüm yalnız iki işaretçi taşıdığı için yapı ikili ağaç mantığıyla kolayca gerçeklenir.
  - Örnekte 4 seviyeli genel ağaç, ikili gösterimde 7 seviyeye çıkar.
- Bir dizinin altındaki kaç alt dizin olacağı ve ağacın kaç seviyeli olacağı önceden bilinemez. Kullanıcı istediği kadar dizin yaratabilir. Bu yüzden sabit sayıda çocuk işaretçisi yerine ilk çocuk / kardeş gösterimi uygundur.
- `dir` yalnız aktif dizinin doğrudan çocuklarını listeler, alt dizinlerin içini göstermez.
- `rmdir` içi dolu (çocuğu olan) dizini silmemelidir.
- Hata durumları ele alınmalıdır: olmayan dizini silmek, olmayan dizine geçmek, kökteyken yukarı çıkmak.

## Kısa Tekrar Notları

- Ağacın derecesi: en çok çocuğu olan düğümün çocuk sayısı.
- First child / next sibling: her düğümde `child` (ilk çocuk) ve `next` (sağdaki kardeş) işaretçisi.
- Kökün kardeşi yoktur; çocuğu ya da kardeşi olmayan işaretçiler `NULL` olur.
- Genel ağaç ikili gösterime çevrilince seviye sayısı artar.
- `mkdir ad`: aktif dizine çocuk ekler.
- `chdir ad`: alt dizine iner; `chdir ..`: bir üst dizine çıkar; kökte `chdir ..` hata verir ("Already in root !!!").
- `rmdir ad`: aktif dizinin boş çocuğunu siler; yoksa "bulunamadı", doluysa "boş değil" hatası verir.
- `dir`: aktif dizinin çocuklarını listeler.
- `count`: aktif dizindeki alt dizin sayısını verir.
- Komutlar terminal gibi tek tek okunur ve ayrıştırılır (parse): önce komut adı, boşluktan sonra dizin adı.

## Detaylı Açıklamalar

### Çoklu ağacın ikili gösterimi

Slayttaki örnekte (ekrandan, 00:10:00) kök A'nın çocukları B, C, D, E, F, G'dir. B'nin çocukları H, I, J; H'nin çocukları N, O; E'nin çocukları K, L; K'nin çocuğu P; L'nin çocuğu Q; G'nin çocuğu M'dir. Düğümlerin çocuk sayıları 6, 3, 2, 1 gibi değerler alır; en büyüğü 6 olduğu için ağaç 6'lı ağaçtır.

İkili gösterimde her düğümün sol bağlantısı ilk çocuğu, sağ bağlantısı sağdaki ilk kardeşi gösterir:

```text
A  : ilk çocuk B,  kardeş yok (kök)
B  : ilk çocuk H,  kardeş C
C  : çocuk yok,    kardeş D
D  : çocuk yok,    kardeş E
E  : ilk çocuk K,  kardeş F
F  : çocuk yok,    kardeş G
G  : ilk çocuk M,  kardeş yok
H  : ilk çocuk N,  kardeş I
I  : çocuk yok,    kardeş J
N  : çocuk yok,    kardeş O
K  : ilk çocuk P,  kardeş L
L  : ilk çocuk Q,  kardeş yok
```

A'dan tek bağlantıyla B'ye inilir; sonra `next` ile B, C, D, E, F, G seviyesi bağlı liste gibi gezilir. Bir alt seviyeye geçmek için ilgili düğümün `child` bağlantısı kullanılır (örneğin B'den H'ye inip H, I, J gezilir; E'den K'ye inip K, L gezilir).

### İki işaretçi ile ağaç oluşturma örneği

İkinci slaytta (ekrandan, 00:15:00) V0 kökünün çocukları V1, V2, V3, V4; V1'in çocukları V5, V6; V3'ün çocukları V7, V8, V9; V7'nin çocuğu V10'dur. Bu 4 seviyeli genel ağaçtır. Bellekte kök V0'ın çocuk işaretçisi V1'i gösterir; V1 → V2 → V3 → V4 kardeş zinciridir. V1'in çocuğu V5 (V5 → V6), V3'ün çocuğu V7 (V7 → V8 → V9), V7'nin çocuğu V10'dur.

Hoca bu yapıyı ikili ağaç olarak çizdi: 0'dan 1; 1'den 2 (kardeş) ve 5 (çocuk); 5'ten 6; 2'den 3; 3'ten 4 (kardeş) ve 7 (çocuk); 7'den 8 (kardeş) ve 10 (çocuk); 8'den 9. En uzun yol V0, V1, V2, V3, V7, V8, V9 olduğu için ikili gösterim 7 seviyelidir (python ile doğrulandı).

### Dizin simülasyonu örneği

Ekranda adım adım kurulan örnek (ekrandan, 00:20:00 ve 00:25:00):

```text
mkdir courses
chdir courses
mkdir dStruct
chdir dStruct
mkdir Trees
mkdir Stacks
mkdir Queues
chdir Trees
mkdir bTrees
mkdir heapTrees
chdir ..          -> dStruct'a çıkılır
dir               -> Trees, Stacks, Queues
rmdir Stacks      -> silinir
rmdir dStruct     -> hata: böyle bir alt dizin yok (directory not found)
rmdir Trees       -> hata: dizin boş değil (directory not empty)
chdir heap        -> hata: dizin yok (doesn't exist)
count             -> 2 (Trees ve Queues)
chdir ..          -> courses
chdir ..          -> root
chdir ..          -> Already in root !!!
```

Ulaşılan ağaç:

```text
root
  courses
    dStruct
      Trees
        bTrees
        heapTrees
      Queues
```

Bu gösterimde her dizin bir düğümdür: dizinin alt dizinleri onun `child` işaretçisinden başlayan kardeş listesidir. `mkdir` bu listeye eleman eklemek, `rmdir` listeden eleman silmek, `dir` listeyi gezmek, `count` listedeki eleman sayısını saymaktır. `chdir ..` için bir üst düğüme dönebilmek gerekir.

### Soru-cevaptan akademik notlar

- Komutlarda seçenek (option) yoktur. `ls -la` gibi bayraklar istenmez, yalnız beş komut gerçeklenir.
- Komut ve ad karşılaştırmasında string karşılaştırma fonksiyonu (`strcmp`) kullanılabilir.
- Yığın ve kuyruk gibi yapılar bazı dillerde ve kütüphanelerde hazır gelir; dış kütüphanelerle de kullanılabilir. Bu derste yapılar elle tanımlanır.
  - Ders sonrası not: Hoca C'de hazır yığın kütüphanesi olduğunu ve "include stack" ile kullanılabileceğini söyledi. Standart C kütüphanesinde hazır yığın yapısı yoktur; `#include <stack>` ile gelen `std::stack` C++ standart kütüphanesine aittir. C'de yalnız üçüncü taraf kütüphaneler kullanılabilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
