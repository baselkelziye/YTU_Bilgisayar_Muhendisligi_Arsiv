# Ders 5 Çalışma Özeti

## Genel Konular

- Bir alt dereceden Karnaugh haritasıyla çözüm (değişken girişli harita)
  - $n$ değişkenli bir fonksiyon $n-1$ değişkenli bir haritayla çözülebilir: 5 değişkenli bir fonksiyon 4 değişkenli, 4 değişkenli bir fonksiyon 3 değişkenli haritayla.
  - Yöntem: ilk $n-1$ bit aynı olan iki satır birlikte incelenir. Son değişkene (örneğin $d$) göre fonksiyon ya hep 0, ya hep 1, ya $d$, ya da $\overline{d}$ çıkar. Haritanın hücresine bu değer yazılır.
  - Karnaugh haritasında hücrede yalnız 0, 1 ya da "don't care" olmak zorunda değildir; bir değişken de yazılabilir.
  - İki değişkenli ısınma örneği: $f=1$ yalnız $ab=01$ ve $ab=10$ iken. $a=0$ iken $f=b$, $a=1$ iken $f=\overline{b}$, sonuç $f=\overline{a}b+a\overline{b}$.
- Dört değişkenli bir örneğin iki yolla çözümü (ekrandan, 00:25:00 ve 00:30:00)
  - 1'ler: $m(1,2,3,6,11,15)$.
  - 4 değişkenli haritayla: $f=\overline{a}\,\overline{b}d+\overline{a}c\overline{d}+acd$.
  - 3 değişkenli ($a,b,c$) haritayla: $abc=000 \to d$, $001 \to 1$, $011 \to \overline{d}$, $101 \to d$, $111 \to d$, diğerleri 0. Aynı sonuç bulunur.
- Değişkenli hücrelerde gruplama kuralları
  - $d$ hücresi $d$ ya da 1 ile gruplanabilir; $\overline{d}$ hücresi $\overline{d}$ ya da 1 ile gruplanabilir. $d$ ile $\overline{d}$ birlikte gruplanmaz.
  - 1 hücresi aslında $d+\overline{d}$ demektir. Bir 1, hem $d$'li hem $\overline{d}$'li bir grupla kapsanmışsa ayrıca gruplanmaz.
  - 1 yalnız $d$'li gruplarla kapsandıysa geriye $\overline{d}$ parçası açıkta kalır; bu yüzden 1'ler kendi aralarında ayrıca gruplanır.
  - Grubun terimi, gruptaki değişmeyen harita değişkenleri ile hücredeki değişkenin (ya da 1'in) çarpımıdır.
- Beş değişkenli örnek (ekrandan, 00:35:00 ve 00:40:00)
  - 4 değişkenli haritada $e$ hücreleri: $abcd=0111, 1100, 1010$; 1 hücreleri: $1101, 1111, 1110, 1011$.
  - $e$'li gruplar: $abe+ace+bcde$. 1'lerin kendi grupları: $abd+abc+acd$.
  - Sonuç: $F=abe+ace+bcde+abd+abc+acd$.
- Quine-McCluskey (tablo) yöntemi (ekrandan, 00:45:00)
  - Mintermler içerdikleri 1 sayısına göre gruplanır. Komşu gruplardan yalnız bir biti farklı olanlar birleştirilir, farklı bit "$-$" ile yazılır. Bu adım tekrarlanır.
  - Temel mantık $XY\overline{Z}+XYZ=XY$ sadeleştirmesidir. Algoritmaya dökülebildiği için 6 ve daha çok değişkende tercih edilir.
  - Slayttaki örnek: $m(0,1,2,5,6,7,8,9,10,14)$ için $f=\overline{a}bd+\overline{b}\,\overline{c}+c\overline{d}$.
  - Son adımda asal çarpanlar arasından bütün mintermleri kapsayacak en az terim seçilir.
- Diziler (sequences) ve dizgiler (strings)
  - Dizi, sıralı bir listeyi gösteren ayrık yapıdır: $s_n$, $n$'nin bir fonksiyonudur ve $n$ doğal sayılardan alınır (ekrandan, 00:50:00).
  - Artan dizi: her $n$ için $s_n<s_{n+1}$; azalan dizi: $s_n>s_{n+1}$. Kural bir yerde bozulursa dizi ne artan ne azalandır.
  - Alt dizi: $s_n=n$ dizisinden $t_n=2n$ (çift sayılar) gibi, sırası korunarak seçilen elemanlar.
  - Toplam ($\sum$) ve çarpım ($\prod$) gösterimi; algoritma analizinde `for` döngülerinin adım sayısı bu gösterimle yazılır.
  - Dizgi (string): bir alfabeden üretilen karakter dizisi. Uzunluk $|\alpha|$, boş dizgi $\lambda$, $X^*$ (boş dizgi dahil bütün dizgiler), $X^+$ (boş dizgi hariç), birleştirme (concatenation), $|\alpha\beta|=|\alpha|+|\beta|$.
  - Run length encoding (RLE): peş peşe tekrar eden karakterler üs ile yazılır, örneğin $b^2ac^4a^2ba$.
- Sayı sistemleri
  - İkili, sekizli, onlu ve onaltılı sistemler; $x$ tabanındaki bir sayıda her basamak $a_i<x$ olmalıdır.
  - Elde mantığı: onluda "14'ün 4'ü, elde 1" derken $14-10$ yapılır; onaltılıda tabandan 16 çıkarılır.
  - Örnekler: $2EF6_{16}+32EB_{16}=61E1_{16}$ (ekrandan, 01:05:00), $23A_{16}+8F_{16}=2C9_{16}$ (ekrandan, 01:20:00).
  - Onaltılı toplama zor gelirse sayılar ikiliye çevrilip toplanabilir.
  - İkili toplamada $1+1=10$; taşan bit işlemcide elde bayrağıdır (carry flag). İşaretli sayılarda taşma bayrağı (overflow flag) ayrıca kontrol edilir.
- Bağıntılar (relations)
  - $X\times Y$ kartezyen çarpımının her alt kümesi $X$'ten $Y$'ye bir ikili bağıntıdır. Tanım kümesi (domain) ve değer kümesi (range) tanımlanır.
  - Yansıma: refleksif (her $(x,x)$ var), non-refleksif (bir kısmı var), irrefleksif (hiçbiri yok).
  - Simetri, antisimetri, geçişme (transitivity). Boş bağıntı geçişkendir.
  - Ters bağıntı ve bileşke ($R^2$, $R^3$).
  - Denklik bağıntısı: refleksif, simetrik, geçişken. Sıralama bağıntısı: refleksif, antisimetrik, geçişken.
  - Hasse diyagramı: sıralama bağıntısında refleksif döngüler ve geçişkenlikten gelen oklar silinerek çizilir.
  - Kapanış (closure) ve geçişken kapanış için Warshall algoritması (ekrandan, 01:50:00).
  - Bağıntıların matrisle gösterimi (ilişki varsa 1, yoksa 0); refleksif bağıntıda köşegen 1'dir. Matris çarpımıyla "kim kiminle konuşabilir" türü sorular çözülür.
- Fonksiyonlar
  - Fonksiyon, bağıntının özel bir hâlidir: tanım kümesinde her elemanın tam bir görüntüsü olur (ekrandan, 02:10:00).
  - Birebir (one-to-one), örten (onto), birebir ve örten (bijective) fonksiyonlar; ters fonksiyon, bileşke, üstel ve logaritmik fonksiyonlar, taban ve tavan fonksiyonları.
- Alıştırmalar: küme işlemleri, Venn diyagramı, toplam ve çarpım hesapları, sayı tabanı, bağıntı özellikleri, ters fonksiyon.

## Hocanın Özellikle Vurguladığı Kısımlar

- Karnaugh haritasında dörtlü grupların iki kez çakışamayacağı diye bir kural yoktur
  - Gruplar istenildiği kadar çakışabilir. Önemli olan her 1'in en az bir grupta olması ve grupların olabildiğince büyük seçilmesidir.
- Harita etiketlerinde Gray kodu
  - Bazı kaynaklar sütunları $\overline{c}\,\overline{d}$, $\overline{c}d$ gibi yazar. Hoca 00, 01, 11, 10 biçimindeki Gray kodunu daha genel buluyor: değişken adları değişince ($x,y$ gibi) dönüştürmek zorlaşmaz.
- $d$ ile $\overline{d}$ birlikte gruplanmaz; 1'ler gerekiyorsa ayrıca gruplanır
  - Değişkenli harita yönteminin kafa karıştıran yeri budur. Bir 1 hücresinin hangi parçasının ($d$ mi $\overline{d}$ mi) kapsandığına bakılır.
- Quine-McCluskey algoritmik bir yöntemdir
  - Karnaugh haritası 6 ve üstü değişkende zorlaşır; tablo yöntemi her boyutta çalışır.
- Geçişkenlikte koşul önemlidir
  - $(x,y)\in R$ ve $(y,z)\in R$ olduğunda $(x,z)\in R$ olmalıdır. Uygun ikinci ikili yoksa geçişkenlik bozulmaz.
  - Bir bağıntının bir özelliği sağlamadığını göstermek için tek bir karşı örnek yeterlidir.
- Bağıntıların matris gösterimi önemlidir
  - Çizgeler (graflar) konusunda tekrar kullanılacak.
- Tavsiye edilen alıştırma
  - Bir bağıntıyı dizide saklayıp refleksif, simetrik, antisimetrik ve geçişken olup olmadığını kontrol eden bir C programı yazmak.

## Kısa Tekrar Notları

- Değişkenli harita: hücreye 0, 1, $d$ ya da $\overline{d}$ yazılır.
- $d$ ile 1, $\overline{d}$ ile 1 gruplanır; $d$ ile $\overline{d}$ gruplanmaz.
- 1 hem $d$'li hem $\overline{d}$'li grupta ise ayrıca gruplanmaz; yalnız biriyle gruplandıysa ayrıca gruplanır.
- $m(1,2,3,6,11,15)$ için $f=\overline{a}\,\overline{b}d+\overline{a}c\overline{d}+acd$.
- Quine-McCluskey: 1 sayısına göre grupla, bir bit farklıları birleştir, asal çarpanlardan kapsayan en az terimi seç.
- $\sum_{k=4}^{8}(-1)^k=1$, $\sum_{i=1}^{4}\sum_{j=1}^{3} ij=60$.
- $\lambda$ boş dizgi; $X^*$ boş dizgi dahil, $X^+$ hariç bütün dizgiler.
- $2EF6_{16}+32EB_{16}=61E1_{16}$; $23A_{16}+8F_{16}=2C9_{16}$.
- Denklik bağıntısı: R, S, T. Sıralama bağıntısı: R, AS, T.
- Warshall: $W_{ij} \leftarrow W_{ij} \lor (W_{ik}\land W_{kj})$, $k=1,\dots,n$.
- Fonksiyon: tanım kümesinde boşta eleman yok, her elemanın tek görüntüsü var.
- Bijektif fonksiyonun tersi de fonksiyondur. $f(x)=x^2$ ($\mathbb{R}\to\mathbb{R}$) birebir değildir.
- Bileşkede birleşme özelliği vardır, değişme özelliği yoktur.

## Detaylı Açıklamalar

- **Değişkenli Karnaugh haritası.** Ders, önceki haftadan kalan bir konuyla başladı: bir fonksiyonu bir alt dereceden haritayla çözmek. Doğruluk tablosunda son değişken dışındaki bitleri aynı olan iki satır yan yanadır. Bu iki satırda $f$, son değişken 0 iken 0 ve 1 iken 1 ise hücreye o değişken ($d$), tersiyse $\overline{d}$, ikisinde de 1 ise 1, ikisinde de 0 ise 0 yazılır. Örnekte $m(1,2,3,6,11,15)$ fonksiyonu önce dört değişkenli haritayla $\overline{a}\,\overline{b}d+\overline{a}c\overline{d}+acd$ olarak bulundu (ekrandan, 00:30:00). Sonra $a,b,c$ haritasında $000 \to d$, $001 \to 1$, $011 \to \overline{d}$, $101 \to d$, $111 \to d$ yazıldı. $d$ ile yanındaki 1 gruplanıp $\overline{a}\,\overline{b}d$, iki $d$ gruplanıp $acd$, $\overline{d}$ ile 1 gruplanıp $\overline{a}c\overline{d}$ bulundu. Ortadaki 1 hem $d$'li hem $\overline{d}$'li grupta olduğu için ayrıca gruplanmadı. Gruplansaydı $\overline{a}\,\overline{b}c$ gibi gereksiz bir terim gelirdi.
- **Beş değişkenli örnek.** Dört değişkenli haritada $e$ ve 1 hücreleri vardı (ekrandan, 00:35:00). Her $e$ en büyük gruba alındı: $abe$ (11 satırı), $ace$ (sağ alttaki dörtlü), $bcde$ (ikili). 1 hücreleri bu gruplarda yalnız $e$ parçasıyla kapsandığı için $\overline{e}$ parçaları açıkta kaldı; bu yüzden 1'ler kendi aralarında $abd$, $abc$, $acd$ olarak gruplandı. Sonuç $F=abe+ace+bcde+abd+abc+acd$ (python ile doğruluk tablosu üzerinden kontrol edildi). Hoca bu yöntemi kaynak kitaplarda pek görmediğini ve sınavda sorulmayacağını söyledi; amaç 5 değişkenli bir fonksiyonu tablo yöntemini hatırlamadan da çözebilmek.
- **Quine-McCluskey.** Yöntem $ABCD\overline{E}+ABCDE=ABCD$ sadeleştirmesine dayanır. Mintermler 1 sayısına göre gruplara ayrılır; ardışık gruplardan yalnız bir biti farklı olan çiftler "$-$" ile birleştirilir (sütun II), sonra aynı yerde "$-$" olan ve bir biti farklı olanlar tekrar birleştirilir (sütun III). Tekrar eden terimler bir kez yazılır. Slayttaki örnekte $m(0,1,2,5,6,7,8,9,10,14)$ için gruplar (0,1,8,9), (0,2,8,10), (2,6,10,14) çıktı ve sonuç $\overline{a}bd+\overline{b}\,\overline{c}+c\overline{d}$ oldu (ekrandan, 00:45:00). Son adımda en çok minterm kapsayan terimden başlanarak bütün mintermleri kapsayan terimler seçilir.
- **Toplam gösterimi.** $\sum_{k=4}^{8}(-1)^k = 1-1+1-1+1 = 1$. İç içe toplamda önce içteki toplam hesaplanır: $\sum_{j=1}^{3} ij = i+2i+3i=6i$, sonra $\sum_{i=1}^{4}6i = 6\cdot\frac{4\cdot 5}{2}=60$ (ekrandan, 00:55:00).
- **Onaltılı toplama.** $2EF6+32EB$: $6+B=17$, $17-16=1$, elde 1; $F+E+1=30$, $30-16=14=E$, elde 1; $E+2+1=17$, $1$, elde 1; $2+3+1=6$. Sonuç $61E1_{16}$. Sağlaması ikili toplama ile yapıldı (ekrandan, 01:05:00).
- **Bağıntı özellikleri.** $A=\{1,2,3,4\}$ üzerinde $a=b^2$ bağıntısı $R=\{(1,1),(4,2)\}$'dir: refleksif değil, non-refleksif, irrefleksif değil (ekrandan, 01:30:00); simetrik değil, antisimetrik ve geçişkendir. $\{(2,2),(2,3),(2,4),(3,2),(3,3),(3,4)\}$: NR, NS, NAS, T. $\{(1,1),(1,2),(2,1),(2,2),(3,3),(4,4)\}$: R, S, NAS, T (ekrandan, 01:35:00).
- **Denklik ve sıralama.** $X=\{1,\dots,6\}$ üzerinde $\{1,3,5\}$, $\{2,6\}$, $\{4\}$ blokları içinde bütün ikilileri içeren bağıntı bir denklik bağıntısıdır (ekrandan, 01:40:00). $\le$ bağıntısı ve bölünebilme bağıntısı ise sıralama bağıntısıdır. $\le$ için Hasse diyagramı $1\to2\to3\to4$ zinciridir.
- **Warshall algoritması.** $W=M_R$ ile başlanır; her $k$ için $W_{ij}\leftarrow W_{ij}\lor(W_{ik}\land W_{kj})$ uygulanır. Bir 1 eklemek, iki düğüm arasına bir yol eklemek demektir. Ekrandaki örnekte $W_1$ ve $W_2$ gösterildi (ekrandan, 01:50:00).
- **Fonksiyonlar.** Grafikte dikey bir doğru eğriyi en fazla bir noktada kesmelidir. $f(x)=2^x$ birebirdir, $f(x)=x^2$ ($\mathbb{R}\to\mathbb{R}$) birebir değildir. $ax+b$ ve $x^3$ bijektiftir (ekrandan, 02:15:00). Ters fonksiyon için $y=f(x)$ yazılır, $x$ yalnız bırakılır, sonra $x$ ile $y$ yer değiştirir: $y=x+1 \Rightarrow f^{-1}(x)=x-1$, $y=ax+b \Rightarrow f^{-1}(x)=\frac{x-b}{a}$.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
