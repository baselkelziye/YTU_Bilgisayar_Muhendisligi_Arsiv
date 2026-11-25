# Ders 5 Genişletilmiş Notu: Doğrusallık, Süperpozisyon İlkesi, İdeal ve Gerçek Kaynaklar ve Kaynak Dönüşümü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Amaçları ve Yol Haritası
- 2. Doğrusallık
- 3. Doğrusal Olmayan Sistemler ve Elemanlar
- 4. Süperpozisyona Giriş: İlk Örnek
- 5. Doğrusallık ile Devre Çözümü
- 6. Süperpozisyon İlkesi ve Uygulama Kuralları
- 7. Süperpozisyon Örnekleri
- 8. Bağımlı Kaynaklı Devrede Süperpozisyon
- 9. İdeal ve Gerçek Kaynaklar
- 10. Kaynak Dönüşümü ve Eşdeğerlik
- 11. Kaynak Dönüşümü ile Devre Çözümü
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Amaçları ve Yol Haritası

Bu haftanın konusu doğrusallık, süperpozisyon ve kaynak dönüşümüdür. Bu konular, devre teorisinde sık kullanılan Thevenin ve Norton eşdeğerlerine giden yolu hazırlar. Slayttaki ders amaçları şöyledir (ekrandan, 00:10:00):

- Doğrusallık özelliğini tanıtmak.
- Süperpozisyon ilkesini tanıtmak.
- İki ya da daha fazla kaynak içeren bir devrede gerilim ve akımları süperpozisyonla adım adım hesaplamak.
- İdeal ve gerçek gerilim ve akım kaynakları arasındaki farkı anlatmak; gerçek bir gerilim kaynağı ile gerçek bir akım kaynağının birbirine eşdeğer olduğunu, birinin devrede diğerinin yerine konabileceğini göstermek.
- Thevenin ve Norton teoremlerini ifade etmek; bir devrenin üç bileşene (kaynak, eşdeğer direnç, yük) indirgenmesinde nasıl kullanıldığını göstermek.
- En büyük güç aktarımı teoremini (maximum power transfer) anlamak.

Hoca akışı şöyle özetledi. Önce doğrusallık tanımlanır. Ardından doğrusallıktan gelen bir özellik olarak süperpozisyon kullanılır: devredeki her kaynağın tek başına etkisi hesaplanır, bu tekil etkilerin net toplamı, bütün kaynaklar devredeyken herhangi bir elemanda görülen etkiye eşittir. Sonra ideal ve gerçek kaynaklar incelenir; kaynak dönüşümü de Norton ve Thevenin teoremlerine götürür. Bu teoremler şunu söyler: bir devrede seçilen herhangi iki düğümden bakıldığında, içeride dirençler, bağımlı ve bağımsız kaynaklardan oluşan çok karmaşık bir devre olsa bile, bu iki uçtan görülen eşdeğer bir gerilim kaynağı ile direnç (ya da bir akım kaynağı ile direnç) bulunabilir. Yüz elemanlı bir devre bile ilgilenilen uçlardan bakıldığında bir kaynak ve bir dirence indirgenebilir.

## 2. Doğrusallık

### 2.1 Tanım

Girdisi $x$, çıktısı $f(x)$ olan bir kara kutu (black box) düşünelim. Girdi olarak $x$ yerine $ax$ verildiğinde çıktı $a\,f(x)$ oluyorsa, yani

$$f(ax) = a\,f(x)$$

sağlanıyorsa bu sistem doğrusaldır (linear).

### 2.2 Ohm yasası bir doğrusal sistemdir

Direnç elemanında uçlara uygulanan gerilim ile içinden geçen akım $R$ direnciyle bağlıdır. Gerilim girdi, akım çıktı olarak düşünülürse $i = v/R$ ilişkisi sıfırdan geçen bir doğrudur. Gerilim iki katına çıkarıldığında akım da iki katına çıkar; çıktı bir sabitle çarpılmış olur.

### 2.3 Toplanabilirlik

Doğrusal sistemin ikinci önemli özelliği, toplam biçiminde verilen girdilerin çıktıda da ayrıştırılabilmesidir:

$$f(x_1 + x_2) = f(x_1) + f(x_2)$$

Bir direnç üzerine iki kaynak etki ediyorsa, bu iki kaynağın toplam etkisi tekil etkilerinin toplamına eşittir. Bu özellik süperpozisyona giden en önemli adımdır.

Hoca bunun daha önce adı konmadan kullanıldığını hatırlattı. Çevre analizinde iki çevrenin paylaştığı bir direnç (örneğin önceki derslerdeki 5 kΩ'luk $V_3$ elemanı) üzerinde iki sanal çevre akımı etkiliydi. Önce yalnız $I_1$ çevresi varmış gibi o elemandaki etki, sonra yalnız $I_2$ varmış gibi etki bulunur ve net akım $I_1 - I_2$ olarak yazılırdı. Bu da doğrusallığın bir sonucudur.

## 3. Doğrusal Olmayan Sistemler ve Elemanlar

### 3.1 Güç doğrusal değildir

Doğrusal dirençli bir devrede güç $P = IV$'dir (ekrandan, 00:15:00). Direnç için akım ya da gerilim cinsinden yazıldığında

$$P = IV = I^2 R = \frac{V^2}{R}$$

olur. Girdinin karesel etkisi olduğu için bu kara kutu doğrusal değildir: gerilim ya da akım $a$ katına çıkınca güç $a^2$ katına çıkar. Akım iki katına çıkarsa güç iki katına değil dört katına çıkar.

### 3.2 Doğrusal elemanlar

- Dirençler.
- Bobin (endüktans) elemanı; ileriki derslerde görülecek.
- Kondansatör (kapasite) elemanı.
- Bağımsız akım ve gerilim kaynakları.
- Doğrusal biçimde kontrol edilen bağımlı kaynaklar. Örneğin değeri $2v_x$ olan bağımlı bir gerilim kaynağı, kontrol büyüklüğünün bir sabitle çarpımı olduğu için doğrusaldır.

Devre teorisi dersinde temel olarak doğrusal elemanlar incelenir; doğrusal olmayan elemanlar daha çok elektronik devreler dersinin konusudur.

### 3.3 Doğrusal olmayan elemanlar

Slayttaki liste (ekrandan, 00:20:00):

- Diyotlar (ışık yayan diyotlar, LED dahil).
- Transistörler.
- SCR'ler.
- Manyetik anahtarlar.
- Doğrusal olmayan biçimde kontrol edilen bağımlı gerilim ve akım kaynakları.

**Diyot.** Hoca diyotun akım-gerilim karakteristiğini tahtada çizdi. Uygun yönde kutuplanan diyot, küçük bir gerilimden sonra akım geçirmeye başlar; yani küçük bir gerilimle "açılır". Ters yönde kutuplandığında belirli bir kırılma geriliminden sonra ters yönde çok yüksek akım geçirmeye başlar. Anahtar (switch) mantığında çalışması için bu kırılma bölgesine girmemesi gerekir. Gerilim iki katına çıktığında akım çok daha fazla artabilir; bu yüzden diyot doğrusal değildir.

**BJT.** Üç uçlu bir elemandır: baz (kontrol ucu), emetör ve kolektör. Baz ucunda çok küçük bir akım oluşturulduğunda kolektörden emetöre büyük bir akımın yolu açılır. Bu da bir anahtar mantığıdır.

**MOSFET.** İki uç arasına uygulanan küçük bir gerilim farkı, diğer yol üzerindeki akışı açar ya da kapatır. Transistörlerin akım-gerilim grafiklerinde farklı kontrol değerleri için farklı eğriler vardır (tahtada çizilen eğri ailesi, ekrandan, 00:20:00). Bu eğriler doğru değildir.

**Doğrusal olmayan bağımlı kaynak.** Değeri örneğin $2I_1^2$ olan bir bağımlı gerilim kaynağı, kontrol büyüklüğünün karesine bağlı olduğu için doğrusal değildir.

## 4. Süperpozisyona Giriş: İlk Örnek

### 4.1 Örnek 01 (ekrandan, 00:25:00)

Devre üç paralel koldan oluşur ve hepsi aynı iki düğüm arasındadır:

| Kol | Eleman | Yön / kutup |
|---|---|---|
| Sol | 10 Ω direnç | İstenen akım $I$ yukarıdan aşağı |
| Orta | 5 V gerilim kaynağı | Artı ucu üstte |
| Sağ | 2 A akım kaynağı | Akım yukarıdan aşağı |

İstenen: 10 Ω'dan geçen $I$ akımı.

Doğrusallıktan $f(x_1 + x_2) = f(x_1) + f(x_2)$ idi. Burada $f(x_1 + x_2)$, iki kaynak birlikte devredeyken 10 Ω'daki toplam akımdır. Yöntem şunu söyler: önce devrede yalnız 5 V kaynak varken etkiyi bul, sonra yalnız 2 A kaynak varken etkiyi bul, ikisini topla.

**Birinci alt devre (yalnız 5 V).** 2 A kaynağı devreden çıkarılmalı, yani o koldaki akım sıfır yapılmalıdır. Hoca öğrencilere bu kaynağın neyle değiştirileceğini sordu; bir öğrenci "voltmetre" dedi. Hoca bunun da doğru olduğunu söyledi: voltmetre açık devre eşdeğeri bir elemandır ve üzerinden akım geçirmez. Aranan cevap açık devredir. Devre 5 V kaynak ve 10 Ω'a indirgenir:

$$I_1 = \frac{5}{10} = 0.5 \text{ A}$$

**İkinci alt devre (yalnız 2 A).** 5 V kaynağı kaldırmak için iki ucu arasındaki gerilim farkı sıfır yapılmalıdır; bunu kısa devre sağlar. Bu durumda 10 Ω kısa devreye paralel kalır; akım kaynağının akımı kısa devre yolundan döner:

$$I_2 = 0$$

**Sonuç.** $I = I_1 + I_2 = 0.5$ A. Burada bir kaynağın katkısının sıfır çıkması bu devrenin özel bir durumudur; her zaman böyle olmaz.

> **Hocanın vurgusu:** Süperpozisyonla çözerken mutlaka bu yolu izleyin: devrede kaç kaynak varsa o kadar alt devre çizin, her birinin net etkisini bulun ve toplayın. $f(x_1 + x_2 + x_3 + x_4)$ isteniyorsa $f(x_1) + f(x_2) + \dots$ biçiminde o kadar alt devre olur.

### 4.2 Neden açık devre, neden kısa devre?

**Soru:** 2 A kaynağını devreden çıkarırken neden açık devre koyduk?

**Cevap:** Amaç kaynağı sıfırlamaktır. Akım kaynağını sıfırlamak, o koldan geçen akımı sıfır yapmak demektir; bunu açık devre sağlar. Gerilim kaynağı için ise 5 V, bir düğümün diğerine göre 5 V daha yüksek gerilimde olması demektir. Bunu sıfırlamak, o iki düğüm arasındaki gerilim farkını sıfır yapmak demektir; bunu kısa devre sağlar.

## 5. Doğrusallık ile Devre Çözümü

### 5.1 Örnek 4 (ekrandan, 00:30:00)

Devre (soldan sağa, alt hat toprak):

| Konum | Eleman | Akım |
|---|---|---|
| En sol dikey kol | $I_s = 15$ A akım kaynağı, yukarı yönlü | — |
| Üst kol | 6 Ω | $I_4$ (sağa) |
| Düğüm 2 ($V_2$) → toprak | 7 Ω | $I_3$ (aşağı) |
| Üst kol | 2 Ω | $I_2$ (sağa) |
| Düğüm 1 ($V_1$) → toprak | 4 Ω | $I_1$ (aşağı) |
| Üst kol, sonra sağ dikey kol | 3 Ω ve 5 Ω seri | $I_0$ (aşağı) |

Soru: $I_0 = 1$ A varsayıp doğrusallıkla gerçek $I_0$ değerini bulun. Hoca soruyu iki yönlü okudu: kaynak değeri bilinmeseydi ve $I_0 = 1$ A olsaydı $I_s$ ne olurdu; $I_s = 15$ A iken $I_0$ ne olur?

Çözüm $I_0 = 1$ A varsayımıyla geriye doğru ilerler:

- 3 Ω ve 5 Ω seri kol ile 4 Ω kolu aynı $V_1$ düğümüne bağlı ve paraleldir. Bu koldaki akım bilindiği için gerilim buradan hesaplanır: $V_1 = (3 + 5) I_0 = 8$ V.
- $I_1 = V_1 / 4 = 2$ A.
- Düğüm 1'de KCL: $I_2 = I_1 + I_0 = 3$ A.
- 2 Ω üzerinde: $\dfrac{V_2 - V_1}{2} = I_2$, buradan $V_2 = V_1 + 2 I_2 = 8 + 6 = 14$ V.
- $I_3 = V_2 / 7 = 2$ A.
- Düğüm 2'de KCL: $I_4 = I_3 + I_2 = 5$ A. Bu da $I_s$'dir.

Demek ki $I_0 = 1$ A iken $I_s = 5$ A. Gerçek kaynak 15 A, yani 3 katıdır. Devre doğrusal olduğu için çıktı da 3 katına çıkar: $I_0 = 3$ A. Devreyi 15 A için baştan çözmeye gerek kalmaz.

**Soru:** Diğer akımlar için de aynı şeyi söyleyebilir miyiz?

**Cevap:** Hoca $V_2$ için $15 \cdot 6 = 90$, $90/7$ gibi bir hesap denedi, birebir bir oran oluşmadığını, gerilim ve akım bölücü yapılar yüzünden başka elemanlar için doğrudan 3 kat demenin mümkün görünmediğini, $I_0$ ile $I_s$ arasında ise doğrusallık olduğunu söyledi. Devre çözülünce $I_s$, $I_0$'ın bir katsayıyla çarpımı ($a \cdot I_0$) olarak çıkar.

> **Ders sonrası not:** Hoca diğer akımların aynı oranda ölçeklenmeyebileceğini söyledi; doğrusu, tek bağımsız kaynaklı doğrusal bir devrede bütün akım ve gerilimler kaynak değeriyle orantılıdır. $I_s = 15$ A için $I_1 = 6$ A, $I_2 = 9$ A, $I_3 = 6$ A, $I_4 = 15$ A, $V_1 = 24$ V, $V_2 = 42$ V olur (python ile doğrulandı). Derste denenen $90/7$ hesabı büyük olasılıkla eleman değerlerinin yanlış eşleştirilmesinden kaynaklandı.

### 5.2 Örnek 5 (derste sözlü, 00:37:33)

Benzer bir soruda $V_0$ için varsayımsal bir değer verilip kaynağın değeri soruluyor, sonra kaynak 40 V iken $V_0$ isteniyor. $V_0$ 8 Ω üzerindeki gerilimdir; aynı akım toplam 20 Ω'luk yoldan da geçer. Bu yüzden kaynak gerilimi

$$V_s = \frac{V_0}{8} \cdot 20 = 2.5\,V_0$$

olur. Girdi ile çıktı arasındaki sabit 2.5'tir. $V_s = 40$ V için $V_0 = 40 / 2.5 = 16$ V.

<!-- BELİRSİZ: Örnek 5'in devre şekli karelerde yok; 8 Ω ve 20 Ω ilişkisi yalnız altyazıdan alındı. -->

### 5.3 Süperpozisyonun ileride kullanımı

Şimdiye kadar görülen devreler yalnız DC kaynaklıdır. Elektronik devreler dersinde karma kaynaklı devreler görülecektir. Örneğin bir kuvvetlendirici devrede transistörün çalışabilmesi için belirli bir gerilim aralığında şartlandırılması (kutuplanması) gerekir; bu DC kaynakla yapılır. Kuvvetlendirilecek işaret ise küçük genlikli bir AC işarettir. Böyle bir devre süperpozisyonla çözülür: önce yalnız DC kaynakla transistörün çalışma şartları bulunur; bu şartlar kuvvetlendirme miktarını belirler. Sonra yalnız AC kaynakla işaretin ne kadar kuvvetlendirildiği hesaplanır.

## 6. Süperpozisyon İlkesi ve Uygulama Kuralları

Slayttaki tanım (ekrandan, 00:40:00):

- Bir elemanın uçlarındaki gerilim, ona etki eden her bağımsız kaynağın o elemanda oluşturduğu gerilimlerin cebirsel toplamıdır.
- Bir elemandan geçen akım, ona etki eden her bağımsız kaynağın o elemandan geçirdiği akımların cebirsel toplamıdır.

Uygulama kuralları:

- Bağımsız kaynakların her biri sırayla tek başına devrede bırakılır, diğer bağımsız kaynaklar kapatılır. Kaç bağımsız kaynak varsa o kadar alt devre çözülür.
- Bağımlı kaynaklar kapatılmaz; her alt devrede kalır.
- Gerilim kaynağını kapatmak, yerine kısa devre koymaktır. Akım kaynağını kapatmak, yerine açık devre koymaktır.
- Her alt devrede ilgilenilen büyüklüğün etkisi bulunur, sonra etkiler toplanır.
- Bazı elemanlar kısa ya da açık devreyle değiştirilse bile, aranan büyüklüğün akım ve gerilim referans yönü bütün alt devrelerde aynı olmalıdır.

> **Hocanın vurgusu:** Bir alt devrede yukarı yönlü, diğerinde aşağı yönlü akım etkisi hesaplanırsa cebirsel toplam hatalı olur. Önce sabit bir referans yönü belirleyin, sonra kaynakları tek tek çıkararak bu yöndeki etkileri bulun.

## 7. Süperpozisyon Örnekleri

### 7.1 Örnek 6: üç bağımsız kaynak (ekrandan, 00:45:00)

Devrede 3 V gerilim kaynağı ($V_1$), $R_1 = 50$ Ω, $R_3 = 20$ Ω, $R_2 = 30$ Ω ile 2 A ve 1 A akım kaynakları vardır. İstenen, ana koldaki ($R_1$ kolu) akımdır. Üç bağımsız kaynak olduğu için üç alt devre çözülür:

- Yalnız 3 V: 2 A ve 1 A açık devre.
- Yalnız 2 A: 3 V kısa devre, 1 A açık devre.
- Yalnız 1 A: 3 V kısa devre, 2 A açık devre.

Ekranda görülen birinci alt devre ("#1: Replace I1 and I2 with Open Circuits"):

| Eleman | Bağlantı |
|---|---|
| 3 V kaynak ($V_1$) | Sol dikey kol, artı ucu üstte |
| $R_1 = 50$ Ω | Kaynağın üst ucundan orta düğüme (A) |
| $R_3 = 20$ Ω | A düğümünden alt hatta (toprak) |
| $R_2 = 30$ Ω | A düğümünden yukarı çıkıp sağdaki B düğümüne |
| Açık uçlar | A–B arasında ve B ile alt hat arasında kaynakların yerleri boş |

**Birinci alt devre.** $R_2$'nin bir ucu boşta olduğu için o kola akım akmaz. Akım yalnız 3 V, $R_1$ ve $R_3$'ten oluşan çevrede akar:

$$I_{A1} = \frac{3}{50 + 20} = \frac{3}{70} \approx 42.9 \text{ mA}$$

(Hoca diğer akımlarla karışmasın diye ana kol akımına $I_A$ adını verdi.)

**İkinci alt devre (yalnız 1 A).** 3 V kısa devre olunca 50 Ω ile 20 Ω paralel olur, bunlar 30 Ω'a seridir. 1 A, $R_2$ üzerinden A düğümüne ulaşır ve $R_1$ ile $R_3$ arasında bölünür.

> **Ders sonrası not:** Hoca bu alt devrede A düğümünün gerilimini 30 V, ana kol katkısını $(0 - 30)/50$ olarak söyledi; ardından slaytta verilen 14.3 değerinin bulduklarıyla eşdeğer olduğunu söyledi. Doğrusu, 1 A'nın akım bölücüyle dağılmasıdır: A düğümünün gerilimi büyüklük olarak $1 \cdot (50 \parallel 20) \approx 14.29$ V (slayttaki 14.3), $R_1$'deki katkı $1 \cdot \dfrac{20}{50+20} \approx 285.7$ mA'dir. 30 Ω, 1 A'lık kaynağa seri olduğu için A düğümünün gerilimini etkilemez.

**Üçüncü alt devre (yalnız 2 A).** Hoca bir noktadan başlayıp devreyi dolaştığında hiçbir kaynağa denk gelmeden başladığı yere döndüğünü gösterdi: bu alt devre $R_1$ ve $R_3$ kollarına akım sürmez, katkısı sıfırdır. Sıfır olduğu için yönün önemi kalmaz.

**Sonuç.** İlk iki alt devrenin katkısı toplanır. Hoca sonucu "328 küsur miliamper" olarak verdi:

$$I_A = \frac{3}{70} + \frac{20}{70} = \frac{23}{70} \approx 328.6 \text{ mA}$$

(python ile doğrulandı). Süperpozisyon yalnız tek bir kol akımı için değil, ilgilenilen her elemanın gerilim ve akımı için kullanılabilir.

<!-- BELİRSİZ: Özgün devrenin tam şekli karelerde görünmüyor, yalnız birinci alt devre ekranda. 1 A ve 2 A kaynaklarının yeri ve yönü altyazıdan ve slayttaki 14.3 değerinden çıkarıldı; iki katkının aynı yönde toplandığı hocanın verdiği 328 mA sonucundan anlaşılıyor. -->

### 7.2 Örnek 7 (ekrandan, 00:50:00)

Devre:

| Eleman | Bağlantı |
|---|---|
| 6 V gerilim kaynağı | Sol dikey kol, artı ucu üstte |
| 8 Ω | Üst kol |
| 4 Ω | Orta dikey kol, gerilimi $v$ (artı üstte) |
| 3 A akım kaynağı | Sağ dikey kol, yukarı yönlü |

Soru: Süperpozisyon teoremiyle devredeki $v$ gerilimini bulun.

**Birinci alt devre (yalnız 6 V).** 3 A açık devre yapılır. 6 V, seri 8 Ω ve 4 Ω'ya uygulanır; 4 Ω'daki gerilim gerilim bölücüyle bulunur:

$$v_1 = \frac{4}{4 + 8}(6) = 2 \text{ V}$$

**İkinci alt devre (yalnız 3 A).** 6 V kısa devre yapılır; 8 Ω ile 4 Ω paralel olur. Paralel dirençlerin gerilimleri eşit olduğundan 4 Ω'dan geçen akım 8 Ω'dan geçenin iki katıdır: 8 Ω'dan $x$, 4 Ω'dan $2x$, toplamda $3x = 3$ A, yani $x = 1$ A. Slayttaki biçimiyle:

$$i_3 = \frac{8}{4 + 8}(3) = 2 \text{ A}, \qquad v_2 = 4 i_3 = 8 \text{ V}$$

**Sonuç.** İki katkı da $v$ ile aynı yönde olduğu için toplanır:

$$v = v_1 + v_2 = 2 + 8 = 10 \text{ V}$$

Hoca süperpozisyonla ilgili bir sonraki örneği (benzer mantıkta olduğu için) öğrencilere bıraktı.

## 8. Bağımlı Kaynaklı Devrede Süperpozisyon

### 8.1 Örnek 9 (ekrandan, 00:55:00)

Bu devre öncekilerden farklıdır çünkü bir bağımlı kaynak içerir. Kural: yalnız bağımsız kaynaklar sırayla kapatılır, bağımlı kaynak devrede kalır.

Devrenin elemanları: 4 A akım kaynağı (sol kol, yukarı yönlü), 2 Ω (üst kol), 3 Ω ve 5 Ω (orta dikey kol, üst ve alt parça), 1 Ω ile $5 i_o$ akım kontrollü gerilim kaynağı (ortadaki yatay kol, kaynağın artı ucu solda), 4 Ω (sağ dikey kol), 20 V gerilim kaynağı (alt hat, sağda). $i_o$, 5 Ω'dan aşağı akan akımdır.

**Devre 1 (20 V kısa devre).** Üç çevreli bir devre kalır: $i_1$ (sol, 4 A'lık kaynağın olduğu göz), $i_2$ (üst sağ göz), $i_3$ (alt sağ göz), hepsi saat yönünde.

- Birinci çevrede akım kaynağı yalnız bu çevrededir, çevre akımını o belirler: $i_1 = 4$ A. (Ortak paylaşılan akım kaynağı, yani süper çevre durumu yoktur.)
- İkinci çevre: $3(i_2 - i_1) + 2 i_2 - 5 i_o' + 1(i_2 - i_3) = 0$. Düzenlenince $-3 i_1 + 6 i_2 - i_3 - 5 i_o' = 0$.
- Üçüncü çevre: $5(i_3 - i_1) + 1(i_3 - i_2) + 5 i_o' + 4 i_3 = 0$. Düzenlenince $-5 i_1 - i_2 + 10 i_3 + 5 i_o' = 0$.
- $i_o'$ de bir bilinmeyen olduğu için bir denklem daha gerekir: 5 Ω'un alt düğümünde $i_o' + i_3 = i_1$, yani $i_3 = 4 - i_o'$.

Dört bilinmeyen ($i_1, i_2, i_3, i_o'$) ve dört denklem vardır. Yerine koyunca $3 i_2 - 2 i_o' = 8$ ve $i_2 + 5 i_o' = 20$ elde edilir:

$$i_o' = \frac{52}{17} \text{ A}$$

> **Ders sonrası not:** Hoca üçüncü çevre denklemini söylerken önce $4 i_3$ terimini unuttu, sonra ekledi; ikinci çevre için de söylerken bir terimi $i_2 - i_1$ diye düzeltti. Yukarıdaki denklemler slayttaki biçimdir.

**Devre 2 (4 A açık devre).** Sol göz ortadan kalkar; iki çevreli bir devre kalır: $i_4$ (üst göz: 3 Ω, 2 Ω, 1 Ω ve bağımlı kaynak) ve $i_5$ (alt göz: 5 Ω, 1 Ω, bağımlı kaynak, 4 Ω, 20 V).

- $i_4$ çevresi: $3 i_4 + 2 i_4 - 5 i_o'' + 1(i_4 - i_5) = 0$, yani $6 i_4 - i_5 - 5 i_o'' = 0$.
- $i_5$ çevresi: $-20 + 5 i_5 + 1(i_5 - i_4) + 5 i_o'' + 4 i_5 = 0$, yani $-i_4 + 10 i_5 - 20 + 5 i_o'' = 0$.
- 5 Ω'dan geçen akım yalnız $i_5$'tir ama yönü terstir: $i_5 = -i_o''$.

Üç bilinmeyen, üç denklem. Düzenlenince $6 i_4 - 4 i_o'' = 0$ ve $i_4 + 5 i_o'' = -20$:

$$i_o'' = -\frac{60}{17} \text{ A}$$

**Sonuç.**

$$i_o = i_o' + i_o'' = \frac{52}{17} - \frac{60}{17} = -\frac{8}{17} \approx -0.4706 \text{ A}$$

(python ile doğrulandı). Bu örnekte görülen: bağımlı kaynak her alt devrede kalır; o alt devrede kontrol büyüklüğü ne ise etkisi ona göre oluşur. Hoca bu örneğin aynı zamanda çevre analizi için de bir alıştırma olduğunu belirtti.

## 9. İdeal ve Gerçek Kaynaklar

### 9.1 Gerilim kaynakları (ekrandan, 01:15:00)

İdeal gerilim kaynağı bağlandığı uçlar arasında kesinlikle $V_s$ gerilim farkını oluşturur. Slayttaki ifadeyle: ideal gerilim kaynağının iç direnci yoktur; devrenin geri kalanına güç vermek için gereken kadar akım üretebilir. Gerçek gerilim kaynağı ise ideal bir gerilim kaynağına seri bir dirençle modellenir; kaynağın verebileceği akım ve çıkış gerilimi sınırlıdır.

Hoca şu soruyu sordu: kaynağın bozucu (parazitik) bir direnci olsaydı onu kaynağa seri mi (kırmızı) yoksa paralel mi (mavi) yerleştirirdiniz?

**Soru:** Parazitik direnç paralel (mavi) konsa neden etkisi olmaz?

**Cevap (bir öğrenci):** Paralelde gerilimler aynı kaldığı için. Hoca doğruladı: ideal gerilim kaynağına paralel bir direnç, uçlarda yine $V_s$ görülmesini engellemez. Bozucu etki seri dirençle görülür.

Kaynağa bir yük direnci $R_L$ bağlandığında $V_s$'nin tamamının yükte düşmesi istenir. Ancak seri iç direnç $R_s$ yükle gerilim bölücü oluşturur ve gerilimin bir kısmı iç dirençte kaybolur:

$$I = \frac{V_s}{R_s + R_L}, \qquad V_L = R_L \cdot \frac{V_s}{R_L + R_s}$$

**Soru:** İdeal durumda iç direnç nedir? **Cevap:** Sıfır. **Soru:** İç direnç yerine iletkenlik düşünülseydi ideal durumda iletkenlik ne olurdu? **Cevap:** Sonsuz; ikisi birbirinin tersidir.

Yük direnci sıfır (uçlar kısa devre) ya da sonsuz (uçlar açık) olduğunda yükte çekilen güç sıfırdır: birinde direnç sıfır, diğerinde akım sıfırdır ($P = I^2R$ ve $P = V^2/R$).

### 9.2 Akım kaynakları (ekrandan, 01:20:00)

İdeal akım kaynağı bağlı olduğu kolda üzerinde yazan akımı mutlaka sağlar; devrenin geri kalanına güç vermek için gereken kadar gerilim üretebilir. Gerçek akım kaynağı ideal bir akım kaynağına paralel bir dirençle modellenir; en büyük gerilim ve akım sınırlıdır.

Hoca yine parazitik direncin yerini sordu (1: seri, 2: paralel). Seri bir direnç etkisizdir, çünkü ideal akım kaynağı o kolda yine aynı akımı oluşturur. Bozucu etki paralel dirençle görülür.

Yük direnci bağlandığında $V_L$ hem $R_s$ hem $R_L$ üzerindedir:

$$I_s = \frac{V_L}{R_s} + \frac{V_L}{R_L}$$

Yani akımın bir kısmı iç dirence ayrılır ve yüke $I_s$'nin tamamı aktarılamaz. Yük direnci sıfır ya da sonsuz olduğunda burada da yükteki güç sıfırdır.

### 9.3 $R_L = R_s$ özel durumu (ekrandan, 01:35:00)

Slayttaki sorular: gerçek gerilim kaynağında $R_s = R_L$ iken yükteki gerilim nedir? Gerçek akım kaynağında $R_s = R_L$ iken yükten geçen akım nedir?

Gerilim kaynağı için $V_L = R_L \dfrac{V_s}{R_L + R_s}$ idi; $R_L = R_s$ ise

$$V_L = \frac{V_s}{2}$$

Akım kaynağı için hoca tahtada adım adım türetti:

- $I_s = \dfrac{V_L}{R_s} + \dfrac{V_L}{R_L} = V_L \left(\dfrac{1}{R_s} + \dfrac{1}{R_L}\right)$
- $V_L = I_L R_L$ yerine konursa $I_s = I_L R_L \dfrac{R_L + R_s}{R_L R_s}$
- Buradan

$$I_L = I_s \frac{R_s}{R_L + R_s}$$

$R_L = R_s$ ise $I_L = I_s/2$ olur.

Bu özel durum en büyük güç aktarımına bağlanır: gerçek bir kaynağa farklı büyüklükte yük dirençleri bağlandığında yükte en büyük güç, yük direnci iç dirence eşit olduğunda elde edilir. Sebebi şudur: yük gücü $V_L \cdot I_L$'dir. Akımı artırmak için daha küçük direnç takılırsa yükteki gerilim düşer; gerilimi artırmak için daha büyük direnç takılırsa bu kez iç direnç tarafı gücün çoğunu tüketmeye başlar. Yük gücü $R_L$'ye göre ikinci dereceden, ters bir parabol gibi davranır ve tepe noktası iç direncin yüke eşit olduğu yerdir. Hoca bunun matematiksel olarak en büyük güç aktarımı konusunda gösterileceğini söyledi.

Özet slaytında (ekrandan, 01:45:00) şu da yazar: $R_L = R_s$ iken $R_L$'de harcanan güç, ideal kaynağın ürettiği gücün %50'sidir.

> **Ek bilgi (derste anlatılmadı):** Gerçek gerilim kaynağında $P_L = \dfrac{V_s^2 R_L}{(R_s + R_L)^2}$ yazılıp $R_L$'ye göre türev alınırsa en büyük değer $R_L = R_s$'de bulunur ve $P_{L,\max} = \dfrac{V_s^2}{4 R_s}$ olur. Bu durumda iç dirençte de aynı güç harcandığı için verim %50'dir.

## 10. Kaynak Dönüşümü ve Eşdeğerlik

### 10.1 Tanım (ekrandan, 01:25:00 ve 01:30:00)

Seri-paralel birleştirme ve Y-Δ dönüşümünün devreleri sadeleştirmeye yardım ettiği görülmüştü. Kaynak dönüşümü de devreleri sadeleştirmek için bir başka araçtır. Bu araçların temelinde eşdeğerlik kavramı vardır: eşdeğer devre, $v$-$i$ karakteristiği özgün devreyle aynı olan devredir.

Kaynak dönüşümü, seri $R$ dirençli bir $v_s$ gerilim kaynağını paralel $R$ dirençli bir $i_s$ akım kaynağıyla değiştirmektir; tersi de geçerlidir. Yani devrede görülen her ideal olmayan gerilim kaynağı ideal olmayan bir akım kaynağıyla değiştirilebilir ve tersi.

Ne işe yarar? Örneğin tek düğüm çiftli bir devrede, ideal olmayan gerilim kaynağı dışında bütün elemanlar paralel olsun. Bu kaynak ideal olmayan akım kaynağına dönüştürülünce o da paralel hâle gelir ve devre tek düğüm çiftli devre olarak kolayca çözülür. Kaynak dönüşümü ayrıca Thevenin ve Norton teoremlerine götürür: pasif elemanlardan oluşan karmaşık bir devre, seçilen iki düğümden bakıldığında ideal olmayan bir akım kaynağı ya da ideal olmayan bir gerilim kaynağı olarak yazılabilir.

### 10.2 Eşdeğerlik şartları ve $v_s = i_s R$ türetmesi

Soldaki devre $v_s$ ve seri $R$, sağdaki devre $i_s$ ve paralel $R$ olsun; her ikisinin uçları $a$ ve $b$. İki şart vardır:

**Şart 1: açık devre gerilimleri eşit.** Soldaki devrede $a$-$b$ uçları boşta iken $R$ üzerinden akım akar mı? Bir öğrenci "akım akmaz" dedi. Akım akmadığı için $R$ üzerinde gerilim düşümü olmaz; KVL'den $v - v_s = 0$, yani uçlarda $v_s$ görülür. Sağdaki devrede uçlar boşta iken $i_s$ akımının hepsi $R$ üzerinden geçer ve uçlarda $i_s R$ görülür. Eşitlikten

$$v_s = i_s R$$

**Şart 2: kısa devre akımları eşit.** Sağdaki devrede $a$ ile $b$ kısa devre yapılınca akım hiç direnci olmayan yolu tercih eder; kısa devreden $i_s$ geçer. Soldaki devrede de aynı akım geçmelidir: KVL'den $i_s R - v_s = 0$, yine $v_s = i_s R$.

Yani $R$ aynı kalmak şartıyla kullanılan gerilim $v_s$ ise eşdeğer akım kaynağı $i_s = v_s / R$ olmak zorundadır. Bu basit durumda iki şart aynı sonucu verdi.

> **Hocanın vurgusu:** Daha karmaşık devrelerde eşdeğerlikten söz edebilmek için iki şartın da sağlanması gerekir.

Kaynak dönüşümü yalnız bağımsız kaynaklar için değil, bağımlı kaynaklar için de geçerlidir.

### 10.3 Eşdeğerlik ve akım-gerilim karakteristiği (ekrandan, 01:40:00)

Slayttaki ifade: her iki devrede $R_L$ aynı olmalı; soldaki devredeki $I_L$ ve $V_L$, sağdaki devredekine eşit olmalıdır.

Hoca bunu kara kutu benzetmesiyle anlattı. İçinde karmaşık devre olan bir kara kutunun ikinci bir kara kutuya eşit olup olmadığını anlamak için iki kutunun uçlarına bir voltmetre bağlanır ve okumaların aynı olup olmadığına bakılır; sonra uçlar bir ampermetre ile birleştirilir ve akımlar karşılaştırılır. İkisi de eşitse devreler eşdeğerdir denir. Bunun başka bir söylenişi, iki kara kutunun akım-gerilim karakteristiklerinin aynı olmasıdır.

Gerçek kaynaklar için yapılan test, karakteristiğin yalnız iki noktasına bakmaktır: $R_L = 0$ (kısa devre) ve $R_L = \infty$ (açık devre). Genel tanım ise, bağlanan yük direncinin bütün değerleri için okunan gerilim ve akımın iki devrede de eşit olmasıdır.

> **Ders sonrası not:** Hoca bir yerde "terminaller açıkken gerilimi ölçmek, yük direncinin sıfır olduğu durum" dedi; hemen ardından doğrusunu söyledi: açık devre $R_L = \infty$, kısa devre $R_L = 0$ durumudur.

Özet slaytındaki (ekrandan, 01:45:00) iki gözlem:

- Gerçek akım kaynağındaki paralel (şönt) direnç küçüldükçe, aynı yük davranışı için ideal akım kaynağının ürettiği akım artmalıdır.
- Gerçek gerilim kaynağındaki seri direnç büyüdükçe, aynı yük davranışı için ideal gerilim kaynağının ürettiği gerilim artmalıdır.

### 10.4 Sayısal örnek: 18 V, 3 kΩ

Slayttaki bir örnekte 18 V ve 3 kΩ'luk gerçek bir gerilim kaynağı vardı. Aynı direnç kullanılırsa eşdeğer akım kaynağı

$$I_s = \frac{18 \text{ V}}{3 \text{ k}\Omega} = 6 \text{ mA}$$

ve buna paralel 3 kΩ'dur. Slaytın devamında farklı iç direnç değerleri için yük akımı ve güç hesaplanmış; başlangıçta hesaplanan 2 mA'lik yük akımının 3 kΩ'da aynı çıktığı ve en yüksek gücün iç direnç yük direncine eşitken oluştuğu görülmüştür. Hoca bu kısmı en büyük güç aktarımı konusunda matematiksel olarak ele alacağını söyleyerek geçti.

<!-- BELİRSİZ: 18 V / 3 kΩ örneğinin devre şekli ve yük direnci değeri karelerde görünmüyor; değerler altyazıdan alındı. -->

## 11. Kaynak Dönüşümü ile Devre Çözümü

### 11.1 Örnek 12 (ekrandan, 01:50:00)

Hoca bu örneğin bu hafta için önemli olduğunu söyledi. Soru: Kaynak dönüşümünü kullanarak devredeki $v_o$ gerilimini bulun.

Özgün devre (soldan sağa, alt hat ortak):

| Konum | Eleman |
|---|---|
| Dikey kol 1 | 4 Ω |
| Dikey kol 2 | 3 A akım kaynağı, aşağı yönlü |
| Üst kol | 2 Ω |
| Dikey kol 3 | 8 Ω, gerilimi $v_o$ (artı üstte) |
| Üst kol | 3 Ω |
| Dikey kol 4 | 12 V gerilim kaynağı, artı ucu üstte |

**Adım 1: 3 A ∥ 4 Ω → gerilim kaynağı.** İdeal olmayan akım kaynağının yerine bir gerilim kaynağı ve ona seri bir direnç gelir. Direnç aynıdır (4 Ω). Gerilimin büyüklüğü $3 \cdot 4 = 12$ V'tur. Yönü: uçlar açık iken akım kaynağı akımı aşağı sürdüğü için 4 Ω'un alt ucu artı, üst ucu eksi olur; yani uçlardan bakıldığında $-12$ V görülür. Eşdeğer gerilim kaynağı da aynı uç gerilimini verecek biçimde, artı ucu altta, eksi ucu üstte bağlanır.

Direncin yeri: referans düğümü alt hat seçilmiştir. 4 Ω direnç alt tarafa konursa referans ile kaynak arasında bir gerilim düşümü oluşur ve düğüm gerilimleri bozulur. Bu yüzden direnç üst tarafa, referansın ters tarafına konur. Böylece 4 Ω ile 2 Ω seri olur: 6 Ω.

Aynı adımda sağdaki 12 V ve seri 3 Ω da dönüştürülür: $12/3 = 4$ A'lik, yukarı yönlü bir akım kaynağı ve ona paralel 3 Ω.

**Adım 2: 12 V + seri 6 Ω → akım kaynağı.** Paralel direnç yine aynıdır (6 Ω). Akımın büyüklüğü $12/6 = 2$ A. Yön: uçlar kısa devre yapılınca akımın eksiden artıya, yani bu durumda yukarı doğru dolaşacağı görülür; eşdeğer devrede de uçlar kısa devre yapılınca aynı yönde akım akmalıdır. Bu da 2 A'lik kaynağın aşağı yönlü olması demektir.

**Adım 3: birleştirme.** Devre artık tamamen paraleldir: aşağı yönlü 2 A, 6 Ω, 8 Ω ($v_o$), 3 Ω, yukarı yönlü 4 A. 6 Ω direnç sağa alınabilir; bu topolojiyi bozmaz. 3 Ω ile 6 Ω paraleldir:

$$\frac{1}{R_{\text{eş}}} = \frac{1}{3} + \frac{1}{6} \Rightarrow R_{\text{eş}} = 2 \text{ Ω}$$

8 Ω korunur çünkü üzerindeki gerilim istenmektedir. Paralel akım kaynakları KCL ile birleştirilir; yönleri ters olduğu için farkları alınır: $4 - 2 = 2$ A (yukarı yönlü).

**Adım 4: akım bölücü.** Elde kalan: 8 Ω ∥ 2 Ω ∥ 2 A. 8 Ω, 2 Ω'un 4 katıdır; 8 Ω'dan bir birim akım geçerse 2 Ω'dan dört birim geçer, toplam $5x = 2$ A, $x = 0.4$ A. Slayttaki biçimiyle:

$$i = \frac{2}{2 + 8}(2) = 0.4 \text{ A}, \qquad v_o = 8 i = 8(0.4) = 3.2 \text{ V}$$

ya da

$$v_o = (8 \parallel 2)(2 \text{ A}) = \frac{8 \times 2}{10}(2) = 3.2 \text{ V}$$

(python ile doğrulandı). Devre yalnız kaynak dönüşümüyle çözülmüş oldu. Hoca bir sonraki aşamanın Thevenin ve Norton eşdeğerleri olduğunu söyleyerek bu haftanın konularını tamamladı.

## Örnek Sorular

**Soru 1** (ekrandan, 00:25:00). 10 Ω direnç, artı ucu üstte 5 V kaynak ve aşağı yönlü 2 A akım kaynağı aynı iki düğüm arasında paraleldir. 10 Ω'dan aşağı akan $I$ akımını süperpozisyonla bulun.

> **Çözüm (derste verildi):** Yalnız 5 V: $I_1 = 5/10 = 0.5$ A. Yalnız 2 A (5 V kısa devre): $I_2 = 0$. $I = 0.5$ A.

**Soru 2** (ekrandan, 00:30:00). Bölüm 5.1'deki devrede $I_0 = 1$ A varsayın ve doğrusallıkla $I_s = 15$ A iken gerçek $I_0$ değerini bulun.

> **Çözüm (derste verildi):** $V_1 = 8$ V, $I_1 = 2$ A, $I_2 = 3$ A, $V_2 = 14$ V, $I_3 = 2$ A, $I_4 = I_s = 5$ A. Oran $15/5 = 3$, $I_0 = 3$ A.

**Soru 3** (derste sözlü, 00:37:33). Bir devrede kaynak ile çıkış arasında $V_s = 2.5\,V_0$ ilişkisi vardır. $V_s = 40$ V iken $V_0$ nedir?

> **Çözüm (derste verildi):** $V_0 = 40 / 2.5 = 16$ V.

**Soru 4** (ekrandan, 00:50:00). Bölüm 7.2'deki devrede (6 V, 8 Ω, 4 Ω, 3 A) süperpozisyon teoremiyle $v$'yi bulun.

> **Çözüm (derste verildi):** $v_1 = \frac{4}{12}(6) = 2$ V, $i_3 = \frac{8}{12}(3) = 2$ A, $v_2 = 8$ V, $v = 10$ V.

**Soru 5** (ekrandan, 00:55:00). Bölüm 8.1'deki bağımlı kaynaklı devrede süperpozisyonla $i_o$'yu bulun.

> **Çözüm (derste verildi):** $i_o' = 52/17$ A, $i_o'' = -60/17$ A, $i_o = -8/17 \approx -0.4706$ A.

**Soru 6** (ekrandan, 01:35:00). Gerçek bir gerilim kaynağında $R_s = R_L$ iken yük gerilimi nedir? Gerçek bir akım kaynağında $R_s = R_L$ iken yük akımı nedir?

> **Çözüm (derste verildi):** $V_L = V_s/2$; $I_L = I_s \dfrac{R_s}{R_L + R_s} = I_s/2$.

**Soru 7** (ekrandan, 01:50:00). Bölüm 11.1'deki devrede kaynak dönüşümüyle $v_o$'yu bulun.

> **Çözüm (derste verildi):** Dönüşümlerle devre 8 Ω ∥ 2 Ω ∥ 2 A'e indirgenir; $i = 0.4$ A, $v_o = 3.2$ V.

## Dersin Toparlaması

Bu derste önce doğrusallık tanımlandı: $f(ax) = a f(x)$ ve $f(x_1 + x_2) = f(x_1) + f(x_2)$. Direnç, bobin, kondansatör, bağımsız kaynaklar ve doğrusal kontrollü bağımlı kaynaklar doğrusal; diyot, transistör ve doğrusal olmayan kontrollü kaynaklar ise doğrusal değildir. Güç de akım ve gerilime göre doğrusal değildir. Doğrusallık, tek kaynaklı bir devrede çıktıya varsayımsal bir değer verip geriye doğru çözme ve sonra ölçekleme imkânı verir. Doğrusallığın sonucu olan süperpozisyon ilkesinde her bağımsız kaynak sırayla tek başına bırakılır (gerilim kaynakları kısa, akım kaynakları açık devre yapılır), bağımlı kaynaklar devrede kalır ve sabit referans yönlerinde bulunan katkılar cebirsel toplanır.

Dersin ikinci yarısında ideal ve gerçek kaynaklar karşılaştırıldı: gerçek gerilim kaynağı seri, gerçek akım kaynağı paralel iç dirençle modellenir; yük direnci iç dirence eşit olduğunda yükte gerilim ya da akımın yarısı görülür ve bu durum en büyük güç aktarımına işaret eder. Eşdeğerlik, iki devrenin $v$-$i$ karakteristiklerinin aynı olmasıdır ve buradan kaynak dönüşümü kuralı $v_s = i_s R$ çıkar. Kaynak dönüşümüyle bir devrenin adım adım sadeleştirilerek çözüldüğü örnekle konu tamamlandı. Bir sonraki aşama Thevenin ve Norton eşdeğerleri ile en büyük güç aktarımı teoremidir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
