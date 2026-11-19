# Ders 16 Genişletilmiş Notu: Diyot, Zener ve BJT DC Öngerilim Soru Çözümleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Amacı ve Diyot Modellerinin Tekrarı
- 2. Seri Diyot Devreleri
- 3. Toprak Görünmeyen Devre: İki Kaynaklı Seri Devre
- 4. Paralel-Seri Diyot Devresi
- 5. Negatif Yarım Dalga Doğrultucu
- 6. İki Diyotlu Köprü ile Tam Dalga Doğrultma
- 7. Seri Kaynaklı Kırpıcı
- 8. Zener Diyotun Çalışması
- 9. Zener Regülatör: Değişken Yük
- 10. Zener Regülatör: Sabit Yük
- 11. BJT Sabit Öngerilim Devresi
- 12. Emitter Dirençli Öngerilim Devresi
- 13. Gerilim Bölücülü Öngerilim Devresi
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Amacı ve Diyot Modellerinin Tekrarı

Önceki derslerde diyotlar ve transistörler anlatılmış, diyot devreleriyle ilgili birkaç soru ve transistörün farklı bağlantılarına göre soru çözümü yapılmıştı. Bu derste yeni konu anlatılmadı; ders tamamen soru çözümüne ayrıldı. Sorular Boylestad & Nashelsky kitabının diyot uygulamaları ve BJT DC öngerilim bölümlerinden alınmış örneklerdir ve ekranda "ElkDev_Sorular1.pdf" adlı dosyadan gösterildi (ekrandan, 00:05:00). Sonraki konunun FET'ler olacağı söylendi.

Hoca önce diyot modellerini hatırlattı. İdeal diyotun karakteristiği, akım ekseni ve diyot gerilimi ekseni üzerinde çizildiğinde, negatif gerilimlerde akım sıfırdır; gerilim sıfırın biraz üzerine çıkınca diyot, devre ne kadar izin veriyorsa o kadar akım akıtır. Daha gerçekçi modelde akım, gerilim belli bir eşik değerini (threshold) aştıktan sonra akmaya başlar. En gerçekçi modelde buna bir de iç direnç eklenir ve eşik sonrası karakteristik dik değil, eğimli olur.

Eşik gerilimi malzemeye bağlıdır: silisyumda yaklaşık 0,7 V, germanyumda yaklaşık 0,3 V'tur. Soruda diyotun silisyum mu germanyum mu olduğu verilir ve buna göre eşik gerilimi kullanılır.

### 1.1 Diyot akımı devreden belirlenir

En basit devre bir DC kaynak, bir Si diyot ve bir dirençten oluşur. Kaynak 10 V ve pozitif olduğu için diyotun artı ucu daha yüksek potansiyeldedir, diyot iletime geçer ve üzerinde 0,7 V düşer. Geri kalan $10 - 0{,}7 = 9{,}3$ V direncin üzerine düşer (ekrandan, 00:10:00).

Akımı belirleyen direnç değeridir. Direnç 1 kΩ ise $I = 9{,}3\text{ V} / 1\text{ k}\Omega = 9{,}3$ mA olur. Direnç 10 kΩ olsaydı akım 0,93 mA olurdu. Hoca bunu şöyle özetledi: diyotun üzerinde düşen gerilim değişmez, ama akım dirençle birlikte değişir.

> Ders sonrası not: Altyazıda direnç 10 kΩ olunca akımın "10 mA" olacağı söyleniyor. $9{,}3\text{ V}/10\text{ k}\Omega = 0{,}93$ mA'dir; söylenen değer büyük olasılıkla bir sürç ya da Whisper hatasıdır.

Ekrandaki ilk sorunun (kitaptaki Şekil 2.3) yanında diyotun ölçülmüş karakteristiği de verilmişti (yaklaşık 0,5 V'ta akım başlıyor, 0,8 V civarında 10 mA'e çıkıyor). Hoca bu grafikle yapılan hesabı geçti (ekrandan, 00:10:00).

## 2. Seri Diyot Devreleri

### 2.1 8 V kaynak ve 2,2 kΩ direnç

Bir Si diyot ve bir direnç seri bağlanmış, $V_D$, $V_R$ ve $I_D$ isteniyor. Hoca devreyi A ve B uçları arasında düşünmeyi önerdi: A noktası kaynaktan diyot ve direnç üzerinden toprağa gider, kaynak da toprağa bağlıdır.

- $V_D = 0{,}7$ V.
- $V_R = 8 - 0{,}7 = 7{,}3$ V.
- $I_D = I_R = 7{,}3\text{ V} / 2{,}2\text{ k}\Omega \approx 3{,}32$ mA (ekrandan, 00:15:00).

**Soru:** (Hoca bir öğrenciye sordu) Diyotun üzerinden geçen akımı nasıl buluruz? **Cevap:** Ana kolda bütün akımlar eşittir, ama diyotun üzerinden ne kadar akım geçtiğini diyottan bilemeyiz. Diyot belli bir gerilimden sonra yalnız akıma izin verir; ne kadar akım akacağını devrenin geri kalanı belirler. Bu yüzden akım direnç üzerinden hesaplanır: $I = V/R$.

### 2.2 Örnek 2.9: Si ve Ge diyot seri

Devrede "+12 V" yazan bir nokta var, oradan Si ve Ge diyot üzerinden 5,6 kΩ'luk dirence ve toprağa gidiliyor; $V_o$ ve $I_D$ isteniyor (ekrandan, 00:15:00).

Hoca bu gösterimin anlamını vurguladı: A noktasına "12 V" yazmak, o noktanın toprağa göre 12 V olduğunu söyler. Devre, artı ucu A'ya, eksi ucu toprağa bağlı bir 12 V kaynakla aynıdır. Çıkış ucu yalnız o noktadan ölçüm almak için çizilmiştir.

- $V_o = E - V_{T_1} - V_{T_2} = 12 - 0{,}7 - 0{,}3 = 11$ V.
- Devre tek koldur, bütün akımlar eşittir: $I_D = I_R = V_o / R = 11\text{ V} / 5{,}6\text{ k}\Omega \cong 1{,}96$ mA.

## 3. Toprak Görünmeyen Devre: İki Kaynaklı Seri Devre

Örnek 2.11'de (Şekil 2.27) devre A noktasında $E_1 = 10$ V ile başlıyor, 4,7 kΩ'luk $R_1$, Si diyot ve 2,2 kΩ'luk $R_2$ üzerinden B noktasına, $E_2 = -5$ V'a gidiyor. $I$, $V_1$, $V_2$ ve $V_o$ isteniyor (ekrandan, 00:20:00).

**Soru:** Bu devre hiç toprağa gitmiyor mu? Bir uçta 10 V, diğer uçta $-5$ V bağlı diyorsunuz. **Cevap:** Gidiyor. A tarafındaki kaynağın eksi ucu toprağa bağlıdır. B tarafındaki kaynak ters bağlanmıştır, artı ucuyla toprağa bağlanır. Kitaptaki Şekil 2.28 bu yeniden çizimi gösterir.

Bu durumda A ile B arasındaki gerilim

$$V_A - V_B = 10 - (-5) = 15 \text{ V}$$

olur ve bütün kol bu 15 V'u paylaşır (ekrandan, 00:20:00).

KVL ile akım:

$$15 = 4{,}7\text{ k}\Omega \cdot I + 0{,}7 + 2{,}2\text{ k}\Omega \cdot I = 6{,}9\text{ k}\Omega \cdot I + 0{,}7$$

$$I = \frac{14{,}3}{6{,}9\text{ k}\Omega} \approx 2{,}07 \text{ mA}$$

Hoca kilo ile mili'nin birbirini götürdüğünü hatırlattı: payda kilo ($10^3$) yukarı çıkınca $10^{-3}$ olur, yani yalnız $14{,}3/6{,}9$ hesaplanıp sonuç mA olarak yazılır.

Hoca akımı 2 mA'e yuvarlayarak devam etti:

- $V_1 = 4{,}7\text{ k}\Omega \cdot 2\text{ mA} = 9{,}4$ V.
- $V_2 = 2{,}2\text{ k}\Omega \cdot 2\text{ mA} = 4{,}4$ V.
- Kontrol: $9{,}4 + 4{,}4 + 0{,}7 = 14{,}5$ V. Toplamın 15 V olması gerekir; eksik 0,5 V akımı 2 mA'e yuvarlamaktan gelir. Hoca, tam değerle çarpılsaydı 15 V'un tamamlanacağını söyledi.

Tam akımla ($I = 2{,}072$ mA) değerler $V_1 \approx 9{,}74$ V ve $V_2 \approx 4{,}56$ V'tur; $9{,}74 + 0{,}7 + 4{,}56 = 15$ V olur (python ile kontrol edildi). $V_o$ derste hesaplanmadı, çözümü Örnek Sorular bölümündedir.

## 4. Paralel-Seri Diyot Devresi

Örnek 2.15'te (Şekil 2.36) 20 V kaynak, seri Si diyot $D_1$, ardından A noktasında ikiye ayrılan iki kol var: biri Si diyot $D_2$, diğeri 3,3 kΩ'luk $R_1$. Kollar B noktasında birleşip 5,6 kΩ'luk $R_2$ üzerinden kaynağa döner. $I_1$, $I_2$ ve $I_{D_2}$ isteniyor (ekrandan, 00:25:00).

Hoca A ve B arasındaki yapıyı bir diyota paralel bir direnç gibi düşünmeyi önerdi. 20 V uygulandığında iki diyotun da anot tarafı daha yüksek potansiyelde olduğu için ikisi de iletimdedir.

- $R_1$, iletimdeki $D_2$'ye paraleldir; uçlarında 0,7 V vardır: $I_1 = 0{,}7\text{ V}/3{,}3\text{ k}\Omega = 0{,}212$ mA.
- Dış çevrede KVL: $20 = 0{,}7 + 0{,}7 + V_2$, buradan $V_2 = 18{,}6$ V.
- $I_2 = 18{,}6\text{ V} / 5{,}6\text{ k}\Omega = 3{,}32$ mA.
- A düğümüne 3,32 mA gelir, bunun 0,212 mA'i $R_1$'den gider, geri kalanı $D_2$'den: $I_{D_2} = I_2 - I_1 = 3{,}32 - 0{,}212 \approx 3{,}11$ mA (ekrandan, 00:25:00).

Hoca bu soruları bir devreyi çözerken nelerden yararlanılacağını görmek için çözdüğünü söyledi: iletim durumu, KVL çevreleri ve düğümde akımın paylaşılması.

## 5. Negatif Yarım Dalga Doğrultucu

Örnek 2.18'de (Şekil 2.48) tepe değeri 20 V olan sinüs girişi, ters yönde bağlı bir diyot üzerinden 2 kΩ'luk dirence uygulanıyor. (a) Çıkışı çizin ve DC seviyesini bulun, (b) ideal diyot yerine Si diyot kullanın, (c) $V_m = 200$ V için tekrarlayın (ekrandan, 00:30:00).

### 5.1 İdeal diyot

Diyotun girişe bakan ucu A, dirence bakan ucu B olsun. Diyotun katodu A tarafındadır. Pozitif yarım periyotta A, B'den yüksektir; diyot ters kutuplanır ve iletmez. Bu süre boyunca $v_o = 0$ olur. Negatif yarım periyotta A, B'den düşük olur, diyot iletir ve $v_o = v_i$ olur. Çıkış, negatif yönde doğrultulmuş bir yarım dalgadır.

$$V_{dc} = -0{,}318 V_m = -0{,}318 \cdot 20 = -6{,}36 \text{ V}$$

Eksi işaret, çıkış polaritesinin şekilde tanımlanan polaritenin tersi olduğunu gösterir (ekrandan, 00:30:00).

### 5.2 Si diyot

Si diyotta diyotun iletime geçmesi için A ucunun B'den 0,7 V daha düşük olması gerekir. Bu yüzden çıkışın tepe değeri $20 - 0{,}7 = 19{,}3$ V olur:

$$V_{dc} = -0{,}318 (20 - 0{,}7) \approx -6{,}14 \text{ V}$$

Çıkış dalga biçiminde de bu görülür: ideal durumda çıkış tam $T/2$ noktasından başlarken, Si diyotta girişin önce $-0{,}7$ V'u aşması gerekir; çıkış $T/2$ noktasından biraz sonra başlar ve periyot sonundan biraz önce biter.

### 5.3 Büyük giriş genliği

$V_m = 200$ V olunca ideal durumda $V_{dc} = -63{,}6$ V, Si diyotta $-0{,}318 \cdot 199{,}3 \approx -63{,}4$ V olur (hoca ikisini de "eksi 63" olarak söyledi). 20 V girişte iki model arasında 0,22 V fark vardı. Büyük gerilimli girişte diyotun ideal kabul edilmesinin ya da üzerinde 0,7 V düşmesinin çok önemi kalmaz; diyot gerilimi ihmal edilebilir.

## 6. İki Diyotlu Köprü ile Tam Dalga Doğrultma

Örnek 2.19'da (Şekil 2.63) köprü benzeri bir yapı var: köprünün üst iki kolunda iki diyot, alt iki kolunda 2 kΩ'luk iki direnç, köprünün ortasında yatay olarak çıkışın alındığı 2 kΩ'luk direnç bulunur. Giriş tepe değeri 10 V olan sinüstür. Çıkış dalga biçimi, DC seviyesi ve diyotların PIV değeri isteniyor (ekrandan, 00:35:00).

### 6.1 Pozitif yarım periyot

Pozitif yarım periyotta diyotlardan biri iletir (kısa devre), diğeri kesimdedir (açık devre). Devre yeniden çizilince (Şekil 2.65) çıkış direnci ile alt dirençlerden biri seri bağlı olarak girişe bağlanır; diğer alt direnç doğrudan girişe paralel kalır. Hoca dirençleri toplayıp 4 kΩ gibi göstermediklerini, çünkü çıkışın yalnız ortadaki direnç üzerinde tanımlandığını söyledi. İki eşit direnç girişi yarı yarıya paylaşır:

$$v_o = \tfrac{1}{2} v_i, \qquad V_{o,max} = \tfrac{1}{2}(10) = 5 \text{ V}$$

(ekrandan, 00:35:00)

### 6.2 Negatif yarım periyot

Negatif yarım periyotta diyotların rolü değişir. Devre yeniden çizildiğinde (hocanın tahtadaki çizimi, ekrandan, 00:40:00) çıkış direnci yine bir başka 2 kΩ ile seri olarak girişe bağlanır, ama bu kez ters yönde: yukarıda eksi, aşağıda artı. Giriş $-10$ V iken iki dirençte $-5$ V'luk paylar düşer. Çıkış uçlarının polaritesi ters bağlandığı için $v_o$ yine $+5$ V olur. Böylece iki yarım periyotta da çıkış pozitiftir; devre tam dalga doğrultucu gibi çalışır.

$$V_{dc} = 0{,}636 \cdot 5 = 3{,}18 \text{ V}$$

(ekrandan, 00:40:00)

### 6.3 Soru-cevaplar

**Soru:** Negatif yarım periyotta sağdaki diyot akım geçirmiyor, soldaki geçiriyor; bu yüzden mi tam dalga doğrultucu oluyor? **Cevap:** Evet. Soldaki diyot kısa devre olunca devre değişir. A ve B uçlarından ilerleyince önce çıkış direncinin eksi ucuna, sonra artı ucuna, sonra diğer 2 kΩ'a gelinir. Negatif yarım periyotta çıkışa bu şekilde ters yönden bağlanılır ve çıkış pozitif olur; bu yüzden devre tam dalga doğrultucu olarak adlandırılır.

**Soru:** Negatif işareti pozitife çevirdik ama genlik 10 V'tan 5 V'a düştü; bu yine tam dalga doğrultucu mu? **Cevap:** Evet, hiç sorun değil. Yalnız değer düşmüştür. Bunun nedeni çıkış direncine seri bağlı eşit bir direncin olmasıdır: 10 V uygulanınca birine 5 V, diğerine 5 V düşer. Dirençler eşit olmasaydı, örneğin biri 1 kΩ diğeri 2 kΩ olsaydı, 1 kΩ'luk dirence 10 V'un üçte biri (3,33 V), 2 kΩ'luk dirence üçte ikisi (6,67 V) düşerdi. Dirençler dengesiz olduğunda gerilim dirençlerle orantılı paylaşılır. Gerilimin artı ya da eksi olması fark etmez; önemli olan gerilimin mutlak değeridir.

Sorudaki PIV kısmı derste ele alınmadı; çözümü Örnek Sorular bölümündedir.

## 7. Seri Kaynaklı Kırpıcı

Bir sonraki soruda (kitaptaki Örnek 2.20) tepe değeri 20 V olan sinüs girişi, seri bağlı 5 V'luk bir DC kaynak, bir diyot ve çıkışın alındığı R direncinden oluşan devreye uygulanıyor. Kaynağın artı ucu diyotun anoduna bakıyor. Diyot ideal kabul ediliyor (ekrandan, 00:45:00).

Hoca bu tür sorularda her zaman pozitif ve negatif yarım periyodu ayrı düşünmeyi önerdi.

- **Pozitif yarım periyot.** Giriş 0 V iken bile diyot, seri 5 V kaynak yüzünden iletimdedir. B ucu (çıkış) $0 + 5 = 5$ V olur. Giriş arttıkça diyot iletimde kalır; giriş 20 V olunca çıkış $20 + 5 = 25$ V olur. Pozitif yarım periyotta çıkış, girişin üzerine 5 V eklenmiş halidir.
- **Negatif yarım periyot.** Giriş $-1$ V iken diyot uçları arasında $-1 + 5 = 4$ V vardır, diyot hâlâ iletimdedir. $-2$ V'ta 3 V, $-4{,}9$ V'ta hâlâ pozitif bir gerilim kalır. Giriş tam $-5$ V olunca kaynak etkisi ortadan kalkar. Giriş $-5$ V'un biraz altına ($-5{,}0001$ V gibi) inince diyot kesilir ve çıkış 0 olur.
- Giriş, negatif yarım periyodun sonunda tekrar $-5$ V'un üzerine çıkınca diyot yeniden iletir ve çıkış yükselmeye başlar.

Sonuç olarak çıkış $v_o = v_i + 5$ biçiminde yukarı kaydırılmış bir sinüs parçasıdır ve yalnız $v_i < -5$ V olduğu aralıkta sıfırdır. Hoca bunun da bir tür yarım dalga doğrultucuya benzediğini söyledi. Çıkış, $T/2$ noktasını biraz aşarak sıfıra iner; çünkü kesilme giriş sıfırdan değil, $-5$ V'a indiği anda başlar.

## 8. Zener Diyotun Çalışması

Aradan sonra iki zener sorusuna geçildi. Hoca önce zener diyotun çalışmasını tekrarladı.

Zener devreye ters yönde bağlanır; artı ucu yukarıdaymış gibi düşünülebilir. Zener gerilimi örneğin $V_Z = 10$ V olsun. Zenerin A ve B uçlarına uygulanan gerilim $V_{AB}$ olsun.

- $V_{AB} < V_Z$ ise zener çalışmaz (off). Uçları açık devre gibidir; devre zener hiç yokmuş gibi çözülür.
- $V_{AB}$, $V_Z$'yi aşmaya zorlanırsa zener iletir (on). Zener kısa devre olmaz; uçlarında $V_Z = 10$ V'u tutar ve üzerinden belli bir akım geçirmeye başlar.

## 9. Zener Regülatör: Değişken Yük

Örnek 2.27'de (Şekil 2.113) 50 V giriş, seri 1 kΩ'luk R, ona paralel $V_Z = 10$ V ve $I_{ZM} = 32$ mA olan zener ve ayarlanabilir yük direnci $R_L$ var. (a) $V_{R_L}$'nin 10 V'ta tutulduğu $R_L$ ve $I_L$ aralığını bulun, (b) diyotun en büyük güç değerini bulun (ekrandan, 00:50:00 ve 01:05:00).

### 9.1 Yük direnci ve A noktasının gerilimi

Zener çıkarılırsa R ile $R_L$ bir gerilim bölücü olur ve A noktasının gerilimi $R_L$'ye bağlıdır. $R_L$ ayarlanarak A noktası 10 V'un altına da indirilebilir, üstüne de çıkarılabilir. Hoca bunu örneklerle gösterdi: R ve $R_L$ ikisi de 1 kΩ olsa 50 V'un yarısı, 25'er V düşer. R = 1 kΩ iken $R_L$ 10 kΩ olsa toplam 11 birimin 10 birimi $R_L$'ye düşer; yaklaşık olarak R'ye 5 V, $R_L$'ye 45 V civarında düşer (ekrandan, 01:05:00).

> Ders sonrası not: Altyazıda bu örnekte R'ye "5 civarında", $R_L$'ye "45 civarında" düştüğü söyleniyor. Tam değerler $50/11 \approx 4{,}5$ V ve $500/11 \approx 45{,}5$ V'tur; yaklaşık söylenen değerler doğrudur.

### 9.2 En küçük yük direnci

Zenerin tam iletime geçtiği sınırda zener henüz akım çekmez ($I_Z = 0$), ama A noktası 10 V'tadır. Bu durumda:

- $V_R = V_i - V_Z = 50 - 10 = 40$ V.
- $I_R = 40\text{ V} / 1\text{ k}\Omega = 40$ mA. Bu, ana koldan geçebilecek akımdır.
- Zener akım çekmediği için $I_L = I_R = 40$ mA.
- $10\text{ V} = 40\text{ mA} \cdot R_L$, buradan $R_L = 250\ \Omega$ (ekrandan, 01:10:00).

Kitaptaki formül de aynı sonucu verir:

$$R_{L,min} = \frac{R V_Z}{V_i - V_Z} = \frac{(1\text{ k}\Omega)(10\text{ V})}{50 - 10} = 250\ \Omega$$

Zener hiç akım çekmediğinde yükten en büyük akım akar. En büyük akım, en küçük direnç demektir: $R_{L,min} = 250\ \Omega$, $I_{L,max} = 40$ mA.

### 9.3 En büyük yük direnci

Ana koldan gelen 40 mA zener ile yük arasında paylaşılır. Zener en çok $I_{ZM} = 32$ mA çekebilir. Bu durumda yüke

$$I_{L,min} = I_R - I_{ZM} = 40 - 32 = 8 \text{ mA}$$

kalır. Zener paralelindeki yüke her zaman aynı gerilimi, 10 V'u sağlamaya çalışır. Bu yüzden

$$R_{L,max} = \frac{V_Z}{I_{L,min}} = \frac{10\text{ V}}{8\text{ mA}} = 1{,}25 \text{ k}\Omega$$

Zenerden en büyük akım geçtiğinde yükten en küçük akım geçer; yük direnci en büyük değerine ulaşmıştır. Ekrandaki grafikte $V_L$, $R_L = 250\ \Omega$ ile $1{,}25$ kΩ arasında ve $I_L = 8$ mA ile 40 mA arasında 10 V'ta sabit kalır (ekrandan, 01:10:00).

> Hocanın vurgusu: Zenerde önemli olan, iletimdeyken paralelindeki yüke daima aynı gerilimi sağlamasıdır.

### 9.4 Diyotun güç değeri

Güç $P = V \cdot I$ ile hesaplanır. Zenerin üzerinde en çok 10 V düşerken üzerinden en çok 32 mA geçer:

$$P_{Z,max} = V_Z I_{ZM} = 10 \cdot 32\text{ mA} = 320 \text{ mW}$$

## 10. Zener Regülatör: Sabit Yük

Hoca birinci zener sorusunu atladığını fark edip ona döndü. Örnek 2.26'da (Şekil 2.109) 16 V giriş, seri 1 kΩ'luk R, $V_Z = 10$ V ve $P_{ZM} = 30$ mW olan zener ve 1,2 kΩ'luk yük var. (a) $V_L$, $V_R$, $I_Z$ ve $P_Z$'yi bulun, (b) $R_L = 3$ kΩ için tekrarlayın (ekrandan, 01:15:00).

Hoca önce zenerden geçebilecek en büyük akımı buldu: $P_{ZM} = V_Z I_{ZM}$ olduğundan $I_{ZM} = 30\text{ mW}/10\text{ V} = 3$ mA (ekrandan, 01:15:00).

### 10.1 $R_L = 1{,}2$ kΩ

Zener çıkarılınca R ve $R_L$ gerilim bölücüdür:

$$V_A = \frac{1{,}2\text{ k}\Omega}{1\text{ k}\Omega + 1{,}2\text{ k}\Omega} \cdot 16 \approx 8{,}73 \text{ V}$$

8,73 V, 10 V'tan küçük olduğu için zener kapalıdır (off), uçları açıktır.

- $V_L = 8{,}73$ V.
- $V_R = 16 - 8{,}73 = 7{,}27$ V (hoca önce 7,23 dedi, sonra 7,27 diye düzeltti).
- Zener açık devre olduğu için $I_Z = 0$ ve $P_Z = 0$.

> Ders sonrası not: Hoca bu noktada "o anki transistörün gücü de 0" dedi; kastedilen zener diyotun gücüdür.

### 10.2 $R_L = 3$ kΩ

Yük direnci artınca bölücüden A noktasına düşecek gerilim de artar:

$$V_A = \frac{3}{4} \cdot 16 = 12 \text{ V}$$

A noktasının 12 V olmak istemesi zeneri çalıştırır. Zener A noktasını 10 V'ta tutar; geri kalan 6 V seri direnç R üzerinde düşer.

Hoca burada olası bir itirazı cevapladı: "A noktası 12 V dedik ama zener 10 V diyor, bu çelişki değil mi?" Hayır. Zener olmasaydı A noktasında 12 V, seri dirençte 4 V olurdu. Zener olunca dirence giden kısmı en fazla 10 V ile sınırlar; yük üzerinde en fazla 10 V düşürtür ve geri kalan gerilim R üzerine düşer.

- $V_L = V_Z = 10$ V, $V_R = 16 - 10 = 6$ V.
- $I_L = 10\text{ V} / 3\text{ k}\Omega = 3{,}33$ mA.
- $I_R = 6\text{ V} / 1\text{ k}\Omega = 6$ mA.
- $I_Z = I_R - I_L = 6 - 3{,}33 = 2{,}67$ mA.
- $P_Z = V_Z I_Z = 10 \cdot 2{,}67\text{ mA} = 26{,}7$ mW (ekrandan, 01:00:00).

26,7 mW, verilen $P_{ZM} = 30$ mW değerinin altında olduğu için zener bozulmadan, istenen sınırlarda çalışır.

> Ders sonrası not: Altyazıda sınır değer "30 watt" olarak geçiyor; ekrandaki değer $P_{ZM} = 30$ mW'tır.

## 11. BJT Sabit Öngerilim Devresi

Transistör sorularına geçildi. Örnek 4.1'deki (Şekil 4.7) devrede $V_{CC} = 12$ V, $R_B = 240$ kΩ, $R_C = 2{,}2$ kΩ, $\beta = 50$ ve giriş ile çıkışta 10 µF'lık kuplaj kondansatörleri var. (a) $I_{B_Q}$ ve $I_{C_Q}$, (b) $V_{CE_Q}$, (c) $V_B$ ve $V_C$, (d) $V_{BC}$ isteniyor (ekrandan, 01:20:00).

**Soru:** (Hoca sordu) Bu ne tip bir transistör? **Cevap:** (Bir öğrenci) npn.

Q indisi çalışma noktasını (quiescent point) gösterir: çalışma noktasındaki taban akımı $I_B$ ve ana koldan geçen kolektör akımı $I_C$.

### 11.1 Kondansatörlerin rolü

Hoca kondansatörlerin işini tahtada bir işaret çizerek hatırlattı: 5 V DC seviye üzerinde salınan bir işaret, iki kısımdan oluşur; ortalaması olan 5 V'luk DC kısım ve onun üzerinde salınan AC kısım. Kondansatör DC'yi yok eder, yalnız AC bileşeni geçirir (ekrandan, 01:20:00). Bu yüzden DC analizde giriş tarafındaki kondansatör kolu yokmuş gibi düşünülür.

### 11.2 Çözüm

Taban çevresi: $V_{CC} = I_B R_B + V_{BE}$. Transistör silisyum ve iletimde olduğu için $V_{BE} = 0{,}7$ V.

$$I_B = \frac{V_{CC} - V_{BE}}{R_B} = \frac{12 - 0{,}7}{240\text{ k}\Omega} = 47{,}08\ \mu\text{A}$$

Hoca bu akımın oldukça küçük olduğuna dikkat çekti; mikro $10^{-6}$ demektir.

$$I_C = \beta I_B = 50 \cdot 47{,}08\ \mu\text{A} = 2{,}35 \text{ mA}$$

Kolektör akımı taban akımının 50 katıdır.

Kolektör çevresi: $V_{CC} = I_C R_C + V_{CE}$.

$$V_{CE} = 12 - (2{,}35\text{ mA})(2{,}2\text{ k}\Omega) = 6{,}83 \text{ V}$$

Noktasal gerilimler toprağa göre ölçülür. Emitter doğrudan toprağa bağlı olduğu için $V_E = 0$:

- $V_{BE} = V_B - V_E$ olduğundan $V_B = V_{BE} = 0{,}7$ V.
- $V_C = V_{CE} = 6{,}83$ V.
- $V_{BC} = V_B - V_C = 0{,}7 - 6{,}83 = -6{,}13$ V (ekrandan, 01:20:00).

Eksi işaret, taban-kolektör ekleminin ters kutuplandığını gösterir. Doğrusal yükseltme için istenen durum budur.

## 12. Emitter Dirençli Öngerilim Devresi

Örnek 4.4'te (Şekil 4.22) aynı yapıya emitter direnci eklenmiş: $V_{CC} = 20$ V, $R_B = 430$ kΩ, $R_C = 2$ kΩ, $R_E = 1$ kΩ (40 µF ile köprülenmiş), $\beta = 50$. $I_B$, $I_C$, $V_{CE}$, $V_C$, $V_E$, $V_B$ ve $V_{BC}$ isteniyor (ekrandan, 01:25:00). Hoca bu devrelerin çözümünün önceki derste anlatıldığını hatırlattı.

### 12.1 Taban akımı

Taban çevresinde KVL:

$$V_{CC} = I_B R_B + V_{BE} + I_E R_E$$

Hoca önce $I_E$ yerine $\beta I_B$ yazmaya başladı, sonra $\beta + 1$ katsayısını doğru elde etmek için düzeltti: $I_E = I_C + I_B$ ve $I_C = \beta I_B$ olduğundan

$$I_E = \beta I_B + I_B = (\beta + 1) I_B$$

Yerine konunca $I_B$ parantezine alınır:

$$V_{CC} - V_{BE} = I_B \left[ R_B + (\beta + 1) R_E \right]$$

$$I_B = \frac{20 - 0{,}7}{430\text{ k}\Omega + (51)(1\text{ k}\Omega)} = \frac{19{,}3\text{ V}}{481\text{ k}\Omega} = 40{,}1\ \mu\text{A}$$

(ekrandan, 01:30:00)

### 12.2 Kolektör akımı ve $V_{CE}$

$$I_C = \beta I_B = 50 \cdot 40{,}1\ \mu\text{A} = 2{,}01 \text{ mA}$$

Kolektör-emitter çevresinde $I_E \approx I_C$ alınır:

$$V_{CC} = I_C (2\text{ k}\Omega) + V_{CE} + I_C (1\text{ k}\Omega)$$

$$V_{CE} = V_{CC} - I_C (R_C + R_E) = 20 - (2{,}01\text{ mA})(3\text{ k}\Omega) = 13{,}97 \text{ V}$$

### 12.3 Noktasal gerilimler

- $V_C = V_{CC} - I_C R_C = 20 - (2{,}01)(2) = 15{,}98$ V.
- $V_E = I_E R_E \approx I_C R_E = 2{,}01$ V. Aynı sonuç $V_C - V_{CE} = 15{,}98 - 13{,}97 = 2{,}01$ V ile de bulunur.
- $V_B$: $V_{BE} = V_B - V_E$, ama bu kez $V_E$ sıfır değildir. $V_B = V_{BE} + V_E = 0{,}7 + 2{,}01 = 2{,}71$ V.
- $V_{BC} = V_B - V_C = 2{,}71 - 15{,}98 \approx -13{,}27$ V.

Hoca $V_{BC}$ için değerleri yerine koymakla yetindi ve sonucun ters kutuplama (reverse biased) gösterdiğini, yani istenen durum olduğunu söyledi. Sayısal değer python ile hesaplandı (ara adım eklendi).

## 13. Gerilim Bölücülü Öngerilim Devresi

Son soruda hoca önce devrenin adını sordu.

**Soru:** Buna nasıl beslemeli transistör diyorduk? **Cevap:** (Hoca) Gerilim bölücülü öngerilim. Tabanda bir gerilim bölücü yapısı var; bunu hemen görmek gerekir, çünkü bu yapıyla bol bol karşılaşılacak.

Devrede $V_{CC} = 22$ V, $R_1 = 39$ kΩ, $R_2 = 3{,}9$ kΩ, $R_C = 10$ kΩ, $R_E = 1{,}5$ kΩ ve $\beta = 140$ (ekrandan, 01:35:00). $I_C$ ve $V_{CE}$ isteniyor.

> Hocanın vurgusu: En önemli yaklaşım, tabanın sol tarafını daha basit hale getirmektir. Bölücü yerine bir $E_{Th}$ kaynağı ve ona seri bir $R_{Th}$ direnci konur, bu direnç doğrudan tabana gider. Dirençlerin $V_{CC}$ ve toprak bağlantıları koparılmış gibi düşünülür.

### 13.1 Thevenin eşdeğeri

$E_{Th}$, $R_2$ üzerinde düşen gerilimdir; gerilim bölücü gibi hesaplanır:

$$E_{Th} = \frac{R_2 V_{CC}}{R_1 + R_2} = \frac{(3{,}9\text{ k}\Omega)(22\text{ V})}{39\text{ k}\Omega + 3{,}9\text{ k}\Omega} = 2 \text{ V}$$

Hoca bunu oranlarla da anlattı: $R_2$ bir birim, $R_1$ on birimse toplam 11 birimdir ve 22 V'un 11'de biri, yani 2 V, $R_2$'ye düşer. Tabanı 2 V ile beslenen bir eşdeğer devre gibi düşünülebilir.

$R_{Th}$, iki direncin paralel eşdeğeridir:

$$\frac{1}{R_{Th}} = \frac{1}{R_1} + \frac{1}{R_2}, \qquad R_{Th} = \frac{(39)(3{,}9)}{39 + 3{,}9}\text{ k}\Omega = 3{,}55 \text{ k}\Omega$$

(ekrandan, 01:35:00)

### 13.2 Taban akımı, kolektör akımı ve $V_{CE}$

Eşdeğer taban çevresi: $E_{Th} = I_B R_{Th} + V_{BE} + I_E R_E$. Taban-emitter arası, sanki orada bir diyot varmış gibi 0,7 V alınır.

$$I_B = \frac{E_{Th} - V_{BE}}{R_{Th} + (\beta + 1) R_E} = \frac{2 - 0{,}7}{3{,}55\text{ k}\Omega + (141)(1{,}5\text{ k}\Omega)} = \frac{1{,}3\text{ V}}{215{,}05\text{ k}\Omega} = 6{,}05\ \mu\text{A}$$

$$I_C = \beta I_B = 140 \cdot 6{,}05\ \mu\text{A} = 0{,}85 \text{ mA}$$

Kolektör çevresi, $I_E \approx I_C$ ile:

$$22 = I_C (10\text{ k}\Omega) + V_{CE} + I_C (1{,}5\text{ k}\Omega)$$

$$V_{CE} = 22 - (0{,}85\text{ mA})(11{,}5\text{ k}\Omega) = 22 - 9{,}78 = 12{,}22 \text{ V}$$

(ekrandan, 01:35:00)

> Ders sonrası not: Hoca sonucu "$V_C$'yi 12 volt bulmuş" diye söyledi. Kurulan denklem $V_{CE}$ içindir ve bulunan değer $V_{CE} \approx 12{,}2$ V'tur. Kolektörün toprağa göre gerilimi $V_C = V_{CC} - I_C R_C \approx 22 - 8{,}5 = 13{,}5$ V olur.

### 13.3 Öğrenci sorusu ve önceki dersin slaytı

Ders sonunda bir öğrenci bu tür soruları anlamadığını söyledi; gerilim bölücüyü bulduktan sonra akımın nasıl hesaplandığını sordu. Hoca önceki dersin slaytlarını (ElDev_08) açtı. O derste sabit öngerilim, emitter dirençli öngerilim ve gerilim bölücülü öngerilim devrelerinin denklemleri teker teker kurulmuştu.

Slayttaki yaklaşık analizde (Approximate Analysis) $I_B \ll I_1$ ve $I_1 \cong I_2$ ise tabanın gerilimi doğrudan bölücüden bulunur: $V_B = R_2 V_{CC}/(R_1 + R_2)$. $\beta R_E > 10 R_2$ koşulunda $V_E = V_B - V_{BE}$, $I_E = V_E/R_E$ ve KVL'den $V_{CE} = V_{CC} - I_C(R_C + R_E)$ yazılır (ekrandan, 01:40:00). Hoca, slaytta $R_{Th}$'nin anlatılmadığını, bu derste soruda onu da anlatmış olduklarını söyledi. Özetle: $E_{Th}$ gerilim bölücüden bulunur (burada $3{,}9/(39 + 3{,}9) \cdot 22 = 2$ V), $R_{Th}$ iki direncin paralel halidir (3,55 kΩ), devre bu iki elemanla basitleştirilir ve $R_{Th}$'den geçen akım $I_B$'dir.

> Ek bilgi (derste anlatılmadı): Kesin analiz (bu derste çözülen, $R_{Th}$'li yöntem) her zaman geçerlidir. Yaklaşık analiz, taban akımı bölücü akımına göre çok küçük olduğunda kullanılır ve taban akımını hesaplamadan $V_B$'yi doğrudan verir. $\beta R_E > 10 R_2$ koşulu bu yaklaşımın geçerli olup olmadığını kontrol etmek için kullanılır.

## Örnek Sorular

### Soru 1: Seri diyot devresi

(ekrandan, 00:15:00)

8 V'luk kaynak, Si diyot ve 2,2 kΩ'luk direnç seri bağlıdır. $V_D$, $V_R$ ve $I_D$'yi bulun.

**Çözüm (derste verildi):** $V_D = 0{,}7$ V, $V_R = 8 - 0{,}7 = 7{,}3$ V, $I_D = I_R = 7{,}3/2{,}2\text{ k}\Omega \approx 3{,}32$ mA.

### Soru 2: Si ve Ge diyot seri (Örnek 2.9)

(ekrandan, 00:15:00)

+12 V'luk noktadan Si ve Ge diyot üzerinden 5,6 kΩ'luk dirence ve toprağa gidilen devrede $V_o$ ve $I_D$'yi bulun.

**Çözüm (derste verildi):** $V_o = 12 - 0{,}7 - 0{,}3 = 11$ V, $I_D = 11/5{,}6\text{ k}\Omega \cong 1{,}96$ mA.

### Soru 3: İki kaynaklı seri devre (Örnek 2.11)

(ekrandan, 00:20:00)

$E_1 = 10$ V, $R_1 = 4{,}7$ kΩ, Si diyot, $R_2 = 2{,}2$ kΩ ve $E_2 = -5$ V seri bağlıdır. $I$, $V_1$, $V_2$ ve $V_o$'yu bulun.

**Çözüm (derste verildi):** $V_A - V_B = 15$ V; $I = 14{,}3/6{,}9\text{ k}\Omega \approx 2{,}07$ mA. Hoca 2 mA ile $V_1 = 9{,}4$ V, $V_2 = 4{,}4$ V buldu.

> **Çözüm (derste verilmedi):** Tam değerlerle $V_1 = 4{,}7 \cdot 2{,}072 \approx 9{,}74$ V, $V_2 = 2{,}2 \cdot 2{,}072 \approx 4{,}56$ V. $V_o$, $R_2$'nin üst ucunun toprağa göre gerilimidir: $V_o = V_2 + E_2 = 4{,}56 - 5 \approx -0{,}44$ V. Python ile kontrol edildi; KVL $9{,}74 + 0{,}7 + 4{,}56 = 15$ V'u sağlar.

### Soru 4: Paralel-seri diyot devresi (Örnek 2.15)

(ekrandan, 00:25:00)

20 V kaynak, seri Si diyot $D_1$, birbirine paralel Si diyot $D_2$ ve 3,3 kΩ'luk $R_1$, dönüşte 5,6 kΩ'luk $R_2$. $I_1$, $I_2$ ve $I_{D_2}$'yi bulun.

**Çözüm (derste verildi):** $I_1 = 0{,}7/3{,}3\text{ k}\Omega = 0{,}212$ mA; $V_2 = 20 - 1{,}4 = 18{,}6$ V; $I_2 = 3{,}32$ mA; $I_{D_2} = 3{,}32 - 0{,}212 \approx 3{,}11$ mA.

### Soru 5: Negatif yarım dalga doğrultucu (Örnek 2.18)

(ekrandan, 00:30:00)

(a) Şekil 2.48'deki devrenin ($V_m = 20$ V, ters bağlı diyot, 2 kΩ) çıkışını çizin ve DC seviyesini bulun. (b) İdeal diyot yerine Si diyotla tekrarlayın. (c) $V_m = 200$ V için (a) ve (b)'yi tekrarlayıp karşılaştırın.

**Çözüm (derste verildi):** (a) Diyot negatif yarım periyotta iletir, $V_{dc} = -0{,}318 \cdot 20 = -6{,}36$ V. (b) $V_{dc} = -0{,}318 \cdot 19{,}3 \approx -6{,}14$ V. (c) $-63{,}6$ V ve yaklaşık $-63{,}4$ V; büyük girişte diyot gerilimi ihmal edilebilir.

### Soru 6: İki diyotlu köprü (Örnek 2.19)

(ekrandan, 00:35:00)

Şekil 2.63'teki köprü devresinin (10 V tepe değerli giriş, iki diyot, üç adet 2 kΩ) çıkış dalga biçimini, çıkış DC seviyesini ve her diyot için gereken PIV değerini bulun.

**Çözüm (derste verildi):** Her yarım periyotta $v_o = v_i/2$ ve çıkış pozitiftir; tepe değer 5 V, $V_{dc} = 0{,}636 \cdot 5 = 3{,}18$ V.

> **Çözüm (derste verilmedi):** PIV kısmı derste çözülmedi. Pozitif yarım periyotta iletimdeki diyotun bağlı olduğu köşe $v_i$ potansiyelindedir; kesimdeki diyotun diğer ucu iki eşit direnç arasındaki noktada, yani $v_i/2$ potansiyelindedir. Kesimdeki diyotun uçlarındaki ters gerilim en çok $10 - 5 = 5$ V olur, yani her diyot için PIV $= 5$ V. Düğüm gerilimleri python ile kontrol edildi.

### Soru 7: Seri kaynaklı kırpıcı (Örnek 2.20)

(ekrandan, 00:45:00)

20 V tepe değerli sinüs girişi, seri 5 V kaynak (artı ucu diyota bakıyor), ideal diyot ve R'den oluşan devrenin çıkış dalga biçimini bulun.

**Çözüm (derste verildi):** $v_i \ge -5$ V iken diyot iletir ve $v_o = v_i + 5$ olur; çıkış 5 V'tan başlar, tepe değeri 25 V'tur. $v_i < -5$ V iken diyot kesimdedir ve $v_o = 0$ olur.

### Soru 8: Zener regülatör, sabit yük (Örnek 2.26)

(ekrandan, 01:15:00)

(a) Şekil 2.109'daki zener devresi için (16 V, R = 1 kΩ, $V_Z = 10$ V, $P_{ZM} = 30$ mW, $R_L = 1{,}2$ kΩ) $V_L$, $V_R$, $I_Z$ ve $P_Z$'yi bulun. (b) $R_L = 3$ kΩ ile tekrarlayın.

**Çözüm (derste verildi):** (a) $V = 8{,}73$ V < 10 V, zener kapalı: $V_L = 8{,}73$ V, $V_R = 7{,}27$ V, $I_Z = 0$, $P_Z = 0$. (b) $V = 12$ V > 10 V, zener açık: $V_L = 10$ V, $V_R = 6$ V, $I_L = 3{,}33$ mA, $I_R = 6$ mA, $I_Z = 2{,}67$ mA, $P_Z = 26{,}7$ mW < 30 mW.

### Soru 9: Zener regülatör, değişken yük (Örnek 2.27)

(ekrandan, 01:05:00)

(a) Şekil 2.113'teki devrede (50 V, R = 1 kΩ, $V_Z = 10$ V, $I_{ZM} = 32$ mA) $V_{R_L}$'yi 10 V'ta tutacak $R_L$ ve $I_L$ aralığını bulun. (b) Diyotun en büyük güç değerini bulun.

**Çözüm (derste verildi):** $R_{L,min} = 250\ \Omega$, $I_R = 40$ mA, $I_{L,max} = 40$ mA, $I_{L,min} = 8$ mA, $R_{L,max} = 1{,}25$ kΩ. $P_{Z,max} = 10 \cdot 32\text{ mA} = 320$ mW.

### Soru 10: Sabit öngerilim (Örnek 4.1)

(ekrandan, 01:20:00)

Şekil 4.7'deki sabit öngerilim devresi için ($V_{CC} = 12$ V, $R_B = 240$ kΩ, $R_C = 2{,}2$ kΩ, $\beta = 50$) (a) $I_{B_Q}$ ve $I_{C_Q}$, (b) $V_{CE_Q}$, (c) $V_B$ ve $V_C$, (d) $V_{BC}$'yi bulun.

**Çözüm (derste verildi):** $I_B = 47{,}08\ \mu$A, $I_C = 2{,}35$ mA, $V_{CE} = 6{,}83$ V, $V_B = 0{,}7$ V, $V_C = 6{,}83$ V, $V_{BC} = -6{,}13$ V.

### Soru 11: Emitter dirençli öngerilim (Örnek 4.4)

(ekrandan, 01:25:00)

Şekil 4.22'deki devre için ($V_{CC} = 20$ V, $R_B = 430$ kΩ, $R_C = 2$ kΩ, $R_E = 1$ kΩ, $\beta = 50$) $I_B$, $I_C$, $V_{CE}$, $V_C$, $V_E$, $V_B$ ve $V_{BC}$'yi bulun.

**Çözüm (derste verildi):** $I_B = 40{,}1\ \mu$A, $I_C = 2{,}01$ mA, $V_{CE} = 13{,}97$ V, $V_C = 15{,}98$ V, $V_E = 2{,}01$ V, $V_B = 2{,}71$ V; $V_{BC}$ negatiftir (ters kutuplama).

> **Çözüm (derste verilmedi):** $V_{BC}$'nin sayısal değeri: $2{,}71 - 15{,}98 \approx -13{,}27$ V (python ile kontrol edildi).

### Soru 12: Gerilim bölücülü öngerilim

(ekrandan, 01:35:00)

$V_{CC} = 22$ V, $R_1 = 39$ kΩ, $R_2 = 3{,}9$ kΩ, $R_C = 10$ kΩ, $R_E = 1{,}5$ kΩ, $\beta = 140$ olan gerilim bölücülü devrede $I_C$ ve $V_{CE}$'yi bulun.

**Çözüm (derste verildi):** $R_{Th} = 3{,}55$ kΩ, $E_{Th} = 2$ V, $I_B = 6{,}05\ \mu$A, $I_C = 0{,}85$ mA, $V_{CE} = 22 - 9{,}78 = 12{,}22$ V.

## Dersin Toparlaması

Bu derste önceki haftalarda görülen konular soru çözümüyle pekiştirildi. Diyot devrelerinde temel yöntem, önce diyotun iletimde olup olmadığını bulmak, iletimdeki diyot yerine eşik gerilimi kadar bir kaynak koymak ve akımı devrenin geri kalanından hesaplamaktır. Toprak görünmeyen devrelerde uçların toprağa göre gerilimleri farkı alınır. Doğrultucu ve kırpıcı sorularında pozitif ve negatif yarım periyot ayrı ayrı düşünülür ve devre her biri için yeniden çizilir. Zener sorularında önce zener çıkarılarak yük gerilimi bulunur; bu gerilim $V_Z$'nin altındaysa zener kapalı, üstündeyse zener açıktır ve yükü $V_Z$'de tutar. Yük direncinin alt sınırı zenerin akım çekmediği, üst sınırı zenerin en büyük akımı çektiği durumdan bulunur.

BJT tarafında sabit öngerilim, emitter dirençli öngerilim ve gerilim bölücülü öngerilim devrelerinin DC çalışma noktası hesaplandı. Ortak adımlar şunlardır: taban çevresinden $I_B$, $I_C = \beta I_B$, kolektör çevresinden $V_{CE}$ ve sonra noktasal gerilimler. Emitter direnci varsa $(\beta + 1)R_E$ terimi tabana yansır; gerilim bölücü varsa önce Thevenin eşdeğeri bulunur. Bir sonraki konunun FET'ler olacağı söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
