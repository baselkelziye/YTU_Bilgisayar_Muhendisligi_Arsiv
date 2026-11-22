# Ders 18 Genişletilmiş Notu: Bağlı Listeden Silme, Bit Alanları, Union, Özyineleme, Fonksiyon ve Void İşaretçileri, Çift İşaretçi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Bağlı listede baştan ve sondan silme
- 2. İç içe struct örneği: polinom toplama
- 3. Struct döndüren fonksiyonlar: oyuncu verimi örneği
- 4. Structure alignment ve bit alanları
- 5. Union
- 6. Özyineleme ve yığın
- 7. Fonksiyon işaretçileri
- 8. Void işaretçi
- 9. Struct kopyalama ve derin kopya
- 10. Dinamik metin okuma
- 11. Tek işaretçi ve çift işaretçiyle parametre geçirme
- Örnek Sorular

## 1. Bağlı listede baştan ve sondan silme

Ders, önceki derste başlanan tek yönlü bağlı liste programının tamamlanmasıyla başladı. Programda menüyle çalışan `insert_at_begin`, `traverse` gibi fonksiyonlar vardı. Bu derste menüye iki seçenek daha eklendi: `delete_from_begin` (baştan silme) ve `delete_from_end` (sondan silme). Programda `head` hâlâ global bir değişkendir; hoca bunun daha sonra değiştirileceğini, `head`'in fonksiyonlara parametre olarak geçirileceğini söyledi (bkz. Bölüm 11).

### 1.1 Baştan silme

Baştan silmek, `head`'in gösterdiği düğümü silmek demektir. Önce `head`'in bir yeri gösterip göstermediğine, yani `NULL` olup olmadığına bakılır. Liste boşsa ekrana "List is empty" yazılır ve `return` ile fonksiyondan çıkılır. Hoca burada şu noktayı açtı: `void` bir fonksiyonda `return` kullanılabilir; `void` fonksiyon yalnızca bir değer döndürmez.

Liste boş değilse silinen değeri göstermek için `n = head->data` alınır. Listede ikinci, üçüncü elemanlar olabileceği için `head`'in gösterdiği düğümün `next` alanı bir geçici değişkende (`tmp`) saklanır. Sonra ilk düğüm `free` ile serbest bırakılır ve `head` saklanan adrese taşınır. Hoca bunu OneNote'taki çizim üzerinde gösterdi: `head` 8'i tutan düğümü, onun `next`'i 5'i tutan düğümü gösteriyorsa `tmp`'ye ikinci düğümün adresi (çizimde `0x005`) kopyalanır, ilk düğüm bırakılır, `head = tmp` yapılır (ekrandan, 00:25:00).

```c
void delete_from_begin(){
    NODE *tmp;
    int n;
    if(head==NULL){
        printf("List is empty");
        return;
    }
    n=head->data;
    tmp=head->next;
    free(head);
    head=tmp;
    printf("%d was deleted",n);
}
```

(ekrandan, 00:25:00) İlk yazımda `free(start)` yazılmıştı; derleme hatası üzerine `free(head)` olarak düzeltildi (ekrandan, 00:20:00).

**Soru:** 58. satırda doğrudan `head = head->next` yazılsa olmaz mı? **Cevap:** Yalnız `head`'i ilerletmek isteseydik olurdu, ama o zaman ilk düğüm `free` edilemez; adresi kaybolur. İlk düğümü serbest bırakabilmek için ikinci düğümün adresini önce `tmp` gibi bir değişkende saklamak gerekir.

### 1.2 Sondan silme

Sondan silmede şuna dikkat etmek gerekir: liste tek yönlü olduğu için son düğüme gidildiğinde bir önceki düğüme geri dönülemez. Bu yüzden `head`'den başlayarak arama yapılırken bir yedek değişken sürekli bir önceki düğümü tutar. Arama `next` alanı `NULL` olan düğümde biter. O anda elde iki işaretçi vardır: biri son düğümü, biri ondan öncekini gösterir. Son düğüm `free` edilir, öncekinin `next` alanı `NULL` yapılır.

Ayrıca listede tek eleman varsa o durum ayrıca ele alınmalıdır, çünkü o düğümün öncesi yoktur; öncesi `head`'in kendisidir. Bu durumda düğüm silinir ve `head = NULL` yapılır. Kod iki geçici değişkenle yazıldı; önce `t` denen ikinci işaretçinin adı, `tmp` ile karışmasın diye `u` yapıldı.

```c
void delete_from_end(){
    NODE *tmp, *u;
    int n;
    if(head==NULL){
        printf("List is empty");
        return;
    }
    if(head->next==NULL){
        n=head->data;
        free(head);
        head=NULL;
        printf("%d was deleted",n);
        return;
    }
    tmp=head;
    while(tmp->next!=NULL){
        u=tmp;
        tmp=tmp->next;
    }
    n=tmp->data;
    u->next=NULL;
    free(tmp);
    printf("%d was deleted",n);
}
```

(ekrandan, 00:20:00, 00:25:00; `tmp = head;` ile başlayan döngü kısmı ekranda görülen karelerde yok, altyazıdan kuruldu.) `tmp = head` ataması `head`'i kaybetmemek için yapılır: arama `head` üzerinden değil, onun kopyası üzerinden ilerler.

Program çalıştırıldığında 1, 2, 3, 4 sırayla başa eklendi; `traverse` 4-3-2-1 yazdı. Baştan silme 4'ü sildi, liste 3-2-1 oldu. Sondan silme 1'i sildi, liste 3-2 kaldı. (Ajan bu iki fonksiyonu küçük bir test programına koyup `gcc -Wall` ile derledi ve aynı sonucu aldı.)

> **Ders sonrası not:** Ekranda programın başka bir yerinde `head=NULL; free(head);` sırası görünüyor (ekrandan, 00:15:00). `head` önce `NULL` yapılırsa `free(NULL)` hiçbir şey yapmaz ve düğüm bırakılmaz. Listeyi bırakmak için bütün düğümler sırayla `free` edilmeli, `head = NULL` en sonda yapılmalıdır.

### 1.3 Çalışma soruları

Hoca iki alıştırma önerdi. Birincisi aranan değere göre düğüm silmedir (delete by search). Fonksiyon bir `n` değeri alır; döngü `NULL` yerine verinin `n`'e eşit olduğu düğümü arar. Bulunduğunda bir önceki düğüm, silinen düğümden sonraki düğüme bağlanır: `u->next = tmp->next`. Aranan eleman ilk elemansa durum farklıdır, bunu ayrıca düşünmek gerekir. İkincisi araya, özellikle sıralı biçimde eleman eklemektir. Hoca konuların sarmal biçimde ilerlediğini, bağlı listeye uygulama saatlerinde ve daha gelişmiş bir "employee" örneğiyle tekrar dönüleceğini söyledi. (Çözüm için Örnek Sorular'a bakın.)

## 2. İç içe struct örneği: polinom toplama

Struct konusunu tekrar etmek ve iç içe (nested) struct görmek için iki polinom üzerinde toplama, çıkarma gibi işlemler yapan bir program incelendi.

### 2.1 Veri yapısı

Polinom terimlerden oluşur; her terimin bir katsayısı ve bir üssü vardır. Hoca katsayıların gerçel sayı olabileceğini, üslerin ise tam sayı olması gerektiğini hatırlattı; bu programda ikisi de `int` tutuldu. Bir terim için `TERM` yapısı tanımlandı. `typedef struct term {...} TERM;` yazımında `typedef` kullanmak "bundan sonra `struct term` yerine `TERM` kullan" demektir; aynı tanım `typedef`'i ayrı satıra yazarak da yapılabilir.

Polinom yapısı `POLY` ise iki şey tutar: terim sayısı `N` ve terimler dizisinin işaretçisi `TERM *terms`. Terimler dizisi dinamik bellek ayırmayla oluşturulur. `main` iki polinomun terim sayılarını alır, her biri için `p1.terms`'e `N` tane terimlik `malloc` yapar; `NULL` dönerse işlem başarısız sayılıp program kapatılır.

Hoca, aynı alanları doğrudan `POLY`'nin içine kopyalayarak iç içe yapı kurmadan da yazılabileceğini, ama bu yapının daha modüler ve daha yönetilebilir olduğunu söyledi.

`main`'in akışı (ekrandan, 00:30:00):

```c
readPoly(&p1);
readPoly(&p2);
mySort(&p1);
mySort(&p2);
displayPoly(&p1);
displayPoly(&p2);
p3=toplam(&p1,&p2);
mySort(p3);
printf("toplam\n");
displayPoly(p3);
p3=fark(&p1,&p2);
mySort(p3);
printf("fark\n");
displayPoly(p3);
free(p1.terms);
free(p2.terms);
return 0;
```

### 2.2 Sıralama

Polinomlar genelde sıralı yazılıp işlendiği için önce sıralanır. `mySort` sıralanacak polinomun işaretçisini alır, terim sayısını `pt->N`'den okur ve terimleri üslerine göre kabarcık sıralamasıyla sıralar (ekrandan, 00:30:00):

```c
void mySort(POLY *pt)
{
    int i, j;
    TERM temp;
    int max=pt->N;

    for (i = 0; i < max - 1; i++)
    {
        for (j = 0; j < (max - 1-i); j++)
        {
            if(pt->terms[j].expo > pt->terms[j+1].expo)
            {
                temp=pt->terms[j];
                pt->terms[j]=pt->terms[j+1];
                pt->terms[j+1]=temp;
            }
        }
    }
}
```

`pt->terms[j].expo` ifadesi üç katmanı gösterir: `pt->` polinoma, `terms[j]` polinomun içindeki terimler dizisinin `j`. elemanına, `.expo` o terimin üs alanına gider. `pt` bir işaretçi olduğu için `->`, `terms[j]` bir struct olduğu için `.` kullanılır. Takas `TERM` türünden bir geçici değişkenle, struct'ın bütün alanları birden kopyalanarak yapılır; hoca bunun yerine `memcpy` de kullanılabileceğini söyledi.

> **Ders sonrası not:** Hoca sıralamada derecesi büyük olan terimin başa geleceğini söyledi. Ekrandaki koşul (`terms[j].expo > terms[j+1].expo` ise takas) terimleri küçükten büyüğe sıralar; hoca `toplam`'ı anlatırken küçükten büyüğe sıralandığını kendisi de söyledi. `toplam` da en büyük üssü dizinin son elemanından (`terms[N-1]`) okur.

### 2.3 Okuma ve yazdırma

`readPoly` her terim için önce dereceyi sorar ve `terms[i].expo` alanına, sonra katsayıyı sorar ve `terms[i].coeff` alanına yazar. `displayPoly` terimleri $a \cdot x^n$ biçiminde yazdırır (ekrandan, 00:35:00):

```c
int i;
int max=pt->N;
for(i=max-1;i>0;i--)
    printf("%d(x^%d)+",pt->terms[i].coeff, pt->terms[i].expo);
printf("%d(x^%d)",pt->terms[i].coeff, pt->terms[i].expo);
printf("\n");
```

Döngü sondan başa gittiği için sıralı dizide en büyük dereceli terim önce yazılır.

### 2.4 Toplama

Toplama fonksiyonu iki polinomu alır, yeni bir polinom oluşturur ve onun adresini döndürür. Hoca bunun önemli olduğunu vurguladı: şimdiye kadar fonksiyonlar genelde `void`'di, burada bir `POLY *` döndürülüyor (ekrandan, 00:35:00).

```c
POLY *toplam(POLY *p1, POLY *p2){
    int a = p1->terms[p1->N-1].expo;
    int b = p2->terms[p2->N-1].expo;
    int i,c,max = 1 + ((a>b) ? a : b);
    POLY *p3;

    int *res = (int *) calloc(max,sizeof(int));

    for(i=0; i<p1->N; i++)
        res[p1->terms[i].expo] += p1->terms[i].coeff;

    for(i=0; i<p2->N; i++)
        res[p2->terms[i].expo] += p2->terms[i].coeff;

    for(c=0, i=0; i<max; i++)
        c += (res[i]!=0);

    p3 = (POLY *) malloc(sizeof(POLY));
    p3->terms = (TERM *) malloc(c*sizeof(TERM));

    p3->N = c;
    for(c=0,i=max-1; i>=0; i--)
        if(res[i]){
            p3->terms[c].expo = i;
            p3->terms[c].coeff = res[i];
            c++;
        }
    free(res);
    return p3;
}
```

Adımlar şöyledir:

- `a` ve `b` iki polinomun en büyük üsleridir (sıralı dizinin son terimi).
- `max`, büyük olan üssün bir fazlasıdır; sıfırıncı dereceyi de içermek için.
- `res` dizisi `calloc` ile açılır ki içi sıfır olsun; böylece katsayılar doğrudan üzerine eklenebilir. Dizinin indisi üssü, değeri katsayıyı tutar.
- Önce birinci, sonra ikinci polinomun katsayıları kendi üslerinin hücresine eklenir; aynı dereceli terimlerin katsayıları böylece toplanır.
- Bazı dereceler iki polinomda da olmayabilir ya da katsayılar birbirini götürebilir; bu hücreler sıfır kalır ve yeni polinoma yazılmamalıdır. Bu yüzden sıfırdan farklı hücreler `c`'de sayılır.
- `c` terimlik yeni bir `POLY` oluşturulur, `res` sondan başa okunarak terimler doldurulur, `res` bırakılır ve `p3` döndürülür.

Hoca `fark` fonksiyonunun da bunun aynısı olduğunu söyledi. Döndürülen `p3` dinamik bellekte oluşturulmalıdır. Fonksiyon içinde normal bir yerel değişkenin adresi döndürülseydi değişkenin ömrü (duration) fonksiyonla bittiği için o adres geçersiz olurdu. `static` burada kullanılamaz; bu yüzden dinamik bellek ayırma zorunludur.

**Soru:** Neden `res` dizisinde üsleri de tutmuyoruz, yalnız katsayıları tutuyoruz? **Cevap:** Üsler dizinin indisleridir. Hoca bir örnek verdi: birinci polinom $3x^7 + 4x^2$, ikinci polinom $5x^5 + 3x^3 - 2x^2$ olsun. Bu durumda $a = 7$, $b = 5$ ve `max` $= 7 + 1 = 8$ olur. Sekiz elemanlı dizi 0'dan 7'ye kadar indislere sahiptir, böylece 7. derece de saklanabilir. İndis derece, hücredeki değer katsayıdır.

Bu örneğin sonucu (ara adım eklendi): `res[7] = 3`, `res[5] = 5`, `res[3] = 3`, `res[2] = 4 + (-2) = 2`, diğer hücreler 0. Sıfırdan farklı hücre sayısı $c = 4$'tür ve toplam $3x^7 + 5x^5 + 3x^3 + 2x^2$ olur. (Ajan ekrandaki `mySort`, `displayPoly` ve `toplam` fonksiyonlarını bu girdilerle derleyip çalıştırdı; çıktı `3(x^7)+5(x^5)+3(x^3)+2(x^2)` oldu.)

## 3. Struct döndüren fonksiyonlar: oyuncu verimi örneği

Ömür (duration) konusuyla ilgili ikinci örnek bir oyundu. Her oyuncunun bir ID'si, üç maçta attığı goller ve toplam oynadığı süre vardır. Bu bilgiler kullanıcıdan alınır ve `n` elemanlı bir `GAME` dizisinde saklanır. Dizi şu fonksiyonla açılır (ekrandan, 00:40:00):

```c
GAME *allocate(int n){
    GAME *ptr =(GAME*) malloc(n*sizeof(GAME)); //implicit GAME*=(void*)
    //GAME *ptr =(GAME*) calloc(n,sizeof(GAME)); // the same as in line 17
    return ptr;
}
```

Amaç en başarılı oyuncuyu bulmaktır; bu bir en büyüğü bulma problemidir. Verim, üç maçtaki gol toplamının süreye bölümüdür. Kodun üç sürümü vardır (ekrandan, 00:40:00).

Birinci sürüm en iyi oyuncunun indisini döndürür:

```c
int calculate(GAME *ptr,int n){
    int i, index;
    float yield=0, maxyield=0;
    for(i=0;i<n;i++){
        yield=(float)(ptr[i].goal[0]+ptr[i].goal[1]+ptr[i].goal[2])/ptr[i].duration;
        if(yield>maxyield){
            index=i;
            maxyield=yield;
        }
    }
    return index;
}
```

Döngü bitince en büyüğün indisi bulunmuş olur; `main` bu indisle en iyi oyuncuyu yazdırabilir.

İkinci sürüm (`GAME calculatev2`) indis yerine elemanın kendisini saklar: `yield1 = ptr[i];` ve sonunda `return yield1;`. Hoca burada şunu vurguladı: `yield1` dizi değil, tek bir struct değişkendir. `yield1 = ptr[i]` ataması struct'ın bütün alanlarını kopyalar, bu bellekte yeni bir alan demektir. `return yield1` ile struct çağıran yerdeki değişkene yine kopyalanarak gider. Bu yüzden fonksiyon bitince yerel `yield1` yok olsa da değerler çağıranda yakalanabilir. Bu, fonksiyondan `int` ya da `float` döndürmekten farksızdır.

Üçüncü sürüm (`GAME calculatev3`) aynı işi işaretçiyle yapar: `ptr->goal[0]` gibi erişir, `yield1 = *ptr;` ile o anki elemanı kopyalar ve her adımda `ptr++` ile işaretçiyi ilerletir. Bu yöntemde işaretçinin kendisi arttırıldığı için başlangıç adresi fonksiyon içinde kaybolur. Hoca bir sürümün de `ptr + i` ile yazılabileceğini, o zaman işaretçinin kaybolmadığını söyledi.

Dönüş türünün `GAME` olması, yani struct'ın kopyalanarak dönmesi sayesinde bu sürümlerin hepsi güvenlidir. Hoca karşı örnek olarak şunu anlattı: fonksiyon içinde `static` anahtar sözcüğü olmadan 3 ya da 5 elemanlı normal bir `int` dizisi tanımlanıp başlangıç adresi döndürülseydi dizi kopyalanmazdı; diziler fonksiyonlara ve fonksiyonlardan kopya olarak değil adres olarak gider. Fonksiyon bitince dizinin alanı geçersiz olur ve çağıran o diziyi güvenle kullanamaz. Hata almadan erişilebilir ama farklı (bozulmuş) değerler görülebilir. `malloc` ile oluşturulan bir alanın adresi ise döndürülebilir, çünkü o alan heap bölgesindedir ve `free` edilene kadar yaşar.

## 4. Structure alignment ve bit alanları

Bu bölümden sonra slaytlarla ilerlendi. Hoca konu anlatımını hızlı geçeceğini söyledi.

### 4.1 Structure alignment

Struct üyeleri bellekte tanımlandıkları sıraya göre yerleşir ve aralarında boşluklar oluşabilir. Slayttaki açıklama (ekrandan, 00:45:00): bazı bilgisayarlar char'dan büyük her nesnenin 2'nin kuvveti olan bir adrese, örneğin çift adreslere yerleşmesini ister. Bu hizalama kısıtları normalde programcıya görünmez ama struct içinde boşluklar oluşturabilir. Örnek yapı:

```c
struct ALIGN_EXAMP{
    char mem1;
    short mem2;
    char mem3;
} s1;
```

Kısıt yoksa üyeler art arda sıkıştırılabilir; kısıt varsa `short` çift adrese yerleşeceği için `mem1`'den sonra boşluk kalır. Bu boşluklar belleğin verimsiz kullanılmasına yol açar.

> **Ek bilgi (derste anlatılmadı):** Üyeleri büyükten küçüğe sıralamak (örneğin `short mem2; char mem1; char mem3;`) çoğu derleyicide bu boşlukları azaltır. Ajanın gcc denemesinde yukarıdaki `s1` 6 bayt yer kapladı.

### 4.2 Bit alanları

Bellek miktarının önemli olduğu gömülü sistem programlamada boşlukları azaltmak için başka yaklaşımlar da kullanılır; bunlardan biri bit alanlarıdır (bit fields). Normalde `int` 4 bayt, `char` 1 bayt yer kaplar; bit alanlarıyla bir üyenin kaplayacağı alan bit düzeyinde kısıtlanır.

Hoca iki örnek verdi. Birincisi TC kimlik numarasıdır: 11 haneli bu değerin kaç bitte saklanabileceği hesaplanabilir. İkincisi doğum tarihidir: gün, ay, yıl `int` ya da `short` yapılabilir, ama gün en fazla 31 olduğu için 5 bit, ay en fazla 12 olduğu için 4 bit yeter. Slayttaki örnek (ekrandan, 00:55:00):

```c
struct DATE{
    unsigned int day : 5;
    unsigned int month : 4;
    unsigned int year : 11;
};
```

> **Ders sonrası not:** Hoca TC kimlik numarası için `int`'in sınırının yetersiz kalabileceğini söylerken "$2^{32}$ kimlik numarası için biraz daha büyüktür" dedi. Doğrusu tersidir: $2^{32} \approx 4{,}29 \times 10^9$, 11 haneli bir sayı ise $10^{11}$'e kadar çıkar. 32 bitlik `int` yetmez; en az 37 bit gerekir.

Yazım biçimi basittir: üye adından sonra iki nokta ve bit sayısı yazılır, örneğin `a` 3 bitlik, `b` 7 bitlik, `c` 2 bitlik bir tam sayı olabilir. Bit alanlarının iki kısıtı vardır:

- Bit alanının adresi alınamaz. Adres bir bellek hücresini gösterir; aynı hücrede birden fazla veri saklanıyorsa hücrenin belli bir bitinin adresi diye bir şey yoktur.
- Bit alanlarından dizi oluşturulamaz; "3 elemanlı bit dizisi" gibi bir tanım yoktur.

Hoca bit alanlarında `int` yerine `unsigned int` kullanmanın daha iyi olduğunu söyledi. Gün, ay, yıl gibi değerlerin işaretsiz olduğu bilinir; işaretsiz yazmak gereksiz değerlerin önüne geçer ve daha taşınabilir (portable) olur.

### 4.3 Bit alanına okuma

Derste bir karmaşık sayı yapısı yazıldı (ekrandan, 00:50:00):

```c
typedef struct cmp{
    int r:5;
    int i:3;
}CMP;
```

`scanf("%d", &s.i);` yazılınca derleyici bit alanının adresinin alınamayacağını söyleyen bir hata verir; hata daha derleme aşamasında alınır. Çözüm geçici bir değişken kullanmaktır: değer önce `x`'e okunur, `x` bir `if` ile kontrol edilir, uygunsa bit alanına atanır. `r` 5 bitlik olduğu için koşul $0 \le x < 32$'dir (ekrandan, 01:05:00):

```c
if(x>=0 && x<32){
    s[4].r=x;
}
//scanf("%d",&s.i); illegal
```

Hoca 32'den büyük, örneğin 36-37 gibi bir değer girilirse taşan kısmın 5 bite sığacak biçimde kesileceğini, bunun denenebileceğini söyledi. Bit alanından dizi kurulamaz, ama bit alanı içeren struct'lardan dizi kurulabilir: yukarıda `s` bir `CMP` dizisidir ve `s[4].r` ile dördüncü indisli elemanın `r` alanına sorunsuz erişilir.

> **Ders sonrası not:** Derste `int r:5;` yazıldı. gcc'de `int` türündeki bit alanı işaretli kabul edilir ve 5 bitlik işaretli bir alan $-16 \ldots 15$ aralığını tutar. Ajanın denemesinde `x < 32` kontrolünden geçen 20 değeri `r`'ye $-12$ olarak yazıldı. Hocanın önerdiği gibi `unsigned int r:5;` yazılırsa aralık $0 \ldots 31$ olur ve kontrol beklendiği gibi çalışır.

Bit alanları değerlerin belli aralıklarda girileceği yerlerde kullanılır. Bu, bir tür veri güvenliği de sağlar: biri 5 bitten büyük bir değer girmeye çalışırsa ya hata verilir ya da farklı bir değer görünür. Kullanılan alan yetmezse bir sonraki bit alanı bir sonraki hücreden başlar.

### 4.4 Yerleşimin derleyiciye bağlı olması

Slayttaki şekil `DATE` yapısının bellekte iki farklı yerleşimini gösterir (ekrandan, 00:55:00). Birinci varsayımda derleyici bit alanlarını en yakın `char` sınırına göre paketler ve bir alanın `int` sınırını aşmasına izin verir; `day`, `month`, `year` art arda dizilir ve bir sonraki kaydın alanları önceki sözcüğe taşabilir. İkinci varsayımda derleyici en yakın `short` sınırına göre paketler ve alanların `int` sınırını aşmasına izin vermez; her kayıt bir sözcükte durur ve aralarda boşluk kalır. Bu yüzden alanların başlangıç adresleri değişebilir. Hoca bunun çalışılan ortama, optimizasyon seviyesine ve derleyiciye bağlı olduğunu, çok önemli bir konu olmadığını söyledi. Slayttaki sonuç: en iyi bellek kullanımı için ortamın bazı ayrıntılarını bilmek gerekir, ama alanların sırasını değiştirmek ya da birkaç bit fazla ayırmak gibi önlemler her zaman alınabilir.

Slaytlardaki sonraki örnek kişi bilgilerinin bit alanlı bir struct'ta saklandığı ve `next` alanıyla bağlı listeye dönüştürüldüğü bir programdır; tarih alanları 5, 4 ve 11 bitliktir ve değerler önce geçici bir değişkene okunup sonra atanır. Slaytlardaki bağlı liste örneğinde eleman arama, eleman silme ve bir `p` düğümünden sonra `q` düğümünü ekleyen `insert_after` fonksiyonları da vardır; hoca bunlara bakmanın faydalı olacağını söyledi.

## 5. Union

Union da bir struct gibi tanımlanır, ama struct'ta her üyenin kendi bellek adresi varken (ad, soyad, yaş ayrı yerlerde durur) union'da bir bellek alanı birden fazla üyeye ayrılır. Union altındaki bütün üyeler ortak bir alanı kullanır ve aynı anda yalnızca biri anlamlıdır. Hoca örnek olarak "Türkiye vatandaşıysa kimlik numarasını, yabancıysa pasaport numarasını gir" durumunu verdi.

### 5.1 Slayttaki örnek

```c
typedef union
{
  struct
  {
    char c1, c2;
  } s;
  long j;
  float x;
} U;

U example;
```

(ekrandan, 01:00:00) Bu alanda ya `c1`, `c2` karakterleri ya `long j` ya da `float x` saklanır. `example.s.c1 = 'a'` ve `example.s.c2 = 'b'` yazıldığında alanın ilk iki baytında 97 ve 98'in bitleri durur. Ardından `example.j = 5` gibi bir atama yapılırsa alanın tamamı 5'e göre yeniden yazılır (overwrite) ve `c1`, `c2`'nin 97, 98 değerleri kalmaz. Benzer biçimde `x`'e 5.28 gibi bir float yazılıp alan `long` olarak okunursa okunan değer float değil, float'ın IEEE 754 bitlerinin tamsayı olarak yorumudur.

### 5.2 Derste yazılan deneme

Hoca aynı yapıyı Dev-C++'ta yazdı ve denedi (ekrandan, 01:00:00, 01:05:00):

```c
U example;
example.s.c1='a';
example.s.c2='b';
printf("%c\n",example.s.c1);
printf("%d",example.j);
example.x=5.56;
printf("%c\n",example.s.c1);
printf("%ld",example.j);
```

- `c1` yazdırılınca `a` görüldü.
- `j` okununca büyük bir sayı geldi: alt baytlar 97 ve 98, bu baytlar birlikte bir tamsayı olarak yorumlanıyor.
- `x = 5.56` yazıldıktan sonra `c1` okununca `a` yerine anlamsız bir simge görüldü. Float alanın tamamını işgal etti; `c1`'e karşılık gelen bayt artık float'ın bir parçası.
- `j` tekrar okununca yine büyük bir sayı geldi; bu, 5.56'nın 0 ve 1'lerle yazılmış halinin onluk karşılığıdır.

Hoca bunu bir IEEE 754 hesaplayıcısı ve ikilikten onluğa çeviriciyle doğrulamaya çalıştı, tek ve çift duyarlıklı gösterimler arasında karışıklık olduğu için tam sonuca ulaşamadı ve amacın üyelerin aynı alanı paylaştığını göstermek olduğunu söyledi.

Derste ara adım olarak şu da anlatıldı: `j`'ye bir şey yazmadan yalnız `c2`'ye `'b'` yazılmışsa `c2` okununca `b` görülür. `j` okunursa ve diğer baytlar sıfırsa `b`'nin ASCII kodu 98'in konumuna göre bir tamsayı okunur; float olarak okunursa yine farklı bir değer gelir.

> **Ders sonrası not:** Üst baytlar sıfırsa ilk `j` okuması $98 \cdot 256 + 97 = 25185$ verir; `example` ilklenmediği için üst baytlarda rastgele değer de olabilir. 5.56'nın 32 bitlik IEEE 754 karşılığı `0x40B1EB85`'tir. `long` 32 bit olduğunda (Windows'ta olduğu gibi) `j` $1085401989$ olarak, `c1` ise `0x85` baytı olarak okunur. Ajan bunu python ve gcc ile doğruladı. Derste satır 33'e yapıştırılan uzun ikilik dizi, 5.56'nın double gösteriminin anlamlı kısmına aittir; bu yüzden hesaplayıcıyla bulunan sayı derste beklenenden büyük çıktı.

> **Ek bilgi (derste anlatılmadı):** C standardına göre union'a en son yazılan üyeden farklı bir üyeyi okumak baytların başka türde yorumlanması demektir; sonuç sistemin bayt sırasına (little/big endian) ve türlerin boyutlarına bağlıdır. Union'ın boyutu en büyük üyesi kadardır.

### 5.3 Gerçek hayattan örnek

Kişi bilgileri saklanırken Türk vatandaşı ise kimlik numarası, değilse doğduğu şehir saklansın; ikisi de karakter dizisi olsun. Normalde bu `if` ile çözülür: Türk vatandaşıysa bir alana, değilse öbür alana yazılır. Ama struct'ta iki alan da her kayıtta yer kaplar. Yalnız bu iki alan bir union içine alınırsa ikisi aynı yeri paylaşır; hocanın söylediğine göre 40 baytlık bir alan 20 bayta düşürülebilir. Yazarken `if` ile uygun üyeye yazılır, okurken de aynı üyeden okunur. Hoca union kullanımına yığın (stack) örnekleri yaparken daha genel örneklerle döneceğini söyledi.

## 6. Özyineleme ve yığın

Aradan sonra özyineleme (recursion) konusuna geçildi. Hoca özyinelemenin genel bir programlama ve algoritma konusu olduğunu, C'deki yazımının çoğu dilde olduğu gibi basit olduğunu söyledi: bir fonksiyonun içinde aynı adlı fonksiyonu tekrar çağırmak özyinelemedir. Gelen parametrelerin ve çağrıdan önce yapılacak işlemlerin tasarımı algoritma tasarımına bağlıdır.

### 6.1 Durma koşulu olmayan özyineleme

Slayttaki fonksiyon kendini koşulsuz çağırır ve her çağrıda `static` bir sayacı yazdırıp arttırır; sayaç kaç çağrı yapıldığını göstermek içindir. Teorik olarak sonsuza kadar çalışması gerekir. Çalıştırıldığında ekranda sayaç kırk üç binleri geçti (ekrandan, 01:25:00), sonra program hata verip kapandı. Bu hata belleğin daha fazla kullanılamaması, yani daha fazla çağrı yapılamaması hatasıdır. Sonsuz çalışmayı önlemek için algoritmada çağrıdan önce mutlaka bir `if` ile koşul yazılmalı ve koşul sağlanınca fonksiyon `return` etmelidir.

### 6.2 Fonksiyon çağrısı neden yığını doldurur

Hoca bunu Assembly'deki program sayacıyla (program counter) açıkladı. Program sayacı çalıştırılacak bir sonraki komutun adresini tutar. Programın 10. satırında bir fonksiyon çağrılsın, fonksiyon 100. satırda başlayıp 110. satırda bitsin. Fonksiyon bitince 11. satıra dönülmesi gerekir; demek ki 11 bir yerde saklanmalıdır.

Bu adres bir yazmaçta, örneğin AX'te saklanabilir: program sayacı 100'ü alır, fonksiyon çalışır, `return` görülünce AX'teki 11 program sayacına kopyalanır. Ama fonksiyonun içinden başka bir fonksiyon (örneğin 200. adreste) çağrılırsa bu kez 110 civarındaki dönüş adresinin de saklanması gerekir. İç içe 20 fonksiyon çağrılırsa o kadar yazmaç yoktur. Bu yüzden belleğin yığın (stack) bölgesi kullanılır: her çağrıda dönüş adresi yığına itilir (önce 11, sonra iç çağrının dönüş adresi), her `return`'de yığının tepesindeki adres çekilip program sayacına yazılır.

Yığına yalnız dönüş adresleri konmaz. Assembly açısından bakıldığında `main` bir program, çağrılan fonksiyon başka bir programdır. Fonksiyon çağrısı geldiğinde `main`'deki değişkenler, işlemcinin durum yazmaçları ve bayrakları (carry flag gibi) da yığında saklanır. Bir fonksiyonun içinden başka bir fonksiyon çağrıldığında onun içindekiler de yığına konur. Özyinelemeli çağrıda bu silsile defalarca tekrarlanır ve bir noktada bellek dolar. Hoca bunun özyinelemeye özgü olmadığını, her fonksiyon çağrısında olduğunu vurguladı.

Slayttaki şekil (ekrandan, 01:30:00) bunu üç durumda gösterir: (a) program `main`'de çalışırken yığında `main`'in değişkenleri vardır; (b) `main` `func1`'i çağırınca `func1`'in değişkenleri ve `main`'in ona geçirdiği parametreler yığının tepesine eklenir; (c) `func1` dönünce onun alanı bırakılır ve yığının tepesi ilk konumuna döner. Slayt ayrıca yığın alanının programın çalışması boyunca tekrar tekrar kullanıldığını, bu alanda önceki kullanımlardan kalan çöp değerler bulunacağını vurgular.

Hoca özyinelemenin problemleri daha kolay çözdüğünü ama belleği daha hızlı doldurduğunu, yani bellekten ödün verildiğini söyledi; sıralama algoritmalarında özyinelemeyle karmaşıklığın genellikle $n \log n$'e indiğini örnek verdi.

### 6.3 Genel yapı ve faktöriyel

Özyinelemeli bir çözümde bir temel durum (base case) belirlenir; faktöriyel için bu $n$'in 1 ya da 0 olmasıdır. Temel duruma ulaşana kadar fonksiyon, problemin daha küçük ve daha basit bir parçasıyla kendini çağırır. Temel duruma ulaşıldığında sonuçlar geriye doğru birleştirilerek döner.

Hoca önce kendi yazımıyla anlattı: `fact(x)` içinde `x == 0` ise `return 1`, değilse `return x * fact(x-1)`. Sonra yan yana yazarak izledi; bu sırada temel durumu 1 olarak düzeltti. Slayttaki kod (ekrandan, 01:35:00):

```c
#include <stdio.h>
int fact( int n ) {
    if( n <= 1 )
        return 1;
    else
        return n*fact(n-1);
}
int main() {
    printf("5! is %d\n", fact(5));
    return 0;
}
```

(Slaytta `main() {` yazılıdır; yukarıda `int main()` ve `return 0;` eklendi. Ajan `gcc -Wall` ile derledi, çıktı `5! is 120`.)

`fact(5)` çağrısının izlenmesi (slayttaki adımlar):

- Adım 1-5: `fact(5)` → `5 * fact(4)` → `4 * fact(3)` → `3 * fact(2)` → `2 * fact(1)`. Çarpma yapılmadan önce fonksiyon çağrısı tamamlanmalıdır, bu yüzden çarpmalar bekler.
- Adım 6: `fact(1)` temel durumdur, 1 döndürür.
- Adım 7: `2 * 1 = 2` döner.
- Adım 8: `3 * 2 = 6` döner.
- Adım 9: `4 * 6 = 24` döner.
- Adım 10: `5 * 24 = 120` döner.

Hoca kendi izlemesinde "6 çarpı 4" dediğini, slaytta "4 * 6" yazdığını; farkın yalnız çarpanların yazılış sırasından geldiğini söyledi. Her iki yazımda da önce özyinelemeli çağrı yapılır, çünkü çarpmanın işlenenlerinden biri o çağrının sonucudur.

Slayt Fibonacci sayıları ($F_{n+1} = F_n + F_{n-1}$), ikili arama ve derinlik öncelikli aramayı ev alıştırması olarak bırakır. Hoca bağlı listeler, ikili arama ve özellikle ikili arama ağaçlarında özyinelemenin çok işe yarayacağını, çünkü orada yinelemeli (iteratif) kod yazmanın daha karışık olduğunu söyledi.

## 7. Fonksiyon işaretçileri

### 7.1 `main`'in argümanlarından fonksiyon işaretçisine

Hoca önce `main`'in argümanlarını hatırlattı: bir argüman sayacı (`argc`) ve bir argüman vektörü (`argv`) vardır, program çalışırken bunlar kullanılabilir. Derleyici `main`'i diğer fonksiyonlar gibi ele alır; çalışma anında bu iki argümanı sağlamak çalışma ortamının görevidir. Slayttaki örnek (ekrandan, 01:10:00):

```c
int main(int argc, char *argv[])  {
     while(--argc > 0 )
           printf("%s\n",  *++argv);
     exit(0);
}
```

Komut satırı argümanlarını ayrıştıran hazır fonksiyonlar (`getopt` gibi) da vardır; hoca bunların çok önemli olmadığını, `argc` ve `argv`'yi bilmenin yeterli olduğunu söyledi.

### 7.2 Tanım

Fonksiyonlar genellikle adlarıyla çağrılır ama bir işaretçiyle de çağrılabilir. Bunun için fonksiyonun prototipine uyan bir işaretçi değişkeni tanımlanır. İki yazım arasındaki farka dikkat etmek gerekir:

- `int *pf();` bir fonksiyon bildirimidir (allusion): parametre almayan ve `int *` döndüren bir fonksiyon.
- `int (*pf)();` bir değişken tanımıdır: `int` döndüren bir fonksiyonu gösteren işaretçi. `*pf`'nin etrafındaki parantezler bunun bir fonksiyon işaretçisi olduğunu gösterir.

Bu prototipe uyan her fonksiyon bu işaretçiyle çağrılabilir.

### 7.3 Atama kuralları

`f1` adlı bir fonksiyon için:

- `pf = f1;` doğrudur; fonksiyon adı fonksiyonun adresidir.
- `pf = f1();` geçersizdir; `f1`'in döndürdüğü değeri `pf`'ye atamaya çalışır. `f1` `int` döndürür ve `int` bir fonksiyon işaretçisine atanamaz.
- `pf = &f1();` geçersizdir; `f1`'in döndürdüğü `int` bir değerdir, değerin adresi olmaz. Yalnız değişkenlerin adresi olur.

> **Ders sonrası not:** Hoca `pf = &f1;` yazımının da geçersiz olduğunu, "adresin adresi" gibi olacağını söyledi. Standart C'de fonksiyon adının adresini almak geçerlidir; `pf = &f1;` ile `pf = f1;` aynı işi yapar. Ajan bunu gcc ile denedi.

Dönüş türleri de uyuşmalıdır. Slayttaki örnekte `int` döndüren `if1`, `if2` fonksiyonları ve `pf1` işaretçisi, `float` döndüren `ff1` ve `pff` işaretçisi, `char` döndüren `cf1` ve `pcf` işaretçisi vardır:

- `pf1 = if1;` geçerlidir, türler uyar.
- `pf1 = cf1;` geçersizdir, biri `char` biri `int`.
- `pff = if2;` geçersizdir, biri `float` biri `int`.
- `pcf = cf1;` geçerlidir.
- `if1 = if2;` geçersizdir; fonksiyon adları sabit adreslerdir, onlara atama yapılamaz.

(Bu satırlar altyazıdan kuruldu; slayt karede okunamayacak kadar küçük.) Ajanın gcc denemesinde türü uyuşmayan iki atama derleme hatası verdi.

### 7.4 Fonksiyon işaretçisiyle çağrı

Slayttaki program (ekrandan, 01:40:00):

```c
#include <stdio.h>
extern int f1(int); //could be defined externally but we have coded it below
int main() {
    int n;
    int (*pf) (int);
    int answer;
    printf("Bir sayi giriniz: "); scanf("%d",&n);

    pf=f1;
    answer=(*pf)(n); // calls f1() with argument n => f1(n)

    printf("%d", answer);
    return 0;
}
int f1( int a ) {
    return a+1;
}
```

`f1` başka bir dosyada tanımlanabileceği için `extern` ile bildirilmiştir; burada aynı dosyanın sonunda yazılmıştır. `pf = f1` atamasından sonra `(*pf)(n)` "`pf`'nin gösterdiği adrese `n` parametresiyle git" demektir; bu `f1(n)` çağrısıyla aynıdır.

> **Ders sonrası not:** Slaytta `int (*pf) ();` yazılıdır. Eski C standartlarında boş parantez "parametreler belirtilmemiş" demektir ve kod derlenir. gcc 15 varsayılan olarak C23 kullanır; C23'te boş parantez "parametre yok" anlamına gelir ve `(*pf)(n)` hata verir. Yukarıda `int (*pf) (int);` yazıldı. Ajan bu haliyle `gcc -Wall` ile derledi; 7 girdisi için çıktı 8 oldu.

### 7.5 Nerede kullanılır: delegate benzetmesi

Hoca nesneye yönelik ve görsel programlamadaki delegate kavramını örnek verdi. Bir stadyumun ya da otobüs firmasının koltukları için görsel programlamayla butonlar oluşturulduğunu düşünelim. Bir koltuk seçilince arka planda "bu kişi 1 numaralı bileti aldı, veritabanında gerekli işleri yap" olayı çalışır. Her buton için ayrı bir olay (tıklama olayı gibi) ve ayrı bir fonksiyon yazmak, 40 bin koltuk için 40 bin olay tanımlamak demektir ve kodu çok uzatır. Bunun yerine genel amaçlı tek bir fonksiyon yazılır; hangi koltuktan değer geldiği parametreyle anlaşılır ve fonksiyon ona göre özel amaçlı çalışır. Delegate'lerin mantığı budur.

### 7.6 Tek fonksiyonla artan ve azalan sıralama

Daha kısa bir örnek sıralamadır. Kullanıcıya "artan sıralama için 1'e, azalan için 2'ye basınız" denildiğinde iki ayrı sıralama algoritması yazmak mantıklı değildir. Kabarcık sıralamasında artan ile azalan arasındaki tek fark iki elemanı karşılaştırıp takas etme koşuludur; geri kalan her şey aynıdır. Bu yüzden karşılaştırma bir fonksiyon işaretçisiyle dışarıdan verilir (ekrandan, 01:45:00):

```c
#include <stdio.h>
#define SIZE 10

void bubble( int work[], const int size, int (*compare)( int a, int b ) );
int ascending( int a, int b );
int descending( int a, int b );

int main( void )
{
   int order;
   int counter;

   int a[ SIZE ] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };

   printf( "Enter 1 to sort in ascending order,\n"
           "Enter 2 to sort in descending order: " );
   scanf( "%d", &order );

   printf( "\nData items in original order\n" );
   for ( counter = 0; counter < SIZE; counter++ ) {
      printf( "%5d", a[counter] );
   }
   /* sort array in ascending order; pass function ascending as an
      argument to specify ascending sorting order */
   if ( order == 1 ) {
      bubble( a, SIZE, ascending );
      printf( "\nData items in ascending order\n" );
   }
   else { /* pass function descending */
      bubble( a, SIZE, descending );
      printf( "\nData items in descending order\n" );
   }
   /* output sorted array */
   for ( counter = 0; counter < SIZE; counter++ ) {
      printf( "%5d", a[ counter ] );
   }
   printf( "\n" );
   return 0;
}

/* multipurpose bubble sort; parameter compare is a pointer to
   the comparison function that determines sorting order */
void bubble( int work[], const int size, int (*compare)( int a, int b ) )
{
   int pass;  /* pass counter */
   int count; /* comparison counter */
   void swap( int *element1Ptr, int *element2ptr ); /* prototype */

   for ( pass = 1; pass < size; pass++ ) {
      for ( count = 0; count < size - 1; count++ ) {
         if ( (*compare)( work[ count ], work[ count + 1 ] ) ) {
            swap( &work[ count ], &work[ count + 1 ] );
         }
      }
   }
}

void swap( int *element1Ptr, int *element2Ptr )
{
   int hold = *element1Ptr;
   *element1Ptr = *element2Ptr;
   *element2Ptr = hold;
}

int ascending( int a, int b ) { return b < a; }
int descending( int a, int b ) { return b > a; }
```

<!-- BELİRSİZ: dizinin ilk değerleri karede soluk; 12 olarak okunan değer 120 de olabilir. -->

`main` ile `bubble` fonksiyonunun başı ve `swap` prototipi karede görülüyor. `bubble`'ın döngüleri, `swap` ve karşılaştırma fonksiyonlarının gövdeleri karede yok; hocanın anlatımına göre (`work[count]` ile `work[count+1]` karşılaştırılır, sonuç doğruysa takas edilir) ajan tarafından tamamlandı. Ajan programı `gcc -Wall` ile derledi; 1 girdisi için `2 4 6 8 10 12 37 45 68 89`, 2 girdisi için `89 68 45 37 12 10 8 6 4 2` yazdı.

`bubble( a, SIZE, ascending )` çağrısında son argüman bir fonksiyon adıdır, yani fonksiyonun adresidir. `bubble`'ın üçüncü parametresi `int (*compare)(int a, int b)` iki `int` alıp `int` döndüren bir fonksiyon işaretçisidir. `bubble` içinde `(*compare)(work[count], work[count+1])` hangi fonksiyon geçirildiyse onu çağırır; dönen doğru ya da yanlış sonuca göre takas yapılır.

### 7.7 Genel toplama örneği

Hoca bir örnek daha gösterdi: bir dizinin elemanlarının ya kendilerini ya karelerini toplayan bir "generic" fonksiyon. Normalde biri kendisini, biri karesini toplayan iki ayrı fonksiyon yazılırdı. Bunun yerine bir değerin kendisini döndüren (`self`) ve karesini döndüren (`square`) iki küçük fonksiyon yazılır; genel toplama fonksiyonu bir fonksiyon işaretçisi parametresi alır ve hangisi geçirilirse ona göre toplar. <!-- BELİRSİZ: bu örneğin kodu görülen karelerde yok; yalnız altyazıdaki anlatım aktarıldı. -->

### 7.8 Fonksiyon işaretçisi dizisi

Fonksiyon işaretçilerinden dizi de oluşturulabilir. Örnekte aynı parametreleri alan ve aynı türü döndüren dört fonksiyon vardır: `sum`, `subtract`, `multiply`, `divide`. Fonksiyonların yapısı aynı olmalıdır, farklı olursa diziye konamaz. İki `int` alıp `int` döndüren dört elemanlı bir fonksiyon işaretçisi dizisi tanımlanır (örnekte global, ama başka yerde de tanımlanabilir). Dizinin 0. elemanına `sum`, sonrakilere `subtract`, `multiply` ve `divide` konur. Kullanıcının seçtiği işleme göre ilgili eleman çağrılır ve sonuç yazdırılır. <!-- BELİRSİZ: bu örneğin kodu görülen karelerde yok; dizinin yazımı altyazıdaki anlatımdan aktarıldı. -->

> **Ek bilgi (derste anlatılmadı):** Böyle bir dizi `int (*p[4])(int, int) = { sum, subtract, multiply, divide };` biçiminde tanımlanır ve `p[i](a, b)` ya da `(*p[i])(a, b)` ile çağrılır.

## 8. Void işaretçi

Hoca dosya işlemlerine geçmeden önce void işaretçi konusunu ele aldı; dosya konusunu gelecek derste bitireceğini söyledi.

### 8.1 `malloc` ve `void *`

Şimdiye kadar `malloc`'tan dönen değer, oluşturulacak dizinin türüne dönüştürülüyordu (cast). Hoca `malloc`'un tanımını Dev-C++'ta gösterdi: `malloc` bir `void *` döndürür (ekranda "void pointer" olarak görüldü). Bu değer daha sonra polinom örneğinde olduğu gibi istenen türe, `int *` ya da bir struct işaretçisine dönüştürülür. Hoca derleyicinin bu dönüşümü kendisi de yaptığını, ama garanti olsun ve tür belli olsun diye açıkça yazıldığını söyledi; bağlı listede `(NODE *)` dönüşümü bu yüzden yazılmıştı.

### 8.2 Genel kullanım

`void *` her türden adresi tutabilen genel (generic) bir işaretçidir. Gösterdiği yere değer yazmak için önce uygun işaretçi türüne dönüştürülür, sonra `*` ile erişilir. Dönüşüm yazılmazsa hata alınır. Slayttaki örnek (ekrandan, 02:00:00):

```c
#include<stdio.h>
#include<conio.h>
Void main()
{
    int p;
    float d;
    char c;
    void *pt;
    clrscr();
    pt=&p;
    *(int*)pt=10;
    printf("\n p=%d",p);
    pt=&d;
    *(float *)pt=3.4;
    printf("\n d=%f",d);
    pt=&c;
    *(char *)pt= 's';
    printf("\n c=%c",c);
    getch();
}
```

Hoca slaytta `pt` yerine yanlış yazılmış bir ad olduğunu söyledi ve düzeltti. `clrscr` ekran silmeyle ilgilidir ve eski bir kütüphaneden (`conio.h`) gelir; önemli değildir. `pt = &p` ile `pt` `p`'yi gösterir; `(int*)pt` onu `int` işaretçisine dönüştürür, baştaki `*` gösterilen adrese 10 yazar. Aynı `pt` sonra `d`'yi gösterir ve `float *`'a, sonra `c`'yi gösterir ve `char *`'a dönüştürülerek kullanılır.

> **Ders sonrası not:** Slayttaki kod standart C değildir: `Void` büyük harfle yazılmış, `main` `void` döndürüyor, `conio.h`, `clrscr` ve `getch` standart kütüphanede yoktur. Ajan bunları çıkarıp `int main(void)` ve `return 0;` ile yazdığı halini `gcc -Wall` ile derledi; çıktı `p=10`, `d=3.400000`, `c=s` oldu.

## 9. Struct kopyalama ve derin kopya

Hoca daha önce anlattığı kopyalama konusuna bir PDF üzerinden tekrar döndü. Değişkenler üç yolla kopyalanır: atama operatörüyle, fonksiyona parametre olarak geçirilerek ve fonksiyondan `return` ile dönerek.

Slayttaki örnek (ekrandan, 01:55:00) "derin" içeriği olan bir struct'tır:

```c
struct PolynomialType {
   unsigned int Degree;
   int*         Coeff;   // dynamically-allocated array
};

typedef struct PolynomialType Polynomial;
. . .
Polynomial P;

P.Degree = 2;
P.Coeff = malloc(3 * sizeof(int));
```

Slayttaki not: `Coeff` `P`'nin bir üyesidir, ama gösterdiği dizi `P`'nin üyesi değildir. Dizi yalnızca dinamik olarak ayrılmış ve `Coeff`'in gösterdiği yerdedir. Bu yüzden struct ataması diziyi kopyalamaz.

Örnekte `P`'nin katsayıları 1, 2, 3 olarak atanır, sonra `P = Q` gibi bir atama yapılır. Struct ataması üyeleri tek tek kopyalar; `Coeff` bir adres olduğu için iki struct aynı diziyi gösterir. Birinin katsayısı 5 yapılırsa öteki de değişir; hoca bunu "arka kapıdan dolaşmak" diye niteledi. Sonra birinin katsayı dizisi `free` edilirse ötekinin gösterdiği alan da kaybolur; bağlı listelerdeki `free` işleminde olduğu gibi.

Gerçek bir derin kopya (deep copy) için, yani kaynaktan hedefe bütün içeriği kopyalamak için `memcpy` ile ya da bir döngüyle bütün elemanlar tek tek kopyalanmalıdır; slayttaki fonksiyon kaynaktaki değerleri hedefe tek tek kopyalar.

> **Ders sonrası not:** Derste struct ataması için "dip copy (derin kopya)" ifadesi kullanıldı. Struct ataması üye üye kopyadır. İşaretçi içermeyen struct'larda bu bütün veriyi kopyalar (Bölüm 3'teki `GAME` gibi). İşaretçi üyesi olan struct'ta ise yalnız adres kopyalanır; buna yüzeysel kopya (shallow copy) denir. Derin kopya için hedefe `malloc` ile ayrı bir alan açılmalı ve elemanlar oraya `memcpy` ya da döngüyle kopyalanmalıdır.

## 10. Dinamik metin okuma

Hoca öğrencilerden gelen bir soruya cevap olarak, uzunluğu bilinmeyen bir metnin Enter'a basılana kadar nasıl okunacağını gösterdi. `getchar` klavyeden her basışta bir karakter döndüren bir fonksiyondur. Karakter `'\n'`'den (Enter) farklı olduğu sürece karakter alınır, karakter dizisine konur ve dizi `realloc` ile bir eleman büyütülür. Enter'a basılınca dizinin sonuna sonlandırma karakteri (`'\0'`) eklenir. Arada boşluk olsa bile Enter'a kadar girilen bütün karakterler bu yapıyla saklanır.

Bu programın kodu görülen karelerde yok. Aşağıdaki kod anlatılan algoritmaya göre ajan tarafından yazıldı; `gcc -Wall` ile derlendi ve `merhaba dunya 123` girdisiyle denendi.

```c
#include <stdio.h>
#include <stdlib.h>
int main(void){
    char *str = NULL, *tmp;
    int len = 0, ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        tmp = (char *) realloc(str, len + 2);
        if (tmp == NULL) { free(str); return 1; }
        str = tmp;
        str[len++] = (char) ch;
    }
    if (str == NULL) { str = (char *) malloc(1); if (str == NULL) return 1; }
    str[len] = '\0';
    printf("%s (%d karakter)\n", str, len);
    free(str);
    return 0;
}
```

## 11. Tek işaretçi ve çift işaretçiyle parametre geçirme

Dersin son bölümünde hoca uzun bir örneği OneNote'ta adres adres çizerek izledi. Amacın bu mantığı elle çözmek olduğunu, bağlı listede `head`'i global değişken yerine parametre olarak kullanırken buna ihtiyaç duyulacağını söyledi.

### 11.1 Senaryo 1: tek işaretçi

Kod (ekrandan, 02:05:00, 02:10:00):

```c
printf("---------------------------------\nScanario-1\n");
// our var
int z = 10;
int *h = &z;
printf("main - value of z: %d\n", z);                      //10
printf("main - addr of z: %p\n", &z);                      //&z
printf("main - value of h: %p\n", h);                      //&z
printf("main - value of what h points to: %d\n", *h);      //10
*h = 22;
printf("main - value of z: %d\n", z);                      //22
printf("main - value of what h points to: %d\n", *h);      //22
my_func(h);
printf("main - value of what h points to: %d\n", *h);      //22
printf("main - value of h: %p\n", h);                      //&z

void my_func(int *p) {
    // allocate space for an int
    int *z = (int *) malloc(sizeof(int));
    // assign a value
    *z = 99;
    printf("my_func - value of z: %d\n", *z);              //99
    printf("my_func - value of p: %p\n", p);               //&z
    // change the value of the pointer p. Now it is not pointing to h anymore
    p = z;
    printf("my_func - make p point to z\n");
    printf("my_func - addr of z %p\n", &*z);
    printf("my_func - value of p %p\n", p);
    printf("my_func - value of what p points to: %d\n", *p); //99
    //free(z);
}
```

Hoca önce adresleri 100 ve 500 gibi temsilî sayılarla, sonra programın gerçek çıktısıyla izledi. Gerçek çıktıdaki adresler (ekrandan, 02:10:00):

- `z`'nin değeri 10, adresi `23FE44`. `h = &z` olduğu için `h`'nin değeri de `23FE44`'tür ve `*h` 10'dur.
- `*h = 22` ile `h`'nin gösterdiği yere, yani `z`'ye 22 yazılır; `z` ve `*h` artık 22'dir.
- `my_func(h)` çağrılınca `h`'nin değeri, yani `23FE44`, `p`'ye kopyalanır. `p` de `z`'yi gösterir.
- Fonksiyon içinde `malloc` ile yeni bir alan açılır; adresi `2F69D0`'dır ve `z` adlı yerel işaretçi onu gösterir. Oraya 99 yazılır. Bu `z`, `main`'deki `z`'den farklıdır; hoca aynı adı bilerek kullandı.
- `p` yazdırılınca hâlâ `23FE44` görülür. Bu noktada `*p` yazdırılsaydı 22 görülürdü.
- `p = z` ile `p`'nin içeriği `2F69D0` olur; `p` artık yeni alanı gösterir ve `*p` 99'dur. `main`'deki `z` ile bağlantı kopmuştur.
- Fonksiyon bitince `main`'de `*h` hâlâ 22, `h` hâlâ `23FE44`'tür.

Fonksiyona adres geçirildi ama o adresteki veri değiştirilmedi; yalnız adresin yerel kopyası olan `p` başka yeri gösterecek biçimde değiştirildi. Hocanın deyişiyle iki taraf "kendi aleminde kaldı". `main`'deki `h`'nin değişmesi isteniyorsa başka bir yol gerekir.

> **Ders sonrası not:** Senaryo 1'de `my_func` içinde `malloc` ile açılan alan `free` edilmiyor (`//free(z);` yorum satırı) ve fonksiyon bitince adresi kayboluyor; bu bir bellek sızıntısıdır.

### 11.2 Senaryo 2: çift işaretçi

İkinci senaryo birincisinden bağımsız düşünülmelidir. Kod (ekrandan, 02:15:00, 02:20:00):

```c
printf("---------------------------------\nScanario-2\n");
// our var
int zz = 10;
int *hh = &zz;
printf("main - value of zz: %d\n", zz);
printf("main - addr of zz: %p\n", &zz);
printf("main - value of hh: %p\n", hh);
printf("main - value of what hh points to: %d\n", *hh);
*hh = 22;
printf("main - value of zz: %d\n", zz);
printf("main - value of what hh points to: %d\n", *hh);
my_func_2(&hh);
printf("main - value of what hh points to: %d\n", *hh);
printf("main - value of hh: %p\n", hh);
free(hh);

void my_func_2(int **p) {
    // allocate space for an int
    int *z = (int *) malloc(sizeof(int));
    // assign a value
    *z = 999;
    printf("my_func - value of z: %d\n", *z);

    printf("my_func - value of p: %p\n", p);
    printf("my_func - value of h: %p\n", *p);
    // change the value of the pointer p. Now it is not pointing to h anymore
    *p = z;
    printf("my_func - make p point to z\n");
    printf("my_func - addr of z %p\n", &*z);
    printf("my_func - value of p %p\n", p);
    printf("my_func - value of h %p\n", *p);
    printf("my_func - value of what p points to: %d\n", **p);
    // we are not deallocating, because we want to keep the value in that
    // memory location, in order for h to access it.
    /* free(z); */
}
```

Bu kez fonksiyona `hh` değil, `hh`'nin adresi (`&hh`) gönderilir, çünkü değişmesi istenen `hh`'nin kendisidir. `hh` birinci dereceden bir işaretçi olduğu için adresi ikinci dereceden bir işaretçiyle (`int **p`) alınmalıdır; tür buna dönüşür. Ekrandaki çıktıya göre adım adım (ekrandan, 02:15:00):

- `zz`'nin adresi `23FE40`, değeri 10. `hh = &zz` ile `hh` `23FE40`'ı gösterir.
- `*hh = 22` ile `zz` 22 olur.
- `my_func_2(&hh)` çağrısında `hh` değişkeninin kendi adresi `23FE38`'dir; bu adres `p`'ye kopyalanır. `p` artık `hh`'yi gösterir.
- Fonksiyon içinde `malloc` ile açılan alanın adresi `6269F0`'dır; `z` onu gösterir ve oraya 999 yazılır.
- `p` yazdırılınca `23FE38` (yani `hh`'nin adresi), `*p` yazdırılınca `23FE40` (yani `hh`'nin içindeki adres) görülür.
- `z = p` yazılamaz, çünkü `z` birinci, `p` ikinci dereceden işaretçidir. Doğru yazım `*p = z`'dir: "`p`'nin gösterdiği yere, yani `hh`'nin içine, `z`'nin değerini yaz." `hh`'nin içeriği `6269F0` olur.
- Bundan sonra `p` hâlâ `23FE38`'i, `*p` `6269F0`'ı, `**p` 999'u verir. Hocanın deyişiyle: "`p`'nin gösterdiği yerin gösterdiği yerdeki değer."
- Fonksiyon bitince `main`'de `*hh` 999, `hh` `6269F0` olur. Bir önceki satırda `*hh` ana programdaki 22'yi gösterirken artık alt programda oluşturulan yeni alanı gösterir.

Fonksiyonda açılan alan `free` edilmez, çünkü `main`'deki `hh` o alanı kullanacaktır; alan `main`'in sonunda `free(hh)` ile bırakılır.

(Ajan iki senaryoyu tek programda birleştirip `gcc -Wall` ile derledi ve çalıştırdı. Adresler farklı çıktı ama değerler ekrandakiyle aynıydı: Senaryo 1'de `main`'e dönünce `*h` 22, Senaryo 2'de `*hh` 999.)

### 11.3 Bağlı listeye bağlantı

Hoca bunu bağlı listeye bağladı. Bağlı listede başa ekleme ya da baştan silme yapılınca `head`'in gösterdiği düğüm değişir. Bu bir tür "head güncelleme"dir. `head` global değil de parametre olarak geçirildiğinde iki yol vardır:

- Tek işaretçiyle `head` alınır ve fonksiyon güncel `head`'i döndürür (`NODE *` dönüş türü). Yeni düğüm dinamik bellekte oluşturulduğu için adresi döndürülebilir.
- Fonksiyon `void` bırakılır ve `head` çift işaretçiyle (`NODE **`) alınır; `*head = yeni_düğüm` gibi bir atamayla çağıranın `head`'i doğrudan güncellenir.

Hoca global değişken kullanılmasını hiçbir zaman istemeyeceğini söyledi. Bir sonraki uygulamada bağlı liste kodundaki `insert_at_begin` fonksiyonuna veriyle birlikte `head` de gönderilecek ve `head` değiştiği için çift işaretçiyle gönderilecek; bu, employee örneğiyle birleştirilecek.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:22:02): Bağlı listede aranan değere göre düğüm silen fonksiyonu yazın. Fonksiyon bir `n` değeri alır, `next` yerine veri üzerinden arama yapar ve bulduğu düğümden önceki düğümü sonraki düğüme bağlar. Aranan eleman ilk elemansa ne olacağını düşünün.

> **Çözüm (derste verilmedi):** Ajanın yazdığı çözüm aşağıdadır. Bölüm 1'deki global `head` ile çalışır. `gcc -Wall` ile derlendi; 9-7-3-2 listesinde 3, 9 ve 2 sırayla silindi, olmayan 5 için "not found" yazıldı.
>
> ```c
> void delete_by_value(int d){
>     NODE *tmp=head, *u=NULL;
>     if(head==NULL){ printf("List is empty\n"); return; }
>     while(tmp!=NULL && tmp->data!=d){ u=tmp; tmp=tmp->next; }
>     if(tmp==NULL){ printf("%d not found\n",d); return; }
>     if(u==NULL) head=tmp->next;      /* aranan ilk eleman */
>     else u->next=tmp->next;          /* önceki düğümü sonrakine bağla */
>     free(tmp);
>     printf("%d was deleted\n",d);
> }
> ```

**Soru 2** (derste sözlü, 00:24:05): Baştan silmede `tmp` kullanmak yerine doğrudan `head = head->next` yazılabilir mi?

> **Çözüm:** Derste verilen cevap: yalnız `head`'i ilerletmek için yazılabilir, ama ilk düğüm `free` edilecekse olmaz. `head` ilerletildikten sonra ilk düğümün adresi kaybolur; bu yüzden ikinci düğümün adresi önce `tmp`'de saklanır, sonra ilk düğüm bırakılır.

**Soru 3** (derste sözlü, 00:36:28): Polinom toplamada ara dizi `res` neden üsleri tutmuyor, yalnız katsayıları tutuyor?

> **Çözüm:** Derste verilen cevap: üsler dizinin indisleridir. $3x^7 + 4x^2$ ile $5x^5 + 3x^3 - 2x^2$ için `max` $= 8$ olur, 0-7 indisli dizi açılır; `res[i]` $x^i$ teriminin katsayısıdır.

**Soru 4** (derste sözlü, 00:48:13): `int r:5; int i:3;` alanlarına `scanf` ile doğrudan okunabilir mi?

> **Çözüm:** Derste verilen cevap: okunamaz; bit alanının adresi alınamaz ve `scanf("%d", &s.i)` derleme hatası verir. Değer geçici bir `x` değişkenine okunur, `if (x >= 0 && x < 32)` ile aralık kontrol edilir ve `s[4].r = x;` ile atanır.

**Soru 5** (ekrandan, 01:35:00): Slaytta ev alıştırması olarak bırakılan Fibonacci sayılarını ($F_{n+1} = F_n + F_{n-1}$) özyinelemeli bir fonksiyonla hesaplayın.

> **Çözüm (derste verilmedi):** Temel durumlar $F_0 = 0$ ve $F_1 = 1$ alınarak ajanın yazdığı çözüm aşağıdadır. `gcc -Wall` ile derlendi; 0'dan 10'a kadar çıktı `0 1 1 2 3 5 8 13 21 34 55` oldu.
>
> ```c
> #include <stdio.h>
> int fib(int n) {
>     if (n <= 1)
>         return n;          /* temel durumlar: F(0)=0, F(1)=1 */
>     return fib(n - 1) + fib(n - 2);
> }
> int main(void) {
>     int i;
>     for (i = 0; i <= 10; i++)
>         printf("%d ", fib(i));
>     printf("\n");
>     return 0;
> }
> ```

**Soru 6** (ekrandan, 02:05:00, 02:15:00): Bölüm 11'deki Senaryo 1 ve Senaryo 2'yi adres adres elle izleyin. Fonksiyondan dönünce `main`'de `*h` ve `*hh` kaç olur, neden?

> **Çözüm:** Derste verilen çözüm: Senaryo 1'de `*h` 22 kalır. `my_func`'a `h`'nin değeri kopyalanır; fonksiyon yalnız yerel `p`'yi yeni alana yönlendirir, `main`'deki `h` değişmez. Senaryo 2'de `*hh` 999 olur. `my_func_2`'ye `hh`'nin adresi gönderilir ve `*p = z` ile `hh`'nin içeriği yeni alanın adresiyle değiştirilir.

## Dersin Toparlaması

Ders, bağlı listede baştan ve sondan silmeyle başladı. Bir düğümü `free` etmeden önce ona bağlı adreslerin saklanması gerektiği, tek yönlü listede sondan silmek için bir önceki düğümün ayrıca tutulması gerektiği görüldü. Ardından polinom örneğiyle iç içe struct ve dinamik dizi kullanımı, fonksiyondan dinamik bellekte oluşturulmuş bir struct'ın adresini döndürme, oyuncu verimi örneğiyle de struct'ın değer olarak kopyalanıp döndürülmesi tekrar edildi. Slaytlarda struct hizalaması ve boşluklar, bellek tasarrufu için bit alanları (adresinin alınamaması, dizisinin kurulamaması, yerleşimin derleyiciye bağlı olması) ve bütün üyelerin aynı alanı paylaştığı union işlendi.

İkinci bölümde özyineleme, fonksiyon çağrılarının yığını nasıl kullandığı üzerinden anlatıldı; durma koşulunun neden zorunlu olduğu ve faktöriyelin adım adım hesaplanması görüldü. Fonksiyon işaretçileriyle tek bir sıralama fonksiyonunun hem artan hem azalan sıralama yapabildiği, fonksiyon işaretçisi dizileri, `void *` ile tür dönüşümü ve `malloc`'un `void *` döndürmesi, işaretçi üyeli struct'larda atamanın derin kopya olmadığı ve `realloc` ile dinamik metin okuma ele alındı. Ders, tek ve çift işaretçiyle parametre geçirmenin farkıyla bitti. Bu fark sonraki uygulamada bağlı listedeki `head`'i global değişken yerine çift işaretçiyle ya da dönüş değeriyle yönetmek için kullanılacak. Hoca gelecek derste dosya işlemlerinin (file I/O) tamamlanacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
