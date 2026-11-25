# Ders 11 Çalışma Özeti

## Genel Konular

- Sürekli sinüzoidal hal ve fazör yaklaşımının yeri
  - Önceki derslerde RL ve RC devreleri birinci, RLC devreleri ikinci dereceden diferansiyel denklemlerle zaman boyutunda çözülmüştü. Bu çözüm durum değişiminden önceki kararlı bölgeyi, yaklaşık $5\tau$ süren geçici hali ve sonraki kararlı bölgeyi kapsar.
  - Fazör çözümü özel bir çözümdür: geçici hal ile ilgilenmez, devre uzun süre sinüzoidal bir kaynakla sürülürken (pratikte $5\tau$ sonrasında) zorlanmış cevabı inceler. Buna sürekli sinüzoidal hal analizi denir.
  - Fazör uzayında kapasite ve endüktansın diferansiyel tanım bağıntıları doğrusal (cebirsel) denklemlere dönüşür. Her eleman bir **empedans** ile temsil edilir ve direnç gibi davranır: seri empedanslar toplanır, paralel empedanslar paralel direnç gibi birleştirilir, düğüm ve çevre yöntemleri aynen uygulanır.
  - Çözüm adımları: elemanları ve kaynakları fazör uzayına geçir, devreyi empedanslarla çöz, istenen gerilim ya da akımın fazörünü bul, bunu kaynak frekansını kullanarak zaman boyutuna geri çevir.
- Empedans ve gizli parametre $\omega$
  - Empedans, fazör gerilimin fazör akıma oranıdır: $Z = \mathbf{V}/\mathbf{I}$ (ohm). Direncin empedansı kendi değeridir; kapasite ve endüktans için farklı (karmaşık) değerler çıkar (ekrandan, 00:15:00: $50\ \Omega$, $-j30\ \Omega$, $j40\ \Omega$, $40\angle30^\circ\ \Omega$).
  - Devrede tek sinüzoidal kaynak (ya da aynı frekanslı birden fazla kaynak) varsa kararlı halde bütün elemanlar kaynak frekansında salınır. Bu yüzden $\omega$ fazör hesabında ayrı bir yerde saklanır, sonuç zaman boyutuna dönerken geri eklenir.
- Osiloskop örneği: RLC devresinde giriş ve çıkış (ekrandan, 00:20:00 ve 00:30:00)
  - Devre: $v_s$ kaynağı, seri $235\ \Omega$, çıkışta paralel bağlı $4.7$ nF kapasite ve $1$ mH endüktans; $v_o$ paralel LC üzerindeki gerilim. $v_s = \sin(2\pi f t)$ V.
  - Kanal 1 kaynağı, kanal 2 çıkışı toprağa göre ölçer. Yatay ölçek $20\ \mu s$/kare; bir periyot iki tepe, her tepe 5 kare: $T = 200\ \mu s$, $f = 1/T = 5$ kHz. Çıkışın periyodu da aynı çıkar.
  - Düşük frekansta ($f \to 0$) kapasite açık devre, endüktans kısa devre olur, $v_o = 0$. Çok yüksek frekansta kapasite kısa devre, endüktans açık devre olur, yine $v_o = 0$. Arada geçiş vardır: devre bant geçiren süzgeç gibi çalışır.
  - 5 kHz'te çıkış çok bastırılmıştır; orta frekansta (derste 50 kHz denildi) çıkış genliği girişe çok yaklaşır ve faz farkı azalır.
  - Üç gözlem: frekans değişince genlik oranı değişir, faz farkı değişir; bütün elemanlar kaynak frekansında salınır.
  - Slayttaki fazör örneği (ekrandan, 00:30:00): $v_s = \sin(2\pi\cdot10^4 t)$ V için $\mathbf{V}_s = 1.00e^{j0^\circ}$ V, KCL ile $\mathbf{V}_o = 0.25e^{j40^\circ}$ V, zamana dönüş: $v_o = 250\sin(2\pi\cdot10^4 t + 40^\circ)$ mV. Frekans kaynaktan gelir, genlik ve faz fazörden.
- Karmaşık sayılar (tekrar)
  - $j = \sqrt{-1}$; $Z = a + jb$, $\mathrm{Re}(Z) = a$, $\mathrm{Im}(Z) = b$. Gösterimler: kartezyen $a + jb$, üstel $re^{j\theta}$, polar $r\angle\theta$. Eşlenik, sayının reel eksene göre ayna görüntüsüdür.
  - Toplama/çıkarma kartezyende kolaydır: $(a+jb)+(c+jd) = (a+c)+j(b+d)$ (ekrandan, 00:35:00). Çarpma/bölme polar ya da üstel formda kolaydır: çarpmada genlikler çarpılır, açılar toplanır; bölmede genlikler bölünür, açılar çıkarılır.
  - Euler formülü $e^{j\theta} = \cos\theta + j\sin\theta$; $e^x$, $\cos x$ ve $\sin x$ Taylor açılımlarında $x = j\theta$ konularak elde edilir ($j$'nin kuvvetleri $1, j, -1, -j$ diye dörtlük periyotla tekrar eder).
  - Dönüşümler (ekrandan, 00:40:00): $a = |z|\cos\theta$, $b = |z|\sin\theta$, $|z| = \sqrt{a^2+b^2}$, $\tan\theta = b/a$. Örnek: $4 + 3j$ için $\theta = \arctan(3/4)$.
- Fazör uzayında Ohm yasası örneği (ekrandan, 00:45:00 ve 00:50:00)
  - Endüktans üzerinde $\mathbf{V}_L = -3\sqrt3 + 3j$ mV, $\mathbf{I}_L = 1 + j\sqrt3$ mA; $Z_L = \mathbf{V}_L/\mathbf{I}_L$.
  - Eşlenikle çarpma: $\dfrac{(-3\sqrt3+3j)(1-j\sqrt3)}{(1+j\sqrt3)(1-j\sqrt3)} = \dfrac{12j}{4} = 3j\ \Omega$.
  - Polar yol: $\dfrac{6\angle150^\circ}{2\angle60^\circ} = 3\angle90^\circ = 3j\ \Omega$. Saf sanal empedans, bir endüktanstan beklenen sonuçtur.
- Fazör uzayında güç
  - Güç, gerilim fazörü ile akım fazörünün **eşleniğinin** çarpımıyla bulunur: $\mathbf{S} = \mathbf{V}\mathbf{I}^*$. Çarpım kartezyende ya da polar formda yapılabilir; sonuçlar aynıdır. <!-- BELİRSİZ: örneğin gerilim ve akım değerleri karelerde görünmüyor, altyazıdaki sayılar tutarlı değil. -->
- Sinüzoidal işaretin özellikleri (ekrandan, 00:55:00 ve 01:00:00)
  - Periyot $T$ (saniye): işaretin kendini tekrarlaması için geçen süre; bir periyot bir çıkan ve bir inen tepeyi tam içerir, iki ardışık tepe arası da bir periyottur. Frekans $f = 1/T$ (Hz). Açısal frekans $\omega = 2\pi/T = 2\pi f$ (rad/s).
  - Genlik: sinüsün önündeki katsayı. Aynı frekanslı iki işaret yalnız genlikte farklı olabilir.
  - Tepeden tepeye genlik ($2A$): işarete DC ofset eklenince sıfır eksenine göre genlik okumak zorlaşır, tepeden tepeye değer kullanılır.
  - Anlık değer: $t$ yerine belirli bir $t_0$ konarak bulunur. Örnek (ekrandan, 01:10:00): $v(t) = 5\sin(377t)$ V için $v(0) = 0$ V, $v(10\text{ ms}) = -2.94$ V.
  - Ortalama değer: $\frac{1}{T}\int_0^T v(t)\,dt$; saf sinüsün bir periyottaki ortalaması sıfırdır. $A\sin(2\pi ft) + C$ işaretinin ortalaması $C$'dir (DC ofset).
  - RMS (etkin) değer (ekrandan, 01:15:00): $V_{RMS} = \sqrt{\frac{1}{T}\int_0^T v^2(t)\,dt}$. Bir dirençte sinüzoidal işaretle aynı gücü harcatan DC değerdir. Sinüs için $V_{RMS} = \frac{\sqrt2}{2}V_p = 0.707V_p$, $P_{ort} = V_{RMS}^2/R$. İspatta $\sin^2 x = \frac{1-\cos2x}{2}$ kullanılır.
  - Radyan-derece dönüşümü: $360^\circ = 2\pi$ rad; $60^\circ = \pi/3$ rad.
- Faz açısı, önde ve geride olma (ekrandan, 01:30:00 ve 01:35:00)
  - Faz açısı, aynı frekanslı işareti zaman ekseninde kaydırır; örneğin $A\sin(2\pi ft - 90^\circ)$, $A\sin(2\pi ft)$'nin $90^\circ$ sağa kaymış halidir.
  - Karşılaştırma kuralları: frekanslar aynı olmalı; iki işaret aynı fonksiyonla (ikisi de kosinüs ya da ikisi de sinüs) yazılmalı; genlikler pozitif olmalı (eksi işaret trigonometrik dönüşümle açıya alınır); fark $180^\circ$'den büyükse dönüşümle $0$-$180^\circ$ aralığına çekilmeli; faz farkı birincinin açısı eksi ikincinin açısıdır.
  - Kullanılan özdeşlikler: $\sin x = \cos(90^\circ - x) = \cos(x - 90^\circ)$, $\cos\alpha = -\cos(\alpha - 180^\circ)$, $\cos(180^\circ+\alpha) = \cos(180^\circ-\alpha) = -\cos\alpha$.
- Fazör gösterimi ve dönüşüm tablosu (ekrandan, 01:40:00 ve 01:45:00)
  - $v(t) = V_m\cos(\omega t + \phi)$ için fazör $\mathbf{V} = V_m\angle\phi = V_m e^{j\phi} = V_m[\cos\phi + j\sin\phi]$. Geri dönüş: $v(t) = \mathrm{Re}\{V_m e^{j\phi}e^{j\omega t}\} = V_m\cos(\omega t + \phi)$.
  - Tablo: $V_m\cos(\omega t+\phi) \to V_m\angle\phi$; $V_m\sin(\omega t+\phi) \to V_m\angle(\phi-90^\circ)$; akımlar için aynı. Varsayım: $V_m > 0$ ve $-180^\circ \le \phi \le 180^\circ$.
  - Açı $0^\circ$ ise pozitif reel, $180^\circ$ ise negatif reel, $90^\circ$ ise pozitif saf sanal ($jA$), $-90^\circ$ ise negatif saf sanal ($-jA$) sayıdır.
  - Fazörler büyük harfle (kitaplarda koyu harfle) yazılır.
- Özel (tekil) fonksiyonlar (ekrandan, 01:55:00)
  - Süreksiz ya da türevi süreksiz fonksiyonlardır (anahtarlama fonksiyonları): impuls, birim basamak, darbe, kare dalga, rampa (üçgen ve testere dişi). Birleşimleriyle karmaşık dalga biçimleri kurulur.
  - Birim basamak $u(t-t_0)$: $t<t_0$ için 0, $t>t_0$ için 1; anahtarın kapanmasına karşılık gelir. $1 - u(t-t_0)$ ters yönlü basamaktır. Basamağın türevi, $t_0$'da sonsuz büyük olan impuls fonksiyonudur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Fazör yaklaşımının asıl kazancı
  - Zaman boyutunda diferansiyel denklem çözmek yerine fazör uzayında doğrusal denklemler çözülür; zamandan fazöre ve fazörden zamana geçiş kolaydır.
- Kaynak frekansı bütün devreyi belirler
  - Uzun süre sinüzoidal kaynakla sürülen devrede bütün elemanlar kaynak frekansında salınır; $\omega$ fazör hesabında dışarıda tutulur ve dönüşte geri eklenir.
- RLC devrelerinde üç noktaya dikkat
  - Frekans değişince giriş-çıkış genlik oranı ve faz farkı değişir, salınım frekansı ise kaynakla aynı kalır.
- İşlem türüne göre gösterim seçimi
  - Çarpma ve bölme polar/üstel formda, toplama ve çıkarma kartezyen formda daha pratiktir.
- RLC formüllerini ezberlemek yerine kullanmayı anlamak
  - Seri ve paralel RLC'de $\alpha$, $\omega_0$ ve çözüm biçimleri verileceğinden ezber yerine nasıl kullanılacakları üzerine düşünmek daha anlamlıdır.
- Faz karşılaştırma kuralları ve sinüs-kosinüs dönüşümü
  - Faz karşılaştırmadan önce aynı frekans, aynı trigonometrik fonksiyon, pozitif genlik ve $0$-$180^\circ$ aralığı sağlanmalıdır. Sinüs, fazörde $-90^\circ$ eklenerek kosinüse çevrilir.

## Kısa Tekrar Notları

- Fazör analizi: geçici hal yok, yalnız sürekli sinüzoidal hal.
- $\omega = 2\pi f = 2\pi/T$; $f = 1/T$.
- $Z = \mathbf{V}/\mathbf{I}$; empedanslar direnç gibi seri/paralel birleştirilir, KCL/KVL/Ohm aynen geçerlidir.
- $V_m\cos(\omega t+\phi) \leftrightarrow V_m\angle\phi$; $V_m\sin(\omega t+\phi) \leftrightarrow V_m\angle(\phi - 90^\circ)$.
- $e^{j\theta} = \cos\theta + j\sin\theta$; $|z| = \sqrt{a^2+b^2}$, $\theta = \arctan(b/a)$ (çeyrek düzleme dikkat).
- Çarpma: genlikler çarpılır, açılar toplanır. Bölme: genlikler bölünür, açılar çıkarılır.
- Güç: $\mathbf{S} = \mathbf{V}\mathbf{I}^*$.
- Saf sinüsün ortalaması 0; DC ofset ortalamayı kaydırır; $V_{RMS} = 0.707V_p$.
- Faz farkı için: aynı frekans, aynı fonksiyon, pozitif genlik, fark $0$-$180^\circ$.
- Paralel LC çıkışlı RLC devresi bant geçiren süzgeç gibi davranır.

## Detaylı Açıklamalar

- **Neden fazör?** Zaman boyutunda RLC devresi ikinci dereceden diferansiyel denkleme götürür. Kaynak sinüzoidal ve devre uzun süre çalışıyorsa geçici etkiler sönmüştür; geriye yalnız kaynak frekansında salınan zorlanmış cevap kalır. Bu durumda her işaret yalnız iki sayıyla (genlik ve faz) tanımlanabilir, çünkü frekans bütün devrede ortaktır. Fazör, bu iki sayıyı tek bir karmaşık sayıda toplar. Kapasite ve endüktansın türev içeren bağıntıları fazör uzayında $\mathbf{V} = Z\mathbf{I}$ biçimini alır; böylece devre "karmaşık dirençlerden" oluşmuş gibi çözülür. Endüktans örneğinde $\mathbf{V}_L/\mathbf{I}_L = 3j\ \Omega$ bulunması, endüktansın empedansının saf sanal olduğunu gösterir.
- **Osiloskop örneğinin yorumu.** Seri $235\ \Omega$ ile paralel $4.7$ nF ∥ $1$ mH devresinde çıkış paralel LC üzerindedir. DC'de endüktans kısa devre olduğundan çıkış sıfırdır; çok yüksek frekansta kapasite kısa devre olduğundan yine sıfırdır. Arada bir frekansta çıkış girişe yaklaşır; bu bir bant geçiren davranıştır. Osiloskopta 5 kHz'te çıkışın çok küçük ve faz kaymalı, orta frekansta ise girişe yakın genlikte ve daha az faz kaymalı olduğu görüldü. Her iki durumda çıkış frekansı girişle aynıdır.
- **Zaman ↔ fazör dönüşümü.** Önce işaret kosinüs biçimine getirilir: $\sin(\omega t+\phi) = \cos(\omega t + \phi - 90^\circ)$. Genlik negatifse $-\cos\alpha = \cos(\alpha - 180^\circ)$ ile açıya aktarılır, açı $[-180^\circ, 180^\circ]$ aralığına çekilir. Sonra $\omega$ not edilir, fazör $V_m\angle\phi$ yazılır. Dönüşte $\mathrm{Re}\{\mathbf{V}e^{j\omega t}\}$ alınır. Örnekler (ekrandan, 01:50:00): $3\sin(100t+20^\circ) = 3\cos(100t-70^\circ) \to 3\angle{-70^\circ}$ V; $7\sin(350t-100^\circ) = 7\cos(350t-190^\circ) = -7\cos(350t-10^\circ) = 7\cos(350t+170^\circ) \to 7\angle170^\circ$ A.
- **Faz farkı örneği** (ekrandan, 01:35:00): $v_1 = 6\sin(20t+40^\circ) = 6\cos(20t-50^\circ)$, $v_2 = -4\cos(20t+20^\circ) = 4\cos(20t-160^\circ)$. Fark $-50^\circ - (-160^\circ) = 110^\circ$; pozitif olduğu için $v_1$, $v_2$'den $110^\circ$ öndedir. Sinüs formunda da $v_2 = 4\sin(20t-70^\circ)$ ve fark yine $40^\circ-(-70^\circ) = 110^\circ$ çıkar.
- **RMS'in anlamı.** Bir dirence uygulanan sinüzoidal gerilimin harcattığı ortalama gücü aynı dirençte harcatacak DC gerilim RMS değerdir. $v = A\sin\omega t$ için $\frac1T\int_0^T A^2\sin^2\omega t\,dt = A^2/2$, dolayısıyla $V_{RMS} = A/\sqrt2$. Ölçü aletleri sinüzoidal işaretin genliğini çoğunlukla RMS olarak gösterir.
- **Ders sonrası notlar**
  - Ortalama değer hesabında hoca $\int A\sin\omega t\,dt$ için katsayıyı "$A$ çarpı $\omega$" dedi; doğrusu $-\frac{A}{\omega}\cos\omega t$'dir. Sonuç (ortalama sıfır) değişmez.
  - Hoca fazör uzayında gücü önce $\mathbf{V}\mathbf{I}$ çarpımı ve açı $\phi+\theta$ diye anlattı, sonra slaytta akımın eşleniğiyle $\mathbf{S} = \mathbf{V}\mathbf{I}^*$ verdi. Karmaşık güçte açı $\phi - \theta$ olur.
  - Slayttaki $\mathbf{V}_o = 0.25e^{j40^\circ}$ V değeri, verilen eleman değerleriyle 10 kHz'te hesaplanınca $\approx 0.263\angle74.8^\circ$ V çıkıyor (python ile hesaplandı). Slayttaki sayılar büyük olasılıkla ölçümden ya da yuvarlanmış temsili değerlerdir; yöntem aynıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
