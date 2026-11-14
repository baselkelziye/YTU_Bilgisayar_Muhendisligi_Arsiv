# Ders 8 Genişletilmiş Notu: Lab 3 (Thevenin-Norton), Vize Çözümleri, Kaynaksız RC/RL Devreleri, Zaman Sabiti, Tekillik Fonksiyonları ve Basamak Cevabı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Laboratuvar 3: Thevenin ve Norton Eşdeğerleri
- 2. Vize Sorularının Çözümleri
- 3. DC Kararlı Hal ve Bu Bölümün Amacı
- 4. Türevi Kendisine Benzeyen Fonksiyon: Üstel Çözüm Fikri
- 5. Kaynaksız RC Devresi
- 6. RC Devresinde Zaman Sabiti
- 7. Kaynaksız RL Devresi
- 8. Tekillik Fonksiyonları: Basamak, Dürtü ve Rampa
- 9. Basamak Cevabı: Akım Kaynaklı RC Devresi
- 10. Basamak Cevabı: Gerilim Kaynaklı RL Devresi
- 11. Example 01: İki Basamak Kaynaklı RC Devresi
- 12. Example 02: Kaynağı Çıkarılan RL Devresi
- 13. Example 03: Kaynağı Çıkarılan RC Devresi

## 1. Laboratuvar 3: Thevenin ve Norton Eşdeğerleri

Kaydın ilk bölümü laboratuvar oturumudur ve laboratuvar asistanı tarafından yürütülür. Soruyu Kübra Hoca hazırlamıştır. Konu, derste işlenmiş olan Thevenin ve Norton teoremleridir.

### 1.1 Teoremlerin Kısa Hatırlatması

Asistan, soru paylaşılana kadar slayttan kısa bir tekrar yaptı. Sol tarafta karmaşık görünen ama aslında basit bir devre vardır ve bu devrenin a-b uçları arasındaki davranışı bizi ilgilendirir. Thevenin eşdeğerinde bu devreyi bir gerilim kaynağı ile ona seri bir eşdeğer dirençle gösteririz. Norton eşdeğerinde ise gerilim kaynağının yerine bir akım kaynağı gelir ve direnç bu kaynağa paralel bağlanır. İki eşdeğerdeki direnç aynıdır, bu yüzden biri bulunduğunda dönüşümle diğerine geçilebilir.

### 1.2 Isınma Örneği

**Verilen:** 12 V'luk kaynak ve ona seri $3\,\Omega$. Ardından paralel kol olarak $6\,\Omega$ ve 1 A'lik akım kaynağı. Son olarak seri $8\,\Omega$ ve a-b uçları.

**$R_{TH}$:** Gerilim kaynağı kısa devre, akım kaynağı açık devre yapılır. a ucundan bakınca önce $8\,\Omega$ görülür, sonra yol ikiye ayrılır: $3\,\Omega$ ve $6\,\Omega$. Bu iki direncin diğer uçları b noktasındadır, yani birbirine paraleldirler:

$$R_{TH} = 8 + (3 \parallel 6) = 8 + 2 = 10\,\Omega$$

**$V_{TH}$:** a-b uçları açık olduğu için devre o tarafta kapalı değildir ve $8\,\Omega$ üzerinden akım geçmez. Geriye tek bilinmeyenli bir düğüm denklemi kalır:

$$\frac{V_{TH} - 12}{3} + \frac{V_{TH}}{6} - 1 = 0$$

Her terimi çözersek (ara adım eklendi) $\frac{V_{TH}}{2} = 5$ ve $V_{TH} = 10$ V bulunur.

**Norton:** İşlem aynıdır, yalnız sonuç dönüşümle paralel biçimde gösterilir: $I_N = V_{TH}/R_{TH} = 10/10 = 1$ A ve paralel $10\,\Omega$. Bu örneğin sonuçları python ile hesaplandı ve aynı çıktı.

### 1.3 Kara Kutu Görevi

Laboratuvar sorusunda Proteus'ta içi kapalı bir kutu (black box) verilir. Kutunun içinde iki direnç, iki kapasitör ve iki bobin (indüktör) vardır. Kutuya sağ tıklayıp "Goto Child Sheet" seçilince iç yapı görülebilir. Kutuyu oluşturan $R_1$, $R_2$ değerleri öğrenciden öğrenciye değişir.

<!-- BELİRSİZ: R1 ve R2'nin öğrenci numarasının son iki hanesine göre belirlendiği altyazıda net değil (00:25:20). Sorunun metni ve kutunun şeması altyazıda yok. -->

Kapasite ve endüktans laboratuvar sırasında henüz derste işlenmemişti. Bu yüzden asistan yalnızca elemanların nasıl ele alınacağını söyledi. Bobin, bir gerilim kaynağını sıfırlarken olduğu gibi kısa devre sayılır. Kapasitör ise bir akım kaynağını sıfırlarken olduğu gibi açık devre sayılır. Böylece hesapta C ve L ile bir işlem yapılmaz, yalnızca dirençlerle çalışılır. Bu davranışın gerekçesi aynı kaydın 3. bölümünde anlatılan DC kararlı haldir.

Görevin adımları şöyledir:

1. **a şıkkı:** Kısa, neredeyse tek kelimelik bir cevap. Asistana göre soru metninde ipucu da verilmiştir.
2. **b şıkkı:** Kutunun $V_{TH}$ ve $R_{TH}$ değerleri Proteus'ta bulunur. Biri çıkış uçları (OUT1, OUT2) arasındaki gerilim ölçümü, diğeri ohmmetreyle çıkış direnci ölçümüdür. $R_{TH}$ bulunurken gerilim kaynağı kısa devre yapılır. Her ölçüm için ayrı bir şekil ve ekran görüntüsü alınır, altına açıklama yazılır.
3. **c şıkkı:** b şıkkındaki değerlerden dönüşümle Norton eşdeğeri bulunur ve çizilir. Simülasyon gerekmez.
4. **d şıkkı:** Tasarım kısmıdır. b şıkkındaki $V_{TH}$ ve $R_{TH}$ değerlerini verecek bir iç devre elle tasarlanır. Bobinler kısa devre, kapasitörler açık devre alınır ve $R_3$, $R_4$ değerleri (örnekteki 10, 10 yerine) sonuç aynı çıkacak biçimde seçilir. Bu tasarım Proteus'ta değil kağıt üzerinde çizilerek yapılır.
5. **e şıkkı:** Deneyle ilgili kısa bir yorum.

<!-- BELİRSİZ: Kaynak değeri olarak söylenen 1 V'un (00:31:37, 00:53:58) kutuyu besleyen kaynak mı yoksa test kaynağı mı olduğu altyazıdan anlaşılmıyor. "Ohmmetre" kelimesi altyazıda "on metre / 10 metre" diye geçiyor, "OUT1, OUT2" ise "avut 1, avut 2" diye geçiyor; ikisi de bağlamdan okundu. -->

### 1.4 Laboratuvarda Sorulan Sorular

**Soru:** İçeriyi tasarlamakla ne kastediliyor? **Cevap:** Önce numaraya göre devre düzenlenip $V_{TH}$ ve $R_{TH}$ bulunur. Sonra iki direnç, iki kapasitör ve iki bobin kullanılarak aynı sonucu veren iç yapı çizilir.

**Soru:** $R_3$ ve $R_4$ değiştirilecek mi? **Cevap:** Evet. Oradaki değerler 10'dur, kendi tasarımınıza göre farklı değerler verirsiniz.

**Soru:** Devrenin şekli de değişmeli mi, yoksa yalnız direnç değerlerini değiştirmek yeter mi? **Cevap:** Yalnız direnç değerlerini değiştirmek yeterlidir. Şekil aynı kalabilir, farklı da çizilebilir, çünkü bobinler zaten kısa devre olacaktır. Önemli olan sonucun daha önce bulunan $V_{TH}$ ve $R_{TH}$ ile aynı çıkmasıdır.

**Soru:** Kondansatör ve bobin ideal olmadığından kutunun içine girip dirençlere göre düşününce ölçülen eşdeğer direnç biraz farklı çıkıyor. Sorun olur mu? **Cevap:** Asistana göre kutudaki elemanlar iç dirençleri olmadan tanımlanmıştır, sonuç çok değişmez ve doğru yapıldıysa sorun olmaz.

**Soru:** Kutudaki değerler deneme yanılmayla mı, formülle mi bulunacak? **Cevap:** İkisi de olabilir. Örneğin bilinmeyenlere $x$ değerleri verip eşitlikten çözebilirsiniz. Asistan formülle çözmeyi tercih ettiğini söyledi. Önemli olan yapılanı açıklamaktır.

## 2. Vize Sorularının Çözümleri

Dr. Erkan Uslu'nun dersi burada başlar. Hoca, 10 çoktan seçmeli sorudan oluşan vizenin çözümlerini geçti. Soruların şekilleri slayttadır. Aşağıdaki devre değerleri kısa nottan alınmıştır, altyazıda yalnızca hocanın sözlü anlatımı vardır.

### 2.1 Soru 1: Çevre Analizi

**Verilen:** 50 V kaynak, $10\,\Omega$ ($i_x$), paralel bağlı 3 A ve $v_x/4$ akım kaynakları, $2\,\Omega$ ($v_x$), $5\,\Omega$ ve $4i_x$ bağımlı gerilim kaynağı.

Hoca üç tür denkleme ihtiyaç olduğunu söyledi: birinci ve ikinci çevre denklemleri, $v_x$'i bağlayan denklem ve $i_x$'i bağlayan denklem. Bunlar yazılıp bir matematik aracında çözülebilir. Püf noktası, iki paralel akım kaynağını tek kaynakta birleştirmektir. Böylece iki çevre üzerinden işlem yapılır.

Kısa nottaki cevap $v_x = -4$ V, $i_x = 2.105$ A'dir (C şıkkı). Bu değerleri veren kuruluş şöyledir (ara adım eklendi). Birleşik kaynak $2\,\Omega$ ile seri kabul edilirse:

$$v_x = -2\left(3 + \frac{v_x}{4}\right) \;\Rightarrow\; \frac{3}{2}v_x = -6 \;\Rightarrow\; v_x = -4\text{ V}$$

Birleşik kaynağın akımı $3 + (-4)/4 = 2$ A olur. İkinci çevre akımı $i_x + 2$ ile yazılınca dış çevre denklemi şu hale gelir:

$$-50 + 10i_x + 5(i_x + 2) + 4i_x = 0 \;\Rightarrow\; 19i_x = 40 \;\Rightarrow\; i_x = 2.105\text{ A}$$

Bu çözüm python ile hesaplandı ve kısa nottaki cevapla aynı çıktı.

<!-- BELİRSİZ: Soru 1'in şekli altyazıda yok. Elemanların yerleşimi ve akım yönleri, cevabı veren kuruluştan çıkarıldı. -->

### 2.2 Soru 2: Düğüm Analizi ve Süper Düğüm

Süper düğüm mantığı kullanılabilir ama şart değildir. Süper düğüm kullanmadan da $V_1$, $V_2$, $V_3$, $V_4$ için denklem yazılabilir. O zaman iki bilinmeyen daha gerekir. Gerilim kaynaklarının üzerinden geçen akım çevredeki elemanlarca belirlendiği için bu akımların her birine bir yön verip bilinmeyen olarak denkleme katmak uygundur. Son olarak $v_x$ için, $V_1$ ile $V_4$ arasındaki farkı veren bir denklem yazılır. Sonuçta dört düğüm gerilimi, iki kaynak akımı ve $v_x$ için bir denklem sistemi oluşur ve matematik aracıyla çözülür.

Kısa nota göre 20 V'luk kaynak 1 ile 2, $3v_x$ kaynağı 3 ile 4 düğümleri arasındadır ve $v_x$, 1 ile 4 arasındaki $3\,\Omega$'un gerilimidir. Düğüm gerilimleri şunlardır: $V_1 = 26.67$, $V_2 = 6.67$, $V_3 = 173.33$, $V_4 = -46.67$ V. Bu değerler kısıt denklemlerini sağlar: $V_1 - V_2 = 20$ V, $v_x = V_1 - V_4 = 73.33$ V ve $V_3 - V_4 = 3v_x = 220$ V (python ile hesaplandı).

> **Ders sonrası not:** Soru metni $v_x$'i soruyor, kısa nottaki şıklar ise düğüm gerilimleridir. Yukarıda hesaplanan $v_x = 73.33$ V o şıklarda yoktur. Büyük olasılıkla her öğrenciye farklı bir düğüm sorulmuştur.

<!-- BELİRSİZ: Soru 2'deki diğer direnç değerleri altyazıda ve kısa notta yok. Tam devre yeniden çözülemedi, yalnız kısıtlar kontrol edildi. -->

### 2.3 Soru 3: Yalnız Bağımlı Kaynaklı Thevenin

İçeride bağımsız kaynak yoktur, bu yüzden doğrudan $V_{TH} = 0$ denebilir. $R_{TH}$ için bağımsız kaynaklar sıfırlanır (burada zaten yok) ve uçlara bir test kaynağı bağlanır. Kısa nota göre cevap $R_{TH} = 31.73\,\Omega$'dur (D şıkkı).

> **Hocanın vurgusu:** En sık yapılan hata, bağımlı kaynakları da sıfırlayarak $R_{TH}$ hesabına gitmektir. Bağımlı kaynakların sıfırlandığı durum yanlış çözüme götürür. Yalnızca bağımsız kaynaklar sıfırlanır, sonra test kaynağı bağlanır.

> **Ek bilgi (derste anlatılmadı):** Bu uyarının gerekçesi büyük olasılıkla şudur: Bağımlı kaynağın değeri devredeki başka bir akım ya da gerilime bağlıdır. Test kaynağı bağlandığında o değişken sıfırdan farklı olur ve bağımlı kaynak da değer alır. Onu baştan sıfırlamak, devrenin davranışını değiştirir.

<!-- BELİRSİZ: Soru 3'ün devre değerleri altyazıda ve kısa notta yok, 31.73 değeri bu notta yeniden hesaplanamadı. -->

### 2.4 Soru 4: Merdiven Devresi

**Verilen:** 28 V, seri $8\,\Omega$, paralel $12\,\Omega$ ($v_1$), seri $6\,\Omega$, paralel $15\,\Omega$, seri $4\,\Omega$, paralel $10\,\Omega$, son kolda seri $2\,\Omega$ ve $13\,\Omega$ ($v_2$).

Seri ve paralel dirençler merdiven biçimindedir. Sınavda tek bir gerilim yerine $v_1$ ve $v_2$ sorulmuştur. Hoca sadeleştirmeyi sağdan sola anlattı, sonra ana kol akımını bulup gerilim ve akım bölücülerle sağ uca gitti. Sadeleştirme adımları:

1. Son kol: $2 + 13 = 15\,\Omega$ (ara adım eklendi).
2. $15 \parallel 10 = 6\,\Omega$.
3. $6 + 4 = 10\,\Omega$.
4. $10 \parallel 15 = 6\,\Omega$.
5. $6 + 6 = 12\,\Omega$.
6. $12 \parallel 12 = 6\,\Omega$.
7. $6 + 8 = 14\,\Omega$, dolayısıyla ana kol akımı $I = 28/14 = 2$ A.

Geri dönerken (ara adım eklendi):

- $v_1 = 2 \cdot 6 = 12$ V.
- $6\,\Omega$'luk koldan $12/12 = 1$ A geçer. Bu direnç 6 V düşürür, $15\,\Omega$'un gerilimi 6 V kalır.
- $4\,\Omega$'luk koldan $6/10 = 0.6$ A geçer. Bu direnç 2.4 V düşürür, $10\,\Omega$'un gerilimi 3.6 V kalır.
- $v_2 = 3.6 \cdot \dfrac{13}{15} = 3.12$ V.

Sonuç $v_1 = 12$ V, $v_2 = 3.12$ V'tur (B şıkkı). Python ile hesaplandı.

### 2.5 Soru 5: Doğrusallık

İçerideki yapı pasif ve doğrusal olduğu için çıkış akımı kaynakların doğrusal birleşimi olarak yazılır:

$$i = a\,i_{s1} + b\,i_{s2}$$

Verilen iki durumdan iki denklem çıkar. $i_{s1} = i_{s2} = 5$ iken $i = 0$, $i_{s1} = 8$, $i_{s2} = 6$ iken $i = 4$ A'dir:

$$5a + 5b = 0, \qquad 8a + 6b = 4$$

Buradan $a = 2$, $b = -2$ bulunur. İstenen durumda $i_{s1} = 3$, $i_{s2} = 4$ A için $i = 2\cdot 3 - 2\cdot 4 = -2$ A olur (A şıkkı). Python ile hesaplandı.

### 2.6 Soru 6: Üç Uçlu Eleman

İçeride üç uçlu bir eleman vardır. Her uç çiftinden bakıldığında ölçülen direnç verilmiştir: $R_{AB} = 1.5$, $R_{BC} = 3$, $R_{AC} = 2.5\,\Omega$. İç yapının nasıl olması gerektiği sorulur. Hocaya göre E şıkkındaki yapıda dirençlerin her biri $1\,\Omega$'dur ve istenen değerleri verir, cevap E'dir.

Bu değerleri veren yapı şöyle bulunabilir (ara adım eklendi). Ortak bir düğüme bağlı üç kol düşünülürse $R_A + R_B = 1.5$, $R_B + R_C = 3$, $R_A + R_C = 2.5$ olur. Python ile hesaplandı: $R_A = 0.5$, $R_B = 1$, $R_C = 2\,\Omega$. Bu kollar beş adet $1\,\Omega$ ile kurulabilir: $1 \parallel 1$, tek $1\,\Omega$ ve $1 + 1$.

> **Ders sonrası not:** E şıkkının şekli altyazıda yok. Yukarıdaki yapı büyük olasılıkla o şekildir, çünkü kısa not beş direnç olduğunu söylüyor ve üç direnç değerini de sağlıyor.

### 2.7 Soru 7: Süperpozisyon

**Verilen:** $5\,\Omega$ ($v$), aşağı yönlü 3 A kaynak, $10\,\Omega$ ve 15 V kaynak. Hoca bu sorunun özellikle yönlere dikkat etmeyi ölçtüğünü söyledi.

- **Yalnız akım kaynağı:** Gerilim kaynağı kısa devre yapılır. $v = -3 \cdot (5 \parallel 10) = -3 \cdot \dfrac{10}{3} = -10$ V.
- **Yalnız gerilim kaynağı:** Akım kaynağı açık devre yapılır. $v = 15 \cdot \dfrac{5}{5 + 10} = 5$ V.
- **Toplam:** $v = -10 + 5 = -5$ V (D şıkkı). Python ile hesaplandı.

### 2.8 Soru 8: Eşdeğer Kapasite

Bu soruda yanlış cevaplar çoktu, doğru cevap 2 F'tır (D şıkkı). Seri kapasiteler, paralel dirençler gibi hesaplanır, paralel kapasiteler ise toplanır. Bir ucu boşta kalan 2 F'lık kapasite hesaba katılmaz.

- **Sol taraf:** $2 \parallel 1$ paralel kapasite olduğu için toplanır, 3 F. Bu 6 F ile seridir: $\dfrac{3 \cdot 6}{3 + 6} = 2$ F. a ucundaki 2 F ile paralel: $2 + 2 = 4$ F.
- **Sağ taraf:** 6 F ile 3 F seridir: 2 F. b ucundaki 2 F ile paralel: $2 + 2 = 4$ F.
- **a-b arası:** 4 F ile 4 F seridir: $C_{\text{eş}} = 2$ F. Python ile hesaplandı.

> **Ders sonrası not:** Hoca önce "2 ile 2 paralel, 1" dedi; doğrusu toplama yapılır ve sonuç 4 F'tır. Sohbetten gelen uyarıyla kendisi de düzeltti. Seri kapasite formülünü de "$1/R_{\text{eş}}$" diye okudu; doğrusu $\dfrac{1}{C_{\text{eş}}} = \dfrac{1}{C_1} + \dfrac{1}{C_2}$'dir.

### 2.9 Soru 9: Bobin Akımından Gerilimi Bulmak

Bir endüktansın akım grafiği verilmiş, uçlarındaki gerilim sorulmuştur. Akımın integraline benzeyen şıkkı ya da direnç davranışına benzeyen A şıkkını seçen hatalı cevaplar olmuş. Akım ile gerilim arasında türev ilişkisi vardır, yani grafiğin türevi alınır. Akımın sabit olduğu yerde türev sıfırdır, eğimin pozitif ve negatif olduğu yerlerde türev de sırasıyla pozitif ve negatiftir. Eğimler 1 büyüklüğündedir ve türevin değerleri 0, 1, 0, $-1$, 0 sırasıyla gelir. $L = 3$ H olduğu için $v = L\,di/dt$:

- $-1 < t < 0$ s: akım 0'dan 1 A'e çıkar, $v = +3$ V.
- $0 < t < 2$ s: akım sabit, $v = 0$.
- $2 < t < 3$ s: akım 0'a iner, $v = -3$ V.

Cevap C şıkkıdır. Aralıklar kısa nottan alınmıştır, hesap python ile yapıldı.

### 2.10 Soru 10: Kısa Devre ve Açık Uç

**Verilen:** 48 V kaynak ile $6\,\Omega$, $4\,\Omega$, $2\,\Omega$'lu dirençler. Hoca iki gözlem üzerinde durdu:

- Üstteki $6\,\Omega$'luk direnç kısa devre olduğu için devrede değildir, devre dışı bırakılır.
- Açık uca bağlı $4\,\Omega$'luk dirençten akım akmaz, o da çıkarılabilir.

Yaygın hata, bu $4\,\Omega$ üzerinden de akım akıyormuş gibi hesap yapmaktır. Geriye 48 V, $4\,\Omega$, $6\,\Omega$ ve $2\,\Omega$'luk değerler kalır ve devre temel teoremlerle çözülür. Kısa nota göre cevap $I = 6$ A, $V = 6$ V'tur (E şıkkı).

<!-- BELİRSİZ: Soru 10'un şekli altyazıda yok. Hocanın "şu 2 onluk dirençlerin konumu" dediği yer (03:07:55) okunamadı. Kalan dirençlerin bağlantısı bilinmediği için I = 6 A, V = 6 V bu notta yeniden hesaplanamadı. -->

## 3. DC Kararlı Hal ve Bu Bölümün Amacı

Bu haftanın konusu RL ve RC devreleri, bunların DC karakteristikleri ve geçici hal (transient) analizidir.

### 3.1 DC Koşulda Kapasite ve Endüktans

DC analiz, elemanın uzun süre boyunca DC koşullarda şartlandırıldığı durumda üzerindeki gerilim ve akımı belirlemektir. Burada akılda tutulacak iki kural vardır:

- **Kapasite** DC koşulda açık devre gibi davranır. Hoca bunu şematik gösterimle hatırlatıyor: sembol iki ayrı plakadır, yani açık devre gibidir. Üzerinden akım geçmez ama üzerinde gerilim düşümü vardır. Bu gerilim, uçlarına uygulanmış gerilime eşittir.
- **Endüktans** DC koşulda kısa devre gibi davranır. Üzerindeki gerilim düşümü sıfırdır ama üzerinden akım geçer. Bu akımı diğer elemanların koşullandırması belirler.

### 3.2 "Yeterince Uzun Süre" Ne Demektir?

"Yeterince uzun süre" teoride sonsuz süre demektir. Pratikte ise $5\tau$ süresi yeterli sayılır. Burada $\tau$ zaman sabitidir. RC devrelerinde $\tau = RC$, RL devrelerinde $\tau = L/R$'dir. Zaman sabitinin 5 katı kadar süre geçince devre pratikte geçici durumunu terk etmiş ve sürekli hale geçmiş kabul edilir.

> **Ders sonrası not:** Hoca burada (03:12) RL için zaman sabitini "R bölü L" dedi; doğrusu $\tau = L/R$'dir. Hoca 7.5'teki türetmede kendisi de doğrusunu verdi.

### 3.3 Yol Haritası

Bu kapsamda iki durumu inceleyeceğiz:

1. **Kaynaksız (source-free) RL ve RC devreleri:** Başlangıçta enerji depolamış bir kapasite ya da endüktans devreye bağlanır. Eleman bu enerjiyi nasıl harcar, bağlı olduğu elemanlarda nasıl akım ve gerilim oluşur?
2. **Kaynak bağlanan devreler:** Uzun süre kaynaksız kalmış, deşarj olmuş bir elemana belirli bir $t_0$ anında kaynak bağlanır. Elemandaki gerilim ya da akım nasıl değişir?

Yaklaşım şöyledir. $t = -\infty$ ile $t_0$ arasında kaynak bağlı değildir. $t_0$ anında kaynak bağlanır. $t \to \infty$ durumu ile $t \to -\infty$ durumu DC analizle bulunur. $t_0$ ile pratikte $t_0 + 5\tau$ arasındaki bölüm ise geçici hal analizidir.

Hoca önceki konuyu da hatırlattı. Kapasite ilk başta boşken kolay yük alır, yük biriktikçe ters yönde bozucu bir etki oluşur ve yük depolama kabiliyeti üstel olarak azalır. Endüktansta da akım değişimleri gerilim oluşturur ve manyetik alanda depolanan enerjiyi akım olarak tutma kabiliyeti azalır. Bu üstel davranış bizim için referans olacak. Enerji depolamış eleman RL ya da RC biçiminde bağlanınca değerler üstel olarak azalıp sıfıra düşer. Kaynak bağlanan elemanda ise sıfırdan başlayan değer üstel olarak, asimptotik biçimde belirli bir değere yakınsar.

> **Ders sonrası not:** Hoca "yük depolama kapasitesi azalıyor" dedi; $C$'nin değeri sabittir. Azalan, büyük olasılıkla kapasiteye yeni yük akıtma kolaylığıdır.

### 3.4 Doğal Cevap

Doğal cevap (natural response), sistemin dış bir kaynağa maruz kalmadığı durumda kendi iç yapısıyla nasıl davrandığıdır. Devredeki karşılığı şudur: kapasitede biriken yükle, endüktansta ise manyetik alanla depolanmış bir enerji vardır. İdeal durumda eleman devreden çıkarıldığında bu enerjinin azalmadığı varsayılır. Eleman sonra bir RL ya da RC devresine bağlanır ve akım ile gerilimin değişimi incelenir. Devrede zorlayıcı kaynak yoktur. Bu yüzden $t \to \infty$ iken kapasite geriliminin ve endüktans akımının asimptotik olarak sıfıra varmasını bekleriz.

### 3.5 Birinci ve İkinci Dereceden Devreler

Tek bir RL ya da RC devresi birinci dereceden devredir. RC devresinde kapasite gerilimi direnç gerilimine eşittir, yani denklemde gerilim olduğu gibi bulunur. Kapasitenin tanımından da onun türevi gelir. Bir değişkenin birinci türevi ve kendisi doğrusal olarak bağlıysa buna birinci dereceden sistem denir.

Önümüzdeki haftalarda görülecek RLC devrelerinde ise fonksiyonun ikinci türevi, birinci türevi ve kendisi doğrusal bir denklemde yer alır. Önerilen çözümler benzerdir ve yine üstel sonuç verir, fakat iki farklı üstel çözüm birlikte ortaya çıkar. İki üstelin toplamı, koşullara göre sinüzoidal ya da sönümlü sinüzoidal salınım veya üstel durumlar üretir. Bu konu daha sonra ayrıntılı işlenecek.

## 4. Türevi Kendisine Benzeyen Fonksiyon: Üstel Çözüm Fikri

Hoca, sohbetten gelen bir yorum üzerine diferansiyel denklemlerin çözümünde neyi aradığımızı anlattı. Elimizde $f$, $f'$ ve gerekirse $f''$'nin doğrusal olarak bağlandığı bir denklem vardır. Bu durumda soru şudur: türevi kendisiyle doğrusal olarak bağlı yazılabilen fonksiyon nedir? Önerdiğimiz bir fonksiyon denklemi sağlıyorsa çözümlerimizden biri olmuş olur.

Cevap üstel fonksiyondur. $f(x) = A e^{\alpha x}$ önerilirse:

$$f'(x) = A\alpha\,e^{\alpha x}, \qquad f''(x) = A\alpha^2 e^{\alpha x}$$

$e^{\alpha x}$ parantezine alındığında $A$, $A\alpha$, $A\alpha^2$ yalnızca sabit katsayılardır. Yani fonksiyon ve türevleri birbirine doğrusal bağımlı yazılabilir.

## 5. Kaynaksız RC Devresi

### 5.1 Senaryo

$t < t_0$ iken kapasitede enerji depolanmıştır. Bunu şöyle düşünebiliriz: başka bir devrede kapasitenin uçlarına bir gerilim uygulanır ve pratikte $5\tau$ kadar beklenir. Kapasitenin gerilimi kaynak değerine ulaşır. Sonra kapasite oradan sökülür ve $t = t_0$ anında bir direncin uçlarına paralel bağlanır. Aynı etki, kaynak uçları arasında bir anahtarlama yaparak da elde edilebilir.

Bağlantıdan sonra kapasitedeki yüklerin yavaş yavaş direnç üzerinden akmasını, kapasitenin deşarj olmasını bekleriz. Başta akıtılabilecek yük fazladır, yükler boşaldıkça bu miktar azalır. Bu da üstel bir davranışa işaret eder. $t \to \infty$ iken kapasite gerilimi sıfır olur. Başlangıç gerilimi yoksa zaten herhangi bir akım ya da gerilim değişimi olmaz.

### 5.2 Denklemin Kurulması

Çevre denklemi ve verilen yönlerle $-v_C + v_R = 0$ ve $i_C = -i_R$ yazılır. Elemanların tanımları şunlardır:

- Direnç için Ohm kanunu: $i_R = v_R/R$.
- Kapasite için $q_C(t) = C\,v_C(t)$. Her iki tarafın zamana göre türevi alınırsa, yükün türevi akım olduğu için $i_C = C\,\dfrac{dv_C}{dt}$ olur.

Bunlar yerine konunca birinci dereceden diferansiyel denklem elde edilir:

$$C\frac{dv_C}{dt} + \frac{v_C}{R} = 0 \quad\Rightarrow\quad \frac{dv_C}{dt} + \frac{1}{RC}v_C = 0$$

**Soru:** $\dfrac{dv_C}{dt} + \dfrac{v_C}{RC} = 0$ eşitliğine nasıl varıldı? **Cevap:** Her iki taraf $C$'ye bölündü, $C$ ikinci terimin paydasına geçti.

### 5.3 Birinci Çözüm Yolu: Üstel Öneri

$R$ ve $C$ sabit olduğu için fonksiyon ile türevi doğrusal bağımlıdır, dolayısıyla $v_C = A e^{\alpha t}$ önerilir. Yerine konursa:

$$A\left(\alpha + \frac{1}{RC}\right)e^{\alpha t} = 0$$

$A = 0$ durumu önemsiz (trivial) çözümdür ve aradığımız şey değildir. $e^{\alpha t}$ zaten sıfır olamaz. Geriye parantezin sıfır olması kalır: $\alpha = -\dfrac{1}{RC}$. Sabit $A$ ise başlangıç potansiyelidir ve hoca bunu $V_0$ ile gösterdi.

### 5.4 İkinci Çözüm Yolu: Logaritma

Hoca, $e$ üzerinin nereden geldiği daha net görülsün diye ikinci bir yol gösterdi. Denklem $v_C$'ye bölünür:

$$\frac{v_C'}{v_C} = -\frac{1}{RC}$$

Soru şudur: türevi $f'/f$ olan fonksiyon nedir? Cevap $\ln f$'tir, çünkü $\ln x$'in türevi $1/x$, $\ln f(x)$'in türevi $f'(x)/f(x)$'tir. Her iki tarafın $t$'ye göre integrali alınır. Sağ tarafta $t$ içeren bir terim olmadığı için integrali $t$ ile bir sabit verir:

$$\ln v_C = -\frac{t}{RC} + \text{sabit}$$

Her iki tarafın $e$ üzerisi alınırsa sabit bir çarpan olarak dışarı çıkar ve ilk yoldaki $A$ katsayısına karşılık gelir. Sonuç aynıdır.

### 5.5 Sonuç ve Grafik

Kapasite $t_0$ anında devreye girdiği için üstteki $t$ yerine $t - t_0$ yazmak daha doğrudur:

$$v_C(t) = V_0\,e^{-(t - t_0)/RC}, \qquad t \ge t_0$$

İki uç kontrol edilir. $t = t_0$'da üs sıfırdır, $e^0 = 1$ ve $v_C = V_0$. $t \to \infty$ iken $e^{-\infty} = 1/e^{\infty} \to 0$ ve $v_C \to 0$. Grafikte $t_0$ anına kadar $V_0$ sabit gelir, $t_0$'dan sonra üstel olarak azalır.

Üç bölge şöyledir:

- $t \ll t_0$: DC durum, $v_C = V_0$.
- $t_0$ ile $t_0 + 5\tau$ arası (pratikte): geçici hal, üstel denklem geçerlidir.
- $t \to \infty$: DC durum, $v_C = 0$.

### 5.6 Akım, Güç ve Enerji

$\tau = RC$ tanımıyla, $v_R = v_C$ olduğundan direnç akımı Ohm kanunundan bulunur, $i_C$ ise bunun eksilisidir:

$$i_R(t) = \frac{V_0}{R}e^{-t/\tau}, \qquad i_C = -i_R$$

Dirençte harcanan güç gerilim ile akımın çarpımıdır ve karesel terim çıkar:

$$p_R(t) = V_0 e^{-t/\tau}\cdot\frac{V_0}{R}e^{-t/\tau} = \frac{V_0^2}{R}e^{-2t/\tau}$$

0 ile $t$ arasındaki toplam enerji, kapasitenin devreye sağladığı enerjidir ve gücün integralidir (ara adımlar eklendi):

$$w_R(t) = \int_0^t \frac{V_0^2}{R}e^{-2s/\tau}\,ds = \frac{V_0^2}{R}\cdot\frac{\tau}{2}\left(1 - e^{-2t/\tau}\right) = \frac{1}{2}CV_0^2\left(1 - e^{-2t/\tau}\right)$$

Bu formül python ile sayısal integralle sınandı ve doğrulandı.

> **Ek bilgi (derste anlatılmadı):** $t \to \infty$ iken parantez 1'e gider ve $w_R \to \tfrac12 CV_0^2$ olur. Python ile yapılan sınama da bu sınırı verir. Bu ifade büyük olasılıkla kapasitede başlangıçta depolanan enerjinin tamamıdır. Yani başlangıç enerjisi sonunda bütünüyle dirençte harcanır.

## 6. RC Devresinde Zaman Sabiti

Zaman sabiti $\tau = RC$'dir. Ayrıca DC şartlarda kapasitenin açık devre gibi çalıştığını, pratikte $5\tau$'nun bu şartı sağladığını yeniden söyleyelim.

> **Hocanın vurgusu:** Zaman sabitindeki $R$, kapasitenin uçlarından bakıldığında görülen Thevenin eşdeğer direncidir. Bir devrede zaman sabiti isteniyorsa kapasite uçlarından bakılarak $R_{TH}$ bulunur ve $RC$ çarpımında o kullanılır.

Zaman sabitinin pratikteki anlamı $v_C$ formülünden okunur:

- $t = \tau$ anında çarpan $e^{-1} \approx 0.368$'dir. Gerilim başlangıç değerinin %36.8'ine düşer.
- $t = 5\tau$ anında çarpan $e^{-5} \approx 0.0067$'dir, yani başlangıcın yaklaşık %0.67'si kalır (sayılar python ile hesaplandı).

**Soru:** $5\tau$ diyoruz. $5\tau$'dan sonrası için hesap yapmamız gerekmiyor mu? **Cevap:** Teorik olarak sonsuz zaman geçmesi gerekir. Ama pratikte, örneğin breadboard üzerinde kurulmuş bir RC devresi $5\tau$ süresi boyunca sistemde kaldığında kapasite deşarj olmuş kabul edilebilir. Teorik olarak ise $t = -\infty$ ile $t = \infty$ arası zaten kapalı formda denklemle verilmiştir.

## 7. Kaynaksız RL Devresi

### 7.1 Başlangıç Koşulu

RC'de yapılan analizin benzeri RL için de yapılır. Fark şudur: kapasitede depolanan enerji bir başlangıç gerilimi olarak, endüktansta depolanan manyetik enerji ise bir başlangıç akımı olarak ortaya çıkar.

### 7.2 Denklemin Kurulması

Verilen yönlerle $v_L + v_R = 0$ ve $i_L = i_R$ yazılır. Endüktansın tanım bağıntısı manyetik akı üzerinden kurulur: $\phi(t) = L\,i_L(t)$. Akı aynı zamanda endüktans uçlarındaki gerilimin integralidir. Her iki tarafın türevi alınınca, akının türevi gerilim olduğu için:

$$v_L(t) = L\frac{di_L}{dt}$$

$v_R = i_R R = i_L R$ yerine konur ve taraflar $L$'ye bölünür:

$$\frac{di_L}{dt} + \frac{R}{L}i_L = 0$$

### 7.3 Çözüm

Yine türeviyle kendisi doğrusal bağımlı bir fonksiyon aranır, $i_L = A e^{\alpha t}$ önerilir. Yerine konup $A e^{\alpha t}$ parantezine alınınca $\alpha + R/L = 0$ çıkar:

$$\alpha = -\frac{R}{L}, \qquad i_L(t) = A e^{-Rt/L}$$

$t = 0$'da $e^0 = 1$ olduğundan $i_L(0) = I_0$ koşulu $A = I_0$ verir. Hoca önce başlangıç gerilimi demiş, hemen ardından $I_0$ diye düzeltmiştir, çünkü burada başlangıç değeri akımdır:

$$i_L(t) = I_0 e^{-Rt/L}, \qquad t \ge 0$$

$t = 0$'da $i_L = I_0$, $t \to \infty$ iken $e^{-\infty} \to 0$ ve $i_L \to 0$. Grafikte $t = 0$'a kadar $I_0$ gelir, sonra üstel olarak azalıp sıfıra asimptotik yaklaşır.

Üstelin nereden geldiği için RC'deki logaritma yolu burada da aynıdır. Denklem $i_L$'ye bölünür, $i_L'/i_L + R/L = 0$ olur, integral $\ln i_L = -\frac{R}{L}t + \text{sabit}$ verir. $e$ üzerisi alınınca $\text{sabit}$ bir çarpana dönüşür ve bu çarpan $I_0$'dır.

### 7.4 Gerilim, Güç ve Enerji

Direnç gerilimi akım ile direncin çarpımıdır. Güç, direnç gerilimi ile akımın çarpımıdır ve yine karesel formdadır. Gücün 0 ile $t$ arasındaki integrali tüketilen enerjiyi verir. Slayttaki formül altyazıda okunmuyor, RC ile aynı yoldan kurulursa (ara adımlar eklendi):

$$v_R = R I_0 e^{-t/\tau}, \qquad p_R = R I_0^2 e^{-2t/\tau}, \qquad w_R(t) = \frac{1}{2}L I_0^2\left(1 - e^{-2t/\tau}\right)$$

Bu enerji formülü python ile sayısal integralle sınandı ve doğrulandı.

### 7.5 RL Zaman Sabiti

RC'de $e^{-t/RC}$, RL'de $e^{-Rt/L}$ çıktı. İkisini yan yana getirmek için, RC'de $t$'nin altındaki terime $\tau$ dediğimize göre RL'de de $t$'nin altında kalan terime $\tau$ demeliyiz. Bu da şunu verir:

$$\tau_{RL} = \frac{L}{R}, \qquad \tau_{RC} = RC$$

> **Hocanın vurgusu:** RL devresinde de zaman sabitindeki $R$, endüktansın uçlarından bakıldığında görülen direnç devresinin $R_{TH}$ değeridir.

Endüktansta da $\tau$ kadar süre geçince akım başlangıç değerinin %36.8'ine, $5\tau$ geçince $e^{-5}$ katına düşer ve pratikte geçici hal bitmiş sayılır.

## 8. Tekillik Fonksiyonları: Basamak, Dürtü ve Rampa

Bir kaynağın $t_0$ anında devreye bağlanması ya da devreden çıkarılması fiziksel olarak bir anahtarla ifade edilir. Aynı şey matematiksel olarak da temsil edilebilir. Şimdiye kadar gördüğümüz çözümler, $t_0$'dan önce 0, sonra 1 değerini veren bir fonksiyona karşılık gelir. Bu fonksiyon birim basamak fonksiyonudur (unit step). Yani aslında birim basamak fonksiyonuna verilen cevabı çözmüş olduk.

Amaç şudur: karmaşık bir fonksiyonla karşılaşınca onu birim basamak fonksiyonları cinsinden yazmak, her biri için çözümü bulmak ve bunları toplayarak net cevabı elde etmek.

Normalde sürekli ve sonsuz kez türevlenebilir fonksiyonlarla çalışmayı bekleriz. Tekillik fonksiyonları (singularity functions) ise kendisi ya da türevleri süreksizlik barındıran fonksiyonlardır.

### 8.1 Birim Basamak Fonksiyonu

$$u(t) = \begin{cases} 0, & t < 0 \\ 1, & t \ge 0 \end{cases}$$

Fonksiyon, içindeki parametre sıfır olduğunda değer değiştirir. Bu yüzden:

- Basamağı pozitif yönde $t_0$ kadar taşımak için $u(t - t_0)$ yazılır. Geçiş $t = t_0$'dadır.
- Negatif yönde taşımak için ($t_0 > 0$ iken) $u(t + t_0)$ yazılır. Fonksiyon $t > -t_0$ için 1 olur.

Fonksiyonun genliği 1'dir. $t = t_0$ anında $V_0$ gerilimi bağlamak istiyorsak $u$'yu bu sabitle çarparız: $V_0\,u(t - t_0)$. Hoca, slaytta $V$ ile $u$'nun karıştırılmamasını özellikle söyledi.

### 8.2 Anahtarın Yerine Basamak Kaynak

a-b uçlarına bağlı bir gerilim kaynağı ve $t = 0$'da onu devreye bağlayan bir anahtar düşünelim. Anahtarı kaldırıp yerine doğrudan $V_0\,u(t)$ değerli bir gerilim kaynağı yazmak aynı anlama gelir. Akım kaynağı için de benzerdir. $t = 0$'dan önce devreye akım vermeyen, $t = 0$'da anahtar konum değiştirince vermeye başlayan kaynak, a-b uçlarına bağlı $I_0\,u(t)$ değerli akım kaynağıyla gösterilir.

> **Ders sonrası not:** Hoca burada (04:12:38) "$I_0 u(t)$ değerli gerilim kaynağı" dedi; doğrusu akım kaynağıdır.

### 8.3 Birim Dürtü Fonksiyonu

$u(t)$'nin türevine bakalım. $t \in (-\infty, 0^-)$ için de $t \in (0^+, \infty)$ için de fonksiyon sabittir, türev sıfırdır. $t = 0$ anında ise anlık bir geçiş vardır ve türev teorik olarak sonsuz genliğe sahiptir. Sonuçta $t = 0$'da sonsuz değerli, altındaki alan 1 olan bir fonksiyon elde edilir. Buna birim dürtü (unit impulse) ya da Dirac delta fonksiyonu denir:

$$\delta(t) = \frac{du(t)}{dt}, \qquad \int_{-\infty}^{\infty}\delta(t)\,dt = 1$$

Hoca bunun iki temel özelliğin en önemlileri olduğunu belirtti. Pratikteki kullanımına örnek olarak bir sinc fonksiyonunun genişliği çok daraltıldığında analog işaretin örneklenmesinde kullanılabilecek bir yapı elde edildiğini söyledi.

<!-- BELİRSİZ: Altyazıda "sink fonksiyonu" geçiyor (04:14:35), "sinc" olarak okundu. -->

Grafikte verilen bir dürtü toplamı örneği:

$$x(t) = 5\,\delta(t + 2) + 10\,\delta(t) - 4\,\delta(t - 3)$$

Dürtünün yanındaki genlik, altında kalan alanı anlatır. $t = -2$'de genliği 5 olan dürtü $5\delta(t + 2)$ ile yazılır. $t = 0$'da genliği 10 olan dürtü vardır. $t = 3$'teki dürtü ters yönlü olduğu için $-4\delta(t - 3)$ yazılır.

### 8.4 Eleme Özelliği

Dürtü bir başka fonksiyonla çarpım halinde integrale girdiğinde, $a < t_0 < b$ ise:

$$\int_a^b f(t)\,\delta(t - t_0)\,dt = f(t_0)$$

Bu, $f$ fonksiyonunun $t_0$ anındaki değerini elde etmektir ve örneklemeye karşılık gelir. Analog işaretlerin örneklenmesinde kullanılan yaklaşım budur.

### 8.5 Birim Rampa Fonksiyonu

Birim rampanın özelliği eğiminin 1 olmasıdır. Tanım olarak birim basamağın 0 ile $t$ arasındaki integralidir:

$$r(t) = \int_0^t u(s)\,ds = t\,u(t) = \begin{cases} 0, & t < 0 \\ t, & t \ge 0 \end{cases}$$

Burada $u(t)$, fonksiyonun yalnız $t > 0$ için anlamlı olmasını; $t$ çarpanı ise eğimin 1 olmasını sağlar. Kırılma noktası, içteki parametrenin sıfır olduğu yerdir. Pozitif yönde taşımak için $r(t - t_0)$, eksi yönde taşımak için $r(t + t_0)$ yazılır. İkincisinde kırılma $t = -t_0$'dadır.

### 8.6 Üç Fonksiyon Arasındaki İlişki

Türev yönünde ve integral yönünde şu zincir vardır:

$$\frac{dr(t)}{dt} = u(t), \qquad \frac{du(t)}{dt} = \delta(t)$$

Ters yönde, dürtünün integrali basamağı, basamağın integrali rampayı verir.

## 9. Basamak Cevabı: Akım Kaynaklı RC Devresi

Şimdiye kadar devrede kaynak yokken doğal cevabı inceledik. Şimdi zorlayıcı bir kaynak olduğunda geçici halin nasıl değiştiğine bakacağız. RC için doğal çözüm üstel olarak azalan bir fonksiyondu. Bu çözümün yanında bir kaynak bağlanınca bu kaynak zorlayıcı kaynak adını alır. Geçici hal, kapasitede depolanan enerjiyle ilgilidir. Geçici hal bittikten sonra (pratikte $5\tau$) sistem artık yalnızca zorlayıcı DC kaynağa göre çalışır.

### 9.1 Devre ve Üç Bölge

Devre: $I_1 u(t - t_0)$ akım kaynağı, ona paralel $R$ ve $C$. Kaynağın akımı $t_0$'a kadar sıfırdır, $t_0$'dan itibaren $I_1$ olur. Yani kaynak $t_0$'da devreye bağlanmış gibi davranır. Üç bölge vardır: $(-\infty, t_0^-)$, geçici hal bölgesi $(t_0^+, \infty)$ ve $t \to \infty$.

**$t \ll t_0$ için DC analiz:** Akım kaynağı sıfır olduğu için açık devre çizilir, kapasite de DC şartta açık devredir. Sadece direnç kalır ve akım sıfırdır. Kapasitede başta bir yük olsa bile uzun süre geçtiği için $v_C = 0$'dır.

**$t \gg t_0$ için DC analiz:** Kaynak $I_1$ değerindedir, kapasite açık devredir. Akımın tamamı direnç üzerinden akar: $v_R = I_1 R$. Kollar paralel olduğu için:

$$v_C(t \to \infty) = I_1 R$$

> **Ders sonrası not:** Hoca bu kısımda (04:23:15) "gerilim kaynağım $I_1$" dedi; doğrusu akım kaynağıdır.

Bu iki uç ve üstel davranış bilgisiyle grafik çizilir: $t_0$'a kadar sıfır gelir, sonra $I_1 R$ değerine asimptotik olarak yaklaşır. Yani üstel olarak artan bir fonksiyon bekliyoruz.

**Soru:** $t_0$'dan öncesi bir daha anlatılabilir mi? **Cevap:** $t_0^-$'a kadar olan aralıkta $I_1 u(t - t_0)$ sıfırdır, yani devrede kaynak yoktur. Çok uzun süre kaynak olmadığı için $t \to -\infty$ civarında kapasitede yük olsa dahi bu süre boyunca boşalır ve $v_C = 0$ olur. Eşdeğer devre, açık devre kaynak, direnç ve açık devre kapasitedir.

**Soru:** Akımın sıfır olmasının nedeni $u$ fonksiyonu mu? **Cevap:** Evet. Kaynak birim basamak fonksiyonuyla kısıtlanmış olduğu için $t_0$'a kadar sıfırdır, sonra $I_1$'e çıkar.

### 9.2 Geçici Hal Denklemi

Teorik olarak $t_0^+$ ile sonsuz arası (sonsuza varmadan) geçici hal analizidir, pratikte $t_0^+$ ile $5\tau$ arası. $t \ge t_0$ için kaynak devrededir. Düğüm denklemi ve eleman bağıntıları şunlardır:

- Düğüm: $I_1 = i_R + i_C$.
- Ohm: $v_R = i_R R$.
- Kapasite: $q_C = C v_C$, türevi $i_C = C\,dv_C/dt$.
- Paralellik: $v_C = v_R$.

Yerine konunca:

$$C\frac{dv_C}{dt} + \frac{v_C}{R} = I_1 \quad\Rightarrow\quad \frac{dv_C}{dt} + \frac{v_C}{RC} = \frac{I_1}{C}$$

> **Ders sonrası not:** Hoca çözüme başlarken sağ tarafı (04:35:43) "$I_1$" diye yazdı, sonra (04:38:07) "$I_1/C$" olduğunu fark edip düzeltti. Doğrusu $I_1/C$'dir.

### 9.3 İki Parçalı Çözüm

Denklem $f' + a f = b$ biçimine indirgenir. Çözüm iki başlık altında incelenir:

1. **Doğal çözüm:** Kaynak sıfırlanır, $f' + a f = 0$ çözülür. Buradan $f_1$ gelir.
2. **Zorlanmış çözüm:** Kaynak hangi formdaysa o formda bir çözüm önerilir, yani kaynak taklit edilir. Buradan $f_2$ gelir.

Net cevap $f = f_1 + f_2$'dir.

Zorlanmış çözüm önerileri şöyledir:

- Kaynak sabitse sabit önerilir (aşağıda gösteriliyor).
- Kaynak sinüzoidalse $A\cos(\omega t + \phi)$ önerilir. $\omega$ kaynağın açısal frekansıdır. $A$ ve $\phi$ iki bilinmeyen, yani iki serbestliktir.
- Kaynak $t^2$ ise $at^2 + bt + c$ önerilir.

Sabit kaynak için sabitin yeterli olduğunu görmek için hoca $f_2 = at + b$ önerdi. $f_2' = a$ olur ve denkleme konunca $f' + Af = B$ için:

$$a + A(at + b) = B$$

Sağ tarafta $t$'li terim olmadığı için $a = 0$ çıkar. Yani önerinin sabit içermesi yeterlidir ve çözüm $b = B/A$ olur.

Toplam çözümdeki $R I_1$ terimi kaynak yüzünden önerilen çözümden, $e$ üzerili terim ise homojen çözümden gelir.

### 9.4 Çözümün Adımları

Önce kaynak $t = 0$'da bağlanmış gibi yazalım.

1. **Doğal çözüm:** $\dfrac{dv_C}{dt} + \dfrac{v_C}{RC} = 0$ denklemi $v_{C1} = A e^{-t/RC}$ verir.
2. **Zorlanmış çözüm:** Kaynak sabit olduğu için $v_{C2} = a$ önerilir. Türevi sıfırdır: $\dfrac{a}{RC} = \dfrac{I_1}{C}$. $C$'ler sadeleşir ve $a = I_1 R$ olur. $t \to \infty$ iken üstel terim sıfıra gittiği için $v_C \to I_1 R$ koşulu da böylece sağlanır, $A$ burada katkı yapmaz.
3. **Toplam:** $v_C(t) = A e^{-t/RC} + I_1 R$.
4. **Başlangıç koşulu:** $t = 0$'da $v_C = 0$ olmalıdır. Üstel terim 1 olur: $A + I_1 R = 0$, yani $A = -I_1 R$.
5. **Sonuç:** $v_C(t) = I_1 R\left(1 - e^{-t/RC}\right)$.

Kaynak $t_0$'da bağlanıyorsa $t$ yerine $t - t_0$ yazılır:

$$v_C(t) = I_1 R\left(1 - e^{-(t - t_0)/RC}\right), \qquad t > t_0$$

Kontrol: $t = t_0$'da $1 - 1 = 0$. $t \to \infty$ iken $1 - 0 = 1$ ve $v_C = I_1 R$. DC analizle bulunan iki değer de sağlanır. Bu çözümün diferansiyel denklemi sağladığı python ile sayısal olarak sınandı.

**Soru:** Bu kadar ayrıntılı çözecek miyiz? **Cevap:** Hayır, bu kadar ayrıntılı çözmeyeceğiz.

> **Hocanın vurgusu:** Zorlayıcı kaynak varsa çıkışın sıfırdan başlayıp asimptotik olarak $I_1 R$'ye yaklaştığını bilmek yeterlidir. Yani $t = t_0$'da sıfır, $t = \infty$'da $R I_1$ verecek biçimde formülü yazabilmek bu aşama için yeterlidir.

## 10. Basamak Cevabı: Gerilim Kaynaklı RL Devresi

Aynı analiz, $V_1 u(t - t_0)$ gerilim kaynağı ile seri $R$ ve $L$ için de yapılır. Üç durum vardır: $(-\infty, t_0^-)$ DC şartlanması, $(t_0^+, \infty)$ geçici hal ve $t \to \infty$ DC durumu.

**DC analizler:** $t < t_0$ için kaynak sıfır olduğundan akım akmaz, $i_L = 0$. $t \to \infty$ için kaynak devrededir, endüktans kısa devre tel gibi davranır ve $i_L = V_1/R$ olur. Aradaki bölümde akım üstel olarak bu değere asimptotik yaklaşır.

**Geçici hal denklemi:** $t_0^+$'dan sonra $u(t - t_0) = 1$ olduğundan kaynak $V_1$ değerindedir. Çevre denklemi:

$$-V_1 + v_R + v_L = 0$$

$v_R = i_R R = i_L R$ ve akının türevinden $v_L = L\,di_L/dt$ yerine konur:

$$\frac{di_L}{dt} + \frac{R}{L}i_L = \frac{V_1}{L}$$

**Çözüm adımları:**

1. **Zorlanmış çözüm:** Sabit kaynak için $i_{L2} = a$ önerilir. Türevi sıfır, $a\dfrac{R}{L} = \dfrac{V_1}{L}$, yani $a = V_1/R$.
2. **Doğal çözüm:** $i_{L1} = A e^{\alpha t}$ önerilir. Yerine konup parantez alınınca $\alpha + R/L = 0$, yani $\alpha = -R/L$.
3. **Toplam:** $i_L(t) = A e^{-Rt/L} + \dfrac{V_1}{R}$.
4. **Başlangıç koşulu:** $i_L(0) = 0$ olduğundan $A + V_1/R = 0$, $A = -V_1/R$.
5. **Sonuç:** Parantez alınır, kaynak $t_0$'da bağlanıyorsa $t$ yerine $t - t_0$ yazılır:

$$i_L(t) = \frac{V_1}{R}\left(1 - e^{-R(t - t_0)/L}\right), \qquad t > t_0$$

Kontrol: $t = t_0$'da $-V_1/R + V_1/R = 0$, sıfırdan başlar. $t \to \infty$ iken $V_1/R$ kalır. Çözüm python ile sayısal olarak sınandı.

> **Hocanın vurgusu:** Bu kadar karmaşık çözüm yapmayacağız. Zorlanmış DC kaynak bulunan bir devrede endüktans akımının bu formülle verildiğini bilmek yeterlidir. Nasıl çıktığını da söylemiş olduk.

> **Ek bilgi (derste anlatılmadı):** Kısa notun tekrar kısmındaki tek formül bu iki sonucu ve kaynaksız durumları özetler: $x(t) = x(\infty) + [x(t_0) - x(\infty)]\,e^{-(t - t_0)/\tau}$. Burada $x$, kapasite gerilimi ya da endüktans akımıdır. $x(t_0) = 0$ alınırsa basamak cevapları, $x(\infty) = 0$ alınırsa doğal cevaplar elde edilir. Hocanın 05:21'de özet diye gösterdiği slayt büyük olasılıkla bu bağıntıları içerir.

## 11. Example 01: İki Basamak Kaynaklı RC Devresi

Son aranın ardından hoca, karma durumları örneklerle çözmeye geçti. Önce hatırlatma yaptı: zorlayıcı kaynak varsa denklem doğal çözüm ile zorlanmış çözümün toplamına ayrılır. Zorlanmış çözümde öneri, kaynağın en genel biçimidir. Örneğin kaynak sinüs ise $A\cos(\omega t + \phi)$, iki serbestlikle yazılır. Birden fazla kaynak varsa daha önce gördüğümüz teoremler kullanılır.

**Devre:** Paralel bağlı $I_1 u(t - t_1)$ (yukarı yönlü), $I_2[1 - u(t - t_2)]$ (aşağı yönlü), $R$ ve $C$. $t_1 < t_2$ varsayılır. Kapasitede başlangıç enerjisi yoktur.

Sol kaynak $t_1$ anında akım vermeye başlar. Ortadaki kaynak ise $t_2$ anında akım vermeyi keser.

### 11.1 Kaynakları Çizmek

Kaynakların akımına $i_A$ ve $i_B$ diyelim.

- $i_A(t) = I_1 u(t - t_1)$: $t_1$'e kadar sıfır, sonra $I_1$.
- $u(t - t_2)$: $t_2$'ye kadar 0, sonra 1. Dolayısıyla $1 - u(t - t_2)$: $t_2$'ye kadar 1, sonra 0.
- Yön ters olduğu için $i_B(t) = -I_2[1 - u(t - t_2)]$: $t_2$'ye kadar $-I_2$, sonra 0.

> **Hocanın vurgusu:** $1 - u(t - t_0)$ fonksiyonunun ne olduğunu fark etmek önemlidir. Bir kaynağın $t_0$ anında devreden çıkmasını modeller.

Bu grafiklerden çözüm aralıkları çıkar:

- $t \in (-\infty, t_1^-)$: yalnız $i_B$ devrede.
- $t \in (t_1^+, t_2^-)$: hem $i_A$ hem $i_B$ devrede.
- $t \in (t_2^+, \infty)$: yalnız $i_A$ devrede.
- $t = -\infty$ ve $t = \infty$: gerçek DC durumlar.

### 11.2 Süperpozisyon

> **Hocanın vurgusu:** Birden fazla kaynakta süperpozisyondan faydalanırız. Her seferinde bir kaynak devredeyken çözüm yapılır, sonuçlar yönlü olarak toplanır.

Akım kaynağını sıfırlamak, yerine açık devre koymak demektir.

**Yalnız $I_1$ devredeyken:** Başlangıç koşulu olmayan, zorlayıcı kaynakla sürülen RC devresidir. Çözüm $t_1$ kadar ötelenmiş basamak cevabıdır. Hoca, zaman ötelemesine dikkat edilmesinin önemli olduğunu söyledi:

$$v_C^{(1)}(t) = \begin{cases} 0, & t < t_1 \\ R I_1\left(1 - e^{-(t - t_1)/RC}\right), & t > t_1 \end{cases}$$

**Yalnız $I_2$ devredeyken:** $t_2$'ye kadar kaynak $-\infty$'dan beri devrededir, yani DC koşul vardır. Kapasite açık devredir, akımın tamamı direnç üzerinden ters yönde akar ve $v_C = -R I_2$ olur. $t_2$ anında kaynak çıkar. Geriye başlangıç koşulu $-R I_2$ olan kaynaksız RC devresi kalır:

$$v_C^{(2)}(t) = \begin{cases} -R I_2, & t < t_2 \\ -R I_2\,e^{-(t - t_2)/RC}, & t > t_2 \end{cases}$$

> **Ders sonrası not:** Hoca bu örnekte birkaç kez "eksi R bölü $I_2$" dedi; doğrusu çarpımdır: $-R I_2$. Ayrıca $t \to -\infty$ için "$I_2 R$'lik gerilim bekliyoruz" dedi; akım ters yönde olduğu için doğrusu $-R I_2$'dir. "$R_1$ çarpı $I_1$" dediği yerde de direnç tektir, doğrusu $R I_1$'dir.

### 11.3 Üç Aralıkta Toplam

$$v_C(t) = \begin{cases} -R I_2, & t < t_1 \\[2pt] R I_1\left(1 - e^{-(t - t_1)/RC}\right) - R I_2, & t_1 < t < t_2 \\[2pt] R I_1\left(1 - e^{-(t - t_1)/RC}\right) - R I_2\,e^{-(t - t_2)/RC}, & t > t_2 \end{cases}$$

Aralıkların yorumu şöyledir:

- $t < t_1$: $I_1$'in etkisi yoktur, yalnız ikinci kaynağın sabit $-R I_2$ gerilimi vardır.
- $t_1 < t < t_2$: Birinci kaynak üstel artan bir gerilim oluşturur. İkinci kaynağın koşulu hâlâ sürer. İkisinin yönlü toplamı alınır.
- $t > t_2$: Birinci kaynağın geçici hali devam ederken ikinci kaynak devreden çıkmıştır. Birinci kaynağın etkisi sıfırdan $R I_1$'e doğru artar, ikinci kaynağın etkisi başlangıç değerinden üstel olarak azalır.

### 11.4 Sınır Kontrolleri ve Süreklilik

Beklentiler kontrol edilir. $t \to -\infty$'da devrede yalnız $I_2$ vardır ve ilk aralıkta $t$ bulunmadığı için doğrudan $-R I_2$ gelir. $t_1^-$ anında ikinci aralıkta $t = t_1$ yazılırsa $1 - 1 = 0$ olur, yine $-R I_2$ kalır.

Üçüncü kontrol $t_2$ sınırındaki sürekliliktir: $v_C(t_2^-) = v_C(t_2^+)$ mi? Üçüncü aralıkta $t = t_2$ yazılınca üstel terim 1'e gider ve $-R I_2$ kalır. Diğer terim iki aralıkta da aynıdır. İki taraf eşittir. Üç aralığın türev denklemini sağladığı ve sınırların sürekli olduğu python ile sayısal olarak sınandı.

> **Hocanın vurgusu:** Kapasite gerilimi süreklidir, atlama yapamaz. Endüktans akımı da süreklidir. Atlama olması anlık bir enerji deşarjı demektir ve böyle bir şey söz konusu değildir. Aralık analizi yaparken bu sürekliliği kontrol etmeyi ihmal etmeyin, cevabınızın doğruluğunu sınar.

> **Ek bilgi (derste anlatılmadı):** Bu ilke büyük olasılıkla doğrudan eleman denklemlerinden de görülür. $v_C$ atlasaydı $i_C = C\,dv_C/dt$ sonsuz olurdu. $i_L$ atlasaydı $v_L = L\,di_L/dt$ sonsuz olurdu. Sınırlı kaynaklı bir devrede bunlar oluşamaz.

Elde ettiğimiz dört formül (kaynak varken $i_L$ ve $v_C$, kaynak yokken $i_L$ ve $v_C$) süperpozisyonla birlikte kullanılarak bu tür karma devrelerin her biri çözülebilir. Slaytta bu denklemlerin bir özeti de vardır ve başvuru için kullanılabilir.

## 12. Example 02: Kaynağı Çıkarılan RL Devresi

Sonraki örneklerde kritik nokta ilk koşulların, yani uç değerlerin belirlenmesidir. Bu da DC analizle yapılır.

**Verilen:** 5 V kaynak, $t = 0$'da açılan ve açık kalan anahtar, seri $10\,\mu$H endüktans ve $1$ k$\Omega$ direnç.

**$t < 0$ için DC analiz:** Kaynak $-\infty$'dan beri devreyi beslediği için DC şartlanma vardır. Endüktans kısa devredir:

$$i_L(0^-) = i_R = \frac{5\text{ V}}{1\text{ k}\Omega} = 5\text{ mA}$$

Endüktansın başlangıç koşulu, yani depoladığı enerji budur.

**Kaynağın modellenmesi:** Anahtarın açılması kaynağın devreden çıkması demektir, ama $t = 0$'a kadar devrede kalmalıdır. Bu yüzden yine $1 - u(t)$ kullanılır. $u(t)$ 0'dan 1'e, $1 - u(t)$ 1'den 0'a geçer, $5[1 - u(t)]$ ise $t = 0$'a kadar 5 V gelir ve sonra sıfıra düşer.

**$t > 0$ için:** Başlangıç enerjisi olan bir endüktans ve bir direnç kalır, zamanla enerji azalır. Hoca burada anahtar açıkken devrenin açık devreye benzediğini fark etti ve depolanan enerjinin harcanacağı bir yol olması gerektiğini söyledi.

> **Ders sonrası not:** Seri devrede anahtar gerçekten açılsaydı endüktans akımının akacağı yol kalmazdı. Slayttaki çözüm büyük olasılıkla kaynağın $5[1 - u(t)]$ ile modellendiğini, yani kaynağın sıfır gerilimli kısa devreye dönüştüğünü ve L-R çevresinin kapalı kaldığını kabul eder. Aşağıdaki hesap bu kabulle tutarlıdır.

**Zaman sabiti:**

$$\tau = \frac{L}{R} = \frac{10\,\mu\text{H}}{1\text{ k}\Omega} = \frac{10\times 10^{-6}}{10^{3}} = 10\text{ ns}$$

> **Ders sonrası not:** Slaytta bobin bir yerde 10 mH olarak geçiyor, hoca "m değil u olacak, mikrohenri" diyerek düzeltti. 10 mH ile sonuç 10 $\mu$s olurdu (python ile hesaplandı). Hoca ayrıca bu sırada "$10^{-9}$" dedi; $\mu$ öneki $10^{-6}$'dır, $10^{-9}$ ise sonuçtaki nano önekidir.

**Sonuçlar:**

$$i_L(t) = 5\,e^{-t/10\text{ ns}}\text{ mA}$$

$$v_R(t) = i_L R = 5\,e^{-t/10\text{ ns}}\text{ V}$$

$$v_L(t) = L\frac{di_L}{dt} = -5\,e^{-t/10\text{ ns}}\text{ V}$$

Türevden gelen çarpan $-1/\tau$'dur. Başlangıç değeri için python ile $L \cdot 5\text{ mA} \cdot (-1/\tau) = -5$ V hesaplandı. Son olarak $v_R + v_L = 0$ olması gerektiği için sonuç bu yoldan da doğrulanır.

## 13. Example 03: Kaynağı Çıkarılan RC Devresi

**Verilen:** 5 V kaynak ve $t = 2$ ms'de açılan anahtar. Anahtardan sonra $R_1 = 1$ k$\Omega$ toprağa bağlıdır. Devamında seri $R_2 = 3$ k$\Omega$, ardından $R_3 = 12$ k$\Omega$ ve $C_1 = 2\,\mu$F paralel olarak toprağa bağlıdır. İstenen, kapasite geriliminin zamanla değişimidir.

**Kaynağın modellenmesi:** Kaynak $t = 2$ ms'de devreden çıktığı için $5[1 - u(t - 2\text{ ms})]$ V olarak yazılır.

**$t < 2$ ms için DC analiz:** Kapasite açık devredir. $R_2$ ve $R_3$ seri olduğu için toplam $15$ k$\Omega$ yapar ve $1$ k$\Omega$ ile paraleldir. Kaynak doğrudan bu kola bağlı olduğundan koldaki gerilim 5 V'tur. Hoca gerilim bölücüyü oranla anlattı: $R_2$ üzerinde $x$ birim, $R_3$ üzerinde $4x$ birim. Toplam $5x = 5$ V olduğu için $R_3$ üzerinde 4 V düşer:

$$v_C(2\text{ ms}^-) = 5\cdot\frac{12}{3 + 12} = 4\text{ V}$$

**$t > 2$ ms için zaman sabiti:** Kaynak çıkınca başlangıç gerilimli bir kapasite ve bir direnç dizisi kalır. $R$, kapasite uçlarından bakılarak bulunur. $12$ k$\Omega$ bir kol, $3$ k$\Omega + 1$ k$\Omega = 4$ k$\Omega$ diğer koldur ve bunlar paraleldir:

$$\frac{1}{R_{\text{eş}}} = \frac{1}{12\text{k}} + \frac{1}{4\text{k}} \;\Rightarrow\; R_{\text{eş}} = 3\text{ k}\Omega$$

$$\tau = R_{\text{eş}}C = 3\times 10^{3}\cdot 2\times 10^{-6} = 6\times 10^{-3}\text{ s} = 6\text{ ms}$$

> **Ders sonrası not:** Hoca önce mikroyu $10^{-9}$ alıp $\tau = 6\,\mu$s buldu, sonra kendisi düzeltti: $2\,\mu\text{F} = 2\times 10^{-6}$ F ve $\tau = 6$ ms. Slaytlarda $\mu$ önekinin yazım kolaylığı için "u" ile gösterildiğini de belirtti. Çözüme $t$ yerine $t - 2$ ms yazılması gerektiğini de sonradan ekledi.

**Sonuç:**

$$v_C(t) = 4\,e^{-(t - 2\text{ ms})/6\text{ ms}}\text{ V}, \qquad t > 2\text{ ms}$$

**Akım:** $v_C$ elde edildikten sonra türevi alınır ve $C$ ile çarpılır. Türevden $-1/6$ ms katsayısı gelir:

$$i_C(t) = C\frac{dv_C}{dt} = 2\,\mu\text{F}\cdot 4\text{ V}\cdot\left(-\frac{1}{6\text{ ms}}\right)e^{-(t - 2\text{ ms})/6\text{ ms}} = -1.33\,e^{-(t - 2\text{ ms})/6\text{ ms}}\text{ mA}$$

> **Ders sonrası not:** Hoca "$i_C$ ile $i_R$ akımı eşit" dedi. Bu, eşdeğer direnç için ve ters işaretle geçerlidir. Tek tek dirençlerde kapasite akımı bölünür. Python ile hesaplandı: $t = 2$ ms$^+$ anında $4$ k$\Omega$'luk koldan 1 mA, $R_3$'ten 0.33 mA geçer, toplam 1.33 mA'dir.

Bu örnekten sonra benzer bir örnek daha var, özel bir durumu yok ve başlangıç enerjisi de yoktur. Hoca Example 04'ün incelemesini tekrara girdiği için öğrencilere bıraktı.

## Dersin Toparlaması

Bu derste önce Thevenin ve Norton eşdeğerleri laboratuvar görevi ve vize soruları üzerinden uygulandı. Bağımlı kaynakların sıfırlanmaması, açık uçtaki dirençten akım akmaması ve yönlere dikkat edilmesi öne çıkan noktalardı. Ardından birinci dereceden devrelere geçildi. DC koşulda kapasite açık, endüktans kısa devredir. Başlangıç enerjisi olan eleman direnç üzerinden üstel olarak boşalır: $v_C = V_0 e^{-t/\tau}$, $i_L = I_0 e^{-t/\tau}$. Zaman sabiti $RC$ ya da $L/R$'dir ve içindeki direnç elemanın uçlarından görülen $R_{TH}$'dir. Tekillik fonksiyonları kaynağın devreye girişini ve çıkışını matematiksel olarak yazmamızı sağlar.

Zorlayıcı kaynakta çözüm, doğal ve zorlanmış çözümün toplamıdır. Basamak cevabı sıfırdan başlayıp son değere üstel olarak yaklaşır. Birden fazla kaynakta süperpozisyon kullanılır ve aralık sınırlarında süreklilik kontrol edilir. Birinci dereceden devreler burada biter. Sonraki konu RLC devreleri, yani ikinci dereceden devrelerdir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
