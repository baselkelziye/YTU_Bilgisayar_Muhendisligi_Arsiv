# Ders 6 Genişletilmiş Notu: Maksimum Güç Aktarımı, Bağımlı Kaynaklı Süperpozisyon ve Thevenin Örnekleri, Kapasite ve Endüktans

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Laboratuvar Oturumundan Kalan Akademik Noktalar
- 2. Thevenin ve Norton Teoremlerinin Tekrarı
- 3. Maksimum Güç Aktarımı
- 4. Örnek 22: Ortak Emitörlü BJT Küçük Sinyal Devresinde Maksimum Güç
- 5. Örnek 23: Bağımlı Kaynaklı Devrede Süperpozisyon
- 6. Örnek 24: Bağımlı Akım Kaynağı ile Kaynak Dönüşümü
- 7. Örnek 25: Bağımlı Kaynaklı Devrenin Thevenin Eşdeğeri
- 8. Kapasite Elemanı: Yapı, Türler ve Pratik Bilgiler
- 9. Kapasite Elemanının Davranışı
- 10. Kapasitenin Akım-Gerilim Bağıntısı ve Enerjisi
- 11. Şarj, Deşarj ve 5τ Kuralı
- 12. Seri ve Paralel Kapasitelerin Eşdeğeri
- 13. Endüktans Elemanı
- 14. Seri ve Paralel Endüktansların Eşdeğeri

## 1. Laboratuvar Oturumundan Kalan Akademik Noktalar

Kaydın ilk bölümü, yaklaşık 2 saat 27 dakika süren laboratuvar oturumudur. Bu bölümde konu anlatımı yoktur, öğrenciler sorular üzerinde çalışır. Laboratuvar sorumlusunun içerikle ilgili söyledikleri kısadır: Bu deneyde hesaplamalar simülasyondan daha ağır basmaktadır. Çözümlerde formüller, ara hesaplar, birimler ve rakamlar açık ve anlaşılır biçimde yazılmalı, Proteus ya da kullanılan başka bir simülasyon ortamındaki her ölçümün ekran çıktısı gösterilmelidir.

**Soru:** Üretecin iç değerini geçen hafta sıfır alabileceğimiz söylenmişti. Bu hafta sıfır mı alacağız, yoksa doğrudan 0.1 mi? **Cevap:** Doğrudan 0.1 alınabilir, sıfır da alınabilir, fark etmez. Soruların amacı bu değerin etkisi değil, başka bir şeyi görmektir.

<!-- BELİRSİZ: "Üretecin iç değeri" ve 0.1 değerinin birimi altyazıda net değil; soru metni de altyazıda yer almıyor. -->

## 2. Thevenin ve Norton Teoremlerinin Tekrarı

Hoca asıl derse geçen haftanın son konusunu hatırlatarak başladı. Thevenin teoremi şunu söyler: Doğrusal elemanlardan oluşan karmaşık bir devrenin, bir terminalden bakıldığında bir yük direnci üzerindeki etkisi, eşdeğer olarak yalnızca bir gerilim kaynağı ve ona seri bir dirençle yazılabilir. Norton teoremi de aynı etkiyi bir akım kaynağı ve ona paralel bir dirençle verir. Bu iki eşdeğer arasındaki geçiş, kaynak dönüşümü konusunda görülen işlemin aynısıdır. Bu nedenle yöntemler Thevenin üzerinden anlatılır, Thevenin eşdeğeri bulunduktan sonra Norton da elde edilir.

Thevenin eşdeğerini bulmak için dört yöntem görülmüştü:

1. **Art arda kaynak dönüşümü.** Devrenin içinde ardışık kaynak dönüşümleri yapılır, bir gerilim kaynağı ve ona seri bir direnç kalana kadar indirgeme sürdürülür.
2. **Yük direncinin uç durumları.** İki devre eşdeğer olduğuna göre, yük direncinin uç değerlerinde de aynı davranmalıdır.
   - $R_L \to \infty$ açık devre demektir. Thevenin eşdeğerinde açık devre gerilimi doğrudan $V_{TH}$'dir, öyleyse karmaşık devrenin terminallerinde görülen açık devre gerilimi de $V_{TH}$'ye eşittir.
   - $R_L = 0$ kısa devre demektir. Bu koldan geçen $I_{SC}$ akımı hesaplanır ya da ölçülür, $R_{TH} = V_{TH}/I_{SC}$ bulunur.
3. **Kaynakları sıfırlayıp bakmak.** $V_{TH}$ yine açık devre geriliminden bulunur. Sonra yük direnci kaldırılır, içerideki bağımsız kaynaklar sıfırlanır ve terminalden içeri bakılarak görülen eşdeğer direnç $R_{TH}$ olarak alınır.
4. **Test kaynağı.** İçeride bağımlı kaynak varsa kullanılır. $V_{TH}$ yine açık devre gerilimidir. $R_{TH}$ için bağımsız kaynaklar sıfırlanır, terminallere birim genlikli bir gerilim kaynağı ya da bir değerli bir akım kaynağı bağlanır. Hangisinin seçileceği, devrenin karmaşıklığına göre hangisi daha pratikse ona bağlıdır. Test kaynağındaki gerilimin akıma oranı $R_{TH}$'yi verir.

Dördüncü yöntemin gerekçesi şudur: Önceki yöntemler kaynakları sıfırlamaya ya da yük direncinin uç durumlarına dayanır. Bağımlı kaynağın değeri ise başka bir yerdeki akıma ya da gerilime bağlı olarak tanımlıdır. Uç durumlar bu kontrol büyüklüğünü bozabilir.

> **Hocanın vurgusu:** İçeride bağımlı kaynak varsa dördüncü yöntem her durumda kullanılabilir ve kullanılması tavsiye edilir. Bağımsız kaynakla birlikte bağımlı kaynak bulunan bazı devrelerde önceki yöntemler de çalışabilir, ama dikkatli olmak gerekir. Bağımlı kaynağın değerini belirleyen gerilim 1, 2 ve 3. yöntemlerde bozuluyorsa gerçekçi sonuç elde edilemez.

> **Ders sonrası not:** Hoca üçüncü yöntemi anlatırken bir yerde "bağımlı kaynakları sıfırladığımız" dedi. Doğrusu bağımsız kaynaklardır. Hoca Örnek 22'de de "içerideki bağımsız kaynakları sıfırlayıp" diye anlattı.

## 3. Maksimum Güç Aktarımı

### 3.1 İdeal Olmayan Kaynak ve Yük Gücü

Şimdiki soru şudur: İdeal olmayan bir gerilim kaynağına bağlanan yük direncindeki güç nasıl hesaplanır ve bu gücün en büyük olması için ne yapılmalıdır?

İdeal olmayan gerilim kaynağı, üzerindeki gerilimin tamamını yüke aktaramaz. Çünkü içinde parazit olarak seri bir direnç vardır ve gerilim bölücü gibi çalışır. Aynı şey akım kaynağı için de geçerlidir. İdeal olmayan akım kaynağı da akımının tamamını yüke aktaramaz, paralel direnci akım bölücü olarak etki eder. Hatırlatma olarak: Akım kaynağının paralel direnci sonsuza giderse, gerilim kaynağının seri direnci sıfıra giderse ideal duruma yaklaşılır.

$R_S$ dışarıdan bağlanan bir değer değildir, kaynağın kendi iç yapısından gelir. Kaynak devreye konulduğunda yanında bu direnç de gelir, kaldırılamaz.

Yük direncindeki güç $P_L = V_L I_L = \frac{V_L^2}{R_L}$ ile verilir. Yük gerilimi, devreden geçen akım ile $R_L$'nin çarpımıdır:

$$V_L = \frac{V_S}{R_L + R_S}\, R_L$$

Bunu güç ifadesine koyup düzenleyince:

$$P_L = \left(\frac{V_S R_L}{R_L + R_S}\right)^2 \frac{1}{R_L} = \frac{V_S^2 R_L}{(R_L + R_S)^2}$$

### 3.2 Uç Durumlar: Tek Tepeli Eğri

$R_L$ hem payda hem de paydada bulunur, bu yüzden değiştiğinde iki terim birden değişir. Uç değerlere bakılırsa $R_L = 0$ iken de $R_L \to \infty$ iken de güç sıfırdır. Arada ise güç pozitiftir. Demek ki $P_{R_L}$ eğrisi tek tepeli bir yapıdadır ve bu tepenin hangi $R_L$ değerinde oluştuğu bulunabilir.

> **Ders sonrası not:** Hoca toparlarken $R_L = 0$ için "akım akmıyor" dedi. Doğrusu, $R_L = 0$ iken akım $V_S/R_S$ değerindedir ve güç, yük gerilimi sıfır olduğu için sıfırdır. Akımın sıfır olduğu durum $R_L \to \infty$ durumudur. Bu sonuç 3.1'deki formüllerden görülür.

### 3.3 Türev ile Tepe Noktası

Tepe noktası, $P_L$'nin $R_L$'ye göre türevinin sıfır olduğu noktadır. İfade iki çarpan biçiminde yazılır:

$$P_L = V_S^2 \cdot R_L \cdot (R_S + R_L)^{-2}$$

Hoca çarpım kuralını hatırlattı: $x$ ve $y$ aynı değişkene bağlı iki fonksiyonsa $(xy)' = x'y + xy'$ olur. $V_S^2$ sabit olarak dışarı alınır. Birinci çarpan $R_L$'nin türevi 1'dir. İkinci çarpanın türevinde $-2$ öne gelir, üs bir azalır. İç türev 1 olduğu için başka terim gelmez:

$$\frac{dP_L}{dR_L} = V_S^2\left[(R_S + R_L)^{-2} + R_L\,(-2)\,(R_S + R_L)^{-3}\right] = 0$$

$V_S$ sıfır olamaz, çünkü o durumda güç hesabının anlamı kalmaz. Öyleyse köşeli parantez sıfırdır. İkinci terim karşıya atılır:

$$(R_S + R_L)^{-2} = 2R_L\,(R_S + R_L)^{-3}$$

Her iki taraf $(R_S + R_L)^3$ ile çarpılırsa (ara adım eklendi) $R_S + R_L = 2R_L$ kalır, yani:

$$R_L = R_S$$

Hoca tahtada önce $(R_S+R_L)^{-2}$ yerine $(R_S+R_L)^{2}$ yazmıştı. Denklem tutmayınca durup kontrol etti, sınıftan gelen uyarıyla üssü $-2$ olarak düzeltti. Slaytta aynı türev, bölüm kuralıyla yazılmıştı. İki yol aynı hesaba çıkar.

Sonucun anlamı şudur: İdeal olmayan bir gerilim kaynağından en büyük gücü çekebilmek için yük direnci kaynak iç direncine eşit olmalıdır. Bu değer $P_L$ ifadesinde yerine konursa (ara adım eklendi):

$$P_{max} = \frac{V_S^2 R_S}{(2R_S)^2} = \frac{V_S^2}{4R_S}$$

> **Ek bilgi (derste anlatılmadı):** $R_L = R_S$ iken aynı akım iki eşit dirençten geçtiği için kaynağın verdiği gücün yarısı iç dirençte, yarısı yükte harcanır. Yani verim %50'dir (python ile hesaplandı). Bu nedenle, kısa notta da yazdığı gibi, verimin önemli olduğu güç sistemlerinde bu koşul büyük olasılıkla aranmaz. Haberleşme ve sinyal devrelerinde ise küçük bir sinyalden en fazla gücü almak için büyük olasılıkla kullanılır.

### 3.4 Genelleme: Herhangi Bir Doğrusal Devre

Bu sonuç yalnız ideal olmayan kaynaklar için değildir. Doğrusal elemanlardan oluşan herhangi bir karmaşık devre, Thevenin eşdeğerine indirgenebilir. O zaman iç direncin yerini devrenin $R_{TH}$ değeri alır. Doğrusal elemanlardan oluşan karmaşık bir devrede, yük direnci $R_{TH}$'ye eşit seçildiğinde yüke en büyük güç aktarılır:

$$R_L = R_{TH}, \qquad P_{max} = \frac{V_{TH}^2}{4R_{TH}}$$

## 4. Örnek 22: Ortak Emitörlü BJT Küçük Sinyal Devresinde Maksimum Güç

### 4.1 Devrenin Kaynağı

Bu devre alışılan yapılardan biraz farklıdır. Elektronik Devreler dersinde görülecek olan BJT transistörün küçük genlik eşdeğer devresidir. Hoca devrenin nereden geldiğini şöyle anlattı: BJT'yi koşullamak için bazı DC kaynaklar kullanılır ve bunlara göre devrenin bir çalışma noktası oluşur. BJT kuvvetlendirme için de kullanılabilir. Kuvvetlendirilecek düşük genlikli AC işaret, süperpozisyondan yararlanılarak bir kapasite üzerinden ilgili uçlara verilir. Bağımlı kaynağın katsayısı, DC koşullamadan oluşan durumla ilişkilidir. Çalışma noktası bir doğru üzerindedir, giriş bu nokta etrafında salınır, çıkış da aynı nokta civarında bu fonksiyona göre salınım yapar. Küçük genlik eşdeğer devresi bu mantıkla elde edilir.

Devre şöyledir:

- Giriş tarafı: $2.5\sin(440t)$ mV kaynak ve seri 300 Ω. Ardından birbirine paralel 17 kΩ ve 5 kΩ. Bu paralel dirençlerin uçlarındaki gerilim $v_\pi$'dir.
- Çıkış tarafı: $0.03\,v_\pi$ değerinde bağımlı akım kaynağı, ona paralel 1 kΩ ve yük direnci $R_L$.

<!-- BELİRSİZ: Giriş kaynağı, 300 Ω, 17 kΩ ve 5 kΩ değerleri altyazıda söylenmiyor, slaytta kalmış olmalı. Değerler kısa nottan alındı. Altyazıda yalnız 0.03 çarpanı ve 1 kΩ geçiyor. -->

### 4.2 Yük Direncinin Değeri

Soru, yükten çekilen gücün en büyük olması için $R_L$'nin ne olması gerektiğidir. Devre karmaşık görünse de problem, $R_L$ çıkarıldığında terminallerden içeri bakınca görülen eşdeğer dirence iner.

Hoca bu örnekte dördüncü yönteme gerek olmadığını, üçüncü yöntemle çözülebileceğini söyledi. Çünkü bağımlı kaynağın kontrol gerilimi $v_\pi$, girişteki bağımsız kaynağa bağlıdır. Çözüm adımları şöyledir:

1. Giriş kaynağı sıfırlanır, yerine tel gelir.
2. Giriş tarafının iki ucu aynı tel üzerinde olduğu için aralarında gerilim farkı yoktur. Bu kısımdaki elemanlardan akım geçmez.
3. Dolayısıyla $v_\pi = 0$ olur ve bağımlı akım kaynağının akımı sıfırdır.
4. Terminallerden bakınca yalnız 1 kΩ görülür: $R_{TH} = 1$ kΩ.

Öyleyse en büyük güç için $R_L = 1$ kΩ bağlanmalıdır.

> **Ders sonrası not:** Hoca bu noktada "eşdeğer direncimiz aynı zamanda VTH'ye eşit" dedi. Kastettiği $R_{TH}$'dir.

### 4.3 Maksimum Gücün Hesabı

Çekilen en büyük güç için açık devre gerilimi gerekir, bu da Thevenin gerilimidir.

**Birinci adım, $v_\pi$.** Birbirine paralel iki direnç ve onlara seri bir direnç vardır. Gerilim bölücü kullanılır (sayısal ara adımlar eklendi):

$$17\,\text{k} \parallel 5\,\text{k} = \frac{17000 \cdot 5000}{22000} \approx 3863.6\ \Omega$$

$$v_\pi = 2.5\sin(440t)\,\text{mV} \cdot \frac{3863.6}{300 + 3863.6} \approx 2.320\sin(440t)\ \text{mV}$$

**İkinci adım, $v_{oc}$.** Açık devrede bağımlı kaynağın akımının tamamı 1 kΩ üzerinden akar:

$$|v_{oc}| = 0.03\,v_\pi \cdot 1000 = 30\,v_\pi \approx 69.60\sin(440t)\ \text{mV}$$

<!-- BELİRSİZ: Bağımlı kaynağın yönü altyazıda belirtilmiyor. Kısa not v_oc = -0.03 v_pi 1000 yazıyor, hoca işaret söylemeden "0.03 VP çarpı 1K" dedi. Güç hesabı işaretten etkilenmez. -->

**Üçüncü adım, güç.** $V_{TH}$ ve $R_{TH}$ bilindiğine göre, 1 kΩ yük bağlıyken:

$$P_{max} = \frac{v_{oc}^2}{4R_{TH}} = \frac{(69.60\,\text{mV})^2\sin^2(440t)}{4 \cdot 1000\ \Omega} \approx 1.211\sin^2(440t)\ \mu\text{W}$$

> **Ders sonrası not:** Hoca bu hesabın sayısal sonucunu söylemedi. Yukarıdaki sayılar kısa nottaki devre değerleriyle python ile hesaplandı: $v_\pi$ genliği 2.3199 mV, $v_{oc}$ genliği 69.596 mV, $P_{max}$ genliği 1.2109 µW.

Hoca bu sorudaki önemli noktayı yineledi: Doğrusal elemanlardan oluşan karmaşık devrenin yüküne en büyük güç, yük direnci devrenin $R_{TH}$ değerine eşit olduğunda aktarılır.

<!-- BELİRSİZ: Hoca bir yerde "bu şu ikisinin paralelliğinden geliyor" dedi. Hangi değeri gösterdiği altyazıdan anlaşılmıyor; büyük olasılıkla slayttaki 17 kΩ ile 5 kΩ ifadesi. -->

## 5. Örnek 23: Bağımlı Kaynaklı Devrede Süperpozisyon

Bu ve sonraki iki örnek, genel tekrar örnekleridir. Burada süperpozisyonla $i_o$ akımı isteniyor. Devrede iki bağımsız kaynak (4 A ve 20 V) vardır, bu yüzden iki alt devre çözülür. Her seferinde bir bağımsız kaynak devrede bırakılır, diğeri sıfırlanır. Bağımlı $5i_o$ kaynağı iki alt devrede de kalır. Her alt devrenin $i_o$'ya katkısı yönüne dikkat edilerek toplanır.

### 5.1 Yalnız 4 A Devredeyken

20 V kaynağı sıfırlanır, yani yerine kısa devre konur. Geriye 4 Ω direnç kalır. Devrede üç düğüm ve üç çevre vardır. İkisi de eşdeğer olduğu için çevrelerle ilerlenir, çevre akımları $i_1, i_2, i_3$ olsun.

- Birinci çevre, akım kaynağının çevresidir: $i_1 = 4$ A.
- İkinci çevre: $3(i_2 - i_1) + 2i_2 - 5i_o + (i_2 - i_3) = 0$
- Üçüncü çevre: $5(i_3 - i_1) + (i_3 - i_2) + 5i_o + 4i_3 = 0$

Bilinmeyenler $i_2, i_3, i_o$ iken bu iki denklem yetmez. Üçüncü denklem, $i_o$'nun aktığı koldan gelir:

$$i_o = i_1 - i_3$$

**Soru:** Değişken sayısı dört değil mi, $i_o$ da var? **Cevap:** $i_1$ bilindiği için $i_2$, $i_3$ ve $i_o$ kalır. Bunlar için de üç denklem vardır.

Hoca hesap kolay olsun diye $i_1$'i de dahil edip dört denklemli matris yazdı. İkinci çevrede $i_2$ katsayısı $3 + 2 + 1 = 6$, üçüncü çevrede $i_3$ katsayısı $5 + 1 + 4 = 10$'dur:

$$\underbrace{\begin{bmatrix} 1 & 0 & 0 & 0 \\ -3 & 6 & -1 & -5 \\ -5 & -1 & 10 & 5 \\ 1 & 0 & -1 & -1 \end{bmatrix}}_{A} \begin{bmatrix} i_1 \\ i_2 \\ i_3 \\ i_o \end{bmatrix} = \begin{bmatrix} 4 \\ 0 \\ 0 \\ 0 \end{bmatrix}$$

$A^{-1}$ ile sağdaki vektör çarpılırsa $4 \times 1$ bir sonuç vektörü çıkar, dördüncü satırı $i_o'$'dur. Bu, yalnız 4 A devredeyken oluşan akımdır.

### 5.2 Yalnız 20 V Devredeyken

4 A kaynağı sıfırlanır, yani açık devre yapılır. Yeni devrede iki çevre kalır. 3 Ω ile 2 Ω aynı çevrede seri olur. İkinci çevrede 5 Ω, 1 Ω, $5i_o$ kaynağı, 4 Ω ve 20 V vardır. Üçüncü denklem $i_o$ kolundan gelir. Bu koldaki $i_o$, $i_2$ çevre akımıyla ters yönlüdür:

- Birinci çevre: $5i_1 - 5i_o + (i_1 - i_2) = 0$
- İkinci çevre: $5i_2 + (i_2 - i_1) + 5i_o + 4i_2 - 20 = 0$
- Kol denklemi: $i_o = -i_2$

Hoca ikinci denklemi önce kaynağı unutarak yazdı. Bir öğrencinin "ikinci denklemde eksi 20 olmayacak mı?" uyarısıyla düzeltti. Denklem sistemi şöyledir:

$$\underbrace{\begin{bmatrix} 6 & -1 & -5 \\ -1 & 10 & 5 \\ 0 & 1 & 1 \end{bmatrix}}_{B} \begin{bmatrix} i_1 \\ i_2 \\ i_o \end{bmatrix} = \begin{bmatrix} 0 \\ 20 \\ 0 \end{bmatrix}$$

$B^{-1}$ ile sağdaki vektör çarpılınca sonuç vektörünün üçüncü satırı $i_o''$'dur.

### 5.3 Süperpozisyon

Toplam akım, iki katkının yönlü toplamıdır:

$$i_o = i_o' + i_o''$$

> **Ders sonrası not:** Hoca matrisleri kurdu ama sayısal sonucu söylemedi. Sistemler python ile (kesirli aritmetikle) çözüldü. Yalnız 4 A için $i_2 = 80/17$, $i_3 = 16/17$, $i_o' = 52/17 \approx 3.059$ A. Yalnız 20 V için $i_1 = -40/17$, $i_2 = 60/17$, $i_o'' = -60/17 \approx -3.529$ A. Toplam $i_o = -8/17 \approx -0.4706$ A. İki kaynak birlikte devredeyken kurulan tek sistem de python ile aynı sonucu verdi.

<!-- BELİRSİZ: Devrenin çizimi altyazıda yalnız sözlü geçiyor. Elemanların yerleşimi yazılan çevre denklemlerinden kuruldu. İkinci çevre denklemindeki 5i_o işareti konuşmada net değil, matristeki "eksi 5" satırına göre yazıldı. -->

## 6. Örnek 24: Bağımlı Akım Kaynağı ile Kaynak Dönüşümü

Burada kaynak dönüşümü yöntemiyle $v_x$ isteniyor. Farklı olan, devrede $0.25\,v_x$ değerinde bir bağımlı akım kaynağı ve ona bağlı 4 Ω direnç bulunmasıdır.

**Soru (hocadan):** Bu bağımlı kaynak ile 4 Ω ikilisini kaynak dönüşümüne sokarsak yerine ne bağlarız? **Cevap (öğrenciden):** Seri bir direnç ve bağımlı bir gerilim kaynağı olur.

Yeni kaynağın değeri $4 \times 0.25\,v_x = v_x$, direnci yine 4 Ω'dur. Önemli olan, kaynak $v_x$ gerilimine bağlı olduğu için $v_x$ geriliminin korunması gerektiğidir. Çözüm adımları şöyledir:

1. Bağımlı akım kaynağı ile 4 Ω, değeri $v_x$ olan bağımlı gerilim kaynağı ile seri 4 Ω'a dönüşür.
2. Soldaki 6 V kaynak ve seri 2 Ω, 3 A akım kaynağı ve paralel 2 Ω'a dönüşür.
3. Bu 2 Ω, $v_x$'in ölçüldüğü düğümler arasındaki 2 Ω'a paraleldir. İkisinin yerine 1 Ω eşdeğer direnç konur.
4. Kalan 3 A ve 1 Ω tekrar dönüştürülür: 3 V ve seri 1 Ω.
5. $v_x$'in tanımlı olduğu düğüm çifti bozulmamıştır. Devrede sırayla 3 V kaynak, 1 Ω, değeri $v_x$ olan bağımlı kaynak, 4 Ω ve 18 V kaynak kalır.

Bütün devreyi dolaşan çevre için, $i$ koldaki akım olmak üzere:

$$-3 + i + v_x + 4i + 18 = 0 \quad\Rightarrow\quad v_x + 5i = -15$$

$v_x$ için küçük çevreden ikinci denklem yazılır:

$$-3 + i + v_x = 0 \quad\Rightarrow\quad v_x + i = 3$$

Taraf tarafa çıkarılınca $4i = -18$, yani $i = -\frac{18}{4} = -4.5$ A bulunur. İkinci denklemde yerine konursa:

$$v_x = 3 - i = 3 + \frac{18}{4} = \frac{30}{4} = 7.5\ \text{V}$$

Sonuç python ile doğrulandı. Hoca bu sorudaki ilginç noktayı, bağımlı akım kaynağı ile paralel direncin bağımlı gerilim kaynağı ve seri direnç biçiminde hesaba katılması olarak gösterdi.

**Burası neden bozulmadı?** Hocanın cevabı: $v_x$ referansını kaybetmemek için. İki direnç birleştirilip bir dönüşüm daha yapılsaydı, referans olarak gereken $v_x$ gerilimi kaybolacaktı.

<!-- BELİRSİZ: Hocanın "şu iki direnci birleştirip" derken hangi dirençleri gösterdiği altyazıdan anlaşılmıyor. Hoca 2 Ω ile 2 Ω'u 3. adımda birleştirdiği için büyük olasılıkla kastettiği, v_x düğümünün iki yanında kalan 1 Ω ve 4 Ω'dur. -->

> **Ders sonrası not:** Hoca soruyu sorarken ikili için "seri direnç", soruyu bitirirken de "bağımlı gerilim kaynağı ile paralel direnç" dedi. Dönüştürülen ikili, bağımlı akım kaynağı ve ona paralel dirençtir. Ayrıca kısa notta bu örnek için verilen $\frac{v_x-6}{2} + \frac{v_x}{2} + \frac{v_x-18}{4} - 0.25\,v_x = 0$ düğüm denklemi derste yazılmadı, hoca çevre denklemleriyle çözdü. Bu denklem de python ile hesaplandığında $v_x = 7.5$ V verir.

## 7. Örnek 25: Bağımlı Kaynaklı Devrenin Thevenin Eşdeğeri

Devrede 5 A akım kaynağı, uçlarında $v_x$ ölçülen 4 Ω, iki düğüm arasında 2 Ω ve ona paralel $2v_x$ bağımlı gerilim kaynağı, 6 Ω ve $a$ ucuna giden 2 Ω vardır. İçeride bağımlı kaynak olduğu için plan şudur: $V_{TH}$ açık devre geriliminden bulunur, $R_{TH}$ için bağımsız kaynak sıfırlanıp test kaynağı bağlanır.

<!-- BELİRSİZ: Devre çizimi altyazıda yalnız sözlü geçiyor. Yukarıdaki yerleşim, hocanın yazdığı düğüm denklemlerinden ve kısa nottan kuruldu. -->

### 7.1 Açık Devre Gerilimi

Uçlar açık olduğu için $a$ ucuna giden 2 Ω'dan akım akmaz, bu direnç düz tel gibi düşünülür. Aranan, 6 Ω üzerindeki gerilimdir. Referans dışında iki düğüm vardır: $V_1$ ve $V_2$.

Bağımlı kaynak için özel bir durum vardır. Bu kaynak kolunun akımını kendisi belirlemez, diğer elemanlar belirler. Bu yüzden kaynak ilk anda yalnız $V_1$ ile $V_2$ arasındaki gerilim farkını kurmak için kullanıldı.

**İlk deneme.** Hoca önce $V_1 - V_2 = 2v_x$ yazıp bunu $5 = \frac{2v_x}{2} + \frac{v_x}{4}$ denkleminde kullandı. Buradan $\frac{5v_x}{4} = 5$, yani $v_x = 4$ V, $V_1 = 4$ V ve $V_2 = 4 - 8 = -4$ V çıktı. Hoca bu sonucu, kaynağın ters yönde konulmuş gibi olması olarak yorumladı. Bir öğrenci $V_1 - V_2$ ifadesini yeniden sorunca hesap kontrol edildi.

**Kaynağın kutbu.** Referanstan çıkılır, 6 Ω'a eksi ucundan girilir, sonra bağımlı kaynağa artı ucundan girilir ve 4 Ω'a artı ucundan girilerek referansa dönülür:

$$-V_2 + 2v_x + V_1 = 0 \quad\Rightarrow\quad V_1 - V_2 = -2v_x$$

Bir öğrencinin önerdiği kısa düşünce de aynı yere çıkar: Kaynağın artı ucu eksi ucundan $2v_x$ yüksektir, yani $V_2$, $V_1$'den $2v_x$ fazladır. 4 Ω doğrudan $V_1$ düğümü ile referans arasında olduğu için $V_1 = v_x$'tir. Öyleyse:

$$V_2 = V_1 + 2v_x = 3v_x$$

**Eksik kalan akım.** Hoca, bağımlı kaynak kolunun akımı bilinmediği için denklemin eksik kaldığını gördü ve bu akıma $i$ dedi. Ders sırasında bir öğrenci $v_x/4$ teriminin de yazılıp yazılmadığını sorunca o terim de denkleme eklendi. Düğüm denklemleri şöyledir:

$V_1$ düğümü (5 A giriyor, diğerleri çıkıyor):

$$5 = \frac{v_x}{4} + \frac{V_1 - V_2}{2} + i = \frac{v_x}{4} + \frac{-2v_x}{2} + i \quad\Rightarrow\quad -\frac{3v_x}{4} + i = 5$$

$V_2$ düğümü: Uçtaki kolda akım akmadığı için 2 Ω'dan ve bağımlı kaynak kolundan gelen akımların toplamı 6 Ω'a gitmek zorundadır:

$$\frac{V_1 - V_2}{2} + i = \frac{V_2}{6} \quad\Rightarrow\quad \frac{-2v_x}{2} + i = \frac{3v_x}{6} \quad\Rightarrow\quad -\frac{3v_x}{2} + i = 0$$

Taraf tarafa çıkarılınca $i$ gider:

$$-5 = -\frac{3v_x}{2} + \frac{3v_x}{4} = -\frac{3v_x}{4} \quad\Rightarrow\quad v_x = \frac{20}{3}\ \text{V}$$

Bu durumda $V_2 = 3v_x = 20$ V olur. Açık devre gerilimi $V_2$ olduğundan:

$$V_{TH} = V_{OC} = 20\ \text{V}$$

### 7.2 Thevenin Direnci

İçerideki 5 A kaynağı sıfırlanır, yani açık devre yapılır. Uçlara 1 V test gerilim kaynağı bağlanır. Hoca önce uçlardaki gerilimi $3v_x$ üzerinden yazan bir yol denedi, tamamlamadan bıraktı, sonra yöntemi Thevenin eşdeğeri üzerinden yeniden hatırlattı: O devrede de gerilim kaynağı kısa devre yapılır, uçlara test kaynağı bağlanır, oradaki akım ve gerilimin oranı $R_{TH}$'yi verir. Dolayısıyla burada 1 V kaynağının bulunduğu koldaki akım gereklidir.

Yine düğümlerle ilerlenir. $V_1$ düğümünde bütün akımlar çıkış yönlüdür:

$$\frac{v_x}{4} + \frac{V_1 - V_2}{2} + i = 0$$

$V_2$ düğümünde $V_1$ tarafından gelen akım, test kaynağı tarafından gelen $\frac{1 - V_2}{2}$ akımı ve bağımlı kaynak kolundan gelen $i$ giriş yönlü, 6 Ω'a giden akım çıkış yönlüdür:

$$\frac{V_1 - V_2}{2} + \frac{1 - V_2}{2} - \frac{V_2}{6} + i = 0$$

Önceki bağıntılar aynen geçerlidir: $V_1 = v_x$, $V_1 - V_2 = -2v_x$, $V_2 = 3v_x$. Yerine konunca:

$$\frac{v_x}{4} - v_x + i = 0 \quad\Rightarrow\quad -\frac{3v_x}{4} + i = 0$$

$$-v_x + \frac{1 - 3v_x}{2} - \frac{3v_x}{6} + i = 0 \quad\Rightarrow\quad -3v_x + \frac{1}{2} + i = 0$$

Taraf tarafa çıkarılınca:

$$3v_x - \frac{3v_x}{4} = \frac{1}{2} \quad\Rightarrow\quad \frac{9v_x}{4} = \frac{1}{2} \quad\Rightarrow\quad v_x = \frac{2}{9}\ \text{V}$$

$V_2 = 3v_x = \frac{2}{3}$ V olur. Test kaynağının bulunduğu koldaki akım:

$$I_{test} = \frac{1 - 2/3}{2} = \frac{1}{6}\ \text{A} \quad\Rightarrow\quad R_{TH} = \frac{1\ \text{V}}{1/6\ \text{A}} = 6\ \Omega$$

Sonuç: $V_{TH} = 20$ V, $R_{TH} = 6$ Ω. Hocanın yorumu: İşlem hataları yüzünden biraz uzun sürdü. Slaytta çözümün çevrelerle yapıldığını da gösterdi, belki çevrelerle daha kolay olduğunu söyledi.

**Soru:** Bağımlı kaynak için ayrı bir denklem yazmıyor muyduk? Burada neden $i$'yi ayrıca denkleme kattık? Kaynak kolunu kesip doğrudan $V_2 - V_1 = 2v_x$ yazmamız gerekmez miydi? **Cevap:** Bu denklem zaten yazıldı. Ama o koldan da akım akar. Hoca denklemleri en genel haliyle yazarak çözmeyi seçti. Bu koldaki akım $i$ olarak bırakıldı, değeri bilinmiyor. Aynı $i$ öbür düğümde de göründüğü için süper düğüm mantığına benzer bir yapı çıkıyor. Ama burada süper düğüm yöntemi kullanılmadı. Kullanılsaydı kol kesilirdi.

> **Ders sonrası not:** İlk denemedeki $-4$ V sonucunun iki nedeni vardır. Birincisi $V_1 - V_2$'nin işaretidir. İkincisi denklemde bağımlı kaynak kolunun akımının yer almamasıdır. Yalnız işaret düzeltilip $i$ yazılmasaydı $v_x = -20/3$ V ve $V_2 = -20$ V çıkardı (python ile hesaplandı). Hocanın kullanmadığı süper düğüm denklemi $5 = \frac{V_1}{4} + \frac{V_2}{6}$ de $V_2 = 3V_1$ ile aynı sonucu verir. Kısa devre akımıyla yapılan kontrol $I_{SC} = 10/3$ A ve $V_{OC}/I_{SC} = 6$ Ω verir. Bu kontrollerin hepsi python ile hesaplandı. Kısa notta geçen Norton eşdeğeri derste hesaplanmadı. Kaynak dönüşümüyle $I_N = 20/6 = 10/3$ A, $R_N = 6$ Ω olur (python ile hesaplandı).

## 8. Kapasite Elemanı: Yapı, Türler ve Pratik Bilgiler

Bu noktada teoremler bitti. Bundan sonraki konu, enerji depolayan elemanlar olan kapasite ve endüktanstır. Hoca bu elemanların genel davranışlarını ve özelliklerini tanıttı.

### 8.1 Yapı ve Kapasiteyi Belirleyen Etkenler

Kapasite temel olarak enerji depolayabilen bir elemandır. Devrede şarj edilmiş bir kapasite varken kaynaklar çekilse bile devrede bir süre daha akım ve gerilim oluşur. Bunun nedeni, kapasitenin depoladığı yük sayesinde enerjisini devreye geri vermesidir.

Yapısı iki plaka ve aralarındaki dielektrik malzemeden oluşur. Bir kapasitenin yük tutabilme miktarını belirleyen $C$ değeri üç şeye bağlıdır:

- **Elektrik sabiti:** Kullanılan dielektrik malzemenin elektrik sabiti arttıkça $C$ artar.
- **Plaka alanı:** Paralel plakaların alanı büyüdükçe yük depolama kapasitesi artar.
- **Plakalar arası mesafe:** Mesafe azaldıkça $C$ artar. Hocanın açıklaması: Mesafe azaldıkça bir plakanın karşı plakaya etkisi daha net olur, çünkü yükün kuvveti mesafeyle karesel olarak azalıyordu.

Yani kapasite alanla ve elektrik sabitiyle doğru, mesafeyle ters orantılıdır.

### 8.2 Seramik ve Elektrolitik Kapasiteler

Sabit değerli kapasiteler için pratikte iki yapı vardır: seramik kapasiteler ve elektrolitik kapasiteler. Hoca, deney yapılsaydı bunların "mercimek" ve "silindirik" kapasiteler olarak kullanılacağını söyledi.

- **Seramik (polarize olmayan) kapasiteler:** Yönleri yoktur, iki uç da değişimli kullanılabilir. Şematikte birbirine paralel ve eşit boyutlu iki plakayla gösterilir.
- **Elektrolitik kapasiteler:** Artı ve eksi uçları tanımlıdır. Şematikte eksi taraf eğik bir çizgiyle gösterilir ya da artı tarafa artı işareti konur. Simülasyonda mikrofarad mertebesinde bir kapasite kullanılırsa, elektrolitik model olma ihtimali vardır.

> **Hocanın vurgusu:** Elektrolitik kapasitede yöne özellikle dikkat edin. Devre ne kadar karmaşık olursa olsun eksi uç devrenin toprağına doğru yerleşmelidir. Ters takılırsa kapasite yanar ve zarar görür.

**Seramik kapasitede değer okuma.** Üzerinde yazan değer pikofarad cinsindendir. Dirençlerde olduğu gibi ilk iki rakam iki basamaklı bir sayıdır, üçüncü rakam bu sayının çarpılacağı 10'un kuvvetini verir. Yanındaki K harfi toleransla ilgilidir. Slayttaki örnek için:

$$10 \times 10^{2} = 1000\ \text{pF}$$

<!-- BELİRSİZ: Slayttaki kod altyazıda okunmuyor; kısa not "102" yazıyor. Altyazıda "10 üzeri 2, 10 çarpı 3" geçiyor, "10 çarpı 3" ifadesi 1000 sonucuna götürmediği için konuşma ya da altyazı hatası sayıldı. -->

Hoca, kapasitelerin toleranslarının genel olarak yüksek olduğunu da ekledi, bunu dirençlerdeki toleranslarla ilişkilendirdi.

### 8.3 Değişken ve Özel Kapasiteler

Değişken kapasitelerde mekanik bir hareketle plakaların net alanı değiştirilir, böylece kapasite değeri değişir. Mikroelektromekanik sistemler düzeyinde de kapasiteler yapılabilir. Yüksek gerilimi destekleyen özel kapasiteler de vardır.

> **Hocanın vurgusu:** Kapasitenin üzerinde hem kapasite değeri hem de desteklediği gerilim verilir. Her kapasite, desteklediği gerilim aralığında kullanılmalıdır.

## 9. Kapasite Elemanının Davranışı

### 9.1 Gerilim Süreklidir, Akım Süreksiz Olabilir

Bir kapasiteyi yükleyip devreden ayırdığımızı düşünelim. İki ucunu birbirine dokundurduğumuz anda kıvılcım oluşabilir. Bu, depolanan yükün bir anda çok yüksek bir akımla boşalması demektir. Hocanın aklımızda kalması için verdiği örnek budur: Kapasite bir pil üzerinden şarj edilip devreden çıkarılır, sonra iki ucu birbirine dokundurulur, bir anda kıvılcım oluşur. Akım bir anda çok yüksek bir değere çıkmıştır, yani akımda süreksizlik olabilir. Ama gerilim bütün $t$ anları için sürekli bir fonksiyondur, ani zıplama yapamaz.

> **Hocanın vurgusu:** Çok önemli: Kapasite akımında ani değişim olabilir, fakat kapasite gerilimi ani değişemez. Kapasiteli devre çözümlerinde kullanılacak temel kısıtlardan biri budur.

### 9.2 DC'de Açık Devre

Kapasite DC koşullarda açık devre eleman gibi çalışır. Hocanın verdiği aklımızda tutma yolu şematik gösterimdir: Sembole bakıldığında iki plaka arasında bir açıklık vardır.

Bu özellik, Elektronik Devreler dersinde BJT ve başka transistörlerin kuvvetlendirme mantığında kullanılacaktır. Hocanın örneğinde transistörün DC koşulları kaynaklar ve $R_1, R_2$ gibi dirençlerle kurulur, süperpozisyondan yararlanılarak bir çalışma noktası belirlenir, sonra küçük AC sinyal bir kapasite üzerinden bunun üzerine eklenir. Kapasitenin DC'de açık devre gibi davranması bu iki kısmı ayırabilmeyi sağlar.

### 9.3 İdeal Olmayan Kapasite

İdeal kapasite, şarj edilip devreden çıkarıldıktan sonra enerjisini korur. Gerçek kapasitede ise küçük kaçak akımlar yüzünden depolanan yük azar azar boşalır. Bu nedenle ideal olmayan bir kapasite, ideal bir kapasiteye paralel bir dirençle modellenir. Kaynak kaldırıldığında kapasite kendi iç direnci üzerinden yavaş yavaş deşarj olur. Modeldeki paralel direnç bu kapalı yolu oluşturur.

### 9.4 Depolanan Yükü Belirleyen Etkenler

Hoca, bir kapasiteye ne kadar yük yüklenebileceğini belirleyen üç etken saydı:

- **Kapasite değeri $C$:** $C$ ne kadar yüksekse o kadar fazla yük depolanabilir. Alan büyüdükçe $C$ büyüdüğü için depolanabilecek yük de artar.
- **Uygulanan gerilim farkı:** Hem ne kadar yük hem de ne kadar hızlı yük depolanacağını etkiler.
- **Başlangıçtaki yük:** Üzerinde hiç yük yoksa, akan elektronlar plakaya yerleşir, karşı plakadaki elektronları iter, orada pozitif yük kalır ve bir potansiyel farkı oluşur. Başlangıçta yük varsa, plakada depolu negatif yükler gelen elektronları iter.

> **Ders sonrası not:** Hoca $C$ için "birim zamanda o kadar fazla yük depolayabilir" dedi. Ders boyunca kullanılan $q = Cv$ bağıntısında zaman yoktur. $C$, belirli bir gerilimde depolanan toplam yükü belirler. Depolama hızı akıma bağlıdır.

Birim olarak yük coulomb, kapasite farad, gerilim volttur. Bu yüzden farad çarpı volt coulomb eder.

## 10. Kapasitenin Akım-Gerilim Bağıntısı ve Enerjisi

### 10.1 Akım-Gerilim Bağıntısı

Çıkış noktası iki bilgidir. Depolanan yük, kapasite değeri ile uç gerilimin çarpımıdır: $q = Cv_C$. Akım ise birim zamandaki net yük değişimidir, yani yükün zamana göre türevidir. İlk bağıntının iki tarafının türevi alınırsa ($C$ sabit olduğundan):

$$i_C = \frac{dq}{dt} = C\frac{dv_C}{dt}$$

Yorumu şudur: Kapasite uçlarındaki gerilimin değişim miktarı, elemandan akacak akımı belirler. Aynı ilişki integral biçiminde de yazılabilir. Akımın integrali toplam yükü verdiği için:

$$\int i_C\,dt = Cv_C \quad\Rightarrow\quad v_C = \frac{1}{C}\int i_C\,dt$$

Kapasitenin akım-gerilim ilişkisi bu yüzden integro-diferansiyel bir tanımlamadır.

> **Ek bilgi (derste anlatılmadı):** Bu integral büyük olasılıkla ders kitaplarında başlangıç gerilimiyle birlikte $v_C(t) = \frac{1}{C}\int_{t_0}^{t} i_C\,dt + v_C(t_0)$ biçiminde yazılır. Hocanın 9.4'te saydığı başlangıç yükü bu terimle ilişkilidir.

### 10.2 Güç ve Enerji

Güç, uç gerilim ile akımın çarpımıdır. $v_C$ olduğu gibi bırakılır, $i_C$ yerine türevli ifade yazılır:

$$p_C = v_C\, i_C = C\,v_C\,\frac{dv_C}{dt}$$

Enerji, gücün zamana göre integralidir. Bu integral $v_C$'ye göre alınırsa $\int v_C\,dv_C = \frac{v_C^2}{2}$ olur:

$$w_C = \frac{1}{2}Cv_C^2$$

$q = Cv_C$ kullanılarak enerji yük cinsinden de yazılabilir. Hem paya hem paydaya $C$ eklenirse üstte $C^2v_C^2 = q^2$, altta $2C$ kalır:

$$w_C = \frac{C^2v_C^2}{2C} = \frac{q^2}{2C}$$

> **Ders sonrası not:** Hoca enerji formülünü söylerken "1 bölü 2 C çarpı VC kare bölü 2" dedi. Bir kez daha 2'ye bölünmez, doğrusu $\frac{1}{2}Cv_C^2$'dir. Hemen ardından yapılan $q^2/2C$ dönüşümü de bunu gösterir. Hoca integral sınırları için de "eksi sonsuz ile artı sonsuz arası" dedi. Belirli bir ana kadar depolanan enerji için üst sınır büyük olasılıkla $t$ olmalıdır.

## 11. Şarj, Deşarj ve 5τ Kuralı

### 11.1 Şarjın Fiziksel Açıklaması

Kapasiteyi şarj etmek için uçlarına gerilim farkı uygulanır. Elektronlar plakaya kadar gelip orada yerleşir, karşı plakadaki elektronları iter ve orada artı yük kalır. Böylece plakalar arasında yavaş yavaş bir potansiyel farkı oluşur. Bu farkın sınırı uygulanan gerilimdir, kapasite şarj edildiği gerilimin üstüne çıkamaz.

Üzerinde hiç yük yokken kapasite gelen elektronları kolay kabul eder, daha hızlı şarj olur. Yüklendikçe yeni gelen elektronlara karşı koyma kuvveti artar. Bu nedenle şarj sırasındaki gerilim grafiği üstel (eksponansiyel) bir eğridir. Deşarjda da benzer bir durum vardır: Kapasite başta yüklerini yüksek akımla gönderebilir, zamanla karşı plakanın çekim etkisi yüzünden yüklerini bırakması gittikçe azalır. Deşarj da üstel bir fonksiyonla ifade edilir.

### 11.2 Şarj Denklemi ve Sınır Kontrolü

Slaytta $v(t)$ kapasite gerilimi, $V_C$ kaynak gerilimi olarak gösterilmiştir. $t = 0$ anında kaynağı bağlanan boş bir kapasite için:

$$v(t) = V_C\left(1 - e^{-t/\tau}\right)$$

Hoca bu denklemi şimdilik türetmedi. Bunlar diferansiyel denklem çözümünden elde edilir ve RC devrelerinin zaman bölgesindeki çözümünde net olarak çıkarılacaktır. Şu aşamada yalnız denklemin deneysel grafikle uyumu kontrol edildi:

- $t \to \infty$ iken $e^{-\infty} = \frac{1}{\infty} = 0$, parantez 1 olur, $v \to V_C$.
- $t = 0$ iken $e^{0} = 1$, parantez 0 olur, $v = 0$.

Yani gerilim sıfırdan başlar, kaynak gerilimine asimptotik olarak yaklaşır.

### 11.3 Deşarj Denklemi ve Sınır Kontrolü

Senaryo şudur: Eksi sonsuzdan beri şarj olan bir kapasite vardır. $t = 0$ anında kaynak devreden çıkarılır ya da sıfırlanır, geriye RC devresi kalır ve yük direnç üzerinden yavaş yavaş boşalır. Eksi sonsuzdan beri şarj olduğu için $t = 0$ anında kapasite gerilimi kaynak gerilimine eşit olmak zorundadır:

$$v(t) = V_C\,e^{-t/\tau}$$

- $t = 0$ iken $e^{0} = 1$, $v = V_C$.
- $t \to \infty$ iken $e^{-\infty} = 0$, $v \to 0$.

### 11.4 Zaman Sabiti ve 5τ Kuralı

$\tau$ (tau), zaman sabitidir. Eğrinin ne kadar dik olacağını, yani ne kadar hızlı oturacağını belirler ve RC devresindeki $R$ ile $C$ değerlerine bağlıdır. Hoca bunu şimdilik yalnız isim olarak bilmemizi istedi.

Slayttaki grafikler standarttır, kapasite değerinden bağımsız çizilebilir: Düşey eksende $v(t)/V_C$, yatay eksende $t/\tau$ vardır. Şarjda oran 1'e, deşarjda 0'a asimptotik olarak yaklaşır.

Pratik kural: $t/\tau = 5$ olduğunda oran tam 1 (deşarjda tam 0) olmaz, ama kapasite pratikte şarj (deşarj) olmuş kabul edilir.

> **Ek bilgi (derste anlatılmadı):** Kısa notta zaman sabiti $\tau = RC$ olarak geçer, altyazıda bu çarpım söylenmez. $t = 5\tau$ anında şarjda oran $1 - e^{-5} \approx 0.9933$, deşarjda $e^{-5} \approx 0.0067$ olur (python ile hesaplandı). Yani kalan fark %1'in altındadır.

> **Ders sonrası not:** Hoca grafiği anlatırken önce $V(t)$'yi kaynak değeri, $V_C$'yi kapasite gerilimi gibi söyledi. Sonra düzeltip $v(t)$'nin kapasite gerilimi, $V_C$'nin kaynak gerilimi olduğunu belirtti. Doğrusu ikincisidir. Grafikteki oran buna göre 1'e yaklaşır.

## 12. Seri ve Paralel Kapasitelerin Eşdeğeri

Eşdeğer kapasite şu anlamdadır: Terminallerdeki gerilim farkı ve geçen akım, birkaç kapasite yerine tek bir kapasite konduğunda da aynı kalıyorsa ikisi eşdeğerdir.

### 12.1 Paralel Bağlı Kapasiteler

Devre iki düğümlüdür, biri referanstır. Hoca önce kaynağı gerilim kaynağı gibi düşündü, sonra slayta bakıp akım kaynağı olduğunu söyleyerek düzeltti. AC bir işaret olsa bile referans yönü verilirse $i_{in}$, kol akımlarının toplamıdır:

$$i_{in} = i_1 + i_2 + i_3 + i_4$$

Elemanlar paralel olduğu için hepsinin üzerindeki gerilim $v$'dir. $C$ zamana bağlı olmadığından her kolda $i_k = C_k \dot{v}$ olur, burada $\dot{v} = \frac{dv}{dt}$:

$$i_{in} = C_1\dot{v} + C_2\dot{v} + C_3\dot{v} + C_4\dot{v} = (C_1 + C_2 + C_3 + C_4)\,\dot{v}$$

Hedeflenen eşdeğer devrede tek bir $C_{\text{eş}}$ vardır ve aynı $i_{in}$ ile aynı $v$ üretmelidir: $i_{in} = C_{\text{eş}}\dot{v}$. İki ifade eşleştirilince:

$$C_{\text{eş}} = C_1 + C_2 + C_3 + C_4$$

### 12.2 Seri Bağlı Kapasiteler

Seri bağlantıda eleman gerilimlerinin toplamı kaynak gerilimine eşittir: $v_{in} = v_1 + v_2 + v_3 + v_4$. Tanım bağıntısı $q = Cv$ yerine $\int i\,dt = Cv$ yazılır ve $C$ karşıya atılır. Seri elemanlardan aynı akım aktığı için:

$$v_{in} = \frac{1}{C_1}\int i\,dt + \frac{1}{C_2}\int i\,dt + \frac{1}{C_3}\int i\,dt + \frac{1}{C_4}\int i\,dt$$

Eşdeğer devrede ise $v_{in} = \frac{1}{C_{\text{eş}}}\int i\,dt$ olmalıdır. $\int i\,dt$ parantezine alınıp eşleştirilince:

$$\frac{1}{C_{\text{eş}}} = \frac{1}{C_1} + \frac{1}{C_2} + \frac{1}{C_3} + \frac{1}{C_4}$$

Seri kapasitelerin eşdeğeri, dirençlerin paralel bağlı olduğu durumdaki gibi hesaplanır.

### 12.3 Kapasite İçin Akılda Kalması Gerekenler

Hoca kapasiteyi şu maddelerle bitirdi:

- Kapasite enerji depolayan bir elemandır, enerjisini plakalarda yük depolayarak tutar.
- DC devrelerde açık devre eleman gibi davranır.
- 5τ geçtikten sonra pratikte şarj ya da deşarj olmuş kabul edilir.
- Paralel ve seri bağlantıda eşdeğer yukarıdaki gibi hesaplanır.

> **Hocanın vurgusu:** Çok önemli bir kural: Kapasitede akım ani değişim gösterebilir, gerilim gösteremez.

## 13. Endüktans Elemanı

### 13.1 Yapı

Endüktans, sargı biçiminde bir tel ve içindeki bir kordan oluşur. Kor hava olabileceği gibi başka malzemeler de olabilir. Şematikte sargılı tel olarak gösterilir. Farklı endüktans tiplerine hoca girmedi. Endüktans enerjisini manyetik alanda depolar.

> **Hocanın vurgusu:** Çok önemli bir özellik: DC şartlarda endüktans kısa devre eleman gibi davranır. Aklınızda şematik gösterimden kalsın: Bu, kıvrılmış ama sürekli bir teldir.

### 13.2 Referans Yönü ve Akım-Gerilim Bağıntısı

Endüktansta gerilim düşümü akım yönüne göre tanımlanır: Akım elemana artı uçtan girer, eksi uçtan çıkar. Hoca, elemanı enerji harcayan bir eleman gibi gösteren bu referans seçiminin notasyonda tutarlılık sağladığını söyledi.

Akımdaki değişim bir manyetik alan etkisi oluşturur, bu da eleman uçlarında gerilim farkına yol açar. Sözle anlatılan bu yapının denklemi şudur:

$$v_L = L\frac{di_L}{dt}$$

$L$ endüktans sabitidir, içerideki kora göre değişir. Kapasitede $q = Cv$ yazıldığı gibi endüktansta da akı ile tanımlama yapılır:

$$\phi = Li$$

Akı, gerilimin integraline karşılık gelir: $\phi = \int v\,dt$. Bu denklemden tıpkı kapasitede olduğu gibi türevli ve integralli yazımlar elde edilir. Yani endüktansın akım-gerilim ilişkisi de integro-diferansiyeldir.

### 13.3 Birimler

Endüktansın birimi henry, kapasitenin birimi farad'dır. Pratikte kapasitede nanofarad ve pikofarad gibi değerlerle uğraşılabilir, endüktanslar da genellikle milihenry mertebesindedir: 1 nF $= 10^{-9}$ F, 1 mH $= 10^{-3}$ H. Denklemlerde endüktans henry, kapasite farad cinsinden kullanılır. Piko, nano, mikro ve mili gibi önekli değerler denkleme konmadan önce bu birimlere çevrilmelidir.

### 13.4 Güç ve Enerji

Eleman üzerinde harcanan güç, akım ile gerilimin çarpımıdır. Akım bırakılır, gerilim yerine bağıntı yazılır. Bunun zamana göre integrali enerjiyi verir:

$$p_L = i_L\,v_L = L\,i_L\frac{di_L}{dt}, \qquad w_L = \frac{1}{2}Li_L^2$$

> **Ders sonrası not:** Hoca bu adımda "integral formülle yazarak" dedi. Güç ifadesinde kullanılan, $v_L = L\,di_L/dt$ türev formülüdür.

### 13.5 Akımın Sürekliliği

Kapasitedeki şarj ve deşarj eğrilerinin üstel olması gibi, endüktans için de benzer durumlar geçerlidir. Burada süreklilik akıma aittir: Endüktans uçlarındaki gerilim ani değişebilir, ama elemandan akan akım sürekli olmak zorundadır. Nedeni, endüktansın depoladığı manyetik enerjiyi bir seferde harcayamamasıdır.

### 13.6 Endüktans Değerinin Hesabı

Kapasitede olduğu gibi $L$ değeri de eleman yapısından hesaplanabilir. Hoca bunun sarım sayısına, kesit alanına, bir malzeme sabitine ve uzunluğa bağlı olduğunu söyledi. Formül kısa notta şöyle geçer:

$$L = \frac{N^2\mu A}{l}$$

<!-- BELİRSİZ: Formül slaytta kalmış, altyazıda yalnız bağlı olduğu büyüklükler sayılıyor. Formül kısa nottan alındı. -->

> **Ders sonrası not:** Hoca $\mu$ için "endüktans sabiti veya iletkenlik sabiti", $l$ için "telin toplam uzunluğu" dedi. $\mu$ büyük olasılıkla çekirdeğin manyetik geçirgenliğidir, $l$ de büyük olasılıkla telin açılmış uzunluğu değil sargının boyudur.

Bu formül sargılı tel içindir. Fakat pratikte düz bir telde bile endüktif etki vardır. Enerji hatları ya da iletim hatları (transmission line) modellenirken tel düz olsa bile endüktif yükle birlikte hesap yapılır.

### 13.7 İdeal Olmayan Endüktans ve Enerji Akışı

İdeal olmayan durumda telin kendi iç direnci ve endüktif etkisi vardır. Sargıda karşılıklı gelen teller arasında da kapasitif etki oluşur. Bu yüzden ideal olmayan bir endüktans, ideal endüktansa seri bir direnç ve bunlara paralel bir kapasite ile modellenir. Bu değerler küçüktür.

Enerji akışı açısından, kaynağa bağlıyken endüktans kaynaktan güç alır ve devrede güç tüketen bir eleman olarak görünür. Enerjisini depoladıktan sonra kaynak sistemden çıkarsa, depoladığı enerjiyi devreye verebilir.

## 14. Seri ve Paralel Endüktansların Eşdeğeri

### 14.1 Seri Bağlı Endüktanslar

Gerilim kaynağından sürülen seri endüktanslarda $v_{in} = v_1 + v_2 + v_3 + v_4$ yazılır. $\phi = Li$ ve $\phi = \int v\,dt$ olduğundan iki tarafın türevi alınırsa $v = L\dot{i}$ kalır, burada $\dot{i} = \frac{di}{dt}$. Tek gözlü devre olduğu için her elemandan aynı akım geçer, yalnız $L$ değerleri farklıdır:

$$v_{in} = L_1\dot{i} + L_2\dot{i} + L_3\dot{i} + L_4\dot{i} = (L_1 + L_2 + L_3 + L_4)\,\dot{i}$$

Eşdeğer devrede $v_{in} = L_{\text{eş}}\dot{i}$ olmalıdır. Eşleştirince:

$$L_{\text{eş}} = L_1 + L_2 + L_3 + L_4$$

Seri endüktanslar, seri dirençler gibi toplanır.

### 14.2 Paralel Bağlı Endüktanslar

Akım kaynağından sürülen paralel endüktanslarda $i_{in} = i_1 + i_2 + i_3 + i_4$ yazılır. Paralel oldukları için hepsinin üzerindeki gerilim aynıdır. $\int v\,dt = L_k i_k$ olduğundan $i_k = \frac{1}{L_k}\int v\,dt$ olur:

$$i_{in} = \left(\frac{1}{L_1} + \frac{1}{L_2} + \frac{1}{L_3} + \frac{1}{L_4}\right)\int v\,dt$$

Eşdeğer devrede $i_{in} = \frac{1}{L_{\text{eş}}}\int v\,dt$ olmalıdır. Eşleştirince:

$$\frac{1}{L_{\text{eş}}} = \frac{1}{L_1} + \frac{1}{L_2} + \frac{1}{L_3} + \frac{1}{L_4}$$

Bu da paralel dirençlerin eşdeğeri gibi hesaplanır.

> **Ders sonrası not:** Hoca bu bölümde iki yerde kelimeyi karıştırdı: Seri endüktansı anlatırken "kapasite elemanlarıyla ilgili olarak akı", paralel durumu açarken "paralel dirençler" dedi. Her ikisinde de kastedilen endüktanstır.

## Dersin Toparlaması

Bu derste teoremler bölümü kapatıldı. Maksimum güç aktarımı, türevle gösterilen $R_L = R_S$ sonucundan Thevenin eşdeğeri yoluyla bütün doğrusal devrelere genelleştirildi ve $R_L = R_{TH}$ koşulu elde edildi. Ardından bağımlı kaynaklı örneklerde süperpozisyon, kaynak dönüşümü ve test kaynağı yöntemleri uygulandı. Bu örneklerin ortak noktası, bağımlı kaynağın ve onu kontrol eden büyüklüğün çözüm boyunca korunmasıdır.

İkinci bölümde enerji depolayan iki eleman tanıtıldı. Kapasite yükü plakalarında tutar, $i = C\,dv/dt$ bağıntısına uyar, gerilimi süreklidir ve DC'de açık devre gibi davranır. Endüktans enerjisini manyetik alanda tutar, $v = L\,di/dt$ bağıntısına uyar, akımı süreklidir ve DC'de kısa devre gibi davranır. Kapasiteler paralelde toplanır, seride terslerinin toplamıyla birleşir. Endüktanslar ise dirençler gibi birleşir. Gelecek haftanın konusu, kaynaksız RL ve RLC devrelerinin zaman bölgesindeki çözümü ve bu elemanların DC davranışıdır. Şarj ve deşarj denklemlerinin türetilmesi de RC devrelerinin zaman bölgesi çözümünde yapılacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
