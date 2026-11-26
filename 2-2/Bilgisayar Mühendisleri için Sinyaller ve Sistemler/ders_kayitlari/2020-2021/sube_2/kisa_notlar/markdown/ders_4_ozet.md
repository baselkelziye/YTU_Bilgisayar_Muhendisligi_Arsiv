# Ders 4 Çalışma Özeti

## Genel Konular

- İşlem sırasının tekrarı ve periyodik işaretler
  - Ölçekleme ve ötelemenin birlikte uygulandığı $x(2(t-1))$ örneğinde önce 1 öteleyip sonra 2 ile sıkıştırmak yanlış sonuç verir; ifade $x(2t-2)$ olarak açılırsa önce 2 öteleyip sonra 2 ile ölçeklemek doğru sonucu verir (ekrandan, 00:10:00).
  - Periyodik bir işaretin $(-\infty, +\infty)$ aralığında incelenmesine gerek yoktur; tek bir periyodun incelenmesi işaretin tamamı hakkında bilgi verir. Değerleri sıfır olan aralıklar da integral ya da toplam sınırlarından çıkarılabilir (örneğin $u[n]$ için $n<0$ kısmı).
- Karmaşık (kompleks) işaretler ve karmaşık sayılar
  - $z(t) = x(t) + j\,y(t)$; $x(t)$ ve $y(t)$ gerçel değerli işaretlerdir, $j=\sqrt{-1}$ (ekrandan, 00:15:00).
  - Kartezyen biçim $z = x + jy$: $x = \Re z$ gerçel kısım, $y = \Im z$ sanal kısım; $x$ ve $y$'ye eş fazlı (in-phase) ve dik (quadrature) bileşen de denir. Mühendislikte $j$, fizik ve matematikte $i$ kullanılır (ekrandan, 00:20:00).
  - Kutupsal biçim $z = r e^{j\phi}$: $r$ genlik (modül), $\phi$ açı (faz); $e^{j\phi} = \cos\phi + j\sin\phi$. $z = x + jy$ için $e^{z} = e^{x}(\cos y + j\sin y)$ (ekrandan, 00:30:00).
  - Radar, sonar, ultrason ve haberleşme gibi uygulamalarda veriler karmaşık olarak saklanır.
- Euler bağıntısı ve sinüzoitlerin karmaşık gösterimi
  - $e^{\pm j\omega_0 t} = \cos\omega_0 t \pm j\sin\omega_0 t$; iki ifade toplanıp 2'ye bölünürse $\cos\omega_0 t = \dfrac{e^{j\omega_0 t} + e^{-j\omega_0 t}}{2}$ elde edilir.
  - Bu gösterim Fourier ve Laplace dönüşümlerinde kısmi integrasyona gerek bırakmadan üstel fonksiyon integraliyle çözüme gitmeyi sağlar.
- İşaretin enerjisi ve gücü
  - Direnç üzerinden geçen akım için $E_R = \lim_{T\to\infty}\int_{-T}^{T} i^2(t)\,R\,dt$ (Joule); $1\,\Omega$ için $E_i = \lim_{T\to\infty}\int_{-T}^{T} i^2(t)\,dt$; genel (karmaşık olabilen) işaret için $E_x = \lim_{T\to\infty}\int_{-T}^{T} |x(t)|^2\,dt$ (ekrandan, 00:35:00).
  - Enerjinin zamana göre ortalaması işaretin gücüdür. Enerji işaretinin gücü sıfır, güç işaretinin enerjisi sonsuzdur.
- Sinüzoidal işaretler
  - $x(t) = \cos(\omega t + \theta)$ ya da $x(t) = A\cos(2\pi f t + \theta)$; $\omega$ açısal frekans (rad/s), $f$ frekans (Hz), $\theta$ faz (radyan) (ekrandan, 00:40:00).
  - Periyot $T = \dfrac{1}{f} = \dfrac{2\pi}{\omega}$ saniyedir (ekrandan, 00:45:00).
  - Ayrık zamanda $x[n] = A\cos(\omega n + \phi)$; $n$ tam sayıdır.
  - Her işaret sonsuz sayıda sinüzoidin toplamı olarak düşünülebilir (Fourier fikri); konuşma sentezi gibi uygulamalar bu fikre dayanır.
- Karmaşık sinüzoitler
  - $A e^{j(\omega t + \theta)} = A\cos(\omega t + \theta) + jA\sin(\omega t + \theta)$; gerçel sinüzoit, karmaşık sinüzoidin gerçel kısmıdır: $\Re\{A e^{j(\omega t+\theta)}\} = A\cos(\omega t + \theta)$ (ekrandan, 00:50:00).
  - $\int x(t)\,e^{-j\omega t}\,dt$ integrali, işaretteki hangi sinüzoidal bileşenlerin baskın olduğunu bulur; sonuç gerçel ve sanal kısımlı çıkar (FFT çıktısı gibi).
- Üstel işaretler ve sönümlü/büyüyen sinüzoitler
  - $x(t) = e^{\sigma t}\cos(\omega t + \theta)$: $\sigma > 0$ ise büyüyen, $\sigma < 0$ ise sönümlü sinüzoit (ekrandan, 00:55:00).
  - İki bileşen de zamana bağlı olduğundan ayrık zamandaki karşılığı iç içe iki toplam, yani iç içe iki `for` döngüsü olarak düşünülmüş ve karmaşıklık $N^2$ olarak verilmiştir.
- Ayrık zamanlı karmaşık üstel ve sinüzoitlerin periyodikliği
  - $x[n] = e^{j\omega_0 n}$ ve $x[n] = \cos\omega_0 n$ için $\dfrac{2\pi}{\omega_0}$ rasyonel ise işaret periyodiktir, değilse periyodik değildir; oran sadeleştirilmiş $N/m$ biçiminde yazılırsa periyot $N$ olur (ekrandan, 01:15:00).
  - Ayrık zamanda açısal frekans için büyük omega ($\Omega$) da kullanılır.
- Temel işaretler
  - Birim basamak $u(t)$: $t \ge 0$ için 1, $t<0$ için 0 (Heaviside); sıfırdaki değer bazı kaynaklarda $1/2$ alınır (ekrandan, 01:20:00). Ayrık karşılığı $u[n]$.
  - $u(t)$ ile çarpma işaretin $t<0$ kısmını sıfırlar: $u(t)e^{-t}$.
  - $u(t) - u(t-1)$ ile $[0,1)$ aralığında 1 olan dikdörtgen darbe elde edilir.
  - Birim dikdörtgen: $\mathrm{rect}(t) = 1$, $|t| \le 1/2$; diğer yerlerde 0. Filtre ya da maske gibi kullanılır (ekrandan, 01:25:00).
  - Birim rampa: $r(t) = t$, $t\ge 0$; $r(t) = \int_{-\infty}^{t} u(\tau)\,d\tau$ (ekrandan, 01:30:00).
  - Birim üçgen: $\Delta(t) = 1-|t|$, $|t|<1$; diğer yerlerde 0 (ekrandan, 01:35:00).
  - Dikdörtgen darbelerin ölçeklenip ötelenmesiyle darbe dizisi (zarf) kurulur; bu zarf bir taşıyıcı kosinüsle çarpılınca darbeli Doppler dalga biçimi elde edilir.
- Dürtü (Dirac delta) fonksiyonu
  - $t=0$ yakınında çok büyük, uzakta çok küçük, integrali 1 olan işaretin idealleştirmesidir; genişliği $\epsilon$ ve yüksekliği $1/\epsilon$ olan dikdörtgen ya da üçgen gibi örneklerle düşünülür (ekrandan, 01:40:00).
  - Ayrık karşılığı birim dürtü $\delta[n]$: $n=0$ için 1, diğer yerlerde 0.
  - Eleme (sifting) özelliği: $\int_{-\infty}^{\infty} f(t)\,\delta(t-T)\,dt = f(T)$ (ekrandan, 01:50:00).
  - İntegral sınırları: $a<0<b$ ise $\int_a^b \delta(t)\,dt = 1$; $a>0$ ya da $b<0$ (ve $a<b$) ise 0; $a=0$ ya da $b=0$ ise belirsizdir (ekrandan, 01:55:00).
  - Fiziksel yorum: çekiç darbesi örneği (ekrandan, 02:00:00) ve kondansatörün hızlı şarjı.
  - Süreksiz fonksiyonun türevi her sıçramada dürtü içerir: $u'(t) = \delta(t)$; slayttaki örnekte $y'(t) = 1 + \delta(t-1) - 2\delta(t-2)$ (ekrandan, 02:05:00).
- Sistemlere giriş
  - Sistem, giriş işaretini çıkış işaretine dönüştüren bir dönüşüm (fonksiyon) olarak tanımlandı; ders tek girişli tek çıkışlı (SISO) sistemlere odaklanır. Blok diyagramda oklar işaretleri, kutu sistemi gösterir.
  - Ölçekleme sistemi $y = Ax$: $|A|>1$ yükselteç, $|A|<1$ zayıflatıcı, $A<0$ evirici; $A$ kazanç (gain) faktörüdür.
  - Türev alan ve integral alan sistemler; zamanda öteleme sistemi $y(t) = x(t-T)$: $T>0$ geciktirici, $T<0$ öngörücü (predictor) (ekrandan, 02:15:00).
  - Konvolüsyon sistemi: bir şablonun (örneğin göz bölgesi) işaret ya da görüntü üzerinde kaydırılarak benzerlik aranması; korelasyon da buna çok benzer.
  - Toplama, fark ve çarpma sistemleri; seri bağlantı $y = G(F(x))$, paralel bağlantı $y = Fx + Gx$ (ekrandan, 02:20:00); geri besleme.
  - İntegral alan ve geri beslemeli sistem örneği: $\dot y(t) = x(t) - a\,y(t)$ biçiminde bir diferansiyel denkleme götürür.
- MATLAB ile karmaşık üstel işaretin çizimi
  - $x[n] = e^{j\pi n/6}$ işaretinin gerçel ve sanal kısımları `stem` ve `subplot` ile ayrı ayrı çizildi (ekrandan, 02:35:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Ölçekleme ve ötelemenin sırası
  - Ölçekleme ve öteleme birlikteyse önce ölçekleme, sonra öteleme yapılır ya da ifade parantez açılarak yeniden yazılır; aksi halde sonuç yanlış olur.
- Periyodik işarette tek periyot yeter
  - Dönüşümlerde sık geçen $(-\infty, +\infty)$ sınırlarından korkulmamalı; periyodiklik ve sıfır değerli aralıklar sınırları daraltır ve çözümü kolaylaştırır.
- Birimlere dikkat
  - Hoca bu derste birimlerin önemli olduğunu söyledi: $\omega$ rad/s, $f$ Hz, periyot saniye. Gerçek anlamda frekans $f$'tir; $\omega$ açısal frekanstır.
- Formül ezberlemek yerine türetmek
  - Periyot formülünü ezberlemek yerine $2\pi f t$ ifadesini verilen argümana eşitleyip $f$'i, oradan $T = 1/f$'yi bulmak önerildi.
- Dürtü fonksiyonunun eleme özelliği
  - $\int f(t)\delta(t-T)\,dt = f(T)$ ifadesi "çok önemli bir integral" olarak vurgulandı; örnekleme konusunda yeniden kullanılacak ve konvolüsyon fikrine bağlanacak.
- Bilgisayar mühendisi açısından
  - İç içe toplamlar iç içe döngü ve algoritma karmaşıklığı demektir; zaman-frekans analizinden çıkan dizilerin farkı (ayrık türev) özellik vektörü olarak kullanılabilir.
  - Sistem modelini bulmak, girdilere göre çıktıyı tahmin edebilmek demektir; geri besleme yapay sinir ağlarının eğitimindeki hata geri yansıtmasına benzetildi.

## Kısa Tekrar Notları

- $x(2(t-1)) = x(2t-2)$: önce 2 öteleme, sonra 2 ile sıkıştırma.
- $z = x + jy = re^{j\phi}$, $r = \sqrt{x^2+y^2}$; $3+4j$ için $r=5$, $\phi \approx 53^\circ$.
- $e^{j\phi} = \cos\phi + j\sin\phi$; $\cos\omega_0 t = (e^{j\omega_0 t}+e^{-j\omega_0 t})/2$.
- $E_x = \lim_{T\to\infty}\int_{-T}^{T}|x(t)|^2dt$; güç = enerjinin zamana göre ortalaması.
- Enerji işareti: güç 0; güç işareti: enerji sonsuz.
- $\cos(500\pi t)$: $f = 250$ Hz, $T = 4$ ms.
- $T = 1/f = 2\pi/\omega$.
- $\Re\{Ae^{j(\omega t+\theta)}\} = A\cos(\omega t+\theta)$.
- $e^{\sigma t}\cos(\omega t+\theta)$: $\sigma>0$ büyüyen, $\sigma<0$ sönümlü.
- Ayrık zamanda $2\pi/\omega_0$ rasyonel ise periyodik: $e^{j\pi n/6}$ için $N=12$; $\cos(2\pi\frac{6}{30}n)$ için $N=5$.
- $u(t)$, $\mathrm{rect}(t)$, $r(t) = \int u$, $\Delta(t)$; $u'(t) = \delta(t)$.
- $\int f(t)\delta(t-T)dt = f(T)$; $\delta$ integral aralığının içindeyse integral 1, dışındaysa 0.
- Sistem: $y = S(x)$; ölçekleme, türev, integral, öteleme (gecikme $T>0$, öngörü $T<0$), konvolüsyon, toplama, çarpma, seri, paralel, geri besleme.

## Detaylı Açıklamalar

- **Karmaşık sayıların anlamı:** Bir öğrencinin sorusu üzerine hoca, ikinci dereceden denklemde diskriminant negatif çıktığında gerçel kök olmadığını, $\sqrt{-1}$ için $j$ gösterimi kabul edilerek sayı kümesinin genişletildiğini anlattı. Bu bir gösterimdir: ileride kare ya da dördüncü kuvvet alındığında $j$ ortadan kalkar ve gerçel bir sonuca ulaşılır. $\sqrt{-4} = \sqrt{4}\cdot\sqrt{-1} = 2j$ örneği ekranda yazıldı (ekrandan, 00:20:00). Devre teorisindeki faz açıları ve radarda yaklaşan ya da uzaklaşan aracın yansıyan işaretinin analizi karmaşık işaretlere örnek olarak verildi.
- **Kutupsal biçim örneği:** $3 + 4j$ sayısı düzlemde gerçel eksende 3, sanal eksende 4 birimdir; hipotenüs Pisagor bağıntısından 5'tir, açı yaklaşık $53^\circ$'dir. Aynı sayı $5e^{j53^\circ}$ olarak yazılabilir; değişen yalnız gösterimdir.
- **Periyot hesabı:** $\cos(500\pi t)$ için $2\pi f t = 500\pi t$ eşitliğinden $f = 250$ Hz, $T = 1/250 = 4\cdot 10^{-3}$ s $= 4$ ms bulunur (ekrandan, 00:45:00). Aynı sonuç $T = 2\pi/\omega = 2\pi/(500\pi)$ ile de çıkar.
  > **Ders sonrası not:** Hoca önce $\cos(500t)$ yazıp $\pi$'yi yaklaşık 1 kabul ederek $f = 250$ Hz dedi, sonra ifadeyi $\cos(500\pi t)$ olarak düzeltti. $\cos(500t)$ için doğrusu $f = 500/(2\pi) \approx 79{,}6$ Hz ve $T \approx 12{,}6$ ms'dir; $f=250$ Hz yalnız $\cos(500\pi t)$ için geçerlidir.
- **Faz:** $\cos(\omega t - \theta)$ grafiği $\cos(\omega t)$'ye göre ötelenmiştir; faz, $t=0$ anında işaretin hangi değerden başladığını ve tepe noktasının ne kadar kaydığını gösterir (ekrandan, 00:45:00).
- **Ayrık türev ve özellik çıkarma:** Zaman-frekans analizinde her zaman aralığındaki baskın frekansların ortalaması alınarak tek boyutlu bir dizi elde edilebilir. Bu dizinin ayrık türevi $f[x+1]-f[x]$ ile bulunur. Hocanın örneğinde ortalama frekans dizisi $3, 6, 8, 12, 2, 4$ için farklar $3, 2, 4, -10, 2$ olur; bu diziler görüntü ya da ses için özellik vektörü olarak kullanılabilir.
- **Eleme özelliği sezgisi:** $f(t) = 2t$ ve $\delta(t-5)$ çarpılıp integre edildiğinde $t=5$ dışındaki bütün çarpımlar sıfırdır; integral yalnız $f(5)$ değerini verir. Hoca integrali "çarpıp çarpıp toplamak" olarak yorumladı ve bunu konvolüsyonla ilişkilendirdi.
- **Konvolüsyon sezgisi:** Göz bebeği (iris) tespitinde yuvarlak bir pencere görüntü üzerinde gezdirilir; piksel değerleri toplamının en karanlık olduğu (sıfıra en yakın değerlerin en çok toplandığı) nokta irisin yeridir. Benzer biçimde gözden kesilen bir parça bütün fotoğrafta gezdirilip benzerliğin en yüksek olduğu yer bulunur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
