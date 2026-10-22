# Ders 6 Çalışma Özeti

## Genel Konular

- Kaydın ilk kısmı (yaklaşık ilk 2 saat 27 dakika) laboratuvar oturumudur. Ders anlatımı bundan sonra başlar.
  - Laboratuvar duyuruları (laboratuvar sorumlusu):
    - Sorular Google Classroom üzerinden paylaşılıyor. Çözümler Google Form ile, saat 19:30'a kadar yükleniyor.
    - Dosya adı "öğrencinumarası_soyad" biçiminde olmalı. Yükleme sonrası doğrulama e-postası gelir; gelmediyse yükleme tamamlanmamıştır.
    - Çözümlerde formülleri, ara hesapları ve birimleri yazın. Simülatör (Proteus) ekran görüntülerini ekleyin.
    - Yüklemeyi son dakikaya bırakmayın.
- Geçen haftanın tekrarı: Thevenin eşdeğerini bulma yöntemleri
  - Yöntem 1: art arda kaynak dönüşümü.
  - Yöntem 2: $V_{TH} = V_{OC}$, $R_{TH} = \frac{V_{OC}}{I_{SC}}$.
  - Yöntem 3: bağımsız kaynakları sıfırlayıp terminallerden eşdeğer direnç.
  - Yöntem 4: bağımlı kaynak varsa, bağımsız kaynakları sıfırlayıp test kaynağı ile $R_{TH} = \frac{v_{test}}{i_{test}}$.
- Maksimum güç aktarımı
  - İç direnci $R_S$ olan $V_S$ kaynağına bağlı $R_L$ yükünün gücü:
    - $P_L = I_L^2 R_L = \frac{V_S^2 R_L}{(R_S + R_L)^2}$.
  - Maksimum için türev sıfıra eşitlenir:
    - $\frac{dP_L}{dR_L} = V_S^2 \frac{(R_S + R_L)^2 - 2R_L(R_S + R_L)}{(R_S + R_L)^4} = 0$.
    - $R_S + R_L = 2R_L$, yani $R_L = R_S$.
  - Maksimum güç: $P_{max} = \frac{V_S^2}{4R_S}$.
  - Bu durumda kaynağın verdiği gücün yarısı iç dirençte, yarısı yükte harcanır. Verim %50'dir.
  - Genelleme: herhangi bir doğrusal devre önce Thevenin eşdeğerine indirgenir. Yük $R_L = R_{TH}$ olduğunda maksimum güç çeker: $P_{max} = \frac{V_{TH}^2}{4R_{TH}}$.
- Örnek 22: maksimum güç, BJT ortak emetörlü yükselteç küçük sinyal modeli
  - Devre: giriş kaynağı $2.5\sin(440t)$ mV ve seri 300 Ω. Ardından paralel 17 kΩ ve 5 kΩ, bunların uçlarındaki gerilim $v_\pi$.
  - Çıkış tarafı: bağımlı akım kaynağı $0.03\,v_\pi$, ona paralel 1 kΩ ve yük $R_L$.
  - Giriş tarafı: $17\text{k} \parallel 5\text{k} \approx 3864$ Ω. Gerilim bölücü: $v_\pi = 2.5\sin(440t)\,\text{mV} \cdot \frac{3864}{300 + 3864}$.
  - $R_{TH}$: giriş kaynağı sıfırlanınca $v_\pi = 0$, bağımlı kaynak açık devre gibi davranır. $R_{TH} = 1$ kΩ.
  - $V_{TH}$: açık devrede bağımlı kaynağın akımı 1 kΩ'dan akar. $v_{oc} = -0.03\,v_\pi \cdot 1000 = -30\,v_\pi$.
  - Maksimum güç için $R_L = 1$ kΩ. $P_{max} = \frac{v_{oc}^2}{4R_{TH}} \approx 1.211\sin^2(440t)$ µW.
- Örnek 23: bağımlı kaynaklı devrede süperpozisyon
  - Devre: 4 A akım kaynağı, 3 Ω, 2 Ω, 1 Ω, bağımlı gerilim kaynağı $5\,i_o$, $i_o$'ın aktığı 5 Ω, 4 Ω ve 20 V kaynak.
  - Bağımsız kaynaklar tek tek bırakılır. Bağımlı kaynak her iki alt devrede de kalır.
  - Yalnız 4 A: $i_o' \approx 3.059$ A. Yalnız 20 V: $i_o'' \approx -3.529$ A.
  - Toplam: $i_o = i_o' + i_o'' \approx -0.4706$ A.
  - Hoca çevre denklemlerini matris biçiminde kurdu, sayısal çözümü öğrencilere bıraktı.
- Örnek 24: bağımlı akım kaynağı ile kaynak dönüşümü
  - Devre: 6 V kaynak ve seri 2 Ω, ortada uçlarında $v_x$ ölçülen 2 Ω, 4 Ω ile seri 18 V kaynak, bağımlı akım kaynağı $0.25\,v_x$.
  - Gerilim kaynakları akım kaynağına çevrilir. $v_x$'in tanımlı olduğu 2 Ω dönüşüme sokulmaz.
  - Tek düğüm denklemi: $\frac{v_x - 6}{2} + \frac{v_x}{2} + \frac{v_x - 18}{4} - 0.25\,v_x = 0$.
  - Sonuç: $v_x = 7.5$ V.
- Örnek 25: bağımlı kaynaklı devrenin Thevenin ve Norton eşdeğeri
  - Devre: 5 A kaynak, uçlarında $v_x$ olan 4 Ω, 2 Ω, bağımlı gerilim kaynağı $2v_x$, 6 Ω ve $a$ ucuna giden 2 Ω.
  - $V_{TH}$: bağımlı gerilim kaynağı iki düğümü bağlar, süper düğüm kurulur.
    - Süper düğüm: $5 = \frac{V_1}{4} + \frac{V_2}{6}$. Kısıt: $V_2 = 3V_1$.
    - Hoca ilk denemede bir işaret hatasıyla $-4$ V buldu, sonra düzeltti. Doğru sonuç $V_{TH} = 20$ V.
  - $R_{TH}$: 5 A sıfırlanır (açık devre), uçlara 1 V test kaynağı bağlanır. $R_{TH} = 6$ Ω.
  - Norton: $I_N = \frac{20}{6} = \frac{10}{3}$ A, $R_N = 6$ Ω.
- Kapasite (kondansatör)
  - Yapı: iki iletken plaka arasında yalıtkan (dielektrik). Yük depolar.
  - Temel bağıntılar:
    - $q = Cv$, $i = C\frac{dv}{dt}$.
    - Depolanan enerji: $w = \frac{1}{2}Cv^2 = \frac{q^2}{2C}$.
  - Davranış:
    - Kapasite gerilimi ani değişemez (süreklidir). Ani değişim sonsuz akım gerektirir.
    - DC'de, kalıcı durumda akım sıfırdır. Kapasite açık devre gibi davranır.
  - Şarj ve deşarj (RC devresi):
    - Zaman sabiti $\tau = RC$.
    - Şarj: $v(t) = V\left(1 - e^{-t/\tau}\right)$. Deşarj: $v(t) = Ve^{-t/\tau}$.
    - Yaklaşık $5\tau$ sonra kapasite tam dolmuş ya da boşalmış kabul edilir.
  - Pratik bilgiler:
    - Seramik kapasitelerde kod: ilk iki rakam değer, üçüncü rakam 10'un kuvveti, birim pF. Ör. 102 = $10 \cdot 10^2$ pF = 1000 pF = 1 nF.
    - Elektrolitik kapasiteler kutupludur. Ters bağlanmamalıdır.
    - İdeal olmayan kapasite: kaçak akım nedeniyle kapasiteye paralel büyük bir dirençle modellenir.
  - Bağlantılar:
    - Paralel: $C_{eş} = C_1 + C_2 + \dots$
    - Seri: $\frac{1}{C_{eş}} = \frac{1}{C_1} + \frac{1}{C_2} + \dots$
- Endüktans (bobin)
  - Yapı: iletken telden sarılmış bobin. Manyetik alanda enerji depolar.
  - Temel bağıntılar:
    - $v = L\frac{di}{dt}$, akı bağı $\lambda = Li$.
    - Depolanan enerji: $w = \frac{1}{2}Li^2$.
    - Fiziksel değer: $L = \frac{N^2 \mu A}{l}$ (N sarım sayısı, $\mu$ çekirdeğin geçirgenliği, A kesit alanı, l bobin uzunluğu).
  - Davranış:
    - Endüktans akımı ani değişemez (süreklidir). Ani değişim sonsuz gerilim gerektirir.
    - DC'de, kalıcı durumda gerilim sıfırdır. Endüktans kısa devre gibi davranır.
    - İdeal olmayan endüktans: sargı direnci (seri) ve sarımlar arası kapasite ile modellenir.
  - Bağlantılar (dirençle aynı kural):
    - Seri: $L_{eş} = L_1 + L_2 + \dots$
    - Paralel: $\frac{1}{L_{eş}} = \frac{1}{L_1} + \frac{1}{L_2} + \dots$
- Duyurular ve plan
  - Gelecek hafta: kaynaksız RL ve RLC devrelerinin zaman bölgesi analizi ve DC davranışı.
  - 8. haftadaki vize bu konuları da kapsar.
  - Kısa sınavın klasik kısımları yeniden değerlendiriliyor. Kısa sınav çözümleri yayınlanmayacak; derste çözülebilir.
  - Laboratuvar saat 17:00'de.

## Hocanın Özellikle Vurguladığı Kısımlar

- Maksimum güç koşulu $R_L = R_{TH}$'dir. Bu durumda verim yalnızca %50'dir.
- Önce devrenin Thevenin eşdeğerini bulun, sonra maksimum güç koşulunu uygulayın.
- Bağımlı kaynakları süperpozisyonda ve Thevenin hesabında asla sıfırlamayın.
- Kaynak dönüşümünde aranan değişkenin ($v_x$, $i_o$) ait olduğu elemanı dönüşüme sokmayın.
- Bağımlı kaynak varken $R_{TH}$ için test kaynağı yöntemini kullanın.
- Kapasite gerilimi, endüktans akımı süreklidir. DC'de kapasite açık devre, endüktans kısa devredir.
- Laboratuvar raporlarında formül, ara işlem, birim ve simülatör görüntüsü olmalı.

## Kısa Tekrar Notları

- $P_L = \frac{V_S^2 R_L}{(R_S + R_L)^2}$, maksimum $R_L = R_S$'de, $P_{max} = \frac{V_S^2}{4R_S}$.
- Doğrusal devre için: $R_L = R_{TH}$, $P_{max} = \frac{V_{TH}^2}{4R_{TH}}$.
- Kapasite: $i = C\frac{dv}{dt}$, $w = \frac{1}{2}Cv^2$, $\tau = RC$.
- Endüktans: $v = L\frac{di}{dt}$, $w = \frac{1}{2}Li^2$.
- Kapasiteler paralelde toplanır, seride terslerinin toplamı. Endüktanslar dirençler gibi birleşir.
- Örnek sonuçları: Örnek 23 $i_o \approx -0.471$ A, Örnek 24 $v_x = 7.5$ V, Örnek 25 $V_{TH} = 20$ V, $R_{TH} = 6$ Ω.

## Detaylı Açıklamalar

### Neden verim %50?

- $R_L = R_S$ iken iki dirençten aynı akım geçer ve dirençler eşittir. Bu yüzden harcanan güçler de eşittir.
- Yüke aktarılan güç en büyük olur ama kaynağın gücünün yarısı kaybolur.
- Güç sistemlerinde verim önemli olduğundan bu koşul aranmaz. Haberleşme ve sinyal devrelerinde ise küçük sinyalden en fazla gücü almak için kullanılır.

### Örnek 22'de neden $R_{TH} = 1$ kΩ?

- Bağımlı kaynak $0.03\,v_\pi$ giriş tarafındaki $v_\pi$'ye bağlıdır.
- Giriş kaynağı sıfırlanınca giriş tarafında enerji yoktur, $v_\pi = 0$ olur. Bağımlı akım kaynağı sıfır akım verir, açık devre gibidir.
- Çıkış uçlarından bakınca yalnız 1 kΩ görülür.

### Ders sonrası notlar

- **Örneklerin kontrolü:** Örnek 23, 24 ve 25 ders sonrasında Python ile ve elle (düğüm denklemleriyle) yeniden çözüldü. Örnek 23: $i_o' = \frac{52}{17} \approx 3.059$ A, $i_o'' = -\frac{60}{17} \approx -3.529$ A, $i_o = -\frac{8}{17} \approx -0.4706$ A. Örnek 24: $v_x = 7.5$ V. Örnek 25: $V_{TH} = 20$ V, $R_{TH} = 6$ Ω, $I_N = \frac{10}{3}$ A.
- **Örnek 22 sayısal sonuç:** $17\text{k} \parallel 5\text{k} = 3863.6$ Ω. $v_\pi$ genliği $2.5 \cdot \frac{3863.6}{4163.6} \approx 2.320$ mV. $v_{oc}$ genliği $30 \cdot 2.320 \approx 69.6$ mV. $P_{max} = \frac{(69.6\,\text{mV})^2}{4 \cdot 1000} \approx 1.211$ µW (genlik), yani $1.211\sin^2(440t)$ µW. Türetmede dirençler için bir yerde "$V_{TH}$" dendi; kastedilen $R_{TH}$'dir.
- **Türevdeki işaret:** Maksimum güç türetmesinde türevin payı ilk yazılırken işaret karıştı, hoca sonra düzeltti. Doğru pay $(R_S + R_L)^2 - 2R_L(R_S + R_L)$'dir. Bu sıfır olunca $R_L = R_S$ çıkar.
- **Örnek 25'te işaret hatası:** İlk çözümde $V_{TH} = -4$ V bulundu. Hata bağımlı kaynağın kutuplarının ters alınmasından geliyordu. Düzeltilmiş kısıt $V_2 = 3V_1$ ile $V_1 = \frac{20}{3}$ V, $V_2 = 20$ V ve $V_{TH} = 20$ V olur (açık devrede 2 Ω'dan akım akmaz).
- **Kapasite enerjisi:** Derste bir yerde "1/2 C çarpı $V_C$ kare bölü 2" dendi. Doğrusu $w = \frac{1}{2}Cv^2$'dir; ikinci kez 2'ye bölünmez.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
