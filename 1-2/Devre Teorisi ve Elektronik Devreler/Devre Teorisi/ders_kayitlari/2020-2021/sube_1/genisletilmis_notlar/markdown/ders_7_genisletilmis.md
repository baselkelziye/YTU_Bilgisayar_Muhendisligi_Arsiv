# Ders 7 Genişletilmiş Notu: İşlemsel Kuvvetlendirici (Op-Amp): İdeal ve Gerçek Model, Eviren/Evirmeyen, Toplayıcı, Fark Alıcı, Kaskat, Türev ve İntegral Alıcı; Kısa Sınav 1 Çözümleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Op-Amp Nedir, Nerede Kullanılır?
- 2. Uçlar ve Eşdeğer Devre Modeli
- 3. İdeal Op-Amp Tanım Bağıntıları ve Ticari Değerler
- 4. Datasheet Okumak: LM741, Desibel ve Frekans
- 5. Besleme Sınırları ve Kırpılma
- 6. Gerilim Karşılaştırıcı ve Açık Çevrim Kazancı
- 7. Kapalı Çevrim: Eviren Kuvvetlendiricinin Türetilmesi
- 8. Kazanç Türleri
- 9. İdeal Olmayan Op-Amp ile Eviren Kuvvetlendirici (Örnek 03)
- 10. Açık Çevrim ile Kapalı Çevrimi Karıştırmamak
- 11. Örnek 04: Kırpılmalı Eviren Kuvvetlendirici
- 12. Evirmeyen Kuvvetlendirici ve Örnek 05
- 13. Gerilim Tekrarlayıcı
- 14. Toplayıcı Devre ve Örnek 07
- 15. Fark Alıcı Devre ve Örnek 08
- 16. Kaskat Bağlantı ve Örnek 09
- 17. İlk Bölümün Toparlaması
- 18. Birinci Dereceden Op-Amp Devreleri ve Analog Bilgisayarlar
- 19. Türev Alıcı Devre
- 20. Örnek 01: Basamak Girişli Türev Alıcı
- 21. Sinüs ve Kosinüs Dönüşümleri, Sinüs Girişli Türev Alıcı
- 22. İntegral Alıcı Devre
- 23. Başlangıç Gerilimi ve Geçici Hal Sorusu
- 24. Endüktanslı Türev ve İntegral Alıcılar
- 25. Geri Besleme Giriş Farkını Nasıl Sıfırlıyor?
- 26. Formülden Tasarıma: Çok Katlı Op-Amp Devresi
- 27. Kısa Sınav 1 Çözümleri

<!-- BELİRSİZ: "Örnek 01, 03, 04, 05, 07, 08, 09" numaraları altyazıda geçmiyor, slayt numaraları olarak kısa nottan alındı. Video karesi yok; devre şemaları altyazıdaki sözlü anlatımdan kuruldu. -->

## 1. Op-Amp Nedir, Nerede Kullanılır?

Geçen hafta doğrusal elemanlardan kapasite ve endüktansın genel tanımları verilmişti. Hoca bu hafta araya girerek op-amp entegresini anlatacağını, sonraki haftalarda RL, RC ve RLC devrelerine dönüleceğini söyledi. O derslerde önce DC şartlardaki davranış, sonra kaynak bağlandığında veya çıkarıldığında devrenin nasıl tepki verdiği incelenecek.

İşlemsel kuvvetlendirici (operational amplifier, op-amp), geçmişte pek çok kullanım alanı bulmuş ve bugün de kuvvetlendirici olarak yaygın kullanılan bir entegredir. Girişleri ile çıkışı arasında çok yüksek bir kazanç sunar. İki giriş ucu, tek çıkış ucu vardır. Yaptığı iş, iki giriş ucu arasındaki gerilim farkını kuvvetlendirmektir. Kazanç, çıkış geriliminin bu giriş farkına oranıdır ve gerçek elemanlarda on binler mertebesindedir:

$$A = \frac{v_{out}}{v_{dif}}$$

Temel kullanım alanı küçük sinyallerin kuvvetlendirilmesidir. Hocanın örneği sensördür. Bir sensör yapısından elde edilen küçük geri bildirim değeri op-amp ile kuvvetlendirilerek anlamlı elektriksel ve lojik seviyelere çekilebilir. Bir başka kullanım alanı analog bilgisayarlardır. Op-amp orada integral alıcı ve türev alıcı olarak görev yapıyordu. Bugün bu işlemler dijital olarak gerçekleştiriliyor.

Dersin planı şöyle kuruldu:

1. İdeal ve ideal olmayan op-amp için uç tanım bağıntıları verilir.
2. Eşdeğer model kurulur ve devrede yerine konarak çözümleme yapılır.
3. Kullanım biçimleri olarak eviren ve evirmeyen kuvvetlendirici, toplayıcı, fark alıcı ve kaskat bağlantı görülür.
4. Analog bilgisayarlardaki kullanım şekliyle integral alıcı ve türev alıcı devreler incelenir.

## 2. Uçlar ve Eşdeğer Devre Modeli

Slaytta op-amp'ın şematik gösterimi yer alıyor. Dersin geri kalanında iki gösterim temel alınacak: biri yalnız giriş ve çıkışı, öbürü bunlara ek olarak artı ve eksi beslemeyi gösterir. Ticari olarak satılan entegrelerde farklı uçlar da tanımlıdır.

Op-amp'ın uçları şunlardır:

- **Eviren giriş (inverting, eksi uç):** $v_n$ ile gösterilir. Modelde $v_1$ olarak da geçer.
- **Evirmeyen giriş (non-inverting, artı uç):** $v_p$ ile gösterilir. Modelde $v_2$ olarak da geçer.
- **Çıkış:** Tek bir uçtur.
- **Besleme uçları $V^+$ ve $V^-$:** İki görevleri vardır. Devreye enerji sağlarlar ve çıkış gerilimi için üst ve alt sınırı belirlerler.

İdeal bir op-amp'ta besleme uçlarını tanımlamaya gerek yoktur. Gerçek bir op-amp'ta ise beslemeler hem tanımlanmak hem de kullanılmak zorundadır. Bu, deneylerde görülen kırpılma durumunun sebebidir ve Bölüm 5'te ayrıntılandırılıyor.

Op-amp'ın iç davranışı bir eşdeğer devreyle modellenebilir. Eviren ve evirmeyen girişler arasındaki gerilim farkı

$$v_d = v_2 - v_1 = v_p - v_n$$

olarak tanımlanır. Model üç parçadan oluşur:

- İki giriş ucu arasında bir **giriş direnci** $R_i$ bulunur. Bu direnç üzerindeki gerilim düşümü $v_d$'dir.
- Çıkışta, $v_d$ gerilimini $A$ ile çarpan bir **gerilim kontrollü gerilim kaynağı** $A\,v_d$ bulunur.
- Çıkış ucu bu kaynağa seri bir **çıkış direnci** $R_o$ üzerinden sürülür.

Buradaki $A$ değerine **açık çevrim kazancı** denir. İki giriş arasındaki gerilim farkı $A$ miktarınca kuvvetlendirilir. Bir op-amp devresini eşdeğer devreyle çözmemiz istenirse, op-amp'ın yerine bu parçalar uçlarına uygun biçimde konur ve devre buna göre çözülür.

## 3. İdeal Op-Amp Tanım Bağıntıları ve Ticari Değerler

İdeal bir op-amp için tanım bağıntıları iki tanedir. Hoca bunları slaytta sarıyla işaretlenmiş olarak gösterdi ve dersin geri kalanındaki çözümlerin hepsi bunlardan başladı:

$$i_n = i_p = 0$$

$$v_p = v_n$$

Yani girişlerden op-amp'ın içine doğru akım akmaz ve iki giriş ucu aynı gerilim seviyesindedir. Kazanç da yine çıkışın giriş farkına oranıdır: $A_v = v_o / (v_p - v_n)$.

İdeal durum çözümlemeyi kolaylaştırır. Eşdeğer devreye ne zaman ihtiyaç vardır? İdeal olmayan bir op-amp'ın davranışı analiz edilmek istendiğinde. O zaman $R_i$ ve $R_o$ da hesaba katılır ve analiz daha gerçekçi olur.

Ticari elemanlarla ideal model şöyle karşılaştırıldı:

| Büyüklük | Ticari op-amp | İdeal op-amp |
|---|---|---|
| Açık çevrim kazancı $A$ | 10 bin, 100 bin mertebesinde | Sonsuz |
| Giriş direnci $R_i$ | Kiloohmlar, megaohmlar mertebesinde | Sonsuz (açık devre gibi) |
| Çıkış direnci $R_o$ | 100 ohmlar mertebesinde | Sıfır |
| Besleme | $-30$ V ile $+30$ V arasında desteklenir | Tanımlanması gerekmez |

İdeal durumda çıkış direncinin sıfır olması, ideal bir kaynağın iç direncinin sıfır olması gibi düşünülebilir. Sonsuz kazancı hatırlamanın yolu ise şudur: İdeal durumda iki uç arasındaki gerilim farkı sıfırdır, buna rağmen çıkışta bir değer vardır. Bu ancak sonsuz bir kazançla açıklanabilir.

> **Ders sonrası not:** Hoca giriş direncini anlatırken "ideal durumda kiloohmlar, megaohmlar mertebesinde" dedi. Cümlenin devamından anlaşıldığı gibi bu değerler ticari op-amp'lara aittir, ideal op-amp için giriş direnci sonsuzdur.

## 4. Datasheet Okumak: LM741, Desibel ve Frekans

### 4.1 Bacak Bağlantıları

Daha önce kullanmadığımız bir entegreyle karşılaştığımızda yapılacak ilk iş datasheet'ini açmaktır. Hocanın örneği ticari kodu LM741 olan entegredir. Şematikte yalnızca üç terminalle gösterilen yapı, pratikte 8 bacaklı bir entegredir. Breadboard üzerinde kurmadan önce hangi bacağın hangi görevi yaptığını bilmek gerekir.

Hoca için önemli olan bacaklar 2, 3, 4, 6 ve 7 numaralı olanlardır. Görevleri kısa nottaki slayt bilgisine göre şöyledir:

| Bacak | Görev |
|---|---|
| 2 | Eviren giriş |
| 3 | Evirmeyen giriş |
| 4 | $V^-$ |
| 6 | Çıkış |
| 7 | $V^+$ |
| 1, 5 | Offset Null (seviye ayarı) |
| 8 | NC (Not Connected, boş) |

<!-- BELİRSİZ: Altyazıda bacak numaraları ile görevlerin tek tek eşleşmesi söylenmiyor; yalnız görev adları ve "2, 3, 4, 7, 6" geçiyor. Eşleşme kısa nottan alındı. -->

Offset Null uçlarının nasıl kullanılacağı datasheet'in ilerleyen kısımlarında anlatılır. Simülasyon ortamında çizilen şematik daha çok ideal gösterime benzer, ama elemanın içine girilip $V^+$ ve $V^-$ gibi ayarlar yapılabilir. Hoca, yüz yüze bir deneyde LM741'in $\pm 12$ V bağlanarak çalıştırılacağını söyledi.

Besleme aralığı için örnek olarak şunu verdi: Datasheet'te desteklenen en büyük gerilim 30 V ise $V^+$ ucuna en fazla $+30$ V, $V^-$ ucuna en fazla $-30$ V bağlanabilir ve çıkış bu aralıkta kalır. Daha küçük değerler de bağlanabilir. Bağlanabilecek en küçük değerler de yine datasheet'ten okunur.

### 4.2 Desibel ve Kazanç

Datasheet'te DC kazancın 100 desibel mertebesinde olduğu yazabilir. Oysa modelde kazanç $A$ ile verilmişti. İkisi nasıl ilişkilendirilir?

Desibel, iki güç değerinin karşılaştırılmasıdır. Güçlerin oranının logaritması alınır ve 10 ile çarpılır:

$$\text{dB} = 10\log_{10}\frac{P_2}{P_1}$$

$A$ ise gerilimler üzerinden tanımlanmıştı. Gücü $P = V^2/R$ biçiminde yazıp yerine koyarsak, karesel terim logaritmanın dışına 2 çarpanı olarak çıkar:

$$\text{dB} = 20\log_{10}\frac{V_2}{V_1}$$

Yani iki güç karşılaştırılıyorsa $10\log$, iki gerilim karşılaştırılıyorsa $20\log$ kullanılır.

> **Ek bilgi (derste anlatılmadı):** $20\log$ biçimine geçerken $R$'nin sadeleşmesi için iki gücün aynı direnç üzerinde hesaplandığı kabul edilir. Dirençler farklı olduğunda $10\log(P_2/P_1)$ ile $20\log(V_2/V_1)$ aynı sonucu vermez. Bu fark python ile hesaplandı.

Datasheet'teki 100 dB için:

$$20\log_{10}\frac{v_o}{v_d} = 100 \quad\Rightarrow\quad \log_{10} A = 5 \quad\Rightarrow\quad A = 10^5$$

(ara adım eklendi). Beklenen 10 bin, 100 bin mertebesiyle uyumlu bir sonuçtur.

### 4.3 V/mV Biriminde Verilen Kazanç

Aynı datasheet'te tipik ve en büyük kazanç değerleri 25 ve 100 olarak görünür. İlk bakışta beklenenden çok küçüktür. Sebep birimdir: Değerler volt bölü milivolt olarak verilmiştir. Volt bölü volta çevirmek için 1000 ile çarpmak gerekir:

- $100$ V/mV $= 100\,000$ V/V
- $25$ V/mV $= 25\,000$ V/V

Böylece değerler beklenen aralığa oturur.

### 4.4 Kazancın Frekansla Değişimi

Datasheet'teki bir başka grafik, $A$ kazancının giriş işaretinin frekansına bağlı olduğunu gösterir. DC durumda bir kazanç tanımlanabildiği gibi AC durumda da kazanç vardır, fakat işaretin frekansı arttıkça kazanç azalır.

<!-- BELİRSİZ: 00:18:47'de hoca bir slaydı "bu kısmı geçiyorum" diyerek atladı; içeriği altyazıda yok. -->

## 5. Besleme Sınırları ve Kırpılma

Besleme gerilimleri hem entegreye enerji sağlar hem de çıkış işaretinin uç sınırlarını tanımlar. Gerçek bir op-amp'ta çıkış teorik olarak $A\,v_d$ değerini almak ister, ama üç durum vardır:

- $A\,v_d > V^+$ ise $v_o \approx V^+$ olur.
- $A\,v_d < V^-$ ise $v_o \approx V^-$ olur.
- $V^- < A\,v_d < V^+$ ise $v_o = A\,v_d$ olur. Çıkış uygun biçimde kuvvetlendirilmiştir.

Slaytta birinci ve ikinci durumda "yaklaşık eşit" yazılmasının sebebi çıkış direncidir. Devre bir sisteme bağlandığında çıkış direnci üzerinde bir gerilim düşümü hesaplamak gerekebilir. Çıkışa herhangi bir bağlantı yapılmamışsa çıkış doğrudan besleme değeri olarak alınabilir.

Hoca durumu kalemle kabaca çizerek gösterdi. Yatay eksen giriş $v_d$, dikey eksen çıkış $v_o$ olsun. Giriş ile çıkış arasındaki ilişki, eğimi $A$ olan bir doğrudur. $A$ 1'e yakın olsaydı doğru yaklaşık 45 derece eğimli olurdu ve giriş aralığı çıkışta yaklaşık aynı genişlikte bir aralığa denk gelirdi. Gerçekte $A$ çok büyük olduğu için doğru çok diktir: Küçük bir giriş sinyali çıkışta çok daha geniş bir aralığa karşılık gelir.

İdeal olmayan op-amp'ta çıkışın $V^-$ ile $V^+$ arasında kalma zorunluluğu vardır. Girişe, kuvvetlendirilmiş hali bu sınırları aşan bir sinyal uygulandığında, sinyal üstten ve alttan kesilir. Çıkış düz, kuvvetlendirme, düz, kuvvetlendirme biçiminde ilerler. Buna **kırpılma** denir, sınır bölgelerine de **doyum** (saturation) adı verilir.

Çıkış şekli grafik üzerinden de bulunabilir: Yatay eksendeki giriş değerinden yukarı çıkılır, kuvvetlendirme eğrisinin kesildiği noktanın dikey izdüşümü işaretlenir. Bu noktalar birleştirilince kuvvetlendirilmiş ve kırpılmış sinyal elde edilir.

## 6. Gerilim Karşılaştırıcı ve Açık Çevrim Kazancı

Op-amp'ın ilk kullanım biçimi gerilim karşılaştırıcıdır (comparator). Devrede geri besleme yoktur, gerilimler doğrudan giriş uçlarına uygulanır. Hocanın örneği artı uçta 0, eksi uçta pozitif bir gerilimdir. Artıdan eksi çıkarıldığında fark negatiftir. $A$ çok büyük olduğu için kuvvetlendirilmiş değer besleme sınırını aşar ve $v_o = V^-$ olur. Bağlantı ters çevrilirse, yani gerilim artı uçta ve 0 eksi uçtaysa, $v_o = V^+$ olur.

Üç durum şöyle özetlenir:

- $v_p = v_n$ ise fark sıfırdır. Sıfır neyle çarpılırsa çarpılsın sıfır olduğu için $v_o = 0$ olur.
- $v_p > v_n$ ise $v_o = V^+$ olur.
- $v_p < v_n$ ise $v_o = V^-$ olur.

Burada önemli olan girişlerin mutlak değeri değil, aralarındaki farktır. Uçlara 5 V ve 6 V gibi değerler uygulanmış olması tek başına bir şey değiştirmez.

Bu çalışma biçimine **açık çevrim** denir. Çıkıştan girişlere herhangi bir geri bildirim yoktur. Çıkış direncinin etkisi de göz ardı edilebilir, çünkü çıkış boştadır ve üzerinden akım akmaz. Dolayısıyla çıkışta doğrudan $v_o = A\,v_d$ görülür.

## 7. Kapalı Çevrim: Eviren Kuvvetlendiricinin Türetilmesi

**Kapalı çevrimde** çıkış, bir direnç üzerinden girişlerden birine geri bildirim olarak iletilir. Kazanç artık farklı hesaplanır.

### 7.1 Devre ve Türetme

Devre şöyledir: Giriş kaynağı $v_s$, $R_1$ direnci üzerinden eviren uca bağlıdır. Çıkış, $R_f$ geri besleme direnci üzerinden yine eviren uca bağlıdır. Evirmeyen uç topraktadır.

Çözüm ideal op-amp bağıntılarından başlar. Evirmeyen uç toprakta olduğundan $v_2 = 0$, $v_1 = v_2$ olduğundan eviren uç da 0 V'tur. Girişlerden içeri akım akmadığından $i_1 = i_2 = 0$'dır.

$R_1$ üzerinden eviren uca gelen akım:

$$i_s = \frac{v_s - 0}{R_1} = \frac{v_s}{R_1}$$

$R_f$ üzerinden çıkışa doğru akan akım:

$$i_f = \frac{0 - v_o}{R_f}$$

$i_1 = 0$ olduğu için bu iki akım eşittir: $i_s = i_f$. Buradan

$$\frac{v_s}{R_1} = -\frac{v_o}{R_f} \quad\Rightarrow\quad \frac{v_o}{v_s} = -\frac{R_f}{R_1}$$

Kapalı çevrim kazancı yalnızca $R_1$ ve $R_f$'ye bağlıdır, $A$ ifadede yoktur. Çünkü op-amp bu geri bildirimle $v_1$ ve $v_2$'yi eşit olacak biçimde dengeler.

Eviren uç, ideal durumda toprağa bağlıymış gibi 0 V'ta olduğu için **sanal toprak** (virtual ground) olarak adlandırıldı. Bu noktada devre, $v_s$'ten $R_1$ üzerinden sıfıra ve $v_o$'dan $R_f$ üzerinden sıfıra giden iki kol gibi düşünülebilir.

### 7.2 Sanal Toprak Üzerine Sorular

Bu noktada derste uzun bir soru-cevap oldu. Çünkü sezgiye ilk bakışta ters gelen birkaç şey var.

**Soru:** İki taraf da toprak yani sıfırsa, $v_s$ de sıfıra eşit olmuyor mu? **Cevap:** Hayır. Kaynağın bir ucu kendi referansına göre $v_s$ gerilimine sahiptir, $R_1$'in öbür ucu ise 0 V'tur. Yüksek potansiyelden düşük potansiyele doğru bir akım akar. $v_s$'in sıfır olması gibi bir durum yoktur.

**Soru:** $i_f$ sıfır olur mu? **Cevap:** Olmaz. Çıkışta $v_o$ gibi bir gerilim vardır ve bu gerilimi op-amp'ın kendisi oluşturur. Referansa göre bir potansiyel fark olduğu için $R_f$ üzerinden akım akar.

**Soru:** $v_1$ sıfırsa $v_o$ da sıfır olmaz mı? **Cevap:** $v_o$'ın sıfır olması gerekmez. $v_o$'daki potansiyeli op-amp'ın kendisi oluşturur. Oraya dışarıdan bir kaynak bağlanmış gibi etki gösterir. Eşdeğer modele bakılırsa, çıkıştaki potansiyel $A\,v_d$ kaynağından gelir.

**Soru:** İdeal durumda $i_1$ sıfırsa $v_d$ de sıfır olmaz mı, o zaman çıkış nasıl oluşur? **Cevap:** Hoca akım üzerinden "tersten giderek" açıkladı. $R_1$'den akan akım $i_s = v_s/R_1$'dir. Bu akım op-amp'ın içine giremediği için $R_f$ kolundan devam etmek zorundadır. Direnç üzerinden geçtiği için orada bir potansiyel farkı oluşturur. Bu fark sonucunda $(0 - v_o)/R_f = v_s/R_1$ olur, yani $v_o = -v_s R_f/R_1$. Akımın geçtiği yöne göre işaret eksidir.

**Soru:** $i_s$, $i_f$'ye mi eşit oluyor? **Cevap:** Evet. Girişlerden içeri akım akmadığı için $i_1 = i_2 = 0$'dır ve bu yüzden $i_s = i_f$'dir.

> **Ders sonrası not:** Hoca "A değerimiz kapalı çevrimde $R_f$ ile $R_1$'in oranına bağlı olarak oluşmuş oluyor" dedi. Doğrusu, açık çevrim kazancı $A$ elemanın özelliğidir ve dış dirençlerle değişmez. $R_f/R_1$ oranına bağlı olan büyüklük kapalı çevrim kazancı $v_o/v_s$'tir.

## 8. Kazanç Türleri

Şimdiye kadar gerilim kazancına, yani $v_o$ ile $v_s$ arasındaki ilişkiye bakıldı. Çıkışa bir yük direnci bağlanırsa $i_o$ akımı da tanımlanır ve başka oranlar da kurulabilir:

- **Gerilim kazancı $v_o/v_s$:** Volt bölü volt olduğu için birimsizdir.
- **Akım kazancı $i_o/i_s$:** Çıkış akımının giriş akımına oranıdır.
- **Çıkış gerilimi bölü giriş akımı $v_o/i_s$:** Birimi ohm'dur.
- **Çıkış akımı bölü giriş gerilimi $i_o/v_s$:** Birimi akım bölü gerilimdir (ara adım eklendi).

Hepsi farklı kazanç oranlarıdır ve birimleri tanımlarından gelir.

## 9. İdeal Olmayan Op-Amp ile Eviren Kuvvetlendirici (Örnek 03)

İdeal olmayan op-amp'ta $R_i$ sonsuz değildir, bu yüzden $i_1$ ve $i_2$ dikkate alınmalıdır. Aynı eviren devrede op-amp'ın yerine eşdeğer model konur. Hoca şu bağıntıları yazdı:

- $i_1$ ve $i_2$ birbirine ters yönlü olarak eşittir: $i_2 = -i_1$.
- Çıkışa yük bağlı olmadığı için $R_f$ akımı, $R_o$ üzerinden geçen akıma eşittir: $i_f = i$.
- Eviren düğümde akımlar: $i_s = i_1 + i_f$.
- Giriş farkı giriş direnci üzerinden yazılır: $v_d = v_2 - v_1 = -i_1 R_i$.
- Kaynak, $R_1$ ve $R_i$ üzerinden geçen çevre: $-v_s + i_s R_1 - v_d = 0$.
- Kaynak, $R_1$, $R_f$ ve çıkış üzerinden geçen çevre: $-v_s + i_s R_1 + i_f R_f + v_o = 0$.
- Çıkış kolu: $v_o$, $A\,v_d$ kaynağı ile $R_o$ üzerindeki düşümden oluşur.

> **Ders sonrası not:** Hoca çıkış kolunu "$A\,v_d$ eksi $R_o$ çarpı $i$" biçiminde söyledi. Akım yukarıdaki çevrelerde olduğu gibi $i_f$ yönünde, yani çıkış ucundan kaynağa doğru alınırsa doğru işaret $v_o = A\,v_d + R_o i_f$'dir. Eksi işaret, akımın kaynaktan dışarı doğru tanımlandığı duruma uyar. Bu denklem takımı python ile çözüldü ve artı işaretli yazımın diğer bağıntılarla tutarlı olduğu hesaplandı.

Denklemler birleştirildiğinde, ideal durumdaki $-R_f/R_1$ kazancına kazancı azaltıcı yönde bir çarpan eklenmiş olur:

$$\frac{v_o}{v_s} = -\frac{R_f}{R_1}\cdot\frac{A b}{1 + A b}, \qquad b = \frac{R_1}{R_1 + R_f}$$

$Ab/(1+Ab)$ her zaman 1'den küçüktür. Yani ideal olmayan op-amp beklenenden daha düşük bir kazanç verir. $A \to \infty$ olduğunda bu çarpan 1'e gider ve ideal sonuca ulaşılır.

> **Ders sonrası not:** Hoca derste bu formülde $R_i$ ve $R_o$'nun nereye gittiğini sordu ve uygun yerine koymalarla ifadenin $R_1$ ile $R_f$ cinsinden yazılabildiğini söyledi. Yukarıdaki kapalı form, eşdeğer devrenin $R_i \to \infty$ ve $R_o \to 0$ sınırındaki çözümüyle birebir aynıdır (python ile rasyonel sayılarla hesaplandı). $R_i$ ve $R_o$ sonlu alınırsa tam çözüm bu formülden az da olsa ayrılır (python ile hesaplandı).

<!-- BELİRSİZ: Formül ve b tanımı slayttan kısa nota geçmiş; altyazıda yalnız "AB bölü 1 artı AB" ve "R1 ve RF'ye bağlı" geçiyor. Slaytın ara adımları altyazıda okunmuyor. -->

## 10. Açık Çevrim ile Kapalı Çevrimi Karıştırmamak

Modelde $v_o = A\,v_d$ yazıldığı için, ideal durumda $v_d = 0$ olması zihinleri karıştırdı.

**Soru:** İdealde $v_1 = v_2$, yani $v_d = 0$ oluyor. $v_o = A\,v_d$ olduğuna göre $v_o$ sıfır olmaz mı? **Cevap:** Kazancın da sonsuz olduğu dikkate alınmalıdır, bu çarpım basitçe sıfır sayılamaz. Besleme sınırları varsa çıkış bu sınırlarda kalır, yani doyuma ulaşır. Sınır konmazsa ideal op-amp'ta çıkış $-\infty$ ile $+\infty$ arasında değer alabilir.

> **Ek bilgi (derste anlatılmadı):** Bu soru, $v_d$'yi çıkış cinsinden yazınca netleşir. Eşdeğer modelde $v_d = v_o / A$'dır. $v_o$ sonlu bir değerdeyken $A$ büyüdükçe $v_d$ sıfıra yaklaşır. Yani $v_d = 0$ tam bir eşitlikten çok, sonsuz kazanç sınırındaki yaklaşımdır ve $v_o$'ın sıfır olmasını gerektirmez. $v_d = v_o/A$ bağıntısı sonlu kazançlı modelde python ile hesaplandı.

Hoca karışıklığın kaynağını şöyle gösterdi: Açık çevrim ve kapalı çevrim durumları ayrı ayrı ele alınmalıdır.

- **Açık çevrimde** $v_o = A\,v_d$ ve doyum sınırları geçerlidir. Karşılaştırıcı böyle çalışır. Giriş farkı sıfır değildir, çıkış çoğunlukla bir besleme sınırındadır.
- **Kapalı çevrimde** $v_p = v_n$ ve $i_n = i_p = 0$ kullanılır. Kazanç dış dirençlerden hesaplanır.

<!-- BELİRSİZ: 00:49:34 civarında hoca slaytta "almost ideal" yazdığını okudu. Kısa nota göre slayt 8'de ideal için "Av > 10^6" yazıyor; altyazıda bu değer geçmiyor. -->

## 11. Örnek 04: Kırpılmalı Eviren Kuvvetlendirici

**Verilen:** Eviren kuvvetlendirici, $R_1 = 1$ kΩ, $R_f = 10$ kΩ, $V^+ = +15$ V, $V^- = -10$ V.

**Çözüm:** Her zamanki gibi tanım bağıntılarından başlanır. $i_1 = i_2 = 0$ ve eviren uç 0 V'tur.

$$i_s = \frac{v_s}{1\text{ k}\Omega} = i_f = \frac{0 - v_o}{10\text{ k}\Omega} \quad\Rightarrow\quad v_o = -10\,v_s$$

Giriş işaretinin negatifi alındığı için bu devreye **eviren kuvvetlendirici** (inverting amplifier) denir. Besleme sınırları içinde kalmak şartıyla çıkış böyle hesaplanır. Farklı girişler için sonuç:

| $v_s$ (V) | $-10\,v_s$ (V) | Çıkış $v_o$ (V) | Durum |
|---|---:|---:|---|
| 0 | 0 | 0 | Doğrusal |
| 0.5 | $-5$ | $-5$ | Doğrusal |
| 1 | $-10$ | $-10$ | Sınırda |
| 1.1 | $-11$ | $-10$ | $V^-$'de kırpıldı |
| $-1.2$ | $+12$ | $+12$ | Doğrusal |
| $-1.51$ | $+15.1$ | $+15$ | $V^+$'da kırpıldı |

Değerler python ile hesaplandı.

> **Ders sonrası not:** Hoca tabloyu okurken "0.5 volt ise 5 volt" dedi. Kazanç negatif olduğu için doğrusu $-5$ V'tur.

Giriş-çıkış grafiğinde doğrunun eğimi $-R_f/R_1 = -10$, yani negatiftir. Doğrusal bölge $-1.5$ V $< v_s < 1$ V aralığıdır. Bu aralığın dışında besleme gerilimleri daha fazlasına izin vermediği için kırpılma olur.

Hoca burada da çıkış geriliminin kaynağını vurguladı: "Eviren uç içeri akım almıyor, çıkış da bağlı değil" gibi düşünülüp çıkış 0 V sanılabilir. Oysa $R_1$ kolundan gelip $R_f$ kolundan devam eden akım $R_f$ üzerinde bir potansiyel fark oluşturur. Bu, eşdeğer modeli açtığımızda gerilim kontrollü gerilim kaynağının ürettiği değere karşılık gelir.

## 12. Evirmeyen Kuvvetlendirici ve Örnek 05

### 12.1 Türetme

Eviren kuvvetlendiricide geri besleme de kaynak da eksi uca bağlıydı ve kazanç negatif çıkıyordu. **Evirmeyen kuvvetlendiricide** (non-inverting amplifier) geri besleme yine eksi uçtadır, ama giriş kaynağı artı uca bağlıdır. $R_1$ eksi uç ile toprak arasında, $R_f$ ise çıkış ile eksi uç arasındadır.

Artı uçta $v_s$ vardır. İdeal op-amp'ta iki giriş eşit olduğundan eksi uç da $v_s$'tir. İçeri akım akmadığından $i_s = i_f$'dir:

$$i_s = \frac{0 - v_s}{R_1}, \qquad i_f = \frac{v_s - v_o}{R_f}$$

Eşitleyip içler dışlar çarpımı yapılır:

$$-R_f v_s = R_1 v_s - R_1 v_o \quad\Rightarrow\quad R_1 v_o = R_1 v_s + R_f v_s$$

$$v_o = \frac{R_1 + R_f}{R_1}\,v_s = \left(1 + \frac{R_f}{R_1}\right) v_s$$

Dirençler pozitif olduğu için kazanç pozitiftir. Devre giriş işaretini kuvvetlendirir, işaretini değiştirmez. Adı buradan gelir.

### 12.2 Örnek 05

**Verilen:** Evirmeyen kuvvetlendirici, $R_1 = 1$ kΩ, $R_f = 10$ kΩ, $V^+ = +15$ V, $V^- = -10$ V.

**Çözüm:** Kazanç $1 + 10/1 = 11$'dir.

| $v_s$ (V) | $11\,v_s$ (V) | Çıkış $v_o$ (V) | Durum |
|---|---:|---:|---|
| 0.5 | $5.5$ | $5.5$ | Doğrusal |
| 1.6 | $17.6$ | $15$ | $V^+$'da kırpıldı |
| $-0.9$ | $-9.9$ | $-9.9$ | Doğrusal |
| $-1.01$ | $-11.11$ | $-10$ | $V^-$'de kırpıldı |

Değerler python ile hesaplandı. Grafikte eğim pozitiftir. Doğrusal bölge

$$-\frac{10}{11}\text{ V} < v_s < \frac{15}{11}\text{ V}$$

aralığıdır. Bunun dışında kazanç eğrisi kırpılır.

> **Ders sonrası not:** Hoca, slayttaki $-1.01$ V satırının hatalı olduğunu derste fark etti ve çıkışın $-10$ V ile sınırlanması gerektiğini söyledi. Kısa nota göre slaytta bu satır büyük olasılıkla $+15$ V olarak yazılmıştır. Doğru değer tabloda verilen $-10$ V'tur (python ile hesaplandı).

## 13. Gerilim Tekrarlayıcı

**Gerilim tekrarlayıcı** (voltage follower), bir gerilim değerini başka bir düğümde, herhangi bir direnç üzerinden kaybetmeden tekrar üretir. Çıkış doğrudan eksi uca bağlıdır, $v_s$ artı uçtadır. İki giriş eşit olduğundan

$$v_o = v_s$$

olur. Özelliği, ideal op-amp için herhangi bir akım kaybı yaşamadan gerilimi tekrar etmesidir.

Hoca neden gerekli olduğunu ilk bölümün sonunda şöyle açıkladı: İki nokta arasına düz bir tel çekilse, telin kapasitif ve rezistif etkileri yüzünden birtakım kayıplar olabilir. Gerilim tekrarlayıcı bunun önüne geçer.

## 14. Toplayıcı Devre ve Örnek 07

### 14.1 Türetme

Toplayıcı devre, eviren kuvvetlendiricinin bir benzeridir. Geri besleme eksi uçtadır, kaynaklar da eksi uca bağlıdır. Farkı, birden fazla kaynağın kendi direnciyle aynı düğüme gelmesidir.

> **Ders sonrası not:** Hoca bir yerde bu yapının "non-inverting amplifier'a benzer" olduğunu söyledi. Hemen öncesinde ve dersin sonundaki toparlamada söylediği gibi doğrusu inverting (eviren) yapıya benzemesidir.

Artı uç topraktadır, öyleyse eksi uç da 0 V'tur. İçeri akım akmadığından giriş akımları toplamı geri besleme akımına eşittir:

$$i_1 + i_2 + i_3 = i_f$$

$$\frac{v_a}{R_a} + \frac{v_b}{R_b} + \frac{v_c}{R_c} = \frac{0 - v_o}{R_f}$$

$$v_o = -\left(\frac{R_f}{R_a}v_a + \frac{R_f}{R_b}v_b + \frac{R_f}{R_c}v_c\right)$$

Çıkış, girişlerin doğrusal bir fonksiyonudur. Ağırlıklı bir toplama yapılmaktadır, katsayılar $-R_f/R_a$, $-R_f/R_b$ ve $-R_f/R_c$'dir.

Hedef $v_o = -(v_a + v_b + v_c)$ ise bütün dirençler eşit seçilir: $R_a = R_b = R_c = R_f$. Farklı ağırlıklar için dirençler uygun biçimde seçilir. Unutulmaması gereken, devrenin eviren mantıkta çalışması, yani sonucun başında eksi işaret olmasıdır.

Bir başka çözüm yolu süperpozisyondur: Kaynaklardan yalnız biri bırakılıp diğerleri sıfırlanır, üç adımda çözülür. Yukarıdaki çözüm bunu tek adımda yapmıştır.

### 14.2 Örnek 07

**Verilen (değerler kısa nottan):** $v_1 = 1$ V ve 5 kΩ, $v_2 = 3$ V ve 2 kΩ, $v_3 = -2$ V ve 4 kΩ, $R_f = 10$ kΩ, besleme $\pm 30$ V.

**Çözüm:**

$$v_o = -10\text{ k}\Omega\left(\frac{1}{5\text{ k}\Omega} + \frac{3}{2\text{ k}\Omega} + \frac{-2}{4\text{ k}\Omega}\right) = -10\,(0.2 + 1.5 - 0.5) = -12\text{ V}$$

Sonuç $\pm 30$ V sınırının içindedir, kırpılma yoktur (python ile hesaplandı).

<!-- BELİRSİZ: Hoca bu örneğin çözümünü slayttan atladı ("değerleri yerine koyarak elde etmemiz mümkün"). Sayılar altyazıda geçmiyor, kısa nottan alındı. -->

## 15. Fark Alıcı Devre ve Örnek 08

### 15.1 Türetme

> **Hocanın vurgusu:** Her zaman ideal op-amp'ın tanım bağıntılarından başlayın. İçeri akan akımlar sıfırdır, iki giriş ucunun gerilimi eşittir.

Fark alıcıda (fark kuvvetlendirici, difference amplifier) $v_a$, $R_a$ üzerinden eksi uca gelir ve $R_f$ çıkıştan eksi uca geri besleme yapar. $v_b$ ise $R_b$ ve $R_c$ dirençlerinden oluşan bir gerilim bölücüden geçer, bölücünün orta noktası artı uca bağlıdır, $R_c$'nin öbür ucu topraktadır.

Çözüm üç adımdır.

1. Artı uç içeri akım çekmediği için bölücü yüksüzdür. Koldan geçen akım $v_b/(R_b + R_c)$'dir, bu akımın $R_c$ ile çarpımı artı ucun gerilimini verir:

$$v = \frac{v_b}{R_b + R_c}\,R_c$$

2. Eksi uç da aynı $v$ gerilimindedir. İçeri akım akmadığından $i_s = i_f$'dir:

$$\frac{v_a - v}{R_a} = \frac{v - v_o}{R_f}$$

3. Eşitlikte $v$ yerine konur ve $v_o$ yalnız bırakılır:

$$v_o = \left(1 + \frac{R_f}{R_a}\right)\frac{R_c}{R_b + R_c}\,v_b - \frac{R_f}{R_a}\,v_a$$

Hoca bu sonucu önce biçim olarak yazdı: $v_o = X\,v_b - Y\,v_a$. Burada $X$ ve $Y$ dirençlerden hesaplanan pozitif katsayılardır:

$$X = \left(1 + \frac{R_f}{R_a}\right)\frac{R_c}{R_b + R_c}, \qquad Y = \frac{R_f}{R_a}$$

Toplayıcıdan farkı açıktır: Orada katsayılar eksi işaret altında toplanıyordu, burada iki gerilimin ağırlıklı **farkı** elde edilir.

> **Ders sonrası not:** Hoca içler dışlar çarpımını yazarken sağ taraftaki terimi "$v_o$ bölü $R_f$ çarpı $R_a$" diye okudu. Altyazı bu noktada net değil. Doğru ara adım $R_f(v_a - v) = R_a(v - v_o)$'dır. Hocanın $v_o = X v_b - Y v_a$ sonucu bu ara adımla elde edilir. Hocanın sözlü olarak verdiği "$X$, $B$ ile $C$'nin toplamı" ifadesinde ayrıca $R_a$'ya bölme de vardır (ara adım eklendi).

### 15.2 Örnek 08

**Verilen (değerler kısa nottan):** $v_a = 2$ V, $R_a = 6$ kΩ, $R_f = 30$ kΩ, $v_b = 3$ V, $R_b = 8$ kΩ, $R_c = 4$ kΩ.

**Çözüm:**

$$v_p = 3\cdot\frac{4}{8 + 4} = 1\text{ V}, \qquad v_n = v_p = 1\text{ V}$$

$$\frac{2 - 1}{6\text{ k}\Omega} = \frac{1 - v_o}{30\text{ k}\Omega} \quad\Rightarrow\quad 1 - v_o = 5 \quad\Rightarrow\quad v_o = -4\text{ V}$$

Genel formülle sağlaması: $X = 6\cdot\frac{1}{3} = 2$, $Y = 5$, $v_o = 2\cdot 3 - 5\cdot 2 = -4$ V (python ile hesaplandı).

<!-- BELİRSİZ: Bu sayılar altyazıda geçmiyor; hoca "değerleri yerine koyarak sonucu elde etmiş" diyerek slayttan geçti. -->

## 16. Kaskat Bağlantı ve Örnek 09

### 16.1 Türetme

Op-amp'lar **kaskat** bağlanabilir: Bir katın çıkışı bir sonrakinin girişi olur. Hocanın örneğinde iki kat vardır.

- **Birinci kat evirmeyendir.** Kaynak $v_s$ artı uçta, $R_1$ eksi uçla toprak arasında, $R_{f1}$ geri beslemededir. Çıkışında bir ara gerilim $v$ oluşur.
- **İkinci kat evirendir.** $v$, $R_2$ üzerinden eksi uca gelir, $R_{f2}$ geri beslemededir, artı uç topraktadır.

Formüller zaten biliniyor, doğrudan yazılabilir, ama hoca adım adım çözdü.

Birinci katta eksi uç $v_s$'tir ve $R_1$ akımı $R_{f1}$ akımına eşittir:

$$\frac{0 - v_s}{R_1} = \frac{v_s - v}{R_{f1}} \quad\Rightarrow\quad v = \left(1 + \frac{R_{f1}}{R_1}\right)v_s$$

İkinci katta eksi uç 0 V'tur ve aynı biçimde:

$$\frac{v}{R_2} = -\frac{v_o}{R_{f2}}$$

$v$ yerine konur:

$$v_o = -\frac{R_{f2}}{R_2}\left(1 + \frac{R_{f1}}{R_1}\right)v_s$$

Sonuç, evirmeyen katın kazancı ile eviren katın kazancının çarpımıdır. Kaskat bağlı katlarda toplam kazanç, kazançların çarpımıdır.

### 16.2 Örnek 09

**Verilen (değerler kısa nottan):** $v_s = 2$ V, $R_1 = 5$ kΩ, $R_{f1} = 15$ kΩ, $R_2 = 2$ kΩ, $R_{f2} = 8$ kΩ.

**Çözüm:** Birinci kat çıkışı $v = 2\,(1 + 15/5) = 8$ V. İkinci kat kazancı $-8/2 = -4$. Çıkış $v_o = -4\cdot 8 = -32$ V (python ile hesaplandı).

> **Ders sonrası not:** Kısa nota göre slaytta besleme gerilimi verilmemiştir, altyazıda da geçmiyor. Bu sonuç sınırsız ideal op-amp kabulüyle geçerlidir. Besleme sınırı $-32$ V'tan küçük büyüklükte olan bir op-amp'ta çıkış eksi besleme sınırında kırpılır.

<!-- BELİRSİZ: 01:14:21'de hoca bir slaydı "bu konu kapsam dahilinde değil" diyerek atladı; konusu altyazıda yok. -->

## 17. İlk Bölümün Toparlaması

Hoca aradan önce ideal op-amp tanımından hareketle görülen geri beslemeli devreleri şöyle özetledi:

- Dirençler seçilerek fark alıcıda çıkarma, toplayıcıda toplama, giriş gerilimlerinin farklı birer doğrusal birleşimi olarak yapılabilir.
- Çıkışın girişle aynı işarette olması isteniyorsa evirmeyen kuvvetlendirici kullanılır.
- Bir işaret dönüşümü, yani eksiyle çarpma gerekiyorsa eviren kuvvetlendirici kullanılır.
- Gerilim tekrarlayıcı, gerilim kaybı yaşamadan aynı değeri başka bir noktada üretir.

## 18. Birinci Dereceden Op-Amp Devreleri ve Analog Bilgisayarlar

Aradan sonra aynı mantık, kapasite ve endüktans içeren devrelere taşındı. Geri besleme bir kapasite veya endüktans üzerinden yapıldığında, ya da giriş katında bu elemanlar kullanıldığında **birinci dereceden op-amp devreleri** elde edilir. Bunlar işlev olarak türev ve integral alır.

Op-amp entegreleri, dijital bilgisayarlardan önce analog bilgisayarların çekirdeğini oluşturuyordu. Bu kullanımın sınırları da vardır. Günümüzde gigahertz mertebesinde işlem yapılabilirken analog bilgisayarlar 10 MHz mertebesiyle sınırlı kalır. Ayrıca devre her yerde ve her frekansta aynı şekilde çalışmaz. Datasheet'te görüldüğü gibi kuvvetlendirme frekansla azalır. Bu devreler ancak mühendislik analizinin yapıldığı belirli noktalarda ve belirli sınırlar içinde kullanılabilir.

Analize geçmeden önce kapasite elemanı hatırlatıldı. Kapasitenin depoladığı toplam yük, kapasitans ile uçlar arasındaki gerilimle doğru orantılıdır:

$$q(t) = C\,v_C(t)$$

Yük akımla ilişkilidir: Belirli bir süredeki toplam akım miktarı yükü verir, $q = \int i\,dt$. Yukarıdaki denklemin iki tarafının zamana göre türevi alınınca, yani birim zamanda geçen yük akım olduğundan:

$$i_C = C\,\frac{dv_C}{dt}$$

Aynı bağıntı integral biçiminde de yazılabilir:

$$v_C = \frac{1}{C}\int i_C\,dt$$

## 19. Türev Alıcı Devre

### 19.1 Türetme

Devre eviren kuvvetlendiriciye benzer. Tek farkı girişte $R_1$ yerine bir $C$ kapasitesinin bulunmasıdır. Kaynak $v_s$, $C$ üzerinden eksi uca gelir, $R$ geri beslemededir, artı uç topraktadır.

Çözüm yine aynı adımlarla başlar. Artı uç toprakta olduğu için eksi uç 0 V'tur ve içeri akım akmaz. Bu yüzden $i_C = i_R$'dir.

$$i_R = \frac{0 - v_o}{R} = -\frac{v_o}{R}$$

Kapasitenin bir ucu $v_s$'te, öbür ucu 0 V'ta olduğu için uçları arasındaki gerilim $v_s$'tir. $q = C\,v_s$ yazılıp iki tarafın zamana göre türevi alınır:

$$i_C = C\,\frac{dv_s}{dt}$$

> **Ders sonrası not:** Hoca bu adımda "her iki tarafın integralini alacak olursak" dedi. Yazdığı sonuç ve bir önceki açıklaması gibi doğrusu türevdir.

İki akım eşitlenir:

$$-\frac{v_o}{R} = C\,\frac{dv_s}{dt} \quad\Rightarrow\quad v_o = -RC\,\frac{dv_s}{dt}$$

Çıkış, giriş işaretinin türevinin $-RC$ sabitiyle ağırlıklandırılmış halidir.

### 19.2 Çıkış Şekillerini Okumak

Hoca iki giriş şekli üzerinden çıkışı çizdi.

**Üçgen dalga giriş.** Üçgen dalganın her parçasında eğim sabittir: pozitif, negatif, pozitif, negatif. Türev bu yüzden iki değer arasında değişen bir **kare dalgadır**. Genliği, girişin en büyük genliği ve $RC$ ile orantılıdır. Hoca ilk çizimde eksi işareti unuttuğunu fark edip düzeltti: Giriş eğimi pozitifken çıkış negatif olur, giriş eğimi negatifken çıkış pozitif olur.

**Sinüs giriş.** Sıfırdan başlayan bir sinüsün türevi kosinüstür, eksi işaretle birlikte çıkış **eksi kosinüs** olur. Kosinüs normalde 1'den başlardı, burada eksi işaret nedeniyle negatif tepeden başlar.

<!-- BELİRSİZ: Hocanın çizimlerindeki genlik ve eksen değerleri altyazıda yok. -->

## 20. Örnek 01: Basamak Girişli Türev Alıcı

**Verilen:** Giriş $v_s = 3\,u(t - 5\text{ s})$ V. Devre değerleri kısa nottan: $C = 40$ µF, $R = 20$ kΩ.

Önce birim basamak fonksiyonu (step function) tanımlandı:

$$u(t) = \begin{cases} 1, & t \ge 0 \\ 0, & t < 0 \end{cases}$$

Fonksiyon $-\infty$'dan $0$'a kadar 0 değeriyle gelir, $t = 0$'dan sonra 1 olur.

$u(t-5)$ ne olur? Fonksiyon, içindeki ifade sıfır veya sıfırdan büyükken 1 üretir. $t - 5 \ge 0$ koşulu $t \ge 5$ demektir. Yani $u(t-5)$, $t = 5$'e kadar 0'dır, sonra 1'dir. $u(t)$ ile arasındaki fark zamanda 5 birim kaydırmadır.

3 ile çarpıldığında $3u(t-5)$, $t < 5$ için 0, $t \ge 5$ için 3 V değerini alır.

Çıkış: Türev alıcı girişin değişimine bakar. $t = 5$ dışında giriş sabit olduğu için türev sıfırdır. $t = 5$ anında ise anlık bir tepe (impuls, dürtü) vardır.

$$RC = 20\text{ k}\Omega \cdot 40\ \mu\text{F} = 0.8\text{ s}$$

$$v_o = -RC\,\frac{d}{dt}\big[3\,u(t-5)\big] = -0.8\cdot 3\,\delta(t-5) = -2.4\,\delta(t-5)\text{ V}\cdot\text{s}$$

(python ile hesaplandı; $\delta$ gösterimi kısa nottan.)

> **Ders sonrası not:** Kısa nota göre hoca dürtüyü yukarı doğru çizmiştir, altyazıdan bu doğrulanamıyor. Eviren yapıda $-RC$ çarpanı olduğu için doğrusu $t = 5$ s'de negatif bir dürtüdür.

Slaytın devamı $e$ üstlü ifadelerle RC devresinin çözümüne geçiyor. Hoca, RC devreleri henüz görülmediği için bu kısmı atladı.

## 21. Sinüs ve Kosinüs Dönüşümleri, Sinüs Girişli Türev Alıcı

### 21.1 Dönüşümler

Girdi sinüs veya kosinüs olduğunda sonucu tek bir biçimde yazabilmek gerekir. Hoca bunun sebebini şöyle açıkladı: İlerleyen aşamada fazör gösterimi kullanılacak. Orada işaretler arasındaki birbirini takip etme durumunu analiz edebilmek için bütün terimler ya sinüs ya kosinüs olarak, belirli bir faz farkıyla yazılmalıdır.

Birinci kural, toplam formülünden gelir:

$$\sin(A + B) = \sin A\cos B + \sin B\cos A$$

$B = 90^\circ$ konursa $\cos 90^\circ = 0$ ve $\sin 90^\circ = 1$ olduğu için:

$$\sin(A + 90^\circ) = \cos A$$

Diğer kurallar birim çember üzerinden okundu. Sinüs düşey, kosinüs yatay izdüşümdür.

- $\sin A = \sin(180^\circ - A)$. Çemberde $A$ açısı ile $180^\circ - A$ açısının düşey izdüşümü aynıdır.
- $\sin(-A) = -\sin A$. Dördüncü bölgede aynı açı negatif sayılır, düşey izdüşüm ters işaretlidir.
- $\cos A = \cos(-A)$. Yatay izdüşüm aynıdır.
- $\cos A = -\cos(180^\circ - A)$. Yatay izdüşümler ters işaretlidir.
- $-\sin A = \sin(A - 180^\circ)$. Birinci kuraldan $\sin A = \sin(180^\circ - A)$'dır. Eksi işareti içeri alınırsa açı $-(180^\circ - A) = A - 180^\circ$ olur. Yani eksi işaretini içeri taşımak için $180^\circ$ faz farkı koymak yeterlidir.

Bu iki adım birleşince eksi kosinüs de sinüs cinsinden yazılır (ara adım eklendi):

$$-\cos A = -\sin(A + 90^\circ) = \sin(A + 90^\circ - 180^\circ) = \sin(A - 90^\circ)$$

Bütün bu özdeşlikler python ile sayısal olarak doğrulandı.

### 21.2 Sinüs Girişli Örnek

**Verilen:** $v_s = 2\sin 500t$ V. Kısa nota göre $RC = 2\times 10^{-4}$ s.

**Çözüm:** Türev alınır (ara adım eklendi):

$$\frac{dv_s}{dt} = 2\cdot 500\cos 500t = 1000\cos 500t$$

$$v_o = -RC\,\frac{dv_s}{dt} = -2\times 10^{-4}\cdot 1000\cos 500t = -0.2\cos 500t\text{ V}$$

Sinüs biçiminde:

$$v_o = 0.2\sin(500t - 90^\circ)\text{ V}$$

Çıkışın genliği 0.2 V'tur ve çıkış girişten $90^\circ$ geridedir (python ile hesaplandı).

> **Ders sonrası not:** Hoca girişin türevini "2 volt çarpı kosinüs 500t" diye söyledi. Doğrusu, zincir kuralından gelen 500 çarpanıyla $2\cdot 500\cos 500t$'dir. $-0.2$ V genliği ancak bu çarpanla elde edilir.

**Faz farkını grafikte okumak.** Giriş işaretinin sıfır olduğu nokta ile çıkış işaretinin tepe yaptığı nokta karşılaştırılır. İkisi arasındaki zaman farkı faz farkını gösterir.

## 22. İntegral Alıcı Devre

### 22.1 Türetme

Analog bilgisayarın bir başka yapısı **integral alıcıdır**. Girişte $R$, geri beslemede $C$ vardır, artı uç topraktadır. Hesap aynı biçimde başlar: İçeri akım yoktur, eksi uç 0 V'tur, bu yüzden $i_R = i_C$'dir:

$$i_R = \frac{v_s}{R} = i_C$$

Kapasitenin tanım bağıntısı $q(t) = C\,v_C(t)$'dir. Kapasitenin gerilimi $v_C = 0 - v_o = -v_o$ olur. Yük ise kapasite akımının integralidir, $q = \int i_C\,dt$. Yerine konunca:

$$\int \frac{v_s}{R}\,dt = -C\,v_o \quad\Rightarrow\quad v_o = -\frac{1}{RC}\int v_s\,dt$$

Çıkış, giriş işaretinin integralinin $-1/RC$ ile çarpılmış halidir. Bu türetmede kapasitede başlangıç gerilimi olmadığı varsayılmıştır (Bölüm 23).

### 22.2 Çıkış Şekillerini Okumak

Integral, altta kalan alandır. Hoca çıkışı bu sezgiyle çizdi.

**Kare dalga giriş.** Sıfır referansına göre pozitif kısımda alan zamanla artar, negatif kısımda aynı miktarda azalır. Alan doğrusal olarak inip çıktığı için integral bir **üçgen dalgadır**. $-1/RC$ çarpanı nedeniyle çıkış önce azalır, sonra artar, sonra azalır biçiminde ilerler.

**Üçgen dalga giriş.** Alan bu kez doğrusal değil karesel değişir: karesel artar, aynı karesellikte azalır, tekrar karesel artar.

**Soru:** Bu çıkış sinüzoidal mi oluyor? **Cevap:** Hayır, karesel bir şey oluyor. Üçgen dalganın her parçası $ax + b$ biçiminde bir doğrudur. Bunun integrali $cx^2 + dx + e$ biçiminde karesel bir ifade olur. Yani çıkış parabol parçalarından oluşur.

> **Ek bilgi (derste anlatılmadı):** Kısa nota göre slayttaki bir PSpice çizimi, sinüs girişte çıkışın $90^\circ$ önde ve bir DC ofset üzerinde olduğunu gösteriyor; altyazıda bu çizim geçmiyor, slayt içeriği büyük olasılıkla böyledir. Sonuç formülle uyumludur: $v_s = V\sin\omega t$ ve boş kapasite için $v_o = -\dfrac{V}{RC\,\omega}(1 - \cos\omega t)$ bulunur. Kosinüs terimi fazı, sabit terim DC ofseti verir. Bu ifade python ile sayısal integrasyonla doğrulandı.

## 23. Başlangıç Gerilimi ve Geçici Hal Sorusu

Hoca bir soruyu açık bıraktığını fark etti: Kapasite yüklü başlarsa, yani bir başlangıç gerilimi varsa ne olur? Türetmede bunun olmadığı varsayılmıştı. Kapasitenin başlangıç gerilimi sanki bir kaynakmış gibi ele alınabilir, ama bunun tam çözümü henüz görülmemiş bir konuyu gerektirir.

Şimdiye kadar kapasite ve endüktans için yalnızca tanım bağıntıları verildi, **geçici hal** (transient) analizi yapılmadı. Bilinenler kalıcı hal veya DC analiz durumlarıdır:

- Kapasite çok uzun süre şarjda bırakılırsa gerilimi şarj gerilimine eşit olur.
- Uçları çok uzun süre kısa devre edilirse ya da bir direnç üzerinden boşaltılırsa uçlarındaki gerilim sıfır olur.

Oysa bir kaynak bağlandığı anda yük birikimi zamana bağlı olarak üstel (eksponansiyel) biçimde değişir. Yüklü bir kapasiteyi direnç üzerinden boşaltırken de yük, akım ve gerilim üstel bir mantıkla değişir. Slaytlardaki $e$ üstlü formüller, kapasite ve endüktans analizinin bir adım ileri götürülmüş halidir.

Hoca bu çözümlemeleri, kapasite elemanının DC ve geçici hal analizi görüldüğünde yapmak üzere sonraya bıraktı. Başlangıç yükünün etkisi de o zaman ele alınacak.

## 24. Endüktanslı Türev ve İntegral Alıcılar

Aynı işlevler kapasite yerine endüktansla da elde edilebilir. Hoca sonuçları söyledi ve hesabı öğrencilere bıraktı:

- **Girişte $R$, geri beslemede $L$:** Türev alıcı olarak çalışır.
- **Girişte $L$, geri beslemede $R$:** İntegral alıcı olarak çalışır.

Kısa notta bu sonuçlar şöyle verilmiştir:

$$v_o = -\frac{L}{R}\frac{dv_s}{dt} \qquad\text{ve}\qquad v_o = -\frac{R}{L}\int v_s\,dt$$

Birinci durumda $i = v_s/R$ akımı $L$'den geçer, $0 - v_o = L\,di/dt$ olur. İkinci durumda $v_s = L\,di/dt$'den $i$ bulunur, $v_o = -R\,i$ olur (ara adım eklendi).

> **Ders sonrası not:** Hoca toparlamada, geri beslemenin kapasite üzerinden yapıldığı durumun türev alıcı, yerleri değiştirilince integral alıcı olduğunu söyledi. Bu ifade ters olmuştur. Bölüm 19 ve 22'deki türetmelere göre türev alıcıda $C$ girişte, integral alıcıda $C$ geri beslemededir.

## 25. Geri Besleme Giriş Farkını Nasıl Sıfırlıyor?

> **Hocanın vurgusu:** Geri besleme varsa, girişlerden içeri akan akımlar sıfırdır ve uçlar arasındaki potansiyel farkı sıfırdır. Tekrar: Bu tanım bağıntısı bir geri besleme durumu olduğunda kullanılır.

Eşdeğer devre mantığı ise kuvvetlendirme aralığında geçerlidir. Çıkış besleme sınırlarını aşmıyorsa kuvvetlendirme aralığındayız. Teorik çıkış besleme aralığının dışına çıkıyorsa, çıkışın beslemeyle kırpılacağının farkında olmamız gerekir.

Soru olarak geldiği için hoca, $v_p = v_n$ eşitliğini sağlayanın ne olduğunu sonda tekrar anlattı. Süreç adım adım düşünülürse:

1. Devre ilk açıldığı anda artı uç ile eksi uç arasında yüksek bir gerilim farkı oluşur, $v_2$ daha büyüktür.
2. Op-amp bu farkı kuvvetlendirerek bir çıkış üretir.
3. Başlangıçta hiç akım yoktur. Bu çıkışa bağlı olarak geri besleme direnci üzerinden yeni bir akım oluşur.
4. Oluşan akım, $v_1$'in $v_2$'ye yaklaşmasını sağlar, yani aradaki farkı azaltır.
5. Süreç, aradaki fark sıfırlanana kadar sürer.

Dolayısıyla farkı sıfırlayan şey geri besleme direncidir. $v_d$, artıdan eksi çıkarılarak tanımlandığı için geri beslemenin eksi uca yapılması anlamlıdır. "Zaman geçtikçe" denmesi, süreci yavaş adımlarla ifade etmek içindir. Gerçekte bu olay hızlıca gerçekleşir.

<!-- BELİRSİZ: 02:10:16'da "aradaki fark azaldıkça da, aradaki fark giderek artar" cümlesi ve ardından gelen "aynen söylediğiniz gibi" net değil; öğrencinin sözü altyazıda yok. -->

## 26. Formülden Tasarıma: Çok Katlı Op-Amp Devresi

Hoca bir tasarım alıştırması önerdi. İstenen çıkış şudur:

$$v_o = -\frac{1}{2}V_A + 2V_B - 4V_C$$

İfadeye bakınca içinde neler olduğu görülür: Eviren bir kazanç, evirmeyen bir kazanç, bir toplama ve bir çıkarma. Tasarım birkaç kat içeren kaskat bir op-amp devresine dönüşür. Birden fazla yaklaşım mümkündür. Hoca iki okuma verdi:

- İlk iki terim için eviren ve evirmeyen katlar, sonra bir toplama ve çıkarma katı.
- Pozitif işaretli terimi önce eviren bir katla işaretini çevirip, sonra bütün terimleri tek bir toplayıcıda toplamak.

> **Hocanın vurgusu:** Verilen bir formülasyondan tasarıma gitmek ilgilenilmesi gereken konulardandır. Böyle bir çıkış verildiğinde neyin gerektiğini görüp devreyi kaskat olarak kurabilmek gerekir. Referans kitapta ve çevrimiçi kaynaklarda bu tür örnekler vardır, kendi örneğinizi de üretip çözebilirsiniz.

> **Ders sonrası not:** Derste çözüm yazılmadı. İkinci okumaya göre kısa notta bir çözüm verilmiştir: Birinci kat eviren ($R = 10$ kΩ, $R_f = 20$ kΩ) ve çıkışı $V' = -2V_B$; ikinci kat toplayıcı ($R_f = 20$ kΩ) ve girişleri $V_A$ için 40 kΩ, $V'$ için 20 kΩ, $V_C$ için 5 kΩ. Katsayılar $-\tfrac12$, $+2$ ve $-4$ olarak python ile hesaplandı.

## 27. Kısa Sınav 1 Çözümleri

Dersin son bölümünde hoca Kısa Sınav 1'in sorularını çözdü. Devre şemaları altyazıda yer almadığı için çözümler hocanın sözlü anlatımı ve yazdığı denklemler üzerinden aktarılıyor.

<!-- BELİRSİZ: Sınav devrelerinin şemaları altyazıda yok. Eleman yerleşimleri yalnız denklemlerden okunabiliyor; soru metinleri tam değil. -->

### 27.1 Soru 1: Düğüm Sayısı, KVL, KCL ve Enerji

**(a) Düğüm sayısı.** Referans düğüm dahil toplam **8 düğüm** vardır. Aynı tel üzerindeki iki nokta farklı düğüm gibi görünse de ortaktır. Hoca sayarken önce 7'ye ulaştı, ardından 24 V kaynağı ile $R_2$ arasındaki düğüm hatırlatıldı ve sonuç 8 olarak doğrulandı. Bu tür sayımlarda gözden kaçabilecek bir nokta budur.

**(b) $v_x$ gerilimi.** Verilen çevrede KVL yazılır:

$$8 + 3 + 6 - 24 + 4 + 2 - 3 - v_x = 0 \quad\Rightarrow\quad v_x = -4\text{ V}$$

Ara toplam: $8 + 3 + 6 = 17$, $17 - 24 = -7$, $-7 + 4 + 2 = -1$, $-1 - 3 = -4$ (ara adım eklendi; python ile hesaplandı).

**(c) $R_5$ akımı.** Verilen yönlerde 10 A, $R_3$'te 3 A, $R_4$'te 5 A vardır. Ortak düğümde giren ve çıkan akımlar eşitlenir. Denklem kısa nottan:

$$3 + 5 + i = 10 \quad\Rightarrow\quad i = 2\text{ A}$$

Hoca akımın referans yönüne dikkat çekti. Akım derste tanımlanan yönde 2 A çıkar. Referans ters seçilseydi $-2$ A çıkacaktı.

**(d) $R_5$'in 7 saniyede harcadığı enerji.** Enerji, güç çarpı zamandır. $R_5$ üzerinde $-4$ V ve seçilen yönde 2 A olduğu için yönler uyumludur ve güç pozitif çıkar:

$$P = 4\text{ V}\cdot 2\text{ A} = 8\text{ W}, \qquad E = 8\text{ W}\cdot 7\text{ s} = 56\text{ J}$$

(ara adım eklendi; python ile hesaplandı.)

> **Ders sonrası not:** Kısa nota göre çözüm belgesinde bu adım "$7\cdot 2\cdot(-4) = 56$ J" yazıyor, bu yazımdaki işaret büyük olasılıkla hatalıdır, çünkü çarpım $-56$ eder. Direnç her zaman güç harcadığından doğru hesap gerilimin büyüklüğü ile yapılan $4\cdot 2\cdot 7 = 56$ J'dür.

### 27.2 Soru 2: Eşdeğer Dirençten $R$'yi Bulmak

**Verilen:** Eşdeğer direnç $R_{eq} = 50$ Ω (kısa nottan), devrede üç adet paralel 12 Ω, seri 10 Ω ve $R$, onlara paralel 60 Ω, en dışta seri 30 Ω.

**Çözüm:** Dıştan içe gidilir.

1. Dışta 30 Ω vardır, $50 - 30 = 20$ Ω kalır. Yani paralel bloğun eşdeğeri 20 Ω olmalıdır.
2. 60 Ω ile hangi direncin paraleli 20 Ω eder? Cevap 30 Ω'dur: $60 \parallel 30 = 20$ Ω.
3. Paralel dirençlerden $12 \parallel 12 \parallel 12 = 4$ Ω gelir. 10 Ω ile toplam $4 + 10 = 14$ Ω olur.
4. $R = 30 - 14 = 16$ Ω.

Sağlama: $30 + \big((4 + 16 + 10)\parallel 60\big) = 30 + 20 = 50$ Ω (python ile hesaplandı).

### 27.3 Soru 3: Kaynağın Sağladığı Güç ve Akım Yönü

Hoca bu sorunun biraz çeldirici olduğunu söyledi. Gerilim kaynağının devreye 50 W güç **sağladığı** veriliyor. Dolayısıyla seçilen yönlere bakıldığında $I$ akımının negatif olması gerekir.

$I$ pozitif olsaydı, $I$ ile kaynak geriliminin çarpımı pozitif çıkar ve kaynak güç tüketiyormuş gibi anlaşılırdı. Kaynağın devreye güç veren bir eleman olması için $I$ negatif olmalıdır. Sorunun önemli noktası budur ve yapılan hata $I$'yı 5 A almaktır.

Çözümün devamı:

1. $I = -5$ A.
2. $I_x = 9$ A veriliyor. Devrede bir de 7 A'lik kaynak vardır.
3. Bunlardan $I_y = 3$ A bulunur.
4. Bu akımla ilgili koldaki gerilim $V = 36$ kV olarak hesaplanır.
5. Aynı gerilim $R_x$ üzerindeki düşüme eşittir. $R_x$ üzerinden 9 A geçtiğine göre $R_x = 36\text{ kV}/9\text{ A} = 4$ kΩ olur (python ile hesaplandı).

<!-- BELİRSİZ: Kaynağın gerilim değeri, I_y'ye götüren KCL denklemi ve 36k değerinin hesabı altyazıda açık değil. "36 kV" birimi kısa nottan; hoca yalnız "36K" dedi. Altyazıda "Ix gerilimi" geçiyor, 9 amper olarak verildiği için akım olarak yazıldı. -->

### 27.4 Soru 4: Düğüm Analizi (Süper Düğümlü ve Süper Düğümsüz)

Hoca soruyu önce süper düğüm kullanmadan çözdü. Devredeki gerilim kaynaklarının üzerinden geçen akım önceden söylenemez, çünkü bu akımları çevresindeki elemanlar belirler. Bu yüzden her biri yeni bir bilinmeyen olarak yazılır: $i$, $j$, $k$. Bilinmeyenler $V_1, V_2, V_3, V_4, V_5, i, j, k, i_x$ olmak üzere 9 tanedir.

Düğüm denklemleri:

- $V_1$ düğümü: $\quad i = \dfrac{V_1 - V_3}{2}$
- $V_2$ düğümü: $\quad \dfrac{V_5 - V_2}{2} + j = i$
- $V_3$ düğümü: $\quad \dfrac{V_1 - V_3}{2} + \dfrac{V_4 - V_3}{3} = \dfrac{V_3}{6}$
- $V_4$ düğümü: $\quad 1 + k = j + \dfrac{V_4 - V_3}{3}$
- $V_5$ düğümü, hepsi çıkan akım: $\quad k + \dfrac{V_5}{8} + \dfrac{V_5 - V_2}{2} = 0$

Kaynak denklemleri:

- $V_1 = V_2 + 16$
- $V_2 = V_4 + 4i_x$
- $V_4 = V_5 + 8$

Bağımlı kaynağın kontrol büyüklüğü:

- $i_x = \dfrac{V_3}{6}$

Çözüm (9 denklem 9 bilinmeyen, python ile hesaplandı):

| $V_1$ | $V_2$ | $V_3$ | $V_4$ | $V_5$ | $i$ | $j$ | $k$ | $i_x$ |
|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| 24 V | 8 V | 12 V | 0 V | $-8$ V | 6 A | 14 A | 9 A | 2 A |

**Süper düğüm kullanılırsa** kaynak denklemleriyle $V_1$, $V_2$ ve $V_4$ yolları izlenerek $V_5$ cinsinden yazılır, $i_x$ yerine de $V_3/6$ konur. Böylece 5 bilinmeyen ve 5 denklem yeterli olur. Kaynak akımları hiç yazılmaz. Bu 5 denklemli sistem de python ile çözüldü ve aynı gerilimleri verdi.

### 27.5 Soru 5: Süper Çevre

Bir kaynak iki çevre arasında ortak olduğu için hoca iki çevreyi birlikte aldı ve üçüncü çevreyi ayrı yazdı. Denklemler:

Bağımlı kaynak:

$$i_1 = 2i_a$$

$i_1$ ve $i_2$'nin birlikte dolaştığı süper çevre:

$$60\,i_2 + 20\,(i_1 + i_2) + 80\,(i_1 + i_2 - i_3) + 40\,(i_2 - i_3) = 0$$

$i_3$ çevresi:

$$10 + 40\,(i_3 - i_2) + 80\,(i_3 - i_2 - i_1) = 0$$

$i_a$ kol akımı, $i_3$ ile aynı yönde, $i_1$ ve $i_2$ ile ters yöndedir:

$$i_a = i_3 - i_2 - i_1$$

Çözüm:

$$i_1 = -0.1\text{ A},\quad i_2 = -0.1\text{ A},\quad i_3 = -0.25\text{ A},\quad i_a = -0.05\text{ A}$$

Değerler python ile hesaplandı. Hoca sonuçların sağlamasını düğüm gerilimleriyle gösterdi. Bir düğüm çiftinde büyüklüğü 6 V, öbür düğüm çiftinde 10 V görülür. Gerçekten $60 \cdot |i_2| = 6$ V'tur.

> **Hocanın vurgusu:** En sık yapılan hata, $i_3$ çevre akımını doğrudan $i_a$'ya eşit almak veya $i_a$'yı $i_1$'in tersi saymaktır. $i_a$ bir kol akımıdır, koldan geçen bütün çevre akımlarının yönlü toplamı hesaba katılmalıdır.

Süper çevre şart değildir. İki çevre ayrı alınıp bir denklem fazla yazılarak da aynı sonuca ulaşılabilir.

> **Ders sonrası not:** Hoca $i_3$ denklemindeki 10 değerini "10 amper" diye okudu. Terim diğer gerilim terimleriyle toplandığı için doğrusu 10 V'tur. Ayrıca kısa nota göre çözüm slaytında ikinci denklem $60(i_2 - i_3)$ olarak yazılmış, bu büyük olasılıkla bir yazım hatasıdır. Hoca derste o kolu $40(i_2 - i_3)$ diye söyledi. Yukarıdaki sonuçlar yalnız 40 Ω ile elde edilir, 60 Ω ile $i_2$ ve $i_3$ farklı çıkar (python ile hesaplandı).

## Dersin Toparlaması

Bu derste op-amp iki düzeyde ele alındı. Gerçek eleman, giriş direnci $R_i$, çıkış direnci $R_o$ ve açık çevrim kazancı $A$ içeren bir eşdeğer devreyle modellenir ve çıkışı $V^-$ ile $V^+$ arasında kırpılır. Geri beslemeli ideal op-amp için ise iki bağıntı yeter: Girişlerden içeri akım akmaz ve $v_p = v_n$'dir. Bu iki bağıntıdan eviren ($-R_f/R_1$), evirmeyen ($1 + R_f/R_1$), gerilim tekrarlayıcı, toplayıcı, fark alıcı ve kaskat devreler aynı adımlarla türetildi. Giriş veya geri beslemedeki direnç yerine kapasite ya da endüktans konunca da türev alıcı ($-RC\,dv_s/dt$) ve integral alıcı ($-\frac{1}{RC}\int v_s\,dt$) elde edildi. Türev alıcıda sinüs-kosinüs dönüşümleri, ilerideki fazör gösterimine de hazırlık oldu.

Dersin son bölümünde Kısa Sınav 1 üzerinden düğüm sayımı, KVL, KCL, enerji, eşdeğer direnç, süper düğüm ve süper çevre tekrar edildi. Kapasitede başlangıç geriliminin etkisi ve geçici hal analizi sonraki konulara bırakıldı. Sonraki derslerde DC şartlardaki RL, RC ve RLC devreleri, kaynak bağlandığında ve çıkarıldığında verdikleri tepkiyle birlikte incelenecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
