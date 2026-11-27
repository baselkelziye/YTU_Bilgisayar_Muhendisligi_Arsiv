# Ders 7 Genişletilmiş Notu: Vize Soru Çözümü ve Rekürans Bağıntıları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Birinci Vize Sorularının Çözümü
- 2. Öz Yinelemeli Bağıntılar ve İleri Yerine Koyma
- 3. Rekürans Bağıntısı ile Dizi Arasındaki Fark
- 4. Rekürans Bağıntılarının Sınıflandırılması
- 5. Sabit Katsayılı Homojen Bağıntılar: Karakteristik Kök Yöntemi
- 6. Homojen Olmayan Bağıntılar ve Özel Çözüm
- 7. Sayı Dizilerini ve Sözel Problemleri Rekürans Bağıntısına Dönüştürme
- 8. Problemlerin Karmaşıklık Sınıfları
- Örnek Sorular
- Dersin Toparlaması

## 1. Birinci Vize Sorularının Çözümü

Dersin ilk yarım saatinde birinci vizenin soruları ekranda açılarak çözüldü. Sorular ve cevap anahtarı bir kelime işlemci belgesinde gösterildi (ekrandan, 00:10:00 - 00:25:00). Soruların tam metni "Örnek Sorular" bölümündedir; burada anlatım akışı verilir.

### 1.1 $xy \ge 1$ bağıntısının özellikleri

Soruda küme açıkça yazılmadığı için kafa karışıklığı yaşandığı söylendi. Hoca kümenin belli olduğunu belirtti: tam sayılar, yani $-\infty$'dan $+\infty$'a bütün tam sayılar. Bağıntı $R=\{(x,y)\in\mathbb{Z}^2 \mid xy\ge 1\}$'dir.

- **Refleksif mi?** Refleksiflik için bütün $(x,x)$ çiftleri bağıntıda olmalıdır. $(1,1)$, $(2,2)$, $(3,3)$ ve negatifler için $(-1,-1)$ gibi çiftler bağıntıdadır. Ama $0\in\mathbb{Z}$ ve $0\cdot 0 = 0$, $1$'den büyük ya da $1$'e eşit değildir. $(0,0)$ yazılamadığı için bağıntı refleksif değildir.
- **İrrefleksif mi?** İrrefleksifte köşegen elemanlarının hiçbiri bağıntıda olmamalıdır. $(1,1)$ bağıntıda olduğu için irrefleksif de değildir.
- **Nonrefleksif mi?** Nonrefleksifte köşegen elemanlarının bir kısmı vardır, bir kısmı yoktur. $(0,0)$ yok, diğerleri var; köşegenin tamamı ne bağıntıda ne de bağıntı dışında. Öyleyse bağıntı nonrefleksiftir.
- **Simetrik mi?** Çarpmanın değişme özelliği vardır: $xy = yx$. $(x,y)$ bağıntıdaysa $(y,x)$ da bağıntıdadır; bağıntı simetriktir.
- **Antisimetrik mi?** $1\cdot 2 = 2 \ge 1$ ve $2\cdot 1 = 2\ge1$; hem $(1,2)$ hem $(2,1)$ bağıntıda ama $1\ne 2$. Antisimetrik değildir.
- **Geçişli mi?** $xy\ge1$ ve $yz\ge1$ ise $xz\ge 1$ de olur; bağıntı geçişlidir.

> **Ek bilgi (derste anlatılmadı):** Geçişliliğin gerekçesi şöyle kurulabilir: $xy\ge1$ olan tam sayılar sıfırdan farklı ve aynı işaretlidir. $xy\ge1$ ve $yz\ge1$ ise $x$, $y$, $z$ üçü de aynı işaretlidir; aynı işaretli iki sıfırdan farklı tam sayının çarpımı en az $1$'dir.

Hoca, kendi okuduğu grupta irrefleksif ile nonrefleksifin karıştırıldığını belirtti ve farkı yeniden hatırlattı.

### 1.2 Hasse diyagramı

Soru: $S=\{0,2,5,10,11,15\}$ kümesi için $x\le y$ şartını sağlayan bağıntının Hasse diyagramı çizilebilir mi?

Hasse diyagramının çizilebilmesi için bağıntının kısmi sıralama bağıntısı olması, yani refleksif, antisimetrik ve geçişli olması gerekir. $\le$ bu üç özelliği sağlar. Bağıntının çiftleri önce köşegen elemanlarıdır: $(0,0),(2,2),(5,5),(10,10),(11,11),(15,15)$. Sonra $x<y$ olan çiftler gelir: $(0,2),(0,5),(0,10),(0,11),(0,15),(2,5),(2,10),\dots$

> **Hocanın vurgusu:** Bu bağıntının grafını çizip "Hasse" diye vermek yanlıştır. Hasse diyagramı, orijinal graftan refleksif halkalar ve geçişlilikten gelen kenarlar ($(x,y)$ ve $(y,z)$ varken $(x,z)$ kenarı) silinerek elde edilir.

Bazı öğrencilerin Hasse diyagramının denklik bağıntısında çizileceğini düşünüp bağıntının denklik bağıntısı olmadığı gerekçesiyle diyagramı hiç çizmediği de söylendi. Hasse diyagramı sıralama bağıntısı içindir.

Bütün silmelerden sonra geriye tek bir zincir kalır (ekrandan, 00:15:00):

```text
0 — 2 — 5 — 10 — 11 — 15
```

> **Ders sonrası not:** Ekrandaki cevap anahtarında zincir "0, 2, 2, 10, 11, 15" diye yazılmış; ikinci "2" bir yazım hatasıdır, doğrusu $5$'tir.

### 1.3 Kredi problemi ve Karnaugh haritası

Dört değişken olduğu için doğruluk tablosu $2^4=16$ satırdır. Önemli olan fonksiyonun değerlerini doğru yerleştirmektir. Değişkenler: ev ($E$), araba ($A$), bankada belirli miktarın üzerinde para ($B$), iş yeri ($I$).

- En az bir ev ya da iş yeri varsa (yalnız ev, yalnız iş yeri ya da ikisi birden) $F=1$.
- Ev ve iş yeri yoksa, bankada para ve araba birlikte varsa $F=1$.

Ekrandaki tablo (ekrandan, 00:15:00) şu mintermleri verir:

$$F(E,A,B,I)=\sum m(1,3,5,6,7,8,9,10,11,12,13,14,15)$$

Karnaugh haritası (satırlar $BI$, sütunlar $EA$, Gray sırasıyla) ekrandan aktarılmıştır:

| $BI \backslash EA$ | 00 | 01 | 11 | 10 |
|---|---|---|---|---|
| 00 | 0 | 0 | 1 | 1 |
| 01 | 1 | 1 | 1 | 1 |
| 11 | 1 | 1 | 1 | 1 |
| 10 | 0 | 1 | 1 | 1 |

Gruplama sırası derste şöyle anlatıldı: 16'lık grup yoktur çünkü sıfırlar vardır. Sonra 8'liklere bakılır: $I=1$ olan iki satır bir 8'lik, $E=1$ olan iki sütun bir 8'lik grup oluşturur. Açıkta yalnız $0110$ hücresi ($E=0,A=1,B=1,I=0$) kalır. Daha önce gruplanmış birler daha büyük grup almaya yardım ettiği için bu hücre $A=1,B=1$ dörtlüsüne alınır. Üç grup vardır:

$$F = I + E + AB$$

(python ile doğruluk tablosu üzerinden doğrulandı.) Ekrandaki anahtarda sonuç "$I + E\,AB$" gibi görünüyor; derste anlatılan üç grup $I$, $E$ ve $AB$'dir.

### 1.4 Prefix ve postfix

İfade $\sqrt[3]{(a^2 * b^2 - c^2)}/a$ biçimindedir; kök işlemi için üs alma ($\uparrow$, $1/3$ üssü) kullanılacaktır.

Hoca derste ifadeyi şu sırayla okudu: önce $a^2$, sonra $b^2$ alınır, ikisi çarpılır, $c^2$ çıkarılır, sonuç $a$'ya bölünür ve en son küp kökü alınır. Bu okumayla ekranda yazdığı prefix (ekrandan, 00:20:00):

$$\uparrow\ /\ -\ *\ \uparrow a\,2\ \uparrow b\,2\ \uparrow c\,2\ a\ /\ 1\,3$$

Sözlü verdiği postfix (00:20:50):

$$a\,2\uparrow\ b\,2\uparrow\ *\ c\,2\uparrow\ -\ a\ /\ 1\,3\ /\ \uparrow$$

Ekrandaki cevap anahtarında ise kök yalnız parantezin içine uygulanmış, bölme en son yapılmıştır (ekrandan, 00:15:00):

- Prefix: $/\ \uparrow\ -\ *\ \uparrow a2\ \uparrow b2\ \uparrow c2\ /13\ a$
- Postfix: $a2\uparrow\ b2\uparrow\ *\ c2\uparrow\ -\ 13/\ \uparrow\ a\ /$

> **Ders sonrası not:** Soru metnindeki kök çizgisi yalnız $(a^2*b^2-c^2)$'yi kapsıyor; bu okumayla ifade $\left(a^2b^2-c^2\right)^{1/3}/a$'dır ve cevap anahtarındaki sıra doğrudur. Hocanın derste anlattığı sıra ise ifadeyi $\left((a^2b^2-c^2)/a\right)^{1/3}$ olarak okur. İki okuma farklı ifadelerdir; sınavda kök çizgisinin neyi kapsadığına dikkat edilmelidir.

<!-- BELİRSİZ: Hoca derste PowerPoint kalemiyle yazmayı denedi, kalem kaybolduğu için metin kutusu kullandı; sözlü anlatımda bazı adımlar karışık. Yukarıdaki iki dizilim karelerden alınmıştır. -->

### 1.5 Algoritma analizi

Kod ve satır satır işlem sayıları ekrandan alınmıştır (ekrandan, 00:25:00):

```c
void function(int n){
    int sayac = 0;                       // 1
    for (int i = n; i <= 2*n; i++)       // 1(=), 2(*,<=)*(n+2), (n+1)(++)
        for (int j = 1; j + n <= 2*n; ++j)   // (n+1)(=), 3*(+,<=,*)*((n+1)*(n+2)), (++j) n*(n+1)
            sayac++;                     // n*(n+1)(++)
}
// T(n) = 5n^2 + 12n + 10   O(n^2)
```

Hoca karşılaştırma sayısını bir örnekle gösterdi: $n=5$ için dış döngüde $i=5,6,\dots,10$ şartı sağlar, $i=11$'de çıkılır. $7$ karşılaştırma yapılır, yani $n+2$; artırma $n+1$ kez olur.

İç döngüde $j=1$ için $j+n=6\le10$, ..., $j=5$ için $10\le 10$ sağlanır; $j=6$'da $11\le10$ sağlanmaz. Hoca anlatırken kendi anahtarındaki iç döngü karşılaştırma frekansının $(n+1)(n+2)$ değil, $(n+1)(n+1)$ olması gerektiğini fark etti ve düzelteceğini söyledi (00:24:00). Bu tür küçük farkların yalnız sabiti ve küçük katsayıları etkilediğini, önemli olanın baskın terim olduğunu belirtti.

> **Ders sonrası not:** Satırlar düzeltilmiş frekanslarla toplanınca ($1 + 1 + 2(n+2) + (n+1) + (n+1) + 3(n+1)^2 + n(n+1) + n(n+1)$) $T(n)=5n^2+12n+11$ çıkar; python ile işlem sayılarak doğrulandı. Ekrandaki $5n^2+12n+10$ ile fark yalnız sabittedir; sonuç her iki durumda da $O(n^2)$'dir.

## 2. Öz Yinelemeli Bağıntılar ve İleri Yerine Koyma

Hoca bu konunun derse pandemi döneminde, online derslerde zaman arttığı için eklendiğini, biraz sıkıcı gelebileceğini ama bilgisayar bilimiyle uğraşanlar için çok önemli olduğunu söyledi. Önceki derslerde öz yinelemesiz ve öz yinelemeli algoritmalar gösterilmişti (faktöriyel örneği gibi); bu derste rekürans bağıntılarının nasıl yazıldığı, kullanıldığı ve çözüldüğü işlenir.

### 2.1 Tanım ve çözüm yöntemleri

Öz yinelemeli fonksiyon, $n$ bağımsız değişkenine göre ifade edilen ve $n$'nin önceki değerlerini içinde bulunduran fonksiyondur (ekrandan, 00:30:00):

$$T(n)=T(n-1)+1$$

$T(n)$ hesaplanırken fonksiyonun kendisinin bir önceki değeri kullanılır. Böyle bir fonksiyonun hesaplanabilmesi için bir başlangıç şartı da verilmelidir.

Çözüm yöntemleri (ekrandan, 00:30:00):

- Forward Substitution (ileri yerine koyma)
- Backward Substitution (geri yerine koyma)
- Recursive Tree Method (özyineleme ağacı)
- Master Theorem
- Karakteristik Denklem Yöntemi (2. veya yüksek dereceden bağıntılar için)

Derste önce ileri yerine koyma gösterildi.

### 2.2 İleri yerine koyma örneği

$T(n)=T(n-1)+1$, $T(1)=2$ verilmiş ve $T(5)$ isteniyor. $n=5$ konunca $T(5)=T(4)+1$ olur ama $T(4)$ bilinmez. Geriye doğru gidilir: $T(4)=T(3)+1$, $T(3)=T(2)+1$, $T(2)=T(1)+1$. $T(1)=2$ verilmiştir. Sonra ileri doğru yerine konur:

$$T(2)=3,\quad T(3)=4,\quad T(4)=5,\quad T(5)=6$$

Hoca farkı şöyle açıkladı: $t_n = n+1$ gibi bir dizi verilseydi $n$ yerine $5$ konur, doğrudan $6$ bulunurdu. Rekürans bağıntısı ise her zaman kendisinden oluşur; bu yüzden geri geri gidilerek işlem yapılır.

### 2.3 Gauss toplamı ve $f(n)=n+f(n-1)$

1'den $n$'ye kadar sayıların toplamı $\frac{n(n+1)}{2}$'dir. Gauss'un gerekçesi (ekrandan, 00:35:00): sayılar bir kez $1,2,\dots,n$ diye, bir kez de tersten $n,n-1,\dots,1$ diye yazılır ve alt alta toplanır. Her sütunun toplamı $n+1$'dir ve $n$ sütun vardır. İki sıra toplandığı için sonuç ikiye bölünür:

$$1+2+\dots+n=\frac{n(n+1)}{2}$$

Aynı toplam rekürans bağıntısıyla da yazılabilir:

$$f(n)=n+f(n-1),\qquad f(1)=1$$

$f(5)$ için: $f(5)=5+f(4)$, $f(4)=4+f(3)$, $f(3)=3+f(2)$, $f(2)=2+f(1)$, $f(1)=1$. Yerine konunca $f(2)=3$, $f(3)=6$, $f(4)=10$, $f(5)=15$ olur. Kontrol: $1+2+3+4+5=15$ ve formülle $\frac{5\cdot6}{2}=15$.

Hoca, bağıntının nereden geldiğini şöyle anlattı: $5$ alınır, kendisinden önceki $n-1$ elemanın toplamıyla toplanır; o da $4$ artı kendisinden öncekilerin toplamıdır, ve bu böyle $1$'e kadar gider. Bir bağıntıya bakarak böyle bir kapalı formülü çıkarmanın kolay olmadığını, bunun yavaş yavaş görüleceğini söyledi.

### 2.4 Faktöriyel

$4! = 4\cdot3\cdot2\cdot1$'dir. $n!$ hesaplanırken aslında $n$ bir şeyle çarpılır, o şey de $(n-1)!$'dir. Ekrandaki algoritma (ekrandan, 00:40:00):

```text
factorial(n):
    if n is 0
        return 1
    return n * factorial(n-1)
```

Rekürans bağıntısı $f(n)=n\cdot f(n-1)$, $f(0)=1$'dir. $f(4)$ çağrılınca $4\cdot f(3)$, o da $3\cdot f(2)$, $2\cdot f(1)$, $1\cdot f(0)$ diye iner; $f(0)=1$ döner ve dönüşte $1, 2, 6, 24$ diye çarpılarak $4!=24$ bulunur. Slayttaki işlem sayısı notu: factorial(0) yalnız $1$ karşılaştırma; factorial(n) ise $1$ karşılaştırma, $1$ çarpma, $1$ çıkarma, $(n-1)$ kez.

### 2.5 Açarak çözme örneği

Ardından $T(n)=T(n-1)+3$ biçiminde bir örnek açıldı. $n$ yerine $n-1$ konarak her adımda $3$ eklenir:

$$T(n)=T(n-1)+3=T(n-2)+6=T(n-3)+9=T(n-4)+12=\dots=T(n-k)+3k$$

$T(0)=1$ başlangıç değeri verildiğinde $k=n$ alınarak $T(n)=1+3n$ bulunur. Böylece $n$ ne olursa olsun bağıntı açılarak hesap yapılabilir.

<!-- BELİRSİZ: Bu örneğin slaytı karelerde yok; bağıntının biçimi ve T(0)=1 altyazıdan kuruldu. -->

## 3. Rekürans Bağıntısı ile Dizi Arasındaki Fark

Tanım (ekrandan, 00:45:00): Bir dizinin içinde kendisinden bir parça bulunuyorsa o diziye rekürans bağıntısı (öz yineli dizi) denir.

- $a_n=5n+1$ bir dizidir (sequence); içinde kendisinden parça yoktur. $n=20$ konunca doğrudan $a_{20}=101$ bulunur.
- $a_n=2a_{n-1}+3$ bir rekürans bağıntısıdır; $a_{n-1}$ kendisinden bir parçadır. $n\ge1$ ve $a_0=3$ ise $a_1=2\cdot3+3=9$.
- $a_n=a_{n-1}-2a_{n-2}+5^n$ ve $a_n=3a_{n-1}+2a_{n-2}$ de rekürans bağıntısıdır. İki geri terim içerdikleri için $n\ge2$ olmalı ve iki başlangıç değeri ($a_0$ ve $a_1$) verilmelidir; $a_2$ hesaplanırken $a_1$ ve $a_0$ gerekir.

Bir dizide $a_{99}=5\cdot 99+1$ doğrudan bulunur. Rekürans bağıntısında ise $a_{99}$ için $a_{98}$, onun için $a_{97}$ gerekir; $a_0$'a kadar inilir, sonra geri dönülerek her biri yerine konur.

Bir başka örnekte iki başlangıç değeriyle $a_2$ ve $a_3$ hesaplandı: $a_n=2a_{n-1}-a_{n-2}+2^{n-1}$ için $a_2 = 2a_1 - a_0 + 2^1 = 5$ ve $a_3 = 2a_2 - a_1 + 2^2 = 2\cdot5-2+4 = 12$.

<!-- BELİRSİZ: Bu örneğin slaytı karelerde yok; a_1=2 altyazıda geçiyor, a_0=1 değeri a_2=5 sonucundan geri hesaplandı. -->

### 3.1 Ayrık matematikteki iki hedef

1. Verilen bir rekürans bağıntısını çözmek.
2. Doğal dilde verilen bir problemi rekürans bağıntısı olarak modellemek ve sonra çözmek. Hoca bu ikinci kısmın daha zor olduğunu söyledi.

## 4. Rekürans Bağıntılarının Sınıflandırılması

### 4.1 Derece (order)

$a_n$'nin kendisinden önceki kaç terime bağlı olduğu, yani kendisinden türetilmiş terimler içinde en büyük geri indis bağıntının derecesini verir (ekrandan, 00:50:00):

| Bağıntı | Derece |
|---|---|
| $a_n=5a_{n-1}+n^2$ | 1 (first order) |
| $a_n=3a_{n-1}-5a_{n-2}$ | 2 (second order) |
| $a_n=3a_{n-1}+a_{n-3}+3^n$ | 3 (third order) |
| $a_n=2a_{n-4}+1$ | 4 |

Üçüncü bağıntıda $a_{n-2}$'nin katsayısı $0$ olduğu için yazılmamıştır; dördüncüde $a_{n-1}, a_{n-2}, a_{n-3}$'ün katsayıları $0$'dır.

### 4.2 Homojenlik

Bağıntıdaki bütün terimler kendisinden türetilmişse ($a$'lı terimlerse) bağıntı homojendir. Kendisinden türetilmemiş bir terim, yani bir sabit sayı ya da $n$'ye bağlı bir ifade ($n^2$, $n^3$ gibi) varsa homojen değildir.

### 4.3 Lineerlik

$a_n$'li terimlerin üssünün alınması ya da birbirleriyle çarpılması lineerliği bozar (ekrandan, 00:55:00):

| Bağıntı | Lineer mi? |
|---|---|
| $a_n=5a_{n-2}+n\cdot a_{n-3}+n^2$ | Evet |
| $a_n=(a_{n-1})^2+3n$ | Hayır |
| $(a_n)^3=a_{n-1}+a_{n-2}$ | Hayır |
| $a_n=(a_{n-1})(a_{n-2})-3$ | Hayır |

Hoca ilk bağıntıda önce $n\cdot a_{n-3}$ yüzünden lineerliğin bozulduğunu söyledi, sonra düzeltti: lineerliği bozan üs alma ve $a$'lı terimlerin birbiriyle çarpılmasıdır; $n$ ile çarpılma lineerliği bozmaz. Bu bağıntı lineerdir ama $n^2$ terimi yüzünden homojen değildir ve derecesi $3$'tür.

### 4.4 Sabit katsayılı olan ve olmayan

$a_n$'li ifadeler $n$'li bir şeyle çarpım durumundaysa bağıntı sabit katsayılı değildir (ekrandan, 00:55:00):

| Bağıntı | Sabit katsayılı mı? |
|---|---|
| $a_n=3a_{n-1}+5a_{n-2}+n-7$ | Evet (homojen değil, lineer) |
| $a_n=n\cdot a_{n-1}+3a_{n-2}+5^n$ | Hayır (homojen değil, lineer) |
| $a_n=7a_{n-1}+10a_{n-2}$ | Evet |
| $a_n=3^n\cdot a_{n-2}+1$ | Hayır |

## 5. Sabit Katsayılı Homojen Bağıntılar: Karakteristik Kök Yöntemi

Sabit katsayılı homojen bir bağıntı karakteristik kök tekniğiyle çözülür. Teknik ikinci ve daha yüksek dereceden bağıntılarda kullanılır; homojen olmayan bağıntılarda da homojen kısmın çözümü için kullanılır.

### 5.1 Homojen ve homojen olmayan durumda çözümün biçimi

Örnek: $a_n=3a_{n-1}+4a_{n-2}$, sabit katsayılı homojen 2. dereceden bir bağıntıdır (ekrandan, 01:00:00).

- Homojense: $a_n=a_n^{(h)}$ (h: homojen).
- Homojen değilse: $a_n=a_n^{(h)}+a_n^{(\text{ö})}$ (ö: özel, homojen olmayan kısmın çözümü).

### 5.2 Karakteristik denklem

En küçük indisli terime $1$, bir üstüne $r$, en büyük indisliye $r^2$ yazılır (ekrandan, 01:10:00):

$$a_{n-2}=1,\quad a_{n-1}=r,\quad a_n=r^2$$

Üçüncü dereceden bir bağıntıda $a_{n-3}=1$, $a_{n-2}=r$, $a_{n-1}=r^2$, $a_n=r^3$ olur. Örnek için:

$$r^2=3r+4 \;\Rightarrow\; r^2-3r-4=0$$

Bu karakteristik denklemdir. Çarpımı $-4$, toplamı $3$ olan sayılar $4$ ve $-1$'dir; kökler $r_1=4$, $r_2=-1$.

### 5.3 Köklere göre homojen çözüm

- Kökler farklıysa: $a_n^{(h)}=c_1r_1^n+c_2r_2^n$.
- Kökler çakışıksa ($r_1=r_2=r$): $a_n^{(h)}=c_1r^n+c_2\,n\,r^n$. Tek fark ikinci terimdeki $n$ çarpanıdır.

Örnekte kökler farklı olduğu için $a_n^{(h)}=c_1 4^n+c_2(-1)^n$. Sonra $c_1$ ve $c_2$ başlangıç değerlerinden bulunur.

Daha yüksek derecede de mantık aynıdır. Üç kök de farklıysa $c_1r_1^n+c_2r_2^n+c_3r_3^n$; dördüncü dereceden ve hepsi farklıysa $+c_4r_4^n$ eklenir. Hepsi aynıysa ikinci terim $n$, üçüncü $n^2$, dördüncü $n^3$ çarpanı alır: $c_1r^n+c_2nr^n+c_3n^2r^n+c_4n^3r^n$. İkisi aynı ikisi farklı gibi karışık durumlarda yalnız çakışan köklere $n$ çarpanları gelir. Hoca derste üçüncü ve dördüncü dereceden çözüm yapılmayacağını, iş çok uzadığı için nasıl yapıldığını bilmenin yeterli olduğunu söyledi.

### 5.4 Örnek: farklı kökler

$a_n=3a_{n-1}+10a_{n-2}$, $a_0=5$, $a_1=8$ (ekrandan, 01:15:00).

Bağıntı ikinci dereceden ve homojendir; bu yüzden $a_0$ ve $a_1$ verilmiştir.

1. Karakteristik denklem: $r^2=3r+10 \Rightarrow r^2-3r-10=0$. Çarpımı $-10$, toplamı $3$ olan sayılar: $r_1=5$, $r_2=-2$.
2. Kökler farklı: $a_n=c_1 5^n+c_2(-2)^n$.
3. $n=0$: $c_1+c_2=5$.
4. $n=1$: $5c_1-2c_2=8$.
5. Çözüm: $2c_1+2c_2=10$ ile toplanınca $7c_1=18$, $c_1=\frac{18}{7}$, $c_2=\frac{17}{7}$.

$$a_n=\frac{18}{7}\,5^n+\frac{17}{7}\,(-2)^n$$

(python ile ilk terimler bağıntıyla karşılaştırılarak doğrulandı: $5, 8, 74, 302, \dots$)

Artık $a_{10}$ istendiğinde $a_9, a_8, \dots$ hesaplanmaz; $n$ yerine $10$ konur. $n=999$ bile doğrudan hesaplanabilir. Bağıntı çözülerek kendisine bağımlı yazılmaktan kurtarılmış olur.

### 5.5 Örnek: çakışık kökler

$a_n=-4a_{n-1}-4a_{n-2}$, $a_0=3$, $a_1=5$ (ekrandan, 01:20:00).

1. Karakteristik denklem: $r^2+4r+4=0 \Rightarrow (r+2)^2=0$, $r_1=r_2=-2$.
2. Çakışık kökler: $a_n=c_1(-2)^n+c_2\,n\,(-2)^n$.
3. $n=0$: ikinci terim $0$ olur, $c_1=3$.
4. $n=1$: $-2c_1-2c_2=5 \Rightarrow -6-2c_2=5 \Rightarrow c_2=-\frac{11}{2}$.

$$a_n=3(-2)^n-\frac{11}{2}\,n\,(-2)^n$$

(python ile doğrulandı; altyazıda $c_2$ değeri yarım kalıyor, $-\frac{11}{2}$ hesapla bulunmuştur.)

Hoca, rekürsif olarak verilmiş bir bağıntıda $a_{30}$ için $a_{29}, a_{28}, \dots, a_2$'ye kadar bütün terimlerin bulunması gerektiğini; çözülmüş biçimde ise yalnız $n$ yerine $30$ konduğunu tekrar vurguladı.

## 6. Homojen Olmayan Bağıntılar ve Özel Çözüm

Homojenliği bozan kısım bir $f(n)$ fonksiyonu olarak görülür. Bu bir polinom olabilir: sabit ($3$ gibi, sıfırıncı derece), birinci derece ($n+2$), ikinci derece ($n^2$). Ya da üstel bir fonksiyon olabilir: $3\cdot2^n$, $5^n$, $7^{-n}$ gibi.

Genel çözüm:

$$a_n^{(g)}=a_n^{(h)}+a_n^{(\text{ö})}$$

Önce homojen kısım çözülür, sonra özel çözüm tahmin edilerek bulunur, ikisi toplanır, en son $c_1$ ve $c_2$ başlangıç koşullarından bulunur.

### 6.1 Polinom durumu: sabit $f(n)$

$a_n=2a_{n-1}+3a_{n-2}+5$, $a_0=4$, $a_1=10$ (ekrandan, 01:25:00 ve 01:30:00).

1. Homojen kısım: $r^2=2r+3 \Rightarrow r^2-2r-3=0$, $r_1=3$, $r_2=-1$. $a_n^{(h)}=c_13^n+c_2(-1)^n$.
2. Özel çözüm tahmini. Ekrandaki not: polinomun derecesi ne ise $a_n$'nin de derecesi aynı olur; $f(n)$ sabit olduğundan tüm terimler sabite eşit olur. $a_n^{(\text{ö})}=A$, $a_{n-1}=A$, $a_{n-2}=A$. Amaç tahmindeki katsayıyı bulmaktır.
3. $A=2A+3A+5 \Rightarrow -4A=5 \Rightarrow A=-\frac54$.
4. Genel çözüm: $a_n=c_13^n+c_2(-1)^n-\frac54$.
5. $n=0$: $c_1+c_2-\frac54=4 \Rightarrow c_1+c_2=\frac{21}{4}$.
6. $n=1$: $3c_1-c_2-\frac54=10 \Rightarrow 3c_1-c_2=\frac{45}{4}$.
7. Toplanınca $4c_1=\frac{66}{4}=\frac{33}{2}$, $c_1=\frac{33}{8}$, $c_2=\frac98$.

$$a_n=\frac{33}{8}\,3^n+\frac98\,(-1)^n-\frac54$$

(python ile doğrulandı: $4, 10, 37, 109, \dots$)

> **Hocanın vurgusu:** $c_1$ ve $c_2$, homojen çözüme özel çözüm eklendikten sonra bulunur; başlangıç denklemlerinde özel çözüm terimi ($-\frac54$) de yer alır.

### 6.2 Polinom durumu: birinci dereceden $f(n)$

$a_n=a_{n-1}+2a_{n-2}+3n+4$, $a_0=5$, $a_1=7$ (ekrandan, 01:35:00).

1. Homojen kısım: $r^2=r+2 \Rightarrow (r-2)(r+1)=0$, $r_1=2$, $r_2=-1$. $a_n^{(h)}=c_12^n+c_2(-1)^n$.
2. $f(n)=3n+4$ birinci dereceden bir polinomdur; özel çözüm de birinci dereceden polinom alınır: $a_n^{(\text{ö})}=An+B$.
3. $n$ yerine $n-1$ ve $n-2$ konur: $a_{n-1}=A(n-1)+B=An-A+B$, $a_{n-2}=A(n-2)+B=An-2A+B$.
4. Yerine koyma: $An+B=(An-A+B)+2(An-2A+B)+3n+4$.
5. Sadeleştirme (ekrandaki gibi): $-2An+5A-2B=3n+4$.
6. $n$'nin katsayıları: $-2A=3 \Rightarrow A=-\frac32$. Sabitler: $5A-2B=4 \Rightarrow -\frac{15}{2}-2B=4 \Rightarrow B=-\frac{23}{4}$.
7. $a_n^{(\text{ö})}=-\frac32 n-\frac{23}{4}$.

Bir öğrenci $a_{n-1}$ yazılırken $n$ yerine $n-1$ konup konmadığını sordu; hoca doğruladı: $An+B$ ifadesinde $n$ yerine $n-1$ konup $A$ dağıtılınca $An-A+B$ çıkar.

Hoca $c_1$ ve $c_2$'yi aynı adımların tekrarı olduğu için derste hesaplamadı.

> **Çözüm (derste verilmedi):** $a_n=c_12^n+c_2(-1)^n-\frac32n-\frac{23}{4}$. $n=0$: $c_1+c_2=\frac{43}{4}$. $n=1$: $2c_1-c_2=\frac{57}{4}$. Buradan $c_1=\frac{25}{3}$, $c_2=\frac{29}{12}$. Sonuç $a_n=\frac{25}{3}2^n+\frac{29}{12}(-1)^n-\frac32n-\frac{23}{4}$ (python ile ilk terimler $5, 7, 27, 54, 124$ olarak doğrulandı).

### 6.3 Üstel fonksiyon durumu

$a_n=-4a_{n-1}-3a_{n-2}+2\cdot5^n$, $a_0=6$, $a_1=10$ (ekrandan, 01:40:00).

1. Homojen kısım: $r^2=-4r-3 \Rightarrow r^2+4r+3=0 \Rightarrow (r+3)(r+1)=0$, $r=-3$, $r=-1$. $a_n^{(h)}=c_1(-3)^n+c_2(-1)^n$.
2. Çakışma kontrolü: $5^n$, $a_n^{(h)}$'nin içinde var mı? Yok.

Ekrandaki kural (ekrandan, 01:40:00):

- Üstel terim homojen çözümde yoksa özel çözüm doğrudan $A\cdot k^n$ alınır.
- Bir tane varsa (bir kökle çakışıyorsa) $a_n^{(\text{ö})}$'ye $n$ çarpanı gelir.
- İki tane varsa (iki kökle çakışıyorsa) $n^2$ çarpanı gelir. Üç kökle çakışsaydı $n^3$ ile çarpılırdı.

3. Özel çözüm: $a_n^{(\text{ö})}=A\cdot5^n$. $a_{n-1}=A\cdot5^{n-1}=\frac{A}{5}5^n$, $a_{n-2}=\frac{A}{25}5^n$.
4. $A\cdot5^n=-4\cdot\frac{A}{5}5^n-3\cdot\frac{A}{25}5^n+2\cdot5^n \Rightarrow A\left(1+\frac45+\frac{3}{25}\right)=2 \Rightarrow A=\frac{25}{24}$ (ara adım eklendi).
5. $a_n^{(\text{ö})}=\frac{25}{24}5^n$. Sonra $n=0$ için $6$'ya, $n=1$ için $10$'a eşitlenerek $c_1$, $c_2$ bulunur.

> **Çözüm (derste verilmedi):** $c_1+c_2=6-\frac{25}{24}=\frac{119}{24}$ ve $-3c_1-c_2=10-\frac{125}{24}=\frac{115}{24}$. Buradan $c_1=-\frac{39}{8}$, $c_2=\frac{59}{6}$; $a_n=-\frac{39}{8}(-3)^n+\frac{59}{6}(-1)^n+\frac{25}{24}5^n$ (python ile doğrulandı). Hoca katsayıları ekranda bulunmuş olarak gösterdi ama değerler karelerde görünmüyor.

### 6.4 Üstel terim bir kökle çakışırsa

$a_n=2a_{n-1}+3a_{n-2}+3^n$, $a_0=7$, $a_1=5$ (ekrandan, 01:45:00).

1. Homojen kısım: $r^2-2r-3=0 \Rightarrow (r-3)(r+1)=0$, $r=3$, $r=-1$. $a_n^{(h)}=c_13^n+c_2(-1)^n$.
2. $3^n$ terimi homojen çözümde bir kez var ($c_13^n$). Bu yüzden özel çözüm $n$ ile çarpılır: $a_n^{(\text{ö})}=A\cdot3^n\cdot n$. İkisi de $3^n$ olsaydı $n^2$ ile çarpılırdı.
3. $a_{n-1}=A\,3^{n-1}(n-1)=\frac{A}{3}3^n n-\frac{A}{3}3^n$, $a_{n-2}=A\,3^{n-2}(n-2)=\frac{A}{9}3^n n-\frac{2A}{9}3^n$.
4. Yerine koyma: $A\,3^n n=\frac{2A}{3}3^n n-\frac{2A}{3}3^n+\frac{A}{3}3^n n-\frac{2A}{3}3^n+3^n$.
5. $n$'li terimler sadeleşir ($\frac{2A}{3}+\frac{A}{3}=A$); geriye $\frac{4A}{3}3^n=3^n$ kalır, $A=\frac34$.
6. $a_n^{(\text{ö})}=\frac34\,n\,3^n$. Sonra $n=0$ için $7$'ye, $n=1$ için $5$'e eşitlenerek $c_1$, $c_2$ bulunur.

> **Çözüm (derste verilmedi):** $c_1+c_2=7$ ve $3c_1-c_2+\frac94=5$. Buradan $c_1=\frac{39}{16}$, $c_2=\frac{73}{16}$; $a_n=\frac{39}{16}3^n+\frac{73}{16}(-1)^n+\frac34n3^n$ (python ile doğrulandı).

## 7. Sayı Dizilerini ve Sözel Problemleri Rekürans Bağıntısına Dönüştürme

Bazen bir sayı dizisi ya da sözel bir ifade verilir ve olayın bir sayı dizisi formunda yazılması beklenir (ekrandan, 02:05:00). Hoca bunu eskiden üniversite sınavlarındaki genel yetenek sorularına benzetti: "bu dizide sonraki sayı nedir?" Bir örüntü aranır; neyle ne yapılınca sonraki terimin bulunduğu çıkarılır. Bazen kolaydır, bazen çok zorlar, bazen de bulunamaz; bulunacak diye bir kural yoktur.

### 7.1 $4, 7, 13, 25, 49, 97, \dots$

Bir terim $2$ ile çarpılıp $1$ çıkarılınca sonraki bulunur: $4\cdot2-1=7$, $7\cdot2-1=13$, $13\cdot2-1=25$. Bağıntı (ekrandan, 02:05:00):

$$a_0=4,\qquad a_n=2a_{n-1}-1,\quad n\ge1$$

Kontrol: $a_1=2a_0-1=7$.

Bağıntı bulundu ama $50$. terim sorulursa yine bütün terimler tek tek hesaplanmalıdır. Bu yüzden bağıntı çözülür. Homojen değildir (sıfırıncı dereceden polinom $-1$ var). Özel kısım için $a_n=a_{n-1}=A$ konur: $A=2A-1$, $A=1$. Sonra homojen çözüme eklenir ve $n=0$ için $4$'e eşitlenerek $c_1$ bulunur.

> **Ders sonrası not:** Altyazıda homojen kısmın karakteristik denklemi "$r-1=0$, $r=1$" olarak geçiyor. $a_n=2a_{n-1}$ için karakteristik denklem $r-2=0$, kök $r=2$'dir; büyük olasılıkla bir söyleyiş ya da çeviri hatasıdır. Doğru çözüm $a_n^{(h)}=c_12^n$, $a_n^{(\text{ö})}=1$, $a_0=4 \Rightarrow c_1=3$, yani $a_n=3\cdot2^n+1$ (python ile $4,7,13,25,49,97$ olarak doğrulandı; kapalı formül derste yazılmadı).

<!-- BELİRSİZ: 02:06 civarında karakteristik denklemin ve kökün tam söylenişi altyazıdan net değil. -->

### 7.2 $1, 3, 7, 17, 41, 99, 239, \dots$

Hoca önce şunu denedi: $1+3=4$, $4+3=7$; $3+7=10$, $10+7=17$; yani iki terimi topla, sonra öncekini bir kez daha ekle. $41$, $99$, $239$ da bu yolla tuttu. Ekrandaki çözüm ise $a_n=2a_{n-1}+a_{n-2}$ idi.

**Soru:** Bu ikisi aynı şey değil mi? $3$'ü iki kez topluyoruz, bu $2$ ile çarpmak demek. **Cevap:** Evet, aynı şey. $a_{n-1}+a_{n-2}$ toplanıp bir kez daha $a_{n-1}$ eklenince iki tane $a_{n-1}$ olur, yani $2a_{n-1}+a_{n-2}$. Hoca farklı yoldan da aynı sonuca gidilebileceğini belirtti.

$$a_0=1,\quad a_1=3,\qquad a_n=2a_{n-1}+a_{n-2},\quad n\ge2$$

(ekrandan, 02:10:00.) Bağıntı ikinci dereceden ve homojendir; özel çözümü yoktur, yalnız homojen yöntemle çözülür.

### 7.3 Homojen olmayan bir dizi örneği

Yeni bir dizide hoca önce birkaç deneme yaptı (toplayıp $2$ eklemek, çarpıp eklemek) ve tutmadığını gösterdi: "Böyle deniyorsun, şanslıysan buluyorsun." Ekrandaki çözümde ardışık iki terim toplanıp $2$'nin bir kuvveti ekleniyor: $1+3+2^1=6$, $3+6+2^2=13$, $6+13+2^3=27$. Üs, bulunan terimin indisine göre belirlenir: $a_2$ için $2^1$, $a_3$ için $2^2$, $a_4$ için $2^3$; yani $2^{n-1}$:

$$a_n=a_{n-1}+a_{n-2}+2^{n-1}$$

Homojen kısım karakteristik denklemle, $2^n$'li kısım ise üstel özel çözümle çözülür ($2^{n-1}=\frac12 2^n$). Özel çözüm yazılırken $2^n$'nin homojen çözüm kökleriyle çakışıp çakışmadığına bakılır. Hoca bu çözümü ayrıca yapmadı.

<!-- BELİRSİZ: Bu dizinin slaytı karelerde yok; terimler (1, 3, 6, 13, 27) altyazıdan kuruldu, altyazıda "26, 27" diye geçiyor. -->

### 7.4 Sözel problem: "00" içeren 0-1 dizileri

Soru (ekrandan, 02:15:00): Sadece $0$ ve $1$'lerden oluşan $n$ birim uzunluğunda sayı dizileri oluşturuluyor. Bu sayı dizilerinden $n$ uzunluğunda olup "00" içerenlerin sayısını veren rekürans bağıntısını başlangıç koşullarını da belirterek yazınız.

Hoca, $n=16$ gibi büyük bir değerle $2^{16}$ dizi yazmak yerine küçük değerlerden başladı (ekrandan, 02:15:00):

| $n$ | Diziler | "00" içerenler | $a_n$ |
|---|---|---|---|
| 0 | dizi yok | — | 0 |
| 1 | 0, 1 | — | 0 |
| 2 | 00, 01, 10, 11 | 00 | 1 |
| 3 | 8 dizi | 000, 001, 100 | 3 |
| 4 | 16 dizi | 0000, 0001, 0010, 0100, 1000, 0011, 1001, 1100 | 8 |

**Soru:** $0000$ dizisinde iki tane "00" var, neden iki sayılmadı? **Cevap:** Soru "00" çiftlerinin adedini değil, içinde ardışık iki sıfır bulunan dizilerin sayısını soruyor; $0000$ bir dizidir ve bir kez sayılır.

Dizi $0, 0, 1, 3, 8, \dots$ olarak çıktı. İlk iki terim başlangıç koşulu gibi düşünüldü. Hoca önce "iki terimi topla, $1$ ekle" denedi, tutmadı. Sonra "bir önceki terimi $2$ ile çarp, ondan önceki terimi ve $1$ ekle" denedi: $2\cdot0+0+1=1$, $2\cdot1+0+1=3$, $2\cdot3+1+1=8$. Bağıntı (ekrandan, 02:15:00):

$$a_n=2a_{n-1}+a_{n-2}+1,\quad n\ge2,\qquad a_0=0,\; a_1=0$$

Bağıntı homojen değildir (sabit $1$). Özel çözüm için $A=2A+A+1$ yazılır; homojen kısım da çözülüp özel kısım eklenince $n$'ye bağlı formül elde edilir. Bundan sonra $n=50$ için $2^{50}$ dizi yazmadan sonuç bulunabilir.

> **Ders sonrası not:** Hocanın bağıntısı $a_5=2\cdot8+3+1=20$ verir, ama $5$ bitlik dizilerde "00" içerenlerin gerçek sayısı $19$'dur (python ile bütün diziler sayıldı: $0,0,1,3,8,19,43,94,\dots$). İlk beş terime uyan bir bağıntı her zaman doğru bağıntı değildir. Doğru bağıntı, dizinin ilk bitine bakarak kurulur: ilk bit $1$ ise geri kalan $n-1$ bitte "00" olmalıdır ($a_{n-1}$); ilk iki bit $01$ ise geri kalan $n-2$ bitte olmalıdır ($a_{n-2}$); ilk iki bit $00$ ise geri kalan $n-2$ bit serbesttir ($2^{n-2}$). Buradan $a_n=a_{n-1}+a_{n-2}+2^{n-2}$, $n\ge2$, $a_0=a_1=0$ çıkar.

Hoca bu tür problemlerde asıl önemli olanın rekürans bağıntısını yazabilmek olduğunu, bunun her zaman hızlı ve kolay çıkmayabileceğini, bakış açısının kişiden kişiye değiştiğini söyledi.

## 8. Problemlerin Karmaşıklık Sınıfları

Konunun sonundaki slaytlar yalnız terim olarak verildi; ayrıntısının algoritma analizi dersinde görüleceği söylendi.

- **Tractable (çözülebilir) problem:** en kötü durumda polinom zaman karmaşıklığına sahip bir algoritmayla çözülebilen problem.
- **Intractable (çözülemez) problem:** en kötü durumda polinom zaman karmaşıklığına sahip bir algoritmayla çözülemeyen problem (ekrandan, 02:25:00). Böyle bir problemin çözümü küçük girdilerle bile genellikle aşırı zaman isteyebilir. Ancak pratikte bazı algoritmalar birçok durumda en kötü durumundan çok daha hızlı çalışır; endüstride çözülemez sayılan birçok problem, günlük hayatın getirdiği girdiler için çözülebilir. Bir başka yol, kesin çözüm yerine yaklaşık çözüm aramaktır.
- Hoca bunu şöyle örnekledi: bir problemin her durumu çözülemiyor olabilir, ama küçük bir örneklem ya da özel bir durum (örneğin yalnız çift sayılar) alınınca çözülebilir hale gelebilir.
- **Unsolvable problemler:** çözümü hiç bulunamayan, eldeki donanım imkânlarıyla şu an çözülemeyen problemler.
- P ve NP sınıfları (polinom zamanda ve polinom olmayan zamanda çözülenler) ve NP-tam (NP-complete) problemler terim olarak anıldı.

## Örnek Sorular

**Soru 1** (ekrandan, 00:10:00): $R=\{(x,y)\in\mathbb{Z} \mid xy\ge1\}$ şartını sağlayan bir bağıntı için aşağıdaki özelliklerden hangileri vardır veya yoktur? Sebebi ile yazınız: Reflexive, Irreflexive, Nonreflexive, Symmetric, Antisymmetric, Transitive.

> **Çözüm (derste verildi):** Refleksif değil ($(0,0)$ yok); irrefleksif değil ($(1,1)$ var); nonrefleksif; simetrik ($xy=yx$); antisimetrik değil ($(1,2)$ ve $(2,1)$); geçişli. (python ile $-6..6$ aralığında kontrol edildi.)

**Soru 2** (ekrandan, 00:10:00): $S=\{0,2,5,10,11,15\}$ kümesi için $x\le y$ şartını sağlayan bağıntının HASSE diyagramı çizilebilir mi? Neden? Çizilebiliyorsa çiziniz.

> **Çözüm (derste verildi):** Refleksif, antisimetrik ve geçişli olduğu için sıralama bağıntısıdır; Hasse diyagramı çizilir. Refleksif ve geçişlilik kenarları koparıldığında $0-2-5-10-11-15$ zinciri kalır.

**Soru 3** (ekrandan, 00:10:00): Bir kişinin bankadan kredi alabilmesi için sırası ile evi ($E$), arabası ($A$), bankada belli bir miktarın üzeri parası ($B$) ve iş yeri sahibi ($I$) olup olmadığı konularında sorular sorulmaktadır. Kredi verme işlemini hızlandırmak için iki kural belirlenmiştir:

- Kredi alacak kişinin kendi üzerine kayıtlı en az bir evi veya iş yeri sahibi olmalıdır.
- Kredi alacak kişi ev veya iş yeri sahibi değilse hem bankada parası hem de arabası olmalıdır.

Bu şartlar için gerekli olan doğruluk tablosunu oluşturunuz ve $F(E,A,B,I)$ fonksiyonunu mintermler cinsinden yazdıktan sonra Karnaugh diyagramlarını kullanarak basitleştirilmiş fonksiyonu çıkarınız.

> **Çözüm (derste verildi):** $F=\sum m(1,3,5,6,7,8,9,10,11,12,13,14,15)$; iki 8'li ve bir 4'lü grupla $F=I+E+AB$ (Bölüm 1.3).

**Soru 4** (ekrandan, 00:10:00): $\sqrt[3]{(a^2*b^2-c^2)}/a$ ifadesinin postfix ve prefix halini yazınız. Kök işlemi için üs alma işlemini kullanınız. Stack ile adım adım sonuç yazmayınız.

> **Çözüm (derste verildi):** Cevap anahtarı (kök yalnız parantezin içinde): prefix $/\uparrow-*\uparrow a2\uparrow b2\uparrow c2/13\,a$, postfix $a2\uparrow b2\uparrow*c2\uparrow-13/\uparrow a/$. Hocanın derste kökü bütün ifadeye uygulayarak yazdığı dizilimler Bölüm 1.4'tedir.

**Soru 5** (ekrandan, 00:20:00 ve 00:25:00): Aşağıda verilen algoritmanın analizini yapınız. (1) Algoritmanın çalışma zamanı fonksiyonunu $T(n)$ tüm operasyonların frekansına göre belirleyiniz. (2) Elde ettiğiniz $T(n)$ fonksiyonunun Big O notasyonunu ifade ediniz. Kod Bölüm 1.5'tedir.

> **Çözüm (derste verildi):** Anahtarda $T(n)=5n^2+12n+10$, $O(n^2)$. İç döngü karşılaştırma frekansı $(n+1)(n+1)$ alınınca $T(n)=5n^2+12n+11$ çıkar; karmaşıklık değişmez.

**Soru 6** (ekrandan, 01:15:00): $a_n=3a_{n-1}+10a_{n-2}$, $a_0=5$ ve $a_1=8$ olan başlangıç değerleri verilmiş rekürans bağıntısını çözünüz.

> **Çözüm (derste verildi):** $a_n=\frac{18}{7}5^n+\frac{17}{7}(-2)^n$ (Bölüm 5.4).

**Soru 7** (ekrandan, 01:20:00): $a_n=-4a_{n-1}-4a_{n-2}$, $a_0=3$, $a_1=5$ başlangıç koşulları ile verilen rekürans bağıntısının çözümünü bulunuz.

> **Çözüm (derste verildi):** $a_n=3(-2)^n-\frac{11}{2}n(-2)^n$ (Bölüm 5.5).

**Soru 8** (ekrandan, 01:25:00): $a_n=2a_{n-1}+3a_{n-2}+5$, $a_0=4$, $a_1=10$ başlangıç koşulları ile verilen rekürans bağıntısını çözünüz.

> **Çözüm (derste verildi):** $a_n=\frac{33}{8}3^n+\frac98(-1)^n-\frac54$ (Bölüm 6.1).

**Soru 9** (ekrandan, 01:35:00): $a_n=a_{n-1}+2a_{n-2}+3n+4$, $a_0=5$, $a_1=7$ başlangıç koşulları ile verilen rekürans bağıntısını çözünüz.

> **Çözüm:** Özel çözüm derste $-\frac32n-\frac{23}{4}$ bulundu; katsayılar derste hesaplanmadı. Tam çözüm Bölüm 6.2'deki "derste verilmedi" bloğundadır.

**Soru 10** (ekrandan, 01:40:00): $a_n=-4a_{n-1}-3a_{n-2}+2\cdot5^n$, $a_0=6$, $a_1=10$ başlangıç koşulları ile verilen rekürans bağıntısını çözünüz.

> **Çözüm:** Özel çözüm derste $\frac{25}{24}5^n$ bulundu; tam çözüm Bölüm 6.3'teki "derste verilmedi" bloğundadır.

**Soru 11** (ekrandan, 01:45:00): $a_n=2a_{n-1}+3a_{n-2}+3^n$, $a_0=7$, $a_1=5$ başlangıç koşulları ile verilen rekürans bağıntısını çözünüz.

> **Çözüm:** Özel çözüm derste $\frac34n\,3^n$ bulundu; tam çözüm Bölüm 6.4'teki "derste verilmedi" bloğundadır.

**Soru 12** (ekrandan, 02:10:00): $1, 3, 7, 17, 41, 99, 239, \dots$ sayı dizisini rekürans bağıntısı olarak yazınız.

> **Çözüm (derste verildi):** $a_0=1$, $a_1=3$, $a_n=2a_{n-1}+a_{n-2}$, $n\ge2$.

**Soru 13** (ekrandan, 02:15:00): Sadece $0$ ve $1$'lerden oluşan $n$ birim uzunluğunda sayı dizileri oluşturuluyor. Buna göre bu sayı dizilerinden $n$ uzunluğunda olup "00" içerenlerin sayısını veren rekürans bağıntısını başlangıç koşullarını da belirterek yazınız.

> **Çözüm (derste verildi):** Derste $a_n=2a_{n-1}+a_{n-2}+1$, $a_0=a_1=0$ yazıldı. Bu bağıntı $n=5$'te hatalıdır; doğru bağıntı $a_n=a_{n-1}+a_{n-2}+2^{n-2}$, $n\ge2$, $a_0=a_1=0$'dır (Bölüm 7.4'teki ders sonrası not).

## Dersin Toparlaması

Ders, birinci vizenin sorularıyla başladı: tam sayılar üzerinde bir bağıntının özellikleri, sıralama bağıntısının Hasse diyagramı, kredi probleminin Karnaugh haritasıyla sadeleştirilmesi, bir ifadenin prefix ve postfix gösterimi ve iç içe döngülü bir algoritmanın işlem sayısı. Hasse diyagramının bağıntı grafından halkalar ve geçişli kenarlar silinerek elde edildiği ve irrefleksif ile nonrefleksif farkı özellikle vurgulandı.

Ardından yeni konu olan rekürans bağıntılarına geçildi. Rekürans bağıntısı içinde kendisinden bir parça bulunan dizidir; derece, homojenlik, lineerlik ve sabit katsayılılık bakımından sınıflandırılır. Sabit katsayılı homojen bağıntılar karakteristik denklemin kökleriyle (farklı ya da çakışık) çözülür; homojen olmayanlarda buna homojenliği bozan terimin biçimine göre tahmin edilen bir özel çözüm eklenir ve katsayılar en son başlangıç koşullarından bulunur. Amaç, $n$. terimi bütün ara terimleri hesaplamadan doğrudan veren bir formül elde etmektir. Son bölümde sayı dizilerinden ve sözel problemlerden rekürans bağıntısı kurma gösterildi ve tractable/intractable problem kavramları terim olarak tanıtıldı. Bir sonraki konu ağaçlar, ardından graflardır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
