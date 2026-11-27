# Ders 2 Çalışma Özeti

## Genel Konular

- Dersin tarihi 19 Ekim 2021 Salı. Ders Zoom üzerinden yapıldı; hoca anlatımı PowerPoint'te dijital mürekkeple siyah sayfalara yazarak ve ders slaytları üzerinden yürüttü.
  - Asıl ders yaklaşık 00:12'de başlar. Kayıtta iki ara vardır (yaklaşık 00:49-01:03 ve 01:35-01:45).
- İspatın yapı taşları
  - Tanımlanmamış terim (undefined term), tanım (definition), aksiyom (axiom), teorem.
- İspat yöntemleri
  - Doğrudan ispat (direct proof): $p \rightarrow q$ için $p$ doğru kabul edilir, $q$'nun doğruluğu gösterilir.
  - Dolaylı ispat (indirect proof, karşıt tersle ispat, derste "olmayana ergi" olarak da anıldı): $\lnot q \rightarrow \lnot p$ ispatlanır.
  - Tümevarımla ispat (mathematical induction): temel adım, kabul, tümevarım adımı.
  - Çelişkiyle ispat (proof by contradiction): önermenin olumsuzunun yanlış olduğu gösterilir.
  - Aksine örnek (counterexample): her için kurulan bir önermenin yanlışlığını tek örnekle gösterme.
  - Deneme yoluyla ispat (sonlu küme üzerinde tüm elemanları tek tek deneme).
- Tümevarım uygulamaları
  - $1+2+\dots+n = \frac{n(n+1)}{2}$, yanlış bir önermede tümevarımın nasıl tıkandığı, ilk $n$ tek sayının toplamı, $n^3-n$'nin 3'e bölünmesi, $3n < n!$ ($n>6$).
- Boole cebrine giriş (Bölüm 3)
  - Bilginin neden iki seviyeli (0/1) elektriksel işaretlerle saklandığı.
  - OR, AND ve NOT kapıları; Boole toplamı, çarpımı ve tümleyeni.
  - Boole fonksiyonu, doğruluk tablosundan ifade yazma, Boole fonksiyonlarının eşitliği.
  - $n$ değişkenli Boole fonksiyonlarının sayısı: $2^{2^n}$.
  - Boole cebrindeki özdeşlikler ve devre sadeleştirme.
  - Çarpımların toplamı (sum of products) ve toplamların çarpımı (product of sums) gösterimlerine giriş.

## Hocanın Özellikle Vurguladığı Kısımlar

- Hangi ispat yönteminin seçileceği
  - $p$ tarafı basit, $q$ tarafı karmaşıksa doğrudan ispat uygundur. $p$ tarafı karmaşıksa (ör. "$n^2$ tek ise $n$ tektir") karşıt terse geçilir.
  - Yöntemi seçmenin bir algoritması yoktur; bol soru çözerek tecrübe kazanılır. Ders kitabının bölüm sonu soruları önerildi.
- Karşıt tersin geçerliliği
  - $p \rightarrow q \equiv \lnot q \rightarrow \lnot p$ olduğu için (doğruluk tablosundaki bütün satırlar aynı) karşıt tersi ispatlamak asıl önermeyi ispatlamaktır.
- Tümevarımın merdiven benzetmesi
  - İlk basamak sağlanmalı; $k$. basamaktan $k+1$. basamağa geçiş tutarlı olmalı. Bir basamak "sakat" ise ötesine bakmaya gerek yoktur.
- Çift sayının $2k$ biçiminde yazılması bir kabuldür; ispatlar bu kabulün üzerine kurulur.
- Boole cebrinde dağılma iki yönlüdür: $x + yz = (x+y)(x+z)$ de geçerlidir; bu, sıradan aritmetikte yoktur.
- Özdeşlikler devreleri sadeleştirmek, yani daha az kapıyla aynı işi yapmak için kullanılır.
  - $xy\bar{z} + \bar{x}y\bar{z}$ gibi bir ifadede $x$'in bir işe yaramadığını görmek, kapı sayısını ciddi biçimde düşürür.
- Kural olarak $x + \bar{x}y = x + y$ önemlidir; ezberlemek yerine dağılma ve $x+\bar{x}=1$ ile türetilebilir.

## Kısa Tekrar Notları

- Aksiyom: ispatsız doğru kabul edilen önerme. Teorem: aksiyom, tanım ve önceki teoremlerle ispatlanan $p \rightarrow q$ biçimli önerme.
- Doğrudan ispat adımları: (1) $p$ doğru kabul edilir, (2) $q$'nun doğru olduğu gösterilir, (3) $p \rightarrow q$ doğrudur.
- Çift sayı: $n = 2k$; tek sayı: $n = 2k+1$, $k \in \mathbb{Z}$.
- Dolaylı ispat: $\lnot q \rightarrow \lnot p$ doğrudan ispatla gösterilir.
- Çelişkiyle ispat: $\lnot(p \rightarrow q) \equiv p \land \lnot q$; bunun yanlış olduğu gösterilir.
- Tümevarım: temel adım ($n$'nin ilk değeri), $n=k$ için doğru kabul, $n=k+1$ için doğruluğu gösterme.
- Aksine örnek: "tüm asal sayılar tektir" önermesi $2$ ile yanlışlanır; "her gerçel $x$ için $x^2>0$" önermesi $x=0$ ile yanlışlanır.
- Boole toplamı = OR, Boole çarpımı = AND, tümleyen = NOT. Öncelik: NOT, sonra AND, sonra OR.
- Doğruluk tablosunda 1 olan satırların çarpım terimleri toplanarak fonksiyon yazılır (çarpımların toplamı).
- $n$ değişkenle $2^n$ satır ve $2^{2^n}$ farklı Boole fonksiyonu vardır ($n=2$ için 16).
- Yutma (absorption): $x + xy = x$, $x(x+y) = x$. Tümleyen: $x + \bar{x} = 1$, $x\bar{x} = 0$.
- Uzlaşma (consensus): $AB + \bar{A}C + BC = AB + \bar{A}C$.

## Detaylı Açıklamalar

- **İspatın yapı taşları.** Tanımlanmamış terimler bir matematik sisteminin başlangıç kavramlarıdır (ör. Öklid geometrisinde nokta ve doğru). Tanım, kabul edilmiş kavramlardan yeni bir kavram üretir (ör. karşılıklı kenarları ve açıları eşit iki üçgen eş üçgendir; toplamı 180 derece olan iki açı birbirini tamamlar). Aksiyom ispatsız doğru kabul edilen önermedir: iki noktadan geçen bir doğru her zaman vardır; bir doğru ve üzerinde olmayan bir nokta verildiğinde bu noktadan geçen doğrulardan biri verilen doğruya paraleldir (ekrandan, 00:15:00). Teorem ise önceden ispatlanmış teoremler, aksiyomlar ve tanımlar kullanılarak, $p$ doğru kabul edilip doğruluğu gösterilen $p \rightarrow q$ biçimli önermedir.
- **Doğrudan ispat.** Tahtada yazılan örnek: "$n$ çift sayı ise $n^2$ çift sayıdır" (ekrandan, 00:25:00). (1) $n = 2k$, $k \in \mathbb{Z}$ doğru kabul edilir. (2) $n^2 = 4k^2 = 2(2k^2) = 2u$, $u = 2k^2 \in \mathbb{Z}$. (3) $n^2 = 2u$ çift sayı biçimindedir; sonuç olarak ("$\therefore$", therefore) $n^2$ çifttir. "$\because$" (since) simgesi "çünkü/olduğu için" anlamında kullanılır.
- **Doğrudan ispatın işlemediği durum.** $p$ tarafının karmaşık olduğu bir önermede (ör. bir toplamın çiftliğinden tek tek terimlerin çiftliğine geçmek) doğrudan ispatla sonuca varılamaz. <!-- BELİRSİZ: Altyazıda bu örnek "m+n çift ise m ... çifttir" olarak geçiyor; önermenin tam metni karede görünmüyor. -->
- **Dolaylı ispat.** "$n^2$ tek sayı ise $n$ tek sayıdır" (ekrandan, 00:30:00): $p$: $n^2$ tek, $q$: $n$ tek; $\lnot p$: $n^2$ çift, $\lnot q$: $n$ çift. $\lnot q \rightarrow \lnot p$ doğrudan ispatlanır: $n = 2k$ ise $n^2 = 4k^2 = 2(2k^2)$ çifttir. Karşıt ters doğru olduğundan asıl önerme de doğrudur. Slayttaki ikinci örnek: "$n$ tam sayı ve $3n+2$ tek ise $n$ tektir." Doğrudan denendiğinde $3n+2 = 2k+1 \Rightarrow 3n+1 = 2k$ bulunur ama buradan $n$'nin tekliği ispat tekniğiyle çıkmaz. Karşıt tersle: $n = 2k$ ise $3n+2 = 6k+2 = 2(3k+1)$ çifttir; dolayısıyla asıl önerme doğrudur.
- **Tümevarım.** Slayt: "$\forall n \in A,\ S(n)$" biçimindeki ifadeler; $N$ pozitif tam sayılar veya doğal sayılar, $A \subseteq N$, $S(n)$ bir önerme; genel olarak özdeşliklerin ispatında kullanılır (ekrandan, 00:35:00). Temel adımın illa $n=1$ olması gerekmez; kümenin ilk elemanından başlanır.
  - $1+2+\dots+n = \frac{n(n+1)}{2}$ (ekrandan, 00:40:00): $n=1$: $\frac{1\cdot 2}{2}=1$; $n=2$: $\frac{2\cdot 3}{2}=3$. $n=k$ için doğru kabul edilir. $n=k+1$ için $\frac{k(k+1)}{2} + (k+1) = \frac{(k+1)(k+2)}{2}$ olur; sol taraf sağ tarafa eşittir.
  - Yanlış önerme örneği: $1+2+\dots+n = \frac{n(n+2)}{2}$. $n=1$ için $1.5 \ne 1$. Tümevarım adımında $\frac{k(k+2)}{2} + (k+1) = \frac{k^2+4k+2}{2}$, oysa $\frac{(k+1)(k+3)}{2} = \frac{k^2+4k+3}{2}$; eşitlik sağlanmaz.
  - İlk $n$ pozitif tek sayının toplamı $n^2$'dir (ekrandan, 00:45:00): $1+3+\dots+(2k-1) = k^2$ kabulüyle $k^2 + (2k+1) = (k+1)^2$.
  - $n^3 - n$, her pozitif tam sayı $n$ için 3'e bölünür: $(k+1)^3 - (k+1) = (k^3 - k) + 3(k^2 + k)$; ilk terim kabulden, ikinci terim çarpandan dolayı 3'e bölünür.
  - $n > 6$ için $3n < n!$ (ekrandan, 01:20:00): $3 \cdot 7 = 21 < 7! = 5040$. $3k < k!$ kabulüyle $3(k+1) = 3k + 3 < k! + k \cdot k! = (k+1)!$, çünkü $k \cdot k! > 3$. Bu, $3n$ adımlı bir algoritmanın $n!$ adımlı bir algoritmadan daha iyi olduğunun ispatı olarak sunuldu.
- **Çelişkiyle ispat.** $p \rightarrow q \equiv \lnot p \lor q$ olduğundan $\lnot(p \rightarrow q) \equiv p \land \lnot q$ (ekrandan, 01:10:00). Örnek: "$n$ tek ise $n^2$ tektir." $n$ tek ve $n^2$ çift varsayılır. $n = 2k+1$ ise $n^2 = 4k^2+4k+1 = 2(2k^2+2k)+1 = 2l+1$ tektir; varsayımla çelişir. $p \land \lnot q$ yanlış olduğundan $p \rightarrow q$ doğrudur.
- **Aksine örnek ve deneme yoluyla ispat.** Bir evrensel önermeyi yanlışlamak için tek bir aksine örnek yeterlidir (ekrandan, 01:15:00). Sonlu bir küme üzerinde ise her eleman denenebilir: $\{-1, 0, 1\}$ üzerinde $x^2 < 5$ önermesi için $1, 0, 1$ değerlerinin hepsi 5'ten küçüktür, önerme doğrudur.
- **Boole cebrinin donanım temeli.** Çok seviyeli voltajla (4 V = A, 3 V = B, ...) bilgi göndermek, iletkenin direnci ($R = \rho \frac{L}{A}$) ve gürültü yüzünden hatalıdır (ekrandan, 01:30:00). Bunun yerine her hatta yalnız "var/yok" (0 V / 5 V) gönderilir; 3 hatla $2^3 = 8$ farklı bilgi taşınabilir. Kondansatör, diyot (silisyumda yaklaşık 0,7 V eşik) ve transistör gibi yarı iletken elemanlar bu iki durumu saklar ve bunlardan lojik kapılar kurulur.
- **Boole işlemleri.** Boole çarpımı (AND): yalnız $1 \cdot 1 = 1$. Tümleyen: $\bar{0} = 1$, $\bar{1} = 0$. Slayt örneği: $1 \cdot 0 + \overline{(0+1)} = 0 + \bar{1} = 0 + 0 = 0$ (ekrandan, 01:35:00).
- **Koşullu önermenin devresi.** $A \rightarrow B \equiv \bar{A} + B$: $A$ bir NOT kapısından geçer, $B$ ile birlikte bir OR kapısına girer. Çıkış yalnız $A=1, B=0$ satırında 0'dır.
- **Boole fonksiyonu.** $F(x,y,z) = xy + \bar{z}$ tablosu (ekrandan, 01:50:00): sırasıyla $xyz = 111, 110, 101, 100, 011, 010, 001, 000$ için $F = 1, 1, 0, 1, 0, 1, 0, 1$. AND, OR'dan önce hesaplanır. Tablodaki 1 satırlarından yazılan ifade $xyz + xy\bar{z} + x\bar{y}\bar{z} + \bar{x}y\bar{z} + \bar{x}\bar{y}\bar{z}$ beş adet üç girişli AND ve OR kapılarıyla kurulur; sade hali $xy + \bar{z}$ ise yalnız bir AND, bir OR ve bir NOT ister. Yalnız 1 satırlarının alınması yeterlidir, çünkü diğer bütün satırlar zaten 0 verir.
- **Eşitlik ve fonksiyon sayısı.** $F$ ve $G$, bütün $(b_1,\dots,b_n)$ girişleri için aynı değeri veriyorsa eşittir (mantıksal denklik). Örnek: $xy$, $xy+0$ ve $xy \cdot 1$ denktir (ekrandan, 01:55:00). $n$ değişkenle $2^n$ satır ve $2^{2^n}$ fonksiyon vardır.
- **Özdeşlikler** (ekrandan, 02:00:00): çift tümleyen $\bar{\bar{x}} = x$; eş güçlülük $x+x=x$, $x \cdot x = x$; birim $x+0=x$, $x \cdot 1 = x$; baskınlık $x+1=1$, $x \cdot 0 = 0$; değişme; birleşme; dağılma $x+yz=(x+y)(x+z)$, $x(y+z)=xy+xz$; De Morgan $\overline{xy}=\bar{x}+\bar{y}$, $\overline{x+y}=\bar{x}\bar{y}$; yutma $x+xy=x$, $x(x+y)=x$; $x+\bar{x}=1$; $x\bar{x}=0$. $x(y+z) = xy + xz$ doğruluk tablosuyla doğrulandı. $x(y+z)$ iki kapıyla, $xy+xz$ üç kapıyla kurulur; soldaki daha iyidir.
- **$x + \bar{x}y = x + y$.** $x = x(1+y) = x + xy$ yazılır; $x + xy + \bar{x}y = x + y(x+\bar{x}) = x + y$. $y$ yerine $yz$ gibi bir çarpım da gelebilir.
- **Doğruluk tablosundan ifade** (ekrandan, 02:15:00): $F$ yalnız $x=z=1, y=0$ iken 1'dir, $F = x\bar{y}z$. $G$ iki satırda 1'dir: $G = xy\bar{z} + \bar{x}y\bar{z} = y\bar{z}(x+\bar{x}) = y\bar{z}$; böylece kapı sayısı ciddi biçimde düşer.
- **İki gösterim.** De Morgan ile $x\bar{y}z = \overline{\bar{x} + y + \bar{z}}$ yazılabilir. İlki çarpımların toplamı, ikincisi toplamların çarpımı biçimine götüren gösterimdir; sistematik sadeleştirme için sonraki derste Karnaugh haritaları ele alınacaktır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
