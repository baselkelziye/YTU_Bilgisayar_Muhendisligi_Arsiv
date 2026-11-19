# Ders 11 Genişletilmiş Notu: BJT DC Kutuplama, Yük Hattı Analizi ve Transistörle Anahtarlama

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kutuplama (Biasing) Nedir?
- 2. npn ve pnp Hatırlatması
- 3. Çalışma Noktası ve Kullanılamayan Bölgeler
- 4. Üç Çalışma Durumu
- 5. Sabit Kutuplama (Fixed Bias)
- 6. Yük Hattı Analizi
- 7. Q Noktasını Etkileyen Devre Değerleri
- 8. Emitörle Kararlı Kılınmış Kutuplama
- 9. Gerilim Bölücü
- 10. Gerilim Bölücülü Kutuplama
- 11. Gerilim Geri Beslemeli Kutuplama
- 12. Transistörün Anahtar Olarak Kullanılması
- Örnek Sorular
- Dersin Toparlaması

## 1. Kutuplama (Biasing) Nedir?

Önceki hafta transistörün yapısı ve çalışma ilkesi gösterilmişti. Bu derste transistörün DC gerilimlerle çalışır seviyeye getirilmesi, yani kutuplanması (biasing) işlendi. Slayttaki tanıma göre kutuplama, transistörü iletime sokup AC işareti yükseltebilmesi için uygulanan DC gerilimlerdir (ekrandan, 00:05:00). Transistör önce DC ile belli bir noktada çalışır hale getirilir; bunun üzerine verilen daha küçük AC işaretler hareket edebilir ve kuvvetlendirilebilir.

Hoca bunu işaretlerin sınıflandırılmasıyla bağladı. Herhangi bir $x(t)$ işareti iki kısımdan oluşur:

- **DC kısım:** İşaretin ortalamasıdır. Sıfır frekanslı ($f = 0$) bileşendir; işareti sanki yukarı kaldıran kısımdır.
- **AC kısım:** Sıfır ortalamalı, değişken kısımdır. $f > 0$ olan sinüzoidal bileşenlerin toplamından oluşur.

Bir işareti sıfır seviyesinde değil de yukarıda görüyorsanız, o işaretin bir **DC ofseti** vardır. "Ofset" kelimesi burada işareti yukarı taşıma anlamında kullanılır. Kutuplama da bu anlamda bir DC besleme, DC gerilimlemedir: transistör DC ile çalışır konuma getirildikten sonra üzerine AC işaret bindirilir.

## 2. npn ve pnp Hatırlatması

İki tip transistör vardı. Sembolde emitör ucundaki ok her zaman N tarafını gösterir:

- Ok dışarı bakıyorsa emitör N'dir; kolektör de dış katman olduğu için N'dir, baz P kalır. Bu **npn** transistördür.
- Ok içeri bakıyorsa baz N tipindedir; kolektör ve emitör P'dir. Bu **pnp** transistördür.

Ders boyunca bütün devreler npn üzerinden anlatıldı. Bir npn'de kolektörden giren akım $I_C$, bazdan giren akım $I_B$, emitörden çıkan akım $I_E$'dir ve

$$I_E = I_C + I_B$$

bağıntısı geçerlidir. $I_B$ çok küçük olduğu için $I_C \approx I_E$ alınır. Kolektör-emitör arasındaki gerilim $V_{CE}$, baz-emitör arasındaki gerilim $V_{BE}$'dir. $V_{BE}$ yaklaşık 0,7 V'u geçince transistör akım akıtmaya başlar; iletimdeyken baz-emitör arası bir diyot gibi düşünülür.

## 3. Çalışma Noktası ve Kullanılamayan Bölgeler

DC gerilimlerle belirlenen ve transistörün çevresinde çalışacağı noktaya **çalışma noktası** ya da işletme noktası denir. İngilizcesi quiescent point'tir, kısaca **Q noktası** (ekrandan, 00:10:00). Amaç, transistörün çalışabileceği uygun bir nokta belirlemektir.

Bu nokta çıkış karakteristiği üzerinde gösterilir. Yatay eksen $V_{CE}$, dikey eksen $I_C$'dir. Hoca bu eksenlerin seçilme nedenini şöyle açıkladı: transistörden güç aktarımı ve çıkış kolektör tarafından yapılır; bu yüzden dışarı verilen akım $I_C$ ve kolektör-emitör gerilimi $V_{CE}$ önemlidir. Slayttaki grafikte her biri bir $I_B$ değerine ait mavi eğriler vardır: $I_B = 0\,\mu\text{A}$'den $80\,\mu\text{A}$'e kadar $10\,\mu\text{A}$ adımlarla (ekrandan, 00:10:00).

Grafikte kullanılmayan bölgeler şunlardır:

- **Kesim (cutoff) bölgesi:** $V_{CE}$ herhangi bir değeri alırken $I_C$'nin neredeyse sıfır olduğu alt şerittir. Transistör dışarı akım vermez.
- **Doyum (saturation) bölgesi:** $I_C$'nin olabildiğince çok aktığı ama $V_{CE}$'nin sıfıra yakın kaldığı sol şerittir. Bu durumda gerilim daha çok yüke düşer.
- **Güç sınırının dışı:** Bir dirençte güç $P = V \cdot I$'dır. Transistörde de güç $P = V_{CE} \cdot I_C$'dir ve transistörün dayanabileceği gücün altında kalmalıdır; örneğin transistör 30 W'lık ise $V_{CE} I_C$ çarpımı 30 W'ın altında tutulur (hoca derste tahtaya $V_{CE} \cdot I_C < V_P$ yazdı, ekrandan, 00:15:00). Bu sınır grafikte $P_{C\max}$ eğrisini oluşturur.

Slayttaki grafikte ayrıca $I_{C\max} = 25$ mA ve $V_{CE\max} = 20$ V sınırları ile A, B, C, D örnek noktaları işaretlidir (ekrandan, 00:10:00). Bütün bu bölgeler çıkarıldığında geriye beyaz bir çalışma bölgesi kalır; Q noktası bunun içinde seçilir.

> **Ek bilgi (derste anlatılmadı):** Slayttaki A, B, C, D noktaları Boylestad kitabındaki örnekten gelir. Büyük olasılıkla A kutuplanmamış (sıfır) durumu, B aktif bölgenin ortasına yakın iyi bir çalışma noktasını, C ve D ise kesime ya da güç sınırına yakın, salınımı sınırlayan noktaları göstermek için konmuştur.

## 4. Üç Çalışma Durumu

Slayt, transistörün üç çalışma durumunu eklemlerin kutuplanmasıyla tanımlar (ekrandan, 00:15:00):

- **Aktif ya da doğrusal (linear) bölge:** Baz-emitör eklemi ileri kutuplanmıştır, akım akıtır. Baz-kolektör eklemi ters kutuplanmıştır; npn yapıda baz P, kolektör N olduğundan bu eklem akım akıtmaz. Yükselteç olarak çalışma bu bölgededir.
- **Kesim bölgesi:** Baz-emitör eklemi ters kutuplanmıştır; $V_{BE} < 0{,}7$ V ve akım akmaz.
- **Doyum bölgesi:** Baz-emitör eklemi 0,7 V'u geçmiş, iletimdedir; baz-kolektör eklemi de ileri kutuplanmıştır. Transistör en büyük akımı akıtır.

Bundan sonra hoca, DC çalışma karakteristiklerini belirlemek için birkaç kutuplama yapısı göstereceğini söyledi: sabit kutuplama, emitörle kararlı kılınmış devre, gerilim bölücülü devre ve gerilim geri beslemeli devre. <!-- BELİRSİZ: Hoca "beş tane yapı" dedi; altyazıda listenin beşinci elemanı net değil ("kollektör-emitör loop" adı sabit kutuplamanın slayt başlığı da olabilir). -->

## 5. Sabit Kutuplama (Fixed Bias)

### 5.1 Devre

Slayttaki devrede bir npn transistör vardır (ekrandan, 00:20:00):

- $V_{CC}$ kaynağı $R_B$ direnci üzerinden baza bağlanır; bu direnç üzerinden baza $I_B$ akımı gönderilerek $V_{BE}$ 0,7 V'un üzerine çıkarılır.
- $V_{CC}$ ayrıca $R_C$ direnci üzerinden kolektöre bağlanır; buradan $I_C$ akımı akar.
- Emitör doğrudan toprağa bağlıdır.
- AC giriş işareti $C_1$ kondansatörü üzerinden baza verilir, AC çıkış işareti $C_2$ kondansatörü üzerinden kolektörden alınır.

Bu tür yapılarda AC işaret genellikle bazdan verilir, çıkış kolektörden alınır. Kondansatörlerin görevi işaretin DC bileşenini süzmektir. Hoca bunu tahtada gösterdi: kondansatörün önündeki A noktasında işaretin hem DC hem AC bileşeni vardır; arkasındaki B noktasında DC yok edilmiştir, yalnız AC bileşen kalır. Böylece içeri yalnız AC işaret girer, dışarı da yalnız AC işaret çıkar.

$V_{CC}$ yazıldığında aslında artı ucu o noktaya, eksi ucu toprağa bağlı bir DC kaynak kastedilir; şemada yalnız tek bir nokta çizilir. Örneğin 10 V bağlanırsa o nokta toprağa göre +10 V'tadır.

### 5.2 Baz-emitör çevresi

Hoca iki yol üzerinden çözüm yaptı. Birinci yol $V_{CC}$'den $R_B$ ve baz-emitör eklemi üzerinden toprağa gider. Hocanın tercih ettiği yazım şudur: $V_{CC}$ ucu ile toprak arasındaki her kol aynı gerilimi taşıdığından, kol üzerindeki gerilimler toplanıp $V_{CC}$'ye eşitlenir. Akım yönünde geçilen direnç için $+IR$, artı ucundan girilen gerilim için $+V$ yazılır:

$$V_{CC} = I_B R_B + V_{BE}$$

Kirchhoff çevre denklemiyle sıfıra eşitlenerek de yazılabilir; o yazımda eksiden girilen kaynak artı, akım yönünde geçilen direnç eksi alınır: $V_{CC} - I_B R_B - V_{BE} = 0$. İki yazım aynı sonucu verir:

$$I_B = \frac{V_{CC} - V_{BE}}{R_B}$$

Burada $V_{BE}$ genellikle 0,7 V alınır. Bu hesapta kolektör tarafından baza hiç akım gelmiyormuş gibi düşünülür.

### 5.3 Kolektör-emitör çevresi

İkinci yol $V_{CC}$'den $R_C$ ve kolektör-emitör üzerinden toprağa gider (ekrandan, 00:25:00). Akım aşağı doğru aktığı için $R_C$ üzerinde $V_{R_C} = I_C R_C$ gerilimi düşer:

$$V_{CC} = I_C R_C + V_{CE} \quad\Rightarrow\quad V_{CE} = V_{CC} - I_C R_C$$

Kolektör akımı baz akımından bulunur:

$$I_C = \beta I_B$$

$\beta = I_C / I_B$ oranı, baz akımının kaç kat kuvvetlendirildiğini gösterir. Bazdan gelen akım çok küçüktür; transistör onu kuvvetlendirip bir $I_C$ akımına dönüştürür ve bu akım çıkışa gidiyormuş gibi düşünülebilir.

### 5.4 Doyum durumu

Doyumda $V_{CE}$ neredeyse sıfırdır; transistörün C ve E uçları sanki kısa devredir. Bu durumda $R_C$ doğrudan toprağa bağlanmış gibi olur ve en büyük akım akar:

$$I_C = \frac{V_{CC}}{R_C}$$

Doyum dışında ise transistör üzerinde gerilim düştükçe $R_C$'ye düşen gerilim azalır, dolayısıyla $I_C$ de azalır.

## 6. Yük Hattı Analizi

Karakteristikteki mavi eğriler devreye uygulanan $I_B$'ye göre çizilir ve bize hazır verilir. Bulunan denklemlerden yararlanarak **yük hattı analizi** (load line analysis) yapılır (ekrandan, 00:30:00).

Yük hattının iki ucu vardır:

- **Doyum ucu ($I_{C\,sat}$):** $V_{CE} = 0$ V alınır; $V_{CC} = I_C R_C$ olduğundan $I_C = V_{CC}/R_C$.
- **Kesim ucu ($V_{CE\,cutoff}$):** $I_C = 0$ mA alınır; denklemden $V_{CE} = V_{CC}$ kalır.

$V_{CE} = V_{CC} - I_C R_C$ denkleminin değişkenleri $I_C$ ve $V_{CE}$'dir. $y$ yerine $I_C$, $x$ yerine $V_{CE}$ konursa birinci dereceden bir denklem, yani bir doğru denklemi elde edilir. Bu doğru iki uç noktası birleştirilerek çizilir. Öte yandan $I_B$ birinci denklemden bulunur ve hangi mavi eğrinin geçerli olduğunu belirler. Yük hattının bu $I_{BQ}$ eğrisini kestiği nokta **Q noktası**, yani çalışma noktasıdır; transistör bu noktanın çevresinde çalışır.

Slayttaki özet de bunu söyler: Q noktası, $R_B$'nin $I_B$ değerini, $I_B$'nin de $V_{CE}$ ve $I_C$ değerlerini belirlediği çalışma noktasıdır (ekrandan, 00:30:00).

Hoca bu haftalarda devrelerin çözümüyle ilgili temel kuralların anlatılacağını, sayı değeri verilmeden teorik çözüm yapıldığını, asıl soru çözümlerinin sonraki haftalarda bu devreler üzerine yapılacağını söyledi.

## 7. Q Noktasını Etkileyen Devre Değerleri

Q noktası $V_{CC}$, $R_C$ ve $I_B$ değerlerinden etkilenir. <!-- BELİRSİZ: altyazıda üçüncü değer "IC" yazılmış; anlatımın devamına göre büyük olasılıkla IB kastedildi. -->

- **$V_{CC}$'nin etkisi:** $R_C$ sabitken $V_{CC}$ büyüdükçe dikey eksendeki $V_{CC}/R_C$ ucu yukarı kayar; yatay eksendeki $V_{CE} = V_{CC}$ ucu sağa kayar. Böylece Q noktası $V_{CC}$ büyüdükçe sağa, küçüldükçe sola kayar.
- **$R_C$'nin etkisi:** Dikey eksendeki uç $V_{CC}/R_C$'dir. Payda küçülürse bu değer büyür. Slaytta $R_3 > R_2 > R_1$ için çizilen üç yük hattında en küçük direnç $R_1$'in ucu en yukarıda, $R_3$'ün ucu en aşağıdadır (ekrandan, 00:35:00). Yatay uç $V_{CC}$ değişmez. Kolektör direnci küçüldükçe yük hattı dikleşir ve Q noktası yukarı kayar; direnç büyüdükçe eğim azalır ve Q noktası aynı $I_{BQ}$ eğrisi üzerinde sola kayar.
- **$I_B$'nin etkisi:** Mavi eğriler sabit olarak verilmiştir. Bazdan akan akım arttıkça daha üstteki eğri geçerli olur ve Q noktası yük hattı üzerinde yukarılara kayar.

## 8. Emitörle Kararlı Kılınmış Kutuplama

### 8.1 Devrenin farkı

Hoca devreyi gösterip öncekinden farkını sordu. Bir öğrencinin cevabı:

**Soru:** Bu devrenin bir önceki devreden farkı nedir? **Cevap (öğrenci):** Topraktan önce bir direnç daha var. Hoca doğruladı: emitör bacağına bir $R_E$ direnci eklenmiştir ve bu direnç devreyi emitörle kararlı kılınmış (emitter-stabilized) bir devre haline getirir.

### 8.2 Baz-emitör çevresi

Yine iki koldan eşitlik çıkarılır (ekrandan, 00:40:00). Hocanın yazımıyla baz kolu:

$$V_{CC} = I_B R_B + V_{BE} + I_E R_E$$

$R_E$ üzerinden akım aşağı doğru akıyorsa üzerinde artısı yukarıda bir $V_{R_E}$ gerilimi vardır ve ona artıdan girilir; bu gerilim $I_E R_E$'dir.

Şimdi $I_E$ yerine $I_B$ cinsinden ifade yazılır:

$$I_E = I_C + I_B, \qquad \beta = \frac{I_C}{I_B} \;\Rightarrow\; I_E = \beta I_B + I_B = (\beta + 1) I_B$$

Yerine konunca tek değişken $I_B$ kalır:

$$V_{CC} - I_B R_B - (\beta + 1) I_B R_E = 0 \quad\Rightarrow\quad I_B = \frac{V_{CC} - V_{BE}}{R_B + (\beta + 1) R_E}$$

$R_E$, $I_B$ ifadesinin paydasına $(\beta + 1)$ katıyla katkıda bulunur.

> **Ders sonrası not:** Slayttaki Kirchhoff denklemi "$+V_{CC} - I_E R_E - V_{BE} - I_E R_E = 0$" biçiminde görünüyor (ekrandan, 00:40:00). İlk terim büyük olasılıkla slayt yazım hatasıdır; doğrusu $+V_{CC} - I_B R_B - V_{BE} - I_E R_E = 0$'dır. Hocanın tahtaya yazdığı $V_{CC} = R_B I_B + V_{BE} + R_E I_E$ ifadesi doğrudur.

### 8.3 Kolektör-emitör çevresi ve düğüm gerilimleri

İkinci yoldan:

$$V_{CC} = I_C R_C + V_{CE} + I_E R_E$$

$I_E \approx I_C$ kabul edilirse:

$$V_{CE} = V_{CC} - I_C (R_C + R_E)$$

Hoca düğüm gerilimlerinin anlamını da açıkladı. $V_{AB}$ iki indisli yazıldığında $V_A - V_B$ demektir. Tek indis kullanılıyorsa $V_A - V_{\text{toprak}}$ kastedilir; toprak sıfır olduğundan bu, A noktasının toprağa göre gerilimidir. Buna göre:

- $V_E = I_E R_E$: emitör direnci üzerinde düşen gerilim.
- $V_C = V_{CC} - I_C R_C$: kolektör noktasının toprağa göre gerilimi.
- $V_B = V_{BE} + V_E$: baz noktasından toprağa doğru gidilerek bulunur.

### 8.4 Kararlılık

"Stability" kelimesi, devredeki akım ve gerilimlerin genel olarak sabit kaldığı bir durumu ifade eder. Emitör direnci eklendiğinde bu akımlar geniş bir sıcaklık aralığında ve geniş bir $\beta$ aralığında yaklaşık sabit kalır. Bu yüzden devreye kararlı kılınmış devre denir.

> **Hocanın vurgusu:** Transistörlü bir devrede emitör bacağına eklenen bir direnç, transistörün kararlılığını artırır.

> **Ek bilgi (derste anlatılmadı):** Kararlılığın nedeni bir tür negatif geri beslemedir. Sıcaklık artıp $I_C$ yükselirse $V_E = I_E R_E$ artar; $V_{CC}$ sabit olduğundan $R_B$ üzerindeki gerilim, dolayısıyla $I_B$ azalır ve bu da $I_C$'deki artışı kısmen dengeler. $I_B$ formülünde $(\beta+1)R_E$ terimi $R_B$'ye göre büyükse $I_C = \beta I_B$ yaklaşık $\beta$'dan bağımsız hale gelir.

### 8.5 Yük hattı

$I_B$ ilk denklemden bulunup eğrilerden biri seçilir; yük hattının iki ucu yine iki uç durumdan bulunur (ekrandan, 00:45:00):

- **Doyum:** $V_{CE} \approx 0$ alınır; $V_{CC} = I_C (R_C + R_E)$, yani $I_{C\,sat} = \dfrac{V_{CC}}{R_C + R_E}$.
- **Kesim:** $I_C = 0$ alınır; $V_{CE\,cutoff} = V_{CC}$.

## 9. Gerilim Bölücü

### 9.1 Temel devre

Gerilim bölücülü kutuplamaya geçmeden önce hoca gerilim bölücünün ne olduğunu tahtada anlattı (ekrandan, 00:50:00). Bir $V_{in}$ (tahtada $V_c$) kaynağı seri $R_1$ ve $R_2$ dirençleri üzerinden toprağa bağlanır; çıkış $V_{out}$, iki direncin birleşim noktasından alınır. Tahtadaki sayılar: $V_{in} = 10$ V, $R_1 = 3\,\Omega$, $R_2 = 7\,\Omega$. Amaç, 10 V'un ne kadarının $V_{out}$'a aktarıldığını iki dirençle gerilimi bölerek göstermektir.

### 9.2 Türetme

Çıkıştan henüz akım çekilmediği, yalnız gerilim alındığı düşünülür. Bu durumda $R_1$ ve $R_2$'den aynı akım geçer: $i_{R_1} = i_{R_2}$ (ekrandan, 00:55:00).

- $R_2$'nin üst ucunda $V_{out}$ gerilimi vardır, alt ucu topraktadır: $i_{R_2} = V_{out}/R_2$.
- $R_1$'in akımı, iki ucu arasındaki gerilim farkının $R_1$'e bölümüdür: $i_{R_1} = (V_{in} - V_{out})/R_1$.

Eşitlenip düzenlenir:

$$\frac{V_{in} - V_{out}}{R_1} = \frac{V_{out}}{R_2} \;\Rightarrow\; \frac{V_{in}}{R_1} = \frac{V_{out}}{R_2} + \frac{V_{out}}{R_1} = V_{out}\,\frac{R_1 + R_2}{R_1 R_2}$$

$$\frac{V_{out}}{V_{in}} = \frac{R_2}{R_1 + R_2} \qquad\text{ya da}\qquad V_{out} = \frac{R_2}{R_1 + R_2}\, V_{in}$$

Hoca son adımda önce yanlış söyleyip hemen düzeltti; doğru sonuç yukarıdakidir. Bu, genel gerilim bölücü yapısıdır.

### 9.3 Sayısal örnek

Hocanın günlük hayat örneği: elinizde 10 voltluk bir pil var ama size 7 volt lazım. Bunu iki dirençle yapabilirsiniz.

- **Verilen:** $V_{in} = 10$ V, $R_1 = 3\,\Omega$, $R_2 = 7\,\Omega$.
- **İşlem:** $R_1 + R_2 = 10\,\Omega$, $V_{out} = \dfrac{7}{10} \cdot 10 = 7$ V.

Dirençler değiştirilerek $V_{in}$'in istenen kısmı çıkışa aktarılır:

- İkisi de $5\,\Omega$ ise $V_{out} = \dfrac{5}{10}\cdot 10 = 5$ V; gerilimin yarısı $R_1$'de, yarısı $R_2$'de kalır (tahtada $V_{out} = \frac{5}{10} \cdot V_{in}$, ekrandan, 00:55:00).
- $R_2 = 1\,\Omega$, $R_1 = 9\,\Omega$ ise $V_{out} = \dfrac{1}{10}\cdot 10 = 1$ V; 10 voltun 1 voltu $R_2$'de, 9 voltu $R_1$'de harcanır.

Üç sonucun hepsi python ile kontrol edildi; her durumda akım $10/(R_1+R_2) = 1$ A'dir.

## 10. Gerilim Bölücülü Kutuplama

### 10.1 Devre

Aradan sonra hoca gerilim bölücülü kutuplama devresine döndü (ekrandan, 01:05:00). $V_{CC}$, $R_1$ üzerinden baz düğümüne, oradan $R_2$ üzerinden toprağa gider. Kolektörde $R_C$, emitörde $R_E$ vardır; AC giriş $v_i$ $C_1$ ile baza, çıkış $v_o$ $C_2$ ile kolektörden alınır. Önceki devrelerden farkı, $V_{CC}$'den baza doğrudan inilmemesi, iki ayarlanabilir direnç üzerinden inilmesidir. Bölücünün çıkış noktası $V_B$, yani bazdır.

### 10.2 Yaklaşık analiz

Bu tür devrelerde bazı varsayımlarla yaklaşık analiz yapılır. Gerilim bölücüde $I_1 = I_2$ demiştik; burada baz düğümünden transistöre de bir $I_B$ akımı akar. $I_B$ çok küçükse, yani $I_B \ll I_1$ ve $I_1 \cong I_2$ ise, baz akımı sıfır kabul edilir ve devre düz bir gerilim bölücü gibi çözülür (ekrandan, 01:05:00):

$$V_B = \frac{R_2\, V_{CC}}{R_1 + R_2}$$

Slayttaki koşul $\beta R_E > 10 R_2$'dir. Bu koşul sağlanıyorsa:

$$V_E = V_B - V_{BE}, \qquad I_E = \frac{V_E}{R_E}$$

Hoca bu koşulun ayrıntısına girmedi; $\beta R_E$ çok büyükse her durumda bu şekilde kabul edileceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** $\beta R_E > 10 R_2$ koşulunun anlamı şudur: bazdan bakıldığında emitör direnci yaklaşık $\beta R_E$ büyüklüğünde bir direnç gibi görünür. Bu direnç $R_2$'nin en az on katıysa $R_2$ ile paralel bağlanması bölücüyü fark edilir ölçüde bozmaz ve $I_B$'yi yok saymak yaklaşık doğru kalır.

### 10.3 Kolektör-emitör çevresi ve yük hattı

Kolektör kolundan:

$$V_{CC} = I_C R_C + V_{CE} + I_E R_E$$

$I_E \cong I_C$ ile:

$$V_{CE} = V_{CC} - I_C (R_C + R_E)$$

Yük hattı analizi aynı mantıkla yapılır: $I_C = 0$ alınınca $V_{CE} = V_{CC}$ (kesim), $V_{CE} = 0$ alınınca $I_C = \dfrac{V_{CC}}{R_C + R_E}$ (doyum). İkisi de $V_{CE}$ için bulunan denklemden elde edilir.

## 11. Gerilim Geri Beslemeli Kutuplama

Bu devrede baz beslemesi doğrudan $V_{CC}$'den değil, $V_{CC}$'den sonraki bir noktadan, kolektör ucundan alınır; $R_B$ kolektör ile baz arasına bağlanır. Kolektör direncinden geçen akım $I'_C$ ile gösterilir; bu akım hem kolektöre hem $R_B$ üzerinden baza gider:

$$I'_C = I_C + I_B$$

$I_B$ çok küçükse $I'_C \approx I_C$ alınarak çözüm yapılır.

Baz kolundan, hocanın yöntemiyle:

$$V_{CC} = I'_C R_C + I_B R_B + V_{BE} + I_E R_E$$

$I'_C \approx I_C$, $I_E \approx I_C$ ve $I_C = \beta I_B$ yazılıp $I_B$ bir tarafa çekilir (ara adım eklendi):

$$I_B = \frac{V_{CC} - V_{BE}}{R_B + \beta (R_C + R_E)}$$

<!-- BELİRSİZ: Bu slaytın karesi yok; IB ifadesi hocanın kurduğu çevre denkleminden ve söylediği yaklaşıklıklardan türetildi, slaytta (β+1) gibi farklı bir biçimde olabilir. -->

Kolektör kolundan:

$$V_{CC} = I'_C R_C + V_{CE} + I_E R_E \;\Rightarrow\; V_{CE} = V_{CC} - I_C (R_C + R_E)$$

Yük hattında yine sırasıyla $I_C = 0$ ve $V_{CE} = 0$ verilerek uç noktalar bulunur ve çıkış hesaplanır. Hoca bunların ayrı örneklerinin ileride görüleceğini söyledi.

## 12. Transistörün Anahtar Olarak Kullanılması

### 12.1 Mantık devresi olarak transistör

Slaytta yalnız DC kaynak uygulanan transistörlerin elektronik anahtar olarak kullanılabileceği yazar (ekrandan, 01:10:00). Devre değerleri: $V_{CC} = 5$ V, $R_C = 0{,}82$ k$\Omega$, $R_B = 68$ k$\Omega$, $h_{FE} = 125$. Girişe 0 V ile 5 V arasında değişen bir kare dalga (mantık 0, 1, 0) verilir; çıkış $V_C$ kolektörden alınır.

- **Giriş 5 V:** Bazdan $I_B$ akar, $V_{BE}$ eşiği aşılır ve transistör doyuma gider. İletime geçtiği anda $V_{CE}$ çok küçük bir değere iner; çıkış sıfıra çekilir, $V_C \approx 0$ V.
- **Giriş 0 V:** $I_B$ akmaz, $I_C$ de sıfırdır. $R_C$'nin iki ucu (tahtada A ve B noktaları) arasında gerilim düşmez; çıkış doğrudan $V_{CC}$ olur, $V_C = 5$ V.

İletimde çıkış 0, giriş 0 iken çıkış 5 V'tur. Mantık devresi olarak düşünülürse bu bir NOT (değil) kapısıdır.

> **Ders sonrası not:** Altyazıda kapının adı "NAT kapısı" diye geçiyor. Tek girişli ve girişi tersine çeviren bu devre bir NOT kapısıdır (evirici); hoca büyük olasılıkla "NOT" dedi.

Transistörlerle bu şekilde NOT, AND gibi basit kapılar oluşturulur; silisyum yarı iletken yongaların içinde mantık kapıları bu yolla kurulur. Mantık kapıları birleştirilerek RAM'ler, ROM'lar ve mikroişlemciler yapılır.

### 12.2 Anahtarlama süreleri

Transistöre 0'dan 1'e geçen bir giriş uygulandığında çıkış gerçekte anında değişmez; elektronik devrenin yükselmesi daha yavaştır.

- **Açılma:** Çıkışın son değerinin %90'ına ulaşması için geçen süreye $t_{on}$ denir. Bu süre bir gecikme süresi $t_d$ (delay) ile yükselme süresi $t_r$ (rise) toplamıdır: $t_{on} = t_r + t_d$.
- **Kapanma:** Transistör kapatıldığında çıkış ideal çizgideki gibi anında düşmez; bir süre kalır, sonra yavaşça azalır. %10 seviyesine kadar düşüş kısmına $t_f$ (fall) denir. Öncesindeki gecikme $t_s$'dir ve $t_{off} = t_s + t_f$ olur.

Demek ki transistörde ideal dik kenarlı anahtarlama mümkün değildir; gerçek davranış belli bir eğim ve gecikmeyle olur. Çok hızlı devrelerde bu süreler çok daha kısadır. <!-- BELİRSİZ: altyazıda "T10" ve "Tse" geçiyor; bunların t_on ve t_s olduğu slayt anlatımından çıkarıldı, bu anın karesi yok. -->

> **Ek bilgi (derste anlatılmadı):** $t_s$ depolama süresidir (storage time). Doyumdaki transistörün bazında biriken fazla yüklerin boşalması zaman aldığı için kapanma, açılmaya göre genellikle daha uzun sürer.

### 12.3 pnp

Ders boyunca bütün devreler npn'e göre çözüldü. pnp transistörlü devreler npn'in tam tersi kutuplarla (gerilim yönleri ve akım yönleri ters) çalışır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:50:00 ve 00:55:00): 10 V'luk bir kaynak, seri $R_1 = 3\,\Omega$ ve $R_2 = 7\,\Omega$ dirençleriyle toprağa bağlanıyor. Çıkış $R_2$ üzerinden alınıyor. $V_{out}$ nedir? Dirençler $5\,\Omega$ ve $5\,\Omega$, ya da $R_1 = 9\,\Omega$, $R_2 = 1\,\Omega$ olursa ne olur?

> **Çözüm (derste verildi):** $V_{out} = \dfrac{R_2}{R_1+R_2} V_{in}$. İlk durumda $\dfrac{7}{10}\cdot 10 = 7$ V, ikincide $\dfrac{5}{10}\cdot 10 = 5$ V, üçüncüde $\dfrac{1}{10}\cdot 10 = 1$ V.

**Soru 2** (derste sözlü, 00:37:01): Emitörle kararlı kılınmış kutuplama devresinin sabit kutuplama devresinden farkı nedir?

> **Çözüm (derste verildi):** Emitör ile toprak arasına bir $R_E$ direnci eklenmiştir. Bu direnç $I_B$ ifadesinin paydasına $(\beta+1)R_E$ olarak girer ve akımları sıcaklık ve $\beta$ değişimine karşı daha kararlı kılar.

**Soru 3** (ekrandan, 01:10:00): Slayttaki anahtarlama devresinde $V_{CC} = 5$ V, $R_C = 0{,}82$ k$\Omega$, $R_B = 68$ k$\Omega$, $h_{FE} = 125$. Giriş 5 V iken transistör doyuma girer mi?

> **Çözüm (derste verilmedi):** Derste devre yalnız nitel olarak anlatıldı. $V_{BE} = 0{,}7$ V alınırsa $I_B = \dfrac{5 - 0{,}7}{68\,\text{k}\Omega} \approx 63{,}2\,\mu\text{A}$. Aktif bölge varsayımıyla $\beta I_B = 125 \cdot 63{,}2\,\mu\text{A} \approx 7{,}90$ mA olurdu. Oysa devrenin verebileceği en büyük akım $I_{C\,sat} = \dfrac{5}{0{,}82\,\text{k}\Omega} \approx 6{,}10$ mA'dir. $\beta I_B > I_{C\,sat}$ olduğundan transistör doyumdadır, $I_C \approx 6{,}10$ mA ve $V_C \approx 0$ V. Doyum için gereken en küçük baz akımı $6{,}10\,\text{mA}/125 \approx 48{,}8\,\mu\text{A}$'dir. Değerler python ile hesaplandı.

## Dersin Toparlaması

Bu derste transistörün DC kutuplanması işlendi. Kutuplamanın amacı, transistörü aktif bölgede bir çalışma noktasına (Q noktası) getirip AC işaretin bu noktanın çevresinde kuvvetlendirilmesini sağlamaktır. Q noktası, kesim ve doyum bölgeleri ile güç sınırı dışında kalan bölgede seçilir. Sabit kutuplamada $I_B = (V_{CC} - V_{BE})/R_B$, $I_C = \beta I_B$ ve $V_{CE} = V_{CC} - I_C R_C$ bulunur; $V_{CE} = V_{CC} - I_C R_C$ doğrusu yük hattıdır ve uçları $V_{CC}/R_C$ ile $V_{CC}$'dir. Emitör direnci eklenince $I_B$ paydasına $(\beta+1)R_E$ girer, yük hattının doyum ucu $V_{CC}/(R_C+R_E)$ olur ve devre kararlı hale gelir. Gerilim bölücülü kutuplamada baz akımı ihmal edilip $V_B = R_2 V_{CC}/(R_1+R_2)$, $V_E = V_B - V_{BE}$, $I_E = V_E/R_E$ hesaplanır. Gerilim geri beslemeli devrede baz beslemesi kolektörden alınır. Son olarak transistörün DC ile anahtar olarak kullanıldığı, girişi tersine çeviren bir devre ve gerçek anahtarlamadaki gecikme, yükselme ve düşme süreleri gösterildi.

Hoca, vize haftasından sonraki derslerde bu devreler üzerine transistör ve diyot sorularının ayrıntılı örneklerle çözüleceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
