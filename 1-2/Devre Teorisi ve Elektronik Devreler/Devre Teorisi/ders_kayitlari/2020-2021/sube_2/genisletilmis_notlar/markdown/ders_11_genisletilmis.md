# Ders 11 Genişletilmiş Notu: AC Devrelerine Giriş: Karmaşık Sayılar, Sinüzoidal Dalgalar ve Fazör Gösterimi

> Kayıt üç parçadır; arşivde parçalar yanlış sırada birleştirildiği için altyazıdaki sıra düzeltildi ve saat damgaları düzeltilmiş altyazıya göredir.

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Konuların Tekrarı ve AC Devrelerine Geçiş
- 2. Giriş Frekansının Çıkışa Etkisi
- 3. Karmaşık Sayılar
- 4. Dikdörtgen, Üstel ve Polar Biçimler Arasında Dönüşüm
- 5. Polar Biçimde Çarpma ve Bölme
- 6. Sinüs Dalgasının Karakteristikleri
- 7. Faz Açısı: Önde ve Geride Olma
- 8. Sinüs ile Kosinüsün Karşılaştırılması
- 9. Fazör Gösterimi
- 10. Tekillik Fonksiyonlarıyla Dalga Biçimleri (Tekrar)
- 11. Sinüzoidal Kaynaklı Devreler ve Fazörle Çözüm
- Örnek Sorular
- Dersin Toparlaması

## 1. Önceki Konuların Tekrarı ve AC Devrelerine Geçiş

Hoca derse önceki iki haftanın özetiyle başladı. RL ve RC devreleri yalnız bir enerji depolayan eleman (bobin ya da kondansatör) içerdiği için birinci dereceden devrelerdir. Bu devrelere DC bir gerilim kaynağı bağlandığında ya da kaynak söküldüğünde bobin veya kondansatör üzerindeki enerji değişir. Bu değişim evresine geçiş (transition) denir ve $L/R$ ya da $RC$ zaman sabitine bağlı olarak yaklaşık $5\tau$ sonra tamamlanır. Kaynak bağlıysa enerji depolanır, kaynak söküldüyse enerji sönümlenir.

Geçen hafta bu iki eleman birlikte kullanıldı: RLC devresi iki enerji depolayan eleman içerir. Fark şudur: RLC devresinde kaynak bağlanırken de, söküldüğünde de kondansatör ile bobin bir süre birbirini besler. Bu davranış üç durumda incelenmişti:

- az sönümlü (underdamped),
- aşırı sönümlü (overdamped),
- kritik sönümlü (critically damped).

Hangi durumun oluşacağını devredeki R, L ve C değerleri belirler. Bu değerlerden $\alpha$ ve $\omega$ parametreleri hesaplanmış, aralarındaki büyüklük ilişkisine göre durum seçilmişti.

Bu analizlerin hepsinde giriş DC idi. Bu yüzden geçişten sonra devre sabit (stable) bir değere oturuyordu: örneğin 5 V bağlanırsa bir süre sonra 5 V'a, kaynak sökülürse 0 V'a. Alternatif akımın (AC) özelliği ise sabit bir değerinin olmamasıdır; zaman ekseninde her an farklı bir değer alır. Hoca AC'nin elektrik devrelerinin gelişmesinde en önemli akım şekli olduğunu, gündelik hayatta kullanılan pek çok cihazın AC devre analizine girdiğini söyledi.

AC ile beslenen RL ya da RLC devresi de bir sürekli hale ulaşır, ancak bu sürekli halde de salınım devam eder. Başlangıç ve son koşullar artık sabit sayılar değil, belirli frekansta sinyallerdir. Bu yüzden türevli denklemleri zaman domeninde çözmek zorlaşır. Hoca çözüm yolunu şöyle anlattı: hesaplar başka bir domene, karmaşık sayılara dayanan bir uzaya taşınacak ve orada lineer cebirle çözülecek. Bu uzaydaki gösterime fazör (phasor) gösterimi denir. Bunun için devredeki bütün büyüklükleri karmaşık sayılarla göstermek gerekir; bu yüzden ders önce karmaşık sayıların temelleriyle başladı.

Bölüm başlığı slaytında (ekrandan, 00:01:13) dersin konuları şöyle sıralanmıştı: AC Circuits; temeller ve ilgili matematik, karmaşık sayılar, dikdörtgen koordinatlar, fazör gösterimi.

## 2. Giriş Frekansının Çıkışa Etkisi

AC analizinin neden farklı olduğunu göstermek için bir örnek devre gösterildi (ekrandan, 00:11:13). Kaynak $v_s=\sin(2\pi f t)\,\text{V}$, ardından seri $235\,\Omega$ direnç, çıkışta paralel bağlı $4.7\,\text{nF}$ kondansatör ve $1\,\text{mH}$ bobin vardır. Çıkış gerilimi $v_o$ bu paralel kollar üzerinden ölçülür. Slayttaki osiloskop görüntüsü $f=5\,\text{kHz}$ için alınmıştır.

Sinüs sinyali her $t$ anında devreye farklı bir gerilim uygular. Osiloskopta giriş ve çıkış sinyallerinin her anda farklı değerler aldığı, çıkışın genlik ve konum olarak girişten farklı olduğu görülür. Hoca, sinüs sinyalinin en anlamlı parametresinin frekans ($f$) olduğunu söyledi. Frekans artırıldığında çıkış da değişir. DC gerilimin frekans bilgisi yoktur, değişmez; bu yüzden DC beslemede çıkışın frekans açısından girişe göre farklılaşması gibi bir durum yoktur. Sinüs dalgası verildiğinde ise çıkış tamamen giriş frekansına göre değişir.

Bunu analiz etmek için giriş sinyali fazör biçimine (genliği ve açısıyla verilen bir $e^{j\theta}$ ifadesine) taşınır. Bu uzayda KCL, KVL ve Ohm kanunu uygulanarak çıkış gerilimi aynı biçimde bulunur. Çıkışın açısının girişten farklı çıkması, iki sinyal arasındaki faz farkını gösterir. Hoca bunu "işi zaman domeninden kurtarıp daha az işlem gerektiren bir domene geçirmek" diye özetledi.

## 3. Karmaşık Sayılar

### 3.1 Tanım ve gösterimler

Bir karmaşık sayı dikdörtgen (rectangular) biçimde $z=x+jy$ diye yazılır; burada $j=\sqrt{-1}$, $x$ reel kısım, $y$ sanal (imaginary) kısımdır (ekrandan, 00:16:13). Aynı sayı polar biçimde $z=r\angle\phi$, üstel biçimde $z=re^{j\phi}$ diye de yazılabilir. Hoca tahtada genel olarak $a\angle b$ ve $ae^{jb}$ yazdı: $a$ bir sayıdır (genlik), $b$ ise açıdır. Fazör gösterimi polar biçimle aynı şeydir.

Aynı slaytta önemli bir kural vardı: yalnız aynı türden büyüklükler toplanıp çıkarılabilir; gerilimle gerilim, akımla akım, empedansla empedans, admitansla admitans.

### 3.2 Eşlenik, toplama ve çıkarma

Karmaşık düzlemde yatay eksen reel, dikey eksen sanal kısımdır; her sayı bu düzlemde bir nokta ya da vektördür. $a+jb$ sayısının eşleniği (conjugate) yalnız sanal kısmın işareti değiştirilerek elde edilir: $a-jb$. Eşlenik özellikle bölmede kullanılır.

Toplama ve çıkarmada reel kısımlar kendi arasında, sanal kısımlar kendi arasında toplanır. Koordinat düzleminde bu işlem vektörleri uç uca ekleme (tip to tail) yöntemiyle de yapılabilir; sonuç aynıdır.

### 3.3 Dikdörtgen biçimde çarpma

Çarpma dağılma özelliğiyle yapılır:

$$(a+jb)(c+jd)=ac+jad+jbc+j^2bd=(ac-bd)+j(ad+bc)$$

$j^2=-1$ olduğu için $bd$ terimi reel kısımdan çıkarılır. Hoca formülü ezberlemeye gerek olmadığını, normal dağılma işlemiyle yapıldığını söyledi. <!-- BELİRSİZ: Slayttaki sayısal çarpma örneğinin değerleri altyazıdan ("5 ile 2'yi, 3 ile") tam çıkarılamadı ve karelerde bu slayt yok. -->

Bu işlem karışıktır. Devrede sürekli çarpma ve bölme yapılır (örneğin $V=IR$); akım ve direnç karmaşık sayı olduğunda çarpmayı polar biçimde yapmak çok daha basittir.

### 3.4 Dikdörtgen biçimde bölme

Bölmede pay ve payda, paydanın eşleniğiyle çarpılır; böylece paydadaki $j$ ortadan kalkar. Slayttaki genel formül (ekrandan, 00:21:13): $Z=X/Y$, $X=a+jb$, $Y=c+jd$ için

$$Z=\frac{(ac+bd)+j(bc-ad)}{c^2+d^2},\qquad \mathrm{Re}(Z)=\frac{ac+bd}{c^2+d^2},\quad \mathrm{Im}(Z)=\frac{bc-ad}{c^2+d^2}$$

Hoca tahtada $X=3+j2$, $Y=2+j5$ örneğini yazdı. Pay ve payda $2-j5$ ile çarpılır, payda $2^2+5^2=29$ olur. İşlem derste sonuna kadar götürülmedi; tamamlanırsa (ara adım eklendi):

$$\frac{3+j2}{2+j5}=\frac{(6+10)+j(4-15)}{29}=\frac{16-j11}{29}\approx0.552-j0.379$$

Hoca bölmenin de zahmetli olduğunu (eşlenik al, çarp, topla, çıkar), polar biçime geçilince çok daha basit hale geldiğini söyledi.

### 3.5 Hangi işlem hangi biçimde?

Özet slayta göre: toplama ve çıkarma dikdörtgen (karmaşık) biçimde, çarpma ve bölme fazör (polar) biçimde yapılır. Örneğin güç hesabında $V\cdot I$ çarpımı fazörle bulunur: $V=V_m\angle\theta_V$, $I=I_m\angle\theta_I$ ise genlikler çarpılır, açılar toplanır. Bölmede genlikler bölünür, açılar çıkarılır.

## 4. Dikdörtgen, Üstel ve Polar Biçimler Arasında Dönüşüm

Hoca dönüşümü Euler bağıntısından türetti (ekrandan, 00:26:13):

$$e^{j\theta}=\cos\theta+j\sin\theta,\qquad |z|e^{j\theta}=|z|\cos\theta+j|z|\sin\theta=a+jb$$

Burada $|z|$'nin pozitif ve reel olduğu varsayılır. Buradan:

- $a=|z|\cos\theta$, $b=|z|\sin\theta$,
- $\dfrac{\sin\theta}{\cos\theta}=\tan\theta=\dfrac ba$, yani $\theta=\tan^{-1}(b/a)$,
- $a^2+b^2=|z|^2(\cos^2\theta+\sin^2\theta)=|z|^2$, yani $|z|=\sqrt{a^2+b^2}$.

Hoca tahtada $3+j2$ üzerinde gösterdi: 3 kısmı $|z|\cos\theta$'ya, 2 kısmı $|z|\sin\theta$'ya karşılık gelir. Açı $\tan^{-1}(2/3)$, genlik $\sqrt{3^2+2^2}$ olur.

Slayt örneği: $4+3j$. $\theta=\tan^{-1}(3/4)\approx37^\circ$, $|z|=\sqrt{16+9}=5$ (3-4-5 üçgeni). Üstel biçim $5e^{j37^\circ}$, polar (fazör) biçim $5\angle37^\circ$. Hoca bu gösterimde frekans bilgisinin bulunmadığına dikkat çekti: sinyalin kaç hertz olduğu yazmaz. Fazör böylece frekans domenindeki hesaplardan kurtarır.

Üç biçimin özeti:

- Dikdörtgen: $a+jb$ (olağan karmaşık sayı gösterimi).
- Üstel: $|z|e^{j\theta}$.
- Polar: $|z|\angle\theta$; $e$ ve $j$ kaldırılmış hali. Hoca polar adının daha yaygın kullanıldığını söyledi.

## 5. Polar Biçimde Çarpma ve Bölme

### 5.1 Çarpma

Slayttaki türetme (ekrandan, 00:31:13): $z_1=a_1+b_1j\Rightarrow|z_1|e^{j\theta_1}$, $z_2=a_2+b_2j\Rightarrow|z_2|e^{j\theta_2}$ ise

$$z_1z_2=|z_1|e^{j\theta_1}|z_2|e^{j\theta_2}=|z_1||z_2|e^{j(\theta_1+\theta_2)}\quad\Rightarrow\quad z_1z_2=|z_1||z_2|\angle(\theta_1+\theta_2)$$

Örnek: $M=3+4j$, $N=\tfrac3{\sqrt2}+\tfrac3{\sqrt2}j$.

- $M$: $\theta=\tan^{-1}(4/3)=53^\circ$, $|M|=5$, yani $M=5\angle53^\circ$. Hoca, bir önceki örnek $4+3j$ olduğu için açının bu kez $37^\circ$ değil $53^\circ$ çıktığını belirtti.
- $N$: $\tan^{-1}(1)=45^\circ$, $|N|=\sqrt{9/2+9/2}=\sqrt9=3$, yani $N=3\angle45^\circ$.
- $MN=(5\cdot3)\angle(53^\circ+45^\circ)=15\angle98^\circ$.

Python kontrolü: $|MN|=15$, açı $98.13^\circ$. Hiçbir terimi tek tek çarpmaya gerek kalmaz.

### 5.2 Bölme

Bölmede genlikler bölünür, açılar çıkarılır. Slayttaki örnekte bir bobin akımı ve bobin gerilimi dikdörtgen biçimde verilmişti; $V_L/I_L$ oranı devrenin direnç (empedans) yapısını verir. Hoca gerilimin genliğini $\sqrt{27+9}=\sqrt{36}=6$, açısını $150^\circ$ buldu. Genliği 2 olan akıma bölünce genlik $6/2=3$, açı ise $90^\circ$ çıkar. <!-- BELİRSİZ: Bu slayt karelerde yok. Gerilimin $-3\sqrt3+j3$ olduğu altyazıdaki ara işlemlerden çıkarıldı; akımın açısının $60^\circ$ olduğu sonuçtan geriye doğru bulundu. Python: $(-3\sqrt3+j3)/(2\angle60^\circ)=3\angle90^\circ$. -->

Bir sonraki slaytta $V\cdot I^*$ (gerilim çarpı akımın eşleniği) çarpımı örneği vardı. Hoca dikdörtgen biçimde her terimin birbiriyle çarpılması gerektiği için işlemin uzadığını, bütün değerler polar biçimdeyse işlemlerin çok daha basit olduğunu söyledi. <!-- BELİRSİZ: $V\cdot I^*$ örneğinin sayısal değerleri altyazıdan çıkarılamadı. -->

## 6. Sinüs Dalgasının Karakteristikleri

Bölüm başlığı "Alternating Current and Voltages: Sinusoidal Waves" idi (ekrandan, 00:36:13). Alternatif akım yalnız zamanla değişen bir gerilim değildir; akımın yönü de belirli bir süre sonra tersine döner. Akım $T/2$ süre bir yönde akarsa, sonraki $T/2$ süre tam simetrik olarak ters yönde akar. RLC devrelerinde bu durum birbirini besleyen bir salınıma yol açar; bu yüzden başlangıç ve son koşulları belirlemek zorlaşır.

Sinüs dalgasının karakteristikleri iki gruba ayrıldı:

- Zaman eksenine bağlı olanlar: periyot, frekans, açısal frekans.
- Genlik eksenine bağlı olanlar: genlik (amplitude), tepeden tepeye genlik, RMS değeri, ortalama değer.

Bunlara ek olarak iki sinyali karşılaştırmak için faz açısı kullanılır.

### 6.1 Periyot

$v(t)=5\sin(377t)$ sinyalinde 5 genliği (magnitude) gösterir; sinyal $+5$ ile $-5$ V arasında salınır. Parantez içindeki $t$'li terim frekans bilgisini taşır.

Periyot ($T$), bir çevrimin (cycle), yani bir desenin baştan sona oluştuğu süredir. Slayta göre (ekrandan, 00:41:13) periyot, sinyalin sıfırdan iki kez geçtiği anlar arasındaki süre ($t_2-t_1$) ya da aynı tepe değerine iki kez ulaştığı anlar arasındaki süre olarak ölçülür:

$$T=t_2-t_1=\frac1{60}\,\text{s}=16.7\,\text{ms}$$

### 6.2 Frekans

Frekans, bir saniyede kaç periyot olduğunu söyler: $f=1/T$. Bir periyot $16.7\,\text{ms}$ ise bir saniyede yaklaşık 60 periyot vardır, yani $f=60\,\text{Hz}$.

**Soru (hoca):** Frekansın artması ne demektir?
**Cevap (bir öğrenci):** Periyodun azalması, yani kendini tekrar eden dalgaların sayısının artması, dalganın daha sık oluşması.

Hoca burada sık yapılan bir yanlış anlamayı düzeltti: 100 Hz'lik bir sinyalle 1 kHz'lik bir sinyal karşılaştırılırken genlik hakkında hiçbir şey söylenmez. Frekans yalnız sinyalin ne sıklıkla tekrarlandığını anlatır. Yüksek frekanslı sinyal sık, düşük frekanslı sinyal seyrektir. Şebeke frekansı Amerika'da 60 Hz, Türkiye'de ve Avrupa'da 50 Hz'dir. Cihazların çoğu bu farkı kendisi karşılar; karşılayamayanlar için adaptörler tasarlanır.

### 6.3 Açısal frekans

Açısal frekans, sinyali başka bir sinyalle karşılaştırmayı sağlayan parametredir:

$$\omega=2\pi f=\frac{2\pi}T\quad(\text{rad/s})$$

Slayttaki örnekte (ekrandan, 00:46:13) $f=60\,\text{Hz}$ için $\omega=377\,\text{rad/s}$ olur. $5\sin(377t)$ yazımındaki 377, $2\pi f$'nin değeridir: $2\cdot3.14\cdot60\approx377$. Slaytta ayrıca santrallerdeki alternatörlerde motor milinin bir tam dönüşünün AC elektriğin bir tam çevrimini ürettiği, mil konumunun radyan ya da derece ile ölçüldüğü yazıyordu. Dönüşüm: $1\,\text{rad}=57.3^\circ$, $2\pi\,\text{rad}=360^\circ$.

> **Hocanın vurgusu:** $\omega$'nın birimi rad/s'dir. 377 radyan, 377 derece demek değildir. Hesap makinesi derece modundaysa önce radyanı dereceye çevirmek gerekir. Çok büyük bir derece çıkarsa $360^\circ$'nin katları atılır, çünkü açı her $360^\circ$'de kendini tekrarlar.

> **Ders sonrası not:** Hoca bir yerde "1 radyan 77.3" ve "53.7" dedi, sonra kendini düzeltti; doğrusu $1\,\text{rad}=57.3^\circ$.

### 6.4 Tepe genliği, tepeden tepeye genlik ve anlık değer

Tepe genliği ($V_p$), sinyalin orta noktasından tepeye olan uzaklıktır. Tepeden tepeye genlik ($V_{pp}$), artı tepe ile eksi tepe arasındaki farktır. "5 V'luk sinüs" denince $\pm5$ V arasında salınan sinyal anlaşılır; tepeden tepeye değer 10 V'tur. Hoca bunun "2.5, 2.5" diye anlaşılmaması gerektiğini söyledi.

Anlık değer, $t$ anındaki gerilimdir. Örnek: $v(t)=5\sin(377t)$ için $t=10\,\text{ms}=0.01\,\text{s}$ anındaki gerilim. $377\cdot0.01=3.77$ radyandır. Hesap makinesi derece modundaysa $\sin(3.77)$ yazmak yanlış sonuç verir. $3.77$ radyanı dereceye çevirmek gerekir: $3.77\cdot57.3^\circ\approx216^\circ$. Bu durumda (ara adım eklendi):

$$v(0.01)=5\sin(216^\circ)\approx-2.94\,\text{V}$$

> **Ders sonrası not:** Hoca dereceyi "160 mı çıkar, bilmiyorum" diye bıraktı; doğrusu yaklaşık $216^\circ$ ve $v(10\,\text{ms})\approx-2.94\,\text{V}$ (python ile kontrol edildi). Bu an sinyalin ikinci yarı periyoduna denk gelir.

### 6.5 Ortalama değer ve DC ofset

Saf bir sinüs dalgasının orta noktası, yani ortalama değeri sıfırdır. Bazı durumlarda sinyale bir DC bileşen (DC offset) eklenir; bu sinyali genlik ekseninde yukarı ya da aşağı kaydırır. Bu durumda ortalama değer sıfırdan farklı olur.

### 6.6 RMS değeri

Slayttaki tanım (ekrandan, 00:51:13): sinüzoidal sinyalin genliğini ölçen cihazların çoğu sonucu RMS (root mean square) değeri olarak gösterir; birim $V_{ac}$ ya da $V_{RMS}$ diye yazılır. RMS gerilim ve akım, bir çevrimdeki ortalama gücü hesaplamak için kullanılır:

$$V_{RMS}=\sqrt{\frac1T\int_0^T[v(t)]^2\,dt},\qquad V_{RMS}=\frac{\sqrt2}2V_p=0.707V_p,\qquad P_{ave}=\frac{V_{RMS}^2}R$$

Hoca tahtaya rastgele seçtiği bir $10\sin(677t)$ sinyali yazdı. Tepe değeri 10 V, tepeden tepeye değeri 20 V'tur. RMS değeri $0.707\cdot10=7.07\,\text{V}$ olur.

> **Ders sonrası not:** Hoca RMS değerini "7 sinüs 677t" diye söyledi. RMS değeri zamana bağlı bir sinyal değil, tek bir sayıdır: $V_{RMS}=7.07\,\text{V}$.

## 7. Faz Açısı: Önde ve Geride Olma

### 7.1 Karşılaştırmanın ön koşulu

Faz açısı, birden fazla AC sinyalin birbirine göre durumunu belirlemek için kullanılır.

> **Hocanın vurgusu:** Karşılaştırılan sinyallerin hepsi aynı frekansta olmalıdır. 50 Hz'lik bir sinyalle 100 Hz'lik bir sinyal faz açısı bakımından karşılaştırılamaz.

Karşılaştırmada iki soru sorulur: Seçilen sinyal referansın önünde mi (leading), arkasında mı (lagging)? Ve bu kaç derecelik faz açısıyla (phase angle) olur?

### 7.2 Zaman kaymasından faz açısı

Slayttaki grafikte (ekrandan, 01:06:13) tepe değeri 5 V olan üç sinyal vardır. Referans mavi sinyaldir (Signal 1). Üçünün periyodu da $500\,\text{s}$'dir, yani frekansları aynıdır. Yeşil sinyal (Signal 2) sıfırdan referanstan $40\,\text{s}$ sonra geçer. Kırmızı sinyal (Signal 3) için hoca kaymayı ters yönden ölçerek $480\,\text{s}$ olarak okudu.

Önce referans sinyalin açısal frekansı bulunur (ekrandan, 01:11:13):

$$V(t)=5\sin(\omega t),\qquad \omega=\frac{2\pi}T=\frac{2\pi}{500}=12.6\,\text{mrad/s}$$

Genliğin 5 V olduğu grafikteki $\pm5$ V değerlerinden okunur. Kaymış sinyaller $V(t)=A\sin(\omega t+\phi)$ biçiminde yazılır; faz kayması:

$$\phi=-2\pi\frac{\Delta t}T\ (\text{radyan}),\qquad \phi=-360^\circ\frac{\Delta t}T\ (\text{derece})$$

- Signal 2: $\phi_2=-360^\circ\cdot40/500=-28.8^\circ$.
- Signal 3: $-360^\circ\cdot480/500=-345.6^\circ$; $360^\circ$ eklenince $+14.4^\circ$.

Yani Signal 2, Signal 1'e göre $28.8^\circ$; Signal 3 ise $14.4^\circ$ faz farkına sahiptir.

> **Ders sonrası not:** Hoca periyodu 500 saniye okuduktan sonra bir yerde "2 Hz'lik bir sinyal" dedi. Periyot 500 s ise frekans $f=1/500=0.002\,\text{Hz}$ olur; $\omega=12.6\,\text{mrad/s}$ değeri de bununla tutarlıdır.

### 7.3 Grafikten ve formülden yorum

Grafikte zaman eksenine dik bir çizgi çekilerek yorum yapılabilir. Mavi sinyal sıfıra geldiğinde kırmızı sinyal sıfırı çoktan geçmiştir; demek ki Signal 3 öndedir (lead). Yeşil sinyal ise henüz sıfıra gelmemiştir; geriden takip eder (lag).

Matematiksel kural:

$$\theta_{\text{seçilen}}-\theta_{ref}<0\Rightarrow\text{lag},\qquad \theta_{\text{seçilen}}-\theta_{ref}>0\Rightarrow\text{lead}$$

Signal 2 için $-28.8-0<0$ olduğundan geridedir. Signal 3 için $14.4-0>0$ olduğundan öndedir. Hoca, burada referansın açısı sıfır olduğu için işin basit göründüğünü, ama referans açısının her zaman sıfır olmayabileceğini söyledi. Sonraki örneklerde bu kuralın işe yarayacağını belirtti.

### 7.4 Genel sinüs ifadesi

Sinüs dalgasını tanımlayan büyüklükler toparlandı: $V_m$ tepe değeridir (5 V denince $\pm5$ V arasında salınım anlaşılır), $f=1/T$ ve $T=2\pi/\omega=1/f$'dir. Faz açısı $\phi$, sinyalin karşılaştırıldığı başka bir sinyale göre kaymasını gösterir.

## 8. Sinüs ile Kosinüsün Karşılaştırılması

### 8.1 Temel örnek: $6\sin(20t+40^\circ)$ ve $-4\cos(20t+20^\circ)$

Slayttaki örnek (ekrandan, 01:16:13 ve 01:21:13): $v_1(t)=6\sin(20t+40^\circ)\,\text{V}$, $v_2(t)=-4\cos(20t+20^\circ)\,\text{V}$. Sinüsün içinde faz terimi olmasaydı sinyal sıfırdan başlardı; $+40^\circ$ terimi sinyalin $40^\circ$ kaydırıldığını gösterir. İki sinyalin frekansı ($20t$) aynıdır.

Kosinüs, sinüsün sıfır olduğu yerde 1 değerini alır; aralarında $90^\circ$ faz farkı vardır. Bu yüzden karşılaştırmadan önce iki sinyal aynı fonksiyona getirilmelidir.

**Kosinüs biçimiyle:**

- Sinüsü kosinüse çevirmek için içeriden $90^\circ$ çıkarılır, çünkü kosinüs $90^\circ$ öndedir: $v_1=6\cos(20t+40^\circ-90^\circ)=6\cos(20t-50^\circ)$.
- $v_2$'nin genliği negatiftir. Bir sinüs ya da kosinüsün katsayısının işaretini değiştirmek, içerideki açıyı $180^\circ$ değiştirmeye denktir: $v_2=4\cos(20t+20^\circ-180^\circ)=4\cos(20t-160^\circ)$.
- Seçilen $v_1$, referans $v_2$: $-50^\circ-(-160^\circ)=110^\circ>0$. Sonuç: $v_1$, $v_2$'den $110^\circ$ öndedir.

Hoca burada $+180^\circ$ de eklenebileceğini, bu durumda açının $200^\circ$ olacağını söyledi. Ancak karşılaştırılan açılar arasındaki farkın $180^\circ$ sınırı içinde tutulması yorumu kolaylaştırır.

**Sinüs biçimiyle:**

- $v_1=6\sin(20t+40^\circ)$ aynen kalır.
- Kosinüsü sinüse çevirmek için $+90^\circ$, eksi işareti gidermek için $-180^\circ$ gerekir. Toplamda $-90^\circ$: $v_2=4\sin(20t+20^\circ-90^\circ)=4\sin(20t-70^\circ)$.
- $40^\circ-(-70^\circ)=110^\circ$. Yine $v_1$, $v_2$'den $110^\circ$ öndedir.

> **Hocanın vurgusu:** "Burası önemliydi arkadaşlar." İki biçimle de aynı faz farkının çıkması gerekir.

### 8.2 Sinüs ve kosinüsün grafikte karşılaştırılması

Sonraki slaytta kırmızı sinüs ve mavi kosinüs çizilmişti. Kosinüs sıfıra indiğinde sinüs ancak $90^\circ$ sonra sıfıra iner; yani sinüs, kosinüsten $90^\circ$ geridedir. Bu yüzden:

- Sinüsü kosinüs biçimine getirmek için $-90^\circ$ eklenir.
- Kosinüsü sinüs biçimine getirmek için $+90^\circ$ eklenir.

Hoca bunun kesinlikle lazım olacağını söyledi, çünkü fazöre geçerken sinyaller kosinüs biçimine getirilecek.

### 8.3 İşaret düzeltmede $+180^\circ$ mi, $-180^\circ$ mi?

Hoca iki örnekle doğru işaretin nasıl seçileceğini gösterdi. <!-- BELİRSİZ: Bu iki örneğin slaytları karelerde yok. Genlikler ve $\omega$ altyazıdan okunamadı; açılar altyazıdaki ara işlemlerden kuruldu. -->

**Birinci örnek:** $v_1$ sinüs ve $+10^\circ$ kaydırılmış, $v_2$ eksi işaretli bir kosinüs ve $-30^\circ$ kaydırılmış.

- $v_1$ kosinüse çevrilir: $10^\circ-90^\circ=-80^\circ$.
- $v_2$'nin eksi işaretini kaldırmak için $-180^\circ$ eklenirse $-30^\circ-180^\circ=-210^\circ$ olur. $+180^\circ$ eklenseydi $+150^\circ$ olurdu; $-80^\circ$ ile farkı $180^\circ$ sınırının dışına çıkardı.
- $-80^\circ-(-210^\circ)=130^\circ>0$. Sonuç: $v_1$ öndedir.

**İkinci örnek:** Bu kez eksi işaret sinüs sinyalindedir; kosinüsün açısı $-30^\circ$'dir.

- Sinüs kosinüse çevrilir: $10^\circ-90^\circ=-80^\circ$.
- Eksi işaret için $-180^\circ$ eklenirse $-260^\circ$ olur ve $-30^\circ$ ile fark büyür. $+180^\circ$ eklenirse $+100^\circ$ olur.
- $100^\circ-(-30^\circ)=130^\circ>0$. Sonuç: $v_1$, $v_2$'den $130^\circ$ öndedir.

### 8.4 Dönüşüm tablosu

Slayttaki tablo (ekrandan, 01:26:13):

| Biçim | Eşdeğeri |
|---|---|
| $A\sin(\omega t+\phi)$ | $A\cos(\omega t+\phi-90^\circ)$ |
| $-A\sin(\omega t+\phi)$ | $A\sin(\omega t+\phi+180^\circ)$ ya da $A\sin(\omega t+\phi-180^\circ)$ |
| $-A\cos(\omega t+\phi)$ | $A\cos(\omega t+\phi+180^\circ)$ ya da $A\cos(\omega t+\phi-180^\circ)$ |
| $A\sin(\omega t+\phi)$ | $A\sin(\omega t+\phi\mp360^\circ)$ |
| $A\cos(\omega t+\phi)$ | $A\cos(\omega t+\phi\mp360^\circ)$ |

### 8.5 İki sinyali karşılaştırma adımları

1. İki sinyalin frekansı aynı mı? Değilse karşılaştırma yapılmaz.
2. İkisi aynı trigonometrik fonksiyona (sinüs ya da kosinüs) getirilir.
3. Genliklerin işareti aynı yapılır (genelde ikisi de pozitif); bunun için $\pm180^\circ$ eklenir ya da çıkarılır.
4. Faz açıları birbirinden çıkarılarak faz farkı bulunur.

## 9. Fazör Gösterimi

### 9.1 Karmaşık sayıdan fazöre

Hoca kısa bir tekrar yaptı. $z=x+jy$ sayısının fazör gösterimi $V_m\angle\phi$'dir; burada $V_m=\sqrt{x^2+y^2}$, $\phi=\tan^{-1}(y/x)$. Aynı sayı üstel biçimde $V_me^{j\phi}$, trigonometrik biçimde $x=V_m\cos\phi$, $y=V_m\sin\phi$ diye yazılır.

Özel durumlar:

- Sanal kısmı olmayan bir sayı: pozitifse açısı $0^\circ$, negatifse $\pm180^\circ$'dir. Örneğin $-V_m=V_m\angle180^\circ$.
- Yalnız sanal kısmı olan bir sayı: sanal kısım pozitifse açı $90^\circ$, negatifse $-90^\circ$'dir.

> **Ders sonrası not:** Hoca pozitif reel sayının açısını bir yerde "normal 180" dedi. Pozitif reel sayının açısı $0^\circ$'dir; $\pm180^\circ$ negatif reel sayıya aittir.

Bir sinüzoidal sinyal, başka bir sinyale göre faz açısı $\phi$ kadar ötelenmiş olarak yazılır.

### 9.2 Sinüzoidal fonksiyonu fazöre çevirme

> **Hocanın vurgusu:** Önce sinyal kosinüs biçimine getirilir. Kosinüs biçimindeki sinyalin genliği fazörün genliğini, içindeki açı da fazörün faz açısını doğrudan verir.

Slayttaki örnekler (ekrandan, 01:31:13):

- $3\sin(100t+20^\circ)\,\text{V}=3\cos(100t-70^\circ)\,\text{V}$. Fazör: $3\angle-70^\circ\,\text{V}$.
- $7\sin(350t-100^\circ)\,\text{A}=7\cos(350t-190^\circ)\,\text{A}$. $-190^\circ$ açısı $\pm180^\circ$ sınırının dışındadır. Önce $180^\circ$ eklenince $-7\cos(350t-10^\circ)$ olur; bir $180^\circ$ daha eklenince (toplamda $360^\circ$, sinyal değişmez) $7\cos(350t+170^\circ)$ elde edilir. Fazör: $7\angle170^\circ\,\text{A}$.

Fazörde sinyalin frekans bilgisi yoktur. $7\angle170^\circ$ yalnız "7 A genlikli, zaman ekseninde $170^\circ$ kaymış bir akım" demektir. Frekans, $\omega t=2\pi f t$ teriminde saklıdır. İkinci örnekte $350/(2\pi)\approx55.7\,\text{Hz}$'tir (python ile $55.70\,\text{Hz}$).

> **Hocanın vurgusu:** Fazör gösterimi, devredeki bütün gerilim ve akım kaynaklarının frekansının aynı olduğu varsayımıyla çalışır. Frekanslar farklıysa fazör notasyonu kullanılamaz. Amaç frekans bilgisini atıp hesabı sadeleştirmektir.

### 9.3 Dikdörtgen biçimden fazöre ve trigonometrik biçim

Dönüşüm formülü her zaman aynıdır: açı $\tan^{-1}(b/a)$, genlik $\sqrt{a^2+b^2}$. Bir fazör kosinüs ve sinüs bileşenleriyle de yazılabilir. Hoca $5+3j$ örneğini verdi: genlik $\sqrt{34}\approx5.83$, açı $\approx31^\circ$. Buna göre

$$5+3j=5.83\cos31^\circ+j\,5.83\sin31^\circ$$

Python: $|5+3j|=5.831$, açı $30.96^\circ$. Hoca bu gösterimin de geçerli olduğunu, ancak işlemlerin her zaman polar gösterimde yapılacağını söyledi.

## 10. Tekillik Fonksiyonlarıyla Dalga Biçimleri (Tekrar)

Hoca, önceki derste görülen tekillik fonksiyonlarını kısaca tekrar etti. Girişteki gerilimin illa bir anahtarla bağlanması gerekmez; gerilim bir fonksiyonla da tanımlanabilir. Basit fonksiyonlar birleştirilerek karmaşık sinyaller üretilebilir.

Slayttaki tanım (ekrandan, 01:36:13): tekillik fonksiyonları süreksizdir ya da türevleri süreksizdir. Bunlara anahtarlama (switching) fonksiyonları da denir. İmpuls, birim basamak, darbe (pulse), kare dalga ve rampa (üçgen ve testere dişi) fonksiyonları bu gruptadır. Bunların birleşimleriyle karmaşık bileşik dalga biçimleri tanımlanabilir. <!-- BELİRSİZ: Aşağıdaki dalga biçimi örneklerinin slaytları karelerde yok; ifadeler altyazıdaki anlatımdan kuruldu. -->

- **Basamak:** $V_0u(t-t_0)$, genliği $V_0$ olan ve $t_0$ anında başlayan gerilimdir.
- **Darbe:** $t_0$ anında $V_0$ uygulanır, $t_1$ anında aynı genlikte negatif bir basamakla sıfırlanır: $V_0u(t-t_0)-V_0u(t-t_1)$.
- **Kare dalga:** $t_0$ anında $3u$ ile $+3$ seviyesine çıkılır. $t_1$ anında $-3$'e inmek için $6u$ çıkarılır. $t_2$ anında sıfıra dönmek için $3u$ geri eklenir: $3u(t-t_0)-6u(t-t_1)+3u(t-t_2)$.
- **Rampa:** $r(t-t_0)=(t-t_0)\,u(t-t_0)$; $t_0$'dan sonra doğrusal artan sinyal.
- **Testere dişi:** Rampa, belirli bir aralıkta 1, dışında 0 olan bir darbeyle çarpılır. Darbe sıfır olan yerlerde sinyal sıfırdır; $t_1$ anında darbe kapanınca sinyal sıfıra düşer.
- **Üçgen dalga:** $t_0$'da bir rampa başlar. $t_1$'de iki rampa çıkarılır; tek rampa çıkarılsaydı sinyal düz devam ederdi, iki rampa çıkarılınca aşağı doğru iner. $t_2$'de bir rampa daha eklenerek sıfırlanır: $r(t-t_0)-2r(t-t_1)+r(t-t_2)$ (eğim katsayısı ihmal edilmiştir).

Bileşik dalga biçimleri (ekrandan, 01:41:13): Sinüzoidal olmayan her fonksiyon birden çok sinüzoidal fonksiyonun toplamı olarak yazılabilir. Bu sinüslerin frekansları, temel frekans denen bir frekansın tam katlarıdır. Yüksek frekanslı bileşenlere harmonik denir. Çift ve tek harmoniklerde çarpan sırasıyla çift ve tek tam sayıdır; 2. ve 3. harmoniğin çarpanı 2 ve 3'tür.

## 11. Sinüzoidal Kaynaklı Devreler ve Fazörle Çözüm

### 11.1 RL devresi ve sonsuza kadar süren salınım

Slayttaki devre (ekrandan, 01:51:13): $V_0\cos(\omega t)$ kaynağı, seri $R$ ve $L$. KVL'den kaynak gerilimi, direnç ve bobin gerilimlerinin toplamına eşittir:

$$\frac{di(t)}{dt}+\frac RL\,i(t)=\frac{V_0}L\cos(\omega t)$$

Bu denklemin çözümü sonsuza kadar salınır ve hiçbir zaman bir DC değere (örneğin sıfıra) oturmaz. Sinüsün işareti sürekli değiştiği için devre doyuma ulaşmadan farklı bir polaritede gerilimle karşılaşır. Slayttaki çözüm yolu: çözümün $i(t)=I_0\cos(\omega t+\theta)$ biçiminde olduğu varsayılır ve denkleme konur:

$$-\omega I_0\sin(\omega t+\theta)+\frac RL I_0\cos(\omega t+\theta)=\frac{V_0}L\cos(\omega t)$$

$I_0$ çözülüp yerine konunca:

$$i(t)=\frac{V_0}{\sqrt{R^2+\omega^2L^2}}\cos\!\left(\omega t-\tan^{-1}\frac{\omega L}R\right)$$

Sonuçta genlik ölçeklenir (amplitude scaling) ve faz kayar (phase shift). Bunu her seferinde diferansiyel denklemle yapmak yerine fazör kullanılır; çünkü $\omega t$'nin etkisine yalnız $L$ (ve $C$) üzerinde bakılır.

Hoca sonraki slaytlarda aynı devreyi sayısal değerlerle gösterdi. Zaman sabiti yaklaşık $1\,\mu\text{s}$ olan bu devrede $5\tau$'ya kadar geçiş analizi yapılır. Ondan sonra devre durağan bir değere oturmaz, sinüs dalgasıyla devam eder. RC ve RLC devrelerinde de durum aynıdır: $5\tau$'ya kadar geçiş (RLC'de az, kritik ya da aşırı sönümlü) incelenir; sonrasında sinüzoidal sürekli hal polar biçimde (fazörle) analiz edilir. <!-- BELİRSİZ: Bu slaytlardaki R ve L değerleri altyazıdan okunamadı. -->

Hoca girişteki sinüzoidal kaynağın devreye bir reel, bir de sanal bileşenle etki ettiğini söyledi: reel kısım direnç üzerindeki etkiyi, sanal kısım bobin ve kondansatör üzerindeki etkiyi gösterir.

### 11.2 Fazör notasyonuyla devre

Slayttaki gösterim (ekrandan, 01:56:13): seri RLC devresinde kaynak $V_m\cos(\omega t+\theta_1)$, akım $I_m\cos(\omega t+\theta_2)$ olsun. Fazör karşılıkları:

$$V_m\cos(\omega t+\theta_1)=\mathrm{Re}\{V_me^{j(\omega t+\theta_1)}\}=\mathrm{Re}\{V_me^{j\omega t}e^{j\theta_1}\}\Rightarrow V_me^{j\theta_1}=V_m\angle\theta_1$$

$$I_m\cos(\omega t+\theta_2)\Rightarrow I_m\angle\theta_2$$

Bütün gerilim ve akımların aynı $\omega=2\pi f$ frekansıyla salındığı varsayılır. Her gerilim ve akımın genliği ile fazı alınır, polar biçimde yazılır. Böylece $\omega t$ akım ve gerilim hesabından atılır. Frekansın etkisi yalnız bobin ve kondansatörün parametrelerine ($j\omega L$, $j\omega C$) katılır. Sonra fazör gösteriminde olağan devre işlemleri yapılır.

Elemanlarda akım-gerilim faz ilişkisi:

- **Direnç:** frekansın etkisi yoktur; akım ve gerilim aynı fazdadır.
- **Bobin:** gerilim akımdan $90^\circ$ öndedir. Bobinin etkisi $\omega L=2\pi fL$ terimiyle frekansa bağlıdır.
- **Kondansatör:** akım gerilimden $90^\circ$ öndedir; hesapta $\omega C$ terimi kullanılır.

### 11.3 Paralel RLC örneği (Example 02)

Slayttaki soru (ekrandan, 02:01:13): $v(t)$'yi bulunuz. Kaynak $i_s(t)=8\cos(2\pi\cdot10^6t+30^\circ)\,\text{mA}$'dir. Akım kaynağına paralel $70\,\Omega$ direnç, $10\,\mu\text{H}$ bobin ve $2\,\text{nF}$ kondansatör bağlıdır; $v(t)$ hepsinin üzerindeki ortak gerilimdir.

**Adım 1: kaynağı yorumla ve fazöre çevir.** $2\pi\cdot10^6t$ terimi $2\pi ft$'dir; demek ki $f=1\,\text{MHz}$. $30^\circ$ faz açısıdır. Kaynak zaten kosinüs biçiminde olduğu için doğrudan yazılır: $\mathbf I_s=8\angle30^\circ\,\text{mA}$. İşlemlerin geri kalanı bu fazör üzerinden yürür.

**Adım 2: KCL yaz.** Düğüme giren akım çıkan akımların toplamına eşittir:

$$\mathbf I_s-\frac{\mathbf V}R-\frac{\mathbf V}{j\omega L}-j\omega C\,\mathbf V=0$$

Bobin akımı $\mathbf V/(j\omega L)$, kondansatör akımı $j\omega C\,\mathbf V$'dir (hoca, kondansatör için bölme değil çarpma olduğunu belirtti). Değerler yerine konunca:

$$8\angle30^\circ-\frac{\mathbf V}{70}-\frac{\mathbf V}{j(2\pi\cdot10^6)(10\cdot10^{-6})}-j(2\pi\cdot10^6)(2\cdot10^{-9})\mathbf V=0$$

**Adım 3: $\mathbf V$'yi çek.** Toplam admitans (ara adım eklendi; python ile hesaplandı):

- $1/R=1/70=0.014286\,\text{S}$,
- $\omega L=2\pi\cdot10^6\cdot10^{-5}=62.83\,\Omega$, yani $1/(j\omega L)=-j\,0.015915\,\text{S}$,
- $\omega C=2\pi\cdot10^6\cdot2\cdot10^{-9}=0.012566\,\text{S}$,
- $Y=0.014286-j\,0.003349\,\text{S}=0.014673\angle-13.19^\circ\,\text{S}$.

Hoca da dikdörtgen biçimi fazöre çevirdi: genlik karelerin toplamının karekökünden, açı $\tan^{-1}(0.0033/0.0143)$'ten bulundu. Sonra

$$\mathbf V=\frac{8\angle30^\circ\,\text{mA}}{0.01467\angle-13.19^\circ\,\text{S}}\approx545\angle43.2^\circ\,\text{mV}$$

> **Ders sonrası not:** Hoca reel kısmı "0.00143", genliği "0.00147" diye okudu; doğrusu $1/70=0.0143$ ve $|Y|=0.0147\,\text{S}$. Sonuç $\mathbf V\approx0.545\angle43.2^\circ\,\text{V}$ (python ile kontrol edildi).

> **Hocanın vurgusu:** Hoca, fazör olarak bulunan $\mathbf V$'nin zaman domenine nasıl geri çevrileceğini araştırma sorusu olarak bıraktı: "Bunu öğreneceğiz." Ekstra bir doküman istemediğini, ama konunun öğrenilmesini beklediğini söyledi. Bu konunun kritik olduğunu, sınavda kesinlikle soru geleceğini ve sonraki derste örnek çözüleceğini belirtti.

## Örnek Sorular

**Soru 1** (ekrandan, 00:31:13): $M=3+4j$ ve $N=\tfrac3{\sqrt2}+\tfrac3{\sqrt2}j$ ise $M\cdot N$ çarpımını polar biçimde bulunuz.

> **Çözüm:** $M=5\angle53^\circ$, $N=3\angle45^\circ$. Genlikler çarpılır, açılar toplanır: $MN=15\angle98^\circ$.

**Soru 2** (ekrandan, 00:21:13): $X=3+j2$ ve $Y=2+j5$ ise $X/Y$ bölümünü dikdörtgen biçimde bulunuz.

> **Çözüm:** Derste payda $2^2+5^2=29$ olarak kuruldu. Tamamlanırsa: $\dfrac{(3+j2)(2-j5)}{29}=\dfrac{16-j11}{29}\approx0.552-j0.379$.

**Soru 3** (derste sözlü, 00:47:48): $v(t)=5\sin(377t)\,\text{V}$ sinyalinin $t=10\,\text{ms}$ anındaki değeri nedir?

> **Çözüm:** $377\cdot0.01=3.77\,\text{rad}\approx216^\circ$, $v=5\sin216^\circ\approx-2.94\,\text{V}$. Derste radyanın dereceye çevrilmesi gerektiği gösterildi, ancak sayısal sonuç verilmedi.

**Soru 4** (ekrandan, 01:06:13 ve 01:11:13): Periyodu $500\,\text{s}$ ve genliği 5 V olan üç sinyalden Signal 2, referans Signal 1'den $40\,\text{s}$ sonra sıfırdan geçiyor; Signal 3 için kayma $480\,\text{s}$ ölçülüyor. Faz açılarını bulup önde mi geride mi olduklarını yorumlayınız.

> **Çözüm:** $\omega=2\pi/500=12.6\,\text{mrad/s}$. $\phi_2=-360^\circ\cdot40/500=-28.8^\circ$ (lag). $\phi_3=-360^\circ\cdot480/500+360^\circ=+14.4^\circ$ (lead).

**Soru 5** (ekrandan, 01:16:13): $v_1=6\sin(20t+40^\circ)\,\text{V}$ ve $v_2=-4\cos(20t+20^\circ)\,\text{V}$ arasındaki faz farkını bulunuz. Hangisi öndedir?

> **Çözüm:** $v_1=6\cos(20t-50^\circ)$, $v_2=4\cos(20t-160^\circ)$. $-50^\circ-(-160^\circ)=110^\circ$. $v_1$, $v_2$'den $110^\circ$ öndedir. Sinüs biçimiyle de $v_2=4\sin(20t-70^\circ)$ ve $40^\circ-(-70^\circ)=110^\circ$ bulunur.

**Soru 6** (ekrandan, 01:31:13): $3\sin(100t+20^\circ)\,\text{V}$ ve $7\sin(350t-100^\circ)\,\text{A}$ ifadelerini fazör gösterimine çeviriniz.

> **Çözüm:** $3\cos(100t-70^\circ)\Rightarrow3\angle-70^\circ\,\text{V}$. $7\cos(350t-190^\circ)=-7\cos(350t-10^\circ)=7\cos(350t+170^\circ)\Rightarrow7\angle170^\circ\,\text{A}$.

**Soru 7** (ekrandan, 02:01:13): $i_s(t)=8\cos(2\pi\cdot10^6t+30^\circ)\,\text{mA}$ akım kaynağına paralel $70\,\Omega$, $10\,\mu\text{H}$ ve $2\,\text{nF}$ bağlıdır. $v(t)$'yi bulunuz.

> **Çözüm (fazör kısmı derste verildi):** $\mathbf I_s=8\angle30^\circ\,\text{mA}$; KCL: $\mathbf I_s-\mathbf V/70-\mathbf V/(j\omega L)-j\omega C\mathbf V=0$. Buradan $Y=0.01467\angle-13.19^\circ\,\text{S}$ ve $\mathbf V\approx0.545\angle43.2^\circ\,\text{V}$.

> **Çözüm (derste verilmedi):** Zaman domenine dönüş fazörün tanımından yapılır: $\mathbf V=V_m\angle\theta$ ise $v(t)=V_m\cos(\omega t+\theta)$. Buna göre $v(t)\approx545\cos(2\pi\cdot10^6t+43.2^\circ)\,\text{mV}$ (python ile hesaplandı).

## Dersin Toparlaması

Bu derste DC kaynaklı birinci ve ikinci dereceden devrelerden AC kaynaklı devrelere geçildi. AC'de devre hiçbir zaman sabit bir değere oturmadığı için analizin karmaşık sayılara dayanan fazör domeninde yapılacağı anlatıldı. Önce karmaşık sayıların dikdörtgen, üstel ve polar biçimleri, aralarındaki dönüşümler ve dört işlem tekrar edildi: toplama ve çıkarma dikdörtgen biçimde, çarpma ve bölme polar biçimde kolaydır. Ardından sinüs dalgasının periyodu, frekansı, açısal frekansı, tepe ve tepeden tepeye genliği, anlık, ortalama ve RMS değerleri tanımlandı; radyan-derece karışıklığına karşı uyarı yapıldı. Faz açısıyla aynı frekanstaki sinyallerin önde ya da geride olduğunun nasıl belirleneceği, sinüs-kosinüs dönüşümleri ve $\pm180^\circ$ ile işaret düzeltme örneklerle gösterildi.

Son bölümde sinüzoidal fonksiyonların kosinüs biçimine getirilip $V_m\angle\theta$ fazörüne çevrilmesi, bütün kaynakların aynı frekansta olması koşulu, RL devresinde sinüzoidal kaynağın sonsuza kadar süren salınım yaratması ve fazörle KCL kullanılarak paralel RLC devresinin çözümü işlendi. Fazörden zaman domenine dönüş öğrencilere araştırma konusu olarak bırakıldı; bir sonraki derste bu konuyla ilgili örnekler çözülecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
