# Ders 23 Çalışma Özeti

## Genel Konular

- Maliyet faktörü ve karmaşıklık hesabı
  - Sayısal bir sistem tasarlanırken iki temel unsur vardır: maliyet ve karmaşıklık. Bunlara ek olarak harcanan güç, tasarım süresi, uyumluluk, transistör sayısı ve gerçeklenebilirlik de göz önünde bulundurulur.
  - Maliyet iki kalemden oluşur: tasarım ve üretim. $M_{\text{maliyet}} = M_{\text{tasarım}} + M_{\text{üretim}}$; üretim maliyeti $M_{\text{üretim}} = M_{\text{makine}} + M_{\text{giderler}}$ biçimindedir (ekrandan, 00:10:00). Tasarım maliyetine devrenin kurgulanması ile çizim ve simülasyon için kullanılan yardımcı araçlar girer; giderlere elektrik, havalandırma, soğutma gibi kalemler girer.
  - Karmaşıklık iki türdür: eleman karmaşıklığı (component complexity) ve zaman (hız) karmaşıklığı (time complexity) (ekrandan, 00:10:00).
  - Eleman karmaşıklığında tüm devre sayısı, farklı tüm devre sayısı ve tüm devre uç sayısı sayılır. Zaman karmaşıklığında tüm devrenin çalışma hızı ve gecikme hesaba katılır.
- Katmanlı devrede gecikme
  - Aynı katmandaki kapıların gecikmelerinden en büyüğü alınır, sonra sonraki katmanın gecikmesi eklenir. Katman sayısı arttıkça toplam gecikme artar.
- Programlanabilir kombinezonsal devreler
  - Tek bir tüm devrenin içinde çok sayıda VE/VEYA (ya da VE-DEĞİL) kapısı bulunur; aralarındaki bağlantılar programlanarak karmaşık bir lojik ifade tek tüm devreyle gerçekleştirilir.
  - Üç tipi anılır: programlanabilir yalnız okunur bellek (PROM), programlanabilir diziler ve programlanabilir lojik diziler. Bu kısım derste ayrıntılı anlatılmadı, öğrencilerin kitaptan çalışmasına bırakıldı.
- Ardışıl (sequential) devrelerin genel yapısı
  - Lojik devreler kombinezonsal ve ardışıl olarak ikiye ayrılır. Kombinezonsal devrede $t$ anındaki çıkış yalnız $t$ anındaki girişe bağlıdır; ardışıl devrede bir hafıza birimi vardır ve çıkış geçmiş durum bilgisine de bağlıdır.
  - Genel yapı: girişler $x(t)$ ve mevcut durumlar $d(t)$ kombinezonsal kısma girer; kombinezonsal kısım çıkışları $z(t)$ ve bir sonraki durumları $d(t+1)$ üretir; $d(t+1)$ hafıza bloğunda saklanır ve sonraki adımda $d(t)$ olarak geri beslenir (ekrandan, 00:20:00).
- Mealy ve Moore makineleri
  - Mealy: $z(t) = f\big(x(t), d(t)\big)$, $d(t+1) = g\big(x(t), d(t)\big)$.
  - Moore: $z(t) = f\big(d(t)\big)$, $d(t+1) = g\big(x(t), d(t)\big)$. Çıkış yalnız duruma bağlıdır; giriş yalnız sonraki durumu üreten kombinezonsal kısımda işlenir.
- Asenkron ve senkron ardışıl devreler
  - Asenkron devrede girişteki değişiklik, bir saat beklenmeden yalnız devrenin iç gecikmeleri kadar sonra çıkışa yansır. Gecikmeler birbirinden farklı uzunlukta olabilir; katman sayısı arttıkça uzar.
  - Senkron devrede bir saat işareti vardır; devre yalnız saatin tetikleme anlarındaki girişleri dikkate alır.
- Saat işareti ve tetikleme
  - Saat işareti lojik 0 ile 1 arasında gidip gelen kare dalga ya da dar bir darbe dizisidir; idealde anlık bir atımdır.
  - Tetikleme türleri: yükselen kenar, düşen kenar (kenar tetiklemeli) ve seviye tetiklemeli (örneğin 1 seviyesindeyken çalışma) (ekrandan, 00:30:00).
  - Periyot $T$, frekansın tersidir ($T = 1/f$). Bir periyot darbe kısmı ve boşluk kısmından oluşur; idealde darbe sıfıra çok yakın, boşluk periyodun neredeyse tamamıdır. $T_{\text{darbe}}/T_{\text{boşluk}}$ ya da $T_{\text{darbe}}/T$ gibi oranlar verilir.
- Durum diyagramı ve durum tablosu
  - Durumlar graf düğümleriyle gösterilir; düğümler arası ok "giriş/çıkış" etiketi taşır. Her düğümden girişin bütün olasılıkları için bir ok çıkmalıdır (1 bitlik girişte 0 ve 1; 2 bitlikte 00, 01, 10, 11).
  - Durum tablosu üç kısımdan oluşur: şimdiki durum $Q(t)$, sonraki durum $Q(t+1)$ (ya da $Q^+$) ve çıkış $Z$. Durumlar ikilik kodlanır; $n$ durum için $\lceil \log_2 n \rceil$ bit gerekir.
- Sonlu durum makineleri ve dizi tanıma örnekleri
  - Sonlu durum makinesi, çıkışı elde etmek için belirli sayıda geçmiş bilgisine ihtiyaç duyan ardışıl devre uygulamasıdır.
  - Örnek 1: art arda 1, 1, 1, 0 gelince çıkışı 1 yapan "şifre" devresi (4 durum, ya da kilitlemeli tasarımda bir ek durum).
  - Örnek 2: art arda 0, 1, 1, 0, 1, 0 gelince 1 üreten ve sonra hep 1 veren kilitlemeli devre (7 durum, 3 bit).
- Standart tasarım birimleri
  - Hafıza bloğunda flip-floplar, tutucular (latch), saklayıcılar (register), sayıcılar, RAM, ROM, PROM, EPROM, EEPROM, CAM ve programlanabilir ardışıl diziler kullanılır. Flip-flop 1 bit saklar (ekrandan, 01:00:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Her düğümden girişin bütün değerleri için geçiş tanımlanmalı
  - Bir durumda yalnız beklenen giriş için ok çizip öteki girişi unutmak tasarımı eksik bırakır; ders sonundaki soru da tam bu tür bir eksikliği (4. durumda 0 gelmesi) yakaladı.
- Dizi bozulunca her zaman başa dönülmez
  - Beklenmeyen bir giriş geldiğinde, son gelen bitlerin aranan dizinin başlangıcıyla örtüşüp örtüşmediğine bakılır. Örneğin 1110 devresinde 1111 gelirse son üç 1 hâlâ geçerlidir ve makine "111 gelmiş" durumunda kalır.
- Problem iyi tanımlanmalı
  - Dizi tamamlandıktan sonra başa mı dönüleceği yoksa kilitlenip hep 1 mi verileceği tamamen tasarım kararıdır; problemin tanımında açıkça belirtilmelidir.
- Senkron devrede yalnız tetikleme anı önemli
  - Saat darbeleri arasında giriş istediği kadar değişebilir; devre için önemli olan seçilen kenar (ya da seviye) anındaki girişlerdir.
- Gecikmede en büyük değer alınır
  - Aynı katmandaki kapı gecikmelerinden en büyüğü alınır ki çıkışın tamamen oluştuğundan emin olunsun.

## Kısa Tekrar Notları

- $M_{\text{maliyet}} = M_{\text{tasarım}} + M_{\text{üretim}}$, $M_{\text{üretim}} = M_{\text{makine}} + M_{\text{giderler}}$.
- Karmaşıklık: eleman (tüm devre sayısı, farklı tüm devre sayısı, uç sayısı) ve zaman (çalışma hızı, gecikme).
- Uç sayısı yüksek tüm devre daha çok transistör içerir, daha pahalıdır; benzer tüm devreler kullanmak maliyeti düşürür.
- Ardışıl devre = kombinezonsal kısım + hafıza; $d(t+1)$ saklanır, sonraki adımda $d(t)$ olur.
- Mealy: çıkış giriş ve duruma bağlı. Moore: çıkış yalnız duruma bağlı.
- Asenkron: değişiklik yalnız gecikmeyle çıkışa yansır. Senkron: saat işaretinin tetikleme anlarında çalışır.
- Tetikleme: yükselen kenar, düşen kenar, seviye.
- $T = 1/f$; periyot = darbe + boşluk.
- Durum tablosu: $Q(t)$, $Q(t+1)$, $Z$; $n$ durum için $\lceil \log_2 n \rceil$ flip-flop.
- 011010 dizisi tanıyıcı: 7 durum, 3 bit ($d_2 d_1 d_0$).
- Flip-flop ve tutucu 1 bit saklar; saklayıcı birden çok flip-floptan oluşur; sayıcı her saat darbesinde içeriğini 1 artırır.

## Detaylı Açıklamalar

### Katmanlı devrede gecikme

Hoca, iki girişli kapılardan oluşan iki katmanlı bir devre çizer: birinci katmanda iki VE-DEĞİL kapısı (1 ve 2), ikinci katmanda bu ikisinin çıkışlarını alan bir VE-DEĞİL kapısı (ekrandan, 00:10:00). Birinci kapının gecikmesi 15, ikincininki 20 birim olsun. İkinci katmanın girişleri ancak ikisi de oluştuğunda doğrudur, bu yüzden birinci katmanın gecikmesi $\max(15, 20) = 20$ alınır ve buna ikinci katmanın gecikmesi eklenir. Bir girişin doğrudan son katmana gelmesi, ötekilerin ise önce bir kapıdan geçmesi durumunda da en uzun yol dikkate alınır.

<!-- BELİRSİZ: Hoca gecikme birimini önce milisaniye, sonra mikrosaniye olarak söyledi; sayılar temsilî. -->

> **Ders sonrası not:** Hoca örnekte gecikmeleri milisaniye ve mikrosaniye cinsinden verdi; gerçek lojik kapıların yayılma gecikmeleri büyük olasılıkla nanosaniye mertebesindedir. Örnek yalnız "en büyük gecikmeyi al, katmanları topla" fikrini göstermek içindir.

### Ardışıl devrenin genel yapısı, Mealy ve Moore

Kombinezonsal devrede kutuya $t$ anında giren bilgi $t$ anında çıkışa yansır. Ardışıl devrede kutunun içinde ayrıca bir hafıza vardır. Kombinezonsal kısım hem girişleri $x(t)$ hem de hafızadan gelen mevcut durumları $d(t)$ alır; çıkışları $z(t)$ ve sonraki durumları $d(t+1)$ üretir. $d(t+1)$ hafızaya yazılır ve bir sonraki adımda yeni girişlerle birlikte işlenir.

Mealy makinesinde çıkış hem girişin hem durumun fonksiyonudur. Moore makinesinde çıkış yalnız durumun fonksiyonudur: giriş ayrı bir kombinezonsal kısımda mevcut durumla birlikte işlenip sonraki durumu üretir, çıkışı üreten kısım ise yalnız durumlarla beslenir. İki makinede de sonraki durum hem girişe hem mevcut duruma bağlıdır.

> **Ders sonrası not:** Hoca Moore makinesini anlatırken bir yerde "giriş sadece durumlara bağlı" dedi; kastedilen çıkıştır. Bir yerde de Mealy'nin sonraki durum fonksiyonu için "aynı Moore makinesindeki gibi" dedi; kastedilen Mealy makinesidir.

### Senkron devre ve saat işareti

Senkron devrede saat işaretinin seçilen kenarı geldiğinde devre o anki girişleri alır ve belli bir gecikmeyle çıkışı günceller. Kenarlar arasında giriş değişse de devre bunu görmez. Saat işaretinde yükselen kenar (y.k.) ve düşen kenar (d.k.) tetiklemesi kenar tetiklemedir; seviye tetiklemede devre işaretin 1 (ya da tersine 0) olduğu süre boyunca çalışır, bu durumda darbenin dar tutulması gerekir.

### Durum diyagramından durum tablosuna: sayıcı örneği

0'dan 7'ye sayan ve tek sayılarda çıkışı 1 yapan bir devrede durumlar 0, 1, ..., 7 düğümleridir; 7'den sonra 0'a dönülebilir ya da 7'de kalınabilir. Ayrı bir giriş yoktur, her saat darbesi bir sonraki duruma geçirir. 8 durum için 3 bit ($A, B, C$) gerekir. Hocanın sözlü kurduğu ilk satırlar: 0'dan 1'e geçişte çıkış 1, 1'den 2'ye 0, 2'den 3'e 1, 3'ten 4'e 0.

### Örnek 1: 1110 şifre devresi

Bir giriş ve bir çıkış vardır. Giriş bit akışında art arda 1, 1, 1, 0 gelince çıkış 1, aksi hâlde 0 olmalıdır (ekrandan, 00:45:00). Durumlar: $d_0$ (başlangıç), $d_1$ ("1" gelmiş), $d_2$ ("11" gelmiş), $d_3$ ("111" gelmiş).

| Durum | $x=0$ | $x=1$ |
|---|---|---|
| $d_0$ | $d_0$ / 0 | $d_1$ / 0 |
| $d_1$ | $d_0$ / 0 | $d_2$ / 0 |
| $d_2$ | $d_0$ / 0 | $d_3$ / 0 |
| $d_3$ | $d_0$ / 1 (başlangıca dönüş) | $d_3$ / 0 |

$d_3$'te 0 gelince iki tasarım seçeneği vardır: başlangıca dönmek (tabloda gösterilen) ya da yeni bir kilit durumuna geçip bundan sonra her girişte 1 üretmek (kilitleme). $d_3$'te 1 gelirse dizinin ilk 1'i düşer, son üç 1 hâlâ "111" olduğu için $d_3$'te kalınır.

### Örnek 2: 011010 dizisi ve kilitlenen çıkış

Akışta sırasıyla 0, 1, 1, 0, 1, 0 gelince çıkış 1 olacak ve bundan sonra hep 1 kalacaktır (ekrandan, 00:50:00 ve 00:55:00). Durum $k$, aranan dizinin ilk $k$ bitinin gelmiş olduğunu gösterir; 6 kilit durumudur.

| Durum | $d_2 d_1 d_0$ | $x=0$: sonraki / $z$ | $x=1$: sonraki / $z$ |
|---|---|---|---|
| 0 | 000 | 001 / 0 | 000 / 0 |
| 1 | 001 | 001 / 0 | 010 / 0 |
| 2 | 010 | 001 / 0 | 011 / 0 |
| 3 | 011 | 100 / 0 | 000 / 0 |
| 4 | 100 | 001 / 0 | 101 / 0 |
| 5 | 101 | 110 / 1 | 011 / 0 |
| 6 | 110 | 110 / 1 | 110 / 1 |

Tablonun ilk satırları derste yazıldı (ekrandan, 01:05:00); geri kalanı diyagramdan çıkarıldı ve python ile bütün kısa giriş dizileri üzerinde denetlendi. 7 durum $\lceil \log_2 7 \rceil = 3$ bitle (3 flip-flop) kodlanır.

> **Ders sonrası not:** Hoca durumları sayarken "0'dan 6'ya 6 durum" dedi; 0'dan 6'ya 7 durum vardır. 3 bit yine yeterlidir. Ayrıca 6. durum için sözlü olarak "çıkışlarım devamlı sıfır" dedi; diyagramda bu durum "–/1" ile gösterilmiştir ve problem gereği çıkış devamlı 1'dir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
