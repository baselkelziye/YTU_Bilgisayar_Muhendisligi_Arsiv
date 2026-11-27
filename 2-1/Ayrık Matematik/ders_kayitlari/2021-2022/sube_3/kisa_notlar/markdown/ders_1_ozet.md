# Ders 1 Çalışma Özeti

## Genel Konular

- Mantığın amacı
  - Mantık, doğru çıkarım (inference) yapmayı inceler. Matematikte özellikle ispatlarda kullanılır; örneğin $1+2+\dots+n = \frac{n(n+1)}{2}$ eşitliğinin doğruluğu ispat teknikleriyle gösterilir ve ispat teknikleri için önce mantık kavranmalıdır.
  - Bilgisayar biliminde bir programın beklenen sonucu üretip üretmediğini incelemekte ve koşullu/tekrarlı yapılardaki mantıksal ifadeleri yazmakta kullanılır.
- Önerme (proposition)
  - Bir hüküm içeren, sonucu ya doğru ya yanlış olan ifadedir. Olasılık söz konusu değildir.
  - Önermeler $p, q, r, s, t$ gibi harflerle gösterilir. Birden fazla önerme bağlaçlarla (connectives) birleştirilerek birleşik önerme elde edilir.
- Doğruluk tablosu (truth table)
  - $n$ önerme için $2^n$ durum vardır. True yerine 1, false yerine 0 yazılır.
  - Hoca tabloyu 0'dan başlatmayı önerir: en sağdaki sütun her satırda, bir soldaki iki satırda bir, sonraki dört satırda bir değişir (basamak değerleri $2^0, 2^1, 2^2$).
- Temel bağlaçlar: AND ($\land$, ve, conjunction), OR ($\lor$, veya, inclusive or, disjunction), NOT ($\lnot$, değil, negation)
  - AND: bütün önermeler doğruysa sonuç 1; seri bağlı anahtarlar devresiyle gösterilir.
  - OR: en az bir önerme doğruysa sonuç 1; paralel bağlı anahtarlar devresiyle gösterilir.
  - NOT: tek operandlı (unary) bir işlemdir; değeri tersine çevirir. Gösterimleri: $\lnot p$, $\sim p$, $\bar p$, $p'$.
  - İşlem önceliğinde NOT önce gelir.
- Türetilmiş bağlaçlar: XOR, ise (implication), ancak ve ancak (biconditional)
  - XOR ($\veebar$, $\oplus$, "ya da"): girişler aynıysa 0, farklıysa 1.
  - $p \oplus q \equiv (\lnot p \land q) \lor (p \land \lnot q)$ (ekrandan, 00:35:00).
  - Kriptografide şifreli mesaj $=$ mesaj $\oplus$ anahtar; şifreli mesaj $\oplus$ anahtar $=$ mesaj (ekrandan, 00:35:00).
  - Koşullu önerme $p \Rightarrow q$: $p$ hipotez (antecedent), $q$ sonuç (consequent, conclusion). Yalnız $p=1, q=0$ durumunda 0'dır.
  - $p \Rightarrow q \equiv \lnot p \lor q$ (ekrandan, 00:55:00).
  - Çift yönlü koşullu önerme $p \Leftrightarrow q$ (if and only if, ancak ve ancak): iki değer aynıysa 1. XOR'un tersidir.
  - $p \Leftrightarrow q \equiv (p \Rightarrow q) \land (q \Rightarrow p) \equiv (\lnot p \lor q) \land (\lnot q \lor p)$.
- Karşıt, ters ve devrik
  - Converse (karşıt): $q \Rightarrow p$. Inverse (ters): $\lnot p \Rightarrow \lnot q$. Contrapositive (devrik): $\lnot q \Rightarrow \lnot p$ (ekrandan, 01:15:00).
  - Yalnız devrik, $p \Rightarrow q$ ile mantıksal olarak denktir.
- Gereklilik ve yeterlilik
  - $p \Rightarrow q$ önermesinde $p$ yeterli koşul (sufficient condition), $q$ gerekli koşuldur (necessary condition).
- Mantıksal denklik, totoloji ve çelişki
  - İki önermenin doğruluk tablosundaki sonuç sütunları aynıysa mantıksal olarak denktir ($\equiv$).
  - Her durumda doğru olan birleşik önerme totoloji, her durumda yanlış olan çelişkidir (contradiction).
- De Morgan kanunu
  - $\lnot(p \lor q) \equiv \lnot p \land \lnot q$, $\lnot(p \land q) \equiv \lnot p \lor \lnot q$ (ekrandan, 01:40:00).
- Niceleyiciler (quantifiers)
  - Önerme fonksiyonu $P(x)$ ve tanım kümesi (domain of discourse).
  - Evrensel niceleyici $\forall x\, P(x)$ ("her $x$ için") ve varoluşsal niceleyici $\exists x\, P(x)$ ("bazı $x$ için", "en az bir $x$ için").
  - Karşı örnek (counterexample) ve niceleyiciler için De Morgan kuralı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Koşullu önermenin tablosunu kısa yoldan hatırlamak
  - Yalnız "1 ise 0" durumu 0'dır: hipotez gerçekleşmiş ama sonuç gerçekleşmemiştir. Diğer üç durum 1'dir.
  - Örnek: "Seçilirsem maaşa zam yaparım." Seçilmeyip zam yapmamak da, seçilmeyip zam yapmak da tutarsız değildir; yalnız seçilip zam yapmamak yanlıştır.
- $p \Rightarrow q \equiv \lnot p \lor q$ dönüşümü "çok önemli"
  - Bir ifadede "ise" görüldüğünde bu biçime çevrilerek problem çözülebilir; bunun tersi de geçerlidir.
- $p \Rightarrow q$ ile $q \Rightarrow p$ denk değildir; hipotez ve sonuç yer değiştiremez.
- Olumsuzu alırken dikkat
  - $x > 2$ önermesinin değili $x \le 2$'dir. Bu tür nüanslarda sık hata yapılır.
- De Morgan, koşul yazarken işlem sayısını azaltmak için kullanılabilir (C'de `if (!(A && B))` yerine `if (!A || !B)` gibi ifadelerin karşılaştırılması).
- Doğruluk tablosunu 0-0'dan başlatmak, ileride lojik devreler ve Karnaugh haritalarında da kullanılan düzen olduğu için önerilir.
- "Her" ile başlayan bir önermenin yanlış olduğunu göstermek için tek bir karşı örnek yeterlidir.

## Kısa Tekrar Notları

- Önerme: doğru ya da yanlış olan hüküm cümlesi.
- $n$ önerme $\Rightarrow$ $2^n$ satırlık doğruluk tablosu.
- AND: hepsi 1 ise 1. OR: en az biri 1 ise 1. NOT: tersler.
- AND özdeşlikleri: $p \land 0 = 0$, $p \land 1 = p$, $p \land p = p$, $p \land \lnot p = 0$, $p \land q = q \land p$.
- OR özdeşlikleri: $p \lor 1 = 1$, $p \lor 0 = p$, $p \lor p = p$, $p \lor \lnot p = 1$.
- XOR özdeşlikleri (ekrandan, 00:40:00): $p \oplus q = q \oplus p$, $p \oplus p = 0$, $p \oplus \lnot p = 1$, $p \oplus 1 = \lnot p$ (ters çevirme), $p \oplus 0 = p$ (kopyalama).
- İse özdeşlikleri (ekrandan, 01:00:00): $p \Rightarrow p \equiv 1$, $p \Rightarrow \lnot p \equiv \lnot p$, $p \Rightarrow 1 \equiv 1$, $p \Rightarrow 0 \equiv \lnot p$.
- Ancak ve ancak özdeşlikleri (ekrandan, 01:30:00): $p \Leftrightarrow q \equiv q \Leftrightarrow p$, $p \Leftrightarrow p \equiv 1$, $p \Leftrightarrow \lnot p \equiv 0$; ayrıca $p \Leftrightarrow 1 \equiv p$, $p \Leftrightarrow 0 \equiv \lnot p$.
- Devrik ($\lnot q \Rightarrow \lnot p$) denk, karşıt ($q \Rightarrow p$) ve ters ($\lnot p \Rightarrow \lnot q$) denk değil.
- Totoloji: hep 1. Çelişki: hep 0. Örnek totoloji $p \Rightarrow (p \lor q)$, örnek çelişki $p \land \lnot p$.
- $\forall$ bir AND zinciri gibi, $\exists$ bir OR zinciri gibi düşünülebilir.
- $\lnot \forall x\, P(x) \equiv \exists x\, \lnot P(x)$ ve $\lnot \exists x\, P(x) \equiv \forall x\, \lnot P(x)$.

## Detaylı Açıklamalar

- **Doğruluk tablosu kurma.** İki önerme için satırlar $00, 01, 10, 11$ olur. Üç önerme için en sağdaki sütun $0,1,0,1,\dots$, ortadaki $0,0,1,1,\dots$, soldaki dört 0 ve dört 1 şeklinde yazılır. Bu düzen ikilik sayma ile aynıdır ve satır atlamayı önler.
- **Anahtar devreleri.** $n$ anahtar seri bağlıysa akımın geçmesi (lambanın yanması) için $S_1 = 1 \land S_2 = 1 \land \dots \land S_n = 1$ gerekir; $2^n$ durumdan yalnız biri 1 verir. Anahtarlar paralel bağlıysa en az birinin kapalı olması yeterlidir: $(S_1 = 1) \lor (S_2 = 1) \lor \dots$ (ekrandan, 00:25:00). Hoca XOR için de iki konumlu anahtarlı bir devre çizmeye çalıştı, bağlantıyı tam kuramadı ve daha sonra paylaşacağını söyledi.
- **XOR'un temel bağlaçlarla yazılışı.** XOR tablosunda sonucun 1 olduğu satırlar $p=0, q=1$ ve $p=1, q=0$'dır. İlk satır $\lnot p \land q$, ikinci satır $p \land \lnot q$ ile ifade edilir; ikisinden biri olması yeterli olduğu için aralarına OR konur. Böylece $p \oplus q \equiv (\lnot p \land q) \lor (p \land \lnot q)$ bulunur. Bir öğrenci Karnaugh haritasıyla daha sade bir biçim olup olmadığını sordu; hoca bunun en sade hâl olduğunu söyledi.
- **Kriptografide XOR.** Mesaj ve mesaj uzunluğunda bir anahtar bit bit XOR'lanır ve şifreli mesaj elde edilir. Şifreli mesaj aynı anahtarla tekrar XOR'lanınca özgün mesaj geri gelir, çünkü $k \oplus k = 0$ ve $m \oplus 0 = m$.
- **Birleşik önerme tablosu: $(p \lor q) \land r$.** $r = 0$ olan bütün satırlar doğrudan 0'dır. $r = 1$ olan satırlarda sonuç $p \lor q$'ya eşittir; yalnız $p = q = 0$ satırı 0 kalır. Sonuç 1 olan satırlar $011$, $101$, $111$'dir (sıra $p, q, r$). Hoca $p \lor (q \land r)$ tablosunu denemeyi önerdi.
- **$p \Rightarrow q \equiv \lnot p \lor q$ türetmesi.** Tek 0 satırı $p \land \lnot q$'dur. O hâlde $p \Rightarrow q \equiv \lnot(p \land \lnot q)$ ve De Morgan ile $\lnot p \lor q$ elde edilir.
- **Karşıt, ters, devrik örneği.** $p$: "Bugün cumartesi", $q$: "Yarın pazar". Karşıt: "Yarın pazar ise bugün cumartesidir." Ters: "Bugün cumartesi değilse yarın pazar değildir." Devrik: "Yarın pazar değilse bugün cumartesi değildir." Devrik özgün önermeyle aynı anlamı taşır.
- **Gerekli ve yeterli koşul.** "Cüneyt programcıysa Zeynep avukattır" önermesinde Cüneyt'in programcı olması yeterli koşul, Zeynep'in avukat olması gerekli koşuldur. Hoca bunu üniversitenin ölçme kuralındaki "gerekli ve yeterli" ifadesiyle de örnekledi: gerekli olan yapılmak zorundadır, fazlası zorunlu değildir.
- **Totoloji örneği.** $p \Rightarrow (p \lor q)$ için dört satırın hepsinde sonuç 1 çıkar: $p=1$ iken $p \lor q = 1$ olduğundan "1 ise 0" durumu hiç oluşmaz.
- **De Morgan ve küme gösterimi.** $(A \land B)'$, iki kümenin kesişimi dışında kalan bölgedir ve $A' \lor B'$ ile aynıdır. Değil içeri dağıtılırken her önerme değillenir ve AND ile OR yer değiştirir. "İse" ve "ancak ve ancak" için doğrudan böyle bir dağıtım yoktur; önce temel bağlaçlarla yazılmaları gerekir.
- **Alıştırmalar.** "not" kullanmadan olumsuz yazma ("Today is Thursday" için diğer altı gün; $2+1=3$ için $2+1<3 \lor 2+1>3$), $p, q, r$ ile verilen cümleleri sembollere çevirme, "if p then q" biçimine getirme, verilen doğruluk değerleriyle ifade hesaplama ve $(\lnot p \land (p \Rightarrow q)) \Rightarrow \lnot q$ önermesinin totoloji olmadığını gösterme. Ayrıntılar genişletilmiş nottadır.
- **Niceleyiciler.** $P(x)$, tanım kümesindeki her $x$ için bir önerme üretir. "Bu sınıftaki her öğrenci 18 yaşından büyüktür" ile "bazı öğrenciler 18 yaşından büyüktür" farklı doğruluk değerleri alabilir. $\forall x\, P(x)$, $P(x_1) \land P(x_2) \land \dots$ gibidir; bir tane karşı örnek onu yanlış yapar. $\exists x\, P(x)$, $P(x_1) \lor P(x_2) \lor \dots$ gibidir; bir tane örnek onu doğru yapar. Slayttaki örnekler: $\forall x \in \mathbb{R},\ x^2 \ge 0$ doğru; $x>1 \Rightarrow x+1>1$ doğru; $x \ge 0 \Rightarrow x+1>1$ yanlış ($x=0$) (ekrandan, 02:30:00).
- **Cümleleri niceleyicilerle yazma.** "If somebody is female and is a parent, then this person is someone's mother": $\forall x\,((F(x) \land P(x)) \Rightarrow \exists y\, M(x,y))$ (ekrandan, 02:40:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
