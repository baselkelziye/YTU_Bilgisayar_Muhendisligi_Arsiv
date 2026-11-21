# Ders 2 Çalışma Özeti

## Genel Konular

- Dersin kapsamı ve sayısal işaret işlemenin amacı
  - Ders; sayısal işaret işleme (DSP), görüntü işleme ve makine öğrenmesini (örüntü tanıma) birleştiren disiplinlerarası bir derstir. İlk kısımda işaret işleme, ardından görüntü işleme ve makine öğrenmesinin temelleri anlatılır.
  - Biyomedikal veri de uzaktan algılama verisi de olsa yapılan iş aynıdır: dış dünyadan sensörle alınan veri, işlem yapabilen bir "bilgisayara" aktarılır. Mikrodenetleyici ya da mikroişlemci barındıran her birim (cep telefonu, sensörlü bir kart, otomobilin kontrol birimi) bu anlamda bir bilgisayardır.
- Bir, iki ve çok boyutlu işaretler
  - $x(t)$ gibi yalnız bir bağımsız değişkene (zamana) bağlı işaret bir boyutludur (1D); örnek: konuşma, EKG (ekrandan, 00:45:00).
  - Gri seviye bir görüntü iki boyutlu bir fonksiyondur: $u(x, y)$. Renkli görüntü R, G, B adlı üç iki boyutlu katmandan oluşur. MR gibi kesit görüntüleri çok katmanlı, $N$ boyutlu veri üretir.
- Analog (sürekli) işaretler ve ayrıklaştırma ihtiyacı
  - Dış dünya verileri süreklidir: ses havada kesintisiz yayılır, gözde piksel kavramı yoktur, eski film makineleri de ışığa kimyasal tepkiyle görüntü kaydeder.
  - İki zaman anı (örneğin 3. ve 4. saniye) arasında sonsuz sayıda genlik değeri vardır. Bilgisayarın hafızası sınırlı olduğu için sürekli işaret ayrık (discrete) hale getirilmelidir.
- Örnekleme (sampling)
  - Sürekli işaretten belirli aralıklarla örnek alınır. İki örnek arasındaki süre örnekleme periyodu $T_s$, tersi örnekleme frekansı $F_s = 1/T_s$ olarak adlandırılır (ekrandan, 00:50:00).
  - Sık örnekleme orijinal işarete iyi yaklaşır ama işlem yükünü ve hafızayı artırır. Seyrek örnekleme kaynak tasarrufu sağlar ama işaretteki önemli değişimler kaçırılır (örneğin EKG'de hastalığa işaret eden küçük bir titreşim).
  - Amaç: işaretin bilgi taşıyan özelliklerini kaybetmeden alınabilecek en büyük $T_s$ değerini bulmak.
- Sinüzoidal işaretler ve frekans
  - Bir sinüzoid üç büyüklükle tanımlanır: genlik $A$, frekans $f$ (ya da periyot $T = 1/f$) ve faz $\varphi$: $f(t) = A\sin(\omega t + \varphi) = A\sin(2\pi f t + \varphi)$ (ekrandan, 01:00:00).
  - Frekans, işaretin birim zamanda (bir saniyede) çevrimini kaç kez tamamladığıdır. Frekans arttıkça periyot kısalır.
  - Sinüs ile kosinüs arasındaki tek fark başlangıç noktasıdır, yani fazdır.
  - Frekansı sıfır olan işaret DC (doğru akım), salınım yapan işaret AC (alternatif akım) işaretidir. Şehir şebekesi Türkiye'de ve Avrupa'nın çoğunda 220 V, 50 Hz; ABD'de 110 V, 60 Hz'dir (ekrandan, 01:05:00).
- Fourier analizi ve bant sınırlı işaretler
  - Fourier'e göre herhangi bir fonksiyon, sonsuz sayıda farklı frekanslı ve farklı genlikli sinüzoidin toplamı olarak yazılabilir. Tahtada: $f(t) = \int_0^{\infty} A_f \sin(2\pi f t)\, df$ (ekrandan, 01:10:00). $f = 0$ bileşeni işaretin ortalamasını verir.
  - Gerçek bir kaynak sınırsız yüksek frekans üretemez; belli bir $f_{max}$ üzerindeki bileşenlerin genliği sıfırdır ($A_f = 0$). Bu tür işaretlere bant sınırlı işaret denir. Konuşma için $f_{max}$ yaklaşık 4 kHz'dir (ekrandan, 01:15:00).
- Nyquist teoremi
  - En kötü durum en yüksek frekanslı bileşendir. Bu bileşenin bir çevriminden yalnız iki örnek (üst ve alt tepe) alınırsa $T_{max} = 2T_s$, yani $F_s = 2F_{max}$ olur. Daha düşük frekanslı bileşenlerden bir çevrimde zaten daha çok örnek alınır.
  - Bir çevrimden dört örnek alınırsa $T_{max} = 4T_s$, $F_s = 4F_{max}$ olur; örnekleme daha iyidir.
  - Teorem: $F_s \ge 2F_{max}$. Bir işaret, içindeki en yüksek frekansın en az iki katı ile örneklenmelidir (ekrandan, 01:20:00).
- Nicemleme (quantization) ve ikili kodlama
  - Örneklenen genlik değerleri hâlâ sürekli değer alır (örneğin 5,14329875...). Hafıza hücresinin kelime boyu (örneğin 16 bit) sınırlı olduğu için genlik ekseni de belli aralıklara (kuanta seviyelerine) bölünür. Bir aralığa düşen bütün değerler o aralığı temsil eden tek bir değerle saklanır.
  - $b$ bit ile $2^b$ seviye kodlanır: 1 bit ile 2, 2 bit ile 4 (00, 01, 10, 11), 3 bit ile 8 seviye (ekrandan, 01:50:00). $L$ seviyeyi kodlamak için $\lceil \log_2 L \rceil$ bit gerekir.
  - Her eklenen bit bütün seviyeleri ikiye böler; seviye aralığı $\Delta$ küçülür ve nicemleme hatası azalır.
  - Zincir: analog işaret → örnekleme → nicemleme → ikili kodlama (binary encoding) → hafıza.
- Ayrık zamanlı işaretler
  - Sürekli işaret $x_a(t)$ normal parantezle, ayrık işaret $x[n]$ köşeli parantezle yazılır; $n$ bir tamsayı indistir: $x[n] = x_a(t)\big|_{t = nT_s}$ (ekrandan, 01:55:00).
  - 8 kHz örneklemede $T_s = 125\ \mu s$; örnekler 0, 125, 250, 375 µs anlarında alınır.
  - Karmaşık diziler: $z[n] = a + jb$; genlik $|z| = \sqrt{a^2 + b^2}$, açı $\varphi = \arctan(b/a)$, kutupsal gösterim $|z| e^{j\varphi}$ (ekrandan, 02:00:00).
- Temel diziler
  - Birim dürtü: $\delta[n] = 1$ ($n = 0$), diğer yerlerde 0. $\delta[n-1]$ dürtüyü $n = 1$'e, $\delta[n+1]$ ise $n = -1$'e taşır.
  - Birim basamak: $u[n] = 1$ ($n \ge 0$), diğer yerlerde 0. $u[-n]$ sola doğru gider, $u[n-1]$ bir sağa kayar.
  - $\delta[n] = u[n] - u[n-1]$ (ekrandan, 02:05:00).
  - Euler eşitliği: $e^{jx} = \cos x + j\sin x$; bu ifade karmaşık üstel olarak adlandırılır.
- Dizilerin sınıflandırılması
  - Süreye göre: sonlu süreli ($N_1 \le n \le N_2$) ve sonsuz süreli; sonsuz süreliler sağ yanlı (örneğin $u[n]$) ve sol yanlı (örneğin $u[-n]$) olur.
  - Periyodik dizi: $x[n] = x[n+N]$, $N$ pozitif tamsayı (ekrandan, 02:10:00). $N_1$ ve $N_2$ periyotlu iki dizinin toplamının ya da çarpımının periyodu $\dfrac{N_1 N_2}{\gcd(N_1, N_2)}$'dir.
  - Simetri: çift dizi $x[n] = x[-n]$ (örnek: kosinüs), tek dizi $x[n] = -x[-n]$ (örnek: sinüs). Karmaşık dizilerde eşlenik ($z^* = a - jb$) kullanılır.
- İşaret manipülasyonları
  - Öteleme: $x[n - n_0]$; $n_0 > 0$ ise sağa, $n_0 < 0$ ise sola kayar.
  - Ters çevirme (reversal): $x[-n]$, işaret dikey eksen etrafında katlanır.
  - Zamanda ölçekleme: $x[Mn]$ alt örnekleme (downsampling), $x[n/N]$ üst örnekleme (upsampling) (ekrandan, 02:20:00).
  - Bu işlemler sıra bağımlıdır (ekrandan, 02:25:00).
  - İşaret ayrıştırma: $x[n] = \sum_{k=-\infty}^{\infty} x[k]\,\delta[n-k]$ (ekrandan, 02:30:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Neden ayrıklaştırma gerekir?
  - Sürekli bir işaretin en küçük zaman aralığında bile sonsuz değer vardır; RAM, disk ya da bulut, hangi hafıza olursa olsun sınırlıdır. Bu yüzden önce zaman ekseni (örnekleme), sonra genlik ekseni (nicemleme) ayrıklaştırılır.
- Örnekleme sıklığının ödünleşimi
  - Sık örnekleme iyi yaklaşım sağlar ama işlem yükü ve hafıza ister; seyrek örnekleme bilgi kaybına yol açar. Hoca, sınırlı kaynağı en verimli kullanmak için "alınabilecek en geniş aralığı" bulmanın asıl problem olduğunu vurguladı.
- Nyquist teoremi: $F_s \ge 2F_{max}$
  - En yüksek frekanslı bileşen en kötü durumdur. Konuşma ($f_{max} \approx 4$ kHz) en az 8 kHz ile örneklenmelidir; 16, 32 ya da 64 kHz daha kaliteli kayıt verir.
- Bit sayısı ile nicemleme hatası ilişkisi
  - Bit sayısı arttıkça kuanta sayısı ikiye katlanır, aralık daralır, hata azalır.
- Sürekli ve ayrık gösterim farkı
  - $x(t)$ ile $x[n]$ arasındaki parantez farkı bilinçli kullanılır: köşeli parantez ayrık işaret, $n$ tamsayı indistir.
- Manipülasyonların sırası önemlidir
  - Önce öteleme sonra ters çevirme $x[-n-n_0]$ verir; önce ters çevirme sonra öteleme $x[-n+n_0]$ verir. İkisi eşit değildir.

## Kısa Tekrar Notları

- DSP: sürekli (analog) işareti ayrık hale getirip bilgisayarda işlemek.
- 1D işaret $x(t)$, 2D görüntü $u(x,y)$, renkli görüntü 3 katman (RGB).
- $T_s$ örnekleme periyodu, $F_s = 1/T_s$ örnekleme frekansı.
- Sinüzoid: $A\sin(2\pi f t + \varphi)$; $T = 1/f$.
- DC: $f = 0$; AC: $f > 0$. Türkiye şebekesi 220 V, 50 Hz; ABD 110 V, 60 Hz.
- Fourier: her işaret farklı frekans ve genlikli sinüzoidlerin toplamıdır.
- Bant sınırlı işaret: $f_{max}$ üzerinde bileşen yoktur. Konuşmada $f_{max} \approx 4$ kHz.
- Nyquist: $F_s \ge 2F_{max}$; konuşma için en az 8 kHz.
- Nicemleme: $b$ bit → $2^b$ seviye; $L$ seviye → $\lceil \log_2 L \rceil$ bit. 8 bit → 256 seviye.
- Zincir: örnekleme → nicemleme → ikili kodlama.
- $x[n] = x_a(nT_s)$; 8 kHz'de $T_s = 125\ \mu s$.
- $z = a + jb = |z|e^{j\varphi}$, $|z| = \sqrt{a^2+b^2}$, $\varphi = \arctan(b/a)$.
- $\delta[n] = u[n] - u[n-1]$; $e^{jx} = \cos x + j\sin x$.
- Periyodik: $x[n] = x[n+N]$; iki periyodik dizinin birleşiminin periyodu $N_1N_2/\gcd(N_1,N_2)$.
- Çift: $x[n] = x[-n]$; tek: $x[n] = -x[-n]$.
- $x[2n]$ alt örnekleme (sıkıştırır), $x[n/2]$ üst örnekleme (genişletir).
- Öteleme, ters çevirme ve ölçekleme sıra bağımlıdır.
- $x[n] = \sum_k x[k]\delta[n-k]$.

## Detaylı Açıklamalar

- **Örnekleme ve Nyquist sınırı.** Hoca, bir kalp atım işareti üzerinde belirli aralıklarla örnek alarak örneklemeyi anlattı. İki örnek arasındaki süre $T_s$'dir. Örnekler çok seyrek alınırsa (tahtada kırmızıyla gösterilen durum) işaretteki ara değişimler yakalanamaz; çok sık alınırsa her nokta hafızada yer tutar. Fourier analizine göre işaret farklı frekanslı sinüzoidlerden oluştuğu ve gerçek işaretler bant sınırlı olduğu için, örnekleme aralığını belirleyen bileşen en yüksek frekanslı olandır. Bu bileşenin yalnız tepe noktaları alındığında bir çevrimde iki örnek olur: $T_{max} = 1/f_{max} = 2T_s$, yani $F_s = 2F_{max}$. Bu, alınabilecek en büyük $T_s$'ye karşılık gelen alt sınırdır. Dolayısıyla $F_s \ge 2F_{max}$ (Nyquist teoremi) yazılır (ekrandan, 01:20:00).
  - Örnek: Konuşma işaretinde $f_{max} = 4$ kHz ise $F_s \ge 8$ kHz olmalıdır. Bu durumda $T_s = 1/8000\ s = 125\ \mu s$; örnekler $0, 125, 250, 375\ \mu s$ anlarında alınır.
  - > **Ders sonrası not:** Hoca örnek anlarını sayarken bir an "750 mikrosaniye" dedi, hemen ardından 375 diye düzeltti. Doğru sıra 0, 125, 250, 375 µs'dir.
- **Nicemleme.** Örneklemeden sonra zaman ayrıktır ama genlik hâlâ süreklidir. 16 bitlik bir hafıza hücresine 5,14329875... gibi sonsuz basamaklı bir değer yazılamaz. Genlik ekseni kuanta seviyelerine bölünür; örneğin hocanın örneğinde 3,70–3,80 aralığına düşen değerler 3,75 ile, 3,80–3,90 aralığına düşenler 3,85 ile temsil edilir. 3,73 ve 3,78 değerleri aynı aralıkta olduğu için ikisi de 3,75 olarak saklanır; mutlak hata toplamı $|3{,}75-3{,}73| + |3{,}78-3{,}75| = 0{,}05$ olur. Bit sayısı arttıkça aralık $\Delta$ daralır ve bu hata küçülür.
  - 8 bit ile $2^8 = 256$ seviye kodlanır (hoca sıfır dahil pozitif ve negatif taraf olarak böldü). 9 bit ile her seviye ikiye bölünür ve $2^9 = 512$ seviye elde edilir.
  - > **Ders sonrası not:** Altyazıda 9 bit için "259" geçiyor; hocanın gerekçesi ("$2^8$'in iki katı") doğrudur ve doğru değer 512'dir. Ayrıca altyazıda "3 bitle 4 kuanta" geçiyor; tahtadaki 00, 01, 10, 11 kodlarına göre 4 seviye 2 bit ile elde edilir (ekrandan, 01:50:00).
- **Temel diziler ve ayrıştırma.** Birim dürtü yalnız $n = 0$'da 1 değerini alır. Birim basamak $n \ge 0$ için 1'dir. $u[n]$'den bir sağa kaymış $u[n-1]$ çıkarılınca yalnız $n = 0$'daki örnek kalır: $\delta[n] = u[n] - u[n-1]$. Her dizi, ötelenmiş ve ağırlıklandırılmış dürtülerin toplamıdır: tahtadaki örnekte $x[0] = 3$, $x[1] = 2$, $x[2] = 1$ için $x[n] = 3\delta[n] + 2\delta[n-1] + 1\cdot\delta[n-2]$ (ekrandan, 02:30:00). Kapalı formda $k$ ötelemeyi, $x[k]$ katsayıyı belirler.
- **Zamanda ölçekleme örneği.** Tahtadaki dizi: $x[-1] = 1$, $x[0] = 3$, $x[1] = 2$, $x[2] = 1$ (ekrandan, 02:20:00).
  - Alt örnekleme $x[2n]$: $n = 0 \to x[0] = 3$, $n = 1 \to x[2] = 1$, diğerleri 0. İşaret sıkışır (ekrandan, 02:25:00).
  - Üst örnekleme $x[n/2]$: $n = -2 \to 1$, $n = 0 \to 3$, $n = 2 \to 2$, $n = 4 \to 1$; tek $n$ değerlerinde $n/2$ tamsayı olmadığı için değer 0'dır. İşaret genişler (ekrandan, 02:25:00).
- **Sıra bağımlılığı.** $x[n] \xrightarrow{T_{n_0}} x[n-n_0] \xrightarrow{T_r} x[-n-n_0]$; buna karşılık $x[n] \xrightarrow{T_r} x[-n] \xrightarrow{T_{n_0}} x[-n+n_0]$. Sonuçlar farklı olduğu için işlemler sıra bağımlıdır (ekrandan, 02:25:00).
- **Ders sonundaki soru.** Bir öğrenci, örneklenen veriyi RAM'e koymak için gereken en az bit sayısının hesaplanıp hesaplanamayacağını sordu. Hoca, kelime boyunun (16, 32, 64 bit) sistemin bir özelliği olduğunu, örnekleme frekansından ayrı bir kavram olduğunu söyledi. Kaba hesapla, sıkıştırma olmadan 8 kHz'de bir saniyelik ses 8000 örnek, 16 bin hücre 2 saniye, 32 bin hücre 4 saniye ses saklar.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
