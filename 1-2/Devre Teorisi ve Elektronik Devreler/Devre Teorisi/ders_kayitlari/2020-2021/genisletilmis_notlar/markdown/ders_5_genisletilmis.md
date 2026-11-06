# Ders 5 Genişletilmiş Notu: Kaynak Dönüşümü, İdeal Olmayan Kaynaklar, Thevenin ve Norton Teoremleri (Yöntem 1-4)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

<!-- BELİRSİZ: Slayt görüntüsü yok. Örnek numaraları (10, 11, 12, 13, 14, 18, 20, 21) altyazıda söylenmiyor, kısa nottan alındı. -->

## İçindekiler

- 1. Geçen Haftanın Tekrarı: Doğrusallık ve Süperpozisyon
- 2. Kaynak Dönüşümü
- 3. İdeal ve İdeal Olmayan Kaynaklar
- 4. Yük Direnci İç Dirence Eşitken Güç
- 5. Örnek 10: Gerilim Kaynağından Akım Kaynağına
- 6. Örnek 11: Akım Kaynağından Gerilim Kaynağına
- 7. Eşdeğerlik Ölçütünün Özeti
- 8. Örnek 12: Kaynak Dönüşümüyle $v_0$
- 9. Örnek 13: Kaynak Dönüşümüyle $i_0$
- 10. Norton ve Thevenin Teoremleri
- 11. Yöntem 1: Art Arda Kaynak Dönüşümü
- 12. Yöntem 2: Açık Devre Gerilimi ve Kısa Devre Akımı
- 13. Yöntem 3: Kaynakları Sıfırlayıp Eşdeğer Direnç Bulmak
- 14. Yöntem 4: Test Kaynağı
- 15. Örnek 18: Bağımlı Kaynaksız Devrede Thevenin ve Norton
- 16. Örnek 20: Bağımlı Kaynaklı Devre
- 17. Örnek 21: Bağımsız Kaynağı Olmayan Devre

## 1. Geçen Haftanın Tekrarı: Doğrusallık ve Süperpozisyon

Geçen hafta devre teoremlerine başlamıştık. İlk teorem doğrusallık (linearite) ve süperpozisyondu. Doğrusallığın pratikteki karşılığı şudur: Birden fazla kaynağın yer aldığı bir devrede, kaynakların bir elemana toplam etkisini doğrudan hesaplamak zorunda değiliz. Her seferinde tek bir kaynağı devrede bırakıp diğerlerini sıfırlarız, her kaynağın tekil etkisini ayrı ayrı buluruz ve bu etkileri yönlerini dikkate alarak toplarız. Sonuç, bütün kaynaklar devredeyken oluşan toplu etkiye eşittir.

Kaynağı sıfırlamanın pratikte ne demek olduğu da önemlidir:

- **Gerilim kaynağını sıfırlamak:** Kaynağın yerine kısa devre eleman koymak.
- **Akım kaynağını sıfırlamak:** Kaynağın yerine açık devre eleman koymak.

Süperpozisyon yaklaşımı hem DC hem AC devrelerde geçerlidir. Bu hafta kaynak dönüşümü, Norton ve Thevenin teoremleri ve maksimum güç konularına geçiyoruz.

## 2. Kaynak Dönüşümü

### 2.1 Daha Önce Gördüğümüz Dönüşümler

Kaynak dönüşümü, Norton ve Thevenin teoreminin altyapısını oluşturur. Mantığı aslında yabancı değil, benzerini daha önce iki yerde gördük. Dirençlerin üçgen ve yıldız bağlantılarında, devre topolojisine göre birini ötekine çevirerek daha basit çözümlere ulaşıyorduk. Eşdeğer direnç ya da eşdeğer iletkenlik hesabında da karmaşık bir yapının yerine tek bir eleman koyuyorduk.

Bu dönüşümlerde önemli olan eşdeğerliktir. Seri ve paralel dirençlerde eşdeğer direnci "bir terminalden bakarak" hesaplıyorduk. Bunun anlamı şudur: Bu iki terminali bir kaynağa bağladığımızda, terminaller arasında oluşan gerilim ve terminal kolundan akan akım, tek direnç koyduğumuz durumda da orijinal devredekiyle aynı olmalıdır.

### 2.2 Eşdeğerlik Ölçütü

Aynı şey kaynak dönüşümü için de geçerlidir. Dönüşümde kullandığımız elemanların dışında kalan elemanlar için akım ve gerilim değerleri değişmemelidir. Başka eleman yoksa, dönüşüm yaptığımız iki uçtan bakarız: Uçlar arasındaki gerilim farkı ve bu uçlar bir yük direncine bağlandığında akan akım iki yapıda da aynı olmalıdır.

Bakılan terminal AB olsun. İddiamız şudur: Bir gerilim kaynağı ve ona seri bir direnç yerine, bir akım kaynağı ve ona paralel bir direnç eşdeğer olarak konabilir, ikisi arasında belirli bir formülle dönüşüm yapılabilir. Bu iddia doğruysa iki şart sağlanmalıdır:

- AB terminalleri açıkken uçlar arasındaki gerilim iki yapıda da aynı olmalıdır.
- AB terminallerine bir yük direnci $R_L$ bağlanınca kollardan akan akım da iki yapıda aynı olmalıdır.

Bu ikisi eşitse dönüşüm eşdeğerdir diyebiliriz. Yük direncinin kısaltması İngilizce "load" kelimesinden gelir.

### 2.3 Açık Devre Koşulu: $V_s = I_s R$

Önce açık devre durumuna bakalım. Gerilim kaynaklı yapıda direnç üzerinden akım akmaz, dolayısıyla direnç üzerinde gerilim düşmez ve uçlarda $V_s$ görülür. Eşdeğerlik gereği akım kaynaklı yapının uçlarında da $V_s$ görmek isteriz, yani paralel direnç ve akım kaynağı üzerindeki gerilim $V_s$ olmalıdır. Terminaller açık olduğundan akım kaynağının akımı $I_s$ doğrudan direnç üzerinden geçer. Direncin gerilimi $V_s$ olabilmesi için:

$$V_s = I_s R$$

Bu, aradığımız dönüşüm bağıntısıdır. Dikkat edin, gerilim kaynağında da akım kaynağında da aynı direnç değerini kullandık. Yani gerilim kaynağına seri bir direnç, bu şart altında, akım kaynağına paralel aynı direnç olarak yazılabilir. Direncin eşit olması burada bir varsayımdı. Örnek 10 ve Örnek 11'de bunun zorunlu olduğu ayrıca çıkacak.

### 2.4 Yük Bağlıyken Denetim

Şimdi iki yapıya da bir $R_L$ bağlayalım. Gerilim kaynaklı yapıda akım doğrudan yazılır:

$$I_L = \frac{V_s}{R + R_L}$$

Akım kaynaklı yapıda ana kol akımı $I_s$, $R$ ve $R_L$ kolları arasında direnç değerleriyle ters orantılı paylaşılır. $R_L$ kolundan geçen akım, karşı taraftaki $R$ ile orantılıdır:

$$I_L = I_s \frac{R}{R + R_L}$$

Burada $I_s R$ çarpımı az önceki hesaptan $V_s$'ye eşittir. Dolayısıyla $I_L = \frac{V_s}{R + R_L}$ olur ve iki yapıda akım aynı çıkar. Böylece eşdeğerliği yük bağlıyken de göstermiş olduk.

**Soru:** $I_s \frac{R_L}{R + R_L}$ dediğimiz kısım $R$ üzerinden geçen akım değil mi?

**Cevap:** Evet, tahtada ok işaretiyle gösterilen akım budur. $R$'den geçen akım karşı koldaki direnç olan $R_L$ ile orantılıdır, bu yüzden böyle yazıldı. $R_L$'den geçen akım da aynı şekilde karşı koldaki $R$ ile orantılıdır.

> **Ek bilgi (derste anlatılmadı):** Buradaki eşdeğerlik yalnız terminallerin dışına karşıdır, yapının içinde harcanan güç iki modelde aynı değildir. Açık devrede gerilim kaynaklı modelde iç dirençten akım geçmez ve içeride güç harcanmaz. Akım kaynaklı modelde ise $I_s$ iç dirençten geçer ve içeride $I_s^2 R$ kadar güç harcanır. Yani iki model yüke aynı akımı ve gerilimi verir, ama kaynağın iç gücünü hesaplamak için kullanılamaz (python ile hesaplandı).

### 2.5 Dönüşümün Faydası

Bir gerilim kaynağı ve ona seri direnç ikilisi yerine bir akım kaynağı ve ona paralel direnç koyabilmek ne kazandırır? Hoca birkaç dirençli bir devre çizdi. Gerilim kaynağı ile seri direncini akım kaynağı ve paralel dirence çevirince, dönüşümden gelen direnç ve devrede zaten duran dirençler birbirine paralel bir yapıya dönüştü. Yani kaynak dönüşümünün temel katkısı, devreyi daha basit topolojilere indirgeyerek daha pratik çözmektir. Genelleştirilmiş halini Norton ve Thevenin teoreminde göreceğiz.

<!-- BELİRSİZ: 00:11:19'daki devre tahtaya çizildi, eleman değerleri altyazıda geçmiyor. -->

### 2.6 Bağımlı Kaynaklar

Buraya kadar bağımsız kaynaklardan konuştuk. Aynı dönüşüm bağımlı kaynaklar için de geçerlidir: Bağımlı bir gerilim kaynağı ve ona seri bir direnç yerine, bir akım kaynağı ve ona paralel bir direnç konabilir.

> **Hocanın vurgusu:** Bağımlı kaynakta kontrol değişkenine dikkat edin. Örneğin $V_s = a\, i_x$ ise $i_x$ nereye aitse, topoloji değişiminden sonra kaybolmamalıdır. $i_x$'i yanlışlıkla başka bir yere yazmayın.

## 3. İdeal ve İdeal Olmayan Kaynaklar

### 3.1 Modelin Kökeni

Yola bir kaynak ve ona seri bir direnç alarak çıkmıştık. Bu aslında pratikte karşılaşacağımız, ideal olmayan gerilim kaynağının kendisidir. Gerilim kaynaklarının bir iç direnci vardır. İdeal durumda, teorik olarak, gerilim kaynağından sonsuz akım çekebiliriz. Pratikte kaynağın iç direnci bunu engeller, yani iç direnç akımı sınırlar. İç direnç gerçekte var olduğu için devrelerin çalışmasını daha iyi modellemek adına bu yapılar kullanılır: Gerilim kaynağına seri direnç, akım kaynağına paralel direnç.

Aynı şey akım kaynağı için de geçerlidir. Modelimiz akım kaynağına paralel bir dirençse, ideal akım kaynağında "iç direnç yok" demek, bu paralel direncin sonsuz olması demektir. Bu kolda hiçbir kayıp olmaz. Modelimiz gerilim kaynağına seri bir dirençse, ideal gerilim kaynağında iç direncin olmaması, bu direncin sıfır olması demektir.

### 3.2 İdeal Olmayan Gerilim Kaynağına Yük Bağlamak

$R_s$ iç dirençli bir kaynağa $R_L$ yükü bağlayalım. Kaynak iki dirençle birlikte gerilim bölücü gibi çalışır:

$$I_L = \frac{V_L}{R_L} = \frac{V_s}{R_s + R_L}, \qquad V_L = V_s \frac{R_L}{R_s + R_L}$$

Şimdi $R_L$'nin iki uç değerine bakalım.

**$R_L = 0$ durumu:** Formülde sıfırla çarptığımız için $V_L = 0$ olur. Akım yalnızca $R_s$ ile belirlenir: $I_L = \frac{V_s}{R_s}$. Yük üzerinde harcanan güç, gerilim sıfır olduğu için sıfırdır.

> **Ders sonrası not:** Hoca bu noktada gücü "sıfır volt" olarak söyledi; güç birimi vattır, doğrusu $P_L = 0$ W.

**$R_L \to \infty$ durumu:** Yük açık devre gibi çalışır. Formüle $R_L$'ye bağlı bir fonksiyon olarak bakarsak, $R_L$ sonsuza giderken $\frac{R_L}{R_s + R_L}$ terimi 1'e yaklaşır ve $V_L = V_s$ olur. Pratik açıdan da aynı sonuç çıkar: Açık devrede akım akmaz, iç dirençte gerilim düşmez, uçlarda $V_s$ görülür. Aynı anda $I_L \to 0$ olur, dolayısıyla güç yine sıfırdır.

Bu ne demek? Yük direncini sıfırdan itibaren artırdığımızda, güç önce sıfırdır, sonda yine sıfırdır. Güç karesel olarak hesaplanan pozitif bir büyüklük olduğuna göre arada bir yerde yükselir, belirli bir değerde tepe yapar, sonra tekrar sıfıra iner. Demek ki ideal olmayan bir gerilim kaynağından maksimum güç çekebilmek için bazı koşulları sağlamak gerekir. Bu sonuç bizi maksimum güç (Max Power) teoremine götürecek.

### 3.3 İdeal Olmayan Akım Kaynağına Yük Bağlamak

Benzer bir durum akım kaynağında da vardır. İdeal akım kaynağında iç direnç yoktur. İdeal olmayan akım kaynağında ise akımın bir kısmı iç dirençten geçer, bu da uçlarda elde edilebilecek akımı sınırlar. Dışarı verebileceğimiz gücün bir kısmı iç dirençte harcanır.

> **Ders sonrası not:** Hoca burada paralel iç direncin "gerilim bölücü" gibi çalıştığını söyledi; doğrusu akım bölücüdür. Hoca da biraz sonra sohbetteki bir yorum üzerine, akım kaynağında akımın bölündüğünü, bunun sonucunda gerilimin sınırlandığını söyledi.

Yük bağlandığında $I_s$ iki parçaya bölünür:

$$I_L = I_s \frac{R_s}{R_s + R_L}, \qquad V_L = I_L R_L$$

Uç değerler yine aynı sonucu verir:

- **$R_L = 0$:** $V_L = 0$ olur. $I_L$'nin bir değeri vardır, ama güç sıfırdır.
- **$R_L \to \infty$:** $\frac{R_s}{R_s + R_L}$ terimi sıfıra yaklaşır, $I_L = 0$ olur ve güç yine sıfırdır.

Yani yine $R_L$ ekseninde sıfırdan başlayan, bir yerde tepe yapan, sonsuzda asimptotik olarak sıfıra yaklaşan tek tepeli (unimodal) bir grafik çıkar. Bu topolojide sonsuz akım çekme ya da sonsuz gerilim alma imkanı yoktur. Hoca, pratikte bu tür kaynakların böyle durumlarda yanarak bozulduğunu da ekledi. Akım kaynağı da bizi aynı maksimum güç noktasına götürür.

### 3.4 Neden Gerilim Kaynağında Seri, Akım Kaynağında Paralel?

**Soru:** Akım kaynağında $R_s$ neden paralel?

**Cevap:** İdeal gerilim kaynağını düşünelim. Kaynağın serisinde bir direnç, yani enerji harcayan bir eleman olması akla yatkındır. Akım kaynağında ise eşdeğerlik hesabı direnci seride değil paralelde bir değer olarak verir. Paralel direnç $I_s$ akımını böler, yani dışarı $I_s$'nin tamamı çıkmaz. Direnç seri konsaydı, $I_s$'nin tamamı yine dışarı çıkabilirdi ve kaybı modellemiş olmazdı.

<!-- BELİRSİZ: 00:23:05'te hoca "seride koymuş olsaydık sıfır çıkacaktı" diyor; neyin sıfır çıkacağı altyazıdan net değil. -->

**Soru:** Bunları birbirine çevirebiliyorduk. Akım kaynağında direnç sınırsız olunca bir geçiş oluyor, ama gerilim kaynağında böyle bir geçiş olmuyor. Bu nasıl oluyor?

**Cevap:** Gerilim kaynağında da iç direncin sıfır olması durumu vardır. İdeal gerilim kaynağında seri iç direnç sıfır, ideal akım kaynağında paralel iç direnç sonsuzdur. Birbirlerinin tersi olarak eşleşirler.

Sohbetteki iç direncin gücüyle ilgili bir yoruma da hoca şöyle cevap verdi: İç direnç modeli, kaynağın ürettiği bütün gücün dışarı verilemediğini gösterir. Gücün içeride kalan kısmı bağlanan yük direncinin değerine göre değişir. Az önceki tek tepeli grafik de bunu görmek açısından faydalıdır.

## 4. Yük Direnci İç Dirence Eşitken Güç

Maksimum güç konusuna az sonra dönmek üzere, hoca elle kısa bir hesap yaptı. İçeride asla atlayamayacağımız bir $R_s$ direnci var. Bu iki terminalli ideal olmayan kaynağa yük bağlıyoruz. Soru: Yük direncini iç dirence eşit seçersek ($R_L = R_s$) ne olur?

- İki direnç eşit olduğundan yük üzerinde düşen gerilim: $V_L = \frac{V_s}{2}$
- Akım: $I_L = \frac{V_s}{2R_s}$
- Güç: $P_L = V_L I_L = \frac{V_s^2}{4R_s}$

$R_L$, $R_s$'den biraz küçük ya da biraz büyük olursa elde edilecek güç bundan küçük olur. Aynı soruyu şöyle de sorabiliriz: $R_L$'yi nasıl seçmeliyiz ki yük üzerinde harcanan güç maksimum olsun?

Bunun çözümü maksimum güç konusuna kaldı, ama yöntemi şudur. Gücü $R_L$'ye bağlı bir fonksiyon olarak yazarız. Bu fonksiyonun tek tepeli olduğunu biliyoruz, çünkü uç limitlerde sıfıra ulaşıyor. Eğimin sıfır olduğu yer aradığımız noktadır. O halde gücün $R_L$'ye göre kısmi türevini alıp sıfıra eşitleriz:

$$\frac{\partial P_L}{\partial R_L} = 0$$

Bu denklemi sağlayan $R_L$, ideal olmayan kaynaktan en fazla gücü çektiren değerdir. Hocanın şimdilik söylediği sonuç: $R_L$ iç dirence eşit olduğu anda en fazla güç çekilir. Yük biraz azalır ya da artarsa tepeden sağa veya sola kayarız ve güç düşer. Akım kaynağı için de aynı analiz geçerlidir.

> **Ek bilgi (derste anlatılmadı):** Hocanın bıraktığı türev kısaca şöyle kurulur: $P_L = V_s^2 \frac{R_L}{(R_s + R_L)^2}$ için $\frac{\partial P_L}{\partial R_L} = V_s^2 \frac{R_s - R_L}{(R_s + R_L)^3}$ olur. Bu ifade $R_L = R_s$'de sıfırlanır, öncesinde pozitif, sonrasında negatiftir. Türev ifadesi ve $R_L = R_s$'deki tepe python ile hesaplandı. Dersin ispatı sonraki derse kaldı.

## 5. Örnek 10: Gerilim Kaynağından Akım Kaynağına

Şimdiye kadar dönüşümü kabaca, dirençlerin eşit olduğunu varsayarak yaptık. Şimdi tersten, varsayım yapmadan bakalım: Yük bağlıyken kollardan geçen akımlar eşit olmalı, yük kaldırılınca da terminaller arasındaki gerilim eşit olmalı. İki kaynak arasındaki direnç ilişkisi bu iki koşuldan çıkar.

**Verilen:** $V_s = 18$ V, $R_s = 3$ kΩ, $R_L = 6$ kΩ. Eşdeğer akım kaynağı ve paralel direnç ikilisi bulunacak.

**Verilen devrede yük varken:**

$$I_L = \frac{18\text{ V}}{9\text{ k}\Omega} = 2\text{ mA}, \qquad V_L = 2\text{ mA} \cdot 6\text{ k}\Omega = 12\text{ V}$$

Eşdeğer devrede $I_s$ ve $R$ bilinmiyor, ama aynı 6 kΩ yük bağlandığında aynı 2 mA ve 12 V elde edilmeli.

**Birinci denklem (yük bağlı):** Yük 12 V gördüğüne göre paralel $R$ de 12 V görür. $R$'ye giden akım $I_s - 2$ mA'dir:

$$(I_s - 2\text{ mA})\, R = 12\text{ V}$$

**İkinci denklem (yük kaldırılmış):** Yük direncini kaldırmak, yerine sonsuz değerli bir direnç koymak gibidir. Verilen devrede uçlarda 18 V görülür. Eşdeğer devrede de bütün akım $R$'den akar:

$$I_s R = 18\text{ V}$$

**Çözüm:** İkinci denklemi birincide yerine koyarsak:

$$18 - 2R = 12 \quad\Rightarrow\quad 6 = 2R \quad\Rightarrow\quad R = 3\text{ k}\Omega$$

Akım miliamper olduğundan direnç kilo-ohm çıkar. Ardından $I_s = \frac{18\text{ V}}{3\text{ k}\Omega} = 6$ mA bulunur.

Yani iki senaryodan iki denklem, iki bilinmeyen elde ettik. Başta varsayım olarak aldığımız "direnç eşitliği" böylece genel bir kural olarak ortaya çıktı. $I_s$ de yine iki değerin oranı, yani $\frac{V_s}{R}$ olarak geldi.

Hoca ardından ideal kaynak yorumunu tekrarladı. İdeal durumda kaynağın akımının tamamı yük direncine aktarılabilmelidir. Akım bölücü etkisi olmaması için iç direnç bulunmamalı, yani o kol açık devre olmalıdır, bu da paralel iç direncin sonsuz olması demektir. İdeal gerilim kaynağında ise seri iç direnç sıfırdır.

Slayt sonra farklı direnç değerleri için çekilen güçleri tablo halinde deneysel olarak gösteriyor. Az önce çıkardığımız grafiğin örneklerle karşılığıdır ve iç dirence eşit yük kullanıldığında en yüksek gücün çekildiğini gösterir.

> **Ders sonrası not:** Hoca bu tabloyu anlatırken "$R_L$'yi sabitledik, farklı $R_s$ değerlerine baktık" dedi. Maksimum güç koşulu ise $R_s$ sabit, $R_L$ değişken durumu içindir. $R_L$ sabitken $P_L$, $R_s$ arttıkça hep azalır ve en büyük değerini $R_s = 0$'da alır (python ile hesaplandı). Slayttaki tabloda büyük olasılıkla $R_s$ sabit, $R_L$ değişkendir.

<!-- BELİRSİZ: 00:35:46 ve 00:40:29'daki güç tablolarının sayıları altyazıda geçmiyor. -->

## 6. Örnek 11: Akım Kaynağından Gerilim Kaynağına

Şimdi tersini yapalım: İdeal olmayan akım kaynağı yerine ideal olmayan bir gerilim kaynağı koyalım.

**Verilen:** $I_s = 5$ mA, paralel $R_s = 50$ Ω, $R_L = 300$ Ω. Eşdeğer gerilim kaynağı ve seri direnç bulunacak.

**Verilen devrede yük varken:** Akım bölücüden, toplam $50 + 300 = 350$ Ω ve karşı koldaki direnç 50 Ω ile:

$$I_L = 5\text{ mA} \cdot \frac{50}{350} = \frac{5}{7}\text{ mA}$$

$$V_L = \frac{5}{7}\text{ mA} \cdot 300\,\Omega = \frac{1500}{7}\text{ mV} \approx 214.3\text{ mV}$$

> **Ders sonrası not:** Hoca $V_L$ için "500 bölü 7" dedi, kendisi de hesapta yanlışlık olup olmadığına baktı; doğrusu $\frac{1500}{7}$ mV'tur (python ile hesaplandı). Bu değer sonraki adımları etkilemiyor.

**Eşdeğer devrede yük varken:** $V_s$ ve $R$ bilinmiyor, yük yine 300 Ω:

$$I_L = \frac{V_s}{R + 300}, \qquad V_L = 300 \cdot \frac{V_s}{R + 300}$$

Bunları yukarıdaki değerlere eşitleyebiliriz. Ama dikkat edin, $V_L$ denklemi $I_L$ denkleminin 300 ile çarpılmış halidir. Yani ikisi aslında aynı denklemdir ve iki bilinmeyeni çözmeye yetmez. Bu yüzden yük kaldırılmış senaryoyu da kullanırız.

**Yük kaldırılmış:** Yük yerine sonsuz direnç koyduğumuzda verilen devrede bütün akım $R_s$ üzerinden döner:

$$V_L = 5\text{ mA} \cdot 50\,\Omega = 250\text{ mV}$$

Eşdeğer devrede yük ayrılınca akım akmaz, uçlarda $V_s$ görülür. O halde $V_s = 250$ mV.

**Çözüm:** $V_s$'yi birinci denklemde yerine koyalım:

$$\frac{250\text{ mV}}{R + 300} = \frac{5}{7}\text{ mA} \quad\Rightarrow\quad R + 300 = 350 \quad\Rightarrow\quad R = 50\,\Omega$$

Aynı kural burada da çıktı: Kaynak dönüşümü sonucunda elde edilen direnç değerleri birbirine eşit olmalıdır. Bu, akım kaynağından gerilim kaynağına dönerken de geçerlidir. Hoca burada önce "eşdeğer direnç" dedi, sonra "eşdeğer direnç demeyelim, iki yapıdaki direnç değerleri birbirine eşit" diye düzeltti.

## 7. Eşdeğerlik Ölçütünün Özeti

Eşdeğerlik ölçütümüz şudur: Herhangi bir terminalden baktığımızda, bu terminale bağlanan yük direncinin **bütün değerleri** için, yükte oluşan gerilim ve yükten akan akım aynıysa, farklı topolojiler birbirine eşdeğerdir.

Bu eşdeğerliğin temel örneği gerilim kaynağına seri direnç ile akım kaynağına paralel direncin eşdeğerliğidir. Eşdeğerlikten hareketle seri iç direnç ile paralel iç direncin birbirine eşit olduğunu gördük. Ayrıca yükten en fazla gücü çekebilmek için yük direncinin iç dirence eşit seçilmesi gerektiği ortaya çıktı. Bu durumda iki eleman eşit olduğundan gücün yarısı iç dirençte, yarısı yük direncinde harcanır. Yani maksimum güç noktasında yük, modeldeki ideal kaynağın sağladığı gücün yarısını alır.

> **Ders sonrası not:** Hoca buna "yükten çekilebilecek güç ideal kaynağın sağladığının en fazla yarısıdır" dedi; bu yalnız maksimum güç noktası için doğrudur. Yükün aldığı pay genel olarak $\frac{R_L}{R_s + R_L}$'dir ve $R_L > R_s$ için yarıdan büyüktür. Ama o durumda yükteki mutlak güç, $R_L = R_s$'dekinden küçüktür (python ile hesaplandı).

## 8. Örnek 12: Kaynak Dönüşümüyle $v_0$

**Verilen:** Soldan sağa: 4 Ω ile paralel, aşağı yönlü 3 A akım kaynağı; 2 Ω seri direnç; $v_0$'ın ölçüldüğü 8 Ω; 3 Ω seri direnç ve 12 V gerilim kaynağı. $v_0$ bulunacak.

<!-- BELİRSİZ: Devre slaytta. Eleman yerleşimi kısa nottan ve altyazıdaki sözlü anlatımdan kuruldu. -->

Bu karmaşık görünen devreyi şimdiye kadarki yöntemlerle üç düğüm üzerinden düğüm denklemleri ya da üç çevre üzerinden çevre denklemleriyle çözebiliriz. Pratik yol ise kaynak dönüşümüdür.

**Adım 1:** 3 A ve paralel 4 Ω yerine bir gerilim kaynağı ve seri direnç koyalım. Değer çarpımdan gelir: $3 \cdot 4 = 12$ V. Direnç yine 4 Ω'dur.

> **Hocanın vurgusu:** Kaynak yönüne dikkat edin. Akım kaynağı aşağı yönlü olduğu için gerilim kaynağının referans yönü de aşağı doğru olur. Hoca kaynağı bunu vurgulamak için özellikle ters çizdi.

**Adım 2:** 4 Ω ile 2 Ω artık seridir, tek bir direnç gibi düşünülür: $4 + 2 = 6$ Ω.

**Adım 3:** Sağ taraftaki 12 V ve seri 3 Ω de dönüşüme uygundur. Akım kaynağı ve paralel 3 Ω olur: $\frac{12}{3} = 4$ A (ara adım eklendi).

> **Ders sonrası not:** Hoca bu dönüşümde bir an "seri iç direnç ve akım kaynağı" dedi; doğrusu akım kaynağına paralel iç dirençtir, nitekim devamı da paralel yapıyla kuruldu.

**Adım 4:** Sol taraftaki 12 V ve seri 6 Ω'yu da çevirelim: $\frac{12}{6} = 2$ A akım kaynağı ve paralel 6 Ω. Artık bütün elemanlar birbirine paraleldir.

**Adım 5:** Buradan istersek daha ileri de gidebiliriz. Bir kaynağı tekrar gerilim kaynağına çevirip tek göze inebilir, tek gözde birbirine seri kaynakları toplayabiliriz. Ama bizden istenen $v_0$'dır ve $v_0$'a kadar inmek yeterlidir. Aynı $v_0$ dönüşümler boyunca korunur, çünkü 8 Ω dönüşüme sokulmamıştır. Topolojik olarak iki gözlü bir devreye inmek yeter.

**Adım 6:** 6 Ω ile 3 Ω paraleldir: $6 \parallel 3 = 2$ Ω. Kaynaklar ters yönlü olduğundan net katkıları $4 - 2 = 2$ A'dir (ara adım eklendi).

**Adım 7:** 2 A, 8 Ω ve 2 Ω arasında paylaşılır. 8 Ω'dan geçen akım, karşı koldaki 2 Ω ile orantılıdır:

$$i_8 = 2 \cdot \frac{2}{2 + 8} = 0.4\text{ A}, \qquad v_0 = 0.4 \cdot 8 = 3.2\text{ V}$$

Düğüm denklemleriyle aynı sonuç python ile hesaplandı: $v_0 = \frac{16}{5} = 3.2$ V. Kaynak dönüşümü daha basit topolojilere götürdüğü için burada avantajlı olur.

> **Hocanın vurgusu:** Kaynak dönüşümleriyle $v_0$'ı kaybetmeden ilerledik. Aradığımız gerilimin ait olduğu eleman dönüşüme sokulmadı.

## 9. Örnek 13: Kaynak Dönüşümüyle $i_0$

**Verilen:** Solda birbirine paralel 6 Ω, yukarı yönlü 5 A ve 3 Ω. Üstte, sol ucu eksi, sağ ucu artı olan 5 V kaynak. Ortada $i_0$ akımının aşağı aktığı 7 Ω. Sağda yukarı yönlü 3 A ve ona paralel, 1 Ω ile 4 Ω'luk seri kol. $i_0$ bulunacak.

<!-- BELİRSİZ: Devre slaytta. Sağdaki 1 Ω + 4 Ω kolu altyazıda yalnız "5 ohm" olarak geçiyor, ayrıntı kısa nottan alındı. Slayttaki 1.78 A cevabı da kısa nottan alındı. -->

Hoca bu örneği yöntemin nereye kadar götürülebileceğini göstermek için uzattı. Önce topolojik olarak her iki tarafı aynı anda dönüştürdü.

**İlk deneme:** Soldan başlayalım. 5 A ve paralel 6 Ω yerine $5 \cdot 6 = 30$ V ve seri 6 Ω yazılabilir. Sağda ise 3 A ve paralel 5 Ω yerine seri 5 Ω ve $3 \cdot 5 = 15$ V konabilir. Bu noktada hoca bir süre fikir sordu.

**Soru:** Az önce gerilim kaynağından akım kaynağı yapmıştık. 30 V'luk kısmı hiç değiştirmesek olmaz mı?

**Cevap:** Olur, belki daha pratik bir şey çıkar. Gerçekten de 6 Ω ile 3 Ω'luk dirençler bu uçlardan bakıldığında birbirine paraleldir ve bu bilgi kullanılmalıdır.

**Sol taraf:** $6 \parallel 3 = 2$ Ω, yani 5 A ve paralel 2 Ω elde ederiz. Bunu çevirirsek $5 \cdot 2 = 10$ V ve seri 2 Ω olur. Bunun devamında 5 V'luk kaynak vardır. Yönleri aynı olduğu için toplanırlar: $10 + 5 = 15$ V ve seri 2 Ω.

**Sağ taraf:** 15 V ve seri 5 Ω.

Devre şuna indi: 15 V, seri 2 Ω; ortada 7 Ω; öbür tarafta seri 5 Ω ve 15 V. Hoca buradan farklı adımlar denedi. Yalnız birini çevirmenin pek pratik olmadığını, paralel direnç sayısının arttığını söyledi ve sonunda iki tarafı da akım kaynağına çevirdi:

$$\frac{15}{2} = 7.5\text{ A} \parallel 2\,\Omega, \qquad \frac{15}{5} = 3\text{ A} \parallel 5\,\Omega$$

Bu kaynaklar aynı yönlü ve paraleldir, toplam katkıları:

$$I_s = 7.5 + 3 = 10.5\text{ A}$$

Devre, bir akım kaynağı, $2 \parallel 5$ ve 7 Ω'luk bir devreye indirgenir. 7 Ω'dan geçen akım, akım bölücüyle:

$$i_0 = 10.5 \cdot \frac{2 \parallel 5}{7 + 2 \parallel 5}$$

Hoca değeri yazdı ama sayısını hesaplamadı. $2 \parallel 5 = \frac{10}{7}$ Ω ile (ara adım eklendi):

$$i_0 = 10.5 \cdot \frac{10/7}{7 + 10/7} = \frac{105}{59} \approx 1.78\text{ A}$$

Bu sonuç, 5 V kaynağın iki yanındaki düğümlerden yazılan denklemlerle de python ile hesaplandı: $i_0 = \frac{105}{59}$ A.

Hoca işin biraz dolambaçlı olduğunu kabul etti. Bu devre iki düğüm üzerinden düğüm denklemleriyle de çözülebilir. Amaç, kaynak dönüşümünü nasıl çeşitlendirebileceğimizi göstermekti.

**Soru:** Kaynak dönüşümünü ara adımlarda yapsak daha iyi olmaz mı? Solda ve sağda akım kaynakları var, çoğu paralel gibi duruyor.

**Cevap:** Öyle görünüyor, ama 5 V'luk kaynak bu durumu bozuyor. Hepsi paralel olamıyor, 5 V'u bir şekilde kurtarmak gerekiyordu.

## 10. Norton ve Thevenin Teoremleri

### 10.1 Teoremlerin İfadesi

Doğrusal elemanlardan oluşan kompleks bir devre olsun. Bu devrenin, herhangi bir $R_L$ değeri için yük direncine etkisi, eşdeğer olarak şu iki yapıdan biriyle yazılabilir:

- **Thevenin:** Bağımsız bir gerilim kaynağı ve ona seri bir direnç. Yani ideal olmayan bir gerilim kaynağı.
- **Norton:** Bağımsız bir akım kaynağı ve ona paralel bir direnç. Yani ideal olmayan bir akım kaynağı.

Her yöntemde iki bilinmeyen vardır. Thevenin için Thevenin gerilimi $V_{TH}$ ve Thevenin direnci $R_{TH}$, Norton için Norton akımı $I_N$ ve Norton direnci $R_N$ hesaplanır.

Kompleks devreye (A) karşılık Thevenin yapısını (B) ve Norton yapısını (C) yazabiliyorsak, B ile C arasındaki ilişki zaten kaynak dönüşümüdür:

$$R_N = R_{TH}, \qquad I_N = \frac{V_{TH}}{R_{TH}}$$

Bu yüzden asıl problem, kompleks devreden $V_{TH}$ ve $R_{TH}$'yi belirlemektir. Thevenin elimizdeyse Norton'u bulmak kolaydır. Dersin akışı da böyledir: Yöntemler Thevenin eşdeğeri için tanımlanır, önce Thevenin sonra Norton hesaplanır. Bu iki adımı birleştirip doğrudan hesaplamak da mümkündür.

### 10.2 Terminal Kavramı

Temel kavram, devrenin bir terminalden bakıldığı haliyle eşdeğerinin elde edilmesidir. Slaytta noktalı çizgilerle işaretlenen kompleks devrenin iki terminali vardır. Bu terminal bir başka devre elemanına, burada bir yük direncine bağlanarak etki gösterir. Eşdeğer yapı da noktalı çizgilerin içinde kurulur.

> **Hocanın vurgusu:** Yük direnci, eşdeğerini oluşturduğumuz sistemin dışında bir yapıdır. Buna dikkat edin.

Bu şöyle de ifade edilir: Sol taraftaki karmaşık devre iki terminalli bir elemandır (Network A). Bunu yine iki terminalli bir Network B'ye bağlarız. Burada Network B yalnızca bir yük direncinden oluşur. Eşdeğer yazdığımız şey Network A'dır.

## 11. Yöntem 1: Art Arda Kaynak Dönüşümü

Birinci yöntem, terminallerden baktığımız taraf için kaynak dönüşümlerini art arda uygulamaktır. Devredeki elemanlar doğrusaldır (bağımlı kaynak, bağımsız kaynak, direnç) ve hepsi için kaynak dönüşümü tanımlıdır. Dönüşümleri bir gerilim kaynağı ve seri direnç kalıncaya kadar sürdürmek, Thevenin parametrelerini belirlemek demektir.

**Örnek 14 (Yöntem 1). Verilen:** 12 V kaynak, seri 3 Ω, paralel 6 Ω, terminale doğru seri 7 Ω. Network A'nın Thevenin eşdeğeri bulunacak.

1. 12 V ve seri 3 Ω, ideal olmayan akım kaynağı olarak yazılır: $\frac{12}{3} = 4$ A ve paralel 3 Ω.
2. 3 Ω ile 6 Ω artık paraleldir: $3 \parallel 6 = 2$ Ω.
3. 4 A ve paralel 2 Ω tekrar gerilim kaynağına çevrilir: $4 \cdot 2 = 8$ V ve seri 2 Ω.
4. 2 Ω ile 7 Ω seridir: $2 + 7 = 9$ Ω.

Sonuç: $V_{TH} = 8$ V, $R_{TH} = 9$ Ω. Karmaşık devreden yola çıkıp dönüşümleri art arda, kademeli uygulayarak Thevenin eşdeğerini bulduk.

Hoca, güç hesabının daha önce yapılana benzediğini söyleyip üzerinde durmadı.

<!-- BELİRSİZ: Slaytta bu örnek için güç sorusu var (01:17:10), altyazıda sayısı geçmiyor. -->

## 12. Yöntem 2: Açık Devre Gerilimi ve Kısa Devre Akımı

### 12.1 Yöntemin Adımları

İkinci yöntem, kaynak dönüşümlerini anlatırken kullandığımız açık devre yaklaşımına benzer. İki ölçüm yapılır:

1. $R_L$ çıkarılır, terminaller arasındaki gerilim ölçülür ya da hesaplanır. Bu, açık devre gerilimi $V_{OC}$'dir (open circuit voltage).
2. Terminaller arasına kısa devre eleman konur, buradan geçen akım $I_{SC}$ ölçülür ya da hesaplanır.

Hoca sınıfa bunların $R_L$'nin hangi özel durumlarına karşılık geldiğini sordu.

**Soru:** Bu ölçümler $R_L$'nin hangi değerlerine karşılık gelir?

**Cevap:** $R_L$'nin iki uç değerine: açık devre için sonsuz, kısa devre için sıfır. Yani $R_L$'nin genel hali için değil, özel iki uç değeri için çözüm yapıyoruz.

### 12.2 Neden Doğru?

Kompleks devre ile Thevenin eşdeğeri eşdeğer olduğuna göre, iki ölçüm Thevenin devresinde de aynı sonucu vermelidir. Bunu Thevenin devresi üzerinde görelim.

**Açık devre:** $R_L$ çıkarılınca akım akmaz, $R_{TH}$ üzerinde gerilim düşmez, uçlarda $V_{TH}$ görülür:

$$V_{OC} = V_{TH}$$

**Kısa devre:** Uçlar kısa devre edilince akan akım:

$$I_{SC} = \frac{V_{TH}}{R_{TH}}$$

$V_{TH}$ zaten bilindiğine göre direnç de bulunur:

$$R_{TH} = \frac{V_{OC}}{I_{SC}}$$

$R_L$'yi devrede bırakıp hesap yapsak başka terimler girer ve iş uzar. Kısa devre yapınca hızlıca çözüm çıkar.

> **Ders sonrası not:** Hoca yöntemi anlatırken birkaç kez "açık devre akımı" ve $I_{OC}$ dedi; doğrusu kısa devre akımı $I_{SC}$'dir. Hoca da sonra "kısa devre akımı olacak, düzeltelim" dedi.

### 12.3 Örnek 14 (Yöntem 2)

Aynı devre üzerinden ilerleyelim.

**Açık devre:** 7 Ω üzerinden akım akmaz. 3 Ω ve 6 Ω gerilim bölücü çalışır. 3 Ω'ya $V$ düşerse 6 Ω'ya $2V$ düşer. Toplam $3V = 12$ V olduğundan $V = 4$ V, 6 Ω'daki gerilim $8$ V'tur:

$$V_{OC} = V_{TH} = 8\text{ V}$$

Hoca ilk seferinde 4 V dedi, öğrencilerin uyarısıyla düzeltti: Direnci iki kat olan elemana iki kat gerilim düşer.

**Kısa devre:** 6 Ω ile 7 Ω paraleldir, 3 Ω bunlara seridir. Eşdeğer dirençten ana kol akımı $I_m$ bulunur:

$$R_{top} = 3 + 6 \parallel 7 = 3 + \frac{42}{13} = \frac{81}{13}\,\Omega, \qquad I_m = \frac{12}{81/13} = \frac{52}{27}\text{ A}$$

(ara adım eklendi: sayısal değerler). Ana kol akımı iki kola, dirençlerle ters orantılı bölünür. Kısa devreli kola $\frac{6}{13}$'ü gider:

$$I_{SC} = I_m \cdot \frac{6}{13} = \frac{8}{9}\text{ A}$$

$$R_{TH} = \frac{V_{OC}}{I_{SC}} = \frac{8}{8/9} = 9\,\Omega$$

Hocanın konuşmasında bu bölme "akımı 8 V'a bölmek" diye geçti, doğru oran yukarıdaki gibidir.

### 12.4 Pratikteki Karşılığı

Yöntemin pratik yönü daha anlamlıdır. Devre karmaşık, içi ne olduğunu bilmediğimiz bir kara kutu (black box) olabilir, önemli değil. Voltmetreyle uçların gerilimini ölçeriz, sonra ampermetreyle uçları birleştirip akımı ölçeriz. Bu iki değerden $V_{TH}$ ve $R_{TH}$ hesaplanır. Deneylerde de böyle bir soru var: Kara kutu bir devre gelir ve içeride bağımlı kaynak olmadığı bilgisi verilmişse, eşdeğeri böyle pratikçe çıkarılır.

**Soru:** $R_{TH}$ içerideki elemanların eşdeğer direnci mi?

**Cevap:** Bunu birazdan özel bir durum için söyleyeceğiz. Yöntem 2'de $R_{TH}$, açık devre geriliminin kısa devre akımına bölünmesiyle elde edilir.

## 13. Yöntem 3: Kaynakları Sıfırlayıp Eşdeğer Direnç Bulmak

Üçüncü yöntem, az önceki sorudaki duruma karşılık gelir.

1. $R_L$ çıkarılır. Açık devrede uçlardaki gerilim ölçülür ya da hesaplanır. Bu $V_{TH}$'dir.
2. Kompleks devredeki bütün bağımsız kaynaklar sıfırlanır (deactivate). Gerilim kaynağı yerine kısa devre, akım kaynağı yerine açık devre konur. Devrenin iç yapısını bildiğimiz, yani teorik durumda yapılabilir.
3. Terminalden bakılan eşdeğer direnç hesaplanır. Bu $R_{TH}$'dir.

Bunu Thevenin devresi üzerinde kontrol edelim. $R_L$'yi çıkarıp gerilim ölçmek $V_{TH}$'yi veriyordu. Gerilim kaynağını sıfırlayıp yerine kısa devre koyarsak, terminalden bakıldığında içeride tek eleman kalır: $R_{TH}$. Yani kural Thevenin eşdeğeri için de tutar.

**Örnek 14 (Yöntem 3):** Açık devre gerilimi 8 V bulunmuştu. 12 V sıfırlanır, yerine kısa devre konur. 3 Ω ile 6 Ω paralel olur: $3 \parallel 6 = 2$ Ω. 7 Ω ile bu 2 Ω seridir:

$$R_{\text{eş}} = R_{TH} = 2 + 7 = 9\,\Omega$$

## 14. Yöntem 4: Test Kaynağı

### 14.1 Ne Zaman Kullanılır?

Dördüncü yöntem özel bir durum içindir: Kompleks devrenin içinde bağımlı kaynak varsa kullanılır.

> **Hocanın vurgusu:** Çok önemli: İçeride bağımlı kaynak varsa dördüncü yöntemi kullanacağız.

> **Ders sonrası not:** Hoca yöntemi tanıtırken iki kez "bağımsız kaynaklar varsa" dedi; doğrusu "bağımlı kaynaklar varsa"dır. Hoca da hemen ardından bağımlı diye düzeltti.

Hoca gerekçeyi şöyle açıkladı: Kaynakları sıfırladığımızda, açık devre ya da kısa devre etkisi bağımlı kaynak üzerinde, yük direnciyle olan durumdan farklı bir durum oluşturur. Bu yüzden önceki yöntemler geçersiz olur.

> **Ders sonrası not:** Hoca önceki yöntemlerin geçersiz olduğunu söyledi; bu, kaynakları sıfırlayıp yalnız dirençlerden eşdeğer alan Yöntem 3 için doğrudur. Yöntem 2 kaynakları sıfırlamadığı için, devrede bağımsız kaynak varsa ve $V_{OC}$, $I_{SC}$ sıfırdan farklıysa doğru sonuç verir. Örnek 20'de bu python ile hesaplandı. Bağımsız kaynak yoksa oran $\frac{0}{0}$ olur, bu durum Örnek 21'dedir.

### 14.2 Adımlar

1. Kompleks devreyi kara kutu gibi düşünürüz. $R_L$ çıkarılır, terminallerdeki gerilim ölçülür: $V_{OC} = V_{TH}$.
2. Kompleks devre içindeki **bağımsız** kaynaklar sıfırlanır. Bağımlı kaynaklar sıfırlanmaz.
3. Yük direnci yerine bir test kaynağı bağlanır. Test kaynağı bağımsız bir kaynak olmalıdır, akım kaynağı ya da gerilim kaynağı olabilir.
4. Devre çözülür. Test kaynağı üzerindeki gerilim ve akım birbirine oranlanır:

$$R_{TH} = \frac{v_{test}}{i_{test}}$$

Test kaynağının değeri belirli olduğundan bir parametreyi azaltmış oluruz: Biri bilinir, diğeri çözülür.

> **Hocanın vurgusu:** Çok önemli ikinci nokta: Burada yalnızca test kaynağından gelen etkiyi inceleyeceğiz. Bu yüzden içerideki bağımsız kaynakları sıfırladıktan sonra test kaynağını uygularız. Test kaynağını, üçüncü yöntemin üzerine eklenen bir ekstra adım gibi düşünürseniz akılda daha kolay kalır.

### 14.3 Thevenin Devresi Üzerinde Kontrol

$R_L$ çıkarıldığında akım akmadığı için ölçülen gerilim $V_{TH}$'dir. Bağımsız kaynağı sıfırlayalım, yani gerilim kaynağı yerine kısa devre koyalım. Yük yerine, hipotetik olarak, 1 A'lik bir test akım kaynağı bağlayalım. Burada bağımlı kaynak olmadığından çözüm doğrudan görülür: Ölçülen gerilim $V = 1 \cdot R_{TH}$'dir. Yani gerilim genlik olarak $R_{TH}$'ye eşittir. Aynı eşdeğerlik, kompleks devrenin içinde bağımlı kaynak varken de sağlanır.

> **Ek bilgi (derste anlatılmadı):** Test kaynağının neden işe yaradığı terminal bağıntısından görülür. Doğrusal bir devre terminallerden $v = V_{TH} + R_{TH}\, i$ doğrusu gibi davranır, burada $i$ terminalden içeri giren akımdır. Bağımsız kaynaklar sıfırlanınca $V_{TH}$ terimi düşer ve $v = R_{TH}\, i$ kalır. Bağımlı kaynaklar devrede kaldığı için oran onların etkisini de içerir ve hangi test değeri seçilirse seçilsin aynı çıkar (Örnek 18 ve Örnek 20 için python ile hesaplandı).

### 14.4 Örnek 14 (Yöntem 4)

Bu devrede bağımlı kaynak olmadığından hızlıca gidelim. $V_{OC} = 8$ V. Bağımsız kaynak sıfırlanınca geriye 9 Ω kalır. Terminale 1 V test kaynağı bağlarsak akan akım bulunur, oran yine eşdeğer dirence eşit çıkar.

> **Ders sonrası not:** Hoca 1 V için akımı "0.1 amper" dedi; doğrusu $\frac{1}{9} \approx 0.111$ A'dir (python ile hesaplandı). 0.1 A alınsa oran 10 Ω çıkardı, doğru oran $\frac{1}{1/9} = 9$ Ω'dur.

Hoca, yöntemin içeride bağımlı kaynak olduğu durumda daha anlamlı olacağını söyledi. Bunu Örnek 20 ve Örnek 21'de göreceğiz.

## 15. Örnek 18: Bağımlı Kaynaksız Devrede Thevenin ve Norton

**Verilen:** 4 V kaynak, 2 kΩ, yukarı yönlü 2 mA akım kaynağı, 3 kΩ ve yük 1 kΩ. Soruda 1 kΩ'luk dirence bakan taraf için çözüm istendiğinden, yük direnci 1 kΩ'dur. Eşdeğeri aranan devre, bu iki terminalden içeriye baktığımız kısımdır. Thevenin ve Norton eşdeğerleri bulunacak.

<!-- BELİRSİZ: Devre slaytta. Eleman yerleşimi kısa nottan ve çevre denklemlerinden kuruldu. -->

Örnek, yöntem 4 başlığı altında slaytta geçiyor ama içeride bağımlı kaynak yoktur. Bu yüzden açık devre gerilimi ve kısa devre akımı ile ya da kaynakları sıfırlayarak çözülebilir.

### 15.1 Açık Devre Gerilimi

$R_L$ çıkarılır. 3 kΩ üzerinden akım akmaz. Geriye tek göz kalır ve bu gözdeki akımı akım kaynağı belirler: 2 mA. Gerilim düşümü:

$$2\text{ mA} \cdot 2\text{ k}\Omega = 4\text{ V}$$

Hoca burada önce "sıfır mı oluyor?" diye durdu, çünkü 4 V kaynak ve 4 V düşüm birbirini götürüyor gibi görünüyordu. Sohbetteki yoruma da bakarak düzeltti: Akım yönü bellidir, bu yüzden referans yönler de bu yöne göre belirlenmelidir. O zaman iki gerilim fark olarak değil toplanarak gelir. Terminaller arasında bir çevre yazınca:

$$V_{OC} = V_{TH} = 4 + 4 = 8\text{ V}$$

Hoca, bu durumda elemanın güç harcayan bir eleman olarak çıktığını ve sonucun sıfır olmadığına dikkat edilmesi gerektiğini söyledi.

### 15.2 Thevenin Direnci: Kaynakları Sıfırlayarak

Pratik yol, içerideki kaynakları sıfırlamaktır. Gerilim kaynağı yerine kısa devre, akım kaynağı yerine açık devre konur. Terminalden bakınca 2 kΩ ile 3 kΩ seridir:

$$R_{TH} = 2 + 3 = 5\text{ k}\Omega$$

Thevenin eşdeğeri 8 V ve seri 5 kΩ, yükü de 1 kΩ'dur. Bunun anlamı şudur: Devre yerine bu iki elemanı koyarsak, yük direnci ne olursa olsun, 1 kΩ, 2 kΩ, 5 kΩ fark etmez, yükte oluşan akım ve gerilim düşümü iki devrede her zaman aynı olur.

### 15.3 Kontrol: Kısa Devre Akımı

Uçlara kısa devre eleman koyunca iki gözlü bir devre kalır. Çevre denklemleriyle gidelim. Aynı akım kaynağını iki farklı çevre kullandığında bir denklem kaybediyorduk. Bunu önceki derslerdeki süper çevre (super mesh) mantığıyla aşıyoruz: Çevrelerden biri kaynağın üzerinden geçmeyecek şekilde dıştan alınır.

İç çevre için akımı kaynak belirler:

$$i_1 = -2\text{ mA}$$

Dış çevre için ilk yazılan denklem $-4 + i_2 \cdot 2\text{ k} + i_2 \cdot 3\text{ k} = 0$ idi ve $i_2 = \frac{4}{5\text{ k}}$ verdi. Öğrenci uyarısıyla düzeltildi: 2 kΩ üzerinden $i_1$ de geçiyor ve yönleri aynıdır. Doğru denklem:

$$-4 + (i_1 + i_2) \cdot 2\text{ k} + i_2 \cdot 3\text{ k} = 0$$

$i_1 = -2$ mA yazılırsa 4 V daha karşıya geçer ve:

$$i_2 = I_{SC} = \frac{8\text{ V}}{5\text{ k}\Omega} = 1.6\text{ mA}$$

Oran alındığında:

$$R_{TH} = \frac{8\text{ V}}{8\text{ V}/5\text{ k}\Omega} = 5\text{ k}\Omega$$

Aynı sonuç python ile de hesaplandı. Yöntem seçerken hangisi pratikse o kullanılabilir. Bu karmaşık devre için $R_{TH}$'yi kaynakları sıfırlayarak bulmak daha pratik oldu.

### 15.4 Norton Eşdeğeri

Thevenin'den Norton'a kaynak dönüşümüyle geçilir:

$$R_N = R_{TH} = 5\text{ k}\Omega, \qquad I_N = \frac{8\text{ V}}{5\text{ k}\Omega} = 1.6\text{ mA}$$

Sonraki benzer örneği hoca yapısı aynı olduğu için kontrol edip geçti.

<!-- BELİRSİZ: 01:42:57'de atlanan benzer örneğin içeriği altyazıda yok. -->

## 16. Örnek 20: Bağımlı Kaynaklı Devre

**Verilen:** 4 V kaynak, 2 kΩ, yukarı yönlü bağımlı akım kaynağı $\frac{v_x}{4000}$, 3 kΩ ve açık uçlarda ölçülen $v_x$. Bağımlı kaynak, terminal uçları arasındaki referans gerilime bağlı olarak tanımlanmıştır. Çözmek istediğimiz asıl durum budur: Bağımlı kaynak varken Yöntem 4 kullanılır.

<!-- BELİRSİZ: Devre slaytta. Eleman yerleşimi kısa nottan ve çevre denklemlerinden kuruldu. -->

### 16.1 Açık Devre Gerilimi

Açık devrede 3 kΩ üzerinden akım akmaz. Gözdeki akımı bağımlı kaynak belirler: $\frac{v_x}{4000}$. Bu akım 2 kΩ'da şu gerilimi düşürür:

$$\frac{v_x}{4000} \cdot 2000 = \frac{v_x}{2}$$

Referans yönler bu akıma göre alınır. Terminaller arasındaki gerilim farkı, Örnek 18'deki gibi, iki gerilimin toplamıdır ve $v_x$'e eşittir:

$$v_x = 4 + \frac{v_x}{2} \quad\Rightarrow\quad \frac{v_x}{2} = 4 \quad\Rightarrow\quad v_x = 8\text{ V}$$

Bu, $V_{OC} = V_{TH} = 8$ V'tur.

### 16.2 Test Kaynağıyla Thevenin Direnci

4 V kaynak sıfırlanır, yerine kısa devre konur. Bağımlı kaynak devrede kalır. Terminallere 1 V test kaynağı bağlanır, dolayısıyla $v_x = 1$ V olur. Çevreleri hocanın aldığı gibi alalım:

$$i_1 = -\frac{v_x}{4000} = -\frac{1}{4000}\text{ A}$$

Büyük çevre için:

$$2\text{ k} \cdot (i_1 + i_2) + 3\text{ k} \cdot i_2 + 1\text{ V} = 0$$

$2\text{ k} \cdot i_1 = -0.5$ V olduğundan:

$$-0.5 + 5\text{ k} \cdot i_2 + 1 = 0 \quad\Rightarrow\quad 5\text{ k} \cdot i_2 = -0.5\text{ V} \quad\Rightarrow\quad i_2 = -0.1\text{ mA}$$

> **Ders sonrası not:** Hoca denklemi "0.5 volt eşittir 5K $i_2$" diye kurup $i_2 = 0.1$ mA buldu; doğrusu $5\text{ k} \cdot i_2 = -0.5$ V ve $i_2 = -0.1$ mA'dir (python ile hesaplandı). Eksi işareti, bu çevrede $i_2$'nin test kaynağının artı ucuna doğru tanımlanmış olmasındandır. Yani test kaynağı devreye 0.1 mA verir ve oranın sonucu değişmez.

Test kaynağından geçen akım $i_2$'dir. Gerilim ve akım oranlanır:

$$R_{TH} = \frac{1\text{ V}}{0.1 \cdot 10^{-3}\text{ A}} = 10\text{ k}\Omega$$

### 16.3 Slayttaki Çözüm ve Hocanın Tavsiyesi

Slayttaki çözüm test kaynağı kullanmıyor. Bağımsız kaynağı olduğu gibi bırakıp doğrudan kısa devre akımı üzerinden hesap yapıyor. Hoca bunun gerekçesini, bağımsız kaynak devredeyken bağımlı kaynakta da değer oluşması olarak söyledi. Yine de her zaman böyle olmayabilir: İçeride bağımsız kaynak olup bağımlı kaynağa değer üretmeyebilir. O zaman yanlış yöntem uygulamış olabilirsiniz.

> **Ders sonrası not:** Hoca bu çözümde bağımlı kaynakta değer oluştuğunu söyledi; bu açık devre durumu için doğrudur. Kısa devrede $v_x = 0$ olduğundan bağımlı kaynak da sıfırdır ve $I_{SC} = \frac{4\text{ V}}{5\text{ k}\Omega} = 0.8$ mA çıkar. Oran yine $\frac{8}{0.8\text{ mA}} = 10$ kΩ'dur (python ile hesaplandı). Bağımlı kaynağın etkisi $V_{OC}$ içindedir. Bağımlı kaynağı hesaba katmadan yalnız dirençlerden alınan eşdeğer ise $2 + 3 = 5$ kΩ verirdi ve yanlış olurdu.

> **Hocanın vurgusu:** Bu durum çok kafa karıştırıcı oluyor. Tavsiyem: İçeride bağımlı kaynak varsa mutlaka test kaynağı üzerinden ilerleyin.

## 17. Örnek 21: Bağımsız Kaynağı Olmayan Devre

**Verilen:** Bağımlı gerilim kaynağı $1.5\,i$, 3 Ω ve 2 Ω. Devrede bağımsız kaynak yoktur. Hoca bunu asıl önemli ve kafa karıştırıcı örnek olarak gösterdi. Bu devrenin kısa devre akımını ölçmeye çalışsak sıfır değeriyle karşılaşırız.

<!-- BELİRSİZ: Devre slaytta. Bağımlı kaynağın ve $i$ akımının konumu çözüm denkleminden kuruldu: $i$ terminal akımı, 2 Ω terminaller arasında, 3 Ω bağımlı kaynakla seri. -->

**Açık devre:** Terminal açılınca $i = 0$ olur. O zaman bağımlı kaynağın gerilimi de sıfırdır ve:

$$V_{OC} = V_{TH} = 0$$

**Test kaynağı:** Bağımsız kaynak zaten olmadığı için sıfırlanacak bir şey yok. Terminale 1 A test akım kaynağı bağlanır. Akım kaynağı tercih edilmesinin nedeni, koldaki akımı doğrudan belirlemesi, bu akımın da bağımlı kaynağın gerilimini belirlemesidir. Akım yönü nedeniyle $i = -1$ A'dir, bağımlı kaynak gerilimi:

$$1.5\,i = -1.5\text{ V}$$

Şimdi üst düğümde akımları yazalım. Düğüm gerilimi $v_{test}$ olsun. 2 Ω'dan aşağı $\frac{v_{test}}{2}$ akar. Ayrıca $i = -1$ A vardır. Bu ikisinin toplamı, 3 Ω kolundan gelen akıma eşittir:

$$\frac{v_{test}}{2} + i = \frac{-1.5 - v_{test}}{3}$$

$i = -1$ yazılırsa tek bilinmeyenli bir denklem kalır:

$$\frac{v_{test}}{2} - 1 = \frac{-1.5 - v_{test}}{3} \quad\Rightarrow\quad v_{test} = 0.6\text{ V}$$

Test akımı 1 A olduğundan:

$$R_{TH} = \frac{0.6\text{ V}}{1\text{ A}} = 0.6\,\Omega$$

Eşdeğer devre $V_{TH} = 0$, $R_{TH} = 0.6$ Ω'dur. Devre terminallerden tek bir 0.6 Ω'luk direnç gibi davranır.

Python ile hesaplandı: $v_{test} = \frac{3}{5}$ V. Kısa devrede de $i = \frac{1.5\,i}{3}$ denkleminden $i = 0$ çıkar. Yani $V_{OC}$ ve $I_{SC}$ birlikte sıfırdır ve Yöntem 2'nin oranı $\frac{0}{0}$ olur. Bu nedenle burada test kaynağı zorunludur.

> **Hocanın vurgusu:** Garanti olması açısından, içeride bağımlı kaynak varsa Yöntem 4'ü kullanalım.

## Dersin Toparlaması

Bu derste iki terminalli devreleri terminalden bakarak eşdeğer yazmayı öğrendik. Eşdeğerlik ölçütü, yükün bütün değerleri için aynı akım ve aynı gerilimi vermektir. Bu ölçütten kaynak dönüşümü çıktı: Gerilim kaynağına seri $R$ ile $I_s = \frac{V_s}{R}$ akım kaynağına paralel aynı $R$ eşdeğerdir. İdeal gerilim kaynağında seri direnç sıfır, ideal akım kaynağında paralel direnç sonsuzdur. Gerçek kaynaklarda iç direnç, gücün bir kısmının içeride harcanmasına yol açar ve yükteki güç tek tepeli bir eğri çizer. $R_L = R_s$ iken yüke aktarılan güç $\frac{V_s^2}{4R_s}$ olur.

Kaynak dönüşümünün genelleşmiş hali Thevenin ve Norton teoremleridir. $V_{TH}$ ve $R_{TH}$ dört yolla bulunur: art arda kaynak dönüşümü, açık devre gerilimi ile kısa devre akımının oranı, bağımsız kaynakları sıfırlayıp eşdeğer direnç almak ve bağımlı kaynak varken test kaynağı bağlamak. Norton eşdeğerine kaynak dönüşümüyle geçilir. Maksimum güç teoremi ve $\frac{\partial P_L}{\partial R_L} = 0$ ispatı önümüzdeki haftaya kaldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
