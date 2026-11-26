# Ders 9 Çalışma Özeti

## Genel Konular

- Paralel diyot ve DC kaynaklı kırpıcı (clipper) örneği
  - Devre: giriş $v_{in}$ (A ucu) seri bir dirençten çıkış düğümüne (B) gider. B ile alt hat (C) arasında, seri bağlı bir ideal diyot ve $+3$ V'luk bir DC kaynak vardır. Çıkış $V_{out} = V_{BC}$'dir. Giriş $v_{in} = 10\sin(2\pi f t)$ V, yani $+10$ V ile $-10$ V arasında salınan bir sinüstür (ekrandan, 00:10:00).
  - Birinci bağlantı: diyot, kaynağın artı ucundan B düğümüne doğru iletecek yöndedir. $v_{in} < 3$ V iken diyot iletimdedir, kısa devre gibi davranır ve çıkış $3$ V'ta sabit kalır. $v_{in} > 3$ V olunca diyot kesime gider, dirençten akım geçmez ve çıkış girişi izler. Sonuç: $v_{out} = \max(v_{in}, 3\ \text{V})$ (ekrandan, 00:30:00).
  - İkinci bağlantı: diyot ters çevrilir. $v_{in} < 3$ V iken diyot kesimdedir, çıkış girişi izler (sıfırda $0$ V'tan başlar). $v_{in} > 3$ V olunca diyot iletir ve çıkış $3$ V'ta tutulur. Sonuç: $v_{out} = \min(v_{in}, 3\ \text{V})$ (ekrandan, 00:30:00).
  - Yalnız diyotun yönü değiştirildiğinde çıkış dalga biçimi neredeyse tersine döner.
- Kırpıcı özet tablosu (slayt)
  - Slaytta seri ve paralel, pozitif ve negatif kırpıcıların devreleri ve çıkışları özetlenir. Paralel kırpıcıda DC kaynak $V$ ile çıkış ya $V$ seviyesinin üstünde ya da altında sınırlanır. İki diyot ve iki kaynak ($V_1$, $V_2$) içeren devrede çıkış $V_1$ ile $-V_2$ arasında sınırlanır (ekrandan, 00:05:00).
- Kenetleyiciler (clamper)
  - Kenetleyici, bir diyot ve bir kapasitörün birlikte kullanılmasıyla AC sinyali belli bir DC seviyesine "kenetleyen" devredir. Ad, nesneyi sabitleyen mengene/kıskaç (clamp) aletinden gelir.
  - Kırpıcılardan farkı devreye kapasitörün girmesidir. Kapasitör pil gibi yük biriktirir; dolu kapasitör ters yönde gerilim kaynağı gibi davranır.
  - Slayttaki örnek: seri $C$, paralel diyot ve $R$; giriş $+V$ ile $-V$ arasında kare dalga. Pozitif yarıda diyot iletir ve kapasitör dolar, çıkış $0$ V olur. Negatif yarıda diyot kesimdedir; dolu kapasitör girişe seri gerilim kaynağı gibi eklenir ve çıkış $-2V$ olur (ekrandan, 00:25:00).
  - Kitaptaki şekillerde kapasitör çok büyük kabul edilir; gerçekte kapasitör $R$ üzerinden boşalırken gerilimi zamanla azalır.
- Zener diyot
  - Normal diyot Si için yaklaşık $0{,}7$ V'ta iletir. Zener diyot ters kutuplamada, belirli bir zener geriliminde ($V_Z$; örneğin 6, 12, 18 V) kırılır ve üzerindeki gerilimi bu değerde tutar.
  - $V_i \ge V_Z$: zener "on" durumundadır, $V_Z$ değerinde sabit bir gerilim kaynağı gibi davranır. Zener akımı $I_Z = I_R - I_{RL}$, zener gücü $P_Z = V_Z I_Z$ (ekrandan, 00:35:00).
  - $V_i < V_Z$: zener "off" durumundadır, açık devre gibi davranır (ekrandan, 00:35:00).
  - Örnek: 6 V'luk zener ve 7 V'luk giriş varsa zener üzerinde 6 V, seri direnç üzerinde 1 V kalır.
  - Zener, giriş ne kadar büyük olursa olsun bağlı olduğu uçlarda en fazla $V_Z$ görülmesini sağlar. Bu yüzden aşırı gerilim koruması ve referans gerilimi üretiminde kullanılır.
- Diyotların diğer uygulamaları
  - Gerilim çoğaltıcılar: diyot, kapasitör ve transformatörle girişin tepe değeri $V_m$'i 2, 3, 4 katına çıkaran devreler (gerilim ikileyici, üçleyici, dörtleyici).
  - Özet: doğrultucular, koruma devreleri, polarite ters çevirme (reversal), zener ile aşırı gerilim koruması ve referans gerilimi.
- Transistör yapısı (BJT)
  - Transistör, üç katmanlı (p ve n tipi) ve üç bacaklı bir elemandır. İki tipi vardır: pnp (ortada n) ve npn (ortada p) (ekrandan, 00:40:00).
  - Bacaklar: emetör (E, yayıcı), baz (B, temel; ortadaki tek malzeme) ve kolektör (C, toplayıcı).
  - Katmanlar arasında tükenme (depletion) bölgeleri oluşur; dış gerilimlerle bu bölgeler daralıp genişler ve transistör iletime ya da kesime geçer.
  - Sembolde ok daima emetör bacağındadır ve n tipi malzemeyi gösterir: npn'de ok emetörden dışarı, pnp'de baza doğru içeri bakar.
  - Akım yönleri: npn'de akım kolektörden emetöre, pnp'de emetörden kolektöre akar.
  - Akım bağıntısı (iki tipte de): $I_E = I_C + I_B$. $I_B$ (µA mertebesi) $I_C$'ye (mA mertebesi) göre çok küçük olduğundan $I_C \approx I_E$ alınır.
  - $V_{BE} \approx 0{,}7$ V (Si), $0{,}3$ V (Ge).
- Bağlantı biçimleri ve çalışma bölgeleri
  - Ortak baz (common base), ortak emetör (common emitter), ortak kolektör (common collector): hangi bacağın ortak (toprağa yakın) olduğuna göre adlandırılır (ekrandan, 00:45:00).
  - Ortak baz giriş karakteristiği: $I_E$–$V_{BE}$ eğrileri $V_{CB} = 1, 10, 20$ V için verilir; akım yaklaşık $0{,}6$–$0{,}7$ V'tan sonra hızla artar (ekrandan, 00:50:00).
  - Üç çalışma bölgesi: aktif bölge, kesim bölgesi (akım yok), doyum bölgesi (akım çok, transistör üzerinde gerilim düşmez).
  - Anahtarlama modu: transistör 0 V ile 5 V arasında geçiş yapan anahtar gibi çalışır; mikroişlemci ve RAM gibi sayısal devrelerin temelidir.
- Transistörle yükseltme örneği (ortak baz, pnp)
  - $V_i = 200$ mV, giriş direnci $R_i = 20\ \Omega$, çıkış direnci $R_o = 100$ kΩ, yük $R = 5$ kΩ (ekrandan, 00:55:00).
  - $I_E = I_i = V_i / R_i = 200\ \text{mV} / 20\ \Omega = 10$ mA; $I_C \approx I_E$, $I_L \approx I_i = 10$ mA.
  - $V_L = I_L R = 10\ \text{mA} \cdot 5\ \text{k}\Omega = 50$ V; $A_v = V_L / V_i = 50\ \text{V} / 200\ \text{mV} = 250$.
- $\alpha$ ve $\beta$ katsayıları
  - $\alpha = I_C / I_E$ (1'e çok yakın), $\beta = I_C / I_B$ (akım kazancı). $I_C = \beta I_B$, $I_E = (\beta + 1) I_B$ (ekrandan, 01:00:00).
  - $\alpha = \dfrac{\beta}{\beta + 1}$, $\beta = \dfrac{\alpha}{1 - \alpha}$.
- Transistör testi ve görünüm
  - Ohmmetreyle npn transistörde baz-emetör ekleminin doğru yönde ölçümü düşük direnç (Low R), baz-kolektör ekleminin ters yönde ölçümü yüksek direnç (High R) gösterir. Her eklem bir diyot gibi düşünülür (ekrandan, 01:05:00).
  - Veri sayfasında (spec) bacak sırası, sıcaklık, güç ve karakteristikler bulunur. Kılıf tipleri: üç bacaklı, bir yüzü düz kılıf; yüzey montajlı (SMD); kalın kılıflı güç transistörleri.

## Hocanın Özellikle Vurguladığı Kısımlar

- Diyotun yönü çıkışı tamamen değiştirir
  - Aynı kırpıcıda yalnız diyot ters çevrildiğinde çıkış dalga biçiminin neredeyse tersine döndüğü iki çizimle gösterildi. Sınavda bir soru bu tür basit değişikliklerle farklılaştırılabilir.
- Gerilim farkı toprağa göre değerlerin farkıdır
  - Bir elemanın uçlarından biri $+3$ V, diğeri $-2$ V ise $V_{AB} = V_A - V_B = 3 - (-2) = 5$ V olur. Uçlardan birine daha düşük gerilim uygulamak aradaki farkı artırır, gerilimler birbirini götürmez.
- Akım yoksa direncin iki ucu aynı gerilimdedir
  - Diyot kesimdeyken dirençten akım geçmez; direncin iki ucu eşit gerilimde olur ve çıkış girişi aynen izler.
- Zener bir koruma elemanıdır
  - Giriş ne kadar büyürse büyüsün zener uçlarında en fazla $V_Z$ görülür; fazlası seri dirence düşer.
- $I_C \approx I_E$ yaklaşımı
  - $I_B$ çok küçük olduğundan hesaplarda kolektör ve emetör akımları eşit alınacaktır.

## Kısa Tekrar Notları

- Paralel kırpıcı ($+3$ V kaynak): diyot bir yönde ise $v_{out} = \max(v_{in}, 3)$, ters yönde ise $v_{out} = \min(v_{in}, 3)$.
- İdeal diyot: iletimde kısa devre, kesimde açık devre.
- Kenetleyici = diyot + kapasitör; sinyalin şekli korunur, DC seviyesi kayar. $\pm V$ kare dalga giriş için örnekte çıkış $0$ ile $-2V$ arasındadır.
- Zener: $V_i \ge V_Z$ ise $V_Z$'lik kaynak; $V_i < V_Z$ ise açık devre. $I_Z = I_R - I_{RL}$, $P_Z = V_Z I_Z$.
- Gerilim çoğaltıcılar: diyot + kapasitör ile $2V_m$, $3V_m$, $4V_m$.
- BJT: pnp / npn; E, B, C; ok emetörde ve n tarafını gösterir.
- $I_E = I_C + I_B$, $I_C \approx I_E$, $V_{BE} \approx 0{,}7$ V (Si).
- Bölgeler: aktif, kesim, doyum. Sayısal devrelerde anahtarlama modu.
- Ortak baz yükseltici örneği: $I_E = 10$ mA, $V_L = 50$ V, $A_v = 250$.
- $\alpha = I_C/I_E = \beta/(\beta+1)$, $\beta = I_C/I_B = \alpha/(1-\alpha)$.
- Ohmmetre testi: doğru yön düşük R, ters yön yüksek R.

## Detaylı Açıklamalar

- Kırpıcı örneğinin adım adım çözümü
  - Devrede giriş A noktasına uygulanır, A ile B arasında bir direnç vardır; çıkış B ile alt hat C arasından alınır. B ile C arasında ideal bir diyot ve $+3$ V'luk bir kaynak seri bağlıdır. Giriş $10\sin(2\pi f t)$ V'tur (ekrandan, 00:10:00).
  - Birinci bağlantıda diyot, 3 V'luk kaynaktan B'ye doğru iletecek yöndedir. $v_{in} = 0$ iken B'deki gerilim kaynaktan düşük olduğundan diyot iletimdedir; kısa devre gibi davranır ve çıkışta 3 V görünür. Giriş 1 V, 2 V olduğunda da durum değişmez; çıkış 3 V'ta kalır. Giriş 3 V'u aştığında diyot artık akım akıtmaz, açık devre olur. Dirençten akım geçmediği için direncin iki ucu eşit gerilimdedir; B, A'yı izler ve çıkış girişle aynı olur. Giriş tekrar 3 V'un altına inince diyot yeniden iletir ve çıkış 3 V'a sabitlenir. Negatif yarı periyot boyunca çıkış 3 V'ta kalır (ekrandan, 00:30:00).
  - İkinci bağlantıda diyot ters çevrilir. $v_{in} = 0$ iken diyotun artı ucuna daha yakın olan taraf 0 V olduğundan diyot iletmez; açık devredir ve çıkış girişi izler. Giriş 3 V'a ulaşınca diyot iletime geçer ve çıkış 3 V'ta tutulur. Giriş 3 V'un altına inince diyot yeniden açık devre olur ve çıkış girişi, $-10$ V'a kadar, aynen izler (ekrandan, 00:30:00).
- Bir öğrenci sorusu: gerilimler birbirini götürür mü?
  - Soru, 3 V'luk kaynak ile 3 V'un altındaki (negatif) giriş geriliminin birbirini azaltıp azaltmadığıydı. Cevap: bir elemanın uçları arasındaki gerilim, her ucun toprağa göre geriliminin farkıdır. Bir uç $+3$ V, diğeri $-2$ V ise fark $5$ V'tur; yani diğer uca daha düşük gerilim bağlamak potansiyel farkı artırır (ekrandan, 00:30:00).
- Bir öğrenci sorusu: $|V_1| > |V_2|$ koşulu
  - Slayttaki iki diyotlu ve iki kaynaklı kırpıcının çıkış grafiğinde yazan $|V_1| > |V_2|$ ifadesi bir zorunluluk değildir; grafikte $V_1$ seviyesinin daha yukarıda çizildiğini göstermek için yazılmıştır (ekrandan, 00:05:00).
- Kenetleyicinin çalışması
  - Pozitif yarı periyotta diyot iletir, kapasitör dolar ve çıkış sıfırda kalır. Negatif yarı periyotta diyot kesime girer; dolu kapasitör girişe seri bir gerilim kaynağı gibi eklenir ve çıkış, giriş genliğinin iki katı kadar negatife kayar. Böylece sinyal bir yönde "sıkıştırılmış" gibi olur. Kitap kapasitörü çok büyük kabul ettiği için çıkış düz çizilir; gerçekte boşalma sırasında gerilim zamanla azalır. Giriş olarak kare dalga kullanmak, pozitif ve negatif durumları ayrı ayrı görmeyi kolaylaştırır.
- Zener ile gerilim sınırlama
  - Zener diyotun karakteristiği ileri yönde normal diyot gibidir. Ters yönde belirli bir $V_Z$ değerine kadar akım akmaz; bu değerde kırılır ve gerilim daha fazla artmaz. Zener devreye ters bağlanır, yani katodu daha yüksek gerilime gelir; bu durumda $V_Z$'yi pozitif bir değer gibi düşünmek kolaylık sağlar. Girişe 6 V'luk zener ve seri direnç bağlanır, giriş 7 V yapılırsa zener üzerinde 6 V, direnç üzerinde 1 V kalır. Bu davranış zeneri aşırı gerilim koruması ve referans gerilimi kaynağı olarak kullanışlı yapar.
- BJT sembolü nasıl okunur
  - Sembolde çizgi (çubuk) tarafı bazdır. Ok emetör bacağındadır ve n tipi malzemeyi gösterir. Ok dışarı bakıyorsa emetör n tipidir, baz p tipidir: npn. Ok baza doğru bakıyorsa baz n tipidir: pnp.
- $\alpha$ ve $\beta$ bağıntısının türetilmesi
  - $I_E = I_C + I_B$ ifadesinde $I_B = I_C/\beta$ ve $I_E = I_C/\alpha$ yazılırsa $\dfrac{I_C}{\alpha} = I_C + \dfrac{I_C}{\beta}$ olur. Her iki taraf $I_C$'ye bölünürse $\dfrac{1}{\alpha} = \dfrac{\beta + 1}{\beta}$, yani $\alpha = \dfrac{\beta}{\beta + 1}$ ve $\beta = \dfrac{\alpha}{1 - \alpha}$ bulunur. Örneğin $\beta = 100$ için $\alpha \approx 0{,}990$'dır.
  - Ders sonrası not: Slaytta ve hocanın okumasında $\beta = \alpha/(\alpha - 1)$ yazıyor; bu ifade negatif sonuç verir. Doğrusu $\beta = \alpha/(1 - \alpha)$'dır.
- Ohmmetreyle transistör testi
  - npn transistörde baz p, emetör ve kolektör n tipidir; baz-emetör ve baz-kolektör eklemleri birer diyot gibidir. Ohmmetre baz-emetör eklemini doğru yönde kutuplayacak biçimde bağlanırsa düşük direnç okunur. Kolektör-baz eklemi ters yönde ölçülürse yüksek direnç okunur. Bu ölçümlerle transistörün sağlam olup olmadığı basitçe anlaşılabilir (ekrandan, 01:05:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
