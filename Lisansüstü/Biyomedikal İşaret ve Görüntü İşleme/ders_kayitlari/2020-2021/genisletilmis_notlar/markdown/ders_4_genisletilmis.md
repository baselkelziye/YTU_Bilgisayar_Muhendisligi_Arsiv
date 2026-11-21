# Ders 4 Genişletilmiş Notu: Frekans Cevabı, Filtreler ve Ayrık Zamanlı Fourier Dönüşümü (DTFT)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Konvolüsyon Tekrarı
- 2. Neden Frekans Uzayı?
- 3. Fourier Analizinin Temel Fikri
- 4. Frekans Cevabı
- 5. Euler Eşitliği ve Kompleks Sayılar
- 6. Frekans Cevabının Özellikleri
- 7. Genlik Cevabı, Faz Cevabı ve Ters Dönüşüm
- 8. İdeal Alçak Geçiren Filtre Örneği
- 9. Filtreler (Süzgeçler)
- 10. Ayrık Zamanlı Fourier Dönüşümü (DTFT)
- 11. Temel Dizilerin DTFT'leri
- 12. DTFT Özellikleri
- 13. Parseval Teoremi
- Örnek Sorular

## 1. Konvolüsyon Tekrarı

Hoca derse, bir önceki haftanın konusu olan konvolüsyonu kısaca hatırlatarak başladı. Tahtadaki çizimde bir $x[n]$ girişi, bir sistem kutusu ve bir $y[n]$ çıkışı vardı (ekrandan, 00:10:00). Kutunun içinde sistemin birim örnek (impuls) cevabı $h[n]$ bulunur. Tahtadaki örnekte $x[n]$ dizisi $[-1,2]$ indis aralığında, $h[n]$ dizisi ise $[-1,1]$ aralığında tanımlıydı ve $h[n]$'nin değerleri sırasıyla 3, 2, 1 idi. Hoca bu iki dizinin konvolüsyonunun $-2$ ile $3$ arasında yer alacağını söyledi: başlangıç indisi $-1+(-1)=-2$, bitiş indisi $2+1=3$'tür.

Ardından konu "Fourier Analizi" başlığıyla açıldı (ekrandan, 00:20:00). Bir ayrık işaret $x[n]$, $T[\cdot]$ ile gösterilen bir sistemden (transform, dönüşüm) geçer. Sistemin impulslara verdiği cevap $h[n]$'dir. Ayrık işaret tek tek impulsların birleşiminden oluştuğu için, sistemin bir impulsa verdiği cevabı bilirsek toplam cevabı konvolüsyonla buluruz:

$$y[n]=x[n]*h[n]=\sum_{k=-\infty}^{\infty}x[k]\,h[n-k]$$

Bütün bunlar zaman domeninde yapılır. $n$ indisini görsek de aslında elimizde sürekli bir fonksiyondan alınmış ayrık örnekler vardır. Toplamın içinde değişken $k$ olduğu için $h[n-k]$, $h$'nin ters çevrilmiş ve kaydırılmış halidir. Her seferinde kaydırıp çarparak ve toplayarak ("kaydır-topla") çıkış dizisi $y[n]$ bulunur.

## 2. Neden Frekans Uzayı?

Hoca, öğrencilerin ödevi programlarken de fark ettikleri bir noktaya dikkat çekti: dizilerin boyutu arttıkça bu işlem zorlaşır. Çıkışın uzunluğu $L_x+L_h-1$'dir ve bu kadar çıkış örneği için hem çarpma hem de toplama (sigma) işlemi yapmak gerekir. Buradan şu soru doğar: işaretleri farklı bir uzayda incelemek mümkün mü? Cevap, işaretlerin frekans domeninde incelendiği Fourier analizidir.

Hoca tahtaya şu notu yazdırdı:

> Ayrık zaman Fourier sunumları oldukça önemlidir. Bu yolla işaretler daha kolay yorumlanabilecekleri uzay (space) veya domainlerde değerlendirilebilirler.

## 3. Fourier Analizinin Temel Fikri

Hoca, ilk derslerde Fourier'i anlatırken söylediğini hatırlattı: herhangi bir $x(t)$ işareti aslında birçok sinüzoidin toplamından oluşur. Tahtada bir $x(t)$ eğrisi çizildi; altına sabit bir çizgi, ardından giderek hızlanan sinüzoidler eklendi (ekrandan, 00:25:00). Her sinüzoidin bir genliği ve $T=1/f$'den gelen bir frekansı vardır. Bunu genel olarak şöyle yazdı:

$$x(t)=\int_0^{\infty}A_f\sin(\omega t)\,df=\int_0^{\infty}A_f\sin(2\pi f)\,df$$

Hoca negatif frekansı şimdilik düşünmediği için integrali sıfırdan başlattı. Frekans küçük $df$ adımlarıyla artırılarak sonsuz sayıda frekans toplanır; tahtada bu "sonsuz bir toplam" diye işaretlendi. Sıfır frekanslı terimin bir değer üretmesi için hoca ifadeyi kosinüse çevirdi: $A_0\cos 0=A_0$, yani sabit bir değerdir (ekrandan, 00:30:00). Bu ilk terim DC bileşendir, frekansın sıfır olduğu yerdeki değerdir. Ondan sonra frekans yükselir; tahtadaki bileşenlerin genlikleri $A_x$, $A_z$ gibi adlarla gösterildi. Sinüs ya da kosinüs kullanmak fark etmez; aralarında yalnız faz farkı vardır.

<!-- BELİRSİZ: Tahtada sinüs/kosinüsün içinde 2πf yazılı, t görünmüyor; doğru gösterim büyük olasılıkla cos(2πft)'dir. -->

Fourier'in söylediği şudur: bir işareti oluşturan frekansları bilirsek işaretin karakteristiğini de yorumlayabiliriz. Aynı işaretin frekans içeriğini çizersek sıfırda ortalama değeri, sonra her frekanstaki miktarı görürüz; bazı frekanslar çok, bazıları az bulunur. Teoride sonsuz frekanstan söz etsek de pratikte bir işaret sonsuz frekanslı olamaz; bir $f_{max}$ değerinden sonra bileşen taşımaz. $0$ ile $f_{max}$ arası işaretin frekans bandıdır.

Böylece işareti yorumlamanın iki yolu ortaya çıkar (ekrandan, 00:30:00):

- Zaman domeni (uzayı): işaretin kendisi. Burada işaretin değişimlerini görürüz.
- Frekans uzayı: işaretin içerdiği frekanslar. Burada yalnız hangi frekansların bulunduğunu görürüz.

Hoca bir örnek verdi: işaretin bir bölgesinde hızlı bir değişim olsun. Bu yüksek frekanslı bileşen frekans grafiğinde $f_x$ gibi yüksek bir frekansta bir tepeye neden olur. Bu frekansın işarette yoğun olarak bulunduğunu söyleyebiliriz ama ne zaman oluştuğunu söyleyemeyiz. Frekans uzayında zaman bilgisini kaybederiz.

**Soru:** (Hoca bir öğrenciye) İşaretin frekans uzayında incelenmesi bizim için neden önemli? **Cevap:** Öğrenci, frekanstaki yön değişimlerini ve işaretin şiddetindeki artış ya da azalışı görüp davranışını belirlemek için dedi. Hoca düzeltti: zamandaki değişimler zaman domeninde görünür. Frekans uzayında ise işaretin içindeki frekans bileşenlerini, yani işareti oluşturan frekansların miktarlarını görürüz. Bu bir nevi frekans histogramıdır; işareti farklı biçimde yorumlayabileceğimiz bir uzaya göndermiş oluruz.

## 4. Frekans Cevabı

Sistemin impuls cevabı (birim örnek cevabı) $h[n]$ de sonuçta örneklenmiş bir işarettir (ekrandan, 00:35:00). $h[n]$ sistemin birim örneklere verdiği cevaptır. Peki giriş işareti frekansların toplamı olduğuna göre, bu kutu belli frekanslara nasıl bir değişim uyguluyor? Sistemin impulslara değil, işaretin sahip olduğu frekanslara nasıl davrandığını bilirsek buna frekans cevabı denir:

$$H(e^{j\Omega})=\sum_{k=-\infty}^{\infty}h[k]\,e^{-jk\Omega}$$

(ekrandan, 00:40:00 ve 00:45:00; hoca önce üsteki $k$'yı unuttuğunu fark edip ekledi.)

Normalde $H(f)$ gibi bir gösterim beklenir. Burada frekans yerine daha genel bir kapsam olan $e^{j\Omega}$ yazılır. $\Omega$ çalışılan (sayısal) frekanstır ve $H(e^{j\Omega})$ ifadesi, o frekansa sistemin nasıl bir işlem yaptığını tarif eder.

Formülde $e^{-jk\Omega}$ kısmı bir sinüzoiddir ve $h[k]$ işaretiyle çarpılır. $k$ değiştikçe $h[k]$ farklı frekanslı sinüzoidlerle, yani farklı taban (baz) fonksiyonlarıyla çarpılmış olur. Hoca bunu bir benzerlik ölçüsü olarak çizdi (ekrandan, 00:45:00):

- İşaret, çarpıldığı sinüse ne kadar benziyorsa iki eğri üst üste oturur; çarpımın altında kalan alan pozitif ve büyük olur. Negatif bölgelerde de üst üste oturuyorlarsa yine büyük değer üretir.
- İşaretin sahip olmadığı sabit bir frekansla çarpıldığında altta kalan alanlar belli bir süre sonra birbirini götürür ve o frekansa katkı küçük olur.

Böylece $h$'nin hangi frekanslara daha çok sahip olduğu, yani sistemin giren işareti hangi frekanslarda daha rahat geçireceği bulunur. Tahtadaki örnek çizimde sistem düşük frekansları ve bazı yüksek frekansları daha çok geçiriyordu.

## 5. Euler Eşitliği ve Kompleks Sayılar

### 5.1 Euler eşitliği

$e^{j\Omega}$'nın ne olduğunu hatırlatmak için hoca öğrencilere Euler eşitliğini sordu (ekrandan, 00:35:00). Birkaç denemeden sonra doğru ifade yazıldı:

$$e^{jx}=\cos x+j\sin x$$

Bu fonksiyonun gerçek kısmında kosinüslü, sanal (imajiner) kısmında sinüslü bir bileşen vardır. Hoca şöyle düşünmeyi önerdi: $e^{jx}$ gördüğünüzde aklınıza sinüzoidal bir hareket gelsin. Örneğin $e^{j\Omega}=\cos\Omega+j\sin\Omega$, sürekli frekansla da $\cos 2\pi f+j\sin 2\pi f$ (fazları şimdilik katmadan) iki bileşenli bir sinüzoiddir. Buna kompleks üstel denir: açıldığında $j$'li bir bileşeni olduğu için kompleks, üstel biçimde yazıldığı için üsteldir.

> **Hocanın vurgusu:** İşaret işlemede işaretleri kompleks düzlemde göstermek daha avantajlıdır. Doppler ve ultrason gibi işaretlerin doğası kompleks olarak ifade edildiği için bu daha genel bir gösterimdir.

### 5.2 $e^{-jx}$ açılımı, çift ve tek fonksiyonlar

Frekans cevabında $e^{-jk\Omega}$ bulunduğundan, $e^{-jx}$'in açılımı gerekir:

$$e^{-jx}=\cos(-x)+j\sin(-x)$$

Kosinüs çift fonksiyondur: $f(x)=f(-x)$; $x$ kadar da $-x$ kadar da gidilse aynı genlik alınır. Sinüs tek fonksiyondur: $f(-x)=-f(x)$; $x$ ve $-x$'teki değerler birbirinin tersidir. Bu yüzden kosinüs içerideki eksiyi yok eder, sinüs ise eksiyi dışarı çıkarır:

$$e^{-jx}=\cos x-j\sin x,\qquad e^{-jk\Omega}=\cos(k\Omega)-j\sin(k\Omega)$$

> **Ders sonrası not:** Hoca tahtada bu açılımı yazarken kosinüs ve sinüsün içine fazladan $j$ koydu ($\cos(-jx)$, $\sin(jx)$ gibi) ve kendisi "buradaki j'ler olmayacak" diyerek düzeltti. Doğru açılım yukarıdaki gibidir (ekrandan, 00:50:00).

Sonuç olarak $h[k]$ bu terimlerle çarpılınca gerçek ve sanal kısımları olan kompleks bir sayı çıkar (ekrandan, 00:50:00):

$$H(e^{j\Omega})=H_R(e^{j\Omega})+j\,H_I(e^{j\Omega})$$

### 5.3 Kartezyen ve polar gösterim

Kompleks sayı $z=a+jb$ biçimindedir. Kartezyen koordinatlarda gerçek eksende $a$, sanal eksende $b$ değerini alır. Doğal, gerçek ve irrasyonel sayılarla çalışırken hep tek bir sayı doğrusundaydık; sanal eksenin eklenmesi bu doğruya dik bir eksen açar ve sayılar artık düzlemin bütün kadranlarında yer alabilir.

Aynı noktayı polar gösterimde belirtmek için iki şey gerekir: başlangıca uzaklık $r$ ve açı $\theta$:

$$r=\sqrt{a^2+b^2},\qquad \theta=\arctan\frac{b}{a},\qquad z=r\,e^{j\theta}$$

$r$ Pisagor teoreminden bulunur. Bu iki gösterim birbirine eşittir. Dolayısıyla frekans cevabı da polar biçimde yazılabilir:

$$H(e^{j\Omega})=|H(e^{j\Omega})|\,e^{j\theta_H}$$

## 6. Frekans Cevabının Özellikleri

### 6.1 Kompleks değerlidir

Birinci özellik, yukarıda görüldüğü gibi frekans cevabının kompleks çıktılar vermesidir. Bir kutunun zaman domenindeki karşılığı $h[n]$, frekans domenindeki davranışı ise $H(e^{j\Omega})$'dır.

### 6.2 $2\pi$ ile periyodiktir

Tahtaya yazılan ifade: "Kompleks değerli, $2\pi$ ile periyodik bir fonksiyondur" (ekrandan, 00:55:00). Neden $2\pi$? Girişteki işaret farklı frekanslı sinüzoidlerden oluşuyordu. $x[n]$'in içinde $e^{jn\Omega_0}$ bileşeni olsun. Bu bileşeni şöyle yazabiliriz:

$$e^{jn\Omega_0}=e^{jn(\Omega_0+2\pi)}=e^{jn\Omega_0}\cdot e^{jn2\pi}$$

Hoca $e^{jn2\pi}$'nin değerini bir öğrenciye Euler eşitliğiyle yazdırdı: $e^{jn2\pi}=\cos(2\pi n)+j\sin(2\pi n)$. $n$ tam sayı değerler alır, dolayısıyla kosinüsün içi $\dots,-2\pi,0,2\pi,4\pi,6\pi,\dots$ gibi değerlerdir. Kosinüs bu noktaların hepsinde 1, sinüs ise 0 değerini alır. Sonuç olarak $e^{jn2\pi}=1$ olur ve $\Omega_0$'a $2\pi$ eklemek yine $e^{jn\Omega_0}$'ı verir. Bu periyodikliğin kanıtıdır (ekrandan, 01:00:00):

$$H(e^{j\Omega_0})=H(e^{j(\Omega_0+2\pi)})$$

Hoca bunun anlamını şöyle bağladı: $x[n]$ aslında $e^{jn\Omega_0}+e^{jn\Omega_1}+\dots$ gibi sinüzoidlerin birikimidir ve sisteme girer. Sistemin içinde bu frekanslara karşılık gelen $H(e^{j\Omega})$ değerleri bulunur; yani sistemin o frekansa nasıl davrandığı. Frekans cevabı $[-\pi,\pi]$ aralığında çizilir ve hem kompleks olur hem de kendini tekrar eder.

### 6.3 Simetri (konjüge simetri)

Aradan sonra üçüncü özellik anlatıldı: $h[n]$ gerçek değerli bir fonksiyon ise frekans cevabı frekansa göre konjüge simetriktir:

$$H(e^{-j\Omega})=H^*(e^{j\Omega})$$

Konjüge, $z=a+jb$ için $a-jb$, yani sanal kısmın eksili yazılmasıdır. Bunun anlamı, gerçek kısım çizildiğinde artı frekanslarda ne varsa eksi frekanslarda da ana eksene göre simetrik olarak aynısının bulunmasıdır. Bu işaret $[-\pi,\pi]$ aralığında gösterilir ve periyodik olarak devam eder; $[0,2\pi]$ aralığında düşünülürse $\pi$'ye göre simetrik olduğu da söylenebilir.

> **Hocanın vurgusu:** Periyodik ve simetrik özellikleri olduğu için yalnız temel periyodu incelemek yeterlidir. Temel periyotta da yalnız sıfır ile $\pi$ arasındaki değerleri incelemek yeterlidir. Buradan çıkarılacak özet sonuç budur.

> **Ek bilgi (derste anlatılmadı):** Konjüge simetrinin bir sonucu olarak, gerçek değerli $h[n]$ için genlik cevabı $|H(e^{j\Omega})|$ ve gerçek kısım $\Omega$'ya göre çift, faz cevabı ve sanal kısım ise tek fonksiyondur. Bu yüzden genlik grafiği $\Omega=0$ eksenine göre ayna simetriktir.

## 7. Genlik Cevabı, Faz Cevabı ve Ters Dönüşüm

$H(e^{j\Omega})$ kompleks bir değer ürettiği için hangi frekanslara nasıl davrandığını görmek üzere iki şey çıkarılır (ekrandan, 01:20:00):

$$|H(e^{j\Omega})|=r,\qquad \theta=\arctan\frac{\mathrm{Im}\{H(e^{j\Omega})\}}{\mathrm{Re}\{H(e^{j\Omega})\}}$$

Bu, $z=a+jb$ için $|z|$ ve $\theta=\arctan(b/a)$ hesabının aynısıdır. Böylece frekans cevabının bir genlik cevabı, bir de faz cevabı olmak üzere iki grafiği çizilebilir. Frekanslara nasıl cevap verildiğini görmek için daha çok genlik cevabından yararlanılır.

Frekans cevabı değişken adı $n$ yapılarak $H(e^{j\Omega})=\sum_{n=-\infty}^{\infty}h[n]e^{-jn\Omega}$ diye de yazılabilir; değişkenin adının değişmesi bir şey değiştirmez. Bunun tersi de vardır ve frekans cevabının tersi olarak adlandırılır (ekrandan, 01:25:00):

$$h[n]=\frac{1}{2\pi}\int_{-\pi}^{\pi}H(e^{j\Omega})\,e^{jn\Omega}\,d\Omega$$

İntegral yalnız $[-\pi,\pi]$ aralığında alınır; fonksiyon periyodik devam etse de temel periyodu incelemek yeterlidir. Bu formülle frekans cevabından impuls cevabı (birim örnek cevabı) geri elde edilir. Olayın özeti: frekans cevabı tersine çevrilebilir; kompleks değerli, periyodik ve simetriktir. Simetrik olduğu için matematiksel olarak negatif frekanslarda da bileşenleri bulunur.

## 8. İdeal Alçak Geçiren Filtre Örneği

Hoca şu frekans cevabını örnek verdi (ekrandan, 01:25:00):

$$H(e^{j\Omega})=\begin{cases}1, & |\Omega|\le\Omega_c\\ 0, & \Omega_c<|\Omega|\le\pi\end{cases}$$

Genlik grafiği $-\Omega_c$ ile $\Omega_c$ arasında 1, $\Omega_c$'den $\pi$'ye (ve $-\Omega_c$'den $-\pi$'ye) kadar 0'dır. Buradaki $c$ "cutoff", yani kesim frekansıdır. Yorum: sistem belli bir kesim frekansına kadar bütün frekansları olduğu gibi geçirir, kesim frekansından maksimum frekansa kadar olan kısmı geçirmez. Bu bir alçak geçiren filtredir.

Hoca, frekans domenine geçmenin en büyük kazancını burada vurguladı: $h[n]$'yi ayrık örnekler halinde çizsek sistemin girişe nasıl davranacağını anlayamayız. $H(e^{j\Omega})$ belirlenince $x[n]$'in içindeki sinüzoidal bileşenlere nasıl davranıldığı bilinir; bu örnekte $\Omega_c$'ye kadar olan frekanslara hiç dokunulmadan geçirilip sonra kesildiği görülür. Hoca ayrıca $\Omega=0$'da en yüksek olup frekans arttıkça azalan bir genlik cevabı çizdi: böyle bir sistem alçak frekansları daha iyi geçirir, frekans yükseldikçe o bileşenlerin genliğini bastırır ve belli bir $\Omega_c$'den sonra hiç geçirmez (ekrandan, 01:30:00).

Bu ideal filtrenin $h[n]$'sini bulmak için ters dönüşüm formülü kullanılır. $H(e^{j\Omega})$ yalnız $[-\Omega_c,\Omega_c]$ aralığında 1 değerini aldığı için integral bu aralığa daralır (ekrandan, 01:30:00):

$$h[n]=\frac{1}{2\pi}\int_{-\pi}^{\pi}H(e^{j\Omega})e^{jn\Omega}\,d\Omega=\frac{1}{2\pi}\int_{-\Omega_c}^{\Omega_c}1\cdot e^{jn\Omega}\,d\Omega=\frac{\sin(n\Omega_c)}{\pi n}$$

Ara adım (ara adım eklendi): $\int_{-\Omega_c}^{\Omega_c}e^{jn\Omega}d\Omega=\dfrac{e^{jn\Omega_c}-e^{-jn\Omega_c}}{jn}=\dfrac{2\sin(n\Omega_c)}{n}$; $2\pi$'ye bölünce sonuç elde edilir. Sonuç python ile sayısal integral alınarak birkaç $n$ değeri için doğrulandı.

$h[n]$ çizildiğinde ortada tepe yapan ve iki yana doğru salınarak sönümlenen bir fonksiyon görülür: sinc fonksiyonu. Bu fonksiyonun ayrık hali, belli bir kesim frekansına kadar alçak frekansları geçiren filtreyi sağlar.

> **Ek bilgi (derste anlatılmadı):** $n=0$'da formül $0/0$ belirsizliği verir; limit alınarak $h[0]=\Omega_c/\pi$ bulunur. Ayrıca bu $h[n]$ iki yönde sonsuza uzandığı için ideal alçak geçiren filtre nedensel değildir ve pratikte doğrudan gerçekleştirilemez; gerçek filtreler buna yaklaşır.

Hoca buradan filtre kavramına geçti: $H(e^{j\Omega})$'nın frekans içeriğini bilmek, sistemin hangi frekanslara nasıl davrandığını anlamak için önemlidir; aslında filtreyi bu oluşturur. Derin öğrenmeyle bağlantı da kuruldu: konvolüsyonel ağlarda girişlere uygulanan filtreler, farklı frekanslara farklı cevaplar üreterek öz nitelik çıkarır. Makine öğrenmesiyle bağlantı bu şekilde kurulabilir.

## 9. Filtreler (Süzgeçler)

### 9.1 Tanım

Hoca sayısal filtrenin tanımını tahtaya yazdı (ekrandan, 01:35:00):

> Sayısal filtre ayrık zamanlı sistemlere referans olarak kullanılır. Giriş işareti olarak tanımlanabilecek örneklenmiş işaretin veya sayı dizisinin hesapsal işlem veya algoritmalar ile çıkış işareti olarak adlandırılan ikinci bir diziye dönüştürülmesi işlemidir.
>
> Filtreler, sistem özelliklerine ait (doğrusallık, shift invariance) terimlerle karakterize edilir ve frekans cevaplarına göre sınıflandırılır.

Temelde bir $x[n]$ girişinden bir $y[n]$ çıkış dizisi oluşturulur. Bu işlem zaman domeninde $h[n]$ ile, frekans uzayında $H(e^{j\Omega})$ ile ifade edilir. Birim örnek cevabı ve frekans cevabı dediğimiz her şey aslında sistemin filtresidir. $H(e^{j\Omega})$, frekans domeninde bu filtrelerin tanımlanması için yardımcı olur. $H(e^{j\Omega})$ kompleks olduğu için hem genliği $|H(e^{j\Omega})|$ hem de fazı $\theta_H$ çıkarılabilir; frekans seçici filtreler genlik cevabı üzerinden tanımlanır.

### 9.2 Frekans seçici filtreler

Hoca dört temel filtre tipini $[-\pi,\pi]$ aralığında genlik cevabıyla çizdi (ekrandan, 01:40:00 ve 01:45:00). Frekans cevapları $[-\pi,\pi]$ aralığında tanımlıdır ($[0,2\pi]$ de düşünülebilir ama genel gösterim budur ve negatif bileşenleri de gösterir). Sıfıra yakın yerler alçak, $\pi$'ye yakın yerler yüksek frekanstır.

- **Alçak geçiren filtre (low pass filter):** $-\Omega_c$ ile $\Omega_c$ arasında 1, dışında 0. Sıfır ile $\Omega_c$ arasındaki frekansları geçirir, üsttekileri geçirmez.
- **Yüksek geçiren filtre (high pass filter):** $\Omega_c$ ile $\pi$ arasında (ve simetriği $-\pi$ ile $-\Omega_c$ arasında) 1. Negatif frekanslarda simetrik olmak zorundadır.
- **Bant geçiren filtre (band pass filter):** $\Omega_1$ ile $\Omega_2$ arasında (ve $-\Omega_2$ ile $-\Omega_1$ arasında) 1.
- **Bant durduran filtre (band stop filter):** $|\Omega|<\Omega_1$ ve $\Omega_2<|\Omega|<\pi$ bölgelerinde 1, $\Omega_1$ ile $\Omega_2$ arasında 0.

Bu genlik cevapları çizildikten sonra ters dönüşüm formülüyle $h[n]$ elde edilirse, işarete uygulanmak istenen filtreleme için gerekli ayrık gösterim bulunmuş olur. Bu $h[n]$ ile $x[n]$ konvolüsyona sokulunca çıkış dizisi oluşur.

**Soru:** (Hoca bant geçiren filtreyi çizip sordu) Bu filtreye ne ad verebiliriz, ne yapıyor? **Cevap:** Bir öğrenci "ara değer filtresi gibi bir şey" dedi, hoca doğru olabileceğini söyledi. Bir başka öğrenci "aralıklı filtre, iki değer arasındaki aralığı alan" dedi. Hoca, belli frekans aralıklarına bant dendiğini (örneğin 100 Hz ile 500 Hz arası bir banttır) ipucu olarak verdi: $\Omega_1$ ile $\Omega_2$ arasındaki bandı geçiren bu filtreye bant geçiren (band pass) filtre denir.

**Soru:** (Hoca dördüncü çizimi gösterip sordu) Bu filtreye ne diyebiliriz? **Cevap:** Bir öğrenci filtrenin hem yüksek geçiren hem alçak geçiren özelliklerini aldığını söyledi; hoca bunun da doğru olduğunu belirtti. Adı bant durduran (band stop) filtredir.

> **Ders sonrası not:** Hoca bu filtreyi anlatırken "$\Omega_2$'den $\pi$'ye kadar olan alçak frekansı geçirmiş" dedi. Tahtadaki çizime göre doğrusu, filtrenin $|\Omega|<\Omega_1$ bölgesindeki alçak frekansları ve $\Omega_2<|\Omega|<\pi$ bölgesindeki yüksek frekansları geçirdiğidir (ekrandan, 01:45:00).

### 9.3 Bant durduran filtrenin kullanımı: şebeke gürültüsü

Hoca bant durduran filtrenin nerede kullanıldığını anlattı. Bir giriş işaretiniz var ama belli frekans aralıklarını görmek istemiyorsunuz; dışarıdan bir gürültü katılmış ve o frekanslar gürültü. Önce $x[n]$'den bu gürültüyü temizlemek gerekir: işareti, o aralıktaki frekansları alıp götüren bir $h[n]$'den geçirirsiniz ve asıl uğraşacağınız dizi çıkış dizisi olur.

Örnek: şehir şebeke frekansı 50 Hz'dir. Bu frekans işaretin içine karışır ve gerçekten uğraşmak istediğimiz işaretin karakteristiğini bozar. Dar bir aralıkta, örneğin 48 ile 52 Hz arasında bir bant durduran filtre uygulanarak işarete karışmış olan 50 Hz'lik şebeke işareti ve hafif çevresi temizlenir.

> **Ek bilgi (derste anlatılmadı):** Biyomedikal işaretlerde (EKG, EEG, EMG) şebeke girişimi büyük olasılıkla en yaygın gürültü kaynaklarından biridir; şebeke frekansı bazı ülkelerde 60 Hz'dir. Bu amaçla kullanılan çok dar bant durduran filtrelere "notch" (çentik) filtre de denir.

## 10. Ayrık Zamanlı Fourier Dönüşümü (DTFT)

Yeni sayfada konu "DTFT (Discrete Time Fourier Transform)", yani ayrık zamanlı Fourier dönüşümüdür (ekrandan, 01:50:00).

Hoca şimdiye kadar yapılanı toparladı: $x[n]$ giriyor, $y[n]$ çıkıyor ve $h[n]$'den $H(e^{j\Omega})=\sum_n h[n]e^{-jn\Omega}$ hesaplanıyordu. Dikkat edilmesi gereken nokta, sağ taraftaki toplamın ayrık ($n$ tam sayı), sol taraftaki $H(e^{j\Omega})$'nın ise sürekli olmasıdır. $|H(e^{j\Omega})|$ $[-\pi,\pi]$ aralığında sürekli bir eğri olarak çizilir, çünkü matematiksel olarak bütün frekanslar ince ince elde edilir.

Sistemi karakterize etmek için $h$'nin frekans içeriğine baktık. Peki giriş işaretinin frekans içeriğini bilmek de işimize yarar mı? Evet: girişin frekans içeriğinden giriş işareti hakkında bilgi edinebilir, öz nitelikler çıkarabiliriz. $x[n]$ de ayrık bir işarettir ve aynı formülasyon ona uygulanınca ayrık zamanlı Fourier dönüşümü elde edilir:

$$X(e^{j\Omega})=\sum_{n=-\infty}^{\infty}x[n]\,e^{-jn\Omega}\qquad(1)$$

Giriş dizisi $x[n]$, farklı frekanslara sahip taban fonksiyonlarıyla çarpılır ve hangi frekanstan ne kadar katkı olduğu bulunur. Bu kısım ayrık, elde edilen $X(e^{j\Omega})$ ise sürekli bir fonksiyondur.

Tahtaya şu not yazıldı (ekrandan, 02:00:00): $H(e^{j\Omega})$, birim örnek cevabının ($h[n]$) DTFT'sidir ve özel olarak frekans cevabı adını alır. Formül genel olarak ayrık işaretlere uygulandığında adı ayrık zamanlı Fourier dönüşümüdür, çünkü girişi ayrıktır.

Ters dönüşüm de aynı şekilde tanımlanır (ekrandan, 02:00:00):

$$x[n]=\frac{1}{2\pi}\int_{-\pi}^{\pi}X(e^{j\Omega})\,e^{jn\Omega}\,d\Omega\qquad(2)$$

Burada integral kullanılmasının nedeni $X(e^{j\Omega})$'nın sürekli bir fonksiyon olmasıdır. Hoca integralin ayrık zamandaki karşılığını sordu ve açıkladı: integralde de sigmada da alt ve üst sınırlar belirlenir; fark, sigmanın ayrık bir fonksiyon, integralin ise belli bir aralıkta tanımlı sürekli bir fonksiyon üzerinde çalışmasıdır.

Bir sonraki adım bu sürekli fonksiyonu bilgisayarda işlemektir. Sürekli bir fonksiyon bilgisayara atılamaz; bu yüzden $X(e^{j\Omega})$ da ayrıklaştırılacak ve $X[k]$ ile gösterilecektir. Buna ayrık Fourier dönüşümü (DFT) denir ve sonraki dersin konusudur. DFT'nin çok bilinen hızlandırılmış bir algoritması vardır: hızlı Fourier dönüşümü (FFT) (ekrandan, 01:55:00). DTFT ise bu ikisi arasında bir ara geçiş formülasyonudur.

## 11. Temel Dizilerin DTFT'leri

Hoca (1) numaralı formülü çeşitli dizilere uygulayıp "Sequence - DTFT" tablosunu kurdu (ekrandan, 02:00:00, 02:05:00, 02:10:00).

### 11.1 Birim impuls: $x[n]=\delta[n]$

$$X(e^{j\Omega})=\sum_{n=-\infty}^{\infty}\delta[n]\,e^{-jn\Omega}$$

İmpuls yalnız $n=0$'da değer alır, dolayısıyla toplamda yalnız $n=0$ terimi kalır: $\delta[0]\cdot e^{-j\cdot0\cdot\Omega}=1\cdot e^0=1\cdot1=1$. Sonuç:

$$\delta[n]\ \longleftrightarrow\ 1$$

Çıkış kompleks değil, yalnız gerçek bileşeni olan 1'dir ve $[-\pi,\pi]$ aralığında sürekli 1 değerini alır (ekrandan, 02:00:00).

**Soru:** İmpulsun frekans içeriğinin bu aralıkta sürekli 1 olması ne demek? **Cevap:** Bir öğrenci bunun $\cos$ ve $\sin$ değerleriyle ilgili olup olmadığını sordu; hoca yalnız çizimden yorum yapılmasını istedi ve şöyle açıkladı. Gerçek hayatta ideal bir impuls oluşturmak mümkün değildir, ama genişliği $\varepsilon$ ($-\varepsilon/2$ ile $\varepsilon/2$ arası), yüksekliği $1/\varepsilon$ olan ve altında kalan alan 1 olan kısa bir darbe düşünülebilir; $\varepsilon$ sıfıra giderken bu darbe impulsa yaklaşır (ekrandan, 02:00:00). Örneğin bir antenden böyle anlık bir elektronik sinyal gönderildiğini düşünün. İşareti sinüslere ayırabildiğimize göre, ideal impulsta bütün sinüsler vardır ve hepsinin genliği 1'dir: 100 Hz'de de, 1000 Hz'de de, 10.000 Hz'de de bileşeni vardır. İdeal bir impuls bütün frekansları kapsayan bileşenlere sahiptir.

### 11.2 Kaydırılmış impuls: $x[n]=\delta[n-n_0]$

İmpuls $n_0$ kadar kaydırılmıştır. Formülde yerine koyunca:

$$X(e^{j\Omega})=\sum_{n=-\infty}^{\infty}\delta[n-n_0]\,e^{-jn\Omega}$$

Toplam yalnız $n=n_0$'da değer alır ve orada $\delta[0]=1$'dir. Sonuç (ekrandan, 02:05:00):

$$\delta[n-n_0]\ \longleftrightarrow\ e^{-jn_0\Omega}=\cos(n_0\Omega)-j\sin(n_0\Omega)$$

Yani $n_0$ kadar kaydırma, $n_0$ ile çarpılmış bir frekansa karşılık gelen kompleks bir üstel üretir.

### 11.3 Sabit (DC) dizi: $x[n]=1$

$x[n]$ her $n$ için 1'dir ve sonsuza kadar sabit gider; DC bir işaretten örneklenmiş bir dizidir. Hoca "bunun frekansını söyleyebildiğiniz zaman anlamışsınızdır" dedi. Sonuç (ekrandan, 02:05:00):

$$x[n]=1\ \longleftrightarrow\ 2\pi\,\delta(\Omega)$$

Bu, tam $\Omega=0$'da değer alan ve genliği $2\pi$ olan bir atımdır. İşaretin içeriğindeki tek frekans sıfırdır: bir çevrime girmeyen, AC olmayan, yalnız DC bir bileşen. İşaretin DC olduğu matematiksel olarak da görülmüş olur.

### 11.4 Kompleks üstel: $x[n]=e^{jn\Omega_0}$

$$e^{jn\Omega_0}\ \longleftrightarrow\ 2\pi\,\delta(\Omega-\Omega_0)$$

Frekans içeriğinde yalnız $\Omega_0$'da $2\pi$ genlikli bir atım vardır (ekrandan, 02:10:00). İşaret sabit tek bir frekanslı sinüzoid olduğu için frekans içeriğinde yalnız o frekansı, tepe noktasında bir impuls olarak görürüz.

### 11.5 Kosinüs: $x[n]=\cos(n\Omega_0)$

Hoca, sinüzoidal fonksiyonları ifade etmek için neden kosinüs değil de kompleks üstel kullandığının burada ortaya çıkacağını söyledi:

$$\cos(n\Omega_0)\ \longleftrightarrow\ \pi\,\delta(\Omega+\Omega_0)+\pi\,\delta(\Omega-\Omega_0)$$

Çizildiğinde biri $\Omega_0$'da, biri $-\Omega_0$'da olmak üzere genliği $\pi$ olan iki atım görülür (ekrandan, 02:10:00). Sinüs için de benzer biçimde hem pozitif hem negatif frekansta bileşen çıkar. Kompleks üstelde ise yalnız tek bir atım vardır; bu daha sade, kafa karıştırmayan bir gösterimdir. Frekans içeriğinde $\pm\Omega_0$'da karşılıklı iki atım görürseniz girişte bir kosinüs, tek bir atım görürseniz $\Omega_0$'da bir kompleks üstel vardır.

> **Ders sonrası not:** Tahtada kosinüsün DTFT'si "$\pi\delta(\Omega+\Omega_0)+\pi(\Omega-\Omega_0)$" diye yazıldı; ikinci terimde $\delta$ eksiktir. Doğrusu yukarıdaki gibidir (ekrandan, 02:10:00). Ayrıca 11.3-11.5'teki atımlar $[-\pi,\pi]$ aralığı için yazılmıştır; DTFT $2\pi$ periyodik olduğundan tam ifade, örneğin $x[n]=1$ için $2\pi\sum_{r}\delta(\Omega-2\pi r)$ gibi her $2\pi$'de tekrar eden bir atım dizisidir.

> **Ek bilgi (derste anlatılmadı):** Kosinüsün DTFT'si Euler eşitliğinden doğrudan çıkar: $\cos(n\Omega_0)=\tfrac{1}{2}e^{jn\Omega_0}+\tfrac{1}{2}e^{-jn\Omega_0}$. Her kompleks üstel $2\pi$ genlikli bir atım verdiğinden, $\tfrac12$ katsayısıyla her biri $\pi$ genlikli iki atım elde edilir.

## 12. DTFT Özellikleri

Hoca, uygulamaya geçmeden önce DTFT özelliklerini kısaca sıraladı (ekrandan, 02:15:00 ve 02:20:00). Kompleks değerli olduğu zaten bilindiği için onu yazmadı.

### 12.1 Periyodiklik ve simetri

Frekans cevabında olduğu gibi DTFT de $2\pi$ ile periyodiktir ve kendini $2\pi$'nin katlarında tekrar eder:

$$X(e^{j\Omega})=X(e^{j(\Omega+2\pi)})$$

Simetri özelliği de vardır; hoca bu kısmı yalnız adını söyleyerek geçti.

### 12.2 Doğrusallık

$$a\,x[n]+b\,y[n]\ \longleftrightarrow\ a\,X(e^{j\Omega})+b\,Y(e^{j\Omega})$$

Buradaki $y[n]$ çıkış dizisi değil, yalnız ikinci bir dizidir. Zaman domeninde iki dizi belli genliklerle çarpılıp toplanırsa, frekans domeninde de dönüşümleri aynı katsayılarla çarpılıp toplanır.

### 12.3 Öteleme (shift)

Giriş dizisi $n_0$ kadar kaydırılırsa, frekans gösterimi bir kompleks üstelle çarpılır:

$$x[n-n_0]\ \longleftrightarrow\ e^{-jn_0\Omega}\,X(e^{j\Omega})$$

> **Ders sonrası not:** Tahtada çarpan $e^{jn_0\Omega}$ diye (eksi işareti olmadan) yazıldı (ekrandan, 02:15:00). Doğrusu $e^{-jn_0\Omega}$'dır; bu, hocanın 11.2'de $\delta[n-n_0]$ için bulduğu $e^{-jn_0\Omega}$ sonucuyla da tutarlıdır. Özellik python ile sayısal olarak kontrol edildi.

### 12.4 Zamanda ters çevirme (time reversal)

$$x[-n]\ \longleftrightarrow\ X(e^{-j\Omega})$$

Hoca, simetri nedeniyle genlik gösteriminin aynı çıkacağını, ters çevirmenin çok fark etmediğini söyledi.

### 12.5 Modülasyon

Bir işaret kompleks üstel bir sinüzoidle çarpılırsa:

$$x[n]\,e^{jn\Omega_0}\ \longleftrightarrow\ X(e^{j(\Omega-\Omega_0)})$$

Frekans domeninde işaret merkezden $\Omega_0$ kadar kaydırılmış olur (ekrandan, 02:15:00).

> **Ders sonrası not:** Tahtada sonuç $X(e^{-j(\Omega-\Omega_0)})$ diye yazıldı; doğrusu $X(e^{j(\Omega-\Omega_0)})$'dır (ekrandan, 02:15:00).

Hoca bunun günlük hayatta en çok kullandığımız özellik olduğunu söyledi. Radyo yayınlarını arabada, evde dinleriz; farklı radyolar farklı frekanslardadır. Her radyo vericisi işaretini farklı bir $\Omega_0$'lı sinüzoidle çarparak frekans domeninde farklı yerlere kaydırır. Böylece frekans bantları etkin kullanılır. Çoklu ve telsiz iletişimde, cep telefonlarında da aynısı geçerlidir: farklı frekanslara kaydırmalarla farklı konuşma veya dinleme kanalları oluşturulur. Bu yüzden adı modülasyondur.

<!-- BELİRSİZ: Hoca radyo örneğinde "100 Hz, 101 Hz, 102 Hz" gibi değerler söyledi; bunlar büyük olasılıkla yalnız temsilî değerlerdir (gerçek FM yayınları MHz düzeyindedir). -->

### 12.6 Konvolüsyon

$$x[n]*y[n]=z[n]\ \longleftrightarrow\ Z(e^{j\Omega})=X(e^{j\Omega})\,Y(e^{j\Omega})$$

> **Hocanın vurgusu:** Burası çok önemli. Zaman domenindeki konvolüsyon frekans domeninde basit bir çarpmaya dönüşür.

Zaman domeninde ters çevirme ve kaydırmalarla konvolüsyon yapmak gerekirken, frekans domeninde yalnız $X(e^{j\Omega})$ ve $Y(e^{j\Omega})$ değerleri çarpılır (sıfırdan farklı yerler çarpılarak) ve $Z(e^{j\Omega})$ elde edilir. Sonra ters dönüşüm uygulanarak $z[n]$ bulunur. Frekans domenine geçmenin bir yararı da budur.

### 12.7 Çarpım (multiplication)

Tersi de geçerlidir (ekrandan, 02:20:00):

$$x[n]\,y[n]\ \longleftrightarrow\ \frac{1}{2\pi}\int_{-\pi}^{\pi}X(e^{j\theta})\,Y(e^{j(\Omega-\theta)})\,d\theta$$

Bu bir sürekli konvolüsyondur. Özetle: zaman domeninde çarpma frekans domeninde konvolüsyona, zaman domeninde konvolüsyon frekans domeninde çarpmaya neden olur.

## 13. Parseval Teoremi

Son olarak Parseval teoremi gösterildi (ekrandan, 02:20:00). Hoca önce bir işaretin karesini almanın onun enerjisini hesaplamak anlamına geldiğini söyledi. İşaret kompleks değerliyse mutlak değerinin karesi, yani genliğinin karesi alınır. Bu, zamanda da frekansta da enerji hesabının genel gösterimidir:

$$\sum_{n=-\infty}^{\infty}|x[n]|^2=\frac{1}{2\pi}\int_{-\pi}^{\pi}|X(e^{j\Omega})|^2\,d\Omega$$

Sol taraf zaman domenindeki enerji, sağ taraf $[-\pi,\pi]$ aralığında ortalaması alınan frekans domenindeki enerjidir. Tahtadaki yorum: "Zaman domenindeki enerji frekans domenindeki enerjiye eşittir." Buna enerjinin korunumu ilkesi denir. Eşitlik python ile rastgele bir dizi üzerinde sayısal olarak doğrulandı.

## Örnek Sorular

### Soru 1: Frekans uzayının önemi

Kaynak: (derste sözlü, 00:30:33)

İşaretin frekans uzayında incelenmesi neden önemlidir? Tek cümleyle açıklayın.

**Çözüm (derste verildi):** Frekans uzayında işaretin içindeki frekans bileşenleri ve bunların miktarları görülür (bir tür frekans histogramı). Zamandaki değişimler zaman domeninde görülür; frekans uzayında zaman bilgisi kaybolur.

### Soru 2: Euler eşitliği

Kaynak: (derste sözlü, 00:34:31; ekrandan, 00:35:00 ve 00:50:00)

$e^{jx}$ ifadesini kosinüs ve sinüs bileşenleri cinsinden yazın. Buradan $e^{-jx}$'in açılımını bulun.

**Çözüm (derste verildi):** $e^{jx}=\cos x+j\sin x$. Kosinüs çift, sinüs tek fonksiyon olduğundan $e^{-jx}=\cos(-x)+j\sin(-x)=\cos x-j\sin x$.

### Soru 3: $e^{jn2\pi}$'nin değeri ve periyodiklik

Kaynak: (derste sözlü, 00:54:42; ekrandan, 00:55:00)

$e^{jn(\Omega_0+2\pi)}=e^{jn\Omega_0}\cdot e^{jn2\pi}$ eşitliğinde $e^{jn2\pi}$'nin değeri nedir ($n$ tam sayı)? Bu sonuç frekans cevabı hakkında ne söyler?

**Çözüm (derste verildi):** Euler eşitliğiyle $e^{jn2\pi}=\cos(2\pi n)+j\sin(2\pi n)$. $n$ tam sayı olduğundan kosinüs her zaman 1, sinüs her zaman 0'dır; sonuç 1'dir. Dolayısıyla $e^{jn(\Omega_0+2\pi)}=e^{jn\Omega_0}$ ve $H(e^{j\Omega_0})=H(e^{j(\Omega_0+2\pi)})$: frekans cevabı $2\pi$ ile periyodiktir. (Python ile $n=-2,\dots,3$ için $e^{j2\pi n}=1$ olduğu kontrol edildi.)

### Soru 4: İdeal alçak geçiren filtrenin impuls cevabı

Kaynak: (ekrandan, 01:25:00 ve 01:30:00)

$H(e^{j\Omega})=1$ ($|\Omega|\le\Omega_c$), $H(e^{j\Omega})=0$ ($\Omega_c<|\Omega|\le\pi$) olarak veriliyor. Bu filtre ne tür bir filtredir? $h[n]$'yi bulun.

**Çözüm (derste verildi):** Kesim frekansı $\Omega_c$'ye kadar olan frekansları olduğu gibi geçirip üstündekileri geçirmediği için alçak geçiren filtredir. Ters dönüşümle:

$$h[n]=\frac{1}{2\pi}\int_{-\Omega_c}^{\Omega_c}e^{jn\Omega}\,d\Omega=\frac{\sin(n\Omega_c)}{\pi n}$$

Bu, sönümlenen bir sinc fonksiyonudur. (Sonuç python ile sayısal integralle $\Omega_c=0{,}4\pi$ ve $n=1,2,3,5$ için doğrulandı.)

### Soru 5: Filtreleri adlandırma

Kaynak: (derste sözlü, 01:41:14 ve 01:44:27; ekrandan, 01:45:00)

Genlik cevabı (a) yalnız $\Omega_1<|\Omega|<\Omega_2$ bandında 1 olan, (b) $|\Omega|<\Omega_1$ ve $\Omega_2<|\Omega|<\pi$ bölgelerinde 1, $\Omega_1<|\Omega|<\Omega_2$ bandında 0 olan filtrelere ne ad verilir? (b) tipi bir filtre biyomedikal işarette nerede kullanılabilir?

**Çözüm (derste verildi):** (a) Bant geçiren filtre (band pass filter). (b) Bant durduran filtre (band stop filter); hem alçak hem yüksek geçirenin özelliklerini taşır. Örneğin işarete karışan 50 Hz'lik şehir şebeke frekansını temizlemek için yaklaşık 48-52 Hz aralığını bastıran dar bir bant durduran filtre uygulanır.

### Soru 6: İntegralin ayrık karşılığı

Kaynak: (derste sözlü, 01:52:50)

Ters DTFT formülünde neden integral kullanılır? İntegralin ayrık zamandaki karşılığı nedir?

**Çözüm (derste verildi):** $X(e^{j\Omega})$ sürekli bir fonksiyon olduğu için integral kullanılır. İntegralin ayrık karşılığı toplamdır (sigma); ikisinde de alt ve üst sınırlar vardır, ama sigma ayrık bir fonksiyon üzerinde, integral belli bir aralıkta tanımlı sürekli bir fonksiyon üzerinde çalışır.

### Soru 7: Birim impulsun DTFT'si ve yorumu

Kaynak: (derste sözlü, 01:55:04 ve 01:57:20; ekrandan, 02:00:00)

$x[n]=\delta[n]$ dizisinin DTFT'sini bulun ve frekans içeriği olarak yorumlayın.

**Çözüm (derste verildi):** $X(e^{j\Omega})=\sum_n\delta[n]e^{-jn\Omega}$; yalnız $n=0$ terimi kalır: $\delta[0]\,e^{0}=1$. DTFT $[-\pi,\pi]$ aralığında sabit 1'dir. Yorum: ideal bir impuls bütün frekanslarda eşit genlikte (1) sinüzoidal bileşen taşır; bütün frekansları kapsar.

### Soru 8: Sabit dizinin DTFT'si

Kaynak: (derste sözlü, 02:03:42; ekrandan, 02:05:00)

Her $n$ için $x[n]=1$ olan dizinin frekans içeriği nedir?

**Çözüm (derste verildi):** $X(e^{j\Omega})=2\pi\,\delta(\Omega)$: yalnız $\Omega=0$'da genliği $2\pi$ olan bir atım. İşaretin yalnız DC (sıfır frekanslı) bileşeni vardır. (Tam ifade $2\pi$ periyodik atım dizisidir; bkz. Bölüm 11.5'teki not.)

### Soru 9: Konvolüsyon çıkışının indis aralığı

Kaynak: (derste sözlü, 00:09:18-00:10:52; ekrandan, 00:10:00)

$x[n]$ dizisi $[-1,2]$ aralığında, $h[n]=\{3,2,1\}$ dizisi $[-1,1]$ aralığında tanımlıdır. $y[n]=x[n]*h[n]$ hangi indis aralığında yer alır ve kaç örneklidir?

**Çözüm (derste verildi):** Başlangıç $-1+(-1)=-2$, bitiş $2+1=3$; yani $y[n]$ $[-2,3]$ aralığındadır. Uzunluk $L_x+L_h-1=4+3-1=6$ örnektir (uzunluk ara adım eklendi).

### Soru 10: Parseval teoreminin yorumu

Kaynak: (derste sözlü, 02:18:23; ekrandan, 02:20:00)

$\sum_n|x[n]|^2=\frac{1}{2\pi}\int_{-\pi}^{\pi}|X(e^{j\Omega})|^2d\Omega$ eşitliğini zaman ve frekans domenini birlikte düşünerek yorumlayın.

**Çözüm (derste verildi):** Bir işaretin (mutlak değerinin) karesini almak onun enerjisini hesaplamaktır. Sol taraf zaman domenindeki enerji, sağ taraf frekans domenindeki enerjidir; ikisi eşittir. Buna enerjinin korunumu ilkesi denir.

## Dersin Toparlaması

Bu derste konvolüsyonun zaman domenindeki yükünden yola çıkılarak frekans uzayına geçildi. Her işaretin farklı frekanslı sinüzoidlerin toplamı olduğu, frekans uzayının hangi frekansların ne kadar bulunduğunu gösterdiği ama zaman bilgisini kaybettirdiği anlatıldı. Sistemin frekanslara verdiği cevap olarak $H(e^{j\Omega})=\sum_k h[k]e^{-jk\Omega}$ tanımlandı. Euler eşitliği ve kompleks sayıların kartezyen/polar gösterimi hatırlatıldı. Frekans cevabının kompleks değerli, $2\pi$ periyodik ve (gerçek $h[n]$ için) konjüge simetrik olduğu, bu yüzden $[0,\pi]$ aralığının yeterli olduğu gösterildi. Genlik ve faz cevabı ile ters dönüşüm verildi. İdeal alçak geçiren filtreden sinc biçimli $h[n]=\sin(n\Omega_c)/(\pi n)$ elde edildi. Ardından sayısal filtre tanımlandı ve alçak geçiren, yüksek geçiren, bant geçiren ve bant durduran filtreler şebeke gürültüsü örneğiyle anlatıldı.

Son bölümde aynı formülün herhangi bir ayrık işarete uygulanmasıyla DTFT ve tersi tanımlandı. Temel dizilerin ($\delta[n]$, $\delta[n-n_0]$, sabit dizi, kompleks üstel, kosinüs) DTFT'leri çıkarıldı. Doğrusallık, öteleme, zamanda ters çevirme, modülasyon, konvolüsyon, çarpım özellikleri ve Parseval teoremi verildi. Hoca, $X(e^{j\Omega})$ sürekli olduğu için bilgisayarda işlenemeyeceğini ve sonraki derste ayrıklaştırılmış hali olan DFT ile hızlı algoritması FFT'ye geçileceğini söyledi. Sayısal işaret işleme kısmı DFT/FFT ve zaman-frekans analizleriyle tamamlanacak, ardından görüntü işlemeye geçilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
