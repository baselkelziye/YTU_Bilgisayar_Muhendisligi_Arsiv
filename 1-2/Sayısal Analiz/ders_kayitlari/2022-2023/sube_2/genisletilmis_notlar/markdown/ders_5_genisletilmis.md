# Ders 5 Genişletilmiş Notu: Taylor Serisiyle Yüksek Mertebeden Sayısal Türev, Jacobi ve Gauss-Seidel Uygulaması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Sayısal Türevin Hatırlatılması
- 2. Taylor Serisiyle Türev Formülü Türetme
- 3. Merkezi Farklarla İkinci Türev
- 4. Beş Noktalı Merkezi Farklar
- 5. Sayısal Yöntemler İçin Python Araçları
- 6. Jacobi ve Gauss-Seidel Yöntemlerinin Excel'de Karşılaştırılması
- 7. Sayısal Yöntemleri C ile Kodlarken Dikkat Edilecekler
- 8. Polinomun struct ile Modellenmesi
- Örnek Sorular

## 1. Sayısal Türevin Hatırlatılması

Bu ders, önceki haftalarda anlatılan sayısal türev konusunun tekrarı ve genişletilmesiyle başladı. Hoca sayısal türevin amacını şöyle hatırlattı: analitik olarak türevi alınması güç olan bir fonksiyonun türev fonksiyonunu bulmaya gerek kalmadan, yalnız fonksiyonun kendi değerlerini kullanarak türevin bir noktadaki yaklaşık değerini tahmin etmek. Türev bir değişim hızıdır: bağımsız değişken değiştiğinde fonksiyonun ne hızla değiştiğini ölçer. Elimizde $f(x)$ vardır ve $x_i$ noktasındaki türevin sayısal değerini bulmak isteriz; $f'(x)$'in fonksiyon olarak bulunmasına gerek yoktur.

Bunun için çok küçük bir $h$ uzaklığı seçilir. $x_i$'den $h$ kadar gerideki nokta $x_{i-1}$'dir; indis kullanılmazsa $x_i - h$ diye de yazılabilir. Eğim, $y$ eksenindeki değişimin $x$ eksenindeki değişime oranıdır. Geri farklarla türev (ekrandan, 00:05:00):

$$f'(x_i) = \frac{\Delta f(x)}{\Delta x} = \frac{f(x_i) - f(x_{i-1})}{x_i - x_{i-1}} = \frac{f(x_i) - f(x_i - h)}{h}$$

İleri farkta $x_i$'den bir sonraki nokta, yani $x_i + h$ kullanılır; formül hemen hemen aynıdır, yalnız noktaların yeri değişir. Merkezi farkta noktanın biraz ilerisi ve biraz gerisi alınır: $x_{i+1}$ ve $x_{i-1}$ noktalarının görüntüleri arasındaki fark, iki nokta arasındaki $2h$ uzaklığına bölünür.

$$f'(x_i) \approx \frac{f(x_{i+1}) - f(x_{i-1})}{2h}$$

Bu ifadelerin hepsi birinci türevi bulmaya yöneliktir. Dersin geri kalanında aynı fikrin Taylor serisiyle ikinci, üçüncü ve daha yüksek mertebeden türevlere nasıl genişletildiği anlatıldı.

## 2. Taylor Serisiyle Türev Formülü Türetme

### 2.1 Genel fikir

Taylor serisi kullanılarak ikinci, üçüncü ya da daha yüksek mertebeden türevler de türev alınmadan, yalnız $f(x)$ değerleriyle hesaplanabilir. $x$ yerine öyle değerler konur ki sonuçta istenen türevin yaklaşık değeri çıkar.

Hoca bunu doğrusal denklem sistemlerine benzetti. $f(x)$ değerlerini hesaplayabiliriz ama türevlerin sayısal değerlerini bilmeyiz. Yani $f'(x_i)$ bir bilinmeyen ($\alpha$), $f''(x_i)$ başka bir bilinmeyen ($\beta$), $f'''(x_i)$ bir başkası ($\gamma$) gibidir. Üç bilinmeyen varsa üç denklem gerekir. Denklemler taraf tarafa toplanıp çıkarılarak istenmeyen bilinmeyenler yok edilir ve istenen türev $f(x)$ değerleri türünden yazılır. Bu şekilde elde edilen eşitliklere türev denklemleri denir; dersin kitabında bunların tabloları da vardır.

Birden fazla denklem için birden fazla nokta gerekir. Bu noktalar $x_i$'nin çevresinden seçilir: $h$ kadar ilerisi $x_{i+1}$, $h$ kadar gerisi $x_{i-1}$, ve gerekirse $x_{i\pm2}$. Bu noktalar Taylor serisine açılarak iki, üç ya da dört denklem kurulur. Örneğin $3x^3 + 4x^2$ gibi bir fonksiyonun ikinci türevi analitik olarak önce birinci, sonra ikinci türev alınarak bulunur; bu yöntemde ise ikinci ya da üçüncü türevi doğrudan yaklaşık hesaplayan eşitlikler elde edilir.

### 2.2 İleri farklarla birinci türev

Slayttaki problem (ekrandan, 00:10:00): $f(x)$ fonksiyonunun $x_i + h$ ve $x_i + 2h$ civarındaki değerlerini $f(x_i)$'nin kuvvetleri cinsinden ikinci kuvvete kadar açıp $f'(x_i)$'yi çekelim. Birinci türev için iki nokta yeter; bu noktalar $x_i + h$ ve $x_i + 2h$ seçildiği için bu bir ileri yönlü açılımdır.

$$f(x_i + h) = f(x_i) + \frac{h^1 f'(x_i)}{1!} + \frac{h^2 f''(x_i)}{2!}$$

$$f(x_i + 2h) = f(x_i) + \frac{(2h)^1 f'(x_i)}{1!} + \frac{(2h)^2 f''(x_i)}{2!}$$

Seride $h^0 = 1$ olan ilk terim $f(x_i)$'dir. Daha yüksek kuvvetli terimler de yazılabilir ama bunlar kesme hatası olarak ayrılır. $(2h)^2 / 2! = 2h^2$ olduğundan ikinci denklem $f(x_i + 2h) = f(x_i) + 2h f'(x_i) + 2h^2 f''(x_i)$ olur.

Birinci türev isteniyorsa ikinci türev yok edilmelidir. İlk denklem $-4$ ile çarpılır:

$$-4f(x_i + h) = -4f(x_i) - 4h f'(x_i) - 2h^2 f''(x_i)$$

$$f(x_i + 2h) = f(x_i) + 2h f'(x_i) + 2h^2 f''(x_i)$$

Taraf tarafa toplanınca $-2h^2 f''$ ile $+2h^2 f''$ birbirini götürür:

$$f(x_i + 2h) - 4f(x_i + h) = -3f(x_i) - 2h f'(x_i)$$

$f(x_i)$'li terim karşı tarafa atılır ve iki taraf $-2h$'ye bölünür:

$$f'(x_i) = \frac{1}{2h}\left[-3f(x_i) + 4f(x_i + h) - f(x_i + 2h)\right], \qquad f'_i = \frac{1}{2h}\left[-3f_i + 4f_{i+1} - f_{i+2}\right]$$

Bunun ileri fark olduğu formüldeki indislerden anlaşılır: $i$ noktası ve ondan sonraki $i+1$, $i+2$ noktaları kullanılır.

Kullanımı: $h = 0.001$ ve $x_i = 5$ verilirse fonksiyonda $x$ yerine $5$ yazılıp sonuç $-3$ ile, $5.001$ yazılıp sonuç $4$ ile çarpılır, $5.002$'deki değerin negatifi eklenir ve toplam $2h = 0.002$'ye bölünür. Bulunan sayı, fonksiyonun o noktadaki türevinin yaklaşık değeridir.

### 2.3 İleri farklarla ikinci türev

Aynı iki açılımdan ikinci türev isteniyorsa bu kez birinci türevli terimler yok edilmelidir. Bunun için ilk denklem $-2$ ile çarpılıp ikincisiyle toplanır. Hoca ikinci türevin $\frac{1}{h^2}$ çarpanıyla $f(x_i)$, $f(x_i + h)$ ve $f(x_i + 2h)$ değerlerinden oluştuğunu söyledi; katsayılar şöyle çıkar (ara adım eklendi):

$$-2f(x_i + h) + f(x_i + 2h) = -f(x_i) + h^2 f''(x_i) \quad\Rightarrow\quad f''(x_i) \approx \frac{f(x_i) - 2f(x_i + h) + f(x_i + 2h)}{h^2}$$

Hoca bunun kodlamadaki karşılığını da anlattı. Bir polinom ya da genel bir fonksiyon için $f(x)$'i hesaplayan bir C fonksiyonu (function evaluation) yazılır. Bu fonksiyon $x_i$, $x_i + h$ ve $x_i + 2h$ ile üç kez çağrılır ve sonuçlar formüle konur. Diğer fark türleri için de durum aynıdır.

## 3. Merkezi Farklarla İkinci Türev

Hoca bu kısmı PowerPoint'te elle yazarak anlattı. Amaç ikinci mertebe türevi üç nokta kullanarak merkezi farklar yöntemiyle bulmaktı.

Merkezi fark demek, $x_i$ noktasının $h$ kadar ilerisindeki $x_{i+1}$ ile $h$ kadar gerisindeki $x_{i-1}$'in birlikte kullanılması demektir. Sonuç denkleminde $i+1$'li, $i-1$'li ve varsa $i$'li terimler bulunur. Önceki bölümdeki ileri fark denkleminde hep $i+1$, $i+2$ gibi artılı indisler vardı; geri farklarda eksili indisler olurdu; merkezi farkta ise hem önceki hem sonraki terim yer alır. İkinci türevi bulmak için birinci türevin de içinde olduğu iki denklem gerekir.

$f$ iki noktada Taylor serisine açılır (ekrandan, 00:20:00):

$$f(x_{i+1}) = f(x_i) + f'(x_i)\,\frac{(x_{i+1} - x_i)}{1!} + f''(x_i)\,\frac{(x_{i+1} - x_i)^2}{2!}$$

$$f(x_{i-1}) = f(x_i) + f'(x_i)\,\frac{(x_{i-1} - x_i)}{1!} + f''(x_i)\,\frac{(x_{i-1} - x_i)^2}{2!}$$

Hoca "$x_{i+1} - x_i$ neye eşittir?" diye sordu; bir öğrenci $h$ diye cevap verdi. Bu, kullanıcıdan alınan sayısal bir değerdir. $x_{i-1} - x_i$ ise $-h$'dir; karesi yine $h^2$ olur. Düzenlenince (ekrandan, 00:25:00):

$$f(x_{i+1}) = f(x_i) + h f'(x_i) + \frac{h^2}{2} f''(x_i)$$

$$f(x_{i-1}) = f(x_i) - h f'(x_i) + \frac{h^2}{2} f''(x_i)$$

İkinci türev isteniyorsa iki denklem doğrudan toplanır: $+h f'$ ve $-h f'$ birbirini götürür. Sağda iki tane $f(x_i)$ kalır, bunlar sola $-2f(x_i)$ olarak geçer; $\frac{h^2}{2} + \frac{h^2}{2} = h^2$ olur ve paydaya alınır:

$$f''(x_i) \approx \frac{f(x_{i+1}) - 2f(x_i) + f(x_{i-1})}{h^2}$$

Terimler sayı doğrusuna göre sıralanarak yazılır. Bazı kaynaklar $f(x_{i-1})$'i önce, bazıları sona yazar; bu yalnız bir gösterim farkıdır.

> **Ders sonrası not:** Hoca formülün düzenli halini sözlü olarak söylerken son terimi "$f(x_{i+1})$" diye okudu; ekranda yazılan ve doğru olan $f(x_{i-1})$'dir.

Birinci türev isteniyorsa ikinci denklem $-1$ ile çarpılıp toplanır. Bu kez ikinci türevler ve $f(x_i)$'ler gider, $2h f'(x_i)$ kalır ve slayttaki merkezi fark formülü $f'(x_i) \approx \frac{f(x_{i+1}) - f(x_{i-1})}{2h}$ yeniden elde edilir.

Hoca bir uygulama önerdi: $f(x) = x^3 - 8x^2$ gibi basit bir fonksiyonun ikinci türevinin $x = 4$'teki değerini $h = 0.1$ ile bulun. Bunun için $4.1$, $4$ ve $3.9$'daki değerler kullanılır. Analitik ikinci türevle karşılaştırıldığında sonucun ona çok yakın çıkacağını söyledi ve hesabı öğrencilere bıraktı (çözümü Örnek Sorular bölümündedir).

## 4. Beş Noktalı Merkezi Farklar

### 4.1 Açılımlar

Sonra konu biraz daha karıştırıldı: beş noktalı merkezi fark formülleri. Noktalar $x_{i-2}, x_{i-1}, x_i, x_{i+1}, x_{i+2}$'dir. İleri farkta hep ileri gidilirdi; merkezi farkta gerideki noktalar da alınır. Bu noktalarla ikinci, üçüncü, hatta dördüncü mertebe türev bulunabilir. Hoca mantığın anlaşılmasının yeterli olduğunu, gerisinin kolay olduğunu söyledi.

Her nokta dördüncü türeve kadar açılır. $x_{i+2} - x_i = 2h$, $x_{i+1} - x_i = h$, $x_{i-1} - x_i = -h$, $x_{i-2} - x_i = -2h$ olduğundan (ekrandan, 00:35:00):

$$f(x_{i+2}) = f(x_i) + f'(x_i)\,2h + \frac{f''(x_i)(2h)^2}{2!} + \frac{f'''(x_i)(2h)^3}{3!} + \frac{f^{(4)}(x_i)(2h)^4}{4!}$$

$$f(x_{i+1}) = f(x_i) + f'(x_i)\,h + \frac{f''(x_i)\,h^2}{2!} + \frac{f'''(x_i)\,h^3}{3!} + \frac{f^{(4)}(x_i)\,h^4}{4!}$$

$$f(x_{i-1}) = f(x_i) - f'(x_i)\,h + \frac{f''(x_i)\,h^2}{2!} - \frac{f'''(x_i)\,h^3}{3!} + \frac{f^{(4)}(x_i)\,h^4}{4!}$$

$$f(x_{i-2}) = f(x_i) - f'(x_i)\,2h + \frac{f''(x_i)\,4h^2}{2!} - \frac{f'''(x_i)\,8h^3}{3!} + \frac{f^{(4)}(x_i)\,16h^4}{4!}$$

$-h$ ve $-2h$'nin tek kuvvetleri eksi işaret getirir ($(-2h)^3 = -8h^3$), çift kuvvetleri artıdır ($(-2h)^4 = 16h^4$).

**Soru:** İlk açılımdaki ikinci türev teriminde $4h^2$ olması gerekmiyor mu? **Cevap:** Evet; $(2h)^2$ parantezle yazılmalıdır, yani $4h^2$ olur. Hoca tahtadaki ifadeyi buna göre düzeltti.

İlk açılım sadeleştirilince katsayılar: $\frac{4h^2}{2} = 2h^2$, $\frac{8h^3}{3!} = \frac{8}{6}h^3$ (hoca $\frac{8}{3}h^3$ diye yazdı), $\frac{16h^4}{24} = \frac{4}{6}h^4$ (ekrandan, 00:35:00).

> **Ders sonrası not:** $\frac{(2h)^3}{3!} = \frac{8h^3}{6} = \frac{4}{3}h^3$'tür; ekranda yazılan $\frac{8}{3}h^3$ yanlıştır. Bu terim toplama sırasında zaten yok olduğu için sonuca etkisi yoktur.

### 4.2 Denklemlerin birleştirilmesi

Bazı terimler denklemler arasında doğrudan birbirini götürür. Dört denklemin hepsi toplanırsa birinci türevler ve üçüncü türevler gider (bunlar $\pm$ çiftler halindedir), geriye ikinci ve dördüncü türevler ile $f(x_i)$'li terimler kalır. İkinci türev katsayısı: $2h^2 + \frac{h^2}{2} + \frac{h^2}{2} + 2h^2 = 5h^2$. Yazım kolaylığı için $f_i = f(x_i)$, $f_{i+1} = f(x_i + h)$ gösterimi kullanılırsa:

$$f_{i+2} + f_{i+1} + f_{i-1} + f_{i-2} = 4f_i + 5h^2 f''_i + \frac{17}{12}h^4 f^{(4)}_i$$

> **Ders sonrası not:** Hoca dördüncü türev katsayısını hesaplarken $\frac{h^4}{12}$ ile $\frac{4}{6}h^4$'ü topladı ve sonucu $\frac{4}{3}h^4$ diye söyledi. Doğrusu, $\pm 2h$ açılımlarından $2 \cdot \frac{16}{24} = \frac{4}{3}$, $\pm h$ açılımlarından $2 \cdot \frac{1}{24} = \frac{1}{12}$ gelir ve toplam $\frac{17}{12}h^4$ olur (python ile kesir hesabıyla doğrulandı).

İkinci bir denklem için, örneğin 1. ve 3. denklemler ile 2. ve 4. denklemler negatifleriyle birleştirilir. Böylece sistem iki bilinmeyenli iki denkleme indirgenir. Sonra istenmeyen türevin katsayısını yok edecek bir çarpanla birleştirme yapılarak istenen türevin formülü bulunur: istenirse dördüncü, istenirse üçüncü, ikinci ya da birinci türev.

### 4.3 Üçüncü türev formülü

Hoca türetmenin sonunda elde ettiği üçüncü türev formülünü yazdı (ekrandan, 00:40:00):

$$f'''(x_i) \approx \frac{-f_{i-2} + 2f_{i-1} - 2f_{i+1} + f_{i+2}}{2h^3}, \qquad f_i = f(x_i),\quad f_{i+1} = f(x_i + h),\ \dots$$

Bu değerlerin hepsi fonksiyonda yerine konup hesaplanabilir. Formül python ile Taylor katsayıları üzerinden kontrol edildi: paydaki birleşim $2h^3 f'''(x_i)$ artı $h^5$ mertebesinde bir kesme hatası verir, yani formül doğrudur.

## 5. Sayısal Yöntemler İçin Python Araçları

Aradan önce hoca, sayısal yöntemler üzerinde deneysel çalışma yapmak isteyenler için hazır araçların olduğunu anlattı. MATLAB gibi dillerde ve kısmen Python'da hazır kütüphaneler, hatta grafik arayüzler vardır. Örnek olarak Berkeley Üniversitesi'nin "Python Numerical Methods" adlı çevrim içi kitabını gösterdi (ekrandan, 00:45:00). Kitap önce Python temellerini, sonra sayıların gösterimi ve sayı tabanları gibi bu dersin konularını anlatıyor.

- **Görselleştirme:** Matplotlib kütüphanesiyle istenen grafik çizilebilir. Kitaptaki örnekte $-5$ ile $5$ arası 100 parçalı bir dizi oluşturulup karelerinin grafiği, yani $x^2$ eğrisi çiziliyor.
- **Sembolik işlem:** SymPy kütüphanesiyle Desmos'taki gibi sembolik işlem yapılabilir. Semboller (ör. $x$, $y$, $z$) tanımlanır, denklemler kurulur, `simplify` ile sadeleştirme yapılır. Kitaptaki bir örnekte $(x+1)^2$ ile $x^2 + 2x + 1$'in `==` ile karşılaştırılması `False` veriyor. Hoca bunu bir tarafın sembolik, diğerinin açılmış ifade olmasıyla açıkladı; iki ifadenin farkı `simplify` edilerek eşitlik görülebilir. Trigonometrik özdeşlikler (ör. $\cos^2 x - \sin^2 x$) de bu yolla denetlenebilir.
- **Doğrusal denklem sistemleri:** Kitapta $4x_1 + 3x_2 - 5x_3 = 2$, $-2x_1 - 4x_2 + 5x_3 = 5$, $8x_1 + 8x_2 = -3$ sistemi `numpy.linalg.solve(A, y)` ile çözülüyor ve sonuç $[2.20833333,\ -2.58333333,\ -0.18333333]$ çıkıyor (ekrandan, 00:45:00). Hoca kendi yazılan algoritmanın sonuçlarının bu birkaç satırlık kodla karşılaştırılabileceğini söyledi. Kitapta Gauss eliminasyonu, Gauss-Jordan, Gauss-Seidel, LU ayrıştırması, köşegen baskınlık ve yakınsama örnekleri de var.
- **Kök bulma:** İkiye bölme (bisection) ve Newton-Raphson önce kitabın kendi yazdığı kodlarla (ör. `my_bisection`) anlatılıyor, sonra hazır bir optimizasyon fonksiyonu (`fsolve`) ile kök bulunuyor. <!-- BELİRSİZ: hocanın fsolve örneği için söylediği "1 ile 100 arasında değer, iki kök" ifadesi altyazıdan net çıkmıyor; ilgili kare yok. -->

> **Ders sonrası not:** Hoca `numpy.linalg.solve`'un arka planda Cholesky yöntemini kullandığını söyledi. Ekrandaki sayfa ise çözücünün LU ayrıştırması yaptığını yazıyor ("Under the hood, the solver is actually doing a LU decomposition"). Sonuç ayrıca Cramer kuralıyla kesir olarak $x_1 = 53/24$, $x_2 = -31/12$, $x_3 = -11/60$ diye doğrulandı.

> **Ek bilgi (derste anlatılmadı):** SymPy'de `==` iki ifadenin matematiksel değil yapısal (yazılış) olarak aynı olup olmadığını sınar; bu yüzden $(x+1)^2$ ile $x^2+2x+1$ için `False` döner. Matematiksel eşitliği sınamak için büyük olasılıkla `simplify(a - b) == 0` ya da `a.equals(b)` kullanılır.

## 6. Jacobi ve Gauss-Seidel Yöntemlerinin Excel'de Karşılaştırılması

### 6.1 Sistemin düzenlenmesi

Aradan sonra hoca önceki derste görülen iki yinelemeli yaklaşım yöntemini (Jacobi ve Gauss-Seidel) basit bir soru üzerinde, hesap makinesiyle uğraşmamak için Excel'de çözdü (ekrandan, 01:05:00). Sistem:

$$x + 2y = 5, \qquad 3x + y = 5$$

Gerçek çözüm $x = 1$, $y = 2$'dir. Yöntem için önce denklemler köşegen baskın (diagonally dominant) olacak biçimde düzenlenir, sonra her denklemden bir değişken yalnız bırakılır. Bu düzende köşegen baskın değildir; denklemler yer değiştirilir:

$$3x + y = 5, \qquad x + 2y = 5$$

Artık köşegende en büyük katsayılar vardır. İlk denklemden $x = \frac{5 - y}{3}$, ikinciden $y = \frac{5 - x}{2}$ bulunur. Yineleme yapıldığı için indisler yazılır:

- İlk yöntem (Jacobi): $x_{i+1} = \dfrac{5 - y_i}{3}$, $y_{i+1} = \dfrac{5 - x_i}{2}$. İki değişken de önceki iterasyonun değerleriyle hesaplanır.
- İkinci yöntem (Gauss-Seidel): $x_{i+1} = \dfrac{5 - y_i}{3}$, $y_{i+1} = \dfrac{5 - x_{i+1}}{2}$. $y$ hesaplanırken o adımda bulunan yeni $x$ kullanılır; bu, sonuca daha hızlı götürür.

### 6.2 Jacobi tablosu

Başlangıç değerleri $x_0 = 0$, $y_0 = 0$ alındı. Excel'de `=(5-B3)/3` gibi formüllerle bir satır hesaplanıp aşağıya çekildi (ekrandan, 01:05:00 ve 01:10:00):

| İterasyon | $x$ | $y$ |
|---|---|---|
| 0 | 0 | 0 |
| 1 | 1.666667 | 2.5 |
| 2 | 0.833333 | 1.666667 |
| 3 | 1.111111 | 2.083333 |
| 4 | 0.972222 | 1.944444 |
| 5 | 1.018519 | 2.013889 |
| 6 | 0.99537 | 1.990741 |
| ... | ... | ... |
| 17 | 1 | 2 |

Değerler hep aynı yönde yaklaşmıyor; gerçek çözümün bir üstüne bir altına geçerek salınıyor. Hoca dört basamakla bakıldığında yaklaşık 18 iterasyonda $x = 1$, $y = 2$'nin bulunduğunu söyledi; tabloda altı basamakla $(1, 2)$ ilk kez 17. iterasyonda görünüyor. Bir kez $1$ ve $2$ bulunduktan sonra denklemler sağlandığı için değerler artık değişmez.

### 6.3 Gauss-Seidel tablosu

İkinci sütun çiftinde $y$ formülü bu kez aynı satırdaki yeni $x$'i kullanır (ekrandan, 01:10:00):

| İterasyon | $x$ | $y$ | $\Delta x$ |
|---|---|---|---|
| 0 | 0 | 0 | |
| 1 | 1.666667 | 1.666667 | 1.666667 |
| 2 | 1.111111 | 1.944444 | -0.555556 |
| 3 | 1.018519 | 1.990741 | -0.092593 |
| 4 | 1.003086 | 1.998457 | -0.015432 |
| 5 | 1.000514 | 1.999743 | -0.002572 |
| 6 | 1.000086 | 1.999957 | -0.000429 |
| 7 | 1.000014 | 1.999993 | $-7.14 \times 10^{-5}$ |
| 8 | 1.000002 | 1.999999 | $-1.19 \times 10^{-5}$ |
| 9 | 1 | 2 | $-1.98 \times 10^{-6}$ |
| 10 | 1 | 2 | $-3.31 \times 10^{-7}$ |
| 11 | 1 | 2 | $-5.51 \times 10^{-8}$ |

Sonuç yaklaşık 9. iterasyonda, yani Jacobi'nin neredeyse yarısında bulundu. Tablolar python ile yeniden hesaplandı ve ekrandaki değerlerle örtüştü.

Hoca kodda kullanılacak durdurma ölçütünü göstermek için ardışık kökler arasındaki değişimi ($\Delta x$) de ekledi. Önce mutlak değer fonksiyonuyla yazmayı denedi, Excel hata verince basitçe yeni değerden eski değeri çıkardı. Farkın hızla çok küçük değerlere indiği görülüyor. Excel yuvarlama yaptığı için son satırlardaki çok küçük farklar ekranda bilimsel gösterimle çıkıyor. Hoca mutlak değerin Excel'de zor ama kodda çok kolay alındığını söyledi.

**Soru:** Mutlak değer (`abs`) Excel'de mi, kodda mı kullanılacak? **Cevap:** C kodunda da kullanılabilir; bunun ayrıntısı kodlama kısmında anlatıldı (bkz. Bölüm 7).

### 6.4 Köşegen baskınlık sağlanmazsa

Hoca öğrencilere köşegen baskın olmayan düzeni de denemelerini önerdi: bazen sonuca gidilir, bazen gidilmez. Sonra bunu kendisi denedi. Denklemlerin ilk verilişine göre $x = 5 - 2y$, $y = 5 - 3x$ yazılır:

| İterasyon | $x$ | $y$ |
|---|---|---|
| 0 | 0 | 0 |
| 1 | 5 | 5 |
| 2 | -5 | -10 |
| 3 | 25 | 20 |
| 4 | -35 | -70 |

Değerler çözümden giderek uzaklaşır, yani yöntem ıraksar: basit bir sistem bile çözülemez. Bu tablonun ilk satırı ($5$, $5$) derste görüldü; sonraki satırlar python ile hesaplandı.

> **Hocanın vurgusu:** Köşegen baskınlığın faydası şudur: köşegendeki en büyük katsayı paydaya gelir, örneğin $\frac{1}{2}$ ya da $\frac{1}{3}$ çarpanı gibi düşünülebilir. Payda ne kadar büyükse kesrin değeri o kadar küçülür ve yineleme çok daha rahat sonuca gider. Kural sağlandığında yakınsama görülür.

## 7. Sayısal Yöntemleri C ile Kodlarken Dikkat Edilecekler

Dersin son kısmında hoca dönem projesi vesilesiyle sayısal yöntemleri C'de kodlarken dikkat edilecek programlama ilkelerini anlattı. Bu bölümde bunların akademik ve programlama tarafı aktarılmıştır.

### 7.1 Modüler yapı ve yardımcı fonksiyonlar

Her yöntem (ikiye bölme, Regula Falsi, Newton-Raphson, matris tersi, Gauss eliminasyonu, Gauss-Seidel, sayısal türev vb.) ayrı bir fonksiyon olarak yazılmalıdır; bütün kodun tek bir `main` içinde olması istenmez. Polinom değeri hesaplama (polynomial evaluation) hemen her yöntemin ortak ihtiyacıdır: sayısal türevde $f(x_{i+1})$, $f(x_i)$ ve $f(x_{i-1})$'i aynı fonksiyon hesaplar. Bu yüzden ayrı bir yardımcı (auxiliary) fonksiyon yazılıp diğer fonksiyonlardan çağrılmalı, kod tekrarı olmamalıdır.

Matematik kütüphanesindeki (`math.h`) `sin`, kare kök, mutlak değer gibi fonksiyonlar kullanılabilir; örneğin fonksiyonda $\sin^2 x$ gibi bir terim varsa sinüs için ayrıca fonksiyon yazmaya gerek yoktur. Ancak türev ya da integral hesaplayan hazır bir kütüphane kullanılmaz; sayısal türev ve integral derste görüldüğü şekliyle sıfırdan yazılmalıdır. Amaç yöntemleri yalnız kodlatmak değil, algoritma tasarlama ve programlama becerisini geliştirmektir.

Kodun ANSI C standardına uygun olması istenir. Hoca kendi kodlarında değişkenleri hep fonksiyonun başında tanımladığını gösterdi. `int i = 1` biçiminde, kodun ortasında yapılan tanımları C++ notasyonu olarak andı ve kendi derleyicisinin buna izin vermediğini, böyle bir kodun onda çalışmayacağını söyledi. Girinti, anlaşılabilirlik ve gerektiği yerde yorum satırı bu disiplinin parçasıdır. Hoca bu alışkanlığın sonraki programlama, veri yapıları ve algoritma analizi dersleri için de temel olduğunu söyledi.

### 7.2 Kullanıcı girdisi ve hata kontrolü

**Soru:** Matrisin tersini alırken bir satır tamamen sıfırsa determinant sıfır olur ve tersi yoktur; bunu baştan kontrol edip yazdırabilir miyiz, çok fazla `if` kullanmak kodu kötüleştirir mi? **Cevap:** Kötüleştirmez. Program kullanıcı dostu olmalıdır: matrisin tersi alınamıyorsa program kapanmamalı ya da sonsuz döngüye girmemeli, bu ilk kontrollerle kullanıcıya "matrisin tersi alınamaz" gibi bilgi verilmelidir. Menüde geçersiz bir seçim yapıldığında da program kapanmamalı, menü yeniden gelmelidir. Öncelik kodun doğru ve programın doğru çalışmasıdır, karmaşıklık ondan sonra gelir. $O(n^2)$'lik bir işi $O(n^3)$ ile yazmak kötüdür, ama $O(n^2)$'lik kodun başına ve sonuna denetim için `if` eklemek gereklidir.

**Soru:** Fonksiyonlar kullanıcıdan mı alınacak? **Cevap:** Evet, her türlü değer kullanıcıdan alınır. Ancak fonksiyon `x^3 + 7x^2` gibi bir metin (string) olarak alınmaz; polinom ise katsayıları bir diziye ya da matrise kaydedilerek modellenir. Metin olarak almak daha güzel olur ama ayrıştırma (parse) gerekir; işin içine sinüs, arksinüs, logaritma girince bu zorlaşır. Bu yüzden fonksiyonların modellenmesi önerildi.

Ekranda gösterilen örnek rapordaki program, yöntemleri numaralı bir menüden seçtiriyor ve ana menüde `0` girilene kadar çalışmaya devam ediyor (ekrandan, 01:35:00). İkiye bölme yöntemi için gereken parametreler başlangıç ve bitiş değerleri (kapalı yöntem), $\varepsilon$ hata miktarı ve en fazla iterasyon sayısıdır.

### 7.3 Durdurma koşulu

Hoca bunu "çok önemli bir detay" diye anlattı (ekrandan, 01:40:00). Örneğin bir `bisection` fonksiyonunda eski kök $x$, yeni kök $x_n$ ve hata $e$ değişkenleri olsun. Döngü içinde $e = |x_n - x|$ hesaplanır. Durdurma koşulu şöyle yazılırsa:

```text
while (e != 0.01) { ... }
```

algoritmik olarak doğru görünse de bu bir sonsuz döngüdür. Kayan noktalı sayılar 32 ya da 64 bitlik uzun gösterimlerdir; iki sayının farkı bit düzeyinde hiçbir zaman tam olarak $0.01$'e eşit olmayabilir. Doğrusu, farkın mutlak değerinin hata toleransının altına düşüp düşmediğini kontrol etmektir:

$$|x_{yeni} - x_{eski}| \le \varepsilon$$

Burada $\varepsilon$ sabit bir sayı yerine kullanıcıdan alınan bir değişken olabilir. Döngü bu koşul sağlanana kadar ya da en fazla iterasyon sayısına ulaşılana kadar döner.

> **Hocanın vurgusu:** Epsilon doğrudan eşitlikle karşılaştırılmamalıdır. İleride "kodum sonsuz döngüden çıkmıyor" diye karşılaşılacak sorunların bir sebebi budur. Kökün önceki hali ile mevcut hali arasındaki farkın mutlak değeri $\varepsilon$'dan küçük ya da eşit olana kadar döngü dönmelidir; bu en iyi durma koşuludur.

### 7.4 Yorum satırları, adlandırma ve kod düzeni

**Soru:** Çok fazla yorum satırı kullanmak sorun olur mu? **Cevap:** Her satıra ("burada döngü dönüyor", "burada karşılaştırma yapılıyor") yorum yazılmamalıdır. Bunun yerine fonksiyonun başına kısa bir özet yazılır: fonksiyon ne yapar, girdisi nedir, çıktısı nedir. Hoca örnek olarak şöyle bir açıklama yazdı: "Bu fonksiyon dizinin en büyük değerini bulur. Girdi: dizi ve boyutu. Çıktı: en büyük elemanın adresi." Çok kritik bir algoritma bölümü ya da kendi eklediğiniz özgün bir kısım varsa yalnız o bölgeye özel açıklama yapılabilir.

**Soru:** Kod yazarken değişken ve fonksiyon adları İngilizce mi olmalı? **Cevap:** İngilizce yazmak iyi olur, özellikle kod GitHub gibi yerlerde paylaşılacaksa. Önemli olan bir standart olmasıdır: hep İngilizce ya da hep Türkçe yazılmalıdır, İngilizce tavsiye edilir.

**Soru:** Fonksiyonları `main`'in üstüne yazmak ile altına yazmak arasındaki fark nedir? **Cevap:** Programın çalışması açısından fark yoktur. Okunabilirlik açısından, dosya açıldığında önce kütüphane tanımları, varsa `struct` ve `#define` tanımları, fonksiyon prototipleri, sonra `main` görülmelidir. Fonksiyonların gövdeleri (implementasyonları) `main`'den sonra gelir. İleride kod birden çok dosyaya da bölünecektir. Hoca bunu önceki kodlarından bir oy sayma (histogram) örneğiyle gösterdi: fonksiyon prototipleri en üstte, gövdeleri `main`'in altında (ekrandan, 01:25:00).

Özyinelemeli (recursive) fonksiyonlar bu yöntemlerde pek gerekmez; kullanılabilir ama dikkat edilmelidir. Hoca bunu bıçağa benzetti: her yerde kullanılmaz ve dikkatli kullanılması gerekir.

## 8. Polinomun struct ile Modellenmesi

Polinom fonksiyon için katsayılar dizisi ve dereceler dizisi (ya da bir matris) tutulabileceği daha önce söylenmişti. Hoca C'de bunun `struct` ile de yapılabileceğini gösterdi. `struct`, kendi değişken tipini tasarlamak gibidir.

Bir polinom terimlerden oluşur. Her terimin bir katsayısı (coefficient, `double`) ve bir üssü (exponent ya da power, `int`) vardır. Bu, `TERM` tipini verir. Bir polinomda $n$ tane terim olur; `POLY` tipi en fazla `MAX` terimlik bir terim dizisi ve kullanılan terim sayısı `n`'den oluşur. Hoca `MAX`'ı örneğin en fazla 15 terim olacak bir sabit diye tarif etti.

`main` içinde `POLY p;` ile normal bir değişken gibi bir polinom tanımlanır. Üyelerine nokta ile erişilir: `p.n = m;` ile terim sayısı atanır. `p.t[i].coef` $i$'inci terimin katsayısı, `p.t[i].exponent` üssüdür. Bunlar bir döngü içinde `scanf` ile kullanıcıdan alınır; katsayı `double` olduğu için `%lf`, üs için `%d` kullanılır ve adres gerektiği için `&` konur.

Hoca kodu önce $m = 5$ ile yazdı, denemek için $m = 3$'e indirdi. Terimleri yazdırırken ilk denemede sonda fazladan bir `+` çıktı. Bunu düzeltmek için döngü bir eksik ($p.n - 1$'e kadar) çalıştırılıp son terim döngüden sonra `+` olmadan yazdırıldı. Ayrıca döngü sınırı olarak `m` değil `p.n` kullanılmalıdır, çünkü terim sayısı kullanıcıdan da alınabilir. Ekrandaki kod (ekrandan, 01:45:00 ve 01:50:00):

```c
#include <stdio.h>
#define MAX 15   /* ekranda görünmüyor, eklendi */

typedef struct term{
    double coef;
    int exponent;
}TERM;
typedef struct poly{
    TERM t[MAX];
    int n;
}POLY;
int main(){
    int m=3;
    POLY p;
    int i;
    p.n=m;
    for(i=0;i<m;i++){
        scanf("%lf",&p.t[i].coef);
        scanf("%d",&p.t[i].exponent);
    }

    for(i=0;i<p.n-1;i++){
        printf("%lf X ^ %d +",p.t[i].coef,p.t[i].exponent);
    }
    printf("%lf X ^ %d",p.t[i].coef,p.t[i].exponent);
    return 0;
}
```

`#define MAX 15` satırı ve `return 0;` ekranda görünmüyor, ajan tarafından eklendi. Kod `gcc -Wall` ile uyarısız derlendi; derste kullanılan `3 2 4 1 6 0` girdisiyle çıktı `3.000000 X ^ 2 +4.000000 X ^ 1 +6.000000 X ^ 0` oldu.

Hoca bu yapının daha dinamik hale getirilebileceğini (sinüs, kosinüs, logaritma terimleri eklemek gibi) söyledi. Polinomu okuma ve polinomu değerlendirme işlerinin ayrı fonksiyonlara taşınması önerildi; laboratuvarın ilk uygulamasında yazılan polinom değerlendirme kodu bir fonksiyona çevrilerek kullanılabilir.

> **Ek bilgi (derste anlatılmadı):** Bu `POLY` yapısıyla polinom değerlendirme fonksiyonu, her terim için `coef * pow(x, exponent)` değerlerini toplayarak yazılabilir. Sayısal türev, ikiye bölme ve Newton-Raphson gibi yöntemler büyük olasılıkla bu tek yardımcı fonksiyonu çağırarak kurulur.

## Örnek Sorular

### Soru 1: Merkezi farklarla ikinci türev

(derste sözlü ve ekrandan, 00:23:04 ve 00:25:00)

$f(x) = x^3 - 8x^2$ fonksiyonunun ikinci türevinin $x = 4$'teki değerini $h = 0.1$ alarak merkezi farklar formülüyle bulun.

> **Çözüm (derste verilmedi):** Formül $f''(x_i) \approx \dfrac{f(x_i + h) - 2f(x_i) + f(x_i - h)}{h^2}$.
> - $f(4.1) = 68.921 - 134.48 = -65.559$
> - $f(4) = 64 - 128 = -64$
> - $f(3.9) = 59.319 - 121.68 = -62.361$
> - $f''(4) \approx \dfrac{-65.559 + 128 - 62.361}{0.01} = \dfrac{0.08}{0.01} = 8$
>
> Analitik olarak $f''(x) = 6x - 16$, $f''(4) = 8$. Sonuç tam çıkar, çünkü bu formülün kesme hatası dördüncü türevle orantılıdır ve kübik fonksiyonda dördüncü türev sıfırdır (python ile doğrulandı).

### Soru 2: Doğrusal sistemin çözümü

(ekrandan, 00:45:00)

Aşağıdaki sistemi çözün (kitapta `numpy.linalg.solve` ile çözdürülen "TRY IT" alıştırması):

$$4x_1 + 3x_2 - 5x_3 = 2, \qquad -2x_1 - 4x_2 + 5x_3 = 5, \qquad 8x_1 + 8x_2 = -3$$

Ekrandaki çözüm: $x = [2.20833333,\ -2.58333333,\ -0.18333333]$. Kesir olarak $x_1 = 53/24$, $x_2 = -31/12$, $x_3 = -11/60$ (Cramer kuralıyla doğrulandı).

### Soru 3: Jacobi ve Gauss-Seidel karşılaştırması

(ekrandan, 01:05:00 ve 01:10:00)

$x + 2y = 5$, $3x + y = 5$ sistemini $(0, 0)$ başlangıcıyla Jacobi ve Gauss-Seidel yöntemleriyle çözün; ayrıca köşegen baskın olmayan düzenle deneyin.

Derste verilen çözüm: Denklemler $3x + y = 5$, $x + 2y = 5$ diye yer değiştirilir. Jacobi $x_{i+1} = (5 - y_i)/3$, $y_{i+1} = (5 - x_i)/2$ ile yaklaşık 17-18 iterasyonda, Gauss-Seidel $y_{i+1} = (5 - x_{i+1})/2$ ile yaklaşık 9 iterasyonda $x = 1$, $y = 2$'ye ulaşır (tablolar Bölüm 6'dadır). Köşegen baskın olmayan $x = 5 - 2y$, $y = 5 - 3x$ düzeni ıraksar.

### Soru 4: Newton-Raphson örnek çıktısı

(ekrandan, 01:30:00)

Örnek rapordaki Newton-Raphson örneği: $f(x) = x^3 - 7x^2 + 14x - 6$, $x_0 = 0$, $\varepsilon = 0.000001$, en fazla 100 iterasyon. Ekranda ilk üç iterasyon görünüyor:

| İterasyon | $x_n$ | $x_{n+1}$ | $f(x_n)$ | $f'(x_n)$ |
|---|---|---|---|---|
| 1 | 0.000000 | 0.428571 | -6.000000 | 14.000000 |
| 2 | 0.428571 | 0.569724 | -1.206997 | 8.551020 |
| 3 | 0.569724 | 0.585592 | -0.111039 | 6.997622 |

> **Çözüm (derste verilmedi):** $f'(x) = 3x^2 - 14x + 14$ ve $x_{n+1} = x_n - f(x_n)/f'(x_n)$ ile devam edilirse 4. iterasyonda $x_5 = 0.585786$ bulunur ($f(x_4) = -0.001328$, $f'(x_4) = 6.830466$). 5. iterasyonda fark $\varepsilon$'un altına düşer ve kök $x \approx 0.585786$ olur. Bu değer $2 - \sqrt{2}$'dir. Ekrandaki ilk üç satır ve devamı python ile doğrulandı.

## Dersin Toparlaması

Bu derste sayısal türev konusu Taylor serisiyle genelleştirildi. Bir noktanın çevresindeki noktalar Taylor serisine açılır ve her türev bir bilinmeyen gibi ele alınır. Kaç bilinmeyen varsa o kadar denklem kurulur ve istenmeyen türevler denklemler birleştirilerek yok edilir. Bu yolla ileri farklarla birinci ve ikinci türev, merkezi farklarla ikinci türev ve beş noktalı merkezi farklarla üçüncü türev formülleri elde edildi. Ardından sayısal yöntemleri denemek için Python araçları (Matplotlib, SymPy, NumPy) tanıtıldı.

İkinci kısımda önceki derste anlatılan Jacobi ve Gauss-Seidel yöntemleri basit bir iki bilinmeyenli sistemde Excel ile karşılaştırıldı. Gauss-Seidel yaklaşık yarı sayıda iterasyonla yakınsadı, köşegen baskınlık sağlanmadığında yöntem ıraksadı. Son olarak bu yöntemleri C'de kodlarken gereken ilkeler anlatıldı: modüler fonksiyonlar ve ortak bir fonksiyon değerlendirme fonksiyonu, kayan noktalı sayılarda $|x_{yeni} - x_{eski}| \le \varepsilon$ biçimli durdurma koşulu, kullanıcı girdisi denetimi, fonksiyon başına kısa açıklama ve polinomun `struct` ile modellenmesi. Sayısal integral konusuna bir sonraki derslerde geçilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
