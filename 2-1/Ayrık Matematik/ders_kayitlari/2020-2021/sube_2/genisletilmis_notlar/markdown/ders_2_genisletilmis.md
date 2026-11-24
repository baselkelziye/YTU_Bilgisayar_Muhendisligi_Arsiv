# Ders 2 Genişletilmiş Notu: Koşullu Önermeler, Niceleyiciler ve İspat Yöntemleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Koşullu Önermenin Tekrarı
- 2. Koşullu Önermenin Türevleri ve Çift Yönlü Önerme
- 3. Totoloji, Çelişki ve De Morgan Kanunu
- 4. Niceleyiciler ve Önerme Fonksiyonları
- 5. Evrensel Niceleyici
- 6. Varoluşsal Niceleyici
- 7. Cümleleri Niceleyicilerle Yazma
- 8. Karşı Örnek ve Niceleyicilerde De Morgan
- 9. İspatın Temelleri: Terim, Tanım, Aksiyom, Teorem
- 10. Doğrudan İspat
- 11. Dolaylı İspat (Karşıt Ters)
- 12. Çelişki ile İspat
- 13. İspat Sorusuna Nasıl Cevap Verilir?
- 14. Tümevarım
- 15. Karşı Örnek ile İspat
- 16. Deneme Yanılma (Kaba Kuvvet)
- 17. Slaytlardaki Ek Örnekler
- Örnek Sorular
- Dersin Toparlaması

## 1. Koşullu Önermenin Tekrarı

Ders, önceki haftanın konusu olan önermeler mantığının kısa bir tekrarıyla başladı. Önceki derste birleşik önermelerde kullanılan bağlaçlar ve bunların birbiri cinsinden nasıl yazıldığı görülmüştü. Bu derste önce koşullu önermeye, yani "ise" bağlacına dönüldü.

Hoca bu bağlacın neden önemli olduğunu vurguladı: ise bağlacı mantığın yanında programlamada da kullanılır ve ispatlarda çok sık geçer. Bu derste anlatılacak ispat yöntemlerinin neredeyse hepsi $p \rightarrow q$ biçimindeki önermeler üzerine kurulur.

$p \rightarrow q$ önermesinde $p$'ye **hipotez**, $q$'ya **sonuç** denir. Doğruluk tablosu ezberlenmek istenirse kural basittir: yalnız $1 \rightarrow 0$ durumunda sonuç $0$'dır, diğer üç durumda $1$'dir. Ama hoca ezberin arkasındaki mantığın önemli olduğunu söyledi: burada bir şartın yerine gelmesinin diğer şartın yerine gelmesiyle ilişkisi incelenir. Hipotez gerçekleşmeden de sonuç doğru olabilir ($0 \rightarrow 1$ doğrudur). Hipotez de sonuç da gerçekleşmezse önerme yine doğrudur ($0 \rightarrow 0$). Yalnız hipotez gerçekleştiği hâlde sonuç gerçekleşmezse önerme yanlıştır.

Bu bağlamda iki kavram öne çıkar:

- **Yeterli şart:** Sonucun gerçekleşmesi için yeterli olan şarttır; hipotez tarafıyla ilgilidir.
- **Gerekli şart:** Sonuç tarafından ifade edilen şarttır.

> **Hocanın vurgusu:** Yeterli şart ve gerekli şart kavramları ispat konusunda kullanılacaktır.

### 1.1 Mantıksal denklik

Hoca ise bağlacını temel bağlaçlar cinsinden yazdı. Temel bağlaçlar değil ($\lnot$, derste tilde $\sim$ ile de gösterildi), ve ($\land$) ile veya ($\lor$) bağlaçlarıdır.

Slaytta gösterilen tablo (ekrandan, 00:20:00):

| $p$ | $q$ | $\lnot p \lor q$ | $p \rightarrow q$ |
|---|---|---|---|
| T | T | T | T |
| T | F | F | F |
| F | T | T | T |
| F | F | T | T |

Hoca $\lnot p \lor q$ sütununu satır satır hesapladı: $p$'nin değili alınır, sonra $q$ ile "veya" yapılır. Elde edilen sütun $p \rightarrow q$ sütunuyla birebir aynı çıkar. Doğruluk tablosundaki değerleri aynı olan iki önerme arasında **mantıksal denklik** (logical equivalence) vardır denir. Buna göre:

$$p \rightarrow q \equiv \lnot p \lor q$$

Yani ise bağlacı "birinci tarafın değili veya ikinci taraf" olarak yazılabilir.

## 2. Koşullu Önermenin Türevleri ve Çift Yönlü Önerme

Önceki derste ise bağlacının üç türevi görülmüştü. Hoca bunları aynı örnek üzerinden tekrar etti. Asıl önerme: "Bugün cumartesi ise yarın pazardır."

- **Karşıt (converse):** $q \rightarrow p$. Örnek: "Yarın pazarsa bugün cumartesidir." Bu önerme asıl önermeyle mantıksal olarak denk değildir. Doğruluk tablosunda satırlar yer değiştirir ve sütunlar aynı çıkmaz.
- **Karşıt ters (contrapositive):** $\lnot q \rightarrow \lnot p$. Örnek: "Yarın pazar değilse bugün cumartesi değildir." Burada hem yerler değişir hem değiller alınır. Doğruluk tablosu asıl önermeninkiyle aynıdır; yani karşıt ters asıl önermeyle **mantıksal olarak denktir**.
- **Ters (inverse):** $\lnot p \rightarrow \lnot q$. Yerler aynı kalır, yalnız değiller alınır. Örnek: "Bugün cumartesi değilse yarın pazar değildir."

> **Hocanın vurgusu:** Karşıt tersin asıl önermeyle denk olması önemlidir; bu denklik dolaylı ispat tekniğinde kullanılacaktır.

### 2.1 Çift yönlü koşullu önerme

Çift yönlü önerme $p \leftrightarrow q$, yalnız iki girişin ikisi de doğru ya da ikisi de yanlış olduğunda doğrudur. Diğer durumlarda yanlıştır. Bu önerme "ve" ile ise bağlacı kullanılarak şöyle yazılır:

$$p \leftrightarrow q \equiv (p \rightarrow q) \land (q \rightarrow p)$$

Her bir ise bağlacı temel bağlaçlarla açılırsa yalnız değil, ve, veya kullanan bir ifade elde edilir:

$$p \leftrightarrow q \equiv (\lnot p \lor q) \land (\lnot q \lor p)$$

## 3. Totoloji, Çelişki ve De Morgan Kanunu

### 3.1 Totoloji ve çelişki

Doğruluk tablosundaki bütün sonuçlar doğruysa önerme bir **totolojidir**. Örnek: $p \rightarrow (p \lor q)$. Bu ifadenin bütün sonuçları doğrudur, bu yüzden totolojidir. Bütün sonuçları yanlış olan önermeye **çelişki** denir.

### 3.2 De Morgan kanunu

Slayttaki ifadeler (ekrandan, 00:25:00):

- $\lnot(p \lor q) \equiv (\lnot p) \land (\lnot q)$
- $\lnot(p \land q) \equiv (\lnot p) \lor (\lnot q)$

Hoca kuralı kümelerden bilinen bir kural olarak hatırlattı: bir ifadenin değili alınırsa o ifadedeki her önermenin değili alınır, "veya" yerine "ve", "ve" yerine "veya" gelir. Hoca tahtada bunu kısaca $p \rightarrow \lnot p$, $\lor \rightarrow \land$, $\land \rightarrow \lor$ diye özetledi. Değilin değili ise önermenin kendisidir.

Hoca bu kuralın programlamadaki yerine de değindi. Bir C programında (ya da herhangi bir dilde) `if` içine `&&` ve `||` operatörleriyle yazılmış çok uzun ve anlaşılması güç bir koşul olabilir. Bu koşulun değili De Morgan kuralından geçirilerek daha kısa ve okunur yazılabilir.

Derste bu noktada iki kısa alıştırma soruldu. Birinde çift yönlü önermenin iki tarafı aynı olduğunda sonucun $1$ olduğu hatırlatıldı. Diğerinde sonucun doğrudan $p$'ye eşit olduğu, yani $p$ $0$ ise sonucun $0$, $1$ ise $1$ olduğu bulundu. <!-- BELİRSİZ: Bu iki alıştırmadaki ifadelerin tam yazılışı altyazıdan çıkmıyor ve o anlara ait kare yok. -->

## 4. Niceleyiciler ve Önerme Fonksiyonları

Önceki derste niceleyiciler (quantifiers) konusunda kalınmıştı. Hoca konuya buradan devam etti.

Bir önerme kurarken üzerinde çalışılan değerler belli bir kümeden gelebilir. Bu kümeleri ifade etmek ve bu kümeler üzerinde önerme yazmak için bazı sembollere ihtiyaç duyulmuştur. Bunlardan biri ters A'ya benzeyen $\forall$ ("her", every), diğeri $\exists$ ("bazı", some) sembolüdür.

$P(x)$, $x$ değişkenine bağlı bir önermedir (önerme fonksiyonu). Örneğin $P(x)$: "$2x$ çift tam sayıdır" olabilir. $x$'in alabileceği değerlerin kümesine **tanım kümesi** (domain of discourse, $D$) denir. Örneğin "$x \in \mathbb{Z}$" ya da "$x \in \mathbb{N}$" gibi. Tanım kümesi, daha genel bir kümeden belli bir kurala uyan daha ayrıntılı bir kümeye inmek için kullanılır. Tanım kümesindeki her $x$ değeri, $P(x)$'i doğru ya da yanlış olan bir önerme yapar.

Hoca bu konudan gelebilecek soru tiplerini de söyledi: niceleyicilerle verilen bir ifadeyi sözel cümleye çevirmek ya da sözel bir cümleyi matematiksel biçimde yazmak.

Slayttaki örnekler (ekrandan, 00:30:00):

- $P(n)$: "$n^2 + 2n$ tek sayıdır." $D$ kümesi pozitif tam sayılardan ($\mathbb{Z}^+$) oluşsun. $n$ tek sayı ise $n^2 + 2n$ tek sayıdır; $n$ çift sayı ise $n^2 + 2n$ tek sayı değildir.
- "Bu sınıftakiler 18 yaşından büyüktür." $D$ kümesi sınıftaki öğrenciler olsun. Öğrencilerin bazıları önermeyi doğru, bazıları yanlış yapar.

Bir başka örnek "Her üçgenin iç açıları toplamı 180 derecedir" önermesidir. Bu, üçgen tanımına uyan her şekil için her zaman doğrudur. İşte tanım kümesindeki elemanların hepsinin mi, yalnız bazılarının mı önermeyi doğru yaptığını göstermek için kullanılan semboller niceleyicilerdir.

## 5. Evrensel Niceleyici

$P(x)$ önermesi $D$ kümesindeki her $x$ değeri için doğruysa bu durum

$$\forall x\, P(x)$$

ile gösterilir ve "her $x$ için $P(x)$ doğrudur" ya da "bütün $x$'ler için $P(x)$" diye okunur. Örneğin "Sınıftaki her öğrenci kalkülüs dersini aldı" cümlesinde $P(x)$: "$x$ öğrencisi kalkülüs dersini aldı" olur ve cümle $\forall x\, P(x)$ biçiminde yazılır. Hoca bunun aslında yalnız bir gösterim (notasyon) olduğunu söyledi.

Hoca bu sembolün içinde gizli bir operatör olduğunu vurguladı: gizli bir **VE** (and) işlemi. Bunu bir çarpım gibi düşünmek mümkündür. Bütün $P(x_i)$ önermeleri birbiriyle çarpılır; sonucun $1$ olması için hepsinin $1$ olması gerekir. Bir tanesi bile $0$ olursa çarpım $0$ olur. Kümeler dilinde bu, kesişim (intersection) işlemine karşılık gelir:

$$\forall x\, P(x) \equiv P(x_1) \land P(x_2) \land \dots \land P(x_n)$$

Bu ifade ancak ve ancak bütün $P(x_i)$'ler doğru olduğunda doğrudur. Tersinden bakılırsa: $\forall x\, P(x)$ doğruysa bütün $x$'ler şartı sağlıyordur; doğru değilse en az bir $x$ şartı bozuyordur.

### 5.1 Tanım kümesinin önemi

Önerme fonksiyonu $P(n)$: "$n^2 + 2n$ tek sayıdır" olsun. $n$ bütün tam sayılar kümesinde gezerse $\forall n\, P(n)$ doğru olmaz, çünkü $n$ çift olduğunda önerme yanlıştır. Önerme yalnız tek sayılar için doğrudur. Doğru olması isteniyorsa tanım kümesi "bütün tek tam sayılar" olarak seçilmelidir.

### 5.2 Gerçel sayılarla örnekler

- "Her gerçel $x$ sayısı için $x^2 \ge 0$." Doğrudur (ekrandan, 00:35:00; slaytta TRUE yazıyor).
- Hoca aynı tanım kümesinde "$x^2 \ge 1$" önermesini sordu. Yanlıştır, çünkü $-1 < x < 1$ aralığında bir istisna vardır. Örneğin $x = 0{,}9$ ya da $x = -0{,}9$ alınırsa karesi pozitiftir ama hiçbir zaman $1$'e ulaşmaz. $0$ dahil bu aralıktaki bütün değerlerde önerme yanlıştır.
- "Her gerçel $x$ için, $x > 1$ ise ..." biçiminde bir önerme de soruldu ve doğru olduğu söylendi; $x = 1{,}1$ gibi bir değer bile şartı sağlar. <!-- BELİRSİZ: Bu önermenin sonuç kısmı altyazıdan net çıkmıyor; büyük olasılıkla "$x > 1$ ise $x^2 > 1$" önermesidir. O ana ait kare yok. -->
- Ardından gösterilen bir başka önermenin yanlış olduğu, çünkü $x = 0$ alındığında sağlanmadığı söylendi. <!-- BELİRSİZ: Önermenin tam metni okunamadı; büyük olasılıkla "her gerçel $x$ için $x^2 > 0$" önermesidir (dersin ilerleyen kısmında 02:11:09'da aynı önerme $x = 0$ karşı örneğiyle çürütüldü). -->

Hoca burada ileride görülecek "fonksiyonların büyümesi" (growth of functions) konusuna da işaret etti: orada $n!$ mi $n^2$ mi daha büyüktür gibi sorularda benzer akıl yürütmeler kullanılacaktır.

### 5.3 Asal sayı üreten ifade

Bir sonraki örnek "her pozitif tam sayı $n$ için $n^2 + n + 19$ asaldır" biçiminde bir önermeydi. <!-- BELİRSİZ: Önermenin tam metni altyazıda bozuk ("N çift olacak, pozitif olacak" ifadesi geçiyor); o ana ait kare yok. --> Hoca bunun doğruluğunu göstermenin zor olduğunu, onun yerine yanlış olduğunu göstermenin daha kolay olduğunu söyledi. Bunun bir yolu çelişki yöntemidir, bir diğeri **karşı örnek** bulmaktır. Hoca $n = 2$ için $4 + 2 + 19 = 25$ elde etti; $25$ asal olmadığından önerme yanlıştır.

> **Ders sonrası not:** Hoca $n = 1$ için sonucun asal olduğunu söyledi. Oysa $1 + 1 + 19 = 21 = 3 \cdot 7$ asal değildir; yani karşı örnek daha ilk denemede, $n = 1$ için bulunur. $n = 2$ için $25$ sonucu doğrudur (python ile kontrol edildi).

## 6. Varoluşsal Niceleyici

Varoluşsal niceleyici (existential quantification) $\exists x\, P(x)$, kümede önermeyi doğru yapan **en az bir** eleman bulunduğunu söyler; bütün elemanların doğru yapması gerekmez. Bir çözümün var olduğunu ya da önermenin doğru olabileceği durumları ifade etmek için kullanılır. Hoca sıralama problemini örnek verdi: sıralama zor bir problemdir, ama belli şartlar altında çözümü vardır.

Bu niceleyicinin içinde gizli bir **VEYA** işlemi vardır. Kümelerde birleşime, toplamada sigma işlemine karşılık gelir. İçlerinden bir tanesi bile doğruysa sonuç doğrudur:

$$\exists x\, P(x) \equiv P(x_1) \lor P(x_2) \lor \dots \lor P(x_n)$$

Burada "bazı" kelimesi önemlidir: önceki niceleyicide "her" vardı, burada "bazı" vardır.

Slayttaki örnek (ekrandan, 00:45:00): "Bazı gerçel $x$ sayıları için $\dfrac{x}{x^2 + 1} = \dfrac{2}{5}$." Hoca $x = 2$ değerini yazdı: $\dfrac{2}{4 + 1} = \dfrac{2}{5}$. Denklem çözülürse başka değerler de bulunabilir, ama önermenin doğruluğu için en az bir örnek yeterlidir.

> **Ek bilgi (derste anlatılmadı):** $\dfrac{x}{x^2+1} = \dfrac{2}{5}$ denklemi $2x^2 - 5x + 2 = 0$ biçimine gelir ve kökleri $x = 2$ ile $x = \dfrac{1}{2}$'dir.

### 6.1 Yokluğun ispatı

Hoca mantıkta önemli bir noktaya değindi: bir şeyin yokluğu doğrudan ispat edilmez. "Bu problemde böyle bir $x$ değeri yoktur" demek bir ispat değildir, çünkü gerçel sayılar sonsuz tanedir ve sonsuz tane değeri deneyip ispat yapmak mümkün değildir. Yokluk ancak varsayılır; bu yüzden böyle bir iddia kanun olmaz, en fazla teori olarak kalır.

Hoca örnek olarak $a^4 + b^4 + c^4 = d^4$ denklemini verdi (tahtada yazılı, ekrandan, 00:45:00). Bir zamanlar bu denklemin pozitif tam sayılarda çözümü olmadığı iddia edilmişti. Bu iddianın yanlış olduğu, sayısal bilgisayarlar ortaya çıkınca bir karşı örnek bulunarak gösterildi. Hoca karşı örneğin "1600 küsurlu" bir sayı olduğunu hatırladığını ama emin olmadığını söyledi.

> **Ders sonrası not:** Bu iddia Euler'in kuvvetler toplamı sanısının $n = 4$ durumudur. Bilinen en küçük karşı örnek $95800^4 + 217519^4 + 414560^4 = 422481^4$'tür; ilk karşı örnek $2682440^4 + 15365639^4 + 18796760^4 = 20615673^4$ eşitliğidir (iki eşitlik python ile doğrulandı). Hocanın andığı "1600 küsur" değeri bu sayılarla uyuşmuyor. Karşı örneklerin 1988'de bulunduğu bilgisi büyük olasılıkla doğrudur ama altyazıdan doğrulanmadı.

### 6.2 Asal sayıdan sonra dört asal olmayan sayı

Örnek: "Bazı pozitif tam sayılar $n$ için, $n$ asal ise $n+1$, $n+2$, $n+3$, $n+4$ asal değildir."

Hoca $n = 2$ ile denedi: $3$ asal olduğu için şart sağlanmaz. Ama $n = 23$ için $23$ asaldır ve $24, 25, 26, 27$ sayılarının hiçbiri asal değildir. Önermeyi doğru yapan bir değer bulunduğu için önerme doğrudur. Hoca bunun aslında zor bir problem olduğunu da ekledi. Önerme şöyle yazılır:

$$\exists x\, \big( x \text{ asal} \rightarrow (x+1, x+2, x+3, x+4 \text{ asal değil}) \big)$$

Python ile yapılan kontrolde bu şartı sağlayan ilk asal sayının gerçekten $23$ olduğu görüldü.

## 7. Cümleleri Niceleyicilerle Yazma

### 7.1 Lunapark treni

Slayttaki soru (ekrandan, 00:40:00): "You can not ride the roller coaster if you are under 4 feet tall unless you are older than 16 years old" cümlesini mantıksal ifadelerle yazınız.

- $q$: Lunapark trenine binebilirsin.
- $r$: Boyun 4 feet'in altındadır.
- $s$: 16 yaşından büyüksün.

Cümle şöyle yorumlanır: boyun 4 feet'in altındaysa **ve** 16 yaşından büyük değilsen trene binemezsin:

$$(r \land \lnot s) \rightarrow \lnot q$$

Hoca ikinci bir yazılış olarak, ifadelerin değilini alıp "De Morgan gibi" farklı bir dille yazılabileceğini söyledi; slaytta $(\lnot r \lor s) \rightarrow q$ yer alıyor. Hoca cümlenin mantıksal ifadeye çevrilmesinin, kişinin önermeleri nasıl yorumladığına bağlı olduğunu da ekledi.

> **Ders sonrası not:** $(\lnot r \lor s) \rightarrow q$ ifadesi, $(r \land \lnot s) \rightarrow \lnot q$ önermesinin tersidir (inverse), karşıt tersi değildir. İkisi mantıksal olarak denk değildir: örneğin $r = 0$, $s = 0$, $q = 0$ için birincisi doğru, ikincisi yanlıştır (doğruluk tablosu python ile karşılaştırıldı). Asıl önermeye denk olan yazılış karşıt terstir: $q \rightarrow (\lnot r \lor s)$.

### 7.2 Herkesin tam olarak bir en iyi arkadaşı vardır

"Everyone has exactly one best friend" cümlesi için $B(x, y)$: "$y$, $x$'in en iyi arkadaşıdır" olsun. Cümle şu anlama gelir: her $x$ kişisi için bir $y$ kişisi vardır; bu $y$, $x$'in en iyi arkadaşıdır ve $y$'den farklı her $z$ kişisi $x$'in en iyi arkadaşı değildir. Mantıksal olarak:

$$\forall x\, \exists y\, \Big( B(x, y) \land \forall z\, \big( (z \ne y) \rightarrow \lnot B(x, z) \big) \Big)$$

<!-- BELİRSİZ: Bu slayda ait kare yok; formül hocanın sözlü anlatımından ("her x için bazı y vardır ki x'in en iyi arkadaşıdır, y'den farklı her z x'in en iyi arkadaşı değildir") kuruldu. -->

### 7.3 Anne örneği

Slayttaki örnek (ekrandan, 00:50:00): "If somebody is female and is a parent, then this person is someone's mother."

- $F(x)$: "$x$ is female" ($x$ kadındır),
- $P(x)$: "$x$ is a parent" ($x$ ebeveyndir),
- $M(x, y)$: "$x$ is the mother of $y$" ($x$, $y$'nin annesidir).

$$\forall x\, \big( (F(x) \land P(x)) \rightarrow \exists y\, M(x, y) \big)$$

Hoca kişinin kadın olması ve ebeveyn olması şartlarının birlikte sağlanması gerektiğini, bu durumda kişinin bazı kişilerin annesi olacağını anlattı. Kişi herkesin annesi olamaz, yalnız bazılarının annesidir; bu yüzden $y$ için "bazı" ($\exists$) kullanılır. Baştaki $\forall x$ ise önermenin bütün kişiler için geçerli olduğunu söyler.

## 8. Karşı Örnek ve Niceleyicilerde De Morgan

### 8.1 Karşı örnek

Bazı $x$'ler $P(x)$'i yanlış yaparsa evrensel önerme $\forall x\, P(x)$ yanlış olur. $P(x)$'i yanlış yapan $x$ değerine **karşı örnek** (counterexample) denir. Örneğin "her tam sayı $x$ için $x$ asaldır" önermesinde $4$ bir karşı örnektir.

### 8.2 Niceleyicilerde De Morgan kuralı

$\forall x\, P(x)$ önermesinin değili alınınca De Morgan'daki gibi "her" yerine "bazı" gelir ve $P(x)$'in değili alınır:

$$\lnot \forall x\, P(x) \equiv \exists x\, \lnot P(x)$$

Yani "her $x$ için doğru değildir" ile "bazı $x$'ler için doğru değildir" aynı anlamı taşır. Tersi de geçerlidir:

$$\lnot \exists x\, P(x) \equiv \forall x\, \lnot P(x)$$

Hoca bu noktada "$x$ asal sayı, $x^2 < 10$" biçiminde bir $P(x)$ örneği verdi ve "her $x$ için" önermesinin yanlış olduğunu, değili alınınca "bazı $x$'ler için yanlıştır" önermesine dönüştüğünü söyledi. <!-- BELİRSİZ: Bu örneğin tam metni altyazıda net değil ve o ana ait kare yok. -->

### 8.3 Kalkülüs örneği

Slayttaki örnek (ekrandan, 00:55:00):

- "Every student in the class has taken a course in calculus" önermesi evrensel niceleyicidir: $\forall x\, P(x)$; $P(x)$: "$x$ kalkülüs dersi almıştır".
- Değili: "It is not the case that every student in the class has taken a course in calculus."
- Bu, şuna denktir: "There is a student in the class who has not taken a course in calculus."
- Bu da asıl önerme fonksiyonunun değilinin varoluşsal niceleyicisidir: $\exists x\, \lnot P(x)$.
- Örnek şu denkliği gösterir: $\lnot \forall x\, P(x) \Leftrightarrow \exists x\, \lnot P(x)$.

Hoca, "her öğrencinin bu dersi aldığı durum değildir" cümlesini yorumlamanın zor olduğunu, De Morgan uygulanınca elde edilen "sınıfta bu dersi almamış bir öğrenci vardır" cümlesinin daha kolay anlaşıldığını söyledi.

Ters yönde: "Sınıfta kalkülüs dersi almış bir öğrenci vardır" önermesi $\exists x\, Q(x)$ biçimindedir. Değili "It is not the case that there is a student in this class who has taken a course in calculus" olur; bu da "Sınıftaki her öğrenci için, öğrenci kalkülüs dersini almamıştır", yani $\forall x\, \lnot Q(x)$ demektir.

Özet:

| Önerme | Denk değili | Ne zaman doğru? |
|---|---|---|
| $\lnot \exists x\, P(x)$ | $\forall x\, \lnot P(x)$ | Her $x$ için $P(x)$ yanlışsa |
| $\lnot \forall x\, P(x)$ | $\exists x\, \lnot P(x)$ | $P(x)$'i yanlış yapan bir $x$ varsa |

## 9. İspatın Temelleri: Terim, Tanım, Aksiyom, Teorem

Aradan sonra ispat konusuna geçildi. Bir matematik sistemi şu yapı taşlarından oluşur (slayt listesi, ekrandan, 01:15:00):

- **Tanımlanmamış terimler (undefined terms):** Kabullerle ortaya konan temel kavramlardır. Öklit geometrisinde nokta ve doğru gibi.
- **Tanım (definition):** Yeni bir kavram yaratmak amacıyla önceden kabul edilmiş kavramlar ve tanımlanmamış terimlerden bir önerme oluşturmaktır. Slayttaki Öklit geometrisi örnekleri (ekrandan, 01:15:00):
  - Eğer iki üçgenin karşılıklı kenarları ve açıları birbirinin aynı ise bu iki üçgen eş üçgendir.
  - İki açının toplamı 180 derece ise bu açılara birbirini tamamlayan açılar denir.
- **Aksiyom (axiom):** Matematiksel bir sistem içinde ispat yapılmadan doğru kabul edilen önermedir. Örnekler:
  - İki nokta verilmişse bu noktalardan geçen bir doğru her zaman vardır.
  - Bir doğru ve doğru üzerinde olmayan bir nokta verilmişse, bu noktadan geçen doğrulardan biri verilen doğruya paraleldir.
- **Teorem:** Önceden ispatlanmış teoremler, aksiyomlar ve tanımlar kullanılarak, $p$'nin doğru olduğu varsayılıp $p \rightarrow q$ biçiminde ispatlanan önermedir.

Hoca bir aksiyomun doğruluğunu göstermek için ya bütün olasılıkları denemek gerektiğini (bu imkânsızdır) ya da aksine ispat, çelişki gibi tekniklere başvurmak gerektiğini söyledi. Bu yüzden aksiyomlar ispatsız kabul edilir.

### 9.1 İspat çeşitleri

İspat, bir teoremin doğruluğunu belirlemek için kullanılan mantıksal çıkarım yöntemidir. Derste ele alınan yöntemler:

- Doğrudan ispat (direct proof),
- Dolaylı ispat / olmayana ergi (indirect proof, karşıt tersle ispat),
- Çelişki ile ispat (proof by contradiction),
- Tümevarım (mathematical induction),
- Karşı örnek (counterexample),
- Deneme yanılma / kaba kuvvet (brute force).

Hoca tümevarımın özdeşliklerin ispatında kullanıldığını, $1 + 2 + \dots + n = \dfrac{n(n+1)}{2}$ (Gauss toplamı) gibi ifadelerin bu yöntemle gösterildiğini söyledi. Bu yöntemlerin bir kısmını slayttan değil, tahta olarak kullandığı not uygulamasında yazarak anlattı.

## 10. Doğrudan İspat

Doğrudan ispat, $p \rightarrow q$ biçimindeki önermelerin ispatıdır. Genellikle $p$ daha basit bir ifade, $q$ ise daha karmaşık bir ifadedir (tahtada "basit" ve "complex" diye işaretlendi, ekrandan, 01:25:00). Örnekler:

- "$n$ tek sayı ise $n^2$ tektir": $p$: $n$ tek sayıdır, $q$: $n^2$ tektir.
- "$m$ ve $n$ çift ise $m + n$ çifttir": $p$: $m$ ve $n$ çifttir, $q$: $m + n$ çifttir.

Doğrudan ispatın üç adımı vardır (ekrandan, 01:25:00 ve 02:15:00):

1. $p \rightarrow q$ için $p$ doğru kabul edilir.
2. $q$ önermesinin doğruluğu gösterilmeye çalışılır.
3. $p \rightarrow q$'nun doğruluğu söylenir.

Hoca bunun en temel yöntem olduğunu, diğerlerinin de bundan türediğini söyledi.

### 10.1 Örnek: $n$ çift ise $n^2$ çifttir

Kaynak: (ekrandan, 01:30:00). $p$: $n$ çifttir; $q$: $n^2$ çifttir.

1. $n = 2k$, $k \in \mathbb{Z}$ doğru kabul edilir.
2. $n^2 = (2k)^2 = 4k^2 = 2 \cdot (2k^2)$. $p = 2k^2$, $p \in \mathbb{Z}$ denirse $n^2 = 2p$ olur.
3. $n^2 = 2p$ çift sayı formatında olduğu için $n^2$ çift sayıdır.

Burada başta kabul edilen çift sayı biçimi ($2k$) ile aynı biçimde ($2p$) bir sonuç üretildi. Aynı formatta üretilebildiği için sonuç da çift sayıdır.

**Soru:** İkinci adımda neden $p = 2k^2$ dendi, anlaşılmadı. **Cevap:** Çift sayının genel formatı "2 çarpı bir tam sayı"dır. $n = 2k$ yerine yazılınca $n^2 = 4k^2 = 2 \cdot 2k^2$ elde edilir. $2k^2$'ye $p$ denirse $n^2 = 2p$ olur; bu, baştaki çift sayı formatına uygundur.

**Soru:** Buradaki $p$'nin mantıktaki $p$ önermesiyle bir ilgisi var mı? **Cevap:** Yok; buradaki $p$ bir değişkendir (tam sayı), önerme değildir.

Hoca bu örneğin slayttaki hâlini de sonradan gösterdi ve slayda $p = 2k^2$ satırını kendisinin eklediğini söyledi (ekrandan, 02:15:00). Slaytta $n^2 = 4k^2 = 2(2k^2)$ yazıyor ve "$p \in \mathbb{Z}$, $p = 2k^2$ için $n^2 = 2p$ olur" satırı ekli. Hocanın açıklamasına göre $2k$ yerine $p$ denilseydi $2p^2$ biçimi çıkardı; çiftlik yine görülebilirdi ama "$2p$" formatında yazmanın daha açık olduğunu düşündü.

### 10.2 Doğrudan ispatın yetmediği durum

"$n^2$ çift ise $n$ çift sayıdır" önermesi doğrudan ispatla yapılamaz (ekrandan, 01:30:00). Doğrudan denense $n^2 = 2k$, $k \in \mathbb{Z}$ yazılır. Buradan $n = \sqrt{2k}$ elde edilir. Bu ifadeden $n$'nin bir tam sayının iki katı olduğu sonucu çıkarılamaz. Doğrudan ispat bu yüzden yetersiz kalır. Slayttaki not da aynı şeyi söylüyor (ekrandan, 02:15:00): "$m + n$ çift sayı ise $m$ ve $n$ çift sayıdır önermesi doğrudan ispat yöntemi ile ispat edilemez."

## 11. Dolaylı İspat (Karşıt Ters)

Dolaylı ispat (indirect proof), olmayana ergi ya da karşıt tersle ispat (contrapositive) olarak da anılır. Doğrudan ispatla yapılamayan önermelerde kullanılır. Fikir şudur: $p \rightarrow q$ yerine onun karşıt tersi $\lnot q \rightarrow \lnot p$ doğrudan ispatlanır. Yani aslında yine doğrudan ispat yapılır, ama dolaylı bir şekilde.

Örnek önermeler: "$n^2$ tek ise $n$ tek sayıdır", "$m + n$ tek ise ..." gibi. Hoca bu ve benzer örneklerin birçok kitapta bulunabileceğini söyledi.

### 11.1 Neden işe yarar?

Hoca karşıt tersin asıl önermeyle denk olduğunu doğruluk tablosuyla yeniden gösterdi (ekrandan, 01:35:00):

| $p$ | $q$ | $p \rightarrow q$ | $\lnot q$ | $\lnot p$ | $\lnot q \rightarrow \lnot p$ |
|---|---|---|---|---|---|
| 0 | 0 | 1 | 1 | 1 | 1 |
| 0 | 1 | 1 | 0 | 1 | 1 |
| 1 | 0 | 0 | 1 | 0 | 0 |
| 1 | 1 | 1 | 0 | 0 | 1 |

(Tahtada yalnız $p \rightarrow q$ sütunu yazıldı; karşıt ters sütunu hocanın sözlü hesabından kuruldu.) İki sütun aynı olduğu için karşıt ters doğrudan ispatlanabilirse asıl önerme de ispatlanmış olur.

### 11.2 Örnek: $n^2$ tek ise $n$ tektir

$p$: $n^2$ tek sayıdır; $q$: $n$ tek sayıdır. Karşıt ters için önce değiller bulunur.

Hoca sınıfa $p$'nin değilini sordu. Bir öğrenci "$n^2$ çift sayıdır" cevabını verdi, hoca da doğru buldu: başka durum yoktur, bu yüzden "$n^2$ tek değildir" demek yerine "$n^2$ çifttir" denir.

> **Hocanın vurgusu:** Olumsuzu başka, tersi başkadır.

$\lnot q$: $n$ çift sayıdır. Yeni önerme: "$n$ çift sayı ise $n^2$ çift sayıdır" ($\lnot q \rightarrow \lnot p$). Bu, doğrudan ispatla gösterilir:

1. $n = 2k$, $k \in \mathbb{Z}$.
2. $n^2 = 4k^2 = 2 \cdot (2k^2)$. Karışmasın diye $u = 2k^2$, $u \in \mathbb{Z}$ denir.
3. $n^2 = 2u$; $n^2$ çift sayıdır.

Böylece $\lnot q \rightarrow \lnot p$ doğrudur. Bunun karşıt tersi olan $p \rightarrow q$ da doğrudur. Yani "$n^2$ tek sayı ise $n$ tek sayıdır" ispatlanmış olur. Tahtada sonuç "$\therefore$ $n^2$ çift sayıdır, doğrudur ($q' \Rightarrow p'$); $\therefore$ $p \Rightarrow q$ önermesi de doğrudur" diye yazıldı (ekrandan, 01:40:00).

## 12. Çelişki ile İspat

Çelişki ile ispatta (proof by contradiction) bir $p$ önermesinin ya da $p \rightarrow q$ önermesinin **olumsuzu** ispat edilir (ekrandan, 01:40:00). Kendisi değil, olumsuzu ele alınır. Olumsuzun yanlış olduğu gösterilerek önermenin kendisinin doğruluğu dolaylı olarak elde edilir.

- $p$ önermesi için: $p$'nin yanlışlığı incelenir.
- $p \rightarrow q$ için: önce temel bağlaçlarla $\lnot p \lor q$ yazılır, sonra değili alınır. De Morgan ile $\lnot(\lnot p \lor q) \equiv p \land \lnot q$ elde edilir. Bunun yanlış olduğu ispatlanır.

Hoca tipik örnekleri verdi: "$\sqrt{2}$ irrasyoneldir" önermesini ispat etmek yerine $\sqrt{2}$'nin rasyonel olmadığı ispatlanır. Benzer biçimde, $\sqrt{4}$ için "tam sayı değildir" iddiası ispat edilemez; tam sayı olduğu ispatlanır.

### 12.1 Örnek: $n$ tek ise $n^2$ tektir

Kaynak: (ekrandan, 01:45:00). $p$: $n$ tektir; $q$: $n^2$ tektir. Çelişki için $p \land \lnot q$, yani "$n$ tek ve $n^2$ çift" kabul edilir ve bunun yanlışlığı ispatlanır.

1. "$n$ tek ise $n^2$ çift sayıdır" ($p \Rightarrow q'$) doğru kabul edilir.
2. $n = 2k + 1$, $k \in \mathbb{Z}$ doğru kabul edilir.
   - $n^2 = (2k + 1)^2 = 4k^2 + 4k + 1 = 2(2k^2 + 2k) + 1$.
   - $t = 2k^2 + 2k$, $t \in \mathbb{Z}$ denirse $n^2 = 2t + 1$ olur.
   - $\therefore$ $n^2$ tek sayıdır.

Böylece birinci maddedeki kabulün ($n^2$ çift) yanlış olduğu görülür. Hoca bunu doğruluk değerleriyle de anlattı: $n$ tek kabul edildiği için $p = 1$'dir. $\lnot q$ ("$n^2$ çifttir") yanlış çıktığı için $\lnot q = 0$'dır. Bu durumda

$$p \land \lnot q = 1 \land 0 = 0$$

olur. Olumsuz yanlış olduğuna göre asıl önerme $p \rightarrow q$ doğrudur.

Hoca farkı şöyle özetledi: önceki örnekte "$n$ tek ise $n^2$ tektir" doğrudan ispatlanabilirdi; burada aynı önerme "$n$ tek ise $n^2$ çift değildir" mantığıyla ispatlanıyor ve bu da bizi aynı yola çıkarıyor.

## 13. İspat Sorusuna Nasıl Cevap Verilir?

Hoca sorulabilecek soru tiplerini anlattı:

- Bir önerme verilip "doğrudan ispatla", "dolaylı ispatla" ya da "çelişki ile ispatlayın" denirse, o yöntemin kuralları uygulanır.
- Bir önerme verilip yöntem seçimi size bırakılabilir. Bu durumda bağlam anlaşılıp hangi yöntemin kullanılacağı seçilir ve **gerekçesi** yazılır ("... çünkü ...").

Her iki durumda da izlenecek yol aynıdır (ekrandan, 01:50:00):

- Yöntem belirlenir (doğrudan / dolaylı / çelişki) ve neden seçildiği yazılır.
- $p$ ve $q$ belirlenir.
- İspat adımları (1, 2, 3) yazılır ve sonuç söylenir ("as a result of these steps").

Hoca üç yöntemin de bir anlamda aynı şeyi yaptığını ekledi.

### 13.1 "Falancanın teoremine göre" bir ispat değildir

Hoca daha önce verdiği bir ödev sorusunu anlattı: "Pozitif sayılar kümesinde $x^4 + y^4 = 625$ ifadesinin çözümünün olmadığını, hangi ispat yöntemini kullandığınızı belirterek açıklayınız." Sınıfa nasıl ispatlanabileceğini sordu; bir öğrenci "tersine ispat" dedi. Hoca bunun için önermenin $p \rightarrow q$ biçiminde yazılıp tersinin alınması gerektiğini söyledi. Tahtada ayrıca $a^2 + b^2 = 625 = 25^2$ ifadesini doğru yapan bir $(a, b)$ ikilisi olup olmadığı sorusu da yazıldı (ekrandan, 01:55:00).

Ödevde bazı cevaplar "Fermat'ın teoremine göre ispatı ..." biçimindeydi. Hoca bunun bir ispat olmadığını vurguladı.

> **Hocanın vurgusu:** "Falancanın teoremine göre böyledir" diyerek bilimsel yöntemle bir şey ispat edilmez; bu ancak rivayettir. İspat, derste görülen yöntemlerle adım adım yapılır.

Hoca bunu $a^4 + b^4 + c^4 = d^4$ örneğine bağladı: biri bu denklemin çözümü olmadığını söylemişti. Herkes "falancaya göre böyledir" deyip geçseydi, bugün hâlâ çözümün olmadığını kabul ediyor olurduk. Ayrıca aynı cevabı birden fazla kişinin vermesinin, bilginin internetten sorgulanmadan kopyalandığını gösterdiğini; bunun hem yanlış bilgi almak hem de onu sorgulamamak anlamına geldiğini söyledi. Bir cevap kopyalanacaksa bile en azından dersin içeriğine ve yöntemlerine uygun olmalıdır.

## 14. Tümevarım

Tümevarım (mathematical induction), genellikle özdeşliklerin ve bazı teoremlerin ispatında kullanılır. Hoca bunu bir **merdiven** benzetmesiyle anlattı: merdivenin sağlamlığı en alt basamaktan en üst basamağa kadar tutarlılığa bağlıdır. Bir basamak sağlamsa bir sonraki de sağlam olabilir; her basamağın sağlamlığı bir öncekine bağlıdır.

Önce kümenin ilk elemanına bakılır. Hoca bunun her zaman $1$ olmadığını, örneğin $3$'ten başlayıp beşer beşer artan sayılar için bir teorem verilseydi önce $3$'ün deneneceğini söyledi.

### 14.1 Örnek: $1 + 2 + \dots + n = \dfrac{n(n+1)}{2}$

Kaynak: (ekrandan, 02:00:00 ve 02:10:00). $n \in \{1, 2, \dots, n\}$.

1. **Temel adım:** $n = 1$ için $\dfrac{1 \cdot 2}{2} = 1$. Doğru. (İstenirse $n = 2$, $n = 3$ için de denenebilir. Bir adımda yanlış çıkarsa devam etmeye gerek yoktur.)
2. **Tümevarım varsayımı:** $n = k$ için $1 + 2 + \dots + k = \dfrac{k(k+1)}{2}$ doğru kabul edilir.

   > **Hocanın vurgusu:** Bu adım önemlidir; burada önerme şu an doğru kabul edilir.

3. **Tümevarım adımı:** $n = k + 1$ için $1 + 2 + \dots + k + (k+1) = \dfrac{(k+1)(k+2)}{2}$ olduğu ispatlanmalıdır. Sol taraftaki ilk $k$ terimin toplamı varsayıma göre $\dfrac{k(k+1)}{2}$'dir:

$$\frac{k(k+1)}{2} + (k+1) = \frac{k(k+1) + 2(k+1)}{2} = \frac{(k+1)(k+2)}{2}$$

Hoca bunu "$2$ tane $k+1$ ve $k$ tane $k+1$ var; $k+1$ parantezine alınca bir taraftan $k$, öbür taraftan $2$ gelir" diye açıkladı. Eşitlik sağlandığı için özdeşlik doğrudur (tahtada "DOĞRU" yazıldı, ekrandan, 02:10:00).

**Soru:** Birinci adımda yanlış çıkarsa ikinci adıma geçmeye gerek yok, değil mi? **Cevap:** Evet; birinci basamak yanlışsa öbür basamaklara bakmaya gerek yoktur.

### 14.2 Yanlış bir formülle deneme

Hoca bunu göstermek için yanlış bir formül denedi. $1 + 2 + \dots + n = \dfrac{n(n+3)}{2}$ olsun. $n = 1$ için $\dfrac{1 \cdot 4}{2} = 2 \ne 1$; temel adım zaten yanlıştır.

Hoca yine de tümevarım adımına baktı. Tahtada önce $\dfrac{k(k+4)}{2}$ yazdı (ekrandan, 02:05:00). Bir öğrenci formülün $n+3$ diye verilip $n+4$ ile hesaplandığını fark etti; hoca hesabı yeniden yaptı. Doğru hâliyle:

$$\frac{k(k+3)}{2} + (k+1) = \frac{k^2 + 5k + 2}{2}, \qquad \frac{(k+1)(k+4)}{2} = \frac{k^2 + 5k + 4}{2}$$

Sabit terimler ($2$ ve $4$) farklı olduğu için eşitlik sağlanmaz. (Tahtadaki ilk denemede de $k^2 + 6k + 2$ ile $k^2 + 6k + 5$ karşılaştırılmış, $2 \ne 5$ bulunmuştu.) Hesaplar python ile kontrol edildi.

> **Hocanın vurgusu:** Düğmeyi yanlış iliklerseniz aşağıda da yanlışa ulaşırsınız; ilk basamak yanlışsa devam etmeye gerek yoktur.

### 14.3 Tümevarımın genel adımları

Slayttaki terimlerle (slayt küçük resmi, ekrandan, 02:20:00):

- **Temel adım (basis step):** İlk eleman için doğruluk gösterilir.
- **Tümevarımsal adım (inductive step):** $k$'ıncı eleman için doğru kabul edilir, $k+1$'inci eleman için bu kabule dayanarak ispatlanır.
- **Sonuç (conclusion):** Bütün pozitif tam sayılar için önerme doğrudur.

### 14.4 Örnek: $n^3 - n$, $3$'e bölünür

Slayttaki örnek: $n$ pozitif tam sayıyken $n^3 - n$'nin $3$'e tam bölündüğünü ispatlayınız; yani $(n^3 - n) \bmod 3 = 0$.

1. $n = 1$: $1 - 1 = 0$, $0 \bmod 3 = 0$. Bölünür. Hoca $n = 2$ için de baktı: $8 - 2 = 6$, $6 / 3 = 2$; bölünür.
2. $n = k$ için $(k^3 - k) \bmod 3 = 0$ kabul edilir.
3. $n = k + 1$ için:

$$(k+1)^3 - (k+1) = k^3 + 3k^2 + 3k + 1 - k - 1 = (k^3 - k) + 3(k^2 + k)$$

İlk parça varsayım gereği $3$'e bölünür, ikinci parça $3$'ün katıdır. Toplam da $3$'e bölünür. Hoca slaydın bir sonraki adımı bir öncekiyle eşleştirerek sonuca ulaştığını anlattı. Sonuç python ile $n = 1, \dots, 199$ için de kontrol edildi.

## 15. Karşı Örnek ile İspat

Karşı örnekte (counterexample) önermenin doğruluğu değil, **yanlışlığı** gösterilir (tahtada "Counter Example: Yanlışlığı ...", ekrandan, 02:10:00). Bir önermenin doğruluğunu ispat etmek çoğu zaman zordur, ama önerme doğru ya da yanlış olacağı için tek bir aksine örnek yanlışlığı göstermeye yeter.

- "Tüm asal sayılar tek sayıdır." Bu önermenin doğruluğunu ispat etmek mümkün değildir. $2$ için önerme yanlıştır, çünkü $2$ hem asal hem çifttir.
- "Her gerçel $x$ için $x^2 > 0$." Doğru mu, yanlış mı? $x = 0$ için $0^2 = 0$ ve $0$, $0$'dan büyük değildir. Önerme aksine örnekle yanlıştır.

> **Hocanın vurgusu:** Çelişki ile karşı örneği karıştırmayın. Karşı örnekte önermenin üzerinde herhangi bir değil işlemi yapılmaz, De Morgan uygulanmaz; doğrudan belirli bir örnek gösterilir.

## 16. Deneme Yanılma (Kaba Kuvvet)

Deneme yanılma (trial and error) ya da kaba kuvvet (brute force) tekniği, $p$ ya da $p \rightarrow q$ biçimindeki bir önermenin **sonlu bir küme** (finite set) üzerinde ispatında kullanılır. Kümedeki her eleman tek tek denenir; hepsi sağlıyorsa önerme doğrudur. Hoca bunun bir program yazarak da yapılabileceğini söyledi.

Örnek (ekrandan, 02:30:00): $x \in \{-1, 0, 1\}$ için $x^2 < 4$ mü?

$$\big((-1)^2 < 4\big) \land \big(0^2 < 4\big) \land \big(1^2 < 4\big) = T \land T \land T = T$$

Bütün elemanlar sağladığı için önerme doğrudur.

## 17. Slaytlardaki Ek Örnekler

Hoca slaytlara geri döndü ve kendi anlattıklarının benzerlerinin slaytlarda da olduğunu gösterdi.

### 17.1 $3n + 2$ tek ise $n$ tektir

$n$ bir tam sayı ve $3n + 2$ tek ise $n$'nin tek olduğu ispatlanacak. Önce doğrudan denenir: $3n + 2 = 2k + 1$ yazılırsa $3n + 1 = 2k$ olur. Buradan $n$'nin tek olduğu ispatlanamaz, çünkü elde $n$ değil $3n + 1$ vardır.

Bu yüzden dolaylı ispat kullanılır. Karşıt ters: "$n$ çift ise $3n + 2$ de çifttir." $n = 2k$ kabulüyle

$$3n + 2 = 6k + 2 = 2(3k + 1)$$

bulunur; $3k + 1$ bir tam sayı olduğundan $3n + 2$ çifttir. Karşıt ters doğru olduğu için "$3n + 2$ tek ise $n$ tektir" önermesi de doğrudur.

### 17.2 Diğer slayt örnekleri

Hoca önceki haftanın soru-cevap slaytlarında kalan kısmı da tamamladı. Bu örnekler aşağıdaki "Örnek Sorular" bölümünde verilmiştir: karşı örnek bulma, olumsuzlama (pizza örneği), $7n + 4$ çiftliği, Sherlock Holmes çıkarımı ve doğruluk değeri bulma.

## Örnek Sorular

**Soru 1** (ekrandan, 00:40:00): "You can not ride the roller coaster if you are under 4 feet tall unless you are older than 16 years old" cümlesini mantıksal ifadelerle yazınız. ($q$: you can ride the roller coaster, $r$: you are under 4 feet tall, $s$: you are older than 16 years old.)

> **Çözüm (derste):** $(r \land \lnot s) \rightarrow \lnot q$. Slaytta ikinci yazılış olarak $(\lnot r \lor s) \rightarrow q$ verilmiştir; bu ifade asıl önermenin tersidir ve ona denk değildir. Denk yazılış $q \rightarrow (\lnot r \lor s)$'tir (bkz. Bölüm 7.1'deki ders sonrası not).

**Soru 2** (ekrandan, 00:35:00 ve derste sözlü, 00:35:27): Her gerçel $x$ için $x^2 \ge 0$ doğru mudur? Aynı tanım kümesinde $x^2 \ge 1$ doğru mudur?

> **Çözüm (derste):** $x^2 \ge 0$ doğrudur. $x^2 \ge 1$ yanlıştır; $-1 < x < 1$ aralığındaki her sayı (örneğin $0$ ya da $0{,}9$) bir karşı örnektir.

**Soru 3** (ekrandan, 00:45:00): "For some real number $x$, $\dfrac{x}{x^2 + 1} = \dfrac{2}{5}$" önermesi doğru mudur?

> **Çözüm (derste):** Doğrudur; $x = 2$ için $\dfrac{2}{5}$ elde edilir.

**Soru 4** (derste sözlü, 00:38:21): Her pozitif tam sayı $n$ için $n^2 + n + 19$ asal mıdır? <!-- BELİRSİZ: Önermenin tam metni altyazıda bozuk; o ana ait kare yok. -->

> **Çözüm (derste):** Hayır. Hoca $n = 2$ için $25$ bulduğunu ve $25$ asal olmadığı için önermenin yanlış olduğunu gösterdi. (Ders sonrası not: $n = 1$ için de $21 = 3 \cdot 7$ asal değildir.)

**Soru 5** (derste sözlü, 00:45:11): Bazı pozitif tam sayılar $n$ için, $n$ asal ise $n+1$, $n+2$, $n+3$, $n+4$ asal değildir. Doğru mudur?

> **Çözüm (derste):** Doğrudur; $n = 23$ için $24, 25, 26, 27$ asal değildir.

**Soru 6** (derste sözlü, 00:46:51): "Everyone has exactly one best friend" cümlesini $B(x, y)$: "$y$, $x$'in en iyi arkadaşıdır" ile mantıksal olarak yazınız.

> **Çözüm (derste):** $\forall x\, \exists y\, \big(B(x, y) \land \forall z\, ((z \ne y) \rightarrow \lnot B(x, z))\big)$.

**Soru 7** (ekrandan, 00:50:00): "If somebody is female and is a parent, then this person is someone's mother" cümlesini $F(x)$, $P(x)$, $M(x, y)$ ile yazınız.

> **Çözüm (derste):** $\forall x\, \big((F(x) \land P(x)) \rightarrow \exists y\, M(x, y)\big)$.

**Soru 8** (ekrandan, 00:55:00): "Every student in the class has taken a course in calculus" önermesinin değilini yazınız.

> **Çözüm (derste):** $\lnot \forall x\, P(x) \equiv \exists x\, \lnot P(x)$: "Sınıfta kalkülüs dersi almamış bir öğrenci vardır."

**Soru 9** (ekrandan, 01:30:00 ve 02:15:00): $n$ çift sayı ise $n^2$'nin de çift sayı olduğunu ispat ediniz.

> **Çözüm (derste):** $n = 2k$, $k \in \mathbb{Z}$; $n^2 = 4k^2 = 2(2k^2) = 2p$, $p = 2k^2 \in \mathbb{Z}$. $n^2$ çift sayı formatında olduğundan çifttir.

**Soru 10** (derste sözlü, 01:31:37): $n^2$ tek ise $n$'nin tek olduğunu ispatlayınız.

> **Çözüm (derste):** Karşıt ters: $n = 2k$ ise $n^2 = 2(2k^2) = 2u$ çifttir. Karşıt ters doğru olduğu için asıl önerme de doğrudur.

**Soru 11** (ekrandan, 01:45:00): $n$ tek ise $n^2$'nin tek olduğunu çelişki ile ispatlayınız.

> **Çözüm (derste):** $p \land \lnot q$ ("$n$ tek ve $n^2$ çift") kabul edilir. $n = 2k + 1$ için $n^2 = 2(2k^2 + 2k) + 1$ tektir; $\lnot q = 0$, $p \land \lnot q = 0$. Olumsuz yanlış olduğundan $p \rightarrow q$ doğrudur.

**Soru 12** (derste sözlü, 01:51:41): Pozitif sayılar kümesinde $x^4 + y^4 = 625$ ifadesinin çözümünün olmadığını, hangi ispat yöntemini kullandığınızı belirterek açıklayınız. <!-- BELİRSİZ: Hoca soruyu $x^4 + y^4$ diye okudu, tahtada ise $a^2 + b^2 = 625$ yazdı (ekrandan, 01:55:00). Burada sözlü okunan biçim esas alındı; "pozitif sayılar" büyük olasılıkla pozitif tam sayılar demektir. -->

> **Çözüm (derste verilmedi):** Pozitif tam sayılarda kaba kuvvetle ispatlanabilir. $5^4 = 625$ olduğundan $x, y \ge 5$ olamaz; $x, y \in \{1, 2, 3, 4\}$ olmalıdır. Bu değerlerin dördüncü kuvvetleri $1, 16, 81, 256$'dır. İki tanesinin toplamı en fazla $256 + 256 = 512 < 625$ olur. Hiçbir ikili $625$'i vermez, dolayısıyla çözüm yoktur (python ile $1 \le x, y < 30$ aralığında kontrol edildi). Tahtadaki $a^2 + b^2 = 625$ biçiminin ise çözümü vardır: $7^2 + 24^2 = 15^2 + 20^2 = 625$; yani kare biçimi için "çözüm yoktur" iddiası yanlış olurdu.

**Soru 13** (ekrandan, 02:00:00 ve 02:10:00): $1 + 2 + \dots + n = \dfrac{n(n+1)}{2}$ özdeşliğini tümevarımla ispatlayınız.

> **Çözüm (derste):** $n = 1$: $1 = 1$. $n = k$ için doğru kabul edilir. $n = k + 1$: $\dfrac{k(k+1)}{2} + (k+1) = \dfrac{(k+1)(k+2)}{2}$. Doğrudur.

**Soru 14** (ekrandan, 02:20:00): İlk $n$ adet pozitif tek sayının toplamının $n^2$ olduğunu ispatlayınız: $S_n = 1 + 3 + 5 + \dots = n^2$.

> **Çözüm (slaytta):** $n = 1$ için $1 = 1^2 = 1$ (doğru). $n = 2$ için $1 + 3 = 2^2 = 4$ (doğru). $n = k$ için $1 + 3 + 5 + \dots + (2k - 1) = k^2$ doğru kabul edilir. $n = k + 1$ için $1 + 3 + \dots + (2k - 1) + (2(k+1) - 1) = k^2 + (2k + 1) = k^2 + 2k + 1 = (k + 1)^2$. Doğrudur.

**Soru 15** (derste sözlü, 02:18:09): $n$ pozitif tam sayıyken $n^3 - n$'nin $3$'e tam bölündüğünü ispatlayınız.

> **Çözüm (derste):** $n = 1$: $0$; $n = 2$: $6$; ikisi de $3$'e bölünür. $n = k$ için kabul edilir. $(k+1)^3 - (k+1) = (k^3 - k) + 3(k^2 + k)$, iki parça da $3$'e bölünür.

**Soru 16** (derste sözlü, 02:20:39): Tanım kümesi tam sayılar olmak üzere, mümkünse karşı örnek bulunuz: (a) $\forall x\, \exists y\, (x = 1/y)$; (b) $\forall x\, \forall y\, (x^2 \ne y^3)$. <!-- BELİRSİZ: Slaytta bu iki önermenin arasında bir üçüncü önerme daha var (hocanın anlatımında "$x$ eksi yüzden küçük olabilir" diye geçiyor); küçük resimden ve altyazıdan tam metni okunamadı. -->

> **Çözüm (derste):** (a) $x = 0$ için $0 = 1/y$ eşitliğini sağlayan bir tam sayı $y$ yoktur; önerme yanlıştır. (b) $(x, y) = (0, 0)$ ya da $(1, 1)$ için $x^2 = y^3$ olur; önerme yanlıştır.

**Soru 17** (derste sözlü, 02:21:43): Aşağıdakilerin olumsuzlarını yazınız: "Only students eat pizza", "All students eat pizza", "Some students eat only pizza".

> **Çözüm (derste):** "Sadece öğrenciler pizza yer" önermesinin olumsuzu: öğrenci olmayan biri de pizza yer. "Bütün öğrenciler pizza yer" önermesinin olumsuzu: pizza yemeyen bir öğrenci vardır. "Bazı öğrenciler sadece pizza yer" önermesinin olumsuzu: sadece pizza yiyen öğrenci yoktur, yani bütün öğrenciler pizzadan başka şeyler de yer. <!-- BELİRSİZ: Olumsuzların tam İngilizce metni slaytın küçük resminden okunamadı; cevaplar hocanın sözlü anlatımından kuruldu. -->

**Soru 18** (derste sözlü, 02:22:42): $n$ pozitif bir tam sayı ise, $n$'nin ancak ve ancak $7n + 4$ çift olduğunda çift olduğunu gösteriniz.

> **Çözüm (derste):** $n$ çift ise $n = 2k$ ve $7n + 4 = 14k + 4 = 2(7k + 2)$ çifttir. Diğer yön için $n$ tek kabul edilir: $n = 2k + 1$ ise $7n + 4 = 14k + 11 = 2(7k + 5) + 1$ tektir. Yani $n$ tek ise $7n + 4$ tektir; bu, "$7n + 4$ çift ise $n$ çifttir" önermesinin karşıt tersidir. (Ara adım eklendi: $14k + 11 = 2(7k + 5) + 1$ yazılışı.)

**Soru 19** (ekrandan, 02:25:00): "If Sherlock Holmes is successful, the Professor Albert will be apprehended. If Dr. Watson doesn't slip up, then Sherlock Holmes will locate the missing clue. If Sherlock Holmes locates the missing clue, then he is successful. Dr. Watson doesn't slip up. Therefore Professor Albert will be apprehended." Önermeleri ve çıkarımı yazınız.

> **Çözüm (slaytta):** $p$: Sherlock Holmes is successful; $q$: Professor Albert is apprehended; $r$: Dr. Watson slips up; $s$: Sherlock Holmes locates the missing clue. Hipotezler: $p \rightarrow q$, $\lnot r \rightarrow s$, $s \rightarrow p$, $\lnot r$. Sonuç: $q$. ($\lnot r$ ve $\lnot r \rightarrow s$ ile $s$; $s \rightarrow p$ ile $p$; $p \rightarrow q$ ile $q$ elde edilir.)

**Soru 20** (derste sözlü, 02:25:14): Tanım kümesi gerçel sayılar olmak üzere doğruluk değerlerini bulunuz: (a) her $x$ için $x^2 > x$; (b) her $x$ ve her $y$ için $x^2 + y^2 = 9$; (c) bazı $x$ ve bazı $y$ için $x^2 + y^2 = 9$. <!-- BELİRSİZ: (a) şıkkı altyazıda "x kare artı x" diye geçiyor; karşı örnek $1/2$ verildiği için büyük olasılıkla $x^2 > x$ önermesidir. Slaytta dördüncü bir şık daha var ($x^2 + y^2 = 0$ ile ilgili), niceleyicileri altyazıdan net çıkmıyor. -->

> **Çözüm (derste):** (a) Yanlış; $x = 1/2$ için $1/4 > 1/2$ sağlanmaz. (b) Yanlış; bir karşı örnek vardır (örneğin $x = y = 0$). (c) Doğru; $x = 1$, $y = \sqrt{8}$ için $1 + 8 = 9$.

**Soru 21** (ekrandan, 02:30:00): $\sqrt{3}$ sayısının irrasyonel olduğunu ispat ediniz. Yöntemi ve ispat adımlarını yazınız.

> **Çözüm (derste verilmedi):** Çelişki ile ispat kullanılır. $\sqrt{3}$'ün rasyonel olduğu, yani $\sqrt{3} = \dfrac{a}{b}$ ($a, b$ tam sayı, $b \ne 0$, kesir sadeleşmiş, $\gcd(a, b) = 1$) olduğu kabul edilsin. Kare alınırsa $a^2 = 3b^2$ olur, yani $3 \mid a^2$. $3$ asal olduğundan $3 \mid a$; $a = 3c$ yazılabilir. Yerine konursa $9c^2 = 3b^2$, yani $b^2 = 3c^2$ ve $3 \mid b$ olur. Böylece $3$ hem $a$'yı hem $b$'yi böler; bu, kesrin sadeleşmiş olması kabulüyle çelişir. Kabul yanlış olduğuna göre $\sqrt{3}$ irrasyoneldir.

**Soru 22** (ekrandan, 02:30:00): $x \in \{-1, 0, 1\}$ için $x^2 < 4$ olduğunu kaba kuvvetle gösteriniz.

> **Çözüm (derste):** $((-1)^2 < 4) \land (0^2 < 4) \land (1^2 < 4) = T \land T \land T = T$.

## Dersin Toparlaması

Bu derste önce önermeler mantığının ispatlar için gereken parçaları tekrar edildi: koşullu önerme ve onun $\lnot p \lor q$ ile denkliği, karşıt, ters ve karşıt ters, çift yönlü önerme, totoloji ve De Morgan kanunu. Ardından niceleyicilere geçildi. $\forall$ gizli bir VE, $\exists$ gizli bir VEYA olarak yorumlandı; tanım kümesinin önermenin doğruluğunu nasıl değiştirdiği, karşı örneğin evrensel bir önermeyi nasıl çürüttüğü ve niceleyicilerde De Morgan kuralı ($\lnot \forall x\, P(x) \equiv \exists x\, \lnot P(x)$) örneklerle gösterildi. Doğal dildeki cümleler niceleyicili mantık ifadelerine çevrildi.

İkinci bölümde ispat konusu işlendi. Tanımlanmamış terim, tanım, aksiyom ve teorem kavramlarından sonra doğrudan ispat, karşıt terse dayanan dolaylı ispat, $p \land \lnot q$'nun yanlışlığını gösteren çelişki ile ispat, merdiven benzetmesiyle tümevarım, karşı örnek ve sonlu kümelerde kaba kuvvet yöntemleri örneklerle anlatıldı. Hoca bir ispatın bilimsel yöntemlerle adım adım yapılması gerektiğini, "falancanın teoremine göre" demenin ispat olmadığını vurguladı. Sonraki derste mantık konusunun lojik devrelerle ilişkisine ve bilgisayar mühendisliğindeki uygulamalarına geçileceği söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
