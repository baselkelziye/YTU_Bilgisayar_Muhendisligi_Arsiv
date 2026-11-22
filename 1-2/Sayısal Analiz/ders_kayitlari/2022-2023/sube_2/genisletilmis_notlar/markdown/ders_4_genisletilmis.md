# Ders 4 Genişletilmiş Notu: Doğrusal Denklem Takımlarının Çözüm Yöntemleri, Doğrusal Olmayan Denklem Takımları ve Sayısal Türev

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Kısa Tekrarı: Matrisin Tersi
- 2. Lineer Denklem Takımları
- 3. Dolaysız Yöntemler: Cramer Yöntemi
- 4. Dolaysız Yöntemler: Gauss Yok Etme (Eliminasyon) Yöntemi
- 5. Gauss-Jordan Yöntemi
- 6. Yoğunlaştırılmış Yok Etme: Cholesky (LU) Yöntemi
- 7. Dolaylı Yöntemler: Jacobi İterasyon Yöntemi
- 8. Gauss-Seidel İterasyon Yöntemi
- 9. Doğrusal Olmayan Denklem Takımlarının Çözümü (Newton-Raphson)
- 10. Sayısal Türev
- 11. Taylor Serisi ile Sayısal Türev
- 12. Sayısal Türevin Newton-Raphson'da Kullanımı
- Örnek Sorular
- Dersin Toparlaması

## 1. Önceki Dersin Kısa Tekrarı: Matrisin Tersi

Hoca derse geçen haftanın beş dakikalık bir özetiyle başladı. Doğrusal (lineer) denklem, bilinmeyenlerin önünde yalnızca sabit çarpanların bulunduğu, kare ya da daha yüksek kuvvet içermeyen denklemdir. Bir doğruyu, iki değişkenden fazlası olduğunda da bir düzlemi ifade eder; örneğin $2x+3y=\dots$ gibi. Böyle denklemlerden oluşan bir takımı çözmek için bilinmeyen sayısı kadar denkleme ihtiyaç vardır.

Bu çözümler için lineer cebir bilgisi gerekir. Geçen derste matris türleri (transpoz, simetrik, köşegen matris vb.), matrisin tersi ve elementer satır işlemleri hatırlatılmıştı. Elementer satır işlemleriyle ters alma şöyle yapılır:

- Matrisin yanına, boyutları uyumlu bir birim matris yazılır.
- En üstteki köşegen elemanından başlanarak köşegen elemanı 1 yapılır, sonra onun altındaki elemanlar sıfırlanır.
- Sonraki köşegen elemanı 1 yapılır, altındakiler ve üstündekiler sıfırlanır. Bu, sol taraf tamamen birim matris olana kadar sürer.
- Sol taraf birim matris olduğunda sağ taraftaki matris, orijinal matrisin tersidir.

Kare olmayan bir matrisin tersi doğrudan alınamaz. Bu durumda matris transpozuyla çarpılarak ($A^TA$ ya da $AA^T$) yaklaşık bir ters alma işlemi yapılabilir. Gauss-Jordan yöntemi, anlatılan bu yöntemin daha genel, algoritmik halidir. $3\times3$ örnekte birinci satır $a_{11}=5$'e bölünerek köşegen 1 yapılmış, ardından diğer satırlarda o sütun sıfırlanmıştı.

## 2. Lineer Denklem Takımları

Genel olarak bir lineer denklem takımı $n$ bilinmeyenli $m$ adet denklemden oluşur (ekrandan, 00:15:00):

$$
\begin{aligned}
a_{11}x_1 + a_{12}x_2 + \dots + a_{1n}x_n &= c_1\\
a_{21}x_1 + a_{22}x_2 + \dots + a_{2n}x_n &= c_2\\
&\ \,\vdots\\
a_{m1}x_1 + a_{m2}x_2 + \dots + a_{mn}x_n &= c_m
\end{aligned}
$$

Burada $a_{11}$ birinci denklemdeki birinci bilinmeyenin katsayısı, $a_{12}$ birinci denklemdeki ikinci bilinmeyenin katsayısı, $c_1$ ise birinci denklemin sağ tarafıdır. Hoca tahtaya örnek olarak $2x-8y+5z-88t=2$ gibi dört bilinmeyenli bir denklem yazdı. Dört bilinmeyen varsa en az dört denkleme ihtiyaç vardır.

Katsayılar bir matriste, bilinmeyenler bir sütun vektöründe, sağ taraflar da bir sütun vektöründe saklanırsa takım $AX=C$ biçiminde gösterilir. Bu, aynı bilginin veri yapısına daha uygun bir halidir. Matris çarpımı yapıldığında $A$'nın birinci satırı ile $X$'in çarpımı $a_{11}x_1+a_{12}x_2+a_{13}x_3=c_1$ eşitliğini geri üretir; diğer satırlar da aynı şekilde. Dolaylı ve dolaysız algoritmaların hepsi bu matris gösterimi üzerinden çalışır.

### 2.1 Homojen ve homojen olmayan denklem takımları

$C$ vektörünün bütün elemanları sıfırsa takıma **homojen**, sıfırdan farklıysa **homojen olmayan** denklem takımı denir. Hoca bu ayrımın bu derste pek etkisi olmayacağını, ama sinyaller ve sistemler gibi sonraki derslerde homojen ve homojen olmayan (diferansiyel) denklemlerin farklı yollarla çözüldüğünü söyledi.

### 2.2 Dolaysız ve dolaylı yöntemler

- **Dolaysız yöntemler** tam çözümü (exact solution) verir ve algoritmik olarak kodlanabilir. Ancak matrisler üzerinde çalıştıkları için karmaşıklıkları bilinmeyen sayısıyla $n^3$ mertebesinde büyüyebilir.
- **Dolaylı yöntemler** bu maliyetten kaçınmak için tam çözüm yerine yaklaşık çözüm (approximate solution) arar. Kolay yöntemlerdir, birkaç istisna kuralları vardır.

## 3. Dolaysız Yöntemler: Cramer Yöntemi

Cramer yönteminde denklem takımı $[A][X]=[C]$ biçimine getirilir. Slayta göre yöntem az sayıda denklemden oluşan sistemlerin çözümünde kullanılır (ekrandan, 00:20:00). Üç bilinmeyen için $3\times3$ katsayılar matrisi, bilinmeyenlerin sütun matrisi ve sağ tarafın sütun matrisi yazılır.

$x_1$'i bulmak için $A$'nın birinci sütunu ($a_{11}, a_{21}, a_{31}$) yerine $c_1, c_2, c_3$ yazılır. Bu yeni matrisin determinantı $A$'nın determinantına bölünür:

$$
x_1 = \frac{\begin{vmatrix} c_1 & a_{12} & a_{13}\\ c_2 & a_{22} & a_{23}\\ c_3 & a_{32} & a_{33}\end{vmatrix}}{|A|},\qquad
x_2 = \frac{\begin{vmatrix} a_{11} & c_1 & a_{13}\\ a_{21} & c_2 & a_{23}\\ a_{31} & c_3 & a_{33}\end{vmatrix}}{|A|},\qquad
x_3 = \frac{\begin{vmatrix} a_{11} & a_{12} & c_1\\ a_{21} & a_{22} & c_2\\ a_{31} & a_{32} & c_3\end{vmatrix}}{|A|}
$$

Üç değişken için toplam dört determinant hesabı gerekir: $|A|$ ve üç pay determinantı. Yöntem tamamen algoritmiktir. Hoca kod yazılırken tekrara düşülmemesi gerektiğini vurguladı: verilen herhangi bir matrisin determinantını hesaplayan genel (jenerik) bir fonksiyon yazılmalı, bu fonksiyon hem pay hem payda için çağrılmalıdır.

> **Hocanın vurgusu:** Projede kullanıcıdan $n$ bilinmeyenli bir denklem alıp matris yapısını kuran ve genel bir determinant kodu yazan bir programı şimdiden alıştırma olarak yazmaya başlayın.

### 3.1 Algoritmik iyileştirme

$n$ bilinmeyen varsa $n-1$ tanesi Cramer ile bulunabilir. Sonuncu bilinmeyen için determinant hesaplamak yerine bulunan değerler denklemlerden birinde yerine koyulur. Böylece bir determinant hesabından kurtulunur. Bu fikir, birazdan Gauss yönteminin geri yerine koyma adımında da kullanılır.

### 3.2 Örnek

Slayttaki sistem (ekrandan, 00:25:00):

$$
\begin{aligned}
2x_1 - 3x_2 + 2x_3 &= -11\\
x_1 + x_2 - 2x_3 &= 8\\
3x_1 - 2x_2 - x_3 &= -1
\end{aligned}
\qquad\Rightarrow\qquad
A=\begin{bmatrix}2&-3&2\\1&1&-2\\3&-2&-1\end{bmatrix}
$$

Slayttaki kofaktör açılımı: $|A| = 2(-1-4)+3(-1+6)+2(-2-3) = -10+15-10 = -5$.

Bir öğrenci $3\times3$ determinantın nasıl hesaplandığını görmediğini söyleyince hoca Sarrus kuralını tahtada gösterdi. İlk iki satır matrisin altına yeniden yazılır, sonra çapraz çarpımlar alınır:

- Sol üstten sağ alta inen köşegenler: $2\cdot1\cdot(-1) + 1\cdot(-2)\cdot2 + 3\cdot(-3)\cdot(-2) = -2-4+18 = 12$.
- Sağ üstten sol alta inen köşegenler: $2\cdot1\cdot3 + (-2)\cdot(-2)\cdot2 + (-1)\cdot(-3)\cdot1 = 6+8+3 = 17$.
- $|A| = 12-17 = -5$.

Hesap sırasında hoca bir terimi önce $-8$ yazdı, öğrencilerden biri $+8$ olması gerektiğini söyledi ve düzeltildi. Determinant, kofaktör açılımıyla bulunan değerle aynıdır.

Pay determinantları $-5$, $-15$ ve $10$ olduğundan:

$$
x_1=\frac{-5}{-5}=1,\qquad x_2=\frac{-15}{-5}=3,\qquad x_3=\frac{10}{-5}=-2
$$

Bu değerler üç denklemi de sağlar (python ile doğrulandı).

> **Ders sonrası not:** Slayttaki matris gösteriminde $C$ sütununun son elemanı $1$ yazılmış. Denklemde bu değer $-1$'dir ve verilen çözüm ($1, 3, -2$) $-1$ ile tutarlıdır.

Hoca $2\times2$ determinantın da basit bir kuralı olduğunu ($ad-bc$), adjoint matrislerle hesaplama gibi başka yöntemler de bulunduğunu hatırlattı.

> **Hocanın vurgusu:** Sınavda elle çözülecek sorular en fazla $4\times4$ olur. $5\times5$ ve üstü zaman kaybı olduğu için sorulmaz.

## 4. Dolaysız Yöntemler: Gauss Yok Etme (Eliminasyon) Yöntemi

### 4.1 "Eliminasyon" ne demek?

Hoca sınıfa, bir şeyin "yok olmasının" matematikte ne anlama geldiğini sordu. Cevap: tamamen sıfırlamak. Hoca İngilizce okurken *elimination* ile *reduction* kavramlarının karıştırılabildiğini söyledi. *Reduction* bir şeyin azalmasıdır; *elimination* ise azalta azalta tamamen sıfıra, yok denecek duruma indirmektir.

### 4.2 Yöntemin adımları

Slayttaki adımlar (ekrandan, 00:30:00):

- Denklem sayısı bilinmeyen sayısına eşit olmalıdır.
- Denklem sistemi genişletilmiş katsayılar matrisi şeklinde yazılır.
- Elementer satır işlemleri uygulanır.
- Katsayılar matrisi üst üçgen matris haline getirilir.

### 4.3 Her lineer denklem sistemini çözer mi?

Hoca bunu iki bilinmeyenli bir örnekle açıkladı. $2x+4y=18$ denklemini çözmek için ikinci bir denklem gerekir. İkinci denklem olarak $4x+8y=36$ alınırsa bu, birincinin iki katıdır; sadeleştirilince aynı denklem elde edilir ve çözüm için yeterli bilgi yoktur. $4x+8y=-36$ alınırsa bu kez denklemler çelişir, çünkü sol taraf birincinin iki katı olduğu halde sağ taraf $36$ değildir. İki durumda da görünüşte iki bilinmeyenli iki denklemlik bir sistem vardır, ama tek bir çözüm çıkmaz.

### 4.4 Neden üst üçgen matris?

Hoca öğrencilerden değerler isteyerek tahtaya bir üst üçgen matris yazdırdı ve sağ tarafa $c_1, c_2, c_3$ koydu:

$$
\begin{bmatrix}1&2&3\\0&4&5\\0&0&6\end{bmatrix}
\begin{bmatrix}x_1\\x_2\\x_3\end{bmatrix}=
\begin{bmatrix}c_1\\c_2\\c_3\end{bmatrix}
$$

Çarpım yapılınca denklemler $x_1+2x_2+3x_3=c_1$, $4x_2+5x_3=c_2$, $6x_3=c_3$ olur. En kolay bulunacak bilinmeyen en alttaki $x_3$'tür. Hoca $c_3=12$ alarak $x_3=2$ buldu. Sonra $c_2=30$ alarak $4x_2+10=30$, yani $x_2=5$ buldu. $x_2$ ve $x_3$ bilindiğinde $x_1$ de birinci denklemden çekilir. Yani önce katsayılar matrisi bu forma getirilir, sonra aşağıdan yukarıya doğru yerine koya koya çözüme gidilir.

Genel halde (ekrandan, 00:35:00):

$$
\sum_{j=1}^{n} a_{ij}x_j = c_i \qquad (i=1,2,\dots,n)
$$

Denklem takımı bir dizi işlemle üst üçgen biçime getirilir:

$$
\begin{aligned}
a'_{11}x_1 + a'_{12}x_2 + a'_{13}x_3 + \dots + a'_{1n}x_n &= c'_1\\
a'_{22}x_2 + a'_{23}x_3 + \dots + a'_{2n}x_n &= c'_2\\
a'_{33}x_3 + \dots + a'_{3n}x_n &= c'_3\\
&\ \,\vdots\\
a'_{nn}x_n &= c'_n
\end{aligned}
$$

En sondaki denklemden başlayarak geriye doğru işlem yapılır.

### 4.5 Geri yerine koyma örneği

Slayttaki üst üçgen sistem (ekrandan, 00:35:00):

$$
\begin{bmatrix}2&-3&2\\0&1&-2\\0&0&1\end{bmatrix}
\begin{bmatrix}x\\y\\z\end{bmatrix}=
\begin{bmatrix}5\\8\\2\end{bmatrix}
$$

- Son satırdan $z=2$.
- İkinci satırdan $y-2z=8$, yani $y=12$.
- Birinci satırdan $x$ çekilir.

> **Ders sonrası not:** Hoca birinci denklemi tahtaya $2x-3y+2z=2$ diye yazdı ve $2x-36+4=2$'den $x=17$ buldu. Slayttaki sağ taraf değeri $c_1=5$ ile hesap $2x-36+4=5$, yani $x=18{,}5$ olur.

### 4.6 Sıfırlama mantığı

İşin zor tarafı köşegenin altını sıfırlamaktır. Birinci satıra dokunulmaz, algoritma birinci köşegenin hemen altındaki elemandan başlar. Örneğin o eleman $4$ olsaydı satır $4$'e bölünerek o eleman $1$ yapılabilir. Yukarıdaki satırın aynı sütunu da $1$ ise, üst satır alt satırdan çıkarılınca eleman sıfır olur. Hoca bir öğrencinin uyarısı üzerine bu noktayı yeniden açıkladı: bir satırdaki elemanı sıfırlamak için satır kendisiyle değil, başka bir satırla (en doğal olarak üst satırla) çarpılıp toplanır.

### 4.7 Sayısal örnek

Slayttaki sistem (ekrandan, 01:10:00; aynı sistem Cholesky örneğinde de kullanıldı):

$$
\begin{aligned}
3{,}6x + 2{,}4y - 1{,}8z &= 6{,}3\\
4{,}2x - 5{,}8y + 2{,}1z &= 7{,}5\\
0{,}8x + 3{,}5y + 6{,}5z &= 3{,}7
\end{aligned}
$$

Hoca, katsayılar ondalıklı olduğu için klasik yok etme yönteminde ortak kat bulmanın, determinant almanın da zor olduğunu söyledi. Bu tür sorularda Gauss yöntemi çok daha kolaydır.

- **1. işlem:** Birinci satır $a_{11}=3{,}6$'ya bölünür: $[1;\ 0{,}667;\ -0{,}5\ |\ 1{,}75]$.
- **2. işlem:** İkinci satır $a_{21}=4{,}2$'ye bölünür; böylece birinci sütunu $1$ olur: $[1;\ -5{,}8/4{,}2;\ 2{,}1/4{,}2\ |\ 7{,}5/4{,}2]$. Birinci satır bundan çıkarılır, sonra satır yeniden $4{,}2$ ile çarpılır: $[0;\ -8{,}6;\ 4{,}2\ |\ 0{,}15]$ (ara adım eklendi).
- **3. işlem:** Üçüncü satır $a_{31}=0{,}8$'e bölünür, birinci satır çıkarılır ve $0{,}8$ ile çarpılır (ekrandan, 00:40:00):

$$
\left[\begin{array}{ccc|c}1&0{,}667&-0{,}5&1{,}75\\0&-8{,}6&4{,}2&0{,}15\\0&2{,}966&6{,}9&2{,}3\end{array}\right]
$$

- **4. işlem:** İkinci satır $a_{22}=-8{,}6$'ya bölünür (ekrandan, 00:40:00):

$$
\left[\begin{array}{ccc|c}1&0{,}667&-0{,}5&1{,}75\\0&1&-0{,}489&-0{,}017\\0&2{,}966&6{,}9&2{,}3\end{array}\right]
$$

- **5. işlem:** Üçüncü satırdan ikinci satırın $2{,}966$ katı çıkarılır; $a_{32}$ sıfır olur ve $a_{33}\approx8{,}349$, $c_3\approx2{,}352$ kalır (ara adım eklendi). İstenirse satır $a_{33}$'e bölünerek $1$ yapılır; bu durumda $z$ doğrudan sağ sütunda okunur.
- **Geri yerine koyma:** önce $z$, sonra $y$, sonra $x$ bulunur:

$$
z\approx0{,}282,\qquad y\approx0{,}120,\qquad x\approx1{,}811
$$

Bu sonuç python ile (`numpy.linalg.solve` ve adım adım eliminasyon) doğrulandı.

> **Hocanın vurgusu:** Gauss yöntemi için 4, 5 bilinmeyene genellenebilen bir kodu C'de şimdiden yazmaya başlayın. Basit bir algoritmadır.

## 5. Gauss-Jordan Yöntemi

Hoca şu soruyu sordu: $z$'yi bildiğime göre işleme devam edip köşegenin üstündeki elemanları da sıfırlasam, yani katsayılar matrisini birim matris yapsam ne olur? Sağ taraftaki değerler doğrudan $x, y, z$ olur. Algoritma o noktaya kadar belli bir düzende çalışıyordu; aynı simetriyle yukarı doğru devam edilir. Buna **Gauss-Jordan yöntemi** denir. Gauss eliminasyonunda üst üçgen matris yeterlidir; Gauss-Jordan'da matris birim matrise çevrilir ve doğrudan çözüme ulaşılır.

Gauss eliminasyonu sonucunda elde edilen matristen başlanır:

- **1. adım:** $a_{23}$ sıfırlanır. İkinci satırdan, $a_{23}$ ile çarpılmış üçüncü satır çıkarılır. Üçüncü satırın köşegeni $1$ olduğu için bu işlem $a_{23}$'ü sıfırlar. Örneğin $a_{23}=4$ ise üçüncü satır $-4$ ile çarpılıp ikinci satıra eklenir.
- **2. adım:** $\alpha_{13}$ sıfırlanır. Birinci satırdan $\alpha_{13}$ ile çarpılmış üçüncü satır çıkarılır; aynı işlem $C$ matrisi için de yapılır. Sağ taraf $\beta_1-\beta_3\alpha_{13}$ olur (ekrandan, 00:45:00).
- **3. adım:** $\alpha_{12}$ sıfırlanır.

Hoca sınıfa üçüncü adımın nasıl yapılacağını sordu. Bir öğrenci birinci satırdan ikinci satırı çıkarmayı önerdi. Hoca doğrudan çıkarmanın yetmeyeceğini, katsayının kullanılması gerektiğini belirtti. Öğrenci açıkladı: ikinci satır $\alpha_{12}$ ile çarpılıp birinciden çıkarılır; örneğin $\alpha_{12}=7$ ise $1\cdot7$ çıkarıldığında $7-7=0$ olur. Bu, $\alpha_{12}$'nin negatifiyle çarpıp toplamakla aynıdır.

Bu işlemler, altındaki ve üstündeki elemanlar sıfırlanan köşegen elemanlarının $1$ olması sayesinde mümkündür. İşleme başlanan bu elemana **pivot eleman** denir. Önce pivotun altı boşaltılır, sonra diğer değişkenlere geçilir, en sonunda üst taraf temizlenir. Sonuçta $x=\gamma_1$, $y=\gamma_2$, $z=\beta_3$ gibi değerler doğrudan okunur.

Sayısal örnekte üçüncü satır $-(-0{,}489)$ ile çarpılıp ikinci satıra eklenir; birinci satır için çarpan $0{,}5$'tir. Bu iki işlemle üçüncü sütun temizlenir. Sonra ikinci satır $-0{,}667$ ile çarpılıp birinci satıra eklenir. Sonuç Gauss ile aynıdır: $x\approx1{,}811$, $y\approx0{,}120$, $z\approx0{,}282$ (python ile doğrulandı).

Hoca Gauss eliminasyonu ile Gauss-Jordan'ın birbirinin modifiye hali olduğunu söyledi.

## 6. Yoğunlaştırılmış Yok Etme: Cholesky (LU) Yöntemi

Gauss ve Gauss-Jordan kolay görünür, ama matris boyutu çok artınca matrisi alt ya da üst üçgen biçime getirmek zorlaşır. Daha sistematik bir yol, slaytta **yoğunlaştırılmış yok etme yöntemleri** başlığı altındaki **Cholesky yöntemi**dir (ekrandan, 01:05:00). Katsayılar matrisi biri alt üçgen (Lower, $L$), diğeri üst üçgen (Upper, $U$) iki matrise ayrıştırılır:

$$
AX=C,\quad A=LU \;\Rightarrow\; LUX=C
$$

$UX=Y$ denirse önce $LY=C$ çözülür, sonra $UX=Y$ çözülür. İki üçgen sistemi çözmek basit yerine koyma işlemleridir. Bu yüzden yöntem algoritmik olarak biraz iyileştirme sağlar, ama matematiksel manipülasyonu diğerlerinden fazladır: matematiği zorlayarak algoritmadan biraz kazanç sağlanır.

> **Hocanın vurgusu:** Çarpım sırası $L\cdot U$'dur, $U\cdot L$ değil. Sıraya dikkat edin.

### 6.1 $L$ ve $U$'nun bulunması

Bu örnekte $U$'nun köşegeni $1$ alınır:

$$
\begin{bmatrix}a_{11}&a_{12}&a_{13}\\a_{21}&a_{22}&a_{23}\\a_{31}&a_{32}&a_{33}\end{bmatrix}=
\begin{bmatrix}L_{11}&0&0\\L_{21}&L_{22}&0\\L_{31}&L_{32}&L_{33}\end{bmatrix}
\begin{bmatrix}1&U_{12}&U_{13}\\0&1&U_{23}\\0&0&1\end{bmatrix}
$$

$L$'nin birinci satırı $U$'nun birinci sütunuyla çarpılınca $L_{11}\cdot1+0+0=a_{11}$ olur. $L$'nin birinci satırı $U$'nun ikinci sütunuyla çarpılınca $L_{11}U_{12}=a_{12}$ olur; $L_{11}$ bilindiği için $U_{12}$ çekilir. Aynı şekilde $L_{11}U_{13}=a_{13}$'ten $U_{13}$ bulunur. Bu, sembolik çarpımın her elemanı için sırayla sürdürülür ve bütün bilinmeyenler yerine koyma yöntemiyle ortaya çıkar.

### 6.2 Örnek

Bölüm 4.7'deki sistemle (ekrandan, 01:10:00):

- $L_{11}=3{,}6$; $L_{11}U_{12}=2{,}4 \Rightarrow U_{12}=0{,}67$; $L_{11}U_{13}=-1{,}8 \Rightarrow U_{13}=-0{,}5$.
- $L_{21}=4{,}2$; $L_{21}U_{12}+L_{22}=-5{,}8 \Rightarrow L_{22}=-8{,}6$; $L_{21}U_{13}+L_{22}U_{23}=2{,}1$, yani $-2{,}1-8{,}6\,U_{23}=2{,}1 \Rightarrow U_{23}\approx-0{,}49$.
- $L_{31}=0{,}8$; $L_{31}U_{12}+L_{32}=3{,}5 \Rightarrow L_{32}=2{,}96$; $L_{31}U_{13}+L_{32}U_{23}+L_{33}=6{,}5$, yani $-0{,}4-1{,}45+L_{33}=6{,}5 \Rightarrow L_{33}\approx8{,}4$ (python: $8{,}349$).

> **Ders sonrası not:** Slaytta $U_{23}=0{,}49$ yazıyor. Kendi denklemi $-2{,}1-8{,}6\,U_{23}=2{,}1$'den $U_{23}=-0{,}488$ çıkar. Slaytın $L_{33}$ satırındaki $-1{,}45$ terimi de eksi işaretli değerle hesaplanmıştır. Gauss örneğindeki $-0{,}489$ da aynı değerdir.

$LY=C$ ileri yerine koyma ile çözülür. Hoca $Y$ değerlerini $1{,}75$; $-0{,}02$; $0{,}28$ diye okudu (python: $1{,}75$; $-0{,}0174$; $0{,}2817$). Ardından $UX=Y$ çözülür. $U$ "içinde bol sıfır olan" bir matristir: önce $x_3$, sonra $x_2$, sonra $x_1$ bulunur. Sonuç Gauss ile aynıdır: $x_1\approx1{,}811$, $x_2\approx0{,}120$, $x_3\approx0{,}282$. Zorluk hazırlık aşamasındadır: $L$ ve $U$ bir kez belli bir sistematikle bulunduktan sonra çözüm çok hızlı ilerler.

### 6.3 Karmaşıklık üzerine

Hoca internette Gauss eliminasyonu, Gauss-Jordan ve Cholesky ayrışımının zaman karmaşıklıklarına baktı. Bulduğu kaynakta Cholesky ayrışımının zaman karmaşıklığının $n^3$ mertebesinde olduğu, yer karmaşıklığının ise yaklaşık $n^2$ olduğu belirtiliyordu. Gauss-Jordan kodlarında iç içe döngüler bulunduğunu, karmaşıklığın $n^3$'e yakın, hatta onu aşan durumları olduğunu, daha yavaş çalıştığı için diğer yönteme ihtiyaç duyulduğunu söyledi. Bu tür analizlerin internette bulunabileceğini ekledi.

> **Ek bilgi (derste anlatılmadı):** Burada anlatılan, $U$'nun köşegeni $1$ olan ayrışım literatürde büyük olasılıkla Crout ayrışımı olarak geçer. "Cholesky ayrışımı" adı ise genellikle simetrik pozitif tanımlı matrisler için $A=LL^T$ biçimindeki ayrışıma verilir. Türkçe ders kaynaklarında genel LU ayrışımına da Cholesky dendiği görülür.

## 7. Dolaylı Yöntemler: Jacobi İterasyon Yöntemi

Bu üç dolaysız yöntem tam çözüm verir, ama algoritmik olarak zorlayıcı tarafları vardır. Hoca kod yazarken bile hangi işlemin önce yapılacağını sistematiğe oturtmanın ilk başta zor gelebildiğini söyledi. Daha kolay çözüm yöntemleri Jacobi iterasyonu ve onun bir alternatifi olan Gauss-Seidel iterasyonudur. Bu dolaylı yöntemler yaklaşık çözüm bulur.

Slayttaki adımlar (ekrandan, 01:20:00):

- **1. Adım:** $A$ matrisinde köşegende yer alan katsayıların mutlak değerce çarpımı maksimum olmalıdır. Gerekiyorsa elementer satır değiştirme işlemleri yapılır. Kısaca her sütunda mutlak değerce en büyük sayı köşegene getirilmelidir.
- **2. Adım:** Tüm denklemler yazıldıktan sonra birinci denklemden $x_1$, ikinci denklemden $x_2$, $n$. denklemden $x_n$ çekilerek yalnız bırakılır.
- **3. Adım:** Verilen ilk değerlerle iterasyon başlatılır. Tüm bilinmeyenler için ardışık iki kök değeri arasındaki mutlak fark verilen hatadan küçük oluncaya kadar devam edilir. Her iterasyon adımı bir önceki iterasyonun değerini kullanır.

Birinci adımdaki özelliğin İngilizce adı **diagonal dominance** (köşegen baskınlığı) dır. Sağlanmazsa yöntem çözümden ıraksayabilir.

### 7.1 Değişkenleri çekmek

Birinci denklemde $x_1$ yalnız bırakılır:

$$
x_1=\frac{c_1-a_{12}x_2-a_{13}x_3-\dots}{a_{11}},\qquad
x_2=\frac{c_2-a_{21}x_1-a_{23}x_3-\dots}{a_{22}}
$$

Diğerleri de aynı şekilde çekilir. Bir başlangıç değeri verilir, örneğin $x_1=x_2=x_3=0$ (istenen herhangi bir değer verilebilir). Bu değerler denklemlerde yerine koyulunca yeni $x_1, x_2, x_3$ bulunur. Sonraki iterasyonda $i-1$. iterasyonun değerleri ($x_1^{(i-1)}, x_2^{(i-1)}, x_3^{(i-1)}$) aynı denklemlerde yerine koyulur. Değerler belli bir noktadan sonra değişmez ya da değişim belli bir $\varepsilon$ değerinin altında kalır; o zaman algoritma durdurulur ve yaklaşık çözüm, bazen tam çözüm elde edilir. Matrisler üzerinde neredeyse hiç işlem yoktur; yalnız çarpma, toplama ve bölme vardır.

> **Hocanın vurgusu:** Değişimler arta arta gidiyorsa ıraksama vardır, bir şeyler yanlıştır. Iraksamayı önlemek için her sütunun en büyük katsayılı değişkeni köşegende olmalıdır. Elementer satır işlemlerine rağmen bu her zaman sağlanamayabilir; bu da yöntemin dezavantajıdır. Bazı durumlarda çözüme gidilemeyebilir.

### 7.2 Örnek

Slayttaki soru (ekrandan, 01:25:00): Denklem takımını Jacobi iterasyon yöntemiyle çözünüz; $x$, $y$ ve $z$ için başlangıç değerleri $0$, hata $0{,}001$.

$$
\begin{aligned}
-x + 4y - 3z &= -8\\
3x + y - 2z &= 9\\
x - y + 4z &= 1
\end{aligned}
$$

Birinci sütunun mutlak değerce en büyüğü $3$ olduğu için ilk iki denklemin yeri değiştirilir. Böylece köşegende $3$, $4$, $4$ olur. Hoca eşitlik durumlarının (burada ikinci ve üçüncü sütunda başka bir $4$ ya da $3$ bulunması) sorun olmadığını, önemli olanın büyük değerlerin köşegende olması olduğunu söyledi:

$$
\begin{aligned}
3x + y - 2z &= 9\\
-x + 4y - 3z &= -8\\
x - y + 4z &= 1
\end{aligned}
\qquad\Rightarrow\qquad
\begin{aligned}
x &= (9 - y + 2z)/3\\
y &= (-8 + x + 3z)/4\\
z &= (1 - x + y)/4
\end{aligned}
$$

$y$'yi yalnız bırakırken hoca bir işaret hatası yaptı; bir öğrenci $-8$'in işaretini sordu ve ifade $y=(-8+x+3z)/4$ olarak düzeltildi.

Başlangıç $0,0,0$ ile birinci iterasyon $x=9/3=3$, $y=-8/4=-2$, $z=1/4=0{,}25$ verir. Değişimler $|\Delta x|=3$, $|\Delta y|=2$, $|\Delta z|=0{,}25$ hatadan büyük olduğu için iterasyon sürer.

Slayttaki tablo ise başlangıç değerini $x=y=z=1$ almıştı. Hoca bunun soru metniyle çeliştiğini söyleyip tabloyu $1,1,1$ ile izledi. $1,1,1$'den ilk adım:

$$
x=\frac{9-1+2}{3}=3{,}333,\qquad y=\frac{-8+1+3}{4}=-1{,}0,\qquad z=\frac{1-1+1}{4}=0{,}25
$$

Sonraki iterasyonda bu değerler yeniden yerine koyulur. Hoca bazı değişkenlerin erken oturduğunu, birinin ise biraz "yalpaladığını" ve hepsi için durma koşulu sağlanana kadar devam edildiğini gösterdi. Sonuçta değerler $x=3$, $y=-2$, $z=-1$'e oturur; bunlar denklemde yerine koyulunca tam çözüm oldukları görülür.

Python ile kontrol: Jacobi, $1,1,1$'den başlayınca ardışık farkların hepsinin $0{,}001$'in altına inmesi 14. satırda (13 iterasyon sonra) gerçekleşir. İkinci satır $3{,}333;\ -1{,}0;\ 0{,}25$, üçüncü satır $3{,}5;\ -0{,}979;\ -0{,}833$ olur.

### 7.3 Köşegen baskınlığının bir başka kontrolü

Hoca köşegen baskınlığı için başka teknikler de bulunduğunu söyledi. Örneğin her satırda köşegen katsayısının mutlak değeri, o satırdaki diğer katsayıların mutlak değerleri toplamından büyük ya da eşit olmalıdır. Örnekteki birinci satırda $|3| \ge |1|+|-2| = 3$ sağlanır.

## 8. Gauss-Seidel İterasyon Yöntemi

Hoca sınıfa bir soru sordu: Bu yöntemde nasıl bir değişiklik yapıp daha hızlı bir çözüm elde edebilirsiniz? Bir öğrenci, $x$'in değeri bulunduktan sonra sonraki adıma geçmeden bu yeni $x$'in hemen kullanılmasını önerdi. Hoca bunun tam olarak Gauss ve Seidel'in bulduğu fikir olduğunu söyledi.

Başlangıç değerleri $x^{(0)}, y^{(0)}, z^{(0)}$ ise $y^{(0)}$ ve $z^{(0)}$ ile $x^{(1)}$ bulunur. $y^{(1)}$ hesaplanırken $x^{(0)}$ değil, yeni $x^{(1)}$ kullanılır. $z^{(1)}$ hesaplanırken hem $x^{(1)}$ hem $y^{(1)}$ kullanılır. Her zaman en son ulaşılan değerler kullanıldığı için çözüme daha kısa sürede erişilir. Sebebi şudur: $\Delta x$ azaldıkça $x$ olması gereken değere yaklaşır, bu da diğer değişkenlerin hesabını iyileştirir. Uzak bir değer kullanmak yalnızca süreci geciktirir.

### 8.1 Örnek

Aynı sistem, aynı denklemler, yine $1,1,1$ başlangıcı (ekrandan, 01:30:00). İlk adımda $x=3{,}333$ bulunur; bu değer hemen $y$'de kullanılır: $y=(-8+3{,}333+3\cdot1)/4=-0{,}417$. Ardından $z=(1-3{,}333-0{,}417)/4=-0{,}688$.

| İterasyon | $x$ | $\lvert\Delta x\rvert$ | $y$ | $\lvert\Delta y\rvert$ | $z$ | $\lvert\Delta z\rvert$ |
|---|---|---|---|---|---|---|
| 1 | 1 | - | 1 | - | 1 | - |
| 2 | 3,330 | 2,333 | -0,417 | 1,417 | -0,688 | 1,688 |
| 3 | 2,680 | 0,348 | -1,845 | 1,428 | -0,882 | 0,194 |
| 4 | 3,027 | 0,346 | -1,904 | 0,059 | -0,983 | 0,101 |
| 5 | 2,979 | 0,048 | -1,992 | 0,088 | -0,983 | 0,010 |
| 6 | 3,002 | 0,023 | -1,994 | 0,002 | -0,999 | 0,006 |
| 7 | 2,999 | 0,003 | -2,000 | 0,006 | -1,000 | 0,001 |
| 8 | 3,000 | 0,001 | -2,000 | 0,000 | -1,000 | 0,000 |
| 9 | 3,000 | 0,000 | -2,000 | 0,000 | -1,000 | 0,000 |

Hoca, Jacobi'de ikinci adımda $y$ için bulunan değerin yerine Gauss-Seidel'de $-0{,}417$ bulunduğunu ve $y$'nin gerçek değerine daha kısa sürede (9 iterasyonda) ulaşıldığını gösterdi. Ölçüt $0{,}01$ olsaydı daha erken, 8. iterasyonda bile durulabilirdi. Fark yalnızca budur, ama algoritmik bir iyileştirmedir.

> **Ders sonrası not:** Tablodaki değerler python ile yeniden üretildi. Yalnız 5. satırdaki $z$ değeri slaytta $-0{,}983$ yazıyor. Hesap $-0{,}993$ veriyor; aynı satırdaki $|\Delta z|=0{,}010$ değeri de $-0{,}983$'ten $-0{,}993$'e geçişle tutarlıdır. Ayrıca 3. satırdaki $|\Delta x|$, slayttaki $x$ değerlerinden ($3{,}330 \to 2{,}680$) hesaplanınca $0{,}65$ çıkıyor (slaytta $0{,}348$). Bu değerler büyük olasılıkla slayttaki yazım hatalarıdır; yöntemin sonucunu etkilemez.

### 8.2 Köşegen baskınlığının arkasındaki matematik

**Soru:** Mutlak değerce en büyük katsayıyı köşegene almanın arkasındaki matematik nedir?

**Cevap:** Köşegen baskın olmayınca değişkeni çekerken bölünen payda küçük bir değer olur. Payda küçük olunca bulunan değer büyür, kökü "boğamayız" ve kökten uzaklaşma olasılığı doğar. Köşegen baskınlığı sağlanmadan da bazı sistemlerde çözüme gidilir, ama bazı sistemlerde gidilemez. Hoca örnek olarak $3x+0y-2z$ gibi, köşegende sıfır bulunan bir satırı gösterdi ve farklı durumların denenebileceğini söyledi. Bunun matematiksel ispatlarının da olduğunu, ancak bunların bu dersin konusu olmadığını ekledi.

> **Ek bilgi (derste anlatılmadı):** Bilinen sonuç şudur: katsayılar matrisi kesin köşegen baskınsa, yani her satırda $|a_{ii}| > \sum_{j\ne i}|a_{ij}|$ ise, Jacobi ve Gauss-Seidel her başlangıç değeri için yakınsar. Bu koşul yeterlidir ama gerekli değildir; koşulu sağlamayan bazı sistemlerde de yöntemler yakınsayabilir.

Hoca dolaylı yöntemlerin düşünsel olarak daha basit olduğunu vurguladı: bir yeri sıfır, öbürünü bir yapmakla uğraşılmaz. Kökler bir diziye atılır, bir `for` ya da `while` döngüsü içinde toplama, çıkarma, çarpma ve bölmeyle sonuca gidilir.

## 9. Doğrusal Olmayan Denklem Takımlarının Çözümü (Newton-Raphson)

Bu bölümde Newton-Raphson yöntemi denklem takımlarıyla birleştirilir. Doğrusal olmayan denklem takımına örnek: $x^2+y=0$ ve $3x^3+4y^2=0$. Sağ tarafların sıfır olması da zorunlu değildir. Artık doğru yoktur, $x^2$ gibi terimler vardır. Fonksiyonlar iki bilinmeyenlidir; $y=f(x)$ gibi bir bağıntıdan söz edilmez. Amaç, iki eşitliği birden sağlayan $x, y$ değerlerini bulmaktır (ekrandan, 01:35:00):

$$
f(x,y)=0 \quad\text{ve}\quad g(x,y)=0
$$

### 9.1 Taylor serisinden türetme

Tek değişkenli Taylor serisi:

$$
f(x_0+h)=\frac{f(x_0)}{0!}+\frac{f'(x_0)}{1!}h+\frac{f''(x_0)}{2!}h^2+\dots
$$

İki değişkenli fonksiyonda hem $x$'e hem $y$'ye belli bir artış verilir: $f(x_0+\Delta x,\ y_0+\Delta y)$. Bu, fonksiyonda $x$ ve $y$ yerine değer koymak demektir; örneğin $f(x,y)=x^2+y$ için $f(2,3)=4+3=7$.

Türev alınırken hangi değişkene göre alındığı belirtilmelidir. Bunun için **kısmi türev** operatörü $\partial$ kullanılır. $\partial f/\partial x$ yalnızca $x$'e göre türev alındığını, diğer değişkenlerin sabit sayıldığını gösterir. Hoca iki örnek verdi:

- $\dfrac{\partial}{\partial x}(x^2+3y)=2x$, çünkü $y$'li terim $x$'e göre sabittir.
- $\dfrac{\partial}{\partial x}(x^2+3x^3y)=2x+9x^2y$.

Taylor serisi iki değişkenli halde açılır. İkinci mertebeden türev terimleri, kesme hatası olarak atılır. Hoca bunun sebebini şöyle açıkladı: fonksiyon, türevi ve ikinci türevi gibi üç bilinmeyenle uğraşmak yerine fonksiyon ve türevinden oluşan iki bilinmeyenli iki denklem daha makuldür. Belli bir hata pahasına bu terimler atılır ve kalan ifade sıfıra eşitlenir (ekrandan, 01:40:00):

$$
\begin{aligned}
f(x_0,y_0)+\frac{\partial f(x_0,y_0)}{\partial x}\Delta x+\frac{\partial f(x_0,y_0)}{\partial y}\Delta y&=0\\
g(x_0,y_0)+\frac{\partial g(x_0,y_0)}{\partial x}\Delta x+\frac{\partial g(x_0,y_0)}{\partial y}\Delta y&=0
\end{aligned}
$$

$f(x_0,y_0)$ ve $g(x_0,y_0)$ sayısal değerlerdir, karşıya atılabilir. Bilinmeyen olarak yalnızca $\Delta x$ ve $\Delta y$ kalır. Bu, $2x+3y=8$ gibi bir lineer sistemin matris biçimine getirilir:

$$
\begin{bmatrix}
\dfrac{\partial f(x_0,y_0)}{\partial x} & \dfrac{\partial f(x_0,y_0)}{\partial y}\\[2mm]
\dfrac{\partial g(x_0,y_0)}{\partial x} & \dfrac{\partial g(x_0,y_0)}{\partial y}
\end{bmatrix}
\begin{bmatrix}\Delta x\\ \Delta y\end{bmatrix}=
\begin{bmatrix}-f(x_0,y_0)\\ -g(x_0,y_0)\end{bmatrix}
$$

$$
x_{n+1}=x_n+\Delta x,\qquad y_{n+1}=y_n+\Delta y,\qquad |x_{n+1}-x_n|,\ |y_{n+1}-y_n| < \text{hata}
$$

Hoca bunu tek değişkenli Newton-Raphson'a bağladı: orada $x_{i+1}=x_i-f(x_i)/f'(x_i)$ idi. Burada da bir sonraki değer, mevcut değerden $\Delta x$ kadar artışla bulunur. $\Delta$ değerleri mutlak hata ölçüsüdür ve belli bir hatanın altına inince iterasyon durdurulur.

Üç değişken için de aynı yol izlenir: $f, g, v$ gibi üç denklem, $x$, $y$ ve $z$'ye göre kısmi türevlerden oluşan bir $3\times3$ matris ve $\Delta x, \Delta y, \Delta z$ bilinmeyenleri olur. Hoca birinci mertebeden türevin burada yeterli olduğunu söyledi.

### 9.2 Örnek

Slayttaki soru (ekrandan, 01:45:00): $x_0=0{,}7$ ve $y_0=1{,}7$ alarak $0{,}08$ hata ile doğrusal olmayan denklem takımını çözünüz.

$$
x^2+y-3=0,\qquad x+y^2-5=0
$$

Kısmi türevler: $\partial f/\partial x=2x$, $\partial f/\partial y=1$, $\partial g/\partial x=1$, $\partial g/\partial y=2y$. Hoca burada $y$ ile $x$ arasında $y=f(x)$ gibi bir ilişki olmadığını, ikisinin ayrı değişkenler olduğunu vurguladı:

$$
\begin{bmatrix}2x & 1\\ 1 & 2y\end{bmatrix}
\begin{bmatrix}\Delta x\\ \Delta y\end{bmatrix}=-
\begin{bmatrix}x^2+y-3\\ x+y^2-5\end{bmatrix}
$$

Yerine koyarken hoca sabiti önce $0{,}3$ diye okudu; bir öğrenci $3$ olması gerektiğini söyledi.

**1. iterasyon** ($x_0=0{,}7$, $y_0=1{,}7$):

- Matris: $\begin{bmatrix}1{,}4&1\\1&3{,}4\end{bmatrix}$.
- Sağ taraf: $-(0{,}49+1{,}7-3)=0{,}81$ ve $-(0{,}7+2{,}89-5)=1{,}41$.
- Sistem: $1{,}4\Delta x+\Delta y=0{,}81$, $\Delta x+3{,}4\Delta y=1{,}41$. Bu, daha önce görülen iki bilinmeyenli lineer sistemdir.
- Python çözümü: $\Delta x\approx0{,}357$, $\Delta y\approx0{,}310$; $x_1\approx1{,}057$, $y_1\approx2{,}010$.

Değişim $0{,}08$'den büyük olduğu için bir iterasyon daha yapılır, yani yeni $x$ ve $y$ değerleri yeniden yerine yazılır.

**2. iterasyon:** Python ile $\Delta x\approx-0{,}056$, $\Delta y\approx-0{,}010$; $x_2\approx1{,}002$, $y_2\approx1{,}9996$. $|\Delta x|$ ve $|\Delta y|$ artık $0{,}08$'in altında olduğundan durulur. Çözüm $x=1$, $y=2$'dir: $1+2-3=0$ ve $1+4-5=0$.

<!-- BELİRSİZ: Ara değerlerin bulunduğu slayt karelerde yok. Hoca birinci iterasyondan sonra yeni x'i 1,1 olarak, ikinci iterasyondaki matris değerlerini "2,02 ... 1, 1, 4,16" diye okudu. Python ile x1 = 1,057, y1 = 2,010 bulundu. Slayttaki değerler büyük olasılıkla yuvarlanmış ya da farklı hesaplanmıştır. Nihai çözüm (1, 2) her iki durumda da aynıdır. -->

Hoca ders kitabında bu konuyla ilgili üç dört örnek bulunduğunu, üç bilinmeyenli denklemler için başka kaynaklardan da örnek çözülmesini tavsiye etti.

### 9.3 Üç değişkenli kısmi türev alıştırması

Hoca sınıfa $f(x,y,z)=x^3+4x^2y^2+z^3x^2$ fonksiyonunun kısmi türevlerini sordu. Bir öğrenci $x$'e göre türeve başladı; hoca toplamın türevi kuralıyla tamamladı:

$$
\frac{\partial f}{\partial x}=3x^2+8xy^2+2xz^3,\qquad
\frac{\partial f}{\partial z}=3z^2x^2
$$

$z$'ye göre türevde ilk iki terim $z$ içermediği için sıfır gelir. Üç bilinmeyenli durumda üç denklem olur. $\Delta x, \Delta y, \Delta z$ değişimleriyle bulunan $x, y, z$ değerleri çözümü verir.

## 10. Sayısal Türev

Hoca proje haftalarında kolaylık olsun diye bir sonraki konuya da bu derste başladı.

### 10.1 Neden sayısal türev?

Bir fonksiyonun bir noktadaki türev değerini bulmak için normalde türev alınır, sonra $x$ yerine sayı yazılır. Zorluk türevi analitik olarak almaktadır: çarpımın türevi, bölümün türevi, trigonometrik fonksiyonların kuralları derken iş bir yerden sonra güçleşir. Sonuçta yalnız bir sayısal değer isteniyorsa bunu daha kolay yoldan yapmak mümkün müdür? Sayısal türev bu arayıştır. En basitinden Newton-Raphson'da işe yarar: türevi zor bir fonksiyonda $f'(x_i)$ hesabından kurtulmanın bir yoludur (daha önce sekant yöntemi de bunun için kullanılmıştı).

### 10.2 Türev nedir?

Türev bir değişim takibi aracıdır. Fiziksel dünyada her şey bir değişkene göre değişir. Hocanın örnekleri:

- Ses, zamanla değişen bir bilgidir.
- Hız, konumun zamana göre değişimidir ($x=vt$).
- Isı geçişi, iki nokta arasındaki sıcaklık farkının değişimiyle ifade edilir.
- Devre teorisinde bobinin uçlarındaki gerilim, bobinden geçen akımın değişimiyle modellenir.

Değişim fark demektir. Bir değişkene göre değişen bağımlı değişken, değiştiği değişken ise bağımsız değişkendir. Slayta göre (ekrandan, 01:55:00):

- Türev, bağımlı bir değişkenin bağımsız bir değişkene göre değişme miktarıdır.
- Analitik olarak türev ya da integral almanın mümkün olmadığı yerlerde sayısal türev veya sayısal integral işlemleri kullanılmalıdır. Birçok olayda değişim oranları kullanılır.
- Geometrik olarak türev, bir fonksiyona ait eğrinin herhangi bir $x$ noktasındaki yatayla yaptığı açı, diğer bir ifadeyle $x$ noktasındaki teğetinin eğimidir.
- Sayısal türev, bir fonksiyonun bağlı olduğu değişkenlere göre değişim hızının bir ölçüsüdür.

$$
f'(x)=\frac{\partial f(x)}{\partial x}=\lim_{\Delta x\to0}\frac{\Delta f(x)}{\Delta x},\qquad
\frac{\Delta f(x)}{\Delta x}=\frac{f(x_i+\Delta x)-f(x_i)}{\Delta x}
$$

Paydadaki fark $(x_i+\Delta x)-x_i=\Delta x$'tir. Hoca bir sayı dizisinin türevini örnek verdi: $2, 4, 8, 6, 10$ dizisinde ardışık farklar $2, 4, -2, 4$'tür. Dizinin türevi bu şekilde alınabilir ve yeri geldiğinde bir bilgi olarak kullanılır. Sürekli bir değişkende ise $\Delta x$ çok küçük, örneğin $0{,}00001$ gibi seçilmelidir. Sonuçta yalnız fonksiyonda değer yerine koyma, çıkarma ve bölme vardır.

### 10.3 Geri, ileri ve merkezi fark

- **Geri fark:** $x_i$ referans alınır ve biraz gerideki $x_{i-1}=x_i-h$ noktası kullanılır:

$$
f'(x_i)\approx\frac{f(x_i)-f(x_i-h)}{h}
$$

Örneğin $h=0{,}001$ ile $f'(5)\approx[f(5)-f(4{,}999)]/0{,}001$. Fonksiyonun türevini bulmaktansa fonksiyonda bir değer yerine koymak çok daha kolaydır.

- **İleri fark:** $x_{i+1}=x_i+h$ kullanılır:

$$
f'(x_i)\approx\frac{f(x_i+h)-f(x_i)}{h}
$$

- **Merkezi fark:** Biraz daha hassastır. $x_i$ merkez alınarak biraz ilerisine ve biraz gerisine bakılır; fark miktarı $2h$ olur:

$$
f'(x_i)\approx\frac{f(x_i+h)-f(x_i-h)}{2h}
$$

### 10.4 Adım aralığının etkisi

Slaytta $f(x)=x^3$ için $h=0{,}1$ ve $h=2$ ile çizilmiş türev grafikleri karşılaştırılıyor (ekrandan, 02:00:00). $h=0{,}1$'de ileri fark (mavi kesikli) ve geri fark (kırmızı noktalı) analitik eğriye yakındır. Merkezi fark ise analitik eğrinin tam üstüne oturur. $h=2$'de ileri ve geri fark eğrileri analitik eğriden belirgin biçimde uzaklaşır. Yani $h$ büyüdükçe gerçek değerden uzaklaşılır.

> **Ders sonrası not:** Hoca bu fonksiyonun türevini "$2x^3$" diye söyledi. $f(x)=x^3$ için doğrusu $f'(x)=3x^2$'dir; grafikteki analitik eğri de $3x^2$'dir ($x=10$'da $300$).

### 10.5 Örnek: $e^x$'in türevi

$f(x)=e^x$ fonksiyonunun $x=1$ noktasındaki türevi $h=0{,}1$ ile bulunacak. Bir öğrenci $e^x$'in türevinin kendisi olduğunu söyledi. Analitik değer $e^1\approx2{,}718$'dir.

- İleri fark: $\dfrac{e^{1{,}1}-e^{1}}{0{,}1}\approx2{,}86$
- Geri fark: $\dfrac{e^{1}-e^{0{,}9}}{0{,}1}\approx2{,}59$
- Merkezi fark: $\dfrac{e^{1{,}1}-e^{0{,}9}}{2\cdot0{,}1}\approx2{,}72$

Merkezi fark analitik değere en yakındır. $h=0{,}1$ yerine $0{,}001$ alınırsa değerler çok daha yakın olur (python ile doğrulandı: $2{,}8588$; $2{,}5868$; $2{,}7228$).

**Soru:** Analitik cevaba en yakın sonucu her zaman merkezi fark mı verir?

**Cevap:** Çok küçük $h$ seçilirse genelleme yapılabilir; beklenen budur, çünkü nokta etrafındaki küçük değişim daha ayrıntılı incelenir. Ancak fonksiyonların grafikleri her zaman düzgün değildir. Karmaşık bir fonksiyonda seçilen noktanın çevresindeki teğet her zaman iyi yakalanamayabilir ve bazı durumlarda diğer yöntemler daha başarılı olabilir. Yine de merkezi fark bilinen en düzgün çözümlerden biridir. Hoca daha iyisinin de olduğunu ve birazdan geleceğini söyledi.

### 10.6 Örnek: $x^2$'nin türevi

$f(x)=x^2$, $x=1$, $h=0{,}1$. Analitik değer $f'(1)=2$'dir. Hoca önce değerleri yanlışlıkla türev ifadesine ($2x$) koydu ve üç yöntemden de tam $2$ buldu. Bir öğrenci değerlerin fonksiyona konması gerektiğini hatırlattı, hesap yeniden yapıldı:

- Geri fark: $\dfrac{1^2-0{,}9^2}{0{,}1}=\dfrac{1-0{,}81}{0{,}1}=1{,}9$
- İleri fark: $\dfrac{1{,}1^2-1^2}{0{,}1}=\dfrac{1{,}21-1}{0{,}1}=2{,}1$
- Merkezi fark: $\dfrac{1{,}1^2-0{,}9^2}{2\cdot0{,}1}=\dfrac{1{,}21-0{,}81}{0{,}2}=\dfrac{0{,}4}{0{,}2}=2$

$h$ küçültülürse, yani hassasiyet artırılırsa, ileri ve geri fark da gerçek değere yaklaşır (python ile doğrulandı).

## 11. Taylor Serisi ile Sayısal Türev

Buraya kadarki formüller bir ya da en fazla iki nokta kullanır. İkinci türev istendiğinde sorun çıkar: $f'(x)\approx[f(x+h)-f(x)]/h$ ifadesinin bir daha türevi alınmak istenirse $f(x+h)$ ve $f(x)$'in türevlerini ayrı ayrı almak gerekir. Üçüncü türevde iş daha da uzar. Bu sorun Taylor serisiyle genel olarak çözülür. Slayta göre (ekrandan, 02:05:00):

- Bir $f(x)$ fonksiyonunun $x_i$ noktasındaki türevi $f'(x_i)$ Taylor serisi yardımıyla elde edilebilir.
- Bir fonksiyonun $x_i+\Delta x$ civarındaki değeri, $x_i$ civarındaki değerinin kuvvetleri cinsinden Taylor serisine açılarak bulunabilir:

$$
f(x_i+\Delta x)=f(x_i)+\frac{\Delta x}{1!}f'(x_i)+\frac{\Delta x^2}{2!}f''(x_i)+\frac{\Delta x^3}{3!}f'''(x_i)+\dots+\frac{\Delta x^n}{n!}f^{(n)}(x_i)
$$

- Taylor serisinde serinin kesildiği noktadan sonraki hatanın mertebesi, kesilen noktadaki $\Delta x$'in mertebesine eşit olur.
- Taylor serisi ile çok noktalı türev yaklaşımı gerçekleştirilir.

### 11.1 Birinci türev (ileri fark, iki noktalı)

$f(x)$'in $x_i+h$ ve $x_i+2h$ civarındaki değerleri ikinci kuvvete kadar açılır (ekrandan, 02:15:00). Örneğin $h=0{,}1$ ise $2h=0{,}2$ olur; $x_i$'den $0{,}1$ ve $0{,}2$ ötedeki noktalara bakılır:

$$
\begin{aligned}
f(x_i+h)&=f(x_i)+h\,f'(x_i)+\frac{h^2}{2!}f''(x_i)\\
f(x_i+2h)&=f(x_i)+2h\,f'(x_i)+\frac{(2h)^2}{2!}f''(x_i)=f(x_i)+2h\,f'(x_i)+2h^2f''(x_i)
\end{aligned}
$$

$f''$ terimini yok etmek için birinci denklem $-4$ ile çarpılır:

$$
-4f(x_i+h)=-4f(x_i)-4h\,f'(x_i)-2h^2f''(x_i)
$$

Taraf tarafa toplanınca $f''$ terimleri gider:

$$
f(x_i+2h)-4f(x_i+h)=-3f(x_i)-2h\,f'(x_i)
$$

$f'(x_i)$ yalnız bırakılır:

$$
f'(x_i)=\frac{1}{2h}\left[-3f(x_i)+4f(x_i+h)-f(x_i+2h)\right],\qquad
f'_i=\frac{1}{2h}\left[-3f_i+4f_{i+1}-f_{i+2}\right]
$$

Slayta göre bu, Taylor serisiyle bulunan ileri fark formülüdür. Örneğin $f'(3)$, $h=0{,}01$ ile isteniyorsa fonksiyonda $3$, $3{,}01$ ve $3{,}02$ yerine koyulur, katsayılarla birleştirilip $2\cdot0{,}01$'e bölünür.

### 11.2 İkinci türev

Asıl kazanç ikinci türevdedir. Bu kez birinci türev terimi yok edilmek istenir. $f(x_i+h)$ açılımı $-2$ ile çarpılırsa $-2h\,f'(x_i)$ terimi, $f(x_i+2h)$'deki $2h\,f'(x_i)$ ile birbirini götürür:

$$
f(x_i+2h)-2f(x_i+h)=-f(x_i)+h^2f''(x_i)
$$

$h^2$'ye bölünüp düzenlenince:

$$
f''(x_i)\approx\frac{f(x_i)-2f(x_i+h)+f(x_i+2h)}{h^2}
$$

Böylece hiç birinci türev almadan, yalnız fonksiyonun değerleriyle ikinci türevin yaklaşık değeri hesaplanır. Birinci türev formülünde payda $2h$, burada $h^2$'dir.

### 11.3 Geri fark ve üç noktalı türevler

Aynı yol geri fark için de izlenir: Taylor serisinde $h$ yerine $-h$ yazılır ve terimler birbirini yok edecek biçimde çarpılıp taraf tarafa toplanır.

Fonksiyon üçüncü kuvvete kadar açılırsa ($x+h$, $x+2h$, $x+3h$ yerine koyulur ve $h^3 f'''(x_i)/3!$ terimleri eklenir) üç bilinmeyenli üç denklem elde edilir. Bunlardan birinci, ikinci ve üçüncü türev formülleri çıkar.

<!-- BELİRSİZ: Üç noktalı formüllerin yazılı olduğu slayt karelerde okunmuyor. Hoca ikinci türev katsayılarını "iki, beş, dört, eksi bir" diye okudu; işaretli hali büyük olasılıkla 2, -5, 4, -1'dir. -->

> **Ek bilgi (derste anlatılmadı):** Üçüncü kuvvete kadar açılımdan bilinen ileri fark formülleri büyük olasılıkla şunlardır: $f''_i\approx\frac{2f_i-5f_{i+1}+4f_{i+2}-f_{i+3}}{h^2}$ ve $f'''_i\approx\frac{-f_i+3f_{i+1}-3f_{i+2}+f_{i+3}}{h^3}$. $f(x)=x^3$, $x=1$, $h=0{,}01$ için python ile ikisi de $6$ verir; analitik değerler $f''(1)=6$, $f'''(1)=6$'dır.

Hoca formülü sınamak için $f(x)=x^3$ önerdi: $f'(x)=3x^2$, $f''(x)=6x$, $f'''(x)=6$; $x=1$'de sırasıyla $3$, $6$, $6$. Küçük bir $h$ (örneğin $0{,}01$) ile fonksiyonda $1$, $1+h$, $1+2h$, $1+3h$ yerine koyulduğunda üçüncü türev için $6$'ya yakın bir değer bulunması beklenir.

Hoca bu katsayıların "türev denklemleri" adıyla tablolar halinde saklandığını söyledi; trigonometri cetveli gibi hazır tablolardır. Birinci türev için $-3, 4, -1$, ikinci türev için benzer katsayılar vardır. Pascal üçgenini biraz andırsalar da aynı şey değildir. Hazır katsayılarla herhangi bir fonksiyonun türevinin istenen noktadaki değeri yaklaşık olarak bulunabilir.

## 12. Sayısal Türevin Newton-Raphson'da Kullanımı

**Soru:** Bunları, türevini almakta zorlandığımız fonksiyonların türevini fonksiyonun kendisine bağlı olarak bulmak için mi öğrendik?

**Cevap:** Evet. Amaç, türevi alınması zor olan bir fonksiyonun, türev alma kurallarına gerek duymadan, türevinin yaklaşık değerini hesaplamaktır.

Hoca en basit kullanım yerini gösterdi: Newton-Raphson ile kök bulmak. Örnek fonksiyon $f(x)=2x+3$'tür; kökü $x=-1{,}5$'tir ve $0$ ile $-2{,}5$ arasında kök aranır (ekrandan, 02:25:00). Newton-Raphson'da $x_{i+1}=x_i-f(x_i)/f'(x_i)$ kullanılır; burada $f'(x)=2$ olduğu için payda sürekli $2$'dir. Analitik türev yerine $f'(x_i)\approx[f(x_i+0{,}01)-f(x_i)]/0{,}01$ gibi bir sayısal türev kullanılabilir. $x_0=0$'dan başlanırsa $f(0)=3$ olur, sayısal türev $[f(0{,}01)-f(0)]/0{,}01=2$ çıkar. Hoca bunun "biraz modifiye edilmiş bir Newton-Raphson" olduğunu söyledi.

> **Ders sonrası not:** Hoca anlatırken sayısal türevi "$f(3+0{,}01)-f(3)$" diye, yani $x$ yerine $f(0)=3$ değerini koyarak söyledi. Doğrusu $x_0=0$ noktasında $[f(0+0{,}01)-f(0)]/0{,}01=2$'dir. Bununla Newton-Raphson'ın ilk adımı $x_1=0-3/2=-1{,}5$ olur ve doğrusal fonksiyonda kök tek adımda bulunur (python ile doğrulandı).

> **Hocanın vurgusu:** Pratik için iki tavsiye: kitaptaki ekstra soruları çözün ve gördüğünüz yöntemlerin kodunu haftada bir yöntem olacak şekilde C'de şimdiden yazın. Hem C pratiği yapılmış, hem dersin tekrarı yapılmış olur.

## Örnek Sorular

**Soru 1** (ekrandan, 00:25:00): Aşağıdaki denklem takımını Cramer yöntemiyle çözünüz.

$$
2x_1-3x_2+2x_3=-11,\qquad x_1+x_2-2x_3=8,\qquad 3x_1-2x_2-x_3=-1
$$

Çözüm (derste verildi): $|A|=2(-1-4)+3(-1+6)+2(-2-3)=-5$. Sarrus ile de $12-17=-5$. Pay determinantları $-5$, $-15$, $10$; $x_1=1$, $x_2=3$, $x_3=-2$.

**Soru 2** (derste sözlü, 00:27:21): Bir şeyin "yok olması" (elimination) matematikte ne anlama gelir?

Cevap (derste verildi): Tamamen sıfırlanması. *Reduction* azalma, *elimination* sıfıra indirme demektir.

**Soru 3** (ekrandan, 00:35:00): Elementer satır işlemlerinden sonra genişletilmiş matris $[2,-3,2\,|\,5;\ 0,1,-2\,|\,8;\ 0,0,1\,|\,2]$ ise $x, y, z$ nedir?

Çözüm (derste verildi): $z=2$, $y=8+2\cdot2=12$. Birinci denklemden $2x=5+3\cdot12-2\cdot2=37$, yani $x=18{,}5$. Hoca sağ tarafı $2$ alıp $x=17$ buldu (bkz. Bölüm 4.5).

**Soru 4** (ekrandan, 01:10:00): $3{,}6x+2{,}4y-1{,}8z=6{,}3$; $4{,}2x-5{,}8y+2{,}1z=7{,}5$; $0{,}8x+3{,}5y+6{,}5z=3{,}7$ denklem sistemini Cholesky yöntemi ile çözünüz. (Derste aynı sistem Gauss ve Gauss-Jordan ile de çözüldü.)

Çözüm (derste verildi, python ile kesinleştirildi):

$$
L=\begin{bmatrix}3{,}6&0&0\\4{,}2&-8{,}6&0\\0{,}8&2{,}967&8{,}349\end{bmatrix},\quad
U=\begin{bmatrix}1&0{,}667&-0{,}5\\0&1&-0{,}488\\0&0&1\end{bmatrix}
$$

$Y\approx(1{,}75;\ -0{,}017;\ 0{,}282)$, $X\approx(1{,}811;\ 0{,}120;\ 0{,}282)$.

**Soru 5** (ekrandan, 01:25:00): $-x+4y-3z=-8$; $3x+y-2z=9$; $x-y+4z=1$ denklem takımını Jacobi iterasyon yöntemi ile çözünüz. $x, y, z$ için başlangıç değerleri $0$, hata $0{,}001$.

Çözüm (derste kısmen verildi): Satır değişimiyle köşegen baskınlığı sağlanır. $x=(9-y+2z)/3$, $y=(-8+x+3z)/4$, $z=(1-x+y)/4$. $0,0,0$'dan ilk iterasyon $(3;\ -2;\ 0{,}25)$ verir. Değerler $x=3$, $y=-2$, $z=-1$'e yakınsar.

> **Çözüm (derste verilmedi):** Python ile $0,0,0$ başlangıcından Jacobi iterasyonu sürdürüldü; ardışık farkların hepsi 13. iterasyonda $0{,}001$'in altına indi ve $x\approx2{,}9997$, $y\approx-2{,}0002$, $z\approx-0{,}9999$ bulundu. Kesin çözüm yerine koyarak doğrulanır: $-3-8+3=-8$, $9-2+2=9$, $3+2-4=1$.

**Soru 6** (derste sözlü, 01:27:03): Jacobi yönteminde nasıl bir değişiklik yapılırsa çözüme daha hızlı ulaşılır?

Cevap (derste verildi, bir öğrenci önerdi): Aynı iterasyon içinde yeni bulunan değeri hemen sonraki değişkenin hesabında kullanmak. Bu, Gauss-Seidel yöntemidir.

**Soru 7** (ekrandan, 01:30:00): Aynı denklem takımını Gauss-Seidel iterasyon yöntemi ile çözünüz (başlangıç $0$, hata $0{,}001$).

Çözüm (derste verildi): Slayttaki tablo $1,1,1$'den başlar ve 9. satırda $x=3$, $y=-2$, $z=-1$'e oturur (tablo Bölüm 8.1'de).

**Soru 8** (ekrandan, 01:45:00): $x^2+y-3=0$, $x+y^2-5=0$ doğrusal olmayan denklem takımını $x_0=0{,}7$, $y_0=1{,}7$ alarak $0{,}08$ hata ile çözünüz.

Çözüm (derste verildi, ara değerler python ile): $\begin{bmatrix}2x&1\\1&2y\end{bmatrix}\begin{bmatrix}\Delta x\\\Delta y\end{bmatrix}=-\begin{bmatrix}x^2+y-3\\x+y^2-5\end{bmatrix}$. 1. iterasyon: $\Delta x\approx0{,}357$, $\Delta y\approx0{,}310$, $(1{,}057;\ 2{,}010)$. 2. iterasyon: $\Delta x\approx-0{,}056$, $\Delta y\approx-0{,}010$, $(1{,}002;\ 1{,}9996)$. Değişimler $0{,}08$'in altında olduğu için durulur; çözüm $(1, 2)$.

**Soru 9** (derste sözlü, 01:47:42): $f(x,y,z)=x^3+4x^2y^2+z^3x^2$ fonksiyonunun $x$'e ve $z$'ye göre kısmi türevleri nedir?

Cevap (derste verildi): $\partial f/\partial x=3x^2+8xy^2+2xz^3$, $\partial f/\partial z=3z^2x^2$.

**Soru 10** (derste sözlü, 02:00:54): $f(x)=e^x$ fonksiyonunun $x=1$ noktasındaki türevini $h=0{,}1$ ile ileri, geri ve merkezi farkla bulunuz.

Çözüm (derste verildi): İleri $2{,}86$, geri $2{,}59$, merkezi $2{,}72$; analitik $e\approx2{,}718$.

**Soru 11** (derste sözlü, 02:04:48): $f(x)=x^2$ fonksiyonunun $x=1$ noktasındaki türevini $h=0{,}1$ ile üç fark yöntemiyle bulunuz.

Çözüm (derste verildi): Geri $1{,}9$, ileri $2{,}1$, merkezi $2$; analitik $2$.

**Soru 12** (ekrandan, 02:20:00): $f(x)=2x^2+1$ fonksiyonunun $x=2$ noktasındaki yaklaşık türevini gördüğünüz tüm yöntemlerle hesaplayınız. $h=0{,}1$; analitik çözüm $f'(2)=8$. İstenenler: basit ileri farkla çözüm ve Taylor serisi ile iki noktalı ileri farkla çözüm, $f'_i=\frac{1}{2h}[-3f_i+4f_{i+1}-f_{i+2}]$.

> **Çözüm (derste verilmedi):** $f(1{,}9)=8{,}22$, $f(2)=9$, $f(2{,}1)=9{,}82$, $f(2{,}2)=10{,}68$. İleri fark: $(9{,}82-9)/0{,}1=8{,}2$. Geri fark: $(9-8{,}22)/0{,}1=7{,}8$. Merkezi fark: $(9{,}82-8{,}22)/0{,}2=8$. Taylor ileri fark: $\frac{1}{0{,}2}[-3\cdot9+4\cdot9{,}82-10{,}68]=\frac{1{,}6}{0{,}2}=8$. İkinci dereceden bir polinomda merkezi fark ve Taylor ileri fark formülü kesin sonucu verir (python ile doğrulandı).

## Dersin Toparlaması

Bu derste lineer denklem takımlarının $AX=C$ gösterimi üzerinden iki grup çözüm yöntemi görüldü. Dolaysız yöntemlerden Cramer, determinant oranlarıyla tam çözümü verir ama her bilinmeyen için ayrı determinant ister. Gauss eliminasyonu katsayılar matrisini üst üçgen hale getirip geri yerine koymayla çözer. Gauss-Jordan matrisi birim matrise çevirip çözümü doğrudan sağ sütunda verir. Cholesky (LU) yöntemi ise $A=LU$ ayrışımıyla sistemi iki kolay üçgen sisteme böler. Dolaylı yöntemlerden Jacobi, köşegen baskınlığı sağlandıktan sonra her iterasyonda bir önceki değerleri kullanır; Gauss-Seidel en güncel değerleri kullanarak daha az iterasyonda yakınsar. Doğrusal olmayan denklem takımlarında iki değişkenli Taylor açılımı birinci mertebede kesilir ve her iterasyonda $\Delta x$, $\Delta y$ için bir lineer sistem çözülür; bu, Newton-Raphson'ın çok değişkenli halidir.

Dersin son kısmında sayısal türeve geçildi. Geri, ileri ve merkezi fark formülleri, türevi analitik olarak zor alınan fonksiyonların türev değerini yalnız fonksiyon değerlerinden hesaplamayı sağlar; merkezi fark genellikle daha doğrudur ve $h$ büyüdükçe hata artar. Taylor serisiyle çok noktalı formüller türetilerek birinci türev için $\frac{1}{2h}[-3f_i+4f_{i+1}-f_{i+2}]$ ve ikinci türev için $\frac{f_i-2f_{i+1}+f_{i+2}}{h^2}$ bulundu. Sayısal türevin Newton-Raphson'da analitik türev yerine kullanılabileceği gösterildi. Bir sonraki konu sayısal integraldir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
