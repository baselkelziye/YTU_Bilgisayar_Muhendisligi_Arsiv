# Ders 13 Çalışma Özeti

## Genel Konular

- Frekans analizinin genel haritası ve Laplace dönüşümünün yeri
  - Frekans analizi sürekli ve ayrık olmak üzere iki koldan ilerler: sürekli zamanlı Fourier serisi (CTFS) ile ayrık zamanlı Fourier serisi (DTFS), sürekli zamanlı Fourier dönüşümü (CTFT) ile ayrık zamanlı Fourier dönüşümü (DTFT) birbirinin karşılığıdır (ekrandan, 00:10:00). Sürekli tarafta integral, ayrık tarafta toplam (sigma) kullanılır.
  - DTFT'de frekans sürekli olduğu için frekansın da ayrıklaştırılmasıyla ayrık Fourier dönüşümü (DFT) elde edilmişti. DFT ve FFT gibi hızlı sürümleri sayısal işaret işleme dersinin konusudur.
  - Laplace dönüşümü (LT) CTFT'nin, z dönüşümü ise DTFT'nin genelleştirilmiş hâlidir (ekrandan, 02:00:00). Bu ders yalnız sürekli zamanlı işaretlerle ilgilidir.
- Fourier dönüşümünün sınırları
  - Frekans cevabı ancak üç koşulda kullanılabilir: sistem sıfır durumundadır (başlangıç koşulları sıfır), impuls cevabı mutlak integrallenebilirdir ($\int_{-\infty}^{\infty}|h(t)|\,dt<\infty$) ve giriş mutlak integrallenebilirdir ($\int_{-\infty}^{\infty}|x(t)|\,dt<\infty$) (ekrandan, 00:05:00).
  - Sinüzoitler ve birim basamak bu koşulu sağlamadığı hâlde FT ile ele alınabilen istisnalardır. LT bu üç koşulun sağlanmadığı durumlarda da kullanılabilir.
  - LT iki analiz yolu açar (ekrandan, 00:15:00): sıfır durumunda LT ve transfer fonksiyonu (FT'nin yaptığını daha geniş bir işaret/sistem sınıfı için yapar) ve sıfır olmayan durumda LT tabanlı diferansiyel denklem çözümü. İkincisi bu dersin kapsamı dışında bırakıldı.
- Laplace dönüşümünün tanımı
  - CTFT: $X(\omega)=\int_{-\infty}^{\infty}x(t)e^{-j\omega t}\,dt$. Sisteme $e^{j\omega t}=\cos\omega t + j\sin\omega t$ biçiminde karmaşık sinüzoit verilir; $\omega=2\pi f$ değiştirilerek sistemin her frekansa cevabı, yani frekans cevabı $H(\omega)$ bulunur (ekrandan, 00:20:00).
  - LT, $e^{-j\omega t}$ yerine $e^{-st}$ kullanır: $s=\sigma+j\omega$ karmaşık bir değişkendir ve $e^{-st}=e^{-\sigma t}e^{-j\omega t}$ olur. $e^{-\sigma t}$ çarpanı integrandın sönümünü kontrol eder (ekrandan, 00:20:00).
  - İki taraflı (bilateral) LT: $X(s)=\int_{-\infty}^{\infty}x(t)e^{-st}\,dt$. Tek taraflı (unilateral) LT integrali $0$'dan başlatır; işaretin $t<0$ kısmını yok sayar ve özellikle nedensel sistemlerde kullanılır (ekrandan, 00:25:00).
  - $X(s)$ karmaşık değerlidir. FT'de $|X(\omega)|$ tek bir frekans ekseninde çizilirken LT'de $\sigma$ ve $j\omega$ eksenlerinden oluşan s düzlemi (s-plane) vardır; $|X(s)|$ üçüncü eksende çizilir.
- Örnek: $x(t)=e^{-bt}u(t)$, $b$ gerçel (ekrandan, 00:30:00)
  - $u(t)$ işareti $t=0$'dan başlatır, bu yüzden işaret nedenseldir ve integral $0$'dan başlar: $X(s)=\int_0^\infty e^{-(s+b)t}\,dt=\dfrac{-1}{s+b}\left[\lim_{t\to\infty}e^{-(s+b)t}-1\right]$.
  - $e^{-(s+b)t}=e^{-(\sigma+b)t}e^{-j\omega t}$ yazılır. $\sigma+b>0$ ise ifade sönümlenir ve limit sıfırdır; $\sigma+b<0$ ise ifade büyür ve integral yoktur (ekrandan, 00:35:00).
  - Sonuç: $X(s)=\dfrac{1}{s+b}$, $\operatorname{Re}\{s\}>-b$ (ekrandan, 00:40:00).
  - FT'de $b>0$ kısıtı gerekiyordu; LT'de böyle bir kısıt yoktur.
- Yakınsama bölgesi (Region of Convergence, ROC)
  - İntegralin var olduğu (sonlu bir değere yakınsadığı) $s$ değerlerinin bölgesidir. Laplace dönüşümü her zaman ROC ile birlikte verilir.
  - $b>0$ ise $x(t)$ sönümlenir, $-b$ negatiftir ve ROC $j\omega$ eksenini içerir; bu durumu FT de LT de çözer. $b<0$ ise $x(t)$ "patlar", $-b$ pozitiftir ve ROC $j\omega$ eksenini içermez; FT çözemez, ama yalnız ROC içindeki $s$ değerlerine bakan LT çözer (ekrandan, 00:45:00).
- CTFT ile LT arasındaki bağlantı
  - ROC $j\omega$ eksenini ($\sigma=0$) içeriyorsa $X(\omega)=X(s)\big|_{s=j\omega}$ olur. Örnek: $\dfrac{1}{s+b}\Big|_{s=j\omega}=\dfrac{1}{j\omega+b}$, FT tablosundakiyle aynıdır (ekrandan, 00:50:00).
  - Bu durumda FT, $|X(s)|$ yüzeyinin $j\omega$ ekseni boyunca alınan kesitidir. ROC $j\omega$ eksenini içermiyorsa $\sigma=0$ koymak FT'yi vermez.
- İki taraflı LT'nin özellikleri (ekrandan, 01:05:00 ve 01:10:00)
  - Doğrusallık: $ax(t)+by(t)\leftrightarrow aX(s)+bY(s)$.
  - Zamanda öteleme: $x(t-c)\leftrightarrow e^{-cs}X(s)$. $\sigma=0$ konursa FT'deki $e^{-j\omega c}$ çarpanı elde edilir.
  - Zamanda türev $s$ ile çarpmaya, zamanda integral $1/s$ ile çarpmaya karşılık gelir.
  - Zamanda ölçekleme: $x(at)\leftrightarrow \dfrac{1}{a}X\!\left(\dfrac{s}{a}\right)$, $a>0$. $a<0$ işareti nedensel olmayan hâle getirdiği için $a>0$ ile sınırlanır.
  - $t^n$ ile çarpma: $t^n x(t)\leftrightarrow(-1)^n\dfrac{d^n}{ds^n}X(s)$.
  - Üstelle çarpma: $e^{at}x(t)\leftrightarrow X(s-a)$, $a$ gerçel ya da karmaşık; s düzleminde ötelemedir.
  - Sinüzoitle çarpma: $x(t)\sin(\omega_0 t)\leftrightarrow\dfrac{j}{2}\left[X(s+j\omega_0)-X(s-j\omega_0)\right]$; kosinüsle çarpma da benzer biçimde $j\omega$ yönünde frekans kaydırması yapar.
- Konvolüsyon ve transfer fonksiyonu
  - Zamanda konvolüsyon s düzleminde çarpmaya dönüşür: $Y(s)=H(s)X(s)$. FT'de $Y(\omega)=H(\omega)X(\omega)$ idi ve $H(\omega)$ frekans cevabıydı.
  - $H(s)$ transfer fonksiyonudur ve frekans cevabının genelleştirilmiş hâlidir.
- Ters Laplace dönüşümü ve kısmi kesirlere ayırma
  - Tanımdaki ters dönüşüm karmaşık çizgi integrali gerektirir ve zordur. Bunun yerine $X(s)$ iki polinomun oranıysa, bilinen tablo çiftlerine ayrılıp tersi tablodan bulunur.
  - Örnek: $\mathcal{L}^{-1}\left\{\dfrac{1/RC}{(s+1/RC)s}\right\}=\mathcal{L}^{-1}\left\{\dfrac1s\right\}-\mathcal{L}^{-1}\left\{\dfrac{1}{s+1/RC}\right\}=u(t)-e^{-t/RC}u(t)$ (ekrandan, 01:15:00).
  - Payın derecesi paydanınkinden küçük değilse sabit bir "doğrudan terim" (direct term) de oluşur. Örnek: $Y(s)=\dfrac{2}{s+3}+\dfrac{4}{s+5}+2$; kutuplar $s=-3$ ve $s=-5$ (ekrandan, 01:20:00).
  - Basit kutuplu örnek: $Y(s)=\dfrac{3s-1}{(s+1)(s+2)}=\dfrac{R_1}{s+1}+\dfrac{R_2}{s+2}$. İki taraf $(s+1)$ ile çarpılıp $s=-1$ konursa $R_1=-4$, $(s+2)$ ile çarpılıp $s=-2$ konursa $R_2=7$ bulunur. Sonuç $y(t)=-4e^{-t}u(t)+7e^{-2t}u(t)$ (ekrandan, 01:25:00). $R_1,R_2$ katsayılarına rezidü denir.
  - Katlı kutup (aynı kökün tekrarlandığı) durum için ayrı formül vardır; hoca bunun derinlemesine bilinmesini beklemediğini söyledi.
- Sıfırlar, kutuplar ve kutup-sıfır çizimi
  - $H(s)=\dfrac{B(s)}{A(s)}=b_M\dfrac{(s-z_1)\cdots(s-z_M)}{(s-p_1)\cdots(s-p_N)}$. $A(s)$ karakteristik polinomdur. $B(s)$'nin kökleri $z_i$ sıfırlardır ($H$ sıfır olur), $A(s)$'nin kökleri $p_i$ kutuplardır ($H$ sonsuza gider). $b_M$ kazanç gibidir.
  - Örnek: $H(s)=\dfrac{2s^2+12s+20}{s^3+6s^2+10s+8}=\dfrac{2(s+3-j)(s+3+j)}{(s+4)(s+1-j)(s+1+j)}$. Sıfırlar $-3\pm j$, kutuplar $-4$ ve $-1\pm j$. Gerçel katsayılı polinomda karmaşık kökler eşlenik çiftler hâlinde gelir. Kutup-sıfır çiziminde × kutbu, o sıfırı gösterir (ekrandan, 01:30:00).
  - Kutup-sıfır çizimi sistemin davranışının grafik görünümüdür; ROC hiçbir kutbu içermez.
- Kitaptan (Schaum) ve M. J. Roberts slaytlarından örnekler
  - $x(t)=e^{-t}u(t)+e^{2t}u(-t)$: $\dfrac{1}{s+1}$ ($\sigma>-1$) ve $-\dfrac{1}{s-2}$ ($\sigma<2$); toplam $\dfrac{-3}{(s+1)(s-2)}$, ROC $-1<\sigma<2$ şeridi (ekrandan, 01:35:00).
  - Sol taraflı işaretler: $-e^{-at}u(-t)\leftrightarrow\dfrac{1}{s+a}$, $\operatorname{Re}\{s\}<-a$; $e^{at}u(-t)\leftrightarrow-\dfrac{1}{s-a}$, $\operatorname{Re}\{s\}<a$ (ekrandan, 01:45:00 ve 01:55:00). $e^{-at}u(t)$ ile $-e^{-at}u(-t)$ aynı cebirsel ifadeyi verir; yalnız ROC'ları farklıdır.
  - Temel çiftler: $\delta(t)\leftrightarrow1$ (bütün $s$), $u(t)\leftrightarrow\dfrac1s$ ($\operatorname{Re}\{s\}>0$), $-u(-t)\leftrightarrow\dfrac1s$ ($\operatorname{Re}\{s\}<0$), $tu(t)\leftrightarrow\dfrac{1}{s^2}$.
  - $x(t)=e^{-2t}u(t)+e^{-3t}u(t)$: $X(s)=\dfrac{2s+5}{(s+2)(s+3)}=\dfrac{2(s+5/2)}{(s+2)(s+3)}$, ROC $\operatorname{Re}\{s\}>-2$; sıfır $-2{,}5$, kutuplar $-2$ ve $-3$ (ekrandan, 01:50:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- "Laplace dönüşümü, CTFT'nin genelleştirilmiş hâlidir."
  - Hoca bu cümleyi yıldızla işaretledi. FT'nin istediği üç koşul sağlanmasa da LT kullanılabilir.
- Dönüşüm sonucu ROC olmadan eksiktir.
  - Aynı $\dfrac{1}{s+a}$ ifadesi hem sağ taraflı hem sol taraflı bir işarete ait olabilir; işareti ROC belirler.
- ROC'un integralden nasıl çıktığı
  - Hoca, $e^{-(s+a)t}$'nin sınırda sıfıra gitmesi koşulundan ROC'u bulma işlemine çalışılmasını özellikle istedi. Sağ taraflı ve sol taraflı iki örneğin herkes tarafından çözülmesini istedi.
- Bilinmesi beklenen soru tipleri
  - Temel işaretlerin LT'sini ve ROC sınırlarını (tablodan) bulmak, ROC'u ve kutup-sıfırları s düzleminde çizmek, basit kısmi kesirlerle ters LT'yi bulmak. Katlı kutuplu ayrıntılı çözümler ve diferansiyel/fark denklemleriyle devre analizi beklenmiyor.
- Bu dersin önemi
  - Burada öğrenilen yöntemler makine öğrenmesinde ve görüntü işlemede işe yarar; sistemin nasıl davrandığını anlayan bir mühendis olmak için gereklidir.

## Kısa Tekrar Notları

- $s=\sigma+j\omega$; $X(s)=\int_{-\infty}^{\infty}x(t)e^{-st}\,dt$ (iki taraflı), alt sınır $0$ ise tek taraflı.
- $e^{-\sigma t}$ çarpanı integrandı sönümlendirir; FT'nin yakınsamadığı işaretler LT ile incelenebilir.
- $e^{-bt}u(t)\leftrightarrow\dfrac{1}{s+b}$, $\operatorname{Re}\{s\}>-b$ (sağ yarı düzlem).
- $-e^{-at}u(-t)\leftrightarrow\dfrac{1}{s+a}$, $\operatorname{Re}\{s\}<-a$ (sol yarı düzlem).
- İki taraflı işaretin ROC'u iki ROC'un kesişimi, yani dikey bir şerittir.
- ROC $j\omega$ eksenini içeriyorsa $X(\omega)=X(s)|_{s=j\omega}$.
- Türev $\to$ $s$ ile çarpma; integral $\to$ $1/s$ ile çarpma; öteleme $\to$ $e^{-cs}$; $e^{at}$ ile çarpma $\to$ $X(s-a)$.
- $Y(s)=H(s)X(s)$; $H(s)$ transfer fonksiyonu.
- Pay kökleri sıfır (o), payda kökleri kutup (×); ROC kutup içermez.
- Kısmi kesirde rezidü: $R_i=\left[(s-p_i)X(s)\right]_{s=p_i}$.

## Detaylı Açıklamalar

- Fourier dönüşümünde sisteme farklı frekanslarda karmaşık sinüzoitler verilip sistemin her birine cevabı ölçülür. Bir işaret farklı frekanslı sinüzoitlerin toplamı olarak modellenebildiği için, sistemin her frekanstaki cevabı ($H(\omega)$) bilinirse herhangi bir girişe cevabı da bulunabilir. Ancak $\int x(t)e^{-j\omega t}dt$ integrali her işaret için sonlu değildir. Örneğin $t\to\infty$ iken büyüyen bir işaretin altında kalan alan sonsuza gider.
- Laplace dönüşümü bu sorunu üstele bir gerçel kısım ekleyerek çözer. $e^{-st}=e^{-\sigma t}e^{-j\omega t}$ çarpımında $e^{-j\omega t}$ kısmının büyüklüğü 1'dir; yakınsamayı yalnız $e^{-\sigma t}$ ile işaretin kendi büyüme hızı belirler. Uygun bir $\sigma$ seçildiğinde büyüyen işaret de bastırılır ve integral sonlu olur. Bu $\sigma$ değerlerinin oluşturduğu bölge ROC'tur ve s düzleminde dikey çizgilerle sınırlanır.
- $e^{-bt}u(t)$ örneğinde $X(s)=\dfrac{1}{s+b}$ bulunur ve integral yalnız $\sigma>-b$ için vardır. $b>0$ iken ROC sanal ekseni içerir; $s=j\omega$ koymak doğrudan FT'yi verir. $b<0$ iken işaret üstel olarak büyür ve FT yoktur, ama ROC ($\sigma>-b>0$) içinde LT tanımlıdır. Bu, LT'nin FT'den daha geniş bir işaret sınıfını kapsadığını gösterir.
- Sol taraflı işaretlerde ($u(-t)$ ile çarpılmış) integral $-\infty$'dan $0$'a alınır. Bu kez üstelin $t\to-\infty$'da sıfıra gitmesi gerekir; bu da ROC'u bir sınırın soluna düşürür. Örneğin $e^{at}u(-t)$ için $e^{-(s-a)t}$ ifadesi $t\to-\infty$'da ancak $\operatorname{Re}\{s\}<a$ iken sıfıra gider ve sonuç $-\dfrac{1}{s-a}$ olur. İki taraflı bir işaret (sağ taraflı ve sol taraflı parçaların toplamı) için ROC iki bölgenin kesişimidir; kesişim boşsa LT yoktur.
- Ters dönüşümde amaç, $X(s)$'i tablodaki basit kesirlerin toplamına ayırmaktır. Basit kutuplarda her rezidü, $X(s)$ ilgili $(s-p_i)$ çarpanıyla çarpılıp $s=p_i$ konularak bulunur. Sonra her $\dfrac{R_i}{s-p_i}$ terimi, ROC'a göre $R_ie^{p_it}u(t)$ (sağ taraflı) ya da $-R_ie^{p_it}u(-t)$ (sol taraflı) olarak geri çevrilir. Doğrusallık sayesinde katsayılar dönüşümün önüne aynen gelir.
- Transfer fonksiyonu kutup ve sıfırlarıyla yazıldığında sistemin s düzlemindeki davranışı görünür olur. $|H(s)|$ yüzeyi sıfırlarda sıfıra iner, kutuplarda sonsuza yükselir. Bu yüzeyin $j\omega$ ekseni boyunca alınan kesiti, ROC bu ekseni içeriyorsa frekans cevabıdır.
- Ders sonrası not: Hoca $e^{-bt}u(t)$ örneğinin ROC'unu s düzleminde gösterirken (00:43:00 civarı) "$\sigma$'nın $-b$'den küçük olduğu kısımlar" dedi; slayttaki ve hesaptaki sonuç $\sigma>-b$'dir, yani ROC $\sigma=-b$ çizgisinin sağıdır.
- Ders sonrası not: $e^{-t}u(t)+e^{2t}u(-t)$ örneğinde hoca kutupları "$-1$ ve $-2$" diye söyledi; $X(s)=\dfrac{-3}{(s+1)(s-2)}$ olduğundan kutuplar $s=-1$ ve $s=2$'dir (slaytta da böyle).
- Ders sonrası not: "Doğrudan terim" slaytında $\dfrac{2}{s+3}+\dfrac{4}{s+5}+2$ ifadesinin ortak paydada payı $2s^2+22s+47$ yazılıydı. Açılınca $2(s+5)+4(s+3)+2(s+3)(s+5)=2s^2+22s+52$ çıkar; slayttaki 47 büyük olasılıkla yazım hatasıdır (python ile kontrol edildi).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
