# Ders 1 Çalışma Özeti

## Genel Konular

- Sayısal işaret işleme temelleri ve örnekleme (sampling) tekrarı
  - Sürekli (analog) işaretlerin ayrık (discrete) hale getirilmesi gerekliliği.
  - İki örnekleme arasında geçen süre: sampling period (TS).
  - TS'nin çok geniş (seyrek) olması: hafıza ve işlem gücü avantajı, ancak işaretin orijinalliğini kaybetme riski.
  - TS'nin çok dar (sık) olması: hafıza ve hesap gücü (computing) açısından dezavantaj.
- Fourier Analizi
  - Joseph Fourier'in (1800'ler) katkısı: herhangi bir işaret/fonksiyon, farklı frekanslara sahip sonsuz sayıda sinüzoidal bileşenin toplamı şeklinde yazılabilir.
  - Matematiksel gösterim: x(t) = ∫ A(f) · sin(2πft) df (sıfırdan sonsuza frekans aralığı).
  - Her sinüzoidal bileşenin katkısı frekansa bağlı genlik katsayıları (A(f)) ile ifade edilir.
  - Faz farkı (φ) da bileşenler arasında farklılık yaratabilir.
- Sinüzoidal İşaretin Temel Parametreleri
  - Genlik (A): −A ile +A arasındaki salınım.
  - Frekans (f): birim zamanda (1 saniyede) kendini tekrar etme sayısı. Birimi Hertz (Hz).
  - Periyot (T): bir çevrimin tamamlanması için geçen süre, T = 1/f. Frekans ile ters orantılı.
  - Faz (φ): işaretin başlangıç kayması. Sinüs ve kosinüs aynı fonksiyonun aralarındaki φ = 90° faz farkı olan halleridir.
  - Genel ifade: x(t) = A · sin(ωt + φ) = A · sin(2πft + φ). ω = 2πf (radyan cinsinden açısal frekans).
- DC (Doğru Akım) ve AC (Alternatif Akım) Kavramları
  - DC: sabit değer alan, frekansı sıfır olan, salınım yapmayan işaret. Genellikle işaretin ortalamasını verir.
  - AC: salınım yapan, frekansı sıfırdan büyük işaret. Sıfır ortalamalıdır.
  - Bir işaret = DC bileşen (ortalama) + AC bileşen (salınım) şeklinde ayrıştırılabilir. AC bileşen DC seviyesinin üzerine binmiş gibi düşünülür.
  - Şehir şebekesi örnek: Avrupa 220V/50Hz, Amerika 110V/60Hz.
  - Adlandırma tarihsel olarak güç (akım) işaretlerinden gelir, "current" akımı ifade eder.
- Örnekleme Teoremi ve Nyquist Kriteri
  - Gerçek işaretler sonsuz frekansa sahip değildir; kaynağın fiziksel sınırlamaları nedeniyle bir maksimum frekans (fmax) vardır (insan sesi ~4 kHz).
  - En kötü durum (worst case) en yüksek frekanslı sinüzoidal bileşende oluşur: bir çevrimde sadece iki tepe noktası örneklenir.
  - Daha düşük frekanslı bileşenlerde bir çevrimde daha fazla örnek alınır → daha iyi temsil edilir.
  - fmax ile TS arasındaki ilişki: en yüksek frekanslı bileşenin bir çevrim süresi Tmax = 1/fmax olup, iki örnek arası TS ile Tmax arasında TS ≤ Tmax/2 ilişkisi aranır (Nyquist).

## Hocanın Özellikle Vurguladığı Kısımlar

- Örnekleme sıklığı (TS) belirleme
  - Optimal TS değeri: olabilecek maksimum genişlikte olmalı, ancak işaretin temel özelliklerini kaybetmemeli. Dengenin Fourier analizi ve Nyquist kriteri ile kurulması.
- En yüksek frekanslı bileşenin kritik rolü
  - Örnekleme kalitesini belirleyen en kritik unsur fmax'tır; hoca bunu özellikle görsel olarak anlatmış, "en kötü durum burada oluşuyor" diyerek altını çizmiş.
- Frekans-Periyot ters ilişkisi
  - Yüksek frekans → düşük T, düşük frekans → yüksek T. Sınavda bu temel ilişkiyi sorgulayabilecek bir soru gelebilir.

## Kısa Tekrar Notları

- Örnekleme: analog → discrete. TS = 1/fs. Seyrek = bilgi kaybı, sık = fazla hafıza/işlem.
- Fourier: her işaret = farklı frekanslı sinüzoidallerin toplamı.
- Sinüzoidal üçlüsü: Genlik (A), Frekans (f), Faz (φ). Formül: x(t) = A·sin(2πft + φ).
- DC = ortalama (f=0), AC = salınım (f>0, ortalama=0).
- Şebeke: TR 220V/50Hz, ABD 110V/60Hz.
- fmax: kaynağın üretebileceği en yüksek frekans, ondan sonrası sıfır.
- Nyquist: TS ≤ 1/(2·fmax). En kötü durum fmax bileşeninde.

## Detaylı Açıklamalar

Derste lojik devrelerin altyapısını oluşturan sayısal işaret işleme (digital signal processing) kavramları işlenmiştir. Fiziksel dünyadaki işaretler sürekli (analog) yapıdadır ve herhangi iki an arasında sonsuz sayıda değer alır. Bilgisayar bu işaretleri işleyebilmek için ayrıklaştırmaya (discretization) ihtiyaç duyar. İlk adım örnekleme (sampling)'dir. Örnekleme, belirli zaman aralıklarında (TS) işaretin değerini alıp kaydetme işlemidir. TS değerinin belirlenmesi için Fourier analizinden yararlanılır: işaret, farklı frekanslara sahip sinüzoidal bileşenlere ayrıştırılır. Bu bileşenlerden en yüksek frekansa sahip olan (fmax), örnekleme aralığını belirleyen temel unsurdur. Teorik olarak TS'nin, fmax frekansındaki bileşenin periyodunun yarısından küçük veya eşit olması gerekir (Nyquist-Shannon örnekleme teoremi). Eğer TS bu değerden büyük olursa aliasing (örtüşme) meydana gelir ve orijinal işaret kaybedilir. Gerçek hayatta işaretler sonsuz frekans içermez; kaynağın fiziksel karakteristiği bir üst sınır belirler. İnsan sesi için bu sınır yaklaşık 4 kHz'dir.

DC/AC ayrımı da temel bir kavram olarak işlenmiştir. Herhangi bir işaret, sabit bir DC seviye ile sıfır ortalamalı AC salınımın toplamı şeklinde modellenebilir. Bu ayrım Fourier analizindeki f=0 bileşenine (DC) ve f>0 bileşenlerine (AC harmonikleri) karşılık gelir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
