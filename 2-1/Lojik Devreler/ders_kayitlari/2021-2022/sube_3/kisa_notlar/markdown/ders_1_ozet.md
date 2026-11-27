# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin kapsamı
  - Lojik devreler, mantık (lojik) matematiğindeki kavramların devreler üzerinde uygulanmasını anlatır. Bilgisayar mühendisliği lisans programının zorunlu, donanım (elektronik) ağırlıklı derslerindendir; bilgisayar mimarisi ve mikroişlemciler gibi derslere temel oluşturur.
  - İki büyük devre ailesi incelenir:
    - Kombinezonsal (birleşik) devreler: hafıza birimi barındırmayan devrelerdir; çıkış yalnız o anki girişlere bağlıdır.
    - Ardışıl devreler (sequential circuits): hafıza barındıran devrelerdir. Örneğin saymak için "4" diyebilmek, daha önce "3" dendiğini bilmeyi gerektirir.
  - Konu akışı: sayısal sistemlerin genel özellikleri, sayı sistemleri, Boole cebri, lojik fonksiyonlar ve kapılar, sadeleştirme, kombinezonsal devreler (karşılaştırıcı, toplayıcı, seçici/multiplexer, dağıtıcı/demultiplexer, kod çözücü/decoder, kodlayıcı/encoder), ardından flip-floplar, ardışıl devre çözümleme ve tasarımı, saklayıcılar, sayıcılar ve bellekler.
  - Ders içeriği ve kaynaklar ders bilgi sayfasında listelenmiştir (ekrandan, 00:15:00): M. Morris Mano ve Charles R. Kime, *Logic and Computer Design Fundamentals*; M. Morris Mano, *Digital Design*; Taner Arsan ve Rıfat Çölkesen, *Lojik Devre Tasarımı*; M. Morris Mano, *Sayısal Tasarım* (Türkçe çeviri). Konular bu kitapların hepsinde hemen hemen aynı sırayla bulunur.
- Transistör ve 0-1 mantığı
  - Bilgisayar mühendisliğinin başlangıcı transistörün bulunuşuna dayandırılır (tahtada "1950s Transistor", ekrandan, 00:20:00).
  - Transistörün tabanına (baz) verilen akıma göre çıkışta 5 V ya da 0 V elde edilir; 5 V "1", 0 V "0" olarak yorumlanır. Böylece 1, 0, 1, 0, 1, 1 gibi bit dizileri (bitstream) oluşur ve karakterler bu dizilerle kodlanır.
  - Lisedeki mantık konusundaki $p$, $q$ önermeleri (doğru/yanlış, 1/0) burada değişkenlere (variable) dönüşür: her değişken 1 ya da 0 değerinden birini alır.
- Analog (sürekli) ve sayısal işaretler
  - Analog işaret $x(t)$ zamanın her anında tanımlıdır; hem zaman ekseninde hem genlik ekseninde sonsuz sayıda değer alabilir (ör. 0,5 ile 0,6 arasında 0,556789... gibi değerler). Bunlara sürekli (continuous) işaretler de denir (ekrandan, 00:20:00).
  - Sayısal işaretler yalnız belli seviyelerde değer alır (ör. yalnız tam sayı değerleri).
  - Örnek analog işaretler: ses işareti, EKG (kalbin deride oluşturduğu elektriksel potansiyel) işareti.
- Örnekleme (sampling)
  - Analog işaret doğrudan bilgisayara atılamaz: sonsuz sayıda değeri vardır, hafıza ise sınırlıdır (tahtada 8 KB'lık bir hafıza örneği, ekrandan, 00:30:00).
  - Çözüm, işareti ayrıklaştırmaktır (discretization). Zaman ekseninde belli aralıklarla örnek almaya örnekleme denir; iki örnek arasındaki süre örnekleme periyodu $T_s$'dir (ör. $T_s = 1$ s ya da $T_s = 1$ ms; ekrandan, 00:30:00).
  - Örnekleme frekansı $F_s = 1/T_s$'dir (ekrandan, 00:40:00).
  - Sık örnekleme: işarete daha çok benzer, hata azdır; ama daha çok hafıza, daha çok işlem yükü ve daha çok güç tüketimi demektir.
  - Seyrek örnekleme: az hafıza ve az işlem gerektirir; ama hızlı değişimler (ör. kalp işaretindeki iniş çıkışlar) kaçırılabilir.
- Frekans, sinüzoidal bileşenler ve Fourier analizi
  - 1 Hz, bir çevrimin 1 saniyede tamamlanması; 2 Hz, saniyede 2 çevrim demektir (ekrandan, 00:40:00).
  - Fourier analizine göre herhangi (keyfi) bir işaret, frekansları 0'dan sonsuza giden sinüzoidal bileşenlerin toplamı olarak yazılabilir.
  - Bir sinüzoidal bileşeni tanımlayan üç özellik: periyot (ya da frekans $f = 1/T$), genlik (amplitude) ve faz. Sinüs ile kosinüs aynı işarettir; aralarında 90°'lik faz farkı vardır.
  - Gerçek işaretler bant sınırlıdır (band limited): içerdikleri en yüksek frekans $f_{max}$ sonludur. İnsan konuşması ortalama 0-4 kHz aralığındadır (ekrandan, 01:00:00).
  - 0 Hz bileşen DC bileşendir (değişim yok), diğerleri AC bileşenlerdir.
- Nyquist teoremi
  - En kötü durum, en yüksek frekanslı bileşenin bir çevriminde yalnız tepe noktalarının (2 örnek) alınmasıdır: $T_{max} = 1/f_{max}$ ve $T_{max} = 2T_s$.
  - Buradan $T_{max} \ge 2T_s$, frekans cinsinden $F_s \ge 2f_{max}$ (Nyquist teoremi) elde edilir (ekrandan, 01:10:00).
  - Ses örneği: $f_{max} = 4$ kHz ise $T_{max} = 250\ \mu s$, en düşük örnekleme frekansı $F_s = 8$ kHz, $T_s = 125\ \mu s$ (ekrandan, 01:10:00). Üst sınır yoktur; 16, 32, 64 kHz de seçilebilir.
- Nicemleme (quantization)
  - Örnekleme yalnız zaman eksenini ayrıklaştırır; genlik hâlâ sonsuz değer alabilir (ör. 0,565432109876...). Hafıza gözleri bitlerden oluştuğu için genliğin de ayrıklaştırılması gerekir. Buna nicemleme denir (ekrandan, 01:25:00).
  - 1 bit ile 2 durum, 2 bit ile 4 durum (00, 01, 10, 11), 3 bit ile 8 durum, 8 bit ile 256 durum ifade edilir; $n$ bit ile $2^n$ seviye vardır (ekrandan, 01:20:00).
  - Bit sayısı arttıkça seviyeler daralır, genlik hassasiyeti artar. Aynı seviyeye düşen iki örnek birbirinden ayırt edilemez; aradaki fark nicemleme hatasıdır.
  - Hafıza boyutu "hücre sayısı × kelime uzunluğu" şeklinde yazılır: $1\text{K} \times 8$ bit, 1024 tane 8 bitlik hücre demektir.
- Temel lojik kapılar
  - AND (VE): iki giriş de 1 ise çıkış 1'dir. OR (VEYA): girişlerden en az biri 1 ise çıkış 1'dir. İki değişkenle $2^2 = 4$ giriş durumu vardır (ekrandan, 01:30:00).
- Sayı sistemlerine giriş
  - Bit (0/1), nibble (4 bit; üst ve alt nibble), byte (8 bit).
  - Aynı hafıza içeriği farklı tabanlarda gösterilebilir: $(01100101)_2 = (101)_{10} = (65)_{16}$ (ekrandan, 01:35:00).
  - Onaltılık (hexadecimal) tabanda 16 rakam vardır: 0-9 ve A, B, C, D, E, F.

## Hocanın Özellikle Vurguladığı Kısımlar

- Analog işaret neden doğrudan işlenemez?
  - Hem zaman hem genlik ekseninde sonsuz değer vardır; bilgisayarın hafızası ve işlem gücü sınırlıdır. Bu yüzden iki eksen de ayrıklaştırılmalıdır: zaman ekseninde örnekleme, genlik ekseninde nicemleme.
- Örnekleme sıklığının bedeli
  - Daha sık örnek daha iyi temsil, ama daha çok hafıza, daha çok hesaplama karmaşıklığı ve daha çok güç tüketimi demektir. Hoca görev yöneticisindeki CPU kullanımını göstererek işlem yükü arttıkça daha çok transistörün çalışıp daha çok akım çektiğini anlattı (ekrandan, 00:35:00).
- $F_s \ge 2f_{max}$
  - Nyquist teoremi örnekleme periyodunun nasıl seçileceği sorusunun cevabıdır. $F_s$'nin bir alt sınırı vardır ($2f_{max}$), üst sınırı yoktur.
- Kalite ve dosya boyutu dengesi
  - Ses dosyalarında örnekleme frekansı arttıkça kalite artar ama dosya boyutu da büyür; düşük örnekleme frekansı kaliteden ödün verip dosyayı küçültür.
- Donanım bilgisinin önemi
  - Gömülü sistemler, robotik ve elektronik sistemlerde çalışabilmek için bu dersler gerekli altyapıyı verir; bilgisayar mühendisliğini yalnız yazılım olarak düşünmemek gerekir.

## Kısa Tekrar Notları

- Kombinezonsal devre: hafızasız. Ardışıl devre: hafızalı.
- Analog işaret: zamanın her anında tanımlı, genliği sürekli.
- Örnekleme: zaman ekseninin ayrıklaştırılması; $T_s$ örnekleme periyodu, $F_s = 1/T_s$ örnekleme frekansı.
- Nicemleme: genlik ekseninin ayrıklaştırılması; $n$ bit → $2^n$ seviye.
- Fourier: her işaret sinüzoidal bileşenlerin toplamıdır; bileşen özellikleri frekans, genlik, faz.
- Gerçek işaretler bant sınırlıdır; konuşma için $f_{max} \approx 4$ kHz.
- Nyquist: $F_s \ge 2f_{max}$, yani $T_s \le T_{max}/2$. Konuşma için $F_s \ge 8$ kHz, $T_s \le 125\ \mu s$.
- DC bileşen 0 Hz (sabit), AC bileşenler salınımlıdır.
- AND: iki giriş 1 ise 1. OR: en az bir giriş 1 ise 1.
- $(01100101)_2 = (101)_{10} = (65)_{16}$; 4 bit = nibble, 8 bit = byte.

## Detaylı Açıklamalar

- Analogdan sayısala geçişin mantığı
  - Bir sensör (mikrofon, EKG elektrotları vb.) fiziksel bir büyüklüğü elektriksel bir işarete çevirir. Bu işaret $x(t)$ zamanın her anında tanımlıdır ve herhangi bir anda, ör. 0 ile 1 arasında, virgülden sonra sonsuza giden herhangi bir değeri alabilir. Bilgisayarda ise bu değerler sınırlı sayıdaki hafıza gözlerine yazılmalıdır. Bu yüzden önce zaman ekseninde belli aralıklarla örnekler alınır (örnekleme), sonra her örneğin genliği sınırlı sayıdaki seviyelerden birine yuvarlanır (nicemleme). Sonuçta her örnek bir bit dizisi olarak hafızaya yazılır (tahtada analog işaret → PC → hafıza gözleri çizimi, ekrandan, 00:30:00).
- Örnekleme periyodunun seçimi
  - $T_s$ küçüldükçe (frekans büyüdükçe) işaret daha iyi temsil edilir, ama hafıza ve işlemci yükü artar. $T_s$ büyüdükçe kaynak tasarrufu sağlanır ama işaretteki hızlı değişimler kaçırılır. Bu ikilemin optimal cevabı Fourier analizinden gelir. İşaretteki hızlı değişimler yüksek frekanslı bileşenlerden kaynaklanır. En yüksek frekanslı bileşenin her çevriminde en az bir üst ve bir alt tepe noktası alınırsa, yani bir çevrimde en az iki örnek alınırsa, daha düşük frekanslı bileşenlerin her çevriminde zaten daha çok örnek alınmış olur. Bu yüzden en kötü durum $T_{max} = 2T_s$'dir; bir çevrimde dört örnek alınırsa $T_{max} = 4T_s$ olur (ekrandan, 01:10:00). Genel koşul $T_{max} \ge 2T_s$ ya da $F_s \ge 2f_{max}$'tır.
  - Sayısal örnek: konuşma işaretinde $f_{max} = 4$ kHz, $T_{max} = 1/4000 = 250\ \mu s$. Nyquist'e göre $F_s \ge 8$ kHz, yani $T_s \le 125\ \mu s$; saniyede en az 8000 örnek alınır.
  - Ders sonrası not: ekranda bir yerde koşul "$T_s \ge 2F_{max}$" diye yazılmış (ekrandan, 01:15:00); doğrusu $F_s \ge 2f_{max}$'tır.
- Nicemleme ve bit sayısı
  - 1 bitlik bir hafıza gözü yalnız işaretin bir referans çizgisinin üstünde mi altında mı olduğunu söyleyebilir. 2 bit ile genlik aralığı 4 bölgeye (00, 01, 10, 11), 3 bit ile 8 bölgeye ayrılır. 8 bit kullanılırsa ve işaret $-5$ V ile $+5$ V arasındaysa 10 V'luk aralık 256 seviyeye bölünür; her seviye yaklaşık $10/256 \approx 39$ mV genişliğindedir (ara adım eklendi). Aynı seviyeye düşen örnekler artık ayırt edilemez; bit sayısı arttırılırsa (ör. 16 bit) ayrışırlar.
  - Ders sonrası not: hoca 8 bitlik örnekte seviyeleri pozitif ve negatif bölge olarak ayırırken önce "258, 256, 128" gibi sayıları karıştırdı. Doğrusu: 8 bit ile toplam $2^8 = 256$ seviye vardır; ilk bit işaret biti olarak kullanılırsa 128 seviye sıfır ve pozitif bölgeye, 128 seviye negatif bölgeye düşer.
- Fourier gösterimi
  - Hoca bir öğrencinin isteği üzerine teoremi integral biçiminde yazdı (ekrandan, 01:40:00): $x(t) = \int_0^{\infty} A_f \sin(2\pi f t)\, df$. Burada $A_f$, $f$ frekansındaki bileşenin genliğidir; işarette bulunmayan bir frekansın genliği sıfırdır. $f = 0$ bileşeni DC, diğerleri AC bileşenlerdir.
  - Ders sonrası not: tam gösterimde her bileşenin fazı da yer alır (ör. $\sin(2\pi f t + \phi_f)$ ya da sinüs ve kosinüs terimleri birlikte); tahtadaki ifade yalnız sezgi için sadeleştirilmiş biçimdir (büyük olasılıkla).
- DC ve AC
  - Pil (ör. 1,5 V) sabit bir gerilim verir: DC (Direct Current). Şehir şebekesi salınım yapan bir işarettir: AC (Alternating Current), frekansı 50 Hz'dir. DC işaretin ortalaması sabit değerin kendisidir; AC işarette pozitif ve negatif alanlar birbirini götürür, ortalama sıfıra yaklaşır.
  - Ders sonrası not: derste şebeke geriliminin "±220 V arasında" salındığı söylendi. 220 V etkin (RMS) değerdir; tepe değeri büyük olasılıkla yaklaşık $220\sqrt{2} \approx 311$ V'tur.
- Sayı sistemleri
  - İkilik tabanda basamak ağırlıkları sağdan sola $2^0, 2^1, \dots, 2^7$'dir (1, 2, 4, ..., 128). $(01100101)_2$ için $64 + 32 + 4 + 1 = 101$ bulunur. Byte iki nibble'a ayrılır: $0110 = 6$, $0101 = 5$, yani $(65)_{16}$ (ekrandan, 01:35:00). Hafıza gözünün içeriği değişmez; değişen yalnız gösterim biçimidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
