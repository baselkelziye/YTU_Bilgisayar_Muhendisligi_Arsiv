# Ders 9 Çalışma Özeti

## Genel Konular

- Dersin tarihi 4 Aralık 2020 Cuma. Ders Zoom üzerinden yapıldı.
  - Bu ders vizeden sonraki ilk derstir. Vize 27 Kasım 2020'de (8. hafta) klasik olarak yapıldı.
  - Kaydın ilk yarım saati vize değerlendirmesidir. Yeni konu yaklaşık 00:28:15'te başlar.
  - Ders bir arayla iki bölüm. Ara yaklaşık 01:05-01:24 arasıdır.
- Vize değerlendirmesi: sorularda en çok yapılan hatalar.
  - Bağıntı sorusu, prefix/postfix sorusu, Karnaugh sorusu, karmaşıklık sorusu, önerme sorusu.
- Özyinelemeli (recursive) algoritmalar
  - Yinelemeli (iterative) ve özyinelemeli algoritmaların farkı.
  - Başlangıç koşulu (initial condition) ve ileri yerine koyma (forward substitution).
  - Örnekler: 1'den $n$'e kadar sayıların toplamı (Gauss), faktöriyel ve yürütme zamanı.
- Rekürans bağıntıları (recurrence relations, öz yineli diziler)
  - Tanım: içinde kendisinden bir parça bulunan dizi.
  - Sınıflandırma: derece (order), homojen/homojen olmayan, doğrusal/doğrusal olmayan, sabit katsayılı/sabit katsayılı olmayan.
  - Sabit katsayılı homojen rekürans bağıntılarının karakteristik kök yöntemiyle çözümü (ayrık ve çakışık kökler).
  - Sabit katsayılı homojen olmayan bağıntılar: homojen çözüm + özel çözüm. $f(n)$ sabit, polinom veya üstel olabilir.
  - Sözel problemlerden ve sayı dizilerinden rekürans bağıntısı çıkarma.
- Çözülebilir (tractable), çözülemez (intractable) ve çözümsüz (unsolvable) problemlere kısa giriş; durma problemi (halting problem), NP-complete ve NP-hard.

## Hocanın Özellikle Vurguladığı Kısımlar

- Vize sonuçları:
  - En yüksek not 95'tir; 100 alan yok.
  - Karnaugh sorusunun "sonucu Bool cebriyle ispatlayın" şıkkı iki grupta da iptal edildi. Çözümü hocalar için bile uzun sürdü.
  - Notlar kontrol edildikten sonra ilan edilecek.
- Klasik sınavda kâğıtlarınıza ad ve numara yazın. Dosyaya ad vermek yetmiyor; sistem indirirken dosya adlarını değiştirdi.
- Prefix/postfix sorusunda en çok yapılan hatalar:
  - Örtük çarpma işaretini unutmak. $(A+B)C$ ifadesinde araya çarpma işareti konmalıdır.
  - Kökü üs olarak yazmamak. $\sqrt[n]{x} = x^{1/n}$ olduğu için $1/n$ de prefix'e çevrilmelidir: $\uparrow x \, / \, 1 \, n$. "$x(1/n)$" gibi bir yazım olmaz.
  - Örnek: $\sqrt[3]{x^2} = x^{2/3}$, prefix'i $\uparrow x \, / \, 2\,3$.
- Bir hata herkesin kâğıdında aynı olmaz. Hoca prefix/postfix sorusunda kopya olduğunu düşündüğünü söyledi, ama üzerinde durmayacağını belirtti.
- Karnaugh sorusunda:
  - 4 giriş (kara yolu, demir yolu, deniz yolu, hava yolu) ve 1 çıkış ($F$) vardı.
  - Minterimler: $\Sigma(4, 8, 9, 10, 12, 14)$.
  - Karnaugh haritasını 90° döndürerek kuranlar farklı minterimler buldu.
  - Bir 1'i komşusuyla 2'li grup yapmak mümkünken tek başına almak, doğru sadeleştirme değildir.
- Karmaşıklık sorusunda çoğu öğrenci $O(n^3)$ buldu. Doğru cevap $O(n^2\log n)$'dir.
  - Bir değişken her adımda 2 ile çarpılıyor veya 2'ye bölünüyorsa o döngünün karmaşıklığı $\log n$'dir. İkili aramayı hatırlayın.
- "Ancak ve ancak" içeren cümle sembolle yazılırken $\leftrightarrow$ kullanılır, XOR değil.
- Rekürans bağıntılarında başlangıç değerleri mutlaka verilmelidir. Derece kaçsa o kadar başlangıç değeri gerekir.
- Rekürans bağıntılarını bu yıl ilk kez anlatıyorlar. Dersi daha önce alıp tekrar alanlara haber verin.
- Homojen olmayan bağıntıda $f(n)$ üstel ise mutlaka kontrol edin: $f(n)$'deki üstel terim homojen çözümde geçiyor mu?
  - Geçiyorsa özel çözüm $n$ ile, iki kez geçiyorsa $n^2$ ile çarpılır.
  - Hoca bu durumun öğrenciler tarafından en çok atlanan nokta olduğunu söyledi.
- Bir problemi rekürsif yazmak zahmetlidir. Matruşka bebekleri gibi kendini tekrar eden bir yapı varsa rekürsif yazılır.
- İkinci vize olup olmayacağı belli değil. Hoca, diğer grubun hocasıyla konuşup USİS üzerinden e-posta atacağını söyledi.

## Kısa Tekrar Notları

- Rekürans bağıntısı: $a_n$, kendinden önceki terimlere ($a_{n-1}, a_{n-2}, \dots$) bağlıdır. Dizi gibi $n$ yerine sayı koyarak doğrudan hesaplanmaz.
- Derece: en büyük geriye kayma. $a_n = a_{n-1} + a_{n-3}$ üçüncü derecedendir.
- Homojen: yalnız $a_{n-i}$ terimleri var. Sabit, $n^2$, $3^n$ gibi bir terim varsa homojen değil.
- Doğrusal değil: terimlerin kuvveti alınıyorsa ($a_{n-1}^2$) veya terimler birbiriyle çarpılıyorsa ($a_{n-1}a_{n-2}$).
- Sabit katsayılı değil: katsayıda $n$ veya $3^n$ gibi bir çarpan varsa ($n\,a_{n-1}$).
- Karakteristik denklem: $a_n = c_1 a_{n-1} + c_2 a_{n-2}$ için $r^2 = c_1 r + c_2$.
- Ayrık kökler $r_1 \ne r_2$: $a_n = C_1 r_1^n + C_2 r_2^n$.
- Çakışık kök $r$: $a_n = C_1 r^n + C_2\, n\, r^n$. Üç katlı kökte üçüncü terim $C_3\,n^2 r^n$ olur.
- Homojen olmayan: $a_n = a_n^{(h)} + a_n^{(ö)}$. Önce özel çözüm bulunur, sonra $C_1$, $C_2$ başlangıç değerleriyle hesaplanır.
- Özel çözüm tahmini:
  - $f(n)$ sabit: $a_n^{(ö)} = A$.
  - $f(n)$ birinci dereceden polinom: $a_n^{(ö)} = An + B$.
  - $f(n) = k\cdot s^n$: $a_n^{(ö)} = A s^n$. $s$ homojen çözümün kökü ise $A\,n\,s^n$.
- Faktöriyel: $T(n) = T(n-1) + 3$, $T(0) = 1$ ise $T(n) = 3n + 1$, karmaşıklık $O(n)$.

## Detaylı Açıklamalar

### Vize değerlendirmesi

**Prefix/postfix sorusu:** Postfix ifadede $n = 2$, $m = 1$ için iki sonuç istenmişti: 25 ve 432.
- 25'i çoğu öğrenci doğru buldu.
- İkinci ifadenin hesabı (derste bir öğrenciyle birlikte yapıldı): $n^2 = 4$, $n \cdot m = 2$, $4 + 2 = 6$, $6^3 = 216$, $216 \cdot 2 = 432$.
- Yanlış yapanların çoğu 532 bulmuştu.
- Sorunun bir şıkkında prefix ifadelerden birini yığın kullanarak değerlendirmek isteniyordu (5 puan). Çoğu öğrenci bunu yapmadı.
- Üs işleminde sıra: prefix'te $\uparrow 3\,2 = 3^2 = 9$, postfix'te $3\,2\uparrow = 3^2 = 9$. Sayıların yeri değişirse $2^3 = 8$ olur.

**Karnaugh sorusu:** Minterimler $\Sigma(4, 8, 9, 10, 12, 14)$. Değişken sırası $A, B, C, D$ ($A$ en anlamlı bit) alınırsa:
- 4'lü grup: $8, 10, 12, 14 \Rightarrow A\overline{D}$.
- 2'li grup: $8, 9 \Rightarrow A\overline{B}\,\overline{C}$.
- 2'li grup: $4, 12 \Rightarrow B\overline{C}\,\overline{D}$.
- Sonuç: $F = A\overline{D} + A\overline{B}\,\overline{C} + B\overline{C}\,\overline{D}$. Bu, en kısa çözümdür (Python ile bütün seçenekler denendi).

**Karmaşıklık sorusu** (tahta karesinden):

```c
for (i = n/2; i <= n; i++)          // yaklaşık n/2 kez
    for (j = 1; j + n/2 <= n; j++)  // n/2 kez
        for (k = 1; k <= n; k = k*2) // log2(n) + 1 kez
            ...
```

- İç döngüde $k$: $1, 2, 4, 8, \dots$ olur. $n = 10$ için $k = 16$'da durur. Tekrar sayısı $\log_2 n$ civarındadır.
- Toplam: $\frac{n}{2} \cdot \frac{n}{2} \cdot \log n = \frac{n^2}{4}\log n$.
- Karmaşıklık: $O(n^2\log n)$. $O(n^3)$ olması mümkün değil.

### Özyinelemeli algoritmalar

- Yinelemeli algoritmalarda bir giriş boyutu, temel işlemler, durum analizi ve $T(n)$ vardı.
- Özyinelemeli algoritma kendi kendini çağırır. Bir başlangıç (durma) koşulu mutlaka olmalıdır.
- Çağrılar yığına atılır. Durma noktasına ulaşınca yığından geri çekilerek sonuç bulunur.

**İleri yerine koyma (forward substitution):** $T(n) = T(n-1) + 1$, $T(1) = 2$.
- $T(2) = T(1) + 1 = 3$, $T(3) = T(2) + 1 = 4$, …
- Genel çözüm: $T(n) = n + 1$.

**Gauss'un toplamı:** Gauss, 1'den $n$'e kadar sayıları alt alta düz ve ters yazıp topladı.
- Her sütunun toplamı $n+1$, sütun sayısı $n$. Her sayı iki kez toplandığı için ikiye bölünür: $\dfrac{n(n+1)}{2}$.
- Rekürsif hali: $f(n) = n + f(n-1)$, $f(1) = 1$.
- $f(5) = 5 + f(4)$, $f(4) = 4 + f(3)$, …, $f(1) = 1$. Geri dönerken $3, 6, 10, 15$ bulunur. $f(5) = 15$.

**Faktöriyel** (slayt kareden doğrulandı):

```text
factorial(n):
    if n is 0
        return 1
    return n * factorial(n-1)
```

- $n = 0$ için 1 karşılaştırma. Diğer her çağrıda 1 karşılaştırma, 1 çarpma, 1 çıkarma.
- $T(n) = T(n-1) + 3$, $T(0) = 1$.
- $T(n) = T(n-2) + 6 = T(n-3) + 9 = \dots = T(n-k) + 3k$.
- $n - k = 0$ için $k = n$: $T(n) = 1 + 3n$. Karmaşıklık $O(n)$.

### Rekürans bağıntısı nedir?

- Dizi: $a_n = 5n + 1$. $a_{20}$ için $n$ yerine 20 konur: $a_{20} = 101$.
- Rekürans bağıntısı: içinde kendisinden bir parça ($a_{n-1}$ gibi) vardır. $a_{20}$ için $a_{19}$ bilinmelidir.

**Örnek** (slayt kareden doğrulandı): $a_n = 2a_{n-1} - a_{n-2} + 2^{n-1}$, $a_0 = 1$, $a_1 = 2$, $n \ge 2$. $a_5 = ?$

| $n$ | Hesap | Sonuç |
| :---: | :--- | :---: |
| 2 | $2 \cdot 2 - 1 + 2$ | 5 |
| 3 | $2 \cdot 5 - 2 + 4$ | 12 |
| 4 | $2 \cdot 12 - 5 + 8$ | 27 |
| 5 | $2 \cdot 27 - 12 + 16$ | 58 |

- İkinci dereceden olduğu için iki başlangıç değeri ($a_0$, $a_1$) gerekir.

### Rekürans bağıntılarının sınıflandırılması

| Özellik | Anlamı | Bozan durum |
| :--- | :--- | :--- |
| Derece | En büyük geriye kayma ($a_{n-k}$'daki $k$) | — |
| Homojen | Yalnız kendisinden türetilmiş terimler | Sabit, $4n$, $3^n$, $n^2$ gibi terimler |
| Doğrusal | Terimler birinci kuvvette ve çarpılmamış | $a_{n-1}^2$, $a_{n-1}a_{n-2}$, $a_n^3$ |
| Sabit katsayılı | Katsayılar sabit sayı | $n\,a_{n-1}$, $3^n a_{n-2}$ |

### Sabit katsayılı homojen bağıntılar: karakteristik kök yöntemi

- En düşük indisli terim 1, bir üstü $r$, bir üstü $r^2$ alınır.
- Örnek (slayt kareden doğrulandı): $a_n = 3a_{n-1} + 4a_{n-2}$
  - $r^2 = 3r + 4 \Rightarrow r^2 - 3r - 4 = 0 \Rightarrow (r-4)(r+1) = 0$.
  - Kökler $4$ ve $-1$. $a_n^{(h)} = C_1 4^n + C_2 (-1)^n$.

**Ayrık kökler örneği:** $a_n = 3a_{n-1} + 10a_{n-2}$, $a_0 = 5$, $a_1 = 8$.
- $r^2 - 3r - 10 = 0 \Rightarrow (r-5)(r+2) = 0$. Kökler $5$ ve $-2$.
- $a_n = C_1 5^n + C_2 (-2)^n$.
- $n = 0$: $C_1 + C_2 = 5$. $n = 1$: $5C_1 - 2C_2 = 8$.
- İlk denklem 2 ile çarpılıp toplanır: $7C_1 = 18 \Rightarrow C_1 = \frac{18}{7}$, $C_2 = \frac{17}{7}$.
- Çözüm: $a_n = \frac{18}{7}5^n + \frac{17}{7}(-2)^n$.

**Çakışık kökler örneği** (slayt kareden doğrulandı): $a_n = -4a_{n-1} - 4a_{n-2}$, $a_0 = 3$, $a_1 = 5$.
- $r^2 + 4r + 4 = 0 \Rightarrow (r+2)^2 = 0$. Çift kök $-2$.
- $a_n = C_1(-2)^n + C_2\,n\,(-2)^n$.
- $n = 0$: $C_1 = 3$. $n = 1$: $-2C_1 - 2C_2 = 5 \Rightarrow C_2 = -\frac{11}{2}$.
- Çözüm: $a_n = 3(-2)^n - \frac{11}{2}n(-2)^n$.

**Üçüncü ve daha yüksek derece:**
- Bütün kökler farklı: $C_1 r_1^n + C_2 r_2^n + C_3 r_3^n$.
- Bütün kökler aynı ($r$): $C_1 r^n + C_2 n r^n + C_3 n^2 r^n$.
- İki kök aynı, biri farklı: $C_1 r_1^n + C_2 n r_1^n + C_3 r_3^n$.

### Sabit katsayılı homojen olmayan bağıntılar

Genel çözüm: $a_n = a_n^{(h)} + a_n^{(ö)}$. Önce homojen kısım çözülür. Sonra $f(n)$'e göre özel çözüm tahmin edilir. $C_1$ ve $C_2$ en son, başlangıç değerleriyle bulunur.

**$f(n)$ sabit** (slayt kareden doğrulandı): $a_n = 2a_{n-1} + 3a_{n-2} + 5$, $a_0 = 4$, $a_1 = 10$.
- Homojen: $r^2 - 2r - 3 = 0$, kökler $3$ ve $-1$.
- Özel: $a_n = a_{n-1} = a_{n-2} = A$ konur. $A = 2A + 3A + 5 \Rightarrow -4A = 5 \Rightarrow A = -\frac{5}{4}$.
- $a_n = C_1 3^n + C_2(-1)^n - \frac{5}{4}$.
- $C_1 + C_2 = \frac{21}{4}$ ve $3C_1 - C_2 = \frac{45}{4}$. Buradan $4C_1 = \frac{33}{2}$, $C_1 = \frac{33}{8}$, $C_2 = \frac{9}{8}$.

**$f(n)$ birinci dereceden polinom:** $a_n = a_{n-1} + 2a_{n-2} + 3n + 4$, $a_0 = 5$, $a_1 = 7$.
- Homojen: $r^2 - r - 2 = 0$, kökler $2$ ve $-1$.
- Özel: $a_n^{(ö)} = An + B$. Bu durumda $a_{n-1} = An - A + B$, $a_{n-2} = An - 2A + B$.
- Yerine koyunca: $An + B = 3An - 5A + 3B + 3n + 4$.
  - $n$'li terimler: $A = 3A + 3 \Rightarrow A = -\frac{3}{2}$.
  - Sabitler: $B = -5A + 3B + 4 \Rightarrow B = -\frac{23}{4}$.
- $a_n = C_1 2^n + C_2(-1)^n - \frac{3}{2}n - \frac{23}{4}$ (slayttaki sonuç kareden doğrulandı).
- Derste $C_1$, $C_2$ hesaplanmadı. Başlangıç değerleriyle: $C_1 = \frac{25}{3}$, $C_2 = \frac{29}{12}$ (Python ile doğrulandı).

**$f(n)$ üstel, homojen çözümde geçmiyor** (slayt kareden doğrulandı): $a_n = -4a_{n-1} - 3a_{n-2} + 2\cdot 5^n$, $a_0 = 6$, $a_1 = 10$.
- Homojen: $r^2 + 4r + 3 = 0 \Rightarrow (r+3)(r+1) = 0$, kökler $-3$ ve $-1$. $5^n$ homojen çözümde yok.
- Özel: $a_n^{(ö)} = A\cdot 5^n$. Katsayı 2 kullanılmaz; yerine bilinmeyen $A$ konur.
  - $a_{n-1} = \frac{A}{5}5^n$, $a_{n-2} = \frac{A}{25}5^n$.
  - $A = -\frac{4A}{5} - \frac{3A}{25} + 2 \Rightarrow \frac{48A}{25} = 2 \Rightarrow A = \frac{25}{24}$.
- $a_n = C_1(-3)^n + C_2(-1)^n + \frac{25}{24}5^n$.
- Derste $C_1$, $C_2$ hesaplanmadı. Başlangıç değerleriyle: $C_1 = -\frac{39}{8}$, $C_2 = \frac{59}{6}$ (Python ile doğrulandı).

**$f(n)$ üstel, homojen çözümde geçiyor** (slayt kareden doğrulandı): $a_n = 2a_{n-1} + 3a_{n-2} + 3^n$, $a_0 = 7$, $a_1 = 5$.
- Homojen: kökler $3$ ve $-1$. $a_n^{(h)} = C_1 3^n + C_2(-1)^n$. $3^n$ homojen çözümde bir kez geçiyor.
- Bu yüzden özel çözüm $n$ ile çarpılır: $a_n^{(ö)} = A\cdot n\cdot 3^n$.
  - $a_{n-1} = \frac{A}{3}n3^n - \frac{A}{3}3^n$, $a_{n-2} = \frac{A}{9}n3^n - \frac{2A}{9}3^n$.
  - Yerine koyunca $n3^n$'li terimler sadeleşir: $\frac{4A}{3} = 1 \Rightarrow A = \frac{3}{4}$.
- $a_n = C_1 3^n + C_2(-1)^n + \frac{3}{4}n3^n$.
- Derste $C_1$, $C_2$ hesaplanmadı. Başlangıç değerleriyle: $C_1 = \frac{39}{16}$, $C_2 = \frac{73}{16}$ (Python ile doğrulandı).

### Sözel problemlerden rekürans bağıntısı

**Dizi 1:** $4, 7, 13, 25, 49, 97, \dots$
- Her terim, bir öncekinin iki katının bir eksiği: $a_n = 2a_{n-1} - 1$, $a_0 = 4$.
- Homojen olmayan, sabit katsayılı, birinci dereceden. Çözümü: $a_n = 3\cdot 2^n + 1$. Örneğin $a_6 = 193$.

**Dizi 2:** $1, 3, 7, 17, 41, 99, 239, \dots$
- $a_n = 2a_{n-1} + a_{n-2}$, $a_0 = 1$, $a_1 = 3$, $n \ge 2$.
- Homojen, sabit katsayılı, ikinci dereceden. Karakteristik kök yöntemiyle çözülür.

**Dizi 3** (slayt kareden doğrulandı): $1, 3, 6, 13, 27, 56, 115, \dots$
- $1 + 3 + 2 = 6$, $3 + 6 + 4 = 13$, $6 + 13 + 8 = 27$.
- $a_n = a_{n-1} + a_{n-2} + 2^{n-1}$, $a_0 = 1$, $a_1 = 3$, $n \ge 2$.
- Homojen değil. Özel çözüm tahmini yapılırken $2^{n-1}$'in homojen çözümde geçip geçmediğine bakılır.

**Sıfır ve birlerden oluşan diziler** (slayt kareden doğrulandı): $n$ uzunluğunda olup içinde art arda "00" bulunan dizilerin sayısı $a_n$.
- Sayarak: $a_0 = 0$, $a_1 = 0$, $a_2 = 1$ (00), $a_3 = 3$ (000, 001, 100), $a_4 = 8$.
- Hoca bu değerlerden $a_n = 2a_{n-1} + a_{n-2} + 1$ bağıntısını çıkardı. Bu bağıntı yanlıştır; bkz. Ders sonrası notlar.
- Doğru bağıntı: $a_n = a_{n-1} + a_{n-2} + 2^{n-2}$, $n \ge 2$, $a_0 = a_1 = 0$.
  - Mantık: Dizi 1 ile başlıyorsa kalan $n-1$ uzunluk "00" içermeli: $a_{n-1}$ yol.
  - Dizi 01 ile başlıyorsa kalan $n-2$ uzunluk "00" içermeli: $a_{n-2}$ yol.
  - Dizi 00 ile başlıyorsa zaten "00" içerir. Kalan $n-2$ basamak serbesttir: $2^{n-2}$ yol.

### Çözülebilirlik

- **Çözülebilir (tractable):** En kötü durumu polinom zamanlı bir algoritmayla çözülebilen problem. Örnek: $O(\log n)$, $O(n^2)$, $O(n^3)$.
- **Çözülemez (intractable):** Polinom zamanlı algoritması bilinmeyen problemler. $2^n$ ve $n!$ gibi karmaşıklıklar pratikte çözülemez. Endüstride bazıları özel koşullar altında çözülebilmiştir.
- **Çözümsüz (unsolvable):** Hiçbir algoritmayla çözülemeyen problem. Örnek: Alan Turing'in durma problemi. Girdi olarak verilen bir programın durup durmayacağını her program için söyleyen bir program yazılamaz.
- NP-complete ve NP-hard kavramlarının ayrıntısı Algoritma Analizi dersinde verilecek.

### Ders sonrası notlar

- **"00" içeren diziler (önemli):** Hocanın çıkardığı $a_n = 2a_{n-1} + a_{n-2} + 1$ bağıntısı ilk beş değeri ($0, 0, 1, 3, 8$) tutturuyor, ama sonraki terimlerde yanlış. Bu bağıntı $a_5 = 20$ verir. Gerçek sayı 19'dur. Bütün 5 bitlik diziler Python ile sayıldı: 32 dizinin 13'ü "00" içermez, 19'u içerir. Doğru bağıntı $a_n = a_{n-1} + a_{n-2} + 2^{n-2}$'dir: $0, 0, 1, 3, 8, 19, 43, 94, 201$. Ders: Birkaç terime uyan bir kural bulmak, bağıntının doğru olduğunu göstermez. Bağıntıyı problemin yapısından kurun.
- **Big-O ile ilgili hatırlatma:** Önceki derste Big-O "en kötü durum", Big-Omega "en iyi durum" diye eşlenmişti. Bu gösterimler aslında üst ve alt sınırdır; durum analiziyle aynı şey değildir. Ayrıntı ders 7 özetinin notlarında.
- **Karakteristik kökler:** Hoca $r^2 - 3r - 10 = 0$ için önce "köklerim 5 ve 2" dedi. Kökler $5$ ve $-2$'dir; çözümde $-2$ kullanıldı. $r^2 - 3r - 4 = 0$ için "çarpımları 4, toplamları $-3$" dendi. Doğrusu: köklerin çarpımı $-4$, toplamı $3$'tür; kökler $4$ ve $-1$.
- **Çakışık kök örneğinde $a_1$:** Hoca bir an "$a_1$ bir ise" dedi. Slaytta $a_1 = 5$ yazıyor ve hesap $5$ ile yapıldı.
- **Faktöriyel yürütme zamanı:** Slayt "(n−1) kez" diyor. Rekürsif çağrı $n, n-1, \dots, 1$ için $n$ kez çarpma ve çıkarma yapar. $T(n) = 3n + 1$ sonucu zaten $n$ tekrara göredir. Karmaşıklık $O(n)$.
- **Homojen olmayan bağıntı notu:** Slayttaki not "polinomun derecesi ne ise $a_n$'nin de derecesi aynı olur" der. Bu, özel çözüm tahmininin $f(n)$ ile aynı dereceden bir polinom olduğu anlamına gelir. Ancak $f(n)$'nin kökü 1 ise (homojen çözümde $1^n$ varsa) tahmin $n$ ile çarpılmalıdır. Bu, üstel durumdaki kuralın aynısıdır.
- **"Polinomsal zamanda çözülemez" ifadesi:** Hoca $2^n$ ve $n!$ karmaşıklıklı algoritmalar için "çözümü hiçbir zaman yok" dedi. Doğrusu: Bu algoritmalar sonlu zamanda çözüm üretir, ama giriş büyüdükçe süre pratik olarak kabul edilemez hale gelir. Hiçbir algoritmayla çözülemeyen problemler (durma problemi gibi) ayrı bir sınıftır.
- **NP-complete tanımı:** Hocanın tanımı belirsiz kaldı. Kısaca: NP, çözümü polinom zamanda doğrulanabilen problemler sınıfıdır. NP-hard, NP'deki her problemin polinom zamanda indirgenebildiği problemlerdir. NP-complete, hem NP'de hem NP-hard olan problemlerdir.
- **Karmaşıklık sorusu:** Dış döngü $i = n/2, \dots, n$ için $n/2 + 1$ kez döner. İç döngü $\lfloor\log_2 n\rfloor + 1$ kez döner. Tam sayım $\Theta(n^2\log n)$'dir; sonuç değişmez.
- Bütün örneklerin sayısal sonuçları ($a_5 = 58$, $C$ katsayıları, dizilerin terimleri, Karnaugh sadeleştirmesi, 432) Python ile kontrol edildi.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
