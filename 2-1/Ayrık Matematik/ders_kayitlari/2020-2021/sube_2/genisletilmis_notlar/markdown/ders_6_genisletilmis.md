# Ders 6 Genişletilmiş Notu: Bağıntı Örnekleri, Algoritmalar, Arama ve Sıralama, Veri Yapıları ve Prefix-Infix-Postfix

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Bağıntı Özellikleri Üzerine Örnekler
- 2. Yönlü Çizgeden Bağıntı Özelliklerini Belirleme
- 3. Bağıntının Kuvvetleri
- 4. Algoritma Kavramı
- 5. Algoritmaların Özellikleri ve Maksimum Bulma Örneği
- 6. Arama Algoritmaları
- 7. Sıralama Algoritmaları
- 8. Öklid Algoritması ve OBEB
- 9. Algoritma Tasarım Yöntemleri ve Analiz Ölçütleri
- 10. Temel Veri Yapıları
- 11. Kuyruk ve Yığın
- 12. Yığın Uygulamaları: Infix, Prefix, Postfix Gösterimleri
- 13. İfadelerin Yığınla Değerlendirilmesi
- 14. Gösterimler Arası Dönüşümler
- Örnek Sorular
- Dersin Toparlaması

## 1. Bağıntı Özellikleri Üzerine Örnekler

Ders, önceki haftanın bağıntılar ve fonksiyonlar bölümünün kitap slaytlarında kalan birkaç örnekle başladı. Önceki hafta ikili bağıntıların üç gösterimi görülmüştü: sıralı ikililerden oluşan küme gösterimi, 0-1 matris gösterimi ve çizge gösterimi.

### 1.1 Yansımalı bağıntı ve aksine örnek

Bir bağıntı, kümedeki her $a$ için $(a,a)\in R$ ise yansımalıdır (refleksif). Slaytta gerçel sayılar üzerindeki bazı bağıntıların yansımalı olduğu, bazılarının olmadığı gösterildi.

**Soru (hocanın sınıfa sorusu):** "Şu bağıntının yansımalı olmadığını kanıtlayın" denirse hangi ispat yöntemi kullanılır?
**Cevap:** Olmayana ergi gerekmez; tek bir aksine örnek (counterexample) bulmak yeterlidir. Slayttaki "yansımalı değildir" örneklerinin her biri aslında bir aksine örnektir.

### 1.2 Simetrik ve ters simetrik bağıntı

Slayttaki tanım (ekrandan, 00:15:00): $R$, her $a,b\in A$ için $(a,b)\in R$ olduğunda $(b,a)\in R$ ise simetriktir. Sembolle:

$$\forall x\,\forall y\,[(x,y)\in R \rightarrow (y,x)\in R]$$

Tam sayılar üzerinde simetrik olanlar:

- $R_3=\{(a,b)\mid a=b \text{ ya da } a=-b\}$
- $R_4=\{(a,b)\mid a=b\}$
- $R_6=\{(a,b)\mid a+b\le 3\}$

Simetrik olmayanlar, aksine örnekleriyle:

- $R_1=\{(a,b)\mid a\le b\}$: $3\le 4$ ama $4\not\le 3$.
- $R_2=\{(a,b)\mid a>b\}$: $4>3$ ama $3\not>4$.
- $R_5=\{(a,b)\mid a=b+1\}$: $4=3+1$ ama $3\ne 4+1$.

Hoca $R_1$ için şunu söyledi: "küçük ya da eşit" bağıntısında eşitlik tarafı simetriyi sağlar ama küçüklük tarafı sağlamaz; $(3,4)$ varken $(4,3)$ yazılamaz.

Ters simetri (antisimetri): $a\ne b$ için $(a,b)$ varsa $(b,a)$ olmamalıdır. $(a,b)$ hiç yoksa $(b,a)$'ya bakmaya gerek yoktur. Geçişkenlik ise sezgisel olarak daha rahat kavranır: $(a,b)$ ve $(b,c)$ varsa $(a,c)$ da olmalıdır.

### 1.3 Bağıntıların birleştirilmesi ve matris gösterimi

İki bağıntı küme olduğu için kesişim ve birleşim gibi küme işlemleriyle birleştirilebilir. Hoca küme birleşimiyle karışmasın diye buna "combination" demeyi tercih etti. Bileşke (composition) de önceki hafta görülmüştü.

Matris gösteriminde bağıntı matrisi simetrik olmak zorunda değildir; yönlü çizgeler simetrik olmayan 0-1 matrisleriyle gösterilir. Matristen özellik okunabilir:

- Bağıntı yansımalıysa köşegenin tamamı 1'dir.
- Bağıntı simetrikse köşegene göre karşılıklı bütün elemanlar eşittir: biri 0 ise diğeri de 0, biri 1 ise diğeri de 1.

<!-- BELİRSİZ: Matris örneğinin (00:17:38) kendisi karelerde yok; altyazıdan yalnız "yansımalı, simetrik ve antisimetrik" sonucu anlaşılıyor. -->

## 2. Yönlü Çizgeden Bağıntı Özelliklerini Belirleme

Bağıntılar genellikle yönlü çizgelerle (digraph, directed graph) gösterilir. Hoca bu gösterimin ayrıntısına çizgeler konusunda geri dönüleceğini, şimdilik eldeki bilgiyle çizilebileceğini söyledi.

Çizgede okuma kuralları:

- Yansımalı: her düğümde kendine dönen bir döngü (loop) olmalı.
- Simetrik: her $x\to y$ kenarı için $y\to x$ kenarı da olmalı.
- Antisimetrik: $x\ne y$ için $x\to y$ ve $y\to x$ birlikte bulunmamalı.
- Geçişken: $x\to y$ ve $y\to z$ varsa $x\to z$ de olmalı.

### 2.1 Örnek 1: yalnız bir döngü

Bu örnekte yalnız $a$ düğümünde bir döngü vardır.

- Yansımalı mı? Hayır; döngü yalnız $a$'da var, $b$, $c$ ve $d$'de de olmalıydı.
- Simetrik mi? Evet; $a\to a$ dışında kenar olmadığından simetriyi bozan bir çift yoktur.
- Antisimetrik mi? Evet; farklı iki düğüm arasında kenar yoktur.
- Geçişken mi? Evet; zincir oluşturan iki kenar yoktur.

> **Hocanın vurgusu:** Burada bir bağıntının hem simetrik hem antisimetrik olabildiği görülüyor. Buna dikkat edin.

<!-- BELİRSİZ: Örnek 1'in çizgesi karelerde yok; kenar kümesi altyazıdan çıkarıldı. -->

### 2.2 Örnek 2

Çizge (ekrandan, 00:20:00): düğümler $a,b,c,d$; kenarlar $a\to b$, $b\to d$, $d\to b$; $c$ yalnızdır.

- Yansımalı mı? Hayır; hiçbir düğümde döngü yok.
- Simetrik mi? Hayır; $a\to b$ var ama $b\to a$ yok.
- Antisimetrik mi? Hayır; $b\to d$ ve $d\to b$ birlikte var.
- Geçişken mi? Hayır; $a\to b$ ve $b\to d$ var ama $a\to d$ yok.

Bu örnekte simetri ve antisimetri ikisi de sağlanmıyor; birinci örnekte ikisi de sağlanıyordu.

> **Ders sonrası not:** Slayttaki geçişkenlik açıklamasında "$a$'dan $c$'ye ve $c$'den $b$'ye kenar var" yazıyor. Hoca bunun yanlış olduğunu söyledi: çizgede $c$'ye giden kenar yoktur; doğru gerekçe $a\to b$, $b\to d$ varken $a\to d$'nin olmamasıdır. Hoca kitap slaytlarında bu tür küçük hatalar bulunduğunu belirtti.

### 2.3 Örnek 3

Bu örnekte kenarlar $a\to c$, $c\to b$ ve $a\to b$'dir; hiçbir kenarın tersi yoktur.

- Yansımalı değil (döngü yok).
- Simetrik değil (yönlü kenarların hiçbirinde geri dönüş yok).
- Antisimetrik (aynı nedenle evet).
- Geçişken: $a\to c$, $c\to b$ var ve $a\to b$ de var; evet.

Hoca slaytta geçişkenlik için "$a$'dan $b$'ye kenar yok" yazıldığını, ama çizgede bu kenarın göründüğünü, büyük olasılıkla harflerin yanlış yazıldığını söyledi. Ayrıca $d\to a$ gibi bir kenar eklenseydi geçişkenliğin bozulup bozulmayacağını tartıştı: $a\to b$ ve $b\to d$ gibi bir zincir varsa $(a,d)$'nin de bulunması beklenir.

<!-- BELİRSİZ: Örnek 3'ün çizgesi karelerde yok; kenarlar altyazıdan çıkarıldı. -->

### 2.4 Örnek 4

Son örnekte de döngü olmadığı için bağıntı yansımalı değildir. Kenarların tersten geri gelmediği için simetrik değildir; aynı nedenle antisimetriktir. Hoca geçişkenliği şöyle açıkladı: $a\to d$ var ama $d$'den başka bir yere gidilmiyor. $d\to b$ ya da $d\to c$ olsaydı $a\to b$ ya da $a\to c$ aranacaktı. Böyle bir zincir olmadığı için geçişkendir.

<!-- BELİRSİZ: Örnek 4'ün çizgesi karelerde yok; kenar kümesi altyazıdan tam çıkarılamıyor. -->

## 3. Bağıntının Kuvvetleri

Bir bağıntının kuvvetini almak, bağıntı matrisinin karesini, küpünü, dördüncü kuvvetini almaya karşılık gelir. Tanım olarak $R^1=R$, $R^{n+1}=R^n\circ R$'dir; yani ikinci kuvvet için $R$'nin kendisiyle bileşkesine bakılır.

Slayttaki örnek (ekrandan, 00:25:00): $R=\{(a,b),(b,c),(c,d),(d,b)\}$.

- $R^2=\{(a,c),(b,d),(c,b),(d,c)\}$
- $R^3=\{(a,d),(b,b),(c,c),(d,d)\}$
- $R^4=\{(a,b),(b,c),(c,d),(d,b)\}=R$

Bu kümeler python ile bileşke hesaplanarak doğrulandı. Slayttaki kural: $(x,y)\in R^n$ ancak ve ancak $R$'de oklar yönünde $x$'ten $y$'ye $n$ uzunluğunda bir yol vardır. Örneğin $R$'de $a\to b\to c$ yolu olduğu için $(a,c)\in R^2$'dir.

Hoca $R$ üzerinde şunu da gösterdi: yansımalı değildir; $a\to b$, $b\to c$ varken $a\to c$ olmadığı için geçişken değildir. Çizgeler konusunda "$a$'dan $c$'ye kaç adımda gidilir" sorusu bu kuvvetlerle tekrar ele alınacaktır. Hoca kuvvetlerin daha teknik kısmının bu ders için gerekli olmadığını, Hasse diyagramlarının da önceki hafta görüldüğünü hatırlattı.

## 4. Algoritma Kavramı

Bu bölümden sonrası, bölümde ileride alınacak veri yapıları ve otomata gibi derslere hazırlık niteliğindedir. Bölümde temel algoritma yapıları, temel problemler, fonksiyonların büyümesi ve asimptotik gösterimler, algoritma analizi işlenecektir.

"Algoritma" sözcüğü Harezmi'nin adından gelir. Slayttaki tanım (ekrandan, 00:30:00):

> Algoritma, hesaplama yapmak veya bir problemi çözmek için sonlu (finite), kesin (precise) komutlar/buyruklar/emirler (instructions) kümesidir.

- **Sonlu:** Adım sayısı bellidir; iş sonsuz bir işleme dönüşmez.
- **Kesin:** Adımlar, işlemcinin ya da programlama dilinin komut repertuvarında bulunan işlemlerle ifade edilir. Hoca bunu şöyle örnekledi: işlemci yalnız toplama yapabiliyorsa integral hesabını toplamalarla yapmak gerekir; hem toplama hem çarpma yapabiliyorsa iş kolaylaşır. Bir türev alma problemi de adım 1, adım 2, adım 3 diye, platformun komut setine sadık kalarak yazılmalıdır.

### 4.1 Algoritma nasıl ifade edilir?

Algoritma doğal dille (Türkçe, İngilizce), sözde kodla (pseudocode), akış diyagramıyla ya da doğrudan bir programlama diliyle ifade edilebilir. Hangi biçim seçilirse seçilsin kesinlik ve sonluluk korunmalıdır.

- Sözde kod bir ara basamaktır; programlamaya yeni başlayanlara yardımcı olur. Doğal dile bağlı olduğu için insanlar arasında iletişim sorunları çıkabilir.
- Akış diyagramı dilden bağımsız, daha ortak bir anlatım sağlar.
- C'de yazılmış bir kodu anlayabiliyorsanız ne sözde koda ne akış diyagramına gerek vardır.

### 4.2 Algoritma ile yaklaşım farkı

Algoritma, problem çözüm yaklaşımıyla (approach) karıştırılmamalıdır. Örneğin "bir matristeki en küçük sayıyı bulun" sorusuna "matrisi baştan sona gezerim, ilk elemanı en küçük kabul ederim, karşılaştırırım" demek bir yaklaşımdır. Bu yaklaşımı sıralı, kesin ve sonlu adımlarla yazmak algoritmadır.

## 5. Algoritmaların Özellikleri ve Maksimum Bulma Örneği

### 5.1 Maksimum bulma

Slayttaki örnek (ekrandan, 00:30:00): sonlu bir tam sayı dizisinde maksimum değeri bulan algoritma.

1. Dizinin ilk elemanı geçici maksimum olarak seçilir.
2. Bir sonraki eleman geçici maksimumla karşılaştırılır; sayı geçici maksimumdan büyükse geçici maksimuma bu sayı atanır.
3. Dizinin son elemanına kadar önceki adım tekrarlanır.
4. Algoritma sonlandığında dizideki en büyük sayı bulunur.

Hoca her adımı işlemci düzeyinde inceledi: 1. adım bir atama, 2. adım bir karşılaştırma (büyüktür/küçüktür) ve gerekirse atama, 3. adım bir döngüdür. Bunların hepsi işlemcilerde bulunan işlemlerdir; örneğin Assembly'de döngü için bir `LOOP` komutu vardır.

**Soru (hocanın sınıfa sorusu):** Bu algoritmada kesinlik açısından bir tereddüt var mı, muğlak bir adım var mı?
**Cevap:** Yok. Her adım doğrudan yapılabilir. Algoritma üç-dört adımda ifade edildiği için sonludur.

### 5.2 Algoritmaların özellikleri

Slayttaki liste (ekrandan, 00:35:00):

- **Giriş (input):** Algoritma belirli bir kümeden giriş değerlerine sahiptir.
- **Çıkış (output):** Algoritma girdi değerlerinden belirli bir kümeden çıktı değerleri üretir. Çıktı değerleri çözümdür.
- **Doğruluk (correctness):** Her girdi değeri kümesi için doğru çıktı değerleri üretilmelidir.
- **Sonluluk (finiteness):** Herhangi bir girdi için sınırlı sayıda adımdan sonra çıktı üretilmelidir.
- **Etkililik (effectiveness):** Her adım doğru ve sınırlı bir süre içinde gerçekleştirilebilmelidir. "Program çalışır ama ne zaman cevap vereceği belli değil" durumu kabul edilmez.
- **Genellik (generality):** Algoritma istenen formdaki tüm problemler için çalışmalıdır.

Genellik için hocanın örnekleri: sıralama algoritması yalnız sayıları değil, nesneleri de bir özelliğine göre sıralar. Öğrenciler numarasına, notuna ya da adının harflerine göre; meyveler şeker oranına göre; tarlalar alanına göre sıralanabilir.

### 5.3 Sözde kodla maksimum ve özelliklerin denetimi

Sözde kodda önce $\max := a_1$ yapılır, sonra $i=2$'den $n$'e kadar her $a_i$ ile karşılaştırılır ve döngü sonunda $\max$ döndürülür. Hoca bir değişiklik önerdi: maksimumun değeri yerine indisi tutulabilir ($\max := 1$), karşılaştırma $a_{\max} < a_i$ ise $\max := i$ biçiminde yapılır. Yeri bilinen bir elemanın değeri diziden her zaman okunabildiği için bu da geçerli bir çözümdür.

Özelliklerin denetimi: girdi ve çıktı vardır; doğruluk algoritmanın yapısından gelir; sonsuza giden bir durum olmadığından sonludur. İşlem sayısı için hoca şöyle hesap yaptı: bir başlangıç ataması vardır; döngü $2$'den $n$'e kadar döner ve her turda bir karşılaştırma ile bazen bir atama yapılır. Tur başına iki işlem sayılırsa yaklaşık $2n-2$, başlangıçla birlikte yaklaşık $2n$ adım çıkar. $n$ de sonludur, çünkü bellekte sonlu bir dizi tutulabilir.

Genellik: Algoritma tam sayılar yerine örneğin stringler için de kullanılabilir; yalnız bazı operatörleri (karşılaştırma gibi) uyarlamak gerekir.

## 6. Arama Algoritmaları

### 6.1 Genel algoritma problemleri

Bu derste incelenecek algoritma türleri arama, sıralama ve optimizasyondur.

- **Arama:** Bir elemanın arama uzayındaki yerinin bulunması.
- **Sıralama:** Bir listenin elemanlarını genellikle artan, bazen azalan bir sıraya koymak.
- **Optimizasyon:** Tüm olası girdiler üzerinden belirli bir büyüklüğün en iyi değerini bulmak (en düşük maliyet, en yüksek verim). Haritada A noktasından B noktasına en kısa yolu bulmak bir optimizasyon problemidir; bu tür problemlere çizgeler konusunda bakılacaktır.

### 6.2 Arama problemi

Slayttaki tanım (ekrandan, 00:40:00): genel arama problemi, ayrı elemanlardan oluşan $(a_1,a_2,\dots,a_n)$ listesinde bir $x$ elemanını bulmak ya da listede olmadığını belirlemektir. Çözüm, listedeki terimin $x$'e eşit olduğu konumdur ($x=a_i$ ise $i$); $x$ listede yoksa 0'dır. Uygulamada bulunamayan eleman için çoğu zaman 0 ya da $-1$ döndürülür.

> **Hocanın vurgusu:** Arama sadece bir sayı dizisinde eleman aramak demek değildir. Örneğin gerçel değerli bir fonksiyonun en küçük değerini bulmak da bir arama problemidir.

Hoca doğrusal ve ikili aramanın yanında üçlü (ternary) aramayı, interpolasyon aramasını ve hash veri yapısıyla aramayı da andı.

### 6.3 Doğrusal (linear) arama

Dizinin ilk elemanından başlanır, son elemana kadar ya da aranan eleman bulunana kadar tek tek bakılır. Aranan eleman bakılan elemandan farklı olduğu sürece $i$ artırılır. Döngüden sonra $i\le n$ ise eleman bulunmuştur ve konum $i$'dir; değilse konum 0 yapılır. Sonunda konum döndürülür.

En küçük ya da en büyük eleman gibi bir şey aranıyorsa arada kesilemez; dizinin sonuna kadar gidilip bütün durumlara bakılmalıdır.

Hocanın kitap örneği: 200 sayfalık bir kitapta 40. sayfa aranıyor. Doğrusal aramada 1, 2, 3, … diye ilerlenir ve 40'a gelince durulur; 200'e kadar gitmeye gerek yoktur, ama 40 bakış yapılmıştır.

### 6.4 İkili (binary) arama

Arama uzayı artan ya da azalan sırada ise elemanlara tek tek bakmaya gerek yoktur. Orta noktaya bakılır; aranan değer orta noktadakinden büyükse sol yarıya, küçükse sağ yarıya bakmaya gerek kalmaz. Orta nokta, sol uç $i$ ile sağ uç $j$'nin toplamının yarısıdır. Hoca, toplamın yarısı yerine başka oranların kullanılmasının bazı performans iyileştirmeleri sağladığını söyledi.

Slayttaki sözde kod (ekrandan, 00:45:00):

```text
procedure binary search(x: integer, a1, a2, ..., an: increasing integers)
i := 1   {i is the left endpoint of interval}
j := n   {j is right endpoint of interval}
while i < j
    m := floor((i + j)/2)
    if x > a_m then i := m + 1
    else j := m
if x = a_i then location := i
else location := 0
return location  {location is the subscript i of the term a_i equal to x, or 0 if x is not found}
```

Döngü, $i<j$ koşulu bozulunca ($i=j$ olunca) biter. Çıkıştaki $i$ konumundaki eleman $x$'e eşitse eleman bulunmuştur ve $i$ döndürülür; değilse 0 döndürülür. Hoca, $i$ ile $j$'nin birbirini geçmesinin elemanın bulunamadığını gösterdiğini de anlattı.

**Kitap örneği (ikili aramayla):** 1-200 arası sayfalarda 40 aranıyor. Hoca sözlü olarak şöyle ilerledi: önce orta nokta 100'e bakılır, 40 daha küçük olduğu için üst yarı atılır; sonra 50'ye, sonra 25'e bakılır; 25 ile 50 arası kalır; ardından 38 civarı, 44 civarı, 42 civarı ve sonunda 40 bulunur. Doğrusal aramadaki 40 bakış yerine yaklaşık 7-8 adım yeter.

Slayttaki algoritma bu örneğe birebir uygulandığında aralıklar şöyle daralır (ara adımlar eklendi, python ile doğrulandı):

| Tur | $i$ | $j$ | $m$ | Karar |
|---|---|---|---|---|
| 1 | 1 | 200 | 100 | $40\le 100$, $j:=100$ |
| 2 | 1 | 100 | 50 | $40\le 50$, $j:=50$ |
| 3 | 1 | 50 | 25 | $40>25$, $i:=26$ |
| 4 | 26 | 50 | 38 | $40>38$, $i:=39$ |
| 5 | 39 | 50 | 44 | $40\le 44$, $j:=44$ |
| 6 | 39 | 44 | 41 | $40\le 41$, $j:=41$ |
| 7 | 39 | 41 | 40 | $40\le 40$, $j:=40$ |
| 8 | 39 | 40 | 39 | $40>39$, $i:=40$ |

Döngü $i=j=40$ ile biter, $a_{40}=40$ olduğu için konum 40 döner.

En kötü durumda gereken adım sayısı eleman sayısına bağlıdır: ikili aramada yaklaşık $\log_2 n$. Bu ifade algoritma karmaşıklığında tekrar karşımıza çıkacaktır. $n=1024$ ise döngü en fazla 10 kez döner; eleman yoksa da 10 bakışta bu anlaşılır.

### 6.5 Üçlü ve interpolasyon araması

Hoca bu iki yöntemi araştırılmak üzere tanıttı.

- **Üçlü arama:** İkili aramada orta nokta $(i+j)\cdot\frac12$ ile bulunur. Hocanın anlatımında üçlü aramada aralık üçe bölünür ve $\frac12$ yerine $\frac23$ gibi bir oranla bakılır. Aranan eleman bu noktadan büyükse aralığın büyük bir kısmı atılır.
- **İnterpolasyon araması:** $\frac12$ yerine elemanların değerlerinden hesaplanan bir oran kullanılır. Bulunulan noktadan, aranan değere göre aşağıya ya da yukarıya ne kadar gidileceği bir denklemle tahmin edilir. Kitapta sayfa ararken elle yapılan tahmin buna benzer: 40. sayfa aranırken 30. sayfa açıldıysa biraz ileri gidilir, belki 42 açılır, bir iki sayfa geri gelinir; genellikle iki üç denemede bulunur.

> **Ek bilgi (derste anlatılmadı):** Yaygın tanımda üçlü arama aralığı $1/3$ ve $2/3$ noktalarındaki iki orta noktayla üç parçaya böler ve her adımda bir ya da iki parçayı atar. Sıralı dizide eleman aramada genellikle ikili aramadan daha hızlı değildir; daha çok tek tepeli (unimodal) bir fonksiyonun en büyük ya da en küçük değerini bulmakta kullanılır.

## 7. Sıralama Algoritmaları

Sıralama, elemanları artan ya da azalan bir sıraya koymaktır. Önemi ikili aramada görüldü; ayrıca veri tabanlarında ve büyük verilerde indeksleme için gereklidir. İnsanları maaşına ya da yaşına göre, dikdörtgen tarlaları alanına göre sıralamak gibi farklı türden verilere uygulanabilir. Bu kadar çok sıralama algoritması olmasının nedeni, problem çözme yaklaşımlarının çeşitliliği ve daha performanslı bir algoritma arayışıdır.

### 7.1 Kabarcık (bubble) sıralama

Slayttaki açıklama ve sözde kod (ekrandan, 00:50:00): kabarcık sıralama bir dizide birden çok geçiş yapar; sıra dışı olduğu tespit edilen her öğe çifti değiştirilir.

```text
procedure bubblesort(a1, ..., an: real numbers with n >= 2)
for i := 1 to n - 1
    for j := 1 to n - i
        if a_j > a_(j+1) then interchange a_j and a_(j+1)
{a1, ..., an is now in increasing order}
```

Birinci elemandan başlanır, yan yana iki eleman karşılaştırılır; küçükten büyüğe kuralı bozuluyorsa yer değiştirilir. Örneğin 3, 2, 1 için önce 3 ile 2, sonra 3 ile 1 yer değiştirir; ama dizi henüz sıralanmamıştır, yeni bir tur gerekir.

Hocanın adım adım anlattığı örnek: $3,2,4,1,5$.

- 1. geçiş: 3-2 değişir ($2,3,4,1,5$); 3-4 değişmez; 4-1 değişir ($2,3,1,4,5$); 4-5 değişmez. Sonuç $2,3,1,4,5$. En büyük eleman 5 en sondadır.
- 2. geçiş: 2-3 değişmez; 3-1 değişir ($2,1,3,4,5$); 3-4 değişmez. Artık 4 ikinci en büyük eleman olarak yerindedir.
- 3. geçiş: 2-1 değişir ($1,2,3,4,5$); 2-3 değişmez. 3 yerindedir.
- 4. geçiş: 1-2 değişmez. Hiç takas olmadığı için algoritma kesilebilir.

Her geçişin sonunda sona taşınan eleman garanti olarak yerindedir. Bu yüzden iç döngü $n-i$'ye kadar gider; sondaki yerleşmiş elemanlara bakmaya gerek yoktur.

### 7.2 Araya ekleme (insertion) sıralaması

Slayttaki açıklama ve sözde kod (ekrandan, 00:55:00): araya ekleme sıralaması 2. elemanla başlar; ikinci elemanı birinciyle karşılaştırır ve daha büyük değilse ilkinden önce koyar. Daha sonra 3. eleman ilk 3 eleman arasında doğru konuma getirilir. Sonraki her geçişte $n+1$. eleman ilk $n+1$ eleman arasında doğru konumuna yerleştirilir. Doğru pozisyonu bulmak için doğrusal arama kullanılır.

```text
procedure insertion sort(a1, ..., an: real numbers with n >= 2)
for j := 2 to n
    i := 1
    while a_j > a_i
        i := i + 1
    m := a_j
    for k := 0 to j - i - 1
        a_(j-k) := a_(j-k-1)
    a_i := m
{Now a1, ..., an is in increasing order}
```

`while` döngüsü $a_j$'nin gireceği ilk konumu ($i$) arar. Sonra $a_j$ yedeklenir ($m:=a_j$), $i$ ile $j-1$ arasındaki elemanlar birer sağa kaydırılır (shift) ve $a_j$ boşalan $i$. konuma yazılır.

Aynı örnek: $3,2,4,1,5$.

- $j=2$: 2, 3'ten küçük; 3 sağa kayar, 2 başa yazılır: $2,3,4,1,5$.
- $j=3$: 4, hem 2'den hem 3'ten büyük; yerinde kalır.
- $j=4$: 1 en başa girmeli. 1 yedeklenir; 4, 1'in yerine; 3, 4'ün yerine; 2, 3'ün yerine kayar; boşalan ilk konuma 1 yazılır: $1,2,3,4,5$.
- $j=5$: 5 yerinde kalır.

Hoca bu algoritmanın yapısal programlamaya giriş derslerinde de gösterilmiş olabileceğini, burada farklı bir açıdan incelendiğini söyledi.

### 7.3 Seçmeli (selection) sıralama

Her turda dizinin kalan kısmındaki en küçük eleman bulunup başa getirilir. Hocanın sayımı: ilk turda en küçük için $n$ kontrol, ikinci turda $n-1$, sonra $n-2$, … diye azalır. Bu sayılar toplandığında $n^2$ mertebesinde bir karmaşıklık çıkar; ayrıntılı analiz ileride yapılacaktır.

> **Ders sonrası not:** Hoca toplamı söylerken ifadeyi karıştırdı. Tur başına $n, n-1, \dots, 1$ kontrol sayılırsa toplam $\frac{n(n+1)}{2}$, standart sayımla ($n-1, n-2, \dots, 1$ karşılaştırma) toplam $\frac{n(n-1)}{2}$'dir. İkisi de $n^2$ mertebesindedir.

## 8. Öklid Algoritması ve OBEB

### 8.1 Kaba yaklaşım

İki sayının OBEB'i (en büyük ortak bölen, gcd) için akla gelen ilk yöntem: $m$ ve $n$'nin küçüğü $x$ bulunur; $x, x-1, x-2, \dots$ diye aşağı inilir ve iki sayıyı da tam bölen ilk değer OBEB'tir. Bu, $x$'ten 1'e doğru yapılan doğrusal arama gibidir.

### 8.2 Öklid algoritması

Slayt (ekrandan, 01:00:00):

- Problem: $\gcd(m,n)$, $m$ ve $n$'nin OBEB'i.
- Örnek: $\gcd(60,24)=12$, $\gcd(60,0)=60$.
- Öklid algoritması: $\gcd(m,n)=\gcd(n, m \bmod n)$; bu eşitlik ikinci sayı ($n$) 0 olana kadar sürer.
- Örnek: $\gcd(60,24)=\gcd(24,12)=\gcd(12,0)=12$.

Çözüm adımları: $\gcd(60,24)$'te küçük sayı 24 doğrudan birinci yere yazılır; ikinci yere $60 \bmod 24$ yazılır. $60=2\cdot 24+12$ olduğundan kalan 12'dir: $\gcd(24,12)$. İkinci sayı 0 olmadığından devam edilir: $24 \bmod 12=0$, yani $\gcd(12,0)$. İkinci sayı 0 olunca birinci sayı OBEB'tir: 12.

Kod mantığı: $n\ne 0$ olduğu sürece $r:=m \bmod n$, $m:=n$, $n:=r$; döngü bitince $m$ döndürülür.

**Hocanın ikinci örneği:** $\gcd(6,12)$. Algoritmaya göre ikinci sayı başa yazılır ve ikinci yere $6 \bmod 12$ gelir. 6, 12'ye bölünemediği için kalan 6'dır: $\gcd(12,6)$. Sonra $12 \bmod 6=0$: $\gcd(6,0)=6$. Büyük sayı sağda yazılmışsa bir iterasyon sonra yerler kendiliğinden düzelir.

### 8.3 Diğer çözümler

Slayttaki "ardışık tam sayı kontrol algoritması" (ekrandan, 01:05:00):

1. İki sayıdan küçük olanı $\{m,n\}$, $T$ değişkenine atayın.
2. $m$'yi $T$'ye bölün. Kalan 0 ise (3)'e gidin; değilse (4)'e gidin.
3. $n$'yi $T$'ye bölün. Kalan 0 ise $T$'yi döndürün ve durun; değilse (4)'e gidin.
4. $T$'yi 1 azaltın ve (2)'ye gidin.

Hoca küçük sayıdan 1'e doğru gitmeyi tercih ettiğini söyledi; 1'den yukarı da gidilebilir. Bulunan değer 1 ise iki sayı aralarında asaldır.

Asal çarpan yaklaşımı (ortaokul-lise yöntemi): sayılar asal çarpanlarına ayrılır, ortak çarpanlar alınır. Hocanın ekrana yazdığı örnek (ekrandan, 01:05:00): $x=2^3\cdot 3^2$ ve $y=3^3\cdot 2^2$ ise ortak kısım $2^2\cdot 3^2=36$'dır (python ile doğrulandı: $\gcd(72,108)=36$).

> **Hocanın vurgusu:** Bu bir algoritma değil, bir yaklaşımdır. Çünkü önce $x$ ve $y$'nin asal çarpanlarını bulmak gerekir; problemin içinden başka bir problem çıkar. "Sayıyı ver, asal çarpanlarını vereyim" diye bir komut yoktur. Bunun için ayrı bir kod yazılmalı ya da çarpanlar hazır verilmiş olmalıdır. Hazır verilmişse bu yöntemi kullanmak elbette mantıklıdır.

## 9. Algoritma Tasarım Yöntemleri ve Analiz Ölçütleri

Hoca bu bölümün her başlığının ayrı bir ders konusu olduğunu, burada yalnız tanıtım yapılacağını söyledi. Slayttaki liste (ekrandan, 01:20:00):

- **Brute force (kaba kuvvet):** Bütün olasılıkları tek tek, baştan sona denemek (exhaustive search). 1'den 100'e kadar sayıları bir döngüyle toplamak bir örnektir.
- **Divide and conquer (böl ve yönet):** Problem verisi önce yarıya, sonra onun yarısına, en küçük parçaya kadar bölünür; küçük parçaların çözümleri birleştirilerek büyük çözüme gidilir. Merge sort ve quicksort örnektir. Örneğin 8 eleman önce 4'erli, sonra 2'şerli parçalara bölünür, parçalar sıralanır ve ikişer ikişer birleştirilir.
- **Decrease and conquer (azalt ve yönet):** Bölmek yerine $n$ elemandan $n-1$'e, ondan $n-2$'ye azaltarak çözmek.
- **Transform and conquer (dönüştür ve yönet):** Bilinen bir algoritmaya veri seti uydurulur; dönüştürülmüş veri üzerinde çalışılıp asıl problem çözülür.
- **Space and time tradeoffs (zaman-bellek ödünleşimi):** Zamanın önemli olmadığı problemlerde zamandan ödün verip belleği verimli kullanmak ya da bellekten ödün verip kısa sürede çözmek. Hoca merge sort'u kısa sürede çalışan ama daha fazla bellek kullanan bir örnek olarak verdi.
- **Greedy (açgözlü):** Tam (exact) çözümü vermeden, mümkün olan en iyi çözümü bulmaya çalışan algoritmalar. Örneğin Türkiye haritasında iki şehir arasındaki belki 100 yoldan gerçekten en kısayı değil, bulunabilen en kısa yolu verir.
- **Dynamic programming (dinamik programlama):** Bir optimizasyon yöntemi; kesin optimum çözümü bulabilir.
- **Iterative improvement:** Eldeki bir çözümü her adımda daha iyi bir noktaya taşımak.
- **Backtracking:** Bir çözüme ulaşıldıktan sonra o çözüme götüren yollar üzerinden geri dönerek aramak.
- **Branch and bound:** Ağaç yapısı üzerinde en iyi çözümü ararken kullanılan bir başka teknik.

### 9.1 Transform and conquer örneği

**Soru (hocanın sınıfa sorusu):** Elimizde dizinin en küçük elemanını veren hazır bir fonksiyon var. Bu fonksiyonu kullanarak dizinin en büyük elemanını nasıl buluruz?
**Cevap (bir öğrenciden geldi, hoca onayladı):** Dizideki bütün elemanlar negatife çevrilir; bu dizinin minimumu, asıl dizinin maksimumunun negatifidir. Bulunan değerin işareti tekrar çevrilir.

Ekrandaki örnek (ekrandan, 01:20:00): dizi $3,6,8,2$ için fonksiyon doğrudan 2'yi verir. Elemanlar $-3,-6,-8,-2$ yapılırsa fonksiyon $-8$'i verir; işaret çevrilince maksimum 8 bulunur.

### 9.2 Analiz ölçütleri

Algoritmalar iki ölçütle analiz edilir: zaman verimliliği (time efficiency) ve bellek verimliliği (space efficiency). Hocanın örneği: aynı problemi çözen üç algoritma farklı süreler (10 ms, 20 ms, 5 ms gibi) ve farklı bellek miktarları (10, 20, 5 bayt gibi) kullanıyor olsun. Bir algoritma zaman açısından, öbürü bellek açısından daha iyi olabilir; hem en kısa sürede hem en az bellekle çalışan algoritma iki açıdan da avantajlıdır. <!-- BELİRSİZ: Hocanın sözlü örneğindeki sayıların hangi algoritmaya ait olduğu altyazıdan tam çıkmıyor. -->

Daha iyi bir algoritma olup olmadığı, alt sınırlar ve optimal çözümler dikkate alınarak bu iki kritere göre değerlendirilir. Bir sonraki adımda ya da farklı bir yöntemle daha iyi sonuç veren, ya da veri setinin belli sınırlarında daha iyi çalışan algoritma daha iyi kabul edilir.

### 9.3 Önemli problem türleri

- Sıralama ve arama.
- Metin işleme: bir veri içinde metin arama (text search) gibi.
- Çizge problemleri: bir kısmına bu derste bakılacak.
- Kombinasyon problemleri: örneğin $\{A,B,C\}$ alfabesiyle üç elemanlı kaç farklı dizilim oluşturulabileceği; şifre oluşturma problemi bir örnektir.
- Geometrik problemler: çizgelerin çizilmesi, bilgisayar grafiği.
- Sayısal problemler: sayısal analiz ve sayısal işaret işleme konuları. Örneğin Fourier dönüşümünün $n^2$ karmaşıklığı hızlı Fourier dönüşümüyle (FFT) $n\log n$'e indirilmiştir.

## 10. Temel Veri Yapıları

### 10.1 Veri yapısı neden gerekir?

Bilgisayarda bir işlemci, komutların ve verilerin tutulduğu bir bellek (RAM) ve kalıcı bir depolama (HDD) vardır. Algoritmanın hızlı çalışması için veriye hızlı ulaşmak gerekir; bunun için veri, ister kalıcı ister uçucu bellekte, en uygun şekilde düzenlenmelidir. Hızlı erişim için yapılan bu düzenleme tekniklerine veri yapıları denir.

Hocanın örneği: 100 öğrencinin vize notu 100 ayrı değişkenle tutulabilir, ama bunlar üzerinde program yazmak çok verimsizdir. Bunun yerine 100 elemanlı bir dizi kullanılır; öğrenci başına iki not tutulacaksa $100\times 2$ boyutlu bir matris kullanılır.

Bellek fiziksel olarak tek boyutludur. İki, üç ya da daha çok boyutlu yapılar mantıksal düzeydedir. Örneğin bir not matrisi iki boyutlu görünür ama bellekte art arda dizilmiş bir sayı dizisidir; bir kısmı birinci notları, bir kısmı ikinci notları tutar.

### 10.2 Veri yapıları listesi

Slayt (ekrandan, 01:30:00):

- Listeler: dizi (array), bağlantılı liste (linked list), string
- Yığın (stack)
- Kuyruk (queue)
- Öncelikli kuyruk (priority queue)
- Çizge (graf)
- Ağaçlar
- Kümeler

Çizge, noktalar ve kenarlar kümesi olarak düşünülen ve matrislerle de temsil edilebilen bir yapıdır; ayrıntılı işlenecektir. Ağaçlar çizgelerin bir alt sınıfıdır. Kümeler, hash set gibi yapılarla karşımıza çıkar.

### 10.3 Dizi

Dizide elemanlar bellekte art arda gelir: bir eleman $P$ adresindeyse sonraki $P+1$ adresindedir. Elemanlar genelde aynı türdendir, ama bazı dillerde farklı türler de saklanabilir. Birinci elemanın adresi bilinirse indis aritmetiğiyle ya da (C'de) işaretçi aritmetiğiyle her elemana doğrudan erişilir.

Dezavantaj: dinamik bellek kullanılsa bile bitişik yer gerektiği için istenen büyüklükte dizi ayrılamayabilir. Örneğin bellekte bir milyon elemanlık boş yer vardır ama bir milyon elemanlık bitişik yer yoktur. Araya eleman eklemek de zordur: sondan başlayarak elemanlar birer kaydırılır, sonra eleman araya yazılır.

### 10.4 Bağlantılı liste

Bağlantılı listede elemanlar bellekte dağınık yerlerdedir. İlk elemana head denir. Her düğüm (node) bir veri ve bir sonraki düğümün adresini tutar; son düğüm null adresini tutar ve listenin bittiğini gösterir. Bitişik yer gerekmediği için bellekte yer bulmak daha kolaydır.

Dezavantaj: dizide üçüncü ya da sekizinci elemana doğrudan erişilirken bağlantılı listede rastgele erişim yoktur; aranan eleman için head'den başlayarak ilerlemek gerekir.

Ekleme işlemleri:

- **Araya ekleme:** Ekleneceği yere kadar ilerlenir. Önceki düğümün gösterdiği adres yedeklenir; yeni düğüm bu adresi gösterir, önceki düğüm de yeni düğümü gösterir. Diğer elemanlar kaydırılmaz, yalnız bağlantılar değişir.
- **Sona ekleme:** Son düğüm artık null yerine yeni düğümü gösterir; yeni düğümün bağlantısı null yapılır.

Dizi ya da bağlantılı listenin her elemanında tek bir tam sayı değil birden fazla veri saklanabilir. Hoca, yapısal programlamada önce tam sayı dizileriyle çalışıldığını, struct ve struct dizileri konusunda birden fazla veri tutan elemanlarla çalışılacağını ve bağlantılı listelerin orada da kurulacağını söyledi. Ayrıntılı gerçekleme ve analiz veri yapıları dersindedir.

**Soru (bir öğrenci):** Bağlantılı listede sona ulaşmak için her seferinde baştan sona gitmek gerekmez mi?
**Cevap:** Görünüşte öyle, ama yardımcı bir işaretçiyle son düğüm her zaman saklanabilir. Bir işaretçi head'i (örneğin `p_head`), diğeri son düğümü (örneğin `p_last`) tutar; her ekleme ve silmede `p_last` güncellenir. Böylece son düğüme doğrudan erişilir.

## 11. Kuyruk ve Yığın

Kuyruk ve yığın dizilerden ya da listelerden türeyen, özel amaçlı veri yapılarıdır. Dizide herhangi bir elemana baştan, ortadan, sondan erişilip değiştirilebilir, silinebilir. Kuyruk ve yığında ise yalnız izin verilen elemana erişilir; temel işlemler ekleme ve silmedir.

### 11.1 Kuyruk (queue)

Günlük hayattaki kuyruktan farkı yoktur: ilk gelen ilk çıkar (FIFO). İki temel işlem vardır: ekleme (add, in, enqueue) ve çıkarma (remove, out, dequeue). Ekleme kuyruğun sonundan, çıkarma başından yapılır; araya ekleme yapılamaz. İlk ve son noktayı gösteren iki işaretçi ya da indis tutulur. Kuyruk dizilerle de bağlantılı listelerle de gerçeklenebilir.

Kullanım örneği: işletim sistemleri süreçleri işlemciye bir sıraya göre alır; kuyruğa ilk gelen süreç önce işlemciye gider.

**Öncelikli kuyruk (priority queue):** Gelen verinin içeriğine bakılarak araya ekleme yapılan kuyruktur; dizide araya ekleme mantığına benzer. Heap veri yapısı öncelikli kuyruğun bir türüdür ve onu gerçeklemekte kullanılır.

### 11.2 Yığın (stack)

Yığında son gelen ilk çıkar (LIFO, ya da ilk gelen son çıkar: FILO). Ekleme işleminin özel adı push, çıkarma işleminin özel adı pop'tur. Dizi genelde yatay gösterilir; yığın push ve pop'u daha iyi anlatmak için düşey gösterilir: alttan yukarı 0., 1., 2., … elemanlar. Bağlantılı liste olarak düşünülürse en üstteki eleman head olur.

Ekleme de çıkarma da yalnız en üstten yapılır; yığında öncelik ya da araya ekleme yoktur. Üst üste konmuş tabaklar gibidir: tabak en üste konur, en üstten alınır.

**Soru (bir öğrenci):** Yığını dizi ile mi bağlantılı listeyle mi gerçeklemek daha verimlidir?
**Cevap:** Uygulamaya göre değişir. Bellek ya da zaman açısından dizi daha hızlı sonuç veriyorsa dizi, işe yaramıyorsa bağlantılı liste kullanılır; "illa dizi kullanılacak" diye bir kural yoktur.

Kullanım alanları:

- İşlemcideki yığın işaretçisi (stack pointer): fonksiyon çağrısında programın kaldığı yerden devam edebilmesi için gereken bilgiler yığın mantığıyla saklanır.
- Matematiksel ifadelerin değerlendirilmesi (bir sonraki bölüm).
- Parantez dengesinin denetlenmesi ve bir stringin ters çevrilmesi.

### 11.3 Parantez dengesi ve string ters çevirme

Bir ifadede parantezlerin kurallı kapatılıp kapatılmadığı yığınla denetlenir. Açma parantezi gelince yığına eklenir. Kapama parantezi gelince yığının üstündeki eleman çıkarılmaya çalışılır; üstteki açma parantezi bu kapama parantezinin eşiyse çıkarılır, değilse çıkarılamaz. İfadenin sonunda yığın boşsa ifade kurallıdır. Örneğin yuvarlak parantezin üstüne köşeli parantez eklenmişse ve yuvarlak kapama gelirse üstteki köşeli parantezle eşleşmez; sonunda yığın dolu kalır ve ifade hatalı sayılır.

String ters çevirme: A, B, C, D sırayla yığına eklenir; ifade bitince tek tek çıkarılır ve D, C, B, A elde edilir.

Hoca bu kontrolün infix değerlendirmeden önce bir ön işlem olarak yapılması gerektiğini söyledi: önce yalnız parantezler yığınla taranır, yığın sonda boşsa değerlendirmeye geçilir.

## 12. Yığın Uygulamaları: Infix, Prefix, Postfix Gösterimleri

Bir matematiksel ifade operatörler ve operandlardan oluşur; bunlar farklı sıralarla yazılabilir. Günlük hayatta $(A+B)\times C$ gibi yazılır ve parantez işlem önceliğini gösterir. Derleyicilerin parantezlerle uğraşmak yerine işlem önceliğini operatörlerin yerinden anlaması için farklı gösterimler geliştirilmiştir: sıralama farklı ama sonuç aynıdır.

Slayt (ekrandan, 01:45:00):

- **Infix gösterimi:** Operatör iki operandın ortasındadır. Örnek: $A+B$, $7-9$.
- **Prefix gösterimi:** Operatör iki operandın önündedir; Polish Notation (PN). Örnek: $+AB$, $-\,7\,9$.
- **Postfix gösterimi:** Operatör iki operandın sonundadır; Reverse Polish Notation. Örnek: $AB+$, $7\,9\,-$.
- Bilgisayar sistemlerinde infix yazımdaki operatör önceliğinin çözümlenmesi zor olduğundan postfix/prefix dönüşümü ile işlemlerin sonucu hesaplanır.
- Dönüşümler infix ↔ postfix, infix ↔ prefix, prefix ↔ postfix olabilir.
- Verilen bir ifadenin sayısal sonucunun hesaplanması çok sık karşılaşılan bir uygulamadır.
- Dönüşümlerde yığın ya da ikili ağaçlar kullanılır.

Yığınla yapılan çözüm basit işlemlerle (yalnız ekle-sil) yapılır ama algoritması biraz karmaşıktır. Ağaçlarda daha çok işlem yapılabildiği için dönüşüm daha kolaydır; ağaçlar konusunda tekrar görülecektir. İkisini de bilmek gerekir.

> **Hocanın vurgusu:** "Sol operand, operatör, sağ operand" gibi kalıpları ezberlemeye gerek yok. Operatör içerideyse infix, öndeyse prefix, sondaysa postfix. Ağaçlardaki inorder, preorder, postorder dolaşmaları da aynı mantıktadır. Bunları şimdiden örneklerle kafanızda kodlarsanız ileride çok rahat edersiniz.

Örneğin $A+B$ infix'tir. Postfix'e dönüştürmek için önce birinci operand, sonra ikinci operand, sonra operatör yazılır: $AB+$.

Derste kabul edilen ifadeler: operandlar sayısal (gerçel) değerlerdir; operatörler toplama, çıkarma, çarpma, bölme, mod ve üs almadır; aralarda boşluk ve parantez kullanılabilir. Öncelik sırası: en üstte üs alma, sonra çarpma ve bölme, sonra toplama ve çıkarma. Parantezler bu sırayı değiştirmek için kullanılır.

## 13. İfadelerin Yığınla Değerlendirilmesi

### 13.1 Infix ifadenin değerlendirilmesi (iki yığın)

Bir operand yığını ve bir operatör yığını kullanılır. Slayttaki algoritma (ekrandan, 01:50:00), ifadeyi karakter karakter tarar:

1. Karakter operandsa operand yığınına push edilir.
2. Karakter operatörse:
   - Operatör yığını boşsa operatör yığınına push edilir.
   - Boş değilse: karakterin önceliği yığının üstündeki operatörün önceliğinden büyük ya da ona eşitse karakter operatör yığınına push edilir. Küçükse, karakterin önceliği küçük kalmayana ya da yığın boşalana kadar "Process" yapılır.
3. Karakter "(" ise operatör yığınına push edilir.
4. Karakter ")" ise operatör yığınında eşi olan "(" görülene kadar Process yapılır, sonra "(" çıkarılır.

İfade bitince operatör yığını boş değilse, boşalana kadar Process yapılır. Operand yığınında kalan değer sonuçtur. Process: operand yığınından iki değer, operatör yığınından bir operatör çekilir, işlem yapılır, sonuç operand yığınına push edilir.

**Örnek (ekrandan, 01:55:00 ve 02:00:00):** $2*(5*(3+6))/15-2$

| Token | İşlem | Operand yığını | Operatör yığını |
|---|---|---|---|
| 2 | operand yığınına | 2 | |
| * | operatör yığınına | 2 | * |
| ( | operatör yığınına | 2 | * ( |
| 5 | operand yığınına | 2 5 | * ( |
| * | operatör yığınına | 2 5 | * ( * |
| ( | operatör yığınına | 2 5 | * ( * ( |
| 3 | operand yığınına | 2 5 3 | * ( * ( |
| + | operatör yığınına | 2 5 3 | * ( * ( + |
| 6 | operand yığınına | 2 5 3 6 | * ( * ( + |
| ) | 6 ve 3 çek, + çek, $6+3=9$, 9'u push, ( çek | 2 5 9 | * ( * |
| ) | 9 ve 5 çek, * çek, $9*5=45$, push, ( çek | 2 45 | * |
| / | önceliği * ile eşit, push | 2 45 | * / |
| 15 | operand yığınına | 2 45 15 | * / |
| - | / daha öncelikli: 15 ve 45 çek, $45/15=3$, push | 2 3 | * |
| | * daha öncelikli: 3 ve 2 çek, $3*2=6$, push | 6 | |
| | - operatör yığınına | 6 | - |
| 2 | operand yığınına | 6 2 | - |
| son | 2 ve 6 çek, - çek, $6-2=4$, push | 4 | |

Sonuç 4'tür (python ile doğrulandı).

Hocanın bu örnek üzerindeki açıklamaları:

- Operand yığınından ilk çekilen değer sağ operand, ikinci çekilen sol operanddır. $6+3$'te bu fark etmez, ama bölme ve çıkarmada önemlidir.
- Slayt bölme ve çıkarma adımlarında operandların sırasını açıkça yazmamış. 15 ilk çekilir ve sağa, 45 ikinci çekilir ve sola yazılmalıdır: $45/15=3$. Çıkarmada da 2 ilk çekilir, 6 ikinci çekilir: $6-2=4$. Slaytta bunun tanımlanması gerekirdi.
- Eksi geldiğinde hemen eklenmez; önce kendisinden yüksek öncelikli bölme, sonra çarpma işlenir. Eksi ancak bunlardan sonra operatör yığınına girer.

> **Ders sonrası not:** Slayttaki algoritma, önceliği yığının üstündekine eşit olan operatörü doğrudan push ediyor. Bu, aynı öncelikli operatörleri sağdan sola işler. $+,-,*,/$ soldan sağa birleştiği için bu kural bazı ifadelerde yanlış sonuç verir: örneğin $8-2+1$ için algoritma önce $2+1=3$, sonra $8-3=5$ hesaplar, doğrusu $7$'dir (python ile doğrulandı). Standart çözümde, gelen operatörün önceliği üstteki operatörün önceliğinden küçük ya da ona eşitse (üs alma hariç) önce Process yapılır. Derste çözülen örnekte bu fark sonucu değiştirmez.

### 13.2 Prefix ifadenin değerlendirilmesi (tek yığın)

Hoca bu kısma geçmeden önce slaydı düzeltmek için kısa bir ara verdi. Önce yığın kullanmadan kısa yolu gösterdi: ifade sondan başa doğru taranır; bir operatör görülünce kendisinden sonra gelen ilk iki operand o operatörle işleme sokulur ve sonuç yerine yazılır.

Slayttaki örnekler (ekrandan, 02:15:00):

- Prefix `+ 500 40`, sonuç 540; infix karşılığı $500+40$.
- Prefix `- / * 20 * 50 + 3 6 300 2`, sonuç 28; infix karşılığı $20*(50*(3+6))/300-2$.

İkinci örneğin kısa yoldan çözümü:

1. Sondan başa ilk operatör $+$: $3+6=9$.
2. Sonraki operatör $*$: $50*9=450$.
3. Sonraki $*$: $20*450=9000$.
4. Sonraki $/$: $9000/300=30$.
5. Sonraki $-$: $30-2=28$.

Slayttaki yığın algoritması: verilen ifade ters çevrilir ve karakter karakter taranır.

1. Karakter rakamsa bir `temp` stringi başlatılır; rakam olmayan karakter gelene kadar rakamlar `temp`'e eklenir. Ters çevrilmiş `temp` sayıya dönüştürülür ve yığına push edilir. Örneğin ters çevrilmiş ifadede 300 sayısı `003` olarak gelir; bu yüzden bir daha ters çevrilip 300 elde edilir.
2. Karakter operatörse yığından bir operand çekilir ($s_1$), bir operand daha çekilir ($s_2$); $s_1 \;\text{op}\; s_2$ hesaplanıp sonuç yığına push edilir.
3. İfade bitince yığında sonuç kalır; pop edilip döndürülür.

Yığınla çözüm: 2, 300, 6, 3 push edilir (boşluklar sayıları ayırır). $+$ gelince $s_1=3$, $s_2=6$ çekilir, $9$ push edilir. 50 push edilir. $*$ gelince 50 ve 9 çekilir, 450 push edilir. 20 push edilir. $*$ gelince 20 ve 450 çekilir, 9000 push edilir. $/$ gelince $s_1=9000$, $s_2=300$ çekilir, 30 push edilir. $-$ gelince $s_1=30$, $s_2=2$ çekilir, 28 push edilir. Sonuç 28 (python ile doğrulandı).

> **Hocanın vurgusu:** Infix değerlendirmede iki yığın kullanılmıştı; prefix'te tek yığın yetti, operatörler yığına atılmadı. Prefix ifadede parantez yoktur ve operatör önceliği kontrolü yapılmaz ("aşağıda çarpma var, önce onu hallet" gibi bir bekleme yoktur). Derleyicilerdeki kolaylık buradan gelir.

Hoca sınavda bu işlemin yığınla, yığın kullanmadan (kısa yoldan) ya da ağaçlarla yapılmasının istenebileceğini söyledi.

### 13.3 Postfix ifadenin değerlendirilmesi (tek yığın)

Algoritma: ifade baştan taranır. Karakter operandsa yığına push edilir. Operatörse bir operand çekilir ($s_1$), bir daha çekilir ($s_2$), $s_2 \;\text{op}\; s_1$ hesaplanır ve sonuç push edilir. Prefix'ten farkı operandların yeridir; ters çevirme de yapılmaz.

Slayttaki örnek (ekrandan, 02:20:00): `2536+**5/2-`

| Token | İşlem | Yığın |
|---|---|---|
| 2, 5, 3, 6 | sırayla push | [2, 5, 3, 6] |
| + | 6 ve 3 çek, $3+6=9$ push | [2, 5, 9] |
| * | 9 ve 5 çek, $5*9=45$ push | [2, 45] |
| * | 45 ve 2 çek, $2*45=90$ push | [90] |
| 5 | push | [90, 5] |
| / | 5 ve 90 çek, $90/5=18$ push | [18] |
| 2 | push | [18, 2] |
| - | 2 ve 18 çek, $18-2=16$ push | [16] |

Sonuç 16'dır (python ile doğrulandı). Yığın kullanmadan kısa yol: baştan sona gidilir, ilk görülen operatör kendisinden önceki iki operandla işlenir: $3+6=9$, $5*9=45$, $2*45=90$, $90/5=18$, $18-2=16$.

Hoca, prefix ifadeyi değerlendirmenin dolaylı yoldan postfix gibi işlem yapmak olduğunu, bu yüzden postfix'te ters çevirme gerekmediğini belirtti. Ayrıca bir alıştırma önerdi: infix değerlendirme örneğindeki ifadeyi önce postfix'e ya da prefix'e çevirip sonra değerlendirmek.

> **Hocanın vurgusu:** Prefix ve postfix ifadelerde parantez yoktur ve operatör önceliğine bakmaya gerek yoktur; ifade zaten öncelik sırasına göre dizilmiştir.

## 14. Gösterimler Arası Dönüşümler

### 14.1 Infix'ten postfix'e

Infix'te parantez ve işlem öncelikleri olduğu için bu dönüşüm diğerlerinden biraz karışıktır. Bir operatör yığını ve bir sonuç (result) stringi kullanılır.

Hocanın okuduğu algoritma: karakter operandsa sonuca eklenir. Operatörse: yığın boşsa push edilir; boş değilse ve gelen operatörün önceliği üstteki operatörünkinden büyük ya da ona eşitse push edilir; küçükse üstteki operatör pop edilip sonuca eklenir. Açma parantezi yığına eklenir; kapama parantezi gelince açma parantezi görülene kadar pop edilip sonuca eklenir, parantezin kendisi sonuca eklenmez. İfade bitince yığında kalanlar sırayla sonuca eklenir.

Slayttaki örnek (ekrandan, 02:25:00): `A+B*(C^D-E)`

| Token | İşlem | Sonuç | Yığın |
|---|---|---|---|
| A | sonuca ekle | A | |
| + | push | A | + |
| B | sonuca ekle | AB | + |
| * | $*$, $+$'dan öncelikli; push | AB | + * |
| ( | push | AB | + * ( |
| C | sonuca ekle | ABC | + * ( |
| ^ | push | ABC | + * ( ^ |
| D | sonuca ekle | ABCD | + * ( ^ |
| - | $-$, ^'dan düşük; ^ pop edilip sonuca, sonra - push | ABCD^ | + * ( - |
| E | sonuca ekle | ABCD^E | + * ( - |
| ) | ( görülene kadar pop: - sonuca; ( atılır | ABCD^E- | + * |
| son | kalanlar: *, + | ABCD^E-*+ | |

Sonuç: `ABCD^E-*+`. Okunuşu: önce $C$ üzeri $D$ alınır (parantez içindeki en öncelikli işlem); bunun sonucundan $E$ çıkarılır; çıkan değer $B$ ile çarpılır; en sonda $A$ ile toplanır.

### 14.2 Infix'ten prefix'e

Infix'ten prefix'e doğrudan bir dönüşüm algoritması yoktur; dolaylı yapılır:

1. Infix ifade ters çevrilir.
2. Ters çevrilen ifadedeki parantezler de ters çevrilir (açma kapama olur, kapama açma olur).
3. Infix-postfix dönüşümü uygulanır.
4. Çıkan sonuç ters çevrilir.

Slayttaki örnek (ekrandan, 02:30:00): `A+B*(C^D-E)`

- Ters çevrilmiş infix: `)E-D^C(*B+A`
- Parantezler çevrilmiş: `(E-D^C)*B+A`
- Postfix dönüşümü adımları: ( push; E sonuca; - push; D sonuca; ^ push (eksiden öncelikli); C sonuca; ) gelince ^ ve - pop edilip sonuca, ( atılır: `EDC^-`; * push; B sonuca: `EDC^-B`; + gelince daha öncelikli * pop edilip sonuca, + push: `EDC^-B*`; A sonuca: `EDC^-B*A`; sonda + pop: `EDC^-B*A+`.
- Ters çevrilmiş sonuç, yani prefix: `+A*B-^CDE`.

Okunuşu (prefix değerlendirme mantığıyla sondan başa): önce $C^D$ hesaplanır, bundan $E$ çıkarılır, sonuç $B$ ile çarpılır, en sonda $A$ eklenir.

> **Ders sonrası not:** Hoca okunuşu anlatırken "$C^D$'nin sonucunu $E$'den çıkaracağız" dedi. İfade $C^D-E$ olduğu için doğrusu $E$'nin $C^D$'den çıkarılmasıdır.

### 14.3 Postfix'ten infix'e

Tek yığın kullanılır, ama bu kez yığına operandlar ve ara ifadeler (stringler) atılır. Karakter operandsa yığına push edilir. Operatörse bir eleman çekilir ($s_1$), bir eleman daha çekilir ($s_2$); `(s2 op s1)` stringi oluşturulup yığına push edilir. Infix'e dönüştürüldüğü için her ara ifadenin başına ve sonuna parantez eklemek doğru olur. İfade bitince yığındaki tek eleman sonuçtur.

Slayttaki örnek (ekrandan, 02:35:00): `ABC/-AK/L-*`

| Token | İşlem | Yığın |
|---|---|---|
| A, B, C | push | [A, B, C] |
| / | C ve B çek, (B/C) push | [A, (B/C)] |
| - | (B/C) ve A çek, (A-(B/C)) push | [(A-(B/C))] |
| A, K | push | [(A-(B/C)), A, K] |
| / | K ve A çek, (A/K) push | [(A-(B/C)), (A/K)] |
| L | push | [(A-(B/C)), (A/K), L] |
| - | L ve (A/K) çek, ((A/K)-L) push | [(A-(B/C)), ((A/K)-L)] |
| * | iki ifadeyi çek, çarpımı push | [((A-(B/C))*((A/K)-L))] |

Sonuç: $((A-(B/C))*((A/K)-L))$. Hoca, köşeli parantezlerin yalnız yığının sınırlarını gösterdiğini, ifadenin parçası olmadığını belirtti. Bu dönüşümle ifade hiçbir belirsizlik olmadan infix'e çevrilir.

### 14.4 Prefix'ten postfix'e

Algoritma: ifade sağdan sola taranır. Karakter operandsa yığına push edilir. Operatörse $s_1$ ve $s_2$ çekilir, `s1 s2 op` stringi push edilir. Postfix'te operatör sonda olduğu için operatör en sona yazılır.

Slayttaki örnek (ekrandan, 02:40:00): `*-A/BC-/AKL`, sağdan sola okunur.

| Token | İşlem | Yığın |
|---|---|---|
| L, K, A | push | [L, K, A] |
| / | A ($s_1$) ve K ($s_2$) çek, AK/ push | [L, AK/] |
| - | AK/ ve L çek, AK/L- push | [AK/L-] |
| C, B | push | [AK/L-, C, B] |
| / | B ve C çek, BC/ push | [AK/L-, BC/] |
| A | push | [AK/L-, BC/, A] |
| - | A ve BC/ çek, ABC/- push | [AK/L-, ABC/-] |
| * | ABC/- ve AK/L- çek, ABC/-AK/L-* push | [ABC/-AK/L-*] |

Sonuç: `ABC/-AK/L-*`. Hiç parantez kullanılmadığına dikkat edilmelidir. Bu sonuç, önceki bölümdeki postfix-infix örneğinin girdisiyle aynıdır.

**Soru (bir öğrenci):** Derleyiciler prefix mi postfix mi kullanır?
**Cevap:** Bu derleyiciye göre değişir; hangi derleyicinin hangisini kullandığını bilmediğini söyledi. Ancak prefix bazı durumlarda postfix'e dönüştürüldüğü için postfix daha mantıklı görünebilir.

### 14.5 Prefix'ten infix'e ve postfix'ten prefix'e

Hoca bu iki dönüşümü slaytta olmadığı için kaynak siteden kısaca gösterdi.

- **Prefix'ten infix'e:** Örnek `+AB` → `A+B`. İfade sağdan sola okunur. Operandsa yığına push edilir; operatörse $s_1$ ve $s_2$ çekilir, `(s1 op s2)` push edilir. `*-A/BC-/AKL` için önce L, K, A push edilir; / gelince $s_1=A$, $s_2=K$ çekilir ve $(A/K)$ push edilir; - gelince $(A/K)$ ve L çekilir, $((A/K)-L)$ push edilir; ifade bu şekilde devam eder.
- **Postfix'ten prefix'e (ekrandan, 02:45:00):** Örnek `AB+` → `+AB`; `ABC/-AK/L-*` → `*-A/BC-/AKL`. İfade soldan sağa okunur. Operandsa push edilir; operatörse $s_1$ ve $s_2$ çekilir ve `op s2 s1` stringi push edilir. Örneğin A, B, C push edildikten sonra / gelince önce C, sonra B çekilir; önce operatör, sonra B, sonra C yazılır: `/BC`.

Hoca, kuyruğun da çok sayıda uygulaması olduğunu, onlara çizgeler konusunda değinileceğini söyledi. Algoritma analizi bir sonraki konudur.

## Örnek Sorular

**1. (derste sözlü, 00:14:07)** Bir bağıntının yansımalı olmadığını kanıtlamak için hangi ispat yöntemi kullanılır?

> **Çözüm:** Aksine örnek göstermek. Kümede $(a,a)\notin R$ olan tek bir $a$ bulmak yeterlidir.

**2. (ekrandan, 00:15:00)** $R_1=\{(a,b)\mid a\le b\}$, $R_2=\{(a,b)\mid a>b\}$, $R_5=\{(a,b)\mid a=b+1\}$ bağıntılarının tam sayılar üzerinde simetrik olmadığını gösterin.

> **Çözüm:** $R_1$: $(3,4)\in R_1$ ama $(4,3)\notin R_1$. $R_2$: $(4,3)\in R_2$ ama $(3,4)\notin R_2$. $R_5$: $(4,3)\in R_5$ çünkü $4=3+1$, ama $(3,4)\notin R_5$ çünkü $3\ne 4+1$.

**3. (ekrandan, 00:20:00)** Düğümleri $a,b,c,d$, kenarları $a\to b$, $b\to d$, $d\to b$ olan yönlü çizgenin gösterdiği bağıntı yansımalı, simetrik, antisimetrik, geçişken midir?

> **Çözüm:** Döngü yok, yansımalı değil. $a\to b$ var, $b\to a$ yok; simetrik değil. $b\to d$ ve $d\to b$ birlikte var; antisimetrik değil. $a\to b$, $b\to d$ var ama $a\to d$ yok; geçişken değil.

**4. (ekrandan, 00:25:00)** $R=\{(a,b),(b,c),(c,d),(d,b)\}$ için $R^2$, $R^3$, $R^4$'ü bulun.

> **Çözüm:** $R^2=\{(a,c),(b,d),(c,b),(d,c)\}$, $R^3=\{(a,d),(b,b),(c,c),(d,d)\}$, $R^4=R$. Her $(x,y)\in R^n$ çifti $R$'de $x$'ten $y$'ye $n$ uzunluğunda bir yola karşılık gelir.

**5. (ekrandan, 00:30:00)** Sonlu bir tam sayı dizisinde maksimum değeri bulmak için bir algoritma yazınız.

> **Çözüm:** Dizinin ilk elemanı geçici maksimum seçilir. Sıradaki eleman geçici maksimumla karşılaştırılır; daha büyükse geçici maksimuma atanır. Bu adım son elemana kadar tekrarlanır. Algoritma bittiğinde geçici maksimum dizideki en büyük sayıdır.

**6. (derste sözlü, 00:30:50)** Bu maksimum bulma algoritmasında kesinlik ya da sonluluk açısından bir sorun var mı?

> **Çözüm:** Yok. Her adım işlemcide bulunan atama, karşılaştırma ve döngü işlemleriyle yapılır; adım sayısı sonludur.

**7. (ekrandan, 00:45:00)** Slayttaki ikili arama algoritmasıyla 1'den 200'e kadar sıralı sayılar içinde 40'ı arayın. (Hoca kitapta 40. sayfayı arama örneği olarak sordu.)

> **Çözüm:** Aralıklar $[1,200]\to[1,100]\to[1,50]\to[26,50]\to[39,50]\to[39,44]\to[39,41]\to[39,40]\to[40,40]$ olarak daralır; 8 turdan sonra $a_{40}=40$ bulunur. Doğrusal aramada 40 bakış gerekirdi.

**8. (ekrandan, 01:00:00)** $\gcd(60,24)$ ve $\gcd(60,0)$ nedir? Öklid algoritmasıyla gösterin.

> **Çözüm:** $\gcd(60,24)=\gcd(24,60 \bmod 24)=\gcd(24,12)=\gcd(12,24 \bmod 12)=\gcd(12,0)=12$. $\gcd(60,0)=60$.

**9. (derste sözlü, 01:02:36)** $\gcd(6,12)$'yi Öklid algoritmasıyla bulun.

> **Çözüm:** $\gcd(6,12)=\gcd(12, 6 \bmod 12)=\gcd(12,6)=\gcd(6, 12 \bmod 6)=\gcd(6,0)=6$.

**10. (ekrandan, 01:05:00)** $x=2^3\cdot 3^2$ ve $y=3^3\cdot 2^2$ sayılarının OBEB'ini asal çarpanlarla bulun.

> **Çözüm:** Ortak asal çarpanların küçük kuvvetleri alınır: $2^2\cdot 3^2=36$.

**11. (derste sözlü, 01:18:03)** Dizinin en küçük elemanını veren hazır bir fonksiyonu kullanarak dizinin en büyük elemanı nasıl bulunur?

> **Çözüm:** Bütün elemanlar negatife çevrilip fonksiyona verilir; dönen değerin işareti çevrilir. $3,6,8,2$ için $-3,-6,-8,-2$'nin minimumu $-8$'dir; maksimum 8'dir.

**12. (ekrandan, 01:55:00)** Infix ifade $2*(5*(3+6))/15-2$'yi operand ve operatör yığınlarıyla değerlendirin.

> **Çözüm:** $6+3=9$, $9*5=45$, $45/15=3$, $3*2=6$, $6-2=4$. Sonuç 4. Adımlar 13.1'deki tablodadır.

**13. (ekrandan, 02:15:00)** Prefix ifadeler `+ 500 40` ve `- / * 20 * 50 + 3 6 300 2`'yi değerlendirin.

> **Çözüm:** İlki $500+40=540$. İkincisi sondan başa: $3+6=9$, $50*9=450$, $20*450=9000$, $9000/300=30$, $30-2=28$.

**14. (ekrandan, 02:20:00)** Postfix ifade `2536+**5/2-`'yi yığınla değerlendirin.

> **Çözüm:** $3+6=9$, $5*9=45$, $2*45=90$, $90/5=18$, $18-2=16$. Sonuç 16.

**15. (derste sözlü, 02:21:39)** Infix değerlendirme örneğindeki $2*(5*(3+6))/15-2$ ifadesini önce postfix'e çevirin, sonra postfix ifadeyi değerlendirin.

> **Çözüm (derste verilmedi):** Postfix karşılığı `2 5 3 6 + * * 15 / 2 -`. Değerlendirme: $3+6=9$, $5*9=45$, $2*45=90$, $90/15=6$, $6-2=4$. Sonuç infix değerlendirmeyle aynı, 4'tür (python ile doğrulandı).

**16. (ekrandan, 02:25:00 ve 02:30:00)** `A+B*(C^D-E)` ifadesini postfix'e ve prefix'e dönüştürün.

> **Çözüm:** Postfix: `ABCD^E-*+`. Prefix: ifade ters çevrilir ve parantezler çevrilir (`(E-D^C)*B+A`), postfix dönüşümü `EDC^-B*A+` verir, bunun tersi `+A*B-^CDE` prefix sonuçtur.

**17. (ekrandan, 02:35:00)** Postfix ifade `ABC/-AK/L-*`'yi infix'e dönüştürün.

> **Çözüm:** $((A-(B/C))*((A/K)-L))$.

**18. (ekrandan, 02:40:00)** Prefix ifade `*-A/BC-/AKL`'yi postfix'e dönüştürün.

> **Çözüm:** Sağdan sola taranır; sonuç `ABC/-AK/L-*`.

## Dersin Toparlaması

Ders, bağıntı özelliklerinin aksine örneklerle, matrislerle ve yönlü çizgelerle nasıl okunacağını gösteren örneklerle başladı; kitap slaytlarındaki bazı hatalı açıklamalar düzeltildi ve bir bağıntının kuvvetlerinin çizgedeki $n$ uzunluklu yollara karşılık geldiği görüldü. Ardından algoritma kavramına geçildi: algoritma sonlu ve kesin komutlar kümesidir; giriş, çıkış, doğruluk, sonluluk, etkililik ve genellik özelliklerini taşımalıdır ve bir problem çözme yaklaşımından ayrılır. Arama (doğrusal, ikili, üçlü, interpolasyon), sıralama (kabarcık, araya ekleme, seçmeli) ve Öklid algoritması örnekleriyle algoritmaların adım sayısına dair ilk sezgiler kazanıldı; ikili aramanın yaklaşık $\log_2 n$, seçmeli sıralamanın $n^2$ mertebesindeki maliyeti ileride algoritma karmaşıklığında tekrar ele alınacaktır.

Dersin ikinci yarısında algoritma tasarım yöntemleri ve analiz ölçütleri tanıtıldı, ardından temel veri yapıları (dizi, bağlantılı liste, kuyruk, öncelikli kuyruk, yığın) anlatıldı. Yığının en önemli uygulaması olarak infix, prefix ve postfix gösterimleri, bu ifadelerin yığınla değerlendirilmesi ve gösterimler arası dönüşümler adım adım çözüldü. Prefix ve postfix gösterimlerin parantez ve öncelik kontrolü gerektirmediği, bu yüzden derleyiciler için uygun olduğu vurgulandı. Aynı dönüşümler ağaçlar konusunda ikili ağaçlarla tekrar ele alınacak, kuyruk uygulamaları çizgeler konusunda görülecek; bir sonraki konu algoritma analizidir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
