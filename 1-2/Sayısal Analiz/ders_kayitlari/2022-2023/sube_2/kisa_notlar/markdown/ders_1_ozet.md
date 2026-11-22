# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin amacı ve yaklaşımı
  - Sayısal analiz (numerical analysis, numerical methods, sayısal yöntemler) mühendislik, işletme, finans gibi pek çok bölümde okutulan bir derstir.
  - Bu derste yöntemlere bilgisayar mühendisi gözüyle bakılır: amaç, bir yöntemi herhangi bir programlama dilinde (özellikle C'de) nasıl iyi kodlayacağımızı öğrenmektir. Ders, yapısal programlama dersini destekleyecek biçimde tasarlanmıştır.
  - Gereken matematik lise seviyesindedir: biraz lineer cebir, basit türev ve integral, limit, trigonometri ve logaritma kuralları. Zor problemler döngüler, `if` yapıları ve iterasyonlarla yaklaşık olarak çözülür.
  - Kaynaklar (ekrandan, 00:05:00): John H. Mathews, *Numerical Methods for Mathematics, Science and Engineering* (Prentice Hall) ve John R. Rice, *Numerical Methods, Software and Analysis* (McGraw Hill). Konu sonlarındaki örnek sorular çalışmak için önerilir.
  - Ders işleyişi: bazı kavramlar slaytla hızlıca aktarılır, algoritmalar ise grafik tablette adım adım izlenir (trace edilir). Dönem projesinde derste anlatılan yöntemler kodlanır.
- Dersin konu başlıkları (ekrandan, 00:15:00 ve 00:20:00)
  - Sayısal analizin tanımı, hata kavramı ve hata türleri.
  - Doğrusal olmayan denklemlerin çözümü (kök bulma): fonksiyonun sıfırı kestiği noktaları bulmak. Bu bölümde altı algoritma anlatılacağı söylendi.
  - Sayısal integral: integrali analitik alınamayan fonksiyonlar için belirli aralıkta yaklaşık alan bulmak.
  - Sayısal türev: türevi zor alınan bir fonksiyonun bir noktadaki türev değerini yaklaşık hesaplamak.
  - Optimizasyon: yerel/global minimum ve maksimumların bulunması.
  - Matrisler: matris tanımı, alt/üst üçgen, birim, köşegen, bant matris; transpoz, determinant, ters alma.
  - Doğrusal sistemlerin çözümü
    - Dolaysız (direct) yöntemler: Cramer, Gauss eliminasyon, Gauss-Jordan eliminasyon, yoğunlaştırılmış yok etme (compact elimination) / Cholesky.
    - Dolaylı (indirect) yöntemler: Jacobi iterasyonu ve Gauss-Seidel.
  - Doğrusal olmayan denklem takımlarının çözümü ve sonlu farklar.
  - Eğri uydurma
    - Enterpolasyon: Gregory-Newton ve Lagrange enterpolasyon formülleri.
    - Regresyon: en küçük kareler yaklaşımı; en küçük karelerde polinom, lineer olmayan (üstel) ve trigonometrik fonksiyonların kullanımı.
  - Adi diferansiyel denklemler: zaman kalırsa Runge-Kutta yöntemine kısaca değinilebileceği söylendi.
- Analitik ve sayısal çözüm (ekrandan, 00:40:00)
  - Analitik (teori): sonuçlar süreklidir, çözüm matematiksel fonksiyon olarak elde edilir, karışık olmayan problemlerde kullanılır, tek ve kesin sonuç verir.
  - Sayısal (deneysel): sonuçlar kesiklidir ve daima sayıdır; analitik çözümü olmayan (karışık) problemlerde kullanılır; iteratif yaklaşık çözüm üretir, hassasiyet adım sayısı artırılarak sağlanır; sonuç bulunduğunda hata analizi yapılır.
- Sayıların gösterimi
  - Taban 10, 2, 8 ve 16 sistemleri; ikilik ile onaltılık arası dönüşüm; onaltılık toplama ve çıkarma.
  - Anlamlı basamak, ondalık basamak (decimal place), kayan nokta (floating point) gösterimi, kesme (truncation) ve yuvarlama (rounding).
- Doğruluk (accuracy) ve hassasiyet (precision)
- Hata (error) ve yanlış (mistake) farkı; kayan noktalı sayıların eşitlikle karşılaştırılması sorunu.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sayısal analizin tanımı (ekrandan, 00:45:00)
  - "Analitik çözümü mümkün olmayan denklemlerin sayısal denemeler ile yaklaşık çözümlerinin bulunmasına Sayısal Analiz denir."
  - $x^2-3x+2=0$ çarpanlarına ayrılır, $(x-2)(x-1)=0$, kökler $x=2$ ve $x=1$: analitik çözümü vardır. $x^2-5x\cos x+e^x=0$ için ise bilinenleri bir tarafa toplama ya da sadeleştirme işe yaramaz; yaklaşık çözüm gerekir.
- İşaret değişimi ile kök arama
  - Sürekli bir fonksiyon bir noktada negatif, diğerinde pozitif değer alıyorsa arada bir kök vardır. Aralık her adımda ikiye bölünerek köke yaklaşılır. Bu, ikiye bölme (bisection) yöntemidir ve programlamadaki ikili aramaya benzer.
  - Reel kök için grafiğin x eksenini kesmesi gerekir: $x^2$'nin kökü 0'dır, $x^2+2$'nin reel kökü yoktur (yalnız sanal kökü vardır).
- Bilgisayar hata yapmaz, programcı yapar
  - Bilgisayar deterministiktir; aynı veriyle aynı sonucu üretir. Arıza başka, hata başkadır.
  - Kayan noktalı sayıları `==` ile karşılaştırmak yanlıştır; bitler tek tek karşılaştırıldığından ekranda 0.01 görünen bir değer bile 0.01 sabitine eşit çıkmayabilir. Bunun yerine fark küçük bir eşik değerle karşılaştırılır. Hoca bunun durdurma kriterlerinde sık karşılaşılacak bir sorun olduğunu söyledi.
- Hata mutlak değerle ölçülür
  - 2 beklenip 8 gelince de, 8 beklenip 2 gelince de hata 6'dır. İşaretli toplanırsa hatalar birbirini götürür; bu yüzden mutlak değer kullanılır.
- Sayısal yöntemler yaklaşımdır
  - Hassasiyet artırıldıkça gerçek çözüme çok yaklaşılır. Bilimin bir tanımı da "approximation to the truth", gerçeğe yaklaşmadır.

## Kısa Tekrar Notları

- Sayısal analiz: analitik çözümü olmayan ya da çok zor olan problemlere iteratif yaklaşık çözüm.
- Analitik çözüm sürekli ve kesindir; sayısal çözüm kesikli, yaklaşık ve daima bir sayıdır.
- Döngü sayısı belliyse `for`, çözüme ne zaman ulaşılacağı belli değilse hassasiyet kriterli `while` kullanılır.
- $(01000001)_2 = 2^6 + 2^0 = 65$ (büyük A harfinin kodu).
- İkilikten onaltılığa: en düşük anlamlı bitten (LSB) başlayarak dörderli gruplanır ($2^4=16$); sekizliğe geçerken üçerli gruplanır.
- $(1110\,0001)_2 = (E1)_{16}$; $(C8)_{16} = (1100\,1000)_2$.
- Onaltılık: $4AF + 322 = 7D1$; $522 - 4AF = 73$.
- Taban büyüdükçe yazı kısalır ama sembol sayısı artar ve anlaşılırlık düşer.
- Kayan nokta: $m \cdot b^e$ (mantis, taban, üs); $156{,}78 = 0{,}15678 \times 10^3$.
- Kesme (truncation) fazla basamakları atar; yuvarlama (rounding) atılan ilk basamağa bakar: $\pi$ dört ondalıkla kesilirse $3{,}1415$, yuvarlanırsa $3{,}1416$.
- Doğruluk: ölçümün gerçek değere yakınlığı. Hassasiyet: ölçümlerin birbirine yakınlığı (kümelenmesi).
- Hata: $\text{error} = |X_g - X_h|$. Yanlış: dijitlerin yer değiştirmesi, tekrar eden dijitin yanlış okunması, tablo satır/sütununun ya da ondalık noktanın yanlış okunması.
- Kayan noktalı sayılarda `a == 0.01` yerine `fabs(a - 0.01) <= eşik` biçiminde karşılaştırma yapılır.

## Detaylı Açıklamalar

- **Neden sayısal yöntem?** Bilgisayarın hızı ve kapasitesi, insanın uzun sürede yapacağı hesapları makul sürede yapmayı sağlar. Bir köprünün davranışı ya da bir makinenin giriş-çıkış ilişkisi gibi fiziksel sistemler matematiksel eşitliklerle (denklem, diferansiyel denklem, integral vb.) ifade edilir. Ara adımlardan biri analitik olarak çözülemiyorsa sayısal yöntem devreye girer. Hoca, eskiden hazır programların denklemi sembolik olarak alamadığını, günümüzde bazı dillerin sembolik türev ve analitik çözüm yapabildiğini de belirtti. Sayısal yöntemler üniversite seviyesindeki matematik problemlerini lise seviyesindeki cebirsel işlemlere indirger.
- **Analitik ve sayısal türev örneği.** $f(x)=x^2-3x+2$ için $f'(x)=2x-3$; türev sıfıra eşitlenince tepe noktası $x=1{,}5$, $f(1{,}5)=-0{,}25$ bulunur. Bu analitik olarak kolaydır. Ama yalnız bir $(x, y)$ tablosu verilmişse ve $x=1{,}5$ için $y$ ya da $y=0{,}8$'e karşılık gelen $x$ soruluyorsa önce verilerden bir fonksiyon üretmek gerekir. Bu bir enterpolasyon (ara değer tahmini) problemidir.
- **Fonksiyonların bilgisayarda modellenmesi.** Proje ve ödevlerde fonksiyonlar C'de modellenecektir. Bir polinom terimi bir katsayı ve bir dereceden oluşur; terimler dizi, matris ya da `struct` ile saklanabilir. Trigonometrik, üstel ve logaritmik fonksiyonlar da benzer biçimde modellenir; ardından kök bulma, türev ya da integral algoritması uygulanır.
- **Enterpolasyon ve regresyon.** Enterpolasyon, hatasız veri noktalarının arasında kalan ara noktaları belirlemek için kullanılır; tablo halinde verilen bilgiler için geçerlidir, eğri noktaların üzerinden geçer (ekrandan, 00:20:00). Hoca bunu resim büyütme örneğiyle gösterdi: bir resim yeniden boyutlandırılınca yeni piksellerin değerleri komşu piksellerden uydurulur; enterpolasyon ne kadar iyiyse büyütülmüş resim o kadar az bozulur. Regresyonda ise noktaları en iyi temsil eden, minimum hatalı bir doğru ya da eğri çizilir; eğri noktalardan geçmek zorunda değildir ve daha çok gelecek tahmini için kullanılır.
- **Diferansiyel denklem örneği.** $y' + 2x = 0$ ise $y' = -2x$, iki tarafın integrali alınınca $y = -x^2 + C$ olur (ekrandan, 00:25:00). $y'' + (y')^2 + 2x^2 = 0$ gibi bir denklemde ise bilinmeyen iki şey ($y'$ ve $y''$) ve tek denklem vardır; analitik yöntemler diferansiyel denklemler dersinde anlatılır. Ekrandaki slaytta yaklaşık çözümün temeli $\frac{dy}{dt} \approx \frac{\Delta y}{\Delta t} = f(t, y)$ ve $y_{i+1} = y_i + f(t_i, y_i)\,\Delta t$ olarak verilmiştir. En çok kullanılan yöntem Runge-Kutta'dır; dördüncü mertebe sürümü en az hatayla çözüme ulaşır.
- **İşaret değişimiyle kök arama örneği.** Hoca Desmos ile $x^2-5x\cos x+e^x$ benzeri bir fonksiyonu çizdirip dört kökü olduğunu gösterdi; $f(0)=1$ olduğunu söyledi. Sonra bir uçta negatif, diğer uçta pozitif değer görülen aralığı ikiye bölerek köke yaklaşmayı anlattı.
  <!-- BELİRSİZ: Desmos'ta çizilen fonksiyonun tam ifadesi karede görülmüyor; f(1) ve f(0,5) için söylenen değerler aşağıdaki hesapla uyuşmuyor. -->
  - Ders sonrası not: Fonksiyon büyük olasılıkla ekrandaki $x^2-5x\cos x+e^x$'tir; python ile hesaplanan kökleri yaklaşık $-3{,}836$, $-1{,}996$, $0{,}303$ ve $0{,}774$'tür. Bu fonksiyon için $f(1)\approx 1{,}017$ (pozitif) ve $f(0{,}5)\approx -0{,}295$ çıkar; hoca $f(1)$'in negatif, $f(0{,}5)$'in yaklaşık $-0{,}6$ olduğunu söyledi. Ayrıca $[0;\,0{,}5]$ aralığının orta noktası $0{,}75$ değil $0{,}25$'tir.
- **Onaltılık sistem ve dönüşümler.** Onaltılık sistemde 9'dan sonra A=10, B=11, C=12, D=13, E=14, F=15 sembolleri kullanılır. Gruplama LSB'den başlar. $1110\,0001$ için sağdaki grup $0001 = 1$, soldaki grup $1110 = 8+4+2 = 14 = E$, sonuç $(E1)_{16}$ (ekrandan, 00:55:00). Ters yönde her onaltılık basamak dört bite açılır: $C8 \rightarrow 1100\;1000$ (ekrandan, 01:10:00).
- **Onaltılık toplama ve çıkarma.** İlkokuldaki elde ve komşudan alma mantığı onluk yerine on altılık ile uygulanır. Toplama ve çıkarmanın adımları genişletilmiş nottadır.
- **Anlamlı basamak.** $2/3 = 0{,}6666\ldots$ beş anlamlı rakamla yuvarlanarak yazılır. Anlamlı basamaklar bir sayıya ne kadar güvenebileceğimizi gösterir. Hız göstergesi örneğinde ibre 40 ile 60 arasında 50'ye yakındır; yakından bakılınca 49 okunur, noktadan sonrası ise bu göstergeden okunamaz (ekrandan, 01:20:00).
- **Yöntemlerde basamak sayısı.** Örneğin başlangıç noktası $x_0=1{,}225$ alınıp virgülden sonra üç basamakla çalışılacaksa, ara sonuç $2{,}878654$ çıktığında yuvarlamayla $2{,}879$, kesmeyle $2{,}878$ olarak kullanılır.
- **Doğruluk ve hassasiyet.** Hedef tahtası benzetmesi: atışlar hem merkezden uzak hem dağınıksa doğruluk da hassasiyet de düşüktür; atışlar birbirine yakın ama yanlış bir noktada kümelenmişse hassasiyet vardır ama doğruluk yoktur. İdeal durum hem doğru hem hassas olandır.
- **Hata kaynakları.** Kayan noktalı işlemler (toplama, çarpma) ve bir değerin bir basamak eksik ya da fazla yazılması hataya yol açabilir; bu hata sonraki adımlara yayılarak sonucu değiştirir. Hata türleri sonraki derste anlatılacaktır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
