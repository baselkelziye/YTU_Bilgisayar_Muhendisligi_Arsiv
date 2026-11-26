# Ders 9 Genişletilmiş Notu: Kırpıcı Örnekleri, Kenetleyiciler, Zener Diyot ve BJT'ye Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kırpıcı Devrelerin Tekrarı ve Paralel Kırpıcı Örneği
- 2. Diyotu Ters Çevirince: İkinci Kırpıcı Örneği
- 3. Kenetleyici (Clamper) Devreler
- 4. Zener Diyot ile Gerilim Sınırlama
- 5. Diyotların Diğer Uygulamaları
- 6. Transistörün Yapısı: pnp ve npn
- 7. Transistör Sembolü ve Akım Bağıntıları
- 8. Bağlantı Biçimleri ve Çalışma Bölgeleri
- 9. Transistörle Gerilim Yükseltme
- 10. Alfa ve Beta Katsayıları
- 11. Veri Sayfası, Transistör Testi ve Kılıflar
- Örnek Sorular
- Dersin Toparlaması

## 1. Kırpıcı Devrelerin Tekrarı ve Paralel Kırpıcı Örneği

Ders, bir önceki derste anlatılan kırpıcı (clipper, kesici) devrelerin kısa bir tekrarıyla başladı. Hoca, slayttaki kırpıcı özetini açarak diyotların bazen seri, bazen paralel, bazen ters yönde bağlandığını ve bunlara DC gerilim kaynakları eklendiğinde birbirinden çok farklı çıkışlar elde edildiğini hatırlattı (ekrandan, 00:05:00). Slayttaki özet tablosunda ideal diyotlu seri kırpıcılar (pozitif ve negatif) ve DC kaynaklı paralel kırpıcılar bulunur. Paralel kırpıcılarda çıkış, kaynağın $V$ değerinin üstünde ya da altında sınırlanır. Tablonun en altında, iki diyot ve iki kaynak ($V_1$, $V_2$) içeren bir devre vardır; bu devrenin çıkışı $V_1$ ile $-V_2$ arasında kırpılır.

Ardından hoca, konuyu pekiştirmek için bir örneği beyaz tahtada birlikte çözdü.

### 1.1 Devre

Tahtaya çizilen devre şöyledir (ekrandan, 00:10:00):

| Eleman | Bağlantı |
|---|---|
| Giriş $v_{in}$ | Üst hattın A ucu ile alt hat arasında |
| Direnç $R$ | A ile çıkış düğümü B arasında, seri |
| İdeal diyot | B ile DC kaynağın artı ucu arasında |
| DC kaynak | $+3$ V; eksi ucu alt hatta (C) |
| Çıkış | $V_{out} = V_{BC}$ |

Giriş $v_{in} = 10\sin(2\pi f t)$ V'tur, yani $+10$ V ile $-10$ V arasında salınır. Diyot bu ilk bağlantıda kaynaktan B düğümüne doğru akım iletecek yöndedir (anot kaynak tarafında, katot B tarafında). Bu tür sorularda genellikle giriş sinüs olarak verilir ve çıkışın girişle aynı eksen üzerinde çizilmesi istenir.

### 1.2 Çözüm: Girişi Adım Adım Artırmak

Hoca bu tür devrelerin girişi sıfırdan başlatıp yavaş yavaş artırarak incelenmesini önerdi.

- $v_{in} = 0$ V: B düğümü kaynaktaki 3 V'tan daha düşük gerilimdedir. Diyot iletimdedir ve kısa devre gibi düşünülür. Kısa devre olunca çıkışta doğrudan kaynağın gerilimi görünür: $v_{out} = 3$ V.
- $v_{in} = 1$ V, $2$ V: Diyot hâlâ iletimdedir, çünkü artı ucundaki 3 V eksi ucundaki gerilimden yüksektir. Aradaki fark dirence düşer, çıkış yine $3$ V'tur.
- $v_{in} > 3$ V: Diyot artık akım akıtmaz, açık devre olur. Akım olmayınca direnç üzerinde gerilim düşmez; direncin iki ucu eşit gerilimde olur. Bu yüzden B, A'daki gerilimi aynen gösterir: çıkış girişi izler ve tepe değeri $+10$ V'a kadar çıkar.
- Giriş yeniden 3 V'un altına inince diyot tekrar iletir; çıkış 3 V'a sabitlenir. Negatif yarı periyot boyunca da (giriş $-10$ V'a kadar inse bile) çıkış 3 V'ta kalır.

Tahtadaki çizimde kırmızı çıkış eğrisi $t = 0$'da 3 V'tan başlar, giriş 3 V'u geçince sinüsün tepesini izler, sonra 3 V'a inip orada yatay devam eder (ekrandan, 00:30:00). Kısaca:

$$v_{out} = \max(v_{in},\ 3\ \text{V})$$

Hoca bunun slayttaki paralel kırpıcılardan birinin karşılığı olduğunu da gösterdi.

### 1.3 Soru-Cevap: Gerilimler Birbirini Götürür mü?

**Soru:** Kaynaktan 3 V geliyor; sinüs girişinden de ters yönde, 3 V'un altında bir değer gelince bu ikisi birbirini azaltmıyor mu?

**Cevap:** Hayır. Hoca bunu bir kara kutu üzerinde açıkladı. Herhangi bir elemanın A ucundaki gerilim $V_A$, B ucundaki gerilim $V_B$ olsun. Uçlar arasındaki gerilim, her ucun toprağa göre geriliminin farkıdır:

$$V_{AB} = V_A - V_B$$

$V_A = +3$ V ve $V_B = -2$ V ise $V_{AB} = 3 - (-2) = 5$ V olur (ekrandan, 00:30:00). Yani bir uca daha düşük bir gerilim bağlamak aradaki potansiyel farkını artırır; gerilimler birbirini götürmez. Bu yüzden giriş 3 V'un altındayken diyot iletimde kalır, 3 V'un üstüne çıkınca da B ucu C'den yüksek olacağından diyot kesime gider.

Hoca bu noktada sınıfa konunun anlaşılıp anlaşılmadığını sordu ve birkaç öğrenciden anlaşıldı cevabı aldı.

## 2. Diyotu Ters Çevirince: İkinci Kırpıcı Örneği

Hoca, sınavda aynı soruyu değiştirmek istediğinde yapılabilecek basit bir değişikliği gösterdi: aynı devrede yalnız diyotun yönü ters çevrilir. Giriş yine $10\sin(2\pi f t)$ V, kaynak yine $+3$ V'tur.

- $v_{in} = 0$ V: Diyotun artı ucuna daha yakın olan taraf (B) 0 V'tadır. Diyotun iletmesi için eksi ucunda daha düşük gerilim olması gerekir; bu sağlanmadığı için diyot iletimde değildir. Açık devre gibi düşünülür ve çıkış girişi izler: $v_{out} = 0$ V.
- $v_{in} = 1$ V, $2$ V: Diyot hâlâ kesimdedir; çıkış girişle aynıdır.
- $v_{in} > 3$ V: Diyot iletime geçer ve kısa devre olur. Çıkış 3 V'ta tutulur, giriş ne kadar artarsa artsın çıkış 3 V'un üstüne çıkmaz.
- Giriş 3 V'un altına inince diyot yeniden açık devre olur; çıkış girişi $-10$ V'a kadar aynen izler. Bir sonraki periyotta aynı döngü tekrarlanır.

Hoca bu çözümde de diyotun ideal kabul edildiğini vurguladı. Sonuç (ekrandan, 00:30:00):

$$v_{out} = \min(v_{in},\ 3\ \text{V})$$

> **Hocanın vurgusu:** Yalnız diyotun yönü değiştirildiğinde çıkış dalga biçimi büyük ölçüde değişir; iki çizim neredeyse birbirinin tersi gibidir. Slayttaki çeşitli kırpıcılar bu tür değişikliklerle elde edilir.

### 2.1 Soru-Cevap: $|V_1| > |V_2|$ Koşulu

**Soru:** Slayttaki en alttaki (iki diyotlu, iki kaynaklı) devrede yazan $|V_1| > |V_2|$ koşulu ne anlama geliyor?

**Cevap:** Böyle bir zorunluluk yoktur. Grafikte $V_1$ seviyesinin daha yukarıda çizildiğini göstermek için yazılmıştır. $V_1$ daha küçük olsaydı da devre aynı mantıkla çalışır; çıkış yine $V_1$ ve $-V_2$ seviyelerinde kırpılır, yalnız grafikteki seviyelerin yeri değişir (ekrandan, 00:05:00).

> **Ek bilgi (derste anlatılmadı):** İki diyotlu paralel kırpıcıda bir diyot $v_{in} > V_1$ iken, diğeri $v_{in} < -V_2$ iken iletir. Böylece çıkış $-V_2 \le v_{out} \le V_1$ aralığında kalır. $V_1$ ve $V_2$'nin büyüklük ilişkisi yalnız kırpma seviyelerinin simetrik olup olmadığını belirler.

## 3. Kenetleyici (Clamper) Devreler

### 3.1 Adın Kökeni

Hoca "clamper" kelimesini açıklamak için mengene ve kıskaç gibi aletleri gösterdi. Clamp, bir nesneyi sıkıştırıp sabitleyerek üzerinde işlem yapmayı sağlayan alettir. Kenetleyici devreler de sinyali belirli bir yöne "sıkıştırır", yani belirli bir DC seviyesine sabitler.

### 3.2 Kırpıcıdan Farkı: Kapasitör

Slayttaki tanıma göre bir diyot ve bir kapasitör birlikte kullanılarak AC sinyal belirli bir DC seviyesine kenetlenebilir (ekrandan, 00:25:00). Kırpıcılardan farkı devreye kapasitörün girmesidir. Kapasitör elektrik yükü biriktiren bir elemandır; hoca onu bir pil gibi düşünmeyi önerdi. Üzerinden akım geçtiği sürece dolar (şarj olur), akım kesilince biriktirdiği yükü ters yönde boşaltır (deşarj olur).

### 3.3 Slayttaki Devre

Slayttaki devre şöyledir (ekrandan, 00:25:00):

| Eleman | Bağlantı |
|---|---|
| Giriş $v_i$ | Sol uçlar |
| Kapasitör $C$ | Üst hatta, giriş ile çıkış düğümü arasında seri |
| Diyot | Çıkış düğümü ile alt hat arasında, paralel |
| Direnç $R$ | Çıkış uçlarına paralel |
| Çıkış $v_o$ | Sağ uçlar |

Giriş, $+V$ ile $-V$ arasında periyodu $T$ olan bir kare dalgadır. Çıkış, $0$ ile $-2V$ arasında salınan bir kare dalgadır.

Çalışma şöyledir:

- Pozitif yarı periyot ($0$–$T/2$): Diyot iletimdedir. Kapasitör diyot üzerinden dolar ve üzerinde $V$ kadar gerilim birikir. Diyot iletimde olduğu için çıkış $0$ V'tur.
- Negatif yarı periyot ($T/2$–$T$): Giriş $-V$'ye iner, diyot kesime gider. Dolu kapasitör girişle seri bir gerilim kaynağı gibi davranır; kapasitördeki $V$ ve girişteki $-V$ toplanır ve çıkışta $-2V$ görünür.

Hoca, kitaptaki şekilde kapasitörün çok büyük kabul edildiğini belirtti. Gerçekte kapasitör boşalırken üzerindeki gerilimi zamanla kaybeder; çıkışın düz değil, zamanla azalan (üstel) bir biçimde çizilmesi gerekirdi. Hoca bunu tahtada kapasitör gerilimi azalan bir eğriyle gösterdi (ekrandan, 00:25:00). Kenetleme işinin sağlıklı yapılabilmesi için kapasitörün periyoda göre yavaş boşalması gerekir.

> **Ek bilgi (derste anlatılmadı):** Kenetleyicide düz çıkış için genellikle $\tau = RC$ zaman sabitinin, giriş periyodunun yarısından çok büyük olması (örneğin en az 5 katı) istenir. Böylece kapasitör bir yarı periyot boyunca belirgin biçimde boşalmaz.

Hoca, kapasitörün işe girdiği bu devrelerin girişte kare dalga ile denenmesini önerdi; böylece pozitif ve negatif durumlar ayrı ayrı görülebilir. Gerilim kaynağı da eklendiğinde sinyalin yine belli bir yöne sıkıştırıldığı, yalnız seviyenin kaydığı görülür.

## 4. Zener Diyot ile Gerilim Sınırlama

### 4.1 Normal Diyot ile Zener Diyotun Karşılaştırılması

Hoca önce normal diyotun $I_D$–$V_D$ karakteristiğini hatırlattı. İdeal diyot ileri yönde sıfırda iletmeye başlar; gerçek diyot silisyum için yaklaşık $0{,}7$ V'tan sonra iletir. Ters yönde ise akım akmaz.

Zener diyot ise ters yönde, belirli bir negatif gerilimde kırılacak biçimde üretilmiş bir diyottur. Bu kırılma gerilimi $V_Z$ ile gösterilir ve üretimle ayarlanabilir: örneğin 2, 6, 12 ya da 18 V. Böylece yalnız $0{,}7$ V'a mahkûm olunmaz; belli bir gerilim aşıldığında üzerinden akım akıtarak gerilimin daha fazla artmasını engelleyen bir eleman elde edilir.

Zener devreye ters bağlanır: katot (sembolde kıvrık çizgili uç) daha yüksek gerilime gelir. Hoca bu durumda negatif gerilimleri unutup $V_Z$'yi pozitif bir değer gibi düşünmenin kolaylık sağladığını söyledi.

### 4.2 Açık ve Kapalı Durumlar

Slayttaki tanım şöyledir (ekrandan, 00:35:00): zener, zener geriliminde ters kutuplamayla çalıştırılan bir diyottur.

- $V_i \ge V_Z$ olduğunda:
  - Zener açıktır ("on").
  - Zener üzerindeki gerilim $V_Z$'dir; zener $V_Z$ değerinde bir gerilim kaynağı gibi davranır.
  - Zener akımı: $I_Z = I_R - I_{RL}$.
  - Zener gücü: $P_Z = V_Z I_Z$.
- $V_i < V_Z$ olduğunda:
  - Zener kapalıdır ("off").
  - Zener açık devre gibi davranır.

Slayttaki örnek devrede $V_i$ kaynağı seri bir $R$ direnci üzerinden, birbirine paralel bağlı zener diyot ve $R_L$ yük direncine bağlanır. Zener üzerindeki gerilim $V_Z$, zenerden geçen akım $I_Z$, zenerin dayanabileceği en büyük güç $P_{ZM}$ ile gösterilir (ekrandan, 00:35:00).

### 4.3 Sayısal Örnek

Hoca sözlü bir örnek verdi: 6 V'luk bir zener, seri bir dirençle birlikte 7 V'luk bir girişe bağlansın. Zener açık durumdadır ve üzerinde 6 V tutar; geriye kalan $7 - 6 = 1$ V seri dirence düşer.

### 4.4 Soru-Cevap: $V_Z$ Aşılırsa Ne Olur?

**Soru:** $V_Z$ aşılırsa, örneğin $-6$ V olması gereken yerde $-7$ V uygulanırsa zener yine iletir mi?

**Cevap:** Zener iletir, ancak fazladan 1 V zenerin üzerine düşmez. Karakteristik $V_Z$'de kıvrıldığı için zener uçlarındaki gerilim $V_Z$'de kalır; fazlası devredeki diğer elemanlara, örneğin seri dirence düşer.

### 4.5 Koruma Elemanı Olarak Zener

> **Hocanın vurgusu:** Giriş ne kadar büyük tutulursa tutulsun, zenerin bağlı olduğu A-B uçlarında görülebilecek en büyük gerilim $V_Z$'dir. Bu yüzden zenerler devrelerde koruma amacıyla çokça kullanılır; zenerin sağ tarafındaki devreye en fazla $V_Z$ uygulanır.

Hoca, $R_{L,\min}$, $R_{L,\max}$ gibi değerlerin hesabının ileride zener soruları üzerinde görüleceğini söyledi.

## 5. Diyotların Diğer Uygulamaları

Diyotlar, transformatör ve kapasitörlerle birlikte gerilim çoğaltıcı devrelerde de kullanılır. Girişte tepe değeri $V_m$ olan bir sinyal, uygun bir diyot-kapasitör merdiveniyle çıkışta $2V_m$ (ikileyici), $3V_m$ (üçleyici) ya da $4V_m$ (dörtleyici) değerine çıkarılabilir. Slayttaki devrede aynı merdivenin farklı noktalarından çıkış alınarak iki, üç ve dört katı elde edildiği gösterildi. Hoca bunları genel bilgi olarak verdi.

Diyot uygulamalarının özeti şöyledir:

- Doğrultucu devreler.
- Basit diyotlu koruma devreleri (aşırı akımı engelleme).
- Polarite ters çevirme (reversal): artı ve eksi tarafın yer değiştirmesinde kullanım.
- Zener diyotlar: aşırı gerilim koruması ve referans gerilimi oluşturma.

## 6. Transistörün Yapısı: pnp ve npn

Dersin ikinci yarısında yeni slayt dosyasına geçilerek transistörlere başlandı. Diyot, bir p-n ekleminden oluşan iki uçlu bir elemandı. Transistör ise üç katmanlı (p ya da n tipi) bir yapıdan oluşur ve üç bacaklıdır (ekrandan, 00:40:00).

İki tip transistör vardır:

- **pnp:** Dışta iki p tipi, ortada bir n tipi katman.
- **npn:** Dışta iki n tipi, ortada bir p tipi katman.

Bacaklar şöyle adlandırılır:

- **Baz (B, base, temel):** Ortadaki, tek kalan malzemeye bağlı bacak.
- **Emetör (E, emitter, yayıcı)** ve **kolektör (C, collector, toplayıcı):** Dıştaki iki aynı tip malzemeye bağlı bacaklar.

Slaytta katman genişlikleri de verilir: toplam genişlik 0,150 inç, ortadaki baz katmanı ise 0,001 inçtir (ekrandan, 00:40:00). Katmanlar arasında, diyotta olduğu gibi tükenme (depletion) bölgeleri oluşur. Dışarıdan bağlanan iki gerilim kaynağı ($V_{EE}$ ve $V_{CC}$) bu bölgeleri daraltıp genişletir; transistör buna göre iletime ya da kesime geçer.

Akım yönleri iki tipte terstir: pnp transistörde iletim durumunda akım emetörden kolektöre doğru, npn transistörde kolektörden emetöre doğru akar.

## 7. Transistör Sembolü ve Akım Bağıntıları

### 7.1 Akım Bağıntısı

Hem pnp hem npn tipinde şu eşitlik geçerlidir:

$$I_E = I_C + I_B$$

Emetör akımı, kolektör ve baz akımlarının toplamıdır; bir tipte iki akım birleşip emetör akımını oluşturur, diğerinde emetör akımı kolektör ve baz üzerinden ayrılır.

### 7.2 Sembol

Hoca npn sembolünü tahtada çizdi (ekrandan, 00:45:00): dikey bir çubuk baz tarafını gösterir; çubuktan iki eğik çizgi çıkar, biri kolektör, diğeri emetördür. Ok daima emetör bacağındadır ve n tipi malzemeyi gösterir.

- npn'de emetör n tipidir; ok emetörden dışarı doğru bakar.
- pnp'de baz n tipidir; ok baza doğru, içeri bakar.

Çizginin (çubuğun) olduğu taraf daima bazdır. Ok emetör tarafına dönükse kenardaki malzemelerin n tipi olduğu, yani transistörün npn olduğu anlaşılır.

### 7.3 Soru-Cevap: Emetör ve Kolektör Nasıl Belirlenir?

**Soru:** Emetör ve kolektör uçları bağlanan kaynağa göre mi belirleniyor, yoksa hep sabit mi? Soldaki emetör, sağdaki kolektör mü oluyor?

**Cevap:** Şimdilik bunu düşünmeye gerek yok. Slaytta solda emetör, sağda kolektör olacak biçimde çizilmiştir; ancak farklı kullanım senaryoları vardır ve bunlar ileride görülecektir. Bilinmesi gereken, npn'de akımın kolektörden emetöre, pnp'de emetörden kolektöre aktığıdır.

### 7.4 Baz Akımı ve $I_C \approx I_E$ Yaklaşımı

Baz akımı $I_B$, kolektör ve emetör akımlarına göre çok küçüktür. Genellikle transistörü iletime ya da kesime geçirmek için kullanılır. Kolektör ve emetör akımları miliamper mertebesindeyken baz akımı mikroamper mertebesindedir. Bu yüzden hesaplarda yaklaşık olarak

$$I_C \approx I_E$$

alınacaktır.

## 8. Bağlantı Biçimleri ve Çalışma Bölgeleri

### 8.1 Ortak Baz, Ortak Emetör, Ortak Kolektör

Transistör devreleri, hangi bacağın giriş ve çıkış için ortak olduğuna (toprağa yakın olduğuna) göre adlandırılır:

- **Ortak baz (common base):** Baz ortaktır. Slaytta pnp ve npn için $V_{EE}$ ve $V_{CC}$ kaynaklı devreler ve akım yönleri gösterilir: pnp'de $I_E$ içeri girer, $I_C$ ve $I_B$ dışarı çıkar; npn'de tersi (ekrandan, 00:45:00).
- **Ortak emetör (common emitter):** Emetör ortaktır. En yaygın kullanım biçimlerinden biridir: baz akımı soldan bir tetikleyici gibi uygulanır, kolektör akımı ise transistörün iletip iletmemesine göre sürülür.
- **Ortak kolektör (common collector):** Kolektör ortaktır; pnp ve npn ile kurulabilir.

### 8.2 Ortak Baz Giriş Karakteristiği

Slayttaki giriş karakteristiği, giriş akımı $I_E$ ile giriş gerilimi $V_{BE}$ arasındaki ilişkiyi üç çıkış gerilimi için gösterir: $V_{CB} = 1$ V, $10$ V ve $20$ V (ekrandan, 00:50:00). Eğriler diyot karakteristiğine benzer: $V_{BE}$ yaklaşık $0{,}6$ V'a kadar akım neredeyse sıfırdır, sonra hızla artar ve yaklaşık $0{,}7$–$0{,}8$ V civarında birkaç miliampere ulaşır. Hoca karakteristikleri hızlı geçti ve ileride ayrıntılı görüleceğini söyledi.

### 8.3 Üç Çalışma Bölgesi

Çıkış karakteristiğinde ($I_C$–$V_{CE}$ eğrileri, farklı $I_B$ değerleri için) üç bölge vardır:

- **Aktif bölge:** Transistör genellikle bu bölgede, uygun bir çalışma noktasında çalıştırılır.
- **Kesim bölgesi (cutoff):** Akımın akmadığı bölge.
- **Doyum bölgesi (saturation):** Akımın çok aktığı, ancak transistör üzerinde gerilimin (neredeyse) düşmediği bölge.

Farklı $I_B$ değerleri, aktif bölgenin hangi eğrisinde çalışılacağını belirler.

### 8.4 Temel Yaklaşık Değerler

- $I_C \approx I_E$.
- Baz-emetör gerilimi $V_{BE}$, transistörü sürmek için önemlidir: silisyum için $0{,}7$ V, germanyum için $0{,}3$ V.
- $I_E = I_C + I_B$ olduğundan $I_B$ ne kadar küçükse $I_C/I_E$ oranı 1'e o kadar yaklaşır.

### 8.5 Anahtarlama Modu

Transistörün en temel kullanımlarından biri anahtarlama elemanı olmasıdır (switching mode): 0 V ile 5 V arasındaki geçişleri sağlar. Bu çalışma biçimi sayısal devrelerde çok kullanılır; mikroişlemcilerin ve RAM'lerin içindeki transistörler anahtarlama modunda çalışır.

## 9. Transistörle Gerilim Yükseltme

Slaytta ortak baz bağlantılı bir pnp transistörle gerilim yükseltme örneği verildi (ekrandan, 00:55:00). Devre:

| Büyüklük | Değer |
|---|---|
| Giriş gerilimi $V_i$ | 200 mV (AC) |
| Giriş direnci $R_i$ (E-B arası) | 20 Ω |
| Çıkış direnci $R_o$ (C-B arası) | 100 kΩ |
| Yük direnci $R$ | 5 kΩ |
| Çıkış | $V_L$, yük üzerindeki gerilim |

Çözüm adım adım:

1. Giriş (emetör) akımı:
   $$I_E = I_i = \frac{V_i}{R_i} = \frac{200\ \text{mV}}{20\ \Omega} = 10\ \text{mA}$$
2. $I_C \approx I_E$ olduğundan yük akımı $I_L \approx I_i = 10$ mA.
3. Yük gerilimi:
   $$V_L = I_L R = (10\ \text{mA})(5\ \text{k}\Omega) = 50\ \text{V}$$
4. Gerilim kazancı:
   $$A_v = \frac{V_L}{V_i} = \frac{50\ \text{V}}{200\ \text{mV}} = \frac{50}{200 \times 10^{-3}} = 250$$

Hoca $L$ indisinin yük (load) anlamına geldiğini, $V_L$'nin yük direnci üzerinde düşen gerilim olduğunu belirtti. Sayısal sonuçlar python ile doğrulandı.

> **Ders sonrası not:** Hoca hesap sırasında akımı bir an "100 mA civarı", kazancı ararken "50 milivolt" dedi; slayttaki ve doğru değerler $I_E = 10$ mA ve $V_L = 50$ V'tur.

Hoca bu örnekteki yapının ortak baz yapısı olduğunu, ortak baz yapılarının gerilim yükseltmede çokça kullanıldığını söyledi.

> **Ek bilgi (derste anlatılmadı):** Bu örnekte kazanç, akımın küçük giriş direncinden ($20\ \Omega$) büyük yük direncine ($5$ kΩ) neredeyse aynen aktarılmasından gelir: $A_v \approx R/R_i = 5000/20 = 250$. Ortak baz bağlantısında akım kazancı 1'e yakındır, gerilim kazancı ise yüksektir.

## 10. Alfa ve Beta Katsayıları

### 10.1 Tanımlar

- **Alfa:** $\alpha = \dfrac{I_C}{I_E}$. $I_B$ çok küçük olduğundan $\alpha$ 1'e çok yakındır. AC çalışmada akımların kendileri yerine değişimleri (farkları) kullanılır.
- **Beta:** $\beta = \dfrac{I_C}{I_B}$. Transistörün kendine özgü bir parametresidir; kolektör akımının girişte verilen baz akımına oranıdır (akım kazancı). AC ve DC analizleri ileride görülecektir.

Hoca ayrıca $I_{CBO}$ gibi azınlık taşıyıcı akımlarıyla ilgili ince hesapların bulunduğunu, ancak bu derste görülmeyeceğini söyledi.

### 10.2 Alfa-Beta İlişkisinin Türetilmesi

Hoca, üç eşitliğin ($I_E = I_C + I_B$, $\alpha = I_C/I_E$, $\beta = I_C/I_B$) birbirine yerleştirilmesiyle ilişkinin çıkarılacağını gösterdi (ekrandan, 01:00:00). $I_B = I_C/\beta$ ve $I_E = I_C/\alpha$ yazılırsa:

$$\frac{I_C}{\alpha} = I_C + \frac{I_C}{\beta}$$

İki taraf $I_C$'ye bölünürse (ara adım eklendi):

$$\frac{1}{\alpha} = 1 + \frac{1}{\beta} = \frac{\beta + 1}{\beta}$$

Buradan:

$$\alpha = \frac{\beta}{\beta + 1}, \qquad \beta = \frac{\alpha}{1 - \alpha}$$

Akımlar arasındaki ilişki de slaytta verilmiştir:

$$I_C = \beta I_B, \qquad I_E = (\beta + 1) I_B$$

> **Ders sonrası not:** Slaytta ve hocanın okumasında $\beta = \dfrac{\alpha}{\alpha - 1}$ yazıyor (ekrandan, 01:00:00). $\alpha < 1$ olduğundan bu ifade negatif bir sonuç verir; doğrusu $\beta = \dfrac{\alpha}{1 - \alpha}$'dır. Örneğin $\beta = 100$ için $\alpha = 100/101 \approx 0{,}990$, buradan $\alpha/(1-\alpha) = 100$ bulunur (python ile kontrol edildi).

> **Ders sonrası not:** Hoca bir yerde "alfada $I_C$ bölü $I_B$" dedi; alfa $I_C/I_E$'dir, $I_C/I_B$ betadır.

## 11. Veri Sayfası, Transistör Testi ve Kılıflar

### 11.1 Veri Sayfası (Spec)

Herhangi bir elektronik elemanın hangi koşullarda nasıl çalıştığı, teknik özellikleri veri sayfasında (specification, spec) bulunur. Transistör veri sayfasında kılıfın bir yüzünün düz (kesik) çizildiği görünüş ve bacak numaraları verilir; slayttaki örnekte 1 numaralı bacak emetör, 2 numaralı bacak baz, 3 numaralı bacak kolektördür. Sıcaklığa göre davranış, güç tüketimi ve karakteristikler gibi ayrıntılar, hassas çalışılacaksa buradan öğrenilir.

### 11.2 Ohmmetre ile Test

Slaytta transistörün doğru çalışıp çalışmadığını test etme yolları listelenir: eğri izleyici (curve tracer) karakteristik eğrileri çizer; bazı dijital multimetreler $\beta_{DC}$ ya da $h_{FE}$ ölçer; ohmmetre ile de eklemler denetlenebilir (ekrandan, 01:05:00).

Ohmmetre testinde transistörün eklemleri birer diyot gibi düşünülür. npn transistörde baz p, emetör ve kolektör n tipidir; bazdan emetöre ve bazdan kolektöre doğru birer diyot varmış gibi kabul edilir.

- Ohmmetre baz ile emetör arasına, bu eklemi doğru yönde kutuplayacak biçimde bağlanırsa (kolektör açıkta) düşük direnç (Low R) okunur.
- Baz-kolektör eklemi ters yönde ölçülürse, yani eklem ters kutuplanacak biçimde bağlanırsa, yüksek direnç (High R) okunur.

Bu ölçümlerle transistörün en azından basitçe sağlam olup olmadığı anlaşılabilir.

> **Ders sonrası not:** Hoca açıklama sırasında "arada bir transistör var" dedi; kastedilen baz ile emetör arasındaki eklemin bir diyot gibi davranmasıdır.

### 11.3 Kılıflar

Transistörler üç bacaklı ve bir yüzü düz kılıflarla üretilir. Yüzeye montaj yapılan transistörler SMD (surface mounted device) olarak adlandırılır; bunlar da üç bacaklıdır ve kartın yüzeyine yapıştırılır. Güç transistörleri daha kalın, kılıflı yapıdadır.

## Örnek Sorular

### Soru 1: Paralel kırpıcının çıkışı

(ekrandan, 00:10:00)

Girişte $v_{in} = 10\sin(2\pi f t)$ V uygulanan devrede giriş, seri bir $R$ direnci üzerinden çıkış düğümüne gider; çıkış düğümü ile alt hat arasında seri bağlı bir ideal diyot ve $+3$ V'luk DC kaynak vardır. Diyot, kaynağın artı ucundan çıkış düğümüne doğru iletecek yöndedir. $v_{in}$ ve $v_{out}$'u aynı eksende çizin.

**Çözüm (derste verildi):** $v_{in} < 3$ V iken diyot iletimdedir ve çıkış $3$ V'tur. $v_{in} > 3$ V iken diyot kesimdedir, dirençten akım geçmez ve çıkış girişi izler. Sonuç $v_{out} = \max(v_{in}, 3\ \text{V})$: çıkış 3 V'tan başlar, sinüsün 3 V üstündeki kısmını izleyerek 10 V'a çıkar, sonra 3 V'ta yatay kalır (ekrandan, 00:30:00).

### Soru 2: Diyot ters çevrildiğinde

(ekrandan, 00:15:00)

Soru 1'deki devrede yalnız diyotun yönü ters çevrilirse çıkış ne olur?

**Çözüm (derste verildi):** $v_{in} < 3$ V iken diyot kesimdedir ve çıkış girişi izler; $v_{in} > 3$ V iken diyot iletir ve çıkış $3$ V'ta tutulur. Sonuç $v_{out} = \min(v_{in}, 3\ \text{V})$: çıkış 0'dan 3 V'a çıkar, 3 V'ta yatay kalır, sonra girişi $-10$ V'a kadar izler (ekrandan, 00:30:00).

### Soru 3: İki diyotlu kırpıcıda $|V_1| > |V_2|$ koşulu

(derste sözlü, 00:21:15)

Slayttaki iki diyotlu ve iki kaynaklı kırpıcıda $|V_1| > |V_2|$ koşulu gerekli midir?

**Çözüm (derste verildi):** Gerekli değildir. İfade yalnız grafikte $V_1$ seviyesinin daha yukarıda çizildiğini belirtir; çıkış her durumda $V_1$ ve $-V_2$ seviyelerinde kırpılır.

### Soru 4: Kare dalga girişli kenetleyici

(ekrandan, 00:25:00)

Seri $C$, paralel diyot ve paralel $R$'den oluşan kenetleyicinin girişine $+V$ ile $-V$ arasında salınan, periyodu $T$ olan bir kare dalga uygulanıyor. Çıkış dalga biçimini çizin.

**Çözüm (derste verildi):** $0$–$T/2$ aralığında diyot iletir, kapasitör $V$'ye dolar ve çıkış $0$ V'tur. $T/2$–$T$ aralığında diyot kesimdedir; kapasitör gerilimi girişe eklenir ve çıkış $-2V$ olur. Çıkış $0$ ile $-2V$ arasında salınan bir kare dalgadır (kapasitör çok büyük kabul edilmiştir).

### Soru 5: Ortak baz yükseltecin kazancı

(ekrandan, 00:55:00)

Ortak baz bağlı bir pnp transistörde $V_i = 200$ mV, $R_i = 20\ \Omega$, $R_o = 100$ kΩ ve yük $R = 5$ kΩ'dur. $I_E$, $I_L$, $V_L$ ve $A_v$'yi bulun.

**Çözüm (derste verildi):** $I_E = 200\ \text{mV}/20\ \Omega = 10$ mA; $I_L \approx I_C \approx I_E = 10$ mA; $V_L = 10\ \text{mA} \times 5\ \text{k}\Omega = 50$ V; $A_v = 50\ \text{V}/200\ \text{mV} = 250$.

## Dersin Toparlaması

Bu derste önce kırpıcı devreler bir örnekle pekiştirildi: $+3$ V'luk kaynak ve paralel bir diyot içeren devrede çıkışın diyotun yönüne göre $\max(v_{in}, 3)$ ya da $\min(v_{in}, 3)$ olduğu, girişin adım adım artırılmasıyla bulundu. Ardından kapasitörün işe girdiği kenetleyici devreler, zener diyotun gerilimi $V_Z$'de tutan davranışı ve koruma elemanı olarak kullanımı, gerilim çoğaltıcılar ve diyot uygulamalarının özeti görüldü.

Dersin ikinci yarısında transistörlere geçildi: pnp ve npn yapılar, emetör-baz-kolektör bacakları, sembol okuma, $I_E = I_C + I_B$ ve $I_C \approx I_E$ yaklaşımı, ortak baz/emetör/kolektör bağlantıları, aktif-kesim-doyum bölgeleri, anahtarlama modu, ortak baz yükselteçte $A_v = 250$ örneği ve $\alpha$-$\beta$ ilişkisi işlendi. Son olarak veri sayfası, ohmmetre ile transistör testi ve kılıf tipleri tanıtıldı. Hoca bir sonraki derste transistörlere ve transistör soru çözümlerine devam edileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
