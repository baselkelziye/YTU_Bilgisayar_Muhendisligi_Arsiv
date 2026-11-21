# Ders 10 Çalışma Özeti

## Genel Konular

- Vektör Kavramı, Norm (Uzunluk) ve Birim Vektör (Vectors, Norm/Length of a Vector, and Unit Vector)
  - Sıcaklık (temperature) veya sürat (speed) gibi yalnızca büyüklüğe (magnitude) sahip fiziksel nicelikler reel sayılarla temsil edilir ve bunlara **skaler** (scalar) denir. Kuvvet (force) ve hız (velocity) gibi hem büyüklüğe hem de yöne (direction) sahip nicelikler ise başlangıç noktasından çizilen yönlü doğru parçalarıyla temsil edilir ve **vektör** (vector) olarak adlandırılır (ekrandan, 00:08:30).
  - Sıfırdan farklı bir $\vec{AB}$ vektörü, farklı iki nokta olan $A$ başlangıç noktasından (initial / start point) $B$ bitiş noktasına (terminal / end point) çizilen yönlü doğru parçasıdır (directed line segment). Uzunluğu (magnitude / length / norm) $\|\vec{AB}\|$ veya $|\vec{AB}|$ ile gösterilir. Yönü belirsiz, uzunluğu $0$ olan tek bir noktadan ibaret vektöre **sıfır vektörü** (zero vector, $\vec{0}$) denir.
  - $\mathbb{R}^3$ uzayında $P_0(x_0, y_0, z_0)$ başlangıç ve $P_1(x_1, y_1, z_1)$ bitiş noktaları arasındaki vektör ve uzunluğu (normu):
    $$\vec{v} = \vec{P_0 P_1} = (x_1 - x_0, \, y_1 - y_0, \, z_1 - z_0), \quad |\vec{v}| = \sqrt{(x_1 - x_0)^2 + (y_1 - y_0)^2 + (z_1 - z_0)^2}$$
    Benzer şekilde $\mathbb{R}^2$ düzleminde $\vec{v} = \vec{P_0 P_1} = (x_1 - x_0, \, y_1 - y_0)$ ve $|\vec{v}| = \sqrt{(x_1 - x_0)^2 + (y_1 - y_0)^2}$ olarak tanımlanır (ekrandan, 00:15:30).
  - Uzunluğu (normu) $1$ olan vektöre ($|\vec{u}| = 1$) **birim vektör** (unit vector) denir. Sıfırdan farklı herhangi bir $\vec{v} \neq \vec{0}$ vektörü kendi uzunluğuna bölünerek $\vec{v}$ ile aynı yönde olan $\frac{\vec{v}}{|\vec{v}|}$ birim vektörü elde edilir.
- Vektör Cebiri: Vektör Toplama, Skalerle Çarpma ve Analitik (Bileşen) Formu (Vector Algebra & Analytic/Component Form)
  - **Vektör Toplama (Vector Addition):** $\mathbb{R}^n$ uzayındaki $\vec{u} = (u_1, u_2, \dots, u_n)$ ve $\vec{v} = (v_1, v_2, \dots, v_n)$ vektörlerinin toplamı, karşılıklı bileşenlerin toplanmasıyla bulunur: $\vec{u} + \vec{v} = (u_1 + v_1, \, u_2 + v_2, \, \dots, \, u_n + v_n)$ (ekrandan, 00:21:30). Geometrik olarak $\vec{u}$'nun bitiş noktasına $\vec{v}$'nin başlangıç noktası eklenerek (uç uca ekleme veya paralelkenar kuralı) $\vec{u} + \vec{v}$ elde edilir.
  - **Skalerle Çarpma (Scalar Multiplication):** $\vec{u} \in \mathbb{R}^n$ ve $\lambda \in \mathbb{R}$ için $\lambda \vec{u} = (\lambda u_1, \, \lambda u_2, \, \dots, \, \lambda u_n)$. $\lambda > 0$ ise $\lambda \vec{u}$ vektörü $\vec{u}$ ile aynı yönde, $\lambda < 0$ ise zıt yöndedir. İki vektör biri diğerinin skaler katı ise ($\vec{u} = \lambda \vec{v}$) birbirine **paraleldir** ($\vec{u} \parallel \vec{v}$) (ekrandan, 00:34:30).
  - **Standart Baz Vektörleri ve Bileşen Formu (Basis Vectors & Component Form):** Birbirine dik (mutually perpendicular) birim vektörler olan standart baz vektörleri $\mathbb{R}^2$'de $\vec{i} = (1, 0), \, \vec{j} = (0, 1)$ ve $\mathbb{R}^3$'te $\vec{i} = (1, 0, 0), \, \vec{j} = (0, 1, 0), \, \vec{k} = (0, 0, 1)$ olarak tanımlanır ($|\vec{i}| = |\vec{j}| = |\vec{k}| = 1$). Her $\vec{v} = (a, b, c) \in \mathbb{R}^3$ vektörü bu baz vektörlerinin tek bir doğrusal (skaler) birleşimi olarak $\vec{v} = a\vec{i} + b\vec{j} + c\vec{k}$ analitik (bileşen) formunda yazılabilir (ekrandan, 00:42:30).
- İç Çarpım / Nokta Çarpım / Skaler Çarpım ve İki Vektör Arasındaki Açı (Dot / Inner / Scalar Product)
  - $\vec{u} = (u_1, u_2, \dots, u_n) \in \mathbb{R}^n$ ve $\vec{v} = (v_1, v_2, \dots, v_n) \in \mathbb{R}^n$ vektörlerinin iç çarpımı ($\vec{u} \cdot \vec{v}$ veya $\langle \vec{u}, \vec{v} \rangle$), karşılıklı bileşenlerin çarpımlarının toplamıdır ve sonucu bir vektör değil **skalerdir** (reel sayıdır) (ekrandan, 00:45:00):
    $$\vec{u} \cdot \vec{v} = u_1 v_1 + u_2 v_2 + \dots + u_n v_n = \sum_{i=1}^n u_i v_i \in \mathbb{R}$$
  - Geometrik bağıntı ve iki vektör arasındaki $\theta$ açısı (ekrandan, 00:57:00 ve 01:02:30):
    $$\vec{u} \cdot \vec{v} = |\vec{u}| |\vec{v}| \cos\theta \implies \cos\theta = \frac{\vec{u} \cdot \vec{v}}{|\vec{u}| |\vec{v}|} \implies \theta = \arccos\left(\frac{\vec{u} \cdot \vec{v}}{|\vec{u}| |\vec{v}|}\right)$$
  - Sıfırdan farklı iki vektörün birbirine **dik (orthogonal / perpendicular)** olması için gerek ve yeter şart iç çarpımlarının sıfır olmasıdır: $\vec{u} \perp \vec{v} \iff \vec{u} \cdot \vec{v} = 0$ ($\theta = \frac{\pi}{2}$).
- Vektörel Çarpım / Dış Çarpım, Karma Çarpım ve İkili Vektörel Çarpım (Cross Product, Mixed Product, and Two-Fold Cross Product)
  - **Vektörel Çarpım (Cross / Vector Product):** Yalnızca $\mathbb{R}^3$ uzayındaki vektörler için tanımlıdır. $\vec{u} = (u_1, u_2, u_3)$ ve $\vec{v} = (v_1, v_2, v_3)$ vektörlerinin vektörel çarpımı ($\vec{u} \times \vec{v}$ veya $\vec{u} \wedge \vec{v}$), hem $\vec{u}$'ya hem de $\vec{v}$'ye dik olan üçüncü bir vektördür ve 1. satıra göre Laplace açılımıyla şu sembolik determinanttan hesaplanır (ekrandan, 01:18:00):
    $$\vec{u} \times \vec{v} = \begin{vmatrix} \vec{i} & \vec{j} & \vec{k} \\ u_1 & u_2 & u_3 \\ v_1 & v_2 & v_3 \end{vmatrix} = (u_2 v_3 - u_3 v_2)\vec{i} - (u_1 v_3 - u_3 v_1)\vec{j} + (u_1 v_2 - u_2 v_1)\vec{k}$$
    Uzunluğu $|\vec{u} \times \vec{v}| = |\vec{u}| |\vec{v}| \sin\theta$ olup komşu kenarları $\vec{u}$ ve $\vec{v}$ olan paralelkenarın alanına (area of parallelogram) eşittir. $\vec{u} \times \vec{v} = \vec{0} \iff \vec{u} \parallel \vec{v}$ (ekrandan, 01:28:30).
  - **Karma Çarpım (Mixed / Scalar Triple Product):** $\vec{u}, \vec{v}, \vec{w} \in \mathbb{R}^3$ için $\vec{u} \cdot (\vec{v} \times \vec{w})$ çarpımı, satırlarına sırasıyla $\vec{u}, \vec{v}, \vec{w}$ bileşenlerinin yazıldığı $3 \times 3$ determinantın değerine eşittir. Mutlak değeri $|\vec{u} \cdot (\vec{v} \times \vec{w})|$, komşu ayrıtları $\vec{u}, \vec{v}, \vec{w}$ olan paralelkenar prizmanın (parallelepiped) hacmini verir.
  - **İkili Vektörel Çarpım (Two-Fold Cross Product / Vector Triple Product):** $\vec{u}, \vec{v}, \vec{w} \in \mathbb{R}^3$ için $\vec{u} \times (\vec{v} \times \vec{w}) = (\vec{u} \cdot \vec{w})\vec{v} - (\vec{u} \cdot \vec{v})\vec{w}$ özdeşliğiyle hesaplanır ve sonucu $\mathbb{R}^3$'te bir vektördür (ekrandan, 01:39:15).

## Hocanın Özellikle Vurguladığı Kısımlar

- İç Çarpımın Sonucunun Skaler Olması ve Üç Vektörün İç Çarpımının Tanımsızlığı
  - İki vektörün iç çarpımı ($\vec{u} \cdot \vec{v}$) bir vektör değil, bir **reel sayıdır (skalerdir)**. Bu nedenle reel sayılarda ve vektör toplamada geçerli olan birleşme özelliği (associative law) iç çarpımda geçerli değildir; üç vektörün iç çarpımı $(\vec{u} \cdot \vec{v}) \cdot \vec{w}$ veya $\vec{u} \cdot (\vec{v} \cdot \vec{w})$ **tanımlanamaz**. Çünkü $\vec{v} \cdot \vec{w}$ bir reel sayıdır, $\vec{u}$ ise bir vektördür; bir vektör ile bir reel sayı arasında iç çarpım yapılamaz (derste sözlü ve ekrandan, 00:48:15–00:50:50).
- Vektörel Çarpımın Yalnızca $\mathbb{R}^3$'te Tanımlı Olması ve Sonucunun Vektör Olması
  - İç çarpım $\mathbb{R}^n$ uzayındaki aynı boyutlu her vektör çifti için tanımlı ve sonucu bir skaler iken, vektörel çarpım ($\vec{u} \times \vec{v}$) **yalnızca $\mathbb{R}^3$ uzayındaki** vektörler için tanımlıdır ve sonucu yine $\mathbb{R}^3$'te hem $\vec{u}$'ya hem de $\vec{v}$'ye dik olan bir **vektördür** (ekrandan, 01:04:15 ve 01:11:20).
- Vektörel Çarpımın Değişme Özelliğinin Olmaması (Anti-Simetri)
  - İç çarpımda $\vec{u} \cdot \vec{v} = \vec{v} \cdot \vec{u}$ değişme özelliği varken, vektörel çarpımda $\vec{u} \times \vec{v}$ ile $\vec{v} \times \vec{u}$ determinantta iki satırın yer değiştirmesine karşılık geldiğinden işaret değiştirir: $\vec{u} \times \vec{v} = -(\vec{v} \times \vec{u})$ (ekrandan, 01:26:00).
- Diklik ve Paralellik Koşullarının Karşılaştırılması
  - Sıfırdan farklı iki vektör için: $\vec{u} \cdot \vec{v} = 0 \iff \vec{u} \perp \vec{v}$ (diklik koşulu, $\cos 90^\circ = 0$), buna karşılık $\vec{u} \times \vec{v} = \vec{0} \iff \vec{u} \parallel \vec{v}$ (paralellik koşulu, $\sin 0^\circ = \sin 180^\circ = 0$) (ekrandan, 01:28:30).

## Kısa Tekrar Notları

- Vektör ve norm: $\vec{v} = \vec{P_0 P_1} = P_1 - P_0$, $|\vec{v}| = \sqrt{v_1^2 + v_2^2 + \dots + v_n^2}$.
- Birim vektör: $|\vec{u}| = 1$. Sıfırdan farklı $\vec{v}$ yönündeki birim vektör: $\vec{u} = \frac{\vec{v}}{|\vec{v}|}$.
- Paralellik: $\vec{u} \parallel \vec{v} \iff \vec{u} = \lambda \vec{v}$ ($\lambda \in \mathbb{R}$) $\iff \vec{u} \times \vec{v} = \vec{0}$ ($\mathbb{R}^3$'te).
- İç çarpım özellikleri (ekrandan, 00:57:00):
  1. $\vec{u} \cdot \vec{v} = \vec{v} \cdot \vec{u}$ (değişme / commutative law)
  2. $\vec{u} \cdot (\vec{v} \mp \vec{w}) = \vec{u} \cdot \vec{v} \mp \vec{u} \cdot \vec{w}$ (dağılma / distributive law)
  3. $\alpha(\vec{u} \cdot \vec{v}) = (\alpha \vec{u}) \cdot \vec{v} = \vec{u} \cdot (\alpha \vec{v})$
  4. $\vec{0} \cdot \vec{u} = 0$
  5. $\vec{u} \cdot \vec{u} = u_1^2 + u_2^2 + \dots + u_n^2 = |\vec{u}|^2$
  6. $|\vec{u} \cdot \vec{v}| \le |\vec{u}| |\vec{v}|$ (Cauchy-Schwarz eşitsizliği)
  7. $\vec{u} \cdot \vec{v} = |\vec{u}| |\vec{v}| \cos\theta$
  8. $\theta = \frac{\pi}{2} \implies \vec{u} \perp \vec{v} \iff \vec{u} \cdot \vec{v} = 0$
- Standart baz vektörlerinin çarpımları ($\mathbb{R}^3$):
  - İç çarpımlar: $\vec{i} \cdot \vec{j} = \vec{j} \cdot \vec{k} = \vec{i} \cdot \vec{k} = 0$ ve $\vec{i} \cdot \vec{i} = \vec{j} \cdot \vec{j} = \vec{k} \cdot \vec{k} = 1$.
  - Vektörel çarpımlar (çember kuralı): $\vec{i} \times \vec{j} = \vec{k}, \quad \vec{j} \times \vec{k} = \vec{i}, \quad \vec{k} \times \vec{i} = \vec{j}$ (ters yönde eksi işaret alır).
- Vektörel çarpım özellikleri (ekrandan, 01:28:30):
  - $\vec{u} \times \vec{v} = -(\vec{v} \times \vec{u})$
  - $\vec{u} \times \vec{v} = (|\vec{u}| |\vec{v}| \sin\theta)\vec{n}$ ($\vec{n}$: hem $\vec{u}$'ya hem $\vec{v}$'ye dik birim vektör) $\implies |\vec{u} \times \vec{v}| = |\vec{u}| |\vec{v}| \sin\theta$ (paralelkenar alanı).
  - $\vec{u} \perp (\vec{u} \times \vec{v})$ ve $\vec{v} \perp (\vec{u} \times \vec{v})$.
- Karma çarpım ve prizma hacmi: $V = |\vec{u} \cdot (\vec{v} \times \vec{w})| = |(\vec{u} \times \vec{v}) \cdot \vec{w}|$.
- İkili vektörel çarpım: $\vec{u} \times (\vec{v} \times \vec{w}) = (\vec{u} \cdot \vec{w})\vec{v} - (\vec{u} \cdot \vec{v})\vec{w}$.

## Detaylı Açıklamalar

- **İki Nokta Arasındaki Vektör, Norm, Toplama ve Skalerle Çarpma Örnekleri (ekrandan, 00:15:30, 00:21:30 ve 00:34:30):**
  1. **Vektör ve Uzunluk ($\mathbb{R}^2$):** $P_0(1, -2)$ ve $P_1(-1, 3)$ noktaları için $\vec{v} = \vec{P_0 P_1}$ vektörü ve normu:
     $$\vec{v} = \vec{P_0 P_1} = (x_1 - x_0, \, y_1 - y_0) = (-1 - 1, \, 3 - (-2)) = (-2, 5)$$
     $$|\vec{v}| = \sqrt{(-2)^2 + 5^2} = \sqrt{4 + 25} = \sqrt{29}$$
  2. **Vektör Toplama ($\mathbb{R}^2$):** $\vec{u} = (1, -2)$ ve $\vec{v} = (-1, 3)$ vektörlerinin toplamı:
     $$\vec{u} + \vec{v} = (1 + (-1), \, -2 + 3) = (0, 1)$$
  3. **Skalerle Çarpma ($\mathbb{R}^2$):** $\vec{v} = (1, 1)$ ve $\lambda = -2 \in \mathbb{R}$ için:
     $$\lambda \vec{v} = -2\vec{v} = ((-2)\cdot 1, \, (-2)\cdot 1) = (-2, -2)$$
     Burada $-2\vec{v}$ vektörü, $\vec{v}$ vektörünün boyunun $2$ katına çıkarılıp yönünün tam tersine ($180^\circ$) çevrilmiş halidir.

- **$\mathbb{R}^4$ Uzayında İç Çarpım ve İki Vektör Arasındaki Açının Bulunması (ekrandan, 00:45:00 ve 01:02:30):**
  1. **İç Çarpım Örneği:** $\vec{u} = (2, 1, 0, 1) \in \mathbb{R}^4$ ve $\vec{v} = (-1, 1, 3, 2) \in \mathbb{R}^4$ için:
     $$\vec{u} \cdot \vec{v} = 2(-1) + 1(1) + 0(3) + 1(2) = -2 + 1 + 0 + 2 = 1$$
  2. **İki Vektör Arasındaki Açı Örneği:** $\vec{u} = (2, 2, 0, 1) \in \mathbb{R}^4$ ve $\vec{v} = (-1, 1, 0, 2) \in \mathbb{R}^4$ vektörleri arasındaki $\theta$ açısını bulmak için önce iç çarpım ve normlar hesaplanır:
     $$\vec{u} \cdot \vec{v} = 2(-1) + 2(1) + 0(0) + 1(2) = -2 + 2 + 0 + 2 = 2$$
     $$|\vec{u}| = \sqrt{2^2 + 2^2 + 0^2 + 1^2} = \sqrt{4 + 4 + 0 + 1} = \sqrt{9} = 3$$
     $$|\vec{v}| = \sqrt{(-1)^2 + 1^2 + 0^2 + 2^2} = \sqrt{1 + 1 + 0 + 4} = \sqrt{6}$$
     $\vec{u} \cdot \vec{v} = |\vec{u}| |\vec{v}| \cos\theta$ bağıntısından:
     $$2 = 3\sqrt{6}\cos\theta \implies \cos\theta = \frac{2}{3\sqrt{6}} \implies \theta = \arccos\left(\frac{2}{3\sqrt{6}}\right)$$

- **Vektörel Çarpım, Karma Çarpım ve İkili Vektörel Çarpım Örnekleri (ekrandan, 01:24:00, 01:35:30 ve 01:39:15):**
  $\mathbb{R}^3$ uzayında $\vec{u} = (1, 2, -1)$, $\vec{v} = (-2, 3, 4)$ ve $\vec{w} = (2, 1, 0)$ vektörleri verilsin:
  1. **Vektörel Çarpım ($\vec{u} \times \vec{v}$):**
     $$\vec{u} \times \vec{v} = \begin{vmatrix} \vec{i} & \vec{j} & \vec{k} \\ 1 & 2 & -1 \\ -2 & 3 & 4 \end{vmatrix} = \begin{vmatrix} 2 & -1 \\ 3 & 4 \end{vmatrix}\vec{i} - \begin{vmatrix} 1 & -1 \\ -2 & 4 \end{vmatrix}\vec{j} + \begin{vmatrix} 1 & 2 \\ -2 & 3 \end{vmatrix}\vec{k}$$
     $$= (8 - (-3))\vec{i} - (4 - 2)\vec{j} + (3 - (-4))\vec{k} = 11\vec{i} - 2\vec{j} + 7\vec{k} = (11, -2, 7)$$
  2. **Karma Çarpım ($\vec{u} \cdot (\vec{v} \times \vec{w})$) ve Paralelkenar Prizmanın Hacmi:**
     $$\vec{u} \cdot (\vec{v} \times \vec{w}) = \begin{vmatrix} 1 & 2 & -1 \\ -2 & 3 & 4 \\ 2 & 1 & 0 \end{vmatrix}$$
     3. satıra (veya 1. satıra) göre determinant açıldığında:
     $$\vec{u} \cdot (\vec{v} \times \vec{w}) = 1\begin{vmatrix} 3 & 4 \\ 1 & 0 \end{vmatrix} - 2\begin{vmatrix} -2 & 4 \\ 2 & 0 \end{vmatrix} + (-1)\begin{vmatrix} -2 & 3 \\ 2 & 1 \end{vmatrix} = 1(-4) - 2(-8) - 1(-8) = -4 + 16 + 8 = 20$$
     Komşu ayrıtları $\vec{u}, \vec{v}, \vec{w}$ olan paralelkenar prizmanın hacmi $V = |20| = 20$ birimküptür (sıralama değişip determinant $-20$ çıksaydı da mutlak değeri alınarak hacim yine $20$ bulunurdu).
  3. **İkili Vektörel Çarpım ($\vec{u} \times (\vec{v} \times \vec{w})$):**
     $$\vec{u} \times (\vec{v} \times \vec{w}) = (\vec{u} \cdot \vec{w})\vec{v} - (\vec{u} \cdot \vec{v})\vec{w}$$
     Burada $\vec{u} \cdot \vec{w} = 1(2) + 2(1) + (-1)(0) = 4$ ve $\vec{u} \cdot \vec{v} = 1(-2) + 2(3) + (-1)(4) = -2 + 6 - 4 = 0$ olduğundan:
     $$\vec{u} \times (\vec{v} \times \vec{w}) = 4\vec{v} - 0\vec{w} = 4(-2, 3, 4) = (-8, 12, 16)$$

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
