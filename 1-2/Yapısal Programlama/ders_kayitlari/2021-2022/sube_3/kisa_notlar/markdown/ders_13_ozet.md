# Ders 13 Çalışma Özeti

## Genel Konular

- Özyinelemeli (recursive) fonksiyonla string'i tersten yazdırma
  - Fonksiyon, gösterilen karakter `'\0'` değilse önce kendini `str+1` ile çağırır, dönüşte karakteri yazar. Böylece `"Dene"` için çıktı `eneD` olur (derlendi, çalıştırıldı).
  - Her çağrı yığına (stack) bir çerçeve olarak eklenir: `main`, `R("Dene")`, `R("ene")`, `R("ne")`, `R("e")`, `R("")` (ekrandan, 00:10:00). En içteki çağrıda koşul yanlış olunca fonksiyon biter ve yığından geri dönülerek karakterler sondan başa yazılır.
  - Faktöriyel gibi özyinelemeli fonksiyonlar da önce en alt seviyeyi (`f(1)`) hesaplar, sonuçları geri dönerken birleştirir. Özyinelemeli bir fonksiyonu izlemenin en doğru yolu yığını çizmektir.
  - Özyineleme yığını kendiliğinden kullandığı için, ayrık matematikte açık bir yığınla yazılan DFS algoritması özyinelemeli olarak yığın kullanmadan yazılabilir.
- İkili arama ağacı (binary search tree, BST)
  - İkili ağaçta her düğümün en çok iki çocuğu vardır. İkili arama ağacında ek olarak sol alt ağaçtaki değerler kökten küçük, sağ alt ağaçtaki değerler kökten büyüktür.
  - Ağaç dizi ile de tutulabilir: `i` indisli düğümün sol çocuğu `2i+1`, sağ çocuğu `2i+2`, atası $\lfloor (i-1)/2 \rfloor$ indisindedir. Boş düğümler dizide boş yer bırakır; bu, dizi gösteriminin dezavantajıdır.
  - Derste ağaç bağlı liste mantığıyla, `malloc` ile oluşturulan düğümlerle kuruldu: `typedef struct TreeNode { int data; struct TreeNode *left, *right; } NODE;`
  - `createNode(int N)`: `malloc(sizeof(NODE))` ile yer açar, `data`'yı atar, `left` ve `right`'ı `NULL` yapar (ekrandan, 00:30:00).
  - İteratif ekleme: `tmp` ile kökten başlanıp yeni değer büyükse sağa, değilse sola gidilir; `tmp2` bir önceki düğümü takip eder. `tmp` `NULL` olunca yeni düğüm `tmp2`'nin uygun çocuğuna bağlanır. Ağaç boşsa yeni düğüm kök olur.
  - Özyinelemeli ekleme (`insertR`): kök `NULL` ise düğüm oluşturulup döndürülür; değilse `root->right = insertR(root->right, data)` ya da `root->left = insertR(root->left, data)` çağrılır, sonunda `root` döndürülür (ekrandan, 00:50:00).
  - Kök yalnız ilk eklemede değişir; bu yüzden `root = insert(root, N)` biçiminde dönen değer atanır. Alternatif, kökün adresini (çift işaretçi) göndermektir.
  - Bu tür BST'de ilk gelen eleman kök olur ve bir daha değişmez; ağaç dengelenmez.
- Ağaçta gezinme (traversal)
  - Pre-order: kök, sol, sağ. In-order: sol, kök, sağ. Post-order: sol, sağ, kök. Reverse post-order: sağ, sol, kök (pek kullanılmaz). Level-order: seviye seviye, soldan sağa.
  - `a + b` ifade ağacında pre-order `+ a b`, in-order `a + b`, post-order `a b +` verir.
  - Pre-order ile level-order her zaman aynı değildir: 1-7 numaralı tam ağaçta level-order `1 2 3 4 5 6 7`, pre-order `1 2 4 5 3 6 7`'dir.
  - Gezinme fonksiyonları özyinelemeli olarak 3-4 satırda yazılır; iteratif yazmak, gidilen yerleri saklamak için ek değişkenler gerektirdiğinden zordur.
  - 5, 3, 8, 1, 4, 6, 9 sırasıyla girilen ağaçta in-order `1 3 4 5 6 8 9`, pre-order `5 3 1 4 8 6 9`, post-order `1 4 3 6 9 8 5` çıkar (ekrandan, 01:10:00).
- BST'de arama karmaşıklığı ve denge
  - Ağaç dengeliyse arama $O(\log n)$ sürer. Değerler sıralı girilirse (1, 2, 3, 4, 5) ağaç bağlı listeye döner, yükseklik $n$ olur ve en kötü durumda $n$ karşılaştırma gerekir.
- BST'den düğüm silme (görselleştirme aracıyla)
  - Silinecek düğüm önce aranarak bulunur. İki çocuklu bir düğüm silinirken yerine sol alt ağacın en büyüğü ya da sağ alt ağacın en küçüğü getirilir; böylece arama ağacı özelliği bozulmaz.
- Dosyadan yapıya okuma: nokta ve ok operatörü
  - Metin dosyasında ad, soyad, numara alanları vardır; dosya nasıl yazıldıysa öyle okunur: `fscanf(fp, "%s %s %d\n", ...)`.
  - Yapı dizisine nokta ile (`kisi[i].ad`) ya da işaretçi ve ok ile (`person->ad`, ardından `person++`) okunabilir. Ok ile okumada işaretçi aritmetiği arka planda adresleri ilerletir.
  - String alanların adı zaten adres olduğu için `&` gerekmez; `int` alan için `&` gerekir.
- Thread'lere giriş
  - Bir program çalıştığında süreç (process) olur ve normalde tek bir yürütme akışı (execution flow) vardır.
  - Thread, bir sürecin içinde aynı bellek alanını paylaşan birden fazla yürütme akışıdır. Süreç oluşturmak (`fork`) daha maliyetlidir.
  - Tek çekirdekte akışlar arasında hızlı bağlam değiştirme (context switching) yapılır; çok çekirdekte gerçekten eş zamanlı çalışabilirler. Thread'ler arası geçiş süreçler arası geçişten hızlıdır.
  - Ortak kaynağa (örnek: banka hesabı) erişimde senkronizasyon gerekir. Hatalı senkronizasyon açlık (starvation) ve kilitlenme (deadlock) doğurabilir.
  - `pthread.h`: `pthread_create`, `pthread_self`, `pthread_equal`, `pthread_exit`, `pthread_join`. Derlemede pthread kütüphanesi bağlanmalıdır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Özyinelemeli bir fonksiyonu anlamanın yolu yığını çizmektir
  - Her çağrının hangi satırdan yapıldığı yığında saklanır; fonksiyon bitince yığından çekilerek kalınan yere dönülür.
- Özyinelemeli düşünmek yazmaktan zordur
  - `insertR` kısa yazılır, ama her alt çağrıyı bir alt ağacın kökü gibi düşünmek gerekir. Durma koşulu `root == NULL` durumudur.
- `root->right = insertR(...)` atamasında sol taraf `root` değil, `root->right` olmalıdır; `root`'a atanırsa kök bozulur.
- Gezinme fonksiyonlarını kopyalayıp düzenlerken içerideki özyinelemeli çağrıların adını değiştirmeyi unutmak hatalı çıktı verir.
  - Derste `preOrder` ve `postOrder` içinde `inOrder` çağrıları kaldığı için önce yanlış sıralar görüldü, düzeltilince doğru sıralar alındı.
- BST dengesizleşebilir; en kötü durumda arama doğrusal olur.
- Thread ile çalışan fonksiyon `void *` parametre alır ve `void *` döndürür; böylece thread'den her türlü değer geri alınabilir.
- `sleep` ile beklemek yerine `pthread_join` kullanılmalıdır; `main` biterse program biter ve bitmemiş thread'ler öldürülür.
- Thread'ler işletim sistemleri dersinde ve gömülü sistem, sistem programlama uygulamalarında sık kullanılır; mantığını şimdiden öğrenmek yararlıdır.

## Kısa Tekrar Notları

- Özyinelemeli tersine yazdırma: `if(*str){ reverse(str+1); printf("%c", *str); }`.
- BST: sol < kök < sağ. Ekleme iteratif (`tmp`, `tmp2`) ya da özyinelemeli (`insertR`) yazılır.
- In-order gezinme BST'yi küçükten büyüğe sıralı verir.
- Pre-order: kök-sol-sağ; in-order: sol-kök-sağ; post-order: sol-sağ-kök.
- Dizi gösteriminde çocuklar `2i+1`, `2i+2`; ata $\lfloor (i-1)/2 \rfloor$.
- Dengeli BST'de arama $O(\log n)$, sıralı girişle oluşan "bağlı liste" ağaçta $O(n)$.
- İki çocuklu düğüm silinirken yerine sol alt ağacın en büyüğü ya da sağ alt ağacın en küçüğü gelir.
- Thread: süreç içindeki yürütme akışı; aynı belleği paylaşır.
- `pthread_create(&tid, NULL, fonksiyon, arg)` başarıda 0 döndürür.
- `pthread_equal` ile thread kimlikleri karşılaştırılır, `==` ile değil.
- `pthread_exit(&deger)` ile thread'den değer döndürülür, `pthread_join(tid, (void**)&ptr)` ile alınır.
- Uygulama: `isReachable` özyinelemeli yol kontrolü; dosyadan `fgets` + `strtok` + `atoi` ile bağlı listeye okuma; fonksiyon işaretçili özyinelemeli sıralama; `fprintf` ile yeni dosyaya yazma.

## Detaylı Açıklamalar

- **Özyinelemeli string ters çevirme.** `reverse(char *str)` fonksiyonu, `*str` boş karakter değilse önce `reverse(str+1)` ile kendini çağırır, ardından `printf("%c", *str)` ile karakteri yazar. `"Dene"` için çağrılar `R("Dene")`, `R("ene")`, `R("ne")`, `R("e")`, `R("")` sırasıyla yığına eklenir (ekrandan, 00:10:00). `R("")` içinde koşul yanlış olduğundan hiçbir şey yapılmadan dönülür; sonra sırasıyla `e`, `n`, `e`, `D` yazılır ve çıktı `eneD` olur. Program `gcc -Wall` ile derlenip çalıştırıldı.

- **İkili arama ağacı yapısı ve ekleme.** Düğüm yapısı bir `data` alanı ile `left` ve `right` işaretçilerinden oluşur. `data` yerine bir öğrenci ya da ders yapısı da tutulabilir. `createNode` fonksiyonu (ekrandan, 00:30:00):

```c
NODE* createNode(int N){
    NODE *ptr= (NODE*)malloc(sizeof(NODE));
    ptr->data = N;
    ptr->left=ptr->right=NULL;
    return ptr;
}
```

  Özyinelemeli ekleme ekrandan (00:50:00):

```c
NODE* insertR(NODE *root, int data){
    if(root==NULL){
        root=createNode(data);
        return root;
    }
    else if( data > root->data){
        root->right = insertR(root->right,data);
    }
    else{
        root->left = insertR(root->left, data);
    }
    return root;
}
```

  Bu fonksiyonun son satırındaki `return root;` derste "en alta bir return yazabiliriz" diye söylendi; kare yazım anındadır. İteratif `insert` fonksiyonu ise ekranda bütün olarak görünmedi; altyazıya göre yapısı şöyledir: yeni düğüm oluşturulur, kök `NULL` ise yeni düğüm döndürülür; değilse `tmp = root`, `tmp2 = NULL` ile başlanır, `tmp` `NULL` olana kadar `tmp2 = tmp` yapılıp değer büyükse sağa, değilse sola gidilir; döngü bitince `tmp2`'nin sağına ya da soluna yeni düğüm bağlanır ve `root` döndürülür. Derste karşılaştırma önce ters yazıldığı için 6'dan sonra eklenen 9 sola düştü; "veri büyükse sağa" olarak düzeltildi. <!-- BELİRSİZ: iteratif insert kodunun tam metni karelerde görünmüyor; yapı altyazıdan kuruldu ve ajan tarafından derlenip test edildi. -->

- **Gezinmeler.** In-order fonksiyonu ekrandan (00:40:00):

```c
void inOrder(NODE* root){//a + b
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
```

  Pre-order'da `printf` başa, post-order'da sona alınır. 5, 3, 8, 1, 4, 6, 9 değerleri girilince (0 çıkış için) program `1 3 4 5 6 8 9`, `5 3 1 4 8 6 9` ve `1 4 3 6 9 8 5` çıktılarını verdi (ekrandan, 01:10:00). Ajan aynı ağacı kurup üç gezinmeyi derleyip çalıştırdı; aynı sonuçlar alındı. İteratif eklemeyle 6, 9, 3, 4, 2, 15, 8 girildiğinde in-order `2 3 4 6 8 9 15` olur (ekrandaki tahta, 00:45:00; ajan tarafından doğrulandı).

- **Denge ve karmaşıklık.** Arama her adımda bir alt ağacı eler; dengeli ağaçta yükseklik yaklaşık $\log n$ olduğundan arama $O(\log n)$'dir. Sıralı girişte her düğüm bir öncekinin sağ çocuğu olur ve ağaç bağlı liste gibi olur; yükseklik $n$'dir. Ders sırasında bir öğrenci dengeli ağaç tanımını sordu. Hoca, denge kavramının ikili ağaçlar için konuşulduğunu ve bu "bağlı liste" biçimli ağacın dengesiz olduğunu söyledi. Ağaç yüksekliği $h$ iken yaprakların $h$ ya da $h-1$ seviyesinde olması tanımı da okundu; bu tanımın en kötü durumu açıkça kapsamadığı tartışıldı ve hoca tanımı araştırıp paylaşacağını söyledi.

- **Silme.** Görselleştirme aracında (cs.usfca.edu BST animasyonu) 5, 3, 8, 1, 4, 6, 9 ağacı kuruldu. İki çocuklu düğüm silindiğinde araç, yerine silinen düğümün sol alt ağacındaki en büyük değeri getirdi. Kök (5) silinirken solun en büyüğü (4) ya da sağın en küçüğü (6) getirilebilir; iki durumda da sol taraf küçük, sağ taraf büyük kalır. Araçta eşit değerin sola eklendiği görüldü.

- **Dosyadan yapıya okuma.** Dosyada her satırda ad, soyad ve numara vardır. Yapı (ad, soyad, numara) tanımlanır, beş kişilik bir dizi kullanılır. Nokta ile okumada dizi elemanının alanlarına, ok ile okumada `person` işaretçisinin alanlarına `fscanf` ile okunur ve her kayıttan sonra `person++` yapılır. Programda `"Ok ile okumak icin 1 nokta ile okumak icin 2"` seçimi sorulur (ekrandan, 01:25:00). Derste bir `printf` biçim dizgisinde eksik `%d` bulunup düzeltildi. <!-- BELİRSİZ: ReadFile örneğinin kodu karelerde tam görünmüyor; ayrıntılar altyazıdan alındı. -->

- **Thread'ler.** Normal fonksiyon çağrısında akış fonksiyona gider ve bitince geri döner; programın tek bir akışı vardır. Thread ile akış ikiye ayrılır ve iki parça eş zamanlı ilerler. Örnek olarak kelime işlemcide yazarken yazım hatası denetiminin aynı anda çalışması ve tarayıcı sekmeleri verildi. Görev yöneticisinde bir programın altında birden çok thread görüldü. Senkronizasyon sorunları için banka hesabı (aynı anda para çekme ve yatırma), açlık için "mikrofon size hiç gelmiyor" benzetmesi, kilitlenme için kavşakta birbirine giren araçlar örneği verildi: süreç A, B'nin tuttuğu kaynağı; B de A'nın tuttuğu kaynağı bekler. Thread'lerle ilgili sorunlar slaytında (ekrandan, 01:40:00) thread içinden `exec` yapılmasının bütün süreci değiştirebileceği, hata ayıklamanın zor olduğu ve çok fazla thread'in performansı düşürebileceği yazıyordu.

- **`pthread_exit` ve `pthread_join` örneği.** Slayttaki kod (ekrandan, 01:55:00):

```c
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
pthread_t tid[2];
int ret1,ret2;
void* doSomeThing(void *arg) {
    unsigned long i = 0;
    pthread_t id = pthread_self();
    for(i=0; i<(0xFFFFFFFF);i++);
    if(pthread_equal(id,tid[0])) {
        printf("\n 1st thread processing done\n");
        ret1 = 100;
        pthread_exit(&ret1);
    }
    else {
        printf("\n 2nd thread processing done\n");
        ret2 = 200;
        pthread_exit(&ret2);
    }
    return NULL;
}
int main(void)
{
    int i = 0, err;
    int *ptr[2];
    while(i < 2) {
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        else
            printf("\n Thread created successfully\n");
        i++;
    }
    pthread_join(tid[0], (void**)&(ptr[0]));
    pthread_join(tid[1], (void**)&(ptr[1]));
    printf("\n return value from first thread is %d\n", *ptr[0]);
    printf("\n return value from second thread is %d\n", *ptr[1]);
    return 0;
}
```

  Boş `for` döngüsü yalnız gecikme içindir. Ajan bu kodu `gcc -Wall -pthread` ile derleyip çalıştırdı (gecikme sayacı kısaltılarak); dönüş değerleri 100 ve 200 olarak alındı. Thread'lerin hangi sırayla bittiği her çalıştırmada değişebilir.

- **Uygulama: özyinelemeli yol kontrolü.** A(2, 2) noktasından yalnız sağa ya da yukarı birer birim giderek hedefe ulaşılıp ulaşılamayacağı kontrol edilir (ekrandan, 02:30:00):

```c
int isReachable(int Ax, int Ay, int Bx, int By){
    // base case
    if(Ax > Bx || Ay > By)
        return 0;
    // Ax = Bx, Ay = By;
    if(Ax == Bx && Ay == By)
        return 1;
    // continue to check
    return (isReachable(Ax+1, Ay, Bx, By) || isReachable(Ax, Ay+1, Bx, By));
}
```

  Son satırın parantez içi ekranda yazılırken görülmedi; altyazıya göre x'i ya da y'yi bir artırarak iki seçenekli çağrıdır. A'dan B(5, 7)'ye yol vardır; C(-2, 7)'ye ve D(7, 9)'dan B'ye yol yoktur. Ajan programı derleyip bu sonuçları doğruladı.

- **Uygulama: dosyadaki kayıtları bağlı listede sıralama.** `Dataset.txt` dosyasında `ID,isim,bölüm` biçiminde satırlar vardır. Yapı `typedef struct DATA { int ID; char Name[50]; char department[20]; struct DATA *next; } data;` biçimindedir (ekrandan, 02:50:00). `File_Read` her satırı `fgets(buf, 255, fp)` ile okur, `malloc` ile düğüm açar, `prev_data->next = curr_data` ile listeye ekler ve `Split_Data` ile satırı parçalar (ekrandan, 03:00:00). `Split_Data` içinde `strtok(buff, delimeter)` ilk parçayı, sonraki `strtok(NULL, delimeter)` çağrıları aynı tampondan devam eden parçaları verir; `atoi` string'i tamsayıya çevirir, `strcpy` ile isim ve bölüm kopyalanır. `Sort_Data(data* head, int (*Sort_Condition)(int, int))` kalan listedeki en büyük (ya da en küçük) elemanı bulur, listeden çıkarır, sıralı kısmın başına koyar ve geri kalanı özyinelemeli sıralar (ekrandan, 03:10:00 ve 03:15:00). `File_Write` dosyayı `"w"` kipinde açıp her düğümü bir satır olarak yazar.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
