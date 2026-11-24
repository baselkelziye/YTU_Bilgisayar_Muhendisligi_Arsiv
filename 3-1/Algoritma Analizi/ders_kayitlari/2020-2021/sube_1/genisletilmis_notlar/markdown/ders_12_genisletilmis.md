# Ders 12 Genişletilmiş Notu: Birinci Ödevin Çözümü: Tek Boyutta En Yakın Çift ve Von Neumann Komşuluğu

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Oturumun amacı
- 2. Problem 1: tek boyutta birbirine en yakın iki eleman
- 3. Brute-force çözüm
- 4. Böl ve yönet çözümü
- 5. Quicksort ile merge sort karşılaştırması
- 6. Sıralamadan sonra tek döngü yaklaşımı
- 7. Problem 1'in C kodu
- 8. Problem 2: Von Neumann komşuluğu
- 9. Özyinelemeli ve yinelemeli çözüm
- 10. Problem 2'nin C kodu ve iki boyutlu dinamik bellek
- Örnek Sorular

## 1. Oturumun amacı

Bu oturum, birinci ödevdeki iki problemin birlikte çözüldüğü bir uygulama oturumudur. Algoritma analizi, programlamaya giriş, yapısal programlama ve veri yapılarından sonra gelen bir derstir; bu yüzden beklenen şey kodun söz dizimi değil, algoritmik düşüncenin kurulabilmesidir. Anlatım önce slaytlardaki sözde kod üzerinden, sonra C kodu üzerinden ilerledi.

## 2. Problem 1: tek boyutta birbirine en yakın iki eleman

Slayttaki soru şöyledir (ekrandan, 00:20:00):

- $N$ elemanlı bir dizide birbirine en yakın değere sahip iki elemanın bulunması isteniyor.
- (a) Problemi brute-force yaklaşımı ile çözen algoritmanın C dilinde kodunu yazıp verimliliğini analiz ediniz.
- (b) Problemi brute-force yaklaşımından daha az karmaşıklığa sahip başka bir algoritmik yöntem ile çözüp analiz ederek verimliliğini ortaya koyunuz. Yeni yaklaşımınızı C dilinde kodlayınız.

Sorudaki "$N$ elemanlı dizi" ifadesi problemin tek boyutlu olduğunu söyler. Elemanlar bir doğru üzerinde duran, $y$ koordinatı 0 olan noktalar gibi düşünülebilir. Noktalar doğru üzerinde karışık sırada dağılmıştır; örneğin $p_1$ noktası 5, $p_2$ noktası 3 olabilir. Slayttaki çizimde doğru üzerinde $p_1, p_2, p_3, q_3, q_1, q_2$ adlı noktalar vardır.

## 3. Brute-force çözüm

Brute-force (kaba kuvvet) yaklaşımı, hiçbir algoritmik fikre dayanmadan problemi en basit yoldan çözmektir. Bir öğrencinin anlattığı ve asistanın da gösterdiği çözüm aynıdır:

- $i = 0$'dan başlanır; her $i$ için $j = i+1$'den sona kadar bütün elemanlarla karşılaştırma yapılır.
- Minimum başlangıçta çok büyük bir değere kurulur (örneğin float'ın en büyük değeri). Böylece ilk karşılaştırılan fark minimum olur.
- Tek boyut olduğu için iki eleman arasındaki uzaklık mutlak değer farkıdır.
- Fark minimumdan küçükse minimum ve iki nokta ($p_1$, $p_2$) güncellenir.

İç içe iki döngü her çifti bir kez karşılaştırdığı için karmaşıklık $O(n^2)$'dir. C kodunda iki noktayı geri almak için fonksiyona birer işaretçi (pointer) gönderildi.

<!-- BELİRSİZ: brute-force sözde kodunun ve C kodunun tam metni karelerde görünmüyor; anlatım altyazıdan kuruldu. -->

## 4. Böl ve yönet çözümü

### 4.1 Fikir

(b) şıkkındaki kritik nokta yalnız diziyi sıralamak değil, bir böl ve yönet (divide and conquer) yaklaşımı geliştirmektir. Problem doğrudan çözülmek yerine alt problemlere ayrılır, alt problemler çözülür ve sonuçlar birleştirilir. Noktalar önce verimli bir sıralama algoritmasıyla sıralanır. Sonra orta nokta bulunur ve dizi sol ($S_1$) ve sağ ($S_2$) olmak üzere ikiye bölünür. Sol tarafta birbirine en yakın iki nokta, sağ tarafta da birbirine en yakın iki nokta bulunur.

### 4.2 İki yarıyı karşılaştırmak neden yetmez

Asistan şunu sordu: $S_1$'in en yakın çifti $\{p_1, p_2\}$, $S_2$'nin en yakın çifti $\{q_1, q_2\}$ olsun; bu ikisinden kısa olanı seçmek yeterli mi?

**Soru:** Bundan ne sıkıntı çıkar? **Cevap (bir öğrenci):** $p_3$ sol tarafta, $q_3$ sağ taraftadır. Yalnız yarıların içine bakılırsa $p_3$ ile $q_3$ hiç karşılaştırılmaz, oysa tüm diziye bakıldığında bu ikisi birbirine daha yakındır. Bölme bu karşılaştırmayı görünmez kılar.

Bu yüzden üç grup varmış gibi düşünülür: $\{p_1,p_2\}$, $\{q_1,q_2\}$ ve kesimin iki yanından gelen $\{p_3, q_3\}$ (ekrandan, 00:30:00). İki yarıdan gelen en küçük uzaklığa $d$ denir. Sonra orta noktanın solunda ve sağında $d$ uzaklık içinde nokta olup olmadığına bakılır; varsa onların uzaklıkları da karşılaştırılır.

### 4.3 Slayttaki adımlar

Slaytta $p < q$, $p \in S_1$ ve $q \in S_2$ olmak üzere şu adımlar verildi (ekrandan, 00:30:00):

1. $m = \text{median}(S)$
2. $S$, $m$ noktasında $S_1$ ve $S_2$'ye bölünür.
3. $\delta_1 = \text{Closest-Pair}(S_1)$
4. $\delta_2 = \text{Closest-Pair}(S_2)$
5. $\delta_{12}$, kesimin iki yanı arasındaki en küçük uzaklıktır.
6. $\delta = \min(\delta_1, \delta_2, \delta_{12})$ döndürülür.

Çizimde orta nokta $m$'nin iki yanında $d$ genişliğinde bir bant işaretlidir; $p_3$ ve $q_3$ bu bandın içindedir.

### 4.4 Sözde kod

Slayttaki sözde kod şöyledir (ekrandan, 00:35:00):

```text
Divide and Conquer Solution
inputs  <- P[n]
outputs <- p1, p2, min
begin
    qsort(P)
    function closestPoint(P)
        if size <= 3 then
            return bruteForce(P)
        end if
        mid = size/2
        midPoint = P[mid]
        dleft  = closestPoint(P, mid)
        dright = closestPoint(P + mid, size-mid)
        d = min(dl, dr)

        for i = 0 to size do
            if |P[i] - midPoint| < d then
                strip = P[i]   //within d dist
            end if
        min_strip = min(strip)
        return min(d, min_strip)
    end function
end
```

Anlatımın ayrıntıları:

- **Durma koşulu:** Eleman sayısı 3 ise orta eleman bir tarafa düşer, iki yanda birer eleman kalır; böl ve yönetin burada bir anlamı yoktur, çünkü soldaki ve sağdaki tek eleman neyle karşılaştırılacaktır? Bu yüzden boyut 3 veya daha azsa brute-force çalıştırılır ve en kısa mesafe döndürülür.
- **Bölme:** `mid = size/2` ile orta indis bulunur, `midPoint` o indisteki elemandır.
- **Özyineleme sırası:** Önce sol taraf için `closestPoint` çağrılır. Sol taraf yeniden orta noktasını bulur ve yeniden ikiye bölünür. Örneğin $p_1, p_2$ iki nokta kalınca brute-force çalışır; tek başına kalan $p_3$ için de çağrı yapılır. Sol tarafın tamamı bitince sağ tarafa geçilir ve aynı işlemler orada tekrarlanır.
- **Sağ yarı:** `P + mid` dizinin orta noktadan başlayan kısmını verir, `size - mid` de bu kısmın uzunluğudur. Böylece sol taraf atılmış, yalnız sağ taraftaki elemanlar alınmış olur.
- **Şerit:** $d = \min(d_{left}, d_{right})$ bulunduktan sonra bütün elemanlar taranır. Orta noktaya uzaklığı $d$'den az olan her eleman `strip` dizisine konur. Şeritteki elemanlar arasındaki en küçük uzaklık bulunur ve $d$ ile karşılaştırılarak küçüğü döndürülür.

> **Ders sonrası not:** Sözde kodda `dleft`/`dright` adlarıyla hesaplanan değerler `min(dl, dr)` satırında kısaltılmış adlarla kullanılmış; anlamı $d = \min(d_{left}, d_{right})$'dir. `strip = P[i]` satırı da elemanı şerit dizisine eklemek anlamındadır (C kodunda `strip[j] = P[i], j++`). Asistan bunun bir sözde kod olduğu için ayrıntıya girmeden yazıldığını belirtti.

## 5. Quicksort ile merge sort karşılaştırması

Sözde kodda sıralama için quicksort kullanıldı. Asistan quicksort'un bir dezavantajı olduğunu söyleyip sordu.

**Soru:** Quicksort'un dezavantajı nedir? **Cevap (bir öğrenci):** En kötü durumu $O(n^2)$'dir.

**Soru:** En kötü durum neden $O(n^2)$'dir? **Cevap:** Önemli olan pivot seçimidir. Pivotun ilk eleman seçildiğini ve dizinin sıralı olduğunu düşünelim, örneğin $1, 2, 3, 4$. Pivot 1 seçilir. Quicksort da böl ve yönet yaklaşımıyla diziyi alt problemlere bölerek çalışır; ama pivot dizinin en küçük (ya da en büyük) elemanı olursa dizi ikiye bölünemez ve en kötü durum $O(n^2)$ olur. Bu yüzden quicksort yerine merge sort seçilirse karmaşıklık daha garantili olur.

**Soru (bir öğrenci):** Merge sort'un $O(n)$ yer karmaşıklığı da var. Bunu düşününce yine quicksort'tan iyi mi? **Cevap:** Merge sort sürekli bölüp sonra birleştirdiği için bellek ihtiyacı yüksektir; bu doğrudur. İkisinin de birer dezavantajı vardır; dizi ya da bağlı liste kullanmak gibi seçenekler de avantaj ve dezavantaj getirir. Vurgu yalnız çalışma zamanı karmaşıklığı içindi. Kaynaklarda bu problem için ikisi de kullanılır; quicksort daha yaygındır.

> **Hocanın vurgusu:** Quicksort'ta karmaşıklığı belirleyen nokta pivot seçimidir.

## 6. Sıralamadan sonra tek döngü yaklaşımı

**Soru (bir öğrenci):** Dizi sıralandıktan sonra tek bir for döngüsüyle sonuç bulunamaz mı? Sıralı olduğu için $a_0$-$a_1$, $a_1$-$a_2$, $a_2$-$a_3$ gibi ardışık elemanlara bakmak yeter.

**Cevap:** Sıralı dizide birbirine en yakın iki eleman mutlaka ardışık iki elemandır. Birinci ile ikinci, ikinci ile üçüncü elemanlar karşılaştırıldığında gereken bütün karşılaştırmalar yapılmış olur; bu $n-1$ karşılaştırmadır ve $O(n)$ tutar. Sıralama $O(n \log n)$ olduğundan toplam $O(n \log n) + O(n) = O(n \log n)$'dir. Asistan, aynı karmaşıklığı verdiği için bu çözümün de kabul edileceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Tek boyutta en yakın çiftin her zaman sıralı dizide komşu iki eleman olması şu yüzdendir: $a_i < a_k < a_j$ ise $a_j - a_i$ farkı $a_k - a_i$'den de $a_j - a_k$'dan da büyüktür. Bu yüzden arada eleman bulunan bir çift hiçbir zaman en yakın çift olamaz.

## 7. Problem 1'in C kodu

Dev-C++'ta açılan kodda (ekrandan, 01:05:00):

```c
    float dr = closestUtil(P + mid, n-mid);

    float d = min(dl, dr);

    //Orta noktaya d uzakliginda olan noktalar
    int strip[n];
    int i,j = 0;
    for ( i = 0; i < n; i++)
        if (abs(P[i] - midPoint) < d)
            strip[j] = P[i], j++;

    return min(d, stripClosest(strip, j, d) );
}

float closest(int P[], int n){
    qsort(P, n, sizeof(int), cmpfunc);

    return closestUtil(P, n);
}

int main()
{
    //int P[] = {13,4,1, 7, 16, 8, 21, 11, 19, 12,23,26,32,34,49,46,52};
    int P[] = {9,5,0,20,35,1,11};
    int n = sizeof(P) / sizeof(P[0]);
    printf("The smallest distance is %f ", closest(P, n));
    return 0;
}
```

Bu bir kod parçasıdır; `closestUtil`'in baş kısmı, `stripClosest`, `min` ve `cmpfunc` ekranda görünmüyor, bu yüzden derlenmedi. Anlatıma göre:

- `closestUtil` eleman sayısı 3'ten azsa (sözde kodda $\le 3$) brute-force sonucunu döndürür; değilse orta noktayı `P[mid]` ile alır, önce sol, sonra sağ tarafı özyinelemeli çağırır ve küçüğünü seçer.
- Orta noktaya $d$ uzaklıktaki noktalar `strip` dizisine toplanır, aralarındaki en küçük uzaklık `stripClosest` fonksiyonunda bulunur. Tek boyutlu olduğu için yine mutlak değer farkı yeterlidir.
- Son olarak şeritteki uzaklık ile $d$'nin küçüğü döndürülür.
- `qsort` için iki elemanın farkını döndüren küçük bir karşılaştırma fonksiyonu (`cmpfunc`) yazıldı.

Ana programdaki dizi $\{9, 5, 0, 20, 35, 1, 11\}$ sıralanınca $0, 1, 5, 9, 11, 20, 35$ olur. Ardışık farklar $1, 4, 4, 2, 9, 15$'tir; en küçük uzaklık 1'dir (0 ile 1). Yorum satırındaki 17 elemanlı dizide de en küçük uzaklık 1'dir. İki değer python ile hem brute-force hem böl ve yönet yöntemiyle kontrol edildi.

**Soru (sohbetten):** Örneğin 5-6 ve 7-8 çiftlerinin uzaklığı da 1 ise hangisi seçilecek? **Cevap:** Ödevde kritik nokta, algoritmik düşünceyle en kısa mesafeyi bulabilmektir; hangi çiftin döndürüldüğü önemli değildir. En yakın elemanları da döndürmek isteyen, en küçüğü hesaplarken hem değeri hem uzaklığı tutan bir yapı (struct) tanımlayabilir ya da fonksiyona işaretçi gönderip $p_1$, $p_2$ noktalarını o yolla alabilir.

> **Hocanın vurgusu:** Kütüphanedeki `qsort` kullanılabilir, ama ödevlerde kodlamaya da bakılır; hazır fonksiyon kullanmak pek tercih edilmez.

## 8. Problem 2: Von Neumann komşuluğu

İkinci problemde bir Von Neumann komşuluğuna uygun matrisler oluşturulması isteniyor. Bir yarıçap değeri alınır ve bu değere göre baklava (diamond) biçiminde şekiller çizilir. Slayttaki tanımlar şöyledir (ekrandan, 00:50:00):

- $N_{(x_0,y_0)} = \{(x,y) : |x - x_0| + |y - y_0| \le r\}$
- Toplam siyah hücre sayısı: $2r(r+1) + 1$ (Delannoy sayıları)
- Matris boyutu: $2n + 3$

$(x_0, y_0)$ merkezdir. Merkeze Manhattan uzaklığı $r$'ye eşit veya ondan küçük olan hücreler siyaha boyanır, yani 1 yapılır. Slaytta $r = 0, 1, 2, 3$ için dört şekil vardır; ödevde yarıçap $n$ diye verildiği için kodda $n$ kullanılır.

Matris boyutu şöyle açıklandı: şekil her yöne yarıçap kadar uzandığı için $2n$ hücre eder, merkezin kendisi 1 hücredir, iki yanda birer boş hücre bırakılır (2 hücre); toplam $2n + 3$.

Python ile kontrol (ara adım eklendi):

| $r$ | Matris boyutu | Satır başına siyah hücre | Toplam | $2r(r+1)+1$ |
|---|---|---|---|---|
| 0 | 3 | 0, 1, 0 | 1 | 1 |
| 1 | 5 | 0, 1, 3, 1, 0 | 5 | 5 |
| 2 | 7 | 0, 1, 3, 5, 3, 1, 0 | 13 | 13 |
| 3 | 9 | 0, 1, 3, 5, 7, 5, 3, 1, 0 | 25 | 25 |

Satır başına siyah hücre sayısı 1'den başlayıp 3, 5, 7 diye artar, sonra yeniden azalır. Asistan, bu belirli kurala göre ilerlediği için satır sayılarının ayrıca hesaplanmadan doğrudan da atanabileceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Delannoy sayısı $D(m,n)$, $(0,0)$'dan $(m,n)$'ye yalnız sağa, yukarı ve çapraz adımlarla giden yolların sayısıdır. $d$ boyutlu, $r$ yarıçaplı Von Neumann komşuluğundaki hücre sayısı $D(d, r)$'ye eşittir; $d = 2$ için bu $2r^2 + 2r + 1$, yani slayttaki formüldür.

**Soru (bir öğrenci):** Bu problem birden fazla yolla çözülebilir mi? **Cevap:** Algoritma sorularının çoğu birden fazla yöntemle çözülebilir. Ancak soru belirli bir algoritmaya bağlıysa o algoritma tabanında çözülmelidir.

Bir öğrenci kendi çözümünü anlattı: önce matris boyutunu belirledi, sonra her satırda siyah hücrelerin başlayacağı ve biteceği indisi veren bir formül kurdu ve yalnız siyah hücreleri doldurdu; beyaz hücreleri hiç gezmedi. Bu çözüm iteratifti. Asistan, algoritmanın mantığına uyduğu sürece bunun sorun olmadığını, ama bu soruda özyinelemeli bir yaklaşım beklendiğini söyledi.

## 9. Özyinelemeli ve yinelemeli çözüm

### 9.1 Neden özyineleme

**Soru (bir öğrenci):** Soruya bakınca özyineleme akla gelmiyor; soruda özyinelemeyi gerektiren bir şey yok. **Cevap:** Şekle bakınca belli bir kurala göre sürekli büyüyen bir yapı görülür. Şekil dört yöne doğru büyüdüğü için örneğin bir yukarı, bir sağa, bir aşağı, bir sola giden özyinelemeli bir yapı kurulabilir. Üst üste binen ve sürekli artan bir yapı özyinelemeyi akla getirmelidir.

**Soru (bir öğrenci):** Özyinelemede yığın taşması (stack overflow) riski olduğu için iteratif tercih edilmez mi? **Cevap:** Özyinelemenin bu dezavantajı vardır, ama bu onu hiç kullanmayacağımız anlamına gelmez. Özyineleme bellek kullanıyor diye sürekli ondan kaçılmamalıdır.

Öğrenciler arasında da bir tartışma oldu: bir öğrenci her karede dört komşuya bakmak gerektiğini, bunun ek karşılaştırma getireceğini söyledi; bir başkası gidilecek yönler hesaplanırsa (örneğin yukarı giden çağrı yalnız yukarı giderse) aynı hücreye tekrar yazmak gerekmeyeceğini savundu. Asistan bunun da olabileceğini söyledi.

> **Hocanın vurgusu:** Özyinelemenin yığın ve bellek maliyeti vardır, ama özyinelemeden kaçmak her zaman doğru değildir; bu soru için özyinelemeli yaklaşım bekleniyordu.

### 9.2 Özyinelemeli sözde kod

Slayttaki sözde kod (ekrandan, 00:55:00):

```text
Von Neumann Neighborhood Recursive
Inputs  <- n
Outputs <- matrix

function vonNeumann(row, col)
    if |row-x0| + |col-y0| <= n then
        matrix[row][col]=1
    end if
    if (col mod size) == 0 then
        col=0
        row=row+1
    end if

    if row<size then
        vonNeuman(row,col)
    end if
end function
```

Fonksiyon her çağrıda tek bir hücreye bakar. Satır ve sütun indisinin merkeze olan Manhattan uzaklığı hesaplanır; $n$'e eşit ya da küçükse hücre 1 yapılır. Sonra sütun ilerletilir; son sütuna gelinince sütun 0'lanır ve bir alt satıra geçilir. Satır indisi boyuttan küçük olduğu sürece fonksiyon yeni indislerle kendini yeniden çağırır ve her hücrenin 0 mı 1 mi kalacağına karar verilir.

> **Ders sonrası not:** Slayttaki sözde kodda sütunu artıran satır eksiktir. Asistan anlatırken bunu fark etti: ilk `end if`'in altında `col = col + 1` olmalıdır; aksi halde `col mod size` hiç değişmez. Aynı eksik yinelemeli sözde kodda da vardı.

Hücreleri ayrıca 0'a eşitlemeye gerek yoktur, çünkü matris dinamik olarak `calloc` ile ayrılır ve `calloc` belleği sıfırla başlatır. Asistan kendi çözümünde özyinelemeli çağrıyı bir kez yaptığını, iki ya da dört kez çağırmanın da verimsiz olmadığını söyledi: çağrı sayısı artınca her birinin işi azalır. Önemli olan aynı karmaşıklığa sahip etkili bir yaklaşım kurmaktır.

### 9.3 Yinelemeli karşılık

Aynı mantık bir `while` döngüsüyle de yazıldı: önce sütunlar, sonra satırlar işlenir; satır indisi boyuttan küçük olduğu sürece döngü döner. Her adımda hücrenin merkeze uzaklığının $n$'e eşit ya da küçük olup olmadığına bakılır, öyleyse 1 atanır. Sütun boyuta göre mod alınır; son sütuna gelinince satır artırılır. Asistan bunu yalnız özyinelemeli çözümün iteratif karşılığını göstermek için yazdığını, daha etkili iteratif çözümler olabileceğini belirtti.

<!-- BELİRSİZ: yinelemeli sözde kodun slaytı karelerde görünmüyor; anlatım altyazıdan kuruldu. -->

## 10. Problem 2'nin C kodu ve iki boyutlu dinamik bellek

Özyinelemeli çözümün `main` kısmı (ekrandan, 01:10:00):

```c
    int **matrix,*rowBlac, black;
    int size,i,j;

    printf("Neighborhood (n) giriniz:");
    scanf("%d", &n);

    size = (2*n) + 3;
    black = ((2*n)*(n+1))+1;

    matrix=(int**)calloc(size,sizeof(int*));
    if(matrix == NULL) {
        printf("Bellek ayrilamadi...\n");
        return -1;
    }

    for(i=0;i<size;i++){
        matrix[i]=(int*)calloc(size,sizeof(int));
    }

    rowBlac = (int*)calloc(size, sizeof(int));

    vonNeumann(matrix, rowBlac, 0, 0, n, size);

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%3d", matrix[i][j]);
        }
        printf("\t\t%d siyah hucre \n",rowBlac[i]);
    }
```

Bu da bir kod parçasıdır (`n`'in bildirimi ve `vonNeumann` fonksiyonu ekranda görünmüyor), bu yüzden derlenmedi. Anlatım:

- Boyut $2n+3$, toplam siyah hücre $2n(n+1)+1$ formüllerle hesaplanır.
- Matris iki boyutlu olduğu için önce satır işaretçileri dizisi (`int**`) ayrılır, sonra bir for döngüsüyle her satır ayrı ayrı `calloc` ile ayrılır. `malloc` yerine `calloc` kullanıldı, çünkü hücrelerin 0 ile başlaması isteniyor.
- Matris tek boyutlu, `size * size` uzunlukta bir dizi olarak da tutulabilir; ama "matris" denince iki boyutlu dinamik bellek ayırma yapılır.
- Soruda her satırdaki siyah hücre sayısı da isteniyordu. Bunun için `rowBlac` dizisi tutuldu; `vonNeumann` fonksiyonu Manhattan uzaklığı $n$'den küçük ya da eşit olan hücreyi 1 yaparken o satırın sayacını da artırır. Bu sayılar belli bir kurala uyduğu için doğrudan da atanabilir; önemli olan karmaşıklığı ve belleği kötüleştirmemektir.

**Soru (bir öğrenci):** `calloc`/`malloc` ile iki boyutlu ayrılan alan nasıl serbest bırakılır? **Cevap:** <!-- BELİRSİZ: cevabın büyük kısmı altyazıda eksik. --> Soru, ayırmanın tersi sırayla önce bir döngüyle satırların, sonra satır işaretçileri dizisinin serbest bırakılması üzerineydi.

> **Ek bilgi (derste anlatılmadı):** İki boyutlu dinamik dizide önce `for` ile her `matrix[i]` için `free(matrix[i])`, en son `free(matrix)` çağrılır. Önce `matrix` serbest bırakılırsa satır işaretçilerine artık güvenli biçimde erişilemez.

## Örnek Sorular

**1. (ekrandan, 00:20:00)** $N$ elemanlı bir dizide birbirine en yakın değere sahip iki eleman bulunacaktır. (a) Brute-force çözümü yazıp verimliliğini analiz ediniz. (b) Daha az karmaşık bir algoritmik yöntemle çözüp analiz ediniz.

> **Çözüm (derste verildi):** (a) İç içe iki döngüyle her çift karşılaştırılır, en küçük mutlak fark tutulur: $O(n^2)$. (b) Dizi sıralanır, orta noktadan ikiye bölünür; iki yarının en küçük uzaklığı $d$ bulunur, orta noktaya $d$'den yakın elemanların oluşturduğu şeritte de en küçük uzaklık aranır ve $\min(\delta_1, \delta_2, \delta_{12})$ döndürülür; $n \le 3$ için brute-force. Sıralamadan sonra yalnız ardışık elemanları karşılaştırmak da $O(n \log n)$ verir.

**2. (derste sözlü, 00:32:56)** Quicksort'un dezavantajı nedir? En kötü durumu neden $O(n^2)$'dir?

> **Çözüm (derste verildi):** Pivot dizinin en küçük ya da en büyük elemanı seçilirse (örneğin sıralı dizide ilk eleman) dizi dengeli bölünemez; her adımda yalnız bir eleman ayrılır ve karmaşıklık $O(n^2)$ olur.

**3. (derste sözlü, 00:29:53)** İki yarının en yakın çiftlerinden kısa olanı seçmek neden yeterli değildir?

> **Çözüm (derste verildi):** En yakın çift kesimin iki yanına düşmüş olabilir ($p_3 \in S_1$, $q_3 \in S_2$). Bu yüzden orta noktaya $d$ uzaklıktaki elemanlar ayrıca karşılaştırılır.

**4. (ekrandan, 00:50:00)** Merkezi $(x_0,y_0)$ olan, yarıçapı $r$ olan Von Neumann komşuluğunu bir matriste 1'lerle gösteriniz; toplam ve satır başına siyah hücre sayısını veriniz.

> **Çözüm (derste verildi):** Matris boyutu $2n+3$; $|x-x_0|+|y-y_0| \le r$ olan hücreler 1 yapılır. Toplam $2r(r+1)+1$; $r = 3$ için 25 hücre, satır sayıları $1, 3, 5, 7, 5, 3, 1$ (python ile doğrulandı).

## Dersin Toparlaması

Bu oturumda birinci ödevin iki problemi çözüldü. Tek boyutta en yakın çift probleminde kaba kuvvet çözümün $O(n^2)$ olduğu, böl ve yönet çözümünde ise sıralamadan sonra diziyi ikiye bölüp iki yarıyı ve orta noktanın $d$ yakınındaki şeridi inceleyerek sonuca ulaşıldığı görüldü. Sıralı dizide en yakın çiftin ardışık olduğu gözlemi de aynı $O(n \log n)$ karmaşıklığa götürdü. Quicksort'un pivot seçimine bağlı en kötü durumu ile merge sort'un ek bellek ihtiyacı karşılaştırıldı.

İkinci problemde Manhattan uzaklığıyla tanımlanan Von Neumann komşuluğu, $2r(r+1)+1$ siyah hücre ve $2n+3$ matris boyutu formülleriyle birlikte işlendi. Özyinelemeli ve yinelemeli çözümler karşılaştırıldı; özyinelemenin bellek maliyetine rağmen kurala göre büyüyen yapılarda doğal bir seçenek olduğu vurgulandı. İki boyutlu dinamik bellek ayırma `calloc` ile tekrar edildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
