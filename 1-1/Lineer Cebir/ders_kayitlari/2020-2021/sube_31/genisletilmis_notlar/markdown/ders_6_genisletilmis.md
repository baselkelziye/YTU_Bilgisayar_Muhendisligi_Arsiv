# Ders 6 Genişletilmiş Notu: Doğrusal Denklem Sistemleri, Homojen Sistemler, Matrisin Rankı ve Gauss-Jordan Eliminasyon Yöntemi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Doğrusal Denklemler ve Doğrusal Denklem Sistemleri (Systems of Linear Equations)
  - 1.1 Doğrusal Denklem (Linear Equation) ve Çözüm Tanımı
  - 1.2 $n$ Bilinmeyenli $m$ Doğrusal Denklem Sistemi
  - 1.3 Tutarlı (Consistent) ve Tutarsız (Inconsistent) Sistemler
- 2. Homojen Doğrusal Denklem Sistemleri (Homogeneous Systems)
  - 2.1 Homojen Sistem Tanımı
  - 2.2 Aşikar (Trivial) ve Aşikar Olmayan (Non-Trivial) Çözümler
- 3. Lineer Sistemin Matris Gösterimi ve Genişletilmiş Matris
  - 3.1 $AX = b$ Matris Formunun Çıkarılışı
  - 3.2 Genişletilmiş Matris (Augmented Matrix): $[A \mid b]$ ve $[A \mid 0]$
- 4. Matrisin Rankı (The Rank of a Matrix)
- 5. Gauss-Jordan Eliminasyon Yöntemi (Gauss-Jordan Elimination Method)
  - 5.1 Rank Yardımıyla Çözüm Durumlarının Analizi (Çözüm Yok, Tek Çözüm, Sonsuz Çözüm)
  - 5.2 Gauss-Jordan Yöntemiyle Homojen Olmayan Sistem Çözümü Örneği
  - 5.3 Homojen Lineer Sistemlerin Çözüm Kriterleri ve Çözümlü Örnek
- Örnek Sorular
- Dersin Toparlaması

## 1. Doğrusal Denklemler ve Doğrusal Denklem Sistemleri (Systems of Linear Equations)

Hoca derse matematik, fizik, biyoloji ve mühendisliğin tüm dallarındaki en temel pratik problemlerden birinin **doğrusal denklem sistemlerinin** (systems of linear equations) çözümü olduğunu belirterek başladı.

### 1.1 Doğrusal Denklem (Linear Equation) ve Çözüm Tanımı

- **Doğrusal Denklem (Linear Equation):** $b$ sabitini $x_1, x_2, \dots, x_n$ bilinmeyenleri (unknowns) ve $a_1, a_2, \dots, a_n$ bilinen sabitleri (constants / katsayıları) cinsinden ifade eden:
  $$a_1 x_1 + a_2 x_2 + \dots + a_n x_n = b$$
  biçimindeki denkleme bir **doğrusal (lineer) denklem** denir. Uygulamalarda genellikle $a_1, a_2, \dots, a_n$ katsayıları ile sağ taraftaki $b$ sabiti verilir ve bizden $x_1, x_2, \dots, x_n$ bilinmeyenlerini bulmamız istenir.

- **Doğrusal Denklemin Çözümü:** $x_1 = s_1, x_2 = s_2, \dots, x_n = s_n$ değerleri denklemde yerine konulduğunda eşitliği sağlayan $s_1, s_2, \dots, s_n$ sayı dizisine (sequence of numbers) bu doğrusal denklemin bir **çözümü** (a solution to the linear equation) denir.

### 1.2 $n$ Bilinmeyenli $m$ Doğrusal Denklem Sistemi

Daha genel olarak, her biri $x_1, x_2, \dots, x_n$ olmak üzere $n$ bilinmeyen içeren $m$ adet doğrusal denklemden oluşan kümeye **$n$ bilinmeyenli $m$ doğrusal denklem sistemi** (a system of $m$ linear equations in $n$ unknowns) veya kısaca **lineer sistem** (linear system) denir ve açık olarak şu şekilde yazılır (ekrandan, 00:18:30):

$$\begin{cases} a_{11}x_1 + a_{12}x_2 + \dots + a_{1n}x_n = b_1 \\ a_{21}x_1 + a_{22}x_2 + \dots + a_{2n}x_n = b_2 \\ \qquad \vdots \\ a_{m1}x_1 + a_{m2}x_2 + \dots + a_{mn}x_n = b_m \end{cases} \qquad (1)$$

Burada $x_1, x_2, \dots, x_n$ sistemin bilinmeyenleridir ve sistemde toplam $m$ adet denklem bulunmaktadır.

### 1.3 Tutarlı (Consistent) ve Tutarsız (Inconsistent) Sistemler

- Eğer $(1)$ numaralı lineer sistemin **hiç çözümü yoksa** (has no solution), bu sisteme **tutarsız** (inconsistent) denir.
- Eğer $(1)$ numaralı lineer sistemin **en az bir çözümü varsa** (if there is a solution), bu sisteme **tutarlı** (consistent) denir.

## 2. Homojen Doğrusal Denklem Sistemleri (Homogeneous Systems)

### 2.1 Homojen Sistem Tanımı

Eğer $(1)$ numaralı lineer sistemde eşitliklerin sağ tarafındaki sabitlerin tamamı sıfıra eşitse ($b_1 = b_2 = \dots = b_m = 0$), bu sisteme **homojen sistem** (homogeneous system) denir (ekrandan, 00:26:00):

$$\begin{cases} a_{11}x_1 + a_{12}x_2 + \dots + a_{1n}x_n = 0 \\ a_{21}x_1 + a_{22}x_2 + \dots + a_{2n}x_n = 0 \\ \qquad \vdots \\ a_{m1}x_1 + a_{m2}x_2 + \dots + a_{mn}x_n = 0 \end{cases}$$

### 2.2 Aşikar (Trivial) ve Aşikar Olmayan (Non-Trivial) Çözümler

Bir homojen sistemde bilinmeyenlerin tamamı yerine sıfır yazıldığında ($x_1 = x_2 = x_3 = \dots = x_n = 0$), sol taraftaki tüm toplamlar $0$'a eşit olacağından tüm denklemler otomatik olarak sağlanır.

- **Aşikar Çözüm (Trivial Solution):** Bir homojen sistem için her zaman bir çözüm olan $x_1 = x_2 = \dots = x_n = 0$ çözümüne **aşikar (trivial) çözüm** veya **sıfır çözümü** (zero solution) denir (ekrandan, 00:26:00).
- **Aşikar Olmayan Çözüm (Non-Trivial Solution):** Bir homojen sistemde $x_1, x_2, \dots, x_n$ bilinmeyenlerinin tamamının sıfır olmadığı (en az bir $x_i \neq 0$ olduğu) bir çözüme ise **aşikar olmayan (non-trivial) çözüm** denir.

## 3. Lineer Sistemin Matris Gösterimi ve Genişletilmiş Matris

### 3.1 $AX = b$ Matris Formunun Çıkarılışı

$n$ bilinmeyenli $m$ denklemden oluşan $(1)$ numaralı lineer sistemi matrisleri kullanarak çözmek için şu üç matrisi tanımlayalım (ekrandan, 00:26:00 ve 00:34:00):

1. **Katsayılar Matrisi (Coefficient Matrix, $A$):** Bilinmeyenlerin katsayılarından oluşan $m \times n$ boyutlu matris:
   $$A = \begin{bmatrix} a_{11} & a_{12} & \cdots & a_{1n} \\ a_{21} & a_{22} & \cdots & a_{2n} \\ \vdots & \vdots & \ddots & \vdots \\ a_{m1} & a_{m2} & \cdots & a_{mn} \end{bmatrix}$$
2. **Bilinmeyenler Vektörü (Vector of Unknowns, $X$):** Bilinmeyenlerden oluşan $n \times 1$ boyutlu sütun matrisi:
   $$X = \begin{bmatrix} x_1 \\ x_2 \\ \vdots \\ x_n \end{bmatrix}$$
3. **Sabitler Vektörü (Vector of Constants, $b$):** Denklemlerin sağ tarafındaki sabitlerden oluşan $m \times 1$ boyutlu sütun matrisi:
   $$b = \begin{bmatrix} b_1 \\ b_2 \\ \vdots \\ b_m \end{bmatrix}$$

$A$ matrisi ile $X$ matrisini çarptığımızda ($A$'nın her bir satırı ile $X$ sütununun iç çarpımı alındığında):
$$AX = \begin{bmatrix} a_{11}x_1 + a_{12}x_2 + \dots + a_{1n}x_n \\ a_{21}x_1 + a_{22}x_2 + \dots + a_{2n}x_n \\ \vdots \\ a_{m1}x_1 + a_{m2}x_2 + \dots + a_{mn}x_n \end{bmatrix}$$
elde edilir (ekrandan, 00:34:00). Dikkat edilirse $AX$ çarpım matrisinin satırları tam olarak $(1)$ numaralı lineer sistemdeki denklemlerin sol taraflarıdır. Sağ taraflar ise $b$ matrisinin elemanları olduğundan, $(1)$ numaralı lineer sistem matris formunda kısaca:
$$AX = b$$
olarak yazılır.

### 3.2 Genişletilmiş Matris (Augmented Matrix): $[A \mid b]$ ve $[A \mid 0]$

Sol tarafa $A$ katsayılar matrisi yazılıp, araya dikey bir çizgi konularak sağ tarafına $b$ sütun matrisinin eklenmesiyle elde edilen matrise lineer sistemin **genişletilmiş matrisi** (augmented matrix of the linear system) denir ve $[A \mid b]$ ile gösterilir (ekrandan, 00:37:30):

$$[A \mid b] = \left[\begin{array}{cccc|c} a_{11} & a_{12} & \cdots & a_{1n} & b_1 \\ a_{21} & a_{22} & \cdots & a_{2n} & b_2 \\ \vdots & \vdots & \ddots & \vdots & \vdots \\ a_{m1} & a_{m2} & \cdots & a_{mn} & b_m \end{array}\right]$$

Bir homojen sistemde ise $b$ sütunundaki tüm elemanlar sıfır olduğundan homojen sistemin genişletilmiş matrisi $[A \mid 0]$ biçimindedir:

$$[A \mid 0] = \left[\begin{array}{cccc|c} a_{11} & a_{12} & \cdots & a_{1n} & 0 \\ a_{21} & a_{22} & \cdots & a_{2n} & 0 \\ \vdots & \vdots & \ddots & \vdots & \vdots \\ a_{m1} & a_{m2} & \cdots & a_{mn} & 0 \end{array}\right]$$

## 4. Matrisin Rankı (The Rank of a Matrix)

Hoca lineer sistemlerin çözüm yöntemine geçmeden önce daha önceki derslerde bahsedilen **matrisin rankı** kavramını tekrar tanımladı ve bir örnekle açıkladı (ekrandan, 00:46:20 ve 00:50:45):

- **Tanım:** Bir $A$ matrisinin satır eşelon formunun (REF) veya indirgenmiş satır eşelon formunun (RREF) $C$ olduğunu varsayalım. $C$ matrisindeki **sıfırdan farklı satırların sayısına** (the number of nonzero rows of $C$) $A$ matrisinin **rankı** denir ve $\text{rank}(A)$ ile gösterilir.

- **Örnek (ekrandan, 00:46:20):**
  Aşağıda bir $A$ matrisi ve bu matrisin elementer satır işlemleriyle elde edilmiş indirgenmiş satır eşelon formu (RREF) olan $C$ matrisi verilmiştir:
  $$A = \begin{pmatrix} 1 & 0 & 1 & 0 & 1 \\ 2 & 0 & 2 & 0 & 2 \\ 1 & -1 & 0 & 1 & 0 \\ 2 & -2 & 0 & 2 & 0 \end{pmatrix} \sim C = \begin{pmatrix} 1 & 0 & 1 & 0 & 1 \\ 0 & 1 & 1 & -1 & 1 \\ 0 & 0 & 0 & 0 & 0 \\ 0 & 0 & 0 & 0 & 0 \end{pmatrix}$$
  $C$ matrisine bakıldığında son iki satır tamamen sıfırlardan oluşmaktadır; sıfırdan farklı (nonzero) yalnızca ilk $2$ satır vardır. Dolayısıyla:
  $$\text{rank}(A) = 2$$
  olur.

## 5. Gauss-Jordan Eliminasyon Yöntemi (Gauss-Jordan Elimination Method)

Bir $AX = b$ lineer sistemini çözmek için sistemin $[A \mid b]$ genişletilmiş matrisini yazıp elementer satır işlemleri yardımıyla bu matrisi **indirgenmiş satır eşelon formuna** (reduced row echelon form - RREF) dönüştürme yöntemine **Gauss-Jordan eliminasyon yöntemi** (Gauss-Jordan elimination method) denir.

### 5.1 Rank Yardımıyla Çözüm Durumlarının Analizi (Çözüm Yok, Tek Çözüm, Sonsuz Çözüm)

$n$ bilinmeyenli ve $m$ denklemli bir $AX = b$ lineer sisteminde $[A \mid b]$ genişletilmiş matrisi eşelon forma indirgendikten sonra $A$'nın rankı ile $[A \mid b]$'nin rankı karşılaştırılır. Sistemin çözümü için üç olası durum vardır (ekrandan, 00:58:15):

```text
                        Lineer Sistemin Çözümü (AX = b, n bilinmeyen)
                                             │
                 ┌───────────────────────────┴───────────────────────────┐
                 ▼                                                       ▼
    rank(A) ≠ rank([A | b])                                 rank(A) = rank([A | b]) = r
   Çözüm Yok (No Solution)                                 Çözüm Var (Tutarlı / Consistent)
    (Tutarsız / Inconsistent)                                            │
                                                   ┌─────────────────────┴─────────────────────┐
                                                   ▼                                           ▼
                                            rank(A) = n                                 rank(A) = r < n
                                     Tek Çözüm (Unique Solution)                    Sonsuz Çoklukta Çözüm
                                                                               (n - r parametreye bağlı)
```

1. **Çözüm Yok (No Solution — Tutarsız / Inconsistent):**
   Eğer $\text{rank}(A) \neq \text{rank}([A \mid b])$ ise sistem tutarsızdır ve hiçbir çözümü yoktur.
2. **Tek Çözüm (Unique Solution — Tutarlı / Consistent):**
   Eğer $\text{rank}(A) = \text{rank}([A \mid b]) = n$ (yani rank, sistemdeki bilinmeyen sayısı $n$'ye eşit) ise sistem tutarlıdır ve **tek bir çözümü** (unique solution) vardır.
3. **Sonsuz Çoklukta Çözüm (Infinitely Many Solutions — Tutarlı / Consistent):**
   Eğer $\text{rank}(A) = \text{rank}([A \mid b]) = r < n$ (yani rank, bilinmeyen sayısı $n$'den küçük) ise sistem tutarlıdır ve **$n - r$ tane keyfi parametreye bağlı sonsuz çoklukta çözümü** vardır.

### 5.2 Gauss-Jordan Yöntemiyle Homojen Olmayan Sistem Çözümü Örneği

Hoca Gauss-Jordan yönteminin tüm adımlarını $3$ bilinmeyenli ve $3$ denklemli bir sistem üzerinde ayrıntılı olarak gösterdi (ekrandan, 01:02:15, 01:11:15 ve 01:18:25):

- **Verilen:**
  $$x - y + 3z = 1, \quad y = -2x + 5, \quad 9z - x - 5y + 7 = 0$$
  doğrusal denklem sistemini Gauss-Jordan eliminasyon yöntemiyle çözünüz.

- **1. Adım (Denklemlerin Standart Sıraya Dizilmesi — ekrandan, 01:02:15):**
  > **Hocanın vurgusu:** Sistemi $AX = b$ formunda yazacağımız için öncelikle tüm denklemlerdeki bilinmeyenleri **aynı sırayla** ($x_1 = x$, $x_2 = y$, $x_3 = z$ sırasıyla) eşitliğin sol tarafına, sabit sayıları ise sağ tarafına yazmalıyız.
  - 1. denklem zaten sıralıdır: $x - y + 3z = 1$
  - 2. denklem ($y = -2x + 5$): $-2x$'i sola atarsak $2x + y = 5$ (veya hocanın tahtada ilk yazdığı gibi $-2x - y = -5$, iki tarafı $-1$ ile çarpınca $2x + y + 0z = 5$). Bu denklemde $z$ terimi olmadığı için $z$'nin katsayısı $0$'dır.
  - 3. denklem ($9z - x - 5y + 7 = 0$): $x, y, z$ sırasına dizip $7$'yi sağa atarsak $-x - 5y + 9z = -7$.

  Böylece $3$ bilinmeyenli ($n = 3$) ve $3$ denklemli sistemimiz standart formda şu şekli alır:
  $$\begin{cases} x - y + 3z = 1 \\ 2x + y + 0z = 5 \\ -x - 5y + 9z = -7 \end{cases}$$

- **2. Adım (Genişletilmiş Matrisin Yazılması ve RREF'e İndirgenmesi — ekrandan, 01:11:15):**
  Sistemin genişletilmiş matrisi $[A \mid b]$ yazılır:
  $$[A \mid b] = \left[\begin{array}{ccc|c} 1 & -1 & 3 & 1 \\ 2 & 1 & 0 & 5 \\ -1 & -5 & 9 & -7 \end{array}\right]$$
  1. satırın ilk elemanı zaten öncü $1$'dir (leading $1$). Bu öncü $1$'in bulunduğu 1. sütundaki diğer elemanları ($2$ ve $-1$) sıfırlamak için 1. satırı $-2$ ile çarpıp 2. satıra ekleriz ($-2r_1 + r_2 \to r_2$) ve 1. satırı doğrudan 3. satıra ekleriz ($r_1 + r_3 \to r_3$):
  - Yeni 2. satır: $(-2+2,\ 2+1,\ -6+0 \mid -2+5) = (0,\ 3,\ -6 \mid 3)$
  - Yeni 3. satır: $(1-1,\ -1-5,\ 3+9 \mid 1-7) = (0,\ -6,\ 12 \mid -6)$
  $$\xrightarrow[\ r_1 + r_3 \to r_3\ ]{-2r_1 + r_2 \to r_2} \left[\begin{array}{ccc|c} 1 & -1 & 3 & 1 \\ 0 & 3 & -6 & 3 \\ 0 & -6 & 12 & -6 \end{array}\right]$$
  Şimdi 2. satırdaki ilk sıfırdan farklı eleman olan $3$'ü öncü $1$ yapmak için 2. satırı $\frac{1}{3}$ ile çarparız ($\frac{1}{3}r_2 \to r_2$):
  $$\xrightarrow{\frac{1}{3}r_2 \to r_2} \left[\begin{array}{ccc|c} 1 & -1 & 3 & 1 \\ 0 & 1 & -2 & 1 \\ 0 & -6 & 12 & -6 \end{array}\right]$$
  İndirgenmiş satır eşelon formunda (RREF) her öncü $1$'in bulunduğu sütundaki diğer tüm elemanlar (hem altındakiler hem üstündekiler) sıfır olmalıdır. 2. sütundaki öncü $1$'in üstündeki $-1$'i sıfırlamak için 2. satırı 1. satıra ekleriz ($r_2 + r_1 \to r_1$) ve altındaki $-6$'yı sıfırlamak için 2. satırın $6$ katını 3. satıra ekleriz ($6r_2 + r_3 \to r_3$):
  - Yeni 1. satır: $(1+0,\ -1+1,\ 3-2 \mid 1+1) = (1,\ 0,\ 1 \mid 2)$
  - Yeni 3. satır: $(0+0,\ -6+6,\ 12-12 \mid -6+6) = (0,\ 0,\ 0 \mid 0)$
  $$\xrightarrow[\ 6r_2 + r_3 \to r_3\ ]{r_2 + r_1 \to r_1} \left[\begin{array}{ccc|c} 1 & 0 & 1 & 2 \\ 0 & 1 & -2 & 1 \\ 0 & 0 & 0 & 0 \end{array}\right]$$
  3. satır tamamen sıfır olduğundan matris indirgenmiş satır eşelon formuna (RREF) ulaşmıştır.

- **3. Adım (Rankların Karşılaştırılması):**
  - Sol taraftaki $A$ matrisinin sıfırdan farklı satır sayısı: $\text{rank}(A) = 2$.
  - Tüm $[A \mid b]$ genişletilmiş matrisinin sıfırdan farklı satır sayısı: $\text{rank}([A \mid b]) = 2$.
  - $\text{rank}(A) = \text{rank}([A \mid b]) = 2$ olduğundan sistem **tutarlıdır** (çözümü vardır).
  - Bilinmeyen sayısı $n = 3$ olup $\text{rank}(A) = 2 < 3$ olduğundan, sistemin $n - r = 3 - 2 = 1$ parametreye bağlı **sonsuz çoklukta çözümü** vardır.

- **4. Adım (Genel Çözümün ve Çözüm Kümesinin Yazılması — ekrandan, 01:18:25):**
  RREF matrisinden denklemlere geri dönülür:
  - 1. satırdan: $1\cdot x + 0\cdot y + 1\cdot z = 2 \implies x + z = 2 \implies x = 2 - z$
  - 2. satırdan: $0\cdot x + 1\cdot y - 2\cdot z = 1 \implies y - 2z = 1 \implies y = 1 + 2z$
  Burada $z$ için keyfi bir reel parametre $z = t \in \mathbb{R}$ seçilirse:
  $$\begin{cases} x = 2 - t \\ y = 1 + 2t \\ z = t \end{cases} \quad (t \in \mathbb{R})$$
  Bu çözüm kümesi vektörel formda şu şekilde yazılır:
  $$X = \begin{bmatrix} x \\ y \\ z \end{bmatrix} = \begin{bmatrix} 2 \\ 1 \\ 0 \end{bmatrix} + t \begin{bmatrix} -1 \\ 2 \\ 1 \end{bmatrix} \quad (t \in \mathbb{R})$$
  $t$ yerine verilen her farklı reel sayı için denklemi sağlayan yeni bir $(x, y, z)$ üçlüsü elde edilir.

### 5.3 Homojen Lineer Sistemlerin Çözüm Kriterleri ve Çözümlü Örnek

Sağ tarafı tamamen sıfır olan homojen bir lineer sistemde ($AX = 0$), genişletilmiş matrisin sağ sütunu tamamen sıfırlardan oluştuğu için satır işlemleri sırasında sağ sütun asla sıfırdan farklı bir eleman üretemez. Dolayısıyla homojen sistemlerde her zaman $\text{rank}(A) = \text{rank}([A \mid 0])$ eşitliği sağlanır ve **bir homojen sistemin daima çözümü vardır** (ekrandan, 01:20:30):

1. Eğer $\text{rank}(A) = n$ (bilinmeyen sayısına eşit) ise sistemin **tek çözümü vardır ve bu çözüm sıfır (aşikar / trivial) çözümüdür** ($x_1 = x_2 = \dots = x_n = 0$).
2. Eğer $\text{rank}(A) = r < n$ (bilinmeyen sayısından küçük) ise sistemin **$n - r$ parametreye bağlı sonsuz çoklukta (aşikar olmayan) çözümü vardır**.

- **Homojen Sistem Çözümü Örneği (ekrandan, 01:20:30 ve 01:28:00):**
  Bir önceki örnekteki sistemin sağ tarafı sıfır yapılarak elde edilen homojen sistemi çözelim:
  $$\begin{cases} x - y + 3z = 0 \\ 2x + y = 0 \\ -x - 5y + 9z = 0 \end{cases}$$
  - **Genişletilmiş Matris ve Satır İşlemleri:**
    $$[A \mid 0] = \left[\begin{array}{ccc|c} 1 & -1 & 3 & 0 \\ 2 & 1 & 0 & 0 \\ -1 & -5 & 9 & 0 \end{array}\right]$$
    Katsayılar matrisi $A$ bir önceki örnekle aynı olduğundan aynı satır işlemleri uygulandığında (Not: Hoca tahtada $-2r_1 + r_2 \to r_2$ adımında $a_{23}$ elemanını sehven $-6$ yerine $+6$ yazmış, ardından bir öğrencinin uyarısıyla $-6$ ve $\frac{1}{3}$ ile bölündüğünde $-2$ olarak düzeltmiştir):
    $$\xrightarrow[\ r_1 + r_3 \to r_3\ ]{-2r_1 + r_2 \to r_2} \left[\begin{array}{ccc|c} 1 & -1 & 3 & 0 \\ 0 & 3 & -6 & 0 \\ 0 & -6 & 12 & 0 \end{array}\right] \xrightarrow{\frac{1}{3}r_2 \to r_2} \left[\begin{array}{ccc|c} 1 & -1 & 3 & 0 \\ 0 & 1 & -2 & 0 \\ 0 & -6 & 12 & 0 \end{array}\right] \xrightarrow[\ 6r_2 + r_3 \to r_3\ ]{r_2 + r_1 \to r_1} \left[\begin{array}{ccc|c} 1 & 0 & 1 & 0 \\ 0 & 1 & -2 & 0 \\ 0 & 0 & 0 & 0 \end{array}\right]$$
  - **Rank ve Çözüm Kümesi (ekrandan, 01:28:00):**
    $\text{rank}(A) = \text{rank}([A \mid 0]) = 2 < 3$ olduğundan $3 - 2 = 1$ parametreye bağlı sonsuz çözüm vardır.
    - 1. satırdan: $1\cdot x + 0\cdot y + 1\cdot z = 0 \implies x + z = 0 \implies x = -z$
    - 2. satırdan: $0\cdot x + 1\cdot y - 2\cdot z = 0 \implies y - 2z = 0 \implies y = 2z$
    Keyfi parametre olarak $z = t \in \mathbb{R}$ seçildiğinde:
    $$x = -t, \quad y = 2t, \quad z = t \implies \mathbf{x} = \begin{bmatrix} x \\ y \\ z \end{bmatrix} = t \begin{bmatrix} -1 \\ 2 \\ 1 \end{bmatrix} \quad (t \in \mathbb{R})$$
    elde edilir. (Özel olarak $t = 0$ için $(0, 0, 0)^T$ aşikar çözümü, $t \neq 0$ için ise aşikar olmayan çözümler bulunur.)

**Soru:** RREF matrisinden sonra $x + z = 0$ ve $y - 2z = 0$ denklemlerini nasıl yazdık ve neden $z$'yi keyfi değişken ($t$) olarak aldık?
**Cevap:** Sistemin matris formu $AX = 0$ şeklindedir ve $X$ sütunundaki bilinmeyenlerin sırası $x_1 = x$, $x_2 = y$, $x_3 = z$'dir. İndirgenmiş matrisin 1. satırı $(1\ \ 0\ \ 1 \mid 0)$ olduğundan katsayıları sırasıyla $x, y, z$ ile çarptığımızda $1\cdot x + 0\cdot y + 1\cdot z = 0$, yani $x + z = 0$ ($x = -z$) elde edilir. 2. satır $(0\ \ 1\ \ -2 \mid 0)$ olduğundan $0\cdot x + 1\cdot y - 2\cdot z = 0$, yani $y - 2z = 0$ ($y = 2z$) elde edilir. Dikkat edilirse hem $x$ hem de $y$, $z$'ye bağlıdır; fakat 3. satır tamamen sıfır olduğu için $z$'yi kısıtlayan hiçbir denklem yoktur. Bu yüzden $z$ keyfi (serbest) bir değişkendir ve $z = t \in \mathbb{R}$ olarak seçilir.

## Örnek Sorular

### Soru 1: Matrisin Rankını Bulma (ekrandan, 00:46:20)

**Soru:** İndirgenmiş satır eşelon formu (RREF)
$$C = \begin{pmatrix} 1 & 0 & 1 & 0 & 1 \\ 0 & 1 & 1 & -1 & 1 \\ 0 & 0 & 0 & 0 & 0 \\ 0 & 0 & 0 & 0 & 0 \end{pmatrix}$$
olan $A$ matrisinin rankı ($\text{rank}(A)$) kaçtır?

**Çözüm:**
Bir matrisin rankı, onun eşelon (REF veya RREF) formundaki sıfırdan farklı satırlarının sayısına eşittir. $C$ matrisinde sıfırdan farklı $2$ satır bulunduğundan $\text{rank}(A) = 2$'dir.

### Soru 2: Gauss-Jordan Eliminasyon Yöntemiyle Lineer Sistem Çözümü (ekrandan, 01:02:15, 01:11:15 ve 01:18:25)

**Soru:**
$$x - y + 3z = 1, \quad y = -2x + 5, \quad 9z - x - 5y + 7 = 0$$
doğrusal denklem sistemini Gauss-Jordan eliminasyon yöntemiyle çözünüz.

**Çözüm:**
Denklemler $x, y, z$ sırasına göre düzenlenip $[A \mid b]$ genişletilmiş matrisi kurulur ve RREF formuna indirgenir:
$$\left[\begin{array}{ccc|c} 1 & -1 & 3 & 1 \\ 2 & 1 & 0 & 5 \\ -1 & -5 & 9 & -7 \end{array}\right] \xrightarrow[\ r_1 + r_3 \to r_3\ ]{-2r_1 + r_2 \to r_2} \left[\begin{array}{ccc|c} 1 & -1 & 3 & 1 \\ 0 & 3 & -6 & 3 \\ 0 & -6 & 12 & -6 \end{array}\right] \xrightarrow{\frac{1}{3}r_2 \to r_2} \left[\begin{array}{ccc|c} 1 & -1 & 3 & 1 \\ 0 & 1 & -2 & 1 \\ 0 & -6 & 12 & -6 \end{array}\right] \xrightarrow[\ 6r_2 + r_3 \to r_3\ ]{r_2 + r_1 \to r_1} \left[\begin{array}{ccc|c} 1 & 0 & 1 & 2 \\ 0 & 1 & -2 & 1 \\ 0 & 0 & 0 & 0 \end{array}\right]$$
$\text{rank}(A) = \text{rank}([A \mid b]) = 2 < 3$ olduğundan $3 - 2 = 1$ parametreye bağlı sonsuz çözüm vardır. $x = 2 - z$ ve $y = 1 + 2z$ olup $z = t \in \mathbb{R}$ için çözüm:
$$\begin{bmatrix} x \\ y \\ z \end{bmatrix} = \begin{bmatrix} 2 \\ 1 \\ 0 \end{bmatrix} + t \begin{bmatrix} -1 \\ 2 \\ 1 \end{bmatrix}$$

### Soru 3: Homojen Lineer Sistem Çözümü (ekrandan, 01:20:30 ve 01:28:00)

**Soru:**
$$\begin{cases} x - y + 3z = 0 \\ 2x + y = 0 \\ -x - 5y + 9z = 0 \end{cases}$$
homojen doğrusal denklem sisteminin çözüm kümesini bulunuz.

**Çözüm:**
Genişletilmiş matris $[A \mid 0]$ aynı satır işlemleriyle RREF formuna indirgendiğinde:
$$\left[\begin{array}{ccc|c} 1 & -1 & 3 & 0 \\ 2 & 1 & 0 & 0 \\ -1 & -5 & 9 & 0 \end{array}\right] \sim \left[\begin{array}{ccc|c} 1 & 0 & 1 & 0 \\ 0 & 1 & -2 & 0 \\ 0 & 0 & 0 & 0 \end{array}\right]$$
elde edilir. $\text{rank}(A) = \text{rank}([A \mid 0]) = 2 < 3$ olduğundan sistemin $1$ parametreye bağlı sonsuz çözümü vardır. $x = -z$ ve $y = 2z$ olup $z = t \in \mathbb{R}$ alındığında tüm çözümler:
$$\mathbf{x} = \begin{bmatrix} x \\ y \\ z \end{bmatrix} = t \begin{bmatrix} -1 \\ 2 \\ 1 \end{bmatrix} \quad (t \in \mathbb{R})$$
biçimindedir.

## Dersin Toparlaması

Bu derste doğrusal denklem sistemlerinin temel kavramları ve ilk çözüm yöntemi olan Gauss-Jordan eliminasyon yöntemi işlendi. Öncelikle doğrusal denklem, $n$ bilinmeyenli $m$ doğrusal denklem sistemi, sistemin tutarlı (consistent) veya tutarsız (inconsistent) olması, sağ tarafı sıfır olan homojen sistemler ($AX = 0$) ile bunların aşikar (trivial) ve aşikar olmayan (non-trivial) çözümleri tanımlandı. Ardından bir lineer sistemin katsayılar matrisi $A$, bilinmeyenler vektörü $X$ ve sabitler vektörü $b$ kullanılarak $AX = b$ matris formunda ve $[A \mid b]$ genişletilmiş matrisiyle nasıl temsil edildiği gösterildi. Matrisin eşelon formundaki sıfırdan farklı satır sayısı olarak tanımlanan rank kavramı hatırlatılarak, Gauss-Jordan eliminasyon yöntemiyle $[A \mid b]$ matrisi RREF formuna indirgendiğinde $\text{rank}(A)$ ile $\text{rank}([A \mid b])$ arasındaki ilişkiye göre sistemin ne zaman çözümsüz, ne zaman tek çözümlü ve ne zaman $n - r$ parametreye bağlı sonsuz çözümlü olduğu hem homojen olmayan hem de homojen sistem örnekleri üzerinde adım adım incelendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
