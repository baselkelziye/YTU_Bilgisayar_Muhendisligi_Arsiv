# Ders 9 Çalışma Özeti

## Genel Konular

- Dersin tarihi 21 Ağustos 2021 Cumartesi (öğleden sonra oturumu). Ders Zoom üzerinden yapıldı.
  - Asıl ders yaklaşık 00:06'da başlar. Aynı gün öğleden sonra vize yapıldı.
  - Kaydın son kısmı (yaklaşık 01:18'den sonra) vize kuralları ve soruların açıklamasıdır.
- Fourier dönüşümü (Fourier transform) çiftleri
  - $\delta(t)$, ötelenmiş $\delta(t-c)$, $\cos\omega_0 t$, $\sin\omega_0 t$, $e^{j\omega_0 t}$.
- Fourier dönüşümünün özellikleri
  - Doğrusallık, zamanda öteleme, ölçekleme, zamanda ters çevirme.
  - $t^n$ ile çarpma, modülasyon (karmaşık üstelle çarpma), türev, integral.
  - Konvolüsyon, zamanda çarpma, Parseval teoremi, dualite.
- Diferansiyel denklemin Fourier dönüşümüyle çözülmesi (örnek).
- Periyodik işaretin Fourier dönüşümü ve Fourier serisiyle ilişkisi.
- Uygulama: genlik modülasyonu ve demodülasyon.
- Fourier dönüşümünün var olmadığı durum: $e^{at}u(t)$, $a>0$.
- Ayrık konvolüsyonda sıfır noktasını bulmak için kısa yol.
- Ödev 1 teslimleri ve vize kuralları, vize sorularının açıklanması.

## Hocanın Özellikle Vurguladığı Kısımlar

- Fourier dönüşümü tablosu ve özellikleri sayesinde integral hesaplamadan birçok sonuca ulaşılır.
  - Hayati olan: Fourier integralini bilmek, tablodaki temel çiftler ve konvolüsyon, türev gibi özellikler. Ters Fourier integralini o kadar kullanmayacağız.
  - Sınavda tablolar çoğunlukla verilir; ezberlemek zorunda değilsiniz.
- Zamanda öteleme ve karmaşık üstelle çarpma (modülasyon) özellikleri çok önemlidir.
- Türev özelliği sayesinde diferansiyel denklemler cebirsel denklemlere dönüşür.
  - Türevden kurtulmadan giriş-çıkış ilişkisini bulamayız.
- Her işaretin Fourier dönüşümü yoktur. İntegral ıraksarsa dönüşüm yoktur, ama Laplace dönüşümü olabilir.
- Derse katılın. Yanlış yapmak ayıp değildir. Hoca anlatmadığı konudan soru sormadığını söyledi.
- Vize kuralları:
  - Cevaplarda ara işlemler gösterilmeli. Doğrudan yazılan sonuçlara puan verilmez.
  - Ayrık zaman ve sürekli zaman notasyonlarına dikkat edin (köşeli ve normal parantez). Puan kırma sebebi olabilir.
  - E-postayla gelen hiçbir şey kabul edilmez. Asıl teslim Online Yıldız'dır.

## Kısa Tekrar Notları

- Fourier dönüşümü: $X(\omega) = \int_{-\infty}^{\infty} x(t)\,e^{-j\omega t}\,dt$. $\omega = 2\pi f$ olduğu için $X(f)$ da yazılabilir.
- Ters dönüşüm: $x(t) = \dfrac{1}{2\pi}\int_{-\infty}^{\infty} X(\omega)\,e^{j\omega t}\,d\omega$.
- Temel çiftler:
  - $\delta(t) \leftrightarrow 1$.
  - $\delta(t-c) \leftrightarrow e^{-j\omega c}$.
  - $1 \leftrightarrow 2\pi\,\delta(\omega)$.
  - $e^{j\omega_0 t} \leftrightarrow 2\pi\,\delta(\omega - \omega_0)$.
  - $\cos\omega_0 t \leftrightarrow \pi\left[\delta(\omega-\omega_0) + \delta(\omega+\omega_0)\right]$.
  - $\sin\omega_0 t \leftrightarrow -j\pi\,\delta(\omega-\omega_0) + j\pi\,\delta(\omega+\omega_0)$.
  - $e^{-bt}u(t) \leftrightarrow \dfrac{1}{b + j\omega}$, $b > 0$.
  - $e^{at}u(-t) \leftrightarrow \dfrac{1}{a - j\omega}$, $a > 0$.
- Özellikler:
  - Doğrusallık: $a\,x(t) + b\,y(t) \leftrightarrow a\,X(\omega) + b\,Y(\omega)$.
  - Zamanda öteleme: $x(t-c) \leftrightarrow e^{-j\omega c} X(\omega)$.
  - Ölçekleme: $x(at) \leftrightarrow \dfrac{1}{|a|} X\!\left(\dfrac{\omega}{a}\right)$, $a \ne 0$.
  - Ters çevirme: $x(-t) \leftrightarrow X(-\omega)$.
  - $t^n$ ile çarpma: $t^n x(t) \leftrightarrow j^n \dfrac{d^n X(\omega)}{d\omega^n}$.
  - Modülasyon: $x(t)\,e^{j\omega_0 t} \leftrightarrow X(\omega - \omega_0)$.
  - $x(t)\cos\omega_0 t \leftrightarrow \tfrac{1}{2}\left[X(\omega-\omega_0) + X(\omega+\omega_0)\right]$.
  - Türev: $\dfrac{d^n x(t)}{dt^n} \leftrightarrow (j\omega)^n X(\omega)$.
  - İntegral: $\int_{-\infty}^{t} x(\lambda)\,d\lambda \leftrightarrow \dfrac{X(\omega)}{j\omega} + \pi X(0)\,\delta(\omega)$.
  - Konvolüsyon: $x(t) * h(t) \leftrightarrow X(\omega)\,H(\omega)$.
  - Zamanda çarpma: $x(t)\,y(t) \leftrightarrow \dfrac{1}{2\pi}\,X(\omega) * Y(\omega)$.
  - Dualite: $X(t) \leftrightarrow 2\pi\,x(-\omega)$.
- Periyodik işaret: $x(t) = \sum_k c_k e^{jk\omega_0 t} \leftrightarrow X(\omega) = 2\pi\sum_k c_k\,\delta(\omega - k\omega_0)$.

## Detaylı Açıklamalar

### Temel Fourier dönüşüm çiftleri

- $\delta(t)$'nin dönüşümü:
  - $\int \delta(t)\,e^{-j\omega t}\,dt$ integralinde yalnız $t = 0$ noktası katkı verir.
  - Sonuç $e^{0} = 1$'dir. Spektrum her frekansta sabit $1$'dir. Faz sıfırdır.
- Ötelenmiş dürtü $\delta(t-c)$:
  - Yalnız $t = c$ noktası katkı verir. Sonuç $e^{-j\omega c}$'dir.
  - Burada $\omega$ bir değişkendir. Periyodik olmayan işaretlerde her frekans olabilir. Bu yüzden $\omega$ yerine sayı yazmayız. Fourier serisinden farkı budur.
- Kosinüs: $\pm\omega_0$'da iki dürtü, ikisinin de ağırlığı $\pi$'dir.
- Sinüs: $\pm\omega_0$'da iki dürtü, ağırlıkları $-j\pi$ ve $+j\pi$'dir.
- Faz ötelemeli kosinüs $\cos(\omega_0 t + \theta)$: kosinüsün dönüşümündeki dürtüler $e^{\pm j\theta}$ ile çarpılır.

### Özellikler neden işe yarar?

- Elimizde $X(\omega)$ varken türevin dönüşümünü bulmak için uzun yol: ters dönüşüm al, türev al, yeniden dönüşüm al.
- Türev özelliğiyle kısa yol: $X(\omega)$'yı $j\omega$ ile çarp.
- Zamanda öteleme: ötelenmiş işaretin dönüşümünü sıfırdan hesaplamak yerine $X(\omega)$'yı $e^{-j\omega c}$ ile çarparız.
- Ölçekleme: $x(2t)$ işareti zamanda sıkışır, frekans ekseninde genişler. Tersi de geçerlidir.
- $t^n x(t)$'nin dönüşümünü doğrudan hesaplamak zor bir integraldir. Özellik sayesinde $X(\omega)$'nın $n$. türevi alınıp $j^n$ ile çarpılır.
  - Örnek: $t^4$ için $j^4 = 1$'dir.
- Modülasyon: işareti $e^{j\omega_0 t}$ (veya kosinüs) ile çarpmak, spektrumu $\omega_0$ kadar kaydırır.
- Konvolüsyon: zaman düzleminde zor olan konvolüsyon integrali yerine $X(\omega) H(\omega)$ çarpılır, sonra ters dönüşüm alınır.

### Örnek: diferansiyel denklemin Fourier dönüşümüyle çözümü

- Sistem: $\dfrac{dy(t)}{dt} + 2y(t) = x(t) + \dfrac{dx(t)}{dt}$. Birim dürtü cevabı $h(t)$ isteniyor.
- İki tarafın Fourier dönüşümü alınır. Türev özelliğiyle:
  - $j\omega\,Y(\omega) + 2\,Y(\omega) = X(\omega) + j\omega\,X(\omega)$.
- Ortak parantez: $Y(\omega)(2 + j\omega) = X(\omega)(1 + j\omega)$.
- Frekans cevabı:
  - $H(\omega) = \dfrac{Y(\omega)}{X(\omega)} = \dfrac{1 + j\omega}{2 + j\omega} = 1 - \dfrac{1}{2 + j\omega}$.
- Tablodan ters dönüşüm:
  - $1 \leftrightarrow \delta(t)$ ve $\dfrac{1}{2 + j\omega} \leftrightarrow e^{-2t}u(t)$.
  - $h(t) = \delta(t) - e^{-2t}u(t)$.
- Diferansiyel denklem klasik yöntemlerle çözülmeden giriş-çıkış ilişkisi bulunmuş olur.

### Periyodik işaretin Fourier dönüşümü

- Periyodik işaret Fourier serisiyle yazılır: $x(t) = \sum_k c_k e^{jk\omega_0 t}$.
- Toplamın dönüşümü alınır. Her $e^{jk\omega_0 t}$ terimi $2\pi\,\delta(\omega - k\omega_0)$ verir.
- Sonuç: spektrum, $k\omega_0$ noktalarında ağırlığı $2\pi c_k$ olan dürtülerden oluşur.
- Böylece Fourier serisi katsayıları Fourier dönüşümüyle de bulunabilir.

### Uygulama: genlik modülasyonu

- Ses işaretini bir kanalda (kablo, anten) taşımak için işaret yüksek frekanslı bir kosinüsle çarpılır.
  - Çarpma, spektrumu $\pm\omega_0$ civarına kaydırır. İşaret kanalın taşıyabileceği frekans aralığına çekilmiş olur.
- Alıcıda işaret yeniden kosinüsle çarpılır (demodülasyon). Gereksiz yüksek frekanslı kopyalar atılır ve ses eski frekans aralığına geri gelir.

### Fourier dönüşümünün var olmadığı durum

- $x(t) = e^{at}u(-t)$, $a > 0$:
  - İntegral $-\infty$'dan $0$'a alınır: $X(\omega) = \int_{-\infty}^{0} e^{(a - j\omega)t}\,dt = \dfrac{1}{a - j\omega}$. Dönüşüm vardır.
- $x(t) = e^{at}u(t)$, $a > 0$:
  - İntegral $0$'dan $\infty$'a alınır. $e^{(a - j\omega)t}$ terimi $t \to \infty$ iken sonsuza gider.
  - İntegral ıraksar. Fourier dönüşümü yoktur. Bu tür işaretlerin Laplace dönüşümü vardır.

### Ayrık konvolüsyonda sıfır noktası için kısa yol

- İki işaretin $n=0$ noktalarındaki değerlerin çarpıldığı adım, sonucun $n=0$ noktasıdır.
- Örnek: $x[n] = \{1, \underline{2}, 1\}$ ($n = -1..1$), $h[n] = \{\underline{1}, 1\}$ ($n = 0..1$).
  - $y[n] = \{1, \underline{3}, 3, 1\}$, $n = -1..2$.
  - Sınırlar: alt sınır $-1 + 0 = -1$, üst sınır $1 + 1 = 2$.

### Ödev 1 teslimleri

- Ödev dosyasında dosya adı görünenlerin ödevi hocaya ulaşmıştır. Boş görünenlerin ödevi gelmemiştir.
- Yüklediğini iddia eden öğrenci başarılı yüklemenin ekran görüntüsünü gönderebilir. Kanıt yoksa ödev teslim edilmemiş sayılır.
- Grafik sonuçlarını rapora koymayanlardan puan kırılacak.

### Vize kuralları ve sorular

- Sınav dosyası Word belgesi olarak verildi. Süre 95 dakika. Soru sayısı beşten dörde indirildi.
- Cevaplar kağıda yazılıp fotoğrafı her sorunun altındaki boşluğa eklenecek. İsterseniz çıktı alıp elle doldurabilirsiniz.
  - Kurşun kalem kullanın. Yazılar okunaklı olsun.
  - Her sayfanın altında isim, soyisim ve imza olacak.
- Teslim Online Yıldız'a Word dosyası olarak yapılacak. Kendi saatinize bakın; sistemin saati güncellenmeyebilir.
- Başarılı yüklemenin ekran görüntüsü kaydedilecek. Ekran görüntüsü ve sınav dosyası sınav belgesindeki Google Form linkine de yüklenecek.
  - Form yalnızca tedbir amaçlıdır. Sınavdan sonra en fazla 10 dakika açık kalır.
- Sorular (Türkçe ve İngilizce yan yana):
  1. Bir $x[n]$ ve $v(t)$'ye bağlı bir $y(t)$ işaretinin grafiklerini çizme (20 puan).
  2. $x[n]$ ve birim dürtü cevabı $h[n]$ için $y[n]$ konvolüsyonunu adım adım hesaplama.
  3. $x[n]$ işaretini birim dürtülerle yazma, grafiklerini çizme, tek ve çift bileşenlerini bulma, $y[n]$'nin enerjisini hesaplama.
  4. Periyodik bir $x(t)$ için temel frekans, DC değer, karmaşık Fourier serisi katsayıları ($c_k$), oradan $a_k$ ve $b_k$, DC ile ilk üç bileşenin frekans spektrumu.

### Ders sonrası notlar

- Hoca diferansiyel denklem örneğinde $h(t)$'ye birkaç kez "sistemin birim basamak cevabı (tepkisi)" dedi. $h(t)$ birim dürtü cevabıdır (impulse response). Birim basamak cevabı $s(t) = \int_{-\infty}^{t} h(\tau)\,d\tau$'dur. Bu örnekte $s(t) = \tfrac{1}{2}(1 + e^{-2t})\,u(t)$ olur.
- Hoca $\delta(t)$'nin dönüşümünü önce "$e^{-j\omega}$" dedi, sonra $1$ olarak düzeltti. Doğrusu $1$'dir.
- Hoca $e^{-j\omega c}$'nin spektrumunu "azalıp giden" bir eğri gibi çizdi. Bu doğru değildir. $|e^{-j\omega c}| = 1$'dir, yani genlik spektrumu her frekansta sabittir. Faz ise $-\omega c$ şeklinde doğrusal değişir.
- Sinüsün dönüşümünde işaretler: $+\omega_0$'daki dürtünün ağırlığı $-j\pi$, $-\omega_0$'daki dürtünün ağırlığı $+j\pi$'dir. Yani $\sin\omega_0 t \leftrightarrow \frac{\pi}{j}\left[\delta(\omega-\omega_0) - \delta(\omega+\omega_0)\right]$.
- İntegral özelliğinde dürtünün katsayısı $x(0)$ değil, $X(0)$'dır (dönüşümün $\omega = 0$'daki değeri, yani işaretin alanı).
- Hoca örneğe başlarken tabloyu "$e^{-bt}$ ↔ $1/(j\omega + b)$" diye okudu. Tam çift: $e^{-bt}u(t) \leftrightarrow \dfrac{1}{b + j\omega}$, $b > 0$.
- İnsan kulağının duyma aralığı yaklaşık $20$ Hz - $20$ kHz'dir (derste emin olunamadı).
- Derste AM radyo için "100 MHz" dendi. AM yayınları yaklaşık $0.5$-$1.7$ MHz aralığındadır. $100$ MHz civarı FM radyo bandıdır ($88$-$108$ MHz).
- Derste alıcının "ters Fourier dönüşümü alarak" sesi geri elde ettiği söylendi. Pratikte demodülasyon, işareti taşıyıcıyla yeniden çarpıp alçak geçiren filtreden geçirmektir. Fourier dönüşümü bu işlemi anlamak için kullanılan bir araçtır.
- Kısa yol örneğinde hoca ara değerleri bir an "2" diye okudu, sonra düzeltti. Doğru sonuç $\{1, 3, 3, 1\}$'dir (Python ile doğrulandı).
- Kayıtta yaklaşık 01:00 civarında hoca bir değişim öğrencisiyle not belgesi hakkında İngilizce konuşuyor. Bu kısım ders içeriği değildir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.
