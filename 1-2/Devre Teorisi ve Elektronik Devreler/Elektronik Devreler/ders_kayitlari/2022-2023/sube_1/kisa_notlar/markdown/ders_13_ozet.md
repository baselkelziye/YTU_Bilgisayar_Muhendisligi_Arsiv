# Ders 13 Çalışma Özeti

## Genel Konular

- Diyot modellerinin kısa tekrarı (ekrandan, 00:05:00)
  - İdeal diyot: $V_D > 0$ olduğu anda (sıfırın hemen üstünde) kısa devre gibi davranır ve akım geçirir; ters gerilimde hiç akım geçirmez.
  - Basitleştirilmiş model: diyotun iletime geçmesi için tükenme bölgesini aşan bir eşik gerilimi gerekir. Bu gerilim silisyumda $V_T = 0{,}7$ V, germanyumda $0{,}3$ V'tur. Model, ideal diyota seri bir $V_T$ kaynağıdır.
  - Parçalı doğrusal model: eşik gerilimine ek olarak bir iç direnç ($r_{av}$) vardır. Gerçek diyot eğrisi eşikten sonra üstel olarak yükselir.
- Seri diyot devresi ve çalışma noktası (ekrandan, 00:10:00)
  - $E = 10$ V, silisyum diyot ve $R = 1$ k$\Omega$ seri bağlı devrede ideal kabul edilirse bütün gerilim dirençte düşer: $I_D = 10\text{ V}/1\text{ k}\Omega = 10$ mA.
  - Gerçekçi hesapta diyot üzerinde 0,7 V düşer: $V_R = 9{,}3$ V ve $I_D = 9{,}3$ mA.
- Silisyum diyot ve 2,2 k$\Omega$ dirençle 8 V'luk kaynak
  - $8 = 0{,}7 + V_R$, buradan $V_R = 7{,}3$ V ve $I = 7{,}3\text{ V}/2{,}2\text{ k}\Omega \approx 3{,}32$ mA.
- Seri silisyum ve germanyum diyotlu devre (ekrandan, 00:15:00)
  - $+12$ V'luk bir uç, toprağa giden bir 12 V'luk DC kaynak gibi düşünülür.
  - $V_A = V_{Si} + V_{Ge} + V_R$, yani $12 = 0{,}7 + 0{,}3 + V_o$; $V_o = V_R = 11$ V.
  - $I_D = I_R = 11\text{ V}/5{,}6\text{ k}\Omega \approx 1{,}96$ mA.
- İki kaynaklı seri devre ($E_1 = 10$ V, $E_2 = -5$ V) (ekrandan, 00:20:00)
  - $-5$ V'luk uç, toprağa ters bağlanmış 5 V'luk bir kaynak gibi düşünülür. Toplam sürücü gerilim $10 + 5 = 15$ V olur.
  - $15 - 0{,}7 = 14{,}3 = I(R_1 + R_2)$, $R_1 = 4{,}7$ k$\Omega$, $R_2 = 2{,}2$ k$\Omega$.
- İki diyotlu paralel-seri devre: $I_1$, $I_2$ ve $I_{D_2}$ (ekrandan, 00:25:00)
  - $E = 20$ V, iki silisyum diyot iletimde. $R_1 = 3{,}3$ k$\Omega$ ikinci diyota paralel olduğu için üzerinde 0,7 V vardır: $I_1 = 0{,}7/3{,}3\text{ k}\Omega \approx 0{,}212$ mA $= 212$ µA.
  - Çevre denklemi: $20 = 0{,}7 + 0{,}7 + I_2 R_2$, $R_2 = 5{,}6$ k$\Omega$; $I_2 = 18{,}6/5{,}6 \approx 3{,}32$ mA.
  - Alt düğümde $I_{D_2} + I_1 = I_2$, buradan $I_{D_2} = 3{,}32 - 0{,}212 \approx 3{,}11$ mA (ekrandan, 00:25:00).
- Yarım dalga doğrultucu ve DC seviyesi (ekrandan, 00:30:00)
  - Girişi tepe değeri 20 V olan sinüs, ters yönde bağlı diyot ve 2 k$\Omega$ yük: diyot yalnız negatif yarı periyotta iletir, çıkışta negatif yarım dalgalar görülür.
  - Yarım dalga için $V_{dc} = 0{,}318 V_m$, tam dalga için $V_{dc} = 0{,}636 V_m$. Burada $V_{dc} = -0{,}318(20) = -6{,}36$ V.
  - Silisyum diyotla $V_{dc} = -0{,}318(20 - 0{,}7) \approx -6{,}14$ V; fark yaklaşık 0,22 V (yaklaşık %3,5).
  - Giriş 200 V olursa ideal durumda $-63{,}6$ V, silisyumda yaklaşık $-63{,}38$ V; fark yine 0,22 V ama oranı çok küçüktür.
- Tam dalga köprü doğrultucu, dirençli köprü (ekrandan, 00:40:00 ve 00:45:00)
  - Giriş tepe değeri 10 V. Pozitif yarı periyotta bir diyot iletir; iki 2 k$\Omega$ direnç seri olur, bunlar üçüncü 2 k$\Omega$ dirence paraleldir. Çıkış, seri iki dirençten birinin üzerindedir: $V_{o,max} = \tfrac{1}{2} V_{i,max} = 5$ V.
  - Negatif yarı periyotta diğer diyot iletir, dirençlerin rolü değişir ve çıkış yine pozitif yönde 5 V tepeli yarım dalga olur.
  - Çıkışın DC seviyesi: $V_{dc} = 0{,}636 \cdot 5 = 3{,}18$ V.
- Seri kaynaklı kırpıcı (clipper) çıkışının çizimi (ekrandan, 00:55:00)
  - Giriş tepe değeri 20 V olan sinüs; girişe seri 5 V'luk bir kaynak ve diyot, çıkış yük direnci üzerinden alınır.
  - Diyot iletimdeyken $v_o = v_i + 5$ V'tur: $v_i = 0$ iken 5 V, $v_i = 2$ V iken 7 V, $v_i = 20$ V iken 25 V.
  - $v_i$ negatife indikçe çıkış azalır ($-1 \to 4$, $-2 \to 3$, $-4 \to 1$ V). $v_i = -5$ V olduğunda diyot kesime girer ve $v_i < -5$ V boyunca çıkış 0 V'tur.
  - Yöntem: girişten noktalar seçip her biri için diyotun durumunu ve çıkışı bulmak; kritik geçiş gerilimini ($v_i = -5$ V) belirlemek.
- Zener diyot ve gerilim bölücü (ekrandan, 01:00:00 ve 01:05:00)
  - Zener ters bağlanır. Üzerine düşmeye çalışan gerilim $V_Z$'nin altındaysa açık devre gibidir; $V_Z$'yi aşınca üzerindeki gerilimi $V_Z$'de sabit tutar, fazlası seri dirence kalır. Böylece yükü korur, bir sınırlayıcı gibi çalışır.
  - Zenerin durumu, zener çıkarılıp gerilim bölücüyle bulunan $V = \dfrac{R_L V_i}{R + R_L}$ değeri $V_Z$ ile karşılaştırılarak belirlenir.
  - Örnek: $V_i = 16$ V, $R = 1$ k$\Omega$, $V_Z = 10$ V, $P_{ZM} = 30$ mW. $R_L = 1{,}2$ k$\Omega$ için $V = 8{,}73$ V $< 10$ V, zener kapalı: $V_L = 8{,}73$ V, $V_R = 7{,}27$ V, $I_Z = 0$, $P_Z = 0$.
  - $R_L = 3$ k$\Omega$ için $V = 12$ V $> 10$ V, zener açık: $V_L = 10$ V, $V_R = 6$ V, $I_R = 6$ mA, $I_L = 3{,}33$ mA, $I_Z = I_R - I_L = 2{,}67$ mA, $P_Z = 10 \cdot 2{,}67 = 26{,}7$ mW $< 30$ mW, zener görevini sürdürür (ekrandan, 01:10:00).
- Ayarlı yüklü zener regülatörü: $R_L$ ve $I_L$ aralığı (ekrandan, 01:15:00 ve 01:20:00)
  - $V_i = 50$ V, $R = 1$ k$\Omega$, $V_Z = 10$ V, $I_{ZM} = 32$ mA.
  - Zenerin tam iletime geçtiği sınırda $I_Z = 0$: $V_R = 50 - 10 = 40$ V, $I_R = 40$ mA, bütün akım yükten geçer: $R_{L\min} = 10\text{ V}/40\text{ mA} = 250\ \Omega$ ($I_{L\max} = 40$ mA).
  - Zener en fazla 32 mA geçirebildiği için yüke en az $40 - 32 = 8$ mA kalır: $R_{L\max} = 10\text{ V}/8\text{ mA} = 1{,}25$ k$\Omega$.
  - Çıkışın 10 V'ta tutulduğu aralık: $250\ \Omega \le R_L \le 1{,}25$ k$\Omega$, $8 \text{ mA} \le I_L \le 40$ mA.
- Seri ve paralel kırpıcı ayrımı (derste sözlü, 01:22:20)
  - Paralel kırpıcıda diyot girişe paralel olan koldadır. Seri kırpıcıda diyot girişin hemen devamında, ana (seri) koldadır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kırpıcı (clipper) devreleri önemlidir
  - Hoca bu tür devrelerin nasıl çözüldüğünü soracağını söyledi. Kritik gerilimleri bulup çıkışı doğru çizmek gerekir.
  - Farklı konfigürasyonlara mutlaka çalışılmalıdır: kaynak ve diyot farklı yönlerde, seri kolda ya da paralel kolda olabilir.
- DC seviyesinin anlamı
  - DC seviyesi, bir periyot boyunca işaretin altında kalan alana eşit alan veren sabit seviyedir. Tek yarım dalga geçiyorsa $0{,}318 V_m$, iki yarım dalga geçiyorsa alan iki katına çıkar ve $0{,}636 V_m$ olur.
- Eşik geriliminin etkisi
  - Giriş gerilimi büyüdükçe diyot üzerinde düşen 0,7 V'un sonuca etkisi oransal olarak önemsizleşir.
- Birim dönüşümleri
  - mili $= 10^{-3}$, mikro $= 10^{-6}$; örneğin $0{,}212$ mA $= 212$ µA.
- Zener sınırlarının anlamı
  - Zener, $V_Z$ aşılınca yükün üzerindeki gerilimi $V_Z$ ile sınırlar; güç sınırı ($P_{ZM}$) ya da akım sınırı ($I_{ZM}$) aşılırsa zener bozulur ve koruma özelliği kalmaz.

## Kısa Tekrar Notları

- Silisyum $V_T = 0{,}7$ V, germanyum $V_T = 0{,}3$ V.
- Seri diyot devresinde: $E = \sum V_T + V_R$, $I = V_R/R$.
- Negatif kaynaklı uç, toprağa ters bağlı bir kaynak gibi çizilir; kaynaklar aynı yönde sürüyorsa gerilimler toplanır.
- Paralel kollarda gerilim eşittir; düğümde giren akımlar toplamı çıkan akıma eşittir ($I_{D_2} + I_1 = I_2$).
- Yarım dalga: $V_{dc} = 0{,}318 V_m$; tam dalga: $V_{dc} = 0{,}636 V_m$. Silisyum diyotta $V_m$ yerine $V_m - 0{,}7$ kullanılır.
- Kırpıcıda: noktaları tek tek dene, diyotun iletim/kesim geçişini veren kritik girişi bul.
- Zener: önce zeneri çıkarıp $V$'yi bul. $V < V_Z$ ise kapalı ($I_Z = 0$); $V \ge V_Z$ ise $V_L = V_Z$, $I_Z = I_R - I_L$, $P_Z = V_Z I_Z$.
- Zener regülatörde $R_{L\min} = \dfrac{R V_Z}{V_i - V_Z}$, $I_{L\min} = I_R - I_{ZM}$, $R_{L\max} = V_Z / I_{L\min}$.

## Detaylı Açıklamalar

- Bu ders, o zamana kadar görülen diyot konularının soru çözümüne ayrıldı. Sorular İngilizce bir ders kitabından alınmış bir soru dosyası üzerinden, ekranda kalemle işaretlenerek çözüldü.
- Seri diyot devrelerinde önce diyotların iletimde olup olmadığına bakılır. DC kaynak diyotları ileri yönde sürüyorsa ve gerilim eşik gerilimlerinin toplamından büyükse diyotlar sürekli iletimdedir; her biri yerine $V_T$ değerinde bir kaynak konur. Ardından Kirchhoff gerilim yasası yazılır. Örneğin 12 V'luk devrede silisyum ve germanyum diyot seri ise $12 = 0{,}7 + 0{,}3 + V_o$ olur, çıkış 11 V'tur, akım $11/5{,}6\text{ k}\Omega \approx 1{,}96$ mA'dir.
- Devrede bir uç toprağa göre negatif verilmişse ($E_2 = -5$ V), bu uç toprağa ters bağlı 5 V'luk bir kaynak olarak çizilir. Bu durumda çevrede iki kaynak aynı yönde akım sürer: $10 + 5 - 0{,}7 = I(R_1 + R_2)$. Akım bütün seri elemanlarda aynı olduğu için $I$ ortak paranteze alınır.
  - Ders sonrası not: Hoca $R_1 + R_2 = 4{,}7 + 2{,}2$ toplamını 5,9 k$\Omega$ aldı ve $I \approx 2{,}42$ mA buldu. Doğrusu $R_1 + R_2 = 6{,}9$ k$\Omega$ ve $I = 14{,}3/6{,}9 \approx 2{,}07$ mA'dir (python ile kontrol edildi).
- İki diyotlu devrede ikinci diyot ile $R_1$ paralel olduğu için $R_1$ üzerinde de 0,7 V vardır; bu yüzden $I_1$ çok küçüktür (212 µA). $I_2$ ise iki diyot ve $R_2$'den oluşan çevreden bulunur (3,32 mA). Diyot akımı düğüm denkleminden gelir: $I_{D_2} = I_2 - I_1 \approx 3{,}11$ mA.
- Yarım dalga doğrultucuda diyotun yönü hangi yarım periyodun geçeceğini belirler. Örnekte diyot ters yönde olduğu için yalnız negatif yarım dalgalar geçer ve DC seviyesi negatiftir ($-6{,}36$ V). Silisyum diyotta tepe değer 0,7 V azalır ve DC seviyesi $-6{,}14$ V olur. Aynı fark (yaklaşık 0,22 V) 200 V girişte de vardır, ama 63,6 V'a göre çok küçüktür.
  - Ders sonrası not: 200 V girişte silisyum diyotla DC seviyesi $-0{,}318(199{,}3) \approx -63{,}38$ V'tur; altyazıda bu değer "6.38" diye geçiyor.
- Dirençli köprü doğrultucuda her yarım periyotta bir diyot kısa devre olur. Devre yeniden çizildiğinde seri iki 2 k$\Omega$ direnç ve onlara paralel bir 2 k$\Omega$ direnç görülür. Seri dirençler eşit olduğu için giriş gerilimi ikiye bölünür ve çıkışta 5 V tepeli bir yarım dalga oluşur. Dirençler eşit olmasaydı (örneğin 3 k$\Omega$ ve 7 k$\Omega$) gerilim oranlarına göre paylaşılırdı. Negatif yarı periyotta diyotların rolü değişir ama çıkış yine aynı yönde oluşur; bu yüzden devre tam dalga doğrultucudur ve DC seviyesi $0{,}636 \cdot 5 = 3{,}18$ V'tur.
- Seri kaynaklı kırpıcıda çıkış, girişten seçilen değerler tek tek denenerek çizilir. 5 V'luk kaynak diyotu ileri yönde sürdüğü için $v_i = 0$ iken bile diyot iletimdedir ve çıkış 5 V'tur. Çıkış girişin 5 V yukarı kaydırılmış hâlidir; giriş $-5$ V'un altına inince diyot kesime girer, çıkış 0 V olur. Bu yüzden çıkış, girişin negatif yarı periyoduna da bir süre taşar.
- Zener soruları iki adımda çözülür: zener çıkarılıp gerilim bölücüyle zener uçlarındaki gerilim bulunur; bu değer $V_Z$'nin altındaysa zener açık devredir. Üstündeyse zener uçlarında $V_Z$ kalır, akımlar KCL ile bulunur ve güç kontrol edilir. Ayarlı yüklü regülatörde yük direncinin alt sınırı zenerin iletime geçtiği an ($I_Z = 0$), üst sınırı zenerin en fazla akımı ($I_{ZM}$) çektiği andır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
