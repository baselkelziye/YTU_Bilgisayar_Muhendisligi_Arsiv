# Ders 5 Genişletilmiş Notu: Determinantın Özellikleri, Üçgensel Matrise İndirgeme, Ek Matris (Adjoint Matrix) ve Determinant ile Ters Matris Bulma

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Determinantın Temel Özellikleri (Properties of Determinants)
  - 1.1 Birim Matrisin Determinantı ve Satır/Sütun Yer Değiştirme
  - 1.2 Bir Satır veya Sütunun Skalerle Çarpılması ve Doğrusallık
  - 1.3 İki Satır veya Sütunun Eşit Olması
  - 1.4 Bir Satırın Katının Başka Bir Satıra Eklenmesi, Sıfır Satırı ve Üçgensel Matrisler
- 2. Matris İşlemlerinin Determinantı ve Elementer İşlem Özeti
  - 2.1 Çarpım, Ters Matris, Kuvvet, Skaler Çarpım ve Transpozun Determinantı
  - 2.2 Elementer Satır İşlemlerinin Determinanta Etkisinin Özeti
- 3. Determinant Özellikleriyle Çarpanlara Ayırma ve Üçgensel Matrise İndirgeme
  - 3.1 Sembolik (Harfli) Determinantı Çarpanlarına Ayırma Örneği
  - 3.2 Üçgensel Matrise İndirgeme (Reduction to Triangular Matrix) Örneği
  - 3.3 Sarrus Kuralı (Rule of Sarrus) Hatırlatması ve Örneği
- 4. Ek Matris (Adjoint Matrix) ve Determinant Yardımıyla Ters Matris Bulma
  - 4.1 Ek Matrisin (Adjoint / Adjugate Matrix) Tanımı
  - 4.2 Ek Matris Hesaplama Örneği ve $A \cdot \text{adj}(A) = \det(A)I_n$ Teoremi
  - 4.3 Ek Matris Yardımıyla Ters Matris ($A^{-1}$) Bulma Formülü ve Örneği
- Örnek Sorular
- Dersin Toparlaması

## 1. Determinantın Temel Özellikleri (Properties of Determinants)

Hoca derse bir önceki haftada işlenen determinant kavramını hatırlatarak başladı ve bir matrisin determinantını hızlı ve pratik biçimde hesaplamak için büyük önem taşıyan **determinantın özelliklerini** (properties of determinants) tek tek örnekleriyle açıkladı.

### 1.1 Birim Matrisin Determinantı ve Satır/Sütun Yer Değiştirme

1. **Birim Matrisin Determinantı:** Boyutu ne olursa olsun her $I_n$ birim matrisinin (identity matrix) determinantı $1$'e eşittir (ekrandan, 00:06:30):
   $$\det(I) = 1$$
   Örneğin $2 \times 2$ boyutlu $I_2 = \begin{pmatrix} 1 & 0 \\ 0 & 1 \end{pmatrix}$ birim matrisinde esas köşegen elemanlarının çarpımından yedek köşegen elemanlarının çarpımı çıkarıldığında:
   $$\begin{vmatrix} 1 & 0 \\ 0 & 1 \end{vmatrix} = 1 \cdot 1 - 0 \cdot 0 = 1$$
   elde edilir.

2. **İki Satırın veya İki Sütunun Yer Değiştirmesi:** Bir matrisin herhangi iki satırının veya herhangi iki sütununun yeri birbiriyle değiştirilirse (exchange two rows or columns), determinantın işareti tersine döner (pozitiften negatife veya negatiften pozitife geçer).
   - **Örnek:** 1. özellikten $\begin{vmatrix} 1 & 0 \\ 0 & 1 \end{vmatrix} = 1$ olduğunu biliyoruz. Bu matrisin 1. sütunu ile 2. sütununun (veya 1. satırı ile 2. satırının) yerini değiştirdiğimizde elde edilen matrisin determinantı $-1$ olur (ekrandan, 00:06:30):
     $$\begin{vmatrix} 0 & 1 \\ 1 & 0 \end{vmatrix} = 0 \cdot 0 - 1 \cdot 1 = -1$$

### 1.2 Bir Satır veya Sütunun Skalerle Çarpılması ve Doğrusallık

3. **Bir Satır veya Sütunun Skaler ile Çarpılması:** Eğer bir $B$ matrisi, bir $A$ kare matrisinin **tek bir satırının veya tek bir sütununun** bir $t \in \mathbb{R}$ reel sayısı (skaleri) ile çarpılmasıyla elde ediliyorsa, $B$'nin determinantı $A$'nın determinantının $t$ katına eşittir:
   $$\det(B) = t \det(A)$$
   Örneğin $2 \times 2$ boyutlu $A = \begin{pmatrix} a & b \\ c & d \end{pmatrix}$ matrisinin 1. satırı $t$ ile çarpıldığında (ekrandan, 00:06:30):
   $$\begin{vmatrix} ta & tb \\ c & d \end{vmatrix} = t \begin{vmatrix} a & b \\ c & d \end{vmatrix}$$
   olur. Tersinden bakıldığında bu özellik, bir satır veya sütundaki ortak bir $t$ çarpanının determinantın dışına çarpan olarak çıkarılabileceği (factor out) anlamına gelir.

4. **Satırlar (veya Sütunlar) Üzerinde Doğrusallık Özelliği:** Determinant fonksiyonu matrisin satırları (veya sütunları) üzerinde doğrusal (lineer) bir fonksiyon ($f(x+y) = f(x) + f(y)$) gibi davranır. Bir satırın elemanları iki terimin toplamı biçimindeyse, determinant diğer satırları aynı kalmak koşuluyla iki ayrı determinantın toplamı olarak yazılabilir:
   $$\begin{vmatrix} a + a' & b + b' \\ c & d \end{vmatrix} = \begin{vmatrix} a & b \\ c & d \end{vmatrix} + \begin{vmatrix} a' & b' \\ c & d \end{vmatrix}$$

- **Ortak Çarpan Parantezine Alma Örneği (ekrandan, 00:12:25 ve 00:16:15):**
  $$\begin{vmatrix} 2 & 6 \\ 1 & 12 \end{vmatrix}$$
  determinantını özellik 3'ü kullanarak hesaplayalım:
  - 1. satırdaki elemanlar ($2$ ve $6$) $2$'nin katıdır. 1. satırdan $2$ ortak çarpanını determinantın dışına çıkarırsak (1. satırı $2$'ye bölersek):
    $$\begin{vmatrix} 2 & 6 \\ 1 & 12 \end{vmatrix} = 2 \begin{vmatrix} 1 & 3 \\ 1 & 12 \end{vmatrix}$$
  - Şimdi kalan matrisin 2. sütunundaki elemanlar ($3$ ve $12$) $3$'ün katıdır. 2. sütundan da $3$ çarpanını dışarı çıkarırsak (2. sütunu $3$'e bölersek: $3/3=1$ ve $12/3=4$):
    $$= 2 \cdot 3 \begin{vmatrix} 1 & 1 \\ 1 & 4 \end{vmatrix}$$
  - Kalan $2 \times 2$ determinant $\begin{vmatrix} 1 & 1 \\ 1 & 4 \end{vmatrix} = 1 \cdot 4 - 1 \cdot 1 = 3$ olduğundan:
    $$= 2 \cdot 3 \cdot 3 = 18$$
    bulunur.

**Soru:** İkinci adımda $3$ ve $12$ nasıl $1$ ve $4$'e dönüştü?
**Cevap:** İlk adımda 1. satır $2$'nin katı olduğu için 1. satırdan $2$'yi dışarı çıkardık ve 1. satır $(1\ \ 3)$ oldu. İkinci adımda ise 2. sütun $(3\ \ 12)^T$ elemanlarından oluşuyor ve her ikisi de $3$'ün katı; bu sütundan $3$'ü çarpan olarak dışarı çıkardığımızda sütundaki elemanları $3$'e bölmüş oluyoruz ($3/3 = 1$ ve $12/3 = 4$).

### 1.3 İki Satır veya Sütunun Eşit Olması

5. **İki Satırı veya İki Sütunu Eşit Olan Matrisin Determinantı:** Bir kare matrisin herhangi iki satırı veya herhangi iki sütunu birbirine eşitse, o matrisin determinantı **sıfırdır** ($\det(A) = 0$) (ekrandan, 00:16:15).

- **Örnek (ekrandan, 00:16:15):**
  $$\begin{vmatrix} 1 & 2 & 3 \\ 1 & 5 & 3 \\ 2 & 8 & 6 \end{vmatrix}$$
  determinantını Sarrus kuralıyla uzun uzun hesaplamak yerine determinant özelliklerini kullanalım. 3. sütundaki $(3, 3, 6)$ elemanlarının tamamı $3$'ün katıdır. 3. sütunu $3$ ortak çarpanı parantezine alırsak:
  $$\begin{vmatrix} 1 & 2 & 3 \\ 1 & 5 & 3 \\ 2 & 8 & 6 \end{vmatrix} = 3 \begin{vmatrix} 1 & 2 & 1 \\ 1 & 5 & 1 \\ 2 & 8 & 2 \end{vmatrix}$$
  Elde edilen determinantta 1. sütun $(1, 1, 2)^T$ ile 3. sütun $(1, 1, 2)^T$ birbirine tamamen eşittir. İki sütunu eşit olan matrisin determinantı $0$ olduğundan:
  $$= 3 \cdot 0 = 0$$
  sonucuna hemen ulaşılır.

### 1.4 Bir Satırın Katının Başka Bir Satıra Eklenmesi, Sıfır Satırı ve Üçgensel Matrisler

6. **Bir Satırın (veya Sütunun) Katının Başka Bir Satıra (veya Sütuna) Eklenmesi:** Bir $B$ matrisi, $A$ matrisinin $s$. satırının (veya sütununun) $t$ katının $r$. satırına (veya sütununa) ($r \neq s$) eklenmesiyle elde ediliyorsa **determinant değişmez**:
   $$\det(B) = \det(A)$$
   - **Örnek (ekrandan, 00:23:10):**
     $$\begin{vmatrix} 1 & 2 & 3 \\ 2 & -1 & 3 \\ 1 & 0 & 1 \end{vmatrix} = \begin{vmatrix} 5 & 0 & 9 \\ 2 & -1 & 3 \\ 1 & 0 & 1 \end{vmatrix}$$
     Bu iki determinant birbirine eşittir; çünkü sağdaki matris, soldaki matrisin 2. satırının $2$ katının 1. satıra eklenmesiyle ($2r_2 + r_1 \to r_1$: $2(2)+1=5$, $2(-1)+2=0$, $2(3)+3=9$) elde edilmiştir.

7. **Sıfır Satırı veya Sütunu Bulunan Matris:** Bir $A$ matrisinin tamamen sıfırlardan oluşan bir satırı veya sütunu varsa determinantı sıfırdır ($\det(A) = 0$).

8. **Üçgensel Matrisin Determinantı:** Üst üçgensel (upper triangular) veya alt üçgensel (lower triangular) bir matrisin determinantı, **esas köşegen (main diagonal) üzerindeki elemanların çarpımına** eşittir:
   $$\det(A) = a_{11} \cdot a_{22} \cdots a_{nn}$$

## 2. Matris İşlemlerinin Determinantı ve Elementer İşlem Özeti

### 2.1 Çarpım, Ters Matris, Kuvvet, Skaler Çarpım ve Transpozun Determinantı

Hoca $n \times n$ boyutlu $A$ ve $B$ kare matrisleri için matris cebiri işlemlerinin determinantla ilişkisini şu kurallarla açıkladı (ekrandan, 00:28:30):

- **Çarpımın Determinantı:** İki matrisin çarpımının determinantı, determinantlarının çarpımına eşittir:
  $$\det(AB) = \det(A)\det(B)$$
- **Ters Matrisin Determinantı:** $A$ tersinir (nonsingular) bir matris ise $A^{-1}A = I$ olduğundan her iki tarafın determinantı alındığında $\det(A^{-1})\det(A) = \det(I) = 1$ olur ve buradan:
  $$\det(A^{-1}) = \frac{1}{\det(A)}$$
  elde edilir. (Eğer $A$ tekil / singular bir matris ise $A^{-1}$ mevcut değildir ve $\det(A^{-1})$ tanımsızdır.)
- **Matrisin Karesinin (ve Kuvvetinin) Determinantı:** $\det(AB) = \det(A)\det(B)$ özelliğinde $B = A$ alınırsa:
  $$\det(A^2) = (\det(A))^2$$
- **Skalerle Çarpılan Matrisin Determinantı:** $A$ matrisi $n \times n$ boyutlu bir kare matris ve $k$ bir skaler olmak üzere:
  $$\det(kA) = k^n \det(A)$$
  - **İspat:** Bir $A$ matrisini $2$ (veya genel olarak $k$) skaleri ile çarpmak, matrisin **tüm elemanlarını** —yani $n$ adet satırının her birini— $k$ ile çarpmak demektir:
    $$kA = \begin{pmatrix} k a_{11} & k a_{12} & \cdots & k a_{1n} \\ k a_{21} & k a_{22} & \cdots & k a_{2n} \\ \vdots & \vdots & \ddots & \vdots \\ k a_{n1} & k a_{n2} & \cdots & k a_{nn} \end{pmatrix}$$
    Determinant özelliğine göre her bir satırdaki ortak $k$ çarpanı determinantın dışına ayrı ayrı çıkar. Matriste $n$ tane satır bulunduğundan dışarıya $n$ adet $k$'nın çarpımı, yani $k^n$ çıkar:
    $$\det(kA) = \underbrace{k \cdot k \cdots k}_{n \text{ tane}} \det(A) = k^n \det(A)$$
    Özel olarak $\det(2A) = 2^n \det(A)$ olur.
- **Transpozun Determinantı:** Bir matrisin transpozunun determinantı kendi determinantına eşittir:
  $$\det(A^T) = \det(A)$$
  Örneğin $2 \times 2$ boyutlu $A = \begin{pmatrix} a & b \\ c & d \end{pmatrix}$ ve $A^T = \begin{pmatrix} a & c \\ b & d \end{pmatrix}$ için $\det(A) = ad - bc$ ve $\det(A^T) = ad - cb = ad - bc$ olup ikisi birbirine eşittir.

### 2.2 Elementer Satır İşlemlerinin Determinanta Etkisinin Özeti

Hoca üç temel elementer satır işleminin determinant üzerindeki etkisini tahtaya özet olarak yazdı (ekrandan, 00:31:30):

1. $i$. ve $j$. satırların yer değiştirmesi ($i \neq j$):
   $$\det(A_{r_i \leftrightarrow r_j}) = -\det(A)$$
2. $i$. satırın $k$ skaleri ile çarpılması:
   $$\det(A_{k r_i \to r_i}) = k \det(A)$$
3. $i$. satırın $k$ katının $j$. satıra eklenmesi ($i \neq j$):
   $$\det(A_{k r_i + r_j \to r_j}) = \det(A)$$

## 3. Determinant Özellikleriyle Çarpanlara Ayırma ve Üçgensel Matrise İndirgeme

### 3.1 Sembolik (Harfli) Determinantı Çarpanlarına Ayırma Örneği

Hoca determinant özelliklerinin bilinmeyenler içeren determinantları çarpanlarına ayırmada nasıl kullanıldığını aşağıdaki örnekle gösterdi (ekrandan, 00:41:40):

- **Verilen:** Determinant özelliklerini kullanarak aşağıdaki determinantı çarpanlarına ayırınız (factorize):
  $$\begin{vmatrix} x+y & z & t \\ z & x+y & t \\ z & t & x+y \end{vmatrix}$$

- **1. Adım (Sütunları toplayarak ortak çarpan oluşturma):**
  Dikkat edilirse her satırda bir adet $x+y$, bir adet $z$ ve bir adet $t$ terimi bulunmaktadır. 2. ve 3. sütunları 1. sütuna eklersek ($c_1 + c_2 + c_3 \to c_1$), determinantın değeri değişmez ve 1. sütundaki tüm elemanlar $x+y+z+t$ olur:
  $$\begin{vmatrix} x+y & z & t \\ z & x+y & t \\ z & t & x+y \end{vmatrix} \xrightarrow{c_1 + c_2 + c_3 \to c_1} \begin{vmatrix} x+y+z+t & z & t \\ x+y+z+t & x+y & t \\ x+y+z+t & t & x+y \end{vmatrix}$$

- **2. Adım (1. sütunu ortak çarpan parantezine alma):**
  1. sütunun tüm elemanları $x+y+z+t$ olduğundan bu ifadeyi determinantın dışına çarpan olarak çıkarırız:
  $$= (x+y+z+t) \begin{vmatrix} 1 & z & t \\ 1 & x+y & t \\ 1 & t & x+y \end{vmatrix}$$

- **3. Adım (Satır işlemleriyle 1. sütundaki $1$'in altını sıfırlama):**
  1. sütunda üç tane $1$ oluştu. 1. satırı kullanarak 2. ve 3. satırdaki $1$'leri sıfırlayabiliriz. Bunun için 1. satırı $-1$ ile çarpıp 2. satıra ($-r_1 + r_2 \to r_2$) ve yine 1. satırı $-1$ ile çarpıp 3. satıra ($-r_1 + r_3 \to r_3$) ekleriz. Bu işlemler determinantı değiştirmez:
  - Yeni 2. satır: $(1-1,\ x+y-z,\ t-t) = (0,\ x+y-z,\ 0)$
  - Yeni 3. satır: $(1-1,\ t-z,\ x+y-t) = (0,\ t-z,\ x+y-t)$
  $$= (x+y+z+t) \begin{vmatrix} 1 & z & t \\ 0 & x+y-z & 0 \\ 0 & t-z & x+y-t \end{vmatrix}$$

> **Hocanın vurgusu:** Daha önce ters matris bulurken satır ve sütun işlemlerini karıştıramayacağımızı söylemiştik; ancak **determinant hesaplamalarında** ($\det(A^T) = \det(A)$ olduğundan) hem satır işlemlerini hem de sütun işlemlerini aynı soruda birlikte kullanabiliriz.

- **4. Adım (1. sütuna göre Laplace açılımı veya üçgensel form):**
  Kısaltma olarak $R = x+y+z+t$ diyelim. Elde edilen matrisin 1. sütununda (veya 2. satırında) iki tane $0$ vardır. 1. sütuna göre kofaktör (Laplace) açılımı yaparsak:
  $$= R \cdot 1 \cdot (-1)^{1+1} \begin{vmatrix} x+y-z & 0 \\ t-z & x+y-t \end{vmatrix}$$
  Kalan $2 \times 2$ determinantta esas köşegen çarpımından yedek köşegen çarpımı ($0$) çıkarıldığında $(x+y-z)(x+y-t) - 0$ bulunur. Böylece sonuç çarpanlarına ayrılmış olarak elde edilir:
  $$\det = (x+y+z+t)(x+y-z)(x+y-t)$$

### 3.2 Üçgensel Matrise İndirgeme (Reduction to Triangular Matrix) Örneği

Hoca bir önceki derste Laplace açılımıyla determinantını $15$ olarak bulduğu matrisi, bu kez özellikle $4 \times 4$ ve daha büyük matrislerde çok işe yarayan **üçgensel matrise indirgeme** (reduction to triangular matrix) yöntemiyle çözdü (ekrandan, 00:49:30):

- **Verilen:**
  $$A = \begin{pmatrix} 2 & 1 & 3 \\ -1 & 2 & 1 \\ -2 & 2 & 3 \end{pmatrix}$$
  matrisinin determinantını determinant özelliklerini (üçgensel matrise indirgeme yöntemini) kullanarak bulunuz.

- **1. Adım (1. sütundaki $2$'nin altındaki $-1$ ve $-2$ elemanlarını sıfırlama):**
  - $-1$'i sıfırlamak için 1. satırı $\frac{1}{2}$ ile çarpıp 2. satıra ekleriz ($\frac{1}{2}r_1 + r_2 \to r_2$):
    - 2. satır: $(-1 + 1,\ 2 + \frac{1}{2},\ 1 + \frac{3}{2}) = (0,\ \frac{5}{2},\ \frac{5}{2})$
  - $-2$'yi sıfırlamak için 1. satırı doğrudan 3. satıra ekleriz ($r_1 + r_3 \to r_3$):
    - 3. satır: $(-2 + 2,\ 2 + 1,\ 3 + 3) = (0,\ 3,\ 6)$
  Bu satır ekleme işlemleri determinantı değiştirmez:
  $$\begin{vmatrix} 2 & 1 & 3 \\ -1 & 2 & 1 \\ -2 & 2 & 3 \end{vmatrix} \xrightarrow[\ r_1 + r_3 \to r_3\ ]{\frac{1}{2}r_1 + r_2 \to r_2} \begin{vmatrix} 2 & 1 & 3 \\ 0 & \frac{5}{2} & \frac{5}{2} \\ 0 & 3 & 6 \end{vmatrix}$$

- **2. Adım (Satırlardaki ortak çarpanları dışarı alma):**
  2. satır $\frac{5}{2}$'nin katıdır (multiple of $\frac{5}{2}$); 3. satır ise $3$'ün katıdır (multiple of $3$). Bu iki çarpanı determinantın dışına çıkarırsak:
  $$= \frac{5}{2} \cdot 3 \begin{vmatrix} 2 & 1 & 3 \\ 0 & 1 & 1 \\ 0 & 1 & 2 \end{vmatrix}$$

- **3. Adım (Üst üçgensel forma getirme ve köşegen elemanlarını çarpma):**
  3. satırın 2. sütunundaki $1$'i sıfırlamak için 2. satırı $-1$ ile çarpıp 3. satıra ekleriz ($-r_2 + r_3 \to r_3$):
  $$\xrightarrow{-r_2 + r_3 \to r_3} \frac{5}{2} \cdot 3 \begin{vmatrix} 2 & 1 & 3 \\ 0 & 1 & 1 \\ 0 & 0 & 1 \end{vmatrix}$$
  Elde edilen matris bir **üst üçgensel matristir** (upper triangular matrix). Üçgensel matrisin determinantı esas köşegen üzerindeki elemanların ($2, 1, 1$) çarpımına eşittir:
  $$\det(A) = \frac{5}{2} \cdot 3 \cdot 2 \cdot 1 \cdot 1 = 15$$

**Soru:** Matrisi üst üçgensel hale getirdikten sonra Sarrus kuralını kullansak yine aynı sonucu bulur muyuz?
**Cevap:** Evet, aynı sonucu bulursunuz; ancak üçgensel (ister üst üçgensel ister alt üçgensel olsun) bir matris elde ettikten sonra Sarrus kuralını kullanmaya hiç gerek yoktur. Yalnızca esas köşegen üzerindeki elemanları çarpmanız yeterlidir.

### 3.3 Sarrus Kuralı (Rule of Sarrus) Hatırlatması ve Örneği

Hoca 5. hafta slaytlarına geçerken Sarrus kuralını kısaca hatırlattı: Sarrus kuralı **yalnızca $3 \times 3$ boyutlu matrisler için** kullanılabilir. Matrisin ilk iki sütunu sağ tarafa (veya ilk iki satırı alt tarafa) tekrar yazılır; soldan sağa doğru inen üç köşegen üzerindeki elemanların çarpımlarının toplamından, sağdan sola doğru inen üç köşegen üzerindeki elemanların çarpımlarının toplamı çıkarılır.

- **Örnek (ekrandan, 00:57:45):**
  $$A = \begin{pmatrix} 1 & 4 & 7 \\ 2 & 5 & 8 \\ 3 & 6 & 9 \end{pmatrix}$$
  matrisinin determinantını Sarrus kuralıyla bulmak için ilk iki sütun sağa eklenir:
  $$\left[\begin{array}{ccc|cc} 1 & 4 & 7 & 1 & 4 \\ 2 & 5 & 8 & 2 & 5 \\ 3 & 6 & 9 & 3 & 6 \end{array}\right]$$
  - Soldan sağa çarpımlar ($+$): $(1 \cdot 5 \cdot 9) + (4 \cdot 8 \cdot 3) + (7 \cdot 2 \cdot 6) = 45 + 96 + 84 = 225$
  - Sağdan sola çarpımlar ($-$): $(7 \cdot 5 \cdot 3) + (1 \cdot 8 \cdot 6) + (4 \cdot 2 \cdot 9) = 105 + 48 + 72 = 225$
  - Fark: $\det(A) = 225 - 225 = 0$.

## 4. Ek Matris (Adjoint Matrix) ve Determinant Yardımıyla Ters Matris Bulma

Hoca daha önce tekil olmayan (nonsingular) bir matrisin tersini $[A \mid I_n] \to [I_n \mid A^{-1}]$ elementer satır işlemleriyle bulmayı öğrendiğimizi, ancak bunun her zaman kolay olmadığını belirterek determinant ve **ek matris** (adjoint matrix) yardımıyla ters matris bulma yöntemine geçti.

### 4.1 Ek Matrisin (Adjoint / Adjugate Matrix) Tanımı

- **Tanım (ekrandan, 01:03:45):** $A = [a_{ij}]$ bir $K$ cismi üzerinde $n \times n$ boyutlu bir kare matris ve $A_{ij}$ de $a_{ij}$ elemanının kofaktörü ($A_{ij} = (-1)^{i+j}\det(M_{ij})$) olsun. $(i, j)$. elemanı $a_{ji}$ elemanının kofaktörü $A_{ji}$ olan $n \times n$ boyutlu matrise —başka bir deyişle **$A$'nın kofaktörler matrisinin transpozuna**— $A$'nın **ek matrisi** (adjoint veya adjugate of $A$) denir ve $\text{adj}(A)$ ile gösterilir:
  $$\text{adj}(A) = [A_{ij}]^T = \begin{pmatrix} A_{11} & A_{12} & \cdots & A_{1n} \\ A_{21} & A_{22} & \cdots & A_{2n} \\ \vdots & \vdots & \ddots & \vdots \\ A_{n1} & A_{n2} & \cdots & A_{nn} \end{pmatrix}^T = \begin{pmatrix} A_{11} & A_{21} & \cdots & A_{n1} \\ A_{12} & A_{22} & \cdots & A_{n2} \\ \vdots & \vdots & \ddots & \vdots \\ A_{1n} & A_{2n} & \cdots & A_{nn} \end{pmatrix}$$

> **Hocanın vurgusu:** $\text{adj}(A)$ matrisi yazılırken kofaktörler matrisinin **transpozu** alınır: 1. satırın kofaktörleri olan $A_{11}, A_{12}, \dots, A_{1n}$ ek matrisin 1. sütununa; 2. satırın kofaktörleri olan $A_{21}, A_{22}, \dots, A_{2n}$ ise 2. sütununa yerleşir.

### 4.2 Ek Matris Hesaplama Örneği ve $A \cdot \text{adj}(A) = \det(A)I_n$ Teoremi

- **Örnek (ekrandan, 01:11:15):**
  $$A = \begin{pmatrix} 3 & -2 & 1 \\ 5 & 6 & 2 \\ 1 & 0 & -3 \end{pmatrix}$$
  matrisinin ek matrisini ($\text{adj}(A)$) bulunuz.

- **Kofaktörlerin Hesaplanması:**
  1. **1. Satırın Kofaktörleri:**
     - $A_{11}$ (1. satır, 1. sütun silinir; işaret $(-1)^{1+1} = +1$):
       $$A_{11} = (-1)^{1+1} \begin{vmatrix} 6 & 2 \\ 0 & -3 \end{vmatrix} = (6)(-3) - (2)(0) = -18$$
     - $A_{12}$ (1. satır, 2. sütun silinir; işaret $(-1)^{1+2} = -1$):
       $$A_{12} = (-1)^{1+2} \begin{vmatrix} 5 & 2 \\ 1 & -3 \end{vmatrix} = -((5)(-3) - (2)(1)) = -(-15 - 2) = 17$$
     - $A_{13}$ (1. satır, 3. sütun silinir; işaret $(-1)^{1+3} = +1$):
       $$A_{13} = (-1)^{1+3} \begin{vmatrix} 5 & 6 \\ 1 & 0 \end{vmatrix} = (5)(0) - (6)(1) = -6$$
  2. **2. Satırın Kofaktörleri:**
     - $A_{21}$ (2. satır, 1. sütun silinir; işaret $(-1)^{2+1} = -1$):
       $$A_{21} = -\begin{vmatrix} -2 & 1 \\ 0 & -3 \end{vmatrix} = -((-2)(-3) - (1)(0)) = -6$$
     - $A_{22}$ (2. satır, 2. sütun silinir; işaret $(-1)^{2+2} = +1$):
       $$A_{22} = +\begin{vmatrix} 3 & 1 \\ 1 & -3 \end{vmatrix} = (3)(-3) - (1)(1) = -9 - 1 = -10$$
     - $A_{23}$ (2. satır, 3. sütun silinir; işaret $(-1)^{2+3} = -1$):
       $$A_{23} = -\begin{vmatrix} 3 & -2 \\ 1 & 0 \end{vmatrix} = -((3)(0) - (-2)(1)) = -(0 + 2) = -2$$
  3. **3. Satırın Kofaktörleri:**
     - $A_{31}$ (3. satır, 1. sütun silinir; işaret $(-1)^{3+1} = +1$):
       $$A_{31} = +\begin{vmatrix} -2 & 1 \\ 6 & 2 \end{vmatrix} = (-2)(2) - (1)(6) = -4 - 6 = -10$$
     - $A_{32}$ (3. satır, 2. sütun silinir; işaret $(-1)^{3+2} = -1$):
       $$A_{32} = -\begin{vmatrix} 3 & 1 \\ 5 & 2 \end{vmatrix} = -((3)(2) - (1)(5)) = -(6 - 5) = -1$$
     - $A_{33}$ (3. satır, 3. sütun silinir; işaret $(-1)^{3+3} = +1$):
       $$A_{33} = +\begin{vmatrix} 3 & -2 \\ 5 & 6 \end{vmatrix} = (3)(6) - (-2)(5) = 18 + 10 = 28$$

- **Ek Matrisin ($\text{adj}(A)$) Yazılması:**
  Bulunan kofaktörler transpoz alınarak (satır kofaktörleri sütunlara yerleştirilerek) yazılır:
  $$\text{adj}(A) = \begin{pmatrix} A_{11} & A_{21} & A_{31} \\ A_{12} & A_{22} & A_{32} \\ A_{13} & A_{23} & A_{33} \end{pmatrix} = \begin{pmatrix} -18 & -6 & -10 \\ 17 & -10 & -1 \\ -6 & -2 & 28 \end{pmatrix}$$

**Soru:** Bir matrisin ek matrisini ($\text{adj}(A)$) bulmanın bundan başka bir yolu var mıdır?
**Cevap:** Hayır, ek matrisi bulmanın tek yolu kofaktörleri hesaplayıp kofaktör matrisinin transpozunu almaktır.

- **Teorem ($A$ ile $\text{adj}(A)$ Çarpımı):**
  $A$ bir $n \times n$ kare matris ise:
  $$A \cdot \text{adj}(A) = \text{adj}(A) \cdot A = \det(A) I_n$$
  eşitliği sağlanır.
  Nitekim yukarıdaki örnekte $A$ matrisi ile bulduğumuz $\text{adj}(A)$ matrisini çarparsak:
  $$A \cdot \text{adj}(A) = \begin{pmatrix} 3 & -2 & 1 \\ 5 & 6 & 2 \\ 1 & 0 & -3 \end{pmatrix} \begin{pmatrix} -18 & -6 & -10 \\ 17 & -10 & -1 \\ -6 & -2 & 28 \end{pmatrix} = \begin{pmatrix} -94 & 0 & 0 \\ 0 & -94 & 0 \\ 0 & 0 & -94 \end{pmatrix} = -94 \begin{pmatrix} 1 & 0 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 1 \end{pmatrix} = -94 I_3$$
  elde edilir. Teorem gereği buradaki skaler çarpan doğrudan $A$'nın determinantıdır: $\det(A) = -94$.

### 4.3 Ek Matris Yardımıyla Ters Matris ($A^{-1}$) Bulma Formülü ve Örneği

$A \cdot \text{adj}(A) = \det(A) I_n$ eşitliğinde eğer $\det(A) \neq 0$ ise her iki taraf $\det(A)$'ya bölündüğünde $A$ matrisinin tersini veren ünlü formül elde edilir:

- **Teorem:** $A$ bir $n \times n$ kare matris ve $\det(A) \neq 0$ ise $A$ tersinirdir (invertible / nonsingular) ve tersi:
  $$A^{-1} = \frac{1}{\det(A)} \text{adj}(A)$$
  formülüyle bulunur (ekrandan, 01:25:55). Eğer $\det(A) = 0$ ise $A$ tekildir (singular) ve tersi yoktur.

- **Örnek (ekrandan, 01:24:30 ve 01:25:55):**
  $$A = \begin{pmatrix} 2 & 3 & 1 \\ 0 & 1 & 2 \\ 1 & 2 & 0 \end{pmatrix}$$
  matrisinin tersini ($A^{-1}$) ek matris yöntemiyle bulunuz.

  1. **Determinantın Kontrol Edilmesi:**
     İlk olarak $\det(A)$ hesaplanır. Sarrus kuralı (veya Laplace açılımı) uygulanırsa:
     - Soldan sağa köşegen çarpımları: $(2)(1)(0) + (3)(2)(1) + (1)(0)(2) = 0 + 6 + 0 = 6$
     - Sağdan sola köşegen çarpımları: $(1)(1)(1) + (2)(2)(2) + (3)(0)(0) = 1 + 8 + 0 = 9$ (Not: Hoca tahtada sağdan sola çarpımlardan birini ilk başta $1$ yerine $-1$ yazıp $\det(A)=-2$ bulmuş, hemen ardından bir öğrencinin uyarısıyla $+1+8=9$ olarak düzeltip determinantı $-3$ bulmuştur.)
     $$\det(A) = 6 - 9 = -3 \neq 0$$
     $\det(A) = -3 \neq 0$ olduğundan $A$'nın tersi mevcuttur.

  2. **Kofaktörlerin Hesaplanması (ekrandan, 01:24:30):**
     - $A_{11} = (-1)^{1+1}\begin{vmatrix} 1 & 2 \\ 2 & 0 \end{vmatrix} = +(0 - 4) = -4$
     - $A_{12} = (-1)^{1+2}\begin{vmatrix} 0 & 2 \\ 1 & 0 \end{vmatrix} = -(0 - 2) = 2$
     - $A_{13} = (-1)^{1+3}\begin{vmatrix} 0 & 1 \\ 1 & 2 \end{vmatrix} = +(0 - 1) = -1$
     - $A_{21} = (-1)^{2+1}\begin{vmatrix} 3 & 1 \\ 2 & 0 \end{vmatrix} = -(0 - 2) = 2$
     - $A_{22} = (-1)^{2+2}\begin{vmatrix} 2 & 1 \\ 1 & 0 \end{vmatrix} = +(0 - 1) = -1$
     - $A_{23} = (-1)^{2+3}\begin{vmatrix} 2 & 3 \\ 1 & 2 \end{vmatrix} = -(4 - 3) = -1$
     - $A_{31} = (-1)^{3+1}\begin{vmatrix} 3 & 1 \\ 1 & 2 \end{vmatrix} = +(6 - 1) = 5$
     - $A_{32} = (-1)^{3+2}\begin{vmatrix} 2 & 1 \\ 0 & 2 \end{vmatrix} = -(4 - 0) = -4$
     - $A_{33} = (-1)^{3+3}\begin{vmatrix} 2 & 3 \\ 0 & 1 \end{vmatrix} = +(2 - 0) = 2$

  3. **Ek Matris ($\text{adj}(A)$) ve Ters Matris ($A^{-1}$):**
     Kofaktör matrisinin transpozu alınarak $\text{adj}(A)$ yazılır (ekrandan, 01:25:55):
     $$\text{adj}(A) = \begin{pmatrix} A_{11} & A_{21} & A_{31} \\ A_{12} & A_{22} & A_{32} \\ A_{13} & A_{23} & A_{33} \end{pmatrix} = \begin{pmatrix} -4 & 2 & 5 \\ 2 & -1 & -4 \\ -1 & -1 & 2 \end{pmatrix}$$
     Buradan $A^{-1} = \frac{1}{\det(A)}\text{adj}(A)$ formülüyle:
     $$A^{-1} = \frac{1}{-3} \begin{pmatrix} -4 & 2 & 5 \\ 2 & -1 & -4 \\ -1 & -1 & 2 \end{pmatrix} = \begin{pmatrix} \frac{4}{3} & -\frac{2}{3} & -\frac{5}{3} \\ -\frac{2}{3} & \frac{1}{3} & \frac{4}{3} \\ \frac{1}{3} & \frac{1}{3} & -\frac{2}{3} \end{pmatrix}$$
     bulunur. ($A \cdot A^{-1} = I_3$ çarpımı yapılarak sonucun doğruluğu kontrol edilebilir.)

**Soru:** Bu ek matris yöntemini boyutu $3$'ten büyük ($4 \times 4$ vb.) veya $2 \times 2$ boyutlu kare matrislerin tersini bulmak için de kullanabilir miyiz?
**Cevap:** Evet. Bu yöntem yalnızca $3 \times 3$ matrisler için değil, her $n \times n$ kare matris için geçerlidir. Örneğin $4 \times 4$ bir matriste önce kofaktör açılımı veya üçgensel matrise indirgeme ile determinantı bulursunuz, ardından kofaktörlerden ek matrisi ($\text{adj}(A)$) hesaplayarak tersini elde edersiniz. $2 \times 2$ matrislerde ise yalnızca iki satır ve iki sütun bulunduğundan ek matrisi ve tersi bulmak çok daha kolaydır.

## Örnek Sorular

### Soru 1: Determinant Özellikleriyle Sembolik Çarpanlara Ayırma (ekrandan, 00:41:40)

**Soru:** Determinantın özelliklerini kullanarak
$$\begin{vmatrix} x+y & z & t \\ z & x+y & t \\ z & t & x+y \end{vmatrix}$$
determinantını çarpanlarına ayırınız.

**Çözüm:**
Önce $c_1 + c_2 + c_3 \to c_1$ sütun işlemi uygulanır ve 1. sütun $(x+y+z+t)$ parantezine alınır:
$$\begin{vmatrix} x+y+z+t & z & t \\ x+y+z+t & x+y & t \\ x+y+z+t & t & x+y \end{vmatrix} = (x+y+z+t) \begin{vmatrix} 1 & z & t \\ 1 & x+y & t \\ 1 & t & x+y \end{vmatrix}$$
Ardından $-r_1 + r_2 \to r_2$ ve $-r_1 + r_3 \to r_3$ satır işlemleri uygulanır:
$$= (x+y+z+t) \begin{vmatrix} 1 & z & t \\ 0 & x+y-z & 0 \\ 0 & t-z & x+y-t \end{vmatrix} = (x+y+z+t)(x+y-z)(x+y-t)$$

### Soru 2: Üçgensel Matrise İndirgeyerek Determinant Bulma (ekrandan, 00:49:30)

**Soru:**
$$A = \begin{pmatrix} 2 & 1 & 3 \\ -1 & 2 & 1 \\ -2 & 2 & 3 \end{pmatrix}$$
matrisinin determinantını üçgensel matrise indirgeme yöntemiyle hesaplayınız.

**Çözüm:**
$$\begin{vmatrix} 2 & 1 & 3 \\ -1 & 2 & 1 \\ -2 & 2 & 3 \end{vmatrix} \xrightarrow[\ r_1 + r_3 \to r_3\ ]{\frac{1}{2}r_1 + r_2 \to r_2} \begin{vmatrix} 2 & 1 & 3 \\ 0 & \frac{5}{2} & \frac{5}{2} \\ 0 & 3 & 6 \end{vmatrix} = \frac{5}{2} \cdot 3 \begin{vmatrix} 2 & 1 & 3 \\ 0 & 1 & 1 \\ 0 & 1 & 2 \end{vmatrix} \xrightarrow{-r_2 + r_3 \to r_3} \frac{5}{2} \cdot 3 \begin{vmatrix} 2 & 1 & 3 \\ 0 & 1 & 1 \\ 0 & 0 & 1 \end{vmatrix}$$
Üst üçgensel matrisin determinantı esas köşegen elemanlarının çarpımı olduğundan:
$$\det(A) = \frac{5}{2} \cdot 3 \cdot 2 \cdot 1 \cdot 1 = 15$$

### Soru 3: Ek Matris ($\text{adj}(A)$) Hesaplama (ekrandan, 01:11:15)

**Soru:**
$$A = \begin{pmatrix} 3 & -2 & 1 \\ 5 & 6 & 2 \\ 1 & 0 & -3 \end{pmatrix}$$
matrisinin ek matrisini ($\text{adj}(A)$) ve $A \cdot \text{adj}(A)$ çarpımından yararlanarak $\det(A)$ değerini bulunuz.

**Çözüm:**
Kofaktörler:
- $A_{11} = -18, \quad A_{12} = 17, \quad A_{13} = -6$
- $A_{21} = -6, \quad A_{22} = -10, \quad A_{23} = -2$
- $A_{31} = -10, \quad A_{32} = -1, \quad A_{33} = 28$

Kofaktör matrisinin transpozu:
$$\text{adj}(A) = \begin{pmatrix} -18 & -6 & -10 \\ 17 & -10 & -1 \\ -6 & -2 & 28 \end{pmatrix}$$
$A \cdot \text{adj}(A) = -94 I_3$ olduğundan $\det(A) = -94$'tür.

### Soru 4: Ek Matris Yardımıyla Ters Matris Bulma (ekrandan, 01:24:30 ve 01:25:55)

**Soru:**
$$A = \begin{pmatrix} 2 & 3 & 1 \\ 0 & 1 & 2 \\ 1 & 2 & 0 \end{pmatrix}$$
matrisinin tersini ($A^{-1}$) ek matris yöntemiyle bulunuz.

**Çözüm:**
$\det(A) = 6 - 9 = -3 \neq 0$. Kofaktörler hesaplanıp transpozu alındığında:
$$\text{adj}(A) = \begin{pmatrix} -4 & 2 & 5 \\ 2 & -1 & -4 \\ -1 & -1 & 2 \end{pmatrix}$$
$$A^{-1} = \frac{1}{\det(A)}\text{adj}(A) = -\frac{1}{3} \begin{pmatrix} -4 & 2 & 5 \\ 2 & -1 & -4 \\ -1 & -1 & 2 \end{pmatrix} = \begin{pmatrix} \frac{4}{3} & -\frac{2}{3} & -\frac{5}{3} \\ -\frac{2}{3} & \frac{1}{3} & \frac{4}{3} \\ \frac{1}{3} & \frac{1}{3} & -\frac{2}{3} \end{pmatrix}$$

## Dersin Toparlaması

Bu derste ilk olarak determinantın temel özellikleri incelendi: birim matrisin determinantının $1$ olduğu, iki satır veya sütunun yer değiştirmesinin determinantın işaretini değiştirdiği, bir satır veya sütunun $k$ skaleriyle çarpılmasının determinantı $k$ ile çarptığı, iki satır veya sütunu eşit olan ya da sıfır satırı içeren matrisin determinantının $0$ olduğu, bir satırın katını başka bir satıra eklemenin determinantı değiştirmediği ve üçgensel matrislerin determinantının esas köşegen elemanlarının çarpımına eşit olduğu gösterildi. Ayrıca $\det(AB) = \det(A)\det(B)$, $\det(A^{-1}) = 1/\det(A)$, $\det(kA) = k^n\det(A)$ ve $\det(A^T) = \det(A)$ bağıntıları çıkarılarak bu özelliklerin çarpanlara ayırma ve üçgensel matrise indirgeme sorularında nasıl kullanıldığı örneklerle pekiştirildi. Dersin ikinci bölümünde ise kofaktör matrisinin transpozu olan ek matris ($\text{adj}(A) = [A_{ij}]^T$) tanımlandı, $A \cdot \text{adj}(A) = \det(A)I_n$ teoremi gösterildi ve $\det(A) \neq 0$ koşulu altında $A^{-1} = \frac{1}{\det(A)}\text{adj}(A)$ formülüyle ters matrisin nasıl hesaplandığı adım adım işlendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
