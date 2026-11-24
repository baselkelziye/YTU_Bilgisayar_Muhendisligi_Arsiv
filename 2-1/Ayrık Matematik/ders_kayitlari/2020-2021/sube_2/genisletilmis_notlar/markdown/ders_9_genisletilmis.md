# Ders 9 Genişletilmiş Notu: Vize Soruları Çözümü, Öz Yinelemeli Algoritma Analizi ve Rekürans Bağıntıları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Birinci Ara Sınav Sorularının Çözümü
- 2. Asimptotik Gösterim Örnekleri
- 3. İteratif Analizin Kısa Tekrarı
- 4. Öz Yinelemeli Algoritmalar ve Rekürans Bağıntısı
- 5. İleri Yerine Koyma (Forward Substitution)
- 6. Geri Yerine Koyma (Backward Substitution)
- 7. Öz Yineleme Ağacı Yöntemi (Recursion Tree)
- 8. Ana Teorem (Master Theorem)
- 9. Rekürans Bağıntılarının Sınıflandırılması
- 10. Karakteristik Denklemle Çözüm
- 11. Sayı Dizilerini Rekürans Bağıntısına Dönüştürme
- 12. Kitaptan Örnekler: Fibonacci, Merge Sort, En Yakın Çift
- 13. Problemlerin Zorluğu: P ve NP
- Örnek Sorular
- Dersin Toparlaması

## 1. Birinci Ara Sınav Sorularının Çözümü

Ders, birinci ara sınavın bazı sorularının çözümüyle başladı. Hoca bütün soruları çözmedi; çoğu bilinen şeyler olduğu için ağırlığı lojik devre sorusuna ve çalışma zamanı sorusuna verdi. Sınavın ilk iki sorusu bağıntı özellikleri tablosu (yansımalı, simetrik, ters simetrik, geçişken, denklik ve kısmi sıralama bağıntısı) ile bir ifadenin prefix ve postfix gösterimleri ve yığınla değerlendirilmesiydi (ekrandan, 00:10:00). Bunların cevapları yalnızca ekranda gösterildi.

İkinci soru üzerine hoca kısa bir hatırlatma yaptı: prefix ifadeyi yığınla değerlendirirken $x^{1/n}$ gibi bir terimde önce $1/n$ hesaplanır, ardından bu değer $\alpha$ olarak kullanılıp $x^{\alpha}$ hesaplanır. Çözümlerde puan kaybının çoğu bu adımın unutulmasından geldi.

<!-- BELİRSİZ: Birinci ve ikinci sorunun cevap anahtarı ekranda kısa süre gösterildi; incelenen karelerde yalnız soru şablonu görünüyor, cevaplar okunamadı. -->

### 1.1 Lojik devre sorusu: soruyu anlamak

Soruda bir yolculuk için dört ulaşım türü vardır: demiryolu ($D$), karayolu ($K$), denizyolu ($D_z$) ve havayolu ($H$). İzin verilen kullanım biçimleri şunlardır (ekrandan, 00:15:00):

- Sadece karayolu kullanmak
- Sadece demiryolu kullanmak
- Havayolu ve demiryolunu birlikte kullanmak
- Karayolu ve demiryolunu birlikte kullanmak
- Denizyolu ve demiryolunu birlikte kullanmak
- Denizyolu, karayolu ve demiryolunu birlikte kullanmak

İlk istenen, devrenin kaç giriş ve kaç çıkışa sahip olduğudur. Dört farklı durum (dört ulaşım türü) olduğu için devrenin dört girişi, karar verme durumu olduğu için de bir çıkışı vardır: 4 girişli, 1 çıkışlı bir devre. Girişler doğruluk tablosunda bütün olasılıkları alır, çıkış $F$'dir. Kısalık için değişkenlere $D, K, D_z, H$ adı verilir; bunun yerine $A, B, C, D$ kullanıp sonra adlandırmak da olur.

Doğruluk tablosunda $F = 1$ olan satırlar şunlardır (ekrandan, 00:15:00):

| Satır | $D$ | $K$ | $D_z$ | $H$ | Durum |
|---|---|---|---|---|---|
| 4 | 0 | 1 | 0 | 0 | yalnız karayolu |
| 8 | 1 | 0 | 0 | 0 | yalnız demiryolu |
| 9 | 1 | 0 | 0 | 1 | hava ve demir |
| 10 | 1 | 0 | 1 | 0 | deniz ve demir |
| 12 | 1 | 1 | 0 | 0 | kara ve demir |
| 14 | 1 | 1 | 1 | 0 | deniz, kara ve demir |

Diğer bütün satırlarda $F = 0$'dır.

### 1.2 Bool cebri ile sadeleştirme

Önce fonksiyon mintermlerin toplamı (SOP) biçiminde yazılır (ekrandan, 00:20:00):

$$F = \underbrace{D'KD_z'H'}_{m_4} + \underbrace{DK'D_z'H'}_{m_8} + \underbrace{DK'D_z'H}_{m_9} + \underbrace{DK'D_zH'}_{m_{10}} + \underbrace{DKD_z'H'}_{m_{12}} + \underbrace{DKD_zH'}_{m_{14}}$$

Derste bir öğrenci $m_4$'te $H'$'nin yazılması gerektiğini hatırlattı, çünkü soru "sadece karayolu" diyor; hoca bunu düzeltti.

**Birinci adım.** $m_8, m_{10}, m_{12}, m_{14}$ terimlerinin hepsinde $D$ ve $H'$ ortaktır. $DH'$ parantezine alınınca:

$$DH'\,(K'D_z' + K'D_z + KD_z' + KD_z)$$

Parantezin içi $K'$ ve $K$ parantezlerine alınırsa $K'(D_z + D_z') + K(D_z + D_z') = K' + K = 1$ olur. Sadeleştirme yapmadan da görülebilir: $K$ ile $D_z$'nin dört birleşiminin hepsi aralarında toplamla yazılmıştır, bu yüzden ifade kesinlikle 1'dir. Böylece:

$$F = DH' + D'KD_z'H' + DK'D_z'H$$

**İkinci adım.** Burada şu kural kullanılır (ekrandan, 00:20:00):

$$x + x'yT = x + yT, \qquad x' + xyT = x' + yT$$

Yani bir şey ile o şeyin değili (yanında başka bir çarpan olsa da) toplamdaysa, değilli kısım düşer. Hoca bu kuralın ispatını daha önce derste göstermişti. Kuralı uygulamadan önce ortak parantez almak gerekir. İlk iki terimden $H'$ parantezine alınır:

$$H'(D + D'KD_z') = H'(D + KD_z') = H'D + H'KD_z'$$

**Üçüncü adım.** Şimdi $H'D$ ile son terim $DK'D_z'H$ birlikte ele alınır ve $D$ parantezine alınır:

$$D(H' + HK'D_z') = D(H' + K'D_z') = DH' + DK'D_z'$$

**Sonuç** (ekrandan, 00:25:00):

$$F = DH' + DK'D_z' + KH'D_z'$$

Bu ifade SOP biçiminde daha fazla sadeleşmez.

### 1.3 Karnaugh haritası ile doğrulama

Dört değişken olduğu için 4x4'lük bir Karnaugh haritası çizilir. Satırlar $DK$, sütunlar $D_zH$ ile etiketlenir; etiketler $00, 01, 11, 10$ sırasıyla yazılır (ekrandan, 00:25:00). Hoca, bazı öğrencilerin hâlâ $DK$, $DK'$ gibi harfli etiketler kullandığını, buna gerek olmadığını söyledi: $00, 01, 11, 10$ sırası her zaman aynıdır, değişken değişince harfli yazımda hata yapılıyor.

Haritadaki 1'ler:

```text
            D_zH:  00   01   11   10
DK = 00             .    .    .    .
DK = 01             1    .    .    .      (m4)
DK = 11             1    .    .    1      (m12, m14)
DK = 10             1    1    .    1      (m8, m9, m10)
```

Gruplama en büyük gruptan başlar. 16'lı grup yapılamaz, 8'li grup ($2^3$) yapılamaz; $2^2 = 4$'lü gruplara bakılır.

- **Dörtlü grup:** $DK = 11$ ve $10$ satırlarında $D_zH = 00$ ve $10$ sütunlarındaki dört hücre (harita kenarları komşu sayılır). Bu grupta $D$ değişmez (1), $K$ değişir, $D_z$ değişir, $H$ değişmez (0). Sonuç: $DH'$.
- Başka dörtlü grup yapılamaz; kalan 1'ler ikili gruplara alınır. Hoca, birçok öğrencinin bu 1'leri bir gruba dahil etmeyip tek tek aldığını ve bu yüzden yanlış yaptığını söyledi.
- **İkili grup 1:** $m_8$ ile $m_9$ ($DK = 10$, $D_zH = 00, 01$). $D = 1$, $K = 0$, $D_z = 0$ sabit, $H$ değişir. Sonuç: $DK'D_z'$.
- **İkili grup 2:** $m_4$ ile $m_{12}$ ($D_zH = 00$, $DK = 01, 11$). $D$ değişir, $K = 1$, $D_z = 0$, $H = 0$ sabit. Sonuç: $KD_z'H'$.

Harita da $F = DH' + DK'D_z' + KH'D_z'$ sonucunu verir; Bool cebri sonucuyla aynıdır. Hoca, gruplamalarda pek sorun olmadığını, hatanın çoğunun doğruluk tablosunun yanlış kurulmasından geldiğini söyledi.

### 1.4 Önermeleri cümleye çevirme sorusu

Beşinci soruda $p$, $q$, $r$ önermeleriyle verilen iki ifadenin Türkçe cümleye çevrilmesi isteniyordu (ekrandan, 00:10:00):

- a) $p \rightarrow \neg r$
- b) $\neg q \leftrightarrow r$

$p$: grip virüsüne sahip olmak, $r$: dersi geçmektir. a) şıkkının cevabı: "Grip virüsüne sahipseniz dersi geçemezsiniz." Bazı cevaplarda "Grip virüsüne sahip değilseniz dersi geçersiniz" yazılmıştı; bu yanlıştır, çünkü a) şıkkında $\neg p$ biçiminde bir önerme yoktur. Cümlenin değilini alarak De Morgan uygulamak burada geçerli değildir. b) şıkkı "ancak ve ancak" bağlacıdır: "Ancak ve ancak final sınavına girerseniz dersi geçersiniz." Bu, "Final sınavına girerseniz dersi geçersiniz ve dersi geçtiyseniz final sınavına girmişsinizdir" diye iki yönlü de yazılabilir. Karşıt ters (kontrapozitif) gibi başka bir biçimde yazmak tam puan getirmedi.

<!-- BELİRSİZ: q önermesinin tam metni ekranda görünmüyor. Cevaptan, ¬q'nun "final sınavına girmek" anlamına geldiği, yani q'nun büyük olasılıkla "final sınavını kaçırmak" olduğu anlaşılıyor. -->

### 1.5 Çalışma zamanı sorusu

Dördüncü soruda şu fonksiyonun $T(n)$ fonksiyonunun bulunması ve asimptotik gösterimle yazılması isteniyordu (ekrandan, 00:10:00):

```c
void function(int n)
{
    int sayac = 0;
    for (int i = n/2; i <= n; i++)
        for (int j = 1; j + n/2 <= n; j = j++)
            for (int k = 1; k <= n; k = k * 2)
                sayac++;
}
```

**Önce iki temel döngü kalıbı.** Hoca çözüme geçmeden iki kalıbı hatırlattı (ekrandan, 00:35:00):

- `for (i = 0; i < n; i++)`: $i$ sırasıyla $0, 1, 2, \dots, k$ değerlerini alır ve $k < n$ şartı bozulunca durur. $0$'dan $k$'ya $k + 1$ terim vardır; bunu $n$'e bağlı yazınca döngü $n$ kez döner. Koşul $\le$ olursa bir fazla, $1$'den başlarsa bir eksik olur.
- `for (i = 1; i < n; i *= 2)`: $i$ değerleri $1, 2, 4, \dots$, yani $2^0, 2^1, 2^2, \dots, 2^k$'dır. Durma noktasında $2^k = n$ alınır, iki tarafın $\log_2$'si alınınca $k = \log_2 n$ bulunur. Bu döngü $\log n$ kez döner.

**Her döngünün işlem sayısı** (ekrandan, 00:40:00):

- `int sayac = 0;` bir atama: $1$.
- Dış döngü: $i = n/2$ için bir bölme ve bir atama ($1 + 1$), bu bir kez olur. $i$ $n/2$'den $n$'e gittiği için döngü yaklaşık $n/2$ kez döner: $n/2$ karşılaştırma ($\le$) ve $n/2$ artırma ($++$).
- Ortadaki döngü: dış döngü $n/2$ kez döndüğü için bu döngü $n/2$ kez başlatılır. Her başlatmada `j = 1` ataması yapılır: $n/2$ atama. Koşul $j + n/2 \le n$ sabitlerle karşılaştırıldığı için kolayca çözülür: $n/2$ karşıya atılınca $j \le n/2$ olur; $j$ $1$'den başladığı için döngü $n/2$ kez döner. Derste bu döngünün karşılaştırma tarafı için $n/2$ toplama, $n/2$ bölme, $n/2$ karşılaştırma, $n/2$ artırma ve $n/2$ atama terimleri yazıldı.
- En içteki döngü: dıştaki iki döngünün dönme sayılarının çarpımı kadar, yani $\frac{n}{2}\cdot\frac{n}{2} = \frac{n^2}{4}$ kez başlatılır: $\frac{n^2}{4}$ atama (`k = 1`). Bu döngü doğrusal değil, ikişer kat artarak gider; her başlatmada $\log n$ kez döner. Böylece $\frac{n^2}{4}\log n$ karşılaştırma, $2\cdot\frac{n^2}{4}\log n$ çarpma ve atama (`k = k * 2`) ve $\frac{n^2}{4}\log n$ `sayac++` işlemi olur.

**Toplama.** Aşağıdan yukarıya toplanır: $\frac{n^2}{4}\log n$'li dört terim, bir $\frac{n^2}{4}$'lük terim, sekiz $\frac{n}{2}$'lik terim ve $1 + 2 = 3$ sabit işlem (ekrandan, 00:45:00):

$$T(n) = 4\cdot\frac{n^2}{4}\log n + \frac{n^2}{4} + 8\cdot\frac{n}{2} + 3 = n^2\log n + \frac{n^2}{4} + 4n + 3$$

**Asimptotik gösterim.** $T(n) \in O(n^2\log n)$ ya da derste gösterilen biçimde $T(n) \approx O(n^2\log n)$ yazılır. $n^3$ de bir üst sınırdır, ama $n^2\log n$ ondan önce gelen daha sıkı terimdir; $\frac{n^2}{4}$ ve diğer terimler daha küçüktür.

**Soru:** İkinci for döngüsündeki karşılaştırma işlemi neden $n/2$ kez sayıldı; üstteki döngü yüzünden $n^2/4$ olması gerekmez mi?
**Cevap:** Dıştaki döngü bir kez çalışmaya başlar ve $n/2$ kez döner. Her dönüşünde ortadaki döngüyü çağırır; yani ortadaki döngü $n/2$ kez çağrılır. Her çağrıda ortadaki döngünün kendi işlemleri yapılır. En içteki döngü ise dıştaki iki döngünün dönme sayılarının çarpımı, yani $\frac{n}{2}\cdot\frac{n}{2}$ kadar çağrılır. Hoca bu sırada eksik yazdığı bir terimi de düzeltti (sabit sayı 3, $n/2$'li terim sayısı 8 oldu).

Hoca, kaba analizle "birinci döngü $n/2$, ikinci döngü $n/2$, üçüncü döngü $\log n$; çarpım $\frac{n^2}{4}\log n$; katsayılar gider, sonuç $O(n^2\log n)$" diye çözenlerin de puan aldığını, bunun hızlı bir analiz olarak doğru olduğunu ama asıl analizin yukarıdaki olduğunu söyledi.

Dersin ikinci yarısında hoca bu sorudaki temel işlemin (basic operation) `sayac++` olduğunu belirtti: her durumda yapılan işlem budur. Kabaca $\frac{n}{2}\cdot\frac{n}{2}\cdot\log n$ kez çalışır.

> **Ders sonrası not:** Ekrandaki kodda ortadaki döngünün artırma kısmı `j = j++` yazılıdır; derste `j++` gibi ele alındı. C dilinde `j = j++` tanımsız davranıştır; büyük olasılıkla `j++` kastedilmiştir. Döngü sayıları derste yaklaşık alındı: $n$ çift olduğunda dış döngü tam olarak $n/2 + 1$, en içteki döngü $\lfloor\log_2 n\rfloor + 1$ kez döner. Python ile sayıldığında `sayac++` tam olarak $(n/2+1)\cdot(n/2)\cdot(\lfloor\log_2 n\rfloor+1)$ kez çalışıyor; asimptotik sonuç yine $\Theta(n^2\log n)$'dir.

## 2. Asimptotik Gösterim Örnekleri

Önceki derste Big-O ve diğer asimptotik gösterimler, iteratif algoritmaların analizi ve seçmeli sıralama (selection sort) işlenmişti. Hoca soru çözmek için birkaç örnek daha yaptı.

### 2.1 $4^n \in O(8^n)$ ispatı

$f(n) = 4^n$, $g(n) = 8^n$ verilmiş ve $f(n) \in O(g(n))$ olduğunun ispatı isteniyor (ekrandan, 00:50:00). Big-O kuralı: $f(n) \le c\cdot g(n)$ eşitsizliğini sağlayan bir $c$ sabiti (ve bir başlangıç değeri) bulunabiliyorsa $f(n) \in O(g(n))$'dir.

$$4^n \le c\cdot 8^n$$

$n = 1$ için $4 \le 8$, $n = 2$ için $16 \le 64$ sağlanır. Analitik çözüm için iki taraf $8^n$'e bölünür:

$$\frac{4^n}{8^n} = \frac{1}{2^n} \le c$$

$c$'nin tam sayı olması gerekmez. $n \ge 2$ için en basit seçim $n = 2$ koyarak $c = 1/4$'tür. Böyle bir $c$ gösterilebildiği için $4^n \in O(8^n)$.

### 2.2 $x^3 + 5x \notin O(x^2)$ ispatı

$f(x) = x^3 + 5x$'in $O(x^2)$'nin elemanı olmadığını göstermek için yine $x^3 + 5x \le c\,x^2$ yazılır (ekrandan, 00:55:00). $c$ yerine $x$ konursa eşitsizlik $x^3 + 5x \le x^3$ olur; bu hiçbir zaman sağlanmaz, tersine $x^3 + 5x > x^3$'tür. Girdi boyutu $x$ hep pozitiftir. $x$, $c$'den büyük alındığında hiçbir $c$ değeri eşitsizliği sağlamaz. Bu yüzden $f(x) \notin O(x^2)$.

<!-- BELİRSİZ: Ekrandaki son satırda "x² + 5x ≤ c·x²" yazıyor gibi görünüyor; bağlama göre kastedilen x³ + 5x'tir. -->

### 2.3 Limit yöntemi

Önceki derste anlatılan limit yöntemi tekrar edildi (ekrandan, 00:55:00):

$$\lim_{n\to\infty}\frac{f(n)}{g(n)} = L$$

- $L = 0$: pay küçük, payda büyük bir fonksiyondur (sayı bölü sonsuz gibi). $f(n) \in O(g(n))$ yazılır.
- $L$ sabit bir sayı: iki fonksiyon yakın derecelerdedir (örneğin biri $x^2$, öbürü $2x^2$). $f(n) \in \Theta(g(n))$ yazılır.
- $L = \infty$: payda küçük olandır. $f(n) \in \Omega(g(n))$ yazılır.

Limitte belirsizlik çıkarsa iki tarafın türevi alınarak L'Hôpital kuralı uygulanır. Hoca küçük-o (little o) ve küçük-omega (little omega) gösterimlerinin de olduğunu, bunların daha ayrıntılı olarak algoritma analizi ve veri yapıları derslerinde gösterileceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Küçük-o ve küçük-omega, Big-O ve Big-Omega'nın kesin (sıkı olmayan) sürümleridir. $f \in o(g)$, $f$'nin $g$'den kesinlikle daha yavaş büyüdüğünü, yani $\lim f/g = 0$ olduğunu söyler; $f \in \omega(g)$ ise $\lim f/g = \infty$ demektir. Bu yüzden limit $0$ çıktığında $f \in o(g)$, dolayısıyla $f \in O(g)$ da yazılabilir.

## 3. İteratif Analizin Kısa Tekrarı

Arada verilen molanın ardından hoca, şimdiye kadar iteratif algoritmaların analizinin ve sonucun asimptotik gösterimle yazılmasının görüldüğünü hatırlattı. Analizde girdi boyutu ve temel işlem belirlenir, $T(n)$ elde edilir, sonra asimptotik gösterimle özetlenir.

Temel işlem seçimi algoritmaya göre değişir. Sıralama algoritmalarında karşılaştırma her zaman yapılır, bu yüzden temel işlem olarak alınır. Yer değiştirme (swap) her zaman temel işlem değildir, çünkü her adımda yer değiştirmek gerekmez. Bazı durumlarda temel işlemin yapılıp yapılmaması girdiye bağlıdır; bu durumda en kötü, ortalama ve en iyi durum analizleri ayrı yapılır.

Seçmeli sıralamanın en kötü durumu, dizinin tersten (büyükten küçüğe) sıralı olup küçükten büyüğe sıralanmak istenmesidir. Dış döngü $0$'dan $n-1$'e döner, iç döngü $n-1-j$ kez döner. $j = 0$ iken $n-1$, $j = 1$ iken $n-2$, $j = n-2$ iken $1$ kez dönüş olur. Toplam, $1$'den $n-1$'e kadar sayıların toplamı gibidir ve sonuç $n^2$ mertebesindedir.

## 4. Öz Yinelemeli Algoritmalar ve Rekürans Bağıntısı

### 4.1 Öz yineleme nedir

Bir $f$ fonksiyonu bir parametre alır ve kendi içinde herhangi bir yerde $f$'yi farklı bir parametreyle yeniden çağırırsa bu öz yinelemedir (ekrandan, 01:30:00). Çağrıya kadar olan kısım normal iteratif analizle incelenir; ardından gelen aynı fonksiyon çağrısı genellikle daha küçük bir boyutla yapılır. Öz yineleme, böl ve yönet (divide and conquer) ile azalt ve yönet (decrease and conquer) yaklaşımlarında kullanılır; merge sort ve quick sort buna örnektir. Analiz, iteratif kısmın analizi ile öz yinelemeli çağrının analizinin birleşimidir.

Öz yinelemeli fonksiyonun sonsuza kadar çalışmasını engellemek için çağrının öncesinde ya da sonrasında bir `if` koşulu bulunur. Bu koşul belli bir şarta ulaşınca `return` eder; buna temel durum denir.

**Faktöriyel örneği.** `if (p == 0) return 1;` değilse `f(p - 1)` çağrılır ve sonuç $p$ ile çarpılır. $p = 5$ gönderildiğinde $f(5)$, $f(4)$'ü; $f(4)$, $f(3)$'ü; ... $f(1)$, $f(0)$'ı çağırır. $f(0)$ geri döner, ardından sırayla diğer çağrılar geri döner ve algoritma tamamlanır.

Öz yinelemeli algoritmalar fark denklemleri (difference equation) ya da rekürans bağıntıları (recurrence relation) ile çözülür. Fark denklemleri Sinyaller ve Sistemler dersinde de görülür; bu derste daha çok rekürans bağıntısı adıyla karşınıza çıkar.

### 4.2 Analiz adımları

- Girdi boyutu belirlenir.
- Temel işlem belirlenir.
- Temel işlemin yapılma sayısının aynı boyuttaki farklı girdilere göre değişip değişmediğine bakılır; değişiyorsa en kötü, en iyi ve ortalama durum ayrı ayrı incelenir.
- Temel işlemin kaç kez yapıldığını veren bir rekürans bağıntısı kurulur.
- Rekürans bağıntısı uygun bir yöntemle çözülür; sonuç yine $T(n)$'dir.
- $T(n)$ asimptotik gösterimle ifade edilir.

Rekürans bağıntısı, $n$ bağımsız değişkenine göre ifade edilen ve $n$'deki değeri önceki değerlerine bağlı olan bir fonksiyondur; örneğin $T(n) = T(n-1) + 1$.

### 4.3 Toplam örneği

$1$'den $n$'e kadar sayıların öz yinelemeli toplamı için tahtaya şu fonksiyon yazıldı (ekrandan, 01:35:00):

```c
void sum(int n[])
{
    if (n == 1)
        return n[1];
    else
        return n + sum(n - 1);
}
```

Tek eleman kaldıysa doğrudan o eleman döndürülür; değilse dizinin geri kalanı ($n-1$ eleman) için fonksiyon yeniden çağrılır. Bir temel işlem ve ardından $n-1$ elemanlı bir fonksiyon çağrısı vardır: $T(n) = T(n-1) + 1$. Bu bağıntı çözülünce $T(n)$ yalnız $n$'e bağlı hale gelir; burada $T(n) = n$, yani $O(n)$ çıkar.

**Soru:** Fonksiyonun dönüş tipi `void` yerine `int` olmamalı mı?
**Cevap:** İstenirse `int` yapılabilir, sorun değil; burada amaç kodun kendisi değil, bağıntının kurulmasıdır. Tahtadaki kod yalnız fikri gösteren kaba bir taslaktır.

### 4.4 Çözüm yöntemleri ve Fibonacci

Rekürans bağıntısı çözüm yöntemleri: ileri yerine koyma (forward substitution), geri yerine koyma (backward substitution), öz yineleme ağacı (recursion tree), ana teorem (master theorem) ve karakteristik denklem yöntemi. Sonuncusu özellikle ikinci ya da daha yüksek dereceli bağıntılar için kullanılır.

Fibonacci fonksiyonunda `n == 1` ise ya da `n == 2` ise 1 döndürülür, değilse `fib(n-1) + fib(n-2)` çağrılır. `fib(3)` çağrıldığında: $3$, $1$ ya da $2$ değildir; `fib(2)` çağrılır ve 1 döner; ardından `fib(1)` çağrılır ve 1 döner; $1 + 1 = 2$. `fib(4)` çağrıldığında `fib(3)` (o da `fib(2)` ve `fib(1)`'i çağırarak 2 bulur) ve `fib(2)` (1) çağrılır, $2 + 1 = 3$ olur. Dizi $1, 1, 2, 3, \dots$ diye gider.

Bu yaklaşımın bir sorunu, aynı değerlerin tekrar tekrar hesaplanmasıdır: `fib(2)` zaten bulunmuşken yeniden hesaplanır; `fib(5)` çağrılınca `fib(3)` iki kez hesaplanır. Bağıntı bir önceki ve iki önceki terime bağlı olduğu için çözümünde diferansiyel denklemlere benzeyen karakteristik denklem yöntemi kullanılır.

## 5. İleri Yerine Koyma (Forward Substitution)

İleri yerine koyma, tahmine ve bir örüntüyü görmeye dayanır. Başlangıç koşulundan başlayıp sonraki terimler hesaplanır, bir genel ifade tahmin edilir ve tahmin denetlenir.

**Örnek 1.** $T(n) = T(n-1) + 1$, $T(1) = 2$ (ekrandan, 01:40:00):

- $T(1) = 2$ (başlangıç koşulu)
- $T(2) = T(1) + 1 = 3$
- $T(3) = T(2) + 1 = 4$
- $T(4) = T(3) + 1 = 5$
- $T(5) = T(4) + 1 = 6$

Tahmin: $T(n) = n + 1$. Bu ifade artık içinde $T$'li bir terim bulundurmaz; öz yinelemeden kurtulunmuştur. Gayri resmi denetim: $T(n) = T(n-1) + 1 = [(n-1) + 1] + 1 = n + 1$ ve $T(1) = 1 + 1 = 2$; başlangıç koşulu da sağlanır.

**Örnek 2 (faktöriyel).** $n$ sayısının faktöriyelini hesaplayan programda $n = 0$ ise 1 döndürülür, değilse `n * factorial(n-1)` döndürülür. Slayttaki bağıntıda her çağrının maliyeti 3 alınmıştır: karşılaştırma (`if`), çarpma ve `return`. Normalde bu kadar ayrıntıya girilmez ve 1 yazılır. Bağıntı $T(n) = T(n-1) + 3$, $T(0) = 1$ olur (ekrandan, 01:45:00):

- $T(1) = T(0) + 3 = 4$
- $T(2) = 4 + 3 = 7$
- $T(3) = 7 + 3 = 10$
- sonraki terim $13$

Değerler üçer üçer artıyor. Hoca önce $n + 4$, $n + 3$ gibi tahminleri denedi ve tutmadığını gördü; doğru tahmin $T(n) = 3n + 1$'dir. İleri yerine koymanın dezavantajı budur: tahmin etmek bazı algoritmalarda zordur. Bu yüzden geri yerine koyma daha çok kullanılır.

**Örnek 3.** $1$'den $n$'e kadar sayıların toplamı $f(n) = n + f(n-1)$ bağıntısıyla çalışır: $f(5) = 5 + f(4)$, $f(4) = 4 + f(3)$, ... Sonuç $\frac{n(n+1)}{2}$'dir.

## 6. Geri Yerine Koyma (Backward Substitution)

Geri yerine koyma, sıfırıncı terimden $n$. terime gitmek yerine $n$. terimden başlangıç terimine doğru gider. Yine tahmin ve denetim mantığı vardır, ama örüntüyü görmek daha kolaydır ve birçok algoritmada işe yarar.

### 6.1 $T(n) = T(n-1) + 1$

$$T(n) = T(n-1) + 1 = T(n-2) + 1 + 1 = T(n-3) + 1 + 1 + 1 = \dots = T(n-k) + \underbrace{1 + \dots + 1}_{k\ \text{tane}}$$

Burada yapılan tahmin, birinci adımda bir tane, ikinci adımda iki tane, $k$. adımda $k$ tane 1 olduğudur. Algoritma bir yerde bitmelidir; $n - k$ temel duruma (burada 1'e) ulaşmalıdır. Bunun için $k = n - 1$ seçilir:

$$T(n) = T(1) + (n-1)$$

Başlangıç koşulu, tek eleman kaldığında öz yinelemeli fonksiyonun maliyetidir ve verilmelidir (1, 3, 5, 0 olabilir). $T(1) = 1$ ise $T(n) = (n-1) + 1 = n$ bulunur. Her adımda 1 yerine 3 eklenseydi $k$ tane 3, sonunda $n-1$ tane 3 olacaktı.

### 6.2 Böl ve yönet bağıntısı: $T(n) = T(n/2) + 1$

Azaltarak gitme durumlarında ($n$ yerine $n-1$, $n-2$, $n-4$ eleman çözmek) bağıntılar $T(n-1)$, $T(n-2)$ gibi fark biçiminde çıkar ve geri yerine koymayla çözülür. Ancak bağıntıda iki farklı önceki terim varsa (örneğin $T(n-1)$ ve $T(n-2)$ birlikte) geri yerine koyma kullanılamaz. Böl ve yönet algoritmalarında (ikili arama, merge sort) $n$ yerine $n/2$ ya da $n/3$ çağrılır.

$T(n) = T(n/2) + 1$ ve başlangıç değeri 1 için:

$$T(n) = T\!\left(\frac{n}{2^1}\right) + 1 = T\!\left(\frac{n}{2^2}\right) + 1 + 1 = T\!\left(\frac{n}{2^3}\right) + 1 + 1 + 1 = \dots = T\!\left(\frac{n}{2^k}\right) + k$$

Sonuca, $n/2^k$ 1 olduğunda ulaşılır. Bu yüzden $2^k = n$ olacak bir $k$ seçilir; iki tarafın logaritması alınınca $k = \log_2 n$ bulunur.

> **Hocanın vurgusu:** $2^k = n \Rightarrow k = \log_2 n$ kuralını çok iyi bilin, karşınıza çıkacak.

Yerine yazınca $T(n) = T(n/n) + \log_2 n = T(1) + \log_2 n = \log_2 n + 1$ olur. Big-O ile $O(\log n)$'dir.

<!-- BELİRSİZ: Hoca başlangıç koşulunu önce "t0 = 1" diye söyledi, çözümde T(1) = 1 olarak kullandı. -->

## 7. Öz Yineleme Ağacı Yöntemi (Recursion Tree)

Bu yöntemde başlangıç koşulu ve her adımdaki temel işlem maliyeti dikkate alınarak bir ağaç kurulur. Ağacın kökü problemin $n$ boyutlu halidir; algoritma nasıl bölünüyorsa ağaç da öyle bölünür ($n/2, n/2$; sonra $n/4, n/4, \dots$) ve sonunda bütün yapraklar 1 boyutlu olur. Her seviyedeki maliyetler toplanır; ağacın derinliği bulunursa toplam maliyet bulunur.

### 7.1 Slayttaki örnek: $T(n) = 4T(n/2) + n$

Slaytta kök maliyeti $n$, ikinci seviyede $2n$, üçüncü seviyede $4n$ olarak gösterilmiştir; ağacın derinliği $\log n$'dir (ekrandan, 01:55:00). Toplam:

$$n + 2n + 4n + \dots\ (\log_2 n\ \text{terim}) = n\,(1 + 2 + 4 + \dots) = n\cdot\frac{2^{\log_2 n} - 1}{2 - 1} = n(n-1) = n^2 - n = \Theta(n^2)$$

Terim toplama (geometrik seri) formülünden $T(n) = \Theta(n^2)$ bulunur.

### 7.2 Derste çözülen örnek: $T(n) = 2T(n/2) + 4n$

Hoca bu bağıntıyı üç yöntemle (öz yineleme ağacı, geri yerine koyma, ana teorem) çözdü (ekrandan, 02:00:00).

**Öz yineleme ağacı.** Kökte maliyet $4n$'dir. Bağıntıdaki "bölü 2" problemin yarıya indiğini, baştaki "2" iki parçaya bölündüğünü söyler.

- Seviye 0: $2^0 = 1$ düğüm, maliyet $4n$; toplam $4n$.
- Seviye 1: $2^1 = 2$ düğüm, her biri $\frac{4n}{2}$; toplam $4n$.
- Seviye 2: $2^2 = 4$ düğüm, her biri $\frac{4n}{2^2}$; toplam $4n$.
- Seviye $i$: $2^i$ düğüm, her biri $\frac{4n}{2^i}$; toplam $4n$.

Her seviyedeki toplam maliyet $4n$'dir. $T(n/2^i)$, $T(1)$'e ulaştığında durulur: $n = 2^i$, yani $i = \log n$. Seviyeler $0$'dan başladığı için $i + 1$ seviye vardır:

$$T(n) = \sum_{i=0}^{\log n} 4n = 4n(\log n + 1) = 4n\log n + 4n$$

Bu $O(n\log n)$'dir; $\Theta(n\log n)$ olarak da yazılabilir.

**Soru (hocanın sorusu):** $\Omega(n)$ yazılabilir mi?
**Cevap:** Asimptotik olarak doğrudur; alt sınır olarak $n\log n$'den küçük bir fonksiyon (örneğin $n$, hatta $\log n$) yazılabilir. Ama bunun algoritma için gerçekten bir alt sınır olduğunu, yani öyle bir durumun gerçekten oluştuğunu göstermek ayrıca algoritmanın içinde incelenmelidir.

**Geri yerine koyma** (ekrandan, 02:05:00 ve 02:10:00):

$$\begin{aligned}
T(n) &= 2T(n/2) + 4n \\
&= 2\left(2T(n/4) + 2n\right) + 4n = 4T(n/4) + 4n + 4n \\
&= 4\left(2T(n/8) + \tfrac{4n}{4}\right) + 4n + 4n = 8T(n/8) + 4n + 4n + 4n \\
&= 2^3\,T(n/2^3) + 3\cdot 4n \\
&\ \ \vdots \\
&= 2^i\,T(n/2^i) + i\cdot 4n
\end{aligned}$$

$T(n/2)$ açılırken $4\cdot\frac{n}{2} = 2n$ gelir; iki tane $2n$ de $4n$ eder. $i = \log_2 n$ yazılınca $2^{\log_2 n} = n$ ve $n/2^{\log_2 n} = 1$ olur:

$$T(n) = n\,T(1) + 4n\log n$$

Hoca önce başlangıç değerini 1 alıp $4n\log n + n$ buldu, sonra ağaçla aynı sonuca ulaşmak için başlangıç değerinin 4 olması gerektiğini söyledi: $T(1) = 4$ ile $T(n) = 4n\log n + 4n$. Her iki durumda da sonuç $n\log n$ mertebesindedir. Böl ve yönet bağıntılarında geri yerine koyma daha rahat çıkar; öz yineleme ağacı çok daha uzun sürer ama o da kullanılabilir.

## 8. Ana Teorem (Master Theorem)

Algoritmanın rekürans bağıntısı bir böl ve yönet yapısı içeriyorsa (problem $a$ parçaya, her biri $b$'ye bölünerek ayrılıyor ve her adımda $n^d$'lik bir ek maliyet var) ana teorem kullanılır (ekrandan, 02:10:00):

$$T(n) = a\,T\!\left(\frac{n}{b}\right) + f(n), \qquad f(n) \in \Theta(n^d)$$

$a \ge 1$, $b \ge 2$, $d \ge 0$ olmalıdır ve $f(n)$ bir polinom olmalıdır: $n^0$, $n^1$, $n^2$, $n^3$ olabilir, ama $2^n$ gibi üstel bir fonksiyon kesinlikle olamaz. Sonuç şu üç durumdan biridir:

- $a < b^d$ ise $T(n) \in \Theta(n^d)$
- $a = b^d$ ise $T(n) \in \Theta(n^d\log n)$
- $a > b^d$ ise $T(n) \in \Theta(n^{\log_b a})$

Ana teorem sonucu doğrudan $\Theta$ olarak verir.

**Örnek: $T(n) = 2T(n/2) + 4n$.** $a = 2$, $b = 2$; $4n$ birinci dereceden bir polinom olduğu için $d = 1$ (katsayıya bakılmaz). $b^d = 2^1 = 2 = a$; ikinci durum geçerlidir: $\Theta(n^1\log n) = \Theta(n\log n)$. Üç yöntem de aynı sonucu verdi.

**Örnek: ikili arama.** İkili aramanın karmaşıklığının $\log n$ olduğu bilinir. Bağıntısı $T(n) = T(n/2) + 1$'dir: her adımda temel işlem 1'dir, aranan bulunduysa ya da bulunamadıysa doğrudan dönülür. $a = 1$, $b = 2$, sabit terim olduğu için $d = 0$. $b^d = 2^0 = 1 = a$; ikinci durum: $\Theta(n^0\log n) = \Theta(\log n)$.

**Slayttaki örnek.** $T(n) = 16T(n/4) + 5n^3$ gibi bir bağıntıda $a = 16$, $b = 4$, $d = 3$ olur; $16 < 4^3 = 64$ olduğu için birinci duruma girer ve sonuç $\Theta(n^3)$'tür. Slayttaki diğer örneklerin hepsinde ortak olan, problemin bir şekilde 2'ye, 3'e, 4'e bölünmesi ve yandaki maliyet teriminin üstel değil polinomsal olmasıdır.

<!-- BELİRSİZ: Bu slayt örneğinin katsayıları altyazıdan ("16, t, n üzeri 4, 5, n küp") çıkarıldı; ilgili ana ait kare incelenmedi. -->

### 8.1 Bir öğrenci sorusu: $f(n)$ üstel olursa

Bir öğrenci, maliyet terimi polinom yerine üstel olursa ne olacağını sordu. Hoca böyle bir algoritma bilmediğini, ama rekürans bağıntılarının matematikte çok geniş bir küme olduğunu söyledi ve $T(n) = T(n/2) + 2^n$ bağıntısını geri yerine koymayla denedi (ekrandan, 02:15:00):

$$T(n) = T(n/2) + 2^n = T(n/4) + 2^{n/2} + 2^n = T(n/8) + 2^{n/4} + 2^{n/2} + 2^n = \dots$$

$i$ yine $\log n$ olur; geriye $2^n + 2^{n/2} + 2^{n/4} + \dots$ toplamı kalır. Hoca bu toplamı veren bir seri formülünün matematikte büyük olasılıkla bulunduğunu, ama kullandığımız algoritmalarda bu biçimde bir bağıntının çıkıp çıkmadığını bilmediğini söyledi. Benzetme olarak, hız problemlerinde konumdan ivmeye giderken en fazla ikinci türevin kullanıldığını, üçüncü türevin pek gerekmediğini; algoritmalarda da böyle bir terimin genelde çıkmadığını belirtti.

> **Ek bilgi (derste anlatılmadı):** Bu toplamda ilk terim baskındır: $2^{n/2} + 2^{n/4} + \dots$ kısmı en fazla $\log n \cdot 2^{n/2}$ kadardır ve $2^n$'in yanında ihmal edilebilir. Bu yüzden $T(n) = T(n/2) + 2^n$ için $T(n) \in \Theta(2^n)$'dir. Ana teoremin daha genel sürümü de bu durumu ($f(n)$ baskın) üçüncü durum olarak kapsar.

Fibonacci gibi $T(n) = T(n-1) + T(n-2)$, $T(0) = T(1) = 1$ biçimindeki bağıntılarda ise geri yerine koyma yapılamaz; $T(n)$ açılınca ifadeler birbirine karışır. Bunlar karakteristik denklem yöntemiyle, yani rekürans bağıntılarının analitik çözümüyle çözülür.

## 9. Rekürans Bağıntılarının Sınıflandırılması

Rekürans (İngilizce "recurrence", nüks etmek) bağıntısı, kendini kendisinin önceki terimleriyle ifade eden bağıntıdır. Hoca bu bölümde $T(n)$ yerine daha kısa olduğu için $a_n$ yazdı (ekrandan, 02:25:00).

### 9.1 Mertebeye (dereceye) göre

En geride olan terime bakılır. Ayrık zamanlı işaretlerde de aynı kavram vardır.

- $a_n = 5a_{n-1}$: birinci mertebe ($n-1$'den dolayı).
- $a_n = 4a_{n-8}$: sekizinci mertebe ($n-8$'den dolayı).
- $a_n = 4a_{n-4} - 5a_{n-3}$: dördüncü mertebe.

### 9.2 Homojenliğe göre

Bağıntıda yalnız $a_n$'li terimler varsa homojendir; bunun dışında bir terim varsa homojen değildir.

- $a_n = 3a_{n-1}$ ve $a_n = a_{n-1} + 2a_{n-2}$: homojen.
- $a_n = a_{n-1} + 2a_{n-2} + 3^n$: $3^n$ homojenliği bozar.
- $a_n = a_{n-1} + 2a_{n-3} - 4$: $-4$ homojenliği bozar.

Slaytta $n^3$'lü bir ek terimin de homojenliği bozduğu gösterildi.

### 9.3 Doğrusallığa göre

$a_n$'li terimler birbiriyle çarpılıyor ya da kuvveti alınıyorsa bağıntı doğrusal değildir. Burada kastedilen, $a_n$'li bir terimin bir başka $a_n$'li terimle çarpılmasıdır.

- $a_n = 5a_{n-2} + n\,a_{n-3} + n^2$: doğrusal ($a$'lı terimler kendi aralarında çarpılmıyor).
- $a_n = (a_{n-1})^2 + 3n$: doğrusal değil.
- $a_n = a_{n-2}\cdot a_{n-6}$: doğrusal değil.
- $a_n^3 = a_{n-1} + 3n$: sağ tarafa bakınca doğrusal görünür, ama sol tarafta üçüncü kuvvet olduğu için doğrusal değildir.

### 9.4 Sabit ya da değişken katsayıya göre

$a_n$'li terimlerin katsayısında $n$'e bağlı bir şey varsa değişken katsayılı, katsayılar 3, 5 gibi sabit sayılarsa sabit katsayılıdır.

- $a_n = 3a_{n-1} + 5a_{n-2}$: sabit katsayılı.
- $a_n = n\,a_{n-4} + 3a_{n-2}$: değişken katsayılı ($n$ işi bozuyor).
- $a_n = 3^n a_{n-2}$: değişken katsayılı.

### 9.5 Bağıntıdan terim hesaplamak ve bağıntıyı kurmak

Slayttaki bir örnekte $a_0$ ve $a_1$ verilip $a_5$ isteniyordu: önce $a_2$, sonra $a_3$, $a_4$, $a_5$ hesaplanır; bu bağıntıdan ileriye doğru gitmektir. Hoca sınavda $a_0$ ve $a_1$ verilip $a_{20}$'nin istenmeyeceğini, en fazla $a_3$, $a_4$ gibi terimlerin sorulabileceğini söyledi.

Rekürans bağıntısıyla ilgili iki iş vardır: algoritmadan rekürans bağıntısını kurmak ve bağıntıyı çözmek. İkili aramadan ya da merge sort'tan bağıntı çıkarmak görece kolaydır; bağıntı kurma teknikleri daha çok algoritma analizi dersinin konusudur. Bu ders daha çok çözme tarafıyla ilgilenir.

## 10. Karakteristik Denklemle Çözüm

İkinci ya da daha yüksek dereceli bir bağıntı varsa karakteristik köklerden yararlanılır. Yöntem sabit katsayılı, homojen, doğrusal bağıntılarda doğrudan kullanılır; bağıntı homojen değilse önce homojen kısmı çözülür, sonra bir özel çözüm eklenir.

### 10.1 Karakteristik denklemi yazmak

İkinci dereceden bir bağıntıda $a_n$ yerine $r^2$, $a_{n-1}$ yerine $r$, $a_{n-2}$ yerine $r^0 = 1$ yazılır ve katsayılar başlarına konur. Örneğin $a_n = 3a_{n-1} + 4a_{n-2}$ için:

$$r^2 = 3r + 4 \quad\Longrightarrow\quad r^2 - 3r - 4 = 0 \quad\Longrightarrow\quad (r-4)(r+1) = 0$$

Kökler $r_1 = 4$, $r_2 = -1$'dir (ekrandan, 02:30:00).

### 10.2 Köklere göre homojen çözüm

İkinci derece (ekrandan, 02:30:00):

- $r_1 \ne r_2$ ise $a_n^{(h)} = c_1 r_1^n + c_2 r_2^n$
- $r_1 = r_2$ ise $a_n^{(h)} = c_1 r_1^n + c_2 r_2^n\cdot n$

Örnekte kökler farklı olduğu için $a_n = c_1\cdot 4^n + c_2\cdot(-1)^n$. Algoritmalarda mutlaka $T(0) = 1$, $T(1) = 2$ gibi başlangıç koşulları verilir; bunlar yerine yazılıp $c_1$ ve $c_2$ bulunarak bağıntı çözülür.

Üçüncü derece (algoritmalarda pek çıkmaz):

- $r_1 \ne r_2 \ne r_3$ ise $a_n^{(h)} = c_1 r_1^n + c_2 r_2^n + c_3 r_3^n$
- $r_1 = r_2 = r_3$ ise $a_n^{(h)} = c_1 r_1^n + c_2 r_2^n\,n + c_3 r_3^n\,n^2$
- $r_1 = r_2 \ne r_3$ ise $a_n^{(h)} = c_1 r_1^n + c_2 r_2^n\,n + c_3 r_3^n$

Biri farklı, ikisi aynıysa aynı olanlardan birine $n$ eklenir, farklı olan bağımsız yazılır.

### 10.3 Farklı köklü örnek

Slayttaki örnekte $a_0 = 5$, $a_1 = 8$ verilmiştir ve bağıntı homojendir. Karakteristik denklem $r^2 = 3r + 10$, yani $r^2 - 3r - 10 = 0$'dır; kökler $5$ ve $-2$'dir. Kökler farklı olduğu için:

$$a_n = c_1\cdot 5^n + c_2\cdot(-2)^n$$

- $n = 0$ için: $c_1 + c_2 = 5$
- $n = 1$ için: $5c_1 - 2c_2 = 8$

İlk denklemi 2 ile çarpıp ikinciye eklersek $7c_1 = 18$, yani $c_1 = \frac{18}{7}$ ve $c_2 = 5 - \frac{18}{7} = \frac{17}{7}$ (ara adım eklendi). Çözüm:

$$a_n = \frac{18}{7}\cdot 5^n + \frac{17}{7}\cdot(-2)^n$$

Sonuç python ile ilk terimler üzerinde denetlendi.

<!-- BELİRSİZ: Bu örneğin bağıntısı altyazıdan "R² ... 3R ... artı 10" diye çıkarıldı (a_n = 3a_{n-1} + 10a_{n-2}); kökler 5 ve -2 ile tutarlı, ama slaytın karesi incelenmedi. -->

### 10.4 Eşit köklü örnek

Slayttaki bir başka örnekte iki kök de $-2$ çıkar. Eşit kök olduğu için ikinci terime $n$ çarpanı eklenir; başlangıç koşulları yerine yazılınca sonuç şu olur:

$$a_n = 3\cdot(-2)^n - \frac{11}{2}\cdot n\cdot(-2)^n$$

<!-- BELİRSİZ: Bu örneğin bağıntısı ve başlangıç koşulları altyazıda söylenmedi ve ilgili kare incelenmedi; yalnız kökler ve sonuç altyazıdan alındı. Sonuçtan a_0 = 3 ve a_1 = 5 olduğu anlaşılıyor. -->

### 10.5 Homojen olmayan bağıntılar: özel çözüm

Homojen olmayan bağıntıda önce bağıntı homojenmiş gibi çözülür, sonra bir özel çözüm tahmin edilip homojen çözüme eklenir:

$$a_n = a_n^{(h)} + a_n^{(\text{ö})}$$

Ek terim polinom ya da üstel olabilir; iki durumda tahmin biçimi farklıdır. Hoca, tek terimli bağıntıların (örneğin ikili arama) da karakteristik kökle çözülebileceğini, ama iki ya da daha fazla terim olduğunda genelde bu yöntemin, diğer durumlarda öbür yöntemlerin daha çok işe yaradığını söyledi. Soruda hangi yöntem istenirse o yöntemle çözülmelidir.

**Polinom ek terim örneği:** $a_n = 2a_{n-1} + 3a_{n-2} + 5$, $a_0 = 4$, $a_1 = 10$ (ekrandan, 02:35:00).

- Homojen kısım: $r^2 - 2r - 3 = 0$, kökler $3$ ve $-1$. $a_n^{(h)} = c_1\cdot 3^n + c_2\cdot(-1)^n$.
- Slayttaki not: polinomun derecesi ne ise özel çözümün derecesi de odur. Ek terim sabit (sıfırıncı derece) olduğu için özel çözüm $a_n^{(\text{ö})} = A$ diye tahmin edilir; $a_{n-1} = A$, $a_{n-2} = A$ olur.
- Bunlar eşitlikte yerine konur: $A = 2A + 3A + 5 \Rightarrow -4A = 5 \Rightarrow A = -\frac{5}{4}$.
- Genel çözüm: $a_n = c_1\cdot 3^n + c_2\cdot(-1)^n - \frac{5}{4}$.
- $a_0 = 4$: $c_1 + c_2 - \frac{5}{4} = 4 \Rightarrow c_1 + c_2 = \frac{21}{4}$.
- $a_1 = 10$: $3c_1 - c_2 - \frac{5}{4} = 10 \Rightarrow 3c_1 - c_2 = \frac{45}{4}$.
- Toplanınca $4c_1 = \frac{66}{4} = \frac{33}{2}$, yani $c_1 = \frac{33}{8}$; $c_2 = \frac{21}{4} - \frac{33}{8} = \frac{9}{8}$.

$$a_n = \frac{33}{8}\cdot 3^n + \frac{9}{8}\cdot(-1)^n - \frac{5}{4}$$

Sonuç python ile ilk terimler üzerinde denetlendi.

**Doğrusal ($n$'e bağlı) ek terim.** Ek terim $3n + 4$ gibi birinci dereceden bir polinomsa özel çözüm $An + B$ diye yazılır. Buna göre $a_{n-1}$ için $An - A + B$, $a_{n-2}$ için $An - 2A + B$ yazılıp bağıntıda yerine konur ve iki katsayı ($A$ ve $B$) bulunur. Sonra özel çözüm homojen çözüme eklenir ve başlangıç koşulları yerine yazılır.

<!-- BELİRSİZ: Bu örneğin bağıntısı ve bulunan A, B değerleri altyazıda söylenmedi; ilgili kare incelenmedi. -->

**Üstel ek terim.** Ek terim üstel olduğunda tahmin işlemi daha da uzar: özel çözüm, üstel terimin bir $A$ katı biçiminde tahmin edilir, yerine konur ve $A$ bulunur. Üstel tabanın karakteristik köklerden biriyle aynı olduğu durumda ($3^n$ örneği) özel çözüme bir $n$ çarpanı gelir; slayttaki örnekte $A = \frac{3}{4}$ ve özel çözüm $\frac{3}{4}\cdot 3^n\cdot n$ bulunmuştur.

<!-- BELİRSİZ: Üstel ek terimli örneklerin bağıntıları altyazıdan tam çıkarılamadı ve ilgili kareler incelenmedi. -->

> **Hocanın vurgusu:** Asıl üzerinde durulması gereken kısım homojen çözümdür. Algoritmalarda böyle polinom ya da üstel ek terimler pek çıkmaz; soru gelirse homojen çözüme kadar olan kısımlardan gelir. Sonraki kısımları (özel çözüm) çok fazla sormayı düşünmüyor.

## 11. Sayı Dizilerini Rekürans Bağıntısına Dönüştürme

Bazen bir sayı dizisi, bazen sözel bir ifade verilir ve olayın bir rekürans bağıntısıyla yazılması beklenir (ekrandan, 02:40:00). Bu, aritmetik ve geometrik dizilerde genel terim bulmaya benzer ve örüntü yakalamaya dayanır. Her zaman kolay değildir; yalnız belli örneklerde örüntü görülür.

- $4, 7, 13, 25, 49, 97, \dots$ dizisi: $a_0 = 4$, $a_n = 2a_{n-1} - 1$, $n \ge 1$. Örneğin $a_1 = 2\cdot 4 - 1 = 7$, $a_2 = 2\cdot 7 - 1 = 13$.
- $1, 3, 7, 17, 41, 99, 239, \dots$ dizisi: $a_0 = 1$, $a_1 = 3$, $a_n = 2a_{n-1} + a_{n-2}$, $n \ge 2$. Her terim, bir önceki terimin iki katı ile iki önceki terimin toplamıdır; örneğin $2\cdot 3 + 1 = 7$, $2\cdot 7 + 3 = 17$.

Bir algoritma bu şekilde tasarlandıktan sonra karmaşıklığı hesaplanabilir. Slayttaki başka bir örnekte $a_{n-1}$ ile $a_{n-2}$ toplanıp bir de üstel bir terim ekleniyordu; bu tür homojen olmayan bir bağıntıyı diziden tahmin etmek çok zordur.

Bir diğer slayt örneği: yalnız 0 ve 1'lerden oluşan $n$ uzunluğundaki sayı dizilerinden "00" içerenlerin sayısını veren rekürans bağıntısını, başlangıç koşullarıyla birlikte yazmak. $n = 2$ için 4 farklı durumdan, $n = 3$ için 8 farklı durumdan söz edildi.

<!-- BELİRSİZ: "00" içeren dizilerin bağıntısı altyazıda okunmadı ve ilgili kare incelenmedi. -->

> **Ek bilgi (derste anlatılmadı):** $n$ uzunluğunda "00" içeren ikili dizilerin sayısı $a_n$ ise $a_n = a_{n-1} + a_{n-2} + 2^{n-2}$, $a_2 = 1$, $a_3 = 3$ bağıntısı geçerlidir (1 ile başlayan, 01 ile başlayan ve 00 ile başlayan diziler ayrı sayılır). Bu bağıntı küçük $n$ değerleri için python ile sayılarak doğrulandı ($a_4 = 8$, $a_5 = 19$). Slayttaki bağıntının bu olup olmadığı büyük olasılıkla evettir, ama karede doğrulanmadı.

Hoca bölümü şöyle bağladı: problemi ve algoritmayı tasarlamak bir konu, tasarlanan öz yinelemeli algoritmadan rekürans bağıntısını çıkarmak bir başka konu, bağıntıyı çözmek de bir başka konudur. Bu ders, çıkarılmış bir bağıntıyı ait olduğu sınıfa göre çözmeyi ele alır.

## 12. Kitaptan Örnekler: Fibonacci, Merge Sort, En Yakın Çift

Hoca dersin kaynak kitabını (Rosen, *Discrete Mathematics and Its Applications*, 7. baskı; Türkçe çevirisi de var) açtı (ekrandan, 02:45:00). Öz yinelemeli algoritmalar 5. bölümün 4. kısmında, doğrusal rekürans bağıntılarının çözümü 8. bölümün 2. kısmında, böl ve yönet algoritmaları 8. bölümün 3. kısmında, üreteç fonksiyonları (generating functions) 8.4'te anlatılır. Kitap bu konuları adım adım anlattığı için tavsiye edildi.

### 12.1 Fibonacci sayıları

Kitapta başlangıç koşulları $f_0 = 0$, $f_1 = 1$ olarak verilir: $f_2 = 1$, ... Genelde kolaylık için dizi $1, 1, 2$ diye yazılır, ama öncesinde bir 0 vardır: 0 ile 1 toplanıp 1'i, 1 ile 1 toplanıp 2'yi oluşturur. Bu sıfırıncı, birinci, ikinci terim diye gider.

Bağıntı $f_n = f_{n-1} + f_{n-2}$ olduğu için karakteristik denklem:

$$r^2 = r + 1 \quad\Longrightarrow\quad r^2 - r - 1 = 0 \quad\Longrightarrow\quad r_{1,2} = \frac{1 \pm \sqrt5}{2}$$

Kökler farklıdır:

$$f_n = \alpha_1\left(\frac{1+\sqrt5}{2}\right)^n + \alpha_2\left(\frac{1-\sqrt5}{2}\right)^n$$

Başlangıç koşulları yerine yazılınca $\alpha_1 = \frac{1}{\sqrt5}$, $\alpha_2 = -\frac{1}{\sqrt5}$ bulunur. Fibonacci sayılarının karmaşıklığını gösteren denklem budur; açılırsa kabaca $\left(\frac{1+\sqrt5}{2}\right)^n$ mertebesinde, Big-O cinsinden üstel bir ifade elde edilir. Formül python ile ilk 20 terim için denetlendi.

Kitapta üç bilinmeyenli (üçüncü dereceden) örnekler ve homojen olmayan çözümler (örneğin $7^n$'li ek terim) de vardır.

### 12.2 Ana teoremle çözülebilen bir kitap örneği

Kitaptaki bir örnek $f(n) = 7f(n/2) + \frac{15n^2}{4}$ bağıntısıdır. Hoca bunun ana teoremle ya da geri yerine koymayla çözülebileceğini, ama $n^2$'li terim yüzünden homojen olmadığı için karakteristik kök yönteminin zor olacağını, ana teoremin daha kolay geleceğini söyledi. Çözümü derste yapılmadı (bkz. Örnek Sorular).

### 12.3 Merge sort

Merge sort'un bağıntısı $M(n) = 2M(n/2) + n$'dir (ekrandan, 02:45:00). Algoritma diziyi ikiye böler: örneğin 16 elemanlı bir dizi 8'e 8, sonra 4'e 4, sonra 2'ye 2 ve en sonunda birer elemana bölünür. Ardından parçalar birleştirilir: birleştirirken küçük olan öne alınır. Kodda `mergeSort(arr, l, m)` ile sol yarı (soldan orta noktaya), `mergeSort(arr, m+1, r)` ile sağ yarı öz yinelemeli olarak sıralanır; bölme $l$, $r$'ye ulaşana kadar sürer, sonra birleştirme (merge) başlar.

Birleştirme örneği: bir yanda $4, 8$, öbür yanda $3, 6$ sıralı parçaları varsa sırayla en küçükler alınır ve $3, 4, 6, 8$ elde edilir. İki sıralı dizinin birleştirilmesi ilk programlama derslerinde anlatılan bir algoritmadır.

Bağıntıdaki 2 katsayısı bölme işleminin iki koldan yürüdüğünü, $n$ terimi her bölmedeki (birleştirme) maliyeti gösterir. Ana teoremde $a = 2$, $b = 2$, $d = 1$ ve $2 = 2^1$ olduğundan $n\log n$ bulunur. Normalde sıralama algoritmalarında $n^2$ karmaşıklık çıkar; merge sort ve quick sort $n\log n$ verir. Merge sort'un bedeli bellektir: seçmeli sıralamada tek bir geçici (`tmp`) değişkenle bütün dizi sıralanabilirken merge sort'ta fazladan birçok diziye ve kopyalamaya ihtiyaç vardır.

### 12.4 En yakın nokta çifti (closest pair)

İki boyutlu uzayda bir sürü nokta varken birbirine en yakın iki noktayı bulmak istiyoruz.

**Soru (hocanın sorusu):** Basit bir algoritmanın karmaşıklığı ne olur?
**Cevap:** $n^2$. Her nokta alınır, bütün noktalara uzaklığı hesaplanır; $n$ noktanın her biri için $n$ uzaklık hesabı yapılır. $n!$ olmaz; öyle bir algoritma gereksizdir.

Öz yinelemeli en yakın çift algoritmasında noktalar önce merge sort ile $x$ eksenine, bir de $y$ eksenine göre sıralanır; sıralamanın maliyeti $n\log n$'dir. Sıralandıktan sonra belli bir şerit (kuşak) içinde arama yapılarak daha kısa sürede sonuca ulaşılır. Elde edilen bağıntıda $a = 2$, $b = 2$, $d = 1$ olduğu için merge sort'la aynı biçimde $n\log n$ karmaşıklık bulunur. Hoca, kitaptaki analizde şerit içinde bir noktanın en fazla belli sayıda (6 civarı) noktayla karşılaştırılması gerektiğini hatırladığını söyledi ve bu iki sayfanın okunmasını, mümkünse kodunun yazılmasını tavsiye etti.

## 13. Problemlerin Zorluğu: P ve NP

Algoritmaların karmaşıklığı vardır; problemler için ise karmaşıklıktan çok zorluktan söz edilir.

- **Çözülebilir (tractable) problemler:** Polinom zamanda ($n^2$, $n^3$, $n^4$ gibi) çözülebilen problemlerdir. $2^n$, $3^n$ gibi sürelere göre çok daha kısa sürede çözülürler. $n^{100}$ gibi bir polinom da uzun sürer, ama polinom zaman genel olarak iyidir; bazen polinom zamanı da iyileştirmek gerekir.
- **Çözülemeyen (intractable) problemler:** Şu an için polinom zamanda çözülemeyen problemlerdir; bilinen algoritmanın karmaşıklığı $2^n$, $3^n$ ya da $n!$ çıkar. En kötü durumda, küçük girdilerle bile genellikle aşırı zaman gerektirirler. "Şu an için" denmesinin nedeni, ileride farklı bir teknik geliştirilirse çözülebilir hale gelebilmeleridir.
- **Hiç çözülemeyen problemler:** Hiçbir algoritmanın çözemediği problemlerdir. Durma problemi (halting problem) Alan Turing tarafından çözülemez olduğu gösterilmiştir: herhangi bir programın sonlanıp sonlanmayacağını söyleyen bir program yazmak.

**Permütasyon örneği.** İkili veride 5 haneli bütün durumlar $2^5$'tir (doğruluk tablosundan bilinir). 0 ve 1 yerine 16'lık sistem kullanılsaydı $16^5$ durum olurdu; polinom zamandan çıkılıp üstel zamana geçilir. Bir parola üretirken her karakter her yere gelebilir; ASCII tablosunda 256 farklı karakter varken 10 karakterlik bir parola için $256^{10}$ farklı durum vardır. Bunu polinom zamanda çözmek şu an için mümkün görünmüyor.

**Problem sınıfları** (ekrandan, 03:00:00):

- **P sınıfı:** Polinom zamanda çözülebilen problemler.
- **NP sınıfı:** Bir çözümü polinom zamanda kontrol edilebilen (doğrulanabilen) problemler. NP, "belirli olmayan polinom zamanlı" (nondeterministic polynomial time) demektir.
- **NP-tam (NP-complete) problemler:** Bunlardan herhangi biri polinomsal en kötü durum zaman algoritmasıyla çözülebilirse, NP sınıfındaki bütün problemler de polinomsal en kötü durum zaman algoritmalarıyla çözülebilir.
- **NP-zor (NP-hard):** Slayttaki tanıma göre, polinom zamanda bir çözümü olduğunu ispatlayamadığımız karar problemlerinin karmaşıklık sınıfıdır.

Bu konuların ayrıntısı Hesaplama Kuramı dersinde, bir kısmı da veri yapıları ve algoritma analizi derslerinde anlatılır. Kitabın algoritmalar bölümündeki algoritma karmaşıklığı (Complexity of Algorithms) kısmının genel kültür için okunması tavsiye edildi.

> **Ek bilgi (derste anlatılmadı):** Yaygın kullanılan tanımda NP-zor, NP'deki her problemin polinom zamanda kendisine indirgenebildiği problemlerdir; NP-zor bir problemin NP'de olması gerekmez. NP-tam problemler hem NP'de olan hem de NP-zor olan problemlerdir. P'nin NP'ye eşit olup olmadığı bilinmemektedir.

## Örnek Sorular

### Soru 1: Lojik devre tasarımı (ekrandan, 00:15:00)

Bir yolculukta demiryolu ($D$), karayolu ($K$), denizyolu ($D_z$) ve havayolu ($H$) kullanılabilir. Yalnız şu kullanımlara izin verilir: sadece karayolu; sadece demiryolu; havayolu ve demiryolu birlikte; karayolu ve demiryolu birlikte; denizyolu ve demiryolu birlikte; denizyolu, karayolu ve demiryolu birlikte. İzin verilen durumlarda 1 veren lojik devre kaç giriş ve kaç çıkışa sahiptir? Doğruluk tablosunu kurun, fonksiyonu Bool cebri kuralları ile ve Karnaugh haritası ile sadeleştirin.

> **Çözüm (derste verildi):** 4 giriş, 1 çıkış. $F = \sum m(4, 8, 9, 10, 12, 14)$. Bool cebri ve Karnaugh haritası aynı sonucu verir: $F = DH' + DK'D_z' + KH'D_z'$. Ayrıntılı çözüm için bkz. Bölüm 1.2 ve 1.3. Sonuç python ile 16 satırın hepsinde denetlendi.

### Soru 2: Çalışma zamanı (ekrandan, 00:10:00)

Aşağıdaki fonksiyonun $T(n)$ fonksiyonunu bulun ve asimptotik gösterimle ifade edin.

```c
void function(int n)
{
    int sayac = 0;
    for (int i = n/2; i <= n; i++)
        for (int j = 1; j + n/2 <= n; j = j++)
            for (int k = 1; k <= n; k = k * 2)
                sayac++;
}
```

> **Çözüm (derste verildi):** $T(n) = n^2\log n + \frac{n^2}{4} + 4n + 3 \in O(n^2\log n)$. Dış döngü ve ortadaki döngü yaklaşık $n/2$'şer, en içteki döngü $\log n$ kez döner. Ayrıntı için bkz. Bölüm 1.5.

### Soru 3: Önermeleri cümleye çevirme (ekrandan, 00:10:00)

$p$: grip virüsüne sahip olmak, $r$: dersi geçmek olmak üzere (q'nun metni için bkz. Bölüm 1.4'teki not) a) $p \rightarrow \neg r$ ve b) $\neg q \leftrightarrow r$ önermelerini Türkçe cümle olarak yazın.

> **Çözüm (derste verildi):** a) "Grip virüsüne sahipseniz dersi geçemezsiniz." b) "Ancak ve ancak final sınavına girerseniz dersi geçersiniz."

### Soru 4: $4^n \in O(8^n)$ (ekrandan, 00:50:00)

$f(n) = 4^n$, $g(n) = 8^n$ için $f(n) \in O(g(n))$ olduğunu ispatlayın.

> **Çözüm (derste verildi):** $4^n \le c\cdot 8^n \iff (1/2)^n \le c$; $n \ge 2$ için $c = 1/4$ seçilebilir. Böyle bir $c$ bulunduğu için $4^n \in O(8^n)$.

### Soru 5: $x^3 + 5x \notin O(x^2)$ (ekrandan, 00:55:00)

$f(x) = x^3 + 5x$'in $O(x^2)$'nin elemanı olmadığını gösterin.

> **Çözüm (derste verildi):** $x^3 + 5x \le c\,x^2$ eşitsizliği $x > c$ için hiçbir sabit $c$ ile sağlanmaz (örneğin $c = x$ konunca $x^3 + 5x > x^3$). Bu yüzden $f(x) \notin O(x^2)$.

### Soru 6: İleri yerine koyma (ekrandan, 01:45:00)

$T(n) = T(n-1) + 3$, $T(0) = 1$ bağıntısını çözün.

> **Çözüm (derste verildi):** $T(1) = 4$, $T(2) = 7$, $T(3) = 10$, $T(4) = 13$; tahmin $T(n) = 3n + 1$. Denetim: $3(n-1) + 1 + 3 = 3n + 1$ ve $T(0) = 1$.

### Soru 7: Üç yöntemle çözüm (ekrandan, 02:00:00)

$T(n) = 2T(n/2) + 4n$ bağıntısını öz yineleme ağacı, geri yerine koyma ve ana teorem ile çözün.

> **Çözüm (derste verildi):** Ağaçta her seviyenin maliyeti $4n$, seviye sayısı $\log n + 1$: $T(n) = 4n\log n + 4n$. Geri yerine koymada $T(n) = 2^iT(n/2^i) + 4in$; $i = \log n$ ve $T(1) = 4$ ile aynı sonuç. Ana teoremde $a = 2$, $b = 2$, $d = 1$, $a = b^d$: $\Theta(n\log n)$. Sonuç python ile $n = 2^k$ değerleri için denetlendi.

### Soru 8: Karakteristik denklem (ekrandan, 02:35:00)

$a_n = 2a_{n-1} + 3a_{n-2} + 5$, $a_0 = 4$, $a_1 = 10$ bağıntısını çözün.

> **Çözüm (derste verildi, slayttan):** $a_n = \frac{33}{8}\cdot 3^n + \frac{9}{8}\cdot(-1)^n - \frac{5}{4}$. Ayrıntı için bkz. Bölüm 10.5.

### Soru 9: Sayı dizisinden bağıntı (ekrandan, 02:40:00)

$1, 3, 7, 17, 41, 99, 239, \dots$ sayı dizisini rekürans bağıntısı olarak yazın.

> **Çözüm (derste verildi, slayttan):** $a_0 = 1$, $a_1 = 3$, $a_n = 2a_{n-1} + a_{n-2}$, $n \ge 2$. Dizi python ile üretilip denetlendi.

### Soru 10: Ana teorem (derste sözlü, 02:45:09)

$f(n) = 7f(n/2) + \frac{15n^2}{4}$ bağıntısının asimptotik çözümü nedir?

> **Çözüm (derste verilmedi):** $a = 7$, $b = 2$, $d = 2$. $b^d = 4 < 7 = a$ olduğu için üçüncü durum geçerlidir: $f(n) \in \Theta(n^{\log_2 7}) \approx \Theta(n^{2.81})$.

## Dersin Toparlaması

Bu derste önce birinci ara sınavın lojik devre, çalışma zamanı ve önerme soruları çözüldü. Lojik devre sorusunda aynı fonksiyonun Bool cebri kurallarıyla ve Karnaugh haritasıyla sadeleştirilmesinin aynı sonucu verdiği görüldü. Çalışma zamanı sorusunda iç içe döngülerin çağrılma sayılarının nasıl çarpıldığı ve ikiye katlanan döngünün $\log n$ kez döndüğü üzerinde duruldu. Ardından asimptotik gösterim örnekleriyle Big-O tanımı ve limit yöntemi tekrar edildi.

Dersin ana konusu öz yinelemeli algoritmaların analiziydi: öz yinelemeli bir algoritmadan bir rekürans bağıntısı çıkar ve bu bağıntı ileri ya da geri yerine koyma, öz yineleme ağacı, ana teorem ya da karakteristik denklem yöntemleriyle çözülerek $T(n)$ ve asimptotik karmaşıklık bulunur. Rekürans bağıntıları mertebe, homojenlik, doğrusallık ve katsayılara göre sınıflandırıldı; Fibonacci, merge sort ve en yakın çift problemleri kitaptan örnek olarak incelendi. Ders, problemlerin zorluğu ve P, NP, NP-tam, NP-zor sınıflarıyla kapandı. Hoca bundan sonra çizgeler, ağaçlar, kromatik polinomlar ve sonlu durum makinelerine (finite state machine) geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
