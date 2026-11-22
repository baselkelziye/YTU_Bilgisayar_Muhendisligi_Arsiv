# Ders 9 Çalışma Özeti

## Genel Konular

- Seri diyot devrelerinde ideal ve gerçek diyot
  - Soruda diyotun silisyum (Si) olduğu belirtilmişse ve "ideal" denmemişse diyot gerçek kabul edilir: iletimdeyken uçlarında Si için 0,7 V, Ge için 0,3 V düşer. Soruda böyle bir ibare yoksa diyot ideal kabul edilir.
  - Slayttaki seri devre analizi (Si için): $V_D = 0{,}7$ V (ya da $E < 0{,}7$ V ise $V_D = E$), $V_R = E - V_D$, $I_D = I_R = I_T = V_R/R$ (ekrandan, 00:15:00).
  - Voltmetrenin nereye bağlandığı sonucu belirler. Diyotun uçlarına bağlanırsa iletimde 0,7 V, kesimde kaynak gerilimi $E$ okunur. Direncin uçlarına bağlanırsa iletimde $E - 0{,}7$ V, kesimde 0 V okunur.
  - İki eş Si diyot paralel bağlandığında aynı iç dirence sahip oldukları için akım teoride ikisine eşit paylaşılır.
- Doğrultucular (tekrar)
  - Yarım dalga doğrultucu tek diyot ve bir dirençle kurulur, AC işaretin yalnız bir yarısını geçirir. Çıkışın DC değeri $V_{DC} = 0{,}318V_m$'dir (ekrandan, 00:20:00).
  - Tam dalga doğrultucu iki yarıyı da aynı yönde geçirir: $V_{DC} = 0{,}636V_m$. Köprü tipi en çok kullanılan tam dalga doğrultucudur.
  - Köprü doğrultucuda her yarım periyotta akım iki diyottan geçer, gerçek diyotlarda iki kez 0,7 V kaybedilir. Orta uçlu transformatörlü doğrultucuda akım tek diyottan geçer (ekrandan, 00:25:00).
  - Ölçüm uçlarının yeri değiştirilirse ya da diyot yönleri ters çevrilirse aynı devre negatif çıkış verir.
- Kırpıcılar (clipper)
  - Kırpıcı, girişin belli bir seviyenin üstünü ya da altını kırpar. Yarım dalga doğrultucu da bir kırpıcıdır, ama her kırpıcı doğrultucu değildir.
  - Kutuplu (bias) kırpıcıda bir DC kaynak diyotun iletime geçtiği seviyeyi kaydırır. Analiz önce $t = 0$ anında (giriş sıfırken) diyotun iletimde mi kesimde mi olduğuna bakılarak başlar.
  - Seri kırpıcıda diyot iletimdeyken çıkış girişi (kaynak gerilimi kadar kaymış olarak) izler, kesimdeyken çıkış 0 olur. Paralel kırpıcıda diyot iletimdeyken çıkış diyotla seri kaynağın gerilimine sabitlenir, kesimdeyken çıkış girişi izler (ekrandan, 00:40:00).
  - Çift diyotlu paralel kırpıcı (alt-üst kırpıcı) çıkışı $V_1$ ile $-V_2$ arasına sınırlar.
  - Kırpıcıda çıkış hiçbir zaman $\pm V_m$ sınırının dışına çıkamaz; bunun için enerji depolayan bir eleman (kondansatör) gerekir.
- Kenetleyiciler (clamper)
  - Diyot ve kondansatör birlikte AC işareti belirli bir DC seviyeye kenetler (ekrandan, 00:50:00). Kondansatör gerilim biçiminde enerji depolar.
  - Kare dalga örneği: $+V$ yarısında diyot iletir, kondansatör $V$'ye dolar ve çıkış 0 olur. $-V$ yarısında diyot kesimdedir, giriş ile kondansatör gerilimi seri toplanır ve çıkış $-2V$ olur.
  - Kenetleyici analizinde $t = 0$ anı yorumlanmaz; önce kararlı durumda kondansatörün neye dolduğu bulunur.
  - Kutuplu kenetleyici örneği: $\pm 20$ V sinüs giriş ve diyotla seri 10 V kaynak ile çıkış $+30$ V ile $-10$ V arasında salınır (ekrandan, 00:55:00).
- Zener diyot
  - Zener diyot ters polarmada zener gerilimi $V_Z$'de çalışır. $V_i \ge V_Z$ ise zener iletimdedir, uçlarındaki gerilim $V_Z$'dir; $V_i < V_Z$ ise açık devredir (ekrandan, 01:05:00).
  - Zener akımı $I_Z = I_R - I_{RL}$, zener gücü $P_Z = V_Z I_Z$'dir.
  - Yük direnci zenere paralel olduğu için $R_L$ üzerindeki gerilim de $V_Z$'dir; $R_L = V_Z / I_L$ ile yük akımının sınırlarından $R_L$'nin sınırları bulunur.
- Gerilim katlayıcılar
  - Diyot-kondansatör (kenetleyici) yapıları art arda bağlanarak gerilim iki, üç ve dört katına çıkarılır (ekrandan, 01:10:00).
  - Katlayıcıda $C_1$ $V_m$'ye, sonraki kondansatörler $2V_m$'ye dolar; çıkış alınan uçlara göre $2V_m$, $3V_m$ ya da $4V_m$ elde edilir.
  - Gerçek diyotlarda $C_1$ $V_m - 0{,}7$'ye, $C_2$ $2V_m - 1{,}4$'e dolar.
  - Uygulamalar: AC-DC adaptörler ve batarya şarj devreleri doğrultucu içerir. Koruma devrelerinde (protective circuit) diyot ters yönlü akımı engellemek için kullanılır.
- Bipolar transistöre (BJT) giriş
  - Transistör de p-n eklemine dayanan bir yarı iletkendir; diyottan farkı üç terminalli olmasıdır: emetör (E), baz (B), kollektör (C) (ekrandan, 01:20:00).
  - İki tipi vardır: pnp (baz n tipi) ve npn (baz p tipi). Elektronik devrelerde en çok npn kullanılır.
  - Çalışma koşulu: emetör-baz eklemi doğru polarmalı (tükenme bölgesi daralır), baz-kollektör eklemi ters polarmalı (tükenme bölgesi genişler).
  - Akım ilişkisi (KCL): $I_E = I_C + I_B$ (ekrandan, 01:25:00).
  - Sembolde ok emetör ucundadır ve her zaman n tipi bölgeyi gösterir. Ok bazı gösteriyorsa pnp, dışarıyı (emetörü) gösteriyorsa npn'dir.

## Hocanın Özellikle Vurguladığı Kısımlar

- İdeal olmayan diyotta 0,7 V'u unutmamak
  - Soruda Si belirtilip ideal denmemişse 0,7 V hesaba katılmazsa çizilen grafik yanlış çıkar. Hoca bunu ayrıca vurguladı.
- Voltmetre nereyi ölçüyor
  - Seri ve paralel kırpıcılar sınavlarda en çok karıştırılan yerdir. İletimde diyot (ve seri kaynak) gerilimi, kesimde giriş gerilimi okunur; ölçülen uç değişince sonuç da değişir.
- Kırpıcı ile kenetleyici farkı
  - Kondansatör yoksa devre kenetleyici olamaz ve çıkış $\pm V_m$'nin dışına çıkamaz. Kondansatörsüz bir devre için $-(V_m + V)$ gibi sınırları aşan bir sonuç bulunmuşsa (seri kaynak etkisi dışında) yanlış yapılmıştır.
- Kenetleyicide önce kondansatörün dolduğu gerilim
  - Kondansatörlü analizlerde ilk iş kondansatörün neye dolduğunu bulmaktır.
- Zener gücü
  - Zener gücü giriş gerilimiyle değil, $V_Z \cdot I_Z$ ile hesaplanır. Örneğin $V_Z = 50$ V, giriş 70 V ise güç $70 \cdot I_Z$ değil $50 \cdot I_Z$'dir. Hoca bunun önemli bir konu olduğunu belirtti.
- Devreleri simülasyonda denemek
  - Kırpıcı ve kenetleyicilerin farklı kaynak değerleriyle (örneğin seri kaynağı 5 V ya da 1-2 V yapmak, $V_1$'i sınır değerine eşitlemek) PSpice, Multisim gibi bir ortamda kurulup denenmesi önerildi.
- Transistör sembolü
  - Sembolün pnp mi npn mi olduğu, eklemlerin nasıl polarlanacağını belirler; ok kuralı iyi bilinmelidir. $I_E = I_C + I_B$ ilişkisi bütün problemlerde kullanılacaktır.

## Kısa Tekrar Notları

- Si: 0,7 V, Ge: 0,3 V. "İdeal" denmemiş ve malzeme verilmişse gerçek diyot kullanılır.
- Yarım dalga $V_{DC} = 0{,}318V_m$ (gerçek: $0{,}318V_m - 0{,}7$); köprü $0{,}636V_m$ (gerçek: $0{,}636V_m - 1{,}4$); orta uçlu $0{,}636V_m$ (gerçek: $0{,}636V_m - 0{,}7$) (ekrandan, 00:25:00).
- Köprüde her yarı periyotta iki diyot iletir, orta uçlu transformatörlüde bir diyot.
- Kırpıcıda $t = 0$ anına bak; kenetleyicide önce kondansatör gerilimini bul.
- Kare dalga kenetleyici: çıkış genliği $2V$ olur, DC seviye diyot yönüne ve seri kaynağa göre kayar.
- Kutuplu kenetleyici örneği: $\pm 20$ V giriş, 10 V kaynak → çıkış $+30$ / $-10$ V.
- Zener: $I_Z = I_R - I_{RL}$, $P_Z = V_Z I_Z$, $V_{RL} = V_Z$.
- Katlayıcı: $C_1 \to V_m$, diğerleri $\to 2V_m$; gerçek diyotla $V_m - 0{,}7$ ve $2V_m - 1{,}4$.
- BJT: E-B doğru, B-C ters polarma; $I_E = I_C + I_B$; ok n tipini gösterir.

## Detaylı Açıklamalar

- Seri diyot devresinde ölçüm yeri
  - Kaynak $E$, Si diyot ve $R$ seri bağlı olsun. Diyot iletimdeyse uçlarında 0,7 V vardır, direnç üzerinde $E - 0{,}7$ V kalır. Diyot kesimdeyse akım geçmez; direnç üzerinde gerilim 0 olur, kaynak gerilimi diyotun uçlarında görülür. Bu yüzden soruda çıkışın diyot uçlarından mı direnç uçlarından mı alındığı her zaman önce kontrol edilmelidir. Paralel kırpıcıda da aynı mantıkla girişin çıkışta görülebilmesi için diyotun kesimde olması gerekir.
- Doğrultucunun DC değeri neden sınırlı
  - Bir öğrenci tam dalga doğrultucuda DC değerin neden $V_m$'ye eşit olmadığını sordu. Hoca, devrelerin DC ile beslendiğini ve devrenin girişin ortalamasını gördüğünü; doğrultulmuş işarette sinüs tepeleri arasında boşluklar bulunduğu için ortalamanın $V_m$'ye ulaşamayacağını anlattı. Transistörle anahtarlanan ek bir DC kaynakla bu aşılabilir, ama zaten bir DC kaynak varsa doğrudan onu kullanmak daha mantıklıdır.
  <!-- BELİRSİZ: Hoca frekans arttıkça ortalamanın Vm'ye yaklaştığını ve güç kaynaklarındaki %80-%95 değerlerini buna bağladı; bu kısım kısa notta kesin bilgi olarak verilmedi (genişletilmiş nottaki ders sonrası nota bakın). -->
- Köprü doğrultucuda düşük giriş
  - Hoca, gerçek diyotlu köprüde her yarı periyotta iki diyotun toplam 1,4 V kaybettirdiğini, 2 V tepeli bir girişte bunun çok büyük bir kayıp olduğunu örnekledi. <!-- BELİRSİZ: Hoca bu durumda devrenin hiç çalışmayacağını söyledi; tepe 2 V > 1,4 V olduğu için çıkışta büyük olasılıkla 0,6 V tepeli küçük bir işaret yine oluşur. -->
- Orta uçlu transformatörlü doğrultucu
  - Transformatör girişi genliği iki katına çıkarmaz; aynı işareti iki kanala (iki yarı sargıya) çoğaltır. Pozitif yarıda üst diyot, negatif yarıda alt diyot iletir ve yük üzerinde iki yarıda da aynı yönde gerilim oluşur.
- Kutuplu seri kırpıcı
  - Diyotla seri bir kaynak varsa giriş sıfırken diyotun durumu kaynağın yönüne bağlıdır. Kaynak diyotu iletime sokuyorsa çıkışta başlangıçta kaynak gerilimi (işaretine dikkat ederek) okunur; giriş bu kaynağı dengeleyecek değere ulaşınca diyot kesime gider ve çıkış 0 olur. Çıkışın işareti, direncin üzerindeki $+/-$ referansı ile akım yönünün uyumuna göre belirlenir: akım referansın tersi yönde akıyorsa ölçülen gerilim negatiftir.
- Kare dalga kenetleyici
  - $+V$ yarısında diyot iletir ve kondansatör $V$'ye dolar. $-V$ yarısında diyot kesime gider; giriş ($V$) ve kondansatör ($V$) seri iki batarya gibi toplanır, akım direnç üzerinden referansın tersi yönde akar ve çıkışta $-2V$ okunur. Bir öğrencinin sorusu üzerine hoca, bu yarıda diyotun uçlarında da $2V$ görüleceğini belirtti.
- Kutuplu kenetleyici sayısal örneği
  - Slayttaki devrede (ekrandan, 00:55:00) giriş $\pm 20$ V sinüs, diyota seri 10 V kaynak vardır. Negatif yarıda diyot iletime geçer, çıkış $-10$ V'ta tutulur ve kondansatör $20 - 10 = 10$ V'a dolar. Pozitif yarıda diyot kesimdedir; çıkış $20 + 10 = 30$ V'a çıkar. Çıkış $+30$ V ile $-10$ V arasında salınır, tepe tepe değeri girişinki gibi 40 V'tur.
- Zener ile yük direnci soruları
  - Zener ve $R_L$ paralel olduğundan ikisinde de $V_Z$ vardır. $I_R = I_Z + I_L$ olduğu için yük akımı küçüldükçe zener akımı büyür. $R_L = V_Z / I_L$ ifadesinde $I_L$ en küçük alınırsa $R_L$'nin en büyük değeri, $I_L$ en büyük alınırsa en küçük değeri bulunur. Hoca "zener akımı en küçük olsun" ya da "yük direncini öyle ayarlayın ki..." biçiminde soruların bu ilişkilerden çözüleceğini söyledi.
- Gerilim üçleyici ile örnek
  - Hoca 10 V tepeli giriş için üçleyici çıkışının 30 V olacağını, bunun yarım dalga gibi düşünülüp $0{,}318$ ile çarpılırsa yaklaşık 9,5 V verdiğini anlattı (ekrandan, 01:15:00). <!-- BELİRSİZ: Bu hesap hocanın yorumudur; ideal katlayıcının çıkışı hafif yükte büyük olasılıkla yaklaşık sabit 3Vm DC'dir. -->
- BJT çalışma ilkesi
  - pnp transistörde emetör p, baz n, kollektör p tipidir. Emetör-baz eklemini doğru polarlamak için emetöre artı, baza eksi verilir; bu eklemin tükenme bölgesi daralır. Baz-kollektör eklemi ters polarlanır (kollektöre eksi), bu eklemin tükenme bölgesi genişler. npn'de bütün polariteler terstir. Slayttaki yapı şeklinde bazın çok ince olduğu görülür: toplam genişlik 0,150 inç, baz genişliği 0,001 inç (ekrandan, 01:20:00). Kollektör akımı çoğunluk ve azınlık bileşenlerinden oluşur: $I_C = I_{C,\text{çoğunluk}} + I_{CO,\text{azınlık}}$ (ekrandan, 01:25:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
