# Ders 1 Genişletilmiş Notu: Hesaplama Kuramına Giriş ve Küme Kuramı Temelleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ders nasıl çalışılır
- 2. Hesaplama kuramı neyi inceler
- 3. Karmaşıklık kuramı
- 4. Hesaplanabilirlik kuramı
- 5. Otomata kuramı
- 6. Küme kuramı temelleri
- 7. Küme işlemleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Ders nasıl çalışılır

Bu dönemin ilk dersi kısa tutulmuş bir giriş dersidir. Hoca dersin bir matematik dersi olduğunu, ancak sayılardan çok semboller ve ispatlarla uğraşılacağını belirtti. Ders slaytlar üzerinden işlenir.

Dersin kaynak kitabı Michael Sipser'in *Introduction to the Theory of Computation* kitabının üçüncü baskısıdır. Hoca kitabın her şeyi güzel açıkladığını söyledi. Önerdiği çalışma yolu üç adımlıdır:

- Dersleri izlemek ve derslere katılmak.
- Kitabı okumak ve bölüm sonlarındaki alıştırmaları çözmeye çalışmak.
- Kitabın yazarının kendi verdiği video dersleri izlemek (hoca, slayttaki bağlantının hâlâ çalışıp çalışmadığından emin değildi).

## 2. Hesaplama kuramı neyi inceler

Ders bazı temel soruları cevaplamayı amaçlar:

- Bilgisayar donanımının ve yazılımının matematiksel özellikleri nelerdir?
- Hesaplama nedir?
- Algoritma nedir?
- Bilgisayarların sınırları nelerdir? Bilgisayarlar her şeyi hesaplayabilir mi?

Öğrenciler daha önce başka derslerde pek çok algoritma görmüştür, ama bu derslerde algoritma büyük olasılıkla gayriresmî biçimde tanımlanmıştır. Bu derste algoritma biçimsel, yani matematiksel olarak tanımlanacaktır.

Son sorunun cevabı belki şaşırtıcıdır: hayır. Bilgisayarlar var olan her problemi çözemez ve bu, kuramsal olarak ispatlanmış bir sonuçtur. Özetle bu derste hesaplamanın biçimsel matematiksel modelleri geliştirilecektir. Ders üç ana kısımdan oluşur: karmaşıklık kuramı, hesaplanabilirlik kuramı ve otomata kuramı.

## 3. Karmaşıklık kuramı

Karmaşıklık kuramının sorusu şudur: Bazı problemleri hesaplama açısından zor, bazılarını kolay yapan nedir? Ders boyunca "kolay" ve "zor" kavramları da matematiksel olarak tanımlanacaktır.

### 3.1 Kolay problemler

Kolay problemler verimli biçimde, yani hızlı çözülebilen problemlerdir. Girdi sayısı çok büyük olsa bile makul bir sürede, çok çabuk çözülebilirler. Hocanın örnekleri:

- Bir grup sayıyı sıralamak.
- Bir listede bir adı aramak.
- İstanbul'da bir semtten başka bir semte en hızlı sürüş yolunu hesaplamak.

Bir milyon sayı varken de, bir milyar sayı varken de bu problemler hızlı ve makul sürede çözülebilir.

### 3.2 Zor problemler

Slayttaki tanıma göre bir problem, verimli çözülemiyorsa ya da verimli çözülüp çözülemeyeceğini bilmiyorsak "zor" diye adlandırılır (ekrandan, 00:25:00). Girdi büyüdüğünde bu problemler makul sürede çözülemez. Slayttaki örnekler:

- Bütün dersler için ders programı çizelgeleme (time table scheduling for all courses).
- 300 basamaklı bir tamsayıyı asal çarpanlarına ayırma.
- VLSI'da yongalar için yerleşim (layout) hesaplama.

Hoca ders programı örneğini şöyle açtı: tek bir üniversitede ders sayısı bin civarındadır ve bugünün bilgisayarları çok hızlı olduğu için bu çizelge makul sürede çıkarılabilir. Ama bin yerine dünyadaki bütün derslerin çizelgelenmesi düşünülürse milyonlarca ders söz konusu olur. Girdi bu kadar büyüdüğünde zor problemlerin çözümü çok uzun sürer ve makul sürede bitmez.

Slayttaki merkezi soru (ekrandan, 00:25:00): *Problemleri "zorluk" derecelerine göre sınıflandırmak; zor görünen problemlerin gerçekten zor olduğunu titiz bir ispatla göstermek.*

Bazı problemler zor, bazıları gerçekten çok zordur; bunların nasıl tanımlanacağı bu kuramın işidir. Bunun pratik bir önemi vardır: bir problemin kuramsal olarak çok zor olduğunu bilirsek buna hazırlanabiliriz. Girdi büyükse çözümün çok zaman alacağını önceden biliriz ve belki başka bir yola gideriz, problemi başka biçimde koyarız ya da başka yoldan çözeriz. Yani problemi anlamak çok önemlidir.

> **Ek bilgi (derste anlatılmadı):** Karmaşıklık kuramında "verimli çözülebilir" kavramı genellikle girdinin uzunluğuna göre polinom zamanda çözülebilme olarak biçimselleştirilir; bu sınıfa P denir. Zor problemlerin önemli bir kısmı NP-tam problemler arasında yer alır ve bunların polinom zamanda çözülüp çözülemeyeceği bilinmemektedir (P = NP? sorusu).

## 4. Hesaplanabilirlik kuramı

Bu kısımda bilgisayar nedir, algoritma nedir, hesaplama nedir sorularının biçimsel tanımları öğrenilecektir.

Karmaşıklık kuramında bazı problemlerin çok zor olduğunu söyledik; bu problemler çok zordur ama bir şekilde çözülebilir. Bazı problemler ise çözülemezdir: kuramsal olarak çözülmeleri mümkün değildir. Bir problemin çözülebilir olup olmadığını anlamak da çok önemlidir. Problem bilgisayarlarla çözülemiyorsa onun için program yazmaya çalışmaz, ona zaman harcamazsınız; elinizdeki asıl probleme farklı bir yoldan yaklaşırsınız.

> **Ek bilgi (derste anlatılmadı):** Çözülemez problemlerin en bilinen örneği durma problemidir (halting problem): verilen bir programın verilen bir girdide sonunda durup durmayacağına her durumda karar veren genel bir algoritma yoktur.

## 5. Otomata kuramı

Otomata kuramı farklı türdeki "hesaplama modellerinin" tanımları ve özellikleriyle ilgilenir (ekrandan, 00:30:00). Bu kısım dersin başlangıç bölümlerinde işlenecektir. Modeller önce çok basittir ve yetenekleri düşüktür; sonra giderek güçlenir. Slayttaki örnekler:

- **Sonlu otomatlar (Finite Automata):** Metin işlemede, derleyicilerde ve donanım tasarımında kullanılır. Yetenekleri düşüktür.
- **Bağlamdan bağımsız gramerler (Context-Free Grammars):** Programlama dillerini tanımlamakta ve yapay zekâda kullanılır. Biraz daha yeteneklidir.
- **Turing makineleri (Turing Machines):** Evdeki bilgisayarınız gibi "gerçek" bir bilgisayarın basit, soyut modelini oluşturur. Bir Turing makinesi gerçek bir bilgisayarın yapabildiği her şeyi yapabilir.

Slayttaki merkezi soru (ekrandan, 00:30:00): *Bu modeller aynı güçte midir, yoksa bir model ötekinden daha fazla problem çözebilir mi?*

Bir problem verildiğinde onu bu modellerden hangisinin çözebileceği önemli bir ayrım, bir sınıflandırmadır. Hoca bunun mühendislikteki karşılığını bir örnekle anlattı: bir buzdolabı ya da çamaşır makinesi yaptığınızı ve bir denetim problemiyle karşılaştığınızı düşünün. Problem sonlu bir otomatla çözülebiliyorsa makineye çok daha ucuz bir "zekâ" koyabilirsiniz, çünkü gereksinim sonlu otomatla karşılanır. Ama gereksinim yüksekse ve problem ancak bir Turing makinesiyle çözülebiliyorsa, gerçek bir bilgisayara benzeyen bir şeye, örneğin cep telefonundaki gibi gerçek bir yongaya ihtiyacınız vardır. Probleminizin sınıfını (sonlu otomat, bağlamdan bağımsız gramer ya da Turing makinesi) bilmek, başka kullanımların yanında ucuz makineler tasarlamanızı da sağlar.

## 6. Küme kuramı temelleri

Matematiğin en azından bir kısmı küme kuramına dayanır; bu ders de küme kuramına dayanır. Bu yüzden küme kuramı çok önemlidir. Hoca bu konuların büyük olasılıkla bilindiğini, ama gösterimi vermek için tekrar edeceğini söyledi.

### 6.1 Küme ve temel sayı kümeleri

Küme, iyi tanımlanmış nesnelerin topluluğudur (ekrandan, 00:35:00). İyi bilinen kümeler:

- **Doğal sayılar:** $\mathbb{N} = \{1, 2, 3, \dots\}$. Bazı kitaplarda ve bazı matematikçilerde doğal sayılar sıfırdan başlar; bu derste sıfır doğal sayı değildir, doğal sayılar 1'den başlar.
- **Tamsayılar:** $\mathbb{Z} = \{\dots, -3, -2, -1, 0, 1, 2, 3, \dots\}$. Eksi sonsuzdan artı sonsuza uzanır.
- **Rasyonel sayılar:** $\mathbb{Q} = \{m/n : m \in \mathbb{Z},\ n \in \mathbb{Z},\ n \neq 0\}$. İki tamsayının bölümü olarak yazılabilen sayılardır.
- **Gerçel sayılar:** $\mathbb{R}$ ile gösterilir.

> **Hocanın vurgusu:** Bu derste doğal sayılar 1'den başlar; 0 doğal sayı değildir.

### 6.2 Küme gösterimi nasıl okunur

Hoca $\mathbb{Q}$'nun tanımı üzerinden gösterimin okunuşunu anlattı. İki nokta üst üste (":") "öyle ki" (such that), virgül "ve" diye okunur. Buna göre:

$\mathbb{Q} = \{m/n : m \in \mathbb{Z},\ n \in \mathbb{Z},\ n \neq 0\}$

"$\mathbb{Q}$, $m/n$ biçiminde gösterilebilen sayılar kümesidir, öyle ki $m$ tamsayılar kümesindedir ve $n$ tamsayılar kümesindedir ve $n$ sıfıra eşit değildir" diye okunur. Bir sayı bu biçimde gösterilebiliyorsa ona rasyonel sayı denir. Örneğin $3$ rasyoneldir, çünkü $3 = 3/1$ biçiminde yazılabilir; $2/3$ de rasyoneldir.

### 6.3 İrrasyonel sayılar

Slaytta "İrrasyonel sayılar nedir?" diye soruldu (ekrandan, 00:35:00). En basit tanım, rasyonel olmayan sayılar kümesidir. Örneğin $\pi$ irrasyoneldir, çünkü $\pi$ iki tamsayının bölümü olarak yazılamaz.

### 6.4 Gerçel sayılar

Gerçel sayılar kümesi $\mathbb{R}$ ile gösterilir. Hoca gerçel sayıların biçimsel tanımının derste daha sonra verilip verilmeyeceğini hatırlamadığını söyledi. Önemli iki özellik: $\mathbb{R}$ sayılamaz (uncountable) bir kümedir ve hem rasyonel hem irrasyonel sayıları içerir. Örneğin $\pi$ bir gerçel sayıdır.

> **Ek bilgi (derste anlatılmadı):** Bir küme, elemanları doğal sayılarla bire bir eşlenebiliyorsa sayılabilir (countable) denir; $\mathbb{N}$, $\mathbb{Z}$ ve $\mathbb{Q}$ sayılabilirdir. $\mathbb{R}$ için böyle bir eşleme yoktur; bu, Cantor'un köşegen yöntemiyle gösterilir ve aynı yöntem ileride hesaplanabilirlik konusunda da karşımıza çıkar.

### 6.5 Alt küme ve kuvvet kümesi

$A$ ve $B$ iki küme olsun. $A$'nın her elemanı aynı zamanda $B$'nin de elemanıysa $A$, $B$'nin alt kümesidir ve $A \subseteq B$ diye yazılır (ekrandan, 00:35:00). Örneğin doğal sayılar tamsayıların alt kümesidir, $\mathbb{N} \subseteq \mathbb{Z}$, çünkü $\mathbb{N}$'nin her elemanı $\mathbb{Z}$'nin de elemanıdır.

Bir $B$ kümesinin kuvvet kümesi $\mathcal{P}(B)$, $B$'nin bütün alt kümelerinin kümesidir:

$\mathcal{P}(B) = \{A : A \subseteq B\}$

Kümenin kendisi de bir alt kümedir ve boş küme her kümenin alt kümesidir. Bu yüzden slaytta belirtildiği gibi $\emptyset \in \mathcal{P}(B)$ ve $B \in \mathcal{P}(B)$'dir.

## 7. Küme işlemleri

$A$ ve $B$ iki küme olsun. Slayttaki tanımlar (ekrandan, 00:45:00):

- **Birleşim:** $A \cup B = \{x : x \in A \text{ veya } x \in B\}$
- **Kesişim:** $A \cap B = \{x : x \in A \text{ ve } x \in B\}$
- **Fark:** $A \setminus B = \{x : x \in A \text{ ve } x \notin B\}$; $A$'da olup $B$'de olmayan elemanlar.
- **Kartezyen çarpım:** $A \times B = \{(x, y) : x \in A \text{ ve } y \in B\}$
- **Tümleyen:** $\bar{A} = \{x : x \notin A\}$; kümenin adının üstüne yatay bir çizgi konarak gösterilir.

### 7.1 Kartezyen çarpım

Kartezyen çarpımın elemanları ikililerdir (pair). $(x, y)$ bir ikilidir, çünkü bu dizilimde (tuple) iki şey vardır: önce $x$, sonra $y$. Kartezyen çarpım bu ikililerin kümesidir; ikilinin ilk elemanı $x$, $A$'dan, ikinci elemanı $y$, $B$'den gelir. Bu gösterimde sıra önemlidir.

> **Hocanın vurgusu:** Kartezyen çarpım bu derste önemlidir; ders kitabını okurken bu gösterimle çok sık karşılaşılır.

Hocanın tahtaya yazdığı örnek (ekrandan, 00:45:00):

- Verilen: $A = \{1, 2\}$, $B = \{3, 4\}$.
- İlk eleman $A$'dan seçilir. $1$ için: $(1, 3)$ ve $(1, 4)$.
- Sonra $2$ için: $(2, 3)$ ve $(2, 4)$.
- Sonuç: $A \times B = \{(1, 3), (1, 4), (2, 3), (2, 4)\}$.

Sonuç python ile (`itertools.product`) doğrulanmıştır. Çarpımda $|A| \cdot |B| = 2 \cdot 2 = 4$ eleman vardır (ara adım eklendi).

## Örnek Sorular

**Soru 1** (ekrandan, 00:35:00): İrrasyonel sayılar nedir?

> **Cevap (derste verildi):** Rasyonel olmayan, yani iki tamsayının bölümü $m/n$ ($n \neq 0$) olarak yazılamayan sayılardır. Örnek: $\pi$.

**Soru 2** (derste tahtada, 00:43:21): $A = \{1, 2\}$ ve $B = \{3, 4\}$ ise $A \times B$ nedir?

> **Cevap (derste verildi):** $A \times B = \{(1, 3), (1, 4), (2, 3), (2, 4)\}$. Her ikilinin ilk elemanı $A$'dan, ikinci elemanı $B$'den gelir.

## Dersin Toparlaması

Bu giriş dersinde hesaplama kuramının neyi incelediği genel olarak ortaya kondu. Ders üç kısımdan oluşur: problemleri zorluk derecelerine göre sınıflandıran karmaşıklık kuramı, bazı problemlerin hiç çözülemeyeceğini gösteren ve bilgisayar, algoritma, hesaplama kavramlarını biçimsel olarak tanımlayan hesaplanabilirlik kuramı, ve sonlu otomatlar, bağlamdan bağımsız gramerler ve Turing makineleri gibi hesaplama modellerinin gücünü karşılaştıran otomata kuramı. Ardından dersin dayandığı küme kuramının temel gösterimleri tekrar edildi: temel sayı kümeleri, alt küme, kuvvet kümesi ve birleşim, kesişim, fark, Kartezyen çarpım, tümleyen işlemleri.

Bir sonraki derste bağıntılar (relations) ve fonksiyonlarla devam edileceği söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
