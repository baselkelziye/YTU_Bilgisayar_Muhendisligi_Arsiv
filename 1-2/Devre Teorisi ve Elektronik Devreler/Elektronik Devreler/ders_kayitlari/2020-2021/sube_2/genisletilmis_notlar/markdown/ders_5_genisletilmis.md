# Ders 5 Genişletilmiş Notu: Yarı İletkenler ve Diyot: p-n Eklemi, Diyot Karakteristiği ve Zener Diyot

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Devre teorisinden elektronik devrelere
- 2. Diyot ve ideal diyot
- 3. Yarı iletken malzemeler ve katkılama
- 4. p-n eklemi ve tükenme bölgesi
- 5. Polarma durumları
- 6. Diyot denklemi, eşik gerilimi ve gerçek karakteristik
- 7. Zener bölgesi ve zener diyot
- 8. Sıcaklık etkisi, diyot direnci ve eşdeğer devre
- 9. Kapasitans, ters toparlanma süresi ve veri sayfası
- 10. Diyot sembolü, uçlar ve diyot testi
- 11. LED, fotodiyot ve diyot dizileri
- Örnek Sorular
- Dersin Toparlaması

## 1. Devre teorisinden elektronik devrelere

Ders, önceki iki haftada işlenen sensör ve eyleyici konularından sonra elektronik devrelerin teorik kısmına giriş olarak başladı. Hoca iki dersin kapsamını şöyle ayırdı. Devre teorisinde KCL, KVL ve Ohm kanunu gibi formülleştirilebilen temel yasalar ve pasif devre elemanları işlenir. Elektronik devreler dersi bu yasaların bilindiğini varsayar ve bir adım ileri giderek yarı iletken elemanların analizine geçer. Kısacası elektronik devreler dersinin konusu yarı iletkenlerdir.

Bu ders kapsamında işlenecek üç yarı iletken eleman diyot, transistör ve MOSFET'tir. Her biri için yarı iletkenliğin ne anlama geldiğine, kutuplama yapılıp akım oluştuğunda elemanın iç yapısında neler değiştiğine bakılacaktır. İlk konu diyottur.

## 2. Diyot ve ideal diyot

### 2.1 İki terminalli eleman

Diyot iki terminalli, yani iki bacaklı bir devre elemanıdır (ekrandan, 00:35:00). Karşılaştırma için hoca üç terminalli elemanlara transistörü ve potansiyometreyi (reosta) örnek verdi. Slaytta diyot sembolünün iki ucunda $+$ ve $-$ işaretleri, üzerinde $V_D$ gerilimi ve sembol yönünde $I_D$ akımı gösterilir.

### 2.2 Tek yönlü iletim

Diyotun bilinmesi gereken ilk özelliği bir polarizasyon (kutuplanma) yönünün olmasıdır: bir ucu artı, bir ucu eksidir. Slaytta "diyot ideal olarak yalnız bir yönde iletir" yazar (ekrandan, 00:35:00).

- **Doğru polarma:** Gerilim doğru yönde verilirse ideal diyot kısa devre gibi davranır, normal bir kablodan farkı kalmaz. Slayttaki şekilde bu durumda akımın "devre tarafından sınırlandığı" (limited by circuit) belirtilir.
- **Ters polarma:** Gerilim ters yönde verilirse diyot sonsuz direnç, yani açık devre gibi davranır. Uçları arasında hiç iletim yoktur, $I_D = 0$.

Hoca bunu bir if-else yapısına benzetti: yazılımda bir değişkene bakıp ne yapılacağına nasıl karar veriliyorsa, diyot da fiziksel olarak "programlanmış" bir elemandır; doğru yönde iletir, ters yönde kesimdedir.

### 2.3 Teori ve pratik

Sonsuz direnç pratikte yoktur. Çok yüksek dirençli bir malzeme de bir noktadan sonra iletime geçer. Benzer biçimde doğru polarmada "sıfır dirençli kablo gibi" denir, ama diyotun iç malzemesi kablonun malzemesinden farklıdır ve hiç direnç göstermeyen bir eleman olamaz. Hoca teorinin ve pratiğin her zaman ayrılması gerektiğini söyledi.

> **Hocanın vurgusu:** Soruda aksi belirtilmedikçe diyot ideal kabul edilir. Şematik şekilde ideal diyot deniyorsa kural şudur: doğru polarmada kısa devre, ters polarmada açık devre.

### 2.4 İdeal diyotun akım-gerilim eğrisi

$V_D$ diyotun iki ucu arasındaki potansiyel farktır. İdeal diyotta $V_D$ pozitif yöne gittiğinde (doğru polarma) diyot kısa devredir; eğri dikey eksen boyunca yukarı çıkar. Ters polarmada akım sıfırdır; eğri yatay eksen üzerinde kalır. Hoca bunu Ohm kanunuyla açıkladı: $V = IR$ ifadesinde $R \to 0$ giderken $I$ çok büyür.

> **Ders sonrası not:** Hoca doğru polarmada ideal diyottan geçen akımın "sonsuz" olduğunu söyledi. İdeal diyot sıfır dirençli bir eleman gibi davranır, ama akımın değerini diyota bağlı kaynak ve dirençler belirler. Slayttaki "limited by circuit" ifadesi bunu anlatır.

## 3. Yarı iletken malzemeler ve katkılama

### 3.1 Si, Ge ve GaAs

Bu derste işlenecek bütün yarı iletken elemanlar (diyot, transistör, MOSFET) üç farklı malzemeden üretilebilir: silisyum (Si), germanyum (Ge) ve galyum arsenür (GaAs). Her malzemenin yoğunluğu ve iletim özelliği farklıdır; bu fark elemanların davranışına da yansır.

### 3.2 Katkılama (doping)

Slayttaki ifadeye göre silisyum ve germanyumun elektriksel özellikleri, malzemeye başka maddeler eklenerek iyileştirilir; bu işleme katkılama (doping) denir (ekrandan, 00:40:00). Hoca kelimenin Türkçesi için "takviye etmek" benzetmesini kullandı: sporcunun doping yapması gibi, malzemenin kutuplaşma özelliği dışarıdan eklenen maddeyle değiştirilir.

Yalnız iki tip katkılı yarı iletken malzeme vardır (ekrandan, 00:40:00):

- **n-tipi:** iletim bandında fazla elektron içerir.
- **p-tipi:** valans bandında fazla delik içerir.

> **Ders sonrası not:** Hoca p-tipini "proton ya da pozitif yükleri fazla olan" malzeme diye anlattı. Slaytta yazdığı gibi p-tipinde fazla olan deliklerdir (valence band holes). Delik, elektronun eksik olduğu yerdir ve hareketli bir pozitif yük gibi davranır; protonlar çekirdekte sabittir ve hareket etmez.

### 3.3 Neden iki tip?

Yarı iletken bir elemanın bir tarafı p-tipi, bir tarafı n-tipi olarak üretilir. Bu sayede eleman farklı gerilimlerde farklı tepki verir. Diyot bunun en basit örneğidir: içinde germanyum da silisyum da kullanılsa, bütün diyotların iç yapısında bir tarafı p-tipi, bir tarafı n-tipi olan bir yarı iletken bulunur.

> **Ek bilgi (derste anlatılmadı):** Silisyuma beş değerlikli bir element (örneğin fosfor) eklenince fazla elektron oluşur ve n-tipi malzeme elde edilir. Üç değerlikli bir element (örneğin bor) eklenince elektron eksikliği, yani delik oluşur ve p-tipi malzeme elde edilir.

## 4. p-n eklemi ve tükenme bölgesi

p-tipi ve n-tipi iki parça yan yana getirilip birleştirilince p-n eklemi (p-n junction) elde edilir. Slayttaki açıklamaya göre (ekrandan, 00:45:00):

- n tarafındaki fazla iletim bandı elektronları, p tarafındaki valans bandı deliklerine doğru çekilir.
- n tipindeki elektronlar eklemi geçerek p tipine göç eder (elektron akışı).
- Bu göç sonucunda eklemin p tarafında negatif, n tarafında pozitif yük birikir.
- Sonuçta eklem çevresinde tükenme bölgesi (depletion region) oluşur.

Hoca "depletion" kelimesinin Türkçesini öğrencilere sordu; "tükenme" karşılığında anlaşıldı. Ancak hoca kaynaklarda kavramın "depletion" diye geçtiğini, bu yüzden İngilizcesiyle de akılda tutulmasının faydalı olduğunu söyledi.

Yükler bir süre karşı tarafa geçtikten sonra denge kurulur. Dengede iki bölge arasında yük akışı durur ve bu denge bölgesi bir potansiyel bariyer gibi davranır. Diyotun tek yönlü iletimi bu bariyere dayanır: diyot bu karakteristik üzerine kurularak üretilir.

## 5. Polarma durumları

### 5.1 Polarmasız durum (no bias)

Diyota hiçbir gerilim bağlanmamışsa (diyot "havada" duruyorsa) buna polarmasız durum denir. Tükenme bölgesi dengededir ve net bir iletim olmaz.

### 5.2 Ters polarma (reverse bias)

Hoca öğrencilere sordu: n-tipi tarafa bataryanın artı ucu, p-tipi tarafa eksi ucu bağlanırsa tükenme bölgesine ne olur? Bir öğrenci bölgenin genişleyeceğini söyledi ve hoca bunu doğruladı. Bataryanın eksi ucu p tarafındaki pozitif taşıyıcıları, artı ucu n tarafındaki elektronları kendine çeker; taşıyıcılar eklemden uzaklaşır ve denge bölgesi genişler (ekrandan, 00:50:00). Ortada yük farkı olmayan bölge büyüdüğü için akım oluşmaz. Diyotun ters polarmada açık devre gibi davranmasının nedeni budur.

### 5.3 Doğru polarma (forward bias)

p-tipi tarafa artı, n-tipi tarafa eksi uç bağlanırsa iki uç da taşıyıcıları ekleme doğru iter. Polarmasız durumda kurulmuş olan denge bozulur ve tükenme bölgesi daralır. Bölge tamamen kalktığında iletim başlar. Akım p'den n'ye doğru akar, çünkü devre teorisinin ilk dersinde görüldüğü gibi akımın yönü elektronların hareket yönünün tersidir.

**Soru:** Diyottan bir kez akım geçtikten sonra denge yeniden kurulabiliyor mu, yoksa bozuluyor mu? **Cevap:** Gerilim uygulandığı sürece bariyer bir kez kalktıktan sonra yeniden oluşmaz. Gerilim kaldırılınca bariyer tekrar oluşur.

### 5.4 İletim akımı ve sızıntı akımı

Hoca burada iki akımdan söz etti. Birincisi doğru polarmada devreden beslenen asıl (çoğunluk taşıyıcı) akımdır. İkincisi, diyotun iç dengesinden kaynaklanan çok küçük bir sızıntı akımıdır. Bu akım genelde hesaplara katılmayacak kadar küçüktür. Doğru polarmada tükenme bölgesi daraldığı için asıl akım rahatça geçer. Ters polarmada tükenme bölgesi genişler ve yalnız küçük sızıntı akımı kalır.

Hoca bu ayrıntıların "kesin bilinmesi gereken" değil, genel kültür niteliğinde olduğunu belirtti. Bilinmesi gereken şudur: p tarafı artı, n tarafı eksi gerilimle sürülürse tükenme bölgesi küçülür ve akım geçer; ters polarmada bölge büyür ve akım geçmez.

> **Ders sonrası not:** Hoca tükenme bölgesinin genişlemesini sızıntı akımına bağladı. Tükenme bölgesini genişleten dışarıdan uygulanan ters gerilimdir. Ters yöndeki küçük akım ise azınlık taşıyıcılardan (p tarafındaki elektronlar, n tarafındaki delikler) oluşur ve ters gerilimden büyük ölçüde bağımsız olarak $I_s$ düzeyinde kalır.

Ders sonunda hoca çoğunluk ve azınlık taşıyıcı kavramlarını da kısaca andı: n-tipinde çoğunluk taşıyıcıları elektronlar, p-tipinde deliklerdir; azınlık taşıyıcıları ise tam tersidir.

## 6. Diyot denklemi, eşik gerilimi ve gerçek karakteristik

### 6.1 Diyot denklemi

Ekranda p-n ekleminin akım-gerilim bağıntısı şöyle verildi (ekrandan, 00:55:00):

$$I \approx I_s\left(\exp\frac{eV}{kT} - 1\right)$$

Oda sıcaklığında $e/kT \approx 40\ \text{V}^{-1}$ alınır. Buna göre:

- $V > +0{,}1$ V ise $I \approx I_s \exp(eV/kT) = I_s \exp(40V)$, yani akım gerilimle üstel artar.
- $V < -0{,}1$ V ise $I \approx I_s(0 - 1) = -I_s$, yani ters yönde sabit küçük bir akım akar.
- $I_s$ ters doyma akımıdır (reverse saturation current).

Hoca bu formüllerin ve iç direnç hesaplarının bu ders için ayrıntılı olduğunu, üzerinde fazla durmayacağını söyledi.

> **Ek bilgi (derste anlatılmadı):** $e/kT$ değeri $T = 300$ K için python ile hesaplanınca yaklaşık $38{,}7\ \text{V}^{-1}$, $T = 293$ K için yaklaşık $39{,}6\ \text{V}^{-1}$ çıkar; slayttaki 40 bunun yuvarlanmış hâlidir. Kaynaklarda bu bağıntı büyük olasılıkla Shockley diyot denklemi olarak geçer ve tersi $V_T = kT/e \approx 26$ mV ısıl gerilim diye adlandırılır.

### 6.2 Eşik gerilimi

Doğru polarmada tükenme bölgesi anında yok olmaz. Gerilim sıfırdan başlayıp belirli bir değere ulaşana kadar bölge yavaş yavaş daralır ve akım çok küçük kalır. Gerilim bu eşik değerini geçince bölge ortadan kalkar ve akım birden, üstel olarak artar. Eşik gerilimi malzemeye bağlıdır:

| Malzeme | Eşik gerilimi |
|---|---|
| Germanyum (Ge) | 0,3 V |
| Silisyum (Si) | 0,7 V |
| Galyum arsenür (GaAs) | 1,2 V |

Hoca önce germanyum için 1,2 V dedi, sonra 0,3 - 0,7 - 1,2 sırasını hatırlayarak düzeltti; slayttaki değerler de tablodaki gibidir. Teorik sorularda malzeme belirtilmemişse diyotun 0 V'ta iletime geçtiği varsayılır.

> **Hocanın vurgusu:** Soruda ideal denmiyor da germanyum ya da silisyum diyot deniyorsa, bu eşik gerilimine kesinlikle dikkat edilmelidir. İleriki sorularda bu sık görülecektir.

### 6.3 Gerçek diyot karakteristiği

Ekrandaki "Actual Diode Characteristics" grafiğinde üç bölge gösterilir (ekrandan, 01:05:00):

- **Doğru polarma bölgesi** ($V_D > 0$ V, $I_D > 0$ mA): Akım eşik civarına kadar çok küçüktür, sonra hızla artar. Ticari bir diyotun eğrisi, denklemden çizilen eğrinin biraz sağında kalır.
- **Polarmasız nokta** ($V_D = 0$ V, $I_D = 0$ mA).
- **Ters polarma bölgesi** ($V_D < 0$ V, $I_D = -I_s$): Ters yönde mikroamper altı düzeyde küçük bir akım akar (grafikte yaklaşık $-0{,}1\ \mu$A).

Slayt ayrıca her bölgenin eksen ölçeğine dikkat edilmesini ister: doğru polarmada akım miliamper, ters polarmada mikroamper ölçeğindedir. Hoca bu grafiği ideal diyot eğrisiyle karşılaştırdı: ideal diyot 0 V'ta doğrudan iletir, ters polarmada akımı sıfırdır.

### 6.4 Malzeme seçimi

**Soru:** Eşik gerilimindeki fark diyotun kalitesini mi gösteriyor, yoksa kullanım alanını mı farklılaştırıyor? **Cevap:** Kullanım alanını. Ayrıca fiyatı da etkiler: silisyum doğada daha bol bulunduğu için gündelik hayattaki diyotların çoğu silisyumdandır. Öte yandan çok ideale yakın olması istenen bir tasarımda düşük eşik önemli olabilir. Örneğin devrede çok sayıda diyot varsa her birinin üzerinde eşik gerilimi kadar gerilim düşer ve güç harcanır. Kapalı bir devrede güç korunduğuna göre, diyotlarda harcanan güç dirençlerden alınacak faydalı gücü azaltır. Bu analizde düşük eşik avantajlıdır; ama uygulamaya göre silisyum diyot daha uygun olabilir.

## 7. Zener bölgesi ve zener diyot

### 7.1 Kırılma ve zener bölgesi

Normal diyot teoride ters polarmada hiçbir zaman akım geçirmez. Hoca, ters yönde $-100$ V verilse bile ideal analizde diyotun açık devre sayılacağını söyledi. Pratikte ise diyot bir noktadan sonra kırılır (breakdown), iletime geçer ve zarar görebilir.

Ekrandaki "Zener Region" slaydına göre (ekrandan, 01:10:00):

- Zener bölgesi diyotun ters polarma bölgesindedir.
- Ters gerilim bir noktada o kadar büyür ki diyot kırılır ve ters akım çok hızlı artar.
- Diyotu zener bölgesine sokmayan en büyük ters gerilime **tepe ters gerilimi** (peak inverse voltage, PIV) ya da **tepe ters gerilim** (peak reverse voltage, PRV) denir.
- Diyotu zener bölgesine sokan gerilime **zener gerilimi** ($V_Z$) denir.

### 7.2 Zener diyot

Zener diyot, diyotun iki yönlü kullanılabilmesini sağlayan özel bir diyottur. Doğru polarmada normal diyot gibi davranır ve malzemesine göre eşik geriliminden sonra iletime geçer. Ters polarmada ise üzerindeki zener gerilimi aşılınca yine iletime geçer. Slayta göre zener, zener geriliminde ters polarmada çalıştırılan bir diyottur ve yaygın zener gerilimleri 1,8 V ile 200 V arasındadır (ekrandan, 01:25:00).

Hoca kullanım amacını şöyle anlattı: küçük ters gerilimlerde devreyi korumak, çok yüksek ters gerilimde ise devrenin başka bir biçimde çalışmasını sağlamak istenebilir. Diyot bir if-else yapısına benziyorsa, zener diyot bir switch-case yapısına benzer.

Zener sembolü normal diyota benzer; tek farkı katot çizgisindeki iki çentiktir. Sorularda sembolün yanında $V_Z$ değeri yazılır, çünkü ters gerilim verildiğinde $I_Z$ akımının geçip geçmeyeceğini analiz etmek için zener geriliminin bilinmesi gerekir.

**Soru:** Slayttaki zener diyot sembolünde anot ve katot ters mi çizilmiş? **Cevap:** Hayır, anot ve katot normal diyottaki gibidir. Şekildeki $+$ ve $-$ işaretleri zenerin çalıştığı polarma yönünü gösterir: üstte (katotta) artı, altta (anotta) eksi vardır, yani zener ters polarmadadır. Bu yönde $V_Z$ değerinde gerilim verilirse $I_Z$ akımı akar. Hoca sorunun iyi bir noktayı yakaladığını söyledi.

## 8. Sıcaklık etkisi, diyot direnci ve eşdeğer devre

### 8.1 Sıcaklık

Ortam sıcaklığı diyotu doğrudan etkiler. Sıcaklık arttıkça doğru polarmadaki eşik gerilimi azalır: hocanın örneğine göre germanyumda 0,3 V'tan 0,2 V civarına, silisyumda 0,7 V'tan 0,6 V civarına düşebilir. Sıcaklıktan en çok etkilenen malzeme germanyumdur.

> **Ders sonrası not:** Hoca sıcaklığın ters polarmadaki sızıntı akımının "önüne geçtiğini" söyledi. Ters doyma akımı sıcaklıkla artar (büyük olasılıkla yaklaşık her 10 °C artışta iki katına çıkar); ayrıca ters kırılma gerilimi de sıcaklıkla değişir.

### 8.2 Diyot direnci

DC (doğru akım) koşulunda diyot doğru polarmada iletir, ters polarmada sonsuz direnç gösterir. İletimdeki küçük direnci bulmak için diyot üzerindeki gerilim o anki akıma bölünür:

$$R_D = \frac{V_D}{I_D}$$

Bu direnç malzemeden kaynaklanır. Hoca AC direnç hesabına girmeyeceğini, bu kısmın çok önemli olmadığını söyledi.

### 8.3 Pratik diyot eşdeğer devresi

Bazı simülasyon programları germanyum ya da silisyum diyot modeli sunar, bazıları yalnız ideal diyot verir. İkinci durumda gerçek diyot ekrandaki eşdeğer devreyle modellenir (ekrandan, 01:15:00): ideal diyota seri bağlı bir $V_K = 0{,}7$ V kaynak ve bir $r_{av} = 10\ \Omega$ direnç. $V_K$ kaynağının artı ucu girişe (anoda) bakar; yani kaynak, iletim yönüne karşı koyar. İdeal diyotun iletime geçmesi için giriş geriliminin 0,7 V'u aşması gerekir; giriş 0,5 V ise diyot iletime geçmez. $r_{av}$ değeri, yukarıdaki $V_D/I_D$ hesabından diyotlarda tipik olarak çıkan 10 Ω mertebesindeki iç dirençtir.

> **Ders sonrası not:** Hoca bu modeli anlatırken "germanyum olduğu için 0,7 V" dedi. Slayttaki 0,7 V silisyum diyotun eşik gerilimidir; germanyum için $V_K = 0{,}3$ V alınır.

## 9. Kapasitans, ters toparlanma süresi ve veri sayfası

### 9.1 Diyot kapasitansı

**Soru:** Bir tarafı pozitif, bir tarafı negatif yüklü olduğuna göre diyot küçük bir batarya gibi kullanılabilir mi? Uçlarına bir lamba bağlansa bir süre yanar mı? **Cevap:** Diyotun içinde yük biriktirmeden kaynaklanan bir kapasitans vardır, ama bu bir LED'i yakacak kadar büyük değildir. Hoca kondansatörü hatırlattı: gerilim altında kalan kondansatör yük depolar ve kaynak çekilince paralel bağlı bir LED'i bir süre daha yakabilir (dizüstü bilgisayar şarj adaptörü fişten çekildikten sonra üzerindeki ışığın bir süre yanmaya devam etmesi gibi). Diyotta da ters polarmada eklemde yük birikir ve kapasitans etkisi oluşur, ama değeri çok küçüktür ve uygulamada enerji depolamak için kullanılmaz.

Ders ilerleyince hoca konuya geri döndü: bu kapasitans pikofarad ($10^{-12}$ F) mertebesindedir. Hoca birimin önemine dikkat çekti.

> **Ders sonrası not:** Hoca kapasitansın doğru polarmada ters polarmaya göre çok daha az olduğunu söyledi. Kaynaklarda ters polarmadaki geçiş (tükenme) kapasitansı ile doğru polarmadaki difüzyon kapasitansı ayrılır; büyük olasılıkla doğru polarmadaki difüzyon kapasitansı ters polarmadaki geçiş kapasitansından daha büyüktür.

**Soru:** Ters polarmadan sonra kaynağın yerine düz bir kablo bağlanıp P ve N uçları kısa devre edilse, bir süre sonra iki taraf da nötr olur mu? **Cevap:** Bu durum polarmasız (no bias) durumla aynıdır. Uçlar dışarıdan bağlansa da bağlanmasa da yükler diyotun içinde zaten dengeye gelir.

### 9.2 Ters toparlanma süresi

Pratikte diyot doğru polarmadayken polarma birden ters çevrilir, sonra yeniden doğru polarmaya geçilirse, çok kısa aralıklı bu anahtarlamalarda tükenme bölgesi hemen uyum sağlayamaz. İletimdeki diyot ters polarmaya geçirilince iç yapısından dolayı bir süre ters yönde akım geçirir, sonra normale döner. Bu süre zaman aldığı için çok hızlı anahtarlama yapan devrelerde sıradan diyotlar genelde tercih edilmez.

### 9.3 Veri sayfasındaki bilgiler

Hoca, sensör konusunda veri sayfası okumayı hatırlatarak diyot veri sayfalarında şu bilgilerin bulunduğunu söyledi:

- İleri yön geriliminin (örneğin 0,7 V) sıcaklık ve akımla değişim oranı.
- Belirli sıcaklıklarda geçebilecek en büyük akım (yüksek sıcaklıkta diyot büyük akım taşıyamayabilir).
- Ters akım bilgisi.
- Kapasitans seviyesi (pikofarad mertebesinde, gerilime bağlı grafik olarak).
- Ters toparlanma süresi (reverse recovery time).
- Çalışma sıcaklığı aralığı.

## 10. Diyot sembolü, uçlar ve diyot testi

### 10.1 Anot ve katot

Fiziksel diyot, gövdesinde bir şerit bulunan küçük bir elemandır; gövde renginin önemi yoktur. Şeritli taraf, sembolde çizgiye karşılık gelen katottur. Anot artının, katot eksinin bağlandığı uçtur. Devre şemalarında diyot P-N ya da anot-katot diye etiketlenebilir, ama en yaygın gösterim üçgen ve çizgili semboldür.

> **Hocanın vurgusu:** Anot artı, katot eksidir; çizgili taraf katottur. Bu ezbere bilinmesi gereken bir noktadır. Sorularda polarma yönleri ayrıca yazılmayacak, sembolden anlaşılması beklenecektir.

### 10.2 Diyot testi

Ekrandaki "Diode Testing" slaydında üç yöntem sayılır (ekrandan, 01:20:00):

- **Diyot test cihazı (diode checker):** Multimetrelerde de diyot sembolüyle işaretli bir kademe olarak bulunur. Sağlam bir silisyum diyotta yaklaşık 0,7 V, germanyumda yaklaşık 0,3 V gösterir. Diyot bozuksa bu değer görünmez.
- **Ohmmetre:** Diyot devreden ayrıyken multimetrenin direnç kademesinde artı uç anoda, ortak (COM) uç katoda bağlanır. Ölçü aleti diyottan küçük bir akım geçirdiği için çok küçük bir direnç okunur. Uçlar ters bağlanınca akım geçmeyeceğinden çok yüksek bir direnç okunması beklenir. Böyle değilse diyot bozuktur.
- **Eğri izleyici (curve tracer):** Osiloskop benzeri bir analiz cihazıdır. Ekranda ters yönde çok küçük sızıntılı, eşiğin (örneğin 0,7 V) üstünde birden iletime geçen karakteristik görülürse diyot sağlamdır.

## 11. LED, fotodiyot ve diyot dizileri

Zener dışında başka diyot türleri de vardır:

- **LED (Light Emitting Diode, ışık yayan diyot):** Doğru polarmada ışık yayar. LED ekranlar bu prensiple çalışır. Sembolü diyot sembolüne dışarı doğru ok eklenmiş hâlidir.
- **Fotodiyot (opto diyot):** Üzerine ışık düşünce iletime geçen diyottur.
- **Diyot dizileri (diode array):** Birden fazla diyotun bir arada bulunduğu yapılardır. Yedi parçalı (seven segment) göstergeler yedi diyotun birleşiminden oluşur; hoca bunların ileride (mikroişlemciler konusunda) görüleceğini söyledi.

> **Ders sonrası not:** Hoca LED'i akkor ampule benzetip "aynı mantık" dedi. Akkor ampulde ışık, telin ısınmasından gelir. LED'de ise ışık, eklemde elektronların deliklerle birleşmesi sırasında açığa çıkan enerjiden gelir; ısınma ışığın kaynağı değildir.

## Örnek Sorular

1. (derste sözlü, 00:47:19) Bir diyotun n-tipi bölgesine bataryanın artı ucu, p-tipi bölgesine eksi ucu bağlanırsa tükenme bölgesine ne olur?

   > **Çözüm:** Tükenme bölgesi genişler. Eksi uç p tarafındaki delikleri, artı uç n tarafındaki elektronları eklemden uzağa çeker. Yük farkı olmayan bölge büyür ve akım geçmez; bu ters polarmadır.

2. (derste sözlü, 00:57:26) Diyot, bir tarafı pozitif bir tarafı negatif yüklü olduğu için küçük bir batarya gibi kullanılıp bir lambayı bir süre yakabilir mi?

   > **Çözüm:** Hayır. Diyotta yük birikmesinden doğan bir kapasitans vardır, ama pikofarad mertebesindedir ve bir LED'i yakacak kadar enerji depolamaz.

3. (derste sözlü, 01:10:56) Ge, Si ve GaAs diyotlar arasındaki eşik gerilimi farkı diyotun kalitesini mi gösterir, kullanım alanını mı belirler?

   > **Çözüm:** Kullanım alanını ve maliyeti belirler. Eşikler sırasıyla 0,3 V, 0,7 V ve 1,2 V'tur. Silisyum bol ve ucuz olduğu için yaygındır; çok sayıda diyot kullanılan ve güç kaybının önemli olduğu tasarımlarda düşük eşik tercih edilebilir.

4. (derste sözlü, 01:24:07) Zener diyot sembolünde anot ve katot normal diyota göre ters mi çizilir?

   > **Çözüm:** Hayır, anot ve katot aynıdır. Slayttaki $+$ ve $-$ işaretleri zenerin çalıştığı ters polarma yönünü gösterir (katotta artı); bu yönde $V_Z$ verilince $I_Z$ akar.

## Dersin Toparlaması

Bu derste elektronik devreler dersinin konusu olan yarı iletkenlere giriş yapıldı ve ilk eleman olarak diyot incelendi. İdeal diyotun doğru polarmada kısa devre, ters polarmada açık devre gibi davrandığı; bu davranışın p-tipi ve n-tipi katkılı malzemelerin birleşmesiyle oluşan p-n eklemi ve tükenme bölgesine dayandığı görüldü. Ters polarma tükenme bölgesini genişletir, doğru polarma daraltır; gerçek diyotta iletim malzemeye bağlı bir eşik geriliminden (Ge 0,3 V, Si 0,7 V, GaAs 1,2 V) sonra başlar ve ters yönde küçük bir doyma akımı akar.

Zener diyot ters polarmada zener geriliminde iletime geçen özel bir diyot olarak tanıtıldı. Sıcaklığın eşik gerilimine etkisi, DC direnç, 0,7 V kaynak ve 10 Ω dirençli pratik eşdeğer devre, pikofarad düzeyindeki kapasitans, ters toparlanma süresi, veri sayfası bilgileri, anot-katot gösterimi ve diyot test yöntemleri de ele alındı. Hoca bir sonraki derste diyotun devredeki kullanım alanlarına, kırpıcı (clipper) ve kenetleyici (clamper) devrelere geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
