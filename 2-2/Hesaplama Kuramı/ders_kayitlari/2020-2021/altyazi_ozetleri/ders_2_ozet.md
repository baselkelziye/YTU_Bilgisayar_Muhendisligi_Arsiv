# Ders 2 Çalışma Özeti

## Genel Konular

- Dersin tarihi 16 Mart 2021 Salı. Ders Zoom üzerinden, İngilizce yapıldı.
  - Asıl ders yaklaşık 00:02'de başlar.
- Değerlendirme sistemi değişti (geçici plan, tahtadan)
  - 3 quiz, her biri 10 puan, toplam 30 puan.
  - 1 vize, 30 puan.
  - Final, 40 puan.
  - Ödev verilmeyecek.
- İspat teknikleri (devam)
  - Yapıcı ispat örneğinin tekrarı.
  - Olmayana ergi (proof by contradiction): $\sqrt{2}$'nin irrasyonel olduğunun ispatı.
  - Tümevarım (proof by induction): $1 + 2 + \dots + n = \frac{n(n+1)}{2}$ ispatı.
  - Güvercin yuvası ilkesi (pigeonhole principle) ve 1-11 arasından 7 sayı seçme örneği.
- Düzenli diller (regular languages) ve temel tanımlar
  - Alfabe (alphabet), sembol (symbol), dizgi (string), dizgi uzunluğu, boş dizgi, ters dizgi, alt dizgi.
  - Birleştirme (concatenation), $x^k$ gösterimi, yıldız (Kleene star).
  - Dil (language): bir alfabe üzerindeki dizgilerin kümesi.
  - Düzenli dil kavramı ve kapalılık (closure) özellikleri.
- Karışık örnekler ve tanımlar
  - Ondalık, ikili ve birli (unary) sayıların dizgi olarak gösterimi.
  - Toplama ve kare alma işlemlerinin birer dil olarak tanımlanması.
  - Önek (prefix) ve sonek (suffix), $\Sigma^+$ işlemi, dilin $\Sigma^*$'ın alt kümesi olması.
  - Boş küme ile boş dizgi arasındaki fark.

## Hocanın Özellikle Vurguladığı Kısımlar

- Quizler sürpriz olmayacak.
  - Quiz zamanı bir hafta önceden duyurulacak.
  - Quizler kısa olacak (15-20 dakika), dersin sonunda yapılacak. Büyük olasılıkla test olacak.
- Olmayana ergi ispatında başta "çelişki elde etmek için varsayalım" diye yazın.
- Tümevarımda iki adım vardır.
  - Taban adımı (basis) sayısal olarak gösterilir.
  - Tümevarım adımı (induction step) sayıyla değil, genel ifadeyle ($n$ ve $n+1$) ispatlanır.
- Dil yalnızca bir dizgi kümesidir.
  - Diller küme olduğu için bütün küme işlemleri dillere uygulanabilir.
- Bu derste $0^2$ gibi gösterimler sayısal işlem değildir.
  - $0^2 = 00$ demektir, yani birleştirmedir.
- Boş küme $\emptyset$ ile boş dizgi $\varepsilon$ aynı şey değildir. Bunlara dikkat edin.
- Güvercin yuvası ilkesi basit bir fikirdir ama birçok teoremin ispatında işe yarar.

## Kısa Tekrar Notları

- Olmayana ergi: Teoremin yanlış olduğunu varsay, bir çelişkiye ulaş, teoremin doğru olduğu sonucunu çıkar.
- Tümevarım: Teoremi $n = 1$ için göster. $n$ için doğruysa $n+1$ için de doğru olduğunu göster.
- Güvercin yuvası ilkesi: $|A| > |B|$ ise $A$'dan $B$'ye bire bir (one-to-one) fonksiyon yoktur.
- Alfabe: sonlu ve boş olmayan sembol kümesi. Genelde $\Sigma$ veya $\Gamma$ ile gösterilir.
- Dizgi: bir alfabedeki sembollerden oluşan sonlu dizi.
- $|w|$: $w$ dizgisinin uzunluğu. $|\varepsilon| = 0$.
- $w^R$: $w$'nin tersi. $w = w_1 w_2 \dots w_n$ ise $w^R = w_n \dots w_2 w_1$.
- Alt dizgi: $w$ içinde ardışık olarak geçen dizgi. Örnek: "cad", "abracadabra"nın alt dizgisidir.
- $A \circ B = \{xy \mid x \in A, y \in B\}$.
- $\Sigma^+ = \Sigma^* - \{\varepsilon\}$.
- $\varepsilon$ her dizginin hem öneki hem sonekidir. Her dizgi kendisinin hem öneki hem sonekidir.
- Bir $\Sigma$ alfabesi üzerindeki her dil $\Sigma^*$'ın alt kümesidir.
- Bütün sonlu diller düzenlidir. Bazı sonsuz diller de düzenlidir.
- Düzenli diller sınıfı birleşim, kesişim, tümleyen, birleştirme ve yıldız işlemlerine göre kapalıdır.

## Detaylı Açıklamalar

### Olmayana ergi: $\sqrt{2}$ irrasyoneldir

**İspat:**
- Çelişki elde etmek için $\sqrt{2}$'nin rasyonel olduğunu varsayalım.
- O hâlde $\sqrt{2} = \frac{p}{q}$ yazılır. $p$ ve $q$ tam sayıdır.
- $p$ ve $q$'nun ortak çarpanı olmadığını da varsayabiliriz.
  - Ortak bir $d$ çarpanı varsa $p' = p/d$, $q' = q/d$ alınarak sadeleştirilir. Örnek: $\frac{9}{6} = \frac{3 \cdot 3}{3 \cdot 2} = \frac{3}{2}$.
- $\frac{p^2}{q^2} = 2$, yani $2q^2 = p^2$.
- $2q^2$ çift olduğundan $p^2$ çifttir. O hâlde $p$ de çifttir. $p = 2r$ yazalım.
- $2q^2 = 4r^2$, yani $q^2 = 2r^2$. Aynı mantıkla $q$ de çifttir.
- $p$ ve $q$'nun ikisi de çift çıktı. Ortak çarpanları 2'dir. Bu, başlangıçtaki varsayımla çelişir.
- O hâlde $\sqrt{2}$ rasyonel değildir.

Bir öğrenci, rasyonel sayıların tanımının ispat gerektirip gerektirmediğini sordu. Hoca Türkçe yanıtladı: Bu bir aksiyom da değildir, bir tanımdır. Rasyonel sayılar bir kümedir. İspatta $\sqrt{2}$'nin bu kümenin içinde olmadığını gösterdik.

### Tümevarım

- Teorem önce bir sayı için ispatlanır. Bu genelde $n = 1$'dir ama başka bir sayı da olabilir.
- Teoremin $n$ için doğru olduğu varsayılır ve $n+1$ için doğru olduğu gösterilir.
- Böylece 1'den 2'ye, 2'den 3'e, sonsuza kadar gidilir.
- Gerekirse $n-1$ yönünde (eksi sonsuza doğru) veya $n+2$ adımıyla (ör. çift sayılar için) de çalışılabilir.

**Teorem:** Her pozitif tam sayı $n$ için $1 + 2 + \dots + n = \frac{n(n+1)}{2}$.

- **Taban adımı:** $n = 1$ için sol taraf 1, sağ taraf $\frac{1 \cdot 2}{2} = 1$. Eşittir.
- **Tümevarım adımı:** $1 + 2 + \dots + n = \frac{n(n+1)}{2}$ olsun.
  - $1 + 2 + \dots + n + (n+1) = \frac{n(n+1)}{2} + (n+1) = \frac{(n+1)(n+2)}{2}$.
  - Bu, formülün $n+1$ için yazılmış hâlidir.

Bir öğrenci, tümevarım adımında $n = 2$ alınıp alınmayacağını sordu. Hoca Türkçe açıkladı: 2'yi sayısal ispatlarsanız yalnız 2'yi ispatlamış olursunuz. "$n$ için doğruysa $n+1$ için de doğrudur" gösterilirse bütün sayılar birden ispatlanır.

### Güvercin yuvası ilkesi

Hoca Türkçe bir resimle açıkladı: 9 yuva ve 10 güvercin varsa, bütün güvercinleri yerleştirmek için bir yuvaya 2 güvercin koymak zorundasınız.

**Teorem:** 1'den 11'e kadar olan sayılardan 7 farklı sayı seçilirse, seçilenlerden ikisinin toplamı 12'dir.

**Örnek seçim:** $\{1, 5, 6, 7, 10, 11, 3\}$. Burada $1 + 11 = 12$. Bu bir ispat değildir, yalnız teoremi anlamaya yarar.

**İspat:**
- Şu 6 küme kurulur: $\{1, 11\}$, $\{2, 10\}$, $\{3, 9\}$, $\{4, 8\}$, $\{5, 7\}$, $\{6\}$.
- 1'den 11'e kadar her sayı bu kümelerden tam birindedir.
- Kümeler yuva, seçilen 7 sayı güvercindir.
- 7 sayı seçildiği için güvercin yuvası ilkesine göre iki seçim aynı kümeden gelir.
- $\{6\}$ kümesinden iki farklı sayı seçilemez. O hâlde bu iki sayı ikili kümelerden birindendir ve toplamları 12'dir.

Bir öğrenci, bu fikrin "elemanların yarısından bir fazlası seçilince zaten belli" olduğunu söyledi. Hoca, ilkenin basit ama farklı uygulamaları olan bir farkındalık olduğunu belirtti.

### Alfabe, dizgi ve dil

- Örnek alfabeler: $\Sigma_1 = \{0, 1\}$, $\Gamma = \{0, 1, x, z\}$.
- $0010$, $\Sigma_1$ üzerinde bir dizgidir. $0xz0$, $\Gamma$ üzerinde bir dizgidir.
- $|0xz0| = 4$.
- Boş dizgi $\varepsilon$ ile gösterilir. Bazı kaynaklar $\lambda$ kullanır.
- Birleştirme: $w = \text{abra}$, $z = \text{cadabra}$ ise $wz = \text{abracadabra}$.
- $x^3 = xxx$.
- $x^* = \{\varepsilon, x, xx, xxx, \dots\}$. Burada $\varepsilon = x^0$.
- Dil örnekleri ($\Sigma = \{0, 1, x\}$):
  - $L_1$ ve $L_2 = \{0, 0x\}$ gibi sonlu diller.
  - $L_3 = \{w \mid w = a^{2n}, a \in \Sigma, n \geq 0\} = \{\varepsilon, 00, 11, xx, 0000, 1111, xxxx, \dots\}$. Bu sonsuz bir dildir.

### Dil üzerinde işlemler (tahtadan)

$A = \{aa, bb\}$ ve $B = \{0, 11\}$ için:

- $A \cup B = \{aa, bb, 0, 11\}$.
- $A \circ B = \{aa0, aa11, bb0, bb11\}$.
- Tahtada yıldız şöyle tanımlandı: $A^* = \{x_1 x_2 \dots x_k \mid k > 0, x_i \in A\} = \{aa, bb, aabb, aaaa, aaaabb, \dots\}$.

### Düzenli diller ve kapalılık

- Hoca, düzenli dillerin bir tanımı olmadığını ama bir dilin düzenli olup olmadığının test edilebileceğini söyledi. Test için sonlu otomatlar kullanılacak (bkz. ders sonrası notlar).
- Bir dil sınıfı bir işleme göre kapalıdır: işlemin sonucu yine aynı sınıftadır.
- $A$ ve $B$ düzenliyse $A \cup B$ de düzenlidir.
- Düzenli diller birleşim, kesişim, tümleyen, birleştirme ve yıldız işlemlerine göre kapalıdır.

### İşlemleri dil olarak yazmak

- Ondalık sayılar: $\Sigma = \{0, 1, \dots, 9\}$ üzerinde dizgiler.
- İkili sayılar: $\Sigma = \{0, 1\}$ üzerinde dizgiler.
- Birli (unary) sayılar: $\Sigma = \{1\}$. Dizginin uzunluğu sayının değeridir. $111 = 3$.
- Birli toplama dili ($\Sigma = \{1, +, =\}$):
  - $\text{ADD} = \{x{+}y{=}z \mid x = 1^m, y = 1^n, z = 1^{m+n}\}$.
  - Örnek: $111{+}11{=}11111$ ve $1{+}11{=}111$. Bu sonsuz bir dildir.
- Birli kare alma dili ($\Sigma = \{1, \#\}$):
  - Hoca önce $y = 1^{2m}$ yazdı. Bir öğrenci bunun iki ile çarpma olduğunu fark etti. Hoca düzeltti: $y = 1^{m^2}$ olmalı.
  - $\text{SQUARE} = \{x\#y \mid x = 1^m, y = 1^{m^2}\}$. Örnek: $1\#1$, $11\#1111$, $111\#111111111$.
- Böylece her işlem bir küme olarak tanımlanabilir ve küme işlemleri kullanılabilir.

### Önek, sonek ve diğer notlar

- $w = \text{abracadabra}$ için "ra" bir sonek, "ab" bir önektir.
- $w = \text{abba}$ ise $\varepsilon w = w \varepsilon = w$. Bu yüzden $\varepsilon$ her dizginin öneki ve sonekidir.
- $\Sigma = \{a, b\}$ için $\Sigma^* = \{\varepsilon, a, b, aa, ab, \dots\}$, $\Sigma^+ = \{a, b, aa, ab, \dots\}$.
- Hoca $\Sigma^+ = \Sigma^* - \varepsilon$ yazdı, sonra düzeltti: fark iki küme arasında alınır, $\Sigma^+ = \Sigma^* - \{\varepsilon\}$.
- Asal sayılar dili: $\{x \mid x \in \Sigma^*, x \text{ asaldır}\}$, $\Sigma = \{0, \dots, 9\}$.
- Tümleyen örneği (tahtadan): $A = \{a, b, aaaa\}$ için $\overline{A} = \Sigma^* - A = \{\varepsilon, aa, bb, \dots\}$.
- Tahtada $\emptyset \neq \varepsilon$ yazıldı. Hoca önce eşittir yazdı, bir öğrenci uyardı.
- Hoca, boş dizgiyi içeren kümenin boş küme olmadığını, bir elemanı olduğunu söyledi: $|\{\varepsilon\}| = 1$.

### Ders sonrası notlar

- **Yıldız işleminin tanımı:** Tahtada $k > 0$ yazıldı ve hoca bir öğrencinin sorusu üzerine $A^*$'ın $\varepsilon$ içermediğini söyledi. Sipser'ın kitabında (Tanım 1.23) $k \geq 0$ alınır. Bu yüzden her $A$ için $\varepsilon \in A^*$'dır. Doğrusu: $A^* = \{\varepsilon, aa, bb, aaaa, aabb, bbaa, bbbb, \dots\}$. Hocanın tanımı aslında $A^+$'yı verir. Bu, dersin kendi notasyonu olan $x^* = \{\varepsilon, x, xx, \dots\}$ ve $\Sigma^+ = \Sigma^* - \{\varepsilon\}$ ile de uyumludur.
- **"aaa" $A^*$'da var mı?** Hoca $A = \{aa, bb\}$ için "aaa" gibi dizgilerin olabileceğini düşündü. $A$'daki her dizgi 2 uzunluktadır. Bu yüzden $A^*$'daki her dizginin uzunluğu çifttir; "aaa" $A^*$'da yoktur.
- **Düzenli dilin tanımı:** Hoca "düzenli dilin bir tanımı yok" dedi. Sipser'da düzenli dil şöyle tanımlanır (Tanım 1.16): Bir sonlu otomatın tanıdığı dil. Eşdeğer olarak, bir düzenli ifadeyle (regular expression) tanımlanabilen dildir. Yani tanım vardır ve doğrudan sonlu otomatlara dayanır.
- **Kapalılık listesi:** Sipser önce birleşim, birleştirme ve yıldızı ispatlar. Kesişim ve tümleyen için kapalılık da doğrudur; DFA'larla gösterilir.
- **Boş dizginin adı:** Hoca $\varepsilon$ için "null" adını önerdi. Kitapta ve yaygın kullanımda adı boş dizgidir (empty string). "Null" boş kümeyle karışabilir.
- **$\emptyset$ ve $\varepsilon$:** Biri küme, diğeri dizgidir; doğrudan karşılaştırılmaz. Kastedilen fark şudur: $\emptyset \neq \{\varepsilon\}$. $|\emptyset| = 0$ ama $|\{\varepsilon\}| = 1$. Örneğin $\emptyset^* = \{\varepsilon\}$ olur.
- **Dizgi gösterimi:** Hoca $w = w_1 w_2 \dots w_n$ yazarken "$n$ alfabededir" dedi. Doğrusu: her $w_i \in \Sigma$'dır.
- **Örnek seçimdeki ikinci ikili:** Hoca $\{1, 5, 6, 7, 10, 11, 3\}$ seçiminde yalnız $1 + 11$'in 12 ettiğini söyledi. $5 + 7 = 12$ de bu seçimdedir.
- **Güvercin yuvası örneği:** Python ile denendi. 1-11 arasından seçilen bütün 7'li gruplarda toplamı 12 olan bir ikili var. 6 sayı seçilince bu garanti yoktur (ör. $\{1, 2, 3, 4, 5, 6\}$).
- **Tümevarım örneği:** Formül $n = 1, \dots, 199$ için Python ile kontrol edildi, doğru.

**Not:** Bu ders İngilizce anlatılmıştır. İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
