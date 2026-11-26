# Ders 5 Çalışma Özeti

## Genel Konular

- Temel sistemlerin tekrarı: türev alıcı ve integral alıcı
  - Sistem, giriş işaretini (veriyi) alıp çıkış işaretine dönüştüren bir yapıdır; matematiksel olarak bir fonksiyon gibi düşünülür. Derste çoğunlukla tek girişli, tek çıkışlı (SISO) sistemler kullanılır.
  - Girişi bir katsayıyla çarpan sistem: katsayı 1'den büyükse yükselteç (amplifier), 1'den küçükse zayıflatıcı (attenuator), negatifse tersleyici (inverter) olur.
  - Türev alıcı: $y(t) = x'(t)$; integral alıcı: $y(t) = \int_a^t x(\tau)\,d\tau$ ($a$ çoğunlukla $0$ ya da $-\infty$) (ekrandan, 00:20:00).
  - Ayrık zamanda türev, türevin tanımından elde edilir: $\dfrac{f(x+h)-f(x)}{(x+h)-x}$ oranında en küçük artım $h=1$ olduğundan birinci fark $x[n+1]-x[n]$ olur (ekrandan, 00:20:00).
  - İntegral alma ayrık zamanda kümülatif toplama karşılık gelir.
- Öteleme ve konvolüsyon sistemleri
  - Zamanda öteleme sistemi işareti belli bir süre ileri ya da geri alır ve yeni bir işaret üretir.
  - Konvolüsyon, küçük bir işaretin (filtre, çekirdek/kernel) büyük bir işaretin üzerinde kaydırılıp çarpılıp toplanmasıdır; benzerliğin yüksek olduğu yerlerde çıkış tepe (pik) yapar. Örnek: bir yüz görüntüsünde göz aramak.
- Çok girişli sistemler ve bağlantı biçimleri
  - Toplayıcı $y(t) = x_1(t) + x_2(t)$, fark sistemi $y(t) = x_1(t) - x_2(t)$, çarpıcı $y(t) = x_1(t)\,x_2(t)$ (ekrandan, 00:25:00).
  - Kaskat (seri) bağlantı bileşke fonksiyona, paralel bağlantı fonksiyonların toplamına benzer.
- Geri beslemeli (feedback) sistemler
  - $y = F(x - Gy)$: çıkış $G$ bloğundan geçirilip girişten çıkarılır (ekrandan, 00:30:00).
  - Hata (beklenen ile gözlenen çıkış farkı) sisteme geri yansıtılarak sistem eğitilir; regresyon, yapay sinir ağlarındaki geri yayılım (backpropagation), hava durumu tahmini bu mantığa benzetildi.
  - Başarım ölçütleri: accuracy (doğru eşleşme oranı), recall (gerçek pozitiflerin ne kadarının yakalandığı, örn. 300 hastadan 250'si bulunduysa $250/300$), precision (pozitif işaretlenenlerin ne kadarının gerçekten pozitif olduğu).
  - Geri beslemeli integral alıcı: integral alıcının girişi $x - ay$ olduğundan $\int^t (x(\tau) - a y(\tau))\,d\tau = y(t)$, yani $x - ay = y'$ (ekrandan, 00:35:00).
- Doğrusallık (linearity)
  - Homojenlik (çarpımsallık): $F(ax) = aF(x)$. Süperpozisyon (toplamsallık): $F(x+\tilde{x}) = F(x) + F(\tilde{x})$. İkisi birden sağlanırsa sistem doğrusaldır (ekrandan, 00:40:00).
  - Sözle: sistemden önce ya da sonra ölçeklemek ve toplamak aynı sonucu verir.
  - Örnek: $F(x) = x$ homojendir; $F(x) = (x+2)^2$ için $(ax+2)^2 = a^2x^2 + 4ax + 4 \neq a(x^2+4x+4)$, homojen değildir (ekrandan, 00:40:00).
  - Doğrusal sistem örnekleri: ölçekleme, türev, integral, kayan ortalama (running average), zamanda öteleme, konvolüsyon, modülatör $y(t) = x(t)\cos 2\pi f t$, örnekleyici. Doğrusal olmayan örnekler: kare alma, işaret dedektörü, karşılaştırıcı (comparator), nicemleyici, uyarlamalı filtreler.
- Bellek ve nedensellik
  - Belleksiz sistem: çıkış yalnız o anki girişe bağlıdır (ideal yükselteç, ideal dişli/kaldıraç) (ekrandan, 00:45:00).
  - Bellekli sistem: çıkış geçmiş ya da gelecek girişlere bağlıdır (kapasitör, bobin, yay, hareketli kütle). Örnek: $a_n = a_{n-5} + a_{n-3}$, Fibonacci bağıntısı.
  - Nedensel sistem: çıkış yalnız geçmiş ve o anki girişlere bağlıdır; gerçek fiziksel devreler ve mekanik sistemler nedenseldir (ekrandan, 00:45:00).
- Zamanla değişmezlik (time invariance)
  - Girişe uygulanan $t_0$ (ya da $k$) kadar gecikme çıkışı da aynı miktarda geciktiriyorsa sistem zamanla değişmezdir: $F\{x[n-k]\} = y[n-k]$.
- Kararlılık (BIBO)
  - $|x(t)| \le M_x < \infty$ olan her sınırlı giriş $|y(t)| \le M_y < \infty$ sınırlı çıkışını veriyorsa sistem BIBO kararlıdır (ekrandan, 00:50:00).
  - Derste asıl ilgilenilecek sınıf, doğrusal ve zamanla değişmeyen (LTI) sistemlerdir.
- Hız sabitleyici (cruise control) örneği
  - İstenen hız ile gerçek hız arasındaki hata bir katsayıyla çarpılıp sisteme geri verilir; pozitif hata gazı artırır, aşma (overshoot) ve altta kalma (undershoot) tekrarlanarak istenen hıza ulaşılır.
- Tersinir (invertible) sistemler
  - Çıkış ters sisteme verildiğinde giriş geri elde edilebiliyorsa sistem tersinirdir; sistemle tersinin bileşkesi birim (identity) operatördür. Fourier ve Laplace gibi dönüşümler için gereklidir.
- Diferansiyel denklemle tanımlanan sistemler
  - Doğrusal sabit katsayılı adi diferansiyel denklem (LCCODE): $a_n y^{(n)}(t) + \dots + a_1 y'(t) + a_0 y(t) = b_m x^{(m)}(t) + \dots + b_1 x'(t) + b_0 x(t)$; başlangıç koşulları $y^{(n-1)}(0), \dots, y'(0), y(0)$; $n$ sistemin mertebesi, $a_i, b_i$ katsayılardır (ekrandan, 00:55:00).
  - Basit örnekler: ölçekleme $y = ax$ ($a_0=1, b_0=a$), integral alıcı $y' = x$ ($a_1=1, b_0=1$), türev alıcı $y = x'$ ($a_0=1, b_1=1$), geri beslemeli integral alıcı $y' + ay = x$ ($a_1=1, a_0=a, b_0=1$) (ekrandan, 01:00:00).
  - RLC devresi: Kirchhoff gerilim yasasıyla $x - Li' - Ri - y = 0$, $i = Cy'$ konunca $LCy'' + RCy' + y = x$ (ekrandan, 01:05:00).
  - Kütle-yay-sönümleyici: $my'' = b(x-y)' + k(x-y)$, yani $my'' + by' + ky = bx' + kx$ (ekrandan, 01:10:00).
  - Denklemin mertebesi problemdeki değişimin derecesinden gelir: konumdan (yol) yola çıkılıp ivmenin değişimine kadar gidilecekse üçüncü mertebe türev gerekir.
- Ayrık zamanlı sistemler
  - Girişler ve çıkışlar ayrık zamanlıysa $t$ yerine $[n]$ gelir; diferansiyel denklemlerin yerini fark denklemleri alır.
  - Örnek: gecikme bloğuna giren $e[n] = x[n] - a y[n]$, çıkış $y[n] = e[n-1]$, dolayısıyla $y[n] = x[n-1] - a y[n-1]$ (ekrandan, 01:15:00).
- Soru çözümü: işaret işlemleri, enerji ve güç, tek/çift bileşenler, sistem özellikleri testleri (ayrıntılar aşağıda ve genişletilmiş notta).

## Hocanın Özellikle Vurguladığı Kısımlar

- Bilgisayar mühendisi için asıl önemli olan ayrık zamanlı karşılıklardır
  - Sürekli zamandaki türev ve integralin ayrık zamandaki karşılıkları fark ve toplamdır; kodlamada karşılaşılan bunlardır.
- Denklemi kurmak, çözmekten daha önemlidir
  - Diferansiyel denklemleri MATLAB ya da Python zaten çözebilir; mühendisin işi olayın arkasındaki mantığı anlayıp sistemin denklemini kurabilmektir.
  - Diferansiyel denklemler bu derste elle çok çözülmeyecek, daha kısa yol olarak Laplace dönüşümü kullanılacak.
- Doğrusallık testi iki özelliğin ikisini de gerektirir
  - Toplamsallık ve çarpımsallık ayrı ayrı ya da $a x_1 + b x_2$ yazılarak birlikte test edilebilir.
- Tersinirlik dönüşümler için şarttır
  - Bir dönüşümden orijinal veri geri elde edilemiyorsa dönüşüm pek anlam taşımaz.
- Enerji ve güç sayısal özelliklerdir
  - Önemli olan sonucun sonlu mu sonsuz mu çıktığıdır; bu değerler sayısal işaret işleme ve yapay zekada özellik (feature) olarak kullanılır (örneğin iki sesten hangisinin güçlü olduğu).

## Kısa Tekrar Notları

- Ayrık türev: $x[n+1] - x[n]$; ayrık integral: kümülatif toplam.
- Geri besleme: $y = F(x - Gy)$; geri beslemeli integral alıcı $y' + ay = x$.
- Doğrusal: $F(ax) = aF(x)$ ve $F(x_1 + x_2) = F(x_1) + F(x_2)$.
- Belleksiz: yalnız şimdiki giriş. Nedensel: geçmiş ve şimdiki giriş. Bellekli: geçmiş ya da gelecek giriş.
- Zamanla değişmez: $F\{x[n-k]\} = y[n-k]$.
- BIBO kararlı: sınırlı giriş her zaman sınırlı çıkış verir.
- Tersinir: $F^{-1} \circ F = I$.
- LCCODE: $\sum a_i y^{(i)} = \sum b_j x^{(j)}$, $n$ mertebe; RLC: $LCy'' + RCy' + y = x$.
- Ayrık geri beslemeli gecikme: $y[n] = x[n-1] - a y[n-1]$.
- Enerji: $E = \int_{-\infty}^{\infty} |x(t)|^2 dt$; periyodik işarette bir periyot yeter; güç $P = E_0/T_0$.
- $x(t) = A\cos\omega t$ için $E_0 = \dfrac{A^2}{2}T_0$, $P = \dfrac{A^2}{2}$.
- $x(t) = e^{-2t}u(t)$ için $E = 1/4$; $x(t) = e^{-|t|}$ için $E = 1$, $P = 0$ (enerji işaretleri).
- Çift bileşen $x_e = \dfrac{x(t)+x(-t)}{2}$, tek bileşen $x_o = \dfrac{x(t)-x(-t)}{2}$.
- $y[n] = 8x^2[n-2]$ doğrusal değil; $y[n] = n^3 x[n+1]$ doğrusal; $y[n] = 4n\,x[n]$ zamanla değişir; $y[n] = x[n] + 2x[n-1]$ zamanla değişmez.

## Detaylı Açıklamalar

- **Ayrık zamanda türev.** Türev, $x$ noktasında $h$ kadar artım verildiğinde fonksiyon değerindeki değişimin $x$'teki değişime oranıdır: $\dfrac{f(x+h)-f(x)}{(x+h)-x}$. Ayrık zamanda indis tam sayı olduğundan en küçük artım $h=1$'dir ve payda 1 olur; birinci fark $x[n+1]-x[n]$ elde edilir (ekrandan, 00:20:00). Hızdaki değişimin ivmeyi vermesi gibi, bir ses işaretinin zamana göre nasıl değiştiği de bu farkla incelenebilir.

- **Konvolüsyonun sezgisi.** Aranan küçük işaret (filtre, çekirdek, wavelet bağlamında "mother function") büyük işaretin başından sonuna kaydırılır; her konumda iki işaret çarpılıp toplanır. Benzerliğin yüksek olduğu yerlerde sonuç tepe yapar, böylece büyük işaretin içinde küçük işarete benzeyen kısımlar bulunur. Bu işlemin sonucu ileride $h$ ile gösterilecek kavramlarla (dürtü yanıtı) bağlanacaktır.

- **Geri besleme ve öğrenme.** Geri beslemeli bir sistemde çıkış ile beklenen çıkış arasındaki hata girişe geri yansıtılır. Hoca bunu sayısal analizdeki regresyon/eğri uydurmaya, yapay sinir ağlarındaki hatanın geri yayılımına ve insanın deneyimden ders çıkarmasına benzetti: integral alıcı deneyimi biriktirir, geri besleme hatayı çıkarır; hatalar küçüldükçe çıkış istenen değere yaklaşır. Slayttaki geri beslemeli integral alıcıda integral alıcının girişi $x - ay$'dir; integral alıcının girişi çıkışının türevi olduğundan $x - ay = y'$ yazılır (ekrandan, 00:35:00).

- **Doğrusallık testi.** $F(x) = x$ için $F(ax) = ax = aF(x)$ sağlandığından sistem homojendir. $F(x) = (x+2)^2$ için $F(ax) = (ax+2)^2 = a^2x^2 + 4ax + 4$ ve $aF(x) = a(x^2 + 4x + 4)$ olur; $a \neq 1$ için eşit değildir, sistem homojen değildir (ekrandan, 00:40:00).

- **Diferansiyel denklemli sistemler.** RLC devresinde (seri $L$, $R$, $C$; çıkış kapasitör gerilimi) Kirchhoff gerilim yasası $x - Li' - Ri - y = 0$ verir; $i = Cy'$ konunca $LCy'' + RCy' + y = x$ bulunur, bu bir LCCODE'dur ve sistem doğrusaldır (ekrandan, 01:05:00). Kütle-yay-sönümleyici sisteminde $x(t)$ tabanın, $y(t)$ kütlenin yer değiştirmesidir; yay kuvveti $k(x-y)$, sönüm kuvveti $b(x-y)'$, Newton denklemi $my'' = b(x-y)' + k(x-y)$, yani $my'' + by' + ky = bx' + kx$ (ekrandan, 01:10:00). Bu tür bir modelin deprem sırasında bir binanın ya da arabanın süspansiyon sisteminin modellenmesinde kullanıldığı söylendi.

- **Sistem analizi ve sentezi.** Analizde verilen sistemin denklemi çözülerek akım, gerilim gibi parametreler bulunur. Sentezde istenen özellikleri sağlayan sistem için önce denklem kurulur, sonra parametreler belirlenerek sistem tasarlanır.

- **Soru çözümü: işaret işlemleri (ekrandan, 01:30:00 - 01:40:00).** Sürekli $x(t)$, $0 \le t \le 4$ aralığında 0'dan 3'e doğrusal artan bir rampa iken $x(t-2)$ 2 birim sağa ötelenir, $x(2t)$ yarıya sıkışır (rampa $[0,2]$), $x(t/2)$ iki kat genişler (rampa $[0,8]$), $x(-t)$ ters çevrilir (rampa $[-4,0]$); genlik değişmez. Ayrık $x[n] = \{0, 1, 2, 3, 3\}$ ($n = 0..4$) için $x[2n]$'de tek indisli örnekler kaybolur (aşağı örnekleme): $x[2n] = \{0, 2, 3\}$ ($n = 0, 1, 2$). $x(t)[u(t) - u(t-1)]$ yalnız $[0,1)$ aralığını geçirir.

- **Soru çözümü: enerji ve güç (ekrandan, 01:45:00 - 01:55:00).** $x(t) = e^{-2t}u(t)$ için $|x|^2 = e^{-4t}$, $E = \int_0^\infty e^{-4t}dt = 1/4$; sonlu olduğundan enerji işaretidir. $x(t) = A\cos\omega t$ için $T_0 = 2\pi/\omega$, $\cos^2 x = (1+\cos 2x)/2$ kullanılarak $E_0 = \dfrac{A^2}{2}T_0$ (çünkü $\int_{-T_0/2}^{T_0/2}\cos 2\omega t\,dt = \sin(\omega T_0)/\omega = \sin(2\pi)/\omega = 0$), $P = E_0/T_0 = A^2/2$. $x(t) = e^{-|t|}$ için $E = 1$, ortalama güç $\dfrac{1}{T}(1 - e^{-T}) \to 0$.

- **Soru çözümü: tek ve çift bileşen (ekrandan, 01:55:00).** $x(t) = 2\cos t - \sin t + 3\sin t\cos t$ için $x_e(t) = 2\cos t$, $x_o(t) = -\sin t + 3\sin t\cos t$. Kosinüs çift, sinüs tek olduğundan ve $\sin t\cos t$ çarpımı tek olduğundan sonuç gözle de görülebilir.

- **Soru çözümü: doğrusallık ve zamanla değişmezlik (ekrandan, 02:00:00 - 02:15:00).** $y[n] = 8x^2[n-2]$: $x \to ax$ için $8a^2x^2[n-2] \neq a\cdot 8x^2[n-2]$ ($a \neq 1$), doğrusal değildir. $y[n] = n^3 x[n+1]$: $a x_1 + b x_2$ yazılınca $a n^3 x_1[n+1] + b n^3 x_2[n+1]$ çıkar, $aF\{x_1\} + bF\{x_2\}$'ye eşittir, doğrusaldır. $y[n] = 4n\,x[n]$: $F\{x[n-k]\} = 4n\,x[n-k]$ ama $y[n-k] = 4(n-k)x[n-k]$, eşit olmadığından zamanla değişir. $y[n] = x[n] + 2x[n-1]$: $F\{x[n-k]\} = x[n-k] + 2x[n-1-k] = y[n-k]$, zamanla değişmez.

- **Ders sonrası notlar.**
  - Hoca $2x + 5$ için önce "lineerdir" dedi, sonra "afin" dedi. Sistem özelliği olarak $y = 2x + 5$ homojenliği sağlamaz ($F(ax) = 2ax + 5 \neq a(2x+5)$); afin bir sistemdir, doğrusal değildir.
  - Hoca nedensel sistemi "bellekli sistemin alt kümesi" diye anlattı; doğrusu, belleksiz sistemler de nedenseldir. Nedensellik ile bellek ayrı özelliklerdir.
  - Hoca normal vücut sıcaklığı için "47 derece" dedi; doğrusu yaklaşık 37 °C'dir (büyük olasılıkla dil sürçmesi ya da Whisper hatası).
  - $x(t/2)\,\delta(t-1.5)$ sorusunda hoca önce sonucu 1 genlikli dürtü buldu, sonra 2'ye düzeltti. Doğrusu: $x(t/2)$'nin $t = 1.5$'teki değeri $x(0.75) = 1$ olduğundan sonuç $\delta(t-1.5)$'tir (genlik 1). Hocanın düzeltmesinde $t = 1.5$ yanlışlıkla $t = 3$'e eşlenmiştir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
