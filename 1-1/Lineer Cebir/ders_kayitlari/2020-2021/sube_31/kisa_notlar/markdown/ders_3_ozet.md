# Ders 3 Çalışma Özeti

## Genel Konular

- Dik (Orthonormal / Orthogonal) Matrisler (Orthogonal Matrices)
  - Elemanları reel sayılar olan bir $A$ matrisinin devriği (transpose) tersine eşitse ($A^T = A^{-1}$), yani $A A^T = A^T A = I$ koşulunu sağlıyorsa $A$'ya dik matris (orthogonal matrix) denir; bu tanım gereği dik matris mutlaka kare ve tersinir (invertible) olmalıdır (ekrandan, 00:12:10).
  - Örneğin $A = \begin{pmatrix} \cos\theta & \sin\theta \\ -\sin\theta & \cos\theta \end{pmatrix}$ matrisi için $A A^T = \begin{pmatrix} \cos^2\theta+\sin^2\theta & 0 \\ 0 & \sin^2\theta+\cos^2\theta \end{pmatrix} = I_2$ olduğundan $A$ bir dik matristir (ekrandan, 00:12:10).
- Karmaşık Matrisler, Eşlenik ve Eşlenik Devrik (Complex Matrices, Conjugate, and Conjugate Transpose)
  - Karmaşık sayılar kümesi $\mathbb{C} = \{a + bi \mid a, b \in \mathbb{R},\ i^2 = -1\}$ olup bir $c = a + bi$ karmaşık sayısının eşleniği (conjugate) sanal kısmın işaretinin değiştirilmesiyle $\bar{c} = a - bi$ olarak bulunur.
  - Elemanları karmaşık sayılar olan bir $A = [a_{ij}]$ karmaşık matrisinin eşleniği (conjugate of $A$), her bir elemanın karmaşık eşleniği alınarak $\bar{A} = [\bar{a}_{ij}]$ biçiminde elde edilir.
  - Eşlenik alma ve devrik alma işlemleri birbiriyle değişmelidir (commute); bir $A$ matrisinin eşleniğinin devriği (veya devriğinin eşleniği) $A^H$ ya da $A^*$ ile gösterilir: $A^H = A^* = (\bar{A})^T = \overline{(A^T)}$ (ekrandan, 00:22:35).
- Hermityen, Ters Hermityen ve Üniter Matrisler (Hermitian, Skew-Hermitian, and Unitary Matrices)
  - Hermityen matris (Hermitian matrix): Eşlenik devriği kendisine eşit olan ($A^H = A^* = A$) karmaşık kare matristir. Bir matrisin Hermityen olması için gerek ve yeter şart esas köşegen elemanlarının tamamının reel sayı olması ($a_{ii} = \bar{a}_{ii} \in \mathbb{R}$) ve köşegen dışındaki simetrik elemanların birbirinin eşleniği olmasıdır ($a_{ij} = \bar{a}_{ji}$) (ekrandan, 00:34:05).
  - Ters Hermityen matris (skew-Hermitian matrix): Eşlenik devriği kendisinin negatifine eşit olan ($A^H = A^* = -A$) karmaşık kare matristir. Bu matrislerde esas köşegen elemanları ($a_{ii} = -\bar{a}_{ii}$) ya $0$ ya da yalnızca sanal kısımdan oluşan (pür sanal / purely imaginary) karmaşık sayılar olmak zorundadır; diğer elemanlar ise $a_{ij} = -\bar{a}_{ji}$ koşulunu sağlar (ekrandan, 00:34:05).
  - Üniter matris (unitary matrix): Eşlenik devriği ile çarpımı birim matrisi veren ($A^* A = A A^* = I$, yani $A^* = A^{-1}$) karmaşık kare matristir.
- Satır Eşelon ve İndirgenmiş Satır Eşelon Formu (Row Echelon Form - REF and Reduced Row Echelon Form - RREF)
  - Bir $m \times n$ boyutlu $A$ matrisi aşağıdaki dört özelliği sağlıyorsa **indirgenmiş satır eşelon formunda** (reduced row echelon form - RREF) denir (ekrandan, 00:47:15):
    - a) Varsa tamamen sıfırlardan oluşan satırlar (zero rows) matrisin en altında yer alır.
    - b) Sıfırdan farklı her satırda soldan ilk sıfırdan farklı eleman $1$'dir; bu elemana o satırın **öncü $1$'i** (leading one) denir.
    - c) Sıfırdan farklı her satırda öncü $1$, kendisinden önceki (üstteki) satırların öncü $1$'lerinin daha sağında ve altında yer alır (merdiven / staircase yapısı oluşturur).
    - d) Bir sütunda öncü $1$ varsa, o sütundaki diğer tüm elemanlar (hem altındakiler hem üstündekiler) $0$'dır.
  - Eğer bir matris yalnızca ilk üç özelliği (a, b ve c) sağlıyor ancak d özelliğini sağlamıyorsa (öncü $1$'lerin altında sıfırlar var fakat üstünde sıfırdan farklı sayılar bulunabiliyorsa) bu matrise **satır eşelon formunda** (row echelon form - REF) denir.
- Elementer Satır İşlemleri, Satır Denkliği ve Pivot Kavramı (Elementary Row Operations, Row Equivalence, and Pivots)
  - Bir matris üzerindeki üç temel (elementer) satır işlemi (elementary row operations) şunlardır (ekrandan, 01:02:15):
    - Tip I (Type I): Herhangi iki satırın yer değiştirmesi ($r_i \leftrightarrow r_j$).
    - Tip II (Type II): Bir satırın sıfırdan farklı bir $k$ sayısı ile çarpılması ($k r_i \to r_i$).
    - Tip III (Type III): Bir satırın $k$ katının başka bir satıra eklenmesi ($k r_i + r_j \to r_j$).
  - Bir matris diğerinden sonlu sayıda elementer satır işlemi uygulanarak elde edilebiliyorsa bu iki matrise **satırca denk** (row equivalent) matrisler denir.
  - Sıfırdan farklı her $m \times n$ matris, satır eşelon formundaki bir matrise satırca denktir ve bir matrisin indirgenmiş satır eşelon formu (RREF) **tektir** (unique) (ekrandan, 01:14:40).
  - Herhangi bir matriste sıfırdan farklı eleman içeren ilk sütuna **pivot sütunu** (pivot column), pivot sütunundaki ilk sıfırdan farklı elemana ise **pivot** denir (ekrandan, 01:14:40).

## Hocanın Özellikle Vurguladığı Kısımlar

- Hermityen ve Ters Hermityen Matrislerde Esas Köşegen Kontrolü
  - Bir karmaşık kare matrisin Hermityen olup olmadığını anlamak için önce esas köşegenine bakılır: Esas köşegen üzerindeki tüm elemanlar reel sayı olmak zorundadır (çünkü bir sayının eşleniğinin kendisine eşit olması ancak sanal kısmının olmamasıyla mümkündür).
  - Ters Hermityen (skew-Hermitian) matriste ise esas köşegen üzerindeki elemanlar ($a_{ii} = -\bar{a}_{ii}$) asla sıfırdan farklı bir reel sayı olamaz; yalnızca $0$ veya reel kısmı olmayan pür sanal sayı (örneğin $i, -3i$) olabilir (ekrandan, 00:34:05).
- Satır Eşelon Formu (REF) ile İndirgenmiş Satır Eşelon Formu (RREF) Arasındaki Fark
  - Her iki formda da sıfır satırları en alttadır, sıfırdan farklı satırların ilk elemanı öncü $1$'dir (leading one) ve öncü $1$'ler merdiven (staircase) biçiminde sağ-aşağı doğru ilerler.
  - Fark dördüncü koşuldadır: RREF'te öncü $1$ içeren bir sütunda öncü $1$'in hem altındaki hem de **üstündeki** tüm elemanlar $0$ olmak zorundadır; REF'te ise yalnızca altındakiler $0$'dır, üstünde sıfırdan farklı sayılar bulunabilir.
- Sütun İşlemleri Yerine Yalnızca Satır İşlemlerinin Kullanılması
  - Teorik olarak sütun eşelon formu ve elementer sütun işlemleri ($c_i \leftrightarrow c_j$ vb.) tanımlanabilse de hoca, karışıklığa yol açtığı için sütun işlemlerinin **kullanılmamasını**, tüm indirgeme işlemlerinin yalnızca **elementer satır işlemleri** (elementary row operations) ile yapılmasını özellikle vurgulamıştır.

## Kısa Tekrar Notları

- Dik matris (orthogonal matrix): $A \in \mathbb{R}^{n \times n}$ için $A^T = A^{-1} \iff A A^T = A^T A = I_n$.
- Eşlenik devrik (conjugate transpose): $A^H = A^* = (\bar{A})^T = \overline{(A^T)}$.
- Hermityen matris: $A^* = A \iff a_{ij} = \bar{a}_{ji}$ (esas köşegen elemanları reeldir: $a_{ii} \in \mathbb{R}$).
- Ters Hermityen matris: $A^* = -A \iff a_{ij} = -\bar{a}_{ji}$ (esas köşegen elemanları $0$ veya pür sanaldır).
- Üniter matris (unitary matrix): $A^* A = A A^* = I_n \iff A^* = A^{-1}$.
- İndirgenmiş satır eşelon formu (RREF) koşulları: (a) Sıfır satırları en altta, (b) her sıfırdan farklı satırın soldan ilk elemanı öncü $1$ (leading one), (c) öncü $1$'ler üstteki öncü $1$'lerin sağında (merdiven yapısı), (d) öncü $1$'lerin bulunduğu sütunlardaki diğer tüm elemanlar $0$.
- Satır eşelon formu (REF): RREF'in yalnızca (a), (b) ve (c) koşullarını sağlar.
- Elementer satır işlemleri: Tip I ($r_i \leftrightarrow r_j$), Tip II ($k r_i \to r_i,\ k \neq 0$), Tip III ($k r_i + r_j \to r_j$).
- Bir matrisin RREF'i tektir (unique); REF'i ise uygulanan satır işlemlerinin sırasına göre farklılık gösterebilir.

## Detaylı Açıklamalar

- **Dik (Orthogonal) Matris veKarmaşık Matris Türleri:**
  - **Dik Matris Örneği:** $A = \begin{pmatrix} \cos\theta & \sin\theta \\ -\sin\theta & \cos\theta \end{pmatrix}$ reel matrisinin dik olup olmadığını kontrol etmek için $A$ ile devriği olan $A^T = \begin{pmatrix} \cos\theta & -\sin\theta \\ \sin\theta & \cos\theta \end{pmatrix}$ çarpılır (ekrandan, 00:12:10):
    $$A A^T = \begin{pmatrix} \cos\theta & \sin\theta \\ -\sin\theta & \cos\theta \end{pmatrix} \begin{pmatrix} \cos\theta & -\sin\theta \\ \sin\theta & \cos\theta \end{pmatrix} = \begin{pmatrix} \cos^2\theta+\sin^2\theta & -\cos\theta\sin\theta+\sin\theta\cos\theta \\ -\sin\theta\cos\theta+\cos\theta\sin\theta & \sin^2\theta+\cos^2\theta \end{pmatrix} = \begin{pmatrix} 1 & 0 \\ 0 & 1 \end{pmatrix} = I_2$$
    $A A^T = I_2$ olduğundan $A$ dik bir matristir.
  - **Eşlenik Devrik ($A^H = A^*$) Örneği:** $2 \times 3$ boyutlu bir karmaşık matrisin eşlenik devriği iki adımda bulunur (ekrandan, 00:22:35):
    $$A = \begin{pmatrix} 2+8i & 5-3i & 4-7i \\ 6i & 1-4i & 3+2i \end{pmatrix} \implies \bar{A} = \begin{bmatrix} 2-8i & 5+3i & 4+7i \\ -6i & 1+4i & 3-2i \end{bmatrix}$$
    $$A^H = A^* = (\bar{A})^T = \begin{bmatrix} 2-8i & -6i \\ 5+3i & 1+4i \\ 4+7i & 3-2i \end{bmatrix}$$
  - **Hermityen ve Üniter Matris İncelemesi:** Derste iki adet $3 \times 3$ karmaşık matris incelenmiştir (ekrandan, 00:38:30):
    $$A = \begin{pmatrix} 3 & 1-2i & 4+7i \\ 1+2i & -4 & -2i \\ 4-7i & 2i & 5 \end{pmatrix}, \quad B = \frac{1}{2}\begin{pmatrix} 1 & -i & -1+i \\ i & 1 & 1+i \\ 1+i & -1+i & 0 \end{pmatrix}$$
    - $A$ matrisinin esas köşegen elemanları $3, -4, 5$ olup tamamı reel sayıdır. Köşegen dışındaki elemanlar karşılaştırıldığında $a_{21} = 1+2i = \overline{1-2i} = \bar{a}_{12}$, $a_{31} = 4-7i = \overline{4+7i} = \bar{a}_{13}$ ve $a_{32} = 2i = \overline{-2i} = \bar{a}_{23}$ olduğu, yani her $i, j$ için $a_{ij} = \bar{a}_{ji}$ ($A^* = A$) sağlandığı görülür; dolayısıyla $A$ **Hermityen** bir matristir.
    - $B$ matrisinde esas köşegen üzerinde $1$ (sıfırdan farklı reel sayı) bulunduğu için $B$ ters Hermityen (skew-Hermitian) olamaz. Esas köşegeni reel ve $b_{21} = i = \overline{-i} = \bar{b}_{12}$ olmasına rağmen $b_{31} = 1+i$ iken $\bar{b}_{13} = \overline{-1+i} = -1-i \neq b_{31}$ olduğundan Hermityen de değildir. Ancak $B^* B = I_3$ çarpımı sağlandığından $B$ bir **üniter matristir** (unitary matrix).

- **İndirgenmiş Satır Eşelon Formu (RREF) ve Satır Eşelon Formu (REF) Örnekleri:**
  - **RREF Örnekleri:** Aşağıdaki $A, B, C$ matrisleri dört koşulu da sağladıkları için indirgenmiş satır eşelon formundadır (ekrandan, 00:53:20):
    $$A = \begin{pmatrix} 1 & 0 & 0 & 0 \\ 0 & 1 & 0 & 0 \\ 0 & 0 & 1 & 0 \\ 0 & 0 & 0 & 1 \end{pmatrix}, \quad B = \begin{pmatrix} 1 & 0 & 0 & 0 & -2 & 4 \\ 0 & 1 & 0 & 0 & 4 & 8 \\ 0 & 0 & 0 & 1 & 7 & -2 \\ 0 & 0 & 0 & 0 & 0 & 0 \\ 0 & 0 & 0 & 0 & 0 & 0 \end{pmatrix}, \quad C = \begin{pmatrix} 1 & 2 & 0 & 0 & 1 \\ 0 & 0 & 1 & 2 & 3 \\ 0 & 0 & 0 & 0 & 0 \end{pmatrix}$$
  - **RREF Olmayan ve REF Olan Matris Örnekleri:**
    - 2. satırı tamamen sıfır olup 3. satırında sıfırdan farklı eleman bulunan bir $D$ matrisi (a koşulunu ihlal ettiği için), sıfırdan farklı bir satırının ilk elemanı $1$ yerine $2$ olan bir $E$ matrisi (b koşulunu ihlal ettiği için) ve $F = \begin{pmatrix} 1 & 0 & 3 & 4 \\ 0 & 1 & -2 & 5 \\ 0 & 1 & 2 & 2 \\ 0 & 0 & 0 & 0 \end{pmatrix}$ matrisi (3. satırdaki öncü $1$, 2. satırdaki öncü $1$'in sağında değil tam altında olduğu, yani c koşulunu ihlal ettiği için) eşelon formda değildir (ekrandan, 00:56:15).
    - Buna karşılık $G = \begin{pmatrix} 1 & 2 & 3 & 4 \\ 0 & 1 & -2 & 5 \\ 0 & 0 & 1 & 2 \\ 0 & 0 & 0 & 0 \end{pmatrix}$ ve $H = \begin{pmatrix} 1 & 5 & 0 & 2 & -2 & 4 \\ 0 & 1 & 0 & 3 & 4 & 8 \\ 0 & 0 & 0 & 1 & 7 & -2 \\ 0 & 0 & 0 & 0 & 0 & 0 \end{pmatrix}$ matrisleri (a), (b) ve (c) koşullarını sağladıkları için **satır eşelon formundadır (REF)**; ancak 2. sütundaki öncü $1$'lerin üstünde $2$ ve $5$ gibi sıfırdan farklı sayılar bulunduğu için (d koşulunu sağlamadıklarından) indirgenmiş satır eşelon formunda (RREF) değildirler (ekrandan, 00:56:15).

- **Elementer Satır İşlemleriyle Bir Matrisi REF ve RREF'e İndirgeme:**
  Derste $A = \begin{pmatrix} 0 & 0 & 1 & 2 \\ 2 & 3 & 0 & -2 \\ 3 & 3 & 6 & -9 \end{pmatrix}$ matrisi önce ayrı ayrı üç elementer satır işlemini göstermek için kullanılmış (ekrandan, 01:08:30), ardından aynı matris adım adım hem REF hem de RREF formuna dönüştürülmüştür (ekrandan, 01:14:40 ve 01:26:50):
  1. Sıfırdan farklı eleman içeren ilk sütun 1. sütundur (pivot sütunu). 1. satırın başında öncü $1$ elde etmek için 1. satır ile 3. satır yer değiştirilir ($r_1 \leftrightarrow r_3$):
     $$B = A_{r_1 \leftrightarrow r_3} = \begin{pmatrix} 3 & 3 & 6 & -9 \\ 2 & 3 & 0 & -2 \\ 0 & 0 & 1 & 2 \end{pmatrix}$$
  2. 1. satır $\frac{1}{3}$ ile çarpılarak 1. satırda öncü $1$ oluşturulur ($\frac{1}{3}r_1 \to r_1$):
     $$C = B_{\frac{1}{3}r_1 \to r_1} = \begin{pmatrix} 1 & 1 & 2 & -3 \\ 2 & 3 & 0 & -2 \\ 0 & 0 & 1 & 2 \end{pmatrix}$$
  3. 1. sütundaki öncü $1$'in altındaki $2$ elemanını sıfırlamak için 1. satırın $-2$ katı 2. satıra eklenir ($-2r_1 + r_2 \to r_2$):
     $$D = C_{-2r_1 + r_2 \to r_2} = \begin{pmatrix} 1 & 1 & 2 & -3 \\ 0 & 1 & -4 & 4 \\ 0 & 0 & 1 & 2 \end{pmatrix}$$
     Elde edilen bu $D$ matrisi (a), (b) ve (c) koşullarını sağladığından $A$ matrisinin bir **satır eşelon formudur (REF)**.
  4. İndirgenmiş satır eşelon formuna (RREF) geçmek için öncü $1$'lerin üstündeki elemanlar da sıfırlanır. Önce 2. sütundaki öncü $1$'in üstündeki $1$'i sıfırlamak amacıyla 2. satırın $-1$ katı 1. satıra eklenir ($-r_2 + r_1 \to r_1$):
     $$E = D_{-r_2 + r_1 \to r_1} = \begin{pmatrix} 1 & 0 & 6 & -7 \\ 0 & 1 & -4 & 4 \\ 0 & 0 & 1 & 2 \end{pmatrix}$$
  5. Son olarak 3. sütundaki öncü $1$'in üstündeki $-4$ ve $6$ elemanlarını sıfırlamak için 3. satırın $4$ katı 2. satıra ($4r_3 + r_2 \to r_2$) ve 3. satırın $-6$ katı 1. satıra ($-6r_3 + r_1 \to r_1$) eklenir:
     $$\text{RREF}(A) = \begin{pmatrix} 1 & 0 & 0 & -19 \\ 0 & 1 & 0 & 12 \\ 0 & 0 & 1 & 2 \end{pmatrix}$$

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
