# Ders 5 Çalışma Özeti

## Genel Konular

- Düşüm algoritmalarının genel yapısı
  - Hata fonksiyonunu en küçük yapan parametreleri bulmak için optimizasyon ve arama algoritmalarında kullanılan düşüm yöntemleri kullanılır. Ters yönde uygulandığında aynı mantık maksimum bulmak için de kullanılabilir; derste yapay sinir ağının çıkışındaki hata küçültülmek istendiği için minimizasyon üzerinden gidilir.
  - Genel şema (ekrandan, 00:05:00): tahmini bir $x_0$ noktası ile başla; durma kriteri sağlanana kadar düşüm yönünü belirle, adımı belirle, güncelle (update et).
  - $x_0$, bulunmaya çalışılan bütün parametreleri içeren vektörel bir değişkendir. Fonksiyonun yapısı hakkında bilgi olmadığından başlangıç noktası rastgele seçilir.
  - Durma koşullarına ek olarak bir epoch (en çok iterasyon) sayısı konur; yanlış bir yöntem seçildiğinde ya da hesaplama süresi kısıtlı olduğunda algoritmanın sonsuz döngüye girmesini önler.
- Durma kriterleri (ekrandan, 00:15:00 ve 00:20:00)
  - İdealde hatanın yeterince küçük olması, $\|e_k\| < \delta_1$, ya da fonksiyonun o anki değerinin minimuma çok yakın olması, $f(x_k) - f(x^*) < \delta_2$. Ancak $x^*$ ve $f(x^*)$ bilinmediği için ikincisi pratikte kullanılamaz.
  - Bunun yerine yaklaşık değerler kullanılır: $\|x_{k+1} - x_k\| < \epsilon_1$ veya $f(x_k) - f(x_{k+1}) < \epsilon_2$. Bu koşulların sağlanması hatanın kesin küçük olduğu anlamına gelmez; fonksiyon bir düzlüğe girmiş de olabilir.
  - Ardışık iki fonksiyon değerinin farkı türev tanımının payı gibidir; bu fark küçülüyorsa türev sıfıra, yani bir minimuma yaklaşılıyor demektir.
  - Diğer tip yakınsama kriteri: $\|f'(x_k)\| < \epsilon_3$. Pek çok düşüm yönteminin gerçeklenmesinde kullanılır.
  - İkinci türev hesaplanabiliyorsa Hessian'a bakılabilir: minimumda $f'(x^*) = 0$ ve $H^* = f''(x^*)$ kesin ya da yarı kesin pozitiftir. Durma koşulu $f(x_k) - f(x^*) \cong \tfrac{1}{2}(x_k - x^*)^T H^* (x_k - x^*) < \epsilon_4$ biçimindedir; pratikte $x_k - x^*$ yerine $x_{k+1} - x_k$, $H^*$ yerine $H_k = f''(x_k)$ kullanılır.
  - Birden çok kriter bir arada uygulanabilir; $\epsilon$ değerleri uygulamaya göre seçilir.
- Düşüm yönü ve en dik (mutlak) düşüm
  - Taylor açılımının ilk iki terimi $f(x + \alpha h) \approx f(x) + \alpha h^T f'(x)$ olarak yazılır. Fonksiyonun küçülmesi için ikinci terimin negatif olması gerekir.
  - $-f'(x)$ vektörü düşüm uzayını gösterir; $h$, $x$'ten bir düşüm yönüdür ancak ve ancak $h^T f'(x) < 0$ (ekrandan, 00:25:00).
  - $h$ ile $-f'(x)$ arasındaki açı: $\cos\theta = \dfrac{-h^T f'(x)}{\|h\|\,\|f'(x)\|}$ (ekrandan, 00:25:00).
  - Mutlak düşüm yöntemi, tüm $k$ için ve $k$'dan bağımsız bir $\mu > 0$ ile $\theta < \frac{\pi}{2} - \mu$ koşulunu sağlayan $h_k$ arama yönlerine sahiptir. Global yakınsama için $\mu$ tüm adımlarda sabit olmalıdır (ekrandan, 00:25:00).
- En dik gradyan düşüm (steepest descent) sayısal örneği
  - $f(x) = 2x_1^2 + x_1x_2 + x_2^2$, $x^0 = [0{,}5;\ 1]^T$, $\epsilon_1 = 0{,}1$ (gradyan normu için), $\epsilon_2 = 0{,}15$ ($\|x^{k+1} - x^k\|$ ve $|f(x^{k+1}) - f(x^k)|$ için), en çok iterasyon $M = 10$ (ekrandan, 00:30:00).
  - Gradyan $\nabla f(x) = [4x_1 + x_2;\ x_1 + 2x_2]^T$; $\nabla f(x^0) = [3;\ 2{,}5]^T$ (ekrandan, 00:35:00).
  - Adım uzunluğu $\ell(t_k) = f(x^k - t_k \nabla f(x^k))$ fonksiyonunun türevi sıfıra eşitlenerek bulunur; ilk adımda $t_0^* = 0{,}24$, yeni nokta $x^1 = [-0{,}22;\ 0{,}4]^T$ (ekrandan, 00:40:00).
  - İkinci adımda $d^1 = [0{,}48;\ -0{,}58]^T$, $t_1^* = 0{,}546$ ve $x^2 = [0{,}04;\ 0{,}08]^T$; $\|x^2 - x^1\| = 0{,}41$ ve $|f(x^2) - f(x^1)| = 0{,}156$, ikisi de $0{,}15$'ten büyük olduğu için iterasyon sürer (ekrandan, 00:45:00).
- Adım miktarı ile öğrenme oranı (learning rate) ilişkisi
  - İkisi aynı amaca hizmet eder: ne kadar uzağa gidileceğini söyler. Öğrenme oranı çoğunlukla sabittir; burada hesaplanan adım miktarı her iterasyonda farklı çıkar.
  - Adım miktarını her adımda $\ell$ fonksiyonunu küçülterek hesaplamak işlem gerektirdiği için pratikte sabit öğrenme oranı kullanmak daha kullanışlı bulunmuştur. Değişken öğrenme oranı (öğrenme hızlanınca azaltma, yavaşlayınca artırma) bu mantığa daha yakındır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Değişkenler vektöreldir
  - Hoca, $x_0$'ın tek bir sayı değil, bulunmaya çalışılan bütün parametreleri içeren vektör olduğunu, artık hep çok boyutlu şeylerden söz edildiğini özellikle hatırlattı.
- Gradyan düşüm garantili ama yavaştır
  - Gradyanın tersi yönünde gitmek fonksiyonu her zaman azaltır; bir minimum varsa (yerel de olsa) yöntem eninde sonunda oraya ulaştırır. Dezavantajı adımların küçük olması ve yavaş ilerlemesidir. Bu yüzden çok yaygın kullanılır.
- Yerel minimumla yetinilir
  - Ulaşılan minimumun global olup olmadığı rastgele seçilen başlangıç noktasına bağlıdır. Yerel minimumları geçip aramaya devam etmek uzun sürdüğü için genelde değmez.
- Geri yayılım ile bağlantı
  - Gradyan düşüm mantığı ilerleyen derslerde geri yayılım (backpropagation) algoritmasında kullanılacaktır; bu küçük boyutlu örnek, gradyan ve Hessian'ın nasıl hesaplandığını görmek için önemlidir.
- $\ell$ fonksiyonunu kurmak
  - Hoca, adım uzunluğu fonksiyonunu kurup çözerken izlerken anlaşılmış gibi göründüğünü ama kendi başına yapmaya çalışınca zorlanıldığını söyledi; gradyan ve norm hesabını bir kez elle yapmanın önemini vurguladı.

## Kısa Tekrar Notları

- Düşüm algoritması: başla, yön belirle, adım belirle, güncelle, durma kriterine bak.
- Pratik durma kriterleri: $\|x_{k+1} - x_k\| < \epsilon_1$, $|f(x_k) - f(x_{k+1})| < \epsilon_2$, $\|f'(x_k)\| < \epsilon_3$, en çok iterasyon $M$.
- Hessian kesin pozitif ise minimum; gradyan düşüm yalnız birinci türeve, Newton yöntemi ikinci türeve de bakar.
- $h$ düşüm yönüdür $\Leftrightarrow h^T f'(x) < 0$; en dik düşüm yönü $d^k = -\nabla f(x^k)$.
- Güncelleme: $x^{k+1} = x^k + t_k^* d^k$, $t_k^*$ değeri $\ell(t) = f(x^k + t\, d^k)$ fonksiyonunun minimumundan bulunur.
- Örnekte $x^0 = [0{,}5;\ 1]^T \to x^1 = [-0{,}22;\ 0{,}4]^T \to x^2 = [0{,}04;\ 0{,}08]^T$.
- Öğrenme oranı, adım miktarının sabit tutulmuş pratik karşılığıdır.

## Detaylı Açıklamalar

- Düşüm algoritmalarının mantığı
  - Elimizde bir hata fonksiyonu ve bilinmeyen katsayılar vardır. Fonksiyonun minimumunun nerede olduğu gözle anlaşılamadığından tanım uzayından rastgele bir $x_0$ ile başlanır. Bu noktanın minimum olma olasılığı neredeyse yoktur; türevle kontrol edilir, yerel minimum değilse yeni nokta seçilir. Yeni nokta artık rastgele değil, türevin gösterdiği yönde (gradyanın tersi) ve belirlenen bir adım uzaklığında seçilir. Yeni noktada türev yine hesaplanır ve durma koşulları sağlanana ya da epoch sayısına ulaşılana kadar devam edilir. Gradyan düşüm ve diğer yöntemlerin hepsinde yapı aynıdır.
- Durma kriterlerinin türev ile ilişkisi
  - Türev tanımı $f'(x) = \lim_{h \to 0} \frac{f(x+h) - f(x)}{h}$ biçimindedir (ekrandan, 00:15:00). Ardışık iki iterasyondaki $f(x_k) - f(x_{k+1})$ farkı bu formülün payına benzer. Pay küçülüyorsa türev sıfıra yaklaşır ve minimuma yaklaşılmış olur; tam sıfır olmasa da çok küçükse durma kararı verilebilir. Hata için bir sınır da konabilir: probleme göre örneğin yüzde 10 hata yeterli görülüyorsa hata bu değerin altına inince durulur. Yalnız fonksiyon değerindeki değişime bakmak tek başına doğru değildir, çünkü algoritma minimumla ilgisi olmayan bir düzlükte dolaşıyor olabilir.
  - Ardışık hataların değişimine bakılarak algoritmanın doğrusal, süperlineer ya da kuadratik yakınsama gösterdiği de belirlenebilir.
- Taylor açılımı ve gradyan düşümün gerekçesi
  - $f(x + \alpha h) \approx f(x) + \alpha h^T f'(x)$ yazıldığında fonksiyonun küçülmesi için $\alpha h^T f'(x)$ teriminin negatif olması gerekir. Türevin pozitif olduğu yön fonksiyonun arttığı yönü, negatif olduğu yön azaldığı yönü gösterir. Bu yüzden gradyanın negatifi yönünde gitmek her zaman fonksiyonu azaltır; Taylor serisi bunun bir tür matematiksel kanıtıdır.
  - Mutlak düşüm koşulundaki açı kontrolü bir çıkarımdır; algoritma normalde böyle bir kontrol yapmaz, amacı yerel de olsa bir minimum bulmaktır.
- Örneğin ilk iterasyonu (ekrandan, 00:30:00 - 00:40:00)
  - Gradyanın normu $\|\nabla f(x^0)\| = \sqrt{3^2 + 2{,}5^2} = \sqrt{15{,}25} \approx 3{,}905 > 0{,}1$; $k = 0 < M$. Durma koşulları sağlanmadığından arama yönü $d^0 = -\nabla f(x^0) = [-3;\ -2{,}5]^T$ alınır.
  - Yeni noktanın bileşenleri $x_1 = 0{,}5 - 3t_0$, $x_2 = 1 - 2{,}5t_0$ olarak $f$'e konur: $\ell(t_0) = 2(0{,}5 - 3t_0)^2 + (0{,}5 - 3t_0)(1 - 2{,}5t_0) + (1 - 2{,}5t_0)^2$. Türev sıfıra eşitlenip $t_0^* = 0{,}24$ bulunur.
  - $x^1 = x^0 + t_0^* d^0 = [0{,}5 - 0{,}72;\ 1 - 0{,}6]^T = [-0{,}22;\ 0{,}4]^T$. Fark vektörü $[-0{,}72;\ -0{,}6]^T$, normu yaklaşık $0{,}94 > 0{,}15$; fonksiyon değerleri $f(x^0) = 2$, $f(x^1) \approx 0{,}169$, fark da $0{,}15$'ten büyük. Algoritma sürer.
  - Ders sonrası not: Slayttaki türev ifadesi $-15{,}25 + 63{,}25\,t_0$ olarak yazılmıştı (ekrandan, 00:40:00). Python ile açılım yapıldığında doğrusu $\frac{d\ell}{dt_0} = -15{,}25 + 63{,}5\,t_0$ ve $t_0^* \approx 0{,}2402$ çıkar; yuvarlanmış sonuç $0{,}24$ değişmez.
  - Ders sonrası not: Hoca sözlü anlatımda gradyanın ikinci bileşenini bir yerde "üç" dedi; slayttaki doğru değer $2{,}5$'tir. Yeni noktayı da "0,22; 0,4" diye okudu; slaytta ilk bileşen $-0{,}22$'dir.
- İkinci iterasyon (ekrandan, 00:45:00)
  - $\nabla f(x^1) = [4(-0{,}22) + 0{,}4;\ -0{,}22 + 0{,}8]^T = [-0{,}48;\ 0{,}58]^T$, normu yaklaşık $0{,}75 > 0{,}1$. Arama yönü $d^1 = [0{,}48;\ -0{,}58]^T$, adım $t_1^* = 0{,}546$.
  - $x^2 = x^1 + t_1^* d^1 = [0{,}04;\ 0{,}08]^T$. $\|x^2 - x^1\| = 0{,}41 > 0{,}15$ ve $|f(x^2) - f(x^1)| = 0{,}156 > 0{,}15$; koşullar sağlanmadığı için $k = 2$ ile sonraki iterasyona geçilir. Değerler python ile doğrulandı.
- Adım miktarı ve öğrenme oranı
  - Bir öğrenci sorusu üzerine hoca, adım miktarı ile öğrenme oranının birebir aynı olmadığını ama birbirinden türetildiğini anlattı. Öğrenme oranı $0{,}1$ seçilmişse her adımda o kadar gidilir; hesaplanan adım miktarı ise bazen yavaşlayan bazen hızlanan bir büyüklüktür. Değişken öğrenme oranı aynı mekanizmanın sezgisel karşılığıdır; burada anlatılan, matematiksel olarak daha doğru sürümüdür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
