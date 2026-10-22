# Ders 10 Çalışma Özeti

## Genel Konular

- Konu: fazörlere (phasor) giriş. Önceki derslerde RL, RC ve RLC devreleri zaman domeninde, DC kaynaklarla incelendi. Bu derste kaynak sinüzoidal olduğunda kullanılacak fazör yönteminin altyapısı kurulur.
- Fazör yönteminin amacı
  - Yalnız **sürekli sinüzoidal hâl** ile ilgilenilir. Geçici hâl (transient) bittikten sonraki durum incelenir, geçici hâl ihmal edilir.
  - Fazör uzayına geçince L ve C'nin diferansiyel tanım bağıntıları **lineer (cebirsel) denklemlere** dönüşür. Devre, direnç devresi gibi çözülür.
  - Sinüzoidal olmayan periyodik işaretler Fourier serisiyle sinüzoidallerin toplamı olarak yazılır. Her bileşen ayrı çözülüp **süperpozisyon** ile toplanır.
  - Laplace dönüşümü hem geçici hem sürekli hâli birlikte verir. Hoca bu dönem Laplace'a muhtemelen girilmeyeceğini söyledi.
- Fazör uzayında her kaynak bir karmaşık sayıyla, her eleman da bir **empedans** ($Z$) ile gösterilir. $Z$, fazör uzayında akıma gösterilen dirençtir (zaman domenindeki $R$'nin karşılığı).
- Karmaşık sayılar (tekrar)
  - Sayı kümeleri: doğal, tam, rasyonel, reel, karmaşık. Karmaşık sayılar en geniş kümedir.
  - Elektrikte sanal birim $i$ yerine $j$ ile gösterilir, çünkü $i$ akım için kullanılır. $j^2 = -1$.
  - Üç gösterim:
    - Kartezyen: $z = x + jy$.
    - Polar: $z = r\angle\phi$, $r = \sqrt{x^2 + y^2}$, $\phi = \tan^{-1}(y/x)$.
    - Üstel: $z = re^{j\phi}$.
  - Dönüşüm: $x = r\cos\phi$, $y = r\sin\phi$.
  - Euler formülü: $e^{j\phi} = \cos\phi + j\sin\phi$. Hoca bunu $e^x$, $\sin x$ ve $\cos x$'in Taylor (kuvvet) serileriyle gösterdi. İspatı isteyenler için isteğe bağlı ödev.
  - Eşlenik: $z^* = x - jy = r\angle -\phi$. $z \cdot z^* = |z|^2 = r^2$.
- Karmaşık sayılarla işlemler
  - Toplama ve çıkarma: kartezyen formda yapılır (vektör toplamı gibi). Reel kısımlar ve sanal kısımlar ayrı toplanır.
  - Çarpma (kartezyen): $(a + jb)(c + jd) = (ac - bd) + j(ad + bc)$.
  - Bölme (kartezyen): pay ve payda paydanın eşleniğiyle çarpılır: $\frac{a + jb}{c + jd} = \frac{(ac + bd) + j(bc - ad)}{c^2 + d^2}$.
  - Çarpma ve bölme polar formda çok daha kolaydır:
    - Çarpma: genlikler çarpılır, açılar toplanır.
    - Bölme: genlikler bölünür, açılar çıkarılır.
  - Fazör uzayında iki önemli işlem:
    - $V / I$: empedans (Ohm kanunu).
    - $V \cdot I^*$: elemanın çektiği güç (gerilim çarpı akımın eşleniği).
- Örnek (slayt 25, "Ohm's Law"): bir AC kaynağa doğrudan bağlı tek endüktans. Endüktans gerilimi $v_L = -3\sqrt{3} + 3j$ mV, endüktans akımı $1 + j\sqrt{3}$ mA. Soru, $v_L / i_L$ oranını istiyor.
  - $-3\sqrt{3} + 3j$: $r = \sqrt{27 + 9} = 6$. Nokta ikinci bölgede ($x$ negatif, $y$ pozitif), referans açı $\tan^{-1}(1/\sqrt{3}) = 30°$, yani $\phi = 150°$. Sonuç $6\angle 150°$.
  - $1 + j\sqrt{3}$: $r = 2$, $\phi = 60°$. Sonuç $2\angle 60°$.
  - Oran: $\frac{6\angle 150°}{2\angle 60°} = 3\angle 90°$.
  - Hoca derste $1 + j\sqrt{3}$'ü endüktansın empedansı ($Z_L$) gibi alıp $I_L = V_s / Z_L$ hesapladı. Bir öğrenci sorunca slaytta bu değerin akım olduğunu, sorunun da empedansı istediğini fark etti (bkz. Ders sonrası notlar).
- Notasyon kuralı (hoca bunu kesin kural olarak koydu)
  - Zaman domenindeki, zamanla değişen bütün büyüklükler **küçük harfle** yazılır: $v_L(t)$, $i_L(t)$.
  - Fazör karşılıkları **büyük harfle** yazılır: $V_L$, $I_L$, $V_s$, $Z_L$.
- Neden $V/I$ sabit oluyor?
  - Endüktans: zaman domeninde $v_L(t) = L\frac{di_L}{dt}$. Fazör uzayında türev, bir katsayıyla çarpmaya dönüşür: $V_L = (\text{sabit}) \cdot I_L$. Bu sabit $L$'yi ve türevden gelen bir çarpanı içerir.
  - Kapasite için de aynısı geçerli: $V_C / I_C$ sabittir.
  - Sonuç: fazör uzayında R, L ve C için gerilim/akım oranı sabit bir karmaşık sayıdır.
- Sinüzoidal işaretler
  - Genel biçim: $v(t) = V_m\sin(\omega t + \phi)$ veya $V_m\cos(\omega t + \phi)$.
  - Üç parametre: genlik $V_m$, açısal frekans $\omega = 2\pi f$ (rad/s), faz açısı $\phi$.
  - Periyot $T = 1/f$. Frekansın birimi Hz = 1/s. $2\pi$ rad = 360°.
  - Tepeden tepeye (peak-to-peak) değer: $2V_m$.
  - Ortalama değer: saf sinüzoidalin bir periyottaki ortalaması 0'dır. İşarete $A$ kadar DC ofset eklenirse ortalama $A$ olur.
  - Etkin (RMS) değer: $V_{rms} = \sqrt{\frac{1}{T}\int_0^T v^2(t)\,dt}$. Sinüzoidal için $\sin^2\omega t = \frac{1 - \cos 2\omega t}{2}$ kullanılarak $V_{rms} = \frac{V_m}{\sqrt{2}}$ bulunur.
  - Şebeke frekansı örneği verildi (bkz. Ders sonrası notlar).
- Faz farkı: önde (leading) ve geride (lagging)
  - Görsel yol: aynı yöndeki sıfır geçişini önce yapan işaret öndedir.
  - Örnek: periyodu 500 olan $5\sin(2\pi t/500)$ referans ($\phi_1 = 0$). Diğer iki işaret $\phi_2 = -28.8°$ ve $\phi_3 = 14.4°$ fazlı.
    - $\phi_1 - \phi_2 > 0$: işaret 1, işaret 2'nin önünde.
    - $\phi_1 - \phi_3 < 0$: işaret 3, işaret 1'in önünde.
  - Karşılaştırma yapmadan önce üç kural:
    1. Genlikler pozitif olmalı.
    2. İki işaret aynı fonksiyon tipinde olmalı (ikisi de sinüs veya ikisi de kosinüs).
    3. Faz açılarının mutlak değeri 180°'den küçük olmalı.
  - Kullanılan dönüşümler:
    - $\sin\theta = \cos(\theta - 90°)$.
    - $-\cos\theta = \cos(\theta \pm 180°)$.
  - Örnek (slayt 48): $v_1(t) = 6\sin(20t + 40°)$, $v_2(t) = -4\cos(20t + 20°)$.
    - Kosinüs formunda: $v_1 = 6\cos(20t - 50°)$, $v_2 = 4\cos(20t - 160°)$. Fark $-50° - (-160°) = 110°$. $v_1$, $v_2$'den 110° önde.
    - Sinüs formunda: $v_1 = 6\sin(20t + 40°)$, $v_2 = 4\sin(20t - 70°)$. Fark yine 110°.
- Fazör dönüşümü
  - Kural: kaynaklar **kosinüs** cinsinden yazılır. Fazör, $V_m e^{j(\omega t + \phi)}$'nin reel kısmı alınarak tanımlanır. Bu dersin kısa sınav ve finalinde bu kabul kullanılacak.
  - $V_m\cos(\omega t + \phi) \to V_m\angle\phi$. Frekans fazörde yazılmaz ama not edilmelidir. Zaman domenine dönerken $\omega$ tekrar yerine konur.
  - Sinüsten başlanırsa: $V_m\sin(\omega t + \phi) = V_m\cos(\omega t + \phi - 90°) \to V_m\angle(\phi - 90°)$.
  - Özel sayılar:
    - Pozitif reel $A$: $A\angle 0°$.
    - Negatif reel $-B$: $B\angle 180°$ (= $B\angle -180°$).
    - $j$: $1\angle 90°$. $-j$: $1\angle -90°$.
  - Örnekler (slayt 62):
    - $3\sin(100t + 20°) = 3\cos(100t - 70°) \to 3\angle -70°$ V.
    - $7\sin(350t - 100°) = 7\cos(350t - 190°)$. $-190°$ aralık dışında. $7\cos(350t - 190°) = -7\cos(350t - 10°) = 7\cos(350t + 170°) \to 7\angle 170°$ A. Not edilecek frekans: $\omega = 350$ rad/s.
  - Kartezyenden polara (slayt 63): $5 + 3j$: $r = \sqrt{34} \approx 5.83$, $\phi = \tan^{-1}(3/5) \approx 31°$.
  - Hesap makinesi: dönüşümleri yapan programlanabilir hesap makineleri veya çevrimiçi araçlar kısa sınavda ve finalde kullanılabilir. Önceden pratik yapın.
- Tekil (singularity, anahtarlama) fonksiyonlar kısaca hatırlatıldı: impuls, birim basamak, darbe, kare dalga, rampa (üçgen, testere dişi). Bunların kombinasyonuyla karmaşık dalga şekilleri yazılabilir.
- Sinüzoidal kaynaklı RL devresi (slayt 78)
  - Devre: $V_0\cos(\omega t)$ kaynağı, $R$ ve $L$ seri.
  - Denklem: $\frac{di}{dt} + \frac{R}{L}i = \frac{V_0}{L}\cos(\omega t)$.
  - Homojen çözüm: $Ae^{-\frac{R}{L}t}$ (geçici hâl).
  - Zorlanmış çözüm önerisi: frekans kaynağınkiyle aynı olmak zorundadır. Kalan iki keyfilik (genlik ve faz) bırakılır: $i(t) = I_0\cos(\omega t + \theta)$.
  - Yerine koyup çözünce: $i(t) = \frac{V_0}{\sqrt{R^2 + \omega^2L^2}}\cos\left(\omega t - \tan^{-1}\frac{\omega L}{R}\right)$. Kaynağa göre genlik ölçeklenir ve faz kayar.
  - Simülasyon grafikleri (RL, RC, paralel RLC): üstel terim yaklaşık $5\tau$ içinde söner. Sonra yalnız kaynakla aynı frekansta salınan sürekli hâl kalır. Fazör yöntemi bu kısmı hesaplar.
- R, L, C'nin fazör tanım bağıntıları (slayt 86, ders sonunda kısaca, detayı gelecek hafta)
  - R: $V = RI$. Gerilim ve akım aynı fazda.
  - L: $V = j\omega L\, I$. Gerilim akımdan 90° önde.
  - C: $I = j\omega C\, V$. Akım gerilimden 90° önde.
- Duyurular
  - Fazör uzayının eksik kalan kısmı gelecek hafta tamamlanacak.
  - Kısa sınav gelecek hafta, dersin son saatinde. Sınava kadar işlenen bütün konular dahil, fazör uzayında çözüm de dahil.
- Kaydın son kısmı (yaklaşık 3. saatten sonra) laboratuvar oturumudur. Dördüncü deney sorusu AC kaynak içerdiği için öğrenciler itiraz etti. Asistan, ders hocasıyla görüşüp soruyu DC kaynakla güncelledi. Teslim süresi saat 20:00'ye kadar verildi. Bu kısım ders içeriği değildir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Fazör yöntemi yalnız sürekli sinüzoidal hâli verir. Geçici hâl ihmal edilir.
- Notasyon: zaman domeni küçük harf ($i_L$), fazör uzayı büyük harf ($I_L$). Hep bu şekilde yazın.
- Çarpma ve bölmeyi polar formda, toplama ve çıkarmayı kartezyen formda yapın.
- Faz karşılaştırmasından önce: genlik pozitif, aynı fonksiyon tipi, faz açısı $(-180°, 180°)$ aralığında.
- **Kısa sınav ve final kabulü:** kaynakları kosinüs cinsinden yazın, fazörün reel kısmını alın.
- Frekansı fazörde yazmasanız da not edin. Zaman domenine dönerken gerekecek.
- Programlanabilir hesap makinesiyle dönüşümleri sınavdan önce pratik edin.

## Kısa Tekrar Notları

- $z = x + jy = r\angle\phi = re^{j\phi}$. $r = \sqrt{x^2 + y^2}$, $\phi = \tan^{-1}(y/x)$ (bölgeye dikkat).
- $e^{j\phi} = \cos\phi + j\sin\phi$. $z^* = r\angle -\phi$.
- Polar çarpma: $r_1 r_2\angle(\phi_1 + \phi_2)$. Polar bölme: $\frac{r_1}{r_2}\angle(\phi_1 - \phi_2)$.
- $Z = V/I$. Güç: $S = V \cdot I^*$.
- $\omega = 2\pi f$, $T = 1/f$, $V_{rms} = V_m/\sqrt{2}$.
- $\sin\theta = \cos(\theta - 90°)$. $-\cos\theta = \cos(\theta \pm 180°)$.
- $V_m\cos(\omega t + \phi) \leftrightarrow V_m\angle\phi$.
- $Z_R = R$, $Z_L = j\omega L$, $Z_C = \frac{1}{j\omega C}$.

## Detaylı Açıklamalar

### Neden önce kosinüse çevrilir?

- Fazör, $V_m e^{j(\omega t + \phi)}$ ifadesinin bir gösterimidir. Euler formülüne göre bunun reel kısmı $V_m\cos(\omega t + \phi)$'dir.
- Bu yüzden kosinüs formundaki bir işaretin fazörü doğrudan $V_m\angle\phi$'dir. Sinüs formundaki işaret önce 90° kaydırılıp kosinüse çevrilir.
- Sanal kısmı (sinüsü) referans alan kabul de vardır. Bir problemde bütün kaynaklar aynı kabulle yazılmalıdır.

### Faz açısı neden $(-180°, 180°)$ aralığında tutulur?

- $\cos(\omega t + \phi)$ ile $\cos(\omega t + \phi + 360°)$ aynı işarettir. Aralık sabitlenmezse "önde" ve "geride" yorumu belirsizleşir.
- Örnek: 270° önde olmak, 90° geride olmakla aynıdır. Aralık içinde kalınca küçük olan fark doğrudan okunur.

### Ders sonrası notlar

- **Slayt 25 örneğinin doğru yorumu:** Slaytta $1 + j\sqrt{3}$ mA endüktansın **akımı**dır. Sorulan, $v_L / i_L$ oranıdır (empedans): $Z_L = \frac{6\angle 150°}{2\angle 60°} = 3\angle 90°$ Ω $= j3$ Ω. Python ile doğrulandı. Açının 90° çıkması ideal endüktansla tutarlı: gerilim akımdan 90° öndedir ($150° - 60° = 90°$).
- **Hocanın derste söylediği 90° faz farkı:** Hoca $1 + j\sqrt{3}$'ü empedans sanıp $I_L = 3\angle 90°$ bulduğunda, "kaynak ile akım arasında 90° fark var" dedi. Bu yorumda bile fark $150° - 90° = 60°$ olurdu. Doğru sonuç yukarıdaki gibidir: $v_L$ ile $i_L$ arasında 90° fark var.
- **Güç örneği (kontrol):** Aynı değerlerle $S = V_L \cdot I_L^* = 12\angle 90°$ $= j12$ (mV·mA $= \mu$VA). Reel kısım 0'dır. İdeal endüktans ortalama güç harcamaz, yalnız reaktif güç alışverişi yapar.
- **Şebeke frekansı:** Hoca "Türkiye ve Avrupa'da 50 Hz, Avrupa'da 60 Hz" dedi. Doğrusu: Türkiye ve Avrupa'da 50 Hz, ABD ve Kuzey Amerika'da 60 Hz.
- **Slayt 63 tablosunda hatalar var.** Derste yalnız ilk satır ($5 + 3j$) işlendi. Python ile kontrol:
  - $5 + 3j = 5.83\angle 30.96°$. Doğru.
  - $-30 + j100$: slaytta $104\angle -73.3°$. Doğrusu $104.4\angle 106.7°$, çünkü sayı ikinci bölgededir. $\tan^{-1}$ hesap makinesinde bölge düzeltmesi yapılmamış.
  - $-0.4 - 0.25j$: slaytta $0.472\angle 32.0°$. Doğrusu $0.472\angle -148.0°$ (üçüncü bölge).
  - $75 - j150 = 167.7\angle -63.4°$. Slayttaki 168 yuvarlanmış değer, doğru.
  - Ders: $\tan^{-1}(y/x)$ yalnız $-90°$ ile $90°$ arası verir. $x < 0$ ise sonuca $180°$ eklenir veya çıkarılır.
- **RL formülü:** Altyazıda genlik "$V_0$ bölü $R^2 + \omega^2L^2$" ve faz "$VL$ bölü $R$'nin tanjant eksi biri" olarak geçiyor. Doğrusu slayttaki gibidir: genlik $\frac{V_0}{\sqrt{R^2 + \omega^2L^2}}$, faz $-\tan^{-1}\frac{\omega L}{R}$. Bu formül, $R = 10$ Ω, $L = 50$ mH, $V_0 = 5$ V, $f = 50$ Hz için diferansiyel denklemin sayısal çözümüyle karşılaştırıldı. Geçici hâl söndükten sonra sonuçlar örtüştü.
- **Kosinüs dönüşümü:** Altyazıda "kosinüs alfa eşittir eksi 180 artı alfa kosinüs" gibi bozuk bir ifade var. Kullanılan doğru özdeşlik: $\cos\alpha = -\cos(\alpha \pm 180°)$ ve $\cos\alpha = -\cos(180° - \alpha)$.
- **Faz farkı örneğindeki sayılar:** Periyot 500 iken $-28.8°$ faz, $\frac{28.8}{360} \cdot 500 = 40$ birimlik gecikmeye, $14.4°$ ise 20 birimlik öne kaymaya karşılık gelir. Hoca bir yerde "frekansı 500" dedi, hemen ardından "periyodu 500" olarak düzeltti.
- **RMS kontrolü:** Genliği 5 olan sinüs için sayısal hesap $3.5355 \approx 5/\sqrt{2}$ verdi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
