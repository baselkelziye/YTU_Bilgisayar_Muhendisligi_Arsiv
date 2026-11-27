# Ders 5 Genişletilmiş Notu: Düzenli İfadeler, NFA'dan Düzenli İfadeye Dönüşüm ve Düzenli Olmayan Diller

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Düzenli İfadeler ve Düzenli Diller
- 2. Düzenli İfadenin Dili
- 3. Dilden Düzenli İfadeye: Örnekler
- 4. Tek Uzunluklu Dizgiler Örneği
- 5. 00 İçermeyen Dizgiler ve Denk Düzenli İfadeler
- 6. Teorem: Düzenli İfadeler ve Düzenli Diller
- 7. NFA'dan Düzenli İfadeye Dönüşüm
- 8. Düzenli Dillerin Standart Gösterimleri
- 9. Düzenli Olmayan Diller ve Makinenin Gücü
- 10. Güvercin Yuvası İlkesi ve Döngüler
- Örnek Sorular

## 1. Düzenli İfadeler ve Düzenli Diller

Ders, önceki derste girişi yapılan düzenli ifadelerle (regular expressions) devam eder. Anlatım ağırlıkla İngilizcedir; bazı yerler Türkçe tekrar edilir. Ekrandaki ilk slaytın başlığı "Regular Expressions"tır ve şu cümleyi taşır: düzenli ifadeler düzenli dilleri betimler. Hoca, "düzenli dil nedir?" sorusunun cevabını slayta elle ekler: düzenli diller, sonlu otomatların tanıdığı dillerdir (ekrandan, 00:05:00).

### 1.1 İlk Örnek: $(a+b\cdot c)^*$

Slayttaki örnek $(a+b\cdot c)^*$ ifadesidir. İfadede yalnızca üç sembol görüldüğü için alfabe $\Sigma=\{a,b,c\}$ alınır. İfadenin parçaları şöyle okunur:

- $a$, $b$, $c$: alfabedeki semboller.
- $^*$: Kleene yıldızı.
- $+$: birleşim (union).
- $\cdot$: birleştirme (concatenation).
- Parantezler: işlemler arasında öncelik verir.

$a+b\cdot c$ küme diliyle $\{a\}\cup\{bc\}=\{a,bc\}$'dir. Bunun yıldızı alınınca

$$\{a,bc\}^*=\{\varepsilon, a, bc, aa, abc, bca, \dots\}$$

elde edilir (ekrandan, 00:05:00).

### 1.2 Temel Öğeler ve İşlemler

Hoca tanımın öğelerini sırayla geçer. $\varepsilon$ boş dizgidir (empty string) ve uzunluğu her zaman sıfırdır: $|\varepsilon|=0$. İki düzenli ifade $r_1$ ve $r_2$ verildiğinde $r_1+r_2$ birleşimi, $r_1\cdot r_2$ birleştirmeyi, $r_1^*$ Kleene yıldızını, $(r_1)$ ise yalnızca önceliği gösterir. Hoca sınıfa "listede hangi işlem yok?" diye sorar; olumsuzlama (negation) ve ters çevirme (reverse) gibi işlemlerin tanımda yer almadığını belirtir.

> **Ek bilgi (derste anlatılmadı):** Tümleme ve ters çevirme düzenli ifade işleçleri arasında yer almasa da düzenli diller bu işlemler altında kapalıdır (önceki derste gösterildi). Yani bu işlemlerle elde edilen diller de düzenlidir; yalnızca ifadeleri doğrudan bir işleçle yazılamaz, yeniden kurulması gerekir.

### 1.3 Düzenli İfade Olan ve Olmayan

Sonraki slaytta (ekrandan, 00:10:00) $(a+b\cdot c)^*\cdot(c+\varepsilon)$ bir düzenli ifade örneğidir. Hoca dilini $\{a,bc\}^*\cdot\{\varepsilon,c\}$ diye yazar. Birleştirme yapılınca önce $\varepsilon$ ile birleştirilen $\{\varepsilon,a,bc,aa,abc,bca,\dots\}$ elemanları, sonra sonlarına $c$ eklenmiş $c, ac, bcc, abcc,\dots$ elemanları gelir. Hoca, ifadenin çok basit, dilin ise sonsuz ve tek tek yazılamayacak kadar karmaşık olduğunu vurgular.

Aynı slayttaki $(a+b+)$ ise düzenli ifade değildir: ikinci $+$ işleminin sağında bir işlenen yoktur, yani tanım kuralları uygulanmamıştır. Hoca eksik parçayı ekleyince ifadenin düzenli ifade olduğunu, silince yeniden kurala aykırı hâle geldiğini gösterir.

## 2. Düzenli İfadenin Dili

### 2.1 $L(r)$ Gösterimi ve Bir Otomatın Dili

$L(r)$, düzenli ifade $r$'nin dilidir. Slaytta $L((a+b\cdot c)^*)=\{\varepsilon,a,bc,aa,abc,bca,\dots\}$ örneği vardır (ekrandan, 00:15:00). Hoca buna bir de makine ekler; $L(M)$ makine $M$'nin dilidir. Çizilen makinenin geçişleri:

| Durum | Sembol | Gidilen durum |
|---|---|---|
| $q_0$ (başlangıç) | $1$ | $q_0$ |
| $q_0$ | $0$ | $q_1$ |
| $q_1$ (kabul) | $0$ | $q_1$ |
| $q_1$ | $1$ | $q_0$ |

Hoca yolları izleyerek ifade yazar: $q_0$'da $1^*$ okunur, $0$ ile kabul durumuna gidilir ($1^*0$); ya da kabul durumunda $0^*$ ile kalınır ($1^*00^*$); ya da kabul durumundan $1$ ile dönülüp yeniden $0$ ile gelinir. Ekranda $1^*0+1^*00^*+1^*00^*1^*0$ yazılıdır. Hoca bazı parçaların diğerlerinin alt kümesi olduğunu, bu yüzden gerekmediğini söyler ve Kleene yıldızıyla sadeleştirmeye gider. <!-- BELİRSİZ: Hocanın vardığı son sade ifade karede ve altyazıda net değil. -->

> **Ders sonrası not:** Bu makine $q_1$'e yalnız $0$ okuyarak girer ve $1$ okuyunca $q_0$'a döner; yani tam olarak $0$ ile biten dizgileri kabul eder: $L(M)=L((0+1)^*0)$. Ekrandaki üç parçalı ifade bu dilin yalnız bir alt kümesidir; örneğin $0100$ ve $01010$ dizgilerini kapsamaz (python ile 10 uzunluğa kadar kontrol edildi).

### 2.2 Temel (İlkel) Düzenli İfadeler

Hoca temel düzenli ifadeleri sıralar:

- $\varepsilon$ bir düzenli ifadedir; dili $\{\varepsilon\}$'dur.
- Tek bir sembol, örneğin $a$, bir düzenli ifadedir; dili $\{a\}$'dır.
- $a+b+c$'nin dili $\{a,b,c\}$'dir.
- $ab+cd$'nin dili $\{ab,cd\}$'dir; burada birleştirme vardır.

Semboller ve boş dizgi ilkel (primitive) düzenli ifadelerdir. Hoca ardından sınıfa boş dilin (empty language) düzenli ifadesini sorar.

> **Ek bilgi (derste anlatılmadı):** Boş dilin düzenli ifadesi $\emptyset$ sembolüdür ve $L(\emptyset)=\{\}$'dir. $\varepsilon$ ile karıştırılmamalıdır: $L(\varepsilon)=\{\varepsilon\}$ bir elemanlı bir kümedir.

### 2.3 Tanımın Devamı

Ekrandaki "Definition (continued)" slaytı (ekrandan, 00:20:00), $r_1$ ve $r_2$ düzenli ifadeleri için şu eşitlikleri verir:

$$L(r_1+r_2)=L(r_1)\cup L(r_2)$$
$$L(r_1\cdot r_2)=L(r_1)\,L(r_2)$$
$$L(r_1^*)=(L(r_1))^*$$
$$L((r_1))=L(r_1)$$

Hoca bu eşitliklerin düzenli ifade işlemleri ile küme işlemleri arasında birebir çeviri sağladığını söyler. Son satır, parantezin dili değiştirmediğini, yalnızca işlemler arasında öncelik kurduğunu gösterir.

### 2.4 Örnek: $(a+b)\cdot a^*$

Hoca slayttaki $(a+b)\cdot a^*$ örneğini adım adım açar. $L((a+b)a^*)=L(a+b)\,L(a^*)=(L(a)\cup L(b))\,(L(a))^*=\{a,b\}\{\varepsilon,a,aa,\dots\}$. Birleştirme yapılınca $a$ sembolü $\varepsilon$, $a$, $aa$, ... ile, $b$ sembolü de aynı elemanlarla birleştirilir: $\{a,aa,aaa,\dots,b,ba,baa,\dots\}$.

### 2.5 Örnek: $(a+b)^*(a+bb)$

Ekrandaki örnek (ekrandan, 00:25:00):

$$r=(a+b)^*(a+bb)$$
$$L(r)=L(a+b)^*\cdot\{a,bb\}=\{a,b\}^*\{a,bb\}=\{\varepsilon,a,b,aa,ab,ba,bb,aaa,aab,\dots\}\{a,bb\}$$

Hoca birleştirmeyi tek tek yapar: $\varepsilon$ ile $a$ → $a$; $\varepsilon$ ile $bb$ → $bb$; $a$ ile $a$ → $aa$; $a$ ile $bb$ → $abb$; $b$ ile $a$ → $ba$; $b$ ile $bb$ → $bbb$. Böylece

$$L(r)=\{a,bb,aa,abb,ba,bbb,\dots\}, \qquad |L(r)|=\infty$$

bulunur. $|L|$ kümenin eleman sayısını (kardinalitesini) gösterir. Hoca, eleman sayısı sonsuz olan bir dille doğrudan çalışmanın zor olduğunu, bu yüzden analizde dilin yerine düzenli ifadesinin kullanıldığını vurgular.

### 2.6 Örnek: $(aa)^*(bb)^*b$

Hoca bu ifadenin dilini yazarken sık yapılan bir hatayı gösterir. Bir küme ile bir sembol doğrudan birleştirilmez; her parça önce kümeye çevrilmelidir:

$$L((aa)^*(bb)^*b)=\{aa\}^*\{bb\}^*\{b\}$$

İlk küme $\{\varepsilon,aa,aaaa,\dots\}$'dır, yani çift sayıda $a$. İkinci küme çift sayıda $b$ verir, sona bir $b$ daha eklenir. $a$ sayısı ile $b$ sayısı birbirinden bağımsız olduğu için iki ayrı üs gerekir:

$$L((aa)^*(bb)^*b)=\{a^{2n}b^{2m}b : n,m\ge 0\}$$

(ekrandan, 00:30:00; karenin üst kenarında görünür). Python ile 10 uzunluğa kadar doğrulandı.

### 2.7 Örnek: $(0+1)^*00(0+1)^*$

Ekrandaki örnek (ekrandan, 00:30:00):

$$r=(0+1)^*00(0+1)^*, \qquad L(r)=\{0,1\}^*\{00\}\{0,1\}^*$$

$(0+1)^*$, $\{0,1\}$ alfabesiyle üretilebilecek bütün dizgilerin kümesidir; boş dizgi de, $0$ ve $1$'lerden oluşan herhangi bir dizgi de bunun elemanıdır. İçinde alfabe dışı bir sembol (örneğin $a$) geçen dizgi eleman değildir. İfadenin ortasında $00$ bulunduğundan

$$L(r)=\{\text{içinde } 00 \text{ alt dizgisi geçen bütün dizgiler}\}$$

olur. Hoca bu tür dillerde iki yönü de bilmek gerektiğini söyler: ifade verilince dil, dil verilince ifade yazılabilmelidir.

## 3. Dilden Düzenli İfadeye: Örnekler

### 3.1 00 ya da 010 İçeren Dizgiler

$L=\{\text{00 ya da 010 içeren bütün dizgiler}\}$ için (ekrandan, 00:35:00):

$$r=(0+1)^*(00+010)(0+1)^*$$

"Ya da" birleşimle ($00+010$) yazılır; başa ve sona bütün dizgiler ($(0+1)^*$) konur.

**Soru:** Sondaki $(0+1)^*$, "ya da" dendiği için mi konuyor? **Cevap:** Hayır. Baştaki ve sondaki $(0+1)^*$ bütün dizgileri gösterdiği için ifade "dizginin herhangi bir yerinde $00$ ya da $010$ var" anlamına gelir. $00$'ın solunda ve sağında her dizgi olabilir, birden fazla $00$ da bulunabilir. Sondaki parça kaldırılsaydı dil "$00$ ya da $010$ ile biten dizgiler" olurdu.

### 3.2 00 ve 010 İçeren Dizgiler

"Ya da" yerine "ve" konunca iki koşul birlikte sağlanmalıdır. $00$ önce de görülebilir, $010$ önce de; aralarında bir sıra yoktur. Hoca bu iki seçeneği birleşimle yazar (ekrandan, 00:40:00; karenin üst kenarında görünür):

$$r=(0+1)^*00(0+1)^*010(0+1)^*+(0+1)^*010(0+1)^*00(0+1)^*$$

> **Ders sonrası not:** Bu ifade, iki alt dizginin üst üste bindiği dizgileri kapsamaz. Örneğin $0100$ ($010$ ve $00$ ortak bir $0$ paylaşır) ve $0010$ dizgilerinin ikisi de $00$ ve $010$ içerir ama ifadede yoktur. Tam ifade için $(0+1)^*(0100+0010)(0+1)^*$ terimi de eklenmelidir; ekleme yapılınca dil 12 uzunluğa kadar python ile doğrulandı.

### 3.3 00 ya da 010 ile Biten Dizgiler

$L=\{\text{00 ya da 010 ile biten bütün dizgiler}\}$ için (ekrandan, 00:40:00):

$$r=(0+1)^*00+(0+1)^*010=(0+1)^*(00+010)$$

### 3.4 00 ya da 11 ile Başlayan ya da Biten Dizgiler

Hoca önce "00 ile başlayan ya da biten" dili yazmaya başlar, sonra soruyu zorlaştırır: $L=\{\text{00 ya da 11 ile başlayan ya da biten bütün dizgiler}\}$ (ekrandan, 00:45:00). Olası biçimleri listeler: $00\dots$, $11\dots$, $00\dots11$, $11\dots00$, $\dots00$, $\dots11$. Hangilerinin ayrıca yazılması gerektiğini sorar.

Bir öğrenci "ilk ikisi ve son ikisi" der. Hoca, $00\dots11$ biçiminin zaten $00\dots$ biçiminin alt kümesi olduğunu gösterir: $00$'dan sonraki kısım herhangi bir dizgi olabildiği için sonu $11$ olan dizgiler de oradadır. Aynı şey $11\dots00$ için geçerlidir. Bu yüzden dört parça yeter:

$$r=00(0+1)^*+11(0+1)^*+(0+1)^*00+(0+1)^*11$$
$$r=(00+11)(0+1)^*+(0+1)^*(00+11)$$

Python ile 10 uzunluğa kadar doğrulandı.

### 3.5 00 ya da 11 ile Başlayıp Biten Dizgiler

Hoca "ya da" yerine "ve" yazar: dizgi $00$ ya da $11$ ile başlamalı **ve** $00$ ya da $11$ ile bitmelidir. Sınıfa hangi biçimlerin geçerli olduğunu sorar. Bir öğrenci eksik olduğunu, $00\dots00$ ve $11\dots11$'in yanında $00\dots11$ ve $11\dots00$ biçimlerinin de geçerli olduğunu söyler. Hoca ifadeyi şöyle yazar:

$$r=(00+11)(0+1)^*(00+11)$$

> **Ders sonrası not:** Bu ifade en az dört uzunluklu dizgileri üretir. $00$, $11$, $000$ ve $111$ dizgileri de "00 ya da 11 ile başlayıp biten" koşulunu sağlar ama ifadede yoktur (python ile kontrol edildi). Tam ifade için $+00+11+000+111$ eklenmelidir. Hoca $000$ ve $111$ durumunu bir sonraki örnekte bir öğrencinin uyarısıyla ele alır.

## 4. Tek Uzunluklu Dizgiler Örneği

Hoca son dili bir adım daha zorlaştırır (ekrandan, 00:50:00):

$$L=\{\text{00 ya da 11 ile başlayıp biten, tek uzunluklu bütün dizgiler}\}$$

$w\in L$ ise $|w|$ tektir, yani $1,3,5,7,\dots$ olabilir. Dizgi $(00+11)\dots(00+11)$ biçimindedir. Baştaki ve sondaki parçaların uzunluğu ikişer, yani çifttir. Toplam tek olacaksa aradaki parçanın uzunluğu tek olmalıdır: $1,3,5,\dots$. Bu durumda dizginin uzunluğu en az 5'tir; 1 ve 3 olamaz, 5, 7, 9, 11, ... olabilir (ekrandan, 00:55:00 ve 01:00:00).

**Soru (öğrenci yorumu):** Eleman sayısını $2n+1$ biçiminde tek tutmak gerektiğini anladım ama bunu ifadede nasıl zorlayacağımızı bilmiyorum.

**Soru:** Dizgi yalnız $000$ olsa kabul edilmez mi? Hem $00$ ile başlıyor hem $00$ ile bitiyor. **Cevap:** Evet, bu doğru bir nokta. Üç tane $0$ olursa bunu da kabul etmesi gerekir; aynı şekilde $111$ de. Hoca ifadenin sonuna $+000+111$ ekler ve bunun güzel bir sınav sorusu olacağını söyler.

### 4.1 Aradaki Tek Uzunluklu Parça

Aradaki parça için hoca küçük bir DFA kurar. Bir başlangıç durumu $q_0$ vardır; bir $0$ ya da $1$ gelince $q_1$'e geçilir. $q_1$ tek sayıda sembol okunduğunu gösteren kabul durumudur. $q_1$'den bir $0$ ya da $1$ gelince yeniden $q_0$'a dönülür. Bu DFA tam olarak tek uzunluklu dizgileri kabul eder.

| Durum | Sembol | Gidilen durum |
|---|---|---|
| $q_0$ (başlangıç) | $0, 1$ | $q_1$ |
| $q_1$ (kabul) | $0, 1$ | $q_0$ |

DFA'dan ifade okunur: önce bir $(0+1)$ ile kabul durumuna gelinir, sonra $q_1\to q_0\to q_1$ döngüsü ($(0+1)(0+1)$) yıldızla tekrarlanır. Yıldız açılınca $(0+1)(0+1)=00+01+10+11$ olur:

$$r_x=(0+1)\big((0+1)(0+1)\big)^*=(0+1)(00+01+10+11)^*$$

(ekrandan, 01:00:00). Sonuç ifade:

$$r=(00+11)\,r_x\,(00+11)+000+111$$

Python ile 10 uzunluğa kadar kontrol edildi: bu ifade tam olarak 00 ya da 11 ile başlayıp biten tek uzunluklu dizgileri üretir.

> **Hocanın vurgusu:** Bu tarzda çok sayıda soru üretilebilir; dil verildiğinde ifadesini yazabilmek gerekir.

## 5. 00 İçermeyen Dizgiler ve Denk Düzenli İfadeler

### 5.1 $(1+01)^*(0+\varepsilon)$

Aradan sonra ekrandaki örnek (ekrandan, 01:10:00):

$$r=(1+01)^*(0+\varepsilon), \qquad L(r)=\{1,01\}^*\cdot\{\varepsilon,0\}$$

Hoca önce $\{1,01\}^*$ kümesini açar (ekrandan, 01:15:00):

$$\{1,01\}^*=\{\varepsilon,1,01,11,101,011,111,1101,1011,10101,0111,01101,01011,010101,\dots\}$$

Bu kümedeki dizgilerde $00$ geçmez, ama hepsi (boş dizgi dışında) $1$ ile biter. Hoca bunu "$00$ içermeyen ama $1$ ile biten bütün dizgiler" diye yazar. Sonradan düzeltir: $r=(1+01)^*$'ın dili "boş dizgi ya da $00$ içermeyen ve $1$ ile biten bütün dizgiler"dir. Sona $(0+\varepsilon)$ eklenince dizgi ya olduğu gibi kalır ya da sonuna bir $0$ eklenir; sonu $1$ olduğu için yeni bir $00$ oluşmaz. Böylece

$$L(r)=\{\text{içinde 00 alt dizgisi geçmeyen bütün dizgiler}\}$$

bulunur.

### 5.2 $(1+10)^*$

Hoca ikinci bir ifadenin kümesini yazar: $\{\varepsilon,1,10,11,101,110,1010,\dots\}$. Bir öğrenci "00 içermeyen ve 1 ile başlayan bütün dizgiler" der, hoca onaylar. Başa $(0+\varepsilon)$ eklenince yine $00$ içermeyen bütün dizgiler elde edilir.

### 5.3 Denk Düzenli İfadeler

İki düzenli ifade $r_1$ ve $r_2$, dilleri aynıysa denktir. İfadeler farklı görünebilir ama aynı dili betimleyebilir. Ekrandaki slayt (ekrandan, 01:20:00):

$$r_1=(1+01)^*(0+\varepsilon)$$
$$r_2=(1^*011^*)^*(0+\varepsilon)+1^*(0+\varepsilon)$$
$$r_3=(0+\varepsilon)(1+10)^*$$
$$L(r_1)=L(r_2)=L(r_3)=L$$

Dolayısıyla $r_1$, $r_2$ ve $r_3$ denk düzenli ifadelerdir. Üçünün de 10 uzunluğa kadar aynı dili (00 içermeyen dizgiler) verdiği python ile kontrol edildi.

> **Hocanın vurgusu:** Sınavda bir öğrenci $r_1$'i, bir başkası $r_2$'yi, bir başkası $r_3$'ü bulabilir; hepsi doğrudur. $r_2$ de doğrudur ama biraz karmaşıktır; daha zarif çözümler olan $r_1$ ve $r_3$ tercih edilir.

## 6. Teorem: Düzenli İfadeler ve Düzenli Diller

**Teorem.** Düzenli ifadelerin ürettiği diller kümesi, düzenli diller kümesine eşittir. Yani düzenli ifadelerin betimleme gücü ile düzenli dillerin gücü aynıdır.

İki kümenin eşitliği iki yönlü alt küme ilişkisiyle gösterilir:

- 1. kısım: düzenli ifadelerin ürettiği diller $\subseteq$ düzenli diller.
- 2. kısım: düzenli diller $\subseteq$ düzenli ifadelerin ürettiği diller.

### 6.1 Birinci Kısım: Her Düzenli İfadenin Dili Düzenlidir

Her düzenli ifade $r$ için $L(r)$'nin düzenli olduğu, ifadenin boyu üzerinde tümevarımla ispatlanır.

- **Taban.** $\varepsilon$ ifadesi için tek durumlu, başlangıç durumu kabul durumu olan bir NFA vardır; dili $\{\varepsilon\}=L(\varepsilon)$'dir. Tek sembol $a$ için iki durumlu, tek $a$ geçişli bir NFA vardır; dili $\{a\}=L(a)$'dır. Bu dilleri tanıyan sonlu otomatlar bulunduğu için bunlar düzenli dillerdir.
- **Tümevarım varsayımı.** $r_1$ ve $r_2$ için $L(r_1)$ ve $L(r_2)$ düzenli dillerdir (ekrandan, 01:25:00).
- **Tümevarım adımı.** Düzenli diller birleşim, birleştirme ve Kleene yıldızı altında kapalıdır. $L(r_1+r_2)=L(r_1)\cup L(r_2)$, $L(r_1r_2)=L(r_1)L(r_2)$, $L(r_1^*)=(L(r_1))^*$ olduğundan bu diller de düzenlidir.

Hoca, örneğin $r=r_1+r_2$ için $L(r_1)$'i tanıyan $M_1$ ve $L(r_2)$'yi tanıyan $M_2$ makinelerinden yeni bir başlangıç durumu ve iki $\varepsilon$ geçişiyle birleşik makinenin kurulduğunu, bunun geçen hafta görüldüğünü hatırlatır. Böylece düzenli ifadelerin tanımladığı bütün dillerin düzenli olduğu gösterilmiş olur.

### 6.2 İkinci Kısım: Her Düzenli Dilin Bir Düzenli İfadesi Vardır

$L$ düzenli bir dil olsun. O hâlde $L$'yi kabul eden bir NFA vardır. Bu NFA'nın tek bir kabul durumu olduğu varsayılabilir; her NFA tek kabul durumlu hâle getirilebilir. Bu NFA'dan denk bir **genelleştirilmiş geçiş grafı** (generalized transition graph) kurulur: okların üzerindeki etiketler artık düzenli ifadedir. Örneğin bir okun üzerinde "$a, b$" yazıyorsa bunun yerine $a+b$ yazılır. Sonra durumlar teker teker silinir ve geriye kalan graftan düzenli ifade okunur.

## 7. NFA'dan Düzenli İfadeye Dönüşüm

### 7.1 Genelleştirilmiş Geçiş Grafı Örneği

Ekrandaki örnek (ekrandan, 01:30:00):

| Durum | Etiket | Gidilen durum |
|---|---|---|
| $q_0$ (başlangıç) | $b$ | $q_1$ |
| $q_1$ | $a$ | $q_0$ |
| $q_1$ | $b$ | $q_1$ |
| $q_1$ | $a, b$ | $q_2$ |
| $q_2$ (kabul) | $b$ | $q_2$ |

Genelleştirilmiş grafta $q_1\to q_2$ okunun etiketi $a+b$ olur. Hoca $q_1$'i siler. $q_0$'dan $b$ ile $q_1$'e gidilir, orada $b^*$ döngüsü vardır, sonra $a$ ile $q_0$'a dönülür: $q_0$'da $bb^*a$ döngüsü oluşur. $q_0$'dan kabul durumuna giden yol ise $bb^*(a+b)$'dir. $q_2$'deki $b$ döngüsü $b^*$ olarak kalır:

$$r=(bb^*a)^*\,bb^*(a+b)\,b^*$$

Bu ifadenin makinenin diline eşit olduğu python ile 10 uzunluğa kadar doğrulandı.

### 7.2 Yolları Sayarak İfade Yazma

Hoca kendi çizdiği örneklerle devam eder. Önce şu makineyi kurar (durum adları $q_0,q_1,q_2$; geçişler altyazıdaki okumadan kuruldu):

| Durum | Sembol | Gidilen durum |
|---|---|---|
| $q_0$ (başlangıç) | $1$ | $q_0$ |
| $q_0$ | $0$ | $q_1$ |
| $q_0$ | $1$ | $q_2$ |
| $q_1$ | $1$ | $q_1$ |
| $q_2$ | $1$ | $q_2$ |
| $q_2$ | $0$ | $q_1$ |

**Tek kabul durumu ($q_1$).** Kabul durumuna giden iki yol vardır: doğrudan $q_0\to q_1$ ve $q_0\to q_2\to q_1$. Her yol bir terim verir:

$$r=1^*01^*+1^*11^*01^*$$

**İki kabul durumu ($q_1$, $q_2$).** Artık üç yol vardır; $q_2$'de biten yol için $1^*11^*$ eklenir:

$$r=1^*01^*+1^*11^*+1^*11^*01^*$$

**Bütün durumlar kabul durumu.** $q_0$'da biten yol için $1^*$ de eklenir; dört yol olur:

$$r=1^*+1^*01^*+1^*11^*+1^*11^*01^*$$

Üç ifadenin de ilgili makinenin diline eşit olduğu python ile 10 uzunluğa kadar doğrulandı.

### 7.3 Döngülü Örnek

Hoca makineyi değiştirir: $q_0\to q_1$ geçişini kaldırıp $q_1\xrightarrow{0}q_0$ geçişini ekler ve üç durumu da kabul durumu yapar (ekrandan, 01:40:00 ve 01:45:00).

| Durum | Sembol | Gidilen durum |
|---|---|---|
| $q_0$ (başlangıç, kabul) | $1$ | $q_0$ |
| $q_0$ | $1$ | $q_2$ |
| $q_1$ (kabul) | $1$ | $q_1$ |
| $q_1$ | $0$ | $q_0$ |
| $q_2$ (kabul) | $1$ | $q_2$ |
| $q_2$ | $0$ | $q_1$ |

Bir öğrenci önce $1^*+1^*11^*+1^*11^*01^*+\dots$ biçiminde yazmaya başlar; ekranda bu kısmi ifade görünür (ekrandan, 01:45:00). Bir başka öğrenci $q_1\to q_0\to q_2\to q_1$ döngüsünün sonsuz kez dönülebileceğini fark eder. Hoca da ilk denemede işin içinden çıkamadığını açıkça söyler ve sınıfa bir liste yapmasını önerir. Kabul durumlarına giden yollar (ekrandan, 01:50:00):

- $q_0\to q_0$
- $q_0\to q_2$
- $q_0\to q_2\to q_1$

Listede önce $q_0\to q_1$ de yazılır, sonra bu doğrudan geçişin olmadığı fark edilip üstü çizilir.

**Soru:** İfadeyi yazarken önce kabul durumuna ulaşıp sonra o durumdaki döngüyü kendi Kleene yıldızı içinde mi yazıyoruz? **Cevap:** Kesinlikle öyle.

Her terim için yöntem şudur: önce kabul durumuna ulaşılır, sonra o durumdan çıkıp aynı duruma geri dönen döngü parantez içinde yazılıp yıldızlanır.

- $q_0$ için: $q_0$'da $1^*$ ile kalınır. $q_0$'dan çıkıp geri dönen döngü $1\,1^*\,0\,1^*\,0\,1^*$'dır ($q_0\to q_2$, $q_2$'de döngü, $q_2\to q_1$, $q_1$'de döngü, $q_1\to q_0$, $q_0$'da döngü). Terim: $1^*(1^*11^*01^*01^*)^*$.
- $q_2$ için: $1^*11^*$ ile $q_2$'ye gelinir, $q_2$'den çıkıp dönen döngü yıldızlanır. Terim: $1^*11^*(1^*01^*01^*11^*)^*$.
- $q_1$ için: $1^*11^*01^*$ ile $q_2$ üzerinden $q_1$'e gelinir, $q_1$'den çıkıp dönen döngü yıldızlanır. Terim: $1^*11^*01^*(1^*01^*11^*01^*)^*$. <!-- BELİRSİZ: Üçüncü terim karede tam görünmüyor, altyazıdaki sözlü anlatımdan kuruldu. -->

$$r=1^*(1^*11^*01^*01^*)^*+1^*11^*(1^*01^*01^*11^*)^*+1^*11^*01^*(1^*01^*11^*01^*)^*$$

Hoca ilk terim için iki yazım seçeneği gösterir ve döngünün başına $1^*$ koyan biçimi daha basit bulduğunu söyler.

**Soru:** Parantezin dışında zaten $1^*$ var; parantezin içi neden yine $1^*$ ile başlıyor? **Cevap:** Dıştaki $1^*$ ile $q_0$'da kalınır. Döngü yeniden $q_0$'dan başladığı için parantezin başındaki $1^*$ aynı durumdaki kalışı gösterir; $q_0$'dan $q_0$'a geri gelinir.

Her terimin ilgili kabul durumunda biten dizgilere, üç terimin birleşiminin de makinenin diline eşit olduğu python ile 10 uzunluğa kadar kontrol edildi.

### 7.4 Genel Durum Silme Kuralı

"In General: Removing a state" slaytında bir $q$ durumunun silinmesi anlatılır. $q_i\xrightarrow{a}q\xrightarrow{b}q_j$ ve $q_j\xrightarrow{c}q\xrightarrow{d}q_i$ yolları vardır, $q$'da $e$ döngüsü bulunur. $q$ silinince dört olası hareket yeni etiketlerle gösterilir:

| Hareket | Yeni etiket |
|---|---|
| $q_i\to q_j$ | $ae^*b$ |
| $q_j\to q_i$ | $ce^*d$ |
| $q_i$ döngüsü | $ae^*d$ |
| $q_j$ döngüsü | $ce^*b$ |

<!-- BELİRSİZ: Bu slaytın karesi yok; etiketler altyazıdan (Whisper harfleri karıştırmış) ve standart kuraldan kuruldu. -->

Hoca bunun otomat gösterimini sadeleştirmek olduğunu söyler. İşlem iki durum kalana kadar tekrarlanır (ekrandan, 01:55:00). Son grafta $q_0$'da $r_1$ döngüsü, $q_f$'de $r_4$ döngüsü, $q_0\xrightarrow{r_2}q_f$ ve $q_f\xrightarrow{r_3}q_0$ vardır. Sonuç ifade:

$$r=r_1^*r_2(r_4+r_3r_1^*r_2)^*, \qquad L(r)=L(M)=L$$

Bu, ispatın ikinci kısmını tamamlar.

> **Ders sonrası not:** Hoca sözlü olarak "$r_1^*r_2r_4^* + \dots r_4^*r_3r_1^*r_2$" biçiminde okudu; slayttaki doğru ifade $r_1^*r_2(r_4+r_3r_1^*r_2)^*$'dır. İkisi de "kabul durumuna git, sonra $q_f$'de kal ya da $q_0$'a dönüp yeniden gel" fikrini anlatır.

## 8. Düzenli Dillerin Standart Gösterimleri

Düzenli diller üç standart biçimde ifade edilir:

- DFA (deterministik sonlu otomat),
- NFA (deterministik olmayan sonlu otomat),
- düzenli ifade.

"Bir düzenli dil verildi" dendiğinde bu dilin bu üç standart gösterimden biriyle verildiği anlaşılır. Hoca, bir dili tanıyan makineyi bulmanın bir tür gerçekleme (implementation) olduğunu, ama bunun Java kodu yazmak gibi düşünülmemesi gerektiğini ekler.

## 9. Düzenli Olmayan Diller ve Makinenin Gücü

### 9.1 Düzenli ve Düzenli Olmayan Diller

Ekrandaki slayt (ekrandan, 02:00:00) iki grup gösterir. Düzenli dillere örnekler: $a^*b$, $b^*c+a$, $b+c(a+b)^*$. Bunlar için bir DFA ya da NFA bulunabilir. Düzenli olmayan dillere örnekler:

$$\{a^nb^n : n\ge 0\}, \qquad \{vv^R : v\in\{a,b\}^*\}$$

Bu diller için onları tanıyan bir NFA ya da DFA yoktur; sonlu otomatların gücü bu dilleri tanımaya yetmez.

### 9.2 $\{a^nb^m\}$ İçin DFA

Aradan sonra hoca "makinenin gücü" başlığıyla bir dil yazar (ekrandan, 02:20:00):

$$L=\{a^nb^m : m,n\ge 0\}=\{\varepsilon,a,b,ab,aa,aab,abb,aaa,\dots\}$$

Bu dili tanıyan bir DFA kurulur. Boş dizgi dilde olduğu için başlangıç durumu aynı zamanda kabul durumudur. Önce istenen sayıda $a$, ardından istenen sayıda $b$ okunur. Hoca her durumdan çıkan geçiş sayısının ikiye, yani alfabenin büyüklüğüne eşit olduğunu göstererek makinenin DFA olduğunu belirtir. Dilin başı $a^*$, devamı $b^*$ biçimindedir. <!-- BELİRSİZ: Çizilen DFA'nın tam geçişleri karelerden okunamadı; ara durum $q_1$ ve $b$ okuyunca geçilen $q_2$ durumu altyazıda geçer. -->

**Soru:** $q_1$ burada fazlalık olmadı mı? $a$ geldikçe $q_0$'ı kendi üstüne döndürseydik? **Cevap:** O da olur; ikisi birleştirilebilir, $q_1$ kaldırılabilir. Aynı dili tanıyan birden fazla makine olabilir, tıpkı aynı dili betimleyen birden fazla düzenli ifade olabileceği gibi.

> **Ek bilgi (derste anlatılmadı):** $L=\{a^nb^m\}$ dilinin düzenli ifadesi $a^*b^*$'dır. Üç durumlu bir DFA yeter: $a$ döngülü başlangıç/kabul durumu, $b$ döngülü ikinci bir kabul durumu ve $b$'den sonra $a$ gelirse gidilen bir tuzak durumu.

### 9.3 $\{a^nb^n\}$ İçin Sonsuz Durum Gerekir

Hoca sorudaki küçük bir değişikliğin dili çok değiştirdiğini gösterir: $m$ yerine $n$ yazar.

$$L=\{a^nb^n : n\ge 0\}=\{\varepsilon, ab, aabb, aaabbb, \dots\}$$

Bir makine kurmaya çalışır. Boş dizgi yüzünden başlangıç durumu kabul durumudur. $ab$ için bir $a$ ve bir $b$ geçişiyle bir kabul durumuna gidilir. $aabb$ için iki $a$'dan sonra iki $b$ okuyan ayrı bir zincir gerekir, $aaabbb$ için üç $a$ ve üç $b$ okuyan bir başka zincir. Dizgi uzadıkça durum sayısı da artar ve bunun bir sonu yoktur. Ekranda şu sonuç yazılır: $a^nb^n$ dilini $n\to\infty$ için tanımak için sonsuz sayıda durum gerekir; ama gerçekte durum sayısı sonludur. Bu yüzden $\{a^nb^n\}$ dilini tanıyan bir NFA ya da DFA yoktur, yani NFA ve DFA'nın gücü bu dili kabul etmeye yetmez. Sonuç olarak dil düzenli değildir.

$\{a^nb^m\}$ ise $a$ ve $b$ sayıları bağımsız olduğundan sonsuz dili birkaç duruma sığdırabilir; NFA ve DFA'nın gücü bu dile yeter.

### 9.4 Bir Dilin Düzenli Olmadığı Nasıl İspatlanır?

Bir dilin düzenli olmadığını göstermek, onu kabul eden hiçbir NFA, DFA ya da düzenli ifade olmadığını ispatlamak demektir. Bu doğrudan kolay değildir. Çözüm pompalama önsavıdır (pumping lemma); pompalama önsavı da güvercin yuvası ilkesine dayanır.

## 10. Güvercin Yuvası İlkesi ve Döngüler

### 10.1 İlke

$n$ güvercin ve $m$ güvercin yuvası olsun, güvercin sayısı yuva sayısından fazla olsun ($n>m$). Hoca bunu bir benzetmeyle anlatır: hava çok soğuk, kış ve güvercinlerin hiçbiri uçmuyor, hepsi yuvalarında. Yuva sayısı güvercin sayısından az olduğuna göre en az bir yuvada birden fazla güvercin olmalıdır.

DFA'ya uyarlandığında durumlar yuvalara, okunan sembollerle bir duruma her varış da bir güvercine karşılık gelir. $\{a^nb^n\}$ örneğinde sonsuz sayıda güvercin vardır ve her durumda yalnız bir güvercin olabildiği için sonsuz sayıda durum gerekir.

### 10.2 Dört Durumlu DFA

Ekrandaki DFA (ekrandan, 02:35:00):

| Durum | Sembol | Gidilen durum |
|---|---|---|
| $q_1$ (başlangıç) | $b$ | $q_1$ |
| $q_1$ | $a$ | $q_2$ |
| $q_2$ | $b$ | $q_2$ |
| $q_2$ | $a$ | $q_3$ |
| $q_3$ | $a$ | $q_2$ |
| $q_3$ | $b$ | $q_4$ |
| $q_4$ (kabul) | $b$ | $q_4$ |
| $q_4$ | $a$ | $q_3$ |

- $aab\in L(M)$: $q_1\xrightarrow{a}q_2\xrightarrow{a}q_3\xrightarrow{b}q_4$. Her durum bir kez kullanılır; her durumda bir güvercin vardır.
- $aabb\in L(M)$: son $b$ ile $q_4$'te kalınır. $q_4$ iki kez kullanılır, yani $q_4$'te iki güvercin vardır.
- $bbaabbb$: $q_1$'de iki, $q_2$'de bir, $q_3$'te bir, $q_4$'te üç güvercin olur.

Bu dizgilerin kabul edildiği python ile kontrol edildi. Döngüdeki sembol sayısı istenildiği kadar artırılabilir; uzunluk sonsuza giderse o durumda sonsuz güvercin olur. Böylece sonsuz bir dil dört durumun içine sıkıştırılmış olur: bazı durumlar birden fazla kez kullanılır. Hocanın deyişiyle bu bir "trik"tir: aynı durumu tekrar tekrar kullanarak sonsuzluk sonlu bir biçimde yakalanır.

Hoca sonsuzluk kavramı üzerine de durur. Sonlu bir yüzeyin içine sonsuz bir yüzey katlamadan konamaz. Sonsuzluk, matematikteki hayali sayı $i=\sqrt{-1}$ gibi zihinde kurulan bir kavramdır. Sonsuz bir dilin bütün elemanları hiçbir zaman tek tek gözlemlenemez; düzenli ifade ve otomatlar bu sonsuzluğu sonlu sayıda öğeyle ifade etmeye yarar. $\{a^nb^n\}$ gibi bir dili tanımak için sonsuz durum gerekir. Bu imkânsız olduğundan makinenin gücünü artırmak gerekir; o zaman makine artık NFA ya da DFA değil, daha güçlü bir makine olur.

### 10.3 Döngü ve Sonsuz Dil

Hoca bir NFA üzerinde döngüleri tek tek gösterir ve sonucu iki dilde de yazar:

> **Hocanın vurgusu:** Bir NFA ya da DFA'da döngü görüyorsanız dilin eleman sayısı sonsuzdur. Döngü, sonsuz boyutlu dil demektir.

Pompalama önsavı için başlangıç şudur. Sonsuz bir düzenli dil $L$ alalım. $L$'yi kabul eden bir DFA vardır. Dil sonsuz olduğu için bu DFA'da bir döngü olmalıdır. Ekrandaki örnekte geçişlerin çoğu soldan sağa ilerler; yalnızca geri dönen bir geçiş döngüye yol açar ve dilin sonsuz olmasının nedeni bu geçiştir. Pompalama önsavının ayrıntıları bir sonraki derse bırakılır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:10:00). $(a+b+)$ bir düzenli ifade midir?

> **Çözüm:** Hayır. İkinci $+$ işleminin sağında işlenen yoktur; tanım kuralları uygulanmamıştır.

**Soru 2** (ekrandan, 00:15:00). Başlangıç durumu $q_0$, kabul durumu $q_1$ olan, $q_0$'da $1$ döngüsü, $q_0\xrightarrow{0}q_1$, $q_1$'de $0$ döngüsü ve $q_1\xrightarrow{1}q_0$ geçişi olan makinenin dilinin düzenli ifadesini yazın.

> **Çözüm (derste verilmedi):** Makine tam olarak $0$ ile biten dizgileri kabul eder: $r=(0+1)^*0$. Derste yazılan $1^*0+1^*00^*+1^*00^*1^*0$ bu dilin yalnız bir alt kümesidir (python ile kontrol edildi).

**Soru 3** (derste sözlü, 00:17:55). Boş dilin düzenli ifadesi nedir?

> **Çözüm (derste verilmedi):** $\emptyset$; $L(\emptyset)=\{\}$.

**Soru 4** (ekrandan, 00:25:00). $L((a+b)^*(a+bb))$ kümesini yazın.

> **Çözüm:** $\{a,b\}^*\{a,bb\}=\{a,bb,aa,abb,ba,bbb,\dots\}$, $|L|=\infty$.

**Soru 5** (ekrandan, 00:30:00). $L((aa)^*(bb)^*b)$ dilini küme yazımıyla verin.

> **Çözüm:** $\{a^{2n}b^{2m}b : n,m\ge 0\}$.

**Soru 6** (ekrandan, 00:35:00). $\{0,1\}$ üzerinde 00 ya da 010 içeren bütün dizgilerin düzenli ifadesini yazın.

> **Çözüm:** $(0+1)^*(00+010)(0+1)^*$.

**Soru 7** (ekrandan, 00:35:00). 00 ve 010 içeren bütün dizgilerin düzenli ifadesini yazın.

> **Çözüm:** Derste $(0+1)^*00(0+1)^*010(0+1)^*+(0+1)^*010(0+1)^*00(0+1)^*$ yazıldı. Üst üste binen dizgiler ($0100$, $0010$) için $+(0+1)^*(0100+0010)(0+1)^*$ eklenmelidir (ders sonrası düzeltme, python ile doğrulandı).

**Soru 8** (ekrandan, 00:40:00). 00 ya da 010 ile biten bütün dizgilerin düzenli ifadesini yazın.

> **Çözüm:** $(0+1)^*00+(0+1)^*010=(0+1)^*(00+010)$.

**Soru 9** (ekrandan, 00:45:00). 00 ya da 11 ile başlayan ya da biten bütün dizgilerin düzenli ifadesini yazın.

> **Çözüm:** $(00+11)(0+1)^*+(0+1)^*(00+11)$.

**Soru 10** (derste sözlü, 00:45:12). 00 ya da 11 ile başlayıp biten bütün dizgilerin düzenli ifadesini yazın.

> **Çözüm:** Derste $(00+11)(0+1)^*(00+11)$ yazıldı. Kısa dizgiler için $+00+11+000+111$ eklenmelidir (ders sonrası düzeltme, python ile doğrulandı).

**Soru 11** (ekrandan, 00:50:00). 00 ya da 11 ile başlayıp biten, tek uzunluklu bütün dizgilerin düzenli ifadesini yazın.

> **Çözüm:** $r=(00+11)(0+1)\big((0+1)(0+1)\big)^*(00+11)+000+111$ (ekrandan, 01:00:00; python ile doğrulandı).

**Soru 12** (ekrandan, 01:10:00). $L((1+01)^*(0+\varepsilon))$ dilini sözle tanımlayın.

> **Çözüm:** İçinde 00 alt dizgisi geçmeyen bütün dizgiler.

**Soru 13** (ekrandan, 01:30:00). Bölüm 7.1'deki makinenin düzenli ifadesini durum silerek bulun.

> **Çözüm:** $(bb^*a)^*bb^*(a+b)b^*$.

**Soru 14** (derste sözlü, 01:33:33). Bölüm 7.2'deki makine için kabul durumu (a) yalnız $q_1$, (b) $q_1$ ve $q_2$, (c) bütün durumlar olduğunda düzenli ifadeyi yazın.

> **Çözüm:** (a) $1^*01^*+1^*11^*01^*$; (b) $+1^*11^*$; (c) $+1^*$.

**Soru 15** (ekrandan, 01:45:00). Bölüm 7.3'teki üç durumlu, bütün durumları kabul durumu olan makinenin düzenli ifadesini yazın.

> **Çözüm:** $1^*(1^*11^*01^*01^*)^*+1^*11^*(1^*01^*01^*11^*)^*+1^*11^*01^*(1^*01^*11^*01^*)^*$ (python ile doğrulandı).

**Soru 16** (ekrandan, 02:20:00). $\{a^nb^m : m,n\ge 0\}$ ve $\{a^nb^n : n\ge 0\}$ dillerini tanıyan birer DFA kurulabilir mi?

> **Çözüm:** İlki için kurulabilir ($a^*b^*$). İkincisi için sonsuz sayıda durum gerekir; bu dili tanıyan bir NFA ya da DFA yoktur, dil düzenli değildir.

## Dersin Toparlaması

Bu derste düzenli ifadeler ayrıntılı işlendi: işlemleri, bir düzenli ifadenin dilinin küme işlemleriyle nasıl bulunacağı ve "içerir", "ile başlar", "ile biter", "tek uzunluklu" gibi koşullarla verilen dillerin ifadelerinin nasıl yazılacağı. Aynı dili betimleyen farklı ifadelerin denk olduğu görüldü. Ardından düzenli ifadelerin tam olarak düzenli dilleri betimlediğini söyleyen teorem iki kısımda ispatlandı. Birinci kısım kapanma özelliklerine dayanan bir tümevarımdı. İkinci kısım NFA'dan genelleştirilmiş geçiş grafına geçip durum silerek düzenli ifade elde etmekti.

Dersin son bölümünde makinenin gücü sorusu açıldı. $\{a^nb^m\}$ bir DFA ile tanınırken $\{a^nb^n\}$ için sonsuz sayıda durum gerektiği ve bu dilin düzenli olmadığı gösterildi. Güvercin yuvası ilkesi ve "döngü varsa dil sonsuzdur" sonucu, bir sonraki derste anlatılacak pompalama önsavının temelini oluşturur. Hoca bundan sonra bağlamdan bağımsız dillere geçileceğini de söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
