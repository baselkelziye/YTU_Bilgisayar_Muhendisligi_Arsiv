# Ders 9 Çalışma Özeti

## Genel Konular

- Enterpolasyonun (ara değer uydurma) amacı ve kullanım alanları
  - Elde az sayıda $(x_i, y_i)$ nokta çifti varken bütün noktalardan geçen bilinen bir fonksiyon (genellikle polinom ya da sinüzoidal fonksiyon) bulunur, sonra noktalar arasındaki bilinmeyen değerler bu fonksiyonla tahmin edilir.
  - Noktalar tek boyutlu olmak zorunda değildir; çok boyutlu durumda doğru yerine bir yüzey oluşturulur.
  - Örnekler: düşük örnekleme hızıyla kaydedilmiş bir sesin örnek sayısını artırmak, bir görüntüyü yeniden boyutlandırmak (resize), telefonda fotoğrafa yakınlaştırma yapmak. Farklı resize yöntemleri farklı enterpolasyon yöntemleri kullanır.
  - Bulunan değer kesin değil tahmindir (prediction, estimation).
- Doğrusal enterpolasyon (hatırlatma)
  - İki noktadan geçen $y = mx + n$ doğrusu kurulur; $m$ eğim, $n$ sabit terimdir. İki bilinmeyen olduğu için iki nokta gerekir.
  - Ekrandaki formül: $F(x) = \dfrac{f(a)-f(b)}{a-b}\,x + \dfrac{b f(a) - a f(b)}{b-a}$ (ekrandan, 00:10:00).
- Eğrisel (kuadratik) enterpolasyon
  - $f(x) = ax^2 + bx + c$ için üç nokta gerekir (ekrandan, 00:20:00).
  - 1. yol: üç noktayı denklemde yerine koyup üç bilinmeyenli doğrusal denklem sistemini çözmek.
  - 2. yol: $f(x) = b_0 + b_1(x-x_0) + b_2(x-x_0)(x-x_1)$ biçimi (ekrandan, 00:25:00):
    - $b_0 = f(x_0)$
    - $b_1 = \dfrac{f(x_1)-f(x_0)}{x_1-x_0}$
    - $b_2 = \dfrac{\frac{f(x_2)-f(x_1)}{x_2-x_1} - \frac{f(x_1)-f(x_0)}{x_1-x_0}}{x_2-x_0}$
  - Programda polinom, katsayıları tutan bir `double` dizisiyle saklanabilir.
  - Kübik enterpolasyon da benzer biçimde kurulabilir ama derece arttıkça formülasyon zorlaşır.
- Gregory-Newton enterpolasyonu (eşit aralıklı $x$)
  - $F(x) = f_0 + \sum_{i=1}^{n} \binom{k}{i} \Delta^i f_0$, $k = \dfrac{x - x_0}{h}$ enterpolasyon değişkenidir, $\binom{k}{i} = \dfrac{k(k-1)\cdots(k-i+1)}{i!}$ (ekrandan, 00:30:00).
  - Açık hali: $F(x) = f_0 + \dfrac{x-x_0}{h}\Delta f_0 + \dfrac{(x-x_0)(x-x_1)}{h^2}\dfrac{\Delta^2 f_0}{2!} + \cdots$ (ekrandan, 00:40:00).
  - Önce ileri sonlu fark tablosu kurulur; tablonun en üst satırındaki değerler ($f_0, \Delta f_0, \Delta^2 f_0, \dots$) formüle konur.
  - Bir mertebede farklar sabitlenirse sonraki farklar sıfırdır, daha yüksek dereceli terim yazılmaz.
- Değişken dönüşümlü Gregory-Newton enterpolasyonu
  - $x$ değerleri eşit aralıklı değilse ama artışlarında bir düzen varsa (ör. 1, 3, 5, 7, 9) sıfırdan birer birer artan geçici bir $z$ değişkeni tanımlanır.
  - Önce $x = F(z)$ ilişkisi, sonra $f$'nin $z$'ye göre enterpolasyonu sonlu farklarla bulunur; en sonda $z$ yerine $x$ cinsinden ifadesi konur (ekrandan, 00:45:00).
- Lagrange enterpolasyonu
  - Noktaların aralıklarının eşit olması gerekmez (ekrandan, 01:10:00).
  - $g(x) = \sum_{i=0}^{n} L_i(x)\, y_i$, $L_i(x) = \prod_{j=0,\ j\ne i}^{n} \dfrac{x - x_j}{x_i - x_j}$.
  - $j \ne i$ şartı paydanın sıfır olmasını önler.

## Hocanın Özellikle Vurguladığı Kısımlar

- Enterpolasyonla bulunan değer bir tahmindir
  - "Bulmak" ya da "saptamak" değil, "tahmin etmek" denir; gerçek değer farklı olabilir. Yine de hiç değer bulamamaktansa tahmin yapmak doğrudur.
- Sonlu farklar sabitlenince durmak
  - Örnekte $\Delta^2 f$ sütunu hep 32 olunca $(x-6)$, $(x-8)$ gibi kökleri içeren terimlere gerek kalmaz; onların katsayısı olan üst mertebe farklar sıfırdır.
- Gregory-Newton yöntemi daha çok noktayı hesaba katar
  - Doğrusal enterpolasyon dokuz noktadan yalnız ikisini kullanırken, sonlu fark tablosu bütün noktaları işin içine katar.
- Lagrange enterpolasyonu genel bir yöntemdir
  - Değişken dönüşümüyle uğraşmadan her durumda kullanılabilir. Formülün nereden geldiğinin mantığını bilmek yeterlidir.

## Kısa Tekrar Notları

- Enterpolasyon: bütün noktalardan geçen fonksiyonla ara değer tahmini. Aralık dışına çıkmak ekstrapolasyondur.
- Doğrusal: 2 nokta; kuadratik: 3 nokta; kübik: 4 nokta.
- Kuadratik 2. yol: $b_0 = f(x_0)$, $b_1$ birinci bölünmüş fark, $b_2$ ikinci bölünmüş fark.
- Gregory-Newton: ileri sonlu fark tablosu, $k = (x-x_0)/h$, $h \ne 1$ ise $i$. terimin paydasında $h^i$ olur.
- Örnek ($h=1$): tablo $-4, -2, 14, 62, 160, 326, 578$ için $F(x) = 3x^3 - 2x^2 + x - 4$, $F(4) = 160$.
- Örnek ($h=2$): tablo $10, 50, 122, 226, 362$ için $F(x) = 4x^2 - 4x + 2$, $F(8) = 226$.
- Eşit aralıklı olmayan ama düzenli artan $x$ için değişken dönüşümü: $z = 0, 1, 2, \dots$
- Lagrange: $g(x) = \sum y_i L_i(x)$, $L_i(x) = \prod_{j\ne i} \frac{x-x_j}{x_i-x_j}$.
- Lagrange örneği: $(0,-5), (1,1), (3,25)$ için $g(2) = 11$.

## Detaylı Açıklamalar

- **Kuadratik enterpolasyon örneği (derste sözlü).** Üç noktadan ilki $x_0 = 1$, $f(x_0) = -2$ olarak verildi. Hesapta $b_0 = -2$, $b_1 = 1$, $b_2 = 2$ bulundu. Böylece $f(x) = -2 + (x-1) + 2(x-1)(x-2) = 2x^2 - 5x + 1$ olur ve $x = 2.5$ için tahmin $f(2.5) = 1$ çıkar (ara adım eklendi, python ile kontrol edildi). <!-- BELİRSİZ: Örneğin nokta tablosu ekranda vardı ama o ana ait kare yok; diğer noktaların değerleri altyazıdan okunamadı. Katsayılardan geri hesaplanınca noktalar (1,-2), (2,-1), (3,4) çıkıyor. -->
- **Gregory-Newton, $h = 1$ (ekrandan, 00:35:00).** Tablo: $x = 0..6$, $f(x) = -4, -2, 14, 62, 160, 326, 578$. Sonlu farklar: $\Delta f = 2, 16, 48, 98, 166, 252$; $\Delta^2 f = 14, 32, 50, 68, 86$; $\Delta^3 f = 18$ (sabit). Formül: $F(x) = -4 + 2\dfrac{x}{1!} + 14\dfrac{x(x-1)}{2!} + 18\dfrac{x(x-1)(x-2)}{3!} = 3x^3 - 2x^2 + x - 4$. Test: $F(4) = 160$. $x = 3.5$ enterpolasyon, $x = 8.5$ ekstrapolasyon olur.
- **Gregory-Newton, $h = 2$ (ekrandan, 00:40:00).** Tablo: $x = 2, 4, 6, 8, 10$, $f(x) = 10, 50, 122, 226, 362$. $\Delta f = 40, 72, 104, 136$; $\Delta^2 f = 32$ (sabit). $F(x) = 10 + \dfrac{x-2}{2}\cdot 40 + \dfrac{(x-2)(x-4)}{4}\cdot\dfrac{32}{2!} = 10 + 20(x-2) + 4(x-2)(x-4) = 4x^2 - 4x + 2$. Test: $F(8) = 226$.
- **Değişken dönüşümü (ekrandan, 00:45:00).** $x = -1, 0, 3, 8, 15, 24$, $f(x) = 2, 1, 10, 65, 226, 577$. $x$ farkları $1, 3, 5, 7, 9$, ikinci farklar sabit 2. $z = 0..5$ alınınca $x = -1 + z + 2\dfrac{z(z-1)}{2} = z^2 - 1$. $f$ için farklar: $\Delta f_0 = -1$, $\Delta^2 f_0 = 10$, $\Delta^3 f_0 = 36$, $\Delta^4 f_0 = 24$ (sabit). $f(z) = 2 - z + 10\frac{z(z-1)}{2!} + 36\frac{z(z-1)(z-2)}{3!} + 24\frac{z(z-1)(z-2)(z-3)}{4!} = z^4 - 2z^2 + 2$. $z^2 = x + 1$ konunca $f(x) = x^2 + 1$ bulunur ($8^2 + 1 = 65$).
- **Eşit aralıklı veride iki yol (ekrandan, 00:50:00).** $x = 2, 4, 6, 8, 10$, $f(x) = 3, 7, 19, 39, 67$. Dönüşümle $x = 2 + 2z$, $z = \frac{x-2}{2}$, $f(z) = 3 + 4z + 8\frac{z(z-1)}{2!} = 4z^2 + 3$ ve $f(x) = x^2 - 4x + 7$. Dönüşümsüz: $3 + \frac{x-2}{2}\cdot 4 + \frac{(x-2)(x-4)}{4}\cdot\frac{8}{2!}$ aynı sonucu verir. Fark sabit olduğunda iki yol da kullanılabilir.
- **Lagrange örneği (ekrandan, 01:20:00).** $(0,-5), (1,1), (3,25)$. $L_0 = \frac{(x-1)(x-3)}{3}$, $L_1 = -\frac{x(x-3)}{2}$, $L_2 = \frac{x(x-1)}{6}$. $g(x) = -\frac{5}{3}(x-1)(x-3) - \frac{1}{2}x(x-3) + \frac{25}{6}x(x-1)$. $g(2) = \frac{5}{3} + 1 + \frac{25}{3} = 11$. Sadeleşmiş hali $2x^2 + 4x - 5$ (python ile kontrol edildi).
- **Dört noktalı Lagrange örneği (ekrandan, 01:25:00).** $x = 3, 7, 15, 22$, $y = 1, -8, -22, -9$. $L_0 = -\frac{1}{912}(x-7)(x-15)(x-22)$, $L_1 = \frac{1}{480}(x-3)(x-15)(x-22)$, $L_2 = -\frac{1}{672}(x-3)(x-7)(x-22)$, $L_3 = \frac{1}{1995}(x-3)(x-7)(x-15)$. $g(x) = 1\cdot L_0 - 8 L_1 - 22 L_2 - 9 L_3$.
  - Ders sonrası not: Hoca sözlü anlatımda katsayı olarak $3, 7, 15, 22$ değerlerini söyledi; bunlar $x$ değerleridir. Lagrange formülünde $y_i$ kullanılır, doğrusu $1, -8, -22, -9$'dur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
