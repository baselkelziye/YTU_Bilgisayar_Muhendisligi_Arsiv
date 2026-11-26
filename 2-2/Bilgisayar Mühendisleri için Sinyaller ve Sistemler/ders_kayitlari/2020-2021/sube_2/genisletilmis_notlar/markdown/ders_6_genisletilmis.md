# Ders 6 Genişletilmiş Notu: Sistem Özellikleri Örnekleri, Doğrusallık, Birim Dürtü Cevabı ve Sürekli Zamanda Konvolüsyon

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yeri ve Hedefi
- 2. Sürekli ve Ayrık Zaman Ayrımı
- 3. Bir Sinyali Birim Basamaklar Cinsinden Yazma
- 4. Çarpıcı Sistemin Özellikleri
- 5. Doğrusallık Testi
- 6. Sistemleri Sınıflandırmanın Amacı
- 7. Sinyali Kaydırılmış Dürtülerle Yazma
- 8. Birim Dürtü Cevabı
- 9. Konvolüsyon İntegrali
- 10. Grafiksel Konvolüsyon
- 11. Analitik Konvolüsyon Örneği
- Örnek Sorular

## 1. Dersin Yeri ve Hedefi

Ders, öğrencilere bu dersten ne beklediklerinin sorulmasıyla başladı. Gelen cevaplar ekrana yazıldı (ekrandan, 00:15:00 ve 00:25:00): sinyal işleme (doğadan alınan sinyalin, örneğin sesin, dijitale çevrilip yorumlanması), görüntü ve ses işleme, makine öğrenmesinin ve derin öğrenmenin temeli.

### 1.1 Önceki ve Sonraki Dersler

Hoca, dersin bir "serüvenin" ortasında durduğunu bir şemayla anlattı (ekrandan, 00:25:00):

```text
Önce:    Lineer cebir, Devre teorisi, Kalkülüs, Elektronik, Fizik,
         Diferansiyel denklemler / Mühendislik matematiği, Nümerik analiz
Şimdi:   Sinyaller ve Sistemler
Sonra:   DSP ve Görüntü işleme
Daha sonra: İleri DSP, İleri görüntü işleme, Bilgisayarlı görü,
            Konuşma ve ses işleme, Video işleme
En son:  Makine öğrenmesi, Derin öğrenme, Örüntü tanıma
```

Dersin iki yüzü vardır. Teorik yüzde Z, Laplace ve Fourier dönüşümleri, diferansiyel denklem çözümü, Taylor ve Maclaurin açılımları gibi araçlar ve bir fiziksel sistemin (bir havuz, bir aracın hız ya da konum-zaman denklemi, bir devre) denklemini kurup çözmek gerekir. Bu yüz daha çok kontrol, elektronik ve elektrik mühendislerini ilgilendirir. Bilgisayar mühendisliği için ağırlık algoritmik yüzdedir.

### 1.2 Bu Dersin Hedefi

Dersin hedefi şunlardır: sinyal nedir, sistem nedir, sinyallerin ve sistemlerin özellikleri nelerdir; sinyal zamanda nasıl kaydırılır, ölçeklenir; bir sinyal bilgisayarda nasıl saklanır (dizi ya da matris); ve bunlar zaman ve frekans domeninde nasıl incelenir. Zaman ya da frekans domeninden, fazdan anlam çıkarmak DSP ve ileri DSP'nin konusudur. Sinyal iki boyutluysa (görüntü) görüntü işleme devreye girer.

Hoca, bazı kitapların ve ders içeriklerinin bu dersin sınırını aşıp DSP konularına girdiğini, bu derste temel konuların sağlam öğretilmesinin daha doğru olduğunu söyledi. Görüntünün iki boyutlu bir matris, sesin bir dizi olarak saklandığını bilmeden hazır bir fonksiyona görüntü verip sonuç almak yüzeysel kalır.

### 1.3 Konvolüsyon ve Derin Öğrenme

Derin öğrenmenin en çok kullanılan modeli CNN'dir (Convolutional Neural Network). Konvolüsyon ve korelasyon bu dersin ayrı bir bölümüdür ve bu haftadan itibaren işlenmeye başlanır. Hoca, konvolüsyonu bu derste öğrenmeden DSP ya da derin öğrenmeye geçmenin anlamsız olduğunu vurguladı.

> **Hocanın vurgusu:** Konvolüsyonun ne olduğu, nasıl çalıştığı, mantığı ve algoritması bu derste öğrenilmelidir; sonraki derslerin temeli budur.

Bir görüntü üzerinde belirli bir maskeyle konvolüsyon yapmak, görüntüdeki kenarları (yatay, düşey ya da çapraz) bulmak demektir. Hoca bunu internetteki kenar bulma örnekleriyle gösterdi (ekrandan, 02:40:00): dikey kenarlar için sütunları $[1, 0, -1]$ biçiminde, yatay kenarlar için satırları $[1,1,1]$, $[0,0,0]$, $[-1,-1,-1]$ biçiminde olan $3\times3$ maskeler. CNN de görüntüdeki kenar ve köşeleri ayırt edici özellik olarak kullanır. Derin öğrenmeden önce ayırt edici özellikler elle çıkarılırdı; bunlar çoğu zaman aritmetik ortalama, standart sapma gibi istatistiksel ölçütlerdi.

Kenar neden ayırt edicidir? Çünkü kenarda renk (yoğunluk) bilgisi aniden değişir; beyazdan siyaha geçiş gibi. Değişim frekans demektir ve bu değişim yeni bir nesnenin başladığını gösterir.

Hoca, bu derste somut örneklerin daha çok matematiksel fonksiyonlar üzerinden olacağını, tıpkı türevin önce saf matematikte öğrenilip uygulamalarının sonra gelmesi gibi, uygulamaların ileriki derslerde ortaya çıkacağını söyledi.

> **Ek bilgi (derste anlatılmadı):** Görüntü işlemede kullanılan bu maskelerin en bilinenleri Prewitt ve Sobel operatörleridir. Derin öğrenme kütüphanelerindeki "konvolüsyon" katmanı aslında çoğu zaman maskeyi ters çevirmeden uygulanan çapraz korelasyondur; öğrenilen ağırlıklar için bu fark önemsizdir.

## 2. Sürekli ve Ayrık Zaman Ayrımı

Sinyaller ve sistemler iki koldan ilerler: sürekli zaman (continuous time) ve ayrık zaman (discrete time). Kararlılık, doğrusallık, konvolüsyon gibi konuların hemen hepsinin iki karşılığı vardır. Sürekli zamanda türev ve integral ile yapılan işler ayrık zamanda fark ve toplam ile yapılır. Bilgisayar mühendisleri daha çok ayrık taraftadır, ama sürekli zamandan örnekler de olacaktır.

Örnek: bir sisteme gelen sayının negatifini alan bir sistem tasarlayalım. 3 gelince $-3$, $-5$ gelince $5$ çıksın.

- Ayrık zamanda bu, gelen değeri $-1$ ile çarpan bir programdır (herhangi bir programlama dilinde, hatta Excel'de). Bir devreyle uğraşılmaz.
- Sürekli zamanda ise bunu yapan bir devre kurmak gerekir (kondansatör, direnç, bobin vb.). Gelen sinüzoidal dalganın tersini veren bir devre, $-1$ ile çarpmanın sürekli zamandaki karşılığıdır.

**Soru:** "Sistem tasarlamak" ne demek? **Cevap:** Girdiyi istenen çıktıya dönüştüren kuralı kurmaktır. Ayrık zamanda bu bir programlama dilinde yazılan bir işlemdir; sürekli zamanda ise aynı işi yapan bir devredir.

## 3. Bir Sinyali Birim Basamaklar Cinsinden Yazma

Ekrandaki soru (ekrandan, 00:35:00): "Express the signal in terms of unit step functions." Sinyal parçalı sabittir: $[-1,0)$ aralığında 1, $[0,1)$ aralığında 3, $[1,2)$ aralığında 2, $[2,3)$ aralığında 1, diğer yerlerde 0.

Birim basamak hatırlatıldı:

$$u(t) = \begin{cases} 1, & t \ge 0 \\ 0, & t < 0 \end{cases}$$

Basamaklar kullanılmasaydı bu sinyal parçalı bir fonksiyon olarak yazılırdı; değerler $t$'ye bağlı değildir, her aralıkta sabittir. Basamak cinsinden yazmak için sinyal soldan sağa taranır ve her sıçrama noktasına bir basamak konur:

- $t=-1$'de 0'dan 1'e çıkış: $u(t+1)$. Bu basamak $-1$'den başlar ve sonsuza gider.
- $t=0$'da 1'den 3'e çıkış (2 birim): $+2u(t)$.
- $t=1$'de 3'ten 2'ye iniş: $-u(t-1)$.
- $t=2$'de 2'den 1'e iniş: $-u(t-2)$.
- $t=3$'te 1'den 0'a iniş: $-u(t-3)$.

Sonuç (ekrandan, 00:40:00):

$$x(t) = u(t+1) + 2u(t) - u(t-1) - u(t-2) - u(t-3)$$

Derste çizim sırasında bir öğrenci $u(t+1)$'in yönünü sordu.

**Soru:** $u(t+1)$ grafikte $-1$'den sağa doğru gitmesi gerekmiyor mu? **Cevap:** Evet; $u(t+1)$, $t=-1$'de başlayıp sağa doğru sonsuza giden basamaktır. Hoca çizimi buna göre baştan düzeltti.

Hoca ayrıca ilk denemede iki terimi üst üste eklemeyi unuttuğu için yanlış bir değer yazdığını, düzeltilmiş halinin yukarıdaki olduğunu belirtti. Python ile aralık ortalarında kontrol edildi: $t=-0.5, 0.5, 1.5, 2.5, 3.5$ için değerler $1, 3, 2, 1, 0$ çıkar.

Sonsuza giden basamaklarla sınırlı süreli parçaları ifade etmek biraz zahmetlidir. Hoca, aynı sinyalin ileride başka temel sinyaller (birim dürtü) cinsinden de yazılacağını söyledi. <!-- BELİRSİZ: 00:42:43 civarında anlatılan alternatif yazımın ayrıntısı altyazıda net değil. -->

## 4. Çarpıcı Sistemin Özellikleri

Ekrandaki sistem (ekrandan, 00:45:00): bir çarpıcı (multiplier) bloğu, girişi $\cos\omega_0 t$ üreten bir osilatör çıkışıyla çarpar:

$$y(t) = x(t)\cos\omega_0 t$$

Soru: sistem (a) belleksiz (memoryless), (b) nedensel (causal), (c) doğrusal (linear), (d) zamanla değişmez (time-invariant), (e) kararlı (stable) mıdır?

Hoca önce iki uyarı yaptı. Birincisi, sinyallerin özellikleriyle sistemlerin özellikleri karıştırılmamalıdır; bunlar sistem özellikleridir. İkincisi, "causal" kelimesi "cause" (neden, sebep) kelimesinden gelir; "casual" (gündelik) ile karıştırılmamalıdır.

Ayrıca gösterimle ilgili sık bir karışıklığa değinildi: $x(t)$ ve $y(t)$ aslında birer değişken gibidir; $t$ yazılması yalnız ikisinin de zamana bağlı olduğunu gösterir. Asıl değişken $t$'dir. Zamanda öteleme yapılırken $x(t)$ yerine $x(t-T)$ yazılır, yani $x(t)$'nin geçtiği yere yeni ifade konur.

### 4.1 Belleksizlik

Sistemde şimdiki çıkışı hesaplamak için geçmiş değerlerin saklanmasına ya da ek bir belleğe ihtiyaç var mı? $y(t)$ yalnız aynı andaki $x(t)$'ye ve $\cos\omega_0 t$'ye bağlıdır. $x(t)$ zaten elimizdeki veridir; $\cos\omega_0 t$ doğrudan hesaplanır. $x(t-1)$ gibi bir terim olsaydı geçmiş değeri saklamak gerekirdi. Bu yüzden sistem **belleksizdir**.

### 4.2 Nedensellik

Nedensel sistemde çıkış yalnız şimdiki ve önceki giriş değerlerine bağlı olmalıdır ("$y(t)$ must depend on current and previous values"). Burada $y(t)$ yalnız şimdiki $x(t)$'ye bağlıdır; sistem **nedenseldir**.

### 4.3 Doğrusallık

Doğrusallık için süperpozisyon sağlanmalıdır: toplamsallık (Law of Additivity) ve homojenlik/çarpımsallık (Law of Homogeneity). İkisi tek adımda test edilebilir (ekrandan, 00:55:00):

$$x(t) = a_1x_1(t) + a_2x_2(t)$$

$$y(t) = \left[a_1x_1(t) + a_2x_2(t)\right]\cos\omega_c t = a_1\,x_1(t)\cos\omega_c t + a_2\,x_2(t)\cos\omega_c t$$

$x_1$'e karşılık çıkış $y_1(t) = x_1(t)\cos\omega_c t$, $x_2$'ye karşılık $y_2(t) = x_2(t)\cos\omega_c t$ olduğundan sonuç $a_1y_1(t) + a_2y_2(t)$'dir. Ayrı ayrı uygulamak ile birlikte uygulamak aynı çıktıyı verir; sistem **doğrusaldır**. Burada çarpan $\cos\omega_c t$ girişe bağlı değildir, yalnız $t$'ye bağlıdır; bu yüzden doğrusallığı bozmaz.

### 4.4 Zamanla Değişmezlik

Tanım: $x(t) \to y(t)$ ise $x(t-T) \to y(t-T)$ olmalıdır. Test iki yoldan yapılır (ekrandan, 01:00:00):

- Girişi geciktir: $y_1(t) = T\{x(t-T)\} = x(t-T)\cos\omega_0 t$. Sistem yalnız $x$'e uygulanan değişikliği görür, kosinüsün içindeki $t$ değişmez.
- Çıkışı geciktir: $y(t-T) = x(t-T)\cos\omega_0(t-T)$. Burada $t$'nin geçtiği her yer değişir.

İkisi eşit değildir. Sistem **zamanla değişmez değildir** (not time-invariant), yani zamanla değişendir.

> **Hocanın vurgusu:** Kilit nokta şudur: girişteki değişiklik yalnız $x$'in argümanını etkiler, çıkıştaki öteleme ise ifadedeki bütün $t$'leri etkiler.

### 4.5 Kararlılık

Kararlılık BIBO (bounded input, bounded output) ile tanımlanır: sınırlı giriş sınırlı çıkış vermelidir. $x(t)$ sınırlıdır; kosinüs zaten tanımı gereği $[-1,1]$ aralığındadır. Sınırlı iki şeyin çarpımı sonsuza gidemez. Hatta kosinüs girişi en fazla 1 ile çarptığından $|y(t)| \le |x(t)|$ olur. Sistem **kararlıdır**.

### 4.6 Nedensellik Üzerine Ek Açıklama

Hoca nedenselliği gündelik dille açıkladı: "Bilgisayarı açtım çünkü dersim var." Burada neden (dersin varlığı) önce gelir, sonuç (bilgisayarı açmak) sonra. "Karnım aç, yemek yiyorum" da aynı yapıdadır. Sistemde de çıkışı üreten neden şimdiki ya da önceki değerlerdir. $y(t) = x(t+1)$ gibi gelecekteki değere bağlı bir sistem gerçek zamanda yoktur, nedensel değildir.

Bir başka örnek faiz problemidir: bankadaki paranın bir sonraki aydaki miktarı, bir önceki aydaki miktara ve sabit faiz oranına bağlıdır. Sabit oran sonucu "nedenlemez"; önceki ayın miktarı ise sonucun nedenidir. Böyle bir sistem özyinelemeli (rekürsif) düşünülür. <!-- BELİRSİZ: faiz örneğinin derste söylenen tam formülü altyazıda net değil (01:02:46); oran olarak 0,05 geçiyor. -->

> **Ek bilgi (derste anlatılmadı):** Aylık %5 faizle bu sistem büyük olasılıkla $y[n] = 1{,}05\,y[n-1]$ ya da girişli halde $y[n] = 1{,}05\,y[n-1] + x[n]$ biçiminde yazılır. Çıkış yalnız şimdiki giriş ve geçmiş çıkışa bağlı olduğu için nedenseldir.

## 5. Doğrusallık Testi

Aradan sonra doğrusallık genel algoritma olarak yeniden anlatıldı (ekrandan, 01:25:00).

### 5.1 Toplamsallık (Law of Additivity)

- $x_1$ sisteme tek başına verilir, çıkış $y_1$ olur.
- $x_2$ sisteme tek başına verilir, çıkış $y_2$ olur.
- Bu ikisi toplanır: $y_1 + y_2$.
- Sonra girişler önce toplanır, $x_1 + x_2$ sisteme verilir; çıkışa $y_3$ denir.
- $y_3 = y_1 + y_2$ ise toplamsallık sağlanır.

Bu sağlanmıyorsa homojenliğe bakmaya gerek yoktur; sistem doğrusal değildir.

### 5.2 Homojenlik (Law of Homogeneity)

$x(t) \to y(t)$ olsun. Girişi bir $c$ sabitiyle çarpıp $c\,x(t)$ sisteme verilir ve çıkışa $\hat y(t)$ denir. $\hat y(t) = c\,y(t)$ ise homojenlik sağlanır. Bu özelliğe çarpımsallık (multiplicity) da denir, ama "homogeneity" daha yaygındır.

İki kural birlikte sağlanırsa ("if LoA && LoH then system is linear") sistem doğrusaldır.

### 5.3 Örnek: $y(t) = x(t)\sin t$

Toplamsallık (ekrandan, 01:25:00):

- $y_1(t) = x_1(t)\sin t$, $y_2(t) = x_2(t)\sin t$, toplam $x_1(t)\sin t + x_2(t)\sin t$.
- $x_3 = x_1(t) + x_2(t)$ için $y_3(t) = \left[x_1(t) + x_2(t)\right]\sin t$; açılınca toplamla aynıdır. Toplamsallık sağlandı.

Homojenlik (ekrandan, 01:35:00):

- Giriş $c\,x_1(t)$ iken çıkış $c\,x_1(t)\sin t$ olur.
- $c\,y_1(t) = c\,x_1(t)\sin t$; ikisi eşittir. Homojenlik sağlandı.

Sistem doğrusaldır.

### 5.4 Örnek: $y(t) = 2x(t) + 4$

Bu soru önce öğrencilere bırakıldı. Görünüşte $y = 2x + 4$ bir doğru denklemidir; iki noktası bilinen bir doğru gibi yazılabilir. Ama sistem olarak doğrusal değildir.

Homojenlik (ekrandan, 01:35:00):

- Giriş $c\,x_1(t)$ iken $y_1(t) = 2c\,x_1(t) + 4$.
- $c\,y(t) = c\left(2x_1(t) + 4\right) = 2c\,x_1(t) + 4c$.
- $4 \ne 4c$ (genel $c$ için), homojenlik sağlanmaz.

Toplamsallık:

- $y_1(t) = 2x_1(t) + 4$, $y_2(t) = 2x_2(t) + 4$, toplamları $2\left(x_1(t) + x_2(t)\right) + 8$.
- $x_3 = x_1 + x_2$ için $y_3(t) = 2\left(x_1(t) + x_2(t)\right) + 4$.
- Sabit terim yüzünden $8 \ne 4$; toplamsallık da sağlanmaz.

Sistem doğrusal değildir. Bu tür sistemlere **afin** (affine) denir.

> **Hocanın vurgusu:** Grafiği doğru olan her ilişki doğrusal sistem değildir; sabit terim doğrusallığı bozar.

## 6. Sistemleri Sınıflandırmanın Amacı

Bir sistemin davranışını bir denklemle yazmak mühendislikte esastır. Bu denkleme sistemin denklemi, matematiksel modeli, modeli ya da transfer fonksiyonu denir. Bu denklemi kurmak kalkülüs, fizik, diferansiyel denklemler ve mühendislik matematiğinin işidir.

Şimdiye kadar incelenen ifadeler ($y(t) = x(t)\sin t$ gibi) zaten çözülmüş ifadelerdir. Gerçekte gelen denklemler çoğunlukla $y$'nin ikinci türevi, birinci türevinin karesi, $-2y + x(t)$ gibi terimler içeren uzun diferansiyel denklemlerdir. Denklemi kurmak bir mesele, çözmek ayrı bir meseledir. Çözüm yöntemi denklemin sınıfına göre seçilir: doğrusal mı, homojen mi, zamanla değişmez mi, bellekli mi, kararlı mı. Benzer bir çözümün ayrık karşılığı ayrık matematikteki rekürans bağıntılarıdır.

Sınıflandırmanın bir amacı da budur. Bundan sonraki derslerde doğrusal ve zamanla değişmeyen (Linear Time-Invariant, LTI) sistemler üzerinde çalışılacaktır; doğrusal olmayan ya da zamanla değişen sistemler kapsam dışında kalacaktır. Elektronik ve bilgisayar alanlarında genellikle LTI sistemlerle başlanır, sonra doğrusal olmayan sistemlere geçilir.

Hatırlatma: $x(t)$, $y(t)$ gibi zamana bağlı sinyaller sürekli zamanlı, $x[n]$ gibi indise bağlı sinyaller ayrık zamanlıdır.

## 7. Sinyali Kaydırılmış Dürtülerle Yazma

Herhangi bir sinyal bilindik bir temel sinyal cinsinden yazılabilir mi? Dikdörtgen ve birim basamak burada kullanışlı değildir; birim dürtü (Dirac delta) ise uygundur (ekrandan, 01:45:00).

Birim dürtünün özelliği: $\delta(t)$ yalnız $t=0$ anında sıfırdan farklıdır, diğer bütün anlarda sıfırdır. Ötelenmiş $\delta(t-T)$ ise yalnız $t=T$ anında sıfırdan farklıdır.

> **Ders sonrası not:** Hoca $\delta(t)$'nin $t=0$'da "1 olduğunu" söyledi (ekranda da $\delta(t)\big|_{t=0} = 1$ yazıldı). Bu ayrık zamandaki $\delta[n]$ için doğrudur: $\delta[0]=1$. Sürekli zamandaki Dirac dürtüsünün $t=0$'daki değeri tanımlı bir sayı değildir; tanımlayıcı özelliği alanının 1 olmasıdır: $\int_{-\infty}^{\infty}\delta(t)\,dt = 1$.

### 7.1 Ayrık Zaman Örneği

Sözlü olarak verilen sinyal: $x[-2]=3$, $x[-1]=2$, $x[1]=2$, $x[4]=6$, diğer değerler 0. Bu sinyal şöyle yazılabilir:

$$x[n] = 3\,\delta[n+2] + 2\,\delta[n+1] + 2\,\delta[n-1] + 6\,\delta[n-4]$$

Örneğin $\delta[n+2]$ yalnız $n=-2$'de 1 olur; o noktada $x[-2]=3$ ile çarpılır. Genel ve kısa hali:

$$x[n] = \sum_{k=-2}^{4} x[k]\,\delta[n-k]$$

Sınırlar $-\infty$ ile $+\infty$ alınırsa her ayrık sinyal için geçerli olur.

### 7.2 Sürekli Zaman Karşılığı

Sürekli zamanda adımlar birer birer değil, sonsuz küçük $d\tau$ adımlarla ilerler. Her $\tau$ anındaki değer ötelenmiş dürtüyle çarpılır ve hepsi integralle toplanır:

$$x(t) = \int_{-\infty}^{\infty} x(\tau)\,\delta(t-\tau)\,d\tau$$

İntegrandda yalnız $\tau = t$ olduğunda dürtü sıfırdan farklıdır; bu yüzden integral $x(t)$'yi verir.

## 8. Birim Dürtü Cevabı

### 8.1 Tanım

Bir sisteme birim dürtü uygulanınca alınan çıkışa **birim dürtü cevabı** (impulse response) denir ve genelde $h(t)$ ya da $h[n]$ ile gösterilir. Hoca bunu sistemin "röntgenini çekmek" diye anlattı: sisteme baştan sona dürtüler uygulanınca sistemin davranışı bulunur. Sonra bu cevaptan yola çıkarak, sistem doğrusal ve zamanla değişmezse, herhangi bir girişe karşı çıkış bulunabilir.

Slayttaki tanım (ekrandan, 01:50:00): doğrusal bir sistemin dürtü cevabı $h_\tau(t)$, sistemin $\tau$ anındaki bir dürtüye $t$ anında verdiği çıkıştır:

$$h_\tau = H(\delta_\tau)$$

Slaytta $\delta(t)$ girişine $h(t,0)$, $\delta(t-\tau)$ girişine $h(t,\tau)$ çıkışı gösterilmiştir; genel bir sistemde bu iki çıkışın biçimi farklı olabilir.

### 8.2 Gösterimdeki Karışıklık

$h_\tau(t) = H(\delta_\tau(t))$ yazıldığında $t$ eşitliğin iki yanında farklı roller oynar (ekrandan, 02:00:00):

- Soldaki $t$ belirli bir zaman değeridir; çıkışın örneklendiği andır.
- Sağdaki $t$ bütün gerçel sayılar üzerinde değişir; soldakiyle aynı $t$ değildir.
- Belirli bir andaki çıkış genelde girişin bütün dalga biçimine bağlıdır.

### 8.3 Zamanla Değişmezlik

$H$ zamanla değişmezse, girişi ve çıkışı aynı $\tau$ kadar geciktirmek aynı cevabı verir (ekrandan, 02:05:00):

$$h_\tau(t) = h(t-\tau)$$

Bu durumda $h_\tau$ ile ayrıca uğraşmaya gerek yoktur; o yalnız $h$'nin zamanda ötelenmiş halidir. Böylece sinyalin bütün değerleri yeterince ötelenmiş dürtüler cinsinden yazılabilir. Sistem doğrusal olduğu için de toplamsallık ve homojenlik kullanılarak her ötelenmiş dürtünün cevabı aynı ağırlıkla toplanabilir.

Nedensel bir sistemde dürtü cevabı $t<0$ için sıfırdır; sistemin davranışı $t \ge 0$ kısmında görülür.

### 8.4 Dürtü Cevabını Ölçmek

Slayttaki örnek (ekrandan, 02:15:00): bir LTI sistemin $h(t)$ dürtü cevabını ölçmek istiyoruz. Pratikte zordur, çünkü girişin genliği sınırlıdır ve çok kısa bir darbenin enerjisi çok azdır. Yaygın bir alternatif, birim basamak girişine verilen cevabı, yani **basamak cevabını** $s(t)$ ölçmektir. Hoca, slaytta dürtü cevabı ile basamak cevabı arasında türev ve integral ile gidip gelindiğini gösterdi: basamak cevabının türevi alınarak dürtü cevabına dönülür.

> **Ek bilgi (derste anlatılmadı):** LTI sistemde $u(t) = \int_{-\infty}^{t}\delta(\lambda)\,d\lambda$ olduğu için basamak cevabı $s(t) = \int_{-\infty}^{t} h(\lambda)\,d\lambda$, dürtü cevabı da $h(t) = \dfrac{ds(t)}{dt}$ olur.

## 9. Konvolüsyon İntegrali

### 9.1 LTI Sistemin Çıkışı

Nihai hedef: bir LTI sisteme bir giriş uygulandığında çıkışı bulmak. $x(t)$ ötelenmiş dürtülerin integrali olarak yazılır, her dürtünün cevabı $h(t-\tau)$ olur ve sonuçlar toplanır. Böylece çıkış, girişle dürtü cevabının "çarpılıp toplanması" olur. Bu yeni işleme **konvolüsyon** (katlama) denir (ekrandan, 02:10:00):

$$y(t) = x(t) * h(t) = \int_{-\infty}^{\infty} x(\tau)\,h(t-\tau)\,d\tau$$

Slayt, aynı ilişkinin frekans ve Laplace domenindeki karşılığını da verir: $x(t) \leftrightarrow X(\omega)$, $x(t) \leftrightarrow X(s)$, $h(t) \leftrightarrow H(\omega)$, $h(t) \leftrightarrow H(s)$ ise

$$Y(\omega) = H(\omega)X(\omega), \qquad Y(s) = H(s)X(s)$$

$$\mathcal{F}^{-1}\{X(\omega)H(\omega)\} = x(t)*h(t), \qquad \mathcal{L}^{-1}\{X(s)H(s)\} = x(t)*h(t)$$

$H(\omega)$ frekans cevabı, $H(s)$ transfer fonksiyonudur. Hoca bu dönüşümlerin ilerideki konular olduğunu, şimdilik bunlara takılmamak gerektiğini söyledi. Bu dönüşümler diferansiyel denklemleri doğrudan çözmeden sistem çıkışını bulmanın yoludur.

Hoca konvolüsyonu şöyle özetledi: birinci sinyalle ikinci sinyali alıp çarpıp toplamak (integralini almak). Bir LTI sistemin dürtü cevabı biliniyorsa, sistemin davranışı biliniyor demektir; girişi bu cevapla konvolüsyona sokmak çıkışı verir. Sistem denklemine $x(t)$'yi yerine koymak yerine, sistem bir kara kutu olarak dürtü cevabıyla temsil edilir.

### 9.2 Nedensel Durumlar

Sistem nedenselse $h(t-\tau)$, $\tau > t$ için sıfırdır; integralin üst sınırı $t$ olur. Giriş de nedenselse ($t<0$ için sıfır) alt sınır 0 olur:

$$y(t) = \int_{0}^{t} x(\tau)\,h(t-\tau)\,d\tau$$

Böylece sonsuz sınırlardan kurtulunur.

### 9.3 Özellikler

- Değişme: $x*h = h*x$.
- Birleşme: $(x*h_1)*h_2 = x*(h_1*h_2)$.
- Dağılma: $x*(h_1+h_2) = x*h_1 + x*h_2$. Sistemlerin birbirine bağlanmasında (interconnection) kullanılır.
- Türev: $y = x*h$ ise $y' = x'*h = x*h'$.
- İntegral: çıkışın integrali, girişin integralinin dürtü cevabıyla ya da girişin dürtü cevabının integraliyle konvolüsyonuna eşittir.

### 9.4 Sürekli ve Ayrık Konvolüsyon

Sürekli zamanda konvolüsyon **integral** ile yapılır (konvolüsyon integrali), ayrık zamanda **toplam** ile yapılır (konvolüsyon toplamı). Başka bir farkı yoktur. Sürekli zamanda iki yol vardır: analitik çözüm (integralin doğrudan hesabı) ya da grafiksel çözüm.

Ayrık zamandaki genel ifade $x[n] = \sum_k x[k]\,\delta[n-k]$ içindeki $n-k$ terimi, grafik çözümünde ikinci sinyalin ters çevrilmesi demektir; sürekli zamandaki $t-\tau$ da aynı anlama gelir.

## 10. Grafiksel Konvolüsyon

### 10.1 Adımlar

Slayttaki adımlar (ekrandan, 02:20:00), $y(t) = \int_{-\infty}^{\infty} x(\tau)h(t-\tau)\,d\tau$ için:

1. Sinyalleri $\tau$ cinsinden yeniden yaz: $x(\tau)$ ve $h(\tau)$.
2. Sinyallerden yalnız birini $t=0$ etrafında ters çevir (flip): $x(-\tau)$ ya da $h(-\tau)$. Genelde süresi kısa olanı çevirmek daha kolaydır. Gösterim için burada $h(-\tau)$ kullanılır.
3. Ters çevrilmiş sinyalin kenarlarını (edge) bul: sol kenar $\tau_{L,0}$, sağ kenar $\tau_{R,0}$.
4. $h(-\tau)$'yu $t$ kadar kaydırıp $h(t-\tau)$'yu elde et. Kenarlar her zaman $\tau_{L,t} = t + \tau_{L,0}$ ve $\tau_{R,t} = t + \tau_{R,0}$ olur. Ters çevrilen sinyal sonlu süreli değilse kenarlardan biri ya da ikisi sonsuz olur ($\tau_{L,t} = -\infty$ ve/veya $\tau_{R,t} = \infty$).
5. Örtüşme bölgelerini belirle.
6. Her bölgede çarpımı kur ve integralini al.

Değişme özelliği sayesinde iki yazım eşittir; bu yüzden hangi sinyalin ters çevrileceği serbesttir (ekrandan, 02:25:00):

$$y(t) = \int_{-\infty}^{\infty} h(\tau)\,x(t-\tau)\,d\tau = \int_{-\infty}^{\infty} x(\tau)\,h(t-\tau)\,d\tau$$

Kaydırılan sinyal her adımda diğeriyle çarpılır; integral olduğu için bu, örtüşen bölgenin altında kalan alanın hesabıdır. Ayrık zamanda ise çarpıp toplamak yeterlidir ve daha kolaydır. Kaydırılan sinyal sonsuza gidiyorsa (örneğin birim basamak) ve diğeri de sonsuza gidiyorsa sonsuz bir alan elde edilebilir.

Örtüşme başladığı anda konvolüsyon sonucu sıfırdan farklı değerler almaya başlar. Örtüşen alan büyüdükçe sonuç artar, bir yerde sabitlenebilir ya da azalmaya başlar; tamamen sinyallere bağlıdır. Sinyaller parçalıysa her parça ayrı değerlendirilir ve her bölgenin sonucu ayrı yazılır.

### 10.2 Örnek: İki Dikdörtgenin Konvolüsyonu

Slayttaki örnek (ekrandan, 02:25:00): $x(t) = 2$ ($0 \le t \le 2$), $h(t) = 3$ ($0 \le t \le 1$), diğer yerlerde ikisi de sıfır. Sistemin davranışı $h(t)$, giriş $x(t)$'dir; $y(t) = x(t)*h(t)$ aranır.

Kısa olan $h$ ters çevrilir: $h(-\tau)$, $[-1, 0]$ aralığında 3 olur. Kaydırılınca $h(t-\tau)$, $[t-1, t]$ aralığında 3'tür. Sola kaydırmanın anlamı yoktur (hep sıfırla çarpılır); sağa doğru kaydırılır. Hoca bunu bir trenin tünele girip çıkmasına benzetti.

- **Bölge I, $t<0$** (ekrandan, 02:30:00): örtüşme yoktur; integrand sıfırdır, sınırların önemi yoktur. $y(t) = 0$.
- **Bölge II, $0 \le t \le 1$** (ekrandan, 02:30:00): örtüşme $[0, t]$ aralığıdır. Çarpım $2 \times 3 = 6$:
  $$y(t) = \int_0^t 6\,d\tau = \left[6\tau\right]_0^t = 6t$$
- **Bölge III, $1 \le t \le 2$:** kısa dikdörtgen tamamen $x$'in içindedir, örtüşme $[t-1, t]$:
  $$y(t) = \int_{t-1}^{t} 6\,d\tau = 6$$
  Burada $t$'ye bağlı değişim yoktur; bir plato (durağan bölge) oluşur.
- **Bölge IV, $2 \le t \le 3$:** dikdörtgen $x$'ten çıkmaktadır, örtüşme $[t-1, 2]$:
  $$y(t) = \int_{t-1}^{2} 6\,d\tau = 6(3-t) = 18 - 6t$$
- **Bölge V, $t > 3$:** örtüşme kalmaz, $y(t) = 0$.

Bütün bölgeler birleştirilince:

$$y(t) = \begin{cases} 0, & t < 0 \\ 6t, & 0 \le t \le 1 \\ 6, & 1 \le t \le 2 \\ 18 - 6t, & 2 \le t \le 3 \\ 0, & t > 3 \end{cases}$$

Sonuç bir yamuktur: 0'dan doğrusal yükselir, 1 ile 2 arasında 6'da sabit kalır, 3'te tekrar 0'a iner. Python ile sayısal konvolüsyonla doğrulandı ($t=0.5$ için 3, $t=1.5$ için 6, $t=2.5$ için 3, $t=3.5$ için 0).

> **Ders sonrası not:** Hoca anlatırken, ters çevrilmiş dikdörtgen tam $t=0$'a geldiğinde çarpımın "$3 \times 2 = 6$ ile başladığını" söyledi. Çarpımın yüksekliği 6'dır, ama integral (alan) $t=0$'da sıfırdır ve $6t$ ile doğrusal artar; slayttaki sonuç da $y(t)=6t$'dir.

**Soru:** Bölge IV'te ($2 \le t \le 3$) sonuç neden sıfır olmuyor? **Cevap:** Dikdörtgen $x$'ten ayrılırken hâlâ bir örtüşme vardır; çarpım yine 6'dır ama örtüşen genişlik azaldıkça alan azalır. Sinyallerden en az biri sıfır olana kadar, yani örtüşme tamamen bitene kadar sonuç sıfır olmaz.

### 10.3 Animasyon ve Benzerlik Yorumu

Hoca bir web sitesindeki animasyonla konvolüsyonu gösterdi (ekrandan, 02:35:00): bir sinyal ($f_2$) ters çevrilip kaydırılıyor, çarpımın altında kalan alan (kırmızı) önce artıyor, sonra azalıyor ve alttaki grafikte konvolüsyon sonucu çiziliyor. İki sinyal ayrılana kadar çarpım devam eder.

Eşit genişlikli iki dikdörtgenin konvolüsyonunda plato oluşmaz, sivri bir tepe oluşur; çünkü tam örtüşme yalnız tek bir kaydırma değerinde gerçekleşir. Tepe noktası, iki sinyalin birbirine en çok benzediği, tam çakıştığı yerdir. Hoca bunu görüntüde göz bulma örneğiyle anlattı: büyük bir yüz fotoğrafı ile gözün küçük bir parçası konvolüsyona sokulduğunda, sonucun en büyük olduğu yer gözün tam çakıştığı yerdir. Bulunan bölge daha büyük bir yapıdan oluşuyorsa tepe yerine bir plato çıkar. İki sinyal birbirine çok benzemiyorsa tek ve belirgin bir tepe çıkmaz.

> **Ek bilgi (derste anlatılmadı):** Şablon eşleştirmede (template matching) benzerlik ölçümü için genelde konvolüsyon değil korelasyon kullanılır; korelasyonda şablon ters çevrilmez. Simetrik şablonlarda ikisi aynı sonucu verir. Korelasyon dersin ilerleyen bölümlerinde konvolüsyonla birlikte ele alınacak konudur.

Slayttaki başka bir örnekte (ekrandan, 02:45:00) iki dikdörtgen $x_1(t)$ ve $x_2(t)$ verilmiştir; $x_2(-\tau)$ ters çevrilip $t = -0.5, 0, 1, 2, 2.5$ için $x_1(\tau)x_2(t-\tau)$ çarpımları gösterilmiş, sonuç $x_1(t)*x_2(t)$ en büyük değeri 6 olan bir yamuk olarak çizilmiştir. <!-- BELİRSİZ: bu slayttaki dikdörtgenlerin tam yükseklik ve genişlikleri karede net okunamadı. --> Üçgen sinyallerin konvolüsyonunda ise tepe yine en çok benzeyen orta noktadadır, ama geçişler yumuşaktır.

### 10.4 RC Devresi Örneği

Slaytta bir RC devresinin dürtü cevabı ile basamak girişinin konvolüsyonu anlatıldı. Analitik çözüm:

- $t < 0$ için giriş sıfırdır, integral 0 olur.
- $t > 0$ için $h(t) = \dfrac{1}{RC}e^{-t/RC}u(t)$ ve $x(t) = u(t)$ alınır; ters çevrilen $h$ ile integral $0$ ile $t$ arasında alınır:

$$y(t) = \frac{1}{RC}\int_0^t e^{-(t-\tau)/RC}\,d\tau = \left(1 - e^{-t/RC}\right)u(t)$$

Hoca, RLC/RC devrelerinde akım ve gerilim denkleminden dürtü cevabının bulunabileceğini, sonra herhangi bir giriş için çıkışın konvolüsyonla hesaplanacağını söyledi. Slaytlarda diferansiyel denklem çözümleri ve MATLAB ile konvolüsyon kodu da bulunuyordu; bunlar derste ayrıntılı işlenmedi. <!-- BELİRSİZ: RC örneğinin slayttaki tam yazımı karelerde okunamadı; ifade altyazıdaki sözlü anlatıma göre yazıldı (02:43:47). -->

## 11. Analitik Konvolüsyon Örneği

Ekrandaki soru (ekrandan, 02:50:00): "Evaluate $y(t) = x(t)*h(t)$, where $x(t) = u(t) - u(t-3)$ and $h(t) = u(t) - u(t-2)$, (a) by an analytical technique, and (b) by a graphical method." $x(t)$, $[0,3]$ aralığında 1; $h(t)$, $[0,2]$ aralığında 1 olan dikdörtgenlerdir.

### 11.1 İntegrali Kurma

$$y(t) = \int_{-\infty}^{\infty} x(\tau)\,h(t-\tau)\,d\tau = \int_{-\infty}^{\infty}\left[u(\tau) - u(\tau-3)\right]\left[u(t-\tau) - u(t-\tau-2)\right]d\tau$$

$h$ ters çevrilip $\tau$ kadar ötelendiğinde $u(t)$ terimi $u(t-\tau)$, $u(t-2)$ terimi $u(t-\tau-2)$ olur. Çarpım açılınca dört integral çıkar (ekrandan, 02:55:00):

$$y(t) = \int u(\tau)u(t-\tau)\,d\tau - \int u(\tau)u(t-2-\tau)\,d\tau - \int u(\tau-3)u(t-\tau)\,d\tau + \int u(\tau-3)u(t-2-\tau)\,d\tau$$

### 11.2 Her Çarpımın Sıfırdan Farklı Olduğu Aralık

Her terim, iki basamağın çarpımı olduğundan belirli bir aralıkta 1, dışında 0'dır (ekrandan, 02:55:00):

- $u(\tau)\,u(t-\tau) = 1$, eğer $0 < \tau < t$ ve $t > 0$; diğer durumlarda 0.
- $u(\tau)\,u(t-2-\tau) = 1$, eğer $0 < \tau < t-2$ ve $t > 2$; diğer durumlarda 0.
- $u(\tau-3)\,u(t-\tau) = 1$, eğer $3 < \tau < t$ ve $t > 3$; diğer durumlarda 0.
- $u(\tau-3)\,u(t-2-\tau) = 1$, eğer $3 < \tau < t-2$ ve $t > 5$; diğer durumlarda 0.

### 11.3 İntegrallerin Hesabı

$$y(t) = \left[\int_0^t d\tau\right]u(t) - \left[\int_0^{t-2} d\tau\right]u(t-2) - \left[\int_3^{t} d\tau\right]u(t-3) + \left[\int_3^{t-2} d\tau\right]u(t-5)$$

$$y(t) = t\,u(t) - (t-2)\,u(t-2) - (t-3)\,u(t-3) + (t-5)\,u(t-5)$$

Hoca, integralin uzun göründüğünü ama sınırlar ve basamaklar yüzünden birçok terimin düştüğünü söyledi. Sonuç python ile sayısal konvolüsyonla doğrulandı ($t = 0.5, 1, 2.5, 4, 5.5$ için $0.5, 1, 2, 1, 0$).

Grafiksel çözümde ise ifade 0'dan küçük, $[0,2]$, $[2,3]$, $[3,5]$ ve 5'ten büyük aralıklar olmak üzere beş parçaya bölünür ve her parçada alan hesaplanır. Sonuç yine bir yamuktur: 0 ile 2 arasında $t$ ile yükselir, 2 ile 3 arasında 2'de sabit kalır, 3 ile 5 arasında $5-t$ ile iner.

### 11.4 Ters Çevirme Üzerine Soru

**Soru:** Konvolüsyonda ters çevirme işlemi tam olarak hangi noktada ve neden yapılıyor? **Cevap:** Ayrık zamanda $x[n] = \sum_k x[k]\,\delta[n-k]$ yazılırken $k$'ıncı değer, $n-k$ ile ötelenmiş dürtüyle eşleştirilir; bu birebir bir terslemedir. Sürekli zamanda aynı yapı $x(\tau)\,h(t-\tau)$ ile görülür: $\tau$'nun önündeki eksi işareti, ikinci sinyalin ters çevrilmesi demektir. $x$'in $\tau$ anındaki değeri, $\tau$ kadar ötelenmiş (ters çevrilmiş) sinyalle çakıştırılarak benzerliğe bakılır.

## Örnek Sorular

### Soru 1: Birim basamaklarla yazma (ekrandan, 00:35:00)

Şekildeki sinyali birim basamak fonksiyonları cinsinden yazınız. Sinyal: $[-1,0)$ aralığında 1, $[0,1)$ aralığında 3, $[1,2)$ aralığında 2, $[2,3)$ aralığında 1, diğer yerlerde 0.

> **Çözüm (derste verildi, ekrandan, 00:40:00):** Sıçrama noktalarında sıçrama büyüklüğüyle çarpılmış basamaklar toplanır:
> $x(t) = u(t+1) + 2u(t) - u(t-1) - u(t-2) - u(t-3)$.

### Soru 2: Çarpıcı sistemin özellikleri (ekrandan, 00:45:00)

$y(t) = x(t)\cos\omega_0 t$ ile tanımlı çarpıcı sistemin (a) belleksiz, (b) nedensel, (c) doğrusal, (d) zamanla değişmez, (e) kararlı olup olmadığını belirleyiniz.

> **Çözüm (derste verildi):** (a) Belleksiz; çıkış yalnız aynı andaki girişe bağlı. (b) Nedensel. (c) Doğrusal; $a_1x_1 + a_2x_2 \to a_1y_1 + a_2y_2$. (d) Zamanla değişmez değil; $x(t-T)\cos\omega_0 t \ne x(t-T)\cos\omega_0(t-T)$. (e) Kararlı; $|y(t)| \le |x(t)|$.

### Soru 3: $y(t) = x(t)\sin t$ doğrusal mı? (ekrandan, 01:25:00)

> **Çözüm (derste verildi):** Toplamsallık: $(x_1+x_2)\sin t = x_1\sin t + x_2\sin t = y_1 + y_2$. Homojenlik: $c\,x_1 \to c\,x_1\sin t = c\,y_1$. İki koşul da sağlanır; sistem doğrusaldır.

### Soru 4: $y(t) = 2x(t) + 4$ doğrusal mı? (derste sözlü, 01:28:11; ekrandan, 01:35:00)

> **Çözüm (derste verildi):** Homojenlik: $c\,x_1 \to 2c\,x_1 + 4 \ne c(2x_1+4) = 2c\,x_1 + 4c$. Toplamsallık: $y_1 + y_2 = 2(x_1+x_2) + 8 \ne y_3 = 2(x_1+x_2) + 4$. Sistem doğrusal değildir; afin bir sistemdir.

### Soru 5: Ayrık sinyali dürtülerle yazma (derste sözlü, 01:45:20)

$x[-2]=3$, $x[-1]=2$, $x[1]=2$, $x[4]=6$ (diğerleri 0) olan sinyali birim dürtüler cinsinden yazınız.

> **Çözüm (derste verildi):** $x[n] = 3\delta[n+2] + 2\delta[n+1] + 2\delta[n-1] + 6\delta[n-4] = \sum_{k=-2}^{4} x[k]\,\delta[n-k]$.

### Soru 6: İki dikdörtgenin grafiksel konvolüsyonu (ekrandan, 02:25:00)

$x(t) = 2$ ($0 \le t \le 2$), $h(t) = 3$ ($0 \le t \le 1$), diğer yerlerde sıfır. $y(t) = x(t)*h(t)$'yi bulunuz.

> **Çözüm (derste verildi, ekrandan, 02:30:00):** $y(t) = 0$ ($t<0$); $6t$ ($0 \le t \le 1$); $6$ ($1 \le t \le 2$); $18-6t$ ($2 \le t \le 3$); $0$ ($t>3$).

### Soru 7: Analitik konvolüsyon (ekrandan, 02:50:00)

$x(t) = u(t) - u(t-3)$ ve $h(t) = u(t) - u(t-2)$ için $y(t) = x(t)*h(t)$'yi (a) analitik, (b) grafiksel yöntemle bulunuz.

> **Çözüm (derste verildi, ekrandan, 02:55:00):** (a) $y(t) = t\,u(t) - (t-2)\,u(t-2) - (t-3)\,u(t-3) + (t-5)\,u(t-5)$.

> **Çözüm (derste verilmedi, b şıkkı):** Kısa olan $h$ ters çevrilip kaydırılır; $h(t-\tau)$, $[t-2, t]$ aralığında 1'dir. $t<0$: 0. $0 \le t \le 2$: örtüşme $[0,t]$, $y=t$. $2 \le t \le 3$: örtüşme $[t-2,t]$, $y=2$. $3 \le t \le 5$: örtüşme $[t-2,3]$, $y=5-t$. $t>5$: 0. Bu parçalı sonuç (a) şıkkıyla aynıdır (python ile doğrulandı).

### Soru 8: Hazırlık alıştırması (derste sözlü, 02:57:38)

Gelecek derse hazırlık olarak, girişlerden biri $e^{-3t}u(t)$ olan bir konvolüsyonun çözülmesi istendi; ters çevrilecek sinyal serbestçe seçilebilir. <!-- BELİRSİZ: alıştırmanın ikinci sinyali altyazıda ve karelerde okunamadı (02:57:38); çözüm bu yüzden yazılmadı. -->

## Dersin Toparlaması

Bu derste önce dersin müfredattaki yeri ve hedefi tartışıldı: sinyallerin ve sistemlerin temel özelliklerini, sinyallerin bilgisayarda nasıl saklandığını ve konvolüsyonu sağlam öğrenmek, DSP, görüntü işleme ve derin öğrenme gibi ileri konuların temelidir. Ardından geçen haftanın konuları örneklerle pekiştirildi: parçalı bir sinyal birim basamaklarla yazıldı, $y(t)=x(t)\cos\omega_0 t$ sisteminin beş özelliği tek tek test edildi ve doğrusallık testinin iki koşulu (toplamsallık ve homojenlik) $y=x\sin t$ ve $y=2x+4$ örnekleriyle uygulandı.

Dersin ikinci yarısında LTI sistemlere geçildi. Bir sinyalin kaydırılmış dürtülerin toplamı ya da integrali olarak yazılabileceği gösterildi, birim dürtü cevabı tanımlandı ve zamanla değişmeyen sistemde dürtü cevabının yalnız ötelendiği vurgulandı. Buradan konvolüsyon integrali elde edildi; özellikleri, grafiksel çözüm adımları, iki dikdörtgen örneği ve basamaklar cinsinden verilmiş iki dikdörtgenin analitik konvolüsyonu işlendi. Bir sonraki derste sürekli zamanda konvolüsyon örneklerine devam edilip ayrık zamanlı konvolüsyona (konvolüsyon toplamına) geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
