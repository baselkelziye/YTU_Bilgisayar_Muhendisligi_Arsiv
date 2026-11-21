# Ders 12 Genişletilmiş Notu: Lineer Sistemler, Vektörler ve Vektör Uzayları Genel Tekrarı ile Örnek Sınav Sorularının Çözümü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Doğrusal Denklem Sistemlerinin Çözüm Yöntemleri Genel Tekrarı
  - 1.1 Katsayılar Matrisi, Genişletilmiş Matris ve Gauss-Jordan İndirgeme Yöntemi
  - 1.2 Rank Analizi ile Çözüm Durumları (Çözümsüz, Tek Çözüm, Sonsuz Çözüm)
  - 1.3 Cramer Kuralı ve Ters Matris Yöntemi ($X = A^{-1}b$)
  - 1.4 Homojen Doğrusal Denklem Sistemleri ($AX = 0$)
- 2. Doğrusal Denklem Sistemleri Üzerine Örnek Sınav Soruları ve Çözümleri
  - 2.1 $4 \times 4$ Sistemde Cramer Kuralıyla Tek Bir Bilinmeyenin ($t$) Bulunması
  - 2.2 Ters Matris Yöntemiyle $3 \times 3$ Sistemlerin Çözümü
  - 2.3 $4 \times 4$ Sistemde Cramer Kuralıyla $y$ Bilinmeyeninin Bulunması
  - 2.4 Sistemin Tutarlı (Consistent) Olması İçin $a, b, c$ Arasındaki Bağıntının Bulunması
  - 2.5 $t$ Parametresine Göre Çözümsüz, Tek Çözümlü ve Sonsuz Çözümlü Olma Analizi
- 3. Vektörler, Alan, Hacim ve Düzlemsellik Genel Tekrarı ve Sınav Soruları
  - 3.1 Norm, Birim Vektör, Standart Baz Vektörleri ve İç Çarpım Tekrarı
  - 3.2 Vektörel Çarpım, Üçgenin Alanı ve Paralelkenarın Alanı
  - 3.3 Karma Çarpım, Paralelkenar Prizmanın Hacmi, Aynı Düzlemde Bulunma (Coplanarity) ve İkili Vektörel Çarpım
  - 3.4 Vektörler Üzerine Örnek Sınav Soruları (Düzlemsellik ve Düzleme Dik Vektör Bulma)
- 4. Vektör Uzayları ve Altuzaylar Genel Tekrarı (Rasyonel Sayılar Kümesi Örneği)
- Örnek Sorular
- Dersin Toparlaması

## 1. Doğrusal Denklem Sistemlerinin Çözüm Yöntemleri Genel Tekrarı

Hoca bu derste önce 6. haftadan 10. haftaya kadar işlenen konuların (doğrusal denklem sistemleri, vektörler, vektör uzayları ve altuzaylar) kapsamlı bir özetini yapacağımızı, ardından örnek sınav sorularını (sample exam questions) çözeceğimizi belirtti.

### 1.1 Katsayılar Matrisi, Genişletilmiş Matris ve Gauss-Jordan İndirgeme Yöntemi

$m$ adet denklem ve $n$ adet bilinmeyenden ($x_1, x_2, \dots, x_n$) oluşan genel bir doğrusal denklem sistemi ele alalım:
$$\begin{cases} a_{11}x_1 + a_{12}x_2 + \dots + a_{1n}x_n = b_1 \\ a_{21}x_1 + a_{22}x_2 + \dots + a_{2n}x_n = b_2 \\ \vdots \\ a_{m1}x_1 + a_{m2}x_2 + \dots + a_{mn}x_n = b_m \end{cases}$$

Bu sistemi matris formunda $AX = b$ olarak yazarız:
- **Katsayılar Matrisi (Coefficient Matrix — $A$):** Her bir satırı ilgili denklemin bilinmeyenlerinin katsayılarından oluşan $m \times n$ boyutlu matristir ($A = [a_{ij}]_{m \times n}$).
- **Genişletilmiş / İlaveli Matris (Augmented Matrix — $[A \mid b]$):** $A$ katsayılar matrisinin sağ tarafına $b = [b_1, b_2, \dots, b_m]^T$ sabitler sütununun eklenmesiyle elde edilen matristir.

Doğrusal denklem sistemlerini çözmek için üç farklı yöntem öğrendik:
1. **Gauss-Jordan İndirgeme Yöntemi** (Gauss-Jordan reduction method),
2. **Cramer Kuralı** (Cramer's rule),
3. **Katsayılar Matrisinin Tersini Kullanma Yöntemi** (Solving via the inverse of the coefficient matrix, $X = A^{-1}b$).

### 1.2 Rank Analizi ile Çözüm Durumları (Çözümsüz, Tek Çözüm, Sonsuz Çözüm)

**1. Yöntem — Gauss-Jordan İndirgeme Yöntemi (ekrandan, 00:18:30):**
Önce sistemin $[A \mid b]$ genişletilmiş matrisi yazılır ve **yalnızca elementer satır işlemleri** (elementary row operations) kullanılarak satırca indirgenmiş eşelon forma (reduced row echelon form — RREF) getirilir. İndirgenmiş matristeki sıfırdan farklı satır sayısına bakılarak $\text{rank}(A)$ ve $\text{rank}[A \mid b]$ belirlenir:

- **Durum 1 — Çözüm Yok (Tutarsız Sistem / Inconsistent):**
  $$\text{Eğer } \text{rank}[A \mid b] \neq \text{rank}(A) \text{ ise}$$
  doğrusal denklem sisteminin **çözümü yoktur** (no solution) ve sisteme **tutarsız** (inconsistent) denir.
- **Durum 2 — Çözüm Var (Tutarlı Sistem / Consistent):**
  $$\text{Eğer } \text{rank}[A \mid b] = \text{rank}(A) = r \text{ ise}$$
  doğrusal denklem sisteminin **en az bir çözümü vardır** (consistent). Bu durumda bilinmeyen sayısı $n$ ile rank $r$ karşılaştırılarak iki alt durum elde edilir:
  1. **Tek Çözüm ($r = n$):** Eğer sistemin rankı bilinmeyen sayısına eşitse ($r = n$), sistemin **tek bir çözümü** (unique solution) vardır.
  2. **Sonsuz Çoklukta Çözüm ($r < n$):** Eğer sistemin rankı bilinmeyen sayısından küçükse ($r < n$, örneğin denklem sayısının bilinmeyen sayısından az olduğu durumlarda), sistemin **$n - r$ tane keyfi değişkene (parametreye / arbitrary variables) bağlı sonsuz çoklukta çözümü** (infinitely many solutions) vardır.

### 1.3 Cramer Kuralı ve Ters Matris Yöntemi ($X = A^{-1}b$)

Cramer kuralını veya ters matris yöntemini ($X = A^{-1}b$) kullanabilmek için **iki temel koşulun** mutlaka sağlanması gerekir (ekrandan, 00:18:30 ve 00:38:30):

1. **Kare Sistem Koşulu ($m = n$):** Denklem sayısı bilinmeyen sayısına eşit olmalıdır ($n$ bilinmeyenli $n$ denklem); yani katsayılar matrisi $A$ bir $n \times n$ **kare matris** olmalıdır. Çünkü kare olmayan bir matrisin determinantından ve tersinden söz edilemez.
2. **Determinantın Sıfırdan Farklı Olması ($\det(A) \neq 0$):** Katsayılar matrisinin determinantı sıfırdan farklı olmalıdır ($\det(A) \neq 0$).

> **Hocanın vurgusu:** Bu iki koşul sağlandığında ($A \in M_{n \times n}$ ve $\det(A) \neq 0$), doğrusal denklem sisteminin **tek bir çözümü** (unique solution) vardır ve bu tek çözüm:
> - **Cramer Yöntemi ile:**
>   $$x_1 = \frac{\det(A_1)}{\det(A)}, \quad x_2 = \frac{\det(A_2)}{\det(A)}, \quad \dots, \quad x_n = \frac{\det(A_n)}{\det(A)}$$
>   formülüyle bulunur (burada $A_i$, $A$ matrisinin $i$. sütununun silinip yerine sağ taraftaki $b$ sabitler sütununun yazılmasıyla elde edilen matristir).
> - **Katsayılar Matrisinin Tersi ($A^{-1}$) Yöntemi ile:**
>   $AX = b$ eşitliğinin her iki tarafı soldan $A^{-1}$ ile çarpılarak:
>   $$A^{-1}AX = A^{-1}b \implies X = A^{-1}b$$
>   formülüyle bulunur.
> - **$\det(A) = 0$ Durumu:** Eğer $n$ bilinmeyenli $n$ denklemli bir sistemde $\det(A) = 0$ çıkarsa, Cramer kuralında payda sıfır olacağından ve ters matris yönteminde $A^{-1}$ mevcut olmadığından **bu iki yöntem kullanılamaz**! $\det(A) = 0$ olduğunda sistemin hiç çözümü olmayabileceği gibi sonsuz çözümü de olabilir; bunu belirlemek ve çözümü bulmak için **Gauss-Jordan indirgeme yöntemi** kullanılır.

### 1.4 Homojen Doğrusal Denklem Sistemleri ($AX = 0$)

Denklem sisteminin sağ tarafındaki tüm sabitlerin sıfır olduğu ($b_1 = b_2 = \dots = b_m = 0$) $AX = 0$ biçimindeki sistemlere **homojen doğrusal denklem sistemi** (homogeneous linear system) denir (ekrandan, 00:38:30).

> **Soru-Cevap (derste sözlü, 00:34:09):**
> **Soru:** Her doğrusal denklem sisteminde $\text{rank}[A \mid b] = \text{rank}(A)$ eşitliği her zaman sağlanır mı?
> **Cevap:** Hayır! Genel bir $AX = b$ sisteminde her zaman $\text{rank}[A \mid b] = \text{rank}(A)$ olmaz; örneğin indirgeme sonucunda $A$'nın son satırı tamamen $0$ iken $b$'nin son satırında sıfırdan farklı bir sayı kalırsa $\text{rank}[A \mid b] \neq \text{rank}(A)$ olur ve çözüm çıkmaz. $\text{rank}[A \mid 0] = \text{rank}(A)$ eşitliği **yalnızca homojen sistemlerde ($b = 0$)** her zaman sağlanır.

Homojen bir sistemde genişletilmiş matris $[A \mid 0]$ olduğundan satır işlemleri sıfır sütununu hiç değiştirmez ve **her zaman** $\text{rank}[A \mid 0] = \text{rank}(A) = r$ olur. Dolayısıyla **homojen bir sistemin her zaman en az bir çözümü vardır** ve iki durum söz konusudur (ekrandan, 00:38:30):

1. **$r = n$ Durumu (Yalnızca Sıfır / Aşikar Çözüm):** Eğer $\text{rank}(A) = r = n$ (bilinmeyen sayısına eşit) ise, homojen sistemin **yalnızca sıfır (aşikar / trivial) çözümü** vardır:
   $$x_1 = 0, \, x_2 = 0, \, \dots, \, x_n = 0$$
2. **$r < n$ Durumu (Sonsuz Çoklukta / Aşikar Olmayan Çözüm):** Eğer $\text{rank}(A) = r < n$ ise, homojen sistemin $n - r$ tane keyfi değişkene (arbitrary variables) bağlı **sonsuz çoklukta çözümü** (dolayısıyla sıfırdan farklı / aşikar olmayan / nontrivial çözümleri) vardır.

## 2. Doğrusal Denklem Sistemleri Üzerine Örnek Sınav Soruları ve Çözümleri

### 2.1 $4 \times 4$ Sistemde Cramer Kuralıyla Tek Bir Bilinmeyenin ($t$) Bulunması

- **Verilen (ekrandan, 00:44:30):**
  $$\begin{cases} x - 2z + t = 2 \\ 2x - y + 3t = 1 \\ 4x + y - 2z = 5 \\ 3x - y + 2t = -1 \end{cases}$$
  denklem sisteminde sadece "$t$" bilinmeyenini **Cramer Yöntemi** ile bulunuz.

- **Adım Adım Çözüm:**
  1. **Katsayılar Matrisi $A$ ve $\det(A)$'nın Hesaplanması:**
     Bilinmeyenlerimiz sırasıyla $x, y, z, t$ (yani $x_1, x_2, x_3, x_4$)'tür. Denklemlerde bulunmayan bilinmeyenlerin katsayısına $0$ yazmaya dikkat ederek katsayılar matrisinin determinantı $\Delta = \det(A)$'yı kuralım:
     - 1. denklem ($y$ yok): $1, \, 0, \, -2, \, 1$
     - 2. denklem ($z$ yok): $2, \, -1, \, 0, \, 3$
     - 3. denklem ($t$ yok): $4, \, 1, \, -2, \, 0$
     - 4. denklem ($z$ yok): $3, \, -1, \, 0, \, 2$
     $$\Delta = \det(A) = \begin{vmatrix} 1 & 0 & -2 & 1 \\ 2 & -1 & 0 & 3 \\ 4 & 1 & -2 & 0 \\ 3 & -1 & 0 & 2 \end{vmatrix}$$
     Satır işlemleri ($R_2 \to R_2 - 2R_1$, $R_3 \to R_3 - 4R_1$, $R_4 \to R_4 - 3R_1$) ve Laplace açılımı uygulandığında:
     $$\det(A) = 14 \neq 0$$
     bulunur. Determinant sıfırdan farklı olduğundan sistemin tek çözümü vardır.
  2. **$\det(A_4)$ ve $t$ Bilinmeyeninin Hesaplanması:**
     $t$ dördüncü bilinmeyen ($x_4$) olduğu için, $A$ katsayılar matrisinin **4. sütununu** silip yerine sağ taraftaki $b = [2, 1, 5, -1]^T$ sabitler sütununu yazarak $A_4$ matrisini oluştururuz:
     $$\det(A_4) = \begin{vmatrix} 1 & 0 & -2 & 2 \\ 2 & -1 & 0 & 1 \\ 4 & 1 & -2 & 5 \\ 3 & -1 & 0 & -1 \end{vmatrix} = 28$$
     (Eğer soruda $z$ yani 3. bilinmeyen sorulsaydı $b$ sütununu 3. sütuna yazacaktık). Buradan Cramer formülüyle:
     $$t = \frac{\det(A_4)}{\det(A)} = \frac{28}{14} = 2$$

> **Hocanın vurgusu:** Determinant hesaplanırken hangi yöntemi (satır işlemleri, sütun işlemleri, Sarrus veya Laplace açılımı) kullandığınız önemli değildir; önemli olan determinantı hatasız hesaplamaktır. Genişletilmiş matriste sistem çözerken yalnızca satır işlemleri yapılabilirken, determinant hesabında hem satır hem sütun işlemleri kullanılabilir.

### 2.2 Ters Matris Yöntemiyle $3 \times 3$ Sistemlerin Çözümü

#### Örnek 1: $3 \times 3$ Sistemin Ters Matrisle Çözümü

- **Verilen (ekrandan, 00:48:45, 00:49:10 ve 00:53:30):**
  $$\begin{cases} 2x + y - z = 5 \\ x - y + z = 1 \\ x + y - 2z = 4 \end{cases}$$
  doğrusal denklem sisteminin çözümünü katsayılar matrisinin tersini ($A^{-1}$) kullanarak bulunuz.
- **Çözüm:**
  1. Katsayılar matrisi $A$ ve sağ taraf matrisi $B$:
     $$A = \begin{bmatrix} 2 & 1 & -1 \\ 1 & -1 & 1 \\ 1 & 1 & -2 \end{bmatrix}, \quad B = \begin{bmatrix} 5 \\ 1 \\ 4 \end{bmatrix}$$
  2. $\det(A)$ hesabı (1. satıra 2. satır eklenerek veya Laplace açılımıyla):
     $$\det(A) = \begin{vmatrix} 2 & 1 & -1 \\ 1 & -1 & 1 \\ 1 & 1 & -2 \end{vmatrix} \xrightarrow{R_1 + R_2 \to R_1} \begin{vmatrix} 3 & 0 & 0 \\ 1 & -1 & 1 \\ 1 & 1 & -2 \end{vmatrix} = 3\begin{vmatrix} -1 & 1 \\ 1 & -2 \end{vmatrix} = 3(2 - 1) = 3 \neq 0$$
     $\det(A) = 3 \neq 0$ olduğundan $A^{-1}$ mevcuttur.
  3. Ek matris ($\text{adj}(A) = \text{Ek}(A)$) ve $A^{-1}$:
     Çözüm kağıdında ek matris ve ters matris şu şekilde yazılmıştır:
     $$A^{-1} = \frac{1}{\det(A)}\text{adj}(A) = \frac{1}{3} \begin{bmatrix} 1 & 1 & 0 \\ 3 & -3 & -3 \\ -2 & -1 & -3 \end{bmatrix}$$
     ve $X = A^{-1}B$ çarpımı yapılmıştır:
     $$X = \begin{bmatrix} x \\ y \\ z \end{bmatrix} = \frac{1}{3} \begin{bmatrix} 1 & 1 & 0 \\ 3 & -3 & -3 \\ -2 & -1 & -3 \end{bmatrix} \begin{bmatrix} 5 \\ 1 \\ 4 \end{bmatrix} = \begin{bmatrix} 2 \\ 0 \\ -23/3 \end{bmatrix}$$

> **Ders sonrası not:** Çözüm kağıdında $A$ matrisinin $(1, 3)$ kofaktörü hesaplanırken $A_{13} = (-1)^{1+3}\begin{vmatrix} 1 & -1 \\ 1 & 1 \end{vmatrix} = 1 - (-1) = 2$ olması gerekirken ek matrisin 3. satır 1. sütununa sehven $-2$ yazılmıştır. Doğru ek matris $\text{adj}(A) = \begin{bmatrix} 1 & 1 & 0 \\ 3 & -3 & -3 \\ 2 & -1 & -3 \end{bmatrix}$ olup $B = [5, 1, 4]^T$ ile çarpıldığında $z = \frac{1}{3}(2\cdot 5 - 1\cdot 1 - 3\cdot 4) = \frac{-3}{3} = -1$, yani tam çözüm $(x, y, z) = (2, 0, -1)$ olarak bulunur.

#### Örnek 2: İkinci $3 \times 3$ Sistem

- **Verilen (ekrandan, 00:50:30):**
  $$\begin{cases} 3x - y + 2z = -2 \\ 7x + y + 3z = 2 \\ 2x + 5y - 3z = 7 \end{cases}$$
  denklem sistemini katsayılar matrisinin tersini kullanarak çözünüz.
- **Yöntem:** Sistem $A = \begin{bmatrix} 3 & -1 & 2 \\ 7 & 1 & 3 \\ 2 & 5 & -3 \end{bmatrix}$, $X = \begin{bmatrix} x \\ y \\ z \end{bmatrix}$ ve $B = \begin{bmatrix} -2 \\ 2 \\ 7 \end{bmatrix}$ biçiminde yazılıp $A^{-1} = \frac{1}{\det(A)}\text{adj}(A)$ hesaplanır ve $X = A^{-1}B$ çarpımıyla bilinmeyenler bulunur (hoca bu sorunun bir önceki soruyla tamamen aynı yapıda olduğunu belirterek adımlarını gösterip geçmiştir).

### 2.3 $4 \times 4$ Sistemde Cramer Kuralıyla $y$ Bilinmeyeninin Bulunması

- **Verilen (ekrandan, 00:51:25 ve 00:52:15):**
  Katsayılar matrisi $A = \begin{bmatrix} 1 & 1 & 3 & 0 \\ 0 & 1 & 2 & -1 \\ 0 & 1 & 0 & -5 \\ 2 & 0 & -1 & -2 \end{bmatrix}$ ve sağ taraf sabitler vektörü $b = \begin{bmatrix} 4 \\ 4 \\ 0 \\ 2 \end{bmatrix}$ olan $4 \times 4$ doğrusal sistemde $y$ bilinmeyenini Cramer kuralını kullanarak bulunuz.
- **Çözüm:**
  1. $\det(A)$ hesabı: $-2R_1 + R_4 \to R_4$ işlemiyle 1. sütundaki $(4,1)$ elemanı sıfırlanıp 1. sütuna göre Laplace açılımı yapıldığında ve ardından $5C_1 + C_3 \to C_3$ sütun işlemiyle 2. satıra göre açıldığında kağıtta $\det(A) = 16$ elde edilmiştir.
  2. $\det(A_2)$ hesabı: $y$ ikinci bilinmeyen olduğundan $A$'nın 2. sütununa $b = [4, 4, 0, 2]^T$ yazılarak:
     $$\det(A_2) = \begin{vmatrix} 1 & 4 & 3 & 0 \\ 0 & 4 & 2 & -1 \\ 0 & 0 & 0 & -5 \\ 2 & 2 & -1 & -2 \end{vmatrix} \xrightarrow{-2R_1 + R_4 \to R_4} \begin{vmatrix} 1 & 4 & 3 & 0 \\ 0 & 4 & 2 & -1 \\ 0 & 0 & 0 & -5 \\ 0 & -6 & -7 & -2 \end{vmatrix} = -80$$
     bulunur. Buradan:
     $$y = \frac{\det(A_2)}{\det(A)} = \frac{-80}{16} = -5$$

> **Ders sonrası not:** Çözüm kağıdında $\det(A)$ hesaplanırken $-2R_1 + R_4 \to R_4$ adımında 4. satırın 2. elemanı $-2(1) + 0 = -2$ yerine sehven $-4$ olarak yazılmış ve bu yüzden $\det(A) = 16$ çıkmıştır (gerçekte $-2$ ile hesaplandığında $\det(A) = 8$ ve $y = -80/8 = -10$ olur).

### 2.4 Sistemin Tutarlı (Consistent) Olması İçin $a, b, c$ Arasındaki Bağıntının Bulunması

- **Verilen (ekrandan, 00:57:00):**
  $$\begin{cases} x + 2y - 3z = a \\ 2x - 3y + z = b \\ x - y = c \end{cases}$$
  doğrusal denklem sisteminin **tutarlı** (consistent — yani en az bir çözüme sahip) olması için $a, b$ ve $c$ arasındaki bağıntıyı bulunuz.

- **Adım Adım Çözüm:**
  Hoca bu tür parametreli sorularda Cramer kuralı yerine **Gauss-Jordan / satır indirgeme yöntemini** kullanmanın çok daha kolay olduğunu vurguladı:
  1. Sistemin genişletilmiş matrisini yazalım:
     $$[A \mid b] = \begin{bmatrix} 1 & 2 & -3 & \mid & a \\ 2 & -3 & 1 & \mid & b \\ 1 & -1 & 0 & \mid & c \end{bmatrix}$$
  2. Elementer satır işlemleri uygulayarak ($-2R_1 + R_2 \to R_2$, $-R_1 + R_3 \to R_3$ ve ardından 2. satır yardımıyla 3. satırı sıfırlayarak) eşelon forma getirelim:
     $$[A \mid b] \sim \begin{bmatrix} 1 & 2 & -3 & \mid & a \\ 0 & 1 & -1 & \mid & (2a - b)/7 \\ 0 & 0 & 0 & \mid & (a + 3b - 7c)/21 \end{bmatrix}$$
  3. **Rank Karşılaştırması:**
     Sol taraftaki katsayılar matrisi $A$'nın 3. satırı tamamen sıfır olduğundan $\text{rank}(A) = 2$'dir. Sistemin tutarlı (çözümlü) olması için $\text{rank}[A \mid b] = \text{rank}(A) = 2$ olması gerekir. Eğer 3. satırın en sağındaki $\frac{a + 3b - 7c}{21}$ ifadesi sıfırdan farklı olursa $\text{rank}[A \mid b] = 3 \neq \text{rank}(A) = 2$ olur ve sistemin çözümü olmaz. Dolayısıyla sistemin tutarlı olması için gerek ve yeter şart:
     $$\frac{a + 3b - 7c}{21} = 0 \implies a + 3b - 7c = 0$$
     bağıntısının sağlanmasıdır.

### 2.5 $t$ Parametresine Göre Çözümsüz, Tek Çözümlü ve Sonsuz Çözümlü Olma Analizi

- **Verilen (ekrandan, 00:59:30, 01:02:30 ve 01:05:15):**
  $$\begin{cases} 3x + 4y - 2tz = 0 \\ 2x + 3y - tz = 1 \\ tx + (t+1)y - 6z = -1 \end{cases}$$
  doğrusal denklem sisteminin:
  a) Çözümsüz (inconsistent),
  b) Tek çözümlü (unique solution),
  c) Sonsuz çözümlü (infinitely many solutions)
  olması için tüm "$t$" değerlerini belirleyiniz.

- **Adım Adım Çözüm:**
  1. **Genişletilmiş Matrisin Eşelon Forma İndirgenmesi:**
     $$[A \mid B] = \begin{bmatrix} 3 & 4 & -2t & \mid & 0 \\ 2 & 3 & -t & \mid & 1 \\ t & t+1 & -6 & \mid & -1 \end{bmatrix} \xrightarrow{R_1 - R_2 \to R_1} \begin{bmatrix} 1 & 1 & -t & \mid & -1 \\ 2 & 3 & -t & \mid & 1 \\ t & t+1 & -6 & \mid & -1 \end{bmatrix}$$
     $-2R_1 + R_2 \to R_2$ ve $-tR_1 + R_3 \to R_3$ işlemleri uygulandığında:
     $$\sim \begin{bmatrix} 1 & 1 & -t & \mid & -1 \\ 0 & 1 & t & \mid & 3 \\ 0 & 1 & t^2 - 6 & \mid & t - 1 \end{bmatrix} \xrightarrow{R_3 - R_2 \to R_3} \begin{bmatrix} 1 & 1 & -t & \mid & -1 \\ 0 & 1 & t & \mid & 3 \\ 0 & 0 & t^2 - t - 6 & \mid & t - 4 \end{bmatrix}$$
     $t^2 - t - 6 = (t - 3)(t + 2)$ olarak çarpanlarına ayrıldığında eşelon form:
     $$\begin{bmatrix} 1 & 1 & -t & \mid & -1 \\ 0 & 1 & t & \mid & 3 \\ 0 & 0 & (t - 3)(t + 2) & \mid & t - 4 \end{bmatrix}$$
     halini alır. Burada bilinmeyen sayısı $n = 3$'tür.
  2. **a) Çözümsüz Olma Koşulu ($\text{rank}(A) \neq \text{rank}[A \mid B]$):**
     Son satırda $(t - 3)(t + 2) = 0$ olurken sağ taraftaki $t - 4 \neq 0$ olursa, $\text{rank}(A) = 2$ ve $\text{rank}[A \mid B] = 3$ olur.
     $$(t - 3)(t + 2) = 0 \implies t = -2 \text{ veya } t = 3$$
     Bu değerler için $t - 4 \neq 0$ olduğundan, **$t = -2$ veya $t = 3$** için sistemin **çözümü yoktur** (inconsistent).
  3. **b) Tek Çözümlü Olma Koşulu ($\text{rank}(A) = \text{rank}[A \mid B] = n = 3$):**
     Son satırdaki $(t - 3)(t + 2)$ katsayısı sıfırdan farklı olduğunda hem $A$'nın hem de $[A \mid B]$'nin rankı $3$'e (bilinmeyen sayısına) eşit olur:
     $$(t - 3)(t + 2) \neq 0 \implies t \neq -2 \text{ ve } t \neq 3 \quad (t \in \mathbb{R} \setminus \{-2, 3\})$$
     için sistemin **tek çözümü vardır**.
  4. **c) Sonsuz Çözümlü Olma Koşulu ($\text{rank}(A) = \text{rank}[A \mid B] = r < 3$):**
     Sonsuz çözüm olması için 3. satırın hem sol tarafının hem de sağ tarafının **aynı anda sıfır** olması (böylece $\text{rank}(A) = \text{rank}[A \mid B] = 2 < 3$ olması) gerekir:
     $$(t - 3)(t + 2) = 0 \quad \text{ve} \quad t - 4 = 0$$
     Ancak $t - 4 = 0$ yapan değer $t = 4$'tür ve $t = 4$ değeri $(t - 3)(t + 2)$'yi sıfır yapmaz; $t = 3$ ve $t = -2$ değerleri de $t - 4$'ü sıfır yapmaz. Dolayısıyla her iki ifadeyi aynı anda sıfır yapan **hiçbir $t$ değeri yoktur**; sistem hiçbir $t$ değeri için sonsuz çözümlü olamaz.

## 3. Vektörler, Alan, Hacim ve Düzlemsellik Genel Tekrarı ve Sınav Soruları

### 3.1 Norm, Birim Vektör, Standart Baz Vektörleri ve İç Çarpım Tekrarı

- **İki Nokta Arasındaki Vektör ve Norm ($\mathbb{R}^3$):** $P(a_0, b_0, c_0)$ başlangıç ve $Q(a_1, b_1, c_1)$ bitiş noktaları için:
  $$\vec{PQ} = (a_1 - a_0, \, b_1 - b_0, \, c_1 - c_0), \quad \|\vec{PQ}\| = \sqrt{(a_1 - a_0)^2 + (b_1 - b_0)^2 + (c_1 - c_0)^2}$$
- **Birim Vektör:** Normu $1$ olan vektördür. Sıfırdan farklı her $\vec{v}$ vektörü kendi normuna bölünerek $\frac{\vec{v}}{\|\vec{v}\|}$ birim vektörü elde edilir.
- **Standart Baz Vektörleri:** $\mathbb{R}^3$'te $\vec{i} = (1, 0, 0), \, \vec{j} = (0, 1, 0), \, \vec{k} = (0, 0, 1)$ olup her $\vec{v} = (a, b, c) \in \mathbb{R}^3$ vektörü $\vec{v} = a\vec{i} + b\vec{j} + c\vec{k}$ doğrusal birleşimi olarak yazılır.
- **İç Çarpım (Dot / Inner / Scalar Product — $\mathbb{R}^n$):** $\vec{u}, \vec{v} \in \mathbb{R}^n$ için $\vec{u} \cdot \vec{v} = u_1 v_1 + \dots + u_n v_n \in \mathbb{R}$ (sonucu bir reel sayıdır). Aralarındaki açı $\theta$ olmak üzere:
  $$\vec{u} \cdot \vec{v} = \|\vec{u}\| \|\vec{v}\| \cos\theta \implies \vec{u} \perp \vec{v} \iff \vec{u} \cdot \vec{v} = 0$$

### 3.2 Vektörel Çarpım, Üçgenin Alanı ve Paralelkenarın Alanı

**Vektörel Çarpım (Cross / Vector Product):** Yalnızca $\mathbb{R}^3$'te tanımlıdır, sonucu hem $\vec{u}$'ya hem $\vec{v}$'ye dik olan bir vektördür ve $\begin{vmatrix} \vec{i} & \vec{j} & \vec{k} \\ u_1 & u_2 & u_3 \\ v_1 & v_2 & v_3 \end{vmatrix}$ determinantıyla hesaplanır. Normu $\|\vec{u} \times \vec{v}\| = \|\vec{u}\| \|\vec{v}\| \sin\theta$'dır.

> **Hocanın vurgusu (Üçgen ve Paralelkenar Alanı — ekrandan, 01:19:30):**
> $\mathbb{R}^3$ uzayında komşu kenarları (adjacent sides) $\vec{u}$ ve $\vec{v}$ vektörleri olan:
> 1. **Üçgenin Alanı (Area of a Triangle):**
>    $$B = \frac{1}{2} \|\vec{u} \times \vec{v}\|$$
> 2. **Paralelkenarın Alanı (Area of a Parallelogram):** Paralelkenar iki eş üçgenden oluştuğu için üçgenin alanının $2$ katıdır:
>    $$A = 2B = \|\vec{u} \times \vec{v}\|$$

### 3.3 Karma Çarpım, Paralelkenar Prizmanın Hacmi, Aynı Düzlemde Bulunma (Coplanarity) ve İkili Vektörel Çarpım

- **Karma Çarpım (Scalar Triple Product) ve Prizma Hacmi (ekrandan, 01:23:00):**
  $\vec{u}, \vec{v}, \vec{w} \in \mathbb{R}^3$ vektörleri tarafından oluşturulan paralelkenar prizmanın (parallelepiped) hacmi, karma çarpımın mutlak değerine eşittir:
  $$V = \left|\vec{u} \cdot (\vec{v} \times \vec{w})\right| = \left|\det\begin{bmatrix} u_1 & u_2 & u_3 \\ v_1 & v_2 & v_3 \\ w_1 & w_2 & w_3 \end{bmatrix}\right|$$
- **Üç Vektörün Aynı Düzlemde Yer Alması (Coplanarity — Çok Önemli, ekrandan, 01:23:00):**
  $\vec{u}, \vec{v}, \vec{w} \in \mathbb{R}^3$ vektörlerinin **aynı düzlemde yer alabilmesi** (lie in the same plane / coplanar) için gerek ve yeter şart, bu üç vektör tarafından oluşturulan paralelkenar prizmanın hacminin (yani karma çarpımlarının) **sıfır** olmasıdır:
  $$\vec{u}, \vec{v}, \vec{w} \text{ aynı düzlemdedir} \iff \vec{u} \cdot (\vec{v} \times \vec{w}) = 0$$
- **İkili Vektörel Çarpım:** $\vec{u} \times (\vec{v} \times \vec{w}) = (\vec{u} \cdot \vec{w})\vec{v} - (\vec{u} \cdot \vec{v})\vec{w}$.

### 3.4 Vektörler Üzerine Örnek Sınav Soruları (Düzlemsellik ve Düzleme Dik Vektör Bulma)

#### Örnek Sınav Sorusu 1 (Soru 4): Üç Vektörün Aynı Düzlemde Olup Olmadığının Belirlenmesi

- **Verilen (ekrandan, 01:24:30):**
  $\vec{a} = (1, 4, -7)$, $\vec{b} = (2, -1, 4)$ ve $\vec{c} = (0, -9, 18)$ vektörlerinin aynı düzlemde yer alıp almadığını (lie in the same plane or not) belirleyiniz.
- **Çözüm:**
  Bu üç vektörün oluşturduğu paralelkenar prizmanın hacmi (karma çarpımı) sıfırsa aynı düzlemdedirler, sıfırdan farklıysa aynı düzlemde değildirler. Karma çarpımı determinantla hesaplayalım:
  $$\vec{a} \cdot (\vec{b} \times \vec{c}) = \begin{vmatrix} 1 & 4 & -7 \\ 2 & -1 & 4 \\ 0 & -9 & 18 \end{vmatrix}$$
  1. sütuna göre Laplace açılımı yaparsak:
  $$= 1 \cdot \begin{vmatrix} -1 & 4 \\ -9 & 18 \end{vmatrix} - 2 \cdot \begin{vmatrix} 4 & -7 \\ -9 & 18 \end{vmatrix} + 0 = 1(-18 - (-36)) - 2(72 - 63) = 18 - 18 = 0$$
  Hacim (karma çarpım) $0$ olduğundan $\vec{a}, \vec{b}, \vec{c}$ vektörleri **aynı düzlemde yer alır** (they lie in the same plane).

#### Örnek Sınav Sorusu 2 (Soru 5): Üç Noktayı İçeren Düzleme Dik Vektör Bulma

- **Verilen (ekrandan, 01:26:30):**
  $P = (3, 0, 1)$, $Q = (4, -2, 1)$ ve $R = (5, 3, -1)$ noktalarını içeren düzleme **dik (orthogonal)** olan bir vektör bulunuz.
- **Çözüm:**
  1. Önce verilen üç noktayı kullanarak düzlemin içinde yer alan (düzleme paralel olan) iki vektör, örneğin $\vec{PQ}$ ve $\vec{PR}$ vektörlerini oluşturalım:
     $$\vec{PQ} = Q - P = (4 - 3, \, -2 - 0, \, 1 - 1) = (1, -2, 0)$$
     $$\vec{PR} = R - P = (5 - 3, \, 3 - 0, \, -1 - 1) = (2, 3, -2)$$
  2. İki vektörün vektörel çarpımı ($\vec{PQ} \times \vec{PR}$) başlangıçtaki her iki vektöre de dik ($\vec{PQ} \times \vec{PR} \perp \vec{PQ}$ ve $\vec{PQ} \times \vec{PR} \perp \vec{PR}$) olduğundan, bu düzleme de dik olacaktır:
     $$\vec{PQ} \times \vec{PR} = \begin{vmatrix} \vec{i} & \vec{j} & \vec{k} \\ 1 & -2 & 0 \\ 2 & 3 & -2 \end{vmatrix} = \vec{i}\begin{vmatrix} -2 & 0 \\ 3 & -2 \end{vmatrix} - \vec{j}\begin{vmatrix} 1 & 0 \\ 2 & -2 \end{vmatrix} + \vec{k}\begin{vmatrix} 1 & -2 \\ 2 & 3 \end{vmatrix}$$
     $$= (4 - 0)\vec{i} - (-2 - 0)\vec{j} + (3 - (-4))\vec{k} = 4\vec{i} + 2\vec{j} + 7\vec{k} = (4, 2, 7)$$

## 4. Vektör Uzayları ve Altuzaylar Genel Tekrarı (Rasyonel Sayılar Kümesi Örneği)

Dersin son bölümünde hoca bir kümenin reel vektör uzayı olması için gereken 10 koşulu (toplamaya göre kapalılık, değişme, birleşme, toplamsal birim / sıfır elemanı, toplamsal ters; skalerle çarpmaya göre kapalılık, iki dağılma özelliği, birleşme ve birim skaler özelliği) ve kontrol sırasını (önce iki kapalılık, sonra sıfır elemanı) hatırlattı (ekrandan, 01:27:15–01:32:30):

- **Vektör Uzayı Olan Kümeler:** $(\mathbb{R}, +, \cdot)$, $(\mathbb{R}^n, +, \cdot)$ ve $(M_{m \times n}(\mathbb{R}), +, \cdot)$.
- **Rasyonel Sayılar Kümesi $(\mathbb{Q}, +, \cdot)$ Neden Reel Vektör Uzayı Değildir? (ekrandan, 01:31:00):**
  Rasyonel sayılar kümesi $\mathbb{Q}$, olağan toplama ve olağan çarpma işlemleri altında bir reel vektör uzayı **değildir**. Çünkü $\mathbb{R}$'den irrasyonel bir skaler (örneğin $c = \sqrt{2} \in \mathbb{R}$) alıp $\mathbb{Q}$'daki sıfırdan farklı bir rasyonel sayıyla çarptığımızda sonuç $\mathbb{Q}$'nun bir elemanı olmaz ($\sqrt{2}q \notin \mathbb{Q}$). Yani $\mathbb{Q}$ kümesi reel skalerle çarpma işlemi altında **kapalı değildir**.
- **Alt Vektör Uzayı (Altuzay) Testi:** $(V, \oplus, \odot)$ bir vektör uzayı ve $\emptyset \neq W \subseteq V$ boş olmayan bir alt küme olmak üzere, her $\mathbf{u}, \mathbf{v} \in W$ için $\mathbf{u} \oplus \mathbf{v} \in W$ ve her $c \in \mathbb{R}, \mathbf{u} \in W$ için $c \odot \mathbf{u} \in W$ sağlanıyorsa $W$, $V$'nin bir altuzayıdır.

## Örnek Sorular

1. **$4 \times 4$ Doğrusal Sistemde Cramer Kuralı Uygulaması** (ekrandan, 00:44:30)
   - **Soru:** $\begin{cases} x - 2z + t = 2 \\ 2x - y + 3t = 1 \\ 4x + y - 2z = 5 \\ 3x - y + 2t = -1 \end{cases}$ denklem sisteminde sadece $t$ bilinmeyenini Cramer yöntemiyle bulunuz.
   - **Çözüm (derste verildi):** Katsayılar matrisinin determinantı $\det(A) = \begin{vmatrix} 1 & 0 & -2 & 1 \\ 2 & -1 & 0 & 3 \\ 4 & 1 & -2 & 0 \\ 3 & -1 & 0 & 2 \end{vmatrix} = 14$ ve 4. sütuna $b = [2, 1, 5, -1]^T$ yazıldığında $\det(A_4) = 28$ bulunur. Buradan $t = \frac{\det(A_4)}{\det(A)} = \frac{28}{14} = 2$'dir.

2. **Doğrusal Sistemin Tutarlı Olma Koşulu** (ekrandan, 00:57:00)
   - **Soru:** $\begin{cases} x + 2y - 3z = a \\ 2x - 3y + z = b \\ x - y = c \end{cases}$ doğrusal sisteminin tutarlı (consistent) olması için $a, b$ ve $c$ arasındaki bağıntıyı bulunuz.
   - **Çözüm (derste verildi):** Genişletilmiş matris satır işlemleriyle $\begin{bmatrix} 1 & 2 & -3 & \mid & a \\ 0 & 1 & -1 & \mid & (2a - b)/7 \\ 0 & 0 & 0 & \mid & (a + 3b - 7c)/21 \end{bmatrix}$ eşelon formuna indirgenir. $\text{rank}(A) = 2$ olduğundan sistemin tutarlı olması için $\text{rank}[A \mid b] = 2$ olmalı, yani $\frac{a + 3b - 7c}{21} = 0 \implies a + 3b - 7c = 0$ olmalıdır.

3. **Parametreli Sistemin Çözüm Durumlarının İncelenmesi** (ekrandan, 00:59:30 ve 01:02:30)
   - **Soru:** $\begin{cases} 3x + 4y - 2tz = 0 \\ 2x + 3y - tz = 1 \\ tx + (t+1)y - 6z = -1 \end{cases}$ sisteminin a) Çözümsüz, b) Tek çözümlü, c) Sonsuz çözümlü olması için tüm $t$ değerlerini bulunuz.
   - **Çözüm (derste verildi):** Genişletilmiş matris $\begin{bmatrix} 1 & 1 & -t & \mid & -1 \\ 0 & 1 & t & \mid & 3 \\ 0 & 0 & (t - 3)(t + 2) & \mid & t - 4 \end{bmatrix}$ formuna indirgenir.
     - a) Çözümsüz: $t = -2$ veya $t = 3$ ($\text{rank}(A) = 2 \neq \text{rank}[A \mid B] = 3$).
     - b) Tek çözümlü: $t \in \mathbb{R} \setminus \{-2, 3\}$ ($\text{rank}(A) = \text{rank}[A \mid B] = 3 = n$).
     - c) Sonsuz çözümlü: $(t-3)(t+2) = 0$ ve $t - 4 = 0$ şartlarını aynı anda sağlayan bir $t$ olmadığından hiçbir $t$ değeri için sonsuz çözüm yoktur.

4. **Üç Vektörün Aynı Düzlemde Olması ve Üç Noktadan Geçen Düzleme Dik Vektör** (ekrandan, 01:24:30 ve 01:26:30)
   - **Soru:**
     a) $\vec{a} = (1, 4, -7)$, $\vec{b} = (2, -1, 4)$ ve $\vec{c} = (0, -9, 18)$ vektörleri aynı düzlemde midir?
     b) $P(3, 0, 1)$, $Q(4, -2, 1)$ ve $R(5, 3, -1)$ noktalarını içeren düzleme dik bir vektör bulunuz.
   - **Çözüm (derste verildi):**
     - a) $\vec{a} \cdot (\vec{b} \times \vec{c}) = \begin{vmatrix} 1 & 4 & -7 \\ 2 & -1 & 4 \\ 0 & -9 & 18 \end{vmatrix} = 0$ olduğundan aynı düzlemdedirler.
     - b) $\vec{PQ} = (1, -2, 0)$ ve $\vec{PR} = (2, 3, -2)$ vektörlerinin vektörel çarpımı $\vec{PQ} \times \vec{PR} = 4\vec{i} + 2\vec{j} + 7\vec{k} = (4, 2, 7)$ düzleme diktir.

## Dersin Toparlaması

Bu derste ikinci ara sınav öncesinde doğrusal denklem sistemlerinin üç çözüm yöntemi (Gauss-Jordan indirgemesi ve rank analizi, Cramer kuralı, ters matris yöntemi), homojen sistemlerin çözüm yapısı, $\mathbb{R}^n$ ve $\mathbb{R}^3$'te vektör işlemleri (norm, birim vektör, iç çarpım, vektörel çarpım, üçgen ve paralelkenar alanı, karma çarpım, paralelkenar prizma hacmi ve üç vektörün aynı düzlemde olma koşulu) ile vektör uzayları ve altuzaylar baştan sona tekrar edilmiş; her konu başlığı için örnek sınav soruları adım adım çözülmüştür.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
