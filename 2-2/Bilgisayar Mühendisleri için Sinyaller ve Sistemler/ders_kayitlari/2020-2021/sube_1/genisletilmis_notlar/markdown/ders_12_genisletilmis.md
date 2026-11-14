# Ders 12 Genişletilmiş Notu: Dürtü Cevabı, Frekans Cevabı, Transfer Fonksiyonu ve Laplace Dönüşümüne Giriş: Yakınsama Bölgesi ve Temel Dönüşümler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Fourier Dönüşümü Konusunun Kısa Tekrarı
- 2. Üç Temel Kavram: Dürtü Cevabı, Frekans Cevabı, Transfer Fonksiyonu
- 3. Sistem Modelleme: Sera Örneği
- 4. Laplace Dönüşümüne Giriş
- 5. Laplace Dönüşümü Nerede Kullanılır?
- 6. Sönümleme Fikri ve $s = \sigma + j\omega$
- 7. İki Taraflı ve Tek Taraflı Laplace Dönüşümü, s-Düzlemi
- 8. Yakınsama Bölgesi ve $e^{-bt}u(t)$ Örneği
- 9. Laplace ile Fourier Arasındaki İlişki
- 10. Ters Laplace Dönüşümü
- 11. Temel Laplace Dönüşümleri
- 12. s-Düzleminde Öteleme
- 13. Temel Frekans Sorusu
- 14. Paydayı Tam Kareye Tamamlama
- 15. $t^n$ ile Çarpma Özelliği

## 1. Fourier Dönüşümü Konusunun Kısa Tekrarı

Hoca yeni konuya geçmeden önce, Fourier analizi slaytlarının üzerinden hızlıca geçip atlanan bir şey olup olmadığına baktı. Bu kısım, aynı günün öğleden önceki oturumunda konuşulanların hatırlatılmasıdır.

### 1.1 Sinüsün Frekans Spektrumu ve Negatif Genlik

Daha önce yapılan kare dalga ve sinüs örneklerinde, $a_k$ katsayılarına bakarak bir işaretin doğrudan sinüse karşılık geldiğini görebiliyorduk. Bunu Euler formülünden görürüz: $e^{j\omega} = \cos\omega + j\sin\omega$ olduğundan sinüs, biri artılı biri eksili iki üstelin farkı olarak yazılır:

$$\sin\omega = \frac{e^{j\omega} - e^{-j\omega}}{2j}$$

> **Ders sonrası not:** Altyazıda payda "eksi $2j$" diye geçiyor. Doğrusu $2j$'dir. Python ile sayısal olarak kontrol edildi: $2j$ ile yazılan ifade sinüsü verir, $-2j$ ile yazılan ise işareti ters çıkarır.

Böyle sinüzoidal bir işaretin frekans spektrumunda biri pozitif, biri negatif iki bileşen görülür. Şimdiye kadar spektrumu genelde pozitif genlikli görmüştük. Hoca burada genliğin negatif de olabileceğini hatırlattı. Önemli olan, incelediğimiz şeyin genliğin frekansa göre değişimi olduğunun farkında olmaktır.

### 1.2 Gibbs Olayı ve Bu Dersten Beklenenler

Fourier analizinde veya sentezinde bir süreksizlik noktasına ulaşınca Gibbs olayı (Gibbs phenomenon) denen şey ortaya çıkıyordu. Slaytta bununla ilgili bazı limitlerden bahsediliyordu. Hoca bunları önceden yapılan örneklere bağlayarak geçti.

> **Hocanın vurgusu:** Bu dersi bitiren biri Fourier analizi kapsamında şunları bilmelidir: Fourier serileri nerede yapılır? Fourier dönüşümü nerede ve hangi şartlarda yapılır? Birazdan göreceğimiz Laplace dönüşümü nerede yapılır?

### 1.3 Özellikler

Hoca kosinüs örneğinden sonra dönüşüm kurallarını sırayla hatırlattı.

**Zaman kayması (time delay).** İşaretin gecikmesi frekans düzlemine üstel bir çarpan olarak yansır:

$$x(t - t_0) \leftrightarrow e^{-j\omega t_0}\, X(\omega)$$

**Gösterim farkları.** Hoca, kaynaklarda terminolojik farklılıklar görülebileceğini söyledi. Örneğin normalde $X(\omega)$ yazarız, bazı yerlerde $X(j\omega)$ yazılır. Bu hiçbir şeyi değiştirmez: $j\omega$'ya göre değişim ile $\omega$'ya göre değişim aynı bilgiyi içerir.

**Frekans kayması.** Bu, zaman kaymasının tersidir. Frekansta bir kayma olursa, zamanda $e^{j\ldots}$'li bir çarpanla çarpılmış oluruz:

$$e^{j\omega_0 t}\, x(t) \leftrightarrow X(\omega - \omega_0)$$

**Ölçekleme.** Slayt bunun nereden geldiğini değişken dönüşümüyle ayrıntılı gösteriyordu. Anlatılan, daraltma ve genişletme (shrink, expand) meselesidir. İşareti zamanda daraltırsak spektrum genişler, işareti genişletirsek spektrum daralır.

**Türev.** Hoca bu özelliğin çok işe yaradığını söyledi. Türev, frekans düzleminde $j\omega$ ile çarpmaya karşılık gelir. Slaytta bunun kısa bir ispatı vardı. Karmaşık şekilli işaretlerin Fourier dönüşümünü almanın da kısa bir yoludur. Hoca, sabahki oturumda $\frac{1}{a + j\omega}$ ile yapılana benzer bir işlem olduğunu hatırlattı ve örneğini sonraki derslerde hazırlayacağını söyledi.

Bu özelliklerin (zaman kayması, frekans kayması, ölçekleme, türev) hepsi bir Gauss işareti üzerinde Python ile sayısal olarak kontrol edildi.

### 1.4 Filtreler, Konvolüsyon ve Modülasyon

İki işaretin konvolüsyonunu almak için frekans düzleminde çarpma yapıyorduk. İdeal alçak geçiren filtre (low-pass filter) de bu kuralın bir uygulamasıdır. Tersi de geçerlidir: İşaretlerin zamanda çarpılması, frekans düzleminde konvolüsyon anlamına gelir.

Hoca, daha önceki bir örnekte çarpanın $\cos(\omega_0 t)$ olduğunu hatırlattı. Bunun adı modülasyondur. Sesin her yere taşınamadığı, bu yüzden taşıyıcıyla çarpıldığı açıklamasını daha önce yapmıştı.

> **Ders sonrası not:** Hoca "$\cos(\omega_0 t)$ ile çarpma yapmak tek bir skaler sayıyla çarpma yapmak demektir" dedi. Bu doğru değildir. $\cos(\omega_0 t)$ zamanla değişen bir çarpandır, sabit bir ölçekleme katsayısı değildir. Sonucu da spektrumu kaydırmaktır: $x(t)\cos(\omega_0 t) \leftrightarrow \frac{1}{2}\left[X(\omega - \omega_0) + X(\omega + \omega_0)\right]$. Zamanda çarpmanın genel kuralı ise $x(t)\,p(t) \leftrightarrow \frac{1}{2\pi}\, X(\omega) * P(\omega)$ biçimindedir. İkisi de Gauss işaretleriyle Python'da sayısal olarak kontrol edildi.

## 2. Üç Temel Kavram: Dürtü Cevabı, Frekans Cevabı, Transfer Fonksiyonu

Hoca, "Sistem Modelleme ve Laplace Dönüşümü" konusuna geçerken şimdiye kadar önümüze gelen üç kavramı bir arada söylemek istedi.

### 2.1 Dürtü Cevabı

Birinci kavram dürtü cevabıdır (impulse response), Türkçede darbe cevabı da denir. Genellikle sürekli zamanda $h(t)$, ayrık zamanda $h[n]$ ile gösterilir.

Hoca tanımı öğrencilere sordu. Bir öğrencinin "tepki, reaksiyon" cevabına, cevap ile tepkinin zaten aynı şey olduğunu söyledi: "Cevap" Arapça kökenliyse "tepki" onun Türkçesi gibidir. Hocanın istediği sözlük anlamı değil, açıklamaydı: Neyin cevabı? Ne yapıyoruz da böyle bir cevap geliyor?

Açıklama şöyledir. Elimizde bir sistem var. Sistemin davranışını $y[n]$ veya $y(t)$ ile gösteriyoruz, yani $y = f(x)$ gibi, zamana göre değişen bir şey düşünebiliriz. Sistem gelen bir girişe (input) karşılık bir çıkış (output) verir: Bir sinyali alır, başka bir sinyale dönüştürür. Bu sistem kendi içinde bir kara kutudur. Ne yaptığını öğrenmek için girişe özel bir işaret veririz: birim dürtü (birim darbe).

Birim dürtü $\delta[n]$ yalnız $n = 0$ noktasında $1$'dir. Hoca, $k$'nın $-\infty$'dan $+\infty$'a değiştiği $\delta[n-k]$ dürtülerini, yani gecikmeli birim dürtüleri girişe verdiğimizi söyledi. Sistemin bunlara verdiği cevap, sistemin nasıl çalıştığını ortaya çıkarır: "Bana böyle bir şey geliyorsa demek ki bu sistem böyle çalışıyor."

Tek şart vardır: Sistem doğrusal ve zamanla değişmez (LTI) olmalıdır. Bu şartlar altında birim dürtüye karşılık gelen sonuç, sürekli zamanda $h(t)$, ayrık zamanda $h[n]$ olur.

Hoca bunu bir benzetmeyle anlattı: Birim dürtü, çarpmadaki birim (etkisiz) eleman gibidir. Bu "bir, bir, bir" diye giden, sonsuz tane $1$ demektir. Etkisiz elemanı kara kutuya uyguladığımızda elde edilen sonuç, o kara kutuyu deşifre etmek anlamına gelir.

> **Ders sonrası not:** Hocanın benzetmesini iki noktada netleştirmek gerekir. Birincisi, $\delta$ çarpmanın değil **konvolüsyonun** birim elemanıdır: $x * \delta = x$. "Sonsuz tane bir" görüntüsü frekans düzlemine aittir, çünkü $\delta(t)$'nin dönüşümü her frekansta $1$'dir. Çarpmadaki etkisiz eleman benzetmesi de orada, $Y(\omega) = 1 \cdot H(\omega)$ eşitliğinde geçerlidir. İkincisi, sistemi çözmek için sonsuz tane dürtü vermek gerekmez. LTI bir sistemde tek bir $\delta[n]$'in cevabı olan $h[n]$ yeterlidir. Gecikmeli dürtülerin cevabı zamanla değişmezlikten dolayı $h[n-k]$ olur, doğrusallık sayesinde de her giriş $x[n] = \sum_k x[k]\,\delta[n-k]$ olarak yazılıp çıkış bulunur. Küçük bir ayrık sistemle Python'da kontrol edildi.

**Soru:** Yani bir sistemi çözebilmek için dışarıdan bir dürtü veriyoruz, çıkan sonuca göre de sistemin nasıl davrandığını ölçüyoruz, değil mi? **Cevap:** Aynen öyle. Ama bu yalnız sistem doğrusal ve zamanla değişmez olduğunda geçerlidir.

$h(t)$'yi bulduktan sonra sistemin nasıl davrandığını biliriz. Ama $h(t)$ için "$y(t)$ bölü $x(t)$" diyemeyiz.

### 2.2 Frekans Cevabı

$h(t)$'nin Fourier düzlemindeki karşılığına frekans cevabı (frequency response) denir. Çıkışın Fourier dönüşümünün, girişin Fourier dönüşümüne oranıdır:

$$H(\omega) = \frac{Y(\omega)}{X(\omega)}$$

$H(j\omega)$ da yazılabilir. Ayrık zamanda ise büyük omega ile $H(\Omega)$ yazılır.

Neden bu oranı frekans düzleminde alıyoruz da zaman düzleminde almıyoruz? Hocaya göre zaman düzleminde bölme yapmak bir anlam ifade etmez. Frekans düzleminde ise $Y$'nin $X$'e oranı, sistemin bir girişe karşılık çıkışta ne vereceğini söyler.

> **Ek bilgi (derste anlatılmadı):** Bunun sebebi, zaman düzlemindeki giriş-çıkış ilişkisinin çarpma değil konvolüsyon olmasıdır: $y(t) = x(t) * h(t)$. Bu yüzden $y(t)/x(t)$ oranı $h(t)$'yi vermez. Dönüşüm alınınca konvolüsyon çarpmaya dönüşür, $Y(\omega) = X(\omega)H(\omega)$ olur ve bölme anlamlı hale gelir.

### 2.3 "Transfer" Ne Demek: Maksimum Güç Transferi

Hoca, üçüncü kavrama geçmeden önce "transfer" sözünün nereden geldiğini açıklamak için devre teorisinden bir soru sordu: Bir elektrik devresinden alınabilecek maksimum güç ne kadardır? Bir öğrenci maksimum güç transferi teoremini (maximum power transfer theorem) hatırlattı. Yük direnci, kaynağın Thevenin eşdeğer direncine eşitken verim yüzde ellidir.

Devreyi şöyle düşünelim: Bir güç kaynağı ve onun Thevenin eşdeğerine karşılık gelen bir iç direnç var. Bu devreye bir eleman (bir modül) bağlıyoruz ve bu elemandan güç alıyoruz. Üreticinin iç direncine eşit bir yük bağlanırsa elemandan alınan güç en büyük olur. Hoca bunu "transfer denen şey, verdiğiniz girişin çıkıştaki yansımasıdır" diye yorumladı: 100 W verirseniz en fazla 50 W alırsınız.

Niye eşitlik gerekiyor? Hocanın sayısal örneği şöyleydi (hesabı derste tamamlanmadı, güç değerleri ara adım olarak eklendi):

- **Verilen:** Kaynak gerilimi $V = 10$ V, iç direnç $R_{in} = 5\ \Omega$.
- **Yük $5\ \Omega$:** Dirençler seri olduğundan $I = \frac{10}{5 + 5} = 1$ A. Yükteki güç $P = I^2 R = 1^2 \cdot 5 = 5$ W (ara adım eklendi).
- **Yük $5{,}1\ \Omega$:** $I = \frac{10}{10{,}1} \approx 0{,}990$ A, $P \approx 4{,}9995$ W (ara adım eklendi).
- **Yük $7\ \Omega$:** $I = \frac{10}{12} \approx 0{,}833$ A, $P \approx 4{,}861$ W (ara adım eklendi).

$P = I^2 R$ olduğu için direnci artırınca gücün artmasını bekleriz. Ama direnç arttıkça akım düşer. Hoca bunu ekonomi modellerine benzetti: İkisi arasında bir ödünleşme (trade-off) vardır ve en iyi nokta, yük direncinin iç dirence eşit olduğu yerdir. Bunun türevle yapılan bir ispatı vardır, ama hoca bu dersin konusu olmadığı için girmedi.

Python ile yük direnci taranarak en büyük gücün $R = 5\ \Omega$ civarında $5$ W olduğu sayısal olarak bulundu.

> **Ders sonrası not:** Hoca "maksimum olabilecek verim yüzde elli" dedi. Doğrusu, **maksimum güç aktarılan anda** verim yüzde ellidir. Verimin üst sınırı yüzde elli değildir. Yukarıdaki örnekte $5\ \Omega$ yükte kaynaktan çekilen güç $10$ W, yükteki güç $5$ W olduğundan verim $\%50$'dir. $7\ \Omega$ yükte ise verim $7/12 \approx \%58{,}3$'e çıkar ama yükteki güç $4{,}861$ W'a düşer. Yük direnci büyüdükçe verim $\%100$'e yaklaşır, aktarılan güç ise azalır. Yani "maksimum güç" ile "maksimum verim" farklı şeylerdir.

Hocanın buradan çıkardığı sonuç şudur: Güç transferinde çıkışta elde edilen gücü girişte verilen güce oranlayıp bir yüzde buluyorsunuz.

### 2.4 Transfer Fonksiyonu

Transfer fonksiyonunda (transfer function) da aynı şeyi yaparız: Çıkış bilgisini girişteki bilgiye oranlarız. Laplace düzleminde bu şöyle yazılır:

$$H(s) = \frac{Y(s)}{X(s)}$$

Sürekli zamanda $s$ ile yazılan bu kavramın, ayrık zamanda z-dönüşümündeki bir karşılığı da vardır.

Bu üç kavram çok işimize yarayacaktır. Bir sistemi modelledikten sonra, kara kutudaki soru işaretinin yerine bir şey koymalıyız. Gerektiğinde bu $H(s)$, gerektiğinde $H(\omega)$, gerektiğinde $h(t)$ veya $h[n]$ olur. Bundan sonra sisteme istediğimiz $x(t)$ veya $x[n]$ girişini verip karşılığındaki $y(t)$ veya $y[n]$ çıkışlarını bulabiliriz. Hocaya göre bilgisayar kullanmaktaki asıl amaç da budur: geleceğe yönelik tahmin yapmak.

## 3. Sistem Modelleme: Sera Örneği

Hoca, elinde olduğunu sandığı bir sistem modeli örneğini gösteremedi, ama anlatarak geçti. Örnek, bölümdeki çok disiplinli tasarım projesi dersinde ortaya atılan bir problemdir: bir seranın sıcaklığının kontrolü.

<!-- BELİRSİZ: Dersin adı altyazıda bozuk geçiyor ("Ç, D, T, F çok çinli bir tasarım", "Çoktis'in tasarım projesi"). "Çok disiplinli tasarım projesi" diye okundu. -->

Seranın sıcaklığını kontrol etmek için değişkenler belirlenir: zaman, basınç, ortamın büyüklüğü (hacmi) ve bazı dış etkenler. Bunlardan bir denklem ortaya atılır, test edilir ve doğruluğu kanıtlanmaya çalışılır. Bu denklem $y(t)$'nin ifadesidir. İçinde $x(t)$ ve belki $z(t)$ gibi başka girişler de bulunur: Biri sıcaklık, biri basınç, biri başka bir şey olabilir. Giriş ile çıkış arasındaki bağlantılardan sistemin transfer fonksiyonu, yani modeli, tasarlanır.

Hoca burada iki rolü ayırdı:

- **Kontrol mühendisi:** Bu model tasarlama işi, kontrol mühendisinin en önemli işlerinden biridir. Sinyaller ve sistemler konularını çok iyi kullanması gerekir.
- **Bilgisayar mühendisi:** Tasarlanmış model üzerinde analiz yapar. Model kararlı çalışıyor mu, yani sınırlı giriş-sınırlı çıkış (bounded input, bounded output, BIBO) sağlanıyor mu? Modelin aksak noktaları neler? Yapay zekâ ile kontrol edilebilir mi?

Örneğin ortam sıcaklığını aç-kapa kontrolü çok iyi denetlemez. Onun yerine yapay zekâ içeren daha uyarlanabilir (adaptive) bir kontrolör yapmak maliyetleri iyileştirir, ürün kalitesini artırır.

Bu girişten sonra hoca, sürekli zamanda transfer fonksiyonu konusuna yoğunlaşacağımızı ve kullanacağımız aracın Laplace dönüşümü olduğunu söyledi.

## 4. Laplace Dönüşümüne Giriş

### 4.1 İntegral Dönüşüm

Laplace dönüşümü (Laplace transform), Fourier dönüşümü gibi bir integral dönüşümdür (integral transform). Hoca bunun ne olduğunu hatırlattı. Elimizde herhangi bir fonksiyon var. Bunu, "ana fonksiyon" da denen, iki değişkenli bir çekirdek (kernel) fonksiyonla çarpıp belli bir $[a, b]$ aralığında integralini alıyoruz. $a$ ve $b$ sonsuz da olabilir:

$$X(\alpha) = \int_a^b x(t)\, K(\alpha, t)\, dt$$

<!-- BELİRSİZ: Hoca çekirdeğe sözlü olarak "kappa" diyor. Yazdığı semboller ve $\alpha$ değişkeninin adı altyazıdan okunamıyor; gösterim kısa notla uyumlu tutuldu. -->

İntegral, çekirdeğin değişkenlerinden yalnız birine göre alınır. Sonuçta çekirdekteki diğer değişkenin düzlemine (domain) geçilmiş olur.

Fourier dönüşümünü buna örnek verdi: $\int x(t)\, e^{-j\omega t}\, dt$ ifadesinde $-j$ sabit bir sayıdır, $\omega$ ve $t$ ise değişkendir. $t$'ye göre integral aldığımız için sonuç, $a$ ve $b$ ne olursa olsun, içinde $\omega$ bulunan ama hiçbir şekilde $t$ bulunmayan bir şey olmak zorundadır. Laplace dönüşümü de bunun gibidir ve $\mathcal{L}$ operatörü ile gösterilir.

### 4.2 Neden İhtiyaç Duyuldu?

Fourier dönüşümünü tekrar yazalım:

$$X(\omega) = \int_{-\infty}^{\infty} x(t)\, e^{-j\omega t}\, dt$$

Bu integrali aldığımızda bazı durumlarda $X(\omega)$ sonsuza gidebiliyor. Bunun örneğini önceki derslerde yapmıştık. İntegralin sonucu $+\infty$'a da $-\infty$'a da gitmemelidir. Bu şart sağlanmıyorsa Fourier dönüşümü yapılamaz. Bu sebeple, Fourier dönüşümünün daha genel hali olan Laplace dönüşümüyle, hemen hemen her fonksiyonun belli şartlar altında integrali alınıp analizi yapılır.

### 4.3 Tanım ve $s$ Değişkeni

Laplace dönüşümü şöyle tanımlanır:

$$X(s) = \int_{-\infty}^{\infty} x(t)\, e^{-st}\, dt$$

Çekirdek bu kez $s$ ve $t$'ye bağlıdır, $t$'ye göre integral alıyoruz, dolayısıyla sonuç $s$'e bağlıdır. Fourier'deki $j\omega$'nın yerine $s$ gelmiştir. Başka bir değişiklik yoktur. Hoca bunu Euler açılımıyla gösterdi: $s$ yerine $j\omega$ yazarsak $e^{-j\omega t} = \cos(\omega t) - j\sin(\omega t)$ olur ve Fourier dönüşümünün aynısı ortaya çıkar.

<!-- BELİRSİZ: Altyazıda bu açılım bozuk geçiyor ("cos, s, eksi, j, sin"). Tahtada yazılan adımlar okunamıyor; yukarıda yalnız varılan sonuç aktarıldı. -->

Tek fark şudur: $s$ yalnız $j\omega$'dan oluşmaz. Daha genel olarak

$$s = \sigma + j\omega$$

şeklindedir. $\sigma$ reel kısım, $\omega$ sanal kısımla ilgilidir. Doğrudan $j\omega$ yazmak Fourier dönüşümüdür, $\sigma + j\omega$ yazmak Laplace dönüşümüdür. Bazı şartlarda ikisi birbirine eşittir.

### 4.4 Yakınsama Şartına İlk Bakış

$s$ yerine $\sigma + j\omega$ koyarsak integral şu olur:

$$X(s) = \int_{-\infty}^{\infty} x(t)\, e^{-(\sigma + j\omega)t}\, dt$$

Bu integrali aldığımızda sınırları, yani $t$ yerine $\pm\infty$ değerlerini yazacağız. Üstün içindeki parantezin bizi ıraksamaya götürmemesi gerekir. Hiçbir şekilde $e^{+\infty}$ gibi bir sonuca ulaşmamalıyız. Hocanın hatırlattığı iki temel değer şunlardır:

- $e^{-\infty} = \frac{1}{e^{\infty}} = \frac{1}{\infty} = 0$
- $e^{0} = 1$

Yani bir şekilde $e^{-\infty}$'a gelmemizi sağlayan şartları inceleyeceğiz. Bu şartlar, sistemin kararlılığıyla ve kutup ve sıfır noktalarıyla ilgilidir.

Hoca, bunun normalde matematikçilerin kullandığı bir yöntem olduğunu, bizim sinyallerimizin içinde ise bir yerlerde $u(t)$, $u(-t)$ veya $\delta(t)$ bulunacağını söyledi. Bunlar sinyalin sınırlarını $-\infty$'dan $0$'a veya $0$'dan $+\infty$'a taşır.

Sağ ve sol taraf ayrımı da buradan çıkar. $t$ yerine $+\infty$ yazdığımız durum sağ taraflı bir integraldir, sıfırın sağındaki değerleri kullanır. Parantezin içi bir şekilde negatif olursa, dışarıdaki eksiyle birlikte üst pozitif olur. O zaman $t$'nin $-\infty$'a gittiği durumlarda yakınsama vardır, $+\infty$'a gittiği durumlarda yoktur. Hoca bu yorumları yapabilmemiz gerektiğini söyledi.

### 4.5 Yakınsama Bölgesi Kavramı

$\sigma$ değerine göre işaretin belli bir aralıkta yakınsadığını söyleyen kavram yakınsama bölgesidir (Region of Convergence, ROC). İşaret bu bölge içinde yakınsar. Bölgenin dışıyla ilgilenmeyiz, orada ıraksıyor deriz.

> **Ders sonrası not:** Hoca bu bölgeyi anlatırken "işaretin kararlı olduğu aralık" ifadesini de kullandı. ROC doğrudan yakınsama ile ilgilidir, $\sigma$'nın kendisi sistemin kararlılığını belirtmez. İki kavram arasındaki bağ şudur: Dürtü cevabı $h(t)$ olan LTI bir sistem, ancak $H(s)$'nin ROC'u $j\omega$ eksenini içeriyorsa BIBO kararlıdır.

Özetle $\sigma = 0$ iken Laplace dönüşümü Fourier dönüşümüne eşittir, $\sigma \neq 0$ iken Laplace dönüşümünü görürüz. $\sigma$'nın bulunduğu yere göre ROC'u tayin ederiz. Bu tayin sonucunda integralin sınırlarını yerine yazarken sonsuzdan farklı değerler elde ederiz.

> **Hocanın vurgusu:** "Bunlar çok önemli." İşin özeti, üstteki ifadede $t$ yerine sınırlar yazıldığında $e^{-\infty}$ veya $e^{0}$ görmemiz, sonsuza gitmememizdir.

### 4.6 Sürekli ve Ayrık Zamanda Araçlar

Sürekli zamanlı (continuous time) sistemleri ifade ederken diferansiyel denklemleri, yani türev ve integrali kullandık. Ayrık zamanda ise fark denklemleri (difference equations) kullanılır. Hoca türevin fark demek olduğunu, sabahki oturumda da $y'$ için $y[n] - y[n-1]$ yazdıklarını hatırlattı. İntegralin yerini de ayrık zamanda toplam (summation) alır.

Hoca "türev" sözcüğü için bir de şaka yaptı: Ayran neyin türevidir? Yoğurdun. Yoğurtla suyu toplarsanız yeni bir ürün olan ayranı elde edersiniz, suyu çıkarırsanız orijinaline dönersiniz.

> **Ders sonrası not:** Ayran benzetmesi "türev" sözcüğünün günlük anlamıyla yapılmış bir sözcük oyunudur. Matematiksel türev ile bir ilgisi yoktur.

Şimdiye kadar gördüklerimiz işaretin türüne göre şöyle ayrılıyordu:

| | Fourier serisi ve dönüşümü | Genelleştirilmiş hali |
|---|---|---|
| Sürekli zaman | Sürekli zamanlı Fourier serisi, CTFT | Laplace dönüşümü (integral) |
| Ayrık zaman | Ayrık zamanlı Fourier serisi, DTFT | z-dönüşümü (toplam) |

Bunların örnekleme (sampling) ile ilişkisini de daha önce konuşmuştuk. Frekans cevabına bakarken de CTFT ile sürekli zamanda, DTFT ile ayrık zamanda dürtü cevabını inceledik. Laplace dönüşümü CTFT'nin, z-dönüşümü de ayrık zamanda aynı işi görecek şekilde DTFT'nin daha gelişmiş halidir.

## 5. Laplace Dönüşümü Nerede Kullanılır?

Hoca, Laplace dönüşümünün sinyal ve özellikle sistemlerin analizinde ve tasarımında çok kullanıldığını, en çok da kontrol ve otomasyoncuların kullandığını söyledi.

### 5.1 Fourier Yaklaşımının Üç Koşulu

Slaytta üç koşul sıralanıyordu:

- Sistem sıfır durumlu (zero state) olmalıdır.
- Dürtü cevabı mutlak integrallenebilir (absolutely integrable) olmalıdır: integral sonsuzdan küçüktür.
- Giriş sınırlı (bounded) olmalıdır. Sınırlı giriş-sınırlı çıkış (BIBO) konusu burada karşımıza gelir.

<!-- BELİRSİZ: Hoca bu koşulları sayarken yalnız "bu ne zaman kullanılır" diyor. Hemen ardından "frekans cevabının elde edilemediği durumlar" ve "bu üç koşulun sağlanmadığı durumlar" dediği için koşullar frekans cevabı yaklaşımının koşulları olarak yazıldı. Slayt görülemedi. -->

Sinyal işlemede ve sinyal sistemlerde genellikle integrallenebilir işaretlerle karşılaşırız. Frekans cevabı da filtrelerde ve sistem analizinde çok işe yarar, diferansiyel denklemleri kolayca çözdürür. Ama bu koşulları sağlamayan sinyaller ve durumlar da vardır. Frekans cevabının elde edilemediği durumlarda sistemin modelini Laplace dönüşümüyle elde ederiz. Laplace dönüşümü, CTFT'nin genelleştirilmiş hali olarak bu üç koşulun sağlanmadığı durumların da üstesinden gelir. Hoca bunun sebebini $j\omega$ yerine $\sigma + j\omega$ koyarak "orijinali biraz bozmamız" diye özetledi.

### 5.2 İki Analiz Yöntemi

Laplace dönüşümünün mümkün kıldığı iki analiz vardır:

- **Sıfır durum (zero state) analizi:** Transfer fonksiyonu ile yapılır. $x(t)$, $h(t)$ gibi sinyaller mutlak integrallenebilir olsun ya da olmasın kullanılır. Fourier dönüşümüyle hemen hemen benzer özelliklere sahiptir.
- **Diferansiyel denklem çözümü:** Sabahki oturumda bir işaretin türevini almanın $j\omega$ çarpanı, ikinci türevin $(j\omega)^2$ çarpanı getirdiğini konuşmuştuk. Burada ek olarak sıfır durumun dışındakiler, yani sistemin başlangıçtaki durumunun sıfırdan farklı olduğu başlangıç değer problemleri ele alınır.

Hocanın başlangıç koşulu örneği cep telefonudur. Telefonu ilk aldığınızda içinde şarj yoksa başlangıç koşulunu sıfır kabul edebilirsiniz. Ama bir sistemi kapatıp açtıysanız içinde önceden kalan veri vardır. O veriyi göz ardı etmemek için başlangıç koşullu çözümden faydalanırız.

## 6. Sönümleme Fikri ve $s = \sigma + j\omega$

### 6.1 "Mitigate" Ne Demek?

Slaytta CTFT'nin bazı durumlarda yakınsamadığı ve Laplace dönüşümünün bu sorunu "mitigate" ettiği yazıyordu. Hoca kelimenin anlamını sordu.

**Soru:** "Mitigate" ne demek? **Cevap:** Bir öğrenci "hafifletmek" dedi. Hoca bunu yatıştırmak, hafifletmek, azaltmak diye genişletti. Burada kastedilen, sönümleme hareketi yaparak Fourier dönüşümünün sonsuza gitme, yani yakınsamama durumunu azaltmak ve dönüşümü mümkün hale getirmektir.

Fourier dönüşümünde zaman düzleminden frekans düzlemine geçerek frekans analizi yapıyorduk ve $j\omega$ operatörünü kullanıyorduk. Şimdi onun yerine reel ve sanal kısmı olan $s = \sigma + j\omega$'yı kullanıyoruz. Yani sanal ifadeye bir reel parça eklenmiştir. Bu, matematikçilerin, Laplace'ın önerdiği bir şeydir. Hoca integral dönüşümler üzerine çalışmaların devam ettiğini söyleyip Hartley dönüşümünü örnek verdi.

> **Ders sonrası not:** Hoca Hartley dönüşümünü Laplace dönüşümündeki bir problemi ortadan kaldırmaya yönelik bir çalışma olarak andı. Hartley dönüşümü, tanımı gereği çekirdeği $\cos(\omega t) + \sin(\omega t)$ olan reel değerli bir dönüşümdür ve Fourier dönüşümüyle ilişkilidir: Değeri, Fourier dönüşümünün reel kısmı eksi sanal kısmına eşittir (Python ile kontrol edildi). Laplace dönüşümüyle kurulan bağ altyazıdan doğrulanamadı, büyük olasılıkla Fourier dönüşümü kastedilmiştir.

### 6.2 Sönümlendirici Çarpan

Üstlü sayıların özelliğinden üsteli ayırırsak integral şuna dönüşür:

$$X(s) = \int_{-\infty}^{\infty} \left[x(t)\, e^{-\sigma t}\right] e^{-j\omega t}\, dt$$

$e^{-\sigma t}$ çarpanını yok sayarsak geriye olduğu gibi Fourier dönüşümü kalır. Peki bu çarpan ne yapıyor?

Hoca, daha önce de görülen $\sin(5t)\, e^{-6t}$ işaretini örnek verdi. Sistemi $t = 0$ anında çalıştırdığımızı düşünelim. $e^{0} = 1$, $\sin 0 = 0$ olduğu için işaret sıfırdan başlar. $t$ arttıkça sinüs yükselir, ama üstel çarpan tabiri caizse bu artışın "kafasına vurur". Sinüs önce bir miktar artar, sonraki salınımda daha az artar ve böylece sönümlenerek sıfıra gider.

İşaretimiz de $e^{-\sigma t}$ sayesinde sönümlenebilir hale gelir. Hocaya göre sönümlenebilen bir şey, integrali sonsuza gitmeyen, yani yakınsayan bir şeydir.

> **Ders sonrası not:** Bir işaretin sıfıra gitmesi tek başına integralinin yakınsamasına yetmez, yeterince hızlı sönümlenmesi gerekir. Üstel sönümleme bu hızı sağlar. Bu örnekteki $\sin(5t)\,e^{-6t}$ işaretinin dönüşümü $\frac{5}{(s+6)^2 + 25}$ çıkar. Bu sonuç Python'da sayısal integralle kontrol edildi.

Laplace dönüşümünde $s$ kompleks bir değişkendir ve reel ile sanal iki bileşeni vardır. Fourier'deki $j\omega$ da kompleks bir değişkendir, ama yalnız sanal kısmı vardır.

> **Hocanın vurgusu:** "CTFT'de $j\omega$ yerine $s$ yazılır" ifadesi buradan gelir. Ama birçok kaynak doğrudan $s = j\omega$ der. Bu her zaman geçerli değildir. $s = \sigma + j\omega$'dır. Laplace dönüşümünü Fourier dönüşümünden türetebiliriz, ama $s$'in ne olduğunu unutmamalıyız.

## 7. İki Taraflı ve Tek Taraflı Laplace Dönüşümü, s-Düzlemi

Aradan dönünce hoca, Laplace dönüşümü için her şeyin hemen hemen aynı olduğunu, sadece değişkende ufak bir fark bulunduğunu söyledi. İntegrali almak hatta daha kolaydır, çünkü $e^{-st}$ basit bir fonksiyondur. Sabahki oturumda gördüğümüz $\frac{1}{1 + j\omega}$ gibi ifadelerin yerine daha az değişken karmaşıklığı olan $\frac{1}{s-1}$ gibi sonuçlar göreceğiz.

### 7.1 İki Taraflı ve Tek Taraflı

Laplace dönüşümü tanımı ve yapılacak işlemler gereği ikiye ayrılır:

- **İki taraflı (bilateral):** İşaret $-\infty$'dan $+\infty$'a bütün durumlar için alınır ve $s = \sigma + j\omega$ yerine yazıldığında integral alınabilir, yani ıraksamaz, yakınsar.

$$X(s) = \int_{-\infty}^{\infty} x(t)\, e^{-st}\, dt$$

- **Tek taraflı (unilateral):** İntegral $0$'dan $\infty$'a veya $-\infty$'dan $0$'a alınır. $0$'dan $\infty$'a alınırsa genellikle sağ taraflı, tersi olursa sol taraflı denir.

$$X(s) = \int_{0}^{\infty} x(t)\, e^{-st}\, dt$$

Hoca, slaytta tek taraflı dönüşümün $t < 0$ için $x(t) \neq 0$ olsa bile bu şekilde tanımlandığının yazıldığını söyledi. Tek taraflı dönüşümü, tüm eksen üzerinde integrali yakınsatan bir $\sigma$ bulunamadığı durumlarla ilişkilendirdi: $-\infty$'dan $+\infty$'a giderken bir yerde $\sigma$ değeriyle uyuşmazlık çıkar ve integral şartları sağlanmaz.

### 7.2 s-Düzlemi

$X(s)$, $s$'e bağlı kompleks bir fonksiyondur. $s$ kompleks değişkeninin iki parçası vardır. Bunu s-düzlemi (s-plane) denen iki boyutlu bir düzleme çizeriz. z-dönüşümünde de aynı şekilde z-düzlemini göreceğiz.

- **Yatay eksen:** $\sigma$, yani reel kısım.
- **Dikey eksen:** $j\omega$, yani sanal kısım. Hoca bunu karmaşık sayılardaki $a + bi$ gösterimine benzetti.

Bu düzlem üzerinde özellikle sistemlerin kararlılık analizini yapacağız. Hoca ileride daha çok sol yarı düzlem (left-half plane) denen, $\mathrm{Re}(s) < 0$ olan bölge üzerinden analiz yapılacağını söyledi. Ayrıntılar konular işlendikçe gelecektir. Şu an önemli olan, yatay eksenin reel, dikey eksenin sanal eksen olduğunu görmektir.

### 7.3 Yakınsama Bölgesinin Tanımı

Yakınsama bölgesi aslında bir kümedir: Laplace integralinin yakınsadığı bütün $s$ değerlerinin kümesi. Bölgenin dışına çıkınca integral yakınsamaz. Her sinyalin kendine ait bir ROC'u vardır. Yani bir $f(t)$ sinyali verildiğinde, onun bir dönüşümü bir de ROC'u bulunur.

> **Hocanın vurgusu:** Laplace tabloları, Fourier tablolarından farklı olarak iki bilgi içerir: hem dönüşümü hem de hangi şartlar altında dönüştüğünü. Çünkü ters dönüşümü, dönüşümün hangi şartlarda yapıldığına göre yapmamız gerekir. Örneğin "$\sigma > 5$ şartında bu sinyal bu dönüşümü verir" deriz.

## 8. Yakınsama Bölgesi ve $e^{-bt}u(t)$ Örneği

Hoca Laplace dönüşümünü adım adım $x(t) = e^{-bt}u(t)$ işareti üzerinde gösterdi. Burada $b$ reel bir sayıdır.

### 8.1 Önce Fourier Dönüşümüne Bakalım

$u(t)$ yüzünden integral $0$'dan $\infty$'a gider:

$$X(\omega) = \int_0^\infty e^{-bt}\, e^{-j\omega t}\, dt = \int_0^\infty e^{-t(b + j\omega)}\, dt$$

$\omega$ frekanstır, onda bir problem yoktur. Ama $b$'nin pozitif olması gerekir ki dışarıdaki eksiyle çarpınca üs negatif kalsın ve $t = \infty$ yazdığımızda $e^{-\infty}$ bulalım. $b$ negatif olursa üs $+bt$ gibi pozitif olur, $t = \infty$ yazınca sonsuza gider. Bu yüzden Fourier dönüşümünde $b > 0$ şartını koyuyorduk.

### 8.2 Laplace Dönüşümü

Laplace dönüşümünde de hemen hemen aynı şey vardır. Tanımda integral $-\infty$'dan $+\infty$'a yazılır, ama $u(t)$ doğası gereği bizi sınırlar, integral $0$'dan başlar:

$$X(s) = \int_0^\infty e^{-bt}\, e^{-st}\, dt = \int_0^\infty e^{-(s+b)t}\, dt$$

İntegral alınır ve baştaki eksi dışarı atılır:

$$X(s) = \left. \frac{e^{-(s+b)t}}{-(s+b)} \right|_0^\infty = \frac{-1}{s+b}\left[\lim_{t\to\infty} e^{-(s+b)t} - 1\right]$$

Şimdi hoca sordu: İntegralin alınabilir olması için $s + b$ pozitif mi olmalı, negatif mi? Öğrencilerin cevabı "pozitif" oldu. Pozitif olsun ki önündeki eksi üssü negatif yapsın ve $t \to \infty$ için $e^{-\infty} = 0$ bulalım. Tersi olursa $e^{+\infty}$ çıkar ve sonsuza gider.

Burada $s$ kompleks olduğundan bakılacak şey reel kısımdır. $s = \sigma + j\omega$ yazınca

$$s + b = (\sigma + b) + j\omega$$

olur. $j\omega$ kısmı bizim için önemli değildir, reel sayıları kendi içinde toplarız. Sıfırla karşılaştırılan $\sigma + b$'dir. İki durum vardır:

- **$\sigma + b > 0$, yani $\sigma > -b$:** Parantezin içi pozitif, üs tamamen negatif olur. Limit $0$'a gider ve integral alınabilir.
- **$\sigma + b < 0$, yani $\sigma < -b$:** Parantezin içi negatif, dışarıdaki eksiyle üs pozitif olur. İntegral sonsuza gider, ıraksar. Bu durumda herhangi bir $X(s)$ dönüşümü bulamayız.

> **Ek bilgi (derste anlatılmadı):** $j\omega$ kısmının yakınsamayı etkilememesinin sebebi $\lvert e^{-j\omega t}\rvert = 1$ olmasıdır. Yani $\lvert e^{-(s+b)t}\rvert = e^{-(\sigma+b)t}$ olur ve limitin davranışını yalnız $\sigma + b$'nin işareti belirler. Sanal kısım yalnız salınım katar. $\sigma + b = 0$ sınırında ise genlik $1$ kalır, limit var olmaz, bu yüzden sınır ROC'a dahil edilmez.

> **Ders sonrası not:** Hoca bu aşamada bir yerde "$\sigma$'nın $-b$'den küçük olduğunu gösteren bir şey olacak tablomuzda" dedi. Doğrusu $\sigma > -b$'dir. Hoca hemen ardından doğru şartı kullandı. Altyazıda geçen "$s + b + \sigma\omega$" yazımı da $(\sigma + b) + j\omega$ olmalıdır.

Sonuç olarak yalnız $\sigma > -b$ iken limit sıfır olur, integral $\frac{-1}{s+b}\,[0 - 1]$ biçimine gelir ve

$$\boxed{e^{-bt}u(t) \leftrightarrow \frac{1}{s+b}, \qquad \mathrm{Re}(s) = \sigma > -b}$$

bulunur. $\mathrm{Re}(s)$ ile $\sigma$ ikisi de aynı anlama gelir. Sonuç Python ile sayısal integralle kontrol edildi: ROC içinde integral $\frac{1}{s+b}$'ye eşit çıkar, ROC dışında üst sınır büyüdükçe integral hızla büyür.

Hoca, sonuca varırken asıl dikkat edilecek yerin $t = 0$ değil $t = \infty$ yazılan adım olduğunu söyledi. Körü körüne sonsuz yazıp "$e^{-\infty}$ gelir" diyemeyiz. Biraz daha dikkatli olmak için limit kullanırız. Limit yakınsamıyorsa orada integral alınamaz. Bu limit incelemesi, dönüşümden sonra ROC'u tayin ederken kullanacağımız özelliktir.

Fourier dönüşümünde yalnız sonucu görüyorsak, Laplace dönüşümünde hem sonucu hem de şartı görmemiz gerekir ki sağlıklı bir geri dönüşüm yapabilelim.

> **Hocanın vurgusu:** Çoğu kitapta "$e^{3t}$'nin dönüşümü $\frac{1}{s-3}$'tür" denir geçilir. Bunu sadece söylemek yanlıştır, yanına virgül koyup hangi şartta olduğunu yazmak gerekir.

> **Hocanın vurgusu:** Detaylar önemlidir. Laplace dönüşümünde integralin sınırları yerine yazılıp sonuç elde edilir. Örneğin $u(t)$ yerine $u(-t)$ verilseydi integralin sınırları değişirdi ve farklı düşünmemiz gerekirdi. Bu göz ardı edilirse sonuç yanlış çıkar. O zaman ters Laplace dönüşümünden elde edilecek $y(t)$ da yanlış çıkar.

> **Ek bilgi (derste anlatılmadı):** ROC'un neden bu kadar gerekli olduğunu şu çift gösterir. $e^{-bt}u(t)$ ve $-e^{-bt}u(-t)$ işaretlerinin ikisinin de dönüşüm ifadesi $\frac{1}{s+b}$'dir. Birincisinde ROC $\sigma > -b$, ikincisinde $\sigma < -b$'dir. Yani aynı cebirsel ifade, ROC'a göre iki ayrı işarete döner. Python ile sayısal olarak kontrol edildi.

### 8.3 Laplace Dönüşümünün Kullanım Akışı

Hoca, bu dönüşümle ne yapacağımızı kısaca şöyle özetledi:

- **Zaman düzlemindeki problem:** Bir sistemin diferansiyel denklemini çözmek veya kararlılığı hakkında bilgi edinmek gibi. Burada birçok şey zordur, en basitinden konvolüsyon zordur.
- **Laplace dönüşümü ile s-düzlemine geçiş:** Dönüşüm yapıldığını göstermek için küçük harften büyük harfe geçilir: $y(t) \to Y(s)$.
- **s-düzleminde cebirsel işlemler:** Temelde dört işlem, yani toplama, çıkarma, çarpma ve bölme.
- **Ters Laplace dönüşümü ile zaman düzlemine dönüş:** Bu adımda ROC mutlaka dikkate alınır. Sonuç, üzerinde işlem yapılmış yeni bir zaman düzlemi verisidir.

### 8.4 $b$'nin İşaretine Göre ROC

$\sigma > -b$ şartı, s-düzleminde $\sigma = -b$ doğrusunun sağında kalan bölgedir. Hoca iki durumu çizdi.

**$b > 0$ durumu.** $-b$ negatif bir noktadır. ROC bu noktadan başlayıp daha büyük değerlere uzanır, dolayısıyla $j\omega$ eksenini içerir. $e^{-bt}u(t)$'nin grafiği sönümlenen bir üsteldir. Bu durumda Laplace dönüşümü Fourier dönüşümüne eşittir.

**$b < 0$ durumu.** İşaret artan bir üsteldir. $-b$ doğası gereği pozitiftir, ROC sağ yarı düzlemde pozitif bir noktadan başlar ve $j\omega$ eksenini içermez. Bu durumda işi Fourier dönüşümüyle yapmak mümkün değildir, ama Laplace dönüşümüyle mümkündür.

<!-- BELİRSİZ: İki ROC çizimi slaytta ve tahtada; altyazıda yalnız sözlü olarak anlatılıyor. -->

**Soru:** $b = 0$ durumu neden dahil edilmiyor? **Cevap:** Hoca $b = 0$ iken $e^{0} = 1$ olduğunu söyledi ve bu notasyonda sıfırın dahil olmadığını belirtti. Genel form bize $e^{3t}$, $e^{5t}$ gibi sorular getirir, $e^{0t}$ gibi bir soru gelmez, dedi.

> **Ders sonrası not:** Hoca bu cevapta "$e^{0t}$ zaten Dirac delta $t$'dir" dedi. Bu yanlıştır. $b = 0$ iken $e^{0\cdot t}u(t) = u(t)$, yani birim basamaktır. Dönüşümü $\frac{1}{s}$, ROC'u $\sigma > 0$'dır, bunu formül de verir. Dışarıda kalan $b = 0$ değil, ROC'un sınırının tam $j\omega$ ekseni üzerine düşmesidir. Eksen ROC'a dahil olmadığı için Fourier dönüşümü $s = j\omega$ koyarak bulunamaz. $u(t)$'nin Fourier dönüşümü $\pi\delta(\omega) + \frac{1}{j\omega}$'dır. Dirac deltanın Laplace dönüşümü ise $1$'dir.

Hoca geçen dersten üç işareti hatırlattı: $e^{-5t}u(t)$, $e^{-5t}u(-t)$ ve $e^{5t}u(t)$. Fourier dönüşümünde birincisi mümkün, diğerleri mümkün değil demiştik. Bunlar artık bu şartlar altında Laplace dönüşümüyle mümkün hale gelir.

> **Ders sonrası not:** Hoca bu üç işaretin sonuçlarını derste yazmadı. Tanımdan sırasıyla $\frac{1}{s+5}$ ($\sigma > -5$), $-\frac{1}{s+5}$ ($\sigma < -5$) ve $\frac{1}{s-5}$ ($\sigma > 5$) çıkar. Yalnız ilkinin ROC'u $j\omega$ eksenini içerir. Üçü de Python ile sayısal olarak kontrol edildi.

Tamamlamak için bu kısmın sonunda hoca, ROC çiziminde $\sigma$'yı $-b$'ye eşitleyip o noktadan başlayan bölgeyi düşündüğümüzü söyledi. Kastedilen, bölgenin başlangıç noktasıdır. Şart yine $\sigma > -b$'dir.

## 9. Laplace ile Fourier Arasındaki İlişki

$\sigma = 0$ olduğunda $s = j\omega$ olur ve Laplace dönüşümü, sürekli zamanlı Fourier dönüşümüne eşittir.

<!-- BELİRSİZ: 01:29:44 civarında altyazı bozuk: sıfır olan şeyin adı yerine bir özel ad yazılmış. Bağlamdan "b'nin sıfır olması değil, sigma'nın sıfır olması kastediliyor" diye okundu. -->

> **Hocanın vurgusu:** Maalesef bazı Türkçe kitaplarda doğrudan $s = j\omega$ deniyor. Bu yanlıştır. $s = \sigma + j\omega$'dır. Yalnız $\sigma = 0$ iken $s = j\omega$ olur ve ancak bu durumda iki dönüşümü eşitleyebiliriz.

$\sigma = 0$ doğrusu, s-düzlemindeki düşey eksendir. Hatırlanması gereken kural şudur: **ROC $j\omega$ eksenini içeriyorsa Fourier dönüşümü vardır ve Laplace dönüşümünde $s = j\omega$ koyarak bulunur.** Hoca $b > 0$ grafiğine dönüp ROC'un $j\omega$'yı içerdiğini, dolayısıyla iki sonucun aynı olduğunu, $b < 0$ grafiğinde ise içermediği için "aynıdır" diyemeyeceğimizi gösterdi.

> **Ders sonrası not:** Hoca "$\sigma$ sıfırken ROC yalnız düşey eksendedir" dedi. $\sigma = 0$, ROC'un kendisi değil, Fourier dönüşümünün hesaplandığı doğrudur. ROC genelde bir yarı düzlemdir. Kuraldaki şart da bu doğrunun ROC içinde kalmasıdır.

Slaytta $\sigma$-$j\omega$ grafiği, renk bilgisiyle üç boyutlu hale getirilmişti. Normalde iki boyutlu çizilen bu düzlemde $e^{-bt}$ için dönüşümün genliği gösteriliyor, $\sigma = 0$ kesiti de görülüyordu.

<!-- BELİRSİZ: Üç boyutlu grafik slaytta; altyazıdan ayrıntısı okunamıyor. -->

**Örnek: $e^{-6t}u(t)$.** Hoca yukarıdaki sonucu şöyle not almamızı söyledi:

- $b = 6$ olduğundan dönüşüm $\frac{1}{s+6}$'dır. İşaret eksi ise paydada artı olur.
- Şart $\sigma > -b$, yani $\sigma > -6$'dır.
- $-6$'dan büyük bölge $j\omega$ eksenini içerir. Dolayısıyla Laplace dönüşümü Fourier dönüşümüne eşittir, $s$ yerine doğrudan $j\omega$ yazabiliriz:

$$X(\omega) = \frac{1}{j\omega + 6}$$

Hem Laplace hem Fourier sonucu Python'da sayısal integralle kontrol edildi. Hoca Fourier tablosuna bakarsak aynı sonucu göreceğimizi de söyledi.

> **Hocanın vurgusu:** Sınavlarda ve bazı derslerde genellikle Laplace ve Fourier dönüşüm tabloları verilir. Önemli olan, Fourier dönüşümünde olduğu gibi Laplace dönüşümünün kolaylaştırıcı kurallarını ve özelliklerini bilmektir.

## 10. Ters Laplace Dönüşümü

Ters Laplace dönüşümü (inverse Laplace transform), s-düzleminden $t$ düzlemine geçer ve Fourier dönüşümündeki ters dönüşüm gibi çalışır:

$$x(t) = \frac{1}{2\pi j} \int_{c - j\infty}^{c + j\infty} X(s)\, e^{st}\, ds$$

Burada $s$ yerine $c + j\omega$ vardır. Bu doğrunun ROC içinde olduğu kabul edilir.

Hocaya göre matematikçi olsaydık bu integrali çok kullanırdık. Biz ise pek kullanmayız, çünkü elimizde tablolar var. Örneğin $\frac{1}{s-5}$ verildiğinde bunun $e^{5t}$'nin Laplace dönüşümü olduğunu ROC şartına dikkat ederek doğrudan söyleriz.

En çok karşılaşacağımız durum, $X(s)$'in karmaşık bir fonksiyon olarak verilmesidir. Elektrik devrelerinde ve bilgisayar sistemlerinde kullanılan model genelde $s$'e bağlı rasyonel bir fonksiyondur. Bunu daha basit kesirler halinde yazarsak, yani kısmi kesirlere ayırma (partial fraction expansion) yaparsak, tablolarla ters dönüşüm kolaylaşır. Hoca bunu sonraki derste anlatacağını söyledi.

Ters dönüşüm integrali $\frac{1}{s+6}$ ve $\frac{1}{s-5}$ üzerinde, ROC içinden geçen birer doğruda sayısal olarak kontrol edildi. Python sonucu $e^{-6t}$ ve $e^{5t}$ değerlerine yakın çıktı. İntegral sınırları kesildiği için küçük bir fark kalır.

## 11. Temel Laplace Dönüşümleri

Hoca, birkaç örnekle hem Laplace dönüşüm tablosunu oluşturmayı hem de bazı kuralları göstermeyi hedefledi. Bu bölümde sonuçları hep fonksiyon gibi yazıyoruz. Hoca, bunları sinyal olarak kullandığımızda ROC ve $u(t)$'lerin de işe gireceğini, sonuçların ona göre biraz değişeceğini hatırlattı. Şimdilik integralin alınabilir olduğunu düşünüyoruz.

### 11.1 Sabit

İşaretimiz sabit bir $A$ olsun. Hoca integrali önce $-\infty$'dan $+\infty$'a yazdı, sonra "burada sıfırdan itibaren yazıyoruz, tek taraflı kabul edeceğiz, şurası yanlış oldu" diye düzeltti:

$$\mathcal{L}\{A\} = \int_0^\infty A\, e^{-st}\, dt = A \left. \frac{e^{-st}}{-s} \right|_0^\infty = A\left[0 - \frac{1}{-s}\right] = \frac{A}{s}$$

ROC şartlarını ayrıca yazacağız. Yani $3$, $5$, $7$ gibi bir sabitin dönüşümü $A/s$'dir.

> **Ders sonrası not:** Hoca integrali "$e^{-st}$ bölü $-st$" diye söyledi. $t$'ye göre integralde payda $-s$'dir. Ayrıca sınırlar $-\infty$'dan başlatılsaydı bu integral hiçbir $s$ için yakınsamazdı. Sonucun tek taraflı olması bu yüzden gereklidir. $t = \infty$'daki sıfır değeri için $\mathrm{Re}(s) > 0$ gerekir.

### 11.2 Polinom

$t^n$ için integral iki çarpan içerir ve kısmi integrasyonla (integration by parts) çözülür. Tabloda göreceğimiz sonuç şudur:

$$\mathcal{L}\{t^n\} = \int_0^\infty t^n\, e^{-st}\, dt = \frac{n!}{s^{n+1}}$$

$n = 0$ için sabit sonucuyla tutarlıdır: $A \cdot t^0 = A$ ve $A \cdot \frac{0!}{s^{0+1}} = \frac{A}{s}$. Bir örnek daha: $t^2 \leftrightarrow \frac{2!}{s^3}$.

> **Ders sonrası not:** Hoca $n$ için "pozitif doğal sayı" dedi, ama hemen $n = 0$'ı kullandı. Formül $n = 0, 1, 2, \ldots$ için geçerlidir. $n = 0$'dan $5$'e kadar Python ile sayısal integralle kontrol edildi.

**Ters dönüşüm örneği 1.** Elimizde $6 \cdot \frac{4!}{s^5}$ olsun. $4!$ ve $s^5$ birlikte $t^4$'ü söyler, $6$ da önündeki katsayıdır. Sonuç bir öğrencinin de söylediği gibi $6t^4$'tür. Hoca, katsayı $6$ değil $\frac{6}{17}$ olsaydı da hiçbir şeyin değişmeyeceğini, sonucun $\frac{6}{17}t^4$ olacağını ekledi.

**Ters dönüşüm örneği 2.** Bu kez faktöriyel görünmüyor: $\frac{6}{s^5}$. Burada biraz matematiksel manipülasyon yaparız. $s^5$ olduğuna göre bu, $t^4$'lü bir şeydir. Kesrin üstünde $4!$ olması gerekir. Eksik faktöriyeli çarpıp böleriz:

$$\frac{6}{s^5} = \frac{6}{4!} \cdot \frac{4!}{s^5} \to \frac{6}{24}\, t^4 = \frac{t^4}{4}$$

Hoca bunun çok kullanacağı özelliklerden biri olduğunu söyledi.

### 11.3 Doğrusallık

Laplace dönüşümünde bir sabit dışarı çıkar. Hoca buna çarpımsallık özelliği dedi:

$$\mathcal{L}\{a\, f(t)\} = a\, \mathcal{L}\{f(t)\}$$

**Örnek: $\mathcal{L}\{5t - 6\}$.** $5t$ için $t \leftrightarrow \frac{1!}{s^2}$, önünde de $5$ vardır. $6$ için sabit kuralı geçerlidir:

$$\mathcal{L}\{5t - 6\} = \frac{5}{s^2} - \frac{6}{s}$$

**Alıştırma: $\mathcal{L}\{3t^2 - 2t + 3\}$.** Hoca bunu öğrencilere çalışırken denemeleri için bıraktı. Aynı kurallarla (ara adım eklendi):

$$\mathcal{L}\{3t^2 - 2t + 3\} = 3\cdot\frac{2!}{s^3} - 2\cdot\frac{1!}{s^2} + \frac{3}{s} = \frac{6}{s^3} - \frac{2}{s^2} + \frac{3}{s}$$

İkisi de Python ile kontrol edildi.

### 11.4 Üstel

Daha önce integralle bulduğumuz sonuç şudur:

$$\mathcal{L}\{e^{at}\} = \frac{1}{s-a}$$

Üstteki işaret ile paydadaki işaret arasında fark vardır: $e^{-5t} \to \frac{1}{s+5}$, $e^{5t} \to \frac{1}{s-5}$.

### 11.5 Sinüs

$B\sin(at)$'de $B$ katsayıdır, dışarı çıkar. İspat için integrale $\sin(at)$ yazılır, sinüs üstel formda açılır ve iki integral ayrı ayrı alınır. Hoca antrenman yapmak isteyenlere bıraktı. Sonuç:

$$\mathcal{L}\{B\sin(at)\} = B\,\frac{a}{s^2 + a^2}$$

Hoca sonucu şöyle okudu: $t$'nin önündeki değer neyse, kesrin üstünde o, altında $s^2$ ile birlikte onun karesi görülür.

> **Ders sonrası not:** Hoca sinüs integralini $-\infty$'dan $+\infty$'a yazdı. Tablodaki $\frac{a}{s^2+a^2}$ sonucu sağ taraflı $\int_0^\infty$ integralinden gelir, ROC'u $\sigma > 0$'dır. Sınırı $-\infty$ olan iki taraflı integral yakınsamaz.

**Örnek: $\sin(7t)$.** Burada $a = 7$ ve $B = 1$: $\frac{7}{s^2 + 49}$.

**Ters dönüşüm örneği: $\frac{3}{s^2 + 25}$.** Bir öğrenci "sinüs ama yukarıda $3$ değil $5$ olsaydı daha kolaydı" dedi. Doğru yoldadır. Paydadaki reel sayıyı bir şeyin karesi olarak yazabiliriz, en kötü ihtimalle kareköklü yazarız. $25$ yerine $26$ olsaydı $\sqrt{26}$ kullanırdık. Burada $25 = 5^2$ olduğundan kesrin üstünde $5$ gerekir, çarpıp böleriz:

$$\frac{3}{s^2 + 25} = \frac{3}{5} \cdot \frac{5}{s^2 + 25} \to \frac{3}{5}\sin(5t)$$

### 11.6 Kosinüs

Kosinüste kesrin üstünde sabit sayı yerine $s$ bulunur:

$$\mathcal{L}\{B\cos(at)\} = B\,\frac{s}{s^2 + a^2}$$

Hoca bunun katsayılarla uğraştırmadığı için daha düzenli olduğunu söyledi. Örnekler:

- $\cos(3t) \to \frac{s}{s^2 + 9}$
- $\frac{5s}{s^2 + 9} \to 5\cos(3t)$

**Ayırt etme ipucu:** Yukarıda $s$'li bir şey, aşağıda $s^2$ varsa kosinüs ararsınız. Yukarıda sabit bir sayı, aşağıda $s^2$ varsa sinüs ararsınız. Üstelde ise paydada $s^2$ hiç olmaz.

**Pay ve payda aynı dereceden olursa: $\frac{s^2}{s^2 + 9}$.** Şimdiye kadar böyle bir model görmedik. $s$ bölü $s^2 + 9$ olsa kolaydı. Bunu basit kesirlere çevirmek için $s^2$'yi $s^2 + 9$'a böleriz: Bir kez gider, kalan $-9$'dur.

$$\frac{s^2}{s^2 + 9} = 1 - \frac{9}{s^2 + 9}$$

Laplace dönüşümü $1$ olan ifade $\delta(t)$'dir. $9 = 3 \cdot 3$ olduğundan ikinci terim $3\sin(3t)$'den gelir:

$$\frac{s^2}{s^2 + 9} \to \delta(t) - 3\sin(3t)$$

Hoca, çözümün var olduğunu ama bu tür ifadeleri ilerideki derslerde göreceğimizi, şimdilik temel fonksiyon ve kuralları iyice öğrenmemiz gerektiğini söyledi. Cebirsel ayrıştırma ve $3\sin(3t)$ dönüşümü Python ile kontrol edildi.

### 11.7 Kosinüsün Dönüşümü İntegralle Nasıl Bulunur?

Temel fonksiyonlar, yani sabit, polinom, üstel, sinüs ve kosinüs bu kadar. Hoca çoğu kitap gibi ispatları uzun uzun yapmadığını, isteyenin integrale yerine yazıp bulabileceğini söyledi. $\cos(3t)$'yi integrale yazdığımızda çarpım şeklinde bir integral elde ederiz:

$$\int_0^\infty \cos(3t)\, e^{-st}\, dt$$

Değişken dönüşümü burada işe yaramaz, çünkü bir tarafa $u$ desek $du$'yu kalan kısımdan bulamayız. O yüzden kısmi integrasyon uygularız: bir tarafa $u$, diğer tarafa $dv$ deriz.

Hoca hangisine $u$ denmesi gerektiğini sordu ve iki seçimi de karşılaştırdı. Bu örnekte iki seçim de çalışır: Hem kosinüsün türevi kolaydır hem üstelin integrali kolaydır. Pratikte bir sıra vardır, hoca buna LAPTÜ dedi. $u$ seçerken öncelik sırası şöyledir:

- **L:** Logaritmik
- **A:** Ters trigonometrik (arc)
- **P:** Polinom
- **T:** Trigonometrik
- **Ü:** Üstel

Asıl ölçüt ise bu sıra değil, ikinci integralin daha kolay hale gelmesidir. Hoca, $t^m \sin(t)\, e^{-st}$ gibi üç çarpanlı bir ifadede farkın belirginleştiğini söyledi. Orada iç içe iki kısmi integrasyon çıkar: Bir çarpana $u$, kalanına $dv$ dersiniz, sonra $dv$'nin içinde tekrar aynı şeyi yaparsınız.

Hoca hesabı tamamlamadı. Genel $a$ için tamamlanışı şöyledir (ara adım eklendi). $I = \int_0^\infty \cos(at)\, e^{-st}\, dt$ ve $J = \int_0^\infty \sin(at)\, e^{-st}\, dt$ diyelim. $u = \cos(at)$, $dv = e^{-st}dt$ seçilirse

$$I = \frac{1}{s} - \frac{a}{s}\, J$$

aynı işlem $J$ için yapılırsa $J = \frac{a}{s}\, I$ bulunur. Yerine yazınca

$$I = \frac{1}{s} - \frac{a^2}{s^2}\, I \quad\Rightarrow\quad I = \frac{s}{s^2 + a^2}$$

Her iki ara eşitlik de Python ile sayısal olarak kontrol edildi.

## 12. s-Düzleminde Öteleme

Hoca integrale girmeden kullanabileceğimiz bir kural daha verdi. Sönümlü fonksiyonlar bize epey zorluk çıkarıyordu. Bir $f(t)$'yi sönümlendirmek için onu $e^{at}$ ile çarpalım. $a$ negatif kabul edilirse bu çarpan $t = 0$'da $1$'dir, sonsuzda sıfıra gider. $f(t)$'nin dönüşümü $F(s)$ ise

$$\mathcal{L}\{e^{at} f(t)\} = F(s - a)$$

olur. Yani s-düzleminde $a$ kadar öteleme (shift) yapılır: $s$ gördüğümüz her yere $s - a$ yazarız.

**Örnek 1: $t\, e^{3t}$.** Bunu $e^{-st}$ ile çarpıp integralden de çıkarabiliriz. Ama $t$'nin dönüşümünün $\frac{1!}{s^2}$ olduğunu biliyoruz. $a = 3$ olduğu için $s$ yerine $s - 3$ yazarız:

$$t\, e^{3t} \to \frac{1}{(s-3)^2}$$

**Örnek 2: $t^4\, e^{-3t}$.** Önce $t^4 \to \frac{4!}{s^5}$. Sonra $a = -3$ olduğundan $s - (-3) = s + 3$:

$$t^4\, e^{-3t} \to \frac{4!}{(s+3)^5}$$

Bu cevabı bir öğrenci verdi.

**Örnek 3 (ters dönüşüm): $\frac{4}{(s-2)^6}$.** Hoca işin bir de ters tarafını düşünmemiz gerektiğini söyledi.

- Bir öğrenci önce "$e^{2t}$ çarpı $\frac{4}{6!}$" dedi. Hoca paydadaki üsse dikkat çekti.
- Paydadaki $6$, bize $t^5$'li bir şeyin dönüşümünü söyler, çünkü $n + 1 = 6$ ise $n = 5$'tir.
- $t^5$ için yukarıda $5!$ olması gerekir. Yok, o zaman çarpıp böleriz.
- Paydadaki $(s - 2)$, $a = 2$ kadar öteleme yapıldığını, yani işaretin $e^{2t}$ ile çarpıldığını gösterir.

$$\frac{4}{(s-2)^6} = \frac{4}{5!} \cdot \frac{5!}{(s-2)^6} \to \frac{4}{120}\, t^5\, e^{2t} = \frac{1}{30}\, t^5\, e^{2t}$$

Son sadeleştirme ara adım olarak eklendi. Sonuç Python ile kontrol edildi.

**Örnek 4: $\sin(5t)\, e^{at}$.** $\sin(5t) \to \frac{5}{s^2 + 25}$. Çarpan öteleme yapar:

$$\sin(5t)\, e^{at} \to \frac{5}{(s-a)^2 + 25}$$

Tersinden okursak: Paydada $s^2$'li bir şey var ama $s$ yalnız değilse, bu $e^{at}$ ile çarpılmış bir sinüstür.

**Örnek 5: $\cos(\sqrt{7}\, t)\, e^{-3t}$.** Bir öğrenci parça parça çözdü: Kosinüs olduğu için yukarı $s$ gelir, altta $s^2 + 7$ olur, öteleme $s + 3$ getirir. Öğrenci önce yukarıdaki $s$'in aynen kalacağını düşündü. Hocanın sorusuyla onun da $s + 3$ olması gerektiğini fark etti, çünkü $s$ gördüğümüz her yere yazıyoruz:

$$\cos(\sqrt{7}\, t)\, e^{-3t} \to \frac{s+3}{(s+3)^2 + 7} = \frac{s+3}{s^2 + 6s + 16}$$

Payda açılımı: $(s+3)^2 = s^2 + 6s + 9$, üzerine $7$ eklenince $16$.

Hoca sorunun size bu açılmış şekilde de gelebileceğini söyledi. O zaman yapılacak şey şudur: Yukarıda $s$'li bir şey, aşağıda $s^2$ var. Aşağısını yukarıdaki $s + 3$ cinsinden yazabilir miyim diye bakarız. $s$'in katsayısının yarısının karesi alınır. $(s+3)^2$ buradan gerçekten çıkar, kalan $7$ olur. Çıkmazsa terim ekleyip çıkarırız. Sonuç, $e^{-3t}$ ile çarpılmış bir kosinüstür.

## 13. Temel Frekans Sorusu

Aradan sonra bir öğrenci temel frekansla ilgili bir soru sordu. Sorunun kendisi altyazıda duyulmuyor, hocanın cevabı şöyledir.

<!-- BELİRSİZ: Öğrencinin sorusu altyazıda yok (02:13:51 civarı). Hoca cevabın sonunda "kosinüs işaretlerinden bahsediyoruz" dedi, örnekler ise sinüslüdür. -->

Temel frekans, işaretin frekansları radyan cinsinden veriliyorsa $\omega_0$, normal frekans olarak veriliyorsa $f_0$ ile gösterilir.

**Örnek 1: $\sin(5\pi t) + \sin(7\pi t)$.** Açısal frekanslar $5\pi$ ve $7\pi$'dir. Temel frekans için ortak bölenlerine (OBEB) bakılır: $\omega_0 = \pi$ rad/s.

**Örnek 2: $\sin(6\pi t) + \sin(8\pi t)$.** Hoca hesabı kolaylaştırmak için sayıları değiştirdi.

- Açısal frekansların ortak böleni $2\pi$'dir.
- $\omega = 2\pi f$'den $f_1 = 3$ Hz ve $f_2 = 4$ Hz bulunur.
- Bunların ortak böleni $f_0 = 1$ Hz'dir.
- Geri dönüştürürsek $\omega_0 = 2\pi f_0 = 2\pi$ rad/s olur.

Python ile kontrol edildi: Birinci toplamın periyodu $T = 2$ s, ikincisinin $T = 1$ s'dir. Daha kısa aday değerlerde işaret kendini tekrar etmez.

> **Ders sonrası not:** Hoca "$\omega_0$ yazabilmek için içinde $\pi$ olması gerekir" dedi. Bu yalnız bu örneklere özgüdür. Toplamın periyodik olması için gereken şart, frekansların oranının rasyonel olmasıdır. Frekanslarda $\pi$ bulunması gerekmez.

## 14. Paydayı Tam Kareye Tamamlama

Hoca, aklına gelen bir örnek türünü daha gösterdi.

**Örnek 1: $\frac{s+4}{s^2 + 8s + 20}$.** Yukarıda $s + 4$ var. Aşağıdan $s + 4$'ün kare açılımını bulabilir miyiz? $(s+4)^2 = s^2 + 8s + 16$ çıkar, kalan $4$'tür:

$$\frac{s+4}{s^2 + 8s + 20} = \frac{s+4}{(s+4)^2 + 2^2} \to e^{-4t}\cos(2t)$$

Yukarıda $s$'li bir ifade olduğu için kosinüs, $2^2$'den dolayı $2t$, $s + 4$'ten dolayı $e^{-4t}$ çarpanı gelir.

**Örnek 2: $\frac{s+5}{s^2 + 8s + 19}$.** Şimdi $s + 5$'in altta tam karesi yoktur, çünkü olması için $s^2 + 10s + 25$ gerekirdi. Terim ekleyip çıkarmak işi iyice karıştırır. Onun yerine yukarıdaki sayıyı azaltıp paydadan gelen $s + 4$'e uydururuz. Fazlalığı ise rasyonel sayılarda toplama yapar gibi ayrı bir kesir olarak yazarız:

$$\frac{s+5}{s^2 + 8s + 19} = \frac{s+4}{s^2 + 8s + 19} + \frac{1}{s^2 + 8s + 19}$$

Payda için $s^2 + 8s + 19 = (s+4)^2 + 3$ yazılır.

- **Birinci kesir:** $\frac{s+4}{(s+4)^2 + 3} \to e^{-4t}\cos(\sqrt{3}\, t)$.
- **İkinci kesir:** $3 = (\sqrt{3})^2$ olarak yazılır, sinüs için kesrin üstünde $\sqrt{3}$ gerekir, çarpılıp bölünür:

$$\frac{1}{(s+4)^2 + 3} = \frac{1}{\sqrt{3}} \cdot \frac{\sqrt{3}}{(s+4)^2 + 3} \to \frac{1}{\sqrt{3}}\, e^{-4t}\sin(\sqrt{3}\, t)$$

İkisini toplarsak:

$$\frac{s+5}{s^2 + 8s + 19} \to e^{-4t}\cos(\sqrt{3}\, t) + \frac{1}{\sqrt{3}}\, e^{-4t}\sin(\sqrt{3}\, t)$$

İstersek $e^{-4t}$ parantezine alabiliriz. Her iki örnek de Python ile kontrol edildi.

## 15. $t^n$ ile Çarpma Özelliği

Son özellik: Bir fonksiyonu $t^n$ ile çarpıyorsak, dönüşümün $s$'e göre $n$. dereceden türevini alırız:

$$\mathcal{L}\{t^n f(t)\} = (-1)^n \frac{d^n F(s)}{ds^n}$$

Hoca, çok yüksek dereceli türevlerle soruyu zorlaştırmaya gerek olmadığını, kuralı bilmenin yeterli olduğunu söyledi.

**Örnek: $\mathcal{L}\{t\sin(2t)\}$.** Yanında $e^{\ldots}$ olsaydı sinüsten geçmek kolaydı, ama $t$ ile çarpınca integral zorlaşır. Bu kuralla rahatça yapılır.

- **Verilen dönüşüm:** $\sin(2t) \to \frac{2}{s^2 + 4}$.
- **Kural:** $n = 1$ için $(-1)^1$ çarpı $s$'e göre birinci türev.
- **Türev:** Kesri $2(s^2 + 4)^{-1}$ olarak yazalım. $-1$ başa gelir, içerinin türevi $2s$, katsayı $2$ ile birlikte $4s$ gelir, üs bir azalıp $-2$ olur:

$$\frac{d}{ds}\left[2(s^2+4)^{-1}\right] = -\frac{4s}{(s^2+4)^2}$$

- **Sonuç:** Baştaki $(-1)$ ile çarpınca

$$\mathcal{L}\{t\sin(2t)\} = \frac{4s}{(s^2+4)^2}$$

Sonuç Python ile sayısal integralle kontrol edildi.

Hoca dikkat edilecek noktayı şöyle gösterdi: Bu ifade, $\frac{4s}{s^2+4}$ gibi kosinüs formunda bir şey değildir. İçeride $s^2$, dışarıda da parantezin karesi varsa, bu sinyalin $t$ ile çarpılmış olduğunu gösterir. Bunun ters dönüşümünü kuraldan bulmak biraz zor olabilir, çünkü birinci dereceden mi ikinci dereceden mi türev olduğuna bakmak gerekir.

## Dersin Toparlaması

Bu derste önce sistemi tanımlayan üç kavram bir araya getirildi: zaman düzleminde dürtü cevabı $h(t)$, Fourier düzleminde frekans cevabı $H(\omega) = Y(\omega)/X(\omega)$, Laplace düzleminde transfer fonksiyonu $H(s) = Y(s)/X(s)$. Amaç, kara kutuyu modelleyip her giriş için çıkışı tahmin edebilmektir. Sera örneği bu modelleme işinin kontrol mühendisi ve bilgisayar mühendisi tarafındaki karşılığını gösterdi.

Ardından Laplace dönüşümü, Fourier dönüşümünün yakınsamadığı durumları hafifleten genel hal olarak tanıtıldı: $s = \sigma + j\omega$ ve $e^{-\sigma t}$ sönümleme çarpanı. Her dönüşümün yanında bir yakınsama bölgesi bulunduğu, ROC $j\omega$ eksenini içeriyorsa dönüşümün Fourier dönüşümüyle aynı olduğu $e^{-bt}u(t)$ üzerinde görüldü. Sonra sabit, polinom, üstel, sinüs ve kosinüs dönüşümleri, doğrusallık, s-düzleminde öteleme ve $t^n$ ile çarpma kurallarıyla ters dönüşümde tablo kullanımı çalışıldı.

Hoca devamını önümüzdeki derslere bıraktı. Sırada Laplace dönüşümünün devam eden özellikleri, ROC'un sinyallerle birlikte kullanımı ve kısmi kesirlere ayırma vardır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
