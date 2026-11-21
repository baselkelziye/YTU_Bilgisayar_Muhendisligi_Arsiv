# Ders 4 Çalışma Özeti

## Genel Konular

- Konvolüsyon tekrarı ve frekans uzayına geçiş gerekçesi
  - LSI sistemde çıkış $y[n]=x[n]*h[n]=\sum_{k=-\infty}^{\infty}x[k]\,h[n-k]$ ile bulunur; ikinci dizi ters çevrilir, kaydırılır, çarpılıp toplanır (ekrandan, 00:20:00).
  - Çıkışın uzunluğu $L_x+L_h-1$'dir. Diziler uzadıkça çarpma ve toplama sayısı artar; bu yüzden işaretleri daha kolay yorumlanabilecekleri başka bir uzayda (frekans uzayında) incelemek istenir.
  - Hocanın tahtaya yazdığı not: Ayrık zaman Fourier sunumları önemlidir; bu yolla işaretler daha kolay yorumlanabilecekleri uzaylarda (domain) değerlendirilebilir.
- Fourier analizinin temel fikri
  - Bir $x(t)$ işareti farklı frekanslı sinüzoidlerin toplamıdır: $x(t)=\int_0^{\infty}A_f\cos(2\pi f t)\,df$ (ekrandan, 00:25:00 ve 00:30:00; tahtada önce sinüs, sonra kosinüs yazıldı).
  - $f=0$ terimi sabit bir değerdir: DC bileşen. Frekans arttıkça daha hızlı salınan bileşenler gelir.
  - Pratikte işaretler sonsuz frekanslı değildir; bir $f_{max}$'a kadar gider. $0$ ile $f_{max}$ arası işaretin frekans bandıdır.
  - İşareti yorumlamanın iki yolu: zaman domeni (uzayı) ve frekans uzayı. Frekans uzayı bir nevi "frekans histogramı"dır; hangi frekansın ne kadar bulunduğunu gösterir ama ne zaman oluştuğunu göstermez (zaman bilgisi kaybolur).
- Frekans cevabı
  - $h[n]$ sistemin birim örneğe (impulsa) cevabıdır. Sistemin farklı frekanslara verdiği cevap ise frekans cevabıdır:
    - $H(e^{j\Omega})=\sum_{k=-\infty}^{\infty}h[k]\,e^{-jk\Omega}$ (ekrandan, 00:40:00 ve 00:45:00).
  - $e^{-jk\Omega}$ terimleri farklı frekanslı taban (baz) fonksiyonlarıdır. $h[k]$ her biriyle çarpılıp toplanır; işaret o sinüzoide ne kadar benziyorsa sonuç o kadar büyük olur, benzemiyorsa alanlar birbirini götürür.
- Euler eşitliği ve kompleks sayılar
  - $e^{jx}=\cos x+j\sin x$; $e^{-jx}=\cos x-j\sin x$ (kosinüs çift, sinüs tek fonksiyon).
  - $e^{j\Omega}$ kompleks üsteldir; bir sinüzoidal hareketi ifade eder.
  - Kompleks sayı: $z=a+jb$ (kartezyen), $z=r\,e^{j\theta}$ (polar); $r=\sqrt{a^2+b^2}$, $\theta=\arctan(b/a)$.
- Frekans cevabının özellikleri
  - Kompleks değerlidir: $H(e^{j\Omega})=H_R(e^{j\Omega})+jH_I(e^{j\Omega})=|H(e^{j\Omega})|\,e^{j\theta_H}$ (ekrandan, 00:50:00).
  - $2\pi$ ile periyodiktir: $e^{jn(\Omega_0+2\pi)}=e^{jn\Omega_0}\,e^{jn2\pi}=e^{jn\Omega_0}$, çünkü $n$ tam sayıyken $e^{jn2\pi}=\cos 2\pi n+j\sin 2\pi n=1$. Dolayısıyla $H(e^{j\Omega_0})=H(e^{j(\Omega_0+2\pi)})$ (ekrandan, 00:55:00 ve 01:00:00).
  - $h[n]$ gerçek değerliyse frekans cevabı konjüge simetriktir: $H(e^{-j\Omega})=H^*(e^{j\Omega})$.
  - Periyodiklik ve simetri yüzünden $[-\pi,\pi]$ aralığına, hatta yalnız $[0,\pi]$ aralığına bakmak yeterlidir.
  - Genlik cevabı $|H(e^{j\Omega})|$, faz cevabı $\theta=\arctan\dfrac{\mathrm{Im}\{H(e^{j\Omega})\}}{\mathrm{Re}\{H(e^{j\Omega})\}}$ (ekrandan, 01:20:00).
  - Ters dönüşüm: $h[n]=\dfrac{1}{2\pi}\int_{-\pi}^{\pi}H(e^{j\Omega})\,e^{jn\Omega}\,d\Omega$ (ekrandan, 01:25:00).
- İdeal alçak geçiren filtre örneği
  - $H(e^{j\Omega})=1$ ($|\Omega|\le\Omega_c$), $0$ ($\Omega_c<|\Omega|\le\pi$); $\Omega_c$ kesim (cutoff) frekansı (ekrandan, 01:25:00).
  - $h[n]=\dfrac{1}{2\pi}\int_{-\Omega_c}^{\Omega_c}e^{jn\Omega}\,d\Omega=\dfrac{\sin(n\Omega_c)}{\pi n}$: sönümlenen bir sinc fonksiyonu (ekrandan, 01:30:00).
- Filtreler (süzgeçler)
  - Tanım (ekrandan, 01:35:00): Sayısal filtre, ayrık zamanlı sistemlere referans olarak kullanılır; giriş işareti olarak tanımlanabilecek örneklenmiş işaretin veya sayı dizisinin, hesapsal işlem veya algoritmalarla çıkış işareti olarak adlandırılan ikinci bir diziye dönüştürülmesi işlemidir. Filtreler doğrusallık, öteleme ile değişmezlik gibi sistem özellikleriyle karakterize edilir ve frekans cevaplarına göre sınıflandırılır.
  - Frekans seçici filtreler (ekrandan, 01:40:00 ve 01:45:00):
    - Alçak geçiren (low pass): $|\Omega|<\Omega_c$ bölgesini geçirir.
    - Yüksek geçiren (high pass): $\Omega_c<|\Omega|<\pi$ bölgesini geçirir.
    - Bant geçiren (band pass): $\Omega_1<|\Omega|<\Omega_2$ bandını geçirir.
    - Bant durduran (band stop): $\Omega_1<|\Omega|<\Omega_2$ bandını bastırır, geri kalanı geçirir.
  - Uygulama: Şehir şebekesinin 50 Hz'lik gürültüsü için yaklaşık 48-52 Hz aralığını temizleyen dar bir bant durduran filtre.
- Ayrık zamanlı Fourier dönüşümü (DTFT)
  - Frekans cevabı formülü herhangi bir ayrık işarete uygulanınca DTFT elde edilir: $X(e^{j\Omega})=\sum_{n=-\infty}^{\infty}x[n]\,e^{-jn\Omega}$ (ekrandan, 01:50:00).
  - Ters DTFT: $x[n]=\dfrac{1}{2\pi}\int_{-\pi}^{\pi}X(e^{j\Omega})\,e^{jn\Omega}\,d\Omega$ (ekrandan, 02:00:00).
  - Not: $H(e^{j\Omega})$, birim örnek cevabının ($h[n]$) DTFT'sidir ve özel olarak frekans cevabı adını alır.
  - Giriş ayrık, $X(e^{j\Omega})$ ise süreklidir; bilgisayarda işlemek için bu da ayrıklaştırılır: $X[k]$, DFT ve onun hızlı algoritması FFT (sonraki dersin konusu).
- Temel DTFT çiftleri (ekrandan, 02:00:00, 02:05:00, 02:10:00)
  - $\delta[n]\ \rightarrow\ 1$ (bütün frekanslarda eşit genlik).
  - $\delta[n-n_0]\ \rightarrow\ e^{-jn_0\Omega}$.
  - $x[n]=1\ \rightarrow\ 2\pi\,\delta(\Omega)$ (yalnız DC bileşen).
  - $e^{jn\Omega_0}\ \rightarrow\ 2\pi\,\delta(\Omega-\Omega_0)$.
  - $\cos(n\Omega_0)\ \rightarrow\ \pi\,\delta(\Omega+\Omega_0)+\pi\,\delta(\Omega-\Omega_0)$.
- DTFT özellikleri (ekrandan, 02:15:00 ve 02:20:00)
  - Periyodiklik: $X(e^{j\Omega})=X(e^{j(\Omega+2\pi)})$; simetri.
  - Doğrusallık: $a\,x[n]+b\,y[n]\ \rightarrow\ a\,X(e^{j\Omega})+b\,Y(e^{j\Omega})$.
  - Öteleme: $x[n-n_0]\ \rightarrow\ e^{-jn_0\Omega}X(e^{j\Omega})$.
  - Zamanda ters çevirme: $x[-n]\ \rightarrow\ X(e^{-j\Omega})$.
  - Modülasyon: $x[n]\,e^{jn\Omega_0}\ \rightarrow\ X(e^{j(\Omega-\Omega_0)})$.
  - Konvolüsyon: $x[n]*y[n]\ \rightarrow\ X(e^{j\Omega})\,Y(e^{j\Omega})$.
  - Çarpım: $x[n]\,y[n]\ \rightarrow\ \dfrac{1}{2\pi}\int_{-\pi}^{\pi}X(e^{j\theta})\,Y(e^{j(\Omega-\theta)})\,d\theta$ (sürekli/periyodik konvolüsyon).
  - Parseval teoremi: $\sum_{n=-\infty}^{\infty}|x[n]|^2=\dfrac{1}{2\pi}\int_{-\pi}^{\pi}|X(e^{j\Omega})|^2\,d\Omega$.

## Hocanın Özellikle Vurguladığı Kısımlar

- Frekans uzayına geçmenin kazancı
  - Zaman domenindeki $h[n]$ örneklerinden sistemin nasıl davrandığı anlaşılmaz. $H(e^{j\Omega})$ çizilince sistemin hangi frekansları geçirip hangilerini bastırdığı, yani bir filtre gibi davrandığı açıkça görülür.
- $e^{j\Omega}$ gördüğünüzde sinüzoid düşünün
  - Kompleks üstel, kosinüs (gerçek kısım) ve sinüs (sanal kısım) bileşenleri olan bir sinüzoiddir. Doppler ve ultrason gibi işaretlerin doğası kompleks olduğundan işaret işlemede bu gösterim daha genel ve avantajlıdır.
- Euler eşitliği bilinmeli
  - Hoca derste Euler eşitliğini öğrencilere sordu ve bunun temel bir bilgi olduğunu, derslere çalışılması gerektiğini vurguladı.
- Periyodiklik ve simetri sonucu
  - Frekans cevabını yalnız temel periyotta, hatta $[0,\pi]$ aralığında incelemek yeterlidir.
- Konvolüsyon-çarpım ikiliği
  - Zaman domenindeki konvolüsyon frekans domeninde basit bir çarpmaya dönüşür; zamandaki çarpım ise frekansta konvolüsyona dönüşür. Frekansa geçmenin en önemli yararlarından biri budur.
- Kosinüs yerine kompleks üstel kullanmanın nedeni
  - $\cos(n\Omega_0)$'ın DTFT'sinde $\pm\Omega_0$'da iki atım, $e^{jn\Omega_0}$'ın DTFT'sinde ise yalnız $\Omega_0$'da tek atım vardır; kompleks üstel daha sade bir gösterimdir.
- Modülasyonun günlük hayattaki karşılığı
  - Radyo yayınları ve cep telefonları, işaretleri farklı frekanslara kaydırarak (modülasyon) frekans bantlarını verimli kullanır ve farklı kanallar oluşturur.
- Derin öğrenmeyle bağlantı
  - Konvolüsyonel ağlarda uygulanan filtreler de aslında farklı frekanslara farklı cevaplar üreterek öz nitelik çıkarır.

## Kısa Tekrar Notları

- $y[n]=x[n]*h[n]$; uzunluk $L_x+L_h-1$.
- Her işaret sinüzoidlerin toplamıdır; $f=0$ bileşeni DC'dir.
- Frekans uzayı zaman bilgisini kaybettirir; yalnız hangi frekansların ne kadar bulunduğunu gösterir.
- Frekans cevabı: $H(e^{j\Omega})=\sum_k h[k]e^{-jk\Omega}$.
- Euler: $e^{jx}=\cos x+j\sin x$.
- $H(e^{j\Omega})$: kompleks, $2\pi$ periyodik, $h[n]$ gerçekse konjüge simetrik.
- Genlik $|H|$, faz $\arctan(\mathrm{Im}/\mathrm{Re})$.
- İdeal alçak geçirenin impuls cevabı: $h[n]=\sin(n\Omega_c)/(\pi n)$ (sinc).
- Dört filtre: alçak geçiren, yüksek geçiren, bant geçiren, bant durduran.
- DTFT: $X(e^{j\Omega})=\sum_n x[n]e^{-jn\Omega}$; ters DTFT $\frac{1}{2\pi}\int_{-\pi}^{\pi}X(e^{j\Omega})e^{jn\Omega}d\Omega$.
- $\delta[n]\to1$, $\delta[n-n_0]\to e^{-jn_0\Omega}$, $1\to2\pi\delta(\Omega)$, $e^{jn\Omega_0}\to2\pi\delta(\Omega-\Omega_0)$, $\cos n\Omega_0\to\pi[\delta(\Omega+\Omega_0)+\delta(\Omega-\Omega_0)]$.
- Zamanda konvolüsyon = frekansta çarpım; zamanda çarpım = frekansta (periyodik) konvolüsyon.
- Parseval: zamandaki enerji = frekanstaki enerji (enerjinin korunumu).
- Sonraki adım: $X(e^{j\Omega})$'nın ayrıklaştırılması (DFT, FFT).

## Detaylı Açıklamalar

Ders, önceki haftanın konvolüsyon konusunun kısa bir tekrarıyla başladı. LSI bir sistemin çıkışı, girişin sistemin birim örnek cevabı $h[n]$ ile konvolüsyonudur. Bu işlem zaman domeninde yapılır: aslında elimizde sürekli bir işaretten alınmış ayrık örnekler vardır. Konvolüsyonun yükü dizilerin uzunluğuyla büyür; çıkış $L_x+L_h-1$ uzunluğundadır ve her çıkış örneği için ayrı çarpma ve toplamalar gerekir. Hoca buradan "işaretleri farklı bir uzayda incelemek mümkün mü?" sorusuna geçti; cevap Fourier analizidir.

Fourier'in temel fikri, herhangi bir işaretin farklı frekans ve genlikteki sinüzoidlerin toplamı olarak yazılabilmesidir. Tahtada $x(t)=\int_0^\infty A_f\cos(2\pi f t)\,df$ biçiminde, sıfırdan sonsuza giden bir "sonsuz toplam" yazıldı. Sıfır frekanslı terim sabittir ve DC bileşen adını alır. Bu bileşenlerin genliklerini frekansa karşı çizersek işaretin frekans içeriğini görürüz. Gerçek işaretler bir $f_{max}$ frekansının üstünde bileşen taşımaz; $0$-$f_{max}$ aralığı işaretin frekans bandıdır. Zaman domeninde işaretin değişimlerini, frekans uzayında ise içerdiği frekansları görürüz. Örneğin işaretin bir bölgesinde hızlı bir salınım varsa frekans grafiğinde yüksek bir frekansta tepe görülür, ama bu salınımın ne zaman olduğu bilgisi kaybolur.

<!-- BELİRSİZ: Hoca Fourier gösteriminde önce sin(ωt), sonra cos(2πf) yazdı; tahtada 2πf ifadesinin yanında t görünmüyor. Doğru gösterim büyük olasılıkla cos(2πft)'dir. -->

Sistem tarafında, $h[n]$ sistemin impulslara verdiği cevaptı. Girişteki işaret sinüzoidlerin toplamı olduğuna göre, sistemin her bir frekansa nasıl davrandığını bilirsek buna frekans cevabı denir: $H(e^{j\Omega})=\sum_k h[k]e^{-jk\Omega}$. Burada $H(f)$ yerine $H(e^{j\Omega})$ yazılır; $e^{j\Omega}$ frekansın daha genel bir gösterimidir. $k$ değiştikçe $e^{-jk\Omega}$ farklı frekanslı taban fonksiyonları üretir. Hoca bu toplamı bir benzerlik ölçüsü olarak anlattı: işaret, çarpıldığı sinüzoide benziyorsa çarpımın altında kalan alan büyük ve pozitif olur; işarette bulunmayan bir frekansla çarpılırsa alanlar bir süre sonra birbirini götürür.

Kompleks sayı tekrarında Euler eşitliği hatırlatıldı. $e^{-jx}$ açılırken kosinüsün çift ($f(x)=f(-x)$), sinüsün tek ($f(-x)=-f(x)$) olduğu kullanılır: $e^{-jx}=\cos x-j\sin x$. Bu yüzden $H(e^{j\Omega})$ gerçek ve sanal kısımlardan oluşan kompleks bir değerdir ve polar biçimde $|H(e^{j\Omega})|e^{j\theta_H}$ olarak yazılabilir.

> **Ders sonrası not:** Hoca tahtada $e^{-jx}$ açılımını yazarken kosinüs ve sinüsün içine fazladan $j$ koydu ($\cos(jx)$, $\sin(jx)$); kendisi "buradaki j'ler olmayacak" diyerek düzeltti. Doğrusu $e^{-jx}=\cos x-j\sin x$ ve $e^{-jk\Omega}=\cos(k\Omega)-j\sin(k\Omega)$'dır (ekrandan, 00:50:00).

Frekans cevabının üç özelliği işlendi. Birincisi kompleks değerli olmasıdır. İkincisi $2\pi$ ile periyodikliktir: $n$ tam sayı olduğundan $e^{jn2\pi}=1$ olur ve frekansa $2\pi$ eklemek hiçbir şeyi değiştirmez. Üçüncüsü simetridir: $h[n]$ gerçek değerliyse $H(e^{-j\Omega})=H^*(e^{j\Omega})$ olur, yani gerçek kısım ve genlik $\Omega=0$ eksenine göre simetriktir. Bu iki özellik yüzünden yalnız $[-\pi,\pi]$, hatta $[0,\pi]$ aralığına bakmak yeterlidir. Kompleks değerden iki grafik çıkar: genlik cevabı ve faz cevabı. Sistemin frekanslara davranışını görmek için daha çok genlik cevabı kullanılır. Ters dönüşüm formülüyle $H(e^{j\Omega})$'dan $h[n]$ geri elde edilebilir.

İdeal alçak geçiren filtre örneğinde $|\Omega|\le\Omega_c$ bölgesi 1, geri kalanı 0 olan bir frekans cevabı verildi. Ters dönüşüm integrali yalnız $[-\Omega_c,\Omega_c]$ aralığında katkı verir ve sonuç $h[n]=\sin(n\Omega_c)/(\pi n)$ olur; bu sönümlenen bir sinc fonksiyonunun ayrık halidir. Hoca ayrıca genliği frekans arttıkça azalan bir cevap çizdi: böyle bir sistem düşük frekansları daha iyi geçirir, yüksek frekansların genliğini bastırır.

Bu noktada filtre kavramı tanımlandı ve frekans seçici dört filtre çizildi. Bant geçiren filtre için hoca öğrencilere yorum sordu; bir öğrenci "ara değer filtresi", bir başkası "iki değer arasındaki aralığı alan filtre" dedi, hoca da belli frekans aralıklarına bant dendiğini (örneğin 100 Hz ile 500 Hz arası) hatırlatarak "band pass filter" adını verdi. Bant durduran filtre için şebeke gürültüsü örneği verildi: işarete karışan 50 Hz'lik şehir şebeke frekansı, 48-52 Hz gibi dar bir bandı bastıran filtreyle temizlenebilir.

> **Ders sonrası not:** Hoca bant durduran filtreyi anlatırken "$\Omega_2$'den $\pi$'ye kadar olan alçak frekansı geçirmiş" dedi; tahtadaki çizime göre doğrusu, filtrenin $|\Omega|<\Omega_1$ alçak frekanslarını ve $\Omega_2<|\Omega|<\pi$ yüksek frekanslarını geçirdiğidir (ekrandan, 01:45:00).

Son bölümde aynı formül sistem yerine giriş işaretine uygulandı ve DTFT tanımlandı. Girişin frekans içeriği de öz nitelik çıkarmak için yararlıdır. DTFT ayrık bir diziden sürekli bir fonksiyon üretir; ters dönüşümde integral kullanılmasının nedeni budur. Bilgisayar sürekli fonksiyonu tutamayacağı için bir sonraki adım $X(e^{j\Omega})$'yı da ayrıklaştırmaktır: $X[k]$, DFT ve hızlı algoritması FFT. Temel diziler için DTFT çiftleri adım adım çıkarıldı. $\delta[n]$'nin DTFT'si 1'dir; bu, ideal bir impulsun bütün frekanslarda eşit genlikte bileşen taşıdığını gösterir. Hoca gerçek hayatta impulsun, genişliği $\varepsilon$ ve yüksekliği $1/\varepsilon$ olan, alanı 1 kalan kısa bir darbeyle ($\varepsilon\to0$) yaklaşıklanabileceğini söyledi. Kaydırılmış impulsun DTFT'si kompleks üstel $e^{-jn_0\Omega}$'dır. Sabit dizi yalnız $\Omega=0$'da $2\pi$ genlikli bir atım verir, yani yalnız DC bileşeni vardır. Kompleks üstel $\Omega_0$'da tek, kosinüs ise $\pm\Omega_0$'da $\pi$ genlikli iki atım verir.

> **Ders sonrası not:** Tahtada kosinüsün DTFT'si "$\pi\delta(\Omega+\Omega_0)+\pi(\Omega-\Omega_0)$" diye yazıldı; ikinci terimde $\delta$ eksiktir. Doğrusu $\pi\delta(\Omega+\Omega_0)+\pi\delta(\Omega-\Omega_0)$'dır (ekrandan, 02:10:00). Ayrıca bu atımlar (sabit dizi ve kompleks üstel için de) $[-\pi,\pi]$ aralığında yazılmıştır; DTFT $2\pi$ periyodik olduğu için tam ifade her $2\pi$'de tekrar eden atım dizisidir.

Ardından DTFT özellikleri sıralandı. Öteleme özelliğinde tahtada çarpan $e^{jn_0\Omega}$, modülasyonda sonuç $X(e^{-j(\Omega-\Omega_0)})$ diye yazıldı.

> **Ders sonrası not:** Öteleme özelliğinde doğru çarpan $e^{-jn_0\Omega}$'dır (hocanın biraz önce $\delta[n-n_0]$ için bulduğu sonuçla da tutarlı); modülasyonda doğru sonuç $X(e^{j(\Omega-\Omega_0)})$'dır (ekrandan, 02:15:00). Öteleme özelliği python ile sayısal olarak kontrol edildi.

Modülasyon, işaretin frekans domeninde $\Omega_0$ kadar kaydırılmasıdır; radyo vericileri ve cep telefonları farklı kanalları böyle oluşturur. Konvolüsyon özelliği, zamandaki konvolüsyonun frekansta çarpıma dönüştüğünü söyler; tersine, zamandaki çarpım frekansta periyodik konvolüsyon olur. Son olarak Parseval teoremi yazıldı: bir işaretin karesini almak enerjisini hesaplamaktır ve zaman domenindeki enerji frekans domenindeki enerjiye eşittir (enerjinin korunumu). Teorem python ile rastgele bir dizi üzerinde sayısal olarak doğrulandı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
