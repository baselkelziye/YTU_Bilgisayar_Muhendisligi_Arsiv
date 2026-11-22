# Ders 5 Genişletilmiş Notu: Düğüm ve Çevre Analizi Karşılaştırması, Doğrusallık, Süperpozisyon ve Kaynak Dönüşümü

> Kayıt iki parçadır; arşivde parçalar yanlış sırada birleştirildiği için altyazıdaki sıra düzeltildi ve saat damgaları düzeltilmiş altyazıya göredir.

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Düğüm ve Çevre Analizi: Aynı Devrede Karşılaştırma
- 2. Doğrusallık (Linearity)
- 3. Doğrusal ve Doğrusal Olmayan Devre Elemanları
- 4. Süperpozisyona Giriş
- 5. Doğrusallık Örnekleri ve Ters Yönden Çözüm
- 6. Süperpozisyon Adımları ve Üç Kaynaklı Örnek
- 7. Süperpozisyon Alıştırmaları
- 8. Bağımlı Kaynaklı Devrede Süperpozisyon
- 9. Kaynak Dönüşümü (Source Transformation)
- 10. Kaynak Dönüşümüyle Devre Sadeleştirme
- Örnek Sorular

## 1. Düğüm ve Çevre Analizi: Aynı Devrede Karşılaştırma

Ders, önceki derste görülen düğüm (nodal) ve çevre (mesh) analizlerinin son bir örnekle bağlanmasıyla başladı. Hoca, şimdiye kadar yapılan işin özünde KVL ve KCL denklemlerini düğümde gerilim, çevrede akım cinsinden yazmak olduğunu hatırlattı. Bu bölümde aynı devre önce düğüm analiziyle, sonra çevre analiziyle çözüldü. Bundan sonra düğüm ve çevre analizi ayrıca işlenmeyecek, ama soru çözümlerinde kullanılmaya devam edecek.

### 1.1 Devre

Devre şöyledir (ekrandan, 00:05:41): Solda artı ucu yukarıda 100 V gerilim kaynağı vardır. Kaynağın üst ucundan 8 Ω ile $v_1$ düğümüne gelinir. $v_1$ düğümünden toprağa 4 Ω bağlıdır. $v_1$ ile $v_2$ arasında 2 Ω vardır ve bu dirençten soldan sağa akan akım $i_x$ olarak gösterilmiştir. $v_2$'den toprağa 3 Ω, $v_2$ ile $v_3$ arasında 10 Ω, $v_3$'ten toprağa 5 Ω bağlıdır. Üstte, 10 Ω'a paralel olacak şekilde $v_3$'ten $v_2$'ye doğru akım veren 8 A'lik bir akım kaynağı bulunur. Soru $i_x$'i istemektedir.

### 1.2 Düğüm analiziyle çözüm

Önce referans düğümü seçilir. Burada referans (toprak) alt düğüme konmuştur. Hoca bunun faydasını şöyle açıkladı: 100 V kaynağın alt ucu toprağa bağlı olduğundan, üst ucunun gerilimi doğrudan 100 V olarak alınabilir.

Düğüm analizinde mantık şudur: Önce düğüme giren ve çıkan akımlarla KCL yazılır (ör. girenlerin toplamı çıkanların toplamına eşittir), sonra her akım düğüm gerilimleri cinsinden ifade edilir. Örneğin $i_x$ soldan sağa aktığı için $i_x = (v_1 - v_2)/2$ yazılır.

**$v_1$ düğümü.** Bütün akımlar düğümden çıkıyormuş gibi yazılır: 8 Ω'luk koldan $(v_1 - 100)/8$, 4 Ω'luk koldan $(v_1 - 0)/4$, 2 Ω'luk koldan $(v_1 - v_2)/2$. Toplamları sıfırdır:

$$\frac{v_1 - 100}{8} + \frac{v_1}{4} + \frac{v_1 - v_2}{2} = 0 \;\Rightarrow\; 0{,}875\,v_1 - 0{,}5\,v_2 = 12{,}5$$

Sağ taraftaki 12,5, sabit terimin ($100/8$) eşitliğin öbür tarafına geçmesinden gelir.

**$v_2$ düğümü.** Çıkan akımlar $(v_2 - v_1)/2$, $v_2/3$ ve $(v_2 - v_3)/10$'dur. 8 A ise düğüme girer. Çıkanların toplamı 8 A'e eşittir; 8 eşitliğin öbür tarafına alınınca $-8$ olur (ara adım eklendi):

$$\frac{v_2 - v_1}{2} + \frac{v_2}{3} + \frac{v_2 - v_3}{10} - 8 = 0$$

**$v_3$ düğümü.** Buradan 8 A çıkar. Diğer çıkan akımlar $(v_3 - v_2)/10$ ve $v_3/5$'tir. Hepsi çıkan olarak alınıp toplam sıfıra eşitlenir:

$$\frac{v_3 - v_2}{10} + \frac{v_3}{5} + 8 = 0$$

Üç denklem, üç bilinmeyen vardır. Bir denklemde bulunmayan değişkenin katsayısı sıfır yazılarak denklem sistemi matris biçimine getirilir. Çözüm $v_1 = 25{,}89$ V, $v_2 = 20{,}31$ V'tur (python ile doğrulandı). Soru $v_3$'ü istemediği için doğrudan

$$i_x = \frac{v_1 - v_2}{2} = \frac{25{,}89 - 20{,}31}{2} = 2{,}79 \text{ A}$$

bulunur.

<!-- BELİRSİZ: Ekranda yazılan 2. ve 3. düğüm denklemlerinin düzenlenmiş katsayıları karede görülmedi; yukarıdaki denklemler devreden kurulmuştur. -->

Hoca burada bir yorum ekledi: Akım yüksek potansiyelden düşük potansiyele akar. $v_1 > v_2$ çıktığı için $i_x$ pozitiftir. Eğer sonuçlar ters olsaydı, yani $v_2 > v_1$ çıksaydı, $i_x$'in negatif çıkacağı hesap yapmadan anlaşılırdı.

### 1.3 Çevre analiziyle çözüm

Çevre analizinin ilk adımı çevreleri (loop) tanımlamak ve her çevreye aynı yönde (burada saat yönünde) bir akım atamaktır. Devrede dört çevre vardır (ekrandan, 00:10:41): $i_1$ (100 V ve 4 Ω'luk çevre), $i_2$ (4 Ω, 2 Ω, 3 Ω'luk çevre), $i_3$ (3 Ω, 10 Ω, 5 Ω'luk çevre) ve üstte akım kaynağının bulunduğu $i_4$.

$i_4$ çevresinin dış kolunda yalnız 8 A'lik akım kaynağı vardır. Kaynağın yönü saat yönünün tersidir; bu yüzden doğrudan $i_4 = -8$ A yazılır. Böylece dört çevreden yalnız üç denklem yazmak gerekir (ekrandan, 00:15:41). $i_4$'ün etkisi yalnız ortak koldaki 10 Ω üzerinde görünür.

Hoca KVL'yi hatırlattı: Bir çevre üzerindeki elemanlarda düşen gerilimlerin toplamı sıfırdır. Burada akım yönü ve kutup (polarizasyon) önemlidir. Dirençlere başta kutup verilmediğinden, tanımlanan çevre akımının girdiği uç artı, çıktığı uç eksi kabul edilir. Gerilim kaynağının kutbu ise bellidir: $i_1$ kaynağa eksi ucundan girip artı ucundan çıktığı için kaynak denklemde $-100$ olarak yer alır.

Ortak dirençlerde iki yazım da doğrudur: İkinci çevrede 4 Ω için $4(i_2 - i_1)$ ya da $-4(i_1 - i_2)$ yazılabilir. Hoca kafa karışıklığını önlemek için, yazılan çevrenin kendi akımını öne almayı (yani $4(i_2 - i_1)$ yazmayı) önerdi. Denklemler (ekrandan, 00:15:41):

$$-100 + 8i_1 + 4(i_1 - i_2) = 0 \quad\Rightarrow\quad 12i_1 - 4i_2 = 100$$

$$4(i_2 - i_1) + 2i_2 + 3(i_2 - i_3) = 0 \quad\Rightarrow\quad -4i_1 + 9i_2 - 3i_3 = 0$$

$$3(i_3 - i_2) + 10(i_3 + 8) + 5i_3 = 0 \quad\Rightarrow\quad -3i_2 + 18i_3 = -80$$

Üçüncü denklemde 10 Ω'un akımı $i_3 - i_4$'tür. $i_4 = -8$ A olduğundan bu $i_3 + 8$ olur.

Üç denklem matris biçiminde, determinantla, çaprazlama ya da yerine koyma yöntemiyle çözülebilir. Sonuç $i_2 = 2{,}79$ A'dir (python ile doğrulandı: $i_1 = 9{,}26$ A, $i_2 = 2{,}79$ A, $i_3 = -3{,}98$ A). $i_x$ tam olarak $i_2$ çevresinin tek başına aktığı koldadır, bu yüzden $i_x = i_2 = 2{,}79$ A. Düğüm analiziyle aynı sonuç çıkmıştır.

Hoca çevre analizinin bu sorudaki avantajını vurguladı: İstenen akım doğrudan bir çevre akımıdır. Düğüm analizinde ise önce düğüm gerilimleri bulunup sonra bunlardan akım hesaplanmak zorundadır.

## 2. Doğrusallık (Linearity)

Bu haftanın yeni konuları doğrusallık, süperpozisyon ve kaynak dönüşümüdür. Kaynak dönüşümü, ileride görülecek Thevenin ve Norton eşdeğer devrelerinin temelini oluşturur.

### 2.1 Doğrusallık nedir?

Doğrusallık, süperpozisyon yönteminin kullanılabilmesi için devrede bulunması gereken bir özelliktir. Matematikte doğrusal fonksiyon, girdisi bir katsayıyla çarpıldığında çıktısı da aynı katsayıyla çarpılan fonksiyondur.

Ohm yasası doğrusal bir fonksiyondur (ekrandan, 00:20:41):

$$V = I \times R, \qquad k \times I \times R = k \times V$$

Akım 5 katına çıkarsa gerilim de 5 katına çıkar. Direnç 5 katına çıkarsa (akım sabitken) gerilim yine 5 katına çıkar. Gerilim sabit tutulup direnç 5 katına çıkarılırsa akım 5'te birine düşer; hoca bunu da ters yönlü bir doğrusallık olarak andı.

Slayttaki örnekte bir $V_1$ kaynağı 1 kΩ'luk $R_1$ direncini besler ve $V_1$ değeri −3 V'tan 3 V'a taranır (DC sweep). Grafikte direnç akımı gerilimle düz bir çizgi boyunca değişir (ekrandan, 00:20:41). $R_1$ sabit kaldıkça girişteki gerilim artışı akımı aynı oranda artırır; bu da devrenin doğrusal olduğunu gösterir.

### 2.2 Toplanabilirlik

Doğrusallığın ikinci özelliği toplanabilirliktir. Ana koldaki akım, $I_1$ ve $I_2$ kol akımlarının toplamıdır. Genel olarak $x_1$ ve $x_2$ girdilerinin toplamına fonksiyonun verdiği sonuç, $x_1$ ve $x_2$'ye ayrı ayrı verilen sonuçların toplamına eşittir:

$$f(x_1 + x_2) = f(x_1) + f(x_2)$$

Hoca çevre analizinin de aslında bu özelliğe dayandığını belirtti: Ortak dirençteki gerilim $5k(i_1 - i_2)$ yerine $5k\,i_1 - 5k\,i_2$ olarak yazılabilir, yani her çevre akımının etkisi ayrı ayrı bulunup toplanabilir.

### 2.3 Güç doğrusal mıdır?

Hoca öğrencilere gücün doğrusal olup olmadığını sordu. **Soru:** Güç doğrusal bir büyüklük müdür? **Cevap:** Bir öğrenci doğrusal olmadığını söyledi; hoca da onayladı. Güç akımla gerilimin çarpımıdır ve $P = I^2 R$ biçiminde akımın karesiyle değişir; bu yüzden doğrusal değildir.

> **Ders sonrası not:** Hoca gücü "eksponansiyel artan, karesi bazında artan" bir büyüklük olarak tanımladı. Doğrusu, güç akımın karesiyle (ikinci dereceden) değişir; üstel (eksponansiyel) bir artış söz konusu değildir.

> **Ek bilgi (derste anlatılmadı):** Gücün doğrusal olmaması, süperpozisyonla güç hesabının doğrudan yapılamayacağı anlamına gelir. Önce akım ya da gerilim süperpozisyonla bulunur, güç bu toplam değerden hesaplanır. Ayrı ayrı bulunan güçleri toplamak genelde yanlış sonuç verir.

## 3. Doğrusal ve Doğrusal Olmayan Devre Elemanları

Doğrusal elemanlar, devreye katsayı bazında etki eden elemanlardır:

- Direnç
- Bobin (indüktör); ileride görülecek
- Kondansatör (kapasitör); ileride görülecek
- Bağımsız gerilim ve akım kaynakları
- Doğrusal olarak kontrol edilen bağımlı akım ve gerilim kaynakları

Bu elemanlardan oluşan devrelerde süperpozisyon uygulanabilir.

Doğrusal olmayan elemanlar daha çok elektronik derslerinin konusudur; bu derste işlenmeyecek, ama bilinmesi faydalıdır. Slaytta ilk örnek ışık yayan diyotlar dahil diyotlardır (ekrandan, 00:25:41). Diyot belli bir eşik gerilimine kadar, gerilim negatif de olsa, hiç akım geçirmez ve açık devre gibi davranır. Eşik gerilimi aşılınca akım birden artar. Bu artış düz bir çizgi değil, eğrisel bir karakteristiktir; bu yüzden diyot doğrusal değildir. Transistör de taban (base) akımı denen kontrol akımıyla iletime geçen, doğrusal olmayan bir elemandır. Bir bağımlı kaynağı kontrol eden büyüklük doğrusal değilse, o bağımlı kaynak da doğrusal olmayan bir kaynak olur.

## 4. Süperpozisyona Giriş

### 4.1 Fikir: parçalı analiz

Süperpozisyon şunu söyler: Devrede birden fazla (en az iki) bağımsız gerilim ya da akım kaynağı varsa ve devredeki bütün elemanlar doğrusalsa, her kaynağın etkisi ayrı ayrı bulunabilir. Her adımda bir kaynak devrede bırakılır, diğerleri çıkarılır; devre çözülür. Sonra öbür kaynak için aynı işlem yapılır. Sonunda bulunan parçalı değerler toplanır. Tek kaynaklı devrede süperpozisyona gerek yoktur; o zaten normal devre çözümüdür.

Kaynak çıkarılırken uyulacak kural:

- Çıkarılan **gerilim kaynağının** yeri **kısa devre** yapılır.
- Çıkarılan **akım kaynağının** yeri **açık devre** yapılır.

> **Ders sonrası not:** Hoca bir an "akım kaynağını çıkardığın yeri kısa devre etmelisin" dedi (00:28:35), hemen ardından doğrusunu söyledi: akım kaynağının yeri açık devre, gerilim kaynağının yeri kısa devre yapılır.

### 4.2 İlk örnek (Example 01)

Devrede 10 Ω'luk bir direnç, 5 V'luk bir gerilim kaynağı ve 2 A'lik bir akım kaynağı birbirine paraleldir; 10 Ω'dan aşağı akan $I$ isteniyor (ekrandan, 00:30:41). İki kaynak olduğu için iki alt devre çıkar:

- **Devre 1 (yalnız 5 V):** Akım kaynağı çıkarılır, yeri açık devre olur. 10 Ω'un üzerinde yalnız 5 V vardır:

  $$I_1 = \frac{5 \text{ V}}{10\ \Omega} = 0{,}5 \text{ A}$$

- **Devre 2 (yalnız 2 A):** Gerilim kaynağı çıkarılır, yeri kısa devre olur. 2 A'lik akımın tamamı kısa devre üzerinden döner, 10 Ω'dan akım geçmez: $I_2 = 0$.

Toplam $I = I_1 + I_2 = 0{,}5 + 0 = 0{,}5$ A. Hoca, devre bir benzetim (simülasyon) ortamında kurulursa da 10 Ω'dan 0,5 A (500 mA) geçtiğinin görüleceğini söyledi; akım kaynağının 2 A'i ise gerilim kaynağı üzerinden döner.

Üç kaynak varsa üç alt devre kurulur. Her birinde iki kaynak aynı kurala göre çıkarılır ve analiz kalan kaynağa göre yapılır; sonunda üç katkı toplanır.

## 5. Doğrusallık Örnekleri ve Ters Yönden Çözüm

### 5.1 Bağımlı kaynaklı bir çevre analizi sorusu

Hoca bu örneğin tam bir süperpozisyon örneği olmadığını, geriye dönüp bağımlı kaynaklı bir devrede doğrusallığı göstermek için yapıldığını belirtti. Soru, $v_s = 12$ V ve $v_s = 24$ V iken $i_0$ akımının nasıl değiştiğini soruyor.

<!-- BELİRSİZ: Bu sorunun devre şekli karede görülmedi (yaklaşık 01:22); aşağıdaki denklemler altyazıdan alındı ve kendi içinde tutarlı olduğu python ile denetlendi. -->

KVL ile iki çevre denklemi yazılır. Sol çevre için:

$$12i_1 - 4i_2 + v_s = 0$$

İkinci çevrede bağımlı kaynağın eksi ucundan girildiği için $-3v_x$ terimi ve kaynak için $-v_s$ terimi yer alır:

$$-4i_1 + 16i_2 - 3v_x - v_s = 0, \qquad v_x = 2i_1$$

$v_x = 2i_1$ yerine konup sistem çözülünce (ara adım eklendi: $-10i_1 + 16i_2 = v_s$ ve $12i_1 - 4i_2 = -v_s$) şu bulunur:

$$i_0 = i_2 = \frac{v_s}{76}$$

Buna göre $v_s = 12$ V için $i_0 = 12/76 \approx 0{,}158$ A, $v_s = 24$ V için $i_0 = 24/76 \approx 0{,}316$ A'dir. Kaynak iki katına çıkınca akım da iki katına çıkar; bu doğrusallığın doğrudan sonucudur.

### 5.2 Example 3: alıştırma

Hemen ardından ekranda bir alıştırma gösterildi: $i_s = 30$ A ve $i_s = 45$ A için $v_0$ isteniyor; cevaplar slaytta verilmişti (ekrandan, 00:35:41). Hoca birkaç dakika uğraşmayı önerdi, derste çözmedi. Soru ve çözüm "Örnek Sorular" bölümündedir.

### 5.3 Example 4: $I_0 = 1$ A varsayarak çözüm

Devre (ekrandan, 00:40:41): Solda yukarı doğru $I_s = 15$ A'lik akım kaynağı vardır. Üst hatta soldan sağa 6 Ω ($I_4$), $V_2$ düğümü, 2 Ω ($I_2$), $V_1$ düğümü ve 3 Ω sıralanır. $V_2$'den toprağa 7 Ω ($I_3$), $V_1$'den toprağa 4 Ω ($I_1$), en sağda 3 Ω ile seri 5 Ω'luk kol ($I_0$) bulunur.

Soru şunu söylüyor: $I_0 = 1$ A olduğunu varsay ve doğrusallığı kullanarak $I_0$'ın gerçek değerini bul. Fikir şudur: $I_0$'dan geriye doğru giderek $I_s$ bulunur. Bulunan değer büyük olasılıkla 15 A çıkmaz, ama 15 A'in belli bir oranı çıkar. Doğrusallığa göre kaynaktaki oran neyse, devredeki bütün büyüklükler aynı oranla değişir.

Adım adım (ekrandan, 00:40:41):

1. $I_0 = 1$ A ise sağ koldaki gerilim $V_1 = (3 + 5) I_0 = 8$ V.
2. $V_1$ aynı zamanda 4 Ω'luk kolun gerilimidir: $I_1 = V_1/4 = 2$ A.
3. $V_1$ düğümünde KCL: $I_2 = I_1 + I_0 = 3$ A.
4. 2 Ω üzerinde $2 \times 3 = 6$ V düşer: $V_2 = V_1 + 2I_2 = 8 + 6 = 14$ V.
5. $I_3 = V_2/7 = 2$ A.
6. $V_2$ düğümünde KCL: $I_4 = I_3 + I_2 = 5$ A. $I_4$ kaynak akımına eşittir, yani $I_s = 5$ A.

Varsayımla 5 A bulundu, ama gerçek kaynak 15 A'dir; arada 3 kat vardır. Bu yüzden gerçek $I_0 = 3 \times 1 = 3$ A'dir. Aynı oran diğer büyüklüklere de uygulanır: Örneğin $I_3$ için bulunan 2 A, gerçek devrede 6 A olarak okunmalıdır.

Hoca buna "tersten analiz yöntemi" dedi: Bir değer biliniyor ya da varsayılıyorsa devre geriye doğru çözülebilir. Bulunan kaynak değeri gerçek kaynakla tutmuyorsa, aradaki oran kadar bütün değerler ölçeklenir.

### 5.4 $v_0 = 1$ V varsayımıyla bir örnek

Bir sonraki örnekte $v_0$ için 1 V varsayılıp gerçek değerin bulunması isteniyor. Hoca önce sorunun evde çalışılabileceğini söyledi, sonra kısaca çözdü. Önce yanlış bir oranlama yaptı ve öğrencilerin bunu fark etmesini bekledi; kendisi düzeltti.

<!-- BELİRSİZ: Bu örneğin devre şekli karede görülmedi (01:30–01:34); değerler altyazıdan alındı. Altyazıya göre 40 V'luk kaynağın beslediği kolda 12 Ω ile seri 8 Ω vardır ve $v_0$ 8 Ω üzerindedir. -->

Doğrudan çözüm: 40 V, seri 12 Ω ve 8 Ω arasında gerilim bölücüyle paylaşılır. 12 Ω'a 24 V, 8 Ω'a 16 V düşer. Yani $v_0 = 16$ V'tur, 1 V değildir.

Doğrusallıkla (tersten) çözüm: $v_0 = 1$ V ise 8 Ω'dan geçen akım $1/8 = 0{,}125$ A'dir. Bu akım 20 Ω'luk seri koldan geçer ve kolda $0{,}125 \times 20 = 2{,}5$ V oluşturur. Oysa kolun gerçek gerilimi 40 V'tur; oran $40/2{,}5 = 16$. Öyleyse $v_0$ da 1 V'un 16 katı, yani 16 V'tur. İki yöntem aynı sonucu verir.

## 6. Süperpozisyon Adımları ve Üç Kaynaklı Örnek

### 6.1 Adımlar

Slayttaki adımlar (ekrandan, 00:45:41):

1. Biri dışındaki bütün bağımsız kaynakları kapat. Gerilim kaynaklarının yerine kısa devre, akım kaynaklarının yerine açık devre koy.
2. Bütün bağımlı kaynakları açık (devrede) tut.
3. Yeni devredeki gerilim ve akımları çöz.
4. Etkin bağımsız kaynağı kapat, diğer bağımsız kaynaklardan birini aç.
5. Adım 3'ü tekrarla.
6. Orijinal devredeki her bağımsız kaynak bir kez açılana kadar devam et.
7. Her elemanın toplam gerilimini ve toplam akımını bulmak için Adım 3'te bulunan katkıları topla.

> **Hocanın vurgusu:** Bağımlı kaynaklara hiçbir şekilde dokunulmaz; ne çıkarılır ne kısa ya da açık devre yapılır. Bütün alt devrelerde (subcircuit) devrede kalırlar.

> **Hocanın vurgusu:** Yönler, çevre analizinde olduğu gibi burada da çok önemlidir. İlk alt devrede bir dirence hangi kutbu ve akım yönünü verdiyseniz, sonraki alt devrelerde de aynısını kullanın.

### 6.2 Example 6: üç kaynaklı devre

Devrede bir gerilim kaynağı ($V_1$) ve iki akım kaynağı ($I_1 = 1$ A, $I_2 = 2$ A) vardır. Dirençler $R_1 = 50$ Ω, $R_2 = 30$ Ω, $R_3 = 20$ Ω'dur (ekrandan, 00:50:41, 00:55:41). Her direncin akımı ve gerilimi isteniyor. Üç kaynak olduğu için üç alt devre kurulur.

**Devre 1: yalnız gerilim kaynağı.** İki akım kaynağı çıkarılıp yerleri açık devre yapılır. Hoca önce sordu: **Soru:** $R_2$ direncinin burada bir etkisi var mı? **Cevap:** Bir öğrenci "yok" dedi; hoca onayladı. $R_2$'nin bağlı olduğu kol devreyi tamamlamaz, akım geçmez. Geriye $R_1$ ve $R_3$'ün kaynakla seri olduğu basit bir devre kalır. Hoca bu devrede dirençlere kutup verdi ($R_1$ ve $R_3$ için artı/eksi) ve bu kutupların sonraki alt devrelerde değişmeyeceğini söyledi. Altyazıya göre kaynak 3 V'tur; $R_1$ ve $R_3$ seri olduğundan eşdeğer direnç $50 + 20 = 70$ Ω, akım $3/70 \approx 0{,}043$ A'dir. Bu akım 50 ve 20 ile çarpılarak $V_1$ ve $V_3$ bulunur.

<!-- BELİRSİZ: Devre 1'in karesi görülmedi; kaynak değeri (3 V) altyazıdan alındı. -->

**Devre 2: yalnız $I_1 = 1$ A.** Gerilim kaynağı kısa devre, $I_2$ açık devre yapılır (ekrandan, 00:50:41). **Soru:** Hangi dirençler paralel, hangileri seri? **Cevap:** Bir öğrenci $R_1$ ile $R_3$'ün paralel, $R_2$'nin bunlara seri olduğunu söyledi; hoca onayladı.

$R_1$ ve $R_3$'ün kutupları ilk devredeki gibi bırakılır, $R_2$'ye yeni bir kutup verilir. Hoca $R_2$ için seçilen yönün çok önemli olmadığını, önemli olanın bir yön tanımlayıp sonraki alt devrelerde de aynısını kullanmak olduğunu söyledi. Bu devrede $R_1$ ile $R_3$ arasındaki bağlantıya göre $V_1$, $V_3$'ün tam tersi çıkar; çünkü bu devrede iki direncin kutup yönleri ilk tanıma göre birbirine terstir.

Eşdeğer direnç:

$$R_{\text{eş}} = R_2 + (R_1 \parallel R_3) = 30 + \frac{50 \cdot 20}{70} \approx 44{,}3\ \Omega$$

$R_2$'den geçen akım, tanımlanan yöne göre $-1$ A'dir. Bu akım eşdeğer dirençle çarpılınca $V_2 + V_3 = 44{,}3 \times (-1) = -44{,}3$ V bulunur. Bu gerilim $R_2$ ile paralel grup arasında oranla paylaşılır: $V_2 = -30$ V, $V_3 = -14{,}3$ V. $V_1$, $V_3$'ün tersidir: $V_1 = 14{,}3$ V. $I_1$ için ya KCL ($I_1 = I_2 + I_3$ biçiminde) kullanılır ya da doğrudan $I_1 = 14{,}3/50 \approx 0{,}29$ A hesaplanır (python ile doğrulandı).

Hoca slaytta direnç birimlerinin "W" (watt) yazıldığını, bunların ohm olması gerektiğini belirtti.

**Devre 3: yalnız $I_2 = 2$ A.** Gerilim kaynağı kısa devre, $I_1$ açık devre yapılır (ekrandan, 00:55:41). **Soru:** Burada paralellik var mı? **Cevap:** Bir öğrenci $R_1$ ile $R_3$'ün yine paralel olup olmadığını sordu. Hoca paralel olmadıklarını açıkladı: Akım kaynağının akımı tek noktadan girer ve girdiği noktaya geri döner. $I_1$'in yeri açık olduğu için akım oradan gidemez. Dolayısıyla 2 A'lik akım kaynağı ile $R_2$ birbirine seridir. Slaytta bu durum "R2 and I2 are not in parallel with R3" diye yazılıdır (ekrandan, 01:00:41).

Düğümde KCL (ekrandan, 01:00:41):

$$I_1 + I_2 = I_3 + 2\text{ A}$$

$R_2$ akım kaynağıyla seri olduğundan $I_2 = 2$ A'dir; geriye $I_1 = I_3$ kalır. $R_2$'nin gerilimi:

$$V_2 = I_2 R_2 = 2 \times 30 = 60 \text{ V}$$

$R_1$ ile $R_3$ bir çevre oluşturur ve bu çevrede kaynak yoktur. KVL'ye göre $0 = V_1 + V_3$, yani $R_1 I_1 = -R_3 I_3$. $R_1$ ile $R_3$ farklı olduğu halde $I_1 = I_3$ olduğundan bu eşitlik ancak $I_1 = I_3 = 0$ ile sağlanır: $V_1 = V_3 = 0$.

<!-- BELİRSİZ: Karedeki KVL satırında "R1 I1 + R1 I1" gibi bir yazım hatası var; hoca da bu satırda bir karışıklık olduğunu söyledi. Doğru biçim $R_1 I_1 = -R_3 I_3$'tür. -->

**Toplama.** Üç alt devrenin sonuçları bir tabloda yan yana yazılır. Bir alt devrede bulunmayan katkı (ör. Devre 1'de $R_2$ için) sıfır yazılır. Her direnç için üç katkı toplanınca üç kaynaklı orijinal devrenin çözümü elde edilir. Hoca, devre benzetimde kurulduğunda aynı değerlerin okunacağını söyledi.

<!-- BELİRSİZ: Toplam tablo karede görülmedi; toplam değerler bu nota alınmadı. -->

**Soru:** Bir öğrenci, akım kaynağının içinde artı/eksi işaretlerinin olmasının kafasını karıştırdığını, üretecin akımı artı ucundan vermesi gerektiğini öğrendiklerini söyledi. **Cevap:** Hoca normalde akım kaynağının içine artı/eksi yazılmadığını, yalnız ok çizildiğini, bu işaretlere takılmamak gerektiğini söyledi. Ayrıca bu alt devredeki direnç kutuplarını belirleyen şeyin o akım kaynağı olmadığını, önceki alt devrede verilen kutupların sabit tutulduğunu açıkladı. Amaç akım yönlerini karıştırmamaktır: Bir alt devrede artı/eksi, öbüründe eksi/artı alınırsa katkılar birbirini götürmesi gerekirken toplanır ve sonuç yanlış çıkar. Sonuç eksi çıkarsa bu, yönün baştan ters kabul edildiğini gösterir.

## 7. Süperpozisyon Alıştırmaları

### 7.1 Example 7

Devre (ekrandan, 01:10:41): Solda artı ucu yukarıda 6 V kaynak, üstte 8 Ω, ortada 4 Ω ($v$ bu direnç üzerinde, artı üstte), sağda yukarı doğru 3 A akım kaynağı. Süperpozisyonla $v$ isteniyor.

- **Yalnız 6 V (akım kaynağı açık devre):** 8 Ω ile 4 Ω seri kalır. Gerilim bölücüyle:

  $$v_1 = 6 \cdot \frac{4}{8 + 4} = 2 \text{ V}$$

- **Yalnız 3 A (gerilim kaynağı kısa devre):** 3 A, paralel duran 4 Ω ve 8 Ω arasında bölünür. Dirençler 1:2 oranında olduğu için akım 2:1 bölünür: 4 Ω'dan 2 A, 8 Ω'dan 1 A geçer.

  $$v_2 = 2 \times 4 = 8 \text{ V}$$

- **Toplam:** $v = v_1 + v_2 = 2 + 8 = 10$ V.

### 7.2 Example 8

Hoca bu soruyu öğrencilere çözdürdü; bir öğrenci ekranda çözümünü anlattı. Soru ve çözüm "Örnek Sorular" bölümündedir.

## 8. Bağımlı Kaynaklı Devrede Süperpozisyon

### 8.1 Example 9

Bu örnek daha karışıktır ve bağımlı bir kaynak içerir. İstenen büyüklük $i_0$'dır ve bağımlı kaynak da $i_0$'a bağlıdır; bu yüzden bağımlı kaynak devrede kalır ve kullanılır. Bağımlı kaynak dışında bir akım kaynağı (4 A) ve bir gerilim kaynağı (20 V) vardır, yani iki alt devre kurulur. Her alt devreye ait akım üst işaretle gösterilir: $i_0'$ ve $i_0''$. İkisi toplanınca ana devredeki $i_0$ bulunur.

**Devre 1 (yalnız 4 A; gerilim kaynağı kısa devre).** Devre (ekrandan, 01:20:41): Solda yukarı doğru 4 A kaynağı bulunan $i_1$ çevresi, sağ üstte $i_2$ çevresi, sağ altta $i_3$ çevresi vardır; hepsi saat yönündedir. $i_1$ ile $i_2$ arasındaki ortak kolda 3 Ω, $i_1$ ile $i_3$ arasındaki ortak kolda 5 Ω vardır ve $i_0'$ 5 Ω'dan aşağı akar. $i_2$ çevresinin üstünde 2 Ω, $i_2$ ile $i_3$ arasındaki ortak yatay kolda 1 Ω ve $5i_0'$ değerli bağımlı gerilim kaynağı, $i_3$ çevresinin sağında 4 Ω bulunur. Akım yönleri bu alt devrede belirlenir ve ikinci alt devrede değiştirilmez.

Denklemler (ekrandan, 01:20:41):

$$i_1 = 4 \text{ A}$$

$$-3i_1 + 6i_2 - 1\,i_3 - 5i_0' = 0$$

$$-5i_1 - 1\,i_2 + 10i_3 + 5i_0' = 0$$

İkinci çevrede $i_2$'nin katsayısı $3 + 2 + 1 = 6$, üçüncü çevrede $i_3$'ün katsayısı $5 + 1 + 4 = 10$'dur. $i_0'$, 5 Ω'dan aşağı akan akım olduğu için $i_0' = i_1 - i_3$, yani

$$i_3 = i_1 - i_0' = 4 - i_0'$$

$i_1 = 4$ ve $i_3 = 4 - i_0'$ yerine konunca yalnız $i_2$ ve $i_0'$ kalır (ekrandan, 01:20:41):

$$3i_2 - 2i_0' = 8, \qquad i_2 + 5i_0' = 20$$

Matris biçiminde, determinantla çözülünce:

$$i_0' = \frac{52}{17} \text{ A} \approx 3{,}06 \text{ A}$$

(python ile doğrulandı; $i_2 = 80/17 \approx 4{,}71$ A).

**Devre 2 (yalnız 20 V; akım kaynağı açık devre).** Akım kaynağının yeri açık olduğu için sol çevre ortadan kalkar; iki çevre kalır, hoca bunlara $i_4$ (üst) ve $i_5$ (alt) dedi. Üst çevrede $i_4$'ün katsayısı yine $3 + 2 + 1 = 6$'dır, ortak 1 Ω'dan $i_5$ çıkarılır ve bağımlı kaynak terimi $5i_0''$ yer alır. Alt çevrede $i_5$'in katsayısı $1 + 5 + 4 = 10$'dur; 20 V'luk kaynak, bağımlı kaynak terimi ve ortak koldan gelen $i_4$ etkisi yazılır. 5 Ω'luk kolda artık yalnız $i_5$ aktığı ve öbür taraf açık devre olduğu için $i_0'' = -i_5$ yazılır. $i_5$ yerine $i_0''$ kullanmak daha mantıklıdır, çünkü istenen $i_0''$'dır. Böylece $i_4$ ve $i_0''$'nin bulunduğu iki bilinmeyenli iki denklem kalır. Çözüm:

$$i_0'' = -\frac{60}{17} \text{ A} \approx -3{,}53 \text{ A}$$

<!-- BELİRSİZ: Devre 2'nin karesi görülmedi; 20 V kaynağın kutup yönü ve denklemlerin ekranda yazılan biçimi okunamadı. Sonuç ($-60/17$ A) altyazıdan alındı; Devre 1'deki çevre katsayılarıyla kurulan denklemler bu sonucu verebilecek biçimdedir. -->

**Toplam:**

$$i_0 = i_0' + i_0'' = \frac{52}{17} - \frac{60}{17} = -\frac{8}{17} \approx -0{,}47 \text{ A}$$

Eksi işaret, akımın kabul edilen yönün tersine, yani 5 Ω'da yukarı doğru aktığını gösterir.

> **Hocanın vurgusu:** Bunlar çok kritik konulardır.

## 9. Kaynak Dönüşümü (Source Transformation)

### 9.1 Amaç

Thevenin ve Norton eşdeğer devreleri aynı şeyi hedefler: Karmaşık bir devreyi tek bir kaynak ve tek bir dirençle gösterebilmek. Kaynak dönüşümü de bu amaca hizmet eden, bu iki konunun temelini oluşturan bir dönüşümdür. Daha önce seri/paralel birleştirmeyle eşdeğer direnç hesaplanarak çok dirençli devrelerin sadeleştirildiği görülmüştü. Henüz işlenmeyen delta-yıldız (Δ-Y) dönüşümünün amacı da karışık devreleri basitleştirmektir; o konu süperpozisyondan sonra işlenecektir.

Tanım (ekrandan, 01:25:41): Kaynak dönüşümü, bir $R$ direncine seri bağlı bir $v_s$ gerilim kaynağının, aynı $R$ direncine paralel bağlı bir $i_s$ akım kaynağıyla değiştirilmesidir (ya da tersi):

$$v_s = i_s R \qquad \text{ya da} \qquad i_s = \frac{v_s}{R}$$

Eşdeğer devre, asıl devreden daha az direnç ve daha az kaynak içerir. Ama devrenin ucuna bir yük direnci bağlandığında, yükteki akım ve gerilim iki devrede de aynı olmak zorundadır. a-b uçları arasında ne ölçülüyorsa, dönüştürülmüş devrede de aynısı ölçülmelidir.

### 9.2 İdeal ve gerçek kaynak, yük direnci

İdeal gerilim kaynağı yalnız değeriyle gösterilir. Gerçek bir gerilim kaynağının ise bir iç direnci vardır ve sorularda $R_S$ ile gösterilir. Kaynağın beslediği devre, ne kadar karmaşık olursa olsun, tek bir eşdeğer dirençle gösterilip yük direnci ($R_L$) olarak adlandırılabilir.

> **Hocanın vurgusu:** Eşdeğer devre bulunurken her zaman yükteki akıma ($I_L$) ve gerilime ($V_L$) bakılır. Thevenin, Norton ya da kaynak dönüşümüyle elde edilen yeni devrede $I_L$ ve $V_L$ aynı değilse, o devre eşdeğer değildir; hesapta hata yapılmıştır.

### 9.3 Example 10: gerilim kaynağından akım kaynağına

Devre (ekrandan, 01:30:41): $V_s = 18$ V, $R_S = 3$ kΩ, $R_L = 6$ kΩ. $I_L$ ve $V_L$ isteniyor.

$$V_L = \frac{R_L}{R_L + R_S} V_S = \frac{6\text{ k}\Omega}{6\text{ k}\Omega + 3\text{ k}\Omega} \cdot 18 \text{ V} = 12 \text{ V}$$

$$I_L = \frac{V_L}{R_L} = \frac{12 \text{ V}}{6 \text{ k}\Omega} = 2 \text{ mA}$$

Kurulacak eşdeğer devre bu 2 mA ve 12 V'u değiştirmemelidir.

Aynı analiz güç üzerinden de yapılabilir. Kaynağın verdiği güç, yükteki güç ile $R_S$'deki gücün toplamıdır (ekrandan, 01:30:41):

$$P_{V_s} = P_L + P_{R_s} = 12 \text{ V}(2 \text{ mA}) + (18 \text{ V} - 12 \text{ V})(2 \text{ mA}) = 36 \text{ mW}$$

Şimdi aynı $I_L$ ve $V_L$'yi bir akım kaynağı ile paralel $R_S$ kullanarak elde etmek istiyoruz. Paralel devrede akım bölücü formülü $I_L = \dfrac{R_S}{R_L + R_S} I_S$'dir. Bilinmeyen $I_S$ olduğu için formül ters çevrilir:

$$I_S = \frac{R_L + R_S}{R_S} I_L$$

Hocanın verdiği durumlar:

- $R_S = 6$ kΩ: $I_S = \dfrac{12}{6} \cdot 2 = 4$ mA. Kaynak gücü $4 \text{ mA} \times 12 \text{ V} = 48$ mW.
- $R_S = 3$ kΩ: $I_S = \dfrac{9}{3} \cdot 2 = 6$ mA. Kaynak gücü $6 \text{ mA} \times 12 \text{ V} = 72$ mW.

<!-- BELİRSİZ: Hoca bir durumu "R_S = 20 kΩ" diye anlattı ve $I_S = 2{,}67$ mA, güç 32 mW dedi. Bu sayılar $R_S = 18$ kΩ ile tutarlıdır: $I_S = (24/18) \cdot 2 = 2{,}67$ mA, $P = 2{,}67 \times 12 = 32$ mW. $R_S = 20$ kΩ alınırsa $I_S = 2{,}6$ mA ve $P = 31{,}2$ mW çıkar. Slayttaki değer karede görülmedi. -->

Görüldüğü gibi $R_S$ düşürüldükçe aynı $I_L$'yi verebilmek için daha büyük bir $I_S$ gerekir; bu da kaynağın daha fazla güç üretmesi demektir. Hoca $R_L$'nin rolünü de açıkladı: $R_L$ devrenin çıkışındaki direnci temsil eder; amaç, içerideki karmaşık yapı ne olursa olsun yükte aynı akım ve gerilimi verecek devreyi belirlemektir.

> **Hocanın vurgusu:** $R_S = R_L$ olursa üretilen gücün %50'si yükte harcanır; yük bu durumda en büyük gücü çeker.

> **Ek bilgi (derste anlatılmadı):** Bu durum "en büyük güç aktarımı" olarak bilinir ve büyük olasılıkla Thevenin eşdeğer devresinden sonra ayrıca işlenecektir. Yükteki güç $R_L = R_S$ iken en büyük değerini alır; bu noktada verim %50'dir.

### 9.4 Example 11: akım kaynağından gerilim kaynağına

Devre (ekrandan, 01:35:41): $I_s = 5$ mA, $R_S = 50$ Ω (paralel), $R_L = 300$ Ω. $I_L$ ve $V_L$ bulunacak, sonra aynı yük değerlerini veren bir gerilim kaynağı devresi kurulacak.

$$I_L = \frac{50\ \Omega}{300\ \Omega + 50\ \Omega} I_S = \frac{50}{350} \cdot 5 \text{ mA} = 0{,}714 \text{ mA}$$

$$V_L = I_L R_L = 0{,}714 \text{ mA} \times 300\ \Omega = 0{,}214 \text{ V}$$

Kaynak gücü (ekrandan, 01:35:41):

$$P = 0{,}214 \text{ V}(0{,}714 \text{ mA}) + 0{,}214 \text{ V}(5 \text{ mA} - 0{,}714 \text{ mA}) = 1{,}07 \text{ mW}$$

Hoca, direnç gelişigüzel seçilirse de aynı $I_L$ ve $V_L$'nin elde edilebileceğini, ama aynı gücün korunması isteniyorsa direncin bu güce göre seçilmesi gerektiğini söyledi:

- $R_S = 0$ alınırsa kaynak gerilimi doğrudan $V_L$'ye eşit olur: $V_s = 0{,}214$ V. Bu durumda verilen güç yalnız $0{,}214 \times 0{,}714 \approx 0{,}153$ mW'tır; güç korunmamıştır.
- $R_S = 50$ Ω alınırsa $V_s = 0{,}714 \text{ mA} \times 350\ \Omega = 0{,}25$ V olur ve güç $0{,}25 \times 0{,}714 \approx 0{,}179$ mW'tır; hâlâ 1,07 mW'ın çok altındadır.

> **Ders sonrası not:** Altyazıda bu iki değer "0,25 milivolt" ve "0,179 milivolt" olarak geçiyor. Doğrusu kaynak gerilimi 0,25 V, güç 0,179 mW'tır (python ile doğrulandı).

Hocaya göre gerilim kaynaklı yapıda ilişki terstir: Akım kaynağında direnç paraleldir ve direnç düşürüldükçe akım, dolayısıyla güç artar. Gerilim kaynağında direnç seridir; yük akımı sabit tutulmak istendiği için seri direnci artırmak kaynak geriliminin ve gücün artmasına yol açar. Burada da yükteki gücün üretilen gücün %50'si olması için $R_S = R_L$ olmalıdır.

## 10. Kaynak Dönüşümüyle Devre Sadeleştirme

### 10.1 Example 12

Hoca kaynak dönüşümünün teoride uzun anlatılsa da uygulamada çok basit bir teknik olduğunu söyledi. Amaç karmaşık bir devreyi sadeleştirmektir; aradaki akımlar değişebilir, ama istenen büyüklük aynı kalmalıdır.

Devre (ekrandan, 01:40:41): Solda 4 Ω ve ona paralel aşağı doğru 3 A'lik akım kaynağı; üst hatta 2 Ω; ortada 8 Ω ($v_0$, artı üstte); üst hatta 3 Ω; sağda artı ucu yukarıda 12 V kaynak. Kaynak dönüşümüyle $v_0$ isteniyor.

Adımlar:

1. **3 A ∥ 4 Ω → gerilim kaynağı.** Direnç sabit tutulup kaynak dönüştürülür: 4 Ω'dan 3 A geçecekse $3 \times 4 = 12$ V gerekir. Sonuç, 4 Ω ile seri 12 V'luk kaynaktır; akım kaynağı aşağı yönlü olduğu için gerilim kaynağının eksi ucu üstte olur (ekrandan, 01:40:41, slaydın alt kısmı).
2. **Seri dirençler birleşir.** 4 Ω ile 2 Ω seri: 6 Ω. Hoca, kaynakla direnç arasında başka bir eleman (ör. paralel bir direnç) olsaydı dönüşümün doğrudan yapılamayacağını, önce o kısmın halledilmesi gerektiğini belirtti.
3. **12 V seri 6 Ω → akım kaynağı.** $12/6 = 2$ A, 6 Ω'a paralel; yönü aşağı doğrudur.
4. **Sağdaki 12 V seri 3 Ω → akım kaynağı.** $12/3 = 4$ A, 3 Ω'a paralel, yukarı yönlü (ekrandan, 01:40:41).
5. **Paralel birleştirme.** 6 Ω ∥ 3 Ω = 2 Ω. Paralel akım kaynakları yönlerine göre toplanır: 4 A yukarı, 2 A aşağı, net 2 A yukarı. $v_0$ istendiği için 8 Ω en sona bırakılır.
6. **Son hesap.** İki yol vardır:
   - Gerilime dönüştürme: 2 A ∥ 2 Ω → 4 V seri 2 Ω. 4 V, 2 Ω ile 8 Ω arasında paylaşılır: $v_0 = 4 \cdot \dfrac{8}{2 + 8} = 3{,}2$ V.
   - Akım bölücü: 2 A, 2 Ω ile 8 Ω arasında bölünür; 8 Ω'dan $2 \cdot \dfrac{2}{10} = 0{,}4$ A geçer, $v_0 = 0{,}4 \times 8 = 3{,}2$ V.

Orijinal devrede düğüm analiziyle de $v_0 = 3{,}2$ V çıkar (python ile doğrulandı). Hoca bunun anlamını şöyle özetledi: Ölçülen değer yalnız $v_0$ olduğu için 8 Ω yük ($R_L$) gibidir; geri kalan karmaşık kısım (bir gerilim kaynağı, bir akım kaynağı ve üç direnç) bir kaynak ve bir dirence indirgenmiştir. Bu indirgeme, ister bir gerilim kaynağı ile seri direnç, ister bir akım kaynağı ile paralel direnç olarak gösterilebilir.

## Örnek Sorular

### Soru 1: Example 3, doğrusallık (ekrandan, 00:35:41)

Devrede yukarı doğru $i_s$ akım kaynağı, ona paralel 4 Ω, üst hatta 12 Ω ve sağda 8 Ω vardır; $v_0$ 8 Ω üzerindedir (artı üstte). $i_s = 30$ A ve $i_s = 45$ A için $v_0$'ı bulun. Slaytta verilen cevap: 40 V, 60 V.

> **Çözüm (derste verilmedi):** 12 Ω ile 8 Ω seri, toplam 20 Ω'dur ve bu kol 4 Ω'a paraleldir. Akım bölücüyle seri koldan geçen akım $i = i_s \cdot \dfrac{4}{4 + 20} = \dfrac{i_s}{6}$'dır. $v_0 = 8i = \dfrac{4}{3} i_s$. $i_s = 30$ A için $v_0 = 40$ V, $i_s = 45$ A için $v_0 = 60$ V (python ile doğrulandı). Kaynak 1,5 katına çıkınca $v_0$ da 1,5 katına çıkar; bu doğrusallığın sonucudur.

### Soru 2: Example 8, süperpozisyon (ekrandan, 01:15:41)

Devrede solda 2 Ω ($v_0$, artı üstte), üst hatta 3 Ω ve 5 Ω, ortada yukarı doğru 5 A akım kaynağı, sağda 12 V gerilim kaynağı vardır. Süperpozisyon teoremiyle $v_0$'ı bulun. Slaytta verilen cevap: 7,4 V.

**Çözüm (derste bir öğrenci anlattı):**

- **Yalnız 12 V (akım kaynağı açık devre):** 5 Ω, 3 Ω ve 2 Ω seri, toplam 10 Ω. Akım $12/10 = 1{,}2$ A. $v_0' = 1{,}2 \times 2 = 2{,}4$ V.
- **Yalnız 5 A (gerilim kaynağı kısa devre):** Akım kaynağının iki yanında 3 Ω + 2 Ω = 5 Ω'luk kol ile 5 Ω'luk kol paraleldir. Akım eşit bölünür: her koldan 2,5 A. $v_0'' = 2{,}5 \times 2 = 5$ V.
- **Toplam:** $v_0 = 2{,}4 + 5 = 7{,}4$ V (python ile doğrulandı).

### Soru 3: Gücün doğrusallığı (derste sözlü, 00:23:39)

Güç doğrusal bir büyüklük müdür?

**Cevap (derste verildi):** Hayır. $P = VI = I^2 R$ olduğu için güç akımın karesiyle değişir; akım $k$ katına çıkınca güç $k^2$ katına çıkar.

### Soru 4: Example 4, $I_0 = 1$ A varsayımı (ekrandan, 00:40:41)

$I_s = 15$ A'lik devrede $I_0 = 1$ A varsayarak doğrusallıkla $I_0$'ın gerçek değerini bulun.

**Çözüm (derste verildi):** $I_0 = 1$ A için $V_1 = 8$ V, $I_1 = 2$ A, $I_2 = 3$ A, $V_2 = 14$ V, $I_3 = 2$ A, $I_4 = I_s = 5$ A. Gerçek kaynak 15 A olduğundan oran 3'tür; $I_0 = 3$ A. Ayrıntılar Bölüm 5.3'te.

### Soru 5: Example 7, süperpozisyon (ekrandan, 01:10:41)

6 V kaynak, 8 Ω, 4 Ω ($v$) ve 3 A akım kaynağından oluşan devrede süperpozisyonla $v$'yi bulun.

**Çözüm (derste verildi):** Yalnız 6 V iken $v_1 = 2$ V, yalnız 3 A iken $v_2 = 8$ V, toplam $v = 10$ V. Ayrıntılar Bölüm 7.1'de.

### Soru 6: Example 12, kaynak dönüşümü (ekrandan, 01:40:41)

Kaynak dönüşümüyle $v_0$'ı bulun.

**Çözüm (derste verildi):** Ardışık dönüşümlerle devre 2 A ∥ 2 Ω ile 8 Ω'a indirgenir; $v_0 = 3{,}2$ V. Ayrıntılar Bölüm 10.1'de.

## Dersin Toparlaması

Bu derste önce düğüm ve çevre analizi aynı devre üzerinde karşılaştırıldı. İki yöntem de $i_x = 2{,}79$ A sonucunu verdi. Çevre analizi istenen akım doğrudan bir çevre akımı olduğu için daha kısa yoldan sonuca ulaştı. Ardından doğrusallık tanımlandı: Ohm yasasında olduğu gibi girdi $k$ katına çıkınca çıktı da $k$ katına çıkar ve ayrı ayrı etkiler toplanabilir. Direnç, bobin, kondansatör ve kaynaklar doğrusal; diyot ve transistör doğrusal olmayan elemanlardır. Güç ise akımın karesiyle değiştiği için doğrusal değildir. Doğrusallık, çıkışa bir birim değer verip devreyi tersten çözme ve sonucu gerçek kaynakla oranlama yöntemine de imkân verir.

Süperpozisyonda her bağımsız kaynağın etkisi ayrı ayrı bulunur: Gerilim kaynakları kısa devre, akım kaynakları açık devre yapılır, bağımlı kaynaklar devrede bırakılır ve her alt devrede aynı yön ve kutup tanımları korunur. Son olarak kaynak dönüşümü işlendi: Seri bir gerilim kaynağı ile direnç, aynı dirence paralel bir akım kaynağına ($v_s = i_s R$) dönüştürülebilir. Eşdeğerliğin ölçütü yükteki akım ve gerilimin değişmemesidir. Kaynak dönüşümü, sonraki konular olan Thevenin ve Norton eşdeğer devrelerinin temelidir; delta-yıldız dönüşümü de süperpozisyondan sonra işlenecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
