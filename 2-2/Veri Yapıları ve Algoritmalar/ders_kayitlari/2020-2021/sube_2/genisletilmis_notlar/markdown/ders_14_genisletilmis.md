# Ders 14 Genişletilmiş Notu: Çoklu Ağaçların İlk Çocuk / Sonraki Kardeş Gösterimi ve Dizin Simülasyonu

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Oturumun Akışı
- 2. Çoklu Ağaçlar ve Ağacın Derecesi
- 3. Çoklu Ağacı İkili Ağaç Olarak Gösterme
- 4. İki İşaretçi ile Genel Ağaç Oluşturma
- 5. Uygulama Problemi: Ağaçla Dizin Simülasyonu
- 6. Komutlar ve Hata Durumları
- 7. Soru-Cevap
- Örnek Sorular
- Dersin Toparlaması

## 1. Oturumun Akışı

Bu kısa oturum dersin uygulama saatiydi. Yeni bir konu anlatılmadı; bir önceki haftada işlenen çoklu ağaçlar (m-ary / n-ary tree) konusuna geri dönülüp çok çocuklu bir ağacın yalnız iki işaretçiyle nasıl gösterileceği tekrar edildi. Ardından bu gösterimin doğrudan kullanılacağı bir uygulama problemi, yani ağaç veri yapısıyla bir dizin (klasör) sistemi simülasyonu, örneklerle açıklandı. Kayıt Zoom üzerinden yapıldı; hoca önce PowerPoint slaytlarını, sonra beyaz tahta (whiteboard) alanını paylaştı.

## 2. Çoklu Ağaçlar ve Ağacın Derecesi

Çoklu ağaç, bir düğümün ikiden fazla çocuğu olabilen ağaçtır. Farklı kaynaklarda m'li (m-ary) ya da n'li (n-ary) ağaç diye geçer; harf kaynağa göre değişir.

Ağacın derecesi, ağaçtaki en çok çocuğa sahip düğümün çocuk sayısıdır. Hoca önce "seviyesi" deyip hemen "derecesi" diye düzeltti. Slayttaki örnekte (ekrandan, 00:10:00) kök A'nın altı çocuğu vardır: B, C, D, E, F, G. Diğer düğümlerde B'nin 3 (H, I, J), H'nin 2 (N, O), E'nin 2 (K, L), K, L ve G'nin 1'er çocuğu vardır. En büyük değer 6 olduğu için bu ağaç 6'lı ağaç olarak tanımlanır.

Örnek ağacın yapısı (ekrandan, 00:10:00):

```text
A
  B
    H
      N
      O
    I
    J
  C
  D
  E
    K
      P
    L
      Q
  F
  G
    M
```

Bu ağaç 4 seviyelidir: A; B-G; H, I, J, K, L, M; N, O, P, Q.

## 3. Çoklu Ağacı İkili Ağaç Olarak Gösterme

Gerçeklemede (implementasyon) her düğüme 6 ya da daha fazla çocuk işaretçisi koymak hem bellek israfıdır hem de çocuk sayısı önceden bilinmiyorsa mümkün değildir. Slayttaki kural şöyledir (ekrandan, 00:10:00):

> "Çok evlatlı ağaçlar, ikili ağaç olarak ifade edilebilir. İlk oğul için bir işaretçi, sağdaki ilk kardeş için bir işaretçi yeterlidir."

Hoca, slayttaki sağ şeklin Wikipedia'dan alındığını belirtti. Her düğümde iki işaretçi tutulur: biri altındaki ilk çocuğu, diğeri sağındaki ilk kardeşi gösterir. Hoca dönüşümü düğüm düğüm yaptı:

- A kök olduğu için kardeşi yoktur; ilk çocuğu B'dir.
- B'nin ilk çocuğu H, kardeşi C'dir. Böylece A'dan B'ye, B'den H'ye ya da B'den C'ye geçilebilir.
- C'nin çocuğu yoktur, kardeşi D'dir. D'nin de çocuğu yoktur, kardeşi E'dir.
- E'nin ilk çocuğu K'dir; burada yapı "çatallanır". E'nin kardeşi F'dir.
- F'nin çocuğu yoktur, kardeşi G'dir. G'nin çocuğu M'dir, kardeşi yoktur.

Çocuğu ya da kardeşi olmayan işaretçiler aslında `NULL`'dır. Hoca bunları önce `NULL` diye çizdi, sonra şekil kalabalık olmasın diye sildi.

Bütün ağacın ikili gösterimi (sol = ilk çocuk, sağ = kardeş; ekrandan, 00:10:00):

| Düğüm | İlk çocuk (sol) | Sağdaki kardeş (sağ) |
|---|---|---|
| A | B | — |
| B | H | C |
| C | — | D |
| D | — | E |
| E | K | F |
| F | — | G |
| G | M | — |
| H | N | I |
| I | — | J |
| J | — | — |
| N | — | O |
| K | P | L |
| L | Q | — |
| M, O, P, Q | — | — |

Bu gösterimde B, C, D, E, F, G seviyesine A'dan tek bağlantıyla erişilir, sonra bağlı listedeki gibi `next`, `next` diye bu seviye gezilir. Bir alt seviyeye inmek için ilgili düğümün çocuk işaretçisi kullanılır: B'den H'ye inip H, I, J; E'den K'ye inip K, L gezilir. H'den N'ye inilip O'ya, K'den P'ye, L'den Q'ya geçilir.

Bedeli şudur: ikili gösterimde ağacın yüksekliği ciddi biçimde artar. Buna rağmen her düğümün yalnız iki işaretçisi olduğundan yapı ikili ağaç mantığıyla çok daha rahat gerçeklenir.

## 4. İki İşaretçi ile Genel Ağaç Oluşturma

İkinci slaytta (ekrandan, 00:15:00) aynı fikir el çizimi bir örnekle gösterilir. Genel ağaç:

```text
V0
  V1
    V5
    V6
  V2
  V3
    V7
      V10
    V8
    V9
  V4
```

Bu 4 seviyeli bir ağaçtır. Slayttaki düğüm kutusu üç alanlıdır: veri, çocuk (c) ve kardeş (k). Aşağı ok çocuğu, yatay ok kardeşi gösterir. Bellekteki karşılığı slayttaki kutu-ok çizimine göre şöyledir:

```text
kök -> V0
V0.child -> V1
V1 -> V2 -> V3 -> V4          (next zinciri)
V1.child -> V5,  V5 -> V6
V3.child -> V7,  V7 -> V8 -> V9
V7.child -> V10
```

Slayttaki düğüm yapısı (ekrandan, 00:15:00):

```c
struct node{
  int data;
  struct node *next;
  struct node *child;
};
```

Hoca bu yapıyı tahtada da adım adım kurdu: önce veri alanı (`int` ya da `char`, tercih size kalmış), sonra aynı seviyedeki kardeşi gösteren işaretçi. Bu işaretçiye `sibling` de denebilir; bağlı listelerde çok kullanılan ada benzediği için `next` denmesi de uygundur. Son olarak bir alt seviyeyi gösteren `first child` işaretçisi eklenir. Her düğümün yalnız iki bağlantısı vardır: `next` ile kardeşler tek tek gezilir, `child` ile bir alt seviyeye inilir, oradaki `next`'lerle o seviyenin kardeşleri gezilir.

### 4.1 Aynı ağacın ikili ağaç olarak çizimi

Hoca aynı ağacı turuncu kalemle ikili ağaç olarak çizdi (ekrandan, 00:15:00). Çizimdeki bağlantılar:

- 0'dan 1 (ilk çocuk).
- 1'den 2 (kardeş) ve 1'den 5 (ilk çocuk); 5'ten 6 (kardeş).
- 2'den 3 (kardeş).
- 3'ten 4 (kardeş) ve 3'ten 7 (ilk çocuk).
- 7'den 8 (kardeş) ve 7'den 10 (ilk çocuk); 8'den 9 (kardeş).

Toplam 11 düğüm (V0-V10) vardır. En uzun yol V0, V1, V2, V3, V7, V8, V9'dur; bu yüzden ikili gösterim 7 seviyelidir. Hoca "6 seviye mi 7 seviye mi, sıfırdan sayınca 7 oluyor" diye sordu. Kökü 1. seviye sayınca 7 seviye çıkar (python ile doğrulandı). Böylece 4 seviyeli genel ağaç 7 seviyeye çıkmıştır, ama her düğüm iki işaretçili olduğu için yapı karmaşadan kurtulmuştur.

> **Hocanın vurgusu:** Uygulama probleminin temeli bu iki işaretçili gösterime dayanır. Bu yapıyı daha önce kendi başına gerçeklemiş olanlar büyük avantaj sahibi olur.

## 5. Uygulama Problemi: Ağaçla Dizin Simülasyonu

Hoca dönemin başında ağaçların nerede kullanıldığını anlatırken işletim sistemini örnek verdiğini hatırlattı. Öğrencilerden gelen cevap "dosya yapısı" idi: işletim sistemindeki dizin hiyerarşisi bir ağaçtır. Uygulama problemi bu hiyerarşinin bir simülasyonudur.

Önemli bir sınır vardır: Bu gerçek bir dosya sistemi değildir. C'nin dizin okuma, yazma ve yaratma fonksiyonları kullanılmaz; bu bir dosya giriş-çıkış (file I/O) çalışması değildir. Dizinler "varmış gibi" bir veri yapısının içinde kurgulanır.

Kurallar (ekrandan, 00:20:00):

- Başlangıçta yalnız `root` adlı bir kök dizin vardır. Gerçek dosya sistemlerindeki `/` dizinine karşılık gelir.
- Düğümler veri olarak karakter dizisi (dizin adı) tutar.
- Gerçeklenecek beş komut: `mkdir`, `chdir`, `rmdir`, `dir`, `count`.
- Program bir "aktif dizin" (o anda içinde bulunulan dizin) tutar. Komutlar bu dizin üzerinde çalışır.

### 5.1 Örnek oturumla ağacın kurulması

Hoca beyaz tahtada şu komutlarla bir ağaç kurdu (ekrandan, 00:20:00 ve 00:25:00):

1. `mkdir courses`: `root` altında `courses` dizini yaratılır.
2. `chdir courses`: aktif dizin artık `courses`'tur. Programın "courses'a girildi" gibi bir mesaj vermesi zorunlu değildir ama daha şık olur.
3. `mkdir dStruct`: `courses` altında `dStruct` yaratılır.
4. `chdir dStruct`: aktif dizin `dStruct` olur.
5. `mkdir Trees`, `mkdir Stacks`, `mkdir Queues`: `dStruct` altında üç dizin yaratılır.
6. `chdir Trees`, ardından `mkdir bTrees` ve `mkdir heapTrees`: `Trees` altında iki dizin yaratılır.
7. `chdir ..`: iki nokta özel addır, bir üst dizine çıkar. `Trees` içindeyken verildiği için aktif dizin tekrar `dStruct` olur.

Bu noktadaki yapı:

```text
root
  courses
    dStruct
      Trees
        bTrees
        heapTrees
      Stacks
      Queues
```

Kullanıcı istediği kadar dizin yaratabileceği için ağacın kaç seviyeli olacağı ve bir dizinde kaç alt dizin olacağı önceden bilinemez. Sabit sayıda çocuk işaretçisi bu yüzden işe yaramaz; ilk çocuk / sonraki kardeş gösterimi burada doğal çözümdür.

## 6. Komutlar ve Hata Durumları

### 6.1 `dir`

`dStruct` içindeyken `dir` verildiğinde aktif dizinin doğrudan alt dizinleri listelenir: `Trees`, `Stacks`, `Queues`. `Trees`'in içindeki `bTrees` ve `heapTrees` gösterilmez. Gerçek dosya sisteminde de bir dizin "kapalıdır"; içindekiler ancak içine girilince görülür.

### 6.2 `rmdir`

- `rmdir Stacks`: `Stacks`, aktif dizin `dStruct`'ın çocuğudur ve boştur, bu yüzden silinir.
- `rmdir dStruct`: Aktif dizin zaten `dStruct`'tır; altında `dStruct` adlı bir dizin yoktur, yalnız `Trees` ve `Queues` vardır. Program "directory not found" / "directory not exist" gibi bir hata vermelidir.
- `rmdir Trees`: `Trees`'in çocukları vardır. İçi dolu dizin silinemez; program "directory not empty" hatası vermelidir.
- `rmdir Queues`: `Queues` boş olduğu için silinebilir ve "silindi" mesajı verilebilir.

### 6.3 `chdir`

- `chdir heap`: Aktif dizinde böyle bir alt dizin yoksa "doesn't exist" gibi bir hata verilir.
- `chdir ..`: bir üst dizine çıkar. Örnekte `dStruct`'tan `courses`'a, oradan `root`'a çıkılır.
- Kökteyken bir kez daha `chdir ..` verilirse daha yukarı çıkılamaz; ekrandaki mesaj "Already in root !!!" şeklindedir (ekrandan, 00:25:00).

Böylece `chdir` iki yönlüdür: ada göre bir alt seviyeye iner, `..` ile bir üst seviyeye çıkar.

### 6.4 `count`

`count`, aktif dizindeki alt dizin sayısını verir. `Stacks` silindikten sonra `dStruct` içinde `Trees` ve `Queues` kaldığı için çıktı 2'dir (ekrandan, 00:25:00: `count --> 2`).

### 6.5 Komutların okunması

Program bir terminal ya da komut istemi gibi çalışır: "komut giriniz" benzeri bir istem gösterir, kullanıcı komutu yazar, program onu ayrıştırır (parse). Önce komutun hangisi olduğu (`chdir`, `rmdir`, `mkdir`, `dir`, `count`) anlaşılır, sonra boşluktan sonraki kısım dizin adı olarak alınır. Örneğin kökteyken `chdir Stacks` verilirse ve kökün altında böyle bir dizin yoksa hata verilir; varsa o düğüme geçilir ve sonraki komutlar oradan devam eder.

Hoca bunu gerçek işletim sistemleriyle karşılaştırdı: Linux, Mac ya da Windows'ta komut adları farklıdır (bir yerde `mkdir`, Windows'ta `md`; bir yerde `rm`, diğerinde `del`) ama hepsi aynı işi yapar: ağacın belirli bir seviyesindeyken o seviyede işlem yapmak.

## 7. Soru-Cevap

**Soru:** Komutlar için seçenekler (option) olacak mı? Örneğin bütün alt dizinleri gösteren bayraklar ya da `ls -la` gibi?
**Cevap:** Hayır. Yalnız beş komut gerçeklenir: `mkdir`, iki yönlü `chdir` (olmayan yere geçerken hata), `rmdir` (dolu dizin ve olmayan dizin için hata) ve aktif dizindeki dizin sayısını veren `count`. Seçenek yoktur.

**Soru:** Komutları kullanıcıdan komut satırıyla mı alacağız?
**Cevap:** Evet. Program çalıştırılınca bir komut istemi gibi bekler, komut girilir, program onu ayrıştırır ve uygular.

**Soru:** String karşılaştırma fonksiyonu kullanabilir miyiz?
**Cevap:** Komutları ve adları karşılaştırmak için kullanılabilir.

**Soru:** Bu derste öğrenilen yığın ve kuyruk gibi yapılar yüksek seviyeli dillerde hazır (built-in) var mı?
**Cevap:** Bazı dillerde ve bazı API'lerde hazır olarak vardır. Olmayan dillerde dış kütüphanelerle kullanılabilir; neredeyse her şeyin kütüphanesi bulunur. Bu derste ise yapılar elle tanımlanır.

> **Ders sonrası not:** Hoca C'de de hazır yazılmış yığın kütüphanesi olduğunu ve "include stack" ile kullanılabileceğini söyledi. Standart C kütüphanesinde hazır yığın yapısı yoktur; `#include <stack>` ile gelen `std::stack` C++ standart kütüphanesine aittir. C'de ancak üçüncü taraf kütüphaneler kullanılabilir.

<!-- BELİRSİZ: Soru-cevapta öğrencinin hazır yığın yapısı olan bir ortamdan söz ettiği kısım ("SMB'li", "eraylar gibi") altyazıda bozuk; büyük olasılıkla Assembly ve dizilerden (array) söz ediliyor. Nota alınmadı. -->

## Örnek Sorular

### Soru 1: İki işaretçili gösterim (ekrandan, 00:10:00)

Slayttaki 6'lı ağacın (A'nın çocukları B-G; B'nin çocukları H, I, J; H'nin N, O; E'nin K, L; K'nin P; L'nin Q; G'nin M) her düğümü için ilk çocuk ve sağdaki kardeş işaretçilerini yazınız.

> **Çözüm (derste verildi):** Bölüm 3'teki tablo. Örneğin B için ilk çocuk H, kardeş C; E için ilk çocuk K, kardeş F; G için ilk çocuk M, kardeş yok.

### Soru 2: İkili gösterimin seviye sayısı (derste sözlü, 00:15:30)

V0-V10 düğümlerinden oluşan 4 seviyeli genel ağaç (ekrandan, 00:15:00) ilk çocuk / sonraki kardeş gösterimiyle ikili ağaca çevrilince kaç seviyeli olur?

> **Çözüm (derste verildi):** En uzun yol V0 → V1 → V2 → V3 → V7 → V8 → V9 olduğundan kök 1. seviye sayılırsa 7 seviye çıkar (python ile doğrulandı).

### Soru 3: Ağaçla dizin simülasyonu (ekrandan, 00:20:00 ve 00:25:00)

Kökü `root` olan bir dizin ağacını bir veri yapısıyla simüle eden ve `mkdir`, `chdir` (`..` dahil), `rmdir`, `dir`, `count` komutlarını komut satırından okuyup uygulayan bir program yazınız. Olmayan dizine geçme, olmayan dizini silme, dolu dizini silme ve kökte `chdir ..` durumlarında hata mesajı verilmelidir. Bölüm 5.1 ve 6'daki örnek oturum çalıştırıldığında `dir` çıktısı `Trees`, `Stacks`, `Queues`; `Stacks` silindikten sonra `count` çıktısı 2 olmalıdır.

> **Çözüm (derste verilmedi):** Aşağıdaki C kodu ilk çocuk / sonraki kardeş gösterimini kullanır. `chdir ..` için derste gösterilen iki işaretçiye ek olarak bir `parent` işaretçisi eklendi; bu tercih ajana aittir. Kod `gcc -Wall -Wextra` ile uyarısız derlendi ve derste ekranda kurulan komut dizisiyle çalıştırıldı.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[64];
    struct node *next;    /* sağdaki kardeş */
    struct node *child;   /* ilk çocuk */
    struct node *parent;  /* chdir .. için */
};

struct node *yeni(const char *ad, struct node *ebeveyn) {
    struct node *n = calloc(1, sizeof *n);
    strncpy(n->name, ad, sizeof n->name - 1);
    n->parent = ebeveyn;
    return n;
}

struct node *bul(struct node *cwd, const char *ad) {
    struct node *p = cwd->child;
    while (p && strcmp(p->name, ad) != 0) p = p->next;
    return p;
}

void mkdir_(struct node *cwd, const char *ad) {
    if (bul(cwd, ad)) { printf("Directory already exists\n"); return; }
    struct node *n = yeni(ad, cwd);
    if (!cwd->child) cwd->child = n;
    else { struct node *p = cwd->child; while (p->next) p = p->next; p->next = n; }
}

struct node *chdir_(struct node *cwd, const char *ad) {
    if (strcmp(ad, "..") == 0) {
        if (!cwd->parent) { printf("Already in root!!!\n"); return cwd; }
        return cwd->parent;
    }
    struct node *h = bul(cwd, ad);
    if (!h) { printf("Directory doesn't exist\n"); return cwd; }
    return h;
}

void rmdir_(struct node *cwd, const char *ad) {
    struct node *onceki = NULL, *p = cwd->child;
    while (p && strcmp(p->name, ad) != 0) { onceki = p; p = p->next; }
    if (!p) { printf("Directory not found\n"); return; }
    if (p->child) { printf("Directory not empty\n"); return; }
    if (onceki) onceki->next = p->next; else cwd->child = p->next;
    free(p);
}

void dir_(struct node *cwd) {
    for (struct node *p = cwd->child; p; p = p->next) printf("%s\n", p->name);
}

int count_(struct node *cwd) {
    int c = 0;
    for (struct node *p = cwd->child; p; p = p->next) c++;
    return c;
}

int main(void) {
    struct node *root = yeni("root", NULL), *cwd = root;
    char satir[160], komut[32], ad[64];
    while (printf("%s> ", cwd->name), fgets(satir, sizeof satir, stdin)) {
        ad[0] = '\0';
        if (sscanf(satir, "%31s %63s", komut, ad) < 1) continue;
        if (!strcmp(komut, "mkdir")) mkdir_(cwd, ad);
        else if (!strcmp(komut, "chdir")) cwd = chdir_(cwd, ad);
        else if (!strcmp(komut, "rmdir")) rmdir_(cwd, ad);
        else if (!strcmp(komut, "dir")) dir_(cwd);
        else if (!strcmp(komut, "count")) printf("%d\n", count_(cwd));
        else if (!strcmp(komut, "exit")) break;
        else printf("Unknown command\n");
    }
    return 0;
}
```

Derste kurulan komut dizisiyle (Bölüm 5.1 ve 6) alınan çıktıların özeti:

```text
dir            -> Trees, Stacks, Queues
rmdir dStruct  -> Directory not found
rmdir Trees    -> Directory not empty
chdir heap     -> Directory doesn't exist
count          -> 2
chdir .. (3 kez, son kez kökte) -> Already in root!!!
```

Kodda her komut aslında bir bağlı liste işlemidir: `mkdir` kardeş listesinin sonuna ekleme, `rmdir` listeden silme (önceki düğümün `next`'i güncellenir), `dir` listeyi gezme, `count` eleman sayma, `chdir` ise listede arama yapıp bulunan düğüme geçmedir.

## Dersin Toparlaması

Bu oturumda çok çocuklu (m-ary) bir ağacın yalnız iki işaretçiyle, yani ilk çocuk ve sağdaki kardeş işaretçileriyle, ikili ağaç olarak gösterilebileceği tekrar edildi. Bu gösterimde aynı seviyedeki kardeşler bir bağlı liste oluşturur, çocuk işaretçisi bir alt seviyeye iner. Ağacın yüksekliği artar, ama düğüm yapısı sabit ve basit kalır; bu sayede çocuk sayısı önceden bilinmeyen ağaçlar rahatça gerçeklenir.

Aynı fikir işletim sistemlerindeki dizin hiyerarşisine uygulandı: her dizin bir düğüm, alt dizinleri onun çocuk listesidir. `mkdir`, `chdir`, `rmdir`, `dir` ve `count` komutları bu ağaç üzerinde ekleme, gezinme, silme, listeleme ve sayma işlemlerine karşılık gelir; olmayan dizin, dolu dizin ve kökten yukarı çıkma gibi durumlar ayrıca ele alınmalıdır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
