# Ders 4 Çalışma Özeti

## Genel Konular

- Karnaugh haritalarında etiketleme ve SOP/POS biçimlerinin önemi
  - Haritanın satır ve sütunlarını Gray kodla ($00, 01, 11, 10$) etiketlemek yeterlidir; ayrıca $\overline{C}\,\overline{D}$ gibi harf etiketleri yazmaya gerek yoktur.
  - Sadeleştirilmiş ifade SOP ya da POS biçiminde yazılırsa devre tek tür kapıyla (yalnız NAND ya da yalnız NOR) ve tek entegreyle kurulabilir. Karışık AND/OR içeren bir ifade fazladan entegre gerektirir.
  - Bir ifadenin iki kez tümleyeni kendisine eşittir; bu, ifadeyi NAND ya da NOR biçimine çevirmenin anahtarıdır.
- NAND ve NOR ile gerçekleme örnekleri
  - $xyz = \overline{\overline{x}+\overline{y}+\overline{z}}$: girişlerin tümleyenleri tek bir NOR kapısına verilir (ekrandan, 00:30:00).
  - $BD + BC = \overline{\overline{BD}\cdot\overline{BC}}$: üç NAND kapısıyla kurulur.
  - Sıfırlar gruplanırsa POS biçimi elde edilir; aynı fonksiyon $B(C+D)$ olarak yazılır ve yalnız NOR kapılarıyla kurulabilir.
- Beş değişkenli fonksiyonlarda "e / e' / 1 / 0" yöntemi
  - Doğruluk tablosu, yalnız son değişken ($e$) değişen ikili satır çiftlerine ayrılır. Her çift için çıkış $0$, $1$, $e$ ya da $e'$ olur.
  - Bu değerler dört değişkenli ($a,b,c,d$) bir haritaya yazılır. $1 = e + e'$ olduğu için $1$ hücreleri hem $e$ gruplarına hem $e'$ gruplarına katılabilir; $e$ grubuna $e'$ hücresi giremez.
  - Hiçbir $e$ ya da $e'$ açıkta kalmamalıdır; bir $1$ hücresi $e$ ile gruplandıysa $e'$ yarısı da bir gruba alınmalıdır.
  - Aynı yöntem üç değişkenli bir örnekle doğrulandı: klasik haritadan ve yöntemden aynı sonuç $\overline{c} + a\overline{b}$ çıktı.
- Önemsiz durumlar (don't care)
  - Tabloda $x$ ile gösterilen girişler $0$ da $1$ de sayılabilir. Grupları büyütmek için $1$ gibi kullanılır, böylece daha az literalli ifade elde edilir.
- Gray kod üretimi ve ikili-Gray kod dönüştürücü
  - Aynalama yöntemi: $0,1$ yaz, aynala, üst yarıya $0$, alt yarıya $1$ ekle; her adımda tekrarla.
  - 3 bitlik ikili koddan Gray koda dönüştürücü: $X = a$, $Y = a\overline{b} + \overline{a}b$, $Z = \overline{b}c + b\overline{c}$ (ekrandan, 01:05:00).
- Kümeler
  - Küme gösterimi, sonlu/sonsuz küme, boş küme, evrensel küme, kardinalite, alt küme ve öz alt küme.
  - $\{\emptyset\}$ bir elemanlı bir kümedir; $\emptyset$ ise boş kümedir.
  - Kuvvet kümesi: $|P(S)| = 2^{|S|}$.
  - İşlemler: birleşim, kesişim, fark, tümleyen, simetrik fark (XOR), Kartezyen çarpım; küme özdeşlikleri Boole cebri kurallarıyla aynıdır.
  - İçerme-dışlama: $|A\cup B| = |A| + |B| - |A\cap B|$; üç küme için kesişimler çıkarılıp üçlü kesişim geri eklenir.
  - Bit dizisiyle küme gösterimi: birleşim ve kesişim bit düzeyinde OR ve AND ile bulunur.
- Diziler, toplam ve çarpım sembolleri
  - Dizi, tam sayı indeksli ayrık bir yapıdır; artan, azalan dizi ve alt dizi tanımları.
  - $\sum$ ve $\prod$ gösterimi; algoritma karmaşıklığı analizinde gereklidir.
- Karakter katarları (string)
  - Uzunluk, boş katar $\lambda$, $X^*$ (boş katar dahil bütün katarlar), $X^+ = X^* - \{\lambda\}$, birleştirme (concatenation) ve $|\alpha\beta| = |\alpha| + |\beta|$.
- Sayı sistemleri
  - İkilik, sekizlik, onluk ve onaltılık tabanlar; dönüşümler ve onaltılık toplama.
- Bağıntılar
  - Bağıntı, Kartezyen çarpımın bir alt kümesidir; tanım ve değer kümesi.
  - Özellikler: yansıyan (reflexive), yansımayan (nonreflexive), hiç yansımayan (irreflexive), simetrik, ters simetrik (antisymmetric), geçişken (transitive).
  - Bağıntının tersi ve bileşkesi ($R^2 = R\circ R$).
  - Denklik bağıntısı (yansıyan + simetrik + geçişken) ve sıralama bağıntısı (yansıyan + ters simetrik + geçişken), Hasse diyagramı.
  - Geçişken kapanış için Warshall algoritması ve bağıntının matrisle gösterimi.
- Fonksiyonlar
  - Fonksiyon, bağıntının özel bir hâlidir: tanım kümesinde boşta eleman kalmaz ve her eleman tek bir elemana gider.
  - Birebir (injective), örten (surjective), birebir ve örten (bijective) fonksiyonlar; ters fonksiyon, bileşke, üstel/logaritmik fonksiyonlar, taban (floor) ve tavan (ceiling).

## Hocanın Özellikle Vurguladığı Kısımlar

- SOP/POS biçiminin pratik değeri
  - Kapı sayısı aynı kalsa bile tek tür kapı kullanmak entegre sayısını, dolayısıyla maliyeti azaltır. Devre ayrıntıları mantık devreleri dersinin konusudur; bu dersin sorumluluğu değildir.
- Beş değişkenli haritada dikkat
  - İki dört değişkenli haritayı üst üste düşünmek zordur; hoca $e/e'$ yöntemini kitaplarda pek bulunmayan ama mantığı öğreten bir yol olarak önerdi.
  - Açıkta $e$ ya da $e'$ kalmamalı; $1$ hücrelerinin iki yarısı da kapsanmalı.
- Gray kod tablosu rastgele yazılmaz
  - Sütunlar ikinin kuvvetlerine göre değişir; aynalama yöntemi bunu hızlıca üretir.
- Onaltılık sistemde $A$–$F$ harflerinin ve bunların ikili karşılıklarının ezbere bilinmesi gerekir.
- Bağıntı özellikleri
  - Bir bağıntı verilip yansıma, simetri, ters simetri ve geçişkenliğin olup olmadığı sorulabilir. Geçişkenlik için bütün $(x,y),(y,z)$ çiftleri tek tek kontrol edilmelidir; tek bir bozan durum yeterlidir.
  - Boş bağıntı geçişkendir (koşulu bozan çift yoktur).
- Ters fonksiyon her zaman fonksiyon değildir; yalnız birebir ve örten fonksiyonun tersi fonksiyondur.

## Kısa Tekrar Notları

- $\overline{\overline{F}} = F$: iki kez tümleyen alıp De Morgan uygulamak NAND/NOR biçimini verir.
- SOP → yalnız NAND; POS → yalnız NOR.
- 5 değişken: çiftler $(\dots0, \dots1)$ → $00\to0$, $11\to1$, $01\to e$, $10\to e'$.
- $1 = e + e'$; $e$ grubuna $1$ girebilir, $e'$ giremez.
- Don't care ($x$): işine gelirse $1$ say.
- Gray kod (3 bit): $000, 001, 011, 010, 110, 111, 101, 100$.
- İkili → Gray: $X=a$, $Y=a\oplus b$, $Z=b\oplus c$.
- $|P(S)| = 2^{|S|}$; $|\emptyset| = 0$, $|\{\emptyset\}| = 1$.
- $X\oplus Y = (X-Y)\cup(Y-X)$.
- $|A\times B| = |A|\cdot|B|$; Kartezyen çarpım değişmeli değildir.
- $|A\cup B\cup C| = |A|+|B|+|C|-|A\cap B|-|A\cap C|-|B\cap C|+|A\cap B\cap C|$.
- $\sum_{k=4}^{8}(-1)^k = 1$; $\sum_{i=1}^{4}\sum_{j=1}^{3} ij = 60$.
- $23A_{16} + 8F_{16} = 2C9_{16}$; $2345_{10} = 929_{16}$.
- Denklik: yansıyan + simetrik + geçişken. Sıralama (kısmi sıra): yansıyan + ters simetrik + geçişken.
- $R^{-1} = \{(y,x) \mid (x,y)\in R\}$; $R^n = R^{n-1}\circ R$.
- Bijektif fonksiyonun tersi fonksiyondur; $f(x)=2^x$ ile $\log_2 x$ birbirinin tersidir.
- $\lfloor 8.3\rfloor = 8$, $\lfloor 1/2\rfloor = 0$, $\lfloor -8.7\rfloor = -9$.

## Detaylı Açıklamalar

- NAND/NOR dönüşümü
  - $xyz$ ifadesinin iki kez tümleyeni alınır: $\overline{\overline{xyz}}$. İçteki tümleyen De Morgan ile açılınca $\overline{\overline{x}+\overline{y}+\overline{z}}$ olur. NOR kapısı girişlerini önce OR'lar sonra tümler; bu yüzden $\overline{x},\overline{y},\overline{z}$ tek bir NOR kapısına verilince $xyz$ elde edilir.
  - $BD + BC$ için: $\overline{\overline{BD}\cdot\overline{BC}}$. $B,D$ bir NAND kapısına, $B,C$ ikinci NAND kapısına, bu iki çıkış üçüncü NAND kapısına verilir. Aynı fonksiyon $B(C+D)$ diye kısaltılabilir, ama AND ve OR karışık olduğu için NAND'e dönüştürmek zorlaşır.
  - Aynı haritada sıfırlar gruplanırsa (8'li grup $B$, 4'lü grup $C+D$) POS biçimi $B\,(C+D)$ çıkar. İki kez tümleyen alınıp $\overline{\overline{B} + \overline{C+D}}$ yazılınca devre yalnız NOR kapılarıyla kurulur. <!-- BELİRSİZ: hocanın NOR devresini çizdiği kare yok; ayrıntı altyazıdan kuruldu. -->
- Beş değişkenli örnek (ekrandan, 00:40:00 ve 00:45:00)
  - Tablo $(a,b,c,d)$ aynı, $e$ farklı satır çiftlerine ayrıldı ve dört değişkenli haritaya şu değerler yazıldı (satır $ab$, sütun $cd$):

    | $ab \backslash cd$ | 00 | 01 | 11 | 10 |
    |---|---|---|---|---|
    | 00 | $e$ | 0 | $e'$ | $e$ |
    | 01 | $e'$ | $e$ | 0 | 1 |
    | 11 | 1 | $e$ | $e'$ | 0 |
    | 10 | 1 | 0 | $e'$ | $e$ |

  - Hocanın gruplarıyla elde edilen ifade (ekrandan, 00:55:00): $e\,\overline{b}\,\overline{d} + e\,b\,\overline{c}\,d + \overline{e}\,acd + \overline{e}\,\overline{b}cd + \overline{e}\,\overline{a}b\overline{d} + 1\cdot a\overline{c}\,\overline{d} + 1\cdot\overline{a}c\overline{d}$.
  - Ders sonrası not: Ekrandaki son terim $1\cdot\overline{a}c\overline{d}$ yazılmış. Bu grup $0010$ hücresini de kapsıyor, ama o hücrede yalnız $e$ var; terim böyle kalırsa $a=b=d=e=0, c=1$ girişinde fonksiyon yanlışlıkla $1$ olur. Doğrusu $e\,\overline{a}c\overline{d}$ olmalı ($0110$ hücresindeki $1$'in $e$ yarısı, $0010$'daki $e$ ile gruplanır). Düzeltilmiş ifade bütün 32 giriş için python ile kontrol edildi.
- Önemsiz durum örneği
  - $001, 010, 100$ girişlerinde çıkış $1$; $101$ ve $110$ önemsiz ($x$). $x$'ler $1$ sayılarak üç ikili grup kuruldu: $F = a\overline{c} + \overline{b}c + b\overline{c}$. $x$ kullanılmasaydı $100$ hücresi tek başına $a\overline{b}\,\overline{c}$ terimini verecekti.
- İkili → Gray kod dönüştürücü (ekrandan, 01:05:00)
  - Giriş $abc$ (ikili), çıkış $XYZ$ (Gray). Üç çıkış için ayrı haritalar çizildi: $X$ haritasında $a=1$ satırının tamamı $1$ → $X=a$. $Y$ haritasında $010, 011, 100, 101$ → $Y = a\overline{b}+\overline{a}b$. $Z$ haritasında $001, 010, 101, 110$ → $Z = \overline{b}c + b\overline{c}$.
  - Kontrol: $abc = 110$ için $X=1$, $Y = 1\cdot0 + 0\cdot1 = 0$, $Z = 0\cdot0 + 1\cdot1 = 1$; sonuç $101$, Gray tablosuyla aynı.
- Bağıntı örnekleri
  - $A=\{1,2,3,4\}$ üzerinde $a = b^2$ bağıntısı $\{(1,1),(4,2)\}$ olur. Yansıyan değildir (yalnız $(1,1)$ var, $(2,2)$ yok) ama hiç yansımayan da değildir; bu yüzden nonreflexive. $(4,2)$ varken $(2,4)$ yok, simetrik değil; ters simetriktir. $2$ ile başlayan çift olmadığı için geçişkenliği bozan durum yoktur, geçişkendir.
  - $R=\{(1,1),(2,2),(3,3),(1,2),(2,1),(1,3),(3,1),(2,3),(3,2)\}$: yansıyan, simetrik ve geçişken olduğu için denklik bağıntısıdır; ters simetrik değildir (ekrandan, 02:20:00).
  - Bileşke: $R=\{(1,1),(2,1),(3,2),(4,3)\}$ için $R^2=\{(1,1),(2,1),(3,1),(4,2)\}$ (ekrandan, 02:15:00), $R^3=\{(1,1),(2,1),(3,1),(4,1)\}$.
- Fonksiyonlar
  - Örnek (ekrandan, 02:30:00): $X=\{a,b,c,d\}$, $f(a)=f(b)=3$, $f(c)=5$, $f(d)=1$. Birebir değildir ($a$ ve $b$ aynı yere gider).
  - Ters fonksiyonlar (ekrandan, 02:35:00): $f=\{(1,a),(2,c),(3,b)\}$ için $f^{-1}=\{(a,1),(c,2),(b,3)\}$; $f(x)=x+1$ için $f^{-1}(x)=x-1$; $f(x)=ax+b$ için $f^{-1}(x)=\frac{x-b}{a}$; $f(x)=\frac{ax+b}{cx+d}$ için $f^{-1}(x)=\frac{-dx+b}{cx-a}$.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
