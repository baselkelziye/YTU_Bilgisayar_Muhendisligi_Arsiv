# Ders 9 Çalışma Özeti

## Genel Konular

- Yığın (stack) veri yapısı
  - Bir veri öbeğine yalnız tek bir uçtan erişilebilen veri yapısıdır. Erişim mantığı "son giren ilk çıkar"dır: Last In First Out (LIFO); aynı şey First In Last Out (FILO) diye de okunabilir.
  - Benzetmeler: üst üste konmuş kitaplar (yalnız en üstteki alınabilir), masada biriken kağıtlar, minibüslerdeki yaylı bozuk para haznesi.
  - Temel işlemler `push` (yığına basma) ve `pop` (yığından çekme); yardımcı işlemler `peek`/`top` (çekmeden en üsttekini okuma), `isEmpty`, `isFull` (ekrandan, 00:10:00).
- Taşma durumları
  - Stack underflow: boş yığından eleman çekmeye (`pop`) çalışmak.
  - Stack overflow: dolu yığına eleman basmaya (`push`) çalışmak. Program yürütmede en çok derin özyinelemeli (recursive) çağrılarda görülür.
- Yığının kullanım alanları
  - Fonksiyon çağrı yığını (call stack / program stack / execution stack): her fonksiyon döndüğünde kendisini çağıranın adresi yığından alınır.
  - Derleyicilerde ayrıştırma (parsing): infix ifadeleri postfix (Polish notation) biçime çevirme ve işleme.
  - Kod kontrolü: parantez ve blokların dengeli olup olmadığını denetleme.
  - Diziyi/stringi tersine çevirme, palindrom kontrolü, Hanoi Kuleleri, 8 vezir (n vezir) problemi.
- Dizi ile (statik, sabit boyutlu) yığın
  - `MAXSIZE`, `stack[8]` ve başlangıçta `top = -1` (ekrandan, 00:35:00).
  - `push`: dolu değilse `top` bir artırılır, `stack[top] = data`; `pop`: boş değilse `data = stack[top]`, `top` bir azaltılır (ekrandan, 00:40:00 ve 00:45:00).
  - Çekilen değer dizide durmaya devam eder ama artık erişilemez; sonraki `push` onun üzerine yazar.
- Bağlı liste ile (dinamik) yığın
  - Her göz `data` ve bir sonraki düğümü gösteren `ptr` alanı olan bir `struct node`'dur. Yığının tepesi listenin başıdır (head = top) (ekrandan, 01:05:00).
  - `push`: yeni düğüm oluşturulur, `ptr`'si eski `top`'u gösterir, `top` yeni düğüm olur. `pop`: tepedeki değer saklanır, `top` bir sonraki düğüme geçer, eski düğüm `free` edilir.
  - Ek işlemler: `create`, `stack_count`, `destroy`. Teorik olarak dolmaz; istenirse `count` ile sınır konabilir.
- Uygulamalar
  - String ters çevirme: karakterler sırayla push, sonra hepsi pop edilir ("merhaba" → "abahrem").
  - Palindrom kontrolü: ilk $n/2$ karakter push edilir; tek uzunlukta ortadaki atlanır; kalan karakterler pop edilenlerle karşılaştırılır.
  - Parantez dengesi kontrolü: açma parantezi push, kapama parantezinde pop edip eşleşme kontrolü; sonda yığın boş olmalı.
- Infix'ten postfix'e dönüşüm
  - 1. yol (elle): ifadeyi tamamen parantezle, her operatörü kendi kapama paranteziyle yer değiştir, parantezleri sil. İki iç içe döngü gerekir, $O(n^2)$'ye gider.
  - 2. yol (stack): terimler doğrudan çıktıya yazılır; operatörler için yığın kullanılır; yığındaki operatörün önceliği gelenin önceliğinden büyük ya da eşitse pop edilip çıktıya yazılır, sonra gelen push edilir. Tek geçiş, $O(n)$.
- Postfix ifadenin işlenmesi
  - Bu kez terimler yığına atılır; operatör gelince iki terim pop edilir, işlem yapılır, sonuç push edilir. Sonda yığında kalan tek değer sonuçtur.
- Kuyruk (queue)
  - Elemanların bir uçtan eklenip diğer uçtan çıkarıldığı veri yapısı; First In First Out (FIFO), "ilk giren ilk çıkar" (ekrandan, 02:25:00).
  - İşlemler `enqueue` (kuyruğa ekleme) ve `dequeue` (kuyruktan çekme).
  - Kullanım alanları: işletim sistemlerinde süreç zamanlama (round robin), giriş/çıkış işlemleri, ağlarda paket anahtarlama.
  - Dizi ile basit çözümde her `dequeue` sonrası kalan elemanlar kaydırılır (pahalı). İyileştirme: `front` ve `rear` iki işaretçi ile dairesel (circular) kuyruk.

## Hocanın Özellikle Vurguladığı Kısımlar

- `isEmpty` ve `isFull` kontrolleri
  - `pop` ve `peek` öncesinde boşluk, `push` öncesinde doluluk kontrol edilmelidir. Kontrol yapılmazsa C'de bellekteki rastgele bir değer okunabilir ya da dizinin dışına yazılabilir.
  - `peek` fonksiyonunda `return stack[top]` boş yığında `top = -1` olduğu için hata verir; buraya mutlaka `isEmpty` kontrolü konmalıdır.
- Yığının gücü $O(1)$ işlemlerden gelir
  - Dizi ile de bağlı liste ile de `push`, `pop`, `peek`, `isEmpty`, `isFull` sabit sayıda işlemle, $O(1)$ zamanda yapılır.
  - Bu yüzden yığınla kurulan algoritmalar (postfix dönüşümü, postfix işleme, parantez kontrolü) tek geçişte, doğrusal zamanda çalışır.
- Bilgisayar insan gibi bağlama bakarak hesap yapamaz
  - "3 + 5 * 2" ifadesinde insan önceliği bilir; makine soldan okurken önce toplamaya kalkar. Bu yüzden ifade bağlamdan bağımsız (context free) postfix biçime çevrilir.
- Postfix dönüşümünde terimlerin sırası değişmez
  - Infix ve postfix ifadede terimler (operand) aynı sırada yer alır; yalnız operatörlerin yeri değişir.
- Egzersiz önerisi
  - Parantez kontrolü, string ters çevirme, palindrom ve postfix işlemleri kodlanmalı; problemlerin varyantları (örneğin tek tür parantezde kaç takas gerektiği) üzerinde çalışılmalı.

## Kısa Tekrar Notları

- Stack: tek uçtan erişim, LIFO. Queue: bir uçtan ekleme, diğer uçtan çıkarma, FIFO.
- Underflow: boş yığından pop. Overflow: dolu yığına push.
- Dizi ile stack: `top = -1` boş demektir; push önce `top++`, sonra yazma; pop önce okuma, sonra `top--`.
- Bağlı liste ile stack: yeni eleman her zaman başa eklenir; top = head. Pop'ta düğüm `free` edilir.
- Bütün stack işlemleri $O(1)$.
- Parantez kontrolü: açma → push; kapama → pop ve eşleştir; uyuşmazlık ya da sonda dolu yığın → hatalı ifade.
- Infix → postfix: terim çıktıya; operatör geldiğinde yığındaki öncelik ≥ gelen öncelik olduğu sürece pop; sonra push; `(` doğrudan push; `)` gelince `(` görülene kadar pop; sonda kalanların hepsi pop.
- `a*(b+c)/d` → `abc+*d/`; `4^2*3-3+8/4/(1+1)` → `42^3*3-84/11+/+` = 46.
- Postfix işleme: terim → push; operatör → iki pop, işlem, sonucu push.
- Dairesel kuyrukta `rear` (ya da `front`) dizinin sonuna gelince 0'a döner; doluluk `size`/`itemCount` ile izlenir.

## Detaylı Açıklamalar

- **Yığın kavramı.** Hoca yığını masaya üst üste konmuş renkli kitaplarla anlattı: en son okunan kitap en üsttedir ve yalnız o alınabilir; aradan kitap çekmek bütün yığını devirir. Aynı mantık masada biriken kağıtlar için de geçerlidir: en son gelen iş ilk ele alınır, en alttakiler en sona kalır. Minibüs şoförlerinin yaylı bozuk para haznesi de bir yığındır: konan her para (push) bir öncekinin üstüne gelir, para üstü verilirken en üstteki para (pop) alınır. Hazne 20 para alıyorsa 21. parayı koymak mümkün değildir; bu, sınırlı bir yığının dolu olması durumudur.

- **Basit örnek.** Yığında yalnız 1 varken sırayla 2, 3, 4, 5, 6 push edilir; yığında 6 eleman olur. Pop edildikçe sırayla 6, 5, 4, 3, 2, 1 çıkar. Yığın boşken bir pop daha yapılırsa stack underflow, 6 gözlük dolu bir yığına 7 push edilmeye çalışılırsa stack overflow oluşur.

- **Çağrı yığını.** Hoca, `main`'in bir `add` fonksiyonunu, `add`'in bir `isPositive` fonksiyonunu, onun da matematik kütüphanesinden `absolute` fonksiyonunu çağırdığı bir örnek çizdi. Her çağrının dönüş adresi yığına basılır; `absolute` bitince yığından pop edilerek kendisini çağıran `isPositive`'e, o bitince `add`'e, sonra `main`'e dönülür. Çağrı yığını boşaldığında `main` işletim sistemine dönmüş olur. Fibonacci'nin özyinelemeli hesabındaki gibi çok sayıda çağrı, sınırlı yığın alanını aşarsa stack overflow ile program sonlanır. Underflow ise daha çok kendi yazdığımız yığın kodunda kontrol unutulduğunda olur.

- **Dizi ile yığın kodları** (ekrandan, 00:35:00, 00:40:00, 00:45:00):

```c
#include <stdio.h>
int MAXSIZE = 8;
int stack[8];
int top = -1;

void push(int data) {
    if(!isfull()) {
        top = top + 1;
        stack[top] = data;
    } else {
        printf("Full\n");
    }
}

int pop() {
    int data;
    if(!isempty()) {
        data = stack[top];
        top = top - 1;
        return data;
    } else {
        printf("empty\n");
    }
}
```

  - `isempty`: `top == -1` ise 1, değilse 0 döner. `isfull`: hoca `top` değerinin `MAXSIZE` ile karşılaştırılacağını söyledi. `peek`: boş değilse `stack[top]` döner. Bu üç fonksiyonun slaytı karelerde yoktur. <!-- BELİRSİZ: isempty/isfull/peek slaytının tam kodu karede görünmüyor; anlatımdan aktarıldı. -->
  - Ders sonrası not: Hoca doluluk için "`top` `MAXSIZE`'a eşit mi" kontrolünü söyledi (push akış şemasında da `top ≠ max` yazıyor). `top` -1'den başlayıp `stack[8]` dizisinin son indisi 7 olduğu için doğru kontrol büyük olasılıkla `top == MAXSIZE - 1` olmalıdır; aksi halde `top = 8` iken dizinin dışına yazılır.
  - Hoca çizdiği örnekte 6'yı pop ettikten sonra 6'nın dizide durmaya devam ettiğini, sonra 7 push edilince onun üzerine yazıldığını gösterdi. Yığın yapısını yalnız `top` işaretçisi korur.

- **Bağlı liste ile yığın** (ekrandan, 01:05:00, 01:15:00, 01:20:00):

```c
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *ptr;
}*top,*top1,*temp;

void push(int data)
{
    if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->data = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->data = data;
        top = temp;
    }
    count++;
}

int pop()
{
    int ret;
    top1 = top;
    if (top1 == NULL)
    {
        printf("\n Error : Trying to pop from empty stack");
        return -1;
    }
    else
        top1 = top1->ptr;
    ret = top->data;
     printf("\n Popped value : %d", top->data);
    free(top);
    top = top1;
    count--;
    return ret;
}
```

  - Slayttaki prototipler: `peek`, `push`, `pop`, `isEmpty`, `destroy`, `stack_count`, `create`; ayrıca `int count = 0;`. `create` `top = NULL` yapar; `peek` `top->data` döndürür (boş yığın kontrolü eklenmeli); `isEmpty` `top == NULL` ise doğru döner. `destroy`, `top1` ile listede ilerleyip her düğümü `free` eder ve sonunda `top = NULL` kalır. <!-- BELİRSİZ: create/count/peek/isEmpty ve destroy slaytlarının tam kodu karelerde görünmüyor; anlatımdan aktarıldı. -->
  - Push ve pop kodları küçük bir `main` ile birlikte `gcc -Wall` ile derlenip denendi (12, 8, 21, 33, 18, 40 push; ardından 7 pop: 40, 18, 33, 21, 8, 12 ve boş yığın hatası).

- **String ters çevirme ve palindrom.** "merhaba" karakter karakter push edilir, sonra pop edildikçe a, b, a, h, r, e, m çıkar ve "abahrem" elde edilir (ekrandan, 00:50:00). Palindrom (tersten ve düzden aynı okunan kelime) için bütün stringi ters çevirmeye gerek yoktur: ilk $n/2$ karakter push edilir, sonra her pop edilen karakter sıradaki karakterle karşılaştırılır. "küllük" ($n = 6$) için k, ü, l push edilir; pop ile gelen l, ü, k sırasıyla 4., 5., 6. karakterlerle eşleşir. "madam" ($n = 5$) için m, a push edilir, ortadaki d atlanır, kalan a ve m pop edilenlerle eşleşir.

- **Parantez dengesi** (ekrandan, 01:25:00). Örnek kod parçası `while(a[first()] ){....}` içindeki parantez dizisi `[ ( ) ] { }` dengelidir: `[` ve `(` push edilir; `)` gelince pop edilen `(` ile eşleşir; `]` gelince `[` ile eşleşir; `{` push edilir, `}` ile eşleşir; sonda yığın boştur → doğru. `[ ( ( ) ]` dizisinde üç açma push edilir; `)` son `(` ile eşleşir; `]` gelince pop edilen `(` ile eşleşmez → hata. Ayrıca sonda yığında `[` kalır, bu da tek başına dengesizlik demektir. Sözde kodda her karakter için açma parantezi push edilir; kapama parantezinde yığın boşsa ya da tepedeki eşleşmiyorsa 0 döndürülür, değilse pop edilir; döngü sonunda yığın boşsa 1, değilse 0 döndürülür. Eşleşmeyi kontrol eden küçük bir `isMatching` fonksiyonu yazılabilir.

- **C operatör öncelikleri** (ekrandan, 01:35:00). Hoca dönüşümden önce C operatör öncelik tablosunu gösterdi: en yüksekte `()`, `[]`, `->`, `.` (17), sonra sonek `++`/`--` (16), önek `++`/`--`, `!`, `~`, tekli `-`/`+`, `&`, `*`, `sizeof` (15), tür dönüşümü (14), `* / %` (13), `+ -` (12), kaydırma (11), ilişkisel (10), eşitlik (9), bit düzeyi `&` (8), `^` (7), `|` (6), `&&` (5), `||` (4), `?:` (3), atamalar (2), en altta virgül (1).
  - Ders sonrası not: Hoca anlatırken "en yüksek öncelik virgülde" dedi; tabloya göre virgülün önceliği en düşüktür (1), en yüksek öncelik parantez ve dizi erişimindedir (17).

- **Infix → postfix, 1. yol** (ekrandan, 01:40:00). `a / b - c + d * e - a * c` önce `((((a / b) - c) + (d * e)) - (a * c))` diye tamamen parantezlenir; her operatör kendi kapama paranteziyle yer değiştirir; parantezler silinince `a b / c - d e * + a c * -` elde edilir. Terimlerin sırası (a, b, c, d, e, a, c) değişmez.

- **Infix → postfix, 2. yol** (ekrandan, 01:45:00). Varsayımlar: operatörler `( ) + - * / %`, terimler tek basamaklı tamsayı ya da tek karakterlik değişken. `a * ( b + c ) / d` örneğinde: a çıktıya; `*` boş yığına push; `(` push; b çıktıya; `+` push (`(` üzerinde pop yapılmaz); c çıktıya; `)` gelince `(` görülene kadar pop: `+` çıktıya, `(` atılır; `/` geldiğinde yığındaki `*` ile önceliği eşit (slaytta "isp of / is 13 and icp of * is 13") olduğu için `*` pop edilip çıktıya yazılır, `/` push edilir (ekrandan, 01:50:00); d çıktıya; sonda `/` pop edilir. Sonuç: `abc+*d/`.

- **Postfix işleme** (ekrandan, 02:05:00 ve 02:10:00). `6 2 / 3 - 4 2 * +`: 6, 2 push; `/` → 6/2 = 3 push; 3 push; `-` → 3 − 3 = 0 push; 4, 2 push; `*` → 4·2 = 8 push; `+` → 0 + 8 = 8. Karşılık gelen infix ifade `6 / 2 - 3 + 4 * 2`, sonuç 8.

- **Örnek 2** (ekrandan, 02:15:00 ve 02:20:00). `4^2*3-3+8/4/(1+1)` ifadesi aynı kurallarla `42^3*3-84/11+/+` biçimine çevrilir; işlenince yığın sırasıyla 16, 48, 45, (8 45), (4 8 45), (2 45), (1 2 45), (1 1 2 45), (2 2 45), (1 45) ve 46 olur. Hocanın elle hesabı da $16 \cdot 3 - 3 + 1 = 46$ idi. Sonuçlar python ile doğrulandı.

- **Kuyruk.** Hoca kuyruğu bilet ya da pasaport gişesindeki insan kuyruğuyla anlattı: ilk gelen ilk hizmet alır; kuyruk 6 kişilikse 7. kişi alınmaz. Dizi ile basit çözümde `enqueue(3)`, `enqueue(5)`, `enqueue(8)`, `enqueue(1)` sonrası `dequeue()` 3'ü çıkarır ve 5, 8, 1 birer göz kaydırılır; her `dequeue` kalan eleman sayısı kadar kaydırma maliyeti getirir (ekrandan, 02:35:00). İyileştirme: `front` ve `rear` işaretçileri ve `size` tutulur. Başlangıçta üçü de -1'dir; `isEmpty` `size < 0`, `isFull` `size == maxsize` ile kontrol edilir. `maxsize = 10` iken `front = 6`, `rear = 9`, `size = 4` (2, 3, 5, 6) durumunda `enqueue(10)` yapılınca `rear` dizinin sonunu aştığı için 0'a döner, 10 sıfırıncı göze yazılır, `size = 5` olur (ekrandan, 02:40:00).

- **Alternatif dairesel kuyruk kodu** (ekrandan, 02:45:00). `front` sona gelince başa dönme kontrolü ilk kodda eksikti; bu kodda var ve tek bir `if` ile çözülüyor:

```c
#define MAX 6

int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

int isEmpty() { return itemCount == 0;}
int isFull() { return itemCount ==MAX;}
int size() { return itemCount; }

void enqueue(int data) {
   if(!isFull()) {
      if(rear == MAX-1) {
         rear = -1;
      }
      intArray[++rear] = data;
      itemCount++;
   }
}

int dequeue() {
   int data = intArray[front++];
   if(front == MAX) {
      front = 0;
   }
   itemCount--;
   return data;
}
```

  - Kod küçük bir `main` ile `gcc -Wall` ile derlenip denendi: 1-6 eklendi, dolu kuyruğa 99 alınmadı, 4 eleman çekildi, 7, 8, 9 başa dönülerek eklendi ve sıra 1, 2, ..., 9 olarak korundu. Slayttaki `dequeue` boş kuyruk kontrolü yapmıyor; çağırmadan önce `isEmpty` kontrolü gerekir.
  - Bağlı liste ile kuyruk slaytı (`front`, `rear` ve `count` tutan `Queue` yapısı) ekrana geldi ama anlatımı bir sonraki derse kaldı (ekrandan, 02:50:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
