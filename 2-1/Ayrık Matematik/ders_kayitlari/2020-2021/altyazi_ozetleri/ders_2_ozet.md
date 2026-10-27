# Ders 2 Çalışma Özeti

## Genel Konular

- Dersin tarihi 16 Ekim 2020 Cuma. Ders Zoom üzerinden yapıldı.
  - Asıl ders yaklaşık 00:06'da başlar. İlk dakikalar sohbet ve yüz yüze eğitim haberleri üzerinedir.
- Önceki dersin tekrarı
  - Önerme, bağlaçlar (AND, OR, XOR, NOT), doğruluk tablosu kurma, koşullu önerme.
  - İşlem önceliği: önce parantez ve olumsuzluk (De Morgan), sonra AND ve OR.
- Mantıksal denklik (logical equivalence)
  - Doğruluk tablosundaki sonuçları aynı olan iki önerme mantıksal olarak denktir: $p \equiv q$.
  - Örnek: $p \rightarrow q \equiv \lnot p \lor q$.
- Koşullu önermenin türevleri
  - Karşıt (converse): $q \rightarrow p$. $p \rightarrow q$ ile denk değildir.
  - Karşıt ters (contrapositive): $\lnot q \rightarrow \lnot p$. $p \rightarrow q$ ile denktir.
- Çift yönlü koşullu önerme (biconditional): $p \leftrightarrow q$, "ancak ve ancak", "if and only if".
  - $p \leftrightarrow q \equiv (p \rightarrow q) \land (q \rightarrow p)$.
- Totoloji (tautology) ve çelişki (contradiction).
- De Morgan kuralları ve bir alıştırma.
- Niceleyiciler (quantifiers)
  - Önerme fonksiyonu $P(x)$ ve tanım kümesi (domain of discourse, "ayrıntılı bilgi alanı").
  - Evrensel niceleyici (universal quantifier): $\forall x\, P(x)$, "her $x$ için".
  - Varoluşsal niceleyici (existential quantifier): $\exists x\, P(x)$, "en az bir $x$ için".
  - Karşı örnek (counterexample).
  - Doğal dil cümlelerini niceleyicilerle yazma.
  - Niceleyiciler için genelleştirilmiş De Morgan kuralı.
- İspatlar
  - Tanımlanmamış terim, tanım, aksiyom, teorem.
  - Doğrudan ispat (direct proof).
  - Karşıt tersle ispat (proof by contraposition), derste "dolaylı ispat" ve "olmayana ergi" olarak anıldı.
  - Tümevarımla ispat (mathematical induction).
- Bölüm sonu soru-cevap slaytları (Rosen alıştırmaları).

## Hocanın Özellikle Vurguladığı Kısımlar

- Bir ifadeyi doğruluk tablosuyla çözmek en güvenli yoldur.
  - Tabloyu bir kez kurarsanız, hoca hangi değerleri sorarsa sorsun cevap o satırdadır.
- Biconditional, XOR'un tam tersidir.
  - XOR'da girişler aynıysa 0, $\leftrightarrow$'da girişler aynıysa 1.
- Bir cümle için birden fazla doğru ifade yazılabilir. Doğru olanlar birbirine mantıksal olarak denk olmalıdır. Kontrol etmek için doğruluk tablosu kurun.
- Önermeleri olumlu biçimde tanımlayın. "You cannot ride" yerine $q$: "You can ride" alınır, olumsuzluk $\lnot q$ ile yazılır.
- Evrensel bir ifadeyi yanlış yapan tek bir örnek yeter. Bu örneğe karşı örnek denir.
- Cümlede "if", "only if", "necessary", "sufficient", "if and only if" gibi kalıplar yoksa $\rightarrow$ kullanmayın.
  - "but", "nevertheless" gibi bağlaçlar AND anlamına gelir.
- Bölüm sonundaki soruların cevapları AVESİS'te; mutlaka bakın.
- Sınav soruları Türkçe sorulacak.
- Sınıf arkadaşının yerine Zoom'a bağlanıp çıkmak, yoklamaya imza atmak gibidir. Hoca bunu hoş karşılamadığını söyledi.

## Kısa Tekrar Notları

- Mantıksal denklik: aynı girişlere aynı çıkış. Gösterim $\equiv$.
- $p \rightarrow q \equiv \lnot p \lor q \equiv \lnot q \rightarrow \lnot p$.
- Karşıtı $q \rightarrow p$ denk değildir.
- $p \leftrightarrow q$: girişler aynıysa 1. $\lnot(p \oplus q)$ ile aynıdır.
- Totoloji: bütün satırlarda 1. Çelişki: bütün satırlarda 0.
- De Morgan: $\lnot(p \lor q) \equiv \lnot p \land \lnot q$, $\lnot(p \land q) \equiv \lnot p \lor \lnot q$.
- $\forall x\, P(x)$ doğru: tanım kümesindeki her $x$ için $P(x)$ doğru. Sonlu kümede $P(x_1) \land \dots \land P(x_n)$ gibidir.
- $\exists x\, P(x)$ doğru: en az bir $x$ için $P(x)$ doğru. Sonlu kümede $P(x_1) \lor \dots \lor P(x_n)$ gibidir.
- $\lnot \forall x\, P(x) \equiv \exists x\, \lnot P(x)$, $\lnot \exists x\, P(x) \equiv \forall x\, \lnot P(x)$.
- Doğrudan ispat: $p$ doğru kabul edilir, $q$ gösterilir.
- Karşıt tersle ispat: $\lnot q$ doğru kabul edilir, $\lnot p$ gösterilir.
- Tümevarım: taban adımı (basis step) $P(1)$; tümevarım adımı (inductive step) $P(k) \Rightarrow P(k+1)$.
- Çift sayı $2k$, tek sayı $2k+1$ (veya $2k-1$) biçiminde yazılır.

## Detaylı Açıklamalar

### Mantıksal denklik

$p \rightarrow q$ ve $\lnot p \lor q$ tabloları aynıdır.

| $p$ | $q$ | $\lnot p$ | $\lnot p \lor q$ | $p \rightarrow q$ | $q \rightarrow p$ | $\lnot q \rightarrow \lnot p$ |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 1 | 1 | 0 | 1 | 1 | 1 | 1 |
| 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| 0 | 1 | 1 | 1 | 1 | 0 | 1 |
| 0 | 0 | 1 | 1 | 1 | 1 | 1 |

- $p \rightarrow q$ ile karşıt tersi aynı sütunu verir: denktir.
- Karşıtı $q \rightarrow p$ farklı sütun verir: denk değildir.
- Hocanın benzetmesi: "Şapka taksam, saçımı boyasam da yine aynı Banu'yum." Görünüş değişir, değer aynı kalır. $\frac{2}{4} = \frac{1}{2}$ gibi.
- $\lnot(\lnot A) \equiv A$. Lojik devrelerde bir kapının yerine denk bir kapı grubu kullanılabilir. İleride Karnaugh diyagramlarıyla sadeleştirme yapılacak.

### Biconditional ve XOR

| $p$ | $q$ | $p \oplus q$ | $p \leftrightarrow q$ | $(p \rightarrow q) \land (q \rightarrow p)$ |
| :---: | :---: | :---: | :---: | :---: |
| 1 | 1 | 0 | 1 | 1 |
| 1 | 0 | 1 | 0 | 0 |
| 0 | 1 | 1 | 0 | 0 |
| 0 | 0 | 0 | 1 | 1 |

### De Morgan alıştırması

Tahtaya $\big((p \land q)' \rightarrow (p \lor q)\big)'$ yazıldı, yani $\lnot\big(\lnot(p \land q) \rightarrow (p \lor q)\big)$. İki satır öğrencilerle hesaplandı.

- $p=1, q=0$: $\lnot(p \land q) = 1$, $p \lor q = 1$, $1 \rightarrow 1 = 1$, sonuç $0$.
- $p=1, q=1$: $\lnot(p \land q) = 0$, $0 \rightarrow 1 = 1$, sonuç $0$.

Bu ifadenin tam tablosu: $(p,q) = (0,0)$ için 1, diğer üç satır için 0.

### Roller coaster cümlesi

"You cannot ride the roller coaster if you are under 4 feet tall unless you are older than 16 years old."

- $q$: You can ride the roller coaster.
- $r$: You are under 4 feet tall.
- $s$: You are older than 16 years old.
- Doğru ifade (slayt): $(r \land \lnot s) \rightarrow \lnot q$.
- Anlamı: boyu 4 fitin altında ve 16 yaşından büyük değilsen binemezsin.

### Niceleyici örnekleri

- $\forall x \in \mathbb{R}$, $x^2 \geq 0$: doğru.
- $\forall x \in \mathbb{R}$, $x > 1 \rightarrow x + 1 > 1$: doğru.
- $\forall x \in \mathbb{R}$, $x \geq 0 \rightarrow x + 1 > 1$: yanlış. Karşı örnek $x = 0$.
- $\forall n$ çift pozitif tam sayı, $n^2 + n + 19$ asaldır: yanlış. Karşı örnek $n = 2$: $4 + 2 + 19 = 25$.
- $\exists x \in \mathbb{R}$, $\frac{x}{x^2+1} = \frac{2}{5}$: doğru. $x = 2$ (ayrıca $x = \frac{1}{2}$).
- $\exists n$ asal, $n+1, n+2, n+3, n+4$ asal değildir: doğru. $n = 23$: 24, 25, 26, 27 asal değil.

### Cümleleri niceleyicilerle yazma

- "Everyone has exactly one best friend."
  - $B(x,y)$: $y$, $x$'in en iyi arkadaşıdır.
  - $\forall x\, \exists y\, \big(B(x,y) \land \forall z\, ((z \neq y) \rightarrow \lnot B(x,z))\big)$.
  - "Tam olarak bir" ifadesi iki parçayla yazılır: en az biri var ve ondan farklı hiç kimse bu özelliği taşımıyor.
- "If somebody is female and is a parent, then this person is someone's mother."
  - $F(x)$: $x$ kadındır. $P(x)$: $x$ ebeveyndir. $M(x,y)$: $x$, $y$'nin annesidir.
  - $\forall x\, \big((F(x) \land P(x)) \rightarrow \exists y\, M(x,y)\big)$.
- "Every student in the class has taken a course in calculus."
  - Olumsuzu: "There is a student in this class who has not taken a course in calculus."
  - $\lnot \forall x\, P(x) \equiv \exists x\, \lnot P(x)$.

### İspat terimleri

- Tanımlanmamış terim: sistemin başlangıç kavramı. Örnek: nokta, doğru.
- Tanım: önceden kabul edilmiş kavramlarla yeni bir kavram kurmak. Örnek: bütünler açılar.
- Aksiyom: ispatsız doğru kabul edilen önerme. Örnek: iki noktadan bir doğru geçer.
- Teorem: aksiyom, tanım ve önceki teoremlerle ispatlanan $p \rightarrow q$ biçiminde önerme.

### Doğrudan ispat: $n$ çift ise $n^2$ çifttir

1. $n$ çift olsun: $n = 2k$, $k \in \mathbb{Z}$.
2. $n^2 = (2k)^2 = 4k^2 = 2(2k^2)$.
3. $u = 2k^2$ bir tam sayıdır. $n^2 = 2u$ çifttir.

### Karşıt tersle ispat: $n^2$ tek ise $n$ tektir

- Karşıt tersi: $n$ çift ise $n^2$ çifttir. Bu yukarıda ispatlandı.
- Karşıt ters doğru olduğu için orijinal önerme de doğrudur.

### Karşıt tersle ispat: $3n + 2$ tek ise $n$ tektir

- Karşıt tersi: $n$ çift ise $3n + 2$ çifttir.
- $n = 2k$: $3n + 2 = 6k + 2 = 2(3k + 1)$. Çifttir.

### Tümevarım örnekleri

**1) $1 + 2 + \dots + n = \frac{n(n+1)}{2}$**

- Taban: $n = 1$ için $\frac{1 \cdot 2}{2} = 1$.
- Varsayım: $1 + \dots + k = \frac{k(k+1)}{2}$.
- Adım: $\frac{k(k+1)}{2} + (k+1) = \frac{k^2 + 3k + 2}{2} = \frac{(k+1)(k+2)}{2}$.

**2) İlk $n$ tek sayının toplamı $n^2$'dir: $1 + 3 + \dots + (2n-1) = n^2$**

- Taban: $n = 1$ için $1 = 1^2$.
- Adım: $k^2 + (2(k+1) - 1) = k^2 + 2k + 1 = (k+1)^2$.

**3) $n^3 - n$, 3'e bölünür**

- Taban: $n = 1$ için $0$; $n = 2$ için $6$.
- Adım: $(k+1)^3 - (k+1) = (k^3 - k) + 3(k^2 + k)$.
- İlk parça varsayım gereği 3'e bölünür. İkinci parça 3'ün katıdır. Toplam 3'e bölünür.

### Bölüm sonu soru-cevaplar

- "not" kullanmadan olumsuz yazma:
  - "Today is Thursday" → "Today is Monday or Tuesday or Wednesday or Friday or Saturday or Sunday."
  - "$2 + 1 = 3$" → "$2 + 1 < 3$ or $2 + 1 > 3$."
  - "There is no wind in Illinois" → "Illinois is windy."
- $p$: finalden A almak, $q$: kitaptaki her alıştırmayı yapmak, $r$: dersten A almak.
  - "Dersten A aldın ama her alıştırmayı yapmadın": $r \land \lnot q$.
  - "Finalden A aldın, her alıştırmayı yaptın ve dersten A aldın": $p \land q \land r$.
  - "Finalden A aldın ama her alıştırmayı yapmadın; yine de dersten A aldın": $p \land \lnot q \land r$.
- "if p then q" biçimine çevirme: "Joey will pass the exam if he studies hard" → "If Joey studies hard, then he will pass the exam."
- $p$ doğru, $q$ yanlış, $r$ bilinmiyor iken $p \lor r$ doğrudur; $r$ ne olursa olsun.
- $(\lnot p \land (p \rightarrow q)) \rightarrow \lnot q$ totoloji değildir. $p = 0, q = 1$ satırında 0'dır.
- Tam sayılarda karşı örnek:
  - $\forall x\, \exists y\, (x = 1/y)$: $x = 0$ için uygun $y$ yok.
  - $\forall x\, \exists y\, (y^2 - x < 100)$: $x \leq -100$ için uygun $y$ yok.
  - $\forall x\, \forall y\, (x^2 \neq y^3)$: $x = y = 0$ veya $x = y = 1$.
- $n$ pozitif tam sayı: $n$ çift $\leftrightarrow$ $7n + 4$ çift.
  - $n = 2k$: $7n + 4 = 14k + 4 = 2(7k + 2)$.
- Sherlock Holmes paragrafı dört önermeyle yazıldı.
  - $p$: Holmes başarılı, $q$: profesör yakalanır, $r$: Watson hata yapar, $s$: Holmes ipucunu bulur.
  - $p \rightarrow q$, $\lnot r \rightarrow s$, $s \rightarrow p$, $\lnot r$; bu nedenle $q$.
- Gerçel sayılarda:
  - $\forall x\, (x^2 > x)$: yanlış. Karşı örnek $x = \frac{1}{2}$ (veya $x = 1$).
  - $\exists x\, (x > 1 \rightarrow x^2 > x)$: doğru.
  - $\forall x\, \forall y\, (x^2 < y + 1)$: yanlış. Karşı örnek $x = 2, y = 0$.
  - $\exists x\, \exists y\, (x^2 + y^2 = 9)$: doğru. $x = 1, y = \sqrt{8}$.

### Ders sonrası notlar

- **Soru cümleleri önerme değildir.** Tekrarda "Bugün hava güneşli mi?" ve "Okullar açılacak mı?" önerme sayıldı. Önerme, doğru ya da yanlış olan bildirme cümlesidir. "Bugün hava güneşli" bir önermedir; soru biçimi değildir.
- **Varoluşsal niceleyicide bütün elemanlar sağlarsa ifade yine doğrudur.** Derste "kümedeki bütün elemanlar sağlarsa o zaman false olur" dendi. Yanlış. $\exists x\, P(x)$ için en az bir eleman yeter; hepsi sağlıyorsa da doğrudur. Ders sonundaki öğrenci sorusunda hoca bunu doğru biçimde onayladı.
- **"Necessary" yönü.** Slaytta "To get an A in this class, it is necessary for you to get an A on the final" için $p \rightarrow r$ yazıyor. "Gerekli" koşul sonuç tarafına gider. Doğrusu $r \rightarrow p$: dersten A aldıysan finalden A almışsındır.
- **Roller coaster için ikinci ifade denk değildir.** Derste $(\lnot r \lor s) \rightarrow q$ da doğru bir çözüm olarak gösterildi. Bu ifade ilkinin tersidir (inverse) ve denk değildir. Python ile 8 satır kontrol edildi; 4 satırda sonuçlar farklı. Örneğin boyu uzun ($r = 0$) ama binemeyen ($q = 0$) biri için asıl kural ihlal edilmez, ikinci ifade ise yanlış olur. Cümle yalnız kimin binemeyeceğini söyler, kimin kesin binebileceğini söylemez.
- **"Today is Thursday" olumsuzu altı günün hepsini içermeli.** Sözlü cevapta yalnız Pazartesi, Salı, Çarşamba sayıldı. Slayttaki cevap doğru: Cuma, Cumartesi, Pazar da eklenir.
- **"Hot and muggy" olumsuzu De Morgan ister.** "The summer in Champaign is hot and muggy" cümlesinin olumsuzu "not hot **or** not muggy" olur. "not" kullanmadan örneğin: "The summer in Champaign is cool or it is dry." Zıt kelimeleri "and" ile bağlamak ("cool and dry") yanlıştır.
- **Karşıt tersle ispat ile olmayana ergi farklıdır.** Derste ikisi aynı ad altında anlatıldı. Karşıt tersle ispatta $\lnot q \rightarrow \lnot p$ doğrudan ispatlanır. Olmayana ergide (proof by contradiction) $p \land \lnot q$ varsayılır ve bir çelişkiye ulaşılır.
- **"$p$ tarafı karmaşıksa doğrudan ispat yapılamaz" bir kural değildir.** Bu durumda doğrudan ispat genellikle zordur, karşıt ters daha kolaydır. Ama doğrudan ispat imkânsız değildir.
- **Karşı örnek bulmak "olmayana ergi" değildir.** $n^2 + n + 19$ örneğinde yapılan, evrensel önermeyi tek bir karşı örnekle çürütmektir.
- **Slayt 49'daki hata.** Slaytta $u = 2k$ için $n^2 = 2 \cdot 2k^2 = 2u^2$ yazıyor. $u = 2k$ ise $2u^2 = 8k^2$ olur, yanlıştır. Bir öğrenci hatayı yakaladı. Doğrusu: $u = 2k^2$ alınır, $n^2 = 2u$ olur.
- **Derste "dolaylı ispatla yaptım" dendi.** $n$ çift ise $n^2$ çifttir örneği doğrudan ispattır.
- **$3n + 2$ hesabı.** $3(2k) + 2 = 6k + 2 = 2(3k + 1)$. Derste ortak çarpan parantezi sözlü olarak karıştı.
- **Tek sayılar örneğinde.** $k^2 + 2k + 1 = (k+1)^2$; derste bir yerde "$2k^2$" dendi.
- **$7n + 4$ örneği iki yönlüdür.** "ancak ve ancak" için iki yön de ispatlanmalı. Derste yalnız $n$ çift ise $7n + 4$ çift yönü gösterildi. Diğer yön karşıt tersle: $n = 2k + 1$ ise $7n + 4 = 14k + 11 = 2(7k + 5) + 1$ tektir.
- **"Female and parent" çevirisi.** Derste "parent" "evli" diye çevrildi. Doğrusu "ebeveyn"dir.
- **De Morgan slaytındaki oklar.** Slaytta $\lnot(p \lor q) \rightarrow (\lnot p) \land (\lnot q)$ yazıyor. Burada ok, koşullu önerme değil denklik anlamındadır; doğru gösterim $\equiv$. Hoca da bunu belirtti.
- **Doğrulama.** Denklikler, roller coaster tablosu, totoloji tablosu, $n^3 - n$, toplam formülleri ve karşı örnekler Python ile kontrol edildi.
- **Altyazı hataları:** "Bağınlı" Banu Diri, "aksiyon" aksiyom, "Champaign hot and muddy" slaytta "hot and muggy"dir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
