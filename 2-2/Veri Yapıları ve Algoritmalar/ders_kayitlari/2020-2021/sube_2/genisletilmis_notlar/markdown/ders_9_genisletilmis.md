# Ders 9 Genişletilmiş Notu: Yığın (Stack) ve Kuyruk (Queue)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Yığın (Stack) Nedir?
- 2. Stack Underflow ve Stack Overflow
- 3. Yığının Kullanım Alanları
- 4. Dizi ile Yığın Gerçekleme
- 5. Stringi Ters Çevirme ve Palindrom Kontrolü
- 6. Bağlı Liste ile Yığın Gerçekleme
- 7. Parantez Dengesi Kontrolü
- 8. C Operatör Öncelikleri
- 9. Infix'ten Postfix'e Dönüşüm
- 10. Postfix İfadenin İşlenmesi
- 11. Yığın İşlemlerinin Karmaşıklığı
- 12. Kuyruk (Queue)
- 13. Dizi ile Kuyruk Gerçekleme
- Örnek Sorular
- Dersin Toparlaması

## 1. Yığın (Stack) Nedir?

Bu derste yeni bir veri yapısı tanıtıldı: stack. Türkçede "yığın" ya da "yığıt" diye çevrilir. Hoca, bu adın ileride görülecek heap ile karışabileceğini söyledi. Bu yüzden derste çoğunlukla İngilizce "stack" kelimesi kullanıldı (ekrandan, 00:05:00).

Slayttaki tanıma göre stack, bir veri öbeğine yalnız tek bir uçtan erişilebilen bir veri yapısıdır (ekrandan, 00:10:00). Veri yapısının ne olduğu daha önceki derslerde tanımlanmıştı. Bir öbek veri bir arada tutulur. Veriler aynı türden de olabilir, farklı türlerden de. Stack'i farklı kılan, bu öbeğe nasıl erişildiğidir.

### 1.1 Kitap yığını benzetmesi

Hoca, slayttaki üst üste konmuş renkli kitap resmiyle anlattı. Önce mavi kitap okunup masaya konmuş, sonra turuncu kitap onun üstüne, sonra mor kitap onun üstüne konmuş. Bu böyle sürmüş ve en üste küçük turkuaz kitap gelmiş. Farkında olmadan bir stack oluşmuştur. Aradan bir kitap çekmek bütün yığını devirir. Bu yüzden erişilebilen tek kitap en üstteki, yani en son okunan kitaptır. O alınınca altındaki erişilebilir hale gelir. Yeni okunan kitap yine en üste konur. Türkçe kitaplar, İngilizce kitaplar ya da romanlar için ayrı yığınlar yapılabileceği gibi, bir problemde birden fazla stack de kullanılabilir.

Hoca ikinci benzetme olarak çalışma masasını verdi. Masaya önce bir ödev, sonra sınav kağıtları, sonra başka bir projenin dokümanı konur ve kağıtlar üst üste birikir. İnsan elini atınca en üsttekini, yani en son gelen işi alır. En alttaki eski işler en sona kalır.

Bu erişim mantığına **Last In First Out (LIFO)**, Türkçesiyle **son giren ilk çıkar** denir. Aynı mantık tersinden **First In Last Out (FILO)** diye de okunabilir: ilk konan mavi kitap yığından en son çıkabilir.

Hoca, aradaki elemanlara erişilemeyen bir yapının ne işe yarayacağı sorusunu kendisi sordu. Cevabı şuydu: işleri belli bir sırayla, özellikle sondan başa doğru yapmak gerektiğinde stack çok verimli bir veri yapısıdır.

### 1.2 Stack işlemleri

Slayttaki işlemler şunlardır (ekrandan, 00:10:00):

- `push`: yığına eleman basmak, yani en üste koymak.
- `pop`: yığından en üstteki elemanı çekmek.
- `peek` / `top`: en üstteki elemanı çekmeden yalnız değerine bakmak.
- `isEmpty`: yığın boş mu?
- `isFull`: yığın dolu mu?

Hoca temel işlemin yalnız `push` ve `pop` olduğunu, gerisinin "süsleme" olduğunu söyledi. `peek` için kitabın adına bakıp onu yığından almamak örneğini verdi.

Bu işlemler için minibüslerdeki yaylı bozuk para kutusunu örnek verdi. Şoför her 1 lirayı tüpün içine bastırır (push). Kutu yaylı olduğu için para üstü verirken en üstteki, yani en son konan lirayı alır (pop). İki lira verildiğinde iki tane 1 lirayı içeri basar. Kutu boşken para çekmeye çalışmak hatadır. Bu durumu önlemek için `isEmpty` kontrolü yapılır. Kutu örneğin 20 lira alıyorsa 21. lira konamaz. Bu da sınırlı bir stack'in dolu olmasıdır ve `isFull` kontrolü bunu önler.

### 1.3 Basit LIFO örneği

Yığında tamsayılar tutulsun. Başta yalnız 1 vardır. Sırayla 2, 3, 4, 5 ve 6 push edilir ve her biri bir öncekinin üstüne gelir. Yığında 6 eleman olur. Pop yapılınca önce en son gelen 6 çıkar. Sonraki pop'larda sırasıyla 5, 4, 3, 2 ve 1 çıkar.

## 2. Stack Underflow ve Stack Overflow

Bütün elemanlar pop edildikten sonra yığın boştur. Bir pop daha yapılırsa döndürülecek bir eleman yoktur. C'de kontrolsüz yazılmış bir kod bellekteki o gözde ne varsa onu döndürebilir ya da başka bir hata verebilir. **Boş bir stack'ten eleman çekmeye çalışmaya stack underflow denir.**

Tersi durumda, 6 gözlük (dizi boyutu 6 tanımlanmış) bir yığında 6 eleman varken 7 push edilmeye çalışılır. Yığında yer yoktur. **Dolu bir stack'e eleman basmaya çalışmaya stack overflow denir.**

Hoca, aynı adı taşıyan meşhur soru-cevap sitesinden de bahsetti. Sitenin adı "o kadar çok bilgi var ki bilgi taşması yaşıyoruz" gibi bir metafora dayanır. Programlarda stack overflow ise özellikle fonksiyon çağrılarında, en çok da özyinelemeli (recursive) fonksiyonlarda karşılaşılan bir sorundur.

**Soru:** Bir öğrenci fonksiyona gönderilen parametrenin (örneğin bir struct'ın) stack'e sığamayacak kadar büyük olması durumunu sordu.
**Cevap:** Hoca, struct gönderilip gönderilmemesinin önemli olmadığını söyledi. Burada konuşulan şey fonksiyon çağrılarıdır ve bellekteki adresler üzerinden düşünmek gerekir. Örneğin özyinelemeli Fibonacci'de Fibonacci(1), (2), (3) gibi değerler tekrar tekrar çağrılır. Bu fonksiyonların adresleri bir stack'te tutulur. 32 bitlik bir derleyicide adreslenebilecek alan, dolayısıyla en fazla çağrı sayısı bellidir. Bunu aşan bir özyineleme stack overflow hata koduyla sonlanır. Stack underflow ise daha çok kendi yazdığımız stack kodunda boşluk kontrolü yapmadığımızda ortaya çıkar. Çağrı yığınında underflow söz konusu değildir.

## 3. Yığının Kullanım Alanları

Hoca stack'i "görünmez gizli kahraman" diye niteledi. Bilgisayarda yapılan hemen her işlemin içinde vardır ama görünmez.

### 3.1 Çağrı yığını (call stack)

Bir program stack olmadan işletilemez. Buna call stack denir. Program stack, execution stack, function stack ya da machine stack diye de anılır. Bir fonksiyon başka bir fonksiyonu çağırdığında, iş bitince nereye geri dönüleceği takip edilmelidir.

Hoca şu örneği çizdi. `main`, bir dizi toplama fonksiyonu olan `add`'i çağırır. `add`, `isPositive` gibi bir fonksiyonu, o da matematik kütüphanesinden `absolute` fonksiyonunu çağırır. Her çağrının adresi yığına basılır. `absolute` bitince "beni kim çağırmıştı?" sorusunun cevabı yığından pop edilerek bulunur ve `isPositive`'e dönülür. Ardından `add`'e, sonra da `main`'e dönülür. Çağrı yığını boşaldığında `main` de dönmüştür ve kontrol işletim sistemine ya da terminale geçer.

### 3.2 Derleyicilerde ayrıştırma

Derleyiciler parsing aşamasında stack kullanmak zorundadır. Bunun örneği infix ifadeleri postfix (Polish notation) biçimine çevirmektir. Hoca nedenini şöyle açıkladı. İnsanlar bağlama bakarak hesap yapar. "3 + 5 × 2" ifadesini görünce önce çarpmayı yapması gerektiğini bilir. Bir makine ise soldan okur. 3'ü, artıyı ve 5'i görünce toplamaya kalkar. Sonra çarpıyı görünce geri dönüp yaptığını bozması gerekir. Üs alma, karekök, fonksiyon çağrıları ve parantezler işin içine girince bu iş içinden çıkılmaz hale gelir.

Çözüm, ifadeyi bağlamdan bağımsız (context free) hale getirmektir. Postfix gösterimde operatörler terimlerin arkasına atılır. Hoca örnek olarak "3 + 5 × 2" için "5 2 × 3 +" yazdı. Makine 5'i ve 2'yi alır, çarpıyı görünce çarpar ve 10 bulur. Sonra 10, 3 ve artıyı işleyip 13'e ulaşır. Hoca bu konuların biçimsel diller ve derleyici tasarımı derslerinde ayrıntılı görüleceğini söyledi.

> **Ders sonrası not:** Hocanın yazdığı "5 2 × 3 +" geçerli bir postfix ifadedir ve sonucu 13'tür. Ancak derste daha sonra anlatılan dönüşüm algoritması terimlerin sırasını korur ve "3 5 2 × +" sonucunu verir. Hocanın yazdığı biçim, toplama değişmeli olduğu için aynı sonuca ulaşır.

### 3.3 Diğer kullanım alanları

- **Kod kontrolü:** Derleyiciler ve geliştirme ortamları, kodu derlemeden önce parantezlerin ve blokların dengeli olup olmadığını stack ile kontrol edebilir.
- **Diziyi tersine çevirme.**
- **Hanoi Kuleleri:** Hoca bir oyuncak üzerinde 6 diskli Hanoi kulesini gösterdi. Büyük disk küçük diskin üstüne konamaz. Amaç diskleri bu kurala uyarak başka bir çubuğa taşımaktır. Stack, küçük diskin büyük diskin altında kalmamasını sağlamak için kullanılabilir. Hoca hazır çözümlerin internette bulunduğunu söyledi ama öğrencilerin önce kendilerinin kafa yormasını önerdi.
- **8 vezir (n vezir) problemi:** 8×8 satranç tahtasına 8 vezir, birbirlerini alamayacak şekilde yerleştirilmelidir. Hiçbiri aynı satırda, aynı sütunda ya da aynı çaprazda olmamalıdır. Hoca bunu 4×4 bir tahta çizerek anlattı. Bu problem için de stack ile verimli bir algoritma tasarlanabilir.

## 4. Dizi ile Yığın Gerçekleme

Stack iki şekilde oluşturulabilir (ekrandan, 00:35:00):

- **Dizi kullanarak:** statik, boyutu sabit.
- **Linkli liste kullanarak:** dinamik, teorik olarak asla dolmaz.

### 4.1 Tanımlar

```c
#include <stdio.h>
int MAXSIZE = 8;
int stack[8];
int top = -1;
```

`MAXSIZE`, doluluk kontrolünde kullanılacak sınırdır. `top`, yığının en üst gözünü gösteren bir "işaretçidir" (burada bir dizi indisi). Push yaparken dizinin hangi gözüne yazılacağını, pop yaparken hangi gözden okunacağını bu değişken söyler. Başlangıç değeri -1'dir. Yani `top` sıfırıncı gözü bile göstermiyor, yığın tamamen boş demektir.

Hoca dinamik yığının dizi ile de `malloc` ve `realloc` kullanılarak yapılabileceğini, ama bağlı listeyle yapmanın çok daha basit olduğunu söyledi.

### 4.2 isEmpty, isFull ve peek

Hoca bu üç fonksiyonu anlatımla şöyle tanımladı. Bu slayt karelerde yer almıyor. <!-- BELİRSİZ: isEmpty/isFull/peek slaytının tam kodu karede görünmüyor; aşağıdaki açıklamalar anlatımdan aktarıldı. -->

- `isEmpty`: `top == -1` ise 1, değilse 0 döndürür. Tek bir kontrol olduğu için $O(1)$'dir. Pop işleminin underflow'a düşmesini bununla engelleriz.
- `isFull`: Hoca `top` değerinin `MAXSIZE` değerine eşit olup olmadığına bakılacağını söyledi. Eşitse yığın doludur ve daha fazla eleman konamaz. Bu da $O(1)$'dir.
- `peek`: `return stack[top];` ile en üstteki değeri okur ama pop etmez. Hoca buradaki hatayı vurguladı: `top` -1 iken bu satır geçersiz bir okuma yapar. Bu yüzden `peek`'in içine mutlaka bir `isEmpty` kontrolü eklenmelidir. İki işlem yapılır ama yine $O(1)$'dir.

> **Hocanın vurgusu:** Boş bir stack'te `peek` yapılırsa da stack underflow yaşanır. Kodlarken bu kontrole dikkat etmek gerekir.

> **Ders sonrası not:** Hoca doluluk için "`top`, `MAXSIZE`'a eşit mi" dedi; push akış şemasında da `top ≠ max` koşulu yazıyor (ekrandan, 00:40:00). `top` -1'den başladığı ve `stack[8]` dizisinin son geçerli indisi 7 olduğu için doğru kontrol büyük olasılıkla `top == MAXSIZE - 1` olmalıdır. Aksi halde `top` 7 iken yapılan push `stack[8]`'e, yani dizinin dışına yazar.

### 4.3 Push

Slaytta akış şeması ve C kodu birlikte verildi (ekrandan, 00:40:00). Akış şemasında `max`, `stack(max)` ve `data` okunur, `top ← -1` yapılır. `top ≠ max` ise `top ← top+1` ve `stack(top) ← data` yapılır. Değilse 'Full' yazılır. Hoca, baştaki okuma ve ilk değer atamalarının aslında ayrı bir akışta, push'un ise ayrı bir fonksiyonda olması gerektiğini, burada sade olsun diye birleştirildiğini söyledi.

```c
void push(int data) {

    if(!isfull()) {
        top = top + 1;
        stack[top] = data;
    } else {
        printf("Full\n");
    }
}
```

Push geriye bir değer döndürmediği için `void`'dir ama basılacak veriyi parametre olarak alır. Önce doluluk kontrol edilir. Yer varsa önce `top` bir artırılır, sonra o göze veri yazılır. Yer yoksa veri yığına konmaz, yani kullanılmamış olur.

### 4.4 Pop

Pop'ta push'un tersi düşünülür. Push'ta yer var mı diye bakılır, pop'ta ise eleman kaldı mı diye bakılır (ekrandan, 00:45:00). Akış şemasında `top ≠ -1` ise `data ← stack(top)`, `top ← top-1` yapılır ve `data` yazdırılır. Değilse 'Empty' yazılır.

```c
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

Pop'un argümanı yoktur ama bir değer döndürmesi gerekir. Örnekler tamsayılarla yapıldığı için dönüş tipi `int`'tir. Boş yığında örneğin -1 gibi bir değer döndürülebilir. Hoca `top = top - 1` yerine `top--` da yazılabileceğini, kodun akış şemasıyla birebir aynı olsun diye böyle yazıldığını söyledi.

### 4.5 Pop sonrası değer nerede kalır?

Hoca slaytın yanına -1'den 6'ya kadar indisli bir yığın çizdi (ekrandan, 00:45:00). `top` 6'yı gösterirken pop yapılır. 6 değeri okunup döndürülür ve `top` bir azaltılır. 6 değeri silinmez, dizide durmaya devam eder ama artık erişilemez. Bir pop daha yapılınca `top` bir aşağı iner. Ardından `push 7` yapılınca `top` bir artar ve 7 o göze yazılır. Bir pop daha 7'yi döndürür ve `top`'u indirir. Sonra 8 ve 9 push edilince eski değerlerin üzerine yazılır. Yığın yapısı yalnız `top` işaretçisiyle korunur. Okuma, çekme ve basma izni yalnız en üstteki elemana verilir.

## 5. Stringi Ters Çevirme ve Palindrom Kontrolü

### 5.1 Stringi ters çevirme

Slaytta "merhaba" stringinin "abahrem"e çevrilmesi gösterildi (ekrandan, 00:50:00). Boş bir yığına sırayla m, e, r, h, a, b, a push edilir. String sonu okununca bütün elemanlar sırayla pop edilir ve bir diziye ya da standart çıktıya yazılır. Önce a, sonra b, a, h, r, e ve m çıkar. Yapılan iş yalnız iki işlemdir: önce bütün karakterleri push etmek, sonra hepsini pop etmek. Hoca bunun stringlerle ilgili pek çok uygulamada kullanılabileceğini söyledi.

### 5.2 Palindrom kontrolü

Slayttaki soru şuydu: "Verilen string'in palindrom olup olmadığını nasıl kontrol edersiniz?" (ekrandan, 00:50:00). Hoca bunun sınavlarda uzun süre sorulan klasik bir soru olduğunu söyledi. Palindrom, tersten ve düzden okunuşu aynı olan kelimedir.

Hoca örnek olarak "madam" yazdı ($n = 5$). Çift uzunlukta bir örnek istedi. Öğrencilerden gelen önerilerden "küllük" ($n = 6$) uygun bulundu. Ekrandaki notlarda ayrıca "anna" ($n = 4$) yazılıydı. "Yatay" da bir palindromdur ama 5 harflidir. Önerilen "amore roma" ise tersten okununca aynı olmadığı için palindrom değildir.

Hoca, bütün stringi ters çevirip karşılaştırmaya gerek olmadığını, çok daha basit bir yol bulunduğunu söyledi:

1. Stringin ilk $n/2$ karakteri stack'e push edilir. Hoca bunu "karpuz gibi ortadan ikiye bölmek" diye anlattı.
2. Uzunluk tekse ortadaki karakter kontrol edilmez, atlanır. Böylece problem $n-1$ karaktere iner.
3. Kalan karakterlerin her biri, stack'ten pop edilen karakterle sırayla karşılaştırılır.
4. Hepsi eşleşirse string palindromdur.

"küllük" için k, ü, l push edilir. Pop edilen l, 4. karakter l ile eşleşir. Sonra pop edilen ü 5. karakterle, en son pop edilen k de 6. karakterle eşleşir. Demek ki "küllük" palindromdur. "madam" için m ve a push edilir, ortadaki d atlanır. Pop edilen a sonraki a ile, m de son m ile eşleşir. Bu da palindromdur.

Hoca bu iki algoritmanın akışlarını ve kodlarını öğrencilere alıştırma olarak bıraktı.

## 6. Bağlı Liste ile Yığın Gerçekleme

### 6.1 Tanımlar

Önceki haftaki bağlı listelere atıfla, yığın bağlı listeyle de yapılabilir. Buna genellikle dinamik stack denir. İstenirse toplam eleman sayısına sınır konabilir. Ama düğüm yaratıp ekleyerek sürekli devam edilebildiği için yığın teorik olarak, erişilebilen bellekle sınırlı olmak üzere, asla dolmaz.

Yığının her gözü bir veri ve bir sonraki gözü gösteren bir bağlantı (pointer) taşımalıdır. Bu yüzden her göz bir `struct node` olarak tanımlanır (ekrandan, 01:05:00):

```c
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *ptr;
}*top,*top1,*temp;

int  peek(void);
void push(int data);
int  pop(void);
void isEmpty(void);
void destroy(void);
void stack_count(void);
void create(void);

int count = 0;
```

Yığının tepesi `top` işaretçisiyle izlenir. Pop ve free işlemlerinde bir sonraki elemanın adresini kaybetmemek için iki işaretçi daha gerekir: `top1` ve `temp`. Bağlı listede `isFull` fonksiyonu yoktur. İstenirse `count`'a bağlı bir sınır konarak eklenebilir. Ayrıca yığını ilk kez kurmak için `create`, sayısını vermek için `stack_count` ve tamamen yok etmek için `destroy` fonksiyonları tanımlanır.

### 6.2 Mantık

Slayttaki şekilde, dizi olarak çizilmiş yığın (alttan üste 12, 08, 21, 33, 18, 40; `Top` 40'ı gösteriyor) ile aynı yığının bağlı liste hali yan yana gösterildi (ekrandan, 01:05:00). Bağlı listede `Head` aynı zamanda `Top`'tur: 40 → 18 → 33 → ... → NULL.

Başta yalnız NULL vardır. İlk push'ta bir düğüm yaratılır, `next`'i NULL'ı gösterir ve `top` bu düğümü gösterir. Sonraki her push'ta yeni bir düğüm yaratılır. Yeni düğümün `next`'i eski `top`'u gösterir ve `top` yeni düğüme taşınır. Yani yeni eleman her zaman listenin başına, head düğüm olarak eklenir. Hoca bunu sırayla 12, 8, 21, 33, 18 ve 40 gelince çizdi. Her seferinde `top` en son geleni gösteriyordu.

Pop'ta tepedeki değer okunur, `top` bir sonraki düğüme kaydırılır ve eski düğüm `free` edilir (ekrandan, 01:10:00). Bu, `top` NULL'ı gösterene kadar sürdürülebilir. `top` NULL ise yığın boştur ve `isEmpty` de böyle gerçeklenir.

### 6.3 create, count, peek, isEmpty

Bu fonksiyonların slaytı karelerde görünmüyor. Anlatıma göre: <!-- BELİRSİZ: create/count/peek/isEmpty slaytının tam kodu karede görünmüyor; anlatımdan aktarıldı. -->

- `create`: En basitidir. `top = NULL` yapılarak boş bir liste kurulur.
- `stack_count`: Tutulan `count` değeri gösterilir.
- `peek`: `return top->data;` ile tepedeki değer döndürülür. Yığın boşken NULL'ın verisine erişilmeye çalışılır. Bu, derleyiciye göre anlamsız bir değer ya da hata verir. Bu yüzden buraya da `isEmpty` kontrolü eklemek iyi olur.
- `isEmpty`: `top` NULL ise yığın boştur ve doğru döndürülür. Değilse eleman sayısı da döndürülebilir. Ama hoca, yanlış (0) döndürmenin daha doğru bir yaklaşım olduğunu söyledi.

### 6.4 Push

Slayttaki kod (ekrandan, 01:15:00):

```c
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
```

Push veriyi argüman olarak alır ve `void`'dir. Hoca `malloc` içindeki `1*sizeof(struct node)` ifadesinin bir düğüm yaratıldığı açıkça görünsün diye böyle yazıldığını söyledi. Yığın boşsa (`top == NULL`) bir düğüm yaratılır, `ptr`'si NULL yapılır ve verisi yazılır. Hoca bunu verisi 3 olan tek bir düğümle çizdi. Yığın boş değilse geçici bir `temp` düğümü yaratılır, `temp->ptr` eski `top`'u gösterir ve verisi yazılır (örnekte 4). Son olarak `top = temp` yapılır. İki durumda da sayaç bir artırılır. 3 ve 4 eklenince `count` 2 olur. Tek bir kontrol ve sabit sayıda işlem olduğu için push $O(1)$'dir.

### 6.5 Pop

Slayttaki kod (ekrandan, 01:20:00):

```c
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

Pop argüman almaz ve bir tamsayı döndürür. Düğüm silineceği için döndürülecek değer önce `ret` değişkenine kopyalanır. `top1` önce `top`'u gösterir. `top1` NULL ise boş yığından eleman çekilmeye çalışılıyordur. Bu kontrol `isEmpty` çağrılarak da yapılabilirdi. Değilse `top1` bir sonraki düğüme kaydırılır, tepedeki değer `ret`'e yazılır (örnekte 3) ve `top` `free` edilir. Hoca bunu düğümün üzerine büyük bir çarpı koyarak gösterdi. Ardından `top = top1` ile ikinci düğüm yeni tepe olur, sayaç bir azaltılır ve `ret` döndürülür.

Hoca, push'ta `temp`, pop'ta `top1` adlı ayrı işaretçilerin yalnız anlatımda farklı görünsünler diye kullanıldığını söyledi. Tek bir `temp` ile de bu iş yapılabilir ve kod daha verimli yazılabilir.

> **Ek bilgi (derste anlatılmadı):** Push ve pop kodları, küçük bir `main` ile birlikte `gcc -Wall` ile derlenip denendi. 12, 8, 21, 33, 18, 40 push edildikten sonra yapılan 7 pop sırasıyla 40, 18, 33, 21, 8, 12 değerlerini ve ardından boş yığın hata mesajını verdi.

### 6.6 Destroy

`destroy` her şeyi yok etmelidir. Yine geçici bir işaretçi olarak `top1` kullanılır. Önce `top1`, `top`'un bir sonrakini gösterir. `top` `free` edilir ve `top = top1` yapılır. Sonra `top1` yeni tepenin bir sonrakine geçer. Bu, `top1` NULL olana kadar sürer. Son düğüm de free edilince geriye yalnız NULL'ı gösteren `top` kalır, yani yığın tamamen ortadan kalkmıştır. Hoca bunu üç düğümlü bir liste çizerek adım adım gösterdi. <!-- BELİRSİZ: destroy fonksiyonunun slayttaki tam kodu karede görünmüyor. -->

Bağlı liste ile push ve pop sabit sayıda işlemle, $O(1)$ zamanda yapılır. Dizi ile de durum aynıdır. İstenirse `count`'a bağlı olarak örneğin 100 ya da 1000 elemanlık bir sınır konup ötesi overflow sayılabilir.

## 7. Parantez Dengesi Kontrolü

### 7.1 Problem

Bir kod verildiğinde içindeki parantezlerin sayılarının ve açılıp kapanma sıralarının doğru olup olmadığı kontrol edilmek istenir. C kodunda köşeli `[ ]`, normal `( )` ve kod bloklarını ayıran küme `{ }` parantezleri olabilir. Hoca örnek olarak şu satırı yazdı (ekrandan, 01:25:00):

```c
while(a[first()] ){....}
```

Diğer karakterler atılıp yalnız parantezler bırakılınca `[ ( ) ] { }` dizisi elde edilir (`while`'ın dış parantezi kalabalık olmasın diye yazılmadı). İçteki parantez açılıp kapanmış, onu kapsayan da doğru sırada kapanmış, sonra bir blok açılıp kapanmıştır. Bu dengeli, kurallı bir dağılımdır. Köşeli parantez açılıp, normal parantez açılıp kapatılıp, köşeli parantez kapatılmadan başka bir şey kapatılırsa bu hatadır ve derleyici bunu bildirmelidir.

### 7.2 Algoritma

- Açma parantezi görülünce stack'e push edilir.
- Kapama parantezi görülünce stack'ten bir eleman pop edilir ve ikisinin eşleşip eşleşmediğine bakılır. Eşleşiyorsa devam edilir.
- Girdi bitince stack boşsa parantezler düzgündür.

**Dengeli örnek `[ ( ) ] { }`** (ekrandan, 01:25:00 ve 01:30:00):

| Adım | Karakter | İşlem | Stack (alttan üste) |
|---|---|---|---|
| 1 | `[` | push | `[` |
| 2 | `(` | push | `[ (` |
| 3 | `)` | pop `(`, eşleşti | `[` |
| 4 | `]` | pop `[`, eşleşti | boş |
| 5 | `{` | push | `{` |
| 6 | `}` | pop `{`, eşleşti | boş |

Sonuç: stack boş, ifade doğru.

**Dengesiz örnek `[ ( ( ) ]`:**

| Adım | Karakter | İşlem | Stack (alttan üste) |
|---|---|---|---|
| 1 | `[` | push | `[` |
| 2 | `(` | push | `[ (` |
| 3 | `(` | push | `[ ( (` |
| 4 | `)` | pop `(`, eşleşti | `[ (` |
| 5 | `]` | pop `(`, eşleşmedi | `[` |

5. adımda normal parantezin açması ile köşeli parantezin kapaması eşleşmez. Hoca bunun için bir `isMatching` fonksiyonundan yanlış döneceğini ve burada hemen "yanlış kapama" denebileceğini söyledi. Bu eşleşme doğru olsaydı bile, sonda yığında hâlâ eleman kaldığı için ifade yine hatalı olurdu. Yani iki hata durumu vardır: herhangi bir anda açma-kapama eşleşmemesi ya da sonda stack'te bir veya daha fazla açma parantezi kalması.

### 7.3 Sözde kod

Hoca slayttaki sözde kodu anlattı. Bu slayt karelerde görünmüyor. <!-- BELİRSİZ: parantez kontrolü sözde kodunun tam metni karede görünmüyor; anlatımdan aktarıldı. --> İfadenin yalnız parantezlerden oluştuğu varsayılır ve $i = 0$'dan $n-1$'e kadar her eleman için:

```text
eğer s[i] açma parantezlerinden biriyse:
    push(s[i])
değilse eğer s[i] kapama parantezlerinden biriyse:
    eğer stack boşsa ya da tepedeki eleman s[i] ile eşleşmiyorsa:
        return 0
    değilse:
        pop
döngü bitince:
    stack boşsa return 1, değilse return 0
```

Hoca, eşleşmenin burada `peek` ile kontrol edildiğini, ardından pop yapıldığını söyledi. Bu kod istenen biçimde değiştirilebilir. Tek tür parantez varsa eşleşme fonksiyonu yazmadan tek bir karşılaştırma yeterlidir.

### 7.4 Alıştırma önerileri

Hoca bu kodların yazılmasını önerdi. Örneğin hangi tür parantezden kaç tanesinin yanlış açılıp kapandığı takip edilebilir. Bir varyant da şudur: yalnız küme parantezleri olsun, açma ve kapama sayıları doğru ama sıraları yanlış olsun. Doğru kod bloğuna ulaşmak için hangi elemanların yer değiştirmesi gerektiği ya da toplam kaç takas (swap) yapılması gerektiği bulunabilir. Bu varyant Örnek Sorular bölümünde çözüldü.

## 8. C Operatör Öncelikleri

Infix'ten postfix'e dönüşümde hangi operatörün önce işleneceğine, hangisinin sona atılacağına karar vermek için öncelik sırasını bilmek gerekir. Hoca C operatör öncelik tablosunu gösterdi (ekrandan, 01:35:00):

| Token | Operatör | Öncelik | Birleşme |
|---|---|---|---|
| `()` `[]` `->` `.` | fonksiyon çağrısı, dizi elemanı, struct/union üyesi | 17 | soldan sağa |
| `--` `++` | artırma, azaltma (sonek) | 16 | soldan sağa |
| `--` `++` `!` `~` `-` `+` `&` `*` `sizeof` | azaltma, artırma (önek), mantıksal değil, birler tümleyeni, tekli eksi/artı, adres/dolaylama, bayt cinsinden boyut | 15 | sağdan sola |
| `(type)` | tür dönüşümü | 14 | sağdan sola |
| `*` `/` `%` | çarpımsal | 13 | soldan sağa |
| `+` `-` | ikili toplama/çıkarma | 12 | soldan sağa |
| `<<` `>>` | kaydırma | 11 | soldan sağa |
| `>` `>=` `<` `<=` | ilişkisel | 10 | soldan sağa |
| `==` `!=` | eşitlik | 9 | soldan sağa |
| `&` | bit düzeyi ve | 8 | soldan sağa |
| `^` | bit düzeyi dışlayıcı veya | 7 | soldan sağa |
| `\|` | bit düzeyi veya | 6 | soldan sağa |
| `&&` | mantıksal ve | 5 | soldan sağa |
| `\|\|` | mantıksal veya | 4 | soldan sağa |
| `?:` | koşullu | 3 | sağdan sola |
| `=` `+=` `-=` `/=` `*=` `%=` `<<=` `>>=` `&=` `^=` `\|=` | atama | 2 | sağdan sola |
| `,` | virgül | 1 | soldan sağa |

Tablonun altındaki notlara göre öncelik sütunu Harbison ve Steele'den alınmıştır. 16. satır sonek (postfix) biçimini, 15. satırdaki artırma/azaltma ise önek (prefix) biçimini gösterir. Çarpma ve bölmenin toplama ve çıkarmadan önce yapıldığı zaten bilinmektedir. Tablo, C'deki sıralamayı hatırlatmak için gösterildi.

> **Ders sonrası not:** Hoca tabloyu aşağıdan yukarı okurken "en yüksek öncelik virgülde" dedi. Tabloya göre virgülün önceliği en düşüktür (1). En yüksek öncelik parantez, dizi erişimi ve üye erişimindedir (17). Hoca da anlatımın sonunda "en yüksek şey parantezlerde" diyerek bunu düzeltti.

## 9. Infix'ten Postfix'e Dönüşüm

Hoca dersin başındaki örneği hatırlattı. "3 + 2 × 5 + 1" ifadesinde insan önce çarpmayı, sonra toplamaları soldan sağa yapacağını bilir. Derleyici ise 3 + 2'yi yapıp 5 bulduktan sonra çarpıyı görürse geri dönmek zorunda kalır. Daha karmaşık ifadelerde ne kadar geri dönmesi gerektiğini fark etmek zordur. Bu yüzden ifade tek yönde (soldan sağa) ilerlenerek her adımda "iki terim, bir operatör" işlenecek hale getirilir. "3 + 2 × 5 + 1" ifadesi "3 2 5 × + 1 +" diye yazılırsa önce 2 ile 5 çarpılır ve 10 bulunur. Sonra 3 ve 10 toplanarak 13, ardından 13 ve 1 toplanarak 14 bulunur. Bunun için operatörlerin sona atılması gerekir.

### 9.1 Birinci yol: elle parantezleme

Slayttaki yöntem üç adımlıdır (ekrandan, 01:40:00):

1. **İfadeyi tamamen paranteze al.** Her operatör ve iki terimi bir paranteze alınır:
   `a / b - c + d * e - a * c` → `((((a / b) - c) + (d * e)) - (a * c))`
2. **Tüm operatörleri ilgili oldukları sağ (kapatma) parantezle yer değiştir.** `/` kendi kapama parantezine, `-` bir dıştakine gider. İçteki `*` `(d * e)`'nin kapamasına, `+` bir dıştakine gider. `(a * c)` içindeki `*` onun kapamasına, son `-` de en dıştaki parantezin yerine geçer. Slaytta bunun için "iki kere döngü" gerektiği yazıyor.
3. **Tüm parantezleri sil:** `a b / c - d e * + a c * -`

Hoca sonucu şöyle okudu. Önce `a b /` işlenir ve yeni bir değer çıkar. Sonra bu değer ve c ile `-` işlenir. Ardından `d e *`, sonra iki değer ile `+`. Sonra `a c *`, en sonda da iki değer ile `-` yapılır. Slayttaki önemli not: **terimlerin (operand) sırası infix ve postfix'te aynıdır** (a, b, c, d, e, a, c).

Bu yöntem akla ilk gelen çözümdür ama maliyetlidir. Bütün girdi üzerinde üç ayrı geçiş yapılır: parantezleme, yer değiştirme ve silme. Ayrıca iç içe iki döngü gerektiği için karmaşıklık $O(n^2)$'ye gider.

### 9.2 İkinci yol: stack ile dönüşüm

Operatörlerin sırasına bakılırsa infix'te `/ - + * - *` olan sıra, postfix'te `/ - * + * -` olur. Yani en son yapılacak işlem en sona atılmaya çalışılıyor. Bu bir LIFO mantığıdır, dolayısıyla stack uygundur.

Slayttaki kurallar şunlardır (ekrandan, 01:45:00):

- **Varsayımlar:** operatörler `(`, `)`, `+`, `-`, `*`, `/`, `%`. Terimler tek basamaklı tamsayı ya da tek karakterlik değişkendir. Bitwise gibi diğer operatörler öncelik sırası bilindiği sürece eklenebilir.
- Operatörler için bir stack kullanılır.
- Terimler ifadeden oldukları gibi alınıp çıktıya eklenir.
- Operatörler, stack'teki öncelikleri gelenin önceliğinden **BÜYÜK ya da EŞİT** olduğu durumda (bu şartı sağlayan operatörler sırasıyla) stack'ten pop edilip çıktıya yazılır. Böylece örneğin çarpmanın toplamadan önce yapılması garanti edilir.
- Yeni gelen operatör push edilir.
- EoS (string sonu) görülene kadar işleme devam edilir. EoS görülünce stack'te kalanlar da pop edilip çıktıya eklenir.

Hoca sözde kodu da anlattı. Başta stack'e bir açma parantezi push edilir, ifadenin sonuna da bir kapama parantezi eklenir. Stack boşalana kadar girdiden karakter okunur. Terim ise çıktıya eklenir. Açma parantezi ise push edilir. Operatör ise yukarıdaki öncelik kuralıyla pop'lar yapılır ve yeni operatör push edilir. Kapama parantezi ise açma parantezine kadar pop edilip çıktıya yazılır. Parantezsiz bir sürüm de düşünülebilir. <!-- BELİRSİZ: dönüşüm sözde kodunun slayttaki tam metni karede görünmüyor. -->

Parantezlerle ilgili kurallar örnekten çıkar. Açma parantezi en yüksek öncelikli kabul edildiği için doğrudan stack'e basılır. Stack'te açma parantezinin üstüne gelen operatör için pop yapılmaz. Kapama parantezi gelince açma parantezi görülene kadar her şey pop edilip çıktıya yazılır. Açma parantezi de atılır, çünkü postfix'te parantez kullanılmaz.

### 9.3 Örnek 1: `a * ( b + c ) / d`

Bu ifadede soldan sağa çalışılır ama parantez önce geldiği için önce b + c yapılır, sonuç a ile çarpılır, sonra d'ye bölünür (ekrandan, 01:50:00).

| Okunan | İşlem | Stack (alttan üste) | Çıktı |
|---|---|---|---|
| `a` | terim, çıktıya | boş | a |
| `*` | stack boş, push | `*` | a |
| `(` | açma parantezi, push | `* (` | a |
| `b` | terim, çıktıya | `* (` | a b |
| `+` | tepede `(` var, pop yok; push | `* ( +` | a b |
| `c` | terim, çıktıya | `* ( +` | a b c |
| `)` | `(` görülene kadar pop: `+` çıktıya, `(` atılır | `*` | a b c + |
| `/` | tepedeki `*` ile öncelik eşit: `*` pop, sonra `/` push | `/` | a b c + * |
| `d` | terim, çıktıya | `/` | a b c + * d |
| EoS | kalanlar pop | boş | a b c + * d / |

Slayttaki açıklama `/` adımı içindir: "the isp of '/' is 13 and the icp of '*' is 13" ve "pop the stack and printout". Çarpma ve bölmenin öncelik değeri tablodaki gibi 13'tür. Eşitlik şartı sağlandığı için çarpı pop edilir.

> **Ek bilgi (derste anlatılmadı):** Slayttaki "isp" (in-stack priority) yığının içindeki operatörün önceliğini, "icp" (incoming priority) ise girdiden yeni gelen operatörün önceliğini ifade eder. Ders kitaplarında açma parantezine yığın dışındayken en yüksek (icp), yığın içindeyken en düşük (isp) öncelik verilir. Böylece parantez doğrudan push edilir ama üstüne gelen operatörler onu pop etmez. Derste anlatılan "parantez en yüksek önceliklidir, doğrudan basılır" kuralı bu düzenin sade bir anlatımıdır.

Sonuç `abc+*d/`'dir. İşlerken önce b ile c toplanır, sonuç a ile çarpılır, ardından d ile bölünür.

### 9.4 Örnek 2: `4^2*3-3+8/4/(1+1)`

Hoca önce bu ifadeyi elle hesapladı: $4^2 = 16$, $8/4 = 2$, $2/2 = 1$, $16 \cdot 3 = 48$, $48 - 3 + 1 = 46$. Sonra dönüşümü adım adım yaptı (ekrandan, 02:15:00):

| Okunan | İşlem | Stack (alttan üste) | Çıktı |
|---|---|---|---|
| `4` | çıktıya | boş | 4 |
| `^` | stack boş, push | `^` | 4 |
| `2` | çıktıya | `^` | 4 2 |
| `*` | tepedeki `^` önceliği büyük: `^` pop, `*` push | `*` | 4 2 ^ |
| `3` | çıktıya | `*` | 4 2 ^ 3 |
| `-` | tepedeki `*` daha öncelikli: `*` pop, `-` push | `-` | 4 2 ^ 3 * |
| `3` | çıktıya | `-` | 4 2 ^ 3 * 3 |
| `+` | `-` ile eşit: `-` pop, `+` push | `+` | 4 2 ^ 3 * 3 - |
| `8` | çıktıya | `+` | ... 3 - 8 |
| `/` | `+` öncelikli değil: pop yok, `/` push | `+ /` | ... 3 - 8 |
| `4` | çıktıya | `+ /` | ... 3 - 8 4 |
| `/` | `/` ile eşit: `/` pop, `/` push | `+ /` | ... 3 - 8 4 / |
| `(` | push | `+ / (` | ... 8 4 / |
| `1` | çıktıya | `+ / (` | ... 8 4 / 1 |
| `+` | tepede `(`: pop yok, push | `+ / ( +` | ... 8 4 / 1 |
| `1` | çıktıya | `+ / ( +` | ... 8 4 / 1 1 |
| `)` | `(`'e kadar pop: `+` çıktıya | `+ /` | ... 8 4 / 1 1 + |
| EoS | kalanlar pop: `/`, `+` | boş | 4 2 ^ 3 * 3 - 8 4 / 1 1 + / + |

Sonuç: `42^3*3-84/11+/+`.

Hoca ikinci `/` adımında şunu vurguladı. Aynı operatörün pop edilip yeniden push edilmesi gereksiz görünebilir. Ama gelen operatör bölü yerine çarpı da olabilirdi ve o zaman sonuç farklı olurdu. Kontrolün tek tip olması için eşitlik durumunda her zaman pop yapılır.

Hoca ayrıca terimlerin tek karakterli olduğunu hatırlattı. Çıktıdaki "4 2" kırk iki değil, iki ayrı terimdir. Çok basamaklı sayılar için her terim ayrı bir göz ya da struct olarak tutulmalıdır. String kullanmak zorunlu değildir. Anlatım kolaylığı için string üzerinden gidildi.

## 10. Postfix İfadenin İşlenmesi

### 10.1 Yöntem

Postfix ifade derleyicinin soldan sağa tek geçişle işleyebilmesi için oluşturulur. Bu kez de stack kullanılır. Ama dönüşümden farklı olarak bu kez **terimler** (sayılar ya da değişkenler) stack'e atılır. Böylece gelen terimler geliş sırasının tersine işlenebilir. Bir operatör görülünce stack'ten iki terim pop edilir, işlem yapılır ve sonuç yeniden push edilir. Hoca, sonuç yerine iki terimi ve operatörü string olarak birleştirip push etmenin de mümkün olduğunu söyledi. Bu şekilde postfix ifade yeniden infix'e çevrilir.

### 10.2 Örnek: `6 2 / 3 - 4 2 * +`

Slayttaki örnek (ekrandan, 02:05:00 ve 02:10:00), tek bir soldan sağa taramayla işlenir:

| Okunan | İşlem | Stack (alttan üste) |
|---|---|---|
| `6` | push | 6 |
| `2` | push | 6 2 |
| `/` | pop 2 ve 6, $6/2 = 3$, push | 3 |
| `3` | push | 3 3 |
| `-` | pop 3 ve 3, $3-3 = 0$, push | 0 |
| `4` | push | 0 4 |
| `2` | push | 0 4 2 |
| `*` | pop 2 ve 4, $4 \cdot 2 = 8$, push | 0 8 |
| `+` | pop 8 ve 0, $0 + 8 = 8$, push | 8 |

Sonunda stack'ten pop edilen değer 8'dir. İşlemler string olarak birleştirilseydi cevap infix ifade olarak `6 / 2 - 3 + 4 * 2` çıkardı (ekrandan, 02:10:00). Tek geçiş yapılır ve her adım $O(1)$ maliyetlidir.

### 10.3 Örnek 2'nin işlenmesi: `42^3*3-84/11+/+`

Slayttaki adımlar (ekrandan, 02:20:00):

| Okunan | Stack (tepe solda) |
|---|---|
| `4` | 4 |
| `2` | 4 2 (slayttaki yazım) |
| `^` | 16 |
| `3` | 3 16 |
| `*` | 48 |
| `3` | 3 48 |
| `-` | 45 |
| `8` | 8 45 |
| `4` | 4 8 45 |
| `/` | 2 45 |
| `1` | 1 2 45 |
| `1` | 1 1 2 45 |
| `+` | 2 2 45 |
| `/` | 1 45 |
| `+` | 46 |

Slaytta yığın tepesi solda yazılıyor. Yalnız ikinci satır bu düzene uymuyor ve "Stack: 4 2" olarak verilmiş; tepede 2 vardır. $4^2 = 16$, $16 \cdot 3 = 48$, $48 - 3 = 45$, $8/4 = 2$, $1+1 = 2$, $2/2 = 1$ ve $45 + 1 = 46$ bulunur. Hoca, 45'in iki basamaklı bir sayı olduğunu ve yığında tek bir değer olarak tutulduğunu gösterdi. Bu sonuç elle bulunan 46 ile aynıdır. Demek ki postfix dönüşümü de, postfix işleme de doğru çalışmıştır. Bu dönüşüm ve işleme python ile de doğrulandı.

Hoca karşılaştırmayı şöyle yaptı. Elle parantezleme yönteminde iç içe iki döngü gerektiği için karmaşıklık $n^2$ olur. Stack ile tek bir döngüde, $O(n)$'de iş biter. Küçük ifadelerde bu fark önemsizdir. Ama $n$ 10.000 ya da 100.000 gibi büyük değerler aldığında doğrusal zamanda kalmanın, karesel zamana göre çok büyük bir avantajı olur.

## 11. Yığın İşlemlerinin Karmaşıklığı

- **push:** Tek bir kontrol ve içinde sabit sayıda atama ya da bellek ayırma yapılır. $O(1)$.
- **pop:** Bir `if` ve sabit sayıda iş yapılır. $O(1)$.
- **peek:** İçinde bir `isEmpty` kontrolü vardır. $O(1)$.
- **isEmpty / isFull:** Tek bir `if` kontrolüdür. $O(1)$.

Hoca, bu işlemlerin eleman sayısından bağımsız olmasının, onları kullanan algoritmanın karmaşıklığının ayrıca $n$ ya da $\log n$ ile çarpılmasını önlediğini söyledi. Örneğin $\log n$ tane push yapan bir algoritma $\log n$ zamanda kalır. Stack ile yapılan $n/2$ tane push-pop da $O(n)$ mertebesindedir. Hoca bu nedenle "stack kullanmak bizi karmaşıklıktan kurtarıyor" dedi.

## 12. Kuyruk (Queue)

### 12.1 Tanım

Dersin ikinci veri yapısı, hocanın stack'in "kardeşi" dediği kuyruktur (queue). Stack'te yapı tek tarafı açık bir hazne gibidir: yalnız tepeye push edilir ve yalnız tepeden pop edilir. Kuyrukta ise iki uç vardır. Slayttaki tanıma göre kuyruk, elemanların sadece bir uçtan eklenip diğer uçtan çıkarılabildiği bir veri yapısıdır (ekrandan, 02:25:00). Erişim mantığı **First In First Out (FIFO)**, yani **ilk giren ilk çıkar**dır. İşlemleri **Enqueue** ve **Dequeue**'dur.

### 12.2 Gişe kuyruğu benzetmesi

Slayttaki resimde havaalanında bir gişe önünde bekleyen bir kuyruk vardı. Hoca pasaport ya da bilet kuyruğunu çizerek anlattı. Gişe henüz açılmamışken ilk gelen kuyruğun başına geçer. Sonra sırayla diğerleri (çizimde farklı renklerde) arkasına dizilir. Kuyruk örneğin 6 kişilikse 7. kişi alınmaz, çünkü kuyruk doludur. Bu bir stack olsaydı ilk gelen en son hizmet alırdı. Kuyrukta ise ilk gelen ilk hizmet alır ve çıkar, sonra ikinci, sonra üçüncü. İki kişi çıkınca kuyruk ilerler ve iki kişilik yer açılır, yeni gelenler arkaya eklenir.

Kuyruğa eleman eklemeye **enqueue** denir. "Push" demek kuyruk için garip olur. Kuyruğun önündeki elemanı alıp hizmet vermeye ve onu kuyruktan çıkarmaya **dequeue** denir. Bunlar stack'teki push ve pop'un karşılıkları gibi düşünülebilir.

### 12.3 Kullanım alanları

- **İşletim sistemlerinde süreç zamanlama:** Hoca, ileride işletim sistemleri dersinde time quantum, round robin gibi yaklaşımların görüleceğini söyledi. Round robin'de süreçler sabit boyutlu, halka gibi dönen bir yapıda dizilir. Sırası gelen süreç CPU'yu bir süre kullanır, sonra sıra bir sonrakine geçer. İşi biten çıkar, yeni süreç sona eklenir. Yeni gelene "hemen seni işleyeyim" denemez. Bu tam bir FIFO mekanizmasıdır ve orada doğrudan kuyruk kullanılır.
- **Giriş/çıkış işlemleri:** Bir dosya okunurken ya da kopyalanırken satırlar ilk satırdan son satıra doğru, okundukları sırayla yazılır.
- **Paket anahtarlama:** Ağ derslerinde görülecek. A noktasından B'ye giden 5 IP paketi farklı yollardan gidebilir ama sonunda birden beşe sırayla işlenmeleri istenir. Switchlerin arkasında paketlerin geliş sırasıyla dağıtıldığı kuyruklar olduğu düşünülebilir.
- Kargo şirketlerinin konveyör hatlarında en öndeki koli, siparişi önce verildiği için önce işlem görür.

## 13. Dizi ile Kuyruk Gerçekleme

Kuyruk da iki şekilde yapılabilir. **Statik ya da sabit boyutlu** kuyruk genellikle dizi ile gerçekleştirilir. **Dinamik** kuyruk ise bağlı listeyle ve dinamik bellek ayırmayla yapılır. Dinamik kuyruk teorik olarak dolmaz: eleman geldikçe düğüm oluşturulup eklenir. Bağlı listede head kuyruğun başını gösterir ve çekme oradan yapılır. Ama yeni eleman sona eklenmelidir ve bu başka bir maliyet getirebilir. Hoca bunun çözümünün kolay olduğunu ve sonra bakılacağını söyledi.

### 13.1 Basit çözüm ve kaydırma maliyeti

Hoca dizi ile basit çözümdeki sorunu önce isimlerle anlattı. Sırada Ali, Ayşe, Fatma, Ahmet ve Mehmet olsun. Birinci gözdeki Ali çıkınca diğer herkesin bir göz başa kayması gerekir. Ayşe çıkınca yine hepsi kayar. Bu bir maliyettir.

Slayttaki örnekte 10 elemanlık bir dizi kullanılır (ekrandan, 02:35:00):

```text
enqueue(3)   3 . . . . . . . . .
enqueue(5)   3 5 . . . . . . . .
enqueue(8)   3 5 8 . . . . . . .
enqueue(1)   3 5 8 1 . . . . . .
dequeue()    . 5 8 1 . . . . . .
             5 8 1 . . . . . . .
dequeue()    . 8 1 . . . . . . .
             8 1 . . . . . . . .
enqueue(7)   8 1 7 . . . . . . .
```

Enqueue'lar ucuzdur: sayaç bir artırılır ve sıradaki boş göze yazılır. Her dequeue'da ise kalan bütün elemanlar başa kaydırılır, yani kalan eleman sayısı kadar iş yapılır.

### 13.2 İki işaretçi ile dairesel kuyruk

İyileştirme basit bir fikre dayanır. Boşluk oluşuyorsa kuyruğun önünü hep sıfırıncı gözde tutmak gerekmez. Kuyruğun önü için bir `front`, sonu için bir `rear` işaretçisi tutulur. Doluluk kontrolü için ayrıca `size` tutulur. Yeni eleman dizinin sonuna gelindiğinde boşalan baş taraftaki gözlere de yazılabilir.

Örnek durum: `front = 0`, `rear = 3`, `size = 4`, `max size = 10`. Kuyruk `max size` boyutunda bir dizidir. Başta `front`, `rear` ve `size` -1'dir, çünkü kuyruk boştur.

- `isEmpty`: `return size < 0;` Size sıfırdan küçükse (-1 ise) eleman yoktur ve doğru döner. Değilse en az bir eleman vardır ve yanlış döner.
- `isFull`: `size == max size` kontrolü yapılır, tıpkı stack'teki gibi.

**Enqueue:** `size` 4, `max size`'tan küçük. `rear` bir artırılır ve 4. göze yeni değer yazılır. Artık `front` 0'ı, `rear` 4'ü gösterir.

Şimdi başka bir durum düşünülsün. Önce 10 enqueue ile dizi doldurulmuş, sonra 6 dequeue yapılmış olsun. Her dequeue'da `front` ilerletildiği için baştaki gözler boştur. Slayttaki durum (ekrandan, 02:40:00):

```text
. . . . . . 2 3 5 6        size=4, front=6, rear=9
enqueue(10)
10 . . . . . 2 3 5 6       size=5, front=6, rear=0
```

`rear` 9 iken enqueue yapılınca `rear`'ı bir artırmak onu 10 yapar. Bu `max size`'a eşit olduğu için `rear` sıfırlanır. Yani kuyruğun sonu artık sıfırıncı indistir. `front` hâlâ 6'yı gösterir. Kuyruk sırası 2, 3, 5, 6, 10'dur. Yeni bir eleman gelirse `rear` 1 olur ve örneğin 8 değeri o göze yazılır. Dequeue her zaman `front`'tan yapılır, yani kuyruğun önündeki önce işlenir. Her dequeue'da `front` bir ilerler. Bu dairesel yapıda `max size`'a gelince sıfırlanıp başa dönülür. `size` kontrolü de yapılır ki eski elemanların üzerine yazılmasın, değerleri kaybolmasın.

### 13.3 İlk gerçekleme (anlatıma göre)

Bu kodun slaytı karelerde görünmüyor. Anlatıma göre enqueue'da üç durum vardır: <!-- BELİRSİZ: ilk enqueue/dequeue kodunun tam metni karede görünmüyor; anlatımdan aktarıldı. -->

1. `size < max size` değilse kuyruk doludur ve yeni eleman alınamaz.
2. Kuyruk boşsa (`size < 0`) bu ilk enqueue'dur: `Q[0] = value`, `front` ve `rear` 0'ı gösterir, `size = 1` olur.
3. `rear == max size - 1` ise `rear` sona gelmiştir. Değer `Q[0]`'a yazılır, `rear = 0` olur ve `size` bir artırılır.
4. Diğer durumda arkada yer vardır. Değer `rear + 1`'e yazılır ve `size` bir artırılır.

Dequeue'da (örnek: `front = 0`, `rear = 3`, `size = 4`) önce mutlaka boşluk kontrol edilir. Döndürülecek değer için bir `temp` değişkeni 0 ile başlatılır. `size` sıfırdan küçükse kuyruk boştur ve `temp`, yani 0 döndürülür (-1 de döndürülebilirdi). Değer varsa her zaman `front`'tan çekilir, `size` bir azaltılır ve `front` bir artırılır. Hoca, bu kodda `front`'un sona gelip başa dönmesi kontrolünün eksik olduğunu belirtti.

### 13.4 Alternatif gerçekleme

Hoca aynı işin "biraz daha düzgün yazılmış" bir kodunu gösterdi (ekrandan, 02:45:00):

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

Burada `MAX` 6'dır. `front` 0'dan, `rear` -1'den başlar, `itemCount` 0'dır. `isEmpty`, `isFull` ve `size` `itemCount`'a göre çalışır. Enqueue yalnız kuyruk dolu değilken yapılır. Hoca `else` koluna bir hata mesajı eklenebileceğini söyledi. `rear` `MAX-1` ise önce -1 yapılır. Böylece `intArray[++rear]` ifadesi `rear`'ı 0 yaparak veriyi başa yazar. Bu sayede önceki koddaki `if / else if / else` yapısındaki ikinci `if`'ten kurtulunur. Dequeue'da `intArray[front++]` önce `front`'taki değeri okur, sonra `front`'u bir artırır. `front` `MAX`'a eşit olduysa sıfırlanır; önceki kodda eksik olan kontrol budur. Sonra sayaç bir azaltılır ve okunan değer döndürülür.

Hoca bu kodun karşılaştırma bakımından daha basit olduğunu söyledi. Başta mı sonda mı olunduğuna ayrıca bakılmadığı için her durumda tek bir atama ya da okuma yapılır. Sonra yalnız "sona geldim mi" kontrolüyle `front` ya da `rear` güncellenir.

> **Ders sonrası not:** Hoca enqueue'yu anlatırken "boş olmadığı zaman ancak enqueue yap" dedi. Koddaki koşul `!isFull()`'dur, yani doğrusu "dolu olmadığı zaman enqueue yap"tır. Ayrıca slayttaki `dequeue` boş kuyruk kontrolü yapmaz. Çağırmadan önce `isEmpty` kontrolü gerekir.

> **Ek bilgi (derste anlatılmadı):** Alternatif kod küçük bir `main` ile `gcc -Wall` ile derlenip denendi. 1'den 6'ya kadar eklendikten sonra dolu kuyruğa 99 alınmadı. 4 eleman çekildi (1, 2, 3, 4). Ardından 7, 8, 9 dizinin başına dönülerek eklendi ve kuyruktan sırasıyla 5, 6, 7, 8, 9 çıktı.

### 13.5 Bağlı liste ile kuyruk

Ders süresi dolduğu için bağlı listeyle kuyruk gerçeklemesine geçilmedi. Slayt yalnız ekrana geldi (ekrandan, 02:50:00). Slaytta `#define FULL 10` ile bir sınır, `data` ve `next` alanlı bir `Node` yapısı, ayrıca `count`, `front` ve `rear` alanlı bir `Queue` yapısı vardı. Şekilde A → B → C → NULL listesinin başını `Front`, sonunu `Rear` gösteriyordu ve `count` 3'tü. Anlatımı bir sonraki derse kaldı.

## Örnek Sorular

### Soru 1: Stringi ters çevirme

(ekrandan, 00:50:00) "merhaba" stringini stack kullanarak "abahrem"e çevirin.

**Çözüm:** Karakterler sırayla push edilir: m, e, r, h, a, b, a (tepe: a). Sonra yığın boşalana kadar pop edilir ve çıkan karakterler sırayla yazılır: a, b, a, h, r, e, m → "abahrem".

### Soru 2: Palindrom kontrolü

(ekrandan, 00:50:00) Verilen string'in palindrom olup olmadığını nasıl kontrol edersiniz? Örnekler: "madam" ($n = 5$), "anna" ($n = 4$), "küllük" ($n = 6$).

**Çözüm (derste verildi):** İlk $\lfloor n/2 \rfloor$ karakter push edilir. $n$ tekse ortadaki karakter atlanır. Kalan her karakter pop edilen karakterle karşılaştırılır. Hepsi eşleşirse palindromdur. "küllük": k, ü, l push. Pop l = 4. karakter, pop ü = 5. karakter, pop k = 6. karakter, yani palindrom. "madam": m, a push, d atlanır. Pop a = a, pop m = m, yani palindrom.

### Soru 3: Parantez dengesi

(ekrandan, 01:25:00) `[ ( ) ] { }` ve `[ ( ( ) ]` ifadelerinin parantezleri dengeli midir?

**Çözüm (derste verildi):** İlkinde her kapama, pop edilen açmayla eşleşir ve sonda stack boştur, yani dengelidir. İkincisinde 5. adımda `]` gelince pop edilen `(` ile eşleşmez. Ayrıca sonda stack'te `[` kalır. İfade dengesizdir. Ayrıntılı tablolar 7.2'dedir.

### Soru 4: Parantez sırasını düzeltmek için en az takas

(derste sözlü, 01:33:10) Yalnız küme parantezlerinden oluşan bir ifadede açma ve kapama sayıları eşit ama sıra yanlıştır. Doğru bloklara ulaşmak için toplam kaç takas (swap) yapılmalıdır?

> **Çözüm (derste verilmedi):** Soru alıştırma olarak bırakıldı. Herhangi iki karakterin yer değiştirmesine izin verildiği varsayılarak çözüldü. Önce stack ile normal eşleştirme yapılır: `{` push edilir; `}` geldiğinde stack boş değilse pop edilir, boşsa eşleşmeyen kapama sayısı $u$ bir artırılır. Gerekli en az takas sayısı $\lceil u/2 \rceil$'dir. Her takas, eşleşmeyen bir `}` ile sondaki eşleşmeyen bir `{`'i yer değiştirerek en fazla iki eşleşmeyen kapamayı düzeltir. Örnekler: `}{}{` için $u = 1$, 1 takas; `}}{{` için $u = 2$, 1 takas; `}}}{{{` için $u = 3$, 2 takas. Formül, en çok 5 çift paranteze kadar bütün diziliş için kaba kuvvet aramasıyla python'da doğrulandı.

### Soru 5: Elle parantezleme ile postfix

(ekrandan, 01:40:00) `a / b - c + d * e - a * c` ifadesini birinci yolla postfix'e çevirin.

**Çözüm (derste verildi):** Tamamen parantezle: `((((a / b) - c) + (d * e)) - (a * c))`. Operatörleri kendi kapama parantezlerine taşı ve parantezleri sil. Sonuç: `a b / c - d e * + a c * -`.

### Soru 6: Stack ile postfix dönüşümü

(ekrandan, 01:50:00) `a * ( b + c ) / d` ifadesini stack kullanarak postfix'e çevirin.

**Çözüm (derste verildi):** Adımlar 9.3'teki tablodadır. Sonuç: `abc+*d/`.

### Soru 7: Postfix ifadenin işlenmesi

(ekrandan, 02:05:00) `6 2 / 3 - 4 2 * +` ifadesinin değeri nedir?

**Çözüm (derste verildi):** Terimler push edilir, her operatörde iki pop yapılıp sonuç push edilir. Ara sonuçlar: $6/2 = 3$, $3-3 = 0$, $4 \cdot 2 = 8$, $0+8 = 8$. Cevap 8'dir; infix karşılığı `6 / 2 - 3 + 4 * 2`.

### Soru 8: Dönüşüm ve işleme, örnek 2

(ekrandan, 02:15:00 ve 02:20:00) `4^2*3-3+8/4/(1+1)` ifadesini postfix'e çevirip stack ile işleyin.

**Çözüm (derste verildi):** Postfix: `42^3*3-84/11+/+` (adımlar 9.4'te). İşleme: 16, 48, 45, 2, 2, 1 ara sonuçlarıyla sonuç 46 (adımlar 10.3'te). Elle hesap da $16 \cdot 3 - 3 + 1 = 46$ verir.

### Soru 9: Dizi ile kuyruk

(ekrandan, 02:35:00) 10 gözlük bir dizide basit çözümle `enqueue(3)`, `enqueue(5)`, `enqueue(8)`, `enqueue(1)`, `dequeue()`, `dequeue()`, `enqueue(7)` işlemleri sonunda kuyruk nasıl görünür?

**Çözüm (derste verildi):** İki dequeue 3'ü ve 5'i çıkarır. Her seferinde kalanlar başa kaydırılır. Son durum `8 1 7 . . . . . . .` olur. Dairesel kuyrukta ise kaydırma yapılmaz, yalnız `front` ilerler.

## Dersin Toparlaması

Bu derste iki temel veri yapısı tanıtıldı. Stack tek uçtan erişimli bir yapıdır ve son giren ilk çıkar (LIFO). Push, pop, peek, isEmpty ve isFull işlemleri hem dizi ile hem bağlı liste ile $O(1)$ zamanda gerçeklenir. Boş yığından çekmek underflow, dolu yığına basmak overflow hatasıdır. Stack'in gücü bu sabit maliyetli işlemlerden gelir. Bu sayede string ters çevirme, palindrom kontrolü, parantez dengesi kontrolü, infix'ten postfix'e dönüşüm ve postfix ifadenin işlenmesi tek geçişte, doğrusal zamanda yapılabilir. Elle parantezleme ise $O(n^2)$'ye gider. Çağrı yığını ve derleyicilerdeki ayrıştırma, stack'in farkında olmadan her gün kullanıldığı yerlerdir.

Kuyruk ise bir uçtan ekleme, öbür uçtan çıkarma yapılan ve ilk giren ilk çıkar (FIFO) mantığıyla çalışan yapıdır. Süreç zamanlama, giriş/çıkış ve paket anahtarlama gibi alanlarda kullanılır. Dizi ile basit gerçeklemede her dequeue bir kaydırma maliyeti getirir. `front` ve `rear` işaretçileriyle kurulan dairesel kuyruk bu maliyeti ortadan kaldırır. Bağlı liste ile kuyruk gerçeklemesi bir sonraki derse kaldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
