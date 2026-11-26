# Ders 12 Genişletilmiş Notu: Özyineleme, Fonksiyon İşaretçileri, Dosya İşlemleri ve Makefile

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Özyineleme (Recursion)
- 2. Özyineleme Örnekleri: Rakamlar ve Üs Alma
- 3. Fonksiyon İşaretçileri
- 4. Dosya İşlemlerine Giriş: Akışlar
- 5. Metin ve İkili Biçim
- 6. FILE Yapısı ve Dosya Konum Göstergesi
- 7. Dosya Açma: fopen ve Erişim Kipleri
- 8. Okuma ve Yazma Yöntemleri
- 9. Karakter G/Ç
- 10. Satır G/Ç
- 11. Blok G/Ç
- 12. Rastgele Erişim: fseek ve ftell
- 13. Dosya Yönetim Fonksiyonları
- 14. void İşaretçiler
- 15. Dosya Kopyalama Örneklerinin Çalıştırılması
- 16. Programın Bellek Düzeni
- 17. Makefile ve Derleme Otomasyonu
- Örnek Sorular
- Dersin Toparlaması

## 1. Özyineleme (Recursion)

Ders, önceki haftadan kalan özyineleme konusuyla başladı. Özyinelemeli fonksiyon kendi kendini çağıran fonksiyondur. Bu C'ye özgü bir şey değil, genel bir programlama stratejisidir; C'de de kullanılabilir.

### 1.1 Durma noktası olmayan özyineleme

Slayttaki örnek (ekrandan, 00:10:00):

```c
void recurse () {
    static count = 1;
    printf("%d\n", count);
    count++;
    recurse();
}
main() {
    recurse();
}
```

Slayttaki açıklamaya göre bu fonksiyon kendini "sonsuza kadar" çağırır; aslında sonsuza kadar değil, bilgisayarın yığın (stack) belleği bitene kadar. Bu da bir çalışma zamanı hatası demektir. Bu yüzden özyinelemeli fonksiyonlara mutlaka bir durma noktası (stop point) konmalıdır.

Hoca bunun nedenini fonksiyon çağrısı mekanizmasıyla açıkladı. Bir fonksiyon çağrıldığında, iş bitince kalınan yere dönülebilmesi için bilgisayar yığın belleğine bir yedek yazar. Bu yedekleme alanı sınırlıdır. Kod derste çalıştırıldı: ekrana art arda artan sayılar yazıldı ve program yaklaşık 43 bin civarında durdu. Yani o bilgisayarda en fazla 43 bin küsur iç içe çağrı yapılabildi; bu sayı makineye göre değişir.

> **Ek bilgi (derste anlatılmadı):** Slayttaki `static count = 1;` ve dönüş türü yazılmamış `main()` eski C'deki "örtük int" kuralına dayanır. Güncel derleyiciler bunu uyarı ya da hata olarak bildirir; `static int count = 1;` ve `int main()` yazmak doğrudur.

### 1.2 Özyineleme ne işe yarar?

Özyineleme özellikle böl ve yönet (divide and conquer) ve azalt ve yönet algoritmalarında işe yarar: problemin boyutu küçültülür, küçük parçalar çözülür, sonra çözümler birleştirilir.

Hoca bunu bir işlem ağacıyla gösterdi. `A*B + X/Y` ifadesinin ağacında kök `+`'dır; sol alt ağaçta `*` ile `A`, `B`; sağ alt ağaçta `/` ile `X`, `Y` bulunur. Prefix (preorder) gezintide kural "önce köke git, sonra sola, sonra sağa"dır:

- Kök `+` yazılır.
- Sol tarafa gelinince orada yeni bir alt ağaç başlar; onun kökü `*` yazılır, sonra solu `A`, sonra sağı `B`.
- Sol taraf bitince sağa geçilir: `/`, `X`, `Y`.

Sonuç `+ * A B / X Y` olur. Her alt ağaçta aynı işin yeniden başlaması, problemin yinelemeli bir yöntemle değil özyinelemeli bir yöntemle daha kolay çözülmesini sağlar.

### 1.3 Temel durum ve yığın

Özyinelemede dikkat edilmesi gereken nokta bir durma noktası, yani temel durumdur (base case). Program çalışınca `main` fonksiyonu bir kere yığına yüklenir. Herhangi bir yerde fonksiyon çağrılınca bu fonksiyonun parametreleri ve içindeki değerler yığına eklenir, çünkü fonksiyon bitince kalınan yere dönülmesi gerekir. Yer sınırlı olduğu için ekleme sürdükçe bir yerde hata alınır. Hoca bunu `malloc` sonrası yapılan kontrole benzetti: orada bellekte yer olup olmadığına bakılıyordu; burada da yığında yer kalıp kalmadığı söz konusudur.

### 1.4 Faktöriyel

En bilinen örnek faktöriyeldir. Fonksiyonun bir temel durumu, bir de kendini çağıran bölümü vardır. Algoritma analizinde bu iki parça ayrı ayrı düşünülür; temel durumun maliyeti kabaca $\Theta(1)$'dir.

Çağrı şöyle açılır: `fact(5)` kendi içinden `5 * fact(4)`'ü, o da `4 * fact(3)`'ü çağırır ve bu 1'e kadar sürer. `fact(1)` temel duruma takılır ve 1 döndürür. Sonra dönüş yolunda değerler çarpılır: `2 * 1 = 2`, `3 * 2 = 6`, `4 * 6 = 24`, `5 * 24 = 120`.

Diğer bilinen örnekler ikili arama ve derinlik öncelikli aramadır (DFS). DFS'te bir graf ya da ağaçta bir düğümden başlanır, onun bir komşusuna, sonra o komşunun bir komşusuna gidilir; bulunabildiği kadar derine inilir. Geri gelirken de aynı yoldan geri çıkılır; bu da bir yığın yapısının kullanılması demektir.

## 2. Özyineleme Örnekleri: Rakamlar ve Üs Alma

Hoca örneklerin önceden yazılmış kodlarını açarak anlattı.

### 2.1 Sayının rakamlarını yazdırma

Kullanıcıdan pozitif bir sayı alınır ve rakamları ekrana yazılır. Program önce yinelemeli (non-recursive), sonra özyinelemeli fonksiyonu çağırır.

- Yinelemeli yöntem: sayının 10'a göre modu alınınca son basamak bulunur. Sonra sayı 10'a bölünür; tamsayı bölmesi olduğu için kesme (truncation) yapılır ve son basamak atılır. Bu döngüyle sürer.
- Özyinelemeli yöntem: döngüyü durduran koşul burada da ifade edilmelidir. Sayı bölündükçe 0'a yaklaşır ve en sonunda 0 olur. Sayı 0 ise `return` yapılır. Değilse sayının 10'a göre modu yazdırılır ve fonksiyon `x / 10` için yeniden çağrılır.

Bu şekilde rakamlar tersten, yani birler basamağından başlayarak elde edilir.

### 2.2 $x^y$ hesabının dört yolu

Hoca öğrencilere $x^y$'yi $O(n)$'den daha iyi hesaplayan bir kodu nasıl yazacaklarını sordu; yanıt gelmeyince yazdığı dört fonksiyonu sırayla inceledi.

**power1 (naif yöntem):** 1'den başlanır, $y$'ye ulaşana kadar sonuç $x$ ile çarpılır. $y$'ye $n$ dersek döngü $n$ kez döner; karmaşıklık $O(n)$'dir.

**power2 (özyinelemeli):** $x$ 0 ise 0, $y$ 0 ise 1 döndürülür. İkincisi özyinelemenin temel durumudur. Sonra `x * power2(x, y-1)` çağrılır: $x^y = x \cdot x^{y-1}$, o da $x \cdot x^{y-2}$'yi çağırır ve böyle sürer. Bir birimlik iş ve bir $T(n-1)$ çağrısı olduğundan $T(n) = T(n-1) + 1$'dir. Geri yerine koyma (back substitution) gibi yöntemlerle çözülünce yine $O(n)$ çıkar.

**power3 (verimsiz böl ve yönet):** Fikir şudur: $x^{y/2}$ bulunur ve kendisiyle çarpılırsa $x^y$ elde edilir; $x^{y/2}$ için de $x^{y/4}$ kullanılır. Böylece acaba $\log n$'e inilebilir mi? Kuvvetin tek mi çift mi olduğuna bakılır. $x^6$ için iki tane $x^3$, $x^7$ için iki tane $x^3$ ve bir $x$ gerekir. Ancak bu sürümde $x^{y/2}$ iki ayrı çağrıyla hesaplanır. Ekranda tek kuvvet satırı şöyledir (ekrandan, 00:25:00):

```c
return x*power3(x,y/2)*power3(x,y/2);
```

Özyineleme bağıntısı $T(n) = 2T(n/2) + 1$'dir. Ana teoremde (master theorem) $a = 2$, $b = 2$, $d = 0$ olur ve sonuç yine $O(n)$ çıkar. Çünkü bir kez hesaplanan bir değer aynı şekilde yeniden hesaplanıyor; bu gereksiz bir yük doğuruyor. Hoca bunu "böl ve yönet ama etkili olmayan, hatta ekstra özyinelemeli çağrı gerektirdiği için daha kötü bir yöntem" diye niteledi.

**power4 (verimli böl ve yönet):** Ekrandaki kod (ekrandan, 00:25:00):

```c
int power4(int x, int y){// T(N) = T(N/2) + 1 a=1, b=2, d=0 ==> O(logN)
    int result;
    if(y == 0)
        return 1;
    result = power4(x,y/2);
    if(y % 2 == 0)
        return result*result;
    else
        return x*result*result;
}
```

Burada $x^{y/2}$ bir kez hesaplanıp `result`'ta tutulur. Kuvvet çiftse `result` iki kez, tekse `result` iki kez ve bir de $x$ ile çarpılır. Bağıntı $T(n) = T(n/2) + 1$, yani $a = 1$, $b = 2$, $d = 0$; ana teoremle sonuç $O(\log n)$'dir.

Fonksiyonlar küçük bir `main` ile `gcc -Wall` altında derlenip denendi: $3^0$ ile $3^7$ arasında `power3` ve `power4` aynı değerleri (1, 3, 9, 27, 81, 243, 729, 2187) verdi, `power4(2, 10)` da 1024 döndürdü.

> **Ek bilgi (derste anlatılmadı):** Ana teoremin $T(n) = aT(n/b) + O(n^d)$ biçiminde, $d < \log_b a$ ise sonuç $O(n^{\log_b a})$, $d = \log_b a$ ise $O(n^d \log n)$ olur. `power3`'te $\log_2 2 = 1 > 0$ olduğundan $O(n)$, `power4`'te $\log_2 1 = 0 = d$ olduğundan $O(\log n)$ çıkar.

## 3. Fonksiyon İşaretçileri

Hoca bu konunun laboratuvarda da örneklerle çalışıldığını söyledi.

### 3.1 Tanım

Bir fonksiyonu çağırmanın tek yolu adını kullanmak değildir; fonksiyonun adresi bir işaretçide tutulup oradan da çağrılabilir. Bu işi yapan işaretçilere fonksiyon işaretçisi denir.

İşaretçi değişkeni üretirken nasıl yıldız (`*`) kullanılıyorsa burada da kullanılır, ama bunun bir fonksiyon olduğunu belirtmek için arkasına parantezli fonksiyon işareti yazılır. Ayrıca `*pf` paranteze alınmalıdır: `int (*pf)(...)`. Parantez yazılmazsa ifade `int*` türünde değer döndüren bir fonksiyon bildirimi gibi okunur.

İşaretçinin türü, çalıştıracağı fonksiyonun prototipi ne döndürüyorsa ona göre seçilir. `int` döndüren fonksiyon için `int`, `void` döndüren için `void` kullanılır.

### 3.2 Atama

`pf = f1;` yazmak, `f1` fonksiyonunun adresini `pf`'ye atar ve doğru yoldur. Hocanın gösterdiği yanlış yazımlar:

- `pf = f1();` fonksiyonu çağırıp dönen tamsayıyı `pf`'ye atamak demektir; olmaz.
- `pf = &f1();` çağrının sonucundan adres almaya çalışır; geçerli değildir.
- Fonksiyon adı zaten bir adres (işaretçi) gibi davrandığından adresini almaya çalışmak "işaretçinin işaretçisi" mantığına gider.

Derste bu üç yöntemin kullanılmadığı, yalnız `pf = f1;` biçiminin kullanıldığı söylendi.

Tür uyumu için slayttaki örnekte `int` döndüren `if1`, `if2`; `float` ve `char` döndüren fonksiyonlar ve bunlara karşılık gelen işaretçiler (`pif`, `pff`, `pcf`) vardı. `pif = if1` doğrudur, çünkü ikisi de `int` türündendir. `pif = cf1` (char döndüren fonksiyon) ya da `float` döndüren işaretçiye `int` fonksiyonu atamak olmaz. `pcf`'ye `char` döndüren fonksiyon atanabilir. Kural basittir: işaretçinin türü fonksiyonun prototipine uymalıdır.

### 3.3 Fonksiyon işaretçisiyle çağrı

Slayttaki örnek (ekrandan, 00:30:00):

```c
#include <stdio.h>
extern int f1(int); //could be defined externally but we have coded it below
int main() {
    int n;
    int (*pf) ();
    int answer;
    printf("Bir sayi giriniz: "); scanf("%d",&n);

    pf=f1;
    answer=(*pf)(n); // calls f1() with argument a => f1(a)

    printf("%d", answer);
    return 0;
}
int f1( int a ) {
    return a+1;
}
```

`f1` sayıya 1 ekleyip döndürür. Sayı kullanıcıdan alınır, `pf = f1;` yapılır, sonra `pf` parametresiyle çağrılır. `f1` bir tamsayı parametre aldığı için çağrıda bu parametre gönderilir; dönen değer de bir değişkende tutulur. Sonuç, `f1(n)` doğrudan çağrılmış gibidir.

Kod `gcc -std=c11 -Wall` ile derlenip 5 girdisiyle çalıştırıldı; çıktı 6 oldu.

> **Ders sonrası not:** Slayttaki `int (*pf) ();` bildirimi C17 ve öncesinde "parametreleri belirtilmemiş fonksiyon işaretçisi" anlamına gelir. Güncel GCC'nin varsayılan standardı olan C23'te `()` "parametre yok" demektir; bu yüzden kod `-std` belirtilmeden derlenince `pf=f1;` ve `(*pf)(n)` satırları hata verir. Her standartta doğru yazım `int (*pf)(int);` biçimidir; bu düzeltmeyle de derlenip aynı sonuç alındı.

### 3.4 Fonksiyon işaretçisini parametre olarak göndermek

Hocaya göre fonksiyon işaretçileri en çok genel (generic) bir fonksiyonun özel hallerini seçmek için kullanılır. Örnek: kullanıcının verdiği aralıktaki (derste 5'ten 15'e) sayıların toplamını ya da karelerinin toplamını bulmak. Toplam; sayıların, karelerin, küplerin ya da başka şeylerin toplamı olabilir. Genel toplama fonksiyonu yazılıp hangi değerin toplanacağı fonksiyon işaretçisiyle parametre olarak verilir.

- `selfI(i)` sayının kendisini döndürür.
- `squareI(i)` sayının karesini döndürür.
- `sumGeneric(fp, x, y)` $x$'ten $y$'ye kadar `fp(i)` değerlerini kümülatif olarak toplar. `fp` olarak `selfI` gelirse sayıların, `squareI` gelirse karelerin toplamı bulunur.

Karşılaştırma için ayrıca yalnız karelerin toplamını bulan, parametreyi doğrudan alan yinelemeli bir `sumOfSquares` fonksiyonu da vardı. Genel fonksiyonda ise fonksiyon adı da argüman olarak verilebilir. Hoca bunu öğrencilerin sıralama algoritmalarında yaptığı işe bağladı: artan mı azalan mı sıralanacağı bir karşılaştırma fonksiyonuyla seçilir.

### 3.5 Fonksiyon işaretçisi dizisi

Fonksiyon işaretçileri dizi olarak da tanımlanabilir. Örnekte dört elemanlı bir fonksiyon işaretçisi dizisi vardı; hoca onu önce global tanımlamıştı (fonksiyonlarla ilişkisini göstermek için), sonra `main` içine aldı ve programı derledi. Dizinin 0. elemanına toplama (`sum`), 1. elemanına çıkarma (`subtract`), ötekilerine çarpma ve bir başka işlem atandı. Kullanıcıdan 1, 2, 3, 4 seçeneklerinden biri ve iki sayı alındı; sonuç `p[islem](i, j)` ile hesaplandı. Derste 5 ve 8 girilip çarpma seçildi ve sonuç ekrana yazıldı.

## 4. Dosya İşlemlerine Giriş: Akışlar

### 4.1 Neden standart G/Ç kütüphanesi?

Slayta göre (ekrandan, 00:35:00) işletim sistemleri dosya ve aygıtlardaki veriye erişim biçimlerinde çok farklılık gösterir. Bu da taşınabilir G/Ç programları yazmayı zorlaştırır. C, G/Ç işlemlerini geniş bir çalışma zamanı rutinleri kümesiyle yapar; bunların bir kısmı UNIX G/Ç kütüphanesinden türetilmiştir.

Hoca bunu `printf` ile örnekledi: arka planda ne yaptığını bilmeyiz ama ekrana yazı bastırdığını biliriz ve Windows, Linux, Mac gibi bütün sistemlerde çalışır. Altında, hangi işletim sistemi çalışıyorsa onunla uyumlu işlem yapan kodlar vardır.

- "C kütüphanesi" çoğunlukla tamponlu (buffered) G/Ç ile, UNIX kütüphanesi tamponsuz (unbuffered) G/Ç ile çalışır. Aynı şey işletim sisteminin kendi komutlarıyla da ekrana yazılabilir; fark tamponlama meselesindedir.
- UNIX ikili ve metin dosyalarını aynı görür; bazı başka sistemlerde bu ayrım çok önemlidir.
- ANSI komitesi bazı fonksiyonları korudu, sildi ya da değiştirdi. En büyük değişiklik tamponsuz G/Ç fonksiyonlarının çıkarılmasıdır; ANSI kütüphanesinde bütün G/Ç fonksiyonları tamponludur, tampon boyutu yine değiştirilebilir. ANSI fonksiyonları dosyaya ikili ya da metin kipinde erişmeyi ayırt eder.

### 4.2 Akış (stream)

Dosya aslında işletim sistemi ile program arasında kurulan bir akıştır (stream); kanal ya da ırmak da denir. Kaynak klavye, dosya ya da başka bir şey olabilir; haberleşme bu yolla yapılır.

Her program için otomatik açılan üç akış vardır (ekrandan, 00:40:00): `stdin`, `stdout` ve `stderr`. Birincisi girdi, diğer ikisi çıktı akışıdır. Bir hata olduğunda mesaj normal çıktı kanalından değil, ayrı bir kanaldan (`stderr`) gönderilir.

Bu akışlar genelde terminali gösterir, ama birçok işletim sistemi bunları yönlendirmeye izin verir; örneğin hata mesajlarının terminal yerine bir dosyaya yazılması istenebilir. Daha önce kullanılan `printf` `stdout`'a yazar, `scanf` `stdin`'den okur. Bu fonksiyonlar `stdin` ve `stdout` dosyaları gösterecek şekilde yönlendirilerek (`freopen` ile) dosya G/Ç'si için de kullanılabilir; ama daha kolay yol, akışı belirtmeye izin veren `fprintf` ve `fscanf` fonksiyonlarıdır.

Hoca çıktının nereye gidebileceğine örnek olarak mantık devreleri ve ileride görülecek mikroişlemciler dersini verdi: programın çıktısı bir devreye, seri porta ya da USB portuna gönderilebilir.

### 4.3 Dosya neden gerekli?

RAM'deki veriler program kapanınca silinir. Veriyi kalıcı saklamak için dosyaya yazmak gerekir. Dosya uzantısı da dosyanın hangi biçimde yazıldığını söyleyen bir bilgidir; işletim sistemi buna göre ilgili programı açar (örneğin `.c` dosyasına çift tıklayınca bir C geliştirme ortamının açılması).

### 4.4 fprintf ve fscanf

`printf` ve `scanf`'te doğrudan biçim dizgesi ve sonra parametreler yazılır. `fprintf`'te ek olarak, hangi dosyaya ulaşılacaksa onun dosya işaretçisi ilk argüman olarak verilir; mesaj ekrana değil o dosyaya yazılır. Tabii öncesinde dosya açılmış, sonrasında kapatılmış olmalıdır.

`fscanf` ile bir kaynaktan okurken de dosya işaretçisi verilir; imlecin bulunduğu yerden bir string okunur ve bir tampon (`buffer`) değişkenine konur. Derste gösterilen bir örnekte önce `file.txt` dosyasına yazıldı, sonra aynı dosya okunup her okunan parça ekrana yazdırıldı; her yeni okumada eski değerin yerini yenisi aldı.

Bir başka örnekte çalışan bilgilerini dosyada saklayan bir program vardı: dosya yazma kipinde açılıyor, açılamazsa hata veriliyor; değilse kimlik, ad ve maaş bilgileri alınıp sırayla `fprintf` ile dosyaya yazılıyor ve dosya kapatılıyordu. Dosya açıldığında içinde bu bilgiler satır satır görülür. Aynı mantıkla dosya okuma kipinde açılıp `fscanf` ile, örneğin eşittir işaretinden sonraki değerler okunarak veriler geri alınabilir. Hoca bu verilerin ayrı değişkenler yerine bir yapıyla (struct) tutulmasının daha güzel olacağını söyledi.

## 5. Metin ve İkili Biçim

Veriye metin ya da ikili (binary) biçimde erişilebilir (ekrandan, 00:45:00).

**Metin biçimi:** Dosyanın içine bakınca yazılmış veriler açıkça görülür. Hocaya göre boyut büyüktür ve güvenlik açısından sorun çıkarabilir. Metin akışı satırlardan oluşur ve her satır yeni satır karakteri (`'\n'`) ile biter.

Ancak işletim sistemleri satırları diskte başka biçimlerde de saklayabilir; bu yüzden metin dosyasındaki her satırın `'\n'` ile bitmesi gerekmez. Örneğin birçok IBM sistemi metin satırlarını her satırın başını gösteren işaretçilerden oluşan bir dizinle takip eder. Bu düzende disk ya da teyp üzerindeki dosyalar mantıksal olarak satırlardan oluşsa da yeni satır karakteri içermeyebilir. Bu satırlar belleğe metin kipinde okunurken çalışma zamanı fonksiyonları yeni satır karakterlerini metin akışına kendiliğinden ekler.

Hoca bunu bir dosya üzerinden anlattı: metin dosyasında `ABC`, Enter, `XYZ` yazıp kaydederken `\n` diye bir şey yazılmaz; Enter'a basılır ve sistem alt satıra geçişi kendisi kaydeder. Ama metnin içine `\n` karakterlerini elle yazarsanız okurken onları da karakter olarak görürsünüz.

Metin dosyalarında veriler genelde nokta, virgül, noktalı virgül gibi ayırıcı karakterlerle ayrılır. Örneğin `AAA;123;XYZ` gibi bir biçim kullanılıyorsa okurken de bu noktalı virgüllere göre ayırmak ve anlamlandırmak gerekir. Dosyanın biçimi nasıl belirlendiyse ona göre yazılır ve ona göre okunur.

**İkili biçim:** Veriler kodlanmış olarak durur; dosya açılınca içerik doğrudan okunamaz. Hoca bir slayt dosyasını metin düzenleyicide açıp anlamsız görünen karakterleri gösterdi: her karakterin 0 ve 1'lerden bir karşılığı vardır ve bunlar bir araya gelerek dosyayı oluşturur. Hocaya göre ikili biçim veriyi daha az yer kaplayacak ve daha güvenli biçimde saklar.

## 6. FILE Yapısı ve Dosya Konum Göstergesi

Akışları kullanmak için G/Ç fonksiyonları kullanılır ve bu fonksiyonlar ilgili dosya ya da aygıtla ilişkilendirilir. Bunun için `FILE` yapısından bir işaretçi tanımlanır. `FILE`, `stdio.h` içinde tanımlanmış bir yapıdır; büyük harfle yazılır.

Yapının içinde dosyanın adı, erişim kipi, dosyada okunacak sıradaki karakterin konumu gibi farklı alanlar ve işletim sistemine dair bilgiler vardır. Dosya açılırken adı ve erişim kipi verilir; bu alanlar işaretçi oluşturulduktan sonra doldurulur.

İşlem sırası şöyledir:

1. Dosya `fopen` ile açılır ve `FILE` işaretçisi alınır.
2. Okuma ve yazma yapılır.
3. Dosya kapatılır.

Dosya işaretçisi dosyaya erişince dosyanın içinde imleç gibi gezinmeyi sağlar. Bu, dosya konum göstergesi (file position indicator) denen yapıyla ilişkilidir. Bir karakter okununca gösterge bir ileri gider. İstenirse geri sarılabilir, başa ya da sona gönderilebilir. Sıralı okumada bir karakter, bir satır, bir string, bir tamsayı, bir ondalık sayı ya da bir blok veri okunabilir.

Slayta göre (ekrandan, 00:50:00) dosya konum göstergesine doğrudan (en azından taşınabilir biçimde) erişilemez; ama değeri kütüphane fonksiyonlarıyla okunup değiştirilebilir. Böylece akışa sıralı olmayan biçimde (rastgele erişimle) ulaşılabilir: dosyanın başına git, bir geri gel, bulunduğun yerden beş ileri git gibi.

Dosya işaretçisi ile dosya konum göstergesi karıştırılmamalıdır:

- Dosya işaretçisi, bir dosyaya ya da aygıta bağlı açık bir akışı tanımlar; program ile işletim sistemi arasında dosyadan okuma yazmayı sağlayan araçtır.
- Dosya konum göstergesi akış içindeki belirli bir bayt konumunu, yani okunacak ya da yazılacak sıradaki karakteri gösterir.

`stdio.h` başlık dosyasında G/Ç fonksiyonlarının prototipleri, `FILE` yapısının bildirimi ve bazı makrolar vardır: `stdin`, `stdout`, `stderr`, `EOF` ve `NULL`. `EOF` dosyanın sonuna gelinip gelinmediğini gösteren bir işarettir. `NULL` boş işaretçidir, yokluğu gösterir. Hoca `NULL` için `stddef.h`'nin de anıldığını, ama `stdio.h`'nin yeterli olduğunu söyledi.

## 7. Dosya Açma: fopen ve Erişim Kipleri

### 7.1 fopen

Dosya üzerinde işlem yapmadan önce açılmış olması gerekir; açılmadan erişmeye çalışılırsa hata alınır (ekrandan, 01:05:00). `fopen` iki argüman alır: birincisi dosya adı, ikincisi erişim kipi. Metin akışları ve ikili akışlar için iki ayrı kip kümesi vardır.

Hoca Dev-C++'ta küçük bir deneme yazdı (ekrandan, 01:10:00). Önce yalnız `FILE *fp;` tanımlayıp `fprintf(fp, "%d %s", 123, "abc");` yazdı ve dosya işaretçisi henüz bir yeri göstermediği için bunun hata vereceğini söyledi. Sonra `fopen` satırını ekledi:

```c
#include <stdio.h>
int main(){
    FILE *fp;
    fptr = fopen("emp.txt", "w+");
    fprintf(fp,"%d %s",123,"abc");

}
```

Ekrandaki ara halde atama satırında değişken adı `fptr` yazılıydı; hoca derlerken bunu "fptr değil, fp diyeceğiz" diyerek `fp` olarak düzeltti. Dosya adı göreli verildiği için program nerede çalışıyorsa aynı klasörde aranır ya da oluşturulur. Program çalıştırılınca masaüstündeki çalışma klasöründe `emp.txt` oluştu.

Düzeltilmiş hali (`fp = fopen(...)` ve sonda `fclose(fp);` eklenerek) not hazırlanırken `gcc -Wall` ile derlenip çalıştırıldı; `emp.txt` dosyasına `123 abc` yazıldı.

### 7.2 Erişim kipleri

- `"r"`: okumak için açar, okuma dosyanın başından başlar. Dosya yoksa açılamaz.
- `"w"`: yazmak için açar. Dosya yoksa oluşturulur; varsa içi temizlenir ve konum göstergesi dosyanın başına getirilir.
- `"a"`: ekleme (append) kipi; dosyanın sonuna gidilir. Konum söylenmiş olsa bile yazma her zaman dosyanın sonundan yapılır.
- `"r+"`: daha önceden var olan bir dosyayı okuma ve yazma için açar.
- `"w+"`: okuma ve yazma için açar; dosya yoksa oluşturur.
- `"a+"`: dosya varsa açar, yoksa oluşturur ve ekleme kipine getirir. Okuma herhangi bir yerden yapılabilir, yazma ise dosyanın sonundan yapılır.

Bu kiplerin sonuna `b` eklenirse (`"rb"`, `"wb"` vb.) dosya ikili biçimde, eklenmezse metin biçiminde açılır.

`fopen` dosyayı açınca bir işaretçi döndürür. Dosya açılamazsa `NULL` döner; sıfırdan farklı bir değer gelirse geçerli bir adres var demektir. Slayttaki örnekte dosya yazma kipinde açılıyor, işaretçi `NULL` ise program kapatılıyor, değilse yazma işlemleri yapılıp dosya kapatılıyordu.

### 7.3 Okuma kipinde yazma denemesi

Hoca kipi `"r"` yaptı ve `if (fp == NULL) printf("Dosya yok");` ile `else` bloğunda `fprintf` kullanan bir sürüm yazdı (ekrandan, 02:25:00):

```c
FILE *fp;
fp = fopen("emp.txt", "r");
if(fp==NULL){
    printf("Dosya yok");
}
else{
    fprintf(fp,"%d %s",123,"abc");
}
```

Dosya varken program çalıştırılınca "Dosya yok" yazmadı. Dosyanın içine bakıldığında yine `123abc` yazılmış görüldü. Hoca bunu, arka planda `fprintf` görülünce dosyanın yazma moduna çevrilmesine bağladı ve normalde Linux gibi sistemlerde bunun yapılmayacağını, hata alınacağını söyledi. Doğrusu, hangi işlem yapılacaksa o kipi kullanmaktır.

> **Ders sonrası not:** C standardına göre `"r"` kipinde açılmış bir akışa yazma işlemi başarısız olur (tanımsız davranış ya da hata). Derste görülen sonuç büyük olasılıkla o ortama özgüdür; okuma kipinde yazmaya güvenilmemelidir.

## 8. Okuma ve Yazma Yöntemleri

Dosya açıldıktan sonra dosya işaretçisiyle okuma ve yazma yapılır. Temel yöntemler:

- Karakter okumak/yazmak: `getc`, `putc`, `fgetc`, `fputc`.
- Satır okumak/yazmak: `fgets`, `fputs`.
- Blok okumak/yazmak: `fread`, `fwrite`.

Hepsinin kendine göre faydaları ve zararları vardır. Temel ilke şudur: dosya nasıl yazıldıysa öyle okunur. Örneğin tek bir karakter (bir bayrak değişkeni gibi) anlamlıysa tek karakter okunur ya da okunan şeyden ayrıştırılıp alınır. Elinizde bir yapı varsa veriler tek bir blok olarak okunabilir. Yöntem probleme göre seçilir.

### 8.1 Bütün G/Ç seviyeleri için kural

Slayttaki kural (ekrandan, 01:15:00): bir akıştan okunduktan sonra araya `fseek()`, `rewind()` ya da `fflush()` çağrısı girmeden o akışa yazılamaz. Yazmadan okumaya geçerken de aynı kural geçerlidir. Bu üç fonksiyon tamponları boşaltan (flush) tek G/Ç fonksiyonlarıdır. İlk ikisi konum göstergesinin yerini değiştirir; `fflush` akışı temizler.

Bellek sıkıntısı yoksa girdi akışından okunup çıktı verisi bellekte kurulabilir ve en sonunda çıktı akışına yazılabilir. Girdi ve çıktı akışları aynı dosyayı gösterebilir; ama bu durumda okunan dosya, ona yazmadan önce kapatılmalıdır. Dosya `fclose(fp)` ile kapatılır.

Genel akış: dosya açılır, ikili mi metin mi olduğu ayarlanır, satır satır, karakter karakter ya da blok blok okuma ve yazma yapılır, gerektiğinde tampon `fflush` ile temizlenir.

## 9. Karakter G/Ç

### 9.1 İkili kipte karakter karakter kopyalama

Slayttaki `copyfile` fonksiyonu bir dosyayı ikili kipte karakter karakter başka bir dosyaya aktarır. İkili kipte, daha önce gösterilen anlamsız karakterlerin her biri yine birer karakterdir.

- Bir girdi, bir de çıktı dosyası için iki dosya işaretçisi vardır; çünkü birinden alınıp öbürüne yazılacaktır. İki kanal açılır.
- Girdi dosyası okuma (`"rb"`), çıktı dosyası yazma (`"wb"`) için açılır.
- `feof(fp1)` dosyanın sonuna gelinip gelinmediğini söyler. Döngü sona gelinene kadar sürer.
- `fp1`'in gösterdiği yerden bir karakter alınır (istenirse bir değişkende tutulur) ve `putc` ile `fp2`'ye yazılır.
- Sonunda iki dosya kapatılır ve başarı değeri döndürülür.

Bu işlemde her karakter sabit diskten RAM'e getirilir, sonra RAM'den diske yazılır; sürekli git-gel yapılır. `main` içinde girdi ve çıktı dosyalarının adları kullanıcıdan alınır, sonuca göre başarılı ya da başarısız yazılır.

Döngü koşulu `getc`'nin dönüş değerini `EOF` ile karşılaştırarak da yazılabilir; ama hoca araya yanlışlıkla `EOF` değerinde bir karakter girerse programın erken durabileceğini, `feof`'un ise dosya sonuna erişilip erişilmediğini kesin olarak söyleyen fonksiyon olduğunu belirtti. Koddaki açıklama da aynısını söyler (ekrandan, 02:15:00): dosya ikili kipte açıldığı için `while ((c = getc(fp1)) != EOF)` döngüsü, okunan karakter `EOF` ile aynı değere sahip olduğu anda biter; bu ikili dosyalarda gerçek bir dosya sonu olmayabilir; `feof()` ise sona ulaşılıp ulaşılmadığını tam olarak verir.

### 9.2 Makro ve fonksiyon sürümleri

Karakter G/Ç için dört fonksiyon vardır (ekrandan, 01:20:00):

- `getc()`: akıştan bir karakter okuyan makro.
- `fgetc()`: `getc()` ile aynı, ama fonksiyon olarak gerçekleştirilmiş.
- `putc()`: akışa bir karakter yazan makro.
- `fputc()`: `putc()` ile aynı, ama fonksiyon olarak gerçekleştirilmiş.

`getc` ve `putc` genellikle makro, `fgetc` ve `fputc` ise kesin olarak fonksiyondur. Makrolarda yerine koyma yapıldığı, fonksiyona dallanma olmadığı için `getc`/`putc` genellikle çok daha hızlı, yaklaşık iki kat hızlıdır.

Ancak makro oldukları için yan etki sorununa açıktırlar. Hoca bunu `SQUARE(x)` makrosuyla hatırlattı: `x*x` biçiminde tanımlanınca `SQUARE(5)` 25 verir, sorun yoktur; ama `SQUARE(3+2)` açılınca `3+2*3+2` olur ve sonuç 11 çıkar. Slayttaki tehlikeli çağrı `putc('x', fp[j++]);` biçimindedir. Argümanda yan etkili işleç varsa kesin olarak fonksiyon olan `fgetc()` ya da `fputc()` kullanılmalıdır. Fonksiyon çağrısında ise önce argümanlardaki işlemler (örneğin `x++`) yapılır, sonra fonksiyon çağrılır.

`SQUARE` makrosu `#define SQUARE(x) x*x` olarak `gcc -Wall` ile denendi: `SQUARE(5)` 25, `SQUARE(3+2)` 11 verdi.

## 10. Satır G/Ç

Metin kipinde okuma yazmada metin dosyada açık biçimde saklanır. Slayttaki satır satır kopyalama örneğinde dosyalar açılır ve `fgets` ile okunur:

- Okunan satırın konacağı yer `line` dizisidir. Bu dizinin boyutu önceden bellidir (örnekte sabit bir `LINESIZE`); program çalışırken büyütülemez. Dinamik olması istenirse `malloc` ile ayrılmalıdır.
- `fgets(line, LINESIZE - 1, fp1)`: dosyadan en çok bu kadar karakter okunur. Satırın sonundaki `'\n'` de okunana dahildir. Okunan karakterler `line` içine aktarılır ve sonuna `'\0'` eklenir.
- Okuma `NULL` dönmediği sürece sürer; okunan satır `fputs(line, fp2)` ile ikinci dosyaya yazılır. Sonunda dosyalar kapatılır.

`fgets`'in özellikleri:

- `char *` döndürür; bu yüzden sonucu bir karakter işaretçisinde tutmak gerekir.
- Üç argüman alır: nereye yazılacağı, en çok ne kadar okunacağı ve hangi dosyadan okunacağı.
- Dosya sonuna, yeni satır karakterine ya da en çok karakter sayısına ulaşınca durur ve okunanın sonuna string sonu karakterini (`'\0'`) koyar.
- Dosyanın sonuna ulaşılmışsa `NULL`, aksi halde ilk argümanı döndürür.

`fputs` daha basittir: yazılacak metin ve dosya verilir.

`fgets`'te dosya işaretçisi yerine `stdin` verilirse dosyadan değil klavyeden okunur. Hoca daha önce `scanf` ile her zaman string almak mümkün olmadığı için bunun önerildiğini hatırlattı. `gets` de aynı işi sabit olarak `stdin` üzerinden yapar.

## 11. Blok G/Ç

### 11.1 Neden blok okuma?

Akışlar aslında RAM ile sabit disk arasında bir köprü kurar. RAM çok hızlıdır. Hoca sabit diskin dönüş hızını örnek verdi: 7200 RPM (dakikadaki devir) saniyede $7200 / 60 = 120$ devir demektir, yani kabaca 120 Hz; buna karşılık RAM MHz düzeyinde çalışır. Aradaki fark çok büyüktür. Program diske karakter oku, karakter yaz diye sürekli git-gel yaparsa gecikmeler oluşur. Bunun yerine mümkün olduğunca diskten bir seferde en fazla veriyi okumak ya da yazmak en iyisidir. Bunun için blok G/Ç kullanılır.

Örneğin bir öğrenci yapısında kimlik, ad, soyad, yaş gibi alanlar varsa bunları tek tek yazmak yerine yapı değişkeni olduğu gibi, bütün olarak yazdırılabilir ya da okunabilir. Ancak blok okuma yapıldığı için yazılacak ve okunacak verinin biçimine çok dikkat etmek gerekir: yapıda önce kimlik, sonra ad, sonra soyad girildiyse dosyaya da o sırayla yazılır ve öyle okunmalıdır.

### 11.2 fread ve fwrite

Her ikisi de dört şey ister: veri nereye okunacak (ya da nereden yazılacak), bir elemanın boyutu, kaç eleman okunacak/yazılacak ve hangi dosya. İlk argüman `void *` türündedir; bu yüzden yapı, string ya da başka herhangi bir şeyin adresi verilebilir.

Slayttaki açıklamalar (ekrandan, 01:30:00):

- `fread()` gerçekten okunan eleman sayısını döndürür. Hata ya da EOF durumu yoksa bu, 3. argümana eşit olmalıdır.
- `fwrite()` `fread()`'in aynasıdır; aynı argümanları alır, ama elemanları akıştan diziye okumak yerine diziden akışa yazar.
- Boyut genelde `sizeof` ile verilir: bir öğrenci yapısının boyutu kadar veri yaz, bir kere yaz, iki kere yaz gibi.
- `fread()` ve `fwrite()`'taki blok boyutları aygıt G/Ç işlemlerinin sayısını etkilemez. Örneğin tampon boyutu 1024 bayt, okuma isteğindeki blok 512 bayt olsun. İşletim sistemi yine diskten 1024 bayt getirip bellekte tutar; `fread()`'e yalnız ilk 512 bayt verilir. Sonraki `fread()` çağrısında işletim sistemi kalan 512 baytı diske yeniden gitmeden bellekten getirir.

### 11.3 Blokla kopyalama

Slayttaki blok kopyalama örneğinde blok boyutu (`BLOCKSIZE`) 512 olarak tanımlanmıştı. Girdi ve çıktı dosyaları açılır, `block` adlı bir karakter dizisine `fread` ile okunur: bir elemanın boyutu `sizeof(DATA)` (bir karakter), eleman sayısı `BLOCKSIZE` olduğundan bir seferde 512 bayt gelir. Okunan blok aynı biçimde `fwrite` ile ikinci dosyaya yazılır ve bu iş sürer. Okuma ya da yazma sırasında hata olursa bu, dosya işaretçisi üzerinden anlaşılır ve `FAIL`, iş tamamlanırsa `SUCCESS` döndürülür.

## 12. Rastgele Erişim: fseek ve ftell

### 12.1 Kavram

Bir blok okununca imleç bloğun bittiği yerde bekler. Rastgele erişimde imleç programcı tarafından ayrıca yönlendirilir. Hoca bunu eski teyplere benzetti: ileri sarma, geri sarma. Bu işi `fseek` yapar; `ftell` ise bulunulan konumu söyler.

`fseek(fp, offset, kaynak)` biçimindedir. Başlangıç noktası (kaynak) şu bayraklardan biridir; bunlar `stdio.h` içinde tanımlıdır:

- `SEEK_SET`: dosyanın başı.
- `SEEK_CUR`: bulunulan yer.
- `SEEK_END`: dosyanın sonu.

Offset, başlangıç noktasından ne kadar gidileceğini söyler: 5 ileri git, 3 geri git gibi. İkili dosyada genellikle bayt cinsindendir; metin dosyasında 0 olabilir ya da `ftell` ile alınmış bir değer kullanılabilir.

### 12.2 Örnek ve kurallar

Slayttaki örnek (ekrandan, 01:35:00): `stat = fseek(fp, 10, SEEK_SET);`

- Dosya konum göstergesini akışın 10. karakterine götürür; sıradaki okuma ya da yazma bu karakterden yapılır.
- Akışlar da diziler gibi 0. konumdan başladığı için 10. karakter aslında akıştaki 11. karakterdir.
- İstek geçerliyse `fseek` 0, değilse 0'dan farklı bir değer döndürür. Dosyada yeterli karakter olmaması gibi çeşitli nedenler buna yol açabilir. Örneğin `fp` salt okuma için açılmışsa `stat = fseek(fp, 1, SEEK_END)` geçersizdir, çünkü göstergeyi dosya sonunun ötesine taşımaya çalışır.
- Salt okunur dosyalarda `SEEK_END` kullanılırsa offset 0'dan küçük ya da 0'a eşit olmalıdır: zaten sondasınız; ya bulunduğunuz yeri okursunuz ya da geriye gidersiniz.
- Benzer şekilde `SEEK_SET` kullanılırsa offset 0'dan büyük ya da 0'a eşit olmalıdır: zaten baştasınız.
- Konum göstergesi dosyanın dışına itilmemelidir; bu hata verir.

`ftell` dosya konum göstergesinin bulunduğu konum numarasını döndürür ve daha çok `fseek` ile birlikte kullanılır.

`fseek(fp, 10, SEEK_SET)` küçük bir testle denendi: `abcdefghijklmnop` içeren dosyada `fseek` 0 döndürdü, `ftell` 10 verdi ve okunan karakter 11. harf olan `k` oldu.

### 12.3 Rastgele erişim örneği: kayıtları isme göre sıralamak

Slayttaki örnekte daha önceki haftalarda kullanılan kişi bilgisi yapısı (`PERSONALSTAT`: ad, kimlik numarası, bit alanlı doğum tarihi) vardır. Dosyada rastgele sırada beş kayıt bulunur; amaç bunları isme göre alfabetik sırada yazdırmaktır. Hocaya göre burada her karşılaştırmada dosyaya git-gel yapmak yerine verileri blok halinde getirmeye bakılır. Bütün kaydı saklamak yerine (anahtar, indeks) çiftleri saklanır.

Önce kayıtlar dosyaya yazılır: dosya ikili kipte yazma için açılır, `PERSONALSTAT` türünden dört elemanlı bir dizi oluşturulur ve her kişinin adı, kimlik numarası ve doğum tarihi kullanıcıdan alınır. Doğum tarihi alanları bit alanı olduğu için doğrudan `scanf` ile okunamaz; önce ayrı bir değişkene okunup sonra atanır. Sonra tek `fwrite` ile `sizeof(PERSONALSTAT)` kadar veri, yani bir kaydın bütün alanları bir seferde dosyaya yazılır.

İsimleri okuyan fonksiyon (ekrandan, 01:40:00):

```c
/* Reads up to max_rec_num records from a file and stores the key field of each record in an index
array. Returns the number of key fields stored. */
int get_records(FILE* data_file, INDEX names_index[], int max_rec_num){
   int offset = 0, counter = 0, k, nm = NAME_LEN;
   char namei[NAME_LEN];

   // get only the name of the 1st PERSON: (the first 19 chars is for name field)
   nm=fread(namei, 1, NAME_LEN, data_file);
   for (k = 0; counter < max_rec_num && nm== NAME_LEN; k++){
      strcpy(names_index[k].key, namei);
      // jump into the beginning of the next person's (next record's) starting point:
      offset += sizeof(PERSONALSTAT);
      fseek(data_file, offset, SEEK_SET);
      counter++;
      // get only the name of the i-th PERSON: (the first 19 chars for each person/record)
      nm=fread(namei, 1, NAME_LEN, data_file);
   }
   return counter;
}
//to be continued in the next slide
```

Hoca bunu şöyle anlattı: kayıt yalnız isimden oluşmaz; isim alanı `NAME_LEN` kadardır. Önce bu kadar veri okunur. Sonra offset bir kayıt boyutu (`sizeof(PERSONALSTAT)`) kadar artırılır ve `fseek` ile dosyanın başından itibaren o konuma gidilir. Orada bir isim daha okunur; sonraki adımda offset iki kayıt boyutuna, sonra üçe çıkar. Böylece bütün isimler indeks dizisine (`INDEX` yapısı: `key` ve kaydın indeksi) aktarılır.

Ardından isimler `strcmp` ile karşılaştırılarak sıralanır (örnekte quicksort ile). Sıralı indeksler yazdırılırken her indeks için `fseek` ile dosyanın başından `sizeof(PERSONALSTAT) * indeks` kadar ileri gidilir, `fread` ile bir `PERSONALSTAT` kaydı okunur ve adı, doğum tarihi gibi bilgileri ekrana yazdırılır. `main` içinde önce kayıtlar alınır, sonra sıralanır, sonra sıralı hali yazdırılır ve dosya kapatılır. Hoca bu örneğin yazılıp denenmesini, rastgele erişimin önemli olduğunu söyledi.

<!-- BELİRSİZ: Sıralama ve yazdırma fonksiyonlarının kodu ekranda okunmadı; bu kısım altyazıdan anlatılmıştır. -->

## 13. Dosya Yönetim Fonksiyonları

İşletim sisteminde, sabit diskte bir dosyayı silmek, adını değiştirmek, geçici bir dosya oluşturmak ya da geçici dosya için ad üretmek istenebilir. Slayttaki fonksiyonlar (ekrandan, 01:45:00):

- `int remove(const char* szFileName);` dosyayı siler.
- `int rename(const char* szOldFileName, const char* szNewFileName);` dosyanın adını değiştirir.
- `FILE* tmpfile();` geçici bir ikili dosya oluşturur.
- `char* tmpnam(char caName[]);` geçici dosyanın adı olarak kullanılabilecek bir string üretir. `\` gibi güvensiz karakterler döndürebileceği için temizlenmesi gerekir.

Hoca bunların yanında klasör oluşturma gibi fonksiyonların da bulunduğunu söyledi.

## 14. void İşaretçiler

`void` işaretçi, istenen türde işaretçiye dönüştürülebilen (cast edilebilen) bir işaretçi türüdür. Bu sayede genel (generic) fonksiyonlar yazılabilir. Örneğin bir fonksiyon ekrana bir şey bastıracak; tamsayı mı karakter mi basılacağı bilinmiyorsa parametre `void *` türünde alınır ve fonksiyonun içinde türüne göre işlenir.

`malloc` da bu yüzden `void *` döndürür. Hoca bunu `(TUR *) malloc(n * sizeof(TUR))` yazımıyla hatırlattı: dönen adres istenen türün işaretçisine dönüştürülür.

Örnekte tek bir `void *ptr` vardı ve sırayla bir `int`, bir `float` ve bir `char` değişkeninin adresine yöneltildi:

- `ptr` `int` değişkenin adresini gösterince, değere ulaşmak için önce `int *` türüne dönüştürülür: `*(int *)ptr = 10;` Yazdırınca 10 görülür.
- Sonra `ptr` `float` değişkenini gösterir. Normalde bir işaretçiyi başka türden bir değişkene yöneltmek hata verir; ama `void *` olduğu için yapılabilir. Değer `*(float *)ptr = 3.4;` ile yazılır.
- Sonra `ptr` `char` değişkenini gösterir ve `*(char *)ptr` ile kullanılır.

Hoca slayttaki örnekte işaretçi adının bir yerde `pt`, bir yerde `ptr` yazıldığını, doğrusunun `ptr` olduğunu belirtti. Ayrıca değerin yazdırılırken de aynı biçimde dönüştürülerek okunabileceğini gösterdi.

Bu mantık `void *` ile `int`, `float` ve `char` değişkenleri kullanan küçük bir programla `gcc -Wall` altında denendi; çıktılar 10, 3.400000 ve verilen karakter oldu.

Hoca `void *`'ın thread'lere parametre gönderirken de kullanıldığını söyledi: gönderilen şey `void *` ile aktarılır ve alınan veri kendi türümüze dönüştürülür.

## 15. Dosya Kopyalama Örneklerinin Çalıştırılması

### 15.1 stderr ile hata bildirimi

Dosya açan iki yardımcı fonksiyon gösterildi (ekrandan, 01:50:00):

```c
#include <stddef.h>
// Returns a pointer to FILE struct:
FILE *open_file1() {
  FILE *fp;
  if ((fp = fopen( "test","r" )) == NULL)
    fprintf( stderr, "Error opening file test\n" );
  return fp;
}
FILE *open_file2(char* file_name, char* access_mode){
  FILE *fp;
  if ((fp = fopen(file_name, access_mode)) == NULL)
    fprintf( stderr, "Error opening file %s with access mode %s\n", file_name, access_mode);
  return fp;
}
```

İkinci fonksiyonun hata satırının sonu ekranda kesik görünüyordu; aynı kodun başka bir düzenleyicideki görüntüsünde (ekrandan, 02:55:00) satır `file_name,` ile devam ediyor. `main` içinde dosya adı ve kip kullanıcıdan alınır ve `open_file2(flnm, mode)` `NULL` dönerse program kapatılır. Hoca bir dosya adı ve `r` kipi verdi: çalışma klasöründe o adda dosya olmadığı için hata mesajı `stderr` kanalından gönderildi ve program kapandı. Aynı ad `w+` kipiyle verilince dosya açıldı, çünkü bu kip dosya yoksa oluşturur.

### 15.2 Karakter karakter kopyalama

İkinci arada sonra hoca karakter karakter ve satır satır okuma kodlarını çalıştırdı. Karakter karakter sürümde okunacak ve yazılacak dosya adları alınıp kopyalama fonksiyonuna gönderilir; dosyalar açılır, dosya sonuna gelinip gelinmediği kontrol edilir, `fp1`'den bir karakter alınıp `fp2`'ye gönderilir. Derste bir C kaynak dosyası yeni bir dosyaya kopyalandı ve içerik birebir kopyalandı; ancak kopyanın sonunda fazladan anlamsız bir karakter görüldü. Hoca bunun dosya okumalarında olabilecek bir durum olduğunu, bu tür bir problemde karakter karakter okumanın git-gel yüzünden kullanışlı olmadığını söyledi.

> **Ek bilgi (derste anlatılmadı):** Fazladan karakter büyük olasılıkla `while (!feof(fp))` kalıbından kaynaklanır: `feof` ancak bir okuma dosya sonuna çarptıktan sonra doğru olur. Son okumada `getc` `EOF` döndürür ve bu değer kontrol edilmeden `putc` ile yazılırsa kopyanın sonuna fazladan bir bayt (genelde 255) eklenir. Okunan değeri yazmadan önce `EOF` olup olmadığına bakmak bunu önler.

### 15.3 Satır satır kopyalama ve okuma sayısı

`copyfilev2` sürümünde `fgets` ile `line` değişkenine en çok satır boyutu kadar karakter `fp1`'den okunur, dosya sonuna gelene kadar her satır `fputs` ile `fp2`'ye yazılır. Hoca fonksiyona bir sayaç (`int x = 0;` ve her okumada `x++`) ekledi ve `SUCCESS` yerine `x`'i döndürerek okumanın kaç kez yapıldığını yazdırdı (ekrandan, 02:15:00 ve 02:20:00). İlk denemede 35 okuma görüldü. Satır boyutu büyütülünce sayı değişmedi; hoca bunun dosyanın satırlarına bağlı olduğunu, satırlar zaten sığıyorsa daha büyük boyutun fark etmeyeceğini söyledi. Boyut küçültülünce (örneğin 20) okuma sayısı arttı; yani daha fazla git-gel, daha fazla emek harcandı.

### 15.4 Blok kopyalama

`copyfilev3` sürümünde ekrandaki başlangıç kısmı şöyledir (ekrandan, 02:20:00):

```c
int copyfilev3(char * infile, char * outfile){

  FILE *fp1, *fp2;
  int num_read;
  char block[BLOCKSIZE];
  if ((fp1 = fopen( infile, "rb" )) == NULL){
    printf( "Error opening file %s for input.\n", infile );
    return FAIL;
  }
  if ((fp2 = fopen( outfile, "wb" )) == NULL){
    printf( "Error opening file %s for output.\n", outfile );
    fclose(fp1);
    return FAIL;
  }
```

Dosyalar açıldıktan sonra `block`'a `fread` ile, eleman boyutu `sizeof(DATA)` ve eleman sayısı `BLOCKSIZE` olacak şekilde okunur; yani 1 × 512 bayt. Hoca `block`'un burada bir karakter dizisi olduğunu, ama başka bir şey de olabileceğini vurguladı. Dizi adı zaten bir işaretçi olduğu için ayrıca `&` yazılmaz; ama bir öğrenci yapısı kullanılsaydı o yapının adresi verilmeliydi. `fwrite`'ın ilk parametresi `void *` türündedir, yani herhangi bir şeyin işaretçisi gönderilebilir. Okunan blok yazılır ve dosyalar kapatılır. Blok karakter türünde olduğu için sonuç metin kopyalar gibi görünür, ama okunan her şey ikili kipte alınıp yazılır.

<!-- BELİRSİZ: copyfilev3'ün döngü kısmı ekranda görülmedi; fread/fwrite çağrısı altyazıdan anlatılmıştır. -->

## 16. Programın Bellek Düzeni

Hoca öğrencilerin program yazarken yapı dizisi oluşturma ve `malloc` kullanma konusunda zorlandığını, bunun için belleğin nasıl yönetildiğini bilmek gerektiğini söyledi ve bir kitaptan (Türkçe kaynağını bulduğu) bir şekil üzerinden anlattı.

Program çalıştırıldığında bellekte ona şu bölgelerden oluşan bir alan ayrılır (düşük adresten yükseğe):

- Programın kodu (en düşük adres).
- İlk değer atanmış global ve statik değişkenler (initialized data).
- İlk değer atanmamış global ve statik değişkenler (uninitialized data).
- Heap.
- Stack (yığın).
- Komut satırından gönderilen argümanlar.

**İlk değerli ve ilk değersiz veri:** Global alanda `int x = 5;` gibi yazılan değişken ilk değer atanmış ve globaldir; initialized data bölgesindedir. Fonksiyon içinde `int e = 9;` yazılırsa bu initialized data değildir (yerel değişkendir). Ama fonksiyon içinde `static int e = 9;` yazılırsa yine initialized data kapsamına girer. İlk değeri verilmemiş global ve statik değişkenler ayrı bir bölgede tutulur. Hoca bu ayrımı statik değişkenin davranışına bağladı: statik değişkene fonksiyon ilk çağrıldığında bir kez ilk değer atanır, sonraki çağrılarda atanmaz ve kaldığı değerden devam eder.

**Stack:** Programa verilen bellek bölgesinin stack kısmı çağrılar oldukça genişler. Burada fonksiyonların yerel değişkenleri (tamsayı, karakter vb.), fonksiyona geçirilen parametreler ve fonksiyonun dönüş adresi saklanır. Dönüş adresi, fonksiyon bitince programın nereye döneceğidir: `main` içinde `f` çağrılırsa, `f` bitince `main`'de kalınan yerden devam edilir. Yerel bir yapı değişkeni, dinamik olmayan bir tamsayı ya da karakter dizisi de stack'tedir.

**Heap:** `malloc`, `realloc` ile oluşturulan dinamik diziler ve yapılar heap bölgesinde saklanır ve `free` ile serbest bırakılmaları gerekir. `free`, oranın kullanımını serbest hale getirir; oradaki değerler silinmez.

Şekildeki örnekte de global ve statik değişkenlerin ilk değerli ya da ilk değersiz segmentlerde, `malloc` ile alınan alanın heap'te, `main`'in yerel değişkeninin stack'te tutulduğu gösterildi.

> **Hocanın vurgusu:** Bilgisayar mühendisi, herhangi bir programlama dilinde yazılmış bir programın belleği nasıl kullandığını çok iyi bilmelidir. Bu yapıyı gözünüzün önüne getirmeniz gerekir.

### 16.1 Yer ayırmadan işaretçiye okuma

Hoca sık yapılan hatayı anlattı: yer açılmadan bir yer gösterilmeye çalışılıyor ya da açılmamış bir yere dosyadan veri okunmaya çalışılıyor. "Dosyadan okuyorum" denince "nereye okuyacaksın?" sorusu gelir; açılan işaretçi henüz belli bir yeri göstermez.

Derste yazılan örnek (ekrandan, 02:25:00):

```c
struct ogr Ogr=malloc(N*sizeof(struct ogr));

struct ogr *ptr;
fread(ptr,sizeof(struct ogr),1,fp);
```

`fread`'in yazımı doğrudur: `ptr`'ye, bir `struct ogr` boyutunda, bir kez, `fp`'den oku. Ama `ptr`'nin gösterdiği hedef henüz herhangi bir bellek adresi değildir; bu şekilde olmaz. İşaretçinin önce bir yere erişmesi gerekir; en basit yol, `malloc` ile oluşturulan alanı işaretçiye vermektir.

> **Ders sonrası not:** Ekranda `struct ogr Ogr=malloc(...)` yazıyor; `malloc` bir adres döndürdüğü için doğrusu `struct ogr *Ogr = malloc(N * sizeof(struct ogr));` biçimidir. Hoca da anlatırken "tabii şurada da pointer olacak" dedi.

Burada iki bellek bölgesi kullanılır: veriyi fiziksel olarak saklayan alan heap'tedir; `Ogr` değişkeni ise stack'te bir işaretçidir ve heap'teki alanın adresini tutar. Bunu bir referans gibi düşünmek mümkündür. Dizilere eleman okurken atamalar bu yüzden yapılır: `malloc` normal bir dizi döndürmez, dizinin başlangıç adresini döndürür; ilgili alanlara işaretçi aritmetiğiyle erişilir.

## 17. Makefile ve Derleme Otomasyonu

### 17.1 IDE derlerken ne yapar?

Hoca Dev-C++'ın derleme günlüğünü gösterdi. Tek bir dosya derlenirken ("Compiling single file") IDE, `gcc`'ye kaynak dosyayı verip önce nesne (object) dosyasını oluşturur, sonra `-o` ile çalıştırılabilir dosyayı (`.exe`) üretir; araya optimizasyonla ilgili bazı bayraklar ve bağlanacak kütüphaneler girer.

Sonra yeni bir proje oluşturdu (Console Application, C). Projeye bir `.c` dosyası ve bir başlık (`.h`) dosyası ekleyip programı modüler hale getirdi. Proje derlenince günlükte "Compiling project changes", "Building makefile" ve "Processing makefile" satırları görüldü: IDE bir Makefile oluşturdu ve `make` programını bu dosyayla çalıştırdı; o da dosyaları tek tek derleyip proje `.exe`'sini oluşturdu. Derste başka dosyadaki fonksiyon `main`'den çağrılınca "undefined reference" hatası alındı ve hoca bunun projeyle ilgili bir sorun olabileceğini söyleyip devam etti.

### 17.2 Makefile neden gerekli?

Bir projede 20 tane C dosyası ve birçok başlık dosyası olabilir. Her seferinde uzun uzun `gcc` komutlarıyla her birini ayrı ayrı derlemek mantıklı değildir. Ayrıca bir dosyada değişiklik yapıldığında değişmeyen 19 dosyayı yeniden derlemeye gerek yoktur. Makefile bir kez yazılır ve yapılacak işler tek komutla yeniden çalıştırılır.

Slayttaki örnekte `data.c`, `data.h`, `main.c`, `io.h`, `io.c` dosyaları vardı. Proje `data.o`, `main.o` ve `io.o`'dan oluşur: `gcc` bu üç nesne dosyasını alıp `-o` ile `project1` çalıştırılabilir dosyasını oluşturur. `data.o`, `data.c` ve `data.h`'den; `main.o` `main.c`'den; `io.o` `io.c`'den `gcc -c` ile derlenerek oluşur. Her hedef bir makro gibi tanımlanır; önce `data.o`, sonra `main.o`, sonra `io.o` yapılır ve en son proje bağlanır.

### 17.3 Elle Makefile yazmak

Komut satırından `gcc`'nin çalışması için, derleyicinin bulunduğu `bin` klasörü ortam değişkenlerindeki `PATH`'e eklenmelidir (Gelişmiş Sistem Ayarları, Ortam Değişkenleri; biri kullanıcı, biri sistem değişkenidir). Dev-C++ ile kurulan MinGW64'ün `bin` klasöründe hem `gcc` hem `make` bulunur. Bu klasör bir kez tanıtılınca komut satırının her yerinden `gcc` yazılabilir.

Hoca `Makefile.win` adlı bir metin dosyası açıp kendi Makefile'ını yazdı. Makefile doğrudan C ile ilgili değildir; başka diller için de yazılabilir. Ekrandaki ara hal (ekrandan, 02:45:00):

```make
programcalistir: program calistir

program: deneme.o main.o
    gcc deneme.o main.o -o program.exe
deneme.o:
    gcc -c deneme
main.o:
    gcc  -c
```

Hoca anlatırken kuralları şöyle tamamladı: `deneme.o` için `gcc -c deneme.c -o deneme.o`, `main.o` için `gcc -c main.c -o main.o`; `calistir` hedefi de `program.exe`'yi çalıştırır.

<!-- BELİRSİZ: Makefile'ın son hali ekranda tam görülmedi; tamamlanan satırlar altyazıdan kuruldu. -->

> **Ek bilgi (derste anlatılmadı):** Makefile'da komut satırları boşlukla değil sekme (Tab) karakteriyle başlamalıdır. Ayrıca `deneme.o: deneme.c deneme.h` gibi bağımlılıklar yazılmazsa `make` kaynak dosyanın değiştiğini anlayamaz ve hedefi yeniden derlemez.

`make` bu dosyayı şöyle işler: iki nokta tanım demektir. Önce `programcalistir` hedefine bakar; bu `program` ve `calistir`'dan oluşur. `program`'ın `deneme.o` ve `main.o`'dan oluştuğunu görür; önce `deneme.o`'nun komutunu, sonra `main.o`'nunkini çalıştırır, sonra bağlama yapar. Ardından `calistir` ile oluşan `.exe` çalıştırılır.

Komut satırında Dev-C++ ile gelen `make` programı `-f` seçeneğiyle bu dosyayla çalıştırıldı. <!-- BELİRSİZ: Altyazıda programın adı "1032 make.exe" diye geçiyor; büyük olasılıkla `mingw32-make.exe`. --> İlk denemede dosya kaydedilmediği için çalışmadı; kaydedince önce `gcc -c` ile `deneme.o`, sonra `main.o` oluştu, `program.exe` bağlandı ve çalıştırıldı, sonuç ekranda görüldü.

Sonra yalnız `deneme.c`'de değişiklik yapıldı (bir `\n` eklendi) ve aynı komut çalıştırıldı. Bu kez yalnız `deneme.o` yeniden derlendi; `main.c` değişmediği için `main.o` derlenmedi. Hoca bunun nedenini bağımlılık grafiği (dependency graph) ile açıkladı: büyük bir projede yalnız düzenlenen dosyaya bağlı olanlar yeniden derlenir, bütün proje baştan derlenmez ve iş tek satırlık bir `make` komutuyla yapılır.

> **Hocanın vurgusu:** IDE'ler bu işi sizin adınıza yapar; ama düşük seviyeli programlamada, gömülü sistemlerde ya da robotik gibi alanlarda Makefile yazıp derlemek karşınıza çıkacaktır.

### 17.4 Dev-C++'ın ürettiği Makefile

Hoca Dev-C++'ın kendi Makefile'ını açtı. Bu dosya işi daha profesyonel yapar:

- Önce makrolar tanımlanır: `CPP`, `CC`, `WINDRES` ne yerine yazılacak; `OBJ` yerine `main.o`, `LINKOBJ` yerine nesne dosyaları; kütüphane ve başlık yolları (her seferinde ortam değişkenlerine güvenmek yerine dosyanın içine yazılır).
- Bütün proje `all-before`, proje `.exe`'si (binary) ve `all-after` adımlarından oluşur.
- `clean` hedefi daha önce oluşturulan her şeyi siler (`rm.exe` ile). Bu değiştirilirse yalnız düzenlenen dosyalar yeniden derlenir.
- `Project1.exe` hedefi nesne dosyalarından bağlanır; `main.o` hedefi `CC` (yani `gcc`) ile `main.c`'den `-c` ile derlenir ve bazı bayraklar (örneğin `-g3`) eklenir. Hoca bayrakların derlemedeki optimizasyon ve hata ayıklama ayarları olduğunu, bu derste ayrıntısına girilmediğini söyledi.
- Burada `all-after` için herhangi bir komut yazılmamıştır; gerekirse ayrıntılandırılabilir.

### 17.5 CMake

Makefile'ın sorunu derleyiciye ve ortama göre farklılaşmasıdır: Dev-C++/MinGW için bir biçim, Clang gibi başka derleyiciler için başka biçim gerekir. Daha genel ve başka dillere de uygulanabilen araç CMake'tir. CMake, hangi IDE'de çalışılırsa çalışılsın kodu derleme, bağlama ve çalıştırılabilir dosya oluşturma işini yapan bir derleme otomasyonu (build automation) aracıdır.

Hoca basit bir CMake örneğini anlattı: CMake'in en düşük sürümü, projenin adı ve `merhaba_dunya.cpp`'den `merhaba` adlı çalıştırılabilir dosya oluşturan komut. Birden fazla kaynak dosya varsa aralarına eklenerek verilir. Daha genel bir örnekte proje, belirli klasörlerdeki kaynaklardan oluşuyor, çalıştırılabilir dosyanın adı belirleniyor, C++ standardı seçiliyor ve proje bir yere kuruluyordu (install).

Hocaya göre CMake, ekip çalışmasında özellikle işe yarar: bir projenin parçalarını farklı kişiler yapıp ortak bir depoya (örneğin GitHub) yükler; biri Dev-C++'ta, biri Xcode'da, biri başka bir ortamda çalışsa da herkes kendi arayüzünden tek bir komutla ortak projeyi ayağa kaldırıp derleyebilir. Hoca Makefile mantığını öğrenince CMake'in daha basit geleceğini, yazılım üzerinde çalışacaklara her zaman basit IDE'ler verilmeyeceğini söyledi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:19:47): $x^y$'yi döngüyle $O(n)$ sürede hesaplayan bilinen algoritmadan daha hızlı hesaplayan bir kod nasıl yazılır?

> **Çözüm (derste verildi, ekrandan, 00:25:00):** $x^{y/2}$ bir kez özyinelemeyle hesaplanıp bir değişkende tutulur. Kuvvet çiftse bu değerin karesi, tekse karesi çarpı $x$ döndürülür (`power4`). $T(n) = T(n/2) + 1$ olduğundan karmaşıklık $O(\log n)$'dir. $x^{y/2}$'yi iki ayrı çağrıyla hesaplamak (`power3`) ise $T(n) = 2T(n/2) + 1$ ile yine $O(n)$ verir.

**Soru 2** (ekrandan, 00:25:00): Aşağıdaki fonksiyonun özyineleme bağıntısı ve karmaşıklığı nedir?

```c
int power4(int x, int y){
    int result;
    if(y == 0)
        return 1;
    result = power4(x,y/2);
    if(y % 2 == 0)
        return result*result;
    else
        return x*result*result;
}
```

> **Çözüm (derste verildi):** Her çağrıda bir özyinelemeli çağrı ve sabit iş vardır: $T(n) = T(n/2) + 1$. Ana teoremde $a = 1$, $b = 2$, $d = 0$; sonuç $O(\log n)$.

**Soru 3** (ekrandan, 00:30:00): Slayttaki fonksiyon işaretçisi programına 5 girilirse çıktı ne olur?

> **Çözüm (derste verilmedi):** `pf = f1;` ile `pf` `f1`'i gösterir; `(*pf)(5)` `f1(5)`'i çağırır ve `5 + 1 = 6` döner. Çıktı `6`'dır. Kod `gcc -std=c11 -Wall` ile derlenip 5 girdisiyle çalıştırıldı, çıktı 6 oldu.

**Soru 4** (ekrandan, 01:35:00): `stat = fseek(fp, 10, SEEK_SET);` çağrısından sonra okunacak karakter dosyanın kaçıncı karakteridir ve `stat` ne olur?

> **Çözüm (derste verildi):** Akışlar 0. konumdan başladığı için 10. konum dosyanın 11. karakteridir. İstek geçerliyse `fseek` 0 döndürür, değilse 0'dan farklı bir değer.

**Soru 5** (ekrandan, 01:35:00): Salt okunur açılmış bir dosyada `stat = fseek(fp, 1, SEEK_END)` neden geçersizdir?

> **Çözüm (derste verildi):** Konum göstergesini dosya sonunun ötesine taşımaya çalışır. Salt okunur dosyada `SEEK_END` ile offset 0'dan küçük ya da 0'a eşit olmalıdır.

**Soru 6** (ekrandan, 01:20:00): `putc('x', fp[j++]);` çağrısı neden tehlikelidir, ne kullanılmalıdır?

> **Çözüm (derste verildi):** `putc` genellikle makro olarak gerçekleştirilir; makro açılımında argüman birden fazla kez yerine konabilir ve `j++` yan etkisi beklenmedik sayıda uygulanabilir. Argümanında yan etkili işleç bulunan çağrılarda kesin olarak fonksiyon olan `fputc` (ya da okumada `fgetc`) kullanılmalıdır.

**Soru 7** (ekrandan, 02:25:00): Aşağıdaki satırların sorunu nedir?

```c
struct ogr *ptr;
fread(ptr,sizeof(struct ogr),1,fp);
```

> **Çözüm (derste verildi):** `ptr` için bellek ayrılmamıştır; hiçbir geçerli adresi göstermez. Veri okunacak yer önce `malloc` ile ayrılmalı (`struct ogr *ptr = malloc(sizeof(struct ogr));`) ya da `ptr` var olan bir değişkenin adresine yöneltilmelidir.

## Dersin Toparlaması

Ders, özyinelemenin yığın belleğiyle ilişkisini ve temel durumun neden şart olduğunu göstererek başladı; üs alma örneğinde aynı problemin dört farklı çözümü karşılaştırıldı ve ara sonucu saklamanın böl ve yönet algoritmasını $O(n)$'den $O(\log n)$'e indirdiği görüldü. Fonksiyon işaretçileriyle bir fonksiyonun adres üzerinden çağrılması, parametre olarak aktarılması ve diziler içinde tutulması işlendi; `void *` ile genel işaretçi kullanımı da bu çerçevede anlatıldı.

Dersin büyük kısmı dosya işlemlerine ayrıldı: akış kavramı, standart akışlar, metin ve ikili biçim, `FILE` yapısı ile dosya konum göstergesi, `fopen` kipleri, karakter, satır ve blok G/Ç, `fseek` ve `ftell` ile rastgele erişim, dosya yönetim fonksiyonları. Kopyalama programının üç sürümü çalıştırılarak diske git-gel sayısının okuma yöntemine göre nasıl değiştiği gösterildi. Programın bellek düzeni (kod, veri, heap, stack) üzerinden işaretçiye yer ayırmanın önemi vurgulandı. Ders, çok dosyalı projelerin Makefile ile derlenmesi, Dev-C++'ın ürettiği Makefile ve daha genel bir araç olan CMake ile bitti. Hoca sonraki derslerde daha çok örnek çözüleceğini ve vakit kalırsa thread konusuna geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
