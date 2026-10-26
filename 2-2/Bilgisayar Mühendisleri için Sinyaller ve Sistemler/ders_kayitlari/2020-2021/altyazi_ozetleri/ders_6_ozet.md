# Ders 6 Çalışma Özeti

## Genel Konular

- Dersin tarihi 14 Ağustos 2021 Cumartesi (öğleden sonra oturumu). Ders Zoom üzerinden yapıldı.
  - Asıl ders yaklaşık 00:07'de başlar. İlk dakikalar quiz ve ödevin sistemde yayınlanıp yayınlanmadığının kontrolüdür.
- Dersin genel haritası
  - Ayrık (dijital) taraf: $n$, köşeli parantez, konvolüsyon toplamı, fark denklemi, z dönüşümü, ayrık zamanlı Fourier dönüşümü (DTFT).
  - Sürekli (analog) taraf: $t$, normal parantez, konvolüsyon integrali, diferansiyel denklem, Laplace dönüşümü, Fourier dönüşümü.
- Frekans düzlemine geçiş
  - Temel frekans (fundamental frequency) ve temel periyot.
  - Frekans analizinin faydası: gürültü temizleme, müzik tanıma (Shazam), ses sentezi.
- Örnekleme (sampling) ve örtüşme (aliasing)
  - Nyquist kuralı ve $t = nT_s$ dönüşümü.
- Periyodik ve periyodik olmayan işaretler
  - Periyodik işarete Fourier serisi, periyodik olmayan işarete Fourier dönüşümü uygulanır.
- Fourier serisi
  - Herhangi bir periyodik işaretin sinüzoidlerin toplamı olarak yazılması.
  - Üç gösterim: genlik-faz, karmaşık üstel, sinüs-kosinüs.
  - Gösterimler arası dönüşüm formülleri ve bir örnek.
  - $c_k$ katsayılarının integralle bulunması. Kare dalga örneği.
- Quiz bilgisi ve vize duyurusu.

## Hocanın Özellikle Vurguladığı Kısımlar

- Temel frekans, frekans bileşenlerinin en büyük ortak böleni (EBOB) ile bulunur.
- Örnekleme frekansı en yüksek frekans bileşeninin en az iki katı olmalıdır.
  - Böylece örtüşme önlenir ve işaret geri elde edilebilir.
  - Bu yüzden örnekleme için bile önce frekans düzlemine bakmak gerekir.
- Periyodik bir işarete Fourier dönüşümü uygulamak gereksiz iş yüküdür. Bir periyot üzerinde Fourier serisi yeterlidir.
- Gösterimler arası dönüşüm formüllerini bir kenara not edin.
  - Sınavda formül kağıdında verilir ama hızlı kullanmak işinize yarar.
- Örneklerde önce $c_k$'ları bulup, sonra $a_k$ ve $b_k$'ya geçmek daha pratiktir.
- Bu ders üst üste kurulur: Fourier serisini anlarsanız Fourier dönüşümünü, onu anlarsanız Laplace'ı anlarsınız.
- Formüller karmaşık görünebilir ama lise matematiğiyle yerine koyarak gidilir. Birkaç alıştırma yeterlidir.
- Vize gelecek hafta Cumartesi öğleden sonra yapılacak.
  - Fourier serileri ve Çarşamba günü işlenecek konular dahil.
  - 4 veya 5 soru, 80-90 dakika, klasik.

## Kısa Tekrar Notları

- Temel frekans: $f_0 = \text{EBOB}(f_1, f_2, \ldots, f_n)$. Bileşenler $f_k = k f_0$.
  - Örnek: $10, 20, 40$ Hz $\Rightarrow f_0 = 10$ Hz. $f_3 = 30$ Hz bileşeninin genliği sıfırdır.
- Temel periyot: $T_0 = \dfrac{1}{f_0} = \dfrac{2\pi}{\omega_0}$.
- Nyquist: $f_s \ge 2 f_{max}$. Örnekleme: $t = nT_s = \dfrac{n}{f_s}$.
  - Ses için $f_s = 44100$ Hz $\Rightarrow$ $22050$ Hz'e kadar bileşenler korunur.
- Periyodik işaret: her $t$ için $x(t) = x(t+T)$; ayrık için $x[n] = x[n+N]$.
- Fourier serisi gösterimleri:
  - Genlik-faz: $x(t) = A_0 + \sum_{k=1}^{\infty} A_k \cos(k\omega_0 t + \theta_k)$.
  - Karmaşık üstel: $x(t) = \sum_{k=-\infty}^{\infty} c_k\, e^{jk\omega_0 t}$.
  - Sinüs-kosinüs: $x(t) = a_0 + \sum_{k=1}^{\infty} \left[a_k \cos(k\omega_0 t) + b_k \sin(k\omega_0 t)\right]$.
- Dönüşüm formülleri:
  - $c_0 = a_0 = A_0$.
  - $c_k = \tfrac{1}{2} A_k e^{j\theta_k}$, $c_{-k} = \tfrac{1}{2} A_k e^{-j\theta_k} = c_k^*$.
  - $a_k = 2\,\text{Re}\{c_k\} = A_k \cos\theta_k$, $b_k = -2\,\text{Im}\{c_k\} = -A_k \sin\theta_k$.
  - $A_k = \sqrt{a_k^2 + b_k^2}$, $\theta_k = \arctan\!\left(\dfrac{-b_k}{a_k}\right)$.
- Katsayı integralleri (bir periyot üzerinde):
  - $c_k = \dfrac{1}{T}\int_{t_0}^{t_0+T} x(t)\, e^{-jk\omega_0 t}\, dt$.
  - $c_0 = \dfrac{1}{T}\int_{t_0}^{t_0+T} x(t)\, dt$ (DC bileşen, işaretin ortalaması).
  - $a_k = \dfrac{2}{T}\int_T x(t)\cos(k\omega_0 t)\,dt$, $b_k = \dfrac{2}{T}\int_T x(t)\sin(k\omega_0 t)\,dt$.
- Euler formülü: $e^{\pm j\omega t} = \cos\omega t \pm j\sin\omega t$.

## Detaylı Açıklamalar

### Frekans düzlemi neden önemli?

- Zaman-genlik analizinin yanında frekans-genlik analizi de yapılabilir.
  - İşaret hakkında ek bilgi verir. Bazı işlemleri kolaylaştırır.
- Gürültü temizleme örneği:
  - Zaman düzleminde gürültüyü silmeye çalışmak (ör. ortalama filtresi) orijinal işareti bozabilir.
  - Doğal işaretlerde düşük frekanslı bileşenler baskındır. Yüksek frekanslarda genlik giderek söner.
  - Gürültü olağan dışı bir frekansta bir bileşen olarak görünür. O bileşenin genliği sıfıra çekilerek gürültü temizlenir.
- Shazam örneği:
  - Uygulama kısa bir ses kaydından şarkıyı tanır.
  - Zaman düzleminde eşleştirme girişim ve gürültü yüzünden zordur. Frekans düzlemindeki baskın bileşenler bir parmak izi gibi kullanılır.
- Kare dalga, sinüzoidlerin toplamıyla yaklaşık elde edilebilir.
  - 1 Hz'lik kare dalga için 1, 3, 5, 7, 9 Hz bileşenleri toplanır.
  - Süreksizlik noktalarında oluşan sivri taşmaya Gibbs olayı denir.

### Örnekleme ve örtüşme

- Örnekleme, analog $x(t)$'den ayrık $x[n]$ elde etmektir.
- Örnekleme frekansı en yüksek frekansın en az iki katı olmalıdır: $f_s \ge 2 f_{max}$.
  - Aksi halde frekanslar birbirine karışır (örtüşme, aliasing) ve işaret sağlıklı geri elde edilemez.
- Dönüşüm: $t$ yerine $n T_s = n / f_s$ yazılır. Böylece $t$ düzleminden $n$ düzlemine geçilir.
  - Örnek: $f_s = 1000$ Hz ise $t = n/1000$.
- $f_{max}$'ı bilmek için işaretin frekans içeriğine bakmak gerekir. Bu yüzden örnekleme de frekans analizine dayanır.

### Fourier serisi: fikir

- Fourier'in fikri: periyodik bir işaret sonsuz sayıda sinüzoidin toplamıyla yazılabilir.
- Periyodik olmayan bir işaret de, periyodu $-\infty$'dan $+\infty$'a uzanan bir işaret gibi düşünülebilir. Fourier dönüşümü bu fikirden çıkar. Laplace ve z dönüşümleri de bunun genelleştirilmiş halleridir.
- Sinüzoidler neden seçilir?
  - Doğal olarak periyodiktirler.
  - Sonsuz kez türevlenebilirler.
  - Doğal işaretlere çok yakındırlar (mikrofonu hoparlöre yaklaştırınca çıkan tiz ses neredeyse saf sinüzoiddir).
  - Genlik, frekans ve faz bilgileri doğrudan okunur.
- Diferansiyel denklemli bir sisteme sinüzoidal giriş verilince türevler cebirsel çarpanlara dönüşür. Bu, sistem analizini kolaylaştırır.
- Asıl iş analizdir: işaretten $\omega_0$, $c_k$ (veya $a_k$, $b_k$) ve faz bilgilerini bulmak. Katsayılar biliniyorsa sentez (işareti geri oluşturmak) kolaydır.
- DC bileşen: frekansı sıfır olan bileşendir ($A_0$ veya $c_0$). İşaretin bir periyottaki ortalamasıdır.

### Gösterimler arası dönüşüm örneği

- Slayttaki işaret: $x(t) = \cos(t) + 0.5\cos(4t + \pi/3) + 0.25\cos(8t + \pi/2)$.
  - $\omega_0 = \text{EBOB}(1, 4, 8) = 1$.
  - $A_1 = 1,\ \theta_1 = 0$; $A_4 = 0.5,\ \theta_4 = \pi/3$; $A_8 = 0.25,\ \theta_8 = \pi/2$. Diğer $A_k$'lar sıfır.
- Karmaşık üstel form ($c_k = \tfrac{1}{2}A_k e^{j\theta_k}$):
  - $c_{\pm 1} = 0.5$, $c_{\pm 4} = 0.25\,e^{\pm j\pi/3}$, $c_{\pm 8} = 0.125\,e^{\pm j\pi/2}$.
- Sinüs-kosinüs form ($a_k = A_k\cos\theta_k$, $b_k = -A_k\sin\theta_k$):
  - $a_1 = 1,\ b_1 = 0$.
  - $a_4 = 0.25,\ b_4 = -0.433$.
  - $a_8 = 0,\ b_8 = -0.25$.
  - $x(t) = \cos t + 0.25\cos 4t - 0.433\sin 4t - 0.25\sin 8t$.

### Örnek: kare dalganın Fourier serisi

- İşaret: periyodu $T = 2$ olan kare dalga. $0 \le t < 1$ için $x(t) = 1$, $1 \le t < 2$ için $x(t) = 0$.
- $f_0 = 1/2$ Hz, $\omega_0 = 2\pi f_0 = \pi$ rad/s.
- Bir periyot üzerinde ($0$'dan $2$'ye) integral yeterlidir. $1$ ile $2$ arası sıfır olduğu için integral yalnız $0$-$1$ arasında kalır:
  - $c_k = \dfrac{1}{2}\int_0^1 e^{-jk\pi t}\,dt = \dfrac{1 - e^{-jk\pi}}{2jk\pi}$.
- $e^{-jk\pi} = \cos k\pi - j\sin k\pi = (-1)^k$ olduğu için:
  - $k$ çift ve sıfırdan farklı: $c_k = 0$.
  - $k$ tek: $c_k = \dfrac{2}{2jk\pi} = \dfrac{-j}{k\pi}$.
- DC bileşen: $c_0 = \dfrac{1}{2}\int_0^1 1\,dt = \dfrac{1}{2}$.
- Sinüs-kosinüs forma geçiş:
  - $a_k = 2\,\text{Re}\{c_k\} = 0$ (kosinüs bileşeni yok).
  - $k$ tek için $b_k = -2\,\text{Im}\{c_k\} = \dfrac{2}{k\pi}$.
- Sonuç: $x(t) = \dfrac{1}{2} + \dfrac{2}{\pi}\left[\sin(\pi t) + \dfrac{1}{3}\sin(3\pi t) + \dfrac{1}{5}\sin(5\pi t) + \cdots\right]$.
  - DC terim çıkarılınca kalan kısım tek fonksiyondur. Bu yüzden yalnızca sinüs terimleri vardır.
- Hoca bir sonraki derste bu katsayılarla MATLAB'de kare dalgaya yakın bir işaret sentezleyeceğini söyledi.
- İleride bir ses sentezi ödevi verilecek: verilen $A_k$ ve $\theta_k$'larla 5-6 frekans bileşeni toplanıp bir ses oluşturulacak.

### Quiz ve vize

- Quiz bugün 15:20'de açılıyor. Süre 30 dakika.
- Vize gelecek Cumartesi (21 Ağustos 2021) öğleden sonra.
  - Çarşamba günü işlenecek konular da dahil. Belki soru çözümü yapılacak.
  - 4 veya 5 soru, 80-90 dakika, klasik.

### Ders sonrası notlar

- Derste DVD ses kalitesindeki örnekleme frekansı net söylenmedi. DVD-Video seslerinde genellikle $48$ kHz (bazen $96$ kHz) kullanılır. CD kalitesi $44.1$ kHz'dir.
- Hoca integral sonucunu anlatırken bir yerde "$\frac{j}{2k\pi}(e^{-jk\pi} - 1)$" şeklinde bir ifade söyledi. Doğru ara sonuç: $c_k = \dfrac{1 - e^{-jk\pi}}{j2k\pi}$. Bu ifade tek $k$ için $-j/(k\pi)$, çift $k$ için $0$ verir. Hocanın son sonuçları doğrudur.
- Hoca örnekteki üçüncü bileşenin genliğini sözlü olarak "0.3" diye okudu. Slaytta $A_8 = 0.25$'tir.
- Slayttaki sinüs-kosinüs sonucunda iki işaret hatası var:
  - Slaytta $b_4 = 0.43$ yazıyor, ama aynı slayttaki formüle göre $b_4 = -A_4\sin\theta_4 = -0.433$'tür. Slayttaki son ifadede terim zaten $-0.43\sin 4t$ olarak doğru yazılmış.
  - Slaytta $b_8 = 0.25$ ve terim $+0.25\sin 8t$ yazıyor. Oysa $0.25\cos(8t + \pi/2) = -0.25\sin 8t$'dir. Doğrusu $b_8 = -0.25$'tir.
  - İki ifadenin eşitliği Python ile sayısal olarak doğrulandı.
- Kare dalga katsayıları sayısal integralle doğrulandı: $b_1 = 2/\pi \approx 0.6366$, $b_3 \approx 0.2122$, $b_5 \approx 0.1273$; çift $k$'lar için $c_k = 0$.
- Derste "$c_k$ integrali bir konvolüsyondur" dendi. Daha doğrusu bu bir iç çarpım (korelasyon) işlemidir: işaret, $e^{-jk\omega_0 t}$ ile çarpılıp bir periyot boyunca integre edilir. Ters çevirme ve kaydırma yoktur.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.
