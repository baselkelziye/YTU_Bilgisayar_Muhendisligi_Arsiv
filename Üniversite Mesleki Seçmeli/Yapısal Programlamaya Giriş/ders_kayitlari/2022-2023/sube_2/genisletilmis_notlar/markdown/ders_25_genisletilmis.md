# Ders 25 Genişletilmiş Notu: Uygulama: Lab Sorusu Çözümü (Robotun Matristeki Yolları), Ağaç Veri Yapısı ve Dizi Tabanlı İkili Arama Ağacı (BST)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Lab sorusu: robotun başlangıçtan bitişe giden rotaları
- 2. Lab sorusu üzerine sorular: dizinin paylaşılması, prototip, kapsam
- 3. Ağaç veri yapısı ve terimleri
- 4. İkili arama ağacı (BST)
- 5. Heap ile BST farkı
- 6. BST'yi dizide tutma: indis formülleri
- 7. BST'de ekleme ve arama (iteratif ve özyinelemeli)
- 8. BST oluşturma ve pre-order yazdırma
- 9. Dengesiz ağaç ve dengeli BST oluşturma
- 10. Kapsam (scope) ve global değişkenler
- 11. Örnek problem: alt ağaç ortalaması
- Örnek Sorular
- Dersin Toparlaması

Bu oturum bir uygulama oturumuydu. İki grup bu hafta aynı bağlantıdan katıldı. Önce bir lab sorusunun çözümü incelendi, sonra ağaç veri yapısına ve özellikle ikili arama ağacına (BST) geçildi. BST, Dev-C++ üzerinde bir dizi kullanılarak adım adım kodlandı ve dersin sonunda BST üzerinde bir problem çözüldü.

## 1. Lab sorusu: robotun başlangıçtan bitişe giden rotaları

### 1.1 Problem

Bir robot oda temizlerken odalar arasında geçiş yapar. Odalar $n \times n$ bir matrisle gösterilir. Kullanıcıdan önce matris boyutu, sonra matrisin elemanları alınır. Program matrisi yazdırır, robotun başlangıçtan bitişe giden bütün rotalarını yazdırır ve kaç rota olduğunu bulur. Çözüm özyinelemeli (recursive) olmalıdır.

- Robot $(0,0)$ hücresinden başlar.
- Sağ alt köşeye, yani $(n-1, n-1)$ hücresine gelince durur.
- Değeri 0 olan odaya giremez, değeri 1 olan odaya girebilir.
- 1 olan bütün odalara girmesi gerekmez; yalnız başlangıçtan bitişe giden rotalar ve sayıları istenir.
- Robot yalnız sağa ve aşağıya ilerler (anlatımda "zaten sadece sağ ve aşağıya gidebiliyor" denildi).

### 1.2 Çözüm kodu

Ekranda gösterilen çözüm (ekrandan, 00:15:00 ve 00:20:00). Türkçe yorumlar ekranda karakter kodlaması bozuk göründüğü için sadeleştirilerek yazıldı; `main` fonksiyonunun sonu karede görünmüyor.

```c
#include <stdio.h>
#define MAX 10
void printPath(int path[], int length) {
    int i;
    for (i = 0; i < length; i += 2) {
        printf("(%d, %d) ", path[i], path[i + 1]);
    }
    printf("\n");
}

int countPaths(int i, int j, int n, int matrix[][MAX], int path[], int pathLength) {
    int rightPaths;
    int downPaths;
    if (i == n-1 && j == n-1) { // Son hucreye ulasildiysa, yolun tamami yazdirilir.
        path[pathLength++] = i;
        path[pathLength++] = j;
        printPath(path, pathLength);
        return 1; // Bir yol daha tamamlandi olarak isaretlenir
    }
    if (i >= n || j >= n || matrix[i][j] == 0) { // Gecersiz hucre veya 0 degeri
        return 0; // Gecerli yol yok
    }

    path[pathLength++] = i;
    path[pathLength++] = j;

    rightPaths = countPaths(i + 1, j, n, matrix, path, pathLength); // Saga gitme yol sayisi
    downPaths = countPaths(i, j + 1, n, matrix, path, pathLength);  // Asagiya gitme yol sayisi

    return rightPaths + downPaths; // Saga gitme yollari ve asagiya gitme yollarinin toplami
}
void getMatrix(int n, int matrix[][MAX]) {
    int i,j;
    printf("Matrisin elemanlarini girin:\n");
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            printf("%d. Satir %d. Sutun Degeri: ",i,j);
            scanf("%d", &matrix[i][j]);
        }
    }
}
void printMatrix(int n, int matrix[][MAX]) {
    int i,j;
    printf("Matris:\n");
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int n;
    int matrix[MAX][MAX];
    int path[2*MAX]={0}; // Yolu depolamak icin bir dizi olusturulur
    printf("Matris boyutunu girin: N>0 olmali");
    scanf("%d", &n);
    do{
        getMatrix(n, matrix);
        printMatrix(n, matrix);
        /* ... devami karede gorunmuyor ... */
```

<!-- BELİRSİZ: main fonksiyonunun do-while döngüsünden sonraki kısmı karelerde görünmüyor; altyazıda da anlatılmadı. -->

### 1.3 Kodun mantığı

Matris, `#define MAX 10` ile tanımlanan sabitle boyutlandırılır. Elemanlar ayrı bir fonksiyonda (`getMatrix`), iç içe iki `for` ile alınır.

Yolu bulan `countPaths` fonksiyonunun üç parçası vardır:

- **Durma koşulu:** `i == n-1` ve `j == n-1` ise sağ alt köşeye ulaşılmıştır. Son hücre de `path` dizisine eklenir ve yol yazdırılır. `path` dizisinde çift indisler satır numarasını, tek indisler sütun numarasını tutar; bu yüzden `printPath` döngüsü birer birer değil ikişer ikişer ilerler. Sonra `return 1` yapılır: "buradan bir yol var".
- **Geçersizlik koşulu:** `i >= n` ya da `j >= n` ise matrisin tanımlı boyutlarının dışına çıkılmıştır. `matrix[i][j] == 0` ise robot o odaya giremez. Bu durumlarda `return 0` yapılır: "geçerli yol yok". `||` kısa devre yaptığı için sınır dışı bir hücrede `matrix[i][j]` okunmaz.
- **Özyineleme:** Bu iki durumun dışında matrisin içindeyiz ve hücre 1'dir. Hücre `path` dizisine eklenir, sonra bir yönde ve diğer yönde fonksiyon yeniden çağrılır. Her çağrı, gittiği yolun sonuca ulaşıp ulaşmadığını (ulaşan yolların sayısını) geri döndürür. İki yönün toplamı yukarı iletilir; en üstteki çağrı başlangıçtan bitişe kaç farklı yol olduğunu verir.

Bir öğrenci özyinelemenin nerede olduğunu sordu. **Cevap:** Fonksiyon, her adımda iki komşu hücre için kendini yeniden çağırdığı satırlarda (`rightPaths = ...` ve `downPaths = ...`) özyinelemelidir.

> **Ders sonrası not:** Koddaki yorumlarda `countPaths(i + 1, j, ...)` "sağa gitme", `countPaths(i, j + 1, ...)` "aşağıya gitme" olarak yazılmış. `i` satır indisi olduğu için `i + 1` aslında bir satır aşağı, `j + 1` bir sütun sağa gider. Toplam sonuç bundan etkilenmez, yalnız değişken adları ve yorumlar yer değiştirmiştir.

> **Ders sonrası not:** `path` dizisi `2*MAX = 20` elemanlıdır, yani en çok 10 hücre tutar. $(0,0)$'dan $(n-1,n-1)$'e yalnız sağa ve aşağıya giden her yol $2n-1$ hücreden geçer, bu da $2(2n-1)$ tamsayı demektir. $n = 6$ için bu 22'dir ve dizi taşar; $n \ge 6$ için `path` dizisinin dışına yazılır. Bu C'de tanımsız davranıştır. Büyük olasılıkla dizinin boyutu `2*(2*MAX-1)` olmalıydı.

Kod ajan tarafından `gcc -Wall` ile derlendi ve `main` yerine elle yazılmış bir deneme ile çalıştırıldı (bu `main` derste yazılmadı). $3 \times 3$ matris

```text
1 1 0
1 1 1
0 1 1
```

için program dört rota yazdırdı ve toplamı 4 buldu:

```text
(0, 0) (1, 0) (1, 1) (2, 1) (2, 2)
(0, 0) (1, 0) (1, 1) (1, 2) (2, 2)
(0, 0) (0, 1) (1, 1) (2, 1) (2, 2)
(0, 0) (0, 1) (1, 1) (1, 2) (2, 2)
Toplam yol sayisi: 4
```

## 2. Lab sorusu üzerine sorular: dizinin paylaşılması, prototip, kapsam

### 2.1 Birden fazla rota aynı dizide nasıl tutuluyor?

Bir öğrenci yol sayısını bulabildiğini ama yolu yazdıramadığını söyledi. Bunun için yolun bir dizide tutulması gerektiği hatırlatıldı.

**Soru:** Birinci rota dizinin hangi indislerinde, ikinci rota nerede tutuluyor? Fonksiyon bir kez çalışınca yalnız bir rota göstermez mi?

**Cevap:** İlk akla gelen "her çağrıda `path` kopyalanıyor" düşüncesi yanlıştır; anlatan bunu kendisi de düzeltti. Dizi fonksiyona gönderildiğinde dizinin kendisi (adresi) gider, kopyalanmaz. Kopyalanan `pathLength` değeridir. Sürecin işleyişi tahtada bir matris üzerinde gösterildi:

- Başlangıç hücresi dizinin 0. ve 1. elemanlarına yazılır, `pathLength` 2 olur.
- Bir yöne gidilir, yeni hücre 2. ve 3. elemanlara yazılır; dallar sonuna kadar inilir ve hedefe varılınca yol yazdırılır.
- Fonksiyonlar geri döner (`return`), bir önceki çağrıya gelinir. O çağrıdaki `pathLength` kendi kopyasıdır, yani eski değerindedir. Diğer yöne gidildiğinde yeni hücre aynı indislere, eski rotanın üzerine yazılır.

Tek boyutlu dizinin üzerine yazılması sorun olmaz, çünkü her rota hedefe ulaşıldığı anda yazdırılmıştır. Yazdırıldıktan sonra başa dönülüp üzerine yazılır.

### 2.2 Her rotayı ayrı bir dizide saklamak

**Soru:** Her rotayı ayrı bir dizide tutmak isteseydik ne yapardık?

**Cevap:** Anlatan bunun iyi bir çözüm olmadığını ve emin olmadığını, bir fikir ürettiğini belirterek şunu önerdi: Satırları ayrı rotalar olan iki boyutlu bir dizi kullanılır. Kaç rota olduğu baştan bilinmez. İlk adımlar her rotada aynıdır. Yol ayrıldığı noktada, yani geri dönülüp başka bir karar verildiğinde, bir alt satıra geçilir, o ana kadarki adımlar yeni satıra kopyalanır ve yeni yönden devam edilir. Daha iyi bir çözüm düşünen olursa konuşulabileceği söylendi.

### 2.3 Parametresiz fonksiyon prototipi

**Soru:** `main`'den sonra tanımlanan fonksiyonlar için en üste yazılan prototipte parametreler yazılmadan (`void f();`) bırakılırsa program yine çalışıyor. Bu bir sorun mu?

**Cevap:** Normalde farklı bildirimler yüzünden hata beklenir; parantezin içi tamamen boş olduğu için derleyici kabul ediyor olabilir. Yine de böyle yazmamak gerekir. Farklı bir derleyici kullanılıyorsa risk vardır: bazı derleyiciler pek çok şeye izin verir, bazıları vermez. Derste kullanılan derleyici bu konularda katıdır. Örneğin `for` içinde değişken tanımlama (`for (int i = 0; ...)`) bu derleyicide kabul edilmez, ama daha modern C derleyicilerinin çoğu kabul eder. Bu yüzden başka bir derleyicide çalışılıyorsa kod, teslimden önce Dev-C++'ta ve derste verilen derleyici sürümünde de denenmelidir (ekranda Dev-C++ 5.11 ve TDM-GCC 4.9.2 görünüyor, ekrandan, 00:15:00).

> **Ek bilgi (derste anlatılmadı):** C'de `void f();` biçimi "parametreleri belirtilmemiş fonksiyon" anlamına gelir (C23'ten önce); derleyici çağrıdaki argümanları denetlemez, bu yüzden hata vermez. Parametresiz olduğu açıkça belirtilmek istenirse `void f(void);` yazılır. GCC 4.9'un varsayılan dil kipi C90 tabanlı olduğu için `for` içinde tanım kabul edilmez; `-std=c99` ile kabul edilir.

### 2.4 Aynı adlı parametre ve değişken

**Soru:** Fonksiyonlarda parametre adı hep `matrix` yazıldı. `main`'de `matrix2` adlı başka bir matris gönderilseydi, fonksiyon içinde hangi matrise erişilirdi?

**Cevap:** Gönderilen matrise (`matrix2`) erişilir. Bunun nedeni değişken kapsamıdır (variable scope). Fonksiyonda erişilen değişkenlerle `main`'de erişilen değişkenler farklıdır; isimleri aynı olsa da fonksiyon içindeki değişkenin erişim alanı yalnız o fonksiyondur.

## 3. Ağaç veri yapısı ve terimleri

Ağaç, programlamada çok kullanılan bir yapıdır; veri yapıları ve algoritma analizi derslerinde sürekli karşılaşılır. Ağaç; kökü olan, çocukları olan, içinde farklı düğümler (node) bulunduran bir yapıdır. Slayttaki ağaç (ekrandan, 00:30:00) şöyledir:

```text
                P            <- Root (kök), Key (anahtar)
           /         \
          Q           R
        /   \       /   \
       A     B     C     D        A ve B: Siblings (kardeş)
       |           |
       L           M
     / | \        / \
    E  F  G      H   I            H, I: Leaf nodes (yapraklar)

L'nin alt ağacı (Subtree): L, E, F, G   (L: Parent, E/F/G: Children)
Height of the tree (yükseklik): 4
```

- **Kök (root):** Ağacın başlangıç noktası. Birisi "kök" derse genelde ana kök (burada P) kastedilir.
- **Kenar (edge):** Düğümleri birbirine bağlayan bağlantılar.
- **Çocuk (child):** Bir düğümün altındaki düğümler. Genellikle iki tanedir: sol çocuk (left child) ve sağ çocuk (right child). Daha karmaşık ağaçlarda ikiden fazla olabilir (slayttaki L'nin üç çocuğu vardır), ama bu derste yalnız ikili ağaçlar görülür.
- **Yaprak (leaf node):** Çocuğu olmayan düğüm. Ağaç, çocuğu olmayan düğümlere gelene kadar ilerler. Tek çocuklu düğümler de olabilir (A ve C gibi).
- **Ebeveyn (parent):** Çocuğu olan düğüm.
- **Kardeş (sibling):** Aynı ebeveyne sahip düğümler.
- **Alt ağaç (subtree):** Her düğüm kendi çocukları ve onların torunlarıyla bir alt ağaç oluşturur. Q, P köklü ağacın elemanıdır; aynı zamanda Q'dan başlayan bir alt ağaç vardır. Alt ağaç ana ağacın altında kalır ama kendisi de bir ağaçtır. Alt ağacın kökü, o alt ağacın en üstteki düğümüdür (Q'nunki Q, L'ninki L).
- **Yükseklik (height):** Kökten en uzaktaki yaprağa ulaşırken atılan adım sayısıdır, düğüm sayısı değildir. P'den R'ye 1, C'ye 2, M'ye 3, I'ya 4 adım atılır; yükseklik 4'tür (ekrandan, 00:35:00).

**Soru:** Bir parçanın alt ağaç olması için en altta mı olması gerekir?

**Cevap:** Alt ağaç, seçilen düğümün bütün çocuklarını (ve onların çocuklarını) kapsamalıdır. Örneğin A'yı içeren bir parçanın alt ağaç olması için A'nın çocuklarını da içermesi gerekir. M, H ve I birlikte bir alt ağaçtır; ama bir düğümü alıp çocuklarından birini dışarıda bırakan parça alt ağaç değildir.

## 4. İkili arama ağacı (BST)

Ağaçlar diziler yerine kullanılır, çünkü ağaçlarla özel yöntemler ve saklama biçimleri kurulabilir. Bunlardan biri ikili arama ağacıdır (binary search tree). "İkili" olması her düğümün en çok iki çocuğu olduğunu gösterir. "Arama" ağacı olması, aramayı kendi kurulma kuralını kullanarak yapmasından gelir: kök, sol çocuktan büyük ve sağ çocuktan küçük olmak zorundadır ve bu kural bütün düğümler için geçerlidir.

Slayttaki örnek (ekrandan, 00:40:00):

```text
            40
         /      \
       30        50
      /  \      /  \
    25    35  45    60
```

- En küçük değere ulaşmak için hep sola gidilir (sol, sol, sol): 25.
- En büyük değere ulaşmak için hep sağa gidilir: 60.

> **Ders sonrası not:** Kural derste "kök, sol çocuktan büyük, sağ çocuktan küçük" diye söylendi. Kesin tanımda yalnız doğrudan çocuklar değil, bütün sol alt ağaç düğümden küçük, bütün sağ alt ağaç düğümden büyüktür. Derste yazılan kodda eşit değerler sola konduğu için sol alt ağaç "küçük ya da eşit" değerleri tutar.

### 4.1 İkili aramayla bağlantı

Öğrencilere ikili aramayı (binary search) görüp görmedikleri soruldu. İkili aramada her adımda dizinin yarısı elenir; yarısına bakmaya gerek kalmaz. BST'de de aynı mantık vardır. Örneğin 35 aranıyor:

- 40'a gelinir. 35, 40'tan büyük mü? Değil, sola gidilir.
- 30'a gelinir. 35, 30'dan büyük mü? Büyük, sağa gidilir.
- 35 bulunur.

Her adımda ağacın yarısı elenmiş olur. BST'nin normal dizideki ikili aramaya göre avantajı şudur: ağacı oluştururken diziyi sıralamak gerekmez. Ağaç iyi (dengeli) bir biçimde oluşturulduysa her arama adımında kalan elemanların yarısı elenir.

### 4.2 Dezavantaj: dengesiz ağaç

Ağaç oluşturulurken dengeli olmayabilir. Değerler 40, 30, 20, 10 sırasıyla gelirse ağaç tek kollu bir zincir olur (ekrandan, 00:40:00):

```text
40
  \__ 30 (sol çocuk)
        \__ 20 (sol çocuk)
              \__ 10 (sol çocuk)
```

Bu aslında sıralı bir diziden farksızdır ve aramada hiçbir kazanç sağlamaz. Bu durum bütün ağaçlar için geçerlidir: ağaca konma sırası önemlidir ve kötü bir sıra ağacın kötü oluşmasına yol açar. Bu bir uç durumdur (edge case); rastgele oluşturulan ağaçlar genellikle böyle olmaz.

## 5. Heap ile BST farkı

**Soru:** Binary heap ile BST'nin farkı ne, neden ikisi de kullanılıyor? Heap derste görülmedi.

**Cevap:** Heap'te sağdaki elemanın kökten büyük ya da küçük olması gibi bir şart yoktur. Min-heap'te kök dizinin en küçük elemanıdır ve ondan sonra gelen bütün değerler kökten büyük (ya da eşit) olmak zorundadır. Kökte 40 varsa iki çocuk da örneğin 50 ve 47 olabilir; iki çocuk da kökten büyüktür. Bu yüzden min-heap'te arama yaparken "artık sağ tarafa bakmama gerek yok" denemez. BST'de ise aranan değer düğümden büyükse ağacın diğer tarafına bakılmaz. Aradaki fark budur.

Heap'in kullanım amacı:

- BST oluştururken bir eleman bir kez yerine kondu mu (40 kökte, 30 solda, 50 sağda) bir daha yeri değişmez. Min-heap'te ise yeni gelen 39 köke yerleşmelidir; 40 yerinden alınıp oynatılır. Yeni eleman sağ çocuğa değil, ağacın sonuna eklenir ve gerekirse yukarı taşınır (ekrandan, 00:45:00).
- Bankada sıra örneği (sık verilen bir örnek): Banka her müşteriye bir öncelik değeri atar; çok değerli müşteriler daha erken girer. Sıradaki kişi belirlenirken en yüksek önceliğe sahip olan girer. Bunun için en öncelikli değer kökte tutulur ve her çekilişte kökteki değer alınır.
- Neden dizi sıralanıp baştan alınmıyor? İki nedeni var. Birincisi, sıralı diziye sonradan eleman eklenince hep kaydırma gerekir; heap'te sıralama olmadığı için eleman yalnız sona eklenir, ekleme ve çıkarma basittir. İkincisi, heap diziyi hiçbir zaman tümüyle sıralamaz; her adımda yalnız en küçük (ya da en öncelikli) elemanı bulup başa koyar.
- Aynı mantık işletim sistemlerinde de kullanılır: işlemci, hangi prosesin çalışacağını seçmek için her prosese bir değer verir ve en değerliyi çekmek için bunları bir heap'te tutabilir.

Heap de belirli kurallara göre oluşur, ama BST'de çocukların konumları daha nettir.

> **Ek bilgi (derste anlatılmadı):** Derste bankadaki örnekte "en değerli numarayı kökte tutuyor" ve ardından "en küçük değeri çekiyorsunuz" denildi. Bu, önceliğin hangi yönde sayıldığına bağlıdır: küçük sayı yüksek öncelik demekse min-heap, büyük sayı yüksek öncelik demekse max-heap kullanılır. Her iki durumda da kök en öncelikli elemandır.

## 6. BST'yi dizide tutma: indis formülleri

Ağaç, programlanırken çizimdeki gibi tutulamaz; düğümler bir dizide saklanır. Ağacı farklı bir yapıyla (bağlı yapılarla) tutmak da mümkündür, ama bu büyük olasılıkla sonraki yıl görülecektir. Burada dizi kullanılır. Soru şudur: düğümler dizide tutulunca sol çocuk ve sağ çocuk nasıl bulunur?

### 6.1 Kök 1'den numaralanırsa

Düğümler katman katman soldan sağa sayılır (ekrandan, 00:50:00): 40 → 1, 30 → 2, 50 → 3, 25 → 4, 35 → 5, 45 → 6, 60 → 7.

- Her katmandaki eleman sayısı: 1, 2, 4; bir katman daha olsa 8. Sayılar 2'nin kuvvetleriyle ilerler.
- En soldaki düğümler hep 2'nin kuvvetidir: 1, 2, 4, (bir katman daha olsa) 8, 16.
- 1'den sol çocuğa (2) gitmek için 2 ile çarpılır; sağ çocuğa (3) gitmek için 2 ile çarpılıp 1 eklenir.
- 2'nin sol çocuğu $2 \cdot 2 = 4$, sağ çocuğu $2 \cdot 2 + 1 = 5$; 3'ün sol çocuğu $3 \cdot 2 = 6$, sağ çocuğu $3 \cdot 2 + 1 = 7$.

Kural: kök 1 ise sol çocuk $2i$, sağ çocuk $2i + 1$.

### 6.2 Kök 0'dan numaralanırsa (C dizileri)

C'de diziler 0'dan başlar, kök 0. indise konur. 0'ın 2 katı yine 0 olduğu için formül bir kayar:

- Kök 0'ın sol çocuğu: $2 \cdot 0 + 1 = 1$. Sağ çocuğu: $2 \cdot 0 + 2 = 2$.
- 1'in sol çocuğu: $2 \cdot 1 + 1 = 3$. Sağ çocuğu: $2 \cdot 1 + 2 = 4$.

Sonuç (ekrandan, 01:00:00):

$$\text{sol çocuk} = 2i + 1, \qquad \text{sağ çocuk} = 2i + 2$$

Örnek ağaç dizide şöyle durur:

| İndis | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|---|
| Değer | 40 | 30 | 50 | 25 | 35 | 45 | 60 |

### 6.3 Boş hücreleri işaretleme

Dizide kullanılmayan hücrelerin ayırt edilmesi gerekir. Tanımlanan bir yerel dizi başlangıçta rastgele değerler taşıyabilir; ayrıca 0 da girilebilecek bir değer olabilir. Bu yüzden boş hücreler gelmeyecek bir değerle işaretlenir: yalnız pozitif değerler gireceği varsayılarak -1 seçildi. Dizi 1024 elemanlıdır ve bir döngüyle doldurulur (ekrandan, 01:05:00):

```c
for(i=0;i<1024;i++){
    BST[i]=-1;
}
```

**Soru (derste sözlü):** Diziyi `int BST[1024] = {-1};` diye başlatsaydık ne olurdu?

**Cevap:** Yalnız ilk eleman -1 olur, geri kalanlar 0 olur. `{-1, -1}` yazılırsa ilk iki eleman -1, gerisi 0 olur. `{0}` yazılınca hepsinin 0 olması da aynı kuralın sonucudur.

> **Hocanın vurgusu:** Dizi başlatmayla ilgili bu tür ayrıntılar sınavlarda sık çıkar; bu yüzden dizi döngüyle -1'e doldurulur.

Bu davranış ajan tarafından `gcc` ile denendi: `int a[5] = {-1};` için çıktı `-1 0 0 0 0` oldu.

### 6.4 Rastgele değerlerin üretilmesi

Rastgele sayı kullanılacağı için önce `srand(time(NULL))` ile tohum (seed) verilir. `#define Max 100` ile değerlerin üst sınırı belirlenir. `n` ağaca konacak değer sayısıdır; bu değerler `Random_Numbers` dizisinde tutulur (ekrandan, 01:05:00 ve 01:25:00):

```c
srand(time(NULL));
printf("Random Numbers: ");
for(i=0;i<n;i++){
    Random_Numbers[i]=rand()%Max;
    printf("%d ",Random_Numbers[i]);
}
printf("\n");
```

Kod ekranda küçük göründüğü için bir öğrencinin isteği üzerine yakınlaştırıldı.

## 7. BST'de ekleme ve arama (iteratif ve özyinelemeli)

### 7.1 Ekleme bir aramadır

BST'ye eleman koyarken ne bilinmelidir? 40 köke kondu, 30 geldi: 30'un 40'tan küçük mü büyük mü olduğu bilinmelidir. 25 geldi: önce 40 ile, sonra 30 ile karşılaştırılır ve yolda ilk -1 görülen yere konur. Yani ekleme sırasında da aslında arama yapılır. Normal bir değer aranırken de aynı yol izlenir; tek fark, eklemede -1 görülünce "buraya koy", aramada -1 görülünce "bulunamadı" denmesidir.

Bu yüzden ikisi tek fonksiyonla yazılır: `Find_Index(int BST[], int number, int mode)`. `number` aranan ya da eklenecek değerdir; `mode` 0 ise ekleme, 1 ise arama yapılır.

**Soru (derste sözlü):** Neden `mode` parametresi koyduk? Neden yalnız -1 görülen yeri döndürüp ana programda kontrol etmedik?

**Cevap:** Bir öğrenci "eklerken nereye koyacağımızı biliyoruz" dedi; ama tam yerin indisi bilinmez, aranan şey odur. Asıl neden şudur: diziye tekrar 30 eklenmek istendiğinde, fonksiyon arama gibi çalışırsa 30'u görüp orada durur. Eklemede ise aynı değer görülse de -1 bulunana kadar devam edilmesi istenir. Bu iki davranışı ayırmak için `mode` gerekir.

### 7.2 Döngü seçimi

**Soru (derste sözlü):** Ağaçta gezinirken `for` mu kullanılır, `while` mı?

**Cevap:** `while`. Bütün diziyi baştan sona gezmek gerekmez; belirli noktalara gelince çıkılır. Bir öğrenci "-1 bulunana kadar devam edeceğimiz için while" dedi; asıl gerekçe çıkışın dizi sonuna değil, koşula bağlı olmasıdır.

### 7.3 Yardımcı fonksiyonlar ve iteratif sürüm

Her seferinde formülü yazmak yerine iki küçük fonksiyon tanımlandı (ekrandan, 01:35:00):

```c
int Move_Left(int i){
    return i*2+1;
}
int Move_Right(int i){
    return i*2+2;
}
```

İteratif arama/ekleme fonksiyonu önce bir `Kontrol` değişkeni ile `while(Kontrol == 0)` biçiminde başladı (ekrandan, 01:05:00). Bir öğrenci kontrol değişkeni hiç değişmediği için döngünün sonsuza kadar dönüp dönmeyeceğini sordu. **Cevap:** Dönmez, çünkü döngünün içindeki `return` koşulu mutlaka sağlanır ve fonksiyondan çıkılır; ama kontrol değişkeni gerçekten gereksizdir. Bu yüzden `while(1)` kullanıldı ve kod yine çalıştı (ekrandan, 01:10:00 ve 01:35:00):

```c
int Find_Index_Ite(int BST[],int number,int mode){
    int i=0;

    while(1){
        if((BST[i]==-1)||((mode==1)&&(BST[i]==number)))
            return i;
        if(number>BST[i]){
            i=Move_Right(i);
        }else{
            i=Move_Left(i);
        }
    }
}
```

- Çıkış koşulu: `BST[i] == -1` ise boş hücre bulunmuştur, indisi döndürülür. Arama kipindeyse (`mode == 1`) ve `BST[i] == number` ise bulunan yer döndürülür.
- Sayı bulunulan düğümden büyükse sağ çocuğa (`2i+2`), değilse sol çocuğa (`2i+1`) gidilir. Bir öğrenci "sağa gitmek için i'yi 1 artırır mıyız" diye sordu; dizide değil ağaçta arandığı için indis bir artmaz, çocuğun indisine atlanır.

**Soru:** Eşitlik kontrol edilmediği için eşit değer doğrudan sola mı gidiyor?

**Cevap:** Evet, eşitse sola konur.

> **Ders sonrası not:** Arama kipinde (`mode == 1`) aranan değer ağaçta yoksa fonksiyon "bulunamadı" anlamına gelen ayrı bir değer döndürmez; değerin ekleneceği boş hücrenin indisini döndürür. Ajanın denemesinde 9, 6, 12, 4, 8, 10, 14 ağacında 11 arandığında 12 döndü (o hücre boştur). Çağıran kod `BST[indis] == -1` ise "bulunamadı" demelidir.

### 7.4 Özyinelemeli sürüm

`while` kullanımı biraz "göze çirkin" bulundu; ağaçlar genelde özyinelemeyle gezilir. Özyinelemeli sürümde koşullar aynen kalır; yalnız her çağrıda nerede olunduğunu bilmek için `i` parametresi eklenir ve fonksiyon yeni indisle kendini çağırır (ekrandan, 01:15:00):

```c
int Find_Index_Rec(int BST[],int i,int number,int mode){
    if((BST[i]==-1)||((mode==1)&&(BST[i]==number)))
        return i;
    if(number>BST[i]){
        i=Move_Right(i);
    }else{
        i=Move_Left(i);
    }

    return Find_Index_Rec(BST,i,number,mode);
}
```

**Soru:** Özyinelemeli ve iteratif sürümün bellekteki (stack) etkisi aynı mı?

**Cevap:** Özyinelemeli sürüm teknik olarak biraz daha kötüdür, ama fark çok azdır. Her çağrıda `i`, `number`, `mode` gibi değişkenler kopyalanır. `BST` dizisi ise kopyalanmaz; yalnız adresi (pointer) kopyalanır, yani 1024 tamsayı her çağrıda kopyalanmaz.

## 8. BST oluşturma ve pre-order yazdırma

### 8.1 Create_BST

Değerlerin hepsi ağaca konacağı için döngü `for` olur. Her değer için önce ekleme kipinde (`mode = 0`) yeri bulunur, sonra değer o indise yazılır (ekrandan, 01:30:00):

```c
void Create_BST(int BST[],int Values[],int n){
    int i;

    for(i=0;i<n;i++){
        int Index=Find_Index_Rec(BST,0,Values[i],0);
        BST[Index]=Values[i];
    }
}
```

Derste ilk yazımda başlangıç indisi olarak döngü değişkeni `i` gönderildi (ekrandan, 01:15:00) ve yerleşimler yanlış çıktı. Arama her zaman kökten (0'dan) başlamalıdır; düzeltilince doğru çalıştı.

### 8.2 Ekleme örneği

Programın ürettiği rastgele değerlerle ekleme adım adım izlendi (değerler her çalıştırmada değişir; altyazıdan izlenen bir çalıştırma):

- 72 boş ağaçta 0. indise (köke) konur.
- 70, 72'den küçük → $2 \cdot 0 + 1 = 1$. indise konur.
- Sonraki değer 72'den ve 70'ten küçük → $2 \cdot 1 + 1 = 3$. indis.
- Bir değer 72'den ve 70'ten küçük, 3. indistekinden büyük → $2 \cdot 3 + 2 = 8$. indis.

<!-- BELİRSİZ: Bu çalıştırmadaki rastgele değerlerin tamamı altyazıdan net okunamadı ve karede görünmüyor; yalnız indis hesabının mantığı aktarıldı. -->

### 8.3 Pre-order yazdırma

1024 hücrenin hepsini indisleriyle yazdırmak mümkündür ama karmaşıktır ve verimli değildir. Bunun yerine ağaç gezme (traversal) yöntemleri kullanılır. Pre-order yazdırmada önce düğüm yazdırılır, sonra sol çocuğun alt ağacı, sonra sağ çocuğun alt ağacı gezilir. Örnek ağaçta (ekrandan, 01:20:00) önce 40, sonra 30, sonra 25 yazdırılır; 25'in çocuğu yoktur, 30'a geri dönülüp sağ çocuk 35 yazdırılır; sonra köke geri dönülüp sağ taraf (50, 45, 60) gezilir. Sonuç: 40 30 25 35 50 45 60.

```c
void Print_BST(int BST[],int i){
    if(BST[i]==-1)
        return;
    printf("%d ",BST[i]);
    Print_BST(BST,Move_Left(i));

    Print_BST(BST,Move_Right(i));
}
```

(ekrandan, 01:25:00)

Çıkış koşulu: `BST[i] == -1` ise ağacın içinde olmayan bir yere gelinmiştir, geri dönülür. Ana programda `Print_BST(BST, 0)` ile kökten başlatılır ve sonuna bir satır sonu yazdırılır.

Rastgele bir çalıştırmanın pre-order çıktısı da okundu: 86 kök; 47, 86'dan küçük olduğu için sol çocuğu; 3, 47'nin sol çocuğu; 45, 3'ün sağ çocuğu; 37, 45'in sol çocuğu; 52, 86'dan küçük ve 47'den büyük olduğu için 47'nin sağ çocuğu ($2 \cdot 1 + 2 = 4$. indis); 58, 52'nin sağ çocuğu; 90, 86'dan büyük olduğu için kökün sağ çocuğu.

Yazdırma satırının yeri değişince diğer gezme türleri elde edilir:

- **In-order:** önce sol alt ağaç, sonra düğüm, sonra sağ alt ağaç.
- **Post-order:** önce sol, sonra sağ alt ağaç, en son düğüm.

> **Ek bilgi (derste anlatılmadı):** BST'de in-order gezme değerleri küçükten büyüğe sıralı verir; örnek ağaç için 25 30 35 40 45 50 60.

Kod ajan tarafından kareden yeniden kurulup `gcc -Wall` ile derlendi; 40, 30, 50, 25, 35, 45, 60 sırasıyla eklenen değerler için pre-order çıktısı `40 30 25 35 50 45 60` oldu.

## 9. Dengesiz ağaç ve dengeli BST oluşturma

### 9.1 Dizi neden taşar?

Bir öğrencinin sorusu üzerine dengesizlik konusuna dönüldü. Bütün değerler kökten küçük gelirse hep sol çocuğa gidilir ve indisler üstel olarak büyür: 0, 1, 3, 7, 15, 31, ... ($2^d - 1$). 1024 elemanlı dizide bu zincire 11 eleman sığar ($2^{10} - 1 = 1023$). `n` 100 yapılıp sıralı 100 değer verilince program çöktü: ağaçta ilerlemeye çalışıyor ama indis 1024'e sığmıyor (ekrandan, 01:25:00).

> **Ders sonrası not:** Programın "patlaması", `BST[i]` okunurken `i` değerinin 1024'ü geçmesinden kaynaklanır. Dizinin dışını okumak C'de tanımsız davranıştır; program çökebilir ya da sessizce yanlış çalışabilir. Ayrıca `Return_Sum` gibi fonksiyonlar yapraktaki düğümün çocuk indisine (`2i+2`) baktığı için, 511 ve sonrası indislerdeki düğümlerde de dizi dışı okuma yapılır.

Heap'in burada avantajı vardı: elemanı doğrudan sona eklediği için böyle bir sorunu yoktur. BST'de bu sorun vardır. Sıralı gelen değerler 10, 20, 30, 40 gibi en kötü durumu oluşturur. Bu düzensiz yapıya dengesiz ağaç (unbalanced tree) denir.

### 9.2 Dengeli ağaç kurmanın yolları

- **Sırala ve ortadan başla:** Dizi sıralanır, orta noktasından başlanarak ağaca eklenir. Derste bu yöntem kodlandı.
- **Sonradan düzenleme:** Ağacı oluşturduktan sonra dengesiz olduğu anda ağacı değiştirmek. Bu daha karmaşıktır, derste anlatılmadı; merak edenlerin araştırması önerildi.

### 9.3 Create_Balanced_BST

`Start` ve `End`, ağacın değil, `Values` dizisinin başlangıç ve bitiş noktalarıdır. Her adımda bu aralığın ortası alınıp ağaca eklenir (ekrandan, 01:30:00 ve 01:40:00):

```c
void Create_Balanced_BST(int BST[],int Values[],int Start,int End){
    if(Start>End)
        return;
    int mid=(Start+End)/2;
    int Index=Find_Index_Rec(BST,0,Values[mid],0);
    BST[Index]=Values[mid];
    Create_Balanced_BST(BST,Values,Start,mid-1);
    Create_Balanced_BST(BST,Values,mid+1,End);
}
```

- Durma koşulu: `Start > End` ise aralık boştur, bakılması gereken yerlere bakılmıştır.
- Orta eleman eklenir; sonra sol yarı (`Start`, `mid-1`) ve sağ yarı (`mid+1`, `End`) için aynı işlem yapılır.
- Orta noktalar sırayla eklendiği için ağaç dengeli olur.

Ekranda sınama için sıralı ve tekrarlı değerler içeren 100 elemanlı sabit bir dizi tanımlandı (ekrandan, 01:40:00). Aynı dizi `Create_BST` ile verilince program çöktü, `Create_Balanced_BST(BST, Random_Numbers, 0, n)` ile verilince ağaç oluştu.

> **Ders sonrası not:** İlk çağrıda `End = n` verildi; anlatan da sonra "aslında burası n-1 oluyor" diyerek düzeltti. `End = n` ile `Values[n]` okunabilir; bu dizinin dışıdır ve tanımsız davranıştır. Doğru çağrı `Create_Balanced_BST(BST, Values, 0, n-1)` biçimindedir.

Ajanın denemesinde sıralı `{4, 6, 8, 9, 10, 12, 14}` dizisi `0, 6` aralığıyla verildi; pre-order çıktısı `9 6 4 8 12 10 14` oldu, yani kök 9 olan dengeli bir ağaç kuruldu.

## 10. Kapsam (scope) ve global değişkenler

**Soru:** `for` içinde `int Index` yazdık. Her turda `Index` adında yeni bir değişken mi tanımlanıyor?

**Cevap:** Evet. Bu da kapsamla ilgilidir. Bloğun içinde her seferinde yeni bir `Index` tanımlanır; blok dışında, örneğin döngüden sonra `printf("%d", Index)` yazılırsa derleyici bu adı tanımaz. Bloğa girmek yeni bir alana girmek gibidir; alandan çıkınca içinde tanımlanan değişkenler görülmez ve silinir. Ekranda bu hata gösterildi: `'Index' undeclared (first use in this function)` (ekrandan, 01:35:00). Bu fonksiyon kapsamına benzer ama blok kapsamıdır.

Global değişkenler bütün fonksiyonların dışında tanımlanır (örneğin `int TMP = 10;`) ve kapsamı bütün programdır; her yerde kullanılabilir. Başka bir C dosyasında tanımlanan global değişkene de, o dosya programa dahil edildiğinde `extern` ile erişilebilir. Bunun ayrıntıları büyük olasılıkla sonraki dönem görülecektir.

> **Hocanın vurgusu:** Global değişken kullanmayın. Amaç bunun alışkanlık hâline gelmemesidir.

Neden zararlı? Normal yazılan kodlarda çok fark olmaz, ama çok iş parçacıklı (multi-thread) programlarda sorun çıkar. Bir iş parçacığı değişkeni değiştirirken diğeri aynı değişkeni okuyabilir; kontrol yoksa (global değişkenlerde böyle bir kontrol kendiliğinden sağlanmaz) birinin yaptığı değişiklik diğerini etkiler. Banka hesabı örneği:

- Hesapta 100 var.
- Birinci iş parçacığı 100'ü okur, 10 ekleyip 110 yazacaktır.
- Bu sırada ikinci iş parçacığı da 100'ü okur, 10 çıkarır ve 90'ı yazar.
- Ardından birinci iş parçacığı 110'u yazar.
- Bir kez 10 eklenip bir kez 10 çıkarıldığı için sonuç 100 olmalıydı, ama 110 olur.

Global değişkenlerde bu durumun denetlenmesi çok zordur.

> **Ek bilgi (derste anlatılmadı):** Bu duruma yarış durumu (race condition) denir. Çözüm, değişkene erişimi kilit (mutex) gibi eş zamanlama araçlarıyla sırayla yapmaktır.

## 11. Örnek problem: alt ağaç ortalaması

### 11.1 Problem

BST'de her düğüm için şu kontrol edilir: düğümün alt ağacındaki bütün düğümlerin (kendisinden sonra gelen bütün torunların) ortalaması düğümün kendi değerine eşit mi? Kontrol bütün alt ağaçlar için yapılır; örneğin slayttaki ağaçta 40, 30 ve 50 için ayrı ayrı (ekrandan, 01:45:00).

Çözüm fikri: alttaki çocukların toplamları özyinelemeyle yukarı taşınır. Her düğümde bu toplamın ortalamasının düğüme eşit olup olmadığına bakılır.

### 11.2 İlk sürüm: Return_Sum

```c
int Return_Sum(int BST[],int Index){
    int Left_Sum,Right_Sum;
    if(BST[Move_Left(Index)]==-1 && BST[Move_Right(Index)]==-1){
        return BST[Index];
    }
    if(BST[Move_Left(Index)]!=-1){
        Left_Sum=Return_Sum(BST,Move_Left(Index));
    }else{
        Left_Sum=0;
    }
    if(BST[Move_Right(Index)]!=-1){
        Right_Sum=Return_Sum(BST,Move_Right(Index));
    }else{
        Right_Sum=0;
    }
    if(BST[Index]==(Left_Sum+Right_Sum)/2)
        printf("Index %d is Average of its Sub Trees\n",Index);
    return BST[Index]+Left_Sum+Right_Sum;
}
```

<!-- BELİRSİZ: Bu ilk sürüm altyazıdaki anlatımdan kuruldu; karede yalnız ikinci (Count'lu) sürüm görünüyor. -->

- Durma koşulu: sol ve sağ çocuk da -1 ise düğüm yapraktır, yalnız kendi değeri döndürülür.
- Tek çocuk olabileceği için her taraf ayrı kontrol edilir; çocuk yoksa o tarafın toplamı 0 alınır.
- Dönüş değeri, düğümün kendisi ile iki alt ağacın toplamıdır.

### 11.3 Elle izleme

Örnek ağaç (ekrandan, 01:45:00):

```text
            9
         /     \
        6       12
       / \     /  \
      4   8   10   14
```

- 6 için: $(4 + 8)/2 = 6$. Eşit.
- 12 için: $(10 + 14)/2 = 24/2 = 12$. Eşit.
- 9 için: yalnız $6 + 12$ mi alınır? Hayır; 9'un alt ağacı ağacın tamamıdır. Sol alt ağacın toplamı $4 + 6 + 8 = 18$, sağ alt ağacın toplamı $10 + 12 + 14 = 36$. Toplam $18 + 36 = 54$, eleman sayısı 6, ortalama $54/6 = 9$. Eşit.

**Soru (derste sözlü):** Yazdığımız kod bu ağaçta sonucu bulur mu?

**Cevap:** Bulmaz. Ağaç `n = 7` değerle kurulup kod çalıştırıldığında yalnız indis 1 (6) ve indis 2 (12) bulundu. Neden: toplam 2'ye bölündü. Kökte $54/2 = 27 \ne 9$ çıkar. İkiye değil, alt ağaçtaki eleman sayısına bölmek gerekir.

### 11.4 Düzeltilmiş sürüm: eleman sayısı

Alt ağacın eleman sayısını bulan ikinci bir fonksiyon yazıldı. Çıkış koşulu aynıdır, ama yaprakta düğümün değeri yerine 1 döndürülür; sonunda sol ve sağ sayılarla kendisi (1) toplanır:

```c
int Return_count(int BST[],int Index){
    int Left_Count,Right_Count;
    if(BST[Move_Left(Index)]==-1 && BST[Move_Right(Index)]==-1)
        return 1;
    if(BST[Move_Left(Index)]!=-1)
        Left_Count=Return_count(BST,Move_Left(Index));
    else
        Left_Count=0;
    if(BST[Move_Right(Index)]!=-1)
        Right_Count=Return_count(BST,Move_Right(Index));
    else
        Right_Count=0;
    return Left_Count+Right_Count+1;
}
```

<!-- BELİRSİZ: Return_count karelerde görünmüyor; altyazıdaki anlatımdan kuruldu. -->

`Return_Sum` içinde `Count` değişkeni eklenir: sol çocuk varsa `Count = Return_count(sol)`, yoksa `Count = 0`; sağ çocuk varsa `Count += Return_count(sağ)`, yoksa değişmez. Bölme artık `Count` ile yapılır (ekrandan, 01:50:00):

```c
    int Count;
    if(BST[Move_Left(Index)]!=-1){
        Left_Sum=Return_Sum(BST,Move_Left(Index));
        Count=Return_count(BST,Move_Left(Index));
    }else{
        Left_Sum=0;
        Count=0;
    }
    if(BST[Move_Right(Index)]!=-1){
        Right_Sum=Return_Sum(BST,Move_Right(Index));
        Count+=Return_count(BST,Move_Right(Index));
    }else{
        Right_Sum=0;
    }

    if(BST[Index]==(Left_Sum+Right_Sum)/Count)
        printf("Index %d is Average of its Sub Trees\n",Index);

    return BST[Index]+Left_Sum+Right_Sum;
```

Yeniden çalıştırıldığında çıktı indis 1, 2 ve 0 oldu: üç düğümün de ortalama koşulunu sağladığı bulundu. Sıranın 1, 2, 0 olması, kontrolün çocuklardan sonra yapılmasından (post-order) gelir.

Ajan bu kodu kareden ve altyazıdan yeniden kurup `gcc -Wall` ile derledi ve 9, 6, 12, 4, 8, 10, 14 ağacında çalıştırdı; çıktı derstekiyle aynıydı:

```text
Index 1 is Average of its Sub Trees
Index 2 is Average of its Sub Trees
Index 0 is Average of its Sub Trees
```

Derste ardından eleman sayısını ayrı ayrı iki çağrıyla hesaplamak yerine tek bir indisin sayısına bakmanın yeterli olup olmayacağı denendi; bir an program hiçbir düğümü bulamadı, sonra "kendini saymasın diye" bir yere -1 eklenince yine doğru çalıştı.

<!-- BELİRSİZ: 01:50:29 - 01:52:40 arasındaki bu son değişikliğin hangi satıra yapıldığı altyazıdan ve karelerden çıkarılamadı. Yukarıdaki iki fonksiyonlu sürüm doğru sonucu verir. -->

> **Ders sonrası not:** `Return_count` bir düğümün kendisi dahil alt ağacındaki düğüm sayısını verir. Düğümün kendi alt ağacı için bölünecek sayı, çocuklarının `Return_count` değerlerinin toplamıdır (düğümün kendisi hariç). Kökte kendi `Return_count` değeri kullanılsaydı 7 elde edilir ve 1 çıkarılması gerekirdi; büyük olasılıkla derste söylenen "-1" bu türden bir düzeltmeydi.

## Örnek Sorular

**1. Robotun rotaları (lab sorusu)** (ekrandan, 00:15:00)

$n \times n$ matriste robot $(0,0)$'dan başlar, $(n-1,n-1)$'de durur; değeri 0 olan hücreye giremez, 1 olana girebilir. Bütün rotaları yazdıran ve rota sayısını özyinelemeyle bulan programı yazın.

> **Çözüm:** Bölüm 1.2'deki `countPaths` fonksiyonu: hedefte yolu yazdırıp 1, geçersiz ya da 0 olan hücrede 0 döndürür; diğer durumda hücreyi `path`'e ekler ve iki yöndeki çağrıların toplamını döndürür. Ajanın denediği matris `{{1,1,0},{1,1,1},{0,1,1}}` için sonuç 4 rotadır.

**2. Dizi başlatma** (derste sözlü, 00:56:49)

`int BST[1024] = {-1};` yazılırsa dizinin elemanları ne olur?

> **Çözüm:** `BST[0] = -1`, diğer bütün elemanlar 0 olur. `{-1, -1}` yazılırsa ilk iki eleman -1, gerisi 0 olur.

**3. Ekleme ve aramanın tek fonksiyonda yazılması** (derste sözlü, 01:01:47)

Ekleme ve arama aynı `Find_Index` fonksiyonuyla yapılıyor. Neden ayrıca bir `mode` parametresi gerekir?

> **Çözüm:** Aynı değer ağaçta zaten varsa, arama o değeri görünce durmalıdır, ekleme ise -1 bulunana kadar devam etmelidir. `mode` bu iki davranışı ayırır.

**4. Ağaçta gezinme döngüsü** (derste sözlü, 01:04:18)

Ağaçta bir değer ararken `for` mu, `while` mı kullanılır?

> **Çözüm:** `while`; çünkü dizinin tamamı gezilmez, belirli bir koşul (boş hücre ya da aranan değer) sağlanınca çıkılır.

**5. BST alt ağaç ortalaması** (ekrandan, 01:45:00)

Bir BST'de her düğüm için alt ağacındaki bütün düğümlerin ortalamasının düğümün değerine eşit olup olmadığını bulan özyinelemeli fonksiyonu yazın. Kök 9, sol çocuk 6 (çocukları 4, 8), sağ çocuk 12 (çocukları 10, 14) olan ağaçta hangi düğümler koşulu sağlar? Toplamı 2'ye bölen kod doğru sonuç verir mi?

> **Çözüm:** 6 ($12/2$), 12 ($24/2$) ve 9 ($54/6$) koşulu sağlar; dizide indis 1, 2 ve 0. Toplamı 2'ye bölen kod yalnız 6 ve 12'yi bulur, kökte $54/2 = 27$ çıkar. Toplam, alt ağaçtaki eleman sayısına bölünmelidir (Bölüm 11.4).

## Dersin Toparlaması

Bu uygulama oturumunda önce bir özyineleme lab sorusunun çözümü incelendi: hedefe ulaşan dalın 1, geçersiz dalın 0 döndürdüğü ve sonuçların toplanarak yukarı taşındığı bir rota sayma fonksiyonu. Bu çözüm üzerinden dizilerin fonksiyonlara adresle gitmesi, değişken kapsamı ve derleyiciler arasındaki farklar tartışıldı.

İkinci bölümde ağaç terimleri (kök, kenar, çocuk, yaprak, kardeş, alt ağaç, yükseklik), ikili arama ağacının kuralı ve heap ile farkı anlatıldı. BST, kök 0 olacak şekilde dizide tutuldu: sol çocuk $2i+1$, sağ çocuk $2i+2$. Ekleme ve arama aynı yürüyüşle, önce `while` ile sonra özyinelemeyle yazıldı; ağaç pre-order gezilerek yazdırıldı. Sıralı verinin ağacı dengesizleştirip diziyi taşırdığı gösterildi ve sıralı diziyi ortadan başlayarak ekleyen dengeli BST kurma yöntemi kodlandı. Son olarak global değişkenlerin çok iş parçacıklı programlarda yarattığı sorun anlatıldı ve alt ağaç ortalaması problemi, toplamla birlikte eleman sayısının da yukarı taşınması gerektiği gösterilerek çözüldü. Ağaçları bağlı yapılarla tutmanın büyük olasılıkla sonraki derslerde görüleceği söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
