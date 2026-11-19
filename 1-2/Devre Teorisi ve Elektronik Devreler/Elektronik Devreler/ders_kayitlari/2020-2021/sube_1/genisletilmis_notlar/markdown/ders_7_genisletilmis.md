# Ders 7 Genişletilmiş Notu: Diyot Kırpıcılar, Kenetleyiciler ve Zener Diyot

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Doğrultucuların Tekrarı
- 2. Seri Diyot Kırpıcı
- 3. DC Kaynaklı Seri Kırpıcı
- 4. Paralel Kırpıcı
- 5. Kırpıcı Özet Tabloları ve Tahtada Çözülen Örnekler
- 6. Kenetleyici (Clamper) Devreler
- 7. Zener Diyot Devreleri
- 8. Gerilim Çoklayıcılar
- Örnek Sorular
- Dersin Toparlaması

## 1. Doğrultucuların Tekrarı

Ders, bir önceki haftada işlenen doğrultucuların kısa bir hatırlatmasıyla açıldı. Yarım dalga doğrultucu, sinüzoidal bir dalganın yalnız pozitif yarı periyodunu (pozitif saykılı) "kurtarır"; negatif yarı periyot çıkışta görünmez. Tam dalga doğrultucuda ise negatif yarı periyot da ters çevrilir ve her iki yarıda da pozitif bir tepe elde edilir.

Doğrultulmuş işaretin ortalama değeri, dalganın altında kalan alanın periyoda bölünmesiyle bulunur ve DC seviye ($V_{dc}$) olarak adlandırılır. Hoca değerleri şöyle hatırlattı:

- Yarım dalga doğrultucu: $V_{dc} \approx 0{,}318\,V_m$.
- Köprü tipi tam dalga doğrultucu: $V_{dc} \approx 0{,}636\,V_m$.
- Transformatörlü (orta uçlu) tam dalga doğrultucu: yine $0{,}636\,V_m$.

Bu katsayılar ideal diyot içindir. Diyotun iletim gerilimi hesaba katılacaksa silisyum için 0,7 V düşülür. Köprü doğrultucuda akım her yarı periyotta iki diyottan geçtiği için düşülecek gerilim $2 \times 0{,}7 = 1{,}4$ V olur.

## 2. Seri Diyot Kırpıcı

### 2.1 Devre ve tanım

Dersin asıl konusu diyot kırpıcılardı (diode clippers). Slayttaki devrede (ekrandan, 00:10:00) diyot giriş kaynağına seri bağlıdır, çıkış diyottan sonra toprağa bağlanan $R$ direnci üzerinden alınır. Slayttaki tanım şudur: seri kırpıcıdaki diyot, kendisini ileri kutuplamayan her gerilimi "kırpar":

- Ters kutuplayan polaritedeki gerilimi,
- İleri kutuplayan ama silisyum diyot için 0,7 V'tan küçük olan gerilimi.

Hoca girişin gösterimini de açıkladı. Şekilde $+\ v_i\ -$ diye gösterilen giriş, aslında oraya bir sinüzoidal kaynak bağlamak demektir. Bu kaynağın eksi ucu toprakta tamamlanır. Çıkıştaki $+\ v_o\ -$ de çıkış düğümünün toprağa göre gerilimidir.

Giriş yalnız sinüs olmak zorunda değildir. Kare dalga ve üçgen dalga da uygulanabilir. Bunlar ortalaması sıfır olan ve belli bir periyotta kendini tekrar eden işaretler olduğu için AC giriş olarak adlandırılır.

### 2.2 İdeal diyotla analiz

Hoca diyotu ideal kabul etti. İdeal diyot sıfırın altında iletmez; sıfırı epsilon kadar geçtiği anda iletime geçer ve kısa devre gibi davranır. Bu durumda üzerinden ne kadar akım geçeceğini devrenin geri kalanı belirler. İdeal olmayan (silisyum) diyot ise ancak 0,7 V civarında kıvrılıp akım akıtmaya başlar.

Kare dalga girişte:

- $0$ ile $T/2$ arasında giriş pozitiftir. Diyot iletir ve kısa devre olur. Devre, girişin doğrudan dirence bağlandığı hale gelir; A noktası ile toprak arasındaki $v_i$ aynen $v_o$ olarak görünür.
- Negatif yarıda diyot ters kutuplanır ve açık devre olur. Dirençten akım akmaz, çıkış toprak gerilimindedir: $v_o = 0$.

Sonuçta çıkış yalnız pozitif kısımlardan oluşur. Bu, yarım dalga doğrultucu mantığıyla çalışan bir devredir; giriş sinüs olsaydı çıkış yarım dalga doğrultulmuş sinüs olurdu. Üçgen dalga girişte de yalnız pozitif üçgen geçer (ekrandan, 00:10:00).

## 3. DC Kaynaklı Seri Kırpıcı

### 3.1 Devre

Ardından DC kaynaklı (biased) kırpıcılara geçildi. Hoca "bias" kelimesinin normalde yönelim, eğilim anlamında kullanıldığını, burada ise devreye eklenen gerilimle diyotun kutuplamasının değiştirilmesini anlattığını söyledi. Slayttaki ifade şudur: kırpıcı diyota seri bir DC kaynak eklemek, diyotun etkin ileri kutuplamasını değiştirir (ekrandan, 00:15:00).

Devre bir önceki seri kırpıcıyla aynıdır (diyot ve direnç), yalnız giriş ile diyot arasına $V = 5$ V'luk bir DC kaynak eklenmiştir. Kaynağın eksi ucu girişe (A), artı ucu diyota (B) bakar. Hoca bunu araya seri bir pil eklenmiş gibi düşünmeyi önerdi. Çıkış düğümü C, toprak T olarak işaretlendi (ekrandan, 00:25:00). Giriş tepe değeri 20 V olan bir sinüstür, yani 20 V ile −20 V arasında gidip gelir.

### 3.2 Adım adım çizim

Hoca çıkışı girişin her anına göre nokta nokta kurdu:

- $t = 0$: A noktası 0 V'tur. Pil 5 V eklediği için B noktası 5 V olur. B toprağa göre yüksekte olduğu için diyot iletir, kısa devre olur. C ile toprak arasındaki gerilim 5 V'tur. Yani sıfır anında çıkış 5 V'tadır.
- $0 < t < T/4$: Giriş 0'dan 20 V'a yükselirken her değerin üzerine 5 V eklenir. Diyot iletimde kalır, çıkış girişi 5 V yukarıdan izler.
- $t = T/4$: Giriş 20 V'tur. Anlık olarak 20 V'luk kaynağa seri bir pil bağlanmış gibi düşünülür; çıkış 25 V olur.
- $t = T/2$: Giriş tekrar 0'dır, çıkış yine 5 V'tur.
- $T/2$'yi biraz geçince giriş negatif olur. Örneğin $v_i = -1$ V iken B noktası $-1 + 5 = 4$ V'tur; diyot hâlâ iletir ve çıkış 4 V olur.
- Giriş −5 V'a geldiğinde B noktası 0 V olur. Bu an geçiş noktasıdır; çıkış 0'a iner.
- Giriş −5 V'un altındayken (−6 V'tan −20 V'a kadar) B noktası toprağın altında kalır, diyot açık devredir ve çıkış 0'dır.
- Giriş tekrar −5 V'un üzerine çıkınca, örneğin −4 V'ta B noktası 1 V olur ve diyot iletir. Çıkış 1, 2, 3 V diye artar; $t = T$'de giriş 0 olduğunda çıkış yine 5 V'tadır. Bundan sonra çizim tekrar eder.

Slayttaki çözüm de aynı noktaları verir (ekrandan, 00:30:00): $v_o = v_i + 5\ \text{V} = 20 + 5 = 25$ V, $v_o = 0 + 5 = 5$ V ve geçiş geriliminde $v_o = -5 + 5 = 0$ V. Girişteki −5 V seviyesi "transition voltage" (geçiş gerilimi) olarak işaretlenmiştir.

Hocanın vardığı sonuç şuydu: devreye seri bir DC gerilim kaynağı eklemek, çıkışı yukarı doğru öteliyormuş gibi bir davranış verir.

> **Hocanın vurgusu:** Bu tür sorular sınavlarda gelecek. Giriş verilip çıkışın çizilmesi istendiğinde önce şekle bakılır, sonra sıfır noktaları ve ekstremum (tepe) noktaları incelenir, en son diyotun iletimden kesime geçtiği an bulunur. Bu örnekte o an, B noktasını sıfıra indiren giriş değeri, yani $v_i = -5$ V'tur.

Hoca çıkışın 0'a indiği ve tekrar yükselmeye başladığı anları da zaman ekseninde gösterdi: biri $T/2$'nin biraz sonrası, diğeri $T$'nin biraz öncesidir.

## 4. Paralel Kırpıcı

### 4.1 Devre ve çalışma

Paralel kırpıcıda diyotun yeri değişir. Giriş A noktasından uygulanır, $R$ direnci A ile B arasındadır, diyot B noktası ile toprak (T) arasına çıkışa paralel bağlanır (ekrandan, 00:40:00). Slayttaki tanım: paralel kırpıcıdaki diyot, kendisini ileri kutuplayan her gerilimi kırpar. Diyota seri bir DC kaynak eklenerek kırpma seviyesi değiştirilebilir.

- Pozitif yarı periyot: B noktası toprağa göre yüksektedir, diyot iletir ve kısa devre olur. Kısa devrenin uçları arasında gerilim farkı kalmaz. Hoca bunu slayta $V_D = V_B - V_T = 0 - 0 = 0$ diye yazdı. Çıkış sıfırda kalır.
- Negatif yarı periyot: B noktası topraktan düşük gerilimdedir ($V_B < V_T$), diyot açık devredir. Devrede yalnız $v_i$ kaynağı ve ona seri bir direnç kalır; direncin öbür ucu boştadır.

### 4.2 Akım akmayan dirençte gerilim

Hoca negatif yarıda çıkışın neden girişi aynen izlediğini şu şekilde açıkladı. Bir girişe direnç bağlanıp öbür ucu boşta bırakılırsa devre toprağa giderek tamamlanmaz ve akım akmaz. Dirençten akacak akım

$$I = \frac{V_A - V_B}{R} = \frac{V_R}{R}$$

olduğuna göre akım sıfırsa $V_A = V_B$ olmak zorundadır (ekrandan, 01:20:00). Yani boştaki uca bir voltmetre bağlansa giriş gerilimi okunur: $v_o = v_i$. Bu yüzden negatif yarıda çıkış girişin negatif kısmını aynen gösterir.

Kare dalga ve üçgen dalga girişte çıkış yalnız negatif kısımdan oluşur; pozitif kısımlar sıfıra kırpılır (ekrandan, 00:40:00).

### 4.3 Öğrenci sorusu

**Soru:** Paralel kırpıcıda diyot ters yönde akım akıtmazken çıkış nasıl oluyor da grafiğin alt kısmını (negatif kısmı) iletiyor?

**Cevap:** Hoca devreyi tekrar adım adım anlattı. Pozitif kısımda B noktası toprağa göre yüksek olduğu için diyotun üzerine pozitif gerilim düşer, diyot iletir ve kısa devre gibi davranır; çıkış sıfırdır. Negatif kısımda B noktası topraktan düşük kalır ve diyot açık devre olur. Çıkış B ile toprak arasından ölçülür; telin uzatılıp uzatılmaması önemli değildir, önemli olan B ile T arasının açık devre olmasıdır. Bu durumda dirençten akım akmaz, uçlarında gerilim farkı oluşmaz ve çıkış girişe eşit olur: girişe −2 V uygulanınca çıkışta −2 V, −5 V uygulanınca −5 V görünür.

**Soru:** Yani direncin üzerinden akım geçmesini sağlıyoruz diyebilir miyiz?

**Cevap:** Hayır; $V_B < V_T$ olduğu durumda tam tersine dirençten akım akmaz, akım sıfırdır. A ve B noktalarının gerilimi aynı olduğu için $v_{in} = v_{out}$ olur. Akım yalnız diyotun ilettiği pozitif yarıda akar, o durumda da diyot kısa devre olduğu için çıkış sıfırdır.

## 5. Kırpıcı Özet Tabloları ve Tahtada Çözülen Örnekler

### 5.1 Özet tabloları

Slaytlarda Boylestad kitabından alınmış iki özet sayfası vardı (ekrandan, 00:45:00 ve 01:30:00). Hepsinde diyotlar ideal, giriş $\pm V_m$ tepeli sinüstür.

- Basit seri kırpıcılar: diyotun yönüne göre çıkış ya yalnız negatif yarı ($-V_m$ tepeli) ya da yalnız pozitif yarıdır ($V_m$ tepeli).
- DC kaynaklı seri kırpıcılar: kaynağın ve diyotun yönüne göre çıkış $-(V_m + V)$, $-(V_m - V)$, $(V_m - V)$ ya da $(V_m + V)$ tepeli olur; bazılarında çıkışın sıfır çizgisi $V$ ya da $-V$ kadar kayar.
- Basit paralel kırpıcılar (1 ve 2 numaralı): çıkış ya yalnız negatif yarı ya da yalnız pozitif yarıdır.
- DC kaynaklı paralel kırpıcılar (3, 4, 6, 7 numaralı): sinüs $V$ ya da $-V$ seviyesinde kırpılır. Örneğin 3 numarada pozitif kısım $V$'de, 6 numarada negatif kısım $-V$'de kırpılır; 4 ve 7 numarada çıkış büyük bölümde $-V$ ya da $V$ seviyesinde kalır, yalnız tepeler geçer.
- 5 numaralı devrede iki diyot ve iki kaynak ($V_1$, $V_2$, $|V_1| > |V_2|$) ile çıkış hem $V_1$'de hem $-V_2$'de kırpılır.

Hoca bu devrelerin hepsinin simülasyon programında sinüs girişle kurulmasını, çıkışlarının çizdirilip nasıl oluştuğunun açıklanmasını istedi. Simülasyonda bir AC kaynak (örneğin ±10 V ya da ±20 V), bir DC kaynak (3 V, 5 V gibi), bir diyot ve bir direnç yeterlidir; giriş ve direnç üzerindeki çıkış osiloskobun iki kanalına bağlanarak birlikte gösterilir. Girişin önce kare dalga, sonra sinüs yapılarak denenmesini önerdi.

> **Hocanın vurgusu:** Bu örneklerin hepsini kendiniz çıkarın; bu tür örnekler sınavlarda gelecek. Hem simülasyonla çizin hem de çıkış şeklinin nasıl oluştuğunu mantığıyla açıklayın.

### 5.2 Birinci örnek: ters bağlı kaynak ve ters diyotlu seri kırpıcı

Hoca daha önce sınavda sorulduğunu söylediği bir devreyi tahtada çözdü (ekrandan, 00:50:00 ve 00:55:00). Girişte ±10 V tepeli sinüs vardır. Ardından ters bağlanmış ve "−5 V" diye işaretlenmiş bir DC kaynak, sonra katodu kaynağa, anodu çıkışa bakan bir diyot gelir. Çıkış, toprağa bağlı $R$ direnci üzerinden alınır. Bu, özet slaytındaki (ekrandan, 00:45:00) çıkışı $-(V_m + V)$'ye inen DC kaynaklı seri kırpıcının karşılığıdır.

Önce diyotun ne zaman ilettiği hatırlatıldı: diyotun eksi ucu (katot) artı ucuna (anot) göre daha düşük potansiyeldeyse diyot iletir. Hoca bunu bir pil ve diyotla gösterdi: anoda bakan uçta $+5$ V varsa $V_A - V_B = 5$ V olur ve diyot iletir; pil ters çevrilirse $V_A < V_B$ olur ve diyot iletmez.

Çizim şöyle yapıldı:

- $v_i = 0$: Diyotun katodu −5 V'tadır, anodu ise direnç üzerinden toprağa bağlıdır. Katot daha düşük potansiyelde olduğu için diyot iletir ve kısa devre olur. Çıkışta −5 V görünür.
- Giriş artarken diyot iletimde kalır ve çıkış $v_i - 5$ olur: 1 V girişte $1 + (-5) = -4$ V, 2 V girişte −3 V, 3 V girişte −2 V. Giriş 5 V'a ulaştığında çıkış 0'a gelir.
- Giriş 5 V'u geçince, örneğin 6 V'ta, katot toprağa göre pozitif olur ve anottan yüksek kalır. Diyot iletmez, devre kopar ve çıkış 0'dır. Bu durum giriş tepeden inip yine 5 V'a gelene kadar sürer.
- Giriş 5 V'un altına inince, örneğin 4 V'ta, diyotun uçlarında −1 V oluşur (katot anottan düşük), diyot tekrar iletir ve çıkış yavaş yavaş aşağı iner. $v_i = 0$ anında çıkış yine −5 V'tur.
- Giriş negatifte azalmaya devam ettikçe çıkış da iner: $v_i = -10$ V iken çıkış $-10 + (-5) = -15$ V olur.
- Sonra giriş yükselir, $v_i = 0$'da çıkış −5 V'a, $v_i = 5$ V'ta 0'a gelir ve çizim tekrar eder (ekrandan, 01:15:00).

Hoca çizimin adım adım mantıkla, diyotun nerede iletip nerede iletmediğine bakılarak tamamlandığını vurguladı.

> **Ek bilgi (derste anlatılmadı):** Bu devre için çıkış tek ifadeyle $v_o = \min(v_i - 5,\ 0)$ olarak yazılabilir. Python ile $v_i = 10\sin(\omega t)$ için kontrol edildiğinde çıkış 0 ile −15 V arasında kalır; çıkışın 0'da kaldığı aralık girişin 5 V'u aştığı $30^\circ$ ile $150^\circ$ arasıdır.

### 5.3 İkinci örnek: DC kaynaklı paralel kırpıcı

Bir öğrencinin paralel kırpıcıyla ilgili sorusundan sonra hoca, "ters mantıklı" bir paralel kırpıcının daha öğretici olacağını söyleyerek 4 numaralı devredeki diyotu ters çevirdi ve bir örnek çözdü (ekrandan, 01:25:00). Devrede giriş A noktasından uygulanır, $R$ direnci girişe seridir. Çıkışa paralel kolda katodu çıkışa (B) bakan bir diyot ve ona seri bir DC kaynak vardır. Kaynak ters bağlıdır: kısa ucu (eksi) yukarıyı, uzun ucu (artı) aşağıyı gösterir; yani pil tersten bağlanmış gibidir. Kaynak değeri $V = 3$ V seçildi, böylece diyotun anodu −3 V'tadır. Giriş ±10 V tepeli sinüstür. Bu devre, özet slaytındaki negatif kısmı $-V$'de kırpan 6 numaralı devreye karşılık gelir (ekrandan, 01:50:00).

Analiz:

- $v_i = 0$: B ucu 0 V, A ucu (anot) −3 V'tadır. $V_A < V_B$ olduğu için diyot iletmez ve açık devre gibi davranır. Dirençten akım akmaz, çıkışta 0 V görünür.
- Giriş pozitifken (1, 2, 5, 10 V) B ucu anottan hep yüksek kalır, diyot açık devredir. Dirençten akım akmadığı için çıkış girişi aynen izler: $v_o = v_i$.
- Giriş negatife geçtikten sonra da −3 V'a kadar diyot kesimde kalır ve çıkış girişi izlemeye devam eder.
- B ucu −3 V'un biraz altına indiğinde (örneğin −3,001 V) $V_B < V_A$ olur, diyot iletir ve kısa devre olur. Çıkışta kaynağın gerilimi, yani −3 V görünür. Giriş −3 V'un altında kaldığı sürece çıkış −3 V'ta sabit kalır.

Sonuçta çıkış, girişin −3 V'un altında kalan kısmı kırpılmış bir sinüstür.

> **Ders sonrası not:** Hoca çizimin ilk halinde pozitif yarı periyotta çıkışı 0 olarak çizdi; ardından bunu kendisi fark edip düzeltti (01:29:58). Doğrusu yukarıdaki gibidir: diyot kesimdeyken çıkış girişi izler, yalnız −3 V'un altı kırpılır.

> **Ek bilgi (derste anlatılmadı):** Bu devrenin çıkışı tek ifadeyle $v_o = \max(v_i,\ -3)$ olarak yazılabilir. Python ile $v_i = 10\sin(\omega t)$ için kontrol edildiğinde çıkış 10 V ile −3 V arasında kalır.

## 6. Kenetleyici (Clamper) Devreler

### 6.1 Clamp kelimesi ve kapasitörün rolü

Kırpıcılardan sonra kapasitörün kullanıldığı kenetleyicilere geçildi. Hoca "clamp" kelimesini masa üstünde bir parçayı işlemek için sıkıştırdığımız kıskaçlarla açıkladı: clamp, bir şeyi sıkıştırmak anlamındadır. Bu devrelerde kapasitörün depolama yeteneğinden yararlanılır: devreden akım geçtiği (diyot iletimde olduğu) zaman kapasitör dolar, akım geçmediği zaman ise boşalır.

### 6.2 Kare dalga girişli temel kenetleyici

Özet slaytındaki ilk devrede giriş $\pm V$ genlikli bir kare dalgadır; kapasitör seri, diyot ve direnç çıkışa paraleldir (ekrandan, 01:35:00).

- Pozitif yarıda diyot iletir ve kısa devre olur. Çıkış uçları arasında kısa devre olduğu için çıkış 0'dır.
- Negatif yarıda diyot iletmez. Negatif gerilimler oluştukça çıkış iki katına çıkar ve $-2V$ olur.

Hoca bunun ideal bir gösterim olduğunu belirtti. Gerçekte kapasitör yavaş yavaş boşaldığı için çıkış düz kalmaz, azalır. Kapasitör çok büyükse çıkış düz kabul edilir ve slaytta da öyle gösterilmiştir.

Özet slaytında diyotun yönü ve diyota seri eklenen $V_1$ kaynağıyla oluşan altı kenetleyici vardır. Hepsinde çıkış $2V$ tepe-tepe genlikli kare dalgadır; yalnız seviyesi değişir: 0 ile $-2V$ arası, 0 ile $2V$ arası, $V_1$ ya da $-V_1$ seviyesine dayanan kare dalgalar (ekrandan, 01:35:00). Hoca kenetleyicilerin çalışma mantığının da bu devreler çizilerek simülasyonla incelenmesini istedi.

> **Ek bilgi (derste anlatılmadı):** Kenetleyicide çıkışın düz kalması için devrenin zaman sabiti $\tau = RC$'nin giriş periyoduna göre çok büyük olması gerekir; Boylestad bu koşulu büyük olasılıkla $5\tau \gg T/2$ biçiminde verir. Kapasitörde biriken gerilim girişe eklendiği için çıkıştaki tepe-tepe genlik girişinkiyle aynı kalır, yalnız DC seviye kayar.

## 7. Zener Diyot Devreleri

### 7.1 Zener'in çalışması

Hoca Zener diyotun ters yönde çalıştığını hatırlattı. Normal bir diyot ters yönde belli bir $V_Z$ geriliminde kırılır ve akım akıtmaya başlar. Çeşitli katkı (doping) malzemeleriyle bu $V_Z$ değeri sağa sola kaydırılır ve diyot belirli gerilimlerde iletim yapabilecek hale getirilir. Zener devreye ters bağlanır; böylece pozitif gerilimlerde belli bir değere, $V_Z$'ye ulaşınca iletir.

$V_Z = 5$ V'luk bir Zener ele alındı:

- Uçlarındaki gerilim 5 V'tan küçükse Zener "off" durumundadır ve açık devre gibi davranır.
- Gerilim 5 V'a ulaşınca Zener "on" olur, akım akıtır ve uçlarında 5 V'luk bir gerilim kaynağı varmış gibi 5 V'ta sabit kalır; bunun üzerine çıkmaz.

Hoca bunun bir çeşit çıkış gerilimi koruması olduğunu söyledi.

### 7.2 Slayttaki bağıntılar ve koruma örneği

Slayttaki devrede (ekrandan, 01:45:00) $V_i$ kaynağı, seri $R$ direnci, ters bağlı Zener ($V_Z$) ve Zener'e paralel $R_L$ yük direnci vardır. Slayttaki bağıntılar:

- Zener on iken: $V_L = V_Z$, Zener akımı $I_Z = I_R - I_{R_L}$, Zener gücü $P_Z = V_Z I_Z$. $P_{ZM}$, Zener'in dayanabileceği en büyük güçtür.
- Zener'e uygulanan gerilim $V_Z$'den küçükken: Zener off'tur ve açık devre gibi davranır.

Hoca örneği şöyle anlattı:

- Girişe 1 V uygulanırsa Zener'in uçlarına gelecek gerilim en fazla 1 V olur; direnç üzerine de gerilim düşüyorsa 1 V'un altında kalır. Zener off durumundadır ve açık devre gibidir.
- Girişe 10 V uygulanırsa Zener iletime geçer ve 5 V'ta sabit kalır.
- Giriş 20 V, 30 V olsa bile $V_A$ ucundaki gerilim 5 V'ta kalır. 30 V girişte 5 V Zener'e, kalan 25 V seri dirence düşer.

$R_L$ yükü Zener'e paralel olduğu için ($V_A$ ile toprak arası) yüke en fazla $V_Z$ kadar gerilim geldiği garanti edilir. Hoca bu yüzden Zener diyotların koruma elemanı olarak çok kullanıldığını söyledi.

> **Ek bilgi (derste anlatılmadı):** Zener'in on olup olmadığına karar verirken asıl bakılan, Zener çıkarıldığında uçlarında oluşacak gerilimdir: $V = \dfrac{R_L}{R + R_L} V_i$. $V \ge V_Z$ ise Zener on'dur. Hocanın derste "Zener'e uygulanan gerilim" dediği büyük olasılıkla bu gerilimdir; $R_L$ çok büyükse $V \approx V_i$ olur.

## 8. Gerilim Çoklayıcılar

Son olarak hoca slaytlardaki gerilim çoklayıcı devreleri gösterdi: gerilim ikileyici, üçleyici ve dörtleyici devreler. Bunlar devrenin gerilimini katlayan devrelerdir ve slaytlarda transformatörle birlikte kullanılmıştır. Hoca bu konuya çok fazla girilmeyeceğini söyledi.

## Örnek Sorular

### Soru 1: DC kaynaklı seri kırpıcı

(ekrandan, 00:15:00 ve 00:30:00)

Seri kırpıcıda giriş ile diyot arasına artı ucu diyota bakan $V = 5$ V'luk kaynak bağlanmıştır. Giriş $v_i$, tepe değeri 20 V olan bir sinüstür. Diyot idealdir. $v_o$'yu çizin.

**Çözüm (derste verildi):**

- Diyot iletimdeyken $v_o = v_i + 5$ V'tur.
- $v_i = 0$ iken $v_o = 0 + 5 = 5$ V; $v_i = 20$ V iken $v_o = 20 + 5 = 25$ V; $v_i = -1$ V iken $v_o = 4$ V.
- Geçiş gerilimi $v_i = -5$ V'tur: $v_o = -5 + 5 = 0$ V.
- $v_i < -5$ V iken diyot açık devredir, $v_o = 0$.
- Çıkış, girişin 5 V yukarı ötelenmiş ve 0'ın altı kesilmiş halidir.

### Soru 2: Ters kaynaklı ve ters diyotlu seri kırpıcı

(ekrandan, 00:55:00 ve 01:15:00)

Girişte ±10 V tepeli sinüs, ardından ters bağlı −5 V'luk DC kaynak ve katodu kaynağa bakan ideal bir diyot vardır; çıkış toprağa bağlı $R$ üzerinden alınır. $v_o$'yu çizin. (Hoca bu sorunun daha önce sınavda sorulduğunu söyledi.)

**Çözüm (derste verildi):**

- $v_i = 0$: diyot iletir, $v_o = -5$ V.
- $0 < v_i < 5$ V: diyot iletir, $v_o = v_i - 5$ (1 V → −4 V, 2 V → −3 V, 3 V → −2 V).
- $v_i \ge 5$ V: diyot kesimde, $v_o = 0$.
- Giriş 5 V'un altına inince diyot tekrar iletir; $v_i = -10$ V iken $v_o = -15$ V.
- Çıkış 0 ile −15 V arasında kalır.

### Soru 3: DC kaynaklı paralel kırpıcı

(ekrandan, 01:25:00)

Paralel kırpıcıda çıkışa paralel kolda katodu çıkışa bakan ideal diyot ve ters bağlı (anodu −3 V'ta tutan) 3 V'luk kaynak vardır. Giriş ±10 V tepeli sinüstür. $v_o$'yu çizin.

**Çözüm (derste verildi):**

- $v_i > -3$ V: diyot kesimde, dirençten akım akmaz, $v_o = v_i$.
- $v_i < -3$ V: diyot iletir, $v_o = -3$ V.
- Çıkış 10 V ile −3 V arasında kalır; girişin −3 V'un altı kırpılır.

### Soru 4: Basit paralel kırpıcı

(ekrandan, 00:40:00)

Paralel kırpıcıda (diyot çıkışa paralel, anodu çıkışa bakar) giriş $\pm V$ genlikli kare dalga ve üçgen dalgadır. Çıkışları çizin.

**Çözüm (derste verildi):** Pozitif kısımda diyot iletir ve $V_D = V_B - V_T = 0$ olduğu için $v_o = 0$'dır. Negatif kısımda diyot açık devredir, dirençten akım akmaz ve $v_o = v_i$'dir. Kare dalgada çıkış 0 ile $-V$ arasında, üçgen dalgada yalnız negatif üçgen görünür.

### Soru 5: Kare dalgalı kenetleyici

(ekrandan, 01:35:00)

Seri kapasitör, çıkışa paralel ideal diyot ve $R$ direncinden oluşan kenetleyiciye $\pm V$ genlikli kare dalga uygulanmıştır. Kapasitör çok büyüktür. Çıkışı çizin.

**Çözüm (derste verildi):** Pozitif yarıda diyot kısa devredir, $v_o = 0$. Negatif yarıda diyot iletmez ve çıkış $-2V$ olur. Çıkış 0 ile $-2V$ arasında, $2V$ tepe-tepe genlikli bir kare dalgadır.

### Soru 6: Zener ile yük koruması

(ekrandan, 01:45:00; derste sözlü, 01:44:19)

$V_Z = 5$ V'luk Zener ve ona paralel $R_L$ yükü, seri bir $R$ direnci üzerinden $V_i$ kaynağıyla beslenmektedir. $V_i = 1$ V ve $V_i = 30$ V için yük gerilimini ve seri dirence düşen gerilimi bulun.

**Çözüm (derste verildi):**

- $V_i = 1$ V: Zener off ve açık devredir; yüke en fazla 1 V gelir.
- $V_i = 30$ V: Zener on'dur; $V_L = V_Z = 5$ V, seri dirençte $V_R = 30 - 5 = 25$ V.

### Soru 7: Kırpıcıların simülasyonu (ödevin akademik içeriği)

(ekrandan, 00:45:00 ve 01:30:00; derste sözlü, 00:44:38)

Özet slaytlarındaki seri ve paralel kırpıcı devrelerini simülasyon programında sinüs (ve kare dalga) girişle kurun. Girişi ve direnç üzerindeki çıkışı osiloskopla birlikte çizdirin ve her devrenin çıkışının nasıl oluştuğunu açıklayın. Kenetleyici özet slaytındaki devreleri de aynı şekilde simüle edin.

> **Çözüm (derste verilmedi):** Çözüm her devre için yukarıdaki adım adım yöntemle bulunur: diyotun iletim ve kesim aralıkları belirlenir, iletimde diyot kısa devre, kesimde açık devre alınır. Beklenen çıkışlar slaytlardaki dalga şekilleridir (örneğin DC kaynaklı seri kırpıcıda $-(V_m+V)$ ya da $(V_m+V)$ tepeleri, DC kaynaklı paralel kırpıcıda $V$ ya da $-V$ seviyesinde kırpma).

## Dersin Toparlaması

Bu derste diyotun doğrultma dışındaki dalga şekillendirme uygulamaları işlendi. Seri kırpıcıda diyot kendisini ileri kutuplamayan gerilimi, paralel kırpıcıda ise ileri kutuplayan gerilimi keser. Diyota seri eklenen bir DC kaynak, kırpma seviyesini kaydırır ve seri kırpıcıda çıkışı yukarı ya da aşağı öteler. Bütün bu devrelerin çıkışı aynı yöntemle çizilir: önce sıfır ve tepe noktaları, sonra diyotun iletimden kesime geçtiği geçiş gerilimi bulunur; iletimde diyot kısa devre, kesimde açık devre alınır. Akım akmayan bir dirençte gerilim düşmediği için diyot kesimdeyken paralel kırpıcının çıkışı girişi aynen izler.

Kenetleyicilerde kapasitör, diyot iletirken dolup sonra yükünü koruyarak işaretin şeklini bozmadan DC seviyesini kaydırır. Zener diyot ise ters yönde $V_Z$ değerine ulaşınca sabit gerilimli bir kaynak gibi davranarak paralel bağlı yükü aşırı gerilime karşı korur. Gerilim çoklayıcılar yalnız tanıtıldı. Hoca Zener devreleriyle ilgili soruların çözüldükçe daha iyi anlaşılacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
