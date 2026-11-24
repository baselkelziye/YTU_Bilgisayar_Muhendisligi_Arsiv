# Ders 2 Çalışma Özeti

## Genel Konular

- Koşullu önermenin (ise bağlacı) tekrarı
  - $p \rightarrow q$ yalnız $p$ doğru, $q$ yanlış iken yanlıştır. Diğer üç durumda doğrudur. $p$'ye hipotez, $q$'ya sonuç denir.
  - Yeterli şart hipotez tarafıyla, gerekli şart sonuç tarafıyla ilgilidir. Bu iki kavram ispatlarda kullanılır.
  - Temel bağlaçlarla yazılışı: $p \rightarrow q \equiv \lnot p \lor q$ (ekrandan, 00:20:00).
- Mantıksal denklik (logical equivalence)
  - Doğruluk tablosundaki değerleri aynı olan iki önerme arasında mantıksal denklik vardır.
  - $\lnot p \lor q$ ile $p \rightarrow q$ sütunları T, F, T, T olarak birebir aynıdır (ekrandan, 00:20:00).
- Koşullu önermenin türevleri
  - Karşıt (converse): $q \rightarrow p$. Asıl önermeyle denk değildir. Örnek: "Bugün cumartesi ise yarın pazardır" önermesinin karşıtı "Yarın pazarsa bugün cumartesidir".
  - Karşıt ters (contrapositive): $\lnot q \rightarrow \lnot p$. Asıl önermeyle mantıksal olarak denktir: "Yarın pazar değilse bugün cumartesi değildir". Dolaylı ispatta kullanılır.
  - Ters (inverse): $\lnot p \rightarrow \lnot q$: "Bugün cumartesi değilse yarın pazar değildir".
- Çift yönlü koşullu önerme
  - $p \leftrightarrow q$ yalnız iki taraf aynı değeri aldığında doğrudur.
  - $p \leftrightarrow q \equiv (p \rightarrow q) \land (q \rightarrow p) \equiv (\lnot p \lor q) \land (\lnot q \lor p)$.
- Totoloji ve çelişki
  - Doğruluk tablosunun bütün sonuçları doğruysa totoloji, hepsi yanlışsa çelişkidir. Örnek totoloji: $p \rightarrow (p \lor q)$.
- De Morgan kanunu (ekrandan, 00:25:00)
  - $\lnot(p \lor q) \equiv \lnot p \land \lnot q$, $\lnot(p \land q) \equiv \lnot p \lor \lnot q$.
  - Değil alınınca her önermenin değili alınır, $\lor$ ile $\land$ yer değiştirir.
- Niceleyiciler (quantifiers)
  - Önerme fonksiyonu $P(x)$: tanım kümesindeki (domain of discourse, $D$) her $x$ değeri $P(x)$'i doğru ya da yanlış bir önerme yapar.
  - Evrensel niceleyici $\forall x\, P(x)$: her $x$ için $P(x)$ doğrudur. Gizli bir VE (çarpım, kesişim) işlemidir: $P(x_1) \land P(x_2) \land \dots \land P(x_n)$.
  - Varoluşsal niceleyici $\exists x\, P(x)$: en az bir $x$ için $P(x)$ doğrudur. Gizli bir VEYA (toplam, birleşim) işlemidir.
  - Karşı örnek: $\forall x\, P(x)$ önermesini yanlış yapan tek bir $x$ değeri yeterlidir.
  - Cümleleri niceleyicilerle yazma: "Herkesin tam olarak bir en iyi arkadaşı vardır", "Kadın ve ebeveyn olan herkes birinin annesidir".
- Niceleyiciler için De Morgan kuralı
  - $\lnot \forall x\, P(x) \equiv \exists x\, \lnot P(x)$ ve $\lnot \exists x\, P(x) \equiv \forall x\, \lnot P(x)$.
- İspatın temelleri
  - Tanımlanmamış terim (nokta, doğru), tanım, aksiyom ve teorem kavramları.
- İspat yöntemleri
  - Doğrudan ispat (direct proof).
  - Dolaylı ispat / olmayana ergi (karşıt tersle ispat, contraposition).
  - Çelişki ile ispat (proof by contradiction).
  - Tümevarım (mathematical induction).
  - Karşı örnek (counterexample) ile yanlışlığı gösterme.
  - Deneme yanılma / kaba kuvvet (brute force) ile sonlu kümede ispat.
- Çıkarım örneği: Sherlock Holmes problemi (hipotezlerden sonuç çıkarma).

## Hocanın Özellikle Vurguladığı Kısımlar

- Koşullu önerme önemlidir
  - Hem mantıkta hem programlamada hem de ispatlarda çok kullanılır.
- Karşıt ters asıl önermeyle denktir, karşıt değildir
  - Dolaylı ispat bu denkliğe dayanır. Hoca denkliği doğruluk tablosuyla yeniden gösterdi.
- De Morgan kuralı programlamada da işe yarar
  - Uzun ve okunması zor bir `if` koşulunun değilini De Morgan ile daha kısa yazmak mümkündür.
- Bir şeyin yokluğu doğrudan ispat edilmez
  - Sonsuz bir kümede bütün değerleri denemek mümkün değildir. Örnek olarak $a^4 + b^4 + c^4 = d^4$ denkleminin çözümü olmadığı iddiası verildi; bu iddia bilgisayarlarla karşı örnek bulunarak çürütüldü.
- "Falancanın teoremine göre böyledir" demek ispat değildir
  - İspat, bilimsel yöntemlerle (doğrudan, dolaylı, çelişki, tümevarım vb.) adım adım yapılır. Başka birine dayanan sonuç, gerekçesi gösterilmezse ispat sayılmaz.
- Olumsuzu ile tersi aynı şey değildir
  - "$n^2$ tek sayıdır" önermesinin değili "$n^2$ çift sayıdır" olur, çünkü başka durum yoktur.
- Soru çözerken izlenecek yol
  - Önce hangi yöntemin kullanılacağına karar verilip gerekçesi yazılır, sonra $p$ ve $q$ belirlenir, ardından ispat adımları (1, 2, 3) ve sonuç yazılır.
- Tümevarımda ilk adım yanlışsa devam edilmez
  - "Düğmeyi yanlış iliklerseniz" sonraki adımlar da yanlışa götürür.
- Çelişki ile karşı örnek farklıdır
  - Karşı örnekte önermenin değili alınmaz, De Morgan uygulanmaz; doğrudan önermeyi bozan tek bir örnek gösterilir.

## Kısa Tekrar Notları

- $p \rightarrow q \equiv \lnot p \lor q$; yalnız $1 \rightarrow 0$ yanlıştır.
- Karşıt: $q \rightarrow p$ (denk değil). Ters: $\lnot p \rightarrow \lnot q$ (denk değil). Karşıt ters: $\lnot q \rightarrow \lnot p$ (denk).
- $p \leftrightarrow q \equiv (p \rightarrow q) \land (q \rightarrow p)$.
- De Morgan: $\lnot(p \lor q) \equiv \lnot p \land \lnot q$, $\lnot(p \land q) \equiv \lnot p \lor \lnot q$.
- $\forall$ gizli VE, $\exists$ gizli VEYA'dır.
- $\lnot \forall x\, P(x) \equiv \exists x\, \lnot P(x)$; $\lnot \exists x\, P(x) \equiv \forall x\, \lnot P(x)$.
- Çift sayı biçimi $2k$, tek sayı biçimi $2k+1$ ($k \in \mathbb{Z}$).
- Doğrudan ispat: $p$ doğru kabul edilir, $q$'nun doğruluğu gösterilir, $p \rightarrow q$'nun doğruluğu söylenir.
- Dolaylı ispat: $\lnot q \rightarrow \lnot p$ doğrudan ispatlanır; bu doğruysa $p \rightarrow q$ da doğrudur.
- Çelişki ile ispat: $\lnot(p \rightarrow q) \equiv p \land \lnot q$ kabul edilir ve bunun yanlış olduğu gösterilir.
- Tümevarım: temel adım ($n=1$), tümevarım adımı ($n=k$ doğru kabul, $n=k+1$ ispat), sonuç.
- Karşı örnek: "Tüm asal sayılar tektir" önermesi $2$ ile çürür.
- Kaba kuvvet: sonlu kümede her eleman tek tek denenir.

## Detaylı Açıklamalar

- Koşullu önerme ve denklik
  - Koşullu önermenin doğruluk tablosu ezberlenebilir (yalnız $1 \rightarrow 0$ durumunda $0$), ama arkasındaki mantık bir şartın gerçekleşmesiyle diğer şartın gerçekleşmesi arasındaki ilişkidir. Hipotez olmadan da sonuç doğru olabilir ($0 \rightarrow 1$ durumu doğrudur).
  - $\lnot p \lor q$ ifadesinin doğruluk tablosu çıkarıldığında $p \rightarrow q$ sütunuyla aynı çıkar. Bu yüzden ikisi mantıksal olarak denktir ve ise bağlacı NOT, AND, OR cinsinden yazılabilir.
  - Karşıtta satırlar yer değiştirdiği için denklik bozulur. Karşıt terste hem yer değişir hem değil alınır ve tablo asıl önermeyle aynı kalır.
  - Derste bir alıştırma olarak $p \leftrightarrow p$ benzeri ifadelerin sonucu soruldu; iki taraf aynıysa sonuç $1$ olur. Bir başka ifadenin sonucunun doğrudan $p$'ye eşit olduğu, yani $p$ $0$ ise $0$, $1$ ise $1$ olduğu gösterildi. <!-- BELİRSİZ: Bu iki alıştırmadaki ifadelerin tam yazılışı altyazıdan çıkmıyor ve o anlara ait kare yok. -->
- Niceleyiciler
  - Örnek (ekrandan, 00:30:00): $P(n)$: "$n^2 + 2n$ tek sayıdır", $D$ pozitif tam sayılar ($\mathbb{Z}^+$). $n$ tek ise $n^2 + 2n$ tektir, $n$ çift ise tek değildir. Bu yüzden $\forall n\, P(n)$ bütün tam sayılarda doğru değildir; tanım kümesi tek tam sayılar alınırsa doğru olur.
  - Örnek (ekrandan, 00:30:00): "Bu sınıftakiler 18 yaşından büyüktür." $D$ sınıftaki öğrencilerdir; bazı öğrenciler önermeyi doğru, bazıları yanlış yapabilir.
  - "Her gerçel $x$ için $x^2 \ge 0$" doğrudur (ekrandan, 00:35:00). "Her gerçel $x$ için $x^2 \ge 1$" yanlıştır; $-1 < x < 1$ aralığındaki sayılar (örneğin $0{,}9$) karşı örnektir.
  - "Bazı gerçel $x$ için $\dfrac{x}{x^2+1} = \dfrac{2}{5}$" doğrudur; $x = 2$ bunu sağlar (ekrandan, 00:45:00).
  - "Bazı pozitif tam sayılar $n$ için, $n$ asal ise $n+1, n+2, n+3, n+4$ asal değildir" doğrudur: $n = 23$ için $24, 25, 26, 27$ asal değildir.
  - Varoluşsal niceleyici, bir problemin çözümünün var olduğunu ya da önermeyi doğru yapan en az bir eleman bulunduğunu ifade eder.
- Cümleleri mantıksal ifadeye çevirme
  - Lunapark sorusu (ekrandan, 00:40:00): $q$: "lunaparktaki trene binebilirsin", $r$: "boyun 4 feet'in altında", $s$: "16 yaşından büyüksün". "16 yaşından büyük değilsen, boyun 4 feet'in altındaysa trene binemezsin" cümlesi $(r \land \lnot s) \rightarrow \lnot q$ olarak yazılır. Slaytta ikinci yazılış olarak $(\lnot r \lor s) \rightarrow q$ verilmiştir.
  - Ders sonrası not: $(\lnot r \lor s) \rightarrow q$, $(r \land \lnot s) \rightarrow \lnot q$ önermesinin tersidir (inverse), karşıt tersi değildir. Bu yüzden ikisi mantıksal olarak denk değildir (python ile doğruluk tablosu karşılaştırıldı). Denk yazılış karşıt terstir: $q \rightarrow (\lnot r \lor s)$.
  - "Herkesin tam olarak bir en iyi arkadaşı vardır": $B(x,y)$ "$y$, $x$'in en iyi arkadaşıdır" olsun. $\forall x\, \exists y\, \big(B(x,y) \land \forall z\, ((z \ne y) \rightarrow \lnot B(x,z))\big)$.
  - "Kadın ve ebeveyn olan herkes birinin annesidir" (ekrandan, 00:50:00): $F(x)$ "$x$ kadındır", $P(x)$ "$x$ ebeveyndir", $M(x,y)$ "$x$, $y$'nin annesidir". $\forall x\, \big((F(x) \land P(x)) \rightarrow \exists y\, M(x,y)\big)$.
- Niceleyicilerde değil alma (ekrandan, 00:55:00)
  - "Sınıftaki her öğrenci kalkülüs dersi almıştır" $\forall x\, P(x)$ biçimindedir. Değili "Sınıfta kalkülüs dersi almamış bir öğrenci vardır", yani $\exists x\, \lnot P(x)$ olur. Bu yorum, "her öğrencinin aldığı durum değildir" demekten daha kolay anlaşılır.
  - Tersi de geçerlidir: "Sınıfta kalkülüs almış bir öğrenci vardır" $\exists x\, Q(x)$ önermesinin değili $\forall x\, \lnot Q(x)$, yani "Sınıftaki hiçbir öğrenci kalkülüs almamıştır" olur.
- İspatın temelleri
  - Tanımlanmamış terimler (nokta, doğru) kabullerle ortaya konur. Tanım, önceden kabul edilmiş kavramlar ve tanımlanmamış terimlerden yeni bir kavram oluşturan önermedir (ekrandan, 01:15:00): karşılıklı kenar ve açıları aynı olan üçgenler eş üçgendir; toplamı 180 derece olan açılar birbirini tamamlayan açılardır.
  - Aksiyom, ispat yapılmadan doğru kabul edilen önermedir: iki noktadan geçen bir doğru vardır; bir doğru ve üzerinde olmayan bir noktadan geçen doğrulardan biri verilen doğruya paraleldir.
  - Teorem, aksiyomlar, tanımlar ve önceden ispatlanmış teoremler kullanılarak $p$ doğru kabul edildiğinde $p \rightarrow q$ biçiminde ispatlanan önermedir.
- Doğrudan ispat (ekrandan, 01:25:00 ve 01:30:00)
  - Genellikle $p$ daha basit, $q$ daha karmaşık bir ifadedir.
  - Örnek: "$n$ çift ise $n^2$ çifttir." $n = 2k$, $k \in \mathbb{Z}$ doğru kabul edilir. $n^2 = 4k^2 = 2(2k^2)$; $p = 2k^2 \in \mathbb{Z}$ denirse $n^2 = 2p$ olur. Bu çift sayı biçimi olduğundan $n^2$ çifttir.
  - "$n^2$ çift ise $n$ çifttir" doğrudan ispatla yapılamaz: $n^2 = 2k$'dan $n = \sqrt{2k}$ elde edilir ve buradan tam sayı biçimi çıkmaz.
- Dolaylı ispat (karşıt ters)
  - Örnek: "$n^2$ tek ise $n$ tektir." Karşıt tersi "$n$ çift ise $n^2$ çifttir" olur. $n = 2k$, $n^2 = 4k^2 = 2(2k^2) = 2u$, $u \in \mathbb{Z}$; $n^2$ çifttir. Karşıt ters doğru olduğundan asıl önerme de doğrudur.
  - Slayt örneği: "$3n + 2$ tek ise $n$ tektir." Doğrudan denenince $3n + 1 = 2k$ elde edilir ve $n$ hakkında sonuç çıkmaz. Karşıt ters: $n = 2k$ ise $3n + 2 = 6k + 2 = 2(3k + 1)$ çifttir.
- Çelişki ile ispat (ekrandan, 01:40:00 ve 01:45:00)
  - $p \rightarrow q$ için $\lnot(\lnot p \lor q) \equiv p \land \lnot q$ yazılır ve bunun yanlış olduğu ispatlanır.
  - Örnek: "$n$ tek ise $n^2$ tektir." $p \land \lnot q$ kabulü: "$n$ tek ve $n^2$ çift". $n = 2k + 1$ ise $n^2 = 4k^2 + 4k + 1 = 2(2k^2 + 2k) + 1 = 2t + 1$; $n^2$ tektir. $\lnot q$ yanlış çıktığından $p \land \lnot q = 1 \land 0 = 0$ olur, dolayısıyla $p \rightarrow q$ doğrudur.
  - Bu yöntem, "$\sqrt{2}$ irrasyoneldir" gibi önermelerde kullanılır: irrasyonel olduğunu göstermek yerine rasyonel olmadığı gösterilir.
- Tümevarım
  - Merdiven benzetmesi: bir basamağın sağlamlığı bir öncekine bağlıdır.
  - Örnek (ekrandan, 02:00:00 ve 02:10:00): $1 + 2 + \dots + n = \dfrac{n(n+1)}{2}$. $n=1$: $\dfrac{1 \cdot 2}{2} = 1$. $n=k$ için doğru kabul edilir. $n=k+1$: $\dfrac{k(k+1)}{2} + (k+1) = \dfrac{(k+1)(k+2)}{2}$; doğrudur.
  - Yanlış bir formülde ($\dfrac{n(n+3)}{2}$) daha ilk adımda $\dfrac{1 \cdot 4}{2} = 2 \ne 1$ çıkar; tümevarım adımı da tutmaz.
  - Slayt örneği: $n^3 - n$ her pozitif $n$ için $3$'e bölünür. $(k+1)^3 - (k+1) = (k^3 - k) + 3(k^2 + k)$.
- Karşı örnek ve kaba kuvvet
  - "Her gerçel $x$ için $x^2 > 0$" önermesi $x = 0$ ile yanlıştır.
  - Kaba kuvvet (ekrandan, 02:30:00): $x \in \{-1, 0, 1\}$ için $x^2 < 4$: $((-1)^2 < 4) \land (0^2 < 4) \land (1^2 < 4) = T \land T \land T = T$.
- Çıkarım: Sherlock Holmes (ekrandan, 02:25:00)
  - $p$: Sherlock Holmes başarılıdır, $q$: Profesör Albert yakalanır, $r$: Dr. Watson hata yapar, $s$: Sherlock Holmes kayıp ipucunu bulur.
  - Hipotezler: $p \rightarrow q$, $\lnot r \rightarrow s$, $s \rightarrow p$, $\lnot r$. Sonuç: $q$. ($\lnot r$ ile $s$, $s$ ile $p$, $p$ ile $q$ elde edilir.)

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
