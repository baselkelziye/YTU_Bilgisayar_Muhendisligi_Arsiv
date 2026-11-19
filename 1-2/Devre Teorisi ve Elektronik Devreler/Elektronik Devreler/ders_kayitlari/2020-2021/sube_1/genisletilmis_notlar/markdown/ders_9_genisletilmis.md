# Ders 9 Genişletilmiş Notu: Kırpıcı Tekrarı, Gerilim Çoklayıcılar ve Bipolar Jonksiyon Transistör (BJT)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Osiloskopta DC ve AC Modu
- 2. Tekrar: İki Kutuplanmış Diyotlu Paralel Kırpıcı
- 3. Gerilim Çoklayıcılar ve Transformatör
- 4. Transistörün Yapısı
- 5. Transistörün Çalışması ve Akım Bağıntısı
- 6. Transistör Sembolü
- 7. Bağlantı Şekilleri
- 8. Çalışma Bölgeleri
- 9. Yaklaşıklıklar, Alfa ve Gerçek Akımlar
- 10. Transistörle Gerilim Yükseltme
- 11. Ortak Emitterli Yapı ve Beta
- 12. Ortak Kolektörlü Yapı ve Güç Sınırı
- 13. Veri Sayfası, Test ve Kılıflar
- Örnek Sorular
- Dersin Toparlaması

## 1. Osiloskopta DC ve AC Modu

Dersin başında simülasyon ödevleri konuşulurken bir öğrenci, osiloskopta bütün kanalların DC moduna alınması gerektiğini, AC modundayken sonuçların olması gerekenden farklı göründüğünü söyledi. Hoca bunun nedenini tahtada bir işaret çizerek açıkladı.

Bir $x(t)$ işareti düşünelim: sıfırın üzerinde bir seviyede, o seviyenin çevresinde inip çıkan bir dalga (ekrandan, 00:15:00). Bu işaret iki kısımdan oluşur. Birincisi DC bileşendir; işaretin ortalamasıdır. DC sıfır frekanslı bileşen olduğu için işaretin ortalamasını verir. İkincisi AC bileşendir; bu ortalamanın çevresinde, diyelim ki $+A$ ile $-A$ arasında salınan kısımdır. İşareti, DC seviyenin üzerine binmiş bir AC işaret olarak düşünebiliriz.

Osiloskopta iki seçim yapılabilir. DC modunda işaret olduğu gibi, yani DC ve AC bileşeni birlikte görülür. AC modunda osiloskop DC bileşeni süzer, onu sıfıra çeker ve yalnız sıfır çevresinde salınan AC bileşeni gösterir. Devrelerdeki gerçek gerilim seviyelerini görmek için normalde DC modunda kalmak gerekir.

> **Ders sonrası not:** Hoca anlatırken bir yerde "AC modu derseniz hem DC hem AC bileşenini görürsünüz" dedi, hemen ardından doğrusunu söyledi. Hem DC hem AC bileşeni gösteren DC modudur; AC modu DC bileşeni süzer.

## 2. Tekrar: İki Kutuplanmış Diyotlu Paralel Kırpıcı

Transistöre geçmeden önce hoca, önceki derste işlenen kutuplanmış paralel kırpıcılardan birini tekrar sorusu olarak çözdü (slayttaki "Biased Parallel Clippers" listesinin son devresi).

### 2.1 Devre

Devrede girişe seri bir direnç vardır. Çıkış uçlarına paralel iki kol bağlıdır (ekrandan, 00:20:00):

- Birinci kol: $D_1$ diyotu, anodu üst hatta, katodu $V_1$ kaynağının artı ucuna bağlı; $V_1$'in eksi ucu alt hatta (toprakta).
- İkinci kol: $D_2$ diyotu ters yönlü, katodu üst hatta, anodu $V_2$ kaynağının eksi ucuna bağlı; $V_2$'nin artı ucu alt hatta.

Hoca pil sembolünü okumayı da hatırlattı: uzun kenar üstte, kısa kenar altta ise üstteki potansiyel artıdır. Kısa kenar üstteyse o kaynak ters bağlanmış bir pil gibi düşünülür.

Giriş $V_{in}$, $V$ ile $-V$ arasında salınan bir sinüstür. Giriş, A noktasının (üst hat) toprağa bağlı B noktasına göre gerilimidir. Sıfırdan başlar, $V$'ye çıkar, sıfıra döner ve negatif yarı periyotta A'nın gerilimi B'ninkinden küçük olur.

### 2.2 Adım adım çözüm

Hoca canlandırmak için sayısal değerler verdi: $V_1 = 3$ V, $V_2 = 4$ V, giriş genliği 10 V (yani giriş 10 V ile $-10$ V arasında) (ekrandan, 00:25:00).

1. Giriş sıfırdayken hiçbir diyottan akım akmaz; çıkış sıfırdır.
2. Giriş pozitif yönde artarken, A'nın gerilimi B'ninkinden yüksek olduğu için pozitif yönde konmuş diyot, yani $D_1$, iletime aday olan diyottur. Ama önce $D_1$'in katoduna bağlı $V_1$ gerilimini yenmesi gerekir. Giriş 1 V iken $D_1$ hâlâ iletmez; $D_2$ zaten ters kutupludur. 2 V'ta da durum aynıdır.
3. Bu aralıkta direnç üzerinden akım akmaz. Akım akmadığı için direnç üzerinde gerilim düşümü olmaz, girişteki gerilim aynen çıkışa aktarılır: girişte 1 V varsa çıkışta 1 V, 2 V varsa 2 V vardır. Çıkış girişi izler.
4. Giriş 3 V'a geldiğinde $D_1$'in uçları arasındaki gerilim sıfır olur; 3,001 V'tan sonra $D_1$ akım akıtmaya başlar ve kısa devre gibi davranır. Çıkış artık $V_1 = 3$ V'a eşittir. Giriş 3 V'un üstünde kaldıkça çıkış 3 V'ta sabit kalır.
5. Giriş tekrar 3 V'un altına düştüğünde $D_1$ kesime girer, çıkış yine girişi izler.
6. Negatif yarı periyotta $D_2$'nin iletmesi için anodundaki gerilimin ($V_F$, $V_2$'nin eksi ucundaki $-4$ V) katodundakinden ($V_G$, çıkış hattı) büyük olması gerekir, yani çıkış hattının $-4$ V'un altına inmesi gerekir. Giriş $-1$ V iken çıkış hattı $-1$ V'tur, anot hâlâ $-4$ V'ta, daha negatiftir; $D_2$ iletmez.
7. Giriş $-4{,}001$ V olduğunda $V_F > V_G$ olur, $D_2$ iletir ve kısa devre gibi davranır. Çıkışta yalnız $V_2$ gerilimi kalır: çıkış $-4$ V'ta sabitlenir.
8. Giriş $-4$ V'un üstüne çıkınca çıkış yine girişi izler; bir periyot böyle tamamlanır.

Sonuç olarak çıkış, $-V_2 = -4$ V ile $V_1 = 3$ V arasında girişi izleyen, üstü 3 V'ta ve altı $-4$ V'ta kırpılmış bir sinüstür. Hoca, gerçek devrede kırpılma köşelerinin dimdik değil hafif yuvarlak olacağını da belirtti.

> **Hocanın vurgusu:** Kırpıcıların her farklı konfigürasyonuyla ilgili soru gelebilir. Hepsinin çözülmesi ve çıkışının doğru yorumlanması isteniyor.

## 3. Gerilim Çoklayıcılar ve Transformatör

Hoca önceki derste işlenen konuları kısaca hatırlattı: kırpıcılardan sonra kenetleyiciler (clamper) işlenmişti; kenetleyicilerde işin içine kondansatörler giriyordu. Zener diyotların en iyi sorular üzerinde anlaşılacağını söyledi. Bir öğrenci çoklayıcıların ayrıntılı anlatılmadığını hatırlatınca hoca bunların yalnız genel bilgi düzeyinde geçildiğini belirtti.

### 3.1 Gerilim çoklayıcılar

Slayttaki devrede transformatör sekonderinden gelen $V_m$ tepe gerilimi, sırayla bağlanmış diyotlar ($D_1$–$D_4$) ve kondansatörlerle ($C_1$–$C_4$) çoğaltılır (ekrandan, 00:30:00). $C_1$ üzerinde $V_m$, $C_2$, $C_3$ ve $C_4$ üzerinde $2V_m$ birikir. Uygun uçlardan $2V_m$ (doubler), $3V_m$ (tripler) ve $4V_m$ (quadrupler) çıkışları alınabilir. Hoca transformatör konusuna girmeyeceklerini, ama transformatörle gelen $V_m$ geriliminin dört katına kadar yükseltilebildiğini görmenin yeterli olduğunu söyledi.

### 3.2 Transformatör nedir?

Bir öğrenci laboratuvar hazırlık dokümanında transformatörün araştırılmasının istendiğini söyleyince hoca kısa bir açıklama yaptı. Transformatörün devre sembolünde bir tarafta bir sarım, karşı tarafta belli bir sarım oranıyla başka bir sarım vardır. $V_1$'in $V_2$'ye aktarımı elektromanyetik güç transferiyle olur. Sarım oranı 1:1 ise iki taraftaki gerilim aynıdır; 1:2 ise $V_1$ gerilimi $2V_1$ olarak aktarılır (ekrandan, 00:30:00). Bir demir çekirdeğin üzerine bakır teller sarılıdır. Bazen 1:1 sarılır; aradaki yalıtkan tabaka sayesinde gerilim izole edilerek karşı tarafa aktarılır.

Hoca ekranda gösterdiği bir kaynaktan şu tanımı okudu: transformatör (trafo), AC sistemlerde gerilimin seviyesini frekansı değiştirmeden manyetik indüksiyon yoluyla dönüştürmek için kullanılan, hareketli parçası bulunmayan bir elektrik makinesidir. Temelde bir demir ya da manyetik nüve vardır ve sarım oranlarına göre farklı aktarım olur. Girişe (giriş sargısına) primer, çıkışa sekonder denir.

### 3.3 Güç korunumu

Transformatörde güç aktarılır, yani giriş ve çıkıştaki güç eşittir. Bu yüzden giriş gerilimi $V$ çıkışta $2V$'ye yükseltiliyorsa, çıkıştaki cihazın akımı yarıya düşer.

Hoca bunu genel bir kurala bağladı. İki bacaklı herhangi bir komponent düşünelim; üzerinden geçen akım $I$, uçları arasındaki gerilim $V$ olsun. Gücü her zaman

$$P = V \cdot I$$

olur. Bu bir direnç de olabilir, bir transistör de. Bir devrenin ya da kara kutunun gerilimi ve çektiği akım biliniyorsa gücü hesaplanabilir.

## 4. Transistörün Yapısı

Dersin ana konusu transistörlerdir; hoca diyottan sonra bizim için en önemli devre elemanı olduğunu söyledi. 1950'li yıllarda yarı iletken transistörlerin bulunmasıyla yarı iletkenle yapılan cihazlar hem küçülmeye başladı hem de sıcaklık koşullarında daha kararlı çalıştırılabildi.

### 4.1 İki eklem, üç katman

Diyotlar tek eklemliydi: P ve N malzemeden oluşan, arasında tükenme bölgesi (depletion region) bulunan bir yapı. Transistörlerde de P ve N tipi malzeme kullanılır, ama üç katman vardır ve bunlardan en az ikisi aynı tiptedir. Merkezdeki malzemenin tipi diğerlerinden farklıdır. Böylece iki eklem oluşur; bu yüzden bu elemana bipolar jonksiyon transistör (BJT) denir. Merkezdeki malzemenin tipine göre iki tip transistör yapılabilir: pnp ve npn (ekrandan, 00:35:00).

Hoca yapıyı şöyle canlandırdı: slaytta kare gibi çizilse de, P (ya da N) tipi bir silindirin tam ortasına kuşak gibi farklı tipte (örneğin N tipi) malzeme konduğunu, sonra silindirin ortasından kesit alındığını düşünebiliriz. Slayttaki kesit bu yandan görünüştür. Slayttaki çizimde yapının toplam genişliği 0,150 inç, ortadaki katmanın kalınlığı ise 0,001 inçtir (ekrandan, 00:35:00).

> **Ek bilgi (derste anlatılmadı):** Slayttaki ölçüler, base katmanının dış katmanlara göre çok ince olduğunu gösterir (yaklaşık 150'de 1). Base'in ince ve az katkılı olması, emitterden gelen taşıyıcıların büyük kısmının base'de kaybolmadan collectora ulaşmasını sağlar; $I_B$'nin küçük olmasının nedeni budur.

### 4.2 Uçlar

pnp ve npn tiplerinin ikisinde de üç uç vardır (ekrandan, 00:35:00):

- Base (B, taban ya da temel): ortadaki kuşağa bağlı olan uçtur.
- Collector (C, toplayıcı): uçlardaki katmanlardan biri.
- Emitter (E, yayıcı): uçlardaki diğer katman.

Hoca adları şöyle canlandırdı: akım emitterden yayılıp collectorda toplanıyor gibi düşünülebilir; diğer tipte ise tam tersi. Base daima ortadadır, emitter ve collector uçlarda yer alır. pnp ve npn birbirinin tam tersi mantığıyla çalışır; akım yönleri ve beslemeleri farklıdır.

## 5. Transistörün Çalışması ve Akım Bağıntısı

### 5.1 pnp transistör

Slaytta pnp bir transistör, iki dış kaynakla ($V_{EE}$ ve $V_{CC}$) bağlanmıştır (ekrandan, 00:40:00). Diyottaki gibi her P-N birleşim yerinde bir tükenme bölgesi oluşur; burada iki tükenme bölgesi vardır.

Kaynaklar şöyle bağlanmıştır:

- Emitter-base eklemi ileri kutuplanmıştır (forward biased): $V_{EB} = V_{EE}$, pozitif.
- Base-collector eklemi ters kutuplanmıştır (reverse biased): $V_{CB} = -V_{CC}$, negatif.

Bu durumda çoğunluk taşıyıcıları (majority carriers) emitterden collectora, transistörün içinden geçer. Bunun yanında küçük bir base akımı $I_B$ oluşur; çok az miktarda azınlık taşıyıcı akımı da vardır.

### 5.2 Akım bağıntısı

Emitter düğümüne Kirchhoff akım yasası uygulanınca:

$$I_E = I_C + I_B$$

> **Ders sonrası not:** Hoca bu eşitliği önce "$I_C = I_B + I_E$" diye yazdı. Bir öğrenci "denklemi yanlış mı yazdınız?" diye sorunca hoca düzeltti: emitterden giren akım $I_C$ ve $I_B$ olarak dağılır, doğrusu $I_E = I_C + I_B$'dir.

### 5.3 npn transistör

npn tipinde bağlantı pnp'nin tam tersidir: kolektörle base arasına pozitif gerilim ($V_{CB} > 0$), emitter-base arasına negatif gerilim ($V_{EB} < 0$) bağlanır. Aynı eşitlik geçerlidir: $I_E = I_C + I_B$. pnp'de akım emitterden girip collectordan çıkıyor diye düşünülürken npn'de collectordan ve base'den girip emitterden çıkıyor diye düşünülür. Her iki durumda da $I_C$ ile $I_B$ düğüme aynı yönde ulaşır; bu yüzden her zaman toplanırlar.

## 6. Transistör Sembolü

Örnekler genellikle npn üzerinden anlatılır. Sembolde base dik bir çizgidir; collector ve emitter bu çizgiye eğik bağlanır. Daima emitter ucunda bir ok bulunur.

Okun okunuşu için hocanın kuralı şudur: okun gösterdiği yön N tipi malzemeyi gösterir.

- Ok dışarıyı gösteriyorsa, dışarıdaki emitter N tipidir. Dış katmanlar aynı tipte olmak zorunda olduğu için collector da N'dir, base'e P kalır: npn.
- Ok içeriyi, yani base tarafını gösteriyorsa, base N tipidir. Dış katmanlar (emitter ve collector) P olur: pnp.

Okun bulunduğu uç daima emitterdir; uçlar buradan da çıkarılabilir. npn'de $I_C$ collectora aşağı doğru girer, $I_B$ base'e içeri doğru girer, $I_E$ emitterden aşağı doğru çıkar. pnp'de bunların eşleniği (ters yönlüsü) geçerlidir (ekrandan, 00:45:00).

> **Hocanın vurgusu:** Okun olduğu bacak emitterdir ve ok N tipini gösterir. Bir sembole bakınca transistörün npn mi pnp mi olduğu buradan çıkarılabilmelidir.

## 7. Bağlantı Şekilleri

Transistör üç bacaklı bir devre elemanıdır: collector, emitter ve base. Kullanılan devre yapısına göre bacaklardan biri toprağa (devrenin ground'una) bağlanır:

- Emitterde toprak varsa ortak emitterli yapı (common-emitter).
- Base toprağa bağlıysa ortak bazlı yapı (common-base).
- Collector toprağa bağlıysa ortak kolektörlü yapı (common-collector).

Slayttaki "Common-Base Configuration" şekli, base'in hem giriş (emitter-base) hem çıkış (collector-base) tarafında ortak olduğunu pnp ve npn için gösterir (ekrandan, 00:45:00).

Ortak bazlı npn bir yapıda base ile emitter arasında, base ile collector arasında birer diyot varmış gibi düşünülebilir; transistör sanki iki diyotun birleşimidir. Silisyumdan yapılmış bir transistörde base-emitter arasına uygulanan gerilim 0,7 V'u geçtikten sonra $I_E$ akımı ciddi biçimde artar.

## 8. Çalışma Bölgeleri

Bir transistörün çalışma eğrisinde üç bölge vardır: kesim bölgesi (cutoff), doyma bölgesi (saturation) ve aktif (çalışma) bölge. Slayttaki ortak bazlı çıkış karakteristiği, $I_E = 0, 1, 2, \dots, 7$ mA değerleri için $I_C$ (mA) – $V_{CB}$ (V) eğrilerini gösterir; hoca kesim bölgesini 1, doyma bölgesini 2 diye işaretledi (ekrandan, 00:50:00).

- Kesim bölgesi: gerilim yükseltilse de akımın akmadığı bölgedir. Slaytta $I_E = 0$ mA eğrisinin altındaki alandır; $V_{CB}$ artsa da $I_C$ ve $I_E$ sıfırdadır. Transistör burada genel olarak çalışmaz.
- Doyma bölgesi: akımın çokça aktığı ama collector-base arasına düşen gerilimin düşük olduğu bölgedir. Slaytta $V_{CB}$'nin 0'ın hemen solundaki dar alandır. Transistör tamamen açıktır; çok az gerilimle yüksek akım elde edilir.
- Aktif bölge: bu ikisinin arasıdır. Yükselteç (transistör) bu bölgede çalışır. Eğriler burada yatay seyreder; $I_C \cong I_E$ olur.

> **Hocanın vurgusu:** Bağlantı şekline göre eğriler değişir. Şimdilik bilinmesi gereken, her transistörde kesim, doyma ve aktif olmak üzere üç bölge bulunduğudur.

Transistöre neden amplifier denir? Amplifier güçlendirici demektir. Transistör yalnız dijital çıkış ve giriş üretmek için değil, en temelde gerilimi yükseltmek amacıyla kullanılır. Özellikle ortak bazlı yapıda bir taraftan giriş uygulanır, öbür taraftan çıkış alınır.

## 9. Yaklaşıklıklar, Alfa ve Gerçek Akımlar

### 9.1 Yaklaşıklıklar

Slayttaki iki yaklaşıklık şunlardır (ekrandan, 00:55:00):

$$I_C \cong I_E \qquad V_{BE} = 0{,}7\ \text{V (silisyum için)}$$

Birincisi $I_E = I_C + I_B$ eşitliğinden gelir: $I_B$ çok küçük olduğu için ihmal edilir. İkincisi için hoca npn transistörün base-emitter arasını bir diyot gibi düşünmeyi önerdi (base P, emitter N). $V_{BE} = V_B - V_E$ gerilimi 0,7 V'un üstüne çıktığı andan itibaren $I_C$ akımı akmaya başlıyor gibi düşünülebilir.

### 9.2 Alfa

$\alpha$, collector akımının emitter akımına oranıdır:

$$\alpha = \frac{I_C}{I_E}$$

$I_B$ küçük olsa da sıfır olmadığından $I_C / I_E$ tam 1 olmaz. En yüksek alabileceği değer 1'dir; genellikle 0,99 gibidir. Hoca başka bir yerde 0,90 ile 0,99 arasında bir değer aldığını söyledi. DC gerilim uygulandığında bu oran sabit akımlarla bulunur; AC durumda değişimlerin oranı olarak bulunur.

> **Ek bilgi (derste anlatılmadı):** Kitapta DC değer $\alpha_{dc} = I_C/I_E$, AC değer ise sabit $V_{CB}$ için $\alpha_{ac} = \Delta I_C / \Delta I_E$ diye tanımlanır. Hocanın "difansiyel farklarının oranı" dediği büyük olasılıkla bu ikinci tanımdır.

### 9.3 Gerçek akımlar

Tam hesap yapılmak istenirse collector akımına azınlık taşıyıcılarının katkısı da eklenir (ekrandan, 01:20:00):

$$I_C = \alpha I_E + I_{CBO}$$

Burada $I_{CBO}$ azınlık kolektör akımıdır (minority collector current). Slayta göre $I_{CBO}$ genellikle ihmal edilebilecek kadar küçüktür; yüksek güçlü transistörler ve yüksek sıcaklık ortamları bunun dışındadır.

$I_B = 0\ \mu$A iken transistör kesimdedir, ama yine de bir azınlık akımı akar. Buna $I_{CEO}$ denir:

$$I_{CEO} = \left.\frac{I_{CBO}}{1-\alpha}\right|_{I_B = 0\ \mu\text{A}}$$

> **Hocanın vurgusu:** Burası çok önemli değil. Önemli olan $\alpha$'yı bilmektir; $I_{CBO}$ ve $I_{CEO}$ akımlarını genel kültür olarak bilmek yeterlidir.

## 10. Transistörle Gerilim Yükseltme

Aradan sonra hoca transistörle gerilim yükseltmeye dair temel bir örneği anlattı (ekrandan, 01:10:00).

### 10.1 Devre

Devrede pnp bir transistör vardır; base toprağa bağlıdır (ortak bazlı yapı). Giriş emitter ucundan verilir, çıkış collectordan alınır. Emitterden $V_i = 200$ mV'luk sinüzoidal bir giriş işareti uygulanır.

- Emitter-base arasındaki direnç $R_i = 20\ \Omega$'dur. Bu direnç düşüktür, çünkü emitter ile base arasında ileri kutuplu bir diyot vardır.
- Collector-base arasındaki direnç $R_o = 100$ k$\Omega$'dur. Aradaki ters kutuplu diyot nedeniyle dışarıdan ölçülen bu direnç 100 k$\Omega$'lar mertebesindedir.
- Collectora toprağa giden bir yük direnci $R = 5$ k$\Omega$ bağlanmıştır.

Yük direnci $R_L$, collectordan beslenen ikinci bir devrenin ya da cihazın iç direncini temsil eder. "Load" (yük) denince asıl çalışan devreden beslenen ikinci devrenin temsili anlaşılır.

### 10.2 Çözüm

Verilenler: $V_i = 200$ mV, $R_i = 20\ \Omega$, $R = 5$ k$\Omega$ (ekrandan, 01:10:00).

1. Emitter akımı: $I_E = I_i = \dfrac{V_i}{R_i} = \dfrac{200\text{ mV}}{20\ \Omega} = 10$ mA.
2. Yaklaşıklık: $I_C \cong I_E$, dolayısıyla $I_L \cong I_i = 10$ mA.
3. Yük gerilimi: $V_L = I_L R = (10\text{ mA})(5\text{ k}\Omega) = 50$ V.
4. Gerilim kazancı, çıkış geriliminin giriş gerilimine oranıdır: $A_v = \dfrac{V_L}{V_i} = \dfrac{50\text{ V}}{200\text{ mV}} = 250$.

Hesaplar python ile doğrulandı. Girişteki 200 mV'luk işaret, çıkışta 250 kat yükseltilmiş olarak 50 V olur.

> **Ders sonrası not:** Hoca sonucu söylerken "girişte 20 milivoltluk, çıkışta 50 voltluk" dedi. Slayttaki giriş 200 mV'tur ve $A_v = 250$ bu değerle bulunur; 20 mV olsaydı kazanç 2500 çıkardı.

### 10.3 Neden yükseltilir?

Sensörlerden alınan dış dünya verileri (EKG cihazları, uydu verileri gibi) çok küçük genliklidir. Bunların mikroişlemcilerin ve DSP birimlerinin işleyebileceği seviyeye getirilmesi gerekir; bu, 50 V değil 5 V seviyesi olsa bile en az 20-25 kat yükseltme demektir. Bu kullanım sinyal yükseltme (signal amplification) diye adlandırılır.

Hoca günlük hayattan bir örnek de verdi: elektro gitar. Gitardaki bir sensör tellerin titreşimine göre değişen çok düşük genlikli bir elektrik işareti üretir. Bu işaret doğrudan hoparlöre verilirse hoparlörü süremez; araya amplifikatör konur, işaret yükseltilir ve hoparlöre öyle verilir. Yüksek enerjili bu devrelerde işaret çeşitli bozulmalara uğrar. Bu bozulmalar aslında istenmeyen bir şeydir, ama müziğe sanatsal bir renk kattığı için bilerek kullanılan distorsiyonlar vardır; amfilerdeki düğmeler bu bozulmaları ayarlar.

## 11. Ortak Emitterli Yapı ve Beta

### 11.1 Ortak emitterli yapı

Ortak emitterli (common-emitter) yapıda emitter toprağa gider. Hoca bunun en çok kullanılan yapı olduğunu vurguladı. npn bir transistörde collector ucuna $V_{CC}$ gerilimi bağlanır, collectordan aşağı doğru bir akım akar, emitterden akım çıkar, base'e akım girer. Genellikle giriş $V_{in}$ base'den uygulanır, emitter topraklanır, transistörün beslemesi collector ucundan verilir. Bu uçlara dirençler bağlanacak ve farklı konfigürasyonlar sonraki derslerde görülecektir.

Ortak emitter karakteristiklerinde $V_{CE}$ gerilimi ile collectordan akan $I_C$ akımının eğrileri ($I_C$–$V_{CE}$ grafiği) önemlidir. Kesim bölgesi, $V_{CE}$ istenen değeri alsa da $I_C$ ya da $I_E$'nin akmadığı bölgedir. Doyma (satürasyon) bölgesi, $I_C$ ya da $I_E$'nin istenen değeri aldığı ama $V_{CE}$'nin çok düşük olduğu bölgedir.

Eğriler $I_B$ değerleri için çizilir ve bu değerler mikroamper ($10^{-6}$ A, milyonda bir amper) seviyesindedir. $I_C$ ve $I_E$ ise miliamper ($10^{-3}$ A) seviyesindedir. Arada binlerce kat fark vardır; $I_B$'nin hesaplarda genellikle ihmal edilmesinin nedeni budur.

### 11.2 Transistör bir anahtar gibi

Hoca transistörün nasıl çalıştığını kafada canlandırmak için şöyle anlattı: base-emitter arasına $V_{BE}$ gerilimi uygulanır. Bu gerilim 0,7 V'u geçince transistör bir nevi anahtar gibi açılır. $V_{BE}$'den dolayı base'de bir $I_B$ akımı oluşur. Bu $I_B$ akımının miktarı, collectordan geçen $I_C$ akımının (ve emitterdeki $I_E$ akımının) miktarını belirler. Bu yüzden devre konfigürasyonunun transistör aktif bölgede çalışacak şekilde yapılması beklenir.

### 11.3 Beta

$\alpha$'nın yanında bir de $\beta$ parametresi vardır:

$$\beta = \frac{I_C}{I_B}$$

$I_B$ çok küçük, $I_C$ ise miliamper seviyesinde olduğu için $\beta_{dc}$ genellikle yüksek bir değerdir. $\beta$ transistörün güçlendirme (yükseltme) faktörü olarak adlandırılır ve sorularda genellikle verilir.

### 11.4 Alfa ile beta arasındaki bağıntı

Hoca bağıntıyı tahtada şöyle türetti:

1. $I_C = \beta I_B$.
2. $I_E = I_C + I_B = \beta I_B + I_B$. $I_B$ parantezine alınınca $I_E = (\beta + 1) I_B$.
3. $\alpha = I_C / I_E$ olduğundan $I_E = I_C / \alpha$. Bunu yerine koyarsak $\dfrac{I_C}{\alpha} = (\beta + 1) I_B$.
4. İki tarafı $I_B$'ye bölüp $I_C / I_B = \beta$ yazılırsa $\dfrac{\beta}{\alpha} = \beta + 1$.
5. Buradan

$$\alpha = \frac{\beta}{\beta + 1}$$

> **Ek bilgi (derste anlatılmadı):** Aynı bağıntı ters çevrilirse $\beta = \dfrac{\alpha}{1-\alpha}$ olur. Bu yüzden $\alpha$ 1'e çok yakın olduğunda $\beta$ büyük bir sayıdır; $I_{CEO} = I_{CBO}/(1-\alpha)$ ifadesi de $I_{CEO} = (\beta + 1) I_{CBO}$ biçiminde yazılabilir.

## 12. Ortak Kolektörlü Yapı ve Güç Sınırı

### 12.1 Ortak kolektörlü yapı

Ortak kolektörlü yapıda, hem pnp hem npn tarafında toprağa en yakın uç collectordur. Eğrileri ortak emitterli yapıdakilere yaklaşık benzer; burada da $I_B$ akımları parametre olarak değerlendirilir.

### 12.2 Güç sınırı

Transistörlerin belli bir gücü vardır. Collector ile emitter arası iki uçlu bir kara kutu gibi düşünülürse, uçlar arasında $V_{CE}$ gerilimi, üzerinden geçen akım $I_C$ (ya da yaklaşık $I_E$) olur. Bu durumda harcanan güç

$$P = V_{CE} \cdot I_C$$

olur. Aktif bölgenin tamamı kullanılamaz. Kesim bölgesi zaten kullanılmaz, doyma bölgesi de kullanılmaz. Ayrıca $V_{CE}$ ile $I_C$'nin çarpımının belli bir değerin altında kalması gerekir; bu da güçten kaynaklanan bir sınır eğrisi getirir. Çarpımın bu değeri aştığı bölge de dışarıda kalır. Bir devre konfigürasyonu yapılırken en iyi çalışılacak yer, aktif bölgenin bu sınırlar içinde kalan alanıdır.

Slayttaki "Operating Limits for Each Configuration" grafiği bu sınırları gösterir (ekrandan, 01:25:00):

- Kesim bölgesinde $V_{CE}$ maksimum, $I_C$ minimumdur ($I_{C\max} = I_{CEO}$).
- Doyma bölgesinde $I_C$ maksimum, $V_{CE}$ minimumdur ($V_{CE\max} = V_{CE\text{sat}} = V_{CEO}$).
- Transistör bu ikisinin arasındaki aktif bölgede çalışır.
- Grafikteki sınır değerleri: $I_{C\max} = 50$ mA, $V_{CE\max} = 20$ V, $V_{CE\text{sat}} = 0{,}3$ V ve güç eğrisi $P_{C\max} = V_{CE} I_C = 300$ mW. Eğri üzerinde işaretli noktalar yaklaşık (6 V, 50 mA), (10 V, 30 mA) ve (20 V, 15 mA)'dir; üçünün çarpımı da 300 mW'tır (python ile doğrulandı).

Ortak emitterli ve ortak kolektörlü yapıda güç $V_{CE} I_C$ ile, ortak bazlı yapıda ise collector-base gerilimi ile $I_C$'nin çarpımıyla ($V_{CB} I_C$) hesaplanır.

## 13. Veri Sayfası, Test ve Kılıflar

### 13.1 Uç dizilimi ve veri sayfası

Yaygın bir transistör kılıfı, bir ucu kesilmiş (düzleştirilmiş) silindirik bir yapıdır. Hocanın gösterdiği örnekte düz yüz size dönükken 1 numaralı bacak emitter, 2 numaralı bacak base, 3 numaralı bacak collectordur.

Bu tür bilgiler transistörün veri sayfasından (spec sheet, kısaca "spek") öğrenilir; örneğin internette "2N4123 spec" diye aratılabilir. Veri sayfasında farklı akımlar, küçük işaret karakteristikleri, açık (on) ve kapalı (off) durumundaki karakteristikler gibi birçok parametre verilir.

<!-- BELİRSİZ: Hoca önce "2N4143" sonra "2N4123" dedi; ikincisi büyük olasılıkla doğrudur. Veri sayfası ekranı karelerde yok. -->

> **Ek bilgi (derste anlatılmadı):** Uç dizilimi kılıfa ve üreticiye göre değişir; aynı görünen iki kılıfta E-B-C sırası farklı olabilir. Bu yüzden hocanın söylediği gibi her transistör için veri sayfasına bakmak gerekir.

### 13.2 Multimetreyle test

npn bir transistörde base-emitter eklemi bir diyot gibi davranır. Ölçü aleti ileri kutuplama yönünde bağlanınca düşük direnç okunur. Collector-base arasında ters kutuplama olduğundan, ölçü aletinin pozitif ucu ters yönde değdirildiğinde yüksek direnç okunur. Hoca bunun yükseltme örneğindeki düşük $R_i$ ve yüksek $R_o$ ile aynı nedenden geldiğini hatırlattı.

### 13.3 Kılıflar

Transistörler farklı kılıflarda karşımıza çıkar; uçların yeri kılıfa göre değişir (ekrandan, 01:30:00). Slaytta beyaz noktayla collectoru işaretlenmiş kılıflar, kılıfın kendisinin collector olduğu metal kılıflar ve vidalı güç transistörleri görülür. Daha büyük transistörler de vardır.

İki ana montaj türü vardır:

- Bacaklı kılıflar (hoca "dip kılıf" dedi): bacakları devre kartındaki deliklerden geçirilerek takılır.
- Yüzey montajlı elemanlar (SMD): özellikle bilgisayar ve telefon kartlarında (PCB) kullanılır. Eleman deliklerden geçirilmez; kart yüzeyindeki lehimli alanlara bacakları değecek şekilde yerleştirilir ve ısıtılarak yüzeye monte edilir. Yine üç bacağı vardır.

## Örnek Sorular

### Soru 1: İki kutuplanmış diyotlu paralel kırpıcı

(ekrandan, 00:20:00 ve 00:25:00)

Girişe seri bir direnç ve çıkışa paralel iki kol bağlıdır: birinci kolda anodu üst hatta olan $D_1$ ile artı ucu yukarıda $V_1 = 3$ V kaynağı, ikinci kolda katodu üst hatta olan $D_2$ ile artı ucu aşağıda $V_2 = 4$ V kaynağı vardır. Giriş tepe değeri 10 V olan bir sinüstür. Diyotlar ideal kabul edilirse çıkış dalga biçimi nasıl olur?

**Çözüm (derste verildi):**

- $-4\ \text{V} < v_i < 3\ \text{V}$: iki diyot da kesimdedir, dirençten akım akmaz, $v_o = v_i$.
- $v_i > 3$ V: $D_1$ iletir, $v_o = V_1 = 3$ V.
- $v_i < -4$ V: $D_2$ iletir, $v_o = -V_2 = -4$ V.
- Çıkış, üstü 3 V'ta ve altı $-4$ V'ta kırpılmış bir sinüstür. Python ile $10\sin(\omega t)$ işareti $[-4, 3]$ aralığına kırpılarak sonuç doğrulandı.

### Soru 2: Transistörle gerilim yükseltme

(ekrandan, 01:10:00)

Ortak bazlı pnp bir devrede emitterden $V_i = 200$ mV uygulanıyor. Giriş direnci $R_i = 20\ \Omega$, çıkış direnci $R_o = 100$ k$\Omega$, yük direnci $R = 5$ k$\Omega$'dur. $I_E$, $I_L$, $V_L$ ve gerilim kazancı $A_v$'yi bulun.

**Çözüm (derste verildi):**

- $I_E = I_i = V_i / R_i = 200\text{ mV} / 20\ \Omega = 10$ mA.
- $I_C \cong I_E \Rightarrow I_L \cong 10$ mA.
- $V_L = I_L R = (10\text{ mA})(5\text{ k}\Omega) = 50$ V.
- $A_v = V_L / V_i = 50\text{ V} / 200\text{ mV} = 250$.

### Soru 3: Transistörün tipi

(derste sözlü, 01:27:34)

Veri sayfası açılan 2N4123 transistörünün sembolüne bakarak tipini söyleyebilir misiniz?

**Çözüm (derste verildi):** npn. Ok emitter ucunda ve dışarıyı gösteriyor, yani emitter N tipi. Dış katmanlar aynı tipte olduğu için collector da N'dir, base P kalır. Veri sayfasında da npn yazar.

### Soru 4: Osiloskopta AC modu

(derste sözlü, 00:14:25)

Simülasyonda osiloskop kanalları AC modundayken sonuçlar neden olması gerekenden farklı görünür?

**Çözüm (derste verildi):** İşaret DC bileşen (ortalama) ile AC bileşenin toplamıdır. AC modu DC bileşeni süzer ve işareti sıfır çevresinde salınıyormuş gibi gösterir. İşaretin gerçek halini görmek için DC moduna geçilmelidir; DC modu iki bileşeni birlikte gösterir.

## Dersin Toparlaması

Ders, osiloskobun DC ve AC modlarının farkıyla ve iki kutuplanmış diyotlu bir paralel kırpıcının adım adım çözümüyle diyot konusunu kapattı. Gerilim çoklayıcıların transformatörden gelen $V_m$'yi dört katına kadar çıkarabildiği hatırlatıldı; transformatörün sarım oranıyla gerilimi dönüştürdüğü ve gücü koruduğu için gerilim artınca akımın azaldığı anlatıldı.

Ardından dersin ana konusu olan bipolar jonksiyon transistöre geçildi. İki eklemli, üç katmanlı yapı (npn, pnp), E-B-C uçları, emitter-base ekleminin ileri, base-collector ekleminin ters kutuplanması, $I_E = I_C + I_B$ bağıntısı ve sembolde okun N tipini gösterdiği kuralı işlendi. Ortak baz, ortak emitter ve ortak kolektör bağlantıları; kesim, doyma ve aktif bölgeler; $I_C \cong I_E$ ve $V_{BE} = 0{,}7$ V yaklaşıklıkları; $\alpha$, $\beta$ ve $\alpha = \beta/(\beta+1)$ bağıntısı; ortak bazlı yükselteçte 250 kat gerilim kazancı; güç sınırı ($P_{C\max} = V_{CE} I_C$), veri sayfası, multimetreyle test ve kılıf türleri görüldü. Hoca, transistör uçlarına dirençler bağlanarak kurulan farklı konfigürasyonların sonraki derste görüleceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
