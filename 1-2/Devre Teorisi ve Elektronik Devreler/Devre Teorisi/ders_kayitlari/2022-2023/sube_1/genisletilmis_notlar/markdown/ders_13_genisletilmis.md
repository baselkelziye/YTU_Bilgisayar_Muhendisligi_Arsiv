# Ders 13 Genişletilmiş Notu: Fazör Uzayında Empedans ve Admitans, Seri-Paralel Devreler, Thevenin-Norton Eşdeğerleri ve Örnek Çözümler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Tekrar: Doğrusallık ve Fazör Uzayına Geçiş
- 2. Eleman Bağıntılarının Fazör Karşılıkları
- 3. Empedans ve Admitans
- 4. Seri ve Paralel Bağlı Empedanslar
- 5. Sürekli Sinüzoidal Hal Örnekleri
- 6. Fazör Uzayında Thevenin ve Norton Eşdeğerleri
- 7. Gerilim ve Akım Bölücüler
- 8. Ek Örnekler: İki Kaynaklı ve Bağımlı Kaynaklı Devreler
- Örnek Sorular
- Dersin Toparlaması

## 1. Tekrar: Doğrusallık ve Fazör Uzayına Geçiş

Önceki derslerde fazörlerin doğrusal bir sistem tanımı üzerinden nasıl çalıştığı, kaynakların fazör gösterimi ve karmaşık sayı ile üstel gösterim arasındaki ilişki görülmüştü. Bu derste bunlar somutlaştırılır: bir devre fazör uzayına geçirilir, orada çözülür ve sonuç zaman boyutuna geri çevrilir. Zaman boyutunda öğrenilen devre teoremlerinin (Thevenin, gerilim/akım bölücü vb.) fazör uzayında da aynen kullanılabildiği gösterilir.

### 1.1 Doğrusallık neden önemli?

Hoca dersi bir soruyla açtı: devrenin doğrusallığından hangi teoremde yararlanılmıştı? Cevap **süperpozisyon** teoremidir. Direnç devrelerinde her kaynağın etkisi doğrusal olduğundan, birden fazla kaynağın toplam etkisi tek tek etkilerin toplamıdır.

Fazör uzayına geçildiğinde kaynak karmaşık bir sayı olur; reel ve sanal kısımları aynı anda devreye etki ediyormuş gibi düşünülür. Fazör uzayında elemanların tanım bağıntıları karmaşık katsayılı doğrusal bağıntılara dönüştüğü için, tıpkı süperpozisyonda olduğu gibi reel kaynağın ve sanal kaynağın etkileri ayrı ayrı izlenebilir. Bu yüzden devre fazör uzayında çözüldükten sonra yalnız reel kısım alınıp zaman boyutuna dönülebilir.

### 1.2 Kaynağın fazöre çevrilmesi

Ekrandaki RLC devresi üzerinden şu bağıntı tekrar edildi (ekrandan, 00:10:00):

$$V_m\cos(\omega t+\theta_1) = \mathrm{Re}\{V_m e^{j(\omega t+\theta_1)}\} = \mathrm{Re}\{V_m e^{j\omega t}e^{j\theta_1}\} \Rightarrow V_m e^{j\theta_1} = V_m\angle\theta_1$$

Akım için de aynısı geçerlidir: $I_m\cos(\omega t+\theta_2) \Rightarrow I_m\angle\theta_2$.

Devre zaman boyutunda çözülüyormuş gibi denklem yazılır, iki tarafın reel kısmı alınır ve reel kısım alma işlemi toplamın içine dağıtılır. Sonuçta devre fazör uzayında çözülüp zaman boyutuna dönülmüş olur. $e^{j\omega t}$ terimi kaynağın frekansını taşır ve bütün elemanlarda ortaktır; paranteze alınır ve kenara not edilir. Geriye genlik ve faz açısı kalır. Bu sayı karmaşık düzlemde orijine uzaklık $r$ ve reel eksenle yapılan açı ile ifade edilir (Euler formülü ile kartezyen-polar geçişi).

Kaynak sinüslü verilirse iki yol vardır:

- Sinüs kosinüse çevrilir ve faz açısı $-180^\circ$ ile $+180^\circ$ arasında tutulacak biçimde trigonometrik dönüşüm yapılır, sonra reel kısım yaklaşımıyla devam edilir.
- Ya da karmaşık sayının sanal kısmı alınır. Bu durumda fazör uzayından dönüşte de sanal kısım alınmalıdır.

## 2. Eleman Bağıntılarının Fazör Karşılıkları

Standart elemanlar direnç, kapasite ve endüktanstır. Her biri için zaman boyutundaki tanım bağıntısından fazör karşılığı türetildi.

### 2.1 Direnç

Direncin uçlarına $v(t) = V_m\cos(\omega t+\theta)$ uygulansın. Ohm yasasından $i(t) = \dfrac{V_m}{R}\cos(\omega t+\theta)$; genlik $I_m$ ile gösterilirse $V_m/I_m = R$. Bölme yalnız genliği değiştirir, frekansı ve fazı değiştirmez. Fazör olarak $V_m\angle\theta = R\,I_m\angle\theta$, yani

$$\mathbf{V} = R\,\mathbf{I}.$$

Direnç faz kayması oluşturmaz; çünkü zaman boyutunda faz kaydıracak bir türev ya da integral yoktur. Bağıntı zaman boyutundakinin aynısıdır.

### 2.2 Kapasite

Kapasitede zaman boyutunda bir türev vardır. Türetme ekranda el yazısıyla yapıldı (ekrandan, 00:25:00):

$$q(t) = C\,v(t), \qquad i(t) = C\frac{dv(t)}{dt}$$

$v(t) = V_m\cos(\omega t+\theta)$ ise:

$$i(t) = -C V_m\omega\sin(\omega t+\theta)$$

Fazör yazabilmek için önce eksi işaretinden, sonra sinüsten kurtulmak gerekir.

- Eksi işareti: birim çemberde $\sin(180^\circ+\alpha) = -\sin\alpha$ olduğundan $180^\circ$ eklenir: $i(t) = CV_m\omega\sin(\omega t+\theta+180^\circ)$.
- Sinüsten kosinüse: dik üçgende $\sin\alpha = a/b = \cos(90^\circ-\alpha)$. Ayrıca $\cos\beta = \cos(-\beta)$ olduğundan $\cos(90^\circ-\alpha) = \cos(\alpha-90^\circ)$.

Böylece

$$i(t) = CV_m\omega\cos(\omega t+\theta+180^\circ-90^\circ) = CV_m\omega\cos(\omega t+\theta+90^\circ)$$

ve fazörü $\mathbf{I} = CV_m\omega\angle(\theta+90^\circ)$ olur. Gerilim fazörü $\mathbf{V} = V_m\angle\theta$ ile oranlanınca $V_m$'ler ve $\theta$'lar sadeleşir:

$$Z_C = \frac{\mathbf{V}}{\mathbf{I}} = \frac{1}{\omega C}\cdot\frac{1}{1\angle90^\circ}$$

Genliği 1, açısı $90^\circ$ olan karmaşık sayı birim çemberde $j$'dir. Dolayısıyla

$$Z_C = \frac{1}{j\omega C} = -\frac{j}{\omega C}.$$

İkinci biçim, pay ve payda $j$ ile genişletilip $j^2 = -1$ kullanılarak elde edilir. Bu noktada bir öğrenci eksi işaretinin unutulup unutulmadığını sordu; hoca $1/(j\omega C)$ ile $-j/(\omega C)$'nin aynı şey olduğunu bu genişletmeyle gösterdi.

Belirli bir $\omega$ için $j$, $\omega$ ve $C$ sabittir; yani fazör uzayında kapasitenin gerilim/akım oranı sabit bir sayıdır, tıpkı direnç gibi. Direnç için bu sayı saf reel, kapasite için saf sanaldır. Önemli sonuç: fazör uzayında elemanların diferansiyel bağıntıları doğrusal (cebirsel) bağıntılara dönüşür.

**Faz ilişkisi:** $\mathbf{V}_C = \dfrac{1}{j\omega C}\mathbf{I}_C$ yazılıp $1/j = 1\angle-90^\circ$ kullanılırsa $\mathbf{V}_C = \dfrac{\mathbf{I}_C}{\omega C}\angle-90^\circ$ bulunur. Akımdan $90^\circ$ çıkarınca gerilim elde edildiği için kapasitede **akım gerilimden $90^\circ$ öndedir**.

**Hatırlama yolu:** bir kaynak, seri direnç ve uçlarındaki gerilimi ölçülen bir kapasite düşünülsün. $\omega\to0$ (DC) iken kapasite açık devre gibi davranmalı ve kaynak gerilimi aynen görülmeli; gerçekten $1/(j\omega C)\to\infty$. $\omega\to\infty$ iken kapasite kısa devre gibi davranmalı ve sıfır görülmeli; gerçekten $1/(j\omega C)\to0$. Formül bu yolla sağlanabilir.

### 2.3 Endüktans

Zaman boyutunda $\phi(t) = L\,i(t)$ ve manyetik akının değişimi gerilimi verir:

$$v_L(t) = L\frac{di_L(t)}{dt}$$

$i_L(t) = I_m\cos(\omega t+\theta)$ ise $v_L(t) = -LI_m\omega\sin(\omega t+\theta)$. Kapasitedeki işlemlerin aynısı uygulanır: eksi işareti için $180^\circ$ eklenir, sinüs $\cos(90^\circ-\alpha)$ ile kosinüse çevrilir, $\cos\alpha = \cos(-\alpha)$ ile içerinin işareti değiştirilir:

$$v_L(t) = LI_m\omega\cos(\omega t+\theta+180^\circ-90^\circ) = LI_m\omega\cos(\omega t+\theta+90^\circ)$$

Fazörler: $\mathbf{I} = I_m\angle\theta$, $\mathbf{V} = \omega L I_m\angle(\theta+90^\circ)$. Oranları

$$Z_L = \frac{\mathbf{V}}{\mathbf{I}} = \omega L\angle90^\circ = j\omega L.$$

**Hatırlama yolu:** DC'de ($\omega = 0$) endüktans kısa devredir; formülde $\omega = 0$ konunca $Z_L = 0$ çıkar, yani uyumludur.

**Faz ilişkisi:** $\mathbf{V}_L = j\omega L\,\mathbf{I}_L = \omega L\,\mathbf{I}_L\angle90^\circ$. Endüktansta **gerilim akımdan $90^\circ$ öndedir**; bu doğrudan formüle bakılarak söylenebilir.

## 3. Empedans ve Admitans

### 3.1 Empedansın tanımı

Ekrandaki tanım (ekrandan, 00:45:00): bütün elemanlar Ohm yasasına, $\mathbf{V} = Z\mathbf{I}$, uymaya zorlanırsa $Z$ elemanın empedansıdır. Yani empedans, fazör uzayında Ohm yasasının yürütülmesiyle elde edilen değerdir; kabaca akıma gösterilen direncin fazör uzayındaki karşılığıdır.

| Eleman | Kartezyen | Polar |
|---|---|---|
| Direnç | $Z_R = R$ | $R\angle0^\circ$ |
| Kapasite | $Z_C = -j/(\omega C)$ | $\frac{1}{\omega C}\angle-90^\circ$ |
| Endüktans | $Z_L = j\omega L$ | $\omega L\angle90^\circ$ |

Kartezyen biçim $a + jb$ olarak okunursa: direnç için $a = R$, $b = 0$; kapasite için $a = 0$, $b = -1/(\omega C)$; endüktans için $a = 0$, $b = \omega L$. $-j$ birim çemberde reel eksene göre $-90^\circ$'de, $j$ ise $+90^\circ$'dedir; polar biçimdeki açılar buradan gelir.

Tek bir eleman için empedans saf reel ya da saf sanaldır. Ama ekranda çizilen seri bağlı kapasite, direnç ve endüktans gibi elemanlar bir arada olduğunda, iki uçtan bakılan eşdeğer empedans genel bir karmaşık sayı $a + jb$ olur.

### 3.2 Admitans

Zaman boyutunda direncin karşılığı iletkenlik $G = i/v$ idi. Fazör uzayında empedansın karşılığı **admitans** $Y$'dir:

$$Y = \frac{\mathbf{I}}{\mathbf{V}} = \frac{1}{Z}$$

- Direnç: $Y_R = 1/R = G\angle0^\circ$.
- Kapasite: $Y_C = j\omega C = \omega C\angle90^\circ$.
- Endüktans: $Y_L = \dfrac{1}{j\omega L} = -\dfrac{j}{\omega L} = \dfrac{1}{\omega L}\angle-90^\circ$.

### 3.3 Frekansa göre davranış

Zaman boyutunda DC'de endüktans kısa devre, kapasite açık devre gibi davranıyordu. Fazör uzayında $\omega\to0$ konunca $Z_L\to0$ (sıfır dirençli eleman) ve $Z_C\to\infty$ (açık devre) çıkar. Frekans çok yükseldiğinde $Z_L = j\omega L\to\infty$ (açık devre), $Z_C\to0$ (kısa devre) olur. Direncin empedansı frekansla değişmez. Admitanslar bunların tersidir. Böylece zaman boyutundaki davranışın aynısı fazör uzayında da görülür. Ezberden yazılan ya da türetilen bir empedans, $\omega$ yerine $0$ ve $\infty$ konup elemanın bilinen davranışıyla karşılaştırılarak sağlanabilir.

### 3.4 Genel empedans ve admitans biçimleri

Genel bir eleman (seri/paralel bağlanmış elemanlardan oluşan iki uçlu bir yapı) için empedans $Z = R + jX = |Z|\angle\phi = |Z|e^{j\phi}$ yazılır. Kartezyen-polar geçişi karmaşık sayı dersinde görülen dönüşümlerle yapılır: $R = |Z|\cos\phi$, $X = |Z|\sin\phi$. Euler formülü $e^{j\theta} = \cos\theta + j\sin\theta$, $e^x$, $\cos x$ ve $\sin x$'in Taylor açılımlarından gelir: $e^{j\theta}$ açılımının çift sıradaki terimleri kosinüsü, tek sıradaki terimleri ($j$ ile) sinüsü oluşturur.

Admitans için (ekrandan, 00:55:00):

$$Y = \frac{1}{Z} = \frac{1}{R+jX} = \frac{R-jX}{R^2+X^2}$$

$Y = G + jB$ yazılırsa

$$G = \frac{R}{R^2+X^2}, \qquad B = \frac{-X}{R^2+X^2}$$

Ayrıca $Y = |Y|\angle\gamma = |Y|e^{j\gamma}$, $|Y| = \sqrt{G^2+B^2}$, $\gamma = \tan^{-1}(B/G)$, $G = |Y|\cos\gamma$, $B = |Y|\sin\gamma$. Bunlar yalnızca karmaşık sayıların yazım biçimleri arasındaki ilişkilerdir.

## 4. Seri ve Paralel Bağlı Empedanslar

Fazör uzayında bir devre çözülürken izlenen yol şudur: kaynağın fazör karşılığı ve elemanların empedansları bulunur, devre fazör uzayında çözülür, ilgilenilen akım ya da gerilimin fazörü bulunur ve zaman boyutuna dönülür. Zaman boyutuna dönerken genlik ve faz fazörden gelir, frekans ise kaynaktan (not edilen $\omega$'dan) eklenir. Artık ikinci dereceden diferansiyel denklem çözmeye gerek kalmaz.

### 4.1 Seri bağlama

Tek gözlü bir devrede gerilim kaynağı $\mathbf{V}_s$, $Z_1$ ve $Z_2$ seri olsun. Tek göz olduğu için aynı $\mathbf{I}$ akımı akar ve gerilimlerin toplamı kaynak gerilimine eşittir:

$$\mathbf{V}_s = \mathbf{V}_1 + \mathbf{V}_2 = \mathbf{I}Z_1 + \mathbf{I}Z_2 \Rightarrow \frac{\mathbf{V}_s}{\mathbf{I}} = Z_1 + Z_2$$

Aynı kaynağı tek bir elemanla sürüp aynı akımı elde etmek istersek o elemanın empedansı $Z_{\text{eş}} = \mathbf{V}_s/\mathbf{I}$ olmalıdır. Demek ki seri bağlı empedansların eşdeğeri toplamlarıdır: $Z_{\text{eş}} = Z_1 + Z_2 + \dots + Z_n$. Direnç devrelerindekinin aynısıdır.

### 4.2 Paralel bağlama

Bir akım kaynağı $\mathbf{I}_s$'ye $Z_1$ ve $Z_2$ paralel bağlansın. Paralel elemanların gerilimi aynıdır. Düğüm denklemi:

$$\mathbf{I}_s = \mathbf{I}_1 + \mathbf{I}_2 = \frac{\mathbf{V}}{Z_1} + \frac{\mathbf{V}}{Z_2} \Rightarrow \frac{\mathbf{V}}{\mathbf{I}_s} = \frac{1}{\frac{1}{Z_1}+\frac{1}{Z_2}}$$

Tek eşdeğer eleman için $\dfrac{1}{Z_{\text{eş}}} = \dfrac{1}{Z_1} + \dfrac{1}{Z_2} + \dots + \dfrac{1}{Z_n}$. Admitans cinsinden: seri elemanların eşdeğer admitansı terslerin toplamının tersi, paralel elemanların eşdeğer admitansı ise admitansların cebirsel toplamıdır.

> **Hocanın vurgusu:** Empedanslar seride toplanır, admitanslar paralelde toplanır.

## 5. Sürekli Sinüzoidal Hal Örnekleri

### 5.1 Fazörle çözüme uygunluk

Bir devre fazörle çözülmeden önce uygun olup olmadığına karar verilir. Tek bir sinüzoidal kaynak varsa ya da birden fazla kaynak aynı frekanstaysa fazörle çözülebilir. Elemanlar direnç, kapasite, endüktanstır.

Kaynak devreye ilk bağlandığında bir geçici hal (transient) oluşur; fazör analizi bununla ilgilenmez. Fazör analizi **sürekli hal** içindir: devre uzun süredir bu düzenle çalışıyor ve bundan sonraki durum inceleniyor.

### 5.2 Seri RL devresi (Example 03)

Devre (ekrandan, 01:20:00): $v_1 = 12\sin(100t+30^\circ)$ V kaynağına seri bağlı $L_1 = 10$ mH ve $R_1 = 10\ \Omega$; tek göz.

- $\omega = 100$ rad/s not edilir.
- $Z_R = 10\ \Omega$; $Z_L = j\omega L = j(100)(10\cdot10^{-3}) = j\ \Omega = 1\angle90^\circ$.
- Kaynak kosinüse çevrilir: $\sin\alpha = \cos(90^\circ-\alpha) = \cos(\alpha-90^\circ)$, $\alpha = 100t+30^\circ$:
  $v_1 = 12\cos(100t+30^\circ-90^\circ) = 12\cos(100t-60^\circ)$, $\mathbf{V}_1 = 12\angle-60^\circ$ V.
- Eşdeğer empedans (ekrandan, 01:25:00): $Z_{\text{eş}} = 10 + j$; bölme yapılacağı için polar biçime geçilir: $|Z_{\text{eş}}| = \sqrt{101} = 10.05$, açı $\tan^{-1}(1/10) = 5.71^\circ$. Açının küçük olması doğaldır, çünkü sanal kısım küçüktür. Slayttaki çözüm de $10.05\angle5.7^\circ\ \Omega$ verir.
- Ana kol akımı (ekrandan, 01:30:00): $\mathbf{I} = \dfrac{\mathbf{V}_1}{Z_{\text{eş}}} = \dfrac{12\angle-60^\circ}{10.05\angle5.71^\circ} = 1.19\angle-65.71^\circ$ A.
- Zaman boyutu: $i(t) = \mathrm{Re}\{1.19\,e^{j(100t-65.71^\circ)}\} = 1.19\cos(100t-65.71^\circ)$ A. Kısa yol: genlik fazörden, reel kısım alınarak gidildiği için kosinüs, $\omega$ not edilen değerden, açı fazörden.
- Endüktans gerilimi: $\mathbf{V}_L = \mathbf{I}Z_L = 1.19\angle-65.71^\circ\cdot1\angle90^\circ = 1.19\angle24.29^\circ$ V, $v_L(t) = 1.19\cos(100t+24.29^\circ)$ V.
- Direnç gerilimi: $\mathbf{V}_R = Z_R\mathbf{I} = 10\cdot1.19\angle-65.71^\circ = 11.9\angle-65.71^\circ$ V, $v_R(t) = 11.9\cos(100t-65.71^\circ)$ V.

Sonuçlar python ile doğrulandı ($|\mathbf{I}| = 1.194$ A).

> **Ek bilgi (derste anlatılmadı):** KVL fazörlerle de sağlanır: $\mathbf{V}_L + \mathbf{V}_R = (1.088 + j0.491) + (4.912 - j10.88) = 6 - j10.39 = 12\angle-60^\circ$ V. Fazörler toplanırken genlikler değil karmaşık sayılar toplanır.

### 5.3 Paralel RLC devresi (Example 04)

Devre (ekrandan, 01:35:00): $i_1 = 4\cos(300t-10^\circ)$ A akım kaynağı; aynı iki düğüm arasına paralel bağlı $R = 1\ \Omega$, $C = 1$ mF, $L = 1$ H.

- $\omega = 300$ rad/s. Kaynak zaten kosinüs: $\mathbf{I}_1 = 4\angle-10^\circ$ A.
- $Z_R = 1 = 1\angle0^\circ$.
- $Z_C = \dfrac{1}{j\omega C} = \dfrac{1}{j\cdot300\cdot10^{-3}} = \dfrac{10}{3j} = -j3.33 = 3.33\angle-90^\circ\ \Omega$.
- $Z_L = j\omega L = j300 = 300\angle90^\circ\ \Omega$.

Üst düğümlerin hepsi ortak olduğu için tek bir düğüm denklemi yazılır (ekrandan, 01:40:00):

$$4\angle-10^\circ = \frac{\mathbf{V}}{1\angle0^\circ} + \frac{\mathbf{V}}{3.33\angle-90^\circ} + \frac{\mathbf{V}}{300\angle90^\circ}$$

Toplama yapılacağı için kartezyen biçim pratiktir: $1/(3.33\angle-90^\circ) = 0.3\angle90^\circ = j0.3$; $1/(300\angle90^\circ) = 0.00333\angle-90^\circ = -j0.00333$. Böylece

$$4\angle-10^\circ = \mathbf{V}\,(1 + j0.3 - j0.00333)$$

Hoca parantezi $1 + j0.27$ olarak yazdı, bunu $1.03\angle15.11^\circ$ diye polar biçime çevirdi ve $\mathbf{V} = 3.88\angle-25.11^\circ$ V buldu. Ardından $i_R$, $i_C = \mathbf{V}/Z_C$ ve $i_L = \mathbf{V}/Z_L$ aynı yolla hesaplandı. Slayttaki çözümle karşılaştırırken slaytta $3.84\angle-26.5^\circ$ görüldü; hoca farkı yuvarlamaya bağladı.

> **Ders sonrası not:** Hoca parantezi $1 + j0.27$ yazdı; doğrusu $1 + j(0.3 - 0.00333) = 1 + j0.2967 = 1.043\angle16.52^\circ$'dir. Fark yuvarlamadan değil bu toplama hatasından gelir. Doğru değerler (python ile): $\mathbf{V} = 3.835\angle-26.52^\circ$ V (slaytla uyumlu), $v(t) = i_R(t) = 3.84\cos(300t-26.52^\circ)$ (V ve A), $\mathbf{I}_C = \mathbf{V}/Z_C = 1.15\angle63.48^\circ$ A, $\mathbf{I}_L = \mathbf{V}/Z_L = 12.8\angle-116.52^\circ$ mA. Hocanın değerleri $3.88\angle-25.11^\circ$, $1.165\angle64.89^\circ$ ve $0.013\angle-115.11^\circ$ idi.

Bu çözümle devre fazör uzayına geçirildi, bütün elemanların fazör akım-gerilimleri bulundu ve zaman boyutuna geri dönüldü; sürekli sinüzoidal hal analizi tamamlanmış oldu.

## 6. Fazör Uzayında Thevenin ve Norton Eşdeğerleri

### 6.1 Teoremler

Thevenin teoremi: karmaşık bir devreye iki ucundan bakıldığında, bu devrenin yerine ideal olmayan bir gerilim kaynağı (bir kaynak ve seri bir empedans) konabilir. Norton teoremi: aynı devrenin yerine ideal olmayan bir akım kaynağı (bir kaynak ve paralel bir empedans) konabilir. Fazör uzayındaki tek fark, empedansın genel bir karmaşık sayı olabilmesidir. Eşdeğerlik ölçütü: uçlara bir yük empedansı bağlandığında yük üzerindeki gerilim ve yükten geçen akım, orijinal devrede ve eşdeğer devrede aynı olmalıdır.

Ekrandaki şekil (ekrandan, 01:45:00): Thevenin devresi $\mathbf{V}_{th}$ kaynağı, seri $Z_{th}$ ve yük $Z_{load}$; Norton devresi $\mathbf{I}_n$ kaynağı, paralel $Z_n$ ve yük $Z_{load}$. İki eşdeğer arasındaki dönüşüm:

$$\mathbf{V}_{th} = \mathbf{I}_n Z_n, \qquad \mathbf{I}_n = \frac{\mathbf{V}_{th}}{Z_{th}}, \qquad Z_n = Z_{th}$$

Hesap yolu zaman boyutundakiyle aynıdır: uçlar açık bırakılıp ölçülen gerilim $\mathbf{V}_{th}$'dır; bağımsız kaynaklar sıfırlanıp (gerilim kaynağı kısa devre, akım kaynağı açık devre) içeri bakılan eşdeğer empedans $Z_{th}$'dır.

### 6.2 Example 05: Karmaşık bir devrenin Thevenin eşdeğeri

Devre (ekrandan, 01:50:00), soldan sağa:

| Eleman | Bağlantı | Değer | Empedans ($\omega = 400$) |
|---|---|---|---|
| $I_1$ | sol düğüm ile toprak arası akım kaynağı | $5\sin(400t+50^\circ)$ mA | $\mathbf{I}_1 = 5\angle-40^\circ$ mA |
| $C_1$ | sol düğüm ile toprak arası ($I_1$'e paralel) | $1\ \mu$F | $-j2500\ \Omega$ |
| $R_1$ | sol düğüm ile orta düğüm arası (seri) | $3$ k$\Omega$ | $3000\ \Omega$ |
| $L_1$ | orta düğüm ile toprak arası | $0.3$ H | $j120\ \Omega$ |
| $L_2$ | orta düğüm ile sağ düğüm arası (seri) | $2$ H | $j800\ \Omega$ |
| $R_2$ | sağ düğüm ile toprak arası | $5$ k$\Omega$ | $5000\ \Omega$ |
| $C_2$ | yük, sağ düğüm ile toprak arası (uçlar) | $0.7\ \mu$F | $-j3571\ \Omega$ |

Kaynak sinüs olduğu için $\sin\alpha = \cos(\alpha-90^\circ)$ ile $5\cos(400t+50^\circ-90^\circ) = 5\cos(400t-40^\circ)$ mA, fazörü $0.005\angle-40^\circ$ A. Hoca burada $\omega$'nın açısal frekans olduğunu hatırlattı: kaynak $\sin(2\pi f t+\phi)$ biçiminde verilseydi $f$ frekans olurdu ve $\omega = 2\pi f$ hesaplanmalıydı.

Empedanslar: $Z_{L2} = j(400)(2) = j800$, $Z_{L1} = j(400)(0.3) = j120$, $Z_{C1} = \dfrac{1}{j\cdot400\cdot10^{-6}} = -j2500$, $Z_{C2} = \dfrac{1}{j\cdot400\cdot0.7\cdot10^{-6}} = -j\dfrac{25000}{7} = -j3571\ \Omega$.

**$Z_{th}$:** Akım kaynağı açık devre yapılır. Geriye $Z_{C1}$ ile $Z_{R1}$ seri kalır; bu seri yapı $Z_{L1}$'e paraleldir; sonuca $Z_{L2}$ seri eklenir; hepsi $Z_{R2}$'ye paraleldir:

$$Z_{th} = \Big[\big((Z_{C1}+Z_{R1})\parallel Z_{L1}\big) + Z_{L2}\Big]\parallel Z_{R2}$$

Hoca bu ifadeyi bir çevrim içi Octave ortamında hesaplamaya çalıştı, slayttaki sonuçla tutturamadı ve hatayı derste bulamadı. Python ile ifade $Z_{th} = 906.5\angle79.37^\circ\ \Omega$ verir; bu, slayttaki $Z_{eq4} = 906\ \Omega\angle79.4^\circ$ ile uyuşur (ekrandan, 02:00:00). Dolayısıyla seri/paralel yapı doğrudur, fark büyük olasılıkla girişteki bir yazım hatasındandır.

**Slayttaki kaynak dönüşümü yolu:** $I_1$ ve paralel $Z_{C1}$, bir gerilim kaynağı ve seri $Z_{C1}$'e dönüştürülür; gerilim, akım ile empedansın çarpımıdır. Seri $Z_{C1} + Z_{R1}$ toplanır, sonra tekrar akım kaynağı + paralel empedansa dönülür, $Z_{L1}$ ile paralel birleştirilir, yeniden gerilim kaynağına dönülür, $Z_{L2}$ eklenir, yine akım kaynağına dönülüp $R_2$ ile birleştirilir. Son durumda bir Norton kaynağı $\mathbf{I}_{n2}$, paralel $Z_{eq4} = 906\angle79.4^\circ\ \Omega$ ve yük $Z_{C2} = 3.57\angle-90^\circ$ k$\Omega$ kalır. Yük akımı akım bölücüyle bulunur (ekrandan, 02:10:00):

$$\mathbf{I}_{C2} = \frac{Y_{C2}}{Y_{C2}+Y_{eq4}}\,\mathbf{I}_{n2}, \qquad Y_{C2} = j0.280\ \text{m}\Omega^{-1},\quad Y_{eq4} = (0.204 - j1.08)\ \text{m}\Omega^{-1}$$

ve gerilim Ohm yasasıyla: $\mathbf{V}_{C2} = \mathbf{I}_{C2}Z_{C2}$ (ekrandan, 02:05:00).

Bir öğrenci, slayttaki ilk dönüşümde $5\ \text{mA}\times2.5\ \text{k}\Omega$ çarpımının $7.5$ değil $12.5$ V olması gerektiğini gösterdi; hoca bunu doğruladı.

> **Ders sonrası not:** Slayttaki ilk adım $\mathbf{I}_1 Z_{C1} = 7.5\angle-130^\circ$ V yazılmıştır; doğrusu $0.005\angle-40^\circ\cdot2500\angle-90^\circ = 12.5\angle-130^\circ$ V'tur. Bu hata sonraki bütün kaynak değerlerine $12.5/7.5$ oranında yansır; empedanslar etkilenmez. Python ile doğru değerler: $\mathbf{V}_{th} = 0.385\angle-12.0^\circ$ V, $\mathbf{I}_{n} = 0.425\angle-91.4^\circ$ mA (slaytta $0.255$ mA), $\mathbf{I}_{C2} = 143\angle74.4^\circ\ \mu$A (slaytta $86.0\ \mu$A), $\mathbf{V}_{C2} = 0.512\angle-15.6^\circ$ V (slaytta $0.309$ V).

### 6.3 Norton dönüşümü ve sonsuz empedans (RLC örneği)

Soru (ekrandan, 02:15:00): sağdaki devrenin soldakinin Norton dönüşümü olduğunu açıklayın; ayrıca RLC ağının doğal frekansı $\omega_0$'ı hesaplayın.

Sol devre: $v_1 = 1\sin(1000t)$ V kaynağı, seri $L_1 = 0.1$ H, ardından aynı iki düğüm arasına paralel $C_1 = 10\ \mu$F ve yük $R_1 = 1$ k$\Omega$. Sağ devre: $10$ mA $\sin(1000t)$ akım kaynağı ve $R_1 = 1$ k$\Omega$.

- $\omega = 1000$; $\sin(1000t) = \cos(1000t-90^\circ)$, $\mathbf{V}_1 = 1\angle-90^\circ$ V.
- $Z_{L1} = j(1000)(0.1) = j100\ \Omega$; $Z_{C1} = \dfrac{1}{j\cdot1000\cdot10\cdot10^{-6}} = \dfrac{100}{j} = -j100\ \Omega$.
- Kaynak sıfırlanınca $L_1$ ve $C_1$ yükün uçlarına paralel kalır:

$$\frac{1}{Z_{th}} = \frac{1}{j100} + \frac{1}{-j100} = 0 \Rightarrow Z_{th}\to\infty$$

Hoca önce bunu "$Z_{th}$ sıfır" diye okudu ve $\mathbf{V}_{th}$ hesabında sonsuz gibi anlamsız bir değer çıktığını gördü. Bir öğrencinin uyarısıyla düzeltildi: sıfır olan $1/Z_{th}$'dır, $Z_{th}$ sonsuzdur. Sonsuz paralel empedans açık devre demektir; Norton eşdeğeri tek başına bir akım kaynağından oluşur.

**Kaynak dönüşümüyle:** gerilim kaynağı ve seri $j100$, bir akım kaynağı ve paralel $j100$'e çevrilir; buna $-j100$ paralel kalır ve ikisinin paraleli yine açık devredir. Akım kaynağı (ekrandan, 02:20:00):

$$\mathbf{I}_n = \frac{1\angle-90^\circ}{100\angle90^\circ} = 0.01\angle-180^\circ\ \text{A}$$

Zaman boyutunda $i_n(t) = 0.01\cos(1000t-180^\circ)$ A $= 10\cos(1000t-180^\circ)$ mA. Hoca bunu slayttaki $10$ mA $\sin(1000t)$ ifadesine trigonometrik dönüşümlerle bağlamaya çalıştı ($-\cos$, $\cos(180^\circ-\alpha)$, $\sin(90^\circ-\alpha)$ dönüşümleri).

> **Ders sonrası not:** $0.01\cos(1000t-180^\circ) = -0.01\cos(1000t)$'dir; bu $0.01\sin(1000t)$'ye eşit değildir, aralarında $90^\circ$ fark vardır. Ekrandaki ara adımda $-0.01\sin(90^\circ-\alpha)$ ifadesi $0.01\sin\alpha$ yapılmıştır; doğrusu $-\sin(90^\circ-\alpha) = -\cos\alpha$'dır. Zaman boyutunda doğrudan çözüm de aynı sonucu verir: uçlar kısa devre edildiğinde $L\,di/dt = \sin(1000t)$, $i = -0.01\cos(1000t)$ A. Büyük olasılıkla slayttaki ifade faz bakımından hatalıdır.

Doğal frekans kısmına derste vakit kaybetmemek için girilmedi; önceki derslerde görülen $\alpha$ ve $\omega_0$ bağıntılarıyla bulunduğu söylendi (çözüm Örnek Sorular bölümünde).

> **Ek bilgi (derste anlatılmadı):** Bu devrede kaynak frekansı, $L_1$-$C_1$ çiftinin rezonans frekansına ($1/\sqrt{LC}$) eşittir. Rezonansta $j\omega L$ ile $1/(j\omega C)$ birbirini götürür; bu yüzden paralel $LC$ çiftinin empedansı sonsuz çıkar.

## 7. Gerilim ve Akım Bölücüler

Seri bağlı empedanslar gerilim bölücü olarak çalışır: gerilimi empedanslarıyla orantılı paylaşırlar. Paralel bağlı empedanslar akım bölücü olarak çalışır: akımı empedanslarıyla ters orantılı (admitanslarıyla orantılı) paylaşırlar. Bu, direnç devrelerindeki durumun aynısıdır; Example 05'teki $\mathbf{I}_{C2} = \dfrac{Y_{C2}}{Y_{C2}+Y_{eq4}}\mathbf{I}_{n2}$ bağıntısı akım bölücünün admitans biçimidir.

## 8. Ek Örnekler: İki Kaynaklı ve Bağımlı Kaynaklı Devreler

### 8.1 İki kaynaklı ve bağımlı kaynaklı devrede düğüm gerilimi (Example 53)

Soru (ekrandan, 02:30:00): $v_a(t)$ gerilimini bulun.

Devre:

- Sol kol: $20\cos(250t)$ V gerilim kaynağı, seri $8\ \Omega$ ve $36$ mH, $a$ düğümüne bağlanır.
- $a$ düğümü ile toprak arası: $0.25$ mF kapasite ($v_a$ bunun üzerindeki gerilim).
- $a$ düğümü ile toprak arası: $1.2\cos(250t+45^\circ)$ A akım kaynağı, akım $a$ düğümüne doğru.
- Sağ kol: $a$ düğümünden $80$ mH üzerinden $4v_a(t)$ bağımlı gerilim kaynağına (artı ucu üstte), oradan toprağa.

İki kaynak da aynı frekansta ($\omega = 250$ rad/s) olduğu için devre fazörle çözülebilir. Farklı frekanslar olsaydı süperpozisyonla her kaynak ayrı çözülüp sonuçlar zaman boyutunda birleştirilecekti.

- $20\angle0^\circ$ V; $1.2\angle45^\circ$ A.
- $Z_R = 8$; $Z_{36\text{mH}} = j(250)(0.036) = j9$; $Z_C = \dfrac{1}{j\cdot250\cdot0.25\cdot10^{-3}} = -j16$; $Z_{80\text{mH}} = j(250)(0.08) = j20\ \Omega$.

Tek bilinmeyenli düğüm denklemi ($a$ düğümünden çıkan akımlar):

$$\frac{\mathbf{V}_a - 20\angle0^\circ}{8+j9} + \frac{\mathbf{V}_a}{-j16} - 1.2\angle45^\circ + \frac{\mathbf{V}_a - 4\mathbf{V}_a}{j20} = 0$$

Son terimdeki $\mathbf{V}_a - 4\mathbf{V}_a = -3\mathbf{V}_a$ olur. Bilinenler karşıya atılıp $\mathbf{V}_a$ paranteze alınır:

$$\mathbf{V}_a\left(\frac{1}{8+j9} - \frac{1}{j16} - \frac{3}{j20}\right) = \frac{20}{8+j9} + 1.2\angle45^\circ$$

Hoca slayttaki sayısal çözümde bir işaret hatası ($8-j9$ yazılması) olduğunu söyledi ve denklemi Octave ile çözdü (ekrandan, 02:40:00 ve 02:50:00).

> **Ders sonrası not:** Derste bulunan $v_a(t) = 0.7253\cos(250t+41.558^\circ)$ sonucu doğru değildir. Ekrandaki Octave çıktısında sağ taraf $1.7338 - j0.2203$ alınmıştır; bu değer $45$'in radyan olarak girilmesiyle elde edilir (doğrusu $20/(8+j9) + 1.2\angle45^\circ = 1.952 - j0.393$). Ayrıca çıktıda genlik `abs(a) = 21.186`, açı `angle(a) = 0.7253` rad idi; radyan cinsinden açı genlik gibi okunmuştur. Doğru çözüm (python ile, düğüm denklemi sağlatılarak): $\mathbf{V}_a = 1.893 - j12.28 = 12.43\angle-81.24^\circ$ V, yani $v_a(t) = 12.43\cos(250t-81.24^\circ)$ V.

### 8.2 Octave ile karmaşık sayı hesabı

Derste çevrim içi Octave kullanıldı (ekrandan, 02:50:00). Gösterilen noktalar:

- `abs(z)` genliği, `angle(z)` açıyı **radyan** olarak verir; dereceye çevirmek için `rad2deg(angle(z))` kullanılır. Örneğin `y = 25-25j` için `abs(y) = 35.355`, `rad2deg(angle(y)) = -45`.
- `exp(j*x)` içindeki $x$ radyandır. Ekrandaki deneme: `10*exp(90*j)` beklenen saf sanal sayıyı vermedi ($-4.48 + j8.94$), `10*exp(deg2rad(90*j))` ise $6.1\cdot10^{-16} + j10$ verdi. $10^{-16}$ mertebesindeki değer pratikte sıfırdır. Benzer şekilde `10*exp(deg2rad(30*j))` $= 8.66 + j5$, yani $10\angle30^\circ$.

> **Hocanın vurgusu:** Matematik araçları kullanılırken üstel fonksiyonun içine verilen açı radyana çevrilmelidir.

### 8.3 Bağımlı kaynaklı devrenin Thevenin eşdeğeri (Example 56)

Devre (ekrandan, 02:45:00): $10\angle30^\circ$ V kaynak, seri $30\ \Omega$, ardından $5\mathbf{I}_a$ bağımlı gerilim kaynağı (eksi ucu solda, artı ucu sağda), sonra bir düğüm; bu düğümden toprağa $-j25\ \Omega$ kapasite (akımı $\mathbf{I}_a$, aşağı yönlü); düğümden çıkışa seri $50\ \Omega$; çıkış uçları $\mathbf{V}_{oc}$.

Bağımlı kaynak olduğunda iki yol vardır: uçlara bir test kaynağı bağlamak ya da açık devre gerilimi ile kısa devre akımını bulup oranlamak. Slayttaki çözüm ikinci yolu izler.

**Açık devre gerilimi:** Uçlar açıkken $50\ \Omega$'dan akım geçmez; tek bir çevre kalır ve kapasitenin akımı $\mathbf{I}_a$'dır. Sol çevrede KVL:

$$30\mathbf{I}_a - 5\mathbf{I}_a + (-j25)\mathbf{I}_a = 10\angle30^\circ$$

Toplama gerektiği için sol taraf kartezyen bırakılır: $\mathbf{I}_a(25 - j25) = 10\angle30^\circ$. Elle çözümde önce $25 - j25 = 25\sqrt2\angle-45^\circ$ bulunur, sonra bölme yapılır:

$$\mathbf{I}_a = \frac{10\angle30^\circ}{35.36\angle-45^\circ} = 0.2828\angle75^\circ\ \text{A}$$

$$\mathbf{V}_{oc} = -j25\,\mathbf{I}_a = 25\angle-90^\circ\cdot0.2828\angle75^\circ = 7.071\angle-15^\circ\ \text{V}$$

Hoca bu sonuçları Octave ile de doğruladı (genlik $7.07$, açı $-15^\circ$).

**Kısa devre akımı:** Uçlar kısa devre edilince iki göz oluşur. Sol göz akımı $\mathbf{I}_1$, sağ göz akımı $\mathbf{I}_{sc}$ ise kapasite akımı $\mathbf{I}_a = \mathbf{I}_1 - \mathbf{I}_{sc}$'dir. Denklemlerde $\mathbf{I}_a$ yerine $\mathbf{I}_1 - \mathbf{I}_{sc}$ yazılır:

$$30\mathbf{I}_1 - 5(\mathbf{I}_1 - \mathbf{I}_{sc}) - j25(\mathbf{I}_1 - \mathbf{I}_{sc}) = 10\angle30^\circ$$

$$-j25(\mathbf{I}_{sc} - \mathbf{I}_1) + 50\,\mathbf{I}_{sc} = 0$$

İki bilinmeyenli karmaşık katsayılı bir doğrusal sistemdir. Çözülünce $Z_{th} = \mathbf{V}_{oc}/\mathbf{I}_{sc}$ ve $\mathbf{I}_n = \mathbf{I}_{sc}$ bulunur. Derste bu sistem sayısal olarak çözülmedi; çözüm Örnek Sorular bölümündedir.

## Örnek Sorular

### Soru 1 (derste sözlü, 00:07:17)

Devrenin doğrusallık özelliğinden hangi teorem çerçevesinde yararlanılmıştı?

**Cevap (derste verildi):** Süperpozisyon. Fazör uzayında da elemanlar doğrusal kaldığı için reel ve sanal kaynak etkileri ayrı izlenebilir ve yalnız reel kısım alınarak zaman boyutuna dönülebilir.

### Soru 2 (ekrandan, 01:20:00)

$v_1 = 12\sin(100t+30^\circ)$ V kaynağına seri bağlı $L_1 = 10$ mH ve $R_1 = 10\ \Omega$ için akımı ve eleman gerilimlerini bulun.

**Çözüm (derste verildi):** $\mathbf{V}_1 = 12\angle-60^\circ$, $Z_{\text{eş}} = 10 + j = 10.05\angle5.71^\circ$, $\mathbf{I} = 1.19\angle-65.71^\circ$ A. $i(t) = 1.19\cos(100t-65.71^\circ)$ A, $v_L(t) = 1.19\cos(100t+24.29^\circ)$ V, $v_R(t) = 11.9\cos(100t-65.71^\circ)$ V.

### Soru 3 (ekrandan, 01:35:00)

$4\cos(300t-10^\circ)$ A akım kaynağına paralel bağlı $1\ \Omega$, $1$ mF, $1$ H için düğüm gerilimini ve eleman akımlarını bulun.

**Çözüm (derste verildi, düzeltilmiş):** $\mathbf{V}\,(1 + j0.2967) = 4\angle-10^\circ$, $\mathbf{V} = 3.84\angle-26.52^\circ$ V. $v(t) = i_R(t) = 3.84\cos(300t-26.52^\circ)$, $i_C(t) = 1.15\cos(300t+63.48^\circ)$ A, $i_L(t) = 12.8\cos(300t-116.52^\circ)$ mA. Derste ara toplamda yapılan hata için 5.3'teki nota bakın.

### Soru 4 (ekrandan, 01:50:00)

Example 05 devresinde yük $C_2 = 0.7\ \mu$F'a göre Thevenin/Norton eşdeğerini ve yük akımını, gerilimini bulun.

**Çözüm (slayttaki yol, python ile düzeltilmiş):** $Z_{th} = 906\angle79.4^\circ\ \Omega$, $\mathbf{V}_{th} = 0.385\angle-12.0^\circ$ V, $\mathbf{I}_n = 0.425\angle-91.4^\circ$ mA, $\mathbf{I}_{C2} = 143\angle74.4^\circ\ \mu$A, $\mathbf{V}_{C2} = 0.512\angle-15.6^\circ$ V. Slayttaki $7.5$ V'luk hatalı ara değer nedeniyle slayttaki kaynak ve yük değerleri $0.6$ katı küçük çıkmıştır.

### Soru 5 (ekrandan, 02:15:00)

$1\sin(1000t)$ V kaynak, seri $0.1$ H, paralel $10\ \mu$F ve $1$ k$\Omega$ yükten oluşan devre için sağdaki devrenin (akım kaynağı + $1$ k$\Omega$) neden Norton dönüşümü olduğunu açıklayın; RLC ağının doğal frekansı $\omega_0$'ı hesaplayın.

**Çözüm (derste verildi, ilk kısım):** $Z_L = j100$, $Z_C = -j100$; kaynak sıfırlanınca ikisi paraleldir ve $1/Z_{th} = 0$, $Z_{th}\to\infty$ (açık devre). Norton eşdeğeri yalnız akım kaynağıdır: $\mathbf{I}_n = 0.01\angle-180^\circ$ A. Slayttaki zaman ifadesiyle ilgili 6.3'teki nota bakın.

> **Çözüm (derste verilmedi):** Kaynak sıfırlandığında yükle birlikte $L_1$, $C_1$ ve $R_1$ paralel bağlı kalır; paralel RLC ağının doğal (sönümsüz) frekansı $\omega_0 = \dfrac{1}{\sqrt{LC}} = \dfrac{1}{\sqrt{0.1\cdot10\cdot10^{-6}}} = 1000$ rad/s'dir (python ile kontrol edildi). Kaynak frekansı da $1000$ rad/s olduğundan $Z_{th}$ sonsuz çıkar.

### Soru 6 (ekrandan, 02:30:00)

Example 53 devresinde $v_a(t)$'yi bulun.

**Çözüm (düğüm denklemi derste kuruldu, sayısal sonuç düzeltildi):** $\dfrac{\mathbf{V}_a-20}{8+j9} + \dfrac{\mathbf{V}_a}{-j16} - 1.2\angle45^\circ - \dfrac{3\mathbf{V}_a}{j20} = 0$ denkleminden $\mathbf{V}_a = 12.43\angle-81.24^\circ$ V, $v_a(t) = 12.43\cos(250t-81.24^\circ)$ V (python ile). Derste bulunan değer için 8.1'deki nota bakın.

### Soru 7 (ekrandan, 02:45:00)

Example 56 devresinin Thevenin eşdeğerini bulun.

**Çözüm (açık devre kısmı derste verildi):** $\mathbf{I}_a = 0.2828\angle75^\circ$ A, $\mathbf{V}_{oc} = 7.071\angle-15^\circ$ V.

> **Çözüm (derste verilmedi):** 8.3'teki iki göz denklemi python ile çözüldü: $\mathbf{I}_{sc} = 0.106\angle-2.0^\circ$ A. Buradan $Z_{th} = \mathbf{V}_{oc}/\mathbf{I}_{sc} = 65 - j15 = 66.7\angle-13.0^\circ\ \Omega$; Norton eşdeğeri $\mathbf{I}_n = 0.106\angle-2.0^\circ$ A ve paralel $65 - j15\ \Omega$.

## Dersin Toparlaması

Bu derste fazör yönteminin bütün parçaları birleştirildi. Direnç, kapasite ve endüktansın zaman boyutundaki tanım bağıntılarından fazör karşılıkları türetildi: $Z_R = R$, $Z_C = 1/(j\omega C)$, $Z_L = j\omega L$. Empedans fazör uzayındaki Ohm yasası olarak, admitans da onun tersi olarak tanımlandı. Fazör uzayında diferansiyel denklemler cebirsel denklemlere dönüştüğü için seri/paralel birleştirme, düğüm ve çevre denklemleri, kaynak dönüşümleri, Thevenin ve Norton eşdeğerleri, gerilim ve akım bölücüler direnç devrelerindeki gibi, yalnız karmaşık sayılarla uygulanır. Her örnekte aynı yol izlendi: $\omega$ not edilir, kaynak kosinüs biçimli fazöre çevrilir, empedanslar bulunur, devre çözülür ve sonuç kosinüsle zaman boyutuna geri yazılır.

Örneklerde slaytlarda ve derste yapılan bazı sayısal hatalar ortaya çıktı; bu notta python ile düzeltildi. Toplamanın kartezyende, çarpma ve bölmenin polar biçimde yapılması, açıların radyan/derece birimine dikkat edilmesi ve sonuçların $\omega\to0$, $\omega\to\infty$ sınırlarıyla sağlanması dersin pratik dersleridir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
