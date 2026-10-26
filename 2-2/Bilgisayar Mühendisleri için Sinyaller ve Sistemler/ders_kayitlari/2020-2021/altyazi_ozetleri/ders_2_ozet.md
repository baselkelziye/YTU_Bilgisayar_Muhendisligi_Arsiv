# Ders 2 Çalışma Özeti

## Genel Konular

- Dersin tarihi 7 Ağustos 2021 Cumartesi. Ders Zoom üzerinden yapıldı. Bu kayıt Cumartesi günün sabah oturumu.
  - Asıl ders yaklaşık 00:06'da başlar.
- Duyuru: Quiz, Cumartesi günleri öğleden sonraki dersin son 40 dakikasında yapılacak. Sistemde soru tanımlama sorunu çözülemezse ilk quiz bir sonraki haftaya ertelenecek.
- Birinci bölümün kalanı: sayıların bilgisayarda gösterimi
  - İşaretsiz tam sayılar, işaret-büyüklük (sign-magnitude), bire tümleyen (one's complement), ikiye tümleyen (two's complement).
  - Kayan noktalı sayılar ve IEEE 754 (tek ve çift duyarlıklı).
  - BCD, Gray kodu, eşlik (parity) denetimi, ASCII ve Unicode.
  - Mantıksal işlemler: AND, OR, NOT, XOR, XNOR.
- MATLAB'a kısa giriş
  - Online MATLAB, değişken tanımlama, vektörler, transpoz, `for` döngüsü, yardım (help) sayfaları.
  - Sembolik matematik: `laplace`, `int`. Grafik çizimi: `plot`.
- Ek kaynak: *Schaum's Outlines: Signals and Systems*. Yaklaşık 571 çözümlü örnek içerir. Ders örnek çözmeye dayandığı için pratik amaçlı önerildi.
- İkinci bölüm: sinyaller ve sistemler
  - Sinyal ve sistem tanımları, örnekler (yay, su tankı, telefon sistemi), alt sistemler, art arda bağlı (cascade) ve bileşik (composite) sistemler.
  - Frekans düzleminin faydası: sinyali sinüzoidal bileşenlerine ayırma (decomposition). Örnek olarak telefon tuş sesleri (DTMF) ve piyano notası incelendi.
  - Geri beslemeli kontrol: araç hız kontrolü, salınım (oscillation).
  - Sinyallerin sınıflandırılması: sürekli/ayrık, analog/sayısal, periyodik/periyodik olmayan, nedensel (causal), tek/çift, deterministik/rastgele.
  - Kosinüs sinyalinin parametreleri: genlik, frekans, periyot, faz.
  - Sistemlerin sınıflandırılması: sürekli zamanlı, ayrık zamanlı, hibrit.
  - Sürekli sinyalden örnekleme ile ayrık sinyal elde etme: $x[n] = x(nT_s)$.
  - Sinyal işlemleri: genlikte ölçekleme ve zamanda ölçekleme (sıkıştırma ve germe), aşağı örnekleme (downsampling) ve yukarı örnekleme (upsampling).

## Hocanın Özellikle Vurguladığı Kısımlar

- **Hangi düzlemde çalıştığınızı bilin.**
  - $x(t)$'den $x[n]$'e, $s$ veya $z$ düzlemine geçtiyseniz sonraki işlemlerde eski değişken ($t$) kalmamalı.
  - Hoca bu hatanın sınavlarda çok yapıldığını söyledi. Yanlış düzleme geçen çözüm doğrudan sıfır alır.
  - Gerekirse en sonda ters dönüşümle eski düzleme dönülür.
- **Gösterim:** Ayrık zamanda köşeli parantez $x[n]$, sürekli zamanda yuvarlak parantez $x(t)$ kullanılır. Sınavlarda bu hata da çok yapılıyor.
- **Genlik ve aralık farkı:** $3\cos(\cdot)$ sinyalinin genliği 3'tür, 6 değildir. Sinyal $-3$ ile $+3$ arasında değişir. Aralığın genişliği 6'dır. Geçen yılın vize sorusunda bazı öğrenciler genliği 6 yazmıştı.
- Bu bölümdeki sınıflandırmalar dönem boyunca kullanılacak. Önemli.
- Ödevler genelde 10-15 satır, en fazla 50 satırlık MATLAB/Python kodu olacak. Çoğunlukla hazır fonksiyon kullanılacak.
- Sınavda derste çözülen örneklere benzer problemler gelecek. Bol örnek çözün.
- İkiye tümleyen günümüzün standardıdır. Tek sıfır vardır ve işaret kontrolü gerekmez.
- Hoca "suggest" kelimesine dikkat çekti. Akademik metinlerde çoğunlukla "öne sürmek, ortaya koymak, göstermek" anlamında kullanılır. "As the name suggests": "adından da anlaşılacağı üzere".

## Kısa Tekrar Notları

- İşaret-büyüklük: en soldaki bit (MSB) işarettir; 1 negatif, 0 pozitif. $+0$ ve $-0$ vardır. Toplama doğrudan çalışmaz.
- Bire tümleyen: negatif sayı, pozitif sayının bütün bitleri ters çevrilerek bulunur. Yine iki sıfır vardır.
- İkiye tümleyen: bitleri ters çevir ve 1 ekle. Kısa yol: sağdan ilk 1'e kadar (o 1 dahil) bitleri aynen yaz, kalanları ters çevir.
- $n$ bit ikiye tümleyen aralığı: $-2^{n-1}$ ile $2^{n-1}-1$. 4 bit: $-8$ ile $+7$. 10 bit: $-512$ ile $+511$.
- IEEE 754 tek duyarlık (32 bit): 1 bit işaret, 8 bit üs, 23 bit kesir; sapma (bias) 127.
- IEEE 754 çift duyarlık (64 bit): 1 bit işaret, 11 bit üs, 52 bit kesir; sapma 1023.
- Değer: $(-1)^s \times 1.F \times 2^{E - \text{bias}}$.
- Gray kodu: art arda gelen iki kod arasında yalnız bir bit değişir.
- Eşlik (parity) biti: iletilen verideki 1'lerin sayısını tek (odd) veya çift (even) yapacak şekilde eklenir. Basit hata denetimidir.
- ASCII: 'A' = 65, 'a' = 97. Büyük ve küçük harf arasında yalnız bir bit farkı vardır.
- XOR: girişler farklıysa 1. XNOR: girişler aynıysa 1. $A \oplus B = A\bar{B} + \bar{A}B$.
- Sinyal: bir veya daha fazla bağımsız değişkene göre değişen büyüklük; matematiksel olarak bir fonksiyon. Sistem: giriş sinyalini çıkış sinyaline dönüştüren yapı.
- Zaman düzleminde konvolüsyon, frekans düzleminde çarpmaya dönüşür. Sistem analizi bu yüzden frekans düzleminde kolaylaşır.
- Kosinüs sinyali: $x(t) = A\cos(\omega t + \varphi)$, $\omega = 2\pi f$, $T = 1/f$.
- Birden çok bileşenli sinyal: $x(t) = \sum_{i=1}^{N} A_i \cos(\omega_i t + \varphi_i)$.
- Periyodik sinyal: her $t$ için $x(t + T) = x(t)$ eşitliğini sağlayan bir $T > 0$ vardır.
- Nedensel (causal) sinyal: $t < 0$ için sıfırdır. Nedensel olmayan (anti-causal) sinyal: $t > 0$ için sıfırdır.
- Çift sinyal: $f(t) = f(-t)$, dikey eksene göre simetrik. Örnek: kosinüs.
- Tek sinyal: $f(-t) = -f(t)$, orijine göre simetrik. Örnek: sinüs.
- Çift-tek ayrışımı: $e(t) = \tfrac{1}{2}[f(t) + f(-t)]$, $o(t) = \tfrac{1}{2}[f(t) - f(-t)]$, $f(t) = e(t) + o(t)$.
- Örnekleme: $x[n] = x(nT_s) = x(n/f_s)$, $n$ tam sayı.
- Genlikte ölçekleme: $a\,x(t)$. $a > 1$ sesi açar, $0 < a < 1$ kısar. Zaman ekseni değişmez.
- Zamanda ölçekleme: $x(bt)$. $b > 1$ sıkıştırır (compression), $0 < b < 1$ gerer (stretching). Genlik değerleri değişmez.
- Ayrık zamanda $x[2n]$ aşağı örneklemedir (örneklerin bir kısmı atılır). $x[n/2]$ yukarı örneklemedir (araya yeni örnekler girer).

## Detaylı Açıklamalar

### İşaretsiz ve işaretli tam sayılar

- 127'nin ikilik karşılığı: $127 = 64 + 32 + 16 + 8 + 4 + 2 + 1$, yani `01111111`.
- İşaret-büyüklükte $+3 + (-3)$: `0011 + 1011 = 1110`. Bu $-6$ olarak okunur, 0 değil. Bu yüzden ek kontrol gerekir.
- Bire tümleyende $+8$ = `00001000`, $-8$ = `11110111`.
  - $+3 + (-3)$ = `111` (3 bitte), yani $-0$. İki sıfır sorunu sürer.
- İkiye tümleyende $-20$ (8 bit):
  - $+20$ = `00010100`.
  - Ters çevir: `11101011`. 1 ekle: `11101100`.
  - Kısa yol: sağdan ilk 1'e kadar `100` aynen kalır, kalan `00010` ters çevrilip `11101` olur. Sonuç `11101100`.
  - $+20 + (-20)$: toplam `1 00000000`. Taşan bit (overflow) atılır, sonuç 0.
- 4 bit ikiye tümleyen tablosu: `0000` = 0, …, `0111` = +7, `1111` = −1, `1110` = −2, …, `1001` = −7, `1000` = −8.

### IEEE 754 örneği: 25,75

- $25 = 11001_2$, $0{,}75 = 0{,}11_2$. Yani $25{,}75 = 11001{,}11_2$.
- Normalleştirme: $1{,}100111 \times 2^4$.
- İşaret $s = 0$. Üs $E = 4 + 127 = 131$ = `10000011`.
- Kesir (23 bit): `10011100000000000000000`.
- Sonuç: `0 10000011 10011100000000000000000` = `0x41CE0000`. Python ile doğrulandı.
- Özel durumlar:
  - Üs 255 ve kesir 0 ise $\pm\infty$.
  - Üs 255 ve kesir sıfırdan farklı ise NaN (not a number).
  - Üs ve kesir 0 ise sıfır. Üs 0, kesir sıfırdan farklıysa normal olmayan (denormalized) sayı.
- Tek duyarlık yaklaşık 7 ondalık basamak, çift duyarlık yaklaşık 15-16 basamak hassasiyet verir.

### Telefon tuş sesleri (DTMF)

- Her tuş iki sinüzoidin toplamıdır (dual tone multi frequency).
  - Satır frekansları: 697, 770, 852, 941 Hz.
  - Sütun frekansları: 1209, 1336, 1477 Hz.
- Örnekler: 1 = 697 + 1209 Hz, 2 = 697 + 1336 Hz, 3 = 697 + 1477 Hz, 9 = 852 + 1477 Hz.
- Ses dosyasından hangi tuşa basıldığını bulmak için:
  - Her tuş sesinin bulunduğu parça (bir dizi) alınır.
  - Frekans düzlemine geçilir ve iki frekans bileşeni bulunur.
  - Frekans tablosundan tuş belirlenir.
- Bileşenleri toplayıp sinyal oluşturmak kolaydır. Toplam sinyali zaman düzleminde bileşenlerine ayırmak zordur. Frekans düzlemi bu ayrımı kolaylaştırır.
- Neden iki ton? Hat frekans aralığı sınırlıdır. Tek tonla birbirine yakın frekanslar kullanılırsa hata olasılığı artar. İki ton hatayı azaltır.

### Frekans düzleminin faydaları

- Sinyalin hangi frekansları içerdiğini gösteren genlik spektrumu elde edilir.
- Piyano notası örneği: Tuşa basıldığında ses yükselir, tepe yapar, sönümlenir ve kaybolur. Ses bir saniyelik dilimde incelendi. Notalar (do, re, mi…) birden çok frekansın birleşimidir.
- Ayırt edici öznitelik çıkarma (distinctive feature extraction): Parmak izi veya ses imzası gibi uygulamalar sinyalin karakteristiğini zaman veya frekans düzleminde çıkarır. Bu, yapay zeka ve makine öğrenmesinin temelidir.
- Doğrusal sistemler frekans düzleminde kolay analiz edilir.
  - Girişin ve sistemin frekans karşılıkları çarpılır, çıkışın frekans karşılığı bulunur.
  - Ters dönüşümle zaman düzlemindeki çıkışa geçilir.
  - Diferansiyel denklem çözmekten daha kolaydır.
- Sistemin kararlı (stable) olup olmadığı frekans düzleminde incelenir. Tacoma Narrows köprüsü, rüzgârın yol açtığı titreşimler ve kararsız mekanik yapı yüzünden çöktü.

### Geri beslemeli hız kontrolü

- Giriş: gaz pedalı $x(t)$. Çıkış: aracın hızı.
- İstenen hız ile ölçülen hız arasındaki fark hata (error) olarak alınır. Hata bir katsayıyla çarpılıp gaz olarak sisteme geri verilir.
- Aç-kapa (on-off) kontrolde sistem iki eşik arasında gidip gelir. Buna salınım (oscillation) denir. Salınım cihazları yıpratır. İyi bir kontrolcü hatayı adım adım azaltıp sistemi istenen değere oturtur.

### Kosinüs sinyali örneği: $x(t) = 3\cos(2\pi \cdot 2t - 3\pi/4)$

- Genlik: 3. Sinyal $[-3, 3]$ aralığında değişir.
- Frekans: $f = 2$ Hz. Periyot: $T = 0{,}5$ s. Açısal frekans: $\omega = 4\pi$ rad/s.
- Faz: $\varphi = -3\pi/4$ rad.
- İlk tepe noktası: $4\pi t - 3\pi/4 = 0$ için $t = 3/16$ s. Sonraki tepeler $3/16 + 0{,}5k$ s'dedir.
- Bu sinyal 4 bitle nicemlenirse 16 seviye olur. Adım: $\Delta = 6/16 = 0{,}375$.

### Sinyal özellikleri örneği

$$f(t) = \begin{cases} \dfrac{\sin(2\pi t)}{t}, & t \ge 1 \\ 0, & t < 1 \end{cases}$$

- Sürekli zamanlı ve analog.
- Periyodik değil: $t < 1$ için sıfırdır ve genliği $1/t$ ile azalır.
- Sonsuz uzunlukta (sağ tarafa doğru sınırsız).
- Nedensel: $t < 0$ için sıfırdır.
- Ne tek ne çift.
- Deterministik: Her $t$ için değeri bir formülle kesin olarak bellidir.

### Bu sinyali MATLAB'da çizdirme

```matlab
clc
clear all
close all

t1 = 1:0.01:10;
t2 = -10:0.01:1-0.01;
timeAxis = [t2 t1];
MySignal = [zeros(1,length(t2)) sin(2*pi*t1)./t1];
plot(timeAxis,MySignal)
ylabel('Amplitude', 'fontsize', 20)
xlabel('time', 'fontsize', 20)
title('My First Signal','fontsize', 20)
```

- `t1` 901 elemanlı, `t2` 1100 elemanlı bir vektördür. Python ile sayıldı.
- `[t2 t1]` iki vektörü birleştirir (concatenation).
- `./` eleman eleman bölmedir. Her $\sin$ değeri karşılık gelen $t$ değerine bölünür.
- Sonuç: $t < 1$'de sıfır, sonrasında sönümlü sinüzoidal dalga.

### Çift-tek ayrışımı örneği

- Sinyal: $-1 \le t < 0$ aralığında $f(t) = t + 1$ (0'dan 1'e çıkan rampa), $0 \le t \le 1$ aralığında $f(t) = 1$, diğer yerlerde 0.
- Çift kısım: $2e(t) = f(t) + f(-t)$. Değeri $t = 0$'da 2, $|t| = 1$'de 1. Yani $0 < |t| < 1$ için $e(t) = 1 - |t|/2$.
- Tek kısım: $2o(t) = f(t) - f(-t)$. $-1 < t < 1$ aralığında $2o(t) = t$, yani $o(t) = t/2$.
- Sağlama: $0 < t < 1$ için $e(t) + o(t) = 1 - t/2 + t/2 = 1$. Bu, orijinal sinyaldir.
- $f(t) = 3t$ örneği: Çift kısmı sıfırdır. Sinyalin tamamı tek kısımdır.

### Sürekli sinyali örnekleme

- $x(t) = 5t$, $f_s = 500$ Hz: $T_s = 1/500$ s. $x[n] = 5 \cdot n/500 = n/100$.
- $x(t) = \cos(2\pi \cdot 500 t)$: Genlik 1, $f = 500$ Hz, $\omega = 1000\pi$ rad/s, faz 0.
  - Nyquist'e göre $f_s > 1000$ Hz olmalı.
  - $f_s = 1000$ Hz ile örneklenirse: $x[n] = \cos(\pi n) = (-1)^n$.
- $n$ yalnız tam sayı değerler alır ($\dots, -1, 0, 1, 2, \dots$).

### Zamanda ölçekleme ve örnek sayısı

- $x(2t)$: $t = 1$'deki değer artık $t = 0{,}5$'te görülür. Sinyal sıkışır.
- Hoca, YouTube'da 2 kat hızla dinlemeyi zamanda sıkıştırmaya benzetti. Hızlandırınca insan sesi anlaşılır kalır, enstrüman seslerinde bozulma daha çok duyulur.
- $x[2n]$: $n = 1$'deki örnek atılır, $n = 2$'deki örnek $n = 1$'e gelir. $n = -1$'deki örnek atılır, $n = -2$'deki örnek $n = -1$'e gelir.
- $x[n/2]$: Araya yeni örnekler eklenmesi gerekir. Görüntüyü yakınlaştırmak (zoom) da benzer bir işlemdir. Vektörel formatlarda yakınlaştırınca bozulma olmaz.

### Sistem türleri

- Sürekli zamanlı sistem: giriş ve çıkışı sürekli. Örnek: FM/AM radyo, mekanik araçlar.
- Ayrık zamanlı sistem: giriş ve çıkışı ayrık. Örnek: bilgisayar oyunu, MATLAB, kredi (mortgage) hesabı.
- Hibrit sistem: ADC ve DAC içerir. Örnek: araçtaki dış sıcaklık göstergesi, ticari ve askeri uçaklar.
- Ses kartı örneği: Ses örneklenir, bilgisayarda bir katsayıyla çarpılır (`A = A*10`, sesi açmak), sonra DAC ile hoparlöre verilir.
- Haberleşme sistemi: mesaj, verici, kanal, alıcı.
- Kontrol sistemi: referans giriş, kontrolcü, kontrol edilen sistem (plant), sensör ve geri besleme.

### Ders sonrası notlar

- **Kosinüs "doğal", sinüs "sonradan üretilmiş" değildir.** Derste kosinüsün doğal sinyal olduğu için kullanıldığı söylendi.
  - Sinüs ve kosinüs aynı dalga biçimidir. Aralarında yalnız $\pi/2$ faz farkı vardır: $\sin(\omega t) = \cos(\omega t - \pi/2)$.
  - Kosinüs bir gelenek olarak kullanılır. $A\cos(\omega t + \varphi)$, karmaşık üstel $Ae^{j(\omega t + \varphi)}$ ifadesinin gerçel kısmıdır. Fazör gösterimi bunun üzerine kurulur.
- **Faz:** Derste faz, "$t = 0$ anında sinyalin ulaştığı genlik değeri" diye anlatıldı.
  - Faz, kosinüsün içindeki açı sabitidir. Bu örnekte $\varphi = -3\pi/4$ rad.
  - $t = 0$'daki genlik ayrı bir değerdir: $x(0) = 3\cos(-3\pi/4) = -3\sqrt{2}/2 \approx -2{,}12$.
- **Periyodiklik:** Derste $f(t) = \sin(2\pi t)/t$ ($t \ge 1$) örneği için "sinüzoidal dalgaların hiçbiri periyodik olmaz" dendi.
  - Saf sinüzoidler periyodiktir.
  - Bu sinyal $t<1$ için sıfır olduğu için periyodik değildir. Genliği $1/t$ ile azaldığı için de periyodik değildir.
- **Periyodik olmayan sinyal:** Doğru tanım şudur: Her $t$ için $x(t+T) = x(t)$ eşitliğini sağlayan hiçbir $T > 0$ yoksa sinyal periyodik değildir. En küçük böyle $T$ değerine temel periyot denir.
- **Tek sinyalin simetrisi:** Derste tek sinyalin "x eksenine göre" simetrik olduğu söylendi. Tek sinyal orijine göre simetriktir.
- **Tek sinyalin ayrışımı:** Derste tek sinyal için formülün "$-f(t)$ verdiği" söylendi. Tek sinyalde $o(t) = \tfrac{1}{2}[f(t) - f(-t)] = \tfrac{1}{2}[f(t) + f(t)] = f(t)$ olur; formül sinyalin kendisini verir.
- **"Causal" kelimesinin kökeni:** Derste "kaos" kelimesinden geldiği söylendi. Kelime Latince *causa* (neden) kökünden gelir; "chaos" ile ilgisi yoktur.
- **Nedensel sistem örneği:** Derste $x[n] = x[n-1] + 2x[n]$ yazıldı. Bu ifade tutarlı bir sistem tanımlamaz. Nedensel bir sistem örneği: $y[n] = 2x[n] + x[n-1]$. Çıkış yalnız şimdiki ve geçmiş girişlere bağlıdır.
- **İkiye tümleyen aralığı:** Derste pozitif sınır "$2^n - 1$", negatif sınır "$-2^n$" diye söylendi. $n$ bit için doğru aralık $-2^{n-1}$ ile $2^{n-1} - 1$'dir. 4 bitte $-8$ ile $+7$.
- **IEEE 754 sapması:** Derste 127 değeri "$2^8 - 1 - 1$" diye açıklandı, sonra düzeltildi. Doğrusu $2^{8-1} - 1 = 127$. Çift duyarlıkta $2^{11-1} - 1 = 1023$.
- **Üs alanı 0:** Derste "$2^{-127}$ üs alanında 00…0 ile gösterilir" dendi. Üs alanının sıfır olması sıfır ve normal olmayan sayılar için ayrılmıştır. Normal sayılarda en küçük üs $-126$'dır.
- **Sayı aralığı:** Çift duyarlığın aralığı yaklaşık $10^{\pm 308}$'dir. Derste "306" dendi. Tek duyarlıkta yaklaşık $10^{\pm 38}$.
- **NaN:** Derste NaN'ın genelde taşmadan (overflow) çıktığı söylendi. Taşma $\pm\infty$ verir. NaN, $0/0$ veya $\infty - \infty$ gibi tanımsız işlemlerden çıkar.
- **BCD:** Derste BCD, 0000'dan 1111'e kadar sayma diye anlatıldı ve 57'yi 5 ve 7 olarak ayrı saklamanın "pek geçerli olmadığı" söylendi.
  - BCD'nin tanımı tam olarak budur: Her ondalık rakam ayrı ayrı 4 bitle (8421) kodlanır. 57 = `0101 0111`.
  - BCD'de yalnız `0000`-`1001` kullanılır. `1010`-`1111` geçersizdir.
- **ASCII:** Derste 'a' için verilen ikilik değer altyazıda bozuk geçiyor.
  - 'A' = 65 = `01000001`, 'a' = 97 = `01100001`. Fark değeri 32 olan bittir.
  - ASCII 7 bitlik bir koddur (128 karakter): 95 basılabilir karakter (boşluk dahil) ve 33 kontrol karakteri.
  - DEL karakteri 127 = `1111111` (7 bitin hepsi 1).
- **Unicode:** Derste Unicode'un 16 bit ve 65 536 karakter olduğu söylendi. Bu ilk sürümler için doğrudur. Bugün Unicode 1 114 112 kod noktasını kapsar ve UTF-8/UTF-16/UTF-32 ile kodlanır.
- **MATLAB `laplace` örneği:** Derste "$1/x^2$'nin Laplace dönüşümü $\sqrt{\pi/s}$" dendi. Dokümantasyondaki örnek $1/\sqrt{t}$ içindir: $\mathcal{L}\{t^{-1/2}\} = \sqrt{\pi/s}$. $1/t^2$'nin Laplace dönüşümü tanımlı değildir; integral $t = 0$ civarında ıraksar.
- **Tam Nyquist frekansında örnekleme:** $\cos(2\pi \cdot 500 t)$, $f_s = 1000$ Hz ile örneklendiğinde $(-1)^n$ elde edilir. Aynı frekanstaki $\sin(2\pi \cdot 500 t)$ ise $\sin(\pi n) = 0$ verir; bütün bilgi kaybolur. Bu yüzden $f_s$, $2f_{max}$'tan kesin olarak büyük olmalıdır.
- **Yukarı örnekleme:** $x[n/2]$ yalnız çift $n$ için tanımlıdır. Tek $n$ değerlerine standart tanımda 0 yazılır. Ardından ara değerleme (interpolation) filtresiyle aralar doldurulabilir.
- **Hızlı oynatma:** YouTube'daki hız ayarı basit bir aşağı örnekleme değildir. Ses perdesini korumak için zaman germe/sıkıştırma (time-stretching) algoritmaları kullanılır. Derste yalnız sezgi için benzetme yapıldı.
- **DTMF:** Derste 3 tuşu için bir yerde "1697 Hz" geçiyor. Doğrusu 697 Hz ve 1477 Hz.
- **Hooke yasası:** Derste yay örneğinde $F = -kx$ hatırlatıldı. İşaret, yay kuvvetinin uzamaya ters yönde olduğunu gösterir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
