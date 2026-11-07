# Ders 2 Genişletilmiş Notu: Olmayana Ergi, Tümevarım, Güvercin Yuvası İlkesi; Alfabe, Dizgi, Dil ve Düzenli Dillere Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. İspat Tekniklerine Dönüş: Doğrudan ve Yapıcı İspat
- 2. Olmayana Ergi
- 3. Tümevarım
- 4. Güvercin Yuvası İlkesi
- 5. Alfabe, Sembol ve Dizgi
- 6. Dizgi İşlemleri
- 7. Dil
- 8. Düzenli Diller
- 9. Diller Üzerinde Küme İşlemleri, Birleştirme ve Yıldız
- 10. Kapalılık
- 11. Sayıları Dizgi Olarak Yazmak
- 12. İşlemleri Dil Olarak Yazmak
- 13. Uzunluk, Önek ve Sonek
- 14. Artı İşlemi
- 15. Her Dil $\Sigma^*$'ın Alt Kümesidir
- 16. Tümleyen
- 17. Boş Küme ve Boş Dizgi

## 1. İspat Tekniklerine Dönüş: Doğrudan ve Yapıcı İspat

Ders İngilizce anlatıldı, araya Türkçe konuşmalar girdi. Hoca, geçen derste başlanan ispat tekniklerini hatırlatarak başladı. Doğrudan ispatta (direct proof) girdilerden yola çıkılır ve ispatlanmak istenen sonuca varılır.

Bir başka yol yapıcı ispattır (constructive proof). Yapıcı ispat genelde bir şeyin var olduğunu göstermek gerektiğinde kullanılır. Hocanın örneği şu önermeydi: $q$ ve $r$ irrasyonel olmak üzere, $q^r = p$ eşitliğini sağlayan rasyonel bir $p$ vardır.

Bir örnek vermek, yani o nesneyi kurmak, ispat için yeterlidir. Şu seçim yapılır:

- $q = \sqrt{2}^{\sqrt{2}}$. Hocanın ifadesiyle bu sayı irrasyoneldir.
- $r = \sqrt{2}$. Bu da irrasyoneldir.

Bu durumda $q^r = \left(\sqrt{2}^{\sqrt{2}}\right)^{\sqrt{2}} = \sqrt{2}^{\sqrt{2} \cdot \sqrt{2}} = \sqrt{2}^{2} = 2$ olur (ara adım eklendi). 2 rasyonel bir sayıdır. Bu kurulumun kendisi ispatı bitirir. Hoca, derste bir şeylerin varlığını göreceğimiz için bu tekniği kullanabileceğimizi söyledi.

> **Ek bilgi (derste anlatılmadı):** Derste $\sqrt{2}^{\sqrt{2}}$'nin irrasyonel olduğu söylendi ama ispatlanmadı. Bu sonuç basit bir hesap değildir. Gelfond-Schneider teoreminden çıkar.

## 2. Olmayana Ergi

### 2.1 Genel Fikir

Olmayana ergide (proof by contradiction) yanlış olan bir şeyden başlanır: teoremin tersinden. İspatlamak istediğiniz şey neyse, onun yanlış olduğunu varsayarsınız. Sonra adım adım ilerlersiniz ve bir noktada bir çelişkiye (contradiction) ulaşırsınız. Teoremin yanlış olduğunu varsaydığınızda çelişki çıktıysa, teorem doğrudur.

Yöntemin iki adımı vardır:

- Teoremin yanlış olduğunu varsay.
- Bu varsayımın bir çelişkiye götürdüğünü göster.

### 2.2 Teorem: $\sqrt{2}$ İrrasyoneldir

Hoca önce rasyonel ve irrasyonel sayıların ne olduğunu hatırlattı. Rasyonel sayılar (rational numbers), $m$ ve $n$ tam sayı (integer) olmak üzere $\frac{m}{n}$ biçimindeki sayıların kümesidir. İrrasyonel sayılar (irrational numbers) bu kümede olmayan sayılardır.

> **Ders sonrası not:** Hoca tanımı "$m$ ve $n$ tam sayıdır" diye yazdı. Tanımda $n \neq 0$ koşulu da gerekir, çünkü sıfıra bölme tanımsızdır.

İspat şu cümleyle başlar: Çelişki elde etmek için $\sqrt{2}$'nin rasyonel olduğunu varsayalım.

> **Hocanın vurgusu:** İspatın başına genelde "çelişki elde etmek için" (for obtaining a contradiction) diye yazılır. Böylece bu varsayımın yalnız çelişki elde etmek için kullanıldığı açıkça belli olur.

Varsayıma göre $\sqrt{2} = \frac{p}{q}$ yazılabilir, burada $p$ ve $q$ tam sayıdır. Çelişki, bu kesrin ortak çarpanı (common factor) olmayacak biçimde düşünülebilmesinden çıkacaktır. Bu yüzden şu kısıtlama da eklenir: $p$ ve $q$'nun ortak çarpanı yoktur.

Bunu neden varsayabiliriz? Hocanın örneği şuydu: $p = 9$, $q = 6$ olsun. O zaman

$$\frac{p}{q} = \frac{9}{6} = \frac{3 \cdot 3}{3 \cdot 2} = \frac{3}{2}$$

olur. Ortak çarpan her zaman sadeleştirilebilir. Genel olarak $p$ ve $q$'nun ortak çarpanı $d$ ise, $p$ yerine $p' = p/d$, $q$ yerine $q' = q/d$ kullanılır. O zaman $\frac{p'}{q'} = \sqrt{2}$ olur ve $p'$ ile $q'$ arasında ortak çarpan kalmaz. Yani sadeleştirmeden sonra, bölümü $\sqrt{2}$ veren ve ortak çarpanı olmayan bir $(p, q)$ çifti bulunur. Hoca buranın önemli olduğunu, çelişkinin buradan geleceğini söyledi.

> **Ders sonrası not:** "Ortak çarpan yok" ifadesindeki kastedilen, 1'den büyük ortak çarpan olmamasıdır. 1 her tam sayı çiftinin ortak çarpanıdır.

<!-- BELİRSİZ: Hocanın 00:15-00:18 arasında tahtaya yazdığı varsayım cümlelerinin tam metni altyazıda bozuk. Matematiksel içerik yukarıdaki gibidir. -->

Şimdi ispat ilerletilir:

- $\frac{p}{q} = \sqrt{2}$ olduğundan $\frac{p^2}{q^2} = 2$ olur.
- Buradan $2q^2 = p^2$ çıkar.
- $2q^2$ çifttir (even), çünkü 2 ile bir tam sayının çarpımı çifttir. O hâlde $p^2$ de çifttir ve dolayısıyla $p$ de çifttir.
- $p$ çift olduğundan $r$ bir tam sayı olmak üzere $p = 2r$ yazılabilir.
- Bu, $2q^2 = p^2$ eşitliğine konur: $2q^2 = (2r)^2 = 4r^2$.
- Buradan $q^2 = 2r^2$ çıkar.
- Az önceki mantıkla $2r^2$ çifttir. O hâlde $q^2$ çifttir ve dolayısıyla $q$ de çifttir.

> **Ek bilgi (derste anlatılmadı):** "$p^2$ çift ise $p$ çifttir" adımı derste gerekçelendirilmedi. Gerekçe şudur: Tek bir sayının karesi $(2k+1)^2 = 2(2k^2 + 2k) + 1$ olduğundan yine tektir. Yani $p$ tek olsaydı $p^2$ de tek olurdu.

Hoca burada "ama bu yanlış, bu bir çelişki" dedi. Bir öğrenci Türkçe olarak $p$ ve $q$'nun aralarında asal olduğunu ama ikisinin de çift çıktığını söyledi. Hoca bunu şöyle toparladı: Başta $p$ ile $q$ arasında ortak çarpan olamayacağını söylemiştik. Fakat ikisi de çift çıktığı için aralarında bir ortak çarpan olduğunu bulduk. Bu ortak çarpan 2'dir.

<!-- BELİRSİZ: 00:26:32'de hoca "That's not the right thing because D was something else" diyor. Tahtaya yazdığı bir ifadeyi düzeltiyor olmalı, ne yazdığı altyazıdan anlaşılmıyor. Argümanı etkilemiyor. -->

Bir çelişkiye vardık. Demek ki varsayımımız, yani $\sqrt{2}$'nin rasyonel olduğu varsayımı yanlıştır. O hâlde $\sqrt{2}$ irrasyoneldir.

Hoca yöntemi tekrar özetledi: İspatlamak istediğinizin tersini varsayarsınız, birkaç adım sonra bir şekilde çelişkiye gelirsiniz. Çelişki olduğuna göre "teorem yanlıştır" varsayımı yanlıştır. O hâlde teorem doğrudur ve ispatlanmıştır.

**Soru:** Başta rasyonel sayıların ne olduğuna dair bir hatırlatma yazmıştık. Bu bir aksiyom mu, bir tanım mı? Onu da ispatlamamız gerekiyor muydu?

**Cevap:** Hayır, onu ispatlamaya gerek yok. Çünkü o aksiyom da değil, tanımdır. Bir küme tanımlamış olduk. Rasyonel sayılar bir kümedir. Konuştuğumuz şey $\sqrt{2}$'nin o kümenin içinde olup olmadığıdır. Teorem o kümenin içinde olmadığını söylüyor, biz de bunu ispatladık.

## 3. Tümevarım

### 3.1 Genel Fikir

Bir başka ispat tekniği tümevarımdır (proof by induction). Genel fikir şöyledir: Önce teoremin bir sayı için geçerli olduğu ispatlanır. Bu sayı genelde $n = 1$'dir ama öyle olmak zorunda değildir. Bir sayı seçer ve teoremin bu sayı için geçerli olduğunu söylersiniz.

Sonra teoremin $n$ için doğru olduğunu varsayar ve $n+1$ için de doğru olduğunu ispatlarsınız. Teoremin 1 için doğru olduğunu biliyoruz. "$n$ için doğruysa $n+1$ için de doğrudur" diye de gösterdik. Öyleyse 1'den 2'ye, 2'den 3'e, oradan sonsuza kadar gidilir. İspat böylece tamamlanır.

Hoca gerekirse bunun tersinin de yapılabileceğini söyledi. Teoremin $n-1$ için de geçerli olduğu ispatlanır ve daha büyük bir değerden başlanırsa, bu yolla eksi sonsuza doğru gidilebilir. Ne istediğinize bağlı olarak başka adımlar da gerekebilir. Örneğin çift sayılarla ilgili bir şey ispatlamak istiyorsanız $n+2$ kullanmanız gerekebilir. Ama genel fikir aynıdır.

Bu adımların adları vardır ve hoca bunları unutmamamızı söyledi:

- **Tümevarımın tabanı (basis of the induction):** Teoremin belirli bir sayı için ispatlandığı adım.
- **Tümevarım adımı (induction step):** $n$ doğruysa $n+1$'in de doğru olduğunun ispatlandığı adım.

Hocaya göre bu tür ispat genelde özdeşlik (identity) ispatlarında kullanılır. Özellikle teoremin kendisini $n+1$ durumunun içinde bulabiliyorsanız tümevarım kolaydır.

### 3.2 Örnek: İlk $n$ Sayının Toplamı

**Teorem:** Her pozitif tam sayı $n$ için

$$1 + 2 + 3 + \dots + n = \frac{n(n+1)}{2}.$$

> **Hocanın vurgusu:** Teorem bütün pozitif tam sayılar içindir. Hoca önce "pozitif sayılar" dedi, hemen "tam sayılar" diye düzeltti ve bunun önemli olduğunu söyledi.

**Taban adımı:** $n = 1$ için sol taraf yalnız 1'dir. Sağ taraf $\frac{1 \cdot (1+1)}{2} = 1$'dir. $1 = 1$ olduğundan teorem $n = 1$ için geçerlidir.

**Tümevarım adımı:** Teoremin $n$ için doğru olduğu varsayılır. $n+1$ durumunda göstermek istediğimiz eşitlik şudur:

$$1 + 2 + 3 + \dots + n + (n+1) = \frac{(n+1)(n+2)}{2}.$$

Sol taraftaki $1 + 2 + \dots + n$ kısmı için özgün özdeşlik kullanılır. Bu kısım $\frac{n(n+1)}{2}$'ye eşittir. Hoca "gerisini sürdürüp ikisinin aynı olduğunu bulursunuz" dedi. Hesap şöyle tamamlanır (ara adım eklendi):

$$\frac{n(n+1)}{2} + (n+1) = \frac{n(n+1) + 2(n+1)}{2} = \frac{(n+1)(n+2)}{2}.$$

Bu, formülün $n+1$ için yazılmış hâlidir. İspat biter.

**Soru:** Taban için $n = 1$ aldık. Tümevarım adımı için de $n = 2$ almayacak mıydık?

**Cevap:** Hayır. Tümevarım adımında sayısal değil, denklem üzerinden ispatlamamız lazım. 2'yi sayısal olarak ispatlarsanız yalnız 2'yi ispatlamış olursunuz. Sonra 3'ü de ispatlamanız gerekir. Ama "$n$ doğruysa $n+1$ için de doğrudur" derseniz, herhangi bir sayı için doğruysa bir üstündeki sayı için de doğru olduğunu göstermiş olursunuz. Hepsini birden ispatlamış olursunuz. Birinci sayıyı sayısal olarak hesaplar ve doğru olduğunu söylersiniz. Diğerini özdeşlik üzerinden yaparsınız. Bir tanesi doğruysa bir sonraki de, ondan sonraki de doğrudur.

## 4. Güvercin Yuvası İlkesi

### 4.1 Fikir

İspatta işe yarayan bir başka şey güvercin yuvası ilkesidir (pigeonhole principle). Hoca bunun çok basit bir fikir olduğunu söyledi. Kavramı anlatmak için ekranda bir güvercin yuvası resmi paylaştı ve Türkçe açıkladı: Pigeon güvercindir, pigeonhole da güvercinin yuvasıdır. Yuvanın birden fazla bölmesi olur.

**Soru:** Bu bir tablo gibi bir şey mi olacak? Çünkü tablodaki gibi gözler var.

**Cevap:** Tablo değil, yalnız kutularımız olacak.

Resimde 9 kutu ve 10 güvercin vardı. İlke şunu söyler: 10 güvercini 9 yuvaya yerleştirmek istediğinizde yuvalardan birine 2 tane koymak zorundasınız. Hoca, "çok basit bir şey" diye düşünülebileceğini, ama bu mantıkla gidince bazı problemleri çözmenin kolaylaştığını söyledi.

Hoca ilkeyi İngilizce olarak da kurdu: Elimizde güvercin yuvaları ve güvercinler var. Güvercin sayısı yuva sayısından büyükse, içinde birden fazla güvercin bulunan en az bir yuva vardır. Güvercinleri birer birer koyduğunuzu düşünün. Her biri ayrı bir yuvaya gider, ta ki boş yuva kalmayana kadar. Sonraki güvercin için dolu bir yuva seçmek zorundasınız. Hangisini seçerseniz seçin, o yuvada birden fazla güvercin olur.

<!-- BELİRSİZ: Hocanın 00:47'de çizdiği kutu ve güvercin sayısı altyazıdan okunmuyor ("now you have three"). -->

### 4.2 Matematiksel İfade

Daha matematiksel yazılırsa: $A$ ve $B$ kümeleri için eleman sayıları $|A| > |B|$ ise, $A$'dan $B$'ye bire bir fonksiyon (one-to-one function) yoktur.

Bire bir fonksiyon demek, $A$'daki her eleman için $B$'de ayrı bir karşılık bulmak demektir. $A$'nın eleman sayısı daha büyükse böyle bir eşleme bulunamaz.

### 4.3 Örnek: 1'den 11'e Yedi Sayı

**Teorem:** 1'den 11'e kadar olan sayılardan 7 farklı sayı seçilirse, seçilen sayılardan ikisinin toplamı 12'dir.

Hoca önce teoremin ne dediğini anlamak için bir örnek yaptı. Küme $S = \{1, 2, \dots, 11\}$ olsun. Bir seçim $P = \{1, 5, 6, 7, 10, 11, 3\}$ olabilir. Teorem, seçim nasıl yapılırsa yapılsın bu sayılardan bazılarının toplamının 12 olacağını söylüyor. Burada $1 + 11 = 12$'dir. Bir çift yeterlidir.

> **Ders sonrası not:** Hoca bu seçimde başka bir çift olmadığını düşündü. Oysa $5 + 7 = 12$ de bu seçimdedir. Seçimdeki çiftler tam taramayla $(1, 11)$ ve $(5, 7)$ olarak bulundu. Teoremin sonucu değişmez.

Hoca bunun bir ispat olmadığını vurguladı. Çünkü her seçim için en az bir çiftin toplamının 12 olduğu gösterilmelidir. Bu örnek yalnız teoremi anlamaya yarar.

**İspat fikri.** Her sayı için toplamı 12 yapan sayı yazılır: 1 için 11, 2 için 10, 3 için 9, 4 için 8, 5 için 7. 6 için yine 6 gerekir, ama yalnız bir tane 6 vardır. Böylece şu kümeler kurulur:

$$\{1, 11\},\quad \{2, 10\},\quad \{3, 9\},\quad \{4, 8\},\quad \{5, 7\},\quad \{6\}.$$

1'den 11'e kadar bütün sayılar bu kümelerde yer alır. Toplam 6 küme vardır. Bu kümeler güvercin yuvalarıdır, yapılacak 7 seçim de güvercinlerdir. İlk altı seçim için bu kümelerden birini seçersiniz. Yedinci seçimde ise daha önce seçilmiş bir yuvadan seçmek zorundasınız. Böylece aynı kümeden gelen iki sayının toplamı doğrudan 12 eder.

Hoca, bu fikrin önce başka bir yerde düşünülmesi, sonra cümlelerle (İngilizce ya da Türkçe) yazılması gerektiğini söyledi. **Yazılı ispat** şöyledir:

Yedi sayı seçildiği için, güvercin yuvası ilkesi seçimlerden ikisinin şu altı kümeden aynı birinden geldiğini garanti eder: $\{1, 11\}$, $\{2, 10\}$, $\{3, 9\}$, $\{4, 8\}$, $\{5, 7\}$, $\{6\}$. Bu iki sayının toplamı 12'dir.

> **Ders sonrası not:** Yazılı ispatın son cümlesi için bir gerekçe daha gerekir: Seçilen sayılar farklı olduğundan iki seçim $\{6\}$ kümesinden gelemez. Demek ki ikisi iki elemanlı kümelerden birindendir ve toplamları 12'dir. Teorem 1-11 arasındaki 330 yedili seçimin tamamı taranarak doğrulandı.

**Soru:** Eleman sayısının yarısından bir fazla seçim yaptığımızda bu zaten ispatlanmış oluyor. Bunun üzerine bir ad koymaya değer mi?

**Cevap:** Bu bir fikirdir ve bazı teoremlerin ispatında kullanabilirsiniz. Kafanızda bir farkındalık oluşturur. İki kümeden birinin eleman sayısı diğerinden fazlaysa bire bir ilişki kuramazsınız. Fikir basittir ama güzel ve farklı uygulamaları vardır. Bu derste sizi o fikre uyandırıyorlar.

## 5. Alfabe, Sembol ve Dizgi

Aradan sonra hoca, temel matematik girişinin bittiğini ve asıl ders içeriğine geçildiğini söyledi. İlk konu düzenli dillerdir (regular languages), ama önce birkaç tanım gerekir.

**Alfabe (alphabet):** Sonlu (finite), boş olmayan bir sembol kümesidir. **Sembol (symbol)**, bir alfabenin elemanıdır. Bu derste alfabeler için genelde $\Sigma$ veya $\Gamma$ kullanılır. Örneğin

$$\Sigma_1 = \{0, 1\}.$$

Burada $\Sigma_1$ alfabenin adıdır, 0 ve 1 semboldür, kümenin kendisi de alfabedir. Başka bir alfabe $\Gamma = \{0, 1, x, z\}$ olabilir.

**Dizgi (string):** Bir alfabe üzerindeki dizgi, o alfabeden alınan sembollerin sonlu bir dizisidir. Dizgiden söz edilirken genelde bir alfabeyle bağlantılı olarak konuşulur. Örneğin $0010$, $\Sigma_1$ üzerinde bir dizgidir. $0xz0$, $\Gamma$ üzerinde bir dizgidir.

**Uzunluk (length):** $w$ dizgisinin uzunluğu, içindeki sembollerin sayısıdır ve $|w|$ ile yazılır. Bu gösterimi gördüğünüzde uzunluk anlayın. Örneğin $|0xz0| = 4$.

**Boş dizgi (empty string):** Dizide hiç sembol olmayan, uzunluğu sıfır olan dizgidir. Bu derste $\varepsilon$ ile yazılır. Genelde epsilon, bazen de lambda ($\lambda$) kullanılır.

Bir $w$ dizgisinin uzunluğu $n$ ise, $w$ sembollerinin dizisi olarak şöyle yazılabilir:

$$w = w_1 w_2 \dots w_n.$$

> **Ders sonrası not:** Altyazıda bu yazımdan sonra "$n$ alfabededir" geçiyor. Doğrusu: Her $w_i$ alfabenin bir elemanıdır, yani $w_i \in \Sigma$. $n$ ise bir uzunluktur.

## 6. Dizgi İşlemleri

### 6.1 Ters Dizgi

$w$ dizgisinin üstüne $R$ yazılırsa tersi kastedilir. Son sembol başa geçer:

$$w^R = w_n \dots w_2 w_1.$$

Hoca, bu bir dizi olduğu için sembollerin arasına virgül koymaya gerek olmadığını söyledi.

### 6.2 Alt Dizgi

Bir $z$ dizgisi, $w$ içinde ardışık olarak geçiyorsa $w$'nin alt dizgisidir (substring). Örneğin $w = \text{abracadabra}$ için $z = \text{cad}$, $w$'nin bir alt dizgisidir.

### 6.3 Birleştirme

Birleştirme (concatenation), dizgileri yan yana yazmaktır. $w = \text{abra}$ ve $z = \text{cadabra}$ ise birleştirmeleri $wz$ diye yazılır ve $wz = \text{abracadabra}$ olur.

Bir dizgi kendisiyle birleştirilecekse kısa gösterimler vardır. $x^3$, $x$'in kendisiyle üç kez birleştirilmesi demektir:

$$x^3 = xxx.$$

### 6.4 Yıldız

$x^*$, $x$'in mümkün olan bütün tekrarları, yani her sayıda birleştirmesi demektir. Bu bir kümedir. Önce $x^0$ düşünülmelidir. $x^0$, hiç $x$ olmaması demektir ve boş dizgiyi verir. Dolayısıyla

$$x^* = \{\varepsilon, x, xx, xxx, \dots\}.$$

Burada $\varepsilon = x^0$, $x = x^1$, $xx = x^2$'dir. Bu işlemin adı Kleene yıldızıdır (Kleene star). Derste kısaca yıldız diyeceğiz.

## 7. Dil

Alfabe ve dizgiyi tanımladıktan sonra dili tanımlayabiliriz. **Dil (language)**, bir alfabe üzerindeki dizgilerin kümesidir.

> **Hocanın vurgusu:** Dil dediğimizde yalnızca bir dizgi kümesi kastediyoruz. Bu çok önemli ve çok kolay bir tanımdır.

Dil bir alfabe üzerinde tanımlandığı için önce alfabe belirtilir. $\Sigma = \{0, 1, x\}$ olsun. Bu alfabe üzerinde bazı diller şunlar olabilir:

- $L_1$: tahtada yazılan sonlu bir dil.
- $L_2 = \{0, 0x\}$.
- $L_3 = \{w \mid w = a^{2n},\ a \in \Sigma,\ n \geq 0\}$.

<!-- BELİRSİZ: L1'in elemanları altyazıda okunmuyor ("A this"). Tahtada yazılmış. -->

<!-- BELİRSİZ: Altyazıda L3'teki değişken de x diye geçiyor ve alfabedeki x sembolüyle aynı harf. Karışmaması için burada a yazıldı. Hoca değişkenin alfabedeki bütün semboller üzerinde gezdiğini sonradan ekledi. -->

$L_3$'ün ne olduğunu görmek için $n$'yi sırayla artıralım. $a$ alfabedeki bütün sembolleri dolaşır:

- $n = 0$: Üs 0'dır ve boş dizgi $\varepsilon$ çıkar.
- $n = 1$: Üs $2 \cdot 1 = 2$'dir. $0^2 = 00$, $1^2 = 11$, $x^2 = xx$ çıkar.
- $n = 2$: Üs $2 \cdot 2 = 4$'tür. $0^4 = 0000$, $1^4 = 1111$, $x^4 = xxxx$ çıkar.

Böylece

$$L_3 = \{\varepsilon, 00, 11, xx, 0000, 1111, xxxx, \dots\}.$$

> **Hocanın vurgusu:** Burada $0^2$ sayısal bir hesap değildir. Bu derste $0^2$, birleştirme demektir: $0^2 = 00$.

$L_1$ ve $L_2$ sonlu (finite) dillerdir. $L_3$ ise sonsuz (infinite) bir dildir, sonsuz sayıda elemanı vardır. İkisi de mümkündür.

## 8. Düzenli Diller

Dillerin bir kısmına düzenli dil (regular language) denir. Hoca, düzenli dillerin dillerin bir alt kümesi olduğunu söyledi ve bu alt kümenin nasıl bir alt küme olduğunu göreceğimizi ekledi.

Hoca burada şunu söyledi: Düzenli dilin bir tanımı yoktur, onu tanımlamanın yolu yoktur. Ama bir dilin düzenli olup olmadığını söyleyen testler vardır. Bize bir dil verildiğinde düzenli olup olmadığını söyleyebiliriz. Bu test için farklı yollar olabilir, ama genelde sonlu otomat (finite automaton) kullanılır. Sonlu otomatları henüz görmedik, göreceğiz.

> **Ders sonrası not:** Hoca "düzenli dilin tanımı yoktur" dedi; doğrusu tanım vardır. Bir dil, onu tanıyan bir sonlu otomat varsa düzenlidir. Yani hocanın "test" dediği sonlu otomat, tanımın kendisidir.

## 9. Diller Üzerinde Küme İşlemleri, Birleştirme ve Yıldız

Düzenli dilleri kullanarak başka düzenli diller de kurabilirsiniz. Diller küme işlemleriyle kurulabilir, çünkü diller yalnızca kümedir. Örnek için şu iki dil alınır:

$$A = \{aa, bb\}, \qquad B = \{0, 11\}.$$

### 9.1 Bileşim ve Diğer Küme İşlemleri

Bileşim (union) bildiğimiz küme işlemidir:

$$A \cup B = \{x \mid x \in A \text{ veya } x \in B\} = \{aa, bb, 0, 11\}.$$

Kesişim (intersection) ve fark (difference) gibi bildiğimiz küme işlemlerinin hepsi kullanılabilir.

### 9.2 Birleştirme

İlginç olanlardan biri birleştirmedir. $AB$ diye ya da araya küçük bir daire koyarak $A \circ B$ diye yazılır:

$$A \circ B = \{xy \mid x \in A \text{ ve } y \in B\}.$$

Örneğimizde $A$'dan iki, $B$'den iki seçenek vardır. Her eşleşme yazılır:

- $aa$ ile $0$: $aa0$
- $aa$ ile $11$: $aa11$
- $bb$ ile $0$: $bb0$
- $bb$ ile $11$: $bb11$

Yani $A \circ B = \{aa0, aa11, bb0, bb11\}$.

### 9.3 Yıldız

Kleene yıldızı bir kümeye uygulanırsa, tahtadaki tanım şöyledir:

$$A^* = \{x_1 x_2 \dots x_k \mid k > 0,\ x_i \in A\}.$$

$A = \{aa, bb\}$ için hoca $k = 1$'de $aa$ ve $bb$'yi, $k = 2$'de de bu ikisinin birleşimlerini yazdı. Bu sonsuz bir kümedir, mümkün olan bütün kombinasyonlar yazılmalıdır.

<!-- BELİRSİZ: Hocanın yazdığı dizgiler altyazıda "A, A, A, A, A, A, A, B, B" biçiminde bozuk. k = 2 listesi aşağıdaki ders sonrası notta hesapla verildi. -->

**Soru:** Bu kümede boş olanın da olması gerekmez mi?

**Cevap:** Hoca gerekmediğini söyledi. Tanımda $k$ sıfırdan büyüktür, yani $A$'dan en az bir değer olmalıdır. $A$'nın tanımına bakılırsa boş olan $A$'nın bir elemanı da değildir.

<!-- BELİRSİZ: Sorunun altyazısı bozuk (01:55, "Bush, Q, me, all must get a key on the service or gelmiş"). Soru, hocanın cevabından kuruldu. -->

> **Ders sonrası not:** Hocanın tanımı ve cevabı düzeltilmelidir. Yıldızın tanımında $k \geq 0$ alınır. Bu yüzden her $A$ için $\varepsilon \in A^*$'dır ve doğrusu $A^* = \{\varepsilon, aa, bb, aaaa, aabb, bbaa, bbbb, \dots\}$'dır. Bu, hocanın kendi verdiği $x^* = \{\varepsilon, x, xx, \dots\}$ gösterimiyle de uyumludur. $k > 0$ koşulu aslında artı işlemini verir (bkz. Bölüm 14). Ayrıca hoca burada "boş küme" dedi; kastedilen boş dizgidir.

> **Ders sonrası not:** Hoca "$aaa$ gibi dizgiler var" diye düşündü. $A$'daki her dizginin uzunluğu 2 olduğundan $A^*$'daki her dizginin uzunluğu çifttir. O yüzden $aaa$, $A^*$'da yoktur. Hesapla $k = 2$ için tam olarak $aaaa$, $aabb$, $bbaa$, $bbbb$ çıkar.

## 10. Kapalılık

Hoca son olarak kapalılık (closure) kavramını verdi. Önce "bir küme bir işleme göre kapalıdır" diye başladı, sonra ifadeyi düzeltti: Söz konusu olan tek bir dil değil, dil sınıfıdır.

**Tanım:** Düzenli diller sınıfı bir işleme göre kapalıdır, eğer bu işlemin sonucu da düzenli ise. Yani düzenli dillere bir işlem uygularsınız ve çıkan dil de hâlâ düzenlidir.

Örnek olarak yukarıdaki iki sonlu dil düzenlidir. Nedenini sonra göreceğiz, ama hoca şimdiden şunu söyledi: Bütün sonlu diller düzenlidir. Sonsuz olup yine de düzenli olan diller de vardır, onlara da geleceğiz.

Düzenli diller sınıfı bileşime göre kapalıdır: $A$ ve $B$ düzenliyse $A \cup B$ de düzenlidir.

<!-- BELİRSİZ: 02:01:45'te hoca bir bileşim örneği yazıyor. Altyazıda "A, A, B, B, D, D, A, B" geçiyor. İkinci dilin elemanları kesin okunmuyor. -->

Yalnız bileşim değil, düzenli diller sınıfı şu işlemlerin hepsine göre kapalıdır:

- Bileşim (union)
- Kesişim (intersection)
- Tümleyen (complement)
- Birleştirme (concatenation)
- Kleene yıldızı (Kleene star)

Hoca, bunların örnek ve uygulamalarını daha sonra göreceğimizi söyledi.

## 11. Sayıları Dizgi Olarak Yazmak

İkinci aradan sonra hoca, bu kısmın karışık örnekler ve yeni tanımlardan oluşacağını söyledi. Önce bir alfabe ve dizgiler yazıldı. $\Sigma = \{a, b\}$ üzerinde örneğin $u = ab$, $v = bbaaa$ ve $w = abba$ tanımlanabilir.

<!-- BELİRSİZ: v dizgisi altyazıda "BB, A, AA" diye geçiyor; bbaaa olarak okundu. -->

Bilinen kümeler de dizgi ve alfabe cinsinden yazılabilir.

- **Ondalık sayılar (decimal numbers):** Alfabe $\{0, 1, 2, \dots, 9\}$'dur ve dizgiler ondalık sayılarımızdır. Bunlar sayı olsa da dizgi gibi düşünülebilir ve sayılar üzerindeki işlemler dizgiler üzerinden yeniden düşünülebilir.
- **İkili sayılar (binary numbers):** Alfabe $\{0, 1\}$'dir ve dizgiler $10010$ gibi ikili sayılardır.
- **Birli sayılar (unary numbers):** Alfabe yalnız $\{1\}$'dir. Dizginin uzunluğu sayının değeridir.

Birli gösterimde sayılar şöyle okunur:

| Dizgi | Uzunluk | Ondalık değer |
|---|---|---|
| $1$ | 1 | 1 |
| $11$ | 2 | 2 |
| $111$ | 3 | 3 |
| $1111$ | 4 | 4 |

Hoca, birli sayılarla dizgi olarak çalışmanın çok kolay olduğunu ve bunlara örneklerde tekrar rastlayacağımızı söyledi.

## 12. İşlemleri Dil Olarak Yazmak

### 12.1 Birli Toplama Dili

Birli toplama için alfabe $\Sigma = \{1, +, =\}$ olsun. Toplamaların dili şöyle tanımlanabilir:

$$\text{ADD} = \{x{+}y{=}z \mid x = 1^m,\ y = 1^n,\ z = 1^{m+n}\}.$$

Burada $+$ ve $=$ alfabedeki sembollerdir, $x$, $y$, $z$ birli sayılardır. $z$'deki birlerin sayısı $m + n$'dir. Örnekler:

- $111{+}11{=}11111$: Burada $m = 3$, $n = 2$ ve $m + n = 5$.
- $1{+}11{=}111$: Burada $m = 1$, $n = 2$ ve $m + n = 3$.

Bu sonsuz bir kümedir. Toplama işlemi kendisi bir küme olur. Bu küme bütün sayıların mümkün olan bütün toplamalarını içerir. Çok büyüktür ama bir kümedir ve bir dildir. Yani bu durumda toplama bir dildir.

### 12.2 Birli Kare Alma Dili

Benzer biçimde kare alma dili düşünülebilir. Alfabe $\Sigma = \{1, \#\}$'dir. $\#$ sembolü kuvveti göstermek için kullanılır. Dilin dizgileri $x\#y$ biçimindedir ve $x = 1^m$'dir.

Hoca önce $y = 1^n$, $n = 2m$ yazdı ve $1\#11$, $11\#1111$ gibi örnekler verdi.

**Soru:** $n = 2m$ olunca iki katını almış olduk. Karesini almayacak mıydık? Örneğin 3'ü 9'a çevirmek gibi.

**Cevap:** Hoca önce örneklere baktı: Birin karesi birdir. 2 için 4 yazılmış, orada sorun görünmüyor. Bir öğrenci 3'te de sorun olacağını, yalnız 2'de sorun olmadığını söyledi. Hoca bunu kabul etti ve hatasını düzeltti: $2m$ değil $m^2$ yazılmalıydı. Aşağıya yazdığı örnekler iki ile çarpma olmuştu.

Doğru tanım şudur:

$$\text{SQUARE} = \{x\#y \mid x = 1^m,\ y = 1^{m^2}\}.$$

Örnekler:

- $m = 1$: $1\#1$. Çünkü $1^2 = 1$.
- $m = 2$: $11\#1111$. Çünkü $2^2 = 4$.
- $m = 3$: $111\#111111111$. Çünkü $3^2 = 9$.

Yanlış yazımın $m = 2$'de doğru görünmesinin nedeni $2 \cdot 2 = 2^2$ olmasıdır.

Bu da sonsuz bir kümedir ve bir dildir. Her değer için o değerin karesini verir. Hoca bu yaklaşımın her tür işlemi küme cinsinden tanımlamaya yaradığını söyledi. Diller küme olduğu için bu şeylerin üzerinde küme işlemleri kullanılabilir. Bunun nasıl işe yaradığını sonra göreceğiz.

## 13. Uzunluk, Önek ve Sonek

Birleştirme ve tersi basit olduğu için hoca uzunlukla devam etti. $w = aab$ ise $|w| = 3$'tür. Boş dizginin uzunluğu ise sıfırdır: $|\varepsilon| = 0$.

Alt dizginin özel durumları vardır: önek (prefix) ve sonek (suffix). $w = \text{abracadabra}$ için:

- $\text{cad}$ bir alt dizgidir.
- $\text{ra}$ bir sonektir, çünkü abracadabra "ra" ile biter.
- $\text{ab}$ bir önektir, çünkü abracadabra "ab" ile başlar.

Dikkat edilecek iki durum vardır.

**$\varepsilon$ bütün dizgilerin hem öneki hem sonekidir.** $w = \text{abba}$ ise $\varepsilon w$ yine abba'dır. Hocanın daha uygun bulduğu yazımla $w = \varepsilon\,\text{abba}$ olur. Boş dizgi herhangi bir dizginin başına ya da sonuna eklenebilir ve dizgiyi değiştirmez.

**Her dizgi kendisinin hem öneki hem sonekidir.** $w = \text{abba}$ ise abba, $w$'nin hem soneki hem önekidir.

## 14. Artı İşlemi

Yıldıza benzeyen bir işlem daha vardır: artı işlemi. $\Sigma = \{a, b\}$ alfabesi için

$$\Sigma^* = \{\varepsilon, a, b, aa, ab, \dots\}$$

olduğunu biliyoruz. $\Sigma^+$ buna çok benzer. Tek farkı $\varepsilon$ içermemesidir:

$$\Sigma^+ = \{a, b, aa, ab, \dots\}.$$

Hoca bunu önce $\Sigma^+ = \Sigma^* - \varepsilon$ diye yazdı, sonra hatasını düzeltti. Burada fark bir küme işlemidir. $\Sigma^*$ kümedir ama $\varepsilon$ küme değildir. O yüzden $\varepsilon$ bir kümenin içine yazılmalıdır:

$$\Sigma^+ = \Sigma^* - \{\varepsilon\}.$$

> **Ders sonrası not:** Hoca burada $\varepsilon$'nin adının "null" olması gerektiğini söyledi. Oysa hoca önceki bölümlerde kendisi de "boş dizgi" (empty string) dedi ve bu notta da o ad kullanılır. "Null" sözcüğü boş kümeyle karıştırılmamalıdır (bkz. Bölüm 17).

## 15. Her Dil $\Sigma^*$'ın Alt Kümesidir

Bir $\Sigma$ alfabesi üzerindeki her dil $\Sigma^*$'ın alt kümesidir. Çünkü $\Sigma^*$ o alfabe üzerindeki bütün dizgileri içerir. Örneğin $\Sigma = \{a, b\}$ ve $L_1 = \{a, aa, b\}$ olsun. $\Sigma^*$, $\varepsilon$, $a$, $aa$, $b$ ve başka dizgileri içerir. $L_1$'in elemanları da bunların arasındadır, dolayısıyla $L_1 \subseteq \Sigma^*$'dır.

<!-- BELİRSİZ: L1 altyazıda "A, A, A, B" diye geçiyor. Hocanın hemen ardından saydığı "A, AA, B" dizgilerine göre {a, aa, b} olarak okundu. -->

Bu özellik tanımlarda kullanılır. Hocanın örneği asal sayılardı. $\Sigma = \{0, 1, 2, \dots, 9\}$ olsun:

$$\text{PRIMES} = \{x \mid x \in \Sigma^*,\ x \text{ asaldır}\}.$$

$x \in \Sigma^*$ demekle $x$'in bir sayı olduğunu söylemiş oluruz. Sonra ek koşul olarak asal olduğunu yazarız. Hoca bunun kullanışlı olduğunu söyledi.

> **Ders sonrası not:** $\Sigma^*$ boş dizgiyi de içerdiği için "$x \in \Sigma^*$ demek $x$ sayıdır demektir" ifadesi tam değildir. Burada sorun çıkmaz, çünkü "$x$ asaldır" koşulu boş dizgiyi dışarıda bırakır.

## 16. Tümleyen

Diller küme olduğu için herhangi bir küme işlemi dillere uygulanabilir: tümleyen, bileşim ve diğerleri. Hocanın ilginç bulduğu örnek tümleyendi. $A = \{a, b, aaaa\}$ olsun. Tümleyen için bir alfabe de belirtmek gerekir, çünkü evrensel küme $\Sigma^*$'dır. Tümleyen, evrensel kümeden $A$'nın çıkarılmasıdır:

$$\overline{A} = \Sigma^* - A = \{\varepsilon, aa, bb, \dots\}.$$

$\varepsilon$ bu kümededir, çünkü $A$'da yoktur. $A$'daki dizgiler ise $\overline{A}$'da bulunamaz.

<!-- BELİRSİZ: A altyazıda "A, B and AAA" diye geçiyor. Son eleman kısa notta tahtadan aaaa olarak alınmış, altyazı üç a duyuruyor. Alfabe de altyazıda açıkça söylenmiyor. Hoca ayrıca yazdığı bir gösterimi "daha önce görmedim, garip" diyerek yazmaktan vazgeçiyor (02:50); hangi gösterim olduğu okunmuyor. -->

## 17. Boş Küme ve Boş Dizgi

Hoca son olarak dikkat edilmesi gereken bir durumu yazdı: boş küme (empty set) $\emptyset$ ile boş dizgi $\varepsilon$ farklı şeylerdir. Hoca tahtaya önce eşittir yazmıştı, bir öğrenci "eşit değildir yazacaktınız" diye uyardı ve hoca düzeltti: $\emptyset \neq \varepsilon$.

Hocanın örneği şuydu: Boş dizgiyi içeren küme $\{\varepsilon\}$, boş küme değildir. Bir elemanı vardır, o da boş dizgidir. Eleman sayısı birdir:

$$|\{\varepsilon\}| = 1.$$

> **Hocanın vurgusu:** Boş küme ile boş dizgi aynı şey değildir. Bu tür şeylere dikkat edin.

> **Ders sonrası not:** $\emptyset$ bir küme, $\varepsilon$ bir dizgidir. Bu yüzden asıl karşılaştırılabilir fark $\emptyset \neq \{\varepsilon\}$'dur: $|\emptyset| = 0$ iken $|\{\varepsilon\}| = 1$.

## Dersin Toparlaması

Bu derste önce ispat teknikleri tamamlandı. Olmayana ergiyle $\sqrt{2}$'nin irrasyonel olduğu, tümevarımla ilk $n$ sayının toplam formülü ispatlandı. Güvercin yuvası ilkesi, 1-11 arasından seçilen 7 sayıdan ikisinin toplamının 12 olduğunu göstermek için kullanıldı.

Ardından asıl ders içeriğine geçildi. Alfabe, dizgi ve dil tanımlandı. Dilin yalnızca bir dizgi kümesi olduğu, bu yüzden küme işlemlerinin dillere uygulanabildiği görüldü. Toplama ve kare alma gibi işlemlerin bile birer dil olarak yazılabildiği gösterildi. Düzenli diller ve kapalılık kavramına giriş yapıldı. Sonraki derste düzenli dilleri belirlemeye yarayan sonlu otomatlara başlanacak. Hoca, bu konuların büyük kısmının kitabın başlangıç bölümünde olduğunu, bazı şeylerin ise kitapta açıkça yazmayabileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
