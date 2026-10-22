# Ders 11 Çalışma Özeti

## Genel Konular

- Duyurular
  - Bu, dönemin son konu dersi. Gelecek hafta ikinci vize var, yine online test. Saat, alttan alınan derslerle çakışmaması için değişebilir. OBS ve Classroom üzerinden duyurulacak.
  - Vizeden sonra projesini bitirenlerin projelerine bakılmaya başlanacak. Dersin mevcudu dönem başında 98 iken 120'ye yaklaştı, kontrol uzun sürecek.
  - Projesini gelecek hafta göstermek isteyenler hocaya e-posta atsın. Sunum sırası listesi yapılmayacak: hoca rastgele isim çağıracak, hazır olan gösterecek, olmayan sonraki haftaya kalacak. Liste yapmak son haftaya kalanlara haksızlık olurdu. Herkes son iki hafta hazır olmalı.
  - Her öğrenci yalnızca kendi projesinden ve sunumundan sorumludur. Diğer sunumları dinlemek zorunlu değil. Sunumda kamera açık olacak.
  - Final: 4-5 klasik soru. Hesap makinesini daha gerçekçi kullanacaksınız, işlem süreleri testteki gibi kısa olmayacak. Finale teste çalışır gibi çalışmayın.
  - Projeyi kendiniz kodlayın. Amaç algoritma düşüncesini birinci sınıfta kazanmanız, çünkü ikinci sınıfta kendinizi algoritmaların içinde bulacaksınız. "Eksik yapın ama kendiniz yapın. Not için değil, geleceğiniz için yapın."
  - Her küçük şeyi sormak yerine araştırın ve inisiyatif alın. Hoca bunu kendisinin geç yaşta öğrendiğini söyler.
- Regresyon ve enterpolasyon farkı
  - İkisinde de ölçülen $x$ ve $y$ değerlerinden bir fonksiyon bulunur. Enterpolasyon daha gerçekçi, noktalardan geçen bir fonksiyon bulur. Regresyon daha yaklaşık bir fonksiyon bulur.
  - Gerçek dünyada bulunan fonksiyon verilere tam oturmaz: $y_i = F(x_i) + \varepsilon_i$. Hoca derste özel bir fonksiyondan üretilmiş veriler verdiği için örneklerde sonuç tam çıkar.
  - Regresyonda doğrusal olmayan fonksiyonlar da uydurulabilir. Bunları çözmek için önce doğrusal hâle getirmek gerekir.
- En küçük kareler yöntemi
  - Her noktada gerçek değer ile uydurulan fonksiyonun değeri arasında bir fark (distance) vardır: $d_i = y_i - F(x_i)$.
  - Farkları doğrudan toplamak yanıltıcıdır: artı ve eksi farklar birbirini götürür. Örnek: farklar 5, −4, −3, +3 ise toplam 1 çıkar ama gerçek toplam sapma 15'tir.
  - Bu yüzden farkların kareleri toplanır: $25 + 16 + 9 + 9 = 59$. Amaç bu kareler toplamını en küçük yapmaktır: $S = \sum_{i=1}^{n} d_i^2$.
  - Yöntem her fonksiyon için aynıdır:
    1. $S = \sum_{i=1}^{n}\left(y_i - F(x_i)\right)^2$ yazılır.
    2. $F$'deki her bilinmeyen katsayıya göre $S$'nin türevi alınıp sıfıra eşitlenir.
    3. Bilinmeyen sayısı kadar denklem çıkar. Matris biçiminde yazılıp çözülür (Cramer, Gauss…).
    4. Bulunan katsayılar $F$'de yerine konur.
- Doğru uydurma: $F(x) = A + Bx$
  - $S = \sum (y_i - A - Bx_i)^2$. $\frac{\partial S}{\partial A} = 0$ ve $\frac{\partial S}{\partial B} = 0$:
    - $\begin{bmatrix} n & \sum x_i \\ \sum x_i & \sum x_i^2 \end{bmatrix}\begin{bmatrix} A \\ B \end{bmatrix} = \begin{bmatrix} \sum y_i \\ \sum x_i y_i \end{bmatrix}$
  - $\sum_{i=1}^{n} A = nA$ olduğu için sol üstte $n$ vardır.
  - Örnek 1: $x$: 0, 2, 4, 6, 8, 10, $y$: 1, 5.1, 9, 13, 17, 21.
    - $n = 6$, $\sum x = 30$, $\sum x^2 = 220$, $\sum y = 66.1$, $\sum xy = 470.2$.
    - Cramer: $\Delta = 6 \cdot 220 - 30^2 = 420$, $\Delta A = 436$, $\Delta B = 838.2$. $A = 1.03809$, $B = 1.99571$.
    - $y = 1.038 + 1.996x$. $x = 0$ için 1.038 (gerçek 1), fark 0.038.
  - Örnek 2: $x$: 0, 2, 3, 4, 5, 7, 8, 9, 10, 12, $y$: 0, 8, 10, 14, 17, 22, 26, 29, 32, 35.
    - $n = 10$, $\sum x = 60$, $\sum x^2 = 492$, $\sum y = 193$, $\sum xy = 1550$. $\Delta = 1320$, $\Delta A = 1956$, $\Delta B = 3920$.
    - $y = 1.48 + 2.96x$. $x = 0$ için 1.48 (gerçek 0).
  - Sapmaların kareleri toplamı çok büyükse bu noktalardan doğru geçmiyordur. Parabol veya üstel bir fonksiyon denenir. Sınavda hangi fonksiyonun geçirileceği söylenecek. Gerçek hayatta noktaları çizip şekle bakarak karar verilir.
- Vize sorusu: $y = ax$ doğrusu
  - Sınıfın büyük çoğunluğu bu soruyu çözemedi, çünkü $A + Bx$ matrisini ezberlemişlerdi.
  - $S = \sum (y_i - ax_i)^2$. Tek bilinmeyen $a$: $\frac{\partial S}{\partial a} = -2\sum x_i(y_i - ax_i) = 0$, yani $a = \frac{\sum x_i y_i}{\sum x_i^2}$.
  - Veri: $x$: 3, 4, 5, 6, 7, $y$: 2.25, 3, 3.75, 4, 5.75. $\sum x^2 = 135$, $\sum xy = 101.75$. $a = \frac{101.75}{135} = 0.7537$. $y = 0.7537x$.
  - Ezberlenmiş matristen de çıkarılabilirdi: $A + Bx$ yerine yalnızca $ax$ olduğu için $A$ yoktur, ikinci denklem $a\sum x_i^2 = \sum x_i y_i$ olur.
  - "Ezber yok. Gerçek $y$ ile geçirilmesi istenen fonksiyonun farkının karelerini toplayıp bilinmeyenlere göre türev alın."
- Parabol uydurma: $F(x) = A + Bx + Cx^2$
  - Üç bilinmeyen, üç türev:
    - $\begin{bmatrix} n & \sum x & \sum x^2 \\ \sum x & \sum x^2 & \sum x^3 \\ \sum x^2 & \sum x^3 & \sum x^4 \end{bmatrix}\begin{bmatrix} A \\ B \\ C \end{bmatrix} = \begin{bmatrix} \sum y \\ \sum xy \\ \sum x^2 y \end{bmatrix}$
  - Desen: her satırda $x$'in kuvveti bir artar, sağ taraf $y$, $xy$, $x^2y$… 3. dereceden polinom için matrise $x^3$…$x^6$ terimleri ve $D$ bilinmeyeni, sağ tarafa $x^3 y$ eklenir.
  - Örnek: $x$: 2, 3, 5, 6, 8, $y$: 1, 6, 22, 33, 61. $\sum x = 24$, $\sum x^2 = 138$, $\sum x^3 = 888$, $\sum x^4 = 6114$, $\sum y = 123$, $\sum xy = 816$, $\sum x^2y = 5700$.
    - $\Delta = 8316$, $A = -3$, $B = 0$, $C = 1$. $y = x^2 - 3$. Kontrol: $x = 2$ için 1, $x = 5$ için 22.
- Fonksiyon seçimi
  - Enterpolasyondaki gibi fark tablosu çıkarılır. Hangi dereceden fark sabitlenirse o dereceden polinom uydurulabilir.
  - Noktalar çizilir. $y$ eksenine göre simetri varsa çift kuvvetli bir fonksiyon, periyodik değişim varsa sinüs-kosinüslü bir fonksiyon kullanılır.
  - Değerler ayrık gruplar hâlindeyse her bölgeye ayrı eğri (ör. bir bölgeye parabol, diğerine doğru) uydurulabilir.
- Doğrusal olmayan fonksiyonlar
  - Bir bilinmeyen başka bir ifadenin üssündeyse (ör. $e^{bx}$, $x^b$, $b^x$) fonksiyon doğrusal değildir. Her iki tarafın logaritması alınarak doğrusal hâle ($Y = A + BX$) getirilir. Sonra doğru matrisinde ilgili yerlere yeni değişkenler konur.
  - $y = ae^{bx}$: $\ln y = \ln a + bx$. $Y = \ln y$, $A = \ln a$, $B = b$, $X = x$. Sonunda $a = e^A$.
  - $y = ax^b$: $\ln y = \ln a + b\ln x$. $Y = \ln y$, $A = \ln a$, $B = b$, $X = \ln x$. Matriste $\sum \ln x$, $\sum (\ln x)^2$, $\sum \ln y$, $\sum \ln x \ln y$ kullanılır.
  - $y = ab^x$: $\ln y = \ln a + x\ln b$. $Y = \ln y$, $A = \ln a$, $B = \ln b$, $X = x$. Sonunda $a = e^A$, $b = e^B$.
  - Örnek ($y = ab^x$): $x$: 0, 2, 3, 4, 5, $y$: 5.2, 56.628, 186.872, 616.679, 2035.04.
    - $n = 5$, $\sum x = 14$, $\sum x^2 = 54$, $\sum \ln y = 24.958$, $\sum x\ln y = 87.550$. $\Delta = 74$.
    - $A = 1.649$, $B = 1.1938$, $a = e^A = 5.202$, $b = e^B = 3.2995$. $y = 5.202 \cdot 3.3^x$.
  - Sınıf alıştırması ($y = ax^b$): $x$: 1, 3, 5, $y$: 3, 15.588, 33.541.
    - $\sum \ln x = 2.708$, $\sum (\ln x)^2 = 3.797$, $\sum \ln y = 7.359$, $\sum \ln x \ln y = 8.671$.
    - $\Delta = 4.0577$, $A = 1.0994$, $B = 1.4996$. $a = e^A = 3$, $b = B = 1.5$. $y = 3x^{1.5}$.
  - Örnek ($y = ae^{bx}$): $x$: 0, 1, 2, $y$: 1, 2, 6.
    - $\sum \ln y = 2.4849$, $\sum x\ln y = 4.2767$. $A = -0.06758$, $B = 0.89588$. $a = e^A = 0.9347$, $b = B$.
    - $y = 0.9347e^{0.8959x}$. $x = 0$ için 0.93 (gerçek 1), sapma vardır.
- Trigonometrik fonksiyonlar
  - En genel hâl: $F(x) = a_0 + \sum_k a_k\cos kx + \sum_k b_k\sin kx$. Bunun bir alt kümesi istenebilir (ör. $a_0 + a_1\cos x$).
  - Yöntem aynı: $S = \sum\left(y_i - F(x_i)\right)^2$, her katsayıya göre türev. Örneğin $a_0 + a_1\cos x + b_1\sin x$ için matris:
    - $\begin{bmatrix} n & \sum\cos x & \sum\sin x \\ \sum\cos x & \sum\cos^2 x & \sum\sin x\cos x \\ \sum\sin x & \sum\sin x\cos x & \sum\sin^2 x \end{bmatrix}\begin{bmatrix} a_0 \\ a_1 \\ b_1 \end{bmatrix} = \begin{bmatrix} \sum y \\ \sum y\cos x \\ \sum y\sin x \end{bmatrix}$
  - Açılar derece verildiyse derece, radyan verildiyse radyan ile hesaplanır.
  - Örnek ($y = a_0 + a_1\sin x$): $x$: 0°, 20°, 40°, 60°, 80°, $y$: 2.5, 3.526, 4.428, 5.098, 5.454.
    - Denklemler: $na_0 + a_1\sum\sin x = \sum y$, $a_0\sum\sin x + a_1\sum\sin^2 x = \sum y\sin x$.
    - Slaytta sonuç $y = 2.571 + 2.874\sin x$ (doğru sonuç için "Ders sonrası notlar"a bakın).
- Çoklu regresyon
  - Birden fazla girdi (bağımsız değişken) vardır.
  - Örnek: kanaldaki akış miktarı $Q$ (m³/s), borunun çapı $D$ ve eğimi $S$'ye bağlı: $Q = a_0 D^{a_1} S^{a_2}$.
    - Logaritma alınınca: $\log Q = \log a_0 + a_1\log D + a_2\log S$. $y = \log Q$, $x_1 = \log D$, $x_2 = \log S$. Model: $y = a_0' + a_1x_1 + a_2x_2$.
    - Matris: $\begin{bmatrix} n & \sum x_1 & \sum x_2 \\ \sum x_1 & \sum x_1^2 & \sum x_1x_2 \\ \sum x_2 & \sum x_1x_2 & \sum x_2^2 \end{bmatrix}\begin{bmatrix} a_0' \\ a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} \sum y \\ \sum x_1 y \\ \sum x_2 y \end{bmatrix}$
    - 9 veri ile: $a_0' = 1.7475$, $a_1 = 2.62$, $a_2 = 0.54$. $a_0 = 10^{1.7475} = 55.9$. Sonuç $Q = 55.9\,D^{2.62}S^{0.54}$.
  - Değişen tek şey hesaplanacak toplamların artmasıdır. Yöntem aynıdır.
- Proje sorusu: Gauss-Seidel'de köşegeni maksimum yapma
  - En kolay yol: her sütunda, henüz yeri değişmemiş denklemler arasında mutlak değerce en büyük katsayıyı bulup o denklemi köşegene getirmek. Bir kez yerleşen denklem bir daha taşınmaz.
  - Bu yöntem her zaman en iyi sonucu vermeyebilir. Bütün permütasyonları denemek ($n!$) büyük matrislerde çok pahalıdır. Hoca bu konudaki hazır kodları araştırıp analiz etmenizi önerdi. İsterseniz kullanıcıdan denklemleri köşegeni büyük olacak şekilde girmesini de isteyebilirsiniz.
  - Kodunuzu 10-20 boyutlu matrislerle sınayın. Değişken tiplerinin (ör. `byte`, `int`) yetmeyebileceğini unutmayın.

## Hocanın Özellikle Vurguladığı Kısımlar

- En küçük kareler: farkları değil, farkların karelerini toplayın. Artı ve eksi farklar birbirini götürür.
- Ezberlemeyin. Her soruda $S = \sum(y_i - F(x_i))^2$ yazın ve bilinmeyenlere göre türev alın. $y = ax$ vize sorusunu çoğunuz ezber yüzünden çözemediniz.
- Doğrusal olmayan fonksiyonu önce logaritma ile doğrusal hâle getirin. Matriste hangi yerine neyi koyduğunuza (ör. $x$ yerine $\ln x$) dikkat edin. Sonunda $a = e^A$ gibi geri dönüşümü unutmayın.
- Final klasik ve daha uzun işlemli olacak.
- Projeyi kendiniz kodlayın, sunumda kamera açık olsun.

## Kısa Tekrar Notları

- $S = \sum (y_i - F(x_i))^2$, $\frac{\partial S}{\partial (\text{katsayı})} = 0$.
- Doğru: $\begin{bmatrix} n & \sum x \\ \sum x & \sum x^2 \end{bmatrix}\begin{bmatrix} A \\ B \end{bmatrix} = \begin{bmatrix} \sum y \\ \sum xy \end{bmatrix}$.
- $y = ax$: $a = \frac{\sum xy}{\sum x^2}$.
- Parabol: $3 \times 3$ matris, $\sum x^0 \ldots \sum x^4$, sağda $\sum y, \sum xy, \sum x^2y$.
- $y = ae^{bx}$: $(\ln y, x)$ doğrusu, $a = e^A$. $y = ax^b$: $(\ln y, \ln x)$ doğrusu, $a = e^A$. $y = ab^x$: $(\ln y, x)$ doğrusu, $a = e^A$, $b = e^B$.
- Çoklu: $Q = a_0D^{a_1}S^{a_2}$, $\log Q = \log a_0 + a_1\log D + a_2\log S$.

## Detaylı Açıklamalar

### Logaritmayla doğrusallaştırmanın bir inceliği

- Logaritma alındıktan sonra en küçük kareler, $\ln y$ üzerindeki hataları en küçük yapar, $y$ üzerindekileri değil. Bu yüzden bulunan katsayılar, doğrudan $y$ üzerinde hatayı küçülten (doğrusal olmayan) en küçük kareler çözümünden biraz farklı olabilir. Ders kapsamında bu fark önemsenmez. Pratikte de yaygın kullanılan yöntem budur.

### Ders sonrası notlar

- **Örneklerin kontrolü:** Bütün örnekler ders sonrasında Python ile yeniden hesaplandı. Doğru (iki örnek), $y = ax$, parabol ($x^2 - 3$), $y = ab^x$, $y = ax^b$ ($3x^{1.5}$), $y = ae^{bx}$ ve çoklu regresyon sonuçları doğrudur.
- **Trigonometrik örnekte hata:** Slayttaki denklem sisteminin ilk satırında $a_1$'in katsayısı $\sum\sin x = 2.836$ olmalıyken $\sum\sin^2 x = 2.25$ yazılmış. Ayrıca $\sum y\sin x$ doğru hesaplanınca $13.838$'dir (slaytta 13.758). Doğru sistem: $5a_0 + 2.836a_1 = 21.006$, $2.836a_0 + 2.25a_1 = 13.838$. Çözüm $a_0 = 2.5$, $a_1 = 3.0$. Yani veriler tam olarak $y = 2.5 + 3\sin x$'ten üretilmiştir: $x = 20°$ için $2.5 + 3 \cdot 0.342 = 3.526$. Slayttaki $y = 2.571 + 2.874\sin x$ sonucu yanlıştır.
- **$y = ae^{bx}$ örneğinde üs:** Slaydın son satırında üs $0.5958797$ yazılmış. Doğrusu $b = 0.8958797$'dir: $y = 0.9347e^{0.8959x}$.
- **$y = ax$ örneğinde:** Slaytta bir yerde $a = 0.7527$, sonuçta $0.7537$ yazıyor. Doğrusu $\frac{101.75}{135} = 0.7537$'dir.
- **Doğru örneği 2:** $B = \frac{3920}{1320} = 2.9697$'dir. Slayttaki 2.96 kesilmiş değerdir, yuvarlanınca 2.97 olur.
- **Çoklu regresyonda logaritma tabanı:** Tablodaki değerler 10 tabanlı logaritmadır ($\log 2 = 0.301$). Bu yüzden $a_0 = 10^{1.7475} = 55.9$'dur. Derste sözlü olarak "$e$ üzeri 1.74" dendi. $e^{1.7475} = 5.74$ olurdu ve yanlış sonuç verirdi. Logaritmayı hangi tabanda aldıysanız geri dönüşü aynı tabanla yapın. Kesin hesapla $a_0 = 55.97$, $a_1 = 2.616$, $a_2 = 0.537$. Ayrıca tablodaki $\sum x_1^2$ (0.954) ile matristeki değer (0.924) uyuşmuyor. Doğrusu yaklaşık 0.955'tir.
- **Parabol örneğinde tablo:** $x = 6$ satırında $x^2 y$ değeri 1118 yazılmış. Doğrusu $36 \cdot 33 = 1188$'dir. Toplam (5700) doğru değerle tutar.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
