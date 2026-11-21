# Ders 7 Çalışma Özeti

## Genel Konular

- Rekabetçi yapay sinir ağlarına giriş
  - Rekabetçi ağlarda çıkışta "%90 şu, %10 bu" gibi kararsız bir sonuç istenmez; mutlaka bir kazanan seçilir. Bu yüzden daha çok kümeleme (clustering) için uygundur.
  - İki grup vardır: sabit ağırlıklı rekabetçi ağlar (MaxNet, Mexican Hat, Hamming Net) ve öğrenen yapılar (Kohonen SOM, LVQ, ters yayılım ağları) (ekrandan, 00:05:00).
  - Rekabetin en uç biçimi Winner Take All (WTA): yalnız bir nöron ya da bir küme kazanır. Mexican Hat daha genel bir rekabettir; kazanan belirginleşir ama diğerleri tümüyle sıfırlanmaz.
  - LVQ ve ters yayılım ağları haritalama (mapping) için geliştirildiğinden supervised, SOM girdi verisinin kümelenmesi için geliştirildiğinden unsupervised öğrenir (ekrandan, 00:10:00).
- Kümeleme ağının yapısı
  - Girdi vektörü $D$ bileşenli ise $D$ giriş nöronu, oluşturulmak istenen küme sayısı $M$ ise $M$ çıkış nöronu vardır. Hesaplamanın yapıldığı çıkış katmanına rekabetçi katman (competitive layer) denir.
  - Exemplar (representative, codebook) vektör: bir kümeyi temsil eden ağırlık vektörü. Genellikle kümedeki örneklerin ortalamasıdır.
  - Yeni örnek bütün exemplar vektörlerle kıyaslanır, en yakın kümeye atanır, yalnız o kümenin ağırlığı güncellenir.
- Kohonen öğrenme kuralı ve yakınlık ölçütleri
  - Ağırlık vektörü giriş vektörüne en yakın birim öğrenir: $w_{.j}(new) = w_{.j}(old) + \alpha[x - w_{.j}(old)] = \alpha x + (1-\alpha) w_{.j}(old)$ (ekrandan, 00:15:00).
  - Bu yapılarda $\alpha$ işlem boyunca azaltılır; çoğu zaman her epokta yarıya indirilir.
  - Öklid mesafesi: $\|x - x_i\| = \sqrt{(x - x_i)^t (x - x_i)}$. Açı (kosinüs benzerliği): $\cos\psi = \dfrac{x^t x_i}{\|x\|\|x_i\|}$ (ekrandan, 00:20:00).
  - Noktasal çarpımın büyük olması açının küçük, korelasyonun yüksek olduğu anlamına gelir.
- MaxNet
  - En büyük girişi olan düğümü seçen bir alt ağdır. Genellikle tek başına değil, başka bir ağın (perceptron, çok katmanlı ağ, kümeleme algoritması) sonunda karar mekanizması olarak kullanılır.
  - Tam bağlıdır; her nöronun kendine bağlantısı $1$, diğerlerine $-\epsilon$'dur. Ağırlık matrisi köşegeni $1$ olan simetrik bir matristir.
  - Başlangıç: $0 < \epsilon < \dfrac{1}{m}$, $a_j(0)$ = $A_j$ düğümünün girdisi; $w_{ij} = 1$ ($i = j$), $w_{ij} = -\epsilon$ ($i \neq j$) (ekrandan, 00:25:00).
  - Güncelleme: $a_j(new) = f\left[a_j(old) - \epsilon \sum_{k \neq j} a_k(old)\right]$; $f(x) = x$ ($x \geq 0$), $0$ (diğer durumda). Durma koşulu: yalnız bir birim sıfırdan farklı kalana kadar (ekrandan, 00:25:00).
- Mexican Hat
  - Her nöronun işbirlikçi (pozitif ağırlıklı) ve rekabetçi (negatif ağırlıklı) komşuları vardır; daha uzaktakilerle bağlantı yoktur. Dışarıdan bir başlangıç aktivasyonu ($s_i$, external aktivasyon) alır (ekrandan, 00:40:00).
  - $R_2$: birimin bağlı olduğu birim sayısı; $R_1$: pozitif bağlı olduğu birim sayısı, $R_1 < R_2$ (ekrandan, 01:05:00).
  - Net input: $x_i = C_1 \sum_{k=-R_1}^{R_1} x\_old_{i+k} + C_2 \sum_{k=-R_2}^{-R_1-1} x\_old_{i+k} + C_2 \sum_{k=R_1+1}^{R_2} x\_old_{i+k}$; $C_1 > 0$, $C_2 < 0$ (ekrandan, 01:10:00).
  - Aktivasyon üç parçalıdır: $x < 0$ ise $0$, $0 \leq x \leq x\_max$ ise $x$, $x > x\_max$ ise $x\_max$; yani $x_i = \min(x\_max, \max(0, x_i))$ (ekrandan, 01:10:00).
  - MaxNet'ten farklı olarak bir kazanan zorunlu değildir; bu yüzden $t\_max$ (maksimum iterasyon sayısı) ile durdurulur.
  - Belli epoktan sonra aktivasyonların grafiği Meksika şapkasına benzer; adı buradan gelir.
- Hamming ağı
  - Birkaç exemplar vektörden hangisinin $n$ bileşenli giriş vektörüne daha çok benzediğini bulan bir maksimum benzerlik sınıflandırıcısıdır. Exemplar vektörler ağırlık matrisini belirler (ekrandan, 01:20:00).
  - Benzerlik ölçüsü $n - H(x_1, x_2)$; iki bipolar vektör arasındaki Hamming mesafesi $d = n - a$ ($a$: aynı olan bit sayısı) (ekrandan, 01:20:00).
  - $w_{ij} = 0.5\, e_i(j)$, $b_j = 0.5 n$, $y\_in_j = b_j + \sum_i x_i w_{ij}$, $y_j(0) = y\_in_j$; en büyüğü MaxNet seçer (ekrandan, 01:25:00).
  - Exemplar vektörler bipolar kullanılır; $1/0$ kullanılırsa mesafe doğru hesaplanmaz.
- Kohonen SOM (Self-Organizing Map)
  - Teuvo Kohonen tarafından 1989'da geliştirilmiştir; topoloji koruma haritası olarak da adlandırılır ve küme birimleri arasında topolojik bir yapı bulur. Bu özellik beyinde görülür (ekrandan, 01:35:00).
  - Tek ya da iki boyutlu dizi halinde düzenlenmiş $m$ kümeleme birimi vardır; komşuluk doğrusal, kare ya da altıgen (hexagonal) gridle tanımlanabilir (ekrandan, 01:40:00).
  - Algoritma: $D(J) = \sum_i (w_{ij} - x_i)^2$ hesaplanır, $D(J)$'yi en küçük yapan $J$ bulunur, $J$ ve komşularının ağırlıkları $w_{ij}(new) = w_{ij}(old) + \alpha[x_i - w_{ij}(old)]$ ile güncellenir, learning rate ve komşuluk yarıçapı küçültülür (ekrandan, 01:45:00).
  - Durma: maksimum epok sayısı ya da ağırlıkların artık çok az değişmesi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Exemplar vektör kavramı
  - Rekabetçi ağlar için özellikle bilinmesi gereken terimdir. Unsupervised öğrenmede bile kümeyi temsil eden az sayıda etiketli veri gerekir; exemplar bunların ortalamasıyla kurulabilir.
- MaxNet'in kullanım yeri
  - Kendi başına çok anlamlı değildir; başka bir ağın verdiği kararsız sonucu netleştirmek için onun sonuna eklenir. Gözle bakınca seçilebilecek bir sonucu otomatikleştirir.
- Hamming ağında bipolar gösterim
  - Hamming mesafesinin doğru hesaplanması için exemplar vektörler bipolar alınmalıdır.
- SOM'da parametre seçimi
  - Komşuluk şekli, yarıçapı ve learning rate deneysel olarak ayarlanır ve başarıyı çok değiştirir. Geniş komşulukla başlayıp daraltmak genellikle daha iyidir.
- Learning rate'in azaltılması
  - Önceki ağlarda öğrenme katsayısı sabit tutuldu; rekabetçi ağlarda genellikle her epokta azaltılarak kullanılır.

## Kısa Tekrar Notları

- Rekabetçi ağ: mutlaka bir kazanan; kümelemeye uygun.
- Sabit ağırlıklı: MaxNet, Mexican Hat, Hamming. Öğrenen: SOM (unsupervised), LVQ ve ters yayılım (supervised).
- Kohonen kuralı: yalnız kazanan birimin ağırlığı $w(new) = w(old) + \alpha(x - w(old))$ ile güncellenir.
- Yakınlık: küçük Öklid mesafesi ya da büyük noktasal çarpım (küçük açı).
- MaxNet: $w_{ii} = 1$, $w_{ij} = -\epsilon$, $0 < \epsilon < 1/m$; tek pozitif nöron kalana kadar iterasyon.
- Mexican Hat: $R_1$ içinde pozitif ($C_1$), $R_1$ ile $R_2$ arasında negatif ($C_2$) bağlantı; aktivasyon $[0, x\_max]$ aralığına kırpılır; $t\_max$ ile durur.
- Hamming: $w_{ij} = 0.5 e_i(j)$, $b = n/2$; $y\_in$ = aynı bit sayısı; MaxNet ile seçim.
- SOM: $D(J)$ en küçük olan kazanır; kazanan ve topolojik komşuları güncellenir; $\alpha$ ve yarıçap küçültülür.

## Detaylı Açıklamalar

- MaxNet sayısal örneği (ekrandan, 00:30:00 ve 00:35:00)
  - Dört nöronlu MaxNet, $\epsilon = 0.2$; slaytta girdiler $a_1(0) = .2$, $a_2(0) = .4$, $a_3(0) = .4$, $a_4(0) = .8$ olarak yazılıdır.
  - $a_1(1) = f\{a_1(0) - \epsilon[a_2(0) + a_3(0) + a_4(0)]\} = f(0.2 - 0.2 \cdot (0.4 + 0.4 + 0.8)) = f(-0.12) = 0$. Birinci nöron ilk iterasyonda kaybeder.
  - Slayttaki iterasyon tablosu: $a(1) = (0, .08, .32, .56)$, $a(2) = (0, 0, .192, .48)$, $a(3) = (0, 0, .096, .442)$, $a(4) = (0, 0, .008, .422)$, $a(5) = (0, 0, 0, .421)$. Beşinci iterasyonda yalnız $A_4$ pozitif kalır; girdi 4. kümeye atanır.
  - Ders sonrası not: Slayttaki tablo $a_3(0) = .6$ için doğrudur (python ile kontrol edildi). Slaytta yazılı $a_3(0) = .4$ ile hesaplanırsa $a(1) = (0, .12, .12, .60)$ olur ve ikinci iterasyonda $A_4$ tek başına kalır. $a_1(1)$ hesabındaki $-0.12$ de $a_3(0) = .4$ ile yapılmıştır; $.6$ ile $-0.16$ çıkar, sonuç yine $0$'dır.
- Mexican Hat sayısal örneği (ekrandan, 01:15:00)
  - 7 nöron, $x\_max = 2$, $R_1 = 1$, $R_2 = 2$, $C_1 = 0.6$, $C_2 = -0.4$. Başlangıç: $(0, 0.5, 0.8, 1, 0.8, 0.5, 0)$.
  - Uçtaki nöronların bir tarafta komşusu olmadığı için denklemleri daha kısadır: $x_1 = 0.6 x\_old_1 + 0.6 x\_old_2 - 0.4 x\_old_3$, $x_3 = -0.4 x\_old_1 + 0.6 x\_old_2 + 0.6 x\_old_3 + 0.6 x\_old_4 - 0.4 x\_old_5$.
  - Birkaç iterasyonda ortadaki nöron yükselir, kenardakiler zayıflar. Alt sınır $0$'a kırpılmasaydı şapkanın negatif yan kısımları da oluşurdu.
  - Bir öğrencinin sorusu üzerine: çıktının şekli Gauss eğrisine benzer; görüntü işlemedeki Gauss filtresiyle bu anlamda ilişkilidir.
- Hamming ağı örneği (ekrandan, 01:30:00)
  - $e(1) = [1, -1, -1, -1]$, $e(2) = [-1, -1, -1, 1]$, $n = 4$, $m = 2$, $b = 2$.
  - Giriş $(1, 1, -1, -1)$ için $y\_in_1 = 2 + 1 = 3$, $y\_in_2 = 2 - 1 = 1$. Giriş $e(1)$ ile 1., 3. ve 4. bitte, $e(2)$ ile yalnız 3. bitte aynıdır; sonuç Hamming benzerliğidir. MaxNet $e(1)$'i seçer.
  - Diğer girişler için derste söylenen değerler: $(4, 2) \to Y_1$, $(2, 4) \to Y_2$, $(1, 3) \to Y_2$. <!-- BELİRSİZ: Bu üç giriş vektörü incelenen karelerde görünmüyor. -->
- SOM sayısal örneği (ekrandan, 01:50:00 ve 01:55:00)
  - $s(1) = (1,1,0,0)$, $s(2) = (0,0,0,1)$, $s(3) = (1,0,0,0)$, $s(4) = (0,0,1,1)$; $m = 2$; $\alpha = 0.6$, $\alpha(t+1) = 0.5\alpha(t)$; $R = 0$; başlangıç ağırlıkları sütunlar halinde $(.2, .6, .5, .9)$ ve $(.8, .4, .7, .3)$.
  - $s(1)$ için $D(1) = 1.86$, $D(2) = 0.98$; 2. küme kazanır ve 2. sütun $(.92, .76, .28, .12)$ olur. Sonra $s(2) \to$ 1. küme, $s(3) \to$ 2. küme, $s(4) \to$ 1. küme.
  - İkinci epokta $\alpha = 0.3$, güncelleme $w_{ij}(new) = 0.7 w_{ij}(old) + 0.3 x_i$.
  - 100. epoch sonunda ağırlıklar sütunlar halinde $(0, 0, .5, 1.0)$ ve $(1.0, 0.5, 0, 0)$.
  - Ders sonrası not: Hoca ve slayt ilk sütunun 1. ve 2. vektörlerin ortalaması olduğunu söyledi. Doğrusu: ilk sütun $s(2)$ ve $s(4)$'ün, ikinci sütun $s(1)$ ve $s(3)$'ün ortalamasıdır (derste de ilk epokta $s(2)$ ve $s(4)$ 1. kümeye düştü). Ayrıca $\alpha$ her epokta yarıya indirilirse ağırlıklar bu ortalamalara tam ulaşmaz, ilk sütun $(0.008, 0.025, 0.582, 0.996)$, ikinci sütun $(0.992, 0.414, 0.029, 0.012)$ civarında kalır (python ile kontrol edildi); tam ortalamalar daha yavaş azalan bir $\alpha$ ile elde edilir.
- SOM ile karakter kümeleme (ekrandan, 02:00:00)
  - Üç farklı fontla yazılmış 21 karakter deseni, 25 kümeleme birimi. Doğrusal yapıda ($R = 1$, kazanan $J$ ile $J \pm 1$ öğrenir) sonuç: 6: K2; 10: J1, J2, J3; 14: E1, E3; 16: K1, K3; 18: B1, B3, D1, D3; 20: C1, C2, C3; 22: D2; 23: B2, E2; 25: A1, A2, A3.
  - Topolojiye ve komşuluk çapına göre sonuç değişir; B ile D'nin bir kısmı karışmıştır.
- SOM ile gezgin satıcı problemi (ekrandan, 02:05:00)
  - $R = 0$, 100 epoch, $\alpha = 0.2$ ile oluşan tur A-J şehirlerini dolaşan bir yol çizer; iki şehre tam isabet olmamıştır ama çözüm bütün şehirleri gezecek şekilde oluşur.
  - SOM unsupervised olduğu için veri hazırlama derdi yoktur, ama parametre ayarı zordur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
