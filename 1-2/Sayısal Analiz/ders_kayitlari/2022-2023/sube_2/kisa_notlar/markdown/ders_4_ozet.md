# Ders 4 Çalışma Özeti

## Genel Konular

- Kısa tekrar: matrisin tersi ve Gauss-Jordan ile ters alma
  - Matrisin yanına aynı boyutta birim matris yazılır, elementer satır işlemleriyle sol taraf birim matrise çevrilir; bu sırada sağ taraf ters matris olur.
  - Önce köşegen elemanı 1 yapılır, sonra onun altındaki (ve üstündeki) elemanlar sıfırlanır; işlem her köşegen için tekrarlanır.
  - Kare olmayan matrislerde doğrudan ters alınamaz; matrisi transpozuyla çarpıp ($A^TA$ ya da $AA^T$) yaklaşık ters alınabilir.
- Lineer denklem takımları
  - $n$ bilinmeyenli $m$ denklemden oluşur: $\sum_{j=1}^{n} a_{ij}x_j = c_i$. Matris biçimi $AX = C$'dir (ekrandan, 00:15:00).
  - $C = 0$ ise homojen, $C \neq 0$ ise homojen olmayan denklem takımı denir.
  - Tek çözüm için bilinmeyen sayısı kadar (birbirinden bağımsız) denklem gerekir.
- Dolaysız (tam çözüm veren) ve dolaylı (iteratif, yaklaşık çözüm veren) yöntemler
  - Dolaysız yöntemlerin karmaşıklığı matris boyutuyla yaklaşık $n^3$ mertebesinde büyür.
  - Dolaylı yöntemler toplama, çıkarma, çarpma ve bölmeden oluşan basit döngülerle yaklaşık çözüme gider.
- Cramer yöntemi
  - $x_k = \dfrac{|A_k|}{|A|}$; $A_k$, $A$'nın $k$. sütununa $C$ yazılarak elde edilir. 3 bilinmeyen için 4 determinant gerekir.
  - İyileştirme: $n-1$ bilinmeyen Cramer ile bulunup sonuncusu denklemde yerine koyularak bulunabilir.
  - Örnek: $2x_1-3x_2+2x_3=-11$, $x_1+x_2-2x_3=8$, $3x_1-2x_2-x_3=-1$; $|A|=-5$, $x_1=1$, $x_2=3$, $x_3=-2$ (ekrandan, 00:25:00).
- Gauss yok etme (eliminasyon) yöntemi
  - Genişletilmiş katsayılar matrisi yazılır, elementer satır işlemleriyle katsayılar matrisi üst üçgen hale getirilir, sonra en alttaki denklemden başlayarak geriye doğru yerine koyulur.
  - Her lineer denklem sistemi çözülmez: $2x+4y=18$ ile $4x+8y=36$ aynı denklemdir, $4x+8y=-36$ ise çelişkilidir (ekrandan, 00:30:00).
- Gauss-Jordan yöntemi
  - Üst üçgen matristen sonra köşegenin üstü de sıfırlanır, katsayılar matrisi birim matris olur ve sağ taraf doğrudan çözümü verir.
  - İşleme başlanan köşegen elemanına pivot eleman denir.
- Cholesky (LU) yöntemi
  - $A = LU$ ayrışımı yapılır ($L$ alt üçgen, $U$ köşegeni 1 olan üst üçgen). $LY = C$ ileri yerine koyma ile, $UX = Y$ geri yerine koyma ile çözülür.
  - Çarpım sırası $L \cdot U$'dur, $U \cdot L$ değil.
- Jacobi iterasyon yöntemi
  - Önce köşegen baskınlığı sağlanır (her sütunun mutlak değerce en büyük elemanı köşegene). Sonra $i$. denklemden $x_i$ çekilir, başlangıç değerleriyle iterasyon yapılır.
  - Her iterasyonda bir önceki iterasyonun değerleri kullanılır. Ardışık değerler arasındaki mutlak fark verilen hatanın altına inince durulur.
- Gauss-Seidel iterasyon yöntemi
  - Jacobi'den tek farkı, aynı iterasyon içinde yeni bulunan değerin hemen kullanılmasıdır; bu yüzden daha az iterasyonda yakınsar.
- Doğrusal olmayan denklem takımları için Newton-Raphson
  - $f(x,y)=0$, $g(x,y)=0$ için iki değişkenli Taylor açılımı birinci mertebede kesilir; $\Delta x$, $\Delta y$ için lineer sistem elde edilir (ekrandan, 01:40:00).
  - $x_{n+1}=x_n+\Delta x$, $y_{n+1}=y_n+\Delta y$; $|\Delta x|$, $|\Delta y|$ hatanın altına inince durulur.
- Sayısal türev
  - Geri fark, ileri fark ve merkezi fark formülleri.
  - Taylor serisiyle çok noktalı türev: ileri farkla $f'_i = \frac{1}{2h}(-3f_i+4f_{i+1}-f_{i+2})$ ve ikinci türev.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kod yazarken tekrar etmeyin
  - Cramer'de aynı determinant fonksiyonu hem pay hem payda için kullanılmalı; genel (jenerik) bir determinant fonksiyonu yazılmalı.
- Sınavda en fazla 4x4 matris
  - Elle çözülecek sorularda 5x5 ve üstü zaman kaybı olduğu için sorulmaz; ama $n$ bilinmeyenli genel kod yazmak iyi bir alıştırmadır.
- Köşegen baskınlığı
  - Jacobi ve Gauss-Seidel'de sağlanmazsa yöntem çözümden ıraksayabilir; satır değiştirmeyle bile her zaman sağlanamayabilir, bu yöntemin dezavantajıdır.
  - Kontrol için her satırda köşegen elemanının mutlak değeri, diğer elemanların mutlak değerleri toplamından büyük ya da eşit olmalıdır.
- Gauss-Seidel'in mantığı
  - Bir değişkeni gerçek değerine yaklaştırmak, diğerlerinin de daha hızlı yaklaşmasını sağlar; eski (uzak) değeri kullanmak süreci geciktirir.
- Sayısal türevin amacı
  - Türevi analitik olarak alınması zor bir fonksiyonun türevinin bir noktadaki değerini, türev kurallarına gerek duymadan, yalnız fonksiyon değerlerinden yaklaşık hesaplamak.
  - Merkezi fark genellikle analitik değere en yakın sonucu verir; adım aralığı $h$ büyüdükçe hata artar.
  - Newton-Raphson'da analitik türev yerine sayısal türev kullanılabilir.

## Kısa Tekrar Notları

- $AX=C$; $C=0$ ise homojen.
- Cramer: $x_k = |A_k|/|A|$.
- Gauss: üst üçgen + geri yerine koyma. Gauss-Jordan: birim matris, çözüm doğrudan sağ sütunda.
- LU (Cholesky): $A=LU$, önce $LY=C$, sonra $UX=Y$.
- Jacobi: önceki iterasyonun değerleri. Gauss-Seidel: en güncel değerler.
- Durma ölçütü: $|x^{(k+1)}-x^{(k)}| <$ hata, bütün değişkenler için.
- Doğrusal olmayan sistem: $J\,[\Delta x,\ \Delta y]^T = -[f,\ g]^T$.
- Geri fark: $f'(x_i)\approx\frac{f(x_i)-f(x_i-h)}{h}$.
- İleri fark: $f'(x_i)\approx\frac{f(x_i+h)-f(x_i)}{h}$.
- Merkezi fark: $f'(x_i)\approx\frac{f(x_i+h)-f(x_i-h)}{2h}$.
- Taylor ile ikinci türev (ileri): $f''(x_i)\approx\frac{f_i-2f_{i+1}+f_{i+2}}{h^2}$.

## Detaylı Açıklamalar

- **Cramer yöntemi.** Denklem takımı $[A][X]=[C]$ biçimine getirilir. $x_1$ için $A$'nın birinci sütununa $c_1, c_2, c_3$ yazılır ve bu matrisin determinantı $|A|$'ya bölünür; $x_2$ ve $x_3$ için aynı işlem ikinci ve üçüncü sütunla yapılır. Derste $3\times3$ determinant Sarrus kuralıyla hesaplandı: ilk iki satır matrisin altına yeniden yazılır, bir yöndeki köşegen çarpımları toplanır, diğer yöndekiler toplanıp çıkarılır. Örnekte bir yönün toplamı 12, diğerininki 17 çıktı ve $|A| = 12-17 = -5$ bulundu. Slayttaki açılım da aynı sonucu verir: $|A| = 2(-1-4)+3(-1+6)+2(-2-3) = -5$ (ekrandan, 00:25:00). Pay determinantları $-5$, $-15$ ve $10$ olduğundan $x_1=1$, $x_2=3$, $x_3=-2$ çıkar (python ile doğrulandı).
  - Ders sonrası not: Slayttaki matris gösteriminde $C$ sütununun son elemanı $1$ yazılmış. Denklemde bu değer $-1$'dir ve verilen çözüm $-1$ ile tutarlıdır.
- **Gauss yok etme.** Üst üçgen biçimdeki bir sistemde en alttaki denklem tek bilinmeyenlidir. Ondan başlayarak yukarı doğru yerine koyma yapılır. Slayttaki örnekte genişletilmiş matris $[2,-3,2\,|\,5;\ 0,1,-2\,|\,8;\ 0,0,1\,|\,2]$ idi: $z=2$, $y-2z=8 \Rightarrow y=12$ (ekrandan, 00:35:00).
  - Ders sonrası not: Hoca birinci denklemi $2x-3y+2z=2$ diye yazıp $x=17$ buldu. Slayttaki sağ taraf değeri ($c_1=5$) ile $2x-36+4=5$, yani $x=18{,}5$ olur.
- **Gauss ve Gauss-Jordan örneği** (Cholesky örneğindeki sistemle aynı): $3{,}6x+2{,}4y-1{,}8z=6{,}3$, $4{,}2x-5{,}8y+2{,}1z=7{,}5$, $0{,}8x+3{,}5y+6{,}5z=3{,}7$ (ekrandan, 01:10:00). Birinci satır $3{,}6$'ya bölünür: $[1;\ 0{,}667;\ -0{,}5\,|\,1{,}75]$. İkinci satır $a_{21}=4{,}2$'ye bölünür, birinci satır çıkarılır, sonra $4{,}2$ ile çarpılır: $[0;\ -8{,}6;\ 4{,}2\,|\,0{,}15]$. Üçüncü satıra $a_{31}=0{,}8$ ile aynı işlem uygulanır: $[0;\ 2{,}966;\ 6{,}9\,|\,2{,}3]$. Sonra ikinci satır $-8{,}6$'ya bölünür: $[0;\ 1;\ -0{,}489\,|\,-0{,}017]$ (ekrandan, 00:40:00). Ardından $a_{32}$ sıfırlanır ve geri yerine koyma yapılır. Gauss-Jordan'da bunlara ek olarak köşegenin üstü de sıfırlanır. Sonuç: $x\approx1{,}811$, $y\approx0{,}120$, $z\approx0{,}282$ (python ile doğrulandı).
- **LU (Cholesky) ayrışımı.** $L$'nin elemanları ve köşegeni 1 olan $U$'nun elemanları, $LU$ çarpımı $A$'ya eleman eleman eşitlenerek sırayla bulunur: $L_{11}=3{,}6$, $U_{12}=0{,}67$, $U_{13}=-0{,}5$, $L_{21}=4{,}2$, $L_{22}=-8{,}6$, $U_{23}\approx-0{,}49$, $L_{31}=0{,}8$, $L_{32}=2{,}96$, $L_{33}=8{,}4$ (ekrandan, 01:10:00). $LY=C$'den $Y\approx(1{,}75;\ -0{,}017;\ 0{,}28)$ çıkar. $UX=Y$ geri yerine koymayla çözülünce Gauss ile aynı sonuç bulunur.
  - Ders sonrası not: Slaytta $U_{23}=0{,}49$ yazıyor. Kendi denklemi $-2{,}1-8{,}6U_{23}=2{,}1$'den $U_{23}=-0{,}488$ çıkar. Slayttaki $L_{33}$ satırında kullanılan $-1{,}45$ terimi de eksi işaretli değerle tutarlıdır.
- **Jacobi ve Gauss-Seidel.** Örnek sistem $-x+4y-3z=-8$, $3x+y-2z=9$, $x-y+4z=1$ (hata $0{,}001$). İlk iki denklemin yeri değiştirilerek köşegen baskınlığı sağlanır. Sonra $x=(9-y+2z)/3$, $y=(-8+x+3z)/4$, $z=(1-x+y)/4$ yazılır (ekrandan, 01:25:00). Başlangıç $0,0,0$ alınınca Jacobi'nin ilk adımı $x=3$, $y=-2$, $z=0{,}25$ verir. Slayttaki tablo $1,1,1$ ile başlar: Jacobi'nin ilk adımı $3{,}333;\ -1{,}0;\ 0{,}25$, Gauss-Seidel'inki ise $3{,}333;\ -0{,}417;\ -0{,}688$ olur. Gauss-Seidel 9. satırda $x=3$, $y=-2$, $z=-1$ değerine oturur (ekrandan, 01:30:00). Python ile aynı başlangıçtan Jacobi'nin $0{,}001$ ölçütünü ancak 14. satırda sağladığı görüldü.
- **Doğrusal olmayan sistem örneği.** $x^2+y-3=0$, $x+y^2-5=0$, $x_0=0{,}7$, $y_0=1{,}7$, hata $0{,}08$. Kısmi türev matrisi $\begin{bmatrix}2x&1\\1&2y\end{bmatrix}$'dir (ekrandan, 01:45:00). İlk adımda $1{,}4\Delta x+\Delta y=0{,}81$ ve $\Delta x+3{,}4\Delta y=1{,}41$ sistemi çözülür. Çözüm $(1, 2)$'ye yakınsar.
- **Sayısal türev örnekleri.** $f(x)=e^x$, $x=1$, $h=0{,}1$ için ileri fark $2{,}86$, geri fark $2{,}59$, merkezi fark $2{,}72$ çıkar; analitik değer $e\approx2{,}718$'dir. $f(x)=x^2$, $x=1$, $h=0{,}1$ için geri fark $1{,}9$, ileri fark $2{,}1$, merkezi fark $2$ çıkar (python ile doğrulandı).
  - Ders sonrası not: Hoca $f(x)=x^3$ grafiğinde türevi "$2x^3$" diye söyledi. Doğrusu $f'(x)=3x^2$'dir.
- **Taylor serisiyle türev.** $f(x_i+h)$ ve $f(x_i+2h)$ ikinci kuvvete kadar açılır. Birinci açılım $-4$ ile çarpılıp ikincisiyle toplanırsa $f''$ terimi yok olur ve $f'_i=\frac{1}{2h}[-3f_i+4f_{i+1}-f_{i+2}]$ bulunur (ekrandan, 02:15:00). Birinci açılım $-2$ ile çarpılıp toplanırsa bu kez $f'$ yok olur: $f''_i \approx \frac{f_i-2f_{i+1}+f_{i+2}}{h^2}$.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
