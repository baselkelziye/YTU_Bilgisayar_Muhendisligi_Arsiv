# Ders 21 Çalışma Özeti

## Genel Konular

- Seçiciler (multiplexer, MUX)
  - $2^n \times 1$ MUX: $2^n$ veri girişi ($I_0 \ldots I_{2^n-1}$), tek çıkış ($Z$) ve $n$ seçim ucu ($S_{n-1} \ldots S_0$) vardır.
  - Seçim uçlarına verilen ikili sayının ondalık değeri hangi girişin çıkışa aktarılacağını belirler. İçeride döner bir anahtar varmış gibi düşünülebilir.
  - $4 \times 1$ MUX için: $Z = I_0\,\overline{S_1}\,\overline{S_0} + I_1\,\overline{S_1}\,S_0 + I_2\,S_1\,\overline{S_0} + I_3\,S_1 S_0$.
- MUX ile Boole fonksiyonu gerçekleme
  - Fonksiyon önce mintermlerin toplamı olarak yazılır.
  - Seçim ucu olarak verilen değişkenlerin dört kombinasyonu ortak paranteze alınır; parantez içinde kalan ifadeler MUX girişlerine bağlanır.
  - Seçim uçlarının seçimi devrenin maliyetini doğrudan etkiler: aynı fonksiyon bir seçimde ek kapılar ister, başka bir seçimde hiç kapı istemez.
- Dağıtıcılar (demultiplexer, DEMUX)
  - $1 \times 2^n$ yapıdadır: tek giriş, $2^n$ çıkış ($Z_0 \ldots Z_{2^n-1}$). Seçim uçları girişin hangi çıkışa gideceğini belirler.
  - MUX ile DEMUX tek bir ortak hat (medium) üzerinden çok sayıda kullanıcıyı bağlayan basit bir santral örneğiyle anlatıldı.
- Kod çözücü (decoder)
  - $n \times 2^n$ yapıdadır: $n$ bitlik girişin değerine karşılık gelen tek çıkışı aktif yapar.
  - Normal çıkışlı kod çözücüde seçilen çıkış 1, diğerleri 0'dır. Tümleyen (değil) çıkışlıda seçilen çıkış 0, diğerleri 1'dir (0 aktif).
  - Her çıkış bir mintermi ürettiği için kod çözücü ve VEYA kapılarıyla herhangi bir fonksiyon gerçeklenebilir; tam toplayıcı örneği yapıldı.
- Kodlayıcı (encoder)
  - $2^n \times n$ yapıdadır: kod çözücünün tersidir. Ek olarak bir "Hazır" (Ready) çıkışı vardır.
  - $4 \times 2$ kodlayıcı örneğinde çıkış, 1 olan en yüksek ağırlıklı girişin numarasını verir; bütün girişler 0 ise Ready = 0'dır.
- Aritmetik Lojik Birim (ALU)
  - Hem aritmetik hem lojik işlem yapan birimdir. A ve B ($n$ bit) girişleri, F ($n$ bit) çıkışı ve $m$ bitlik işlem kodu vardır; $2^m$ işlem tanımlanabilir.
  - Örnek: 4 bitlik A ve B, elde girişi/çıkışı, 2 bitlik işlem kodu ($M_1M_0$) olan 4 işlemli bir ALU'nun kavramsal tasarımı.
- Yedi parçalı gösterge (seven segment display) sürücüsü
  - 4 bitlik BCD girişini a–g parçalarını süren 7 çıkışa çeviren kombinezonsal devre; 10–15 girişleri "önemsiz" (don't care) durumdur.
- Tampon (buffer) ve yüksek empedans
  - İki çıkış aynı hatta doğrudan bağlanamaz. Ortak hatta bağlanacak çıkışlar için üç durumlu tamponlar kullanılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bit sıralamasına dikkat
  - Örnekte en ağırlıklı bit $X_1$, en az ağırlıklı bit $X_4$'tür. MUX'ta daha ağırlıklı seçim değişkeni $S_1$'e, daha az ağırlıklı olan $S_0$'a bağlanmalıdır.
- Seçim uçlarının seçimi çok önemli
  - Aynı fonksiyon $X_3X_4$ seçim uçlarıyla VE, XOR, DEĞİL, VEYA kapıları gerektirirken, $X_1X_2$ seçim uçlarıyla girişlere yalnız $X_3$, $X_4$, 1 ve 0 bağlanarak tek bir MUX ile gerçeklenir.
- MUX ile gerçekleme "en verimli" devre olmayabilir
  - Karnaugh ile indirgenmiş devre de aynı çıkışı verir; MUX yöntemi farklı bir tasarım yoludur.
- Kod çözücünün mantığı
  - Verilen giriş değerine karşılık gelen tek çıkış aktif olur; tümleyen çıkışlıda aktif seviye 0'dır.
- Çıkışlar ortak hatta doğrudan bağlanmaz
  - Bir çıkış 1, öteki 0 verirse yüksek gerilimden düşük gerilime doğrudan yol oluşur. Bunun için tampon ya da pull-up direnci (açık kolektörlü çıkış) kullanılır.

## Kısa Tekrar Notları

- $2^n \times 1$ MUX: $n$ seçim ucu; seçim değeri $k$ ise $Z = I_k$.
- MUX ile gerçekleme: mintermleri yaz, seçim değişkenlerine göre ortak paranteze al, parantez içlerini sadeleştir, girişlere bağla.
- Örnek $f = \sum m(2,3,5,7,8,9,10,11)$:
  - Seçim $X_3X_4$: $I_0 = X_1\overline{X_2}$, $I_1 = X_1 \oplus X_2$, $I_2 = \overline{X_2}$, $I_3 = \overline{X_1} + \overline{X_2}$.
  - Seçim $X_1X_2$: $I_0 = X_3$, $I_1 = X_4$, $I_2 = 1$, $I_3 = 0$.
- DEMUX $1 \times 2^n$: tek girişi seçilen çıkışa yollar.
- Kod çözücü $n \times 2^n$: her çıkış bir minterm. Tam toplayıcı: $T = D_1 + D_2 + D_4 + D_7$, $E_{\text{ç}} = D_3 + D_5 + D_6 + D_7$.
- Kodlayıcı $2^n \times n$ + Ready çıkışı.
- ALU: veri girişleri, işlem kodu, elde girişi/çıkışı; işlem blokları paralel çalışır, sonuç MUX'larla seçilir.
- Yedi parçalı gösterge: 10 rakam için 4 bit gerekir, 6 kombinasyon boşta kalır ve önemsiz durum olur.
- Tampon: çıkış izni aktifse çıkış = giriş, değilse çıkış yüksek empedanstır (hat kopuk gibi davranır).

## Detaylı Açıklamalar

- **MUX ile fonksiyon gerçekleme örneği.** Dört değişkenli $f(X_1,X_2,X_3,X_4)$ doğruluk tablosuyla verilmiştir (ekrandan, 00:15:00). Fonksiyon 2, 3, 5, 7, 8, 9, 10, 11 numaralı satırlarda 1'dir. Soru: $4 \times 1$ MUX kullanarak, $X_3$ ve $X_4$ seçim uçları olacak şekilde $f$'yi gerçekleyiniz. Mintermler yazılıp $\overline{X_3}\,\overline{X_4}$, $\overline{X_3}X_4$, $X_3\overline{X_4}$, $X_3X_4$ parantezlerine alınır (ekrandan, 00:25:00):
  - $f = \overline{X_3}\,\overline{X_4}(X_1\overline{X_2}) + \overline{X_3}X_4(\overline{X_1}X_2 + X_1\overline{X_2}) + X_3\overline{X_4}(\overline{X_1}\,\overline{X_2} + X_1\overline{X_2}) + X_3X_4(\overline{X_1}\,\overline{X_2} + \overline{X_1}X_2 + X_1\overline{X_2})$
  - Sadeleştirme: ikinci parantez $X_1 \oplus X_2$, üçüncü parantez $\overline{X_2}(\overline{X_1} + X_1) = \overline{X_2}$, dördüncü parantez $\overline{X_1} + X_1\overline{X_2} = \overline{X_1} + \overline{X_2}$ olur.
  - Devre: $I_0$'a VE kapısı ($X_1$, $\overline{X_2}$), $I_1$'e XOR kapısı, $I_2$'ye $\overline{X_2}$, $I_3$'e girişleri değillenmiş bir VEYA kapısı bağlanır; $S_1 = X_3$, $S_0 = X_4$ (ekrandan, 00:30:00).
- **Seçim uçlarını değiştirmek.** Aynı fonksiyon $X_1$ ($S_1$) ve $X_2$ ($S_0$) ile seçilirse $\overline{X_1}\,\overline{X_2}$ grubunda $X_3\overline{X_4} + X_3X_4 = X_3$, $\overline{X_1}X_2$ grubunda $\overline{X_3}X_4 + X_3X_4 = X_4$, $X_1\overline{X_2}$ grubunda dört terimin hepsi bulunduğu için 1 kalır; $X_1X_2$ grubunda hiç minterm yoktur, 0 olur (ekrandan, 00:35:00 ve 00:40:00). Böylece MUX'un girişlerine $X_3$, $X_4$, 1, 0 bağlanır ve hiç ek kapı gerekmez. Sonuçlar python ile doğruluk tablosu üzerinden kontrol edildi.
- **DEMUX ve santral örneği.** Solda $2^n \times 1$ MUX'a bağlı abonelerden biri seçilir, ortak hat (kablo, fiber vb.) üzerinden sağdaki $1 \times 2^n$ DEMUX'a gelir ve DEMUX'un seçim uçlarıyla karşı taraftaki abone seçilir. Örneğin solda 000 ($I_0$), sağda 011 ($Z_3$) seçilirse bu iki abone hattı kullanır; sonra solda 010, sağda 101 seçilince $I_2$ ile $Z_5$ bağlanır (ekrandan, 00:50:00).
- **Kod çözücü.** $3 \times 8$ kod çözücüde $XYZ = 000$ iken yalnız $D_0 = 1$, $101$ iken yalnız $D_5 = 1$, $111$ iken yalnız $D_7 = 1$ olur. Tümleyen çıkışlıda $111$ girişinde yalnız $D_7 = 0$, diğerleri 1'dir (ekrandan, 00:55:00).
- **Kod çözücüyle tam toplayıcı.** $T(E_g,a,b) = \sum m(1,2,4,7)$, $E_{\text{ç}}(E_g,a,b) = \sum m(3,5,6,7)$ (ekrandan, 01:00:00). $E_g$ en ağırlıklı, $b$ en az ağırlıklı giriş olacak şekilde $3 \times 8$ kod çözücüye bağlanır. $D_1, D_2, D_4, D_7$ dört girişli bir VEYA kapısına girerek toplamı, $D_3, D_5, D_6, D_7$ ikinci bir dört girişli VEYA kapısına girerek elde çıkışını üretir (ekrandan, 01:05:00).
  - Ders sonrası not: Hoca girişlerin sırası değişirse farklı değerler çıkacağını söyledi. Genel olarak bu doğrudur, ama toplam ve elde fonksiyonları üç girişe göre simetrik olduğu için tam toplayıcıda minterm listeleri sıradan etkilenmez (python ile kontrol edildi).
- **Kodlayıcı.** $4 \times 2$ kodlayıcıda girişler $I_3$ (en ağırlıklı) … $I_0$, çıkışlar $X$, $Y$ ve Ready'dir (ekrandan, 01:15:00). Bütün girişler 0 iken $X$, $Y$ belirsiz ve Ready = 0'dır. 0001 için çıkış 00, $001\phi$ için 01, $01\phi\phi$ için 10, $1\phi\phi\phi$ için 11 ve Ready = 1 olur; yani çıkış 1 olan en yüksek basamağın numarasını verir. <!-- BELİRSİZ: kodlayıcı tablosunun dolu hali karelerde görünmüyor; satırlar altyazıdan kuruldu -->
- **ALU kavramsal tasarımı.** Örnekte 4 bitlik A, B; elde girişi $E_g$, elde çıkışı; 4 bitlik çıkış F ve 2 bitlik işlem kodu $M_1M_0$ vardır (ekrandan, 01:20:00). İşlemler: 00'da $A + B$, 10'da $\overline{A}$ (1'e tümleyen), 11'de A'nın 1 bit sağa ötelenmesi ($E_g \to F_3$, $A_3 \to F_2$, $A_2 \to F_1$, $A_1 \to F_0$, $A_0 \to$ elde çıkışı). <!-- BELİRSİZ: 01 işlem kodunun anlamı altyazıda söylenmiyor; blok sırasına göre büyük olasılıkla çıkarma (A − B) --> Tam toplayıcı (TT), tam çıkarıcı (TÇ), tümleyici ve öteleyici blokları aynı anda çalışır; her çıkış bitini $M_1M_0$ ile seçen dört adet $4 \times 1$ MUX sonucu F'ye aktarır (ekrandan, 01:25:00 ve 01:30:00).
- **Yedi parçalı gösterge sürücüsü.** Parçalar a–g ile adlandırılır; her parça bir LED'dir ve 1 verildiğinde yanar. 0 için a–f yanar, g yanmaz; 1 için yalnız b ve c yanar; 9 için e dışındaki bütün parçalar yanar; 2 için a, b, g, e, d yanar (ekrandan, 01:40:00). Her çıkış için ayrı bir Karnaugh haritası çizilir; derste yalnız a çıkışı tablonun bir kısmıyla gösterildi ve tahtada $a = X_1 + (X_2 \odot X_4)$ bulundu (ekrandan, 01:45:00).
  - Ders sonrası not: Tahtadaki ifade yalnız doldurulan satırlara (0, 1, 9) göredir. 0–9 satırlarının tamamı yazıldığında 3 ve 6 rakamlarında da a parçası yandığı için ifade $a = X_1 + X_3 + (X_2 \odot X_4)$ olur (python ile kontrol edildi).
- **Tampon ve yüksek empedans.** Tamponun bir girişi, bir çıkışı ve bir çıkış izni (enable) ucu vardır (ekrandan, 01:50:00). 1 aktif tamponda çıkış izni 1 iken çıkış = giriş, 0 iken çıkış yüksek empedanstır. 0 aktif tamponda (enable ucunda yuvarlak) bunun tersidir. Yüksek empedans, çok büyük bir direnç ya da hattın kopması gibidir; o çıkıştan akım akmaz, böylece aynı hatta bağlı çıkışlardan yalnız biri hattı sürer.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
