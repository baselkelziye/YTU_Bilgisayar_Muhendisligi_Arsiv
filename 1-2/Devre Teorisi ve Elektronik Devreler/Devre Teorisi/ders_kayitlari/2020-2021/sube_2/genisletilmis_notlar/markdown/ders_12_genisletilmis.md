# Ders 12 Genişletilmiş Notu: Empedans ve Admitans: AC Devre Analizi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. AC Devrelerde Ohm Kanunu
- 2. Kondansatörde Faz Kayması ve Empedans
- 3. Bobinde Faz Kayması ve Empedans
- 4. Empedansın Tanımı ve Fazör Biçimi
- 5. Admitans
- 6. Empedanslarla KVL, KCL ve Eşdeğer Devreler
- 7. Örnek 03: Seri RL Devresi
- 8. Örnek 04: Paralel Devrede Admitans
- 9. Thevenin, Norton ve Kaynak Dönüşümü
- 10. Örnek 05: Kaynak Dönüşümüyle Thevenin Gerilimi
- 11. Gerilim ve Akım Bölücü
- 12. Önceki Haftadan Örnek 02: Paralel RLC'de KCL
- Örnek Sorular
- Dersin Toparlaması

## 1. AC Devrelerde Ohm Kanunu

Dersin amacı empedans kavramını ayrıntılı incelemektir: empedansın ne olduğu, Ohm kanunu çerçevesinde nasıl kullanıldığı, KVL ve KCL'nin, Thevenin ve Norton eşdeğerlerinin empedanslarla nasıl uygulandığı. Önceki dersin sonunda empedansa kısaca değinilmişti.

Ohm kanunu $V = IR$ biçimindedir ve gerilimin akım ile dirence bağlı olduğunu söyler. Bu yazımda $V$ ve $I$ büyük harfle gösterilir; büyük harf DC büyüklükleri, yani zamana göre değişmeyen gerilim ve akımı belirtir. Alternatif akım ve gerilim ise zaman domeninde değişen, sinüs, kosinüs ya da bunların birleşiminden oluşan zamana bağlı (time variant) sinyallerdir. AC analizde gerilim ve akım küçük harfle, zaman parametresiyle birlikte yazılır: $v(t)$, $i(t)$.

Direnç için slayttaki ifade şöyledir (ekrandan, 00:10:00):

$$v(t) = R\,i(t) = R I_m\cos(\omega t + \theta)$$

$$\mathbf{V} = R I_m\angle\theta = R\mathbf{I}, \qquad \theta = \phi$$

Burada $I_m$ akımın tepe (maksimum) değeridir. $\cos(\omega t + \theta)$ çarpanı, belirli bir $t$ anında bu tepe değerin ne kadarının görüldüğünü verir. Örneğin $\pm 5$ A arasında salınan bir akımın belli bir andaki değeri, 5 ile o andaki kosinüs değerinin çarpımıdır.

Fazör gösterime geçmenin amacı, ifadedeki $t$ değişkeninden kurtulmaktır. Fazörde yalnız genlik ve faz açısı kalır. Dirençli bir devrede gerilim ve akım aynı fazdadır; aralarında açı farkı oluşmaz. Bu yüzden yalnız direnç içeren bir AC devrede akım fazöre çevrilip $R$ ile çarpılır, gerilim fazörü elde edilir; gerekirse ters dönüşümle yeniden kosinüslü biçime geçilip sinyal çizilir.

## 2. Kondansatörde Faz Kayması ve Empedans

### 2.1 Neden ek bir işlem gerekir?

Devrede kondansatör ya da bobin varsa durum değişir. Bu elemanlar enerji depoladıkları için gerilim ile akım arasında faz kayması oluştururlar. Bu kaymayı hesaba katmadan dirençteki gibi doğrudan işlem yapılamaz.

Kondansatör akımı $i = C\,dv/dt$ ile verilir. Devreyi $v(t) = V_m\cos\omega t$ geriliminin beslediğini düşünelim. Türev alınınca (ekrandan, 00:15:00):

$$i(t) = C\frac{dv(t)}{dt} = -C\omega V_m\sin(\omega t)$$

$C$ zamana bağlı olmadığı için türevin dışına çıkar; kosinüsün içindeki $\omega$ katsayısı da dışarı gelir. Sonuçta akım, verilen gerilimden farklı biçimde bir sinyale dönüşmüştür.

### 2.2 Aynı frekans şartı

İki sinyali karşılaştırmanın ilk şartı frekanslarının aynı olmasıdır, yani içlerindeki $\omega t$ terimlerinin eşit olması. Hoca örnek olarak $\sin(2\pi\cdot 50\,t)$ ile $\cos(2\pi\cdot 125\,t)$ sinyallerini verdi: frekansları farklı olduğu için bu ikisi aynı domende karşılaştırılamaz. Kondansatör sinyalin frekansını değiştirmez; sinyal kondansatör yüzünden "daha sık" hale gelmez. Etkisi yalnız fazdadır.

### 2.3 Kosinüs biçimine getirme

İkinci şart iki sinyalin aynı biçimde (ikisi de pozitif kosinüs) yazılmasıdır. Önce eksi işaret $180^\circ$ eklenerek kaldırılır, sonra sinüs $90^\circ$ çıkarılarak kosinüse çevrilir (ekrandan, 00:15:00):

$$i(t) = \omega C V_m\sin(\omega t + 180^\circ) = \omega C V_m\cos(\omega t + 180^\circ - 90^\circ) = \omega C V_m\cos(\omega t + 90^\circ)$$

Şimdi gerilim $V_m\cos\omega t$, akım $\omega C V_m\cos(\omega t + 90^\circ)$ biçimindedir. İkisi de pozitif kosinüs olduğu için karşılaştırılabilir: kondansatörde akım gerilimden $90^\circ$ öndedir. Dirençli devrede bu fark olmadığı için doğrudan işlem yapılabiliyordu; kondansatörde ise bir ön işlem gerekir. Bu ön işleme empedans dönüşümü denir.

### 2.4 Fazörde kondansatör empedansı

Kosinüslü ifadeler fazöre çevrilirken genlik aynen kalır, açı kosinüsün içindeki faz olur. $V_m\cos\omega t$ için $\mathbf{V} = V_m\angle 0^\circ$, $V_m\cos(\omega t + 90^\circ)$ için ise $V_m\angle 90^\circ$ yazılır. Slayttaki zincir şöyledir (ekrandan, 00:20:00):

$$\mathbf{V} = V_m\angle 0^\circ, \qquad \mathbf{I} = \omega C V_m\cos(\omega t + 90^\circ)$$

$$V_m\cos(\omega t + 90^\circ) = \mathbf{V}e^{j90^\circ} = \mathbf{V}\angle 90^\circ = j\mathbf{V}$$

$$\mathbf{I} = j\omega C\mathbf{V} \quad\text{ya da}\quad \mathbf{V} = \frac{1}{j\omega C}\mathbf{I} = -\frac{j}{\omega C}\mathbf{I}$$

Burada $C$ kondansatörün farad cinsinden değeri, $\mathbf{V}$ besleme geriliminin fazörüdür. Artık akım ve gerilim arasında ayrıca $90^\circ$ farktan söz edilmez, çünkü bu fark $j$ çarpanının içine alınmıştır; akım ve gerilim "aynı dilden" konuşur.

Dirençli devrede direnç $V/I$ ile bulunuyordu. Kondansatör için de aynı oran alınırsa $1/(j\omega C)$ elde edilir (ekrandan, 00:25:00). Bu, kondansatörün AC devredeki katkısını gösteren parametredir: kondansatörün empedansı. Hedef, $t$'ye ya da faz farkına bağlı kalmadan devrenin eşdeğer "direncini" bulabilmektir.

$1/(j\omega C)$ ifadesi genelde $-j/(\omega C)$ biçiminde yazılır; çünkü $1/j = -j$'dir. İkisi aynı şeydir. $j$ çarpanı $90^\circ$'lik faz farkını, $\omega = 2\pi f$ frekans bilgisini, $C$ de kondansatörün değerini denkleme katar.

> **Ek bilgi (derste anlatılmadı):** $j = \sqrt{-1}$ olduğundan $j\cdot j = -1$ ve $1/j = j/(j\cdot j) = -j$ olur. Bu yüzden $1/(j\omega C) = -j/(\omega C)$ eşitliği yalnız bir yeniden yazımdır.

## 3. Bobinde Faz Kayması ve Empedans

Bobinde akım üzerinden gidilir. Bobine $i(t) = I_m\cos\omega t$ akımı verildiğini düşünelim. Gerilim $v = L\,di/dt$ ile bulunur; türev alınınca kondansatördekine benzer biçimde $90^\circ$'lik bir fark çıkar. Bu fark, bobinde gerilimin akımdan $90^\circ$ önde olduğunu söyler.

Bu sonuç formüle dökülünce bobinin empedansı $j\omega L$ olur. Kondansatörde gerilim üzerinden gidildiği için $\mathbf{I} = j\omega C\mathbf{V}$ yazılmıştı; bobin için akım üzerinden gidilince $\mathbf{V} = j\omega L\,\mathbf{I}$ elde edilir. Hesaplarda bobin için $j\omega L$, kondansatör için $-j/(\omega C)$ kullanılır.

## 4. Empedansın Tanımı ve Fazör Biçimi

### 4.1 Tanım

Empedans, alternatif akım ya da gerilim bulunan devrelerde, DC devrelerdeki eşdeğer direncin gördüğü işi gören parametredir. Ona tam olarak "direnç" demek doğru değildir, ama bobin ve kondansatör içeren devrelerde direncin rolünü üstlenir. $Z$ ile gösterilir ve Ohm kanunu şu biçimi alır:

$$\mathbf{V} = \mathbf{I}\mathbf{Z}$$

Z domenine geçilmesinin nedeni, bobin ve kondansatörde oluşan zamana bağlı faz kaymasının katkısını formüle edebilmektir. Bir DC devrede akım bulunacaksa önce eşdeğer direnç hesaplanır. AC devrede de önce empedans bulunur: devrede direnç, bobin ve kondansatör varsa her biri fazör biçimine getirilir, sonra $\mathbf{V}/\mathbf{Z}$ ile devrenin ana akımı bulunur.

### 4.2 Temel elemanların empedansı

- Direnç: $Z_R = R = R\angle 0^\circ$. Saf gerçel bir sayının fazör genliği $\sqrt{R^2} = R$, açısı $0^\circ$'dir.
- Bobin: $Z_L = j\omega L = \omega L\angle 90^\circ$.
- Kondansatör: $Z_C = -j/(\omega C) = (1/\omega C)\angle -90^\circ$.

> **Ders sonrası not:** Hoca direncin fazör açısını anlatırken arktanjanttan "1 gelir" dedi (00:28:25). Doğrusu, sanal kısım sıfır olduğu için $\tan^{-1}(0/R) = 0^\circ$'dir; slayttaki $R\angle 0^\circ$ ifadesi de bunu gösterir.

### 4.3 $\pm 90^\circ$ açıları nereden gelir?

Hoca bunu bir öğrenciye sordu ve karmaşık düzlem üzerinden açıkladı. Kartezyen düzlemde yatay eksen gerçel kısım (pozitif ve negatif reel), dikey eksen sanal kısımdır; yukarı $+j$, aşağı $-j$ yönüdür. $+j$ noktası $90^\circ$, $-j$ noktası $-90^\circ$ açısındadır.

Dik (rectangular) biçimdeki $a + jb$ sayısı fazöre çevrilirken genlik $\sqrt{a^2 + b^2}$, açı $\tan^{-1}(b/a)$ olur. Kondansatörde $a = 0$, $b = -1/(\omega C)$'dir; gerçel kısım olmadığı için açı doğrudan $b$'nin işaretinden $-90^\circ$ gelir. Bobinde $b = \omega L > 0$ olduğu için açı $+90^\circ$'dir.

### 4.4 Genel bileşen

Empedans, direnç, bobin ya da kondansatörü temsil edebilen genel bir bileşendir. Slayttaki bağıntılar (ekrandan, 00:35:00):

$$\mathbf{Z} = |Z|\angle\phi, \qquad \mathbf{Z} = R + jX$$

$$|Z| = \sqrt{R^2 + X^2}, \qquad \phi = \tan^{-1}(X/R)$$

$$R = |Z|\cos\phi, \qquad X = |Z|\sin\phi$$

$R$ gerçel kısmı devredeki dirençlerden gelir. $X$ sanal kısmı ise bobin ve kondansatörlerin ortak katkısıdır; ikisinde de $j$ bulunduğu için açısal farkı bu elemanların dinamikleri oluşturur. $Z_R$, $Z_L$ ve $Z_C$ toplanınca genel empedans elde edilir: gerçel kısım dirençten, sanal kısım $j$ ortak parantezinde $\omega L$ ve $-1/(\omega C)$ terimlerinden oluşur. Bunu fazör biçimine çevirmek devrenin eşdeğer empedansını hesaplamak demektir.

Ters yönde, fazör biçimden dik biçime de geçilebilir: bir soruda yalnız direnç kısmı istenirse $R = |Z|\cos\phi$, sanal kısım istenirse $X = |Z|\sin\phi$ kullanılır.

> **Ders sonrası not:** Hoca açı formülünü birkaç kez "eksi arktanjant" diye okudu (00:35:38, 00:53:46). Slayttaki ve doğru ifade $\phi = \tan^{-1}(X/R)$, yani $\tan^{-1}(b/a)$'dır; derste çözülen örneklerin sayısal sonuçları da bu ifadeyle uyumludur.

## 5. Admitans

Empedansın tersine admitans denir. Daha önce dirence (resistance) karşılık iletkenlik (conductance) tanımlanmıştı; admitans da empedansa karşılık gelen aynı fikirdir. Slayttaki tanım (ekrandan, 00:30:00):

$$\mathbf{I} = \mathbf{Y}\mathbf{V}, \qquad \mathbf{Y} = 1/\mathbf{Z}$$

- Direnç: $Y_R = 1/R = G$, fazörde $G\angle 0^\circ$.
- Kondansatör: $Y_C = j\omega C$, fazörde $\omega C\angle 90^\circ$.
- Bobin: $Y_L = -j/(\omega L)$, fazörde $(1/\omega L)\angle -90^\circ$.

Admitansta kondansatör ve bobinin rolleri yer değiştirir: kondansatörün admitansı bobinin empedansına benzer ($j$'li), bobininki kondansatörün empedansına benzer ($-j$'li); açılar da tersine döner. Genel olarak $Z = R + jX$ iken $Y = 1/(R + jX)$ olur. Admitansın birimi $\Omega^{-1}$'dir.

Sorularda genelde empedans istenir. Admitans, empedans hesabının zor olduğu durumlarda kullanılır: önce admitans bulunur, sonra tersi alınarak empedansa geçilir.

Empedans bulunduktan sonra bütün işlemler Ohm kanunudur: akım verilmişse $\mathbf{V} = \mathbf{I}\mathbf{Z}$, gerilim verilmişse $\mathbf{I} = \mathbf{V}/\mathbf{Z}$. Admitansla ise $\mathbf{V} = \mathbf{I}/\mathbf{Y}$ ve $\mathbf{I} = \mathbf{V}\mathbf{Y}$ yazılır.

## 6. Empedanslarla KVL, KCL ve Eşdeğer Devreler

### 6.1 Seri bağlantı ve KVL

İki devre elemanını "kara kutu" gibi düşünelim; bobin, kondansatör ya da direnç olması fark etmez. Empedansa çevrildikten sonra hepsi aynı biçimde işlenir. Örneğin bir kondansatör empedansa çevrilince $j$'li bir sayı çıkar; bu sayı $\omega = 2\pi f$'ye, yani frekansa bağlıdır.

Slayttaki seri devre (ekrandan, 00:40:00): $V_s$ kaynağına seri bağlı $Z_1$ ve $Z_2$, üzerlerinde $V_1$ ve $V_2$ gerilimleri.

$$V_1 + V_2 - V_s = 0$$

Seri bağlı elemanlardan aynı akım geçer. Ohm kanunuyla $V_1 = IZ_1$, $V_2 = IZ_2$. KVL'de yerine konunca:

$$IZ_1 + IZ_2 - V_s = 0 \quad\Rightarrow\quad I(Z_1 + Z_2) = V_s$$

Kabul edilen bütün kurallar, empedansa geçtikten sonra DC devredeki gibi uygulanır. $V_1$ ve $V_2$ ayrı ayrı bulunabileceği gibi, $Z_1$ ile $Z_2$ toplanıp ana kol akımı da bulunabilir.

### 6.2 Paralel bağlantı ve KCL

KCL'ye göre düğüme gelen akım dallara bölünür: $I_s = I_1 + I_2$. Paralel iki empedans, dirençlerdeki gibi ters toplamla birleştirilir. Paralel elemanlarda gerilim aynı olduğu için $I_1 = V/Z_1$, $I_2 = V/Z_2$ yazılır.

Admitans kullanılırsa her şey tersine döner, iletkenlikte olduğu gibi:

- Seri admitanslar: $1/Y_{eq} = 1/Y_1 + 1/Y_2$.
- Paralel admitanslar: $Y_{eq} = Y_1 + Y_2$.

> **Hocanın vurgusu:** DC dirençli devrelerde hangi kurallar uygulanıyorsa, bobin ve kondansatör empedansa çevrildikten sonra aynı kurallar doğrudan uygulanır. Empedans işleri çok kolaylaştıran bir dönüşümdür.

## 7. Örnek 03: Seri RL Devresi

### 7.1 Kaynağın yorumu

Giriş gerilimi $v_s = 12\sin(100t + 30^\circ)$ V'tur. Bu, genliği 12 V olan bir sinüs dalgasıdır. İçerideki 100 değeri $\omega$'dır ve $\omega = 2\pi f$ olduğundan frekans $f = 100/(2\pi) \approx 15{,}9$ Hz olur. Sinyal ayrıca $30^\circ$ kaydırılmıştır.

> **Ders sonrası not:** Hoca frekansı önce "20 Hz gibi", sonra "16 Hz gibi" diye tahmin etti; hesap $f = 100/(2\pi) \approx 15{,}9$ Hz verir. Hoca sinyali "tepeden tepeye 12 V" diye niteledi; 12 V tepe (genlik) değeridir, tepeden tepeye değer 24 V'tur.

### 7.2 Eşdeğer empedans

Devrede seri bağlı $R = 10\ \Omega$ ve $L = 10$ mH vardır. "10 artı 10 eşittir 20" denemez; biri ohm, öteki milihenry cinsindendir, farklı domenlerdedir. İkisi de empedansa çevrilince ohm olur ve toplanabilir (ekrandan, 00:45:00):

$$Z_R = 10\ \Omega$$

$$Z_L = j\omega L = j(100)(10\text{ mH}) = j1\ \Omega$$

$$Z_{eq} = Z_R + Z_L = 10 + j1\ \Omega \quad\text{(dik koordinatlar)}$$

Fazör biçimine geçilir, çünkü sonra bir bölme yapılacaktır ve fazörde bölme, genliklerin bölünmesi ve açıların çıkarılmasıyla kolayca yapılır:

$$Z_{eq} = (Z_R^2 + Z_L^2)^{1/2}\angle\tan^{-1}(\text{Im}/\text{Re}) = (100 + 1)^{1/2}\angle\tan^{-1}(1/10) = 10{,}05\angle 5{,}7^\circ\ \Omega$$

Slaytta bu değer yuvarlanarak $10{,}1\angle 5{,}7^\circ\ \Omega$ diye de yazılmıştır.

> **Hocanın vurgusu:** Seri bağlı elemanları birleştirirken empedans kullanmak admitanstan kolaydır; admitansla seri birleştirme ters toplam gerektirirdi.

### 7.3 Kaynağı fazöre çevirme

Fazöre kosinüsten geçmek daha kolaydır. Sinüsü kosinüse çevirmek için açıdan $90^\circ$ çıkarılır:

$$12\sin(100t + 30^\circ) = 12\cos(100t + 30^\circ - 90^\circ) = 12\cos(100t - 60^\circ)\ \text{V}$$

$$\mathbf{V} = 12\angle -60^\circ\ \text{V}$$

### 7.4 Akım

$$\mathbf{I} = \frac{\mathbf{V}}{Z_{eq}} = \frac{12\angle -60^\circ}{10{,}05\angle 5{,}7^\circ} = 1{,}19\angle -65{,}7^\circ\ \text{A}$$

Genlik $12/10{,}05$, açı $-60^\circ - 5{,}7^\circ$ olarak bulunur. Aynı sonuç üstel biçimde de yazılabilir (ekrandan, 00:50:00):

$$\mathbf{I} = 1{,}19\,e^{-j65{,}7^\circ}\ \text{A}, \qquad \mathbf{V} = 12\,e^{-j60^\circ}\ \text{V}$$

### 7.5 Öncelik ve gecikme

Devrede direncin yanında bobin ya da kondansatör varsa gerilim ile akım arasında mutlaka bir kayma olur. Kaymanın miktarı eşdeğer empedansa bağlıdır. Yalnız direnç varsa kayma olmaz, çünkü direnç yalnız gerçel kısmı olan bir elemandır.

Karşılaştırmada genlikler önemli değildir, açılara bakılır. Açısı daha pozitif olan sinyal öndedir. Burada gerilim $-60^\circ$, akım $-65{,}7^\circ$'dir. Gerilim daha pozitif olduğu için gerilim akımdan $5{,}7^\circ$ öndedir. Slayttaki ifade: "The voltage has a more positive angle, voltage leads the current." (ekrandan, 00:50:00)

## 8. Örnek 04: Paralel Devrede Admitans

### 8.1 Devre

Slayttaki devrede (ekrandan, 00:55:00) $i_1 = 4\cos(300t - 10^\circ)$ A akım kaynağına paralel $R = 1\ \Omega$, $C = 1$ mF ve $L = 1$ H bağlıdır. Kaynak kosinüs biçiminde olduğu için fazörü doğrudan $\mathbf{I} = 4\angle -10^\circ$ A'dır; $\omega = 300$ rad/s.

> **Ders sonrası not:** Hoca açıyı önce yanlış okudu, bir öğrencinin uyarısıyla "eksi 10" olarak düzeltti (00:51:39).

### 8.2 Neden admitans?

Elemanlar paralel olduğu için empedansla gidilirse $1/\big(1/R + 1/(-j/\omega C) + 1/(j\omega L)\big)$ gibi paydaları eşitlemek, $j$'lerden kurtulmak gerektiren uzun bir işlem çıkar. Paralel admitanslar ise doğrudan toplanır.

$$Y_R = 1/R = 1\ \Omega^{-1}$$

$$Y_C = j\omega C = j(300)(10^{-3}) = j0{,}3\ \Omega^{-1}$$

$$Y_L = -j/(\omega L) = -j/300 = -j3{,}33\ \text{m}\Omega^{-1}$$

$$Y_{eq} = 1 + j0{,}3 - j0{,}00333 = 1 + j0{,}297\ \Omega^{-1}$$

### 8.3 Fazör biçimi ve empedans

Slayttaki hesap (ekrandan, 00:55:00):

$$Y_{eq} = (Y_{Re}^2 + Y_{Im}^2)^{1/2}\angle\tan^{-1}(\text{Im}/\text{Re}) = (1^2 + 0{,}297^2)^{1/2}\angle\tan^{-1}(0{,}297/1) = 1{,}04\angle 16{,}5^\circ\ \Omega^{-1}$$

$$Z_{eq} = Y_{eq}^{-1} = \frac{1}{1{,}04}\angle(0 - 16{,}5^\circ)\ \Omega = 0{,}959\angle -16{,}5^\circ\ \Omega$$

Tersini almak genliğin tersini almak ve açının işaretini değiştirmektir.

> **Hocanın vurgusu:** Paralel yapılarda genelde admitanstan yürünür, sonra tersi alınarak empedansa geçilir.

### 8.4 Gerilim ve öncelik

Soru metninde ne istendiği slaytta görünmüyordu; hoca büyük olasılıkla gerilimin sorulduğunu söyleyerek devam etti.

$$\mathbf{V} = \mathbf{I}Z_{eq} = (4\angle -10^\circ)(0{,}959\angle -16{,}5^\circ) = 3{,}84\angle -26{,}5^\circ\ \text{V}$$

Genlikler çarpılır ($4\times 0{,}959$), açılar toplanır ($-10^\circ - 16{,}5^\circ$). Admitansla $\mathbf{V} = \mathbf{I}/\mathbf{Y}$ yazılsa da aynı sonuç çıkar.

Akım $-10^\circ$, gerilim $-26{,}5^\circ$ açısındadır. Akım pozitife daha yakın olduğu için bu soruda akım gerilimden öndedir.

> **Ek bilgi (derste anlatılmadı):** Bu devrede kondansatörün admitansı ($j0{,}3$) bobininkinden ($-j0{,}0033$) çok büyük olduğu için eşdeğer admitansın sanal kısmı pozitif, devre kapasitif davranır. Kapasitif devrelerde akımın gerilimden önde olması bu yüzdendir; Örnek 03'teki RL devresi ise endüktiftir ve orada gerilim öndedir.

## 9. Thevenin, Norton ve Kaynak Dönüşümü

DC analizde Thevenin ve Norton eşdeğerlerinin fikri şuydu: bir yük direnci var, bu yüke gelen akımı üreten devre bir "kara kutu"dur ve içinde birçok eleman olabilir. İçine bakmadan, bu kara kutu tek bir gerilim kaynağı ve tek bir dirençle gösterilir; bu basit devrenin yükte oluşturduğu akım, karmaşık devreninkiyle aynıdır. Gerilim kaynağı Thevenin gerilimi, akım Norton akımı, direnç de Thevenin ya da Norton eşdeğer direncidir. Thevenin gerilim üzerinden, Norton akım üzerinden gider.

AC devrelerde hiçbir şey değişmez. Elemanlar empedansa çevrildikten sonra devre, dirençli devre gibi analiz edilir. Kaynak dönüşümü (source transformation) de aynı empedans usulüyle yapılır.

Slayttaki özet (ekrandan, 01:10:00): direnç, bobin ve kondansatör içeren devreler Thevenin ve Norton teoremleriyle sadeleştirilebilir. Dönüşümler fazör biçiminde yazılmış akım, gerilim, empedans ve admitanslarla kolayca yapılır. Eşdeğer empedans ve admitans hesabı, akım ve gerilim bölücü bağıntılarının kullanımı fazörlerin dik koordinatlara çevrilmesini gerektirir.

## 10. Örnek 05: Kaynak Dönüşümüyle Thevenin Gerilimi

### 10.1 Devre ve kaynak

Slayttaki devre (ekrandan, 01:00:00): $I_1 = 5\text{ mA}\sin(400t + 50^\circ)$ akım kaynağı; ona paralel $C_1 = 1\ \mu$F; seri $R_1 = 3$ kΩ; paralel $L_1 = 0{,}3$ H; seri $L_2 = 2$ H; paralel $R_2 = 5$ kΩ; en sağda kesikli çerçeve içinde $C_2 = 0{,}7\ \mu$F.

Önce akım kaynağı kosinüse, sonra fazöre çevrilir (ekrandan, 01:00:00):

$$I_1 = 5\text{ mA}\sin(400t + 50^\circ) = 5\text{ mA}\cos(400t + 50^\circ - 90^\circ) = 5\text{ mA}\cos(400t - 40^\circ)$$

$$\mathbf{I}_1 = 5\angle -40^\circ\ \text{mA}$$

### 10.2 Empedanslar

$\omega = 400$ rad/s ile her elemanın empedansı bulunur. $\omega$'nın empedansın içinde görünmesi, $t$ domenindeki frekans bilgisinin sanal kısım aracılığıyla empedansa katıldığını gösterir.

- $Z_{C1} = -j/(\omega C_1) = -j/(400\cdot 10^{-6}) = -j2{,}5$ kΩ $= 2{,}5\angle -90^\circ$ kΩ
- $Z_{R1} = 3$ kΩ $\angle 0^\circ$
- $Z_{L1} = j\omega L_1 = j(400)(0{,}3) = j120\ \Omega = 120\angle 90^\circ\ \Omega$
- $Z_{L2} = j(400)(2) = j800\ \Omega = 800\angle 90^\circ\ \Omega$
- $Z_{R2} = 5$ kΩ $\angle 0^\circ$
- $Z_{C2} = -j/(400\cdot 0{,}7\cdot 10^{-6}) = -j3{,}57$ kΩ $= 3{,}57\angle -90^\circ$ kΩ

Bunların hepsi fazör biçimine getirilir, çünkü kaynak dönüşümünde çok sayıda çarpma ve bölme yapılacaktır. Saf sanal olanların açısı $j$'nin işaretinden $\pm 90^\circ$ gelir.

> **Ders sonrası not:** Hoca $Z_{C2}$'yi "357 kilo" diye okudu (01:01:39); doğrusu $3{,}57$ kΩ'dur ve slayttaki son devrede de $3{,}57\text{ k}\Omega\angle -90^\circ$ yazar.

### 10.3 Dönüşüm adımları

Hocanın anlattığı akış şöyledir:

1. Akım kaynağı $\mathbf{I}_1$ ile ona paralel $Z_{C1}$, gerilim kaynağı $\mathbf{I}_1 Z_{C1}$ ve ona seri $Z_{C1}$'e dönüştürülür. Fazörde genlikler çarpılır, açılar toplanır. Bunun amacı $Z_{C1}$'i $R_1$ ile seri hale getirip toplayabilmektir.
2. $Z_{R1} + Z_{C1}$ toplanır; gerçel ve sanal kısmı olan bu sayı fazöre çevrilir (genlik kareler toplamının karekökü, açı arktanjant).
3. Gerilim kaynağı bu empedansa bölünerek yeniden akım kaynağına ($\mathbf{I}_{n1}$) ve ona paralel empedansa dönüştürülür.
4. Bu empedans ile $Z_{L1}$ paralel olduğu için admitanslar toplanır: $\mathbf{Y}_{th2}$.
5. Akım kaynağı ve paralel admitans, gerilim kaynağı $\mathbf{V}_{th2} = \mathbf{I}_{n1}/\mathbf{Y}_{th2}$ ve seri elemana dönüştürülür.
6. Seri elemanı $Z_{L2}$ ile toplamak için admitans yeniden empedansa çevrilir; admitans ile empedans doğrudan toplanamaz, hangisi avantajlıysa ona çevrilir. Seri bağda empedans kullanılır.
7. Son olarak devre bir gerilim kaynağı ve seri empedanslarla $R_2 \parallel C_2$'den oluşur; akım Ohm kanunuyla bulunur ve $C_2$ üzerindeki gerilim hesaplanır.

Slaytta görünen ara sonuç (ekrandan, 01:05:00):

$$\mathbf{V}_{th2} = \frac{\mathbf{I}_{n1}}{\mathbf{Y}_{th2}} = \frac{1{,}92\text{ mA}\angle -90{,}2^\circ}{8{,}17\text{ m}\Omega^{-1}\angle -88{,}6^\circ} = 0{,}235\text{ V}\angle -1{,}6^\circ$$

Aynı slaytta sadeleşmiş devre görülür: $\mathbf{V}_{th2} = 0{,}235\text{ V}\angle -1{,}6^\circ$ kaynağı, seri $Y_{th2} = 8{,}17\text{ m}\Omega^{-1}\angle -88{,}6^\circ$, seri $Z_{L2} = 800\ \Omega\angle 90^\circ$, paralel $Z_{R2} = 5\text{ k}\Omega\angle 0^\circ$ ve $Z_{C2} = 3{,}57\text{ k}\Omega\angle -90^\circ$.

> **Ders sonrası not:** Python ile yeniden hesaplandığında $\mathbf{I}_1 Z_{C1} = 12{,}5\angle -130^\circ$ V, $Z_{R1} + Z_{C1} = 3905\angle -39{,}8^\circ\ \Omega$ ve $\mathbf{I}_{n1} = 3{,}20\angle -90{,}2^\circ$ mA çıkar. $\mathbf{Y}_{th2} = 8{,}17\text{ m}\Omega^{-1}\angle -88{,}6^\circ$ slaytla aynıdır. Buna göre $\mathbf{V}_{th2} \approx 0{,}392\angle -1{,}6^\circ$ V olmalıdır. Açılar slaytla aynı olduğundan slayttaki $1{,}92$ mA değeri büyük olasılıkla bir ara hesap hatasıdır; ara adımların slaytları karelerde yoktur. <!-- BELİRSİZ: 1,92 mA'nın hangi ara adımdan geldiği karelerde görünmüyor. -->

Hoca sonucun slayta yazılmadığını belirtti; $C_2$ üzerindeki gerilimin sayısal değeri derste verilmedi (çözüm Örnek Sorular bölümünde).

> **Hocanın vurgusu:** Bu soruda Thevenin sorularına göre fazladan hiçbir şey yoktur. Tek ön işlem bütün değerleri empedansa çevirmek, empedansları açısal (fazör) biçime getirmek ve sonra eşdeğer empedans ya da kaynak dönüşümü yapmaktır.

## 11. Gerilim ve Akım Bölücü

DC analizdeki gerilim bölücü ve akım bölücü bağıntıları da empedansa geçtikten sonra aynen kullanılır. Seri $Z_1$ ve $Z_2$ için:

$$V_2 = V_s\frac{Z_2}{Z_1 + Z_2}, \qquad V_1 = V_s\frac{Z_1}{Z_1 + Z_2}$$

Akım bölücüde de akımın dallara dağılımı empedansların oranıyla belirlenir; dirençlerdekiyle aynı biçimdedir. Paralel dallarda gerilim kaynağı biliniyorsa, her dalda aynı gerilim olduğundan $I_1 = V_s/Z_1$ gibi doğrudan da bulunabilir. Bütün bu kısımlar DC analizdekinin birebir aynısıdır; tek fark empedansa ve fazör gösterime geçip orada işlem yapmaktır.

> **Hocanın vurgusu:** Empedans konusu önemlidir. Empedans, zaman domenindeki analizden kurtarır ve bobin, kondansatör, direnç hepsi birbiriyle "iletişime geçebilen" tek tip devre elemanlarıymış gibi analiz edilir.

## 12. Önceki Haftadan Örnek 02: Paralel RLC'de KCL

### 12.1 Devre ve fazör

Ders sonunda önceki haftanın son sunumundaki bir soru, empedans işlendikten sonra yeniden çözüldü (ekrandan, 01:15:00). İstenen $v(t)$'dir.

$$i_s(t) = 8\cos(2\pi\cdot 10^6 t + 30^\circ)\ \text{mA}$$

Akım kaynağına paralel $70\ \Omega$, $10\ \mu$H ve $2$ nF bağlıdır. Kaynak kosinüs biçiminde olduğundan fazörü doğrudan $\mathbf{I}_s = 8\angle 30^\circ$ mA'dır. $\omega = 2\pi\cdot 10^6$ rad/s değeri, bobin ve kondansatörün devreye katkısını bulmak için gereklidir.

### 12.2 KCL denklemi

Bütün elemanlarda aynı $\mathbf{V}$ gerilimi vardır. KCL: $\mathbf{I}_s = \mathbf{I}_R + \mathbf{I}_L + \mathbf{I}_C$. Her dal akımı $\mathbf{V}$'nin o dalın empedansına bölümüdür:

- $\mathbf{I}_R = \mathbf{V}/R = \mathbf{V}/70$
- $\mathbf{I}_L = \mathbf{V}/Z_L = \mathbf{V}/(j\omega L)$
- $\mathbf{I}_C = \mathbf{V}/Z_C = \mathbf{V}/(-j/\omega C) = j\omega C\,\mathbf{V}$

Kondansatör teriminde $\omega C$ paya geçer, $-j$ de paya alınınca ($1/(-j) = j$) eksi işaret kalkar ve $j\omega C\mathbf{V}$ elde edilir. Denklemdeki eksi işaretler KCL'den gelir, $j$'den değil. Slayttaki denklem (ekrandan, 01:15:00):

$$\mathbf{I}_s - \frac{\mathbf{V}}{R} - \frac{\mathbf{V}}{j\omega L} - j\omega C\cdot\mathbf{V} = 0$$

$$8\angle 30^\circ - \frac{\mathbf{V}}{70} - \frac{\mathbf{V}}{j(2\pi\cdot 10^6)(10\cdot 10^{-6})} - j(2\pi\cdot 10^6)(2\cdot 10^{-9})\cdot\mathbf{V} = 0$$

### 12.3 Çözüm

$\mathbf{V}$ ortak paranteze alınınca parantez içinde dik biçimde bir karmaşık sayı kalır (ara adım eklendi):

$$\frac{1}{70} - \frac{j}{62{,}83} + j0{,}01257 = 0{,}01429 - j0{,}00335\ \Omega^{-1} = 0{,}0147\angle -13{,}2^\circ\ \Omega^{-1}$$

Bu fazöre çevrilip karşıya atılınca:

$$\mathbf{V} = \frac{8\angle 30^\circ\ \text{mA}}{0{,}0147\angle -13{,}2^\circ\ \Omega^{-1}} \approx 545\angle 43{,}2^\circ\ \text{mV}$$

Hoca sonucu "yaklaşık 544 mV, $43^\circ$" olarak okudu; Python ile hesap $545\angle 43{,}2^\circ$ mV verir. Gerilim açısı $43^\circ$, akım açısı $30^\circ$ olduğundan gerilim akımdan yaklaşık $13^\circ$ öndedir.

### 12.4 Eşdeğer empedans sorulsaydı

Bu soruda eşdeğer empedans sorulmadığı için admitansa girilmedi. Sorulsaydı, elemanlar paralel olduğundan hoca admitanstan giderdi: $Y_L = -j/(\omega L)$, $Y_C = j\omega C$ ve $Y_R = 1/R$ hesaplanıp doğrudan toplanır; gerçel kısmı dirençten, sanal kısmı bobin ve kondansatörden gelen dik biçimli bir sayı çıkar. Bu sayı kutupsal biçime çevrilir, sonra tersi alınarak empedans bulunur.

> **Hocanın vurgusu:** Bu sorular genelde basittir. En sık karışıklık akım-gerilim karşılaştırmasında olur: kim kimin önünde (lead), kim geride (lag). Burada "V leads I", yani gerilim akımın önündedir; tersi "I lags V" diye söylenir. İkinci karışıklık, empedansa geçerken kondansatör ($-j/\omega C$) ve bobin ($j\omega L$) formüllerinin karıştırılmasıdır; admitansta bu roller yer değiştirdiği için ayrıca dikkat gerekir.

## Örnek Sorular

### Soru 1: Seri RL devresi (Örnek 03)

(ekrandan, 00:45:00 ve 00:50:00)

$v_s = 12\sin(100t + 30^\circ)$ V kaynağına seri $R = 10\ \Omega$ ve $L = 10$ mH bağlıdır. Eşdeğer empedansı, akımı bulun; gerilim ile akımdan hangisinin önde olduğunu belirtin.

> **Çözüm (derste verildi):** $Z_{eq} = 10 + j1 = 10{,}05\angle 5{,}7^\circ\ \Omega$. $\mathbf{V} = 12\angle -60^\circ$ V. $\mathbf{I} = \mathbf{V}/Z_{eq} = 1{,}19\angle -65{,}7^\circ$ A. Gerilimin açısı daha pozitif olduğu için gerilim akımdan $5{,}7^\circ$ öndedir.

### Soru 2: Paralel RCL devresi (Örnek 04)

(ekrandan, 00:55:00)

$i_1 = 4\cos(300t - 10^\circ)$ A akım kaynağına paralel $R = 1\ \Omega$, $C = 1$ mF ve $L = 1$ H bağlıdır. Eşdeğer admitansı ve empedansı, eleman gerilimini bulun. <!-- BELİRSİZ: Soru metni karede görünmüyor; hoca gerilimin sorulduğunu varsayarak çözdü. -->

> **Çözüm (derste verildi):** $Y_{eq} = 1 + j0{,}3 - j0{,}00333 = 1 + j0{,}297 = 1{,}04\angle 16{,}5^\circ\ \Omega^{-1}$, $Z_{eq} = 0{,}959\angle -16{,}5^\circ\ \Omega$. $\mathbf{V} = (4\angle -10^\circ)(0{,}959\angle -16{,}5^\circ) = 3{,}84\angle -26{,}5^\circ$ V. Akım daha pozitif açılı olduğu için akım gerilimden öndedir.

### Soru 3: Kaynak dönüşümüyle Thevenin (Örnek 05)

(ekrandan, 01:00:00 ve 01:05:00)

$I_1 = 5\text{ mA}\sin(400t + 50^\circ)$ kaynağı; paralel $C_1 = 1\ \mu$F, seri $R_1 = 3$ kΩ, paralel $L_1 = 0{,}3$ H, seri $L_2 = 2$ H, paralel $R_2 = 5$ kΩ ve $C_2 = 0{,}7\ \mu$F. Kaynak dönüşümleriyle devreyi sadeleştirip $C_2$ üzerindeki gerilimi bulun.

Derste gösterilen kısım: $\mathbf{I}_1 = 5\angle -40^\circ$ mA; $Z_{C1} = -j2{,}5$ kΩ, $Z_{L1} = j120\ \Omega$, $Z_{L2} = j800\ \Omega$, $Z_{C2} = -j3{,}57$ kΩ; slaytta $\mathbf{Y}_{th2} = 8{,}17\text{ m}\Omega^{-1}\angle -88{,}6^\circ$ ve $\mathbf{V}_{th2} = 0{,}235\angle -1{,}6^\circ$ V.

> **Çözüm (derste verilmedi):** Python ile tutarlı değerlerle: $\mathbf{I}_{n1} = 3{,}20\angle -90{,}2^\circ$ mA, $\mathbf{V}_{th2} = 0{,}392\angle -1{,}6^\circ$ V, $Z_{th2} = 1/\mathbf{Y}_{th2} = 122{,}4\angle 88{,}6^\circ\ \Omega$. $R_2 \parallel C_2 = 2906\angle -54{,}5^\circ\ \Omega$. Gerilim bölücüyle $\mathbf{V}_{C2} = \mathbf{V}_{th2}\dfrac{Z_{R2}\parallel Z_{C2}}{Z_{th2} + Z_{L2} + Z_{R2}\parallel Z_{C2}} \approx 0{,}512\angle -15{,}6^\circ$ V. Slayttaki $0{,}235$ V kullanılsaydı sonuç $0{,}307\angle -15{,}6^\circ$ V çıkardı. $C_2$ yük kabul edilip çıkarıldığında $R_2$ uçlarındaki açık devre (Thevenin) gerilimi ise $\approx 0{,}385\angle -12{,}0^\circ$ V'tur.

### Soru 4: Paralel RLC'de $v(t)$ (Örnek 02)

(ekrandan, 01:15:00)

$i_s(t) = 8\cos(2\pi\cdot 10^6 t + 30^\circ)$ mA kaynağına paralel $70\ \Omega$, $10\ \mu$H ve $2$ nF bağlıdır. $v(t)$'yi bulun.

> **Çözüm (derste verildi):** KCL: $8\angle 30^\circ - \mathbf{V}/70 - \mathbf{V}/(j\omega L) - j\omega C\mathbf{V} = 0$. Buradan $\mathbf{V} \approx 545\angle 43{,}2^\circ$ mV; gerilim akımdan yaklaşık $13^\circ$ öndedir.

> **Çözüm (derste verilmedi):** Zaman domenine dönüş: $v(t) \approx 545\cos(2\pi\cdot 10^6 t + 43{,}2^\circ)$ mV.

### Soru 5: Açıların kaynağı

(derste sözlü, 00:30:13)

Kondansatörün empedansında $-90^\circ$, bobininkinde $+90^\circ$ açısı nereden gelir?

> **Çözüm (derste verildi):** Karmaşık düzlemde $+j$ ekseni $90^\circ$, $-j$ ekseni $-90^\circ$'dedir. $a + jb$'nin açısı $\tan^{-1}(b/a)$'dır; $Z_C = -j/(\omega C)$ ve $Z_L = j\omega L$'de gerçel kısım sıfır olduğu için açı yalnız sanal kısmın işaretinden gelir: kondansatörde $-90^\circ$, bobinde $+90^\circ$.

## Dersin Toparlaması

Bu derste AC devre analizinin temel aracı olan empedans işlendi. Kondansatör ve bobinin gerilim ile akım arasında $90^\circ$ faz kayması oluşturduğu türev üzerinden gösterildi; bu kayma fazörde $j$ çarpanına aktarılarak $Z_C = -j/(\omega C)$ ve $Z_L = j\omega L$ empedansları elde edildi. Empedans $Z = R + jX$ biçiminde genel bir bileşen olarak tanımlandı, tersi olan admitans $Y = 1/Z$ da eleman bazında verildi. Empedansa geçildikten sonra Ohm kanunu, KVL, KCL, seri/paralel birleştirme, gerilim ve akım bölücü, Thevenin, Norton ve kaynak dönüşümünün DC'deki gibi uygulandığı örneklerle gösterildi. Seri bağlarda empedans, paralel bağlarda admitans kullanmanın kolaylığı ve gerilim ile akımdan hangisinin önde olduğunun açılar karşılaştırılarak belirlenmesi özellikle vurgulandı.

Hoca bir sonraki derste büyük olasılıkla Bode diyagramlarına giriş yapılacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
