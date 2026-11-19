# Ders 9 Çalışma Özeti

## Genel Konular

- Osiloskopta DC ve AC giriş modu
  - Bir işaret $x(t)$, ortalaması olan DC bileşen ile bu ortalamanın çevresinde $+A$ ile $-A$ arasında salınan AC bileşenin toplamı olarak düşünülür (ekrandan, 00:15:00). DC bileşen sıfır frekanslı bileşendir, yani işaretin ortalamasıdır.
  - Osiloskobun DC modu işareti olduğu gibi (DC + AC) gösterir. AC modu DC bileşeni süzer, işareti sıfır çevresinde salınan AC bileşen olarak gösterir. Simülasyonda doğru sonucu görmek için kanallar DC moduna alınmalıdır.
- Tekrar sorusu: iki kutuplanmış diyotlu paralel kırpıcı
  - Devre: seri bir direnç, çıkışa paralel iki kol. Birinci kolda $D_1$ (anot yukarıda) ve artı ucu yukarıda $V_1$ kaynağı, ikinci kolda ters yönlü $D_2$ ve artı ucu aşağıda $V_2$ kaynağı var (ekrandan, 00:20:00). Giriş $V$ ile $-V$ arasında salınan sinüs.
  - Hocanın sayısal canlandırması: $V_1 = 3$ V, $V_2 = 4$ V, giriş genliği 10 V (ekrandan, 00:25:00). Giriş $-4$ V ile $3$ V arasındayken iki diyot da kesimdedir, çıkış girişi izler. Giriş 3 V'u geçince $D_1$ iletime girer, çıkış 3 V'ta kalır. Giriş $-4$ V'un altına inince $D_2$ iletime girer, çıkış $-4$ V'ta kalır.
- Gerilim çoklayıcılar ve transformatör
  - Slayttaki devre, transformatör sekonderinden gelen $V_m$ ile diyot ve kondansatörlerle $2V_m$ (doubler), $3V_m$ (tripler) ve $4V_m$ (quadrupler) çıkışlarının alınabildiğini gösterir (ekrandan, 00:30:00).
  - Transformatör: demir (manyetik) çekirdek üzerine sarılmış bakır sargılar arasında elektromanyetik güç aktarımı yapar. Giriş sargısı primer, çıkış sargısı sekonderdir. Sarım oranı 1:2 ise $V_1$ gerilimi $2V_1$ olarak aktarılır. Hareketli parçası olmayan, AC gerilimin seviyesini frekansı değiştirmeden manyetik indüksiyonla dönüştüren bir makinedir. Galvanik yalıtım için 1:1 sarım da kullanılır.
  - Güç korunduğu için gerilim iki katına çıkarsa akım yarıya iner. İki uçlu herhangi bir elemanın gücü $P = V \cdot I$'dır.
- Bipolar jonksiyon transistörün (BJT) yapısı
  - Transistör, P ve N tipi malzemeden üç katmanlı bir yapıdır; iki eklem (jonksiyon) vardır. Ortadaki katmanın tipi uçtakilerden farklıdır. Böylece iki tip elde edilir: pnp ve npn (ekrandan, 00:35:00).
  - Uçlar: E (emitter, yayıcı), B (base, taban/temel), C (collector, toplayıcı). Base her zaman ortadaki katmana bağlıdır. Slayttaki çizimde toplam genişlik 0,150 inç, ortadaki base katmanı 0,001 inç kalınlığındadır.
  - Her P-N birleşim yerinde, diyotta olduğu gibi bir tükenme bölgesi (depletion region) oluşur.
- Transistörün çalışması
  - Çalışma koşulu: emitter-base eklemi ileri kutuplanır, base-collector eklemi ters kutuplanır (ekrandan, 00:40:00). pnp örneğinde $V_{EB} = V_{EE}$ (pozitif), $V_{CB} = -V_{CC}$ (negatif). npn'de kutuplar terstir.
  - Çoğunluk taşıyıcıları emitterden collectora geçer; küçük bir base akımı da oluşur. Kirchhoff akım yasasıyla $I_E = I_C + I_B$.
- Transistör sembolü
  - Ok her zaman emitter ucundadır ve N tipi malzemeyi gösterir. Ok dışarıyı gösteriyorsa emitter N'dir, dolayısıyla npn; ok base'i (içeriyi) gösteriyorsa base N'dir, dolayısıyla pnp.
  - npn'de $I_B$ ve $I_C$ transistöre girer, $I_E$ çıkar; pnp'de yönler terstir.
- Üç bağlantı şekli
  - Ortak bazlı (common-base): base toprağa bağlı. Ortak emitterli (common-emitter): emitter toprağa bağlı, en çok kullanılan yapı. Ortak kolektörlü (common-collector): collector toprağa yakın.
  - Ortak bazlı yapıda base-emitter gerilimi yaklaşık 0,7 V'u geçince $I_E$ hızla artar.
- Çalışma bölgeleri
  - Kesim (cutoff), doyma (saturation) ve aktif bölge. Ortak bazlı çıkış karakteristiğinde $I_C$–$V_{CB}$ eğrileri $I_E = 0, 1, \dots, 7$ mA için çizilir (ekrandan, 00:50:00).
  - Kesimde gerilim olsa da akım yok denecek kadar azdır. Doymada akım yüksektir ama uçlar arasındaki gerilim düşüktür. Yükselteç olarak aktif bölgede çalışılır.
- Yaklaşıklıklar ve parametreler
  - $I_C \cong I_E$ ($I_B$ çok küçük olduğu için ihmal edilir) ve silisyum için $V_{BE} = 0{,}7$ V (ekrandan, 00:55:00).
  - $\alpha = I_C / I_E$; en fazla 1 olabilir, pratikte 0,90–0,99 arasıdır (genelde 0,99 civarı).
  - Gerçek akım: $I_C = \alpha I_E + I_{CBO}$, $I_{CBO}$ azınlık kolektör akımıdır. $I_B = 0$ iken kesimde akan azınlık akımı $I_{CEO} = \dfrac{I_{CBO}}{1-\alpha}$ (ekrandan, 01:20:00).
  - $\beta = I_C / I_B$, transistörün güçlendirme (yükseltme) faktörüdür; sorularda genelde verilir. $I_E = (\beta + 1) I_B$ ve $\alpha = \dfrac{\beta}{\beta + 1}$.
- Transistörle gerilim yükseltme örneği
  - pnp, ortak bazlı devre: $V_i = 200$ mV, giriş (emitter-base) direnci $R_i = 20\ \Omega$, çıkış (collector-base) direnci $R_o = 100$ k$\Omega$, yük $R = 5$ k$\Omega$ (ekrandan, 01:10:00).
  - $I_E = I_i = 200\text{ mV}/20\ \Omega = 10$ mA, $I_L \cong I_C \cong I_E = 10$ mA, $V_L = (10\text{ mA})(5\text{ k}\Omega) = 50$ V, $A_v = 50\text{ V}/200\text{ mV} = 250$.
  - Kullanım alanı: sensör, EKG ya da uydu verisi gibi küçük işaretlerin mikroişlemci ve DSP'nin işleyebileceği seviyeye yükseltilmesi (signal amplification), elektro gitar amfisi.
- Ortak emitterli yapı ve güç sınırı
  - Giriş base'den verilir, emitter topraklanır, besleme ($V_{CC}$) collectordan verilir. Önemli eğri $I_C$–$V_{CE}$ karakteristiğidir; eğriler $I_B$ değerleri (mikroamper) için çizilir, $I_C$ miliamper mertebesindedir.
  - Transistörün gücü $P = V_{CE} I_C$ (ortak bazlıda $V_{CB} I_C$). Slayttaki örnekte $P_{C\max} = V_{CE} I_C = 300$ mW, $I_{C\max} = 50$ mA, $V_{CE\max} = 20$ V, $V_{CE\text{sat}} = 0{,}3$ V (ekrandan, 01:25:00). Kullanılabilir alan kesim, doyma ve güç eğrisiyle sınırlanan aktif bölge parçasıdır.
- Veri sayfası, test ve kılıflar
  - Uç dizilimi ve parametreler veri sayfasından (spec sheet) öğrenilir. Örnek: 2N4123, npn tipi bir transistördür.
  - Multimetreyle test: npn'de ileri kutuplu base-emitter ekleminde düşük, ters kutuplu collector-base ekleminde yüksek direnç okunur.
  - Kılıflar: delikli karta takılan bacaklı kılıflar ve PCB yüzeyine lehimlenen yüzey montaj (SMD) kılıflar (ekrandan, 01:30:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Kırpıcı devreleri
  - Kırpıcıların her farklı konfigürasyonunun çözülüp çıkışının doğru yorumlanabilmesi istenir. Yöntem: giriş gerilimini adım adım artırıp azaltarak hangi diyotun hangi gerilimde iletime girdiğini bulmak.
- Transistörün üç bölgesi
  - Bağlantı şekline göre eğriler değişse de her transistörde kesim, doyma ve aktif bölge olmak üzere üç bölge olduğu bilinmelidir.
- Transistör bir anahtar ve yükselteç gibi
  - $V_{BE}$ 0,7 V'u geçince transistör "açılır"; $I_B$ akımının miktarı $I_C$ akımını belirler. Transistörün asıl kullanım amacı gerilimi yükseltmektir.
- $\alpha$ ve $\beta$
  - $\alpha$ mutlaka bilinmeli. $I_{CBO}$ ve $I_{CEO}$ genel kültür düzeyinde yeterlidir. $\beta$ değeri sorularda genelde verilir.
- Sembolden tip okuma
  - Okun olduğu bacak emitterdir ve ok N tipini gösterir; buradan transistörün npn mi pnp mi olduğu çıkarılır.

## Kısa Tekrar Notları

- Osiloskop: DC modu = DC + AC, AC modu = yalnız AC bileşen.
- Paralel kırpıcı ($V_1 = 3$ V, $V_2 = 4$ V): çıkış $-4$ V ile $3$ V arasında kırpılır.
- Çoklayıcılar: $V_m \to 2V_m, 3V_m, 4V_m$; transformatörde $P$ korunur, $V$ artarsa $I$ azalır.
- BJT: iki eklem, iki tip (npn, pnp), uçlar E, B, C; base ortadadır ve incedir.
- Çalışma: EB ileri, CB ters kutuplu.
- $I_E = I_C + I_B$, $I_C \cong I_E$, $V_{BE} = 0{,}7$ V (Si).
- $\alpha = I_C/I_E \approx 0{,}99$, $\beta = I_C/I_B$, $I_E = (\beta+1)I_B$, $\alpha = \beta/(\beta+1)$.
- $I_C = \alpha I_E + I_{CBO}$, $I_{CEO} = I_{CBO}/(1-\alpha)$.
- Ok emitterdedir ve N'yi gösterir: dışarı = npn, içeri = pnp.
- Bağlantılar: ortak baz, ortak emitter (en yaygın), ortak kolektör.
- Bölgeler: kesim, doyma, aktif; yükselteç aktif bölgede.
- Yükseltme örneği: 10 mA, 50 V, $A_v = 250$.
- Güç sınırı $P_{C\max} = V_{CE} I_C$; kılıflar bacaklı ya da SMD.

## Detaylı Açıklamalar

- Kırpıcı tekrarında giriş gerilimi sıfırdan başlatılır. Sıfırdayken hiçbir diyottan akım geçmez. Giriş artarken $D_1$'in anodu girişe, katodu $V_1$ kaynağının artı ucuna bağlı olduğundan, giriş $V_1$'i (örnekte 3 V) aşana kadar $D_1$ kesimde kalır; $D_2$ zaten ters kutupludur. Bu aralıkta direnç üzerinden akım akmadığı için girişteki gerilim aynen çıkışa aktarılır. Giriş 3 V'u biraz geçtiğinde $D_1$ kısa devre gibi davranır ve çıkış $V_1$'e kilitlenir. Negatif yarı periyotta giriş $-V_2$'nin (örnekte $-4$ V) altına inene kadar $D_2$ iletmez, çıkış girişi izler; $-4$ V'un altında $D_2$ iletir ve çıkış $-4$ V'ta kalır. Hoca, gerçek devrede köşelerin dik değil hafif yuvarlak olacağını da söyledi.
- Transistör 1950'lerden sonra yarı iletkenlerle yapılan cihazların küçülmesini ve sıcaklığa karşı daha kararlı çalışmasını sağladı. Diyot tek eklemli (P ve N) iken transistörde üç katman ve iki eklem vardır; bu yüzden "bipolar jonksiyon transistör" (BJT) adı verilir. Hoca yapıyı, bir P (ya da N) silindirin ortasına bir kuşak gibi farklı tip malzeme konmuş ve ortasından kesit alınmış hali olarak canlandırdı.
- pnp transistörde emitter-base eklemine pozitif $V_{EE}$, collector-base eklemine negatif gerilim uygulanır. Çoğunluk taşıyıcıları ileri kutuplu eklemden base'e geçer, base çok ince olduğu için büyük kısmı ters kutuplu ikinci eklemi aşarak collectora ulaşır. Emitter düğümünde KCL yazıldığında $I_E = I_C + I_B$ bulunur. npn'de kaynak kutupları ve akım yönleri terstir ama aynı eşitlik geçerlidir; $I_C$ ve $I_B$ düğüme aynı yönde ulaşır ve toplanır.
- Hocanın yükseltme örneğinde emitter-base arasındaki ileri kutuplu diyot nedeniyle giriş direnci yaklaşık 20 $\Omega$ gibi düşük, collector-base arasındaki ters kutuplu diyot nedeniyle çıkış direnci 100 k$\Omega$ mertebesinde yüksektir. Yük direnci $R_L$, transistörden beslenen ikinci bir devrenin ya da cihazın iç direncini temsil eder. Giriş akımı neredeyse aynen yüke aktarıldığından, büyük yük direnci üzerinde girişten çok daha büyük bir gerilim oluşur: 200 mV'luk giriş 50 V olur ve gerilim kazancı 250'dir.
- Ortak emitterli karakteristiklerde $I_B$ mikroamper ($10^{-6}$ A), $I_C$ miliamper ($10^{-3}$ A) mertebesindedir; aralarındaki yaklaşık bin katlık fark $I_B$'nin hesaplarda çoğu zaman ihmal edilmesinin nedenidir. $\beta$ ilişkisinden $I_E = I_C + I_B = \beta I_B + I_B = (\beta+1)I_B$ yazılır; $I_C = \alpha I_E$ yerine konunca $\beta I_B = \alpha(\beta+1)I_B$ ve buradan $\alpha = \beta/(\beta+1)$ elde edilir.
- Transistör iki uçlu bir kara kutu gibi düşünülürse, collector-emitter arasındaki gerilim ile üzerinden geçen akımın çarpımı harcanan gücü verir. Aktif bölgenin tamamı kullanılamaz; $V_{CE} I_C$ çarpımının üretici sınırını ($P_{C\max}$) aştığı bölge de dışarıda bırakılır.
- Ders sonrası notlar
  - Hoca emitter düğümü eşitliğini önce "$I_C = I_B + I_E$" diye yazdı; bir öğrencinin uyarısıyla derste düzeltti. Doğrusu $I_E = I_C + I_B$.
  - Hoca yükseltme örneğinin sonunda "girişte 20 milivolt" dedi; slaytta giriş 200 mV'tur ve kazanç $50/0{,}2 = 250$ buna göre hesaplanır.
  - Hoca osiloskop anlatımında bir yerde "AC modu derseniz hem DC hem AC bileşenini görürsünüz" dedi, hemen ardından doğrusunu anlattı: hem DC hem AC bileşeni gösteren DC modudur, AC modu DC bileşeni süzer.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
