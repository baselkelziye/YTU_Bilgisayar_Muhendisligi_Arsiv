# Ders 11 Çalışma Özeti

## Genel Konular

- Boole cebri ile sadeleştirmenin tekrarı
  - Boole cebrinin amacı bir sözel problemden ya da lojik diyagramdan elde edilen $F$ fonksiyonunu daha az kapıyla, daha az karmaşık bir lojik diyagramla gerçekleştirmektir. Bütün teoremlerin arkasında VE, VEYA ve TÜMLEYEN işlemlerinin mantığı vardır.
  - Slaytta yutma (absorption) teoreminin ispatı hatırlatıldı: $A + A\cdot B = A\cdot 1 + A\cdot B = A(1+B) = A\cdot 1 = A$ (ekrandan, 00:05:00).
  - Örnek 1: $\bar A\bar B\bar C + A(C\bar D + \bar B)$ sadeleştirildi; sonuç $\bar B A + \bar C\bar B + AC\bar D$ (ekrandan, 00:10:00 ve 00:15:00).
  - Örnek 2: $(\bar A + ABC)(A + \bar C)$ sadeleştirildi; sonuç $\bar A\bar C + ABC$ (python ile doğrulandı). <!-- BELİRSİZ: tahtadaki son satır karelerde görünmüyor; 00:15:00 karesinde yalnız ilk açılım ($\bar A A + \bar A\bar C + \dots$) okunuyor -->
- Kanonik formlar (canonical forms)
  - Bir Boole fonksiyonunu standart bir biçimde yazmanın yoludur. Kaynağı doğruluk tablosudur.
  - Slayttaki iki gerekçe: eşitlik karşılaştırmasına izin verir (iki devrenin aynı fonksiyonu üretip üretmediği anlaşılır) ve doğruluk tablosuyla birebir karşılığı vardır (ekrandan, 00:25:00).
  - İki yaygın kanonik form vardır: mintermlerin toplamı (Sum of Minterms, SOM) ve maxtermlerin çarpımı (Product of Maxterms, POM).
- Doğruluk tablosu (tekrar)
  - Sol tarafta giriş değişkenlerinin bütün kombinasyonları, sağda çıkış $F$ yazılır.
  - Kombinasyonlar şöyle üretilir: en sağdaki sütun her satırda, bir soldaki iki satırda bir, bir soldaki dört satırda bir değişir ($2^0, 2^1, 2^2$).
  - Örnek: $F = x + yz$ için $x = 1$ olan dört satırda $F = 1$, $x = 0$ iken yalnız $y = z = 1$ satırında $F = 1$ olur; yani $F$ 3, 4, 5, 6, 7 numaralı satırlarda 1'dir (ekrandan, 00:30:00).
- Mintermler
  - Minterm, her değişkenin ya kendisiyle ya tümleyeniyle bulunduğu VE terimidir. $n$ değişken için $2^n$ minterm vardır (ekrandan, 00:30:00).
  - İki değişken için: $XY$, $X\bar Y$, $\bar X Y$, $\bar X\bar Y$.
  - Mintermler doğruluk tablosunda $F = 1$ olan satırlardan yazılır. Satırdaki 1 olan değişken olduğu gibi, 0 olan değişken tümlenmiş yazılır (çünkü VE'nin sonucu 1 olmalıdır).
  - $F = x + yz$ için mintermler: $\bar x y z$, $x\bar y\bar z$, $x\bar y z$, $xy\bar z$, $xyz$ (ekrandan, 00:30:00).
- Maxtermler
  - Maxterm, her değişkenin ya kendisiyle ya tümleyeniyle bulunduğu VEYA terimidir.
  - Maxtermler doğruluk tablosunda $F = 0$ olan satırlardan yazılır. Satırdaki 0 olan değişken olduğu gibi, 1 olan değişken tümlenmiş yazılır (çünkü VEYA'nın sonucu 0 olmalıdır).
- İndeks gösterimi
  - Standart sıra $X, Y, Z$'dir. İndeks, satırın ikilik değerinin onluk karşılığıdır (ekrandan, 00:35:00).
  - İndeks 0 ($000$): minterm $m_0 = \bar X\bar Y\bar Z$, maxterm $M_0 = X + Y + Z$.
  - İndeks 6 ($110$): $m_6 = XY\bar Z$, $M_6 = \bar X + \bar Y + Z$.
  - Küçük $m$ minterm, büyük $M$ maxterm için kullanılır.
  - De Morgan ile $\overline{m_i} = M_i$ ve $\overline{M_i} = m_i$; örneğin $\overline{XY} = \bar X + \bar Y$.
- Minterm ve maxterm fonksiyon örnekleri
  - $F_1 = m_1 + m_4 + m_7 = \bar x\bar y z + x\bar y\bar z + xyz$ (ekrandan, 00:40:00).
  - Beş değişkenli örnek: $F(A,B,C,D,E) = m_2 + m_9 + m_{17} + m_{23} = \bar A\bar B\bar C D\bar E + \bar A B\bar C\bar D E + A\bar B\bar C\bar D E + A\bar B C D E$. <!-- BELİRSİZ: bu slayt karelerde yok; indeksler altyazıdan (2, 9, 17, 23), terimler ikilik açılımla python'da kontrol edildi -->
  - $F_1 = M_0 \cdot M_2 \cdot M_3 \cdot M_5 \cdot M_6 = (x+y+z)(x+\bar y+z)(x+\bar y+\bar z)(\bar x+y+\bar z)(\bar x+\bar y+z)$ (ekrandan, 00:45:00).
  - $F(A,B,C,D) = M_3 \cdot M_8 \cdot M_{11} \cdot M_{14} = (A+B+\bar C+\bar D)(\bar A+B+C+D)(\bar A+B+\bar C+\bar D)(\bar A+\bar B+\bar C+D)$ (ekrandan, 00:50:00; son çarpan derste yazılmadı, ikilik açılımla tamamlandı).
- Kanonik mintermler toplamı (SOM)
  - Her Boole fonksiyonu mintermlerin toplamı olarak yazılabilir. Tablodan yazarken 1'lere karşılık gelen mintermler kullanılır (ekrandan, 01:00:00).
  - İfadeden yazarken her terimde eksik olan değişken $v$ için terim $(v + \bar v) = 1$ ile çarpılır, sonra dağıtılır. Tekrarlanan mintermlerden biri atılır.
  - Örnek: $f = x + \bar x\bar y = x(y+\bar y) + \bar x\bar y = xy + x\bar y + \bar x\bar y = m_3 + m_2 + m_0$ (ekrandan, 01:00:00).
  - Örnek: $F = A + \bar B C = m_1 + m_4 + m_5 + m_6 + m_7$; kısa gösterim $F(A,B,C) = \Sigma m(1,4,5,6,7)$ (ekrandan, 01:05:00).
- Kanonik maxtermler çarpımı (POM)
  - Her Boole fonksiyonu maxtermlerin çarpımı olarak yazılabilir. Tablodan yazarken 0'lara karşılık gelen maxtermler kullanılır (ekrandan, 01:10:00).
  - İfadeden yazarken önce ikinci dağılma kuralı $x + yz = (x+y)(x+z)$ uygulanır, eksik değişken $V$ için terime $V\bar V$ (= 0) VEYA'lanır, sonra yine dağıtılır.
  - Örnek: $f(x,y,z) = x + \bar x\bar y = (x+\bar x)(x+\bar y) = x + \bar y = x + \bar y + z\bar z = (x+\bar y+z)(x+\bar y+\bar z) = M_2 \cdot M_3$ (ekrandan, 01:10:00).
  - Örnek: $f(A,B,C) = A\bar C + BC + \bar A\bar B = (\bar A + B + \bar C)(A + \bar B + C) = M_5 \cdot M_2$ (ekrandan, 01:30:00).
- Karışık gösterimler ve sadeleştirmenin önemi
  - Ne SOP ne POS olan karışık ifadeler önce SOP ya da POS biçimine getirilip sonra işlenir.
  - Kanonik formlar en açık (sadeleşmemiş) gösterimdir; doğrudan gerçekleştirilirse çok kapı gerekir. Sadeleştirme Boole cebriyle ya da bir sonraki derste işlenecek Karnaugh haritalarıyla yapılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Boole cebriyle sadeleştirme örneklerini mutlaka çözün
  - Hoca bu konuyla ilgili mutlaka örnek soru çözülmesini istedi; konu kesinlikle önemli bir konu olarak vurgulandı.
- Bir VEYA'nın girişlerinden biri diğer terimde tümlenmiş olarak varsa o değişken düşer
  - $\bar A + ABC = \bar A + BC$. Bunu baştan görmek dağıtma adımlarını kısaltır; dağıtmada farklı bir değişken olsaydı ekstra adım gerekecekti.
- Mintermler 1'lere, maxtermler 0'lara göre kurulur
  - Mintermde 1 olan değişken olduğu gibi, 0 olan tümlenmiş yazılır; maxtermde tam tersi. Amaç mintermde VE sonucunun 1, maxtermde VEYA sonucunun 0 olmasıdır.
  - Bir öğrencinin $m_6$ için VEYA'lı bir ifade yazması üzerine hoca, VEYA ile yazılan terimin maxterm olduğunu, minterm için VE kullanılması gerektiğini belirtti.
- Mintermler ile maxtermler birbirinin tümleyenidir
  - Bir fonksiyonun mintermlerinde bulunmayan indeksler, maxtermlerinin indeksleridir.
- İkinci dağılma kuralı unutuluyor
  - $A + BC = (A+B)(A+C)$ kuralını öğrenciler genelde unutur; hoca bunun maxterm işlemlerinde en çok kullanılacak dağıtım biçimi olduğunu vurguladı.

## Kısa Tekrar Notları

- Kanonik form: SOM (mintermlerin toplamı) ve POM (maxtermlerin çarpımı).
- Minterm: VE terimi, her değişken bulunur, $F = 1$ satırları. Maxterm: VEYA terimi, her değişken bulunur, $F = 0$ satırları.
- $n$ değişken için $2^n$ minterm (ve $2^n$ maxterm) vardır.
- $m_0 = \bar X\bar Y\bar Z$, $M_0 = X+Y+Z$; $m_6 = XY\bar Z$, $M_6 = \bar X+\bar Y+Z$.
- $\overline{m_i} = M_i$.
- SOM'a çevirme: eksik değişken için $(v+\bar v)$ ile çarp, dağıt, tekrarları at.
- POM'a çevirme: $x+yz = (x+y)(x+z)$ uygula, eksik değişken için $v\bar v$ ekle, tekrar dağıt.
- $\Sigma m(\dots)$ kısa gösterimi; POM için $\Pi M(\dots)$ benzer biçimde yazılır.
- $f = A\bar C + BC + \bar A\bar B = \Sigma m(0,1,3,4,6,7) = M_2 \cdot M_5$.
- Sadeleştirme yolları: Boole cebri ve Karnaugh haritaları.

## Detaylı Açıklamalar

- **Sadeleştirme örneği 1.** $\bar A\bar B\bar C + A(C\bar D + \bar B)$ ifadesinde önce $A$ parantezin içine dağıtılır: $\bar A\bar B\bar C + AC\bar D + A\bar B$. Sonra $\bar B$ ortak paranteze alınır: $\bar B(\bar A\bar C + A) + AC\bar D$. Parantezin içindeki $A + \bar A\bar C$, ikinci dağılma kuralıyla $(A+\bar A)(A+\bar C) = A + \bar C$ olur. Böylece $\bar B(A + \bar C) + AC\bar D = \bar B A + \bar C\bar B + AC\bar D$ elde edilir (ekrandan, 00:15:00). Hoca, buradan $\bar B$ yeniden ortak alınabilse de daha fazla sadeleşmediğini belirtti. Sonuç python ile bütün girişler için doğrulandı.
- **Sadeleştirme örneği 2.** $(\bar A + ABC)(A + \bar C)$ için önce $\bar A + ABC = \bar A + BC$ yazılabilir. Sonra çarpım açılırsa $\bar A A + \bar A\bar C + ABC + BC\bar C = \bar A\bar C + ABC$ olur. Hoca, bir öğrencinin üç terimi birden dağıtarak aynı sonuca ulaştığını, ama $\bar A$'nın diğer terimdeki $A$'yı baştan götürdüğünü görmenin işi kısalttığını anlattı. (Ara adımlar eklendi; sonuç python ile doğrulandı.)
- **Neden kanonik form?** $x + yz$ ile $y + z$ gibi iki ifadeyi kapı sayısıyla kıyaslamak mümkündür, ama eşit olup olmadıklarını sadeleşmiş hallerine bakarak anlamak zordur. Kanonik formda ikisi de açılmış halde yazılır ve terim terim karşılaştırılabilir. Ayrıca sadeleşmiş bir ifadede tek terim birden fazla tablo satırını kapsar; kanonik formda ise her terim tek bir satıra karşılık gelir.
- **Mintermlerle fonksiyon kurma.** $F_1 = m_1 + m_4 + m_7$ için indeksler ikiliğe çevrilir: $1 = 001$, $4 = 100$, $7 = 111$. 0 olan değişkenler tümlenir: $\bar x\bar y z + x\bar y\bar z + xyz$. Bu üç dışındaki bütün kombinasyonlarda $F_1 = 0$'dır. Beş değişkenli örnekte de aynı yol izlenir: $2 = 00010$, $9 = 01001$, $17 = 10001$ ($16+1$), $23 = 10111$ ($16+4+2+1$).
- **Maxtermlerle fonksiyon kurma.** $F_1 = M_0 M_2 M_3 M_5 M_6$ için her indeksin ikilik değerinde 1 olan değişkenler tümlenir ki o satırda VEYA sonucu 0 olsun: $M_3$ ($011$) için $x + \bar y + \bar z$, $M_5$ ($101$) için $\bar x + y + \bar z$ (ekrandan, 00:45:00). Dört değişkenli örnekte $M_3 = 0011 \Rightarrow A + B + \bar C + \bar D$, $M_8 = 1000 \Rightarrow \bar A + B + C + D$, $M_{11} = 1011 \Rightarrow \bar A + B + \bar C + \bar D$ (ekrandan, 00:50:00).
- **SOM'a çevirme örneği.** $F = A + \bar B C$ üç değişkenlidir. $A$ teriminde $B$ ve $C$ eksik olduğundan $A(B+\bar B)(C+\bar C)$, $\bar B C$ teriminde $A$ eksik olduğundan $(A+\bar A)\bar B C$ yazılır. Açılınca $ABC + A\bar B C + AB\bar C + A\bar B\bar C + A\bar B C + \bar A\bar B C$ çıkar; $A\bar B C$ iki kez geçtiği için biri atılır. İndeksler: $ABC = 7$, $AB\bar C = 6$, $A\bar B C = 5$, $A\bar B\bar C = 4$, $\bar A\bar B C = 1$. Sonuç $F(A,B,C) = \Sigma m(1,4,5,6,7)$ (ekrandan, 01:05:00).
- **POM'a çevirme örneği.** $f(x,y,z) = x + \bar x\bar y$ için dağılma kuralıyla $(x+\bar x)(x+\bar y) = x + \bar y$ bulunur. İki değişkenli düşünülürse $x + \bar y$, $x=0, y=1$ satırında 0 olduğundan $M_1$'dir; ama $z$ de bir giriştir. $z\bar z = 0$ eklenip dağıtılır: $(x+\bar y+z)(x+\bar y+\bar z) = M_2 \cdot M_3$ (ekrandan, 01:10:00).
- **İkinci POM örneği ve iki çözüm yolu.** $f = A\bar C + BC + \bar A\bar B$ önce SOM'a açılarak $\Sigma m(0,1,3,4,6,7)$ bulunur. Eksik indeksler 2 ve 5 olduğundan $f = M_2 \cdot M_5$ olmalıdır. Bunu cebirle göstermenin bir yolu çift tümleyendir: $f = \overline{\overline{f}}$; içteki tümleyen De Morgan ile dağıtılır, $\bar f = (\bar A + C)(\bar B + \bar C)(A + B)$, çarpım açıldığında çoğu terim $X\bar X = 0$ ile düşer ve $\bar f = \bar A B\bar C + A\bar B C$ kalır; dıştaki tümleyen yeniden dağıtılınca $(A + \bar B + C)(\bar A + B + \bar C)$ elde edilir (ekrandan, 01:25:00). Slayttaki yol ise $x = A\bar C + BC$, $y = \bar A$, $z = \bar B$ alıp $x + yz = (x+y)(x+z)$ uygulamak, sonra $x + \bar x y = x + y$ kuralını iki kez kullanmaktır: $f = (\bar C + B + \bar A)(A + C + \bar B)$, standart sırayla $(\bar A + B + \bar C)(A + \bar B + C) = M_5 \cdot M_2$ (ekrandan, 01:30:00).
- **Kanonik form ve devre maliyeti.** $\Sigma m(1,4,5,6,7)$ doğrudan gerçekleştirilirse hocanın sayımına göre 6 DEĞİL, 10 VE ve 4 VEYA kapısı gerekir; aynı fonksiyon sadeleşmiş haliyle ($A + \bar B C$) bir DEĞİL, bir VE ve bir VEYA kapısıyla kurulur. Örneğin $AB\bar C + ABC$ terimlerinde $C$'nin etkisi yoktur. Slayttaki sonuç: kanonik formlar ve SOP/POS gibi standart formlar karmaşıklıkta farklıdır, Boole cebri ifadeyi sadeleştirmeye yarar ve daha sade ifade daha sade iki seviyeli gerçekleştirme verir (ekrandan, 01:35:00).
- **Ders sonrası not:** Hoca $f = x + \bar x\bar y$ örneğinde kısa gösterimi önce "$m_1, m_2, m_3$" diye söyledi; slayttaki doğru sonuç $m_0 + m_2 + m_3$'tür. İkinci POM örneğinde de maxtermleri bir yerde "0, 1, 2 ve 5" diye söyledi; doğrusu yalnız 2 ve 5'tir (mintermler 0, 1, 3, 4, 6, 7). Dört değişkenli maxterm anlatımında 1100 için "$\bar A + \bar B + C + \bar D$" gibi duyulan ifadenin doğrusu $M_{12} = \bar A + \bar B + C + D$'dir (büyük olasılıkla Whisper ya da dil sürçmesi).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
