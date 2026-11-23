# Ders 2 Çalışma Özeti

## Genel Konular

- Küme teorisi tekrarı
  - Birleşim, kesişim, fark, tümleyen ve Kartezyen çarpım kısaca hatırlatıldı. $A \times B$, ilk bileşeni $A$'dan, ikinci bileşeni $B$'den gelen sıralı ikililerin kümesidir.
  - İkili ilişki (binary relation): $A$ ve $B$ kümeleri üzerinde $A \times B$'nin herhangi bir alt kümesi.
  - Fonksiyon $f: A \to B$: her $a \in A$ için ilk bileşeni $a$ olan tam olarak bir sıralı ikili içeren ikili ilişki. $A$ tanım kümesi (domain), $\{b \in B : f(a)=b \text{ olan bir } a \in A \text{ var}\}$ kümesi görüntü kümesidir (range).
  - Denklik ilişkisi: $R \subseteq A \times A$ yansımalı (reflexive), simetrik ve geçişli (transitive) ise denklik ilişkisidir.
- Boole mantığı
  - Değerler 1 (doğru) ve 0 (yanlış). İşlemler: değil ($\neg$), ve ($\wedge$), veya ($\vee$), özel veya ($\oplus$), denklik ($\Leftrightarrow$), gerektirme ($\Rightarrow$).
  - XOR, iki işlenen farklıysa 1 verir; denklik, XOR'un tersidir.
  - Gerektirme $p \Rightarrow q$ yalnız $p=1$, $q=0$ iken yanlıştır.
- Matematiksel tanımlar
  - Teorem (doğru olduğu ispatlanmış önerme), ispat, aksiyom (ispatsız kabul), hipotez (sınırlı kanıtlı tahmin), lemma ve sonuç (corollary).
- İspat teknikleri
  - İspat için ipuçları: önermeyi tam anlamak, "ancak ve ancak" ifadelerinde iki yönü ayrı ispatlamak, küme eşitliğinde $A \subseteq B$ ve $B \subseteq A$ göstermek, basit durumlarla denemek, sabırlı olmak.
  - Doğrudan ispat, inşa ile ispat (constructive proof), olmayana ergi (proof by contradiction), tümevarım (induction), güvercin yuvası ilkesi.
- Diller (languages)
  - Alfabe $\Sigma$: sembollerden oluşan sonlu küme. Dize (string): alfabedeki sembollerin dizisi. Dil: dizelerin kümesi, yani $\Sigma^*$'ın herhangi bir alt kümesi.
  - Hesaplama problemleri küme üyeliği problemine çevrilir: "x asal mı?" sorusu "$x \in PRIMES$ mi?" sorusudur.
  - Onluk, ikilik ve tekli (unary) sayı alfabeleri.
- Dize işlemleri
  - Birleştirme (concatenation), ters (reverse, $w^R$), uzunluk ($|w|$), boş dize ($\varepsilon$ ya da $\lambda$), alt dize, önek ve sonek, dize kuvveti ($w^n$), $\Sigma^*$ ve $\Sigma^+$.
- Dil örnekleri ve dil işlemleri
  - $\{a^n b^n : n \ge 0\}$, PRIMES, EVEN, ODD, tekli sayılarla ADDITION ve SQUARES dilleri.
  - Boş dil $\emptyset$ ile $\{\varepsilon\}$ farkı.
  - Küme işlemleri, tümleyen ($\overline{L} = \Sigma^* - L$), dilin tersi ($L^R$), dil birleştirme ($L_1L_2$), dil kuvveti ($L^n$, $L^0=\{\varepsilon\}$), Kleene yıldızı ($L^*$) ve pozitif kapanış ($L^+$).

## Hocanın Özellikle Vurguladığı Kısımlar

- Bu dersteki her şey kümelere dayanır
  - Küme eşitliğini iki yönlü alt küme ilişkisiyle ispatlamak bu derste çok kullanılacak.
- Sipser'in kitabında inşa ile ispat ve olmayana ergi çok sık kullanılır
  - Bir hesaplama modelinin var olduğunu göstermenin en iyi yolu o modeli kurmaktır.
- Gerektirme tablosu ilk bakışta kafa karıştırır
  - Çöp örneği: "çöpü çıkarırsan bir dolar alırsın". Söz yalnız çöp çıkarılıp dolar verilmediğinde bozulur; çöp çıkarılmadıysa sonuç ne olursa olsun önerme doğrudur.
- $w^2$ sayılardaki kuvvet değildir
  - $w^2 = ww$, yani dizenin kendisiyle birleştirilmesidir. $w^0 = \varepsilon$ tanım gereğidir.
  - SQUARES dilinde $x$ ve $y$ dizeyken kuvvet birleştirme, $n$ ve $m$ sayıyken aritmetik kuvvettir; hoca bunu operatör aşırı yüklemeye (operator overloading) benzetti.
- Boş dil ile boş dizeli dil karıştırılmamalı
  - $|\emptyset| = 0$, $|\{\varepsilon\}| = 1$, $|\varepsilon| = 0$. Biri küme boyutu, diğeri dize uzunluğudur.
- $L^2$, $\{a^n b^n a^n b^n\}$ değildir
  - $L=\{a^nb^n\}$ için $L^2 = \{a^n b^n a^m b^m : n,m \ge 0\}$; iki parça birbirinden bağımsız seçilir.
- Yıldız işareti üç farklı şeyin üzerine konabilir
  - Alfabe üzerinde: o alfabeyle yazılabilen tüm dizeler. Dize üzerinde: dizenin tüm kuvvetleri. Dil üzerinde: dilin tüm kuvvetlerinin birleşimi.

## Kısa Tekrar Notları

- İkili ilişki $\subseteq A \times B$; fonksiyon, her $a$ için tek çıktısı olan ilişkidir.
- Denklik ilişkisi = yansımalı + simetrik + geçişli.
- $p \Rightarrow q$ yalnız $1 \Rightarrow 0$ durumunda 0'dır. XOR farklılığı, denklik eşitliği kontrol eder.
- "Ancak ve ancak" iki yönlü ispat ister; $A=B$ için $A \subseteq B$ ve $B \subseteq A$.
- Doğrudan ispat: $n=2k+1 \Rightarrow n^2 = 2(2k^2+2k)+1$, yani tek.
- İnşa ile ispat: $a=\sqrt{2}$, $b=\log_2 9$ irrasyonel, $a^b = 3$ rasyonel.
- Olmayana ergi: $\sqrt{2} = p/q$ varsay, $p$ ve $q$'nun ikisinin de çift çıktığını göster, çelişki.
- Tümevarım: taban durumu ($n=1$) + $P(n) \Rightarrow P(n+1)$.
- Güvercin yuvası: $n+1$ nesne $n$ kutuya konursa bir kutuda en az iki nesne olur.
- $|uv| = |u| + |v|$; $\varepsilon w = w\varepsilon = w$; $|\varepsilon|=0$.
- $\varepsilon$ ve dizenin kendisi hem önek hem sonektir.
- $\Sigma^+ = \Sigma^* - \{\varepsilon\}$.
- $\overline{L} = \Sigma^* - L$; $L^R = \{w^R : w \in L\}$; $L_1L_2 = \{xy : x\in L_1, y \in L_2\}$.
- $L^0 = \{\varepsilon\}$; $L^* = L^0 \cup L^1 \cup L^2 \cup \cdots$; $L^+ = L^1 \cup L^2 \cup \cdots$.

## Detaylı Açıklamalar

- **Fonksiyon ve ilişki.** Fonksiyonlar, belirli bir şartı sağlayan ikili ilişkilerdir: tanım kümesindeki her eleman için ilişkide tam olarak bir ikili bulunur. $f(a)=b$ yazmak, $(a,b)$ ikilisinin ilişkide olduğunu söylemektir. Hoca ikili ilişkiyi fonksiyonların üst kümesi gibi düşünmeyi önerdi. Denklik ilişkisi için Türkçede "denklik ilişkisi" terimi kullanıldı.
- **Doğruluk tablosu (ekrandan, 00:25:00).**

| $p$ | $q$ | $\neg p$ | $p \wedge q$ | $p \vee q$ | $p \oplus q$ | $p \Leftrightarrow q$ | $p \Rightarrow q$ |
|---|---|---|---|---|---|---|---|
| 0 | 0 | 1 | 0 | 0 | 0 | 1 | 1 |
| 0 | 1 | 1 | 0 | 1 | 1 | 0 | 1 |
| 1 | 0 | 0 | 0 | 1 | 1 | 0 | 0 |
| 1 | 1 | 0 | 1 | 1 | 0 | 1 | 1 |

- **İnşa ile ispat (constructive proof).** "Bir nesne vardır" türündeki teoremler o nesneyi kurarak ispatlanır. Örnek teorem: $a$ ve $b$ irrasyonel olmak üzere $a^b$ biçiminde yazılabilen rasyonel bir $p$ vardır. $a=\sqrt{2}$, $b=\log_2 9$ seçilir. $\log_2 9 = m/n$ olsaydı $2^m = 9^n$ olurdu; sol taraf çift, sağ taraf tek olduğundan bu olamaz, yani $b$ irrasyoneldir. $a^b = 2^{\frac{1}{2}\log_2 9} = 9^{1/2} = 3$ rasyoneldir.
- **Olmayana ergi (ekrandan, 00:50:00).** $\sqrt{2}=p/q$, $p$ ve $q$ ortak çarpansız varsayılır. $2q^2 = p^2$ olduğundan $p^2$, dolayısıyla $p$ çifttir: $p=2r$. Buradan $2q^2 = 4r^2$, yani $q^2 = 2r^2$ ve $q$ da çifttir. $p$ ile $q$'nun ortak çarpanı 2 çıkar; bu, varsayımla çelişir. Demek ki $\sqrt{2}$ irrasyoneldir.
- **Tümevarım (ekrandan, 01:00:00).** $1+2+\cdots+n = \frac{n(n+1)}{2}$ için taban: $n=1$'de iki taraf da 1'dir. Adım: ifade $n$ için doğru kabul edilir, $n+1$ için $\frac{n(n+1)}{2} + (n+1) = \frac{(n+1)(n+2)}{2}$ olduğu gösterilir. $P(1)$ doğru ve $P(n) \Rightarrow P(n+1)$ olduğundan zincirleme olarak tüm pozitif tam sayılar için doğrudur.
- **Dilleri tanımlama.** Dil elemanları tek tek listelenebilir ya da özellikleriyle tanımlanabilir. $\{a^nb^n : n\ge 0\} = \{\varepsilon, ab, aabb, aaabbb, \ldots\}$ sonsuz bir dildir; $abb$ ya da $ba$ gibi dizeler bu biçime uymadığı için dilde değildir. Tekli gösterimle ADDITION dili $\{x+y=z : x=1^n, y=1^m, z=1^k, n+m=k, n\ge1, m\ge1\}$ biçiminde geçerli toplamaları tanımlar: $11+111=11111 \in ADDITION$, $111+111=111 \notin ADDITION$ (ekrandan, 02:15:00). SQUARES dili $\{x\#y : x=1^n, y=1^m, m=n^2\}$ geçerli kare alma işlemlerini tanımlar.
- **Dil işlemleri.** Diller küme olduğundan birleşim, kesişim, fark ve tümleyen uygulanabilir. Dil birleştirmede $L_1$'deki her dize $L_2$'deki her dizeyle birleştirilir; $L_1$ üç, $L_2$ iki elemanlıysa sonuç en fazla altı elemanlıdır. $\{a,b\}^3 = \{aaa, aab, aba, abb, baa, bab, bba, bbb\}$ (ekrandan, 02:30:00). $\{a,bb\}^* = \{\varepsilon, a, bb, aa, abb, bba, bbbb, aaa, aabb, abba, abbbb, \ldots\}$ (ekrandan, 02:40:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
