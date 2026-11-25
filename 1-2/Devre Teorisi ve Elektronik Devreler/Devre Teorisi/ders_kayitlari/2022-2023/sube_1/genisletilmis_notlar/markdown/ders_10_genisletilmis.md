# Ders 10 Genişletilmiş Notu: Kaynaksız ve Kaynaklı RLC Devreleri, Sönüm Durumları ve Karmaşık Sayılar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Giriş: Kondansatörün Frekansa Göre Davranışı
- 2. İkinci Dereceden Devrelerde Başlangıç ve Sınır Koşulları
- 3. Kaynaksız Seri RLC Devresi
- 4. Karakteristik Kökler, Doğal ve Zorlanmış Çözüm
- 5. Katsayıların Başlangıç Koşullarından Bulunması
- 6. Üç Sönüm Durumu
- 7. Kaynaksız Paralel RLC Devresi
- 8. Kaynaklı Seri RLC Devresi (Basamak Cevabı)
- 9. Kaynaklı Paralel RLC Devresi
- 10. Frekans Uzayına Geçiş Fikri
- 11. Karmaşık Sayılar
- Örnek Sorular
- Dersin Toparlaması

## 1. Giriş: Kondansatörün Frekansa Göre Davranışı

Ders, laboratuvar çalışmasıyla ilgili bir soru üzerine kısa bir kavramsal açıklamayla başladı. Konu bir filtrenin karakteristiğiydi. Hoca bunun derste görülmemiş bir konu olmadığını, bilinenlerden çıkarılabileceğini şöyle anlattı.

DC şart, frekansın sıfır olduğu durumdur. DC şartlarda kondansatör açık devre gibi çalışır. Frekans yükseldikçe kondansatörün davranışı değişir; frekans sonsuza giderken kondansatör kısa devre gibi çalışır. Çıkış gerilimi kondansatör üzerinden alınan bir devrede frekans sonsuza giderken kondansatör kısa devre olduğu için çıkış sıfıra düşer. Girişte hangi sinyal olursa olsun çıkış sıfırdır; yani devre yüksek frekansları geçirmez. Frekans sıfırken ise kondansatör açık devredir ve çıkışta belirli bir gerilim oluşur.

Bu iki uç durumu (frekans sıfır ve frekans sonsuz) ayrı ayrı çözmek, bir filtrenin çalışma mantığını kabaca ortaya çıkarır. Filtrenin frekans cevabı da aslında bu analizin genişletilmesidir.

> **Ek bilgi (derste anlatılmadı):** Çıkışı kondansatör üzerinden alınan seri RC devresi alçak geçiren filtredir. Kondansatörün empedansı $Z_C = 1/(j\omega C)$ olduğundan $\omega \to 0$ iken empedans sonsuza (açık devre), $\omega \to \infty$ iken sıfıra (kısa devre) gider. Hocanın anlattığı iki uç durum bu bağıntının sonucudur.

## 2. İkinci Dereceden Devrelerde Başlangıç ve Sınır Koşulları

### 2.1 Neden iki başlangıç koşulu gerekir

Önceki derste başlanan ikinci dereceden devrelerde (RLC devreleri) ilgilenilen bir elemanın akım ya da gerilimi bulunmak istendiğinde ikinci dereceden bir diferansiyel denklem çıkar. Bu denklemin genel çözümünde iki bilinmeyen katsayı vardır. Bu yüzden ikinci dereceden devrelerde **en az iki başlangıç koşulu** gerekir.

Bu koşullar enerji depolayan elemanların temel özelliklerinden kurulur:

- **Kondansatör:** Gerilim süreklidir. Devrede bir durum değişimi olduğunda değişimin hemen öncesi ve hemen sonrasındaki kondansatör gerilimi aynıdır. Bu yüzden değişimden önceki kondansatör gerilimi hesaplanarak ilk koşul elde edilir. İkinci koşul, kondansatör geriliminin türevinin kondansatör akımıyla ilişkisinden ($i_C = C\,dv_C/dt$) ve bu akımın devredeki diğer akımlarla ilişkisinden gelir.
- **Bobin (endüktans):** Akım süreklidir. Değişimin hemen öncesindeki bobin akımı hesaplanır ve değişimden hemen sonra da aynı kabul edilir. İkinci koşul, bobin akımının türevinin bobin gerilimini vermesinden ($v_L = L\,di_L/dt$) ve bu gerilimin diğer elemanlarla ilişkisinden gelir.

### 2.2 Üç zaman bölgesi

Bu derste ele alınan devrelerde DC kaynaklar açılıp kapatılır; yani bir tür basamak cevabı (birim basamak fonksiyonu cevabı) incelenir. Üç durum ayrı ayrı düşünülür:

- Değişim olmadan önce: devre uzun süre belirli bir DC şartta çalışmıştır.
- Geçici hal: değişimden sonra yaklaşık $5\tau$ süresine kadar devrenin davranışı.
- Sürekli hal: geçici haller bittikten sonra $t \to \infty$'a giden süreç.

### 2.3 Başlangıç koşulunu hesaplama adımları

Slayttaki adımlar şöyledir (ekrandan, 00:10:00):

- Devreyi $t < t_0$ için yeniden çiz.
- $t < t_0$ için bütün gerilim ve akım kaynaklarının değerini belirle.
- Enerji depolayan elemanların yerine uygun eşdeğerleri koy:
  - Bütün kondansatörlerin yerine açık devre ($\infty\,\Omega$ direnç) koy. Bu yüzden $I_C(t < t_0) = 0$ A.
  - Bütün bobinlerin yerine kısa devre ($0\,\Omega$ direnç) koy. Bu yüzden $V_L(t < t_0) = 0$ V.
- $V_C(t < t_0)$ ve $I_L(t < t_0)$ değerlerini hesapla.

### 2.4 İntegral form yerine diferansiyel form

Hoca, diferansiyel denklemlerin integral formda ya da türevli (diferansiyel) formda yazılabileceğini hatırlattı. İntegral formda yazınca integralden gelen bir sabit ortaya çıkar ve onu belirlemek gerekir. Bununla uğraşmamak için seri ve paralel kaynaksız devrelerde mümkünse diferansiyel form kullanılır. Önceki derste yapılan çözüm integral formdaydı; aynı sonucu verir ama daha dolambaçlıdır.

Hoca ayrıca, bu dersin kapsamında diferansiyel denklemlerin ayrıntılı çözümüne girilmeyeceğini söyledi. Devrenin çalışma mantığına göre sınır koşullar belirlenecek ve hangi koşul gerçekleşiyorsa ona uygun hazır bir çözüm önerisi seçilecektir. Bu, indirgenmiş bir çözüm yoludur; çünkü tam çözüm diferansiyel denklemler bilgisi gerektirir.

## 3. Kaynaksız Seri RLC Devresi

### 3.1 Devre ve anahtar yorumu

Seri RLC devresinde bir gerilim kaynağı vardır. Kaynak uzun süre devrededir ve $t_0$ anında devreden çıkarılır. Hoca bunu fiziksel olarak şöyle anlattı: kaynakla birlikte kapalı bir anahtar vardır, $t_0$ anında biri gelip anahtarı açar. Bu durum, kaynağın birim basamak fonksiyonuyla (u(t)) tanımlanmasına eşdeğerdir. Kaynak devreden kalkınca yerine kısa devre konur.

Kaynak uzun süre devrede kaldığı için kondansatör ve bobin için başlangıç koşulları oluşur. Kaynak kalkınca kondansatörde depolanmış enerji bobin ve direnç üzerinden harcanır, yük boşalır ve $t \to \infty$'da bütün gerilim ve akımlar sıfıra oturur.

### 3.2 Başlangıç ve son durum

$t_0^-$ anında devre uzun süre DC şartlarda çalışmıştır. Kondansatör açık devre gibidir, akım akmaz. Slayttaki değerler (ekrandan, 00:15:00):

- $i(t_0^-) = i_L(t_0^-) = 0$ A ve $v_C(t_0^-) = V_s$
- $v_L(t_0^-) = 0$ V ve $i_C(t_0^-) = 0$ A
- Sürekli halde: $i(\infty) = i_L(\infty) = 0$ A, $v_C(\infty) = 0$ V, $v_L(\infty) = 0$ V, $i_C(\infty) = 0$ A

Yani $i_L$, $i_R$, $i_C$ başlangıçta sıfırdır; $v_R$ ve $v_L$ da akım olmadığı için sıfırdır; yalnız $v_C = V_s$'dir.

> **Ders sonrası not:** Bu slaytta kaynak için "$t < t_0$ iken 0 V, $t > t_0$ iken $V_s$" yazıyor; ama verilen değerler ($v_C(t_0^-) = V_s$, $v_C(\infty) = 0$) ve hocanın anlatımı, kaynağın $t_0$'a kadar $V_s$ olup $t_0$'da devreden çıkarıldığı kaynaksız duruma uyar. Slayt metnindeki 0 ve $V_s$ yer değiştirmiş görünüyor; doğrusu büyük olasılıkla "$t < t_0$ iken $V_s$, $t > t_0$ iken 0".

### 3.3 Diferansiyel denklemin kurulması

Çevre üzerinden ilerlenir: $v_R + v_L + v_C = 0$.

- $v_C$ doğrudan yazılır.
- $v_L$ için: akı $\phi = L\,i$ ve $\phi$ gerilimin integrali olduğundan, iki tarafın türevi alınınca $v_L = L\,\frac{di_L}{dt}$ olur.
- Tek kol olduğu için $i_L = i_R = i_C = i$.
- $v_R = R\,i$.

Akım, kondansatör cinsinden $i = C\,\frac{dv_C}{dt}$ yazılır. Bunun türevi alınınca ($C$ sabit olduğu için dışarı çıkar) $\frac{di}{dt} = C\,\frac{d^2v_C}{dt^2}$ olur. Yerine konunca:

$$LC\,\frac{d^2v_C}{dt^2} + RC\,\frac{dv_C}{dt} + v_C = 0$$

En yüksek dereceli türevin katsayısı 1 olsun diye her taraf $LC$'ye bölünür:

$$\frac{d^2v_C}{dt^2} + \frac{R}{L}\,\frac{dv_C}{dt} + \frac{1}{LC}\,v_C = 0$$

Bu denklem $t_0$ anındaki değişimden sonra geçerlidir.

### 3.4 Önerilen çözüm

Öyle bir fonksiyon aranır ki ikinci türevi, birinci türevi ve kendisi katsayılarla çarpılıp toplandığında sıfır versin; yani türevleri kendisiyle aynı biçimde olsun. Bu fonksiyon üsteldir. Önerilen çözüm (ekrandan, 00:20:00):

$$v_C(t) = A\,e^{s\Delta t}$$

Bir fonksiyon diferansiyel denklemin çözümüyse, onun bir sabitle çarpılmışı da çözümdür; bu yüzden en genel biçim $A\,e^{s\Delta t}$'dir. Yerine konunca:

$$As^2e^{s\Delta t} + \frac{AR}{L}\,s\,e^{s\Delta t} + \frac{A}{LC}\,e^{s\Delta t} = 0$$

$$Ae^{s\Delta t}\left(s^2 + \frac{R}{L}s + \frac{1}{LC}\right) = 0$$

$Ae^{s\Delta t} = 0$ olması aranan çözüm değildir; o durumda $v_C$ hep sıfırdır ve çözmeye gerek kalmaz. Bu yüzden parantezin sıfır olması gerekir:

$$s^2 + \frac{R}{L}s + \frac{1}{LC} = 0$$

Bu, $s$'ye göre ikinci dereceden bir denklemdir (karakteristik denklem).

## 4. Karakteristik Kökler, Doğal ve Zorlanmış Çözüm

### 4.1 Köklerin olası durumları

İkinci dereceden denklemin kökleri için üç durum vardır:

- $s_1$ ve $s_2$ birbirinden farklı iki gerçek kök olabilir.
- Kökler aynı (çakışık) olabilir; $(x - a)^2 = 0$ gibi.
- Kökler eşlenik karmaşık sayılar olabilir.

Her biri için ayrı bir çözüm biçimi gerekir.

### 4.2 Değişken dönüşümü: $\alpha$ ve $\omega_0$

$as^2 + bs + c = 0$ denkleminin kökleri $s_{1,2} = \frac{-b \pm \sqrt{b^2 - 4ac}}{2a}$'dır; burada $a = 1$. Şu tanımlar yapılır (ekrandan, 00:25:00):

$$\alpha = \frac{R}{2L}, \qquad \omega_0 = \frac{1}{\sqrt{LC}}$$

Bunlarla denklem $s^2 + 2\alpha s + \omega_0^2 = 0$ olur. Kök formülünde $\frac{-2\alpha \pm \sqrt{4\alpha^2 - 4\omega_0^2}}{2}$ ifadesinden 2'ler sadeleşir:

$$s_1 = -\alpha + \sqrt{\alpha^2 - \omega_0^2}, \qquad s_2 = -\alpha - \sqrt{\alpha^2 - \omega_0^2}$$

### 4.3 Doğal çözüm ve zorlanmış çözüm

Hoca slayta şunu not etti: bu kökler, devrede enerji depolayan elemanların başlangıç enerjisi varken, yani başlangıç durumu sıfırdan farklıyken geçerlidir (ekrandan, 00:25:00).

- Devrede başka kaynak yoksa ve yalnız başlangıç koşullarından gelen bir geçici hal varsa bu çözüme **doğal çözüm** (natural solution) denir.
- $t \to \infty$ iken devrede bir kaynak bulunuyorsa, kaynaktan gelen çözüme **zorlanmış çözüm** (forced solution) denir.
- Hoca, ikisini birlikte içeren en genel çözüme "homojen çözüm" dedi: $x(t) = x_f(t) + x_n(t)$.

> **Ek bilgi (derste anlatılmadı):** Diferansiyel denklemler dilinde "homojen çözüm" genellikle sağ tarafı sıfır olan denklemin çözümü, yani doğal çözüm için kullanılır. Doğal ve zorlanmış çözümün toplamı çoğu kaynakta "tam çözüm" (complete response) diye anılır; slaytlardaki "Complete Solution" başlığı da bunu gösterir.

Şu an incelenen kaynaksız seri RLC devresinde yalnız doğal çözüm vardır.

### 4.4 Parametrelerin adları

Slayttaki adlar (ekrandan, 00:25:00):

- $s_1$ ve $s_2$: **doğal frekanslar**, birimi neper/saniye (Np/s). Devrenin doğal cevabıyla ilişkili oldukları için bu adı alırlar.
- $\omega_0$: **rezonans frekansı** ya da tam adıyla sönümsüz doğal frekans, birimi rad/s.
- $\alpha$: **neper frekansı** ya da **sönüm faktörü** (damping factor), birimi Np/s.

Hoca, rezonans frekansının şu durumda önem kazandığını söyledi: $t \to \infty$ iken devrede sinüzoidal bir kaynak varsa ve frekansı $\omega_0$'a yakınsa sinyal sönümlenmez, kuvvetlenerek devam eder.

> **Ders sonrası not:** Hoca rezonansta sinyalin "asla sönümlenmediğini, hatta kuvvetlenerek devam ettiğini" söyledi. Sınırsız büyüme büyük olasılıkla yalnız kayıpsız ($R = 0$) devre için geçerlidir. Direnç içeren bir devrede sürekli hal genliği sonludur; rezonans frekansında yalnız en büyük değerine ulaşır.

$\alpha$'nın sönüm faktörü adını almasının nedeni şudur: $R$ ve $L$ pozitif olduğu için $\alpha$ pozitiftir. Çözümde $e^{-\alpha t} = 1/e^{\alpha t}$ terimi bulunur; bu, zaman geçtikçe üstel olarak azalan bir zarf oluşturur.

### 4.5 Genel çözüm

İki kök çıktığı için ikisi de denklemi sağlar. $s_1$'li üstel bir sabitle çarpılınca da, $s_2$'li üstel bir sabitle çarpılınca da çözümdür. Bunların toplamı da çözümdür; çünkü türev işlemi doğrusaldır: $A_1$ paranteze alınan kısım kendi içinde sıfır verir, $A_2$ paranteze alınan kısım da sıfır verir, sıfır artı sıfır denklemi sağlar. Genel çözüm (ekrandan, 00:30:00):

$$v_{C1}(t) = A_1e^{s_1\Delta t}, \qquad v_{C2}(t) = A_2e^{s_2\Delta t}$$

$$v_C(t) = v_{C1}(t) + v_{C2}(t) = A_1e^{s_1\Delta t} + A_2e^{s_2\Delta t}$$

Burada $\Delta t = t - t_0$ bir değişken dönüşümüdür. Değişim $t = 0$'da oluyorsa $\Delta t = t$; $t_0$'da oluyorsa üstellerde $t - t_0$ kullanılmalıdır.

## 5. Katsayıların Başlangıç Koşullarından Bulunması

$s_1$ ve $s_2$, $R$, $L$, $C$ değerlerinden bulunur. $A_1$ ve $A_2$ ise başlangıç koşullarından bulunur. Slayttaki işlemler (ekrandan, 00:35:00):

**Birinci koşul (kondansatör gerilimi sürekli):**

$$v_C(t_0^-) = v_C(t_0^+) = v_{C1}(t_0^+) + v_{C2}(t_0^+) = V_s$$

$t = t_0$'da $\Delta t = 0$ ve $e^0 = 1$ olduğundan:

$$A_1e^{s_1(0)} + A_2e^{s_2(0)} = A_1 + A_2 = V_s$$

**İkinci koşul (bobin akımı başlangıçta sıfır):** $i_L(t_0^-) = 0$ biliniyor. Bobin akımı kondansatör akımına eşittir ($i_L = i_C$) ve $i_C = C\,dv_C/dt$'dir. Bu yüzden genel çözümün türevi alınır:

$$i_C(t_0) = C\,\frac{dv_C(t_0)}{dt} = C\,\frac{d}{dt}\left[v_{C1}(t_0) + v_{C2}(t_0)\right] = 0$$

Türev alınca $s_1$ ve $s_2$ öne gelir. $C \neq 0$ olduğundan türevin sıfır olması gerekir; $\Delta t = 0$'da üsteller 1 olur:

$$s_1A_1e^{s_1(0)} + s_2A_2e^{s_2(0)} = s_1A_1 + s_2A_2 = 0$$

İki bilinmeyen ve iki denklem vardır. Çözüm (ara adım eklendi):

$$A_1 = \frac{-s_2V_s}{s_1 - s_2}, \qquad A_2 = \frac{s_1V_s}{s_1 - s_2}$$

Bu ifadelerin iki denklemi de sağladığı python ile kontrol edildi. Böylece $v_C$ tam ve tanımlı biçimde bulunur: $s_1, s_2$ devre elemanlarından, $A_1, A_2$ başlangıç koşullarından gelir.

## 6. Üç Sönüm Durumu

### 6.1 Aşırı sönümlü durum ($\alpha > \omega_0$)

Kökün içi pozitiftir, iki farklı gerçek kök çıkar. $-\alpha$ ile başlandığı için ikisi de negatiftir. Çözüm iki ayrı üstelin toplamıdır:

$$v_C(t) = A_1e^{s_1\Delta t} + A_2e^{s_2\Delta t}$$

Bu duruma aşırı sönümlü (overdamped) denir. Hoca, aşırı sönümlü cevapta değerin hızla sıfıra oturmaya çalıştığını, ilk hareketin hızlı olduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** Seri devrede $\alpha > \omega_0$ koşulu $\frac{R^2}{4L^2} > \frac{1}{LC}$, yani $C > 4L/R^2$ demektir. Kritik sönüm $C = 4L/R^2$'de olur. Bu iki eşitsizlik, slayttaki az sönümlü koşul $C < 4L/R^2$'den aynı yolla çıkar.

### 6.2 Kritik sönümlü durum ($\alpha = \omega_0$)

Kök içi sıfır olur, $s_1 = s_2 = -\alpha$. Tek kök çıksa da çözüm tek terimli değildir; yine iki çözüm önerilir:

$$v_C(t) = A_1e^{s_1\Delta t} + A_2\,\Delta t\,e^{s_1\Delta t} = (A_1 + A_2\Delta t)\,e^{-\alpha\Delta t}$$

Hoca bunu şöyle açıkladı: üstel fonksiyon, türevleriyle aynı biçimdedir; üstelin $t$ ile çarpılmış hali de polinom bir çarpanla bu yapıyı korur. Çakışık kök varsa bir çözüm köke bağlı üstel, ikinci çözüm bu üstelin $\Delta t$ ile çarpılmış halidir.

### 6.3 Az sönümlü durum ($\alpha < \omega_0$)

Kökün içi negatif olur, sanal sayı çıkar. Kökler eşlenik karmaşıktır. Slayttaki ifadeler (ekrandan, 00:40:00):

- Koşul: $\alpha < \omega_0$; bu, seri devre için $C < 4L/R^2$ demektir.
- $s_1 = -\alpha + \sqrt{\alpha^2 - \omega_0^2} = -\alpha + j\omega_d$
- $s_2 = -\alpha - \sqrt{\alpha^2 - \omega_0^2} = -\alpha - j\omega_d$
- $\omega_d = \sqrt{\omega_0^2 - \alpha^2}$
- $j = \sqrt{-1}$; matematikçiler sanal birim için $i$ kullanır, elektrikte akımla karışmasın diye $j$ kullanılır.

Slayttaki grafik: $v(t)$, $t = 0$'dan başlayıp $e^{-t}$ biçimli kesikli zarfın içinde salınan bir eğridir; ardışık iki tepe arası $2\pi/\omega_d$'dir.

### 6.4 Az sönümlü çözümün gerçek biçime çevrilmesi

Kökler yerine konunca (ekrandan, 00:45:00):

$$v_C(t) = e^{-\alpha\Delta t}\left(A_1e^{j\omega_d\Delta t} + A_2e^{-j\omega_d\Delta t}\right)$$

Euler formülü kullanılır:

$$e^{j\theta} = \cos\theta + j\sin\theta, \qquad e^{-j\theta} = \cos\theta - j\sin\theta$$

Açılınca:

$$v_C(t) = e^{-\alpha\Delta t}\left[A_1(\cos\omega_d\Delta t + j\sin\omega_d\Delta t) + A_2(\cos\omega_d\Delta t - j\sin\omega_d\Delta t)\right]$$

Kosinüs ve sinüs paranteze alınınca:

$$v_C(t) = e^{-\alpha\Delta t}\left[(A_1 + A_2)\cos\omega_d\Delta t + j(A_1 - A_2)\sin\omega_d\Delta t\right]$$

$B_1 = A_1 + A_2$ ve $B_2 = j(A_1 - A_2)$ denince:

$$v_C(t) = e^{-\alpha\Delta t}\left[B_1\cos\omega_d\Delta t + B_2\sin\omega_d\Delta t\right]$$

Hoca bir adım daha ilerletti: aynı frekanslı sinüs ve kosinüsün toplamı, genliği ve faz farkı olan tek bir kosinüs olarak da yazılabilir. Yine iki bilinmeyen vardır (genlik ve faz). İki biçim de geçerlidir; hangisi kolaysa o kullanılır.

$e^{-\alpha\Delta t}$ azalan bir fonksiyon, kosinüs ise dalgalanan bir fonksiyondur. Çarpımları, üstel zarfı izleyen ve zarfın dışına çıkmayan, genliği giderek azalan bir sinüzoidaldir.

### 6.5 $\omega_0$ ile $\omega_d$ farkı

Bu durumda iki frekans vardır: $\omega_0$ diferansiyel denklemin katsayısından gelir; $\omega_d$ ise karmaşık kökün sanal kısmıdır. Kökler kabaca $s_{1,2} = -\alpha \pm j\beta$ biçimindedir ve $\beta = \omega_d$'dir. Bu ikisi farklı değerlerdir ve karıştırılmamalıdır.

### 6.6 Davranışların karşılaştırılması

Hoca bir seri RLC devresi üzerinden davranışları özetledi: kaynak ($V\,u(t)$ biçiminde) eksi sonsuzdan sıfıra kadar devrededir ve kondansatör şarj olmuştur. Sonra kaynak kaldırılır; geriye L, R ve C kalır ve kondansatördeki yük direnç üzerinden boşalır. $v_C$'nin davranışı:

- Aşırı sönümlü (iki ayrı negatif gerçek kök): hızla sıfıra oturmaya çalışır.
- Kritik sönümlü (eşit kökler): çözüm $(A_1 + A_2\Delta t)e^{-\alpha\Delta t}$ biçimindedir.
- Az sönümlü (karmaşık eşlenik kökler): üstel zarf içinde salınır.

> **Ders sonrası not:** Hoca bu karşılaştırmada önce eşit kök durumunu "underdamped" diye, karmaşık kök durumunu da yanlış adla andı; birkaç dakika sonra kendisi düzeltti: eşit gerçek kökler **kritik sönümlü** (critically damped), karmaşık kökler **az sönümlü** (underdamped) durumdur.

Slayttaki RLC devresi özellikleri (ekrandan, 00:50:00):

- Kayıplı bir RLC devresinde salınımlı cevap mümkündür, çünkü bobin ve kondansatördeki enerji bir elemandan diğerine aktarılabilir.
  - Az sönümlü cevap sönümlü bir salınımdır ve buna **ringing** denir.
- Kritik sönümlü devreler, aşırı ve az sönümlü devrelere göre son sürekli hale en kısa sürede ulaşır.
  - Ancak aşırı ya da az sönümlü bir devrenin ilk değişimi, kritik sönümlü devreninkinden büyük olabilir.

### 6.7 Sönümü sağlayan eleman

Değerin sıfıra azalmasını sağlayan parametre $\alpha$'dır; seri devrede $\alpha = R/(2L)$ olduğundan sönümü sağlayan direnç değeridir. $R = 0$ ise devre kayıpsızdır. Kondansatör enerjisini bobine, bobin bir sonraki çevrimde kondansatöre aktarır; sürekli sinüzoidal salınım içinde devam eden akım ve gerilim değerleri elde edilir. Devrede anlamlı bir $R$ varsa bütün akım ve gerilimlerde anlamlı bir sönüm olur.

## 7. Kaynaksız Paralel RLC Devresi

### 7.1 Formüller sınavda nasıl ele alınır

Hoca, diferansiyel denklemleri her seferinde çıkarmanın pratik olmadığını belirtti. $\alpha$, kökler gibi formüllerin gerekirse verilebileceğini, asıl beklentinin şu olduğunu söyledi: kökler gerçek, çakışık ya da eşlenik karmaşık çıktığında hangi çözümün önerileceği doğru seçilmelidir.

### 7.2 Devre ve başlangıç koşulları

Paralel devrede anahtarlı durumu bir akım kaynağıyla kurmak daha pratiktir. Slayttaki devre (ekrandan, 00:55:00): "Akım kaynağının $t = t_0$ anında devreden çıkarıldığı paralel RLC devresi."

| Eleman | Değer | Bağlantı |
|---|---|---|
| $I_s$ | akım kaynağı (yukarı yönlü) | $t = t_0$'da açılan seri anahtar üzerinden üst düğüme bağlı |
| $R$ | $2\,\mathrm{k}\Omega$ | üst ve alt düğüm arasında, akım $I_R$ aşağı |
| $L$ | $10\,\mu\mathrm{H}$ | üst ve alt düğüm arasında, akım $I_L$ aşağı |
| $C$ | $3\,\mu\mathrm{F}$ | üst ve alt düğüm arasında, akım $I_C$ aşağı |

Ortak gerilim $v(t)$, üst düğüm $+$, alt düğüm $-$ olarak tanımlıdır. Anahtar eksi sonsuzdan $t_0$'a kadar kapalıdır.

$t_0^-$ anında devre uzun süre DC şartlarda çalışmıştır: bobin kısa devre, kondansatör açık devredir. Bu yüzden:

- $i_L(t_0^-) = I_s$
- $i_R(t_0^-) = 0$, $i_C(t_0^-) = 0$
- Bobin kısa devre olduğundan ortak gerilim sıfırdır: $v_R = v_L = v_C = 0$.

Enerji depolayan eleman burada bobindir; başlangıç akımına sahiptir. Kaynak kalkınca devrede başka kaynak olmadığından bu enerji tüketilir ve $t \to \infty$'da her elemanın akım ve gerilimi sıfıra gider.

### 7.3 Düğüm denklemi

Alt düğüm referans (0 V), üst düğüm gerilimi $v(t)$ alınır. Düğümden çıkan akımların toplamı sıfırdır (ekrandan, 01:00:00):

$$i_R(t) + i_L(t) + i_C(t) = 0$$

$$v(t) = v_R(t) = v_L(t) = v_C(t)$$

$$\frac{v_R(t)}{R} + i_L(t) + C\,\frac{dv_C(t)}{dt} = 0$$

Hepsi $i_L$ cinsinden yazılır. Bobin bağıntısı $v_L(t) = v(t) = L\,\frac{di_L(t)}{dt}$ olduğundan:

- $\frac{v_R}{R} = \frac{L}{R}\,\frac{di_L}{dt}$
- $C\,\frac{dv_C}{dt} = C\,\frac{d}{dt}\left(L\,\frac{di_L}{dt}\right) = LC\,\frac{d^2i_L}{dt^2}$

Yerine konunca:

$$LC\,\frac{d^2i_L(t)}{dt^2} + \frac{L}{R}\,\frac{di_L(t)}{dt} + i_L(t) = 0$$

$LC$'ye bölününce:

$$\frac{d^2i_L(t)}{dt^2} + \frac{1}{RC}\,\frac{di_L(t)}{dt} + \frac{i_L(t)}{LC} = 0$$

Hoca bunu genel biçimde $i_L'' + a\,i_L' + b\,i_L = 0$ diye yazdı.

### 7.4 Çözüm

Yine kendisi ve türevleri aynı biçimde olan bir fonksiyon aranır: $i_L = Ae^{st}$. Birinci türev $sAe^{st}$, ikinci türev $s^2Ae^{st}$ olur. Yerine konup $Ae^{st}$ paranteze alınınca:

$$s^2 + \frac{s}{RC} + \frac{1}{LC} = 0$$

$Ae^{st} = 0$ yine aranan çözüm değildir ($i_L = 0$ çözümü). Kökler $\alpha$ ve $\omega_0$ ile yazılır, ama önemli bir fark vardır:

> **Hocanın vurgusu:** Kaynaksız seri RLC devresinde $\alpha = \dfrac{R}{2L}$, kaynaksız paralel RLC devresinde $\alpha = \dfrac{1}{2RC}$'dir. İkisinde de $\omega_0 = \dfrac{1}{\sqrt{LC}}$. Alfalar farklıdır, dikkat edilmelidir.

Kökler yine $s_{1,2} = -\alpha \pm \sqrt{\alpha^2 - \omega_0^2}$'dir ve $\alpha$ ile $\omega_0$'ın büyüklüğüne göre aynı üç durum çıkar:

- İki negatif gerçek kök: iki ayrı üstel toplanır.
- Çakışık kök: bir üstel ve onun $t$ (ya da $\Delta t$) ile çarpılmışı.
- Eşlenik karmaşık kökler: $\omega_d = \sqrt{\omega_0^2 - \alpha^2}$ ile bir sönüm terimi ve bir salınım terimi içeren sönümlü sinüzoidal.

Her durumda iki bilinmeyen vardır ($A_1, A_2$ ya da $B_1, B_2$). Bunlar iki başlangıç koşulundan bulunur: bobinin başlangıç akımı ve bobin akımının türevinden hesaplanan bobin gerilimi. Paralel devrede bobin gerilimi kondansatörün başlangıç gerilimine eşittir; kondansatörün başlangıç gerilimi hesaplanabildiği için ikinci koşul elde edilir.

### 7.5 Diğer akım ve gerilimler

$i_L$ bulunduktan sonra (ekrandan, 01:05:00):

$$v_L(t) = L\,\frac{di_L(t)}{dt}, \qquad v_L(t) = v_C(t) = v_R(t)$$

$$i_C(t) = C\,\frac{dv_C(t)}{dt}, \qquad i_R(t) = \frac{v_R(t)}{R}$$

Hoca, seri ve paralel durumların özet tablosunun sınavda verilebileceğini ya da yanda bulunmasına izin verilebileceğini, öğrencilerden bunun üzerinden yorum yapmalarının bekleneceğini söyledi.

### 7.6 Konu sırası

Hoca konuları dört adımda topladı:

- 1. Kaynaksız seri RLC
- 2. Kaynaksız paralel RLC
- 3. Kaynaklı seri RLC
- 4. Kaynaklı paralel RLC

Kaynaksız devrelerde $t \to \infty$'da akım ve gerilimler sıfıra yaklaşır. Kaynaklı devrelerde ise uygulanan kaynağın DC şartlarındaki değerlerine yaklaşırlar.

## 8. Kaynaklı Seri RLC Devresi (Basamak Cevabı)

### 8.1 Amaç

Slayttaki ders amacı (ekrandan, 01:10:00): seri bağlı direnç, bobin ve kondansatör gerilimlerini ilişkilendiren denklemleri şu durumlar için türetmek:

- gerilim ya da akım kaynağıyla ilişkili birim basamak fonksiyonu 0'dan 1'e değiştiğinde, ya da
- bir anahtar devreye bir gerilim ya da akım kaynağı bağladığında.

Ve ikinci dereceden denklemin çözümünü aşırı sönümlü, kritik sönümlü ve az sönümlü durumlar için tanımlamak.

Hoca slayta şunu yazdı (ekrandan, 01:10:00):

$$v_{C,h}(t) = v_{C,n}(t) + v_{C,f}(t)$$

Burada $v_{C,n}$ kaynaklar sıfırken bulunan doğal çözümdür; $v_{C,f}$ ise kaynağın fonksiyonu cinsinden önerilecek zorlanmış çözümdür. İlk örneklerde kaynaklar DC'dir; ama genelleştirilerek şu söylenecektir: kaynak hangi tipteyse, o tipin en genel fonksiyonu zorlanmış çözüm olarak önerilir.

> **Hocanın vurgusu:** Elde edilen nihai çözümler, kaynaklı ya da kaynaksız devre fark etmeksizin, $t \to \infty$ veya bilinen başka $t$ değerleri için mutlaka doğrulanmalıdır.

### 8.2 Başlangıç ve son durum

Kaynak $V_s\,u(t - t_0)$'dır: uzun süre sıfırdır, $t_0$ anında $V_s$'e çıkar ve orada kalır. Eksi sonsuzdan $t_0^-$'a kadar devre kaynaksızdır; bu yüzden:

$$i_L(t_0^-) = 0, \quad i_C(t_0^-) = 0, \quad v_C(t_0^-) = 0, \quad v_L(t_0^-) = 0$$

$t \to \infty$ eşdeğerinde kaynak devrededir; bobin kısa devre, kondansatör açık devredir:

$$i_L(\infty) = 0, \quad v_L(\infty) = 0, \quad i_C(\infty) = 0, \quad v_C(\infty) = V_s$$

Son durumda $v_C$ sıfırdan farklıdır; bu son koşulu sağlatmak için ek bir çözüm (zorlanmış çözüm) gelir.

### 8.3 Diferansiyel denklem

Slayttaki devre (ekrandan, 01:25:00):

| Eleman | Değer | Not |
|---|---|---|
| Kaynak | $V_s\,u(t - t_0)$ | DC gerilim kaynağı |
| $R$ | $2\,\mathrm{k}\Omega$ | gerilimi $V_R$ ($+$ sol, $-$ sağ) |
| $L$ | $10\,\mu\mathrm{H}$ | gerilimi $V_L$ ($+$ sol, $-$ sağ) |
| $C$ | $3\,\mu\mathrm{F}$ | gerilimi $V_C$ ($+$ üst, $-$ alt) |

Hepsi seri bağlıdır, çevre akımı $i(t)$'dir. Çevre denklemi $v_R + v_L + v_C = V_s$ ya da slayttaki biçimiyle:

$$\sum v(t) = 0: \quad v_C(t) + L\,\frac{di_L(t)}{dt} + R\,i_L - V_s = 0$$

$$i_C(t) = C\,\frac{dv_C(t)}{dt}, \qquad i_L(t) = i_C(t)$$

Tek kol olduğu için $i_R = i = i_L = i_C$. $i$ yerine $C\,dv_C/dt$ yazılınca:

$$LC\,\frac{d^2v_C(t)}{dt^2} + RC\,\frac{dv_C(t)}{dt} + v_C(t) = V_s$$

$$\frac{d^2v_C(t)}{dt^2} + \frac{R}{L}\,\frac{dv_C(t)}{dt} + \frac{1}{LC}\,v_C(t) = \frac{V_s}{LC}$$

$$v_C(t - t_0) = v_t(t - t_0) + v_{ss}(t - t_0) \quad (t > t_0)$$

### 8.4 İki çözüm

- **Geçici hal çözümü:** denklemin sağ tarafı sıfır kabul edilerek bulunur. Doğal çözüm, natural solution ya da transient solution da denir; hepsi devrenin kendi elemanlarından gelen doğal davranışıdır.
- **Sürekli hal çözümü:** kaynağın tipinde önerilen çözümdür. Zorlanmış çözüm, forced solution ya da steady-state solution da denir.

Doğal çözüm yaklaşımı kaynaksız seri devreyle aynıdır: $\alpha = R/(2L)$, $\omega_0 = 1/\sqrt{LC}$, kökler $-\alpha \pm \sqrt{\alpha^2 - \omega_0^2}$ ve üç sönüm durumu.

### 8.5 Zorlanmış çözümün bulunması

Slaytta son durum $v_C(\infty) = V_s$'dir ve hoca zorlanmış çözüm için önce daha genel bir biçim önerdi (ekrandan, 01:35:00):

$$v_{C,ss}(t) = at + b$$

Bu, denklemde yerine konur:

- $v_{C,ss}'' = 0$
- $v_{C,ss}' = a$

$$0 + \frac{R}{L}\,a + \frac{at + b}{LC} = \frac{V_s}{LC}$$

Düzenlenince:

$$\frac{a}{LC}\,t + \left(\frac{aR}{L} + \frac{b}{LC}\right) = 0\cdot t + \frac{V_s}{LC}$$

Polinomlarda iki taraftaki aynı dereceli terimlerin katsayıları eşit olmalıdır. Sağ tarafta $t$'li terim yoktur; bu yüzden $a/(LC) = 0$ ve $L, C$ sıfır olamayacağına göre $a = 0$. Kalan $b/(LC) = V_s/(LC)$'den $b = V_s$ bulunur.

Hoca buradan şunu çıkardı: zamana bağlı terim gereksizmiş, fazladan bilgi eklenmiş. Sabit kaynak için sürekli hal çözümü sabit olmalıdır.

### 8.6 Zorlanmış çözüm kaynağın tipindedir

Hoca kuralı genelleştirdi:

| Kaynak | Önerilecek sürekli hal çözümü |
|---|---|
| $v_{kaynak} = V_s$ (sabit) | $A$ (sabit) |
| $v_{kaynak} = A\sin\omega t$ | $B\sin(\omega t + \phi)$ |
| $v_{kaynak} = At + B$ (örneğin $2t + B$) | $at + b$ |

Sinüzoidal işarette yapılabilecek en büyük genişletme genlik ve faz farkı eklemektir. Sabit bir değer genişletilemez. Birinci dereceden bir doğru için yapılabilecek tek şey $a$ ve $b$ katsayılarını serbest bırakıp devreden belirlemektir.

> **Hocanın vurgusu:** Sürekli hal (steady-state) çözümü için önerilecek denklem kaynağın tipinde olmalıdır. Bu çok önemli bir noktadır.

### 8.7 Tam çözümler

Slayttaki tam çözümler, $\Delta t = t - t_0$ (ekrandan, 01:40:00):

- Aşırı sönümlü: $v_C(t) = A_1e^{s_1\Delta t} + A_2e^{s_2\Delta t} + V_s$
- Kritik sönümlü: $v_C(t) = (A_1 + A_2\Delta t)e^{-\alpha\Delta t} + V_s$
- Az sönümlü: $v_C(t) = [B_1\cos(\omega_d\Delta t) + B_2\sin(\omega_d\Delta t)]e^{-\alpha\Delta t} + V_s$
- $\omega_d = \sqrt{\omega_0^2 - \alpha^2}$, $B_1 = A_1 + A_2$, $B_2 = j(A_1 - A_2)$

Hoca slaytta ilk kısmı (üstelli terimler) doğal çözümden, $+V_s$ kısmını zorlanmış çözümden gelen parça diye ayrı kutulara aldı.

Diğer elemanların değerleri bu çözümden yayılır: kondansatör geriliminin türevi alınıp $C$ ile çarpılınca akım bulunur; bobin akımı biliniyorsa türevi alınıp $L$ ile çarpılınca bobin gerilimi bulunur.

## 9. Kaynaklı Paralel RLC Devresi

### 9.1 Devre ve koşullar

Slayttaki devre (ekrandan, 01:45:00): $I_s$ akım kaynağına paralel bir anahtar vardır ($t = t_0$'da açılır). Kaynağın yanında sırasıyla $R = 2\,\mathrm{k}\Omega$, $L = 10\,\mu\mathrm{H}$, $C = 3\,\mu\mathrm{F}$ üst ve alt düğüm arasına paralel bağlıdır; alt düğüm referanstır (0).

Uzun süre anahtar kapalıdır. Bunun anlamı, kaynak akımının anahtar üzerinden kendi içinde dönmesi ve devreyi beslememesidir. Bu yüzden:

$$v_C(t_0^-) = 0, \quad v_L(t_0^-) = 0, \quad i_C(t_0^-) = 0, \quad i_L(t_0^-) = 0$$

$t = t_0$'da anahtar açılır ve kaynak devreyi beslemeye başlar. $t \to \infty$ eşdeğerinde bobin kısa devre, kondansatör açık devredir:

$$i_L(\infty) = I_s, \quad v_C(\infty) = 0, \quad i_C(\infty) = 0, \quad v_L(\infty) = 0$$

Bobin akımı sıfırdan başlar ve asimptotik olarak kaynak akımına yaklaşır.

### 9.2 Diferansiyel denklem

Üst düğümde $i_R$, $i_L$, $i_C$ çıkış yönlü, $i_s$ giriş yönlüdür. Paralel olduğu için bütün eleman gerilimleri eşittir ve $v$ ile gösterilir. Slayttaki işlemler (ekrandan, 01:45:00):

$$i_R(t) + i_L(t) + i_C(t) = i_s(t)$$

$$v(t) = v_R(t) = v_L(t) = v_C(t)$$

$$\frac{v_R(t)}{R} + i_L(t) + C\,\frac{dv_C(t)}{dt} = I_s$$

Kondansatör için $q_C = C\,v_C$, türev alınınca $i_C = C\,v_C'$. Bobin için akı $\phi_L = L\,i_L$, türev alınınca $v = v_L = L\,i_L'$. Bunlar yerine konunca:

$$LC\,\frac{d^2i_L(t)}{dt^2} + \frac{L}{R}\,\frac{di_L(t)}{dt} + i_L(t) = I_s$$

$$\frac{d^2i_L(t)}{dt^2} + \frac{1}{RC}\,\frac{di_L(t)}{dt} + \frac{i_L(t)}{LC} = \frac{I_s}{LC}$$

$$i_L(t) = i_t(t) + i_{ss}(t)$$

### 9.3 Zorlanmış ve geçici çözüm

Kaynak sabit olduğundan zorlanmış çözüm için sabit bir $A$ önerilir. Sabitin birinci ve ikinci türevi sıfırdır; denklem $A/(LC) = I_s/(LC)$ olur, yani $A = I_s$.

Geçici çözüm, türevli kısım sıfıra eşitlenerek bulunur. $i_L$ için $e^{st}$ önerilir, $s$'ye göre ikinci dereceden denklem çıkar ve kökler:

$$s_{1,2} = -\alpha \pm \sqrt{\alpha^2 - \omega_0^2}, \qquad \alpha = \frac{1}{2RC}, \quad \omega_0 = \frac{1}{\sqrt{LC}}$$

Az sönümlü durumda çözüm $e^{-\alpha t}\,C_1\sin(\omega_d\Delta t + C_2)$ biçiminde de yazılabilir; hangisi kolaysa o kullanılır.

> **Ders sonrası not:** Hoca bu bölümde "kökler gerçek ve ayrı ise" dedikten sonra çözümü $A_1e^{-\alpha t} + A_2e^{-\alpha t}\Delta t$ diye okudu; bu kritik sönümlü (çakışık kök) durumun çözümüdür. Gerçek ve ayrı kökler için doğru biçim, slayttaki gibi $A_1e^{s_1\Delta t} + A_2e^{s_2\Delta t}$'dir.

### 9.4 Tam çözümler

Slayttaki tam çözümler (ekrandan, 01:50:00):

- Aşırı sönümlü: $i_L(t) = A_1e^{s_1\Delta t} + A_2e^{s_2\Delta t} + I_s$
- Kritik sönümlü: $i_L(t) = (A_1 + A_2\Delta t)e^{-\alpha\Delta t} + I_s$
- Az sönümlü: $i_L(t) = [B_1\cos(\omega_d\Delta t) + B_2\sin(\omega_d\Delta t)]e^{-\alpha\Delta t} + I_s$
- $\omega_d = \sqrt{\omega_0^2 - \alpha^2}$, $B_1 = A_1 + A_2$, $B_2 = j(A_1 - A_2)$

$s_1$ ve $s_2$ $R$, $L$, $C$'ye bağlı olarak bulunur. $A_1, A_2$ (ya da $B_1, B_2$) başlangıç koşulları ve son durumdan bulunur. Hoca, bu devrede başlangıç değerlerinin hepsi sıfır olduğu için son durumun ($t \to \infty$) önemli olduğunu, $i_L$ ve $v_C$'nin sonsuzdaki değerlerinden denklemler kurulacağını söyledi.

> **Ek bilgi (derste anlatılmadı):** Katsayıları bulmak için genellikle iki başlangıç koşulu kullanılır: $i_L(t_0^+) = 0$ ve $v_L(t_0^+) = L\,i_L'(t_0^+) = v_C(t_0^+) = 0$, yani $i_L'(t_0^+) = 0$. Örneğin aşırı sönümlü durumda $A_1 + A_2 + I_s = 0$ ve $s_1A_1 + s_2A_2 = 0$ olur. Son değer $I_s$ ise zorlanmış çözümle zaten sağlanmıştır.

Hoca ayrıca dualite kavramına kısaca değindi: bu kavram daha önce direnç ve iletkenlik ilişkisinde görülmüştü; seri ve paralel RLC devreleri arasında da benzer bir dualite vardır. Dual devrelerin ayrıntısına girilmedi.

## 10. Frekans Uzayına Geçiş Fikri

Bu derste yapılan çözümleme, RLC devresindeki bir akım ya da gerilimin zaman uzayındaki ($t$'ye bağlı) çözümünü verir. Asıl ayrıntılı bilgi geçiş halindedir: kaynağı devreye bağladığımız ya da devreden çektiğimiz andaki değişimler.

Birçok devrede geçici haller ilgi alanı dışında kalır; asıl ilgilenilen, $5\tau$ kadar süre geçtikten sonraki davranıştır. Günümüzde çok kullanılan kaynak türü sinüzoidal kaynaklardır. Kaynak sinüzoidal ise ve geçici haller geçtikten sonraki davranış inceleniyorsa diferansiyel denklemlerle uğraşmaya gerek kalmayabilir.

Slayttaki başlık "Neden karmaşık sayılar kullanmamız gerekir?" idi (ekrandan, 01:55:00): Devredeki bağımsız kaynakların hepsinin sinüzoidal olduğu ve bütün geçici hallerin (basamaklar, anahtarlar, darbeler) bittiği biliniyorsa, devre başlangıç ve son koşullar belirlenmeden cebirsel olarak (örneğin düğüm, çevre yöntemleriyle) çözülebilir. Slayttaki tablo, seri ($\alpha = R/2L$) ve paralel (paydası kısmen örtülü $\alpha$ ifadesi) devreler için aşırı, kritik ve az sönümlü çözüm kalıplarını gösteriyor ve üzerinde "NOT NECESSARY" (gerekli değil) yazıyordu.

<!-- BELİRSİZ: Slayttaki paralel devre α ifadesinin paydası "NOT NECESSARY" yazısının altında kalıyor; derste paralel devre için α = 1/(2RC) verildi. -->

Frekans uzayında şu kolaylık elde edilir: eleman karakteristikleri (örneğin kondansatörde akımın gerilimin türeviyle orantılı olması) gibi diferansiyel bağıntılar doğrusal (cebirsel) denklemlere dönüşür. Zaman uzayında akım ile gerilim arasındaki ilişki diferansiyel denklemken, frekans uzayında bu ilişki doğrusaldır; yani eleman o uzayda bir dirence dönüşmüş olur. R, L, C elemanlarının tanım bağıntıları, kaynak değerleri ve devre topolojisi frekans uzayına geçirildiğinde, devre ne kadar karmaşık olursa olsun bir direnç devresi gibi çözülür. Dersin başından beri görülen direnç devresi yöntemleri burada tekrar kullanılabilir hale gelir.

Devre frekans uzayında çözüldükten sonra ilgilenilen değişken (örneğin kondansatör gerilimi) orada bırakılmaz, tekrar zaman uzayına geçirilir; böylece $v_C$ yine $t$'ye bağlı bir fonksiyon olarak yazılır. İki yaklaşımın farkı:

- Bu dersteki yaklaşım: zaman uzayında diferansiyel denklem çözülür, çözüm önerisi elde edilir.
- Sonraki yaklaşım: eleman bağıntıları, kaynaklar ve topoloji frekans uzayına geçirilir, devre direnç devresi gibi çözülür, sonuç zaman uzayına geri çevrilir.

Frekans uzayına geçerken karmaşık sayılar kullanılacağı için ders, karmaşık sayıların tekrarıyla devam etti.

## 11. Karmaşık Sayılar

### 11.1 Tanım ve fonksiyon gösterimi

Hoca karmaşık sayıları önce el yazısıyla tanıttı (ekrandan, 02:00:00): $\mathbb{C} = \{(a, b) \mid a, b \in \mathbb{R}\}$. Karmaşık sayı, gerçek sayılardan oluşan bir $(a, b)$ ikilisidir ve iki boyutlu bir düzlemde (yatay eksen gerçek, dikey eksen sanal) bir noktadır. Bu ikili $(a, b)$ ya da $a + jb$ diye yazılır. Gerçek sayılar bir doğru üzerinde gösterilirken karmaşık sayılar bir düzlemde gösterilir.

Fonksiyon gösterimi açısından:

- $f: \mathbb{R} \to \mathbb{R}$ bir fonksiyon, giriş değeri yatay, çıkış dikey olacak biçimde iki boyutlu düzlemde çizilebilir.
- $f: \mathbb{R}^2 \to \mathbb{R}$ üç boyutlu bir yüzey olarak çizilebilir.
- $f: \mathbb{C} \to \mathbb{C}$ ise iki boyutlu bir girdiyi iki boyutlu bir çıktıya götürür; alışılmış çizimlerle gösterilemez. Bu yüzden ikiye ayrılır: gerçek kısım $\mathrm{Re}\{f\}: \mathbb{C} \to \mathbb{R}$ ve sanal kısım $\mathrm{Im}\{f\}: \mathbb{C} \to \mathbb{R}$. İki ayrı birim olarak incelenir.

### 11.2 Kartezyen ve polar gösterim

Slayttaki tanımlar (ekrandan, 02:05:00):

- Bir karmaşık sayı $z$ dikdörtgen (kartezyen) biçimde $z = x + jy$ yazılır; $j = \sqrt{-1}$.
  - $x$, $z$'nin gerçek kısmıdır.
  - $y$, $z$'nin sanal kısmıdır.
- $z$ polar ya da üstel biçimde $z = r\angle\phi = re^{j\phi}$ yazılabilir.
- Yalnız gerilim gerilimle, akım akımla, empedans empedansla, admitans admitansla toplanıp çıkarılabilir.

Karmaşık sayılarda değişken genelde küçük $z$ ile gösterilir; $x$ ve $y$ gerçek olmak üzere $x + jy$ biçimindeki bütün sayıların kümesi karmaşık sayılardır. Kartezyen gösterimde $z$'nin iki bileşeni, $x$ ve $y$ eksenleri üzerindeki izdüşümleridir. Polar gösterimde aynı $z$, orijine uzaklığı $r$ ve $x$ eksenine göre açısı $\phi$ ile, yani $(r, \phi)$ ikilisiyle ifade edilir; $r\angle\phi$ diye de yazılır. Üstel gösterimde $z = r\,e^{j\phi}$'dir.

Dönüşümler (hocanın el yazısı, ekrandan, 02:05:00):

$$r = \sqrt{x^2 + y^2}, \qquad \phi = \arctan\left(\frac{y}{x}\right)$$

$$x = r\cos\phi, \qquad y = r\sin\phi$$

$r$, dik üçgenin hipotenüsüdür. Açı, orijinden noktaya çizilen doğrunun eğiminden bulunur.

### 11.3 Euler formülü

$$e^{j\phi} = \cos\phi + j\sin\phi$$

Hoca bu formülün kaynağını şöyle anlattı: $e^x$ sonsuz terimli bir polinom olarak yazılır; $\sin x$ ve $\cos x$ de sonsuz terimli polinomlar olarak yazılır. $x$ yerine $j\phi$ konunca, $j$'nin kuvvetleri her dört adımda tekrar eder:

$$j^0 = 1, \quad j^1 = j, \quad j^2 = -1, \quad j^3 = -j, \quad j^4 = 1$$

Bu yüzden açılımın çift dereceli terimleri kosinüsün açılımına, tek dereceli terimleri $j$ çarpı sinüsün açılımına karşılık gelir. Böylece Euler formülü ve buradan polar biçim elde edilir.

### 11.4 Gerçek ve sanal kısım, eşlenik

Örnek: $M = 3 + j$ ise $\mathrm{Re}\{M\} = 3$, $\mathrm{Im}\{M\} = 1$. $N = 2 - 2j$ ise $\mathrm{Re}\{N\} = 2$, $\mathrm{Im}\{N\} = -2$. Karmaşık sayı aslında gerçek sayı ikilisidir.

**Karmaşık eşlenik** $z^*$ ile gösterilir. $z = a + jb$ ($a, b$ gerçek, $j = \sqrt{-1}$) ise $z^* = a - jb$'dir. Bu, karmaşık sayının kartezyen gösteriminde yatay (gerçek) eksene göre ayna görüntüsüdür. Örneğin $M = 3 + 1j$ ise $M^* = 3 - 1j$: gerçek kısım aynı kalır, sanal kısım $-1$'e gider.

### 11.5 Toplama ve çıkarma

$x = a + jb$, $y = c + jd$ ($a, b, c, d$ gerçek) için gerçek kısımlar kendi aralarında, sanal kısımlar kendi aralarında toplanır ya da çıkarılır:

$$x + y = (a + c) + j(b + d), \qquad x - y = (a - c) + j(b - d)$$

Karmaşık sayılar gerçek ikililer olduğu için vektör gibi de düşünülebilir. Toplama, vektörleri uç uca eklemeye (tip-to-tail) karşılık gelir: ilk vektörün başlangıcından son vektörün bitişine çizilen vektör toplamdır. Slayttaki örnek (ekrandan, 02:10:00):

$$M = 3 + 1j, \qquad N = 2 - 2j, \qquad M + N = 5 - 1j$$

Grafikte $M$ orijinden $(3, 1)$'e, $N$ bunun ucundan başlayıp $(5, -1)$'e gider; orijinden $(5, -1)$'e çizilen vektör $M + N$'dir. Cebirsel olarak:

$$M = a_1 + b_1 j, \quad N = a_2 + b_2 j, \quad M + N = (a_1 + a_2) + (b_1 + b_2)j$$

### 11.6 Çarpma

**Kartezyen biçimde** çarpma daha zordur. Çarpmanın toplamaya göre dağılma özelliği ve $j^2 = -1$ kullanılır:

$$(a + jb)(c + jd) = ac + jad + jbc + j^2bd = (ac - bd) + j(ad + bc)$$

Gerçek kısım $ac$ ve $jb \cdot jd = -bd$'den, sanal kısım $ad$ ve $bc$'den gelir.

**Üstel biçimde:** $x = r_1e^{j\phi_1}$, $y = r_2e^{j\phi_2}$ ($r_1, r_2, \phi_1, \phi_2$ gerçek) ise:

$$x\cdot y = r_1r_2\,e^{j(\phi_1 + \phi_2)}$$

**Polar biçimde:** $x = r_1\angle\phi_1$, $y = r_2\angle\phi_2$ ise genlikler çarpılır, açılar toplanır:

$$x\cdot y = r_1r_2\angle(\phi_1 + \phi_2)$$

Bu, üstel biçimle uyumludur: genlik $r_1r_2$, $e^{j(\cdot)}$'deki kısım ise açıdır.

### 11.7 Bölme

**Kartezyen biçimde:** $z = \dfrac{a + jb}{c + jd}$ hesaplanırken pay ve payda, paydanın eşleniği $c - jd$ ile çarpılır. Bir karmaşık sayı eşleniğiyle çarpılınca saf gerçek bir sayı çıkar; böylece payda karmaşıklıktan kurtulur. Paydada $-cdj + cdj - d^2j^2 = c^2 + d^2$ kalır:

$$\mathrm{Re}\{z\} = \frac{ac + bd}{c^2 + d^2}, \qquad \mathrm{Im}\{z\} = \frac{bc - ad}{c^2 + d^2}$$

**Üstel biçimde:**

$$\frac{r_1e^{j\phi_1}}{r_2e^{j\phi_2}} = \frac{r_1}{r_2}\,e^{j(\phi_1 - \phi_2)}$$

**Polar biçimde:** genlikler birbirine oranlanır, açılar çıkarılır:

$$\frac{r_1\angle\phi_1}{r_2\angle\phi_2} = \frac{r_1}{r_2}\angle(\phi_1 - \phi_2)$$

Kartezyen çarpma ve bölme formülleri ile polar biçimdeki karşılıkları rastgele sayılarla python ile kontrol edildi.

Hoca, bir sonraki derste RLC devreleriyle ilgili örnek çözüldükten sonra fazör uzayına geçileceğini söyledi.

## Örnek Sorular

**Soru 1** (ekrandan, 02:10:00): $M = 3 + 1j$ ve $N = 2 - 2j$ karmaşık sayıları için $M + N$'i cebirsel ve grafik olarak bulun.

> **Çözüm (derste verildi):** Gerçek kısımlar toplanır: $3 + 2 = 5$. Sanal kısımlar toplanır: $1 + (-2) = -1$. $M + N = 5 - 1j$. Grafikte $M$ vektörünün ucuna $N$ eklenir (uç uca); orijinden $(5, -1)$ noktasına çizilen vektör toplamdır.

**Soru 2** (derste sözlü, 01:34:37): Kaynaklı seri RLC devresinde $v_C'' + \frac{R}{L}v_C' + \frac{1}{LC}v_C = \frac{V_s}{LC}$ denklemi için sürekli hal çözümü $v_{C,ss} = at + b$ önerilirse $v_C''$ ve $v_C'$ ne olur, $a$ ve $b$ kaç çıkar?

> **Çözüm (derste verildi):** $v_C'' = 0$, $v_C' = a$. Denklem $\frac{a}{LC}t + \frac{aR}{L} + \frac{b}{LC} = \frac{V_s}{LC}$ olur. Sağda $t$'li terim yok, bu yüzden $a = 0$; sabit terimlerden $b = V_s$. Sürekli hal çözümü $v_{C,ss} = V_s$'dir.

**Soru 3** (derste sözlü, 02:02:48): Kartezyen biçimde $z = x + jy$ verilmişse $r$ ve $\phi$, polar biçimde $r$ ve $\phi$ verilmişse $x$ ve $y$ nasıl yazılır?

> **Çözüm (derste verildi):** $r = \sqrt{x^2 + y^2}$, $\phi = \arctan(y/x)$; $x = r\cos\phi$, $y = r\sin\phi$.

**Soru 4** (ekrandan, 01:25:00 ve 00:55:00): Ekrandaki devrelerde $R = 2\,\mathrm{k}\Omega$, $L = 10\,\mu\mathrm{H}$, $C = 3\,\mu\mathrm{F}$ verilmiştir. Bu değerlerle seri RLC devresi ve paralel RLC devresi hangi sönüm durumundadır?

> **Çözüm (derste verilmedi):** Her iki devrede $\omega_0 = 1/\sqrt{LC} = 1/\sqrt{10\cdot10^{-6}\cdot3\cdot10^{-6}} \approx 1{,}826\cdot10^{5}$ rad/s.
>
> - Seri: $\alpha = R/(2L) = 2000/(2\cdot10^{-5}) = 10^{8}$ Np/s. $\alpha > \omega_0$, yani aşırı sönümlü. Kökler $s_1 \approx -166{,}7$ Np/s ve $s_2 \approx -2{,}0\cdot10^{8}$ Np/s. (Denetim: $4L/R^2 = 10^{-11}$ F ve $C = 3\cdot10^{-6}$ F bundan büyük.)
> - Paralel: $\alpha = 1/(2RC) = 1/(2\cdot2000\cdot3\cdot10^{-6}) \approx 83{,}3$ Np/s. $\alpha < \omega_0$, yani az sönümlü; $\omega_d = \sqrt{\omega_0^2 - \alpha^2} \approx 1{,}826\cdot10^{5}$ rad/s.
>
> Değerler python ile hesaplandı.

## Dersin Toparlaması

Bu derste ikinci dereceden (RLC) devrelerin zaman uzayındaki çözümü tamamlandı. Kaynaksız seri devrede kondansatör gerilimi için, kaynaksız paralel devrede bobin akımı için ikinci dereceden diferansiyel denklem kuruldu; $e^{st}$ önerisiyle karakteristik denkleme ve $s_{1,2} = -\alpha \pm \sqrt{\alpha^2 - \omega_0^2}$ köklerine ulaşıldı. Seri devrede $\alpha = R/(2L)$, paralel devrede $\alpha = 1/(2RC)$, ikisinde de $\omega_0 = 1/\sqrt{LC}$'dir. $\alpha$ ile $\omega_0$'ın karşılaştırılmasına göre aşırı, kritik ve az sönümlü çözüm kalıpları seçilir; katsayılar kondansatör geriliminin ve bobin akımının sürekliliğinden gelen iki koşulla bulunur. Kaynaklı devrelerde tam çözüm, doğal çözüme kaynağın tipinde önerilen zorlanmış çözümün ($V_s$ ya da $I_s$) eklenmesiyle elde edilir ve sonuç $t \to \infty$ gibi bilinen anlarda doğrulanmalıdır.

Dersin son kısmında, sinüzoidal kaynaklı ve geçici hali bitmiş devrelerin diferansiyel denklem çözmeden, frekans uzayında direnç devresi gibi çözülebileceği fikri tanıtıldı. Bunun için gereken karmaşık sayı bilgisi (kartezyen, polar ve üstel gösterim, Euler formülü, eşlenik, dört işlem) tekrar edildi. Bir sonraki derste RLC devreleriyle ilgili örnek çözülüp fazör uzayına geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
