# Ders 21 Çalışma Özeti

## Genel Konular

- Sanal makineden ana işletim sistemine dosya aktarma
  - Ubuntu sanal makinesinde (VMware Player) yazılan bir dosyayı Windows tarafına çıkarmanın birkaç yolu konuşuldu: USB bellek, VMware Tools ile ortak pano, sanal makinenin kendi interneti ve e-posta.
  - USB bellek takıldığında önce Windows tarafından bağlanır (mount); VMware Player'ın üst çubuğundaki çıkarılabilir aygıtlar menüsünden aygıt konuğa (guest, yani içerideki Linux'a) bağlanır, dosya kopyalanır, sonra aygıtın bağlantısı kesilip yeniden Windows'a verilir.
  - VMware Tools yüklenirse kopyala-yapıştır alanı iki işletim sistemi arasında ortak hale gelir; dosya ya da metin içeriden dışarıya, dışarıdan içeriye yapıştırılabilir.
- Matris çarpımının C programı
  - Önceki derste konuşulan matris çarpımının kodu `vi` ile `mat.c` dosyasına yazıldı, `gcc -Wall` ile derlenip çalıştırıldı.
  - Boyutlar: A matrisi $n \times m$, B matrisi $m \times l$, sonuç C matrisi $n \times l$. Ortak boyut ($m$) için ayrı değişken tanımlanmaz; üç boyut değişkeni (`n`, `m`, `l`) ve üç indis (`i`, `j`, `k`) yeter.
  - Dinamik bellek ayırma henüz kullanılmadığı için matrisler olası en büyük durumdan biraz büyük, statik boyutla tanımlandı: `#define DIM 25`, `int a[DIM][DIM], b[DIM][DIM], c[DIM][DIM];` (ekrandan, 00:15:00).
  - Kullanıcıdan önce A'nın satır ve sütun sayısı, sonra yalnız B'nin sütun sayısı alınır; B'nin satır sayısı A'nın sütun sayısına eşit olmak zorundadır.
  - Matrisler iç içe iki `for` döngüsüyle eleman eleman, `a[0][0] : ` biçiminde sorularak okunur.
- Ara kontrol
  - Çarpma yazılmadan önce yalnız A matrisi yazdırılarak okumanın doğru olduğu denendi. Hoca bunu "ortalık karışmadan" yapılan bir doğrulama adımı olarak gösterdi.
- Çarpma döngüsü
  - Dış döngü `i` (A'nın satırları, `n`), orta döngü `k` (B'nin sütunları, `l`), iç döngü `j` (ortak boyut, `m`).
  - Her `(i, k)` için `tmp` sıfırlanır, iç döngüde `tmp += a[i][j] * b[j][k];` ile toplanır, döngüden çıkınca `c[i][k] = tmp;` yazılır (ekrandan, 00:40:00).
  - Kopyala-yapıştırla yazılan döngü sınırları ilk anda yanlıştı; `i` 0'dan `n`'e, `k` 0'dan `l`'ye, `j` 0'dan `m`'ye olacak biçimde düzeltildi.
- Sonucu yazdırma
  - Dış döngü satırları, iç döngü sütunları gezer; her elemandan sonra `\t`, her satırın sonunda `\n` basılır. Böylece çıktı matris biçiminde okunur.

## Hocanın Özellikle Vurguladığı Kısımlar

- İndis adları ezberlenmez
  - `i`, `j`, `k` adları yalnız boyutları ve o boyutlarda gezinen indisleri temsil eder. "Önce i, sonra j, sonra k" diye bir zorunluluk yoktur; döngülerin sırası yapılan işe göre belirlenir.
  - Toplama ortak boyut ($m$) üzerinde yapıldığı için `j` en içte, B'nin her sütunu için bu toplama bir kez daha yapılacağı için `k` dışarıdadır.
  - Hoca, kodu bir matrisle kâğıt üzerinde izleyip `i`, `j`, `k`'nın hangi değerleri aldığını tek tek çıkarmayı ve döngü sırası değişirse ne olacağını düşünmeyi önerdi.
- Kodu küçük bir örnekle elle doğrulamak
  - 3×4 ve 4×2'lik örnekte sonuç elle hesaplanıp programın çıktısıyla karşılaştırıldı. Tek bir örnek yeterli güvence vermez; başka bir matrisle de denemek gerekir.
- İndis değişkeninin matrisle bağı yoktur
  - Sonuç yazdırılırken `c[i][j]` kullanılması, çarpmada `c[i][k]` yazılmasıyla çelişmez. Döngü değişkeni yalnız bir sayaçtır; hangi matrise ait olduğu yoktur.
- `printf` belgesine bakmak
  - `\t` (sekme) ve `\n` (yeni satır) gibi kaçış karakterleri ile `%d` gibi biçim belirteçlerini `printf` belgesinden öğrenmek öğrencinin sorumluluğundadır.

## Kısa Tekrar Notları

- $A_{n \times m} \cdot B_{m \times l} = C_{n \times l}$; ortadaki boyut sonuçta kaybolur.
- $c_{ik} = \sum_{j=0}^{m-1} a_{ij}\, b_{jk}$.
- Döngü sırası: `i` (satır) → `k` (B'nin sütunu) → `j` (toplama indisi).
- `tmp` her `(i, k)` için sıfırlanır; iç döngü bitince `c[i][k]`'ya yazılır.
- `tmp += x;` ile `tmp = tmp + x;` arasında fark yoktur.
- Okunan veriyi önce yazdırıp kontrol et, sonra asıl işleme geç.
- Yazdırmada elemanlar arasında `\t`, satır sonunda `\n`.
- Kodda Türkçe karakter kullanmak sorun çıkarabilir.

## Detaylı Açıklamalar

- Program `vi mat.c` ile boş bir dosyadan yazıldı. Önce `#include <stdio.h>`, `#define DIM 25` ve `main` iskeleti, sonra değişkenler geldi: `int i,j,k;` (indisler), `int n,m,l;` (boyutlar), `int tmp;` (ara toplam). `tmp`, toplamı doğrudan `c[i][k]` üzerinde her adımda indisleyerek biriktirmek yerine geçici bir değişkende tutmak için kullanılır (ekrandan, 00:10:00).
- Okuma bölümü: `printf("Please enter # of rows for mat A : ")` ve `scanf("%d", &n)` ile `n`, aynı biçimde `m` (A'nın sütun sayısı) ve `l` (B'nin sütun sayısı) alınır. A için `i < n`, `j < m`; B için `i < m`, `j < l` sınırlarıyla iki döngü çifti yazılır. B'nin döngüsü A'nınkinden kopyalandığı için sınırların ve `&b[i][j]` hedefinin ayrıca düzeltilmesi gerekti (ekrandan, 00:15:00 ve 00:20:00).
- İlk denemede (3×4 ve 4×2) yalnız A yazdırıldı ve girilen değerlerin matris biçiminde doğru göründüğü kontrol edildi (ekrandan, 00:25:00).
- Çarpmanın tam hali ve testi (ekrandan, 00:25:00): A = `1 2 3 4 / 5 6 7 8 / 9 0 1 2`, B = `1 2 / 3 4 / 5 6 / 7 8` girildiğinde çıktı `50 60 / 114 140 / 28 40` oldu. Hoca ilk satırı elle doğruladı: $1\cdot1 + 2\cdot3 + 3\cdot5 + 4\cdot7 = 1+6+15+28 = 50$, $1\cdot2 + 2\cdot4 + 3\cdot6 + 4\cdot8 = 2+8+18+32 = 60$; ikinci satır $5+18+35+56 = 114$, $10+24+42+64 = 140$; üçüncü satırın ilk elemanı $9+0+5+14 = 28$. Kod `gcc -Wall` ile derlenip aynı girdiyle çalıştırıldı (ajan testi), aynı sonuç alındı.
- Döngü sırasının nedeni (ekrandan, 00:35:00): hoca bir metin dosyasında her sonuç elemanını açık yazdı, örneğin ilk eleman `a[0][0]*b[0][0] + a[0][1]*b[1][0] + a[0][2]*b[2][0] + a[0][3]*b[3][0]`. Bir terimden ötekine geçerken A'nın sütun indisi ile B'nin satır indisi (ikisi de `j`) ilerler; satır indisi `i` sabittir. Aynı toplama B'nin ikinci sütunu için yeniden yapılır (B'nin sütun indisi 1 olur); B üç sütunlu olsaydı üç kez yapılırdı. Son olarak A'nın sonraki satırlarına geçilir. Bu yüzden en içte `j`, ortada `k`, en dışta `i` vardır.
- Yazdırma bölümünde `printf("%d\t", c[i][j]);` iç döngüde, `printf("\n");` dış döngüde yer alır. Hoca `\t`'yi kaldırıp 1-12 değerleriyle yeniden çalıştırınca sayılar birbirine yapıştı ve sonuç matris olarak okunamaz hale geldi. Her elemandan sonra yeni satır basılsaydı da çıktı tek boyutlu bir dizi gibi görünürdü.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
