# Ders 7 Genişletilmiş Notu: Diyot Uygulamaları: Doğrultucular ve Kırpıcı Devreler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Diyot Modellerinin Tekrarı
- 2. Seri ve Paralel Diyot Konfigürasyonları
- 3. Doğrultma: AC'den DC'ye
- 4. Yarım Dalga Doğrultucu
- 5. Tam Dalga Köprü Doğrultucu
- 6. Doğrultucuların İdeal ve Gerçekçi DC Değerleri
- 7. Kırpıcılar (Clipper) ve Seri Kırpıcı
- 8. Seri Kaynaklı Kırpıcı Örneği
- 9. Paralel Kırpıcı
- 10. Değer Vererek Çıkış Çizme: Çözülen Örnekler
- Örnek Sorular
- Dersin Toparlaması

## 1. Diyot Modellerinin Tekrarı

Ders, önceki haftada görülen diyot konusunun kısa bir tekrarıyla başladı. Diyot sembolünde üçgenin olduğu taraf anot (artı uç), çizginin olduğu taraf katottur (eksi uç). Diyot üzerindeki gerilim anottan katoda doğru $V_D$ olarak tanımlanır.

### 1.1 İdeal diyot

İdeal diyotun $I_D$–$V_D$ grafiği iki parçadan oluşur: negatif gerilimlerde akım sıfırdır, $V_D$ sıfırı geçtiği anda akım akmaya başlar ve grafik dikey yükselir (ekrandan, 00:10:00). Buna göre:

- $V_D > 0$ ise diyot iletimdedir ve kısa devre (düz tel) gibi davranır; üzerinde gerilim düşmez.
- $V_D \le 0$ ise diyot kesimdedir ve açık devre gibi davranır; akım akmaz.

### 1.2 Gerçek diyot

Gerçek diyotun karakteristiği ideal çizim gibi değildir. Sıfırdan küçük gerilimlerde küçük bir sızıntı akımı akar; ileri yönde ise akım belirli bir diyot geriliminden sonra hızla artar. Hocanın tahtaya yazdığı eşik gerilimleri şunlardır (ekrandan, 00:10:00):

| Malzeme | Yaklaşık eşik gerilimi |
|---|---|
| Silisyum (Si) | 0,7 V |
| Germanyum (Ge) | 0,3 V |
| Galyum arsenit (GaAs) | 1,2 V |

> **Hocanın vurgusu:** Derste çoğunlukla silisyum diyot kullanılacağı için 0,7 V değeri akılda tutulmalıdır.

İdeal olmayan diyot, A ve B uçları arasında üç parçayla özetlenebilir: bir ideal diyot, diyotun iç direnci ($r_D$) ve aşılması gereken 0,7 V'luk potansiyel bariyeri. İdeal diyot iletime geçtiğinde üzerinde gerilim kalmazken, ideal olmayan diyot iletime geçtiğinde üzerinde 0,7 V'luk bir gerilim bulunur.

## 2. Seri ve Paralel Diyot Konfigürasyonları

### 2.1 Seri diyot

Slayttaki devrede bir $E$ kaynağı, seri bir silisyum diyot ve bir $R$ direnci vardır; çıkış gerilimi $V_R$ direnç üzerinden alınır (ekrandan, 00:05:00). Silisyum için analiz:

- $V_D = 0{,}7\ \text{V}$ (ya da $E < 0{,}7$ V ise diyot iletmez ve $V_D = E$ olur)
- $V_R = E - V_D$
- $I_D = I_R = I_T = V_R / R$

Uygulanan gerilim 0,7 V'tan büyükse diyot bariyeri açılır ve dirençten akım akmaya başlar. Hocanın sözlü örneğinde $E = 5$ V'tur: 0,7 V diyot üzerinde düşer, kalan $5 - 0{,}7 = 4{,}3$ V direnç üzerinde görülür. Direnç gerilimi direnç değerine bölünerek ana koldan geçen akım bulunur.

### 2.2 Paralel diyotlar

Hoca önceki haftada çözülen paralel diyot örneğini hatırlattı. İki özdeş silisyum diyot paralel bağlıdır; ikisinin anodunun bağlı olduğu B noktasının toprağa göre gerilimi, diyotlar iletimdeyken diyot gerilimine, yani 0,7 V'a eşittir. Kaynak $V_A = 10$ V olduğundan direnç üzerindeki gerilim:

$$V_R = V_A - V_B = 10 - 0{,}7 = 9{,}3\ \text{V}$$

Bu gerilim direnç değerine bölünerek ana kol akımı $I_1 \approx 28$ mA bulunur. B noktasında akım iki özdeş kola eşit bölünür; her diyottan yaklaşık 14 mA geçer. <!-- BELİRSİZ: direnç değeri altyazıda söylenmedi ve okunan karelerde görünmüyor -->

> **Ek bilgi (derste anlatılmadı):** Sonuç, direncin büyük olasılıkla $0{,}33\ \text{k}\Omega$ olduğu kitap örneğiyle uyumludur: $9{,}3 / 0{,}33\,\text{k}\Omega \approx 28{,}2$ mA ve kol başına yaklaşık 14,1 mA (python ile hesaplandı).

## 3. Doğrultma: AC'den DC'ye

Diyotların en önemli uygulamalarından biri doğrultuculardır. Duvardaki prizden sinüzoidal bir güç işareti alınır; bu tür işaretlere AC işaret denir. Şebeke işareti 220 V ve 50 Hz'tir. Oysa birçok cihaz zamanla değişmeyen, sabit bir DC gerilime ihtiyaç duyar. Hocanın örnekleri: laptop adaptörü (bir taraftan AC girer, diğer taraftan örneğin 19 V ya da 12 V DC çıkar), cep telefonu şarj cihazları ve LCD televizyonların güç katı.

Bir sinüs işaretinin bir periyot boyunca ortalaması sıfırdır. DC elde etmenin ilk adımı ortalamayı yukarı çekmektir:

- İşaretin negatif yarım periyodu sıfıra çekilirse ortalama yükselir. Buna yarım dalga doğrultma denir.
- Negatif yarım periyot pozitife çevrilirse ortalama daha da yükselir. Buna tam dalga doğrultma denir.

Ortalamanın yüksek olması, elde edilecek DC'nin daha yüksek ve daha verimli olması demektir. Doğrultmadan sonra kondansatörlü yapılarla pozitif tepeler arasındaki boşluklar doldurulur ve işaret olabildiğince düz bir DC gerilime dönüştürülmeye çalışılır. İngilizcede doğrultmaya *rectification*, doğrultucuya *rectifier* denir.

## 4. Yarım Dalga Doğrultucu

### 4.1 Devre ve çalışma

Devre bir giriş $v_i$, girişe seri bir diyot ve çıkışın alındığı bir $R$ direncinden oluşur (ekrandan, 00:20:00). Diyot ideal kabul edilir.

- Pozitif yarım periyot ($v_i > 0$): Diyot iletimdedir ve kısa devre gibidir; üzerinde gerilim düşmez. Girişin tamamı $R$ üzerinde oluşur: $v_o = v_i$.
- Negatif yarım periyot ($v_i < 0$): Diyot kesimdedir ve açık devre gibidir. Giriş ile çıkış arasında bağlantı kalmaz, akım akmaz: $v_o = 0$ V.

İki durum birleştirildiğinde çıkışta yalnız pozitif yarım periyotlar görülür. Diyotun bir yönde geçirip diğer yönde geçirmeme özelliği kullanılarak yarım dalga doğrultma yapılmış olur. Slayttaki ifadeyle: diyot yalnız doğru kutuplandığında iletir, bu yüzden AC periyodunun yalnız yarısı çıkışa geçer (ekrandan, 00:20:00).

### 4.2 Ortalama (DC) değer

Çıkışın bir periyot boyunca ortalaması, yani eğrinin altında kalan alanın periyoda bölümü:

$$V_{DC} = 0{,}318\,V_m$$

Burada $V_m$ giriş işaretinin tepe değeridir (ekrandan, 00:20:00). Hoca bu değerin integral hesabından bulunduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** $\frac{1}{T}\int_0^{T/2} V_m \sin(\omega t)\,dt = \frac{V_m}{\pi} \approx 0{,}318\,V_m$. Tam dalgada iki yarım periyot da pozitif olduğundan sonuç iki katına çıkar: $\frac{2V_m}{\pi} \approx 0{,}636\,V_m$. Her iki değer python ile sayısal olarak doğrulandı.

### 4.3 Soru-cevap

**Soru:** Dalga doğrultmanın amacı nedir? Ortalamayı yukarı çekmek mi?

**Cevap:** Amaç AC'den DC'ye geçmektir. Önce ortalama yukarı çekilir. Sonra kondansatörlü devrelerle pozitif tarafta kondansatör doldurulur ve bir sonraki tepeye kadar işaret daha az düşer; böylece dalgalı ama DC'ye yakın bir işaret elde edilir. Daha güçlü kondansatörlerle olabildiğince düz, DC'ye yakın bir işaret elde edilir.

## 5. Tam Dalga Köprü Doğrultucu

### 5.1 Devre

Basit yarım dalga doğrultucu bir diyot ve bir dirençten oluşurken, tam dalga doğrultucu köprü biçiminde bağlanmış dört diyot kullanır (köprü doğrultucu). Slayttaki devre (ekrandan, 00:25:00):

- Giriş $v_i$ (tepe değeri $V_m$ olan sinüs), köprünün üst ve alt düğümlerine, yani A ve B uçlarına uygulanır.
- Dört diyot D1, D2, D3, D4 köprünün dört kolundadır.
- Yük direnci $R$ köprünün sol ve sağ düğümleri arasındadır; çıkış $v_o$ bu direnç üzerinden alınır (eksi ucu solda, artı ucu sağda).

### 5.2 Pozitif yarım periyot

Pozitif yarım periyotta A noktasının gerilimi B noktasınınkinden yüksektir. D1'in diğer ucu B tarafına daha yakın olduğundan D1 iletmez; D2 iletir. Akım D2 üzerinden yük direncine gelir. D4 ters bağlı olduğundan akım oradan geçemez; D3 üzerinden B'ye döner. Yani D2 ve D3 iletimdedir. Bu iki diyot kısa devre kabul edilirse çıkıştaki $v_o$, girişin aynısıdır.

### 5.3 Negatif yarım periyot

Negatif yarım periyotta $V_{AB}$ negatiftir, yani A'nın gerilimi B'ye göre düşüktür. Bu durumda D1 ve D4 iletime geçer, D2 ve D3 kesimdedir; devre D1 ve D4 üzerinden tamamlanır (ekrandan, 00:30:00). Hoca bunu, B'den A'ya gidiliyormuş gibi düşünmek olarak anlattı.

Önemli olan yük direncinin uçlarıdır: yüksek gerilimli B tarafı direncin artı ucuna, düşük gerilimli A tarafı eksi ucuna bağlı kalır. Bu nedenle negatif giriş, artı-eksi yönlerinin bu şekilde seçilmesiyle çıkışta pozitif olarak görülür. Sonuç olarak bir $T$ periyodu boyunca işaretin iki yarısı da pozitife çevrilmiş olur.

### 5.4 Ortalama değer

Tam dalga doğrultucunun çıkış ortalaması:

$$V_{DC} = 0{,}636\,V_m$$

(ekrandan, 00:25:00). Yarım dalgaya göre iki kat daha büyüktür, çünkü her iki yarım periyotta da eğrinin altında pozitif alan kalır.

### 5.5 Transformatörlü tam dalga doğrultucu

Tam dalga doğrultma orta uçlu transformatörlü bir yapıyla da yapılabilir. Hoca transformatörlü yapıların daha çok eskiden kullanıldığını söyledi ve bu yapıların ayrıntısına girmedi; bilgi olarak bilinmesinin yeterli olduğunu belirtti.

### 5.6 Soru-cevap

**Soru:** Elimde hem yarım hem tam dalga doğrultucu varsa, tasarımda yarım dalga doğrultucuyu kullanmamın bir sebebi ya da avantajı olabilir mi?

**Cevap:** Hocanın cevabı altyazıda tam anlaşılmıyor; yalnızca tek yarıyı geçiren bir yapının istendiği bir durum düşünülebileceğini söylediği anlaşılıyor. <!-- BELİRSİZ: cevabın devamı altyazıda bozuk -->

## 6. Doğrultucuların İdeal ve Gerçekçi DC Değerleri

Buraya kadar iletimdeki diyotlar kısa devre kabul edildi. Diyotlar ideal değilse, iletimdeki her silisyum diyotun üzerinde 0,7 V düştüğü hesaba katılmalıdır. Slayttaki özet tablo (ekrandan, 00:35:00):

| Doğrultucu | İdeal $V_{DC}$ | Gerçekçi $V_{DC}$ |
|---|---|---|
| Yarım dalga | $0{,}318\,V_m$ | $0{,}318\,V_m - 0{,}7$ |
| Köprü (tam dalga) | $0{,}636\,V_m$ | $0{,}636\,V_m - 2(0{,}7\ \text{V})$ |
| Orta uçlu transformatörlü | $0{,}636\,V_m$ | $0{,}636\,V_m - 0{,}7\ \text{V}$ |

$V_m$, AC gerilimin tepe değeridir. Orta uçlu transformatörlü doğrultucuda tepe AC gerilim, transformatör sekonderinin orta uca kadarki gerilimidir (ekrandan, 00:35:00).

- Yarım dalga doğrultucuda tek diyot vardır; gerçekçi DC değerde bir diyot düşümü çıkarılır.
- Köprü doğrultucuda her yarım periyotta iki diyot birlikte iletimdedir; bu yüzden $2 \times 0{,}7$ V hesaba katılır.
- Transformatörlü yapıda iletim anında tek diyot çalışır.

> **Hocanın vurgusu:** Transformatörlü yapının ayrıntısının bilinmesine gerek yok, ama yarım dalga ve tam dalga doğrultucunun DC ortalamalarının bilinmesinde yarar var.

> **Ders sonrası not:** Tablodaki gerçekçi ifadeler slayttaki yaklaşık biçimdir. Diyot düşümü tepe değerden çıktığı için daha kesin ifade büyük olasılıkla $V_{DC} \approx 0{,}318\,(V_m - 0{,}7)$ (yarım dalga) ve $V_{DC} \approx 0{,}636\,(V_m - 1{,}4)$ (köprü) biçimindedir; $V_m$ büyükken iki yazım arasındaki fark küçüktür.

## 7. Kırpıcılar (Clipper) ve Seri Kırpıcı

Yarım dalga doğrultucuda diyot girişe seri, çıkış ise $R$ üzerinden alınıyordu. Bu devre giriş işaretinin belirli bir kısmını kestiği (kırptığı) için kırpıcı (*clipper*) olarak da adlandırılır. Derste kırpıcılar, devreye gerilim kaynakları eklenerek ve diyotların yeri değiştirilerek incelendi.

> **Hocanın vurgusu:** Bu konu elektronik devrelerin yorumlanması açısından önemlidir; dikkatle dinlenmesi özellikle tavsiye edildi.

Girişe yalnız sinüs değil, kare dalga ya da üçgen dalga da uygulanabilir; bunların hepsi AC işaretlerdir. Seri kırpıcıda (diyot girişe seri, direnç çıkışa paralel) ideal diyotla:

- Pozitif kısımda A noktası (diyot anodu) toprağa (B) göre yüksektir, diyot iletir ve kısa devre olur. Giriş $R$ üzerinde oluşur: $v_o = v_i$.
- Negatif kısımda diyot açık devredir, akım akmaz: $v_o = 0$.

Hangi dalga şekli verilirse verilsin, $T/2$'ye kadar girişin aynısı, $T/2$'den $T$'ye kadar 0 V oluşur. Bu yapıda işaretin negatif yarım periyodu kırpılmış olur.

## 8. Seri Kaynaklı Kırpıcı Örneği

### 8.1 Devre

Girişi tepe değeri 20 V olan bir sinüs; önceki seri kırpıcıdan tek farkı diyota seri bağlı $V = 5$ V'luk bir kaynaktır (ekrandan, 00:40:00). Kaynağın eksi ucu girişe, artı ucu diyotun anoduna bakar. Diyotun katodu çıkış düğümüne, oradan $R$ üzerinden toprağa bağlıdır. Böylece diyotun anodundaki gerilim $v_A = v_i + 5$ V olur.

### 8.2 Adım adım çözüm

Çıkış, girişe değer verilerek çizilir:

| $v_i$ | Diyot | $v_o$ |
|---|---|---|
| 0 V | iletimde (anot 5 V) | 5 V |
| 1 V | iletimde | 6 V |
| 5 V | iletimde | 10 V |
| 20 V (tepe) | iletimde | 25 V |
| $-1$ V | iletimde | 4 V |
| $-5$ V | sınır: anot 0 V | 0 V |
| $-5$ V ile $-20$ V arası | kesimde | 0 V |

- $v_i = 0$ iken bile 5 V'luk kaynak yüzünden A noktası B'ye göre yüksektir; diyot iletir ve çıkışta 5 V görülür.
- Pozitif yarım periyotta diyot her zaman iletimdedir; tepe değerde $v_o = v_i + 5 = 20 + 5 = 25$ V'tur (ekrandan, 00:40:00).
- Negatif yarım periyotta giriş $-1$, $-2$, $-4$ V iken diyot hâlâ iletir. Giriş $-5$ V'a geldiğinde kaynak gerilimini tam karşılar; anot gerilimi sıfır olur, diyot iletimden çıkar ve açık devre gibi davranır.
- $-5$ V'un altındaki girişlerde ($-6$ V'tan $-20$ V'a kadar) çıkış 0 V'tur. Giriş $-5$ V'un üzerine çıktığında ($-4$, $-3$ V) diyot yeniden iletime geçer; giriş sıfıra geldiğinde çıkış tekrar 5 V olur.

Sonuç: diyota seri bağlanan kaynak, artı yönü diyota bakacak şekildeyse giriş işaretini 5 V yukarı ötelenmiş (offsetlenmiş) gibi çıkışa verir. Girişin $-5$ V olduğu anlarda çıkış sıfıra değer, $-5$ V'un altında kalan kısım sıfıra kırpılır (ekrandan, 00:45:00). Bu sonuç python ile doğrulandı: çıkışın en büyük değeri 25 V, en küçük değeri 0 V'tur.

Hoca bu tür sorularda girişe değerler verilerek geçiş noktalarının yaklaşık olarak bulunacağını ve çözümün bu yolla ilerletileceğini söyledi.

## 9. Paralel Kırpıcı

### 9.1 Devre ve çalışma

Bu kez önceki yapının tersi kurulur: $R$ girişe seri, diyot çıkışa paraleldir (diyotun anodu çıkış düğümünde, katodu toprakta). Çıkış diyotun uçlarından alındığı için $v_D = v_o$'dur (ekrandan, 00:50:00).

- Pozitif yarım periyot: A noktası (giriş) B'ye göre yüksektir. Diyotun üst ucu (D noktası) toprağa göre yüksek olduğu için diyot iletir. İletimdeki diyot düz teldir; iki ucu arasında gerilim farkı yoktur ($V_{DC} = V_D - V_C = 0$, ekrandan, 00:55:00). Çıkış 0 V olur.
- Negatif yarım periyot: Diyotun üst ucu toprağa göre düşüktür, diyot açık devredir. Devreden akım akmaz; direncin iki ucundaki gerilim eşit olmak zorundadır, yani $V_A = V_D$. Giriş aynen çıkışta görülür.

Sonuç: Yalnız diyotun yeri değiştirilip paralel alınarak, negatif yarım periyodu geçiren bir yarım dalga doğrultucu elde edildi. Slayttaki örneklerde kare dalga ve üçgen dalga girişlerinde de çıkış, pozitif kısımda 0 V, negatif kısımda girişin aynısıdır (ekrandan, 00:55:00). Slayttaki ifadeye göre paralel kırpıcı, diyotu doğru kutuplayan gerilimi kırpar; diyota seri bir DC kaynak eklenerek kırpma seviyesi değiştirilebilir.

### 9.2 Soru-cevap

**Soru:** Bu kısmı özetleyebilir misiniz?

**Cevap:** Pozitif yarım periyotta $v_i$ pozitiftir ve ideal diyot iletir; devre diyot üzerinden tamamlanır. Diyotun üst ucu D, alt ucu C olsun. Kısa devre olduğu için $V_D = V_C$, yani $V_{DC} = 0$ V'tur; düz bir telin iki ucu arasında gerilim farkı yoktur, ikisi aslında aynı noktadır. Bu yüzden çıkış 0 V'tur. Negatif yarım periyotta D noktasındaki gerilim de düşüktür, diyot iletmez ve açık devredir; akım akmadığı için A noktasındaki gerilim doğrudan çıkışta görülür.

## 10. Değer Vererek Çıkış Çizme: Çözülen Örnekler

Bu bölümde slayttaki çeşitli kırpıcı devrelerinden bazıları Microsoft Whiteboard üzerinde çizilerek çözüldü. Hepsinde yöntem aynıdır: önce giriş işareti çizilir, sonra girişe sırayla değerler verilir ve her değerde diyotların durumu belirlenir.

### 10.1 Çift diyotlu paralel kırpıcı

Devre (ekrandan, 01:10:00):

- Giriş $v_i$ seri bir direnç üzerinden çıkış düğümüne (N1) bağlıdır; çıkış $v_o$ bu düğüm ile toprak arasından alınır.
- Birinci kol: D1'in anodu çıkış düğümünde, katodu $V_1 = 3$ V'luk kaynağın artı ucuna bağlı; kaynağın eksi ucu toprakta.
- İkinci kol: D2'nin katodu çıkış düğümünde, anodu (B noktası) $V_2 = 4$ V'luk kaynağın eksi ucuna bağlı; kaynağın artı ucu toprakta. Yani B noktası $-4$ V'tadır.
- Giriş $+10$ V ile $-10$ V arasında değişen bir sinüstür.

Adım adım:

- $v_i = 0$: D1'in anodu 0 V, katodu 3 V'tadır; iletmez. D2'nin anodu $-4$ V, katodu 0 V'tadır; iletmez. Akım akmadığından $v_o = v_i = 0$ V.
- $v_i = 3$ V: D1 hâlâ iletimde değildir (iki ucu da 3 V). D2 de iletmez. $v_o = 3$ V.
- $v_i = 3{,}1$ V: D1 iletime geçer ve kısa devre olur. Çıkış düğümü 3 V'luk kaynağa bağlanmış olur: $V_{N1} = 3\ \text{V} = v_o$. Giriş 4, 5, 10 V olsa da çıkış 3 V'ta kalır. Giriş yeniden 3 V'un altına inince D1 iletimden çıkar.
- $v_i = -2$ V: D2 iletmez, çünkü B noktası $-4$ V ile daha düşüktür. $v_o = -2$ V.
- $v_i = -4{,}01$ V: Çıkış düğümü B'den biraz düşük olur; fark 0,01 V bile olsa ideal diyot iletime geçer. Çıkış $-4$ V'ta sabitlenir ve giriş $-5$, $-6$, $-10$ V olsa da $v_o = -4$ V kalır.

Sonuç: $-4\ \text{V} < v_i < 3\ \text{V}$ aralığında $v_o = v_i$; $v_i \ge 3$ V'ta $v_o = 3$ V; $v_i \le -4$ V'ta $v_o = -4$ V. Hoca sonucu slayttaki çözümle karşılaştırdı; slaytta değerler $V_1$ ve $V_2$ olarak genel bırakılmıştır. Python ile $\pm 10$ V'luk sinüs için çıkışın $-4$ V ile 3 V arasında kaldığı doğrulandı.

> **Hocanın vurgusu:** Önemli olan, giriş adım adım değişirken çıkışın ne zaman değiştiğini, diyotun ne zaman kısa devre olduğunu ve çıkışın nasıl oluştuğunu kafada kurabilmektir.

### 10.2 Yorum yazma örneği: tek diyotlu paralel kırpıcı

Hoca, devrenin çıkışını yalnız çizmenin değil, çıkışın nasıl oluştuğunu açıklamanın da beklendiğini söyledi ve bir örnekle gösterdi (ekrandan, 01:15:00):

- Giriş seri bir direnç üzerinden çıkışa bağlıdır.
- Diyot çıkışa paraleldir: katodu çıkış düğümünde, anodu 3 V'luk kaynağın artı ucuna bağlıdır; kaynağın eksi ucu toprakta.
- Giriş tepe değeri 10 V olan bir sinüstür.

Çözüm:

- $v_i = 0$: Diyotun anodu (3 V) katodundan yüksektir; diyot iletir ve kısa devre olur. Çıkışta 3 V görülür.
- Giriş 3 V'un altında olduğu sürece (2 V, 0 V, $-1$ V, $-5$ V, $-10$ V) diyot iletimdedir ve $v_o = 3$ V'tur.
- Giriş 3 V'a ulaşınca diyot iletimden kesilir ve açık devre olur. $v_i > 3$ V için $v_o = v_i$ olur.

Sonuç: çıkış, girişin 3 V'un üzerindeki kısmını aynen izler, diğer bütün anlarda 3 V'tadır. Python ile çıkışın 3 V ile 10 V arasında kaldığı doğrulandı.

### 10.3 Seri kaynaklı kırpıcı: $-3$ V

Slayttaki dokuzuncu devre çizildi (ekrandan, 01:20:00):

- Girişin artı ucundan sonra seri bir 3 V'luk kaynak gelir; kaynağın artı ucu girişe, eksi ucu diyota bakar. Kaynak ters bağlı olduğundan diyot tarafındaki A noktasında $-3$ V olarak görülür.
- Diyotun katodu A noktasında, anodu (B) çıkış tarafındadır.
- Çıkış, B ile toprak arasındaki $R$ üzerinden alınır. Giriş $\pm 10$ V'luk sinüstür.

Böylece A noktasının gerilimi $v_A = v_i - 3$ V'tur.

Adım adım (ekrandan, 01:25:00):

| $v_i$ | $v_A = v_i - 3$ | Diyot | $v_o$ |
|---|---|---|---|
| 0 V | $-3$ V | iletimde | $-3$ V |
| 1 V | $-2$ V | iletimde | $-2$ V |
| 2 V | $-1$ V | iletimde | $-1$ V |
| 3 V | 0 V | sınır | 0 V |
| 3 V'tan büyük | pozitif | kesimde | 0 V |
| $-1$ V | $-4$ V | iletimde | $-4$ V |
| $-2$ V | $-5$ V | iletimde | $-5$ V |
| $-10$ V (tepe) | $-13$ V | iletimde | $-13$ V |

- $v_i = 0$ iken A noktası $-3$ V'tadır; B'ye göre düşük olduğu için diyot iletir ve kısa devre olur. $-3$ V aynen çıkışta görülür.
- Giriş 3 V'a ulaşana kadar çıkış girişi 3 V aşağıdan izler. Giriş 3 V'u geçince girişteki 3 V kaynağın gerilimini "yer", diyot açık devre olur, dirençten akım akmaz ve çıkış 0 V'tur.
- Giriş yeniden 3 V'un altına inince diyot tekrar iletir; sıfırda çıkış $-3$ V'tur. Negatif yarım periyotta çıkış her zaman girişin 3 V altındadır; giriş $-10$ V'ta iken çıkış $-13$ V olur.

Sonuç: Dalga şekli kaynak gerilimi kadar (3 V) aşağı kaydırılır ve girişin 3 V'tan büyük olduğu kesimler 0 V'a kırpılır. Çıkış, orijinal işaretin sıfır geçişlerinde $-V$ değerinden geçer; slayttaki çözümde en düşük değer $-V_m - V$ olarak verilmiştir. Python ile çıkışın $-13$ V ile 0 V arasında kaldığı doğrulandı.

> **Hocanın vurgusu:** Giriş işaretine göre çıkış işaretinin çizilmesi beklenir; slayttaki kırpıcı devrelerinden herhangi biri sorulabilir. Bu konu iyi çalışılmalıdır.

### 10.4 Soru-cevap: kaynak neden $-3$ V alındı?

**Soru:** Bu devrede gerilim kaynağına $-3$ V dememizin sebebi diyotla ters yönde olması mı?

**Cevap:** Kaynağın artı ucu bir tarafta, eksi ucu diğer taraftadır. Kaynak, artı ucu A noktasına bakacak şekilde bağlansaydı A noktası 3 V olurdu. Burada kaynak ters bağlanmıştır; A noktasındaki gerilim B tarafına göre düşüktür. Bu yüzden A noktasında kaynak $-3$ V olarak görülür. Pil ters bağlanmış, negatif ucu bu tarafa bakıyormuş gibi düşünülebilir. Bu nedenle $v_i = 0$ iken bile eksi gerilim diyotu iletimde tutar ve A noktasındaki $-3$ V aynen çıkışta görülür. Giriş 1 V iken çıkış $-2$ V, 2 V iken $-1$ V olur; çıkışa ancak giriş 3 V olunca 0 V gelinir. Giriş ile çıkış arasında hep 3 V'luk bir fark vardır.

### 10.5 Soru-cevap: diyot ters çevrilirse

**Soru:** Aynı devrede yalnız diyotu ters çevirsek nasıl bir çizim elde ederiz?

**Cevap:** Kaynak yine $-3$ V kabul edilir; bu kez diyotun anodu A noktasında, katodu çıkış tarafındadır (ekrandan, 01:35:00). Diyotun girişe bakan ucundaki gerilim $V_{DA} = v_i - 3$ V'tur.

- $v_i = 0$: $V_{DA} = -3$ V'tur, diyot iletmez ve çıkış 0 V'tur.
- $v_i = 1$ V: $V_{DA} = -2$ V'tur, diyot iletmez, çıkış 0 V'tur.
- $v_i = 2$ V: $V_{DA} = -1$ V'tur, çıkış yine 0 V'tur.
- $v_i = 3$ V: hâlâ akım akmaz.
- $v_i = 3{,}01$ V: $V_{DA} = 3{,}01 - 3 = 0{,}01$ V olur; ideal diyot iletime geçer ve kısa devre olur. $V_{DA}$ aynen çıkışta görülür ve giriş arttıkça çıkış artar.
- $v_i = 10$ V (tepe): $v_o = 10 - 3 = 7$ V.
- Giriş yeniden 3 V'un altına inince (2 V, 1 V, 0 V, negatif değerler) diyot açık kalır ve çıkış 0 V olur.

Sonuç: Yalnız diyotun yönü değiştirilerek, önceki çözümde kırpılan parça alınmış olur. Çıkışın tepe değeri $V_m - V = 10 - 3 = 7$ V'tur; hoca sonucu slayttaki çözümle karşılaştırdı. Python ile çıkışın 0 V ile 7 V arasında kaldığı doğrulandı.

### 10.6 Genel yöntem

Hoca dersin sonunda yöntemi şöyle özetledi: önce giriş dalga şekli çizilir. Sonra girişin değerlerine göre çıkış nokta nokta çizilir; örneğin tepe 10 V, ara noktalar 7 V, 5 V, $-2$ V, $-10$ V gibi. Kritik dönüm noktaları bulunur: diyotun iletime geçip geçmeyeceği, geçtiğinde çıkışın ne olacağı ve giriş oradan arttığında ne olacağı. Bu noktalar birleştirilince çıkış dalga şekli oluşur. Diyotlu devreleri iyi analiz edebilmek için bu adımların alışkanlık haline gelmesi gerekir.

### 10.7 Soru-cevap: gerçek diyot

**Soru:** Slayttaki sekizinci devrede diyot hiçbir zaman ideal olmayacağı için yine de bir akım olmaz mı? Çıkış tam sıfırlanmıyor, değil mi?

**Cevap:** Bu çizimlerde diyot ideal kabul edilir. Gerçek bir senaryoda da sızıntı akımı dikkate alınmaz. Ama diyot iletime geçtiğinde, ideal olmayan durumda üzerindeki 0,7 V'luk gerilim (bu devrede diyotun bağlanma yönüne göre $-0{,}7$ V) hesaba katılmalıdır. İdeal diyot iletimde düz bir tel gibi düşünülürken, silisyum diyotta iletimde 0,7 V'luk bir düşüm vardır.

## Örnek Sorular

### Soru 1: Seri kaynaklı kırpıcı (ekrandan, 00:40:00)

Tepe değeri 20 V olan sinüs $v_i$, eksi ucu girişe, artı ucu diyot anoduna bakan $V = 5$ V'luk seri kaynak, seri ideal diyot ve çıkışa paralel $R$'den oluşan devrede $v_o$'yu çizin.

> **Çözüm (derste verildi):** $v_i > -5$ V için diyot iletir ve $v_o = v_i + 5$ V'tur; tepe değer $20 + 5 = 25$ V'tur. $v_i \le -5$ V için diyot kesimdedir ve $v_o = 0$ V'tur. Çıkış, 5 V yukarı ötelenmiş ve $-5$ V'un altı kırpılmış sinüstür.

### Soru 2: Çift diyotlu paralel kırpıcı (ekrandan, 01:10:00)

Seri direnç, çıkışa paralel iki kol: D1 (anot çıkışta) ile seri $V_1 = 3$ V (artı ucu diyota bakar), D2 (katot çıkışta) ile seri $V_2 = 4$ V (eksi ucu diyota bakar). Giriş $\pm 10$ V'luk sinüs. $v_o$'yu çizin.

> **Çözüm (derste verildi):** $-4 < v_i < 3$ V aralığında iki diyot da kesimdedir ve $v_o = v_i$'dir. $v_i \ge 3$ V'ta D1 iletir, $v_o = 3$ V. $v_i \le -4$ V'ta D2 iletir, $v_o = -4$ V. Çıkış 3 V'ta üstten, $-4$ V'ta alttan kırpılmış sinüstür.

### Soru 3: Tek diyotlu paralel kırpıcı (ekrandan, 01:15:00)

Seri direnç, çıkışa paralel diyot (katot çıkışta, anot 3 V'luk kaynağın artı ucunda). Giriş tepe değeri 10 V olan sinüs. $v_o$'yu çizin.

> **Çözüm (derste verildi):** $v_i < 3$ V iken diyot iletir ve $v_o = 3$ V'tur. $v_i > 3$ V iken diyot açık devredir ve $v_o = v_i$'dir; tepe değer 10 V'tur.

### Soru 4: $-3$ V seri kaynaklı kırpıcı (ekrandan, 01:20:00)

Girişe seri, artı ucu girişe bakan 3 V'luk kaynak; katodu kaynağa, anodu çıkışa bakan ideal diyot; çıkışa paralel $R$. Giriş $\pm 10$ V'luk sinüs. $v_o$'yu çizin. Ardından diyot ters çevrildiğinde çıkışı çizin (derste sözlü, 01:31:29).

> **Çözüm (derste verildi):** İlk devrede $v_i < 3$ V için $v_o = v_i - 3$ V (en düşük $-13$ V), $v_i > 3$ V için $v_o = 0$ V. Diyot ters çevrildiğinde $v_i > 3$ V için $v_o = v_i - 3$ V (en yüksek 7 V), $v_i < 3$ V için $v_o = 0$ V.

### Soru 5: Doğrultucu DC değerleri (ekrandan, 00:35:00)

Tepe değeri $V_m$ olan sinüs için yarım dalga, köprü ve orta uçlu transformatörlü doğrultucuların ideal ve gerçekçi (Si diyot) DC çıkış değerleri nedir?

> **Çözüm (derste verildi):** Yarım dalga: $0{,}318\,V_m$ ve $0{,}318\,V_m - 0{,}7$. Köprü: $0{,}636\,V_m$ ve $0{,}636\,V_m - 2(0{,}7)$. Transformatörlü: $0{,}636\,V_m$ ve $0{,}636\,V_m - 0{,}7$.

## Dersin Toparlaması

Bu derste diyotun tek yönde iletme özelliğinin iki temel uygulaması işlendi. Doğrultucularda amaç AC işaretin ortalamasını yükselterek DC'ye yaklaşmaktır: yarım dalga doğrultucu tek diyotla $0{,}318\,V_m$, köprü doğrultucu dört diyotla $0{,}636\,V_m$ ortalama verir; gerçek diyotlarda iletimdeki her diyot için 0,7 V düşülür. Kırpıcılarda ise diyot, seri ya da paralel bağlanışına ve eklenen DC kaynaklara göre giriş işaretinin belirli bir seviyenin üstünü ya da altını keser, bazen de işareti kaynak gerilimi kadar öteler.

Bütün kırpıcı sorularında yöntem aynıdır: giriş çizilir, girişe değerler verilir, her değerde diyotun iletimde mi kesimde mi olduğu belirlenir, kritik geçiş noktaları bulunur ve çıkış nokta nokta çizilir. Hoca bir sonraki derste kenetleyicilere (clamper) geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
