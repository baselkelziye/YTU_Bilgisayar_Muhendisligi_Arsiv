# Ders 4 Çalışma Özeti

## Genel Konular

- Bool cebri ile sadeleştirme örnekleri
  - $x+\overline{x}y = x+y$ kuralı hatırlatıldı. Örnek: $\overline{z}\,(xy+x\overline{y}+\overline{x}y)$ ifadesinde önce $x$ paranteze alınır: $x(y+\overline{y})+\overline{x}y = x+\overline{x}y = x+y$. Sonuç $\overline{z}(x+y)$, istenirse SOP biçiminde $x\overline{z}+y\overline{z}$ (ekrandan, 00:20:00 ve 00:30:00).
  - Ortak parantez almadan önce aynı terimler birleştirilir: $AA=A$, $AB+AB=AB$. $1$ ile toplanan her şey $1$ olur.
  - $(A+B)(A+C) = A+BC$ (ekrandan, 00:45:00): $AA+AC+AB+BC = A(1+C+B)+BC = A+BC$.
  - Daha karmaşık örnek (ekrandan, 00:55:00): $\overline{\overline{A}(B+\overline{C})}\cdot(A+\overline{B}+\overline{C})\cdot\overline{\overline{A}\,\overline{B}\,\overline{C}}$. De Morgan ile tümleyenler kaldırılır, parantezler açılır, $A$ ortak paranteze alınır. Sonuç $A+\overline{B}C$ (ekrandan, 01:00:00).
- Karnaugh haritasında gruplama hatası örneği
  - $\sum m(2,7,8,10,12,13,14)$, dört değişken, dört bitlik harita (ekrandan, 00:30:00).
  - Dörtlü grup $A\overline{D}$; ikili gruplar $\overline{B}C\overline{D}$ (2 ve 10) ve $AB\overline{C}$ (12 ve 13); tek kalan 7 için $\overline{A}BCD$.
  - Sonuç: $F = A\overline{D}+\overline{B}C\overline{D}+AB\overline{C}+\overline{A}BCD$.
  - Harita eksenlerinde $AB$'nin satıra mı sütuna mı yazıldığı sonucu değiştirmez; önemli olan $00,01,11,10$ sırasıdır.
- SOP ve POS biçimleri
  - SOP (sum of products): çarpımların toplamı, örneğin $abc+\overline{a}\,\overline{b}c$. POS (product of sums): toplamların çarpımı, örneğin $(\overline{a}+b+c)(\overline{a}+\overline{c})$ (ekrandan, 00:35:00).
  - Sayısal gösterim: SOP için $\sum m(\dots)$, POS için $\prod(\dots)$. Örnek: $\prod(5,4,3,6)$; en büyük sayı 6 olduğu için 3 bit gerekir (ekrandan, 00:35:00).
- Dual alma ile SOP'tan POS'a örnek
  - $f(A,B,C) = A\overline{C}+\overline{A}B+\overline{B}C$ (ekrandan, 00:40:00). Dual: $+$ ile $\cdot$ yer değiştirir, tümleyenler aynen kalır: $(A+\overline{C})(\overline{A}+B)(\overline{B}+C)$.
  - Açılıp sadeleştirilince $ABC+\overline{A}\,\overline{B}\,\overline{C}$ bulundu; bunun duali $(A+B+C)(\overline{A}+\overline{B}+\overline{C})$ oldu.
  - Devre: iki üç girişli AND (biri tümlenmiş girişlerle) ve bir OR (ekrandan, 00:45:00).
- NAND, NOR, XNOR ve evrensel kapılar
  - NAND = AND + NOT, NOR = OR + NOT, XNOR = XOR + NOT. Evrensel kapılar devre elemanı sayısını ve maliyeti azaltır.
  - Örnek: dört bitlik sayı 3'ten küçük ya da 12'den büyükse çıkış 1: $\sum m(0,1,2,13,14,15)$. Karnaugh ile $f = ABD+ABC+\overline{A}\,\overline{B}\,\overline{C}+\overline{A}\,\overline{B}\,\overline{D}$ (ekrandan, 01:10:00).
  - Yalnız NAND ile: ifadenin iki kez tümleyeni alınır, De Morgan ile $f=\overline{\overline{ABD}\cdot\overline{ABC}\cdot\overline{\overline{A}\,\overline{B}\,\overline{C}}\cdot\overline{\overline{A}\,\overline{B}\,\overline{D}}}$. Dört üç girişli NAND ve bir dört girişli NAND, toplam beş NAND (ekrandan, 01:15:00).
  - Yalnız NOR ile: haritada 0'lar gruplanır, POS biçimi bulunur: $f=(A+\overline{C}+\overline{D})(\overline{A}+C+D)(\overline{A}+B)(A+\overline{B})$; iki kez tümleyen alınınca her parantez bir NOR, dışı da bir NOR olur (ekrandan, 01:45:00).
- Önemsiz (don't care) durumlar
  - Haritada $X$ ile gösterilir. Grubu büyütmeye yarıyorsa 1, yaramıyorsa 0 sayılır.
  - Aynı örnekte 3 önemsiz olursa $f=\overline{A}\,\overline{B}+ABD+ABC$; 3 ve 12 önemsiz olursa iki dörtlü grup çıkar: $f=\overline{A}\,\overline{B}+AB$ (ekrandan, 01:50:00).
- Beş değişkenli problem: haritaya değişken yazma
  - Oylama örneği: ağırlıklar $A=30$, $B=25$, $C=25$, $D=10$, $E=10$; toplam $\geq 65$ ise çıkış 1 (ekrandan, 01:55:00).
  - Doğruluk tablosunda yalnız $E$'si farklı satır çiftleri karşılaştırılır: sonuç $E=0$'da 0, $E=1$'de 1 ise hücreye $E$; ikisinde de 1 ise 1 yazılır. Böylece dört değişkenli harita yeter (ekrandan, 02:00:00).
  - Hocanın bulduğu ifadede hata var; doğrusu aşağıdaki "Ders sonrası not" maddesinde.
- Quine-McCluskey yöntemi
  - Çok değişkenli ifadeler için algoritmik sadeleştirme. Mintermler içerdikleri 1 sayısına göre gruplanır; komşu gruplarda tek bit farklı olanlar birleştirilir, değişen bit "d" (ya da "-") ile işaretlenir; işlem birleşme kalmayana dek sürer (ekrandan, 02:10:00 ve 02:15:00).
  - Örnek: mintermler 0, 3, 5, 6, 7, 10, 12, 13; önemsizler 2, 9, 15. Asal çarpanlar: $\overline{W}\,\overline{X}\,\overline{Z}$, $\overline{W}Y$, $\overline{X}Y\overline{Z}$, $XZ$, $W\overline{Y}Z$, $WX\overline{Y}$. Bütün mintermleri en az terimle kapsayan seçim: $XZ+WX\overline{Y}+\overline{X}Y\overline{Z}+\overline{W}Y+\overline{W}\,\overline{X}\,\overline{Z}$.
- Matematik dili: kümeler
  - Küme: ayrık nesnelerden oluşan topluluk. Venn şeması, liste ve tanım (kural) gösterimi.
  - Sonlu ve sonsuz küme, boş küme ($\emptyset$ ya da $\{\}$; $\{\emptyset\}$ boş küme değildir), evrensel küme (problemin tanım alanı; sonlu da olabilir).
  - Kardinalite $|S|$: farklı elemanların sayısı. Sonsuz kümelerde sayılabilir (doğal sayılar, tam sayılar) ve sayılamaz (reel sayılar) ayrımı.
  - Alt küme $X\subseteq Y$, eşitlik $X=Y \iff X\subseteq Y \wedge Y\subseteq X$, öz alt küme, $\emptyset$ her kümenin alt kümesidir (ekrandan, 02:30:00).
  - Kuvvet kümesi: $2^S=\{x : x\subseteq S\}$; $|S|=n$ ise $|2^S|=2^n$ (ekrandan, 02:35:00).
  - Birleşim (OR), kesişim (AND), ayrık kümeler, tümleyen, fark, simetrik fark $X\oplus Y=(X-Y)\cup(Y-X)$ (XOR) (ekrandan, 02:40:00).
  - Küme işlemlerinin özellikleri: birleşme, değişme, dağılma, birim, tümleyen, eş kuvvetlilik, sınır, yutma, involüsyon, 0/1 kanunu, De Morgan (ekrandan, 02:45:00).
  - Kartezyen çarpım: $A\times B=\{(a,b) : a\in A \wedge b\in B\}$; $A\times B \neq B\times A$; $|A\times B|=|A|\cdot|B|$.
  - Genelleştirilmiş birleşim ve kesişim, $s(A\cup B)=s(A)+s(B)-s(A\cap B)$ ve üç küme için içerme-dışlama (ekrandan, 02:50:00).
  - Küme işlemlerinin bit düzeyi karşılığı: AND, OR, XOR; XOR ile şifreleme.

## Hocanın Özellikle Vurguladığı Kısımlar

- Karnaugh haritasındaki satır/sütun kodları
  - Derste en sık yapılan hata, $00,01,11,10$ sırasını bozmak ya da yanlış hücreye 0/1 yazmaktır.
- Ortak terime dikkat
  - Parantez almadan önce $AA=A$, $AB+AB=AB$ gibi birleştirmeler yapılmazsa sadeleştirme tıkanır.
- Evrensel kapılarla maliyet
  - Tasarımda amaç en az devre elemanı kullanmaktır. Yalnız NAND için 1'ler, yalnız NOR için 0'lar gruplanır ve iki kez tümleyen alınır.
  - Yalnız NAND istendiğinde terimlerin girişlerinde NOT kullanmak serbesttir; terimleri birleştiren kapılar NAND olur.
- Sadeleştirme araçlarının kapsamı
  - Karnaugh haritası 3-4 değişkenli problemler için uygundur; daha çok değişkenli ifadeler Bool cebri kurallarıyla ya da algoritmik yöntemle (Quine-McCluskey) sadeleştirilir.
- Alt küme kavramı
  - Alt küme yalnız matematik konusu değildir; örneğin 1000 verinin %80'iyle (800 veri) eğitim kümesi oluşturmak bir alt küme seçmektir.

## Kısa Tekrar Notları

- $x+\overline{x}y=x+y$; $A+AB=A$; $A(A+B)=A$; $(A+B)(A+C)=A+BC$.
- SOP = çarpımların toplamı, POS = toplamların çarpımı; $\sum m$ ve $\prod$ gösterimi.
- Bir ifadenin duali: $+\leftrightarrow\cdot$, $0\leftrightarrow 1$; tümleyenler değişmez. Dual genelde ifadeye eşit değildir.
- NAND/NOR evrenseldir. Yalnız NAND: 1'leri grupla, SOP'un iki kez tümleyenini al. Yalnız NOR: 0'ları grupla, POS'un iki kez tümleyenini al.
- Önemsiz durum $X$: işe yarıyorsa gruba katılır, zorunlu değildir.
- 5 değişken: bir değişken haritaya hücre değeri olarak yazılabilir ($0$, $1$, $E$, $\overline{E}$).
- Quine-McCluskey: 1 sayısına göre grupla, tek bit farkla birleştir, asal çarpanlardan en az terimle bütün mintermleri kapsa.
- $|2^S|=2^{|S|}$, $|A\times B|=|A||B|$, $|A\cup B|=|A|+|B|-|A\cap B|$.
- Simetrik fark XOR'a, birleşim OR'a, kesişim AND'e karşılık gelir.
- Ders sonrası not: hoca bir yerde SOP için "toplamların çarpımı" dedi (00:21:19); doğrusu SOP çarpımların toplamı, POS toplamların çarpımıdır.
- Ders sonrası not (oylama örneği): hoca $AB$ ve $AC$ dörtlülerine $E$ yazılı hücreleri de kattı ve $AB+AC+\dots$ buldu. Bu ifade 10100 (puan 55) ve 11000 (puan 55) satırlarında yanlışlıkla 1 verir. 1'ler gruplanırken $E$ hücreleri 0 sayılmalı, $E$'ler gruplanırken 1'ler önemsiz sayılabilir. Python ile bulunan en sade doğru ifade: $f=ABC+ABD+ACD+ABE+ACE+BCDE$. Hoca da kuraldan emin olmadığını, sonraki derste döneceğini söyledi.
- Ders sonrası not (dual örneği): $f=A\overline{C}+\overline{A}B+\overline{B}C$ yalnız 000 ve 111'de 0'dır; ara sonuç $ABC+\overline{A}\,\overline{B}\,\overline{C}$ $f$'ye eşit değildir, $f$'nin dualidir (bu örnekte $\overline{f}$ ile aynı). Dualin duali yeniden $f$'yi verir; bu yüzden son sonuç $(A+B+C)(\overline{A}+\overline{B}+\overline{C})$ doğrudur (python ile denetlendi).

## Detaylı Açıklamalar

- **Sadeleştirmede sıra.** Derste önce $\overline{z}(xy+x\overline{y}+\overline{x}y)$ çözüldü. Parantezin içi ayrı düşünülür: $xy+x\overline{y}=x(y+\overline{y})=x$, kalan $x+\overline{x}y$ ifadesi $x+y$ olur. Bir öğrenci $y$'lerin üçünün birden paranteze alınıp alınamayacağını sordu; hoca $x$ parantezinin yalnız $x$ içeren iki terimde ortak olduğunu, üçüncü terimde $\overline{x}$ bulunduğunu açıkladı. Sonuç ya $\overline{z}(x+y)$ biçiminde bırakılır ya da SOP istenirse $x\overline{z}+y\overline{z}$ diye açılır.
- **Karmaşık ifade örneği.** $\overline{\overline{A}(B+\overline{C})}=A+\overline{B}C$ ve $\overline{\overline{A}\,\overline{B}\,\overline{C}}=A+B+C$ olur. Önce $(A+\overline{B}C)(A+\overline{B}+\overline{C})$ açılır; $A$ ortak paranteze alınınca $A(1+\dots)+\overline{B}C=A+\overline{B}C$ kalır ($\overline{B}C\,\overline{C}=0$, $\overline{B}C\overline{B}=\overline{B}C$). Sonra $(A+\overline{B}C)(A+B+C)$ açılır: $A+\overline{B}CB+\overline{B}CC = A+0+\overline{B}C$. Sonuç $A+\overline{B}C$ (python ile doğrulandı). Hoca derste bir terimi yanlışlıkla silmiş, öğrenci sorusu üzerine düzeltmiştir.
- **NAND ile gerçekleme.** $f=ABD+ABC+\overline{A}\,\overline{B}\,\overline{C}+\overline{A}\,\overline{B}\,\overline{D}$ için $f=\overline{\overline{f}}$ yazılır ve iç tümleyen De Morgan ile dağıtılır. Her çarpım terimi bir NAND'in çıkışıdır; bu dört çıkış son bir dört girişli NAND'e girer. Hoca doğruluk tablosunun ve haritanın aynı fonksiyonu verdiğini, aradaki tek farkın kapı türü olduğunu vurguladı.
- **NOR ile gerçekleme.** 0'lar gruplanır ve her grup bir toplam terimi verir: 3 ve 7 için $A+\overline{C}+\overline{D}$, 8 ve 12 için $\overline{A}+C+D$, 8-11 dörtlüsü için $\overline{A}+B$, 4-7 dörtlüsü için $A+\overline{B}$. Bu çarpımın iki kez tümleyeni alınınca $f=\overline{\overline{(A+\overline{C}+\overline{D})}+\overline{(\overline{A}+C+D)}+\overline{(\overline{A}+B)}+\overline{(A+\overline{B})}}$ olur; her iç parantez bir NOR, dış işlem de bir NOR'dur (python ile doğrulandı).
- **Haritaya değişken yazma (5 değişken).** 32 satırlık tablo, $E$ dışındaki bitleri aynı olan satır çiftlerine ayrılır. Örnekte $ABCD=0111$, $1010$ ve $1100$ hücrelerine $E$, $1011$, $1101$, $1110$, $1111$ hücrelerine 1, diğerlerine 0 yazılır. Hoca $E$ değerinin $\overline{E}$ olabileceği durumu da örnekledi (sonuç $E=0$'da 1, $E=1$'de 0 ise). Doğru sadeleştirme için yukarıdaki "Ders sonrası not" maddesine bakın.
- **Quine-McCluskey.** Karnaugh haritası 5-6 değişkenden sonra kullanışsızdır; Quine-McCluskey aynı birleştirmeyi tabloyla, bilgisayarda uygulanabilir biçimde yapar. Birleşmeyen terimler (örnekte 0-2, 2-10, 9-13, 12-13 ve dörtlüler) asal çarpanlardır. Seçim aşamasında önemsizler kapsanmak zorunda değildir; amaç bütün mintermleri en az terimle kapsamaktır. Örnekte $W\overline{Y}Z$ (9, 13) seçilmeden bütün mintermler kapsanır (python ile doğrulandı).
- **Kümelerden algoritmaya.** Kümeler, kartezyen çarpım, bağıntılar ve fonksiyonlar algoritma kavramına giden yolun temelidir. Hoca cebirsel yapıları kısaca hatırlattı: kapalılık ve birleşme varsa yarı grup; birim ve ters eleman da varsa grup; değişme de varsa abelyen grup. Mod 26'da 2'nin çarpmaya göre tersi olmadığı için çarpma işlemi orada grup oluşturmaz.
- **Kümeler ve mantık.** Birleşim mantıksal OR'a ve Bool toplamına, kesişim AND'e ve Bool çarpımına, simetrik fark XOR'a karşılık gelir. Fark işlemi "X ama Y değil" ($z\in X \wedge z\notin Y$) biçiminde okunur. Küme özdeşlikleri Bool cebrinin özdeşlikleriyle aynıdır: $A\cup\emptyset=A$ ile $A+0=A$, $A\cup U=U$ ile $A+1=1$, $A\cup(A\cap B)=A$ ile $A+AB=A$.
- **İçerme-dışlama.** İki küme için kesişim bir kez çıkarılır. Üç kümede $|A|+|B|+|C|$ toplanır, ikili kesişimler çıkarılır, fazladan çıkarılan üçlü kesişim geri eklenir: $|A\cup B\cup C|=|A|+|B|+|C|-|A\cap B|-|A\cap C|-|B\cap C|+|A\cap B\cap C|$. <!-- BELİRSİZ: Slayttaki 217 öğrencili örneğin ara sayıları karede görünmüyor; altyazıda sonuç "onç" (büyük olasılıkla 13) diye geçiyor. -->
- **XOR ile şifreleme.** Anahtar ve mesaj bit bit XOR'lanır; bitler aynıysa 0, farklıysa 1 çıkar ve şifreli metin elde edilir. <!-- BELİRSİZ: Derste kullanılan anahtar ve mesaj bitleri karede görünmüyor, altyazıdan kesin çıkmıyor. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
