# Ders 13 Genişletilmiş Notu: Vektörlerin Doğrusal (Lineer) Bağımlılığı ve Bağımsızlığı, Doğrusal Birleşim ve Germe Kümeleri (Spanning Sets)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Vektörlerin Doğrusal (Lineer) Bağımlılığı ve Bağımsızlığı (Linear Dependence and Independence)
  - 1.1 Doğrusal Bağımlılık ve Doğrusal Bağımsızlık Tanımı
  - 1.2 Homojen Doğrusal Denklem Sistemi ve Determinant ile İlişkisi
  - 1.3 $\mathbb{R}^3$ Uzayında Standart Baz Vektörlerinin Doğrusal Bağımsızlığı Örneği
  - 1.4 $\mathbb{R}^3$ Uzayında Üç Vektörün Doğrusal Bağımlılığı Örneği
  - 1.5 $M_{2 \times 2}$ Matrisler Uzayında Doğrusal Bağımlılık Örneği
- 2. Vektörlerin Doğrusal (Lineer) Birleşimi (Linear Combination of Vectors)
  - 2.1 Doğrusal Birleşim Tanımı
  - 2.2 Bir Vektörün Diğer İki Vektörün Doğrusal Birleşimi Olup Olmadığının Gösterilmesi
  - 2.3 Doğrusal Birleşim Koşulunu Sağlayan $k$ Parametresinin Bulunması
- 3. Doğrusal Bağımlılık ve Bağımsızlık Teoremleri ile Temel Özellikler
  - 3.1 Doğrusal Bağımsız Kümenin Genişletilmesi ve Alt Küme / Üst Küme Teoremleri
  - 3.2 Rank ve Determinant Teoremi
  - 3.3 Sıfır Vektörü, Tek Elemanlı Küme ve Eşit Vektörler İçin Temel Özellikler
  - 3.4 $\mathbb{R}^4$ Uzayında Dört Vektörün Doğrusal Bağımsızlığı ve Doğrusal Birleşim Örneği
- 4. Germe Kümeleri / Geren Küme (Spanning Sets)
  - 4.1 Gerilen Küme ($\text{span}(S)$) Tanımı ve Altuzay Özelliği
  - 4.2 $M_{2 \times 3}$ Matrisler Uzayında ve $\mathbb{R}^4$ Uzayında Germe Kümesi Örnekleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Vektörlerin Doğrusal (Lineer) Bağımlılığı ve Bağımsızlığı (Linear Dependence and Independence)

Hoca bu derste vektör uzaylarının en önemli konularından olan **vektörlerin doğrusal bağımlılığı ve bağımsızlığı** (linear dependence and independence of vectors), **vektörlerin doğrusal birleşimi** (linear combination of vectors) ve **germe kümeleri** (spanning sets) konularını işleyeceğimizi belirtti.

### 1.1 Doğrusal Bağımlılık ve Doğrusal Bağımsızlık Tanımı

$V$ bir reel vektör uzayı (bundan sonra kısaca vektör uzayı diyeceğiz ve vektör toplamayı $+$, skalerle çarpmayı olağan çarpma ile göstereceğiz), $\vec{v}_1, \vec{v}_2, \dots, \vec{v}_n \in V$ bu uzayda $n$ adet vektör ve $x_1, x_2, \dots, x_n \in \mathbb{R}$ skalerler (reel sayılar) olsun (ekrandan, 00:11:30):

$$x_1 \vec{v}_1 + x_2 \vec{v}_2 + \dots + x_n \vec{v}_n = \vec{0}$$

toplam denklemini (vektör denklemini) oluşturduğumuzda iki durum ortaya çıkar:

- **Doğrusal Bağımlı Vektörler (Linearly Dependent Vectors):**
  Eğer yukarıdaki $x_1 \vec{v}_1 + x_2 \vec{v}_2 + \dots + x_n \vec{v}_n = \vec{0}$ eşitliğini sağlayan, **hepsi birden sıfır olmayan** (not all of them zero — yani en az bir $i$ için $x_i \neq 0$ olan) $x_1, x_2, \dots, x_n \in \mathbb{R}$ skalerleri mevcutsa, $\vec{v}_1, \vec{v}_2, \dots, \vec{v}_n$ vektörlerine **doğrusal bağımlı** (linearly dependent) denir.
- **Doğrusal Bağımsız Vektörler (Linearly Independent Vectors):**
  Aksi halde, yani $x_1 \vec{v}_1 + x_2 \vec{v}_2 + \dots + x_n \vec{v}_n = \vec{0}$ eşitliği **yalnızca skalerlerin tümü sıfır olduğunda** ($x_1 = x_2 = \dots = x_n = 0$ — all of them zero) sağlanıyorsa, $\vec{v}_1, \vec{v}_2, \dots, \vec{v}_n$ vektörlerine **doğrusal bağımsız** (linearly independent) denir. Başka bir ifadeyle:
  $$\vec{v}_1, \dots, \vec{v}_n \text{ doğrusal bağımsızdır} \iff \left(a_1 \vec{v}_1 + a_2 \vec{v}_2 + \dots + a_n \vec{v}_n = \vec{0} \implies a_1 = a_2 = \dots = a_n = 0\right)$$
- **Kümeler İçin Terminoloji:** Eğer $S = \{\vec{v}_1, \vec{v}_2, \dots, \vec{v}_n\}$ bu vektörlerden oluşan küme ise, içindeki vektörler doğrusal bağımlı olduğunda $S$ kümesine **doğrusal bağımlı küme**, vektörler doğrusal bağımsız olduğunda ise $S$ kümesine **doğrusal bağımsız küme** denir.

### 1.2 Homojen Doğrusal Denklem Sistemi ve Determinant ile İlişkisi

> **Hocanın vurgusu (ekrandan, 00:12:30–00:14:40):**
> Herhangi $\vec{v}_1, \vec{v}_2, \dots, \vec{v}_n$ vektörleri için tüm skalerleri $x_1 = x_2 = \dots = x_n = 0$ seçtiğimizde $x_1 \vec{v}_1 + \dots + x_n \vec{v}_n = \vec{0}$ denklemi zaten her zaman sağlanır (bu, homojen doğrusal denklem sisteminin aşikar / sıfır çözümüdür). Burada asıl soru şudur: **En az bir $x_i$ skaleri sıfırdan farklı ($x_i \neq 0$) olacak biçimde bu denklemi sağlamak mümkün müdür?**
> - Eğer kurulan homojen doğrusal denklem sisteminin **yalnızca sıfır çözümü** ($x_1 = x_2 = \dots = x_n = 0$) varsa, vektörler **doğrusal bağımsızdır**.
> - Eğer homojen sistemin **sonsuz çoklukta çözümü** (dolayısıyla sıfırdan farklı çözümleri) varsa, en az bir $x_i \neq 0$ seçilebileceğinden vektörler **doğrusal bağımlıdır**.

### 1.3 $\mathbb{R}^3$ Uzayında Standart Baz Vektörlerinin Doğrusal Bağımsızlığı Örneği

- **Verilen (ekrandan, 00:18:30):** $\mathbb{R}^3$ vektör uzayında standart baz vektörleri olan ($\vec{i}, \vec{j}, \vec{k}$ olarak da bildiğimiz):
  $$\vec{e}_1 = (1, 0, 0), \quad \vec{e}_2 = (0, 1, 0), \quad \vec{e}_3 = (0, 0, 1)$$
  vektörlerinin doğrusal bağımsız olduğunu gösteriniz.
- **Çözüm:**
  $x_1, x_2, x_3 \in \mathbb{R}$ skalerleri için doğrusal birleşimi $\mathbb{R}^3$ uzayının sıfır vektörü olan $\vec{0} = (0, 0, 0)$'a eşitleyelim:
  $$x_1 \vec{e}_1 + x_2 \vec{e}_2 + x_3 \vec{e}_3 = \vec{0}$$
  $$x_1(1, 0, 0) + x_2(0, 1, 0) + x_3(0, 0, 1) = (0, 0, 0)$$
  $$(x_1, 0, 0) + (0, x_2, 0) + (0, 0, x_3) = (0, 0, 0)$$
  $$(x_1, x_2, x_3) = (0, 0, 0)$$
  İki sıralı üçlünün eşitliğinden:
  $$x_1 = 0, \quad x_2 = 0, \quad x_3 = 0$$
  bulunur. Denklemi sağlayan skalerlerin tümü zorunlu olarak sıfır çıktığından, tanım gereği $\vec{e}_1, \vec{e}_2, \vec{e}_3$ vektörleri **doğrusal bağımsızdır**.

### 1.4 $\mathbb{R}^3$ Uzayında Üç Vektörün Doğrusal Bağımlılığı Örneği

- **Verilen (ekrandan, 00:24:30 ve 00:27:30):**
  $\mathbb{R}^3$ uzayındaki $\{\vec{v}_1 = (1, 2, 0), \, \vec{v}_2 = (2, 0, 1), \, \vec{v}_3 = (3, 2, 1)\} \subset \mathbb{R}^3$ vektörlerinin doğrusal bağımlı olduğunu gösteriniz.
- **Çözüm:**
  $x_1, x_2, x_3 \in \mathbb{R}$ (veya hoca tahtada $a_1, a_2, a_3$ olarak da yazmıştır) skalerleri için homojen sistemi kuralım:
  $$x_1 \vec{v}_1 + x_2 \vec{v}_2 + x_3 \vec{v}_3 = (0, 0, 0)$$
  $$x_1(1, 2, 0) + x_2(2, 0, 1) + x_3(3, 2, 1) = (0, 0, 0)$$
  Karşılıklı bileşenleri topladığımızda şu $3$ bilinmeyenli $3$ denklemli homojen doğrusal sistemi elde ederiz:
  $$\begin{cases} x_1 + 2x_2 + 3x_3 = 0 \\ 2x_1 + 2x_3 = 0 \\ x_2 + x_3 = 0 \end{cases}$$
  Bu homojen sistemin katsayılar matrisi, $\vec{v}_1, \vec{v}_2, \vec{v}_3$ vektörlerinin sütunlara yazılmasıyla oluşan $3 \times 3$ kare matristir:
  $$A = \begin{bmatrix} 1 & 2 & 3 \\ 2 & 0 & 2 \\ 0 & 1 & 1 \end{bmatrix}$$

  - **1. Yol (Determinant Kriteri — ekrandan, 00:24:30):**
    $n$ bilinmeyenli $n$ denklemli bir homojen sistemde $\det(A) \neq 0$ ise yalnız sıfır çözümü vardır (vektörler doğrusal bağımsızdır); $\det(A) = 0$ ise sonsuz çözüm vardır (vektörler doğrusal bağımlıdır). Sarrus kuralıyla determinantı hesaplayalım:
    $$\det(A) = \begin{vmatrix} 1 & 2 & 3 \\ 2 & 0 & 2 \\ 0 & 1 & 1 \end{vmatrix} = (0 + 0 + 6) - (0 + 2 + 4) = 6 - 6 = 0$$
    $\det(A) = 0$ olduğundan homojen sistemin sonsuz çoklukta (sıfırdan farklı) çözümü vardır; dolayısıyla $\vec{v}_1, \vec{v}_2, \vec{v}_3$ vektörleri **doğrusal bağımlıdır**.

  - **2. Yol (Satır İndirgeme ile Çözüm — ekrandan, 00:27:30):**
    Katsayılar matrisine satır işlemleri uygulandığında:
    $$\begin{pmatrix} 1 & 2 & 3 \\ 2 & 0 & 2 \\ 0 & 1 & 1 \end{pmatrix} \sim \begin{pmatrix} 1 & 0 & 1 \\ 0 & 1 & 1 \\ 0 & 0 & 0 \end{pmatrix} \implies \begin{cases} x_1 + x_3 = 0 \\ x_2 + x_3 = 0 \end{cases}$$
    Burada $x_3 = r \in \mathbb{R}$ keyfi değişken (parametre) seçilirse $x_1 = x_2 = -r$ sonsuz çözüm ailesi bulunur (örneğin $r = 1 \neq 0$ için $x_1 = -1, x_2 = -1, x_3 = 1$). Dolayısıyla $\vec{v}_1, \vec{v}_2, \vec{v}_3$ **doğrusal bağımlıdır**.

### 1.5 $M_{2 \times 2}$ Matrisler Uzayında Doğrusal Bağımlılık Örneği

- **Verilen (ekrandan, 00:33:30):**
  Tüm $2 \times 2$ matrislerin vektör uzayı olan $M_{2 \times 2}$ içinde:
  $$v_1 = \begin{bmatrix} 2 & 1 \\ 0 & 1 \end{bmatrix}, \quad v_2 = \begin{bmatrix} 1 & 2 \\ 1 & 0 \end{bmatrix}, \quad v_3 = \begin{bmatrix} 0 & -3 \\ -2 & 1 \end{bmatrix} \in M_{2 \times 2}$$
  vektörleri (matrisleri) doğrusal bağımsız mıdır?
- **Çözüm:**
  $M_{2 \times 2}$ vektör uzayının sıfır vektörü $2 \times 2$ sıfır matrisi $\mathbf{0} = \begin{bmatrix} 0 & 0 \\ 0 & 0 \end{bmatrix}$'dır. $a_1, a_2, a_3 \in \mathbb{R}$ skalerleri için $a_1 v_1 + a_2 v_2 + a_3 v_3 = \mathbf{0}$ denklemini kuralım:
  $$a_1 \begin{bmatrix} 2 & 1 \\ 0 & 1 \end{bmatrix} + a_2 \begin{bmatrix} 1 & 2 \\ 1 & 0 \end{bmatrix} + a_3 \begin{bmatrix} 0 & -3 \\ -2 & 1 \end{bmatrix} = \begin{bmatrix} 0 & 0 \\ 0 & 0 \end{bmatrix}$$
  Karşılıklı matris elemanlarını sıfıra eşitlediğimizde $3$ bilinmeyenli ($a_1, a_2, a_3$) ve $4$ denklemli şu homojen sistemi elde ederiz:
  $$\begin{cases} 2a_1 + a_2 = 0 \\ a_1 + 2a_2 - 3a_3 = 0 \\ a_2 - 2a_3 = 0 \\ a_1 + a_3 = 0 \end{cases}$$
  3. denklemden $a_2 = 2a_3$ ve 4. denklemden $a_1 = -a_3$ bulunur. Bu değerler 1. ve 2. denklemde yerine koyulduğunda $2(-a_3) + 2a_3 = 0$ ve $(-a_3) + 2(2a_3) - 3a_3 = 0$ denklemleri her $a_3 \in \mathbb{R}$ için özdeş olarak sağlanır (ara adım eklendi). Yani sistemin $a_3$ parametresine bağlı **sonsuz çoklukta çözümü** vardır (örneğin $a_3 = -1$ için $a_1 = 1, a_2 = -2$). Dolayısıyla $v_1, v_2, v_3$ matrisleri **doğrusal bağımlıdır**.

> **Ders sonrası not:** Hoca derste bu homojen sistemde denklem sayısı ($m = 4$) bilinmeyen sayısından ($n = 3$) büyük olduğu ($m > n$) için sistemin her zaman sonsuz çözüme sahip olduğunu söylemiştir. Genel olarak bir homojen sistemde her zaman sonsuz çözüm garantisi $m < n$ (denklem sayısı bilinmeyen sayısından az) olduğunda geçerlidir; $m > n$ olduğunda ise katsayılar matrisinin rankı $r = n = 3$ olsaydı yalnız sıfır çözümü çıkardı. Bu örnekte 1. ve 2. denklemler 3. ve 4. denklemlerin doğrusal birleşimi olduğundan $\text{rank}(A) = 2 < n = 3$ çıkmakta ve bu nedenle sonsuz çözüm elde edilmektedir.

## 2. Vektörlerin Doğrusal (Lineer) Birleşimi (Linear Combination of Vectors)

### 2.1 Doğrusal Birleşim Tanımı

- **Tanım (Doğrusal Birleşim — ekrandan, 00:38:30):**
  Bir $V$ vektör uzayında $\vec{v}_1, \vec{v}_2, \dots, \vec{v}_k \in V$ vektörleri verilsin. Eğer bir $\vec{v} \in V$ vektörü, bazı $a_1, a_2, \dots, a_k \in \mathbb{R}$ reel sayıları (skalerleri) için:
  $$\vec{v} = a_1 \vec{v}_1 + a_2 \vec{v}_2 + \dots + a_k \vec{v}_k = \sum_{j=1}^k a_j \vec{v}_j$$
  biçiminde yazılabiliyorsa, $\vec{v}$ vektörüne $\vec{v}_1, \vec{v}_2, \dots, \vec{v}_k$ vektörlerinin bir **doğrusal (lineer) birleşimi** (linear combination) denir.

### 2.2 Bir Vektörün Diğer İki Vektörün Doğrusal Birleşimi Olup Olmadığının Gösterilmesi

- **Verilen (ekrandan, 00:42:30 ve 00:46:30):**
  $\mathbb{R}^3$ uzayında $\vec{u} = (1, 2, -1)$ ve $\vec{v} = (6, 4, 2)$ vektörleri veriliyor. $\vec{w} = (9, 2, 7) \in \mathbb{R}^3$ vektörünün $\vec{u}$ ve $\vec{v}$'nin bir doğrusal birleşimi olduğunu, fakat $\vec{w}' = (4, -1, 8)$ vektörünün bir doğrusal birleşim **olmadığını** gösteriniz.

- **Adım Adım Çözüm:**
  1. **$\vec{w} = (9, 2, 7)$ İçin Doğrusal Birleşim Kontrolü (ekrandan, 00:42:30):**
     $\vec{w} = x_1 \vec{u} + x_2 \vec{v}$ eşitliğini sağlayan $x_1, x_2 \in \mathbb{R}$ skalerlerini arıyoruz:
     $$(9, 2, 7) = x_1(1, 2, -1) + x_2(6, 4, 2)$$
     Bileşenleri eşitlediğimizde şu doğrusal denklem sistemi elde edilir:
     $$\begin{cases} x_1 + 6x_2 = 9 \\ 2x_1 + 4x_2 = 2 \\ -x_1 + 2x_2 = 7 \end{cases}$$
     Sistemin genişletilmiş matrisini yazıp elementer satır işlemleriyle RREF formuna indirgediğimizde:
     $$\begin{pmatrix} 1 & 6 & 9 \\ 2 & 4 & 2 \\ -1 & 2 & 7 \end{pmatrix} \sim \begin{pmatrix} 1 & 0 & -3 \\ 0 & 1 & 2 \\ 0 & 0 & 0 \end{pmatrix} \implies x_1 = -3, \quad x_2 = 2$$
     bulunur. Yani $\vec{w} = -3\vec{u} + 2\vec{v}$ olarak yazılabildiğinden $\vec{w}$, $\vec{u}$ ve $\vec{v}$'nin bir **doğrusal birleşimidir**.

  2. **$\vec{w}' = (4, -1, 8)$ İçin Doğrusal Birleşim Kontrolü (ekrandan, 00:46:30):**
     $\vec{w}' = x_1 \vec{u} + x_2 \vec{v}$ yazalım:
     $$(4, -1, 8) = x_1(1, 2, -1) + x_2(6, 4, 2) \implies \begin{cases} x_1 + 6x_2 = 4 \\ 2x_1 + 4x_2 = -1 \\ -x_1 + 2x_2 = 8 \end{cases}$$
     Genişletilmiş matrisi satır eşelon formuna indirgediğimizde (Not: Slaytta genişletilmiş matrisin 2. satır sağ tarafında $-1$ yerine sehven $-2$ yazılmıştır, ancak her iki durumda da 3. satırda $0 = 1$ çelişkisi elde edilir):
     $$\begin{pmatrix} 1 & 6 & \mid & 4 \\ 2 & 4 & \mid & -2 \\ -1 & 2 & \mid & 8 \end{pmatrix} \sim \begin{pmatrix} 1 & 0 & \mid & 0 \\ 0 & 1 & \mid & 0 \\ 0 & 0 & \mid & 1 \end{pmatrix}$$
     İndirgenmiş matrise baktığımızda $\text{rank}(A) = 2$ iken $\text{rank}[A \mid b] = 3$'tür ($\text{rank}(A) \neq \text{rank}[A \mid b]$, son satır $0 = 1$ çelişkisi verir). Dolayısıyla bu doğrusal denklem sistemi **tutarsızdır** (inconsistent / çözümü yoktur). Denklemi sağlayan $x_1, x_2$ skalerleri bulunamadığından $\vec{w}'$, $\vec{u}$ ve $\vec{v}$ vektörlerinin bir doğrusal birleşimi olarak **yazılamaz**.

### 2.3 Doğrusal Birleşim Koşulunu Sağlayan $k$ Parametresinin Bulunması

- **Verilen (ekrandan, 00:49:15):**
  $k$'nın hangi değerleri için $\vec{w} = (1, -2, k) \in \mathbb{R}^3$ vektörü, $\vec{u} = (3, 0, -2)$ ve $\vec{v} = (2, -1, 5)$ vektörlerinin bir doğrusal birleşimi olarak yazılabilir?
- **Çözüm:**
  $\vec{w} = a_1 \vec{u} + a_2 \vec{v}$ eşitliğini kuralım:
  $$(1, -2, k) = a_1(3, 0, -2) + a_2(2, -1, 5)$$
  Karşılıklı bileşenleri eşitlediğimizde:
  $$\begin{cases} 3a_1 + 2a_2 = 1 \\ 0a_1 - a_2 = -2 \\ -2a_1 + 5a_2 = k \end{cases}$$
  1. İkinci denklemden doğrudan $-a_2 = -2 \implies a_2 = 2$ bulunur.
  2. $a_2 = 2$ değerini birinci denklemde yerine yazalım:
     $$3a_1 + 2(2) = 1 \implies 3a_1 = 1 - 4 = -3 \implies a_1 = -1$$
  3. Bulunan $a_1 = -1$ ve $a_2 = 2$ değerlerini üçüncü denklemde yerine yazarak $k$'yı hesaplayalım:
     $$k = -2a_1 + 5a_2 = -2(-1) + 5(2) = 2 + 10 = 12$$
  Dolayısıyla yalnızca **$k = 12$** değeri için $\vec{w}$ vektörü $\vec{u}$ ve $\vec{v}$'nin doğrusal birleşimi olarak yazılabilir.

## 3. Doğrusal Bağımlılık ve Bağımsızlık Teoremleri ile Temel Özellikler

### 3.1 Doğrusal Bağımsız Kümenin Genişletilmesi ve Alt Küme / Üst Küme Teoremleri

- **Teorem 1 (ekrandan, 00:53:30):**
  $\vec{v}_1, \vec{v}_2, \dots, \vec{v}_m \in V$, $V$ vektör uzayında **doğrusal bağımsız** $m$ adet vektör olsun. Eğer bunlara bir $\vec{v}_{m+1}$ vektörü eklendiğinde oluşan $\vec{v}_1, \vec{v}_2, \dots, \vec{v}_m, \vec{v}_{m+1}$ vektörleri **doğrusal bağımlı** oluyorsa, $\vec{v}_{m+1}$ vektörü $\vec{v}_1, \vec{v}_2, \dots, \vec{v}_m$ vektörlerinin bir **doğrusal birleşimi** olarak yazılabilir.

- **Teorem 2 (Alt Küme ve Üst Küme İlişkisi — ekrandan, 00:53:30):**
  $r < m$ olmak üzere, $\vec{v}_1, \dots, \vec{v}_m \in V$ vektörlerinin içindeki herhangi $r$ tane vektör doğrusal bağımlı ise, tüm $\vec{v}_1, \dots, \vec{v}_m$ vektörleri de **doğrusal bağımlıdır**.
  Hoca bu teoremi kümeler diliyle şu şekilde özetleyip tahtaya yazmıştır:
  $S_1$ ve $S_2$ bir $V$ vektör uzayının iki alt kümesi ve **$S_1 \subseteq S_2$** ($S_1$ küçük küme, $S_2$ büyük küme) olsun:
  1. **a)** Eğer küçük küme **$S_1$ doğrusal bağımlı** ise, büyük küme **$S_2$ de doğrusal bağımlıdır**.
  2. **b)** Eğer büyük küme **$S_2$ doğrusal bağımsız** ise, küçük küme **$S_1$ de doğrusal bağımsızdır**.

### 3.2 Rank ve Determinant Teoremi

- **Teorem 3 (ekrandan, 00:55:30):**
  $V$ bir vektör uzayı ve $m \le n$ için $\vec{v}_1 = (a_{11}, a_{12}, \dots, a_{1n})$, $\vec{v}_2 = (a_{21}, a_{22}, \dots, a_{2n}), \dots, \vec{v}_m = (a_{m1}, a_{m2}, \dots, a_{mn})$ vektörlerinin satırlara yerleştirilmesiyle oluşturulan:
  $$A = \begin{pmatrix} a_{11} & a_{12} & \dots & a_{1n} \\ a_{21} & a_{22} & \dots & a_{2n} \\ \vdots & \vdots & \ddots & \vdots \\ a_{m1} & a_{m2} & \dots & a_{mn} \end{pmatrix}$$
  matrisinin rankı $\text{rank}(A) = r$ ise, bu $m$ vektörün içindeki **$r$ tane vektör doğrusal bağımsızdır**.
  1. Eğer $r < m$ ise, geriye kalan $m - r$ tane vektör bu $r$ tane doğrusal bağımsız vektörün birer **doğrusal birleşimi** olarak yazılabilir.
  2. **Özel Durum ($n = m$, Kare Matris):** Eğer vektör sayısı koordinat sayısına eşitse ($n = m$, yani $A$ kare matris ise):
     $$m \text{ adet vektör doğrusal bağımsızdır} \iff |A| = \det(A) \neq 0$$
     ($\det(A) = 0$ ise vektörler doğrusal bağımlıdır).

### 3.3 Sıfır Vektörü, Tek Elemanlı Küme ve Eşit Vektörler İçin Temel Özellikler

Hoca sınavlarda doğru/yanlış veya çoktan seçmeli sorularda sıkça kullanılan dört kritik özelliği sınıfa soru sorarak yazdırdı (ekrandan, 00:59:30 ve 01:04:30):

1. **Yalnızca Sıfır Vektöründen Oluşan Küme ($S = \{\vec{0}\}$):**
   **Soru:** Yalnızca sıfır vektöründen oluşan $S = \{\vec{0}\}$ kümesi doğrusal bağımlı mıdır, yoksa doğrusal bağımsız mıdır?
   **Cevap:** **Doğrusal bağımlıdır** (linearly dependent)! Çünkü tek bir $\vec{v}_1 = \vec{0}$ vektörü için $a_1 \vec{v}_1 = \vec{0}$ denklemini yazdığımızda:
   $$a_1 \cdot \vec{0} = \vec{0}$$
   eşitliği $a_1 = 5 \neq 0$ gibi sıfırdan farklı her $a_1 \in \mathbb{R}$ skaleri için sağlanır. Sıfırdan farklı bir skaler ($a_1 \neq 0$) bulunabildiği için $S = \{\vec{0}\}$ kümesi **doğrusal bağımlıdır**.

2. **Sıfır Vektörünü İçeren Herhangi Bir Küme ($\vec{0} \in S$):**
   Eğer $S = \{\vec{v}_1, \vec{v}_2, \dots, \vec{v}_k, \vec{0}\}$ sıfır vektörünü ($\vec{0}$) içeren herhangi bir vektör kümesi ise, $S$ kümesi kesinlikle **doğrusal bağımlıdır**. Çünkü:
   $$0\vec{v}_1 + 0\vec{v}_2 + \dots + 0\vec{v}_k + 5\vec{0} = \vec{0}$$
   yazıldığında diğer tüm katsayılar $0$ seçilse bile $\vec{0}$'ın katsayısı sıfırdan farklı ($a_{k+1} = 5 \neq 0$) seçilebilir (veya Teorem 2a gereği doğrusal bağımlı $\{\vec{0}\} \subseteq S$ alt kümesini kapsadığı için $S$ de doğrusal bağımlıdır).

3. **Sıfırdan Farklı Tek Bir Vektörden Oluşan Küme ($S = \{\vec{v}\}, \, \vec{v} \neq \vec{0}$):**
   Sıfırdan farklı tek bir vektörden oluşan $S = \{\vec{v}\}$ ($\vec{v} \neq \vec{0}$) kümesi **doğrusal bağımsızdır** (çünkü $\vec{v} \neq \vec{0}$ iken $a_1 \vec{v} = \vec{0} \implies a_1 = 0$ olmak zorundadır).

4. **İki Vektörü Birbirine Eşit Olan Küme:**
   Bir $V$ vektör uzayındaki $\vec{v}_1, \vec{v}_2, \dots, \vec{v}_k$ vektörlerinden herhangi ikisi birbirine eşitse (örneğin $\vec{v}_1 = \vec{v}_2$), bu vektörler **doğrusal bağımlıdır** (çünkü $1\vec{v}_1 - 1\vec{v}_2 + 0\vec{v}_3 + \dots + 0\vec{v}_k = \vec{0}$ eşitliği sıfırdan farklı katsayılarla sağlanır).
   > **Sonuç:** Eğer $\vec{v}_1, \vec{v}_2, \dots, \vec{v}_k$ vektörleri **doğrusal bağımsız** ise, bu vektörlerin tamamı birbirinden farklı (distinct) ve sıfırdan farklı (nonzero) olmak zorundadır.

### 3.4 $\mathbb{R}^4$ Uzayında Dört Vektörün Doğrusal Bağımsızlığı ve Doğrusal Birleşim Örneği

- **Verilen (ekrandan, 01:09:30 ve 01:10:45):**
  $\mathbb{R}^4$ uzayında $\vec{a} = (1, 0, 0, 1)$, $\vec{b} = (0, -1, 2, 1)$, $\vec{c} = (1, 2, 2, 1)$ ve $\vec{d} = (-2, 1, 0, 0) \in \mathbb{R}^4$ vektörleri veriliyor.
  1. $\vec{a}, \vec{b}, \vec{c}, \vec{d}$ vektörlerinin doğrusal bağımsız mı yoksa bağımlı mı olduğunu belirleyiniz.
  2. $\vec{u} = (1, -1, 2, 1)$ vektörünü $\vec{a}, \vec{b}, \vec{c}, \vec{d}$ vektörlerinin bir doğrusal birleşimi olarak ifade ediniz.

- **Adım Adım Çözüm:**
  1. **Doğrusal Bağımsızlığın Belirlenmesi (ekrandan, 01:09:30):**
     $\mathbb{R}^4$ uzayında $4$ adet vektör verildiğinden ($n = m = 4$), bu dört vektörü bir $4 \times 4$ matrisin sütunlarına yazıp determinantını hesaplayabiliriz:
     $$\det(A) = \begin{vmatrix} 1 & 0 & 1 & -2 \\ 0 & -1 & 2 & 1 \\ 0 & 2 & 2 & 0 \\ 1 & 1 & 1 & 0 \end{vmatrix}$$
     1. sütundaki son elemanı sıfırlamak için 1. satırı $-1$ ile çarpıp 4. satıra ekleyelim ($-R_1 + R_4 \to R_4$):
     $$\det(A) = \begin{vmatrix} 1 & 0 & 1 & -2 \\ 0 & -1 & 2 & 1 \\ 0 & 2 & 2 & 0 \\ 0 & 1 & 0 & 2 \end{vmatrix}$$
     Şimdi 1. sütuna göre Laplace açılımı yapıp oluşan $3 \times 3$ determinantı Sarrus kuralıyla hesaplayalım:
     $$\det(A) = 1 \cdot (-1)^{1+1} \begin{vmatrix} -1 & 2 & 1 \\ 2 & 2 & 0 \\ 1 & 0 & 2 \end{vmatrix} = ((-4 + 0 + 0) - (2 + 0 + 8)) = -4 - 2 - 8 = -14 \neq 0$$
     Determinant sıfırdan farklı ($-14 \neq 0$) olduğundan $x_1\vec{a} + x_2\vec{b} + x_3\vec{c} + x_4\vec{d} = \vec{0}$ homojen sisteminin yalnızca sıfır çözümü ($x_1 = x_2 = x_3 = x_4 = 0$) vardır; dolayısıyla $\vec{a}, \vec{b}, \vec{c}, \vec{d}$ vektörleri **doğrusal bağımsızdır**.

  2. **$\vec{u} = (1, -1, 2, 1)$ Vektörünün Doğrusal Birleşim Olarak Yazılması (ekrandan, 01:10:45):**
     $c_1\vec{a} + c_2\vec{b} + c_3\vec{c} + c_4\vec{d} = (1, -1, 2, 1)$ denklemini kurduğumuzda şu doğrusal sistem elde edilir:
     $$\begin{cases} c_1 + c_3 - 2c_4 = 1 \\ -c_2 + 2c_3 + c_4 = -1 \\ 2c_2 + 2c_3 = 2 \\ c_1 + c_2 + c_3 = 1 \end{cases}$$
     Genişletilmiş matrisi Gauss-Jordan yöntemiyle RREF formuna indirgediğimizde:
     $$[A \mid \mathbf{b}] = \begin{pmatrix} 1 & 0 & 1 & -2 & 1 \\ 0 & -1 & 2 & 1 & -1 \\ 0 & 2 & 2 & 0 & 2 \\ 1 & 1 & 1 & 0 & 1 \end{pmatrix} \sim \begin{pmatrix} 1 & 0 & 0 & 0 & 0 \\ 0 & 1 & 0 & 0 & \frac{6}{7} \\ 0 & 0 & 1 & 0 & \frac{1}{7} \\ 0 & 0 & 0 & 1 & -\frac{3}{7} \end{pmatrix}$$
     Buradan skalerler:
     $$c_1 = 0, \quad c_2 = \frac{6}{7}, \quad c_3 = \frac{1}{7}, \quad c_4 = -\frac{3}{7}$$
     olarak bulunur (Slaytta son eleman baskı hatasıyla $c_3 = -3/7$ olarak yazılmıştır, doğrusu $c_4 = -3/7$'dir). Böylece:
     $$\vec{u} = 0\vec{a} + \frac{6}{7}\vec{b} + \frac{1}{7}\vec{c} - \frac{3}{7}\vec{d}$$

## 4. Germe Kümeleri / Geren Küme (Spanning Sets)

### 4.1 Gerilen Küme ($\text{span}(S)$) Tanımı ve Altuzay Özelliği

Doğrusal birleşimler, vektör uzaylarını ve altuzayları tarif etmede çok önemli bir rol oynar: bir vektör uzayındaki bir vektör kümesinin olası tüm doğrusal birleşimlerinin kümesi bize yeni bir alt vektör uzayı verir.

- **Tanım (Gerilen Küme / Span — ekrandan, 01:17:00):**
  $V$ bir vektör uzayı ve $S = \{\vec{v}_1, \vec{v}_2, \dots, \vec{v}_r\} \subset V$ bu uzayın bir alt kümesi olsun. $S$ kümesi tarafından **gerilen küme** (the set spanned by $S$), $\text{span}(S)$ veya $\langle S \rangle$ ile gösterilir ve $S$'deki vektörlerin **olası tüm doğrusal birleşimlerinin kümesi** olarak tanımlanır:
  $$\text{span}(S) = \langle S \rangle = \{k_1 \vec{v}_1 + k_2 \vec{v}_2 + \dots + k_r \vec{v}_r \mid k_1, k_2, \dots, k_r \in \mathbb{R}\}$$

> **Hocanın vurgusu (Önemli Not — ekrandan, 01:17:00):**
> $\text{span}(S)$ kümesi her zaman $V$ vektör uzayının bir **alt vektör uzayıdır (altuzayıdır / subspace of $V$)**.

### 4.2 $M_{2 \times 3}$ Matrisler Uzayında ve $\mathbb{R}^4$ Uzayında Germe Kümesi Örnekleri

#### Örnek 1: $M_{2 \times 3}$ Uzayında Dört Matrisin Gerdiği Altuzay

- **Verilen (ekrandan, 01:17:00):**
  $2 \times 3$ boyutlu matrisler uzayı $M_{2 \times 3}$ içinde:
  $$S = \left\{ v_1 = \begin{bmatrix} 1 & 0 & 0 \\ 0 & 0 & 0 \end{bmatrix}, \quad v_2 = \begin{bmatrix} 0 & 1 & 0 \\ 0 & 0 & 0 \end{bmatrix}, \quad v_3 = \begin{bmatrix} 0 & 0 & 0 \\ 0 & 1 & 0 \end{bmatrix}, \quad v_4 = \begin{bmatrix} 0 & 0 & 0 \\ 0 & 0 & 1 \end{bmatrix} \right\}$$
  kümesi tarafından gerilen $\text{span}(S)$ kümesini bulunuz.
- **Çözüm:**
  Tanım gereği $\text{span}(S)$, $v_1, v_2, v_3, v_4$ matrislerinin tüm doğrusal birleşimlerinin kümesidir:
  $$\text{span}(S) = \{a v_1 + b v_2 + c v_3 + d v_4 \mid a, b, c, d \in \mathbb{R}\}$$
  $$= \left\{ a\begin{bmatrix} 1 & 0 & 0 \\ 0 & 0 & 0 \end{bmatrix} + b\begin{bmatrix} 0 & 1 & 0 \\ 0 & 0 & 0 \end{bmatrix} + c\begin{bmatrix} 0 & 0 & 0 \\ 0 & 1 & 0 \end{bmatrix} + d\begin{bmatrix} 0 & 0 & 0 \\ 0 & 0 & 1 \end{bmatrix} \,\middle|\, a, b, c, d \in \mathbb{R} \right\}$$
  $$= \left\{ \begin{bmatrix} a & b & 0 \\ 0 & c & d \end{bmatrix} \,\middle|\, a, b, c, d \in \mathbb{R} \right\} \subset M_{2 \times 3}$$
  Yani $\text{span}(S)$, $M_{2 \times 3}$ uzayında $(1, 3)$ ve $(2, 1)$ bileşenleri sıfır olan tüm $2 \times 3$ boyutlu matrislerin oluşturduğu altuzaydır.

#### Örnek 2: Tek Bir Vektörün ve $\mathbb{R}^4$'te İki Vektörün Gerdiği Küme

- **Tek Vektör Durumu:** Eğer $S = \{\vec{u}\}$ yalnızca tek bir vektörden oluşuyorsa, $\text{span}(S) = \{k\vec{u} \mid k \in \mathbb{R}\}$ ($\vec{u}$ vektörünün tüm skaler katları) olur.
- **$\mathbb{R}^4$ Uzayında İki Vektörün Gerdiği Küme (ekrandan, 01:19:15):**
  $S = \{\vec{u} = (1, -2, 1, 3), \, \vec{v} = (0, 2, -1, 0)\} \subset \mathbb{R}^4$ kümesinin gerdiği $\text{span}(S)$ kümesi:
  $$\text{span}(\{(1, -2, 1, 3), \, (0, 2, -1, 0)\}) = \{a(1, -2, 1, 3) + b(0, 2, -1, 0) \mid a, b \in \mathbb{R}\}$$
  $$= \{(a, \, -2a + 2b, \, a - b, \, 3a) \mid a, b \in \mathbb{R}\} \subset \mathbb{R}^4$$

## Örnek Sorular

1. **Doğrusal Birleşim Olma Koşulu ve $k$ Parametresinin Bulunması** (ekrandan, 00:49:15)
   - **Soru:** $k$'nın hangi değerleri için $\vec{w} = (1, -2, k) \in \mathbb{R}^3$ vektörü, $\vec{u} = (3, 0, -2)$ ve $\vec{v} = (2, -1, 5)$ vektörlerinin bir doğrusal birleşimi olarak yazılabilir?
   - **Çözüm (derste verildi):** $\vec{w} = a_1\vec{u} + a_2\vec{v}$ eşitliğinden $3a_1 + 2a_2 = 1$, $-a_2 = -2$ ve $-2a_1 + 5a_2 = k$ sistemi kurulur. İkinci denklemden $a_2 = 2$, birinci denklemden $3a_1 = 1 - 4 = -3 \implies a_1 = -1$ ve üçüncü denklemden $k = -2(-1) + 5(2) = 12$ bulunur.

2. **Sıfır Vektöründen Oluşan Kümenin Doğrusal Bağımlılığı** (derste sözlü ve ekrandan, 00:57:10–01:00:05)
   - **Soru:** Yalnızca sıfır vektöründen oluşan $S = \{\vec{0}\}$ kümesi doğrusal bağımlı mıdır, yoksa doğrusal bağımsız mıdır? Neden?
   - **Çözüm (derste verildi):** Doğrusal bağımlıdır. Çünkü $a_1 \vec{v}_1 = \vec{0}$ denkleminde $\vec{v}_1 = \vec{0}$ olduğundan, $a_1 = 5 \neq 0$ gibi sıfırdan farklı her reel sayı için $5 \cdot \vec{0} = \vec{0}$ eşitliği sağlanır. Sıfırdan farklı skaler bulunabildiği için $\{\vec{0}\}$ doğrusal bağımlıdır.

3. **$\mathbb{R}^4$ Uzayında Dört Vektörün Doğrusal Bağımsızlığı ve Doğrusal Birleşim Hesabı** (ekrandan, 01:09:30 ve 01:10:45)
   - **Soru:** $\vec{a} = (1, 0, 0, 1)$, $\vec{b} = (0, -1, 2, 1)$, $\vec{c} = (1, 2, 2, 1)$ ve $\vec{d} = (-2, 1, 0, 0) \in \mathbb{R}^4$ vektörleri doğrusal bağımsız mıdır? $\vec{u} = (1, -1, 2, 1)$ vektörünü bu dört vektörün doğrusal birleşimi olarak yazınız.
   - **Çözüm (derste verildi):**
     - Vektörler sütunlara yazılıp determinantı alındığında $\det(A) = -14 \neq 0$ çıktığından dört vektör **doğrusal bağımsızdır**.
     - $c_1\vec{a} + c_2\vec{b} + c_3\vec{c} + c_4\vec{d} = (1, -1, 2, 1)$ sistemi Gauss-Jordan indirgemesiyle çözüldüğünde $c_1 = 0, \, c_2 = \frac{6}{7}, \, c_3 = \frac{1}{7}, \, c_4 = -\frac{3}{7}$ bulunur.

## Dersin Toparlaması

Bu derste bir vektör uzayındaki vektörlerin **doğrusal bağımlılığı ve bağımsızlığı** tanımlanmış; $x_1\vec{v}_1 + \dots + x_n\vec{v}_n = \vec{0}$ homojen sisteminin yalnızca sıfır çözümüne sahip olması ($\mathbb{R}^n$'de $n$ vektör için $\det(A) \neq 0$ olması) durumunda vektörlerin doğrusal bağımsız, sıfırdan farklı çözümlere sahip olması durumunda ise doğrusal bağımlı olduğu gösterilmiştir. Ardından bir vektörün diğer vektörlerin **doğrusal birleşimi** (linear combination) olarak yazılabilmesi koşulu ($AX = b$ sisteminin tutarlı olması), doğrusal bağımlılık/bağımsızlık teoremleri (alt küme/üst küme ilişkisi, $\{\vec{0}\}$ kümesinin ve $\vec{0}$ içeren her kümenin doğrusal bağımlı olması) ve bir $S$ kümesinin olası tüm doğrusal birleşimlerinden oluşan **germe kümesi** ($\text{span}(S)$) kavramı işlenmiştir. Bir sonraki derste germe kümeleri ile doğrusal bağımsızlığı birleştirerek bir vektör uzayının bazı (tabanı / basis) ve boyutu (dimension) konularına geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
