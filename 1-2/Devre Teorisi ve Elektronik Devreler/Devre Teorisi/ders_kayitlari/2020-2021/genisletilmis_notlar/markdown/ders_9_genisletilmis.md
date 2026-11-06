# Ders 9 Genişletilmiş Notu: İkinci Dereceden Devreler: Başlangıç Koşulları, Kaynaksız ve Basamak Cevaplı Seri/Paralel RLC Devreleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. RL ve RC Devrelerinden RLC Devrelerine
- 2. İkinci Dereceden Devre Nedir?
- 3. Uç Durumlar: DC Analiz ve Süreklilik
- 4. Uç Durum Örnekleri
- 5. Kaynaksız Seri RLC Devresi
- 6. Köklerin Üç Durumu: Aşırı, Kritik ve Az Sönümlü Cevap
- 7. Kaynaksız Paralel RLC Devresi
- 8. Kaynaksız Devrelerin Özeti
- 9. Basamak Cevaplı Seri RLC Devresi
- 10. Başlangıç Koşulları Genel Çözüme Konur
- 11. Basamak Cevaplı Paralel RLC Devresi
- 12. Sinüzoidal Kaynak ve Fazöre Geçiş
- 13. Pratikte Soru Nasıl Çözülür?

## 1. RL ve RC Devrelerinden RLC Devrelerine

### 1.1 Önceki Dersten Hatırlananlar

Hoca derse, en son incelenen RL ve RC devrelerini hatırlatarak başladı. Bu devrelerin zaman domenindeki, yani $t$'ye bağlı davranışı incelenmişti. Bir kaynak devreye bağlandıktan sonra ne olduğunu anlamak için iki uç durum analiz edilmişti: kaynağın uzun süredir devrede olmadığı başlangıç durumu ve kaynağın uzun süre devrede kaldığı, $t$ sonsuza giderkenki nihai durum. Kaynağın devreye bağlandığı $t_0$ anının civarında ise büyüklüklerin üstel olarak değiştiği diferansiyel denklem çözümleriyle gösterilmişti.

O derste elde edilen diferansiyel denklemler aslında tek bir arayışa varıyordu: kendisiyle doğrusal bağımlı yazılabilen bir fonksiyon. Bu da üstel bir fonksiyon önerisine, yani $e^{\alpha t}$ biçiminde bir çözüme götürüyordu. Öneri denklemde yerine konuyor, sonra katsayılar belirleniyordu. Katsayıyı belirlemek için bir başlangıç koşulu gerekiyordu. Bu koşul, kaynağın devreye girdiği ya da devreden çıktığı anın hemen öncesindeki, yani $t_0^-$ anındaki durumdan hesaplanıyordu.

Önemli bir özellik daha vardı: Kapasitenin gerilimi kaynağın bağlandığı an dahil süreklilik göstermek zorundadır, ani yükselip düşemez. Endüktansın akımı da kaynağın devreye girdiği ya da çıktığı anda süreklilik göstermek zorundadır. Hoca bu iki kısıtın RLC devreleri için de geçerli olduğunu söyledi.

### 1.2 Dersin Planı

Bu haftanın konusu RLC devreleridir. Sıra şöyledir:

1. Uç durumlar: $t = -\infty$, $t = t_0^-$, $t = t_0^+$ ve $t = \infty$ için başlangıç ve son durumların (boundary, initial ve final condition) hesabı.
2. Kaynaksız (source-free) seri RLC devresi.
3. Kaynaksız paralel RLC devresi.
4. Birim basamak fonksiyonu biçiminde kaynak bağlanmış seri RLC devresi.
5. Birim basamak fonksiyonu biçiminde kaynak bağlanmış paralel RLC devresi.

> **Ders sonrası not:** Hoca uç durumları sayarken ilkini "$t$ eşittir sonsuz" dedi; doğrusu $t = -\infty$'dur. Listenin sonundaki durum $t = +\infty$'dur.

RL ve RC devrelerinde tek bir koşul yetiyordu. Örneğin kapasitenin $t_0^-$ anındaki gerilimini bilmek, tek katsayıyı bulmak için yeterliydi. RLC devrelerinde ise iki katsayı bulunacaktır. Bunun için ilgilenilen değişkenin belirli bir andaki değeri ve aynı değişkenin türevinin o andaki değeri olmak üzere iki başlangıç koşulu gerekir.

### 1.3 Homojen ve Zorlanmış Çözüm

Bu derste de diferansiyel denklemler çözülecektir. Hoca şu ayrımı hatırlattı: Kaynaksız devrelerde bulunan sonuç, genel bir diferansiyel denklem için **homojen çözüme** karşılık gelir. Devrede kaynak varsa, yani denklem sıfırdan farklı bir şeye eşitse, bir de **zorlanmış çözüm** gerekir. Aranan cevap ikisinin toplamıdır:

$$\text{genel çözüm} = \text{homojen çözüm} + \text{zorlanmış çözüm}$$

Zorlanmış çözüm, denklemin sağ tarafı ne ise ona benzer bir öneriyle bulunur:

- **Sabit değer:** Birim basamak kaynakta sağ taraf sabittir, öneri de sabit bir değerdir.
- **Sinüzoidal kaynak:** Genlik ve faz farkı olmak üzere iki parametreli en genel biçim önerilir: $A\sin(\omega t + \phi)$.
- **Rampa ya da doğrusal fonksiyon:** Kaynak $at + b$ biçimindeyse (örneğin $3t + 5$), hoca ikinci dereceden bir polinom önerdi: $At^2 + Bt + C$.

> **Ders sonrası not:** Hoca rampa için ikinci dereceden polinom önerdi; birinci dereceden $Bt + C$ önerisi yeterlidir. $At^2 + Bt + C$ önerilirse denklemdeki $t^2$ teriminden $A = 0$ çıkar (python ile hesaplandı; denklemde $i$ ya da $v$ teriminin katsayısı sıfırdan farklıyken geçerlidir).

## 2. İkinci Dereceden Devre Nedir?

İkinci dereceden devreler, derste ele alındığı biçimiyle RLC devreleridir. Bu adı almalarının sebebi devrede en az iki enerji depolayan elemanın bulunmasıdır. Bu devrelerde iki tür analiz yapılacaktır:

- **DC analiz:** $t = \infty$ ve $t = -\infty$ durumlarındaki uç değerleri ve geçişlerde kullanılacak sınır değerlerini verir.
- **Geçici hâl (transient) analizi:** Kaynak devreye bağlandığında ya da devreden çıktığında endüktans ve kapasitenin akım ve gerilim değerlerinin zamana bağlı fonksiyonlarını verir.

İki enerji depolayan elemanın farklı dizilişleri vardır. Seri RLC, paralel RLC, birbiriyle kuple iki RLC yapısı ve iki kapasitenin bir direnç üzerinden bir kaynağa bağlandığı durumların hepsi ikinci dereceden diferansiyel denklem gerektirir. Bu derste seri ve paralel RLC görülecektir. Önce kaynaksız hâller incelenir: Bir başlangıç koşulu vardır, kaynak $t_0$ anında devreden çıkar ve elemanlarda depolanmış enerji yüzünden akım ve gerilim değişimi olur. Son kısımda ise $t$ sonsuza giderken devrede kalan zorlayıcı bir kaynak bulunur ve onun etkisi incelenir.

## 3. Uç Durumlar: DC Analiz ve Süreklilik

### 3.1 DC Rejimler

Uç durumlar, kaynağın $t_0$ anında bağlanması ya da çıkarılması dışında kalan durumlardır, yani uzun süre DC şartlarda çalışılan durumlardır. Bu rejimler iki aralıktadır: $-\infty$'dan $t_0^-$ anına kadar ve $t \to \infty$ durumu. Teoride "uzun süre" bu sonsuz durumlardır. Pratikte ise beş zaman sabiti kadar süre geçtikten sonra bu duruma gelindiği kabul edilir.

DC şartlarda:

- Kapasite **açık devre** gibi davranır. Dolayısıyla akımı sıfırdır: $i_C = 0$. Hatırlama yolu, kapasitenin şematik çizimidir: birbirine değmeyen iki paralel plaka.
- Endüktans **kısa devre** gibi davranır. Dolayısıyla gerilimi sıfırdır: $v_L = 0$.

Bu yerine koymalar yapıldıktan sonra geriye direnç ve kaynaklardan oluşan bir devre kalır. Seri ve paralel bağlılık durumlarına göre $v_C$ ve $i_L$ hesaplanır. Aynı işlem hem $t < t_0$ için hem de $t \to \infty$ için yapılır.

### 3.2 $t_0$ Anında Süreklilik

Hoca bunu çok önemli bir koşul olarak vurguladı. $t_0$'ın hemen öncesi ve hemen sonrası için:

$$v_C(t_0^-) = v_C(t_0^+), \qquad i_L(t_0^-) = i_L(t_0^+)$$

Yani $-\infty$'dan $t_0^-$ anına kadar kapasitenin gerilimi neyse, kaynak devreye girdikten ya da çıktıktan sonraki $t_0^+$ anında da aynı değere sahip olmalıdır. Endüktansın akımı da aynı değerden itibaren değişmeye başlar. Bu değerler geçici hâl analizinin başlangıç koşullarıdır.

Bunu aklında tutmanın yolu, iki elemanın tanım bağıntılarını diferansiyel biçimde yazmaktır:

$$i_C = C\frac{dv_C}{dt}, \qquad v_L = L\frac{di_L}{dt}$$

Türevi alınan değişken süreklilik göstermek zorundadır. Kapasitenin gerilimi anlık olarak büyük değişimler gösterebilseydi akımda büyük sıçramalar olurdu ve bunu sağlayabilecek bir yapı yoktur.

> **Hocanın vurgusu:** DC şartlarda kapasitenin yerine açık devre, endüktansın yerine kısa devre konur. Geçiş anında ise kapasitenin gerilimi ve endüktansın akımı süreklilik göstermek zorundadır. Bunlar aklınızdan çıkmamalı.

## 4. Uç Durum Örnekleri

Hoca dört örnek gösterdi, üçünü çözdü, dördüncüyü öğrencilere bıraktı.

<!-- BELİRSİZ: Örnek devre şemaları yalnız slaytta. Bağlantılar altyazıdaki anlatımdan ve kısa nottan kuruldu. Örnek 2, 3 ve 4'teki bazı eleman değerleri (L ve C değerleri, Örnek 4'ün tüm değerleri) altyazıda geçmiyor, kısa nottan alındı. -->

### 4.1 Örnek 1: Anahtar Açılınca Kaynağın Devreden Çıkması

**Verilen:** $V_1$ kaynağı ve ona seri $R_1$; düğümden toprağa $R_2$; aynı düğümden $L_1$, $R_3$ ve $C_1$'in seri bağlı olduğu bir kol. Anahtar uzun süre kapalı kalmış, $t = t_0$ anında açılıyor. Uç durumlar isteniyor.

**$t < t_0$ durumu.** Devre DC şartlarda çalışır. Endüktans kısa devre, kapasite açık devredir. Hoca, kapasitenin direncini sonsuz gibi düşünmenin de mümkün olduğunu söyledi. Kapasite açık devre olduğu için bu kolda akım akmaz:

$$i_L = i_C = 0, \qquad v_L = 0$$

Akım akmadığı için $R_3$ üzerinde gerilim düşümü de olmaz. Bu yüzden $R_2$ üzerinde görülen gerilimin aynısı $v_C$'de görülür. $R_1$ ve $R_2$ gerilim bölücü gibi çalışır, koldaki akım $V_1/(R_1 + R_2)$'dir:

$$v_C = \frac{V_1}{R_1 + R_2}\,R_2$$

**$t \to \infty$ durumu.** Anahtar açıldığı için kaynağın artık katkısı yoktur. Endüktans yine kısa devre, kapasite yine açık devredir. Devrede kaynak kalmadığı için ilgilenilen dört değer de sıfır olur:

$$i_L = v_L = i_C = v_C = 0$$

**Aradaki aralık.** Değerin $t_0^-$'da sıfır, $t \to \infty$'da sıfır olması, arada da sıfır olduğu anlamına gelmez. $i_L$ örneğin bu aralıkta yükselip azalabilir. $t_0$'ın artı yönündeki aralıkta $i_L$, $v_L$, $i_C$ ve $v_C$ sıfırdan farklı değerler alır ve üstel fonksiyonlar cinsinden ifade edilir.

### 4.2 Örnek 2: İki Kaynaklı Devre

**Verilen:** Solda $V_1 = 2$ V ve seri $R_1 = 5$ kΩ, sağda $V_2 = 5$ V ve seri $R_2 = 5$ kΩ. Ortadaki düğümden toprağa $C_1$, düğüm ile sağ taraf arasında $L_1 = 10$ µH. Anahtar uzun süre kapalı, $t_0$ anında açılıyor ve sol taraf devreden çıkıyor. Yani anahtar kapalıyken iki kaynak birlikte etki eder, açılınca tek kaynak kalır.

**$t < t_0$ durumu.** Kapasite açık devre, endüktans kısa devre yapıldığında tek bir çevre kalır. Net kaynak ve toplam direnç şöyledir:

$$V_{\text{net}} = 5 - 2 = 3\text{ V}, \qquad R_{\text{toplam}} = 5\text{ k}\Omega + 5\text{ k}\Omega = 10\text{ k}\Omega$$

$$|i_L| = \frac{3\text{ V}}{10\text{ k}\Omega} = 0.3\text{ mA}$$

Ayrıca kısa devre olduğu için $v_L = 0$, açık devre olduğu için $i_C = 0$'dır.

**Soru:** $i_L$ burada eksi olmaz mı? Çünkü 5 voltluk kaynağın artı tarafı yukarıda. **Cevap:** Doğru, eksi yönlü olur. Slaytta yalnız genlik yazılmış. Gerilim hesabı yapılırken yön dikkate alınacak.

> **Ders sonrası not:** Slaytta $i_L = 0.3$ mA yazıyor; hocanın onayladığı gibi, ok yönüne göre değer $i_L = -0.3$ mA'dir. Kısa nottaki slayt bilgisine göre $i_L$ oku sağa doğrudur, net akım ise 5 V'tan 2 V'a, yani sağdan sola akar. <!-- BELİRSİZ: i_L okunun yönü altyazıda yalnız "bu yönde" diye geçiyor, slaytta. -->

Kapasitenin gerilimi orta düğümün gerilimidir. Akım yönü dikkate alındığında $R_1$ üzerindeki düşüm 1.5 V'tur ve 2 V'un üstüne eklenir:

$$v_C = 2 + 5\text{ k}\Omega \cdot 0.3\text{ mA} = 2 + 1.5 = 3.5\text{ V}$$

Sağ taraftan da aynı sonuç çıkar (ara adım eklendi): $5 - 1.5 = 3.5$ V. Bu sonuç python ile hesaplandı.

**$t \to \infty$ durumu.** Anahtar açıldığı için devrenin sol tarafı etki etmez. Kapasite açık devre, endüktans kısa devredir. Çevre tamamlanamaz, akım akmaz:

$$i_L = i_C = 0, \qquad v_L = 0$$

Akım akmadığı için $R_2$ üzerinde düşüm yoktur ve 5 voltluk kaynağın uçlarındaki gerilim doğrudan kapasitede görülür: $v_C = 5$ V.

Geçici hâlde beklenen, bu değerlerden başlayıp $t \to \infty$'da belirtilen değerlere ulaşan üstel fonksiyonlardır. İki uç değer bu fonksiyonların elde edilmesinde kullanılacaktır. Süreklilikten $v_C(t_0^+) = 3.5$ V'tur (ara adım eklendi).

### 4.3 Örnek 3: İki Endüktanslı Devre

**Verilen:** Aynı yapı, ancak orta düğümden toprağa kapasite yerine $L_2 = 40$ µH bağlı. $L_1 = 10$ µH. Anahtar uzun süre açık kalıyor, $t_0$ anında kapanıyor. Dolayısıyla $t_0^-$'a kadar sol taraf devrede değildir, $t \to \infty$'da her iki taraf da devrededir.

**$t < t_0$ durumu.** Her iki endüktans da kısa devredir. Orta düğüm $L_2$'nin kısa devresi üzerinden toprağa bağlıdır, yani 0 V'tur. 5 V kaynağı 5 kΩ üzerinden bu düğüme bir akım gönderir:

$$\frac{5\text{ V}}{5\text{ k}\Omega} = 1\text{ mA}$$

Bu akım $i_{L2}$ yönündedir, $i_{L1}$ yönünün ise tersidir:

$$i_{L2} = 1\text{ mA}, \qquad i_{L1} = -1\text{ mA}, \qquad v_{L1} = v_{L2} = 0$$

**$t \to \infty$ durumu.** Anahtar kapalı, iki endüktans yine kısa devredir ve iki gerilim de sıfırdır: $v_{L1} = v_{L2} = 0$. Hoca önce devreyi "5k, 5k, 10k, net 3 V" diye tek çevre gibi toplamaya başladı, sonra orta düğümün 0 V olduğunu görüp her kolu ayrı hesapladı. Kısa devre orta düğümü toprağa bağladığı için iki kol birbirinden bağımsızdır:

- Sağ kol: Düğüm 0 V olduğundan akım yine 1 mA'dir, yönü dikkate alınınca $i_{L1} = -1$ mA.
- Sol kol: 2 V kaynağı 5 kΩ üzerinden düğüme $\dfrac{2\text{ V}}{5\text{ k}\Omega} = 0.4$ mA gönderir. Bu akım da $i_{L2}$ yönündedir.

Toplam:

$$i_{L2} = 1 + 0.4 = 1.4\text{ mA}$$

Bu sonuçlar python ile hesaplandı. Anahtar kapatılana kadar devre $t < t_0$ değerlerindedir. Kapandıktan sonra bu değerlerden başlayıp $t = \infty$ değerlerine ulaşan üstel fonksiyonlar yazılacaktır.

### 4.4 Örnek 4: Öğrencilere Bırakılan Örnek

Hoca bu örneği çözmedi, dikkat edilecek noktaları söyledi. Devrede iki paralel kapasite vardır, bunlar eşdeğeri alınarak tek kapasite gibi kullanılabilir. İki kaynak vardır. $t = 0$ anına kadar ikisi de devrededir, $t = 0$'da sağdaki kaynak devreden çıkar ve yalnız soldaki kalır. Devre $t = -\infty$'dan $0^-$ anına kadar ve $t = \infty$ için aynı mantıkla çözülür. Kısa nottaki slayt değerleri şöyledir: $V_1 = 1$ V, $L_1 = 10$ µH, $C_1 = C_2 = 1$ µF, $R_1 = 1$ kΩ, $V_2 = 5$ V, $R_2 = 3$ kΩ.

> **Ders sonrası not:** Çözüm derste yapılmadı. Kaynakların artı uçları üstteyse ve iki direnç aynı çevredeyse, $t < 0$'da net 4 V ve toplam 4 kΩ ile akımın genliği 1 mA'dir (python ile hesaplandı). $t \to \infty$'da büyük olasılıkla $i_L = 0$, $v_L = 0$, $i_C = 0$, $v_C = 1$ V'tur. $t < 0$'daki $v_C$ ise dirençlerin hangi tarafta olduğuna bağlıdır: 1 kΩ, 5 V tarafındaysa 4 V, 3 kΩ, 5 V tarafındaysa 2 V çıkar (python ile hesaplandı). Kısa not 4 V veriyor; şekil altyazıda olmadığı için bu değer büyük olasılıkla doğrudur, ama doğrulanamadı. <!-- BELİRSİZ: Örnek 4'ün bağlantı şeması altyazıda yok. -->

### 4.5 Örneklerden Sonra Gelen Soru

**Soru:** Örneklerde $t_0$ ile sonsuz arasındaki kısma bir daha bakabilir miyiz? **Cevap:** O kısım henüz anlatılmadı, geçici hâl analizinde anlatılacak. Şunu şimdiden söylemek gerekir: Bu aralıkta endüktansın yerine kısa devre, kapasitenin yerine açık devre koymaya gerek yoktur. Çünkü elemanlar burada diferansiyel bağıntılarına göre akım ve gerilim değiştirir. Bu bağıntılardan ikinci dereceden bir diferansiyel denklem yazılarak $t_0^+$ ile sonsuz arasındaki çözüm elde edilecektir.

## 5. Kaynaksız Seri RLC Devresi

### 5.1 "Kaynaksız" Ne Demek?

Kaynaksız RLC devrelerinden kasıt şudur: Belirli bir kaynak, devredeki endüktans ve kapasitede enerji depolar. Sonra $t_0$ anında bu kaynak devreden çıkarılır. Elemanlarda depolanmış enerji, direnç üzerinden harcanırken devrede akım ve gerilim oluşturur. $t \to \infty$'da bütün değerler asimptotik olarak sıfıra oturur.

Hoca çözüme geçmeden üç senaryoyu önceden haber verdi. İkinci dereceden denklemin ($x^2 + bx + c = 0$ gibi) iki kökü vardır:

- Kökler gerçek ve farklıysa **aşırı sönümlü (overdamped)** durum olur, sonuç iki farklı üstel fonksiyonun toplamıdır.
- Kökler eşitse, yani katlı kökse **kritik sönümlü (critically damped)** durum olur.
- Kökler karmaşıksa **az sönümlü (underdamped)** durum olur.

### 5.2 Devre ve Başlangıç Koşulları

Devre, $V_s$ kaynağı, $R = 2$ kΩ, $L = 10$ µH ve $C = 3$ µF'tan oluşan bir seri RLC devresidir. Kaynak $V_s[1 - u(t - t_0)]$ biçimindedir. Yani $-\infty$'dan $t_0$ anına kadar devrededir, $t_0$ anında sıfırlanır. Burada "devreden çıkarmak", kaynağı sıfırlamak demektir. $t_0^-$ anına kadar endüktans ve kapasite DC şartlarda enerji depolar. Sonra bu enerji direnç üzerinden harcanarak $v_C$, $v_L$, $i_C$ ve $i_L$'de üstel bir değişime yol açar.

<!-- BELİRSİZ: Kaynak ifadesinin yazımı altyazıda "1-U-T-T0" diye geçiyor; V_s[1 - u(t - t_0)] biçimi kısa nottan alındı. -->

$-\infty < t < t_0^-$ aralığı DC'dir. Endüktansın yerine kısa devre, kapasitenin yerine açık devre konur. Hoca değerleri öğrencilerle birlikte buldu:

**Soru:** $v_L$ niye sıfır? **Cevap:** Endüktansın yerine kısa devre konduğu için. Direnci sıfır olan bir elemanın üzerinde gerilim düşümü olmaz.

**Soru:** $v_C$ için ne denebilir? **Cevap:** $V_s$ denebilir. Devre açık olduğu için akım akmaz, 2 kΩ'luk direnç üzerinden akan akım sıfırdır. Bu yüzden $v_C$, kaynak uçlarındaki gerilimin aynısıdır.

**Soru:** $i_L$ ve $i_C$ için ne denebilir? **Cevap:** Akım akmadığı için ikisi de sıfırdır.

Özetle $t < t_0$ için $v_L = 0$, $v_C = V_s$, $i_L = i_C = 0$'dır. Süreklilikten:

$$v_C(t_0^+) = V_s, \qquad i_L(t_0^+) = 0$$

### 5.3 Diferansiyel Denklem

$t > t_0$ için devrede kaynak yoktur. Eşdeğer devre, sıfırlanan kaynak, 2 kΩ, endüktans ve kapasiteden ibarettir. Çevre boyunca Kirchhoff gerilimler kanunu:

$$v_R + v_L + v_C = 0$$

Her eleman tanım bağıntısıyla yazılır. Seri devrede tek bir ana kol akımı vardır: $i = i_C = i_L = i_R$. Bu akımı belirleyen, kapasitenin gerilimindeki değişimdir. Hoca bunu $q = Cv$ tanımından hatırlattı:

$$i = C\frac{dv_C}{dt}$$

Benzer şekilde $\phi = Li$ tanımından endüktans gerilimi yazılır. $i_L = i_C$ olduğu için:

$$v_L = L\frac{di_L}{dt} = L\frac{d}{dt}\left(C\frac{dv_C}{dt}\right) = LC\frac{d^2 v_C}{dt^2}$$

Direnç gerilimi ise:

$$v_R = iR = RC\frac{dv_C}{dt}$$

Bunlar çevre denkleminde yerine konur ve her taraf $LC$'ye bölünür:

$$LC\frac{d^2 v_C}{dt^2} + RC\frac{dv_C}{dt} + v_C = 0$$

$$\frac{d^2 v_C}{dt^2} + \frac{R}{L}\frac{dv_C}{dt} + \frac{1}{LC}v_C = 0$$

Bu, önceki dersteki denklemlerden farklıdır. Orada birinci türev ve fonksiyonun kendisi vardı, burada ikinci türev de vardır.

### 5.4 Çözüm Önerisi ve Karakteristik Denklem

Aranan şey, zamana bağlı öyle bir değişkendir ki ikinci türevi, birinci türevi ve kendisi birbiriyle doğrusal bağımlıdır. $R/L$ ve $1/LC$ sabit katsayılardır. Doğrusal bağımlılık, bu büyüklüklerin belli bir doğrusal birleşiminin toplamının sıfır olması demektir.

**Soru:** Böyle bir fonksiyon olarak ne önerirsiniz? **Cevap:** Her zamanki gibi üstel bir fonksiyon. Doğrudur. Ancak birinci dereceden denklemde tek çözüm yeterliyken burada iki farklı çözüm olması gerekir, bunu akılda tutarak ilerlenir.

Öneri, üstel olarak yazılabilecek en genel biçimdir: Fonksiyonun önünde bir katsayı, $t$'nin önünde başka bir katsayı olabilir. Hoca bu katsayıya önce $\alpha$ dedi, paralel devreye gelince karışmasın diye $s$ yazmaya başladı. Bu notta baştan $s$ kullanılmıştır:

$$v_C(t) = Ae^{st}, \qquad v_C' = sAe^{st}, \qquad v_C'' = s^2Ae^{st}$$

Denklemde yerine konup ortak parantez alınır:

$$Ae^{st}\left(s^2 + \frac{R}{L}s + \frac{1}{LC}\right) = 0$$

$A$'nın sıfır olması çözümün sıfır olması, yani trivial çözüm demektir. Bu aranmaz, çünkü sıfırdan farklı başlangıç koşulları vardır. Geriye parantezin sıfır olması kalır:

$$s^2 + \frac{R}{L}s + \frac{1}{LC} = 0$$

Aranan iki çözüm bu ikinci dereceden denklemin köklerinden gelir. Bilinen kök formülü ($-b$, $\pm\sqrt{b^2 - 4ac}$, bölü $2a$) uygulanır. Burada $a = 1$, $b = R/L$, $c = 1/(LC)$'dir:

$$s_{1,2} = \frac{-\dfrac{R}{L} \pm \sqrt{\left(\dfrac{R}{L}\right)^2 - \dfrac{4}{LC}}}{2}$$

Paydadaki 2 içeri alınır. Kökün içine girerken her iki terimi de 4'e böler:

$$s_{1,2} = -\frac{R}{2L} \pm \sqrt{\left(\frac{R}{2L}\right)^2 - \frac{1}{LC}}$$

Görüldüğü gibi kökler yalnız devrenin sabitleri olan $R$, $L$ ve $C$'ye bağlıdır.

> **Ders sonrası not:** Hoca çözümleri açık yazarken bir yerde üsteki ilk terimi $-R/L$ dedi; doğrusu $-R/(2L)$'dir.

### 5.5 Genel Homojen Çözüm

Elde iki çözüm vardır:

$$v_{C1}(t) = A_1e^{s_1t}, \qquad v_{C2}(t) = A_2e^{s_2t}$$

Katsayılar aynı olmak zorunda olmadığı için farklı yazılmıştır. Bir diferansiyel denklemin çözümü hem $v_{C1}$ hem de $v_{C2}$ ise en genel çözüm bunların doğrusal birleşimidir:

$$v_C(t) = A_1e^{s_1t} + A_2e^{s_2t}$$

Bu, doğal (homojen) çözümdür ve denklemin sıfıra eşit olduğu, yani kaynağın olmadığı duruma karşılık gelir. Kaynak olsaydı buna bir de zorlanmış çözüm eklenecekti.

### 5.6 Katsayıların Bulunması

$s_1$ ve $s_2$ bilinmektedir, bilinmeyenler büyük $A_1$ ve $A_2$'dir. İki bilinmeyen için iki koşul gerekir: $v_C$'nin belli bir andaki değeri ve $v_C$'nin türevinin belli bir andaki değeri. Türevle ilgili bilgi akımda saklıdır, çünkü $i_C = C\,dv_C/dt$'dir.

$t = 0$'da kaynağın kesildiği durumda $v_C(0) = V_s$ ve $i_C(0) = 0$ koşulları şu denklemleri verir:

$$A_1 + A_2 = V_s$$

$$s_1A_1 + s_2A_2 = 0$$

İki denklemin çözümü (ara adım eklendi):

$$A_1 = -\frac{s_2}{s_1 - s_2}V_s, \qquad A_2 = \frac{s_1}{s_1 - s_2}V_s$$

Kaynak $t = 0$ yerine $t_0$ anında kesiliyorsa denklemlerdeki $t$'lerin yerine $t - t_0$ yazılır.

Hoca burada şu uyarıyı yaptı ve dersin sonunda geri döneceğini söyledi: Zorlanmış çözüm varsa bu sınır koşulları homojen artı zorlanmış çözümde yerine konarak katsayılar bulunur.

### 5.7 Diğer Büyüklükler

$v_C(t)$ bir kere bulununca gerisi kolaydır:

- $v_C$'nin türevi alınıp kapasiteyle çarpılır: $i_C(t) = C\,dv_C/dt$. Bu aynı zamanda $i_L(t)$, $i_R(t)$ ve ana kol akımı $i(t)$'dir.
- Bu akımın bir kez daha türevi alınıp $L$ ile çarpılır: $v_L(t) = L\,di/dt$.
- Akım $R$ ile çarpılır: $v_R(t) = Ri(t)$.

> **Ders sonrası not:** Hoca bu devrenin sayısal sonucunu yazmadı. Verilen $R = 2$ kΩ, $L = 10$ µH, $C = 3$ µF için python ile hesaplandı: $\alpha = R/(2L) = 10^8$ s⁻¹, $\omega_0 = 1/\sqrt{LC} \approx 1.826 \times 10^5$ rad/s. $\alpha > \omega_0$ olduğundan devre aşırı sönümlüdür. Kökler $s_1 \approx -2.000 \times 10^8$ s⁻¹ ve $s_2 \approx -166.67$ s⁻¹'dir. Katsayılar $A_1 \approx -8.33 \times 10^{-7}V_s$ ve $A_2 \approx V_s$ olduğundan pratikte $v_C(t) \approx V_se^{-166.67t}$ yazılabilir (zaman sabiti yaklaşık 6 ms).

## 6. Köklerin Üç Durumu: Aşırı, Kritik ve Az Sönümlü Cevap

### 6.1 Kısaltmalar: $\alpha$ ve $\omega_0$

Kökler daha okunabilir yazılmak için iki kısaltma kullanılır:

$$\alpha = \frac{R}{2L}, \qquad \omega_0 = \frac{1}{\sqrt{LC}}, \qquad s_{1,2} = -\alpha \pm \sqrt{\alpha^2 - \omega_0^2}$$

Hoca bunun $e^{\alpha t}$ önerisindeki $\alpha$'dan farklı olduğunu, kökün sabit değerleri gibi düşünülmesi gerektiğini söyledi. Bu yüzden önerideki katsayı için $s$ kullanılır. $\alpha$ ile $\omega_0$'ın karşılaştırılması üç durumu verir:

- $\alpha > \omega_0$: Kökün içi pozitiftir. İki gerçek ve farklı kök vardır. **Aşırı sönümlü.**
- $\alpha = \omega_0$: Kökün içi sıfırdır. $s_1 = s_2 = -\alpha$, yani katlı kök. Denklem $(x - b)^2 = 0$ biçimine benzer. **Kritik sönümlü.**
- $\alpha < \omega_0$: Kökün içi negatiftir. Kökler eşlenik karmaşık sayılardır: $s_{1,2} = -\alpha \pm j\beta$. **Az sönümlü.**

### 6.2 Aşırı Sönümlü Durum

İki ayrık gerçek kök vardır. Çözüm doğrudan yazılır:

$$v_C(t) = A_1e^{s_1t} + A_2e^{s_2t}$$

### 6.3 Kritik Sönümlü Durum: İkinci Çözüm Neden $t$ ile Çarpılır?

Burada sorun şudur: İkinci dereceden denklem için iki farklı çözüm gerekir, ama elde yalnız $e^{-\alpha t}$ vardır. İkinci çözüm için hoca şöyle düşündü. $Ae^{st}$ biçiminde bir fonksiyonun türevi $sAe^{st}$'dir, yani kendisi ve türevi doğrusal bağımlıdır. Şimdi de $Ate^{st}$ fonksiyonuna bakılır. Bu, $t$'ye bağlı iki fonksiyonun çarpımıdır, çarpım kuralıyla türev alınır:

$$\frac{d}{dt}\left(Ate^{st}\right) = Ae^{st} + Ats\,e^{st} = Ae^{st}(1 + st)$$

Yine üstel fonksiyonun bir polinomla çarpılmış biçimi çıkmıştır. Genelleştirirsek, $e^{st}$'nin $t$'ye bağlı bir polinomla çarpılmış hâli ve türevleri aynı aileden kalır. Bu yüzden katlı kök durumunda ikinci çözüm $t$ ile çarpılmış biçimde önerilir:

$$v_{C1}(t) = A_1e^{-\frac{R}{2L}t}, \qquad v_{C2}(t) = A_2\,t\,e^{-\frac{R}{2L}t}$$

$$v_C(t) = e^{-\alpha t}\left(A_1 + A_2t\right)$$

Slaytta $t$ yerine $\Delta t$ yazılan gösterimde $\Delta t = t - t_0$'dır. Bu, kaynağın $t_0$ anında girip çıktığı durumu ifade eder.

> **Ders sonrası not:** Hoca burada $e^{st}$ ile $te^{st}$'nin "birbiriyle doğrusal bağımlı" olduğunu söyledi; doğrusu bu iki çözümün **doğrusal bağımsız** olmasıdır. Birini diğerinin sabit katı olarak yazamayız. Wronskian değerleri $e^{2st}$ olup sıfır değildir (python ile hesaplandı). Hocanın kastettiği, bir fonksiyonun türevleriyle aynı aileden kalmasıdır; kendisi de birazdan dört katlı kök için "doğrusal bağımsız çözüm" diyor. Ayrıca $te^{st}$ fonksiyonunun türevi kendisinin sabit katı değildir, $e^{st}$ ile $te^{st}$'nin birleşimidir. Türev yazılırken parantez bir ara "$1 + t$" diye okundu; doğrusu $1 + st$'dir. $te^{-\alpha t}$ fonksiyonunun katlı kök denklemini sağladığı python ile hesaplandı.

Hoca genellemeyi şöyle yaptı: Dördüncü dereceden bir denklemde dört kökün hepsi katlı çıksaydı, yani denklem $(x - a)^4 = 0$ gibi olsaydı, dört doğrusal bağımsız çözüm önerilecekti: $Ae^{st}$, $Ate^{st}$, $At^2e^{st}$ ve $At^3e^{st}$.

### 6.4 Az Sönümlü Durum: Euler Formülü ile Sinüzoidal Çözüm

Kökün içi negatif olduğunda, içeride pozitif çıkması için büyük olan terim öne alınarak $\omega_d$ tanımlanır:

$$\omega_d = \sqrt{\omega_0^2 - \alpha^2} = \sqrt{\frac{1}{LC} - \left(\frac{R}{2L}\right)^2}, \qquad s_{1,2} = -\alpha \pm j\omega_d$$

Genel çözüm yazılır ve ortak üstel çarpan dışarı alınır:

$$v_C(t) = A_1e^{(-\alpha + j\omega_d)t} + A_2e^{(-\alpha - j\omega_d)t} = e^{-\alpha t}\left(A_1e^{j\omega_dt} + A_2e^{-j\omega_dt}\right)$$

Dışarıdaki çarpana bakılırsa, $\alpha = R/(2L)$ pozitiftir, önünde de eksi vardır. Demek ki $e^{-\alpha t}$ üstel olarak azalan (decaying) bir çarpandır. Parantezin içinin sinüzoidal olduğunu göstermek için Euler formülü kullanılır.

Euler formülü, bir karmaşık sayının kartezyen ve kutupsal biçimde yazılabilmesiyle ilgilidir. $a + jb$ biçimindeki bir sayı $re^{j\theta}$ olarak da yazılır:

$$r = \sqrt{a^2 + b^2}, \qquad \theta = \arctan\frac{b}{a}$$

Birim çember üzerinde, yani $r = 1$ iken $a = \cos\theta$, $b = \sin\theta$ olur:

$$e^{j\theta} = \cos\theta + j\sin\theta$$

Hoca bunu kısa yoldan hatırlattığını, asıl gösterimin üstel fonksiyon, kosinüs ve sinüs fonksiyonlarının Taylor açılımlarını karşılaştırmak olduğunu söyledi. Formül parantezin içine uygulanır, kosinüslü ve sinüslü terimler toplanır:

$$A_1(\cos\omega_dt + j\sin\omega_dt) + A_2(\cos\omega_dt - j\sin\omega_dt) = (A_1 + A_2)\cos\omega_dt + j(A_1 - A_2)\sin\omega_dt$$

$B_1 = A_1 + A_2$ ve $B_2 = j(A_1 - A_2)$ denirse çözüm şöyle olur:

$$v_C(t) = e^{-\alpha t}\left(B_1\cos\omega_dt + B_2\sin\omega_dt\right)$$

> **Ek bilgi (derste anlatılmadı):** $v_C(t)$ gerçek bir büyüklük olduğu için $A_1$ ve $A_2$ birbirinin eşleniğidir. Bu durumda $B_1 = A_1 + A_2$ ve $B_2 = j(A_1 - A_2)$ gerçek sayılar olur, parantezin toplamı da gerçek çıkar (python ile hesaplandı). Karmaşık sayılar yalnız ara adımda görünür, son sonuçta görünmez.

Aynı frekanstaki iki sinüzoidalin toplamı, bir genlik ve bir faz farkıyla tek terim olarak yazılabilir. Hoca bunun gösterimini ileride karmaşık sayılar ve fazörlerle yapacaklarını söyledi:

$$v_C(t) = e^{-\alpha t}\,B\cos(\omega_dt + \phi)$$

Bu biçimde de iki bilinmeyen vardır: $B$ ve $\phi$. Önceki biçimdeki iki bilinmeyen ise $B_1$ ve $B_2$ idi. İki yazım eşdeğerdir, duruma göre hangisi gerekiyorsa kullanılır.

Sonucun şekli şudur: $+e^{-\alpha t}$ ve $-e^{-\alpha t}$ eğrileri üstel olarak azalan bir zarf oluşturur. Sinüzoidal işaret bu zarfın içinde salınır, $t$ sonsuza gittiğinde söner.

> **Ders sonrası not:** Hoca genel yazımı bir yerde $e^{\alpha t}$ diye söyledi; doğrusu $e^{-\alpha t}$'dir, hemen ardından kendisi de öyle kullandı.

### 6.5 Direncin Sıfır Olduğu Durum

$\omega_0 = 1/\sqrt{LC}$ değerine **sönümsüz doğal frekans** denir. Adının sebebi şudur: $\alpha$, $R$'ye bağlıdır, $\omega_d$ ise hem $\alpha$'ya hem $\omega_0$'a bağlıdır. $R = 0$ olursa $\alpha = 0$ ve $\omega_d = \omega_0$ olur. Bu durumda zarf kalkar, işaret $\omega_0$ frekansında hiç sönümlenmeden salınır.

Bu varsayımsal bir durumdur, çünkü gerçekte devrede ya da kablolarda sıfır direnç elde edilemez. Gerçekte $R$ sıfır olmadığı için $\omega_d$ frekansında salınan, üstel zarf içinde sönen bir işaret elde edilir.

### 6.6 Üç Durumun Karşılaştırılması

Slaytta üç durumun $v_C$ grafikleri karşılaştırıldı. Hoca şunu söyledi: Kritik sönümlü durum, bütün çözümler içinde kararlı duruma (steady state) en hızlı oturan durumdur. İki gerçek köklü durum biraz daha uzun sürede oturur. Eşlenik köklü durum ise referans değer olan 0 volt civarında dalgalanır, $t$ sonsuza giderken o da 0'a oturur.

<!-- BELİRSİZ: Üç durumun grafiği yalnız slaytta; altyazıda eksen değerleri geçmiyor. -->

> **Ders sonrası not:** Hoca iki gerçek köklü durum için bir yerde "under damped" dedi; doğrusu aşırı sönümlüdür (overdamped). Ayrıca "kritik sönüm en hızlı oturur" ifadesi, salınım yapmayan durumlar arasında doğrudur. Az sönümlü devre son değere ilk kez daha erken ulaşır; zayıf sönümlüyken uzun süre salınır, ama sönüm kritiğe yakınken belirli bir tolerans bandına kritik sönümlüden daha erken de girebilir (python ile hesaplandı).

### 6.7 Katsayılar ve Koşullar

Katsayılar her üç durumda sınır koşullarını sağlatarak bulunur. İkinci dereceden denklem olduğu için iki koşul gerekir. Seri devrede denklem $v_C$ cinsinden yazıldığı için bunlar $v_C$'nin $t_0$'daki değeri ve türevinin $t_0$'daki değeridir. Türev, kapasite akımıyla ilgili olduğundan devrede belirlenen akım değeri kullanılır.

## 7. Kaynaksız Paralel RLC Devresi

### 7.1 Yöntemin Ana Hatları

Yol seri devreyle aynıdır: DC koşullardan başlangıç değerleri bulunur, sonra elemanlar yerinde bırakılarak diferansiyel denklem yazılır, iki başlangıç koşulu ile katsayılar hesaplanır. Yine üç durum çıkar. Hocanın dikkat çektiği iki nokta vardır:

- Seri kaynaksız devrede denklem **kapasite gerilimi** cinsinden yazılır. Paralel devrede ise **endüktans akımı** cinsinden yazılır. Diğer türlü de olabilir, ama ek katsayılar getirir. Endüktans akımı cinsinden çözmek burada pratiktir.
- Hem seri hem paralel kaynaksız devrede, bulunan salınım frekansı ya da üstel terimin değişim frekansı, akım ve gerilim değerlerinin hepsi için aynıdır.

<!-- BELİRSİZ: Paralel devrenin slayttaki sayısal değerleri altyazıda geçmiyor; hoca "daha genel bir şekilde çözmeye çalışacağız" diyerek sembolik ilerledi. R = 2 kΩ, L = 10 µH, C = 3 µF değerleri kısa nottan alındı. -->

### 7.2 Devre ve Başlangıç Koşulları

$-\infty$'dan $t_0^-$ anına kadar devreye bir $I_s$ akım kaynağı bağlıdır. $t_0$ anında anahtar açılır. Akım kaynağını sıfırlamak, onu devreden çıkarmak demektir.

**$t < t_0$ durumu.** Kaynak, direnç, endüktans ve kapasite birbirine paraleldir. Endüktansın yerine kısa devre, kapasitenin yerine açık devre konur. Kısa devre olduğu için akımın tamamı endüktanstan geçer:

$$i_L(t_0^-) = I_s, \qquad i_C(t_0^-) = 0, \qquad i_R(t_0^-) = 0$$

$$v_L(t_0^-) = v_C(t_0^-) = v_R(t_0^-) = 0$$

Burada dikkat çekici olan, enerjiyi yalnız endüktansın depolamış olmasıdır. Kapasitenin gerilimi sıfır olduğu için depoladığı enerji yoktur. $t > t_0$'da devreye enerjiyi endüktans sağlar.

**$t \to \infty$ durumu.** Kaynak devreden çıkmıştır, endüktans yine kısa devre, kapasite yine açık devredir. Devrede kaynak kalmadığı için:

$$i_L(\infty) = i_C(\infty) = v_L(\infty) = v_C(\infty) = 0$$

> **Ders sonrası not:** Hoca bu uç durumu anlatırken "$t$ eksi sonsuza giderken" dedi; doğrusu $t \to +\infty$'dur, çünkü kaynak devreden çıkmış durumdadır.

### 7.3 Diferansiyel Denklem

Tek bir düğüm üzerinden hareket edilir. Referans yönlerinin hepsi düğümden çıktığı için akımların toplamı sıfırdır. Elemanlar paralel olduğundan gerilimleri de ortaktır: $v_R = v_L = v_C = v$.

$$i_R + i_L + i_C = \frac{v}{R} + i_L + C\frac{dv}{dt} = 0$$

Her şey $i_L$ cinsinden yazılır. $v = L\,di_L/dt$ olduğundan:

$$\frac{L}{R}\frac{di_L}{dt} + i_L + LC\frac{d^2 i_L}{dt^2} = 0$$

Her taraf $LC$'ye bölünür:

$$\frac{d^2 i_L}{dt^2} + \frac{1}{RC}\frac{di_L}{dt} + \frac{1}{LC}i_L = 0$$

Kaynak olmadığı için bu yine homojen çözüme karşılık gelir. İkinci türevi, birinci türevi ve kendisi doğrusal bağımlı bir fonksiyon, yani yine üstel bir öneri gerekir.

### 7.4 Kökler

$i_L(t) = Ae^{st}$ önerilir. Türevleri $sAe^{st}$ ve $s^2Ae^{st}$'dir. Yerine konup ortak parantez alınırsa:

$$Ae^{st}\left(s^2 + \frac{1}{RC}s + \frac{1}{LC}\right) = 0$$

Kök formülü uygulanıp 2 içeri dağıtılır:

$$s_{1,2} = -\frac{1}{2RC} \pm \sqrt{\left(\frac{1}{2RC}\right)^2 - \left(\frac{1}{\sqrt{LC}}\right)^2}$$

Son terim bilerek bu biçimde yazıldı, önceki formata benzesin diye. Böylece paralel devre için:

$$\alpha = \frac{1}{2RC}, \qquad \omega_0 = \frac{1}{\sqrt{LC}}$$

### 7.5 Üç Durum

Çözüm biçimleri seri devredekilerin aynısıdır, tek fark bunların $i_L(t)$ için geçerli olmasıdır:

- **$\alpha > \omega_0$:** İki gerçek ve farklı kök vardır, $i_L(t) = A_1e^{s_1t} + A_2e^{s_2t}$. Zaman ötelemesi varsa $\Delta t = t - t_0$ yazılır.
- **$\alpha = \omega_0$:** $s_1 = s_2 = -\alpha$. İki çözüm gerektiği için ikincisi $t$ ile çarpılarak önerilir: $i_L(t) = e^{-\alpha t}(A_1 + A_2t)$.
- **$\alpha < \omega_0$:** Eşlenik karmaşık kökler vardır: $i_L(t) = e^{-\alpha t}(B_1\cos\omega_dt + B_2\sin\omega_dt)$. Eşdeğer olarak $e^{-\alpha t}B\cos(\omega_dt + \phi)$ de yazılır. Bilinmeyenler $B_1$, $B_2$ ya da $B$, $\phi$ olmak üzere yine ikidir. Üstel azalan zarf içinde sönen bir salınım elde edilir.

Hoca $R = 0$ için de seri devredekinin aynısını söyledi: $\alpha$ sıfır olur, işaret hiç sönmez, ama pratikte $R$ sıfır olamaz. Bu ifadenin düzeltmesi aşağıdaki nottadır.

> **Ders sonrası not:** Hoca $\alpha > \omega_0$ koşulunu okurken "$1/\sqrt{RC}$'den büyükse" dedi; doğrusu $1/\sqrt{LC}$'dir. Hoca paralel devrede de "$R$ sıfırsa $\alpha$ sıfır olur" dedi; bu yalnız seri devrede doğrudur. Paralel devrede $\alpha = 1/(2RC)$ olduğu için $R$ küçüldükçe $\alpha$ büyür, $R$ büyüdükçe sıfıra yaklaşır (python ile hesaplandı). Yani paralel devrede sönmeyen salınım $R \to \infty$, yani direnç kolunun açık devre olması durumudur.

### 7.6 Diğer Büyüklükler

$i_L$ bulunduktan sonra:

- $L$ ile türevi alınır: $v_L = L\,di_L/dt$. Elemanlar paralel olduğundan bu aynı zamanda $v_C$ ve $v_R$'dir.
- Bu gerilimin türevi alınıp $C$ ile çarpılır: $i_C = C\,dv/dt$.
- Gerilim $R$'ye bölünür: $i_R = v/R$.

> **Ek bilgi (derste anlatılmadı):** Süreklilik zorunluluğu kapasitenin gerilimi ve endüktansın akımı içindir, $i_C$ için değildir. Kaynaksız paralel devrede $i_C(t_0^-) = 0$ iken, düğüm denkleminden $i_C(t_0^+) = -I_s$ çıkar (python ile hesaplandı). Bu yüzden katsayı bulmada $t_0$ koşulu olarak $i_L$ ve $v_C$ kullanılır. Seri devrede ise $i_C = i_L$ olduğundan $i_C(t_0^+) = i_L(t_0^+)$'dır ve seri örnekteki $i_C(0) = 0$ koşulu bu yolla geçerlidir.

> **Ders sonrası not:** Aynı devre değerleri için ($R = 2$ kΩ, $L = 10$ µH, $C = 3$ µF) python ile hesaplandı: $\alpha = 1/(2RC) \approx 83.33$ s⁻¹, $\omega_d \approx 1.826 \times 10^5$ rad/s (yaklaşık 29.06 kHz). $\alpha < \omega_0$ olduğu için devre az sönümlüdür. Oysa aynı değerler seri bağlandığında aşırı sönümlüydü. $i_L(0) = I_s$ ve $v_C(0) = 0$ koşullarıyla (ara adım eklendi) $i_L(t) = I_se^{-83.33t}\left(\cos\omega_dt + 4.56 \times 10^{-4}\sin\omega_dt\right)$ bulunur. Zarfın zaman sabiti 12 ms'dir.

## 8. Kaynaksız Devrelerin Özeti

Hoca kaynaksız devreler için adımları toparladı: Eksi sonsuzdan $t_0^-$ anına kadar bağlı DC kaynak başlangıç koşullarını oluşturur. Endüktans ve kapasitenin yerine sırasıyla kısa ve açık devre konarak $v_C$, $v_L$, $i_C$ ve $i_L$ bulunur. $i_L(t_0^-) = i_L(t_0^+)$ ve $v_C(t_0^-) = v_C(t_0^+)$ kullanılır. Kaynak kalktıktan sonra devrenin geri kalanı için seri devrede gerilimler kanunuyla $v_C$, paralel devrede akımlar kanunuyla $i_L$ cinsinden denklem kurulur. $t \to \infty$'da bütün değerler asimptotik olarak sıfıra düşer.

| Durum | Koşul | Cevap |
|---|---|---|
| Aşırı sönümlü | $\alpha > \omega_0$ | $A_1e^{s_1t} + A_2e^{s_2t}$, $s_{1,2} = -\alpha \pm \sqrt{\alpha^2 - \omega_0^2}$ |
| Kritik sönümlü | $\alpha = \omega_0$ | $e^{-\alpha t}(A_1t + A_2)$ |
| Az sönümlü | $\alpha < \omega_0$ | $e^{-\alpha t}(B_1\cos\omega_dt + B_2\sin\omega_dt)$, $\omega_d = \sqrt{\omega_0^2 - \alpha^2}$ |

Seri devrede $\alpha = R/(2L)$ ve cevap $v_C(t)$'dir. Paralel devrede $\alpha = 1/(2RC)$ ve cevap $i_L(t)$'dir. İkisinde de $\omega_0 = 1/\sqrt{LC}$'dir.

## 9. Basamak Cevaplı Seri RLC Devresi

### 9.1 Kaynaksız Durumdan Farkı

Bu kısımda $t_0$ anında devreye DC bir kaynak bağlanır ve sonra devrede kalır. Kaynaksız devrelerde ikinci dereceden denklem sıfıra eşit çıkıyordu, çünkü $t$ sonsuza giderken devrede kaynak yoktu. Basamak cevabında ise denklem bir sabite eşit çıkar. Matematikte karşılaşılan durum, zorlanmış bir diferansiyel denklemin çözümüdür. İşlem sırası şöyledir:

1. Denklem sıfıra eşitlenip homojen çözüm (natural response, doğal cevap) bulunur. İkinci dereceden denklem olduğu için buradan iki terim gelir. Kökler ayrık gerçek, katlı ya da eşlenik karmaşık olabilir.
2. Sağ taraf neyse o cinsten bir zorlanmış çözüm önerilir. Sabit için sabit önerilir. Buradan üçüncü bir terim gelir.
3. Genel çözüm üç terimin toplamıdır. Katsayılar başlangıç koşullarıyla bulunur.

Hoca, başlangıç değerlerini genel olarak $v_C(t_0^-)$ ve $i_L(t_0^-)$ diye yazmasının sebebini de söyledi: Başlangıç koşullarını oluşturan iki farklı kaynak olabilir, $t_0$'da bunlardan biri daha devreye girmiş olabilir. Yani başlangıç değeri her zaman sıfır olmak zorunda değildir.

### 9.2 Uç Durumlar

Seri devrede kaynak $t_0$ anında devreye girer. $t_0$'dan önce kaynak değeri sıfırdır, bu yüzden:

$$i_L(t_0^-) = 0, \qquad v_C(t_0^-) = 0, \qquad v_L(t_0^-) = 0, \qquad i_C(t_0^-) = 0$$

$t \to \infty$'da kaynak devrededir, endüktans kısa devre, kapasite açık devredir:

$$v_C(\infty) = V_s, \qquad i_L(\infty) = 0$$

Hoca önce $i_L(\infty) = V_s/R$ dedi, sonra kapasite açık devre olduğu için akım akmayacağını hatırlayıp düzeltti.

### 9.3 Diferansiyel Denklem

Seri devre olduğu için yine her şey $v_C$ cinsinden yazılır. Çevre denklemi:

$$-V_s + v_R + v_L + v_C = 0$$

Akım yine $i = C\,dv_C/dt$'dir. Kaynaksız durumdaki düzenleme aynen yapılır, $LC$'ye bölünürken $V_s$ de bölünür:

$$\frac{d^2 v_C}{dt^2} + \frac{R}{L}\frac{dv_C}{dt} + \frac{1}{LC}v_C = \frac{V_s}{LC}$$

### 9.4 Homojen ve Zorlanmış Çözüm

**Homojen çözüm.** Sağ taraf sıfır alınır. Bu, kaynaksız seri devre çözümünün aynısıdır:

$$v_{C,h}(t) = A_1e^{s_1t} + A_2e^{s_2t}, \qquad s_{1,2} = -\alpha \pm \sqrt{\alpha^2 - \omega_0^2}, \quad \alpha = \frac{R}{2L}, \quad \omega_0 = \frac{1}{\sqrt{LC}}$$

**Zorlanmış çözüm.** Sağ taraf sabit olduğu için sabit önerilir: $v_{C3}(t) = A$. Sabitin birinci ve ikinci türevi sıfırdır. Geriye şu kalır:

$$\frac{A}{LC} = \frac{V_s}{LC} \quad\Rightarrow\quad A = V_s$$

Hoca önce denklemin sağ tarafını $V_s$ aldığı için $A = V_sLC$ buldu, sağ tarafın $V_s/LC$ olduğunu görüp düzeltti.

**Genel çözüm.**

$$v_C(t) = A_1e^{s_1t} + A_2e^{s_2t} + V_s$$

### 9.5 Katsayılar

Hoca önce koşulları denerken bir yanlış yola girdi, öğretici olduğu için kısaca aktarılır. Türevde $t$ yerine sonsuz koyduğunda üstel terimler sıfıra gitti ve bir şey bulunamadı. Çünkü $s_1$ ve $s_2$ negatif olduğundan $t \to \infty$'da üstel terimler söner, geriye $V_s$ kalır. Bu, $v_C(\infty) = V_s$ ve $i_L(\infty) = 0$ koşullarının kendiliğinden sağlandığını gösterir, ama katsayılar hakkında bilgi vermez. Katsayılar başlangıç koşullarından bulunur:

$$v_C(0) = 0 \quad\Rightarrow\quad A_1 + A_2 + V_s = 0$$

$$i_L(0) = C\,v_C'(0) = 0 \quad\Rightarrow\quad s_1A_1 + s_2A_2 = 0$$

İki denklem, iki bilinmeyen. Çözüm (ara adım eklendi):

$$A_1 = \frac{s_2}{s_1 - s_2}V_s, \qquad A_2 = -\frac{s_1}{s_1 - s_2}V_s$$

> **Ders sonrası not:** Hoca ikinci denklemi söylerken "$A_1s_1 + A_2s_2 + V_s = 0$" dedi; doğrusu $s_1A_1 + s_2A_2 = 0$'dır. Sabit terimin türevi sıfırdır, nitekim hoca bir önceki anlatımda da bunu söylemişti ve paralel devrede denklemi doğru yazdı. Yukarıdaki $A_1$ ve $A_2$ formüllerinin iki koşulu sağladığı python ile hesaplandı.

### 9.6 Üç Durum ve Diğer Büyüklükler

Köklerin durumu yine homojen çözümün karakteristik denkleminden belirlenir:

$$s^2 + \frac{R}{L}s + \frac{1}{LC} = 0$$

| Durum | Koşul | Genel çözüm |
|---|---|---|
| Aşırı sönümlü | $\alpha > \omega_0$ | $v_C(t) = A_1e^{s_1t} + A_2e^{s_2t} + V_s$ |
| Kritik sönümlü | $\alpha = \omega_0$ | $v_C(t) = e^{-\alpha t}(A_1 + A_2t) + V_s$ |
| Az sönümlü | $\alpha < \omega_0$ | $v_C(t) = e^{-\alpha t}(B_1\cos\omega_dt + B_2\sin\omega_dt) + V_s$ |

Bilinmeyenler iki tanedir: $A_1$, $A_2$ ya da $B_1$, $B_2$. Hepsi $v_C(t_0)$ ve $i_L(t_0)$ ile bulunur.

Az sönümlü durum için hoca şunu da ekledi: Fiziksel dünyada karmaşık sayının bir karşılığı yoktur. Çözüm açısından ise matematiksel bir karşılığı vardır, çünkü $B_1$ ve $B_2$ katsayılarını verilen başlangıç koşullarıyla bulmayı sağlar.

<!-- BELİRSİZ: Karmaşık sayı yorumundan hemen önce altyazıda bir soru duyulmuyor; hocanın bir soruya cevap verip vermediği net değil. -->

Diğer büyüklükler kaynaksız durumdaki gibidir. $v_C$ biliniyorsa türevinin $C$ ile çarpımı $i_C$'yi verir. Seri devrede $i_L = i_R = i_C$'dir ve akımı belirleyen kapasitedeki gerilim değişimidir. Endüktans akımının türevi $L$ ile çarpılarak $v_L$, ana kol akımı $R$ ile çarpılarak $v_R$ bulunur.

## 10. Başlangıç Koşulları Genel Çözüme Konur

Hoca buradaki noktanın üzerinde en çok durdu. Diferansiyel denklem birinci ya da ikinci dereceden olsun, bir fonksiyona eşitse bu zorlanmış çözüm demektir ve çözüm iki koldan gider: sıfıra eşit hâlinin homojen çözümü ve sağ taraf cinsinden önerilen zorlanmış çözüm. Sonra katsayılar bulunur.

> **Hocanın vurgusu:** $A_1$ ve $A_2$ katsayıları, başlangıç koşulları **genel çözüme** (homojen artı zorlanmış) konarak bulunur. Koşulları yalnız homojen çözüme koyarsanız zorlanmış çözümü dışarıda bırakmış olursunuz ve sonuç hatalı çıkar. Bu çok önemli bir farktır, lütfen atlamayın.

Kaynaksız devrelerde ise denklemin genel çözümü zaten homojen çözümdür, bu yüzden koşullar doğrudan ona konmuştu.

## 11. Basamak Cevaplı Paralel RLC Devresi

### 11.1 Devre ve Uç Durumlar

Seri devredeki gibi, denklem $i_L$ cinsinden yazılır ve bir sabite eşit çıkar. Homojen kısım sıfıra eşitlenerek çözülür, zorlanmış kısım için ise önerilen çözüm eklenir.

$t_0^-$ anına kadar anahtar kapalıdır. Bu, akım kaynağının paralelinde bir kısa devre demektir, kaynak akımı bu yol üzerinden akar. Yani devreye bakıldığında kaynak yok gibidir. Endüktansın yerine kısa, kapasitenin yerine açık devre konduğunda:

$$i_L(t_0^-) = v_L(t_0^-) = i_C(t_0^-) = v_C(t_0^-) = 0$$

Anahtar açıldıktan sonra $I_s$ devreye girer ve $t \to \infty$'da endüktansın kısa devresi üzerinden akar:

$$i_L(\infty) = I_s, \qquad v_L(\infty) = 0, \qquad v_C(\infty) = 0, \qquad i_C(\infty) = 0$$

### 11.2 Diferansiyel Denklem

Kaynaksız devreden tek fark, $I_s$'nin düğüme girmesi, diğer akımların düğümden çıkmasıdır. Düğüm denkleminin sağ tarafı sıfır yerine $I_s$ olur. $LC$'ye bölününce:

$$\frac{d^2 i_L}{dt^2} + \frac{1}{RC}\frac{di_L}{dt} + \frac{1}{LC}i_L = \frac{I_s}{LC}$$

### 11.3 Homojen ve Zorlanmış Çözüm

Homojen kısım sıfıra eşitlenir ve iki üstel terim verir:

$$i_{L1}(t) = A_1e^{s_1t}, \qquad i_{L2}(t) = A_2e^{s_2t}$$

Zorlanmış kısım için sabit önerilir: $i_{L3}(t) = A$. Birinci ve ikinci türevler sıfırdır:

$$\frac{A}{LC} = \frac{I_s}{LC} \quad\Rightarrow\quad A = I_s$$

Genel çözüm:

$$i_L(t) = A_1e^{s_1t} + A_2e^{s_2t} + I_s$$

$s_1$ ve $s_2$ şu denklemin kökleridir:

$$\left(s^2 + \frac{1}{RC}s + \frac{1}{LC}\right)Ae^{st} = 0$$

$A$ ve $s$'nin sıfır olması istenmediği için parantez sıfıra eşitlenir. Kökler ayrık gerçek, katlı ya da karmaşık eşlenik olabilir.

### 11.4 Katsayılar

Başlangıç koşulları $i_L(t_0) = 0$ ve $v_C(t_0) = 0$'dır. Paralel devrede $v_C = v_L = L\,di_L/dt$ olduğu için ikinci koşul türevle ilgili bilgiyi verir. Koşullar, hoca yeniden hatırlatarak, genel çözüme konur. $t = 0$ için:

$$i_L(0) = 0 \quad\Rightarrow\quad A_1 + A_2 + I_s = 0$$

$$v_C(0) = L\,i_L'(0) = 0 \quad\Rightarrow\quad s_1A_1 + s_2A_2 = 0$$

Türev alınınca sabit $I_s$ gider. İki denklem iki bilinmeyen ile katsayılar bulunur. Kaynak $t_0$ anında devreye giriyorsa $t$ yerine $t - t_0$ yazılır.

### 11.5 Üç Durum ve Diğer Büyüklükler

Kökün içi sıfır olursa ikinci terim $t$ ile çarpılır. Kökün içi negatif olursa iki serbestlik dereceli kosinüs ve sinüs toplamı kullanılır. $\alpha = 1/(2RC)$ pozitif olduğundan $e^{-\alpha t}$ azalan bir zarftır ve çözüm bu zarf içinde azalan bir sinüzoidal olur:

| Durum | Koşul | Genel çözüm |
|---|---|---|
| Aşırı sönümlü | $\alpha > \omega_0$ | $i_L(t) = A_1e^{s_1t} + A_2e^{s_2t} + I_s$ |
| Kritik sönümlü | $\alpha = \omega_0$ | $i_L(t) = e^{-\alpha t}(A_1 + A_2t) + I_s$ |
| Az sönümlü | $\alpha < \omega_0$ | $i_L(t) = e^{-\alpha t}(B_1\cos\omega_dt + B_2\sin\omega_dt) + I_s$ |

Diğer büyüklükler yine $i_L$'den çıkar: Türevi $L$ ile çarpılarak $v_L$ bulunur. Elemanlar paralel olduğu için bütün gerilimler bellidir. Bu gerilimin türevi $C$ ile çarpılarak $i_C$, gerilim $R$'ye bölünerek $i_R$ bulunur.

> **Ders sonrası not:** Hoca "üç farklı çözümde de üç bilinmeyen var" dedi; üç **terim** vardır, bilinmeyen katsayı ikidir ($A_1$, $A_2$ ya da $B_1$, $B_2$). Üçüncü terim olan $V_s$ ya da $I_s$ bilinir. Bunu kendisi de önceden "iki tane bilinmeyen" diye söylemişti.

> **Ders sonrası not:** Slayttaki değerlerle ($R = 2$ kΩ, $L = 10$ µH, $C = 3$ µF) devre az sönümlüdür ve (ara adım eklendi) $i_L(t) = I_s\left[1 - e^{-83.33t}\left(\cos\omega_dt + 4.56 \times 10^{-4}\sin\omega_dt\right)\right]$ bulunur, $\omega_d \approx 1.826 \times 10^5$ rad/s. Bu ifadenin denklemi ve $i_L(0) = 0$, $i_L'(0) = 0$ koşullarını sağladığı python ile hesaplandı. Derste bu sonuç yazılmadı.

### 11.6 Seri ve Paralel Başlangıç Koşullarının Özeti

İki başlangıç koşulu vardır: ilgilenilen değişkenin $t_0$'daki değeri ve türevinin $t_0$'daki değeri.

- **Seri RLC:** İlgilenilen değişken $v_C$'dir. Türevi akımla ilişkilidir, bu da $i_L$'yi belirler. Kullanılan koşullar $v_C(t_0)$ ve $i_L(t_0)$'dır.
- **Paralel RLC:** İlgilenilen değişken $i_L$'dir. Türevi $v_L$ ile, paralel devre olduğu için de $v_C$ ile ilişkilidir. Kullanılan koşullar $i_L(t_0)$ ve $v_C(t_0)$'dır.

Bu koşullar kaynaklı devrede genel çözüme, kaynaksız devrede ise zaten genel çözüm olan homojen çözüme konur.

## 12. Sinüzoidal Kaynak ve Fazöre Geçiş

Zorlayıcı kaynak sinüzoidal olsaydı denklem yine ikinci dereceden olur, sağ taraf zamana bağlı sinüslü bir fonksiyon olurdu. Bu, gelecek haftanın konusu olan fazör gösteriminin konusudur. Fazör yaklaşımının temel noktası şudur: Geçici hâller bittikten sonraki durum incelenir. Geçici hâller değerlendirilmez. Sinüzoidal kaynağın baskın olduğu bu duruma sürekli sinüzoidal hâl denir, fazör yaklaşımı sürekli sinüzoidal hâl analizi olarak kullanılır. Hoca, benzer devrelerin fazör üzerinden daha basit çözüleceğini söyledi. Laplace dönüşümüne ise zaman açısından yetişilemeyebileceğini ekledi.

## 13. Pratikte Soru Nasıl Çözülür?

Hoca ders sonunda bu kadar diferansiyel denklemin arkada yatan teori ve hesaplama olduğunu, öğrencilerin pratikte yapacağı işin ise şu adımlar olduğunu söyledi:

1. Devre seri mi, paralel mi, belirlenir.
2. Kaynaksız mı, basamak cevaplı mı, belirlenir.
3. Homojen çözümün köklerine bakılır: aşırı, kritik ya da az sönümlü.
4. Bunlara göre hangi genel çözümün kullanılacağı seçilir.
5. Başlangıç koşulları yerine konup bilinmeyenler bulunur.

Hoca, parça parça verilen tabloların birleştirilip referans olarak yanında bulundurulabileceğini söyledi. Devre elemanlarının ikilik (dualite) konusuna ise girmedi, öğrencilerin bakmasını istedi.

> **Ek bilgi (derste anlatılmadı):** Dualite, dersteki iki denklemde görülebilir. Seri denklemde $R \to 1/R$, $L \to C$, $C \to L$ değişimi yapılırsa $R/L$ katsayısı $1/(RC)$'ye, $1/(LC)$ yine $1/(LC)$'ye, $\alpha = R/(2L)$ da $1/(2RC)$'ye dönüşür (python ile hesaplandı). Bu eşlemede seri devredeki $v_C$ ve $V_s$, paralel devredeki $i_L$ ve $I_s$'ye karşılık gelir.

> **Hocanın vurgusu:** RL, RC ve RLC devreleri için çözümlere dikkat edin, bunlarla ilgili pratik yapın. Hem zaman domeninde hem fazör domeninde bu tür sorularla karşılaşacaksınız.

## Dersin Toparlaması

Bu derste ikinci dereceden devrelerin çözüm yöntemi kuruldu. Önce DC analizle uç değerlerin bulunuşu ve kapasite gerilimi ile endüktans akımının sürekliliği hatırlatıldı. Sonra kaynaksız seri devre için $v_C$, kaynaksız paralel devre için $i_L$ cinsinden ikinci dereceden denklem yazıldı. Üstel öneri, karakteristik denkleme ve iki köke götürdü. $\alpha$ ile $\omega_0$'ın karşılaştırılması aşırı, kritik ve az sönümlü olmak üzere üç çözüm biçimini verdi. Seride $\alpha = R/(2L)$, paralelde $\alpha = 1/(2RC)$, ikisinde de $\omega_0 = 1/\sqrt{LC}$'dir.

Basamak cevabında sağ taraf sabit olduğu için homojen çözüme $V_s$ ya da $I_s$ eklendi ve başlangıç koşullarının bu genel çözüme konması gerektiği vurgulandı. Gelecek hafta sürekli sinüzoidal hâl analizi için fazör gösterimine geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
