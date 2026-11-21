# Ders 10 Genişletilmiş Notu: Vektörlere Giriş, Vektör Cebiri, İç Çarpım, Vektörel Çarpım, Karma Çarpım ve İkili Vektörel Çarpım

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Vektör Kavramı, Fiziksel Yorum ve Norm (Uzunluk)
  - 1.1 Skaler ve Vektör Tanımları
  - 1.2 $\mathbb{R}^3$ ve $\mathbb{R}^2$ Uzaylarında İki Nokta Arasındaki Vektör ve Uzunluğu (Normu)
  - 1.3 Birim Vektör (Unit Vector) ve Bir Vektörü Birim Vektöre Dönüştürme
- 2. Vektör Cebiri ve Analitik (Bileşen) Gösterim
  - 2.1 Vektörlerde Toplama İşlemi ve Geometrik Yorumu (Üçgen ve Paralelkenar Kuralı)
  - 2.2 Bir Vektörün Skaler ile Çarpımı ve Vektörlerin Paralelliği
  - 2.3 Standart Baz Vektörleri ($\vec{i}, \vec{j}, \vec{k}$) ve Vektörlerin Analitik (Bileşen) Formu
- 3. İç Çarpım / Nokta Çarpım / Skaler Çarpım (Dot / Inner / Scalar Product)
  - 3.1 İç Çarpımın Tanımı ve $\mathbb{R}^4$ Uzayında Sayısal Örnek
  - 3.2 İç Çarpımda Birleşme Özelliğinin Geçersizliği ve Üç Vektörün İç Çarpımı Sorusu
  - 3.3 İç Çarpımın Özellikleri ve Diklik (Orthogonality) Koşulu
  - 3.4 İki Vektör Arasındaki Açının Bulunması ve Sayısal Örnek
- 4. Vektörel Çarpım / Dış Çarpım (Cross / Vector Product)
  - 4.1 Vektörel Çarpımın Tanımı, Homojen Sistemden Çıkarılışı ve Geometrik Yorumu
  - 4.2 Determinant ve Laplace Açılımı Yardımıyla Vektörel Çarpım Hesabı
  - 4.3 Standart Baz Vektörlerinin Vektörel Çarpımı ($\vec{i}, \vec{j}, \vec{k}$ Çemberi)
  - 4.4 $\mathbb{R}^3$ Uzayında Vektörel Çarpım Örneği
  - 4.5 Vektörel Çarpımın Özellikleri ve Paralellik Koşulu
- 5. Karma Çarpım (Mixed / Scalar Triple Product) ve Paralelkenar Prizmanın Hacmi
  - 5.1 Karma Çarpımın Determinant Formülü ve Geometrik Anlamı
  - 5.2 Karma Çarpım ve Paralelkenar Prizma Hacmi Örneği
- 6. İkili Vektörel Çarpım (Two-Fold Cross Product / Vector Triple Product)
  - 6.1 İkili Vektörel Çarpım Özdeşliği
  - 6.2 İkili Vektörel Çarpım Sayısal Örneği
- Örnek Sorular
- Dersin Toparlaması

## 1. Vektör Kavramı, Fiziksel Yorum ve Norm (Uzunluk)

Hoca bu derste vektör kavramını tanıtacağımızı ve vektörler üzerindeki önemli çarpım işlemlerini — iç çarpım (inner / dot product), vektörel çarpım (cross / vector product), karma çarpım (mixed / scalar triple product) ve ikili vektörel çarpım (two-fold cross product) — inceleyeceğimizi belirterek derse başladı.

### 1.1 Skaler ve Vektör Tanımları

Fiziksel dünyada karşılaştığımız pek çok nicelik iki farklı grupta incelenir (ekrandan, 00:08:30):

1. **Skaler Nicelikler (Scalars):** Sıcaklık (temperature) veya sürat (speed) gibi pek çok fiziksel nicelik yalnızca bir **büyüklüğe** (magnitude) sahiptir. Bu tür nicelikleri yalnızca tek bir reel sayıyla temsil edebiliriz; bu reel sayılara **skaler** (scalar) adı verilir.
2. **Vektörel Nicelikler (Vectors):** Kuvvet (force) ve hız (velocity) gibi nicelikleri tam olarak ifade edebilmek için ise hem **büyüklüğe** (magnitude) hem de **yöne** (direction) ihtiyaç duyarız. Bu nicelikler, belirli bir $A$ referans noktasından çıkan, uygun uzunluğa ve yöne sahip oklarla (yönlü doğru parçalarıyla) temsil edilir ve bunlara **vektör** (vector) denir.

- **Tanım (Vektör — ekrandan, 00:08:30):** Birbirinden farklı $A$ ve $B$ noktaları için, $A$ noktasından (başlangıç noktası / initial point / start point) $B$ noktasına (bitiş noktası / terminal point / end point) çizilen yönlü doğru parçasına (directed line segment) **sıfırdan farklı bir vektör** (nonzero vector) denir ve $\vec{AB}$ ile gösterilir.
- **Vektörün Uzunluğu (Magnitude / Length / Norm):** $\vec{AB}$ vektörünün büyüklüğü (uzunluğu veya normu), $AB$ doğru parçasının uzunluğudur ve $\|\vec{AB}\|$ veya bazı kitaplarda $|\vec{AB}|$ ile gösterilir.
- **Sıfır Vektörü (Zero Vector):** Yönü diğer vektörlerle aynı biçimde tanımlanamayan, yalnızca tek bir noktadan ibaret olan ve uzunluğu $0$ olan vektöre **sıfır vektörü** denir ve $\vec{0}$ ile gösterilir.

### 1.2 $\mathbb{R}^3$ ve $\mathbb{R}^2$ Uzaylarında İki Nokta Arasındaki Vektör ve Uzunluğu (Normu)

$\mathbb{R}^3$ üç boyutlu Öklid uzayında $P_0(x_0, y_0, z_0)$ ve $P_1(x_1, y_1, z_1)$ gibi iki nokta alalım. Burada $x_0, y_0, z_0 \in \mathbb{R}$ üçer reel sayı olduğundan bu noktalar $\mathbb{R}^3$ uzayının elemanlarıdır. Başlangıç noktası $P_0$ ve bitiş noktası $P_1$ olan vektör, $P_0$'dan $P_1$'e çizilen bir okla gösterilir ve bitiş noktasının koordinatlarından başlangıç noktasının karşılıklı koordinatlarının çıkarılmasıyla tanımlanır:
$$\vec{v} = \vec{P_0 P_1} = (x_1 - x_0, \, y_1 - y_0, \, z_1 - z_0)$$
Bu $\vec{v} \in \mathbb{R}^3$ vektörünün **uzunluğu (normu / büyüklüğü)** ise bileşenlerinin kareleri toplamının karekökü alınarak hesaplanır:
$$|\vec{v}| = \|\vec{P_0 P_1}\| = \sqrt{(x_1 - x_0)^2 + (y_1 - y_0)^2 + (z_1 - z_0)^2}$$

Benzer şekilde $\mathbb{R}^2$ Öklid düzleminde (plane) her noktanın iki koordinatı vardır. $P_0(x_0, y_0) \in \mathbb{R}^2$ ve $P_1(x_1, y_1) \in \mathbb{R}^2$ noktaları için $\vec{v} = \vec{P_0 P_1}$ vektörü ve normu şu şekildedir (ekrandan, 00:15:30):
$$\vec{v} = \vec{P_0 P_1} = (x_1 - x_0, \, y_1 - y_0), \quad |\vec{v}| = \sqrt{(x_1 - x_0)^2 + (y_1 - y_0)^2}$$

#### Örnek: $\mathbb{R}^2$ Düzleminde İki Nokta Arasındaki Vektör ve Normu

- **Verilen (ekrandan, 00:15:30):** $\mathbb{R}^2$ düzleminde $P_0(1, -2)$ ve $P_1(-1, 3)$ noktaları veriliyor. $\vec{v} = \vec{P_0 P_1}$ vektörünü ve $|\vec{v}|$ uzunluğunu bulunuz.
- **Çözüm:**
  1. Bitiş noktası $P_1(-1, 3)$ koordinatlarından başlangıç noktası $P_0(1, -2)$ koordinatlarını çıkaralım:
     $$\vec{v} = \vec{P_0 P_1} = (x_1 - x_0, \, y_1 - y_0) = (-1 - 1, \, 3 - (-2)) = (-2, 5)$$
     Geometrik olarak bu vektör, koordinat düzleminde orijinden $(-2, 5)$ noktasına çizilen yönlü doğru parçasına karşılık gelir.
  2. Vektörün uzunluğu (normu):
     $$|\vec{v}| = \sqrt{(x_1 - x_0)^2 + (y_1 - y_0)^2} = \sqrt{(-2)^2 + 5^2} = \sqrt{4 + 25} = \sqrt{29}$$

### 1.3 Birim Vektör (Unit Vector) ve Bir Vektörü Birim Vektöre Dönüştürme

- **Tanım (Birim Vektör — ekrandan, 00:15:30):** Uzunluğu (büyüklüğü / normu) $1$'e eşit olan bir $\vec{u}$ vektörüne ($|\vec{u}| = 1$) **birim vektör** (unit vector) denir.
- **Birim Vektör Elde Etme (Normalizasyon):** Sıfırdan farklı herhangi bir $\vec{v} \neq \vec{0}$ vektörü verildiğinde, bu vektörü kendi uzunluğuna ($|\vec{v}|$ veya $\|\vec{v}\|$) bölerek $\vec{v}$ ile **aynı yönde olan bir birim vektör** elde edebiliriz:
  $$\vec{u} = \frac{\vec{v}}{|\vec{v}|} \implies |\vec{u}| = 1$$

## 2. Vektör Cebiri ve Analitik (Bileşen) Gösterim

### 2.1 Vektörlerde Toplama İşlemi ve Geometrik Yorumu (Üçgen ve Paralelkenar Kuralı)

$\vec{u} = (u_1, u_2, \dots, u_n) \in \mathbb{R}^n$ ve $\vec{v} = (v_1, v_2, \dots, v_n) \in \mathbb{R}^n$ olmak üzere her biri $n$ adet reel koordinata sahip iki vektör alalım. Matrisler konusunda $n \times 1$ boyutlu sütun matrislerine (veya $1 \times n$ satır matrislerine) vektör dediğimizi hatırlayalım; dolayısıyla vektörlerde toplama işlemi, aynı tipteki matrislerin toplanmasıyla birebir aynıdır:

- **Vektör Toplama Tanımı:** İki vektörü toplayabilmek için öncelikle koordinat sayılarının (boyutlarının) aynı olması gerekir. Toplam vektörü $\vec{u} + \vec{v}$, karşılıklı bileşenlerin (koordinatların) toplanmasıyla bulunur:
  $$\vec{u} + \vec{v} = (u_1 + v_1, \, u_2 + v_2, \, \dots, \, u_n + v_n)$$

#### Örnek: $\mathbb{R}^2$ Düzleminde Vektör Toplama

- **Verilen (ekrandan, 00:21:30):** $\vec{u} = (1, -2) \in \mathbb{R}^2$ ve $\vec{v} = (-1, 3) \in \mathbb{R}^2$ vektörlerinin toplamını bulunuz.
- **Çözüm:**
  $$\vec{u} + \vec{v} = (1 + (-1), \, -2 + 3) = (0, 1)$$

- **Geometrik Yorum (Uç Uca Ekleme ve Paralelkenar Kuralı — ekrandan, 00:21:30):**
  Düzlemde veya uzayda $\vec{u} + \vec{v}$ toplamını geometrik olarak göstermek için $\vec{v}$ vektörünü yönünü ve uzunluğunu değiştirmeden taşıyıp başlangıç noktasını $\vec{u}$ vektörünün bitiş noktasına (ucuna) ekleriz. Bu durumda $\vec{u}$'nun başlangıç noktasından, taşınan $\vec{v}$'nin bitiş noktasına çizilen vektör $\vec{u} + \vec{v}$ toplam vektörünü verir. Aynı işlem $\vec{u}$ ve $\vec{v}$ aynı başlangıç noktasından çizilip oluşturdukları paralelkenarın (parallelogram) ortak başlangıç noktasından çıkan köşegen vektörü çizilerek de gösterilir; iki geometrik gösterim birbiriyle tamamen aynıdır.

### 2.2 Bir Vektörün Skaler ile Çarpımı ve Vektörlerin Paralelliği

Bir vektörün bir skalerle çarpımı da matrislerin skalerle çarpımıyla aynı kurallara tabidir:

- **Tanım (Skalerle Çarpma):** $\vec{u} = (u_1, u_2, \dots, u_n) \in \mathbb{R}^n$ bir vektör ve $\lambda \in \mathbb{R}$ bir skaler (reel sayı) olsun. $\vec{u}$ vektörünün $\lambda$ ile skaler çarpımı, $\vec{u}$'nun her bir bileşeninin $\lambda$ ile çarpılmasıyla elde edilen vektördür:
  $$\lambda \vec{u} = (\lambda u_1, \, \lambda u_2, \, \dots, \, \lambda u_n)$$

> **Tarihsel Not (derste sözlü, 00:25:55–00:27:50):** Hoca sınav kapsamı dışında genel kültür olarak "skaler" (scalar) teriminin 19. yüzyılda İrlandalı matematikçi William Rowan Hamilton tarafından bir ölçek (scale) üzerindeki tek bir noktayla temsil edilebilen büyüklükleri ifade etmek için türetildiğini, "vektör" (vector) kelimesinin ise Latincede "taşıyıcı" (carrier) anlamına gelen kelimeden geldiğini paylaşmıştır.

- **Geometrik Etkisi (Uzama, Kısalma ve Yön Değiştirme — ekrandan, 00:34:30):**
  Bir $\vec{v}$ vektörünü $\lambda$ skaleriyle çarpmak geometrik olarak vektörü uzatmak (stretching), kısaltmak (shrinking) veya zıt yöne çevirmek (flipping) anlamına gelir:
  - $\lambda > 0$ ise $\lambda \vec{v}$ vektörü $\vec{v}$ ile **aynı yöndedir** (örneğin $2\vec{v}$ ve $3\vec{v}$ aynı yönde uzatılmış, $0.5\vec{v}$ ise aynı yönde yarıya kısaltılmış vektördür).
  - $\lambda < 0$ ise $\lambda \vec{v}$ vektörü $\vec{v}$ ile **zıt yöndedir** (örneğin $-\vec{v}$ aynı boyda fakat zıt yönde, $-2\vec{v}$ ise $2$ kat uzunlukta ve zıt yönde bir vektördür).

#### Örnek: Vektörün Negatif Bir Skalerle Çarpımı

- **Verilen (ekrandan, 00:34:30):** $\vec{v} = (1, 1) \in \mathbb{R}^2$ ve $\lambda = -2 \in \mathbb{R}$ için $\lambda \vec{v}$ vektörünü bulunuz.
- **Çözüm:**
  $$\lambda \vec{v} = -2\vec{v} = ((-2)\cdot 1, \, (-2)\cdot 1) = (-2, -2) = -2(1, 1)$$
  Koordinat düzleminde $\vec{v} = (1, 1)$ birinci bölgede orijinden $(1, 1)$'e uzanırken, $-2\vec{v} = (-2, -2)$ üçüncü bölgede tam zıt yönde ve $\vec{v}$'nin iki katı uzunluktadır.

- **Paralel Vektörler Tanımı (ekrandan, 00:34:30):**
  İki $\vec{u}$ ve $\vec{v}$ vektöründen biri diğerinin bir skaler katı ise ($\vec{u} = \lambda \vec{v}$ olacak biçimde bir $\lambda \in \mathbb{R}$ varsa), bu iki vektöre **paralel vektörler** (parallel vectors) denir ve $\vec{u} \parallel \vec{v}$ ile gösterilir.

### 2.3 Standart Baz Vektörleri ($\vec{i}, \vec{j}, \vec{k}$) ve Vektörlerin Analitik (Bileşen) Formu

İç çarpıma geçmeden önce hoca, sıklıkla kullanacağımız özel birim vektörleri ve vektörlerin analitik (bileşen) gösterimini tahtaya yazarak açıkladı (ekrandan, 00:42:30):

- **Standart Baz Vektörleri (Basis Vectors):**
  - $\mathbb{R}^3$ uzayında:
    $$\vec{i} = (1, 0, 0), \quad \vec{j} = (0, 1, 0), \quad \vec{k} = (0, 0, 1)$$
  - $\mathbb{R}^2$ düzleminde:
    $$\vec{i} = (1, 0), \quad \vec{j} = (0, 1)$$
  Bu özel vektörlerin üç temel özelliği vardır:
  1. Hepsi birer **birim vektördür**: $\|\vec{i}\| = \|\vec{j}\| = \|\vec{k}\| = 1$.
  2. Farklı koordinat eksenleri ($x, y, z$ eksenleri) üzerinde yer aldıklarından **ikişer ikişer birbirine diktirler** (mutually perpendicular).
  3. Uzaydaki veya düzlemdeki her vektör, bu baz vektörlerinin **tek bir skaler (doğrusal) birleşimi** (unique scalar combination) olarak yazılabilir:
     - $\mathbb{R}^2$'de herhangi bir $\vec{v} = (a, b)$ vektörü:
       $$\vec{v} = (a, b) = a(1, 0) + b(0, 1) = a\vec{i} + b\vec{j}$$
     - $\mathbb{R}^3$'te herhangi bir $\vec{v} = (a, b, c)$ vektörü:
       $$\vec{v} = (a, b, c) = a(1, 0, 0) + b(0, 1, 0) + c(0, 0, 1) = a\vec{i} + b\vec{j} + c\vec{k}$$

- **Analitik (Bileşen) Form (Analytic / Component Form):** Bir $\vec{v} = (a, b, c)$ vektörü $\vec{v} = a\vec{i} + b\vec{j} + c\vec{k}$ biçiminde yazıldığında, $\vec{v}$ vektörü **bileşen formunda** (in component form) veya **analitik formda** (in analytic form) yazılmış olur. Burada $a, b, c$ skalerlerine sırasıyla vektörün $\vec{i}, \vec{j}$ ve $\vec{k}$ bileşenleri denir.

## 3. İç Çarpım / Nokta Çarpım / Skaler Çarpım (Dot / Inner / Scalar Product)

### 3.1 İç Çarpımın Tanımı ve $\mathbb{R}^4$ Uzayında Sayısal Örnek

Matris çarpımını öğrenirken satır ile sütun matrislerinin çarpımından aslında iki vektörün iç çarpımını görmüştük. Şimdi bunu vektörler üzerinde resmen tanımlayalım (ekrandan, 00:45:00):

- **Tanım (İç Çarpım / Nokta Çarpım / Skaler Çarpım):** $\mathbb{R}^n$ uzayında $\vec{u} = (u_1, u_2, \dots, u_n)$ ve $\vec{v} = (v_1, v_2, \dots, v_n)$ vektörlerinin **nokta çarpımı** (dot product), **iç çarpımı** (inner product) veya **skaler çarpımı** (scalar product), $\vec{u} \cdot \vec{v}$ veya $\langle \vec{u}, \vec{v} \rangle$ ile gösterilir ve karşılıklı bileşenlerin çarpımlarının toplamı olarak tanımlanır:
  $$\vec{u} \cdot \vec{v} = u_1 v_1 + u_2 v_2 + \dots + u_n v_n = \sum_{i=1}^n u_i v_i$$

#### Örnek: $\mathbb{R}^4$ Uzayında İki Vektörün İç Çarpımı

- **Verilen (ekrandan, 00:45:00):** $\vec{u} = (2, 1, 0, 1) \in \mathbb{R}^4$ ve $\vec{v} = (-1, 1, 3, 2) \in \mathbb{R}^4$ vektörlerinin iç çarpımını ($\vec{u} \cdot \vec{v}$) bulunuz.
- **Çözüm:**
  $$\vec{u} \cdot \vec{v} = u_1 v_1 + u_2 v_2 + u_3 v_3 + u_4 v_4 = \sum_{i=1}^4 u_i v_i$$
  $$= 2(-1) + 1\cdot 1 + 0\cdot 3 + 1\cdot 2 = -2 + 1 + 0 + 2 = 1 \in \mathbb{R}$$

> **Hocanın vurgusu:** İki vektörün iç çarpımının (nokta çarpımının) sonucu bir vektör **değildir**; her zaman bir **reel sayıdır (skalerdir)**. Bu işleme "skaler çarpım" (scalar product) denmesinin nedeni de sonucun bir skaler çıkmasıdır.

### 3.2 İç Çarpımda Birleşme Özelliğinin Geçersizliği ve Üç Vektörün İç Çarpımı Sorusu

Hoca iç çarpımın sonucunun bir skaler olduğunu vurguladıktan sonra sınıfa şu önemli kavramsal soruyu yöneltti (derste sözlü ve ekrandan, 00:46:30–00:50:50):

**Soru:** Reel sayıların çarpımında ve vektörlerin toplamında geçerli olan birleşme özelliği (associative law), neden vektörlerin iç çarpımında (nokta çarpımında) geçerli değildir? Yani $\vec{u}, \vec{v}, \vec{w} \in \mathbb{R}^n$ gibi üç vektör verildiğinde $\vec{u} \cdot (\vec{v} \cdot \vec{w})$ gibi üç vektörün iç çarpımını tanımlayabilir miyiz?
**Cevap:** Hayır, tanımlayamayız. Çünkü parantez içindeki $\vec{v} \cdot \vec{w}$ iç çarpımının sonucu bir vektör değil, bir **skalerdir (reel sayıdır)**. Dışarıdaki $\vec{u}$ ise bir **vektördür**. İç çarpım yalnızca aynı boyutlu iki vektör arasında tanımlıdır; bir $\vec{u}$ vektörü ile bir $(\vec{v} \cdot \vec{w})$ reel sayısı arasında iç çarpım (dot product) yapılamaz. Bu nedenle üç vektörün iç çarpımı tanımsızdır ve iç çarpımda birleşme özelliğinden söz edilemez.

### 3.3 İç Çarpımın Özellikleri ve Diklik (Orthogonality) Koşulu

$\vec{u} = (u_1, u_2, \dots, u_n)$, $\vec{v} = (v_1, v_2, \dots, v_n)$, $\vec{w} = (w_1, w_2, \dots, w_n) \in \mathbb{R}^n$ vektörleri ve $\alpha, \beta \in \mathbb{R}$ skalerleri verildiğinde iç çarpım aşağıdaki 9 özelliği sağlar (ekrandan, 00:57:00):

1. **Değişme Özelliği (Commutative Law):** $\vec{u} \cdot \vec{v} = \vec{v} \cdot \vec{u}$
2. **Dağılma Özelliği (Distributive Law):** $\vec{u} \cdot (\vec{v} \mp \vec{w}) = \vec{u} \cdot \vec{v} \mp \vec{u} \cdot \vec{w}$
3. **Skalerle Çarpım Özelliği:** $\alpha(\vec{u} \cdot \vec{v}) = (\alpha \vec{u}) \cdot \vec{v} = \vec{u} \cdot (\alpha \vec{v})$
4. **Sıfır Vektörü ile İç Çarpım:** $\vec{0} \cdot \vec{u} = 0$ (Sıfır vektörünün başka bir vektörle iç çarpımı $0$ reel sayısını verir).
5. **Vektörün Kendisiyle İç Çarpımı (Normun Karesi — Önemli):**
   $$\vec{u} \cdot \vec{u} = u_1^2 + u_2^2 + \dots + u_n^2 = |\vec{u}|^2$$
   Bir vektörü kendisiyle iç çarpıma soktuğumuzda $u_1 u_1 + u_2 u_2 + \dots + u_n u_n = u_1^2 + u_2^2 + \dots + u_n^2$ elde edilir. $\vec{u}$'nun uzunluğu $|\vec{u}| = \sqrt{u_1^2 + u_2^2 + \dots + u_n^2}$ olduğundan, $\vec{u} \cdot \vec{u}$ doğrudan vektörün uzunluğunun karesine ($|\vec{u}|^2$) eşittir.
6. **Cauchy-Schwarz Eşitsizliği (Schwarz Inequality):** $|\vec{u} \cdot \vec{v}| \le |\vec{u}| |\vec{v}|$
7. **İç Çarpımın Geometrik (Açı) Formülü (Çok Önemli):**
   $$\vec{u} \cdot \vec{v} = |\vec{u}| |\vec{v}| \cos\theta$$
   Burada $\theta$, $\vec{u}$ ve $\vec{v}$ vektörleri arasındaki açıdır ($0 \le \theta \le \pi$).
8. **Diklik (Orthogonality / Perpendicularity) Koşulu (Çok Önemli):**
   $$\theta = \frac{\pi}{2} \implies \vec{u} \perp \vec{v} \iff \vec{u} \cdot \vec{v} = 0$$
   > **Hocanın vurgusu:** Sıfırdan farklı iki $\vec{u}$ ve $\vec{v}$ vektörünün birbirine **dik (perpendicular / orthogonal)** olması için gerek ve yeter şart iç çarpımlarının sıfır olmasıdır ($\vec{u} \cdot \vec{v} = 0$). Çünkü $\theta = \frac{\pi}{2}$ ($90^\circ$) olduğunda $\cos\frac{\pi}{2} = 0$ olur ve $|\vec{u}| |\vec{v}| \cos\frac{\pi}{2} = 0$ elde edilir.
9. **Paralellik ve Açı İlişkisi:** $\theta = 0$ (aynı yönlü) veya $\theta = \pi$ (zıt yönlü) $\iff \vec{u} \parallel \vec{v}$.

### 3.4 İki Vektör Arasındaki Açının Bulunması ve Sayısal Örnek

Özellik 7'deki $\vec{u} \cdot \vec{v} = |\vec{u}| |\vec{v}| \cos\theta$ formülünden sıfırdan farklı iki vektör arasındaki $\theta$ açısını çekersek:
$$\cos\theta = \frac{\vec{u} \cdot \vec{v}}{|\vec{u}| |\vec{v}|} \implies \theta = \arccos\left(\frac{\vec{u} \cdot \vec{v}}{|\vec{u}| |\vec{v}|}\right)$$
bağıntısı elde edilir.

#### Örnek: $\mathbb{R}^4$ Uzayında İki Vektör Arasındaki Açının Hesaplanması

- **Verilen (ekrandan, 01:02:30):** $\vec{u} = (2, 2, 0, 1) \in \mathbb{R}^4$ ve $\vec{v} = (-1, 1, 0, 2) \in \mathbb{R}^4$ vektörleri arasındaki $\theta$ açısını bulunuz.
- **Çözüm:**
  1. **İç Çarpım ($\vec{u} \cdot \vec{v}$):**
     $$\vec{u} \cdot \vec{v} = \sum_{i=1}^4 u_i v_i = 2(-1) + 2\cdot 1 + 0\cdot 0 + 1\cdot 2 = -2 + 2 + 0 + 2 = 2$$
  2. **Vektörlerin Uzunlukları ($|\vec{u}|$ ve $|\vec{v}|$):**
     $$|\vec{u}| = \sqrt{2^2 + 2^2 + 0^2 + 1^2} = \sqrt{4 + 4 + 0 + 1} = \sqrt{9} = 3$$
     $$|\vec{v}| = \sqrt{(-1)^2 + 1^2 + 0^2 + 2^2} = \sqrt{1 + 1 + 0 + 4} = \sqrt{6}$$
  3. **Açının Bulunması:**
     $$\vec{u} \cdot \vec{v} = |\vec{u}| |\vec{v}| \cos\theta \implies 2 = 3\sqrt{6}\cos\theta$$
     $$\cos\theta = \frac{2}{3\sqrt{6}} \implies \theta = \arccos\left(\frac{2}{3\sqrt{6}}\right)$$

## 4. Vektörel Çarpım / Dış Çarpım (Cross / Vector Product)

### 4.1 Vektörel Çarpımın Tanımı, Homojen Sistemden Çıkarılışı ve Geometrik Yorumu

Vektörler üzerindeki ikinci çok önemli çarpım işlemi **vektörel çarpım** (cross product veya vector product) işlemidir.

> **Hocanın vurgusu:** Vektörel çarpım ($\vec{u} \times \vec{v}$) **yalnızca $\mathbb{R}^3$ uzayındaki vektörler için tanımlıdır** ($\mathbb{R}^2$ veya $\mathbb{R}^4$'te tanımlı değildir). Ayrıca iç çarpımın sonucu bir skaler (reel sayı) iken, iki vektörün vektörel çarpımının sonucu yine $\mathbb{R}^3$ uzayında bir **vektördür**.

- **Homojen Doğrusal Denklem Sisteminden Çıkarılışı (ekrandan, 01:09:00):**
  $\mathbb{R}^3$ uzayında $\vec{u} = u_1\vec{i} + u_2\vec{j} + u_3\vec{k} = (u_1, u_2, u_3)$ ve $\vec{v} = v_1\vec{i} + v_2\vec{j} + v_3\vec{k} = (v_1, v_2, v_3)$ vektörleri verilsin. Hem $\vec{u}$'ya hem de $\vec{v}$'ye **dik (orthogonal / perpendicular)** olan bir $\vec{w} = (x, y, z) \in \mathbb{R}^3$ vektörü aradığımızı düşünelim:
  - $\vec{w} \perp \vec{u} \implies \vec{u} \cdot \vec{w} = 0 \implies u_1 x + u_2 y + u_3 z = 0$
  - $\vec{w} \perp \vec{v} \implies \vec{v} \cdot \vec{w} = 0 \implies v_1 x + v_2 y + v_3 z = 0$
  Bu iki denklem, $x, y, z$ bilinmeyenlerine bağlı bir homojen doğrusal denklem sistemi oluşturur. Bu homojen sistem çözüldüğünde elde edilen özel $\vec{w}$ çözüm vektörüne $\vec{u}$ ile $\vec{v}$'nin **vektörel çarpımı** (cross product) denir ve $\vec{u} \times \vec{v}$ veya bazı kaynaklarda $\vec{u} \wedge \vec{v}$ ile gösterilir:
  $$\vec{w} = \vec{u} \times \vec{v} = (u_2 v_3 - u_3 v_2)\vec{i} - (u_1 v_3 - u_3 v_1)\vec{j} + (u_1 v_2 - u_2 v_1)\vec{k}$$

- **Geometrik Yorum ve Paralelkenar Alanı (ekrandan, 01:13:00–01:13:50):**
  1. **Yönü:** $\vec{u} \times \vec{v}$ vektörü, hem $\vec{u}$ vektörüne hem de $\vec{v}$ vektörüne (dolayısıyla $\vec{u}$ ve $\vec{v}$'nin belirttiği düzleme) dik olan bir vektördür.
  2. **Büyüklüğü (Paralelkenar Alanı):** $\vec{u} \times \vec{v}$ vektörünün uzunluğu (normu) olan $|\vec{u} \times \vec{v}|$, komşu kenarları $\vec{u}$ ve $\vec{v}$ vektörleri olan **paralelkenarın alanına** (area of the parallelogram) eşittir:
     $$\text{Alan} = |\vec{u} \times \vec{v}| = |\vec{u}| |\vec{v}| \sin\theta$$

### 4.2 Determinant ve Laplace Açılımı Yardımıyla Vektörel Çarpım Hesabı

Yukarıdaki bileşen formülünü ezberlemek yerine, $\vec{u} = (u_1, u_2, u_3)$ ve $\vec{v} = (v_1, v_2, v_3)$ vektörlerinin vektörel çarpımı $3 \times 3$ boyutlu bir determinant yardımıyla çok kolay hesaplanır (ekrandan, 01:18:00):
- 1. satıra standart baz vektörleri $\vec{i}, \vec{j}, \vec{k}$ yazılır.
- 2. satıra birinci vektör $\vec{u}$'nun bileşenleri ($u_1, u_2, u_3$) yazılır.
- 3. satıra ikinci vektör $\vec{v}$'nin bileşenleri ($v_1, v_2, v_3$) yazılır.

Bu determinant **1. satıra göre Laplace açılımı** (Laplace expansion along the first row) ile açıldığında:
$$\vec{u} \times \vec{v} = \begin{vmatrix} \vec{i} & \vec{j} & \vec{k} \\ u_1 & u_2 & u_3 \\ v_1 & v_2 & v_3 \end{vmatrix} = \vec{i}\cdot(-1)^{1+1}\begin{vmatrix} u_2 & u_3 \\ v_2 & v_3 \end{vmatrix} + \vec{j}\cdot(-1)^{1+2}\begin{vmatrix} u_1 & u_3 \\ v_1 & v_3 \end{vmatrix} + \vec{k}\cdot(-1)^{1+3}\begin{vmatrix} u_1 & u_2 \\ v_1 & v_2 \end{vmatrix}$$
$$= (u_2 v_3 - u_3 v_2)\vec{i} - (u_1 v_3 - u_3 v_1)\vec{j} + (u_1 v_2 - u_2 v_1)\vec{k}$$
formülü doğrudan elde edilir. Ortadaki $\vec{j}$ bileşeninin önünde $(-1)^{1+2} = -1$'den dolayı **eksi ($-$) işareti** bulunduğuna dikkat edilmelidir.

### 4.3 Standart Baz Vektörlerinin Vektörel Çarpımı ($\vec{i}, \vec{j}, \vec{k}$ Çemberi)

#### Örnek: $\vec{i} \times \vec{j}$ Çarpımının Hesaplanması

- **Verilen (ekrandan, 01:21:30):** $\mathbb{R}^3$ uzayında $\vec{i} = (1, 0, 0)$ ve $\vec{j} = (0, 1, 0)$ baz vektörleri için $\vec{i} \times \vec{j}$ çarpımını bulunuz.
- **Çözüm:**
  $$\vec{i} \times \vec{j} = \begin{vmatrix} \vec{i} & \vec{j} & \vec{k} \\ 1 & 0 & 0 \\ 0 & 1 & 0 \end{vmatrix} = \vec{i}\begin{vmatrix} 0 & 0 \\ 1 & 0 \end{vmatrix} - \vec{j}\begin{vmatrix} 1 & 0 \\ 0 & 0 \end{vmatrix} + \vec{k}\begin{vmatrix} 1 & 0 \\ 0 & 1 \end{vmatrix} = 0\vec{i} - 0\vec{j} + 1\vec{k} = \vec{k}$$

- **Standart Baz Vektörleri Çemberi:**
  $\vec{i}, \vec{j}, \vec{k}$ vektörlerini bir çember üzerinde saat yönünde sıraladığımızda, seçilen yönde ardışık iki baz vektörünün vektörel çarpımı üçüncü baz vektörünü verir:
  $$\vec{i} \times \vec{j} = \vec{k}, \quad \vec{j} \times \vec{k} = \vec{i}, \quad \vec{k} \times \vec{i} = \vec{j}$$
  Ters yönde çarpıldığında ise işaret eksi olur ($\vec{j} \times \vec{i} = -\vec{k}, \quad \vec{k} \times \vec{j} = -\vec{i}, \quad \vec{i} \times \vec{k} = -\vec{j}$).
  Buna karşılık baz vektörleri birbirine dik olduklarından **iç çarpımları sıfırdır**:
  $$\vec{i} \cdot \vec{j} = 0, \quad \vec{j} \cdot \vec{k} = 0, \quad \vec{i} \cdot \vec{k} = 0$$

### 4.4 $\mathbb{R}^3$ Uzayında Vektörel Çarpım Örneği

- **Verilen (ekrandan, 01:24:00):** $\vec{u} = (1, 2, -1) \in \mathbb{R}^3$ ve $\vec{v} = (-2, 3, 4) \in \mathbb{R}^3$ vektörlerinin vektörel çarpımını ($\vec{u} \times \vec{v}$) bulunuz.
- **Çözüm (1. Yöntem — Determinant ve Laplace Açılımı):**
  $$\vec{u} \times \vec{v} = \begin{vmatrix} \vec{i} & \vec{j} & \vec{k} \\ 1 & 2 & -1 \\ -2 & 3 & 4 \end{vmatrix} = \begin{vmatrix} 2 & -1 \\ 3 & 4 \end{vmatrix}\vec{i} - \begin{vmatrix} 1 & -1 \\ -2 & 4 \end{vmatrix}\vec{j} + \begin{vmatrix} 1 & 2 \\ -2 & 3 \end{vmatrix}\vec{k}$$
  Alt determinantları hesaplayalım:
  - 1. bileşen ($\vec{i}$): $(2)(4) - (-1)(3) = 8 - (-3) = 11$
  - 2. bileşen ($\vec{j}$): $-\left[(1)(4) - (-1)(-2)\right] = -(4 - 2) = -2$
  - 3. bileşen ($\vec{k}$): $(1)(3) - (2)(-2) = 3 - (-4) = 7$
  Buradan:
  $$\vec{u} \times \vec{v} = 11\vec{i} - 2\vec{j} + 7\vec{k} = (11, -2, 7)$$
- **2. Yöntem Hakkında Not:** Slaytta ayrıca $\vec{u} \times \vec{v} = \left(\begin{vmatrix} 2 & -1 \\ 3 & 4 \end{vmatrix}, \begin{vmatrix} -1 & 1 \\ 4 & -2 \end{vmatrix}, \begin{vmatrix} 1 & 2 \\ -2 & 3 \end{vmatrix}\right)$ biçiminde ikinci bir yazım verilmiştir. Hoca bunun 1. yöntemle tamamen aynı olduğunu, yalnızca ortadaki $2 \times 2$ determinantın önündeki eksi işaretini kaldırmak için determinantın 1. ve 2. sütunlarının yer değiştirildiğini (determinantta iki sütun yer değiştirince işaret değiştiğini) açıklamıştır.

### 4.5 Vektörel Çarpımın Özellikleri ve Paralellik Koşulu

$\vec{u} = (u_1, u_2, u_3)$, $\vec{v} = (v_1, v_2, v_3)$, $\vec{w} = (w_1, w_2, w_3) \in \mathbb{R}^3$ ve $c \in \mathbb{R}$ için vektörel çarpımın temel özellikleri şunlardır (ekrandan, 01:28:30):

1. **Ters Değişme (Anti-Simetri) Özelliği (Çok Önemli):**
   $$\vec{u} \times \vec{v} = -(\vec{v} \times \vec{u})$$
   Vektörel çarpımda değişme özelliği yoktur! Çünkü $\vec{v} \times \vec{u}$ determinantında 2. ve 3. satırlar yer değiştirmiş olur; bir determinantta iki satır yer değiştirdiğinde determinantın işareti değişir.
2. **Skalerle Çarpım:** $(c\vec{u}) \times \vec{v} = c(\vec{u} \times \vec{v}) = \vec{u} \times (c\vec{v})$
3. **Soldan Dağılma:** $\vec{u} \times (\vec{v} \mp \vec{w}) = \vec{u} \times \vec{v} \mp \vec{u} \times \vec{w}$
4. **Sağdan Dağılma:** $(\vec{u} \mp \vec{v}) \times \vec{w} = \vec{u} \times \vec{w} \mp \vec{v} \times \vec{w}$
5. **Karma Çarpım Simetrisi:** $\vec{u} \cdot (\vec{v} \times \vec{w}) = (\vec{u} \times \vec{v}) \cdot \vec{w}$
6. **İkili Vektörel Çarpım:** $\vec{u} \times (\vec{v} \times \vec{w}) = (\vec{u} \cdot \vec{w})\vec{v} - (\vec{u} \cdot \vec{v})\vec{w}$
7. **Büyüklük ve Sinüs Formülü (Çok Önemli):**
   $$\vec{u} \times \vec{v} = \left(|\vec{u}| |\vec{v}| \sin\theta\right)\vec{n} \quad (\vec{u} \perp \vec{n}, \, \vec{v} \perp \vec{n}, \, |\vec{n}| = 1)$$
   Burada $\vec{n}$, hem $\vec{u}$'ya hem $\vec{v}$'ye dik olan birim vektördür ($|\vec{n}| = 1$). Her iki tarafın normu alındığında $|\vec{n}| = 1$ olduğundan:
   $$|\vec{u} \times \vec{v}| = |\vec{u}| |\vec{v}| \sin\theta$$
   elde edilir. Böylece iki vektör arasındaki açıyı bulmak için $\vec{u} \cdot \vec{v} = |\vec{u}| |\vec{v}| \cos\theta$ yanında bu bağıntı da kullanılabilir.
8. **Paralellik Koşulu (Çok Önemli):**
   $$\theta = 0 \text{ veya } \theta = \pi \implies \vec{u} \times \vec{v} = \vec{0} \implies \vec{u} \parallel \vec{v}$$
   > **Hocanın vurgusu:** Sıfırdan farklı iki vektörün iç çarpımı sıfırsa vektörler birbirine **diktir** ($\vec{u} \cdot \vec{v} = 0 \iff \vec{u} \perp \vec{v}$); vektörel çarpımı sıfır vektörü ise vektörler birbirine **paraleldir** ($\vec{u} \times \vec{v} = \vec{0} \iff \vec{u} \parallel \vec{v}$).
9. **Çarpanlara Diklik:** $\vec{u} \perp (\vec{u} \times \vec{v})$ ve $\vec{v} \perp (\vec{u} \times \vec{v})$ (Slaytta 9. maddede ikinci ifade sehven $\vec{u} \perp (\vec{u} \times \vec{v})$ olarak tekrar yazılmıştır; anlamı $\vec{u} \times \vec{v}$'nin hem $\vec{u}$'ya hem $\vec{v}$'ye dik olduğudur).

## 5. Karma Çarpım (Mixed / Scalar Triple Product) ve Paralelkenar Prizmanın Hacmi

### 5.1 Karma Çarpımın Determinant Formülü ve Geometrik Anlamı

$\mathbb{R}^3$ uzayında $\vec{u} = (u_1, u_2, u_3)$, $\vec{v} = (v_1, v_2, v_3)$ ve $\vec{w} = (w_1, w_2, w_3)$ gibi üç vektör verildiğinde, $\vec{u}$ vektörü ile $\vec{v} \times \vec{w}$ vektörünün iç çarpımına **karma çarpım** (mixed product) veya **skaler üçlü çarpım** (scalar triple product) denir.

$\vec{v} \times \vec{w}$ bir vektör olduğundan ve bu vektör $\vec{u}$ ile iç çarpıma sokulduğundan, karma çarpımın sonucu bir **skalerdir (reel sayıdır)** ve bileşenlerin satırlara yazıldığı $3 \times 3$ determinant ile hesaplanır:
$$\vec{u} \cdot (\vec{v} \times \vec{w}) = \begin{vmatrix} u_1 & u_2 & u_3 \\ v_1 & v_2 & v_3 \\ w_1 & w_2 & w_3 \end{vmatrix}$$

- **Geometrik Anlamı (Paralelkenar Prizmanın Hacmi — ekrandan, 01:31:25–01:35:30):**
  Geometrik olarak karma çarpımın mutlak değeri, komşu ayrıtları (adjacent sides) $\vec{u}, \vec{v}$ ve $\vec{w}$ vektörleri olan **paralelkenar prizmanın (parallelepiped) hacmini** verir:
  $$\text{Hacim } (V) = \left|\vec{u} \cdot (\vec{v} \times \vec{w})\right|$$
  Determinant hesaplandığında sonuç negatif çıkarsa, hacim negatif olamayacağı için sonucun **mutlak değeri** (absolute value) alınır. Ayrıca $(\vec{u} \times \vec{v}) \cdot \vec{w} = \vec{u} \cdot (\vec{v} \times \vec{w})$ eşitliği geçerlidir; satırların sırası değiştiğinde determinant en fazla işaret değiştirir, mutlak değeri (yani prizmanın hacmi) değişmez.

### 5.2 Karma Çarpım ve Paralelkenar Prizma Hacmi Örneği

- **Verilen (ekrandan, 01:35:30):** $\vec{u} = (1, 2, -1)$, $\vec{v} = (-2, 3, 4)$ ve $\vec{w} = (2, 1, 0) \in \mathbb{R}^3$ vektörlerinin $\vec{u} \cdot (\vec{v} \times \vec{w})$ karma çarpımını ve bu üç vektörün belirttiği paralelkenar prizmanın hacmini bulunuz.
- **Çözüm:**
  1. Sırasıyla $\vec{u}, \vec{v}, \vec{w}$ vektörlerini satırlara yazarak determinantı kuralım:
     $$\vec{u} \cdot (\vec{v} \times \vec{w}) = \begin{vmatrix} 1 & 2 & -1 \\ -2 & 3 & 4 \\ 2 & 1 & 0 \end{vmatrix}$$
  2. 1. satıra göre Laplace açılımı yapalım:
     $$\vec{u} \cdot (\vec{v} \times \vec{w}) = 1\begin{vmatrix} 3 & 4 \\ 1 & 0 \end{vmatrix} - 2\begin{vmatrix} -2 & 4 \\ 2 & 0 \end{vmatrix} - 1\begin{vmatrix} -2 & 3 \\ 2 & 1 \end{vmatrix}$$
     $$= 1(0 - 4) - 2(0 - 8) - 1(-2 - 6) = -4 + 16 + 8 = 20$$
  3. Sonuç pozitif ($20$) olduğundan komşu ayrıtları $\vec{u}, \vec{v}, \vec{w}$ olan paralelkenar prizmanın hacmi $V = 20$ birimküptür. (Eğer vektörlerin sırası değiştirilip determinant $-20$ bulunsaydı da mutlak değeri alınarak hacim yine $|-20| = 20$ olarak bulunurdu).

## 6. İkili Vektörel Çarpım (Two-Fold Cross Product / Vector Triple Product)

### 6.1 İkili Vektörel Çarpım Özdeşliği

Dersin son konusu olarak $\mathbb{R}^3$ uzayındaki üç vektörün art arda vektörel çarpımı olan **ikili vektörel çarpım** (two-fold cross product / vector triple product) tanımlanmıştır (ekrandan, 01:36:35–01:39:15):

- **Tanım:** $\vec{u}, \vec{v}, \vec{w} \in \mathbb{R}^3$ vektörleri için $\vec{u} \times (\vec{v} \times \vec{w})$ çarpımı şu özdeşlikle tanımlanır ve hesaplanır:
  $$\vec{u} \times (\vec{v} \times \vec{w}) = (\vec{u} \cdot \vec{w})\vec{v} - (\vec{u} \cdot \vec{v})\vec{w}$$
  Burada $(\vec{u} \cdot \vec{w})$ ve $(\vec{u} \cdot \vec{v})$ birer skaler (reel sayı) olduğundan, sağ taraf $\vec{v}$ ve $\vec{w}$ vektörlerinin bir doğrusal birleşimidir; dolayısıyla ikili vektörel çarpımın sonucu $\mathbb{R}^3$ uzayında bir **vektördür**.

### 6.2 İkili Vektörel Çarpım Sayısal Örneği

- **Verilen (ekrandan, 01:39:15):** $\vec{u} = (1, 2, -1)$, $\vec{v} = (-2, 3, 4)$ ve $\vec{w} = (2, 1, 0) \in \mathbb{R}^3$ vektörleri için $\vec{u} \times (\vec{v} \times \vec{w})$ çarpımını bulunuz.
- **Çözüm:**
  İkili vektörel çarpım formülünü yazalım:
  $$\vec{u} \times (\vec{v} \times \vec{w}) = (\vec{u} \cdot \vec{w})\vec{v} - (\vec{u} \cdot \vec{v})\vec{w}$$
  1. **$\vec{u} \cdot \vec{w}$ iç çarpımının hesabı:**
     $$\vec{u} \cdot \vec{w} = 1\cdot 2 + 2\cdot 1 + (-1)\cdot 0 = 2 + 2 + 0 = 4$$
  2. **$\vec{u} \cdot \vec{v}$ iç çarpımının hesabı:**
     $$\vec{u} \cdot \vec{v} = 1(-2) + 2\cdot 3 + (-1)\cdot 4 = -2 + 6 - 4 = 0$$
  3. **Formülde yerine koyma:**
     $$\vec{u} \times (\vec{v} \times \vec{w}) = 4\vec{v} - 0\vec{w} = 4(-2, 3, 4) = (-8, 12, 16) \in \mathbb{R}^3$$

## Örnek Sorular

1. **Üç Vektörün İç Çarpımının Tanımlanabilirliği** (derste sözlü ve ekrandan, 00:48:15–00:50:50)
   - **Soru:** $\vec{u}, \vec{v}, \vec{w} \in \mathbb{R}^n$ olmak üzere üç vektörün $\vec{u} \cdot (\vec{v} \cdot \vec{w})$ biçiminde iç çarpımı (dot product) tanımlanabilir mi? Neden?
   - **Çözüm (derste verildi):** Tanımlanamaz. Çünkü iki vektörün iç çarpımı olan $\vec{v} \cdot \vec{w}$ bir vektör değil, bir **reel sayıdır (skalerdir)**; $\vec{u}$ ise bir **vektördür**. İç çarpım işlemi yalnızca iki vektör arasında tanımlıdır, bir vektör ile bir reel sayı arasında iç çarpım yapılamaz. Bu yüzden iç çarpımda birleşme özelliği (associative law) geçerli değildir.

2. **$\mathbb{R}^4$ Uzayında İki Vektör Arasındaki Açının Bulunması** (ekrandan, 01:02:30)
   - **Soru:** $\vec{u} = (2, 2, 0, 1) \in \mathbb{R}^4$ ve $\vec{v} = (-1, 1, 0, 2) \in \mathbb{R}^4$ vektörleri arasındaki açıyı bulunuz.
   - **Çözüm (derste verildi):**
     $$\vec{u} \cdot \vec{v} = 2(-1) + 2(1) + 0(0) + 1(2) = 2$$
     $$|\vec{u}| = \sqrt{2^2 + 2^2 + 0^2 + 1^2} = 3, \quad |\vec{v}| = \sqrt{(-1)^2 + 1^2 + 0^2 + 2^2} = \sqrt{6}$$
     $$\vec{u} \cdot \vec{v} = |\vec{u}| |\vec{v}| \cos\theta \implies 2 = 3\sqrt{6}\cos\theta \implies \theta = \arccos\left(\frac{2}{3\sqrt{6}}\right)$$

3. **Vektörel Çarpım, Karma Çarpım ve İkili Vektörel Çarpım Hesabı** (ekrandan, 01:24:00, 01:35:30 ve 01:39:15)
   - **Soru:** $\mathbb{R}^3$ uzayında $\vec{u} = (1, 2, -1)$, $\vec{v} = (-2, 3, 4)$ ve $\vec{w} = (2, 1, 0)$ vektörleri için:
     a) $\vec{u} \times \vec{v}$ vektörel çarpımını,
     b) $\vec{u} \cdot (\vec{v} \times \vec{w})$ karma çarpımını ve bu üç vektörün oluşturduğu paralelkenar prizmanın hacmini,
     c) $\vec{u} \times (\vec{v} \times \vec{w})$ ikili vektörel çarpımını bulunuz.
   - **Çözüm (derste verildi):**
     - **a)** $\vec{u} \times \vec{v} = \begin{vmatrix} \vec{i} & \vec{j} & \vec{k} \\ 1 & 2 & -1 \\ -2 & 3 & 4 \end{vmatrix} = (8 - (-3))\vec{i} - (4 - 2)\vec{j} + (3 - (-4))\vec{k} = 11\vec{i} - 2\vec{j} + 7\vec{k} = (11, -2, 7)$.
     - **b)** $\vec{u} \cdot (\vec{v} \times \vec{w}) = \begin{vmatrix} 1 & 2 & -1 \\ -2 & 3 & 4 \\ 2 & 1 & 0 \end{vmatrix} = 1(-4) - 2(-8) - 1(-8) = -4 + 16 + 8 = 20$. Paralelkenar prizmanın hacmi $V = |20| = 20$'dir.
     - **c)** $\vec{u} \times (\vec{v} \times \vec{w}) = (\vec{u} \cdot \vec{w})\vec{v} - (\vec{u} \cdot \vec{v})\vec{w}$. Burada $\vec{u} \cdot \vec{w} = 4$ ve $\vec{u} \cdot \vec{v} = 0$ olduğundan $4\vec{v} - 0\vec{w} = (-8, 12, 16)$ bulunur.

## Dersin Toparlaması

Bu derste skaler ve vektör kavramlarından başlayarak $\mathbb{R}^2$, $\mathbb{R}^3$ ve genel olarak $\mathbb{R}^n$ uzaylarında bir vektörün koordinat gösterimi, uzunluğu (normu), birim vektör elde edilmesi, vektör toplama, skalerle çarpma, vektörlerin paralelliği ve standart baz vektörleri ($\vec{i}, \vec{j}, \vec{k}$) cinsinden analitik (bileşen) formu işlenmiştir. Ardından $\mathbb{R}^n$ uzayında tanımlı olan ve sonucu bir skaler veren iç çarpım (dot / inner product) ile iki vektör arasındaki açının ve diklik koşulunun ($\vec{u} \cdot \vec{v} = 0$) bulunması ele alınmıştır. İkinci bölümde yalnızca $\mathbb{R}^3$ uzayında tanımlı olan ve sonucu hem $\vec{u}$'ya hem $\vec{v}$'ye dik bir vektör veren vektörel çarpım ($\vec{u} \times \vec{v}$), $3 \times 3$ determinant açılımıyla hesaplanması, paralelkenar alanıyla ilişkisi ve paralellik koşulu ($\vec{u} \times \vec{v} = \vec{0}$) incelenmiştir. Son olarak üç vektörün oluşturduğu paralelkenar prizmanın hacmini veren karma çarpım ($\vec{u} \cdot (\vec{v} \times \vec{w})$) ile sonucu bir vektör olan ikili vektörel çarpım ($\vec{u} \times (\vec{v} \times \vec{w})$) formülleri ve uygulamaları tamamlanmıştır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
