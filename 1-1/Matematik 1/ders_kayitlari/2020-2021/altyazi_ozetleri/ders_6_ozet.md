# Ders 6 Çalışma Özeti

## Genel Konular

- Zincir kuralı (chain rule) alıştırmaları: köklü, trigonometrik ve kuvvet içeren bileşkeler.
- Tablo ile zincir kuralı (chain rule using a table).
- Zincir kuralıyla teğet doğrusu soruları.
- Yüksek mertebeden türevler (higher order derivatives).
- Kapalı türev (implicit differentiation): açık form (explicit form) ve kapalı form (implicit form).
- Kapalı formda verilen eğrilere teğet doğrusu.
- $\dfrac{dy}{dx}$ ile $\dfrac{dx}{dy}$ arasındaki ilişki.

## Hocanın Özellikle Vurguladığı Kısımlar

- Hoca sınavdan önce bütün konuları bitirmeyi hedefliyor. Sonra sınava yönelik genel alıştırmalar ve geçen yılların test soruları çözülecek.
- Çok soru çözmek marifet değil. Her formülün arkasındaki mantığı anlayın.
- Ders sırasında önünüzde kâğıt kalem olsun. Hoca ara ara alıştırma veriyor.
- Hoca üç yıldızla (\*\*\*) işaretlediği soruların test sınavında çıkma olasılığının yüksek olduğunu söylüyor.
- Sınav soruları kitaptaki soruların değiştirilmiş (modifiye edilmiş) hâlleridir. Sorunun yapısına odaklanın.
- Teğet doğrusu soruları test sınavında sıkça sorulur.
- Kapalı türevde iki tarafın türevini alırken $y$'nin $x$'e bağlı olduğunu unutmayın. Sabitin türevi $0$'dır.
- Henüz öğretilmeyen kapalı türev formülünü (kısmi türevli formül) kullanmayın. O, ikinci dönemin konusu. Önce mantığı kavrayın.
- "Eğrinin eğimi" denmez. Eğriye teğet olan doğrunun eğimi denir.
- Sonuçları sadeleştirmek zorunda değilsiniz. Sınavda genelde bir noktadaki değer sorulur; değeri yerine koymanız yeter.

## Kısa Tekrar Notları

- $\big(\sqrt{u}\big)' = \dfrac{u'}{2\sqrt{u}}$
- $\big(u^n\big)' = n u^{n-1} u'$
- $h(x) = f(g(x)) \Rightarrow h'(x) = f'(g(x)) \cdot g'(x)$
- $p(x) = g(f(x)) \Rightarrow p'(x) = g'(f(x)) \cdot f'(x)$. Bileşke sırasına dikkat edin.
- İkinci türev, birinci türevin türevidir: $\dfrac{d^2y}{dx^2} = \dfrac{d}{dx}\left(\dfrac{dy}{dx}\right)$.
- Açık form: $y = f(x)$ ya da $x = g(y)$. Kapalı form: $F(x, y) = 0$ gibi, $x$ ve $y$'nin birlikte bulunduğu denklem.
- Kapalı türev adımları:
  - İki tarafın $x$'e göre türevini alın.
  - $y$ içeren terimlerde zincir kuralını kullanın: $\dfrac{d}{dx}(y^2) = 2y \cdot y'$.
  - $y'$'yü yalnız bırakın ya da noktayı yerine koyup $m$'yi bulun.
- Teğet doğrusu: $y - y_0 = m(x - x_0)$, $m = y'(x_0, y_0)$.
- $\dfrac{dy}{dx} \cdot \dfrac{dx}{dy} = 1$ (paydalar sıfırdan farklıysa).

## Detaylı Açıklamalar

### Zincir kuralı alıştırmaları

- Örnek 1: $y = \sqrt{\sin^2 x + x^2}$.
  - $y' = \dfrac{1}{2\sqrt{\sin^2 x + x^2}} \cdot (2\sin x \cos x + 2x)$.
  - $\sin^2 x$'in türevi için de zincir kuralı kullanılır: $u = \sin x$, $(u^2)' = 2u \cdot u'$.
- Örnek 2: $y = (3x+7)^{10}$. $u = 3x + 7$ ise $y' = 10u^9 \cdot 3 = 30(3x+7)^9$.
- Örnek 3: $y = \cos(x^5)$. $u = x^5$, $y = \cos u$. $y' = -\sin(x^5) \cdot 5x^4$.
- Örnek 4: $y = \tan(5x^2)$. $y' = \sec^2(5x^2) \cdot 10x$.
- Örnek 5: $y = \sin^5 x$. $y' = 5\sin^4 x \cos x$.
- Üstel fonksiyonlu sorular sonraki haftaların konusu.

### Örnek 6: Tablo ile zincir kuralı (kitap, 37. soru)

- $h(x) = f(g(x))$, $p(x) = g(f(x))$. Tablo:

| $x$ | 1 | 2 | 3 | 4 | 5 |
|---|---|---|---|---|---|
| $f(x)$ | 0 | 3 | 5 | 1 | 0 |
| $f'(x)$ | 5 | 2 | −5 | −8 | −10 |
| $g(x)$ | 4 | 5 | 1 | 3 | 2 |
| $g'(x)$ | 2 | 10 | 20 | 15 | 20 |

- a) $h'(3) = f'(g(3)) \cdot g'(3) = f'(1) \cdot 20 = 5 \cdot 20 = 100$.
- $p$'de sıra terstir: $p'(x) = g'(f(x)) \cdot f'(x)$.
- Diğer şıklar ödev.

### Sınavda soru nasıl zorlaştırılır?

- Hoca, soru hazırlayanların kitaptaki soruyu değiştirdiğini anlatıyor.
- Örnek: $f(x) = \tan(g(x)) \cdot h(x)$ ve $g$, $h$ için bir tablo verilir.
- Çarpım ve zincir kuralı birlikte kullanılır:
  - $f'(x) = \big(1 + \tan^2 g(x)\big) \cdot g'(x) \cdot h(x) + \tan(g(x)) \cdot h'(x)$.
- Bu tarz sorular zincir kuralını bilip bilmediğinizi ölçer.

### Yüksek mertebeden türevler

- Gösterim: $y''$, $\dfrac{d^2y}{dx^2}$, $y^{(n)}$, $\dfrac{d^ny}{dx^n}$.
- Örnek 7: $y = x\cos(x^2)$.
  - $y' = \cos(x^2) - 2x^2 \sin(x^2)$. (Çarpım kuralı ve $(\cos u)' = -\sin u \cdot u'$.)
  - $y'' = -2x\sin(x^2) - \big(4x\sin(x^2) + 2x^2 \cos(x^2) \cdot 2x\big) = -6x\sin(x^2) - 4x^3\cos(x^2)$.
- Bir öğrenci eksi işaretinin nereden geldiğini soruyor. Hoca: Çarpım kuralında artı var. Eksi, $\cos$'un türevinden geliyor.

### Örnek 8: Teğet doğrusu ve zincir kuralı (kitap, 78. soru)

- $f$ türevlenebilir. Grafiği $(1, 4)$'ten geçiyor. $f$'nin $(1,4)$'teki teğeti $y = 3x + 1$. $g(x) = f(x^2)$.
- Teğetin eğimi $f'(1)$'dir. Yani $f'(1) = 3$ ve $f(1) = 4$.
- a) $g(1) = f(1) = 4$.
- b) $g'(x) = f'(x^2) \cdot 2x$.
- c) $g'(1) = f'(1) \cdot 2 = 6$.
- d) $g$'nin $x = 1$'deki teğeti: $y - 4 = 6(x - 1)$, yani $y = 6x - 2$.
- Bir öğrenci $f(x) = 3x^2 + 1$ mi diye soruyor. Hoca: Hayır. $y = 3x + 1$ teğet doğrusunun denklemidir. $f$'nin kuralını bilmiyoruz. Yalnız teğetin eğiminin $f'(1)$ olduğunu biliyoruz.
- Hoca: Kolay soru budur. Zorlaştırmak için $\tan$, $\sec$ ya da üstel fonksiyonlar eklenir.

### Örnek 9: $g(x) = f(\sin x)$

- $f'(0) = 3$, $f'(1) = 5$ veriliyor.
- $g'(x) = f'(\sin x) \cdot \cos x$.
- $g'(0) = f'(0) \cdot \cos 0 = 3$.
- $g'(\pi/2) = f'(1) \cdot \cos(\pi/2) = 5 \cdot 0 = 0$.
- $g'(\pi) = f'(0) \cdot \cos \pi = 3 \cdot (-1) = -3$.

### Kapalı türev: açık ve kapalı form

- Açık form: bağımlı değişken yalnız bağımsız değişken cinsinden yazılır.
  - $y = f(x)$: $\dfrac{dy}{dx}$ konuşulur.
  - $x = g(y)$: $\dfrac{dx}{dy}$ konuşulur. Bu da teğetin eğimiyle ilgilidir.
- Kapalı form: $x$ ve $y$ içeren bir denklem. $y$'yi $x$ cinsinden (ya da tersini) her zaman yazamayabiliriz.
- Bütün eğri bir fonksiyonun grafiği olmayabilir. $\dfrac{dy}{dx}$ istendiğinde eğrinin yerel bir parçası (local part) üzerinde çalışırız.

### Örnek 10: Birim çember $x^2 + y^2 = 1$

- Üst yarı çember: $y = \sqrt{1 - x^2}$.
  - $\dfrac{dy}{dx} = \dfrac{-2x}{2\sqrt{1-x^2}} = -\dfrac{x}{\sqrt{1-x^2}}$.
  - Bu fonksiyon, üst yarı çembere çizilen teğetlerin eğimini hesaplayan bir araçtır.
- Alt yarı çember için benzer işlem yapılır.
- Sol yarı çember: $x = -\sqrt{1 - y^2}$. Burada $x$ bağımlı, $y$ bağımsız değişkendir.
  - $\dfrac{dx}{dy} = \dfrac{y}{\sqrt{1-y^2}}$.
- İkinci yöntem (açık forma geçmeden):
  - $y = f(x)$ olduğunu bilip $f$'yi bulmadan iki tarafın $x$'e göre türevi alınır.
  - $2x + 2y \cdot y' = 0 \Rightarrow y' = -\dfrac{x}{y}$.
  - Ağaç diyagramı: $y^2$, $y$'ye; $y$, $x$'e bağlı.

### Örnek 11: $x^2 + \sin(xy) = y^2$ (hocanın kafadan yazdığı örnek)

- İki tarafın $x$'e göre türevi:
  - $2x + \cos(xy) \cdot (y + x y') = 2y \cdot y'$.
- Bu hâliyle bırakmak yeterli. Düzenlemek zorunda değilsiniz.
- $\dfrac{dx}{dy}$ istenirse $x$'i bağımlı, $y$'yi bağımsız kabul edip iki tarafın $y$'ye göre türevi alınır:
  - $2x \cdot x' + \cos(xy) \cdot (x' y + x) = 2y$.
- Ödev: İki sonucu bulup çarpın. $\dfrac{dy}{dx} \cdot \dfrac{dx}{dy} = 1$ olduğunu görün.
- Sonuç: $\dfrac{dy}{dx}$ biliniyorsa $\dfrac{dx}{dy} = \dfrac{1}{dy/dx}$ olur (payda sıfır değilse).

### Örnek 12: $x^2 + xy + y^2 = 3y$, $(1, 1)$ noktasında teğet

- Nokta eğri üzerinde: $1 + 1 + 1 = 3$.
- İki tarafın $x$'e göre türevi: $2x + y + x y' + 2y y' = 3y'$.
- $(1,1)$ ve $y' = m$ yazılır: $2 + 1 + m + 2m = 3m \Rightarrow 3 = 0$. Çelişki.
- Hoca bunu "bu noktada kırılma var, teğet yok" diye yorumluyor. Bu yorum yanlış. Doğrusu "Ders sonrası notlar" kısmında.
- Hoca bu soruyu kafadan yazdığını, sınavda böyle gelmeyeceğini söylüyor.

### Örnek 13: $x^2 + xy + y^2 = 3y^3$, $(1, 1)$ noktasında teğet

- Hoca sağ tarafı küp yaparak soruyu düzeltiyor. Nokta yine eğri üzerinde.
- Türev: $2x + y + x y' + 2y y' = 9y^2 y'$.
- $(1,1)$'de: $3 + 3m = 9m \Rightarrow 6m = 3 \Rightarrow m = \dfrac{1}{2}$.
- Teğet: $y - 1 = \dfrac{1}{2}(x - 1)$.
- Hoca soruya "(if any)" (varsa) eklenmesini öneriyor. Teğet yoksa cevap "teğet yoktur" olur.

### Örnek 14: $x^2 + \sin(xy) = x + y - 1$, $P(0, 1)$ noktasında teğet (varsa)

- Nokta eğri üzerinde: $0 + \sin 0 = 0 + 1 - 1$.
- Türev: $2x + \cos(xy)(y + x y') = 1 + y'$.
- $(0, 1)$'de: $0 + 1 \cdot (1 + 0) = 1 + m \Rightarrow m = 0$.
- Teğet: $y - 1 = 0$, yani $y = 1$. Yatay doğru.

### Örnek 15: Rasyonel üslü kapalı türev (kitap, 47. soru)

- $x y^{1/3} + y = 10$, $(1, 8)$ noktasında teğetin eğimi.
- Türev: $y^{1/3} + x \cdot \dfrac{1}{3} y^{-2/3} y' + y' = 0$.
- $(1, 8)$'de: $2 + \dfrac{1}{3} \cdot 8^{-2/3} m + m = 0 \Rightarrow 2 + \dfrac{m}{12} + m = 0$.
- $\dfrac{13m}{12} = -2 \Rightarrow m = -\dfrac{24}{13}$.
- Bir öğrenci sağ tarafı neden $10$ değil $0$ yaptıklarını soruyor. Hoca: İki tarafın türevini alıyoruz. Sabitin türevi $0$'dır.
- Hoca kitaptaki "determine the slope of the following curves" ifadesini düzeltiyor: "eğrilere teğet olan doğruların eğimi" olmalı.

### Örnek 16: $(x + y)^{2/3} = y$, $(4, 4)$ (kitap, 48. soru, ödev)

- Hoca yalnız türevi gösteriyor: $\dfrac{2}{3}(x+y)^{-1/3}(1 + y') = y'$.
- $u = x + y$ ve $y$, $x$'e bağlı olduğu için $u' = 1 + y'$.
- Kontrol için: $(4,4)$'te $(x+y)^{-1/3} = 8^{-1/3} = \dfrac{1}{2}$. $\dfrac{1}{3}(1 + m) = m \Rightarrow m = \dfrac{1}{2}$.

### Ders sonrası notlar

- **Örnek 12'nin yorumu düzeltilmeli.** $x^2 + xy + y^2 = 3y$ bir elipstir. Elips düzgün bir eğridir, köşesi (kırılması) yoktur.
  - $3 = 0$ çelişkisi, $(1,1)$'de $\dfrac{dy}{dx}$'in tanımsız olduğunu gösterir. Teğet yok demek değildir.
  - $\dfrac{dx}{dy}$ hesaplanırsa: $2x x' + x' y + x + 2y = 3 \Rightarrow 3x' + 3 = 3 \Rightarrow x' = 0$.
  - Yani $(1,1)$'de teğet **dikey**dir: $x = 1$. Eğimi tanımsızdır (sonsuz).
  - Doğru yorum: Kapalı türevde $y'$'nin katsayısı $0$ olursa, ya dikey teğet vardır ya da o nokta tekil (singular) bir noktadır. Hangisi olduğu ayrıca incelenmelidir.
- Hoca "derivation" diyor. Doğru İngilizce terim "derivative" (türev) ve "differentiation" (türev alma).
- "Implicit function" yerine hoca "implicit form" demeyi tercih ediyor. Doğru Türkçe karşılığı "kapalı fonksiyonun türevi" ya da "kapalı türev".
- Ders sırasında yoklama alındı. Özete öğrenci adları yazılmadı.
- Hoca konuları 4.–5. hafta civarında bitirmek istediğini söylüyor. Cümle altyazıda tam anlaşılmıyor.
- Bazı geçişlerin sözlü anlatımı (ör. 00:09:36–00:09:58 ve 01:21:02, 01:35:16) altyazıda döngüye girmiş. Bu kısımlar altyazıda anlaşılmıyor. Çözümler ekrandaki yazıdan tamamlandı.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
