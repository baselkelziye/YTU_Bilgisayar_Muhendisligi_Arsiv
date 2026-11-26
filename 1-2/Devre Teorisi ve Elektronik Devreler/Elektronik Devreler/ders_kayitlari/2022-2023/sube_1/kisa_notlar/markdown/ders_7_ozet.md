# Ders 7 Çalışma Özeti

## Genel Konular

- Diyot modellerinin tekrarı
  - Diyot sembolünde üçgen tarafı anot (artı uç), çizgi tarafı katottur (eksi uç). İdeal diyot $V_D > 0$ iken kısa devre, $V_D \le 0$ iken açık devre gibi davranır (ekrandan, 00:10:00).
  - Gerçek diyot karakteristiğinde ters gerilimde küçük bir sızıntı akımı akar; ileri yönde akım belirli bir eşikten sonra hızla artar. Eşik gerilimleri: silisyum (Si) yaklaşık 0,7 V, germanyum (Ge) yaklaşık 0,3 V, galyum arsenit (GaAs) yaklaşık 1,2 V (ekrandan, 00:10:00).
  - İdeal olmayan diyot; ideal diyot, seri bir iç direnç ve aşılması gereken 0,7 V'luk bir bariyer gerilimiyle modellenir.
- Seri ve paralel diyot konfigürasyonlarının tekrarı
  - Seri Si diyotlu devrede (kaynak $E$, diyot, direnç $R$): $V_D = 0{,}7\ \text{V}$ (ya da $E < 0{,}7$ V ise $V_D = E$), $V_R = E - V_D$, $I_D = I_R = V_R / R$ (ekrandan, 00:05:00). Örneğin $E = 5$ V ise $V_R = 4{,}3$ V olur.
  - Paralel iki özdeş Si diyotlu örnekte $E = 10$ V için direnç üzerindeki gerilim $10 - 0{,}7 = 9{,}3$ V, ana kol akımı $I_1 \approx 28$ mA'dır. Kollar özdeş olduğu için akım ikiye bölünür, her diyottan yaklaşık 14 mA geçer. <!-- BELİRSİZ: direnç değeri altyazıda söylenmedi ve okunan karelerde görünmüyor -->
- Doğrultma (rectification): AC'den DC'ye
  - Prizdeki işaret 220 V, 50 Hz'lik sinüzoidal (AC) bir işarettir. Laptop adaptörü, telefon şarj cihazı, LCD televizyon gibi cihazlar sabit (DC) gerilime ihtiyaç duyar (örneğin 19 V, 12 V).
  - Sinüsün bir periyottaki ortalaması sıfırdır. Negatif yarım periyot sıfıra çekilirse ortalama yükselir: yarım dalga doğrultma. Negatif yarım periyot da pozitife çevrilirse ortalama daha da yükselir: tam dalga doğrultma.
  - Sonraki adımda kondansatörlü yapılarla doğrultulmuş işaret olabildiğince düzleştirilir; amaç olabildiğince dalgasız bir DC gerilim elde etmektir.
- Yarım dalga doğrultucu
  - Devre: giriş $v_i$, seri bir diyot ve çıkışın alındığı paralel direnç $R$ (ekrandan, 00:20:00).
  - Pozitif yarım periyotta ideal diyot iletir (kısa devre), $v_o = v_i$ olur. Negatif yarım periyotta diyot kesimdedir (açık devre), akım akmaz, $v_o = 0$ V olur.
  - Çıkışın DC (ortalama) değeri $V_{DC} = 0{,}318\,V_m$'dir; $V_m$ giriş işaretinin tepe değeridir (ekrandan, 00:20:00).
- Tam dalga köprü doğrultucu
  - Dört diyot (D1-D4) köprü biçiminde bağlanır; giriş $v_i$ A ve B uçlarından uygulanır, çıkış köprünün ortasındaki $R$ üzerinden alınır (ekrandan, 00:25:00).
  - Pozitif yarım periyotta ($V_A > V_B$) D2 ve D3 iletir, D1 ve D4 kesimdedir; çıkışta $v_o = v_i$ görülür.
  - Negatif yarım periyotta ($V_A < V_B$) D1 ve D4 iletir; akım yük direncinden yine aynı yönde geçtiği için negatif yarım periyot çıkışta pozitif olarak görülür (ekrandan, 00:30:00).
  - Çıkışın DC değeri $V_{DC} = 0{,}636\,V_m$'dir (ekrandan, 00:25:00).
  - Tam dalga doğrultma orta uçlu transformatörlü bir yapıyla da yapılabilir; bu yapı derste yalnız bilgi olarak geçildi.
- Doğrultucu özeti (ideal ve gerçekçi $V_{DC}$)
  - Tablo (ekrandan, 00:35:00):

| Doğrultucu | İdeal $V_{DC}$ | Gerçekçi $V_{DC}$ |
|---|---|---|
| Yarım dalga | $0{,}318\,V_m$ | $0{,}318\,V_m - 0{,}7$ |
| Köprü (tam dalga) | $0{,}636\,V_m$ | $0{,}636\,V_m - 2(0{,}7\ \text{V})$ |
| Orta uçlu transformatörlü | $0{,}636\,V_m$ | $0{,}636\,V_m - 0{,}7\ \text{V}$ |

  - Köprüde her yarım periyotta iki diyot iletimde olduğu için iki diyot düşümü ($2 \times 0{,}7$ V) hesaba katılır; transformatörlü yapıda iletimde tek diyot vardır.
- Kırpıcılar (clipper)
  - Giriş işaretinin bir kısmını kesen (kırpan) diyotlu devrelere kırpıcı denir. Yarım dalga doğrultucu da işaretin negatif kısmını kırpan bir seri kırpıcıdır.
  - Giriş sinüs, kare ya da üçgen dalga olabilir; yöntem aynıdır.
  - Seri kırpıcı: diyot girişe seri, direnç çıkışa paraleldir. Ters bağlanan diyotla işaretin pozitif kısmı kırpılır.
  - Paralel kırpıcı: direnç seri, diyot çıkışa paraleldir. İletimdeki diyot kısa devre olduğundan çıkış 0 V olur; kesimdeyken akım akmaz ve $v_o = v_i$ olur (ekrandan, 00:55:00).
  - Diyota seri ya da paralel bir DC gerilim kaynağı eklenerek kırpma seviyesi değiştirilebilir.
- Seri kaynaklı kırpıcı örneği ($V = 5$ V, $v_i$ tepe 20 V)
  - Kaynağın artı ucu diyotun anoduna bakar; anot gerilimi $v_i + 5$ V olur (ekrandan, 00:40:00).
  - $v_i > -5$ V olduğu sürece diyot iletir ve $v_o = v_i + 5$ V'tur: $v_i = 0$ için 5 V, $v_i = 1$ V için 6 V, $v_i = 20$ V için 25 V.
  - $v_i \le -5$ V olunca diyot açık devre olur ve $v_o = 0$ V'tur. Sonuç: işaret 5 V yukarı ötelenir, $-5$ V'un altında kalan kısımlar sıfıra kırpılır (ekrandan, 00:45:00).
- Çift diyotlu paralel kırpıcı örneği ($V_1 = 3$ V, $V_2 = 4$ V, $v_i$: $\pm 10$ V)
  - D1 (anot çıkışta) $+3$ V'luk kaynağa, D2 (katot çıkışta) anodu $-4$ V'ta kalacak şekilde 4 V'luk kaynağa bağlıdır (ekrandan, 01:10:00).
  - $-4 < v_i < 3$ V aralığında iki diyot da kesimdedir, $v_o = v_i$ olur. $v_i > 3$ V'ta D1 iletir, $v_o = 3$ V'ta sabitlenir. $v_i < -4$ V'ta D2 iletir, $v_o = -4$ V'ta sabitlenir.
- Paralel kırpıcı örneği (katodu çıkışta diyot, anodu $+3$ V'ta)
  - $v_i < 3$ V iken diyot iletir ve $v_o = 3$ V olur; $v_i > 3$ V'ta diyot açık devredir ve $v_o = v_i$ olur (ekrandan, 01:15:00).
- Seri kaynaklı kırpıcı örneği ($-3$ V kaynak, $v_i$: $\pm 10$ V)
  - Kaynak girişe ters bağlıdır; diyotun girişe bakan ucundaki gerilim $v_i - 3$ V olur (ekrandan, 01:25:00).
  - Diyot anodu çıkışa bakacak şekilde bağlıysa: $v_i < 3$ V iken iletir ve $v_o = v_i - 3$ V'tur ($v_i = 0$ için $-3$ V, tepe $-10$ V için $-13$ V). $v_i > 3$ V iken kesimdedir ve $v_o = 0$ V'tur.
  - Diyot ters çevrilirse: $v_i > 3$ V iken iletir ve $v_o = v_i - 3$ V'tur (tepe değeri $10 - 3 = 7$ V); $v_i < 3$ V iken $v_o = 0$ V'tur (ekrandan, 01:35:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Silisyum diyot eşik gerilimi
  - Derslerde çoğunlukla silisyum kullanılacağı için 0,7 V değerinin akılda tutulması istendi. İdeal olmayan hesaplarda iletimdeki her diyotun üzerinde 0,7 V düştüğü hesaba katılmalıdır.
- Yarım ve tam dalga doğrultucunun DC değerleri
  - $0{,}318\,V_m$ ve $0{,}636\,V_m$ değerlerinin bilinmesinde yarar olduğu söylendi; transformatörlü yapının ayrıntısının bilinmesine gerek olmadığı belirtildi.
- Kırpıcıların yorumlanması
  - Kırpıcı konusunun elektronik devrelerin yorumlanması açısından önemli olduğu, dikkatle dinlenmesi gerektiği söylendi.
  - Bu tür devrelerde giriş işaretinin verilip çıkış dalga şeklinin çizilmesi beklenir; slayttaki kırpıcı devrelerinden herhangi birinin sorulabileceği vurgulandı.
- Çözüm yöntemi: değer vererek ilerlemek
  - Önce giriş işareti çizilir. Sonra girişe sırayla değerler verilir (0 V, 1 V, 3 V, eksi değerler), her değerde diyotun iletimde mi kesimde mi olduğu belirlenir ve çıkış nokta nokta çizilir.
  - Kritik dönüm noktaları, diyotun iletime girdiği ve iletimden çıktığı giriş değerleridir.

## Kısa Tekrar Notları

- İdeal diyot: iletimde kısa devre, kesimde açık devre. Gerçek Si diyot: iletimde yaklaşık 0,7 V düşüm.
- Seri devre: $V_R = E - V_D$, $I = V_R / R$.
- Yarım dalga doğrultucu: $V_{DC} = 0{,}318\,V_m$; gerçekçi değerde bir diyot düşümü çıkarılır.
- Köprü doğrultucu: $V_{DC} = 0{,}636\,V_m$; her yarım periyotta iki diyot iletir, gerçekçi değerde $2 \times 0{,}7$ V çıkarılır.
- Köprüde pozitif yarıda D2-D3, negatif yarıda D1-D4 iletir (derste kullanılan çizimde).
- Seri kırpıcıda diyot iletimdeyken $v_o = v_i$ (artı varsa seri kaynak), kesimdeyken $v_o = 0$.
- Paralel kırpıcıda diyot iletimdeyken çıkış diyot koluna (0 V ya da seri kaynak gerilimi) sabitlenir, kesimdeyken $v_o = v_i$.
- Diyota seri bağlı kaynak dalga şeklini o kaynak kadar yukarı ya da aşağı öteler; kesime geçilen bölgede çıkış sıfırdır.
- Ters bağlı kaynak, bağlandığı noktada eksi gerilim olarak görülür.

## Detaylı Açıklamalar

- Doğrultmanın amacı
  - Elektrik şebekesinden gelen işaret sinüzoidaldir ve bir periyot boyunca ortalaması sıfırdır. Elektronik cihazlar ise zamanla değişmeyen bir DC gerilim ister. Bu dönüşümün ilk adımı doğrultmadır: diyotun akımı tek yönde geçirme özelliği kullanılarak işaretin negatif kısmı ya sıfıra çekilir (yarım dalga) ya da pozitife çevrilir (tam dalga). Ortalama ne kadar yüksekse elde edilecek DC o kadar yüksek ve verimli olur.
  - Derste bir öğrenci doğrultmanın amacını sordu. Cevap: önce ortalama yukarı çekilir, sonra kondansatörlü yapılarla pozitif tepeler arasındaki boşluklar doldurulur. Kondansatör tepede dolar, işaret düşerken yükü besler; böylece dalgalı ama DC'ye yakın bir işaret elde edilir. Daha büyük kondansatörlerle işaret olabildiğince düzleştirilir.
- Ortalama değerin kökeni
  - Yarım dalgada bir periyottaki alan $\int_0^{T/2} V_m \sin(\omega t)\,dt$ olup periyoda bölündüğünde $V_m/\pi \approx 0{,}318\,V_m$ elde edilir. Tam dalgada iki yarım periyodun alanı da pozitif olduğundan ortalama iki katına çıkar: $2V_m/\pi \approx 0{,}636\,V_m$. Bu değerler python ile sayısal olarak doğrulandı.
- Köprü doğrultucunun çalışması
  - Pozitif yarım periyotta A ucu B'den yüksektir. D1'in anodu B tarafına bakar, bu yüzden D1 iletmez; akım D2 üzerinden yük direncine gelir, D4 ters bağlı olduğundan oradan geçemez, D3 üzerinden B'ye döner. D2 ve D3 kısa devre kabul edilirse çıkışta girişin aynısı görülür.
  - Negatif yarım periyotta B ucu A'dan yüksektir. Bu kez D1 ve D4 iletir. Yük direncinin artı ucu yine yüksek potansiyelli tarafa, eksi ucu düşük potansiyelli A tarafına bağlı kaldığı için yükteki gerilim yön değiştirmez; negatif yarım periyot çıkışta pozitif olarak görülür.
- Paralel kırpıcının mantığı
  - Diyot çıkışa paralel olduğunda $v_o$ doğrudan diyotun uçlarındaki gerilimdir. Pozitif yarım periyotta diyot iletir; kısa devrenin iki ucu arasında gerilim farkı olmadığından çıkış 0 V olur. Negatif yarım periyotta diyot açık devredir, dirençten akım akmaz; direncin iki ucundaki gerilim eşit olduğundan giriş aynen çıkışa aktarılır. Böylece negatif yarım periyodu geçiren bir yarım dalga doğrultucu elde edilir.
- Seri kaynaklı kırpıcıda adım adım çözüm
  - $V = 5$ V'luk kaynak, artı ucu diyotun anoduna bakacak şekilde girişe seri bağlıdır. $v_i = 0$ iken bile anot 5 V'tadır ve diyot iletir; çıkış 5 V olur. Giriş arttıkça çıkış $v_i + 5$ olarak artar ve tepe değerde 25 V'a ulaşır. Negatif yarım periyotta giriş $-1$ V iken çıkış 4 V'tur; giriş $-5$ V'a gelince anot gerilimi sıfıra iner, diyot iletimden çıkar ve çıkış 0 V olur. $-5$ V'un altındaki bütün giriş değerlerinde çıkış sıfırdır. Sonuç, 5 V yukarı ötelenmiş ve alt kısmı kırpılmış bir dalgadır.
- Ters bağlı kaynak neden eksi alınır
  - Bir öğrenci $-3$ V kaynağın neden eksi alındığını sordu. Kaynağın artı ucu girişe, eksi ucu diyota bakıyorsa diyot tarafındaki A noktası girişten 3 V düşüktür; yani girişe göre A noktasında kaynak $-3$ V olarak görülür. Pil ters bağlanmış gibi düşünülür. Bu yüzden $v_i = 0$ iken A noktası $-3$ V'tadır ve diyot iletimdeyse bu değer aynen çıkışta görülür.
- Gerçek diyotla çizim
  - Bir öğrenci ideal olmayan diyotta kesimde de küçük bir akım olup olmayacağını sordu. Cevap: çizimler ideal diyotla yapılır; gerçek bir senaryoda sızıntı akımı yine ihmal edilir, ama iletimdeki diyotun üzerindeki 0,7 V'luk düşüm hesaba katılmalıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
