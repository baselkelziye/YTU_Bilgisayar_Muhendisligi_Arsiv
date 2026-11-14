# Ders 7 Genişletilmiş Notu: Sınav Öncesi Tekrar: Fourier Serileri, İşaret ve Sistem Özellikleri, Konvolüsyon ve Quiz Çözümü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Fourier Serilerinin Amacı ve Üç Formül
- 2. Kare Dalganın Fourier Serisi
- 3. Tek ve Çift İşaretlerde Kısayol
- 4. Frekans Spektrumu ve Negatif Frekans
- 5. Parseval Teoremi ve Ses Sentezi Fikri
- 6. Fourier Serisi Örneği: Parçalı $e^{-t}$ İşareti
- 7. Ayrık İşarette Öteleme, Ters Çevirme ve $x[2n]$
- 8. Sürekli İşaretin Örneklenmesi
- 9. Periyodiklik ve Temel Periyot
- 10. Enerji ve Güç İşaretleri
- 11. Basamak, Darbe ve İşaret Fonksiyonlarıyla İşlemler
- 12. Sistem Özellikleri: İki Tam Çözüm
- 13. Tek ve Çift Bileşenlere Ayırma
- 14. Konvolüsyon Tekrarı
- 15. Quiz Sorularının Çözümü
- 16. Spektrumdan İşarete, Ses Örnekleri ve Temel Frekans

## 1. Fourier Serilerinin Amacı ve Üç Formül

Bu ders, soru çözümüne dayalı bir genel tekrardır. Hoca önce Fourier serilerini özetledi, sonra hazırladığı çalışma sorularını ve quiz sorularını çözdü.

Fourier serilerini görme sebebimiz şudur: Periyodik bir işareti, belli şartlar altında, daha bilinen basit işaretler cinsinden yazmak. Buna ayrıştırma (decomposition) dedik. Birinci amaç, herhangi bir $x(t)$ işaretini sinüzoidal işaretler cinsinden yazmaktır. Sinüzoidlerden birinin frekansı sıfırdır, onu $a_0$ diye ayrı tutarız. Geri kalanı, $k = 1$'den sonsuza kadar giden kosinüs bileşenlerinin toplamıdır. Teori budur.

Bu toplamda kosinüsün frekansı işaretten belirlenebilir, çünkü $\omega_0$ serbest bir değişken değildir. Periyodik bir işaretin periyodunu bulup oradan frekansına geçeriz. Kare dalganın periyodunu ve frekansını bulmak basittir. Önemli olan, bu frekansı bulduktan sonra onun 1 katı, 2 katı, 3 katı frekanslarda bileşen olup olmadığına bakmaktır. Bileşen varsa o frekanstaki katsayı sıfırdan farklı çıkar.

Mantık şudur: İşareti sinüzoidal işaretlerle karşılaştırırız, benzerliğine bakarız. İşaretin içinde belli bir frekansta sinüzoid varsa sonuç pik verir. Yoksa pik vermez ve o frekansta bileşen yok deriz.

> **Ders sonrası not:** Hoca bu karşılaştırmaya birkaç yerde "konvolüsyon" dedi. Hocanın 01:47'deki kendi tanımına göre konvolüsyonda işaretlerden biri ters çevrilir ve ötelenir. Burada ters çevirme ve öteleme yoktur: İşaret $e^{-jk\omega_0 t}$ ile çarpılır ve bir periyot boyunca integre edilir. Hocanın yanında söylediği "korelasyon, benzerlik" ifadesi bu işleme daha uygundur.

> **Ek bilgi (derste anlatılmadı):** Bu benzerlik ölçümünün her frekansı ayrı ayrı yakalamasının sebebi harmoniklerin birbirine dik olmasıdır: $k \ne m$ için $\int_T e^{jk\omega_0 t} e^{-jm\omega_0 t}\, dt = 0$, $k = m$ için sonuç $T$'dir. Bu eşitlik sayısal olarak doğrulandı. Bu yüzden integralde yalnız aranan harmonik kalır.

### 1.1 Üç Eşdeğer Yazım

Hocaya göre üç formül aslında birbirinin aynısıdır:

$$x(t) = a_0 + \sum_{k=1}^{\infty} \left[ a_k \cos(k\omega_0 t) + b_k \sin(k\omega_0 t) \right]$$

$$x(t) = a_0 + \sum_{k=1}^{\infty} A_k \cos(2\pi f_k t + \phi_k)$$

$$x(t) = \sum_{k=-\infty}^{\infty} c_k\, e^{jk\omega_0 t}$$

İkinci yazımda frekans, genlik ve faz $k$'ya bağlıdır. Her sinüs bir kosinüs cinsinden rahatça yazılabilir, çünkü aralarında 90 derecelik faz farkı vardır. Üçüncü yazımda $e^{jk\omega_0 t}$ açılırsa $\cos(k\omega_0 t)$ ve $\sin(k\omega_0 t)$ gelir. Bunların önüne sinüsler ve kosinüsler için ayrı katsayılar gelir. Yani işaretin içindeki kosinüsleri ve sinüsleri ayrı ayrı analiz edebiliriz.

Bazı kaynaklarda $c_k$ yerine $a_k$ yazılır. Yanında $e^{jk\omega_0 t}$ varsa bu da yanlış değildir, yalnız bir yazım farkıdır.

Hesap için en kullanışlı yol karmaşık formdur. Önce $c_k$ bulunur, sonra $a_k$ ve $b_k$ değerlerine geçilir:

$$c_k = \frac{1}{T} \int_{t_0}^{t_0 + T} x(t)\, e^{-jk\omega_0 t}\, dt$$

$k = 0$ özel bir durumdur. Frekans sıfır olunca üstel terim $e^0 = 1$ olur ve geriye yalnız işaretin integrali kalır:

$$c_0 = a_0 = \frac{1}{T} \int_T x(t)\, dt$$

DC bileşen dediğimiz şey budur. Elimizde bir dalga biçimi varsa, bir periyottaki alanı analitik geometriyle hesaplayıp periyoda bölerek de $c_0$ bulunur. İntegralle aynı şeydir.

$a_k$ kosinüs bileşenidir ve $c_k$'nın reel tarafından gelir. Kosinüsün üstel açılımında bölü 2 olduğu için o 2'yi yok etmek üzere reel kısım 2 ile çarpılır. $b_k$ sinüs bileşenidir ve sanal kısımdan gelir:

$$a_k = 2\,\mathrm{Re}\{c_k\}, \qquad b_k = -2\,\mathrm{Im}\{c_k\}$$

## 2. Kare Dalganın Fourier Serisi

Hoca daha önce konuşulan kare dalga örneğini tekrar etti. İşaret $0 \le t < 1$ aralığında 1, $1 \le t < 2$ aralığında 0'dır ve kendini tekrar eder.

**Periyot ve frekans.** İşaret kendini 2 saniyede bir tekrar eder, yani $T = 2$. Periyodu nereden ölçtüğünüzün önemi yoktur: Bir düşen kenardan sonraki düşen kenara da 2 saniyedir. Buradan $f = 1/2$ ve $\omega_0 = 2\pi f = \pi$ rad/s bulunur.

**İntegralin sınırları.** Başlangıç noktası istenildiği gibi seçilebilir, ama en makulü kolay olanı seçmektir.

> **Hocanın vurgusu:** Başlangıç noktasını seçerken önemli olan, integrali çok parçalı hale getirmemektir.

Burada 0'dan 2'ye gidilir. İşaret 0-1 aralığında başka, 1-2 aralığında başka davranır. 1-2 aralığı sıfır olduğu için doğrudan gider:

$$c_k = \frac{1}{2} \int_0^2 x(t)\, e^{-jk\pi t}\, dt = \frac{1}{2} \int_0^1 e^{-jk\pi t}\, dt$$

**İntegral.** Hocanın hatırlattığı kural: $e^{at}$'nin integrali $e^{at}$ bölü $t$'nin yanındaki katsayıdır. Buna göre:

$$c_k = \frac{1}{2} \cdot \frac{e^{-jk\pi t}}{-jk\pi} \Bigg|_0^1 = \frac{1}{2} \cdot \frac{e^{-jk\pi} - 1}{-jk\pi}$$

**Üstel terimi çözmek.** Hoca bu noktada kosinüse geri dönüşüm yaptı:

$$e^{-jk\pi} = \cos(k\pi) - j\sin(k\pi)$$

Birim çemberde $k\pi$ her zaman yatay eksene düşer. Sinüs ekseninde karşılığı sıfırdır: $\sin 180^\circ$ de $\sin 360^\circ$ de sıfırdır. Kosinüs ise $k$ tekse $-1$, çiftse $+1$ olur.

> **Hocanın vurgusu:** $e^{-j\theta} = \cos\theta - j\sin\theta$ dönüşümünü çok iyi kullanmak gerekir.

- $k$ çift: Pay $1 - 1 = 0$ olur, dolayısıyla $c_k = 0$.
- $k$ tek: Pay $-1 - 1 = -2$ olur. 2'ler sadeleşir: $c_k = \dfrac{-2}{2 \cdot (-jk\pi)} = \dfrac{1}{jk\pi} = \dfrac{-j}{k\pi}$.

**DC bileşen.** İşareti bir periyot boyunca entegre ederiz. Bu, alan hesabıdır: $c_0 = \frac{1}{2} \cdot 1 = \frac{1}{2}$.

**$a_k$ ve $b_k$.** $c_k = -j/(k\pi)$ ifadesinde reel kısım yoktur. $A + jB$ biçiminde düşünürseniz yalnız $j$'li terim vardır. O yüzden:

$$a_k = 0, \qquad b_k = -2 \cdot \left( -\frac{1}{k\pi} \right) = \frac{2}{k\pi} \quad (k \text{ tek})$$

**Sonuç.** Yerine yazınca:

$$x(t) = \frac{1}{2} + \frac{2}{\pi} \sin(\omega_0 t) + \frac{2}{3\pi} \sin(3\omega_0 t) + \dots, \qquad \omega_0 = \pi$$

$2\omega_0$ gibi çift harmonikler yoktur, çünkü başlarındaki katsayı sıfırdır. Hocaya göre MATLAB'de 5-6 terim toplanırsa kare dalgaya yakın bir sonuç elde edilir.

**Faz bilgisi.** Faz da eklenirse tek $k$ değerlerinde her bileşende $-\pi/2$ vardır. Bu faz $k$'ya göre değişmez. $\cos(\theta - 90^\circ) = \sin\theta$ olduğu için kosinüsler sinüse döner. Yani aynı işaret şöyle de yazılır:

$$x(t) = \frac{1}{2} + \sum_{k\ \text{tek}} \frac{2}{k\pi} \cos\!\left( k\omega_0 t - \frac{\pi}{2} \right)$$

Bu örneğin katsayıları ve sonucu sayısal integralle doğrulandı.

## 3. Tek ve Çift İşaretlerde Kısayol

Bazı işaretlerde integralin bir kısmını hiç hesaplamaya gerek yoktur. Kosinüs çift simetriye, sinüs tek simetriye sahiptir. Buradan iki kural çıkar:

- **Çift işaret** (y eksenine göre simetrik): Yalnız kosinüs bileşenleri vardır, $b_k = 0$. Faz $0$ veya $\pm\pi$ çıkar.
- **Tek işaret:** Yalnız sinüs bileşenleri vardır, $a_k = 0$. $c_k$'nın sanal kısmı alınır. Faz $\pm\pi/2$ çıkar.

> **Hocanın vurgusu:** Tek işarette $a_k$, çift işarette $b_k$ sıfır çıkar. Bunu görürseniz hesaplamaya gerek yoktur.

Hoca kare dalgaya bu gözle yeniden baktı: İntegrale gerek kalmadan, bu bir tek işarettir, $k \ne 0$ için $a_k$ sıfırdır, $c_k$'nın sanal kısmı alınır ve faz $-\pi/2$ gelir.

> **Ders sonrası not:** Hoca kare dalgaya doğrudan "tek işaret" dedi. $x(t)$'nin kendisi tek değildir, ortalaması $1/2$'dir. Tek olan $x(t) - \frac{1}{2}$'dir. Hocanın sonucu bu yüzden $k \ne 0$ için geçerlidir: DC terimi ayrılınca geriye yalnız sinüsler kalır.

## 4. Frekans Spektrumu ve Negatif Frekans

Fourier analizi yapıldıktan sonra frekans spektrumu çizilebilir. Önceden zamana bağlı değişen bir işaret varken, artık genlik-frekans ve faz-frekans grafikleri vardır. Yani zaman düzleminden frekans düzlemine geçmiş oluruz. Bu grafikte frekansın 0 olduğu nokta DC bileşendir. Diğer noktalar temel frekansın, yani $f_0$ veya $\omega_0$'ın katlarıdır. Bir noktada sıfırdan farklı katsayı varsa o frekansta bileşen var demektir.

Bu gösterim birden fazla bileşen olduğunda işe yarar. Tek bir işarette faz bilgisi için $t$ yerine 0 verip değeri bulmaya çalışıyorduk, bu biraz daha zordur. Spektrumda hangi bileşenlerin bulunduğu ve fazları daha rahat analiz edilir.

Hocaya göre inceleyeceğimiz sinyallerin spektrumu genelde şöyledir: Düşük frekanslarda genlikler yüksektir, yüksek frekanslarda azalır.

Spektrum çizme sorusunda yöntem şudur: "Bu işaretin frekans spektrumunun ilk 4 bileşenini çizin" denirse önce temel frekans bulunur. Temel frekans örneğin 5 ise 5, 10, 15 ve 20 frekanslarındaki genlikler yazılır. Kare dalgada $c_k$ çizildiğinde ilk genlik $1/\pi$, sonraki $1/(3\pi)$ gelir, yani azalarak gider.

### 4.1 Negatif Frekans

Spektrum normalde iki taraflıdır, çünkü üstel formda bir frekansın eksi tarafı da vardır. Bu derste daha çok pozitif taraf kullanılır. Hocanın radar örneği şudur: Negatif frekans kağıt üzerinde vardır. Bir araba size yaklaşıyorsa çarpıp gelen dalganın frekansı artar. Uzaklaşıyorsa negatif durumdan söz edilir. Dersin ilerleyen bölümünde hoca bunu slayttaki hız ölçen polis radarı üzerinden tekrar etti: $+400$ Hz gibi bir sonuç aracın radara doğru geldiğini, $-400$ Hz ters yönde gittiğini gösterir. Bu konu ileri işaret işlemenin konusudur.

Hoca bir de tren ıslığı örneği verdi. Tren gelirken ses kulağınıza yoğunlaşarak gelir, giderken uzaklaşır.

> **Ders sonrası not:** Hoca tren ıslığında gelişte ve gidişte "aynı frekans" olduğunu, değişenin yoğunluk olduğunu söyledi. Hocanın radar için söylediği "yaklaşınca frekans artar" ifadesi ile bu çelişir. Duyulan frekans da büyük olasılıkla gelirken yüksek, giderken düşüktür (Doppler etkisi). Yoğunluğun değişmesi bundan ayrı bir etkidir.

## 5. Parseval Teoremi ve Ses Sentezi Fikri

Parseval teoremi, bir periyot boyunca işaretin ortalama gücünün katsayıların karelerinin toplamına eşit olduğunu söyler:

$$P = \frac{1}{T} \int_T |x(t)|^2\, dt = \sum_{k=-\infty}^{\infty} |c_k|^2$$

Zaman düzleminde yapılan güç hesabına çok benzer: Orada işaretin karesini alıp bir periyot boyunca ortalıyorduk, burada katsayıların karelerini topluyoruz.

> **Ders sonrası not:** Hoca Parseval teoremini "işaretin bileşenlerinden kendisini inşa etmek için kullanılan teorem" diye tanıttı. Hocanın yazdığı formül ise yalnız gücü verir ve katsayıların fazını içermez, bu yüzden işareti geri getiremez. İşareti bileşenlerinden kuran, 1.1'deki Fourier serisi toplamının kendisidir.

Hoca bu bileşenleri toplama fikrini bir ses örneğiyle anlattı: Ses analizinde bir karakter, örneğin "A" karakteri için elimizde frekans, faz ve genlik bilgileri vardır. Bunların hepsiyle sinüzoidleri oluşturup topladığınızda ve MATLAB'deki seslendirme komutuyla çaldığınızda o sesi duyarsınız.

## 6. Fourier Serisi Örneği: Parçalı $e^{-t}$ İşareti

Hoca bu örneği yazarak çözdü. İşaretin frekans bileşenleri isteniyor:

$$x(t) = \begin{cases} e^{-t}, & 0 \le t < 1 \\ 0, & 1 \le t < 2 \end{cases} \qquad \text{periyot } T = 2$$

**Adım 1: Periyot ve frekans.** İşaret periyodiktir ve $T = 2$'dir. $f = 1/2$, $\omega_0 = 2\pi f = \pi$ rad/s.

**Adım 2: Formülü yazmak.** İşaret 0-1 ve 1-2 aralıklarında iki türlü davranır. 1-2 aralığı sıfır olduğu için yazılmaz:

$$c_k = \frac{1}{2} \int_0^1 e^{-t} e^{-jk\pi t}\, dt + 0$$

**Adım 3: Üsleri birleştirmek.** Üstlü sayıların özelliğinden $-t$ parantezine alınır:

$$c_k = \frac{1}{2} \int_0^1 e^{-(1 + jk\pi)t}\, dt$$

**Adım 4: İntegral.** Üstel terim aynen yazılır, $t$'nin önündeki $-(1 + jk\pi)$ paydaya gelir:

$$c_k = \frac{1}{2} \cdot \frac{e^{-(1 + jk\pi)t}}{-(1 + jk\pi)} \Bigg|_0^1 = \frac{-1}{2(1 + jk\pi)} \left[ e^{-(1 + jk\pi)} - 1 \right] = \frac{1 - e^{-(1 + jk\pi)}}{2(1 + jk\pi)}$$

**Adım 5: Üstel terimi ayırmak.** $e^{-(1 + jk\pi)}$ içinde $jk\pi$ kısmı dönüşüme uygundur, ama başındaki 1 işi bozar. Üstlü sayıların özelliğiyle $e^{-1} e^{-jk\pi}$ diye ayrılır. $k$ çiftse bu üstel terim $1$, tekse $-1$ olur, yani $(-1)^k$'dır:

$$c_k = \frac{1 - e^{-1}(-1)^k}{2(1 + jk\pi)}$$

Hocaya göre $c_k$ katsayıları bu kadardır. Hoca bir ara $e^{jk\pi}$ yazdı. $k$ tam sayı olduğu için $e^{jk\pi} = e^{-jk\pi} = (-1)^k$'dır ve sonuç değişmez.

**Tek mi, çift mi?** Hoca sordu. Çift olması için y eksenine göre simetri gerekir, bu işarette yoktur. İşaret ne tek ne de çifttir. Hem sinüs hem kosinüs bileşenleri vardır. Bu yüzden $a_k$ ve $b_k$ için formül doğrudan uygulanmalıdır.

**Bir değer yerine koymak.** Hoca $k = 1$ için yerine koydu: $(-1)^1 = -1$ olduğundan pay $1 + e^{-1}$ olur ve

$$c_1 = \frac{1 + e^{-1}}{2(1 + j\pi)} \approx 0.0629 - 0.1977j \quad \text{(sayısal değer eklendi)}$$

$c_0$ için aynı formül $(1 - e^{-1})/2 \approx 0.316$ verir. Bu değerin reel kısmı alınır, sonra $k = 2, 3, \dots$ verilir. İki taraflı spektrum çizilecekse $k = -1, -2, \dots$ da hesaplanır. Formül sayısal integralle $k = -1, 0, 1, 2, 3$ için doğrulandı.

**Spektrum.** Hoca $k = 1$'den 10'a kadar $c_k$ değerlerini gösteren grafiği açtı. Frekans arttıkça genlik bir yerden sonra azalır, sönümlenir. Yani bu işaret belki 30-40 sinüzoid toplanarak yüzde 95-99 oranında elde edilebilir. Daha fazlası için daha çok bileşen eklemek gerekir.

> **Ders sonrası not:** Hoca grafiğe bakarken "temel frekansımız 1'di" dedi. Oysa bu işarette $\omega_0 = \pi$ rad/s, $f_0 = 1/2$ Hz'dir. Grafiğin yatay ekseninde büyük olasılıkla harmonik numarası $k$ vardır, 1 de ilk harmoniği gösterir.

> **Ders sonrası not:** Hocanın oranı güç üzerinden denetlendi: $k = \pm 30$'a kadar toplamda gücün yüzde 99.1'i, $\pm 40$'a kadar yüzde 99.3'ü, $\pm 5$'e kadar yüzde 95.5'i toplanır. Azalma düzgün değildir: $|c_2| \approx 0.050$ iken $|c_3| \approx 0.072$'dir, çünkü paydaki $(-1)^k$ çift ve tek $k$ için farklıdır.

## 7. Ayrık İşarette Öteleme, Ters Çevirme ve $x[2n]$

Hoca buradan sonra kitaplardan alıp hazırladığı çalışma sorularına geçti. İlk soruda işaret vektörel olarak verilir ve altı çizili eleman $n = 0$ noktasıdır:

$$x[n] = [0,\ \underline{0},\ 1,\ 2,\ 3,\ 3]$$

Yani $x[-1] = 0$, $x[0] = 0$, $x[1] = 1$, $x[2] = 2$, $x[3] = 3$, $x[4] = 3$. Diğer noktalar sıfırdır.

**Çizim.** İşaret $n$'e bağlı olduğu için ayrıktır.

> **Hocanın vurgusu:** Ayrık işareti görüp sürekli bir grafik çizmek soruyu doğrudan yanlış yapar. Ayrık işaret çubuklarla, her $n$ noktasında ayrı ayrı çizilir.

**$x[n+2]$.** Önce öteleme yapılır. $n$'e 2 eklemek işareti 2 birim sola alır. 4. örnek 2. noktaya, 3. örnek 1. noktaya gelir:

| $n$ | $-1$ | $0$ | $1$ | $2$ |
|:---:|:---:|:---:|:---:|:---:|
| $x[n+2]$ | 1 | 2 | 3 | 3 |

**$x[-n+2]$.** Şimdi bir önceki sonuçta $n$ yerine $-n$ yazılır. Değerler sıfıra göre karşılıklı yer değiştirir: 2'deki eksi 2'ye, 1'deki eksi 1'e gelir, 0'daki yerinde kalır, eksi 1'deki artı 1'e gider. Hocaya göre önce ters çevirip sonra ötelemek de mümkündür.

| $n$ | $-2$ | $-1$ | $0$ | $1$ |
|:---:|:---:|:---:|:---:|:---:|
| $x[-n+2]$ | 3 | 3 | 2 | 1 |

**$x[2n]$.** Hoca bu soruyu burada sık hata yapıldığı için koyduğunu söyledi. Genlikte değişim olmaz, yalnız örneklerin yeri değişir. 4. örnek 2. noktaya gelir ve değeri 3 kalır. 2. örnek 1. noktaya gelir ve değeri 2'dir. 0. örnek yerinde kalır. 3. örnek ise $1.5$'inci noktaya düşer. Ayrık zamanda böyle bir nokta yoktur, bu yüzden o örnek kaybolur. 1. örnek de aynı sebeple gider.

$$x[2n] = [\underline{0},\ 2,\ 3]$$

Eksi 2. noktada bir örnek olsaydı eksi 1. noktaya gelirdi. Bu işarette orası zaten sıfırdır. Bu üç sonuç doğrudan $x[n]$ tanımından hesapla doğrulandı.

## 8. Sürekli İşaretin Örneklenmesi

Sürekli bir işaret veriliyor ve örneklenmesi isteniyor:

$$x(t) = \begin{cases} 1 - |t|, & -1 \le t \le 1 \\ 0, & \text{diğer} \end{cases}$$

**Çizim.** $t = 0$'da değer 1'dir. $t$ arttıkça doğrusal azalır ve $t = 1$'de 0 olur. Eksi 1'e doğru da aynıdır. Bu bir üçgendir, dışarıda işaret sıfırdır.

**Soru.** (a) $T_s = 0.25$ s, (b) $T_s = 0.5$ s aralıkla örnekleme yapılırsa oluşan ayrık işaret nedir?

Örnekleme frekansı buradan çıkarılabilir, ama işaret basit olduğu için değerler doğrudan yazılır. $n$ tam sayı değerleri alır ve her $n$ için $t = n T_s$ noktasına bakılır. Hoca önce yanlışlıkla "0.5" dedi, bir öğrenci 0.25 olduğunu söyleyince hesabı şöyle yaptı:

- $n = 0$, $t = 0$: $x[0] = 1 - 0 = 1$
- $n = 1$, $t = 0.25$: $x[1] = 1 - 0.25 = 0.75$
- $n = 2$, $t = 0.5$: $x[2] = 1 - 0.5 = 0.5$
- $n = 3$, $t = 0.75$: $x[3] = 1 - 0.75 = 0.25$
- $n = 4$, $t = 1$: $x[4] = 1 - 1 = 0$

Daha sonrası zaten sıfırdır, gitmeye gerek yoktur. İşaretin negatif tarafta da karşılığı olduğu için geriye doğru da gelinir. $|t|$ yüzünden aynı değerler çıkar: $x[-1] = 0.75$, $x[-2] = 0.5$, $x[-3] = 0.25$, $x[-4] = 0$. Sonuç, altı çizili eleman $n = 0$ olmak üzere:

$$x[n] = [0,\ 0.25,\ 0.5,\ 0.75,\ \underline{1},\ 0.75,\ 0.5,\ 0.25,\ 0]$$

**Soru:** Bunun vektörel gösterimi yalnız 0, 1, 0 gibi mi yazılır? **Cevap:** Hayır, bütün değerler yazılır ve sıfır noktasının hangisi olduğu gösterilir.

**Soru:** Sıfır noktasını kendimiz altını çizerek göstersek olur mu? **Cevap:** Olur, nasıl çizebiliyorsanız. Programda altını çizmek zor geliyorsa "sıfır noktası kaçıncı örnek" diye de yazabilirsiniz. Burada sıfır noktası 5. örnektir.

> **Hocanın vurgusu:** Vektörel gösterimde sıfır noktası mutlaka bir şekilde belirtilmelidir. Grafikte zaten yerine oturur.

> **Ders sonrası not:** Altyazıda $x[2]$ için "0.55" geçiyor. Doğrusu $1 - 0.5 = 0.5$'tir. (b) şıkkı derste çözülmedi. Aynı yöntem $T_s = 0.5$ s için $[0,\ 0.5,\ \underline{1},\ 0.5,\ 0]$ verir. İki sonuç da hesapla doğrulandı.

## 9. Periyodiklik ve Temel Periyot

### 9.1 $x(t) = \cos(t + \pi/4)$

Bu işaretin temel periyodu ve periyodik olup olmadığı soruluyor. $\cos(\omega t + \dots)$ biçimine bakınca doğrudan $\omega = 1$ okunur. $f$ üzerinden gitmeye gerek yoktur: $f = 1/(2\pi)$, $T = 1/f = 2\pi$. Hoca sınıfa sordu, ilk cevap $1/(2\pi)$ oldu, sonra $2\pi$ söylendi.

Hoca burada çok kişinin hata yaptığı için bu soruyu koyduğunu belirtti ve bir ölçüt verdi: "Periyot rasyonel bir sayıysa işaret periyodiktir."

**Soru:** Bu işaret periyodik değil, çünkü $\pi$ rasyonel bir sayı mı bilmiyorum. **Cevap:** Hoca $\pi$'nin $22/7$ olduğunu, dolayısıyla rasyonel olduğunu söyledi. İrrasyonel olması için $\sqrt{2}$, $\sqrt{3}$ gibi bir şey gerektiğini ekledi. Sonra kosinüs işaretlerinin zaten kendi doğası gereği periyodik olduğunu belirtti.

> **Ders sonrası not:** Sonuç doğrudur, gerekçe yanlıştır. Hoca "$\pi = 22/7$, rasyoneldir" dedi. $\pi \approx 3.14159$, $22/7 \approx 3.14286$'dır (fark hesapla yaklaşık $0.00126$), yani $22/7$ yalnız yaklaşık değerdir. $\pi$ irrasyoneldir. "Periyot rasyonelse periyodiktir" ölçütü de yanlıştır: $T = 2\pi$ rasyonel değildir ve işaret yine periyodiktir. Sürekli zamanda tek bir sinüzoid $\omega \ne 0$ için her zaman periyodiktir. Rasyonellik, 9.2'deki gibi bileşenlerin periyotlarının oranında aranır.

### 9.2 $x(t) = \cos(\frac{\pi}{3} t) + \sin(\frac{\pi}{4} t)$

Birden fazla bileşen varsa her biri ayrı incelenir. Hoca sordu: Birden fazla frekans bileşeni olan işaretin temel frekansı nasıl bulunuyordu?

**Soru:** EKOK ile miydi? **Cevap:** Temel frekans EBOB ile, temel periyot tersine EKOK ile bulunur.

$$f_0 = \mathrm{EBOB}(f_1, f_2, \dots, f_n), \qquad T_0 = \mathrm{EKOK}(T_1, T_2, \dots, T_n)$$

İki yol da olur: Ya $f_0$ bulunup $T_0 = 1/f_0$ denir ya da doğrudan periyotların EKOK'u alınır. Burada:

$$T_1 = \frac{2\pi}{\pi/3} = 6, \qquad T_2 = \frac{2\pi}{\pi/4} = 8, \qquad T_0 = \mathrm{EKOK}(6, 8) = 24$$

Hoca bunu matematikteki bir soru tarzına benzetti: Dairesel pistte biri 6, öbürü 8 ile koşan iki koşucu başlangıç noktasında ilk ne zaman buluşur? Burada da dairesel bir durum vardır.

**Soru:** Periyodik mi? Periyot 24 çıktığı için mi? **Cevap:** Periyodik, ama ölçüt 24 değildir. Bileşenler oranlanır: $6/8$ veya $8/6$ rasyonel olduğu için işaret periyodiktir.

Hesapla denetlendi: $x(t + 24) = x(t)$ sağlanır, $x(t + 12) \ne x(t)$'dir.

> **Ders sonrası not:** Koşucu benzetmesinde 6 ve 8 "hız" gibi söylendi. Örneğe uyan okuma, bunların bir tur süresi olmasıdır, çünkü burada EKOK'u alınan büyüklükler periyotlardır.

### 9.3 Ayrık İşaret: $x[n] = e^{j\pi n/4}$

Hoca ayrık zamanda büyük omega kullanıldığını hatırlattı: $\Omega$ ayrık, $\omega$ sürekli zaman içindir. Periyot için ayrık zamanda $N_0$ daha doğrudur, ama $T_0$ da görülebilir.

Hoca önce sembolü "$\Omega_0 = 1/4$" diye okudu ve periyoda 4 dedi. Sonra işareti düzelterek $e^{j\pi n/4}$ olarak yazdı ve bileşenlerine ayırdı: $\cos(\frac{\pi}{4} n)$ ve $\sin(\frac{\pi}{4} n)$. İki bileşenin de açısal frekansı $\pi/4$'tür, yani çakışıktır. Sonra $\Omega_0 = 2\pi f$ üzerinden gitti: $\pi/4 = 2\pi f$, $f = 1/8$, periyot 8.

<!-- BELİRSİZ: Slayttaki işaretin ilk biçimi altyazıda net değil. Hoca önce "bir bölü dört n" okudu, sonra "şurası güzel olmamış" diyerek pi/4 n yazdı. -->

> **Ders sonrası not:** Derste ara adımlarda "4", "$8\pi$" ve "$N_0 = 1/8$" geçti, ayrıca açılımda $j$ söylenmedi. Doğrusu $e^{j\pi n/4} = \cos(\frac{\pi}{4} n) + j\sin(\frac{\pi}{4} n)$ ve $N_0 = \frac{2\pi}{\pi/4} = 8$'dir. Hesapla en küçük tam sayı periyot 8 çıktı. Periyot $1/\Omega_0$ ile bulunmaz. Ayrıca ayrık zamanda "periyot rasyonel" ölçütü de yeterli değildir: $x[n + N] = x[n]$ için $\Omega_0 N = 2\pi k$ olmalı ve $N$ tam sayı çıkmalıdır, yani $\Omega_0 / 2\pi$ rasyonel olmalıdır.

### 9.4 $x(t) = \cos t + \sin(\sqrt{2}\, t)$

$$T_1 = \frac{2\pi}{1} = 2\pi, \qquad T_2 = \frac{2\pi}{\sqrt{2}} = \sqrt{2}\,\pi$$

Periyotların oranına bakılır:

$$\frac{T_1}{T_2} = \frac{2\pi}{\sqrt{2}\,\pi} = \frac{2}{\sqrt{2}} = \sqrt{2}$$

$\sqrt{2}$ rasyonel olmadığı için işaret periyodik değildir.

> **Ders sonrası not:** Hoca burada "temel periyodu LCM yapıp bulabilirsiniz" diye de söyledi. Oran irrasyonelse ortak kat yoktur, bu yüzden bu işaretin temel periyodu da yoktur.

> **Hocanın vurgusu:** $\omega = 2\pi f$, $f = 1/T$ gibi basit formüller hızlıca aklınızda olursa bu sorular hızlıca çözülür.

## 10. Enerji ve Güç İşaretleri

### 10.1 $x(t) = e^{-at} u(t)$, $a > 0$

Enerji formülü, işaretin genliğinin karesinin eksi sonsuzdan artı sonsuza integralidir. $u(t)$ yüzünden integral 0'dan başlar:

$$E = \int_{-\infty}^{\infty} |x(t)|^2\, dt = \int_0^{\infty} e^{-2at}\, dt = \frac{e^{-2at}}{-2a} \Bigg|_0^{\infty}$$

$t \to \infty$ iken $e^{-\infty} = 1/e^{\infty} = 0$ olur. $t = 0$'da $e^0 = 1$ gelir. Sonuç:

$$E = 0 - \left( -\frac{1}{2a} \right) = \frac{1}{2a}$$

$a > 0$ olduğu için bu değer sonsuzdan küçüktür, yani bu bir enerji işaretidir. Sonsuza gitseydi enerji işareti diyemezdik. $a = 0.5, 1, 2$ için sayısal integral aynı sonucu verdi.

### 10.2 $x(t) = t\, u(t)$

Bu sefer enerji limitli biçimde yazılır:

$$E = \lim_{T \to \infty} \int_{-T/2}^{T/2} |x(t)|^2\, dt$$

$-T/2$'den 0'a kadar olan kısım $u(t)$ yüzünden etkisizdir. Kalan:

$$E = \lim_{T \to \infty} \int_0^{T/2} t^2\, dt = \lim_{T \to \infty} \frac{(T/2)^3}{3} = \lim_{T \to \infty} \frac{T^3}{24} = \infty$$

Yani enerji işareti değildir. Güç için bir periyot boyunca ortalama alınır:

$$P = \lim_{T \to \infty} \frac{1}{T} \int_0^{T/2} t^2\, dt = \lim_{T \to \infty} \frac{T^2}{24} = \infty \quad \text{(ara adım eklendi)}$$

Bu da sonsuz olduğu için işaret güç işareti de değildir. Sonuç: **Ne enerji ne de güç işaretidir.**

> **Ders sonrası not:** Hoca burada limitte belirsizlik çıktığını söyleyip türev aldı. $T^3/24$ ifadesinde belirsizlik yoktur, limit doğrudan sonsuzdur. Hoca ayrıca işarete "periyodik gibi" dedi. $t\,u(t)$ periyodik değildir. Formüldeki $T$ yalnız integral penceresinin uzunluğudur.

## 11. Basamak, Darbe ve İşaret Fonksiyonlarıyla İşlemler

### 11.1 Sürekli Zamanda Çarpma

Bir $x(t)$ işareti veriliyor ve şu işlemlerin sonucu isteniyor. Önce ikinci çarpanın ne olduğunu tespit etmek gerekir.

<!-- BELİRSİZ: x(t) grafiği slaytta. Altyazıdan yalnız x(3/2) = 2 değeri ve t = 1 noktasının önemi anlaşılıyor. Kare yok. -->

**1. $x(t)\, \delta(t - 3/2)$.** Dirac delta $t = 3/2$ noktasında vardır, diğer yerlerde sıfırdır. Çarpım, işaretin o noktadaki değerini örnekler. Bu noktadaki değer 2 olduğu için sonuç $t = 3/2$'de tek bir darbedir: $2\,\delta(t - 3/2)$.

**2. $x(t)\, u(1 - t)$.** $u(t)$ sağa doğru gider. $u(-t)$ tersine, sola doğru gider. Bir birim geri alınınca $u(1 - t)$ olur ve $t = 1$'den geriye doğru 1 değerini alır. Bu yüzden $x(t)$ ile çarpım, 1'den geriye doğru olan değerleri bırakır, diğerlerini yok eder.

**3. $x(t) [u(t) - u(t - 1)]$.** $u(t)$'den $u(t - 1)$ çıkarılınca yalnız 0-1 aralığı kalır. Hoca bunu belli aralığı geçiren bir filtreye benzetti. Çarpım, $x(t)$'nin 0-1 aralığındaki kısmını alır, diğerlerini sıfırlar.

### 11.2 Ayrık Zamanda Çarpma

Aynı işlemler ayrık zamanda da yapıldı.

<!-- BELİRSİZ: Bu x[n] slaytta. Altyazıdan x[-3] = 3, x[-2] = 2, x[-1] = 1 okunuyor. x[0] ve x[1] değerleri net değil. Kare yok. -->

**a) $x[n]\, u[1 - n]$.** $u[1 - n]$, $n \le 1$ için 1'dir, $n = 1$ noktası da dahildir. Sonuçta $n \le 1$ örnekleri aynen kalır.

**b) $x[n] (u[n + 2] - u[n])$.** $u[n + 2]$ eksi 2'den başlar. $u[n]$ çıkarılınca yalnız eksi 2 ve eksi 1 noktaları kalır. Bu örneklerin değerleri 2 ve 1'dir, kalanlar atılır.

**c) $x[n]\, \delta[n - 1]$.** Bu, işareti örneklemek demektir: $n = 1$ noktasındaki değer alınır, sonuç o noktada tek bir örnektir.

### 11.3 $x(t) = u(t) - u(t - a)$ ve Türevi

$a$ pozitif verilmiştir. $u(t)$ sıfırdan başlar, $u(t - a)$ ise $a$ noktasından itibaren başlar. Biri öbüründen çıkarılınca yalnız $0 \le t < a$ aralığı kalır: Yüksekliği 1 olan bir dikdörtgen.

Türev terim terim alınır:

$$x'(t) = u'(t) - u'(t - a) = \delta(t) - \delta(t - a)$$

$u(t)$ sabit gider ve yalnız sıçradığı noktada türevi bir darbe verir. $t = a$'daki terim negatif olduğu için orada aşağı yönlü bir darbe vardır. Hocanın yorumu: İşaret belli bir değerde sabit gidiyor, sonra bir anda sıfıra iniyor. Bu ani değişim türevde darbe olarak görünür.

> **Ders sonrası not:** Hoca "$u(t - a)$'nın türevi, $a$ kadar ötelenmiş delta fonksiyonunun türevini gösterir" dedi. Doğrusu, $u(t - a)$'nın türevi $a$ kadar ötelenmiş delta fonksiyonunun kendisidir: $\delta(t - a)$. Hocanın çizimi de budur. "Sabitin türevi tek bir noktaya karşı gelir" ifadesi de düzeltilmelidir: Sabit kısımların türevi sıfırdır, darbe yalnız sıçrama noktasından gelir.

### 11.4 $\mathrm{sgn}(t)$'nin Türevi

$\frac{d}{dt}\mathrm{sgn}(t) = 2\delta(t)$ eşitliği hoca tarafından şöyle gösterildi. İşaret fonksiyonu iki basamakla yazılır:

$$\mathrm{sgn}(t) = u(t) - u(-t)$$

$u(t)$ sağ tarafı $+1$, $-u(-t)$ sol tarafı $-1$ yapar. Türev alınırsa $u(t)$'den $\delta(t)$ gelir. $u(-t)$'den ise $\delta(-t)$ gelir. Zaman ters çevirmesinden dolayı bir eksi daha çıkar ve önündeki eksiyle birleşip artıya döner:

$$\frac{d}{dt}\mathrm{sgn}(t) = \delta(t) + \delta(-t) = 2\delta(t)$$

Darbe sıfır noktasında olduğu için ters çevrilince yeri değişmez, yani $\delta(-t) = \delta(t)$'dir.

## 12. Sistem Özellikleri: İki Tam Çözüm

### 12.1 Modülatör: $y(t) = x(t) \cos(\omega_0 t)$

Blok şemada geri besleme yoktur. Çıkış, $x(t)$ ile $\cos(\omega_0 t)$'nin çarpımıdır. Buna modülatör demiştik.

**Bellek.** Bellekli olmak, sistemin şu anki değer dışında başka değerlere ihtiyaç duymasıdır. Burada yalnız şu anki $t$ kullanılır. Sistem belleksizdir.

**Nedensellik.** Şu anki ve önceki değerlere bağlıysa sistem nedenseldir. Şu anki $t$'ye bağlı olması yeterlidir, illa $t - 1$ olması gerekmez. Sistem nedenseldir.

**BIBO kararlılık.** Sınırlı girişe karşılık sınırlı çıkış gelir mi? Kosinüs $-1$ ile $+1$ arasında değer alır, yani bir ölçekleme değeridir ve $x(t)$'yi en fazla kendisine eşit bırakır:

$$|y(t)| = |x(t)\cos(\omega_0 t)| \le |x(t)| < \infty$$

Girişte sonsuzdan küçük bir değer varsa çıkışta da sonsuzdan küçük bir değer vardır. Sistem BIBO (bounded input, bounded output) kararlıdır.

**Doğrusallık.** Hem çarpımsallık hem toplamsallık sağlanmalıdır.

- Çarpımsallık: Girişe $a\, x(t)$ verilirse çıkış $a\, x(t) \cos(\omega_0 t)$ olur. $a\, y(t)$ de aynıdır. Sağlanır.
- Toplamsallık: Girişe $x_1(t) + x_2(t)$ verilirse çıkış $[x_1(t) + x_2(t)] \cos(\omega_0 t)$ olur. Ayrı ayrı verilip toplanırsa $x_1(t)\cos(\omega_0 t) + x_2(t)\cos(\omega_0 t)$ olur. Açılınca ikisi aynıdır. Sağlanır.

Sistem doğrusaldır. Görünüşte $y = a x$ gibi bir fonksiyondur.

**Soru:** $t$'ye niye katsayı getirmedik de $x(t)$'ye getirdik? **Cevap:** Sistem $t$'ye değil $x$'e bağlıdır. $x$ de ayrıca $t$'ye bağlıdır. Sistemin girişi $t$ değil $x$'tir. $t$ yalnız bağımsız zaman parametresidir.

**Soru:** Kosinüse niye katsayı vermedik? **Cevap:** Verilen sistem kosinüse bağlı bir şey değildir. $\cos(\omega_0 t)$ bir çarpandır, $x(t) \cdot 5$ demekle arasında bu açıdan fark yoktur. Yalnız bu çarpan zamanla değişir. Bu girişte olan bir değişim değildir.

**Zamanla değişmezlik.** Hoca sınıfa sordu. Bir öğrenci "zamanla değişir, çünkü $x$ $t$'ye bağlı, $x$ değişince $y$ de değişir" dedi. Hoca sonucun doğru, gerekçenin yanlış olduğunu söyledi. Şart şudur: Girişte yapılan öteleme, çıkışta yapılan aynı ötelemeyle aynı sonucu vermelidir.

- Çıkışı ötelemek: Çıkıştaki her $t$ yerine $t - t_0$ yazılır: $y(t - t_0) = x(t - t_0) \cos(\omega_0 (t - t_0))$.
- Girişi ötelemek: Yalnız giriş değişir, sistemdeki kosinüs değişmez: $x(t - t_0) \cos(\omega_0 t)$.

İkisi eşit olmadığı için sistem zamanla değişir (time variant).

> **Ders sonrası not:** Hoca $\cos(\omega_0 t)$ için "sabit bir sayı, ölçekleme katsayısı" dedi. Bu çarpan girişe bağlı değildir ve doğrusallık testinde $x(t)$ gibi ölçeklenmez, hocanın anlatmak istediği budur. Ama sabit değildir, zamanla değişen bir kazançtır. Sistemin zamanla değişmesinin sebebi de tam olarak budur.

### 12.2 $y[n] = n\, x[n]$

**Bellek ve nedensellik.** Yalnız $n$'e bağlı terim vardır, $n + 1$ veya $n - 1$ yoktur. Sistem belleksizdir. Şu anki duruma bağlı olduğu için nedenseldir.

**Zamanla değişmezlik.** Çıkışı ötelemek $(n - n_0)\, x[n - n_0]$ verir. Girişi ötelemek $n\, x[n - n_0]$ verir, çünkü öteleme baştaki $n$'i etkilemez. Eşit olmadıkları için sistem zamanla değişir.

**BIBO kararlılık.** Hoca bunun yanıltıcı olduğunu söyledi. Bir öğrenci kararsız olduğunu, çünkü $n$ sonsuza giderken büyüdüğünü söyledi. Hoca sonucu doğru buldu, ama "bellek sonsuz değil" diyerek gerekçeyi programlamadaki taşmaya bağladı: Bir sayı $n$ ile çarpılınca integer boyutunu aşabilir, sınırı aşan sonuç "not a number" durumuna düşer ve sonsuz gibi davranır. Bu yüzden sistem kararsızdır.

> **Ders sonrası not:** Kararsızlığın gerekçesi bellek taşması değildir, öğrencinin ilk söylediği gerekçe doğru yöndedir. Sınırlı bir giriş seçilir, örneğin her $n$ için $x[n] = 1$. Çıkış $y[n] = n$ olur ve $n \to \infty$ iken sınırsız büyür. BIBO tanımı matematikseldir, bilgisayar belleğine bağlı değildir. Ayrıca taşma büyük olasılıkla "not a number" ile aynı şey değildir: NaN kayan noktalı sayılara ait bir değerdir, integer taşmasından çıkmaz.

**Doğrusallık.** Hoca önce çarpımsallığın kontrol edilmesini tavsiye etti.

- Çarpımsallık: $a\, y[n] = a\, n\, x[n]$. Girişe $a\, x[n]$ verilince $n\, a\, x[n]$ gelir. Eşittir.
- Toplamsallık: $n (x_1[n] + x_2[n]) = n\, x_1[n] + n\, x_2[n]$. Eşittir.

Sistem doğrusaldır.

## 13. Tek ve Çift Bileşenlere Ayırma

Çift olmak $g[n] = g[-n]$ demektir. O yüzden $g[n]$ ile $g[-n]$ toplanıp ikiye bölünürse çift işarette hiçbir şey değişmez. Tek olmak $g[n] = -g[-n]$ demektir. Bu kez farkı alıp ikiye böleriz. Bileşen formülleri budur:

$$g_e[n] = \frac{g[n] + g[-n]}{2}, \qquad g_o[n] = \frac{g[n] - g[-n]}{2}$$

Soru, şu işaretin bileşenlerini istiyor:

$$g[n] = \sin\!\left( \frac{2\pi n}{7} \right) (1 + n^2)$$

<!-- BELİRSİZ: Altyazıda hoca işareti sürekli "sinüs 2 pi n bölü 7 çarpı 1 artı n kare" diye okuyor. Bir yerde "artı 1 bölü n kare" da geçiyor. Slayt görülemedi. Çarpım okuması tercih edildi; 1 + n^2 paydada olsaydı da çift olduğu için sonuç aynı kalırdı (hesapla denetlendi). -->

$g[-n]$ yazarken dikkat: Sinüsün içine $-n$, parantezin içine $(-n)^2$ gelir.

$$g[-n] = \sin\!\left( -\frac{2\pi n}{7} \right) (1 + (-n)^2) = -\sin\!\left( \frac{2\pi n}{7} \right) (1 + n^2) = -g[n]$$

Sinüs tek fonksiyondur, $\sin(-a) = -\sin a$. $1 + n^2$ ise çifttir, $(-n)^2 = n^2$. Buradan:

$$g_e[n] = \frac{g[n] - g[n]}{2} = 0, \qquad g_o[n] = \frac{g[n] + g[n]}{2} = g[n]$$

Çift bileşen yoktur. Tek bileşen işaretin kendisidir. Bu normaldir, çünkü işaretin kendisi tektir. Hesapla $n = -20, \dots, 20$ için doğrulandı.

> **Hocanın vurgusu:** Bazıları $\sin(2\pi n)$'nin her zaman sıfır olduğu gibi düşünüp hemen sıfır yazıyor. Burada paydada 7 vardır, bu yüzden açı $2\pi$'nin katı değildir ve ifade sıfır olmaz.

Hoca, geçen dönem bu soru tipinin parçalı bir grafikle sorulduğunu da hatırlattı: Bir grafik verilir, $g(-t)$ çizilir ve aynı toplama-çıkarma işlemi her aralık için ayrı ayrı yapılır.

## 14. Konvolüsyon Tekrarı

### 14.1 Sabit Sayıyla Konvolüsyon

Hoca konvolüsyona geçerken quizde zorlayıcı olmuş olabilecek bir noktayı açıkladı. Bir seçenekte $A$ ile $\cos$ arasında yıldız işareti vardı. $A$ tek elemanlı, sabit bir sayı olduğu için çarpma ile konvolüsyon burada aynıdır. Örneğin 1, 1, 1 işaretini 3 ile konvolüsyon yapmak ne demektir? 3 ile çarparsınız, 3 çıkar, kaydırırsınız, yine 3 ile çarparsınız, yine 3 çıkar. Yani çarpmanın aynısıdır.

> **Hocanın vurgusu:** Sabit bir sayıyla konvolüsyon, o sayıyla çarpmakla aynıdır. İki taraf da vektör, yani işaretse iş farklılaşır: Çarpma ile konvolüsyon birbirine eşit çıkmaz.

> **Ders sonrası not:** Hesapla `[3] * [1, 1, 1] = [3, 3, 3]` çıktı. Burada "sabit sayı", tek elemanlı dizi yani $3\,\delta[n]$ anlamındadır. Her $n$'de 3 olan sabit bir işaret kastedilmez.

### 14.2 Tanım

Konvolüsyon, iki fonksiyon üzerinde tanımlanan bir işlemdir. Bir sinyal tersine alınır, belli miktar ötelenir, diğer sinyalle çarpılıp toplanır. Sinyalin bir ucundan başlayıp olası bütün değerler çarpılıp toplanır. Hoca bunu benzerlik, korelasyon işlemi diye de yorumladı.

$$(f * g)(t) = \int_{-\infty}^{\infty} f(\tau)\, g(t - \tau)\, d\tau$$

İşaretler yalnız pozitif zamanda tanımlıysa sınırlar 0 ile $t$ olur. Öteleme iki işaretten herhangi birine uygulanabilir. Küçük fonksiyona uygulamak işlemi kısaltır.

> **Ders sonrası not:** Konvolüsyonun korelasyonla aynı şey olduğu düşünülmemelidir: Konvolüsyonda işaret ters çevrilir, korelasyonda çevrilmez. 14.4'teki dikdörtgen simetrik olduğu için iki işlem aynı biçimi verir. Genelde sonuçlar büyük olasılıkla farklıdır.

### 14.3 Sürekli Örnek: $t * t^2$

$f(t) = t$, $g(t) = t^2$ ve ikisi de yalnız $t \ge 0$ için tanımlı. Öteleme küçük olan $f$'ye uygulanır:

$$(f * g)(t) = \int_0^t (t - \tau)\, \tau^2\, d\tau$$

$\tau^2$ içeri dağıtılır:

$$= \int_0^t \left( t\tau^2 - \tau^3 \right) d\tau = \left[ t\frac{\tau^3}{3} - \frac{\tau^4}{4} \right]_0^t = \frac{t^4}{3} - \frac{t^4}{4} = \frac{4t^4 - 3t^4}{12} = \frac{t^4}{12}$$

Sonuç dördüncü dereceden bir işarettir. $t = 0.5, 1, 1.8, 2.5$ için sayısal integral bu sonucu verdi.

Hoca bunu sistem gözüyle yorumladı: $g(t)$ sistemimizse ve $f(t)$ sisteme verdiğimiz girişse, sistemin herhangi bir $t$ anındaki çıkışı bu grafikten okunur. Fonksiyon bu kadar temiz ve düzenliyse işlem kolaydır. İşi zorlaştıran, fonksiyonun parçalı olması veya integralin zor olmasıdır.

### 14.4 Sürekli Örnek: İki Dikdörtgen

Bu kez $x(t)$ ve $y(t)$ aynıdır: 0 ile 1 arasında 1, başka yerde 0. Hoca bu örneği, sonucun tek noktada pik yapacağını ve en yüksek benzerliğin orada görüleceğini göstermek için seçti.

$$f(t) = x(t) * y(t) = \int_{-\infty}^{\infty} x(\tau)\, y(t - \tau)\, d\tau$$

Eksenini değiştireceğimiz işaret $y$ olsun. $y(-\tau)$, $\tau$ ekseninde $y$'nin ters çevrilmişidir. Bunu $t$ kadar ötelersek $y(t - \tau)$ elde edilir: Sağ kenarı $\tau = t$, sol kenarı $\tau = t - 1$ noktasındadır. İşlev parçalı olduğu için bölgeler ayrı ayrı incelenir:

- **$t < 0$:** $x$ ile $y$ arasında örtüşme yoktur. $f(t) = 0$.
- **$0 \le t < 1$:** $y$ belli bir noktaya kadar gelmiştir, bir kısmı hâlâ dışarıdadır. İki işaret de örtüşme bölgesinde 1'dir ve bu bölge 0 ile $t$ arasıdır: $f(t) = \int_0^t 1 \cdot 1\, d\tau = t$.
- **$1 \le t < 2$:** Sol kenar $t - 1$ noktasındadır ve örtüşme, 1 noktasına kadar sürer: $f(t) = \int_{t-1}^{1} 1 \cdot 1\, d\tau = 1 - (t - 1) = 2 - t$.
- **$t \ge 2$:** Örtüşme biter. $f(t) = 0$.

Bunlar birleştirilince üçgen elde edilir: 0'dan 1'e $t$ kadar yükselir, $t = 1$'de tepe yapar, sonra aynı şekilde 2'ye kadar azalır. Tepe noktası, iki sinyalin tam örtüştüğü andır, yani en yüksek benzerlik buradadır. Sayısal konvolüsyon $t = 0.5, 1, 1.5, 2, 2.5$ noktalarında yaklaşık $0.5, 1, 0.5, 0, 0$ verdi.

Hocaya göre işlem aslında kolaydır, integralin parçalı olması işi bazı durumlarda zorlaştırır. Bu sonuçla da girişi $x(t)$, sistemi $y(t)$ olan bir sistemin istenen andaki çıkışı hesaplanabilir.

### 14.5 Ayrık Örnek: $[1,1,1,1] * [1,1,1]$

İki işaret de $n = 0$'dan başlar: $x[n] = [1, 1, 1, 1]$, $y[n] = [1, 1, 1]$. Hoca aynı sonucu iki yoldan buldu.

**Birinci yol: Kaydırarak.** Küçük olan ters çevrilir ve her adımda bir kaydırılır. Örtüşen örnekler çarpılıp toplanır:

| $n$ | Örtüşen örnek sayısı | Sonuç |
|:---:|:---:|:---:|
| 0 | 1 | 1 |
| 1 | 2 | 2 |
| 2 | 3 | 3 |
| 3 | 3 | 3 |
| 4 | 2 | 2 |
| 5 | 1 | 1 |

Sonrası sıfırdır. Sonuç $[1, 2, 3, 3, 2, 1]$. Hoca adım adım gösterilmesi istendiğinde tek tek yazılması gerektiğini söyledi.

> **Ders sonrası not:** Altyazıda bir yerde "1, 2, 3, 3, 3, 3, 3, 2, 1" geçiyor. Doğru sonuç 6 örnektir: $[1, 2, 3, 3, 2, 1]$. Hesapla ve iki yolla da doğrulandı.

**İkinci yol: Dağılma özelliği.** İşaretler birim darbeler cinsinden yazılır:

$$x[n] = \delta[n] + \delta[n-1] + \delta[n-2] + \delta[n-3]$$

$$y[n] = \delta[n] + \delta[n-1] + \delta[n-2]$$

Katsayılar 1 olduğu için hepsinin başında 1 vardır. Değer 2 olsaydı başına 2 gelirdi. Hoca bu ayrık işaret yazımını "birim basamak" diye de andı, doğrusu "birim darbe"dir.

Konvolüsyonun dağılma özelliği gereği $y[n]$ parantezin içine dağıtılır:

$$y[n] * x[n] = y[n] * \delta[n] + y[n] * \delta[n-1] + y[n] * \delta[n-2] + y[n] * \delta[n-3]$$

Delta fonksiyonunun özelliği hatırlatılırken şu soru geçti.

**Soru:** Delta hangi noktada örnek alır, yanına yazılan sayıda mı? Örneğin $\delta[-2]$ ise 2 noktasında mı? **Cevap:** Hayır. $\delta[n]$, $n = 0$ noktasında çalışır. $\delta[-2]$ doğrudan sıfırdır. $\delta[n - 2]$ olursa dediğiniz olur: 2 birim ötelenmiştir ve $n = 2$'de 1'dir.

Her terim $y[n]$'nin ötelenmiş halini verir:

$$y[n] * x[n] = y[n] + y[n-1] + y[n-2] + y[n-3]$$

> **Ders sonrası not:** Hoca bunu "$\delta$ ile konvolüsyonda yalnız o noktadaki değer alınır, diğerleri sıfır olur" diye anlattı. Bu, $\delta$ ile **çarpmanın** özelliğidir (11. bölüm). Konvolüsyonda işaretin tamamı ötelenir: $y[n] * \delta[n - k] = y[n - k]$. Hocanın yazdığı formül de budur, sonuç doğrudur.

Şimdi her terim açılır. $y[n-1]$, bütün $\delta$'ları bir birim öteler:

$$y[n] = \delta[n] + \delta[n-1] + \delta[n-2]$$

$$y[n-1] = \delta[n-1] + \delta[n-2] + \delta[n-3]$$

$$y[n-2] = \delta[n-2] + \delta[n-3] + \delta[n-4]$$

$$y[n-3] = \delta[n-3] + \delta[n-4] + \delta[n-5]$$

Ortak terimler toplanır. $\delta[n]$'den 1, $\delta[n-1]$'den 2, $\delta[n-2]$'den 3, $\delta[n-3]$'den 3, $\delta[n-4]$'den 2, $\delta[n-5]$'den 1 tane vardır:

$$h[n] = \delta[n] + 2\delta[n-1] + 3\delta[n-2] + 3\delta[n-3] + 2\delta[n-4] + \delta[n-5]$$

Bu, yine bir ayrık işaretin delta fonksiyonları cinsinden yazılışıdır. Değerleri 1, 2, 3, 3, 2, 1'dir, hoca bunları ikişer ikişer "on iki, otuz üç, yirmi bir" diye karşılaştırdı. Birinci yol daha algoritmik bir yöntemdir, ikincisi analitik olarak sonuca ulaşmanın yoludur.

## 15. Quiz Sorularının Çözümü

<!-- BELİRSİZ: Seçenek metinleri slaytta. Burada yalnız hocanın okuduğu kadarıyla aktarılıyor; bazı seçeneklerin tam formülü altyazıdan okunamıyor. Kare yok. -->

### 15.1 Birinci Soru: $x[n] = A\cos(\Omega_0 n + \theta)$

Hangi ifade yanlıştır?

- **A:** İşaret ayrık zamanlı ve periyodiktir. Hoca doğru saydı.
- **B ve C:** Karmaşık üstel gösterimle ilgili seçeneklerdir. $e^{j(\Omega_0 n + \theta)}$ açıldığında reel kısım kosinüs bileşenini verir. 90 derece faz farkı uygulanırsa kosinüsten sinüse gidilir ve sanal kısım gelir. Fikir doğrudur, ama hoca soruyu yazarken $j$'yi parantezin dışına yazması gerektiğini, yazım hatası yaptığını söyledi.
- **D:** $\Omega_0 = 500$ için $T_0 = 1/250$. Bu yanlıştır, sorunun cevabıdır. Hocanın hesabı: $2\pi f = 500$, $f = 250/\pi$, $T = \pi/250$.
- **E:** $\theta = -90^\circ$ için işaret $A\sin(\Omega_0 n)$ olur. Doğrudur. Hoca bu seçeneğin çok işaretlendiğini söyledi ve açılımı gösterdi:

$$\cos(a - b) = \cos a \cos b + \sin a \sin b$$

$b = 90^\circ$ için $\cos 90^\circ = 0$, $\sin 90^\circ = 1$ olduğundan $\cos(a - 90^\circ) = \sin a$ olur. Dışarıdaki genliğin bunda hiçbir önemi yoktur.

> **Hocanın vurgusu:** $\cos(a - b)$ açılımını ve $e^{-j\theta}$ dönüşümünü bilmek gerekir.

> **Ders sonrası not:** Hocanın $T = \pi/250$ hesabı sürekli zaman mantığıdır. Ayrık zamanda $\Omega_0 = 500$ için $\Omega_0 / 2\pi = 250/\pi$ rasyonel olmadığından bu işaret periyodik olmaz. D seçeneğinin yanlış olduğu sonucu değişmez, ama A seçeneği ancak $\Omega_0 / 2\pi$ rasyonelse doğrudur.

### 15.2 İkinci Soru

Hangi ifade doğrudur?

- **A:** $x[n + n_1]$, $n_1 > 0$ ise gecikme yapar. Yanlıştır. Hoca önce doğru dedi, hemen düzeltti: Bu öne almadır (advance).
- **B:** Görüntüdeki bir pikselin bit sayısı örnekleme frekansıyla belirlenir. Yanlıştır. Bit sayısı, nicemleme seviye sayısıyla (number of quantization levels) ilgilidir.
- **C:** İki farklı kanaldan kaydedilmiş ses işareti arasındaki faz farkını gidermek ve hizalamak için işaretlerden birinde $n$ düzleminde öteleme yapılır. **Doğrudur, cevap budur.** Biri sinüs, biri kosinüs gibi hizasız işaretlere öteleme uygulanabilir.
- **D:** Örnek sayısını iki katına çıkarmak için $x[n/2]$ yapılabilir ve böylece ses kalitesi kesinlikle artar. İlk kısım doğrudur, örnek sayısı artar. "Kesinlikle" kısmı yanlıştır. Örnekler kopyalanırsa 1, 1, 5, 5 dizisi 1, 1, 1, 1, 5, 5, 5, 5 olur ve kalite azalabilir. İyi bir ara değerleme (interpolasyon) gerekir: 1'den 5'e geçişte komşu örneklerin durumuna bakılır, belki kuadratik veya kübik spline kullanılır. Kötü bir interpolasyon çoğu zaman kaliteyi düşürür.
- **E:** Analog işareti sayısala çevirirken örnekleme frekansı için nicemleme seviyesi dikkate alınır. Yanlıştır. $f_s$ için $2 f_{max}$ değerine bakılır.

> **Ek bilgi (derste anlatılmadı):** Bit sayısı ile seviye sayısı arasındaki ilişki büyük olasılıkla $L = 2^b$ biçimindedir: $b$ bit ile $L$ farklı nicemleme seviyesi gösterilir. Bu yüzden pikselin bit sayısı örnekleme frekansından değil seviye sayısından gelir. Örnekleme frekansı ise görüntüde kaç piksel olduğuyla ilgilidir.

### 15.3 Üçüncü Soru

Hangi ifade yanlıştır?

- $u[n] - u[n-1] = \delta[n]$: Doğrudur. Çıkarınca yalnız sıfır noktasında bir darbe kalır.
- $z[n] = \sum_k z[k]\, \delta[n - k]$: Doğrudur. İşaret, her $k$ noktasındaki değeri ile ötelenmiş darbelerin toplamıdır. Slaytlarda vardı.
- Bir $t$ noktasındaki tek değer alınacaksa toplam, o noktanın değerine iner. Doğrudur.
- $e^{jt}$'nin çift bileşeni $\cos t$'dir. Doğrudur.
- $e^{-t}\cos(2\pi t)$ işaretinin sonsuzdaki değeri sonsuzdur. **Yanlıştır, cevap budur.** $e^{-\infty} = 1/e^{\infty}$ sıfıra gider, sonsuzdaki değer 0'dır.

> **Ders sonrası not:** Hoca açılımı "$e^{jt} = \cos t - j\sin t$" diye söyledi. Doğrusu $e^{jt} = \cos t + j\sin t$'dir, eksi işareti $e^{-jt}$ içindir. Çift bileşen yine $\frac{e^{jt} + e^{-jt}}{2} = \cos t$ çıkar, sonuç sayısal olarak doğrulandı.

### 15.4 Dördüncü Soru

Hangi ifade yanlıştır?

- **A:** $a\,x(t)$ biçimindeki sistemde kazanç 1'den büyükse sistem kuvvetlendirici olarak çalışır. Doğrudur.
- **B:** Bir sistem bellekli ve nedensel değildir denilen seçenekte $n + 1$ terimi vardır. Sonraki zamana ihtiyaç duyduğu için hem belleklidir hem nedensel değildir. Doğrudur.
- **C:** Toplam biçimindeki bir sistem için nedensel ve bellekli denilmiş. Hoca sonucun $k = -\infty$'dan $n$'e kadar giden, $x[k]$ içeren bir toplam olmasını amaçladığını söyledi: Bu durumda $n - 1, n - 2, \dots$ değerleri kullanılır. Yazarken $k$ yerine $n$ yazdığı için ifade bozulmuştur.
- **D:** $|x| < K_1$ iken $|y| < K_2$ ise sistem kararlıdır. Doğrudur: Sınırlı girişe karşılık sınırlı çıkış.
- **E:** Doğrusallık, toplamsallık **veya** çarpımsallığın sağlanmasına bağlıdır. **Yanlıştır, cevap budur.** "Ve" olmalıdır. "Veya" denirse ikisinden yalnız birini sağlayan sistem de doğrusal sayılırdı.

### 15.5 Son Soru

Hoca bu sorunun seçeneklerini tek tek geçti:

- Sürekli zamanlı sistem doğrusal değildir, ancak nedenseldir, deniyor. Hoca aynı sistemin ayrık halinin az önce yapıldığını söyledi. Nedensellik vardır, ama sistem doğrusaldır. İfade yanlıştır. <!-- BELİRSİZ: Sistemin denklemi slaytta. "Ayrık zamanlı halini yapmıştık" ifadesinden büyük olasılıkla y(t) = t x(t). -->
- $\sin(n)\, \delta[n]$: $n = 0$ noktasında $\delta$ 1'dir, ama $\sin 0 = 0$'dır. Sonuç sıfırdır, ifade doğrudur.
- $\delta(t)$'nin sıfırı içermeyen bir aralıkta integrali: Darbe o aralığa düşmediği için bütün integraller sıfırdır.
- $x[n] = (0.5)^n u[n]$ işaretinin enerjisi:

$$E = \sum_{n=0}^{\infty} \left( (0.5)^n \right)^2 = \sum_{n=0}^{\infty} (0.25)^n = \frac{4}{3} \quad \text{(hesapla doğrulandı)}$$

Sonuç sonlu olduğu için bu bir enerji işaretidir.

## 16. Spektrumdan İşarete, Ses Örnekleri ve Temel Frekans

### 16.1 Bileşenlerden İşareti Yazmak

Hoca Fourier serileriyle ilgili ek PDF'e döndü. Bu kaynakta notasyon biraz farklıdır, $c_k$ yerine $a_k$ gibi yazımlar görülebilir. Amaç yine ayrıştırmadır. Spektrumda şu bileşenler verilmiş:

| Frekans (Hz) | $0$ | $100$ | $-100$ | $250$ | $-250$ |
|:---:|:---:|:---:|:---:|:---:|:---:|
| Bileşen | $10$ | $7e^{-j\pi/3}$ | $7e^{j\pi/3}$ | $4e^{j\pi/2}$ | $4e^{-j\pi/2}$ |

Elimizde genlik, faz ve frekans varsa işaret inşa edilebilir. Önce uzun biçimi yazılır:

$$x(t) = 10 + 7e^{-j\pi/3} e^{j2\pi 100 t} + 7e^{j\pi/3} e^{-j2\pi 100 t} + 4e^{j\pi/2} e^{j2\pi 250 t} + 4e^{-j\pi/2} e^{-j2\pi 250 t}$$

Sadeleştirirken şu eşitlik kullanılır. Her kosinüs, iki karmaşık üstelin toplamıdır:

$$A\cos(\omega t + \phi) = \frac{A}{2} e^{j\phi} e^{j\omega t} + \frac{A}{2} e^{-j\phi} e^{-j\omega t}$$

> **Hocanın vurgusu:** Bu eşitliği çok iyi bilmek gerekir.

Eşlenik çiftlerde $A/2 = 7$ ise $A = 14$, $A/2 = 4$ ise $A = 8$'dir. Sonuç:

$$x(t) = 10 + 14\cos\!\left( 2\pi \cdot 100\, t - \frac{\pi}{3} \right) + 8\cos\!\left( 2\pi \cdot 250\, t + \frac{\pi}{2} \right)$$

Üstel toplam ile bu sonuç sayısal olarak karşılaştırıldı, aynı çıktı.

> **Ders sonrası not:** Altyazıda bir yerde "17 çarpı kosinüs" geçiyor, doğrusu $2 \cdot 7 = 14$'tür. Hoca üstel biçimi ilk yazarken $+100$ Hz terimine $e^{j\pi/3}$ dedi, sonra düzeltti: $+100$ Hz terimi $e^{-j\pi/3}$'tür.

**Temel frekans.** Hoca sordu: Buranın temel frekansı kaçtır? Bileşenlerin EBOB'u alınır: $\mathrm{EBOB}(100, 250) = 50$. Temel frekans 100 değildir. 50 Hz'deki bileşenin genliği sıfırdır, o yüzden spektrumda görülmez, ama temel frekans yine $f_0 = 50$ Hz'dir. Temel periyot $T_0 = 1/50$ s'dir. Bu periyot hesapla doğrulandı.

### 16.2 Notalar, Konuşma ve Sentez

Hoca spektrumun nerede işe yaradığını birkaç örnekle anlattı.

- **Telefon tuşları:** Geçen konuşulduğu gibi her tuşa karşılık iki frekans bileşeni vardır.
- **Müzik:** Her notanın kendine ait frekansları vardır. Yatay eksen zamanı, yani hangi notanın basılacağını, dikey eksen frekansı gösterir. Piyanoda bir nota için kord, yani birden fazla ses kullanılır.
- **Konuşma:** Sesin periyodik gibi görünen bir bölümü vardır. Bir "a" sesinin bulunduğu yere bakılınca belirli bir karakteristik görülür. Otobüslerdeki makine konuşmaları bu analiz ve sentez işinin örnekleridir. Sentez yapabilmek için önce analiz yapmak gerekir.

<!-- BELİRSİZ: Slayttaki ses örneğinin sözcüğü altyazıda "bad" olarak geçiyor. Grafikler, çalınan ses ve eksen değerleri altyazıdan görülemiyor. -->

### 16.3 Sinüsü Üstellerle Yazmak

Bir sinüs, formülde yerine konursa iki üstele ayrılır:

$$A\sin(7t) = \frac{A}{2j} e^{j7t} - \frac{A}{2j} e^{-j7t}$$

Hoca buradaki 7'nin açısal frekans olduğunu, frekans düzleminde yazmak için $2\pi f$'e geçildiğini söyledi ve 3.5 değerine ulaştı.

> **Ders sonrası not:** $\omega = 7$ rad/s için $f = 7/(2\pi) \approx 1.11$ Hz'dir. $3.5$ Hz değeri ancak $\omega = 7\pi$ için doğrudur (ikisi de hesaplandı). Slayttaki ifade büyük olasılıkla $\sin(7\pi t)$ idi.

Katsayılardaki $1/j$ için hoca şu eşitliği hatırlattı:

$$e^{j0.5\pi} = \cos(0.5\pi) + j\sin(0.5\pi) = 0 + j = j, \qquad -\frac{1}{j} = j$$

İkincisinin sebebi $j \cdot j = -1$ olmasıdır. Buradan $\frac{1}{2j} = \frac{1}{2} e^{-j\pi/2}$ ve $-\frac{1}{2j} = \frac{1}{2} e^{j\pi/2}$ gelir (ara adım eklendi, sayısal olarak doğrulandı). Yani sinüs, faz $\mp\pi/2$ olan iki spektrum çizgisi verir.

### 16.4 Sentetik Ses

Bir sentetik sesin harmonikleri 200, 400, 500, 1600 ve 1700 Hz'de veriliyor. Temel frekans kaçtır? Bir öğrencinin cevabı ve hocanın onayı: EBOB alınınca 100 Hz'dir. Slaytta bu frekanslara ait $X_k$ genlikleri ve fazları da vardır.

<!-- BELİRSİZ: Bu sentetik sesin genlik ve faz tablosu slaytta, altyazıda okunmuyor. -->

Bu bilgiler frekans düzlemine aktarılır, ardından 5 kosinüs dalgası oluşturulup toplanırsa sesin dalga biçimi elde edilir. Bu işlemlerin hepsi işaretin periyodik olduğu varsayımıyla yapılır.

### 16.5 Karmaşık Üstelin Periyodikliği

Herhangi bir $T$ için $e^{j\omega(t + T)}$ değerinin $e^{j\omega t}$'ye eşit olup olmadığına bakılır. Eşitlik için $e^{j\omega T} = 1$ olmalıdır, yani $\omega T = 2\pi k$'dir. $2\pi$ demek, düzlemde baştan sona 360 derece dönmek demektir. Bu kadar döndüğünüzde aynı noktaya geliyorsanız periyodik bir şey vardır.

> **Hocanın vurgusu:** $e^{j2\pi k} = 1$ eşitliğini çok iyi bilmek gerekir, çünkü kosinüsle ilişkilidir.

### 16.6 En Küçük Frekans Her Zaman Temel Frekans Değildir

10, 30 ve 50 Hz bileşenleri için EBOB 10'dur, yani $f_0 = 10$ Hz. 100 ve 250 Hz bileşenleri için ise 50 Hz'dir.

> **Hocanın vurgusu:** Bazen "en küçükse temel frekans odur" deniyor, her zaman öyle değildir. Doğrudan EBOB bulunur.

## Dersin Toparlaması

Bu derste Fourier serilerinin hesabı baştan sona bağlandı: Periyot ve $\omega_0$ bulunur, integrali parçalamayacak bir aralık seçilir, $c_k$ hesaplanır, $e^{-jk\pi} = (-1)^k$ gibi dönüşümlerle sadeleştirilir, $a_k$ ve $b_k$'ya geçilir. Tek ve çift simetri bu hesabı kısaltır. Spektrum, aynı bilgiyi frekans düzleminde gösterir. Parseval teoremi gücü verir, işaret ise bileşenlerin toplanmasıyla kurulur. Temel frekans EBOB ile, temel periyot EKOK ile bulunur.

Çalışma soruları, dönemin temel işaret ve sistem konularını tekrar etti: Ayrık işlemlerde öteleme ve ölçekleme, örnekleme, periyodiklik, enerji ve güç, $u$ ve $\delta$ ile çarpma ve türev, sistem özellikleri, tek-çift ayrıştırma ve konvolüsyon. Hoca bir sonraki aşamada birkaç Fourier serisi örneği daha yapıp ardından Fourier dönüşümüne geçmeyi planladığını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
