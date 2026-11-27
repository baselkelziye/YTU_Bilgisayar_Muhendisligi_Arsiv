# Ders 9 Genişletilmiş Notu: Bağlamdan Bağımsız Diller İçin Pompalama Önsavı, Gramerlerin Sadeleştirilmesi, Normal Biçimler ve Yığıtlı Otomatlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Düzenli Dillerden Bağlamdan Bağımsız Dillere: Yeni Bir Pompalama Önsavı
- 2. Kaç İlişki Var? Sezgisel Sınıflandırma
- 3. Önsavın İfadesi
- 4. Önsavın İspat Fikri: CNF ve Ayrıştırma Ağacı
- 5. Önsavın Kullanımı: İki Sayım Çifti ve İki Dizgi
- 6. Örnek: $\{0^i 1 0^i 1 0^i\}$ Bağlamdan Bağımsız Değildir
- 7. Örnek: $\{a^n b a^n\}$ ve Pompalanabilen Bir Dizgi
- 8. Gramerlerin Sadeleştirilmesi: Yerine Koyma Kuralı
- 9. $\varepsilon$-Üretimlerinin Kaldırılması
- 10. Birim Üretimlerin Kaldırılması
- 11. Yararsız Üretimlerin Kaldırılması
- 12. Sadeleştirme Sırası
- 13. Derste Çözülen Sadeleştirme Örnekleri
- 14. Chomsky Normal Biçimi
- 15. Greibach Normal Biçimi
- 16. Yığıtlı Otomatlar: Yığıt ve Geçiş Gösterimi
- 17. $\{a^n b^n\}$ İçin PDA ve Çalıştırma İzleri
- 18. $\{vv^R\}$ İçin PDA ve Belirlenimsizlik
- 19. Çok Sembollü Pop ve Push
- 20. $a$ Sayısı ile $b$ Sayısı Eşit Olan Dizgiler İçin PDA
- Örnek Sorular

## 1. Düzenli Dillerden Bağlamdan Bağımsız Dillere: Yeni Bir Pompalama Önsavı

Ders, bağlamdan bağımsız diller (context-free languages, CFL) için pompalama önsavıyla (pumping lemma) başlar. Anlatım büyük ölçüde İngilizcedir; bazı açıklamalar Türkçe tekrar edilir. Önceki derslerde bazı dillerin bağlamdan bağımsız olup olmadığı tartışılmıştı.

Hoca önce düzenli diller için pompalama önsavını hatırlattı. O önsavda dildeki yeterince uzun bir dizgi, dilin DFA'sında bir döngüye yol açar; bu döngü pompalanabilir, yani dizgideki bir parça istenildiği kadar tekrarlanabilir. Önsav, bir dilin düzenli **olmadığını** göstermek için kullanılıyordu. Bağlamdan bağımsız diller için kullanacağımız önsav bunun genişletilmiş bir sürümüdür: bu kez dizginin iki ayrı parçası birlikte pompalanır.

## 2. Kaç İlişki Var? Sezgisel Sınıflandırma

Hoca önsava geçmeden önce dilleri, sembol sayıları arasındaki ilişki sayısına göre sezgisel olarak sınıflandırdı.

- $L_1 = \{a^m b^n \mid m, n \ge 0\}$: $a$ sayısı ile $b$ sayısı arasında hiçbir ilişki yoktur. Bu dil düzenlidir; her düzenli dil aynı zamanda bağlamdan bağımsızdır.
- $L_2 = \{a^m b^m \mid m \ge 0\}$: $a$ sayısı $b$ sayısına eşit olmalıdır. Tek bir ilişki vardır; dil bağlamdan bağımsızdır.
- $\{a^m b^m c^m \mid m \ge 0\}$: $a$ ile $b$, $b$ ile $c$ ve $a$ ile $c$ arasında ilişki vardır. Birden fazla ilişki olduğu için dil bağlamdan bağımsız değildir.

Hoca bu sezgiyi şöyle özetledi: bağlamdan bağımsız dillerde pompalama önsavıyla yalnız bir ilişki olup olmadığına bakılır.

Ekranda, hocanın önceki sayfalara dönerken gösterdiği el yazısı örnekler de görünür (ekrandan, 00:10:00):

- $\{a^n b^m c^k \mid n > k,\ m > k\}$: bağlamdan bağımsız değil (üzeri çizili "CFL").
- $\{a^n b^n c^n \mid n \le 5\}$: bağlamdan bağımsız. Dil sonludur: $\{\varepsilon, abc, aabbcc, \ldots, aaaaabbbbbccccc\}$.
- $\{a^m b^n c^k \mid m, n \ge 0,\ k = \min(m, 5)\}$: bağlamdan bağımsız olarak işaretli.

<!-- BELİRSİZ: Bu üç örnek karede önceki sayfalarda görünüyor; altyazıda bu derste ayrıca anlatıldıkları duyulmuyor. -->

> **Ek bilgi (derste anlatılmadı):** "İlişki sayısı" bir ispat yöntemi değil, sezgidir. Örneğin $\{ww\}$'de görünürde tek bir eşleşme vardır ama dil bağlamdan bağımsız değildir; $\{a^n b^n c^n \mid n \le 5\}$'te üç eşitlik olduğu hâlde dil sonlu olduğu için düzenlidir. Kesin sonuç için gramer/PDA ya da pompalama önsavı gerekir.

## 3. Önsavın İfadesi

Slayttaki ifade şudur (ekrandan, 00:15:00):

Her bağlamdan bağımsız $L$ dili için bir $n$ tam sayısı vardır öyle ki, $L$'deki uzunluğu $n$'den büyük her $z$ dizgisi $z = uvwxy$ biçiminde yazılabilir ve:

1. $|vwx| < n$,
2. $|vx| > 0$,
3. her $i > 0$ için $uv^iwx^iy \in L$.

Hoca bunu bir şekille açıkladı (ekrandan, 00:30:00): $L$ bir kümedir, içinde dizgiler vardır. Bunlardan biri $z$'dir ve $|z| > n$ ise $z = uvwxy$ diye beş parçaya bölünebilir. $v$ ve $x$ parçaları aynı sayıda pompalanır ve elde edilen $uv^iwx^iy$ yine dilde olmalıdır. $i = 0$ alındığında $v$ ve $x$ silinir ve $uwy$ elde edilir. Pompalanan kısmın uzunluğu ($|vx|$) en az 1 olmalıdır.

Bir dil bu önsavı sağlamıyorsa bağlamdan bağımsız değildir. İspat çelişki (contradiction) yöntemiyle yapılır: dilin bağlamdan bağımsız olduğu varsayılır ve önsavın koşullarının sağlanamadığı gösterilir.

> **Ders sonrası not:** Önsavın standart biçimi şudur: $|z| \ge n$ olan her $z \in L$ için $|vwx| \le n$, $|vx| \ge 1$ ve **her $i \ge 0$** için $uv^iwx^iy \in L$. Slayttaki "$i > 0$" ifadesi $i = 0$ durumunu dışarıda bırakır; oysa hocanın da derste kullandığı $uv^0wx^0y = uwy$ adımı önsavın parçasıdır.

> **Ders sonrası not:** Hoca bir yerde "dil önsavı sağlamıyorsa bağlamdan bağımsız değildir, aksi hâlde bağlamdan bağımsızdır" dedi. İlk yarı doğrudur, ikinci yarı doğru değildir: önsavı sağlayan ama bağlamdan bağımsız olmayan diller vardır. Önsav yalnız "bağlamdan bağımsız değildir" sonucunu vermek için kullanılabilir.

## 4. Önsavın İspat Fikri: CNF ve Ayrıştırma Ağacı

İspat, Chomsky normal biçimindeki (Chomsky normal form, CNF) bir gramerle başlar. CNF bu derste daha sonra anlatıldı (Bölüm 14); burada bilmemiz gereken, CNF ayrıştırma ağacında her iç düğümün iki dalı olduğu ve son düğümün tek bir terminal ürettiğidir.

Slayttaki adımlar (ekrandan, 00:20:00):

- Gramerde $m$ değişken olsun.
- $n = 2^m$ seçilir.
- $|z| > n$ olsun.
- "Lemma 1": verimi (yield) $z$ olan bir ayrıştırma ağacında uzunluğu $m+2$ ya da daha fazla olan bir yol vardır.
- "Proof of Lemma 1": CNF gramerin ayrıştırma ağacındaki bütün yolların uzunluğu $m+1$'den küçükse en uzun verim $2^{m-1}$ uzunluğundadır.

Hoca bunu şöyle anlattı: $z$'yi ayrıştırmak için ağaçta en az $m+1$ değişken içeren bir yol bulunmalıdır. Gramerde yalnız $m$ değişken olduğu için bu yolda bir değişken tekrar eder. Tekrar eden değişkenin iki geçişi arasındaki ağaç parçası (slaytta sarı gösterilen kısım) pompalanan kısımdır ve $z = uvwxy$ bölünmesini verir.

- Sarı parça çıkarılırsa ağaç $uv^0wx^0y = uwy$ dizgisinin ağacı olur.
- Sarı parça iki kez yerleştirilirse $uv^2wx^2y$ dizgisinin ağacı elde edilir.
- Üç kez yerleştirilirse $uv^3wx^3y$ elde edilir.

Böylece her $i$ için $uv^iwx^iy$ dizgisinin bir ayrıştırma ağacı vardır, yani dizgi dildedir.

## 5. Önsavın Kullanımı: İki Sayım Çifti ve İki Dizgi

Slaytın ana fikri şudur (ekrandan, 00:25:00): bağlamdan bağımsız olmayan diller genelde iki sayım çiftini (two pairs of counts) ya da iki dizgiyi eşleştirmeye çalışır.

Hoca üç dili karşılaştırdı:

- $L_1 = \{ww^R \mid w \in \{0,1\}^*\}$: soldaki ile sağdaki parça arasında tek bir ilişki vardır, o da ters çevirmedir. Başa bir sembol eklenince sona da aynı sembol eklenir. Dil bağlamdan bağımsızdır.
- $L_2 = \{ww \mid w \in \{0,1\}^*\}$: slayta göre pompalama önsavıyla bağlamdan bağımsız olmadığı gösterilebilir.
- $L_3 = \{0^i 1 0^i \mid i > 1\}$: 1'in solundaki 0 sayısı sağındaki 0 sayısına eşittir. Tek bir sayım çifti eşleştirilir; dil bağlamdan bağımsızdır.

<!-- BELİRSİZ: Hocanın $L_2$ için verdiği gerekçe ("ilişki simetrik değil", "ba dilde değil") altyazıda karışık; kesin bir ispat verilmedi. -->

> **Ek bilgi (derste anlatılmadı):** $\{ww\}$'nin bağlamdan bağımsız olmadığı genelde $z = 0^n 1^n 0^n 1^n$ seçilerek gösterilir. $|vwx| \le n$ olduğundan $vwx$ en çok iki komşu bloğa değer; pompalama bu blokların yalnız bir kısmını değiştirir ve dizgi iki eş yarıya bölünemez hâle gelir.

## 6. Örnek: $\{0^i 1 0^i 1 0^i\}$ Bağlamdan Bağımsız Değildir

Bu dilde 1'lerin solundaki, ortasındaki ve sağındaki 0 sayılarının üçü de eşit olmalıdır. İlişki sayısı birden fazladır, bu yüzden dil bağlamdan bağımsız değildir. Hoca bunu pompalama önsavıyla da gösterdi.

Adımlar:

- Dilin bağlamdan bağımsız olduğu varsayılır ve $n$ pompalama sabiti alınır.
- $z = 0^n 1 0^n 1 0^n$ seçilir. $|z| = 3n + 2 > n$ olduğundan koşul sağlanır.
- $z = uvwxy$ yazılır; $|vx| > 0$ olmalıdır.
- $i = 0$ için $uv^0wx^0y = uwy$ dizgisine bakılır.

Hoca somut olarak $n = 3$ aldı (ekrandan, 00:35:00):

$$z = 000\,1\,000\,1\,000$$

Kareye göre ilk $000$ $u$, ilk $1$ $v$, ortadaki $000$ $w$, ikinci $1$ $x$ ve son $000$ $y$ olarak işaretlendi. Bu bölünmede $uwy = 000\,000\,000$ olur; dizgide hiç 1 kalmadığı için dile ait değildir. Hoca hangi bölünme denenirse denensin $uv^0wx^0y$'nin dilde olduğu bir bölünme bulunamadığını söyledi. Bu, "her $i$ için $uv^iwx^iy \in L$" koşuluyla çelişir; o hâlde dil bağlamdan bağımsız değildir.

Slaytta çözümün durumlarından biri de yazılıdır (ekrandan, 00:35:00): "Durum 1: $vx$ hiç 0 içermiyorsa en az biri 1'dir ve $uwy$ en çok bir tane 1 içerir; dildeki hiçbir dizgi böyle değildir."

> **Ders sonrası not:** Tek bir bölünmeyi denemek ispat için yetmez; önsav bölünmenin **var olduğunu** söyler, bu yüzden çelişki **bütün** olası bölünmeler için gösterilmelidir. Slayttaki durum ayrımı bunu yapar: (1) $vx$ bir 1 içeriyorsa $uwy$'de en çok bir 1 kalır; (2) $vx$ yalnız 0'lardan oluşuyorsa, $|vwx| \le n$ olduğu için $vwx$ üç 0 bloğunun hepsine birden değemez, bu yüzden $uwy$'de en az bir blok $n$ tane 0 olarak kalırken başka bir blok kısalır ve bloklar eşit olmaz.

## 7. Örnek: $\{a^n b a^n\}$ ve Pompalanabilen Bir Dizgi

Hoca ikinci örnek olarak $L = \{a^n b a^n \mid n \ge 0\}$ dilini aldı (ekrandan, 00:40:00). $n = 3$ için:

$$z = aaabaaa = uvwxy,\quad u = aa,\ v = a,\ w = b,\ x = a,\ y = aa$$

Hocanın bölünmeyi seçerken kullandığı fikir şudur: $w$ desen gereği $b$ olmalıdır, $v$ ve $x$ ise $b$'nin iki yanından birer $a$ almalıdır.

Kontroller:

- Kareye yazılan: $|uwy| = 2 + 1 + 2 = 5$.
- $|vx| = 2 > 0$.
- $i = 0$: $uv^0wx^0y = aabaa \in L$.
- $i = 1$: $uvwxy = aaabaaa \in L$.
- $i = 2$: $uv^2wx^2y = aaaabaaaa = a^4ba^4 \in L$.
- $i = 3$: $uv^3wx^3y = a^5ba^5 \in L$.
- Genel olarak: $uv^iwx^iy = a^{2}\,a^{i}\,b\,a^{i}\,a^{2} = a^{i+2} b a^{i+2} \in L$.

Hoca buradan, dil önsavın bütün koşullarını sağladığı için bağlamdan bağımsızdır sonucuna vardı ve bunu önceki örnekle karşılaştırdı.

> **Ders sonrası not:** Hoca kareye $|uwy|$ yazdı; önsavın ilk koşulu $|vwx|$ ile ilgilidir. Bu bölünmede $|vwx| = |aba| = 3$'tür. Ayrıca bir dizginin pompalanabildiğini göstermek dilin bağlamdan bağımsız olduğunu **ispatlamaz** (Bölüm 3'teki not). $\{a^n b a^n\}$'nin bağlamdan bağımsız olduğu bir gramerle gösterilir: $S \to aSa \mid b$.

## 8. Gramerlerin Sadeleştirilmesi: Yerine Koyma Kuralı

İkinci konu bağlamdan bağımsız gramerlerin sadeleştirilmesidir (simplification of context-free grammars). Amaç, aynı dili üreten daha basit (daha az üretimli) bir gramer elde etmektir.

Slayttaki örnek (ekrandan, 00:45:00):

| Özgün gramer | $B \to b$ yerine konduktan sonra |
|---|---|
| $S \to aB$ | $S \to aB \mid ab$ |
| $A \to aaA$ | $A \to aaA$ |
| $A \to abBc$ | $A \to abBc \mid abbc$ |
| $B \to aA$ | $B \to aA$ |
| $B \to b$ | (silindi) |

$B$ değişkeninin iki üretimi vardır: $B \to aA$ ve $B \to b$. $B \to b$ üretimini kaldırmak istiyoruz. Bunun için $B$'nin geçtiği her sağ taraf için iki olasılık düşünülür: $B$ yerinde kalır (öteki üretimle türetilecektir) ya da $B$ yerine $b$ yazılır. Böylece $S \to aB$, $S \to aB \mid ab$ olur; $A \to abBc$, $A \to abBc \mid abbc$ olur. İçinde $B$ geçmeyen üretimler değişmez. Yeni gramer eşdeğerdir ve terminal üretimler dışında üretim sayısı azalmıştır.

Genel kural: $A \to x_1 B x_2$ ve $B \to y_1$ varsa, $B \to y_1$ kaldırılırken $A \to x_1 B x_2 \mid x_1 y_1 x_2$ yazılır.

## 9. $\varepsilon$-Üretimlerinin Kaldırılması

$X \to \varepsilon$ biçimindeki üretimlere $\varepsilon$-üretimi (epsilon production) denir. Türetme sırasında boş dizgiye dönüşebilen değişkenlere boşa giden değişken (nullable variable) denir.

Slayttaki örnek (ekrandan, 00:50:00):

| Özgün gramer | $M \to \varepsilon$ yerine konduktan sonra |
|---|---|
| $S \to aMb$ | $S \to aMb \mid ab$ |
| $M \to aMb$ | $M \to aMb \mid ab$ |
| $M \to \varepsilon$ | (silindi) |

$M$ geçen her sağ tarafa $M$'nin $\varepsilon$ yapıldığı bir kopya eklenir. Slaytın alt kısmındaki cümleye göre bütün $\varepsilon$-üretimleri kaldırıldıktan sonra, başlangıç değişkeni dışında bütün boşa giden değişkenler ortadan kalkar.

## 10. Birim Üretimlerin Kaldırılması

$A \to B$ gibi, bir değişkenin doğrudan başka bir değişkene dönüştüğü, önünde ve arkasında hiçbir sembol olmayan üretimlere birim üretim (unit production) denir.

- $A \to B$ kaldırılırken $A$'nın geçtiği üretimlere $B$'li kopyalar eklenir (ya da $B$'nin sağ tarafları $A$'ya aktarılır).
- $B \to B$ gibi bir değişkenin kendisine dönen birim üretimi doğrudan silinir; dil değişmez.

Slayttaki son gramer (ekrandan, 00:55:00):

- Önce: $S \to aA \mid aB \mid aA$ (son $aA$ karede üstü çizili), $A \to a$, $B \to bb$.
- Sonra: $S \to aA \mid aB$, $A \to a$, $B \to bb$.

Son adımda aynı sağ taraf ($aA$) iki kez göründüğü için biri silinir.

<!-- BELİRSİZ: Birim üretim örneğinin başlangıç grameri karede görünmüyor; altyazıdan yalnız $A \to B$ ve $B \to B$ üretimlerinin sırayla kaldırıldığı anlaşılıyor. -->

## 11. Yararsız Üretimlerin Kaldırılması

Türetme sonunda elde edilen dizgi yalnız terminallerden oluşur. Bir değişken, terminal bir dizgi $w$ elde etmek için bir türetmede kullanılabiliyorsa yararlıdır (useful); aksi hâlde yararsızdır (useless).

Hoca iki tür yararsızlığı anlattı:

- **Kilitlenme:** $A \to aA$ gibi yalnız kendine dönen bir değişken hiçbir zaman terminal dizgiye ulaşmaz; bu üretim yararsızdır. Bir değişken ancak yararsız değişkenlere gidiyorsa (örneğin $B \to C$ ama $C$'nin işe yarar üretimi yoksa) o da yararsız olur.
- **Ulaşılamama:** başlangıç değişkeninden hiçbir türetmeyle ulaşılamayan değişken yararsızdır.

Slayttaki örnek gramer (ekrandan, 01:15:00):

$$S \to aS \mid A \mid C,\quad A \to a,\quad B \to aa,\quad C \to aCb$$

Slayttaki ilk adım: yalnız terminal ya da $\varepsilon$ üretebilen değişkenler bulunur. $C \to aCb$ hiçbir zaman sonlanmaz, bu yüzden $C$ ve $S \to C$ silinir. Sonra başlangıçtan ulaşılamayan değişkenler aranır: $S$'den $B$'ye hiçbir yol yoktur, bu yüzden $B \to aa$ da silinir.

Hoca anlatım sırasında $C$'ye $S$'ye giden bir seçenek ekleyerek ($C \to aCb \mid S$) $C$'nin artık kilitlenmediğini ve o durumda üretimin kaldırılamayacağını da gösterdi.

<!-- BELİRSİZ: Bu varyasyonun ayrıntıları ve hocanın ardından yazdığı ara gramerler altyazıda karışık; karede yalnız eklenen "| S" görünüyor. -->

## 12. Sadeleştirme Sırası

Slaytta ve hocanın özetinde sıra şöyledir:

1. Bütün boşa giden değişkenleri ($\varepsilon$-üretimlerini) kaldır.
2. Bütün birim üretimleri kaldır.
3. Bütün yararsız değişkenleri kaldır.

Slayttaki cümleye göre bu sıra, istenmeyen değişkenlerin ve üretimlerin kaldırılmasını garanti eder (ekrandan, 01:20:00).

> **Ek bilgi (derste anlatılmadı):** Sıra önemlidir, çünkü $\varepsilon$-üretimlerini kaldırmak yeni birim üretimler doğurabilir (örneğin $A \to BC$ ve $C \to \varepsilon$ ise $A \to B$ oluşur), birim üretimleri kaldırmak da bazı değişkenleri ulaşılamaz hâle getirebilir.

## 13. Derste Çözülen Sadeleştirme Örnekleri

Hoca slaytlardaki örneklerden sonra, kendi yazdığı ve öğrencilerle birlikte oluşturduğu gramerler üzerinde örnekler çözdü. Bu bölümün büyük kısmı Türkçe anlatıldı.

> **Hocanın vurgusu:** Bir üretimi yok ederken önce var olan üretimleri aynen yazın, sonra yok ettiğiniz üretimden kaynaklanan değişiklikleri ekleyin.

### 13.1 Hiç Dizgi Üretmeyen Gramer

Gramer (ekrandan, 01:25:00):

$$S \to aSS \mid AB \mid B,\quad A \to aA \mid S$$

- $B$ değişkenine ulaşılıyor ama $B$'nin hiçbir üretimi yok. Bu yüzden $AB$ ve $B$ seçenekleri silinir.
- Geriye $S \to aSS$ ve $A \to aA \mid S$ kalır. $A$'ya artık $S$'den ulaşılamaz.
- $S \to aSS$ her adımda yeniden $S$ üretir; türetme hiçbir zaman sonlanmaz, her yerde kilitlenme vardır.

Hocanın vardığı sonuç: "Bu bir gramer değil." Hoca bunu çok ilginç bir örnek olarak niteledi.

> **Ders sonrası not:** Biçimsel olarak bu yine bir gramerdir; ama hiçbir terminal dizgi üretmez, yani $L(G) = \emptyset$'dir. Python ile uzunluğu 8'e kadar bütün türetmeler denenmiş ve hiçbir dizgi çıkmamıştır.

### 13.2 Kendine Dönen $B \to BB$

Gramer (ekrandan, 01:30:00 ve 01:40:00):

$$S \to aS \mid aB,\quad S \to b,\quad B \to BB \mid a,\quad C \to B$$

<!-- BELİRSİZ: Karede ikinci satır "S → b" olarak okunuyor ve önünde kırmızı bir çizgi var; satırın anlamı altyazıdan net çıkmıyor. -->

- $C$ değişkeni hiçbir yerde kullanılmıyor (başlangıçtan ulaşılamıyor); $C \to B$ silinir.
- Ardından tek terminalli üretim yerine konarak $S \to aS \mid ab \mid aB$, $B \to BB \mid a$ yazıldı.
- Hoca sonra $B \to BB$ üretimini de kaldırmayı denedi ve $S \to aS \mid ab \mid aB \mid aBB$, $B \to a$ yazdı; ardından $B$'yi $a$ ile değiştirerek $S \to aS \mid ab \mid aa \mid \ldots$ biçimine gitti.

Burada bir öğrenci şunu sordu:

**Soru:** $B$'den $BB$'ye giden üretimi kaldırdık; ama o $BB$'lerin de kendi içinde tekrar $BB$ üretme ihtimali yok mu? **Cevap:** Hoca önce başka $B$ olmadığı için doğrudan atladığını, normalde bu adımların da gösterilebileceğini söyledi. Ardından öğrencinin dediği gibi $B$'nin her zaman $B$'den $BB$'ye dönebildiğini, bunun da $B, BB, BBB, \ldots$ diye uzayıp gittiğini kabul etti: "Doğru diyorsun."

Bu düzeltmeden sonra çözüm şöyle bırakıldı: $C$ silindi, tek terminalli üretim yerine kondu, $B \to BB$ ise kaldırılamaz. Sonuç:

$$S \to aS \mid ab \mid aB,\quad B \to BB \mid a$$

Hoca, $B \to BB$'yi yine de yok etmeye kalkışırsak gramerin daha karmaşık hâle geldiğini, üretimlerin arttığını gösterdi ve en basit hâlin bu olduğunu söyledi.

> **Ders sonrası not:** Karedeki ikinci satır gerçekten $S \to b$ ise, bu üretim $S \to aS$'ye yerine konarak $ab$ seçeneği eklendikten sonra silinemez: başlangıç değişkeninin kendisi de doğrudan $b$ üretiyordu ve $b$ dizgisi dilden düşer. Doğru sonuç $S \to aS \mid ab \mid aB \mid b$, $B \to BB \mid a$'dır. Bu iki gramerin dilleri Python ile karşılaştırılmış, ilk gramerde $b$ bulunduğu, ikincisinde bulunmadığı görülmüştür.

### 13.3 Öğrencilerin Önerdiği Gramer: $S \to 0S0 \mid 1A1$

Hoca grameri öğrencilere söyletti. Bir kısmını kendisi yazdı, kalanını öğrenciler önerdi (ekrandan, 01:35:00):

$$S \to 0S0 \mid 1A1,\quad A \to 0A \mid b$$

Öğrencinin önerdiği büyük $B$, karışıklık olmasın diye küçük $b$ terminali olarak yazıldı. Hoca grameri önce tek tek üretimlere ayırdı:

$$S \to 0S0,\quad S \to 1A1,\quad A \to 0A,\quad A \to b$$

Sonra $A \to b$ üretimini yok etti. $S \to 0S0$'da $A$ yoktur, aynen kalır. $S \to 1A1$'de $A$ yerine $b$ gelir: $S \to 1A1 \mid 1b1$. $A \to 0A$'da da $A$ yerine $b$ gelir: $A \to 0A \mid 0b$.

Ardından hoca $A \to 0A$ üretiminin kendine döndüğünü gösterdi: $A$'yı yok etmeye çalışınca aynı üretim yine geri gelir. $A$ kendinden kendine gider, sonunda terminale ulaşır; bu üretimler yararlıdır ve yok edilemez. Hoca bu grameri "indirgenemez" (unreducible) olarak niteledi: daha fazla sadeleştirilemez, çok kompakt bir gramerdir.

**Soru:** O zaman bir önceki gramer de indirgenemez olmuyor mu? ($B$'den $B$'ye gidiyordu.) **Cevap:** Hoca önce hayır dedi, sonra öğrencinin haklı olduğunu kabul etti ve önceki örneğin çözümünü Bölüm 13.2'deki biçimde düzeltti.

> **Ders sonrası not:** Bu gramerde $\varepsilon$-üretimi, birim üretim ya da yararsız değişken yoktur; bu yüzden sadeleştirme algoritması grameri olduğu gibi bırakır. $A \to b$'yi yerine koymak zorunlu bir adım değildir ve üretim sayısını artırır. İki gramerin aynı dili ürettiği Python ile doğrulanmıştır.

### 13.4 $S \to Ab \mid aaB$

Hoca bu grameri, sınavda sorulmuş bir gramer olarak hatırladığını söyleyerek yazdı (ekrandan, 01:45:00):

$$S \to Ab \mid aaB,\quad A \to a \mid Aa,\quad B \to b$$

- $B \to b$ yok edilir: $S \to Ab \mid aaB$ aynen yazılır, $aaB$ yerine $aab$ gelir. $B$'ye artık ulaşılamaz.
- Sonuç: $S \to Ab \mid aab$, $A \to a \mid Aa$.
- $A \to Aa$ kendine dönen yararlı bir üretimdir, kaldırılamaz.

> **Ek bilgi (derste anlatılmadı):** $A$, $a^+$ dilini üretir; bu yüzden $S \to Ab$ zaten $aab$'yi de üretir ($A \Rightarrow Aa \Rightarrow aa$). Yani $S \to Ab$, $A \to a \mid Aa$ da aynı dili ($a^+b$) üretir. Bu tür fazlalıkları sadeleştirme algoritması kendiliğinden bulmaz. Eşdeğerlik Python ile doğrulanmıştır.

Hoca ardından benzer bir varyasyon yazdı: $A$ değişkeninin hiç üretimi yoksa $S \to Ab$ seçeneği doğrudan "ölür" ve silinir; kalan gramer tek bir dizgiye götürür ve hocanın deyişiyle bu düzenli bir dilin grameridir.

<!-- BELİRSİZ: Varyasyonun tam üretimleri altyazıda karışık ve karede görünmüyor. -->

### 13.5 Belirsiz Gramer Sorusundaki Gramer

Hoca bu grameri sınavdaki belirsiz (ambiguous) gramer sorusundan aldığını söyledi (ekrandan, 01:50:00):

$$S \to 0A \mid 1B,\quad A \to 0AA \mid 1S \mid 1,\quad B \to 1BB \mid 0S \mid 0$$

<!-- BELİRSİZ: $B$ satırı karede okunuyor; $S$ ve $A$ satırları karede görünmüyor, altyazıdan kuruldu. -->

Hocanın değerlendirmesi: $A$'dan $S$'ye ve $S$'den $A$'ya geçişler var. Örneğin $1S$'deki $S$'yi ya da $0S$'yi yok etmeye kalksak, $S$'nin seçeneklerini bu yerlere tekrar yerleştirmemiz gerekir; gramer daha karmaşık olur. Bu yüzden bu gramer en basit hâlindedir, daha fazla indirgenmez.

### 13.6 $\varepsilon$-Üretimli Gramer

Gramer (ekrandan, 01:50:00):

$$S \to X \mid Xb \mid Xbb,\quad X \to Xa \mid cX \mid cXa \mid \varepsilon$$

$X \to \varepsilon$ kaldırılır. Her üretim önce aynen yazılır, sonra $X$'in yerine $\varepsilon$ konmuş kopya eklenir:

- $S \to X$ ve $S \to \varepsilon$.
- $S \to Xb$ ve $S \to b$.
- $S \to Xbb$ ve $S \to bb$.
- $X \to Xa$ ve $X \to a$.
- $X \to cX$ ve $X \to c$.
- $X \to cXa$ ve $X \to ca$.

Böylece $\varepsilon$ yalnız başlangıç değişkenine taşınmış olur. Düzenlenmiş gramer (ekrandan, 01:55:00):

$$S \to X \mid Xb \mid Xbb \mid bb \mid b \mid \varepsilon,\quad X \to cXa \mid cX \mid Xa \mid ca \mid c \mid a$$

Hoca bu grameri daha fazla sadeleştiremeyeceğimizi söyledi: başlangıç değişkenindeki $\varepsilon$ hiçbir zaman yok edilemez (dil boş dizgiyi içerir), $X$'leri kaldırmaya çalışmak ise grameri daha karmaşık yapar.

> **Ders sonrası not:** Sadeleştirme sırasının 2. adımına göre $S \to X$ birim üretimi de kaldırılmalıdır: $X$'in sağ tarafları $S$'ye eklenir ve $S \to Xb \mid Xbb \mid bb \mid b \mid \varepsilon \mid cXa \mid cX \mid Xa \mid ca \mid c \mid a$ elde edilir. Python ile bu gramerin, derste bırakılan gramerle aynı dili ürettiği (uzunluk 7'ye kadar) doğrulanmıştır.

## 14. Chomsky Normal Biçimi

Chomsky normal biçiminde (Chomsky normal form, CNF) her üretim şu iki biçimden birindedir:

$$A \to BC \qquad \text{ya da} \qquad A \to a$$

Yani bir değişken ya iki değişkenin birleştirmesine ya da tek bir terminale dönüşür.

Hoca slayttaki örnekleri değerlendirdi: bütün üretimleri iki değişkene ya da tek terminale giden bir gramer CNF'dir. Bir değişkenin üç değişkene gittiği ya da iki terminale ($A \to aa$ gibi) gittiği bir gramer CNF değildir, ama CNF'ye dönüştürülebilir.

<!-- BELİRSİZ: Bu ilk iki slayt örneğinin üretimleri karede görünmüyor. -->

### 14.1 CNF'ye Dönüştürme Örneği

Dönüştürme iki adımda yapılır:

1. Her terminal için yeni bir değişken eklenir: $T_a \to a$, $T_b \to b$, $T_c \to c$. Sağ taraflardaki terminaller bu değişkenlerle değiştirilir.
2. İkiden uzun sağ taraflar, yeni değişkenler eklenerek ikili parçalara bölünür.

Slayttaki ara ve son gramer (ekrandan, 02:10:00):

| Ara gramer | CNF |
|---|---|
| $S \to AV_1$ | $S \to AV_1$ |
| $V_1 \to BT_a$ | $V_1 \to BT_a$ |
| $A \to T_aT_aT_b$ | $A \to T_aV_2$ |
| | $V_2 \to T_aT_b$ |
| $B \to AT_c$ | $B \to AT_c$ |
| $T_a \to a$, $T_b \to b$, $T_c \to c$ | $T_a \to a$, $T_b \to b$, $T_c \to c$ |

İlk adımda $S$'nin üç sembollü sağ tarafı ($A$, $B$, $T_a$) için $V_1$ eklendi: $S \to AV_1$, $V_1 \to BT_a$. Geriye yalnız $A \to T_aT_aT_b$ kaldı; aynı yöntemle $V_2$ eklenerek $A \to T_aV_2$, $V_2 \to T_aT_b$ yazıldı.

Bu sonuç, $S \to ABa$, $A \to aab$, $B \to Ac$ gramerinin CNF karşılığıdır (ara adım eklendi: özgün gramer karede görünmüyor, sonuç gramerden geri çıkarıldı). İki gramerin aynı dili ($\{aabaabca\}$ tek dizgisini) ürettiği Python ile doğrulanmıştır.

### 14.2 Genel Yöntem ve CNF'nin Yararı

$\varepsilon$ üretmeyen ve CNF'de olmayan her bağlamdan bağımsız gramerden CNF'de eşdeğer bir gramer elde edilebilir. Bunun için önce boşa giden değişkenler, birim üretimler ve yararsız değişkenler kaldırılır; sonra yukarıdaki iki adım uygulanır. $A \to T_a$ gibi zaten uygun olan üretimler değiştirilmez.

$A \to C_1 C_2 \cdots C_n$ biçiminde uzunluğu $n$ olan bir sağ taraf için $n - 2$ yeni değişken gerekir:

$$A \to C_1 V_1,\quad V_1 \to C_2 V_2,\quad \ldots,\quad V_{n-2} \to C_{n-1} C_n$$

Hocaya göre CNF'ye neden ihtiyaç duyulur: CNF yazılımda gerçeklemeyi kolaylaştırır. Herhangi bir gramer CNF'ye çevrilip araçlarla kolayca yazılıma dönüştürülebilir. CNF ayrıştırma ve teorem ispatı için kullanışlıdır ve her bağlamdan bağımsız gramerin CNF'si kolayca bulunabilir.

## 15. Greibach Normal Biçimi

Greibach normal biçiminde (Greibach normal form, GNF) her üretim bir terminalle başlar, ardından sıfır ya da daha fazla değişken gelir:

$$A \to a V_1 V_2 \cdots V_k \qquad (k \ge 0)$$

Slayttaki örnekler (ekrandan, 02:15:00):

- $S \to cAB$, $A \to aA \mid bB \mid b$, $B \to b$: GNF'dir.
- $S \to abSb$, $S \to aa$: GNF değildir; sağ taraflar birden fazla terminal içerir.

Hoca ikinci grameri GNF'ye kendisi çevirdi. Terminaller için yeni değişkenler eklenir ve yalnız ilk terminal yerinde bırakılır:

$$S \to aBSB,\quad S \to aA,\quad A \to a,\quad B \to b$$

Python ile iki gramerin aynı dili ürettiği doğrulanmıştır.

GNF de dizgileri ayrıştırmak için çok kullanışlıdır. Ancak hocaya göre bazı gramerlerin GNF'sini bulmak kolay değildir; örneğin $\varepsilon$ varsa mümkün olmayabilir.

## 16. Yığıtlı Otomatlar: Yığıt ve Geçiş Gösterimi

Bağlamdan bağımsız gramerler bir makine olarak da gerçeklenebilir. Bu makineye yığıtlı otomat (pushdown automaton, PDA) denir. PDA'lar bağlamdan bağımsız dilleri tanır; düzenli diller de bağlamdan bağımsız olduğu için PDA ile tanınabilir.

### 16.1 Yığıt

PDA'nın sonlu otomattan farkı bir yığıta (stack) sahip olmasıdır. Başta yığıtın boş olduğu ve yığıtın tepesinde $\$$ sembolü bulunduğu varsayılır (bazen $\$$ yerine 0 da kullanılır).

> **Hocanın vurgusu:** Yığıt $\$$ ile başlar; buna çok dikkat edin.

### 16.2 Geçiş Gösterimi

Bir geçiş $q_1 \xrightarrow{a,\ b \to c} q_2$ biçiminde yazılır:

- $a$: girdi sembolü,
- $b$: yığıttan çekilen (pop) sembol,
- $c$: yığıta itilen (push) sembol.

Girdi sembolü $a$ ve yığıtın tepesi $b$ ise geçiş geçerlidir; $b$ çekilir, $c$ itilir ve makine $q_2$'ye geçer. Örneğin yığıt (tepeden aşağı) $b\,h\,e$ ise geçişten sonra $c\,h\,e$ olur.

Özel durumlar:

- $a, \varepsilon \to c$: yığıttan hiçbir şey çekilmez, yalnız $c$ itilir. Yığıt $b\,h\,e$ ise $c\,b\,h\,e$ olur.
- $a, b \to \varepsilon$: $b$ çekilir, hiçbir şey itilmez.
- $a, \varepsilon \to \varepsilon$: yığıt değişmez; yalnız girdi okunur.
- Girdi $a$ ama yığıtın tepesinde $b$ yoksa $a, b \to c$ geçişi geçersizdir; başka geçiş de yoksa otomat durur ve girdi ret edilir.
- $\varepsilon, b \to c$: girdi okunmadan durum değiştirilir; buna $\varepsilon$ geçişi denir.

Hoca aynı durumdan aynı girdi ve aynı yığıt koşuluyla iki farklı duruma ($q_2$ ve $q_3$) giden geçişler gösterdi. Bu nedenle PDA'lar belirlenimsizdir (non-deterministic).

## 17. $\{a^n b^n\}$ İçin PDA ve Çalıştırma İzleri

Slayttaki PDA (ekrandan, 02:25:00), $L(M) = \{a^n b^n : n \ge 0\}$:

| Geçiş | Girdi, pop $\to$ push |
|---|---|
| $q_0 \to q_1$ | $\varepsilon, \varepsilon \to \varepsilon$ |
| $q_1 \to q_1$ (döngü) | $a, \varepsilon \to a$ |
| $q_1 \to q_2$ | $b, a \to \varepsilon$ |
| $q_2 \to q_2$ (döngü) | $b, a \to \varepsilon$ |
| $q_2 \to q_3$ | $\varepsilon, \$ \to \$$ |

Kabul durumları $q_0$ ve $q_3$'tür. $n = 0$ için $\varepsilon \in L(M)$ olduğu için başlangıç durumu da kabul durumudur.

Temel fikir: her $a$ için yığıta bir $a$ itilir; her $b$ için yığıttan bir $a$ çekilir. Girdi bittiğinde yığıtta yalnız $\$$ kalmışsa (yani $\varepsilon, \$ \to \$$ geçişi yapılabiliyorsa) $a$ sayısının $b$ sayısına eşit olduğundan emin oluruz. $\$$ çekilip yeniden itildiği için yığıt değişmez; bu geçiş "yığıt boş mu?" sınamasıdır. Hoca yığıta $a$ yerine başka bir sembol (örneğin $X$) itmenin de aynı işi göreceğini söyledi.

### 17.1 $aaabbb$ Girdisi

| Zaman | Okunan | Geçiş | Durum | Yığıt (tepeden) |
|---|---|---|---|---|
| 0 | — | başlangıç | $q_0$ | $\$$ |
| 1 | — | $\varepsilon,\varepsilon\to\varepsilon$ | $q_1$ | $\$$ |
| 2 | $a$ | $a,\varepsilon\to a$ | $q_1$ | $a\,\$$ |
| 3 | $a$ | $a,\varepsilon\to a$ | $q_1$ | $aa\,\$$ |
| 4 | $a$ | $a,\varepsilon\to a$ | $q_1$ | $aaa\,\$$ |
| 5 | $b$ | $b,a\to\varepsilon$ | $q_2$ | $aa\,\$$ |
| 6 | $b$ | $b,a\to\varepsilon$ | $q_2$ | $a\,\$$ |
| 7 | $b$ | $b,a\to\varepsilon$ | $q_2$ | $\$$ |
| 8 | — | $\varepsilon,\$\to\$$ | $q_3$ | $\$$ |

Girdi tükendi ve kabul durumu $q_3$'e ulaşıldı; $aaabbb$ kabul edilir.

<!-- BELİRSİZ: Slayttaki zaman numaraları altyazıda tam takip edilemiyor; tablo geçişlerden kuruldu (ara adım eklendi). -->

### 17.2 $aab$ Girdisi

İki $a$ okunduktan sonra yığıtta $aa\,\$$ vardır. $b$ okununca bir $a$ çekilir ve $q_2$'ye geçilir; yığıtta $a\,\$$ kalır. Girdi biter ama yığıtın tepesinde $\$$ değil $a$ vardır; $\varepsilon, \$ \to \$$ geçişi geçerli değildir. Başka geçerli geçiş de yoktur. $aab$ için kabul eden bir hesaplama bulunmadığından girdi ret edilir. Bu sonuç Python ile yazılan bir PDA benzetimiyle doğrulanmıştır.

## 18. $\{vv^R\}$ İçin PDA ve Belirlenimsizlik

Slayttaki dil $L(M) = \{vv^R : v \in \{a,b\}^*\}$'dir: bir dizgi, kendi tersiyle birleştirilir. Hocanın tahtaya yazdığı üyelik örnekleri (ekrandan, 02:35:00):

- $aabbab \notin L$, $ab \notin L$, $ba \notin L$,
- $aa \in L$, $abba \in L$, $aaba\,abaa \in L$.

PDA (ekrandan, 02:35:00):

| Geçiş | Girdi, pop $\to$ push |
|---|---|
| $q_0 \to q_0$ (döngü) | $a, \varepsilon \to a$ ve $b, \varepsilon \to b$ |
| $q_0 \to q_1$ | $\varepsilon, \varepsilon \to \varepsilon$ |
| $q_1 \to q_1$ (döngü) | $a, a \to \varepsilon$ ve $b, b \to \varepsilon$ |
| $q_1 \to q_2$ | $\varepsilon, \$ \to \$$ |

$q_2$ kabul durumudur. Hoca slaytta da $a$ ve $b$ yerine $X$ ve $Y$ yazarak yığıta itilen sembollerin girdiden farklı olabileceğini gösterdi.

Temel fikir: $v$'nin sembolleri sırayla yığıta itilir; yığıttan çekilirken ters sırada çıkarlar ve $v^R$ ile eşleştirilir. Yığıt boşalmışsa kabul durumuna geçilir. Yığıtın doğal çalışması ters çevirme işlemini gerçeklemeye yardım eder.

> **Ders sonrası not:** Hoca yığıtı bir yerde "first in, last out", ardından "last in, last out" diye nitelendirdi. Doğrusu yığıtın son giren ilk çıkar (last in, first out, LIFO) olmasıdır; "first in, last out" ifadesi bununla aynı anlamdadır, "last in, last out" ise yanlıştır.

### 18.1 Ortayı Nasıl Buluyor?

**Soru:** Bu PDA dizginin ortasını nasıl buluyor? **Cevap:** Hoca önce yığıtın sırasını anlattı: önce $X$, sonra $Y$ konursa önce $Y$, sonra $X$ okunur; sonunda yığıtta hiçbir şey kalmazsa iki kısım birbirine eşit olmuş olur.

**Soru:** $abba$ için ilk başta $a$, sonra $b$ konuyor; üçüncü harfe gelince tekrar $b$ koymaz mı? **Cevap:** Hoca bunu NFA'daki paralel çalışmayla açıkladı. NFA'da makine aynı anda birden fazla durumda bulunabiliyordu ve kendini kopyalıyordu. Burada da her adımda makine hem $q_0$'da kalabilir hem de $\varepsilon, \varepsilon \to \varepsilon$ geçişiyle $q_1$'e geçebilir; durumla birlikte yığıt da kopyalanır. Ortaya varılana kadar $q_1$'e geçen kopyalar ölür, ortaya varıldığında ise $q_1$'deki kopya yaşamaya başlar ve kabul durumuna ulaşır. Bu $\varepsilon$ geçişi orta noktayı "tahmin eder" (guess the middle).

### 18.2 $abba$ Üzerinde Hesaplamalar

Kabul eden hesaplama:

| Adım | Okunan | Geçiş | Durum | Yığıt (tepeden) |
|---|---|---|---|---|
| 1 | $a$ | $a,\varepsilon\to a$ | $q_0$ | $a\,\$$ |
| 2 | $b$ | $b,\varepsilon\to b$ | $q_0$ | $ba\,\$$ |
| 3 | — | $\varepsilon,\varepsilon\to\varepsilon$ (orta tahmini) | $q_1$ | $ba\,\$$ |
| 4 | $b$ | $b,b\to\varepsilon$ | $q_1$ | $a\,\$$ |
| 5 | $a$ | $a,a\to\varepsilon$ | $q_1$ | $\$$ |
| 6 | — | $\varepsilon,\$\to\$$ | $q_2$ | $\$$ |

Girdi tükenmiş ve yığıt boşalmıştır; $abba$ kabul edilir.

Hoca aynı dizgi için ortayı yanlış tahmin eden hesaplamaları da gösterdi. Örneğin orta çok erken tahmin edilirse $q_1$'de okunan $b$ için yığıtın tepesinde $b$ yoktur ve hesaplama orada durur. Bir başka hesaplamada girdi bittiğinde kabul durumuna ulaşılamaz. Dizgi, kabul eden en az bir hesaplama varsa kabul edilir; yanlış tahminlerin ölmesi sonucu değiştirmez.

<!-- BELİRSİZ: Yanlış tahminli hesaplamaların zaman adımları altyazıda büyük ölçüde okunamıyor. -->

Python benzetimi slayttaki altı üyelik örneğinin hepsinde hocanın işaretlediği sonucu vermiştir.

## 19. Çok Sembollü Pop ve Push

Bir geçişte birden fazla sembol çekilip itilebilir (ekrandan, 02:45:00):

$$q_1 \xrightarrow{a,\ eb \to cdf} q_2$$

Başta yığıtın tepesinde $e$, altında $b$ vardır. Girdi $a$ için önce $e$, sonra $b$ çekilir; sonra önce $f$, ardından $d$, en son $c$ itilir. Böylece yığıtın tepesinde $c$ kalır.

> **Hocanın vurgusu:** Bu sıraya çok dikkat edin: önce pop, sonra pop; önce push, sonra push, sonra push.

Slaytta bu geçiş, ara durumlarla tek sembollü geçişlere açılmış eşdeğer bir diziyle gösterilir: pop kısmı ($e$ ve $b$ çekilir), aradaki $\varepsilon, \varepsilon \to \varepsilon$ geçişi ve push kısmı ($f$, $d$, $c$ itilir). Hoca slayttaki geçişlere bakarken ilk geçişten sonrakilerde girdinin $\varepsilon$ olması gerektiğini söyledi ve doğrusunu şöyle özetledi: girdi $a$ için $e$ çekilir, $b$ çekilir, $f$ itilir, $d$ itilir, $c$ itilir.

> **Ders sonrası not:** Slayttaki açılımda pop ve push geçişlerinin hepsinin girdisi $a$ olarak görünüyor. Girdi $a$ yalnız bir kez okunmalıdır; doğru açılım $a, e \to \varepsilon$; $\varepsilon, b \to \varepsilon$; $\varepsilon, \varepsilon \to f$; $\varepsilon, \varepsilon \to d$; $\varepsilon, \varepsilon \to c$ biçimindedir. Hocanın derste yaptığı düzeltme de bu yöndedir.

## 20. $a$ Sayısı ile $b$ Sayısı Eşit Olan Dizgiler İçin PDA

Dil, içindeki $a$ sayısı $b$ sayısına eşit olan dizgilerden oluşur; $a$ ve $b$'lerin sırası önemli değildir, yalnız sayılırlar. Hocanın verdiği örnekler: $aa$ dilde değildir, $ab$ dildedir, $abb$ dilde değildir, $abab$ dildedir.

PDA (ekrandan, 02:50:00): $q_1$ başlangıç durumudur ve şu döngüleri vardır:

| Girdi $a$ | Girdi $b$ |
|---|---|
| $a, \$ \to 0\$$ | $b, \$ \to 1\$$ |
| $a, 0 \to 00$ | $b, 1 \to 11$ |
| $a, 1 \to \varepsilon$ | $b, 0 \to \varepsilon$ |

Ayrıca $q_1 \xrightarrow{\varepsilon,\ \$ \to \$} q_2$ geçişi vardır; $q_2$ kabul durumudur.

Hocanın Türkçe açıklaması: yığıt boşken bir $a$ gelirse 0 eklenir. Bir $a$ daha gelirse 0 çekilir, iki 0 eklenir; yığıttaki 0 sayısı bir artar. Yani her fazla $a$ için 0'ların sayısı artar; benzer şekilde her fazla $b$ için 1'lerin sayısı artar. Yığıtta 0 varsa daha önce fazladan $a$ gelmiş demektir; o sırada bir $b$ gelirse bir 0 silinir, çünkü $a$ ve $b$ sayıları eşitlenmelidir. Yığıtta 1 varsa daha önce fazladan $b$ gelmiş demektir; bir $a$ gelince bir 1 silinir. Dizginin sonunda $a$ sayısı $b$ sayısına eşitse yığıtta yalnız $\$$ kalır ve kabul durumuna geçilir.

### 20.1 $abbbaa$ Girdisi

Slayttaki girdi $abbbaa$'dır (3 tane $a$, 3 tane $b$):

| Adım | Okunan | Geçiş | Yığıt (tepeden) |
|---|---|---|---|
| 1 | $a$ | $a,\$\to 0\$$ | $0\,\$$ |
| 2 | $b$ | $b,0\to\varepsilon$ | $\$$ |
| 3 | $b$ | $b,\$\to 1\$$ | $1\,\$$ |
| 4 | $b$ | $b,1\to 11$ | $11\,\$$ |
| 5 | $a$ | $a,1\to\varepsilon$ | $1\,\$$ |
| 6 | $a$ | $a,1\to\varepsilon$ | $\$$ |
| 7 | — | $\varepsilon,\$\to\$$ ($q_2$'ye) | $\$$ |

Karede son $a$ okunurken yığıttaki 1'in silindiği ve altında yalnız $\$$ kaldığı görülür (ekrandan, 02:50:00). Girdi kabul edilir. Python benzetimi $abbbaa$, $ab$, $abab$ için kabul; $aa$, $abb$ için ret sonucunu vermiştir.

<!-- BELİRSİZ: Bu izin ara adımları altyazıda büyük ölçüde bozuk; tablo slayttaki geçişlerden kuruldu (ara adım eklendi). -->

## Örnek Sorular

**Soru 1** (ekrandan, 00:35:00): $L = \{0^i 1 0^i 1 0^i \mid i \ge 1\}$ dilinin bağlamdan bağımsız olmadığını pompalama önsavıyla gösterin.

> **Çözüm (derste verilen):** $z = 0^n 1 0^n 1 0^n$, $|z| = 3n+2 > n$. $n = 3$ için $z = 000\,1\,000\,1\,000$ üzerinde $i = 0$ alınınca $uwy$ dile ait olmuyor. Bütün bölünmeler için durum ayrımı Bölüm 6'daki ders sonrası notta verilmiştir.

**Soru 2** (ekrandan, 00:40:00): $L = \{a^n b a^n \mid n \ge 0\}$ için $n = 3$, $z = aaabaaa$ dizgisini önsavın koşullarını sağlayacak biçimde bölün ve $uv^iwx^iy$'yi bulun.

> **Çözüm (derste verilen):** $u = aa$, $v = a$, $w = b$, $x = a$, $y = aa$; $|vx| = 2 > 0$, $|vwx| = 3$; $uv^iwx^iy = a^{i+2}ba^{i+2} \in L$. Bu, dilin bağlamdan bağımsız olduğunu ispatlamaz; ispat için $S \to aSa \mid b$ grameri verilir.

**Soru 3** (ekrandan, 01:25:00): $S \to aSS \mid AB \mid B$, $A \to aA \mid S$ gramerini sadeleştirin.

> **Çözüm (derste verilen):** $B$'nin üretimi olmadığı için $AB$ ve $B$ silinir; kalan $S \to aSS$ hiç sonlanmaz. Gramer hiçbir dizgi üretmez: $L(G) = \emptyset$.

**Soru 4** (ekrandan, 01:30:00): $S \to aS \mid aB$, $S \to b$, $B \to BB \mid a$, $C \to B$ gramerini sadeleştirin.

> **Çözüm (derste verilen):** $C$ ulaşılamaz, silinir. $B \to BB$ kendine dönen yararlı bir üretimdir, kaldırılamaz. Derste bırakılan sonuç $S \to aS \mid ab \mid aB$, $B \to BB \mid a$'dır. Satırın gerçekten $S \to b$ olması durumunda $S \to b$ seçeneği de korunmalıdır (Bölüm 13.2'deki ders sonrası not).

**Soru 5** (derste sözlü, 01:33:08): Öğrencilerle kurulan $S \to 0S0 \mid 1A1$, $A \to 0A \mid b$ gramerini sadeleştirin.

> **Çözüm (derste verilen):** $A \to b$ yerine konursa $S \to 0S0 \mid 1A1 \mid 1b1$, $A \to 0A \mid 0b$ olur; $A \to 0A$ kendine döndüğü için giderilemez. Gramer daha fazla sadeleşmez.

**Soru 6** (ekrandan, 01:45:00; hocaya göre sınavda sorulmuş bir gramer): $S \to Ab \mid aaB$, $A \to a \mid Aa$, $B \to b$ gramerini sadeleştirin.

> **Çözüm (derste verilen):** $B \to b$ yerine konur ve $B$ silinir: $S \to Ab \mid aab$, $A \to a \mid Aa$. $A \to Aa$ kaldırılamaz. (Bölüm 13.4'teki ek bilgiye göre $aab$ seçeneği de fazladır.)

**Soru 7** (ekrandan, 01:50:00; hocaya göre sınavdaki belirsiz gramer sorusunun grameri): $S \to 0A \mid 1B$, $A \to 0AA \mid 1S \mid 1$, $B \to 1BB \mid 0S \mid 0$ grameri sadeleştirilebilir mi?

> **Çözüm (derste verilen):** Hayır. $S$'yi ya da $A$, $B$ üretimlerini yerine koyarak yok etmeye çalışmak grameri daha karmaşık yapar; gramer en basit hâlindedir.

**Soru 8** (ekrandan, 01:50:00): $S \to X \mid Xb \mid Xbb$, $X \to Xa \mid cX \mid cXa \mid \varepsilon$ gramerindeki $\varepsilon$-üretimini kaldırın.

> **Çözüm (derste verilen):** $S \to X \mid Xb \mid Xbb \mid bb \mid b \mid \varepsilon$, $X \to cXa \mid cX \mid Xa \mid ca \mid c \mid a$. Sadeleştirme sırasına göre $S \to X$ birim üretimi de kaldırılabilir (Bölüm 13.6'daki ders sonrası not).

**Soru 9** (ekrandan, 02:15:00): $S \to abSb$, $S \to aa$ grameri GNF midir? Değilse GNF'ye çevirin.

> **Çözüm (derste verilen):** GNF değildir. GNF karşılığı: $S \to aBSB \mid aA$, $A \to a$, $B \to b$.

**Soru 10** (ekrandan, 02:35:00): $L = \{vv^R : v \in \{a,b\}^*\}$ için $aabbab$, $ab$, $ba$, $aa$, $abba$, $aabaabaa$ dizgilerinden hangileri dildedir?

> **Çözüm (derste verilen):** $aa$, $abba$ ve $aabaabaa$ dildedir; $aabbab$, $ab$ ve $ba$ dilde değildir. Python ile PDA benzetimi aynı sonucu vermiştir.

**Soru 11** (ekrandan, 02:25:00 ve 02:50:00): $\{a^n b^n\}$ PDA'sını $aaabbb$ ve $aab$ üzerinde, "$a$ sayısı = $b$ sayısı" PDA'sını $abbbaa$ üzerinde çalıştırın.

> **Çözüm (derste verilen):** $aaabbb$ kabul, $aab$ ret edilir (Bölüm 17); $abbbaa$ kabul edilir (Bölüm 20.1).

## Dersin Toparlaması

Bu derste önce bağlamdan bağımsız diller için pompalama önsavı görüldü. Önsav, CNF ayrıştırma ağacında tekrar eden bir değişkenden çıkar ve $v$ ile $x$ parçalarının birlikte pompalanmasını söyler. Önsav yalnız bir dilin bağlamdan bağımsız olmadığını göstermek için kullanılabilir; $\{0^i 1 0^i 1 0^i\}$ gibi üç sayımın eşleşmesini isteyen diller bağlamdan bağımsız değildir.

Ardından bağlamdan bağımsız gramerlerin sadeleştirilmesi ($\varepsilon$-üretimleri, birim üretimler, yararsız değişkenler) ve iki normal biçim (Chomsky ve Greibach) ele alındı; derste birçok gramer el yazısıyla sadeleştirildi. Son bölümde bağlamdan bağımsız dilleri tanıyan makine olarak yığıtlı otomatlara giriş yapıldı: geçiş gösterimi, yığıtın $\$$ ile başlaması, $\{a^n b^n\}$, $\{vv^R\}$ ve eşit sayıda $a$ ile $b$ içeren dizgiler için PDA'lar ve belirlenimsizliğin orta noktayı tahmin etmedeki rolü. Hoca bir sonraki derste yığıtlı otomatlarla ilgili çok sayıda örnek yapılacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
