# Ders 15 Çalışma Özeti

## Genel Konular

- Oturumun yapısı
  - Kısa bir oturumdur (yaklaşık bir saat). Önce bir sınav sorusu (N karmaşık sayıyı $N \times 2$ dinamik `int` matriste saklama) Dev-C++ ortamında baştan sona kodlandı. Sonra aynı problem `struct` ile yeniden çözülerek yapılara (struct) giriş yapıldı.
  - Ortak tema, dinamik bellek ayırmanın (`malloc`, `free`) fonksiyonlarla birlikte kullanılmasıdır.
- Soru: Karmaşık sayılar ve dinamik matris (ekrandan, 00:55:00)
  - Kullanıcıdan alınan N sayısına göre N karmaşık sayının reel ve sanal kısmı $N \times 2$ boyutlu dinamik bir `int` matriste saklanır. Bilgi girişi `main` içinde yapılır.
  - (a) `enbuyuk_bul`: matrisi parametre alır, reel ve sanal kısımların kareleri toplamı en büyük olan sayının kaçıncı satırda olduğunu bulup döndürür.
  - (b) `liste_yazdir`: her sayıyı `a + bi` biçiminde alt alta yazar (örnek çıktı: `2 + 3i`, `5 - 2i`, ..., `7 + 4i`).
  - Fonksiyonların dönüş türü soruda boş bırakılmıştı; öğrencinin kendisinin çıkarması isteniyordu.
- Dinamik matrisin kurulması (ekrandan, 00:10:00, 00:15:00)
  - `int **matris;` tanımlanır. Önce N tane satır işaretçisi için `matris = (int **) malloc(N*sizeof(int*));` ile yer ayrılır.
  - Sonra döngüyle her satıra iki sütunluk yer açılır: `matris[i] = (int*)malloc(2*sizeof(int));`
  - `matris[i][0]` reel kısım, `matris[i][1]` sanal kısım olarak okunur: `scanf("%d", &matris[i][0]);`. Köşeli parantezle erişimde işaretçi aritmetiği gerekmez, ama `scanf` adres istediği için `&` yazılır.
- `liste_yazdir` fonksiyonu (ekrandan, 00:20:00)
  - Prototip: `void liste_yazdir(int **matris, int N)`. Yalnız yazdıran ve bir şey döndürmeyen fonksiyonun türü `void` olmalıdır.
  - Önce reel kısım yazılır. Sanal kısım 0 ise yazılmaz. Sıfırdan büyükse `" + "`, küçükse `" - "` yazılır, ardından sanal kısmın mutlak değeri `abs(...)` ve `i` harfi basılır. Böylece `3 - -2i` gibi çift eksi önlenir.
- `enbuyuk_bul` fonksiyonu (ekrandan, 00:25:00)
  - Prototip: `int enbuyuk_bul(int **matris, int N)`. `maxI = 0` ile başlar; her satır için $a^2 + b^2$ değeri `tmp`, o ana kadarki en büyüğün değeri `tmp2` olarak hesaplanır; `tmp > tmp2` ise `maxI = i` yapılır. Sonunda `maxI` döndürülür.
  - Karşılaştırma kareler üzerinden yapıldığı için karekök almak gerekmez.
  - Deneme: girdi $2+2i$, $4+4i$, $3-2i$, $1+7i$; çıktı "En buyuk deger = 3. satirdadir" (ekrandan, 00:30:00). Kareler toplamı sırasıyla 8, 32, 13, 50'dir.
- Belleğin bırakılması (ekrandan, 00:25:00)
  - Önce döngüyle her satır `free(matris[i])`, sonra işaretçi dizisi `free(matris)` ile bırakılır.
- Yapılara (struct) giriş (ekrandan, 00:35:00)
  - `typedef struct complex { int reel; int sanal; } CMP;` Bu bir değişken tanımı değil, bir tür (yapı) tanımıdır. `typedef` ile `struct complex` adı `CMP` diye kısaltılır.
  - `int` ile yapılabilen her tanım `CMP` ile de yapılabilir: tek değişken (`CMP c0;`), işaretçi (`CMP *c1`), işaretçinin işaretçisi (`CMP **c2`), statik dizi (`CMP C3[10];`), `malloc` ile dinamik dizi.
  - Dinamik dizi: `c1 = (CMP*)malloc(N*sizeof(CMP));` Uzun yazımı: `(struct complex*)malloc(N*sizeof(struct complex))`.
  - Alanlara nokta operatörüyle erişilir: `scanf("%d", &c1[i].reel);`. Ok (`->`) operatörü gibi diğer yollar sonraki derse bırakıldı.
- Struct dizisini fonksiyona göndermek (ekrandan, 00:40:00, 00:45:00)
  - `int enbuyuk_bul2(CMP *c, int n)`: aynı algoritma `pow(c[i].reel,2) + pow(c[i].sanal,2)` ile yazıldı. `pow` için `math.h` eklenmezse derleyici "incompatible implicit declaration of built-in function 'pow'" uyarısı verir.
  - Prototip `typedef`'ten sonra yazılmalıdır; tür tanımlanmadan prototipte kullanılamaz.
  - Dönen indisle `main` içinde `c1[i].reel` ve `c1[i].sanal` doğrudan yazdırılabilir.
- Fonksiyondan struct döndürmek (ekrandan, 00:50:00)
  - `CMP enbuyuk_bul3(CMP *c, int n)`: en büyüğün indisi bulunur, yerel `CMP c2;` değişkenine alanlar kopyalanır ve `return c2;` yapılır. `main` içinde `c0 = enbuyuk_bul3(c1, N);`.
  - Debug ve `%p` ile `&c0` ve `&c2` adreslerinin farklı olduğu gösterildi: dönüş değeri değerle (call by value) `c0`'a kopyalanır.
  - Uyarı: Fonksiyon içinde statik tanımlanan bir dizinin adresi döndürülürse bu güvenli değildir; fonksiyon bitince stack'teki o alan serbest kalır ve değerler bozulabilir. Konu sonraki derslere bırakıldı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sorudaki kurala uymak
  - $N \times 2$ dinamik matris istendiyse tek boyutlu dizi ya da iki ayrı dizi kullanmak kural dışıdır. Benzetme: "markette pirinç isterken bulgur almak." Kural belirsizse sınav sırasında sorulmalıdır.
- C dosyası açmak
  - Kod `.c` dosyası olarak yazılmalı, C++'a ait yapılar kullanılmamalıdır.
- `free` zorunludur
  - "Bir şey allocation yapılıyorsa free etmek lazım." Programcı açısından zorunludur.
- `void` dönüş türü
  - Yalnız yazdıran bir fonksiyonun boş yere `int` döndürmesi yerine `void` yazılması gerekir; başarı/başarısızlık için 0/1 döndürmek ise anlaşılır bir tercihtir.
- Hazır fonksiyonlar
  - Aksi söylenmedikçe `abs`, `pow`, `strcmp` gibi hazır fonksiyonlar kullanılabilir.
- Diziyi 0'dan başlatmak
  - N elemanlı dizi için `n+1` yer ayırıp indisi 1'den başlatmak yanlıştır. Kullanıcıya 1'den saymak isteniyorsa yalnız yazdırırken `i+1` yazılmalıdır.
- Boyut parametre ile gönderilir
  - Dinamik dizinin boyutu `sizeof` ile fonksiyon içinde bulunamaz; N parametre olarak gönderilmelidir.

## Kısa Tekrar Notları

- 2B dinamik matris: `int **m = malloc(N*sizeof(int*));` sonra her satıra `malloc(2*sizeof(int))`.
- Bırakma ters sıradadır: önce satırlar, sonra işaretçi dizisi.
- `scanf` içinde `&matris[i][0]` ve `&c1[i].reel` yazılır.
- Karmaşık sayının büyüklüğü karşılaştırılırken $a^2 + b^2$ yeterlidir.
- `typedef struct complex {...} CMP;` ile kısa tür adı tanımlanır.
- Struct türünden değişken, işaretçi, statik ve dinamik dizi `int` gibi tanımlanır.
- Prototipler `typedef`'ten sonra gelir.
- Struct değerle döndürülürse alanları çağıran değişkene kopyalanır.
- Yerel (stack) dizinin adresini döndürmek tehlikelidir.

## Detaylı Açıklamalar

- Dinamik matrisin mantığı
  - $N \times 2$ matris, N elemanlı bir işaretçi dizisi ve her biri iki `int` tutan N ayrı dizi olarak kurulur. `matris` bir `int **`'dır, çünkü elemanları `int *` türündedir. `matris[i]` bir satırın adresidir, `matris[i][j]` o satırdaki elemandır. Problemin tek boyutlu diziyle de çözülebileceği belirtildi, ama soru açıkça iki boyutlu dinamik matris istediği için o yol kabul edilmez.
- Karmaşık sayının büyüklüğü
  - Bir öğrenci, $i^2 = -1$ olduğu için sanal kısmın karesinin eksi işaretli alınması gerekip gerekmediğini sordu. Cevap: Büyüklük hesaplanırken sayı iki boyutlu düzlemde bir vektör gibi düşünülür. $3 + 4i$ için reel eksende 3, sanal eksende 4 uzunluğunda iki dik kenar vardır; büyüklük hipotenüstür: $\sqrt{3^2 + 4^2} = 5$. Bu yüzden iki karenin toplamı alınır; $i$ yalnız iki bileşeni ayırt etmek için kullanılan bir gösterimdir. Programda sanal kısım da sıradan bir `int` olarak saklanır.
  - Toplama ya da çarpma istenseydi sanal kısmı ilgili cebir kurallarına göre işlemek gerekirdi; bu soruda yalnız kareler alınır.
- `liste_yazdir` kodu (ekrandan, 00:20:00)

```c
void liste_yazdir(int **matris, int N){
    int i;
    for(i=0;i<N;i++){
        printf("%d -> %d",i,matris[i][0]);
        if(matris[i][1]!=0){
            if(matris[i][1]>0){
                printf(" + ");
            }
            else {
                printf(" - ");
            }
            printf("%di\n",abs(matris[i][1]));
        }
        printf("\n");
    }
}
```

- Ders sonrası not: Bu kodda sanal kısım sıfırdan farklıyken hem `"%di\n"` hem de döngü sonundaki `printf("\n")` çalışır; bu yüzden ekrandaki çıktıda satırlar arasında boş satır oluşmuştur (ekrandan, 00:30:00). Boş satır istenmiyorsa `"%di"` yazmak yeterlidir.
- `enbuyuk_bul` kodu (ekrandan, 00:25:00; dönüş satırı altyazıdan)

```c
int enbuyuk_bul(int **matris, int N){
    int i, maxI=0, tmp=0, tmp2=0;
    for(i=0;i<N;i++){
        tmp=matris[i][0]*matris[i][0] + matris[i][1]*matris[i][1];
        tmp2=matris[maxI][0]*matris[maxI][0] + matris[maxI][1]*matris[maxI][1];
        if(tmp>tmp2){
            maxI=i;
        }
    }
    return maxI;
}
```

- Tam program `main`, `liste_yazdir` ve `enbuyuk_bul` ile birlikte `gcc -Wall` ile derlendi ve ekrandaki girdiyle (4; 2 2, 4 4, 3 -2, 1 7) çalıştırıldı; çıktı ekrandakiyle aynıdır ("En buyuk deger = 3. satirdadir"). Kullanılmayan `j` değişkeni için yalnız bir uyarı verir. Fonksiyon prototiplerinin `main`'den önce yazılması gerekir.
- Struct ile aynı problem
  - `CMP *c1` dinamik dizisinde her eleman bir yapıdır; `c1[i].reel` ve `c1[i].sanal` alanlarına nokta ile erişilir. `c1` işaretçisi stack'te durur, gösterdiği alan heap'tedir; `free(c1)` ile bu alanın tamamı bırakılır. Bir `int` dizisi fonksiyona nasıl gönderiliyorsa struct dizisi de öyle, adıyla gönderilir.
- Struct döndüren fonksiyon (ekrandan, 00:50:00)

```c
CMP enbuyuk_bul3(CMP *c,int n){
    int i, maxI=0, tmp=0, tmp2=0;
    CMP c2;
    for(i=0;i<N;i++){
        tmp=pow(c[i].reel,2)+pow(c[i].sanal,2);
        tmp2=pow(c[maxI].reel,2)+pow(c[maxI].sanal,2);
        if(tmp>tmp2){
            maxI=i;
        }
    }
    printf("%p",&c2);
    c2.reel=c[maxI].reel;
    c2.sanal=c[maxI].sanal;
    return c2;
}
```

- Bu fonksiyon `N` 3 yapılarak $3+3i$, $2+2i$, $5+5i$ girdisiyle debug edildi; `c0` ve `c2`'nin ikisinde de `reel = 5`, `sanal = 5` görüldü (ekrandan, 00:50:00) ve adresleri farklı çıktı. Döngü sınırı parametre `n` yerine `#define` ile tanımlı `N` makrosunu kullanır. Program bu haliyle (`math.h` eklenerek) `gcc -Wall` ile derlendi ve aynı girdiyle $5 + 5i$ sonucunu verdi.
- Ders sonrası not: Hoca bu kopyalamayı "deep copy" diye adlandırdı. Struct'ın değerle döndürülmesi alan alan (üye üye) bir kopyadır; bu yapı yalnız `int` alanlar içerdiği için kopya eksiksizdir. Struct içinde işaretçi alan olsaydı, büyük olasılıkla yalnız adres kopyalanır, gösterilen veri kopyalanmazdı.
- Ders sonrası not: Hoca, fonksiyon bitince stack'teki alanı "başka programların" kullanabileceğini söyledi. Doğrusu büyük olasılıkla şudur: o alanı aynı programın sonraki fonksiyon çağrıları yeniden kullanır; bu yüzden yerel dizinin adresi üzerinden okunan değerler bozulabilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
